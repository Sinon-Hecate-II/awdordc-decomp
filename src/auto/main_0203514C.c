/* 5 functions from 0x0203514C to 0x0203538C (main), found by ds-decomp. */
#include "common.h"

void func_0203514c(void){extern void *data_0213d138;extern M2C_UNK data_020fb800,data_020fb810,data_020fb82c,data_020fb84c;register void *p;void (*cb)(void*,void*,s32)=*(void (**)(void*,void*,s32))((char *)data_0213d138+0x110c);p=M2C_FIELD(&data_0213d138,void**,0x14);if(p){func_02034480();cb(&data_020fb800,M2C_FIELD(&data_0213d138,void**,0x14),0);M2C_FIELD(&data_0213d138,void**,0x14)=0;}func_02032b10();if(!data_0213d138)return;if(M2C_FIELD(data_0213d138,void**,0x1114)){cb(&data_020fb810,M2C_FIELD(data_0213d138,void**,0x1114),0);M2C_FIELD(data_0213d138,void**,0x1114)=0;}if(M2C_FIELD(data_0213d138,void**,0x1118)){cb(&data_020fb82c,M2C_FIELD(data_0213d138,void**,0x1118),0);M2C_FIELD(data_0213d138,void**,0x1118)=0;}cb(&data_020fb84c,data_0213d138,0);data_0213d138=0;}

void func_02035244(void) {
    M2C_UNK func_02005d60(void *);
    M2C_UNK func_02032a84(void);
    M2C_UNK func_02033f3c(void);
    extern void *data_0213d138;
    if (data_0213d138 == NULL) return;
    if (M2C_FIELD(&data_0213d138, s32 *, 0x14) != 0) {
        func_02033f3c();
    }
    func_02032a84();
    if (M2C_FIELD(data_0213d138, s32 *, 0x1188) != 0) {
        func_02005d60(data_0213d138 + 0x111C);
    }
    M2C_FIELD(data_0213d138, s32 *, 0x1004) = -7;
}

s32 func_020352ac(void) {
    M2C_UNK func_02006564(void *);
    M2C_UNK func_020065e8(void *);
    extern void *data_0213d138;
    s32 result;
    func_02006564(data_0213d138 + 0x11DC);
    result = M2C_FIELD(data_0213d138, s32 *, 0x1000);
    func_020065e8(data_0213d138 + 0x11DC);
    return result;
}

s32 func_020352ec(void) {
    extern void *data_0213d138;
    return M2C_FIELD(data_0213d138, s32 *, 0x1004);
}

void func_02035304(void) {
    M2C_UNK func_02005ac0(void *, void (*)(void), void *, void *, s32, s32);
    s32 func_02005d90(void *);
    M2C_UNK func_02005e5c(void *);
    void func_0203538c(void);
    extern void *data_0213d138;
    if (M2C_FIELD(data_0213d138, s32 *, 0x1188) != 0 && func_02005d90(data_0213d138 + 0x111C) == 0) {
        return;
    }
    func_02005ac0(data_0213d138 + 0x111C, func_0203538c, data_0213d138, data_0213d138 + 0x1000, 0x1000, 0x10);
    func_02005e5c(data_0213d138 + 0x111C);
}

