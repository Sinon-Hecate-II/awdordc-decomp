/* 32 functions from 0x020B6168 to 0x020B7138 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
typedef struct { u8 pad[0x48]; u32 distance:10; u32 flags:22; } RangeEffect;

void func_020b6168(void *arg0) {
    extern void **gCurrentMap;
    M2C_UNK PlaySoundAtTile(M2C_UNK, s32, s32);
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    s32 SetAnimatedSpriteFrame(void *, s32);
    void func_02080750(s32, s32, s32);
    void func_02080358(s32, s32, s32, s32);
    M2C_UNK CancelMapCursorAnimation(void);
    void func_020b6124(void *);

    u8 *core;
    register s32 xc,yc,range;
    s32 minX, minY, maxY;
    register s32 maxX;
    s32 t;
    register void *p;
    register s32 x,y,dy,dx;
    s32 dist, adx, ady;
    u32 bits;


    range = M2C_FIELD(arg0, s16 *, 0x4C);
    xc = M2C_FIELD(arg0, s16 *, 0x44);
    yc = M2C_FIELD(arg0, s16 *, 0x46);

    minX = xc - range;
    if (minX < 0) minX = 0;
    minY = yc - range;
    if (minY < 0) minY = 0;

    core = (u8 *)*gCurrentMap;
    maxX = (s32)M2C_FIELD(core, u16 *, 0x5144) - 1;
    t = xc + range;
    if (t < maxX) maxX = t;

    maxY = (s32)M2C_FIELD(core, u16 *, 0x5146) - 1;
    t = yc + range;
    if (t < maxY) maxY = t;

    if (minY <= maxY) {
        for (y = minY; y <= maxY; y++) {
            for (x = minX; x <= maxX; x++) {
                dx = M2C_FIELD(arg0,s16 *,0x44) - x;
                dist=0;
                if (dx > 0) dist += dx;
                else dist += x - M2C_FIELD(arg0,s16 *,0x44);
                dy = M2C_FIELD(arg0,s16 *,0x46) - y;
                if (dy > 0) dist += dy;
                else dist += y - M2C_FIELD(arg0,s16 *,0x46);
                if (dist < 0) continue;
                if (dist > M2C_FIELD(arg0,s16 *,0x4c)) continue;

                if (dy < 0) dy=-dy;
                if (dx < 0) dx=-dx;

                p = CreateEffectMapSprite((M2C_UNK *)((u8 *)arg0 + 0x34), x, y, 0x10, 0, 0, arg0);
                SetAnimatedSpriteFrame(p, 2);
                ((RangeEffect *)p)->distance=(u8)((dx+dy)*8);
                M2C_FIELD(p, s32 *, 0x58) = x;
                M2C_FIELD(p, s32 *, 0x5C) = y;
                M2C_FIELD(p, s32 *, 0x60) = M2C_FIELD(arg0, s16 *, 0x4E);
                M2C_FIELD(p, void (**)(void *), 0x6C) = func_020b6124;
            }
        }
    }

    func_02080750(2, 0x3C, 0);
    func_02080358(4, 0, 2, 0);
    PlaySoundAtTile(0x93, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46));
    CancelMapCursorAnimation();
}

/* Step the screen-transition down-counter (func_020b524c -> CloseEffectNarcArchive, which
 * fires CloseNarcArchive once the counter wraps to zero), then finalize the current
 * map view and run its registered callbacks (RefreshMapView -> func_020d0270 +
 * func_020cfd38). */
void func_020b6320(void) {
    M2C_UNK RefreshMapView();
    M2C_UNK func_020b524c();
    func_020b524c();
    RefreshMapView();
}

/* Spawn a path-marker task at tile (x, y) with the given range and tile index,
 * copy its label string into the task, then move the view onto the marker. */
void func_020b6330(s16 x, s16 y, s16 range, s16 tileIdx, s32 parent) {
    void *CreateSpriteObject();
    M2C_UNK StringCopy(void *, M2C_UNK *);
    extern M2C_UNK data_02128cec, data_02128e98;
    void *task;
    task = CreateSpriteObject(&data_02128cec, parent);
    M2C_FIELD(task, s16 *, 0x44) = x;
    M2C_FIELD(task, s16 *, 0x46) = y;
    M2C_FIELD(task, s16 *, 0x4C) = range;
    M2C_FIELD(task, s16 *, 0x4E) = tileIdx;
    M2C_FIELD(task, s32 *, 0x50) = 0;
    StringCopy(task + 0x34, &data_02128e98);
    PanMapViewToTile(x, y);
}

