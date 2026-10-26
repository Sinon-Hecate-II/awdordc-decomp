/* 5 functions from 0x0206ADF8 to 0x0206BD7C (main), found by ds-decomp. */
#include "common.h"

/* Rounds the decimal number held at `number` at digit position `digitPos`. */
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
