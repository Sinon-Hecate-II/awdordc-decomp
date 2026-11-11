/* 28 functions from 0x020AF760 to 0x020B0658 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
typedef struct { s32 x,y,z; } VecAff;
typedef struct { u8 pad[4]; s32 unk4; } Unk020af860_Sub;
typedef struct { u8 pad[0x34]; Unk020af860_Sub *unk34; } Unk020af860_Unit;
typedef struct { Unk020af860_Unit *unk0; u8 pad[0x14]; } Unk020af860_Rec;
extern u8 data_02122d08[],data_021213e0[];
extern s32 gFrameCounter;

void func_020af760(void) {
M2C_UNK func_02090448(s32); extern M2C_UNK gPlayerSettings;
s32 i=0; u8 *p=(u8*)&gPlayerSettings;
do { s32 v=*M2C_FIELD(M2C_FIELD(p,void **,4),s32 **,0x34); if(v)func_02090448(v); i++; p+=0x18; }while(i<2);
}

void func_020af79c(void) {
    M2C_UNK func_02090480(M2C_UNK);
    func_02090480(0);
}

#pragma push
#pragma scheduling off
void func_020af7ac(void) {
extern u8 data_0215c430[],data_0215c42c[];
s32 i=0;u8 zero=i;volatile u8 *p=data_0215c430,*q=data_0215c42c;
do { *p++=zero; *q++=zero; } while(++i<2);
}
#pragma pop
void func_020af7dc(void) {
    extern u8 data_0215c42c[];
    extern u8 data_0215c430[];
    s32 var_r1;
    u8 *var_r2;
    u8 *var_r3;
    u8 temp_r0;
    u8 temp_r0_2;

    var_r2 = data_0215c430;
    var_r3 = data_0215c42c;
    var_r1 = 0;
    do {
        temp_r0 = *var_r2;
        var_r1 += 1;
        if (temp_r0 != 0) {
            *var_r2 = temp_r0 - 1;
        }
        temp_r0_2 = *var_r3;
        var_r2 += 1;
        if (temp_r0_2 != 0) {
            *var_r3 = temp_r0_2 - 1;
        }
        var_r3 += 1;
    } while (var_r1 < 2);
}

void func_020af828(s32 arg0, s32 arg1) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_0208ff94(M2C_UNK);
    if (arg1 == 0) {
        return;
    }
    PlaySoundEffect(arg1);
    if (arg0 == 0) {
        func_0208ff94(-0x80);
        return;
    }
    func_0208ff94(0x7F);
}

void func_020af860(s32 arg0, s32 arg1) {
    M2C_UNK func_0208ffe4(s32, s32, s32);
    M2C_UNK func_02090100(s32, s32);
    void func_020af8c8(s32, s32);
    extern M2C_UNK gEffectTable;
    s32 v = M2C_FIELD(M2C_FIELD(*(void **)((u8 *)&gEffectTable + arg0 * 0x18), void **, 0x34), s32 *, 4);
    if (v == 0) return;
    func_0208ffe4(arg0, -1, v);
    if (arg0 == 0) func_02090100(arg0, -0x80);
    else func_02090100(arg0, 0x7F);
    func_020af8c8(arg0, arg1);
}

void func_020af8c8(s32 arg0, s32 arg1) {
    M2C_UNK func_020900a4(s32, s32, M2C_UNK);
    M2C_UNK func_02090158(s32, u8, M2C_UNK);
    extern M2C_UNK data_02127ed8;
    extern M2C_UNK data_ov002_021f2f44;
    extern M2C_UNK gEffectTable;
    extern M2C_UNK data_ov002_021f314e;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r2;
    s32 var_r3;
    u8 temp_r0;
    void *temp_r1;

    temp_r1 = *(void **)((u8 *)&gEffectTable + (arg0 * 0x18));
    if (M2C_FIELD(M2C_FIELD(temp_r1, void **, 0x34), s32 *, 4) == 0) {
        return;
    }
    if (M2C_FIELD(temp_r1, u8 *, 0x3D) == 3) {
        var_r1 = 7;
    } else if (*((u8 *)&data_ov002_021f314e + (arg0 * 0x2C)) != 0 && arg1 != 0) {
        var_r1 = 7;
    } else if (arg1 <= 0) {
        var_r1 = 0;
    } else if (arg1 <= 1) {
        var_r1 = 1;
    } else if (arg1 <= 3) {
        var_r1 = 3;
    } else {
        var_r1 = 7;
    }
    func_020900a4(arg0, ~var_r1, 2);
    var_r2 = 5;
    if (*((u8 *)&data_ov002_021f314e + (arg0 * 0x2C)) != 0) {
        var_r2 = 0;
    } else {
        var_r3 = (arg0 * 0x68) + (s32) &data_ov002_021f2f44;
        var_r1_2 = 0;
        do {
            temp_r0 = M2C_FIELD(var_r3, u8 *, 0x12);
            var_r3 += 1;
            if ((s32) temp_r0 < arg1) {
                var_r2 = var_r1_2;
            }
            var_r1_2 += 1;
        } while (var_r1_2 < var_r2);
    }
    func_02090158(arg0, *((u8 *)&data_02127ed8 + var_r2), 0);
}

void func_020af9cc(s32 arg0,s32 arg1,s32 arg2) {
M2C_UNK func_02090034(s32,s32); extern M2C_UNK gEffectTable;
if(arg2==0 && M2C_FIELD(*(void **)((u8*)&gEffectTable+arg0*0x18),u8 *,0x3d)==3)return;
func_02090034(arg0,arg1);
}

void func_020afa00(s32 a){extern M2C_UNK gEffectTable;extern u8 gEffectDefaultVariant;extern u8 data_0215c430[];u32 n=*((u8 *)&gEffectDefaultVariant+a*24);void *p=*(void **)((u8 *)&gEffectTable+a*24);if(M2C_FIELD((u8 *)p+n,u8 *,0x3e)==1){if((data_0215c430)[a])return;(data_0215c430)[a]=4;}func_020af828(a,M2C_FIELD((u8 *)M2C_FIELD(p,void **,0x34)+n*4,s32 *,8));}

void func_020afa64(s32 a){extern M2C_UNK gEffectTable;s32 b;if(a==0)b=1;else b=0;func_020af828(a,M2C_FIELD(M2C_FIELD(*(void **)((u8 *)&gEffectTable+b*24),void **,0x34),s32 *,0x10));}

void func_020afa98(s32 a){extern M2C_UNK gEffectTable;extern u8 gEffectDefaultVariant;extern u8 data_0215c42c[];s32 n;if(M2C_FIELD((u8 *)*(void **)((u8 *)&gEffectTable+(a==0?1:0)*24)+*((u8 *)&gEffectDefaultVariant+(a==0?1:0)*24),u8 *,0x3e)==1){if((data_0215c42c)[a])return;(data_0215c42c)[a]=4;n=1;}else n=0;func_020af828(a,M2C_FIELD((u8 *)M2C_FIELD(*(void **)((u8 *)&gEffectTable+a*24),void **,0x34)+n*4,s32 *,0x14));}

void func_020afb34(s32 a){extern M2C_UNK gEffectTable;switch(M2C_FIELD(*(void **)((u8 *)&gEffectTable+a*24),u8 *,0x3d)){case 2:func_020af828(a,0x2000b);return;case 3:func_020af828(a,0x2000c);return;default:func_020af828(a,0x2000a);return;}}

void func_020afb94(s32 arg0) {
extern M2C_UNK gEffectTable;
void func_020afb34(s32);
s32 v=M2C_FIELD(M2C_FIELD(*(void **)((u8*)&gEffectTable+arg0*24),void **,0x34),s32 *,0x1c);
if(v){func_020af828(arg0,v);return;}func_020afb34(arg0);
}

void func_020afbcc(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_020afbe8(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
}

void func_020afc04(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
}

void func_020afc20(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
}

void func_020afc3c(void) {

}

void func_020afc40(void) {

}

void func_020afc44(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4, s32 arg5, s32 arg6) {
    void func_0209107c(void *, s32, s32, VecAff *, s32, s32, s32, s32, s32);
    extern s32 gFrameCounter;
    volatile s32 sp30;
    volatile s32 sp2C;
    volatile s32 sp28;
    volatile s32 sp24;
    volatile s32 sp20;
    volatile s32 sp1C;
    volatile s32 sp18;
    volatile s32 sp14;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 var_r11;
    s32 var_r11_2;
    s32 var_r11_3;
    s32 var_r11_4;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r4_4;

    temp_r4 = arg0 * 0x30;
    sp14 = arg0;
    sp2C = (arg1 - (arg2 * 0x10)) * 0x30;
    sp30 = 0x8A1;
    sp28 = temp_r4;
    func_0209107c(arg3, 0x14, gFrameCounter, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
    sp2C = (arg1 + (arg2 * 0x10)) * 0x30;
    sp28 = temp_r4;
    func_0209107c(arg3, 0x15, gFrameCounter, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
    temp_r4_2 = arg1 * 0x30;
    sp28 = (sp14 - (arg2 * 0x10)) * 0x30;
    sp2C = temp_r4_2;
    func_0209107c(arg3, 0x16, gFrameCounter, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
    sp2C = temp_r4_2;
    sp28 = (sp14 + (arg2 * 0x10)) * 0x30;
    func_0209107c(arg3, 0x17, gFrameCounter, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
    temp_r0 = arg2 - 1;
    var_r11 = 1;
    sp18 = temp_r0;
    if (temp_r0 >= 1) {
        var_r4 = 0x10;
        do {
            sp28 = (sp14 - var_r4) * 0x30;
            sp2C = (arg1 - ((arg2 - var_r11) * 0x10)) * 0x30;
            func_0209107c(arg3, 0x18, gFrameCounter, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
            var_r11 += 1;
            var_r4 += 0x10;
        } while (var_r11 <= sp18);
    }
    temp_r0_2 = arg2 - 1;
    sp1C = temp_r0_2;
    var_r4_2 = 1;
    if (temp_r0_2 >= 1) {
        var_r11_2 = sp14 + 0x10;
        do {
            sp28 = var_r11_2 * 0x30;
            sp2C = (arg1 - ((arg2 - var_r4_2) * 0x10)) * 0x30;
            func_0209107c(arg3, 0x19, gFrameCounter, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
            var_r4_2 += 1;
            var_r11_2 += 0x10;
        } while (var_r4_2 <= sp1C);
    }
    temp_r0_3 = arg2 - 1;
    sp20 = temp_r0_3;
    var_r4_3 = 1;
    if (temp_r0_3 >= 1) {
        var_r11_3 = 0x10;
        do {
            sp28 = (sp14 - var_r11_3) * 0x30;
            sp2C = (arg1 + ((arg2 - var_r4_3) * 0x10)) * 0x30;
            func_0209107c(arg3, 0x1A, gFrameCounter, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
            var_r4_3 += 1;
            var_r11_3 += 0x10;
        } while (var_r4_3 <= sp20);
    }
    temp_r0_4 = arg2 - 1;
    sp24 = temp_r0_4;
    var_r4_4 = 1;
    if (temp_r0_4 < 1) {
        return;
    }
    var_r11_4 = sp14 + 0x10;
    do {
        sp28 = var_r11_4 * 0x30;
        sp2C = (arg1 + ((arg2 - var_r4_4) * 0x10)) * 0x30;
        func_0209107c(arg3, 0x1B, gFrameCounter, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
        var_r4_4 += 1;
        var_r11_4 += 0x10;
    } while (var_r4_4 <= sp24);
}

void func_020affac(s32 x,s32 y){
s32 func_0207b9f4(s32,s32);
s32 GetViewZoom(s32);
void func_02091248(s32);
void func_020afc44(s32,s32,s32,void *,s32,s32,s32);
void func_0209107c(void *,s32,s32,VecAff *,s32,s32,s32,s32,s32);
extern s32 *gCurrentMap;
VecAff v;
s32 c;void *b;s32 a; s32 n; s32 mode;
n=func_0207b9f4(x+8,y+8);
mode=GetViewZoom(*gCurrentMap+0x6ef8)<=0?16:24;
if(mode==16){a=0x21000;b=data_021213e0;c=0x30000;}
else {a=0x21980;b=data_02122d08;c=0x20000;}
func_02091248(31);
if(n>19){func_020afc44(x+8,y+8,n-19,b,a,0x1440,c);return;}
v.x=(x+8)*48;v.y=(y+8)*48;v.z=0x8a1;
func_0209107c(b,n,gFrameCounter,&v,a,0x1440,c,0,0);
}

void func_020b00c0(void) {
    M2C_UNK func_0207ce54(s32);
    extern s32 *gCurrentMap;
    func_0207ce54(*gCurrentMap + 0x6EF8);
}

void func_020b00e4(void) {

}

void func_020b00e8(void) {

}

void Set3DSpriteLayerModesAlt(void) { extern void *gCur3DSpriteEngine;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)&~3)|3;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)&~3)|0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)&~3)|1;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)&~3)|2;
}

void Set3DSpriteLayerModes(void) { extern void *gCur3DSpriteEngine;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)&~3)|1;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)&~3)|0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)&~3)|2;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)&~3)|3;
}

/* Configure the current 3D sprite engine for a map view: set the four layer
   modes, pick the bank's split rows from the map's tileset setting, then force
   the OAM attribute bits and restart the engine. */
