/* 28 functions from 0x020A38F4 to 0x020A48EC (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct MapEffectParticle { u16 x, y, dx, dy, sprite, unkA; } MapEffectParticle;
static inline void DrawMapParticleAtX(u8 x,MapEffectParticle *p,void *map) {
 void DS3D_AddSpriteQuad(s32, s32, u32, u16 *);extern u8 data_021204a4[];
 DS3D_AddSpriteQuad(x,(u8)((p->y>>8)-M2C_FIELD(map,s16 *,0x514a)),0,(u16 *)(data_021204a4+p->sprite*8));
}

typedef struct { u16 first; u16 low:6; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020AEntry;

/* Give the acting player a one-turn weather-change delay when the weather turns
 * adverse (rain, snow or sandstorm). */
void SetWeatherChangeDelay(s32 weather) {
    extern s32 *gCurrentMap;
    void *map;
    u32 playerIndex;

    switch (weather) {
    case WEATHER_RAIN:
    case WEATHER_SNOW:
    case WEATHER_SANDSTORM:
        map = (void *)*gCurrentMap;
        playerIndex = (u32)M2C_FIELD(map, u16 *, MAP_CURRENT_PLAYER) - 1;
        M2C_FIELD(map + playerIndex, u8 *, MAP_WEATHER_DELAY) = 1;
        break;
    }
}

#pragma opt_instruction_scheduling off
/* When the weather changes to an adverse one (rain, snow or sandstorm), give
 * every active player `turns` turns of weather-change delay.  (The delay array
 * sits one byte past MAP_WEATHER_RESET, so player 1's entry is at RESET + 1.) */
void SetWeatherChangeDelayForAllPlayers(s32 weather, s32 turns) {
    extern s32 *gCurrentMap;
    s32 IsPlayerActive(s32);
    s32 player;

    switch (weather) {
    case WEATHER_RAIN:
    case WEATHER_SNOW:
    case WEATHER_SANDSTORM:
        player = 1;
        do {
            if (IsPlayerActive(player))
                M2C_FIELD(*gCurrentMap + player, u8 *, MAP_WEATHER_DELAY - 1) = (u8)turns;
            player++;
        } while (player < MAX_PLAYERS);
        break;
    }
}
#pragma opt_instruction_scheduling reset
/* Give the acting player a weather-change delay for `weather`, unless it is clear
 * weather or the map's weather is already `weather` (so nothing changed). */
void SetWeatherChangeDelayIfChanged(s32 weather) {
    extern s32 *gCurrentMap;
    if (weather == WEATHER_CLEAR) return;
    if (weather == M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER)) return;
    SetWeatherChangeDelay(weather);
}

/* Starts the map's weather transition to `weather`: every active player gets
 * `turns` turns of weather-change delay, then the transition sprite (a normal
 * change, not a reset to the start weather) is created. */
void StartWeatherChange(s32 weather, s32 turns) {
    void SetWeatherChangeDelayForAllPlayers(s32, s32);
    extern M2C_UNK gWeatherTransitionSpriteClass;
    void *sprite;

    SetWeatherChangeDelayForAllPlayers(weather, turns);
    sprite = CreateSpriteFromClass(&gWeatherTransitionSpriteClass, 7);
    M2C_FIELD(sprite, s16 *, WEATHER_SPRITE_TARGET) = NormalizeWeather(weather);
    M2C_FIELD(sprite, s16 *, WEATHER_SPRITE_IS_RESET) = 0;
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

/* Bring the map back to the weather it started with: if the start weather
 * differs from the current one, first note the change for the acting player,
 * then start a transition sprite towards the start weather. */
void BeginWeatherResetTransition(void) {
    extern s32 *gCurrentMap;
    extern M2C_UNK gWeatherTransitionSpriteClass;
    void *sprite;

    SetWeatherChangeDelayIfChanged(M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER_START));
    if (M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER) == M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER_START)) return;
    sprite = CreateSpriteFromClass(&gWeatherTransitionSpriteClass, 7);
    M2C_FIELD(sprite, u16 *, 0x36) = M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER_START);
    M2C_FIELD(sprite, u16 *, 0x38) = 1;
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

/* Sets up the rain weather effect: loads the particle sprites and palette, then
 * scatters the 32 falling particles at random positions with their drift pattern. */
