/* 5 functions from 0x0203514C to 0x0203538C (main), found by ds-decomp. */
#include "common.h"

#pragma scheduling on
void func_0203514c(void){extern void *gWfcNet;extern M2C_UNK data_020fb800,data_020fb810,data_020fb82c,data_020fb84c;void (*cb)(void*,void*,s32); void *base=*(void *volatile *)&gWfcNet;void *condition=*(void *volatile *)((char *)&gWfcNet+20);cb=M2C_FIELD(base,void (**)(void*,void*,s32),0x110c);if(condition){func_02034480();cb(&data_020fb800,M2C_FIELD(&gWfcNet,void**,20),0);M2C_FIELD(&gWfcNet,void**,20)=0;}func_02032b10();if(!gWfcNet)return;if(M2C_FIELD(gWfcNet,void**,0x1114)){cb(&data_020fb810,M2C_FIELD(gWfcNet,void**,0x1114),0);M2C_FIELD(gWfcNet,void**,0x1114)=0;}if(M2C_FIELD(gWfcNet,void**,0x1118)){cb(&data_020fb82c,M2C_FIELD(gWfcNet,void**,0x1118),0);M2C_FIELD(gWfcNet,void**,0x1118)=0;}cb(&data_020fb84c,gWfcNet,0);gWfcNet=0;}
void func_02035244(void) {
    M2C_UNK func_02005d60(void *);
    M2C_UNK func_02032a84(void);
    M2C_UNK func_02033f3c(void);
    extern void *gWfcNet;
    if (gWfcNet == NULL) return;
    if (M2C_FIELD(&gWfcNet, s32 *, 0x14) != 0) {
        func_02033f3c();
    }
    func_02032a84();
    if (M2C_FIELD(gWfcNet, s32 *, 0x1188) != 0) {
        func_02005d60(gWfcNet + 0x111C);
    }
    M2C_FIELD(gWfcNet, s32 *, 0x1004) = -7;
}

s32 func_020352ac(void) {
    M2C_UNK LockMutex(void *);
    M2C_UNK UnlockMutex(void *);
    extern void *gWfcNet;
    s32 result;
    LockMutex(gWfcNet + 0x11DC);
    result = M2C_FIELD(gWfcNet, s32 *, 0x1000);
    UnlockMutex(gWfcNet + 0x11DC);
    return result;
}

s32 func_020352ec(void) {
    extern void *gWfcNet;
    return M2C_FIELD(gWfcNet, s32 *, 0x1004);
}

void func_02035304(void) {
    M2C_UNK func_02005ac0(void *, void (*)(void), void *, void *, s32, s32);
    s32 func_02005d90(void *);
    M2C_UNK TaskWake(void *);
    void func_0203538c(void);
    extern void *gWfcNet;
    if (M2C_FIELD(gWfcNet, s32 *, 0x1188) != 0 && func_02005d90(gWfcNet + 0x111C) == 0) {
        return;
    }
    func_02005ac0(gWfcNet + 0x111C, func_0203538c, gWfcNet, gWfcNet + 0x1000, 0x1000, 0x10);
    TaskWake(gWfcNet + 0x111C);
}

