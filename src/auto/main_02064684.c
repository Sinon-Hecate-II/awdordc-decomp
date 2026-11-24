/* 23 functions from 0x02064684 to 0x0206536C (main), found by ds-decomp. */
#include "common.h"
/* The first bytes of a GameSpy stream object: the flag word at +4 (mode in
 * bits 2..4, access in bits 7..9, nonzero while the stream is open) and the
 * state word at +8 (low 3 bits: 0 closed, 1 open, 2 flushing). */
typedef struct { u32 unused0; u32 flagsLow:2, mode:3, flagsMid:2, access:3, flagsHigh:22; u32 state:3, stateRest:29; } StreamFlags649;
/* Other fields of a stream object, used to locate its current position. */
#define STREAM_ERROR      0x0D /* u8 nonzero once a stream error was set */
#define STREAM_POSITION   0x18 /* s32 position of a stream that does not buffer */
#define STREAM_BUFFER     0x1C /* u8 *start of the stream's buffer */
#define STREAM_CURSOR     0x24 /* u8 *current read/write cursor in it */
#define STREAM_BUFFER_POS 0x34 /* s32 file offset the buffer starts at */
extern u8 gStdinStream[], gStdoutStream[], gStderrStream[], gStreamMutexes[];
extern s32 gStreamLockOwner[], gStreamLockDepth[];
extern M2C_UNK gSocketManager;
typedef struct ThreadGlobal { s32 unused; void *current; } ThreadGlobal;

#pragma push
#pragma opt_common_subs off
/* Appends count*size bytes from buffer to a GameSpy stream, in buffered chunks:
 * flushes through the stream's write callback, stops early at a newline when the
 * stream is line-buffered, and returns written/size via the divide helper. */
