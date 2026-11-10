/* 2 functions from 0x02215664 to 0x02216518 (ov005), found by ds-decomp. */
#include "common.h"
typedef struct ScreenConfig02215664 { u16 values[6]; } ScreenConfig02215664;
extern u8 data_ov005_0222071c[],data_ov005_02220730[],data_ov005_02220744[],data_ov005_02220754[],data_ov005_02220764[],data_ov005_02220774[],data_ov005_02220784[],data_ov005_02220794[],data_ov005_022207a4[],data_ov005_022207b0[],data_ov005_022207c0[],data_ov005_022207c8[],data_ov005_022207dc[],data_ov005_022207e8[],data_ov005_022207f0[];
void *GetLocalizedFileName(void *);void func_020814e4(void *);void func_02081590(void *,s32);void func_020816a4(void *,s32,s32,s32);void func_02081528(void);
void LoadFileToSpriteBuffer(void *,s32,s32);void func_020815fc(void *,s32,s32);void LoadDecompressedFileTo(void *,s32);
void func_02099450(s32,s32,s32);void func_ov005_02214b98(void);s32 func_020ae22c(s32);void func_0208ca2c(s32,s32,s32,s32);
void func_020e3058(void *,s32,s32,s32,s32,s32,s32,void *,s32);void func_ov005_02214cdc(s32);void *func_0208931c(void *);s32 func_020aaf74(void *);void func_020a9a30(s32,s32,s32,s32);void func_02091cd0(void);void func_ov005_022148f0(s32);

extern const u16 data_ov005_02220030[];
extern u8 data_ov005_02221304[],data_ov005_02220484[],data_ov005_02220570[];
extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain,g3DSpriteEngineSub;
void func_02086608(s32);void *func_020e34bc(s32);void func_02082c84(void);
void GX_SetBankForBG(s32);void func_02002968(s32);void func_02003124(s32);void func_020031cc(s32);void func_02002ab8(s32);void func_0200323c(s32);
void func_02007e98(s32,void *,s32);s32 func_020ad5dc(void);s32 func_ov005_022140f8(s32);s32 func_ov005_02214120(s32);
s32 RandomIntRange(s32,s32);void func_02090248(s32);void func_ov005_022140e4(void);void func_020822b8(void *);


