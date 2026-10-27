/* 31 functions from 0x020BDA88 to 0x020BE718 (main), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_0215d890,data_0215d990,data_0215d9b8;
typedef struct { s16 a,b,c,d; } EntryBE;

static inline s32 IsNewerValue(u32 b, u32 a) {
    register u32 result = a & 0xffff0000;
    if (result == 0xffff0000 && !(b & 0xffff0000) && b != 0) result = 0;
    else if (!result && (b & 0xffff0000) == 0xffff0000 && a != 0) result = 1;
    else result = a > b;
    return result;
}

/* Convert the polled touch point to map tile coordinates and, when a tile is under it, record the touched tile in the map context (and in the hover-from-tile state when applicable), notifying the caller of the chosen tile index. */
void func_020bda88(s32 *outTileIndex, s32 arg) {
    void func_0207bb3c(u16 touchX, u16 touchY, s32 *coords);
    s32 func_0207c8ec(s32 value, s32 divisor);
    s32 func_020947c0(void);
    s32 func_020caba4(s32 tileX, s32 tileY, s32 mask);
    void func_020bd0a8(s16 x, s16 y);
    void func_020bd0e0(void);
    extern void *data_02101e88;
    extern void **gCurrentMap;
    s32 coords[3];
    s32 pixelX, pixelY, tileIndex;
    u16 touchX = M2C_FIELD(data_02101e88, u16 *, 0);
    u16 touchY = M2C_FIELD(data_02101e88, u16 *, 2);
    void *map;
    if (func_020947c0() != 0) return;
    if (M2C_FIELD(data_02101e88, u8 *, 0x12) == 0) return;
    func_0207bb3c(touchX, touchY, coords);
    pixelX = func_0207c8ec(coords[0], 0x300);
    pixelY = func_0207c8ec(coords[1], 0x300);
    tileIndex = func_020caba4(pixelX, pixelY, arg);
    if (tileIndex >= 0) {
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = pixelX;
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = pixelY;
        *outTileIndex = tileIndex;
    }
    if (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0) {
        M2C_FIELD(*gCurrentMap, s16 *, 0x52CA) = pixelX;
        M2C_FIELD(*gCurrentMap, s16 *, 0x52CC) = pixelY;
        map = *gCurrentMap;
        func_020bd0a8(M2C_FIELD(map, s16 *, 0x52CA), M2C_FIELD(map, s16 *, 0x52CC));
    }
    map = *gCurrentMap;
    if (M2C_FIELD(map, s16 *, 0x52CA) == pixelX && M2C_FIELD(map, s16 *, 0x52CC) == pixelY) return;
    func_020bd0e0();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52CA) = 255;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52CC) = 255;
}

s32 func_020bdbf4(s32 arg0) {
s32 func_020947c0(void); void func_0207bb3c(u16,u16,s32 *); s32 func_0207c8ec(s32,s32); void func_020bd104(void); s32 func_020caba4(s32,s32,s32); extern void *data_02101e88; extern void **gCurrentMap;
s32 coords[3];u16 x,y;s32 scaledX,scaledY,result;
x=M2C_FIELD(data_02101e88,u16 *,0);y=M2C_FIELD(data_02101e88,u16 *,2);
if(func_020947c0()!=0)return 0;
func_0207bb3c(x,y,coords);scaledX=func_0207c8ec(coords[0],0x300);scaledY=func_0207c8ec(coords[1],0x300);
if(M2C_FIELD(data_02101e88,u8 *,0x16)==0)return 0;
if(scaledX==M2C_FIELD(*gCurrentMap,s16 *,0x52ca)&&scaledY==M2C_FIELD(*gCurrentMap,s16 *,0x52cc)){func_020bd104();if(func_020caba4(scaledX,scaledY,arg0)>=0)result=0x10;else result=0x20;}else result=0;return result;
}

s32 func_020bdcd0(void) {
    s32 func_020947c0();
    extern void *data_02101e88;
    if (func_020947c0() != 0) {
        return 0;
    }
    if ((M2C_FIELD(data_02101e88, u8 *, 0x12) == 0) || ((u32) M2C_FIELD(data_02101e88, u8 *, 0x10) < 0x14U)) {
        return 0x20;
    }
    return 0;
}