void func_020b638c(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    void *CreateSpriteObject();
    M2C_UNK StringCopy(void *, M2C_UNK *);
    extern M2C_UNK data_02128cec, data_02128ea4;
    M2C_UNK *g = &data_02128cec;
    void *p;
    p = CreateSpriteObject(g, arg4);
    M2C_FIELD(p, s16 *, 0x44) = arg0;
    M2C_FIELD(p, s16 *, 0x46) = arg1;
    M2C_FIELD(p, s16 *, 0x4C) = arg2;
    M2C_FIELD(p, s16 *, 0x4E) = arg3;
    M2C_FIELD(p, s32 *, 0x50) = 0;
    StringCopy(p + 0x34, &data_02128ea4);
    PanMapViewToTile(arg0, arg1);
}

void func_020b63e8(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    void *CreateSpriteObject();
    M2C_UNK StringCopy(void *, M2C_UNK *);
    extern M2C_UNK data_02128cec, data_02128eb0;
    M2C_UNK *g = &data_02128cec;
    void *p;
    p = CreateSpriteObject(g, arg4);
    M2C_FIELD(p, s16 *, 0x44) = arg0;
    M2C_FIELD(p, s16 *, 0x46) = arg1;
    M2C_FIELD(p, s16 *, 0x4C) = arg2;
    M2C_FIELD(p, s16 *, 0x4E) = arg3;
    M2C_FIELD(p, s32 *, 0x50) = 0;
    StringCopy(p + 0x34, &data_02128eb0);
    PanMapViewToTile(arg0, arg1);
}

void func_020b6444(void *arg0) {
    void ResetEffectSpritePool(void);
    void LoadEffectSpriteSheet(M2C_UNK *, s32);
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    s32 SetAnimatedSpriteFrame(void *, s32);
    M2C_UNK PlaySoundAtTile(M2C_UNK, s32, s32);
    extern void **gCurrentMap;
    extern M2C_UNK data_02128ebc;
    extern M2C_UNK data_02128ec4;
    u8 *u;
    s32 n, x, y;

    u = M2C_FIELD(arg0, u8 **, 0x5c);
    x = u[1] << 4;
    y = u[2] << 4;
    if (u) {
        if (!u) n = 0;
        else n = ((s32)u - (s32)((u8 *)*gCurrentMap + 0x59a4)) / 14;
        n = (n >> 6) + 1;
    } else {
        n = 0;
    }
    y = y - 2;
    if (*((u8 *)*gCurrentMap + n * 140 + 0x67cc) != 0) {
        x = x + 6;
    } else {
        x = x - 6;
    }
    ResetEffectSpritePool();
    LoadEffectSpriteSheet(&data_02128ebc, 0);
    {
        void *p = CreateEffectMapSprite(&data_02128ec4, x, y, 0x30, 0, 0, arg0);
        SetAnimatedSpriteFrame(p, 0);
    }
    {
        u8 *uu = M2C_FIELD(arg0, u8 **, 0x5c);
        PlaySoundAtTile(0x12f, uu[1], uu[2]);
    }
}

void CreateUnitFlareSprite(s32 arg0) {
    void *CreateSpriteObject();
    M2C_UNK PanMapViewToUnit(s32);
    extern M2C_UNK gUnitFlareSpriteClass;
    M2C_FIELD(CreateSpriteObject(&gUnitFlareSpriteClass), s32 *, 0x5C) = arg0;
    PanMapViewToUnit(arg0);
}

