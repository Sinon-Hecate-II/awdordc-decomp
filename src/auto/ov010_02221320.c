/* 5 functions from 0x02221320 to 0x022221B8 (ov010), found by ds-decomp. */
#include "common.h"

void func_ov010_02221320(u8 *arg0, void *arg1, u32 arg2, void *arg3) {
    extern s8 data_ov010_0222bd68[];
    extern s16 data_ov010_0222bd78[];
    s16 temp_r11;
    s16 temp_r11_2;
    s16 temp_r8;
    s16 temp_r8_2;
    s16 temp_r8_3;
    s16 temp_r8_4;
    s32 temp_r10;
    s32 temp_r10_2;
    s32 var_r7;
    s32 var_r7_2;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r9;
    s32 var_r9_2;
    u32 var_r6;
    u8 *var_r0;
    u8 temp_r7;
    u8 temp_r7_2;
    void *var_r1;

    var_r0 = arg0;
    var_r1 = arg1;
    var_r6 = 0;
    if (arg2 <= 0U) {
        return;
    }
    do {
        temp_r7 = M2C_FIELD(arg3, u8 *, 2);
        temp_r8 = M2C_FIELD(arg3, s16 *, 0);
        temp_r11 = data_ov010_0222bd78[temp_r7];
        temp_r10 = *var_r0 & 0xF;
        var_r9 = temp_r11 >> 3;
        if (temp_r10 & 4) {
            var_r9 += temp_r11;
        }
        if (temp_r10 & 2) {
            var_r9 += temp_r11 >> 1;
        }
        if (temp_r10 & 1) {
            var_r9 += temp_r11 >> 2;
        }
        if (temp_r10 & 8) {
            var_r8 = temp_r8 - var_r9;
            if (var_r8 < -0x8000) {
                var_r8 = -0x8000;
            }
        } else {
            var_r8 = temp_r8 + var_r9;
            if (var_r8 > 0x7FFF) {
                var_r8 = 0x7FFF;
            }
        }
        var_r7 = temp_r7 + data_ov010_0222bd68[temp_r10];
        if (var_r7 < 0) {
            var_r7 = 0;
        } else if (var_r7 > 0x58) {
            var_r7 = 0x58;
        }
        temp_r8_2 = (s16) var_r8;
        M2C_FIELD(arg3, s16 *, 0) = temp_r8_2;
        M2C_FIELD(arg3, u8 *, 2) = (u8) var_r7;
        M2C_FIELD(var_r1, s16 *, 0) = temp_r8_2;
        temp_r7_2 = M2C_FIELD(arg3, u8 *, 2);
        temp_r8_3 = M2C_FIELD(arg3, s16 *, 0);
        temp_r11_2 = data_ov010_0222bd78[temp_r7_2];
        temp_r10_2 = ((s32) *var_r0 >> 4) & 0xF;
        var_r9_2 = temp_r11_2 >> 3;
        if (temp_r10_2 & 4) {
            var_r9_2 += temp_r11_2;
        }
        if (temp_r10_2 & 2) {
            var_r9_2 += temp_r11_2 >> 1;
        }
        if (temp_r10_2 & 1) {
            var_r9_2 += temp_r11_2 >> 2;
        }
        if (temp_r10_2 & 8) {
            var_r8_2 = temp_r8_3 - var_r9_2;
            if (var_r8_2 < -0x8000) {
                var_r8_2 = -0x8000;
            }
        } else {
            var_r8_2 = temp_r8_3 + var_r9_2;
            if (var_r8_2 > 0x7FFF) {
                var_r8_2 = 0x7FFF;
            }
        }
        var_r7_2 = temp_r7_2 + data_ov010_0222bd68[temp_r10_2];
        if (var_r7_2 < 0) {
            var_r7_2 = 0;
        } else if (var_r7_2 > 0x58) {
            var_r7_2 = 0x58;
        }
        temp_r8_4 = (s16) var_r8_2;
        M2C_FIELD(arg3, s16 *, 0) = temp_r8_4;
        M2C_FIELD(arg3, u8 *, 2) = (u8) var_r7_2;
        var_r6 += 1;
        M2C_FIELD(var_r1, s16 *, 2) = temp_r8_4;
        var_r1 += 4;
        var_r0 += 1;
    } while (var_r6 < arg2);
}

