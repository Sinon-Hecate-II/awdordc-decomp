/* 28 functions from 0x02026164 to 0x020270B4 (main), found by ds-decomp. */
#include "common.h"

#pragma scheduling off
void func_02026164(u8 *state,const u8 *key,s32 keylen) {
s32 i; u8 *S; s32 jj; s32 ii; s32 k; u8 sk,keybyte,sj;
state[0]=0;state[1]=0;S=state+2;
for(i=0;i<256;i++)S[i]=(u8)i;
ii=0;jj=0;
for(k=0;k<256;k++){
sk=S[k];keybyte=key[ii];
ii=(ii+1)&255;
jj=(jj+(sk+keybyte))&255;
sj=S[jj];
if(ii>=keylen)ii=0;
S[k]=sj;S[jj]=sk;
}
}
#pragma scheduling reset
void func_020261d8(u8 *state, u8 *data, s32 len) {
    s32 n;
    u8 j;
    u8 i;
    u8 *S;

    S = state + 2;
    j = state[0];
    i = state[1];
    for (n = 0; n < len; n++) {
        u8 si;
        u8 sj;
        u8 k;
        j = (u8)((j + 1) & 0xff);
        si = S[j];
        i = (u8)((i + si) & 0xff);
        sj = S[i];
        S[j] = sj;
        S[i] = si;
        k = (u8)((si + sj) & 0xff);
        data[n] ^= S[k];
    }
    state[0] = j;
    state[1] = i;
}

s32 BigNumLen(u16 *arr, s32 n) {
    s32 var_r1 = n;
    while (var_r1 != 0 && arr[var_r1 - 1] == 0) {
        var_r1 -= 1;
    }
    return var_r1;
}

s32 BigNumSign(u16 *arr, s32 n) {
    if ((arr[n - 1] & 0x8000) != 0) {
        return -1;
    }
    return BigNumLen(arr, n) != 0;
}

void BigNumAdd(u16 *dst, u16 *src1, u16 *src2, s32 len) {
    s32 a;
    s32 b;
    s32 m;
    s32 k;
    u32 carry;

    a = BigNumLen(src1, len);
    b = BigNumLen(src2, len);
    m = a;
    if (a < b) {
        m = b;
    }
    if (m != len) {
        m++;
    }
    carry = 0;
    k = 0;
    while (k < m) {
        u32 s = src1[k] + src2[k] + carry;
        dst[k] = (u16)s;
        carry = s >> 16;
        k++;
    }
    if (dst != src1 && dst != src2) {
        func_02007f8c((u8 *)(dst + k), 0, (u32)((len - k) * 2));
    }
}

void func_02026338(u16 *dst, u16 *src, u32 carry, s32 len) {
    s32 i = 0;
    u32 s;
    for (; i < len; i++) {
        s = carry + src[i];
        dst[i] = (u16)s;
        carry = s >> 16;
        if (carry == 0) break;
    }
    if (dst == src) return;
    for (i++; i < len; i++) {
        dst[i] = src[i];
    }
}

void BigNumNeg(u16 *arr, s32 n) {
    void func_02026338(u16 *, u16 *, u32, s32);
    s32 i;
    for (i = 0; i < n; i++) {
        arr[i] = ~arr[i];
    }
    func_02026338(arr, arr, 1, n);
}

void BigNumSub(u16 *dst, u16 *src1, u16 *src2, s32 len) {
    s32 BigNumLen(u16 *, s32);
    M2C_UNK func_02007f8c(u8 *, s32, u32);
    s32 a;
    s32 b;
    s32 m;
    s32 k;
    s32 borrow;

    a = BigNumLen(src1, len);
    b = BigNumLen(src2, len);
    m = a;
    if (a < b) {
        m = b;
    }
    if (m != len) {
        m++;
    }
    borrow = 0;
    k = 0;
    while (k < m || (k < len && borrow != 0)) {
        s32 s = src1[k] - src2[k] + borrow;
        dst[k] = (u16)s;
        borrow = s >> 16;
        k++;
    }
    if (dst != src1 && dst != src2) {
        func_02007f8c((u8 *)(dst + k), 0, (u32)((len - k) * 2));
    }
}

