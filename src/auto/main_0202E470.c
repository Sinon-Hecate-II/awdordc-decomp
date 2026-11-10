/* 25 functions from 0x0202E470 to 0x0202F37C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pad[0xd0a];u8 a;u8 b:2;u8 padb:6;u8 c:4;u8 d:2;u8 padd:2; } Config0202ef;
typedef struct { s32 unk_0; s32 unk_4; } Unk0202ed18;
typedef struct {
 void *sp8; s32 spC,sp10;u32 sp14,sp18,sp1C,sp20; s32 sp24;
 u32 sp28; s32 sp2C;u32 sp30;s32 sp34,sp38;void *sp3C;
} AudioWork470;

static inline void Reset470(void *state,void *src) { *(Unk0202ed18 *)state=*(Unk0202ed18 *)src; }
static inline s16 Decode470(void *state,s32 code) {
extern s8 data_020ea780[16];extern s16 data_020ea790[90];
const s16 *steps=data_020ea790;
const s8 *changes=data_020ea780;
s32 delta,step,index,sample;
index=M2C_FIELD(state,u8 *,2);
sample=M2C_FIELD(state,s16 *,0);
step=steps[index];
delta=step>>3;
if(code&4)delta+=step;
if(code&2)delta+=step>>1;
if(code&1)delta+=step>>2;
if(code&8){sample-=delta;if(sample< -32768)sample=-32768;}
else{sample+=delta;if(sample>32767)sample=32767;}
index+=data_020ea780[code];
if(index<0)index=0;else if(index>88)index=88;
M2C_FIELD(state,s16 *,0)=(s16)sample;M2C_FIELD(state,u8 *,2)=index;
return (s16)sample;
}
s32 func_0202ed18(void *,s32);
void func_0202ed8c(s32);
void func_0202ed9c(void *,s32,s32,s32);
void func_0202edd4(s32);
s32 func_0202ede4(void *,s32);
void func_0202ee0c(void);
s32 func_0202ee10(void *,s32,s32,s32);
void func_0202ee2c(void);
#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_0202e470(void *arg0) {
    void func_02006564(void *);
    void func_020065e8(void *);
    M2C_UNK func_020067e0(s32, u32);
    M2C_UNK MI_CpuFill8(u8 *, s32, u32);
    M2C_UNK func_0202e32c(void *);
    u32 func_020722fc(s32, u32);
    extern s8 data_020ea780[16];
    extern s16 data_020ea790[90];
    extern M2C_UNK data_0213c290;
    extern M2C_UNK data_0213c2a8;
    void *sp3C;
    s32 sp38;
    s32 sp34;
    u32 sp30;
    s32 sp2C;
    u32 sp28;
    s32 sp24;
    u32 sp20;
    u32 sp1C;
    u32 sp18;
    u32 sp14;
    s32 sp10;
    s32 spC;
    void *sp8;
    M2C_UNK (*temp_r4_2)(s32, s32, void *, u32, s32, s32);
    s16 temp_ip;
    s16 temp_ip_3;
    s16 temp_lr;
    s16 temp_lr_2;
    s16 temp_lr_3;
    s16 temp_r10_2;
    s16 temp_r10_4;
    s16 temp_r1_2;
    s16 temp_r1_3;
    s16 temp_r2_3;
    s16 temp_r2_5;
    s16 temp_r3_4;
    s32 temp_r0_6;
    s32 temp_r0_7;
    s32 temp_r2_2;
    s32 temp_r2_4;
    s32 temp_r2_6;
    s32 temp_r3;
    s32 temp_r3_5;
    s32 temp_r5;
    s32 var_ip;
    s32 var_ip_2;
    s32 var_ip_3;
    s32 var_lr;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r10;
    s32 var_r10_2;
    s32 var_r1_5;
    s32 var_r1_6;
    s32 var_r2;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r4;
    s32 var_r4_3;
    u32 temp_r0_2;
    u32 temp_r0_3;
    u32 temp_r0_4;
    u32 temp_r1;
    u32 temp_r2;
    u32 temp_r3_3;
    s32 temp_r4;
    u32 temp_r6;
    u32 var_r1;
    u32 var_r1_2;
    u32 var_r1_4;
    u8 *var_r0;
    u8 *var_r1_3;
    u8 *var_r4_2;
    u8 temp_ip_2;
    u8 temp_r0_5;
    u8 temp_r10;
    u8 temp_r10_3;
    u8 temp_r3_2;
    void *temp_r0;
    void *var_r5;

    sp8 = arg0;
    sp3C = M2C_FIELD(arg0, void **, 8);
    if ((((s32) (M2C_FIELD(sp3C, s32 *, 0x110) << 0x1A) >> 0x1F) != 0) && ((s32) M2C_FIELD(sp3C, volatile s32 *, 0x114) > 0)) {
        M2C_FIELD(sp3C, volatile s32 *, 0x114) = (s32) (M2C_FIELD(sp3C, volatile s32 *, 0x114) - 1);
    }
    temp_r0_2 = M2C_FIELD(sp8, u32 *, 0x2C);
    sp30 = temp_r0_2;
    sp34 = 0;
    if (temp_r0_2 != 0) {
loop_4:
        if (((s32) (M2C_FIELD(sp3C, s32 *, 0x110) << 0x1A) >> 0x1F) != 0) {
            var_r4 = 0;
            if ((s32) M2C_FIELD(sp8, s32 *, 0x10) > 0) {
                do {
                    MI_CpuFill8(M2C_FIELD((sp8 + (var_r4 * 4)), s32 *, 0x14) + sp34, 0, sp30);
                    var_r4 += 1;
                } while (var_r4 < (s32) M2C_FIELD(sp8, s32 *, 0x10));
            }
        } else {
            temp_r4 = M2C_FIELD(sp3C, u32 *, 0xDC);
            temp_r5 = M2C_FIELD(sp3C, s32 *, 0x160);
            temp_r0_3 = func_020722fc(temp_r5, temp_r4);
            if (temp_r0_3 < (u32) (M2C_FIELD(sp3C, s32 *, 0xD4) - 1)) {
                var_r1 = temp_r4;
                sp2C = M2C_FIELD(sp3C, s32 *, 0xD8);
            } else {
                sp2C = M2C_FIELD(sp3C, s32 *, 0xE0);
                var_r1 = M2C_FIELD(sp3C, u32 *, 0xE4);
            }
            sp20 = sp30;
            sp28 = temp_r5 - (temp_r0_3 * temp_r4);
            if (M2C_FIELD(sp3C, u8 *, 0xC0) != 0) {
                sp20 = sp30 >> 1;
            }
            temp_r3 = M2C_FIELD(sp3C, s32 *, 0x110);
            if (((s32) (temp_r3 << 0x1B) >> 0x1F) != 0) {
                if (sp28 == 0) {
                    M2C_FIELD(sp3C,s32 *,0x110)=temp_r3&~0x10;
                } else {
                    sp20=sp28;
                    sp28=0;
                }
            }
            sp38 = 0;
            if ((u32) (sp28 + sp20) >= var_r1) {
                sp20 = var_r1 - sp28;
                if (temp_r0_3 >= (u32) (M2C_FIELD(sp3C, s32 *, 0xD4) - 1)) {
                    if (M2C_FIELD(sp3C, u8 *, 0xC1) != 0) {
                        sp38 = 1;
                    } else {
                        M2C_FIELD(sp3C, s32 *, 0x110) = (s32) (M2C_FIELD(sp3C, s32 *, 0x110) | 0x20);
                    }
                }
            }
            temp_r3_2 = M2C_FIELD(sp3C, u8 *, 0xC0);
            var_r1_2 = sp28;
            sp1C = sp20;
            switch (temp_r3_2) {                    /* irregular */
            case 0:
                sp18 = sp20;
                break;
            case 1:
                temp_r1 = sp20 * 2;
                sp1C = temp_r1;
                sp18 = temp_r1;
                var_r1_2 = sp28 * 2;
                break;
            case 2:
                temp_r3_3 = var_r1_2 + sp20 + 1;
                var_r1_2 = sp28 >> 1;
                temp_r2 = (temp_r3_3 >> 1) - var_r1_2;
                sp18 = temp_r2;
                if (sp28 == 0) {
                    sp18 = temp_r2 + 4;
                } else {
                    var_r1_2 += 4;
                }
                sp1C *= 2;
                break;
            }
            sp24 = (M2C_FIELD(sp3C, u8 *, 0xC2) * (temp_r0_3 * M2C_FIELD(sp3C, s32 *, 0xD8))) + var_r1_2 + M2C_FIELD(sp3C, s32 *, 0xD0);
            spC = 0;
            if ((s32) M2C_FIELD(sp8, s32 *, 0x10) > 0) {
                var_r5 = sp3C + 0xF8;
                sp14 = sp28 + sp20;
                sp10 = sp28 & 1;
                temp_r6 = sp14 & ~1;
loop_35:
                var_r1_3 = M2C_FIELD((sp8 + (spC * 4)), s32 *, 0x14) + sp34;
                var_r4_2 = var_r1_3;
                if (spC < (s32) M2C_FIELD(sp3C, u8 *, 0xC2)) {
                    if (M2C_FIELD(sp3C, u8 *, 0xC0) == 2) {
                        func_02006564(&data_0213c2a8);
                        var_r1_3 = M2C_FIELD(&data_0213c290, u8 **, 8);
                    }
                    if (M2C_FIELD(sp3C, s32 (**)(void *, u8 *, u32, s32), 0x16C)(sp3C, var_r1_3, sp18, (spC * sp2C) + sp24) != sp18) {
                        sp1C = 0;
                        M2C_FIELD(sp3C, s32 *, 0x110) = (s32) (M2C_FIELD(sp3C, s32 *, 0x110) | 0x20);
                        sp20 = 0;
                        sp38 = 0;
                        if (M2C_FIELD(sp3C, u8 *, 0xC0) == 2) {
                            func_020065e8(&data_0213c2a8);
                        }
                    } else {
                        if (M2C_FIELD(sp3C, u8 *, 0xC0) == 2) {
                            var_r1_3 = M2C_FIELD(&data_0213c290, u8 **, 8);
                            var_r0=var_r1_3;
                            if (sp28 == 0) {
                                var_r0 = var_r1_3 + 4;
                                temp_r2_3=M2C_FIELD(var_r1_3,u16 *,0);
                                temp_r1_2=M2C_FIELD(var_r1_3,u16 *,2);
                                M2C_FIELD(var_r5,u16 *,0)=temp_r2_3;
                                M2C_FIELD(var_r5,u16 *,2)=temp_r1_2;
                            }
                            var_r1_4 = sp28;
                            if (sp10 != 0) {
                                M2C_FIELD(var_r4_2,s16 *,0)=Decode470(var_r5,(*var_r0>>4)&15);
                                var_r4_2 += 2;
                                var_r1_4 += 1;
                                var_r0 += 1;
                            }
                            if (var_r1_4 < temp_r6) {
                                do {
                                    M2C_FIELD(var_r4_2,s16 *,0)=Decode470(var_r5,*var_r0&15);
                                    M2C_FIELD(var_r4_2,s16 *,2)=Decode470(var_r5,(*var_r0>>4)&15);
                                    var_r1_4 += 2;
                                    var_r4_2 += 4;
                                    var_r0 += 1;
                                } while (var_r1_4 < temp_r6);
                            }
                            if (var_r1_4 < sp14) {
                                M2C_FIELD(var_r4_2,s16 *,0)=Decode470(var_r5,*var_r0&15);
                            }
                            func_020065e8(&data_0213c2a8);
                        }
                        goto block_118;
                    }
                } else {
                    if (((s32) (M2C_FIELD(sp3C, s32 *, 0x110) << 0x19) >> 0x1F) != 0) {
                        MI_CpuFill8(var_r1_3, 0, sp1C);
                    } else {
                        MI_CpuCopy8(M2C_FIELD(sp8, s32 *, 0x14) + sp34, var_r1_3, sp1C);
                    }
block_118:
                    var_r5 += 4;
                    temp_r0_6 = spC + 1;
                    spC = temp_r0_6;
                    if (temp_r0_6 < (s32) M2C_FIELD(sp8, s32 *, 0x10)) {
                        goto loop_35;
                    }
                }
            }
            temp_r0_7 = M2C_FIELD(sp3C, s32 *, 0x110);
            if (((s32) (temp_r0_7 << 0x1B) >> 0x1F) != 0) {
                M2C_FIELD(sp3C, s32 *, 0x110) = (s32) (temp_r0_7 & ~0x10);
            } else {
                if (sp38 != 0) {
                    var_r1_6 = M2C_FIELD(sp3C, s32 *, 0xC8);
                } else {
                    var_r1_6 = M2C_FIELD(sp3C, s32 *, 0x160) + sp20;
                }
                M2C_FIELD(sp3C, s32 *, 0x160) = var_r1_6;
                sp34 += sp1C;
                sp30 -= sp1C;
                if ((((s32) (M2C_FIELD(sp3C, s32 *, 0x110) << 0x1A) >> 0x1F) != 0) && (M2C_FIELD(sp3C, s32 *, 0x13C) != 0)) {
                    func_0202e32c(sp3C);
                }
            }
            if (sp30 != 0) {
                goto loop_4;
            }
        }
    }
    temp_r4_2 = M2C_FIELD(sp3C, M2C_UNK (**)(s32, s32, void *, u32, s32, s32), 0x134);
    if (temp_r4_2 != NULL) {
        if (M2C_FIELD(sp3C, u8 *, 0xC0) == 0) {
            var_r0_3 = 0;
        } else {
            var_r0_3 = 1;
        }
        temp_r4_2(M2C_FIELD(sp8, s32 *, 0xC), M2C_FIELD(sp8, s32 *, 0x10), sp8 + 0x14, M2C_FIELD(sp8, u32 *, 0x2C), var_r0_3, M2C_FIELD(sp3C, s32 *, 0x138));
    }
    var_r4_3 = 0;
    if ((s32) M2C_FIELD(sp8, s32 *, 0x10) > 0) {
        do {
            func_020067e0(M2C_FIELD((sp8 + (var_r4_3 * 4)), s32 *, 0x14), M2C_FIELD(sp8, u32 *, 0x2C));
            var_r4_3 += 1;
        } while (var_r4_3 < (s32) M2C_FIELD(sp8, s32 *, 0x10));
    }
    if (M2C_FIELD(sp8, s32 *, 0xC) == 0) {
        M2C_FIELD(sp3C, s32 *, 0x118) = 1;
    }
}

