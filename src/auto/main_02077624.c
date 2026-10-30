/* 21 functions from 0x02077624 to 0x020785B0 (main), found by ds-decomp. */
#include "common.h"
static inline s32 cellIndex02078170(s32 x,s32 y) { extern s32 *gCurrentMap; return x+M2C_FIELD(*gCurrentMap+y*2,u16 *,0x3758); }
static inline u8 initialCell02078170(s8 elev) { return elev>=0 ? 2:0; }
static inline u8 mapByte020778cc(s32 map,u32 index) { return M2C_FIELD(map+index,u8 *,0x1420); }
static inline u8 mapFog020778cc(u8 *bits,u32 index) { return bits[index>>3] & (1<<(index&7)); }
static inline u8 *mapBits020778cc(u8 *dims) { return dims+0xe1; }
static inline u32 tileFlags020778cc(u16 tile) {
 extern u32 data_020edebc[][2];
 return data_020edebc[tile][0] & 0x7fff0000;
}

typedef struct Unk0207Color3 { u32 words[3]; } Unk0207Color3;
extern const Unk0207Color3 data_020eb1b4;
extern const Unk0207Color3 data_020eb1a8;
extern void *gCur3DSpriteEngine;
s16 func_0207cfb8(void *);
s32 func_0207ca38(s32, s32, s32, s32, s32);
void func_0207d990(s32, void *, void *);

void func_02077624(void) {
    M2C_UNK func_02003de4();
    s32 func_0207ca38(s32, s32, s32, s32, s32);
    extern u32 data_027e15bc;
    extern const u16 data_020eb210[];
    extern const u16 data_020eb250[];
    extern u16 data_02140fc8[];
    s32 i;
    s32 blend;
    const u16 *src0;
    const u16 *src1;
    s32 a;
    s32 b;
    s32 lo;
    s32 mid;
    s32 hi;

    i = 0;
    blend = data_027e15bc & 0x3F;
    if (blend < 0x20) {
        src0 = data_020eb210;
        src1 = data_020eb250;
    } else {
        src0 = data_020eb250;
        src1 = data_020eb210;
        blend -= 0x20;
    }
    do {
        a = src0[i];
        b = src1[i];
        lo = func_0207ca38(0, a & 0x1F, b & 0x1F, blend, 0x20);
        mid = func_0207ca38(0, (a & 0x3E0) >> 5, (b & 0x3E0) >> 5, blend, 0x20);
        hi = func_0207ca38(0, (a & 0x7C00) >> 0xA, (b & 0x7C00) >> 0xA, blend, 0x20);
        data_02140fc8[i] = lo | (mid << 5) | (hi << 10);
        i++;
    } while (i < 0x20);
    func_02003de4();
}

void func_02077700(void) {
    M2C_UNK func_02001fb4(M2C_UNK, s32);
    extern M2C_UNK data_02140f70;
    func_02001fb4(0x60000, M2C_FIELD(&data_02140f70, s32 *, 0x18) * 3);
}

void func_02077720(void) {*(volatile u32 *)0x40004c0=0x7fffffff;*(volatile u32 *)0x40004c4=0x7fff4210;}

