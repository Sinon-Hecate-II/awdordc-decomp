/* 16 functions from 0x02018FF0 to 0x02019E64 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 left; char *current,*start; } Print195;
typedef struct { char prefix[2]; Print195 out; char digits[24]; } Format195;
typedef struct Work19334 { s32 (*first)(struct Work19334 *); void (*second)(struct Work19334 *); s32 result; s32 rest[6]; } Work19334;

void Mb_SendBootParams(void) {
    extern M2C_UNK gMbBootState;
    extern s16 gMbBootSync;
    extern M2C_UNK data_02136cc0;
    extern M2C_UNK data_02136cc4;
    extern s32 Mb_CheckCartridgeHeader(void);
    void Mb_LockCartridgeAccess(M2C_UNK, void *);
    void Mb_SaveCartridgeBusConfig(void *);
    void Mb_RestoreCartridgeBusConfig(void *);
    void Mb_UnlockCartridgeAccess(M2C_UNK, void *);
    M2C_UNK Mb_SendControlMessage(M2C_UNK);
    s32 OS_SetIrqEnableMask(s32);
    void DC_InvalidateRange(M2C_UNK, M2C_UNK);
    M2C_UNK DmaCopy16(s32, M2C_UNK, M2C_UNK, u32);
    void MIi_CpuCopy32(void *, void *, s32);
    void DC_FlushAll(void);
    void WaitByLoop(s32);

    u8 buf[16];
    s32 old;
    u16 saved_ie;
    s32 carry;
    s32 i;
    s32 delay;
    u16 hw;
    u8 *p;
    u8 *dst;

    if (gMbBootState != 0) {
        return;
    }
    gMbBootState = 1;
    hw = *(volatile u16 *)0x4000300;
    if (!(hw & 1)) {
        return;
    }

    old = OS_SetIrqEnableMask(0x40000);
    saved_ie = *(volatile u16 *)0x4000208;
    *(volatile u16 *)0x4000208 = 1;
    Mb_LockCartridgeAccess(*(u16 *)((u8 *)&gMbBootSync + 2), buf + 8);

    carry = (*(volatile u16 *)0x4000204 & 0x8000) >> 15;
    Mb_SaveCartridgeBusConfig(buf);

    hw = *(volatile u16 *)0x4000204;
    *(volatile u16 *)0x4000204 = hw & ~0x8000;
    DC_InvalidateRange((M2C_UNK)((s32)&data_02136cc0 + 0x80), 0x40);
    DmaCopy16(1, (M2C_UNK)0x8000080, (M2C_UNK)((s32)&data_02136cc0 + 0x80), 0x40);

    hw = *(volatile u16 *)0x4000204;
    *(volatile u16 *)0x4000204 = (hw & ~0x8000) | (carry << 15);
    Mb_RestoreCartridgeBusConfig(buf);

    Mb_UnlockCartridgeAccess(*(u16 *)((u8 *)&gMbBootSync + 2), buf + 8);

    p = (u8 *)0x027FFF9A;
    if (p[1] != 0 || p[0] == 0) {
        dst = (u8 *)0x027FFC30;
        *(u16 *)dst = *(u16 *)((u8 *)&data_02136cc0 + 0xBE);
        for (i = 0; i < 3; i++) {
            dst[i + 2] = ((u8 *)&data_02136cc0)[i + 0xB5];
        }
        *(u16 *)(dst + 6) = *(u16 *)((u8 *)&data_02136cc0 + 0xB0);
        *(u32 *)(dst + 8) = *(u32 *)((u8 *)&data_02136cc0 + 0xAC);
        p[1] = (Mb_CheckCartridgeHeader() != 0) ? 1 : 0;
        p[0] = 1;
    }

    MIi_CpuCopy32((void *)0xFFFF0020, (void *)&data_02136cc4, 0x9C);
    DC_FlushAll();
    Mb_SendControlMessage((((u32)&data_02136cc0 + 0xFE000000) >> 5) << 6 | 1);

    delay = 1;
    while (*(u16 *)((u8 *)&gMbBootSync + 0) != 1) {
        WaitByLoop(delay);
    }

    (void)*(volatile u16 *)0x4000208;
    *(volatile u16 *)0x4000208 = saved_ie;
    OS_SetIrqEnableMask(old);
}

/* Multiboot boot-ready handler (FIFO tag MB_FIFO_TAG): the ARM7 reports that it
 * is ready for the boot parameters, so raise the sync flag Mb_SendBootParams
 * waits on; any other status halts this console. */
