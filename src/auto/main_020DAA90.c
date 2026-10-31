/* 20 functions from 0x020DAA90 to 0x020DB920 (main), found by ds-decomp. */
#include "common.h"
typedef void DAACC_RET;
typedef void DAE_RET;

void func_020daa90(void) {
    M2C_UNK func_020daa0c();
    func_020daa0c();
}

void func_020daa9c(void) {
    func_020daa0c();
}

void func_020daaa8(void) {
    func_020daa0c();
}

void func_020daab4(void) {
    func_020daa90();
}

void func_020daac0(void) {
    func_020daa90();
}

#pragma opt_strength_reduction off
DAACC_RET func_020daacc(void *arg0) {
    M2C_UNK func_020a8f8c(s32);
    s32 func_020a8ff4(s32);
    M2C_UNK func_020b1c44(s32, M2C_UNK);
    M2C_UNK func_020809c0(u16 *, s32, s32);
    M2C_UNK func_020e4cd8(u16 *, u32, u32, u32, u16, u16, u32);
    M2C_UNK func_020675e4(void *, const char *, ...);
    M2C_UNK func_0209b2b4(s32, s32, s32, void *, s32, s32);
    s32 func_ov009_022246ac(s32);
    extern void **data_027e00c8;
    extern void **gCur3DSpriteEngine;
    extern s32 data_02168f7c[];
    extern s8 data_0212d244[];
    extern s8 data_0212d248[];
    extern char data_0212d24c[];
    extern u16 data_0212d258[];
    extern char data_0212d270[];
    void *saved;
    void *unit;
    s32 temp_r0;
    u16 temp_r3;
    volatile u32 ime;
    u8 v6b;
    u8 v6c;
    s32 x;
    s32 y;
    s32 i;
    s32 z;
    s32 j;
    s8 buf2[16];
    s8 buf[16];

    func_020a8f8c(M2C_FIELD(arg0, s32 *, 0x68));
    temp_r0 = func_020a8ff4(M2C_FIELD(arg0, s32 *, 0x68));
    func_020b1c44(temp_r0, 0);
    saved = gCur3DSpriteEngine;
    temp_r3 = 0 - temp_r0;
    gCur3DSpriteEngine = data_027e00c8;
    M2C_FIELD(*data_027e00c8, u16 *, 0x3A) = temp_r3;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0x38) = temp_r3;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x40) = 0;

    if (!(M2C_FIELD(arg0, u16 *, 0x48) & 2)) {
        M2C_FIELD(arg0, s8 *, 0x42) = 0;
        x = (*(s32 *)0x027ffc3c & 1) * 0x180 + 0x124;
        y = 2;
        z = 0x40;
        for (i = 0; i < 4; i++) {
            ime = *(volatile u16 *)0x04000208;
            *(volatile u16 *)0x04000208 = 0;
            unit = (void *)func_ov009_022246ac(i);
            if (unit == NULL) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                continue;
            }
            if (M2C_FIELD(unit, u8 *, 0x4A) != 0x60) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                continue;
            }
            if (!(M2C_FIELD(unit, u8 *, 0x4B) & 1)) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                continue;
            }
            if (!(M2C_FIELD(unit, u8 *, 0x66) & 2)) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                continue;
            }
            if (M2C_FIELD(arg0, s32 *, 0x38) != (s8)M2C_FIELD(unit, s8 *, 0x6D)) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                continue;
            }
            data_02168f7c[(s8)M2C_FIELD(arg0, s8 *, 0x42)] = i;
            v6b = M2C_FIELD(unit, u8 *, 0x6B);
            v6c = M2C_FIELD(unit, u8 *, 0x6C);
            func_020809c0((u16 *)(M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24) + 6 + (z << 1)), 0x14, 2);
            func_020e4cd8((u16 *)((u8 *)unit + 0x50), M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x10), M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24), 9, 3, (u16)y, x);
            func_020675e4(buf2, data_0212d24c, data_0212d248[0], data_0212d244[1] + v6b, data_0212d248[0], data_0212d244[1] + v6c);
            func_0209b2b4(0x1A, (s16)y, 1, buf2, 0x9000, (u16)(x + 0x28));
            M2C_FIELD(arg0, s8 *, 0x42)++;
            x += 0x34;
            z += 0xA0;
            y += 5;
            if (M2C_FIELD(arg0, s8 *, 0x42) == 4) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                break;
            }
            (void)*(volatile u16 *)0x04000208;
            *(volatile u16 *)0x04000208 = ime;
        }
        for (j = M2C_FIELD(arg0, s8 *, 0x42); j < 4; j++) {
            data_02168f7c[j] = -1;
            func_020e4cd8(data_0212d258, M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x10), M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24), 9, 3, (u16)y, x);
            func_020675e4(buf, data_0212d270);
            func_0209b2b4(0x1A, (s16)y, 1, buf, 0x9000, (u16)(x + 0x28));
            x += 0x34;
            y += 5;
        }
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    gCur3DSpriteEngine = saved;
}
M2C_UNK func_020a8f8c(s32);
M2C_UNK func_020dae28(void *arg0) {
    return func_020a8f8c(M2C_FIELD(arg0, s32 *, 0x68));
}

