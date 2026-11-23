/* 28 functions from 0x02026164 to 0x020270B4 (main), found by ds-decomp. */
#include "common.h"

#pragma scheduling off
void RC4_Init(u8 *state,const u8 *key,s32 keylen) {
u8 *S; s32 k,jj,ii,i; u8 sk,keybyte,sj;
state[0]=0;state[1]=0;S=state+2;
for(i=0;i<256;i++)S[i]=(u8)i;
ii=0;jj=0;
k=0;do{
sk=S[k];keybyte=key[ii];ii=(ii+1)&255;
jj=(jj+(sk+keybyte))&255;sj=S[jj];
if(ii>=keylen)ii=0;S[k]=sj;S[jj]=sk;
k++;}while(k<256);
}
#pragma scheduling reset
/* Run the RC4 keystream over len bytes: advance both S-box indices, swap the two
 * S-box entries, and XOR each byte with the entry their sum names. */
void RC4_Crypt(u8 *state, u8 *data, s32 len) {
    s32 n;
    u8 i;
    u8 j;
    u8 *sbox;

    sbox = state + RC4_SBOX;
    i = state[RC4_INDEX_I];
    j = state[RC4_INDEX_J];
    for (n = 0; n < len; n++) {
        u8 si;
        u8 sj;
        u8 k;
        i = (u8)((i + 1) & 0xff);
        si = sbox[i];
        j = (u8)((j + si) & 0xff);
        sj = sbox[j];
        sbox[i] = sj;
        sbox[j] = si;
        k = (u8)((si + sj) & 0xff);
        data[n] ^= sbox[k];
    }
    state[RC4_INDEX_I] = i;
    state[RC4_INDEX_J] = j;
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

/* dst = src1 + src2 over `len` 16-bit limbs: add the significant limbs of both
 * operands plus one extra limb to carry out of the top, then zero the unused
 * high limbs unless dst aliases an operand. */
void BigNumAdd(u16 *dst, u16 *src1, u16 *src2, s32 len) {
    s32 len1;
    s32 len2;
    s32 n;
    s32 i;
    u32 carry;

    len1 = BigNumLen(src1, len);
    len2 = BigNumLen(src2, len);
    n = len1;
    if (len1 < len2) {
        n = len2;
    }
    if (n != len) {
        n++;
    }
    carry = 0;
    i = 0;
    while (i < n) {
        u32 sum = src1[i] + src2[i] + carry;
        dst[i] = (u16)sum;
        carry = sum >> 16;
        i++;
    }
    if (dst != src1 && dst != src2) {
        MI_CpuFill8((u8 *)(dst + i), 0, (u32)((len - i) * 2));
    }
}

/* dst = src + carry over `len` 16-bit limbs: add the small carry into the low
 * limbs, stopping as soon as it is absorbed, then copy the untouched higher
 * limbs from src (the copy is skipped when dst aliases src). */
void BigNumAddCarry(u16 *dst, u16 *src, u32 carry, s32 len) {
    s32 i = 0;
    u32 sum;
    for (; i < len; i++) {
        sum = carry + src[i];
        dst[i] = (u16)sum;
        carry = sum >> 16;
        if (carry == 0) break;
    }
    if (dst == src) return;
    for (i++; i < len; i++) {
        dst[i] = src[i];
    }
}

void BigNumNeg(u16 *arr, s32 n) {
    void BigNumAddCarry(u16 *, u16 *, u32, s32);
    s32 i;
    for (i = 0; i < n; i++) {
        arr[i] = ~arr[i];
    }
    BigNumAddCarry(arr, arr, 1, n);
}

/* dst = src1 - src2 over `len` 16-bit limbs: subtract the significant limbs of
 * both operands plus one extra limb to absorb the final borrow, then zero the
 * unused high limbs unless dst aliases an operand. */
void BigNumSub(u16 *dst, u16 *src1, u16 *src2, s32 len) {
    s32 BigNumLen(u16 *, s32);
    M2C_UNK MI_CpuFill8(u8 *, s32, u32);
    s32 len1;
    s32 len2;
    s32 n;
    s32 i;
    s32 borrow;

    len1 = BigNumLen(src1, len);
    len2 = BigNumLen(src2, len);
    n = len1;
    if (len1 < len2) {
        n = len2;
    }
    if (n != len) {
        n++;
    }
    borrow = 0;
    i = 0;
    while (i < n || (i < len && borrow != 0)) {
        s32 s = src1[i] - src2[i] + borrow;
        dst[i] = (u16)s;
        borrow = s >> 16;
        i++;
    }
    if (dst != src1 && dst != src2) {
        MI_CpuFill8((u8 *)(dst + i), 0, (u32)((len - i) * 2));
    }
}

/* dst = src - borrow over `len` 16-bit limbs: subtract the incoming borrow
 * (0 or 1) and propagate its borrow upwards, then copy the untouched high limbs
 * unless dst aliases src. */
void BigNumSubBorrow(u16 *dst, u16 *src, u32 borrow, s32 len) {
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

s32 BigNumCmp(u16 *a, u16 *b, s32 n) {
    s32 i = n - 1;
    for (; i >= 0; i--) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

void BigNumAddCarryAt(u16 *arr, u32 carry, s32 i, s32 len) {
    u32 s;
    while (carry != 0 && i < len) {
        s = carry + arr[i];
        arr[i] = (u16)s;
        i++;
        carry = s >> 16;
    }
}

/* dst = src1 * src2 over `len` 16-bit limbs, schoolbook style: each limb of
 * src2 multiplies src1's limbs and the 32-bit product is carried into dst at
 * that limb's offset. */
void BigNumMul(u16 *dst, u16 *src1, u16 *src2, s32 len) {
    M2C_UNK MI_CpuFill8(u8 *, s32, u32);
    s32 BigNumLen(u16 *, s32);
    void BigNumAddCarryAt(u16 *, u32, s32, s32);
    s32 len1, len2;
    s32 i, j;

    MI_CpuFill8((u8 *)dst, 0, (u32)(len * 2));
    len1 = BigNumLen(src1, len);
    len2 = BigNumLen(src2, len);
    for (i = 0; i < len2; i++) {
        j = 0;
        while (j < len1 && j < len - i) {
            BigNumAddCarryAt(dst, (u32)src1[j] * (u32)src2[i], i + j, len);
            j++;
        }
    }
}

/* dst = src * mult over `len` 16-bit limbs: each limb is multiplied by the
 * scalar and the 32-bit product carries into the next limb; one limb holds the
 * last carry and the limbs after it are cleared. */
void BigNumMulSmall(u16 *dst, u16 *src, s32 mult, s32 len) {
    M2C_UNK MI_CpuFill8(u8 *, s32, u32);
    s32 BigNumLen(u16 *, s32);
    s32 srcLen;
    u32 carry;
    s32 i;

    srcLen = BigNumLen(src, len);
    carry = 0;
    i = 0;
    while (i < srcLen) {
        u32 product = (u32)mult * src[i] + carry;
        dst[i] = (u16)product;
        carry = product >> 16;
        i++;
    }
    if (i < len) {
        dst[i] = (u16)carry;
        i++;
    }
    MI_CpuFill8((u8 *)(dst + i), 0, (u32)((len - i) * 2));
}

#pragma opt_propagation off
/* dst = src * src over `n` 16-bit limbs: the diagonal terms src[k]*src[k] are
 * written first (each 32-bit product straddling limbs 2k and 2k+1), then every
 * off-diagonal term 2*src[i]*src[k] is carry-added at limb i+k. */
void BigNumSquare(u16 *dst, u16 *src, s32 n) {
    s32 srcLen = BigNumLen(src, n);
    s32 i, k, j;
    u32 product;

    if (n > srcLen * 2) {
        MI_CpuFill8((u8 *)(dst + srcLen * 2), 0, (n - srcLen * 2) * 2);
    }
    k = 0;
    if (srcLen > 0) {
        j = 0;
        do {
            if (j >= n) break;
            product = (u32)src[k] * src[k];
            dst[j] = product;
            if (j == n - 1) break;
            k++;
            dst[j + 1] = product >> 16;
            j += 2;
        } while (k < srcLen);
    }
    for (k = 0; k < srcLen; k++) {
        for (i = k + 1; i < srcLen && k + i < n; i++) {
            j = k + i;
            product = (u32)src[i] * src[k];
            if (product <= BIGNUM_DOUBLE_PRODUCT_MAX) {
                BigNumAddCarryAt(dst, product << 1, j, n);
            } else {
                BigNumAddCarryAt(dst, product, j, n);
                BigNumAddCarryAt(dst, product, j, n);
            }
        }
    }
}
#pragma opt_propagation reset
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
M2C_UNK MemMove(M2C_UNK,M2C_UNK,M2C_UNK);
u64 U64Divide(u64,u64);
s32 i;u32 digit;u16 *q,*r;s32 nb,na,bytes;u64 divisor;
q=work+n;r=q+n;
MI_CpuFill8((u8 *)q,0,n*4);
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
MemMove((s32)(q+1),(s32)q,(n*2-1)*2);
digit=U64Divide(func_020267e0((u8 *)r+bytes),divisor);
if(digit>65535)digit=65535;
again:
BigNumMulSmall(work,b,(u16)digit,n);
if(BigNumCmp(r,work,n)<0){digit--;goto again;}
BigNumSub(r,r,work,n);*q=digit;
}while(++i<n);
}
}
if(out)MI_CpuCopy8((s32)q,(s32)out,n*2);
if(rem)MI_CpuCopy8((s32)r,(s32)rem,n*2);
}
#pragma scheduling reset
void func_020269dc(u16 *arg0, u16 *arg1, u16 *arg2, s32 arg3, u16 *arg4) {
    M2C_UNK MI_CpuFill8(u8 *, s32, u32);
    M2C_UNK MI_CpuCopy8(s32, s32, s32);
    s32 BigNumLen(u16 *, s32);
    void BigNumMul(u16 *, u16 *, u16 *, s32);
    void BigNumSquare(u16 *, u16 *, s32);
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
    MI_CpuFill8((u8 *)(arg0 + 1), 0, (u32)((arg3 - 1) * 2));
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
            BigNumSquare(temp_r4, arg0, arg3);
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
/* One Montgomery multiplication step of BigNumModPow: form result = base * op
 * (op is 1 to square base, 0 to keep base, otherwise a pointer to the other
 * factor), then add montConst * modulus so the low t limbs cancel, shift those
 * t limbs out and reduce the result modulo modulus. */
void BigNumMontMul(u16 *result, u16 *base, s32 op, s32 n, s32 t, u16 *modulus, u16 *montConst, u16 *tmp, u16 *prod)
{
  M2C_UNK MI_CpuFill8(u8 *, s32, u32);
  M2C_UNK MI_CpuCopy8(s32, s32, s32);
  void BigNumAdd(u16 *, u16 *, u16 *, s32);
  void BigNumSub(u16 *, u16 *, u16 *, s32);
  s32 BigNumCmp(u16 *, u16 *, s32);
  void BigNumMul(u16 *, u16 *, u16 *, s32);
  void BigNumSquare(u16 *, u16 *, s32);
  M2C_UNK MemMove(M2C_UNK, M2C_UNK, M2C_UNK);
  s32 padBytes;

  MI_CpuCopy8((s32) result, (s32) base, n * 2);
  if (op == 1)
  {
    BigNumSquare(result, base, n);
  }
  else
    if (op != 0)
  {
    BigNumMul(result, base, (u16 *) op, n);
  }
  BigNumMul(tmp, result, montConst, t);
  padBytes = (n - t) * 2;
  MI_CpuFill8((u8 *) (tmp + t), 0, (u32) padBytes);
  BigNumMul(prod, tmp, modulus, n);
  BigNumAdd(result, result, prod, n);
  MemMove((s32) result, (s32) (result + t), (n - t) * 2);
  MI_CpuFill8((u8 *) ((result + n) - t), 0, (u32) (t * 2));
  switch (BigNumCmp(result, modulus, n))
  {
    case 0:
      MI_CpuFill8((u8 *) result, 0, (u32) (n * 2));
      return;

    case 1:
      BigNumSub(result, result, modulus, n);
      return;

  }

}

#pragma push
#pragma opt_strength_reduction off
void BigNumModPow(void *arg0, void *arg1, void *arg2, s32 arg3, void *arg4) {
    M2C_UNK MI_CpuFill8(u8 *, s32, u32);
    s32 BigNumLen(u16 *, s32);
    void BigNumSubBorrow(u16 *, u16 *, u32, s32);
    void BigNumMul(u16 *, u16 *, u16 *, s32);
    void BigNumDivMod(u16 *, u16 *, u16 *, u16 *, s32, u16 *);
    void func_02026b70(u16 *, u16 *, u16 *, s32, u16 *);
    void BigNumMontMul(u16 *, u16 *, s32, s32, s32, u16 *, u16 *, u16 *, u16 *);
    extern u16 *(*gAlloc)(s32);
    extern void (*gFree)(void *);

    s32 n = arg3;
    u16 *buf;
    s32 t;
    s32 counter;
    u16 *r6;
    s32 sp20;
    u16 *r7;
    u16 *r8;
    u16 *sp24;
    u16 *r5;
 
    buf = gAlloc(n * 0x16);
    if (buf == 0) {
        return;
    }
    MI_CpuFill8((u8 *)buf, 0, (u32)(n * 0x16));

    r6 = buf + n;
    r5 = r6 + n;
    sp24=r5;
    r7 = sp24 + n;
    r8 = r7 + n;
    r5=r8+n;
    sp20 = (s32)r5;
    r5 = (u16 *)sp20 + n;

    t = BigNumLen((u16 *)arg4, n);
    buf[t] = 1;

    func_02026b70(r6, buf, (u16 *)arg4, n, sp24);
    BigNumMul(r7, buf, r6, n);
    BigNumSubBorrow(r6, r7, 1, n);
    BigNumDivMod(r6, r6, (u16 *)arg4, (u16 *)0, n, r5);
    BigNumMul(sp24, (u16 *)arg1, buf, n);
    BigNumDivMod((u16 *)0, sp24, (u16 *)arg4, sp24, n, r5);
    BigNumDivMod((u16 *)0, buf, (u16 *)arg4, (u16 *)arg0, n, r5);

    counter=0;
    if ((t << 4) != 0) {
        do {
            BigNumMontMul((u16 *)arg0, (u16 *)sp20, 1, n, t, (u16 *)arg4, r6, r7, r8);
            {
                u16 word = ((u16 *)arg2)[t - (counter >> 4) - 1];
                if ((0x8000u >> (counter & 0x0F)) & word) {
                    BigNumMontMul((u16 *)arg0, (u16 *)sp20, (s32)sp24, n, t, (u16 *)arg4, r6, r7, r8);
                }
            }
        counter++;
        } while ((u32)counter < (u32)(t << 4));
    }
    BigNumMontMul((u16 *)arg0, (u16 *)sp20, 0, n, t, (u16 *)arg4, r6, r7, r8);

    gFree(buf);
}
#pragma pop
/* Convert `byteCount` big-endian bytes into the `limbCount`-limb big number
 * `limbs`, zero-filling the top limbs; a leading odd byte goes into the top limb
 * on its own. (Big numbers are arrays of 16-bit limbs, least significant first.) */
void BigNumFromBytes(u16 *limbs, const u8 *bytes, s32 byteCount, s32 limbCount) {
    M2C_UNK MI_CpuFill8(u8 *, s32, u32);
    u16 *out;
    s32 remaining;
    const u8 *in;

    out = limbs;
    remaining = byteCount;
    in = bytes;
    MI_CpuFill8((u8 *)out, 0, (u32)(limbCount * 2));
    in = in + (remaining - 1);
    if (remaining > 1) {
        do {
            remaining -= 2;
            *out = (s16)(in[0] + (in[-1] << 8));
            out += 1;
            in -= 2;
        } while (remaining > 1);
    }
    if (remaining > 0) {
        *out = (s16)in[0];
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

void MD5ContextInit(void) {
    M2C_UNK MD5Init();
    MD5Init();
}

void MD5ContextUpdate(void) {
    M2C_UNK MD5Update();
    MD5Update();
}

void MD5ContextFinal(void) {
    M2C_UNK func_0200c55c();
    func_0200c55c();
}

