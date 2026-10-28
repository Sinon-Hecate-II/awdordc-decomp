/* 24 functions from 0x0221F4F8 to 0x02220018 (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_0221f4f8(void *arg0) {
    (void)arg0;
}

void func_ov005_0221fa00(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220c38;
    func_01ffa42c(&data_ov005_02220c38, arg0);
}

/* Enable five display-control bits (0x10/0x20/0x40/0x80/0x100) on each of the two screen contexts. */
void func_ov005_0221fa18(void) {
    M2C_UNK func_02082cb4(); M2C_UNK func_0208232c();
    extern s32 gCur3DSpriteEngine; extern s32 data_027e00c4; extern s32 data_027e00c8;
    u16 *volatile ctxPtr0; u16 *volatile ctxPtr1; u16 *volatile ctxPtr2; u16 *volatile ctxPtr3; u16 *volatile ctxPtr4;
    s32 savedContext; s32 i;
    func_02082cb4(); savedContext = gCur3DSpriteEngine; i = 0;
    do {
        gCur3DSpriteEngine = i == 0 ? data_027e00c8 : data_027e00c4;
        func_0208232c(); i++;
        ctxPtr0 = *(u16 **)gCur3DSpriteEngine; *ctxPtr0 = *ctxPtr0 | 0x10;
        ctxPtr1 = *(u16 **)gCur3DSpriteEngine; *ctxPtr1 = *ctxPtr1 | 0x20;
        ctxPtr2 = *(u16 **)gCur3DSpriteEngine; *ctxPtr2 = *ctxPtr2 | 0x40;
        ctxPtr3 = *(u16 **)gCur3DSpriteEngine; *ctxPtr3 = *ctxPtr3 | 0x80;
        ctxPtr4 = *(u16 **)gCur3DSpriteEngine; *ctxPtr4 = *ctxPtr4 | 0x100;
    } while (i < 2);
    gCur3DSpriteEngine = savedContext;
}

void func_ov005_0221fb14(M2C_UNK arg0) {
    M2C_UNK func_020675e4(void *, void *, s32);
    M2C_UNK func_02068d68(void *, void *);
    s32 func_02086680(s32);
    M2C_UNK func_020899fc(s32, M2C_UNK, s32, void *);
    s32 func_0208b564(M2C_UNK);
    extern s32 data_0212616c;
    extern M2C_UNK data_0215c334;
    extern M2C_UNK data_ov005_022212f4;
    extern M2C_UNK data_ov005_022212f8;
    char sp20[128];
    char sp0[32];
    s32 var_r9;
    char *var_r10;
    func_020675e4(sp20, &data_ov005_022212f4, func_02086680(0xF000000F));
    var_r10 = (char *)&data_0212616c;
    var_r9 = 0;
    do {
        if (M2C_FIELD(&data_0215c334, s32 *, 8) & (1 << var_r9)) {
            func_020675e4(sp0, &data_ov005_022212f8, func_02086680(*(s32 *)var_r10));
            func_02068d68(sp20, sp0);
        }
        var_r9 += 1;
        var_r10 += 0x9C;
    } while (var_r9 < 0xF);
    func_020899fc(func_0208b564(arg0), 2, 0x6B80, sp20);
}

void func_ov005_0221fbc8(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0215c334;
    extern M2C_UNK data_ov005_02220b38;
    s32 i;
    for (i = 0; i < 15; i++) {
        if (M2C_FIELD(&data_0215c334, s32 *, 8) & (1 << i)) {
            func_01ffa42c(&data_ov005_02220b38, arg0);
            return;
        }
    }
}

void func_ov005_0221fc0c(void) {
M2C_UNK func_02082cb4(); M2C_UNK func_0208232c(); M2C_UNK func_02086608(M2C_UNK);
extern s32 gCur3DSpriteEngine; extern s32 data_027e00c4; extern s32 data_027e00c8;
u16 *volatile p0; u16 *volatile p1; u16 *volatile p2; u16 *volatile p3; u16 *volatile p4;
s32 saved; s32 i;
func_02082cb4(); saved=gCur3DSpriteEngine; i=0;
do {
gCur3DSpriteEngine=i==0?data_027e00c8:data_027e00c4;
func_0208232c(); i++;
p0=*(u16 **)gCur3DSpriteEngine; *p0=*p0|0x10;
p1=*(u16 **)gCur3DSpriteEngine; *p1=*p1|0x20;
p2=*(u16 **)gCur3DSpriteEngine; *p2=*p2|0x40;
p3=*(u16 **)gCur3DSpriteEngine; *p3=*p3|0x80;
p4=*(u16 **)gCur3DSpriteEngine; *p4=*p4|0x100;
} while(i<2);
gCur3DSpriteEngine=saved;
func_02086608(11);
}

