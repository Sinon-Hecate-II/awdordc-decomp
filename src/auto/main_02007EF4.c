/* 41 functions from 0x02007EF4 to 0x02008EF0 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u32 v[8]; } Copy32;
typedef struct { u32 v[1]; } Copy4;
typedef struct { u32 x, y, z; } CopyV3;

void MI_CpuCopy32(u8 *src, u8 *dst, u32 size) {
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

void MTX_Copy33(CopyV3 *src, CopyV3 *dst) {
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
}

void MTX_Copy43(CopyV3 *src, CopyV3 *dst) {
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
}

void MI_CpuFill8(u8 *dst, u32 val, u32 size) {
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

void Ov001_DecompressBuffer(u32 *arg0,u8 *dst){
 s32 remaining=*arg0++>>8;u8 *src=(u8*)arg0;
 while(remaining>0){u32 flags=*src++; s32 bits=8;
 while(--bits>=0){if(!(flags&128)){*dst++=*src++;remaining--;}
 else{s32 count=(*src>>4)+3;u32 off=(*src++&15)<<8;off|=*src++;off++;remaining-=count;do{u32 val=dst[-off];*dst++=val;}while(--count>0);}
 if(remaining<=0)break; flags<<=1;}
 }
}

void func_0200826c(u32 *arg0, s16 *arg1) {
    u8 *in = (u8 *)arg0;
    s16 *out = arg1;
    s32 acc = 0;
    s32 bit = 0;
    s32 remaining = (s32)(*arg0 >> 8);
    in += 4;
    while (remaining > 0) {
        u8 code = *in++;
        s32 n = 8;
        for (;;) {
            if (--n < 0) break;
            if (!(code & 0x80)) {
                acc |= (*in++) << bit;
                remaining--;
                bit ^= 8;
                if (bit == 0) *out++ = acc;
                if (bit == 0) acc = 0;
            } else {
                s32 count = 3 + (*in >> 4);
                u32 len = (((*in++ & 0xF) << 8) | *in++) + 1;
                s32 shift = (8 - bit) ^ ((len & 1) << 3);
                remaining -= count;
                do {
                    u32 dist;
                    u32 word;
                    s32 val;
                    shift ^= 8;
                    dist = ((len + ((8 - bit) >> 3)) >> 1) << 1;
                    word = *(u16 *)((u8 *)out - dist);
                    val = (word & (0xFF << shift)) >> shift;
                    acc |= val << bit;
                    bit ^= 8;
                    if (bit == 0) *out++ = acc;
                    if (bit == 0) acc = 0;
                    count--;
                } while (count > 0);
            }
            if (remaining <= 0) break;
            code <<= 1;
        }
    }
}

#pragma push
#pragma optimize_for_size on
void func_0200836c(void *arg0, u32 *arg1) {
    s32 sp0;
    s32 temp_r2;
    s32 temp_r4;
    s32 temp_r6;
    s32 temp_r9;
    s32 var_lr;
    s32 var_r8;
    u32 *var_r0;
    u32 *var_r1;
    u32 var_ip;
    u32 var_r3;
    u32 var_r5;
    u8 *temp_r7;
    u8 *var_r2;

    var_r1 = arg1;
    temp_r2 = arg0 + 4;
    temp_r7 = temp_r2 + 1;
    temp_r4 = M2C_FIELD(arg0, u8 *, 0) & 0xF;
    var_r3 = 0;
    var_lr = 0;
    sp0 = (temp_r4 & 7) + 4;
    var_ip = M2C_FIELD(arg0, u32 *, 0) >> 8;
    var_r0 = temp_r2 + ((M2C_FIELD(arg0, u8 *, 4) + 1) * 2);
    var_r2 = temp_r7;
loop_1:
    if ((s32) var_ip > 0) {
        var_r8 = 0x20;
        var_r5 = *var_r0;
        var_r0++;
loop_3:
        var_r8 -= 1;
        if ((s32) var_r8 >= 0) {
            temp_r9 = 1 & (var_r5 >> 0x1F);
            temp_r6 = *var_r2 << temp_r9;
            var_r2 = (((u32) var_r2 >> 1) * 2) + (((*var_r2 & 0x3F) + 1) * 2) + temp_r9;
            if (temp_r6 & 0x80) {
                var_r3 = (var_r3 >> temp_r4) | (*var_r2 << (0x20 - temp_r4));
                var_r2 = temp_r7;
                var_lr += 1;
                if (var_lr == sp0) {
                    *var_r1 = var_r3;
                    var_r1++;
                    var_ip -= 4;
                    var_lr = 0;
                }
            }
            if ((s32) var_ip > 0) {
                var_r5 *= 2;
                goto loop_3;
            }
        }
        goto loop_1;
    }
}
#pragma pop
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

#pragma thumb on
void func_020084d0(const u8 *src, u16 *out) {
u32 acc=0; s32 remaining=*(const u32 *)src>>8; s32 pos=0;
volatile u32 header; volatile u32 val;
src+=4;
while(remaining>0) {
s32 cnt;
header=*src; ++src;
cnt=(header<<25)>>25;
if((header>>7)==0) {
cnt++; remaining-=cnt;
do { acc|=*src<<pos; ++src; pos^=8; if(!pos) {*out++=acc;acc=0;} }while(--cnt>0);
} else {
cnt+=3; remaining-=cnt;
val=*src; ++src;
do {acc|=val<<pos;pos^=8;if(!pos){*out++=acc;acc=0;}}while(--cnt>0);
}
}
}
#pragma thumb off
void func_02008538(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 DmaCheckChannelConflict(s32, s32);
    void DmaValidateTransfer(s32, s32, s32, s32);
    void DmaStartTransferLocked(s32, s32, s32, s32);

    s32 off;
    volatile u32 *p;

    DmaCheckChannelConflict(arg0, -1);
    DmaValidateTransfer(arg0, arg1, arg3, 0x1000000);

    if (arg3 != 0) {
        off = arg0;
        off = arg0 + (off << 1);
        off += 2;
        off <<= 2;

        p = (volatile u32 *)(off + 0xB0);

        if (p[0x1000000] & 0x80000000) {
            return;
        }

        DmaStartTransferLocked(arg0, arg1, arg2, 0xaf000001);
        return;
    }
}

void InitRleDecompress(void *arg0, s32 arg1, u32 *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, u32 *, 4) = (u32) ((u32) *arg2 >> 8);
    M2C_FIELD(arg0, s8 *, 0xB) = 0;
    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s8 *, 0xA) = 0;
}

void InitLz77Decompress(void *arg0, s32 arg1, u32 *arg2) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, u32 *, 4) = (u32) ((u32) *arg2 >> 8);
    M2C_FIELD(arg0, s8 *, 0xB) = 0;
    M2C_FIELD(arg0, s8 *, 0xC) = 0;
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    M2C_FIELD(arg0, s8 *, 0xE) = 0;
    M2C_FIELD(arg0, s16 *, 8) = 0;
    M2C_FIELD(arg0, s8 *, 0xA) = 0;
}

#pragma push
#pragma opt_propagation off
/* Initialise the Huffman decoder state (DecompressState +0x04): store the output
 * address and the decompressed size from the block header, take the header's low
 * nibble as the output pixel width, point the node pointer at the decoder's own
 * symbol buffer and clear the accumulators. */
