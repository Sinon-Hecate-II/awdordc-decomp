/* 16 functions from 0x0206DF88 to 0x0206EEB4 (main), found by ds-decomp. */
#include "common.h"

double func_0206df88(double x,double y) { ((u32 *)&x)[1] = (((u32 *)&x)[1] & 0x7fffffff) | (((u32 *)&y)[1] & 0x80000000); return x; }

double func_0206dfb0(double x) { ((u32 *)&x)[1] &= 0x7fffffff; return x; }

double func_0206dfd0(double x,s32 *exp) {
 double func_02070658(double,double);
 s32 hi,word,lo;
 word=((s32 *)&x)[1]; hi=word & 0x7fffffff; *exp=0; lo=((s32 *)&x)[0];
 if(hi>=0x7ff00000 || (hi|lo)==0) return x;
 if(hi<0x100000) { x=func_02070658(x,18014398509481984.0); *exp=-54; word=((s32 *)&x)[1]; hi=word & 0x7fffffff; }
 *exp += (hi>>20)-1022;
 ((u32 *)&x)[1]=(word & 0x800fffff) | 0x3fe00000;
 return x;
}

double func_0206e08c(double x, s32 n) {
    u32 *px = (u32 *)&x;
    u32 hx = px[1];
    u32 lx = px[0];
    s32 k = (s32)((hx & 0x7ff00000U) >> 20);
    if (k == 0) {
        if (((hx & 0x7fffffffU) | lx) == 0) return x;
        x = func_02070658(x, 18014398509481984.0);
        px = (u32 *)&x;
        hx = px[1];
        lx = px[0];
        k = (s32)(((hx & 0x7ff00000U) >> 20) - 54);
        n += 54;
    }
    if (k == 0x7ff) return func_02070134(x, x);
    k += n;
    if (k > 0x7fe) {
        double h = 1.0e300;
        return func_02070658(func_0206df88(h, x), h);
    }
    if (k <= -54) {
        if (n > 50000) {
            double h = 1.0e-300;
            return func_02070658(func_0206df88(h, x), h);
        } else {
            double h = 1.0e-300;
            return func_02070658(func_0206df88(h, x), x);
        }
    }
    px[1] = (hx & 0x800fffffU) | ((k + 54) << 20);
    return func_02070658(x, 5.551115123125783e-17);
}

void func_0206e2d8(void) {
    M2C_UNK func_0206ce00();
    func_0206ce00();
}

s32 func_0206e2e4(u8 *p,s32 i) {
 u8 *q=p+5+i; u8 *end;
 if(*q>5) return 1; if(*q<5) return -1;
 q++; end=p+5+p[4];
 while(q<end) { if(*q!=0)return 1; q++; }
 i--; if(M2C_FIELD(p+i,u8 *,5)&1)return 1; return -1;
}

#pragma opt_dead_code off
void func_0206e350(u8 *p,s32 n) {
 u8 *start=p+5; u8 *q=start+n-1;
 for(;;) {
 if(*q<9) { ++*q; return; }
 if(q==start) { *q=1; M2C_FIELD(p,s16 *,2) += 1; return; }
 *q--=0;
 }
}
#pragma opt_dead_code reset
void func_0206e39c(void) {

}

void func_0206e3a0(u8 *p,s32 n) {
 s32 r;
 if(n<=0)return; if(n>=p[4])return;
 r=func_0206e2e4(p,n); p[4]=n; if(r<0)return;
 func_0206e350(p,n);
}

u64 func_02072088(u64,u64);
u64 func_02072094(u64,u64);
void func_0206e3e0(u8 *p, u64 value) {
    u8 *lo;
    u8 *hi;
    p[0] = 0;
    p[4] = 0;
    while (value) {
        p[5 + p[4]++] = value % 10ULL;
        value /= 10ULL;
    }
    lo = p + 5;
    hi = lo + p[4] - 1;
    while (lo < hi) {
        u8 t = *lo;
        *lo++ = *hi;
        *hi-- = t;
    }
    *((s16 *)(p + 2)) = (s16)(p[4] - 1);
}

