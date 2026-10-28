/* 48 functions from 0x02031290 to 0x02032228 (main), found by ds-decomp. */
#include "common.h"

/* Dispatch the next state depending on the current game mode. */
s32 func_02031290(void) {
    s32 func_02027c84();
    s32 func_0202f544();
    s32 func_020313f0(void *);
    s32 func_0203152c();
    M2C_UNK func_02035244();
    s32 state;
    u32 tmp;
    void *ctx;

    state = func_0202f544();
    ctx = func_0202f48c(0x10);
    if (func_02027c84() == 9) {
        tmp = state - 0xA;
        switch (tmp) {                          /* switch 1 */
        default:                                /* switch 1 */
            break;
        case 0:                                 /* switch 1 */
            state = func_0203138c(ctx);
            break;
        case 2:                                 /* switch 1 */
            state = func_020313f0(ctx);
            break;
        case 3:                                 /* switch 1 */
            state = func_02031480();
            break;
        case 4:                                 /* switch 1 */
            state = func_020314ac(ctx);
            break;
        case 5:                                 /* switch 1 */
            state = func_02031518(ctx);
            break;
        case 1:                                 /* switch 1 */
            state = func_0203152c();
            break;
        }
    } else {
        switch (state) {                       /* switch 2; irregular */
        case 15:                               /* switch 2 */
            state = func_02031518(ctx);
            break;
        case 11:                               /* switch 2 */
            state = func_0203152c();
            break;
        case 14:                               /* switch 2 */
            func_02035244();
            func_0203514c();
            /* fallthrough */
        default:                               /* switch 2 */
            state = 0xB;
            M2C_FIELD((ctx + (M2C_FIELD(ctx, u8 *, 0xD13) * 4)), s8 *, 0x444) = 2;
            break;
        }
    }
    return state;
}

s32 func_0203138c(M2C_UNK arg0) {
 s32 func_02021a90(s32);
 void func_0203155c(M2C_UNK,M2C_UNK,M2C_UNK);
 extern volatile s32 data_02138ac0;
 M2C_UNK a,b;
 a=func_0202f48c(1); b=func_0202f48c(4);
 func_0203155c(a,arg0,b); data_02138ac0=4;
 if(func_02021a90(b)==0) return 12;
 func_0202f558(2); return 17;
}

s32 func_020313f0(void *arg0) {
 s32 func_020218bc(); void func_020316c4(void *);
 u64 func_02007004(void); u64 func_02072088(u64,u64);
 u32 v; u64 now,old,elapsed;
 if(func_020218bc()!=0) {func_020316c4(arg0);v=(u32)(M2C_FIELD(arg0,u8 *,0xd0c)<<26)>>30;return v==1?15:13;}
 now=func_02007004(); old=M2C_FIELD(arg0,u64 *,0xcb0); elapsed=now-old;
 if(func_02072088(elapsed<<6,0x1ff6210ULL)<10ULL) return 12;
 else {M2C_FIELD(arg0+M2C_FIELD(arg0,u8 *,0xd13)*4,s8 *,0x444)=1;return 11;}
}

s32 func_02031480(void) {
    M2C_UNK func_0202f48c(M2C_UNK);
    M2C_UNK func_0202f558(M2C_UNK);
    s32 func_0203506c();
    func_0202f48c(8);
    if (func_0203506c() == 0) {
        return 0xE;
    }
    func_0202f558(3);
    return 0x11;
}

s32 func_020314ac(void *arg0) {
    s32 func_0202f5ac(u8);
    M2C_UNK func_0203514c();
    s32 func_020352ac();
    s32 func_020352ec();
    s32 temp_r0;
    void *temp_r4;

    temp_r4 = func_0202f48c(1);
    temp_r0 = func_020352ac();
    if (temp_r0 != 0) {
        if (M2C_FIELD(temp_r4, u8 *, 0x15) == func_0202f5ac(M2C_FIELD(arg0, u8 *, 0xD0D))) {
            M2C_FIELD(temp_r4, s32 *, 0x10) = func_020352ec();
        }
        func_0203514c();
        if (temp_r0 == 0xB) {
            return 0xF;
        }
        M2C_FIELD((arg0 + (M2C_FIELD(arg0, u8 *, 0xD13) * 4)), s8 *, 0x444) = 1;
        return 0xB;
    }
    return 0xE;
}

