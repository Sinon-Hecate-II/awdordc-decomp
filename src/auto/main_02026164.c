/* 28 functions from 0x02026164 to 0x020270B4 (main), found by ds-decomp. */
#include "common.h"

void func_02026164(u8 *state, const u8 *key, s32 keylen) {
    s32 i;
    u8 *S;
    s32 jj;
    s32 ii;
    s32 k;
    u8 sk;
    u8 keybyte;
    u8 sj;

    state[0] = 0;
    state[1] = 0;
    S = state + 2;
    for (i = 0; i < 256; i++) {
        S[i] = (u8)i;
    }
    ii = 0;
    jj = 0;
    for (k = 0; k < 256; k++) {
        sk = S[k];
        keybyte = key[ii];
        ii = (ii + 1) & 0xff;
        if (ii >= keylen) {
            ii = 0;
        }
        jj = (jj + sk + keybyte) & 0xff;
        sj = S[jj];
        S[k] = sj;
        S[jj] = sk;
    }
}

void func_020261d8(u8 *state, u8 *data, s32 len) {
    u8 *S = state + 2;
    u8 i = state[0];
    u8 j = state[1];
    s32 n;
    for (n = 0; n < len; n++) {
        u8 si;
        u8 sj;
        u8 k;
        i = (u8)((i + 1) & 0xff);
        si = S[i];
        j = (u8)((j + si) & 0xff);
        sj = S[j];
        S[i] = sj;
        S[j] = si;
        k = (u8)((si + sj) & 0xff);
        data[n] ^= S[k];
    }
    state[0] = i;
    state[1] = j;
}

s32 func_02026244(u16 *arr, s32 n) {
    s32 var_r1 = n;
    while (var_r1 != 0 && arr[var_r1 - 1] == 0) {
        var_r1 -= 1;
    }
    return var_r1;
}

s32 func_0202626c(u16 *arr, s32 n) {
    if ((arr[n - 1] & 0x8000) != 0) {
        return -1;
    }
    return func_02026244(arr, n) != 0;
}

void func_0202629c(u16 *dst, u16 *src1, u16 *src2, s32 len) {
    s32 a;
    s32 b;
    s32 m;
    s32 k;
    u32 carry;

    a = func_02026244(src1, len);
    b = func_02026244(src2, len);
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

void func_0202639c(u16 *arr, s32 n) {
    void func_02026338(u16 *, u16 *, u32, s32);
    s32 i;
    for (i = 0; i < n; i++) {
        arr[i] = ~arr[i];
    }
    func_02026338(arr, arr, 1, n);
}

void func_020263dc(u16 *dst, u16 *src1, u16 *src2, s32 len) {
    s32 func_02026244(u16 *, s32);
    M2C_UNK func_02007f8c(u8 *, s32, u32);
    s32 a;
    s32 b;
    s32 m;
    s32 k;
    s32 borrow;

    a = func_02026244(src1, len);
    b = func_02026244(src2, len);
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
    while (i < len) {
        s = carry + arr[i];
        arr[i] = (u16)s;
        i++;
        carry = s >> 16;
        if (carry != 0) continue;
        return;
    }
}

void func_02026558(u16 *dst, u16 *src1, u16 *src2, s32 len) {
    M2C_UNK func_02007f8c(u8 *, s32, u32);
    s32 func_02026244(u16 *, s32);
    void func_02026524(u16 *, u32, s32, s32);
    s32 a;
    s32 b;
    s32 i;
    s32 j;

    func_02007f8c((u8 *)dst, 0, (u32)(len * 2));
    a = func_02026244(src1, len);
    b = func_02026244(src2, len);
    if (b <= 0) return;
    i = 0;
    while (i < b) {
        j = 0;
        while (j < a && j < len - i) {
            func_02026524(dst, (u32)src1[j] * (u32)src2[i], i + j, len);
            j++;
        }
        i++;
    }
}

void func_02026604(u16 *dst, u16 *src, s32 mult, s32 len) {
    M2C_UNK func_02007f8c(u8 *, s32, u32);
    s32 func_02026244(u16 *, s32);
    s32 n;
    u32 carry;
    s32 k;

    n = func_02026244(src, len);
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

s32 func_020267b0(u16 *arg0) {
    if (*(volatile u16 *)arg0) {
    }
    return 0;
}

s32 func_020267bc(volatile u16 *arg0) {
    if (arg0[0]) {
    }
    return arg0[-1] << 0x10;
}

s32 func_020267cc(volatile u16 *arg0) {
    return (arg0[0], (arg0[-1] << 0x10) | arg0[-2]);
}

s32 func_020267e0(void *arg0) {
    return M2C_FIELD(arg0, u16 *, -6) | (M2C_FIELD(arg0, u16 *, -4) << 0x10);
}

void func_02026ff0(s16 *dst, u8 *src, s32 count, s32 size) {
    M2C_UNK func_02007f8c(u8 *, s32, u32);
    s16 *var_r4;
    s32 var_r5;
    u8 *var_r6;

    var_r4 = dst;
    var_r5 = count;
    func_02007f8c((u8 *)var_r4, 0, (u32)(size * 2));
    var_r6 = src + (var_r5 - 1);
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

void func_0202704c(u8 *dst, u16 *src, s32 n) {
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

