/* 3 functions from 0x021E4B94 to 0x021E59E4 (ov002), found by ds-decomp. */
#include "common.h"
extern u16 **gCur3DSpriteEngine;
extern u8 data_027e00ac[],data_027e007c[],gSpriteDesc16x8[],gSpriteDesc16x16[],data_ov002_021f30ff[],data_ov002_021f3101[],gPlayerSettings[];
void func_02087064(s32,s32,s32,s32,s32);
void func_020878c4(s32,s32,s32,s32,s32,s32,s32,s32,s32);
void func_ov002_021e482c(s32,s32,s32,s32);
void func_ov002_021e48e8(s32,s32,s32,s32);
void AddSprite(u16,u16,u16,void *,s32);
s32 GetLanguage(void);
s32 RandomIntRange(s32,s32);
void func_ov002_021e497c(s32,s32,s32,s32);

extern u8 data_ov002_021f30fd[],data_ov002_021f30fe[],data_ov002_021f3107[],data_ov002_021f3105[],data_ov002_021f3106[];
extern u8 data_ov002_021f303e[],data_ov002_021f3040[],data_ov002_021f3042[],data_ov002_021f3044[],data_ov002_021f3018[];
s32 EaseInterpolate(s32,s32,s32,s32,s32);
void func_0208718c(void);
void func_020871a8(s32,s32,s32,s32,s32,u16);
void func_ov002_021e5974(s32 *,s32 *);
void func_ov002_021e4368(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
void func_ov002_021e447c(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
s32 func_ov002_021e4b68(void);
void func_ov002_021e4728(s32,s32,s32,s32,s32);
void func_ov002_021e47b0(s32,s32,s32,s32,s32);
void func_ov002_021e45c0(s32,s32,s32,s32,s32);
void func_ov002_021e4674(s32,s32,s32,s32,s32);


void func_ov002_021e4b94(void *arg0) {
u8 *p=arg0; s32 width,b,a,color,tiles,offset,yy,i,xx;s16 x,y;
width=EaseInterpolate(0,data_ov002_021f30fd[((u32)(p[3]<<28)>>28)*24],data_ov002_021f30fe[((u32)(p[3]<<28)>>28)*24],p[0],p[1]);
y=166-(s8)p[2];func_0208718c();func_020871a8(0,y,10,256,20,0x1cc2);
offset=((u32)(p[3]<<28)>>28)*24;
color=data_ov002_021f3107[offset]?M2C_FIELD(p,u16 *,6):0x7fff;
if(data_ov002_021f3105[offset]){
if(data_ov002_021f3106[offset]!=2){
y=168-(s8)p[2];func_0208718c();a=91;b=82;
if(((u32)(p[3]<<28)>>28)==1)func_ov002_021e5974(&a,&b);
if(((u32)(p[3]<<28)>>28)==0)func_ov002_021e4368(0,y,a,y,0,y+16,b,y+16,9,0);
else func_ov002_021e4368(256-a,y,256,y,256-b,y+16,256,y+16,9,0);
y=169-(s8)p[2];func_0208718c();a=84;b=76;
if(((u32)(p[3]<<28)>>28)==1)func_ov002_021e5974(&a,&b);
if(((u32)(p[3]<<28)>>28)==0)func_ov002_021e447c(0,y,a,y,0,y+14,b,y+14,8,color,0);
else func_ov002_021e447c(256-a,y,256,y,256-b,y+14,256,y+14,8,color,1);
if(data_ov002_021f3105[((u32)(p[3]<<28)>>28)*24]){
y=167-(s8)p[2];
tiles=M2C_FIELD((func_ov002_021e4b68()?data_ov002_021f3040:data_ov002_021f303e)+((u32)(p[3]<<28)>>28)*100,u16 *,0);
if(((u32)(p[3]<<28)>>28)==0)func_ov002_021e4728(0,y,0,tiles,data_ov002_021f3044[((u32)(p[3]<<28)>>28)*100]);
else func_ov002_021e47b0(208,y,0,tiles,data_ov002_021f3044[((u32)(p[3]<<28)>>28)*100]);
}
}else{
y=154-(s8)p[2];func_0208718c();a=97;b=80;
if(((u32)(p[3]<<28)>>28)==1)func_ov002_021e5974(&a,&b);
if(((u32)(p[3]<<28)>>28)==0)func_ov002_021e4368(0,y,a,y,0,y+30,b,y+30,9,0);
else func_ov002_021e4368(256-a,y,256,y,256-b,y+30,256,y+30,9,0);
y=155-(s8)p[2];func_0208718c();a=90;b=74;
if(((u32)(p[3]<<28)>>28)==1)func_ov002_021e5974(&a,&b);
if(((u32)(p[3]<<28)>>28)==0)func_ov002_021e447c(0,y,a,y,0,y+28,b,y+28,8,color,0);
else func_ov002_021e447c(256-a,y,256,y,256-b,y+28,256,y+28,8,color,1);
if(data_ov002_021f3105[((u32)(p[3]<<28)>>28)*24]){
y=119-(s8)p[2];
tiles=M2C_FIELD((func_ov002_021e4b68()?data_ov002_021f3040:data_ov002_021f303e)+((u32)(p[3]<<28)>>28)*100,u16 *,0);
if(((u32)(p[3]<<28)>>28)==0)func_ov002_021e45c0(0,y,0,tiles,data_ov002_021f3044[((u32)(p[3]<<28)>>28)*100]);
else func_ov002_021e4674(184,y,0,tiles,data_ov002_021f3044[((u32)(p[3]<<28)>>28)*100]);
}
}
}
x=(((u32)(p[3]<<28)>>28)==0?100:28);y=170-(s8)p[2];
func_02087064(3,128,16,M2C_FIELD(data_ov002_021f3018,u16 *,200),data_ov002_021f3018[202]);
x=(s16)x;func_020878c4(x,y,1,128,16,0,0,128,16);
func_02087064(3,128,16,M2C_FIELD(data_ov002_021f3018,u16 *,200),data_ov002_021f3042[((u32)(p[3]<<28)>>28)*100]);
if(width){if(((u32)(p[3]<<28)>>28)==0)func_ov002_021e482c(x,y,0,width);else func_ov002_021e48e8(x,y,0,width);}
x=((u32)(p[3]<<28)>>28)==0?221:3;y=150-(s8)p[2];width=(width+9)/10;
if(y<192){AddSprite((u16)((x)&511),(u16)((y)&255),(u16)((0x3ff&((64+(width<<4))>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((((u32)(p[3]<<28)>>28)==0?1:2)<<12)),data_027e00ac,0);
}
if(data_ov002_021f3106[((u32)(p[3]<<28)>>28)*24]){
x=(s16)(((u32)(p[3]<<28)>>28)==0?0:185);y=183-(s8)p[2];
if(y<192){
AddSprite((u16)((x)&511),(u16)((y)&255),(u16)((0x3ff&((0x108)>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((((u32)(p[3]<<28)>>28)==0?1:2)<<12)),data_027e007c,0);

AddSprite((u16)((x+32)&511),(u16)((y)&255),(u16)((0x3ff&((0x10c)>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((((u32)(p[3]<<28)>>28)==0?1:2)<<12)),data_027e007c,0);

AddSprite((u16)((x+64)&511),(u16)((y)&255),(u16)((0x3ff&((0x110)>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((((u32)(p[3]<<28)>>28)==0?1:2)<<12)),gSpriteDesc16x8,0);

}}
if(data_ov002_021f30ff[((u32)(p[3]<<28)>>28)*24]){
x=(s16)(((u32)(p[3]<<28)>>28)==0?184:44);y=164-(s8)p[2];
if(((u32)(p[3]<<28)>>28)==0 && data_ov002_021f30ff[((u32)(p[3]<<28)>>28)*24]<=2)x=(s16)(x+10);
if(GetLanguage()==2 && ((u32)(p[3]<<28)>>28)==0 && data_ov002_021f30ff[((u32)(p[3]<<28)>>28)*24]>=3)x=(s16)(x+23);
if(GetLanguage()==5 && ((u32)(p[3]<<28)>>28)==0 && data_ov002_021f30ff[((u32)(p[3]<<28)>>28)*24]<=2)x=(s16)(x-8);
if(y<192){
AddSprite((u16)((x)&511),(u16)((y)&255),(u16)((0x3ff&((0xf0+((data_ov002_021f30ff[((u32)(p[3]<<28)>>28)*24]-1)<<3))>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((((u32)(p[3]<<28)>>28)==0?1:2)<<12)),data_027e007c,0);

AddSprite((u16)((x+32)&511),(u16)((y)&255),(u16)((0x3ff&((0xf4+((data_ov002_021f30ff[((u32)(p[3]<<28)>>28)*24]-1)<<3))>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((((u32)(p[3]<<28)>>28)==0?1:2)<<12)),data_027e007c,0);

}}
x=(s16)(((u32)(p[3]<<28)>>28)==0?4:192);yy=(s16)((s8)p[2]+4);
if(yy-8 > -16){
AddSprite((u16)((x)&511),(u16)((yy)&255),(u16)((0x3ff&((0x112)>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((((u32)(p[3]<<28)>>28)==0?1:2)<<12)),data_027e007c,0);

x=(s16)(x+20);
for(i=0,xx=x;i<gPlayerSettings[((u32)(p[3]<<28)>>28)*24+17];i++,xx+=10){
AddSprite((u16)((xx)&511),(u16)((yy-8)&255),(u16)((0x3ff&((0x116)>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((((u32)(p[3]<<28)>>28)==0?1:2)<<12)),gSpriteDesc16x16,0);

}
for(xx=x+i*10;i<4;i++,xx+=10){
AddSprite((u16)((xx)&511),(u16)((yy-8)&255),(u16)((0x3ff&((0x11a)>>((u32)(**gCur3DSpriteEngine<<17)>>30))) | (u16)((((u32)(p[3]<<28)>>28)==0?1:2)<<12)),gSpriteDesc16x16,0);

}}
if(func_ov002_021e4b68() && (s8)p[4]!=-1){
if(data_ov002_021f3106[((u32)(p[3]<<28)>>28)*24]==2)x=(s16)(((u32)(p[3]<<28)>>28)==0?76:100);
else x=(s16)(((u32)(p[3]<<28)>>28)==0?52:124);
y=124-(s8)p[2];
if(p[5]){x=(s16)(x+RandomIntRange(-4,4));y=(s16)(y+RandomIntRange(-4,4));}
func_ov002_021e497c(x,y,((u32)(p[3]<<28)>>28),(s8)p[4]);
}
}

void func_ov002_021e5974(s32 *arg0, s32 *arg1) {
    s32 temp_r3;

    temp_r3 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_r3;
}

void func_ov002_021e5988(u16 *arg0, s32 arg1) {
    s32 j;
    s32 i;
    u16 a;
    u16 b;
    for (i = 0; i < arg1; i++) {
        for (j = 0; j < 16; j++) {
            a = arg0[31 - j];
            b = arg0[j];
            arg0[j] = a ^ 0x400;
            arg0[31 - j] = b ^ 0x400;
        }
        arg0 += 32;
    }
}

