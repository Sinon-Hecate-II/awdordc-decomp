/* 1 function from 0x022066D8 to 0x02207A54 (ov003), found by ds-decomp. */
#include "common.h"
extern u8 data_ov003_022109e0[];
extern u8 data_ov003_0221107c[];
extern u8 data_ov003_02211084[];
extern u8 data_ov003_02211094[];
extern u8 data_ov003_022110a4[];
extern u8 data_ov003_022110b4[];
extern u8 data_ov003_022110c0[];
extern u8 data_ov003_022110cc[];
extern u8 data_ov003_022110d8[];
extern u8 data_ov003_022110e4[];
extern u8 data_ov003_022109d4[];
extern u8 data_ov003_022110f8[];
extern u8 data_ov003_02211108[];
extern u8 data_ov003_02211118[];
extern u8 data_ov003_02211124[];
extern u8 data_ov003_02211130[];
extern u8 data_ov003_0221113c[];
extern u8 data_ov003_02211148[];
extern u8 data_ov003_02211160[];
extern u8 data_ov003_02211178[];
extern void *g3DSpriteEngineSub;
extern u32 data_0215d9b8;
extern u32 data_0215d8a0;

extern u8 data_ov003_0221106c[16];
extern void *gCur3DSpriteEngine;
extern void *g3DSpriteEngineMain;
void func_02086d18(void *);
void func_02082c84(void);
void func_02082cb4(void);
void SetFileDirectory(void *);
void func_02091cd0(void);
void func_020c8ed4(void *);


