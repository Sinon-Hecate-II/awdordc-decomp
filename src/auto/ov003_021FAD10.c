/* 2 functions from 0x021FAD10 to 0x021FBCF8 (ov003), found by ds-decomp. */
#include "common.h"

typedef struct { u8 low : 4; u8 high : 4; } Ov003DrawNibble;
typedef struct { u8 low : 3; u8 high : 5; } Ov003DrawBits3;
typedef struct { u16 low : 13; u16 mode : 2; u16 high : 1; } Ov003DrawDisplay;
typedef struct { u32 low : 18; u32 frame : 8; u32 high : 6; } Ov003DrawFrame;

static inline u16 Ov003DrawItem(void *object, s32 index) {
    u8 page = (u8)M2C_FIELD(M2C_FIELD(object, void **, 0x5c), s32 *, 4);
    return M2C_FIELD((u8*)M2C_FIELD(object, void **, 0x44) + (page << 9) + index * 2, u16 *, 0x2e);
}

extern void **gCur3DSpriteEngine;
extern u16 data_ov003_0220feac[];
s32 GetSpriteAnimValue(void *);
s32 Modulo(s32,s32);
s32 func_0207c8ec(s32,s32);
void func_01ff9ce8(s32);
s32 func_ov003_021f3f5c(s16,s16,s32,s32,s32,s32,s32,s32);
void func_020809c0(void *,s32,s32);
u8 func_ov003_021f269c(void *,void *,u16);
void func_ov003_021fac2c(u16,u16,s16,s16,s32);
s32 func_ov003_021f3f0c(s16,s32,s32);
void func_020a92bc(void *,s16);
void func_020a94fc(void *);
s32 func_ov003_02200a18(u8,u16);
void AddSprite(u16,u8,u16,void *,s32);
s32 func_ov003_021f2654(void);
s32 func_020c7f30(u16);
s32 func_020c7eb8(u16);
s32 func_020c7ef4(u16);
s32 func_02086960(u16);
void *func_020cfbdc(u16);
void func_0209b32c(s16,s16,s32,void *,s32,u8,u16);
extern u8 gSpriteDesc16x16[];
s32 func_020abb24(void *);
void func_0208e0b8(s16,s16,s16,u16,s32);
s16 func_ov003_021f2780(void *,void *);
void func_02088e84(void *,s16,s16,s16,s16);
s32 func_020aae10(void *);
s32 func_020aae44(void *);
void func_02087d84(void *,s32,s16,s16,u16,u16);
void func_ov003_021fad10(void *arg0,s32 arg1,s32 arg2) {
 s32 x,y,i,end,n,px,py,tx,ty,j; u16 item,neg; u8 idx,mode,shade; void *p;
 p=M2C_FIELD(arg0,void **,0x4c);
 x=arg1+M2C_FIELD(p,s16 *,0x28);
 y=arg2+GetSpriteAnimValue((u8*)p+0x30);
 M2C_FIELD(gCur3DSpriteEngine[0],u16 *,0x3e)=-arg1;
 neg=-y;
 M2C_FIELD(gCur3DSpriteEngine[0],u16 *,0x46)=neg;
 M2C_FIELD(gCur3DSpriteEngine[0],u16 *,0x38)=-(arg1+40);
 M2C_FIELD(gCur3DSpriteEngine[0],u16 *,0x40)=neg;
 func_01ff9ce8(3);
 p=M2C_FIELD(arg0,void **,0x4c);
 i=(s16)M2C_FIELD(p,s32 *,0x1c);
 n=(u8)M2C_FIELD(p,s16 *,8);
 end=(s16)(M2C_FIELD(p,s32 *,0x18)+(s16)(M2C_FIELD(p,s16 *,6)*M2C_FIELD(p,s16 *,8))+n*2);
 if(i<0)i=0;
 for(;i<=end;i++){
 p=M2C_FIELD(arg0,void **,0x44);
 item=Ov003DrawItem(arg0,i);
 px=x+Modulo(i,n)*120;
 py=y+func_0207c8ec(i,n)*16;
 tx=Modulo(i,n)*15;
 ty=Modulo(func_0207c8ec(i,n)*2,32);
 if(!func_ov003_021f3f5c((s16)px,(s16)py,240,16,6,40,240,112)){
 idx=(u8)i;
 if((u8)!(M2C_FIELD((u8*)M2C_FIELD(arg0,void **,0x44)+(idx>>3),u8 *,0x186c)&(1<<(idx&7)))==0){
 func_020809c0((u8*)gCur3DSpriteEngine[8]+tx*2+ty*64,9,2);
 M2C_FIELD((u8*)M2C_FIELD(arg0,void **,0x44)+(idx>>3),u8 *,0x186c)&=~(1<<(idx&7));
 }
 continue;
 }
 if(Modulo(i,M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s16 *,8))==0){
 for(j=0;j<64;j++){
 M2C_FIELD((u8*)gCur3DSpriteEngine[11]+(tx+ty*32)*2+j*2,u16 *,0)=(data_ov003_0220feac[j]&0x3ff)|0x9000;
 if(i==M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s32 *,0x18)&&j<32)
 M2C_FIELD((u8*)gCur3DSpriteEngine[11]+(tx+(ty+2)*32)*2+j*2,u16 *,0)=(data_ov003_0220feac[j]&0x3ff)|0x9000;
 }}
 mode=M2C_FIELD(arg0,Ov003DrawNibble *,0x3b).low;
 if((u8)(mode==4)){
 p=M2C_FIELD(arg0,void **,0x44);
 if((u8)(func_ov003_021f269c((u8*)p+4,(u8*)p+8,item)!=255))
 func_ov003_021fac2c((u16)i,item,(s16)tx,(s16)ty,4);
 else {p=M2C_FIELD(arg0,void **,0x44);
 if((u8)(func_ov003_021f269c((u8*)p+4,(u8*)p+18,item)!=255))
 func_ov003_021fac2c((u16)i,item,(s16)tx,(s16)ty,8);}
 }
 if(!func_ov003_021f3f0c((s16)py,24,152)||i>M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s32 *,0x18))continue;
 func_020a92bc(M2C_FIELD(arg0,void **,0x50),(s16)(i+1));
 p=M2C_FIELD(arg0,void **,0x50);
 M2C_FIELD(p,u8 *,0x28)=(M2C_FIELD(p,u8 *,0x28)&~0xe0)|0x20;
 p=M2C_FIELD(arg0,void **,0x50);
 M2C_FIELD(p,s16 *,6)=px+34;M2C_FIELD(p,s16 *,8)=py+5;
 M2C_FIELD(M2C_FIELD(arg0,void **,0x50),s16 *,0x12)=1024;
 M2C_FIELD(M2C_FIELD(arg0,void **,0x50),u8 *,0x21)=8;
 func_020a94fc(M2C_FIELD(arg0,void **,0x50));
 p=(u8*)M2C_FIELD(arg0,void **,0x44)+((u8)M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),s32 *,4)<<9);
 {u16 tile=(u16)(func_ov003_02200a18(M2C_FIELD(p,u8 *,0x22c),Ov003DrawItem(arg0,i))*4+0x418);
 AddSprite((u16)((px+3)&0x1ff),(u8)(py-2),(u16)(((tile>>M2C_FIELD(gCur3DSpriteEngine[0],Ov003DrawDisplay *,0).mode)&0x3ff)|0x8800),gSpriteDesc16x16,17);}
 idx=(u8)i;
 if((u8)!(M2C_FIELD((u8*)M2C_FIELD(arg0,void **,0x44)+(idx>>3),u8 *,0x186c)&(1<<(idx&7)))){
 func_020809c0((u8*)gCur3DSpriteEngine[8]+tx*2+ty*64,9,2);
 if(func_ov003_021f2654())shade=0;
 else {
 mode=M2C_FIELD(arg0,Ov003DrawNibble *,0x3b).low;
 if((u8)(mode==6))shade=(u8)(func_020c7f30(item)?0:3);
 else if((u8)(mode==4)||(u8)(mode==8)||(u8)(mode==7)){
 p=M2C_FIELD(arg0,void **,0x44);shade=0;
 if(!(u8)(func_ov003_021f269c((u8*)p+4,(u8*)p+18,item)!=255))
 shade=(u8)(((s32)item>=225&&(s32)item<0x1a9&&!func_020c7eb8(item))?3:0);
 } else if((u8)(mode==2))shade=(u8)(func_020c7ef4(item)?0:3);
 else shade=(u8)(func_02086960(item)?0:3);
 }
 {u8 a=(u8)Modulo(i,20);void *b=func_020cfbdc(item);
 func_0209b32c((s16)tx,(s16)ty,0,b,0xa000,shade,(u16)(a*16+1));}
 p=(u8*)M2C_FIELD(arg0,void **,0x44)+(idx>>3);
 M2C_FIELD(p,u8 *,0x186c)=(M2C_FIELD(p,u8 *,0x186c)&~(1<<(idx&7)))|(1<<(idx&7));
 }
 }
 M2C_FIELD((void*)gCur3DSpriteEngine,u8 *,0x46)|=1;
 M2C_FIELD((void*)gCur3DSpriteEngine,u8 *,0x46)|=8;

 p=M2C_FIELD(arg0,void **,0x4c);
 {s32 a=M2C_FIELD(p,s16 *,0x28)+GetSpriteAnimValue((u8*)p+0x42);
 s32 b=func_020abb24(M2C_FIELD(arg0,void **,0x4c));
 void *q=M2C_FIELD(M2C_FIELD(arg0,void **,0x6c),void **,0);
 M2C_FIELD(q,s16 *,0x34)=arg1+(s16)(a+2);
 M2C_FIELD(q,s16 *,0x36)=arg2+(s16)(b+2);
 M2C_FIELD(q,u32 *,0x40)=((M2C_FIELD(q,u32 *,0x40)&~0x1ff)|0x6e)&0xfffc01ff|0x1a00;}
 p=M2C_FIELD(arg0,void **,0x4c);
 if(M2C_FIELD(p,s32 *,0x18)>=(s16)(M2C_FIELD(p,s16 *,6)*M2C_FIELD(p,s16 *,8))){
 s16 a=(s16)func_0207c8ec((s16)M2C_FIELD(p,s32 *,0x18),M2C_FIELD(p,s16 *,8));
 s16 h=(s16)func_0207c8ec(M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s16 *,6)*113,a+1);
 s16 total,pos,off;
 p=M2C_FIELD(arg0,void **,0x4c);
 total=(s16)(M2C_FIELD(p,u8 *,10)*M2C_FIELD(p,s16 *,6));
 pos=(s16)(M2C_FIELD(p,u8 *,10)*func_0207c8ec((s16)M2C_FIELD(p,s32 *,0x18),M2C_FIELD(p,s16 *,8)));
 off=(s16)func_0207c8ec((113-h)*-GetSpriteAnimValue((u8*)M2C_FIELD(arg0,void **,0x4c)+0x30),pos-total+16);
 if(h>113)h=113;else if(h<1)h=1;
 func_0208e0b8((s16)(arg1+242),(s16)(arg2+1+off),h,(u16)(((0x47c>>M2C_FIELD(gCur3DSpriteEngine[0],Ov003DrawDisplay *,0).mode)&0x3ff)|0xa000),17);
 }
 mode=M2C_FIELD(arg0,Ov003DrawNibble *,0x3b).low;
 if((u8)(mode==0)||(u8)(mode==2)||(u8)(mode==3)||(u8)(mode==6)||(u8)(mode==7)||(u8)(mode==8)){
 func_020a92bc(M2C_FIELD(arg0,void **,0x50),(s16)(M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s32 *,0x18)+1));
 p=M2C_FIELD(arg0,void **,0x50);M2C_FIELD(p,u8 *,0x28)&=~0xe0;
 p=M2C_FIELD(arg0,void **,0x50);M2C_FIELD(p,s16 *,6)=arg1+241;M2C_FIELD(p,s16 *,8)=arg2-12;
 M2C_FIELD(M2C_FIELD(arg0,void **,0x50),s16 *,0x12)=1024;M2C_FIELD(M2C_FIELD(arg0,void **,0x50),u8 *,0x21)=8;
 func_020a94fc(M2C_FIELD(arg0,void **,0x50));
 func_020a92bc(M2C_FIELD(arg0,void **,0x50),(s16)((s16)M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s32 *,0x14)+1));
 p=M2C_FIELD(arg0,void **,0x50);M2C_FIELD(p,u8 *,0x28)&=~0xe0;
 p=M2C_FIELD(arg0,void **,0x50);M2C_FIELD(p,s16 *,6)=arg1+217;M2C_FIELD(p,s16 *,8)=arg2-12;
 M2C_FIELD(M2C_FIELD(arg0,void **,0x50),s16 *,0x12)=1024;M2C_FIELD(M2C_FIELD(arg0,void **,0x50),u8 *,0x21)=8;
 func_020a94fc(M2C_FIELD(arg0,void **,0x50));
 }else if((u8)(mode==4)){
 u8 a; s16 x0=(s16)(arg1+17),x1=(s16)(arg1+33),x2=(s16)(arg1+217),x3=(s16)(arg1+233),yy=(s16)(arg2-12);
 for(a=0;a<4;a++){
 s16 xx,num;u8 color=8;
 switch(a){
 case 0:xx=x0;p=M2C_FIELD(arg0,void **,0x44);num=func_ov003_021f2780((u8*)p+4,(u8*)p+8);if((u8)((M2C_FIELD(arg0,Ov003DrawBits3 *,0x3e).low)==1))color=9;break;
 case 1:xx=x1;num=5;if((u8)((M2C_FIELD(arg0,Ov003DrawBits3 *,0x3e).low)==1))color=9;break;
 case 2:xx=x2;p=M2C_FIELD(arg0,void **,0x44);num=func_ov003_021f2780((u8*)p+4,(u8*)p+18);if(!(u8)((M2C_FIELD(arg0,Ov003DrawBits3 *,0x3e).low)==1))color=9;break;
 case 3:xx=x3;num=5;if(!(u8)((M2C_FIELD(arg0,Ov003DrawBits3 *,0x3e).low)==1))color=9;break;
 }
 func_020a92bc(M2C_FIELD(arg0,void **,0x50),num);
 p=M2C_FIELD(arg0,void **,0x50);M2C_FIELD(p,u8 *,0x28)&=~0xe0;
 p=M2C_FIELD(arg0,void **,0x50);M2C_FIELD(p,s16 *,6)=xx;M2C_FIELD(p,s16 *,8)=yy;
 M2C_FIELD(M2C_FIELD(arg0,void **,0x50),s16 *,0x12)=1024;M2C_FIELD(M2C_FIELD(arg0,void **,0x50),u8 *,0x21)=color;
 func_020a94fc(M2C_FIELD(arg0,void **,0x50));
 }}
{s16 xx=(s16)(arg1+90),yy=(s16)(arg2+116);void *q=M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,24);
func_02088e84(q,xx,yy,xx,yy);
if((u8)(M2C_FIELD(M2C_FIELD(q,void **,0x64),u8 *,0x12)!=0)){s16 a=M2C_FIELD(q,s16 *,0x52),b=M2C_FIELD(q,s16 *,0x50);s32 c=func_020aae10(q);u16 d=(u16)func_020aae44(q);func_02087d84(M2C_FIELD(q,void **,0x64),1,b,a,(u16)c,d);}M2C_FIELD(q,s16 *,0x34)=xx;M2C_FIELD(q,s16 *,0x36)=yy;if((u8)(M2C_FIELD(M2C_FIELD(q,void **,0x64),u8 *,0x12)!=0)){s16 a=M2C_FIELD(q,s16 *,0x52),b=M2C_FIELD(q,s16 *,0x50);s32 c=func_020aae10(q);u16 d=(u16)func_020aae44(q);func_02087d84(M2C_FIELD(q,void **,0x64),1,b,a,(u16)c,d);}}{s16 xx=(s16)(arg1+122),yy=(s16)(arg2+116);void *q=M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,28);
func_02088e84(q,xx,yy,xx,yy);
if((u8)(M2C_FIELD(M2C_FIELD(q,void **,0x64),u8 *,0x12)!=0)){s16 a=M2C_FIELD(q,s16 *,0x52),b=M2C_FIELD(q,s16 *,0x50);s32 c=func_020aae10(q);u16 d=(u16)func_020aae44(q);func_02087d84(M2C_FIELD(q,void **,0x64),1,b,a,(u16)c,d);}M2C_FIELD(q,s16 *,0x34)=xx;M2C_FIELD(q,s16 *,0x36)=yy;if((u8)(M2C_FIELD(M2C_FIELD(q,void **,0x64),u8 *,0x12)!=0)){s16 a=M2C_FIELD(q,s16 *,0x52),b=M2C_FIELD(q,s16 *,0x50);s32 c=func_020aae10(q);u16 d=(u16)func_020aae44(q);func_02087d84(M2C_FIELD(q,void **,0x64),1,b,a,(u16)c,d);}}
 p=M2C_FIELD(arg0,void **,0x4c);
 {s16 a=M2C_FIELD(p,s16 *,0x2a);
 if(!(u8)(a>GetSpriteAnimValue((u8*)p+0x30))){
 u8 ok=0;p=M2C_FIELD(arg0,void **,0x4c);
 if((s16)func_0207c8ec(M2C_FIELD(p,s16 *,0xc),M2C_FIELD(p,s16 *,8))>0&&M2C_FIELD(p,s16 *,6)<=(s16)func_0207c8ec((s16)M2C_FIELD(p,s32 *,0x18),M2C_FIELD(p,s16 *,8)))ok=1;
 p=M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,0x18);
 if(ok){u32 a=M2C_FIELD(p,u8 *,0x59)&15;if(!(u8)(a+2!=(u16)((M2C_FIELD(p,u32 *,0x40)>>18)&255))){M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u8)(u16)a<<18);M2C_FIELD(p,u8 *,0x5a)=0;}}
 else{M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u8)(u16)((M2C_FIELD(p,u8 *,0x59)&15)+2)<<18);M2C_FIELD(p,u8 *,0x5a)=0;}
 }}
 p=M2C_FIELD(arg0,void **,0x4c);
 {s16 a=M2C_FIELD(p,s16 *,0x2a);
 if((u8)(a<GetSpriteAnimValue((u8*)p+0x30)))return;
 p=M2C_FIELD(arg0,void **,0x4c);
 {s16 rows=M2C_FIELD(p,s16 *,6);s16 a=(s16)func_0207c8ec(M2C_FIELD(p,s16 *,0xc),M2C_FIELD(p,s16 *,8));
 s16 b=(s16)func_0207c8ec((s16)M2C_FIELD(p,s32 *,0x18),M2C_FIELD(p,s16 *,8));
 p=M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,0x1c);
 if((u8)(rows+a<b+1)){u32 a=M2C_FIELD(p,u8 *,0x59)&15;if((u8)(a+2!=(u16)((M2C_FIELD(p,u32 *,0x40)>>18)&255)))return;M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u8)(u16)a<<18);M2C_FIELD(p,u8 *,0x5a)=0;}
 else{M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u8)(u16)((M2C_FIELD(p,u8 *,0x59)&15)+2)<<18);M2C_FIELD(p,u8 *,0x5a)=0;}
 }}
}

u16 func_ov003_021fbcd8(void *arg0, s32 arg1) {
    s32 func_ov003_02200bd0(u8);
    return (u16) (func_ov003_02200bd0(M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x44) + (arg1 << 9)), u8 *, 0x22C)) * 0x10);
}
