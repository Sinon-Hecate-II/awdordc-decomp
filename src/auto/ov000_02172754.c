/* 10 functions from 0x02172754 to 0x02173468 (ov000), found by ds-decomp. */
#include "common.h"
extern s32 data_ov000_021b976c, data_ov000_021b9bec, data_ov000_021bb06c, data_ov000_021b9c6c, data_ov000_021b99ec, data_ov000_021bb1ec;
extern void *data_027e00c4;
extern void *gCur3DSpriteEngine;
extern void **gCurrentMap;extern M2C_UNK data_ov000_021c1944, data_ov000_021c13b0, data_ov000_021c11dc, data_ov000_021c1764, data_ov000_021c1b28, data_ov000_021c1d0c;
extern M2C_UNK data_ov000_021d841c, data_ov000_021b8f5c;

void func_ov000_02172754(void *arg0) {
    s32 func_ov000_0216cbc4(s32);
    s32 func_020a86c4(s32, s32);
    s32 func_0207c8ec(s32, s32);
    void func_02098a34(s32, s32, s32, s32, u8);
    s32 func_020a334c(s32);
    s32 func_020a3594(M2C_UNK, M2C_UNK);
    s32 func_020719d4(s32);
    s32 func_020714f0(s32, s32);
    s32 func_02071a1c(u8);
    s32 func_02071a64(u32, u32);
    s32 func_02071564(s32, s32);
    u32 func_020719a0(s32);
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c4;
    extern void **gCurrentMap;
    extern s8 data_ov000_021b5560[32];

    void *saved;
    s32 *p18;
    s32 val;
    s32 i;
    s32 off;
    s32 changed;
    void *rec;
    u8 *rcd;
    s32 r7;

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    p18 = *(s32 **)((u8 *)arg0 + 0x18);
    val = func_ov000_0216cbc4(p18[0]);
    val = func_020a86c4(0, val);
    if (val >= 0 && val <= 0x270f && val != p18[2]) {
        s32 q,rem;
        q = func_0207c8ec(val, 0x3e8);
        p18[6] = q;
        rem = val - q * 0x3e8;
        q = func_0207c8ec(rem, 0x64);
        p18[5] = q;
        rem = rem - q * 0x64;
        q = func_0207c8ec(rem, 0xa);
        p18[4] = q;
        p18[3] = rem - q * 0xa;
        p18[2] = val;
    }
    p18[1] = data_ov000_021b5560[func_ov000_0216cbc4(p18[0])];

    changed = 0;
    i = 0;
    off = 0;
    while (i < 4) {
        rec = (void *)((u8 *)*((void **)gCurrentMap) + 0x67a4 + (i + 1) * 0x8c);
        rcd = (u8 *)p18 + 0x3c + off;
        {
            u8 b1e = *((u8 *)rec + 0x1e);
            u8 old33 = rcd[0x33];
            u8 old34 = rcd[0x34];
            if (b1e != 0) {
                u8 b19 = *((u8 *)rec + 0x19);
                if (b19 != 0) rcd[0x33] = 0; else rcd[0x33] = 1;
                rcd[0x34] = (*((u8 *)rec + 0x1c) != 0);
            }
            if (old33 != rcd[0x33]) changed = 1;
            if (old34 != rcd[0x34]) {
                s32 rec6c;
                int j,k;
                s32 r8v;
                changed = 1;
                rec6c = *(s32 *)((u8 *)rec + 0x6c);
                func_02098a34((u8)(rec6c & 0xff), 0, 2, 0, (u8)8);
                r7 = *(s32 *)rec;
                if (r7 >= 0 && r7 <= 0xf423f) {
                    if (r7 != *(s32 *)(rcd + 0x2c)) {
                        s32 cur;
                        *(s32 *)(rcd + 0x2c) = r7;
                        *(s32 *)(rcd + 0x28) = 1;
                        cur = r7;
                        for (k = 5; k >= 0; k--) {
                            r8v = 1;
                            for (j = 0; j < k; j++) r8v *= 10;
                            {
                                s32 q2 = func_0207c8ec(cur, r8v);
                                if (*(s32 *)(rcd + 0x28) == 1 && q2 != 0) *(s32 *)(rcd + 0x28) = k + 1;
                                cur = cur - q2 * r8v;
                                *(s32 *)(rcd + 0x10 + k * 4) = q2;
                            }
                        }
                    }
                }
                rcd[0x0c] = *((u8 *)rec + 0x18);
                rcd[0x08] = *((u8 *)rec + 0x31);
                *(u8 *)(rcd + 0x30) = (u8)func_020a334c(1);
                r7 = func_020a3594((M2C_UNK)1, (M2C_UNK)2);
                if (func_020714f0(0, func_020719d4(r7)) != 0) {
                    s32 r6c = *(s32 *)((u8 *)rec + 0x6c);
                    u8 b21 = (u8)(r6c >> 21);
                    s32 r4v = func_02071a64(0x41400000u, (u32)func_02071a1c(b21));
                    *(s32 *)(rcd + 0x4) = func_020719a0(func_02071564(r4v, func_020719d4(r7)));
                    *(u8 *)(rcd + 0x31) = (u8)((r7 == (r6c >> 21)) ? 1 : 0);
                } else {
                    *(s32 *)(rcd + 0x4) = 0;
                    *(u8 *)(rcd + 0x31) = 0;
                }
                *(u8 *)(rcd + 0x32) = 1;
            }
        }
        i++;
        off += 0x38;
    }
    gCur3DSpriteEngine = saved;
}

