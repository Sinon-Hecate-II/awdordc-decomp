/* 37 functions from 0x020D7BC8 to 0x020D8BB4 (main), found by ds-decomp. */
#include "common.h"

#pragma push
#pragma opt_strength_reduction off
#pragma opt_lifetimes off
/* Draws a unit's status panel at (x,y): kind icon, health bars, ammo, attack and
 * movement icons plus the owning player's colour strip. */
void DrawUnitStatus(s32 x,s32 y,s32 side,void *unit) {
extern void **gCurrentMap;
extern void *gCur3DSpriteEngine;
extern u8 gSpriteDesc8x8[],gSpriteDesc32x16[],gSpriteDesc16x16[];
s32 GetUnitKind(void *);
s32 GetUnitHealthBarCount(void *);
s32 func_ov000_0216cd2c(void *);
s32 GetUnitAmmo(void *);
s32 func_ov000_0216cd4c(s32);
s32 func_ov000_0216cd78(s32,s32);
s32 func_ov000_0216cd90(s32);
void func_0207c3dc(s32,s32,s32,s32);
void func_01ff9e44(s32,s32,s32);
s32 func_020a8604(s32);
s32 func_020a7c68(s32);
void DrawDecimalNumber(s32,s32,s32);
void AddSprite(u16,u16,u16,void *,s32);
s32 unitKind=GetUnitKind(unit);
s32 colorIndex,variantIndex,screenY;
s32 unitId;
u8 *playerData;
if(unit==0)unitId=0;else unitId=((s32)unit-(s32)((u8 *)*gCurrentMap+0x59a4))/14;
playerData=(u8 *)*gCurrentMap+0x67a4+((unitId>>6)+1)*140;
colorIndex=playerData[0x1d];variantIndex=playerData[0x29];
screenY=(y+16)&255;
AddSprite((u16)((x+23)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (22 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
DrawDecimalNumber((x+39)&511,screenY,GetUnitHealthBarCount(unit));
AddSprite((u16)((x+47)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (24 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
DrawDecimalNumber((x+63)&511,screenY,func_ov000_0216cd2c(unit));
if(func_020a8604((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)) {
AddSprite((u16)((x+71)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (58 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
}else{
AddSprite((u16)((x+71)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (26 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
}
if(func_020a7c68((u32)(M2C_FIELD(unit,u8 *,0)<<26)>>26)==0) {
AddSprite((u16)((x+79)&511),(u16)screenY,(u16)(((0x3ff & (0x150 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30))) | 0x9000) + (0x3ff & (20 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))),gSpriteDesc8x8,8);
}else{
DrawDecimalNumber((x+79)&511,screenY,GetUnitAmmo(unit));
}
func_0207c3dc(func_ov000_0216cd4c(unitKind),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x4480,256,0);
AddSprite((u16)((x+20)&511),(u16)((y+2)&255),(u16)((0x3ff & (0x224 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))+0x9000),gSpriteDesc32x16,8);
func_01ff9e44(func_ov000_0216cd90(colorIndex),0x300,32);
func_0207c3dc(func_ov000_0216cd78(unitKind,variantIndex),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x4300,128,0);
AddSprite((u16)((x+4)&511),(u16)((y+4)&255),(u16)((0x3ff & (0x218 >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void *volatile *,0),u16 *,0)<<17)>>30)))+0x8000),gSpriteDesc16x16,9);
}
#pragma pop
void func_020d8084(void *arg0, s32 arg1, s32 arg2, s32 arg3) { (void)arg0; (void)arg1; (void)arg2; (void)arg3; }

s32 func_020d849c(void *arg0) {
    s32 func_020d2850(u32, u16, u8);
    extern void **gCurrentMap;
    s32 var_r3;
    if (arg0 == NULL) return 0;
    if (arg0 == NULL) var_r3 = 0;
    else var_r3 = ((s32)arg0 - (s32)((u8 *)*gCurrentMap + 0x59A4)) / 14;
    if (func_020d2850((u32)(M2C_FIELD(arg0,u8 *,0) << 26) >> 26, M2C_FIELD(*gCurrentMap,u16 *,0x52A4), (u8)((var_r3 >> 6)+1)) != 0) return 2;
    if ((M2C_FIELD(arg0,u8 *,12) | M2C_FIELD(arg0,u8 *,13)) != 0) return 2;
    return 1;
}

void func_020d8540(void) {
    extern void **gCurrentMap;
    void *temp_r0;
    temp_r0 = *gCurrentMap;
    M2C_FIELD(temp_r0,u16 *,0x52E6) = (M2C_FIELD(temp_r0,u16 *,0x52E6) & ~0x1FC) | ((u32)(M2C_FIELD(temp_r0,u16 *,0x52C2) << 25) >> 23);
    temp_r0 = *gCurrentMap;
    M2C_FIELD(temp_r0,u16 *,0x52E6) = (M2C_FIELD(temp_r0,u16 *,0x52E6) & ~0xFE00) | ((u32)(M2C_FIELD(temp_r0,u16 *,0x52C4) << 25) >> 16);
}

void func_020d8594(void) {
    /* Ease the camera height towards its target (168), using the hardware divider. */
    extern void **gCurrentMap;
    s32 func_0207c8ec(s32, s32);
    void *mapData;
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) <= 0) {
        M2C_FIELD(mapData, u16 *, 0x52E6) = (M2C_FIELD(mapData, u16 *, 0x52E6) & ~3) | 1;
        mapData = *gCurrentMap;
        if (M2C_FIELD(mapData, s16 *, 0x52E4) <= -99) M2C_FIELD(mapData, s16 *, 0x52E4) = 262;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= func_0207c8ec(M2C_FIELD(mapData, s16 *, 0x52E4) + 100, 2);
    }
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) > 168) {
        if (M2C_FIELD(mapData, s16 *, 0x52E4) <= 169) M2C_FIELD(mapData, s16 *, 0x52E4) = 168;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= func_0207c8ec(M2C_FIELD(mapData, s16 *, 0x52E4) - 168, 2);
        func_020d8540();
    }
    if (M2C_FIELD(*gCurrentMap, s16 *, 0x52E4) == 168) func_020d8540();
}

void func_020d867c(void) {
    /* Ease the camera height across the 0/268 wrap boundary, using the hardware divider. */
    extern void **gCurrentMap;
    s32 func_0207c8ec(s32, s32);
    void *mapData;
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) >= 168) {
        M2C_FIELD(mapData, u16 *, 0x52E6) = (M2C_FIELD(mapData, u16 *, 0x52E6) & ~3);
        mapData = *gCurrentMap;
        if (M2C_FIELD(mapData, s16 *, 0x52E4) >= 267) M2C_FIELD(mapData, s16 *, 0x52E4) = -94;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= func_0207c8ec(M2C_FIELD(mapData, s16 *, 0x52E4) - 268, 2);
    }
    mapData = *gCurrentMap;
    if (M2C_FIELD(mapData, s16 *, 0x52E4) < 0) {
        if (M2C_FIELD(mapData, s16 *, 0x52E4) >= -1) M2C_FIELD(mapData, s16 *, 0x52E4) = 0;
        else M2C_FIELD(mapData, s16 *, 0x52E4) -= func_0207c8ec(M2C_FIELD(mapData, s16 *, 0x52E4), 2);
        func_020d8540();
    }
    if (M2C_FIELD(*gCurrentMap, s16 *, 0x52E4) == 0) func_020d8540();
}

s32 func_020d8764(void) {
    void func_02079c6c(s16,s16,s32 *);
    extern void **gCurrentMap;
    s32 sp0[3];
    void *temp_r0 = *gCurrentMap;
    func_02079c6c(M2C_FIELD(temp_r0,s16 *,0x52C2),M2C_FIELD(temp_r0,s16 *,0x52C4),sp0);
    if (sp0[1] > 128) return sp0[0] < 128 ? 1 : 0;
    return (u32)(M2C_FIELD(*gCurrentMap,u16 *,0x52E6) << 30) >> 30;
}

void func_020d87d8(void) {
    void func_020d8594();
    void func_020d867c(void);
    s32 func_020d8764();
    s32 temp_r0;

    temp_r0 = func_020d8764();
    switch (temp_r0) {                              /* irregular */
    case 0:
        func_020d867c();
        return;
    case 1:
        func_020d8594();
        return;
    }
}

void func_020d8804(void) {
    extern void **gCurrentMap;
    s32 temp_r0;

    temp_r0 = func_020d8764();
    switch (temp_r0) {                              /* irregular */
    case 0:
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E4) = 0;
        return;
    case 1:
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E4) = 0xA8;
        return;
    }
}

