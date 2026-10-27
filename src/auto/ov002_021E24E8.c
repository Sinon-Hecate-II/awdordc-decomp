/* 29 functions from 0x021E24E8 to 0x021E3210 (ov002), found by ds-decomp. */
#include "common.h"
typedef struct SlotEntry { s16 value; u8 index:3; u8 rest:5; u8 pad; } SlotEntry;
static inline void SetSlotIndex(SlotEntry *p, u8 index) { p->index=index; }
extern M2C_UNK data_ov002_021ea704;
static inline void *init_021e2848(void *p) {
M2C_FIELD(p,M2C_UNK **,0)=&data_ov002_021ea704;
M2C_FIELD(p,s32 *,8)=0;
M2C_FIELD(p,s32 *,12)=0;
return p;
}



/* Recursively tear down a node's right/child subtree, freeing every child pointer. */
void func_ov002_021e25e0(void *, void *);
/* Recursively tear down a node's right/child subtree, freeing every child pointer. */
void func_ov002_021e24e8(void *node) {
    void func_020e35cc(void *);
    void *right = M2C_FIELD(node, void **, 12);
    void *rightRight;
    if (right != NULL) {
        rightRight = M2C_FIELD(right, void **, 4);
        if (rightRight != NULL) {
            if (M2C_FIELD(rightRight, void **, 4) != NULL) func_ov002_021e25e0((u8 *)node + 8, M2C_FIELD(rightRight, void **, 4));
            if (M2C_FIELD(rightRight, void **, 0) != NULL) func_ov002_021e24e8(M2C_FIELD(rightRight, void **, 0));
            if (M2C_FIELD(rightRight, void **, 0) != NULL) { func_020e35cc(M2C_FIELD(rightRight, void **, 0)); M2C_FIELD(rightRight, void **, 0) = NULL; }
            if (M2C_FIELD(rightRight, void **, 4) != NULL) { func_020e35cc(M2C_FIELD(rightRight, void **, 4)); M2C_FIELD(rightRight, void **, 4) = NULL; }
        }
        if (M2C_FIELD(right, void **, 0) != NULL) func_ov002_021e24e8(M2C_FIELD(right, void **, 0));
        if (M2C_FIELD(right, void **, 0) != NULL) { func_020e35cc(M2C_FIELD(right, void **, 0)); M2C_FIELD(right, void **, 0) = NULL; }
        if (M2C_FIELD(right, void **, 4) != NULL) { func_020e35cc(M2C_FIELD(right, void **, 4)); M2C_FIELD(right, void **, 4) = NULL; }
    }
    if (M2C_FIELD(node, void **, 8) != NULL) func_ov002_021e24e8(M2C_FIELD(node, void **, 8));
    if (M2C_FIELD(node, void **, 8) != NULL) { func_020e35cc(M2C_FIELD(node, void **, 8)); M2C_FIELD(node, void **, 8) = NULL; }
    if (M2C_FIELD(node, void **, 12) != NULL) { func_020e35cc(M2C_FIELD(node, void **, 12)); M2C_FIELD(node, void **, 12) = NULL; }
}