void InitRainEffects(void){
void SetFileDirectory(void *);void LoadDecompressedFileTo(void *,void *);void LoadFileToSpriteBuffer(void *,s32,s32);s32 NextRandomValue(void);
extern u8 sRainDir[],sRainCgName[],sRainClName[];extern s32 gCur3DSpriteEngine;extern s32 *gCurrentMap;extern u16 sWeatherParticlePatterns[];
s16 particle; s32 particleOffset;
SetFileDirectory(sRainDir);
LoadDecompressedFileTo(sRainCgName,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x2800);
LoadFileToSpriteBuffer(sRainClName,0x2c0,32);
particle=0;particleOffset=0;
do{
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+particleOffset,u16 *,MAP_EFFECT_PARTICLE_X)=(NextRandomValue()%255)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+particleOffset,u16 *,MAP_EFFECT_PARTICLE_Y)=(NextRandomValue()%255)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+particleOffset,u16 *,MAP_EFFECT_PARTICLE_DX)=sWeatherParticlePatterns[(particle%16)*3];
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+particleOffset,u16 *,MAP_EFFECT_PARTICLE_DY)=sWeatherParticlePatterns[(particle%16)*3+1];
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+particleOffset,u16 *,MAP_EFFECT_PARTICLE_SPRITE)=sWeatherParticlePatterns[(particle%16)*3+2];
particle++;particleOffset+=MAP_EFFECT_PARTICLE_STRIDE;
}while(particle<MAP_EFFECT_PARTICLE_COUNT);
}

/* Sets up the snow weather effect: loads the snow particle sprites and scatters
 * the 32 falling particles at random positions with a sideways drift. */
void InitSnowEffects(void){
void SetFileDirectory(void *);void LoadDecompressedFileTo(void *,void *);void LoadFileToSpriteBuffer(void *,s32,s32);s32 NextRandomValue(void);
extern u8 sSnowDir[],sSnowCgName[],sSnowClName[];extern s32 gCur3DSpriteEngine;extern s32 *gCurrentMap;extern u16 sWeatherParticlePatterns[];
s16 i; s32 offset;
SetFileDirectory(sSnowDir);
LoadDecompressedFileTo(sSnowCgName,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x2800);
LoadFileToSpriteBuffer(sSnowClName,0x2c0,32);
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

/* Sets up the sandstorm weather effect: loads the sand particle sprites and scatters
 * the 32 drifting particles at random positions with a fast sideways drift. */
void InitSandstormEffects(void){
void SetFileDirectory(void *);void LoadDecompressedFileTo(void *,void *);void LoadFileToSpriteBuffer(void *,s32,s32);s32 NextRandomValue(void);
extern u8 sBmapFsDir[],sStormCgName[],sStormClName[];extern s32 gCur3DSpriteEngine;extern s32 *gCurrentMap;extern u16 sWeatherParticlePatterns[];
s32 particle; s32 particleOffset;
SetFileDirectory(sBmapFsDir);
LoadDecompressedFileTo(sStormCgName,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x2800);
LoadFileToSpriteBuffer(sStormClName,0x2c0,32);
particle=0;particleOffset=0;
do{
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+particleOffset,u16 *,MAP_EFFECT_PARTICLE_X)=(NextRandomValue()%255)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+particleOffset,u16 *,MAP_EFFECT_PARTICLE_Y)=(NextRandomValue()%255)<<8;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+particleOffset,u16 *,MAP_EFFECT_PARTICLE_DX)=sWeatherParticlePatterns[(particle%16)*3]*20;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+particleOffset,u16 *,MAP_EFFECT_PARTICLE_DY)=sWeatherParticlePatterns[(particle%16)*3+1];
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,12)+particleOffset,u16 *,MAP_EFFECT_PARTICLE_SPRITE)=sWeatherParticlePatterns[(particle%16)*3+2];
particle++;particleOffset+=MAP_EFFECT_PARTICLE_STRIDE;
}while(particle<MAP_EFFECT_PARTICLE_COUNT);
}

/* Install the map effect set for the given weather: clear, rain, snow or
 * sandstorm particles and their drift records. */
void ApplyWeatherEffects(u32 weather) {
    void InitClearWeatherEffects(void);
    void InitRainEffects(void);
    void InitSnowEffects(void);
    void InitSandstormEffects(void);

    switch (weather) {
    case WEATHER_CLEAR:     InitClearWeatherEffects();     return;
    case WEATHER_RAIN:      InitRainEffects();             return;
    case WEATHER_SNOW:      InitSnowEffects();             return;
    case WEATHER_SANDSTORM: InitSandstormEffects();        return;
    default: return;
    }
}

/* Fixes the map's weather to `weather`: current, start and reset weather all
 * become it, and the automatic weather change is turned off. */
