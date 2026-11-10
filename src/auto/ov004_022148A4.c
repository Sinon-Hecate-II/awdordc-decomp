/* 4 functions from 0x022148A4 to 0x02215814 (ov004), found by ds-decomp. */
#include "common.h"
extern u8 data_ov004_0223c5a8[],data_ov004_0223c5f4[],data_ov004_0223c5b8[],data_ov004_0223c5d0[],data_ov004_0223c5c0[],data_ov004_0223c660[],data_ov004_0223c630[],data_ov004_0223c624[],data_ov004_0223c5e8[],data_ov004_0223c5dc[],data_ov004_0223c5c8[],data_ov004_0223c5b0[],data_ov004_0223c60c[],data_ov004_0223c600[],data_ov004_0223c66c[],data_ov004_0223c654[],data_ov004_0223c648[],data_ov004_0223c618[];extern const u16 data_ov004_02218bc4[];extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain,g3DSpriteEngineSub;
typedef struct Config149 {u16 values[6];} Config149;
void Reset3DSpriteBankState();void *func_020ab1c4(void *);void *GetLocalizedFileName(void *);
static inline u8 Visible149(void *p){return M2C_FIELD(M2C_FIELD(p,void **,100),u8 *,18)!=0;}

extern s32 data_0215d8a0;extern u32 data_0215d8a8[];
void func_020885fc(void);void *MemAlloc(s32);s32 func_020a8958(s32);u32 func_020a8a94(s32);s32 func_020a8a84(s32);s32 func_020a8aac(s32,s32);
static inline void *Entry149(void *base,s32 i){if(i<0)return 0;if(i>=64)return 0;return (u8 *)base+i*32;}
static inline void *Cell149(void *base,s32 x,s32 y){if(x<0)return 0;if(y<0)return 0;if(x>=8)return 0;if(y>=8)return 0;return Entry149(base,x+y*8);}
static inline u8 Flag149(void *p,u32 bit){return (M2C_FIELD(p,u8 *,4)&bit)?1:0;}
static inline void *Find149(void *base,s32 id){s32 i;void *p;for(i=0;i<64;i++){p=(u8 *)base+i*32;if(M2C_FIELD(p,u8 *,7)==id)return p;}return 0;}
static inline void *Selected149(void *base){s32 i;u8 *cursor=base;void *p;for(i=0;i<64;i++,cursor+=32){if(i<0)p=0;else if(i>=64)p=0;else p=cursor;if(Flag149(p,2))return p;}return 0;}


void func_ov004_022148a4(void) {
    M2C_UNK func_02003bd0();
    func_02003bd0();
    *(u16 *)0x04000060 = (*(u16 *)0x04000060 & ~0x3000) | 8;
    M2C_FIELD((void *)0x040004C8, s32 *, 0) = 0x1FF00000;
    M2C_FIELD((void *)0x040004C8, s32 *, 4) = 0x7FFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -8) = 0x7FFFFFFF;
    M2C_FIELD((void *)0x040004C8, s32 *, -4) = 0x7FFF7FFF;
    M2C_FIELD((void *)0x040004C8, s32 *, 0xB8) = 0xBFFF0000;
}

void func_ov004_02214904(void) {
    *(s32 *)0x04000540 = 1;
}