void Configure3DSpriteMapView(void) {
    void Set3DSpriteLayerModes(void);
    void Reset3DSpriteEngineState(void);
    extern s32 *gCurrentMap;
    extern void *gCur3DSpriteEngine;
    u16 *volatile oamC0;
    u16 *volatile oam1;
    u16 *volatile oam2;
    u16 *volatile oam4;
    u16 *volatile oam8;
    u16 *volatile oam10;
    u16 *volatile oam20;
    u16 *volatile oam100;
    u16 *volatile oam200;
    u16 *volatile oam400;
    u16 *volatile oam800;
    u16 *volatile oam1000;
    u16 *volatile oam2000;
    u8 splitAbove;
    u8 splitBelow;
    u8 zero = 0;

    Set3DSpriteLayerModes();
    if (M2C_FIELD(*gCurrentMap, u8 *, MAP_TILESET) == 1) {
        splitAbove = 0xa;
        splitBelow = 0x8;
    } else {
        splitAbove = 0xc;
        splitBelow = 0x8;
    }
    oamC0 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oamC0 = (*oamC0 & ~0xc0) | 0x40;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->rowsAbove = splitAbove;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->rowsBelow = splitBelow;
    ((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->filler_53 = zero;
    oam1 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam1 = (*oam1 & ~1) | 1;
    oam2 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam2 = *oam2 & ~2;
    oam4 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam4 = *oam4 & ~4;
    oam8 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam8 = *oam8 & ~8;
    oam10 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam10 = *oam10 & ~0x10;
    oam20 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam20 = *oam20 & ~0x20;
    oam100 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam100 = *oam100 & ~0x100;
    oam200 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam200 = *oam200 & ~0x200;
    oam400 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam400 = *oam400 | 0x400;
    oam800 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam800 = *oam800 | 0x800;
    oam1000 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam1000 = *oam1000 | 0x1000;
    oam2000 = &((DS3DSpriteBank *)((DS3DSpriteEngine *)gCur3DSpriteEngine)->bank)->oamAttr;
    *oam2000 = *oam2000 | 0x2000;
    Reset3DSpriteEngineState();
}

/* Configure the 3D sprite engine for a map view: set the per-layer 2-bit
 * rotation modes (layers 0-3 to 1/0/2/3 via Set3DSpriteLayerModes), pick the two
 * layer-scope bytes by the map's 0x5157 mode flag, then update the engine's
 * flag word at +0x12 (layer 3 enabled, all layer-select/enable bits cleared,
 * the high mode bits 0x400-0x2000 set) before resetting the engine state. */
void func_020b0408(void) {
    void Set3DSpriteLayerModes(void);
    void Reset3DSpriteEngineState(void);
    extern s32 *gCurrentMap;
    extern void *gCur3DSpriteEngine;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    u16 *volatile sp0;
    u8 v51;
    u8 v52;
    u8 v0 = 0;

    Set3DSpriteLayerModes();
    if (*(u8 *)((s32)*gCurrentMap + 0x5157) == 1) {
        v51 = 0xa;
        v52 = 0x8;
    } else {
        v51 = 0x6;
        v52 = 0x10;
    }
    sp30 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp30 = (*sp30 & ~0xc0) | 0x40;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = v51;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = v52;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x53) = v0;
    sp2C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp2C = (*sp2C & ~1) | 1;
    sp28 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp28 = *sp28 & ~2;
    sp24 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp24 = *sp24 & ~4;
    sp20 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp20 = *sp20 & ~8;
    sp1C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp1C = *sp1C & ~0x10;
    sp18 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp18 = *sp18 & ~0x20;
    sp14 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp14 = *sp14 & ~0x100;
    sp10 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp10 = *sp10 & ~0x200;
    spC = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *spC = *spC | 0x400;
    sp8 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp8 = *sp8 | 0x800;
    sp4 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp4 = *sp4 | 0x1000;
    sp0 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp0 = *sp0 | 0x2000;
    Reset3DSpriteEngineState();
}

