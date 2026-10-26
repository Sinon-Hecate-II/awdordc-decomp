/* 22 functions from 0x020E4490 to 0x020E5080 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 pixels[32]; } Unk020ETile;
u16 *func_020e4c10(u16 *,u16 *,u16 *,u32);

void func_020e4570(void) {
    M2C_UNK func_020024cc();
    M2C_UNK func_02007598();
    func_02007598();
    func_020024cc();
    *(s32 *)0x04001000 |= 0x10000;
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

s32 func_020e4818(s32 a){extern u8 data_0215dba4[];u32 *p=(u32 *)(data_0215dba4+a*0x118);p[0]&=~15;p[0]&=~240;p[1]=(u16)(p[1]&0xffff0000);p[0]&=~0xff00;p[0]&=~0xff0000;p[0]&=~0xff000000;return p[0];}

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

void func_020e4b24(void) {

}

u8 func_020e4b28(s32 a){extern u8 data_0215dba4[];return ((u32)(M2C_FIELD(data_0215dba4,u32 *,a*0x118)<<16)>>24)!=0;}

s32 func_020e4b54(void) {
    extern u16 data_02168f14;
    extern void **data_027e0058;
    if (!(((u32) (data_02168f14 << 0x1D) >> 0x1D) & 0xFF) && (M2C_FIELD(*data_027e0058, u16 *, 0x5142) == 0xBA)) {
        return 1;
    }
    return 0;
}

s32 func_020e4b9c(u16 key,...){extern u16 data_0212da1c;extern u16 data_020f4eb4[];volatile u8 a=0;volatile u8 b=0;u16 *p=func_020e4c10(data_020f4eb4,data_020f4eb4+data_0212da1c,&key,*(u32 *)&b);if(*p!=key)return 0;return p-data_020f4eb4;}

u16 *func_020e4c10(u16 *first,u16 *last,u16 *key,u32 unused){s32 n=last-first;while(n>0){s32 half=n/2;u16 *p=first+half;if(*p>=*key){n=half;continue;}half++;n-=half;first=p+1;}return first;}

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
    void *temp_r0;

    func_020aacf0(M2C_FIELD(arg0, void **, 0x38));
    temp_r2 = M2C_FIELD(arg0, void **, 0x38);
    temp_r1 = M2C_FIELD(temp_r2, void **, 0x64);
    var_r3 = *data_02101e84;
    var_r0 = M2C_FIELD(temp_r1, s8 *, 0xb);
    var_r12 = 1;
    if (var_r0 != 1) {
        if (((u32) (M2C_FIELD(temp_r2, u8 *, 0x59) << 0x1b) >> 0x1f) != 0) {
            var_r0 = M2C_FIELD(temp_r1, s8 *, 0xc);
            if (var_r0 != 1) {
                var_r12 = 0;
            }
        }
    }
    if (!(var_r12 & 0xff) && !(var_r3 & 0x2)) {
        return var_r0;
    }
    func_0208fe30(0x1000f);
    temp_r0 = M2C_FIELD(arg0, void **, 0x38);
    if ((s32) M2C_FIELD(temp_r0, s8 *, 0x5a) >= 0) {
        M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03fc0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1c) >> 0x1c) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0, s8 *, 0x5a) = 0xc;
    }
    return func_01ffa6fc(arg0);
}

s32 func_020e4e44(void *a) {s16 n=M2C_FIELD(a,s16 *,62);s32 done;s32 flags;if(n>0)M2C_FIELD(a,s16 *,62)=n-1;if(M2C_FIELD(a,s16 *,62)==0)done=1;else done=0;if(!(done&255))return 0;flags=M2C_FIELD(a,u8 *,60)&~2;M2C_FIELD(a,s8 *,60)=(u8)flags|1;return 1;}

void func_020e4e8c(void *arg0) {
    M2C_UNK func_0200dedc(M2C_UNK *);
    extern M2C_UNK data_02168ff8;
    func_0200dedc(&data_02168ff8);
    M2C_FIELD(arg0, u8 *, 0x3C) = (u8) (M2C_FIELD(arg0, u8 *, 0x3C) | 2);
}

