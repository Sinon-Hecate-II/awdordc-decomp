/* 17 functions from 0x021E6D04 to 0x021E7C84 (ov002), found by ds-decomp. */
#include "common.h"
typedef struct { u16 b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1,b8:1,b9:1,b10:1,b11:1,b12:1,b13:1,b14:1,b15:1; } SetupFlags;
typedef struct { u8 low:4; u8 high:4; } NibbleFlags;
static inline u8 IsEntryReady(void *p) {
s32 ready=1;
if(M2C_FIELD(p,u8 *,1)!=0) {
if(((NibbleFlags *)(p+3))->high!=0) {
if(M2C_FIELD(p,u8 *,0)==M2C_FIELD(p,u8 *,1)) goto done;
}
ready=0;
}
done:
return ready ? 1 : 0;
}

void func_ov002_021e6d04(void *arg0) {
    M2C_UNK func_020e35cc();
    s32 var_r9;
    void *var_r10;

    var_r9 = 0;
    var_r10 = arg0;
    do {
        if (M2C_FIELD(var_r10, s32 *, 0) != 0) {
            func_020e35cc();
            M2C_FIELD(var_r10, s32 *, 0) = 0;
        }
        if (M2C_FIELD(var_r10, s32 *, 4) != 0) {
            func_020e35cc();
            M2C_FIELD(var_r10, s32 *, 4) = 0;
        }
        if (M2C_FIELD(var_r10, s32 *, 8) != 0) {
            func_020e35cc();
            M2C_FIELD(var_r10, s32 *, 8) = 0;
        }
        if (M2C_FIELD(var_r10, s32 *, 0xC) != 0) {
            func_020e35cc();
            M2C_FIELD(var_r10, s32 *, 0xC) = 0;
        }
        if (M2C_FIELD(var_r10, s32 *, 0x10) != 0) {
            func_020e35cc();
            M2C_FIELD(var_r10, s32 *, 0x10) = 0;
        }
        if (M2C_FIELD(var_r10, s32 *, 0x14) != 0) {
            func_020e35cc();
            M2C_FIELD(var_r10, s32 *, 0x14) = 0;
        }
        var_r9 += 1;
        var_r10 += 0x64;
    } while (var_r9 < 2);
}

