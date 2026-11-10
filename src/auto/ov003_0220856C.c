/* 5 functions from 0x0220856C to 0x02209310 (ov003), found by ds-decomp. */
#include "common.h"

s16 GetSpriteAnimValue(void *);
void func_02086e9c(void);
void func_02086dfc(s32);
s32 Divide(s32, s32);
void func_02087048(s32, s32);
void func_020a8cf0(s32, s32, s32, s32, u16, s32, u16, u16, u16, volatile u16);
s32 func_ov003_02206690(s32, s32, s32);
s32 func_020e4b28(s32);
s32 func_020a8e28(s32, s32);
void func_020bf054(s32, s32);
s32 func_020bee64(void);
void func_020a8e3c(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
static inline u8 Animated856(void *p){return M2C_FIELD(p,u8 *,0x34)!=0;}
static inline u8 Mode856(void *p,s32 m){return M2C_FIELD(M2C_FIELD(p,void **,0x3c),u8 *,15)==m;}
static inline u8 Pair856(void *p,u8 i){return M2C_FIELD(M2C_FIELD(p,void **,0x3c),u8 *,15)==8 && i<=1;}
static inline u8 Split856(void *p,u8 i){return Mode856(p,8)&&func_ov003_02206690(i,2,4)!=0;}
static inline u8 Row856(void *p,u8 i,u8 target){return Mode856(p,8)&&i==target;}
static inline s32 Selected856(void *p,s32 none){void *q=M2C_FIELD(M2C_FIELD(p,void **,0x5c),void **,0);return (u8)((q?M2C_FIELD(q,u16 *,8):none)-11);}
static inline u8 Small856(s32 value){return value<3;}

void func_ov003_0220856c(void *arg0,s32 arg1,s32 arg2){
s32 x,sx,sy,i,y;s16 width;void *entry,*data; s32 originY,scaleX,scaleY,alpha,color;void *desc;s32 shiftedX,image,imageSel,align,image2,image2Sel,offset,half,halfSel,shade,shiftedY,base,none,white;
originY=(s16)arg2;func_02086dfc((s16)arg2);
data=M2C_FIELD(arg0,void **,68);i=0;
if((s32)M2C_FIELD(data,u8 *,0)>0){base=0x8ec0;none=-1;white=none+0x8000;offset=0;
do{
entry=(u8 *)M2C_FIELD(arg0,void **,72)+offset;desc=M2C_FIELD(entry,void **,0);
width=M2C_FIELD(data,u8 *,1);half=width>>1;
x=(s16)(arg1+M2C_FIELD(entry,s16 *,6)+(width>>1));
y=(s16)(originY+M2C_FIELD(entry,s16 *,8)+(M2C_FIELD(data,u8 *,2)>>1));
shade=M2C_FIELD(entry,u8 *,17)==1?0x6bef:0;
if(Animated856(arg0)){
if(M2C_FIELD(M2C_FIELD(entry,void **,32),u8 *,14))alpha=M2C_FIELD(entry,s8 *,19);
else alpha=GetSpriteAnimValue(M2C_FIELD(M2C_FIELD(entry,void **,32),void **,0));
color=26;
if(!M2C_FIELD(M2C_FIELD(entry,void **,24),u8 *,14)){
sx=(M2C_FIELD(entry,u16 *,12)*GetSpriteAnimValue(M2C_FIELD(M2C_FIELD(entry,void **,24),void **,0)))>>8;
sy=(M2C_FIELD(entry,u16 *,12)*GetSpriteAnimValue(M2C_FIELD(M2C_FIELD(entry,void **,28),void **,0)))>>8;
scaleX=GetSpriteAnimValue(M2C_FIELD(M2C_FIELD(entry,void **,24),void **,0));
scaleY=GetSpriteAnimValue(M2C_FIELD(M2C_FIELD(entry,void **,28),void **,0));
if(sx==0||sy==0){data=M2C_FIELD(arg0,void **,68);originY=(s16)(originY+M2C_FIELD(data,u8 *,4));goto advance;}
}
}else{
alpha=M2C_FIELD(entry,s8 *,19);
if(i!=Selected856(arg0,none))color=26;
else{alpha+=GetSpriteAnimValue(M2C_FIELD(arg0,void **,80));color=31;}
sx=sy=M2C_FIELD(entry,u16 *,12);scaleX=scaleY=256;
}
func_02087048(1,31);
if(Pair856(arg0,i)){
*(volatile u32 *)0x4000480=(u16)(color|(color<<5)|(color<<10));
func_020a8cf0(x+(width>>2),y,1,(u16)half,24,3,0x22a,1,(u16)scaleX,(u16)scaleY);
*(volatile u32 *)0x4000480=white;
}
if(!(Small856((24*(s16)sy)>>8)|Small856((M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,1)*(s16)sx)>>8))){
if(i!=Selected856(arg0,none)){
shiftedX=Divide(sx<<8,205);shiftedY=Divide(sy<<8,205);
image=M2C_FIELD(desc,u16 *,6);
if(Mode856(arg0,9)||Mode856(arg0,11)){func_020bf054(0,i);if(func_020bee64())image=base+0x1cc0;else if(!func_020e4b28(i))image=base+0x10c0;}
if(Pair856(arg0,i)){func_020a8cf0(x-48,y,1,96,16,3,image>>5,1,(u16)shiftedX,(u16)shiftedY);}
else if(Split856(arg0,i)){
if(Row856(arg0,i,2)){
switch((u8)M2C_FIELD(M2C_FIELD(arg0,void **,64),u32 *,4)){case 0:image2=base-0x300;goto nonsel_tex;case 1:image2=base+0x600;goto nonsel_tex;case 2:image2=base;goto nonsel_tex;}}
if(Row856(arg0,i,3)){
switch((u8)M2C_FIELD(M2C_FIELD(arg0,void **,64),u32 *,28)){case 0:image2=base-0x300;goto nonsel_tex;case 1:image2=base+0x300;goto nonsel_tex;case 2:image2=base;goto nonsel_tex;}}
if(Row856(arg0,i,4)){
switch((u8)M2C_FIELD(M2C_FIELD(arg0,void **,64),u32 *,52)){case 0:image2=base-0x600;goto nonsel_tex;case 1:image2=base;goto nonsel_tex;}}
image2=0;
nonsel_tex:
halfSel=width>>1;
func_020a8cf0(x-48,y,1,96,16,3,image>>5,1,(u16)shiftedX,(u16)shiftedY);
func_020a8cf0(x+48,y,1,96,16,3,image2>>5,1,(u16)shiftedX,(u16)shiftedY);
}else func_020a8cf0(x,y,1,192,16,3,image>>5,1,(u16)shiftedX,(u16)shiftedY);
func_020a8cf0(x,y,10,256,M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,3),3,M2C_FIELD(desc,u16 *,10)>>5,2,(u16)shiftedX,(u16)shiftedY);
}else{
imageSel=M2C_FIELD(desc,u16 *,4);
if(Mode856(arg0,9)||Mode856(arg0,11)){func_020bf054(0,i);if(func_020bee64())imageSel=0x9500;else if(!func_020e4b28(i))imageSel=0x8000;}
if(Pair856(arg0,i)){halfSel=width>>1;align=func_020a8e28(halfSel,sx);func_020a8cf0(x-(width>>2)+align,y,1,(u16)halfSel,24,3,imageSel>>5,1,(u16)sx,(u16)sy);}
else if(Split856(arg0,i)){
align=func_020a8e28(half,sx);if(Row856(arg0,i,2)){
switch((u8)M2C_FIELD(M2C_FIELD(arg0,void **,64),u32 *,4)){case 0:image2Sel=base-0x2f40;goto sel_tex;case 1:image2Sel=base-0x1f80;goto sel_tex;case 2:image2Sel=base-0x2a00;goto sel_tex;}}
if(Row856(arg0,i,3)){
switch((u8)M2C_FIELD(M2C_FIELD(arg0,void **,64),u32 *,28)){case 0:image2Sel=base-0x2f40;goto sel_tex;case 1:image2Sel=0x6a00;goto sel_tex;case 2:image2Sel=base-0x2a00;goto sel_tex;}}
if(Row856(arg0,i,4)){
switch((u8)M2C_FIELD(M2C_FIELD(arg0,void **,64),u32 *,52)){case 0:image2Sel=base-0x3480;goto sel_tex;case 1:image2Sel=base-0x2a00;goto sel_tex;}}
image2Sel=0;
sel_tex:
func_020a8cf0(x-(width>>2)+align,y,1,(u16)(width>>1),24,3,imageSel>>5,1,(u16)sx,(u16)sy);
func_020a8cf0(x+(width>>2)-align,y,1,(u16)(width>>1),24,3,image2Sel>>5,1,(u16)sx,(u16)sy);
}else func_020a8cf0(x,y,1,(u16)width,24,3,imageSel>>5,1,(u16)sx,(u16)sy);
func_020a8cf0(x,y,10,256,M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,3),3,M2C_FIELD(desc,u16 *,8)>>5,2,(u16)sx,(u16)sy);
}
}
align=Pair856(arg0,i)?128:256;
if(alpha && !((u32)(M2C_FIELD(arg0,u8 *,56)<<27)>>31) &&
(((u32)(M2C_FIELD(arg0,u8 *,56)<<30)>>31)||i!=Selected856(arg0,none))){
func_02087048(1,(u8)alpha);func_020a8e3c(x,y,2,width,M2C_FIELD(M2C_FIELD(arg0,void **,68),u8 *,2),shade,sx,sy,align,256);func_02087048(1,31);
}
if(!Pair856(arg0,i)&&Mode856(arg0,8))func_ov003_02206690((u8)i,2,4);
next:data=M2C_FIELD(arg0,void **,68);originY=(s16)(originY+M2C_FIELD(data,u8 *,4));advance:i++;offset+=36;
}while(i<M2C_FIELD(data,u8 *,0));
}
func_02086e9c();
}

u8 func_ov003_02209258(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 9) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_02209274(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 2) result = 1;
 else result = 0;
 return result;
}

u8 func_ov003_022092a8(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 3) result = 1;
 else result = 0;
 return result;
}

u8 func_ov003_022092dc(void *arg0, s32 arg1) {
 s32 active;
 s32 result;
 if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active = 1;
 else active = 0;
 if ((active & 0xFF) && arg1 == 4) result = 1;
 else result = 0;
 return result;
}

