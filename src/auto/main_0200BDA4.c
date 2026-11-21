/* 19 functions from 0x0200BDA4 to 0x0200CD68 (main), found by ds-decomp. */
#include "common.h"
#include "fs.h"
#include "md5.h"
#include "fs.h"
typedef struct { u32 first, second; } Unk0200FilePair;

void func_0200bda4(s32 arg0) {
    s32 OS_GetLockID(void);
    void SaveDevice_Init(void);
    void func_0200b118(void *);
    s32 RegisterArchiveName(void *, M2C_UNK, M2C_UNK);
    void func_0200b6a8(void *, s32, s32);
    s32 ConfigureArchiveLayout(void *, s32, s32, s32, s32, s32, void *, void *);
    s32 func_0200bd9c(void);
    s32 func_0200bd94(void);
    s32 func_0200bd20(void);
    s32 CardArchiveCommand(s32, s32);
    s32 func_0200bcd8(s32, s32, s32, s32);
    extern M2C_UNK gCardArchiveWork;
    extern M2C_UNK data_0212fc14;
    extern u32 data_020f5220;
    register u32 *base = (u32 *)0x27ffc40;

    M2C_FIELD(&gCardArchiveWork, s32 *, 4) = arg0;
    M2C_FIELD(&gCardArchiveWork, s32 *, 0) = OS_GetLockID();
    M2C_FIELD(&gCardArchiveWork, s32 *, 8) = 0;
    M2C_FIELD(&gCardArchiveWork, s32 *, 0xc) = 0;
    M2C_FIELD(&gCardArchiveWork, s32 *, 0x10) = 0;
    M2C_FIELD(&gCardArchiveWork, s32 *, 0x14) = 0;
    SaveDevice_Init();
    func_0200b118(&data_0212fc14);
    RegisterArchiveName(&data_0212fc14, (M2C_UNK)&data_020f5220, 3);

    if (M2C_FIELD(base, u16 *, 0) == 2) {
        M2C_FIELD(&gCardArchiveWork, s32 *, 8) = -1;
        M2C_FIELD(&gCardArchiveWork, s32 *, 0xc) = 0;
        M2C_FIELD(&gCardArchiveWork, s32 *, 0x10) = -1;
        M2C_FIELD(&gCardArchiveWork, s32 *, 0x14) = 0;
        func_0200b6a8(&data_0212fc14, (s32)func_0200bd9c, -1);
        ConfigureArchiveLayout(&data_0212fc14, 0, 0, 0, 0, 0,
                      (void *)func_0200bd94, (void *)func_0200bd20);
        return;
    }

    func_0200b6a8(&data_0212fc14, (s32)CardArchiveCommand, 0x602);

    {
        u32 v0 = base[0x80];
        if (v0 != (u32)-1 && v0 != 0) {
            u32 v2 = base[0x82];
            if (v2 != (u32)-1 && v2 != 0) {
                ConfigureArchiveLayout(&data_0212fc14, 0, (s32)v2, (s32)base[0x83], (s32)v0, (s32)base[0x81],
                              (void *)func_0200bcd8, (void *)func_0200bd20);
            }
        }
    }
}