void func_ov002_021e25e0(void *owner, void *node) {
void func_ov002_021e24e8(void *);
void func_020e35cc(void *);
void *right;
void *rightRight;
right = M2C_FIELD(node, void **, 4);
if (right != NULL) {
rightRight = M2C_FIELD(right, void **, 4);
if (rightRight != NULL) {
if (M2C_FIELD(rightRight, void **, 4) != NULL) func_ov002_021e25e0(owner, M2C_FIELD(rightRight, void **, 4));
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

void func_ov002_021e26d4(void *arg0) {
 void **p=0;
 M2C_FIELD(arg0,s8 *,0x50)=1;
 while((p=p ? M2C_FIELD(p,void ***,4) : (M2C_FIELD(arg0,s32 *,8)==0 ? 0 : (void **)((u8 *)arg0+8)))!=0) {
 func_ov002_021e26d4(*p);
 }
}

void func_ov002_021e2724(void *arg0) {
 void **p=0;
 M2C_FIELD(arg0,s8 *,0x50)=0;
 while((p=p ? M2C_FIELD(p,void ***,4) : (M2C_FIELD(arg0,s32 *,8)==0 ? 0 : (void **)((u8 *)arg0+8)))!=0) {
 func_ov002_021e2724(*p);
 }
}

void func_ov002_021e2770(void *arg0, s8 arg1) {
 void **p=0;
 M2C_FIELD(arg0,s8 *,0x51)=arg1;
 while((p=p ? M2C_FIELD(p,void ***,4) : (M2C_FIELD(arg0,s32 *,8)==0 ? 0 : (void **)((u8 *)arg0+8)))!=0) {
 func_ov002_021e2770(*p,arg1);
 }
}

s32 func_ov002_021e27c4(void *a){s32 sum=0;u8 *p;if(!M2C_FIELD(a,s32 *,4))return sum;p=M2C_FIELD(a,u8 **,0x18);while(p[1]!=255){if(!p[0]){switch(p[1]){case 0:case 2:return sum;case 1:case 6:return 0;case 3:case 4:case 5:default:break;}}else sum+=p[0];p+=12;}return sum;}

void func_ov002_021e2848(void *a,s32 b,s32 c) {
void *func_02082028(M2C_UNK);
M2C_UNK func_ov002_021e16dc(void *,s32,s16,s8,u8);
register void *q;
void *p;
if(M2C_FIELD(a,void **,8)) {
p=func_02082028(8);
if(p) {M2C_FIELD(p,void **,0)=0;M2C_FIELD(p,void **,4)=0;}
M2C_FIELD(p,void **,0)=M2C_FIELD(a,void **,8);
M2C_FIELD(p,void **,4)=M2C_FIELD(a,void **,12);
M2C_FIELD(a,void **,12)=p;
}
M2C_FIELD(a,void **,8)=((p=func_02082028(0x54)) ? init_021e2848(p) : p);
q=M2C_FIELD(a,void **,8);
func_ov002_021e16bc(q,M2C_FIELD(a,u8 *,0x53),M2C_FIELD(a,u8 *,0x47));
func_ov002_021e179c(q,0,0,(s16)c);
((M2C_UNK (*)(void *,s32,u16,u8,s32))func_ov002_021e16dc)(q,M2C_FIELD(a,s32 *,4),M2C_FIELD(a,u16 *,0x38),M2C_FIELD(a,u8 *,0x3a),b);
M2C_FIELD(q,s32 *,0x28)=M2C_FIELD(a,s32 *,0x1c);
M2C_FIELD(q,s32 *,0x2c)=M2C_FIELD(a,s32 *,0x24);
M2C_FIELD(q,u8 *,0x4c)=M2C_FIELD(a,u8 *,0x4b);
M2C_FIELD(q,u8 *,0x50)=M2C_FIELD(a,u8 *,0x50);
M2C_FIELD(q,u8 *,0x51)=M2C_FIELD(a,u8 *,0x51);
}

void func_ov002_021e2928(void *a,s32 b){void func_ov002_021e1780(void *);void **p=0;while((p=p?M2C_FIELD(p,void ***,4):(M2C_FIELD(a,s32 *,8)==0?0:(void **)((u8 *)a+8)))!=0){func_ov002_021e2928(*p,b);if(b==M2C_FIELD(*p,u8 *,0x46))func_ov002_021e1780(*p);}}

void func_ov002_021e298c(void) {

}

void func_ov002_021e2990(void) {

}

s32 func_ov002_021e2994(void) {
    return 0;
}

void func_ov002_021e299c(void *a,s32 b){void func_ov002_021e17b4(s32,s32,s32);extern M2C_UNK data_ov002_021f312c;extern u8 data_ov002_021f3046;s32 n=M2C_FIELD(a,u8 *,0x53);s32 i=M2C_FIELD(a,u8 *,0x47);func_ov002_021e17b4(M2C_FIELD((u8 *)&data_ov002_021f312c+n*44,s32 *,i*4),b,(&data_ov002_021f3046+n*100)[i*8]);}

void func_ov002_021e29d8(void *arg0) {
    M2C_UNK func_ov002_021e88a0(s32);
    extern M2C_UNK data_ov002_021f3124;
    func_ov002_021e88a0((M2C_FIELD(arg0, u8 *, 0x53) * 0x2C) + (s32) &data_ov002_021f3124);
}

void func_ov002_021e29f8(void *arg0,s32 a,s32 b) {
 void func_ov002_021ea4bc(s32,s32,s32);
 extern M2C_UNK data_ov002_021f312c;
 func_ov002_021ea4bc(M2C_FIELD((u8 *)&data_ov002_021f312c+M2C_FIELD(arg0,u8 *,0x53)*44,s32 *,M2C_FIELD(arg0,u8 *,0x47)*4),a,b);
}

void func_ov002_021e2a20(void *arg0) {
    M2C_UNK func_ov002_021e16bc();
    func_ov002_021e16bc();
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
    M2C_FIELD(arg0, s32 *, 0x68) = 0;
    M2C_FIELD(arg0, s16 *, 0x78) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x7A) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x7C) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x7E) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C) = -1;
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    M2C_FIELD(arg0, s32 *, 0x74) = 0;
    M2C_FIELD(arg0, s16 *, 0x80) = 0;
    M2C_FIELD(arg0, s16 *, 0x82) = 0;
    M2C_FIELD(arg0, s16 *, 0x84) = 0x100;
    M2C_FIELD(arg0, s16 *, 0x86) = 0;
}