s32 func_020bdd18(void) {
 s32 func_020947c0(void);
 void func_020bd0e0(void);
 void func_020bd104(void);
 extern void *data_02101e88;
 extern void **gCurrentMap;
 if (func_020947c0()) return 0;
 if (M2C_FIELD(data_02101e88,u8 *,0x12) && M2C_FIELD(data_02101e88,u8 *,0x10)==20) {
 func_020bd0e0();
 M2C_FIELD(*gCurrentMap,s16 *,0x52ca)=255;
 M2C_FIELD(*gCurrentMap,s16 *,0x52cc)=255;
 }
 if (M2C_FIELD(data_02101e88,u8 *,0x16) &&
 M2C_FIELD(*gCurrentMap,s16 *,0x52c2)==M2C_FIELD(*gCurrentMap,s16 *,0x52ca) &&
 M2C_FIELD(*gCurrentMap,s16 *,0x52c4)==M2C_FIELD(*gCurrentMap,s16 *,0x52cc)) {
 func_020bd104(); return 16;
 }
 return 0;
}

/* Update the selection cursor from the current stylus position and return any resulting action code. */
s32 func_020bddd4(void) {
    s32 func_020947c0(void);
    s32 func_020bdef8(s32, s32);
    void func_020bd0e0(void);
    void func_020bd104(void);
    extern void *data_02101e88;
    extern void **gCurrentMap;

    u16 touchX, touchY;
    touchX = M2C_FIELD(data_02101e88, u16 *, 0);
    touchY = M2C_FIELD(data_02101e88, u16 *, 2);
    if (func_020947c0()) return 0;
    if (M2C_FIELD(data_02101e88, u8 *, 0x14)) {
        if (func_020bdef8(touchX, touchY)) return 32;
    }
    if (M2C_FIELD(data_02101e88, u8 *, 0x12) && M2C_FIELD(data_02101e88, u8 *, 0x10) == 20) {
        func_020bd0e0();
        M2C_FIELD(*gCurrentMap, s16 *, 0x52ca) = 255;
        M2C_FIELD(*gCurrentMap, s16 *, 0x52cc) = 255;
    }
    if (M2C_FIELD(data_02101e88, u8 *, 0x16) &&
        M2C_FIELD(*gCurrentMap, s16 *, 0x52c2) == M2C_FIELD(*gCurrentMap, s16 *, 0x52ca) &&
        M2C_FIELD(*gCurrentMap, s16 *, 0x52c4) == M2C_FIELD(*gCurrentMap, s16 *, 0x52cc)) {
        func_020bd104();
        return 16;
    }
    return 0;
}

s32 func_020bdecc(s32 arg0, s32 arg1) {
    if ((arg0 >= 0x70) && (arg0 <= 0x90) && (arg1 >= 0) && (arg1 <= 0x10)) {
        return 1;
    }
    return 0;
}

s32 func_020bdef8(s32 arg0, s32 arg1) {
    if ((arg0 >= 0x70) && (arg0 <= 0x90) && (arg1 >= 0) && (arg1 <= 0x10)) {
        return 1;
    }
    return 0;
}

s32 func_020bdf24(s32 arg0, s32 arg1) {
    if ((arg0 >= 0x70) && (arg0 <= 0x90) && (arg1 >= 0) && (arg1 <= 0x10)) {
        return 1;
    }
    return 0;
}

s32 func_020bdf50(s32 arg0, s32 arg1) {
    if ((arg0 >= 0x40) && (arg0 <= 0x60) && (arg1 >= 0) && (arg1 <= 0x10)) {
        return 1;
    }
    return 0;
}

s32 func_020bdf7c(s32 arg0, s32 arg1) {
    if ((arg0 >= 0xA0) && (arg0 <= 0xC0) && (arg1 >= 0) && (arg1 <= 0x10)) {
        return 1;
    }
    return 0;
}

