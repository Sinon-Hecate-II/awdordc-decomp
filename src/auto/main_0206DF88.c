/* 16 functions from 0x0206DF88 to 0x0206EEB4 (main), found by ds-decomp. */
#include "common.h"

double func_0206df88(double x,double y) { ((u32 *)&x)[1] = (((u32 *)&x)[1] & 0x7fffffff) | (((u32 *)&y)[1] & 0x80000000); return x; }

double fabs(double x) { ((u32 *)&x)[1] &= 0x7fffffff; return x; }

/* frexp: split `value` into a mantissa in [0.5, 1) and the exponent `exponent`
 * it is scaled by, so value == mantissa * 2^exponent.  Zero, infinity and NaN
 * come back unchanged with exponent 0; a subnormal is first scaled up by 2^54
 * (18014398509481984.0) and its exponent corrected by -54. */
double Frexp(double value,s32 *exponent) {
 double func_02070658(double,double);
 s32 absHigh,highWord,lowWord;
 highWord=((s32 *)&value)[1]; absHigh=highWord & 0x7fffffff; *exponent=0; lowWord=((s32 *)&value)[0];
 if(absHigh>=0x7ff00000 || (absHigh|lowWord)==0) return value;
 if(absHigh<0x100000) { value=func_02070658(value,18014398509481984.0); *exponent=-54; highWord=((s32 *)&value)[1]; absHigh=highWord & 0x7fffffff; }
 *exponent += (absHigh>>20)-1022;
 ((u32 *)&value)[1]=(highWord & 0x800fffff) | 0x3fe00000;
 return value;
}

double func_02070134(double,double);
s32 ClassifyDouble(double);
/* scalbn: return x * 2^scale, splitting the scaling into two steps and going
   through the soft-float multiply/copysign helpers at the overflow and
   underflow limits (2^54 steps for subnormals). */
double ScaleDoubleByExp(double x, s32 scale) {
    double func_02070658(double, double);
    double func_02070134(double, double);
    s32 ClassifyDouble(double);
    s32 exponent, hiWord, loWord;

    if (ClassifyDouble(x) <= 2 || x == 0.0) return x;
    hiWord = ((s32 *)&x)[1];
    loWord = ((s32 *)&x)[0];
    exponent = (hiWord & 0x7ff00000) >> 20;
    if (exponent == 0) {
        if ((loWord | (hiWord & 0x7fffffff)) == 0) return x;
        x = func_02070658(x, 18014398509481984.0);
        hiWord = ((s32 *)&x)[1];
        exponent = ((hiWord & 0x7ff00000) >> 20) - 54;
        if (scale < -50000) return func_02070658(1.0e-300, x);
    }
    if (exponent == 0x7ff) return func_02070134(x, x);
    exponent = exponent + scale;
    if (exponent > 0x7fe) return func_02070658(1.0e300, func_0206df88(1.0e300, x));
    if (exponent > 0) {
        ((s32 *)&x)[1] = (hiWord & 0x800fffff) | (exponent << 20);
        return x;
    }
    if (exponent <= -54) {
        if (scale > 50000) return func_02070658(1.0e300, func_0206df88(1.0e300, x));
        return func_02070658(1.0e-300, func_0206df88(1.0e-300, x));
    }
    ((s32 *)&x)[1] = (hiWord & 0x800fffff) | ((exponent + 54) << 20);
    return func_02070658(5.551115123125783e-17, x);
}

void func_0206e2d8(void) {
    M2C_UNK func_0206ce00();
    func_0206ce00();
}

/* Decide whether rounding a DecimalNumber at digit `i` rounds up (1) or down
 * (-1): a digit above 5 rounds up and below 5 rounds down, while an exact 5
 * rounds to even (up only when the preceding digit is odd), after checking that
 * every following digit is zero. */
s32 DecimalShouldRoundUp(u8 *p, s32 i) {
    DecimalNumber *number = (DecimalNumber *)p;
    u8 *q = number->digits + i;
    u8 *end;
    if (*q > 5) return 1;
    if (*q < 5) return -1;
    q++;
    end = number->digits + number->length;
    while (q < end) { if (*q != 0) return 1; q++; }
    i--;
    if (number->digits[i] & 1) return 1;
    return -1;
}

#pragma optimization_level 3
void DecimalIncrementDigits(u8 *p,s32 n) {
 u8 *start=p+5; u8 *q=start+n-1;
 for (;;) {
 u8 digit = *q;
 if(digit < 9) { *q = digit + 1; return; }
 if(q == start) { *q = 1; ++M2C_FIELD(p,s16 *,2); return; }
 *q-- = 0;
 }
}
#pragma optimization_level reset
void func_0206e39c(void) {

}

