/* 19 functions from 0x0219D724 to 0x0219E6D4 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0219d848(void) {
    /* Collect the indices of type-6 map entries into a list, then install the
       func_ov000_021811e8 callback. */
    extern void **data_027e0058;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern s8 data_ov000_021df824;
    extern M2C_UNK func_ov000_021811e8;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;

    data_ov000_021df658 = &data_ov000_021df824;
    obj = *data_027e0058;
    baseIndex = data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && data_ov000_021b5bfc[type * 0x70 + 0x14] == 6) {
                    out = data_ov000_021df658;
                    data_ov000_021df658 = out + 1;
                    *out = (s8)index;
                }
            }
            index++;
            obj = *data_027e0058;
            stride += 14;
        } while (index < data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = &data_ov000_021df824;
    data_ov000_021df654 = &func_ov000_021811e8;
    *data_ov000_021df580 = 2;
}

void func_ov000_0219d960(void) {
    /* Variant of func_ov000_0219d848 installing func_ov000_02181560. */
    extern void **data_027e0058;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern s8 data_ov000_021df824;
    extern M2C_UNK func_ov000_02181560;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;

    data_ov000_021df658 = &data_ov000_021df824;
    obj = *data_027e0058;
    baseIndex = data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && data_ov000_021b5bfc[type * 0x70 + 0x14] == 6) {
                    out = data_ov000_021df658;
                    data_ov000_021df658 = out + 1;
                    *out = (s8)index;
                }
            }
            index++;
            obj = *data_027e0058;
            stride += 14;
        } while (index < data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = &data_ov000_021df824;
    data_ov000_021df654 = &func_ov000_02181560;
    *data_ov000_021df580 = 2;
}

void func_ov000_0219da78(void) {
    /* Collect the indices of type-6 map entries into a list, then install the
       func_ov000_021812a8 callback. */
    extern void **data_027e0058;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern s8 data_ov000_021df824;
    extern M2C_UNK func_ov000_021812a8;
    s32 index;
    s32 stride;
    s8 *out;
    u16 baseIndex;
    u32 type;
    void *table;
    void *obj;

    data_ov000_021df658 = &data_ov000_021df824;
    obj = *data_027e0058;
    baseIndex = data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)];
    index = baseIndex + 1;
    if (index < baseIndex + 0x33) {
        stride = index * 14;
        do {
            table = (u8 *)obj + 0x59A4;
            type = (u32)(M2C_FIELD(table, u8 *, stride) << 26) >> 26;
            if (type != 0) {
                if (!(M2C_FIELD((u8 *)table + stride, u16 *, 4) & 1) && data_ov000_021b5bfc[type * 0x70 + 0x14] == 6) {
                    out = data_ov000_021df658;
                    data_ov000_021df658 = out + 1;
                    *out = index;
                }
            }
            index++;
            obj = *data_027e0058;
            stride += 14;
        } while (index < data_ov000_021aeef4[M2C_FIELD(obj, u16 *, 0x52A4)] + 0x33);
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = &data_ov000_021df824;
    data_ov000_021df654 = &func_ov000_021812a8;
    *data_ov000_021df580 = 2;
}

void func_ov000_0219db90(void) {
 extern s8 *data_ov000_021df580;
 extern M2C_UNK *data_ov000_021df654;
 extern s8 *data_ov000_021df658;
 extern s8 data_ov000_021df824;
 extern M2C_UNK func_ov000_021855e4;
 data_ov000_021df658 = &data_ov000_021df824;
 *data_ov000_021df658++ = 0x40;
 *data_ov000_021df658 = 0;
 data_ov000_021df658 = &data_ov000_021df824;
 data_ov000_021df654 = &func_ov000_021855e4;
 *data_ov000_021df580 = 2;
}

void func_ov000_0219dbe8(void) {
 extern s8 *data_ov000_021df580;
 extern M2C_UNK *data_ov000_021df654;
 extern s8 *data_ov000_021df658;
 extern s8 data_ov000_021df824;
 extern M2C_UNK func_ov000_0219b3c8;
 data_ov000_021df658 = &data_ov000_021df824;
 *data_ov000_021df658++ = 0x40;
 *data_ov000_021df658 = 0;
 data_ov000_021df658 = &data_ov000_021df824;
 data_ov000_021df654 = &func_ov000_0219b3c8;
 *data_ov000_021df580 = 2;
}

