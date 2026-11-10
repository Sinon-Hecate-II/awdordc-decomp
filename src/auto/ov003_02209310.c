/* 3 functions from 0x02209310 to 0x02209D0C (ov003), found by ds-decomp. */
#include "common.h"

#pragma opt_common_subs off
#pragma opt_peephole off
void func_ov003_02209310(void *arg0) {
void func_ov003_0220a6bc(void *);
void func_ov003_0220bf98(void *);
void func_ov003_0220ac58(void *);
void func_ov003_0220856c(void *,s32,s32);
void func_02088e84(void *,s16,s32,s16,s32);
s32 func_020aae10(void *);
s32 func_020aae44(void *);
void func_02087d84(void *,s32,s16,s16,u16,u16);
s32 GetSpriteAnimValue(void *);
s32 func_0207c8ec(s32,s32);
void SetSpriteQuad(s32,s16,s16,s16,s16);
void AddSprite(u16,u16,u16,void *,s32);
s32 func_ov003_02206690(s32,s32,s32);
s32 func_02089080(void *);
void func_02088d94(void *);
s32 func_02089064(void *);
void func_02088da8(void *);
u16 *volatile blend;
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain,*g3DSpriteEngineSub;
extern s16 gSinCosTable[];
extern u8 data_ov003_022109cc[];
void *saved,*sprite,*obj,*child;
s32 boolean,state,kind,index,show,a,b,c,d,sine,cosine;
u32 scale,scale2;
s16 sy,sx,y,x;
s32 width;
if(!((u32)(M2C_FIELD(arg0,u8 *,0x38)<<25)>>31))return;
func_ov003_0220a6bc(arg0);
state=(u32)(M2C_FIELD(arg0,u8 *,0x36)<<24)>>28;
if(state==1)boolean=1;else boolean=0;
if(!(boolean&255)||!M2C_FIELD(arg0,u8 *,0x35))func_ov003_0220bf98(arg0);
func_ov003_0220ac58(arg0);
func_ov003_0220856c(arg0,16,2);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
a=M2C_FIELD(M2C_FIELD(arg0,void **,0x58),s16 *,2);
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x3c)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x44)=-a;
a=M2C_FIELD(M2C_FIELD(arg0,void **,0x58),s16 *,2);
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x3a)=0xfffe;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x42)=-a;
state=(u32)(M2C_FIELD(arg0,u8 *,0x36)<<24)>>28;
if(state==0)boolean=1;else boolean=0;
if(!(boolean&255)){
if(state==1)boolean=1;else boolean=0;
if(!(boolean&255)){if(state==2)boolean=1;else boolean=0;}
if(boolean&255){
sprite=M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,0);
func_02088e84(sprite,224,160,224,160);
if(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)boolean=1;else boolean=0;
if(boolean&255){sy=M2C_FIELD(sprite,s16 *,0x52);sx=M2C_FIELD(sprite,s16 *,0x50);width=func_020aae10(sprite);
func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)width,(u16)func_020aae44(sprite));}
M2C_FIELD(sprite,s16 *,0x34)=224;M2C_FIELD(sprite,s16 *,0x36)=160;
if(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)boolean=1;else boolean=0;
if(boolean&255){sy=M2C_FIELD(sprite,s16 *,0x52);sx=M2C_FIELD(sprite,s16 *,0x50);width=func_020aae10(sprite);
func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)width,(u16)func_020aae44(sprite));}
}}
kind=M2C_FIELD(M2C_FIELD(arg0,void **,0x3c),u8 *,15);if(kind==8)boolean=1;else boolean=0;
if(boolean&255){state=(u32)(M2C_FIELD(arg0,u8 *,0x36)<<24)>>28;
if(state==1)boolean=1;else boolean=0;
if(boolean&255)goto enabled0;
if(kind==8)boolean=1;else boolean=0;
if(!(boolean&255))goto disabled0;
if((u32)(M2C_FIELD(arg0,u8 *,0x38)<<28)>>31){boolean=1;goto test0;}
disabled0:boolean=0;
test0:if(!(boolean&255))goto normal0;
enabled0:scale=256;goto scaled0;
normal0:
scale=(u16)GetSpriteAnimValue(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void **,76),void **,28),void **,0));
scaled0:;
if(scale>1){
if((s32)scale>=2)scale2=scale;else if(scale>2)scale2=2;else{scale2=-2;if((s32)scale>=-2)scale2=scale;}
sine=gSinCosTable[1];cosine=gSinCosTable[0];
if((s32)scale<2){if(scale>2)scale=2;else if((s32)scale<-2)scale=-2;}
d=sine<<4;
a=func_0207c8ec(d,256);
b=func_0207c8ec((-cosine)<<4,scale);
c=func_0207c8ec(cosine<<4,256);
d=func_0207c8ec(d,scale2);
SetSpriteQuad(0,(s16)a,(s16)b,(s16)c,(s16)d);
obj=M2C_FIELD(arg0,void **,96);
boolean=M2C_FIELD(M2C_FIELD(obj,void **,0x1c),u8 *,6)|M2C_FIELD(obj,u8 *,6);
child=M2C_FIELD(obj,void **,0x1c);
a=(boolean&255)?7:6;
y=M2C_FIELD(child,s16 *,10)-(M2C_FIELD(child,u8 *,17)>>1);
x=M2C_FIELD(child,s16 *,8)-(M2C_FIELD(child,u8 *,16)>>1);
AddSprite((u16)((x&511)),(u16)((y&255)|256),(u16)((u32)(a<<28)>>16),data_ov003_022109cc,11);
}
state=(u32)(M2C_FIELD(arg0,u8 *,0x36)<<24)>>28;
if(state==1)boolean=1;else boolean=0;
if(boolean&255)goto enabled1;
if(M2C_FIELD(M2C_FIELD(arg0,void **,0x3c),u8 *,15)==8)boolean=1;else boolean=0;
if(!(boolean&255))goto disabled1;
if((u32)(M2C_FIELD(arg0,u8 *,0x38)<<28)>>31){boolean=1;goto test1;}
disabled1:boolean=0;
test1:if(!(boolean&255))goto normal1;
enabled1:scale=256;goto scaled1;
normal1:
scale=(u16)GetSpriteAnimValue(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void **,72),void **,64),void **,0));
scaled1:;
if(scale>1){
if((s32)scale>=2)scale2=scale;else if(scale>2)scale2=2;else{scale2=-2;if((s32)scale>=-2)scale2=scale;}
sine=gSinCosTable[1];cosine=gSinCosTable[0];
if((s32)scale<2){if(scale>2)scale=2;else if((s32)scale<-2)scale=-2;}
d=sine<<4;
a=func_0207c8ec(d,256);
b=func_0207c8ec((-cosine)<<4,scale);
c=func_0207c8ec(cosine<<4,256);
d=func_0207c8ec(d,scale2);
SetSpriteQuad(1,(s16)a,(s16)b,(s16)c,(s16)d);
obj=M2C_FIELD(arg0,void **,100);
boolean=M2C_FIELD(M2C_FIELD(obj,void **,0x1c),u8 *,6)|M2C_FIELD(obj,u8 *,6);
child=M2C_FIELD(obj,void **,0x1c);
a=(boolean&255)?7:6;
y=M2C_FIELD(child,s16 *,10)-(M2C_FIELD(child,u8 *,17)>>1);
x=M2C_FIELD(child,s16 *,8)-(M2C_FIELD(child,u8 *,16)>>1);
AddSprite((u16)((x&511)|512),(u16)((y&255)|256),(u16)((u32)(a<<28)>>16),data_ov003_022109cc,17);
}
}
obj=M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),void **,0);
index=((obj?M2C_FIELD(obj,u16 *,8):-1)-11)&255;
if(M2C_FIELD(M2C_FIELD(arg0,void **,0x3c),u8 *,15)==8)boolean=1;else boolean=0;
if(!(boolean&255)){show=0;goto decide;}
state=(u32)(M2C_FIELD(arg0,u8 *,0x36)<<24)>>28;
if(state==0)boolean=1;else boolean=0;
if(boolean&255){if(M2C_FIELD(arg0,u8 *,0x34)!=0)boolean=1;else boolean=0;if(boolean&255){show=0;goto decide;}}
if(!func_ov003_02206690(index,2,4)){show=0;goto decide;}
show=M2C_FIELD((u8 *)M2C_FIELD(arg0,void **,0x48)+index*36,u16 *,12)==256;
decide:

