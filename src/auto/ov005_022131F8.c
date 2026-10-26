/* 12 functions from 0x022131F8 to 0x022141CC (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_0221339c(u8 *arg0) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_ov005_02211a8c();
    extern void *data_ov005_02221300;
    M2C_FIELD(data_ov005_02221300, u8 *, 2) = (u8) *arg0;
    func_ov005_02211a8c();
    func_0208fe30(0x10019);
}

void func_ov005_02213cf4(void) {
    M2C_UNK func_020b2224();
    M2C_UNK func_020b1bf4(s32, s32, s32, s32);
    M2C_UNK func_020b1c78(s32);
    M2C_UNK func_020b22a4(s32, s32, M2C_UNK *, s32);
    void *func_ov005_02211a38(s32);
    extern M2C_UNK data_ov005_022201e0;
    s32 var_r4;
    s32 var_r6;
    s32 var_r7;
    s32 var_r8;
    func_020b2224();
    func_020b1bf4(0, -0x10, 0x100, -0x10);
    var_r4 = 0;
    do {
        if (M2C_FIELD(func_ov005_02211a38(var_r4), s16 *, 8) > var_r6) {
            var_r6 = M2C_FIELD(func_ov005_02211a38(var_r4), s16 *, 8);
        }
        var_r4++;
    } while (var_r4 < 3);
    var_r8 = 0;
    if (var_r6 > 0) {
        var_r7 = 0x28;
loop:
        if (var_r8 != 7) {
            func_020b22a4(4, var_r7, &data_ov005_022201e0, var_r8);
            var_r8++;
            var_r7 += 0x10;
            if (var_r8 < var_r6) goto loop;
        }
    }
    func_020b1c78(0);
}

void func_ov005_02214094(void) {
    M2C_UNK func_020af1e4();
    M2C_UNK func_020842d4();
    M2C_UNK func_020b2178();
    M2C_UNK func_020e35cc();
    extern void *data_ov005_02221300;
    func_020af1e4();
    func_020842d4();
    func_020b2178();
    if (data_ov005_02221300 == NULL) return;
    func_020e35cc();
    data_ov005_02221300 = NULL;
}

void func_ov005_022140cc(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220208;
    func_01ffa42c(&data_ov005_02220208, arg0);
}

void func_ov005_022140e4(void) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    extern M2C_UNK data_ov005_02220644;
    func_0200bc5c(&data_ov005_02220644);
}

s32 func_ov005_022140f8(s32 arg0) {
    s32 func_020ad658(s32);
    extern M2C_UNK data_ov005_02221304;
    if (*M2C_FIELD(&data_ov005_02221304, u16 **, 8) & 2) return 1;
    return func_020ad658(arg0);
}

s32 func_ov005_02214120(s32 arg0) {
    s32 func_020ad61c(s32);
    extern M2C_UNK data_ov005_02221304;
    if (*M2C_FIELD(&data_ov005_02221304, u16 **, 8) & 2) return 1;
    return func_020ad61c(arg0);
}

s32 func_ov005_02214148(void) {
    extern M2C_UNK data_ov005_02221304;
    s16 temp_r1;

    temp_r1 = M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98);
    if (temp_r1 == 0) {
        return 0;
    }
    M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) = (s16) (temp_r1 - 1);
    func_0208fe30(0x10019);
    return 1;
}

s16 func_ov005_02214184(void) {
    extern M2C_UNK data_ov005_02221304;
    s16 temp_r3;
    temp_r3 = M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98);
    M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) = (s16)(temp_r3 - 6);
    if (M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) < 0) {
        M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) = 0;
    }
    return (s16)(M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) - temp_r3);
}

