/* 28 functions from 0x020A38F4 to 0x020A48EC (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct MapEffectParticle { u16 x, y, dx, dy, sprite, unkA; } MapEffectParticle;
static inline void DrawMapParticleAtX(u8 x,MapEffectParticle *p,void *map) {
 void func_01ff90e4(u8,u8,s32,void *);extern u8 data_021204a4[];
 func_01ff90e4(x,(u8)((p->y>>8)-M2C_FIELD(map,s16 *,0x514a)),0,data_021204a4+p->sprite*8);
}

typedef struct { u8 x,y; u16 width:3; u16 height:3; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020ADimEntryTop;
typedef struct { u16 first; u16 low:6; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020AEntry;

void func_020a38f4(s32 a) {
 extern s32 *gCurrentMap;
 void *p;u32 index;
 switch(a){case 1:case 2:case 3:
 p=(void *)*gCurrentMap;
 index=(u32)M2C_FIELD(p,u16 *,0x52a4)-1;
 M2C_FIELD(p+index,u8 *,0x515c)=1;
 break;
 }
}

#pragma opt_instruction_scheduling off
void func_020a3934(s32 a,s32 b) {
 extern s32 *data_027e0058;
 s32 IsPlayerActive(s32);
 s32 i;
 switch(a){case 1:case 2:case 3:
 i=1;
 do{
 if(IsPlayerActive(i))M2C_FIELD(*data_027e0058+i,u8 *,0x515b)=(u8)b;
 i++;
 }while(i<5);
 break;}
}
#pragma opt_instruction_scheduling reset
void func_020a398c(s32 a) {
 extern s32 *gCurrentMap;
 if(a==0)return;
 if(a==M2C_FIELD(*gCurrentMap,u8 *,0x5158))return;
 func_020a38f4(a);
}

void func_020a39c0(M2C_UNK arg0) {
    s16 func_020a3790(M2C_UNK);
    void func_020a3934();
    extern M2C_UNK data_021204f4;
    void *temp_r4;

    func_020a3934();
    temp_r4 = func_01ffa3dc(&data_021204f4, 7);
    M2C_FIELD(temp_r4, s16 *, 0x36) = func_020a3790(arg0);
    M2C_FIELD(temp_r4, s16 *, 0x38) = 0;
}

/* Decide the weather to announce for the next turn: manual weather (mode != 1)
   falls back to the map's reset weather, random weather picks the next one using
   the transition chances of the current weather. */
s32 RollNextWeather(void){
extern s32 *gCurrentMap;
s32 NextRandomValue(void);s32 IsWeatherChangeDue(void);
s32 weather=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,0),u8*,MAP_WEATHER);
s32 roll=NextRandomValue()%100;
if(M2C_FIELD(M2C_FIELD(gCurrentMap,void**,0),u8*,MAP_WEATHER)==M2C_FIELD(M2C_FIELD(gCurrentMap,void**,0),u8*,MAP_WEATHER_RESET)){
if(M2C_FIELD(M2C_FIELD(gCurrentMap,void**,0),u8*,MAP_WEATHER_MODE)!=1)return weather;
}
if(!IsWeatherChangeDue())return weather;
if(M2C_FIELD(M2C_FIELD(gCurrentMap,void**,0),u8*,MAP_WEATHER_MODE)!=1)weather=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,0),u8*,MAP_WEATHER_RESET);
else switch(weather){
case 0:if(roll<70)weather=0;else if(roll<80)weather=2;else if(roll<90)weather=1;else weather=3;break;
case 2:if(roll<30)weather=0;else if(roll<60)weather=2;else if(roll<80)weather=1;else weather=3;break;
case 1:if(roll<30)weather=0;else if(roll<50)weather=2;else if(roll<80)weather=1;else weather=3;break;
case 3:if(roll<30)weather=0;else if(roll<50)weather=2;else if(roll<70)weather=1;else weather=3;break;
}
return weather;
}