void Mb_BootHandshakeHandler(s32 unused, s32 message) {
    extern s16 gMbBootSync;
    if ((message & MB_STATUS_MASK) == MB_STATUS_BOOT_READY) {
        gMbBootSync = 1;
        return;
    }
    SystemHalt();
}

/* ARM7 multiboot message handler: on the boot-complete status, run the boot
 * state's optional completion callback and record that the boot finished, aborting
 * the boot when that callback fails; halt on any other status. */
void Mb_BootCompleteHandler(s32 unused,s32 message) {
void Mb_AbortBoot(void);
extern M2C_UNK gMbBootState;
if((message&63)==17){
s32 result;
if(M2C_FIELD(&gMbBootState,s32 *,0xc))return;
result=0;
if(M2C_FIELD(&gMbBootState,s32 (**)(),0x18)) result=M2C_FIELD(&gMbBootState,s32 (**)(),0x18)();
if(result)Mb_AbortBoot();
M2C_FIELD(&gMbBootState,s32 *,0xc)=1;
return;
}
SystemHalt();
}

void Mb_AbortBoot(void) {
    M2C_UNK SystemHalt();
    M2C_UNK Mb_SendControlMessage(M2C_UNK);
    Mb_SendControlMessage(2);
    SystemHalt();
}

void Mb_RemoteReadyHandler(void) {
    extern M2C_UNK gMbBootState;
    M2C_FIELD(&gMbBootState, s32 *, 4) = 0;
}

/* Start the multiboot worker thread on thread object `task`, once: empty the
 * thread's own job record, hand it the network stack's memory as its 0x400-byte
 * stack at priority 20 and wake it. */
void Mb_StartTask(M2C_UNK task) {
void MbJob_Clear(M2C_UNK);
extern s32 gMbJobTask;
extern M2C_UNK data_02136e6c,gNetStack;
void MbWorker_Main();
s32 OS_DisableInterrupts(void);
void OS_RestoreInterrupts(s32);
void TaskCreate(M2C_UNK,void (*)(void),M2C_UNK,void *,s32,s32);
s32 saved=OS_DisableInterrupts();
if(!gMbJobTask){
gMbJobTask=task;
MbJob_Clear(task+MB_TASK_JOB_BLOCK);
MbJob_Clear((s32)&data_02136e6c);
M2C_FIELD(task,s32 *,MB_TASK_JOB)=0;
TaskCreate(task,MbWorker_Main,task,&gNetStack,0x400,20);
TaskWake(task);
}
OS_RestoreInterrupts(saved);
}

void MbJob_Clear(M2C_UNK arg0) {
    M2C_UNK MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    MI_CpuFill8(arg0, 0, 0x24);
}

void MbWorker_Main(void *arg0) {
extern s32 gMbJobTask;
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32);
void OS_SleepThread(s32); void TaskExitCurrent(void);
s32 saved; Work19334 w; void (*second)(Work19334 *);
for(;;) {
MI_CpuFill8((s32)&w,0,0x24);
saved=OS_DisableInterrupts();
while(!M2C_FIELD(arg0,Work19334 * volatile *,0xc0)) OS_SleepThread(0);
w=*M2C_FIELD((short)arg0,Work19334 **,0xc0);
OS_RestoreInterrupts(saved);
if(w.first) w.result=w.first(&w);
saved=OS_DisableInterrupts();
second=w.second;
M2C_FIELD(&gMbJobTask,u8 *,0x26)=0;
if(second) second(&w);
if(!gMbJobTask) break;
M2C_FIELD(arg0,Work19334 **,0xc0)=0;
OS_RestoreInterrupts(saved);
}
TaskExitCurrent();
}

/* Copy the NUL-terminated string `src` to `dst`, terminator included, and return
 * `dst`. */
s8 *Mb_StringCopy(s8 *dst, volatile s8 *src) {
    s8 *start = dst;
    if (*src) do { *dst++ = *src; } while (*++src);
    *dst = 0;
    return start;
}

/* Copy the NUL-terminated string `src` into `dst`, at most `size - 1` bytes,
 * always NUL-terminating, and return the length of `src` (strlcpy semantics). */