#pragma opt_propagation off
void UpdateSmallFlareSprite(void *arg0) {
s32 EaseInterpolate(s32,s32,s32,u16,s32);M2C_UNK func_0208c0d0(void *,u8);
u32 bits=M2C_FIELD(arg0,u32 *,0x48);
u16 top=(u16)(bits>>21),bottom=(u16)((bits<<11)>>21);
s32 a=EaseInterpolate(4,31,0,top,bottom);
s32 b=EaseInterpolate(4,0,0x40000,top,bottom);
func_0208c0d0(arg0,(u8)a);M2C_FIELD(arg0,s32 *,0x40)=b;
}
#pragma opt_propagation reset
void InitFallingFlarePosition(void *arg0) {
    s32 temp_r2;

    temp_r2 = M2C_FIELD(arg0, s32 *, 0x38);
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) (temp_r2 - 0x600);
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_r2;
}

/* Per-frame update of a falling "flare" sprite: eases its y from the descent start
 * to the target the sprite was given (its +0x58 and +0x5C) over the fade duration in
 * its SpriteTimer, and every 16 elapsed frames drops a copy of the flare sheet at
 * the sprite's current position. */
void UpdateFlareSprite(void *sprite) {
    s32 EaseInterpolate(s32, s32, s32, u16, s32);
    M2C_UNK CreateAnimatedMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    M2C_UNK SetAnimatedSpriteFrame(void *, s32);
    extern M2C_UNK gFlareName;
    u16 elapsed;
    u32 bits;
    void *copy;
    bits = M2C_FIELD(sprite, u32 *, 0x48);
    elapsed = (u16)(bits >> 21);
    M2C_FIELD(sprite, s32 *, 0x38) = EaseInterpolate(EASE_LINEAR, M2C_FIELD(sprite, s32 *, 0x58), M2C_FIELD(sprite, s32 *, 0x5C), elapsed, (u16)((bits << 11) >> 21));
    if ((s32)elapsed % 16 != 0) return;
    copy = (void *)CreateAnimatedMapSprite(&gFlareName, 0, 0, 0x10, 0, 0, sprite);
    SetAnimatedSpriteFrame(copy, 2);
    M2C_FIELD(copy, s32 *, 0x34) = M2C_FIELD(sprite, s32 *, 0x34);
    M2C_FIELD(copy, s32 *, 0x38) = M2C_FIELD(sprite, s32 *, 0x38);
}

/* Spawn a falling flare over the task's cell: reset the effect sprite pool, load
 * the flare sheet, place the flare sprite on the task's tile with the descent
 * initialiser as its create callback and the flare update as its per-frame one,
 * then play the flare launch sound there. */
void CreateFallingFlareSprite(void *task) {
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    M2C_UNK SetAnimatedSpriteFrame(void *, s32);
    void InitFallingFlarePosition(void *);
    void UpdateFlareSprite(void *);
    extern M2C_UNK gFallingFlareName, gFallingFlareSprite;
    void *flare;
    ResetEffectSpritePool();
    LoadEffectSpriteSheet(&gFallingFlareName, 0);
    flare = CreateEffectMapSprite(&gFallingFlareSprite, M2C_FIELD(task, s16 *, 0x44), M2C_FIELD(task, s16 *, 0x46), 16, 0, 0, task);
    SetAnimatedSpriteFrame(flare, 1);
    M2C_FIELD(flare, void (**)(void *), 0x68) = InitFallingFlarePosition;
    M2C_FIELD(flare, void (**)(void *), 0x6C) = UpdateFlareSprite;
    PlaySoundAtTile(0x130, M2C_FIELD(task, s16 *, 0x44), M2C_FIELD(task, s16 *, 0x46));
}

/* Spawn the small "flare_s" effect over the task's cell: reset the effect sprite
 * pool, load the flare sheet, place the flare sprite on the task's tile with the
 * small-flare update as its per-frame callback, cancel the cursor animation and
 * play the flare sound there. */
void CreateSmallFlareSprite(void *task) {
    M2C_UNK SetAnimatedSpriteFrame(void *, M2C_UNK);
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, M2C_UNK, s32, s32, void *);
    M2C_UNK CancelMapCursorAnimation();
    extern M2C_UNK gSmallFlareName;
    extern M2C_UNK gSmallFlareSprite;
    void UpdateSmallFlareSprite(void *);
    void *flare;

    ResetEffectSpritePool();
    LoadEffectSpriteSheet(&gSmallFlareName, 0);
    flare = CreateEffectMapSprite(&gSmallFlareSprite, M2C_FIELD(task, s16 *, 0x44), M2C_FIELD(task, s16 *, 0x46), 0x10, 0, 0, task);
    SetAnimatedSpriteFrame(flare, 0);
    M2C_FIELD(flare, void (**)(void *), 0x6C) = UpdateSmallFlareSprite;
    CancelMapCursorAnimation();
    PlaySoundAtTile(0x131, M2C_FIELD(task, s16 *, 0x44), M2C_FIELD(task, s16 *, 0x46));
}

