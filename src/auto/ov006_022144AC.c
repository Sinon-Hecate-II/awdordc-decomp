/* 17 functions from 0x022144AC to 0x022153FC (ov006), found by ds-decomp. */
#include "common.h"

int func_ov006_022144ac(void *arg0) {
    (void)arg0;
    return 0;
}

void func_ov006_02215010(void) {
    M2C_UNK func_ov006_02212184();
    func_ov006_02212184();
}

void func_ov006_0221501c(void) {
    M2C_UNK func_ov006_02211200();
    func_ov006_02211200();
}

void func_ov006_02215028(void) {
    M2C_UNK func_ov006_02211388();
    func_ov006_02211388();
}

void func_ov006_02215034(void) {

}

void func_ov006_02215038(void) {
    M2C_UNK func_ov006_02211314();
    func_ov006_02211314();
}

void func_ov006_02215044(void) {
    M2C_UNK func_020c4dd0();
    func_020c4dd0();
}

void func_ov006_02215050(void) {
    M2C_UNK func_020c52d8();
    func_020c52d8();
}

void func_ov006_0221505c(void *arg0) {
    M2C_UNK func_020c5664(s16);
    func_020c5664(M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s16 *, 8));
    M2C_FIELD(arg0, s8 *, 0x34) = 1;
}

void func_ov006_0221507c(void **arg0) {
 M2C_FIELD(*arg0, void (**)(void *), 8)(arg0);
}

void func_ov006_02215090(void *arg0) {
    M2C_UNK func_01ffa574(s32);
    M2C_UNK func_020af1e4();
    func_020af1e4();
    func_01ffa574(M2C_FIELD(arg0, s32 *, 0x38));
}

void func_ov006_022150a8(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_020a8f8c(void *);
    void *ptr = M2C_FIELD(arg0, void **, 0x48);
    u8 equal = M2C_FIELD(ptr, u16 *, 2) == M2C_FIELD(ptr, s16 *, 0xC);
    if (equal) {
        func_01ffa6fc(arg0);
        return;
    }
    func_020a8f8c(ptr);
}

void func_ov006_022150e0(void) {
    M2C_UNK func_ov006_02213e98();
    func_ov006_02213e98();
}

void func_ov006_022150ec(void) {
    M2C_UNK func_ov006_0221440c();
    func_ov006_0221440c();
}

void func_ov006_022150f8(void) {
    M2C_UNK func_ov006_022144ac();
    func_ov006_022144ac();
}

void func_ov006_02215104(s32 arg0) {
void func_01ff9ce8(s32);
void func_01ff9dd8(s32);
void *func_0208b564(s32);
void func_020899cc(void *,s32,s32,s32);
void func_02091d4c(s32);
extern void *gCur3DSpriteEngine,*data_027e00c8,*data_027e00c4;
u16 *volatile p0,*volatile p1,*volatile p2,*volatile p3,*volatile p4,*volatile p5,*volatile p6,*volatile p7,*volatile p8,*volatile p9,*volatile p10,*volatile p11;
void *saved=gCur3DSpriteEngine;
void *obj;
gCur3DSpriteEngine=data_027e00c8;
p0=*(u16 **)gCur3DSpriteEngine; *p0=*p0|0x10;
p1=*(u16 **)gCur3DSpriteEngine; *p1=*p1|0x20;
p2=*(u16 **)gCur3DSpriteEngine; *p2=*p2|0x40;
p3=*(u16 **)gCur3DSpriteEngine; *p3=*p3&~0x80;
p4=*(u16 **)gCur3DSpriteEngine; *p4=*p4|0x100;
p5=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12); *p5=*p5&~0xc0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
func_01ff9ce8(0);func_01ff9ce8(1);func_01ff9dd8(0);func_01ff9dd8(1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)=M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|1;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)=M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|2;
obj=func_0208b564(arg0);func_020899cc(obj,2,0x4640,0x42000001);M2C_FIELD(obj,u32 *,0x58)|=0x1000;
gCur3DSpriteEngine=data_027e00c4;
p6=*(u16 **)gCur3DSpriteEngine; *p6=*p6|0x10;
p7=*(u16 **)gCur3DSpriteEngine; *p7=*p7|0x20;
p8=*(u16 **)gCur3DSpriteEngine; *p8=*p8|0x40;
p9=*(u16 **)gCur3DSpriteEngine; *p9=*p9&~0x80;
p10=*(u16 **)gCur3DSpriteEngine; *p10=*p10|0x100;
p11=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12); *p11=*p11&~0xc0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x53)=0;
func_01ff9ce8(0);func_01ff9ce8(1);func_01ff9dd8(0);func_01ff9dd8(1);
func_01ff9ce8(0);func_01ff9dd8(0);func_02091d4c(7);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)=M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|1;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)=M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|1;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)=M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|2;
gCur3DSpriteEngine=saved;
}

u8 func_ov006_022153f4(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x34);
}