#pragma opt_strength_reduction off
DAE_RET func_020dae38(void *arg0) {
M2C_UNK func_020a8f8c(s32); s32 func_020a8ff4(s32); M2C_UNK func_020b1c44(s32,M2C_UNK);
M2C_UNK func_020809c0(u16*,s32,s32); M2C_UNK func_020e4cd8(u16*,u32,u32,u32,u16,u16,u32);
M2C_UNK func_020675e4(void*,const char*,...); M2C_UNK func_0209b2b4(s32,s32,s32,void*,s32,s32);
s32 func_020c52ec(s32); s32 func_020c544c(s32); s32 func_0203a68c(s32,s32);
void func_ov010_0222697c(void*); s32 func_0203a7c0(s32,u8*,u8*,void*,s32*);
extern void **data_027e00c8; extern void **gCur3DSpriteEngine;
extern s32 data_02168f7c[]; extern s8 data_0212d278[]; extern s8 data_0212d27c[];
extern char data_0212d280[]; extern u16 data_0212d28c[]; extern char data_0212d2a4[];
void *saved; s32 unit, temp; u16 scroll; u8 a,b; s32 c;
s32 x,y,i,z,j; s8 buf2[16],buf[16]; u8 info[108];
func_020a8f8c(M2C_FIELD(arg0,s32*,0x68));
temp=func_020a8ff4(M2C_FIELD(arg0,s32*,0x68));
func_020b1c44(temp,0);
saved=gCur3DSpriteEngine;
scroll=-temp;
gCur3DSpriteEngine=data_027e00c8;
M2C_FIELD(*data_027e00c8,u16*,0x3a)=scroll;
M2C_FIELD(*gCur3DSpriteEngine,s16*,0x42)=0;
M2C_FIELD(*gCur3DSpriteEngine,u16*,0x38)=scroll;
M2C_FIELD(*gCur3DSpriteEngine,s16*,0x40)=0;
if(!(M2C_FIELD(arg0,u16*,0x48)&2)){
M2C_FIELD(arg0,s8*,0x42)=0;
x=(*(s32*)0x027ffc3c&1)*0x180+0x124; y=2;z=0x40;
for(i=0;i<60;i++){
unit=func_020c52ec(i); if(!unit)continue;
if(func_020c544c(unit)!=3)continue;
if(func_0203a68c(unit,0)!=6)continue;
func_ov010_0222697c(info);
if(func_0203a7c0(unit,&a,&b,info,&c)!=6)continue;
if(!(info[0x1a]&2)||a==b)continue;
if(M2C_FIELD(arg0,s32*,0x38)!=M2C_FIELD(info,s8*,0x28))continue;
data_02168f7c[M2C_FIELD(arg0,s8*,0x42)]=i;
func_020809c0((u16*)(M2C_FIELD(gCur3DSpriteEngine,u32*,0x24)+6+(z<<1)),20,2);
func_020e4cd8((u16*)info,M2C_FIELD(gCur3DSpriteEngine,u32*,0x10),M2C_FIELD(gCur3DSpriteEngine,u32*,0x24),9,3,(u16)y,x);
func_020675e4(buf2,data_0212d280,data_0212d27c[0],data_0212d278[1]+b,data_0212d27c[0],data_0212d278[1]+a);
func_0209b2b4(26,(s16)y,1,buf2,0x9000,(u16)(x+0x28));
M2C_FIELD(arg0,s8*,0x42)++;x+=0x34;z+=0xa0;y+=5;
if(M2C_FIELD(arg0,s8*,0x42)==4)break;
}
for(j=M2C_FIELD(arg0,s8*,0x42);j<4;j++){
data_02168f7c[j]=-1;
func_020e4cd8(data_0212d28c,M2C_FIELD(gCur3DSpriteEngine,u32*,0x10),M2C_FIELD(gCur3DSpriteEngine,u32*,0x24),9,3,(u16)y,x);
func_020675e4(buf,data_0212d2a4);
func_0209b2b4(26,(s16)y,1,buf,0x9000,(u16)(x+0x28));x+=0x34;y+=5;
}
}
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2; gCur3DSpriteEngine=saved;
}
void func_020db134(void) {
    ((void (*)())func_020dae38)();
}

void func_020db140(void) {
    DAACC_RET func_020daacc();
    func_020daacc();
}

void func_020db14c(void) {
    DAACC_RET func_020daacc();
    func_020daacc();
}

void func_020db158(void *arg0) {
    M2C_UNK func_020dae28();
    func_020dae28(arg0);
}

void func_020db164(void *arg0) {
    func_020dae28(arg0);
}

void func_020db170(void) {
    ((M2C_UNK (*)())func_020dae38)();
}

void func_020db17c(void) {
    func_020db134();
}

void func_020db188(void) {
    ((M2C_UNK (*)())func_020dae38)();
}

void func_020db194(void) {
    func_020db134();
}

M2C_UNK func_020db1a0(M2C_UNK arg0) {
    return 0;
}

M2C_UNK func_020db5e8() {
    return 0;
}

void func_020db914(void) {
    M2C_UNK func_020db5e8();
    func_020db5e8();
}