void func_ov010_02221474(s8 *arg0, void *arg1, u32 arg2, void *arg3) {
    extern s8 data_ov010_0222bd68[];
    extern s16 data_ov010_0222bd78[];
    s8 *var_r0;
    void *var_r1;
    u32 temp_r2;
    u32 var_r4;
    s32 var_r5;
    s32 var_r6;
    u8 temp_r6;
    s16 temp_r7;
    s32 savedIndex;
    u32 temp_r8;
    s32 temp_r9;
    s32 temp_r9_2;
    s32 temp_r10;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r11;
    s32 var_r11_2;

    var_r0 = arg0;
    var_r1 = arg1;
    temp_r8 = arg2 >> 1;
    var_r4 = 0;
    if (temp_r8 == 0) {
        return;
    }
    temp_r2 = -0x8000U >> 0x11;
    do {
        temp_r6 = M2C_FIELD(arg3, u8 *, 2);
        temp_r7 = M2C_FIELD(arg3, s16 *, 0);
        temp_r9 = data_ov010_0222bd78[temp_r6];
        var_r10 = M2C_FIELD(var_r1, volatile s16 *, 0) - temp_r7;
        if (var_r10 < 0) {
            var_r5 = 8;
            var_r10 = 0 - var_r10;
        } else {
            var_r5 = 0;
        }
        if (var_r10 >= (s32) temp_r9) {
            var_r5 |= 4;
            var_r10 -= temp_r9;
        }
        if (var_r10 >= (s32) (temp_r9 >> 1)) {
            var_r5 |= 2;
            var_r10 -= temp_r9 >> 1;
        }
        if (var_r10 >= (s32) (temp_r9 >> 2)) {
            var_r5 |= 1;
        }
        var_r10_2 = temp_r9 >> 3;
        if (var_r5 & 4) {
            var_r10_2 += temp_r9;
        }
        if (var_r5 & 2) {
            var_r10_2 += temp_r9 >> 1;
        }
        if (var_r5 & 1) {
            var_r10_2 += temp_r9 >> 2;
        }
        if (var_r5 & 8) {
            var_r10_2 = 0 - var_r10_2;
        }
        temp_r9 = temp_r7 + var_r10_2;
        if (temp_r9 < -0x8000) {
            temp_r9 = -0x8000;
        }
        if (temp_r9 > (s32) temp_r2) {
            temp_r9 = (s32) temp_r2;
        }
        var_r6 = temp_r6 + data_ov010_0222bd68[var_r5];
        if (var_r6 < 0) {
            var_r6 = 0;
        } else if (var_r6 > 0x58) {
            var_r6 = 0x58;
        }
        M2C_FIELD(arg3, s16 *, 0) = (s16) temp_r9;
        M2C_FIELD(arg3, s8 *, 2) = (s8) var_r6;
        temp_r9_2 = M2C_FIELD(arg3, s16 *, 0);
        savedIndex = (u8)var_r6;
        temp_r10 = data_ov010_0222bd78[savedIndex];
        var_r11 = M2C_FIELD(var_r1, volatile s16 *, 2) - temp_r9_2;
        if (var_r11 < 0) {
            var_r6 = 8;
            var_r11 = 0 - var_r11;
        } else {
            var_r6 = 0;
        }
        if (var_r11 >= (s32) temp_r10) {
            var_r6 |= 4;
            var_r11 -= temp_r10;
        }
        if (var_r11 >= (s32) (temp_r10 >> 1)) {
            var_r6 |= 2;
            var_r11 -= temp_r10 >> 1;
        }
        if (var_r11 >= (s32) (temp_r10 >> 2)) {
            var_r6 |= 1;
        }
        var_r11_2 = temp_r10 >> 3;
        if (var_r6 & 4) {
            var_r11_2 += temp_r10;
        }
        if (var_r6 & 2) {
            var_r11_2 += temp_r10 >> 1;
        }
        if (var_r6 & 1) {
            var_r11_2 += temp_r10 >> 2;
        }
        if (var_r6 & 8) {
            var_r11_2 = 0 - var_r11_2;
        }
        temp_r10 = temp_r9_2 + var_r11_2;
        if (temp_r10 < -0x8000) {
            temp_r10 = -0x8000;
        }
        if (temp_r10 > (s32) temp_r2) {
            temp_r10 = (s32) temp_r2;
        }
        savedIndex = savedIndex + data_ov010_0222bd68[var_r6];
        var_r1 += 4;
        if (savedIndex < 0) {
            savedIndex = 0;
        } else if (savedIndex > 0x58) {
            savedIndex = 0x58;
        }
        M2C_FIELD(arg3, s16 *, 0) = (s16) temp_r10;
        M2C_FIELD(arg3, s8 *, 2) = (s8) savedIndex;
        *var_r0 = (s8)((u8)var_r5 | ((u8)var_r6 << 4));
        var_r0 += 1;
        var_r4 += 1;
    } while (var_r4 < temp_r8);
}

