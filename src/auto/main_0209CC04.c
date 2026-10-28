/* 65 functions from 0x0209CC04 to 0x0209DB48 (main), found by ds-decomp. */
#include "common.h"

void func_0209cc04(void) {
 extern M2C_UNK data_021581a8;
 extern s32 data_021581ac[];
 extern void *data_021581dc[];
 extern M2C_UNK data_021583e0;
 u8 *p;
 s32 i;
 s32 j;
 i = 0;
 p = (u8 *)&data_021583e0;
  do {
 M2C_FIELD(p, s32 *, 0) = 0;
M2C_FIELD(p, s32 *, 4) = 0;
M2C_FIELD(p, s32 *, 8) = 0;
M2C_FIELD(p, s32 *, 12) = 0;
M2C_FIELD(p, s32 *, 16) = 0;
M2C_FIELD(p, s32 *, 20) = 0;
M2C_FIELD(p, s32 *, 24) = 0;
M2C_FIELD(p, s32 *, 28) = 0;
M2C_FIELD(p, s32 *, 32) = 0;
M2C_FIELD(p, s32 *, 36) = 0;
M2C_FIELD(p, s32 *, 40) = 0;
 M2C_FIELD(p, s16 *, 0x2c) = 0;
 M2C_FIELD(p, u16 *, 0x2e) = 0xff00;
 M2C_FIELD(p, s8 *, 0x30) = 1;
 data_021581dc[i] = p;
 i++;
 M2C_FIELD(p, s8 *, 0x31) = 0;
 p += 0x74;
 } while(i < 0x80);
 M2C_FIELD(&data_021581a8, s32 *, 0x234) = 0;
 M2C_FIELD(&data_021581a8, void **, 0) = &data_021581dc;
 j = 0;
 do {
 data_021581ac[j] = 0;
 j++;
 } while(j < 12);
}

void func_0209cca8(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 0x34)(arg0);
}

void func_0209ccb8(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *);
    extern M2C_UNK data_0211e010;
    M2C_FIELD(func_01ffa3dc(&data_0211e010), s32 *, 0x34) = arg0;
}

void func_0209ccd4(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 0x34)(arg0);
}

void func_0209cce4(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *);
    extern M2C_UNK data_0211dff0;
    M2C_FIELD(func_01ffa3dc(&data_0211dff0), s32 *, 0x34) = arg0;
}

void func_0209cd00(s32 arg0) {
 M2C_UNK func_01ffa574();
 extern M2C_UNK data_0211dff0;
 extern M2C_UNK data_021583e0;
 u8 *p;
 s32 i;
 p = (u8 *)&data_021583e0;
 i = 0;
 do {
  if (M2C_FIELD(p, void **, 4) == &data_0211dff0 && M2C_FIELD(p, s32 *, 0x34) == arg0) func_01ffa574(p);
  i++;
  p += 0x74;
 } while (i < 0x80);
}

s32 func_0209cd4c(void) {
    M2C_UNK func_01ffa574();
    func_01ffa574();
    return 0;
}

s32 func_0209cd5c(void) {
    return 0;
}

s32 func_0209cd64(void) {
    return 1;
}

s32 func_0209cd6c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 8);
    return 1;
}

