/* 31 functions from 0x02096C7C to 0x02097C50 (main), found by ds-decomp. */
#include "common.h"

void func_02096c7c(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_020c9b70();
    M2C_UNK func_020c9ebc(s32, M2C_UNK);
    s32 func_020d1938(s32);
    s32 func_020d273c(s32, s32);
    extern s32 *gCurrentMap;
    s32 temp_r2;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    void *temp_r3;

    var_r6 = 0x8C;
    var_r5 = 1;
    var_r7 = arg0 * 0x8C;
    do {
        if ((func_020d1938(var_r5) != 0) && (func_020d273c(arg0, var_r5) == 0)) {
            temp_r2 = *gCurrentMap;
            temp_r3 = var_r7 + temp_r2;
            M2C_FIELD(temp_r3, u16 *, 0x67C6) = (u16) (M2C_FIELD(temp_r3, u16 *, 0x67C6) + M2C_FIELD((temp_r2 + var_r6), u8 *, 0x67D5));
            func_020c9ebc(var_r5, arg1);
        }
        var_r5 += 1;
        var_r6 += 0x8C;
    } while (var_r5 < 5);
    func_020c9b70();
}

void func_02096d0c(void) {
    M2C_UNK func_020822b8(u16 *);
    typedef struct { u16 a, b, c, d, e, f; } T;
    extern T data_020f3644;
    T sp0;

    sp0 = data_020f3644;
    func_020822b8((u16 *) &sp0);
}

void func_02096d5c(void) {
    M2C_UNK func_020026d8(M2C_UNK);
    M2C_UNK func_02002968(M2C_UNK);
    M2C_UNK func_02002ab8(M2C_UNK);
    M2C_UNK func_02003124(M2C_UNK);
    M2C_UNK func_020031cc(M2C_UNK);
    M2C_UNK func_0200323c(M2C_UNK);
    M2C_UNK func_020032bc(M2C_UNK);
    M2C_UNK func_02082c84();
    func_02082c84();
    func_020026d8(1);
    func_02002968(2);
    func_02003124(4);
    func_020031cc(8);
    func_02002ab8(0x10);
    func_02002bb8(0x20);
    func_0200323c(0x80);
    func_020032bc(0x100);
}

void func_02096da8(void) {
    M2C_UNK func_02002bb8(M2C_UNK);
    M2C_UNK func_020b1800();
    func_020b1800();
    func_02002bb8(0x40);
}

void func_02096dbc(void) {
    M2C_UNK func_020b17ec();
    func_020b17ec();
}