void func_020b6794(void *arg0) {
    M2C_UNK MarkThreatBitmap(s16, s16, M2C_UNK, M2C_UNK, s32, s32);
    M2C_UNK RefreshMapView(void);
    extern void **gCurrentMap;
    void **m = gCurrentMap;
    void *p = arg0;
    u8 v = (u8)M2C_FIELD(*m, u16 *, 0x52A4);
    MarkThreatBitmap(M2C_FIELD(p, s16 *, 0x44), M2C_FIELD(p, s16 *, 0x46), 2, 1, v, 2);
    RefreshMapView();
}

void func_020b67e0(s16 arg0, s16 arg1, M2C_UNK arg2) {
    extern M2C_UNK data_02128b8c;
    void *temp_r0;

    void *CreateSpriteObject();
 temp_r0 = CreateSpriteObject(&data_02128b8c, arg2);
    M2C_FIELD(temp_r0, s16 *, 0x44) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x46) = arg1;
    PanMapViewToTile(arg0, arg1);
}

#pragma opt_propagation off
void func_020b6814(void *p){
s32 func_020b5594(s32,s32,s32);s32 func_020b5e00(s32,s32,void*,...);s32 func_020b5964(s32,void*);s32 func_020b5d94(s32,void*);
s32 a=M2C_FIELD(p,s32*,0x34);
if(M2C_FIELD(p,s16*,0x6e)>0){func_020b5594(M2C_FIELD(p,s32*,0x38),M2C_FIELD(p,s32*,0x3c),0);return;}
switch(M2C_FIELD(p,s16*,0x6c)){
case 0:break;case 1:func_020b5e00(M2C_FIELD(p,s32*,0x38),M2C_FIELD(p,s32*,0x3c),p);return;
case 2:break;case 3:break;case 4:func_020b5964(a,p);return;case 5:break;case 6:case 7:func_020b5d94(a,p);return;default:break;
}}
#pragma opt_propagation reset
s32 CreateUnitPreviewSprite(s32 a,s32 b) {
void GetMapOrderEffectPosition(s32,s16 *);void *CreateSpriteObject();extern M2C_UNK data_02128abc;
s16 xy[2];s32 p;
GetMapOrderEffectPosition(a,xy);p=CreateSpriteObject(&data_02128abc,b);
M2C_FIELD(p,s32 *,0x38)=xy[0];M2C_FIELD(p,s32 *,0x3c)=xy[1];
M2C_FIELD(p,s16 *,0x6c)=(u32)(M2C_FIELD(a,u16 *,2)<<22)>>28;
M2C_FIELD(p,s16 *,0x6e)=M2C_FIELD(a,u8 *,4);
M2C_FIELD(p,s32 *,0x34)=a;return p;
}

s32 CreateTilePreviewSprite(s32 a,s32 b,s32 c) {
extern M2C_UNK data_02128abc;extern void **data_027e0058;void *CreateSpriteObject();
s32 p=CreateSpriteObject(&data_02128abc,c);
void *base;
M2C_FIELD(p,s32 *,0x38)=a;M2C_FIELD(p,s32 *,0x3c)=b;
M2C_FIELD(p,s16 *,0x6c)=1;base=*data_027e0058;
M2C_FIELD(p,s16 *,0x6e)=M2C_FIELD(base+(a+M2C_FIELD(base+b*2,u16 *,0x3758)),u8 *,0x539c)&127;
M2C_FIELD(p,s32 *,0x34)=0;return p;
}

/* Applies the pending damage held by the battle map's target list to every
 * target from index `firstTarget` on: damages the unit on each target tile,
 * pops a "damage" sprite over it, marks the tile, then shakes the screen and
 * plays the explosion sound at the average target position. */