void func_020d885c(s32 arg0) {
    extern s32 data_02168f28;
    data_02168f28 = arg0;
}

s32 func_020d886c(void) {
    extern s32 data_02168f28;
    return data_02168f28;
}

void func_020d887c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212c058;
    func_01ffa3dc(&data_0212c058, 7);
}

M2C_UNK func_020d8894(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bfe8;
    func_01ffa3dc(&data_0212bfe8, 7);
}

void func_020d88ac(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212c020;
    func_01ffa3dc(&data_0212c020, 7);
}

M2C_UNK func_020d88c4(void) {
 M2C_UNK func_01ffa3dc(M2C_UNK *,M2C_UNK);
 extern u16 gMapConfig; extern M2C_UNK data_0212bfb8;
 gMapConfig=(gMapConfig&~7)|4;
 func_01ffa3dc(&data_0212bfb8,7);
}

void func_020d88f4(void) {
    M2C_UNK func_020d895c();
    M2C_UNK func_020d8cc4();
    func_020d8cc4();
    func_020d895c();
}

void func_020d8904(void) {
    M2C_UNK func_020d895c();
    M2C_UNK func_020d8cc4();
    func_020d8cc4();
    func_020d895c();
}

void func_020d8914(void) {
    M2C_UNK func_0209f87c();
    M2C_UNK func_020a2204(M2C_UNK);
    func_0209f87c();
    func_020a2204(0);
}

