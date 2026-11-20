/* 16 functions from 0x020793F0 to 0x0207A3B0 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct { u16 mode:3; u16 rest:13; } Mode0207;
typedef struct { u8 kind:6; u8 group:2; u8 pad[10]; u8 variant:4; u8 rest:4; } UnitBits7971c;
typedef struct { s32 values[4]; } DrawLookup793f0;
extern const DrawLookup793f0 data_020eb1c0;
extern u8 data_020eb7b8[];

typedef struct {
    s32 x, y, z;
} Vec3;

/* Per-unit draw context (same layout as the one in main_020785B0.c). */
typedef struct { Vec3 pos; void *unit; s32 kind,frame,variant,side,hp,flags; u8 color; u8 pad[3]; s32 extra; u8 mode; u8 pad2[3]; } UnitRenderContext;

#pragma opt_propagation off
void func_020793f0(void *arg0) {
extern M2C_UNK gMapHighlightState;
s32 kind=M2C_FIELD(arg0,s32 *,16);
s32 x=M2C_FIELD(arg0,s32 *,0), y=M2C_FIELD(arg0,s32 *,4), z=M2C_FIELD(arg0,s32 *,8);
DrawLookup793f0 lookup=data_020eb1c0;
s32 frame=lookup.values[M2C_FIELD(&gMapHighlightState,u8 *,2)];
s32 c0=0x7fff,c1=c0,c2=c0,c3=c0,mode;

s32 vx,vy,ex;
s32 *base=(s32 *)(data_020eb7b8+kind*48), *size;
s32 tx,ty,rx,by;u32 alpha;
frame*=104;
if(!M2C_FIELD(arg0,s32 *,44)) mode=0; else { c0=M2C_FIELD(&gMapHighlightState,u16 *,16);c1=M2C_FIELD(&gMapHighlightState,u16 *,18);c2=M2C_FIELD(&gMapHighlightState,u16 *,20);c3=M2C_FIELD(&gMapHighlightState,u16 *,22);mode=2;}
vx=x-384;vy=y-768;ex=x+384;
if(M2C_FIELD(arg0,s32 *,20)==16) {size=base+6;if(size[1]==24)vy=y-1152;}else{size=base+9;base+=3;if(size[1]==32)vy=y-1152;}
tx=(base[0]<<12)+2048;rx=((base[0]+size[0])<<12)+2048;
ty=((base[1]+frame)<<12)+2048;by=((base[1]+frame+size[1])<<12)+2048;
if(M2C_FIELD(arg0,u8 *,40)) { s32 tmp=tx;tx=rx-4096;rx=tmp-4096;}
*(volatile u32 *)0x40004a8=0x6f5049a4;
*(volatile u32 *)0x40004ac=((M2C_FIELD(arg0,u32 *,24)<<5)+0x1200)>>4;
alpha=M2C_FIELD(arg0,u8 *,48)?12:31;
tx=(s32)(tx<<8)>>16;ty=(s32)(ty<<8)>>16;rx=(s32)(rx<<8)>>16;by=(s32)(by<<8)>>16;
vx=(s16)vx;vy=(s16)vy;ex=(s16)ex;y=(s16)y;z=(s16)z;
*(volatile u32 *)0x40004a4=M2C_FIELD(&gMapHighlightState,u32 *,8)|(M2C_FIELD(&gMapHighlightState,u32 *,4)|(mode<<4)|128)|0x2000000|(alpha<<16);
*(volatile u32 *)0x4000500=1;
*(volatile u32 *)0x4000488=(u16)tx|((u16)ty<<16);
*(volatile u32 *)0x4000480=c0;
*(volatile u32 *)0x400048c=(u16)vx|((u16)vy<<16);*(volatile u32 *)0x400048c=(u16)z;
*(volatile u32 *)0x4000488=(u16)tx|((u16)by<<16);
*(volatile u32 *)0x4000480=c1;
*(volatile u32 *)0x400048c=(u16)vx|((u16)y<<16);*(volatile u32 *)0x400048c=(u16)z;
*(volatile u32 *)0x4000488=(u16)rx|((u16)by<<16);
*(volatile u32 *)0x4000480=c2;
*(volatile u32 *)0x400048c=(u16)ex|((u16)y<<16);*(volatile u32 *)0x400048c=(u16)z;
*(volatile u32 *)0x4000488=(u16)rx|((u16)ty<<16);
*(volatile u32 *)0x4000480=c3;
*(volatile u32 *)0x400048c=(u16)ex|((u16)vy<<16);*(volatile u32 *)0x400048c=(u16)z;
*(volatile u32 *)0x4000504=0;
}
#pragma opt_propagation reset
void func_020796b0(M2C_UNK arg0, void *arg1) {
    void func_020799dc(void *, void *, void *, u32);
    extern M2C_UNK data_020eb4e0;
    s32 ptr;
    s32 index;
    s32 flip;
    if (M2C_FIELD(arg1, u8 *, 0x30) == 1) return;
    if (M2C_FIELD(arg1, s32 *, 0x20) < 1) return;
    if (M2C_FIELD(arg1, s32 *, 0x20) >= 10) return;
    index = M2C_FIELD(arg1, u32 *, 0x20);
    if (M2C_FIELD(arg1, s32 *, 0x14) == 0x18) index += 0x1A;
    ptr = index * 14 + (s32)&data_020eb4e0;
    flip = (s32)(M2C_FIELD(arg1, s32 *, 0x18) & 7) >= 4;
    func_020799dc((void *)arg0, (void *)ptr, (void *)(ptr + 6), (flip << 5) + 0x1400);
}

