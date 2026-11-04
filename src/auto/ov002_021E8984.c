/* 16 functions from 0x021E8984 to 0x021E997C (ov002), found by ds-decomp. */
#include "common.h"
static inline void Translate021e9014(s32 x,s32 y,s32 z) {
 volatile s32 *p=(volatile s32 *)0x4000444;
 p[11]=x;p[11]=y;p[11]=z;
}
static inline void CopyView021e8984(u16 **engine,s32 destination,s32 source) {
 u16 value=M2C_FIELD(*engine,volatile u16 *,source);
 M2C_FIELD(*engine,volatile u16 *,destination)=value;
}
static inline void *Next021e8e8c(void *head, void *node) {
 if(node==0) { if(M2C_FIELD(head,void **,0)==0)return 0; return head; }
 return M2C_FIELD(node,void **,4);
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma scheduling off
void func_ov002_021e8984(void *arg0){
s32 func_ov002_021e79ac(void *);s32 func_0207ca38(s32,s32,s32,s32,s32);void func_02087048(s32,s32);void func_02087064(s32,s32,s32,s32,s32);void func_02087b94(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);void func_ov002_021e9014(void *);void func_ov002_021e4b94(void *);
extern u16 **gCur3DSpriteEngine;extern u8 data_ov002_021f30f8[],data_ov002_021f30e4[],data_ov002_021f3043[],data_ov002_021f303c[];
s32 j,x,y,alpha,t,i,depth;u8 used,best;void *p;volatile s32 *matrix=(volatile s32 *)0x4000444;
x=M2C_FIELD(arg0,s16 *,0x1e)+M2C_FIELD(arg0,s16 *,0x22);y=M2C_FIELD(arg0,s16 *,0x24);
if(x||y){matrix[0]=0;if(!M2C_FIELD(arg0,u8 *,0x27)){Translate021e9014(x,y,0);}else{Translate021e9014(-x,y,0);}}
if(!M2C_FIELD(arg0,u8 *,0x27)){
M2C_FIELD(*gCur3DSpriteEngine,volatile s16 *,0x3e)=-(x+M2C_FIELD(arg0,s16 *,0x20));
{void *engine=gCur3DSpriteEngine; u16 value=M2C_FIELD(M2C_FIELD(engine,void **,0),volatile u16 *,0x3e);M2C_FIELD(M2C_FIELD(engine,void **,0),volatile u16 *,0x3c)=value;}
}else{
M2C_FIELD(*gCur3DSpriteEngine,volatile s16 *,0x3e)=x+M2C_FIELD(arg0,s16 *,0x20);
{void *engine=gCur3DSpriteEngine; u16 value=M2C_FIELD(M2C_FIELD(engine,void **,0),volatile u16 *,0x3e);M2C_FIELD(M2C_FIELD(engine,void **,0),volatile u16 *,0x3c)=value;}
}
M2C_FIELD(*gCur3DSpriteEngine,volatile s16 *,0x46)=y;
{void *engine=gCur3DSpriteEngine; u16 value=M2C_FIELD(M2C_FIELD(engine,void **,0),volatile u16 *,0x46);M2C_FIELD(M2C_FIELD(engine,void **,0),volatile u16 *,0x44)=value;}
if(M2C_FIELD(M2C_FIELD(data_ov002_021f30f8,void **,(s16)M2C_FIELD(arg0,u8 *,0x27)*24),s32 *,16)!=0&&!func_ov002_021e79ac(data_ov002_021f30e4)){
t=M2C_FIELD(arg0,u8 *,0x29)&127;
if(t<32)alpha=0;else if(t<64)alpha=(s16)func_0207ca38(0,0,31,t-32,32);else if(t<96)alpha=31;else alpha=(s16)func_0207ca38(0,31,0,t-96,32);
if(alpha){func_02087048(31,alpha&255);
t=(s16)M2C_FIELD(arg0,u8 *,0x27)*100;
func_02087064(3,256,128,M2C_FIELD(data_ov002_021f303c,u16 *,t),data_ov002_021f3043[t]);
func_02087b94(0,120,100,256,72,0,0,256,72,M2C_FIELD(arg0,u8 *,0x27)!=0,0);
}
func_02087048(0,31);
}
matrix[0]=0;Translate021e9014(128,0,0);
t=(s32)(M2C_FIELD(arg0,u16 *,0x1c)<<12)>>8;matrix[10]=t;matrix[10]=t;matrix[10]=4096;
used=0;j=0;
do{depth=-32767;best=255;i=0;do{p=M2C_FIELD((u8 *)arg0+i*4,void **,8);if(p&&!(used&(1<<i))){if(depth<=M2C_FIELD(p,s16 *,0x70)){depth=M2C_FIELD(p,s16 *,0x70);best=i;}}i++;}while(i<5);
if(best==255)break;
func_ov002_021e9014(M2C_FIELD((u8 *)arg0+best*4,void **,8));used|=1<<best;j++;
}while(j<5);
*(volatile s32 *)0x4000448=1;if(x||y)*(volatile s32 *)0x4000448=1;
func_ov002_021e4b94(arg0);
}
#pragma scheduling on
void func_ov002_021e8ca4(void *arg0) {
void func_020e35cc(void *);
void func_ov002_021e9318(void *);
s32 i=0;
do {
if(M2C_FIELD((u32)arg0+(i<<2),void **,8)!=0) {
func_ov002_021e9318(M2C_FIELD((u32)arg0+(i<<2),void **,8));
if(M2C_FIELD((u32)arg0+(i<<2),void **,8)!=0) {
func_020e35cc(M2C_FIELD((u32)arg0+(i<<2),void **,8));
M2C_FIELD((u32)arg0+(i<<2),void **,8)=0;
}
}
i++;
}while(i<5);
func_020af9cc(M2C_FIELD(arg0,u8 *,0x27),0,1);
}
#pragma pop
void func_ov002_021e8d04(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x1C) = arg1;
}