void func_ov002_021e2a80(void *a,s32 b,s16 c,s8 d,u8 e){M2C_UNK func_ov002_021e16dc(void *,s32,s16,s8,u8);func_ov002_021e16dc(a,b,c,d,e);M2C_FIELD(a,s32 *,0x6c)=0;}

void func_ov002_021e2aa8(void *arg0) {
    s32 func_0207ca38(s32, s32, s32, s32, s32);
    void func_ov002_021e1780(void *);
    void func_ov002_021e1790(void *, s32, s32);
    void func_ov002_021e1844(void *);
    void func_ov002_021e299c(void *, s32);
    s32 func_ov002_021e2e28(void *);
    s32 t;
    if (M2C_FIELD(arg0, s32 *, 0x6C) >= 0) {
        M2C_FIELD(arg0, s32 *, 0x6C) = M2C_FIELD(arg0, s32 *, 0x6C) + 1;
        if (M2C_FIELD(arg0, u16 *, 0x86) == 0) {
            if (M2C_FIELD(arg0, s32 *, 0x6C) > M2C_FIELD(arg0, s32 *, 0x70)) {
                M2C_FIELD(arg0, s32 *, 0x54) = M2C_FIELD(arg0, s32 *, 0x54) + M2C_FIELD(arg0, s32 *, 0x5C);
                M2C_FIELD(arg0, s32 *, 0x58) = M2C_FIELD(arg0, s32 *, 0x58) + M2C_FIELD(arg0, s32 *, 0x60);
                M2C_FIELD(arg0, s32 *, 0x5C) = M2C_FIELD(arg0, s32 *, 0x5C) + M2C_FIELD(arg0, s32 *, 0x64);
                M2C_FIELD(arg0, s32 *, 0x60) = M2C_FIELD(arg0, s32 *, 0x60) + M2C_FIELD(arg0, s32 *, 0x68);
                t = (s32)M2C_FIELD(arg0, s16 *, 0x7E) + (s32)M2C_FIELD(arg0, u16 *, 0x78);
                if (t < 0) t = 0;
                M2C_FIELD(arg0, u16 *, 0x78) = (u16)t;
                func_ov002_021e1790(arg0, (s32)(M2C_FIELD(arg0, s32 *, 0x54) << 8) >> 16, (s32)(M2C_FIELD(arg0, s32 *, 0x58) << 8) >> 16);
                if (func_ov002_021e2e28(arg0) != 0) {
                    func_ov002_021e1780(arg0);
                    M2C_FIELD(arg0, s32 *, 0x6C) = -1;
                }
            } else {
                M2C_FIELD(arg0, u16 *, 0x78) = (u16)func_0207ca38(0, M2C_FIELD(arg0, s16 *, 0x7A), M2C_FIELD(arg0, s16 *, 0x7C), M2C_FIELD(arg0, s32 *, 0x6C), M2C_FIELD(arg0, s32 *, 0x70));
            }
        } else {
            M2C_FIELD(arg0, s32 *, 0x54) = M2C_FIELD(arg0, s32 *, 0x54) + M2C_FIELD(arg0, s32 *, 0x5C);
            M2C_FIELD(arg0, s32 *, 0x58) = M2C_FIELD(arg0, s32 *, 0x58) + M2C_FIELD(arg0, s32 *, 0x60);
            M2C_FIELD(arg0, s32 *, 0x5C) = M2C_FIELD(arg0, s32 *, 0x5C) + M2C_FIELD(arg0, s32 *, 0x64);
            M2C_FIELD(arg0, s32 *, 0x60) = M2C_FIELD(arg0, s32 *, 0x60) + M2C_FIELD(arg0, s32 *, 0x68);
            t = (s32)M2C_FIELD(arg0, s16 *, 0x7E) + (s32)M2C_FIELD(arg0, u16 *, 0x78);
            if (t < 0) t = 0;
            M2C_FIELD(arg0, u16 *, 0x78) = (u16)t;
            func_ov002_021e1790(arg0, (s32)(M2C_FIELD(arg0, s32 *, 0x54) << 8) >> 16, (s32)(M2C_FIELD(arg0, s32 *, 0x58) << 8) >> 16);
            if (M2C_FIELD(arg0, s32 *, 0x6C) >= M2C_FIELD(arg0, s32 *, 0x70)) {
                func_ov002_021e299c(arg0, 6);
                func_ov002_021e1780(arg0);
                M2C_FIELD(arg0, s32 *, 0x6C) = -1;
            }
        }
    }
    func_ov002_021e1844(arg0);
}

