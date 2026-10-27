/* 10 functions from 0x020C1F58 to 0x020C2E4C (main), found by ds-decomp. */
#include "common.h"

void func_020c2ca0(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(2);
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(arg0, u8 *, 0x35) = 0;
}

void func_020c2cec(void){
extern void *gCurrentMap,*gCur3DSpriteEngine;
void (*callback)(void);u16 *volatile v0;u16 *volatile v1;u16 *volatile v2;u16 *volatile v3;u16 *volatile v4;u16 *volatile v5;
callback=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x40);if(callback)callback();
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

void func_020c2e10(void) {
    M2C_UNK func_020c1f58();
    func_020c1f58();
}

void func_020c2e1c(void) {
    void func_020c2cec(void);
    func_020c2cec();
}

void func_020c2e28(void) {
    void func_020c2ca0();
    func_020c2ca0();
}

void func_020c2e34(void) {
    M2C_UNK func_020c253c();
    func_020c253c();
}

void func_020c2e40(void) {
    M2C_UNK func_020c2aa4();
    func_020c2aa4();
}

