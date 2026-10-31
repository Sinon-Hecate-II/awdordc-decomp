/* 18 functions from 0x021E7C84 to 0x021E8984 (ov002), found by ds-decomp. */
#include "common.h"
typedef struct { s32 pad[2]; s32 slots[5]; } ObjectSlots;

void func_ov002_021e7c84(u8 *p) { extern s32 gPlayerSettings; p[0]=0;p[1]=0;((u8 *)&gPlayerSettings)[12]=8;((u8 *)&gPlayerSettings)[36]=12;((u8 *)&gPlayerSettings)[16]=0;((u8 *)&gPlayerSettings)[40]=1;((u8 *)&gPlayerSettings)[17]=3;((u8 *)&gPlayerSettings)[41]=3;((u8 *)&gPlayerSettings)[18]=0;((u8 *)&gPlayerSettings)[42]=0;((u8 *)&gPlayerSettings)[3]=0;p[13]=100;p[37]=100;p[14]=80;p[38]=20;p[15]=3;p[39]=3;p[21]=1;p[45]=2;p[22]=2;p[46]=2;p[23]=1;p[47]=1;((u8 *)&gPlayerSettings)[20]=1;((u8 *)&gPlayerSettings)[44]=1;((u8 *)&gPlayerSettings)[19]=0;((u8 *)&gPlayerSettings)[43]=0;((u8 *)&gPlayerSettings)[24]=0;((u8 *)&gPlayerSettings)[48]=1;((u8 *)&gPlayerSettings)[25]=0;((u8 *)&gPlayerSettings)[49]=1;}

void func_ov002_021e7d34(void *arg0, s32 arg1, u32 arg2, u32 arg3, s32 arg4) {
    extern u8 data_ov002_021f2e54[];
    extern u8 data_ov002_021f2e44[];
    extern u8 data_ov002_021f2e48[];
    extern u8 data_ov002_021f1171[];
    extern u8 data_ov002_021f2e50[];
    extern u8 data_ov002_021f2e4c[];
    extern u8 data_ov002_021f2e70[];
    extern void **gCurrentMap;
    s32 RandomIntRange(s32, s32);
    u8 *p;
    s32 r5;
    s32 i19;
    u8 *ptr19;
    u8 *ptr10;
    u8 r1;
    u8 r8;
    u8 r7;
    u8 r6;
    u8 lr;
    u8 flag;
    u32 t;
    s32 rr;
    u8 v;
    p = (u8 *)arg0;
    r5 = arg1 * 24;
    ptr19 = p + 0x19;
    i19 = ptr19[r5];
    i19 = i19 - 1;
    ptr19[r5] = (u8)i19;
    ptr10 = p+0x10;
    r1 = data_ov002_021f2e54[arg2];
    r8 = M2C_FIELD(p+r5,u8 *,0x18);
    r7 = M2C_FIELD(p+r5,u8 *,0x13);
    r6 = M2C_FIELD(p+r5,u8 *,0x14);
    lr = ptr10[r5];
    switch (arg2) {
        case 1:
            if (lr == 0x07) r1 = 0x01;
            break;
        case 2:
            if (r7 == 0) {
                if(r8 == 0) { if(lr==7) r1=3; else r1=2; }
                else { if(lr==7)r1=5;else r1=4; }
            } else { if(lr==7)r1=1;else r1=0; }
            break;
        case 9:
            if (r7 == 0) {
                if (r8 == 0) r1 = 0x09; else r1 = 0x0A;
            } else {
                r1 = 0x0B;
            }
            break;
        case 15:
            if (r6 == 0) r1 = 0x17;
            break;
        case 17:
            if (r8 == 0) r1 = 0x18; else r1 = 0x19;
            break;
        case 20:
            if (arg3 == 0x16) r1 = 0x1D;
            break;
        case 21:
            if (r8 == 0) {
                if (arg3 == 0x16) r1 = 0x1F; else r1 = 0x1E;
            } else {
                if (arg3 == 0x16) r1 = 0x21; else r1 = 0x20;
            }
            break;
        case 22:
            if ((u8)arg4 != 0) r1 = 0x26;
            break;
        case 23:
            if (r7 == 0) {
                if (arg3 == 0x16) r1 = 0x23; else r1 = 0x22;
            } else {
                r1 = 0x24;
            }
            break;
        case 24:
            if (arg3 == 0x16) r1 = 0x28;
            break;
        case 25: if(arg3 == 0x16) r1=0x2a;break;
        default:
            break;
    }
    p[r5 + 0x0C] = r1;
    flag = ((u8 *)*gCurrentMap)[0x5157];
    if (flag == 0x04 && lr == 0x04) {
        rr = RandomIntRange(0, 2);
        ptr10[r5] = data_ov002_021f2e44[rr];
        return;
    }
    if (flag == 0x08) {
        t = (s32)lr - 1;
        if (t <= 1) {
            rr = RandomIntRange(0, 2);
            ptr10[r5] = data_ov002_021f2e48[rr];
            return;
        }
    }
    if (lr == 0x13) {
        if (data_ov002_021f1171[r1 * 0x40] != 0x03) {
            v = p[0x03];
            ptr10[r5] = data_ov002_021f2e50[v];
            return;
        }
    }
    if (lr == 0x15) {
        if (data_ov002_021f1171[r1 * 0x40] != 0x03) {
            v = p[0x03];
            ptr10[r5] = data_ov002_021f2e4c[v];
            return;
        }
    }
    v = p[0x03];
    ptr10[r5] = data_ov002_021f2e70[v + (u32)lr * 4];
}

