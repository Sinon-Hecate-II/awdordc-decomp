/* 24 functions from 0x020AB884 to 0x020AC7DC (main), found by ds-decomp. */
#include "common.h"

void func_020ab884(void *arg0) {
    return;
}

s16 func_020abb24(void *arg0) {
    s32 func_020a8ff4(void *);
    s16 temp_r4_3;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 var_r0;

    temp_r4_3 = M2C_FIELD(arg0, s16 *, 0x2A);
    if (temp_r4_3 != func_020a8ff4(arg0 + 0x30)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 & 0xFF) {
        M2C_FIELD(arg0, s8 *, 0x54) = 1;
        temp_r4_2 = func_020a8ff4(arg0 + 0x30);
        return (s16) (temp_r4_2 + func_020a8ff4(arg0 + 0x54));
    }
    temp_r4 = func_020a8ff4(arg0 + 0x30);
    return (s16) (temp_r4 + func_020a8ff4(arg0 + 0x54));
}

void func_020abb9c(void *arg0) {
    M2C_UNK func_01ffa860(M2C_UNK *, u16);
    extern M2C_UNK data_02126b94;
    func_01ffa860(&data_02126b94, M2C_FIELD(arg0, u16 *, 0x68));
}

void func_020abbb4(void *arg0) {M2C_UNK func_01ffa860(M2C_UNK *,u16);extern M2C_UNK data_02126b94;func_01ffa860(&data_02126b94,M2C_FIELD(arg0,u16 *,106));}

void func_020abbcc(void *arg0) {M2C_UNK func_01ffa860(M2C_UNK *,u16);extern M2C_UNK data_02126b94;func_01ffa860(&data_02126b94,M2C_FIELD(arg0,u16 *,108));}

void func_020abbe4(void *arg0) {M2C_UNK func_01ffa860(M2C_UNK *,u16);extern M2C_UNK data_02126b94;func_01ffa860(&data_02126b94,M2C_FIELD(arg0,u16 *,110));}

void func_020abbfc(void *arg0) {
    s32 func_0207ca38(s32, s32, s32, s32, s32);
    s32 var_r0;
    s32 var_r2;
    u16 temp_r0_2;
    u16 temp_r0_3;
    u8 temp_r0;
    u8 temp_r3;

    var_r2 = 0;
    M2C_FIELD(arg0, s8 *, 0x13) = 0;
    temp_r3 = M2C_FIELD(arg0, u8 *, 0x10);
    if ((M2C_FIELD(arg0, u8 *, 0xE) == temp_r3) && (M2C_FIELD(arg0, u8 *, 0xF) == M2C_FIELD(arg0, u8 *, 0x11))) {
        var_r2 = 1;
    }
    if (!(var_r2 & 0xFF)) {
        M2C_FIELD(arg0, u8 *, 0xE) = temp_r3;
        M2C_FIELD(arg0, u8 *, 0xF) = (u8) M2C_FIELD(arg0, u8 *, 0x11);
        if (M2C_FIELD(arg0, u16 *, 6) == 0) {
            if ((M2C_FIELD(arg0, u8 *, 0xE) == M2C_FIELD(arg0, u8 *, 0xC)) && (M2C_FIELD(arg0, u8 *, 0xF) == M2C_FIELD(arg0, u8 *, 0xD))) {
                var_r0 = 1;
            } else {
                var_r0 = 0;
            }
            temp_r0 = M2C_FIELD(arg0, u8 *, 0x12);
            if (var_r0 & 0xFF) {
                if (temp_r0 == 0) {
                    M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg0, s16 *, 0xA);
                    M2C_FIELD(arg0, u16 *, 4) = 0U;
                    M2C_FIELD(arg0, u8 *, 0x12) = 1U;
                }
            } else if (temp_r0 == 1) {
                M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg0, s16 *, 0xA);
                M2C_FIELD(arg0, u16 *, 4) = 0U;
                M2C_FIELD(arg0, u8 *, 0x12) = 0U;
            }
        }
        M2C_FIELD(arg0, u16 *, 6) = 0U;
    }
    if (M2C_FIELD(arg0, u8 *, 0x12) == 0) {
        M2C_FIELD(arg0, s16 *, 0xA) = (s16) (M2C_FIELD(arg0, s16 *, 8) + func_0207ca38(1, 0, 0xA0, M2C_FIELD(arg0, u16 *, 4), 8));
        if ((s32) M2C_FIELD(arg0, s16 *, 0xA) > 0xA0) {
            M2C_FIELD(arg0, s16 *, 0xA) = 0xA0;
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0xA) = func_0207ca38(4, M2C_FIELD(arg0, s16 *, 8), 0, M2C_FIELD(arg0, u16 *, 4), 8);
    }
    temp_r0_2 = M2C_FIELD(arg0, u16 *, 4);
    if (temp_r0_2 == 8) {
        if (M2C_FIELD(arg0, u8 *, 0x12) != 0) {
            return;
        }
        temp_r0_3 = M2C_FIELD(arg0, u16 *, 6);
        if ((s32) temp_r0_3 < 4) {
            M2C_FIELD(arg0, u16 *, 6) = (u16) (temp_r0_3 + 1);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0xC) = (u8) M2C_FIELD(arg0, u8 *, 0xE);
        M2C_FIELD(arg0, u8 *, 0xD) = (u8) M2C_FIELD(arg0, u8 *, 0xF);
        M2C_FIELD(arg0, s16 *, 8) = (s16) M2C_FIELD(arg0, s16 *, 0xA);
        M2C_FIELD(arg0, u16 *, 4) = 0U;
        M2C_FIELD(arg0, u16 *, 6) = 0U;
        if (M2C_FIELD(arg0, u8 *, 0xE) == 0x63) {
            return;
        }
        M2C_FIELD(arg0, s8 *, 0x13) = 1;
        M2C_FIELD(arg0, u8 *, 0x12) = 1U;
        return;
    }
    M2C_FIELD(arg0, u16 *, 4) = (u16) (temp_r0_2 + 1);
}