s32 ApplyPendingDamageToTargets(s32 firstTarget, s32 graphicOffset, s32 tileIndex) {
s32 GetTargetCount(void); void *GetTargetPosition(s32);
s32 CreateAnimatedMapSprite(M2C_UNK *,s32,s32,s32,s32,s32,void *);
s32 Divide(s32,s32);
extern void **gCurrentMap; extern M2C_UNK gDamageSpriteName;
s32 n=0, sx=0, sy=0; s32 x,y;
for (;firstTarget<GetTargetCount();firstTarget++) {
u16 id=M2C_FIELD(GetTargetPosition(firstTarget),u16 *,0);
u8 *unit=(u8 *)*gCurrentMap+MAP_UNIT_RECORDS+id*MAP_UNIT_STRIDE;
MapTargetEntry *target=GetTargetPosition(firstTarget);
x=unit[MAP_UNIT_X]; y=unit[MAP_UNIT_Y];
DamageUnitAtTile(x,y,target->value);
M2C_FIELD((void *)CreateAnimatedMapSprite(&gDamageSpriteName,x,y,16,graphicOffset,tileIndex,(void *)7),s32 *,0x3c)=0x8c1;
func_02076910(x,y);
sx+=x; sy+=y; n++;
}
func_02080750(1,20,0); func_02080358(4,0,2,0);
if(n>0) PlaySoundAtTile(0x6d,Divide(sx,n),Divide(sy,n));
else func_0208facc(0x6d);
}

/* Centres the map view on the average tile of the battle targets from index
 * start on (the list GetTargetCount / GetTargetPosition describe). */
s32 PanMapViewToTargetCenter(s16 start) {
    s32 GetTargetCount(void);
    void *GetTargetPosition(s32);
    s32 RuntimeIntDivMod(s32, s32);
    extern void **gCurrentMap;
    BattleMapUnit *unit;
    s32 sumX = 0, sumY = 0, count = 0, i = start;
    u16 id;

    for (; i < GetTargetCount(); i++) {
        id = M2C_FIELD(GetTargetPosition(i), u16 *, 0);
        unit = (BattleMapUnit *)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS) + id;
        sumX += unit->x;
        sumY += unit->y;
        count++;
    }
    if (count > 0) PanMapViewToTile(RuntimeIntDivMod(sumX, count), RuntimeIntDivMod(sumY, count));
}

void UpdateAuroraAimMarker(void *arg0) {
s32 GetObjectTileX(void *); s32 GetObjectTileY(void *);
s32 a; s32 t; u32 bits=M2C_FIELD(arg0,u32 *,0x48);
u16 count=(u16)(bits>>21);
if(count) return;
a=GetObjectTileX(arg0);
t=GetObjectTileY(arg0);
PlaySoundAtTile(0xfc,a,t);
}

s32 ApplyPendingDamage(void *p) {
s32 ApplyPendingDamageToTargets(s32,s32,s32);
s32 b=M2C_FIELD(p,s32 *,0x64);
s32 a=M2C_FIELD(p,s32 *,0x58);
if(!b)return a;
ApplyPendingDamageToTargets(a,b,8);M2C_FIELD(p,s32 *,0x64)=0;return 0;
}

/* Aim the Aurora strike at the remaining targets: each target's unit cell gets
 * an "arura_aim" marker made with the strike's aim graphic, its start delayed by
 * 8 frames per marker, and UpdateAuroraAimMarker as its update callback. */
void AuroraBombardTargets(void *strike) {
    s32 GetTargetCount(void);
    void *GetTargetPosition(s32);
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    extern void **gCurrentMap;
    extern M2C_UNK gAuroraAimName;

    s32 aimGraphic, delay, i;
    void *unit, *marker;

    i = M2C_FIELD(strike, s32 *, 0x58);
    aimGraphic = M2C_FIELD(strike, s32 *, 0x5c);
    delay = 0;
    for (; i < GetTargetCount(); i++) {
        u16 id = M2C_FIELD(GetTargetPosition(i), u16 *, 0);
        unit = *gCurrentMap + MAP_UNIT_RECORDS + id * MAP_UNIT_STRIDE;
        marker = CreateEffectMapSprite(&gAuroraAimName, M2C_FIELD(unit, u8 *, MAP_UNIT_X), M2C_FIELD(unit, u8 *, MAP_UNIT_Y), 16, aimGraphic, 0, strike);
        M2C_FIELD(marker, u32 *, 0x48) = (M2C_FIELD(marker, u32 *, 0x48) & ~1023) | ((u8)delay & 1023);
        M2C_FIELD(marker, void (**)(void *), 0x6c) = UpdateAuroraAimMarker;
        delay += 8;
    }
}

