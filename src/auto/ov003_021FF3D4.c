/* 7 functions from 0x021FF3D4 to 0x022001EC (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021ff7ac(void) {
    extern M2C_UNK data_ov003_0220fe64;
    void *temp_r0;
    temp_r0 = func_01ffa770(&data_ov003_0220fe64);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(*(void **)temp_r0, void (**)(void *), 0x10)(temp_r0);
}

/* Destructor: releases all owned sub-objects and frees this object. */
void *func_ov003_021ff7d4(void *obj) {
    void func_01ffa574(void *);
    void func_02082040(void *);
    void func_020c127c(void);
    void func_020e35cc(s32);
    void func_ov003_021f140c(s32);
    void func_ov003_021f1920(void);
    void func_ov003_021f1a58(void);
    extern M2C_UNK data_ov003_02210104, data_ov003_02210130;
    extern M2C_UNK data_ov003_02210158, data_ov003_02210184;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210158;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210184;
    func_ov003_021f1920();
    func_ov003_021f1a58();
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210104;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210130;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        func_020e35cc(M2C_FIELD(sub, s32 *, 0x14));
        func_02082040(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) func_02082040(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) func_02082040(child);
    sub = M2C_FIELD(obj, void **, 104);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        if (M2C_FIELD(sub, void **, 8) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 8));
        if (M2C_FIELD(sub, void **, 12) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 12));
        if (M2C_FIELD(sub, void **, 16) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 16));
        if (M2C_FIELD(sub, void **, 20) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 20));
        if (M2C_FIELD(sub, void **, 24) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 24));
        if (M2C_FIELD(sub, void **, 28) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 28));
        if (M2C_FIELD(sub, void **, 32) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 32));
        if (M2C_FIELD(sub, void **, 36) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 36));
        func_02082040(sub);
    }
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        func_02082040(sub);
    }
    func_ov003_021f140c(4);
    func_020c127c();
    return obj;
}

/* Destructor: releases all owned sub-objects and frees this object. */
void *func_ov003_021ff9dc(void *obj) {
    void func_01ffa574(void *);
    void func_02082040(void *);
    void func_020c127c(void);
    void func_020e35cc(s32);
    void func_ov003_021f140c(s32);
    void func_ov003_021f1920(void);
    void func_ov003_021f1a58(void);
    extern M2C_UNK data_ov003_02210104, data_ov003_02210130;
    extern M2C_UNK data_ov003_02210158, data_ov003_02210184;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210158;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210184;
    func_ov003_021f1920();
    func_ov003_021f1a58();
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210104;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210130;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        func_020e35cc(M2C_FIELD(sub, s32 *, 0x14));
        func_02082040(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) func_02082040(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) func_02082040(child);
    sub = M2C_FIELD(obj, void **, 104);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        if (M2C_FIELD(sub, void **, 8) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 8));
        if (M2C_FIELD(sub, void **, 12) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 12));
        if (M2C_FIELD(sub, void **, 16) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 16));
        if (M2C_FIELD(sub, void **, 20) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 20));
        if (M2C_FIELD(sub, void **, 24) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 24));
        if (M2C_FIELD(sub, void **, 28) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 28));
        if (M2C_FIELD(sub, void **, 32) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 32));
        if (M2C_FIELD(sub, void **, 36) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 36));
        func_02082040(sub);
    }
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        func_02082040(sub);
    }
    func_ov003_021f140c(4);
    func_020c127c();
    func_02082040(obj);
    return obj;
}

/* Releases all owned sub-objects but does not free this object (vtable reset to base first). */
void *func_ov003_021ffbec(void *obj) {
    void func_01ffa574(void *);
    void func_02082040(void *);
    void func_020c127c(void);
    void func_020e35cc(s32);
    void func_ov003_021f140c(s32);
    void func_020af1e4(void);
    void func_ov003_021f1a58(void);
    extern M2C_UNK data_ov003_02210104, data_ov003_02210130;
    extern M2C_UNK data_ov003_022101ac, data_ov003_022101d8;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &data_ov003_022101ac;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_022101d8;
    func_020af1e4();
    func_ov003_021f1a58();
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210104;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210130;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        func_020e35cc(M2C_FIELD(sub, s32 *, 0x14));
        func_02082040(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) func_02082040(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) func_02082040(child);
    sub = M2C_FIELD(obj, void **, 104);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        if (M2C_FIELD(sub, void **, 8) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 8));
        if (M2C_FIELD(sub, void **, 12) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 12));
        if (M2C_FIELD(sub, void **, 16) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 16));
        if (M2C_FIELD(sub, void **, 20) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 20));
        if (M2C_FIELD(sub, void **, 24) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 24));
        if (M2C_FIELD(sub, void **, 28) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 28));
        if (M2C_FIELD(sub, void **, 32) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 32));
        if (M2C_FIELD(sub, void **, 36) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 36));
        func_02082040(sub);
    }
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        func_02082040(sub);
    }
    func_ov003_021f140c(4);
    func_020c127c();
    return obj;
}

