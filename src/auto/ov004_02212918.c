/* 23 functions from 0x02212918 to 0x022138B0 (ov004), found by ds-decomp. */
#include "common.h"
extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain,g3DSpriteEngineSub;
static inline void Clear129(s32 off,u32 mask){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+off);*p=*p&~mask;}
static inline void Set129(s32 off,u32 mask){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+off);*p=*p|mask;}
static inline void Blend129(s32 n){u16 * volatile p=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0)+18);*p=(*p&~0xc0)|(n<<6);}
static inline void Store129(s32 off,u16 n){M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,off)=n;}

void func_ov004_02212918(void *state){
s32 EaseInterpolate(s32,s16,s16,u16,s32);void func_0208c830(void *,s32);void func_0208c7b8(void *,s32);void func_ov004_022124e0(s32,s32,s32,s32);void func_ov004_02212688(s32,s32,s32);
s32 saved,screen,engine,value;
saved=gCur3DSpriteEngine;
for(screen=0;screen<2;screen++){
engine=screen==0?g3DSpriteEngineMain:g3DSpriteEngineSub;gCur3DSpriteEngine=engine;
if(engine==g3DSpriteEngineSub){
if(M2C_FIELD(state,u8 *,0x3d)!=0)M2C_FIELD(state,u8 *,0x3d)--;
else switch(M2C_FIELD(state,u8 *,0x3b)){
case 0:
Blend129(1);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=16;
Clear129(18,1);Clear129(18,2);Clear129(18,4);Clear129(18,8);Set129(18,16);Clear129(18,32);Clear129(18,256);Clear129(18,512);Clear129(18,1024);Set129(18,2048);Clear129(18,4096);Clear129(18,8192);
Clear129(0,16);Clear129(0,32);Clear129(0,64);Set129(0,128);Set129(0,256);
M2C_FIELD(state,u16 *,0x34)=0;M2C_FIELD(state,u8 *,0x3b)++;break;
case 1:
M2C_FIELD(state,u16 *,0x34)++;
value=EaseInterpolate(0,0,16,M2C_FIELD(state,u16 *,0x34),16);
M2C_FIELD(state,u8 *,0x3c)=EaseInterpolate(0,0,20,M2C_FIELD(state,u16 *,0x34),16);
Blend129(1);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=value;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=16-value;
if(M2C_FIELD(state,u16 *,0x34)>=16){
Blend129(0);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=0;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x53)=0;M2C_FIELD(state,u8 *,0x3b)++;
}break;
case 2:
Clear129(0,16);Set129(0,32);Set129(0,64);Set129(0,128);Set129(0,256);
Blend129(1);M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x51)=16;M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u8 *,0x52)=16;
Clear129(18,1);Clear129(18,2);Set129(18,4);Clear129(18,8);Clear129(18,16);Clear129(18,32);Clear129(18,256);Set129(18,512);Clear129(18,1024);Clear129(18,2048);Clear129(18,4096);Clear129(18,8192);
func_0208c830(M2C_FIELD(state,void **,0x44),32);M2C_FIELD(state,u8 *,0x3d)=16;M2C_FIELD(state,u8 *,0x3b)++;break;
case 3:
func_0208c830(M2C_FIELD(state,void **,0x40),32);M2C_FIELD(state,u8 *,0x3d)=16;M2C_FIELD(state,u8 *,0x3b)++;break;
case 4:
func_0208c7b8(M2C_FIELD(state,void **,0x44),32);M2C_FIELD(state,u8 *,0x3b)++;break;
}
Store129(0x3a,0);Store129(0x42,0xffb0);Store129(0x3c,0);Store129(0x44,0xffb0);
Store129(0x3e,(u8)(M2C_FIELD(state,u16 *,0x36)>>1));Store129(0x46,0);
func_ov004_022124e0(80,56,0,M2C_FIELD(state,u8 *,0x3a));
func_ov004_02212688(32,96-M2C_FIELD(state,u8 *,0x3c),0);func_ov004_02212688(32,96+M2C_FIELD(state,u8 *,0x3c),0);
}}
gCur3DSpriteEngine=saved;M2C_FIELD(state,u16 *,0x36)++;
}

void func_ov004_022130f4(void) {
    M2C_UNK func_ov004_022120c0();
    func_ov004_022120c0();
}

void func_ov004_02213100(void) {
    M2C_UNK func_ov004_0221285c();
    func_ov004_0221285c();
}

void func_ov004_0221310c(void) {
    void func_ov004_02212918();
    func_ov004_02212918();
}