#pragma opt_common_subs off
/* Per-frame update of the Aurora effect: plays its sound cues at fixed frames,
 * applies the staged damage at frame 60, shakes the tile randomly between
 * frames 32 and 90 and spawns a smoke puff. */
void UpdateAuroraEffect(void *effect) {
    M2C_UNK GetObjectTileX(void *);
    M2C_UNK GetObjectTileY(void *);
    M2C_UNK PlaySoundAtTile(s32, s32, s32);
    s32 ApplyPendingDamage(void *);
    u32 NextRandomValue(void);
    M2C_UNK CreateAnimatedMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    extern M2C_UNK gAuroraSmokeName;
    s32 tileX, tileY, power;
    u16 frame;

    power = M2C_FIELD(effect, s32 *, 0x60);
    frame = (u16)(M2C_FIELD(effect, u32 *, 0x48) >> 21);
    tileX = GetObjectTileX(effect);
    tileY = GetObjectTileY(effect) - 1;
    switch (frame) {
    case 0: PlaySoundAtTile(253, tileX, tileY); break;
    case 20: PlaySoundAtTile(254, tileX, tileY); break;
    case 32: PlaySoundAtTile(256, tileX, tileY); break;
    case 90: PlaySoundAtTile(255, tileX, tileY); break;
    case 104: PlaySoundAtTile(258, tileX, tileY); break;
    }
    if (frame == 60) ApplyPendingDamage(effect);
    if ((s32)frame < 32) return;
    if ((s32)frame > 90) return;
    if ((s32)frame % 8) return;
    if (NextRandomValue() & 1) tileX += (s32)NextRandomValue() % 2 + 2;
    else tileX -= (s32)NextRandomValue() % 2 + 2;
    if (NextRandomValue() & 1) tileY += (s32)NextRandomValue() % 2 + 2;
    else tileY -= (s32)NextRandomValue() % 2 + 2;
    PlaySoundAtTile(257, tileX, tileY);
    CreateAnimatedMapSprite(&gAuroraSmokeName, tileX, tileY, 16, power, 1, effect);
}
#pragma opt_common_subs reset
void ApplyAuroraPendingDamage(void) {
    M2C_UNK ApplyPendingDamage();
    ApplyPendingDamage();
}

void func_020b6e58(void *arg0) {
    M2C_UNK ResetEffectSpritePool();
    ResetEffectSpritePool();
    M2C_FIELD(arg0, s16 *, 0x56) = 0;
}

/* Advance the staged Aurora strike: the first three frames load the aim, smoke and
 * damage sprite handles onto the staging object, then the fourth spawns the strike
 * sprite, copies those handles and the power value onto it, wires up its bombard/
 * update/apply callbacks and deletes the staging object. */
