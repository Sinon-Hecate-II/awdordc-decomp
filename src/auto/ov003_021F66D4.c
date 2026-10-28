/* 3 functions from 0x021F66D4 to 0x021F7164 (ov003), found by ds-decomp. */
#include "common.h"

typedef struct UnkUnitOv003 {
    u8 pad00[0x3A];
    u8 cnt : 7;
    u8 f3a7 : 1;
    u8 state : 4;
    u8 f3b4 : 1;
    u8 active : 1;
    u8 f3b67 : 2;
    u8 pad3C[8];
    u8 *f44;
    u8 pad48[4];
    u8 *f4C;
    u8 pad50[8];
    u8 *f58;
    u8 pad5C[4];
    u8 *f60;
    u8 *f64;
    u8 *f68;
} UnkUnitOv003;

void func_ov003_021f66d4(M2C_UNK arg0) {
    M2C_UNK func_01ffa6fc(M2C_UNK);
    s32 func_02084d3c(s32 *, M2C_UNK);
    M2C_UNK func_02084d88(s32 *, M2C_UNK);
    M2C_UNK func_02084e74();
    s32 buffer[9];

    if (func_02084d3c(buffer, 0x24) == 0) {
        return;
    }
    buffer[0] = 0;
    buffer[1] = 0;
    func_02084d88(buffer, 0x24);
    func_02084e74();
    func_01ffa6fc(arg0);
}

void func_ov003_021f6724(void *arg0) {
    M2C_UNK func_02088ff4(s32);
    M2C_UNK func_ov003_021f8c20(void *);
    void *temp_r4;

    temp_r4 = M2C_FIELD(arg0, void **, 0x68);
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 0));
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 4));
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 8));
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 0xC));
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 0x10));
    func_02088ff4(M2C_FIELD(temp_r4, s32 *, 0x14));
    func_ov003_021f8c20(arg0);
}

void func_ov003_021f676c(UnkUnitOv003 *arg0) {
    extern void *gCur3DSpriteEngine, *data_027e00c8, *data_027e00c4;
    extern u8 data_027e00b4[8];
    extern u8 data_ov003_0220fe00[28];
    extern u8 data_ov003_0220fdf2[14];
    void func_020a8f8c(void *);
    void func_020ab2c4(void *);
    s16 func_020a8ff4(void *);
    void func_02088e84(void *, s16, s16, s16, s32);
    s16 func_020aae10(void *);
    s16 func_020aae44(void *);
    void func_02087d84(void *, s32, s32, s32, u16, u16);
    void func_01ffaacc(s32, s32, u16, void *, s32);
    s32 func_ov003_021f400c(void);
    s32 func_ov003_021f4064(void);
    u16 func_ov003_021fbcd8(void *, s32);
    s32 func_ov003_021f3f24(s32, s32, s32, s32);
    s16 func_ov003_021f3fa0(s32, s32, s32);
    s32 func_0207c8ec(s32, s32);
    void func_ov003_021f9fe0(void *, s32, s32);
    void func_ov003_021f9e50(void *, s32, s32);
    void func_ov003_021fad10(void *, s32, s32);
    s32 temp_r5;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 temp_var;
    s16 temp_r4;
    s16 temp_r7;
    s16 temp_r8;
    s32 temp_r9;
    s32 temp_v6;
    void *temp_r6;
    void *sp14;
    void *old;
    u32 cond;
    s32 i;
    s32 lim;
    s32 cv;
    s32 r7v;
    s32 c1;
    s32 c3;
    s32 d;
    s32 r11r;
    s32 ctr;
    s16 q;
    s32 w;
    s32 pv;
    u16 cval;

    if (arg0->active == 0) {
        return;
    }
    if (arg0->cnt != 0x30) {
        arg0->cnt = arg0->cnt + 1;
    }
    if (arg0->state == 0) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L1;
    }
    if (arg0->state == 2) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L1;
    }
    if (arg0->state == 3) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L1;
    }
    if (arg0->state == 4) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L1;
    }
    if (arg0->state == 6) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L1;
    }
    if (arg0->state == 7) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L1;
    }
    if (arg0->state == 8) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
L1:
        func_020a8f8c(arg0->f60 + 0x20);
        func_020ab2c4(arg0->f4C);
        func_020a8f8c(arg0->f44 + 0x1C);
    }
    if (arg0->state == 0) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L2;
    }
    if (arg0->state == 2) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L2;
    }
    if (arg0->state == 3) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L2;
    }
    if (arg0->state == 4) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L2;
    }
    if (arg0->state == 6) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L2;
    }
    if (arg0->state == 7) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L2;
    }
    if (arg0->state == 8) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
