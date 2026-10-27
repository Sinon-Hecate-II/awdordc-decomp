/* 48 functions from 0x020E0194 to 0x020E0F14 (main), found by ds-decomp. */
#include "common.h"
M2C_UNK func_020e0e8c();
M2C_UNK func_020e0194();
M2C_UNK func_020e02ac();
typedef struct { unsigned char value:4; } E0194Bits;
static inline u32 func_020e_low(void *p) { return M2C_FIELD(p,E0194Bits*,0x59).value; }
static inline u16 func_020e_get_value(void *p) { return (M2C_FIELD(p,u32*,0x40)<<6)>>24; }
static inline u8 func_020e_check(void *p) { return func_020e_low(p)+2 != func_020e_get_value(p); }

M2C_UNK func_ov010_022294ec();
M2C_UNK func_ov010_02228c88();
M2C_UNK func_ov009_02225348();
M2C_UNK func_02088ff4();
s32 func_02089064();
s16 func_020a8ff4();
M2C_UNK func_020e0194(void *arg0) { void *p;
 s16 v;
void *q;
u16 value;
 func_ov009_02225348();
 p=M2C_FIELD(arg0,void**,0x54);
 if(func_020e_check(p))func_02088ff4(p);
 func_02088ff4(M2C_FIELD(arg0,void**,0x58));
 if(func_02089064(M2C_FIELD(arg0,void**,0x60)))func_02088ff4(M2C_FIELD(arg0,void**,0x60));
 func_02088ff4(M2C_FIELD(arg0,void**,0x64));
 v=func_020a8ff4(M2C_FIELD(arg0,void**,0x68));
 q=M2C_FIELD(arg0,void**,0x68);
 M2C_FIELD(q,s16*,0xe)=v;
 M2C_FIELD(q,s16*,0x10)=-255;
 M2C_FIELD(q,s16*,0xc)=12;
 value=M2C_FIELD(q,u16*,4);
M2C_FIELD(q,u16*,2)=value;
 return value;
}

M2C_UNK func_020e0230(void *arg0) { void *p;
 s16 v;
void *q;
u16 value;
 func_ov010_022294ec();func_ov010_02228c88(arg0);
 p=M2C_FIELD(arg0,void**,0x54);
 if(func_020e_check(p))func_02088ff4(p);
 func_02088ff4(M2C_FIELD(arg0,void**,0x58));
 if(func_02089064(M2C_FIELD(arg0,void**,0x60)))func_02088ff4(M2C_FIELD(arg0,void**,0x60));
 func_02088ff4(M2C_FIELD(arg0,void**,0x64));
 
}

M2C_UNK func_020e02ac(void *arg0) { void *p;
 s16 v;
void *q;
u16 value;
 func_ov010_022294ec();func_ov010_02228c88(arg0);
 p=M2C_FIELD(arg0,void**,0x54);
 if(func_020e_check(p))func_02088ff4(p);
 func_02088ff4(M2C_FIELD(arg0,void**,0x58));
 if(func_02089064(M2C_FIELD(arg0,void**,0x60)))func_02088ff4(M2C_FIELD(arg0,void**,0x60));
 func_02088ff4(M2C_FIELD(arg0,void**,0x64));
 v=func_020a8ff4(M2C_FIELD(arg0,void**,0x68));
 q=M2C_FIELD(arg0,void**,0x68);
 M2C_FIELD(q,s16*,0xe)=v;
 M2C_FIELD(q,s16*,0x10)=-255;
 M2C_FIELD(q,s16*,0xc)=12;
 value=M2C_FIELD(q,u16*,4);
M2C_FIELD(q,u16*,2)=value;
 return value;
}

void func_020e0350(void) {
    M2C_UNK func_020e02ac();
    ((M2C_UNK (*)())func_020e02ac)();
}

void func_020e035c(void) {
    M2C_UNK func_020e0194();
    ((M2C_UNK (*)())func_020e0194)();
}

void func_020e0368(void) {
    ((M2C_UNK (*)())func_020e0194)();
}