void *func_020abdac(void *arg0) {
 extern M2C_UNK data_02126be4;
 void *p;
 M2C_FIELD(arg0,M2C_UNK **,0)=&data_02126be4;
 p=M2C_FIELD(arg0,void **,0x64);
 if(p!=NULL) {func_020e35cc(M2C_FIELD(p,s32 *,0x14));func_02082040(p);}
 func_02082040(arg0);return arg0;
}

void *func_020abdec(void *arg0) {
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK data_02126be4;
    void *temp_r4;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_02126be4;
    temp_r4 = M2C_FIELD(arg0, void **, 0x64);
    if (temp_r4 != NULL) {
        func_020e35cc(M2C_FIELD(temp_r4, s32 *, 0x14));
        func_02082040(temp_r4);
    }
    return arg0;
}

void func_020abe24(void) {

}

s32 func_020abe28(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_020abe3c(u8 arg0,s8 arg1) {extern s32 data_0212735c; extern s32 data_027e00c8; extern s32 gCur3DSpriteEngine;
u8 a,b,c; a=arg0; if(a==3) {if(gCur3DSpriteEngine==data_027e00c8)b=1;else b=0;if(b!=1)c=1;else c=0;a=c;} M2C_FIELD(data_0212735c+a,s8 *,0)=arg1;}

u8 func_020abe90(u8 arg0) {extern s32 data_0212735c; extern s32 data_027e00c8; extern s32 gCur3DSpriteEngine;
u8 a,b,c; a=arg0; if(a==3) {if(gCur3DSpriteEngine==data_027e00c8)b=1;else b=0;if(b!=1)c=1;else c=0;a=c;} return M2C_FIELD(data_0212735c+a,u8 *,0);}

void func_020abee4(u8 arg0, s8 arg1) {
    extern s32 data_0212735c;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    u8 var_r0;
    u8 var_r0_2;
    u8 var_r0_3;

    var_r0 = arg0;
    if (var_r0 == 3) {
        if (gCur3DSpriteEngine == data_027e00c8) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 != 1) {
            var_r0_3 = 1;
        } else {
            var_r0_3 = 0;
        }
        var_r0 = var_r0_3;
    }
    M2C_FIELD((data_0212735c + var_r0), s8 *, 2) = arg1;
}

u8 func_020abf3c(u8 arg0) {extern s32 data_0212735c; extern s32 data_027e00c8; extern s32 gCur3DSpriteEngine;
u8 a,b,c; a=arg0; if(a==3) {if(gCur3DSpriteEngine==data_027e00c8)b=1;else b=0;if(b!=1)c=1;else c=0;a=c;} return M2C_FIELD(data_0212735c+a,u8 *,2);}