s32 func_02031518(void *arg0) {
    M2C_UNK func_0202f590(u8);
    func_0202f590(M2C_FIELD(arg0, u8 *, 0xD0D));
    return 0x10;
}

s32 func_0203152c(void) {
 s32 func_020210b8(void);s32 func_02021c04(void);
 u32 v; if(func_020210b8()!=0)return 11;
 v=func_02021c04();return v==0 || v==(u32)-39 ?9:11;
}

void func_0203155c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    extern u8 data_020ea894[];
    void func_02008048(void *, void *, u32);
    s32 func_0202f5ac(u8);
    s32 func_0203161c(void *);
    s32 func_02031670(s32);
    u8 idx;

    func_02008048((M2C_UNK) data_020ea894, arg2, 0x58);
    M2C_FIELD(arg2, s32 *, 4) = M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(arg2, s32 *, 8) = M2C_FIELD(arg0, s32 *, 4);
    idx = M2C_FIELD(arg1, u8 *, 0xD0D);
    if (idx >= 6) {
        return;
    }
    arg1 = (M2C_UNK) ((u8 *) arg1 + (func_0202f5ac(idx) << 8));
    if (M2C_FIELD(arg1, u8 *, 0xC0) != 0) {
        M2C_FIELD(arg2, s32 *, 0xC) = 0;
        M2C_FIELD(arg2, s32 *, 0x10) = func_0203161c((u8 *) arg1 + 0xC0);
        M2C_FIELD(arg2, s32 *, 0x14) = func_02031670(M2C_FIELD(arg1, u8 *, 0xD0));
        M2C_FIELD(arg2, s32 *, 0x18) = func_0203161c((u8 *) arg1 + 0xC4);
        M2C_FIELD(arg2, s32 *, 0x1C) = func_0203161c((u8 *) arg1 + 0xC8);
        M2C_FIELD(arg2, s32 *, 0x20) = func_0203161c((u8 *) arg1 + 0xCC);
        return;
    }
    M2C_FIELD(arg2, s32 *, 0xC) = 1;
    M2C_FIELD(arg2, s32 *, 0x10) = 0;
    M2C_FIELD(arg2, s32 *, 0x14) = 0;
    M2C_FIELD(arg2, s32 *, 0x18) = 0;
    M2C_FIELD(arg2, s32 *, 0x1C) = 0;
    M2C_FIELD(arg2, s32 *, 0x20) = 0;
}

/* func_0203155c (void) is written by compile_and_diff below */

s32 func_0203161c(void *a) { u32 v=0; v|=M2C_FIELD(a,u8 *,0)<<24; v|=M2C_FIELD(a,u8 *,1)<<16; v|=M2C_FIELD(a,u8 *,2)<<8; v|=M2C_FIELD(a,u8 *,3); return ((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00))); }

s32 func_02031670(s32 arg0) {
    u32 var_r3;
    s32 var_r0;
    s32 temp_r1;

    temp_r1 = 0x20 - arg0;
    var_r3 = -1U;
    var_r0 = 0;
    if (temp_r1 > 0) {
        do {
            var_r0 += 1;
            var_r3 *= 2;
        } while (var_r0 < temp_r1);
    }
    return ((var_r3 << 0x18) & 0xFF000000) | (((var_r3 << 8) & 0xFF0000) | ((u8) (var_r3 >> 0x18) | ((var_r3 >> 8) & 0xFF00)));
}