void func_020bdfa8(void) {
    M2C_UNK func_020be0ac(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    func_020be0ac(0x70, 0, 0x20, 0x10, 0x9000, 0x1F0);
}

void func_020bdfdc(void) {
    func_020be0ac(0x70, 0, 0x20, 0x10, 0x9000, 0x1F8);
}

void func_020be010(void) {
    func_020be0ac(0x70, 0, 0x20, 0x10, 0x9000, 0x1E8);
}

void func_020be044(void) {
    func_020be0ac(0x40, 0, 0x20, 0x10, 0x9000, 0x200);
}

void func_020be078(void) {
    func_020be0ac(0xA0, 0, 0x20, 0x10, 0x9000, 0x208);
}

M2C_UNK func_020be0ac(M2C_UNK a,M2C_UNK b,M2C_UNK c,M2C_UNK d,s32 e,s32 f) {
 s32 func_01ff8e44(M2C_UNK,M2C_UNK);
 M2C_UNK func_01ff883c(u16,u8,u16,s32);
 extern u16 **gCur3DSpriteEngine;
 s32 v=func_01ff8e44(c,d);
 u32 shift;
 a &= 511;
 shift=(u32)(**gCur3DSpriteEngine<<17)>>30;
 b=(u8)b;
 e |= (f>>shift)&1023;
 return func_01ff883c((u16)a,b,(u16)e,v);
}

M2C_UNK *func_020be120(void) {
    extern M2C_UNK data_0215deec;
    return &data_0215deec;
}

void func_020be12c(void) {

}

void func_020be130(void *arg0) {
    s32 func_02076208();
    M2C_UNK func_02076244();
    M2C_UNK func_02086680(s32);
    M2C_UNK func_020e35cc(s32);
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x54);
    if (func_02076208() != 0) {
        func_02086680(0xC000034C);
        func_02076244();
    }
    if (temp_r4 == 0) {
        return;
    }
    func_020e35cc(temp_r4);
}

void func_020be168(M2C_UNK arg0) {
    s32 func_020761f8();
    M2C_UNK func_01ffa574(M2C_UNK);
    if (func_020761f8() != 0) {
        return;
    }
    func_01ffa574(arg0);
}

void func_020be188(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212948c;
    M2C_FIELD(func_01ffa3dc(&data_0212948c, 6), s32 *, 0x54) = arg0;
}

u8 func_020be1a8(void) {
 s32 func_01ffa770(M2C_UNK *);
 extern M2C_UNK data_0212948c;
 u8 result;
 if (func_01ffa770(&data_0212948c)) return 1;
 if (func_020761f8()) result=1; else result=0;
 return result;
}

void func_020be1dc(s32 arg0) {
void *func_02076228(void);s32 func_02076234(void);
M2C_UNK func_02076010(s32,s32);M2C_UNK func_02076180(u16);
u8 *p,*best;s32 n,i,id;register s32 better;register u32 high;u32 b,a;
switch(arg0){case 2:case 3:case 4:func_02076010(arg0,1);return;}
p=func_02076228();best=0;n=func_02076234();i=0;
if(n>0)do{if(arg0==p[2]){if(best){better=IsNewerValue(M2C_FIELD(best,u32 *,4),M2C_FIELD(p,u32 *,4));
if(!better)goto next;
}best=p;}next:i++;p+=40;}while(i<n);
if(best)id=*(u16 *)best;else id=-1;
if(id==-1)return;
func_02076180((u16)id);
}

void func_020be2e0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02075fd8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_02075fd8(arg0, 0, arg1, arg2);
}

void func_020be2f8(M2C_UNK arg0) {
    M2C_UNK func_020be718();
    func_020be718();
    func_020be1dc(4);
    func_020be2e0(arg0, 0x5CC, 4);
}

u8 func_020be324(s32 arg0,M2C_UNK arg1){
void *func_02076228(void);s32 func_02076234(void);s32 func_020761c0(u16,M2C_UNK);s32 func_02076208(void);M2C_UNK func_02086680(s32);M2C_UNK func_02076244();
u8 *p,*best;s32 n,i,id; s32 better; u32 high;u32 b,a;u8 result;
p=func_02076228();best=0;n=func_02076234();i=0;
if(n>0)do{if(arg0==p[2]){if(best){better=IsNewerValue(M2C_FIELD(best,u32 *,4),M2C_FIELD(p,u32 *,4));
if(!better)goto next;
}best=p;}next:i++;p+=40;}while(i<n);
if(best)id=*(u16 *)best;else id=-1;
if(id==-1)return 0;
result=func_020761c0(id,arg1);
if(func_02076208()){func_02086680(0xc000034d);func_02076244();}
return result;
}