void func_02077740(void) {
    extern s32 *gCurrentMap;
    s32 *base;
    u16 width;
    u16 height;
    s32 mode;
    u16 px;
    u16 py;
    u16 tx;
    u16 ty;

    base = *gCurrentMap;
    width = *(u16 *)((u8 *)base + 0x5144);
    height = *(u16 *)((u8 *)base + 0x5146);
    mode = func_0207cfb8((void *)((u8 *)base + 0x6EF8));

    if (mode <= 0) mode = 0x10;
    else mode = 0x18;

    switch (mode) {
    case 0x10:
        *(volatile u32 *)0x40004a8 = 0x6c9364a4;
        px = width << 8;
        py = height << 8;
        break;
    case 0x18:
        *(volatile u32 *)0x40004a8 = 0x6d2364b4;
        px = width << 9;
        py = height << 9;
        break;
    }

    tx = width * 3;
    tx = tx << 8;
    ty = height * 3;
    ty = ty << 8;

    *(volatile u32 *)0x40004ac = 0x152;
    *(volatile u32 *)0x40004a4 = 0x3080080;
    *(volatile u32 *)0x4000480 = 0x7fff;
    *(volatile u32 *)0x4000500 = 1;

    *(volatile u32 *)0x4000488 = 0;
    *(volatile u32 *)0x400048c = 0;
    *(volatile u32 *)0x400048c = 0x420;

    *(volatile u32 *)0x4000488 = (u32)py << 16;
    *(volatile u32 *)0x400048c = (u32)ty << 16;
    *(volatile u32 *)0x400048c = 0x420;

    *(volatile u32 *)0x4000488 = (u32)px | ((u32)py << 16);
    *(volatile u32 *)0x400048c = (u32)tx | ((u32)ty << 16);
    *(volatile u32 *)0x400048c = 0x420;

    *(volatile u32 *)0x4000488 = (u32)px;
    *(volatile u32 *)0x400048c = (u32)tx;
    *(volatile u32 *)0x400048c = 0x420;

    *(volatile u32 *)0x4000504 = (u32)width << 24;
}

#pragma push
#pragma optimization_level 2
void func_020778cc(s32 left,s32 top,s32 right,s32 bottom) {
 void func_02079310(s32,s32,s32,s32,u8,u8,u8,u8);
 extern s32 *gCurrentMap;
 extern u8 data_02141f08[];
 extern u8 data_02142ebc[3840];
 extern u32 data_020edebc[][2];
 extern u8 data_02141788[];
 s32 x,y;
 u32 flags;
 s32 base;
 u32 index;
 u8 *bits;
 u8 *dims;
 u8 fog,terrain,a,b;
 *(volatile u32 *)0x04000444=0;
 *(volatile u32 *)0x04000470=0;
 *(volatile u32 *)0x04000470=0;
 *(volatile u32 *)0x04000470=-16;
 for(y=top;y<=bottom;y++) {
 for(x=left;x<=right;x++) {
 if(x>=0 && y>=0) {
 base=*gCurrentMap;
 dims=(u8 *)base+0x5120;
 if(x<M2C_FIELD(dims,u16 *,0x24) && y<M2C_FIELD(dims,u16 *,0x26)) {
 flags=tileFlags020778cc(*(u16 *)(data_02142ebc+x*80+y*2));
 if(flags&0x20000) {
 bits=mapBits020778cc(dims);
 index=x+M2C_FIELD(base+y*2,u16 *,0x3758);
 fog=mapFog020778cc(bits,index);
 terrain=mapByte020778cc(base,index);
 a=(data_02141f08+x*40)[y];
 b=(data_02141788+x*40)[y];
 func_02079310(x,y,0xac,0,terrain,fog,a,b);
 }
 }
 }
 }
 }
 *(volatile u32 *)0x04000448=1;
}
#pragma pop
void func_02077a30(void) {
    M2C_UNK func_02003d8c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_02003d8c(0, 0, 0, 0);
}

void func_02077a4c(void) {extern M2C_UNK data_02140f70;M2C_FIELD(&data_02140f70,s32 *,4)=0;*(volatile u32 *)0x40004c8=0x20000000;*(volatile u32 *)0x40004cc=0x7fff;}

void func_02077a7c(void) {void func_02077c8c();void func_02077eb8(void);void func_02077ebc(void);void func_0207ce28();void func_0207cbb0();void func_0207749c();extern s32 *gCurrentMap;
func_02077c8c();func_02077a4c();func_02077eb8();func_02077ebc();func_0207ce28(*gCurrentMap+0x6ef8);func_0207cbb0();func_0207749c();}

