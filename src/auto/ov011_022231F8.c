/* 3 functions from 0x022231F8 to 0x02223CB8 (ov011), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
extern u16 gIntroRevealedTiles[];
extern u16 gIntroStateDurations[];
extern u8 data_02101f5c[],gSpriteDesc64x8[];
extern DS3DSpriteTransform data_ov011_02227f28;
extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;

/* Reveals the intro tile strip one tile at a time, fading the current tile in and
 * sliding it vertically toward y=48, then submits both halves of every revealed
 * tile to the sprite engine. `tileCount` bit 0x80 means "highlight all revealed
 * tiles" with the total in the low bits; `position` bit 0x8000 means a fixed y. */
s32 G3_UpdateIntroTiles(u8 *entry,u8 tileCount,s32 duration,u16 position,u8 *tileOffsets){
s32 EaseInterpolate(s32,s32,s32,u16,s32);void AddSpriteToMainEngine(s32,u16,u16,void *,s32);s32 GetLanguage(void);
extern u16 gIntroAnimState[];
u16 tileAttr[5]={0,0,0,0,0};
u16 *volatile v0;
u16 *volatile v1;
u16 *volatile v2;
u16 *volatile v3;
u16 *volatile v4;
u16 *volatile v5;
u16 *volatile v6;
u16 *volatile v7;
u16 *volatile v8;
u16 *volatile v9;
u16 *volatile v10;
u16 *volatile v11;
u16 *volatile v12;
u8 tileIndex;s32 tileNum; s32 baseY;u8 revealIndex; s16 blend;void *savedEngine;u16 limit;u8 state;
if(duration==0){gIntroAnimState[3]=0;gIntroRevealedTiles[0]=1;if(tileCount==0)gIntroAnimState[5]=0;return 0;}
if(duration==32767 && (tileCount&128)){gIntroRevealedTiles[0]=tileCount-128;}
else{
if(duration==2047)blend=16;else if(duration==32767)blend=0;else if(duration>=0)blend=EaseInterpolate(0,16,0,gIntroAnimState[3],duration);else blend=EaseInterpolate(0,0,16,gIntroAnimState[3],-duration);
savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
v0=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v0=(*v0&~1);
v1=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v1=(*v1&~2);
v2=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v2=(*v2&~4);
v3=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v3=(*v3&~8);
v4=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v4=(*v4&~16);
v5=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v5=(*v5&~32);
v6=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v6=(*v6|256);
v7=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v7=(*v7|512);
v8=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v8=(*v8|1024);
v9=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v9=(*v9|2048);
v10=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v10=(*v10|4096);
v11=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v11=(*v11|8192);
v12=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+18);*v12=(*v12&~192)|64;

M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,81)=16-blend;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,82)=blend;
gCur3DSpriteEngine=savedEngine;
if(tileCount&128){gIntroRevealedTiles[0]=tileCount-128;limit=gIntroRevealedTiles[0];for(revealIndex=0;revealIndex<limit;revealIndex++)tileAttr[revealIndex]=1024;}
else tileAttr[gIntroRevealedTiles[0]-1]=1024;
}
if(position&32768)position-=32768;
else{state=entry[57];if(state%2)state--;limit=gIntroStateDurations[state];position=EaseInterpolate(0,position,48,gIntroAnimState[5],limit);if(gIntroAnimState[5]<limit)gIntroAnimState[5]++;}
for(tileIndex=0;tileIndex<gIntroRevealedTiles[0];tileIndex++){
baseY=position+tileIndex*18;tileNum=tileIndex*64;
AddSpriteToMainEngine(0,tileAttr[tileIndex]|((baseY+tileOffsets[tileIndex])&255),(tileNum)&1023,data_02101f5c,0);
AddSpriteToMainEngine(128,tileAttr[tileIndex]|((baseY+tileOffsets[tileIndex])&255),(tileNum+32)&1023,data_02101f5c,0);
if(GetLanguage()==4 && entry[57]>=8)AddSpriteToMainEngine(0,tileAttr[0]|74,128,gSpriteDesc64x8,0);
}
gIntroAnimState[3]++;
if(gIntroAnimState[3]>(duration&32767)){
revealIndex=0;gIntroAnimState[3]=revealIndex;gIntroRevealedTiles[0]++;
if(gIntroRevealedTiles[0]>tileCount){gIntroRevealedTiles[0]=tileCount;if(duration>0)gIntroAnimState[3]=duration;else gIntroAnimState[3]=revealIndex;}
}
return 0;
}

