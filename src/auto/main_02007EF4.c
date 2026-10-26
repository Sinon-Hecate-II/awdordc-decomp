/* 41 functions from 0x02007EF4 to 0x02008EF0 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u32 v[8]; } Copy32;
typedef struct { u32 v[1]; } Copy4;
typedef struct { u32 x, y, z; } CopyV3;

void func_02007ef4(u8 *src, u8 *dst, u32 size) {
    u8 *end = dst + size;
    u8 *end32 = dst + ((size >> 5) << 5);
    while (dst < end32) {
        *(Copy32 *)dst = *(Copy32 *)src;
        src += 32;
        dst += 32;
    }
    while (dst < end) {
        *(Copy4 *)dst = *(Copy4 *)src;
        src += 4;
        dst += 4;
    }
}

void func_02007f4c(CopyV3 *src, CopyV3 *dst) {
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
}

void func_02007f68(CopyV3 *src, CopyV3 *dst) {
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
}

void func_02007f8c(u8 *dst, u32 val, u32 size) {
    u32 v16;
    u32 v32;
    u32 n;

    if (size == 0)
        return;
    if ((u32)dst & 1) {
        u16 *q = (u16 *)(dst - 1);
        *q = (u16)((*q & 0xFF) | (val << 8));
        dst++;
        size--;
        if (size == 0)
            return;
    }
    if (size < 2)
        goto tail;
    v16 = val | (val << 8);
    if ((u32)dst & 2) {
        *(u16 *)dst = (u16)v16;
        dst += 2;
        size -= 2;
        if (size == 0)
            return;
    }
    v32 = v16 | (v16 << 16);
    n = size & ~3;
    if (n != 0) {
        u8 *end = dst + n;
        size -= n;
        do {
            *(u32 *)dst = v32;
            dst += 4;
        } while (dst < end);
    }
    if (size & 2) {
        *(u16 *)dst = (u16)v16;
        dst += 2;
    }
tail:
    if (size & 1) {
        u16 *q = (u16 *)dst;
        *q = (u16)((*q & 0xFF00) | (val & 0xFF));
    }
}

s32 func_020081c8(void) {
    return M2C_ERROR(/* unknown instruction: swp $r0, $r0, ($r1) */);
}

void func_020081d0(u32 *arg0,u8 *dst){
 s32 remaining=*arg0++>>8;u8 *src=(u8*)arg0;
 while(remaining>0){u32 flags=*src++; s32 bits=8;
 while(--bits>=0){if(!(flags&128)){*dst++=*src++;remaining--;}
 else{s32 count=(*src>>4)+3;u32 off=(*src++&15)<<8;off|=*src++;off++;remaining-=count;do{u32 val=dst[-off];*dst++=val;}while(--count>0);}
 if(remaining<=0)break; flags<<=1;}
 }
}

void func_02008464(u32 *arg0) {
    s32 temp_r2;
    s32 var_r2;
    s32 var_r2_2;
    u32 var_r7;
    u8 *var_r0;
    u8 temp_r4;

    var_r0 = arg0 + 4;
    var_r7 = (u32) *arg0 >> 8;
loop_1:
    if ((s32) var_r7 > 0) {
        temp_r4 = *var_r0;
        var_r0 += 1;
        temp_r2 = temp_r4 & 0x7F;
        if (!(temp_r4 & 0x80)) {
            var_r2 = temp_r2 + 1;
            var_r7 -= var_r2;
            do {
                var_r0 += 1;
                M2C_ERROR(/* unknown instruction: swpb $r3, $r3, ($r1) */);
                var_r2 -= 1;
            } while ((s64) var_r2 > 0);
        } else {
            var_r2_2 = temp_r2 + 3;
            var_r7 -= var_r2_2;
            var_r0 += 1;
            do {
                M2C_ERROR(/* unknown instruction: swpb $r4, $r5, ($r1) */);
                var_r2_2 -= 1;
            } while ((s64) var_r2_2 > 0);
        }
        goto loop_1;
    }
}

void func_020084d0(u32 *arg0, s16 *arg1) {
    u32 remaining;
    u8 *src;
    s16 *dst;
    u16 acc;
    s32 pos;
    s16 *out;

    remaining = *arg0++ >> 8;
    src = (u8 *)arg0;
    out = arg1;
    acc = 0;
    pos = 0;
    while ((s32)remaining > 0) {
        u8 hdr = *src++;
        s32 cnt = hdr & 0x7F;
        int run = (hdr & 0x80) != 0;
        if (!run) {
            cnt += 1;
        } else {
            cnt += 3;
        }
        remaining -= cnt;
        if (!run) {
            do {
                u8 x = *src++;
                acc |= (u16)(x << pos);
                pos ^= 8;
                if (pos == 0) {
                    *out++ = (s16)acc;
                    acc = 0;
                }
                cnt--;
            } while (cnt > 0);
        } else {
            u8 val = *src++;
            do {
                acc |= (u16)(val << pos);
                pos ^= 8;
                if (pos == 0) {
                    *out++ = (s16)acc;
                    acc = 0;
                }
                cnt--;
            } while (cnt > 0);
        }
    }
}

void func_02008538(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_02007d20(s32, s32);
    void func_02007da4(s32, s32, s32, s32);
    void func_01ff8480(s32, s32, s32, s32);

    s32 off;
    volatile u32 *p;

    func_02007d20(arg0, -1);
    func_02007da4(arg0, arg1, arg3, 0x1000000);

    if (arg3 != 0) {
        off = arg0;
        off = arg0 + (off << 1);
        off += 2;
        off <<= 2;

        p = (volatile u32 *)(off + 0xB0);

        if (p[0x1000000] & 0x80000000) {
            return;
        }

        func_01ff8480(arg0, arg1, arg2, 0xaf000001);
        return;
    }
}