void InitHuffmanDecompress(void *decoder, s32 dest, s32 *header) {
M2C_FIELD(decoder,s32 *,HUFFMAN_OUTPUT)=dest;
M2C_FIELD(decoder,u32 *,HUFFMAN_REMAINING)=(u32)*header>>8;
M2C_FIELD(decoder,s8 *,HUFFMAN_WORD_SHIFT)=(u32)(*header<<28)>>28;
M2C_FIELD(decoder,s16 *,HUFFMAN_NODE_COUNT)=-1;
M2C_FIELD(decoder,void **,HUFFMAN_NODE)=(u8 *)decoder+HUFFMAN_BUFFER;
M2C_FIELD(decoder,s32 *,HUFFMAN_OUT_WORD)=0;
M2C_FIELD(decoder,s8 *,HUFFMAN_WORD_BITS)=0;
M2C_FIELD(decoder,s32 *,HUFFMAN_BITS)=0;
M2C_FIELD(decoder,s8 *,HUFFMAN_BIT_COUNT)=0;
}
#pragma pop
s32 RleDecompress8Bit(void *arg0,u8 *src,s32 size){
 u8 *dst=M2C_FIELD(arg0,u8**,0);s32 remaining=M2C_FIELD(arg0,s32*,4);u32 hdr=M2C_FIELD(arg0,u8*,11);s32 cnt=M2C_FIELD(arg0,u16*,12);
 for(;;){
 if(!(hdr&128)){while(cnt>0){u8 val;cnt--;val=*src++;remaining--;*dst++=val;if(--size==0)goto done;}}
 else if(cnt>0){u8 val=*src++;do{remaining--;*dst++=val;}while(--cnt>0);if(--size==0)goto done;}
 hdr=*src++;cnt=hdr&127;if(hdr&128)cnt+=2;cnt++;if(--size==0)break;
 }
done:M2C_FIELD(arg0,u8**,0)=dst;M2C_FIELD(arg0,s32*,4)=remaining;M2C_FIELD(arg0,u8*,11)=hdr;M2C_FIELD(arg0,u16*,12)=cnt;return remaining;
}