s32 Mb_StringCopyBounded(s8 *dst, s8 *src, s32 size) {
    s32 i;
    s8 *p;
    p = src;
    i = 0;
    for (; i < size - 1; i++, p++) {
        dst[i] = *p;
        if (*p == 0) break;
    }
    if (i >= size - 1 && size != 0) dst[i] = 0;
    return Mb_StringLength(src);
}

/* Return the length of the NUL-terminated string `string`. */
s32 Mb_StringLength(s8 *string) {
    s32 length;

    length = 0;
    if (*string != 0) {
        do {
            length += 1;
        } while (*(string + length) != 0);
    }
    return length;
}

#pragma opt_propagation off
/* Compare the NUL-terminated strings `a` and `b` byte by byte and return the
 * difference of the first pair that differs (0 when they are equal). */
s32 Mb_StringCompare(s8 *a, s8 *b) {
 for (; *a == *b && *a != 0; a++, b++) {}
 return *a - *b;
}
#pragma opt_propagation reset
/* Write one character into a formatter output buffer: store it and shrink the
 * remaining capacity only while there is room, but always advance the write
 * cursor so the final length counts every character the format asked for. */
void FormatPutChar(Print195 *out, s8 c) {
    if (M2C_FIELD(out, s32 *, 0) != 0) {
        *M2C_FIELD(out, s8 **, 4) = c;
        M2C_FIELD(out, s32 *, 0) = (s32) (M2C_FIELD(out, s32 *, 0) - 1);
    }
    M2C_FIELD(out, s8 **, 4) = (s8 *) (M2C_FIELD(out, s8 **, 4) + 1);
}

/* Formatter helper: write `count` copies of fill byte `c` into the output buffer,
 * but only as many as still fit; reduce the remaining capacity by the bytes
 * written and advance the write cursor by the whole count. */
void FormatWriteFill(Print195 *out, s8 c, s32 count) {
    u32 i, len;
    if (count <= 0) return;
    len = out->left; i = 0;
    if (len > (u32)count) len = count;
    for (; i < len; i++) out->current[i] = c;
    out->left -= len;
    out->current += count;
}

/* Bounded write into a formatter output buffer: copy `count` bytes from `src`
 * into the buffer, but only as many as still fit in the buffer's remaining
 * capacity (+0); reduce that remaining count by the bytes written and advance
 * the write cursor (+4) by the whole field width. */
void FormatWriteBytes(void *out, s8 *src, s32 count) {
    u32 i, len;

    if (count <= 0) return;
    len = M2C_FIELD(out, u32 *, 0);
    i = 0;
    if (len > (u32)count) len = count;
    for (; i < len; i++) M2C_FIELD(out, s8 **, 4)[i] = src[i];
    M2C_FIELD(out, u32 *, 0) -= len;
    M2C_FIELD(out, s8 **, 4) += count;
}