L2:
        func_020a8f8c(arg0->f58);
        func_020a8f8c(arg0->f64);
        sp14 = gCur3DSpriteEngine;
        gCur3DSpriteEngine = data_027e00c8;
        temp_r5 = func_020a8ff4(arg0->f64);
        if (arg0->state == 0) {
            cond = 1;
        } else {
            cond = 0;
        }
        if (cond & 0xff) {
            goto L3;
        }
        if (arg0->state == 3) {
            cond = 1;
        } else {
            cond = 0;
        }
        if (cond & 0xff) {
L3:
            if ((s16) M2C_FIELD(arg0->f60, s32 *, 0x10) != 0) {
                temp_r6 = M2C_FIELD(arg0->f68, void **, 0x10);
                temp_r4 = (s16) (temp_r5 + 4);
                func_02088e84(temp_r6, 0x38, temp_r4, 0x38, temp_r4);
                if (M2C_FIELD(M2C_FIELD(temp_r6, void **, 0x64), u8 *, 0x12) != 0) {
                    var_r0 = 1;
                } else {
                    var_r0 = 0;
                }
                if (var_r0 & 0xFF) {
                    temp_r7 = M2C_FIELD(temp_r6, s16 *, 0x52);
                    temp_r8 = M2C_FIELD(temp_r6, s16 *, 0x50);
                    temp_r9 = func_020aae10(temp_r6);
                    func_02087d84(M2C_FIELD(temp_r6, void **, 0x64), 1, temp_r8, temp_r7, (u16) temp_r9, (u16) func_020aae44(temp_r6));
                }
                M2C_FIELD(temp_r6, s16 *, 0x34) = 0x38;
                M2C_FIELD(temp_r6, s16 *, 0x36) = temp_r4;
                if (M2C_FIELD(M2C_FIELD(temp_r6, void **, 0x64), u8 *, 0x12) != 0) {
                    var_r0_2 = 1;
                } else {
                    var_r0_2 = 0;
                }
                if (var_r0_2 & 0xFF) {
                    temp_r7 = M2C_FIELD(temp_r6, s16 *, 0x52);
                    temp_r8 = M2C_FIELD(temp_r6, s16 *, 0x50);
                    temp_r9 = func_020aae10(temp_r6);
                    func_02087d84(M2C_FIELD(temp_r6, void **, 0x64), 1, temp_r8, temp_r7, (u16) temp_r9, (u16) func_020aae44(temp_r6));
                }
                temp_r6 = M2C_FIELD(arg0->f68, void **, 0x14);
                func_02088e84(temp_r6, 0xA8, temp_r4, 0xA8, temp_r4);
                if (M2C_FIELD(M2C_FIELD(temp_r6, void **, 0x64), u8 *, 0x12) != 0) {
                    var_r0_3 = 1;
                } else {
                    var_r0_3 = 0;
                }
                if (var_r0_3 & 0xFF) {
                    temp_r7 = M2C_FIELD(temp_r6, s16 *, 0x52);
                    temp_r8 = M2C_FIELD(temp_r6, s16 *, 0x50);
                    temp_r9 = func_020aae10(temp_r6);
                    func_02087d84(M2C_FIELD(temp_r6, void **, 0x64), 1, temp_r8, temp_r7, (u16) temp_r9, (u16) func_020aae44(temp_r6));
                }
                M2C_FIELD(temp_r6, s16 *, 0x34) = 0xA8;
                M2C_FIELD(temp_r6, s16 *, 0x36) = temp_r4;
                if (M2C_FIELD(M2C_FIELD(temp_r6, void **, 0x64), u8 *, 0x12) != 0) {
                    var_r0_4 = 1;
                } else {
                    var_r0_4 = 0;
                }
                if (var_r0_4 & 0xFF) {
                    temp_r7 = M2C_FIELD(temp_r6, s16 *, 0x52);
                    temp_r8 = M2C_FIELD(temp_r6, s16 *, 0x50);
                    temp_r9 = func_020aae10(temp_r6);
                    func_02087d84(M2C_FIELD(temp_r6, void **, 0x64), 1, temp_r8, temp_r7, (u16) temp_r9, (u16) func_020aae44(temp_r6));
                }
            }
        }
        if (arg0->state == 4) {
            cond = 1;
        } else {
            cond = 0;
        }
        if (!(cond & 0xff)) {
            var_r0 = (s16) temp_r5;
            func_01ffaacc(0, (u8) var_r0, (u16) (0xB800 | ((0x48C >> ((u32) (M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 0x11) >> 0x1E)) & 0x3FF)), data_ov003_0220fe00, 0xB);
        }
        if ((func_ov003_021f400c() == 0) && (func_ov003_021f4064() != 0)) {
            var_r0 = 0xA0 - temp_r5;
            func_01ffaacc(0xC0, (u8) var_r0, (u16) (0xB000 | ((0x4CC >> ((u32) (M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 0x11) >> 0x1E)) & 0x3FF)), data_027e00b4, 0xB);
        }
        if (arg0->state == 4) {
            cond = 1;
        } else {
            cond = 0;
        }
        if (!(cond & 0xff)) {
            i = 0;
            lim = ((s16) M2C_FIELD(arg0->f60, s32 *, 0x10)) & 0xFF;
            if (lim < 0) {
                goto LEND;
            }
            r7v = (lim + 1) * 0x70;
            cv = (temp_r5 + 4) & 0xFF;
            do {
                temp_v6 = func_ov003_021fbcd8(arg0, i & 0xFF);
                if (arg0->state == 2) {
                    cond = 1;
                } else {
                    cond = 0;
                }
                if (cond & 0xff) {
                    goto L600;
                }
                if (lim != 0) {
                    goto L608;
                }
L600:
                temp_r9 = 0x60;
                goto L698;
L608:
                q = M2C_FIELD(arg0->f60, s16 *, 4);
                temp_r9 = (s16) ((((s16) M2C_FIELD(arg0->f60, s32 *, 0x10)) + 1) * q);
                temp_r5 = func_020a8ff4(arg0->f60 + 0x20);
                r11r = func_0207c8ec(temp_r9, 2);
                w = func_0207c8ec(temp_r9, 2);
                pv = func_ov003_021f3fa0((s16) (temp_r5 + (s16) ((lim - i) * q)), (s16) (-r11r), (s16) w);
                temp_r9 = (s16) (-0x10 - pv);
L698:
                if ((lim != 0) && ((u32) lim < 3)) {
                    goto L7E0;
                }
                if (lim == 3) {
                    if (temp_r9 < -0xC0) {
                        temp_r5 = (temp_r9 + 0x1C0) & 0xFF;
                        if (func_ov003_021f3f24(temp_r5, 4, 0x40, 0x20)) {
                            func_01ffaacc((u16) (temp_r5 & 0x1FF), (u16) cv, (u16) (0x7400 | (0x3FF & ((temp_v6 + 0x340) >> ((u32) (M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 0x11) >> 0x1E)))), data_ov003_0220fdf2, 0xB);
                        }
                    }
                }
                if (func_ov003_021f3f24(temp_r9, 4, 0x40, 0x20)) {
                    temp_v6 = temp_v6 + 0x340;
                    func_01ffaacc((u16) (temp_r9 & 0x1FF), (u16) cv, (u16) (0x400 | (((u32) ((i == ((s16) M2C_FIELD(arg0->f60, s32 *, 0xC))) ? 6 : 7) << 0x1C) >> 0x10) | (0x3FF & (temp_v6 >> ((u32) (M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 0x11) >> 0x1E)))), data_ov003_0220fdf2, 0xB);
                }
                goto L8BC;
L7E0:
                cval = (u16) cv;
                c1 = 0x1FF;
                c3 = 0x3FF;
                d = -r7v;
                r11r = temp_v6 + 0x340;
                ctr = -1;
                do {
                    temp_r4 = (s16) (temp_r9 + d);
                    if (func_ov003_021f3f24(temp_r4, 4, 0x40, 0x20)) {
                        func_01ffaacc((u16) (temp_r4 & c1), cval, (u16) (0x400 | (((u32) ((i == ((s16) M2C_FIELD(arg0->f60, s32 *, 0xC))) ? 6 : 7) << 0x1C) >> 0x10) | (c3 & (r11r >> ((u32) (M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) << 0x11) >> 0x1E)))), data_ov003_0220fdf2, 0xB);
                    }
                    d = d + r7v;
                    ctr = (s8) (ctr + 1);
                } while (ctr <= 1);
L8BC:
                i = (s16) (i + 1);
            } while (lim >= i);
