/* 21 functions from 0x021E3210 to 0x021E41AC (ov002), found by ds-decomp. */
#include "common.h"

void func_ov002_021e3210(void *arg0) {
    (void)arg0;
}

void func_ov002_021e3578(void *arg0) {
    s8 func_ov002_021e30d0(void *);
    extern u8 gPlayerSettings;
    s32 temp_r0_2;
    s32 var_r10;
    s32 var_r11;
    s32 var_r2;
    s32 var_r6;
    u8 *var_r5;
    u8 temp_r9;
    u8 temp_r9_2;
    u8 temp_r9_3;
    u8 temp_r9_4;
    void *var_lr;

    var_r2 = 0;
    do {
        M2C_FIELD(arg0 + var_r2 * 4, s16 *, 0x4A) = -1;
        var_r2 = var_r2 + 1;
    } while (var_r2 < 5);
    temp_r0_2 = func_ov002_021e30d0(arg0 + 0x36);
    var_r6 = 0;
    var_lr = arg0 + 0x4A;
    if (temp_r0_2 <= 0) {
        return;
    }
    var_r5 = arg0 + 0x38;
    do {
        temp_r9 = *var_r5;
        if ((((u32) (temp_r9 << 0x18) >> 0x1F) == 0) || (((u32) (temp_r9 << 0x19) >> 0x1F) != 0)) {
            temp_r9_2 = M2C_FIELD(arg0, u8 *, 0x64);
            if (temp_r9_2 == 0) {
                var_r10 = 1;
            } else {
                var_r10 = 0;
            }
            if (temp_r9_2 == 0) {
                var_r11 = 1;
            } else {
                var_r11 = 0;
            }
            if ((M2C_FIELD((M2C_FIELD(((var_r11 * 0x18) + (s32) &gPlayerSettings), s32 *, 4) + (M2C_FIELD(((var_r10 * 0x18) + (s32) &gPlayerSettings), u8 *, 0x13) * 4)), s32 *, 0x1C) != 0) || (((u32) (*var_r5 << 0x19) >> 0x1F) != 0)) {
                M2C_FIELD(var_lr, s16 *, 0) = (s16) (M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), void **, 4), u8 *, 2) + M2C_FIELD((arg0 + (var_r6 * 4)), s16 *, 0x36));
                temp_r9_3 = (M2C_FIELD(var_lr, u8 *, 2) & ~7) | (((u32) (*var_r5 << 0x1D) >> 0x1D) & 7);
                M2C_FIELD(var_lr, u8 *, 2) = temp_r9_3;
                temp_r9_4 = (temp_r9_3 & ~0x38) | ((u32) (((u32) (*var_r5 << 0x1A) >> 0x1D) << 0x1D) >> 0x1A);
                M2C_FIELD(var_lr, u8 *, 2) = temp_r9_4;
                M2C_FIELD(var_lr, u8 *, 2) = (u8) ((temp_r9_4 & ~0x40) | ((u32) (((u32) (*var_r5 << 0x19) >> 0x1F) << 0x1F) >> 0x19));
                var_lr = var_lr + 4;
            }
        }
        var_r6 = var_r6 + 1;
        var_r5 = var_r5 + 4;
    } while (var_r6 < temp_r0_2);
}

void func_ov002_021e36d0(void *a) {
s8 func_ov002_021e30d0(void *);void *p;s32 i;
M2C_FIELD(a,s8 *,102)=func_ov002_021e30d0(a+34);if(!M2C_FIELD(a,u8 *,101))return;
for(p=a+34,i=0;i<5;i++,p+=4)M2C_FIELD(p,u8 *,2)&=~7;
{void *q; s32 j;for(q=a+54,j=0;j<5;j++,q+=4)M2C_FIELD(q,u8 *,2)&=~7;}
{void *q; s32 j;for(q=a+74,j=0;j<5;j++,q+=4)M2C_FIELD(q,u8 *,2)&=~7;}
{void *q; s32 j;for(q=a+38,j=1;j<5;j++,q+=4)M2C_FIELD(q,s16 *,0)=-1;}
}