void func_ov002_021e8d0c(void *arg0, s8 arg1, s8 arg2) {
    M2C_UNK func_ov002_021e16bc();
    M2C_UNK func_ov002_021e26d4(void *);
    func_ov002_021e16bc();
    func_ov002_021e26d4(arg0);
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = 0;
    M2C_FIELD(arg0, s16 *, 0x70) = 0;
    M2C_FIELD(arg0, s16 *, 0x72) = 0x100;
    M2C_FIELD(arg0, s32 *, 0x74) = 0;
    M2C_FIELD(arg0, s32 *, 0x78) = 0;
    M2C_FIELD(arg0, s16 *, 0x88) = 0;
    M2C_FIELD(arg0, s16 *, 0x8A) = 0;
    M2C_FIELD(arg0, s16 *, 0x7C) = 0;
    M2C_FIELD(arg0, s16 *, 0x7E) = 0;
    M2C_FIELD(arg0, s32 *, 0x80) = (s32) (arg2 * 0x10);
    M2C_FIELD(arg0, s32 *, 0x84) = 0;
    M2C_FIELD(arg0, s8 *, 0x8C) = arg1;
    M2C_FIELD(arg0, s8 *, 0x8D) = arg2;
}

s32 func_ov002_021e8d70(s32 a,s32 b){
if(a){switch(b){
case 0x6f:case 0x70:case 0x72:case 0x75:case 0x79:case 0x7f:return 1;
case 0xef:case 0xf0:case 0xf2:case 0xf5:case 0xf9:case 0xff:return -1;
}}
else{switch(b){case 0x59:case 0x5b:case 0x5f:return 1;case 0xb9:case 0xbb:case 0xbf:return -1;}}
return 0;}

s32 func_ov002_021e8e7c(s32 arg0) {
    if (arg0 != 0) {
        return 0x100;
    }
    return 0xC0;
}

/* Advance one unit's animation: tick its child lists, accumulate position deltas, and step its frame. */
void func_ov002_021e8e8c(void *unit){
void func_ov002_021e1844(void *);void func_ov002_021e2aa8(void *);void func_ov002_021e3e64(void *);
extern u8 data_ov002_021f30f4[],data_ov002_021f314e[];
void *node;
func_ov002_021e1844(unit);
node=0;
while((node=Next021e8e8c(unit+0x54,node))!=0){func_ov002_021e1844(M2C_FIELD(node,void **,0));}
node=0;
while((node=Next021e8e8c(unit+0x5c,node))!=0){func_ov002_021e2aa8(M2C_FIELD(node,void **,0));}
node=0;
while((node=Next021e8e8c(unit+0x64,node))!=0){func_ov002_021e3e64(M2C_FIELD(node,void **,0));}
M2C_FIELD(unit,s32 *,0x74)+=M2C_FIELD(unit,s16 *,0x88);
M2C_FIELD(unit,s32 *,0x78)+=M2C_FIELD(unit,s16 *,0x8a);
if(M2C_FIELD(M2C_FIELD(data_ov002_021f30f4,void **,M2C_FIELD(unit,u8 *,0x8c)*24),u8 *,0x3d)==2){
M2C_FIELD(unit,s32 *,0x80)++;
M2C_FIELD(unit,s16 *,0x7e)+=func_ov002_021e8d70(data_ov002_021f314e[M2C_FIELD(unit,u8 *,0x8c)*44],M2C_FIELD(unit,s32 *,0x80));
if(M2C_FIELD(unit,s32 *,0x80)==func_ov002_021e8e7c(data_ov002_021f314e[M2C_FIELD(unit,u8 *,0x8c)*44]))M2C_FIELD(unit,s32 *,0x80)=0;
}}

