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
    u8 *var_r2x;

    var_r1 = arg1;
    temp_r2 = arg0 + 4;
    temp_r7 = temp_r2 + 1;
    temp_r4 = M2C_FIELD(arg0, u8 *, 0) & 0xF;
    var_r3 = 0;
    var_lr = 0;
    sp0 = (temp_r4 & 7) + 4;
    var_ip = (u32) M2C_FIELD(arg0, u8 *, 0) >> 8;
    var_r0 = temp_r2 + ((M2C_FIELD(arg0, u8 *, 4) + 1) * 2);
    var_r2x = temp_r7;
loop_1:
    if ((s32) var_ip > 0) {
        var_r8 = 0x20;
        var_r5 = *var_r0;
        var_r0 += 4;
loop_3:
        var_r8 -= 1;
        if ((s64) var_r8 >= 0) {
            temp_r9 = 1 & (var_r5 >> 0x1F);
            temp_r6 = *var_r2x << temp_r9;
            var_r2x = (((u32) var_r2x >> 1) * 2) + (((*var_r2x & 0x3F) + 1) * 2) + temp_r9;
            if (temp_r6 & 0x80) {
                var_r3 = (var_r3 >> temp_r4) | (*var_r2x << (0x20 - temp_r4));
                var_r2x = temp_r7;
                var_lr += 1;
                if (var_lr != sp0) {

                } else {
                    *var_r1 = var_r3;
                    var_r1 += 4;
                }
                if (var_lr != sp0) {

                } else {
                    var_ip -= 4;
                }
                if (var_lr != sp0) {

                } else {
                    var_lr = 0;
                }
            }
            if ((s32) var_ip <= 0) {

            } else {
                var_r5 *= 2;
            }
            if ((s32) var_ip <= 0) {

            } else {
                goto loop_3;
            }
        }
        goto loop_1;
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

#pragma push
#pragma opt_propagation off
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
#pragma pop
s32 func_0200864c(void *arg0,u8 *src,s32 size){
 u8 *dst=M2C_FIELD(arg0,u8**,0);s32 remaining=M2C_FIELD(arg0,s32*,4);u32 hdr=M2C_FIELD(arg0,u8*,11);s32 cnt=M2C_FIELD(arg0,u16*,12);
 for(;;){
 if(!(hdr&128)){while(cnt>0){u8 val;cnt--;val=*src++;remaining--;*dst++=val;if(--size==0)goto done;}}
 else if(cnt>0){u8 val=*src++;do{remaining--;*dst++=val;}while(--cnt>0);if(--size==0)goto done;}
 hdr=*src++;cnt=hdr&127;if(hdr&128)cnt+=2;cnt++;if(--size==0)break;
 }
done:M2C_FIELD(arg0,u8**,0)=dst;M2C_FIELD(arg0,s32*,4)=remaining;M2C_FIELD(arg0,u8*,11)=hdr;M2C_FIELD(arg0,u16*,12)=cnt;return remaining;
}

s32 func_02008700(void *arg0,u8 *src,s32 size){
 struct S { u16 *out; s32 remain; u16 acc; u8 pos; u8 hdr; u16 cnt; };
 volatile struct S *s=arg0;
 u32 out;s32 remaining;u32 hdr;s32 cnt;u32 acc;s32 pos;u32 val;
 out=(u32)s->out;remaining=s->remain;hdr=s->hdr;cnt=s->cnt;acc=s->acc;pos=s->pos;
loop:
 if(remaining<=0)goto done;
 if(!(hdr&128)){
lit:
  if(cnt<=0)goto next;
  cnt--;val=*src++;acc|=val<<pos;pos+=8;if(pos==16){*(u16*)out=acc;out+=2;acc=0;pos=0;remaining-=2;}if(--size==0)goto done;
  goto lit;
 }
 else if(cnt>0){val=*src++;do{acc|=val<<pos;pos+=8;if(pos==16){*(u16*)out=acc;out+=2;acc=0;pos=0;remaining-=2;}}while(--cnt>0);if(--size==0)goto done;}
next:
 hdr=*src++;cnt=hdr&127;if(hdr&128)cnt+=2;cnt++;if(--size!=0)goto loop;
done:s->out=(u16*)out;s->remain=remaining;s->hdr=hdr;s->cnt=cnt;s->acc=acc;s->pos=pos;return remaining;
}

s32 func_020087ec(void *arg0, u8 *src, s32 size) {
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

s32 func_020088ec(void *arg0, u8 *arg1, s32 arg2) {
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

s32 func_02008a60(void *p,u8 *src,s32 len){
u32 *dst=M2C_FIELD(p,u32**,0);s32 left=M2C_FIELD(p,s32*,4);u8 *tree=M2C_FIELD(p,u8**,8);
u32 bits=M2C_FIELD(p,u32*,12),out=M2C_FIELD(p,u32*,16);
s32 count=M2C_FIELD(p,s16*,20),nb=M2C_FIELD(p,u8*,22),no=M2C_FIELD(p,u8*,23),width=M2C_FIELD(p,u8*,24);
if(count){
if(count<0){count=*src++;len--;*tree++=count;count=((count+1)<<1)-1;}
do{if(!len)goto end;*tree++=*src++;len--;if(--count==0)tree=(u8*)p+29;}while(count>0);
}
while(left>0){
while(nb<32){if(!len)goto end;bits|=(*(u32*)src)<<nb;src++;len--;nb+=8;}
do{
u32 bit=bits>>31;u32 node=*tree;
tree=(u8*)(((u32)tree>>1)<<1)+((node&63)+1)*2+bit;
count=0;bits<<=1;nb--;
if((node<<bit)&128){
out=(out>>width)|(*tree<<(32-width));tree=(u8*)p+29;no+=width;
if(no==32){*dst++=out;no=0;left-=4;if(left<=0){left=0;goto end;}}
}
}while(nb>0);
}
end:
M2C_FIELD(p,u32**,0)=dst;M2C_FIELD(p,s32*,4)=left;M2C_FIELD(p,u8**,8)=tree;
M2C_FIELD(p,u32*,12)=bits;M2C_FIELD(p,u32*,16)=out;
M2C_FIELD(p,s16*,20)=count;M2C_FIELD(p,u8*,22)=nb;M2C_FIELD(p,u8*,23)=no;M2C_FIELD(p,u8*,24)=width;
return left;
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