s32 func_ov002_021e7fec(s32 arg0,s32 arg1) { switch(M2C_FIELD(arg0+arg1*24,u8 *,12)) {case 0x25: case 0x26:return 1; default:return 0;} }

u8 func_ov002_021e8014(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(((arg1 * 0x18) + arg0), void **, 8), u8 *, 0x22) == 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov002_021e8038(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(((arg1 * 0x18) + arg0), void **, 8), u8 *, 0x22) == 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov002_021e805c(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(((arg1 * 0x18) + arg0), void **, 8), u8 *, 0x21) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov002_021e8080(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(((arg1 * 0x18) + arg0), void **, 8), u8 *, 0x21) == 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov002_021e80a4(s32 arg0, s32 arg1) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(((arg1 * 0x18) + arg0), void **, 8), u8 *, 0x21) == 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov002_021e80c8(void *arg0, s32 idx, void *arg2, s32 arg3) {
    extern void **gCurrentMap;
    s32 func_ov000_0216ca8c(u8, u8);
    s32 func_020a7cfc(void *);
    void func_020d03ec(s32, u8, u8);
    s32 func_020a27f8(s32, s32);
    u8 *a;
    u8 *r7;
    void *r6;
    void *base;
    s32 r5;
    u8 low6;
    s32 t6;
    u16 w;
    s16 r2v;
    s32 r1s;
    s32 high;
    s32 r4v;
    void *map;
    u8 u1;
    u8 u2;
    u16 tbl;
    s32 diff;
    s64 prod;
    s32 high2;
    s32 tmp;
    s32 sign;
    s32 q;
    s32 idx2;
    void *mapb;
    u32 vv;
    s32 r0;
    u8 *ptr;
    s32 diff3;
    s64 prod3;
    s32 high3;
    s32 tmp3;
    s32 sign3;
    s32 q3;
    s32 idx3;
    s32 idx4;
    s32 diff4;
    s64 prod4;
    s32 high4;
    s32 tmp4;
    s32 sign4;
    s32 q4;
    u8 low;
    u8 res;
    s32 idx5;
    s32 diff5;
    s64 prod5;
    s32 high5;
    s32 tmp5;
    s32 sign5;
    s32 q5;
    u8 v2;
    s32 idx6;
    s32 diff6;
    s64 prod6;
    s32 high6;
    s32 tmp6;
    s32 sign6;
    s32 q6;
    u8 *dest;
    u8 v3;

    a = (u8 *)arg0;
    r7 = (u8 *)arg2;
    r6 = (void *)arg3;
    r5 = idx * 0x18;
    low6 = (u8)(((unsigned)r7[0] << 26) >> 26);
    a[r5 + 0xc] = low6;
    t6 = *(s16 *)((u8 *)r6 + 0x1e);
    a[r5 + 0x14] = (u8)(t6 != 0);
    t6 = *(s16 *)((u8 *)r6 + 0x1e);
    a[r5 + 0x13] = (u8)(t6 == 2);
    w = *(u16 *)((u8 *)r7 + 6);
    a[r5 + 0xd] = (u8)(((unsigned)w << 25) >> 25);
    a[r5 + 0xe] = (u8)*(s16 *)((u8 *)r6 + 0xe);
    a[r5 + 0xf] = (u8)(((unsigned)r7[0] << 24) >> 30);
    a[0x10 + r5] = (u8)*(s16 *)((u8 *)r6 + 0x4);
    r0 = func_ov000_0216ca8c(r7[1], r7[2]);
    if (r0 == 0x28) a[0x10 + r5] = 0x1b;
    r0 = func_ov000_0216ca8c(r7[1], r7[2]);
    if (r0 == 0x29) a[0x10 + r5] = 0x1c;
    r2v = *(s16 *)((u8 *)r6 + 0x6);
    r1s = (s32)((u32)r2v >> 31);
    high = (s32)(((s64)0x66666667 * r2v) >> 32);
    r4v = r1s + (high >> 2);
    a[r5 + 0x11] = (u8)r4v;
    map = *gCurrentMap;
    u1 = r7[2];
    u2 = r7[1];
    tbl = *(u16 *)((u8 *)map + 0x3758 + u1 * 2);
    a[r5 + 0x12] = (u8)(((((*(u8 *)((u8 *)map + 0x1420 + u2 + tbl)) & 0xE0)) >> 5));
    if (r7 == 0) idx2 = 0;
    else {
        base = (u8 *)map + 0x59a4;
        diff = (s32)((u8 *)r7 - (u8 *)base);
        prod = (s64)0x92492493 * diff;
        high2 = (s32)(prod >> 32);
        tmp = diff + high2;
        sign = (s32)((u32)diff >> 31);
        q = (sign + (tmp >> 3)) >> 6;
        idx2 = q + 1;
    }
    mapb = *gCurrentMap;
    vv = *(u32 *)((u8 *)mapb + idx2 * 0x8c + 0x6810);
    a[r5 + 0x15] = (u8)((vv << 24) >> 24);
    r0 = func_020a7cfc(r7);
    if (r0 != 0) {
        a[r5 + 0x16] = 2;
        ptr = a + r5 + 0x16;
    } else {
        if (r7 == 0) idx3 = 0;
        else {
            base = (u8 *)map + 0x59a4;
            diff3 = (s32)((u8 *)r7 - (u8 *)base);
            prod3 = (s64)0x92492493 * diff3;
            high3 = (s32)(prod3 >> 32);
            tmp3 = diff3 + high3;
            sign3 = (s32)((u32)diff3 >> 31);
            q3 = (sign3 + (tmp3 >> 3)) >> 6;
            idx3 = q3 + 1;
        }
        func_020d03ec(idx3, r7[1], r7[2]);
        a[r5 + 0x16] = 1;
        ptr = a + r5 + 0x16;
    }
    if (ptr[0] != 0) {
        if (r7 == 0) idx4 = 0;
        else {
            base = (u8 *)map + 0x59a4;
            diff4 = (s32)((u8 *)r7 - (u8 *)base);
            prod4 = (s64)0x92492493 * diff4;
            high4 = (s32)(prod4 >> 32);
            tmp4 = diff4 + high4;
            sign4 = (s32)((u32)diff4 >> 31);
            q4 = (sign4 + (tmp4 >> 3)) >> 6;
            idx4 = q4 + 1;
        }
        low = (u8)(((unsigned)r7[0] << 26) >> 26);
        res = (u8)func_020a27f8(idx4, (s32)low);
        a[r5 + 0x17] = res;
    } else {
        a[r5 + 0x17] = 0;
    }
    if (r7 == 0) idx5 = 0;
    else {
        base = (u8 *)map + 0x59a4;
        diff5 = (s32)((u8 *)r7 - (u8 *)base);
        prod5 = (s64)0x92492493 * diff5;
        high5 = (s32)(prod5 >> 32);
        tmp5 = diff5 + high5;
        sign5 = (s32)((u32)diff5 >> 31);
        q5 = (sign5 + (tmp5 >> 3)) >> 6;
        idx5 = q5 + 1;
    }
    v2 = *(u8 *)((u8 *)map + idx5 * 0x8c + 0x67cd);
    a[r5 + 0x18] = v2;
    if (r7 == 0) idx6 = 0;
    else {
        base = (u8 *)map + 0x59a4;
        diff6 = (s32)((u8 *)r7 - (u8 *)base);
        prod6 = (s64)0x92492493 * diff6;
        high6 = (s32)(prod6 >> 32);
        tmp6 = diff6 + high6;
        sign6 = (s32)((u32)diff6 >> 31);
        q6 = (sign6 + (tmp6 >> 3)) >> 6;
        idx6 = q6 + 1;
    }
    dest = a + 0x19;
    v3 = *(u8 *)((u8 *)map + idx6 * 0x8c + 0x67c1);
    dest[r5] = v3;
    if (v3 == 3) {
        dest[r5] = 4;
        return;
    }
    if (v3 == 4) {
        dest[r5] = 3;
    }
}

