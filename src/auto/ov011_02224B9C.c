/* 42 functions from 0x02224B9C to 0x02225A9C (ov011), found by ds-decomp. */
#include "common.h"
typedef struct { s32 words[5]; } ContextTemplate;
extern ContextTemplate data_ov011_02227f3c;
extern void *gCur3DSpriteEngine, *data_027e00c4, *data_027e00c8;

/* Submit a 2D sprite/quad to one of the two 3D sprite engines (screen 0 or 1,
   selected by arg1, or to the engine already active when arg1 is 3) using the
   geometry template data_ov011_02227f3c with its corner fields overwritten;
   arg2 picks the vertex list offset inside the active engine's state block. */
void G3_SubmitSpriteQuad(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s16 arg4) {
void func_02082a8c(void *, void *);
ContextTemplate temp = data_ov011_02227f3c;
void *saved; void *p; s32 i;
((s16 *)&temp)[4]=arg3; ((s16 *)&temp)[5]=(s16)arg4;
saved=gCur3DSpriteEngine; i=0;
do {
if(i==0)p=data_027e00c8; else p=data_027e00c4;
gCur3DSpriteEngine=p;
if((arg1!=0 || p==data_027e00c8) && (arg1!=1 || p==data_027e00c4) && (arg1!=3 || p==saved)) {
switch(arg2) {case 2: func_02082a8c(&temp,(u8 *)*(void **)p+0x14); break; case 3: func_02082a8c(&temp,(u8 *)*(void **)p+0x24); break;}
}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;
}

void func_ov011_02224f00(M2C_UNK arg0) {
    M2C_UNK func_ov011_02222010(M2C_UNK, M2C_UNK, M2C_UNK);

    func_ov011_022216d8(arg0, 7, 0, 3);
    func_ov011_022216d8(arg0, 8, 1, 3);
    func_ov011_02222010(arg0, 4, 0);
    G3_SubmitSpriteQuad(arg0, 2, 2, 0x80, 0x20);
}

void func_ov011_02224f64(void) {
    M2C_UNK func_ov011_0222140c();
    func_ov011_0222140c();
}

void func_ov011_02224f70(void) {
    M2C_UNK func_ov011_022247f4();
    func_ov011_022247f4();
}

void func_ov011_02224f7c(void) {

}

void func_ov011_02224f80(void) { u32 v=*(u16 *)0x04000006 & 255; u8 a=0; u8 b; if(v<160) a=8-(s32)(v*8)/160; b=16-a; *(u16 *)0x04000052=(a&31)|((b&31)<<8); }

void func_ov011_02224fe0(M2C_UNK arg0) {
    func_ov011_022216d8(arg0, 1, 1, 0);
    func_ov011_022216d8(arg0, 0, 0, 0);
}

void func_ov011_02225010(M2C_UNK arg0) {
    M2C_UNK func_0208f780(s32);
    M2C_UNK func_ov011_0222161c();
    M2C_UNK func_ov011_02222204(M2C_UNK);
    func_ov011_0222161c();
    func_ov011_02222204(arg0);
    func_0208f780(0x1001D);
}

void func_ov011_02225034(void) {
    M2C_UNK func_ov011_022224a8();
    func_ov011_022224a8();
}

void func_ov011_02225040(void) {
    M2C_UNK func_ov011_0222166c();
    func_ov011_0222166c();
}

void func_ov011_0222504c(void) {
    M2C_UNK func_ov011_02223cb8();
    func_ov011_02223cb8();
}

void func_ov011_02225058(void) {
    M2C_UNK func_ov011_022242dc();
    func_ov011_022242dc();
}

void func_ov011_02225064(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x39) = (u8) (M2C_FIELD(arg0, u8 *, 0x39) + 1);
}

void func_ov011_02225074(M2C_UNK arg0) {
    M2C_UNK func_ov011_0222491c();
    M2C_UNK func_ov011_022224a8(M2C_UNK);
    func_ov011_0222491c();
    func_ov011_022224a8(arg0);
}

void func_ov011_0222508c(void) {
    M2C_UNK func_0207fa74(void (*)(void));
    void func_ov011_02224f80(void);
    func_0207fa74(&func_ov011_02224f80);
}

void func_ov011_022250a0(void) {
    M2C_UNK func_0207faa0();
    func_0207faa0();
}

void func_ov011_022250ac(M2C_UNK arg0) {
    M2C_UNK func_ov011_022216d8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_ov011_022216d8(arg0, 0x16, 0, 0);
}