s32 func_ov002_021e377c(void *arg0) {
    extern u8 data_ov002_021f30f4;
    extern u8 data_ov002_021f3103;
    u8 *p;
    s32 i;
    s32 min;
    s32 max;
    s32 a;
    s32 b;
    s16 t;
    s32 sum;
    u8 temp;

    temp = M2C_FIELD(arg0, u8 *, 0x64);
    max = 0;
    if (temp == 0) {
        a = 1;
    } else {
        a = 0;
    }
    if (temp == 0) {
        b = 1;
    } else {
        b = 0;
    }
    min = -1;
    if (M2C_FIELD((u8 *)M2C_FIELD(&data_ov002_021f30f4, void **, b * 0x18) + M2C_FIELD(&data_ov002_021f3103, u8 *, a * 0x18) * 4, s32 *, 0x1c) == 0) {
        for (p = arg0 + 0x36, i = 0; i < 5; i++, p += 4) {
            t = M2C_FIELD(p, s16 *, 0);
            if (t == -1) break;
            if (min == -1) {
                min = t;
            } else if (min >= t) {
                min = t;
            }
            sum = t + M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), void **, 4), u8 *, 2);
            if (max <= sum) {
                max = sum;
            }
        }
    }
    for (p = arg0 + 0x4a, i = 0; i < 5; i++, p += 4) {
        t = M2C_FIELD(p, s16 *, 0);
        if (t == -1) break;
        if (min == -1) {
            min = t;
        } else if (min >= t) {
            min = t;
        }
        if (max <= t) {
            max = t;
        }
    }
    if (min == -1) {
        return 0;
    }
    sum = max - min;
    if (sum <= 1) {
        sum = 1;
    }
    return sum;
}

void func_ov002_021e3890(s32 arg0) {
    extern u8 gPlayerSettings;
    s32 var_lr;
    s32 var_r4;
    u8 *var_r5;
    s32 var_r6;
    u8 temp_r2;
    var_lr = 0;
    var_r5 = &gPlayerSettings;
    var_r4 = arg0;
    do {
        if (var_lr == 0) var_r6 = 1;
        else var_r6 = 0;
        M2C_FIELD(var_r4, u8 *, 0x64) = var_lr;
        M2C_FIELD(var_r4, s32 *, 0x60) = var_r6 * 0x68 + arg0;
        temp_r2 = M2C_FIELD(M2C_FIELD(var_r5, void **, 4), u8 *, 0x3C);
        var_lr += 1;
        var_r5 += 0x18;
        M2C_FIELD(var_r4, u8 *, 0x65) = temp_r2;
        var_r4 += 0x68;
    } while (var_lr < 2);
}

/* Rebuild both players' status panels: the two 0x68-byte panel objects at p
   and p+0x68 take their value and thresholds from the versus player settings,
   then have their icons, positions and gauges refreshed. */
void PlayerPanels_Init(void *p){
void func_ov002_021e2eb8(void *,s32,s32);void func_ov002_021e3044(void *,s32,s32);
void func_ov002_021e3100(void *);void func_ov002_021e3210(void *);void func_ov002_021e3578(void *);
extern u8 gPlayerSettings;
func_ov002_021e2eb8(p,M2C_FIELD(M2C_FIELD(&gPlayerSettings,void **,4)+M2C_FIELD(&gPlayerSettings,u8 *,0x13)*4,s32 *,0x2c),0);
func_ov002_021e2eb8(p+0x68,M2C_FIELD(M2C_FIELD(&gPlayerSettings,void **,0x1c)+M2C_FIELD(&gPlayerSettings,u8 *,0x2b)*4,s32 *,0x2c),0);
func_ov002_021e3044(p,(M2C_FIELD(&gPlayerSettings,u8 *,0xd)+9)/10,(M2C_FIELD(&gPlayerSettings,u8 *,0xe)+9)/10);
func_ov002_021e3044(p+0x68,(M2C_FIELD(&gPlayerSettings,u8 *,0x25)+9)/10,(M2C_FIELD(&gPlayerSettings,u8 *,0x26)+9)/10);
func_ov002_021e3100(p);func_ov002_021e3100(p+0x68);
func_ov002_021e3210(p);func_ov002_021e3210(p+0x68);
func_ov002_021e3578(p);func_ov002_021e3578(p+0x68);
func_ov002_021e36d0(p);func_ov002_021e36d0(p+0x68);
}