void func_ov002_021e8ff0(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s16 *, 0x6C) = arg1;
    M2C_FIELD(arg0, s16 *, 0x6E) = arg2;
    M2C_FIELD(arg0, s16 *, 0x70) = arg3;
}

void func_ov002_021e9000(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x72) = arg1;
}

void func_ov002_021e9008(void *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x88) = arg1;
    M2C_FIELD(arg0, s16 *, 0x8A) = arg2;
}

void func_ov002_021e9014(void *unit){
void func_ov002_021e1ef8(void *,s32);void func_ov002_021e2cf0(void *);void func_ov002_021e3e7c(void *);
void *node,*obj;s32 x,z,y,scale;volatile u32 *matrix=(volatile u32 *)0x4000444;
matrix[0]=0;
if(!M2C_FIELD(unit,u8 *,0x8c)){
Translate021e9014(-M2C_FIELD(unit,s16 *,0x6c),M2C_FIELD(unit,s16 *,0x6e),M2C_FIELD(unit,s16 *,0x70));
}else{Translate021e9014(M2C_FIELD(unit,s16 *,0x6c),M2C_FIELD(unit,s16 *,0x6e),M2C_FIELD(unit,s16 *,0x70));}
scale=(s32)(M2C_FIELD(unit,u16 *,0x72)<<12)>>8;
*(volatile s32 *)0x400046c=scale;*(volatile s32 *)0x400046c=scale;*(volatile s32 *)0x400046c=0x1000;
if(M2C_FIELD(unit,s32 *,0x74)||M2C_FIELD(unit,s32 *,0x78)){
matrix[0]=0;
if(!M2C_FIELD(unit,u8 *,0x8c)){Translate021e9014(-(M2C_FIELD(unit,s32 *,0x74)>>8),M2C_FIELD(unit,s32 *,0x78)>>8,0);}else{Translate021e9014(M2C_FIELD(unit,s32 *,0x74)>>8,M2C_FIELD(unit,s32 *,0x78)>>8,0);}
}
if(M2C_FIELD(unit,s16 *,0x7c)||M2C_FIELD(unit,s16 *,0x7e)){
matrix[0]=0;
if(!M2C_FIELD(unit,u8 *,0x8c)){x=-M2C_FIELD(unit,s16 *,0x7c);y=M2C_FIELD(unit,s16 *,0x7e);matrix[11]=x;matrix[11]=y;matrix[11]=0;}
else{x=M2C_FIELD(unit,s16 *,0x7c);y=M2C_FIELD(unit,s16 *,0x7e);matrix[11]=x;matrix[11]=y;matrix[11]=0;}
}
func_ov002_021e1ef8(unit,0);
node=0;while((node=Next021e8e8c(unit+0x54,node))!=0){obj=M2C_FIELD(node,void **,0);if(M2C_FIELD(obj,u8 *,0x4a))func_ov002_021e1ef8(obj,0);}
node=0;while((node=Next021e8e8c(unit+0x5c,node))!=0){obj=M2C_FIELD(node,void **,0);if(M2C_FIELD(obj,u8 *,0x4a))func_ov002_021e2cf0(obj);}
node=0;while((node=Next021e8e8c(unit+0x64,node))!=0)func_ov002_021e3e7c(M2C_FIELD(node,void **,0));
if(M2C_FIELD(unit,s16 *,0x7c)||M2C_FIELD(unit,s16 *,0x7e))*(volatile u32 *)0x4000448=1;
if(M2C_FIELD(unit,s32 *,0x74)||M2C_FIELD(unit,s32 *,0x78))*(volatile u32 *)0x4000448=1;
node=0;while((node=Next021e8e8c(unit+0x54,node))!=0){obj=M2C_FIELD(node,void **,0);if(!M2C_FIELD(obj,u8 *,0x4a))func_ov002_021e1ef8(obj,0);}
node=0;while((node=Next021e8e8c(unit+0x5c,node))!=0){obj=M2C_FIELD(node,void **,0);if(!M2C_FIELD(obj,u8 *,0x4a))func_ov002_021e2cf0(obj);}
*(volatile u32 *)0x4000448=1;
}