/* Destructor: releases all owned sub-objects and frees this object. */
void *func_ov003_021ffdf4(void *obj) {
    void func_01ffa574(void *);
    void func_02082040(void *);
    void func_020c127c(void);
    void func_020e35cc(s32);
    void func_ov003_021f140c(s32);
    void func_020af1e4(void);
    void func_ov003_021f1a58(void);
    extern M2C_UNK data_ov003_02210104, data_ov003_02210130;
    extern M2C_UNK data_ov003_022101ac, data_ov003_022101d8;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &data_ov003_022101ac;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_022101d8;
    func_020af1e4();
    func_ov003_021f1a58();
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210104;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210130;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        func_020e35cc(M2C_FIELD(sub, s32 *, 0x14));
        func_02082040(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) func_02082040(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) func_02082040(child);
    sub = M2C_FIELD(obj, void **, 104);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        if (M2C_FIELD(sub, void **, 8) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 8));
        if (M2C_FIELD(sub, void **, 12) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 12));
        if (M2C_FIELD(sub, void **, 16) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 16));
        if (M2C_FIELD(sub, void **, 20) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 20));
        if (M2C_FIELD(sub, void **, 24) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 24));
        if (M2C_FIELD(sub, void **, 28) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 28));
        if (M2C_FIELD(sub, void **, 32) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 32));
        if (M2C_FIELD(sub, void **, 36) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 36));
        func_02082040(sub);
    }
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        func_02082040(sub);
    }
    func_ov003_021f140c(4);
    func_020c127c();
    func_02082040(obj);
    return obj;
}

void *func_ov003_02200004(void *obj) {
    void func_01ffa574(void *);
    void func_02082040(void *);
    void func_020c127c(void);
    void func_020e35cc(s32);
    void func_ov003_021f140c(s32);
    void func_020af1e4(void);
    void func_ov003_021f1a58(void);
    extern M2C_UNK data_ov003_02210104, data_ov003_02210130;
    extern M2C_UNK data_ov003_022101ac, data_ov003_022101d8;
    void *sub;
    void *child;
    M2C_FIELD(obj, void **, 0) = &data_ov003_02210104;
    M2C_FIELD(obj, void **, 0x34) = &data_ov003_02210130;
    sub = M2C_FIELD(obj, void **, 0x70);
    if (sub != NULL) {
        func_020e35cc(M2C_FIELD(sub, s32 *, 0x14));
        func_02082040(sub);
    }
    child = M2C_FIELD(obj, void **, 68);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 76);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 80);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 84);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 92);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 96);
    if (child != NULL) M2C_FIELD(*(void **)child, void (**)(void *), 4)(child);
    child = M2C_FIELD(obj, void **, 88);
    if (child != NULL) func_02082040(child);
    child = M2C_FIELD(obj, void **, 100);
    if (child != NULL) func_02082040(child);
    sub = M2C_FIELD(obj, void **, 104);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        if (M2C_FIELD(sub, void **, 8) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 8));
        if (M2C_FIELD(sub, void **, 12) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 12));
        if (M2C_FIELD(sub, void **, 16) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 16));
        if (M2C_FIELD(sub, void **, 20) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 20));
        if (M2C_FIELD(sub, void **, 24) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 24));
        if (M2C_FIELD(sub, void **, 28) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 28));
        if (M2C_FIELD(sub, void **, 32) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 32));
        if (M2C_FIELD(sub, void **, 36) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 36));
        func_02082040(sub);
    }
    sub = M2C_FIELD(obj, void **, 108);
    if (sub != NULL) {
        if (M2C_FIELD(sub, void **, 0) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 0));
        if (M2C_FIELD(sub, void **, 4) != NULL) func_01ffa574(M2C_FIELD(sub, void **, 4));
        func_02082040(sub);
    }
    func_ov003_021f140c(4);
    func_020c127c();
    return obj;
}