void func_ov002_021e8470(u8 *p,u8 *a,u8 *b,s32 c,s32 d){
extern void **data_027e0058;
void func_ov002_021e80c8(void*,s32,void*,s32);
s32 func_020a7d38(void*);

p[0]=a!=M2C_FIELD(*data_027e0058,u8**,0x52d0);
p[1]=!p[0];
switch(M2C_FIELD(*data_027e0058,u8*,0x5157)){
case 3: case 4: case 6:p[3]=1;break;
case 1:p[3]=2;break;
case 2:p[3]=3;break;
default:p[3]=0;break;
}
func_ov002_021e80c8(p,0,a,c);
func_ov002_021e80c8(p,1,b,d);
func_ov002_021e7d34(p,0,(u32)(a[0]<<26)>>26,(u32)(b[0]<<26)>>26,func_020a7d38(a));
func_ov002_021e7d34(p,1,(u32)(b[0]<<26)>>26,(u32)(a[0]<<26)>>26,func_020a7d38(b));
}

void func_ov002_021e85b0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    void func_ov002_021e8470(u8 *, u8 *, u8 *, s32, s32);
    extern M2C_UNK gPlayerSettings;
    func_ov002_021e8470(&gPlayerSettings, arg0, arg1, arg2, arg3);
}

void func_ov002_021e85e8(void *p) {
M2C_UNK func_ov002_021e3f2c(void *, u8);
extern M2C_UNK data_ov002_021f3124;
extern u8 data_ov002_021f2fa9[], data_ov002_021f30fd[];
extern u8 *data_ov002_021f30f4[];
s32 i;
u8 flag;
flag = (u8)(p != &data_ov002_021f3124);
M2C_FIELD(p, u8 *, 0x27) = flag;
for (i = 0; i < 5; i++) ((ObjectSlots *)p)->slots[i] = 0;
M2C_FIELD(p, u8 *, 0x2A) = data_ov002_021f2fa9[M2C_FIELD(p, u8 *, 0x27) * 104];
M2C_FIELD(p, u8 *, 0x2B) = (((data_ov002_021f30fd[M2C_FIELD(p, u8 *, 0x27) * 24] + 9) / 10 + 1) & ~1U) >> 1;
if (M2C_FIELD(p, u8 *, 0x2A) && M2C_FIELD(p, u8 *, 0x2B)) M2C_FIELD(p, u8 *, 0x2B) = 1;
M2C_FIELD(p, u16 *, 0x1C) = 256;
M2C_FIELD(p, u16 *, 0x1E) = 0; M2C_FIELD(p, u16 *, 0x20) = 0; M2C_FIELD(p, u16 *, 0x22) = 0; M2C_FIELD(p, u16 *, 0x24) = 0;
M2C_FIELD(p, s8 *, 0x26) = -1;
if (M2C_FIELD(*(u8 **)((u8 *)data_ov002_021f30f4 + M2C_FIELD(p, u8 *, 0x27) * 24), u8 *, 0x3D) != 2)
M2C_FIELD(p, u8 *, 0x28) = 0; else M2C_FIELD(p, u8 *, 0x28) = 1;
M2C_FIELD(p, u8 *, 0x29) = 0;
func_ov002_021e3f2c(p, M2C_FIELD(p, u8 *, 0x27));
}

