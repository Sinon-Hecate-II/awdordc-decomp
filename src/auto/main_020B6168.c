/* 32 functions from 0x020B6168 to 0x020B7138 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pad[0x48]; u32 distance:10; u32 flags:22; } RangeEffect;

void func_020b6168(void *arg0) {
    extern void **gCurrentMap;
    M2C_UNK PlaySoundAtTile(M2C_UNK, s32, s32);
    void *func_020b5188(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    s32 func_0208c080(void *, s32);
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

                p = func_020b5188((M2C_UNK *)((u8 *)arg0 + 0x34), x, y, 0x10, 0, 0, arg0);
                func_0208c080(p, 2);
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

/* Step the screen-transition down-counter (func_020b524c -> func_0208c6fc, which
 * fires CloseNarcArchive once the counter wraps to zero), then finalize the current
 * map view and run its registered callbacks (func_020cfd28 -> func_020d0270 +
 * func_020cfd38). */
void func_020b6320(void) {
    M2C_UNK func_020cfd28();
    M2C_UNK func_020b524c();
    func_020b524c();
    func_020cfd28();
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
    func_0207b774(x, y);
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
    func_0207b774(arg0, arg1);
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
    func_0207b774(arg0, arg1);
}

void func_020b6444(void *arg0) {
    void func_020b51dc(void);
    void func_020b5200(M2C_UNK *, s32);
    void *func_020b5188(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    s32 func_0208c080(void *, s32);
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
    func_020b51dc();
    func_020b5200(&data_02128ebc, 0);
    {
        void *p = func_020b5188(&data_02128ec4, x, y, 0x30, 0, 0, arg0);
        func_0208c080(p, 0);
    }
    {
        u8 *uu = M2C_FIELD(arg0, u8 **, 0x5c);
        PlaySoundAtTile(0x12f, uu[1], uu[2]);
    }
}

void func_020b654c(s32 arg0) {
    void *CreateSpriteObject();
    M2C_UNK func_0207b7a4(s32);
    extern M2C_UNK data_02128adc;
    M2C_FIELD(CreateSpriteObject(&data_02128adc), s32 *, 0x5C) = arg0;
    func_0207b7a4(arg0);
}

#pragma opt_propagation off
void func_020b6570(void *arg0) {
s32 EaseInterpolate(s32,s32,s32,u16,s32);M2C_UNK func_0208c0d0(void *,u8);
u32 bits=M2C_FIELD(arg0,u32 *,0x48);
u16 top=(u16)(bits>>21),bottom=(u16)((bits<<11)>>21);
s32 a=EaseInterpolate(4,31,0,top,bottom);
s32 b=EaseInterpolate(4,0,0x40000,top,bottom);
func_0208c0d0(arg0,(u8)a);M2C_FIELD(arg0,s32 *,0x40)=b;
}
#pragma opt_propagation reset
void func_020b65e4(void *arg0) {
    s32 temp_r2;

    temp_r2 = M2C_FIELD(arg0, s32 *, 0x38);
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) (temp_r2 - 0x600);
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_r2;
}

void func_020b65f8(void *arg0) {
    s32 EaseInterpolate(s32, s32, s32, u16, s32);
    M2C_UNK func_020b5134(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    M2C_UNK func_0208c080(void *, s32);
    extern M2C_UNK data_02128ecc;
    u16 count;
    u32 bits;
    void *p;
    bits = M2C_FIELD(arg0, u32 *, 0x48);
    count = (u16)(bits >> 21);
    M2C_FIELD(arg0, s32 *, 0x38) = EaseInterpolate(0, M2C_FIELD(arg0, s32 *, 0x58), M2C_FIELD(arg0, s32 *, 0x5C), count, (u16)((bits << 11) >> 21));
    if ((s32)count % 16 != 0) return;
    p = (void *)func_020b5134(&data_02128ecc, 0, 0, 16, 0, 0, arg0);
    func_0208c080(p, 2);
    M2C_FIELD(p, s32 *, 0x34) = M2C_FIELD(arg0, s32 *, 0x34);
    M2C_FIELD(p, s32 *, 0x38) = M2C_FIELD(arg0, s32 *, 0x38);
}

void func_020b6698(void *arg0) {
    void *func_020b5188(M2C_UNK *, s32, s32, s32, s32, s32, void *);
    M2C_UNK func_0208c080(void *, s32);
    void func_020b65e4(void *);
    void func_020b65f8(void *);
    extern M2C_UNK data_02128ed4, data_02128edc;
    void *p;
    func_020b51dc();
    func_020b5200(&data_02128ed4, 0);
    p = func_020b5188(&data_02128edc, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46), 16, 0, 0, arg0);
    func_0208c080(p, 1);
    M2C_FIELD(p, void (**)(void *), 0x68) = func_020b65e4;
    M2C_FIELD(p, void (**)(void *), 0x6C) = func_020b65f8;
    PlaySoundAtTile(0x130, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46));
}