#pragma opt_propagation off
/* Pick the status icon that belongs to a unit (by side/variant in mode 2, else by
   its status flags, with a pseudo-random pick from the candidates) and draw it as
   a 3D quad at the unit's position. */
void DrawUnitStatusIcon(Vec3 *pos, UnitRenderContext *ctx) {
    void func_020799dc(void *, void *, void *, u32);
    extern Mode0207 gMapConfig;
    extern M2C_UNK gFrameCounter;
    extern M2C_UNK data_020eb4ec;
    extern M2C_UNK data_020eb4e0;
    s32 mode2Icons[16];
    s32 flagIcons[16];
    void *unit;
    s32 sideType;
    s32 count;
    s32 icon;
    s32 rotation;
    s32 count2;
    s32 flags;
    s32 index;
    s32 frame;
    s32 offset;
    s32 style;
    void *iconPtr;
    s32 side;
    s32 flip;

    if (ctx->mode == 1) return;
    icon = (u8)gMapConfig.mode;
    if (icon == 2) {
        icon = 0;
        unit = ctx->unit;
        sideType = ((UnitBits7971c *)unit)->group;
        count = icon;
        if (sideType == 3) {
            mode2Icons[0] = 0x14; count = icon + 1;
        }
        switch (((UnitBits7971c *)unit)->variant) {
        case 0: mode2Icons[count++] = 0x16; break;
        case 1: mode2Icons[count++] = 0x17; break;
        case 8: mode2Icons[count++] = 0x18; break;
        case 6: mode2Icons[count++] = 0x19; break;
        default: break;
        }
        if (count == 0) goto chosen;
        index = ((u32)gFrameCounter >> 6) % count;
        icon = mode2Icons[index];
    } else {
        icon = 0;
        side = ctx->side;
        count2 = icon;
        if (side > 0) { flagIcons[0] = 0x11; count2 = icon + 1; }
        flags = ctx->flags;
        if (flags != 0) {
            if (flags & 0x02) flagIcons[count2++] = 0x0A;
            if (flags & 0x04) flagIcons[count2++] = 0x0B;
            if (flags & 0x08) flagIcons[count2++] = 0x0C;
            if (flags & 0x800) flagIcons[count2++] = 0x15;
            if (flags & 0x80) flagIcons[count2++] = 0x0D;
            if (flags & 0x40) flagIcons[count2++] = 0x0E;
            if (flags & 0x20) flagIcons[count2++] = 0x0F;
            if (flags & 0x100) flagIcons[count2++] = 0x10;
        }
        if (count2 == 0) goto chosen;
        index = ((u32)gFrameCounter >> 6) % count2;
        icon = flagIcons[index];
        if (icon == 0x11) {
            if (side > 0) {
                count2 = side - 1;
                icon += count2;
            }
            if (flags & 0x400) icon += 1;
        }
    }
chosen:
    if (icon == 0) return;
    frame = ctx->frame;
    if (frame == 0x18) icon += 0x1A;
    offset = icon * 0x0E;
    iconPtr = (u8 *)&data_020eb4e0 + offset;
    style = ((u8 *)&data_020eb4ec)[offset];

    switch (style) {
    case 0:
        flip = ctx->variant & 7;
        flip = flip >= 4 ? 1 : 0;
        flip <<= 5;
        rotation = flip + 0x1400;
        break;
    case 1:
        rotation = (ctx->variant << 5) + 0x1200;
        break;
    }
    func_020799dc(pos, iconPtr, (void *)((u8 *)iconPtr + 6), (u32)rotation);
}
void func_020799dc(void *arg0, void *arg1, void *arg2, u32 arg3) {
#pragma opt_propagation on
extern M2C_UNK gMapHighlightState;
s16 x=((s16*)arg1)[0], y=((s16*)arg1)[1];
s16 h=((s16*)arg2)[1], w=((s16*)arg2)[0];
s32 px=((s32*)arg0)[0], py=((s32*)arg0)[1];
s32 vx=(s16)(px-192), vy=(s16)(py-384);
s32 tx=(s32)(((x<<12)+2048)<<8)>>16, ty=(s32)(((y<<12)+2048)<<8)>>16;
s32 by=(s32)((((y+h)<<12)+2048)<<8)>>16, rx=(s32)((((x+w)<<12)+2048)<<8)>>16;
s32 ey=(s16)py, ex=(s16)(px+192);

(*(volatile u32*)0x40004a8)=0x6d504000; (*(volatile u32*)0x40004ac)=arg3>>4;
(*(volatile u32*)0x40004a4)=M2C_FIELD(&gMapHighlightState,u32*,8)|(M2C_FIELD(&gMapHighlightState,u32*,4)|0xc0)|0x21f0000;
(*(volatile u32*)0x4000480)=0x7fff; (*(volatile u32*)0x4000500)=1;
(*(volatile u32*)0x4000488)=(u16)tx|((u16)ty<<16);
(*(volatile u32*)0x400048c)=(u16)vx|((u16)vy<<16); (*(volatile u32*)0x400048c)=0x831;
(*(volatile u32*)0x4000488)=(u16)tx|((u16)by<<16);
(*(volatile u32*)0x400048c)=(u16)vx|((u16)ey<<16); (*(volatile u32*)0x400048c)=0x831;
(*(volatile u32*)0x4000488)=(u16)rx|((u16)by<<16);
(*(volatile u32*)0x400048c)=(u16)ex|((u16)ey<<16); (*(volatile u32*)0x400048c)=0x831;
(*(volatile u32*)0x4000488)=(u16)rx|((u16)ty<<16);
(*(volatile u32*)0x400048c)=(u16)ex|((u16)vy<<16); (*(volatile u32*)0x400048c)=0x831;
(*(volatile u32*)0x4000504)=0;
}
#pragma scheduling reset
void func_02079b64(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 0x80;
    M2C_FIELD(arg0, s32 *, 0x60) = 0x180;
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = 0x10;
}