#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
s32 func_ov002_021e86f8(s32 arg0,s32 arg1) { s32 result=20; s32 i=0; do { if(i!=arg1) { if((u32)M2C_FIELD(arg0+i*8,u16 *,6)>(u32)M2C_FIELD(arg0+arg1*8,u16 *,6)) result+=20; } i++; }while(i<5); return result; }
#pragma opt_loop_invariants reset
#pragma opt_strength_reduction reset
void func_ov002_021e8738(void *p) {
    M2C_UNK func_02082028(s32);
    void func_ov002_021e8d0c(void *, s8, s8);
    void func_ov002_021e997c(void *);
    s32 func_ov002_021e86f8(s32, s32);
    void func_ov002_021e8ff0(void *, s16, s16, s16);
    void func_ov002_021e9000(void *, s16);
    void func_020af860(s32, s32);
    extern u8 data_ov002_021f2f44[];
    extern u8 data_ov002_021ea704[];
    extern u8 data_ov002_021f2f1c[];
    extern u8 *data_ov002_021f30f4[];
    u8 *tableBase;
    void *alloc;
    s32 owner;
    s32 flag;
    s32 idx;

    flag = M2C_FIELD(p, u8 *, 0x2A);
    owner = M2C_FIELD(p, u8 *, 0x27);
    idx = 0;
loop:
    if (flag == 0) {
        if (M2C_FIELD(data_ov002_021f2f44 + owner * 0x68, u8 *, idx * 2 + 8) == 0) goto tail2;
    }
    alloc = func_02082028(0x90);
    if (alloc != 0) {
        M2C_FIELD(alloc, void **, 0x00) = (void *)data_ov002_021ea704;
        M2C_FIELD(alloc, s32 *, 0x08) = 0;
        M2C_FIELD(alloc, s32 *, 0x0C) = 0;
        M2C_FIELD(alloc, void **, 0x00) = (void *)data_ov002_021f2f1c;
        M2C_FIELD(alloc, s32 *, 0x54) = 0;
        M2C_FIELD(alloc, s32 *, 0x58) = 0;
        M2C_FIELD(alloc, s32 *, 0x5C) = 0;
        M2C_FIELD(alloc, s32 *, 0x60) = 0;
        M2C_FIELD(alloc, s32 *, 0x64) = 0;
        M2C_FIELD(alloc, s32 *, 0x68) = 0;
        M2C_FIELD(p, void **, 0x08 + idx * 4) = alloc;
        func_ov002_021e8d0c(alloc, (s8)owner, (s8)idx);
        func_ov002_021e997c(alloc);
        tableBase = M2C_FIELD(M2C_FIELD((void *)((u8 *)data_ov002_021f30f4 + owner * 0x18), void **, 0x04), void **, 0x28);
        func_ov002_021e8ff0(M2C_FIELD(p, void **, 0x08 + idx * 4),
            (s16)(M2C_FIELD(tableBase, s16 *, idx * 8 + 0) - 0x80),
            M2C_FIELD(tableBase, s16 *, idx * 8 + 2),
            (s16)(M2C_FIELD(tableBase, s16 *, idx * 8 + 4) + (flag != 0 ? 0x14 : func_ov002_021e86f8((s32)tableBase, idx))));
        func_ov002_021e9000(M2C_FIELD(p, void **, 0x08 + idx * 4), M2C_FIELD(tableBase, u16 *, idx * 8 + 6));
    }
    if (flag != 0) goto tail;
    idx++;
    if (idx < 5) goto loop;
tail:
    func_020af860(owner, M2C_FIELD(p, u8 *, 0x2B));
    return;
tail2:
    if (flag != 0) goto tail;
    idx++;
    if (idx < 5) goto loop;
    goto tail;
}