M2C_UNK func_ov002_021e39e8(s32 *p) {
u32 v;
if(*p&1){*(volatile u16 *)0x4000304|=0x8000;func_020033f4();func_02003124(4);func_02003104(8);v=0x80330000;*(volatile u32 *)0x4000064=v;}
else{*(volatile u16 *)0x4000304&=~0x8000;func_020033e0();func_020031cc(8);func_02003104(4);v=0x80320000;*(volatile u32 *)0x4000064=v;}return ++*p;
}

#pragma opt_strength_reduction off
M2C_UNK func_ov002_021e3a7c(s32 *p) {
    extern u8 gPlayerSettings;
    extern u8 data_ov002_021f30f4;
    void func_02082098(s32, s32);
    void func_02082104(s32, s32);
    void func_02082134(s32, s32);
    s32 i;
    if (*p & 1) {
        func_02082098(2, 0);
        func_02082098(3, 0);
        func_02082104(2, 15);
        func_02082104(3, 14);
        i = M2C_FIELD(&gPlayerSettings, u8 *, 1);
        if (M2C_FIELD(M2C_FIELD(&data_ov002_021f30f4, void **, i * 24), u8 *, 0x3D) != 2) {
            func_02082134(3, 1);
        } else {
            func_02082134(3, 0);
        }
    } else {
        func_02082098(2, 2);
        func_02082098(3, 2);
        func_02082104(2, 31);
        func_02082104(3, 30);
        if (M2C_FIELD(&gPlayerSettings, u8 *, 1) == 0) {
            i = 1;
        } else {
            i = 0;
        }
        if (M2C_FIELD(M2C_FIELD(&data_ov002_021f30f4, void **, i * 24), u8 *, 0x3D) != 2) {
            func_02082134(3, 1);
        } else {
            func_02082134(3, 0);
        }
    }
}
#pragma opt_strength_reduction off
void func_ov002_021e3b7c(M2C_UNK *p) {
extern u32 gCur3DSpriteEngine, data_027e00c4;
extern u8 data_027e008c[];
s32 x,y,tx,ty; u32 old; u16 v;
if(*p&1)return;
old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;
for(y=0,ty=0;y<192;y+=64,ty+=8){
v=(u16)((y&255)|0xc00);
for(tx=0,x=0;tx<32;tx+=8,x+=64)
func_01ffaacc((u16)(x&511),v,(u16)(((tx+(ty<<5))&1023)|0xf000),data_027e008c,0);
}
gCur3DSpriteEngine=old;
}
#pragma opt_strength_reduction on
void func_ov002_021e3c5c(void) {
    M2C_UNK func_ov002_021e39e8(M2C_UNK *);
    extern M2C_UNK data_ov002_021f3014;
    func_ov002_021e39e8(&data_ov002_021f3014);
}

void func_ov002_021e3c70(void) {
    M2C_UNK func_ov002_021e3a7c(M2C_UNK *);
    extern M2C_UNK data_ov002_021f3014;
    func_ov002_021e3a7c(&data_ov002_021f3014);
}

void func_ov002_021e3c84(void) {

    extern M2C_UNK data_ov002_021f3014;
    func_ov002_021e3b7c(&data_ov002_021f3014);
}