s32 func_020d4810();
M2C_UNK func_020e0374(void *arg0) { s16 v; void *q; u16 value; func_020e0230(arg0);  v=func_020a8ff4(M2C_FIELD(arg0,void**,0x68));
 q=M2C_FIELD(arg0,void**,0x68);
 M2C_FIELD(q,s16*,0xe)=v;
 M2C_FIELD(q,s16*,0x10)=-255;
 M2C_FIELD(q,s16*,0xc)=12;
 value=M2C_FIELD(q,u16*,4);
M2C_FIELD(q,u16*,2)=value;
 return value;
}

void func_020e03ac(void) {
    M2C_UNK func_020e0230();
    func_020e0230();
}

M2C_UNK func_020e03b8(void *arg0) { void *p;
 s16 v;
void *q;
u16 value;
 if(!func_020d4810()){func_ov010_022294ec();func_ov010_02228c88(arg0);}
 p=M2C_FIELD(arg0,void**,0x54);
 if(func_020e_check(p))func_02088ff4(p);
 func_02088ff4(M2C_FIELD(arg0,void**,0x58));
 if(func_02089064(M2C_FIELD(arg0,void**,0x60)))func_02088ff4(M2C_FIELD(arg0,void**,0x60));
 func_02088ff4(M2C_FIELD(arg0,void**,0x64));
 v=func_020a8ff4(M2C_FIELD(arg0,void**,0x68));
 q=M2C_FIELD(arg0,void**,0x68);
 M2C_FIELD(q,s16*,0xe)=v;
 M2C_FIELD(q,s16*,0x10)=-255;
 M2C_FIELD(q,s16*,0xc)=12;
 value=M2C_FIELD(q,u16*,4);
M2C_FIELD(q,u16*,2)=value;
 return value;
}

void func_020e0468(void) {
    ((M2C_UNK (*)())func_020e02ac)();
}

void func_020e0474(void) {
    M2C_UNK func_020e03b8();
    func_020e03b8();
}

void func_020e0480(void) {
    func_020e0350();
}

/* Processes two current-entity slots, creating objects for an entity when slot conditions allow. */
void func_020e048c(void *entity) {
    M2C_UNK func_02007df8(M2C_UNK, M2C_UNK *, M2C_UNK);
    M2C_UNK func_020899cc(void *, s32, s32, s32);
    M2C_UNK func_0208af20();
    void *func_0208b520(void *);
    s32 func_0208b5ec();
    extern M2C_UNK data_02168f74;
    extern s32 data_027e00c8, data_027e00c4, gCur3DSpriteEngine;
    void *created;
    s32 bank;
    register s32 i;
    u8 mode;
    int savedEntity;
    if (func_0208b5ec()) func_0208af20();
    i = 0;
    savedEntity = gCur3DSpriteEngine;
    do {
        if (i == 0) bank = data_027e00c8; else bank = data_027e00c4;
        gCur3DSpriteEngine = bank;
        mode = M2C_FIELD(entity, u8 *, 0x44);
        if (mode == 0 && bank != data_027e00c8) goto next;
        if (mode == 1 && bank != data_027e00c4) goto next;
        if (mode == 3 && bank != savedEntity) goto next;
        created = func_0208b520(entity);
        func_020899cc(created, 0, M2C_FIELD(entity, u16 *, 0x46) << 5, 0x44000009);
        M2C_FIELD(created, s32 *, 0x58) |= 0x1800;
    next:
        ++i;
    } while (2 > i);
    gCur3DSpriteEngine = savedEntity;
    func_02007df8(0, &data_02168f74, 8);
    func_02084ea0(0x434c4353, entity);
}

M2C_UNK func_020e0580(s32 arg0) {
 s32 func_020848c4(); s16 func_020848f8(); M2C_UNK func_02085724();
 extern u16 *data_0212c5f8[];
 s32 i=func_020848c4();
 *data_0212c5f8[i]=func_020848f8();
 return func_02085724(data_0212c5f8,data_0212c5f8[func_020848c4()],2,arg0);
}