void func_ov002_021e9318(void *x) {
void func_ov002_021e25e0(void *,void *); void func_ov002_021e95f0(void *,void *); void func_ov002_021e96e4(void *,void *);
void func_ov002_021e24e8(void *); void func_ov002_021e3f28(void *); void func_020e35cc(void *);
void *right,*next;
right=M2C_FIELD(x,void **,88);if(right!=0){next=M2C_FIELD(right,void **,4);if(next!=0){if(M2C_FIELD(next,void **,4)!=0)func_ov002_021e25e0((u8*)x+84,M2C_FIELD(next,void **,4));
if(M2C_FIELD(next,void **,0)!=0)func_ov002_021e24e8(M2C_FIELD(next,void **,0));
if(M2C_FIELD(next,void **,0)!=0){func_020e35cc(M2C_FIELD(next,void **,0));M2C_FIELD(next,void **,0)=0;}
if(M2C_FIELD(next,void **,4)!=0){func_020e35cc(M2C_FIELD(next,void **,4));M2C_FIELD(next,void **,4)=0;}
}
if(M2C_FIELD(right,void **,0)!=0)func_ov002_021e24e8(M2C_FIELD(right,void **,0));
if(M2C_FIELD(right,void **,0)!=0){func_020e35cc(M2C_FIELD(right,void **,0));M2C_FIELD(right,void **,0)=0;}
if(M2C_FIELD(right,void **,4)!=0){func_020e35cc(M2C_FIELD(right,void **,4));M2C_FIELD(right,void **,4)=0;}
}
if(M2C_FIELD(x,void **,84)!=0)func_ov002_021e24e8(M2C_FIELD(x,void **,84));
if(M2C_FIELD(x,void **,84)!=0){func_020e35cc(M2C_FIELD(x,void **,84));M2C_FIELD(x,void **,84)=0;}
if(M2C_FIELD(x,void **,88)!=0){func_020e35cc(M2C_FIELD(x,void **,88));M2C_FIELD(x,void **,88)=0;}
right=M2C_FIELD(x,void **,96);if(right!=0){next=M2C_FIELD(right,void **,4);if(next!=0){if(M2C_FIELD(next,void **,4)!=0)func_ov002_021e95f0((u8*)x+92,M2C_FIELD(next,void **,4));
if(M2C_FIELD(next,void **,0)!=0)func_ov002_021e24e8(M2C_FIELD(next,void **,0));
if(M2C_FIELD(next,void **,0)!=0){func_020e35cc(M2C_FIELD(next,void **,0));M2C_FIELD(next,void **,0)=0;}
if(M2C_FIELD(next,void **,4)!=0){func_020e35cc(M2C_FIELD(next,void **,4));M2C_FIELD(next,void **,4)=0;}
}
if(M2C_FIELD(right,void **,0)!=0)func_ov002_021e24e8(M2C_FIELD(right,void **,0));
if(M2C_FIELD(right,void **,0)!=0){func_020e35cc(M2C_FIELD(right,void **,0));M2C_FIELD(right,void **,0)=0;}
if(M2C_FIELD(right,void **,4)!=0){func_020e35cc(M2C_FIELD(right,void **,4));M2C_FIELD(right,void **,4)=0;}
}
if(M2C_FIELD(x,void **,92)!=0)func_ov002_021e24e8(M2C_FIELD(x,void **,92));
if(M2C_FIELD(x,void **,92)!=0){func_020e35cc(M2C_FIELD(x,void **,92));M2C_FIELD(x,void **,92)=0;}
if(M2C_FIELD(x,void **,96)!=0){func_020e35cc(M2C_FIELD(x,void **,96));M2C_FIELD(x,void **,96)=0;}
right=M2C_FIELD(x,void **,104);if(right!=0){next=M2C_FIELD(right,void **,4);if(next!=0){if(M2C_FIELD(next,void **,4)!=0)func_ov002_021e96e4((u8*)x+100,M2C_FIELD(next,void **,4));
if(M2C_FIELD(next,void **,0)!=0)func_ov002_021e3f28(M2C_FIELD(next,void **,0));
if(M2C_FIELD(next,void **,0)!=0){func_020e35cc(M2C_FIELD(next,void **,0));M2C_FIELD(next,void **,0)=0;}
if(M2C_FIELD(next,void **,4)!=0){func_020e35cc(M2C_FIELD(next,void **,4));M2C_FIELD(next,void **,4)=0;}
}
if(M2C_FIELD(right,void **,0)!=0)func_ov002_021e3f28(M2C_FIELD(right,void **,0));
if(M2C_FIELD(right,void **,0)!=0){func_020e35cc(M2C_FIELD(right,void **,0));M2C_FIELD(right,void **,0)=0;}
if(M2C_FIELD(right,void **,4)!=0){func_020e35cc(M2C_FIELD(right,void **,4));M2C_FIELD(right,void **,4)=0;}
}
if(M2C_FIELD(x,void **,100)!=0)func_ov002_021e3f28(M2C_FIELD(x,void **,100));
if(M2C_FIELD(x,void **,100)!=0){func_020e35cc(M2C_FIELD(x,void **,100));M2C_FIELD(x,void **,100)=0;}
if(M2C_FIELD(x,void **,104)!=0){func_020e35cc(M2C_FIELD(x,void **,104));M2C_FIELD(x,void **,104)=0;}
func_ov002_021e24e8(x);
}