void func_ov005_02215664(void *arg0){
volatile ScreenConfig02215664 first=*(const ScreenConfig02215664 *)(data_ov005_02220030+6);
volatile ScreenConfig02215664 second=*(const ScreenConfig02215664 *)data_ov005_02220030;
s32 i,j,k,t,saved;void *w;
func_02086608(7);M2C_FIELD(data_ov005_02221304,u8 **,8)=func_020e34bc(0x188);func_02082c84();GX_SetBankForBG(1);func_02002968(2);func_02003124(4);func_020031cc(8);func_02002ab8(16);func_0200323c(128);func_02007e98(0,M2C_FIELD(data_ov005_02221304,u8 **,8),0x188);
M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,0)=1;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,2)=-1;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,136)=0;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,134)=M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,136);M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u8 *,138)=0;
M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,144)=-1;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,142)=M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,144);M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,140)=M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,142);
M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,146)=0;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,148)=0;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,150)=0;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,152)=0;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,154)=func_020ad5dc();M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,158)=0;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,156)=0;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,160)=-1;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,226)=-1;
for(i=0;i<M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,154);i++){if(!func_ov005_022140f8(i))M2C_FIELD(data_ov005_02221304,u8 **,8)[i+162]=0;else{M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,156)=M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,156)+1;M2C_FIELD(data_ov005_02221304,u8 **,8)[i+162]=1;}}
M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,4)=0;
i=0;if(M2C_FIELD(data_ov005_02220484,s16 *,236)!=-1)do{if(func_ov005_02214120(M2C_FIELD(data_ov005_02220570,s16 *,(u32)i*4))){M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8)+M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,4)*2,s16 *,6)=i;M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),u16 *,4)=M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,4)+1;}i++;}while(M2C_FIELD(data_ov005_02220570,s16 *,(u32)i*4)!=-1);
for(i=0;i<M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,4)*2;i++){j=RandomIntRange(0,M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,4)-1);k=RandomIntRange(0,M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),s16 *,4)-1);t=M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8)+j*2,s16 *,6);M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8)+j*2,s16 *,6)=M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8)+k*2,s16 *,6);M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8)+k*2,s16 *,6)=t;}
func_02090248(15);func_ov005_022140e4();
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;func_020822b8(&first);
{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|16;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|32;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|64;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|128;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|256;}w=M2C_FIELD(gCur3DSpriteEngine,void **,0);M2C_FIELD(w,u16 *,6)=(M2C_FIELD(w,u16 *,6)&~3)|0;w=M2C_FIELD(gCur3DSpriteEngine,void **,0);M2C_FIELD(w,u16 *,8)=(M2C_FIELD(w,u16 *,8)&~3)|1;w=M2C_FIELD(gCur3DSpriteEngine,void **,0);M2C_FIELD(w,u16 *,10)=(M2C_FIELD(w,u16 *,10)&~3)|2;w=M2C_FIELD(gCur3DSpriteEngine,void **,0);M2C_FIELD(w,u16 *,12)=(M2C_FIELD(w,u16 *,12)&~3)|3;{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~1);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~2);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~4);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=*reg|8;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~16);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~32);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~256);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~512);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~1024);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~2048);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~4096);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=*reg|8192;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~192)|64;}M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,81)=16;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,82)=0;func_02099450(1,0,0);
func_020814e4(GetLocalizedFileName(data_ov005_0222071c));
func_02081590(GetLocalizedFileName(data_ov005_02220730),M2C_FIELD(gCur3DSpriteEngine,s32 *,20));
func_020816a4(GetLocalizedFileName(data_ov005_02220744),M2C_FIELD(gCur3DSpriteEngine,s32 *,40),0,0);func_02081528();
LoadFileToSpriteBuffer(data_ov005_02220754,0,32);
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=4;M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=2;
func_020814e4(data_ov005_02220764);
func_02081590(data_ov005_02220774,M2C_FIELD(gCur3DSpriteEngine,s32 *,12));
func_020816a4(data_ov005_02220784,M2C_FIELD(gCur3DSpriteEngine,s32 *,32),0,1);
func_020815fc(data_ov005_02220794,32,32);func_02081528();
M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=1;func_ov005_02214b98();
LoadDecompressedFileTo(data_ov005_022207a4,M2C_FIELD(gCur3DSpriteEngine,s32 *,16)+0x2480);LoadDecompressedFileTo(data_ov005_022207b0,M2C_FIELD(gCur3DSpriteEngine,s32 *,16)+0x2500);
func_0208ca2c(0x1000,1,func_020ae22c(9),2);
LoadFileToSpriteBuffer(data_ov005_022207c0,64,32);
func_0208ca2c(0x2800,6,func_020ae22c(12),2);func_020e3058(M2C_FIELD(data_ov005_02221304,u8 **,8)+364,158,166,17,384,3,256,arg0,1);func_020e3058(M2C_FIELD(data_ov005_02221304,u8 **,8)+368,66,166,16,396,3,512,arg0,0);func_020e3058(M2C_FIELD(data_ov005_02221304,u8 **,8)+372,94,122,10,408,3,-1,arg0,0);func_020e3058(M2C_FIELD(data_ov005_02221304,u8 **,8)+376,130,122,11,416,3,-1,arg0,0);func_020e3058(M2C_FIELD(data_ov005_02221304,u8 **,8)+380,112,160,47,424,3,1,arg0,0);func_020e3058(M2C_FIELD(data_ov005_02221304,u8 **,8)+384,224,160,2,440,3,2,arg0,0);func_020e3058(M2C_FIELD(data_ov005_02221304,u8 **,8)+388,20,160,49,456,3,1024,arg0,0);w=M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),void **,372);t=(u16)(((u32)(M2C_FIELD(w,u8 *,89)<<28)>>28)+2);M2C_FIELD(w,u32 *,64)=(M2C_FIELD(w,u32 *,64)&~0x3fc0000)|((u32)(t<<24)>>6);M2C_FIELD(w,u8 *,90)=0;w=M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),void **,364);t=(u16)(((u32)(M2C_FIELD(w,u8 *,89)<<28)>>28)+2);M2C_FIELD(w,u32 *,64)=(M2C_FIELD(w,u32 *,64)&~0x3fc0000)|((u32)(t<<24)>>6);M2C_FIELD(w,u8 *,90)=0;w=M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),void **,368);t=(u16)(((u32)(M2C_FIELD(w,u8 *,89)<<28)>>28)+2);M2C_FIELD(w,u32 *,64)=(M2C_FIELD(w,u32 *,64)&~0x3fc0000)|((u32)(t<<24)>>6);M2C_FIELD(w,u8 *,90)=0;gCur3DSpriteEngine=g3DSpriteEngineSub;func_020822b8(&second);{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~16);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~32);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=(*reg&~64);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|128;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+0);*reg=*reg|256;}w=M2C_FIELD(gCur3DSpriteEngine,void **,0);M2C_FIELD(w,u16 *,6)=(M2C_FIELD(w,u16 *,6)&~3)|0;w=M2C_FIELD(gCur3DSpriteEngine,void **,0);M2C_FIELD(w,u16 *,8)=(M2C_FIELD(w,u16 *,8)&~3)|1;w=M2C_FIELD(gCur3DSpriteEngine,void **,0);M2C_FIELD(w,u16 *,10)=(M2C_FIELD(w,u16 *,10)&~3)|2;w=M2C_FIELD(gCur3DSpriteEngine,void **,0);M2C_FIELD(w,u16 *,12)=(M2C_FIELD(w,u16 *,12)&~3)|3;{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~1);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~2);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~4);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=*reg|8;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~16);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~32);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~256);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~512);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~1024);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~2048);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~4096);}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=*reg|8192;}{u16 *volatile reg=(u16 *)((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0)+18);*reg=(*reg&~192)|64;}M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,81)=16;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,82)=0;func_ov005_02214cdc(0);
func_020814e4(GetLocalizedFileName(data_ov005_022207c8));
func_02081590(GetLocalizedFileName(data_ov005_022207dc),M2C_FIELD(gCur3DSpriteEngine,s32 *,28)+0x2800);func_02081528();
LoadDecompressedFileTo(data_ov005_022207e8,M2C_FIELD(gCur3DSpriteEngine,s32 *,28)+0x2c40);
LoadFileToSpriteBuffer(data_ov005_022207f0,0x2c0,32);
M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),void **,0x168)=func_0208931c(arg0);
w=M2C_FIELD(M2C_FIELD(data_ov005_02221304,u8 **,8),void **,0x168);
M2C_FIELD(w,u8 *,88)=13;
func_020a9a30(2,0,13,M2C_FIELD(gCur3DSpriteEngine,s32 *,28)+0x2e40);
func_020a9a30(2,2,13,M2C_FIELD(gCur3DSpriteEngine,s32 *,48)+0x2e0);
M2C_FIELD(w,s32 *,68)=func_020aaf74(w);
M2C_FIELD(w,u16 *,62)=0x172;
M2C_FIELD(w,u32 *,64)=(M2C_FIELD(w,u32 *,64)&~0x3fc0000)|0x5c0000;
M2C_FIELD(w,u16 *,60)=0xc00;
gCur3DSpriteEngine=saved;func_02091cd0();func_ov005_022148f0(0);}

void func_ov005_02216498(void) {
    M2C_UNK func_020b1bf4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020b1c78(M2C_UNK);
    M2C_UNK func_020b2224();
    M2C_UNK func_020b22a4(M2C_UNK, s32, M2C_UNK *, s32);
    extern M2C_UNK data_ov005_02220490;
    extern M2C_UNK data_ov005_022204b8;
    s32 var_r8;
    s32 var_r9;

    func_020b2224();
    func_020b1bf4(0, -0x10, 0x100, -0x10);
    var_r8 = 0;
    var_r9 = 0x18;
    do {
        func_020b22a4(4, var_r9, &data_ov005_02220490, var_r8);
        func_020b22a4(0xE0, var_r9, &data_ov005_022204b8, var_r8);
        var_r8 += 1;
        var_r9 += 0x10;
    } while (var_r8 < 6);
    func_020b1c78(0);
}
