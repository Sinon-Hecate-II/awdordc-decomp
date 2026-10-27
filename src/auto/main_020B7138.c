/* 17 functions from 0x020B7138 to 0x020B8078 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pad[0x44]; u32 tile:16; u32 flags:16; } SpriteTile;

void func_020b7138(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *func_01ffa42c(M2C_UNK *, s32);
    extern M2C_UNK data_02128da4;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_02128da4, arg5);
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg2;
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x44) = arg4;
}

/* Rasterize a mode-selected line into the path grid, install its endpoint as
 * the next path cell, and spawn the entities along it. */
void func_020b7178(void *task) {
    M2C_UNK func_02076910(u32, u32);
    M2C_UNK func_0207b774(u32, u32);
    M2C_UNK func_0208fb0c(M2C_UNK, u32, u32);
    s32 func_020b5200(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020b695c(s32, s32, M2C_UNK);
    extern void **gCurrentMap;
    extern M2C_UNK data_02128f94;
    u32 y;
    u32 mode;
    s32 spawnIndex;
    void *temp_r0;
    u32 x;

    x = M2C_FIELD(task, u32 *, 0x5C);
    y = M2C_FIELD(task, u32 *, 0x60);
    mode = M2C_FIELD(task, u32 *, 0x64);
    spawnIndex = M2C_FIELD(task, s32 *, 0x58);
    func_0208fb0c(0x104, x, y);
    switch (mode) {
    default:
        break;
    case 1:
    case 3:
loop_8:
        if (y < (u32) M2C_FIELD(*gCurrentMap, u16 *, 0x5146)) {
            func_02076910(x, y);
            y += 1;
            goto loop_8;
        }
        break;
    case 0:
loop_11:
        if ((x != 0) && (y < (u32) M2C_FIELD(*gCurrentMap, u16 *, 0x5146))) {
            func_02076910(x, y);
            x -= 1;
            y += 1;
            goto loop_11;
        }
        break;
    case 2:
loop_15:
        temp_r0 = *gCurrentMap;
        if ((x < (u32) M2C_FIELD(temp_r0, u16 *, 0x5144)) && (y < (u32) M2C_FIELD(temp_r0, u16 *, 0x5146))) {
            func_02076910(x, y);
            x += 1;
            y += 1;
            goto loop_15;
        }
        break;
    }
    func_0207b774(x, y);
    func_020b695c(spawnIndex, func_020b5200(&data_02128f94, 8), 8);
}

void func_020b7294(s32 arg0, s32 arg1, u32 arg2, s32 arg3, void *arg4) {
 M2C_UNK func_0207b774(u32,u32); M2C_UNK func_0207b7e8(void *); M2C_UNK func_0208fb0c(M2C_UNK,u32,u32);
 u32 func_020a4ab0(u32);
 void *func_020b5188(M2C_UNK *,s32,s32,s32,s32,s32,void *);
 void func_020b51dc(void); s32 func_020b51f0(void);
 extern M2C_UNK data_02128f9c,data_02128fa4,data_02128fac;
 s32 t,t2; u32 tile; s32 x,y; void *p,*q;
 tile=func_020a4ab0(arg2); x=0; y=0;
 func_020b51dc(); t=func_020b5200(&data_02128f9c,0);
 switch(arg2) {case 0:x=-132;y=132;break;case 1:y=176;break;case 2:x=132;y=x;break;case 3:y=172;break;default:break;}
 p=func_020b5188(&data_02128fa4,x+arg0*16,y+arg1*16,48,t,0,arg4);
 if(p) {
 ((SpriteTile *)p)->tile=(u16)(tile+0x4000);
 M2C_FIELD(p,s32 *,0x58)=arg3; M2C_FIELD(p,s32 *,0x5c)=arg0; M2C_FIELD(p,s32 *,0x60)=arg1; M2C_FIELD(p,u32 *,0x64)=arg2; M2C_FIELD(p,void (**)(void *),0x68)=func_020b7178; arg4=p;
 }
 t2=func_020b51f0();
 switch(arg2) {case 0:x=-12;y=12;break;case 1:x=0;y=16;break;case 2:x=12;y=x;break;case 3:x=0;y=12;break;default:break;}
 q=func_020b5188(&data_02128fac,x+arg0*16,y+arg1*16,32,t2,1,arg4);
 if(q) {func_0208fb0c(0x103,arg0,arg1+2); ((SpriteTile *)q)->tile=(u16)tile;}
 func_0207b774(arg0,arg1+2);func_0207b7e8(q);
}

/* Draw a centered gauge and two flanking icon sprites for the object. */
void func_020b7724(void *obj) {
void func_0209b67c(u16,s32,u16,u16,s32);
void func_01ffaacc(s32,s32,u16,void *,s32);
extern void *gCur3DSpriteEngine; extern u8 data_027e0064[];
s32 size=M2C_FIELD(obj,s32 *,0x34);
func_0209b67c((u16)((256-size)/2),0x58,(u16)size,(u16)(0xd000|((0x39c >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30))&0x3ff)),11);
func_01ffaacc(0x38,0x58,(u16)(0xb000|((0x35c >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30))&0x3ff)),data_027e0064,11);
func_01ffaacc(0x10b8,0x58,(u16)(0xb000|((0x35c >> ((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30))&0x3ff)),data_027e0064,11);
}