void func_ov004_02213118(void) {
    M2C_UNK func_ov004_022128b8();
    func_ov004_022128b8();
}

void func_ov004_02213124(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov004_02218da8;
    func_01ffa42c(&data_ov004_02218da8, arg0);
}

s32 func_ov004_0221313c(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 struct Bits2e98 { u8 kind:6; u8 sub:2; };
 s32 i; s32 p; s32 end; struct Bits2e98 *u;
 i=gPlayerUnitIdBase[1]+1; end=gPlayerUnitIdBase[1]+0x33;
 if(i<end) {p=(s32)*gCurrentMap+0x59A4+i*14;
 do {u=(struct Bits2e98 *)p; if(u->kind&&u->sub)return 1; i++; p+=14;}while(i<end);}
 return 0;
}

s32 func_ov004_022131b0(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 u32 bits; s32 i; u8 *p; s32 end;
 i=gPlayerUnitIdBase[1]+1; end=gPlayerUnitIdBase[1]+0x33;
 if(i<end) {p=(u8 *)*gCurrentMap+0x59A4+i*14;
 do {bits=(u32)(*p<<26)>>26; if(bits&&((u32)(M2C_FIELD(p,u16 *,6)<<25)>>25)<=90U)return 1; i++; p+=14;}while(i<end);}
 return 0;
}

s32 func_ov004_0221322c(void) {
 extern void **gCurrentMap;
 void *p;
 s32 n;
 s16 x, y;
 p = *gCurrentMap;
 n = M2C_FIELD(p, u16 *, 0x52A2);
 if (n < 2) return 0;
 x = M2C_FIELD(p, s16 *, 0x52DC);
 y = M2C_FIELD(p, s16 *, 0x52DE);
 return x == 11 && y == 6;
}

s32 func_ov004_0221326c(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 s32 i; u8 *p; s32 end; u8 *base;
 base=(u8 *)*gCurrentMap;
 if((s32)M2C_FIELD(base,u16 *,0x52A2)<2)return 0;
 i=gPlayerUnitIdBase[1]+1; end=gPlayerUnitIdBase[1]+0x33;
 if(i<end) {p=base+0x59A4+i*14;
 do {if(((u32)(*p<<26)>>26)&&p[1]==11&&p[2]==6)return 1; i++; p+=14;}while(i<end);}
 return 0;
}

s32 func_ov004_022132fc(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 u32 bits; s32 i; u8 *p; s32 end;
 i=gPlayerUnitIdBase[1]+1; end=gPlayerUnitIdBase[1]+0x33;
 if(i<end) {p=(u8 *)*gCurrentMap+0x59A4+i*14;
 do {bits=(u32)(*p<<26)>>26; if(bits&&((u32)(M2C_FIELD(p,u16 *,6)<<25)>>25)<=70U&&bits==2)return 1; i++; p+=14;}while(i<end);}
 return 0;
}

s32 func_ov004_02213380(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 u32 bits; s32 i; u8 *p; s32 end;
 i=gPlayerUnitIdBase[1]+1; end=gPlayerUnitIdBase[1]+0x33;
 if(i<end) {p=(u8 *)*gCurrentMap+0x59A4+i*14;
 do {bits=(u32)(*p<<26)>>26; if(bits&&((u32)(M2C_FIELD(p,u16 *,6)<<25)>>25)<=70U&&bits==7)return 1; i++; p+=14;}while(i<end);}
 return 0;
}

