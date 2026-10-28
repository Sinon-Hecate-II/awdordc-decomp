/* 17 functions from 0x022144AC to 0x022153FC (ov006), found by ds-decomp. */
#include "common.h"

int func_ov006_022144ac(void *arg0) {
    (void)arg0;
    return 0;
}

void func_ov006_02215010(void) {
    M2C_UNK func_ov006_02212184();
    func_ov006_02212184();
}

void func_ov006_0221501c(void) {
    M2C_UNK func_ov006_02211200();
    func_ov006_02211200();
}

void func_ov006_02215028(void) {
    M2C_UNK func_ov006_02211388();
    func_ov006_02211388();
}

void func_ov006_02215034(void) {

}

void func_ov006_02215038(void) {
    M2C_UNK func_ov006_02211314();
    func_ov006_02211314();
}

void func_ov006_02215044(void) {
    M2C_UNK func_020c4dd0();
    func_020c4dd0();
}

void func_ov006_02215050(void) {
    M2C_UNK func_020c52d8();
    func_020c52d8();
}

void func_ov006_0221505c(void *arg0) {
    M2C_UNK func_020c5664(s16);
    func_020c5664(M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s16 *, 8));
    M2C_FIELD(arg0, s8 *, 0x34) = 1;
}

void func_ov006_0221507c(void **arg0) {
 M2C_FIELD(*arg0, void (**)(void *), 8)(arg0);
}

void func_ov006_02215090(void *arg0) {
    M2C_UNK func_01ffa574(s32);
    M2C_UNK func_020af1e4();
    func_020af1e4();
    func_01ffa574(M2C_FIELD(arg0, s32 *, 0x38));
}

void func_ov006_022150a8(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_020a8f8c(void *);
    void *ptr = M2C_FIELD(arg0, void **, 0x48);
    u8 equal = M2C_FIELD(ptr, u16 *, 2) == M2C_FIELD(ptr, s16 *, 0xC);
    if (equal) {
        func_01ffa6fc(arg0);
        return;
    }
    func_020a8f8c(ptr);
}

void func_ov006_022150e0(void) {
    M2C_UNK func_ov006_02213e98();
    func_ov006_02213e98();
}

void func_ov006_022150ec(void) {
    M2C_UNK func_ov006_0221440c();
    func_ov006_0221440c();
}

void func_ov006_022150f8(void) {
    M2C_UNK func_ov006_022144ac();
    func_ov006_022144ac();
}

void func_ov006_02215104(s32 arg0) {
    (void)arg0;
}

u8 func_ov006_022153f4(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x34);
}