void func_ov002_021e3c98(s32 *arg0) {M2C_UNK func_020033e0(void);M2C_UNK func_020033f4(void);void func_02082104(s32,s32);void func_02082134(s32,s32);void func_0209cce4(s32,s32);
extern volatile u16 *data_027e00c0;extern u32 gCur3DSpriteEngine;extern u32 data_027e00c4;
func_020033e0();func_020033f4();
data_027e00c0[0]=(u16)((data_027e00c0[0]&~0x7)|0x3);
data_027e00c0[0]=(u16)(data_027e00c0[0]&~0x10);
data_027e00c0[0]=(u16)(data_027e00c0[0]&~0x20);
data_027e00c0[0]=(u16)(data_027e00c0[0]&~0x40);
data_027e00c0[0]=(u16)(data_027e00c0[0]|0x80);
data_027e00c0[0]=(u16)(data_027e00c0[0]|0x100);
data_027e00c0[1]=(u16)((data_027e00c0[1]&~0xC0)|0x40);
data_027e00c0[1]=(u16)(data_027e00c0[1]&~0x100);
{u32 old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;
data_027e00c0[6]=(u16)((data_027e00c0[6]&~0x3C)|0x4);
data_027e00c0[6]=(u16)(data_027e00c0[6]|0x80);
func_02082104(3,0);func_02082134(3,1);gCur3DSpriteEngine=old;}
*arg0=0;
func_0209cce4((s32)func_ov002_021e3c5c,2);
func_0209cce4((s32)func_ov002_021e3c70,7);
func_0209cce4((s32)func_ov002_021e3c84,9);
}

void func_ov002_021e3dd4(void) {
    M2C_UNK func_0209cd00(void (*)(void));
    func_0209cd00(func_ov002_021e3c5c);
    func_0209cd00(func_ov002_021e3c70);
    func_0209cd00(func_ov002_021e3c84);
}

s32 func_ov002_021e3e00(s32 *arg0) {
    return *arg0 & 1;
}

void func_ov002_021e3e0c(void *arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u8 arg8, u8 arg9, u8 argA, u8 argB) {
    M2C_FIELD(arg0, s16 *, 0) = arg1;
    M2C_FIELD(arg0, s16 *, 2) = arg2;
    M2C_FIELD(arg0, s16 *, 4) = arg3;
    M2C_FIELD(arg0, u16 *, 0xC) = arg4;
    M2C_FIELD(arg0, u16 *, 0xE) = arg5;
    M2C_FIELD(arg0, u16 *, 0xA) = arg6;
    M2C_FIELD(arg0, u16 *, 8) = arg7;
    M2C_FIELD(arg0, u8 *, 0x11) = arg8;
    M2C_FIELD(arg0, u8 *, 0x10) = arg9;
    M2C_FIELD(arg0, u8 *, 0x12) = argA;
    M2C_FIELD(arg0, u8 *, 0x13) = argB;
    M2C_FIELD(arg0, s16 *, 6) = 0;
}

void func_ov002_021e3e64(void *arg0) {
    u16 temp_r2;

    temp_r2 = M2C_FIELD(arg0, u16 *, 6);
    if ((u32) temp_r2 < (u32) M2C_FIELD(arg0, u16 *, 8)) {
        M2C_FIELD(arg0, u16 *, 6) = (u16) (temp_r2 + 1);
    }
}

void func_ov002_021e3e7c(void *p) {
s32 func_0207ca38(s32,s32,s32,s32,s32);s32 a,b;
if(M2C_FIELD(p,u16 *,6)>=M2C_FIELD(p,u16 *,8))return;
a=func_0207ca38(0,M2C_FIELD(p,u8 *,16),0,M2C_FIELD(p,u16 *,6),M2C_FIELD(p,u16 *,8));
b=func_0207ca38(4,M2C_FIELD(p,u16 *,12),M2C_FIELD(p,u16 *,14),M2C_FIELD(p,u16 *,6),M2C_FIELD(p,u16 *,8));
func_02087048(M2C_FIELD(p,u8 *,17),(u8)a);func_0208718c();
func_020872c8(M2C_FIELD(p,u8 *,18)?M2C_FIELD(p,s16 *,0):-M2C_FIELD(p,s16 *,0),M2C_FIELD(p,s16 *,2),M2C_FIELD(p,s16 *,4),b,32,M2C_FIELD(p,u16 *,10));
func_02087048(0,31);
}