/* Interpolate two constant backdrop colors by blend factor t and store the resulting RGB plus engine viewport dimensions into data_02140f88. */
M2C_UNK func_02077ab8(s32 arg0) {
    extern M2C_UNK data_02140f88;
    Unk0207Color3 colorTop = data_020eb1b4;
    Unk0207Color3 colorBottom = data_020eb1a8;
    s32 t = func_0207cfb8((void *)arg0);
    s32 colors[3];
    s32 dims[3];
    void *engine;

    colors[0] = func_0207ca38(0, colorTop.words[0], colorBottom.words[0], t, 0x80);
    colors[1] = func_0207ca38(0, colorTop.words[1], colorBottom.words[1], t, 0x80);
    colors[2] = func_0207ca38(0, colorTop.words[2], colorBottom.words[2], t, 0x80);
    engine = gCur3DSpriteEngine;
    dims[0] = (M2C_FIELD(engine, s16 *, 0x3C) + M2C_FIELD(engine, s16 *, 0x40)) * 0x30;
    dims[1] = (M2C_FIELD(engine, s16 *, 0x3E) + M2C_FIELD(engine, s16 *, 0x42)) * 0x30;
    dims[2] = 0;
    func_0207d990((s32)&data_02140f88, colors, dims);
}

void func_02077bb4(s32 arg0) {void func_02003a8c();void func_02001034();extern M2C_UNK data_02140f88;u8 temp[64];
*(volatile u32 *)0x4000440=0;*(volatile u32 *)0x4000454=0;func_02003a8c(&data_02140f88);func_02001034(arg0+28,temp);func_02003a8c(temp);*(volatile u32 *)0x4000440=2;*(volatile u32 *)0x4000454=0;}

void func_02077c10(void) {
    M2C_UNK func_02077ab8(s32);
    void func_02077bb4(s32);
    M2C_UNK func_0207cd0c(s32);
    M2C_UNK func_0207cddc(s32, M2C_UNK *);
    M2C_UNK func_0207ce54(s32);
    M2C_UNK func_0207d95c(M2C_UNK);
    extern M2C_UNK data_02140f88;
    extern s32 *gCurrentMap;
    s32 temp_r4;

    temp_r4 = *gCurrentMap + 0x2F8;
    func_0207d95c(0);
    func_02077ab8(temp_r4 + 0x6C00);
    func_0207ce54(temp_r4 + 0x6C00);
    func_0207cd0c(temp_r4 + 0x6C00);
    func_0207cddc(temp_r4 + 0x6C00, &data_02140f88);
    func_02077bb4(temp_r4 + 0x6C00);
}

void func_02077c64(void) {
    M2C_UNK func_02003bd0();
    void func_02077720();
    M2C_UNK func_02078828();
    func_02003bd0();
    func_02078828();
    func_02077720();
}

void func_02077c78(void) {
    *(s32 *)0x04000540 = 0;
}