u8 func_ov004_02213404(void) {
    extern void **gCurrentMap;
    u8 temp_r1;
    u8 var_r0;
    void *temp_r2;

    temp_r2 = *gCurrentMap;
    temp_r1 = M2C_FIELD((temp_r2 + (M2C_FIELD(temp_r2, u16 *, 0x3762) + 5)), u8 *, 0x508);
    if (temp_r1 == 0) {
        return 0U;
    }
    if ((u32) ((u32) (M2C_FIELD(((temp_r1 * 0xE) + (s32) temp_r2), u16 *, 0x59AA) << 0x19) >> 0x19) <= 0x5AU) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov004_02213460(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 s32 count; s32 i; u8 *p; s32 end; u8 v;
 count=0; i=gPlayerUnitIdBase[2]+1; end=gPlayerUnitIdBase[2]+0x33;
 if(i<end) {p=(u8 *)*gCurrentMap+0x59A4+i*14;
 do {v=*p; if((u32)(v<<26)>>26) count++; i++; p+=14;}while(i<end);}
 if(count<=4)return 1; return 0;
}

s32 func_ov004_022134d0(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 s32 result; u32 bits; s32 i; u8 *p; s32 end; u8 *base;
 result=1; base=(u8 *)*gCurrentMap;
 if((s32)M2C_FIELD(base,u16 *,0x52A2)>1)return 0;
 i=gPlayerUnitIdBase[1]+1; end=gPlayerUnitIdBase[1]+0x33;
 if(i<end) {p=base+0x59A4+i*14;
 do {bits=(u32)(*p<<26)>>26; if(bits&&bits==1&&p[2]<=5U)result=0; i++; p+=14;}while(i<end);}
 return result;
}

s32 func_ov004_02213564(void) {
 extern void **gCurrentMap; extern u8 gAiCommand;
 u8 value; u8 *p; u8 *base; u8 x,y;
 base=*gCurrentMap; p=M2C_FIELD(base,u8 **,0x52D0); x=p[1]; y=p[2];
 if(gAiCommand==3) {
 p=base+(x+M2C_FIELD(base+y*2,u16 *,0x3758)); value=p[0x1420];
 if(((s32)(value&0xE0)>>5)==1&&(value&0x1F)==0x10)return 1;
 } return 0;
}

s32 func_ov004_022135d8(void) {
extern void **gCurrentMap;
extern u8 gAiCommand;
u8 value,*p,*base,x,y;
base=*gCurrentMap;
p=M2C_FIELD(base,u8 **,0x52d0);
x=p[1];y=p[2];
if(gAiCommand==3) {
p=base+(x+M2C_FIELD(base+y*2,u16 *,0x3758));value=p[0x1420];
if(((s32)(value&0xe0)>>5)==1 && (value&0x1f)==0x11)return 1;
}
return 0;
}

s32 func_ov004_0221364c(void) {
extern void **gCurrentMap;
extern u8 gAiCommand;
u8 value,*p,*base,x,y;
base=*gCurrentMap;
p=M2C_FIELD(base,u8 **,0x52d0);
x=p[1];y=p[2];
if(gAiCommand==3 && M2C_FIELD(base,u16 *,0x52a4)==1) {
p=base+(x+M2C_FIELD(base+y*2,u16 *,0x3758));value=p[0x1420];
if((value&0x1f)==0x11)return 1;
}
return 0;
}

s32 func_ov004_022136c0(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 u32 bits; s32 i; u8 *p; s32 end;
 i=gPlayerUnitIdBase[1]+1; end=gPlayerUnitIdBase[1]+0x33;
 if(i<end) {p=(u8 *)*gCurrentMap+0x59A4+i*14;
 do {bits=(u32)(*p<<26)>>26; if(bits&&((u32)(M2C_FIELD(p,u16 *,6)<<25)>>25)<=90U)return 1; i++; p+=14;}while(i<end);}
 return 0;
}

s32 func_ov004_0221373c(void) {
extern void **gCurrentMap;
u8 *base; u32 i; u8 v;
base=*gCurrentMap;
if(M2C_FIELD(base,u16 *,0x52a4)==1) {
i=M2C_FIELD(base,u16 *,0x3764)+3;
v=(base+i)[0x1420];
if(((s32)(v&0xe0)>>5)==1) {if(base[i]==0)return 1;}
}return 0;
}

s32 func_ov004_02213798(void) {
extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];
s32 count,i,end;u8 *p,v;
count=0;
if(func_02086b40(0))return count;
i=gPlayerUnitIdBase[2]+1;end=gPlayerUnitIdBase[2]+0x33;
if(i<end) {
p=(u8 *)*gCurrentMap+0x59a4+i*14;
do {v=*p;if((u32)(v<<26)>>26)count++;i++;p+=14;}while(i<end);
}
if(count!=0)return 0;return 1;
}

u8 func_ov004_02213820(void) {
    s32 func_02086b40(M2C_UNK);
    u8 var_r0;

    if (func_02086b40(1) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov004_02213840(void) {
 extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
 s32 count; s32 i; u8 *p; s32 end; u8 v;
 count=0; i=gPlayerUnitIdBase[2]+1; end=gPlayerUnitIdBase[2]+0x33;
 if(i<end) {p=(u8 *)*gCurrentMap+0x59A4+i*14;
 do {v=*p; if((u32)(v<<26)>>26) count++; i++; p+=14;}while(i<end);}
 if(count!=0)return 0; return 1;
}

