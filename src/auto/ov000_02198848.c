/* 9 functions from 0x02198848 to 0x02199614 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct Unit98 { u8 kind:6; u8 owner:2; u8 x,y,pad; u16 flags; u16 health:7; u16 rest:9; u8 tail[6]; } Unit98;

void func_ov000_02198c08(void) {
    M2C_UNK func_02007f8c(M2C_UNK *, M2C_UNK, s32);
    M2C_UNK func_ov000_0219c508(s32, M2C_UNK);
    extern s32 *gCurrentMap;
    extern M2C_UNK data_ov000_021e0a58;
    func_ov000_0219c508(*gCurrentMap + 0x2840, 0);
    func_ov000_0219c508(*gCurrentMap + 0x2D48, 0);
    func_02007f8c(&data_ov000_021e0a58, 0, 0x508);
}

void func_ov000_02198c60(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_02198c08(void);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void func_ov000_02198848(u8);
    extern s32 *gCurrentMap;
    extern void *data_ov000_021df580;
    extern M2C_UNK data_ov000_021e0a58;
    u8 state;
    u16 saved;
    s32 i;
    u8 idx;
    u8 xi;
    u8 yi;
    u16 row;
    u16 width;

    state = M2C_FIELD(data_ov000_021df580, u8 *, 7);
    saved = M2C_FIELD(*gCurrentMap, u16 *, 0x52B6);
    if (state & 1) {
        return;
    }
    state = (u8)((state & ~1) | 1);
    M2C_FIELD(data_ov000_021df580, u8 *, 7) = state;
    func_ov000_02198c08();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 &&
            func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) == 0) {
            func_ov000_02198848((u8)i);
        }
    }

    idx = M2C_FIELD(*gCurrentMap, u8 *, 0x52D6);
    if (idx != 0) {
        xi = M2C_FIELD(*gCurrentMap, u8 *, 0x59A4 + idx * 14 + 1);
        yi = M2C_FIELD(*gCurrentMap, u8 *, 0x59A4 + idx * 14 + 2);
        row = M2C_FIELD(*gCurrentMap, u16 *, 0x3758 + yi * 2);
        M2C_FIELD(*gCurrentMap, u8 *, 0x2840 + xi + row) = 0;
        row = M2C_FIELD(*gCurrentMap, u16 *, 0x3758 + yi * 2);
        M2C_FIELD(*gCurrentMap, u8 *, 0x2D48 + xi + row) = 0;
        width = M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
        M2C_FIELD(data_ov000_021e0a58, u8 *, (s32)yi * (s32)width + (s32)xi) = 0;
    }

    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = saved;
}

void func_ov000_02198da4(u8 player) {
extern s32 *gCurrentMap;
extern u16 data_ov000_021aeef4[];
extern u8 data_ov000_021b5bfc[];
s32 i, value; Unit98 *unit; s32 kind;
if(!func_ov000_021973f8(14))return;
M2C_FIELD(*gCurrentMap,u16 *,0x52b6)=player;
for(i=data_ov000_021aeef4[player]+1;i<data_ov000_021aeef4[player]+51;i++){
unit=(Unit98 *)(*gCurrentMap+0x59a4+i*14);
if(!(unit->kind))continue;
if(M2C_FIELD(unit,u16 *,4)&8){
s32 map=*gCurrentMap; s32 y=unit->y; s32 x=unit->x; s32 idx; s32 row=M2C_FIELD(map+y*2,u16 *,0x3758); x=(s32)((u8 *)map+x); row+=x; idx=M2C_FIELD(row,u8 *,0x508);
if(!func_020a85dc(((Unit98 *)(map+idx*14+0x59a4))->kind))continue;
}
kind=unit->kind;
if(data_ov000_021b5bfc[kind*112+19]&16)continue;
value=func_ov000_02197434(kind,14);
if(value<25)continue;
if(!func_ov000_02197814(M2C_FIELD(*gCurrentMap,s32 *,0x52d0),unit,1))continue;
value=func_ov000_02197470(value,0,unit->owner);
value=func_ov000_021974bc(value,0,unit);
value=func_ov000_0219763c(value,unit,unit->health);
func_ov000_02197a8c(unit,value,14,100,0,1,0);
}
}

void func_ov000_02198f60(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void func_ov000_02198da4(u8);
    extern s32 *gCurrentMap;
    u16 saved;
    s32 i;
    saved = M2C_FIELD(*gCurrentMap, u16 *, 0x52B6);
    func_ov000_02198c08();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 && func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) == 0) {
            func_ov000_02198da4(i);
        }
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = saved;
}

void func_ov000_02199330(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void func_ov000_02198fec(u8);
    extern s32 *gCurrentMap;
    u16 saved;
    s32 i;
    saved = M2C_FIELD(*gCurrentMap, u16 *, 0x52B6);
    func_ov000_02198c08();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 && func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) == 0) {
            func_ov000_02198fec(i);
        }
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = saved;
}

void func_ov000_021993bc(u8 player) {
extern s32 *gCurrentMap;
extern u16 data_ov000_021aeef4[];
extern u8 data_ov000_021b5bfc[];
s32 value, bonus, i; Unit98 *unit; s32 kind;
if(!func_ov000_021973f8(6))return;
bonus=func_020d0ddc((u8)M2C_FIELD(*gCurrentMap,u16 *,0x52a4));
M2C_FIELD(*gCurrentMap,u16 *,0x52b6)=player;
for(i=data_ov000_021aeef4[player]+1;i<data_ov000_021aeef4[player]+51;i++){
unit=(Unit98 *)(*gCurrentMap+0x59a4+i*14);
if(!(unit->kind))continue;
if(M2C_FIELD(unit,u16 *,4)&8){
s32 map=*gCurrentMap; s32 y=unit->y; s32 x=unit->x; s32 idx; s32 row=M2C_FIELD(map+y*2,u16 *,0x3758); x=(s32)((u8 *)map+x); row+=x; idx=M2C_FIELD(row,u8 *,0x508);
if(!func_020a85dc(((Unit98 *)(map+idx*14+0x59a4))->kind))continue;
}
kind=unit->kind;
value=func_ov000_02197434(kind,6);
if(value<25)continue;
if(!func_ov000_021a98e4(unit->kind) && func_ov000_021a97d0(6,unit->kind)>=50)continue;
value=func_ov000_02197470(value,0,unit->owner);
value=func_ov000_021974bc(value,0,unit);
value=func_ov000_0219763c(value,unit,unit->health);
func_ov000_02197a8c(unit,value,6,100,0,0,bonus);
}
}

void func_ov000_02199588(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_02197990(void);
    void func_ov000_0219798c(void);
    void func_ov000_021993bc(u8);
    extern s32 *gCurrentMap;
    u16 saved;
    s32 i;
    saved = M2C_FIELD(*gCurrentMap, u16 *, 0x52B6);
    func_ov000_02198c08();
    func_ov000_02197990();
    func_ov000_0219798c();
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 && func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) == 0) {
            func_ov000_021993bc(i);
        }
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = saved;
}