void func_020abf94(void) {
 void func_020abe3c(u8,s8); void func_020abee4(u8,s8);
 s32 i=0; do {func_020abe3c(i,1);func_020abee4(i,0);i++;}while(i<2);
}

void func_020abfcc(u16 arg0, u16 arg1) {
    s32 func_0207ca38(s32, s32, s32, s32, s32);
    void func_020aca8c(s32);
    extern s32 gCur3DSpriteEngine;
    s32 a;
    s32 c;

    a = func_0207ca38(0, 0, 0x100, arg0, arg1);
    c = func_0207ca38(0, 0, 0xc0, arg0, arg1);
    if (a == 0 || c == 0) {
        func_020aca8c(2);
        return;
    }
    if (a >= 0x100) {
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x48) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4a) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x49) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4b) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4c) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4e) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4d) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4f) = 0;
    } else {
        u8 b0 = (u8)((a + 0x100) >> 1);
        u8 b1 = (u8)((0x100 - a) >> 1);
        u8 b2 = (u8)((0xc0 - c) >> 1);
        u8 b3 = (u8)((c + 0xc0) >> 1);
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x48) = b0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4a) = 0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x49) = b1;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4b) = b2;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4c) = b0;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4e) = b3;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4d) = b1;
        M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x4f) = 0xc0;
    }
}

M2C_UNK func_020ac144(u8 arg0, s32 arg1, u8 arg2) {
    u8 func_020abf3c(u8);
    void func_020abe3c(u8, s8);
    void func_020abee4(u8, s8);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c8;
    extern s32 data_027e00c4;
    s32 savedEngine;
    s32 i;
    s32 x;
    u16 *volatile sp44;
    u16 *volatile sp48;
    u16 *volatile sp40;
    u16 *volatile sp3c;
    u16 *volatile sp38;
    u16 *volatile sp34;
    u16 *volatile sp30;
    u16 *volatile sp2c;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1c;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    u16 *volatile sp0;

    savedEngine = gCur3DSpriteEngine;

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            gCur3DSpriteEngine = data_027e00c8;
        } else {
            gCur3DSpriteEngine = data_027e00c4;
        }

        if (arg0 == 0 && gCur3DSpriteEngine != data_027e00c8) {
            continue;
        }
        if (arg0 == 1 && gCur3DSpriteEngine != data_027e00c4) {
            continue;
        }
        if (arg0 == 3 && gCur3DSpriteEngine != savedEngine) {
            continue;
        }

        x = func_020abf3c(arg0);
        if (x == 0 || x == 1) {
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x50) = 0;
        } else if (x == 2) {
            sp44 = (u16 *)*(u8 **)gCur3DSpriteEngine;
            *sp44 = *sp44 & ~0x200;

            sp48 = (u16 *)*(u8 **)gCur3DSpriteEngine;
            *sp48 = *sp48 & ~0x400;
        }

        if (arg2 == 0) {
            *(s8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x50) = -16;
        } else if (arg2 == 1) {
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x50) = 0x10;
        } else if (arg2 == 2) {
            sp44 = (u16 *)*(u8 **)gCur3DSpriteEngine;
            *sp44 = *sp44 | 0x200;

            sp40 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp40 = *sp40 & ~1;

            sp3c = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp3c = *sp3c & ~2;

            sp38 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp38 = *sp38 & ~4;

            sp34 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp34 = *sp34 & ~8;

            sp30 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp30 = *sp30 & ~0x10;

            sp2c = (u16 *)*(u8 **)gCur3DSpriteEngine;
            *sp2c = *sp2c | 0x400;

            sp28 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp28 = *sp28 & ~0x100;

            sp24 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp24 = *sp24 & ~0x200;

            sp20 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp20 = *sp20 & ~0x400;

            sp1c = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp1c = *sp1c & ~0x800;

            sp18 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
            *sp18 = *sp18 & ~0x1000;

            sp14 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *sp14 = (*sp14 & ~1) | 1;

            sp10 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *sp10 = *sp10 | 0x2;

            spC = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *spC = *spC | 0x4;

            sp8 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *sp8 = *sp8 | 0x8;

            sp4 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *sp4 = *sp4 | 0x10;

            sp0 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
            *sp0 = *sp0 | 0x20;

            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x48) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4a) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x49) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4b) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4c) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4e) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4d) = 0;
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4f) = 0;
        }

        ((void(*)(u8, s32))func_020abe3c)(arg0, arg1);
        ((void(*)(u8, s32))func_020abee4)(arg0, (s32)arg2);
    }

    gCur3DSpriteEngine = savedEngine;
    return 0;
}