void func_020b6718(void *arg0) {
    M2C_UNK func_0208c080(void *, M2C_UNK);
    void *func_020b5188(M2C_UNK *, s32, s32, M2C_UNK, s32, s32, void *);
    M2C_UNK CancelMapCursorAnimation();
    extern M2C_UNK data_02128ee4;
    extern M2C_UNK data_02128eec;
    void func_020b6570(void *);
    void *temp_r0;

    func_020b51dc();
    func_020b5200(&data_02128ee4, 0);
    temp_r0 = func_020b5188(&data_02128eec, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46), 0x10, 0, 0, arg0);
    func_0208c080(temp_r0, 0);
    M2C_FIELD(temp_r0, void (**)(void *), 0x6C) = func_020b6570;
    CancelMapCursorAnimation();
    PlaySoundAtTile(0x131, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46));
}

void func_020b6794(void *arg0) {
    M2C_UNK MarkThreatBitmap(s16, s16, M2C_UNK, M2C_UNK, s32, s32);
    M2C_UNK func_020cfd28(void);
    extern void **gCurrentMap;
    void **m = gCurrentMap;
    void *p = arg0;
    u8 v = (u8)M2C_FIELD(*m, u16 *, 0x52A4);
    MarkThreatBitmap(M2C_FIELD(p, s16 *, 0x44), M2C_FIELD(p, s16 *, 0x46), 2, 1, v, 2);
    func_020cfd28();
}

void func_020b67e0(s16 arg0, s16 arg1, M2C_UNK arg2) {
    extern M2C_UNK data_02128b8c;
    void *temp_r0;

    void *CreateSpriteObject();
 temp_r0 = CreateSpriteObject(&data_02128b8c, arg2);
    M2C_FIELD(temp_r0, s16 *, 0x44) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x46) = arg1;
    func_0207b774(arg0, arg1);
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
s32 func_020b689c(s32 a,s32 b) {
void func_020a488c(s32,s16 *);void *CreateSpriteObject();extern M2C_UNK data_02128abc;
s16 xy[2];s32 p;
func_020a488c(a,xy);p=CreateSpriteObject(&data_02128abc,b);
M2C_FIELD(p,s32 *,0x38)=xy[0];M2C_FIELD(p,s32 *,0x3c)=xy[1];
M2C_FIELD(p,s16 *,0x6c)=(u32)(M2C_FIELD(a,u16 *,2)<<22)>>28;
M2C_FIELD(p,s16 *,0x6e)=M2C_FIELD(a,u8 *,4);
M2C_FIELD(p,s32 *,0x34)=a;return p;
}

s32 func_020b68f0(s32 a,s32 b,s32 c) {
extern M2C_UNK data_02128abc;extern void **data_027e0058;void *CreateSpriteObject();
s32 p=CreateSpriteObject(&data_02128abc,c);
void *base;
M2C_FIELD(p,s32 *,0x38)=a;M2C_FIELD(p,s32 *,0x3c)=b;
M2C_FIELD(p,s16 *,0x6c)=1;base=*data_027e0058;
M2C_FIELD(p,s16 *,0x6e)=M2C_FIELD(base+(a+M2C_FIELD(base+b*2,u16 *,0x3758)),u8 *,0x539c)&127;
M2C_FIELD(p,s32 *,0x34)=0;return p;
}

