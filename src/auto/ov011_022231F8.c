/* 3 functions from 0x022231F8 to 0x02223CB8 (ov011), found by ds-decomp. */
#include "common.h"
extern u16 gIntroRevealedTiles[];
extern u16 gIntroStateDurations[];
extern u8 data_02101f5c[],data_02101f0c[];
typedef struct { s32 words[5]; } ContextTemplate;
extern ContextTemplate data_ov011_02227f28;
extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;

/* Reveals the intro tile strip one tile at a time, fading the current tile in and
 * sliding it vertically toward y=48, then submits both halves of every revealed
 * tile to the sprite engine. `tileCount` bit 0x80 means "highlight all revealed
 * tiles" with the total in the low bits; `position` bit 0x8000 means a fixed y. */
s32 G3_UpdateIntroTiles(u8 *entry,u8 tileCount,s32 duration,u16 position,u8 *tileOffsets){
s32 EaseInterpolate(s32,s32,s32,u16,s32);void func_01ffac9c(s32,u16,u16,void *,s32);s32 func_020e31e0(void);
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
func_01ffac9c(0,tileAttr[tileIndex]|((baseY+tileOffsets[tileIndex])&255),(tileNum)&1023,data_02101f5c,0);
func_01ffac9c(128,tileAttr[tileIndex]|((baseY+tileOffsets[tileIndex])&255),(tileNum+32)&1023,data_02101f5c,0);
if(func_020e31e0()==4 && entry[57]>=8)func_01ffac9c(0,tileAttr[0]|74,128,data_02101f0c,0);
}
gIntroAnimState[3]++;
if(gIntroAnimState[3]>(duration&32767)){
revealIndex=0;gIntroAnimState[3]=revealIndex;gIntroRevealedTiles[0]++;
if(gIntroRevealedTiles[0]>tileCount){gIntroRevealedTiles[0]=tileCount;if(duration>0)gIntroAnimState[3]=duration;else gIntroAnimState[3]=revealIndex;}
}
return 0;
}