void func_020ac598(s32 arg0) {
    M2C_UNK func_01ff91d8();
    M2C_UNK func_01ff9690();
    M2C_UNK func_01ff9b38();
    switch (arg0) {                                 /* irregular */
    case 0:
        func_01ff91d8();
        return;
    case 1:
        func_01ff9690();
        return;
    default:
        func_01ff9b38();
        return;
    }
}

void func_020ac5c8(void *arg0) {
    M2C_UNK func_01ffaa6c();
    if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
        return;
    }
    func_01ffaa6c();
}

void func_020ac5e0(void *arg0) {
 u8 func_020abf3c(u8); M2C_UNK func_020ac144(u8,s32,u8);
 M2C_FIELD(arg0,u16 *,0x38)=0;
 switch(func_020abf3c(M2C_FIELD(arg0,u8 *,0x3c))) {
 case 0: case 2: if(M2C_FIELD(arg0,s32 *,0x34)==1)M2C_FIELD(arg0,s32 *,0x34)=0; break;
 case 1: if(M2C_FIELD(arg0,s32 *,0x34)==0)M2C_FIELD(arg0,s32 *,0x34)=1;
 if(M2C_FIELD(arg0,s32 *,0x34)==2)M2C_FIELD(arg0,s32 *,0x34)=1; break;
 }
 func_020ac144(M2C_FIELD(arg0,u8 *,0x3c),0,M2C_FIELD(arg0,s32 *,0x34));
}

void func_020ac65c(void *arg0) {
    s32 saved;
    s8 val;
    s8 neg;
    s32 i;
    s32 temp;
    void *bank;
    u8 mode;
    s32 func_0207ca38(s32, s32, s32, s32, s32);
    void func_020abfcc(u16, u16);
    void func_020ac998(s32);
    void func_01ffa6fc(void *);
    void func_020ac598(s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4, data_027e00c8;

    M2C_FIELD(arg0, u16 *, 0x38)++;
    temp = func_0207ca38(0, 0x10, 0, M2C_FIELD(arg0, u16 *, 0x38), M2C_FIELD(arg0, u16 *, 0x3a));
    saved = gCur3DSpriteEngine;
    val = (s8)temp;
    neg = (s8)(-temp);

    i = 0;
    do {
        if (i == 0) bank = (void *)data_027e00c8; else bank = (void *)data_027e00c4;
        gCur3DSpriteEngine = (s32)bank;
        mode = M2C_FIELD(arg0, u8 *, 0x3c);
        if (mode == 0 && bank != (void *)data_027e00c8) goto next;
        if (mode == 1 && bank != (void *)data_027e00c4) goto next;
        if (mode == 3 && bank != (void *)saved) goto next;

        switch (M2C_FIELD(arg0, s32 *, 0x34)) {
        case 0:
            M2C_FIELD(M2C_FIELD(bank, s32 *, 0), s8 *, 0x50) = neg;
            break;
        case 1:
            M2C_FIELD(M2C_FIELD(bank, s32 *, 0), s8 *, 0x50) = val;
            break;
        case 2:
            func_020abfcc(M2C_FIELD(arg0, u16 *, 0x38), M2C_FIELD(arg0, u16 *, 0x3a));
            break;
        }
        if (M2C_FIELD(arg0, u16 *, 0x38) >= M2C_FIELD(arg0, u16 *, 0x3a)) {
            func_020ac998(M2C_FIELD(arg0, s32 *, 0x34) & 0xff);
            func_01ffa6fc(arg0);
        }
    next:
        ++i;
    } while (i < 2);

    gCur3DSpriteEngine = saved;
    if (M2C_FIELD(arg0, s32 *, 0x18) != 1) {
        return;
    }
    func_020ac598(M2C_FIELD(arg0, u8 *, 0x3c));
}

void func_020ac7a0(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x40) == 0) {
        return;
    }
    func_01ffaa6c();
}

void func_020ac7b8(void *arg0) {
    M2C_UNK func_020ac144(u8, M2C_UNK, u8);
    M2C_FIELD(arg0, s16 *, 0x38) = 0;
    func_020ac144(M2C_FIELD(arg0, u8 *, 0x3C), 1, (u8) M2C_FIELD(arg0, s32 *, 0x34));
}