void func_020e05c4(void *entity) {
s32 func_020848c4(); void func_020d47d0(); void func_020d47f0();
s32 func_0208b5ec(); M2C_UNK func_0208af20(); void *func_0208b564(void *);
M2C_UNK func_020899cc(void *,s32,s32,s32);
extern u16 *data_0212c5f8[];
extern s32 data_027e00c8,data_027e00c4,gCur3DSpriteEngine;
void *created; s32 bank; register s32 i; u8 mode; s32 saved; u16 mask; s32 j;
mask=*data_0212c5f8[func_020848c4()];
func_020d47d0();
for(j=0;j<4;j++){
if((mask & (1<<j)) && mask != *data_0212c5f8[j]){
if(func_0208b5ec())func_0208af20();
saved=gCur3DSpriteEngine;i=0;
do {
if(i==0)bank=data_027e00c8;else bank=data_027e00c4;
gCur3DSpriteEngine=bank;
mode=M2C_FIELD(entity,u8*,0x44);
if(mode==0 && bank!=data_027e00c8)goto next;
if(mode==1 && bank!=data_027e00c4)goto next;
if(mode==3 && bank!=saved)goto next;
created=func_0208b564(entity);
func_020899cc(created,2,M2C_FIELD(entity,u16*,0x46)<<5,0x4400000a);
M2C_FIELD(created,s32*,0x58)|=0x1000;
next: ++i;
}while(i<2);
gCur3DSpriteEngine=saved;func_020d47f0();break;
}}
if(func_020d4810() && func_0208b5ec())func_0208af20();
}

void func_020e0aa4(void) {
    M2C_UNK func_020e06fc();
    func_020e06fc();
}

void func_020e0ab0(void) {
    func_020e0aa4();
}

void func_020e0abc(void) {
    func_020e06fc();
}

void func_020e0ac8(void) {
    func_020e06fc();
}

void func_020e0ad4(void) {
    func_020e0aa4();
}

void func_020e0ae0(void) {
    func_020e0aa4();
}

void func_020e0aec(void) {
    func_020e0ab0();
}

void func_020e0af8(void) {
    func_020e0ab0();
}

void func_020e0d6c(void) {
    M2C_UNK func_020e0b04();
    func_020e0b04();
}

void func_020e0d78(void) {
    func_020e0d6c();
}

void func_020e0d84(void) {
    func_020e0b04();
}

void func_020e0d90(void) {
    func_020e0b04();
}

void func_020e0d9c(void) {
    func_020e0d6c();
}

void func_020e0da8(void) {
    func_020e0d6c();
}

void func_020e0db4(void) {
    func_020e0d78();
}

void func_020e0dc0(void) {
    func_020e0d78();
}

void func_020e0dcc(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    M2C_UNK func_ov010_02229a94();
    func_ov010_02229a94();
    func_02084ea0(0x56434854, arg0);
}

void func_020e0dec(M2C_UNK arg0) {
    func_ov010_02229a94();
    func_02084ea0(0x56434854, arg0);
}

void func_020e0e0c(M2C_UNK arg0) {
    func_ov010_02229a94();
    func_02084ea0(0x56434854, arg0);
}

void func_020e0e2c(M2C_UNK arg0) {
    func_ov010_02229a94();
    func_02084ea0(0x56434854, arg0);
}

void func_020e0e4c(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    M2C_UNK func_ov010_02229a94();
    func_ov010_02229a94();
    func_02084ea0(0x56434854, arg0);
}

void func_020e0e6c(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    M2C_UNK func_ov010_02229a94();
    func_ov010_02229a94();
    func_02084ea0(0x56434854, arg0);
}

M2C_UNK func_020e0e8c(void *arg0) { M2C_UNK func_020b2178();
M2C_UNK func_020b1c44();
func_ov010_022294ec();
func_ov010_02228c88(arg0);
func_020b2178();
return func_020b1c44(0,0);
}

void func_020e0eb4(void) {
    M2C_UNK func_020e0e8c();
    ((M2C_UNK (*)())func_020e0e8c)();
}

void func_020e0ec0(void) {
    func_020e0eb4();
}

void func_020e0ecc(void) {
    ((M2C_UNK (*)())func_020e0e8c)();
}

void func_020e0ed8(void) {
    ((M2C_UNK (*)())func_020e0e8c)();
}

void func_020e0ee4(void) {
    func_020e0eb4();
}

void func_020e0ef0(void) {
    func_020e0eb4();
}

void func_020e0efc(void) {
    func_020e0ec0();
}

void func_020e0f08(void) {
    func_020e0ec0();
}

