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
    M2C_UNK HeapFreeBlock();
    s32 var_r9;
    void *var_r10;

    var_r9 = 0;
    var_r10 = arg0;
    do {
        if (M2C_FIELD(var_r10, s32 *, 0) != 0) {
            HeapFreeBlock();
            M2C_FIELD(var_r10, s32 *, 0) = 0;
        }
        if (M2C_FIELD(var_r10, s32 *, 4) != 0) {
            HeapFreeBlock();
            M2C_FIELD(var_r10, s32 *, 4) = 0;
        }
        if (M2C_FIELD(var_r10, s32 *, 8) != 0) {
            HeapFreeBlock();
            M2C_FIELD(var_r10, s32 *, 8) = 0;
        }
        if (M2C_FIELD(var_r10, s32 *, 0xC) != 0) {
            HeapFreeBlock();
            M2C_FIELD(var_r10, s32 *, 0xC) = 0;
        }
        if (M2C_FIELD(var_r10, s32 *, 0x10) != 0) {
            HeapFreeBlock();
            M2C_FIELD(var_r10, s32 *, 0x10) = 0;
        }
        if (M2C_FIELD(var_r10, s32 *, 0x14) != 0) {
            HeapFreeBlock();
            M2C_FIELD(var_r10, s32 *, 0x14) = 0;
        }
        var_r9 += 1;
        var_r10 += 0x64;
    } while (var_r9 < 2);
}

#pragma opt_common_subs off
/* Sets up the ov002 battle scene: loads both players' settings and status
 * panels, initialises each side's battle unit view and its character effects,
 * then configures the background/3D-sprite control registers. */