void func_020a3b58(void) {
extern s32 *gCurrentMap;extern M2C_UNK data_021204f4;
void *p;
func_020a398c(M2C_FIELD(*gCurrentMap,u8 *,0x515a));
if(M2C_FIELD(*gCurrentMap,u8 *,0x5158)==M2C_FIELD(*gCurrentMap,u8 *,0x515a))return;
p=func_01ffa3dc(&data_021204f4,7);
M2C_FIELD(p,u16 *,0x36)=M2C_FIELD(*gCurrentMap,u8 *,0x515a);
M2C_FIELD(p,u16 *,0x38)=1;
}

/* Sets up the clear-weather map effects: the four drifting records get random
 * positions and their drift velocities from data_020f3ba4, and all 32 weather
 * particles are parked so none is drawn. */
void InitClearWeatherEffects(void){
extern s32 *gCurrentMap;extern s32 data_020f3ba4[];s32 NextRandomValue(void);
s32 drifter;s32 drifterOffset,driftIndex,xMask,yMask;s32 particleOffset,particle;
xMask=M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH)>=32?1023:511;
yMask=M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT)>=32?1023:511;
drifter=0;drifterOffset=drifter;driftIndex=drifter;
do{
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+drifterOffset,s32 *,MAP_EFFECT_DRIFTERS+MAP_EFFECT_DRIFTER_X)=(NextRandomValue()&xMask)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+drifterOffset,s32 *,MAP_EFFECT_DRIFTERS+MAP_EFFECT_DRIFTER_Y)=(NextRandomValue()&yMask)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+drifterOffset,s32 *,MAP_EFFECT_DRIFTERS+MAP_EFFECT_DRIFTER_DX)=data_020f3ba4[driftIndex];
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+drifterOffset,s32 *,MAP_EFFECT_DRIFTERS+MAP_EFFECT_DRIFTER_DY)=data_020f3ba4[driftIndex+1];
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+drifterOffset,u16 *,MAP_EFFECT_DRIFTERS+MAP_EFFECT_DRIFTER_TIMER)=NextRandomValue()%255;
drifterOffset+=MAP_EFFECT_DRIFTER_STRIDE;driftIndex+=3;drifter++;
}while(drifter<MAP_EFFECT_DRIFTER_COUNT);
particle=0;particleOffset=particle;
do{M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+particleOffset,u16 *,MAP_EFFECT_PARTICLE_SPRITE)=0;particle++;particleOffset+=MAP_EFFECT_PARTICLE_STRIDE;}while(particle<MAP_EFFECT_PARTICLE_COUNT);
}

void InitRainEffects(void){
void SetFileDirectory(void *);void LoadDecompressedFileTo(void *,void *);void LoadFileToSpriteBuffer(void *,s32,s32);s32 NextRandomValue(void);
extern u8 data_0212054c[],data_02120558[],data_02120568[];extern s32 gCur3DSpriteEngine;extern s32 *gCurrentMap;extern u16 sWeatherParticlePatterns[];
s16 i; s32 offset;
SetFileDirectory(data_0212054c);
LoadDecompressedFileTo(data_02120558,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x2800);
LoadFileToSpriteBuffer(data_02120568,0x2c0,32);
i=0;offset=0;
do{
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,0)=(NextRandomValue()%255)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,2)=(NextRandomValue()%255)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,4)=sWeatherParticlePatterns[(i%16)*3];
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,6)=sWeatherParticlePatterns[(i%16)*3+1];
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,8)=sWeatherParticlePatterns[(i%16)*3+2];
i++;offset+=12;
}while(i<32);
}

/* Sets up the snow weather effect: loads the snow particle sprites and scatters
 * the 32 falling particles at random positions with a sideways drift. */
void InitSnowEffects(void){
void SetFileDirectory(void *);void LoadDecompressedFileTo(void *,void *);void LoadFileToSpriteBuffer(void *,s32,s32);s32 NextRandomValue(void);
extern u8 data_02120574[],data_02120580[],data_02120590[];extern s32 gCur3DSpriteEngine;extern s32 *gCurrentMap;extern u16 sWeatherParticlePatterns[];
s16 i; s32 offset;
SetFileDirectory(data_02120574);
LoadDecompressedFileTo(data_02120580,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x2800);
LoadFileToSpriteBuffer(data_02120590,0x2c0,32);
i=0;offset=0;
do{
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,MAP_EFFECT_PARTICLE_X)=(NextRandomValue()%255)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,MAP_EFFECT_PARTICLE_Y)=(NextRandomValue()%255)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,MAP_EFFECT_PARTICLE_DX)=sWeatherParticlePatterns[(i%16)*3]*3;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,MAP_EFFECT_PARTICLE_DY)=sWeatherParticlePatterns[(i%16)*3+1]*8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,MAP_EFFECT_PARTICLE_SPRITE)=sWeatherParticlePatterns[(i%16)*3+2];
i++;offset+=MAP_EFFECT_PARTICLE_STRIDE;
}while(i<MAP_EFFECT_PARTICLE_COUNT);
}