void func_02079b88(void *arg0) {
    void Sprite_ResumeAnimation(void *);
    M2C_FIELD(arg0, s16 *, 0x6C)++;
    if (M2C_FIELD(arg0, s16 *, 0x6C) < M2C_FIELD(arg0, s16 *, 0x6E)) return;
    Sprite_ResumeAnimation(arg0);
}

void func_02079bb0(M2C_UNK arg0) {
    M2C_UNK func_02079bc4(M2C_UNK, M2C_UNK);
    func_02079bc4(0x10, arg0);
}

M2C_UNK func_02079bc4(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK PlaySoundEffect(s32);
    void *CreateSpriteObject();
    extern M2C_UNK data_02100ab0;
    PlaySoundEffect(0x82);
    M2C_FIELD(CreateSpriteObject(&data_02100ab0, arg1), s16 *, 0x6E) = arg0;
}

void func_02079bf0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 0x180;
    M2C_FIELD(arg0, s32 *, 0x60) = 0x80;
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = 0x10;
}

void func_02079c14(void *arg0) {
    void Sprite_ResumeAnimation(void *);
    M2C_FIELD(arg0, s16 *, 0x6C)++;
    if (M2C_FIELD(arg0, s16 *, 0x6C) < M2C_FIELD(arg0, s16 *, 0x6E)) return;
    Sprite_ResumeAnimation(arg0);
}

void func_02079c3c(M2C_UNK arg0) {
    M2C_UNK func_02079c50(M2C_UNK, M2C_UNK);
    func_02079c50(0x10, arg0);
}

M2C_UNK func_02079c50(M2C_UNK arg0, M2C_UNK arg1) {
    void *CreateSpriteObject();
    extern M2C_UNK data_02100a88;
    M2C_FIELD(CreateSpriteObject(&data_02100a88, arg1), s16 *, 0x6E) = arg0;
}

void MapTileToScreen(s32 arg0, s32 arg1) {
    void func_02079c90();
    func_02079c90((arg0 * 0x300) + 0x180, (arg1 * 0x300) + 0x180);
}