void StageAuroraEffect(void *effect) {
    s32 LoadEffectSpriteSheet(M2C_UNK *, s32);
    s32 GetEffectSpritePoolOffset(void);
    void *CreateEffectMapSprite(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    void Sprite_ResumeAnimation(void *);
    extern M2C_UNK gAuroraAimSprite, gAuroraSmokeSprite, gAuroraDamageSprite, gAuroraSprite;
    void AuroraBombardTargets(void *);
    void UpdateAuroraEffect(void *);
    void ApplyAuroraPendingDamage(void);

    s32 stage = M2C_FIELD(effect, s16 *, 0x56);
    s32 x, y, power;
    void *strike;

    power = M2C_FIELD(effect, s16 *, 0x6c);
    x = M2C_FIELD(effect, s32 *, 0x38);
    y = M2C_FIELD(effect, s32 *, 0x3c);
    M2C_FIELD(effect, s16 *, 0x56) = stage + 1;
    switch (stage) {
    case 0:
        M2C_FIELD(effect, s32 *, 0x5c) = LoadEffectSpriteSheet(&gAuroraAimSprite, 0);
        break;
    case 1:
        M2C_FIELD(effect, s32 *, 0x60) = LoadEffectSpriteSheet(&gAuroraSmokeSprite, 1);
        break;
    case 2:
        M2C_FIELD(effect, s32 *, 0x64) = LoadEffectSpriteSheet(&gAuroraDamageSprite, 8);
        break;
    case 3:
        strike = CreateEffectMapSprite(&gAuroraSprite, x, y, 1, GetEffectSpritePoolOffset(), 2, effect);
        M2C_FIELD(strike, s32 *, 0x58) = power;
        M2C_FIELD(strike, s32 *, 0x5c) = M2C_FIELD(effect, s32 *, 0x5c);
        M2C_FIELD(strike, s32 *, 0x60) = M2C_FIELD(effect, s32 *, 0x60);
        M2C_FIELD(strike, s32 *, 0x64) = M2C_FIELD(effect, s32 *, 0x64);
        M2C_FIELD(strike, u32 *, 0x48) = (M2C_FIELD(strike, u32 *, 0x48) & ~1023) | 10;
        M2C_FIELD(strike, void **, 0x68) = AuroraBombardTargets;
        M2C_FIELD(strike, void **, 0x6c) = UpdateAuroraEffect;
        M2C_FIELD(strike, void **, 0x70) = ApplyAuroraPendingDamage;
        Sprite_ResumeAnimation(effect);
        break;
    }
}

void func_020b6f98(s32 arg0, s32 arg1, s16 arg2, M2C_UNK arg3) {
    M2C_UNK PanMapViewToTargetCenter(s16);
    extern M2C_UNK data_02128cac;
    void *temp_r0;

    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
temp_r0 = CreateSpriteObject(&data_02128cac, arg3);
    M2C_FIELD(temp_r0, s32 *, 0x38) = (s32) (arg0 + 1);
    M2C_FIELD(temp_r0, s32 *, 0x3C) = (s32) (arg1 + 1);
    M2C_FIELD(temp_r0, s16 *, 0x6C) = arg2;
    PanMapViewToTargetCenter(arg2);
}

void func_020b6fd8(void *arg0) {
    M2C_UNK PanMapViewToTile(s32, s32);
    ResetEffectSpritePool();
    PanMapViewToTile(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_020b6ff4(void *arg0) {
    M2C_UNK PlaySoundAtTile(s32, s32, s32);
    M2C_UNK CreateAnimatedMapSprite(M2C_UNK *, s32, s32, M2C_UNK, s32, s32, void *);
    extern M2C_UNK data_02128f3c;
    extern M2C_UNK data_02128f48;
    CreateAnimatedMapSprite(&data_02128f48, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), 0x10, LoadEffectSpriteSheet(&data_02128f3c, 0), 0, arg0);
    PlaySoundAtTile(0x105, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_020b7050(void *arg0) {
    M2C_UNK func_0207b7e8(s32);
    extern M2C_UNK data_02128f54;
    extern M2C_UNK data_02128f64;
    s32 temp_r4;

    temp_r4 = CreateAnimatedMapSprite(&data_02128f64, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40), 0x10, LoadEffectSpriteSheet(&data_02128f54, 1), 1, arg0);
    PanMapViewToTile(M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
    func_0207b7e8(temp_r4);
}

void func_020b70b0(void *arg0) {
    extern M2C_UNK data_02128f74;
    extern M2C_UNK data_02128f80;
    s32 temp = LoadEffectSpriteSheet(&data_02128f74, 2);
    CreateAnimatedMapSprite(&data_02128f80, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40), 0x10, temp, 2, arg0);
    PlaySoundAtTile(0x106, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
}

void func_020b710c(void *arg0) {
    s32 LoadEffectSpriteSheet(M2C_UNK *, M2C_UNK);
    M2C_UNK ApplyPendingDamageToTargets(s32, s32, M2C_UNK);
    extern M2C_UNK data_02128f8c;
    ApplyPendingDamageToTargets(M2C_FIELD(arg0, s32 *, 0x44), LoadEffectSpriteSheet(&data_02128f8c, 8), 8);
}

