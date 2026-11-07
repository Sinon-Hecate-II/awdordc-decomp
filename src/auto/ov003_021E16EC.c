/* 2 functions from 0x021E16EC to 0x021E2628 (ov003), found by ds-decomp. */
#include "common.h"
extern u16 data_ov003_0220f34a,data_ov003_0220f346,data_ov003_0220f342,data_ov003_0220f344,data_ov003_0220f340,data_ov003_0220f348;
void func_ov003_021f1b38(s32,void*);void func_ov003_021f1b7c(s32,void*);void func_ov003_021f2860(void*);
u32 func_ov003_021f2574(void);u32 func_ov003_021f2560(void);
void *func_020c7e58(u16);void func_02007ef4(void*,void*,s32);
void func_ov003_021f14a0(void);void func_01ff9b38(void);
void *func_020ab1c4(void*);void func_020aab24(void*,s32,s32,s32,s32);
void func_02088e84(void*,s32,s32,s32,s32);void func_02088da8(void*);
s32 func_020aae10(void*);s32 func_020aae44(void*);void func_02087d84(void*,s32,s16,s16,u16,u16);
void *func_0208bc24(void*);s32 func_0207c8ec(s32,s32);s32 func_0207c928(s32,s32);
void func_ov003_021e1530(void*,u8);void *func_020896f0(void*);void func_020893f4(void*,s32,s32);void func_02089438(void*);
static inline void RefreshSprite(void *sprite) {
u8 active=M2C_FIELD(M2C_FIELD(sprite,void**,0x64),u8*,0x12)!=0;
if(active){s16 y=M2C_FIELD(sprite,s16*,0x52),x=M2C_FIELD(sprite,s16*,0x50);s32 w=func_020aae10(sprite),h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void**,0x64),1,x,y,(u16)w,(u16)h);}
}
static inline u8 CountEntries(void *object) {
u8 n=0;u8 i=0;for(;i<5;i++)if(M2C_FIELD(M2C_FIELD(object,u8**,0x6c)+i*0x6f8,u8*,0x27))n++;return n;
}
static inline u32 VisibleEntries(void *object) { u32 n=func_ov003_021f2574();u8 m=CountEntries(object);return n<m?n:m; }
static inline void ResetAnim(void *anim) {M2C_FIELD(anim,u16*,0xe)=0;M2C_FIELD(anim,u16*,0x10)=0;M2C_FIELD(anim,u16*,0xc)=12;M2C_FIELD(anim,u16*,2)=M2C_FIELD(anim,u16*,4);}


extern void **gCur3DSpriteEngine,**data_027e00c4,**data_027e00c8;
extern u8 data_ov003_0220f500[],data_ov003_0220f508[],data_ov003_0220f518[],data_ov003_0220f530[],data_ov003_0220f544[],data_ov003_0220f560[],data_ov003_0220f574[],data_ov003_0220f584[],data_ov003_0220f59c[],data_ov003_0220f5a4[],data_ov003_0220f5b4[],data_ov003_0220f5cc[],data_ov003_0220f5e0[],data_ov003_0220f5f4[];
void func_ov003_021e3714(void*);void func_0208b758(void*,s32);void func_0200bc5c(void*);void func_01ff9ce8(s32);
void *func_020e3218(void*);void func_02080cfc(void*,void*);void func_0208116c(void*,s32,s32);void func_020808dc(void*,s32,s32,s32);
void func_020a9a30(s32,s32,s32,void*);void func_02091d4c(s32);void func_02091d6c(s32,s32);
void *func_02080e30(void*,s32);void func_0207c780(void*,void*);void func_020e35cc(void*);
void func_020c1230(void*,void*,s32,s32);void *func_020ae22c(s32);void func_0208ca2c(s32,s32,void*,s32);
u8 func_ov003_02200b5c(u8);void *func_ov000_0216cdcc(u8);void *func_ov000_0216cdec(s32,s32);void func_01ff9e44(void*,s32,s32);void func_020ae528(void*);
static inline u8 *MenuButton(void *menu,s32 index) {return M2C_FIELD(menu+index*4,u8**,12);}
static inline void SetupLayer(void *engine,s32 layer,s32 bank,s32 slot,s32 field,s32 offset){
u8 *base=M2C_FIELD(engine,u8**,field);func_020a9a30(layer,bank,slot,base+offset);
}
typedef struct {u32 width:9,height:9,tile:8,high:6;} SpriteGeometry;
typedef struct {u8 low:2;u8 mode:2;u8 high:4;} MenuModeBits;

