/* 18 functions from 0x020DE264 to 0x020DF1D0 (main), found by ds-decomp. */
#include "common.h"
typedef struct SetupSprite {
 u8 pad[0x40];
 unsigned field0:18;
 unsigned frame:8;
 unsigned field26:6;
} SetupSprite;
static inline s32 GetSetupCode(void *p) {
    s32 result=-1;
    switch(M2C_FIELD(p,s32 *,0x34)) {
    case 0:
        switch(M2C_FIELD(p,s32 *,0x38)) {case 1: result=2; break; default: result=4; break;}
        break;
    case 1: case 2: result=2; break;
    }
    return result;
}

#pragma opt_strength_reduction off
M2C_UNK func_020de264(M2C_UNK arg0, M2C_UNK arg1) {
    void func_01ff9ce8(u8);
    void func_0200bc5c(void *);
    void *func_020e3218(void *);
    void func_020814e4(void *);
    void func_02081590(void *, void *);
    void func_02081528(void);
    void func_02080944(void *, s32, s32, s32);
    void func_0208e7ec(s32, s32);
    void func_02088f1c(void *);
    void func_02088da8(void *);
    void func_0208b758(void *, u32);
    s32 func_020a8ff4(void *);
    void func_ov010_02228d48(s32, s32, s32, s32, s32, s32, s32);
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c8;
    extern void *data_027e00c4;
    extern M2C_UNK data_0212d428;
    extern M2C_UNK data_0212d430;
    extern M2C_UNK data_0212d440;
    extern M2C_UNK data_0212d450;
    s32 func_020de50c(s32, void *);
    s32 func_020de5b0(M2C_UNK);
    void func_020de610(void);

    void *old = gCur3DSpriteEngine;
    s32 code;
    s32 code2;
    void *p;
    u8 low;
    u32 val;
    s32 t;
    s32 v3c;
    s32 v34;
    s32 v38;
    s32 tmp;

    gCur3DSpriteEngine = data_027e00c8;
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x2;
    func_0200bc5c(&data_0212d428);
    func_020814e4(func_020e3218(&data_0212d430));

    v34 = M2C_FIELD((void *)arg0, s32 *, 0x34);
    code = -1;
    if (v34 != 0) {
        if (v34 == 1) code = 2;
        if (v34 == 2) code = 2;
    } else {
        v38 = M2C_FIELD((void *)arg0, s32 *, 0x38);
        if (v38 == 1) code = 2; else code = 4;
    }

    if (code == 2) {
        func_02081590(func_020e3218(&data_0212d450), M2C_FIELD(gCur3DSpriteEngine, void **, 0x20));
    } else if (code == 4) {
        func_02081590(func_020e3218(&data_0212d440), M2C_FIELD(gCur3DSpriteEngine, void **, 0x20));
    }

    func_02081528();
    func_02080944(M2C_FIELD(gCur3DSpriteEngine, void **, 0x20), 0x20, 0x18, 0x5);

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x1;
    gCur3DSpriteEngine = data_027e00c4;
    func_0208e7ec(0x3c00, 0x7);

    gCur3DSpriteEngine = old;

    M2C_FIELD((void *)arg0, u16 *, 0x48) |= 0x20;

    p = M2C_FIELD((void *)arg0, void **, 0x54);
    low = M2C_FIELD(p, u8 *, 0x59);
    low = (u8)((low << 28) >> 28);
    val = M2C_FIELD(p, u32 *, 0x40);
    val &= ~0x03FC0000u;
    val |= ((u32)(low + 2)) << 18;
    M2C_FIELD(p, u32 *, 0x40) = val;
    M2C_FIELD(p, u8 *, 0x5a) = 0;

    func_02088f1c(M2C_FIELD((void *)arg0, void **, 0x58));
    func_02088da8(M2C_FIELD((void *)arg0, void **, 0x60));
    func_0208b758(M2C_FIELD((void *)arg0, void **, 0x64), 0x44000011U);
    func_02088f1c(M2C_FIELD((void *)arg0, void **, 0x64));

    p = M2C_FIELD((void *)arg0, void **, 0x68);
    if (func_020a8ff4(p) != 0) {
        t = func_020a8ff4(p);
        M2C_FIELD(p, u16 *, 0xe) = (u16)t;
        M2C_FIELD(p, u16 *, 0x10) = 0;
        M2C_FIELD(p, u16 *, 0xc) = 0xc;
        M2C_FIELD(p, u16 *, 0x2) = M2C_FIELD(p, u16 *, 0x4);
        M2C_FIELD((void *)arg0, u16 *, 0x48) &= ~0x100;
        M2C_FIELD((void *)arg0, u16 *, 0x48) &= ~0x200;
    }

    v3c = M2C_FIELD((void *)arg0, s32 *, 0x3c);
    if (v3c == 0) {
        M2C_FIELD((void *)arg0, u16 *, 0x4a) = 0xa;
    } else if (v3c == 1) {
        M2C_FIELD((void *)arg0, u16 *, 0x4a) = 0xa;
        func_020de5b0;
    }

    M2C_FIELD((void *)arg0, u8 *, 0x41) = 0;
    M2C_FIELD((void *)arg0, u16 *, 0x4c) = 0x708;

    v34 = M2C_FIELD((void *)arg0, s32 *, 0x34);
    code2 = -1;
    if (v34 != 0) {
        if (v34 == 1) code2 = 2;
        if (v34 == 2) code2 = 2;
        tmp = v34;
    } else {
        v38 = M2C_FIELD((void *)arg0, s32 *, 0x38);
        if (v38 == 1) code2 = 2; else code2 = 4;
        tmp = v38;
    }

    v3c = M2C_FIELD((void *)arg0, s32 *, 0x3c);
    func_ov010_02228d48((s32)arg1, code2, (s32)func_020de610, (s32)arg0, tmp, (s32)arg0, v3c);
}

