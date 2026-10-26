/* 10 functions from 0x02202DC8 to 0x02203710 (ov003), found by ds-decomp. */
#include "common.h"

typedef struct {
    s32 field_00;
    u8  field_04;
    u8  pad_05[7];
    s32 value;
    s32 max;
    s32 min;
} Ov003Elem; /* size 0x18 */

void func_ov003_02202dc8(void *arg0, s32 arg1) {
    s32 off = arg1 * 24;
    *(s32 *)((char *)arg0 + 12 + off) += *(s32 *)((char *)arg0 + off + 24);
    if (*(u8 *)((char *)arg0 + off + 28) != 0) {
        while (*(s32 *)((char *)arg0 + 12 + off) > *(s32 *)((char *)arg0 + off + 16)) {
            *(s32 *)((char *)arg0 + 12 + off) -= (*(s32 *)((char *)arg0 + off + 16) - *(s32 *)((char *)arg0 + off + 20) + 1);
        }
        while (*(s32 *)((char *)arg0 + 12 + off) < *(s32 *)((char *)arg0 + off + 20)) {
            *(s32 *)((char *)arg0 + 12 + off) += (*(s32 *)((char *)arg0 + off + 16) - *(s32 *)((char *)arg0 + off + 20) + 1);
        }
    } else {
        if (*(s32 *)((char *)arg0 + 12 + off) > *(s32 *)((char *)arg0 + off + 16)) {
            *(s32 *)((char *)arg0 + 12 + off) = *(s32 *)((char *)arg0 + off + 16);
        } else if (*(s32 *)((char *)arg0 + 12 + off) < *(s32 *)((char *)arg0 + off + 20)) {
            *(s32 *)((char *)arg0 + 12 + off) = *(s32 *)((char *)arg0 + off + 20);
        }
    }
}

u8 func_ov003_02202e94(s32 arg0, s32 arg1) {
    u8 temp = arg1 + 0xFF;
    u8 result = 0;
    if ((u32)temp <= 5U) {
        result = ((1 << temp) & 0x23) ? 1 : result;
    }
    return result;
}

void func_ov003_02203280(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020d47d0();
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_UNK func_ov003_021f1bd4();
    s32 func_ov003_02200c7c();
    M2C_UNK func_ov003_02204fac(void *);
    extern u16 data_02168f14;
    void **temp_r0_2;
    void *temp_r0;
    func_020d47d0();
    func_0208fe30(0x1000E);
    temp_r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), void **, 4);
    if ((s32) M2C_FIELD(temp_r0, s8 *, 0x5A) >= 0) {
        M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0, s8 *, 0x5A) = 0xC;
    }
    func_ov003_021f1bd4();
    { s32 temp_r6 = M2C_FIELD(arg0, s32 *, 0x44);
    u8 var_r7 = 0;
    do {
        temp_r0_2 = M2C_FIELD((temp_r6 + (var_r7 * 4)), void ***, 0xC8);
        M2C_FIELD(*temp_r0_2, M2C_UNK (**)(void **, s32), 0x1C)(temp_r0_2, M2C_FIELD(((var_r7 * 0x18) + temp_r6), s32 *, 0xC));
        var_r7 += 1;
    } while ((u32) var_r7 < 8U);
    }
    data_02168f14 |= 0x2000;
    func_02088da8(M2C_FIELD(arg0, s32 *, 0x4C));
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
    if (func_ov003_02200c7c() == 0) return;
    func_ov003_02204fac(arg0);
}

void func_ov003_022035fc(void *arg0, s32 arg1) {
s32 value,limit; void *p=(char *)arg0+arg1*24;
#define F(o,t) (*(t *)((char *)arg0+(o)+arg1*24))
F(12,s32)-=F(24,s32);
if(F(28,u8)){
if(F(12,s32)>F(16,s32)) do { M2C_FIELD(p,s32 *,12)-=M2C_FIELD(p,s32 *,16)-M2C_FIELD(p,s32 *,20)+1; } while(M2C_FIELD(p,s32 *,12)>M2C_FIELD(p,s32 *,16));
if(F(12,s32)<F(20,s32)) { void *q=(char *)arg0+arg1*24; do { M2C_FIELD(q,s32 *,12)+=M2C_FIELD(q,s32 *,16)-M2C_FIELD(q,s32 *,20)+1; } while(M2C_FIELD(q,s32 *,12)<M2C_FIELD(q,s32 *,20)); }
}else{limit=F(16,s32);value=F(12,s32);if(value<=limit){limit=F(20,s32);if(value>=limit)limit=value;}F(12,s32)=limit;}
#undef F
}

u8 func_ov003_022036c8(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s8 *, 4) != -1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s8 func_ov003_022036e4(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 4);
}

u8 func_ov003_022036ec(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s8 *, 5) != -1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s8 func_ov003_02203708(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 5);
}