s32 func_0209cd80(void *arg0) {
    M2C_UNK func_01ffa918(void *, s32);
    func_01ffa918(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209cda8(void *arg0) {
    M2C_UNK func_01ffa920(void *, s32);
    func_01ffa920(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209cdd0(void *arg0) {
    void *temp_r1;
    M2C_UNK (*fn)();

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    fn = M2C_FIELD(temp_r1, M2C_UNK (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r1 + 8);
    fn(arg0);
    return 1;
}

s32 func_0209cdf0(void *arg0) {
    void *temp_r2;
    s16 value;
    M2C_UNK (*fn)();

    temp_r2 = M2C_FIELD(arg0, void **, 8);
    value = M2C_FIELD(temp_r2, s16 *, 2);
    fn = M2C_FIELD(temp_r2, M2C_UNK (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r2 + 8);
    fn(arg0, value);
    return 1;
}

s32 func_0209ce14(void *arg0) {
    void *temp_r1;
    s32 (*fn)();

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    fn = M2C_FIELD(temp_r1, s32 (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r1 + 8);
    if (fn(arg0) == 0) {
        return 1;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) - 8);
    return 0;
}

s32 func_0209ce50(void *arg0) {
    void *temp_r2;
    s16 value;
    s32 (*fn)();

    temp_r2 = M2C_FIELD(arg0, void **, 8);
    value = M2C_FIELD(temp_r2, s16 *, 2);
    fn = M2C_FIELD(temp_r2, s32 (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r2 + 8);
    if (fn(arg0, value) == 0) {
        return 1;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) - 8);
    return 0;
}

s32 func_0209ce90(void *arg0) {
    void *temp_r1;
    s32 (*fn)();

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    fn = M2C_FIELD(temp_r1, s32 (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r1 + 8);
    if (fn(arg0) != 0) {
        return 1;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) - 8);
    return 0;
}

s32 func_0209cecc(void *arg0) {
    void *temp_r2;
    s16 value;
    s32 (*fn)();

    temp_r2 = M2C_FIELD(arg0, void **, 8);
    value = M2C_FIELD(temp_r2, s16 *, 2);
    fn = M2C_FIELD(temp_r2, s32 (**)(), 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (temp_r2 + 8);
    if (fn(arg0, value) != 0) {
        return 1;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) - 8);
    return 0;
}

s32 func_0209cf0c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4);
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 0;
}

s32 func_0209cf2c(void *arg0) {
    s32 func_01ffa770(s32);
    if (func_01ffa770(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4)) != 0) {
        return 0;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209cf60(void *arg0) {
    func_01ffa3dc(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4), arg0);
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209cf8c(void *arg0) {
    M2C_UNK func_01ffa42c(s32, void *);
    func_01ffa42c(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4), arg0);
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 0;
}

s32 func_0209cfb8(void *arg0) {
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 8);
    func_01ffa3dc(M2C_FIELD(temp_r0, s32 *, 4), M2C_FIELD(temp_r0, s16 *, 2));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209cfe4(void *arg0) {
    M2C_UNK func_01ffa9e4(s32);
    M2C_UNK func_01ffa9f8(s32);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(temp_r1, s16 *, 2) != 0) {
        func_01ffa9f8(M2C_FIELD(temp_r1, s32 *, 4));
    } else {
        func_01ffa9e4(M2C_FIELD(temp_r1, s32 *, 4));
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d020(void *arg0) {
    M2C_UNK func_01ffa9bc(s32);
    M2C_UNK func_01ffa9d0(s32);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(temp_r1, s16 *, 2) != 0) {
        func_01ffa9d0(M2C_FIELD(temp_r1, s32 *, 4));
    } else {
        func_01ffa9bc(M2C_FIELD(temp_r1, s32 *, 4));
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d05c(void *arg0) {
    M2C_UNK func_01ffa8c4(void *, s16);
    func_01ffa8c4(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2));
    return 1;
}

s32 func_0209d074(void *arg0) {
    s32 (*func)(void *);
    func = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 (**)(void *), 4);
    if (func == NULL || func(arg0) != 0) {
        func_01ffa8c4(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2));
    } else {
        M2C_FIELD(arg0, void **, 8) += 8;
    }
    return 1;
}

s32 func_0209d0c0(void *arg0) {
    s32 (*func)(void *);
    func = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 (**)(void *), 4);
    if (func == NULL || func(arg0) == 0) {
        func_01ffa8c4(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2));
    } else {
        M2C_FIELD(arg0, void **, 8) += 8;
    }
    return 1;
}

s32 func_0209d10c(void *arg0) {
    M2C_UNK func_01ffa904(void *, s32);
    func_01ffa904(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    return 1;
}

void func_0209d124(void *arg0) {
    void func_01ffa6fc(void *);
    M2C_FIELD(arg0, s16 *, 0x2C)--;
    if (M2C_FIELD(arg0, s16 *, 0x2C) > 0) return;
    func_01ffa6fc(arg0);
}

s32 func_0209d148(void *arg0) {
    void func_0209d124(void *);
    s16 temp_r2;

    temp_r2 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2);
    if (temp_r2 != 0) {
        M2C_FIELD(arg0, s16 *, 0x2C) = temp_r2;
        M2C_FIELD(arg0, void (**)(void *), 0x10) = &func_0209d124;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 0;
}

void func_0209d178(void *arg0) {
    void func_01ffa6fc(void *);
    extern u16 *data_02101e84;
    extern void *data_02101e88;
    M2C_FIELD(arg0, s16 *, 0x2C)--;
    if (M2C_FIELD(arg0, s16 *, 0x2C) <= 0) {
        func_01ffa6fc(arg0);
        return;
    }
    if (*data_02101e84 == 0 && M2C_FIELD(data_02101e88, u8 *, 0x14) == 0) return;
    func_01ffa6fc(arg0);
}

s32 func_0209d1d4(void *arg0) {
    void func_0209d178(void *);
    s16 temp_r2;

    temp_r2 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2);
    if (temp_r2 != 0) {
        M2C_FIELD(arg0, s16 *, 0x2C) = temp_r2;
        M2C_FIELD(arg0, void (**)(void *), 0x10) = &func_0209d178;
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 0;
}

s32 func_0209d204(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2E) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2);
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d224(void *arg0) {
    extern M2C_UNK data_021581a8;
    extern void *data_021581dc[];
    extern s32 gCur3DSpriteEngine;
    void **p;
    p = data_021581dc;
    for (; p < M2C_FIELD(&data_021581a8, void ***, 0); p++) {
        void *other = *p;
        if (other != arg0 && M2C_FIELD(other, s32 *, 4) == M2C_FIELD(arg0, s32 *, 4)) {
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2) == 0 || M2C_FIELD(other, s32 *, 0x28) == gCur3DSpriteEngine) {
                func_01ffa574(arg0);
                return 0;
            }
        }
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 1;
}