s32 func_020b695c(s32 i, s32 a, s32 b) {
s32 func_0209f8d4(void); void *GetTargetPosition(s32);
s32 func_020b5134(M2C_UNK *,s32,s32,s32,s32,s32,void *);
s32 Divide(s32,s32);
extern void **gCurrentMap; extern M2C_UNK data_02128ef4;
s32 n=0, sx=0, sy=0; s32 x,y;
for (;i<func_0209f8d4();i++) {
u16 id=M2C_FIELD(GetTargetPosition(i),u16 *,0);
u8 *u=(u8 *)*gCurrentMap+0x59a4+id*14;
void *p=GetTargetPosition(i);
x=u[1]; y=u[2];
DamageUnitAtTile(x,y,M2C_FIELD(p,u16 *,2));
M2C_FIELD((void *)func_020b5134(&data_02128ef4,x,y,16,a,b,(void *)7),s32 *,0x3c)=0x8c1;
func_02076910(x,y);
sx+=x; sy+=y; n++;
}
func_02080750(1,20,0); func_02080358(4,0,2,0);
if(n>0) PlaySoundAtTile(0x6d,Divide(sx,n),Divide(sy,n));
else func_0208facc(0x6d);
}

s32 func_020b6a9c(s16 start) {
s32 func_0209f8d4(void); void *GetTargetPosition(s32);s32 func_020720f0(s32,s32);
extern void **gCurrentMap;
s32 x=0,y=0,n=0,i=start;void *p;u16 id;
for(;i<func_0209f8d4();i++){id=M2C_FIELD(GetTargetPosition(i),u16 *,0);p=*gCurrentMap+0x59a4+id*14;x+=M2C_FIELD(p,u8 *,1);y+=M2C_FIELD(p,u8 *,2);n++;}
if(n>0)func_0207b774(func_020720f0(x,n),func_020720f0(y,n));
}

void func_020b6b40(void *arg0) {
s32 GetObjectTileX(void *); s32 GetObjectTileY(void *);
s32 a; s32 t; u32 bits=M2C_FIELD(arg0,u32 *,0x48);
u16 count=(u16)(bits>>21);
if(count) return;
a=GetObjectTileX(arg0);
t=GetObjectTileY(arg0);
PlaySoundAtTile(0xfc,a,t);
}

s32 ApplyPendingDamage(void *p) {
s32 func_020b695c(s32,s32,s32);
s32 b=M2C_FIELD(p,s32 *,0x64);
s32 a=M2C_FIELD(p,s32 *,0x58);
if(!b)return a;
func_020b695c(a,b,8);M2C_FIELD(p,s32 *,0x64)=0;return 0;
}

void func_020b6bac(void *arg0) {
s32 func_0209f8d4(void);void *GetTargetPosition(s32);
void *func_020b5188(M2C_UNK *,s32,s32,s32,s32,s32,void *);
extern void **gCurrentMap;extern M2C_UNK data_02128efc;
s32 v,n,i;void *p,*q;
i=M2C_FIELD(arg0,s32 *,0x58);v=M2C_FIELD(arg0,s32 *,0x5c);n=0;
for(;i<func_0209f8d4();i++){u16 id=M2C_FIELD(GetTargetPosition(i),u16 *,0);p=*gCurrentMap+0x59a4+id*14;
q=func_020b5188(&data_02128efc,M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),16,v,0,arg0);
M2C_FIELD(q,u32 *,0x48)=(M2C_FIELD(q,u32 *,0x48)&~1023)|((u8)n&1023);
M2C_FIELD(q,void (**)(void *),0x6c)=func_020b6b40;n+=8;}
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
    M2C_UNK func_020b5134(M2C_UNK *, s32, s32, s32, s32, s32, void *);
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
    func_020b5134(&gAuroraSmokeName, tileX, tileY, 16, power, 1, effect);
}
#pragma opt_common_subs reset
void func_020b6e4c(void) {
    M2C_UNK ApplyPendingDamage();
    ApplyPendingDamage();
}

void func_020b6e58(void *arg0) {
    M2C_UNK func_020b51dc();
    func_020b51dc();
    M2C_FIELD(arg0, s16 *, 0x56) = 0;
}