void func_0206e4ac(u8 *arg0, u8 *arg1, u8 *arg2) {
    u8 buf[0x40];
    u32 acc;
    s32 total;
    u8 *cursor;
    u8 *endmark;
    s32 t;
    s32 idx;
    s32 cnt;
    s32 lim;
    s32 n;
    u8 *base1;
    u8 *base2;
    u8 *p1;
    u8 *p2;
    u8 tt;

    acc = 0;
    total = arg1[4] + arg2[4] - 1;
    cursor = buf + total + 1;
    endmark = cursor;
    arg0[0] = 0;
    if (total > 0) {
        base1 = arg1 + 5;
        base2 = arg2 + 5;
        do {
            t = arg2[4] - 1;
            idx = total - t - 1;
            if (idx < 0) {
                idx = 0;
                t = total - 1;
            }
            cnt = t + 1;
            lim = arg1[4] - idx;
            if (cnt > lim) {
                cnt = lim;
            }
            p1 = base1 + idx;
            p2 = base2 + t;
            n = cnt;
            while (n > 0) {
                u8 a = *p1++;
                u8 b = *p2--;
                n--;
                acc += (u32)a * (u32)b;
            }
            total--;
            cursor--;
            *cursor = (u8)(acc % 10);
            acc = acc / 10;
        } while (total > 0);
    }
    *(s16 *)(arg0 + 2) = *(s16 *)(arg1 + 2) + *(s16 *)(arg2 + 2);
    if (acc != 0) {
        cursor--;
        *cursor = (u8)acc;
        *(s16 *)(arg0 + 2) = *(s16 *)(arg0 + 2) + 1;
    }
    n = 0;
    while (n < 0x20 && cursor < endmark) {
        arg0[5 + n] = *cursor++;
        n++;
    }
    arg0[4] = (u8)n;
    if (cursor >= endmark) {
        return;
    }
    tt = cursor[0];
    if (tt < 5) {
        return;
    }
    if (tt == 5) {
        u8 *p = cursor + 1;
        while (p < endmark) {
            if (*p != 0) {
                goto call;
            }
            p++;
        }
        if (!(cursor[-1] & 1)) {
            return;
        }
    }
call:
    func_0206e350(arg0, arg0[4]);
}

void func_0206e630(u8 *p,s8 *s,s16 e) {
 s32 n=0;
 M2C_FIELD(p,s16 *,2)=e; p[0]=0;
 while(n<32 && *s) { p[5+n++]=*s++-'0'; }
 p[4]=n;
 if(*s==0)return;
 if(*s<5)return;
 if(*s<=5) {
 {s32 c=s[1]; s++;
 while(c) { if(c!='0')goto round; c=*++s; }}
 n--; if(!(M2C_FIELD(p+n,u8 *,5)&1))return;
 }
round:
 func_0206e350(p,p[4]);
}

