/* 7 functions from 0x020D6398 to 0x020D6E0C (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 v[4]; } MenuBounds;
extern const MenuBounds data_020f4e88;
extern u8 data_02168f14[16];

s32 func_020d6398(s32 x, s32 y) {
    extern void **gCurrentMap;
    s32 func_020a85b8(s32);
    u8 func_020ba790(s32, s32);
    s32 func_020a7074(void *, void *);
    u8 func_020d273c(s32, s32);

    u8 *base = *gCurrentMap;
    u16 rowOff = *(u16 *)(base + y * 2 + 0x3758);
    u8 unitId = base[x + rowOff];
    s8 *rowPtr;
    s8 cell;
    u8 *selected;
    u8 *unitBase;
    u8 *unit;
    s32 idx0, idx1, selectedId, kind;

    if (*(u16 *)(base + 0x52a8) != (base[0x52d4] & 0xc0)) return 0;

    rowPtr = *(s8 **)(base + y * 4 + 0x52e8);
    cell = rowPtr[x];
    if (cell < 0) goto bad;
    if (cell > 0x6e) goto bad;

    if (unitId == 0) return 1;
    if (unitId == base[0x52d6]) return 0;

    if (func_020ba790(x, y) == 1) return 1;

    selected = *(u8 **)(base + 0x52d0);
    unitBase = base + 0x59a4;
    unit = unitBase + unitId * 14;
    if (func_020a7074(selected, unit) == 1) return 1;

    kind = selected[0] & 0x3f;
    if (func_020a85b8(kind) == 0) return 0;

    if (unit == (u8 *)0) idx1 = 0;
    else idx1 = (unitId >> 6) + 1;

    if (selected == (u8 *)0) idx0 = 0;
    else {
        selectedId = (selected - unitBase) / 14;
        idx0 = (selectedId >> 6) + 1;
    }

    if (func_020d273c(idx0, idx1) == 0) return 1;
    return 0;

bad:
    return 0;
}

s32 func_020d66fc(s8 *arg0) {
    s32 value;
    while ((value = *arg0) != 4 && value != -1) {
        if (value == 10) return 1;
        arg0++;
    }
    return 0;
}

void func_020d672c(void) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02080cfc(s32, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    s32 func_020e3218(M2C_UNK *);
    extern M2C_UNK data_0212beec;
    extern M2C_UNK data_0212bef8;
    extern M2C_UNK data_0212bf08;
    extern u16 **gCur3DSpriteEngine;
    func_0200bc5c(&data_0212beec);
    func_02080cfc(func_020e3218(&data_0212bef8), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x2A00);
    func_0208116c(&data_0212bf08, 0x320, 0x20);
}

void func_020d6778(s32 mode) {
 extern void **gCurrentMap;
 void func_020d87d8(void); s32 func_020d849c(void *);
 void func_020d6a20(s32,s32,u32,u32); void func_020d759c(s32,s32,s32);
 void func_020d7b04(s32,s32,s32,void *);void func_020d7bc8(s32,s32,s32,void *);
 void func_020d8084(s32,s32,u32,u32,s32,void *);void func_020d6e0c(s32,s32,s32,s32);
 u32 enabled=(u32)(*(u16 *)data_02168f14<<21)>>31;
 MenuBounds bounds=data_020f4e88;
 u8 *unit=0; u8 *map; s16 b; s32 side; u32 y; s16 a,kind; u32 x,id;
 if(!enabled)return;
 func_020d87d8();map=*gCurrentMap;
 y=(u32)(*(u16 *)(map+0x52e6)<<16)>>25;
 x=(u32)(*(u16 *)(map+0x52e6)<<23)>>25;
 id=map[*(u16 *)(map+0x3758+y*2)+x];
 if(id)unit=map+0x59a4+id*14;
 else {u8 *p=*(u8 **)(map+0x52d0);if(p && ((u32)(p[0]<<26)>>26) && p[1]==x && p[2]==y)unit=p;}
 kind=func_020d849c(unit);
 map=*gCurrentMap;a=*(s16 *)(map+0x52e4);
 if(a<=bounds.v[0]) {b=bounds.v[1];side=0;}else {b=bounds.v[3];side=1;}
 switch(mode) {case 0:func_020d6a20(2,2,*(u16 *)(map+0x52a2),data_02168f14[3]);break;case 1:func_020d759c(a,b,side);break;case 2:break;}
 switch(kind) {case 2:func_020d7b04(a,b,side,unit);case 1:func_020d7bc8(a,b,side,unit);case 0:func_020d8084(a,b,x,y,side,unit);break;}
 func_020d6e0c(a,b,side,kind);
}

void func_020d694c(s32 arg0, s32 arg1, s32 arg2) {
M2C_UNK func_01ffaacc(u16,u16,u16,M2C_UNK *,s32);
extern M2C_UNK data_027e0084;extern u16 **gCur3DSpriteEngine;
do {
func_01ffaacc((u16)(arg0&511),(u16)(arg1&255),(u16)((((0x150 >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine<<17)>>30))&1023)|0x9000)+((((arg2%10)*2) >> ((u32)(*(u16 *)*(volatile u32 *)gCur3DSpriteEngine<<17)>>30))&1023)),&data_027e0084,8);
arg0-=8;arg2/=10;
}while(arg2);
}

void func_020d6a20(s32 a, s32 b, u32 c, u32 d) {
    s32 func_020e31e0(void);
    (void)a; (void)b; (void)c; (void)d;
    if (func_020e31e0() != 0) {
        return;
    }
    return;
}