void func_02026484(u16 *dst, u16 *src, u32 borrow, s32 len) {
    s32 i = 0;
    u32 s;
    for (; i < len; i++) {
        s = src[i] - borrow;
        dst[i] = (u16)s;
        borrow = s >> 16;
        borrow &= 1;
        if (borrow == 0) break;
    }
    if (dst == src) return;
    for (i++; i < len; i++) {
        dst[i] = src[i];
    }
}

s32 func_020264ec(u16 *a, u16 *b, s32 n) {
    s32 i = n - 1;
    for (; i >= 0; i--) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

void func_02026524(u16 *arr, u32 carry, s32 i, s32 len) {
    u32 s;
    while (carry != 0 && i < len) {
        s = carry + arr[i];
        arr[i] = (u16)s;
        i++;
        carry = s >> 16;
    }
}

void BigNumMul(u16 *dst,u16 *src1,u16 *src2,s32 len){
M2C_UNK func_02007f8c(u8 *,s32,u32);s32 BigNumLen(u16 *,s32);void func_02026524(u16 *,u32,s32,s32);
s32 a,b,i,j;
func_02007f8c((u8 *)dst,0,(u32)(len*2));
a=BigNumLen(src1,len);b=BigNumLen(src2,len);
for(i=0;i<b;i++){
j=0;while(j<a && j<len-i){
func_02026524(dst,(u32)src1[j]*(u32)src2[i],i+j,len);j++;
}
}
}

void func_02026604(u16 *dst, u16 *src, s32 mult, s32 len) {
    M2C_UNK func_02007f8c(u8 *, s32, u32);
    s32 BigNumLen(u16 *, s32);
    s32 n;
    u32 carry;
    s32 k;

    n = BigNumLen(src, len);
    carry = 0;
    k = 0;
    while (k < n) {
        u32 s = (u32)mult * src[k] + carry;
        dst[k] = (u16)s;
        carry = s >> 16;
        k++;
    }
    if (k < len) {
        dst[k] = (u16)carry;
        k++;
    }
    func_02007f8c((u8 *)(dst + k), 0, (u32)((len - k) * 2));
}

void func_0202667c(u16 *dst,u16 *src,s32 n){
s32 m=BigNumLen(src,n); s32 i,k,j; u32 p;
if(n>m*2)func_02007f8c((u8*)(dst+m*2),0,(n-m*2)*2);
i=0;if(m>0){j=0;do{if(j>=n)break;p=(u32)src[i]*src[i];dst[j]=p;if(j==n-1)break;i++;dst[j+1]=p>>16;j+=2;}while(i<m);}
for(k=0;k<m;k++){i=k+1;goto test;
body:p=(u32)src[i]*src[k];if(p<=0x7fff8000U)func_02026524(dst,p<<1,j,n);else{func_02026524(dst,p,j,n);func_02026524(dst,p,j,n);}i++;
test:if(i<m){j=k+i;if(j<n)goto body;}
}
}

u64 func_020267b0(u16 *arg0) {
    return (u64)*arg0 << 32;
}

s32 func_020267bc(volatile u16 *arg0) {
    if (arg0[0]) {
    }
    return arg0[-1] << 0x10;
}

u64 func_020267cc(volatile u16 *arg0) {
    u32 high = arg0[0];
    return ((u64)high << 32) | (u32)((arg0[-1] << 16) | arg0[-2]);
}

u64 func_020267e0(void *arg0) {
    return (u64)M2C_FIELD(arg0, u16 *, -2) << 32 | (u32)(M2C_FIELD(arg0, u16 *, -6) | (M2C_FIELD(arg0, u16 *, -4) << 16));
}

#pragma scheduling off
void BigNumDivMod(u16 *out,u16 *a,u16 *b,u16 *rem,s32 n,u16 *work) {
M2C_UNK MI_CpuCopy8(s32,s32,s32);
M2C_UNK func_020651c4(M2C_UNK,M2C_UNK,M2C_UNK);
u64 func_02072088(u64,u64);
s32 i;u32 digit;u16 *q,*r;s32 nb,na,bytes;u64 divisor;
q=work+n;r=q+n;
func_02007f8c((u8 *)q,0,n*4);
na=BigNumLen(a,n);nb=BigNumLen(b,n);
if(na>0 && nb>0){
i=nb+(n-na)-1;
if(i>=n){MI_CpuCopy8((s32)a,(s32)r,n*2);}
else {
MI_CpuCopy8((s32)a,(s32)(q+i),na*2);
if(nb>2){bytes=nb*2;divisor=func_020267cc(b+nb-1);}
else if(nb>1){bytes=nb*2;divisor=((u64(*)(volatile u16 *))func_020267bc)(b+nb-1);}
else {bytes=nb*2;divisor=func_020267b0(b+nb-1);}
if(i<n) do {
func_020651c4((s32)(q+1),(s32)q,(n*2-1)*2);
digit=func_02072088(func_020267e0((u8 *)r+bytes),divisor);
if(digit>65535)digit=65535;
again:
func_02026604(work,b,(u16)digit,n);
if(func_020264ec(r,work,n)<0){digit--;goto again;}
BigNumSub(r,r,work,n);*q=digit;
}while(++i<n);
}
}
if(out)MI_CpuCopy8((s32)q,(s32)out,n*2);
if(rem)MI_CpuCopy8((s32)r,(s32)rem,n*2);
}
#pragma scheduling reset
void func_020269dc(u16 *arg0, u16 *arg1, u16 *arg2, s32 arg3, u16 *arg4) {
    M2C_UNK func_02007f8c(u8 *, s32, u32);
    M2C_UNK MI_CpuCopy8(s32, s32, s32);
    s32 BigNumLen(u16 *, s32);
    void BigNumMul(u16 *, u16 *, u16 *, s32);
    void func_0202667c(u16 *, u16 *, s32);
    void BigNumDivMod(u16 *, u16 *, u16 *, u16 *, s32, u16 *);
    extern u16 *(*gAlloc)(s32);
    extern void (*gFree)(void *);

    s32 var_r6;
    u16 *temp_r4;
    u16 *temp_r5;
    u32 sp8;
    s32 temp_r11;

    sp8 = (u32)arg1;
    temp_r4 = gAlloc(arg3 * 8);
    if (temp_r4 == 0) {
        return;
    }
    temp_r5 = temp_r4 + arg3;
    func_02007f8c((u8 *)(arg0 + 1), 0, (u32)((arg3 - 1) * 2));
    *arg0 = 1;
    var_r6 = (u32)((arg3 - BigNumLen(arg2, arg3)) * 16);
    for (; (u32)var_r6 < (u32)(arg3 * 16); var_r6++) {
        if (arg2[arg3 - (var_r6 >> 4) - 1] & (0x8000U >> (var_r6 & 0xF))) {
            MI_CpuCopy8(sp8, (s32)arg0, arg3 * 2);
            var_r6++;
            break;
        }
    }
    if ((u32)var_r6 < (u32)(arg3 * 16)) {
        temp_r11 = arg3 * 2;
        do {
            func_0202667c(temp_r4, arg0, arg3);
            MI_CpuCopy8((s32)temp_r4, (s32)arg0, temp_r11);
            if (arg4 != 0) {
                BigNumDivMod(0, arg0, arg4, arg0, arg3, temp_r5);
            }
            if (arg2[arg3 - (var_r6 >> 4) - 1] & (0x8000U >> (var_r6 & 0xF))) {
                BigNumMul(temp_r4, arg0, (u16 *)sp8, arg3);
                MI_CpuCopy8((s32)temp_r4, (s32)arg0, temp_r11);
                if (arg4 != 0) {
                    BigNumDivMod(0, arg0, arg4, arg0, arg3, temp_r5);
                }
            }
            var_r6 += 1;
        } while ((u32)var_r6 < (u32)(arg3 * 16));
    }
    gFree(temp_r4);
}
#pragma scheduling reset
void func_02026b70(u16 *arg0, u16 *arg1, u16 *arg2, s32 arg3, u16 *arg4) {
    M2C_UNK MI_CpuCopy8(s32, s32, s32);
    s32 BigNumSign(u16 *, s32);
    void BigNumAdd(u16 *, u16 *, u16 *, s32);
    void BigNumSub(u16 *, u16 *, u16 *, s32);
    void BigNumMul(u16 *, u16 *, u16 *, s32);
    void BigNumDivMod(u16 *, u16 *, u16 *, u16 *, s32, u16 *);

    s32 bytes;
    u16 *p5;
    u16 *p4;
    u16 *p3;
    u16 *p2;
    u16 *p1;
    u16 *base;
    u16 *p6;
    s32 n;

    n = arg3;
    base = arg4;
    p6 = 0;
    bytes = n << 1;
    p1 = base + n;
    p2 = p1 + n;
    p3 = p2 + n;
    p4 = p3 + n;
    p5 = p4 + n;
    p6 = p5 + n;

    MI_CpuCopy8((s32)arg1, (s32)base, bytes);
    MI_CpuCopy8((s32)arg2, (s32)p2, bytes);
    p3[0] = 1;

    if (BigNumSign(base, n) > 0) {
        do {
            BigNumDivMod(p1, p2, base, p5, n, p6);
            MI_CpuCopy8((s32)base, (s32)p2, bytes);
            MI_CpuCopy8((s32)p5, (s32)base, bytes);
            BigNumMul(p5, p1, p3, n);
            BigNumSub(p5, p4, p5, n);
            MI_CpuCopy8((s32)p3, (s32)p4, bytes);
            MI_CpuCopy8((s32)p5, (s32)p3, bytes);
        } while (BigNumSign(base, n) > 0);
    }
    BigNumAdd(p4, p4, arg2, n);
    BigNumDivMod(0, p4, arg2, arg0, n, p6);
}
#pragma scheduling reset
void func_02026cbc(u16 *arg0, u16 *arg1, s32 arg2, s32 arg3, s32 arg4, u16 *arg5, u16 *arg6, u16 *arg7, u16 *arg8)
{
  M2C_UNK func_02007f8c(u8 *, s32, u32);
  M2C_UNK MI_CpuCopy8(s32, s32, s32);
  void BigNumAdd(u16 *, u16 *, u16 *, s32);
  void BigNumSub(u16 *, u16 *, u16 *, s32);
  s32 func_020264ec(u16 *, u16 *, s32);
  void BigNumMul(u16 *, u16 *, u16 *, s32);
      void func_0202667c(u16 *, u16 *, s32);
  M2C_UNK func_020651c4(M2C_UNK, M2C_UNK, M2C_UNK);
  MI_CpuCopy8((s32) arg0, (s32) arg1, arg3 * 2);
  if (arg2 == 1)
  {
    func_0202667c(arg0, arg1, arg3);
  }
  else
    if (arg2 != 0)
  {
    BigNumMul(arg0, arg1, (u16 *) arg2, arg3);
  }
  BigNumMul(arg7, arg0, arg6, arg4);
  arg2 = (arg3 - arg4) * 2;
  func_02007f8c((u8 *) (arg7 + arg4), 0, (u32) arg2);
  BigNumMul(arg8, arg7, arg5, arg3);
  BigNumAdd(arg0, arg0, arg8, arg3);
  func_020651c4((s32) arg0, (s32) (arg0 + arg4), (arg3 - arg4) * 2);
  func_02007f8c((u8 *) ((arg0 + arg3) - arg4), 0, (u32) (arg4 * 2));
  switch (func_020264ec(arg0, arg5, arg3))
  {
    case 0:
      func_02007f8c((u8 *) arg0, 0, (u32) (arg3 * 2));
      return;

    case 1:
      BigNumSub(arg0, arg0, arg5, arg3);
      return;

  }

}

#pragma push
#pragma opt_strength_reduction off
void BigNumModPow(void *arg0, void *arg1, void *arg2, s32 arg3, void *arg4) {
    M2C_UNK func_02007f8c(u8 *, s32, u32);
    s32 BigNumLen(u16 *, s32);
    void func_02026484(u16 *, u16 *, u32, s32);
    void BigNumMul(u16 *, u16 *, u16 *, s32);
    void BigNumDivMod(u16 *, u16 *, u16 *, u16 *, s32, u16 *);
    void func_02026b70(u16 *, u16 *, u16 *, s32, u16 *);
    void func_02026cbc(u16 *, u16 *, s32, s32, s32, u16 *, u16 *, u16 *, u16 *);
    extern u16 *(*gAlloc)(s32);
    extern void (*gFree)(void *);

    s32 n = arg3;
    u16 *buf;
    s32 t;
    s32 counter;
    u16 *r6;
    u16 *sp20;
    u16 *r7;
    u16 *r8;
    u16 *sp24;
    u16 *r5;
 
    buf = gAlloc(n * 0x16);
    if (buf == 0) {
        return;
    }
    func_02007f8c((u8 *)buf, 0, (u32)(n * 0x16));

    r6 = buf + n;
    r5 = r6 + n;
    sp24=r5;
    r7 = sp24 + n;
    r8 = r7 + n;
    r5=r8+n;
    sp20 = r5;
    r5 = sp20 + n;

    t = BigNumLen((u16 *)arg4, n);
    buf[t] = 1;

    func_02026b70(r6, buf, (u16 *)arg4, n, sp24);
    BigNumMul(r7, buf, r6, n);
    func_02026484(r6, r7, 1, n);
    BigNumDivMod(r6, r6, (u16 *)arg4, (u16 *)0, n, r5);
    BigNumMul(sp24, (u16 *)arg1, buf, n);
    BigNumDivMod((u16 *)0, sp24, (u16 *)arg4, sp24, n, r5);
    BigNumDivMod((u16 *)0, buf, (u16 *)arg4, (u16 *)arg0, n, r5);

    counter=0;
    if ((t << 4) != 0) {
        do {
            func_02026cbc((u16 *)arg0, sp20, 1, n, t, (u16 *)arg4, r6, r7, r8);
            {
                u16 word = ((u16 *)arg2)[t - (counter >> 4) - 1];
                if ((0x8000u >> (counter & 0x0F)) & word) {
                    func_02026cbc((u16 *)arg0, sp20, (s32)sp24, n, t, (u16 *)arg4, r6, r7, r8);
                }
            }
        counter++;
        } while ((u32)counter < (u32)(t << 4));
    }
    func_02026cbc((u16 *)arg0, sp20, 0, n, t, (u16 *)arg4, r6, r7, r8);

    gFree(buf);
}
#pragma pop
void BigNumFromBytes(s16 *dst, u8 *src, s32 count, s32 size) {
    M2C_UNK func_02007f8c(u8 *, s32, u32);
    s16 *var_r4;
    s32 var_r5;
    u8 *var_r6;

    var_r4 = dst;
    var_r5 = count;
    var_r6 = src;
    func_02007f8c((u8 *)var_r4, 0, (u32)(size * 2));
    var_r6 = var_r6 + (var_r5 - 1);
    if (var_r5 > 1) {
        do {
            var_r5 -= 2;
            *var_r4 = (s16)(var_r6[0] + (var_r6[-1] << 8));
            var_r4 += 1;
            var_r6 -= 2;
        } while (var_r5 > 1);
    }
    if (var_r5 > 0) {
        *var_r4 = (s16)var_r6[0];
    }
}

void BigNumToBytes(u8 *dst, u16 *src, s32 n) {
    u8 *p;
    dst += n - 1;
    while (n > 1) {
        p = dst - 1;
        *dst = (u8)*src;
        dst -= 2;
        *p = (u8)(*src >> 8);
        src++;
        n -= 2;
    }
    if (n > 0) {
        *dst = (u8)*src;
    }
}

void func_02027090(void) {
    M2C_UNK func_0200c454();
    func_0200c454();
}

void func_0202709c(void) {
    M2C_UNK func_0200c494();
    func_0200c494();
}

void func_020270a8(void) {
    M2C_UNK func_0200c55c();
    func_0200c55c();
}