void func_0206e6cc(u16 *arg0, s32 arg1) {
    void func_0206e4ac(u8 *, u8 *, u8 *);
    void func_0206e630(u8 *, s8 *, s16);
    extern s8 data_021005fc[];
    extern s8 data_0210062c[];
    extern s8 data_02100654[];
    extern s8 data_0210066c[];
    extern s8 data_0210067c[];
    extern s8 data_02100684[];
    extern s8 data_0210068c[];
    extern s8 data_02100694[];
    extern s8 data_0210069c[];
    extern s8 data_021006a0[];
    extern s8 data_021006a4[];
    extern s8 data_021006a8[];
    extern s8 data_021006ac[];
    extern s8 data_021006b0[];
    extern s8 data_021006b4[];
    extern s8 data_021006b8[];
    extern s8 data_021006bc[];
    extern s8 data_021006c0[];
    extern s8 data_021006c4[];
    extern s8 data_021006c8[];
    extern s8 data_021006cc[];
    u16 sp26;
    u16 sp0;
    s32 var_r2;
    u16 *var_ip;
    u16 *var_r3;
    u16 temp_r0;
    u16 temp_r1_2;
    u32 temp_r1;

    if (arg1 <= -0x35) {
        if (arg1 < -0x35) {
            if (arg1 != -0x40) {
                goto block_69;
            }
            func_0206e630((u8 *)arg0, data_021005fc, -0x14);
            return;
        }
        func_0206e630((u8 *)arg0, data_0210062c, -0x10);
        return;
    }
    temp_r1 = arg1 + 0x20;
    switch (temp_r1) {
    default:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
block_69:
        func_0206e6cc(&sp26, (s32) (arg1 + ((u32) (arg1 & 0x80000000) >> 0x1F)) >> 1);
        func_0206e4ac((u8 *)arg0, (u8 *)&sp26, (u8 *)&sp26);
        if (!(arg1 & 1)) {
            return;
        }
        var_r3 = &sp0;
        var_ip = arg0;
        var_r2 = 9;
        do {
            temp_r1_2 = var_ip[0];
            temp_r0 = var_ip[1];
            var_ip += 2;
            var_r2 -= 1;
            var_r3[0] = temp_r1_2;
            var_r3[1] = temp_r0;
            var_r3 += 2;
        } while (var_r2 != 0);
        var_r3[0] = var_ip[0];
        if (arg1 > 0) {
            func_0206e630((u8 *)&sp26, data_021006b0, 0);
        } else {
            func_0206e630((u8 *)&sp26, data_021006a8, -1);
        }
        func_0206e4ac((u8 *)arg0, (u8 *)&sp0, (u8 *)&sp26);
        return;
    case 0:
        func_0206e630((u8 *)arg0, data_02100654, -0xA);
        return;
    case 16:
        func_0206e630((u8 *)arg0, data_0210066c, -5);
        return;
    case 24:
        func_0206e630((u8 *)arg0, data_0210067c, -3);
        return;
    case 25:
        func_0206e630((u8 *)arg0, data_02100684, -3);
        return;
    case 26:
        func_0206e630((u8 *)arg0, data_0210068c, -2);
        return;
    case 27:
        func_0206e630((u8 *)arg0, data_02100694, -2);
        return;
    case 28:
        func_0206e630((u8 *)arg0, data_0210069c, -2);
        return;
    case 29:
        func_0206e630((u8 *)arg0, data_021006a0, -1);
        return;
    case 30:
        func_0206e630((u8 *)arg0, data_021006a4, -1);
        return;
    case 31:
        func_0206e630((u8 *)arg0, data_021006a8, -1);
        return;
    case 32:
        func_0206e630((u8 *)arg0, data_021006ac, 0);
        return;
    case 33:
        func_0206e630((u8 *)arg0, data_021006b0, 0);
        return;
    case 34:
        func_0206e630((u8 *)arg0, data_021006b4, 0);
        return;
    case 35:
        func_0206e630((u8 *)arg0, data_021006b8, 0);
        return;
    case 36:
        func_0206e630((u8 *)arg0, data_021006bc, 1);
        return;
    case 37:
        func_0206e630((u8 *)arg0, data_021006c0, 1);
        return;
    case 38:
        func_0206e630((u8 *)arg0, data_021006c4, 1);
        return;
    case 39:
        func_0206e630((u8 *)arg0, data_021006c8, 2);
        return;
    case 40:
        func_0206e630((u8 *)arg0, data_021006cc, 2);
        return;
    }
}

s32 func_0206ea50(void *a,void *b){
s32 i,n;u8 x,y,z;
x=M2C_FIELD(a,u8*,5);
if(x==0)return M2C_FIELD(b,u8*,5)==0;
if(M2C_FIELD(b,u8*,5)==0)return x==0;
if(M2C_FIELD(a,s16*,2)==M2C_FIELD(b,s16*,2)){
y=M2C_FIELD(a,u8*,4);z=M2C_FIELD(b,u8*,4);i=0;n=y;
if((s32)y>(s32)z)n=z;
for(;i<n;i++){if(M2C_FIELD(a+i,u8*,5)!=M2C_FIELD(b+i,u8*,5))return 0;}
if(n==y)a=b;
for(;i<M2C_FIELD(a,volatile u8*,4);i++){if(M2C_FIELD(a+i,u8*,5)!=0)return 0;}
return 1;
}
return 0;
}