void InitSandstormEffects(void){
void SetFileDirectory(void *);void LoadDecompressedFileTo(void *,void *);void LoadFileToSpriteBuffer(void *,s32,s32);s32 NextRandomValue(void);
extern u8 data_0212059c[],data_021205a8[],data_021205bc[];extern s32 gCur3DSpriteEngine;extern s32 *gCurrentMap;extern u16 sWeatherParticlePatterns[];
s32 i; s32 offset;
SetFileDirectory(data_0212059c);
LoadDecompressedFileTo(data_021205a8,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x2800);
LoadFileToSpriteBuffer(data_021205bc,0x2c0,32);
i=0;offset=0;
do{
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,0)=(NextRandomValue()%255)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,2)=(NextRandomValue()%255)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,4)=sWeatherParticlePatterns[(i%16)*3]*20;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,6)=sWeatherParticlePatterns[(i%16)*3+1];
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+offset,u16 *,8)=sWeatherParticlePatterns[(i%16)*3+2];
i++;offset+=12;
}while(i<32);
}

void ApplyWeatherEffects(u32 a) {
void InitClearWeatherEffects(void);void InitRainEffects(void);void InitSnowEffects(void);void InitSandstormEffects(void);
switch(a){case 0:InitClearWeatherEffects();return;case 1:InitRainEffects();return;case 2:InitSnowEffects();return;case 3:InitSandstormEffects();return;default:return;}
}

void func_020a4100(s32 a) {
extern s32 *gCurrentMap;u8 b=a;
M2C_FIELD(*gCurrentMap,u8 *,0x515b)=b;
M2C_FIELD(*gCurrentMap,u8 *,0x5158)=b;
M2C_FIELD(*gCurrentMap,u8 *,0x515a)=b;
M2C_FIELD(*gCurrentMap,u8 *,0x5159)=0;
}

#pragma push
#pragma opt_instruction_scheduling on
void func_020a4154(void) {
void func_01ff90e4(u8,u8,s32,void *); extern u8 data_021204a4[];extern s32 *gCurrentMap;extern s32 data_027e15c0;
s16 i=0; s32 offset=0;void *p,*q;s32 drawOffset,end;u32 j;s16 next;
do {p=M2C_FIELD(gCurrentMap,void **,12);i++;M2C_FIELD(p,u16 *,offset)+=M2C_FIELD((u8 *)p+offset,u16 *,4);q=(u8 *)M2C_FIELD(gCurrentMap,void **,12)+offset;offset+=12;M2C_FIELD(q,u16 *,2)+=M2C_FIELD(q,u16 *,6);}while(i<32);
j=(u32)(data_027e15c0<<31)>>27;end=j+16;if(end<=(s32)j)return;drawOffset=(s16)j*12;
do {p=(u8 *)M2C_FIELD(gCurrentMap,void **,12)+drawOffset;q=M2C_FIELD(gCurrentMap,void **,0);
{u16 x=M2C_FIELD(p,volatile u16 *,0);s16 mx=M2C_FIELD(q,volatile s16 *,0x5148);u16 idx=M2C_FIELD(p,volatile u16 *,8);
func_01ff90e4((u8)((x>>8)-mx),(u8)((M2C_FIELD(p,u16 *,2)>>8)-M2C_FIELD(q,s16 *,0x514a)),0,data_021204a4+idx*8);}
next=j+1;drawOffset+=12;j=next;}while(end>(s32)j);
}

