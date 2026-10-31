/* 23 functions from 0x020D166C to 0x020D2470 (main), found by ds-decomp. */
#include "common.h"
static inline u8 PlayerStatusIndex(void *p) { return M2C_FIELD(p,s32 *,0x6810); }

void func_020d166c(s32 a, s32 b) {
    void func_020d0de4(s16, s16);
    if (!b) return;
    func_020d0de4((s16)a, (s16)b);
}

void func_020d1690(u8 arg0, s32 arg1, void *arg2) {
    extern void **gCurrentMap;
    s32 func_020a5ae0(s32);
    u8 func_020a8204(void *);
    s32 func_020a796c(s32, s32, s32);
    s32 func_020a86f8(void *, s32, s32, s32);
    void func_020d068c(void *, s16);
    s32 func_0207c8ec(s32, s32);
    s32 func_ov000_0216b154(void);
    void func_020d0afc(void *, s32, s32);

    s32 r4 = 0, r5 = 0, r6 = 0;
    u8 *unit = (u8 *)*gCurrentMap + 0x59a4 + arg0 * 14;
    u8 saved1 = unit[1];
    u8 saved2 = unit[2];
    s32 low7, d4, prod;
    u32 f6;
    u8 *m;
    s16 cc;

    if (arg2 != NULL) {
        unit[1] = (u8)*(s16 *)arg2;
        unit[2] = (u8)*((s16 *)arg2 + 1);
        func_020d068c((u8 *)*gCurrentMap + 0x6eb8, (s16)arg0);
        if (func_020a8204(unit)) {
            r4 = func_020a86f8(unit, func_020a5ae0(arg1), 0, 0);
        } else {
            r6 = func_020a796c(((u32)unit[0] << 26) >> 26, arg1, 1);
            if (r6) {
                r5 = func_020a86f8(unit, func_020a5ae0(arg1), 1, 0);
            }
        }
    } else {
        r6 = func_020a796c(((u32)unit[0] << 26) >> 26, arg1, 1);
        if (r6) {
            r5 = func_020a86f8(unit, func_020a5ae0(arg1), 1, 0);
        }
    }

    if (r4 > r5) {
        m = (u8 *)*gCurrentMap + 0x6e00;
        *(s16 *)(m + 0xd6) = 1;
        *(s16 *)(m + 0xd0) = (s16)r4;
        *(s16 *)((u8 *)*gCurrentMap + 0x6ec8) -= 1;
    } else {
        if (r6) {
            m = (u8 *)*gCurrentMap + 0x6e00;
            *(s16 *)(m + 0xd6) = 2;
            *(s16 *)(m + 0xd0) = (s16)r5;
        }
    }

    func_020d0afc((u8 *)*gCurrentMap + 0x6eb8, 0, 0);

    m = (u8 *)*gCurrentMap;
    {
        void *o = *(void **)((u8 *)*gCurrentMap + 0x6eb8);
        f6 = *(u16 *)((u8 *)o + 6);
    }
    if ((f6 & 0x7F) == 0) {
        low7 = 0;
    } else {
        low7 = func_0207c8ec((f6 & 0x7F) - 1, 10) + 1;
    }
    d4 = *(s16 *)(m + 0x6ed4);
    prod = func_0207c8ec(d4 * low7, 10);
    *(s16 *)(m + 0x6ecc) = (s16)prod;
    *(s16 *)(m + 0x6ed4) = *(s16 *)(m + 0x6ecc);

    if (func_ov000_0216b154()) {
        cc = *(s16 *)(m + 0x6ecc);
        if (cc > 0) {
            *(s16 *)(m + 0x6ecc) = 1;
            *(s16 *)(m + 0x6ed4) = *(s16 *)(m + 0x6ecc);
        }
    }

    unit[1] = saved1;
    unit[2] = saved2;
}

s32 func_020d18e8(s32 *arg0) {
    M2C_UNK func_020a7310(s32);
    func_020a7310(*arg0);
    return 0;
}

void func_020d18fc(s32 a) {
    extern void **gCurrentMap;
    u8 *p = (u8 *)*gCurrentMap + 0x67a4 + a * 0x8c;
    if ((u32)M2C_FIELD(p, u16 *, 0x20) < 0xffff) M2C_FIELD(p, u16 *, 0x20)++;
}