#pragma pop
void Sound_SetPlayerCallbacks(void *arg0,s32 arg1) {
 if(func_0202c444(arg1)==0) {
 M2C_FIELD(arg0,void **,0x164)=func_0202ed18;
 M2C_FIELD(arg0,void **,0x168)=func_0202ed8c;
 M2C_FIELD(arg0,void **,0x16C)=func_0202ed9c;
 M2C_FIELD(arg0,void **,0x170)=func_0202edd4;
 } else {
 M2C_FIELD(arg0,void **,0x164)=func_0202ede4;
 M2C_FIELD(arg0,void **,0x168)=func_0202ee0c;
 M2C_FIELD(arg0,void **,0x16C)=func_0202ee10;
 M2C_FIELD(arg0,void **,0x170)=func_0202ee2c;
 }
}

s32 func_0202ed18(void *arg0, s32 arg1) {
 s32 func_0202c3ac(s32,void *,s32,s32);
 void func_0202c424(void *);
 s32 func_0200b9e4(void *,Unk0202ed18);
 s32 func_0202c35c(s32);
 Unk0202ed18 sp0;
 if(func_0202c3ac(arg1,arg0+0xA8,0x40,0)!=0x40)return 0;
 func_0202c424(&sp0);
 if(!func_0200b9e4(arg0+0x5C,sp0))return 0;
 M2C_FIELD(arg0,s32 *,0xA4)=func_0202c35c(arg1);return 1;
}