#pragma push
#pragma opt_instruction_scheduling on
void func_020a4250(void) {
void func_01ff90e4(u8,u8,s32,void *); extern u8 data_021204bc[];extern s32 *data_027e0058;extern s32 data_027e15c0;
s16 i=0; s32 offset=0;void *p,*q;s32 drawOffset,end;u32 j;s16 next;
do {p=M2C_FIELD(data_027e0058,void **,12);i++;M2C_FIELD(p,u16 *,offset)+=M2C_FIELD((u8 *)p+offset,u16 *,4);q=(u8 *)M2C_FIELD(data_027e0058,void **,12)+offset;offset+=12;M2C_FIELD(q,u16 *,2)+=M2C_FIELD(q,u16 *,6);}while(i<32);
j=(u32)(data_027e15c0<<31)>>27;end=j+16;if(end<=(s32)j)return;drawOffset=(s16)j*12;
do {p=(u8 *)M2C_FIELD(data_027e0058,void **,12)+drawOffset;q=M2C_FIELD(data_027e0058,void **,0);
{u16 x=M2C_FIELD(p,volatile u16 *,0);s16 mx=M2C_FIELD(q,volatile s16 *,0x5148);u16 idx=M2C_FIELD(p,volatile u16 *,8);
func_01ff90e4((u8)((x>>8)-mx),(u8)((M2C_FIELD(p,u16 *,2)>>8)-M2C_FIELD(q,s16 *,0x514a)),0,data_021204bc+idx*8);}
next=j+1;drawOffset+=12;j=next;}while(end>(s32)j);
}
#pragma pop
void func_020a434c(void) {
    void func_01ff90e4(u8, u8, s32, void *);
    extern u8 data_0212049c[];
    extern s32 *gCurrentMap;
    extern s32 data_027e15c0;
    s16 i;
    s32 offset;
    void *p;
    void *q;
    s32 drawOffset;
    s32 end;
    u32 j;
    s16 next;
    i = 0;
    offset = 0;
    do {
        p = M2C_FIELD(gCurrentMap, void **, 0xC);
        i++;
        M2C_FIELD(p, u16 *, offset) += M2C_FIELD((u8 *)p + offset, u16 *, 4);
        q = (u8 *)M2C_FIELD(gCurrentMap, void **, 0xC) + offset;
        offset += 12;
        M2C_FIELD(q, u16 *, 2) += M2C_FIELD(q, u16 *, 6);
    } while (i < 32);
    j = (u32)(data_027e15c0 << 31) >> 27;
    end = j + 16;
    if (end <= (s32)j) return;
    drawOffset = (s16)j * 12;
    do {
        p = (u8 *)M2C_FIELD(gCurrentMap, void **, 0xC) + drawOffset;
        q = M2C_FIELD(gCurrentMap, void **, 0);
        func_01ff90e4((u8)(((((M2C_FIELD(p, u16 *, 0) >> 8) - (s32)M2C_FIELD(M2C_FIELD(q, void **, 0), s16 *, 0x5148)) & 0xff) - 0x10) & 0x1ff),
                     (u8)(((M2C_FIELD(p, u16 *, 2) >> 8) - (s32)M2C_FIELD(M2C_FIELD(q, void **, 0), s16 *, 0x514A)) & 0xff),
                     0,
                     data_0212049c);
        next = j + 1;
        drawOffset += 12;
        j = next;
    } while (end > (s32)j);
}

void func_020a445c(void) {
extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain;extern s32 *gCurrentMap;
void func_020a4250(void);void func_020a434c(void);
s32 old=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
switch(M2C_FIELD(*gCurrentMap,u8 *,0x5158)){case 0:break;case 1:func_020a4154();break;case 2:func_020a4250();break;case 3:func_020a434c();break;}
gCur3DSpriteEngine=old;
}

#pragma scheduling reset
void func_020a44d0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021204d4;
    func_01ffa3dc(&data_021204d4, 1);
}

void func_020a44e8(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_021204d4;
    func_01ffa9e4(&data_021204d4);
}

void func_020a44fc(M2C_UNK arg0, s32 arg1) {
    M2C_UNK MI_CpuCopy8(M2C_UNK, s32, M2C_UNK);
    extern s32 *gCurrentMap;
    MI_CpuCopy8(arg0, *gCurrentMap + 0x58A4 + (arg1 * 8), 8);
}