/* Recursively tear down a node's right chain, cleaning up its left children. */
void func_ov002_021e95f0(void *owner, void *node) {
void func_ov002_021e24e8(void *);
void func_020e35cc(void *);
void *right;
void *rightRight;
right = M2C_FIELD(node, void **, 4);
if (right != NULL) {
rightRight = M2C_FIELD(right, void **, 4);
if (rightRight != NULL) {
if (M2C_FIELD(rightRight, void **, 4) != NULL) func_ov002_021e95f0(owner, M2C_FIELD(rightRight, void **, 4));
if (M2C_FIELD(rightRight, void **, 0) != NULL) func_ov002_021e24e8(M2C_FIELD(rightRight, void **, 0));
if (M2C_FIELD(rightRight, void **, 0) != NULL) { func_020e35cc(M2C_FIELD(rightRight, void **, 0)); M2C_FIELD(rightRight, void **, 0) = NULL; }
if (M2C_FIELD(rightRight, void **, 4) != NULL) { func_020e35cc(M2C_FIELD(rightRight, void **, 4)); M2C_FIELD(rightRight, void **, 4) = NULL; }
}
if (M2C_FIELD(right, void **, 0) != NULL) func_ov002_021e24e8(M2C_FIELD(right, void **, 0));
if (M2C_FIELD(right, void **, 0) != NULL) { func_020e35cc(M2C_FIELD(right, void **, 0)); M2C_FIELD(right, void **, 0) = NULL; }
if (M2C_FIELD(right, void **, 4) != NULL) { func_020e35cc(M2C_FIELD(right, void **, 4)); M2C_FIELD(right, void **, 4) = NULL; }
}
if (M2C_FIELD(node, void **, 0) != NULL) func_ov002_021e24e8(M2C_FIELD(node, void **, 0));
if (M2C_FIELD(node, void **, 0) != NULL) { func_020e35cc(M2C_FIELD(node, void **, 0)); M2C_FIELD(node, void **, 0) = NULL; }
if (M2C_FIELD(node, void **, 4) != NULL) { func_020e35cc(M2C_FIELD(node, void **, 4)); M2C_FIELD(node, void **, 4) = NULL; }
}