void func_020316c4(void *arg0) {
    void func_020218f4(M2C_UNK *, M2C_UNK *);
    s32 func_0202f5ac(u8);
    s32 func_0203161c(void *);
    s32 sp4;
    s32 sp0;
    u8 *p;
    u8 c0;
    u32 sum;

    p = (u8 *) arg0;
    if (M2C_FIELD(p, u8 *, 0xD0D) >= 6) {
        return;
    }
    p += func_0202f5ac(M2C_FIELD(p, u8 *, 0xD0D)) << 8;
    c0 = M2C_FIELD(p, u8 *, 0xC0);
    sum = M2C_FIELD(p, u8 *, 0xC8) + M2C_FIELD(p, u8 *, 0xC9) + M2C_FIELD(p, u8 *, 0xCA) + M2C_FIELD(p, u8 *, 0xCB);
    if (c0 != 0) {
        return;
    }
    if (sum == 0) {
        return;
    }
    sp4 = func_0203161c(p + 0xC8);
    sp0 = func_0203161c(p + 0xCC);
    func_020218f4(&sp4, &sp0);
}

s32 func_0203174c(M2C_UNK a) { M2C_UNK func_0203182c(M2C_UNK,M2C_UNK *); s32 func_0206527c(M2C_UNK,M2C_UNK *,M2C_UNK); extern M2C_UNK data_020fb2a4; M2C_UNK buf[6]; func_0203182c(a,buf); return func_0206527c((M2C_UNK)buf,&data_020fb2a4,8)==0; }

void func_02031784(M2C_UNK a,M2C_UNK b) { M2C_UNK func_0203182c(M2C_UNK,M2C_UNK *); void func_02031930(M2C_UNK *,M2C_UNK); M2C_UNK buf[6]; func_0203182c(a,buf); func_02031930(buf,b); }

