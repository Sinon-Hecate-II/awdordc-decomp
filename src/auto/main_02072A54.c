/* 15 functions from 0x02072A54 to 0x020739F8 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 type:5; } RuntimeType;

s32 func_02072a54(void) { return 7; }

s32 func_02072a68(void) {
    return 0x18;
}

s32 func_02072a78(s32 unused,u8 *p,u32 *count) {
s32 func_02072a54(void);
u32 i;
u32 n=*count;
for(i=0;i<n;i++) {
s32 c=func_02072a54();
p[i]=(short)c;
if((u8)c==13 || (u8)c==10) { *count=i+1; break; }
}
return 0;
}

s32 func_02072ac8(s32 unused,u8 *p,u32 *count) {
void func_02072a40(u8 *);
u32 i;
u32 n=*count;
for(i=0;i<n;i++) func_02072a40(p+i);
return 0;
}

s32 func_02072afc(void) {
    return 0;
}

s32 func_02072b04(void *buf) {
    /* save context */
    /* can't express stmia of registers in C directly */
    return 0;
}

void *func_02072b20(void *arg0, s32 *arg1) {
    s8 temp_r2;
    u8 temp_lr;
    u8 temp_r4;

    temp_r2 = M2C_FIELD(arg0, s8 *, 0);
    if (!(temp_r2 & 1)) {
        *arg1 = temp_r2 >> 1;
        return arg0 + 1;
    }
    temp_r4 = M2C_FIELD(arg0, u8 *, 1);
    if (!(temp_r2 & 2)) {
        *arg1 = temp_r4 | ((temp_r2 >> 2) << 8);
        return arg0 + 2;
    }
    temp_lr = M2C_FIELD(arg0, u8 *, 2);
    if (!(temp_r2 & 4)) {
        *arg1 = temp_lr | ((temp_r4 << 8) | ((temp_r2 >> 3) << 0x10));
        return arg0 + 3;
    }
    *arg1 = M2C_FIELD(arg0, u8 *, 3) | ((temp_r4 << 0x10) | ((temp_r2 >> 3) << 0x18) | (temp_lr << 8));
    return arg0 + 4;
}

void *func_02072bac(u8 *p,u32 *out) {
u32 a;
u32 b,c;
a=*(u8 *)p;
if(!(a&1)) { *out=a>>1; return p+1; }
b=p[1];
if(!(a&2)) { *out=b|((a>>2)<<8); return p+2; }
c=p[2];
if(!(a&4)) { *out=c|((b<<8)|((a>>3)<<16)); return p+3; }
*out=p[3]|((b<<16)|((a>>3)<<24)|(c<<8)); return p+4;
}

void *func_02072c38(u32 *p,s32 n,u32 addr) {
s32 mid;
u32 *q;
s32 lo=0;
s32 hi=n-1;
while(lo<=hi) {
mid=(lo+hi)>>1;
q=(u32 *)((u8 *)p+mid*12);
if(addr<q[0]) hi=mid-1;
else if(addr>q[0]+(q[1]&~1U)) lo=mid+1;
else return q;
}
return 0;
}

void func_02072c9c(s32 arg0, void *arg1) {
    s32 __FindExceptionTable(void *, s32);
    void *func_02072bac(u8 *, u32 *);
    void *func_02072c38(u32 *, s32, u32);
    s32 func_020745fc(void *);
    u32 sp8;
    u32 sp4;
    u32 sp0;
    u32 *temp_r0;
    u32 *temp_r0_2;
    s32 temp_r1;
    u32 temp_r7;
    u32 var_r8;
    void *var_r0;
    void *var_r1;
    M2C_FIELD(arg1, s32 *, 4) = 0;
    M2C_FIELD(arg1, s32 *, 8) = 0;
    if (__FindExceptionTable(arg1, arg0) == 0) {
        return;
    }
    temp_r0 = M2C_FIELD(arg1, u32 *, 0xC);
    temp_r1 = M2C_FIELD(arg1, s32 *, 0x10);
    temp_r0_2 = func_02072c38(temp_r0, (temp_r1 - (s32)temp_r0) / 12, (u32)arg0);
    if (temp_r0_2 == NULL) {
        return;
    }
    if (M2C_FIELD(temp_r0_2, s32 *, 4) & 1) {
        var_r1 = (void *)((u8 *)temp_r0_2 + 8);
    } else {
        var_r1 = M2C_FIELD(temp_r0_2, void **, 8);
    }
    M2C_FIELD(arg1, void **, 4) = var_r1;
    M2C_FIELD(arg1, s32 *, 0) = M2C_FIELD(temp_r0_2, s32 *, 0);
    temp_r7 = (u32)(arg0 - M2C_FIELD(temp_r0_2, s32 *, 0));
    var_r0 = func_020745fc(M2C_FIELD(arg1, void **, 4));
    var_r8 = 0;
loop:
    var_r0 = func_02072bac((u8 *)var_r0, &sp8);
    if (sp8 == 0) {
        return;
    }
    var_r0 = func_02072bac((u8 *)var_r0, &sp4);
    var_r0 = func_02072bac((u8 *)var_r0, &sp0);
    {
        u32 temp_r2 = var_r8 + sp8;
        if (temp_r7 < temp_r2) {
            return;
        }
        var_r8 = temp_r2 + sp4;
        if (temp_r7 > var_r8) {
            goto loop;
        }
    }
    M2C_FIELD(arg1, void **, 8) = (void *)((u8 *)M2C_FIELD(arg1, void **, 4) + sp0);
    return;
}

