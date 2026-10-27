/* 10 functions from 0x0216B898 to 0x0216C7F0 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0216bfa4(void *arg0) {
extern u16 *data_02101e84;
extern u8 *data_02101e88;
func_020a91a8(M2C_FIELD(arg0,s32 *,0x44));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x48));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x4c));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x50));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x54));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x58));
func_020a91a8(M2C_FIELD(arg0,s32 *,0x5c));
switch(M2C_FIELD(arg0,u16 *,0x34)){
case 8:func_0208fe30(0x1003e);
case 0x68:func_0208fe30(0x1003f);
}
if((*data_02101e84 &9)||data_02101e88[0x14]||M2C_FIELD(arg0,u16 *,0x34)==0x83)func_01ffa6fc(arg0);
M2C_FIELD(arg0,u16 *,0x34)++;
}

void func_ov000_0216c068(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(3);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 8;
    M2C_FIELD(arg0, u8 *, 0x36) = 0;
}

void func_ov000_0216c09c(void){
extern void *gCurrentMap,*gCur3DSpriteEngine;
void (*callback)(void);u16 *volatile v0;u16 *volatile v1;u16 *volatile v2;u16 *volatile v3;u16 *volatile v4;u16 *volatile v5;
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x40);if(callback)callback();
func_020c0a88();
v0=(u16 *)(*(u8 **)gCur3DSpriteEngine+18);*v0=*v0&~0xc0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
v1=*(u16 **)gCur3DSpriteEngine;*v1=*v1|0x10;
v2=*(u16 **)gCur3DSpriteEngine;*v2=*v2|0x20;
v3=*(u16 **)gCur3DSpriteEngine;*v3=*v3|0x40;
v4=*(u16 **)gCur3DSpriteEngine;*v4=*v4|0x80;
v5=*(u16 **)gCur3DSpriteEngine;*v5=*v5|0x100;
}

void func_ov000_0216c1c4(void) {
    M2C_UNK func_ov000_0216b194();
    func_ov000_0216b194();
}

void func_ov000_0216c1d0(void) {
    void func_ov000_0216c09c(void);
    func_ov000_0216c09c();
}

void func_ov000_0216c1dc(void) {
    void func_ov000_0216c068();
    func_ov000_0216c068();
}

void func_ov000_0216c1e8(void) {
    M2C_UNK func_ov000_0216b898();
    func_ov000_0216b898();
}

void func_ov000_0216c1f4(void) {
    void func_ov000_0216bfa4();
    func_ov000_0216bfa4();
}