s32 StreamWrite(s32 buffer, s32 elemSize, s32 count, void *stream) {
    M2C_UNK StreamResetBuffer(void *);
    s32 StreamFlush(void *, s32);
    s8 *MemCopy(s8 *, s8 *, s32);
    u8 *FindLastByte(u8 *, s32, u32);
    s32 func_0206ad4c(void *, M2C_UNK);
    s32 U32DivideRem(s32, s32);
    u32 chunk;
    s32 size;
    s32 writeBase;
    s32 flags;
    s32 stateWord;
    s32 scratch;
    s32 savedBase;
    s32 src;
    u32 remaining;
    s32 written;
    s32 eol;
    s32 chunked;
    s32 unusedZ;
    u32 unusedTemp0;
    u32 unusedTemp1;
    u32 avail;
    u32 savedSize;
    src = buffer;
    size = elemSize;
    if (func_0206ad4c(stream, 0) == 0) {
        func_0206ad4c(stream, -1);
    }
    remaining = size * count;
    if ((remaining == 0) || (M2C_FIELD(stream, u8 *, 0xD) != 0) || (flags = M2C_FIELD(stream, s32 *, 4), (((u32) (flags << 0x16) >> 0x1D) == 0))) {
        return 0;
    }
    chunked = 1;
    if (((u32)(flags << 19) >> 31) != 0 &&
        ((u32)(flags << 25) >> 30) != 2 &&
        ((u32)(flags << 25) >> 30) != 1) chunked = 0;
    stateWord = M2C_FIELD(stream, s32 *, 8);
    if ((((u32) (stateWord << 0x1D) >> 0x1D) == 0) && (((u32) (M2C_FIELD(stream, s32 *, 4) << 0x1B) >> 0x1D) & 2)) {
        M2C_FIELD(stream, s32 *, 8) = (s32) ((stateWord & ~7) | 1);
        StreamResetBuffer(stream);
    }
    if (((u32) (M2C_FIELD(stream, s32 *, 8) << 0x1D) >> 0x1D) != 1) {
        M2C_FIELD(stream, u8 *, 0xD) = 1U;
        M2C_FIELD(stream, u32 *, 0x28) = 0U;
        return 0;
    }
    written = 0;
    if (remaining != 0) {
        writeBase = M2C_FIELD(stream, s32 *, 0x1C);
        scratch = M2C_FIELD(stream, s32 *, 0x24);
        if ((scratch == writeBase) && (chunked == 0)) {

        } else {
            M2C_FIELD(stream, u32 *, 0x28) = (u32) (M2C_FIELD(stream, u32 *, 0x20) - (scratch - writeBase));
loop_21:
            avail = M2C_FIELD(stream, u32 *, 0x28);
            eol = 0;
            chunk = avail;
            if (avail > remaining) {
                chunk = remaining;
            }
            if ((((u32) (M2C_FIELD(stream, s32 *, 4) << 0x19) >> 0x1E) == 1) && (chunk != 0)) {
                eol = (s32)FindLastByte((u8 *)src, 0xA, chunk);
                if (eol != 0) {
                    chunk = (eol + 1) - src;
                }
            }
            if (chunk != 0) {
                MemCopy(M2C_FIELD(stream, s8 **, 0x24), (s8 *)src, chunk);
                scratch = chunk;
                src += scratch;
                M2C_FIELD(stream, s32 *, 0x24) = (s32) (M2C_FIELD(stream, s32 *, 0x24) + scratch);
                remaining -= scratch;
                M2C_FIELD(stream, u32 *, 0x28) = (u32) (M2C_FIELD(stream, u32 *, 0x28) - chunk);
            }
            if (((M2C_FIELD(stream, u32 *, 0x28) == 0) || (eol != 0) || (((u32) (M2C_FIELD(stream, s32 *, 4) << 0x19) >> 0x1E) == 0)) && (StreamFlush(stream, NULL) != 0)) {
                M2C_FIELD(stream, u8 *, 0xD) = 1U;
                remaining = 0;
                M2C_FIELD(stream, u32 *, 0x28) = 0U;
            } else {
                written += chunk;
                if ((remaining != 0) && (chunked != 0)) {
                    goto loop_21;
                }
            }
        }
    }
    if ((remaining != 0) && (chunked == 0)) {
        savedBase = M2C_FIELD(stream, s32 *, 0x1C);
        savedSize = M2C_FIELD(stream, u32 *, 0x20);
        M2C_FIELD(stream, s32 *, 0x1C) = src;
        M2C_FIELD(stream, u32 *, 0x20) = remaining;
        M2C_FIELD(stream, s32 *, 0x24) = (s32) (src + remaining);
        if (StreamFlush(stream, (s32)&chunk) == 0) {
            written += chunk;
        } else {
            M2C_FIELD(stream, u8 *, 0xD) = 1U;
            M2C_FIELD(stream, u32 *, 0x28) = 0U;
        }
        M2C_FIELD(stream, s32 *, 0x1C) = savedBase;
        M2C_FIELD(stream, u32 *, 0x20) = savedSize;
        StreamResetBuffer(stream);
        M2C_FIELD(stream, u32 *, 0x28) = 0U;
    }
    if (((u32) (M2C_FIELD(stream, s32 *, 4) << 0x19) >> 0x1E) != 2) {
        M2C_FIELD(stream, u32 *, 0x28) = 0U;
    }
    return U32DivideRem(written, size);
}
#pragma pop
/* Flushes and closes a file stream, returning -1 if either operation fails. */
s32 CloseFileStream(void *stream) {
    s32 FlushFileStream(void *);
    s32 closeStatus, flushStatus, failed;

    if (!stream) return -1;
    if (FILE_STREAM_KIND(M2C_FIELD(stream, s32 *, FILE_STREAM_MODE)) == 0) return 0;

    flushStatus = FlushFileStream(stream);
    closeStatus = M2C_FIELD(stream, s32 (**)(s32), FILE_STREAM_CLOSE_CB)(
        M2C_FIELD(stream, s32 *, FILE_STREAM_HANDLE));
    failed = 0;
    M2C_FIELD(stream, volatile s32 *, FILE_STREAM_MODE) &= ~FILE_STREAM_KIND_MASK;
    M2C_FIELD(stream, volatile s32 *, FILE_STREAM_HANDLE) = 0;
    if (FILE_STREAM_CLOSE_ERROR(M2C_FIELD(stream, volatile s32 *, FILE_STREAM_STATE)) != 0) return -1;
    if (flushStatus != 0 || closeStatus != 0) failed = 1;
    return -failed;
}
#pragma scheduling on
/* Flushes buffered writes and resets the stream's I/O state. Passing NULL
 * flushes the standard streams. */