void func_ov002_021e2c48(void *a,u8 b) {
 s32 x,y,z; u16 scale; s32 value;
 scale=(M2C_FIELD(a,u16 *,0x78)*M2C_FIELD(a,u16 *,0x42))>>8;
 if(M2C_FIELD(a,u16 *,0x86))b=!b;
 if(!b) {
 z=M2C_FIELD(a,s16 *,0x40);y=M2C_FIELD(a,s16 *,0x3e);x=M2C_FIELD(a,s16 *,0x3c);
 *(volatile s32 *)0x4000470=x;*(volatile s32 *)0x4000470=y;*(volatile s32 *)0x4000470=z;
 }else{
 x=M2C_FIELD(a,s16 *,0x3c);z=M2C_FIELD(a,s16 *,0x40);y=M2C_FIELD(a,s16 *,0x3e);
 *(volatile s32 *)0x4000470=-x;*(volatile s32 *)0x4000470=y;*(volatile s32 *)0x4000470=z;
 }
 if(scale==256)return;
 value=(s32)(scale<<12)>>8;
 *(volatile s32 *)0x400046c=value;*(volatile s32 *)0x400046c=value;*(volatile s32 *)0x400046c=4096;
}

void func_ov002_021e2cf0(void *arg0) {
    M2C_UNK func_ov002_021e1ef8(void *, u8);
    func_ov002_021e1ef8(arg0, (u8) M2C_FIELD(arg0, u16 *, 0x86));
}

void func_ov002_021e2d04(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_ov002_021e179c();
    func_ov002_021e179c();
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) (arg1 << 8);
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) (arg2 << 8);
}

void func_ov002_021e2d2c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, s16 arg8) {
    M2C_FIELD(arg0, s32 *, 0x5C) = arg1;
    M2C_FIELD(arg0, s32 *, 0x60) = arg2;
    M2C_FIELD(arg0, s32 *, 0x64) = arg3;
    M2C_FIELD(arg0, s32 *, 0x68) = arg4;
    M2C_FIELD(arg0, s32 *, 0x70) = arg5;
    M2C_FIELD(arg0, s16 *, 0x7A) = arg6;
    M2C_FIELD(arg0, s16 *, 0x7C) = arg7;
    M2C_FIELD(arg0, s16 *, 0x7E) = arg8;
    if (arg5 != 0) {
        M2C_FIELD(arg0, s16 *, 0x78) = arg6;
    } else {
        M2C_FIELD(arg0, s16 *, 0x78) = arg7;
    }
    M2C_FIELD(arg0, s16 *, 0x86) = 0;
}

