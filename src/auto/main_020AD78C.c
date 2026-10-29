/* 29 functions from 0x020AD78C to 0x020AE768 (main), found by ds-decomp. */
#include "common.h"

void func_020ad78c(void) {
    void func_020ad67c(void);
    s32 func_020ad690(void);
    s32 func_020ad6b0(void);
    s32 func_020ad6d0(void);
    void func_01ff9ce8(u8);
    void func_02068c50(void *, void *);
    void func_02068d68(void *, void *);
    M2C_UNK func_020e3218(M2C_UNK);
    u8 func_020814e4(M2C_UNK);
    void func_020815fc(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02081590(void *, void *);
    void func_020816cc(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_02081528(void);

    extern s32 data_0215c428;
    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c4;
    typedef struct { void *p; s32 pad; } E8;
    extern E8 data_02127c08[];
    extern char data_02127d8c[];
    extern char data_02127d94[];
    extern char data_02127d98[];
    extern char data_02127d9c[];

    register u16 **saved asm("r4");
    char sp[0x40];
    register s32 idx asm("r3");
    register M2C_UNK h asm("r5");

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_020ad67c();
    func_01ff9ce8((u8)func_020ad690());

    idx = ((s16 *)data_0215c428)[1];
    func_02068c50((void *)sp, data_02127c08[idx].p);
    func_02068d68((void *)sp, data_02127d8c);

    func_020814e4(func_020e3218((M2C_UNK)sp));

    idx = ((s16 *)data_0215c428)[1];
    func_02068c50((void *)sp, data_02127c08[idx].p);
    func_02068d68((void *)sp, data_02127d94);

    if (func_020ad690() == 0) {
        func_020815fc(func_020e3218((M2C_UNK)sp), 0, 0x100);
    } else {
        func_020815fc(func_020e3218((M2C_UNK)sp), 0x100, 0x100);
    }

    idx = ((s16 *)data_0215c428)[1];
    func_02068c50((void *)sp, data_02127c08[idx].p);
    func_02068d68((void *)sp, data_02127d98);

    h = func_020e3218((M2C_UNK)sp);
    func_02081590(h, (void *)((char *)0 + func_020ad6b0() + 0x20));

    idx = ((s16 *)data_0215c428)[1];
    func_02068c50((void *)sp, data_02127c08[idx].p);
    func_02068d68((void *)sp, data_02127d9c);

    if (func_020ad690() == 0) {
        h = func_020e3218((M2C_UNK)sp);
        func_020816cc(h, func_020ad6d0(), 1, 0);
        ((u8 *)*gCur3DSpriteEngine)[0x46] |= 0x1;
    } else {
        h = func_020e3218((M2C_UNK)sp);
        func_020816cc(h, func_020ad6d0(), 1, 8);
        ((u8 *)*gCur3DSpriteEngine)[0x46] |= 0x2;
    }

    func_02081528();
    gCur3DSpriteEngine = saved;
}

void func_020ad968(void) {
    M2C_UNK func_020822b8(u16 *);
    typedef struct { u16 a, b, c, d, e, f; } T;
    extern T data_020f4d1c;
    T sp0;

    sp0 = data_020f4d1c;
    func_020822b8((u16 *) &sp0);
}

void func_020ad9b8(M2C_UNK a0) {
    void func_020ad968(void);
    void func_020ad67c(void);
    s32 func_020ad690(void);
    void func_01ff9ce8(u8);
    void func_020ad78c(void);
    M2C_UNK func_020e3218(M2C_UNK);
    M2C_UNK func_02080cfc(M2C_UNK, M2C_UNK);
    M2C_UNK func_0208116c(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_020ad6f0(void);
    void func_020ae028(s32);
    M2C_UNK func_020e34bc(M2C_UNK);
    M2C_UNK func_02007f8c(M2C_UNK, M2C_UNK, M2C_UNK);

    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c4;
    extern s32 data_0215c428;
    extern char data_02127da0[];
    extern char data_02127dac[];

    u16 **saved;

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_020ad968();

    **gCur3DSpriteEngine |= 0x10;
    **gCur3DSpriteEngine |= 0x20;
    **gCur3DSpriteEngine &= ~0x40;
    **gCur3DSpriteEngine &= ~0x80;
    **gCur3DSpriteEngine |= 0x100;

    (*gCur3DSpriteEngine)[3] &= ~3;
    (*gCur3DSpriteEngine)[4] = ((*gCur3DSpriteEngine)[4] & ~3) | 1;
    (*gCur3DSpriteEngine)[5] = ((*gCur3DSpriteEngine)[5] & ~3) | 2;
    (*gCur3DSpriteEngine)[6] = ((*gCur3DSpriteEngine)[6] & ~3) | 3;

    (*gCur3DSpriteEngine)[28] = 0;
    (*gCur3DSpriteEngine)[32] = 0;
    (*gCur3DSpriteEngine)[29] = 0;
    (*gCur3DSpriteEngine)[33] = 0;

    (*gCur3DSpriteEngine)[9] &= ~0xc0;

    ((u8 *)*gCur3DSpriteEngine)[0x51] = 0;
    ((u8 *)*gCur3DSpriteEngine)[0x52] = 0;
    ((u8 *)*gCur3DSpriteEngine)[0x53] = 0;

    data_0215c428 = (s32)func_020e34bc(0xc);
    func_02007f8c((M2C_UNK)data_0215c428, 0, 0xc);

    *(s16 *)((char *)data_0215c428 + 2) = (s16)M2C_FIELD(a0, s32 *, 0x5c);
    *(s16 *)((char *)data_0215c428 + 4) = 0;
    *(s16 *)((char *)data_0215c428 + 10) = 0;
    *(s16 *)((char *)data_0215c428 + 8) = 20;
    *(s16 *)((char *)data_0215c428 + 6) = *(s16 *)((char *)data_0215c428 + 8);

    func_020ad67c();
    func_01ff9ce8((u8)func_020ad690());
    func_020ad78c();

    func_02080cfc(func_020e3218((M2C_UNK)data_02127da0),
        (M2C_UNK)(*(u32 *)((u8 *)data_027e00c4 + 0x1c) + 0x2800));
    func_0208116c((M2C_UNK)data_02127dac, 0x2c0, 0x20);

    func_020ad6f0();
    func_020ae028(1);

    gCur3DSpriteEngine = saved;
}

void func_020adc20(void) {
    M2C_UNK func_020e35cc();
    extern s32 data_0215c428;
    if (data_0215c428 == 0) {
        return;
    }
    func_020e35cc();
    data_0215c428 = 0;
}

u8 func_020adc4c(void) {
    s32 func_020d46e8();
    s32 func_020d4ea8();
    u8 var_r0;

    if (func_020d46e8() != 0) {
        return 0U;
    }
    if (func_020d4ea8() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Swaps in the primary display list, emits four corner sprites whose tile depends on the
   current list's mode bits, then restores the previous display list. */
void func_020adc78(void) {
    M2C_UNK func_01ffaacc(M2C_UNK, M2C_UNK, u16, M2C_UNK *, s32);
    extern M2C_UNK data_02101f0c;
    extern u16 **data_027e00c4;
    extern u16 **gCur3DSpriteEngine;
    u16 **saved_list;

    saved_list = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    if (func_020adc4c() != 0) {
        func_01ffaacc(0x7C, 0xB0, (u16) ((0x3FF & (0x140 >> ((u32) (**gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x6000), &data_02101f0c, 0);
        func_01ffaacc(0xBC, 0xB0, (u16) ((0x3FF & (0x148 >> ((u32) (**gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x6000), &data_02101f0c, 0);
        func_01ffaacc(0x7C, 0xB8, (u16) ((0x3FF & (0x150 >> ((u32) (**gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x6000), &data_02101f0c, 0);
        func_01ffaacc(0xBC, 0xB8, (u16) ((0x3FF & (0x158 >> ((u32) (**gCur3DSpriteEngine << 0x11) >> 0x1E))) | 0x6000), &data_02101f0c, 0);
    }
    gCur3DSpriteEngine = saved_list;
}

void func_020adde0(void) {
    u8 func_0207b7c4(void);
    void func_020d8f1c(s16, s32);
    s32 func_020ad690(void);
    void func_020ad74c(void);
    s32 func_0207ca38(s32, s32, s32, s32, s32);
    void func_020ad6f0(void);

    extern s32 data_0215c428;
    extern u16 **gCur3DSpriteEngine;
    extern u16 **data_027e00c4;

    s16 *p = (s16 *)data_0215c428;
    u16 **saved;
    s16 v;
    s32 idx;
    u16 *eng;
    u16 *slotbase;
    s16 sparg;
    s32 res;

    if (p[0] & 4) {
        if (func_0207b7c4() != 0) {
            return;
        }
        func_020d8f1c(1, 0);
        return;
    }

    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;

    if (p[3] == 0) {
        func_020ad74c();
    } else if (p[3] == 1) {
        if (func_020ad690() == 0) {
            u16 *q = *gCur3DSpriteEngine;
            q[3] &= ~3;
            q[4] = (q[4] & ~3) | 1;
            q[5] = (q[5] & ~3) | 2;
            q[6] = (q[6] & ~3) | 3;
        } else {
            u16 *q = *gCur3DSpriteEngine;
            q[3] = (q[3] & ~3) | 1;
            q[4] &= ~3;
            q[5] = (q[5] & ~3) | 2;
            q[6] = (q[6] & ~3) | 3;
        }
    } else {
        if (p[3] == p[4]) {
            func_020ad6f0();
        }
    }

    v = p[5];
    idx = func_020ad690();
    eng = *gCur3DSpriteEngine;
    eng[28 + idx] = v;

    slotbase = *gCur3DSpriteEngine;
    *((u16 *)((char *)slotbase + 0x40 + (idx << 1))) = 0;

    sparg = p[4];
    res = func_0207ca38(4, 0x100, 0, p[3], sparg);

    p[5] = res;
    p[3] = p[3] + 1;
    if (p[3] >= p[4]) {
        p[3] = p[4];
    }

    gCur3DSpriteEngine = saved;
}

s32 func_020adfd0(void) {
 s32 func_01ffa770(M2C_UNK *);
 extern M2C_UNK data_02127bc8;
 u8 var_r0;
 if(func_01ffa770(&data_02127bc8)!=0) var_r0=1; else var_r0=0;
 return var_r0;
}

s32 func_020adff4(void) {
 extern s32 data_0215c428;
 if(func_020adfd0()==0) return 0;
 if(data_0215c428==0) return 0;
 return *(s16 *)data_0215c428 & 2;
}

void func_020ae028(s32 arg0) {
 extern s32 data_0215c428;
 s16 temp_r0;
 if(func_020adfd0()!=0 && data_0215c428!=0) {
 temp_r0=*(s16 *)data_0215c428;
 if(arg0!=0) { *(s16 *)data_0215c428=temp_r0|2; return; }
 *(s16 *)data_0215c428=temp_r0 & ~2;
 }
}

s32 func_020ae068(void) {
 extern s32 data_0215c428;
 if(func_020adfd0()==0) return 0;
 if(data_0215c428==0) return 0;
 *(s16 *)data_0215c428 |=4;
 return 1;
}

s32 func_020ae0a8(void) {
    extern s32 data_0215c428;
    if (func_020adfd0() == 0) return -1;
    if (data_0215c428 == 0) return -1;
    return *(s16 *)(data_0215c428 + 2);
}

void func_020ae0d8(s32 arg0, s32 arg1) {
    M2C_UNK func_020ad70c();
    M2C_UNK func_020d8ce8(s32);
    M2C_UNK func_0208fe30(s32);
    extern s32 data_0215c428;
    func_020ad70c();
    *(s16 *)(data_0215c428 + 6) = 0;
    *(s16 *)(data_0215c428 + 8) = arg1;
    *(s16 *)(data_0215c428 + 2) = arg0;
    func_020d8ce8(arg0);
    func_0208fe30(0x10021);
}

void func_020ae124(s32 arg0) {
    s32 func_020ad728();
    void func_020ae0d8(s32, s32);
    extern s32 data_0215c428;
    if (func_020adfd0() != 0 && data_0215c428 != 0) {
        if (func_020ad728() == 0) return;
        func_020ae0d8(arg0, 0x14);
    }
}

void func_020ae164(s32 arg0) {
s32 func_020ad728();
extern s32 data_0215c428;
if(func_020adfd0()!=0 && data_0215c428!=0) {
if(func_020ad728()==0)return;
func_020ae0d8(arg0,14);
}
}

u8 func_020ae1a4(void) {
s32 func_020ad728();
extern s32 data_0215c428;
u8 result;
if(!func_020adfd0())return 0;
if(!data_0215c428)return 0;
if(func_020ad728()!=0)result=1;else result=0;
return result;
}

void func_020ae1e8(s32 arg0) {
void *func_01ffa3dc(void *,s32);
extern M2C_UNK data_02127bc8;
void *p=func_01ffa3dc(&data_02127bc8,7);
if(p)M2C_FIELD(p,s32 *,0x5c)=arg0;
}

void func_020ae20c(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    s32 func_020adfd0();
    extern M2C_UNK data_02127bc8;
    if (func_020adfd0() == 0) {
        return;
    }
    func_01ffa9e4(&data_02127bc8);
}

s32 func_020ae22c(u32 arg0) {
    switch (arg0) {
    case 0:
        return 0;
    case 1:
        return 0x7FFF;
    case 2:
        return 0x1F;
    case 3:
        return 0x3E0;
    case 4:
        return 0x7C00;
    case 5:
        return 0x3FF;
    case 6:
        return 0x7C1F;
    case 7:
        return 0x7FE0;
    case 8:
        return 0x4210;
    case 9:
        return 0x63E0;
    case 10:
        return 0;
    case 11:
        return 0x211F;
    case 12:
        return 0x63E0;
    case 13:
        return 0x3D8A;
    case 14:
        return 0x2108;
    case 15:
        return 0x7E10;
    case 16:
        return 0x43FF;
    case 17:
        return 0x7FE0;
    case 18:
        return 0x421F;
    }
    return 0;
}

u16 func_020ae354(u32 arg0,u32 arg1,u32 arg2,u32 arg3) {
u32 g1=(arg1&0x3e0)>>5;
u32 r1=arg1&31;
u32 b1=(arg1&0x7c00)>>10;
u32 g0=(arg0&0x3e0)>>5;
u32 r0=arg0&31;
u32 b0=(arg0&0x7c00)>>10;
u16 g=(g0*arg2+g1*arg3)>>4;
u16 r=(r0*arg2+r1*arg3)>>4;
u16 b=(b0*arg2+b1*arg3)>>4;
return (r&31)|((g&31)<<5)|((b&31)<<10);
}

u16 func_020ae3e0(s32 a,s32 b,s32 x,s32 y) {
u32 bg=(b&0x3e0)>>5;
u32 br=b&31;
u32 bb=(b&0x7c00)>>10;
u32 ag=(a&0x3e0)>>5;
u32 ar=a&31;
u32 ab=(a&0x7c00)>>10;
u16 g=(ag*x+bg*y)>>5;
u16 r=(ar*x+br*y)>>5;
u16 bl=(ab*x+bb*y)>>5;
return (r&31)|((g&31)<<5)|((bl&31)<<10);
}

void func_020ae46c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    void func_020ae548(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_020ae548(arg0, arg1, arg2, arg3, 0x20);
}

void func_020ae480(u16 *p,s32 a,s32 b,s32 c) {
s16 r,g,bl; s32 i=0;u16 v;;
do {
v=*p;i++;
r=(v&31)+a;
g=b+((s32)(v&0x3e0)>>5);
if(r<0)r=0;
bl=c+((s32)(v&0x7c00)>>10);
if(g<0)g=0;if(bl<0)bl=0;
if(r>31)r=31;if(g>31)g=31;if(bl>31)bl=31;
*p++=(r&31)|((u32)(g<<27)>>22)|((u32)(bl<<27)>>17);
}while(i<16);
}

void func_020ae528(M2C_UNK arg0) {
    void func_020ae548(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_020ae548(arg0, 0, 8, 8, 0x20);
}

void func_020ae548(s32 arg0,s32 a,s32 b,s32 c,s32 n) {s32 i;u16 *p;n/=2;p=(u16 *)arg0;i=0;if(n>0)for(;i<n;i++){*p=func_020ae354(*p,a,b,c);p++;}}

u16 func_020ae5a0(u16 a) {
u16 r=a&31,g=(a&0x3e0)>>5,b=(a&0x7c00)>>10;
u16 v=(r*299+g*587+b*114)/1000;
r=v*255/255; g=v*200/255; b=v*150/255;
return (r&31)|((g&31)<<5)|((b&31)<<10);
}

void func_020ae67c(u16 *arg0, s32 arg1) {
    u16 func_020ae5a0(u16);
    s32 i;
    u16 *ptr;
    arg1 /= 2;
    ptr = arg0;
    i = 0;
    if (arg1 > 0) {
        for (; i < arg1; i++) {
            *ptr = func_020ae5a0(*ptr);
            ptr++;
        }
    }
}

u16 func_020ae6bc(u16 a) {
u16 r=a&31,g=(a&0x3e0)>>5,b=(a&0x7c00)>>10;
u16 v=(r*299+g*587+b*114)/1000;
s32 c=v&31;
return c|(c<<5)|(c<<10);
}

void func_020ae728(u16 *arg0, s32 arg1) {
    u16 func_020ae6bc(u16);
    s32 i;
    u16 *ptr;
    arg1 /= 2;
    ptr = arg0;
    i = 0;
    if (arg1 > 0) {
        for (; i < arg1; i++) {
            *ptr = func_020ae6bc(*ptr);
            ptr++;
        }
    }
}

