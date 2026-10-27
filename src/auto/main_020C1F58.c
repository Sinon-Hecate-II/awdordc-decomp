/* 10 functions from 0x020C1F58 to 0x020C2E4C (main), found by ds-decomp. */
#include "common.h"

void func_020c2aa4(u8 *p){
void func_01ffa6fc(void *);
void func_020c32bc(s32,s32);
void func_0208fe30(s32);
u32 func_0207c928(u32,u32);
s32 func_020d19b4(s32);
extern u16 *data_02101e84;
extern u8 *data_02101e88;
u8 *q;
u16 *a;
if(p[0x34]==p[0x38]){func_01ffa6fc(p);return;}
if((*data_02101e84&9)||data_02101e88[20]){
q=*(u8 **)(p+64);
if(q[5]==20 && p[0x34]<p[0x37]+7)func_020c32bc(q[0],0);
func_01ffa6fc(p);return;
}
if(p[0x34]==6){
func_0208fe30((p[0x39]+42)|0x10000);p[0x39]++;
}else if(p[0x34]>6 && p[0x39]<(*(u8 **)(p+64))[5] && func_0207c928(p[0x34]-6,3)==0){
func_0208fe30((p[0x39]+42)|0x10000);p[0x39]++;
}
if(p[0x34]==p[0x37]){
if((*(u8 **)(p+64))[5]==20){
p[80]=(p[80]&~0xfc)|4;
a=*(u16 **)(p+68);a[7]=0;a[8]=5;a[6]=8;a[1]=a[2];
}else{
p[80]=(p[80]&~1)|1;p[80]|=2;
}
a=*(u16 **)(p+72);a[7]=0x1c0;a[8]=0x100;a[6]=5;a[1]=a[2];
}
q=*(u8 **)(p+64);
if(q[5]==20){
if(p[0x34]==p[0x37]+8)func_020c32bc(q[0],0);
}else if(p[0x34]==p[0x37]+5){
if(func_020d19b4(q[0]))func_0208fe30(0xe0);else func_0208fe30(0xe2);
}
p[0x34]++;
}

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
    void func_020c2aa4();
    func_020c2aa4();
}