#pragma opt_common_subs off
void func_ov002_021e6db4(void *arg0) {
    void func_ov002_021e7a64(void *);
    void func_ov002_021e3890(void *);
    void PlayerPanels_Init(void *);
    void func_ov002_021e85e8(void *);
    void func_ov002_021e6cdc(void *);
    void func_020af7ac(void);
    void func_020af760(void);
    void func_ov002_021e8738(void *);
    void func_ov002_021e42a8(void *, s32);
    void func_ov002_021e8d04(void *, s32);
    void func_02086d18(void);
    extern M2C_UNK gPlayerSettings;
    extern u8 data_ov002_021f2f44[];
    extern M2C_UNK data_ov002_021f3124;
    extern M2C_UNK data_ov002_021f3018;
    extern void *data_027e00bc;

    func_ov002_021e7a64(&gPlayerSettings);
    func_ov002_021e3890(data_ov002_021f2f44);
    PlayerPanels_Init(data_ov002_021f2f44);

    {
        s32 i = 0;
        void *p = &data_ov002_021f3124;
        do {
            func_ov002_021e85e8(p);
            i++;
            p = (u8 *)p + 0x2C;
        } while (i < 2);
    }

    func_ov002_021e6cdc(&data_ov002_021f3018);
    func_020af7ac();
    func_020af760();

    {
        void *r5 = &data_ov002_021f3124;
        void *r6 = &gPlayerSettings;
        s32 r7 = 0;
        M2C_FIELD(arg0, u8 *, 8) = (u8)r7;
        M2C_FIELD(arg0, s32 *, 0) = r7;
        M2C_FIELD(arg0, s32 *, 4) = r7;
        M2C_FIELD(arg0, u8 *, 9) = (u8)r7;

        do {
            func_ov002_021e8738(r5);
            func_ov002_021e42a8(r5, -0x50);
            {
                void *ptr = M2C_FIELD(r6, void **, 4);
                if (M2C_FIELD(ptr, u8 *, 0x3D) == 2) {
                    if (M2C_FIELD(r5, u8 *, 0x2A) != 0) {
                        func_ov002_021e8d04(r5, 0x200);
                    }
                }
            }
            r7++;
            r5 = (u8 *)r5 + 0x2C;
            r6 = (u8 *)r6 + 0x18;
        } while (r7 < 2);
    }


    {
        volatile u16 *r1;
        M2C_FIELD(data_027e00bc, u16 *, 0) = (u16)(M2C_FIELD(data_027e00bc, u16 *, 0) | 0x10);
        M2C_FIELD(data_027e00bc, u16 *, 0) = (u16)(M2C_FIELD(data_027e00bc, u16 *, 0) & ~0x20);
        M2C_FIELD(data_027e00bc, u16 *, 0) = (u16)(M2C_FIELD(data_027e00bc, u16 *, 0) | 0x40);
        M2C_FIELD(data_027e00bc, u16 *, 0) = (u16)(M2C_FIELD(data_027e00bc, u16 *, 0) | 0x80);
        M2C_FIELD(data_027e00bc, u16 *, 0) = (u16)(M2C_FIELD(data_027e00bc, u16 *, 0) | 0x100);
        M2C_FIELD(data_027e00bc, u16 *, 0x12) = (u16)((M2C_FIELD(data_027e00bc, u16 *, 0x12) & ~0xC0) | 0x40);
        M2C_FIELD(data_027e00bc, u8 *, 0x51) = 0x10;
        M2C_FIELD(data_027e00bc, u8 *, 0x52) = 0;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b0=1;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b1=0;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b2=1;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b3=0;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b4=0;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b5=0;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b8=0;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b9=0;
        r1 = (volatile u16 *)0x4000060;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b10=1;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b11=1;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b12=0;
        ((SetupFlags *)((u8 *)data_027e00bc+0x12))->b13=0;
        r1[0] = (u16)((r1[0] & ~0x3000) | 0x8);
    }


    func_02086d18();
}
#pragma opt_common_subs reset
void func_ov002_021e795c(void *);
void func_ov002_021e7120(void *);
void func_ov002_021e7474(void *);
void func_ov002_021e6ff0(void *arg0) {
void func_ov002_021e70a0(void *);
extern u8 data_ov002_021f2f40;
extern void *data_02101e84;
extern u32 data_027e15bc;
extern void *data_02101e88;
if(data_ov002_021f2f40) return;
if(M2C_FIELD(data_02101e84,u16 *,6)&0x200) {
if(data_027e15bc&1) func_ov002_021e70a0(arg0);
} else if(M2C_FIELD(data_02101e84,u16 *,6)&0x100) {
func_ov002_021e70a0(arg0); func_ov002_021e70a0(arg0);
} else func_ov002_021e70a0(arg0);
if(!M2C_FIELD(arg0,u8 *,9)) return;
if((M2C_FIELD(data_02101e84,u16 *,0)&0xB)||M2C_FIELD(data_02101e88,u8 *,0x14)) func_ov002_021e795c(arg0);
}

void func_ov002_021e70a0(void *arg0) {
void func_ov002_021e712c(void *);
void func_ov002_021e749c(void *);
void func_ov002_021e8914(void *);
void func_020af7dc(void);
void func_ov002_021e78a4(void *);
extern M2C_UNK data_ov002_021f3124;
extern M2C_UNK data_ov002_021f3150;
extern u8 data_ov002_021f2f40;
switch(M2C_FIELD(arg0,u8 *,8)) {
case 0: func_ov002_021e7120(arg0); break;
case 1: func_ov002_021e712c(arg0); break;
case 2: func_ov002_021e7474(arg0); break;
case 3: func_ov002_021e749c(arg0); break;
}
func_ov002_021e8914(&data_ov002_021f3124);
func_ov002_021e8914(&data_ov002_021f3150);
func_020af7dc();
if(data_ov002_021f2f40) return;
func_ov002_021e78a4(arg0);
}

void func_ov002_021e7120(void *arg0) {
    M2C_FIELD(arg0, s8 *, 8) = 1;
}

void func_ov002_021e712c(void *a) { }

void func_ov002_021e7474(void *arg0) {
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0) + 1;
    M2C_FIELD(arg0, s32 *, 0) = temp_r1;
    if (temp_r1 != 0x20) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 8) = 3;
    M2C_FIELD(arg0, s32 *, 0) = 0;
}

void func_ov002_021e749c(void *arg0) {
    (void)arg0;
}

s32 func_ov002_021e77dc(void *arg0) {
extern M2C_UNK gPlayerSettings,data_ov002_021f3124;
if(M2C_FIELD(&gPlayerSettings,u8 *,0x2c)) {
if(!IsEntryReady(&data_ov002_021f3124)) return 0;
}
if(M2C_FIELD(&gPlayerSettings,u8 *,0x14)) {
if(!IsEntryReady((void *)&data_ov002_021f3124+0x2c)) return 0;
}
return 1;
}