/* Round a decimal number to its first `digits` digits: leave it alone when it is
 * shorter, otherwise keep those digits and, when the dropped part rounds up
 * (DecimalShouldRoundUp), increment them. */
void RoundDecimalToDigits(DecimalNumber *number, s32 digits) {
    s32 roundUp;

    if (digits <= 0) return;
    if (digits >= number->length) return;
    roundUp = DecimalShouldRoundUp((u8 *) number, digits);
    number->length = (u8) digits;
    if (roundUp < 0) return;
    DecimalIncrementDigits((u8 *) number, digits);
}

u64 U64Divide(u64,u64);
u64 func_02072094(u64,u64);
/* Stores the unsigned 64-bit `value` in `p` as a decimal number: converts it
 * digit by digit (least significant first, growing the digit count), reverses
 * the digits in place and sets the exponent to the digit count minus one. */
void DecimalFromU64(DecimalNumber *p, u64 value) {
    u8 *lo;
    u8 *hi;
    p->sign = 0;
    p->length = 0;
    while (value) {
        p->digits[p->length++] = value % 10ULL;
        value /= 10ULL;
    }
    lo = p->digits;
    hi = lo + p->length - 1;
    while (lo < hi) {
        u8 t = *lo;
        *lo++ = *hi;
        *hi-- = t;
    }
    p->exponent = (s16)(p->length - 1);
}

#pragma scheduling off
void DecimalMultiply(u8 *arg0, u8 *arg1, u8 *arg2) {
u8 buf[64]; register s32 total; register u32 acc; register u8 *cursor; register u8 *endmark;
s32 n; u8 *base1,*base2; register s32 cnt,t,idx; u8 *p1,*p2; s32 lim; u8 tt;
acc=0;total=arg1[4]+arg2[4]-1;cursor=buf+total+1;endmark=cursor;
arg0[0]=0;
if(total>0) { base1=arg1+5; base2=arg2+5; do {
t=arg2[4]-1; idx=total-t-1;
if(idx<0){idx=0;t=total-1;}
lim=arg1[4]-idx;cnt=t+1; cnt=cnt<=lim?cnt:lim;
t=(s32)(base2+t);idx=(s32)(base1+idx);
while(cnt>0){acc+=(u32)*(u8*)idx * *(u8*)t;idx++;t--;cnt--;}
total--;*--cursor=acc%10;acc/=10;
}while(total>0);}
*(s16*)(arg0+2)=*(s16*)(arg1+2)+*(s16*)(arg2+2);
if(acc){*--cursor=acc;++*(s16*)(arg0+2);}
for(n=0;n<32 && cursor<endmark;n++)arg0[5+n]=*cursor++;
arg0[4]=n;if(cursor>=endmark)return;
tt=*cursor;if(tt<5)return;
if(tt==5){for(p2=cursor+1;p2<endmark;++p2){if(*p2)goto call;}if(!(cursor[-1]&1))return;}
call:DecimalIncrementDigits(arg0,arg0[4]);
}
#pragma scheduling reset
/* Build a DecimalNumber from the ASCII digit string digitString (at most 32
 * digits): copy the digits and set their count and the decimal exponent, then
 * round the digits that did not fit (past 5 rounds up, exactly 5 rounds to even,
 * below 5 truncates; the dropped digit is compared as the raw character, as the
 * original does). */
void DecimalFromDigitString(u8 *p,s8 *digitString,s16 exponent) {
 DecimalNumber *number=(DecimalNumber *)p;
 s32 n=0;
 number->exponent=exponent; number->sign=0;
 while(n<32 && *digitString) { number->digits[n++]=*digitString++-'0'; }
 number->length=n;
 if(*digitString==0)return;
 if(*digitString<5)return;
 if(*digitString<=5) {
 {s32 c=digitString[1]; digitString++;
 while(c) { if(c!='0')goto round; c=*++digitString; }}
 n--; if(!(number->digits[n]&1))return;
 }
round:
 DecimalIncrementDigits(p,number->length);
}

/* Store 2^exponent as a DecimalNumber.  The small exponents -64, -53, -32,
 * -16 and -8..8 come from precomputed digit strings (2^-64 is the smallest
 * power the soft-float code needs); any other exponent is halved and computed
 * recursively, squared, and for an odd exponent multiplied once more by 2
 * (positive) or by 0.5 (negative). */