void func_ov011_02223764(u8 *entry, s32 duration, s32 tileCount, u8 *tileOffsets)
{
    extern u16 gIntroAnimState[];
    s32 EaseInterpolate(s32, s32, s32, u16, s32);
    u16 *volatile flags0;
    u16 *volatile flags1;
    u16 *volatile flags2;
    u16 *volatile flags3;
    u16 *volatile flags4;
    u16 *volatile flags5;
    u16 *volatile flags6;
    u16 *volatile flags7;
    u16 *volatile flags8;
    u16 *volatile flags9;
    u16 *volatile flags10;
    u16 *volatile flags11;
    u16 *volatile flags12;
    u16 *volatile flags13;
    u16 *volatile flags14;
    u16 *volatile flags15;
    u16 *volatile flags16;
    s32 alpha;
    if (duration == 0) {
        void *savedEngine = gCur3DSpriteEngine;
        s32 screen = 0;
        do {
            gCur3DSpriteEngine = screen == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
            flags0 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags0 = *flags0 & ~0xC0;
            (*(DS3DSpriteBank **)gCur3DSpriteEngine)->rowsAbove = 0;
            (*(DS3DSpriteBank **)gCur3DSpriteEngine)->rowsBelow = 0;
            (*(DS3DSpriteBank **)gCur3DSpriteEngine)->filler_53 = 0;
        } while (++screen < 2);
        *(void *volatile *)&gCur3DSpriteEngine = savedEngine;
        ((volatile u16 *)gIntroAnimState)[2] = 0;
        return;
    }
    if (duration > 0)
        alpha = EaseInterpolate(0, 16, 0, ((volatile u16 *)gIntroAnimState)[2], duration);
    else {
        u16 time = ((volatile u16 *)gIntroAnimState)[2];
        alpha = EaseInterpolate(0, 0, 16, time, -duration);
    }
    if ((u8)alpha < 16) {
        void *savedEngine = gCur3DSpriteEngine;
        s32 screen = 0;
        do {
            gCur3DSpriteEngine = screen == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
            flags1 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags1 = (*flags1 & ~1) | 1;
            flags2 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags2 = *flags2 | 2;
            flags3 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags3 = *flags3 | 4;
            flags4 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags4 = *flags4 | 8;
            flags5 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags5 = *flags5 & ~0x10;
            flags6 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags6 = *flags6 & ~0x100;
            flags7 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags7 = *flags7 & ~0x200;
            flags8 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags8 = *flags8 & ~0x400;
            flags9 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags9 = *flags9 & ~0x800;
            flags10 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags10 = *flags10 & ~0x1000;
            flags11 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->oamAttr;
            *flags11 = (*flags11 & ~0xC0) | 0xC0;
            (*(DS3DSpriteBank **)gCur3DSpriteEngine)->rowsAbove = 0;
            (*(DS3DSpriteBank **)gCur3DSpriteEngine)->rowsBelow = 0;
            (*(DS3DSpriteBank **)gCur3DSpriteEngine)->filler_53 = alpha;
        } while (++screen < 2);
        gCur3DSpriteEngine = savedEngine;
    } else {
        void *savedEngine = gCur3DSpriteEngine;
        s32 screen = 0;
        do {
            gCur3DSpriteEngine = screen == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
            flags12 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->flags;
            *flags12 = *flags12 & ~0x10;
            flags13 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->flags;
            *flags13 = *flags13 & ~0x20;
            flags14 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->flags;
            *flags14 = *flags14 & ~0x40;
            flags15 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->flags;
            *flags15 = *flags15 & ~0x80;
            flags16 = &(*(DS3DSpriteBank **)gCur3DSpriteEngine)->flags;
            *flags16 = *flags16 | 0x100;
        } while (++screen < 2);
        gCur3DSpriteEngine = savedEngine;
    }
    tileCount |= 0x80;
    gIntroAnimState[2]++;
    G3_UpdateIntroTiles(entry, tileCount, 0x7FFF, (u16)0x80, tileOffsets);
}

/* Build the layer transform for bank matrix `matrix` (DS3D_MATRIX_A or
 * DS3D_MATRIX_B) on both 3D sprite engines from the shared default transform; a
 * nonzero `scale` (8.8 fixed point) replaces both axis scales. */
void G3_SetSpriteTransformScale(s32 unused,s32 scale,u32 matrix) {
void Build3DSpriteTransform(void*,void*);
DS3DSpriteTransform transform=data_ov011_02227f28;
void *saved,*engine; s32 i;
if(matrix<DS3D_MATRIX_A)return;
i=0;
if(scale==0){saved=gCur3DSpriteEngine;
do {
if(i==0)engine=g3DSpriteEngineMain;else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
switch(matrix){case DS3D_MATRIX_A:Build3DSpriteTransform(&transform,(u8*)*(void**)engine+0x14);break;case DS3D_MATRIX_B:Build3DSpriteTransform(&transform,(u8*)*(void**)engine+0x24);break;}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;return;}
transform.scaleY=scale;
transform.scaleX=transform.scaleY;
saved=gCur3DSpriteEngine;
do {
if(i==0)engine=g3DSpriteEngineMain;else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
switch(matrix){case DS3D_MATRIX_A:Build3DSpriteTransform(&transform,(u8*)*(void**)engine+0x14);break;case DS3D_MATRIX_B:Build3DSpriteTransform(&transform,(u8*)*(void**)engine+0x24);break;}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;
}