#pragma opt_common_subs off
void func_02079c90(s32 arg0,s32 arg1,s32 *arg2) {
s32 Divide(s32,s32);
M2C_UNK ProjectPoint(Vec3 *,void *);
extern s32 *gCurrentMap;
Vec3 pos; void *base;
base=(void *)(*gCurrentMap+0x6EF8);
pos.x=arg0;pos.y=arg1;pos.z=0;
ProjectPoint(&pos,base+0x70);
arg2[0]=Divide((arg2[0]+0x1000)<<8,0x2000);
arg2[1]=Divide((0x1000-arg2[1])*0xC0,0x2000);
}
#pragma opt_common_subs reset
/* Convert a point on the main screen (up to 256x192) to the map's fixed-point
 * position (0x300 units per cell), unprojected through the map view's matrix
 * and offset by the view's world origin. */
void ScreenToMapFixedPoint(s32 screenX, s32 screenY, Vec3 *out) {
    M2C_UNK MTX_Apply33(Vec3 *, void *, Vec3 *);
    s32 Divide(s32, s32);
    extern s32 *gCurrentMap;
    Vec3 pos;
    void *view;
    view = (void *)(*gCurrentMap + MAP_VIEW_ZOOM);
    pos.x = Divide((screenX << 12) - 0x80000, 0x80);
    pos.y = -Divide((screenY << 12) - 0x60000, 0x60);
    pos.z = 0;
    MTX_Apply33(&pos, view + MAP_VIEW_MATRIX, &pos);
    out->x = M2C_FIELD(view, s32 *, MAP_VIEW_ORIGIN) + pos.x;
    out->y = M2C_FIELD(view, s32 *, MAP_VIEW_ORIGIN + 4) + pos.y;
    out->z = M2C_FIELD(view, s32 *, MAP_VIEW_ORIGIN + 8) + pos.z;
}