#pragma opt_common_subs off
void func_ov003_021e16ec(void *a) {
u8 *p=a,*q,*sprite,*menu;
u8 i;u32 n;void **saved;void *data;
s32 cw,ch;
s16 x,y;s32 w,h;u16 left,right,up,down;
func_ov003_021f1b38(0,&data_ov003_0220f34a);func_ov003_021f1b38(1,&data_ov003_0220f346);func_ov003_021f1b38(3,&data_ov003_0220f342);
func_ov003_021f1b7c(0,&data_ov003_0220f344);func_ov003_021f1b7c(1,&data_ov003_0220f340);func_ov003_021f1b7c(3,&data_ov003_0220f348);
func_ov003_021f2860(M2C_FIELD(p,u8**,0x5c)+4);
for(i=0;i<VisibleEntries(p);i++)func_02007ef4(M2C_FIELD(p,u8**,0x6c)+i*0x6f8,func_020c7e58((u16)(i+50)),84);
func_ov003_021f14a0();func_01ff9b38();
q=M2C_FIELD(p,u8**,0x44);
M2C_FIELD(q,void**,0)=func_020ab1c4(p);func_020aab24(M2C_FIELD(q,void**,0),32,320,3,0);
sprite=M2C_FIELD(q,u8**,0);func_02088e84(sprite,112,164,112,192);{u8 active=M2C_FIELD(M2C_FIELD(sprite,void**,0x64),u8*,0x12)!=0;if(active){s16 sy=M2C_FIELD(sprite,s16*,0x52);s16 sx=M2C_FIELD(sprite,s16*,0x50);s32 sw=func_020aae10(sprite);s32 sh=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void**,0x64),1,sx,sy,(u16)sw,(u16)sh);}}func_02088da8(M2C_FIELD(q,void**,0));
M2C_FIELD(q,void**,4)=func_020ab1c4(p);func_020aab24(M2C_FIELD(q,void**,4),2,332,3,0);
sprite=M2C_FIELD(q,u8**,4);func_02088e84(sprite,224,160,224,192);{u8 active=M2C_FIELD(M2C_FIELD(sprite,void**,0x64),u8*,0x12)!=0;if(active){s16 sy=M2C_FIELD(sprite,s16*,0x52);s16 sx=M2C_FIELD(sprite,s16*,0x50);s32 sw=func_020aae10(sprite);s32 sh=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void**,0x64),1,sx,sy,(u16)sw,(u16)sh);}}func_02088da8(M2C_FIELD(q,void**,4));
M2C_FIELD(p,void**,0x58)=func_0208bc24(p);M2C_FIELD(M2C_FIELD(p,void**,0x58),u16*,0x3e)=876;
sprite=M2C_FIELD(p,u8**,0x58);M2C_FIELD(sprite,u32*,0x40)=(M2C_FIELD(sprite,u32*,0x40)&~0x3fc0000)|0x300000;
ResetAnim(M2C_FIELD(p,void**,0x3c));ResetAnim(M2C_FIELD(p,void**,0x40));
n=VisibleEntries(p);menu=M2C_FIELD(p,u8**,0x48);menu[11]=n;n=func_ov003_021f2560();
if(menu[11])menu[6]=5;else if(n)menu[6]=0;
for(i=0;i<11;i++){
if(i<10){x=(s16)((func_0207c8ec(i,5)<<7)+6);y=(s16)((func_0207c928(i,5)<<4)+40);w=116;h=16;}
else if(i==10){x=110;y=162;w=36;h=28;}
switch(i){
case 0:case 1:case 2:case 3:case 4:
if((u8)i>=n)continue;
left=(u16)(i-1);right=(u16)(i+1);down=up=(u16)(i+5);
if((u8)i==0)left=10;if((u8)i==n-1)right=10;
if(!menu[11])down=up=i;else if((u8)i>=menu[11])down=up=(u16)(menu[11]+4);break;
case 5:case 6:case 7:case 8:case 9:
if((u8)(i-5)>=menu[11])continue;
down=up=(u16)(i-5);left=(u16)(i-1);right=(u16)(i+1);
if((u8)(i-5)==0)left=10;if((u8)(i-5)==menu[11]-1)right=10;
if(!n)down=up=i;else if((u8)(i-5)>=n)down=up=(u16)(n-1);break;
case 10:down=up=10;if(n){left=(u16)(n-1);right=0;}else if(!menu[11]){left=right=10;}else{left=(u16)(menu[11]+4);right=5;}break;
}
M2C_FIELD(menu+i*4,void**,12)=func_020ab1c4(p);sprite=M2C_FIELD(menu+i*4,u8**,12);M2C_FIELD(sprite,u16*,0x2e)=i;
func_020aab24(sprite,71,0,0,0);sprite=M2C_FIELD(menu+i*4,u8**,12);func_02088e84(sprite,x,y,x,y);{u8 active=M2C_FIELD(M2C_FIELD(sprite,void**,0x64),u8*,0x12)!=0;if(active){s16 sy=M2C_FIELD(sprite,s16*,0x52);s16 sx=M2C_FIELD(sprite,s16*,0x50);s32 sw=func_020aae10(sprite);s32 sh=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void**,0x64),1,sx,sy,(u16)sw,(u16)sh);}}
M2C_FIELD(sprite,s16*,0x34)=x;M2C_FIELD(sprite,s16*,0x36)=y;{u8 active=M2C_FIELD(M2C_FIELD(sprite,void**,0x64),u8*,0x12)!=0;if(active){s16 sy=M2C_FIELD(sprite,s16*,0x52);s16 sx=M2C_FIELD(sprite,s16*,0x50);s32 sw=func_020aae10(sprite);s32 sh=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void**,0x64),1,sx,sy,(u16)sw,(u16)sh);}}
M2C_FIELD(sprite,u32*,0x40)=(M2C_FIELD(sprite,u32*,0x40)&~511)|(w&511);
M2C_FIELD(sprite,u32*,0x40)=(M2C_FIELD(sprite,u32*,0x40)&0xfffc01ff)|((u32)(h<<23)>>14);{u8 active=M2C_FIELD(M2C_FIELD(sprite,void**,0x64),u8*,0x12)!=0;if(active){s16 sy=M2C_FIELD(sprite,s16*,0x52);s16 sx=M2C_FIELD(sprite,s16*,0x50);s32 sw=func_020aae10(sprite);s32 sh=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void**,0x64),1,sx,sy,(u16)sw,(u16)sh);}}
sprite=M2C_FIELD(menu+i*4,u8**,12);M2C_FIELD(sprite,u16*,0x68)=left;M2C_FIELD(sprite,u16*,0x6a)=right;M2C_FIELD(sprite,u16*,0x6c)=up;M2C_FIELD(sprite,u16*,0x6e)=down;
}
func_ov003_021e1530(menu,10);
M2C_FIELD(p,void**,0x4c)=func_020896f0(p);func_020893f4(M2C_FIELD(p,void**,0x4c),0x4f00,1);sprite=M2C_FIELD(p,u8**,0x4c);
M2C_FIELD(sprite,u16*,0x34)=112;M2C_FIELD(sprite,u16*,0x36)=164;M2C_FIELD(sprite,u32*,0x40)=((M2C_FIELD(sprite,u32*,0x40)&~511)|58)&0xfffc01ff|0x7400;
func_02089438(M2C_FIELD(p,void**,0x4c));M2C_FIELD(M2C_FIELD(p,void**,0x4c),u8*,0x58)=1;func_02088da8(M2C_FIELD(p,void**,0x4c));
func_ov003_021e3714(p);
sprite=M2C_FIELD(M2C_FIELD(p,u8**,0x48),u8**,0x38);ch=func_020aae44(sprite)-4;cw=func_020aae10(sprite)-4;
q=M2C_FIELD(p,u8**,0x4c);M2C_FIELD(q,s16*,0x34)=M2C_FIELD(sprite,s16*,0x34)+2;M2C_FIELD(q,s16*,0x36)=M2C_FIELD(sprite,s16*,0x36)+2;
M2C_FIELD(q,u32*,0x40)=((M2C_FIELD(q,u32*,0x40)&~511)|(cw&511))&0xfffc01ff|((u32)(ch<<23)>>14);func_02089438(M2C_FIELD(p,void**,0x4c));
switch((u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(p,u8**,0x48),u8**,0x38),u16*,0x2e)){
case 0:case 1:case 2:case 3:case 4:func_0208b758(M2C_FIELD(p,void**,0x58),0x47000019);break;
case 5:case 6:case 7:case 8:case 9:func_0208b758(M2C_FIELD(p,void**,0x58),0x4700001a);break;
case 10:func_0208b758(M2C_FIELD(p,void**,0x58),0x4700001b);break;
}
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
func_0200bc5c(data_ov003_0220f500);func_01ff9ce8(1);
data=func_020e3218(data_ov003_0220f508);func_02080cfc(data,M2C_FIELD(gCur3DSpriteEngine,void**,0x10));
data=func_020e3218(data_ov003_0220f518);func_02080cfc(data,M2C_FIELD(gCur3DSpriteEngine,void**,0x24));
func_0208116c(data_ov003_0220f530,160,32);
func_020808dc(M2C_FIELD(gCur3DSpriteEngine,void**,0x24),32,32,5);M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
func_01ff9ce8(3);func_020a9a30(3,0,0,M2C_FIELD(gCur3DSpriteEngine,void**,0x18));
func_02080cfc(data_ov003_0220f544,M2C_FIELD(gCur3DSpriteEngine,void**,0x2c));
func_020a9a30(3,2,0,M2C_FIELD(gCur3DSpriteEngine,u8**,0x30)+192);
func_020808dc(M2C_FIELD(gCur3DSpriteEngine,void**,0x2c),32,32,6);M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=8;
func_01ff9ce8(0);func_02091d4c(7);func_02091d6c(8,0);M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=1;
data=func_02080e30(func_020e3218(data_ov003_0220f560),1);
func_0207c780(data,M2C_FIELD(gCur3DSpriteEngine,u8**,0x1c)+0x2b80);
func_0207c780((u8*)data+0xb3c,M2C_FIELD(gCur3DSpriteEngine,u8**,0x1c)+0x5500);
func_0207c780((u8*)data+0xbcc,M2C_FIELD(gCur3DSpriteEngine,u8**,0x1c)+0x5900);func_020e35cc(data);
func_0208116c(data_ov003_0220f574,0x2c0,64);func_0208116c(data_ov003_0220f584,0x340,32);
func_020a9a30(1,0,0,M2C_FIELD(gCur3DSpriteEngine,u8**,0x1c)+0x4380);
func_020a9a30(1,0,4,M2C_FIELD(gCur3DSpriteEngine,u8**,0x1c)+0x4680);
func_020a9a30(1,2,0,M2C_FIELD(gCur3DSpriteEngine,u8**,0x30)+0x300);
gCur3DSpriteEngine=data_027e00c4;
func_0200bc5c(data_ov003_0220f59c);
data=func_020e3218(data_ov003_0220f5a4);func_02080cfc(data,M2C_FIELD(gCur3DSpriteEngine,void**,0x10));
data=func_020e3218(data_ov003_0220f5b4);func_02080cfc(data,M2C_FIELD(gCur3DSpriteEngine,void**,0x24));
func_0208116c(data_ov003_0220f5cc,224,32);func_020808dc(M2C_FIELD(gCur3DSpriteEngine,void**,0x24),32,32,7);M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
func_02091d4c(9);M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=8;
func_020c1230(M2C_FIELD(gCur3DSpriteEngine,void**,0xc),M2C_FIELD(gCur3DSpriteEngine,void**,0x20),((MenuModeBits*)(p+0x60))->mode*322+1,5);
((MenuModeBits*)(p+0x60))->mode=(u8)(((MenuModeBits*)(p+0x60))->mode==0);
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=1;
func_0208ca2c(0x5100,10,func_020ae22c(10),1);
data=func_02080e30(func_020e3218(data_ov003_0220f5e0),1);func_0207c780(data,M2C_FIELD(gCur3DSpriteEngine,u8**,0x1c)+0x2800);func_020e35cc(data);
func_0208116c(data_ov003_0220f5f4,0x2c0,32);
func_020a9a30(1,0,4,M2C_FIELD(gCur3DSpriteEngine,u8**,0x1c)+0x6500);
func_020a9a30(1,2,0,M2C_FIELD(gCur3DSpriteEngine,u8**,0x30)+0x360);
func_020a9a30(1,0,0,M2C_FIELD(gCur3DSpriteEngine,u8**,0x1c)+0x4b00);
func_020a9a30(1,0,2,M2C_FIELD(gCur3DSpriteEngine,u8**,0x1c)+0x4e00);
func_020a9a30(1,2,0,M2C_FIELD(gCur3DSpriteEngine,u8**,0x30)+0x320);
for(i=0;i<=7;i++){u8 *dest=M2C_FIELD(gCur3DSpriteEngine,u8**,0x1c)+((u16)((i<<3)+0x210)<<5);func_02007ef4(func_ov000_0216cdcc(func_ov003_02200b5c(i)),dest,256);}
func_01ff9e44(func_ov000_0216cdec(15,0),0x2e0,32);func_01ff9e44(func_ov000_0216cdec(15,0),0x300,32);
func_020ae528(M2C_FIELD(gCur3DSpriteEngine,u8**,0x30)+0x300);M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=16;
gCur3DSpriteEngine=saved;
}
#pragma opt_common_subs reset
void func_ov003_021e2518(void *arg0) {
M2C_UNK func_020a8f8c(s32); s32 func_020a8ff4(s32);
M2C_UNK func_ov003_021e3960(void *,s32,M2C_UNK);
M2C_UNK func_ov003_021e3aec(void *,s32,M2C_UNK);
M2C_UNK func_ov003_021e3ff8(void *,s16,M2C_UNK);
extern void **gCur3DSpriteEngine; extern void **data_027e00c8; extern void **data_027e00c4;
s32 v; void **saved;
if(M2C_FIELD(arg0,u8 *,0x39)==0)return;
func_020a8f8c(M2C_FIELD(arg0,s32 *,0x3c));
func_020a8f8c(M2C_FIELD(arg0,s32 *,0x40));
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
func_020a8ff4(M2C_FIELD(arg0,s32 *,0x3c));
func_020a8ff4(M2C_FIELD(arg0,s32 *,0x40));
M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x3a)=-func_020a8ff4(M2C_FIELD(arg0,s32 *,0x3c));
M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x42)=0;
func_ov003_021e3ff8(arg0,(s16)(func_020a8ff4(M2C_FIELD(arg0,s32 *,0x3c))+6),40);
gCur3DSpriteEngine=data_027e00c4;
v=func_020a8ff4(M2C_FIELD(arg0,s32 *,0x3c));
func_ov003_021e3aec(arg0,v,0);func_ov003_021e3960(arg0,v,0);
M2C_FIELD(*gCur3DSpriteEngine,s16 *,0x3e)=-44-v;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x46)=0xffe9;
gCur3DSpriteEngine=saved;
}
