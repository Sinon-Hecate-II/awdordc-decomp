/* 3 functions from 0x02211200 to 0x02212184 (ov006), found by ds-decomp. */
#include "common.h"
extern s32 gCur3DSpriteEngine,data_027e00c8,data_027e00c4;
extern u8 data_ov006_022183c0[],data_ov006_0221861c[],data_ov006_02218624[],data_ov006_02218634[],data_ov006_02218644[],data_ov006_02218658[],data_ov006_02218668[],data_ov006_02218670[],data_ov006_02218680[],data_ov006_02218690[],data_ov006_022186a4[];
void func_01ff9ce8(s32);
void func_01ff9dd8(s32);
void func_0200bc5c(void *);
void *func_020e3218(void *);
void func_020814e4(void *);
void func_02081590(void *,s32);
void func_02081528(void);
void func_02081340(void *,s32,s32,s32);
void func_020808dc(s32,s32,s32,s32);
void func_02080944(s32,s32,s32,s32);
s32 func_020a9a30(s32,s32,s32,s32);
void func_02091d4c(s32);
s32 func_020ae22c(s32);
void func_0208ca2c(s32,s32,s32,s32);
void *func_0208206c(void);
void func_020e4cd8(void *,s32,s32,s32,s32,s32,s32);
void func_ov000_0216a470(void);
void *func_ov000_0216a564(void);
void func_ov000_0216a30c(void *,s32,s32);
s32 func_ov000_0216a76c(void);
void *func_ov000_0216a77c(s32);
s32 func_ov000_0216a7c4(void);
void *func_ov000_0216a7d4(s32);
void *func_0209b26c(s32,s32,s32,void *,s32,s32);
void func_02088f1c(void *);
static inline void Bits02211388(s32 offset,u16 set,u16 clear){
u16 *volatile p=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+offset);
*p=(*p&~clear)|set;
}

static inline void SetBits02211388(u16 bit){u16 *volatile p=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*p|=bit;}
static inline void ClearBits02211388(s32 offset,u16 bit){u16 *volatile p=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+offset);*p&=~bit;}
void *func_020ab1c4(void *);
void func_020aab24(void *,s32,s32,s32,s32);
void func_02088e84(void *,s32,s32,s32,s32);
s32 func_020aae10(void *);
s32 func_020aae44(void *);
void func_02087d84(void *,s32,s32,s32,s32,s32);
void func_020aad18(void *);
void func_020a92bc(void *,s32);
static inline u8 Visible02211388(void *p){return M2C_FIELD(M2C_FIELD(p,void **,0x64),u8 *,0x12)!=0;}



void func_ov006_02211200(void *arg0) {
M2C_UNK func_01ff9b38();
M2C_UNK func_02002bb8(M2C_UNK);
M2C_UNK func_02003560();
M2C_UNK func_020822b8(M2C_UNK *);
M2C_UNK func_02082cb4();
void *func_0208931c(M2C_UNK);
M2C_UNK func_020a9a30(M2C_UNK,M2C_UNK,M2C_UNK,s32);
s32 func_020aaf74(void *);
M2C_UNK func_020aeebc(M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_020aef7c(M2C_UNK,M2C_UNK,M2C_UNK);
extern s32 data_027e00c4;
extern s32 data_027e00c8;
extern s32 gCur3DSpriteEngine;
extern M2C_UNK data_ov006_022183c8;
extern M2C_UNK data_ov006_022183d4;
s32 saved; void *p;
func_02082cb4();func_02003560();func_02002bb8(64);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
func_020822b8(&data_ov006_022183c8);func_020aeebc(2,15,5);
gCur3DSpriteEngine=data_027e00c4;
func_020822b8(&data_ov006_022183d4);func_020aef7c(2,15,5);
p=M2C_FIELD(arg0,void **,0x38)=func_0208931c(9);
M2C_FIELD(p,u8 *,0x58)=6;
func_020a9a30(2,0,6,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x4580);
func_020a9a30(2,2,6,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30)+0x320);
M2C_FIELD(p,s32 *,0x44)=func_020aaf74(p);
M2C_FIELD(p,u16 *,0x3e)=0x22c;
M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|0x640000;
M2C_FIELD(p,u16 *,0x3c)=0xc00;
gCur3DSpriteEngine=saved;func_01ff9b38();
}