void func_020b6e70(void *a){s32 func_020b5200(M2C_UNK *,s32);s32 func_020b51f0(void);void *func_020b5188(M2C_UNK *,s32,s32,s32,s32,s32,void *);void func_01ffa6fc(void *);extern M2C_UNK data_02128f14,data_02128f20,data_02128f2c,data_02128f34;void func_020b6bac(void *);void UpdateAuroraEffect(void *);void func_020b6e4c(void);s32 n=M2C_FIELD(a,s16 *,0x56);s32 x,y,v;void *p;v=M2C_FIELD(a,s16 *,0x6c);x=M2C_FIELD(a,s32 *,0x38);y=M2C_FIELD(a,s32 *,0x3c);M2C_FIELD(a,s16 *,0x56)=n+1;switch(n){case 0:M2C_FIELD(a,s32 *,0x5c)=func_020b5200(&data_02128f14,0);break;case 1:M2C_FIELD(a,s32 *,0x60)=func_020b5200(&data_02128f20,1);break;case 2:M2C_FIELD(a,s32 *,0x64)=func_020b5200(&data_02128f2c,8);break;case 3:p=func_020b5188(&data_02128f34,x,y,1,func_020b51f0(),2,a);M2C_FIELD(p,s32 *,0x58)=v;M2C_FIELD(p,s32 *,0x5c)=M2C_FIELD(a,s32 *,0x5c);M2C_FIELD(p,s32 *,0x60)=M2C_FIELD(a,s32 *,0x60);M2C_FIELD(p,s32 *,0x64)=M2C_FIELD(a,s32 *,0x64);M2C_FIELD(p,u32 *,0x48)=(M2C_FIELD(p,u32 *,0x48)&~1023)|10;M2C_FIELD(p,void **,0x68)=func_020b6bac;M2C_FIELD(p,void **,0x6c)=UpdateAuroraEffect;M2C_FIELD(p,void **,0x70)=func_020b6e4c;func_01ffa6fc(a);break;}}

void func_020b6f98(s32 arg0, s32 arg1, s16 arg2, M2C_UNK arg3) {
    M2C_UNK func_020b6a9c(s16);
    extern M2C_UNK data_02128cac;
    void *temp_r0;

    void *CreateSpriteObject(M2C_UNK *, M2C_UNK);
temp_r0 = CreateSpriteObject(&data_02128cac, arg3);
    M2C_FIELD(temp_r0, s32 *, 0x38) = (s32) (arg0 + 1);
    M2C_FIELD(temp_r0, s32 *, 0x3C) = (s32) (arg1 + 1);
    M2C_FIELD(temp_r0, s16 *, 0x6C) = arg2;
    func_020b6a9c(arg2);
}

void func_020b6fd8(void *arg0) {
    M2C_UNK func_0207b774(s32, s32);
    func_020b51dc();
    func_0207b774(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_020b6ff4(void *arg0) {
    M2C_UNK PlaySoundAtTile(s32, s32, s32);
    M2C_UNK func_020b5134(M2C_UNK *, s32, s32, M2C_UNK, s32, s32, void *);
    extern M2C_UNK data_02128f3c;
    extern M2C_UNK data_02128f48;
    func_020b5134(&data_02128f48, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), 0x10, func_020b5200(&data_02128f3c, 0), 0, arg0);
    PlaySoundAtTile(0x105, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38));
}

void func_020b7050(void *arg0) {
    M2C_UNK func_0207b7e8(s32);
    extern M2C_UNK data_02128f54;
    extern M2C_UNK data_02128f64;
    s32 temp_r4;

    temp_r4 = func_020b5134(&data_02128f64, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40), 0x10, func_020b5200(&data_02128f54, 1), 1, arg0);
    func_0207b774(M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
    func_0207b7e8(temp_r4);
}

void func_020b70b0(void *arg0) {
    extern M2C_UNK data_02128f74;
    extern M2C_UNK data_02128f80;
    s32 temp = func_020b5200(&data_02128f74, 2);
    func_020b5134(&data_02128f80, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40), 0x10, temp, 2, arg0);
    PlaySoundAtTile(0x106, M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
}

void func_020b710c(void *arg0) {
    s32 func_020b5200(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020b695c(s32, s32, M2C_UNK);
    extern M2C_UNK data_02128f8c;
    func_020b695c(M2C_FIELD(arg0, s32 *, 0x44), func_020b5200(&data_02128f8c, 8), 8);
}

