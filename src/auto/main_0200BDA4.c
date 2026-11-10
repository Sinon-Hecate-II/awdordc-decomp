/* 19 functions from 0x0200BDA4 to 0x0200CD68 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 first, second; } Unk0200FilePair;

void func_0200bda4(s32 arg0) {
    s32 func_0200558c(void);
    void func_02010c14(void);
    void func_0200b118(void *);
    s32 func_0200b184(void *, M2C_UNK, M2C_UNK);
    void func_0200b6a8(void *, s32, s32);
    s32 func_0200b2bc(void *, s32, s32, s32, s32, s32, void *, void *);
    s32 func_0200bd9c(void);
    s32 func_0200bd94(void);
    s32 func_0200bd20(void);
    s32 func_0200bd28(s32, s32);
    s32 func_0200bcd8(s32, s32, s32, s32);
    extern M2C_UNK data_0212fbfc;
    extern M2C_UNK data_0212fc14;
    extern u32 data_020f5220;
    register u32 *base = (u32 *)0x27ffc40;

    M2C_FIELD(&data_0212fbfc, s32 *, 4) = arg0;
    M2C_FIELD(&data_0212fbfc, s32 *, 0) = func_0200558c();
    M2C_FIELD(&data_0212fbfc, s32 *, 8) = 0;
    M2C_FIELD(&data_0212fbfc, s32 *, 0xc) = 0;
    M2C_FIELD(&data_0212fbfc, s32 *, 0x10) = 0;
    M2C_FIELD(&data_0212fbfc, s32 *, 0x14) = 0;
    func_02010c14();
    func_0200b118(&data_0212fc14);
    func_0200b184(&data_0212fc14, (M2C_UNK)&data_020f5220, 3);

    if (M2C_FIELD(base, u16 *, 0) == 2) {
        M2C_FIELD(&data_0212fbfc, s32 *, 8) = -1;
        M2C_FIELD(&data_0212fbfc, s32 *, 0xc) = 0;
        M2C_FIELD(&data_0212fbfc, s32 *, 0x10) = -1;
        M2C_FIELD(&data_0212fbfc, s32 *, 0x14) = 0;
        func_0200b6a8(&data_0212fc14, (s32)func_0200bd9c, -1);
        func_0200b2bc(&data_0212fc14, 0, 0, 0, 0, 0,
                      (void *)func_0200bd94, (void *)func_0200bd20);
        return;
    }

    func_0200b6a8(&data_0212fc14, (s32)func_0200bd28, 0x602);

    {
        u32 v0 = base[0x80];
        if (v0 != (u32)-1 && v0 != 0) {
            u32 v2 = base[0x82];
            if (v2 != (u32)-1 && v2 != 0) {
                func_0200b2bc(&data_0212fc14, 0, (s32)v2, (s32)base[0x83], (s32)v0, (s32)base[0x81],
                              (void *)func_0200bcd8, (void *)func_0200bd20);
            }
        }
    }
}

void func_0200beec(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0200b3ec(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0212fc14;
    func_0200b3ec(&data_0212fc14, arg0, arg1);
}

#pragma opt_strength_reduction off
u32 func_0200bf0c(void *arg0) {
    typedef union {
        struct { u32 value : 24; u32 enabled : 1; u32 rest : 7; } f;
        u32 w;
    } Bits;
    Bits *b = (Bits *)((u8 *)arg0 + 0x1c);
    if ((b->w >> 24) & 1) return b->f.value;
    return M2C_FIELD(arg0, u32 *, 8);
}
#pragma opt_strength_reduction reset
void func_0200bf28(void *arg0) {
    M2C_UNK DC_InvalidateRange(s32, s32);
    M2C_UNK func_0200681c(s32, s32);
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, s32);
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;

    temp_r4 = M2C_FIELD(arg0, s32 *, 4);
    temp_r5 = M2C_FIELD(arg0, s32 *, 8);
    temp_r6 = temp_r5 + M2C_FIELD(arg0, s32 *, 0xC);
    func_0200681c(temp_r4, temp_r6);
    DC_InvalidateRange(temp_r4, temp_r6);
    MI_CpuFill8(temp_r4 + temp_r5, 0, temp_r6 - temp_r5);
}

void func_0200bf64(u32 *arg0,void *arg1) {
    extern M2C_UNK data_0212fc14;
    volatile u32 tmp[2];
    u32 base = (u32)&data_0212fc14;
    u32 x = M2C_FIELD(arg1,u32 *,24);
    tmp[1] = x;
    arg0[0] = base;
    tmp[0] = base;
    arg0[1] = x;
}

#pragma scheduling off
s32 func_0200bf8c(u32 *arg0, s32 arg1, u32 arg2, s32 arg3, u32 arg4, u32 arg5, u32 arg6, u32 arg7)
{
  void InitFileRequest(void *);
  s32 func_0200b99c(void *, s32, u32, u32, s32);
  s32 func_0200bbe0(void *, void *, s32);
  void func_0200ba9c(void *);
  s32 func_0200b9e4(void *, Unk0200FilePair);
  u32 work[18];
  Unk0200FilePair pair;
  u32 size;
  u32 base;
  u32 shifted = arg2 << 5;
  int new_var;
  if (arg1 == 0)
  {
    size = arg5;
    base = arg4;
  }
  else
  {
    size = arg7;
    base = arg6;
  }
  if (size <= shifted)
  {
    return 0;
  }
  arg2++;
  arg2--;
  InitFileRequest(work);
  if (new_var = !func_0200b99c(work, arg3, base + shifted, base + size, -(shifted = 1)))
  {
    return 0;
  }
  if (func_0200bbe0(work, arg0, 32) != 32)
  {
    func_0200ba9c(work);
    return 0;
  }
  func_0200ba9c(work);
  arg0[8] = arg1;
  func_0200bf64((u32 *) (&pair), arg0);
  if (!func_0200b9e4(work, pair))
  {
    return 0;
  }
  arg0[9] = work[9];
  arg0[10] = work[10] - work[9];
  func_0200ba9c(work);
  return 1;
}
#pragma scheduling reset
s32 func_0200c084(u32 *arg0,s32 arg1,u32 arg2) {
void InitFileRequest(void *);s32 func_0200b9e4(void *,Unk0200FilePair);void func_0200ba9c(void *);void MI_CpuCopy8();
extern u32 data_0212fc04[2],data_0212fc0c[2];extern M2C_UNK data_0212fc14;
u32 work[18];Unk0200FilePair pair;u32 *p;
p=arg1==0?data_0212fc04:data_0212fc0c;
if(p[0]){
if(p[1]<=(arg2<<5))return 0;
MI_CpuCopy8(p[0]+(arg2<<5),arg0,32);
arg0[8]=arg1;InitFileRequest(work);func_0200bf64((u32 *)&pair,arg0);
if(!func_0200b9e4(work,pair))return 0;
arg0[9]=work[9];arg0[10]=work[10]-work[9];func_0200ba9c(work);return 1;
}
return func_0200bf8c(arg0,arg1,arg2,(s32)&data_0212fc14,*(u32 *)0x27ffe50,*(u32 *)0x27ffe54,*(u32 *)0x27ffe58,*(u32 *)0x27ffe5c);
}
#pragma optimization_level 4
s32 func_0200c180(u32 arg0,s32 arg1,s32 arg2) {
M2C_UNK MI_CpuFill8(s32,M2C_UNK,s32);
void MI_CpuCopy8();void func_0200cd68();
extern u32 data_020f5224[2];
u32 out[5];u8 work[64];u32 i;u32 *p;
MI_CpuFill8((s32)out,0,20);
MI_CpuCopy8(data_020f5224[0],work,data_020f5224[1]);
func_0200cd68(out,arg1,arg2,work,data_020f5224[1]);
p=out;for(i=0;i<20;i+=4,p++) if(*p!=*(u32 *)(arg0+i)) break;
return i==20;
}

void func_0200c214(void *arg0) {
    u32 func_0200bf0c(void *);
    s32 func_0200c180(u32, s32, s32);
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, s32);
    void func_02007958(void);
    void func_02000970(s32);
    M2C_UNK func_020067e0(M2C_UNK, M2C_UNK);
    extern u8 data_0212dbac[];
    extern s16 data_0212dbc0;
    void *r5;
    u32 r4;
    u32 top = 0;
    u32 idx = 0;
    u8 *start;
    u8 *end;
    s32 count = 0;
    void *p;
    u32 rr4;
    u32 rr5;
    u32 pp;
    u32 fn;

    r5 = arg0;
    r4 = func_0200bf0c(r5);

    if (*(u16 *)0x27ffc40 == 2) {
        top = (u32)M2C_FIELD(r5, u32 *, 0x1c) >> 24;
        if (top & 2) {
            start = data_0212dbac;
            end = (u8 *)&data_0212dbc0;
            idx = M2C_FIELD(r5, u32 *, 0x0);
            count = (s32)(end - start) / 20;
            if (idx < (u32)count) {
                p = start + idx * 20;
                if (func_0200c180((u32)p, M2C_FIELD(r5, s32 *, 4), r4) == 0) {
                    MI_CpuFill8(M2C_FIELD(r5, s32 *, 4), 0, r4);
                    func_02007958();
                    return;
                }
            }
        }
    }

    top = (u32)M2C_FIELD(r5, u32 *, 0x1c) >> 24;
    if (top & 1) {
        func_02000970(M2C_FIELD(r5, s32 *, 4) + (s32)r4);
    }
    func_020067e0(M2C_FIELD(r5, M2C_UNK *, 4), M2C_FIELD(r5, M2C_UNK *, 8));
    rr4 = M2C_FIELD(r5, u32 *, 0x10);
    rr5 = M2C_FIELD(r5, u32 *, 0x14);
    if (rr4 >= rr5) return;
    pp = rr4;
    while (pp < rr5) {
        fn = *(u32 *)pp;
        if (fn) ((void (*)(void))fn)();
        pp += 4;
    }
}

M2C_UNK func_0200c308(void *arg0) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern void *data_0213ea14;
    s32 irq;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 base;
    u32 end;
    void *head;
    void *cur;
    void *next;
    void *prev_kept;
    void *removed_head;
    void *removed_tail;
    u32 node_arg;
    void (*cb)(u32);

    f8 = M2C_FIELD(arg0, u32 *, 8);
    fc = M2C_FIELD(arg0, u32 *, 0xC);
    f4 = M2C_FIELD(arg0, u32 *, 4);
    base = f4;
    removed_head = (void *)0;
    removed_tail = (void *)0;
    end = base + f8 + fc;
    irq = OS_DisableInterrupts();
    head = data_0213ea14;
    cur = head;
    prev_kept = (void *)0;
    if (head != (void *)0) {
        while (cur != (void *)0) {
            next = M2C_FIELD(cur, void **, 0);
            node_arg = M2C_FIELD(cur, u32 *, 8);
            cb = M2C_FIELD(cur, void (**)(u32), 4);
            if ((node_arg == 0 && (u32)cb >= base && (u32)cb < end) ||
                (node_arg != 0 && node_arg >= base && node_arg < end)) {
                if (removed_tail != (void *)0) {
                    M2C_FIELD(removed_tail, void **, 0) = cur;
                } else {
                    removed_head = cur;
                }
                M2C_FIELD(cur, void **, 0) = (void *)0;
                if (cur == head) {
                    data_0213ea14 = next;
                    head = next;
                }
                if (prev_kept != (void *)0) {
                    M2C_FIELD(prev_kept, void **, 0) = next;
                }
                removed_tail = cur;
            } else {
                prev_kept = cur;
            }
            cur = next;
        }
    }
    OS_RestoreInterrupts(irq);
    cur = removed_head;
    while (cur != (void *)0) {
        next = M2C_FIELD(cur, void **, 0);
        cb = M2C_FIELD(cur, void (**)(u32), 4);
        if (cb != (void *)0) {
            cb(M2C_FIELD(cur, u32 *, 8));
        }
        cur = next;
    }
}

s32 func_0200c3f8(void) {
    M2C_UNK func_0200c308();
    func_0200c308();
    return 1;
}

s32 func_0200c408(s32 arg0,s32 arg1) {s32 func_0200c084();u8 temp[44];if(!func_0200c084(temp,arg0,arg1) || !((s32 (*)())func_0200c3f8)(temp)) return 0;return 1;}

void func_0200c454(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
}

void func_0200c494(void *arg0, void *arg1, u32 arg2) {
    void MI_CpuCopy8(void *, void *, u32);
    void func_0200c614(void *);
    u64 total = M2C_FIELD(arg0, u64 *, 0x10);
    u32 rem = (u32)total & 0x3f;
    u32 space = 0x40 - rem;
    s32 n;

    M2C_FIELD(arg0, u64 *, 0x10) = total + arg2;
    if (space > arg2) {
        if (arg2 == 0) return;
        MI_CpuCopy8(arg1, (u8 *)arg0 + 0x18 + rem, arg2);
        return;
    }
    MI_CpuCopy8(arg1, (u8 *)arg0 + 0x18 + rem, space);
    func_0200c614(arg0);
    arg2 -= space;
    n = arg2 >> 6;
    arg1 = (u8 *)arg1 + space;
    while (n > 0) {
        MI_CpuCopy8(arg1, (u8 *)arg0 + 0x18, 0x40);
        arg1 = (u8 *)arg1 + 0x40;
        func_0200c614(arg0);
        n = n - 1;
    }
    if (arg2 & 0x3f)
        MI_CpuCopy8(arg1, (u8 *)arg0 + 0x18, 0x3f & arg2);
}

void func_0200c55c(M2C_UNK arg0, void *arg1) {
    void func_0200c494(void *, void *, u32);
    void func_0200c614(void *);
    s32 MI_CpuFill8();
    void MI_CpuCopy8();
    extern M2C_UNK data_020f522c;
    s32 temp_r6;
    s32 temp_r7;
    s32 var_r3;
    u32 temp_r3;
    u32 var_r2;

    temp_r3 = M2C_FIELD(arg1, u32 *, 0x10);
    temp_r6 = (M2C_FIELD(arg1, s32 *, 0x14) * 8) | (temp_r3 >> 0x1D);
    temp_r7 = temp_r3 * 8;
    func_0200c494(arg1, &data_020f522c, 1);
    var_r3 = M2C_FIELD(arg1, u32 *, 0x10) & 0x3F;
    var_r2 = 0x40 - var_r3;
    if (var_r2 < 8U) {
        MI_CpuFill8(arg1 + 0x18 + var_r3);
        func_0200c614(arg1);
        var_r3 = 0;
        var_r2 = 0x40;
    }
    if (var_r2 > 8U) {
        MI_CpuFill8(arg1 + 0x18 + var_r3, 0, var_r2 - 8);
    }
    M2C_FIELD(arg1, s32 *, 0x50) = temp_r7;
    M2C_FIELD(arg1, s32 *, 0x54) = temp_r6;
    func_0200c614(arg1);
    MI_CpuCopy8(arg1, arg0, 0x10);
    MI_CpuFill8(arg1, 0, 0x58);
}

void func_0200c614(void *arg0) { (void)arg0; }

void func_0200c9c8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
    M2C_FIELD(arg0, s32 *, 0x10) = 0xC3D2E1F0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
}

void func_0200ca18(void *arg0, void *arg1, u32 arg2) {
    void MI_CpuCopy8(void *, void *, u32);
    extern void (*gSha1Transform)(void *, void *, u32);
    u8 *buf;
    u32 size;
    void *src;
    u32 pending;
    u32 full;
    s32 remaining;

    size = arg2;
    src = arg1;
    buf = (u8 *)arg0 + 0x20;
    if (size == 0) {
        return;
    }
    {
        u32 lo = M2C_FIELD(arg0, u32 *, 0x14);
        u32 newlo = lo + (size << 3);
        if (newlo < lo) {
            M2C_FIELD(arg0, u32 *, 0x18) = M2C_FIELD(arg0, u32 *, 0x18) + 1;
        }
        M2C_FIELD(arg0, u32 *, 0x18) = M2C_FIELD(arg0, u32 *, 0x18) + (size >> 29);
        M2C_FIELD(arg0, u32 *, 0x14) = newlo;
    }
    pending = M2C_FIELD(arg0, u32 *, 0x1C);
    if (pending != 0) {
        if (pending + size >= 0x40U) {
            u32 take = 0x40U - pending;
            MI_CpuCopy8(src, buf + pending, take);
            size = size - take;
            src = (u8 *)src + take;
            gSha1Transform(arg0, buf, 0x40);
            M2C_FIELD(arg0, u32 *, 0x1C) = 0;
        } else {
            MI_CpuCopy8(src, buf + pending, size);
            M2C_FIELD(arg0, u32 *, 0x1C) = M2C_FIELD(arg0, u32 *, 0x1C) + size;
            return;
        }
    }
    if (size >= 0x40U) {
        full = size & ~0x3fU;
        size = size - full;
        if (((u32)src & 3U) == 0U) {
            gSha1Transform(arg0, src, full);
            src = (u8 *)src + full;
        } else {
            remaining = full;
            do {
                MI_CpuCopy8(src, buf, 0x40);
                src = (u8 *)src + 0x40;
                gSha1Transform(arg0, buf, 0x40);
                remaining = remaining - 0x40;
            } while (remaining > 0);
        }
    }
    M2C_FIELD(arg0, u32 *, 0x1C) = size;
    if (size == 0) {
        return;
    }
    MI_CpuCopy8(src, buf, size);
}

#pragma opt_propagation off
#pragma opt_common_subs off
/* Finalizes a SHA1 context of the game's hash module: the context holds the
 * five-word state (+0x00), the low and high words of the bit count (+0x14,
 * +0x18), the buffered byte count (+0x1c) and the 64-byte block (+0x20).
 * Pads the message, compresses the final block and writes the 20-byte
 * big-endian digest to digest. */
