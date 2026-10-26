/* 3 functions from 0x02218200 to 0x02218340 (ov006), found by ds-decomp. */
#include "common.h"

/* Validates the linked sub-object and propagates its state into the entity's slots. */
void func_ov006_02218200(void *entity) {
    s32 func_020c79ec();
    s32 func_020c7e58(s32);
    s32 func_02084cf8();
    s32 func_020c8c6c(void *);
    s32 func_020c7a3c(s32);
    void *sub = M2C_FIELD(entity, void **, 0x54);
    s32 curId = func_020c79ec();
    s32 prevId = func_020c7e58(0);
    s32 hasSub;
    s32 ok;
    s32 value;

    if (!M2C_FIELD(entity, s32 *, 0x34)) {
        func_01ffa8c4(entity, 2);
        return;
    }
    if (!M2C_FIELD(sub, s32 *, 0x30C)) {
        hasSub = 0;
    } else if (!M2C_FIELD(sub, s32 *, 4)) {
        hasSub = 0;
    } else {
        hasSub = 1;
    }
    if (!hasSub) {
        func_01ffa8c4(entity, 2);
        return;
    }
    value = M2C_FIELD(sub, s32 *, 4);
    if (value == func_02084cf8()) {
        ok = 1;
    } else if (func_020c8c6c(sub + 0x50)) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (!ok) {
        func_01ffa8c4(entity, 2);
        return;
    }
    func_020c7cd0(sub + 0x10, curId);
    if (!func_020c7a3c(curId)) {
        func_01ffa8c4(entity, 3);
        return;
    }
    func_ov006_02217cfc(M2C_FIELD(sub, s32 *, 8));
    func_02007ef4(curId, prevId, 0x54);
    func_020d47d0();
}

void func_ov006_02218300(M2C_UNK arg0) {
    M2C_UNK func_01ffa8c4(M2C_UNK, M2C_UNK);
    s32 func_0208471c();
    M2C_UNK func_020d47f0();
    if (func_0208471c() == 0) {
        return;
    }
    func_020d47f0();
    func_01ffa8c4(arg0, 3);
}

void func_ov006_02218328(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov006_02218cdc;
    func_01ffa42c(&data_ov006_02218cdc, arg0);
}