/* Recursively tear down a node's right chain, cleaning its left children via the no-op sibling handler. */
void func_ov002_021e96e4(void *owner, void *node) {
void func_ov002_021e3f28(void *);
void func_020e35cc(void *);
void *right;
void *rightRight;
right = M2C_FIELD(node, void **, 4);
if (right != NULL) {
rightRight = M2C_FIELD(right, void **, 4);
if (rightRight != NULL) {
if (M2C_FIELD(rightRight, void **, 4) != NULL) func_ov002_021e96e4(owner, M2C_FIELD(rightRight, void **, 4));
if (M2C_FIELD(rightRight, void **, 0) != NULL) func_ov002_021e3f28(M2C_FIELD(rightRight, void **, 0));
if (M2C_FIELD(rightRight, void **, 0) != NULL) { func_020e35cc(M2C_FIELD(rightRight, void **, 0)); M2C_FIELD(rightRight, void **, 0) = NULL; }
if (M2C_FIELD(rightRight, void **, 4) != NULL) { func_020e35cc(M2C_FIELD(rightRight, void **, 4)); M2C_FIELD(rightRight, void **, 4) = NULL; }
}
if (M2C_FIELD(right, void **, 0) != NULL) func_ov002_021e3f28(M2C_FIELD(right, void **, 0));
if (M2C_FIELD(right, void **, 0) != NULL) { func_020e35cc(M2C_FIELD(right, void **, 0)); M2C_FIELD(right, void **, 0) = NULL; }
if (M2C_FIELD(right, void **, 4) != NULL) { func_020e35cc(M2C_FIELD(right, void **, 4)); M2C_FIELD(right, void **, 4) = NULL; }
}
if (M2C_FIELD(node, void **, 0) != NULL) func_ov002_021e3f28(M2C_FIELD(node, void **, 0));
if (M2C_FIELD(node, void **, 0) != NULL) { func_020e35cc(M2C_FIELD(node, void **, 0)); M2C_FIELD(node, void **, 0) = NULL; }
if (M2C_FIELD(node, void **, 4) != NULL) { func_020e35cc(M2C_FIELD(node, void **, 4)); M2C_FIELD(node, void **, 4) = NULL; }
}

/* Update a unit's animation/movement state. mode 0 picks the idle/frame slot from
   the animation table, mode 1 applies a movement value (or -1), mode 2 starts
   an attack/movement action and updates the unit's travel speed. */
void func_ov002_021e97d8(void *unit, s32 mode, s32 value, s32 flag) {
void func_ov002_021e173c(void *, u8);
void func_ov002_021e9e0c(void *, s32);
void func_ov002_021ea208(void *, s32);
void func_ov002_021ea37c(void *);
void func_ov002_021ea4bc(void *, s16, s16);
extern u8 data_ov002_021f30f4[], data_ov002_021f3103[], data_ov002_021f314e[];
s32 off;
switch (mode) {
case 0:
off = M2C_FIELD(unit, u8 *, 0x8c) * 24;
if (data_ov002_021f3103[off] == 0) { func_ov002_021e173c(unit, M2C_FIELD(M2C_FIELD(data_ov002_021f30f4, void **, off), u8 *, 0x39)); return; }
func_ov002_021e173c(unit, M2C_FIELD(M2C_FIELD(data_ov002_021f30f4, void **, off), u8 *, 0x3a)); return;
case 1:
if (flag == 0) { func_ov002_021e9e0c(unit, value); return; }
func_ov002_021e9e0c(unit, -1); return;
case 2:
if (flag == 0) { func_ov002_021ea208(unit, value); return; }
func_ov002_021e173c(unit, M2C_FIELD(M2C_FIELD(data_ov002_021f30f4, void **, M2C_FIELD(unit, u8 *, 0x8c) * 24), u8 *, 0x3b));
if (data_ov002_021f314e[M2C_FIELD(unit, u8 *, 0x8c) * 44]) func_ov002_021ea37c(unit); else func_ov002_021ea208(unit, -1);
if (M2C_FIELD(M2C_FIELD(data_ov002_021f30f4, void **, M2C_FIELD(unit, u8 *, 0x8c) * 24), u8 *, 0x3d) == 0) func_ov002_021e9008(unit, 0x800, -0x800); else func_ov002_021ea4bc(unit, 0, 0);
if (M2C_FIELD(M2C_FIELD(data_ov002_021f30f4, void **, M2C_FIELD(unit, u8 *, 0x8c) * 24), u8 *, 0x3d) != 2) return;
func_ov002_021e9008(unit, 0x200, 0x100); M2C_FIELD(unit, s32 *, 0x80) = -1; return;
}
}

void func_ov002_021e994c(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3, s8 arg4) {
    M2C_UNK func_ov002_021e9f80(M2C_UNK, M2C_UNK, M2C_UNK);
    if (arg2 != 1) {
        return;
    }
    if (arg4 == 0) {
        func_ov002_021e9f80(arg0, arg1, arg3);
        return;
    }
    func_ov002_021e9f80(arg0, arg1, -1);
}

