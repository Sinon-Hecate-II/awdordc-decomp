/* 1 function from 0x021E59E4 to 0x021E5D5C (ov002), found by ds-decomp. */
#include "common.h"

void func_ov002_021e59e4(M2C_UNK arg0) {
    extern M2C_UNK data_ov002_021f2d84;
    extern M2C_UNK gPlayerSettings;
    extern M2C_UNK data_ov002_021f30f8;
    extern M2C_UNK data_027e00c8;
    extern M2C_UNK data_027e00c4;
    M2C_UNK func_02080e30(M2C_UNK, M2C_UNK);
    M2C_UNK func_02080cfc(M2C_UNK, M2C_UNK);
    void func_ov002_021e5988(M2C_UNK, M2C_UNK);
    M2C_UNK func_02007ef4(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_01ff9e44(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020e35cc(M2C_UNK);
    M2C_UNK func_ov002_021e5988_helper = 0;
    M2C_UNK r4 = (M2C_UNK)arg0;
    M2C_UNK r5 = 0;
    M2C_UNK i;

    func_02080e30((M2C_UNK)&data_ov002_021f2d84, 1);
    r5 = func_02080e30((M2C_UNK)&data_ov002_021f2d84, 1);
    func_02080cfc((M2C_UNK)&data_ov002_021f30f8, 0x6000000);

    for (i = 0; i < 0x400; i++) {
        M2C_UNK base = (M2C_UNK)gPlayerSettings;
        M2C_UNK off = i * 2;
        *((M2C_UNK *)((M2C_UNK)gPlayerSettings + (M2C_UNK)0)) = 0;
    }

    func_020e35cc(r5);
    return;
}
