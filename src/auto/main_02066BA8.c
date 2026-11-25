/* 11 functions from 0x02066BA8 to 0x020677B8 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 a,b,c,d,e,f,g,h; s32 width,precision; } HexFormat;
typedef struct { char *q; u32 lo,hi; char space,pad; } FormatterScratch;
static inline void heapSwap(s8 *a,s8 *b,u32 n) { s8 t; if(n) do { t=*a; *a++=*b; *b++=t; } while(--n); }

char *FormatIntegerNarrow(s32,char *,HexFormat);
char *func_02065b48(u64,char *,HexFormat);
char *func_02066444(double,char *,HexFormat);
char *func_02065e44(double,char *,HexFormat);
extern u8 data_0210054c[],data_02100550[];
#pragma opt_strength_reduction off
u32 FormatString(s32 (*writer)(void *,const char *,s32), void *state, char *p, char *args) {
    char buffer[512];
    HexFormat f;
    char pad=' ', space;
    char *q;
    s32 total=0;
    s32 len;
    char *text;
    s32 width;
    s32 value;
    u64 wide;
    double real;
    while (*p) {
        char *mark=(char *)StringFindChar(p,37);
        q=mark;
        if (!mark) {
            len=StringLength(p); total+=len;
            if(len && !writer(state,p,len)) return -1;
            break;
        }
        len=mark-p;total+=len;
        if(len && !writer(state,p,len)) return -1;
        p=(char *)func_0206536c(q,&args,&f);
        switch(f.f) {
        case 'd': case 'i':
            if(f.e==3) {args+=4;value=*(long *)(args-4);}
            else if(f.e==4) {args+=8;wide=*(u64 *)(args-8);}
            else if(f.e==6) {args+=8;wide=*(u64 *)(args-8);}
            else if(f.e==7) {args+=4;value=*(unsigned long *)(args-4);}
            else if(f.e==8) {args+=4;value=(s32)*(char **)(args-4);}
            else {args+=4;value=*(s32 *)(args-4);}
            if(f.e==2)value=(s16)value;
            if(f.e==1)value=(s8)value;
            if(f.e==4 || f.e==6){char *converted=func_02065b48(wide,buffer+512,f);if(!converted)goto invalid;text=converted;}
            else {text=FormatIntegerNarrow(value,buffer+512,f);if(!text)goto invalid;}
            len=buffer+511-text;break;
        case 'o': case 'u': case 'x': case 'X':
            if(f.e==3) {args+=4;value=*(long *)(args-4);}
            else if(f.e==4) {args+=8;wide=*(u64 *)(args-8);}
            else if(f.e==6) {args+=8;wide=*(u64 *)(args-8);}
            else if(f.e==7) {args+=4;value=*(unsigned long *)(args-4);}
            else if(f.e==8) {args+=4;value=(s32)*(char **)(args-4);}
            else {args+=4;value=*(s32 *)(args-4);}
            if(f.e==2)value=(u16)value;
            if(f.e==1)value=(u8)value;
            if(f.e==4 || f.e==6){char *converted=func_02065b48(wide,buffer+512,f);if(!converted)goto invalid;text=converted;}
            else {text=FormatIntegerNarrow(value,buffer+512,f);if(!text)goto invalid;}
            len=buffer+511-text;break;
        case 'e':case 'E':case 'f':case 'F':case 'g':case 'G':
            if(f.e==9){args+=8;real=*(double *)(args-8);}
            else {args+=8;real=*(long double *)(args-8);}
            text=func_02066444(real,buffer+512,f);
            if(!text)goto invalid;
            len=buffer+511-text;break;
        case 'a':case 'A':
            if(f.e==9){args+=8;real=*(double *)(args-8);}
            else {args+=8;real=*(long double *)(args-8);}
            text=func_02065e44(real,buffer+512,f);
            if(!text)goto invalid;
            len=buffer+511-text;break;
        case 's':
            if(f.e==5){
                u16 *str;
                args+=4;str=*(u16 **)(args-4);
                if(!str)str=(u16 *)data_0210054c;
                if((s32)WideStringToString(buffer,str,512)<0)goto invalid;
                text=buffer;
            } else {args+=4;text=*(char **)(args-4);}
            if(!text)text=(char *)data_02100550;
            if(f.d){
                len=(u8)*text++;
                if(f.c && len>f.precision)len=f.precision;
            }else if(f.c){
                char *end;
                len=f.precision;
                end=(char *)func_02065224(text,0,len);
                if(end)len=end-text;
            }else len=StringLength(text);
            break;
        case 'n':{
            void *ptr;
            args+=4;ptr=*(void **)(args-4);
            switch(f.e){
            case 0:*(s32 *)ptr=total;break;
            case 2:*(s16 *)ptr=total;break;
            case 3:*(s32 *)ptr=total;break;
            case 6:*(s64 *)ptr=total;break;
            case 7:*(s32 *)ptr=total;break;
            case 8:*(s32 *)ptr=total;break;
            case 4:*(s64 *)ptr=total;break;
            }
            continue;
        }
        case 'c':args+=4;buffer[0]=*(s32 *)(args-4);text=buffer;len=1;break;
        case '%':buffer[0]='%';text=buffer;len=1;break;
        case 255:
        default:
        invalid:
            len=StringLength(q);
            if(len && !writer(state,q,len))return -1;
            return total+len;
        }
        width=len;
        if(f.a){
            pad=f.a==2?'0':' ';
            if((*text=='+' || *text=='-' || *text==' ') && pad=='0'){
                if(!writer(state,text,1))return -1;
                text++;len--;
            }
            while(width<f.width){
                if(!writer(state,&pad,1))return -1;
                width++;
            }
        }
        if(len && !writer(state,text,len))return -1;
        if(f.a==0){
            while(width<f.width){
                space=' ';
                if(!writer(state,&space,1))return -1;
                width++;
            }
        }
        total+=width;
    }
    return total;
}
#pragma opt_strength_reduction reset
/* FormatString writer for StdoutPrintf: write `count` bytes of `data` to the
 * stdout stream and return the stream, or 0 when the stream took fewer bytes. */