void func_ov002_021e2d78(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7) {
 s32 var_r2=arg2; s32 var_r4; s32 var_r5;
 M2C_FIELD(arg0,s32 *,0x5c)=arg3*arg5-arg1;
 M2C_FIELD(arg0,s32 *,0x60)=var_r2-arg4*arg5;
 M2C_FIELD(arg0,s32 *,0x64)=-arg3;
 M2C_FIELD(arg0,s32 *,0x68)=arg4;
 M2C_FIELD(arg0,s32 *,0x70)=arg5;
 M2C_FIELD(arg0,s32 *,0x74)=arg5;
 M2C_FIELD(arg0,s16 *,0x7c)=arg6-arg7*arg5;
 M2C_FIELD(arg0,s16 *,0x7e)=arg7;
 var_r5=-arg1;
 M2C_FIELD(arg0,s16 *,0x78)=M2C_FIELD(arg0,s16 *,0x7c);
 var_r4=0;
 if(arg5>0)do {
 var_r5+=arg3;
 M2C_FIELD(arg0,s32 *,0x54)-=var_r5;
 var_r2-=arg4;
 M2C_FIELD(arg0,s32 *,0x58)-=var_r2;
 var_r4++;
 }while(var_r4<arg5);
 M2C_FIELD(arg0,s16 *,0x86)=1;
}

void func_ov002_021e2e18(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    M2C_FIELD(arg0, s16 *, 0x80) = arg1;
    M2C_FIELD(arg0, s16 *, 0x82) = arg2;
    M2C_FIELD(arg0, s16 *, 0x84) = arg3;
}

s32 func_ov002_021e2e28(void *arg0) {
    s32 temp_r1;
    s32 temp_r2;
    s32 temp_r3;
    s32 temp_r4;
    u16 temp_lr;

    temp_lr = M2C_FIELD(arg0, u16 *, 0x84);
    temp_r4 = M2C_FIELD(arg0, s32 *, 0x64);
    temp_r3 = M2C_FIELD(arg0, s16 *, 0x80) + ((s32) (((s32) M2C_FIELD(arg0, s32 *, 0x54) >> 8) * temp_lr) >> 8);
    temp_r1 = M2C_FIELD(arg0, s16 *, 0x82) + ((s32) (((s32) M2C_FIELD(arg0, s32 *, 0x58) >> 8) * temp_lr) >> 8);
    temp_r2 = M2C_FIELD(arg0, s32 *, 0x68);
    if ((temp_r4 < 0) && (temp_r3 < -0xA0)) {
        return 1;
    }
    if ((temp_r2 < 0) && (temp_r1 < -0x20)) {
        return 1;
    }
    if ((temp_r4 > 0) && (temp_r3 >= 0xA0)) {
        return 1;
    }
    if ((temp_r2 > 0) && (temp_r1 >= 0xE0)) {
        return 1;
    }
    return 0;
}

