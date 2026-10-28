/* 3 functions from 0x02190094 to 0x02190F74 (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_unit_entry.h"
typedef struct {
 u16 x:6;
 u16 y:6;
 u16 unk:2;
 u16 state:2;
} Position_021906a0;
typedef struct { u16 low:11; u16 high:5; } Health_021906a0;
typedef struct { u8 a[3]; u8 count; u8 b[2]; } Supply_021906a0;

extern void **gCurrentMap;
void func_01ffc328(void *);
int func_ov000_021a8fc0(int);
int func_ov000_021a8984(int);
int func_ov000_021a995c(void *,int);
int func_ov000_0217c2d4(void *);
void func_ov000_0217c3a4(void);
int func_ov000_0217de64(s16,s16,int,u8,void *);
void func_ov000_02199d74(s16,s16,int,int,int);
#pragma opt_strength_reduction off
void func_ov000_021906a0(int);
extern u8 *data_ov000_021df580;
extern u16 data_ov000_021aeef4[];
void func_01ffc2e8(void *);
s32 func_ov000_02179be0(void);
void func_ov000_0217a59c(s32,s32,s32,s32);
s32 func_ov000_021a9860(s32,s32);
s32 func_020a7694(void *);
void func_ov000_02199f38(void);
void func_ov000_0218a9ac(s32,s32);
s32 func_ov000_021a91d0(s32);
void func_ov000_02190b54(void);
#pragma push
#pragma opt_common_subs off
#pragma scheduling off
void func_ov000_02190094(void) {
u8 *m,*u; s32 best,score,i,cost,y,x,sx,sy,a,b,index,kind,scan;u8 tile;
if((((u32)*(u16 *)(data_ov000_021df580+10)<<26)>>29)&4) {
u=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
if(((UnkStruct_ov000_021A860C *)u)->unkB_4==1) {
func_01ffc2e8(u);m=*gCurrentMap;
scan=data_ov000_021aeef4[*(u16 *)(m+0x52a4)]+1;
if(scan<data_ov000_021aeef4[*(u16 *)(m+0x52a4)]+51){
u=(u8 *)((UnkStruct_ov000_021A860C *)(m+0x59a4)+scan);
do {
kind=((UnkStruct_ov000_021A860C *)u)->unk0;
if(kind){switch(kind){case 24:case 25:if((*(s8 **)((u8 *)*gCurrentMap+0x52e8+u[2]*4))[u[1]]>=0){
((UnkStruct_ov000_021A860C *)*(u8 **)(m+0x52d0))->unkB_4=0;goto scan_done;
}break;default:break;}}scan++;u+=14;}while(scan<data_ov000_021aeef4[*(u16 *)((u8 *)*gCurrentMap+0x52a4)]+51);}}}
scan_done:
u=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
func_ov000_0217a59c(u[1],u[2],((UnkStruct_ov000_021A860C *)u)->unk0,func_ov000_02179be0());
m=*gCurrentMap;u=*(u8 **)(m+0x52d0);
a=((Position_021906a0 *)(u+8))->x;
if(a!=63 && ((UnkStruct_ov000_021A860C *)u)->unk6>=61) {
b=((Position_021906a0 *)(u+8))->y;
if((*(s8 **)(m+0x52e8+b*4))[a]>=0 && func_ov000_021a9860(a,b)){
m=*gCurrentMap;index=*(u16 *)(m+0x3758+b*2)+a;
if(!((Supply_021906a0 *)(m+0x6c60))[*(s8 *)(m+0x1928+index)].count && (!m[index] || (((u32)data_ov000_021df580[7]<<28)>>31))){
cost=func_020a7694(*(u8 **)(m+0x52d0));
if((*(s8 **)((u8 *)*gCurrentMap+0x52e8+b*4))[a]<cost){
func_ov000_02199f38();m=*gCurrentMap;
((Supply_021906a0 *)(m+0x6c60))[*(s8 *)(m+0x1928+(a+*(u16 *)(m+0x3758+b*2)))].count++;
m=*gCurrentMap;
cost=*(s8 *)(m+0x2338+(a+*(u16 *)(m+0x3758+b*2)));
if(cost>2)func_ov000_021906a0(cost);
func_ov000_0218a9ac(a,b);
}}}}
sx=-1;sy=-1;best=32767;score=32767;
((Position_021906a0 *)(*(u8 **)((u8 *)*gCurrentMap+0x52d0)+8))->x=63;
((Position_021906a0 *)(*(u8 **)((u8 *)*gCurrentMap+0x52d0)+8))->y=63;
m=*gCurrentMap;
for(y=0;y<*(u16 *)(m+0x5146);y++){
for(x=0;x<*(u16 *)(m+0x5144);x++,m=*gCurrentMap){
if((*(s8 **)(m+0x52e8+y*4))[x]<0 || !func_ov000_021a9860(x,y))continue;
m=*gCurrentMap;
if(((Supply_021906a0 *)(m+0x6c60))[*(s8 *)(*(u16 *)(m+0x3758+y*2)+(m+x)+0x1928)].count && !(*(u16 *)(data_ov000_021df580+8)&32))continue;
tile=m[0x1420+x+*(u16 *)(m+0x3758+y*2)];cost=2*(*(s8 *)(m+0x2338+x+*(u16 *)(m+0x3758+y*2)));
i=(*(s8 **)(m+0x52e8+y*4))[x];
if(func_ov000_021a91d0(tile&31)==1)cost--;
if(cost>score || (cost==score && best>i))continue;
sx=x;sy=y;best=i;score=cost;
}}
if(best==32767)goto no_candidate;
{
u=*(u8 **)(m+0x52d0);
if(((UnkStruct_ov000_021A860C *)u)->unk6>=61)
((Supply_021906a0 *)(m+0x6c60))[*(s8 *)(m+0x1928+(sx+*(u16 *)(m+0x3758+sy*2)))].count++;
((Position_021906a0 *)(*(u8 **)((u8 *)*gCurrentMap+0x52d0)+8))->x=(u16)sx;
((Position_021906a0 *)(*(u8 **)((u8 *)*gCurrentMap+0x52d0)+8))->y=(u16)sy;
cost=score>>1;
if(cost>2){
u=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
if(((UnkStruct_ov000_021A860C *)u)->unk6>=61 && !(((u32)u[11]<<24)>>31))func_ov000_021906a0(cost);
}
((Position_021906a0 *)(*(u8 **)((u8 *)*gCurrentMap+0x52d0)+8))->state=1;
func_ov000_0218a9ac(sx,sy);
return;}no_candidate:{
u=*(u8 **)(m+0x52d0);
if(((UnkStruct_ov000_021A860C *)u)->unk6<61 || (((u32)u[11]<<24)>>31))return;
func_ov000_02190b54();
((Position_021906a0 *)(*(u8 **)((u8 *)*gCurrentMap+0x52d0)+8))->state=2;
}
}
#pragma pop
void func_ov000_021906a0(int arg) {
 u8 *u;
 int sx=-1,sy=-1,kind=0,x,y;
 u8 *m; u16 pos[2];
 func_01ffc328(*(void **)((u8 *)*gCurrentMap+0x52d0));
 for(y=0;y<*(u16 *)((u8 *)*gCurrentMap+0x5146);y++){
 for(x=0;x<*(u16 *)((u8 *)*gCurrentMap+0x5144);x++){
 m=*gCurrentMap;
 if((*(s8 **)(m+0x52e8+y*4))[x]<0)continue;
 if(!m[x+*(u16 *)(m+0x3758+y*2)])continue;
 if(!func_ov000_021a8fc0(m[x+*(u16 *)(m+0x3758+y*2)+0x508]))continue;
 m=*gCurrentMap;u=m+0x59a4+14*m[x+*(u16 *)(m+0x3758+y*2)];
 if(func_ov000_021a8984(((UnkStruct_ov000_021A860C *)u)->unkB))continue;
 if(!func_ov000_021a995c(u,((UnkStruct_ov000_021A860C *)*(void **)((u8 *)*gCurrentMap+0x52d0))->unk0))continue;
 if(((Health_021906a0 *)(u+6))->high!=0)continue;
 switch(kind){
 case 25:
 if((((UnkStruct_ov000_021A860C *)u)->unk0)==24)continue;
 case 24:
 if((((UnkStruct_ov000_021A860C *)*(void **)((u8 *)*gCurrentMap+0x52d0))->unkB_4)==1)continue;
 if((((UnkStruct_ov000_021A860C *)u)->unk0)==13)continue;
 case 0: case 13:
 if((((UnkStruct_ov000_021A860C *)*(void **)((u8 *)*gCurrentMap+0x52d0))->unkB_4)==1 || arg<=4) {
 if( ((((UnkStruct_ov000_021A860C *)u)->unk0)==24 || (((UnkStruct_ov000_021A860C *)u)->unk0)==25))continue;
 }
 sx=x;sy=y;kind=((UnkStruct_ov000_021A860C *)u)->unk0;break;
 case 19:break;
 default:break;
 }
 }}
 if(sx==-1)return;
 m=*gCurrentMap;
 if(kind==13 && !func_ov000_0217c2d4(m+0x59a4+14*m[sx+*(u16 *)(m+0x3758+sy*2)]))return;
 if(kind==24||kind==25){
 int a; s16 b; m=*gCurrentMap;u=*(u8 **)(m+0x52d0);a=((Position_021906a0 *)(u+8))->x;
 if(a!=63){
 b=*(s8 *)(m+0x1928+(a+*(u16 *)(m+0x3758+((Position_021906a0 *)(u+8))->y*2)));
 if((m+b*6)[0x6c63])((Supply_021906a0 *)(m+0x6c60))[b].count--;
 }
 m=*gCurrentMap;u=m+0x59a4+14*m[sx+*(u16 *)(m+0x3758+sy*2)];
 ((Position_021906a0 *)(u+8))->x=(u16)sx;
 ((Position_021906a0 *)(u+8))->y=(u16)sy;
 }
 u=*(u8 **)((u8 *)*gCurrentMap+0x52d0);
 ((Position_021906a0 *)(u+8))->state=0;
 func_ov000_0217c3a4();
 if(kind==19){
 m=*gCurrentMap;
 if(func_ov000_0217de64((s16)sx,(s16)sy,19,(u8)((*(u16 *)(m+0x59a8+14*m[sx+*(u16 *)(m+0x3758+sy*2)])&1)!=0),pos)==1){
 u=*(u8 **)((u8 *)*gCurrentMap+0x52d0);*(u16 *)(u+8)=(*(u16 *)(u+8)&~63)|(pos[0]&63);
 u=*(u8 **)((u8 *)*gCurrentMap+0x52d0);*(u16 *)(u+8)=(*(u16 *)(u+8)&~0xfc0)|((pos[1]&63)<<6);
 u=*(u8 **)((u8 *)*gCurrentMap+0x52d0);u[11]=(u[11]&~15)|2;
 }}
 func_ov000_02199d74((s16)sx,(s16)sy,7,0,0);
}
void func_ov000_02190b54(void) {
}