s32 func_020de50c(s32 arg0, void *arg1) {
s32 func_0203c0b0(s32,s32 *,s32); void *func_ov010_02229b00(void); extern M2C_UNK data_0212c5d8;
s32 saved,a,n,v; register s32 d; s32 t; void *p;
p=func_ov010_02229b00();
if(!(M2C_FIELD(p,u8 *,0x1a)&2)) return -1;
saved=M2C_FIELD(p,s32 *,0x20);
d=(saved>>12)-(func_0203c0b0(arg0,&data_0212c5d8,0x5dc000)>>12);
if(d<0) a=-d; else a=d;
t=M2C_FIELD(arg1,u16 *,0x4a);
if(t<a) {n=t+20; if(n>=50000)n=50000; M2C_FIELD(arg1,u16 *,0x4a)=n;return -1;}
if(d<0)n=-d; else n=d;
v=0x7fffff-n;
if(v>0x7fffff)v=0x7fffff;
else if(v<0)v=0;
return v;
}

s32 func_020de5b0(register M2C_UNK arg0) {
    M2C_UNK func_0203c0b0(M2C_UNK, M2C_UNK *, s32);
    void *func_ov010_02229b00();
    extern M2C_UNK data_0212c5e0;
    extern M2C_UNK data_0212c5d0;
    if (!(M2C_FIELD(func_ov010_02229b00(), u8 *, 0x1A) & 2)) {
        return -1;
    }
    if (func_0203c0b0(arg0, &data_0212c5e0, 1) != 1) {
        return -1;
    }
    func_0203c0b0(arg0, &data_0212c5d0, 0x5DC000);
    return 0x7FFFFF;
}

void func_020de610(void) {

}

M2C_UNK func_020de614(M2C_UNK a0, M2C_UNK a1) { return 0; }

void func_020de868(s32 arg0, s32 arg1, void *arg2) {
    if (arg0 != 0) {
        return;
    }
    if (arg1 != 0) {
        M2C_FIELD(arg2, u16 *, 0x48) = (u16) (M2C_FIELD(arg2, u16 *, 0x48) | 0x100);
    }
}

s32 func_020de884(M2C_UNK arg0) {
    M2C_UNK func_0203c0b0(M2C_UNK, M2C_UNK *, s32);
    void *func_ov010_02229b00();
    extern M2C_UNK data_0212c5c8;
    if (!(M2C_FIELD(func_ov010_02229b00(), u8 *, 0x1A) & 2)) {
        return -1;
    }
    func_0203c0b0(arg0, &data_0212c5c8, 0x5DC000);
    return 0x7FFFFF;
}

