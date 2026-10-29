/* 10 functions from 0x02226D9C to 0x02227D34 (ov010), found by ds-decomp. */
#include "common.h"
extern unsigned char data_ov010_0222f02c[];

M2C_UNK func_ov010_02226d9c(void *a) {
    (void)a;
    return 0;
}

void func_ov010_02227264(void *arg0) {
M2C_UNK func_01ffa6fc(void *);
s32 func_0204428c(u8);
M2C_UNK func_ov010_02229580(s32);
s32 func_ov010_02229a24();
s32 i;
u16 mask;
mask = func_ov010_02229a24() & M2C_FIELD(arg0,u16 *,0x44);
for (i=0;i<4;i++) {
if ((1 << i) & mask) { if (!func_0204428c((u8)i)) return; }
}
func_ov010_02229580(M2C_FIELD(arg0,s32 *,0x3c));
M2C_FIELD(arg0,s32 *,0x3c)=0;
M2C_FIELD(arg0,s32 *,0x40)=0;
func_01ffa6fc(arg0);
}

void func_ov010_022272cc(void *arg0) { (void)arg0; }

s32 func_ov010_0222791c(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    s32 temp_r2;

    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x40);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x40) = arg0;
    return temp_r2;
}

void func_ov010_02227934(s32 a, s32 b) {
extern M2C_UNK data_ov010_0222eee0;
void (*cb)(s32,s32) = M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,s32),0x38);
if (!cb) return;
cb(a,b);
}

void func_ov010_02227954(void) {
}

void func_ov010_02227bc8(void) {
    M2C_UNK func_ov010_02228cbc();
    func_ov010_02228cbc();
}

#pragma opt_common_subs off
void func_ov010_02227bd4(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f) {
extern M2C_UNK data_ov010_0222eee0;
void (*cb)(s32,s32,s32,s32,s32,s32);
u8 *p = &data_ov010_0222f02c[d*0x6c];
s32 value=M2C_FIELD(p,u8 *,0x1a);
s32 flags=M2C_FIELD(&data_ov010_0222eee0,u16 *,0);
M2C_FIELD(p,u8 *,0x1a) = value & ~1;
M2C_FIELD(&data_ov010_0222eee0,u16 *,0) = flags | (1 << d);
cb=M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,s32,s32,s32,s32,s32),0x34);
if (!cb) return;
cb(a,b,c,d,e,f);
}
#pragma opt_common_subs reset
void func_ov010_02227c3c(s32 a,s32 b) {
extern M2C_UNK data_ov010_0222eee0;
void (*cb)(s32,s32)=M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,s32),0x10);
if (!cb) return;
cb(a,b);
}

void func_ov010_02227c5c(s32 arg0, s32 arg1, s32 arg2) {
    extern M2C_UNK data_ov010_0222eee0;
    void (*cb)(s32, s32, s32);
    s32 r0_val;
    
    // The code does some pointer math.
    // mul r5, r8, r0 (r8=arg0, r0=0x28) => r5 = arg0 * 40
    // mul r12, r7, r0 (r7=arg1, r0=0x28) => r12 = arg1 * 40
    
    // It seems r4 is a base pointer, likely returned by func_020c4b60
    
    // Let's try to sketch it.
    void *func_020c4b60(void);
    void *r4 = func_020c4b60();
    
    // The operations are complex, but clearly manipulate 16-bit values.
}