s32 func_0209d2b0(void *arg0) {
    extern M2C_UNK data_021581a8;
    extern void *data_021581dc[];
    extern s32 gCur3DSpriteEngine;
    void **p;
    p = data_021581dc;
    for (; p < M2C_FIELD(&data_021581a8, void ***, 0); p++) {
        void *other = *p;
        if (other != arg0 && M2C_FIELD(other, s32 *, 4) == M2C_FIELD(arg0, s32 *, 4)) {
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2) == 0 || M2C_FIELD(other, s32 *, 0x28) == gCur3DSpriteEngine) {
                func_01ffa574(arg0);
                return 0;
            }
        }
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 1;
}

s32 func_0209d33c(void *arg0) {
    extern M2C_UNK data_021581a8;
    extern void *data_021581dc[];
    extern s32 gCur3DSpriteEngine;
    void **p;
    p = data_021581dc;
    for (; p < M2C_FIELD(&data_021581a8, void ***, 0); p++) {
        void *other = *p;
        if (other != arg0 && M2C_FIELD(other, s32 *, 4) == M2C_FIELD(arg0, s32 *, 4)) {
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2) == 0 || M2C_FIELD(other, s32 *, 0x28) == gCur3DSpriteEngine) {
                func_01ffa574(other);
                break;
            }
        }
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 1;
}

s32 func_0209d3c8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 8);
    return 1;
}

s32 func_0209d3dc(void *arg0) {
    void func_020ad150(s32, u16, s32, void *);
    void func_020ad2a0(s32, u16, s32, void *);
    void *cmd = M2C_FIELD(arg0, void **, 8);
    s32 mode = 3;
    s32 flags = M2C_FIELD(cmd, s32 *, 4);
    s16 value = M2C_FIELD(cmd, s16 *, 2);
    if (flags & 1) mode = 0;
    if (flags & 2) mode = 1;
    if (flags & 4) mode = 2;
    if (flags & 8) func_020ad2a0(2, (u16)value, mode, arg0);
    else func_020ad150(2, (u16)value, mode, arg0);
    M2C_FIELD(arg0, void **, 8) += 8;
    return 1;
}

s32 func_0209d44c(void *arg0) {
    void func_020ad1f8(s32, u16, s32, void *);
    void func_020ad348(s32, u16, s32, void *);
    void *cmd = M2C_FIELD(arg0, void **, 8);
    s32 mode = 3;
    s32 flags = M2C_FIELD(cmd, s32 *, 4);
    s16 value = M2C_FIELD(cmd, s16 *, 2);
    if (flags & 1) mode = 0;
    if (flags & 2) mode = 1;
    if (flags & 4) mode = 2;
    if (flags & 8) func_020ad348(2, (u16)value, mode, arg0);
    else func_020ad1f8(2, (u16)value, mode, arg0);
    M2C_FIELD(arg0, void **, 8) += 8;
    return 1;
}

s32 func_0209d4bc(void *arg0) {
    void func_020ad150(s32, u16, s32, void *);
    void func_020ad2a0(s32, u16, s32, void *);
    void *cmd = M2C_FIELD(arg0, void **, 8);
    s32 mode = 3;
    s32 flags = M2C_FIELD(cmd, s32 *, 4);
    s16 value = M2C_FIELD(cmd, s16 *, 2);
    if (flags & 1) mode = 0;
    if (flags & 2) mode = 1;
    if (flags & 4) mode = 2;
    if (flags & 8) func_020ad2a0(0, (u16)value, mode, arg0);
    else func_020ad150(0, (u16)value, mode, arg0);
    M2C_FIELD(arg0, void **, 8) += 8;
    return 1;
}