#pragma push
#pragma opt_strength_reduction off
s32 RleDecompress16Bit(void *arg0,u8 *src,s32 size){
 struct S { u16 *out; s32 remain; u16 acc; u8 pos; u8 hdr; u16 cnt; };
 volatile struct S *s=arg0;
 u32 out;s32 remaining;u32 hdr;s32 cnt;u32 acc;s32 pos;u32 val;
 out=(u32)s->out;remaining=s->remain;hdr=s->hdr;cnt=s->cnt;acc=s->acc;pos=s->pos;
loop:
 if(remaining<=0)goto done;
 if(!(hdr&128)){
lit:
  if(cnt<=0)goto next;
  val=*src++;cnt--;acc|=val<<pos;pos+=8;if(pos==16){*(u16*)out=acc;out+=2;acc=0;pos=0;remaining-=2;}size--;
  if (size) goto lit;
  goto done;
 }
 else if(cnt>0){val=*src++;do{acc|=val<<pos;pos+=8;if(pos==16){*(u16*)out=acc;out+=2;acc=0;pos=0;remaining-=2;}}while(--cnt>0);if(--size==0)goto done;}
next:
 hdr=*src++;cnt=hdr&127; if ((hdr&128)==0) goto increment; cnt+=2;
increment: cnt++;if(--size!=0)goto loop;
done:s->out=(u16*)out;s->remain=remaining;s->hdr=hdr;s->cnt=cnt;s->acc=acc;s->pos=pos;return remaining;
}
#pragma pop
s32 Lz77Decompress8Bit(void *arg0, u8 *src, s32 size) {
    struct S { u8 *out; s32 remain; u16 unk8; u8 unkA; u8 hdr; u8 cnt; u8 prev; u8 have; };
    volatile struct S *s = (volatile struct S *)arg0;
    u8 *out = s->out;
    s32 remain = s->remain;
    u32 hdr = s->hdr;
    s32 cnt = s->cnt;
    u32 prev = s->prev;
    u32 have = s->have;

    if (remain <= 0) goto done;
    if (cnt == 0) goto reload;
loop:
    if (size == 0) goto done;
    if (!(hdr & 0x80)) {
        *out++ = *src++;
        remain--;
        size--;
    } else {
        if (have == 0) {
            prev = *src++;
            have = 1;
            size--;
        }
        if (size == 0) goto done;
        {
            u32 dist = (((prev & 0xF) << 8) | *src++) + 1;
            s32 count = 3 + ((s32)prev >> 4);
            have = 0;
            size--;
            if (count != 0) {
                do {
                    *out = out[-(s32)dist];
                    out++;
                    remain--;
                } while (--count > 0);
            }
        }
    }
    if (remain == 0) goto done;
    hdr <<= 1;
    if (--cnt != 0) goto loop;
reload:
    if (size == 0) goto done;
    hdr = *src++;
    cnt = 8;
    size--;
    goto loop;
done:
    s->out = out;
    s->remain = remain;
    s->hdr = hdr;
    s->cnt = cnt;
    s->prev = prev;
    s->have = have;
    return remain;
}