void func_ov002_021e78a4(void *arg0) {
s32 func_ov002_021e77dc(void *);
s32 temp;
if(!M2C_FIELD(arg0,u8 *,9)) return;
if(!func_ov002_021e77dc(arg0)) return;
temp=M2C_FIELD(arg0,s32 *,4)+1;
M2C_FIELD(arg0,s32 *,4)=temp;
if(temp!=0x4B) return;
func_ov002_021e795c(arg0);
}

void func_ov002_021e78e4(void) {
    M2C_UNK func_02086dfc();
    M2C_UNK func_02086ec8();
    M2C_UNK func_02087048(M2C_UNK, M2C_UNK);
    s32 func_ov002_021e3e00(M2C_UNK *);
    M2C_UNK func_ov002_021e8984(s32);
    extern M2C_UNK data_ov002_021f3014;
    extern M2C_UNK gPlayerSettings;
    extern M2C_UNK data_ov002_021f3124;
    s32 var_r2;

    func_02086dfc();
    func_02087048(0, 0x1F);
    if (func_ov002_021e3e00(&data_ov002_021f3014) != 0) {
        func_ov002_021e8984((M2C_FIELD(&gPlayerSettings, u8 *, 1) * 0x2C) + (s32) &data_ov002_021f3124);
    } else {
        if (M2C_FIELD(&gPlayerSettings, u8 *, 1) == 0) {
            var_r2 = 1;
        } else {
            var_r2 = 0;
        }
        func_ov002_021e8984((var_r2 * 0x2C) + (s32) &data_ov002_021f3124);
    }
    func_02086ec8();
}

void func_ov002_021e795c(void *arg0) {
    M2C_UNK func_ov002_021e15e0();
    M2C_FIELD(arg0, s8 *, 9) = 0;
    func_ov002_021e15e0();
}

void func_ov002_021e7970(void) {
    void func_ov002_021e8ca4(void *);
    void func_020af79c(void);
    extern M2C_UNK data_ov002_021f3124;
    extern M2C_UNK data_ov002_021f3018;
    s32 i;
    void *p;
    p=&data_ov002_021f3124;
    i=0;
    do { func_ov002_021e8ca4(p); i++; p+=0x2C; } while(i<2);
    func_ov002_021e6d04(&data_ov002_021f3018);
    func_020af79c();
}