void InitBattleScene(void *state) {
    void SetupPlayerSettings(void *);
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
    extern void *g3DSpriteBankMain;

    SetupPlayerSettings(&gPlayerSettings);
    func_ov002_021e3890(data_ov002_021f2f44);
    PlayerPanels_Init(data_ov002_021f2f44);

    {
        s32 side = 0;
        void *unitView = &data_ov002_021f3124;
        do {
            func_ov002_021e85e8(unitView);
            side++;
            unitView = (u8 *)unitView + 0x2C;
        } while (side < 2);
    }

    func_ov002_021e6cdc(&data_ov002_021f3018);
    func_020af7ac();
    func_020af760();

    {
        void *unitView = &data_ov002_021f3124;
        void *settings = &gPlayerSettings;
        s32 side = 0;
        M2C_FIELD(state, u8 *, 8) = (u8)side;
        M2C_FIELD(state, s32 *, 0) = side;
        M2C_FIELD(state, s32 *, 4) = side;
        M2C_FIELD(state, u8 *, 9) = (u8)side;

        do {
            func_ov002_021e8738(unitView);
            func_ov002_021e42a8(unitView, -0x50);
            {
                void *player = M2C_FIELD(settings, void **, 4);
                if (M2C_FIELD(player, u8 *, 0x3D) == 2) {
                    if (M2C_FIELD(unitView, u8 *, 0x2A) != 0) {
                        func_ov002_021e8d04(unitView, 0x200);
                    }
                }
            }
            side++;
            unitView = (u8 *)unitView + 0x2C;
            settings = (u8 *)settings + 0x18;
        } while (side < 2);
    }


    {
        volatile u16 *ctrlReg;
        M2C_FIELD(g3DSpriteBankMain, u16 *, 0) = (u16)(M2C_FIELD(g3DSpriteBankMain, u16 *, 0) | 0x10);
        M2C_FIELD(g3DSpriteBankMain, u16 *, 0) = (u16)(M2C_FIELD(g3DSpriteBankMain, u16 *, 0) & ~0x20);
        M2C_FIELD(g3DSpriteBankMain, u16 *, 0) = (u16)(M2C_FIELD(g3DSpriteBankMain, u16 *, 0) | 0x40);
        M2C_FIELD(g3DSpriteBankMain, u16 *, 0) = (u16)(M2C_FIELD(g3DSpriteBankMain, u16 *, 0) | 0x80);
        M2C_FIELD(g3DSpriteBankMain, u16 *, 0) = (u16)(M2C_FIELD(g3DSpriteBankMain, u16 *, 0) | 0x100);
        M2C_FIELD(g3DSpriteBankMain, u16 *, 0x12) = (u16)((M2C_FIELD(g3DSpriteBankMain, u16 *, 0x12) & ~0xC0) | 0x40);
        M2C_FIELD(g3DSpriteBankMain, u8 *, 0x51) = 0x10;
        M2C_FIELD(g3DSpriteBankMain, u8 *, 0x52) = 0;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b0=1;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b1=0;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b2=1;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b3=0;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b4=0;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b5=0;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b8=0;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b9=0;
        ctrlReg = (volatile u16 *)0x4000060;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b10=1;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b11=1;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b12=0;
        ((SetupFlags *)((u8 *)g3DSpriteBankMain+0x12))->b13=0;
        ctrlReg[0] = (u16)((ctrlReg[0] & ~0x3000) | 0x8);
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
extern void *gKeyState;
extern u32 gFrameCounter;
extern void *gTouchState;
if(data_ov002_021f2f40) return;
if(M2C_FIELD(gKeyState,u16 *,6)&0x200) {
if(gFrameCounter&1) func_ov002_021e70a0(arg0);
} else if(M2C_FIELD(gKeyState,u16 *,6)&0x100) {
func_ov002_021e70a0(arg0); func_ov002_021e70a0(arg0);
} else func_ov002_021e70a0(arg0);
if(!M2C_FIELD(arg0,u8 *,9)) return;
if((M2C_FIELD(gKeyState,u16 *,0)&0xB)||M2C_FIELD(gTouchState,u8 *,0x14)) func_ov002_021e795c(arg0);
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

#pragma opt_common_subs off
#pragma opt_strength_reduction off
void func_ov002_021e712c(void *arg0) {
    s32 EaseInterpolate(s32, s32, s32, s32, s32);
    void func_ov002_021e8898(void *, s32);
    void func_ov002_021e42a8(void *, s32);
    void func_ov002_021e8d04(void *, s32);
    extern s32 data_ov002_021f3124, data_ov002_021f3150, gPlayerSettings;
    extern void *g3DSpriteBankMain, *g3DSpriteEngineMain, *g3DSpriteEngineSub;
    s32 v, i, j;

    // Advance transition timer and interpolate panel/sprite positions and alpha
    M2C_FIELD(arg0, s32 *, 0)++;
    v = EaseInterpolate(4, -256, 0, M2C_FIELD(arg0, s32 *, 0), 32);
    func_ov002_021e8898(&data_ov002_021f3124, v);
    func_ov002_021e8898(&data_ov002_021f3150, v);
    v = EaseInterpolate(0, 16, 0, M2C_FIELD(arg0, s32 *, 0), 32);
    M2C_FIELD(g3DSpriteBankMain, u8 *, 0x51) = v;
    M2C_FIELD(g3DSpriteBankMain, u8 *, 0x52) = 16 - v;
    v = EaseInterpolate(4, -80, 0, M2C_FIELD(arg0, s32 *, 0), 32);
    func_ov002_021e42a8(&data_ov002_021f3124, v);
    func_ov002_021e42a8(&data_ov002_021f3150, v);
    v = EaseInterpolate(0, 512, 256, M2C_FIELD(arg0, s32 *, 0), 32);
    if (M2C_FIELD(M2C_FIELD(&gPlayerSettings, void **, 4), u8 *, 0x3D) == 2 && M2C_FIELD(&data_ov002_021f3124, u8 *, 0x2A)) {
        func_ov002_021e8d04(&data_ov002_021f3124, (u16)v);
    }
    if (M2C_FIELD(M2C_FIELD(&gPlayerSettings, void **, 28), u8 *, 0x3D) == 2 && M2C_FIELD(&data_ov002_021f3124, u8 *, 0x56)) {
        func_ov002_021e8d04(&data_ov002_021f3150, (u16)v);
    }
    if (M2C_FIELD(arg0, s32 *, 0) != 32) {
        return;
    }
    M2C_FIELD(g3DSpriteBankMain, u16 *, 0) |= 16;
    M2C_FIELD(g3DSpriteBankMain, u16 *, 0) &= ~32;
    M2C_FIELD(g3DSpriteBankMain, u16 *, 0) &= ~64;
    M2C_FIELD(g3DSpriteBankMain, u16 *, 0) |= 128;
    M2C_FIELD(g3DSpriteBankMain, u16 *, 0) |= 256;
    M2C_FIELD(g3DSpriteBankMain, u16 *, 0x12) = (M2C_FIELD(g3DSpriteBankMain, u16 *, 0x12) & ~0xC0) | 0x40;
    M2C_FIELD(g3DSpriteBankMain, u8 *, 0x51) = 16;
    M2C_FIELD(g3DSpriteBankMain, u8 *, 0x52) = 16;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b0 = 1;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b1 = 0;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b2 = 0;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b3 = 0;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b4 = 0;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b5 = 0;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b8 = 0;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b9 = 0;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b10 = 0;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b11 = 1;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b12 = 0;
    ((SetupFlags *)((u8 *)g3DSpriteBankMain + 0x12))->b13 = 0;
    i = 0;
    j = 0;
    do {
        M2C_FIELD((u8 *)0x6007800 + j * 2, u16 *, 0) = M2C_FIELD((u8 *)M2C_FIELD(g3DSpriteEngineMain, void **, 0x2C) + j * 2, u16 *, 0x3E) ^ 0x400;
        M2C_FIELD((u8 *)0x6007800 + j * 2, u16 *, 0x3E) = M2C_FIELD(M2C_FIELD(g3DSpriteEngineMain, void **, 0x2C), u16 *, j * 2) ^ 0x400;
        M2C_FIELD((u8 *)0x600f800 + j * 2, u16 *, 0) = M2C_FIELD((u8 *)M2C_FIELD(g3DSpriteEngineSub, void **, 0x2C) + j * 2, u16 *, 0x3E) ^ 0x400;
        M2C_FIELD((u8 *)0x600f800 + j * 2, u16 *, 0x3E) = M2C_FIELD(M2C_FIELD(g3DSpriteEngineSub, void **, 0x2C), u16 *, j * 2) ^ 0x400;
        i++;
        j += 32;
    } while (i < 32);
    M2C_FIELD(arg0, u8 *, 8) = 2;
    M2C_FIELD(arg0, s32 *, 0) = 0;
}
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
/* Set up both players' battle settings for the scene: point each side at its
 * army and unit-set definitions, choose the animation variant for certain CO
 * types, then fix up the active player, stat pairs and cursor slots. */
void SetupPlayerSettings(void *settings) {
    extern M2C_UNK gPlayerSettings;
    extern u8 data_ov002_021f1134[];
extern u8 data_ov002_021f2f40;
    extern u8 data_ov002_021f1bf4[];
    u8 func_ov002_021e8014(s32, s32);
    s32 func_ov002_021e79c4(M2C_UNK, M2C_UNK);
    u8 func_ov002_021e8038(s32, s32);
    s32 func_ov002_021e7a14(M2C_UNK, M2C_UNK);

    M2C_FIELD(settings, void **, 0x4) = (void *)(data_ov002_021f1134 + M2C_FIELD(&gPlayerSettings, u8 *, 0xc) * 64);
    M2C_FIELD(settings, void **, 0x1c) = (void *)(data_ov002_021f1134 + M2C_FIELD(&gPlayerSettings, u8 *, 0x24) * 64);
    M2C_FIELD(settings, void **, 0x8) = (void *)(data_ov002_021f1bf4 + M2C_FIELD(&gPlayerSettings, u8 *, 0x10) * 0x24);
    M2C_FIELD(settings, void **, 0x20) = (void *)(data_ov002_021f1bf4 + M2C_FIELD(&gPlayerSettings, u8 *, 0x28) * 0x24);

    if (M2C_FIELD(M2C_FIELD(settings, void **, 0x4), u8 *, 0x3d) == 2) {
        if (func_ov002_021e8014((s32)settings, 0) == 0) {
            u8 variant = func_ov002_021e79c4((M2C_UNK)settings, 0);
            M2C_FIELD(&gPlayerSettings, u8 *, 0x10) = variant;
        }
    }
    if (M2C_FIELD(M2C_FIELD(settings, void **, 0x1c), u8 *, 0x3d) == 2) {
        if (func_ov002_021e8014((s32)settings, 1) == 0) {
            u8 variant = func_ov002_021e79c4((M2C_UNK)settings, 1);
            M2C_FIELD(&gPlayerSettings, u8 *, 0x28) = variant;
        }
    }
    if (M2C_FIELD(M2C_FIELD(settings, void **, 0x4), u8 *, 0x3d) == 3) {
        if (func_ov002_021e8038((s32)settings, 0) == 0) {
            u8 variant = func_ov002_021e7a14((M2C_UNK)settings, 0);
            M2C_FIELD(&gPlayerSettings, u8 *, 0x10) = variant;
        }
    }
    if (M2C_FIELD(M2C_FIELD(settings, void **, 0x1c), u8 *, 0x3d) == 3) {
        if (func_ov002_021e8038((s32)settings, 1) == 0) {
            u8 variant = func_ov002_021e7a14((M2C_UNK)settings, 1);
            M2C_FIELD(&gPlayerSettings, u8 *, 0x28) = variant;
        }
    }

    M2C_FIELD(settings, void **, 0x8) = (void *)(data_ov002_021f1bf4 + M2C_FIELD(&gPlayerSettings, u8 *, 0x10) * 0x24);
    M2C_FIELD(settings, void **, 0x20) = (void *)(data_ov002_021f1bf4 + M2C_FIELD(&gPlayerSettings, u8 *, 0x28) * 0x24);

    if (data_ov002_021f2f40 == 0) {
        u8 side = M2C_FIELD(settings, u8 *, 0x0);
        s32 otherSide = (side == 0) ? 1 : 0;
        u8 otherType = M2C_FIELD(M2C_FIELD((u8 *)settings + otherSide * 0x18, void **, 0x4), u8 *, 0x3d);
        if (otherType != 2) {
            u8 *sideSettings = (u8 *)settings + side * 0x18;
            if (otherType != 3) {
                u8 ownType = M2C_FIELD(M2C_FIELD(sideSettings, void **, 0x4), volatile u8 *, 0x3d);
                if (ownType == 2) {
                    M2C_FIELD(settings, u8 *, 0x1) = side;
                }
            } else {
                u8 ownType = M2C_FIELD(M2C_FIELD(sideSettings, void **, 0x4), volatile u8 *, 0x3d);
                if (ownType != 3) {
                    M2C_FIELD(settings, u8 *, 0x1) = side;
                }
            }
        }
    }

    {
        u8 statA = M2C_FIELD(settings, u8 *, 0xd);
        u8 statB = M2C_FIELD(settings, u8 *, 0xe);
        if (statA < statB) {
            M2C_FIELD(settings, u8 *, 0xe) = statA;
        }
    }
    {
        u8 statA = M2C_FIELD(settings, u8 *, 0x25);
        u8 statB = M2C_FIELD(settings, u8 *, 0x26);
        if (statA < statB) {
            M2C_FIELD(settings, u8 *, 0x26) = statA;
        }
    }

    {
        u8 slot = M2C_FIELD(settings, u8 *, 0x13);
        void *armyDef = M2C_FIELD(settings, void **, 0x4);
        s32 *slotEntry = (s32 *)((u8 *)armyDef + slot * 4 + 0x2c);
        if (*slotEntry == 0) {
            u8 next = (slot + 1) & 1;
            M2C_FIELD(settings, u8 *, 0x13) = next;
        }
    }
    {
        u8 slot = M2C_FIELD(settings, u8 *, 0x2b);
        void *armyDef = M2C_FIELD(settings, void **, 0x1c);
        s32 *slotEntry = (s32 *)((u8 *)armyDef + slot * 4 + 0x2c);
        if (*slotEntry == 0) {
            u8 next = (slot + 1) & 1;
            M2C_FIELD(settings, u8 *, 0x2b) = next;
        }
    }
}