#pragma opt_common_subs off
#pragma opt_lifetimes off
s32 func_020195e8(char *dst,s32 capacity,const char *format,char *args) {
char digits[24];
Print195 out;
char prefix[2];
const char *mark;
register char *ap=args;
char *str;
s32 flags,width,precision,base,alpha,n,prefixLen,len,c,pad;
s32 left;
u64 value;
u64 U64Divide(u64,u64);
out.left=capacity;out.start=dst;out.current=dst;
while(*format){
c=*format;
if((((u8)c^0x20)-0xa1U)<0x3c){
FormatPutChar(&out,*format);
if(*++format){FormatPutChar(&out,*format++);}
continue;
}
if(c!='%'){FormatPutChar(&out,*format);format++;continue;}
flags=0;width=0;precision=-1;mark=format;base=10;alpha=87;
for(;;){
c=*++format;
switch(c){
case '+':if(format[-1]==' '){flags|=2;continue;}break;
case ' ':flags|=1;continue;
case '-':flags|=8;continue;
case '0':flags|=16;continue;
}
break;
}
if(*format=='*'){
ap+=4;width=*(s32 *)(ap-4);format++;
if(width<0){width=-width;flags|=8;}
}else while(*format>='0'&&*format<='9'){width=width*10+*format++-'0';}
if(*format=='.'){
format++;precision=0;
if(*format=='*'){ap+=4;precision=*(s32 *)(ap-4);format++;if(precision<0)precision=-1;}
else while(*format>='0'&&*format<='9'){precision=precision*10+*format++-'0';}
}
switch(*format){case 'h':format++;if(*format!='h')flags|=64;else {format++;flags|=256;}break;
case 'l':format++;if(*format!='l')flags|=32;else{format++;flags|=128;}break;}
switch(*format){
case 'o':flags|=4096;base=8;goto number;
case 'u':flags|=4096;goto number;
case 'X':alpha=55;goto hex;
case 'p':flags|=4;precision=8;goto hex;
case 'x':goto hex;
case 'd':case 'i':goto number;
case 'c':
if(precision>=0)goto invalid;
ap+=4;c=*(s32 *)(ap-4);
if(flags&8){FormatPutChar(&out,(s8)c);FormatWriteFill(&out,' ',width-1);}
else {FormatWriteFill(&out,(s8)(flags&16?'0':' '),width-1);FormatPutChar(&out,(s8)c);}
format++;continue;
case 's':
ap+=4;str=*(char **)(ap-4);len=0;
if(precision<0){while(str[len])len++;}
else {while(len<precision&&str[len])len++;}
width-=len;
if(flags&8){FormatWriteBytes(&out,(s8 *)str,len);FormatWriteFill(&out,' ',width);}
else {FormatWriteFill(&out,(s8)(flags&16?'0':' '),width);FormatWriteBytes(&out,(s8 *)str,len);}
format++;continue;
case 'n':
n=out.current-out.start;
if(!(flags&256)){
if(flags&64){ap+=4;**(s16 **)(ap-4)=n;}
else {ap+=4;if(!(flags&128))**(s32 **)(ap-4)=n;else **(s64 **)(ap-4)=n;}
}
format++;continue;
case '%':
if(mark+1==format){FormatPutChar(&out,*format++);continue;}
default:
invalid:FormatWriteBytes(&out,(s8 *)mark,format-mark);continue;
}
hex:flags|=4096;base=16;
number:
if(flags&8)flags&=~16;
if(precision>=0)flags&=~16;else precision=1;
prefixLen=0;
if(flags&4096){
if(flags&256){ap+=4;value=*(u8 *)(ap-4);}
else if(flags&64){ap+=4;value=*(u16 *)(ap-4);}
else if(!(flags&128)){ap+=4;value=*(u32 *)(ap-4);}
else {ap+=8;value=*(u64 *)(ap-8);flags&=~3;}
if(flags&4){
if(base==16&&value){prefix[0]=alpha+33;prefix[1]='0';prefixLen=2;}
else if(base==8){prefix[0]='0';prefixLen=1;}
}
}else {
if(flags&256){ap+=4;value=*(s8 *)(ap-4);}
else if(flags&64){ap+=4;value=*(s16 *)(ap-4);}
else if(!(flags&128)){ap+=4;value=*(s32 *)(ap-4);}
else {ap+=8;value=*(s64 *)(ap-8);}
if(value&0x8000000000000000ULL){prefix[0]='-';value=~value+1;prefixLen=1;}
else if(value||precision){
if(flags&2){prefix[0]='+';prefixLen=1;}
else if(flags&1){prefix[0]=' ';prefixLen=1;}
}
}
n=0;
switch(base){
case 8:while(value){digits[n++]=((u32)value&7)+'0';value>>=3;}break;
case 10:
if((value & 0xffffffff00000000ULL)==0){
u32 small=value;
while(small){u32 q=small/10;c=small-q*10;small=q;digits[n++]=c+'0';}
}else while(value){u64 quotient=U64Divide(value,10);digits[n++]=(u32)(value-quotient*10)+'0';value=quotient;}
break;
case 16:while(value){c=value&15;value>>=4;digits[n++]=c<10?c+'0':c+alpha;}break;
}
if(prefixLen>0&&prefix[0]=='0'){digits[n++]='0';prefixLen=0;}
precision-=n;
if(flags&16){pad=width-n-prefixLen;if(precision<pad)precision=pad;}
if(precision>0)width-=precision;
width-=prefixLen+n;
left=flags&8;
if(!left)FormatWriteFill(&out,' ',width);
while(prefixLen>0)FormatPutChar(&out,prefix[--prefixLen]);
FormatWriteFill(&out,'0',precision);
while(n>0)FormatPutChar(&out,digits[--n]);
if(left)FormatWriteFill(&out,' ',width);
format++;
}
if(out.left)*out.current=0;
else if(capacity)out.start[capacity-1]=0;
return out.current-out.start;
}
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