LEND:
            ;
        }
        {
            s32 v = func_020a8ff4(arg0->f58);
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3A) = (s16) (-v);
            M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x42) = 0;
        }
        func_ov003_021fad10(arg0, (s16) (func_020a8ff4(arg0->f58) + 6), 0x28);
        gCur3DSpriteEngine = sp14;
    }
    old = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    if (arg0->state == 0) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L4;
    }
    if (arg0->state == 4) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L4;
    }
    if (arg0->state == 6) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L4;
    }
    if (arg0->state == 7) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
        goto L4;
    }
    if (arg0->state == 8) {
        cond = 1;
    } else {
        cond = 0;
    }
    if (cond & 0xff) {
L4:
        temp_var = func_020a8ff4(arg0->f58);
    } else {
        if (arg0->state == 1) {
            cond = 1;
        } else {
            cond = 0;
        }
        if (cond & 0xff) {
            goto L5;
        }
        if (arg0->state == 2) {
            cond = 1;
        } else {
            cond = 0;
        }
        if (cond & 0xff) {
            goto L5;
        }
        if (arg0->state == 3) {
            cond = 1;
        } else {
            cond = 0;
        }
        if (cond & 0xff) {
            goto L5;
        }
        if (arg0->state == 5) {
            cond = 1;
        } else {
            cond = 0;
        }
        if (cond & 0xff) {
L5:
            temp_var = 0;
        }
    }
    func_ov003_021f9fe0(arg0, temp_var, 0);
    func_ov003_021f9e50(arg0, temp_var, 0);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3E) = (s16) (-0x2C - temp_var);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x46) = (s16) data_027e00c4;
    gCur3DSpriteEngine = old;
}