u8 func_02072da4(void *arg0) {
u8 *p=M2C_FIELD(arg0,u8 **,8);
s32 result;
if(p) result=*p&31;
else result=0;
return (u8)result;
}

s32 func_02072dc0(void *arg0) {
    void *func_02072b20(void *, s32 *);
    void *func_02072bac(u8 *, u32 *);
    void func_02072c9c(s32, void *);
    s32 func_020744e0(void *, void *);
    M2C_UNK func_0207453c(void *, void *);
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 sp4;
    s32 sp0;
    s32 temp_r0;
    s32 temp_r0_2;
    u32 temp_r0_4;
    u8 *temp_r0_5;
    u8 *temp_r2;
    u8 *var_r2;
    u8 temp_r0_3;

loop_1:
    temp_r2 = M2C_FIELD(arg0, u8 **, 8);
    if ((temp_r2 == NULL) || (temp_r0_3 = *temp_r2, ((temp_r0_3 & 0x80) != 0))) {
        func_02072c9c(func_020744e0(arg0 + 0x18, arg0), arg0);
        if (M2C_FIELD(arg0, s32 *, 4) == 0) {
            return 0xFF;
        }
        func_0207453c(arg0 + 0x18, arg0);
        if (M2C_FIELD(arg0, u8 **, 8) != NULL) {
            goto block_48;
        }
        goto loop_1;
    }
    temp_r0_4 = temp_r0_3 & 0x1F;
    switch (temp_r0_4) {
    default:
    case 0:
    case 1:
    case 14:
        return 0xFF;
    case 2:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(temp_r2 + 1, &sp9C) + 4);
block_48:
        var_r2 = M2C_FIELD(arg0, u8 **, 8);
        temp_r0_2 = *var_r2 & 0x1F;
        if (temp_r0_2 != 1) {
            return temp_r0_2;
        }
        do {
            func_02072b20(var_r2 + 1, &sp0);
            var_r2 = &M2C_FIELD(arg0, u8 **, 8)[sp0];
            M2C_FIELD(arg0, u8 **, 8) = var_r2;
            temp_r0 = *var_r2 & 0x1F;
        } while (temp_r0 == 1);
        return temp_r0;
    case 3:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(temp_r2 + 1, &sp94), &sp98) + 4);
        goto block_48;
    case 4:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(temp_r2 + 1, &sp90) + 4);
        goto block_48;
    case 5:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072bac(func_02072bac(func_02072b20(temp_r2 + 1, &sp84), &sp88), &sp8C) + 4);
        goto block_48;
    case 6:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(temp_r2 + 1, &sp7C), &sp80) + 4);
        goto block_48;
    case 7:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(temp_r2 + 1, &sp74), &sp78) + 4);
        goto block_48;
    case 8:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(func_02072b20(temp_r2 + 1, &sp68), &sp6C), &sp70) + 4);
        goto block_48;
    case 9:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072bac(func_02072bac(func_02072b20(func_02072b20(temp_r2 + 1, &sp58), &sp5C), &sp60), &sp64) + 4);
        goto block_48;
    case 10:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(temp_r2 + 1, &sp54) + 4);
        goto block_48;
    case 11:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(temp_r2 + 1, &sp4C), &sp50) + 4);
        goto block_48;
    case 12:
        M2C_FIELD(arg0, u8 **, 8) = func_02072b20(func_02072bac(temp_r2 + 5, &sp44), &sp48);
        goto block_48;
    case 13:
        M2C_FIELD(arg0, u8 **, 8) = func_02072b20(temp_r2 + 1, &sp40);
        goto block_48;
    case 15:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072bac(func_02072bac(temp_r2 + 1, &sp34), &sp38), &sp3C) + (sp34 * 4));
        goto block_48;
    case 16:
        temp_r0_5 = func_02072b20(func_02072b20(temp_r2 + 1, &sp24), &sp28);
        sp30 = M2C_FIELD(temp_r0_5, u8 *, 0) | (M2C_FIELD(temp_r0_5, u8 *, 1) << 8) | (M2C_FIELD(temp_r0_5, u8 *, 2) << 0x10) | (M2C_FIELD(temp_r0_5, u8 *, 3) << 0x18);
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(temp_r0_5 + 4, &sp2C) + 4);
        goto block_48;
    case 17:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(func_02072b20(func_02072b20(temp_r2 + 1, &sp14), &sp1C) + 1, &sp18), &sp20) + 4);
        goto block_48;
    case 18:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072bac(func_02072b20(func_02072b20(temp_r2 + 1, &sp8) + 1, &spC), &sp10) + 4);
        goto block_48;
    case 19:
        M2C_FIELD(arg0, u8 **, 8) = func_02072b20(temp_r2 + 1, &sp4);
        goto block_48;
    }
}

