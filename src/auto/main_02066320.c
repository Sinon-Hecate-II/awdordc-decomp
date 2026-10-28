/* 2 functions from 0x02066320 to 0x02066BA8 (main), found by ds-decomp. */
#include "common.h"

/* Rounds the decimal string in an object at the given digit position. */
void func_02066320(void *str, s32 pos) {
    s32 carry;
    s8 *tail;
    s8 *p;
    s8 digit;
    u8 len;
    s8 *start;
    if (pos < 0) {
zero:
        M2C_FIELD(str,s16 *,2)=0;
        M2C_FIELD(str,u8 *,4)=1;
        M2C_FIELD(str,s8 *,5)='0';
        return;
    }
    len=M2C_FIELD(str,u8 *,4);
    if (pos >= len) return;
    start=(s8 *)str+5;
    p=start+pos+1;
    digit=*--p-'0';
    if (digit == 5) {
        tail=start+len;
        do { --tail; } while (tail > p && *tail == '0');
        if (tail == p) carry=p[-1]&1;
        else carry=1;
    } else {
        carry=digit > 5;
    }
    if (pos != 0) {
        do {
            digit=(*--p-'0')+carry;
            carry=digit > 9;
            if (carry != 0 || digit == 0) {
                --pos;
            } else {
                *p=digit+'0';
                break;
            }
        } while (pos != 0);
    }
    if (carry != 0) {
        M2C_FIELD(str,s16 *,2)++;
        M2C_FIELD(str,u8 *,4)=1;
        M2C_FIELD(str,s8 *,5)='1';
        return;
    }
    if (pos == 0) goto zero;
    M2C_FIELD(str,u8 *,4)=pos;
}

void func_02066444(void) {
    return;
}

