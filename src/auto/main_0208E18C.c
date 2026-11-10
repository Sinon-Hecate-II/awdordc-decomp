/* 16 functions from 0x0208E18C to 0x0208EE90 (main), found by ds-decomp. */
#include "common.h"

typedef struct { s32 a; s32 b; } Pair;
typedef struct { u8 pad[0x60]; u64 v; u64 *p; } UnkNode0208EE1C;


void func_0208e18c(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    void AddSprite(u16, u16, u16, void *, u8);
    s32 func_0207c8ec(s32, s32);
    void DrawVerticalBar(s32, s16, s16, u16);
    void DrawVerticalBarReverse(s16, s16, s16, u16);
    void DrawHorizontalBar(s16, s32, s16, u16);
    void DrawHorizontalBarReverse(s16, s16, s16, u16);
    void SetSpriteQuad(s32, s16, s16, s16, s16);
    extern s32 gCur3DSpriteEngine;
    extern u32 data_020f35c8[];
    extern u8 gSpriteDesc8x8[];
    extern s16 gSinCosTable[];
    s32 tbl[25];
    s32 i;
    s32 v4, v8, vc, v10, v14, v18, v1c, v20, v38, v3c;
    s32 sh, r4, r5, r6, r7, r11;

    for (i = 0; i < 25; i++) tbl[i] = data_020f35c8[i];

    sh = (u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30;
    r7 = a0 & 0x3ff;
    r4 = a1 & 0xff;
    AddSprite((u16)r7, (u8)r4, (u16)(a4 + ((0x54 >> sh) & 0x3ff)), gSpriteDesc8x8, (u8)a5);

    v8 = a0 + a2 - 8;
    r4 = v8 & 0x1ff;
    sh = (u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30;
    AddSprite((u16)r4, (u8)a1, (u16)(a4 + ((0x56 >> sh) & 0x3ff)), gSpriteDesc8x8, (u8)a5);

    vc = a1 + a3 - 8;
    r7 = vc & 0xff;
    sh = (u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30;
    AddSprite((u16)(a0 & 0x3ff), (u8)r7, (u16)(a4 + ((0x58 >> sh) & 0x3ff)), gSpriteDesc8x8, (u8)a5);

    sh = (u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30;
    AddSprite((u16)r4, (u8)r7, (u16)(a4 + ((0x5a >> sh) & 0x3ff)), gSpriteDesc8x8, (u8)a5);

    sh = (u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30;
    DrawVerticalBar(a0, (s16)(a1 + 8), (s16)(a3 - 16), (u16)(a4 + ((0x4a >> sh) & 0x3ff)));

    sh = (u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30;
    DrawVerticalBarReverse((s16)v8, (s16)(a1 + 8), (s16)(a3 - 16), (u16)(a4 + ((0x4a >> sh) & 0x3ff)));

    sh = (u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30;
    DrawHorizontalBar((s16)(a0 + 8), a1, (s16)(a2 - 16), (u16)(a4 + ((0x40 >> sh) & 0x3ff)));

    sh = (u32)(M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0) << 17) >> 30;
    DrawHorizontalBarReverse((s16)(a0 + 8), (s16)vc, (s16)(a2 - 16), (u16)(a4 + ((0x40 >> sh) & 0x3ff)));

    v1c = (s16)(a3 - 16);
    v20 = (s16)(a1 + 8);
    v4 = (s16)(a2 - 16);

    if (!(v4 < 0x40 && v1c < 0x40)) {
        s16 d0 = gSinCosTable[0];
        s16 d1 = gSinCosTable[1];
        s32 x5 = d1 << 4;
        s32 x7 = (-d0) << 4;
        s32 x6 = d0 << 4;
        s32 c1 = func_0207c8ec(x5, 0x200);
        s32 c2 = func_0207c8ec(x7, 0x100);
        s32 c3 = func_0207c8ec(x6, 0x200);
        s32 c4 = func_0207c8ec(x5, 0x100);
        SetSpriteQuad(0x1c, (s16)c1, (s16)c2, (s16)c3, (s16)c4);
        c1 = func_0207c8ec(x5, 0x100);
        c2 = func_0207c8ec(x7, 0x200);
        c3 = func_0207c8ec(x6, 0x100);
        c4 = func_0207c8ec(x5, 0x200);
        SetSpriteQuad(0x1b, (s16)c1, (s16)c2, (s16)c3, (s16)c4);
        c1 = func_0207c8ec(x5, 0x200);
        c2 = func_0207c8ec(x7, 0x200);
        c3 = func_0207c8ec(x6, 0x200);
        c4 = func_0207c8ec(x5, 0x200);
        SetSpriteQuad(0x1f, (s16)c1, (s16)c2, (s16)c3, (s16)c4);
    }

    v10 = (s16)(a0 + 8);
    v18 = 0;
    r4 = 0x80;

    while (v18 < 5) {
        if (v1c >= r4) {
            v14 = v4;
            v3c = (u16)(v20 & 0xff);
            r11 = (u16)((v20 & 0xff) | 0x300);
            v38 = (u16)(((v20 - (r4 >> 1)) & 0xff) | 0x300);
            r5 = v10;
            r6 = 0x80;
            r7 = 0;
            while (r7 < 5) {
                while (v14 >= r6) {
                    if (r6 >= 0x40 && r4 >= 0x40) {
                        AddSprite((u16)((r5 & 0x1ff) | 0x3e00), (u16)r11, (u16)a4, (void *)tbl[r7], (u8)a5);
                    } else if (r6 >= 0x40) {
                        AddSprite((u16)((r5 & 0x1ff) | 0x3800), (u16)v38, (u16)a4, (void *)tbl[r7], (u8)a5);
                    } else if (r4 >= 0x40) {
                        AddSprite((u16)(((r5 - (r6 >> 1)) & 0x1ff) | 0x3600), (u16)r11, (u16)a4, (void *)tbl[r7], (u8)a5);
                    } else {
                        AddSprite((u16)((r5 & 0x1ff)), (u16)v3c, (u16)a4, (void *)tbl[r7], (u8)a5);
                    }
                    r5 += r6;
                    v14 -= r6;
                }
                r6 >>= 1;
                r7++;
            }
            v1c -= r4;
            v20 += r4;
            if (v1c >= r4) continue;
        }
        r4 >>= 1;
        v18++;
    }
}

void func_0208e7ec(u32 arg0,s32 arg1) { extern u8 data_02102888[],data_02102898[],data_021028a4[],data_021028b0[]; extern s32 gCur3DSpriteEngine; void *p; SetFileDirectory(data_02102888); func_020814e4(data_02102898); func_02081590(data_021028a4,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+arg0); func_020815fc(data_021028b0,(arg1+16)<<5,32); func_02081528(); p=(void *)gCur3DSpriteEngine; M2C_FIELD(p,u8 *,0x46)|=16; }

/* Draw a minutes:centiseconds readout with AddSprite digits at (x, y). */
void DrawTimerDigits(s16 x, s32 y, u16 baseTile, u8 priority, s32 value) {
s32 func_0207c8ec(s32,s32);
void AddSprite(u16,u16,u16,void *,u8);
extern s32 gCur3DSpriteEngine;
extern u8 gSpriteDesc16x8[],gSpriteDesc8x8[];
s32 minutes,centis;
u16 sy;
const s32 mask=0x3ff;
minutes=func_0207c8ec(value,60);
centis=func_0207c8ec((value%60)*100,60);
if(value<600)baseTile+=(32>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask;
sy=(u16)y;
AddSprite((u16)x,sy,(u16)(baseTile+((22>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),gSpriteDesc16x8,priority);
x+=48;
AddSprite((u16)x,sy,(u16)(baseTile+(((centis%10)*2>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),gSpriteDesc8x8,priority);
x-=8;
centis=func_0207c8ec(centis,10);
AddSprite((u16)x,sy,(u16)(baseTile+(((centis%10)*2>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),gSpriteDesc8x8,priority);
x-=8;
AddSprite((u16)x,sy,(u16)(baseTile+((20>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),gSpriteDesc8x8,priority);
x-=8;
do{
AddSprite((u16)x,sy,(u16)(baseTile+(((minutes%10)*2>>(((u32)M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0)<<17)>>30))&mask)),gSpriteDesc8x8,priority);
minutes=func_0207c8ec(minutes,10);
x-=8;
}while(minutes!=0);
}

void func_0208eb30(void *arg0, u32 arg1, s32 arg2) {

    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg1 >> 5);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg2 << 0x18) >> 6));
    func_0208e7ec(arg1, arg2);
}

void func_0208eb60(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x58) = arg1;
}

u8 func_0208eb68(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s32 *, 0x58) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0208eb80(void *p) {
extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub,g3DSpriteEngineMain;
void DrawTimerDigits(s16,s32,u16,u8,s32);
s32 saved,bank,i,clamped;
u32 mode,shift;
u16 pal,base,tile,bankVal;
void **bankPtr;
if(M2C_FIELD(p,s32 *,0x58)>0)M2C_FIELD(p,s32 *,0x58)--;
if(M2C_FIELD(p,s32 *,0x58)<0)M2C_FIELD(p,s32 *,0x58)=0;
saved=gCur3DSpriteEngine;
for(i=0;i<2;i++){
if(i==0)bank=g3DSpriteEngineMain;else bank=g3DSpriteEngineSub;
gCur3DSpriteEngine=bank;
mode=(u32)(M2C_FIELD(p,u8 *,0x48)<<28)>>29;
if((mode!=0||bank==g3DSpriteEngineMain)&&(mode!=1||bank==g3DSpriteEngineSub)&&(mode!=3||bank==saved)){
bankPtr=(void **)bank;
bankVal=M2C_FIELD(bankPtr,u16 *,0);
shift=(((u32)bankVal)<<17)>>30;
pal=(u16)((u32)(M2C_FIELD(p,u32 *,0x40)<<6)>>24);
base=M2C_FIELD(p,u16 *,0x3c);
tile=M2C_FIELD(p,u16 *,0x3e);
clamped=M2C_FIELD(p,s32 *,0x58);
DrawTimerDigits((s16)((M2C_FIELD(p,s16 *,0x34)+M2C_FIELD(p,s16 *,0x38))&511),
(M2C_FIELD(p,s16 *,0x36)+M2C_FIELD(p,s16 *,0x3a))&255,
(u16)(base|((u16)(pal<<12))|(((u32)tile>>shift)&1023)),
M2C_FIELD(p,u8 *,0x49),clamped);
}}
gCur3DSpriteEngine=saved;
}

void *func_0208ecc0(void *arg0) { M2C_UNK func_02089108(); extern M2C_UNK data_021025d4; extern s32 g3DSpriteEngineMain,gCur3DSpriteEngine; u8 var_r0,var_r0_2; func_02089108(); M2C_FIELD(arg0,M2C_UNK **,0)=&data_021025d4; if(gCur3DSpriteEngine==g3DSpriteEngineMain)var_r0=1;else var_r0=0; if(var_r0!=1)var_r0_2=1;else var_r0_2=0; M2C_FIELD(arg0,u8 *,0x48)=(u8)((M2C_FIELD(arg0,u8 *,0x48)&~0xE)|((u32)(var_r0_2<<29)>>28)); M2C_FIELD(arg0,s16 *,0x34)=0; M2C_FIELD(arg0,s16 *,0x36)=0; M2C_FIELD(arg0,s32 *,0x58)=0; M2C_FIELD(arg0,s16 *,0x3c)=0; return arg0; }

void func_0208ed40(void) {

}

s32 func_0208ed44(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_0208ed58(void *p){func_0208eb80(p);}

void func_0208ed64(M2C_UNK arg0) {
    s32 func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_0208ecc0();
    extern M2C_UNK data_021026b8;
    if (func_01ffa3dc(&data_021026b8, arg0) == 0) {
        return;
    }
    func_0208ecc0();
}

void *func_0208ed88(void *arg0) {
    M2C_UNK func_02089108();
    extern M2C_UNK data_02102624;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    u8 var_r0;
    u8 var_r0_2;

    func_02089108();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_02102624;
    if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 1) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    M2C_FIELD(arg0, u8 *, 0x48) = (u8) ((M2C_FIELD(arg0, u8 *, 0x48) & ~0xE) | ((u32) (var_r0_2 << 0x1D) >> 0x1C));
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0;
    M2C_FIELD(arg0, s16 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 9;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 0x68) = 0;
    return arg0;
}

#pragma opt_propagation off
void *func_0208ee1c(void *arg0) {
    unsigned long long *p = M2C_FIELD(arg0, unsigned long long **, 0x68);
    if (p != 0) {
        *p = M2C_FIELD(arg0, unsigned long long *, 0x60);
    }
    return arg0;
}
#pragma opt_propagation reset
void *func_0208ee34(void *arg0) { void *p=M2C_FIELD(arg0,void **,0x68); if(p) *(u64 *)p=M2C_FIELD(arg0,u64 *,0x60); MemFree(arg0); return arg0; }

#pragma opt_propagation reset
void func_0208ee60(void *arg0, u32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg1 >> 5);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg2 << 0x18) >> 6));
    func_0208e7ec(arg1, arg2);
}