void func_ov006_02211314(M2C_UNK arg0) {
    M2C_UNK func_020899cc(void *, M2C_UNK, s32, s32);
    void *func_0208b564(M2C_UNK);
    s64 func_020c53e4(M2C_UNK);
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r4;
    void *temp_r0;
    if (func_020c53e4(0) == 0) {
        temp_r4 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = data_027e00c8;
        temp_r0 = func_0208b564(arg0);
        func_020899cc(temp_r0, 2, 0x4640, 0x42000001);
        M2C_FIELD(temp_r0, s32 *, 0x58) |= 0x1000;
        gCur3DSpriteEngine = temp_r4;
    }
}

void func_ov006_02211388(void *arg0){void **items=M2C_FIELD(arg0,void ***,0x3c);void *w; s32 y,x,a,b,saved;items[0]=func_020ab1c4(arg0);func_020aab24(items[0],2,336,3,1);w=items[0];func_02088e84(w,224,160,224,192);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=func_020aae10(w);b=func_020aae44(w);func_02087d84(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[0];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[0]);
items[1]=func_020ab1c4(arg0);func_020aab24(items[1],10,352,3,0);w=items[1];func_02088e84(w,94,142,94,142);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=func_020aae10(w);b=func_020aae44(w);func_02087d84(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
M2C_FIELD(w,u16 *,0x34)=94;M2C_FIELD(w,u16 *,0x36)=142;if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=func_020aae10(w);b=func_020aae44(w);func_02087d84(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[1];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[1]);
items[2]=func_020ab1c4(arg0);func_020aab24(items[2],11,360,3,0);w=items[2];func_02088e84(w,130,142,130,142);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=func_020aae10(w);b=func_020aae44(w);func_02087d84(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
M2C_FIELD(w,u16 *,0x34)=130;M2C_FIELD(w,u16 *,0x36)=142;if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=func_020aae10(w);b=func_020aae44(w);func_02087d84(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[2];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[2]);
items[3]=func_020ab1c4(arg0);func_020aab24(items[3],39,368,3,0);w=items[3];func_02088e84(w,48,164,48,192);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=func_020aae10(w);b=func_020aae44(w);func_02087d84(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[3];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[3]);
items[4]=func_020ab1c4(arg0);func_020aab24(items[4],41,404,3,0);w=items[4];func_02088e84(w,104,164,104,192);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=func_020aae10(w);b=func_020aae44(w);func_02087d84(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[4];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[4]);
items[5]=func_020ab1c4(arg0);func_020aab24(items[5],40,386,3,0);w=items[5];func_02088e84(w,160,164,160,192);if(Visible02211388(w)){y=M2C_FIELD(w,s16 *,0x52);x=M2C_FIELD(w,s16 *,0x50);a=func_020aae10(w);b=func_020aae44(w);func_02087d84(M2C_FIELD(w,void **,0x64),1,x,y,(u16)a,(u16)b);}
w=items[5];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_020aad18(items[5]);
M2C_FIELD(M2C_FIELD(arg0,void **,64),u8 *,0x16)=2;M2C_FIELD(M2C_FIELD(arg0,void **,64),u8 *,0x14)=8;M2C_FIELD(M2C_FIELD(arg0,void **,64),u8 *,0x17)=8;func_020a92bc(M2C_FIELD(arg0,void **,64),0);
w=M2C_FIELD(arg0,void **,64);M2C_FIELD(w,u8 *,0x20)=(M2C_FIELD(w,u8 *,0x20)&~0xe0)|64;
w=M2C_FIELD(arg0,void **,64);M2C_FIELD(w,u8 *,0x28)=(M2C_FIELD(w,u8 *,0x28)&~0xe0)|64;
M2C_FIELD(M2C_FIELD(arg0,void **,64),u16 *,0x12)=422;M2C_FIELD(M2C_FIELD(arg0,void **,64),u8 *,0x21)=22;M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,0x16)=4;M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,0x14)=16;M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,0x17)=16;func_020a92bc(M2C_FIELD(arg0,void **,68),0);
w=M2C_FIELD(arg0,void **,68);M2C_FIELD(w,u8 *,0x20)=(M2C_FIELD(w,u8 *,0x20)&~0xe0)|0;
w=M2C_FIELD(arg0,void **,68);M2C_FIELD(w,u8 *,0x28)=(M2C_FIELD(w,u8 *,0x28)&~0xe0)|0;
M2C_FIELD(M2C_FIELD(arg0,void **,68),u16 *,0x12)=480;M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,0x21)=23;M2C_FIELD(M2C_FIELD(arg0,void **,68),void **,0x24)=data_ov006_022183c0;
w=M2C_FIELD(arg0,void **,72);M2C_FIELD(w,u16 *,14)=0;M2C_FIELD(w,u16 *,16)=0;M2C_FIELD(w,u16 *,12)=12;M2C_FIELD(w,u16 *,2)=M2C_FIELD(w,u16 *,4);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|16;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|32;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|64;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|128;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|256;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=*reg&~192;}
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x53)=0;
func_01ff9ce8(0);
func_0200bc5c(data_ov006_0221861c);
func_020814e4(func_020e3218(data_ov006_02218624));
func_02081590(func_020e3218(data_ov006_02218634),M2C_FIELD(gCur3DSpriteEngine,s32 *,12));
func_02081590(func_020e3218(data_ov006_02218644),M2C_FIELD(gCur3DSpriteEngine,s32 *,32));
func_02081528();
func_02081340(data_ov006_02218658,160,0,32);
func_020808dc(M2C_FIELD(gCur3DSpriteEngine,s32 *,32),32,32,5);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;func_01ff9ce8(3);
w=(void *)gCur3DSpriteEngine;func_020a9a30(3,0,0,M2C_FIELD(w,s32 *,24));
w=(void *)gCur3DSpriteEngine;func_020a9a30(3,2,0,M2C_FIELD(w,s32 *,48)+224);
func_020808dc(M2C_FIELD(gCur3DSpriteEngine,s32 *,44),32,32,7);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;func_01ff9ce8(1);func_01ff9dd8(1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;func_02091d4c(6);
w=(void *)gCur3DSpriteEngine;func_020a9a30(1,0,1,M2C_FIELD(w,s32 *,28)+0x34c0);
w=(void *)gCur3DSpriteEngine;func_020a9a30(1,2,0,M2C_FIELD(w,s32 *,48)+0x2c0);
w=(void *)gCur3DSpriteEngine;func_020a9a30(1,0,5,M2C_FIELD(w,s32 *,28)+0x37c0);
func_0208ca2c(0x3e40,1,func_020ae22c(9),2);
func_0208ca2c(0x4240,1,func_020ae22c(12),2);gCur3DSpriteEngine=data_027e00c4;{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|16;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|32;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|64;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg&~128;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|256;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=*reg&~192;}
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x53)=0;
func_01ff9ce8(0);
func_0200bc5c(data_ov006_02218668);
func_020814e4(func_020e3218(data_ov006_02218670));
func_02081590(func_020e3218(data_ov006_02218680),M2C_FIELD(gCur3DSpriteEngine,s32 *,12));
func_02081590(func_020e3218(data_ov006_02218690),M2C_FIELD(gCur3DSpriteEngine,s32 *,32));
func_02081528();
func_02081340(data_ov006_022186a4,160,0,64);
func_02080944(M2C_FIELD(gCur3DSpriteEngine,s32 *,32),32,32,5);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;func_01ff9ce8(1);
func_01ff9dd8(1);func_02091d4c(7);
a=2;w=(void *)gCur3DSpriteEngine;
func_020e4cd8(func_0208206c(),M2C_FIELD(w,s32 *,16),M2C_FIELD(w,s32 *,36),7,6,4,a);
a+=48;func_ov000_0216a470();func_ov000_0216a30c(func_ov000_0216a564(),0x4280,8);
if(func_ov000_0216a76c()!=-2 && func_ov000_0216a76c()!=-1){
w=func_0209b26c(12,7,1,func_ov000_0216a77c(func_ov000_0216a76c()),0x7000,(u16)a);
a+=M2C_FIELD(w,u16 *,76)-M2C_FIELD(w,u16 *,78)+2;
x=(s16)(M2C_FIELD(w,u8 *,74)+2);
func_0209b26c(x,7,1,func_ov000_0216a7d4(func_ov000_0216a7c4()),0x7000,(u16)a);
}
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=2;
w=(void *)gCur3DSpriteEngine;func_020a9a30(1,0,5,M2C_FIELD(w,s32 *,28)+0x3c00);
w=(void *)gCur3DSpriteEngine;func_020a9a30(1,2,0,M2C_FIELD(w,s32 *,48)+0x2e0);
gCur3DSpriteEngine=saved;items=M2C_FIELD(arg0,void ***,60);
func_02088f1c(items[0]);
w=items[1];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;w=items[2];a=(u16)(((u32)(M2C_FIELD(w,u8 *,0x59)<<28)>>28)+2);M2C_FIELD(w,u32 *,0x40)=(M2C_FIELD(w,u32 *,0x40)&~0x3fc0000)|((u32)(a<<24)>>6);M2C_FIELD(w,u8 *,0x5a)=0;func_02088f1c(items[3]);func_02088f1c(items[4]);func_02088f1c(items[5]);}