void func_0202ed8c(s32 arg0) {
    M2C_UNK func_0200ba9c(s32);
    func_0200ba9c(arg0 + 0x5C);
}

void func_0202ed9c(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK FileRead(void *, M2C_UNK, M2C_UNK);
    M2C_UNK FileSeek(void *, s32, M2C_UNK);
    FileSeek(arg0 + 0x5C, M2C_FIELD(arg0, s32 *, 0xA4) + arg3, 0);
    FileRead(arg0 + 0x5C, arg1, arg2);
}

void func_0202edd4(s32 arg0) {
    M2C_UNK func_0200bb98(s32);
    func_0200bb98(arg0 + 0x5C);
}

s32 func_0202ede4(void *arg0, M2C_UNK arg1) {
    M2C_UNK MI_CpuCopy8(s32, s32, M2C_UNK);
    s32 func_0202c444(M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_0202c444(arg1);
    M2C_FIELD(arg0, s32 *, 0xA4) = temp_r0;
    MI_CpuCopy8(temp_r0, arg0 + 0xA8, 0x40);
    return 1;
}

void func_0202ee0c(void) {

}

s32 func_0202ee10(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
 MI_CpuCopy8(M2C_FIELD(arg0,s32 *,0xA4)+arg3,arg1,arg2); return arg2;
}

void func_0202ee2c(void) {

}

#pragma opt_common_subs off
void func_0202ee30(void *arg0) {
 void OS_SleepThread(void *);
 void func_02006564(void *);
 void func_020065e8(void *);
 void *func_0202e09c(void *);
 void func_0202e470(void *);
 void func_0202e12c(void *);
 volatile void *p;
 void *base=arg0+0xC8;
 OS_SleepThread(arg0+0x4C0);
 for(;;) {
 func_02006564(base+0x400);
 p=func_0202e09c(arg0+0x4E0);
 if(!p){func_020065e8(base+0x400);continue;}
 func_0202e470(p);func_0202e12c(p);func_020065e8(base+0x400);
 }
}
#pragma opt_common_subs reset
void *func_0202ee80(void *arg0,s32 arg1) {
 void *p;
 if(arg1<0)return NULL;
 if((u32)arg1>=M2C_FIELD(arg0,u32 *,0x1C))return NULL;
 p=arg0+0x20+arg1*12;
 if(M2C_FIELD(p,s32 *,0)==-1)return NULL;
 return p;
}

void func_0202eec0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

void func_0202eed8(void *arg0, s32 arg1, s32 arg2) {
    s32 func_0202ef00();
    M2C_FIELD(arg0, s32 *, 0) = func_0202ef00();
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 0xC) = arg2;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

s32 func_0202ef00(void *arg0) {
 s32 func_020720f0(s32,s32);
 s32 n=M2C_FIELD(arg0,s32 *,0xC);
 s32 t=M2C_FIELD(arg0,s32 *,8);
 s32 start;
 if(t>=n)return M2C_FIELD(arg0,s32 *,4);
 start=M2C_FIELD(arg0,s32 *,0);
 return start+func_020720f0(t*(M2C_FIELD(arg0,s32 *,4)-start),n);
}

void func_0202ef34(void *arg0) {
    s32 temp_r2;

    temp_r2 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_r2 < (s32) M2C_FIELD(arg0, s32 *, 0xC)) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_r2 + 1);
    }
}