s32 func_020d1938(s32 a){extern void **gCurrentMap;u8 result;u8 *p=(u8 *)*gCurrentMap+0x67a4+a*0x8c;if(!p[0x1e])return 0;if(M2C_FIELD(p,u16 *,0x1a)==0)result=1;else result=0;return result;}

u8 func_020d1980(s32 a){extern void **gCurrentMap;return ((u8 *)*gCurrentMap+a*0x8c)[0x67c2]!=0;}

s32 func_020d19b4(s32 a){extern void **gCurrentMap;return (u8)(((u8 *)*gCurrentMap+a*0x8c)[0x67c2]==1);}

u8 func_020d19e8(s32 a){extern void **gCurrentMap;return ((u8 *)*gCurrentMap+a*0x8c)[0x67c2]==2;}

s32 func_020d1a1c(s32 arg0) {
 s32 func_0208485c();
 extern M2C_UNK data_02168f08;
 if(M2C_FIELD(&data_02168f08,u8 *,4)==0)return 1;
 if(func_020d19b4(arg0))return 1;
 if(func_0208485c() && func_020d19e8(arg0))return 1;
 return 0;
}

u8 func_020d1a74(void) {
    s32 func_020a334c();
    u8 var_r0;

    if (func_020a334c() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020d1a90(void) {
 extern void **gCurrentMap;
 u16 n=M2C_FIELD(*gCurrentMap,u16 *,0x52a4);
 do { n++; if(n==5)n=1; } while(!func_020d1938(n));
 return n<M2C_FIELD(*gCurrentMap,u16 *,0x52a4);
}

s32 func_020d1afc(void) {
    s32 func_020d1938(s32);
    s32 var_r5;
    s32 var_r6;

    var_r6 = 1;
    var_r5 = 0;
    do {
        if ((func_020d1938(var_r6) != 0) && (func_020d19b4(var_r6) != 0)) {
            var_r5 = 1;
        }
        var_r6 += 1;
    } while (var_r6 < 5);
    return var_r5;
}

s32 func_020d1b40(void) {
    s32 func_020d19b4(s32);
    s32 func_020d3214(s32);
    s32 var_r4;

    var_r4 = 1;
loop_1:
    if ((func_020d19b4(var_r4) != 0) && (func_020d3214(var_r4) != 0)) {
        return 1;
    }
    var_r4 += 1;
    if (var_r4 >= 5) {
        return 0;
    }
    goto loop_1;
}

void func_020d1b80(void){
void func_020bf85c(void);void func_02091c20(s32,s32);extern void **gCurrentMap;
s32 active=func_020d1afc();s32 one=1;u8 *p;
do {
M2C_FIELD(*gCurrentMap,u16 *,0x52a4)++;
if(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)==5){func_020bf85c();M2C_FIELD(*gCurrentMap,u16 *,0x52a4)=one;if(active)func_02091c20(one,one);}
}while(!func_020d1938(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)));
p=*gCurrentMap;M2C_FIELD(p+M2C_FIELD(p,u16 *,0x52a4)*0x8c,s32 *,0x682c)=0;
}

void func_020d1c38(void) {
    extern void **gCurrentMap;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C0) = 0;
}

void func_020d1c58(void){
extern void **gCurrentMap;extern u16 data_ov000_021aeef4[];
void func_020cd8a8(void);void func_020cd754(s32);void func_020d0270(void);void func_020cea28(void);
M2C_FIELD(*gCurrentMap,u16 *,0x52a6)=M2C_FIELD(*gCurrentMap,u16 *,0x52a4)<<5;
M2C_FIELD(*gCurrentMap,u16 *,0x52a8)=data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)];
M2C_FIELD(*gCurrentMap,u16 *,0x52b6)=M2C_FIELD(*gCurrentMap,u16 *,0x52a4);
func_020cd8a8();func_020cd754((u8)M2C_FIELD(*gCurrentMap,u16 *,0x52b8));func_020d0270();func_020cea28();
}

void func_020d1ce0(void){
extern void **gCurrentMap;void func_020d2d80(s32);void func_020d2d60(s32);void func_020d2d90(s32);s32 func_020d0590(s32);void func_020cf498(s16,s16);void func_020d1d9c(void);u8 *p;
M2C_FIELD(*gCurrentMap,u16 *,0x52c0)=0;
func_020d2d80(M2C_FIELD(*gCurrentMap,u16 *,0x52a4));
func_020d2d60(M2C_FIELD(*gCurrentMap,u16 *,0x52a4));
func_020d2d90(M2C_FIELD(*gCurrentMap,u16 *,0x52a4));
if(func_020d0590(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))){
p=*gCurrentMap;p=p+0x67a4+M2C_FIELD(p,u16 *,0x52a4)*0x8c;func_020cf498(p[0x2d],p[0x2e]);}
func_020d1d9c();
}