s32 FlushFileStream(void *stream) {
    s32 CloseStandardStreams();
    s32 StreamFlush(void *, M2C_UNK);
    s32 temp_r0;
    s32 stateWord;
    s32 stateWord2;

    if (stream == NULL) {
        return CloseStandardStreams();
    }
    if ((M2C_FIELD(stream, u8 *, 0xD) != 0) || (((StreamFlags649 *)stream)->access == 0)) {
        return -1;
    }
    if (((StreamFlags649 *)stream)->mode == 1) {
        return 0;
    }
    stateWord = M2C_FIELD(stream, s32 *, 8);
    if (((StreamFlags649 *)stream)->state >= 3U) {
        ((StreamFlags649 *)stream)->state=2;
    }
    if (((u32) (M2C_FIELD(stream, s32 *, 8) << 0x1D) >> 0x1D) == 2) {
        M2C_FIELD(stream, s32 *, 0x28) = 0;
    }
    stateWord2 = M2C_FIELD(stream, s32 *, 8);
    if (((StreamFlags649 *)stream)->state != 1) {
        ((StreamFlags649 *)stream)->state=0;
        return 0;
    }
    if (StreamFlush(stream, 0) != 0) {
        M2C_FIELD(stream, u8 *, 0xD) = 1U;
        M2C_FIELD(stream, s32 *, 0x28) = 0;
        return -1;
    }
    M2C_FIELD(stream, s32 *, 8) = (s32) (M2C_FIELD(stream, s32 *, 8) & ~7);
    M2C_FIELD(stream, s32 *, 0x18) = 0;
    M2C_FIELD(stream, s32 *, 0x28) = 0;
    return 0;
}

/* Reverse the characters of the NUL-terminated string `s` in place and return it. */
char *StringReverse(char *s) {
    s32 StringLength(char *);
    s32 left = 0;
    s32 right = StringLength(s) - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    return s;
}

#pragma opt_strength_reduction off
/* Write `value` into `buffer` in the given radix (10 gives digits, 16 hex with
 * lower-case letters), prefixed with '-' when negative, and return the buffer;
 * the digits are generated least-significant first and the string reversed. */
char *IntegerToRadixString(s32 value, char *buffer, s32 radix) {
    s32 negative = 0, i = 0, rem;
    if (value < 0) { value = -value; negative = 1; }
    do {
        rem = value % radix;
        if (rem > 9) {
            buffer[i] = (char)(rem + 0x37);
        } else {
            buffer[i] = (char)(rem + 0x30);
        }
        i++;
        value = value / radix;
    } while (value != 0);
    if (negative) {
        buffer[i++] = '-';
    }
    buffer[i] = 0;
    StringReverse(buffer);
    return buffer;
}
#pragma opt_strength_reduction reset
/* GetStreamPosition: report the current read/write position of a stream.
 * A stream that is not open for reading or writing (access 1 or 2) or that has
 * an error set fails with errno 40.  A stream that does not buffer keeps its
 * position directly; otherwise the position is the buffer's file offset plus
 * the bytes used in it, less the bytes a pending flush holds back (the
 * flushing states 3 and up keep one or two extra bytes). */