void func_ov000_02172aa0(void) {
 M2C_UNK func_0207c780(M2C_UNK *,s32); u32 func_ov000_02175074();
 void *saved; s32 base; M2C_UNK *p;
 base=M2C_FIELD(data_027e00c4,s32 *,0x28); saved=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c4;
 switch(func_ov000_02175074()) {
 case 0:p=&data_ov000_021c1944;break;
 case 1:p=&data_ov000_021c13b0;break;
 case 2:p=&data_ov000_021c11dc;break;
 case 3:p=&data_ov000_021c1764;break;
 case 4:p=&data_ov000_021c1b28;break;
 case 5:p=&data_ov000_021c1d0c;break;
 default:p=&data_ov000_021c1944;break;
 }
 func_0207c780(p,base);gCur3DSpriteEngine=saved;
}

void func_ov000_02172b4c(void *arg0) {
    M2C_UNK func_0207c780(M2C_UNK *,s32);
    void func_01ff9e44(M2C_UNK,s32,s32);
    void func_0209b26c(s32,s32,s32,s32,s32,u16);
    s32 func_ov000_0217244c();
    s32 func_ov000_02172458(s32,s32);
    s32 func_ov000_02172478(s32,s32);
    s32 func_ov000_02172488(s32,s32);
    s32 func_ov000_02172498(s32,s32);
    s32 func_ov000_021724a8(s32,s32);
    s32 func_ov000_021724cc(s32,s32);
    s32 ctx; void *saved; s32 y; s32 color;
    ctx=func_ov000_0217244c();
    color=M2C_FIELD(arg0,s32 *,0)?0xa3:0x103;
    saved=gCur3DSpriteEngine;
    gCur3DSpriteEngine=data_027e00c4;
    y=M2C_FIELD(arg0,s32 *,0)?M2C_FIELD(data_027e00c4,s32 *,0x10)+0x20:M2C_FIELD(data_027e00c4,s32 *,0x10)+0xa40;
    if(func_ov000_02172458(ctx,*M2C_FIELD(arg0,s32 **,0x18))){
        func_0207c780((M2C_UNK *)func_ov000_02172458(ctx,*M2C_FIELD(arg0,s32 **,0x18)),y);
    } else {
        func_0207c780(&data_ov000_021d841c,y);
    }
    if(func_ov000_02172458(ctx,*M2C_FIELD(arg0,s32 **,0x18))){
        switch(M2C_FIELD(M2C_FIELD(gCurrentMap,s32 *,0)+0x5000,u8 *,0x157)){
        case 0: case 5: case 7: case 8: case 9:
            func_01ff9e44(func_ov000_02172478(ctx,*M2C_FIELD(arg0,s32 **,0x18)),0x80,0xc0); break;
        case 1:
            func_01ff9e44(func_ov000_02172498(ctx,*M2C_FIELD(arg0,s32 **,0x18)),0x80,0xc0); break;
        case 2:
            func_01ff9e44(func_ov000_021724a8(ctx,*M2C_FIELD(arg0,s32 **,0x18)),0x80,0xc0); break;
        case 3: case 4: case 6:
            func_01ff9e44(func_ov000_02172488(ctx,*M2C_FIELD(arg0,s32 **,0x18)),0x80,0xc0); break;
        }
    } else {
        func_01ff9e44((s32)&data_ov000_021b8f5c,0x80,0xc0);
    }
    func_0209b26c(2,0xa,1,func_ov000_021724cc(ctx,*M2C_FIELD(arg0,s32 **,0x18)),0xf000,(u16)color);
    gCur3DSpriteEngine=saved;
}