void DecimalFromPowerOfTwo(DecimalNumber *out, s32 exponent) {
    extern s8 gPow2Neg64Digits[];
    extern s8 gPow2Neg53Digits[];
    extern s8 gPow2Neg32Digits[];
    extern s8 gPow2Neg16Digits[];
    extern s8 gPow2Neg8Digits[];
    extern s8 gPow2Neg7Digits[];
    extern s8 gPow2Neg6Digits[];
    extern s8 gPow2Neg5Digits[];
    extern s8 gPow2Neg4Digits[];
    extern s8 gPow2Neg3Digits[];
    extern s8 gPow2Neg2Digits[];
    extern s8 gPow2Neg1Digits[];
    extern s8 gPow2ZeroDigits[];
    extern s8 gPow2OneDigits[];
    extern s8 gPow2TwoDigits[];
    extern s8 gPow2ThreeDigits[];
    extern s8 gPow2FourDigits[];
    extern s8 gPow2FiveDigits[];
    extern s8 gPow2SixDigits[];
    extern s8 gPow2SevenDigits[];
    extern s8 gPow2EightDigits[];
    DecimalNumber power;
    DecimalNumber squared;

    switch (exponent) {
    case -64:
        DecimalFromDigitString((u8 *)out, gPow2Neg64Digits, -20);
        return;
    case -53:
        DecimalFromDigitString((u8 *)out, gPow2Neg53Digits, -16);
        return;
    case -32:
        DecimalFromDigitString((u8 *)out, gPow2Neg32Digits, -0xA);
        return;
    case -16:
        DecimalFromDigitString((u8 *)out, gPow2Neg16Digits, -5);
        return;
    case -8:
        DecimalFromDigitString((u8 *)out, gPow2Neg8Digits, -3);
        return;
    case -7:
        DecimalFromDigitString((u8 *)out, gPow2Neg7Digits, -3);
        return;
    case -6:
        DecimalFromDigitString((u8 *)out, gPow2Neg6Digits, -2);
        return;
    case -5:
        DecimalFromDigitString((u8 *)out, gPow2Neg5Digits, -2);
        return;
    case -4:
        DecimalFromDigitString((u8 *)out, gPow2Neg4Digits, -2);
        return;
    case -3:
        DecimalFromDigitString((u8 *)out, gPow2Neg3Digits, -1);
        return;
    case -2:
        DecimalFromDigitString((u8 *)out, gPow2Neg2Digits, -1);
        return;
    case -1:
        DecimalFromDigitString((u8 *)out, gPow2Neg1Digits, -1);
        return;
    case 0:
        DecimalFromDigitString((u8 *)out, gPow2ZeroDigits, 0);
        return;
    case 1:
        DecimalFromDigitString((u8 *)out, gPow2OneDigits, 0);
        return;
    case 2:
        DecimalFromDigitString((u8 *)out, gPow2TwoDigits, 0);
        return;
    case 3:
        DecimalFromDigitString((u8 *)out, gPow2ThreeDigits, 0);
        return;
    case 4:
        DecimalFromDigitString((u8 *)out, gPow2FourDigits, 1);
        return;
    case 5:
        DecimalFromDigitString((u8 *)out, gPow2FiveDigits, 1);
        return;
    case 6:
        DecimalFromDigitString((u8 *)out, gPow2SixDigits, 1);
        return;
    case 7:
        DecimalFromDigitString((u8 *)out, gPow2SevenDigits, 2);
        return;
    case 8:
        DecimalFromDigitString((u8 *)out, gPow2EightDigits, 2);
        return;
    default:
        break;
    }

    DecimalFromPowerOfTwo(&power, (s32)(exponent + (((u32)exponent & 0x80000000U) >> 31)) >> 1);
    DecimalMultiply((u8 *)out, (u8 *)&power, (u8 *)&power);
    if (!(exponent & 1))
        return;
    squared = *out;
    if (exponent > 0)
        DecimalFromDigitString((u8 *)&power, gPow2OneDigits, 0);
    else
        DecimalFromDigitString((u8 *)&power, gPow2Neg1Digits, -1);
    DecimalMultiply((u8 *)out, (u8 *)&squared, (u8 *)&power);
}

/* Compare two digits BCD values: header byte +0 is the sign, +2 the exponent,
 * +4 the digit count and +5.. the most significant first digits. Equal when
 * both are zero, or the sign, exponent and digits (after trailing zeros are
 * dropped) agree. */