s32 func_0209d52c(void *arg0) {
    void func_020ad1f8(s32, u16, s32, void *);
    void func_020ad348(s32, u16, s32, void *);
    void *cmd = M2C_FIELD(arg0, void **, 8);
    s32 mode = 3;
    s32 flags = M2C_FIELD(cmd, s32 *, 4);
    s16 value = M2C_FIELD(cmd, s16 *, 2);
    if (flags & 1) mode = 0;
    if (flags & 2) mode = 1;
    if (flags & 4) mode = 2;
    if (flags & 8) func_020ad348(0, (u16)value, mode, arg0);
    else func_020ad1f8(0, (u16)value, mode, arg0);
    M2C_FIELD(arg0, void **, 8) += 8;
    return 1;
}

s32 func_0209d59c(void *arg0) {
    void func_020ad150(s32, u16, s32, void *);
    void func_020ad2a0(s32, u16, s32, void *);
    void *cmd = M2C_FIELD(arg0, void **, 8);
    s32 mode = 3;
    s32 flags = M2C_FIELD(cmd, s32 *, 4);
    s16 value = M2C_FIELD(cmd, s16 *, 2);
    if (flags & 1) mode = 0;
    if (flags & 2) mode = 1;
    if (flags & 4) mode = 2;
    if (flags & 8) func_020ad2a0(1, (u16)value, mode, arg0);
    else func_020ad150(1, (u16)value, mode, arg0);
    M2C_FIELD(arg0, void **, 8) += 8;
    return 1;
}

s32 func_0209d60c(void *arg0) {
    void func_020ad1f8(s32, u16, s32, void *);
    void func_020ad348(s32, u16, s32, void *);
    void *cmd = M2C_FIELD(arg0, void **, 8);
    s32 mode = 3;
    s32 flags = M2C_FIELD(cmd, s32 *, 4);
    s16 value = M2C_FIELD(cmd, s16 *, 2);
    if (flags & 1) mode = 0;
    if (flags & 2) mode = 1;
    if (flags & 4) mode = 2;
    if (flags & 8) func_020ad348(1, (u16)value, mode, arg0);
    else func_020ad1f8(1, (u16)value, mode, arg0);
    M2C_FIELD(arg0, void **, 8) += 8;
    return 1;
}

