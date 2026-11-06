#include "common.h"

void func_020d6e0c(s32 arg0, u8 arg1, s32 arg3) {
    // Simplified version without complex bit shifts
    if (arg3 == 0) {
        func_01ffaacc(arg0 & 0x1FF, arg1 + 0x18, 0x400, &data_02101f1c, 0xA);
        func_01ffaacc((arg0 + 0x40) & 0x1FF, arg1 + 0x18, 0x400, &data_027e0064, 0xA);
        func_01ffaacc((arg0 + 0x50) & 0x1FF, arg1 + 0x18, 0x400, &data_027e006c, 0xA);
        func_01ffaacc(arg1 + 0x28, 0x400, &data_02101f0c, 0xA);
        func_01ffaacc((arg0 + 0x40) & 0x1FF, arg1 + 0x28, 0x400, &data_027e00a4, 0xA);
        func_01ffaacc((arg0 + 0x50) & 0x1FF, arg1 + 0x28, 0x400, &data_027e0084, 0xA);
    } else {
        func_01ffaacc(arg0 & 0x1FF, arg1 + 0x400, &data_027e00b4, 0xA);
        func_01ffaacc((arg0 + 0x40) & 0x1FF, arg1 + 0x400, &data_027e0074, 0xA);
        func_01ffaacc((arg0 + 0x50) & 0x1FF, arg1 + 0x400, &data_027e009c, 0xA);
        func_01ffaacc(arg1 + 0x20, 0x400, &data_02101f1c, 0xA);
        func_01ffaacc((arg0 + 0x40) & 0x1FF, arg1 + 0x20, &data_027e0064, 0xA);
        func_01ffaacc((arg0 + 0x50) & 0x1FF, arg1 + 0x20, &data_027e006c, 0xA);
    }
}