void func_0200beec(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK LoadArchiveIndex(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0212fc14;
    LoadArchiveIndex(&data_0212fc14, arg0, arg1);
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
void ClearFileBss(void *arg0) {
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

void BuildFileRange(u32 *arg0,void *arg1) {
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
  void func_0200b774(void *);
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
  func_0200b774(work);
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
#pragma opt_strength_reduction off
s32 LoadFileHeader(u32 *arg0,s32 arg1,u32 arg2) {
void InitFileRequest(void *);s32 OpenFileRange(void *,Unk0200FilePair);void CloseFileRequest(void *);void MI_CpuCopy8();
extern u32 data_0212fc04[2],data_0212fc0c[2];extern M2C_UNK data_0212fc14;
u32 work[18];Unk0200FilePair pair;u32 *p;
p=arg1==0?data_0212fc04:data_0212fc0c;
if(p[0]){
u32 offset = arg2 << 5;
if(p[1] <= offset) return 0;
MI_CpuCopy8((const void *)(offset + p[0]),arg0,32);
arg0[8]=arg1;InitFileRequest(work);BuildFileRange((u32 *)&pair,arg0);
if(!OpenFileRange(work,pair))return 0;
arg0[9]=work[9];arg0[10]=work[10]-work[9];CloseFileRequest(work);return 1;
}
return func_0200bf8c(arg0,arg1,arg2,(s32)&data_0212fc14,*(u32 *)0x27ffe50,*(u32 *)0x27ffe54,*(u32 *)0x27ffe58,*(u32 *)0x27ffe5c);
}
#pragma opt_strength_reduction on
/* Verify that `message` carries the expected HMAC-SHA1 signature
 * (`expectedDigest`): sign it with the fixed archive key and compare the 20-byte
 * digest word by word.  Returns 1 when they match. */
s32 HmacSha1Verify(u32 expectedDigest, s32 message, s32 messageLength) {
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, s32);
    void MI_CpuCopy8();
    void HmacSha1();
    extern HmacKey gHmacSha1Key;
    u32 digest[5], i;
    u8 keyBlock[64];
    u32 *computed;
    MI_CpuFill8((s32)digest, 0, SHA1_DIGEST_SIZE);
    MI_CpuCopy8(gHmacSha1Key.data, keyBlock, gHmacSha1Key.length);
    HmacSha1(digest, message, messageLength, keyBlock, gHmacSha1Key.length);
    computed = digest;
    for (i = 0; i < SHA1_DIGEST_SIZE; i += 4, computed++)
        if (*computed != *(u32 *)(expectedDigest + i)) break;
    return i == SHA1_DIGEST_SIZE;
}

#pragma push
#pragma opt_lifetimes off
void CompleteFileLoad(void *arg0) {
    u32 func_0200bf0c(void *);
    s32 HmacSha1Verify(u32, s32, s32);
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, s32);
    void SystemHalt(void);
    void func_02000970(s32);
    M2C_UNK DC_FlushRange(M2C_UNK, M2C_UNK);
    extern u8 data_0212dbac[];
    extern s16 gGxDisplayStatus;
    void *r5;
    u32 r4;
    u32 top = 0;
    u32 idx = 0;
    u8 *end;
    u8 *start;
    s32 count = 0;
    void *p;
    s32 verified;
    u32 fn;

    r5 = arg0;
    r4 = func_0200bf0c(r5);

    if (*(u16 *)0x27ffc40 == 2) {
        top = (u32)M2C_FIELD(r5, u32 *, 0x1c) >> 24;
        verified = 0;
        if (top & 2) {
            end = (u8 *)&gGxDisplayStatus;
            start = data_0212dbac;
            idx = M2C_FIELD(r5, u32 *, 0x0);
            count = (s32)(end - start) / 20;
            if (idx < (u32)count) {
                p = start + idx * 20;
                verified = HmacSha1Verify((u32)p, M2C_FIELD(r5, s32 *, 4), r4);
            }
        }
        if (verified == 0) {
            MI_CpuFill8(M2C_FIELD(r5, s32 *, 4), 0, r4);
            SystemHalt();
            return;
        }
    }

    top = (u32)M2C_FIELD(r5, u32 *, 0x1c) >> 24;
    if (top & 1) {
        func_02000970(M2C_FIELD(r5, s32 *, 4) + (s32)r4);
    }
    DC_FlushRange(M2C_FIELD(r5, M2C_UNK *, 4), M2C_FIELD(r5, M2C_UNK *, 8));
    r4 = M2C_FIELD(r5, u32 *, 0x10);
    r5 = M2C_FIELD(r5, void **, 0x14);
    if (r4 < (u32)r5) do {
        fn = *(u32 *)r4;
        if (fn) ((void (*)(void))fn)();
        r4 += 4;
    } while (r4 < (u32)r5);
}
#pragma pop
/* Run and unregister every exit function (a static destructor registered
 * through gExitFunctionList) that belongs to the module now occupying `header`'s
 * buffer: a node is taken out when its callback address, or its nonzero
 * argument, lies in [data, data + dataSize + bssSize).  The list is walked under
 * an interrupt lock, then the functions taken out are run, and the walk repeats
 * until nothing is left to remove. */
void RunModuleExitFunctions(FSFileHeader *header) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern void *gExitFunctionList;
    s32 irq;
    u32 dataSize;
    u32 bssSize;
    u32 data;
    u32 base;
    u32 end;
    void *prev_kept;
    void *head;
    void *cur;
    void *next;
    void *removed_head;
    void *removed_tail;
    u32 exitArg;
    void (*cb)(u32);

    for (;;) {
        dataSize = header->dataSize;
        bssSize = header->bssSize;
        data = (u32)header->data;
        base = data;
        removed_head = (void *)0;
        removed_tail = (void *)0;
        end = base + (dataSize + bssSize);
        irq = OS_DisableInterrupts();
        head = gExitFunctionList;
        cur = head;
        prev_kept = (void *)0;
        if (head != (void *)0) {
            do {
                next = M2C_FIELD(cur, void **, EXIT_FUNC_NEXT);
                exitArg = M2C_FIELD(cur, u32 *, EXIT_FUNC_ARG);
                cb = M2C_FIELD(cur, void (**)(u32), EXIT_FUNC_CALLBACK);
                if ((exitArg == 0 && (u32)cb >= base && (u32)cb < end) ||
                    (exitArg >= base && exitArg < end)) {
                    if (removed_tail != (void *)0) {
                        M2C_FIELD(removed_tail, void **, EXIT_FUNC_NEXT) = cur;
                    } else {
                        removed_head = cur;
                    }
                    if (head == cur) {
                        gExitFunctionList = next;
                        head = next;
                    }
                    M2C_FIELD(cur, void **, EXIT_FUNC_NEXT) = (void *)0;
                    removed_tail = cur;
                    if (prev_kept != (void *)0) {
                        M2C_FIELD(prev_kept, void **, EXIT_FUNC_NEXT) = next;
                    }
                } else {
                    prev_kept = cur;
                }
                cur = next;
            } while (cur != (void *)0);
        }
        OS_RestoreInterrupts(irq);
        if (removed_head == NULL) break;
        do {
            cb = M2C_FIELD(removed_head, void (**)(u32), EXIT_FUNC_CALLBACK);
            removed_tail = M2C_FIELD(removed_head, void **, EXIT_FUNC_NEXT);
            if (cb != NULL) {
                cb(M2C_FIELD(removed_head, u32 *, EXIT_FUNC_ARG));
            }
            removed_head = removed_tail;
        } while (removed_tail != NULL);
    }
}

s32 func_0200c3f8(void *range) {
    RunModuleExitFunctions(range);
    return 1;
}

s32 func_0200c408(s32 arg0,s32 arg1) {s32 LoadFileHeader();u8 temp[44];if(!LoadFileHeader(temp,arg0,arg1) || !func_0200c3f8(temp)) return 0;return 1;}

void MD5Init(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
}

/* Append length bytes of message data to an MD5 context: fill the pending
 * block, compress every complete 64-byte block, and keep the tail buffered. */
void MD5Update(void *context, void *data, u32 length) {
    void MI_CpuCopy8(void *, void *, u32);
    void MD5Transform(void *);
    MD5Context *ctx = context;
    u32 rem = ctx->count[0] & 0x3f;
    u32 space = MD5_BLOCK_SIZE - rem;
    const u8 *cursor;
    s32 blocks;

    *(u64 *)ctx->count += length;
    if (space > length) {
        if (length == 0) return;
        MI_CpuCopy8(data, ctx->buffer + rem, length);
        return;
    }
    MI_CpuCopy8(data, ctx->buffer + rem, space);
    MD5Transform(ctx);
    length -= space;
    blocks = length >> 6;
    cursor = (const u8 *)data + space;
    if (blocks > 0) do {
        MI_CpuCopy8((void *)cursor, ctx->buffer, MD5_BLOCK_SIZE);
        cursor += MD5_BLOCK_SIZE;
        MD5Transform(ctx);
    } while (--blocks > 0);
    if (length & 0x3f)
        MI_CpuCopy8((void *)cursor, ctx->buffer, 0x3f & length);
}

void func_0200c55c(M2C_UNK arg0, void *arg1) {
    M2C_UNK func_02008048(void *, M2C_UNK, M2C_UNK);
    M2C_UNK func_0200c494(void *, M2C_UNK *, M2C_UNK);
    M2C_UNK func_0200c614(void *);
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
        func_02007f8c(arg1 + 0x18 + var_r3);
        func_0200c614(arg1);
        var_r3 = 0;
        var_r2 = 0x40;
    }
    if (var_r2 > 8U) {
        func_02007f8c(arg1 + 0x18 + var_r3, 0, var_r2 - 8);
    }
    M2C_FIELD(arg1, s32 *, 0x50) = temp_r7;
    M2C_FIELD(arg1, s32 *, 0x54) = temp_r6;
    func_0200c614(arg1);
    func_02008048(arg1, arg0, 0x10);
    func_02007f8c(arg1, 0, 0x58);
}