s32 Bcd_IsEqual(void *a,void *b){
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

/* Orders two BCD digit strings (sign at +0, exponent at +2, digit count at +4,
 * most significant digit first at +5): a zero value sorts first, then the
 * smaller exponent, then the smaller digit sequence. Returns 1 when a < b. */
s32 func_0206eb30(void *a, void *b) {
    s16 expA, expB;
    s32 i, count;
    s32 countB;
    u32 countA;
    u8 digitA, digitB;

    if (!M2C_FIELD(a, u8 *, 5)) return M2C_FIELD(b, u8 *, 5) != 0;
    if (!M2C_FIELD(b, u8 *, 5)) return 0;
    expB = M2C_FIELD(b, s16 *, 2);
    expA = M2C_FIELD(a, s16 *, 2);
    if (expA == expB) {
        countA = M2C_FIELD(a, u8 *, 4);
        countB = M2C_FIELD(b, u8 *, 4);
        i = 0;
        count = countA;
        if ((s32)countA > (s32)countB) count = countB;
        if (count > 0) do {
            digitB = M2C_FIELD(b + i, u8 *, 5);
            digitA = M2C_FIELD(a + i, u8 *, 5);
            if (digitA < digitB) return 1;
            if (digitB < digitA) return 0;
            i++;
        } while (i < count);
        if (count == countA && i < countB) {
            do {
                if (M2C_FIELD(b + i, u8 *, 5) != 0) return 1;
                i++;
            } while (i < M2C_FIELD(b, volatile u8 *, 4));
        }
        return 0;
    }
    return expA < expB;
}

#pragma optimization_level 2
void func_0206ec10(void *arg0, void *arg1, void *arg2) {
    s32 temp_lr;
    s32 temp_r4_2;
    s32 temp_r6;
    int var_r5;
    u8 temp_r3_2;
    void *var_r1;
    void *var_r6;
    u16 temp_r3;
    u16 temp_r4;
    u8 *temp_r4_3;
    u8 *var_lr;
    u8 *var_r2;
    u8 *var_r3;
    u8 *var_ip;
    u8 *var_r4;
    u8 *var_r5_2;
    u8 *var_r5_3;
    u8 temp_r1_2;
    u8 temp_r1_3;
    u8 temp_r2_3;
    s32 var_r7;
    u8 temp_r5;
    u8 temp_r7;
    s32 var_r1_2;
    u8 *temp_r1;
    u8 *temp_r2;
    u8 *temp_r2_2;
    u8 *temp_r2_4;
    u8 *temp_r2_5;
    u8 *var_r3_2;

    var_r1 = arg1;
    var_r6 = arg0;
    var_r5 = 9;
    do {
        temp_r4 = M2C_FIELD(var_r1, u16 *, 0);
        temp_r3 = M2C_FIELD(var_r1, u16 *, 2);
        var_r1 += 4;
        var_r5--;
        M2C_FIELD(var_r6, u16 *, 0) = temp_r4;
        M2C_FIELD(var_r6, u16 *, 2) = temp_r3;
        var_r6 += 4;
    } while (var_r5 != 0);
    M2C_FIELD(var_r6,u16 *,0) = M2C_FIELD(var_r1,u16 *,0);
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
    var_r1_2 += temp_r6;
    if (var_r1_2 > 0x20) {
        var_r1_2 = 0x20;
    }
    if ((s32) temp_r7 < var_r1_2) {
        do {
            M2C_FIELD(arg0, u8 *, 4) = (u8) (M2C_FIELD(arg0, volatile u8 *, 4) + 1);
            M2C_FIELD((arg0 + temp_r7), s8 *, 5) = 0;
            temp_r7 = M2C_FIELD(arg0,u8 *,4);
        } while ((s32) M2C_FIELD(arg0, u8 *, 4) < var_r1_2);
    }
    var_r3 = arg0 + 5;
    var_ip = var_r3 + var_r1_2;
    temp_r4_2 = M2C_FIELD(arg2, u8 *, 4) + temp_r6;
    if (temp_r4_2 < var_r1_2) {
        var_ip = var_r3 + temp_r4_2;
    }
    temp_r1 = arg2 + 5;
    var_lr = temp_r1 + ((var_ip - var_r3) - temp_r6);
    temp_r4_3 = var_lr;
    goto test_20;
loop_20:
    {
        var_ip -= 1;
        var_lr -= 1;
        if ((u32) M2C_FIELD(var_ip, u8 *, 0) < (u32) *var_lr) {
            var_r5_2 = var_ip - 1;
            if (M2C_FIELD(var_ip, u8 *, -1) == 0) {
                do {
                    var_r5_2--;
                } while (*var_r5_2 == 0);
            }
            if (var_r5_2 != var_ip) {
                do {
                    *var_r5_2 -= 1;
                    ++var_r5_2;
                    *var_r5_2 += 0xA;
                } while (var_r5_2 != var_ip);
            }
        }
        M2C_FIELD(var_ip, u8 *, 0) = (u8) (M2C_FIELD(var_ip, u8 *, 0) - *var_lr);
    }
test_20:
    if (((u32)var_ip > (u32)var_r3) && ((u32)var_lr > (u32)temp_r1)) goto loop_20;
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
                var_r3 += 1;
                *var_r3 = temp_r1_3;
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
#pragma optimization_level reset