if(show){
sprite=M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,4);
if(func_02089080(sprite)){func_02088d94(M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,4));
obj=M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),void **,0);index=((obj?M2C_FIELD(obj,u16 *,8):-1)-11)&255;
y=(index-2)*30+62;
sprite=M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,4);
func_02088e84(sprite,129,y,129,y);
if(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)boolean=1;else boolean=0;
if(boolean&255){sy=M2C_FIELD(sprite,s16 *,0x52);sx=M2C_FIELD(sprite,s16 *,0x50);width=func_020aae10(sprite);
func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)width,(u16)func_020aae44(sprite));}
M2C_FIELD(sprite,s16 *,0x34)=129;M2C_FIELD(sprite,s16 *,0x36)=y;
if(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)boolean=1;else boolean=0;
if(boolean&255){sy=M2C_FIELD(sprite,s16 *,0x52);sx=M2C_FIELD(sprite,s16 *,0x50);width=func_020aae10(sprite);
func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)width,(u16)func_020aae44(sprite));}
}
sprite=M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,8);
if(func_02089080(sprite)){func_02088d94(M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,8));
obj=M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),void **,0);index=((obj?M2C_FIELD(obj,u16 *,8):-1)-11)&255;
y=(index-2)*30+62;
sprite=M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,8);
func_02088e84(sprite,223,y,223,y);
if(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)boolean=1;else boolean=0;
if(boolean&255){sy=M2C_FIELD(sprite,s16 *,0x52);sx=M2C_FIELD(sprite,s16 *,0x50);width=func_020aae10(sprite);
func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)width,(u16)func_020aae44(sprite));}
M2C_FIELD(sprite,s16 *,0x34)=223;M2C_FIELD(sprite,s16 *,0x36)=y;
if(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)boolean=1;else boolean=0;
if(boolean&255){sy=M2C_FIELD(sprite,s16 *,0x52);sx=M2C_FIELD(sprite,s16 *,0x50);width=func_020aae10(sprite);
func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)width,(u16)func_020aae44(sprite));}
}
}else{
if(func_02089064(M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,4)))func_02088da8(M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,4));
if(func_02089064(M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,8)))func_02088da8(M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,8));
}
gCur3DSpriteEngine=g3DSpriteEngineSub;
a=16-GetSpriteAnimValue(M2C_FIELD(arg0,void **,0x54));
b=GetSpriteAnimValue(M2C_FIELD(arg0,void **,0x54));
blend=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12);
*blend=(*blend&~0xc0)|0x40;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=b;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=a;
gCur3DSpriteEngine=saved;
}
#pragma opt_peephole reset
#pragma opt_common_subs reset
s32 func_ov003_02209cc8(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x1C), u8 *, 6) | M2C_FIELD(arg0, u8 *, 6);
}

u32 func_ov003_02209cdc(void *arg0) {
    M2C_UNK func_ov003_0220adb4(void *);
    u32 func_ov003_0220c10c(void *);
    M2C_UNK func_ov003_0220c43c();
    u32 temp_r0;

    func_ov003_0220c43c();
    temp_r0 = (u32) (M2C_FIELD(arg0, u8 *, 0x38) << 0x1B) >> 0x1F;
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_ov003_0220adb4(arg0);
    return func_ov003_0220c10c(arg0);
}