u8 func_ov002_021e79ac(void *arg0) {
    u8 var_r0;

    if ((u32) M2C_FIELD(arg0, u8 *, 8) <= 1U) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov002_021e79c4(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_ov002_021e805c();
    s32 func_ov002_021e8080(M2C_UNK, M2C_UNK);
    s32 func_ov002_021e80a4(M2C_UNK, M2C_UNK);
    if (func_ov002_021e805c() != 0) {
        return 0x1F;
    }
    if (func_ov002_021e8080(arg0, arg1) != 0) {
        return 0x3C;
    }
    if (func_ov002_021e80a4(arg0, arg1) != 0) {
        return 0x59;
    }
    return 2;
}

s32 func_ov002_021e7a14(M2C_UNK arg0, M2C_UNK arg1) {
    if (func_ov002_021e805c() != 0) {
        return 0x21;
    }
    if (func_ov002_021e8080(arg0, arg1) != 0) {
        return 0x3E;
    }
    if (func_ov002_021e80a4(arg0, arg1) != 0) {
        return 0x5B;
    }
    return 4;
}

#pragma scheduling off
#pragma scheduling reset
void func_ov002_021e7a64(void *arg0) {
    extern M2C_UNK gPlayerSettings;
    extern u8 data_ov002_021f1134[];
extern u8 data_ov002_021f2f40;
    extern u8 data_ov002_021f1bf4[];
    u8 func_ov002_021e8014(s32, s32);
    s32 func_ov002_021e79c4(M2C_UNK, M2C_UNK);
    u8 func_ov002_021e8038(s32, s32);
    s32 func_ov002_021e7a14(M2C_UNK, M2C_UNK);

    M2C_FIELD(arg0, void **, 0x4) = (void *)(data_ov002_021f1134 + M2C_FIELD(&gPlayerSettings, u8 *, 0xc) * 64);
    M2C_FIELD(arg0, void **, 0x1c) = (void *)(data_ov002_021f1134 + M2C_FIELD(&gPlayerSettings, u8 *, 0x24) * 64);
    M2C_FIELD(arg0, void **, 0x8) = (void *)(data_ov002_021f1bf4 + M2C_FIELD(&gPlayerSettings, u8 *, 0x10) * 0x24);
    M2C_FIELD(arg0, void **, 0x20) = (void *)(data_ov002_021f1bf4 + M2C_FIELD(&gPlayerSettings, u8 *, 0x28) * 0x24);

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x4), u8 *, 0x3d) == 2) {
        if (func_ov002_021e8014((s32)arg0, 0) == 0) {
            u8 r = func_ov002_021e79c4((M2C_UNK)arg0, 0);
            M2C_FIELD(&gPlayerSettings, u8 *, 0x10) = r;
        }
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x1c), u8 *, 0x3d) == 2) {
        if (func_ov002_021e8014((s32)arg0, 1) == 0) {
            u8 r = func_ov002_021e79c4((M2C_UNK)arg0, 1);
            M2C_FIELD(&gPlayerSettings, u8 *, 0x28) = r;
        }
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x4), u8 *, 0x3d) == 3) {
        if (func_ov002_021e8038((s32)arg0, 0) == 0) {
            u8 r = func_ov002_021e7a14((M2C_UNK)arg0, 0);
            M2C_FIELD(&gPlayerSettings, u8 *, 0x10) = r;
        }
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x1c), u8 *, 0x3d) == 3) {
        if (func_ov002_021e8038((s32)arg0, 1) == 0) {
            u8 r = func_ov002_021e7a14((M2C_UNK)arg0, 1);
            M2C_FIELD(&gPlayerSettings, u8 *, 0x28) = r;
        }
    }

    M2C_FIELD(arg0, void **, 0x8) = (void *)(data_ov002_021f1bf4 + M2C_FIELD(&gPlayerSettings, u8 *, 0x10) * 0x24);
    M2C_FIELD(arg0, void **, 0x20) = (void *)(data_ov002_021f1bf4 + M2C_FIELD(&gPlayerSettings, u8 *, 0x28) * 0x24);

    if (data_ov002_021f2f40 == 0) {
        u8 idx = M2C_FIELD(arg0, u8 *, 0x0);
        s32 flag = (idx == 0) ? 1 : 0;
        u8 v = M2C_FIELD(M2C_FIELD((u8 *)arg0 + flag * 0x18, void **, 0x4), u8 *, 0x3d);
        if (v != 2) {
            u8 *q = (u8 *)arg0 + idx * 0x18;
            if (v != 3) {
                u8 v2 = M2C_FIELD(M2C_FIELD(q, void **, 0x4), volatile u8 *, 0x3d);
                if (v2 == 2) {
                    M2C_FIELD(arg0, u8 *, 0x1) = idx;
                }
            } else {
                u8 v2 = M2C_FIELD(M2C_FIELD(q, void **, 0x4), volatile u8 *, 0x3d);
                if (v2 != 3) {
                    M2C_FIELD(arg0, u8 *, 0x1) = idx;
                }
            }
        }
    }

    {
        u8 a = M2C_FIELD(arg0, u8 *, 0xd);
        u8 b = M2C_FIELD(arg0, u8 *, 0xe);
        if (a < b) {
            M2C_FIELD(arg0, u8 *, 0xe) = a;
        }
    }
    {
        u8 a = M2C_FIELD(arg0, u8 *, 0x25);
        u8 b = M2C_FIELD(arg0, u8 *, 0x26);
        if (a < b) {
            M2C_FIELD(arg0, u8 *, 0x26) = a;
        }
    }

    {
        u8 idx1 = M2C_FIELD(arg0, u8 *, 0x13);
        void *p = M2C_FIELD(arg0, void **, 0x4);
        s32 *loc = (s32 *)((u8 *)p + idx1 * 4 + 0x2c);
        if (*loc == 0) {
            u8 r = (idx1 + 1) & 1;
            M2C_FIELD(arg0, u8 *, 0x13) = r;
        }
    }
    {
        u8 idx1 = M2C_FIELD(arg0, u8 *, 0x2b);
        void *p = M2C_FIELD(arg0, void **, 0x1c);
        s32 *loc = (s32 *)((u8 *)p + idx1 * 4 + 0x2c);
        if (*loc == 0) {
            u8 r = (idx1 + 1) & 1;
            M2C_FIELD(arg0, u8 *, 0x2b) = r;
        }
    }
}