s32 func_0206eb30(void *arg0,void *arg1){s16 x,y;s32 i,min;s32 b;u32 a;u8 c,d;
if(!M2C_FIELD(arg0,u8 *,5))return M2C_FIELD(arg1,u8 *,5)!=0;
if(!M2C_FIELD(arg1,u8 *,5))return 0;
y=M2C_FIELD(arg1,s16 *,2);x=M2C_FIELD(arg0,s16 *,2);
if(x==y){a=M2C_FIELD(arg0,u8 *,4);b=M2C_FIELD(arg1,u8 *,4);i=0;min=a;if((s32)a>(s32)b)min=b;
if(min>0)do{d=M2C_FIELD(arg1+i,u8 *,5);c=M2C_FIELD(arg0+i,u8 *,5);if(c<d)return 1;if(d<c)return 0;i++;}while(i<min);
if(min==a && i<b){do{if(M2C_FIELD(arg1+i,u8 *,5)!=0)return 1;i++;}while(i<M2C_FIELD(arg1,volatile u8 *,4));}return 0;}return x<y;}

void func_0206ec10(u16 *arg0, u16 *arg1, void *arg2) {
    s32 temp_lr;
    s32 temp_r4_2;
    s32 temp_r6;
    s32 var_r1_3;
    s32 var_r5;
    s32 var_r7;
    u16 *var_r1;
    u16 *var_r6;
    u16 temp_r3;
    u16 temp_r4;
    u8 *temp_r4_3;
    u8 *var_lr;
    u8 *var_r2;
    u8 *var_r3;
    u8 *var_r3_2;
    u8 *var_r4;
    u8 *var_r5_2;
    u8 *var_r5_3;
    u8 temp_r1_2;
    u8 temp_r1_3;
    u8 temp_r2_3;
    u8 temp_r3_2;
    u8 temp_r5;
    u8 temp_r7;
    u8 var_r1_2;
    void *temp_r1;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_4;
    void *temp_r2_5;
    void *var_ip;

    var_r1 = arg1;
    var_r6 = arg0;
    var_r5 = 9;
    do {
        temp_r4 = M2C_FIELD(var_r1, u16 *, 0);
        temp_r3 = M2C_FIELD(var_r1, u16 *, 2);
        var_r1 += 4;
        var_r5 -= 1;
        M2C_FIELD(var_r6, u16 *, 0) = temp_r4;
        M2C_FIELD(var_r6, u16 *, 2) = temp_r3;
        var_r6 += 4;
    } while (var_r5 != 0);
    *var_r6 = *var_r1;
    if (M2C_FIELD(arg2, u8 *, 5) == 0) {
        return;
    }
    temp_r7 = M2C_FIELD(arg0, u8 *, 4);
    temp_r3_2 = M2C_FIELD(arg2, u8 *, 4);
    var_r1_2 = temp_r7;
    if ((s32) temp_r7 < (s32) temp_r3_2) {
        var_r1_2 = temp_r3_2;
    }
    temp_r6 = M2C_FIELD(arg0, s16 *, 2) - M2C_FIELD(arg2, s16 *, 2);
    var_r1_3 = var_r1_2 + temp_r6;
    if (var_r1_3 > 0x20) {
        var_r1_3 = 0x20;
    }
    if ((s32) temp_r7 < var_r1_3) {
        do {
            M2C_FIELD(arg0, u8 *, 4) = (u8) (M2C_FIELD(arg0, u8 *, 4) + 1);
            M2C_FIELD((arg0 + M2C_FIELD(arg0, u8 *, 4)), s8 *, 5) = 0;
        } while ((s32) M2C_FIELD(arg0, u8 *, 4) < var_r1_3);
    }
    var_r3 = arg0 + 5;
    var_ip = var_r3 + var_r1_3;
    temp_r4_2 = M2C_FIELD(arg2, u8 *, 4) + temp_r6;
    if (temp_r4_2 < var_r1_3) {
        var_ip = var_r3 + temp_r4_2;
    }
    temp_r1 = arg2 + 5;
    var_lr = temp_r1 + ((var_ip - var_r3) - temp_r6);
    temp_r4_3 = var_lr;
loop_20:
    if (((u32) var_ip > (u32) var_r3) && ((u32) var_lr > (u32) temp_r1)) {
        var_ip -= 1;
        var_lr -= 1;
        if ((u32) M2C_FIELD(var_ip, u8 *, 0) < (u32) *var_lr) {
            var_r5_2 = var_ip - 1;
            if (M2C_FIELD(var_ip, u8 *, -1) == 0) {
                do {
                    var_r5_2 -= 1;
                } while (*var_r5_2 == 0);
            }
            if (var_r5_2 != var_ip) {
                do {
                    *var_r5_2 -= 1;
                    var_r5_2 += 1;
                    *var_r5_2 += 0xA;
                } while (var_r5_2 != var_ip);
            }
        }
        M2C_FIELD(var_ip, u8 *, 0) = (u8) (M2C_FIELD(var_ip, u8 *, 0) - *var_lr);
        goto loop_20;
    }
    temp_r5 = M2C_FIELD(arg2, u8 *, 4);
    temp_lr = temp_r4_3 - temp_r1;
    if (temp_lr < (s32) temp_r5) {
        temp_r1_2 = *temp_r4_3;
        var_r7 = 0;
        if ((u32) temp_r1_2 < 5U) {
            var_r7 = 1;
            goto block_32;
        }
        if (temp_r1_2 == 5) {
            temp_r2 = arg2 + 5 + temp_r5;
            var_r4 = temp_r4_3 + 1;
            if ((u32) var_r4 < (u32) temp_r2) {
loop_28:
                if (*var_r4 == 0) {
                    var_r4 += 1;
                    if ((u32) var_r4 >= (u32) temp_r2) {
                        goto block_30;
                    }
                    goto loop_28;
                }
            } else {
block_30:
                temp_r2_2 = var_r3 + temp_lr + temp_r6;
                var_ip = temp_r2_2 - 1;
                if (M2C_FIELD(temp_r2_2, u8 *, -1) & 1) {
                    var_r7 = 1;
                }
                goto block_32;
            }
        } else {
block_32:
            if (var_r7 != 0) {
                if ((u32) M2C_FIELD(var_ip, u8 *, 0) < 1U) {
                    var_r2 = var_ip - 1;
                    if (M2C_FIELD(var_ip, u8 *, -1) == 0) {
                        do {
                            var_r2 -= 1;
                        } while (*var_r2 == 0);
                    }
                    if (var_r2 != var_ip) {
                        do {
                            *var_r2 -= 1;
                            var_r2 += 1;
                            *var_r2 += 0xA;
                        } while (var_r2 != var_ip);
                    }
                }
                M2C_FIELD(var_ip, u8 *, 0) = (u8) (M2C_FIELD(var_ip, u8 *, 0) - 1);
            }
        }
    }
    var_r5_3 = var_r3;
    if (M2C_FIELD(arg0, u8 *, 5) == 0) {
        do {
            var_r5_3 += 1;
        } while (*var_r5_3 == 0);
    }
    if ((u32) var_r5_3 > (u32) var_r3) {
        temp_r2_3 = var_r5_3 - var_r3;
        M2C_FIELD(arg0, s16 *, 2) = (s16) (M2C_FIELD(arg0, s16 *, 2) - temp_r2_3);
        temp_r2_4 = var_r3 + M2C_FIELD(arg0, u8 *, 4);
        if ((u32) var_r5_3 < (u32) temp_r2_4) {
            do {
                temp_r1_3 = *var_r5_3;
                var_r5_3 += 1;
                *var_r3 = temp_r1_3;
                var_r3 += 1;
            } while ((u32) var_r5_3 < (u32) temp_r2_4);
        }
        M2C_FIELD(arg0, u8 *, 4) = (u8) (M2C_FIELD(arg0, u8 *, 4) - temp_r2_3);
    }
    temp_r2_5 = arg0 + 5;
    var_r3_2 = temp_r2_5 + M2C_FIELD(arg0, u8 *, 4);
    if ((u32) var_r3_2 > (u32) temp_r2_5) {
loop_46:
        var_r3_2 -= 1;
        if (*var_r3_2 == 0) {
            if ((u32) var_r3_2 > (u32) temp_r2_5) {
                goto loop_46;
            }
        }
    }
    M2C_FIELD(arg0, u8 *, 4) = (u8) ((var_r3_2 - temp_r2_5) + 1);
}

