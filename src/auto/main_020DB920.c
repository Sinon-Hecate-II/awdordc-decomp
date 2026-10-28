/* 25 functions from 0x020DB920 to 0x020DC838 (main), found by ds-decomp. */
#include "common.h"

static inline void func_020dbe00(void *q) {
    s32 next;
    u32 base;
    u32 value;
    s32 test;
    base = (u32) (M2C_FIELD(q, u8 *, 0x59) << 28) >> 28;
    next = base + 2;
    if (next != (u16) ((u32) (M2C_FIELD(q, s32 *, 0x40) << 6) >> 24)) test = 1; else test = 0;
    if (test & 255) value = base << 16; else value = next << 16;
    M2C_FIELD(q, u32 *, 0x40) = (M2C_FIELD(q, u32 *, 0x40) & ~0x3fc0000) | (((value >> 16) << 24) >> 6);
}

static inline void func_020dbe10(void *q) {
    s32 next;
    u32 base;
    u32 value;
    s32 test;
    base = (u32) (M2C_FIELD(q, u8 *, 0x59) << 28) >> 28;
    next = base + 2;
    if (next != (u16) ((u32) (M2C_FIELD(q, s32 *, 0x40) << 6) >> 24)) test = 1; else test = 0;
    if (test & 255) value = base << 16; else value = next << 16;
    M2C_FIELD(q, u32 *, 0x40) = (M2C_FIELD(q, u32 *, 0x40) & ~0x3fc0000) | (((value >> 16) << 24) >> 6);
}

static inline void func_020dbe20(void *q) {
    u32 base;
    s32 next;
    s32 test;
    base = (u32) (M2C_FIELD(q, u8 *, 0x59) << 28) >> 28;
    next = base + 2;
    if (next != (u16) ((u32) (M2C_FIELD(q, s32 *, 0x40) << 6) >> 24)) test = 1; else test = 0;
    if (!(test & 255)) {
        M2C_FIELD(q, u32 *, 0x40) = (M2C_FIELD(q, u32 *, 0x40) & ~0x3fc0000) | ((u32) ((u16) base << 24) >> 6);
        M2C_FIELD(q, u8 *, 0x5a) = 0;
    }
}

M2C_UNK func_020db920() { return 0; }

void func_020dbd00(void) {
    M2C_UNK func_020db1a0();
    func_020db1a0();
}

void func_020dbd0c(void) {
    func_020db1a0();
}

void func_020dbd18(void) {
    M2C_UNK func_020db5e8();
    func_020db5e8();
}

void func_020dbd24(void) {
    func_020db5e8();
}

void func_020dbd30(void) {
    M2C_UNK func_020db914();
    func_020db914();
}

void func_020dbd3c(void) {
    func_020db914();
}

void func_020dbd48(void) {
    M2C_UNK func_020db920();
    func_020db920();
}

void func_020dbd54(void) {
    func_020db920();
}

void func_020dbd60(void *arg0) {
    M2C_UNK func_020a8f8c(s32);
    s32 func_020a8ff4(s32);
    M2C_UNK func_020b1c44(s32, M2C_UNK);
    extern void **data_027e00c8;
    extern void **gCur3DSpriteEngine;
    s32 temp_r0;
    u16 temp_r3;
    void **temp_ip;
    func_020a8f8c(M2C_FIELD(arg0, s32 *, 0x68));
    temp_r0 = func_020a8ff4(M2C_FIELD(arg0, s32 *, 0x68));
    func_020b1c44(temp_r0, 0);
    temp_ip = gCur3DSpriteEngine;
    temp_r3 = 0 - temp_r0;
    gCur3DSpriteEngine = data_027e00c8;
    M2C_FIELD(*data_027e00c8, u16 *, 0x3A) = temp_r3;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0x38) = temp_r3;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x40) = 0;
    gCur3DSpriteEngine = temp_ip;
}

void func_020dbde4(void *arg0) {
    M2C_UNK func_020a8f8c(s32);
    s32 func_020a8ff4(s32);
    M2C_UNK func_020b1c44(s32, M2C_UNK);
    extern void **data_027e00c8;
    extern void **gCur3DSpriteEngine;
    s32 temp_r0;
    u16 temp_r3;
    void **temp_ip;
    func_020a8f8c(M2C_FIELD(arg0, s32 *, 0x68));
    temp_r0 = func_020a8ff4(M2C_FIELD(arg0, s32 *, 0x68));
    func_020b1c44(temp_r0, 0);
    temp_ip = gCur3DSpriteEngine;
    temp_r3 = 0 - temp_r0;
    gCur3DSpriteEngine = data_027e00c8;
    M2C_FIELD(*data_027e00c8, u16 *, 0x3A) = temp_r3;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0x38) = temp_r3;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x40) = 0;
    gCur3DSpriteEngine = temp_ip;
}