s32 func_0209d67c(void *arg0) {
    M2C_UNK func_0208f780(s32);
    func_0208f780(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d6a4(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d6cc(void *arg0) {
    M2C_UNK func_0208ffe4(M2C_UNK, M2C_UNK, s32);
    func_0208ffe4(0, -1, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d6fc(void *arg0) {
    M2C_UNK func_02090034(M2C_UNK, s16);
    func_02090034(0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d728(void *arg0) {
    M2C_UNK func_0208f844(s16);
    func_0208f844(M2C_FIELD(M2C_FIELD(arg0, void **, 8), s16 *, 2));
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d750(void *arg0) {
    void func_02086608(u8);
    void func_02086658(u8);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(temp_r1, s32 *, 4) != 0) {
        func_02086608(M2C_FIELD(temp_r1, s16 *, 2));
    } else {
        func_02086658(M2C_FIELD(temp_r1, s16 *, 2));
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

s32 func_0209d790(void *arg0) {
    s32 func_020866fc(s32);
    M2C_UNK func_020926f8(s32);
    M2C_UNK func_02092888(void *);
    M2C_UNK func_020945f8();
    s32 temp_r4;

    temp_r4 = M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 4);
    if (func_020866fc(temp_r4) != 0) {
        func_020945f8();
        func_020926f8(temp_r4);
        func_02092888(arg0);
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 0;
}

s32 func_0209d7d8(void *arg0) {
    void func_020883f0(u8);
    void func_020884f8(u8);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    if (M2C_FIELD(temp_r1, s32 *, 4) != 0) {
        func_020883f0(M2C_FIELD(temp_r1, s16 *, 2));
    } else {
        func_020884f8(M2C_FIELD(temp_r1, s16 *, 2));
    }
    M2C_FIELD(arg0, void **, 8) = (void *) (M2C_FIELD(arg0, void **, 8) + 8);
    return 1;
}

void func_0209d818(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_0208999c(void *, u8, s32);
    void func_020899cc(void *, u8, s32, s32);
    if (arg3 < 0) func_0208999c(arg0, (u8)arg1, arg2);
    else func_020899cc(arg0, (u8)arg1, arg3 << 5, arg2);
    M2C_FIELD(arg0, s32 *, 0x58) |= 0x1000;
}

s32 func_0209d858(void *arg0) {
    void *func_0208b520(void *);
    void func_0209d818(void *, s32, s32, s32);
    s32 id;
    s16 value;
    void *cmd;
    void *obj;
    cmd = M2C_FIELD(arg0, void **, 8);
    id = M2C_FIELD(cmd, s32 *, 4);
    value = M2C_FIELD(cmd, s16 *, 2);
    if (func_020866fc(id) != 0) {
        obj = func_0208b520(arg0);
        func_0209d818(obj, 0, id, value);
        M2C_FIELD(obj, s32 *, 0x58) = M2C_FIELD(obj, s32 *, 0x58) | 0xC00;
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 0;
}

s32 func_0209d8b8(void *arg0) {
    void *func_0208b520(void *);
    void func_0209d818(void *, s32, s32, s32);
    s32 id;
    s16 value;
    void *cmd;
    void *obj;
    cmd = M2C_FIELD(arg0, void **, 8);
    id = M2C_FIELD(cmd, s32 *, 4);
    value = M2C_FIELD(cmd, s16 *, 2);
    if (func_020866fc(id) != 0) {
        obj = func_0208b520(arg0);
        func_0209d818(obj, 0, id, value);
        M2C_FIELD(obj, s32 *, 0x58) = (M2C_FIELD(obj, s32 *, 0x58) | 0x800) & ~0x400;
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 0;
}

s32 func_0209d91c(void *arg0) {
    void *func_0208b564(void *);
    void func_0209d818(void *, s32, s32, s32);
    s32 id;
    s16 value;
    void *cmd;
    void *obj;
    cmd = M2C_FIELD(arg0, void **, 8);
    id = M2C_FIELD(cmd, s32 *, 4);
    value = M2C_FIELD(cmd, s16 *, 2);
    if (func_020866fc(id) != 0) {
        obj = func_0208b564(arg0);
        func_0209d818(obj, 2, id, value);
        M2C_FIELD(obj, s32 *, 0x58) |= 0x400;
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 0;
}

s32 func_0209d97c(void *arg0) {
    void *func_0208b564(void *);
    void func_0209d818(void *, s32, s32, s32);
    s32 id;
    s16 value;
    void *cmd;
    void *obj;
    cmd = M2C_FIELD(arg0, void **, 8);
    id = M2C_FIELD(cmd, s32 *, 4);
    value = M2C_FIELD(cmd, s16 *, 2);
    if (func_020866fc(id) != 0) {
        obj = func_0208b564(arg0);
        func_0209d818(obj, 1, id, value);
        M2C_FIELD(obj, s32 *, 0x58) |= 0x400;
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 0;
}

s32 func_0209d9dc(void *arg0) {
    void *func_0208b564(void *);
    void func_0209d818(void *, s32, s32, s32);
    s32 id;
    s16 value;
    void *cmd;
    void *obj;
    cmd = M2C_FIELD(arg0, void **, 8);
    id = M2C_FIELD(cmd, s32 *, 4);
    value = M2C_FIELD(cmd, s16 *, 2);
    if (func_020866fc(id) != 0) {
        obj = func_0208b564(arg0);
        func_0209d818(obj, 3, id, value);
        M2C_FIELD(obj, s32 *, 0x58) |= 0x400;
    }
    M2C_FIELD(arg0, void **, 8) += 8;
    return 0;
}

s32 func_0209da3c(void *arg0) {
    M2C_UNK func_0208af20();
    s32 func_0208b5ec();
    if (func_0208b5ec() != 0) {
        func_0208af20();
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 8);
    return 0;
}

s32 func_0209da68(void *arg0) {
    s32 func_0208b5c4();
    if (func_0208b5c4() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 8);
    }
    return 0;
}

void func_0209da8c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
}

void func_0209da98(void *arg0) {
    s32 count;
    count = M2C_FIELD(arg0, s32 *, 0x5c) + 1;
    M2C_FIELD(arg0, s32 *, 0x5c) = count;
    if (count < M2C_FIELD(arg0, s32 *, 0x60)) return;
    func_01ffa574(arg0);
}

void func_0209dabc(s32 arg0) {
    extern M2C_UNK data_0211e030;
    M2C_FIELD(func_01ffa3dc(&data_0211e030), s32 *, 0x60) = arg0;
}

void func_0209dad8(void **arg0) {
 M2C_FIELD(*arg0, void (**)(void *), 8)(arg0);
}

void func_0209daec(void) {
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    s32 saved;
    s32 i;
    s32 obj;
    saved = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) obj = data_027e00c8;
        else obj = data_027e00c4;
        gCur3DSpriteEngine = obj;
        M2C_FIELD(obj, s32 *, 8) = 0;
        M2C_FIELD(gCur3DSpriteEngine, s8 *, 0x49) = 0;
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = saved;
}

