/* 10 functions from 0x02226D9C to 0x02227D34 (ov010), found by ds-decomp. */
#include "common.h"
typedef struct { u8 bytes[26]; u16 count0, count1, count2; s8 state0, state1, state2; u8 pad[5]; } Ov010Entry;
typedef struct { u8 pad[0x2d4]; Ov010Entry entries[1]; } Ov010State;
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
void *func_020c4b60(void);
void func_02007df8(s32,void *,s32);
extern M2C_UNK data_ov010_0222eee0;
Ov010State *base;
s32 offset;
void (*cb)(s32,s32,s32);
base=func_020c4b60();
offset=arg0*40;
M2C_FIELD((u8 *)base+0x2ee,u16 *,arg1*40)+=((Ov010State *)((u8 *)base+offset))->entries[0].count0;
M2C_FIELD((u8 *)base+0x2f0,u16 *,arg1*40)+=((Ov010State *)((u8 *)base+offset))->entries[0].count1;
M2C_FIELD((u8 *)base+0x2f2,u16 *,arg1*40)+=((Ov010State *)((u8 *)base+offset))->entries[0].count2;
func_02007df8(0,base->entries[arg0].bytes,26);
base->entries[arg0].count0=0;
base->entries[arg0].count1=0;
base->entries[arg0].count2=0;
base->entries[arg0].state0=-1;
base->entries[arg0].state1=-2;
base->entries[arg0].state2=-2;
cb=M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,s32,s32),20);
if(cb)cb(arg0,arg1,arg2);
}