#pragma opt_strength_reduction on
void func_020de8c4(M2C_UNK arg0, M2C_UNK arg1) {
    void func_01ff9ce8(u8);
    void func_0200bc5c(void *);
    void *func_020e3218(void *);
    void func_020814e4(void *);
    void func_02081590(void *, void *);
    void func_02081528(void);
    void func_02080944(void *, s32, s32, s32);
    void func_0208e7ec(s32, s32);
    void func_02088f1c(void *);
    void func_02088da8(void *);
    void func_0208b758(void *, u32);
    s32 func_020a8ff4(void *);
    void func_ov010_02228d48(s32, s32, s32, s32, s32, s32, s32);
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c8;
    extern void *data_027e00c4;
    extern M2C_UNK data_0212d498;
    extern M2C_UNK data_0212d4a0;
    extern M2C_UNK data_0212d4b0;
    extern M2C_UNK data_0212d4c0;
    s32 func_020de50c(s32, void *);
    s32 func_020de5b0(M2C_UNK);
    void func_020de610(void);

    void func_ov010_02229190(s32,s32,s32,s32,s32,s32);
    void func_ov010_022292e4(s32,s32,s32,s32,s32,s32);
    void func_020deb44(s32,s32,s32,s32,s32,void *);
    extern s32 data_02168f7c[];
    void *old = gCur3DSpriteEngine;
    s32 code;
    s32 code2;
    void *p;
    s32 low;
    u32 val;
    s32 t;
    s32 v3c;
    s32 v34;
    s32 v38;
    s32 tmp;

    gCur3DSpriteEngine = data_027e00c8;
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x2;
    func_0200bc5c(&data_0212d498);
    func_020814e4(func_020e3218(&data_0212d4a0));

    code=GetSetupCode((void *)arg0);
    switch(code) {
    case 4: func_02081590(func_020e3218(&data_0212d4b0), M2C_FIELD(gCur3DSpriteEngine,void **,0x20)); break;
    case 2: func_02081590(func_020e3218(&data_0212d4c0), M2C_FIELD(gCur3DSpriteEngine,void **,0x20)); break;
    }

    func_02081528();
    func_02080944(M2C_FIELD(gCur3DSpriteEngine, void **, 0x20), 0x20, 0x18, 0x5);

    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x1;

    gCur3DSpriteEngine = old;

    M2C_FIELD((void *)arg0, u16 *, 0x48) |= 0x20;

    p = M2C_FIELD((void *)arg0, void **, 0x54);
    low = M2C_FIELD(p, u8 *, 0x59);
    low = (s32)((u32)(low << 28) >> 28);
    val = M2C_FIELD(p, u32 *, 0x40);
    val &= ~0x03FC0000u;
    val |= ((u32)(u16)(low + 2) << 24) >> 6;
    M2C_FIELD(p, u32 *, 0x40) = val;
    M2C_FIELD(p, u8 *, 0x5a) = 0;

    func_02088f1c(M2C_FIELD((void *)arg0, void **, 0x58));
    func_02088da8(M2C_FIELD((void *)arg0, void **, 0x60));
    func_0208b758(M2C_FIELD((void *)arg0, void **, 0x64), 0x44000011U);
    func_02088f1c(M2C_FIELD((void *)arg0, void **, 0x64));

    if (func_020a8ff4(M2C_FIELD((void *)arg0, void **, 0x68)) != 0) {
        t = func_020a8ff4(M2C_FIELD((void *)arg0, void **, 0x68));
        p = M2C_FIELD((void *)arg0, void **, 0x68);
        M2C_FIELD(p, u16 *, 0xe) = (u16)t;
        M2C_FIELD(p, u16 *, 0xc) = 0xc;
        M2C_FIELD(p, u16 *, 0x10) = 0;
        M2C_FIELD(p, u16 *, 0x2) = M2C_FIELD(p, u16 *, 0x4);
    }
    M2C_FIELD((void *)arg0, s16 *, 0x48) &= ~0x100;
    M2C_FIELD((void *)arg0, s16 *, 0x48) &= ~0x200;

    M2C_FIELD((void *)arg0, u8 *, 0x41) = 0;
    if(M2C_FIELD((void *)arg0,u16 *,0x48)&1) {
    code2=GetSetupCode((void *)arg0);
    func_ov010_02229190(arg1,code2,(s32)func_020deb44,arg0,0,0);
    } else {
    func_ov010_022292e4(arg1,data_02168f7c[M2C_FIELD((void *)arg0,s8 *,0x43)],(s32)func_020deb44,arg0,0,0);
    }
}
#pragma opt_strength_reduction off
void func_020deb44(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,void *arg5) { register u16 *p=(u16 *)((u8 *)arg5+0x48); if(arg0!=0)return; if(arg1==0)return; if(arg2!=0)return; if(arg3!=0)*p|=0x100; }

void func_020deb74(M2C_UNK arg0) {
    M2C_UNK func_020ddfd8(M2C_UNK, M2C_UNK);
    func_020ddfd8(arg0, 0);
}

void func_020deb84(M2C_UNK arg0) {
    M2C_UNK func_020ddfd8(M2C_UNK, M2C_UNK);
    func_020ddfd8(arg0, 1);
}

void func_020deb94(M2C_UNK arg0) {
    M2C_UNK func_020de264(M2C_UNK, M2C_UNK);
    func_020de264(arg0, 0);
}

void func_020deba4(M2C_UNK arg0) {
    M2C_UNK func_020de264(M2C_UNK, M2C_UNK);
    func_020de264(arg0, 1);
}

void func_020debb4(M2C_UNK arg0) {
    M2C_UNK func_020de614(M2C_UNK, M2C_UNK);
    func_020de614(arg0, 0);
}

void func_020debc4(M2C_UNK arg0) {
    M2C_UNK func_020de614(M2C_UNK, M2C_UNK);
    func_020de614(arg0, 1);
}

void func_020debd4(M2C_UNK arg0) {
    void func_020de8c4(M2C_UNK, M2C_UNK);
    func_020de8c4(arg0, 0);
}

void func_020debe4(M2C_UNK arg0) {
    void func_020de8c4(M2C_UNK, M2C_UNK);
    func_020de8c4(arg0, 1);
}

void func_020debf4() {
    return;
}

