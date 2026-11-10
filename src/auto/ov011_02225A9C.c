/* 5 functions from 0x02225A9C to 0x02226658 (ov011), found by ds-decomp. */
#include "common.h"
extern s32 gCur3DSpriteEngine;
extern s32 g3DSpriteEngineMain,g3DSpriteEngineSub;
extern u8 data_ov011_02228a3c[],data_ov011_02228b54[],data_ov011_02228b5c[],data_ov011_02228b68[],data_ov011_02228b74[],data_ov011_02228b80[],data_ov011_02228a30[],data_ov011_02228b8c[],data_ov011_02228b94[],data_ov011_02228ba0[],data_ov011_02228bac[],data_ov011_02228bb8[],data_ov011_02228bc4[],data_ov011_02228bcc[],data_ov011_02228bd8[],data_ov011_02228be4[],data_ov011_02228bf0[],data_ov011_02228bfc[],data_ov011_02228c04[],data_ov011_02228c0c[];
static inline void Clear25d(s32 offset,u32 mask){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+offset);*p= *p & ~mask;}
static inline void Set25d(s32 offset,u32 mask){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+offset);*p= *p | mask;}
static inline void Priority25d(s32 offset,s32 n){u16 *p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+offset);*p=(*p&~3)|n;}
typedef struct Mode25d {u16 mode:3;u16 rest:13;} Mode25d;

void func_ov011_02225a9c(void *arg0,s32 arg1,s32 arg2,s32 arg3){
void StringFormat(void *,void *,...);
void func_ov011_02226550(s32,s32);
s32 EaseInterpolate(s32,s32,s32,s32,s32);
extern u8 data_ov011_02228b48[];
char buf[8];s32 start;u8 alpha;
StringFormat(buf,data_ov011_02228b48,arg3);
switch(arg3){case 0:start=600;break;case 1:start=1600;break;case 2:start=2600;break;case 3:start=3600;break;case 4:start=4600;break;case 5:start=5600;break;case 6:start=6600;break;case 7:start=7600;break;case 8:start=8600;break;case 9:start=9600;break;}
if(M2C_FIELD(arg0,u16 *,0x3a)==start){
M2C_FIELD(arg0,u16 *,0x3c)=arg1;
M2C_FIELD(arg0,u16 *,0x3e)=arg2;
func_ov011_02226550((s32)buf,2);
}
if(M2C_FIELD(arg0,u16 *,0x3a)<start)return;
if(M2C_FIELD(arg0,u16 *,0x3a)>start+620)return;
Set25d(0,16);Clear25d(0,32);Set25d(0,64);Set25d(0,128);Clear25d(0,256);
M2C_FIELD(arg0,u16 *,0x3e)=EaseInterpolate(0,0,64,M2C_FIELD(arg0,u16 *,0x3a)-start,740);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3c)=M2C_FIELD(arg0,u16 *,0x3c);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x44)=M2C_FIELD(arg0,u16 *,0x3e);
if(M2C_FIELD(arg0,u16 *,0x3a)<=start+120){
u16 *volatile p;
M2C_FIELD(arg0,u8 *,0x36)=EaseInterpolate(4,0,16,M2C_FIELD(arg0,u16 *,0x3a)-start,120);
alpha=M2C_FIELD(arg0,u8 *,0x36);
p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18);*p=(*p&~192)|64;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=alpha;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=16-alpha;
}else if(M2C_FIELD(arg0,u16 *,0x3a)>=start+500){
u16 *volatile p;
M2C_FIELD(arg0,u8 *,0x36)=EaseInterpolate(1,0,16,M2C_FIELD(arg0,u16 *,0x3a)-(start+500),120);
alpha=M2C_FIELD(arg0,u8 *,0x36);
p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18);*p=(*p&~192)|64;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=16-alpha;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=alpha;
}
}

