/* 35 functions from 0x02174F68 to 0x02175F60 (ov001), found by ds-decomp. */
#include "common.h"

typedef struct { s32 x; u32 y; } Position;

void func_ov001_021757d0(s32 arg0) {
    M2C_UNK func_ov001_0216d14c();
    M2C_UNK func_ov001_02184b50(void *);
    extern M2C_UNK gOv001WirelessSetup;
    extern M2C_UNK data_ov001_02193d28;
    func_ov001_0216d14c();
    if (arg0 != 0) {
        if ((M2C_FIELD(M2C_FIELD(&gOv001WirelessSetup, void **, 4), u8 *, 0x116) == 0) && (M2C_FIELD(&gOv001WirelessSetup, u8 *, 0) == 1)) {
            func_ov001_02184b50(M2C_FIELD(&gOv001WirelessSetup, void **, 4) + 0x117);
        }
    }
    Ov001_FreeAlloc(&data_ov001_02193d28);
}

s32 func_ov001_02175820(void) {
    extern M2C_UNK gOv001WirelessSetup;
    s32 func_ov001_0216ad74(M2C_UNK);
    if (func_ov001_0216ad74(M2C_FIELD(&gOv001WirelessSetup, M2C_UNK *, 4)) == 0) {
        M2C_FIELD(&gOv001WirelessSetup, u8 *, 0) = 1;
        return 1;
    }
    {
        u8 c = M2C_FIELD(M2C_FIELD(&gOv001WirelessSetup, M2C_UNK *, 4), u8 *, 0x116);
        if (c == 1) goto L0;
        if ((u8)(c + 0xFD) > 2) goto L2;
    L0:
        return 0;
    L2:
        return 2;
    }
}

void Ov001_AllocWirelessWork(M2C_UNK arg0) {
    M2C_UNK Ov001_Alloc(M2C_UNK, M2C_UNK);
    Ov001_Alloc(arg0, 0x20);
}

void Ov001_FreeWirelessWork(void) {
    M2C_UNK func_ov001_0218b760();
    func_ov001_0218b760();
}

s32 func_ov001_0217589c(M2C_UNK arg0, s32 arg1, s32 arg2) {
void Ov001_InitScreen(void);
s32 func_ov001_02175928(s32,s32);
void Ov001_InitCore(void); void Ov001_SetupDisplay(void); void func_ov001_02184f68(void);
void Ov001_SetStepCallback(s32); void func_ov001_0218b850(void); void func_ov001_0218c7d4(s32);
void func_ov001_0218bdb0(void); void func_ov001_0218c63c(void); void func_02007598(void); void func_ov001_02175d04(void);
extern u8 gOv001ScreenState;
M2C_FIELD(&gOv001ScreenState,M2C_UNK*,4)=arg0;
if (!func_ov001_02175928(arg1,arg2)) return -1;
M2C_FIELD(&gOv001ScreenState,u8*,1)=0;
Ov001_InitCore(); Ov001_SetupDisplay(); func_ov001_02184f68();
Ov001_SetStepCallback((s32)Ov001_InitScreen);
do {
func_ov001_0218b850();
M2C_FIELD(&gOv001ScreenState,void(**)(void),12)();
func_ov001_0218c7d4(0); func_ov001_0218bdb0(); func_ov001_0218c63c(); func_02007598();
} while (!M2C_FIELD(&gOv001ScreenState,u8*,1));
func_ov001_02175d04(); return 0;
}

#pragma scheduling off
s32 func_ov001_02175928(s32 arg0,s32 arg1){
extern u8 gOv001ScreenState;
M2C_FIELD(&gOv001ScreenState,u8 *,0)=arg0;
M2C_FIELD(&gOv001ScreenState,s32 *,8)=arg1;
if(arg0<0||arg0>6)return 0;
if(arg0==1){if(((u32)arg1>>4)&~2U)return 0;}
arg1=M2C_FIELD(&gOv001ScreenState,s32 *,8);
{u32 nibble=(u32)(arg1<<28); nibble>>=28; if(nibble>1U)return 0;}
if(arg0!=0){if(((u32)arg1>>4)&1)return 0;}
if(arg0==0){if(!(((u32)M2C_FIELD(&gOv001ScreenState,volatile s32 *,8)>>4)&1))return 0;}
return 1;
}
#pragma scheduling reset
/* Bring overlay 001 up: stop interrupts and the sub display, halt if a core
 * device fails to initialise, reset the display and the vblank IRQ, then
 * initialise the ov001 subsystems (tasks, fades, sound, streaming) and run the
 * save-block initialiser on a temporary 0x700-byte scratch buffer. */