void func_ov002_021e3f28(void) {

}

void func_ov002_021e3f2c(void *arg0, s32 arg1) {
    extern u8 data_ov002_021f2f44[];
    extern u8 data_ov002_021f3105[];
    extern s8 data_ov002_021f2d4c[];
    s32 func_ov002_021e377c(void *);
    s32 func_ov002_021e41ac(void *, s32);
    s32 RandomIntRange(s32, s32);
    s8 t;

    M2C_FIELD(arg0, u8 *, 3) = (M2C_FIELD(arg0, u8 *, 3) & ~0xF) | ((u8)arg1 & 0xF);
    M2C_FIELD(arg0, s8 *, 1) = func_ov002_021e377c((s32)data_ov002_021f2f44 + arg1 * 0x68);
    M2C_FIELD(arg0, s8 *, 0) = 0;
    M2C_FIELD(arg0, s8 *, 5) = 0x10;
    M2C_FIELD(arg0, s8 *, 2) = 0;
    M2C_FIELD(arg0, u8 *, 3) = M2C_FIELD(arg0, u8 *, 3) & ~0xF0;
    M2C_FIELD(arg0, s8 *, 4) = func_ov002_021e41ac(arg0, 1);
    t = M2C_FIELD(arg0, s8 *, 4);
    switch (t) {
    case 0:
        M2C_FIELD(arg0, s8 *, 4) = -1;
        return;
    case 1:
        M2C_FIELD(arg0, s8 *, 4) = data_ov002_021f2d4c[data_ov002_021f3105[arg1 * 0x18] * 3 + RandomIntRange(0, 1)];
        return;
    case 2:
        M2C_FIELD(arg0, s8 *, 4) = data_ov002_021f2d4c[data_ov002_021f3105[arg1 * 0x18] * 3 + 2];
        return;
    default:
        M2C_FIELD(arg0, s8 *, 4) = -1;
        return;
    }
}

s32 func_ov002_021e4034(void *arg0) {
    extern u8 data_ov002_021f30fd[];
    extern u8 data_ov002_021f3104[];
    extern u8 data_ov002_021f3105[];
    u32 i;
    s32 j;
    u8 alive;
    s32 a;

    j = ((u32)(M2C_FIELD(arg0, u8 *, 3) << 0x1C) >> 0x1C) * 0x18;
    i = (u32)(M2C_FIELD(arg0, u8 *, 3) << 0x1C) >> 0x1C;
    if (data_ov002_021f3105[j] == 0) {
        return 0;
    }
    alive = data_ov002_021f3104[j];
    if (alive == 0 || data_ov002_021f3104[(i == 0 ? 1 : 0) * 0x18] == 0) {
        if (alive != 0) {
            return 0;
        }
        if ((data_ov002_021f30fd[j] + 9) / 10 >= (data_ov002_021f30fd[(i == 0 ? 1 : 0) * 0x18] + 9) / 10 + 3) {
            return 0;
        }
        return 2;
    }
    a = (data_ov002_021f30fd[j] + 9) / 10;
    if (a <= 4) {
        if ((data_ov002_021f30fd[(i == 0 ? 1 : 0) * 0x18] + 9) / 10 <= 4) {
            return 2;
        }
    }
    if (a + 4 <= (data_ov002_021f30fd[(i == 0 ? 1 : 0) * 0x18] + 9) / 10) {
        return 2;
    }
    return 0;
}