void func_020d8928(void) {
    s32 func_020846a4();
    extern M2C_UNK data_02168f0c;
    if (func_020846a4() == 0) {
        return;
    }
    M2C_FIELD(&data_02168f0c, s8 *, 0) = 1;
    M2C_FIELD(&data_02168f0c, s8 *, 1) = 0;
    M2C_FIELD(&data_02168f0c, s8 *, 2) = 0;
    M2C_FIELD(&data_02168f0c, s8 *, 3) = 1;
}

M2C_UNK func_020d895c(void) {
 M2C_UNK func_01ffa3dc(M2C_UNK *,M2C_UNK);
 extern u16 gMapConfig; extern M2C_UNK data_0212c1a0;
 gMapConfig=(gMapConfig&~7)|1;
 func_01ffa3dc(&data_0212c1a0,7);
}

void func_020d898c(void) {
    M2C_UNK func_020d4ac8(M2C_UNK);
    extern M2C_UNK data_02168f2c;
    if (M2C_FIELD(&data_02168f2c, s8 *, 8) != 0) {
        func_020d4ac8(8);
        return;
    }
    func_020d895c();
}

M2C_UNK func_020d89b8(void) {
 M2C_UNK func_01ffa3dc(M2C_UNK *,M2C_UNK);
 extern u16 gMapConfig; extern M2C_UNK data_0212c098;
 gMapConfig=(gMapConfig&~7)|2;
 func_01ffa3dc(&data_0212c098,7);
}

void func_020d89e8(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bf38;
    func_01ffa3dc(&data_0212bf38, 7);
}

void func_020d8a00(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bf78;
    func_01ffa3dc(&data_0212bf78, 7);
}

void func_020d8a18(void) {
    M2C_UNK func_020cd480(M2C_UNK);
    func_020cd480(0);
}

void func_020d8a28(void) {
    func_020cd480(1);
}

void func_020d8a38(void) {
    func_020cd480(2);
}

void func_020d8a48(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bf58;
    func_01ffa3dc(&data_0212bf58, 7);
}

u8 func_020d8a60(void) {
    extern u16 gMapConfig;
    u8 var_r0;

    if ((u8) ((u32) (gMapConfig << 0x1D) >> 0x1D) == 7) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

M2C_UNK func_020d8a8c(void) {
 M2C_UNK func_01ffa3dc(M2C_UNK *,M2C_UNK);
 extern u16 gMapConfig; extern M2C_UNK data_0212c0d8;
 gMapConfig=(gMapConfig&~7)|6;
 func_01ffa3dc(&data_0212c0d8,7);
}

void func_020d8abc(void) {
    M2C_UNK func_020d8a8c();
    func_020d8a8c();
}

void func_020d8ac8(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bf98;
    func_01ffa3dc(&data_0212bf98, 7);
}

M2C_UNK func_020d8ae0(void) {
 M2C_UNK func_01ffa3dc(M2C_UNK *,M2C_UNK);
 extern u16 gMapConfig; extern M2C_UNK data_0212c0d8;
 gMapConfig=(gMapConfig&~7)|7;
 func_01ffa3dc(&data_0212c0d8,7);
}

void func_020d8b10(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212bf18;
    func_01ffa3dc(&data_0212bf18, 7);
}

void func_020d8b28(void) {
    M2C_UNK func_020d8894();
    func_020d8894();
}

void func_020d8b34(void) {
 extern M2C_UNK data_0212c260; extern M2C_UNK data_0212c264; extern M2C_UNK data_0215d9b8;
 s32 func_020d886c();
 void (*callback)(void);
 u16 value;
 callback=M2C_FIELD((u8 *)&data_0212c260+func_020d886c()*8,void (**)(void),0);
 value=M2C_FIELD((u8 *)&data_0212c264+func_020d886c()*8,u32 *,0);
 M2C_FIELD(&data_0215d9b8,u16 *,6)=(M2C_FIELD(&data_0215d9b8,u16 *,6)&~15)|(value&15);
 callback();
}

s32 func_020d8b84(s32 arg0) {
    s32 func_020be120();
    M2C_UNK func_020be324(M2C_UNK, s32);
    func_020be120();
    if (arg0 != 1) {
        return 1;
    }
    func_020be324(8, func_020be120());
    return 1;
}