void Ov001_InitCore(void) {
extern u8 gOv001ScreenState;
M2C_UNK func_02002490(); M2C_UNK func_02006f8c(); M2C_UNK func_02007180(); M2C_UNK SystemHalt(); void GX_SetVBlankIrq(s32); M2C_UNK func_020022d8(); M2C_UNK func_0200b74c(); M2C_UNK func_0200d544(); M2C_UNK func_0200ee70(); M2C_UNK GxReleaseAllBankGrants(); M2C_UNK func_ov001_0218b648(); M2C_UNK func_ov001_0218be2c(); M2C_UNK Ov001_InitTasks(); M2C_UNK func_ov001_02189ad0(); M2C_UNK func_ov001_0218b79c(); M2C_UNK Ov001_InitFades(); M2C_UNK Ov001_Alloc(M2C_UNK,M2C_UNK); M2C_UNK func_02046884();
M2C_UNK scratch;
*(volatile u16 *)0x4000208; *(volatile u16 *)0x4000208=0;
func_02002490(0);*(volatile u32 *)0x4001000&=~0x10000;
if(!func_02006f8c())SystemHalt();if(!func_02007180())SystemHalt();GX_SetVBlankIrq(0);func_020022d8();func_0200b74c(-1);func_0200d544();func_02002490(func_0200ee70());*(volatile u32 *)0x4001000&=~0x10000;
GxReleaseAllBankGrants();func_ov001_0218b648(M2C_FIELD(&gOv001ScreenState,M2C_UNK *,4));func_ov001_0218be2c();Ov001_InitTasks();func_ov001_02189ad0();func_ov001_0218b79c();Ov001_InitFades();scratch=Ov001_Alloc(0x700,0x20);func_02046884();Ov001_FreeAlloc(&scratch);
}

/* Initialise the display for overlay 001: allocate VRAM banks for the
 * background, reset and configure the background control/scroll registers of
 * both the main and sub engines, set up alpha blending and master brightness,
 * then turn the main display on. */