/* Shuffle the five auto-attack slot indices for a panel: take a fixed order from the caller when given, otherwise randomize-then-anchor specific slots, then build a descending priority index table. */
void func_ov002_021e2eb8(void *panel, void *slotTable, void *orderSeq) {
void func_02008048(void *, void *, s32);
s32 RandomIntRange(s32, s32);
void func_ov002_021e3030(u8 *, u8 *);
s32 j, best; void *entry; s32 k, mask, which, i;
M2C_FIELD(panel, void **, 4) = slotTable;
if (orderSeq) func_02008048(orderSeq, panel + 0x12, 5);
else {
for (i = 0; i < 5; i++) M2C_FIELD(panel + i, u8 *, 0x12) = i;
for (i = 0; i < 5; i++) func_ov002_021e3030(panel + 0x12 + i, panel + 0x12 + RandomIntRange(0, 4));
which = -1;
if (!M2C_FIELD(panel, u8 *, 0x12)) which = 0;
if (!M2C_FIELD(panel, u8 *, 0x16)) which = 4;
if (which != -1) func_ov002_021e3030(panel + 0x12 + which, panel + 0x12 + RandomIntRange(1, 3));
}
for (i = 0; i < 5; i++) M2C_FIELD(panel + i, u8 *, 0x17) = i;
for (i = 0; i < 5; i++) func_ov002_021e3030(panel + 0x17 + i, panel + 0x17 + RandomIntRange(0, 4));
mask = 0;
for (k = 0; k < 5; k++) {
entry = panel + k;
M2C_FIELD(entry, u8 *, 0x1c) = 0;
best = -1;
for (j = 0; j < 5; j++) {
if (!(mask & (1 << j)) && best < M2C_FIELD(panel + j, u8 *, 0x12)) {
M2C_FIELD(entry, u8 *, 0x1c) = j;
best = M2C_FIELD(panel + j, u8 *, 0x12);
}
}
mask |= 1 << M2C_FIELD(entry, u8 *, 0x1c);
}
}

void func_ov002_021e3030(u8 *arg0, u8 *arg1) {
    u8 temp_r3;

    temp_r3 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_r3;
}

void func_ov002_021e3044(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_lr;
    s32 temp_r2;
    s32 var_r4;
    u8 temp_r5_2;
    u8 temp_r9;
    void *temp_r5;
    void *temp_r5_3;
    void *temp_r9_2;

    var_r4 = 0;
    temp_lr = arg1 - 1;
    temp_r2 = arg2 - 1;
    do {
        temp_r5 = arg0 + var_r4;
        temp_r9 = M2C_FIELD(temp_r5, u8 *, 0x12);
        if (temp_lr > (s32) (temp_r9 * 2)) {
            M2C_FIELD((arg0 + (var_r4 * 2)), s8 *, 8) = 2;
        } else {
            temp_r9_2 = arg0 + (var_r4 * 2);
            if (temp_lr == (temp_r9 * 2)) {
                M2C_FIELD(temp_r9_2, s8 *, 8) = 1;
            } else {
                M2C_FIELD(temp_r9_2, s8 *, 8) = 0;
            }
        }
        temp_r5_2 = M2C_FIELD(temp_r5, u8 *, 0x12);
        if (temp_r2 > (s32) (temp_r5_2 * 2)) {
            M2C_FIELD((arg0 + (var_r4 * 2)), s8 *, 9) = 2;
        } else {
            temp_r5_3 = arg0 + (var_r4 * 2);
            if (temp_r2 == (temp_r5_2 * 2)) {
                M2C_FIELD(temp_r5_3, s8 *, 9) = 1;
            } else {
                M2C_FIELD(temp_r5_3, s8 *, 9) = 0;
            }
        }
        var_r4 += 1;
    } while (var_r4 < 5);
}

s32 func_ov002_021e30d0(s16 *p) {s32 n=0;while(*p!=-1 && n<5){n++;p+=2;}return n;}

void func_ov002_021e3100(void *a){
extern u8 data_ov002_021f3104[];extern volatile u8 gPlayerSettings[];
SlotEntry *p;s32 first,n,i;u32 index;u8 *src;void *entry;
first=0;do{M2C_FIELD(a+((u32)first<<2),s16 *,0x22)=-1;first++;}while(first<5);
if(!data_ov002_021f3104[(s16)M2C_FIELD(a,u8 *,0x64)*24])return;
n=0;i=0;p=a+0x22;
do{
index=M2C_FIELD(a+i,u8 *,0x17);
if(M2C_FIELD(a,u8 *,0x64)==gPlayerSettings[0]){
if(M2C_FIELD(a+index*2,u8 *,8)){
src=M2C_FIELD(a,u8 **,4);
p->value=src[0]+src[n+3];n++;
SetSlotIndex(p,index);p++;
}
}else if(M2C_FIELD(a+index*2,u8 *,9)){
src=M2C_FIELD(M2C_FIELD(a,void **,0x60),u8 **,4);
p->value=src[0]+src[n+8];n++;
SetSlotIndex(p,index);p++;
}
i++;
}while(i<5);
}

