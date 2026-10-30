/* 22 functions from 0x020E4490 to 0x020E5080 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pixels[32]; } Unk020ETile;
typedef struct { u8 count; u8 pad[3]; s32 ptr; } Unk02168Fec;
u16 *func_020e4c10(u16 *,u16 *,u16 *,u32);
extern s32 data_02168ff4;

void func_020e4490(void) {
    M2C_UNK func_020e4378();
    M2C_UNK func_02082058();
    M2C_UNK func_02081724();
    M2C_UNK func_02081a48();
    M2C_UNK func_02082d08();
    M2C_UNK func_02082b78();
    M2C_UNK func_02082cb4();
    M2C_UNK func_02082078();
    M2C_UNK func_020e31f0();
    M2C_UNK func_01ff85ec();
    M2C_UNK func_0208232c();
    M2C_UNK func_0209daec();
    M2C_UNK func_020e3448();
    M2C_UNK func_02080bd4();
    M2C_UNK func_020883bc();
    M2C_UNK func_02086574();
    M2C_UNK func_0208fba0();
    M2C_UNK func_0209cc04();
    M2C_UNK func_020e4458();
    M2C_UNK func_0200ee70();
    M2C_UNK func_0207c240();
    M2C_UNK func_02075efc();
    void func_020e476c(void);
    M2C_UNK func_020e349c();
    extern s32 data_027e15bc;
    extern s32 data_027e15c0;
    extern u8 data_027e15b4;
    extern u8 data_027e15b8;
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    s32 var_r0;
    s32 temp_r7;
    s32 var_r8;

    data_027e15bc = 0;
    data_027e15c0 = 0;
    data_027e15b4 = 0;
    data_027e15b8 = 0;
    func_020e4378();
    func_02082058();
    func_02081724();
    func_02081a48();
    func_02082d08();
    func_02082b78();
    func_02082cb4();
    func_02082078();
    func_020e31f0();
    temp_r7 = gCur3DSpriteEngine;
    var_r8 = 0;
    do {
        if (var_r8 == 0) {
            var_r0 = data_027e00c8;
        } else {
            var_r0 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r0;
        func_01ff85ec();
        func_0208232c();
        var_r8 += 1;
    } while (var_r8 < 2);
    gCur3DSpriteEngine = temp_r7;
    func_0209daec();
    func_020e3448();
    func_02080bd4();
    func_020883bc();
    func_02086574();
    func_0208fba0();
    func_0209cc04();
    func_020e4458();
    func_0200ee70();
    func_0207c240();
    func_02075efc();
    func_020e476c();
    func_020e349c();
}

void func_020e4570(void) {
    M2C_UNK func_020024cc();
    M2C_UNK func_02007598();
    func_02007598();
    func_020024cc();
    *(s32 *)0x04001000 |= 0x10000;
}

void func_020e4594(void) {
extern u8 data_027e15b4;
extern s32 data_027e15bc;
extern void (*data_02168fe8)(void);
void func_0208f4d8(void);
void func_0208184c(void);
void func_02081ae4(void);
void func_02090390(void);
void func_02081ee4(void);
void func_02091bf4(void);
void func_020b2400(void);
void func_020b25b8(void);
void func_0209db48(void);
void func_0208f4f0(void);
void func_01ffa13c(int);
void func_01ffa5b8(void);
void func_02004e60(int,int);
if (!data_027e15b4) return;
data_02168fe8=0;
func_0208f4d8();
data_027e15bc++;
func_0208184c(); func_02081ae4(); func_02090390(); func_02081ee4();
func_01ffa13c(3);func_01ffa5b8();
func_01ffa13c(4);func_01ffa5b8();
func_01ffa13c(5);func_01ffa5b8();
func_01ffa13c(6);func_01ffa5b8();
func_01ffa13c(7);func_01ffa5b8();
func_01ffa13c(8);func_01ffa5b8();
func_02091bf4();func_020b2400();func_020b25b8();
func_01ffa13c(9);func_01ffa5b8();
func_01ffa13c(10);func_01ffa5b8();
func_0209db48();
if(data_02168fe8) data_02168fe8();
data_027e15b4=0;
func_0208f4f0();
func_02004e60(1,1);
}

void func_020e476c(void) {
    M2C_UNK func_01ff9b38();
    M2C_UNK func_0207b800();
    M2C_UNK func_0208337c();
    M2C_UNK func_020834c4();
    M2C_UNK func_020945f8();
    M2C_UNK func_020960b4();
    M2C_UNK func_0209f87c();
    M2C_UNK func_020abf94();
    M2C_UNK func_020aca8c(M2C_UNK);
    M2C_UNK func_020b1b3c();
    M2C_UNK func_020be5d0();
    M2C_UNK func_020c8eec();
    M2C_UNK func_020d3cec();
    M2C_UNK func_ov000_02169368();
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r8;
    s32 var_r1;
    s32 var_r9;

    func_020be5d0();
    func_020945f8();
    func_020b1b3c();
    func_020834c4();
    func_0208337c();
    func_020c8eec();
    func_020abf94();
    temp_r8 = gCur3DSpriteEngine;
    var_r9 = 0;
    do {
        if (var_r9 == 0) {
            var_r1 = data_027e00c8;
        } else {
            var_r1 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r1;
        func_020aca8c(1);
        func_01ff9b38();
        var_r9 += 1;
    } while (var_r9 < 2);
    gCur3DSpriteEngine = temp_r8;
    func_0207b800();
    func_020d3cec();
    func_0209f87c();
    func_ov000_02169368();
    func_020960b4();
}

void func_020e47f8(void) {
    M2C_UNK func_020e4818(s32);
    s32 var_r4;

    var_r4 = 0;
    do {
        func_020e4818(var_r4);
        var_r4 += 1;
    } while (var_r4 < 3);
}

s32 func_020e4818(s32 a){extern u8 data_0215dba4[];u32 *p=(u32 *)(data_0215dba4+a*0x118);p[0]&=~15;p[0]&=~240;{u32 t=p[1];t&=0xffff0000U;p[1]=(u16)t;}p[0]&=~0xff00;p[0]&=~0xff0000;p[0]&=~0xff000000;return p[0];}

void func_020e4870(s32 arg0) {
    extern M2C_UNK data_0215d9b8;
    extern M2C_UNK data_0215d8a0;
    extern void **gCurrentMap;
    extern u8 data_0215dba4[];
    extern u8 data_0215dbac[];
    extern M2C_UNK data_0215d8a8;
    extern u8 data_0215dcac[];
    extern M2C_UNK data_0215d9a8;
    extern u8 data_0215dcb4[];
    extern M2C_UNK data_0215d9b0;

    s32 i;
    u16 t;
    u32 d0;
    u32 d1;
    void **gmap;
    void *gm;
    u32 gm0;
    u16 f1;
    u16 f2;
    u32 b;
    u32 off;
    u32 *dst;
    u32 *src;
    u8 *d2;
    u8 *s2;

    t = ((u16 *)&data_0215d9b8)[3];
    d0 = ((u32 *)&data_0215d8a0)[0];

    t = (u16)((t & ~0x70) | (((u16)arg0 << 4) & 0x70));
    ((u16 *)&data_0215d9b8)[3] = t;

    d0 = (d0 & ~0x0F) | ((u32)arg0 & 0x0F);
    ((u32 *)&data_0215d8a0)[0] = d0;

    gmap = gCurrentMap;
    gm = *gmap;
    gm0 = *(u32 *)gm;

    d1 = ((u32 *)&data_0215d8a0)[1];
    d1 = d1 & ~0x0000FFFFu;
    f1 = (u16)((*(u16 *)((u8 *)gm0 + 0x5142)) - 0xA1);
    d1 = d1 | f1;
    ((u32 *)&data_0215d8a0)[1] = d1;

    f2 = *(u16 *)((u8 *)gm0 + 0x52A2);
    d1 = ((u32 *)&data_0215d8a0)[1];
    ((u32 *)&data_0215d8a0)[1] = (f2 << 16) | (d1 & 0x0000FFFFu);

    b = (d0 >> 8) & 0xFFu;
    if (b < 0xFFu) {
        b++;
    }
    d0 = (((u32 *)&data_0215d8a0)[0] & ~0x0000FF00u) | (b << 8);
    ((u32 *)&data_0215d8a0)[0] = d0;

    off = (u32)(arg0 * 0x118);
    *(u32 *)(data_0215dba4 + off) = d0;
    *(u32 *)(data_0215dba4 + off + 4) = ((u32 *)&data_0215d8a0)[1];

    dst = (u32 *)(data_0215dbac + off);
    src = (u32 *)&data_0215d8a8;
    i = 16;
    do {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst += 4;
        src += 4;
    } while (--i);

    d2 = data_0215dcac + off;
    s2 = (u8 *)&data_0215d9a8;
    i = 4;
    do {
        d2[0] = s2[0];
        d2[1] = s2[1];
        s2 += 2;
        d2 += 2;
    } while (--i);

    d2 = data_0215dcb4 + off;
    s2 = (u8 *)&data_0215d9b0;
    i = 4;
    do {
        d2[0] = s2[0];
        d2[1] = s2[1];
        s2 += 2;
        d2 += 2;
    } while (--i);
}

void func_020e49ec(void) {
    M2C_UNK func_02086ae4(s32, M2C_UNK);
    M2C_UNK func_0209c7fc();
    s32 var_r5;

    func_0209c7fc();
    var_r5 = 0x60;
    do {
        func_02086ae4(var_r5, 0);
        var_r5 += 1;
    } while (var_r5 < 0xA0);
}

void func_020e4a18(s32 arg0) {
    s32 func_020be120();
    s32 func_020be324(M2C_UNK, s32);
    extern M2C_UNK data_0215d8a0;
    extern M2C_UNK data_0215d8a8;
    extern M2C_UNK data_0215d9a8;
    extern M2C_UNK data_0215d9b0;
    extern M2C_UNK data_0215d9b8;
    M2C_UNK *var_r3;
    M2C_UNK *var_r3_2;
    M2C_UNK *var_r5;
    s32 temp_ip;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r1;
    s32 temp_r2;
    s32 temp_r3_2;
    s32 var_lr;
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r5_2;
    u16 temp_r0_5;
    u8 temp_r0_3;
    u8 temp_r0_4;
    u8 temp_r1_2;
    u8 temp_r1_3;
    void *temp_r1_4;
    void *temp_r3;
    void *temp_r3_3;
    void *var_ip;
    void *var_lr_2;
    void *var_r6;

    temp_r0 = func_020be120();
    if (func_020be324(4, temp_r0) == 0) {
        return;
    }
    temp_ip = arg0 * 0x118;
    temp_r3 = temp_r0 + temp_ip;
    var_r5 = &data_0215d8a8;
    M2C_FIELD(&data_0215d8a0, s32 *, 0) = (s32) M2C_FIELD(temp_r3, s32 *, 0x284);
    M2C_FIELD(&data_0215d8a0, s32 *, 4) = (s32) M2C_FIELD(temp_r3, s32 *, 0x288);
    var_r6 = temp_r3 + 0x28C;
    var_lr = 0x10;
    do {
        temp_r0_2 = M2C_FIELD(var_r6, s32 *, 0);
        temp_r1 = M2C_FIELD(var_r6, s32 *, 4);
        temp_r2 = M2C_FIELD(var_r6, s32 *, 8);
        temp_r3_2 = M2C_FIELD(var_r6, s32 *, 0xC);
        var_r6 += 0x10;
        M2C_FIELD(var_r5, s32 *, 0) = temp_r0_2;
        M2C_FIELD(var_r5, s32 *, 4) = temp_r1;
        M2C_FIELD(var_r5, s32 *, 8) = temp_r2;
        M2C_FIELD(var_r5, s32 *, 0xC) = temp_r3_2;
        var_r5 += 0x10;
        var_lr -= 1;
    } while (var_lr != 0);
    var_r3 = &data_0215d9a8;
    var_lr_2 = temp_r0 + temp_ip + 0x38C;
    var_r2 = 4;
    do {
        temp_r1_2 = M2C_FIELD(var_lr_2, u8 *, 0);
        temp_r0_3 = M2C_FIELD(var_lr_2, u8 *, 1);
        var_lr_2 += 2;
        var_r2 -= 1;
        M2C_FIELD(var_r3, u8 *, 0) = temp_r1_2;
        M2C_FIELD(var_r3, u8 *, 1) = temp_r0_3;
        var_r3 += 2;
    } while (var_r2 != 0);
    var_r3_2 = &data_0215d9b0;
    var_ip = temp_r0 + temp_ip + 0x394;
    var_r2_2 = 4;
    do {
        temp_r1_3 = M2C_FIELD(var_ip, u8 *, 0);
        temp_r0_4 = M2C_FIELD(var_ip, u8 *, 1);
        var_ip += 2;
        var_r2_2 -= 1;
        M2C_FIELD(var_r3_2, u8 *, 0) = temp_r1_3;
        M2C_FIELD(var_r3_2, u8 *, 1) = temp_r0_4;
        var_r3_2 += 2;
    } while (var_r2_2 != 0);
    var_r5_2 = 0;
    do {
        temp_r3_3 = temp_r0 + (var_r5_2 * 8);
        temp_r0_5 = M2C_FIELD(temp_r3_3, u16 *, 0xCC);
        temp_r1_4 = &data_0215d9b8 + (var_r5_2 * 8);
        var_r5_2 += 1;
        M2C_FIELD(temp_r1_4, u16 *, 0x34) = temp_r0_5;
        M2C_FIELD(temp_r1_4, u16 *, 0x36) = (u16) M2C_FIELD(temp_r3_3, u16 *, 0xCE);
        M2C_FIELD(temp_r1_4, s32 *, 0x38) = (s32) M2C_FIELD(temp_r3_3, s32 *, 0xD0);
    } while (var_r5_2 < 3);
}

void func_020e4b24(void) {

}

u8 func_020e4b28(s32 a){extern u8 data_0215dba4[];return ((u32)(M2C_FIELD(data_0215dba4,u32 *,a*0x118)<<16)>>24)!=0;}

s32 func_020e4b54(void) {
    extern u16 data_02168f14;
    extern void **gCurrentMap;
    if (!(((u32) (data_02168f14 << 0x1D) >> 0x1D) & 0xFF) && (M2C_FIELD(*gCurrentMap, u16 *, 0x5142) == 0xBA)) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
s32 func_020e4b9c(u16 key,...){extern u16 data_0212da1c;extern u16 data_020f4eb4[];volatile u8 a=0;volatile u8 b=0;u16 *p=func_020e4c10(data_020f4eb4,data_020f4eb4+data_0212da1c,&key,*(u32 *)&b);if(*p!=key)return 0;return p-data_020f4eb4;}
#pragma pop
u16 *func_020e4c10(u16 *first,u16 *last,u16 *key,u32 unused){
s32 n=last-first;
while(n>0){
s32 half=n/2;
u16 *p=first+half;
if(*p<*key){
half++;
first=p+1;
n-=half;
}else n=half;
}
return first;
}
#pragma opt_propagation reset
void func_020e4c64(void) {
    s32 func_02081070(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212da20;
    extern M2C_UNK data_02168fec;
    u8 temp_r2;

    temp_r2 = M2C_FIELD(&data_02168fec, u8 *, 0);
    M2C_FIELD(&data_02168fec, u8 *, 0) = (u8) (temp_r2 + 1);
    if (temp_r2 != 0) {
        return;
    }
    M2C_FIELD(&data_02168fec, s32 *, 4) = func_02081070(&data_0212da20, 1);
}

void func_020e4ca0(void) {M2C_UNK func_020e35cc(s32);extern M2C_UNK data_02168fec;u32 n=M2C_FIELD(&data_02168fec,u8 *,0)-1;M2C_FIELD(&data_02168fec,u8 *,0)=n;if(n&255)return;func_020e35cc(M2C_FIELD(&data_02168fec,s32 *,4));M2C_FIELD(&data_02168fec,s32 *,4)=0;}

void func_020e4cd8(u16 *keys,u32 dst,u32 map,u32 pal,u16 x,u16 y,u32 tileArg) {M2C_UNK func_02007ef4();extern M2C_UNK data_02168fec;u32 i;u16 *p;u32 bits;u32 next,next2,cur;u32 offset;u32 source;if(!*keys)return;bits=pal<<28;offset=y<<5;p=(u16 *)(map+((x+offset)*2));i=0;do {s32 index=func_020e4b9c(*keys);source=M2C_FIELD(&data_02168fec,u32 *,4)+index*128;func_02007ef4(source,dst+tileArg*32,128);next=(tileArg+1)|(bits>>16);next2=(tileArg+2)|(bits>>16);cur=tileArg|(bits>>16);p[i]=cur;p[i+1]=next;p[i+32]=next2;p[i+33]=(tileArg+3)|(bits>>16);keys++;tileArg+=4;i+=2;}while(*keys);}

s8 func_020e4d80(void *arg0) {
    s8 func_01ffa6fc(void *);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020aacf0(void *);
    extern u16 *data_02101e84;

    void *temp_r2;
    void *temp_r1;
    u16 var_r3;
    s8 var_r0;
    u8 var_r12;

    func_020aacf0(M2C_FIELD(arg0, void **, 0x38));
    temp_r2 = M2C_FIELD(arg0, void **, 0x38);
    temp_r1 = M2C_FIELD(temp_r2, void **, 0x64);
    var_r3 = *data_02101e84;
    var_r0 = M2C_FIELD(temp_r1, s8 *, 0xb);
    var_r12 = 1;
    if (var_r0 == 1) {
        goto L944;
    }
    if (((u32)(M2C_FIELD(temp_r2, u8 *, 0x59) << 0x1b) >> 0x1f) == 0) {
        goto L940;
    }
    var_r0 = M2C_FIELD(temp_r1, s8 *, 0xc);
    if (var_r0 == 1) {
        goto L944;
    }
    var_r12 = 0;
L940:
L944:
    if (!(var_r12 & 0xff)) {
        if (!(var_r3 & 0x2)) {
            return var_r0;
        }
    }
    func_0208fe30(0x1000f);
    {
        void *temp_r0 = M2C_FIELD(arg0, void **, 0x38);
        if ((s32) M2C_FIELD(temp_r0, s8 *, 0x5a) >= 0) {
            M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03fc0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1c) >> 0x1c) + 1) << 0x18) >> 6));
            M2C_FIELD(temp_r0, s8 *, 0x5a) = 0xc;
        }
    }
    return func_01ffa6fc(arg0);
}

#pragma scheduling off
s32 func_020e4e44(void *arg0) {
    s16 temp_r1;
    s32 var_r1;

    temp_r1 = M2C_FIELD(arg0, s16 *, 0x3E);
    if ((s32) temp_r1 > 0) {
        M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (temp_r1 - 1);
    }
    if (M2C_FIELD(arg0, s16 *, 0x3E) == 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    if (!(var_r1 & 0xFF)) {
        return 0;
    }
    M2C_FIELD(arg0, u8 *, 0x3C) = (u8) ((u8) (M2C_FIELD(arg0, u8 *, 0x3C) & ~2) | 1);
    return 1;
}
#pragma scheduling reset
void func_020e4e8c(void *arg0) {
    M2C_UNK func_0200dedc(M2C_UNK *);
    extern M2C_UNK data_02168ff8;
    func_0200dedc(&data_02168ff8);
    M2C_FIELD(arg0, u8 *, 0x3C) = (u8) (M2C_FIELD(arg0, u8 *, 0x3C) | 2);
}

void func_020e4eb0(void *arg0) {
    void func_020067a8(void *, s32);
    s32 func_0207c8ec(s32, s32);
    void func_01ffaacc(s32, s32, s32, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_02168ff4;
    extern u8 data_027e00ac[];

    u8 cond;
    u8 idx;
    u8 nidx;
    u8 *r3p;
    u8 *r2p;
    s32 saved;
    u8 *arr;
    u8 b;
    u32 i;
    u32 maxv;
    u8 t;
    s32 tier;
    u32 sum;
    u8 *p;
    s32 divres;
    s32 r10;
    s32 r8v;
    u32 r9v;
    u16 a0;
    u16 **eng;
    u16 *base;
    u32 sh;
    u16 arg2;

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;

    cond = (*(volatile s16 *)((char *)arg0 + 0x3e) == 0);
    if (!cond) goto skip_all;

    arr = (u8 *)data_02168ff4;
    func_020067a8(arr, 0x20);

    maxv = 0;
    i = 0;
    do {
        b = arr[i];
        if (b >= 0x15 && b <= 0xea) {
            t = b;
            if (b < 0x80) {
                t = (u8)(0x100 - b);
            }
            if (maxv < t) {
                maxv = t;
            }
        }
        i = i + 1;
    } while (i < 0x20);

    if (maxv > 0xd0) tier = 4;
    else if (maxv > 0xbb) tier = 3;
    else if (maxv > 0xa3) tier = 2;
    else if (maxv > 0x8d) tier = 1;
    else tier = 0;

    idx = ((u8 *)arg0)[0x40];
    r3p = (u8 *)arg0 + 0x41;
    r2p = (u8 *)arg0 + 0x4b;
    ((u8 *)arg0 + idx)[0x41] = (u8)tier;

    idx = ((u8 *)arg0)[0x40];
    nidx = idx + 1;
    ((u8 *)arg0)[0x40] = nidx;
    if ((u8)(nidx & 0xff) >= 0x0a) {
        ((u8 *)arg0)[0x40] = 0;
    }

    sum = 0;
    p = r3p;
    if (p != r2p) {
        do {
            sum += *p;
            p++;
        } while (p != r2p);
    }

    divres = func_0207c8ec(sum, 10);
    r10 = divres;
    if (r10 > 3) {
        r10 = 3;
    } else if (r10 < 0) {
        r10 = 0;
    }

    r8v = 0x50;
    r9v = 0;
    if (r10 > 0) {
        do {
            a0 = (u16)(r8v & ((s32)data_027e00ac - 0x200));
            eng = (u16 **)gCur3DSpriteEngine;
            base = eng[0];
            sh = ((u32)base[0] << 17) >> 30;
            arg2 = (u16)(((s32)data_027e00ac & (0x140 >> sh)) | 0x6000);
            func_01ffaacc(a0, 0x28, arg2, 0x3ff, 0x11);

            r9v = (r9v + 1) & 0xff;
            r8v = (s16)(r8v + 0x20);
        } while (r9v < (u32)r10);
    }

skip_all:
    gCur3DSpriteEngine = saved;
}