s32 func_0202ef4c(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 8) >= (s32) M2C_FIELD(arg0, s32 *, 0xC)) {
        return 1;
    }
    return 0;
}

s32 func_0202ef64(void *a) {
void func_02007e54(s32,void *,s32);s32 func_0202f2f4(s32,M2C_UNK);void func_02045c90(void);s32 func_020270b4(void *,s32);void func_0202f37c(void);
extern M2C_UNK data_0213d100;
void *p,*q;Config0202ef *cfg;s32 r;
p=M2C_FIELD(a,void *(**)(s32,s32),0)(1,24);
M2C_FIELD(&data_0213d100,void **,16)=p;func_02007e54(0,p,24);
p=M2C_FIELD(&data_0213d100,void **,16);
M2C_FIELD(p,s32 *,0)=M2C_FIELD(a,s32 *,0);M2C_FIELD(p,s32 *,4)=M2C_FIELD(a,s32 *,4);
M2C_FIELD(p,u8 *,9)=1;M2C_FIELD(p,u8 *,22)=1;M2C_FIELD(p,u8 *,8)=1;
M2C_FIELD(&data_0213d100,s32 *,0)=func_0202f2f4(16,0xd18);
M2C_FIELD(&data_0213d100,s32 *,4)=func_0202f2f4(2,0x2300);
M2C_FIELD(&data_0213d100,s32 *,8)=func_0202f2f4(4,88);
M2C_FIELD(&data_0213d100,s32 *,12)=func_0202f2f4(8,12);
func_02007e54(0,M2C_FIELD(&data_0213d100,void **,0),0xd18);
func_02007e54(0,M2C_FIELD(&data_0213d100,void **,4),0x2300);
func_02007e54(0,M2C_FIELD(&data_0213d100,void **,8),88);
func_02007e54(0,M2C_FIELD(&data_0213d100,void **,12),12);
cfg=M2C_FIELD(&data_0213d100,Config0202ef **,0);
cfg->a=M2C_FIELD(a,u8 *,8);cfg->b=M2C_FIELD(a,u8 *,9);
q=M2C_FIELD(&data_0213d100,void **,12);M2C_FIELD(q,s32 *,0)=M2C_FIELD(a,s32 *,0);M2C_FIELD(q,s32 *,4)=M2C_FIELD(a,s32 *,4);M2C_FIELD(q,s32 *,8)=0;
cfg->c=M2C_FIELD(a,u8 *,10);cfg->d=M2C_FIELD(a,u8 *,11);
func_02045c90();
r=func_020270b4(M2C_FIELD(&data_0213d100,void **,4),0x2300);
if(r==1 || r>=4){func_0202f37c();return 0;}return 1;
}