void func_ov011_02223764(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 EaseInterpolate(M2C_UNK, M2C_UNK, M2C_UNK, u16, s32);
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    extern void *data_027e01d8;
    extern u16 gIntroAnimState[];
    u16 *sp44 = 0;
    u16 *sp40 = 0;
    u16 *sp3C = 0;
    u16 *sp38 = 0;
    u16 *sp34 = 0;
    u16 *sp30 = 0;
    u16 *sp2C = 0;
    u16 *sp28 = 0;
    u16 *sp24 = 0;
    u16 *sp20 = 0;
    u16 *sp1C = 0;
    u16 *sp18 = 0;
    u16 *sp14 = 0;
    u16 *sp10 = 0;
    u16 *spC = 0;
    u16 *sp8 = 0;
    u16 *sp4 = 0;
    s32 temp_z = 0;
    s32 temp_z_2 = 0;
    s32 var_r1 = 0;
    s32 var_r2 = 0;
    s32 var_r2_2 = 0;
    void *temp_r0 = 0;
    void *temp_r1 = 0;
    void *temp_r1_2 = 0;
    void **var_r6 = 0;
    void **var_r7 = 0;
    void **var_r8 = 0;
    u16 *temp_r6 = 0;
    u16 *temp_r7 = 0;
    u16 *temp_r7_2 = 0;
    u16 *temp_r7_3 = 0;
    u16 *temp_r7_4 = 0;
    u16 *temp_r7_5 = 0;
    u16 *temp_r8 = 0;
    u16 *temp_r8_10 = 0;
    u16 *temp_r8_11 = 0;
    u16 *temp_r8_2 = 0;
    u16 *temp_r8_3 = 0;
    u16 *temp_r8_4 = 0;
    u16 *temp_r8_5 = 0;
    u16 *temp_r8_6 = 0;
    u16 *temp_r8_7 = 0;
    u16 *temp_r8_8 = 0;
    u16 *temp_r8_9 = 0;
    u8 var_r0 = 0;

    if (arg1 == 0) {
        var_r2 = 0;
        temp_r1 = data_027e01d8;
        do {
            temp_z = var_r2 == 0;
            var_r2 += 1;
            if (temp_z) {
                var_r6 = (void**)g3DSpriteEngineMain;
            } else {
                var_r6 = (void**)g3DSpriteEngineSub;
            }
            data_027e01d8 = var_r6;
            temp_r6 = *var_r6;
            sp44 = temp_r6 + 0x12;
            M2C_FIELD(temp_r6, s16 *, 0x12) = (s16) (*sp44 & ~0xC0);
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x51) = 0;
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x52) = 0;
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x53) = 0;
        } while (var_r2 < 2);
        data_027e01d8 = temp_r1;
        M2C_FIELD(&gIntroAnimState, u16 *, 4) = 0U;
        return;
    }
    if (arg1 > 0) {
        var_r0 = EaseInterpolate(0, 0x10, 0, M2C_FIELD(&gIntroAnimState, u16 *, 4), arg1);
    } else {
        var_r0 = EaseInterpolate(0, 0, 0x10, M2C_FIELD(&gIntroAnimState, u16 *, 4), 0 - arg1);
    }
    if ((u32) var_r0 < 0x10U) {
        var_r2_2 = 0;
        temp_r1_2 = data_027e01d8;
        do {
            if (var_r2_2 == 0) {
                var_r8 = (void**)g3DSpriteEngineMain;
            } else {
                var_r8 = (void**)g3DSpriteEngineSub;
            }
            data_027e01d8 = var_r8;
            temp_r8 = *var_r8;
            sp40 = temp_r8 + 0x12;
            M2C_FIELD(temp_r8, s16 *, 0x12) = (s16) ((*sp40 & ~1) | 1);
            temp_r8_2 = *(void**)data_027e01d8;
            sp3C = temp_r8_2 + 0x12;
            M2C_FIELD(temp_r8_2, s16 *, 0x12) = (s16) (*sp3C | 2);
            temp_r8_3 = *(void**)data_027e01d8;
            sp38 = temp_r8_3 + 0x12;
            M2C_FIELD(temp_r8_3, s16 *, 0x12) = (s16) (*sp38 | 4);
            temp_r8_4 = *(void**)data_027e01d8;
            sp34 = temp_r8_4 + 0x12;
            M2C_FIELD(temp_r8_4, s16 *, 0x12) = (s16) (*sp34 | 8);
            temp_r8_5 = *(void**)data_027e01d8;
            sp30 = temp_r8_5 + 0x12;
            M2C_FIELD(temp_r8_5, s16 *, 0x12) = (s16) (*sp30 & ~0x10);
            temp_r8_6 = *(void**)data_027e01d8;
            sp2C = temp_r8_6 + 0x12;
            M2C_FIELD(temp_r8_6, s16 *, 0x12) = (s16) (*sp2C & ~0x100);
            temp_r8_7 = *(void**)data_027e01d8;
            sp28 = temp_r8_7 + 0x12;
            M2C_FIELD(temp_r8_7, s16 *, 0x12) = (s16) (*sp28 & ~0x200);
            temp_r8_8 = *(void**)data_027e01d8;
            sp24 = temp_r8_8 + 0x12;
            M2C_FIELD(temp_r8_8, s16 *, 0x12) = (s16) (*sp24 & ~0x400);
            temp_r8_9 = *(void**)data_027e01d8;
            sp20 = temp_r8_9 + 0x12;
            M2C_FIELD(temp_r8_9, s16 *, 0x12) = (s16) (*sp20 & ~0x800);
            temp_r8_10 = *(void**)data_027e01d8;
            sp1C = temp_r8_10 + 0x12;
            M2C_FIELD(temp_r8_10, s16 *, 0x12) = (s16) (*sp1C & ~0x1000);
            var_r2_2 += 1;
            temp_r8_11 = *(void**)data_027e01d8;
            sp18 = temp_r8_11 + 0x12;
            M2C_FIELD(temp_r8_11, s16 *, 0x12) = (s16) ((*sp18 & ~0xC0) | 0xC0);
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x51) = 0;
            M2C_FIELD(*(void**)data_027e01d8, s8 *, 0x52) = 0;
            M2C_FIELD(*(void**)data_027e01d8, u8 *, 0x53) = var_r0;
        } while (var_r2_2 < 2);
        data_027e01d8 = temp_r1_2;
    } else {
        temp_r0 = data_027e01d8;
        var_r1 = 0;
        do {
            temp_z_2 = var_r1 == 0;
            var_r1 += 1;
            if (temp_z_2) {
                var_r7 = (void**)g3DSpriteEngineMain;
            } else {
                var_r7 = (void**)g3DSpriteEngineSub;
            }
            data_027e01d8 = var_r7;
            temp_r7 = *(void**)data_027e01d8;
            sp14 = temp_r7;
            *temp_r7 = *sp14 & ~0x10;
            temp_r7_2 = *(void**)data_027e01d8;
            sp10 = temp_r7_2;
            *temp_r7_2 = *sp10 & ~0x20;
            temp_r7_3 = *(void**)data_027e01d8;
            spC = temp_r7_3;
            *temp_r7_3 = *spC & ~0x40;
            temp_r7_4 = *(void**)data_027e01d8;
            sp8 = temp_r7_4;
            *temp_r7_4 = *sp8 & ~0x80;
            temp_r7_5 = *(void**)data_027e01d8;
            sp4 = temp_r7_5;
            *temp_r7_5 = *sp4 | 0x100;
        } while (var_r1 < 2);
        data_027e01d8 = temp_r0;
    }
    M2C_FIELD(&gIntroAnimState, u16 *, 4) = (u16) (M2C_FIELD(&gIntroAnimState, u16 *, 4) + 1);
    ((M2C_UNK(*)(M2C_UNK,u8,s32,M2C_UNK,s32))G3_UpdateIntroTiles)(arg0, (u8)(arg2 | 0x80), 0x7FFF, 0x80, arg3);
}

void func_ov011_02223b70(s32 unused,s32 value,u32 mode) {
void func_02082a8c(void*,void*);
ContextTemplate temp=data_ov011_02227f28;
void *saved,*p; s32 i;
if(mode<2)return;
i=0;
if(value==0){saved=gCur3DSpriteEngine;
do {
if(i==0)p=g3DSpriteEngineMain;else p=g3DSpriteEngineSub;
gCur3DSpriteEngine=p;
switch(mode){case 2:func_02082a8c(&temp,(u8*)*(void**)p+0x14);break;case 3:func_02082a8c(&temp,(u8*)*(void**)p+0x24);break;}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;return;}
((s16*)&temp)[7]=value;
((s16*)&temp)[6]=((s16*)&temp)[7];
saved=gCur3DSpriteEngine;
do {
if(i==0)p=g3DSpriteEngineMain;else p=g3DSpriteEngineSub;
gCur3DSpriteEngine=p;
switch(mode){case 2:func_02082a8c(&temp,(u8*)*(void**)p+0x14);break;case 3:func_02082a8c(&temp,(u8*)*(void**)p+0x24);break;}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;
}