void MD5Transform(void *arg0) {
    extern u32 data_020f52f0[64];
    extern u32 data_020f5230[48];
    MD5Context *ctx = arg0;
    u32 a = ctx->state[0];
    u32 b = ctx->state[1];
    u32 c = ctx->state[2];
    u32 d = ctx->state[3];
    const u32 *words = (const u32 *)ctx->buffer;
    const u32 *word = (const u32 *)ctx->buffer;
    const u32 *constant = data_020f52f0;
    const u32 *index;
    u32 t;
    s32 i;
#define F(x, y, z) (((x) & (y)) | (~(x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & ~(z)))
#define H(x, y, z) ((z) ^ ((x) ^ (y)))
#define I(x, y, z) ((y) ^ ((x) | ~(z)))
#define STEP(f, a, b, c, d, word, k, shift) \
    t = (k) + ((word) + ((a) + f((b), (c), (d)))); \
    (a) = (b) + ((t << (shift)) | (t >> (32 - (shift))))

    for (i = 0; i < 4; i++) {
        STEP(F, a, b, c, d, word[0], constant[0], 7);
        STEP(F, d, a, b, c, word[1], constant[1], 12);
        STEP(F, c, d, a, b, word[2], constant[2], 17);
        {
            u32 lastWord = word[3];
            u32 lastConstant = constant[3];
            constant += 4;
            word += 4;
            STEP(F, b, c, d, a, lastWord, lastConstant, 22);
        }
    }
    index = data_020f5230;
    for (i = 0; i < 4; i++) {
        STEP(G, a, b, c, d, words[index[0]], constant[0], 5);
        STEP(G, d, a, b, c, words[index[1]], constant[1], 9);
        STEP(G, c, d, a, b, words[index[2]], constant[2], 14);
        {
            u32 lastWord = words[index[3]];
            u32 lastConstant = constant[3];
            constant += 4;
            index += 4;
            STEP(G, b, c, d, a, lastWord, lastConstant, 20);
        }
    }
    for (i = 0; i < 4; i++) {
        STEP(H, a, b, c, d, words[index[0]], constant[0], 4);
        STEP(H, d, a, b, c, words[index[1]], constant[1], 11);
        STEP(H, c, d, a, b, words[index[2]], constant[2], 16);
        {
            u32 lastWord = words[index[3]];
            u32 lastConstant = constant[3];
            constant += 4;
            index += 4;
            STEP(H, b, c, d, a, lastWord, lastConstant, 23);
        }
    }
    for (i = 0; i < 4; i++) {
        STEP(I, a, b, c, d, words[index[0]], constant[0], 6);
        STEP(I, d, a, b, c, words[index[1]], constant[1], 10);
        STEP(I, c, d, a, b, words[index[2]], constant[2], 15);
        {
            u32 lastWord = words[index[3]];
            u32 lastConstant = constant[3];
            constant += 4;
            index += 4;
            STEP(I, b, c, d, a, lastWord, lastConstant, 21);
        }
    }

    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
#undef STEP
#undef I
#undef H
#undef G
#undef F
}