s32 Lz77Decompress16Bit(void *arg0, u8 *arg1, s32 arg2) {
    s32 temp_ip;
    s32 temp_r11_3;
    s32 var_r2;
    s32 var_r4;
    u16 *var_r3;
    u32 var_lr;
    u32 var_r9;
    u8 *var_r1;
    u8 temp_r11;
    u8 temp_r11_2;
    s32 var_r10;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    s32 var_r8;

    var_r1 = arg1;
    var_r2 = arg2;
    var_r3 = M2C_FIELD(arg0, u16 **, 0);
    var_r4 = M2C_FIELD(arg0, s32 *, 4);
    var_r5 = M2C_FIELD(arg0, u8 *, 0xB);
    var_r6 = M2C_FIELD(arg0, u8 *, 0xC);
    var_r7 = M2C_FIELD(arg0, u8 *, 0xD);
    var_r8 = M2C_FIELD(arg0, u8 *, 0xE);
    var_r9 = M2C_FIELD(arg0, u16 *, 8);
    var_r10 = M2C_FIELD(arg0, u8 *, 0xA);
loop_1:
    if (var_r4 > 0) {
        if (var_r6 != 0) {
loop_3:
            if (var_r2 != 0) {
                if (!(var_r5 & 0x80)) {
                    temp_r11 = *var_r1;
                    var_r1 += 1;
                    var_r2 -= 1;
                    var_r9 |= temp_r11 << var_r10;
                    var_r10 += 8;
                    if (var_r10 == 0x10) {
                        *var_r3 = var_r9;
                        var_r3 += 1;
                        var_r4 -= 2;
                        var_r9 = 0;
                        var_r10 = 0;
                    }
                    goto block_23;
                }
                if (var_r8 == 0) {
                    var_r7 = *var_r1;
                    var_r1 += 1;
                    var_r8 = 1;
                    var_r2 -= 1;
                }
                if (var_r2 != 0) {
                    temp_r11_2 = *var_r1;
                    var_r1 += 1;
                    var_r8 = 0;
                    var_r2 -= 1;
                    temp_r11_3 = (temp_r11_2 | ((var_r7 & 0xF) << 8)) + 1;
                    var_r7 = ((s32) var_r7 >> 4) + 3;
                    if (var_r7 != 0) {
                        do {
                            temp_ip = temp_r11_3 - (var_r10 >> 3);
                            if (temp_ip == 0) {
                                var_r9 |= (var_r9 & 0xF) << 8;
                            } else {
                                var_lr = *(var_r3 - ((u32) (temp_ip + 1) >> 1));
                                if (!(temp_ip & 1)) {

                                } else {
                                    var_lr = (var_lr >> 8);
                                }
                                if (temp_ip & 1) {

                                } else {
                                    var_lr = var_lr & 255;
                                }
                                var_r9 |= var_lr << var_r10;
                            }
                            var_r10 += 8;
                            if (var_r10 == 0x10) {
                                *var_r3 = var_r9;
                                var_r3 += 1;
                                var_r4 -= 2;
                                var_r9 = 0;
                                var_r10 = 0;
                            }
                            var_r7 -= 1;
                        } while ((s64) (s32) var_r7 > 0);
                    }
block_23:
                    if (var_r4 != 0) {
                        var_r5 *= 2;
                        var_r6 -= 1;
                        if (var_r6 == 0) {
                            goto block_25;
                        }
                        goto loop_3;
                    }
                }
            }
        } else {
block_25:
            if (var_r2 != 0) {
                var_r5 = *var_r1;
                var_r1 += 1;
                var_r6 = 8;
                var_r2 -= 1;
                goto loop_1;
            }
        }
    }
    M2C_FIELD(arg0, u16 **, 0) = var_r3;
    M2C_FIELD(arg0, s32 *, 4) = var_r4;
    M2C_FIELD(arg0, u8 *, 0xB) = var_r5;
    M2C_FIELD(arg0, u8 *, 0xC) = var_r6;
    M2C_FIELD(arg0, u8 *, 0xD) = var_r7;
    M2C_FIELD(arg0, u8 *, 0xE) = var_r8;
    M2C_FIELD(arg0, u16 *, 8) = var_r9;
    M2C_FIELD(arg0, u8 *, 0xA) = var_r10;
    return var_r4;
}