void func_ov000_02172d28(void *arg0) {
 M2C_UNK func_020807e4(s32,s32,u16,s32);
 s32 func_ov000_0217244c(); s32 func_ov000_02172468(s32,s32);
 s32 base; void *saved; s32 ctx,value; s32 color;
 saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;
 ctx=func_ov000_0217244c();
 base=M2C_FIELD(data_027e00c4,s32 *,0x24);
 color=M2C_FIELD(arg0,s32 *,0)?0x52:1;
 value=func_ov000_02172468(ctx,*M2C_FIELD(arg0,s32 **,0x18));
 if(func_ov000_02172468(ctx,*M2C_FIELD(arg0,s32 **,0x18))) func_020807e4(value,base+0xc4,(u16)color,4);
 gCur3DSpriteEngine=saved;
}

void func_ov000_02172dc0(void *p){
M2C_UNK func_020807e4(s32,s32,u16,s32);
void *ctx,*saved;
if(M2C_FIELD(p,s32*,12)%4==0){
s32 *frames[6]={&data_ov000_021b976c,&data_ov000_021b9bec,&data_ov000_021bb06c,&data_ov000_021b9c6c,&data_ov000_021b99ec,&data_ov000_021bb1ec};
s32 index; u16 color; s32 **table=frames;
saved=gCur3DSpriteEngine;ctx=data_027e00c4;gCur3DSpriteEngine=ctx;
index=M2C_FIELD(p,s32*,12)/4;
color=M2C_FIELD(p,s32*,0)?0x52:1;
func_020807e4((s32)table[index],M2C_FIELD(ctx,s32*,0x24)+0xc4,(u16)color,4);
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
gCur3DSpriteEngine=saved;
}
M2C_FIELD(p,s32*,12)++;
if(M2C_FIELD(p,s32*,12)>=24)M2C_FIELD(p,s32*,12)=0;
}