void func_ov002_021e8898(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x1E) = arg1;
}

void func_ov002_021e88a0(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x26) = 0;
}

void func_ov002_021e88ac(void *p) { extern s8 data_ov002_021f2ef0[]; s32 i; if(M2C_FIELD(p,s8 *,0x26)==-1)return;
 M2C_FIELD(p,s16 *,0x22)=data_ov002_021f2ef0[M2C_FIELD(p,s8 *,0x26)&~1];
 M2C_FIELD(p,s16 *,0x24)=data_ov002_021f2ef0[(M2C_FIELD(p,s8 *,0x26)&~1)+1];
 i=M2C_FIELD(p,s8 *,0x26)&~1;
 if(data_ov002_021f2ef0[i]==0 && data_ov002_021f2ef0[i+1]==0) M2C_FIELD(p,s8 *,0x26)=-1;
 else M2C_FIELD(p,s8 *,0x26)++;
}

void func_ov002_021e8914(void *arg0) {
    void func_ov002_021e42c4(void *);
    s32 func_ov002_021e79ac(void *);
    void func_ov002_021e8e8c(void *);
    extern u8 data_ov002_021f30e4[];
    register s32 i;
    if (func_ov002_021e79ac(data_ov002_021f30e4)==0) M2C_FIELD(arg0,u8 *,0x29)++;
    i=0;
    do {
        if (((void **)arg0)[i+2]!=0) func_ov002_021e8e8c(((void **)arg0)[i+2]);
        i++;
    } while(i<5);
    func_ov002_021e88ac(arg0);
    if(M2C_FIELD(arg0,u8 *,0x28)!=0) M2C_FIELD(arg0,s16 *,0x20)--;
    func_ov002_021e42c4(arg0);
}