void func_ov011_022250c4(M2C_UNK arg0) {
    s32 func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_ov011_02221320(s32, M2C_UNK);
    extern M2C_UNK data_ov011_02227fa4;
    s32 temp_r0;

    temp_r0 = func_01ffa42c(&data_ov011_02227fa4, arg0);
    if (temp_r0 == 0) {
        return;
    }
    func_ov011_02221320(temp_r0, 0);
}

void func_ov011_022250ec(M2C_UNK arg0) { s32 func_01ffa42c(M2C_UNK *,M2C_UNK); M2C_UNK func_ov011_02221320(s32,M2C_UNK); extern M2C_UNK data_ov011_02227fa4; s32 t=func_01ffa42c(&data_ov011_02227fa4,arg0); if(t==0)return; func_ov011_02221320(t,1); }

void func_ov011_02225114(M2C_UNK arg0) { s32 func_01ffa42c(M2C_UNK *,M2C_UNK); M2C_UNK func_ov011_02221320(s32,M2C_UNK); extern M2C_UNK data_ov011_02227fa4; s32 t=func_01ffa42c(&data_ov011_02227fa4,arg0); if(t==0)return; func_ov011_02221320(t,2); }

/* Initialize the DS 3D graphics hardware: reset the geometry engine, configure the LCD display control mode,
   program the viewport/projection matrix blocks, and set up the 3D command and capture registers. */
void func_ov011_0222513c(void) {
    M2C_UNK func_02003bd0();
    M2C_UNK func_02003dfc(M2C_UNK, M2C_UNK, s32, M2C_UNK, s32);
    M2C_UNK func_02003fc8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32);
    func_02003bd0();
    *(u16 *)0x04000060 = (*(u16 *)0x04000060 & ~0x3000) | 8;
    func_02003dfc(0, 0, 0x7FFF, 0x3F, 0);
    M2C_FIELD((void *)0x040004C8, s32 *, 0) = 0x1FF00000;
    M2C_FIELD((void *)0x040004C8, s32 *, 4) = 0x7FFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -8) = 0x7FFFFFFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -4) = 0x7FFF7FFF;
    M2C_FIELD((void *)0x040004C8, s32 *, 0xB8) = 0xBFFF0000;
    M2C_FIELD((void *)0x040004C8, s32 *, -0x88) = 0;
    func_02003fc8(0, 0xC0, 0, 0x100, -0x3E8, 0, 0x1000, 1, 0);
    M2C_FIELD((void *)0x04000440, s32 *, 0) = 3;
    M2C_FIELD((void *)0x04000440, s32 *, 0x14) = 0;
    M2C_FIELD((void *)0x04000440, s32 *, 0) = 2;
    M2C_FIELD((void *)0x04000440, s32 *, 0x14) = 0;
    M2C_FIELD((void *)0x04000440, s32 *, 0x44) = 0x20000000;
    M2C_FIELD((void *)0x04000440, s32 *, 0xC) = 0;
}

void func_ov011_02225224(void) {
    *(s32 *)0x04000540 = 1;
}

void func_ov011_02225348(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s16 arg3, s16 arg4, register u32 arg5) {
 M2C_UNK func_01ffa574(void *);
 s16 func_0207ca38(M2C_UNK, M2C_UNK, s16, u32, s32);
 u32 temp_ip; void *temp_r3; s32 x,y;
 temp_ip=M2C_FIELD(arg0,u32 *,0x48);
 if(temp_ip >= (u32)(arg5-1)) {
 if(M2C_FIELD(arg0,void **,0x4c)!=NULL) func_01ffa574(M2C_FIELD(arg0,void **,0x4c));
 M2C_FIELD(arg0,void **,0x4c)=NULL; return; }
 M2C_FIELD(arg0,s16 *,0x38)=func_0207ca38(0,arg1,arg3,temp_ip,arg5);
 M2C_FIELD(arg0,s16 *,0x3a)=func_0207ca38(0,arg2,arg4,M2C_FIELD(arg0,u32 *,0x48),arg5);
 temp_r3=M2C_FIELD(arg0,void **,0x4c); if(!temp_r3)return;
 y=M2C_FIELD(arg0,s16 *,0x3a); x=M2C_FIELD(arg0,s16 *,0x38);
 M2C_FIELD(temp_r3,s32 *,0x34)=x; M2C_FIELD(temp_r3,s32 *,0x38)=y; M2C_FIELD(temp_r3,s32 *,0x3c)=0;
}

void func_ov011_022253f0(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    M2C_FIELD(arg0, s16 *, 0x3C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x3E) = arg2;
    M2C_FIELD(arg0, s16 *, 0x40) = arg3;
    M2C_FIELD(arg0, s16 *, 0x42) = arg4;
}