void Ov001_SetupDisplay(void) {
    void GX_SetVBlankIrq(s32);
    void GX_SetBankForBG(s32);
    void GX_SetBankForOBJ(s32);
    void GX_ConfigureDisplay(s32, s32, s32);
    void GX_SetMasterBrightness(void *, s32);
    void GX_SetBlendControl(s32, s32, s32);
    void func_02003124(s32);
    void func_020031cc(s32);
    void GX_SetSubBgMode(s32);
    void func_ov001_0218aab4(void);
    void Ov001_InitSpriteObjs(void);
    void Ov001_InitTilePools(void);
    void Ov001_InitSpritePools(void);
    void GX_TurnOnDisplay(void);

    GX_SetVBlankIrq(0);
    GX_SetBankForBG(1);
    GX_SetBankForOBJ(2);
    GX_ConfigureDisplay(1, 0, 0);

    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x1f00);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0xe000);
    GX_SetMasterBrightness((void *)0x0400006C, 0);

    *(volatile u32 *)0x04000000 =
        (*(volatile u32 *)0x04000000 & 0xffcfffef) | 0x10 | 0x200000;
    *(volatile u16 *)0x04000008 = (*(volatile u16 *)0x04000008 & ~0x40);
    *(volatile u16 *)0x0400000a = (*(volatile u16 *)0x0400000a & ~0x40);
    *(volatile u16 *)0x0400000c = (*(volatile u16 *)0x0400000c & ~0x40);
    *(volatile u16 *)0x0400000e = (*(volatile u16 *)0x0400000e & ~0x40);
    *(volatile u32 *)0x04000010 = 0;
    *(volatile u32 *)0x04000014 = 0;
    *(volatile u32 *)0x04000018 = 0;
    *(volatile u32 *)0x0400001c = 0;
    GX_SetBlendControl(0x04000050, 0x3f, 0x10);
    func_02003124(0x80);
    func_020031cc(0x100);
    GX_SetSubBgMode(0);

    {
        volatile u32 *display = (volatile u32 *)0x04001000;
        u32 value;
        value = *display;
        *display = value & ~0x1f00;
        value = *display;
        *display = value & ~0xe000;
        GX_SetMasterBrightness((u8 *)display + 0x6c, 0);
    }


    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & 0xffcfffef) | 0x10;
    *(volatile u16 *)0x04001008 = (*(volatile u16 *)0x04001008 & ~0x40);
    *(volatile u16 *)0x0400100a = (*(volatile u16 *)0x0400100a & ~0x40);
    *(volatile u16 *)0x0400100c = (*(volatile u16 *)0x0400100c & ~0x40);
    *(volatile u16 *)0x0400100e = (*(volatile u16 *)0x0400100e & ~0x40);
    *(volatile u32 *)0x04001010 = 0;
    *(volatile u32 *)0x04001014 = 0;
    *(volatile u32 *)0x04001018 = 0;
    *(volatile u32 *)0x0400101c = 0;
    GX_SetBlendControl(0x04001050, 0x3f, 0x10);

    *(volatile u16 *)0x04000008 = (*(volatile u16 *)0x04000008 & 0x43) | 0xc00;
    *(volatile u16 *)0x0400000a = (*(volatile u16 *)0x0400000a & 0x43) | 0x108 | 0xc00;
    *(volatile u16 *)0x0400000c = (*(volatile u16 *)0x0400000c & 0x43) | 0xe10;
    *(volatile u16 *)0x0400000e = (*(volatile u16 *)0x0400000e & 0x43) | 0xf10;
    *(volatile u16 *)0x04001008 = (*(volatile u16 *)0x04001008 & 0x43) | 0xc00;
    *(volatile u16 *)0x0400100a = (*(volatile u16 *)0x0400100a & 0x43) | 0xd00;
    *(volatile u16 *)0x0400100c = (*(volatile u16 *)0x0400100c & 0x43) | 0xe00;
    *(volatile u16 *)0x0400100e = (*(volatile u16 *)0x0400100e & 0x43) | 0xf00;

    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x38000000);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x7000000);
    *(volatile u16 *)0x04000304 = (*(volatile u16 *)0x04000304 & ~0x8000);

    func_ov001_0218aab4();
    Ov001_InitSpriteObjs();
    Ov001_InitTilePools();
    Ov001_InitSpritePools();
    GX_TurnOnDisplay();

    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 | 0x10000);
    GX_SetVBlankIrq(1);
}

void func_ov001_02175d04(void) {
    M2C_UNK func_02002490();
    M2C_UNK func_ov001_02184ff8();
    M2C_UNK func_ov001_02189c80();
    M2C_UNK func_ov001_0218a01c();
    M2C_UNK Ov001_FreeFades();
    M2C_UNK func_ov001_0218abb8();
    M2C_UNK func_ov001_0218b688();
    M2C_UNK func_ov001_0218b818();
    M2C_UNK func_ov001_0218bea0();
    M2C_UNK func_ov001_0218c0b8();
    M2C_UNK func_ov001_0218c4c0();
    M2C_UNK func_ov001_0218c668();
    M2C_UNK func_ov001_0218c78c();
    func_02002490();
    *(s32 *)0x04001000 &= ~0x10000;
    func_ov001_0218c668();
    func_ov001_0218b818();
    func_ov001_0218bea0();
    func_ov001_02184ff8();
    func_ov001_0218a01c();
    func_ov001_0218c0b8();
    func_ov001_0218abb8();
    Ov001_FreeFades();
    func_ov001_02189c80();
    func_ov001_0218c78c();
    func_ov001_0218b688();
    func_ov001_0218c4c0();
}

void Ov001_SetStepCallback(s32 arg0) {
    extern u8 gOv001ScreenState;
    M2C_FIELD(&gOv001ScreenState, s32 *, 0xc) = arg0;
}

void Ov001_SetNextScreenMode(s32 arg0, s32 arg1) {
    extern u8 gOv001ScreenState;
    M2C_FIELD(&gOv001ScreenState, s32 *, 0x10) = arg0;
    M2C_FIELD(&gOv001ScreenState, s32 *, 0x14) = arg1;
}

void func_ov001_02175d78(s32 *arg0, s32 *arg1) {
    extern u8 gOv001ScreenState;
    if (arg0 != 0) {
        *arg0 = M2C_FIELD(&gOv001ScreenState, s32 *, 0x10);
    }
    if (arg1 != 0) {
        *arg1 = M2C_FIELD(&gOv001ScreenState, s32 *, 0x14);
    }
}