s32 func_0202f10c(void) {
 u32 func_0202f544();
 u32 func_02031208(); u32 func_02030a38(); u32 func_0202fc9c();
 u32 func_0203095c(); u32 func_02031290(); u32 func_02030324();
 s32 OS_DisableInterrupts(); void OS_RestoreInterrupts(s32);
 void func_0202f4e4(u32); s32 func_0202f5f4(); void func_0202f5bc();
 u32 n=func_0202f544(); s32 t;
 if(n==1)n=func_02031208();
 else if(n<7){t=OS_DisableInterrupts();n=func_02030a38();func_0202f4e4(n);OS_RestoreInterrupts(t);}
 else if(n<9)n=func_0202fc9c();
 else if(n<10)n=func_0203095c();
 else if(n<16)n=func_02031290();
 else if(n==17)n=func_02030324();
 func_0202f4e4(n);
 if(n==16){t=func_0202f5f4();func_0202f5bc();return t;}
 if(n==18){func_0202f5bc();return -1;}
 return 0;
}

s32 func_0202f1dc(void) {
 u32 func_0202f544();
 s32 func_02030348(u32);
 u32 n=func_0202f544();
 if(n<=1)return 0;
 if(n<7)return 1;
 if(n==9)return 4;
 if(n<10)return 2;
 if(n==11)return 4;
 if(n<16)return 3;
 if(n==16)return 5;
 if(n==17)return 4;
 return func_02030348(n);
}