void SetMapWeather(s32 weather) {
    extern s32 *gCurrentMap;
    u8 w = weather;
    M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER_RESET) = w;
    M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER) = w;
    M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER_START) = w;
    M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER_MODE) = 0;
}

#pragma push
#pragma opt_instruction_scheduling on
/* Rain pass, drawn through the effect sprite engine: advance the off-screen
 * weather particles (16 of the 32 by turn) and draw them as rain sprites. */
void DrawRainParticles(void) {
    void DS3D_AddSpriteQuad(s32, s32, u32, u16 *);
    extern u8 data_021204a4[];
    extern s32 *gCurrentMap;
    extern s32 gVBlankCount;
    s16 particle = 0;
    s32 offset = 0;
    void *p;
    void *q;
    s32 drawOffset;
    s32 end;
    u32 first;
    s16 next;

    do {
        p = M2C_FIELD(gCurrentMap, void **, 12);
        particle++;
        M2C_FIELD(p, u16 *, offset) += M2C_FIELD((u8 *)p + offset, u16 *, 4);
        q = (u8 *)M2C_FIELD(gCurrentMap, void **, 12) + offset;
        offset += 12;
        M2C_FIELD(q, u16 *, 2) += M2C_FIELD(q, u16 *, 6);
    } while (particle < 32);
    first = (u32)(gVBlankCount << 31) >> 27;
    end = first + 16;
    if (end <= (s32)first) return;
    drawOffset = (s16)first * 12;
    do {
        p = (u8 *)M2C_FIELD(gCurrentMap, void **, 12) + drawOffset;
        q = M2C_FIELD(gCurrentMap, void **, 0);
        {
            u16 x = M2C_FIELD(p, volatile u16 *, 0);
            s16 mx = M2C_FIELD(q, volatile s16 *, 0x5148);
            u16 sprite = M2C_FIELD(p, volatile u16 *, 8);
            DS3D_AddSpriteQuad((u8)((x >> 8) - mx),
                          (u8)((M2C_FIELD(p, u16 *, 2) >> 8) - M2C_FIELD(q, s16 *, 0x514a)),
                          0, (u16 *)(data_021204a4 + sprite * 8));
        }
        next = first + 1;
        drawOffset += 12;
        first = next;
    } while (end > (s32)first);
}

#pragma push
#pragma opt_instruction_scheduling on
/* Snow pass, drawn through the effect sprite engine: advance the off-screen
 * weather particles (16 of the 32 by turn) and draw them as snow sprites. */
void DrawSnowParticles(void) {
    void DS3D_AddSpriteQuad(s32, s32, u32, u16 *);
    extern u8 data_021204bc[];
    extern s32 *data_027e0058;
    extern s32 gVBlankCount;
    s16 particle = 0;
    s32 offset = 0;
    void *p;
    void *q;
    s32 drawOffset;
    s32 end;
    u32 first;
    s16 next;

    do {
        p = M2C_FIELD(data_027e0058, void **, 12);
        particle++;
        M2C_FIELD(p, u16 *, offset) += M2C_FIELD((u8 *)p + offset, u16 *, 4);
        q = (u8 *)M2C_FIELD(data_027e0058, void **, 12) + offset;
        offset += 12;
        M2C_FIELD(q, u16 *, 2) += M2C_FIELD(q, u16 *, 6);
    } while (particle < 32);
    first = (u32)(gVBlankCount << 31) >> 27;
    end = first + 16;
    if (end <= (s32)first) return;
    drawOffset = (s16)first * 12;
    do {
        p = (u8 *)M2C_FIELD(data_027e0058, void **, 12) + drawOffset;
        q = M2C_FIELD(data_027e0058, void **, 0);
        {
            u16 x = M2C_FIELD(p, volatile u16 *, 0);
            s16 mx = M2C_FIELD(q, volatile s16 *, 0x5148);
            u16 sprite = M2C_FIELD(p, volatile u16 *, 8);
            DS3D_AddSpriteQuad((u8)((x >> 8) - mx),
                          (u8)((M2C_FIELD(p, u16 *, 2) >> 8) - M2C_FIELD(q, s16 *, 0x514a)),
                          0, (u16 *)(data_021204bc + sprite * 8));
        }
        next = first + 1;
        drawOffset += 12;
        first = next;
    } while (end > (s32)first);
}
#pragma scheduling on
void DrawSandstormParticles(void) {
    void DS3D_AddSpriteQuad(s32, s32, u32, u16 *);
    extern u8 data_0212049c[];
    extern s32 *gCurrentMap;
    extern s32 gVBlankCount;
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
    j = (u32)(gVBlankCount << 31) >> 27;
    end = j + 16;
    if (end <= (s32)j) return;
    drawOffset = (s16)j * 12;
    do {
        p = (u8 *)M2C_FIELD(gCurrentMap, void **, 0xC) + drawOffset;
        q = M2C_FIELD(gCurrentMap, void **, 0);
        {
            u16 x = M2C_FIELD(p, volatile u16 *, 0);
            s16 mx = M2C_FIELD(q, volatile s16 *, 0x5148);
            u16 y = M2C_FIELD(p, u16 *, 2);
            s16 my = M2C_FIELD(q, s16 *, 0x514a);
            u8 relativeX = (x >> 8) - mx;
            u8 relativeY = (y >> 8) - my;
            DS3D_AddSpriteQuad((u32)((u16)((relativeX - 16) & 0x1ff)), relativeY,
                              0, (u16 *)data_0212049c);
        }
        next = j + 1;
        drawOffset += 12;
        j = next;
    } while (end > (s32)j);
}
#pragma scheduling reset
/* Draws the map's current weather particles on the main 3D sprite engine: the
 * engine is switched to the main screen for the draw and restored afterwards,
 * then the drawer chosen by MAP_WEATHER runs (nothing in clear weather). */