s32 HuffmanDecompress(void *arg0, u8 *arg1, s32 arg2) {
    s16 var_r8;
    s32 temp_gt;
    s32 temp_ip_2;
    s32 var_r2;
    s32 var_r4;
    u32 *var_r3;
    u32 temp_ip_3;
    u32 var_r6;
    u32 var_r7;
    u8 *var_r1;
    u8 *var_r5;
    u8 temp_ip;
    u8 temp_lr;
    u8 temp_r11;
    u8 temp_r8;
    u8 var_r10;
    u8 var_r9;

    var_r1 = arg1;
    var_r2 = arg2;
    var_r3 = M2C_FIELD(arg0, u32 **, 0);
    var_r4 = M2C_FIELD(arg0, s32 *, 4);
    var_r5 = M2C_FIELD(arg0, u8 **, 8);
    var_r6 = M2C_FIELD(arg0, u32 *, 0xC);
    var_r7 = M2C_FIELD(arg0, u32 *, 0x10);
    var_r8 = M2C_FIELD(arg0, s16 *, 0x14);
    var_r9 = M2C_FIELD(arg0, u8 *, 0x16);
    var_r10 = M2C_FIELD(arg0, u8 *, 0x17);
    temp_r11 = M2C_FIELD(arg0, u8 *, 0x18);
    if (var_r8 != 0) {
        if ((s32) var_r8 <= 0) {
            temp_r8 = *var_r1;
            var_r1 += 1;
            var_r2 -= 1;
            *var_r5 = temp_r8;
            var_r5 += 1;
            var_r8 = ((temp_r8 + 1) * 2) - 1;
        }
loop_3:
        if (var_r2 != 0) {
            temp_ip = *var_r1;
            var_r1 += 1;
            var_r2 -= 1;
            *var_r5 = temp_ip;
            var_r5 += 1;
            var_r8 -= 1;
            if (var_r8 != 0) {

            } else {
                var_r5 = arg0 + 0x1D;
            }
            if ((s64) (s32) var_r8 <= 0) {
                goto block_8;
            }
            goto loop_3;
        }
    } else {
block_8:
        if (var_r4 > 0) {
loop_9:
            if ((s32) var_r9 < 0x20) {
loop_10:
                if (var_r2 != 0) {
                    temp_ip_2 = *var_r1;
                    var_r1 += 1;
                    var_r2 -= 1;
                    var_r6 |= temp_ip_2 << var_r9;
                    var_r9 += 8;
                    if ((s32) var_r9 >= 0x20) {
                        goto loop_12;
                    }
                    goto loop_10;
                }
            } else {
loop_12:
                temp_ip_3 = var_r6 >> 0x1F;
                temp_lr = *var_r5;
                var_r5 = (((u32) var_r5 >> 1) * 2) + (((temp_lr & 0x3F) + 1) * 2) + temp_ip_3;
                var_r8 = 0;
                var_r6 *= 2;
                var_r9 -= 1;
                if (((temp_lr << temp_ip_3) & 0x80) && (var_r7 = (var_r7 >> temp_r11) | (*var_r5 << (0x20 - temp_r11)), var_r5 = arg0 + 0x1D, var_r10 += temp_r11, (var_r10 == 0x20))) {
                    *var_r3 = var_r7;
                    var_r3 += 4;
                    var_r10 = 0;
                    var_r4 -= 4;
                    temp_gt = (s64) var_r4 > 0;
                    if ((s64) var_r4 > 0) {

                    } else {
                        var_r4 = 0;
                    }
                    if (temp_gt) {
                        goto block_18;
                    }
                } else {
block_18:
                    if ((s32) var_r9 <= 0) {
                        if (var_r4 > 0) {
                            goto loop_9;
                        }
                    } else {
                        goto loop_12;
                    }
                }
            }
        }
    }
    M2C_FIELD(arg0, u32 **, 0) = var_r3;
    M2C_FIELD(arg0, s32 *, 4) = var_r4;
    M2C_FIELD(arg0, u8 **, 8) = var_r5;
    M2C_FIELD(arg0, u32 *, 0xC) = var_r6;
    M2C_FIELD(arg0, u32 *, 0x10) = var_r7;
    M2C_FIELD(arg0, s16 *, 0x14) = var_r8;
    M2C_FIELD(arg0, u8 *, 0x16) = var_r9;
    M2C_FIELD(arg0, u8 *, 0x17) = var_r10;
    M2C_FIELD(arg0, u8 *, 0x18) = temp_r11;
    return var_r4;
}