s32 func_020317f8(M2C_UNK arg0) {
    s32 func_0206527c(M2C_UNK, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fb2b0;
    if (func_0206527c(arg0, &data_020fb2b0, 8) == 0) {
        return 1;
    }
    return 0;
}

void func_0203181c(s32 arg0, u8 *dst) {
    void func_0203197c(u8 *, u8 *);
    func_0203197c((u8 *)arg0 + 0xC, dst);
}

M2C_UNK func_0203182c(M2C_UNK arg0, M2C_UNK *arg1) {
    extern u8 data_020ea8ef[];
    extern M2C_UNK data_020fb23c[];
    M2C_UNK func_02031b98(M2C_UNK, u8 *, s32, s32);
    u8 buf[0x18];
    u8 *p;
    signed char *key;
    u8 *src;
    u8 *dst;
    s32 n;
    s32 i;
    s32 pos;
    s32 next;
    s32 saved;
    s32 save;
    u8 val;

    p = (u8 *)arg1;

    src = (u8 *)data_020ea8ef;
    dst = buf;
    for (n = 0xC; n > 0; n--) {
        *dst++ = *src++;
        *dst++ = *src++;
    }

    func_02031b98(arg0, p, 0x20, 0x18);

    key = (signed char *)data_020fb23c[2];
    for (i = 0; i < 0x18; i++) {
        p[i] = (u8)(p[i] ^ key[i]);
    }

    for (i = 0; i < 0x18; i++) {
        val = buf[i];
        if (val == 0xFF) {
            continue;
        }
        saved = (s32)p[i];
        pos = i;
        do {
            next = buf[pos];
            save = (s32)p[next];
            p[next] = (u8)saved;
            buf[pos] = 0xFF;
            saved = save;
            pos = next;
        } while (buf[pos] != 0xFF);
    }

    key = (signed char *)data_020fb23c[0];
    for (i = 0; i < 0x18; i++) {
        p[i] = (u8)(p[i] ^ key[i]);
    }
}

void func_0203197c(u8 *src, u8 *dst) {
    u8 tmp[0x10];
    extern M2C_UNK data_020fb23c[];
    extern u8 data_020ea908[];
    extern u8 data_020ea918[];
    void func_02008048(void *, void *, u32);

    s32 i;
    for (i = 0; i < 0xD; i++) {
        dst[i] = (u8)(src[i] ^ src[(i % 7) + 0xD]);
    }
    for (i = 0; i < 0x7; i++) {
        dst[i + 0x3] = (u8)(dst[i + 0x3] ^ src[i + 0xD]);
    }
    for (i = 0; i < 0xD; i++) {
        dst[i] = (u8)(dst[i] ^ ((signed char *)data_020fb23c[1])[i]);
    }
    func_02008048(dst, tmp, 0xD);
    for (i = 0; i < 0xD; i++) {
        dst[data_020ea908[i]] = tmp[i];
    }
    for (i = 0; i < 0xD; i++) {
        dst[i] = (u8)(dst[i] ^ ((signed char *)data_020fb23c[3])[i]);
    }
    for (i = 0; i < 0xD; i++) {
        u8 b = dst[i];
        u8 hi = (u8)((b >> 4) & 0x0F);
        u8 lo = (u8)(b & 0x0F);
        dst[i] = (u8)((data_020ea918[hi] << 4) | data_020ea918[lo]);
    }
    for (i = 0; i < 0x3; i++) {
        dst[i] = (u8)(dst[i] ^ dst[i + 0x6]);
        dst[i + 0x3] = (u8)(dst[i + 0x3] ^ dst[i + 0x9]);
        dst[i + 0x6] = (u8)(dst[i + 0x6] ^ dst[i + 0x3]);
        dst[i + 0x9] = (u8)(dst[i + 0x9] ^ dst[i]);
        dst[0xC] = (u8)(dst[0xC] ^ dst[i]);
    }
}

s32 func_02031b28(u32 arg0) {
    if (arg0 >= 0x41U && arg0 <= 0x5AU) {
        return (s32) (arg0 - 0x41U);
    }
    if (arg0 >= 0x61U && arg0 <= 0x7AU) {
        s32 temp_r0;

        temp_r0 = (s32) (arg0 - 0x61U);
        return temp_r0 + 0x1A;
    }
    if (arg0 >= 0x30U && arg0 <= 0x39U) {
        s32 temp_r0;

        temp_r0 = (s32) (arg0 - 0x30U);
        return temp_r0 + 0x34;
    }
    if (arg0 == 0x2BU) {
        return 0x3E;
    }
    if (arg0 == 0x2FU) {
        return 0x3F;
    }
    if (arg0 == 0x3DU) {
        return 0;
    }
    return -1;
}

#pragma opt_strength_reduction off
s32 func_02031b98(s32 arg,u8 *dst,s32 n,s32 capacity){
u8 *src=(u8 *)arg;u32 size=((u32)(n*3))>>2;s32 rem; s32 full; s32 pos; s32 block;s32 j;s32 val;u32 word;u32 tail;u8 *in;u8 *out;
if((u32)capacity>=size){rem=n&3;full=n-rem;}else return -1;
pos=0;
if(full>0){block=0;do{
val=0;j=0;in=src+pos;
do{val|=func_02031b28(*in++)<<((3-j)*6);j++;}while(j<4);
j=0;word=val;out=dst+block*3;
do{*out++=((u8 *)&word)[2-j];j++;}while(j<3);
pos+=4;block++;
}while(pos<full);}
if(rem!=0){
val=0;j=0;tail=0;
if(rem>0){s32 accum=0;in=src+full;do{val|=func_02031b28(*in++)<<((3-j)*6);j++;accum|=val;}while(j<rem);tail=accum;}
j=0;if(rem>0){out=dst+(full*3)/4;do{*out++=((u8 *)&tail)[2-j];j++;}while(j<rem);}
}
return size;
}
#pragma opt_strength_reduction on
s32 func_02031d00(M2C_UNK arg0) {
    M2C_UNK func_02000b9c(s32);
    s32 func_02046884(M2C_UNK);
    M2C_UNK func_02047098(M2C_UNK);
    s32 func_02047320();
    s32 temp_r4;
    s32 var_r0;
    s32 var_r5;

    var_r5 = 0;
    func_02000b9c(0x02000C34);
    temp_r4 = func_02046884(arg0);
    if (func_02047320() != 0) {
        func_02047098(arg0);
        var_r5 = 1;
    }
    if (temp_r4 < 0) {
        if (var_r5 != 0) {
            var_r0 = 2;
        } else {
            var_r0 = 3;
        }
        return var_r0;
    }
    if (var_r5 != 0) {
        return 1;
    }
    return 0;
}

s32 func_02031d64(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    if (((u32) arg1 & ~(u32) arg3) != 0U) {
        return 0;
    }
    *(u32 *) arg0 = (*(u32 *) arg0 & ~((u32) arg3 << (u32) arg2)) | ((u32) arg1 << (u32) arg2);
    return 1;
}

u64 func_02031d90(void *arg0) {
    u32 hi = M2C_FIELD(arg0, u32 *, 0) & 0x7FF;
    u32 lo = M2C_FIELD(arg0, u32 *, 4);
    return ((u64) hi << 32) | lo;
}

s32 func_02031db0(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 8);
}