void DrawWeatherEffects(void) {
    extern s32 gCur3DSpriteEngine, g3DSpriteEngineMain;
    extern s32 *gCurrentMap;
    void DrawRainParticles(void);
    void DrawSnowParticles(void);
    void DrawSandstormParticles(void);
    s32 savedEngine = gCur3DSpriteEngine;

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    switch (M2C_FIELD(*gCurrentMap, u8 *, MAP_WEATHER)) {
    case MAP_WEATHER_CLEAR:
        break;
    case MAP_WEATHER_RAIN:
        DrawRainParticles();
        break;
    case MAP_WEATHER_SNOW:
        DrawSnowParticles();
        break;
    case MAP_WEATHER_SANDSTORM:
        DrawSandstormParticles();
        break;
    }
    gCur3DSpriteEngine = savedEngine;
}

#pragma scheduling reset
void CreateWeatherEffectSprite(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gWeatherEffectSpriteClass;
    CreateSpriteFromClass(&gWeatherEffectSpriteClass, 1);
}

void DeleteWeatherEffectSprites(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK gWeatherEffectSpriteClass;
    DeleteSpriteObjectsOfClass(&gWeatherEffectSpriteClass);
}

/* Store the 8-byte map order `record` into the map's order queue at `index`
 * (used when a saved battle restores the queue). */
void SetMapOrderRecord(void *record, s32 index) {
    M2C_UNK MI_CpuCopy8(M2C_UNK, s32, M2C_UNK);
    extern s32 *gCurrentMap;
    MI_CpuCopy8(record, *gCurrentMap + MAP_ORDERS + (index * MAP_ORDER_STRIDE), MAP_ORDER_STRIDE);
}

/* Empties the map's order queue: every one of its 32 records is cleared, with the
 * record's rectangle, type, value and countdown all set to 0. */
void ClearMapOrders(void) {
extern s32 *gCurrentMap;MapOrder *order=(MapOrder *)(*gCurrentMap+MAP_ORDERS);s32 i=0;
do{order->height=0;order->width=order->height;
M2C_FIELD(order,u8 *,0)=M2C_FIELD(order,u8 *,1)=order->width;
order->type=0;order->value=0;order->mode=0;order->kind=0;order->timer=0;order->last=0;order++;i++;}while(i<MAP_ORDER_COUNT);
}

/* Reset the map's order queue: clear the type of the order at the head of the
 * queue, then clear every order record. */
void ResetMapOrders(void) {
    void ClearMapOrders(void);
    extern s32 *gCurrentMap;

    M2C_FIELD(*gCurrentMap, u16 *, MAP_ORDERS + MAP_ORDER_TYPE) &= ~MAP_ORDER_TYPE_BITS;
    ClearMapOrders();
}

/* Returns the first map order whose tile rectangle covers (x, y), whatever its type, or NULL. */
MapOrder *FindMapOrderAtTile(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    MapOrder *order = (MapOrder *)(*gCurrentMap + MAP_ORDERS);
    while (order->type) {
        s32 startX = order->x;
        s32 endX = startX + order->width;
        s32 startY = order->y;
        s32 endY = startY + order->height;
        if (x >= startX && y >= startY && x < endX && y < endY) return order;
        order++;
    }
    return 0;
}