void func_020be438(s32 a,s32 b,s32 c) {
 s32 func_020e34bc(s32);
 s32 v=0;
 func_020be1dc(a);
 func_020be2e0(b,c,(u8)a);
 if(a!=4) {v=func_020e34bc(0x6000);func_020be2f8(v);}
 func_02076198();
 func_020be188(v);
}

void func_020be488(s32 a) {
    s32 func_020e34bc(s32);
    s32 v=0;
    func_020be1dc(a);
    if(a!=4) {
        v=func_020e34bc(0x6000);
        func_020be2f8(v);
    }
    func_02076198();
    func_020be188(v);
}

s32 func_020be4c0(s32 arg0) { void *func_02076228(void); s32 func_02076234(void); u8 *p,*best; s32 n,i,id; register s32 better;register u32 high;u32 b,a;
p=func_02076228();best=0;n=func_02076234();i=0;
if(n>0)do{if(arg0==p[2]){if(best){a=M2C_FIELD(p,u32 *,4);b=M2C_FIELD(best,u32 *,4);high=a&0xffff0000;
if(high==0xffff0000 && !(b&0xffff0000) && b!=0)better=0;
else if(high==0 && (b&0xffff0000)==0xffff0000 && a!=0)better=1;
else better=a>b;
if(!better)goto next;
}best=p;}next:i++;p+=40;}while(i<n);
if(best)id=*(u16 *)best;else id=-1;return id!=-1; }

void func_020be59c(void) {
    M2C_UNK func_02076010(s32, M2C_UNK);
    M2C_UNK func_02076198();
    s32 var_r5;

    var_r5 = 4;
    do {
        func_02076010(var_r5, 0);
        var_r5 += 1;
    } while (var_r5 < 0x3B);
    func_02076198();
    func_020be188(0);
}

void func_020be5d0(void) {
M2C_UNK func_02086b9c();M2C_UNK func_02091bcc();M2C_UNK func_020bf814(M2C_UNK);M2C_UNK func_020bf8ac(s32,s32);M2C_UNK func_020bf8fc(s32,s32);M2C_UNK func_020bf9f0(M2C_UNK);M2C_UNK func_020bfa30(M2C_UNK);M2C_UNK func_020bfa80(M2C_UNK);M2C_UNK func_020e47f8();M2C_UNK func_020e49ec();
s32 i,j,k; s32 zero1,zero2;
M2C_FIELD(&data_0215d890,s32 *,0x128)=0x20070810;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~15;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0x70;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0xc00;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0x3000;
M2C_FIELD(&data_0215d990,u16 *,0x2e)|=0x4000;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0x8000;
func_020bfa80(0);
i=0;zero1=0;zero2=0;
do{func_020bf8ac(i,zero1);func_020bf8fc(i,zero2);++i;}while(i<15);
func_020bf814(0);func_020e47f8();func_020e49ec();func_02086b9c();func_02091bcc();
M2C_FIELD(&data_0215d990,u16 *,0x2e)=(M2C_FIELD(&data_0215d990,u16 *,0x2e)&~0x380)|0x80;
func_020bf9f0(95);func_020bfa30(95);
j=0;
M2C_FIELD(&data_0215d890,s32 *,0x140)=0;
M2C_FIELD(&data_0215d890,s32 *,0x144)=1;
M2C_FIELD(&data_0215d890,s32 *,0x148)=1;
M2C_FIELD(&data_0215d890,s32 *,0x14c)=6;
M2C_FIELD(&data_0215d890,s32 *,0x150)=0;
M2C_FIELD(&data_0215d890,s32 *,0x154)=0;
M2C_FIELD(&data_0215d890,s32 *,0x158)=0;
do{M2C_FIELD((u8 *)&data_0215d9b8+(u32)j*8,s16 *,0x36)=0;++j;}while(j<4);
k=0;
do{M2C_FIELD((u8 *)&data_0215d9b8+(u32)k*2,s16 *,8)=0;++k;}while(k<4);
}

