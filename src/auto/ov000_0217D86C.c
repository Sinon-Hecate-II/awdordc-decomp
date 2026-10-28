/* 4 functions from 0x0217D86C to 0x0217E798 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6; u8 flags:2; u8 x,y; u8 rest[11]; } Unit7DC;

s32 func_ov000_0217d86c(void) {
    extern void **gCurrentMap;
    extern void *data_ov000_021df580;
    extern u8 data_ov000_021b5c0f[];
    s32 func_ov000_021a98e4(void);
    s32 func_ov000_021a9014(s32);
    s32 func_ov000_021a8fc0(s16);
    s32 func_ov000_021a98a8(s32);
    void func_01ffada0(u8,u8,u8,s32,s32);

    u16 stflags;
    void *unit;
    s32 count;
    s32 count2;
    s32 count3;
    s32 var4;
    s32 var8;
    s32 varc;
    u16 height;
    u16 width;
    s32 y;
    s32 x;
    signed char *rowp;
    u16 rowoff;
    u8 tile;
    u16 team;
    u8 occ;
    u8 *urec;
    u16 f8;
    u8 ukind;
    u8 skind;
    s32 funcRes;

    stflags = M2C_FIELD(data_ov000_021df580, u16 *, 0xa);
    if (!(( (u32)(stflags << 20) >> 29) & 1)) return 0;
    if (!(( (u32)(stflags << 26) >> 29) & 4)) return 0;

    unit = M2C_FIELD(*gCurrentMap, void **, 0x52d0);
    if (!(data_ov000_021b5c0f[((u32)(M2C_FIELD(unit, u8 *, 0) << 26) >> 26) * 0x70] & 7)) return 0;
    if (func_ov000_021a98e4() != 0) return 0;
    if (((M2C_FIELD(unit, u8 *, 0xb) << 24) >> 31)) return 0;

    func_01ffada0(M2C_FIELD(unit, u8 *, 1), M2C_FIELD(unit, u8 *, 2), 7, 0x6e, 0);

    count = 0;
    count2 = 0;
    count3 = 0;
    var4 = 0;
    var8 = 0;
    varc = 0;

    height = M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
    for (y = 0; y < height; y++) {
        width = M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
        if (width <= 0) continue;
        for (x = 0; x < width; x++) {
            rowp = M2C_FIELD(*gCurrentMap, signed char **, 0x52e8 + y * 4);
            if (rowp[x] < 0) continue;
            rowoff = M2C_FIELD(*gCurrentMap, u16 *, 0x3758 + y * 2);
            tile = M2C_FIELD(*gCurrentMap, u8 *, 0x1420 + rowoff + x);
            if (!func_ov000_021a9014(tile)) continue;
            team = M2C_FIELD(*gCurrentMap, u16 *, 0x52a6);
            if ((tile & 0xe0) != team) continue;
            if ((tile & 0x1f) == 0x11) var4 = 1;
            count++;
            occ = M2C_FIELD(*gCurrentMap, u8 *, rowoff + x);
            if (occ != 0) {
                if (func_ov000_021a8fc0(occ) != 0) {
                    urec = (u8 *)*gCurrentMap + 0x59a4 + (s32)occ * 14;
                    f8 = M2C_FIELD(urec, u16 *, 8);
                    if ((f8 >> 14) == 2) varc++;
                    if (M2C_FIELD(urec, u8 *, 0xb) & 0x80) {
                        count3++;
                        ukind = (u8)(((u32)(M2C_FIELD(urec, u8 *, 0) << 26)) >> 26);
                        if (func_ov000_021a98a8(ukind) != 0) count2++;
                        if (ukind == 6) var8 = 1;
                    }
                }
            }
        }
    }

    if (count == 0) return 0;
    if (var8 == 0) {
        skind = (u8)(((u32)(M2C_FIELD(unit, u8 *, 0) << 26)) >> 26);
        if (skind == 6) {
            M2C_FIELD(unit, u8 *, 0xb) |= 0x80;
            return 1;
        }
    }
    if (var4 == 0) return (M2C_FIELD(unit, u8 *, 0xb) >> 7) & 1;
    if (varc < 3) return 0;
    skind = (u8)(((u32)(M2C_FIELD(unit, u8 *, 0) << 26)) >> 26);
    funcRes = func_ov000_021a98a8(skind);
    if (funcRes != 0) {
        if (count <= 3 && count2 == 0) M2C_FIELD(unit, u8 *, 0xb) |= 0x80;
        else if (count2 <= 1) M2C_FIELD(unit, u8 *, 0xb) |= 0x80;
    } else {
        if (count <= 3 && count3 == 0) M2C_FIELD(unit, u8 *, 0xb) |= 0x80;
        else if (count <= 6 && (count3 - count2) == 0) M2C_FIELD(unit, u8 *, 0xb) |= 0x80;
        else if ((count3 - count2) <= 1) M2C_FIELD(unit, u8 *, 0xb) |= 0x80;
    }
    return (M2C_FIELD(unit, u8 *, 0xb) >> 7) & 1;
}

s32 func_ov000_0217dcd0(void){
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
void func_01ffb554(void *);
s32 func_ov000_02179be0(void);
void func_01ffada0(u8,u8,u8,s32,s32);
void func_01ffb9c4(s8);
s32 func_020d1938(s32);
s32 func_020d273c(u16,s32);
u8 *unit;
s32 p,end,i;
u32 kind;
if(((u32)(**(u8 **)((u8 *)*gCurrentMap+0x52d0)<<26)>>26)!=23)return 0;
func_01ffb554((u8 *)*gCurrentMap+0x2338);
unit=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
func_01ffada0(unit[1],unit[2],((Unit7DC *)unit)->kind,func_ov000_02179be0(),1);
func_01ffb9c4(0x6f);
for(p=1;p<5;p++){
if(!func_020d1938(p))continue;
if(func_020d273c(*(u16 *)((u8 *)*gCurrentMap+0x52a4),p)==1)continue;
i=data_ov000_021aeef4[p]+1;end=data_ov000_021aeef4[p]+0x33;
for(;i<end;i++){
Unit7DC *entry=&((Unit7DC *)((u8 *)*gCurrentMap+0x59a4))[i];
kind=entry->kind;
if(kind && kind==22 && (*(s8 **)((u8 *)*gCurrentMap+0x52e8+entry->y*4))[entry->x]>=0){
func_01ffb554((u8 *)*gCurrentMap+0x1e30);return 1;
}
}}
func_01ffb554((u8 *)*gCurrentMap+0x1e30);return 0;
}

int func_ov000_0217de64(void) { return 0; }

u8 func_ov000_0217e6bc(s32 arg0,s32 arg1){
s32 ManhattanDistance(u8,u8,s16,s16);extern void **gCurrentMap;extern void *data_ov000_021df580;
void *base,*world,*entry;u8 result;
base=(u8 *)*gCurrentMap+0x5000;
if(!M2C_FIELD(base,u8 *,0x2d6))return 1;
base=M2C_FIELD(base,void **,0x2d0);
if(((u32)(M2C_FIELD(base,u8 *,0)<<26)>>26)!=17)return 1;
if(ManhattanDistance(M2C_FIELD(base,u8 *,1),M2C_FIELD(base,u8 *,2),(s16)arg0,(s16)arg1)<=(s32)(M2C_FIELD(data_ov000_021df580,u8 *,5)*2))return 1;
world=*gCurrentMap;entry=(u8 *)world+0x59a4+M2C_FIELD((u8 *)world+0x5000,u8 *,0x2d6)*14;
if(((u32)(M2C_FIELD(entry,u16 *,6)<<25)>>25)<=30)return 1;
if(((u32)(M2C_FIELD(entry,u8 *,10)<<25)>>25)<=10)result=1;else result=0;
return result;
}