/* Finds the first map order of the given type whose rectangle contains the
 * tile (x, y), or NULL. */
void *FindMapOrderOfTypeAt(s32 x,s32 y,s32 type) {
extern s32 *gCurrentMap;MapOrder *order=(MapOrder *)(*gCurrentMap+MAP_ORDERS);u32 orderType;
while(orderType=order->type){s32 startX=order->x;s32 endX=startX+order->width; s32 startY=order->y;s32 endY=startY+order->height;
if(x>=startX&&y>=startY&&x<endX&&y<endY){if(orderType==type)return order;}order++;}return 0;
}

/* Returns 1 when the map order covering tile (x, y) has its effect position
 * marked in the current cell layer: the tile lies in the order effect area
 * (a commander power, a missile...) being shown on the map. */
u8 IsCellInOrderEffectArea(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s16 pos[2];
    s32 map;
    MapOrder *order = FindMapOrderAtTile(x, y);
    if (!order) return 0;
    if (!GetMapOrderEffectPosition(order, pos)) return 0;
    map = *gCurrentMap;
    return M2C_FIELD(map + (pos[0] + M2C_FIELD(map + pos[1] * 2, u16 *, MAP_ROW_OFFSETS)), s8 *, MAP_CELL_ORDER) >= 0;
}

/* The destructible map feature anchored exactly at tile (x, y), or NULL: the map
 * order covering the tile must resolve to this tile and still have hit points left. */
s32 FindMapFeatureAtTile(s32 x,s32 y) {
s16 pos[2];void *order=FindMapOrderAtTile(x,y);
if(!order)return 0;
if(!func_020a488c(order,pos))return 0;
if(pos[0]!=x||pos[1]!=y)return 0;
if(!M2C_FIELD(order,u8 *,MAP_ORDER_VALUE))order=0;
return (s32)order;
}

/* The destructible map feature anchored at tile (x, y), or NULL: only a tile
 * whose terrain kind is a feature tile can hold one. */
s32 FindDestructibleFeatureAtTile(s32 x,s32 y) {
extern s32 *gCurrentMap;s32 FindMapFeatureAtTile(s32,s32);s32 map=*gCurrentMap;
if((M2C_FIELD(map+(x+M2C_FIELD(map+y*2,u16 *,MAP_ROW_OFFSETS)),u8 *,MAP_CELL_TERRAIN)&MAP_TERRAIN_KIND_MASK)!=MAP_TERRAIN_FEATURE)return 0;return FindMapFeatureAtTile(x,y);
}

#pragma scheduling off
/* The battle-preview target kind of tile (x, y): 1 when the tile has destructible
 * terrain hit points left, otherwise the type of the attack order anchored on it,
 * or 0 when the tile holds neither. */
s32 GetTileTargetKind(s32 x, s32 y) {
extern s32 *gCurrentMap;
s32 feature = FindMapFeatureAtTile(x, y);
s32 map = *gCurrentMap;
s32 targetKind = 0;
u32 terrainHp;

terrainHp = M2C_FIELD(map + (x + M2C_FIELD(map + y * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_TERRAIN_HP) & MAP_CELL_TERRAIN_HP_MASK;
if (feature) targetKind = (u32)(M2C_FIELD(feature, u16 *, MAP_ORDER_TYPE) << 22) >> 28;
if (terrainHp) targetKind = 1;
return targetKind;
}
#pragma scheduling reset
/* Writes the tile a map order's effect plays at into out: a line attack (or a
 * player-facing line) plays on the order's own tile, a radius-5 area attack one
 * tile right and two rows below its rectangle origin.  Returns 0 for an order
 * with no fixed effect tile. */
s32 GetMapOrderEffectPosition(MapOrder *order, s16 *out) {
    u32 type;

    type = (u32) (M2C_FIELD(order, u16 *, MAP_ORDER_TYPE) << 0x16) >> 0x1C;
    switch (type) {                                 /* irregular */
    case MAPORDER_ATTACK_LINE:
    case MAPORDER_ATTACK_LINE_FACING:
        out[0] = M2C_FIELD(order, u8 *, 0);
        out[1] = M2C_FIELD(order, u8 *, 1);
        return 1;
    case MAPORDER_ATTACK_AREA:
        out[0] = (s16) (M2C_FIELD(order, u8 *, 0) + 1);
        out[1] = (s16) (M2C_FIELD(order, u8 *, 1) + 2);
        return 1;
    default:
        return 0;
    }
}
typedef struct { u8 x,y; u16 width:3; u16 height:3; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020ADimEntry;