void Sha1Init(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
    M2C_FIELD(arg0, s32 *, 0x10) = 0xC3D2E1F0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
}

/* Feed more message bytes to a SHA1 context: advance the 64-bit bit counter,
   fill and compress any pending block, compress whole blocks straight from the
   source when it is word aligned, then buffer the remainder. */
void Sha1Update(void *ctx, void *data, u32 length) {
    void MI_CpuCopy8(void *, void *, u32);
    extern void (*gSha1Transform)(void *, void *, u32);
    u8 *block;
    u32 size;
    void *src;
    u32 pending;
    u32 full;
    s32 remaining;

    size = length;
    src = data;
    block = ((Sha1Context *)ctx)->block;
    if (size == 0) {
        return;
    }
    {
        u32 lo = ((Sha1Context *)ctx)->bitCountLo;
        u32 newlo = lo + (size << 3);
        if (newlo < lo) {
            ((Sha1Context *)ctx)->bitCountHi = ((Sha1Context *)ctx)->bitCountHi + 1;
        }
        ((Sha1Context *)ctx)->bitCountHi = ((Sha1Context *)ctx)->bitCountHi + (size >> 29);
        ((Sha1Context *)ctx)->bitCountLo = newlo;
    }
    pending = ((Sha1Context *)ctx)->bufferBytes;
    if (pending != 0) {
        if (pending + size >= 0x40U) {
            u32 take = 0x40U - pending;
            MI_CpuCopy8(src, block + pending, take);
            size = size - take;
            src = (u8 *)src + take;
            gSha1Transform(ctx, block, 0x40);
            ((Sha1Context *)ctx)->bufferBytes = 0;
        } else {
            MI_CpuCopy8(src, block + pending, size);
            ((Sha1Context *)ctx)->bufferBytes = ((Sha1Context *)ctx)->bufferBytes + size;
            return;
        }
    }
    if (size >= 0x40U) {
        full = size & ~0x3fU;
        size = size - full;
        if (((u32)src & 3U) == 0U) {
            gSha1Transform(ctx, src, full);
            src = (u8 *)src + full;
        } else {
            remaining = full;
            do {
                MI_CpuCopy8(src, block, 0x40);
                src = (u8 *)src + 0x40;
                gSha1Transform(ctx, block, 0x40);
                remaining = remaining - 0x40;
            } while (remaining > 0);
        }
    }
    ((Sha1Context *)ctx)->bufferBytes = size;
    if (size == 0) {
        return;
    }
    MI_CpuCopy8(src, block, size);
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
    void CpuFill(u32, void *, s32);
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
    CpuFill(0, (void *)&ctx, 4);
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
