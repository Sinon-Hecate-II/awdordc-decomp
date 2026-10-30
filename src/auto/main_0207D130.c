/* 14 functions from 0x0207D130 to 0x0207DE50 (main), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern u8 data_02101884;
extern const s16 data_020ebe8c[24];
extern const s16 data_020ebe58[24];
extern const u16 data_021018a4[16];
extern const u16 data_021018c4[256];
extern const u8 data_020edebc[];

extern const u8 data_020ec6bc[], data_020ecabc[], data_020ecebc[], data_020ed2bc[], data_020ed6bc[], data_020edabc[], data_020ec2bc[];
extern u32 data_0214c0c0[2];
extern const u16 data_020ebddc[8];

void func_0207d130(void *a, void *b, s32 c, s32 d) {
    extern void **gCur3DSpriteEngine;
    (void)a; (void)b; (void)c; (void)d; (void)gCur3DSpriteEngine;
}

void func_0207d49c(s32 a, s32 b, s32 flags) {
    s32 left = 0x800, half = a >> 1, ax = a << 12, by = b << 12;
    s32 right = ax + 0x800, top = 0x800, bottom = by + 0x800;
    s16 vright, vy, vleft, y1, x1, y2, x2;
    vy = (s16)-b;
    vleft = (s16)-half;
    vright = (s16)half;
    if (flags & 0x1000) {
        left = right - 0x1000;
        right = -top;
    }
    if (flags & 0x2000) {
        top = bottom - 0x1000;
        bottom = -0x800;
    }
    y1 = (s16)(top >> 8);
    x1 = (s16)(left >> 8);
    y2 = (s16)(bottom >> 8);
    x2 = (s16)(right >> 8);
    *(volatile u32 *)0x4000500 = 1;
    *(volatile u32 *)0x4000488 = (u32)(u16)x1 | ((u32)(u16)y1 << 16);
    *(volatile u32 *)0x400048c = (u32)(u16)vleft | ((u32)(u16)vy << 16);
    *(volatile u32 *)0x400048c = 0;
    *(volatile u32 *)0x4000488 = (u32)(u16)x1 | ((u32)(u16)y2 << 16);
    *(volatile u32 *)0x400048c = (u16)vleft;
    *(volatile u32 *)0x400048c = 0;
    *(volatile u32 *)0x4000488 = (u32)(u16)x2 | ((u32)(u16)y2 << 16);
    *(volatile u32 *)0x400048c = (u16)vright;
    *(volatile u32 *)0x400048c = 0;
    *(volatile u32 *)0x4000488 = (u32)(u16)x2 | ((u32)(u16)y1 << 16);
    *(volatile u32 *)0x400048c = (u32)(u16)vright | ((u32)(u16)vy << 16);
    *(volatile u32 *)0x400048c = 0;
    *(volatile u32 *)0x4000504 = 0;
}

void func_0207d5c0(s32 a,s32 b,s32 flags){
s32 ax=a<<12,by=b<<12; s32 left=0x800,top=0x800,right=ax+0x800,bottom=by+0x800;
s16 vx,vy,y1,x1,y2,x2;
if(flags&0x1000){left=right-0x1000;right=-top;}
if(flags&0x2000){top=bottom-0x1000;bottom=-0x800;}
vx=(s16)a;vy=(s16)b;y1=(s16)(top>>8);x1=(s16)(left>>8);
y2=(s16)(bottom>>8);x2=(s16)(right>>8);
*(volatile u32 *)0x4000500=1;
*(volatile u32 *)0x4000488=(u32)(u16)x1|((u32)(u16)y1<<16);
*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000488=(u32)(u16)x1|((u32)(u16)y2<<16);
*(volatile u32 *)0x400048c=(u32)(u16)vy<<16;
*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000488=(u32)(u16)x2|((u32)(u16)y2<<16);
*(volatile u32 *)0x400048c=(u32)(u16)vx|((u32)(u16)vy<<16);
*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000488=(u32)(u16)x2|((u32)(u16)y1<<16);
*(volatile u32 *)0x400048c=(u16)vx;
*(volatile u32 *)0x400048c=0;
*(volatile u32 *)0x4000504=0;
}

s32 func_0207d6c8(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0x8:
        return 0;
    case 0x10:
        return 1;
    case 0x20:
        return 2;
    case 0x40:
        return 3;
    case 0x80:
        return 4;
    case 0x100:
        return 5;
    case 0x200:
        return 6;
    case 0x400:
        return 7;
    default:
        return 0;
    }
}

s32 func_0207d774(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0x8:
        return 0;
    case 0x10:
        return 1;
    case 0x20:
        return 2;
    case 0x40:
        return 3;
    case 0x80:
        return 4;
    case 0x100:
        return 5;
    case 0x200:
        return 6;
    case 0x400:
        return 7;
    default:
        return 0;
    }
}

void func_0207d820(s32 *v,s32 *m,s32 *out){
s32 y=v[1],x=v[0],z=v[2],w;
out[0]=(s32)(((s64)x*m[0]+(s64)y*m[4]+(s64)z*m[8])>>12);out[0]+=m[12];
out[1]=(s32)(((s64)x*m[1]+(s64)y*m[5]+(s64)z*m[9])>>12);out[1]+=m[13];
out[2]=(s32)(((s64)x*m[2]+(s64)y*m[6]+(s64)z*m[10])>>12);out[2]+=m[14];
w=(s32)(((s64)x*m[3]+(s64)y*m[7]+(s64)z*m[11])>>12);w+=m[15];
out[0]=((s64)out[0]<<12)/w;
out[1]=((s64)out[1]<<12)/w;
out[2]=((s64)out[2]<<12)/w;
}

void func_0207d95c(M2C_UNK *arg0) {
    extern M2C_UNK data_02101874;
    M2C_UNK *var_r0;

    var_r0 = arg0;
    if (var_r0 == NULL) {
        var_r0 = &data_02101874;
    }
    *(s32 *)0x04000580 = M2C_FIELD(var_r0, s32 *, 0) | (M2C_FIELD(var_r0, s32 *, 4) << 8) | (M2C_FIELD(var_r0, s32 *, 8) << 0x10) | (M2C_FIELD(var_r0, s32 *, 0xC) << 0x18);
}

void func_0207d990(s32 arg0, void *arg1, void *arg2) {
    M2C_UNK func_0200154c(s32, s32, s32, s32, s32);
    M2C_UNK func_02001624(s32, s32, s32, s32, s32);
    M2C_UNK func_02003fc8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32);
    M2C_FIELD((void *)0x04000440, s32 *, 0) = 0;
    M2C_FIELD((void *)0x04000440, s32 *, 0x14) = 0;
    func_02003fc8(-0x1200, 0x1200, -0x1800, 0x1800, 0, 0x2000, 0x1000, 1, arg0);
    func_0200154c(arg0, arg0, M2C_FIELD(arg2, s32 *, 0), M2C_FIELD(arg2, s32 *, 4), M2C_FIELD(arg2, s32 *, 8));
    func_02001624(arg0, arg0, M2C_FIELD(arg1, s32 *, 0), M2C_FIELD(arg1, s32 *, 4), M2C_FIELD(arg1, s32 *, 8));
    *(s32 *)0x0400044C = 0;
}

void func_0207da34(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02004b54();
    M2C_UNK func_02004bb0(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02004cf0();
    func_02004b54();
    func_02004bb0(arg0, arg1, arg2);
    func_02004cf0();
}

void func_0207da60(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02004d3c();
    M2C_UNK func_02004d70(s32, s32, s32);
    M2C_UNK func_02004ddc();
    M2C_UNK func_0207dacc(s32, s32);
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;

    var_r6 = arg0;
    var_r5 = arg1;
    var_r4 = arg2;
    if ((var_r6 & 2) || (var_r5 & 2) || (var_r4 & 2)) {
        if (var_r4 == 0) {
            return;
        }
        do {
            func_0207dacc(var_r6, var_r5);
            var_r6 += 2;
            var_r5 += 2;
            var_r4 -= 2;
        } while (var_r4 != 0);
        return;
    }
    func_02004d3c();
    func_02004d70(var_r6, var_r5, var_r4);
    func_02004ddc();
}

M2C_UNK func_0207dacc(s32 arg0,s32 arg1) {
s32 func_020033cc(void);
void func_02002e3c(s32);
s32 state=func_020033cc();
u32 base=(u32)data_020ebddc[state>>4]<<12;
data_0214c0c0[1]=state;
data_0214c0c0[0]=base;
*(u16 *)(base+(arg1&~1))=*(u16 *)arg0;
func_02002e3c(state);
}

void func_0207db18(u8 arg0) { switch(M2C_FIELD(*gCurrentMap,u8 *,0x5157)) {
case 4: M2C_FIELD(&data_02101884,const u8 **,4)=data_020ec6bc;break;
case 5: M2C_FIELD(&data_02101884,const u8 **,4)=data_020ecabc;break;
case 6: M2C_FIELD(&data_02101884,const u8 **,4)=data_020ecebc;break;
case 7: M2C_FIELD(&data_02101884,const u8 **,4)=data_020ed2bc;break;
case 8: M2C_FIELD(&data_02101884,const u8 **,4)=data_020ed6bc;break;
case 9: M2C_FIELD(&data_02101884,const u8 **,4)=data_020edabc;break;
default:M2C_FIELD(&data_02101884,const u8 **,4)=data_020ec2bc;break;
} data_02101884=arg0; }

u8 func_0207dbfc(void) {
    extern u8 data_02101884;
    return data_02101884;
}

u16 func_0207dc0c(s32 x, s32 y) {
    s16 first[24];
    s16 second[12];
    s32 mask = 0;
    {
        const u16 *src = (const u16 *)data_020ebe8c;
        u16 *dst = (u16 *)first;
        s32 count = 12;
        do {
            u16 a = src[0];
            u16 bb = src[1];
            src += 2;
            dst[0] = a;
            dst[1] = bb;
            dst += 2;
        } while (--count);
    }
    {
        void *map = *gCurrentMap;
        const u16 *tileAttr = ((const u16 **)&data_02101884)[1];
        const u32 (*attrs)[2] = (const u32 (*)[2])data_020edebc;
        {
            s32 i;
            s16 *p = first;
            for (i = 0; i < 8; i++, p += 3) {
                s32 nx = x + p[0];
                s32 ny = y + p[1];
                if (nx >= 0 && ny >= 0 && nx < M2C_FIELD(map, u16 *, 0x5144) && ny < M2C_FIELD(map, u16 *, 0x5146)) {
                    u16 off = M2C_FIELD((u8 *)map + ny * 2, u16 *, 0x3758);
                    u16 tile = M2C_FIELD((u8 *)map + (nx + off) * 2, u16 *, 0xa10);
                    if ((attrs[tileAttr[tile]][0] & 0x20000) == 0) {
                        mask |= 1 << i;
                        mask &= 0xff;
                    }
                }
            }
        }
        if (mask != 0) {
            s32 sub = mask & 0x5a;
            switch (sub) {
            case 2:
                if (mask & 0x94) goto skip_second;
                break;
            case 8:
                if (mask & 0xe0) goto skip_second;
                break;
            case 16:
                if (mask & 0x29) goto skip_second;
                break;
            case 64:
                if (mask & 0x07) goto skip_second;
                break;
            default:
                goto skip_second;
            }
            {
                s32 b = 0;
                {
                    const u16 *src = (const u16 *)data_020ebe58;
                    u16 *dst = (u16 *)second;
                    s32 count = 6;
                    do {
                        u16 a = src[0];
                        u16 bb = src[1];
                        src += 2;
                        dst[0] = a;
                        dst[1] = bb;
                        dst += 2;
                    } while (--count);
                }
                {
                    s32 i;
                    s16 *p = second;
                    for (i = 0; i < 4; i++, p += 3) {
                        s32 nx = x + p[0];
                        s32 ny = y + p[1];
                        if (nx >= 0 && ny >= 0 && nx < M2C_FIELD(map, u16 *, 0x5144) && ny < M2C_FIELD(map, u16 *, 0x5146)) {
                            u16 off = M2C_FIELD((u8 *)map + ny * 2, u16 *, 0x3758);
                            u16 tile = M2C_FIELD((u8 *)map + (nx + off) * 2, u16 *, 0xa10);
                            if ((attrs[tileAttr[tile]][0] & 0x80000) != 0) {
                                b |= 1 << i;
                                b &= 0xff;
                            }
                        }
                    }
                    {
                        u16 val = data_021018a4[b];
                        if (val != 0) {
                            return val;
                        }
                    }
                }
            }
        }
skip_second:
        return data_021018c4[mask];
    }
}