#pragma opt_strength_reduction off
void func_ov004_02214918(void *arg0){
u8 *base,*p,*q,*end,*cursor; s32 i,j,id,state,n,y,x,old;s32 saved;u32 pos;u8 selected;volatile u8 coords[4];
func_020885fc();
M2C_FIELD(arg0,u8 *,54)=0;M2C_FIELD(arg0,u16 *,68)=0;M2C_FIELD(arg0,u16 *,70)=0;M2C_FIELD(arg0,u16 *,76)=0;M2C_FIELD(arg0,u16 *,78)=0;M2C_FIELD(arg0,u16 *,72)=0;M2C_FIELD(arg0,u16 *,74)=0;M2C_FIELD(arg0,u16 *,80)=0;M2C_FIELD(arg0,u16 *,82)=0;M2C_FIELD(arg0,u8 *,57)=0;M2C_FIELD(arg0,u8 *,56)=1;M2C_FIELD(arg0,s32 *,64)=4096;
M2C_FIELD(arg0,u16 *,60)=0;M2C_FIELD(arg0,void **,92)=0;M2C_FIELD(arg0,u8 *,52)=0;
if((u32)data_0215d8a0>>24==0)M2C_FIELD(arg0,s32 *,64)=4096;
if((u32)data_0215d8a0>>24==1)M2C_FIELD(arg0,s32 *,64)=2048;
if((M2C_FIELD(&data_0215d8a0,u32 *,108)<<3)>>29)M2C_FIELD(arg0,u8 *,57)=1;
base=MemAlloc(2048);
if(base){end=base+2048;p=base;do{
M2C_FIELD(p,u8 *,4)=0;M2C_FIELD(p,u8 *,6)=0;M2C_FIELD(p,u16 *,0)=0;M2C_FIELD(p,u16 *,2)=0;M2C_FIELD(p,u8 *,7)=255;M2C_FIELD(p,u8 *,5)=255;M2C_FIELD(p,s32 *,8)=4096;M2C_FIELD(p,s32 *,12)=4096;
for(j=0;j<4;j++)M2C_FIELD(p+(u32)j*4,void **,16)=0;
p+=32;}while(p<end);
for(i=0;i<64;i++){M2C_FIELD(base+i*32,u16 *,0)=(i%8)*64+32;M2C_FIELD(base+i*32,u16 *,2)=(i/8)*38+19;}
}
M2C_FIELD(arg0,void **,92)=base;
for(i=0;i<275;i++){
state=func_020a8958(i);pos=func_020a8a94(i);coords[0]=pos;coords[1]=pos>>8;coords[2]=coords[0];coords[3]=(u8)(pos>>8);x=coords[2];y=coords[3];
if(state==0||state==2){base=M2C_FIELD(arg0,void **,92);p=Cell149(base,x,y);
M2C_FIELD(p,u8 *,6)=func_020a8a84(i);M2C_FIELD(p,u8 *,7)=i-161;id=(u8)(i-161);
state=func_020a8958(id+161);selected=Flag149(p,2);M2C_FIELD(p,u8 *,4)=0;
if(state==2)M2C_FIELD(p,u8 *,4)|=4;
if((data_0215d8a8[id]<<29)>>29)M2C_FIELD(p,u8 *,4)|=1;
if((data_0215d8a8[id]<<29)>>29==1)M2C_FIELD(p,u8 *,4)|=16;
if((data_0215d8a8[id]<<29)>>29==3)M2C_FIELD(p,u8 *,4)|=8;
if(selected)M2C_FIELD(p,u8 *,4)|=2;
M2C_FIELD(p,u8 *,5)=(data_0215d8a8[id]<<3)>>29;
}}
base=M2C_FIELD(arg0,void **,92);
for(i=0,cursor=base;i<64;i++,cursor+=32){if(i<0)p=0;else if(i>=64)p=0;else p=cursor;
for(j=0;j<4;j++){n=func_020a8aac(M2C_FIELD(p,u8 *,7)+161,j);q=0;if(n){for(id=0;id<64;id++){q=base+id*32;if(n==M2C_FIELD(q,u8 *,7)+161)break;}if(id==64)q=0;}M2C_FIELD(p+j*4,void **,16)=q;}}
base=M2C_FIELD(arg0,void **,92);p=Find149(base,(u16)M2C_FIELD(&data_0215d8a0,u32 *,4));
if(p&&p!=Selected149(base)&&Flag149(p,1)){for(i=0,cursor=base;i<64;i++,cursor+=32){if(i<0)q=0;else if(i>=64)q=0;else q=cursor;M2C_FIELD(q,u8 *,4)&=~2;}M2C_FIELD(p,u8 *,4)|=2;}
if(p){y=M2C_FIELD(p,s16 *,2);x=M2C_FIELD(p,s16 *,0);M2C_FIELD(arg0,u16 *,68)=x;M2C_FIELD(arg0,u16 *,70)=y;M2C_FIELD(arg0,u16 *,72)=x;M2C_FIELD(arg0,u16 *,74)=y;}
{volatile Config149 first=*(const Config149 *)data_ov004_02218bc4;volatile Config149 second=*(const Config149 *)(data_ov004_02218bc4+6);
func_02082c84();func_02002c64(3);GX_SetBankForBG(32);func_02002968(16);func_02002e3c(64);func_02003124(4);func_020031cc(8);func_0200323c(128);func_020032bc(256);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;func_020822b8(&second);{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|16;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|32;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|64;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|128;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|256;}Reset3DSpriteBankState();M2C_FIELD(gCur3DSpriteEngine,u16 *,68)=0;func_020994e0();gCur3DSpriteEngine=g3DSpriteEngineSub;func_020822b8(&first);{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|16;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|32;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|64;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|128;}{u16 *volatile reg=M2C_FIELD(gCur3DSpriteEngine,u16 **,0);*reg=*reg|256;}Reset3DSpriteBankState();M2C_FIELD(gCur3DSpriteEngine,u16 *,68)=0;func_020994e0();gCur3DSpriteEngine=g3DSpriteEngineMain;SetFileDirectory(data_ov004_0223c5a8);
func_02081384(data_ov004_0223c5f4,0);func_02081400(data_ov004_0223c5b8,0,512);
func_02081384(data_ov004_0223c5d0,0x28000);func_02081400(data_ov004_0223c5c0,512,32);
func_02081384(data_ov004_0223c660,0x30000);func_02081400(data_ov004_0223c630,544,32);
func_020814e4(data_ov004_0223c624);func_0208168c(GetLocalizedFileName(data_ov004_0223c5e8),0x38000);func_0208168c(GetLocalizedFileName(data_ov004_0223c5dc),0x39000);func_02081528();
func_02081400(data_ov004_0223c5c8,576,160);func_02081400(data_ov004_0223c5b0,736,32);
func_02081384(data_ov004_0223c60c,0x3a000);func_02081400(data_ov004_0223c600,768,32);
func_020814e4(data_ov004_0223c66c);func_02081590(data_ov004_0223c654,M2C_FIELD(gCur3DSpriteEngine,s32 *,24)+32);func_02081590(data_ov004_0223c648,M2C_FIELD(gCur3DSpriteEngine,s32 *,44));func_020815fc(data_ov004_0223c618,480,32);func_02081528();
n=func_01ff9c34((u8)((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<29)>>29),1);func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,s32 *,44),(u16)n,0xf001);
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=8;func_020a9a30(0,2,71,M2C_FIELD(gCur3DSpriteEngine,s32 *,48)+608);p=func_020ab1c4(arg0);func_020aab24(p,2,320,3,0);func_020ab150(p,2);M2C_FIELD(p,u16 *,60)=2048;func_02088e84(p,224,156,224,188);if(Visible149(p)){y=M2C_FIELD(p,s16 *,82);x=M2C_FIELD(p,s16 *,80);n=func_020aae10(p);j=func_020aae44(p);func_02087d84(M2C_FIELD(p,void **,100),1,x,y,(u16)n,(u16)j);}func_02088f1c(p);func_020aad18(p);p=func_020ab1c4(arg0);func_020aab24(p,6,336,3,0);func_020ab150(p,256);M2C_FIELD(p,u16 *,60)=2048;func_02088e84(p,192,156,192,188);if(Visible149(p)){y=M2C_FIELD(p,s16 *,82);x=M2C_FIELD(p,s16 *,80);n=func_020aae10(p);j=func_020aae44(p);func_02087d84(M2C_FIELD(p,void **,100),1,x,y,(u16)n,(u16)j);}func_02088f1c(p);func_020aad18(p);p=func_020ab1c4(arg0);func_020aab24(p,18,352,3,0);M2C_FIELD(p,u16 *,60)=2048;func_020ab150(p,8);func_02088e84(p,128,156,128,188);if(Visible149(p)){y=M2C_FIELD(p,s16 *,82);x=M2C_FIELD(p,s16 *,80);n=func_020aae10(p);j=func_020aae44(p);func_02087d84(M2C_FIELD(p,void **,100),1,x,y,(u16)n,(u16)j);}func_02088f1c(p);func_020aad18(p);gCur3DSpriteEngine=saved;}func_ov003_021fef58(arg0);func_0209cce4(func_ov004_022148a4,4);func_0209cce4(func_ov004_02214904,10);if(M2C_FIELD(arg0,s32 *,64)==2048||M2C_FIELD(arg0,s32 *,64)==4096){if(M2C_FIELD(arg0,s16 *,80)<96-func_0207c8ec(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,80)=96-func_0207c8ec(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096);if(M2C_FIELD(arg0,s16 *,82)<57-func_0207c8ec(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,82)=57-func_0207c8ec(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096);if(M2C_FIELD(arg0,s16 *,80)>160-func_0207c8ec(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,80)=160-func_0207c8ec(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096);if(M2C_FIELD(arg0,s16 *,82)>95-func_0207c8ec(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,82)=95-func_0207c8ec(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096);}if(M2C_FIELD(arg0,s32 *,64)==2048||M2C_FIELD(arg0,s32 *,64)==4096){if(M2C_FIELD(arg0,s16 *,68)<0)M2C_FIELD(arg0,s16 *,68)=0;if(M2C_FIELD(arg0,s16 *,68)>512)M2C_FIELD(arg0,s16 *,68)=512;if(M2C_FIELD(arg0,s16 *,70)<0)M2C_FIELD(arg0,s16 *,70)=0;if(M2C_FIELD(arg0,s16 *,70)>304)M2C_FIELD(arg0,s16 *,70)=304;if(M2C_FIELD(arg0,s16 *,80)<256-func_0207c8ec(M2C_FIELD(arg0,s32 *,64)*512,4096))M2C_FIELD(arg0,s16 *,80)=256-func_0207c8ec(M2C_FIELD(arg0,s32 *,64)*512,4096);if(M2C_FIELD(arg0,s16 *,82)<192-func_0207c8ec(M2C_FIELD(arg0,s32 *,64)*344,4096))M2C_FIELD(arg0,s16 *,82)=192-func_0207c8ec(M2C_FIELD(arg0,s32 *,64)*344,4096);if(M2C_FIELD(arg0,s16 *,80)>0)M2C_FIELD(arg0,s16 *,80)=0;if(M2C_FIELD(arg0,s16 *,82)>0)M2C_FIELD(arg0,s16 *,82)=0;}
p=Selected149(M2C_FIELD(arg0,void **,92));if(p){func_020ceb48();func_020cf278(M2C_FIELD(p,u8 *,7)+161);func_020cf0a8(M2C_FIELD(p,u8 *,7)+161);func_ov003_021ff36c();}
M2C_FIELD(arg0,s16 *,76)=0;M2C_FIELD(arg0,s16 *,78)=0;n=0;state=0x10019;for(i=0;i<26;i++){if((data_0215d8a8[i]<<29)>>29>=3)n=i+1;}
if(n>=10)state=0x1001a;if(n>=16)state=0x1001b;if(n>=21)state=0x1001c;func_0208f780(state);}
#pragma opt_strength_reduction reset
void func_ov004_02215754(void *a){extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain,data_0215d8a0;void func_ov004_022148a4(void);void func_ov004_02214904(void);s32 old=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;Reset3DSpriteBankState(a);gCur3DSpriteEngine=old;func_ov003_021ff3ac();func_020ab200();func_0209cd00(func_ov004_022148a4);func_0209cd00(func_ov004_02214904);func_0209e9f4();func_0209bf7c();func_0208f890();func_0209c868();if(M2C_FIELD(a,s32*,0x40)==0x1000)data_0215d8a0 &=0xffffff;if(M2C_FIELD(a,s32*,0x40)==0x800)data_0215d8a0=(data_0215d8a0&0xffffff)|0x1000000;if(M2C_FIELD(a,s32*,0x5c))MemFree(M2C_FIELD(a,s32*,0x5c));M2C_FIELD(a,s32*,0x5c)=0;func_02088624();}