s32 GetStreamPosition(void *stream) {
    extern s32 gErrno;
    s32 position;
    u32 state;

    if (((u32) (u8) ((u8) ((u32) (u8) (((StreamFlags649 *)stream)->access) + 0xFF)) > 1U) || (M2C_FIELD(stream, u8 *, STREAM_ERROR) != 0)) {
        gErrno = 0x28;
        return -1;
    }
    state = ((StreamFlags649 *)stream)->state;
    if (state == 0) {
        return M2C_FIELD(stream, s32 *, STREAM_POSITION);
    }
    position = M2C_FIELD(stream, s32 *, STREAM_BUFFER_POS) + (M2C_FIELD(stream, s32 *, STREAM_CURSOR) - M2C_FIELD(stream, s32 *, STREAM_BUFFER));
    if (state >= 3U) {
        position -= state - 2;
    }
    return position;
}

/* Reports the current position of stream fp, under the same reentrant per-stream
 * lock SetFilePosition uses: TryLockMutex takes it when free, the holding thread
 * otherwise just bumps gStreamLockDepth, and a different thread blocks in
 * LockMutex.  The lock is released when the outermost caller returns. */
s32 GetFilePosition(void *fp) {
extern u8 gStdinStream[], gStdoutStream[], gStderrStream[], gStreamMutexes[];
extern s32 gStreamLockOwner[], gStreamLockDepth[];
extern M2C_UNK gSocketManager;
s32 TryLockMutex(void *);
s32 GetStreamPosition(void *);
s32 lockIndex, position, owner; void *thread;
if (fp == gStdinStream) lockIndex = 2; else if (fp == gStdoutStream) lockIndex = 3; else if (fp == gStderrStream) lockIndex = 4; else lockIndex = 5;
if (!TryLockMutex(gStreamMutexes + 24 * lockIndex)) {
gStreamLockOwner[lockIndex] = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), s32 *, 0x6c); gStreamLockDepth[lockIndex] = 1;
} else if ((thread = M2C_FIELD(&gSocketManager, void **, 4), owner = gStreamLockOwner[lockIndex], owner == M2C_FIELD(thread, s32 *, 0x6c))) {
gStreamLockDepth[lockIndex]++;
} else { LockMutex(gStreamMutexes + 24 * lockIndex); gStreamLockOwner[lockIndex] = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), s32 *, 0x6c); gStreamLockDepth[lockIndex] = 1; }
position = GetStreamPosition(fp);
if (--gStreamLockDepth[lockIndex] == 0) UnlockMutex(gStreamMutexes + 24 * lockIndex);
return position;
}

/* Sets/updates the transfer position, adjusting buffered stream state, and reports progress through the object's callback. */
s32 func_02064ce8(void *stream, u32 position, s32 mode, ...) {
s32 StreamFlush(void *, s32);
s32 GetStreamPosition(void *);
extern s32 gErrno;
if ((u8)((M2C_FIELD(stream,u32 *,4)<<22)>>29)!=1 || M2C_FIELD(stream,u8 *,13)!=0) { gErrno=40; return -1; }
if (((u32)(M2C_FIELD(stream,s32 *,8)<<29)>>29) ==1 && StreamFlush(stream,0)!=0) { M2C_FIELD(stream,u8 *,13)=1; M2C_FIELD(stream,u32 *,40)=0; gErrno=40; return -1; }
if(mode==1){mode=0;position+=GetStreamPosition(stream);}
if(mode!=2 && (M2C_FIELD(stream,u32 *,4)<<27)>>29 !=3 && (((u32)(M2C_FIELD(stream,s32 *,8)<<29)>>29))-2<=1) {
u32 current=position; u32 base;
if(current>=M2C_FIELD(stream,u32 *,24)) goto clear;
base=M2C_FIELD(stream,u32 *,52); if(current<base) { clear: M2C_FIELD(stream,u32 *,8)&=~7; goto done; }
update: {
M2C_FIELD(stream,u32 *,36)=M2C_FIELD(stream,u32 *,28)+(current-base);
M2C_FIELD(stream,u32 *,40)=M2C_FIELD(stream,u32 *,24)-position;
M2C_FIELD(stream,u32 *,8)=(M2C_FIELD(stream,u32 *,8)&~7)|2;
}
}else M2C_FIELD(stream,u32 *,8)&=~7;
done:
if(((u32)(M2C_FIELD(stream,s32 *,8)<<29)>>29) ==0){
s32 (*callback)(s32,u32 *,s32,s32)=M2C_FIELD(stream,s32 (**)(s32,u32 *,s32,s32),56);
if(callback && callback(M2C_FIELD(stream,s32 *,0),&position,mode,M2C_FIELD(stream,s32 *,72))!=0){
M2C_FIELD(stream,u8 *,13)=1; M2C_FIELD(stream,u32 *,40)=0; gErrno=40;return -1;
}
M2C_FIELD(stream,u8 *,12)=0;M2C_FIELD(stream,u32 *,24)=position;M2C_FIELD(stream,u32 *,40)=0;
}
return 0;
}