void func_020d1d9c(void) {
 void func_020c0a1c(s32); void func_020c09c0(s32);
 extern void **gCurrentMap;
 func_020c0a1c(3);
 func_020c09c0(M2C_FIELD(*gCurrentMap,u16 *,0x52a4));
}

/* Updates, for each of the four playable slots (i = 1..4), the cached display state (idle/busy flags etc.) that drives sprite selection for that slot. */
void func_020d1dc8(void) {
    extern void **gCurrentMap;
    extern u8 data_0212616c[];
    s32 func_020cd6d4(void);
    s32 func_020a8ae0(u16, s32);
    s32 func_020cd728(void);
    s32 i;
    s32 state, flag, other;
    i = 1;
    do {
        state = 0;
        flag = state;
        other = state;
        if (func_020cd6d4()) state = func_020a8ae0(M2C_FIELD(*gCurrentMap, u16 *, 0x5142), i);
        if (state == 0) state = data_0212616c[((u32)(M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, s32 *, 0x6810) << 24) >> 24) * 0x9c + 0x23];
        if (func_020cd728()) state = i;
        switch (state) {
        case 1:
        case 3:
            flag = 0;
            break;
        case 2:
        case 4:
        case 5:
            flag = 1;
            break;
        }
        switch (M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, u8 *, 0x67ca)) {
        case 1:
        case 3:
            other = 1;
            break;
        case 2:
        case 4:
            other = 0;
            break;
        }
        M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, u8 *, 0x67cb) = state;
        M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, u8 *, 0x67cd) = flag;
        M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, u8 *, 0x67cc) = other;
        if (func_020cd728()) M2C_FIELD((u8 *)*gCurrentMap + i * 0x8c, u8 *, 0x67c3) = 2;
        i++;
    } while (i < 5);
}

void func_020d1f2c(void) {
    extern void **gCurrentMap;
    extern M2C_UNK data_02168f08;
    s32 func_020cfb94(void);
    s32 func_020a23a4(s32, s32);
    s32 func_020a23b4(s32, s32);
    s32 func_020a2360(s32);
    s32 func_020a8bd8(s32, s32);
    s32 func_020a22fc(void);
    s32 func_020a2390(s32);
    void func_020a3550(s32, s32);
    s32 func_020a2370(s32);
    s32 func_020a2380(s32);
    s32 func_020cd6d4(void);
    void func_020d2168(void);
    void func_020d1dc8(void);
    s32 func_020d3154(s32);

    int dummy_unused = 0;

    {
        s32 r5 = 4 - func_020cfb94();
        if (r5 >= 1) {
            do {
                func_020a23a4(5 - r5, 0);
                r5--;
            } while (r5 >= 1);
        }
    }

    {
        u8 *p = (u8 *)*gCurrentMap + 0x67a4;
        p[0xaa] = (u8)func_020a23b4(1, (s32)*gCurrentMap + 0x3a4);
        p[0x136] = (u8)func_020a23b4(2, (s32)*gCurrentMap + 0x3a4);
        p[0x1c2] = (u8)func_020a23b4(3, (s32)*gCurrentMap + 0x3a4);
        p[0x24e] = (u8)func_020a23b4(4, (s32)*gCurrentMap + 0x3a4);
    }

    {
        s32 r8;
        s32 r9 = 0x8c;
        for (r8 = 1; r8 < 5; r8++, r9 += 0x8c) {
            u8 *buf = (u8 *)*gCurrentMap;
            u8 *r10 = (u8 *)*gCurrentMap + 0x67a4 + r9;

            r10[0x1d] = (u8)func_020a2360(r8);

            if (buf[r9 + 0x67c2] != 0) {
                s32 ret = func_020a22fc();
                func_020a8bd8(r8, ret);
            } else {
                func_020a8bd8(r8, 0);
            }

            func_020a3550(r8, func_020a2390(r8));

            r10 = (u8 *)*gCurrentMap + 0x67a4 + r9;
            r10[0x26] = (u8)func_020a2370(r8);

            r10 = (u8 *)*gCurrentMap + 0x67a4 + r9;
            r10[0x32] = (u8)func_020a2380(r8);

            if (func_020cd6d4() != 0) {
                buf[r9 + 0x67ce] = 2;
            } else {
                u16 val = M2C_FIELD(&data_02168f08, u16 *, 0xc);
                buf[r9 + 0x67ce] = (u8)((val >> 3) & 7);
            }
        }
    }

    func_020d2168();
    func_020d1dc8();

    {
        u16 val = M2C_FIELD(&data_02168f08, u16 *, 0xc);
        if (((val << 18) >> 31) == 0) {
            M2C_FIELD(&data_02168f08, u16 *, 0xc) = val & ~(u16)0x1000;
        }
    }

    {
        u8 *buf = (u8 *)*gCurrentMap;
        s32 r4 = 0xe;
        s32 r5v;
        for (r5v = 1; r5v < 256; r5v++, r4 += 0xe) {
            s32 low6 = buf[r4 + 0x59a4] & 0x3f;
            if (low6 != 0) {
                func_020d3154((r5v >> 6) + 1);
            }
        }
    }

    (void)dummy_unused;
    return;
}