void SHA1_Finalize(void *ctx, void *digest) {
    extern void (*gSha1Transform)(void *, void *, u32);
    void func_02007e54(u32, void *, s32);
    register u32 *words;
    register u8 *block;
    u8 *digestOut;
    register s32 wordIndex;
    s32 used;
    u32 lengthLo;
    u32 lengthHi;
    u32 state0;
    u32 state1;
    u32 state2;
    u32 state3;
    u32 state4;

    words = (u32 *)((u8 *)ctx + 0x20);
        digestOut = (u8 *)digest;
    used = *(s32 *)((u8 *)ctx + 0x1c);
    wordIndex = used >> 2;

    if ((used & 3) == 0) {
        words[wordIndex] = 0;
    }
    block = (u8 *)ctx + 0x20;
    
    block[used] = 0x80;
    used = used + 1;
    while (used & 3) {
        block[used] = 0;
        used = used + 1;
    }
    wordIndex++;
    if (*(s32 *)((u8 *)ctx + 0x1c) >= 0x38) {
        while (wordIndex < 16) {
            words[wordIndex] = 0;
            wordIndex = wordIndex + 1;
        }
        gSha1Transform(ctx, words, 0x40);
        wordIndex = 0;
    }
    while (wordIndex < 14) {
        words[wordIndex] = 0;
        wordIndex++;
    }
    lengthLo = *(u32 *)((u8 *)ctx + 0x14);
    block[0x3f] = (u8)lengthLo;
    block[0x3e] = (u8)(lengthLo >> 8);
    block[0x3d] = (u8)(lengthLo >> 16);
    block[0x3c] = (u8)(lengthLo >> 24);
    lengthHi = *(u32 *)((u8 *)ctx + 0x18);
    block[0x3b] = (u8)lengthHi;
    block[0x3a] = (u8)(lengthHi >> 8);
    block[0x39] = (u8)(lengthHi >> 16);
    block[0x38] = (u8)(lengthHi >> 24);
    gSha1Transform(ctx, words, 0x40);

    state0 = *(u32 *)((u8 *)ctx + 0x00);

    digestOut[0] = (u8)(state0 >> 24);
    digestOut[1] = (u8)(state0 >> 16);
    digestOut[2] = (u8)(state0 >> 8);
    digestOut[3] = (u8)state0;
    state1 = *(u32 *)((u8 *)ctx + 0x04);
    digestOut[4] = (u8)(state1 >> 24);
    digestOut[5] = (u8)(state1 >> 16);
    digestOut[6] = (u8)(state1 >> 8);
    digestOut[7] = (u8)state1;
    state2 = *(u32 *)((u8 *)ctx + 0x08);
    digestOut[8] = (u8)(state2 >> 24);
    digestOut[9] = (u8)(state2 >> 16);
    digestOut[10] = (u8)(state2 >> 8);
    digestOut[11] = (u8)state2;
    state3 = *(u32 *)((u8 *)ctx + 0x0c);
    digestOut[12] = (u8)(state3 >> 24);
    digestOut[13] = (u8)(state3 >> 16);
    digestOut[14] = (u8)(state3 >> 8);
    digestOut[15] = (u8)state3;
    state4 = *(u32 *)((u8 *)ctx + 0x10);
    digestOut[16] = (u8)(state4 >> 24);
    digestOut[17] = (u8)(state4 >> 16);
    digestOut[18] = (u8)(state4 >> 8);
    digestOut[19] = (u8)state4;

    *(u32 *)((u8 *)ctx + 0x1c) = 0;
    func_02007e54(0, (void *)&ctx, 4);
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