/* Seeks stream fp to pos with fseek-style whence (0 = start, 1 = current,
 * 2 = end).  The seek runs under the stream's shared lock, which is taken
 * reentrantly (the holding thread and its nest count are kept in
 * gStreamLockOwner/gStreamLockDepth) and released when the outermost caller is
 * done. */
s32 SetFilePosition(void *fp, s32 pos, s32 whence) {
s32 TryLockMutex(void *); M2C_UNK LockMutex(); M2C_UNK UnlockMutex();
s32 lockIndex, result, owner; void *thread;
if(fp==gStdinStream)lockIndex=2;else if(fp==gStdoutStream)lockIndex=3;else if(fp==gStderrStream)lockIndex=4;else lockIndex=5;
if(TryLockMutex(gStreamMutexes+lockIndex*24)==0) {
gStreamLockOwner[lockIndex]=M2C_FIELD(M2C_FIELD(&gSocketManager,void **,4),s32 *,108);
gStreamLockDepth[lockIndex]=1;
}else if((thread=M2C_FIELD(&gSocketManager,void **,4),owner=gStreamLockOwner[lockIndex],owner==M2C_FIELD(thread,s32 *,108))) {gStreamLockDepth[lockIndex]++;}
else{LockMutex(gStreamMutexes+lockIndex*24);
gStreamLockOwner[lockIndex]=M2C_FIELD(M2C_FIELD(&gSocketManager,void **,4),s32 *,108);
gStreamLockDepth[lockIndex]=1;
}
result=func_02064ce8(fp,pos,whence);
if(--gStreamLockDepth[lockIndex]==0)UnlockMutex(gStreamMutexes+lockIndex*24);
return result;
}

#pragma opt_propagation off
void RewindStream(void *arg0) {
    M2C_UNK SetFilePosition(void *, M2C_UNK, M2C_UNK);
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    SetFilePosition(arg0, 0, 0);
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
}
#pragma opt_propagation reset
M2C_UNK func_02065020(M2C_UNK a,M2C_UNK b,M2C_UNK c) {
 extern u32 data_0210040c[];
 return (*(M2C_UNK (**)(M2C_UNK,M2C_UNK,M2C_UNK))data_0210040c[2])(a,b,c);
}

s32 func_0206503c(s16 *arg0, u8 *arg1, s32 arg2) {
    if (arg1 == NULL) {
        return 0;
    }
    if (arg2 == 0) {
        return -1;
    }
    if (arg0 != NULL) {
        *arg0 = (s16) *arg1;
    }
    if ((s8) *arg1 == 0) {
        return 0;
    }
    return 1;
}

s32 func_02065074(s8 *arg0, s8 arg1) {
    if (arg0 == NULL) {
        return 0;
    }
    *arg0 = arg1;
    return 1;
}

s32 WideCharToMultibyte(s8 *a,u16 b) {
extern u32 data_0210040c[];
return (*(s32 (**)(s8 *,u16))(data_0210040c[2]+4))(a,b);
}

/* Convert the multibyte string `in` to wide characters at `out`, at most `count`
 * of them: each character is converted with the locale's mbtowc
 * (data_0210040c[2]), and the string's NUL is stored as the end.  Returns the
 * number of characters stored, or -1 when a character cannot be converted. */