void func_ov005_0221fd10(void) {
    M2C_UNK func_02086658(M2C_UNK);
    func_02086658(0xB);
}

void func_ov005_0221fd20(M2C_UNK arg0) {
    M2C_UNK func_020868e0(s32, M2C_UNK);
    s32 func_020869a0(s32);
    s32 func_020cd6d4();
    extern void **gCurrentMap;
    extern M2C_UNK data_ov005_02220bb0;
    s32 temp_r5;
    s32 var_r1;
    u16 temp_r0;

    temp_r5 = M2C_FIELD(*gCurrentMap, u16 *, 0x5142) - 0x40;
    if (func_020cd6d4() == 0) {
        return;
    }
    var_r1 = 0;
    temp_r0 = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
    if (((u32) temp_r0 >= 0xA1U) && ((u32) temp_r0 < 0xBBU)) {
        var_r1 = 1;
    }
    if (var_r1 == 0) {
        return;
    }
    if (func_020869a0(temp_r5) != 0) {
        return;
    }
    func_020868e0(temp_r5, 1);
    func_01ffa42c(&data_ov005_02220bb0, arg0);
}

void *func_ov005_0221fdb0(void *arg0) {
    extern M2C_UNK data_ov005_02220f54;
    void *temp_r4;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220f54;
    temp_r4 = M2C_FIELD(arg0, void **, 0x34);
    if (temp_r4 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
        func_02082040(temp_r4);
    }
    func_02082040(arg0);
    return arg0;
}

void *func_ov005_0221fdf0(void *arg0) {
    extern M2C_UNK data_ov005_02220f54;
    void *temp_r4;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220f54;
    temp_r4 = M2C_FIELD(arg0, void **, 0x34);
    if (temp_r4 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
        func_02082040(temp_r4);
    }
    return arg0;
}

s32 func_ov005_0221fe28(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov005_0221fe3c(void) {

}

s32 func_ov005_0221fe40(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov005_0221fe54(void) {

}

#pragma opt_strength_reduction off
M2C_UNK **func_ov005_0221fe58(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574(s32);
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov005_02220fa4;
    s32 temp_r8;
    s32 var_r0;
    s32 var_r9;
    *arg0 = &data_ov005_02220fa4;
    temp_r8 = gCur3DSpriteEngine;
    var_r9 = 0;
    do {
        if (var_r9 == 0) var_r0 = data_027e00c8;
        else var_r0 = data_027e00c4;
        gCur3DSpriteEngine = var_r0;
        func_01ffa574(M2C_FIELD((arg0 + var_r9), s32 *, 0x34));
        var_r9 += 1;
    } while (var_r9 < 2);
    gCur3DSpriteEngine = temp_r8;
    func_02082040(arg0);
    return arg0;
}
#pragma opt_strength_reduction reset

#pragma opt_strength_reduction off
M2C_UNK **func_ov005_0221fecc(M2C_UNK **arg0) {
    M2C_UNK func_01ffa574(s32);
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    extern M2C_UNK data_ov005_02220fa4;
    s32 temp_r8;
    s32 var_r0;
    s32 var_r9;
    *arg0 = &data_ov005_02220fa4;
    temp_r8 = gCur3DSpriteEngine;
    var_r9 = 0;
    do {
        if (var_r9 == 0) var_r0 = data_027e00c8;
        else var_r0 = data_027e00c4;
        gCur3DSpriteEngine = var_r0;
        func_01ffa574(M2C_FIELD((arg0 + var_r9), s32 *, 0x34));
        var_r9 += 1;
    } while (var_r9 < 2);
    gCur3DSpriteEngine = temp_r8;
    return arg0;
}

void *func_ov005_0221ff38(void *arg0) {
    M2C_UNK func_01ffaa6c();
    extern M2C_UNK data_ov005_02220fb8;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220fb8;
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) func_01ffaa6c();
    func_02082040(arg0);
    return arg0;
}

void *func_ov005_0221ff6c(void *arg0) {
    M2C_UNK func_01ffaa6c();
    extern M2C_UNK data_ov005_02220fb8;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220fb8;
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        func_01ffaa6c();
    }
    return arg0;
}

void *func_ov005_0221ff98(void *arg0) {
    M2C_UNK func_02082040(void *);
    extern M2C_UNK data_ov005_02220fe0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220fe0;
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x34));
    func_02082040(arg0);
    return arg0;
}

void *func_ov005_0221ffc4(void *arg0) {
    extern M2C_UNK data_ov005_02220fe0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov005_02220fe0;
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x34));
    return arg0;
}

void func_ov005_0221ffe8(void) {

}

s32 func_ov005_0221ffec(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov005_02220000(void) {

}

s32 func_ov005_02220004(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