void func_ov011_02225408(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x35) = arg1;
}

void func_ov011_02225410(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x34) = arg1;
}

void func_ov011_02225418(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x50) = arg1;
}

void func_ov011_02225420(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x54) = arg1;
}

void func_ov011_02225600(void) {

}

void func_ov011_02225604(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) + 1);
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) (M2C_FIELD(arg0, s32 *, 0x48) + M2C_FIELD(arg0, u8 *, 0x36));
}

void func_ov011_02225624(void *arg0) {
 M2C_UNK func_01ffa574(void *); void func_ov011_02225428(void *,s32);
 if(M2C_FIELD(arg0,s32 *,0x50))func_ov011_02225428(arg0,M2C_FIELD(arg0,s32 *,0x50));
 func_ov011_02225348(arg0,M2C_FIELD(arg0,s16 *,0x3c),M2C_FIELD(arg0,s16 *,0x3e),M2C_FIELD(arg0,s16 *,0x40),M2C_FIELD(arg0,s16 *,0x42),120);
 if(M2C_FIELD(arg0,u32 *,0x44)<199)return; func_01ffa574(arg0);
}

void *func_ov011_02225684(M2C_UNK **arg0) { M2C_UNK func_02086608(s32); extern M2C_UNK data_02129b9c; extern M2C_UNK data_ov011_02228b08; register s32 i; M2C_FIELD(arg0,M2C_UNK **,0)=&data_ov011_02228b08; i=0; M2C_FIELD(arg0,u8 *,0x34)|=2; M2C_FIELD(arg0,s16 *,0x3a)=0; M2C_FIELD(arg0,s8 *,0x37)=0; M2C_FIELD(arg0,s8 *,0x38)=0; M2C_FIELD(arg0,u8 *,0x34)&=~0xf0; M2C_FIELD(arg0,u8 *,0x35)&=~15; M2C_FIELD(arg0,s32 *,0x50)=0; do { arg0[i+16]=0; i++; }while(i<3); M2C_FIELD(arg0,M2C_UNK **,0x4c)=&data_02129b9c; func_02086608(10); return arg0; }

void *func_ov011_02225704(M2C_UNK **arg0) { M2C_UNK func_01ffa574(void *); M2C_UNK func_02086658(s32); extern M2C_UNK data_ov011_02228b08; register s32 i; M2C_FIELD(arg0,M2C_UNK **,0)=&data_ov011_02228b08; i=0; do {void *p=arg0[i+16]; if(p) {func_01ffa574(p); arg0[i+16]=0;} i++;}while(i<3); func_02086658(10);  return arg0; }

void *func_ov011_02225758(M2C_UNK **arg0) { M2C_UNK func_01ffa574(void *); M2C_UNK func_02086658(s32); extern M2C_UNK data_ov011_02228b08; register s32 i; M2C_FIELD(arg0,M2C_UNK **,0)=&data_ov011_02228b08; i=0; do {void *p=arg0[i+16]; if(p) {func_01ffa574(p); arg0[i+16]=0;} i++;}while(i<3); func_02086658(10); func_02082040(arg0); return arg0; }

void func_ov011_022257b4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 *, 4);
}

void func_ov011_022257c4(void *arg0) {
s32 func_02086680(s32); s32 func_0209b5e4(s32,s32); void func_0209b67c(u16,s32,u16,s32,s32);
extern void *data_027e00c8; extern void *gCur3DSpriteEngine;
s16 width,x; u16 w; void *saved;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
width=func_0209b5e4(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c),func_02086680(M2C_FIELD(arg0,s32 *,0x50)));
x=128-width/2;w=width;
func_0209b67c((u16)(x&511),14,w,0xf800,11);
func_0209b67c((u16)((x+1)&511),15,w,0xe800,17);
gCur3DSpriteEngine=saved;
}

s32 func_ov011_02225a18(void *arg0) {
    return *M2C_FIELD(arg0, s32 **, 0x4C);
}

void func_ov011_02225a24(void *arg0,s32 arg1,s32 arg2){s16 x,y;s32 i;void *p;i=0;if((s32)((u32)(M2C_FIELD(arg0,u8 *,0x35)<<28)>>28)<=0)return;do{p=((void **)((u8 *)arg0+0x40))[i];x=M2C_FIELD(p,s16 *,0x38);if(x-18<=arg1&&arg1<x+18){y=M2C_FIELD(p,s16 *,0x3a);if(y-18<=arg2&&arg2<y+18)M2C_FIELD(p,u8 *,0x36)=2;}i++;}while(i<(s32)((u32)(M2C_FIELD(arg0,u8 *,0x35)<<28)>>28));}