void func_020085ac(void *arg0, s32 arg1, u32 *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, u32 *, 4) = (u32) ((u32) *arg2 >> 8);
    M2C_FIELD(arg0, s8 *, 0xB) = 0;
    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s8 *, 0xA) = 0;
}

void func_020085d4(void *arg0, s32 arg1, u32 *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, u32 *, 4) = (u32) ((u32) *arg2 >> 8);
    M2C_FIELD(arg0, s8 *, 0xB) = 0;
    M2C_FIELD(arg0, s8 *, 0xC) = 0;
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    M2C_FIELD(arg0, s8 *, 0xE) = 0;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s8 *, 0xA) = 0;
}

#pragma opt_strength_reduction off
#pragma peephole off
void func_02008604(void *arg0, s32 arg1, u32 *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, u32 *, 4) = (u32) ((u32) *arg2 >> 8);
    M2C_FIELD(arg0, s8 *, 0x18) = (s8) ((u32) (*arg2 << 0x1C) >> 0x1C);
    M2C_FIELD(arg0, s16 *, 0x14) = -1;
    M2C_FIELD(arg0, void **, 8) = (void *) (arg0 + 0x1C);
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s8 *, 0x17) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s8 *, 0x16) = 0;
}

s32 func_0200864c(void *arg0,u8 *src,s32 size){
 u8 *dst=M2C_FIELD(arg0,u8**,0);s32 remaining=M2C_FIELD(arg0,s32*,4);u32 hdr=M2C_FIELD(arg0,u8*,11);s32 cnt=M2C_FIELD(arg0,u16*,12);
 for(;;){
 if(!(hdr&128)){while(cnt>0){u8 val;cnt--;val=*src++;remaining--;*dst++=val;if(--size==0)goto done;}}
 else if(cnt>0){u8 val=*src++;do{remaining--;*dst++=val;}while(--cnt>0);if(--size==0)goto done;}
 hdr=*src++;cnt=hdr&127;if(hdr&128)cnt+=2;cnt++;if(--size==0)break;
 }
done:M2C_FIELD(arg0,u8**,0)=dst;M2C_FIELD(arg0,s32*,4)=remaining;M2C_FIELD(arg0,u8*,11)=hdr;M2C_FIELD(arg0,u16*,12)=cnt;return remaining;
}

#pragma peephole reset
#pragma opt_strength_reduction reset
void func_02008bb8(void) {
    M2C_UNK func_02007974(M2C_UNK);
    M2C_UNK func_02007ca4(M2C_UNK);
    func_02007974(3);
    func_02007ca4(0);
}

void func_02008bd0(M2C_UNK arg0) {
    M2C_UNK func_02008f88(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02008f88(1, arg0, 0, 0, 0);
}

void func_02008bf0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    func_02008f88(2, arg0, arg1, arg2, arg3);
}

void func_02008c18(M2C_UNK arg0) {
    func_02008f88(3, arg0, 0, 0, 0);
}

void func_02008c38(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02008f38(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_02008f38(arg0, 6, arg1, 2);
}

void func_02008c50(M2C_UNK arg0, M2C_UNK arg1) {
    func_02008f38(arg0, 4, arg1, 1);
}

void func_02008c68(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02008f60(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02008f60(arg0, arg1, 0xC, arg2, 2);
}

void func_02008c84(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_02008f60(arg0, arg1, 9, arg2, 1);
}

void func_02008ca0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_02008f88(9, arg0, arg1, arg2, 0);
}

void func_02008cc8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    func_02008f88(0xC, arg0, arg1, arg2, arg3);
}

void func_02008cf0(M2C_UNK arg0, M2C_UNK arg1, u32 arg2, s32 arg3) {
    M2C_UNK func_0200976c(s32);
    M2C_UNK func_02008f88(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 var_r4;
    u32 var_r5;

    var_r5 = arg2;
    var_r4 = 0;
    while (var_r4 < 8 && var_r5 != 0) {
        if (var_r5 & 1) {
            func_0200976c(var_r4);
        }
        var_r4 += 1;
        var_r5 = var_r5 >> 1;
    }
    func_02008f88(0xD, arg0, arg1, arg2, arg3);
}

void func_02008d54(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    s32 func_0200978c(M2C_UNK, M2C_UNK, s32);
    func_02008f88(0x12, arg0, arg1, arg2, func_0200978c(arg0, arg3, arg4));
}

void func_02008d94(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_02008f88(8, arg0, arg1, arg2, 0);
}

void func_02008dbc(M2C_UNK arg0, M2C_UNK arg1) {
    func_02008f88(0x1A, arg0, arg1, 0, 0);
}

void func_02008ddc(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02008f88(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_02008f88(0x1B, arg0, arg1, 0, 0);
}

void func_02008dfc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_02008f88(0x14, arg0, arg1, arg2, 0);
}

void func_02008e24(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02008f88(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02008f88(0x15, arg0, arg1, 0, 0);
}

void func_02008e44(s32 arg0, s32 arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    M2C_UNK func_02008f88(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02008f88(0xE, arg0 | (arg8 << 0x10), arg2, arg5 | ((arg6 << 0x18) | (arg7 << 0x16)), arg4 | (((arg3 << 0x1A) | (arg1 << 0x18)) | (arg9 << 0x10)));
}

void func_02008e90(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02008f88(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02008f88(0x1E, arg0, arg1, 0, 0);
}

void func_02008eb0(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02008f88(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02008f88(0x1F, arg0, arg1, 0, 0);
}

void func_02008ed0(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02008f88(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02008f88(0x20, arg0, arg1, 0, 0);
}

