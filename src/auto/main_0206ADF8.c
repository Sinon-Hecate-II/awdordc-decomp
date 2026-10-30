/* 5 functions from 0x0206ADF8 to 0x0206BD7C (main), found by ds-decomp. */
#include "common.h"

typedef struct { u8 pad, sign, unused, alternate; u16 reserved, conversion; s32 width, precision; } FormatFlags;

/* Rounds the decimal number held at `number` at digit position `digitPos`. */
M2C_UNK func_0206adf8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK *arg2) {
    return arg0;
}

u16 *func_0206b370(s32 value, u16 *end, FormatFlags flags) {
s32 width; s32 precision=flags.precision; s32 negative=0; u16 base; u16 *p=end; s32 count=0; s32 digit; s32 sign; u16 type; u8 alt;
*--p=0;
alt=flags.alternate; type=flags.conversion; width=flags.width; sign=flags.sign;
if(value==0 && precision==0) { if(!alt || type!='o') return p; }
switch(type) {
case 'd': case 'i': base=10; if(value<0) { if(value != (s32)0x80000000) value=-value; negative=1; } break;
case 'o': base=8; sign=0; break;
case 'u': base=10; sign=0; break;
case 'x': case 'X': base=16; sign=0; break;
}
do { digit=(u32)value%base; value=(u32)value/base; if(digit<10) digit+='0'; else if(type=='x') digit+=87; else digit+=55; *--p=digit; ++count; } while(value!=0);
if(base==8 && alt && *p!='0') { *--p='0'; ++count; }
if(flags.pad==2) { precision=width; if(negative || sign) --precision; if(base==16 && alt) precision-=2; }
if(precision+(end-p)>509) return 0;
while(count<precision) { *--p='0'; ++count; }
if(base==16 && alt) { *--p=type; *--p='0'; }
if(negative) *--p='-'; else if(sign==1) *--p='+'; else if(sign==2) *--p=' ';
return p;
}

M2C_UNK func_0206b5c0(void) {
    return 0;
}

M2C_UNK func_0206b8c0(M2C_UNK arg0) {
    return 0;
}

void func_0206bc58(void *number, s32 digitPos) {
    s32 carry;
    s8 *tail;
    s8 *p;
    s8 digit;
    u8 len;
    s8 *start;
    if (digitPos < 0) {
zero:
        M2C_FIELD(number,s16 *,2)=0;
        M2C_FIELD(number,u8 *,4)=1;
        M2C_FIELD(number,s8 *,5)='0';
        return;
    }
    len=M2C_FIELD(number,u8 *,4);
    if (digitPos >= len) return;
    start=(s8 *)number+5;
    p=start+digitPos+1;
    digit=*--p-'0';
    if (digit == 5) {
        tail=start+len;
        do { --tail; } while (tail > p && *tail == '0');
        if (tail == p) carry=p[-1]&1;
        else carry=1;
    } else {
        carry=digit > 5;
    }
    if (digitPos != 0) {
        do {
            digit=(*--p-'0')+carry;
            carry=digit > 9;
            if (carry != 0 || digit == 0) {
                --digitPos;
            } else {
                *p=digit+'0';
                break;
            }
        } while (digitPos != 0);
    }
    if (carry != 0) {
        M2C_FIELD(number,s16 *,2)++;
        M2C_FIELD(number,u8 *,4)=1;
        M2C_FIELD(number,s8 *,5)='1';
        return;
    }
    if (digitPos == 0) goto zero;
    M2C_FIELD(number,u8 *,4)=digitPos;
}