void func_02077c8c(void) {
    void func_02003ac4(void);
    void func_02003c64(void);
    M2C_UNK func_02003dfc(s32, s32, s16, s32, s32);
    M2C_UNK func_02003de4(M2C_UNK);
    void func_02077a30(void);
    extern u32 data_027e00bc;
    extern void *gCur3DSpriteEngine;
    extern s32 *gCurrentMap;
    extern u16 data_02140fc8[];

    u8 *obj;
    u16 *p;
    void **eng;
    u8 *cur;
    u8 *node;
    u8 *hw;
    u16 *hp;
    u32 val;

    obj = (u8 *)data_027e00bc;
    *(u32 *)(obj + 0x34) = 1;
    eng = (void **)gCur3DSpriteEngine;
    cur = (u8 *)*eng;
    p = (u16 *)cur;
    p[0] = p[0] & ~7;
    p = (u16 *)data_027e00bc;
    p[0] = p[0] | 8;
    node = (u8 *)*eng;
    p = (u16 *)node;
    p[0] = p[0] | 0x10;
    node = (u8 *)*eng;
    p = (u16 *)node;
    p[0] = p[0] | 0x20;
    node = (u8 *)*eng;
    p = (u16 *)node;
    p[0] = p[0] | 0x40;
    node = (u8 *)*eng;
    p = (u16 *)node;
    p[0] = p[0] | 0x80;
    node = (u8 *)*eng;
    p = (u16 *)node;
    p[0] = p[0] | 0x100;

    node = (u8 *)*eng;
    obj = node;
    p = (u16 *)*(u32 *)obj;
    p[3] = (p[3] & ~3) | 3;
    obj = node;
    p = (u16 *)*(u32 *)obj;
    p[4] = p[4] & ~3;
    obj = node;
    p = (u16 *)*(u32 *)obj;
    p[5] = p[5] & ~3;
    obj = node;
    p = (u16 *)*(u32 *)obj;
    p[6] = p[6] & ~3;

    func_02003ac4();
    func_02003c64();

    {
        void **q = (void **)((u8 *)gCurrentMap + 4);
        void *field4 = *q;
        void (**cbp)(void) = (void (**)(void))((u8 *)field4 + 0x4c);
        void (*cb)(void) = *cbp;
        if (cb != 0) {
            cb();
        }
    }

    hw = (u8 *)0x4000000;
    val = *(u32 *)hw;
    val = (val & ~0x1f00) | 0x1100;
    *(u32 *)hw = val;
    p = (u16 *)hw;
    p[4] = p[4] & ~3;
    p[0x30] = p[0x30] & (u16)0xcfef;
    p[0x30] = (p[0x30] & ~0x3000) | 8;
    p[0x28] = 0;
    func_02003dfc(0, 0x1f, (s16)0x7fff, 0x3f, 0);

    {
        u16 *hptr = (u16 *)((u8 *)data_02140fc8 - 0x520);
        *(u32 *)data_02140fc8 = 0x4000540;
        hptr[0] = (hptr[0] & (u16)0xcffd) | 2;
        func_02003de4((M2C_UNK)data_02140fc8);
        func_02077a30();
        *(u32 *)0x4000540 = 0;
    }
}

void func_02077eb8(void) {

}