void func_020dbe68(void *arg0) {
    void func_020dbde4(void *);
    func_020dbde4(arg0);
}

void func_020dbe74(void *arg0) {
    void func_020dbd60(void *);
    func_020dbd60(arg0);
}

void func_020dbe80(void *arg0) {
    func_020dbd60(arg0);
}

void func_020dbe8c(void *arg0) {
    func_020dbde4(arg0);
}

void func_020dbe98(void *arg0) {
    func_020dbde4(arg0);
}

void func_020dbea4(void *arg0) {
    func_020dbe68(arg0);
}

void func_020dbeb0(void *arg0) {
    func_020dbe68(arg0);
}

M2C_UNK func_020dbebc(void *arg0) {
extern void **gCur3DSpriteEngine, **data_027e00c8;
extern M2C_UNK data_0212d358, data_0212d360, data_0212d370, data_0212c658;
M2C_UNK func_01ff9ce8(s32), func_0200bc5c(void *);
s32 func_020e3218(void *);
M2C_UNK func_020814e4(void), func_02081528(void);
M2C_UNK func_02081590(s32,s32), func_02080944(s32,s32,s32,s32);
s32 func_020b20e0(s32);
void *func_020b22a4(s32,s32,void *,s32), *func_020b1c78(s32);
M2C_UNK func_020808dc(s32,s32,u16,u16);
M2C_UNK func_0208fe30(s32), func_020b1c44(s32,s32);
M2C_UNK func_02088f1c(void *), func_0208b758(void *,s32);
s32 func_020a8ff4(s32);
void *sp4;
void **sp0;
s32 i, x, test;
s32 i2;
void *item;
s32 y, end;
s32 color;
u8 selected;
void *p;
void **saved;
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
func_01ff9ce8(1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
func_0200bc5c(&data_0212d358);
func_020e3218(&data_0212d360);
func_020814e4();
func_02081590(func_020e3218(&data_0212d370),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20));
func_02081528();
func_02080944(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20),32,24,5);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
gCur3DSpriteEngine=saved;
M2C_FIELD(arg0,u16 *,0x48)|=32;
if(func_020b20e0(0)==0) test=1; else test=0;
if(test) {
i=0; x=0;
do {
p=func_020b22a4(0,x,&data_0212c658,i);
i++;
M2C_FIELD(p,void **,0x10)=arg0;
x+=40;
} while(i<2);
}
item=func_020b1c78(M2C_FIELD(arg0,s32 *,0x3c));
if(item) {
sp4=M2C_FIELD(item,void **,0x10);
sp0=gCur3DSpriteEngine;
y=10;
gCur3DSpriteEngine=data_027e00c8;
end=14; i2=0;
do {
if(M2C_FIELD(item,u8 *,0)!=i2) color=7; else color=8;
func_020808dc(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20)+8+(y<<6),24,(u16)(end-y),(u16)color);
i2++; y=(s16)(y+5); end=(s16)(end+5);
} while(i2<2);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
gCur3DSpriteEngine=sp0;
selected=M2C_FIELD(item,u8 *,0);
if(selected!=M2C_FIELD(sp4,s32 *,0x3c)) {
M2C_FIELD(sp4,s32 *,0x3c)=selected;
func_0208fe30(0x10019);
}
}
func_020b1c44(0,0);
p=M2C_FIELD(arg0,void **,0x50);
func_02088f1c(p);
p=M2C_FIELD(arg0,void **,0x50);
func_020dbe00(p);
M2C_FIELD(p,u8 *,0x5a)=0;
p=M2C_FIELD(arg0,void **,0x58);
func_02088f1c(p);
p=M2C_FIELD(arg0,void **,0x58);
func_020dbe10(p);
M2C_FIELD(p,u8 *,0x5a)=0;
func_020dbe20(M2C_FIELD(arg0,void **,0x50));
func_0208b758(M2C_FIELD(arg0,void **,0x64),0x4400000e);
func_02088f1c(M2C_FIELD(arg0,void **,0x64));
if(func_020a8ff4(M2C_FIELD(arg0,s32 *,0x68))) {
s32 result=func_020a8ff4(M2C_FIELD(arg0,s32 *,0x68));
p=M2C_FIELD(arg0,void **,0x68);
M2C_FIELD(p,u16 *,0xe)=result;
M2C_FIELD(p,u16 *,0x10)=0;
M2C_FIELD(p,u16 *,0xc)=12;
M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);
}
M2C_FIELD(arg0,u16 *,0x48)&=~4;
}

void func_020dc5e4(void *arg0) {
    M2C_UNK func_020dbebc(void *);
    func_020dbebc(arg0);
}

void func_020dc5f0(void *arg0) {
    func_020dbebc(arg0);
}

void func_020dc5fc(void) {
    M2C_UNK func_020dc250();
    func_020dc250();
}

void func_020dc608(void) {
    func_020dc250();
}