void func_020b7824(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_01ffa574(s32);
    extern void *gCur3DSpriteEngine;
    func_01ffa574(M2C_FIELD(arg0, s32 *, 0x38));
    func_01ffa574(M2C_FIELD(arg0, s32 *, 0x3C));
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
}

void func_020b7860(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    extern u16 *data_02101e84;
    extern void *data_02101e88;
    if (*data_02101e84 & 0xC0B) {
        func_01ffa6fc(arg0);
        return;
    }
    if (M2C_FIELD(data_02101e88, u8 *, 0x14) == 0) return;
    func_01ffa6fc(arg0);
}

void func_020b78ac(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02128d2c;
    func_01ffa3dc(&data_02128d2c, 7);
}

#pragma opt_scalarize off
#pragma opt_decomposeaggregates off
#pragma cplusplus on
inline void func_020b7b54_clear(u16 &r) {
    r &= ~0xC0;
}
#pragma cplusplus on
extern "C" void func_020b7b54(void) {
    extern void *gCur3DSpriteEngine;
    u16 *volatile p;
    p = (u16 *)((s8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) + 0x12);
    *p = (u16)(*p & ~0xC0);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x51) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x52) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x53) = 0;
}
#pragma cplusplus off
void func_020b7bbc(void) {
    s32 func_0208c528(s32);
    void func_020b78c4(void);
    void func_020b7b54(void);
    extern M2C_UNK data_02128ffc, data_02129004;
    s32 temp_r4;
    s32 resource;
    s32 size = 0x6B80;
    temp_r4 = func_0208c528(7);
    func_0208c5fc(func_020e3218(&data_02128ffc), 0x6B80, 0xB);
    resource = func_020e3218(&data_02129004);
    func_0208bddc(temp_r4, resource, size, 0xB, 0);
    M2C_FIELD(temp_r4, s32 *, 0x44) |= 0x380000;
    M2C_FIELD(temp_r4, void (**)(void), 0x6C) = func_020b78c4;
    M2C_FIELD(temp_r4, void (**)(void), 0x70) = func_020b7b54;
    func_0208fe30(0x127);
}

void func_020b7c4c(void) {
    M2C_UNK func_0208fe30(M2C_UNK);
    func_0208fe30(0xE5);
}

#pragma cplusplus on
extern "C" void func_020b7ef0(void) {
    extern void *gCur3DSpriteEngine;
    u16 *volatile p;
    p = (u16 *)((s8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) + 0x12);
    *p = (u16)(*p & ~0xC0);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x51) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x52) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x53) = 0;
}
#pragma cplusplus off

s32 func_020b7f58(void) {
    M2C_UNK func_0208bddc(s32, s32, s32, M2C_UNK, s32);
    s32 func_0208c54c();
    M2C_UNK func_0208c5fc(s32, s32, M2C_UNK);
    s32 func_020e3218(M2C_UNK *);
    extern M2C_UNK data_0212900c;
    extern M2C_UNK data_0212901c;
    s32 temp_r4;

    temp_r4 = func_0208c54c();
    func_0208c5fc(func_020e3218(&data_0212900c), 0x6B80, 0xB);
    func_0208bddc(temp_r4, func_020e3218(&data_0212901c), 0x6B80, 0xB, 0);
    return temp_r4;
}

s32 func_020b7fb8(void) {
    extern M2C_UNK data_0212902c;
    extern M2C_UNK data_0212903c;
    s32 temp_r4;

    temp_r4 = func_0208c54c();
    func_0208c5fc(func_020e3218(&data_0212902c), 0x6B80, 0xB);
    func_0208bddc(temp_r4, func_020e3218(&data_0212903c), 0x6B80, 0xB, 0);
    return temp_r4;
}

s32 func_020b8018(void) {
    extern M2C_UNK data_0212904c;
    extern M2C_UNK data_0212905c;
    s32 temp_r4;

    temp_r4 = func_0208c54c();
    func_0208c5fc(func_020e3218(&data_0212904c), 0x6B80, 0xB);
    func_0208bddc(temp_r4, func_020e3218(&data_0212905c), 0x6B80, 0xB, 0);
    return temp_r4;
}