#pragma scheduling on
void func_ov010_02221fa0(u8 *arg0,void *arg1,u32 arg2,void *arg3){extern s8 data_ov010_0222bd5c[];extern s16 data_ov010_0222bd78[];u32 i;s32 idx,pred,code,step; s16 sample;
i=0;if(i>=arg2)return;do{
code=((s32)*arg0>>0)&3;idx=M2C_FIELD(arg3,u8 *,2);pred=M2C_FIELD(arg3,s16 *,0);step=data_ov010_0222bd78[idx];if(!(code&1))step=0;if(code&2){pred-=step;if(pred< -32768)pred=-32768;}else{pred+=step;if(pred>32767)pred=32767;}idx+=data_ov010_0222bd5c[code];if(idx<0)idx=0;else if(idx>88)idx=88;sample=pred;M2C_FIELD(arg3,s16 *,0)=sample;M2C_FIELD(arg3,u8 *,2)=idx;M2C_FIELD(arg1,s16 *,0)=sample;
code=((s32)*arg0>>2)&3;idx=M2C_FIELD(arg3,u8 *,2);pred=M2C_FIELD(arg3,s16 *,0);step=data_ov010_0222bd78[idx];if(!(code&1))step=0;if(code&2){pred-=step;if(pred< -32768)pred=-32768;}else{pred+=step;if(pred>32767)pred=32767;}idx+=data_ov010_0222bd5c[code];if(idx<0)idx=0;else if(idx>88)idx=88;sample=pred;M2C_FIELD(arg3,s16 *,0)=sample;M2C_FIELD(arg3,u8 *,2)=idx;M2C_FIELD(arg1,s16 *,2)=sample;
code=((s32)*arg0>>4)&3;idx=M2C_FIELD(arg3,u8 *,2);pred=M2C_FIELD(arg3,s16 *,0);step=data_ov010_0222bd78[idx];if(!(code&1))step=0;if(code&2){pred-=step;if(pred< -32768)pred=-32768;}else{pred+=step;if(pred>32767)pred=32767;}idx+=data_ov010_0222bd5c[code];if(idx<0)idx=0;else if(idx>88)idx=88;sample=pred;M2C_FIELD(arg3,s16 *,0)=sample;M2C_FIELD(arg3,u8 *,2)=idx;M2C_FIELD(arg1,s16 *,4)=sample;
code=((s32)*arg0>>6)&3;idx=M2C_FIELD(arg3,u8 *,2);pred=M2C_FIELD(arg3,s16 *,0);step=data_ov010_0222bd78[idx];if(!(code&1))step=0;if(code&2){pred-=step;if(pred< -32768)pred=-32768;}else{pred+=step;if(pred>32767)pred=32767;}idx+=data_ov010_0222bd5c[code];if(idx<0)idx=0;else if(idx>88)idx=88;sample=pred;M2C_FIELD(arg3,s16 *,0)=sample;M2C_FIELD(arg3,u8 *,2)=idx;i++;M2C_FIELD(arg1,s16 *,6)=sample;
arg1+=8;arg0++;}while(i<arg2);}
