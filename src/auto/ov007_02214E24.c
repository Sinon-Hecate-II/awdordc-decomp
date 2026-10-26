/* 12 functions from 0x02214E24 to 0x02215DD8 (ov007), found by ds-decomp. */
#include "common.h"
extern s32 *data_027e0058;
extern u8 data_ov007_02221a84[800];

void func_ov007_02214e24(void) {
s32 x,y; s32 *p; u8 *row;
p=data_027e0058;
y=0;
if(M2C_FIELD(*p,u16 *,0x5146)<=y)return;
row=data_ov007_02221a84;
do {

for(x=0;x<M2C_FIELD(*p,u16 *,0x5144);x++){
row[x]=0;
if(x==0)row[x]=1;
if(y==0)row[x]=1;
if(x==M2C_FIELD(*p,u16 *,0x5144)-1)row[x]=1;
if(y==M2C_FIELD(*p,u16 *,0x5146)-1)row[x]=1;
}
y++; row+=30;
}while(y<M2C_FIELD(*p,u16 *,0x5146));
}

/* Mark each unit standing on a tile of the tactical map (value 2 in the
   30-wide unit grid data_ov007_02221a84) as "moved" (1) and clear value 2
   from its four orthogonal neighbours; returns 1 if any unit was found. */
s32 Map_MarkUnitsMoved(void){
s32 x,y,found=0; s32 *p=data_027e0058; s8 *row;
y=0;
if(y<M2C_FIELD(*p,u16 *,0x5146)){
row=(s8*)data_ov007_02221a84;
do{
for(x=0;x<M2C_FIELD(*p,u16 *,0x5144);x++){
if(row[x]==2){
if(x-1>=0)row[x-1]=0;
if(y-1>=0)row[x-30]=0;
if(x+1<M2C_FIELD(*p,u16 *,0x5144))row[x+1]=0;
if(y+1<M2C_FIELD(*p,u16 *,0x5146))row[x+30]=0;
found=1;row[x]=1;
}
}
y++;row+=30;
}while(y<M2C_FIELD(*p,u16 *,0x5146));
}return found!=0;
}

void func_ov007_02215254(s32 arg0, s32 arg1, s16 arg2) {
    s8 func_0207efb4(s16);
    extern s32 *data_027e0058;
    s32 temp_ip;
    s32 temp_r6;

    temp_ip = *data_027e0058;
    M2C_FIELD((temp_ip + ((arg0 + M2C_FIELD((temp_ip + (arg1 * 2)), u16 *, 0x3758)) * 2)), s16 *, 0xA10) = arg2;
    temp_r6 = *data_027e0058;
    M2C_FIELD((temp_r6 + (arg0 + M2C_FIELD((temp_r6 + (arg1 * 2)), u16 *, 0x3758))), s8 *, 0x1420) = func_0207efb4(arg2);
}

s32 func_ov007_022156a4(s32 x,s32 y) {
 s32 func_ov007_0221b754(s32,s32);
 s32 i,j;
 for(j=y-1;j<=y+1;j++)
 for(i=x-1;i<=x+1;i++)
 if(!func_ov007_0221b754(i,j)) return 0;
 return 1;
}

s32 func_ov007_02215704(s32 x,s32 y){
s32 func_ov007_0221b754(s32,s32);
if(func_ov007_0221b754(x-1,y)==1 && ((s8*)data_ov007_02221a84+y*30)[x-1]!=2 &&
func_ov007_0221b754(x+1,y)==1 && ((s8*)data_ov007_02221a84+y*30)[x+1]!=2){
func_ov007_02215254(x,y,36);return 1;
}
if(func_ov007_0221b754(x,y-1)==1 && ((s8*)data_ov007_02221a84+(y-1)*30)[x]!=2 &&
func_ov007_0221b754(x,y+1)==1 && ((s8*)data_ov007_02221a84+(y+1)*30)[x]!=2){
func_ov007_02215254(x,y,36);return 1;
}return 0;
}

s32 func_ov007_02215bc4(s32 *x,s32 *y,s32 value) {
 s32 func_0207c330(s32,s32);
 extern s32 *data_027e0058;
 s32 n=0;
 s32 a=0,b=0;
 do {
 if(++n>100) return 0;
 *x=func_0207c330(a,M2C_FIELD(*data_027e0058,u16 *,0x5144)-1);
 *y=func_0207c330(b,M2C_FIELD(*data_027e0058,u16 *,0x5146)-1);
 } while(value!=M2C_FIELD((*data_027e0058+((*x+M2C_FIELD((*data_027e0058+(*y*2)),u16 *,0x3758))*2)),u16 *,0xA10));
 return 1;
}

