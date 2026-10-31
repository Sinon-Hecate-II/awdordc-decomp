/* 16 functions from 0x021E8984 to 0x021E997C (ov002), found by ds-decomp. */
#include "common.h"
static inline void *Next021e8e8c(void *head, void *node) {
 if(node==0) { if(M2C_FIELD(head,void **,0)==0)return 0; return head; }
 return M2C_FIELD(node,void **,4);
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_ov002_021e8984(void *arg0) {
    (void)arg0;
}

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