/* Loads and prepares the animation/texture data tables used at startup. */
void func_02077ebc(void) {
    M2C_UNK func_02004b54();
    M2C_UNK func_02004bb0(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_02004cf0();
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02081384(M2C_UNK *, s32);
    M2C_UNK func_02081400(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4(M2C_UNK *);
    M2C_UNK func_02081528();
    M2C_UNK func_0208166c(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_0208168c(M2C_UNK *, s32);
    M2C_UNK *func_020e3218(M2C_UNK *);
    extern M2C_UNK data_02100ad8;
    extern M2C_UNK data_02100ae4;
    extern M2C_UNK data_02100af0;
    extern M2C_UNK data_02100afc;
    extern M2C_UNK data_02100b0c;
    extern M2C_UNK data_02100b1c;
    extern M2C_UNK data_02100b28;
    extern M2C_UNK data_02100b3c;
    extern M2C_UNK data_02100b50;
    extern M2C_UNK data_02100b60;
    extern M2C_UNK data_02100b70;
    extern M2C_UNK data_02100b7c;
    extern M2C_UNK data_02100b88;
    extern M2C_UNK data_02100b94;
    extern M2C_UNK data_02100b9c;
    extern M2C_UNK data_02100ba4;
    extern M2C_UNK data_02144cbc;
    s32 i;
    s32 j;

    func_02004b54();
    i = 0;
    do {
        func_02004bb0(&data_02144cbc, i + 0x329A0, 0x20);
        i += 0x20;
    } while (i < 0xD660);
    j = 0;
    do {
        func_02004bb0(&data_02144cbc, j + 0x30D20, 0x20);
        j += 0x20;
    } while (j < 0x1800);
    func_02004cf0();
    func_0200bc5c(&data_02100ad8);
    func_02081384(&data_02100ae4, 0x24D20);
    func_02081400(&data_02100af0, 0x1200, 0x200);
    func_02081384(func_020e3218(&data_02100afc), 0x20000);
    func_02081400(&data_02100b0c, 0x1400, 0x40);
    func_020814e4(&data_02100b1c);
    func_0208168c(&data_02100b28, 0x22F20);
    func_0208166c(&data_02100b3c, 0x1460, 0x40);
    func_0208168c(&data_02100b50, 0x21000);
    func_0208168c(&data_02100b60, 0x21980);
    func_0208166c(&data_02100b70, 0x1440, 0x20);
    func_0208168c(&data_02100b7c, 0x32520);
    func_0208168c(&data_02100b88, 0x325A0);
    func_0208166c(&data_02100b94, 0x1520, 0x20);
    func_0208168c(&data_02100b9c, 0x327A0);
    func_0208166c(&data_02100ba4, 0x1540, 0x20);
    func_02081528();
}

void func_02078068(void) {
    M2C_UNK func_02007e98(M2C_UNK, void *, M2C_UNK);
    u8 *func_020a32f4(s32);
    s32 func_020a334c(s32);
    s32 func_020d0468(s32, s32, s32);
    extern s32 *gCurrentMap;
    extern u8 data_02141008[];
    u8 *base;
    s32 selected;
    u16 width;
    u16 height;
    u8 *unit;
    u8 kindByte;
    u8 otherByte;
    u16 rowVal;
    s32 idx;
    s32 x;
    s32 y;

    base = (u8 *)*gCurrentMap;
    selected = *(u16 *)(base + 0x52A4);
    width = *(u16 *)(base + 0x5144);
    height = *(u16 *)(base + 0x5146);
    func_02007e98(0, data_02141008, 0x780);
    unit = func_020a32f4(selected);
    if (unit == 0) {
        return;
    }
    if (func_020a334c(selected) != 0) {
        return;
    }
    base = (u8 *)*gCurrentMap;
    kindByte = unit[2];
    otherByte = unit[1];
    rowVal = *(u16 *)(base + 0x3758 + kindByte * 2);
    idx = otherByte + rowVal;
    if (!(base[0x5201 + (idx >> 3)] & (1 << (idx & 7)))) {
        return;
    }
    y = 0;
    while (y < height) {
        x = 0;
        while (x < width) {
            if (func_020d0468(selected, x, y) != -1) {
                data_02141008[x * 0x28 + y] = 1;
            }
            x = x + 1;
        }
        y = y + 1;
    }
}

#pragma optimization_level 2
#pragma opt_strength_reduction off
#pragma opt_common_subs off
void func_02078170(s32 x0, s32 y0, s32 x1, s32 y1) {
    u8 func_020bd118(void);
    s32 func_020774cc(void);
    u8 func_020a4700(s32, s32);
    extern s32 *gCurrentMap;
    extern u8 data_02141f08[];
    extern M2C_UNK data_02140f70;
    u8 *dims;
    u16 width;
    u16 height;
    s32 x;
    u8 flag;
    s32 y;

    dims = (u8 *)*gCurrentMap + 0x120;
    width = M2C_FIELD(dims,u16 *,0x5024);
    height = M2C_FIELD(dims,u16 *,0x5026);
    flag = func_020bd118();
    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 > width - 1) x1 = width - 1;
    if (y1 > height - 1) y1 = height - 1;

    if (func_020774cc()) {
    for (y = y0; y <= y1; y++) {
        for (x = x0; x <= x1; x++) {
            u16 rowVal;
            s32 cell;
            u8 tile;
            u8 cellVal;
            s8 elev;

            rowVal = *(u16 *)((u8 *)*gCurrentMap + 0x3758 + y * 2);
            cell = x + rowVal;
            tile = *((u8 *)*gCurrentMap + 0x1420 + cell);
            elev = (s8)*((u8 *)*gCurrentMap + 0x1e30 + cell);
            cellVal = initialCell02078170(elev);
            elev = *(s8 *)((u8 *)*gCurrentMap + 0x1e30 + cellIndex02078170(x,y));
            if (elev >= 0x40) cellVal = 3;

            if ((tile & 0x1F) == 0x1D &&
                *(s32 *)(((u8 *)&data_02140f70) + 0xC) != 0 &&
                func_020a4700(x, y) != 0) {
                cellVal = 1;
            }

            if (flag) {
                if (*(s16 *)((u8 *)*gCurrentMap + 0x52C2) == x &&
                    *(s16 *)((u8 *)*gCurrentMap + 0x52C4) == y) {
                    cellVal = 1;
                }
            }

            (data_02141f08+x * 0x28)[y] = cellVal;
        }
    }
    } else {
    for (y = y0; y <= y1; y++) {
            for (x = x0; x <= x1; x++) {
                (data_02141f08+x * 0x28)[y] = 0;
            }
        }
    }
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
#pragma optimization_level reset
void func_02078340(s32 x0, s32 y0, s32 x1, s32 y1) {
    extern s32 *data_027e0058;
    extern u8 data_02141008[];
    extern u8 data_02141788[];
    extern u32 data_027e15bc;
    extern const u8 data_020eb1f0[32];
    u8 pal[32];
    u8 *base;
    u8 *sub;
    s32 w;
    s32 h;
    s32 x;
    s32 y;
    s32 i;
    u8 c;

    base = *(u8 **)data_027e0058;
    sub = base + 0x120;
    w = M2C_FIELD(sub, u16 *, 0x5024);
    h = M2C_FIELD(sub, u16 *, 0x5026);
    if (x0 < 0) {
        x0 = 0;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (x1 > w - 1) {
        x1 = w - 1;
    }
    if (y1 > h - 1) {
        y1 = h - 1;
    }
    for (y = y0; y <= y1; y++) {
        for (x = x0; x <= x1; x++) {
            c = 0;
            if (M2C_FIELD(y, u8 *, (s32)&data_02141008 + x * 0x28) != 0) {
                for (i = 0; i < 0x20; i += 2) {
                    pal[i] = data_020eb1f0[i];
                    pal[i + 1] = data_020eb1f0[i + 1];
                }
                c = pal[(data_027e15bc >> 2) & 0x1F];
            }
            M2C_FIELD(y, u8 *, (s32)&data_02141788 + x * 0x28) = c;
        }
    }
}

#pragma opt_strength_reduction off
void func_0207843c(s32 x0,s32 y0,s32 x1,s32 y1){
s32 func_0207e52c(s32,s32);s32 func_0207ef5c(s32,s32,u16);
extern s32 *gCurrentMap;extern u8 data_02142ebc[3840],data_02143dbc[3840];
u8 *base=*(u8**)gCurrentMap;u8 *sub=base+0x120;s32 off;u16 *p; s32 a,x,y,w,h,b;u16 *q;
w=M2C_FIELD(sub,u16*,0x5024);h=M2C_FIELD(sub,u16*,0x5026);
if(x0<0)x0=0;if(y0<0)y0=0;if(x1>w-1)x1=w-1;if(y1>h-1)y1=h-1;
p=(u16*)data_02142ebc;q=(u16*)data_02143dbc;y=y0;goto outercheck;outer: x=x0;off=y*2;goto innercheck;inner:
a=func_0207e52c(x,y);b=func_0207ef5c(x,y,(u16)a);
M2C_FIELD((u8*)p+x*80,u16*,off)=a;
M2C_FIELD(data_02143dbc,u16*,x*80+y*2)=b;
x++;innercheck:if(x<=x1)goto inner;
y++;outercheck:if(y<=y1)goto outer;
}
#pragma opt_strength_reduction on
void func_02078528(void) {
unsigned long long func_020722fc(unsigned long, unsigned long);
extern u8 data_020ebd78[32],data_020ebd58[32];extern u32 data_027e15bc;extern M2C_UNK data_02140f70;
s32 sum,idx,accum;u8 *p;s32 i;unsigned long long res;s32 rem;
sum=0;accum=0;idx=0;i=0;p=data_020ebd78;
do{sum+=*p++;i++;}while(i<30);
res=func_020722fc(data_027e15bc,sum);rem=res>>32;
{u8 *q=data_020ebd78;s32 j=0;
do{accum+=*q;if(accum>rem){idx=j;break;}j++;q++;}while(j<30);}
*(u8*)&data_02140f70=data_020ebd58[idx];
}

