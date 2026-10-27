/* 28 functions from 0x02095C90 to 0x02096C7C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u16 unk0, unk2, unk4, unk6; } Unk0209Rect;
typedef struct { u8 kind:6; u8 owner:2; u8 rest[13]; } Unit964;
extern u8 data_02102ee4[];
extern u16 data_02168f14[];

void func_02095eb4(void) {
    M2C_UNK func_020af230();
    M2C_UNK func_0208232c();
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c4;
    u16 *volatile v0;
    u16 *volatile v1;
    u16 *volatile v2;
    u16 *volatile v3;
    u16 *volatile v4;
    void *saved;

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_020af230();
    func_0208232c();
    v0 = *(u16 **)gCur3DSpriteEngine;
    *v0 = *v0 | 0x10;
    v1 = *(u16 **)gCur3DSpriteEngine;
    *v1 = *v1 | 0x20;
    v2 = *(u16 **)gCur3DSpriteEngine;
    *v2 = *v2 | 0x40;
    v3 = *(u16 **)gCur3DSpriteEngine;
    *v3 = *v3 | 0x80;
    v4 = *(u16 **)gCur3DSpriteEngine;
    *v4 = *v4 | 0x100;
    gCur3DSpriteEngine = saved;
}

void func_02095f90(void) {

}

void func_02095f94(s32 arg0) {
void func_02095fc0(void);
M2C_UNK func_01ffa3dc(M2C_UNK *,M2C_UNK);
void func_02068c50(void *,s32);
extern M2C_UNK data_02102b18;
s32 p;
func_02095fc0();
p=func_01ffa3dc(&data_02102b18,7);
func_02068c50((u8 *)p+0x36,arg0);
}

void func_02095fc0(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02102b18;
    func_01ffa9e4(&data_02102b18);
}

void func_02095fd4(void) {
void *func_02091da8(void);
M2C_FIELD(func_02091da8(),s8 *,0x46)=0;
}

u8 func_02095fe8(void) {
    void *func_02091da8();
    return M2C_FIELD(func_02091da8(), u8 *, 0x46);
}

void func_02095ff8(s8 arg0) {
    M2C_FIELD(func_02091da8(), s8 *, 0x46) = arg0;
}

u8 func_0209600c(void) {
    u8 var_r0;

    if (func_02095fe8() == 1) {
        return 1U;
    }
    if (func_02095fe8() == 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_02096038(void) {
    u8 var_r0;

    if (func_02095fe8() == 3) {
        return 0U;
    }
    if (func_02095fe8() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_02096064(void) {
    extern u16 *data_02101e84;
    if (func_02096038() == 0) {
        return 0;
    }
    if (func_0209600c() != 0) {
        return 0;
    }
    if (!(*data_02101e84 & 8)) {
        return 0;
    }
    func_02095ff8(1);
    return 1;
}

void func_020960b4(void) {
    M2C_UNK func_0209cce4(M2C_UNK *, M2C_UNK);
    extern M2C_UNK func_020949f8;
    func_0209cce4(&func_020949f8, 5);
}

void func_020960cc(s32 arg0, s32 arg1, void *arg2) {
    s32 func_0207c8ec(s32, M2C_UNK);
    s32 temp_r0;

    temp_r0 = arg0 - arg1;
    M2C_FIELD(arg2, s16 *, 0) = (s16) (((u32) (temp_r0 & 0x3F) >> 1) * 8);
    M2C_FIELD(arg2, s16 *, 2) = (s16) (func_0207c8ec(temp_r0, 0x40) * 8);
}

void func_020960fc(void *arg0) {
M2C_UNK func_02091e50(void);
void func_02097c50(s32,s32,s32);
extern void *gCur3DSpriteEngine;
s16 pos[2];
func_020960cc(M2C_FIELD(arg0,s32 *,0x4c),M2C_FIELD((u8 *)gCur3DSpriteEngine+M2C_FIELD(arg0,u8 *,0x40)*4,s32 *,0x20),pos);
func_02097c50(func_02091e50(),pos[0]+M2C_FIELD(arg0,s16 *,0x4a),pos[1]);
}

void func_0209614c(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_02091e50();
    M2C_UNK func_02097cb8();
    s32 func_0209dc48();
    s32 func_0209dd54();
    s32 temp_r4;
    u16 temp_r4_2;

    temp_r4 = func_0209dc48();
    temp_r4_2 = temp_r4 | func_0209dd54();
    if ((func_02096038() != 0) && (temp_r4_2 & 0x400)) {
        func_02095ff8(1);
    }
    if (!(temp_r4_2 & 0x430)) {
        return;
    }
    func_0208fe30(0x10012);
    func_02091e50();
    func_02097cb8();
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x44)();
    func_01ffa6fc(arg0);
}

M2C_UNK func_020961b8(void *p) {
s32 func_02091e50(void);
void func_0209de6c(s32,Unk0209Rect);
void func_02097c84(s32,s32,s32);
extern void *gCur3DSpriteEngine;
s32 cursor=func_02091e50();
s32 x=0,y=0;
s16 pos[2];
Unk0209Rect a,b;
func_020960cc(M2C_FIELD(p,s32 *,0x4c),M2C_FIELD(gCur3DSpriteEngine+M2C_FIELD(p,u8 *,0x40)*4,s32 *,0x20),pos);
a.unk2=pos[1];a.unk4=32;a.unk6=16;
pos[0]+=M2C_FIELD(p,s16 *,0x4a);
a.unk0=pos[0];
func_0209de6c(1,a);
b.unk0=pos[0]+32;b.unk2=pos[1];b.unk4=32;b.unk6=16;
func_0209de6c(2,b);
switch(M2C_FIELD(p,s16 *,0x34)) {case 0:x=pos[0];y=pos[1];break;case 1:x=pos[0]+32;y=pos[1];break;}
func_02097c84(cursor,x,y);
}

void func_020962ec(void *arg0) {
    M2C_UNK func_020961b8(void *);
    M2C_UNK func_0209bfdc(M2C_UNK, M2C_UNK, s32, s32, s32, s32);
    func_0209bfdc(0, 0, M2C_FIELD(arg0, s32 *, 0x4C), 0xC0000321, (s32) M2C_FIELD(arg0, u16 *, 0x48), 0);
    func_020961b8(arg0);
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x44)();
}

void func_02096334(void *arg0) {
    M2C_UNK func_02097bac(M2C_UNK);
    s32 func_0209dcf0(void);
    s32 func_0209def8(void);
    M2C_UNK func_020d47d0(void);
    M2C_UNK func_020d47f0(void);
    M2C_UNK func_020961b8(void *);
    M2C_UNK func_0208fe30(M2C_UNK);
    M2C_UNK func_02091e50(void);
    M2C_UNK func_02097cb8(void);
    M2C_UNK func_01ffa6fc(void *);

    s16 temp_r0;
    s16 temp_r1;
    s32 temp_r5;
    s32 temp_r0_2;

    temp_r5 = func_0209dcf0();
    temp_r0_2 = func_0209def8();
    temp_r1 = M2C_FIELD(arg0, s16 *, 0x34);
    temp_r5 = temp_r5 | temp_r0_2;
    if (temp_r1 != 0) {
        if ((temp_r1 == 1) && (temp_r5 & 4)) {
            M2C_FIELD(arg0, s16 *, 0x34) = 0;
            func_020961b8(arg0);
            func_0208fe30(0x10010);
            return;
        }
        goto block_8;
    }
    if (temp_r5 & 8) {
        M2C_FIELD(arg0, s16 *, 0x34) = 1;
        func_020961b8(arg0);
        func_0208fe30(0x10010);
        return;
    }
    if (temp_r5 & 0x20) {
        M2C_FIELD(arg0, s16 *, 0x34) = 1;
        func_020961b8(arg0);
    }
block_8:
    if (temp_r5 & 0x10) {
        func_0208fe30(0x1000D);
    }
    if (temp_r5 & 0x20) {
        func_0208fe30(0x1000F);
    }
    if (!(temp_r5 & 0x30)) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, s16 *, 0x34);
    switch (temp_r0) {
    case 0:
        func_020d47d0();
        break;
    case 1:
        func_020d47f0();
        break;
    }
    func_02091e50();
    func_02097cb8();
    func_02097bac(3);
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x44)();
    func_01ffa6fc(arg0);
}

void func_0209643c(void){
extern s32 *gCurrentMap;
s32 func_020c79ec(void);s32 func_020846a4(void);s32 func_020c85c4(s32,s32);void func_020c8564(s32);s32 func_020a8b2c(s32);M2C_UNK func_0200bc5c(M2C_UNK *);s32 func_02080e30(s32,s32);M2C_UNK func_0209670c(s32,M2C_UNK);M2C_UNK func_020e35cc(s32);void func_020a7310(void *);void *func_020a32f4(void);void func_020cfd28();
s32 id=M2C_FIELD((void *)*gCurrentMap,u16 *,0x5142);
s32 p,i;Unit964 *unit; s32 off;
if(id>=225&&id<425){
p=func_020c79ec();
if(!func_020846a4()){
if(!func_020c85c4(id,p))return;
}
func_020c8564(p);
}else{
if(!func_020a8b2c(id))return;
func_0200bc5c((M2C_UNK *)data_02102ee4);
p=func_02080e30(func_020a8b2c(id),1);
func_0209670c(p,0);
func_020e35cc(p);
}
if(!((u32)(data_02168f14[0]<<23)>>31)){
i=1;off=14;
do{
unit=(Unit964 *)((u8 *)*gCurrentMap+0x59a4+off);
if(unit->kind&&unit->owner){
func_020a7310(unit);
if(unit!=func_020a32f4())unit->owner=0;
}
++i;off+=14;
}while(i<256);
}
func_020cfd28();
}

void func_0209656c(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    s32 func_02080e30(M2C_UNK, M2C_UNK);
    M2C_UNK func_0209670c(s32, M2C_UNK);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK data_02102eec;
    s32 temp_r0;

    func_0200bc5c(&data_02102eec);
    temp_r0 = func_02080e30(arg0, 1);
    func_0209670c(temp_r0, arg1);
    func_020e35cc(temp_r0);
}