void func_ov000_02172e90(void *arg0) {
    M2C_UNK func_020ae354(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern u8 data_ov000_021ae25c[12];

    void *saved;
    u8 buf[6];
    s32 i;
    s32 off;
    void *rec;
    u8 mapByte;
    s32 rcd;
    s32 counter;
    s32 t;
    u8 r3v;
    u16 h;
    u8 *tab;
    u8 *p;

    buf[0] = data_ov000_021ae25c[6];
    buf[1] = data_ov000_021ae25c[7];
    buf[2] = data_ov000_021ae25c[8];
    buf[3] = data_ov000_021ae25c[9];
    buf[4] = data_ov000_021ae25c[10];
    buf[5] = data_ov000_021ae25c[11];

    *(s32 *)((s8 *)arg0 + 0x10) = *(s32 *)((s8 *)arg0 + 0x10) + 1;
    if (*(s32 *)((s8 *)arg0 + 0x10) > 0x80) {
        *(s32 *)((s8 *)arg0 + 0x10) = 0;
    }

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;

    i = 0;
    off = 0;
    do {
        rec = (void *)((i + 1) * 0x8c + (s32)*gCurrentMap + 0x67a4);
        rcd = *(s32 *)((s8 *)arg0 + 0x18) + 0x3c + off;
        mapByte = *(u8 *)((s8 *)rec + 0x1d);
        tab = *(u8 **)((s8 *)gCur3DSpriteEngine + 0x30);
        p = tab + (buf[mapByte] << 5);
        h = *(u16 *)((s8 *)p + 0x1e);

        if (*(u8 *)((s8 *)rcd + 0x34) == 0) {
            *(u16 *)((s8 *)p + 0x06) = (u16)func_020ae354(h, 0, 8, 8);
        } else {
            if (*(u8 *)((s8 *)rcd + 0x30) != 0) {
                counter = *(s32 *)((s8 *)arg0 + 0x10);
                t = counter / 32;
                if (t <= 0x10) {
                    r3v = (u8)((t >> 1) & 0xff);
                } else {
                    t = t - 0x10;
                    t = t >> 1;
                    r3v = (u8)((8 - t) & 0xff);
                }
            } else if (*(u8 *)((s8 *)rcd + 0x31) != 0) {
                counter = *(s32 *)((s8 *)arg0 + 0x10);
                if (counter <= 0x40) {
                    r3v = (u8)((counter >> 3) & 0xff);
                } else {
                    counter = counter - 0x40;
                    counter = counter >> 3;
                    r3v = (u8)((8 - counter) & 0xff);
                }
            } else {
                r3v = 0;
            }
            *(u16 *)((s8 *)p + 0x06) = (u16)func_020ae354(h, 0xffff, (16 - r3v) & 0xff, r3v);
        }

        i = i + 1;
        off = off + 0x38;
    } while (i < 4);

    *(u8 *)((s8 *)gCur3DSpriteEngine + 0x46) =
        (u8)(*(u8 *)((s8 *)gCur3DSpriteEngine + 0x46) | 0x10);
    gCur3DSpriteEngine = saved;
}

void func_ov000_02173058(void *arg0) {
 s32 func_ov000_0217244c();
 s32 func_ov000_021724b8(s32,s32);
 s32 func_020e3438(s32);
 void func_02007ef4(s32,s32);
 s32 base; void *saved; s32 index;
 saved=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c4;
 index=func_ov000_021724b8(func_ov000_0217244c(),*M2C_FIELD(arg0,s32 **,0x18));
 base=M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x2880;
 if(index!=-1) func_02007ef4(0x4e0*(s16)index+func_020e3438(2),base);
 gCur3DSpriteEngine=saved;
}

#pragma opt_strength_reduction off
void func_ov000_021730cc(void *arg0) {
    M2C_UNK func_01ff9ce8(s32);
    M2C_UNK func_020807e4(s32, s32, u16, s32);
    void func_02098844(u32, s32, s32, s32, u16, u16, u8);
    u32 func_ov000_02175074();
    extern u8 data_ov000_021ae25c[12];
    extern u16 data_ov000_021b8df4[4];
    extern M2C_UNK data_ov000_021b8f7c, data_ov000_021b8fe4, data_ov000_021b904c, data_ov000_021b90b4, data_ov000_021b911c, data_ov000_021b9184;

    void *saved;
    u8 buf[6];
    M2C_UNK *sel;
    s32 i;
    s32 dst;
    M2C_UNK *rec;
    s32 off;
    s32 boff;
    s32 row;

    buf[0] = data_ov000_021ae25c[0];
    buf[1] = data_ov000_021ae25c[1];
    buf[2] = data_ov000_021ae25c[2];
    buf[3] = data_ov000_021ae25c[3];
    buf[4] = data_ov000_021ae25c[4];
    buf[5] = data_ov000_021ae25c[5];
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_01ff9ce8(0);
    i = 0;
    off = 0;
    boff = 0;
    row = 2;
    do {
        rec = (M2C_UNK *)((i + 1) * 0x8c + ((s32)*gCurrentMap + 0x67a4));
        if (M2C_FIELD(M2C_FIELD(arg0, s32 *, 0x18) + off, u8 *, 0x6f) != 0) {
            dst = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28) + 0xac + boff * 2;
            switch (func_ov000_02175074()) {
            case 0: sel = &data_ov000_021b90b4; break;
            case 1: sel = &data_ov000_021b8f7c; break;
            case 2: sel = &data_ov000_021b8fe4; break;
            case 3: sel = &data_ov000_021b911c; break;
            case 4: sel = &data_ov000_021b9184; break;
            case 5: sel = &data_ov000_021b904c; break;
            default: sel = &data_ov000_021b90b4; break;
            }
            func_020807e4((s32)sel, dst, (u16)(M2C_FIELD(rec, u8 *, 0x27) << 5), buf[M2C_FIELD(rec, u8 *, 0x1d)]);
            func_02098844(0, 0x1a, row, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), data_ov000_021b8df4[i], (u16)i, 0);
            boff += 0xa0;
            row += 5;
        }
        off += 0x38;
        i++;
    } while (i < 4);
    gCur3DSpriteEngine = saved;
}
#pragma opt_strength_reduction reset
void func_ov000_02173290(void *arg0) {
     void func_ov000_02172b4c(void *);
 void func_ov000_02173058();
 func_ov000_02173058();
    if (M2C_FIELD(arg0, u8 *, 0x15) != 0) {
        return;
    }
    func_ov000_02172b4c(arg0);
    M2C_FIELD(arg0, s32 *, 0) = (s32) (1 - M2C_FIELD(arg0, s32 *, 0));
}

