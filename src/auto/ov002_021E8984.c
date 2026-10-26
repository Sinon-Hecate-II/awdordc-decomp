/* 16 functions from 0x021E8984 to 0x021E997C (ov002), found by ds-decomp. */
#include "common.h"

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
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

s32 func_ov002_021e8e7c(s32 arg0) {
    if (arg0 != 0) {
        return 0x100;
    }
    return 0xC0;
}

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

