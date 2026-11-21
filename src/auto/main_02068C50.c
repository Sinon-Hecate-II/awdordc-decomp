/* 8 functions from 0x02068C50 to 0x02069048 (main), found by ds-decomp. */
#include "common.h"

/* Copy a NUL-terminated string: byte by byte until both pointers share an
 * alignment, then a word at a time while no word of the source holds a NUL
 * byte.  Returns the destination. */
unsigned char *StringCopy(unsigned char *dst, const unsigned char *src) {
    unsigned char *out = dst;
    u32 lead = (u32)src & 3;
    u32 word, zeros, notWord;
    if (((u32)dst & 3) == lead) {
        if (lead) {
            if (!(*out = *src)) return dst;
            lead = 3 - lead;
            while (lead) {
                if (!(*++out = *++src)) return dst;
                --lead;
            }
            ++out; ++src;
        }
        word = *(const u32 *)src;
        if (!((word + STRING_ZERO_BIAS) & ~word & STRING_ZERO_MASK)) {
            out -= 4;
            do {
                *(u32 *)(out += 4) = word;
                src += 4;
                word = *(const u32 *)src;
                zeros = word + STRING_ZERO_BIAS;
                notWord = ~word;
                zeros = notWord & zeros;
            } while (!(zeros & STRING_ZERO_MASK));
            out += 4;
        }
    }
    if (!(*out = *src)) return dst;
    while ((*++out = *++src) != 0) {}
    return dst;
}

s8 *StringCopyPad(s8 *a,s8 *b,s32 n) {
s8 *p=a;
if(n==0) return a;
do {
if((*p++=*b++)==0) {
if(--n==0) return a;
do { *p++=0; } while(--n);
return a;
}
} while(--n);
return a;
}

s8 *StringAppend(s8 *a,s8 *b) {
s8 *p=a;
while(*p++);
p--;
while((*p++=*b++)!=0);
return a;
}

/* Compare two NUL-terminated strings: byte by byte until both pointers share an
 * alignment, then a word at a time while no word of the first holds a NUL byte.
 * Returns the difference of the first differing bytes, 0 when equal. */
s32 StringCompare(u8 *a,u8 *b){
u32 ca,cb,wb; s32 diff,align;
ca=*a; diff=ca-*b; if(diff)return diff;
align=(u32)a&3;
if(((u32)b&3)==align){
if(align){
if(!ca)return 0;
align=3-align;
while(align){cb=*++a;diff=cb-*++b;if(diff)return diff;if(!cb)return 0;align--;}
a++;b++;
}
ca=*(u32 *)a;
wb=*(u32 *)b;
if(!((ca+STRING_ZERO_BIAS)&~ca&STRING_ZERO_MASK)){
while(ca==wb){
a+=4;b+=4;ca=*(u32 *)a;wb=*(u32 *)b;
if((ca+STRING_ZERO_BIAS)&STRING_ZERO_MASK)goto bytes;
}
a--;b--;goto next;
}
bytes:
ca=*a;diff=ca-*b;if(diff)return diff;
}
next:
if(!ca)return 0;
do{ca=*++a;diff=ca-*++b;if(diff)return diff;}while(ca);
return 0;
}

s32 StringCompareN(u8 *a,u8 *b,s32 n) {
if(n) {
do {
u32 y=*b++;
u32 x=*a++;
if(x!=y) return x-y;
if(x==0) break;
} while(--n);
}
return 0;
}

s8 *StringFindChar(s8 *a,s32 b) {
s8 c=*a++;
b=(s8)b;
while(c!=0) {
if(c==b) return a-1;
c=*a++;
}
if(b!=0) return 0;
return a-1;
}

/* strspn: returns the length of the leading run of `string` made up only of
 * bytes that also occur in `accept` (the bytes up to the first one that does
 * not), marking the accept set in a 256-bit bitmap first. */
s32 StringSpanUntil(u8 *string, u8 *accept) {
    u8 bitmap[32];
    u32 i = 8;
    u8 *p = bitmap;
    s32 c;
    u8 *q;

    do { p[0]=0; p[1]=0; p[2]=0; p[3]=0; p+=4; } while (--i);
    c=*accept; q=accept+1;
    while (c) {
        bitmap[(s32)(u8)c>>3] |= (u8)(1<<(c&7));
        c=*q++;
    }
    c=*string; q=string+1;
    while (c) {
        if (bitmap[(s32)(u8)c>>3] & (u8)(1<<(c&7))) break;
        c=*q++;
    }
    return q-string-1;
}

/* strstr: return a pointer to the first occurrence of `needle` in `text`, or
 * NULL when it does not occur.  An empty needle matches the start of `text`. */
u8 *StringFind(u8 *text,u8 *needle) {
u8 first,c,wanted,found;
u8 *p,*scan,*q;
if(!needle || !(first=*needle)) return text;
c=*text;
p=text+1;
while(c) {
if(c==first) {
scan=p;q=needle+1;
do {wanted=*q++;found=*scan++;} while(found==wanted && found);
if(!wanted) return p-1;
}
c=*p++;
}
return 0;
}