#pragma opt_common_subs off
void func_ov011_02225d98(void *state){
s32 func_02082cb4(void *);s32 func_020822b8(void *);s32 func_01ff9ce8(u8);s32 SetFileDirectory(void *);s32 OpenNarcArchive(void *);s32 LoadNarcFileDecompressed(void *,s32);s32 LoadNarcFileToSpriteBuffer(void *,s32,s32);s32 CloseNarcArchive(void);s32 func_01ff9c34(u8,s32);s32 func_01ff85b8(s32,u16,s32);s32 func_02091d4c(s32);s32 func_02088774(s32);s32 func_020aeebc(s32,s32,s32);s32 func_020ae46c(s32,s32,s32,s32);s32 func_0208161c(void *,s32,s32,s32);s32 GetLocalizedFileName(void *);s32 LoadDecompressedFileTo(s32,s32);s32 LoadFileToSpriteBuffer(void *,s32,s32);s32 func_0209cce4(void *,s32);s32 func_0208f780(s32);
extern M2C_UNK func_ov011_0222513c;extern M2C_UNK func_ov011_02225224;
s32 saved;
M2C_FIELD(state,u8 *,0x34)&=~1;func_02082cb4(state);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
func_020822b8(data_ov011_02228a3c);
Priority25d(6,0);Priority25d(8,1);Priority25d(10,2);Priority25d(12,3);
Set25d(0,16);Clear25d(0,32);Set25d(0,64);Set25d(0,128);Set25d(0,256);
Clear25d(18,256);Clear25d(18,512);Set25d(18,1024);Set25d(18,2048);Clear25d(18,4096);
func_01ff9ce8(2);SetFileDirectory(data_ov011_02228b54);OpenNarcArchive(data_ov011_02228b5c);
LoadNarcFileDecompressed(data_ov011_02228b68,M2C_FIELD(gCur3DSpriteEngine,s32 *,20));
LoadNarcFileDecompressed(data_ov011_02228b74,M2C_FIELD(gCur3DSpriteEngine,s32 *,40));
LoadNarcFileToSpriteBuffer(data_ov011_02228b80,32,32);CloseNarcArchive();
func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,s32 *,40),(u16)func_01ff9c34((u8)M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),Mode25d *,0).mode,2),4096);
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=4;
Set25d(0,4096);Clear25d(0,0x6000);
func_02091d4c(31);func_02088774(30);func_020aeebc(3,15,7);
func_020ae46c(M2C_FIELD(gCur3DSpriteEngine,s32 *,48)+480,0,8,8);
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=16;M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=8;
gCur3DSpriteEngine=g3DSpriteEngineSub;func_020822b8(data_ov011_02228a30);
Priority25d(6,3);Priority25d(8,0);Priority25d(10,1);Priority25d(12,2);
Set25d(0,16);Clear25d(0,32);Clear25d(0,64);Set25d(0,128);Clear25d(0,256);
func_01ff9ce8(0);SetFileDirectory(data_ov011_02228b8c);OpenNarcArchive(data_ov011_02228b94);
LoadNarcFileDecompressed(data_ov011_02228ba0,M2C_FIELD(gCur3DSpriteEngine,s32 *,12));
LoadNarcFileDecompressed(data_ov011_02228bac,M2C_FIELD(gCur3DSpriteEngine,s32 *,32));
LoadNarcFileToSpriteBuffer(data_ov011_02228bb8,0,32);CloseNarcArchive();
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=1;
func_01ff9ce8(3);SetFileDirectory(data_ov011_02228bc4);OpenNarcArchive(data_ov011_02228bcc);
LoadNarcFileDecompressed(data_ov011_02228bd8,M2C_FIELD(gCur3DSpriteEngine,s32 *,24));
LoadNarcFileDecompressed(data_ov011_02228be4,M2C_FIELD(gCur3DSpriteEngine,s32 *,44));
func_0208161c(data_ov011_02228bf0,3,0,512);CloseNarcArchive();
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=8;
SetFileDirectory(data_ov011_02228bfc);
LoadDecompressedFileTo(GetLocalizedFileName(data_ov011_02228c04),M2C_FIELD(gCur3DSpriteEngine,s32 *,28));
LoadFileToSpriteBuffer(data_ov011_02228c0c,512,32);
Clear25d(18,1);Clear25d(18,2);Set25d(18,4);Clear25d(18,8);Clear25d(18,16);
Set25d(18,256);Clear25d(18,512);Clear25d(18,1024);Set25d(18,2048);Clear25d(18,4096);
gCur3DSpriteEngine=saved;func_0209cce4(&func_ov011_0222513c,4);func_0209cce4(&func_ov011_02225224,10);func_0208f780(0x10011);
}
#pragma opt_common_subs reset
void func_ov011_022264e4(void) {
    M2C_UNK func_0209cd00(M2C_UNK *);
    M2C_UNK func_020af1e4();
    extern M2C_UNK func_ov011_0222513c;
    extern M2C_UNK func_ov011_02225224;
    func_0209cd00(&func_ov011_0222513c);
    func_0209cd00(&func_ov011_02225224);
    func_020af1e4();
}

void func_ov011_02226508(void *arg0) {
extern s32 gCur3DSpriteEngine;
M2C_FIELD(arg0,u16 *,0x3A)++;
M2C_FIELD(arg0,u8 *,0x37)++;
if (((u32)(M2C_FIELD(arg0,u8 *,0x34)<<31)>>31)==0) return;
*(volatile s32 *)&gCur3DSpriteEngine = *(volatile s32 *)&gCur3DSpriteEngine;
M2C_FIELD(arg0,u8 *,0x38)++;
}

void func_ov011_02226550(s32 arg0,s32 arg1) {
s32 func_01ff9ce8(u8);
s32 SetFileDirectory(void *);
s32 StringCopy(void *,s32);
s32 StringAppend(void *,void *);
s32 OpenNarcArchive(void *);
s32 CloseNarcArchive(void);
s32 LoadNarcFileDecompressed(void *,s32);
s32 func_02081644(void *,s32,s32,s32);
extern s32 gCur3DSpriteEngine;
extern M2C_UNK data_ov011_02228c14,data_ov011_02228c1c,data_ov011_02228c20,data_ov011_02228c24,data_ov011_02228c28;
u32 sp60[8],sp40[8],sp20[8],sp0[8];
StringCopy(sp60,arg0);StringAppend(sp60,&data_ov011_02228c14);
StringCopy(sp40,arg0);StringAppend(sp40,&data_ov011_02228c1c);
StringCopy(sp20,arg0);StringAppend(sp20,&data_ov011_02228c20);
StringCopy(sp0,arg0);StringAppend(sp0,&data_ov011_02228c24);
func_01ff9ce8((u8)arg1);SetFileDirectory(&data_ov011_02228c28);
OpenNarcArchive(sp60);
LoadNarcFileDecompressed(sp40,M2C_FIELD(gCur3DSpriteEngine+arg1*4,s32 *,12));
LoadNarcFileDecompressed(sp20,M2C_FIELD(gCur3DSpriteEngine+arg1*4,s32 *,32));
func_02081644(sp0,arg1,0,0x200);CloseNarcArchive();
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1<<arg1;
}