#pragma opt_propagation off
void Map_SubmitCellQuads(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, signed int a5) {
    extern u8 gTerrainClassFlags[];
    extern M2C_UNK gMapHighlightState;
    extern u8 gMapCellCornerColors[];
    extern u16 data_020eb1a8[];
    extern u16 data_020eb1d0[];
    extern u16 data_020eb1e0[];
    s32 func_0207fa64(s32);
    volatile s16 offsets[2];
    volatile u16 raw[2];
    s32 mode = 0;
    u16 c0 = 0x7fff, c1 = c0, c2 = c0, c3 = c0;
    s32 u0 = (a0 << 4) * 0x30;
    s32 v0 = (a1 << 4) * 0x30;
    s32 z = mode;
    u32 low;
    s32 vx, vy, ex, ey;
    s32 tx, ty, rx, by;
    u32 flags = M2C_FIELD(gTerrainClassFlags + a2 * 8, u32 *, 0);
    struct { u32 flags; u8 x, y, palette, offset; } *entry = (void *)(gTerrainClassFlags + a2 * 8);
    s32 x = entry->x;
    s32 y = entry->y;
    u32 sign = flags & 0x80000000;
    u32 h = entry->palette + a3;
    s32 k = entry->offset;

    low = flags & 0xffff;
    if (k != 0) {
        u32 v = func_0207fa64(k);
        u16 offsetX, offsetY;
        raw[0] = v;
        raw[1] = v >> 16;
        offsetX = raw[0];
        offsetY = raw[1];
        offsets[0] = offsetX;
        offsets[1] = offsetY;
        x += offsets[0];
        y += offsets[1];
    }
    switch (a4) {
    case 0:
    case 1:
        if (low & 0x40) {
            *(volatile u32 *)0x40004ac = (((u32)(M2C_FIELD(&gMapHighlightState, u8 *, 0) + a3) << 5) + 0xc00) >> 4;
        } else if ((low & 0x80) && M2C_FIELD(&gMapHighlightState, u8 *, 1) && a3 && a3 < 0x10) {
            *(volatile u32 *)0x40004ac = (((u32)(a3 - 1) << 5) + 0x1000) >> 4;
        } else {
            *(volatile u32 *)0x40004ac = (h << 5) >> 4;
        }
        break;
    case 2:
        *(volatile u32 *)0x40004ac = ((h << 5) + 0x800) >> 4;
        break;
    case 3:
        *(volatile u32 *)0x40004ac = ((h << 5) + 0x400) >> 4;
        break;
    }
    if (a4 != 0) {
        mode = 2;
        c0 = M2C_FIELD(&gMapHighlightState, u16 *, 0x10);
        c1 = M2C_FIELD(&gMapHighlightState, u16 *, 0x12);
        c2 = M2C_FIELD(&gMapHighlightState, u16 *, 0x14);
        c3 = M2C_FIELD(&gMapHighlightState, u16 *, 0x16);
    } else {
        if (entry->flags & 0x20) {
            u16 d = (a5 | (a5 << 5)) | (a5 << 10);
            if (sign != 0) {
                if (sign == 0x80000000) {
                    const u8 (*cells)[42] = (const u8 (*)[42])gMapCellCornerColors;
                    c0 = (u16)(data_020eb1a8[0x14] - d);
                    c1 = (u16)(data_020eb1d0[cells[a0][a1+1]] - d);
                    c3 = c0;
                    c2 = (u16)(data_020eb1d0[cells[a0+1][a1+1]] - d);
                }
            } else {
                const u8 *row0 = gMapCellCornerColors + a0 * 42;
                s32 i1 = (a0 + 1) * 0x2a;
                c0 = (u16)(data_020eb1e0[row0[a1]] - d);
                c1 = (u16)(data_020eb1e0[row0[a1 + 1]] - d);
                c3 = (u16)(data_020eb1e0[gMapCellCornerColors[i1 + a1]] - d);
                c2 = (u16)(data_020eb1e0[gMapCellCornerColors[i1 + a1 + 1]] - d);
            }
        } else {
            u16 d = (a5 | (a5 << 5)) | (a5 << 10);
            c0 = (u16)(0x7fff - d);
            c1 = c0;
            c2 = c0;
            c3 = c0;
        }
    }
    if (sign != 0) {
        if (sign == 0x80000000) {
            z = ((a1 << 12) >> 8) + 0x430;
            tx = x * 0x18000 + 0x800;
            ty = y * 0x18000 + 0x800;
            vx = u0;
            ex = u0 + 0x300;
            rx = (x + 1) * 0x18000 + 0x800;
            by = (y + 2) * 0x18000 + 0x800;
            vy = v0 - 0x300;
            ey = v0 + 0x300;
        }
    } else {
        z = ((a1 << 12) >> 8) + 0x20;
        tx = x * 0x18000 + 0x800;
        ty = y * 0x18000 + 0x800;
        vx = u0;
        ex = u0 + 0x300;
        rx = (x + 1) * 0x18000 + 0x800;
        by = (y + 1) * 0x18000 + 0x800;
        vy = v0;
        ey = v0 + 0x300;
    }
    if (entry->flags & 0x100) {
        *(volatile u32 *)0x40004a4 = M2C_FIELD(&gMapHighlightState, u32 *, 8) |
            (M2C_FIELD(&gMapHighlightState, u32 *, 4) | (mode << 4) | 0x80) | 0x1140000;
    } else {
        *(volatile u32 *)0x40004a4 = M2C_FIELD(&gMapHighlightState, u32 *, 8) |
            (M2C_FIELD(&gMapHighlightState, u32 *, 4) | (mode << 4) | 0x80) | 0x1f0000;
    }
    *(volatile u32 *)0x4000500 = 1;
    *(volatile u32 *)0x4000488 = ((u32)(u16)(s16)(ty >> 8) << 16) | (u32)(u16)(s16)(tx >> 8);
    *(volatile u32 *)0x4000480 = c0;
    *(volatile u32 *)0x400048c = ((u32)(u16)(s16)vy << 16) | (u32)(u16)(s16)vx;
    *(volatile u32 *)0x400048c = (u16)(s16)z;
    *(volatile u32 *)0x4000488 = ((u32)(u16)(s16)(by >> 8) << 16) | (u32)(u16)(s16)(tx >> 8);
    *(volatile u32 *)0x4000480 = c1;
    *(volatile u32 *)0x400048c = ((u32)(u16)(s16)ey << 16) | (u32)(u16)(s16)vx;
    *(volatile u32 *)0x400048c = (u16)(s16)z;
    *(volatile u32 *)0x4000488 = ((u32)(u16)(s16)(by >> 8) << 16) | (u32)(u16)(s16)(rx >> 8);
    *(volatile u32 *)0x4000480 = c2;
    *(volatile u32 *)0x400048c = ((u32)(u16)(s16)ey << 16) | (u32)(u16)(s16)ex;
    *(volatile u32 *)0x400048c = (u16)(s16)z;
    *(volatile u32 *)0x4000488 = ((u32)(u16)(s16)(ty >> 8) << 16) | (u32)(u16)(s16)(rx >> 8);
    *(volatile u32 *)0x4000480 = c3;
    *(volatile u32 *)0x400048c = ((u32)(u16)(s16)vy << 16) | (u32)(u16)(s16)ex;
    *(volatile u32 *)0x400048c = (u16)(s16)z;
    *(volatile u32 *)0x4000504 = 0;
}
#pragma opt_propagation reset
