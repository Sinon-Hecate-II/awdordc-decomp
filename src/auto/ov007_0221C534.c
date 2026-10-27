/* 9 functions from 0x0221C534 to 0x0221D008 (ov007), found by ds-decomp. */
#include "common.h"

/* Initialize the map scene: load map data, fill tile slots, and center the viewport. */
void func_ov007_0221c534(void) {
M2C_UNK func_0207b754(u32,u32); M2C_UNK func_020cf498(s16,s16);
M2C_UNK func_020cfd28(); M2C_UNK func_ov007_022121b0();
M2C_UNK func_ov007_022121d4(M2C_UNK); M2C_UNK func_ov007_0221ab68();
extern void **gCurrentMap;
M2C_UNK func_020c857c(M2C_UNK); M2C_UNK func_ov007_0221c27c(M2C_UNK);
M2C_UNK func_ov007_0221bee4(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov007_0221c030(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov007_0221c250();
s32 slot1,slot2,slot3,slot1b,slot2b,slot3b; u32 viewX,viewY; void *state;
func_020c857c(M2C_FIELD(*gCurrentMap,u16 *,0x5142));
slot1=func_ov007_0221c27c(1);slot2=func_ov007_0221c27c(2);slot3=func_ov007_0221c27c(3);
func_ov007_0221bee4(slot1,slot2,slot3,func_ov007_0221c27c(4));
slot1b=func_ov007_0221c27c(1);slot2b=func_ov007_0221c27c(2);slot3b=func_ov007_0221c27c(3);
func_ov007_0221c030(slot1b,slot2b,slot3b,func_ov007_0221c27c(4));
func_ov007_0221c250(); func_020cfd28(); func_ov007_022121b0(); func_ov007_0221ab68();
state=*gCurrentMap;
viewX=(u32)M2C_FIELD(state,u16 *,0x5144)>>1;
viewY=(u32)M2C_FIELD(state,u16 *,0x5146)>>1;
func_020cf498((s16)viewX,(s16)viewY);func_0207b754(viewX,viewY);func_ov007_022121d4(0);
}

void func_ov007_0221c630(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_02220178;
    func_01ffa3dc(&data_ov007_02220178, 7);
}

void func_ov007_0221c648(M2C_UNK arg0) {
    M2C_UNK func_020bfebc(M2C_UNK);
    M2C_UNK func_020c002c(s32);
    s32 func_020c7e98(M2C_UNK);
    s32 func_020c7eb8();
    M2C_UNK func_020c857c(M2C_UNK);
    M2C_UNK func_ov007_02214814(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov007_0221bee4(s32, s32, s32, s32);
    M2C_UNK func_ov007_0221c030(s32, s32, s32, s32);
    M2C_UNK func_ov007_0221c250();
    s32 func_ov007_0221c27c(M2C_UNK);
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    s32 temp_r6_2;

    if (func_020c7eb8() == 0) {
        func_ov007_02214814(0x14, 0x14);
        return;
    }
    temp_r4 = func_020c7e98(arg0);
    func_020c857c(arg0);
    func_020c002c(temp_r4);
    func_020bfebc(0);
    temp_r6 = func_ov007_0221c27c(1);
    temp_r5 = func_ov007_0221c27c(2);
    temp_r4_2 = func_ov007_0221c27c(3);
    func_ov007_0221bee4(temp_r6, temp_r5, temp_r4_2, func_ov007_0221c27c(4));
    temp_r6_2 = func_ov007_0221c27c(1);
    temp_r5_2 = func_ov007_0221c27c(2);
    temp_r4_3 = func_ov007_0221c27c(3);
    func_ov007_0221c030(temp_r6_2, temp_r5_2, temp_r4_3, func_ov007_0221c27c(4));
    func_ov007_0221c250();
}

void func_ov007_0221cd5c(void) {
    M2C_UNK func_ov007_0221c718();
    func_ov007_0221c718();
}

void func_ov007_0221cd68(void *arg0) {
M2C_UNK func_0200bc5c(M2C_UNK *);
M2C_UNK func_020808dc(s32,s32,s32,s32);
M2C_UNK func_020814e4();
M2C_UNK func_02081528();
M2C_UNK func_02081590(s32,s32);
s32 func_020e32e8(M2C_UNK *);
M2C_UNK func_0208fe30(s32);
extern void *data_027e00c8;
extern void *gCur3DSpriteEngine;
extern M2C_UNK data_ov007_02220d34;
extern s32 data_ov007_02220d40[];
extern M2C_UNK data_ov007_0222192c;
extern M2C_UNK data_ov007_0222193c;
extern M2C_UNK data_ov007_0222194c;
extern M2C_UNK data_ov007_0222195c;
s32 kind;
void *p;
void *saved;
s32 old;
kind=M2C_FIELD(arg0,u8 *,0);
p=M2C_FIELD(arg0,void **,0x10);
old=M2C_FIELD(p,s32 *,0x34);
if((s32)kind>=100 && (s32)kind<103) M2C_FIELD(p,s32 *,0x34)=data_ov007_02220d40[kind-100];
if(old==M2C_FIELD(p,s32 *,0x34))return;
func_0200bc5c(&data_ov007_02220d34);
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
func_020e32e8(&data_ov007_0222192c);
func_020814e4();
switch(kind){
case 102:func_02081590(func_020e32e8(&data_ov007_0222195c),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24));break;
case 100:func_02081590(func_020e32e8(&data_ov007_0222194c),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24));break;
case 101:func_02081590(func_020e32e8(&data_ov007_0222193c),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24));break;
}
func_02081528();
func_020808dc(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24),32,24,5);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
gCur3DSpriteEngine=saved;
func_0208fe30(0x10011);
}

void func_ov007_0221ce9c(u8 *arg0) {
M2C_UNK func_020b1c60(u8);
extern void *data_02101e84;
u16 held,pressed;
u8 current,old;
old=*arg0;
pressed=M2C_FIELD(data_02101e84,u16 *,0);
current=old;
held=M2C_FIELD(data_02101e84,u16 *,2);
if(pressed&1){func_ov007_0221cd68(arg0);return;}
if(held&0x40){
switch(old){
case 100:if(held==pressed)current=60;break;
case 101:if(held==pressed)current=61;break;
case 102:if(held==pressed)current=62;break;
}
if(current>=100U){ if(current>=103U){} else goto horizontal; }
}else if(held&0x80){
switch(old){
case 100:if(held==pressed)current=0;break;
case 101:if(held==pressed)current=1;break;
case 102:if(held==pressed)current=2;break;
}
if(current>=100U && current<103U)goto horizontal;
}else{
horizontal:
if(held&0x20){
switch(current){
case 101:case 102:current--;break;
case 100:if(held==pressed)current=106;break;
}
if(current>=100U && current<103U)goto done;
}else if(held&0x10){
switch(current){
case 100:case 101:current++;break;
case 102:current=103;break;
}
}
}
done:
if(old==current)return;
func_020b1c60(current);
}

void func_ov007_0221cfe8(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov007_0221cffc(void) {
    M2C_UNK func_ov007_0221c718();
    func_ov007_0221c718();
}