#pragma push
#pragma scheduling on
void func_ov003_022066d8(void *a){
void func_020822b8(void *);void func_02004d3c(void);u8 *func_02080e30(void *,s32);void func_02004d70(void *,s32,s32);void HeapFreeBlock(void *);void func_02004ddc(void);void LoadDecompressedFileTo(void *,void *);void func_020811b8(void *,s32,s32,s32);void func_020808dc(void *,s32,s32,s32);void func_0207c780(void *,void *);void func_01ff9e44(void *,s32,s32);void func_02091d4c(s32);void func_020a9a30(s32,s32,s32,void *);void *func_020ab1c4(void *);void func_020aab24(void *,s32,s32,s32,s32);void func_02088e84(void *,s32,s32,s32,s32);s32 func_020aae10(void *);s32 func_020aae44(void *);void func_02087d84(void *,s32,s16,s16,u16,u16);void func_02088da8(void *);
void func_02082eb4(void *,s32,s32,s32);void *GetLocalizedFileName(void *);void LoadFileToSpriteBuffer(void *,s32,s32);void func_020af62c(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);void func_ov003_02209d0c(void *,s32);void func_0208f780(s32);s32 IsUnitAvailable(s32);void func_ov003_02208034(void *);void SetSpriteAnimation(void *,s32);s32 GetSpriteAnimValue(void *);s32 n,m;void *saved,*q;u8 *p;
func_02086d18(a);func_02082c84();func_02082cb4();SetFileDirectory(data_ov003_0221106c);func_02091cd0();if((u8)((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28==0))func_020c8ed4(a);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;func_020822b8(data_ov003_022109e0);
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~16)|16;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~32)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~64)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~128)|128;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~256)|256;}*(volatile u16 *)0x04000060=(*(volatile u16 *)0x04000060&~0x3000)|8;
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~192)|64;}M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=16;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=16;{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~1)|1;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~2)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~4)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~8)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~16)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~32)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~256)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~512)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~1024)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~2048)|2048;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~4096)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~8192)|8192;}func_02004d3c();p=func_02080e30(data_ov003_0221107c,1);func_02004d70(p,32,32);HeapFreeBlock(p);p=func_02080e30(data_ov003_02211084,1);func_02004d70(p,64,32);HeapFreeBlock(p);func_02004ddc();
if((u8)(((u32)M2C_FIELD(a,u8 *,0x36)<<24)>>28==0)||(u8)(((u32)M2C_FIELD(a,u8 *,0x36)<<24)>>28==1)){
LoadDecompressedFileTo(data_ov003_02211094,M2C_FIELD(g3DSpriteEngineMain,void **,0x18));LoadDecompressedFileTo(data_ov003_022110a4,M2C_FIELD(g3DSpriteEngineMain,void **,0x2c));func_020811b8(data_ov003_022110b4,3,0,512);
}else if((u8)(((u32)M2C_FIELD(a,u8 *,0x36)<<24)>>28==2)){
LoadDecompressedFileTo(data_ov003_022110c0,M2C_FIELD(g3DSpriteEngineMain,void **,0x18));LoadDecompressedFileTo(data_ov003_022110cc,M2C_FIELD(g3DSpriteEngineMain,void **,0x2c));func_020811b8(data_ov003_022110d8,3,0,512);}
func_020808dc(M2C_FIELD(g3DSpriteEngineMain,void **,0x2c),32,32,0);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3e)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x46)=0;
p=func_02080e30(data_ov003_022110e4,1);func_0207c780((u8 *)p+0x118,M2C_FIELD(g3DSpriteEngineMain,void **,0x14));func_0207c780(p,M2C_FIELD(g3DSpriteEngineMain,void **,0x28));func_01ff9e44((u8 *)p+0x204,32,32);func_020808dc(M2C_FIELD(g3DSpriteEngineMain,void **,0x28),32,32,1);HeapFreeBlock(p);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;func_02091d4c(2);func_020808dc(M2C_FIELD(g3DSpriteEngineMain,void **,0x24),32,32,2);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
func_020a9a30(0,0,25,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x1c)+0x6c60);
func_020a9a30(0,2,0,(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x30)+0x2c0);
q=M2C_FIELD(a,void **,0x68);M2C_FIELD(q,void **,0)=func_020ab1c4(a);func_020aab24(M2C_FIELD(q,void **,0),2,320,6,0);{void *sprite=M2C_FIELD(q,void **,0);func_02088e84(sprite,224,160,224,192);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(q,void **,0));M2C_FIELD(q,void **,4)=func_020ab1c4(a);func_020aab24(M2C_FIELD(q,void **,4),12,336,6,0);{void *sprite=M2C_FIELD(q,void **,4);func_02088e84(sprite,129,62,129,62);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}M2C_FIELD(sprite,s16 *,0x34)=129;M2C_FIELD(sprite,s16 *,0x36)=62;if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(q,void **,4));M2C_FIELD(q,void **,8)=func_020ab1c4(a);func_020aab24(M2C_FIELD(q,void **,8),13,344,6,0);{void *sprite=M2C_FIELD(q,void **,8);func_02088e84(sprite,223,62,223,62);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}M2C_FIELD(sprite,s16 *,0x34)=223;M2C_FIELD(sprite,s16 *,0x36)=62;if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(q,void **,8));M2C_FIELD(q,void **,12)=func_020ab1c4(a);func_020aab24(M2C_FIELD(q,void **,12),26,352,6,0);{void *sprite=M2C_FIELD(q,void **,12);func_02088e84(sprite,160,160,160,192);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(q,void **,12));M2C_FIELD(q,void **,16)=func_020ab1c4(a);func_020aab24(M2C_FIELD(q,void **,16),27,384,6,0);{void *sprite=M2C_FIELD(q,void **,16);func_02088e84(sprite,160,160,160,192);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(q,void **,16));M2C_FIELD(q,void **,20)=func_020ab1c4(a);func_020aab24(M2C_FIELD(q,void **,20),29,416,6,0);{void *sprite=M2C_FIELD(q,void **,20);func_02088e84(sprite,0,160,0,192);if ((u8)(M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0)) {s16 sy=M2C_FIELD(sprite,s16 *,0x52),sx=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,sx,sy,(u16)w,(u16)h);}}func_02088da8(M2C_FIELD(q,void **,20));gCur3DSpriteEngine=g3DSpriteEngineSub;func_020822b8(data_ov003_022109d4);{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~16)|16;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~32)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~64)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~128)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~256)|256;}n=16-GetSpriteAnimValue(M2C_FIELD(a,void **,0x54));m=GetSpriteAnimValue(M2C_FIELD(a,void **,0x54));{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~192)|64;}M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=m;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=n;{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~1)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~2)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~4)|4;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~8)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~16)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~32)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~256)|256;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~512)|512;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~1024)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~2048)|2048;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~4096)|4096;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~8192)|8192;}if((u8)(((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)==0)||(u8)(((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)==1)){LoadDecompressedFileTo(data_ov003_022110f8,M2C_FIELD(g3DSpriteEngineSub,void **,12));LoadDecompressedFileTo(data_ov003_02211108,M2C_FIELD(g3DSpriteEngineSub,void **,32));func_020811b8(data_ov003_02211118,0,512,512);}else if((u8)(((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)==2)){LoadDecompressedFileTo(data_ov003_02211124,M2C_FIELD(g3DSpriteEngineSub,void **,12));LoadDecompressedFileTo(data_ov003_02211130,M2C_FIELD(g3DSpriteEngineSub,void **,32));func_020811b8(data_ov003_0221113c,0,512,512);}
func_020808dc(M2C_FIELD(g3DSpriteEngineSub,void **,32),32,32,1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x38)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x40)=0;
p=func_02080e30(data_ov003_02211148,1);
func_0207c780((u8 *)p+0x120,M2C_FIELD(g3DSpriteEngineSub,void **,24));func_0207c780(p,M2C_FIELD(g3DSpriteEngineSub,void **,44));
func_020808dc(M2C_FIELD(g3DSpriteEngineSub,void **,44),32,32,1);func_02082eb4((u8 *)p+0x1e0,3,512,32);HeapFreeBlock(p);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3e)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x46)=0;
p=func_02080e30(GetLocalizedFileName(data_ov003_02211160),1);func_0207c780(p,M2C_FIELD(g3DSpriteEngineSub,void **,40));func_020808dc(M2C_FIELD(g3DSpriteEngineSub,void **,40),32,32,2);HeapFreeBlock(p);
LoadFileToSpriteBuffer(data_ov003_02211178,64,32);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3c)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x44)=0;func_02091d4c(3);
func_020808dc(M2C_FIELD(g3DSpriteEngineSub,void **,36),32,32,3);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3a)=0xffe4;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x42)=0xffa0;
gCur3DSpriteEngine=saved;
if((u8)(((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)==2)){func_020af62c(3,2,1,2,1,0,2,1,2,1);}else{func_020af62c(3,2,0,2,1,0,2,0,2,1);}
switch(((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)){
case 0:func_ov003_02209d0c(a,M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15));func_0208f780(4);
M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,9)=(u32)(M2C_FIELD(&data_0215d9b8,u16 *,6)<<25)>>29;
M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,10)=1;
if((u8)(M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)==10)&&IsUnitAvailable(8)==0)func_ov003_02209d0c(a,1);
if((u8)(M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)==8))M2C_FIELD(a,u8 *,0x38)|=8;break;
case 1:M2C_FIELD(a,u8 *,0x39)=M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15);q=M2C_FIELD(a,void **,0x3c);M2C_FIELD(a,u8 *,0x3a)=M2C_FIELD(q,u8 *,M2C_FIELD(q,u8 *,15));M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,8)=0;func_ov003_02209d0c(a,8);break;
case 2:M2C_FIELD(a,u8 *,0x39)=M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15);q=M2C_FIELD(a,void **,0x3c);M2C_FIELD(a,u8 *,0x3a)=M2C_FIELD(q,u8 *,M2C_FIELD(q,u8 *,15));M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,11)=(u32)((s32)data_0215d8a0<<28)>>28;func_ov003_02209d0c(a,11);break;
}
M2C_FIELD(a,u8 *,0x38)|=64;
p=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~16)|16;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~32)|32;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~64)|64;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~128)|128;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~256)|256;}gCur3DSpriteEngine=g3DSpriteEngineSub;{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~16)|16;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~32)|32;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~64)|64;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~128)|0;}
{u16 * volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~256)|256;}gCur3DSpriteEngine=p;func_ov003_02208034(a);SetSpriteAnimation(a,1);}
#pragma pop
