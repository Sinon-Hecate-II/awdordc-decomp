/* 4 functions from 0x02188D64 to 0x02189A08 (ov000), found by ds-decomp. */
#include "common.h"


void func_ov000_02188d64(void) {
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
s32 func_ov000_02189000(s32 x,s32 y,s16 *out) {
extern void **gCurrentMap;
extern u8 data_ov000_021b5bfc[];
s32 func_ov000_021a9084(s32); s32 func_ov000_021a8fc0(s16); s32 func_ov000_021a98e4(s32);
s32 sy; s32 ndy,minx,maxy;
register s32 id,dy,j,i,maxx;
s32 dist,kind,cost,zero,adx;
void *base;
out[0]=0x270f;
minx=x-1;
if(minx<0)minx=0;
i=y-1;
if(i<0)i=0;
base=*gCurrentMap;
maxx=M2C_FIELD(base,u16*,0x5144)-1;
if(x+1<maxx)maxx=x+1;
maxy=M2C_FIELD(base,u16*,0x5146)-1;
if(y+1<maxy)maxy=y+1;
for(;i<=maxy;i++){
j=minx;
if(j<=maxx){
dy=y-i;ndy=i-y;sy=i;
do {
dist=0;
adx=x-j;
if(adx>0)dist=adx+dist;else dist=(j-x)+dist;
if(dy>0)dist=dist+dy;else dist=dist+ndy;
if(dist>=1&&dist<=1){
base=*gCurrentMap;
cost=M2C_FIELD(M2C_FIELD(base+i*4,s8**,0x52e8),s8*,j);
if(cost>=0&&cost<=110){
if(func_ov000_021a9084(M2C_FIELD(base+j+M2C_FIELD(base+i*2,u16*,0x3758),u8*,0x1420))){
base=*gCurrentMap;
id=M2C_FIELD(base+j,u8*,M2C_FIELD(base+i*2,u16*,0x3758));
if(id){
if(!func_ov000_021a8fc0((s16)id))goto next;

base=*gCurrentMap;
kind=(u32)(M2C_FIELD(base+id*14,u8*,0x59a4)<<26)>>26;
if((data_ov000_021b5bfc[kind*112+19]&7)||func_ov000_021a98e4(kind)==1)goto next;
}
{
if(out[0]==0x270f||M2C_FIELD(M2C_FIELD(*gCurrentMap+i*4,s8**,0x52e8),s8*,j)<=M2C_FIELD(M2C_FIELD(*gCurrentMap+out[1]*4,s8**,0x52e8),s8*,out[0])){
out[0]=j;out[1]=(s16)sy;
}
}
}
}
}
next:
j++;
}while(j<=maxx);
}
}
if(out[0]==0x270f)return 0;return 1;
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
s32 func_ov000_02189248(void *arg0, void *arg1) {
    (void)arg0;
    (void)arg1;
    return 0;
}

M2C_UNK func_ov000_021895bc(M2C_UNK a, M2C_UNK b, M2C_UNK c, M2C_UNK d) { return 0; }