void func_020a4528(void) {
extern s32 *gCurrentMap;Unk020ADimEntryTop *p=(Unk020ADimEntryTop *)(*gCurrentMap+0x58a4);s32 i=0;
do{p->height=0;p->width=p->height;
M2C_FIELD(p,u8 *,0)=M2C_FIELD(p,u8 *,1)=p->width;
p->type=0;p->value=0;p->mode=0;p->kind=0;p->extra=0;p->last=0;p++;i++;}while(i<32);
}

void func_020a45cc(void) {
 void func_020a4528(void);
 extern s32 *gCurrentMap;
 M2C_FIELD(*gCurrentMap,u16 *,0x58a6)&=~0x3c0;
 func_020a4528();
}

void *func_020a45f8(s32 a,s32 b) {
extern s32 *gCurrentMap;Unk020ADimEntryTop *p=(Unk020ADimEntryTop *)(*gCurrentMap+0x58a4);
while(p->type){s32 x=M2C_FIELD(p,u8 *,0);s32 endx=x+p->width; s32 y=M2C_FIELD(p,u8 *,1);s32 endy=y+p->height;
if(a>=x&&b>=y&&a<endx&&b<endy)return p;p++;}return 0;
}

void *func_020a4678(s32 a,s32 b,s32 c) {
extern s32 *gCurrentMap;Unk020ADimEntryTop *p=(Unk020ADimEntryTop *)(*gCurrentMap+0x58a4);u32 t;
while(t=p->type){s32 x=M2C_FIELD(p,u8 *,0);s32 endx=x+p->width; s32 y=M2C_FIELD(p,u8 *,1);s32 endy=y+p->height;
if(a>=x&&b>=y&&a<endx&&b<endy){if(t==c)return p;}p++;}return 0;
}

u8 func_020a4700(s32 a,s32 b) {
extern s32 *gCurrentMap;
s16 pos[2];s32 p;void *q=func_020a45f8(a,b);
if(!q)return 0;
if(!func_020a488c(q,pos))return 0;
p=*gCurrentMap;
return M2C_FIELD(p+(pos[0]+M2C_FIELD(p+pos[1]*2,u16 *,0x3758)),s8 *,0x1e30)>=0;
}

s32 func_020a4770(s32 a,s32 b) {
s16 pos[2];void *p=func_020a45f8(a,b);
if(!p)return 0;
if(!func_020a488c(p,pos))return 0;
if(pos[0]!=a||pos[1]!=b)return 0;
if(!M2C_FIELD(p,u8 *,4))p=0;
return (s32)p;
}

s32 func_020a47e0(s32 a,s32 b) {
extern s32 *gCurrentMap;s32 func_020a4770(s32,s32);s32 p=*gCurrentMap;
if((M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420)&31)!=29)return 0;return func_020a4770(a,b);
}

#pragma scheduling off
s32 func_020a4828(s32 a,s32 b) {
extern s32 *gCurrentMap;
s32 q=func_020a4770(a,b);s32 p=*gCurrentMap; s32 result=0;u32 value;

value=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x539c)&127;
if(q)result=(u32)(M2C_FIELD(q,u16 *,2)<<22)>>28;
if(value)result=1;
return result;
}
#pragma scheduling reset
s32 func_020a488c(void *arg0, void *arg1) {
    u32 temp_r2;

    temp_r2 = (u32) (M2C_FIELD(arg0, u16 *, 2) << 0x16) >> 0x1C;
    switch (temp_r2) {                              /* irregular */
    case 6:
    case 7:
        M2C_FIELD(arg1, s16 *, 0) = (s16) M2C_FIELD(arg0, u8 *, 0);
        M2C_FIELD(arg1, s16 *, 2) = (s16) M2C_FIELD(arg0, u8 *, 1);
        return 1;
    case 4:
        M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u8 *, 0) + 1);
        M2C_FIELD(arg1, s16 *, 2) = (s16) (M2C_FIELD(arg0, u8 *, 1) + 2);
        return 1;
    default:
        return 0;
    }
}
typedef struct { u8 x,y; u16 width:3; u16 height:3; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020ADimEntry;