u8 func_0202f248(void) {
    u32 func_0202f544();
    extern M2C_UNK data_0213d100;
    u32 temp_r0;
    u8 var_r4;

    var_r4 = 0xFF;
    if (M2C_FIELD(&data_0213d100, void **, 0x10) == NULL) {
        return 0xFFU;
    }
    temp_r0 = func_0202f544();
    if ((temp_r0 >= 0xAU) && (temp_r0 <= 0x10U)) {
        var_r4 = M2C_FIELD(M2C_FIELD(&data_0213d100, void **, 0x10), u8 *, 0x17);
    }
    return var_r4;
}

s32 func_0202f28c(void) {
 u32 func_0202f544();
 void func_0202f37c(void);
 void func_020301dc(u8 *);
 void func_0202f4e4(u32);
 u8 n=func_0202f544();
 if(n==0 || n==18) {
 func_0202f37c(); return 1;
 }
 func_020301dc(&n);func_0202f4e4(n);return 0;
}

void func_0202f2c8(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_02007e70(M2C_UNK, s32, M2C_UNK);
    s32 func_0202f48c(M2C_UNK);
    func_02007e70(arg1, func_0202f48c(0x10) + (arg0 << 8), 0xF0);
}

s32 func_0202f2f4(s32 arg0, M2C_UNK arg1) {
    u8 temp_r1;
    void *temp_r0;

    temp_r0 = func_0202f48c(1);
    temp_r1 = M2C_FIELD(temp_r0, u8 *, 8);
    if (temp_r1 & arg0) {
        return 0;
    }
    M2C_FIELD(temp_r0, u8 *, 8) = (u8) (temp_r1 | arg0);
    return M2C_FIELD(temp_r0, s32 (**)(s32, M2C_UNK), 0)(arg0, arg1);
}

void func_0202f334(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    u8 temp_r2;
    void *temp_r0;

    temp_r0 = func_0202f48c(1);
    temp_r2 = M2C_FIELD(temp_r0, u8 *, 8);
    if (!(temp_r2 & arg0)) {
        return;
    }
    M2C_FIELD(temp_r0, u8 *, 8) = (u8) (temp_r2 & ~arg0);
    M2C_FIELD(temp_r0, M2C_UNK (**)(s32, M2C_UNK, M2C_UNK), 4)(arg0, arg1, arg2);
}