u64 func_02031db8(void *arg0) {
    u32 hi;
    u32 lo;

    hi = M2C_FIELD(arg0, u32 *, 8);
    lo = M2C_FIELD(arg0, u32 *, 4);
    return ((u64) hi << 32) | lo;
}

s32 func_02031dcc(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4);
}

void func_02031dd4(void *arg0, s32 arg1, M2C_UNK arg2) {
    func_02031d64(arg0, arg2, 0, 0x7FF);
    M2C_FIELD(arg0, s32 *, 4) = arg1;
}

void func_02031dfc(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
}

void func_02031e04(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg2;
}

void func_02031e0c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
}

s32 func_02031e14(u32 *arg0) {
    return 0x1FFFFF & ((u32) *arg0 >> 0xB);
}

s32 func_02031e28(void) {
    s32 func_02031e14();
    return func_02031e14() & 3;
}

s32 func_02031e38(M2C_UNK arg0) {
    s32 var_r0;

    if (func_02031e28() == 3) {
        if ((func_02031e14(arg0) & 4) == 4) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    }
    return 0;
}

void func_02031e70(void) {
    M2C_UNK func_02031e28();
    func_02031e28();
}

#pragma optimization_level 2
void func_02031e7c(M2C_UNK a,M2C_UNK b) { M2C_UNK func_02031d64(M2C_UNK,M2C_UNK,M2C_UNK,s32); func_02031d64(a,b,11,0x1fffff); }
void func_02031e94(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_02031e14(u32 *);
    void func_02031e7c(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02031e14((u32 *) arg0);
    temp_r0 = temp_r0 & ~3;
    func_02031e7c(arg0, temp_r0 | arg1);
}

void func_02031eb8(M2C_UNK arg0) {
    s32 func_02031e28();
    s32 func_02031e14(u32 *);
    void func_02031e7c(M2C_UNK, M2C_UNK);
    s32 res;

    if (func_02031e28() != 3) {
        return;
    }
    res = func_02031e14((u32 *) arg0) | 4;
    func_02031e7c(arg0, res);
}

void func_02031ee4(M2C_UNK arg0) {
    if (func_02031e28() != 3) {
        return;
    }
    func_02031e7c(arg0, func_02031e14(arg0) & ~4);
}

u64 func_02031f14(s32 arg0, s32 arg1) {
    void func_02076698(u8 *, s32);
    s32 func_02076810(u8 *, s32 *, s32);
    u8 buf[0x100];
    s32 in[2];

    in[0] = arg0;
    in[1] = arg1;
    func_02076698(buf, 7);
    return (u32) arg0 | ((u64) (func_02076810(buf, in, 8) & 0x7f) << 32);
}

void func_02031f58(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02031f74(M2C_UNK, M2C_UNK, s32);
    func_02031f74(arg1, arg2, M2C_FIELD(arg0, s32 *, 0x24));
}

s32 func_02031f74(s32 arg0, s32 arg1, s32 arg2) {
    void func_02076698(u8 *, s32);
    s32 func_02076810(u8 *, s32 *, s32);
    u8 buf[0x100];
    s32 in[2];
    s32 c1;
    s32 c2;
    s32 h;
    s32 masked;

    c1 = arg1 & 0;
    c2 = arg0 & 0x80000000;
    if (c1 == 0 && c2 == 0) {
        in[0] = arg0;
        in[1] = arg2;
        func_02076698(buf, 7);
        h = func_02076810(buf, in, 8);
        masked = h & 0x7f;
        if ((masked >> 31) == 0 && masked == arg1) {
            return 1;
        }
        return 0;
    }
    return 0;
}

s32 func_02031fe4(u32 arg0, u32 arg1, s32 arg2) {
    M2C_UNK func_02031f74(M2C_UNK, M2C_UNK, s32);
    if (func_02031f74(arg0, arg1, arg2) != 0) {
        return (s32) arg0;
    }
    return 0;
}

void func_02032004(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_0200567c(M2C_UNK, M2C_UNK, M2C_UNK *, ...);
    extern M2C_UNK data_020fb2bc;
    func_0200567c(arg0, 0xD, &data_020fb2bc, arg1, arg2);
}

u64 func_02032024(void *arg0) {
    signed char *p;
    s32 i;
    u64 result;
    u64 mult;
    s32 c;

    result = 0;
    mult = 1;
    p = (signed char *)arg0 + 0xB;
    for (i = 0; i < 0xC; i++) {
        c = *p--;
        if (c < 0x30 || c > 0x39) {
            return 0;
        }
        result += (u64)(c - 0x30) * mult;
        mult *= 10;
    }
    return result;
}

void func_020320ac(s32 arg0, s32 arg1, s32 arg2, char *arg3) {
    extern u8 data_020fb2c4[];
    u32 lo = (u32)arg0;
    u32 hi = (u32)arg1;
    s32 count = (arg2 + 4) / 5;
    s32 i;

    for (i = 0; i < count; i++) {
        arg3[count - 1 - i] = (char)data_020fb2c4[lo & 0x1F];
        lo = (lo >> 5) | (hi << 27);
        hi >>= 5;
    }
    arg3[count] = 0;
}

void func_0203211c(void *arg0, u32 arg1, void *arg2) {
    u64 func_02031d90(void *);
    s32 func_02031db0(void *);
    void func_020320ac(s32, s32, s32, char *);
    M2C_UNK func_0200567c(M2C_UNK, M2C_UNK, M2C_UNK *, ...);
    extern M2C_UNK data_020fb2e8;
    M2C_UNK sp29;
    M2C_UNK sp14;
    u64 v;

    v = func_02031d90(arg0);
    func_020320ac((s32)v, (s32)(v >> 32), 0x2B, (char *)&sp29);
    func_020320ac(func_02031db0(arg0), 0, 0x20, (char *)&sp14);
    func_0200567c(arg2, 0x15, &data_020fb2e8, &sp29,
                   (s32)((arg1 >> 24) & 0xFF),
                   (s32)((arg1 >> 16) & 0xFF),
                   (s32)((arg1 >> 8) & 0xFF),
                   (s32)(arg1 & 0xFF),
                   &sp14);
}

void func_020321ac(void *arg0, s32 arg1) {
    void func_02007f8c(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_02032228(void *);
    void func_02031e94(M2C_UNK, M2C_UNK);
    void func_02076794(M2C_UNK *, s32);
    s32 func_02076860(M2C_UNK *, void *, M2C_UNK);
    u32 table[256];

    func_02007f8c(arg0, 0, 0x40);
    M2C_FIELD(arg0, s32 *, 0) = 0x40;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = arg1;
    func_02032228((u8 *)arg0 + 4);
    func_02031e94((u8 *)arg0 + 0x10, 0);
    func_02076794(table, 0xEDB88320);
    M2C_FIELD(arg0, s32 *, 0x3C) = func_02076860(table, arg0, 0x3C);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32)(M2C_FIELD(arg0, s32 *, 0x20) | 1);
}