s32 StdoutWrite(void *stream, char *data, s32 count) {
    s32 StreamWrite(s32, s32, s32, void *);
    s32 result;

    result = (s32)stream;
    if (count != StreamWrite((s32)data, 1, count, (void *)result)) {
        result = 0;
    }
    return result;
}

/* Writer callback for the bounded string formatter: appends `count` bytes from
 * `data` to the FormatBuffer, clamped to the space left after the bytes already
 * written, and returns 1. */
s32 WriteFormatBuffer(FormatBuffer *state, M2C_UNK data, u32 count) {
    M2C_UNK MemCopy(s32, M2C_UNK, s32);
    u32 position;
    u32 writeCount;
    u32 size;

    position = state->position;
    writeCount = count;
    size = state->size;
    if (position + writeCount > size) {
        writeCount = size - position;
    }
    MemCopy((s32)(state->buffer + position), data, (s32)writeCount);
    state->position = state->position + writeCount;
    return 1;
}

/* printf to the game's stdout stream: take the stdout lock (a recursive GsiMutex
 * keyed by the running thread's id), format the arguments into the stream and
 * release the lock once the write is done.  Returns the write result, or -1 when
 * stdout is in an error state. */
s32 StdoutPrintf(char *format, ...) {
    extern u8 gStdoutStream[], gSocketManager[], gStreamMutexStdout[];
    extern s32 gStreamLockOwner[], gStreamLockDepth[];
    s32 func_0206ad4c(void *, s32);
    s32 TryLockMutex(void *);
    u32 FormatString();
    s32 result;
    char *args;
    if (func_0206ad4c(gStdoutStream, -1) >= 0) return -1;
    if (!TryLockMutex(gStreamMutexStdout)) {
        gStreamLockOwner[STREAM_LOCK_STDOUT] = M2C_FIELD(M2C_FIELD(gSocketManager, void **, 4), s32 *, STREAM_THREAD_ID);
        gStreamLockDepth[STREAM_LOCK_STDOUT] = 1;
    } else if (gStreamLockOwner[STREAM_LOCK_STDOUT] == M2C_FIELD(M2C_FIELD(gSocketManager, void **, 4), s32 *, STREAM_THREAD_ID)) {
        gStreamLockDepth[STREAM_LOCK_STDOUT]++;
    } else {
        LockMutex(gStreamMutexStdout);
        gStreamLockOwner[STREAM_LOCK_STDOUT] = M2C_FIELD(M2C_FIELD(gSocketManager, void **, 4), s32 *, STREAM_THREAD_ID);
        gStreamLockDepth[STREAM_LOCK_STDOUT] = 1;
    }
    args = (char *)(((u32)&format & ~3U) + 4);
    result = FormatString(StdoutWrite, gStdoutStream, format, args);
    if (--gStreamLockDepth[STREAM_LOCK_STDOUT] == 0) UnlockMutex(gStreamMutexStdout);
    return result;
}

/* Formats `format` with the argument list `args` into `buffer`, writing at most
 * `size` bytes: the output is truncated at `size`, a nonzero `size` keeps a NUL
 * terminator in the last byte when it overflows, and a null buffer is not
 * written.  Returns the length the whole formatted string would need. */
u32 StringFormatBounded(char *buffer, u32 size, s32 format, void *args) {
    u32 FormatString();
    FormatBuffer state;
    u32 result;
    state.buffer = buffer;
    state.size = size;
    state.position = 0;
    result = FormatString(WriteFormatBuffer, &state, format, args);
    if (buffer == 0) return result;
    if (result < size) {
        buffer[result] = 0;
        return result;
    }
    if (size != 0) (buffer + size)[-1] = 0;
    return result;
}

void StringFormatBuffer(s32 arg0, s32 arg1, s32 arg2, ...) {
    char *args;
    args = (char *)(((u32)&arg2 & ~3U) + 4);
    StringFormatBounded(arg0, arg1, arg2, args);

}

void StringFormat(s32 arg0, s32 arg1, ...) {
    char *args;
    args = (char *)(((u32)&arg1 & ~3U) + 4);
    StringFormatBounded((char *)arg0, -1, arg1, args);
}

void func_02067610(s8 *base,u32 count,u32 size,s32 (*compare)(const void*,const void*)) {
u32 root,child,k; s8 *start,*end,*parent,*q,*p; s8 byte; u32 offset,neg;
if(count<2)return;
root=(count>>1)+1;
start=base+size*(root-1);end=base+size*(count-1);offset=root*size;neg=size*-1;
for(;;){
if(root>1){--root;offset-=size;start-=size;}
else {
heapSwap(start,end,size);
if(--count==1)return;
end-=size;
}
child=root;p=base+(offset+neg);
while(count>=child*2){
child*=2;parent=p;p=base+size*(child-1);
if(count>child && compare(p,p+size)<0){child++;p+=size;}
if(compare(parent,p)>=0)break;
heapSwap(parent,p,size);
}
}
}

/* Advance the game's global 32-bit LCG and return the top 15 bits of the new state. */
s32 Rand(void) {
    extern s32 gRandSeed;
    u32 value;

    value = (gRandSeed * RAND_MULTIPLIER) + RAND_INCREMENT;
    gRandSeed = value;
    return RAND_MASK & (value >> RAND_SHIFT);
}

void SetRandSeed(s32 arg0) {
    extern s32 gRandSeed;
    gRandSeed = arg0;
}