u32 StringToWideString(s16 *out, char *in, u32 count) {
    s32 StringLength(char *);
    u32 index;
    s32 left;
    s32 length;

    left = StringLength(in);
    index = 0;
    if (out) {
        for (; index < count; index++) {
            if (*in) {
                length = func_02065020(out, in, left);
                out++;
                if (length > 0) {
                    in += length;
                    left -= length;
                } else return -1;
            } else {
                *out = 0;
                break;
            }
        }
    }
    return index;
}

/* Convert the wide string `in` to multibyte characters at `out`, converting each
 * character with the locale's wctomb and terminating at the string's NUL; at most
 * `maxBytes` bytes are written.  Returns the number of bytes written. */
u32 WideStringToString(s8 *out,u16 *in,u32 maxBytes) {
void StringCopyPad(void *,void *,u32);
s8 buf[4];
u32 used=0;
if(!out || !in) return 0;
do {
u32 len;
if(!*in) {out[used]=0;break;}
len=WideCharToMultibyte(buf,*in++);
if(used+len>maxBytes) break;
StringCopyPad(out+used,buf,len);
used+=len;
} while(used<=maxBytes);
return used;
}

s8 *MemCopy(s8 *out,s8 *in,s32 n) {
s8 *p=out;
if(n) do {s8 c=*in++;--n;*p++=c;} while(n);
return out;
}

/* Copy `count` bytes from `src` to `dst`: forward when dst is at or after src,
 * backward (from the end) when the ranges overlap the other way. */
void *MemMove(char *dst, char *src, u32 count) {
    if (src >= dst) {
        char *to = dst;
        if (count) { do { *to++ = *src++; } while (--count); }
    } else {
        char *from = src + count;
        char *to = dst + count;
        if (count) { do { *--to = *--from; } while (--count); }
    }
    return dst;
}

s32 MemSet(s32 arg0) {
    M2C_UNK MemFill();
    MemFill();
    return arg0;
}

u8 *func_02065224(u8 *p,s32 value,u32 n) {
 u32 c=(u8)value;
 if(n) { do { if(*p++==c) return p-1; } while(--n); }
 return NULL;
}

u8 *FindLastByte(u8 *p,s32 value,u32 n) {
 u32 c=(u8)value;
 p+=n;
 if(n) { do { if(*--p==c) return p; } while(--n); }
 return NULL;
}

s32 ByteCompareN(u8 *a,u8 *b,u32 n) {
 if(n) { do {
 u32 x=*a++; u32 y=*b++;
 if(x!=y) return a[-1]<b[-1]?-1:1;
 } while(--n); }
 return 0;
}

/* Fill n bytes at p with the byte value and return the address one past them:
   align p to a word, expand the byte into all four lanes, store 32 bytes at a
   time, then whole words, then the trailing bytes. */
M2C_UNK MemFill(u8 *p, s32 value, u32 n) {
    u32 fill = (u8)value;
    u32 words;
    if (n >= 32) {
        words = (-(u32)p) & 3;
        if (words) {
            n -= words;
            do { *p++ = (u8)fill; } while (--words);
        }
        if (fill == 0) goto skip_expand;
        fill |= ((fill << 24) | (fill << 16)) | (fill << 8);
    skip_expand:
        words = n >> 5;
        if (words) do {
            ((u32 *)p)[0] = fill; ((u32 *)p)[1] = fill; ((u32 *)p)[2] = fill; ((u32 *)p)[3] = fill;
            ((u32 *)p)[4] = fill; ((u32 *)p)[5] = fill; ((u32 *)p)[6] = fill; ((u32 *)p)[7] = fill;
            p += 32;
        } while (--words);
        words = (n & 31) >> 2;
        if (words) do { *(u32 *)p = fill; p += 4; } while (--words);
        n &= 3;
    }
    if (n) do { *p++ = (u8)fill; } while (--n);
    (void)words;
    return (s32)p;
}

