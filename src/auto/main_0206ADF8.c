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

u16 *func_0206b5c0(s64 value, u16 *end, FormatFlags flags) {
s32 width; s32 negative=0; s32 precision=flags.precision; u64 base; u16 *p=end; s32 count=0; s32 digit; s32 sign; u16 type; u8 alt;
*--p=0;
alt=flags.alternate; type=flags.conversion; width=flags.width; sign=flags.sign;
if(value==0 && precision==0) { if(!alt || type!='o') return p; }
switch(type) {
case 'd': case 'i': base=10; if(value<0) { if(value != (s64)0x8000000000000000ULL) value=-value; negative=1; } break;
case 'o': base=8; sign=0; break;
case 'u': base=10; sign=0; break;
case 'x': case 'X': base=16; sign=0; break;
}
do { digit=(u64)value%base; value=(u64)value/base; if(digit<10) digit+='0'; else if(type=='x') digit+=87; else digit+=55; *--p=digit; ++count; } while(value!=0);
if(base==8 && alt && *p!='0') { *--p='0'; ++count; }
if(flags.pad==2) { precision=width; if(negative || sign) --precision; if(base==16 && alt) precision-=2; }
if(precision+(end-p)>509) return 0;
while(count<precision) { *--p='0'; ++count; }
if(base==16 && alt) { *--p=type; *--p='0'; }
if(negative) *--p='-'; else if(sign==1) *--p='+'; else if(sign==2) *--p=' ';
return p;
}

u16 *func_0206b8c0(double value, u16 *end, FormatFlags fmt) {
    u16 *func_0206cdac(u16 *, u16 *);
    void func_0206f034(void *, double, void *);
    u16 *func_0206b370(s32, u16 *, FormatFlags);
    double func_0206dfb0(double);
    extern u16 data_02100558[], data_02100564[], data_02100570[], data_0210057c[], data_02100584[], data_0210058c[], data_02100598[], data_021005a4[], data_021005ac[];
    FormatFlags f;
    u16 *p;
    s32 precision;
    u8 spec;
    u8 alt;
    s8 signFlag;
    u8 *bytes;
    int i, bit, n;
    s8 tmp;
    s32 exp;
    u8 conv[4];
    u8 decimal[40];
    p = end;
    precision = fmt.precision;
    spec = fmt.conversion;
    alt = fmt.alternate;
    signFlag = fmt.sign;
    if (precision > 509) return 0;
    conv[0] = 0; *(u16 *)(conv + 2) = 32;
    func_0206f034(conv, value, decimal);
    if (func_0206dfb0(value) == 0.0) {
        p = end - 6;
        func_0206cdac(p, data_02100558);
        return p;
    }
    if (decimal[5] == 'I') {
        if (*(s8 *)decimal != 0) {
            p = end - 5;
            if (spec == 'A') func_0206cdac(p, data_02100564);
            else func_0206cdac(p, data_02100570);
            return p;
        }
        p = end - 4;
        if (spec == 'A') func_0206cdac(p, data_0210057c);
        else func_0206cdac(p, data_02100584);
        return p;
    }
    if (decimal[5] == 'N') {
        if (*(s8 *)decimal != 0) {
            p = end - 5;
            if (spec == 'A') func_0206cdac(p, data_0210058c);
            else func_0206cdac(p, data_02100598);
            return p;
        }
        p = end - 4;
        if (spec == 'A') func_0206cdac(p, data_021005a4);
        else func_0206cdac(p, data_021005ac);
        return p;
    }
    bytes = (u8 *)&value;
    for (i = 0; i < 4; i++) { tmp = bytes[i]; bytes[i] = bytes[7 - i]; bytes[7 - i] = tmp; }
    exp = ((((u32)bytes[1]) << 17) | (((u32)bytes[0]) << 25)) >> 21 & 0x7ff;
    exp = exp - 1023;
    f.pad = 1; f.sign = 1; f.unused = 0; f.alternate = 0; f.reserved = 0; f.conversion = 'd'; f.width = 0; f.precision = 1;
    p = func_0206b370(exp, end, f);
    *--p = (spec == 'a' ? 'p' : 'P');
    bit = precision * 4 + 11;
    n = precision;
    while (n >= 1) {
        u8 digit;
        if (bit < 64) {
            int shift = 7 - (bit & 7);
            digit = bytes[bit >> 3] >> shift;
            if (((bit & ~7) != ((bit - 4) & ~7)))
                digit = (u8)(digit | (bytes[(bit >> 3) - 1] << 8) >> shift);
            digit &= 0x0f;
            if (digit < 10) digit += '0';
            else if (spec == 'a') digit += 87;
            else digit += 55;
        } else {
            digit = '0';
        }
        --n;
        *--p = digit;
        bit -= 4;
    }
    if (precision || alt) *--p = '.';
    p[-1] = '1';
    p -= 2;
    *p = (spec == 'a' ? 'x' : 'X');
    *--p = '0';
    if (*(s8 *)decimal != 0) *--p = '-';
    else if (signFlag == 1) *--p = '+';
    else if (signFlag == 2) *--p = ' ';
    return p;
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