#pragma peephole reset
#pragma opt_strength_reduction reset
void func_02008bb8(void) {
    M2C_UNK func_02007974(M2C_UNK);
    M2C_UNK DmaStopChannel(M2C_UNK);
    func_02007974(3);
    DmaStopChannel(0);
}

void func_02008bd0(M2C_UNK arg0) {
    M2C_UNK SendArm7Message(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    SendArm7Message(1, arg0, 0, 0, 0);
}

void func_02008bf0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    SendArm7Message(2, arg0, arg1, arg2, arg3);
}

void func_02008c18(M2C_UNK arg0) {
    SendArm7Message(3, arg0, 0, 0, 0);
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
    SendArm7Message(9, arg0, arg1, arg2, 0);
}

void Sound_StartChannels(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    SendArm7Message(0xC, arg0, arg1, arg2, arg3);
}

/* Send the ARM7 "stop channels" command (id 0xD) for the channels selected by
 * channelMask, first bumping the in-flight command counter of each selected
 * channel so Sound_WaitForCommand can tell when the ARM7 has processed it. */
void Sound_StopChannels(M2C_UNK arg0, M2C_UNK arg1, u32 channelMask, s32 arg3) {
    M2C_UNK func_0200976c(s32);
    M2C_UNK SendArm7Message(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 channel;
    u32 mask;

    mask = channelMask;
    channel = 0;
    while (channel < 8 && mask != 0) {
        if (mask & 1) {
            func_0200976c(channel);
        }
        channel += 1;
        mask = mask >> 1;
    }
    SendArm7Message(0xD, arg0, arg1, channelMask, arg3);
}

/* Register `callback`/`callbackArg` as the ARM7 timer callback for hardware
 * `channel` and start that channel's timer (ARM7 sound command 0x12) with the
 * timer parameters; the freshly bumped generation is sent as the last argument. */
void Sound_StartChannelTimer(M2C_UNK channel, M2C_UNK period, M2C_UNK reload, M2C_UNK callback, s32 callbackArg) {
    s32 Sound_RegisterChannelCallback(M2C_UNK, M2C_UNK, s32);
    SendArm7Message(0x12, channel, period, reload, Sound_RegisterChannelCallback(channel, callback, callbackArg));
}

void func_02008d94(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    SendArm7Message(8, arg0, arg1, arg2, 0);
}

void func_02008dbc(M2C_UNK arg0, M2C_UNK arg1) {
    SendArm7Message(0x1A, arg0, arg1, 0, 0);
}

void func_02008ddc(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK SendArm7Message(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    SendArm7Message(0x1B, arg0, arg1, 0, 0);
}

void func_02008dfc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    SendArm7Message(0x14, arg0, arg1, arg2, 0);
}

void func_02008e24(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK SendArm7Message(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    SendArm7Message(0x15, arg0, arg1, 0, 0);
}

/* Send the ARM7 "start channel" command (id 0xE), which keys one hardware
 * channel on with a sample: the channel number and its timer period (rate << 5)
 * in the first word, the sample address in the second, the length in 32-bit
 * words with the volume and its loop flags in the third, and the loop start
 * point, pan, play mode and channel flags in the last. */
void Sound_StartChannel(s32 channel, s32 playMode, s32 sampleAddr, s32 channelFlags, s32 loopStart, s32 lengthWords, s32 volume, s32 loopFlags, s32 timer, s32 pan) {
    M2C_UNK SendArm7Message(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    SendArm7Message(0xE, channel | (timer << 0x10), sampleAddr, lengthWords | ((volume << 0x18) | (loopFlags << 0x16)), loopStart | (((channelFlags << 0x1A) | (playMode << 0x18)) | (pan << 0x10)));
}

void func_02008e90(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK SendArm7Message(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    SendArm7Message(0x1E, arg0, arg1, 0, 0);
}

void func_02008eb0(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK SendArm7Message(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    SendArm7Message(0x1F, arg0, arg1, 0, 0);
}

void Sound_FreeWaveArchiveMemory(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK SendArm7Message(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    SendArm7Message(0x20, arg0, arg1, 0, 0);
}