void Ov001_SetNameEntryMode(s32 arg0, s32 arg1) {
    extern u8 gOv001ScreenState;
    M2C_FIELD(&gOv001ScreenState, s32 *, 0x18) = arg0;
    M2C_FIELD(&gOv001ScreenState, s32 *, 0x1c) = arg1;
}

void Ov001_GetNameEntryMode(s32 *arg0, s32 *arg1) {
    extern u8 gOv001ScreenState;
    if (arg0 != 0) {
        *arg0 = M2C_FIELD(&gOv001ScreenState, s32 *, 0x18);
    }
    if (arg1 != 0) {
        *arg1 = M2C_FIELD(&gOv001ScreenState, s32 *, 0x1c);
    }
}

u8 Ov001_GetLanguage(void) {
    extern u8 gOv001ScreenState;
    return gOv001ScreenState;
}

s32 Ov001_GetScreenLayout(void) {
    extern u8 gOv001ScreenState;
    typedef struct { u32 a, b; unsigned val : 4; } S;
    return ((S *)&gOv001ScreenState)->val;
}

s32 Ov001_HasOptionFlag(s32 arg0) {
    extern u8 gOv001ScreenState;
    if (arg0 & ((u32)M2C_FIELD(&gOv001ScreenState, s32 *, 8) >> 4)) {
        return 1;
    }
    return 0;
}

void func_ov001_02175e20(void) {
    extern u8 gOv001ScreenState;
    M2C_FIELD(&gOv001ScreenState, u8 *, 1) = 1;
}

s32 func_ov001_02175e34(void) {
    extern u8 gOv001ScreenState;
    u8 r1 = gOv001ScreenState;
    if (r1 == 6) {
        return 0x38;
    }
    if (r1 == 1) {
        if (!(( ((u32)M2C_FIELD(&gOv001ScreenState, s32 *, 8)) >> 4) & 2)) {
            return 0x37;
        }
    }
    return (r1 + 0x31) & 0xFF;
}

void func_ov001_02175e74(void) {
    M2C_UNK Ov001_Alloc(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_QueueCreateFromBuffer(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_02193d4c;
    M2C_UNK val;
    M2C_UNK res;
    val = Ov001_Alloc(0x64, 0x4);
    data_ov001_02193d4c = val;
    res = Ov001_QueueCreateFromBuffer(0x8, val, 0xc);
    M2C_FIELD((void *)data_ov001_02193d4c, M2C_UNK *, 0x60) = res;
}

void func_ov001_02175eb0(void) {
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern M2C_UNK data_ov001_02193d4c;
    Ov001_FreeAlloc(&data_ov001_02193d4c);
}

M2C_UNK Ov001_LoadMessageArchive(M2C_UNK arg0) {
    M2C_UNK Ov001_QueuePop(M2C_UNK);
    M2C_UNK Ov001_LoadFile(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_02193d4c;
    M2C_UNK var_r4;
    M2C_UNK local;
    M2C_UNK ret;
    M2C_UNK r2;
    M2C_UNK r1;
    var_r4 = Ov001_QueuePop(M2C_FIELD(data_ov001_02193d4c, M2C_UNK *, 0x60));
    ret = Ov001_LoadFile(arg0, &local, 4);
    r2 = ret + 0x20;
    M2C_FIELD(var_r4, M2C_UNK *, 0x8) = ret;
    M2C_FIELD(var_r4, M2C_UNK *, 0x0) = r2 + 0x10;
    r1 = M2C_FIELD(r2, M2C_UNK *, 0x4);
    M2C_FIELD(var_r4, M2C_UNK *, 0x4) = r2 + r1 + 0x8;
    return var_r4;
}

void func_ov001_02175f1c(M2C_UNK arg0) {
    M2C_UNK Ov001_FreeFile(M2C_UNK);
    M2C_UNK Ov001_QueuePush(M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_02193d4c;
    Ov001_FreeFile(M2C_FIELD((void *)arg0, M2C_UNK *, 0x8));
    Ov001_QueuePush(M2C_FIELD((void *)data_ov001_02193d4c, M2C_UNK *, 0x60), arg0);
}

s32 Ov001_GetMessageText(M2C_UNK arg0, u32 arg1) {
    void **p = (void **)arg0;
    arg1 = (arg1 << 16) >> 16;
    return ((s32 *)p[0])[(u32)arg1] + (s32)p[1];
}