void func_ov000_0219dc40(void) {
 extern s8 *data_ov000_021df580;
 extern M2C_UNK *data_ov000_021df654;
 extern s8 *data_ov000_021df658;
 extern s8 data_ov000_021df824;
 extern M2C_UNK func_ov000_0219a6c8;
 data_ov000_021df658 = &data_ov000_021df824;
 *data_ov000_021df658++ = 0x40;
 *data_ov000_021df658 = 0;
 data_ov000_021df658 = &data_ov000_021df824;
 data_ov000_021df654 = &func_ov000_0219a6c8;
 *data_ov000_021df580 = 2;
}

void func_ov000_0219dc98(void) {
    s8 func_ov000_021a9f30();
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern s8 data_ov000_021df824;
    extern M2C_UNK func_ov000_02181ba4;
    s8 *temp_r3;
    s8 temp_r0;

    data_ov000_021df658 = &data_ov000_021df824;
    temp_r0 = func_ov000_021a9f30();
    if (temp_r0 != 0) {
        temp_r3 = data_ov000_021df658;
        data_ov000_021df658 = temp_r3 + 1;
        *temp_r3 = temp_r0;
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = &data_ov000_021df824;
    data_ov000_021df654 = &func_ov000_02181ba4;
    *data_ov000_021df580 = 2;
}

void func_ov000_0219dd14(void) {
    s8 func_ov000_021aa214();
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern s8 data_ov000_021df824;
    extern M2C_UNK func_ov000_02181c10;
    s8 *temp_r3;
    s8 temp_r0;

    data_ov000_021df658 = &data_ov000_021df824;
    temp_r0 = func_ov000_021aa214();
    if (temp_r0 != 0) {
        temp_r3 = data_ov000_021df658;
        data_ov000_021df658 = temp_r3 + 1;
        *temp_r3 = temp_r0;
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = &data_ov000_021df824;
    data_ov000_021df654 = &func_ov000_02181c10;
    *data_ov000_021df580 = 2;
}

void func_ov000_0219dd90(void) {
 extern s8 *data_ov000_021df580;
 extern M2C_UNK *data_ov000_021df654;
 extern s8 *data_ov000_021df658;
 extern s8 data_ov000_021df824;
 extern M2C_UNK func_ov000_0217d428;
 data_ov000_021df658 = &data_ov000_021df824;
 *data_ov000_021df658++ = 0x40;
 *data_ov000_021df658 = 0;
 data_ov000_021df658 = &data_ov000_021df824;
 data_ov000_021df654 = &func_ov000_0217d428;
 *data_ov000_021df580 = 2;
}

void func_ov000_0219dde8(void) {
 extern s8 *data_ov000_021df580;
 extern M2C_UNK *data_ov000_021df654;
 extern s8 *data_ov000_021df658;
 extern s8 data_ov000_021df824;
 extern M2C_UNK func_ov000_0217d6dc;
 data_ov000_021df658 = &data_ov000_021df824;
 *data_ov000_021df658++ = 0x40;
 *data_ov000_021df658 = 0;
 data_ov000_021df658 = &data_ov000_021df824;
 data_ov000_021df654 = &func_ov000_0217d6dc;
 *data_ov000_021df580 = 2;
}

void func_ov000_0219de40(void) {
 extern s8 *data_ov000_021df580;
 extern M2C_UNK *data_ov000_021df654;
 extern s8 *data_ov000_021df658;
 extern s8 data_ov000_021df824;
 extern M2C_UNK func_ov000_0217d850;
 data_ov000_021df658 = &data_ov000_021df824;
 *data_ov000_021df658++ = 0x40;
 *data_ov000_021df658 = 0;
 data_ov000_021df658 = &data_ov000_021df824;
 data_ov000_021df654 = &func_ov000_0217d850;
 *data_ov000_021df580 = 2;
}

/* Collects eligible slot indices into the slot list buffer, then installs the
   corresponding handler callback and switches the mode to 2. */
void func_ov000_0219e214(void) {
    void func_ov000_0219c9e8(s32);
    extern void **data_027e0058;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern s8 data_ov000_021df824;
    extern M2C_UNK func_ov000_02181838;
    s32 slotIndex;
    s32 stride;
    s8 *outputPtr;
    u16 countBase;
    u32 entryId;
    u8 flags;
    void *entry;
    void *entry2;
    void *gameState;

    data_ov000_021df658 = &data_ov000_021df824;
    gameState = *data_027e0058;
    countBase = data_ov000_021aeef4[M2C_FIELD(gameState,u16 *,0x52A4)];
    slotIndex = countBase + 1;
    if (slotIndex < countBase + 0x33) {
        stride = slotIndex * 14;
        do {
            entry = (u8 *)gameState + 0x59A4;
            entry2 = (u8 *)entry + stride;
            entryId = (u32)(M2C_FIELD(entry,u8 *,stride) << 26) >> 26;
            if (entryId != 0) {
                if (!(M2C_FIELD(entry2,u16 *,4) & 1) && data_ov000_021b5bfc[entryId * 0x70 + 0x14] == 2) {
                    flags = M2C_FIELD(entry2,u8 *,0xC);
                    if (flags != 0 && ((u32)(M2C_FIELD((u8 *)gameState + flags * 14,u8 *,0x59AF) << 28) >> 28) == 0) {
                        outputPtr = data_ov000_021df658;
                        data_ov000_021df658 = outputPtr + 1;
                        *outputPtr = slotIndex;
                    }
                }
            }
            slotIndex++;
            gameState = *data_027e0058;
            stride += 14;
        } while (slotIndex < data_ov000_021aeef4[M2C_FIELD(gameState,u16 *,0x52A4)] + 0x33);
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = &data_ov000_021df824;
    func_ov000_0219c9e8(0);
    data_ov000_021df654 = &func_ov000_02181838;
    *data_ov000_021df580 = 2;
}

/* Collects eligible slot indices into the slot list buffer, then installs the
   corresponding handler callback and switches the mode to 2. */
void func_ov000_0219e358(void) {
    void func_ov000_0219c9e8(s32);
    extern void **data_027e0058;
    extern u16 data_ov000_021aeef4[];
    extern u8 data_ov000_021b5bfc[];
    extern s8 *data_ov000_021df580;
    extern M2C_UNK *data_ov000_021df654;
    extern s8 *data_ov000_021df658;
    extern s8 data_ov000_021df824;
    extern M2C_UNK func_ov000_0218190c;
    s32 slotIndex;
    s32 stride;
    s8 *outputPtr;
    u16 countBase;
    u32 entryId;
    u8 flags;
    void *entry;
    void *entry2;
    void *gameState;

    data_ov000_021df658 = &data_ov000_021df824;
    gameState = *data_027e0058;
    countBase = data_ov000_021aeef4[M2C_FIELD(gameState,u16 *,0x52A4)];
    slotIndex = countBase + 1;
    if (slotIndex < countBase + 0x33) {
        stride = slotIndex * 14;
        do {
            entry = (u8 *)gameState + 0x59A4;
            entry2 = (u8 *)entry + stride;
            entryId = (u32)(M2C_FIELD(entry,u8 *,stride) << 26) >> 26;
            if (entryId != 0) {
                if (!(M2C_FIELD(entry2,u16 *,4) & 1) && data_ov000_021b5bfc[entryId * 0x70 + 0x14] == 2) {
                    flags = M2C_FIELD(entry2,u8 *,0xC);
                    if (flags != 0 && ((u32)(M2C_FIELD((u8 *)gameState + flags * 14,u8 *,0x59AF) << 28) >> 28) == 0) {
                        outputPtr = data_ov000_021df658;
                        data_ov000_021df658 = outputPtr + 1;
                        *outputPtr = slotIndex;
                    }
                }
            }
            slotIndex++;
            gameState = *data_027e0058;
            stride += 14;
        } while (slotIndex < data_ov000_021aeef4[M2C_FIELD(gameState,u16 *,0x52A4)] + 0x33);
    }
    *data_ov000_021df658 = 0;
    data_ov000_021df658 = &data_ov000_021df824;
    func_ov000_0219c9e8(0);
    data_ov000_021df654 = &func_ov000_0218190c;
    *data_ov000_021df580 = 2;
}