void func_02096dc8(void) {
    void func_02096d5c(void);
    void func_02096d0c(void);
    M2C_UNK func_020aca8c(M2C_UNK);
    M2C_UNK func_01ff9e00(void);
    s32 func_02091e14(void);
    extern void *gCur3DSpriteEngine, *data_027e00c4, *data_027e00c8;
    u16 *volatile p0, *volatile p1, *volatile p2, *volatile p3, *volatile p4;
    void *saved;
    s32 i;
    func_02096d5c();
    saved = gCur3DSpriteEngine;
    i = 0;
    do {
        gCur3DSpriteEngine = (i == 0) ? data_027e00c8 : data_027e00c4;
        if ((func_02091e14() != 0 || gCur3DSpriteEngine == data_027e00c8) &&
            (func_02091e14() != 1 || gCur3DSpriteEngine == data_027e00c4) &&
            (func_02091e14() != 3 || gCur3DSpriteEngine == saved)) {
            func_02096d0c();
            p0 = *(u16 **)gCur3DSpriteEngine; *p0 = *p0 | 0x10;
            p1 = *(u16 **)gCur3DSpriteEngine; *p1 = *p1 | 0x20;
            p2 = *(u16 **)gCur3DSpriteEngine; *p2 = *p2 | 0x40;
            p3 = *(u16 **)gCur3DSpriteEngine; *p3 = *p3 | 0x80;
            p4 = *(u16 **)gCur3DSpriteEngine; *p4 = *p4 | 0x100;
            func_020aca8c(3);
            func_01ff9e00();
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = saved;
}

void func_02096f24(void) {
M2C_UNK func_02082cb4();
M2C_UNK func_0208232c();
s32 func_02091e14();
M2C_UNK func_020aca8c(M2C_UNK);
extern void *gCur3DSpriteEngine,*data_027e00c4,*data_027e00c8;
u16 *volatile p0;u16 *volatile p1;u16 *volatile p2;u16 *volatile p3;u16 *volatile p4;
void *saved; s32 i;
func_02082cb4();
saved=gCur3DSpriteEngine;
i=0;
do {
gCur3DSpriteEngine=i==0?data_027e00c8:data_027e00c4;
if((func_02091e14()!=0||gCur3DSpriteEngine==data_027e00c8)&&(func_02091e14()!=1||gCur3DSpriteEngine==data_027e00c4)&&(func_02091e14()!=3||gCur3DSpriteEngine==saved)){
func_0208232c();
p0=*(u16 **)gCur3DSpriteEngine;*p0=*p0&~16;
p1=*(u16 **)gCur3DSpriteEngine;*p1=*p1&~32;
p2=*(u16 **)gCur3DSpriteEngine;*p2=*p2&~64;
p3=*(u16 **)gCur3DSpriteEngine;*p3=*p3&~128;
p4=*(u16 **)gCur3DSpriteEngine;*p4=*p4&~256;
func_020aca8c(3);
}
++i;
}while(i<2);
gCur3DSpriteEngine=saved;
}

void func_0209707c(void) {
    s32 func_02091e24();
    extern void *data_027e00c4;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    s32 var_r5;
    void *var_r0;

    temp_r4 = gCur3DSpriteEngine;
    var_r5 = 0;
    do {
        if (var_r5 == 0) {
            var_r0 = data_027e00c8;
        } else {
            var_r0 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r0;
        if (((func_02091e24() != 0) || (gCur3DSpriteEngine == data_027e00c8)) && ((func_02091e24() != 1) || (gCur3DSpriteEngine == data_027e00c4)) && ((func_02091e24() != 3) || (gCur3DSpriteEngine == temp_r4))) {
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
        }
        var_r5 += 1;
    } while (var_r5 < 2);
    gCur3DSpriteEngine = temp_r4;
}

void func_02097128(s8 arg0) {
    void *func_02091da8();
    M2C_FIELD(func_02091da8(), s8 *, 0x4A) = arg0;
}

void func_0209713c(s8 arg0) {
    M2C_FIELD(func_02091da8(), s8 *, 0x4C) = arg0;
}

void func_02097150(M2C_UNK arg0, s16 arg1) {
    s32 *func_02091f18();
    M2C_FIELD(func_02091f18(), s16 *, 4) = arg1;
}

void func_02097164(s32 a,s8 b) { s32 *func_02091f18(); M2C_FIELD(func_02091f18(),s8 *,6)=b; }

void func_02097178(s32 a,s32 b) { s32 *func_02091f18(); s32 p; M2C_FIELD(func_02091f18(),u8 *,7)=b; p=func_0209e9dc((u16)a); if(!p)return; if(b==1)func_0209e2b8(p,1);else func_0209e2b8(p,0); }

void func_020971c0(s32 a,s32 b) { s32 p; void *q; s32 r; p=func_0209e9dc((u16)a);if(!p)return;q=func_0209e2c0(p,0);r=M2C_FIELD(q,s32 *,0x60);if(b)func_02098e2c(r,0);else func_02098e2c(r,M2C_FIELD(q,u8 *,0x58));func_0209e320(p); }

void func_02097214(s32 a,s32 b,s32 c) { s32 func_02091e04(void); void func_020991fc(void *,u32);void func_020990fc(void *,s32,s32,s32);s32 p,r;void *q;p=func_0209e9dc((u16)a);if(!p)return;q=func_0209e2c0(p,0);r=M2C_FIELD(q,s32 *,0x60);func_020991fc(q,(u8)func_02091e04());func_020990fc(q,b,c+5,1);func_02098e2c(r,b);func_0209e320(p); }

void func_02097280(s32 arg0) {
    M2C_UNK func_02088db8(void *, s32);
    M2C_UNK func_02088d94(s32);
    M2C_UNK func_02088ea8(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 func_020abe90(u8);
    void *temp_r0;
    void *temp_r7;
    s32 var_r8;
    s32 temp_r4;

    temp_r0 = func_0209e9dc(2);
    if (temp_r0 == NULL) {
        return;
    }
    temp_r7 = func_0209e2c0(temp_r0, arg0);
    var_r8 = 8;
    temp_r4 = M2C_FIELD(temp_r7, s32 *, 0x60);
    if (func_020abe90((u8) ((u32) (M2C_FIELD(temp_r0, u8 *, 0x48) << 0x1C) >> 0x1D)) == 1) {
        var_r8 = 0;
    }
    switch (arg0) {                                 /* irregular */
    case 0:
        func_02088ea8(temp_r7, -0x40, 0, 0, 0, var_r8);
        func_02088db8(temp_r7, var_r8);
        break;
    case 1:
        func_02088ea8(temp_r7, 0xA0, 0, 0x60, 0, var_r8);
        func_02088db8(temp_r7, var_r8);
        break;
    }
    func_02088d94(temp_r4);
    func_0209e320(temp_r0);
}

void func_02097348(s32 arg0) {
    M2C_UNK func_02088f8c(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_02088e0c(void *, s32);
    s32 func_020abe90(u8);
    register s32 temp_r4 = 0;
    void *temp_r0;
    register void *temp_r7;
    long var_r8;

    temp_r0 = func_0209e9dc(2);
    if (temp_r0 == NULL) {
        return;
    }
    temp_r7 = func_0209e2c0(temp_r0, arg0);
    var_r8 = 8;
    temp_r4 = M2C_FIELD(temp_r7, s32 *, 0x60);
    if (func_020abe90((u8) ((u32) (M2C_FIELD(temp_r0, u8 *, 0x48) << 0x1C) >> 0x1D)) == 1) {
        var_r8 = 0;
    }
    switch (arg0) {
    case 0:
        func_02088f8c(temp_r7, 0, 0, -0x40, 0, var_r8);
        func_02088e0c(temp_r7, var_r8);
        break;
    case 1:
        func_02088f8c(temp_r7, 0x60, 0, 0xA0, 0, var_r8);
        func_02088e0c(temp_r7, var_r8);
        break;
    }
    func_02088da8(temp_r4);
    func_0209e320(temp_r0);
}

void func_02097410(void) {

}

void func_02097414(s32 a,s32 b,s32 c) { s32 func_02091e04(void); void func_020991fc(void *,u32);void func_020990fc(void *,s32,s32,s32);s32 p,r;void *q;p=func_0209e9dc(2);if(!p)return;q=func_0209e2c0(p,a);r=M2C_FIELD(q,s32 *,0x60);func_020991fc(q,(u8)func_02091e04());func_020990fc(q,b,c+8,1);func_02098e2c(r,b); }

void func_0209747c(M2C_UNK arg0, s32 arg1) {
    s32 temp_r0;
    s32 temp_r0_3;
    void *temp_r0_2;

    temp_r0 = func_0209e9dc(2);
    if (temp_r0 == 0) {
        return;
    }
    temp_r0_2 = func_0209e2c0(temp_r0, arg0);
    temp_r0_3 = M2C_FIELD(temp_r0_2, s32 *, 0x60);
    if (arg1 != 0) {
        func_02098e2c(temp_r0_3, 0U);
    } else {
        func_02098e2c(temp_r0_3, M2C_FIELD(temp_r0_2, u8 *, 0x58));
    }
    func_0209e320(temp_r0);
}

void func_020974d0(s32 arg0) {
    s32 func_02091db4();
    s32 func_02091e24();
    void func_020943a8(s32);
    M2C_UNK func_02098e04(void *, s32, u16);
    M2C_UNK func_020990d4(void *, s32, u16);
    M2C_UNK func_0209e184(void *, M2C_UNK, M2C_UNK, u16);
    void *func_0209e9a4(s32);
    extern void *data_027e00c4;
    extern void *data_027e00c8;
    extern void *data_027e01d8;
    void *spC;
    s32 sp8;
    s32 sp4;
    s32 sp0;
    void **var_r0;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_4;
    s32 var_r8;
    s32 var_r8_2;
    s32 var_r9;
    s32 var_r9_2;
    u16 temp_r5;
    u16 var_r6;
    u16 var_r6_2;
    void *temp_r0_3;
    void *temp_r0_5;
    void *temp_r0_6;
    void *temp_r0_7;
    void *temp_r0_8;
    void *temp_r7;
    void *temp_r7_2;

    sp0 = arg0;
    spC = data_027e01d8;
    sp8 = 0;
    do {
        if (sp8 == 0) {
            var_r0 = &data_027e00c8;
        } else {
            var_r0 = &data_027e00c4;
        }
        data_027e01d8 = *var_r0;
        if (((func_02091e24() != 0) || (data_027e01d8 == data_027e00c8)) && ((func_02091e24() != 1) || (data_027e01d8 == data_027e00c4)) && ((func_02091e24() != 3) || (data_027e01d8 == spC))) {
            temp_r0_2 = func_02091db4();
            switch (temp_r0_2) {                    /* irregular */
            case 0:
                temp_r0_3 = func_0209e9a4(sp0);
                func_0209e184(temp_r0_3, 1, 0, 8U);
                M2C_FIELD(temp_r0_3, s16 *, 0x2E) = 2;
                M2C_FIELD(temp_r0_3, s16 *, 0x3C) = 0x400;
                break;
            case 1:
                sp4 = 0;
                var_r8 = 0x9000;
                var_r9 = 0x9800;
                do {
                    temp_r0_5 = func_0209e9a4(sp0);
                    func_0209e184(temp_r0_5, 1, 0x8000, (u16) (sp4 + 0xD));
                    var_r6 = 0;
                    temp_r5 = (u16) sp4;
                    M2C_FIELD(temp_r0_5, u16 *, 0x2E) = temp_r5;
                    M2C_FIELD(temp_r0_5, s16 *, 0x3C) = 0x400;
loop_17:
                    temp_r0_6 = func_0209e2c0(temp_r0_5, var_r6);
                    temp_r7 = M2C_FIELD(temp_r0_6, void **, 0x60);
                    func_02098e04(temp_r7, var_r8, (u16) (sp4 + 0xA));
                    func_020990d4(temp_r0_6, var_r9, temp_r5);
                    M2C_FIELD(temp_r7, s16 *, 0x3C) = 0x400;
                    var_r6 += 1;
                    M2C_FIELD(temp_r0_6, s16 *, 0x3C) = 0x400;
                    if ((s32) var_r6 < 2) {
                        goto loop_17;
                    }
                    var_r8 += 0x200;
                    temp_r0_4 = sp4 + 1;
                    sp4 = temp_r0_4;
                    var_r9 += 0xA00;
                } while (temp_r0_4 < 3);
                break;
            case 2:
                temp_r0_7 = func_0209e9a4(sp0);
                func_0209e184(temp_r0_7, 2, 0, 0xDU);
                M2C_FIELD(temp_r0_7, s16 *, 0x2E) = 2;
                M2C_FIELD(temp_r0_7, s16 *, 0x3C) = 0x400;
                var_r6_2 = 0;
                var_r8_2 = 0x1800;
                var_r9_2 = 0x2000;
                do {
                    temp_r0_8 = func_0209e2c0(temp_r0_7, var_r6_2);
                    temp_r7_2 = M2C_FIELD(temp_r0_8, void **, 0x60);
                    func_02098e04(temp_r7_2, var_r8_2, (u16) (var_r6_2 + 0xA));
                    func_020990d4(temp_r0_8, var_r9_2, var_r6_2);
                    M2C_FIELD(temp_r7_2, s16 *, 0x3C) = 0x400;
                    M2C_FIELD(temp_r0_8, s16 *, 0x3C) = 0x400;
                    var_r8_2 += 0x200;
                    var_r9_2 += 0x8000;
                    var_r6_2 += 1;
                } while ((s32) var_r6_2 < 2);
                break;
            }
        }
        temp_r0 = sp8 + 1;
        sp8 = temp_r0;
    } while (temp_r0 < 2);
    data_027e01d8 = spC;
    func_020943a8(-1);
}

void func_02097768(void) {

}

s32 func_0209776c(s32 arg0) {
    s32 func_02089064(void);
    s32 func_020abe90(u8);
    M2C_UNK func_02088ea8(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_0209e9dc(M2C_UNK);
    void func_0209e1b0(void *);
    s32 *func_02091f18();
    s32 func_02091f08(void);
    void func_02091d4c(M2C_UNK);
    s32 func_02091e50(void);
    void func_020943a8(s32);
    void *temp_r4;
    s32 var_r6;
    s32 *temp_r5;

    temp_r4 = (void *) func_0209e9dc((u16) arg0);
    if (temp_r4 != NULL && func_02089064() == 0) {
        func_0209e1b0(temp_r4);
        var_r6 = 8;
        if (func_020abe90((u8) ((u32) (M2C_FIELD(temp_r4, u8 *, 0x48) << 0x1C) >> 0x1D)) == 1) {
            var_r6 = 0;
        }
        switch (arg0) {
        case 0:
            func_02088ea8(temp_r4, 0, -0x40, 0, 0, var_r6);
            break;
        case 1:
            func_02088ea8(temp_r4, -0x100, 0x40, 0, 0x40, var_r6);
            break;
        case 2:
            func_02088ea8(temp_r4, 0, 0xc0, 0, 0x80, var_r6);
            break;
        }
        temp_r5 = func_02091f18(arg0);
        M2C_FIELD(temp_r5, u16 *, 0x8) = (u16) func_02091f08();
        func_02091d4c(M2C_FIELD(temp_r5, u8 *, 0x6));
        if (func_02091e50() < 0) {
            func_020943a8(arg0);
        }
        return 1;
    }
    return 0;
}

s32 func_0209787c(s32 arg0) {
    s32 func_02089064(void);
    s32 func_020abe90(u8);
    M2C_UNK func_02088f8c(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_02097bac(s32);
    void *temp_r4;
    s32 var_r5;

    temp_r4 = (void *) func_0209e9dc((u16) arg0);
    if (temp_r4 != NULL && func_02089064() != 0) {
        var_r5 = 8;
        if (func_020abe90((u8) ((u32) (M2C_FIELD(temp_r4, u8 *, 0x48) << 0x1C) >> 0x1D)) == 1) {
            var_r5 = 0;
        }
        switch (arg0) {
        case 0:
            func_02088f8c(temp_r4, 0, 0, 0, -0x40, var_r5);
            break;
        case 1:
            func_02088f8c(temp_r4, 0, 0x40, 0x100, 0x40, var_r5);
            break;
        case 2:
            func_02088f8c(temp_r4, 0, 0x80, 0, 0xc0, var_r5);
            break;
        }
        func_02097bac(arg0);
        return 1;
    }
    return 0;
}

s32 func_02097964(void) {
    s32 func_0209787c(M2C_UNK);
    s32 var_r4;

    var_r4 = 0;
    if (func_0209787c(0) != 0) {
        var_r4 = 1;
    }
    if (func_0209787c(1) != 0) {
        var_r4 = 1;
    }
    if (func_0209787c(2) != 0) {
        var_r4 = 1;
    }
    return var_r4;
}

s32 func_020979a4(s32 a) { s32 *func_02091f18();s32 i,q,p,b;for(i=0;i<3;i++){q=func_02091f18(i);p=func_0209e9dc((u16)i);if(p){b=0;if(i==a)b=1;func_02091d6c(M2C_FIELD(q,u8 *,6),b);func_0209e26c(p,b);func_0209e320(p);}}func_020943a8(a);func_02094ba0(a);func_0209707c();return 1;}

void func_02097a2c(s32 arg0) {
    s32 func_02091db4();
    M2C_UNK func_020991f4(s32, s32);
    M2C_UNK func_02099204(s32);
    long var_r6;
    s32 temp_r0;
    s32 temp_r0_2;

    if (func_02091db4() != 2) {
        return;
    }
    temp_r0 = func_0209e9dc(2);
    if (!temp_r0) {
        return;
    }
    var_r6 = 0;
    do {
        temp_r0_2 = func_0209e2c0(temp_r0, var_r6);
        if (var_r6 == arg0) {
            func_020991f4(temp_r0_2, 1);
        } else {
            func_020991f4(temp_r0_2, 0);
        }
        func_02099204(temp_r0_2);
        var_r6++;
    } while (2 > var_r6);
    func_0209e320(temp_r0);
}

void func_02097aa8(void) {

}

void func_02097aac(s32 arg0, u8 arg1) {
    s32 func_02091e24();
    extern void *data_027e00c4;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    void *var_r0;
    s32 var_r5;
    u16 *base;
    s32 r6;
    s32 lr;
    s32 r8;
    s32 r12;
    s32 r3;

    temp_r4 = gCur3DSpriteEngine;
    r6 = arg1 * 2 + 1;
    base = (u16 *) arg0;
    var_r5 = 0;
    lr = 1;
    do {
        if (var_r5 == 0) {
            var_r0 = data_027e00c8;
        } else {
            var_r0 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r0;
        if (((func_02091e24() != 0) || (gCur3DSpriteEngine == data_027e00c8)) &&
            ((func_02091e24() != 1) || (gCur3DSpriteEngine == data_027e00c4)) &&
            ((func_02091e24() != 3) || (gCur3DSpriteEngine == temp_r4))) {
            if (r6 > 1) {
                r8 = 0x20;
                r3 = 0;
                r12 = r3;
                lr = 1;
                do {
                    for (r12 = 0; r12 < 0x20; r12++) {
                        base[r8 + r12] = 0;
                    }
                    r8 += 0x20;
                    lr += 1;
                } while (lr < r6);
            }
        }
        var_r5 += 1;
    } while (var_r5 < 2);
    gCur3DSpriteEngine = temp_r4;
}

void func_02097bac(M2C_UNK arg0) {
    s32 func_02091e70(M2C_UNK);
    s32 *func_02091f18();
    void func_02097aac(s32, u8);
    s32 *temp_r5;
    s32 temp_r4;

    temp_r5 = func_02091f18();
    temp_r4 = func_02091e70(arg0);
    func_02097aac(*temp_r5 + (temp_r4 * 2), M2C_FIELD(func_02091da8(), u8 *, 0x4A));
}

s32 func_02097be0(void) {
s32 func_020890d4(s32);
s32 i,p,j;
i=0;do {p=func_0209e9dc((u16)i);if(p) {
if(func_020890d4(p))return 1;
j=0;do {if(func_020890d4(func_0209e2c0(p,j)))return 1;j++;}while(j<2);
}i++;}while(i<3);return 0;
}