void func_020d2168(void) {

}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_strength_reduction off
void func_020d216c(void){
extern void **gCurrentMap;extern M2C_UNK data_02168f08;
void func_020a338c(s32,s32);void func_020a3428(s32,s32);void func_020a33f0(s32,s32);void func_020a3550(s32,s32);void func_020a3184(s32,s32);void func_020d31f0(s32,u8);void func_020d327c(s32,s32);void func_020d2d60(s32);void func_020d33c4(void);
s32 offset; s32 player;
s32 i;player=1;offset=140;
do{
M2C_FIELD((*gCurrentMap+offset),s32*,0x67a4)=M2C_FIELD(&data_02168f08,s32*,20);
M2C_FIELD((*gCurrentMap+offset),s32*,0x67a8)=0;
M2C_FIELD((*gCurrentMap+offset),s32*,0x67b0)=0;
M2C_FIELD((*gCurrentMap+offset),u8*,0x67bc)=0;
M2C_FIELD((*gCurrentMap+offset),u8*,0x67bd)=0;
M2C_FIELD((*gCurrentMap+offset),u8*,0x67c0)=0;
M2C_FIELD((*gCurrentMap+offset),u16*,0x67be)=0;
M2C_FIELD((*gCurrentMap+offset),u16*,0x67c4)=0;
M2C_FIELD((*gCurrentMap+offset),u16*,0x67c6)=0;
M2C_FIELD((*gCurrentMap+offset),u8*,0x67c1)=0;
M2C_FIELD((*gCurrentMap+offset),u8*,0x67c2)=0;
M2C_FIELD((*gCurrentMap+offset),u8*,0x67c3)=0;
M2C_FIELD((*gCurrentMap+offset),s32*,0x6818)=0;
M2C_FIELD((*gCurrentMap+offset),s32*,0x681c)=0;
M2C_FIELD((*gCurrentMap+offset),s32*,0x6820)=0;
M2C_FIELD((*gCurrentMap+offset),s32*,0x6824)=0;
M2C_FIELD((*gCurrentMap+0x67a4)+offset,u32*,0x6c)&=~255;
func_020a338c(player,0);func_020a3428(player,0);func_020a33f0(player,0);
M2C_FIELD((*gCurrentMap+0x67a4)+offset,u32*,0x6c)&=~0x3c000;
func_020a3550(player,0);func_020a3184(player,0);
M2C_FIELD((*gCurrentMap+offset),u8*,0x67ca)=1;M2C_FIELD((*gCurrentMap+offset),u8*,0x67cb)=0;
func_020d31f0(player,0);func_020d327c(player,0);
M2C_FIELD((*gCurrentMap+offset),u8*,0x67d5)=0;
for(i=0;i<27;i++){M2C_FIELD(i+(offset+*gCurrentMap),u8*,0x67d7)=0;M2C_FIELD(i+(offset+*gCurrentMap),u8*,0x67f2)=0;}
func_020d2d60(player);
M2C_FIELD((*gCurrentMap+offset),s32*,0x6828)=0;M2C_FIELD((*gCurrentMap+offset),s32*,0x682c)=0;
player++;offset+=140;
}while(player<5);func_020d33c4();
}
#pragma pop
s32 func_020d243c(s32 a){extern void **gCurrentMap;return (u8)((((u8 *)*gCurrentMap+a*0x8c)[0x67cf]&0x80)==0);}