void func_ov000_021732c0(void *arg0) {
    void func_020809c0(M2C_UNK, s32, s32);
    s32 func_0209b2b4(s32, s32, s32, s32, s32, s32);
    void func_020c1230(M2C_UNK, M2C_UNK, s32, s32);
    void func_020c1d28(s32, s32, s32, s32);
    s32 func_020cfb78(void);
    void func_ov000_02172aa0(void);
    void func_ov000_02172d28(void *);
    void func_ov000_021730cc(void *);
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c4;
    extern void **gCurrentMap;

    void *saved;
    void **mapPtr;
    u32 temp_r2;
    u32 temp_r3;
    u32 xm;
    u32 ym;

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    M2C_FIELD(M2C_FIELD(data_027e00c4, void **, 0), s16 *, 0x38) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x40) = 0;
    func_ov000_02172aa0();
    if (M2C_FIELD(arg0, u8 *, 0x15) == 0) {
        func_ov000_02172d28(arg0);
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3A) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = 0;
    } else {
        func_020809c0(M2C_FIELD(data_027e00c4, s32 *, 0x28) + 0x80, 0x18, 0x14);
        mapPtr = *gCurrentMap;
        temp_r2 = M2C_FIELD(mapPtr, u16 *, 0x5144) * 4;
        temp_r3 = M2C_FIELD(mapPtr, u16 *, 0x5146) * 4;
        xm = 0x58 - ((s32) (temp_r2 + (temp_r2 >> 0x1F)) >> 1);
        ym = 0x60 - ((s32) (temp_r3 + (temp_r3 >> 0x1F)) >> 1);
        func_020c1230(M2C_FIELD(gCur3DSpriteEngine, M2C_UNK *, 0x10), M2C_FIELD(gCur3DSpriteEngine, M2C_UNK *, 0x24), 1, 10);
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3A) = (s16) (0 - xm);
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = (s16) (0 - ym);
        func_020c1d28(xm, ym, 0x60, 7);
        func_0209b2b4(1, 2, 2, func_020cfb78(), 0xF000, 0x340);
    }
    func_ov000_021730cc(arg0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    gCur3DSpriteEngine = saved;
}

