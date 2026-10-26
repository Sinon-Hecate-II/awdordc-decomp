/* 16 functions from 0x022153FC to 0x022162F4 (ov006), found by ds-decomp. */
#include "common.h"

extern s8 data_ov006_02218345[];
extern s8 data_ov006_02218e10[];
void *func_ov006_02215620(void *arg0){
extern M2C_UNK data_ov006_02218610;
M2C_UNK func_01ffa574(M2C_UNK);M2C_UNK func_02082040(M2C_UNK);M2C_UNK func_020e4ca0();
s32 *arr;void *p=arg0;
M2C_FIELD(p,void **,0)=&data_ov006_02218610;
arr=M2C_FIELD(p,s32 **,0x3c);
if(arr){func_01ffa574(arr[0]);func_01ffa574(arr[1]);func_01ffa574(arr[2]);func_01ffa574(arr[3]);func_01ffa574(arr[4]);func_01ffa574(arr[5]);func_02082040((s32)arr);}
arr=M2C_FIELD(p,void **,0x40);if(arr)M2C_FIELD(M2C_FIELD(arr,void **,0),void (**)(void *),4)((void *)arr);
arr=M2C_FIELD(p,void **,0x44);if(arr)M2C_FIELD(M2C_FIELD(arr,void **,0),void (**)(void *),4)((void *)arr);
arr=M2C_FIELD(p,void **,0x48);if(arr)func_02082040((s32)arr);
arr=M2C_FIELD(p,void **,0x4c);if(arr)M2C_FIELD(M2C_FIELD(arr,void **,0),void (**)(void *),4)((void *)arr);
func_020e4ca0();func_02082040((s32)p);return p;
}

void *func_ov006_022156e4(void *arg0) {
    M2C_UNK func_01ffa574(M2C_UNK);
    M2C_UNK func_02082040(M2C_UNK);
    M2C_UNK func_020e4ca0();
    extern M2C_UNK data_ov006_02218610;
    void *p;
    void *self;

    self = arg0;
    M2C_FIELD(self, void **, 0) = &data_ov006_02218610;
    p = M2C_FIELD(self, void **, 0x3C);
    if (p != NULL) {
        func_01ffa574(M2C_FIELD(p, void **, 0));
        func_01ffa574(M2C_FIELD(p, void **, 4));
        func_01ffa574(M2C_FIELD(p, void **, 8));
        func_01ffa574(M2C_FIELD(p, void **, 0xC));
        func_01ffa574(M2C_FIELD(p, void **, 0x10));
        func_01ffa574(M2C_FIELD(p, void **, 0x14));
        func_02082040(p);
    }
    p = M2C_FIELD(self, void **, 0x40);
    if (p != NULL) {
        M2C_FIELD(M2C_FIELD(p, void **, 0), void (**)(void *), 4)(p);
    }
    p = M2C_FIELD(self, void **, 0x44);
    if (p != NULL) {
        M2C_FIELD(M2C_FIELD(p, void **, 0), void (**)(void *), 4)(p);
    }
    p = M2C_FIELD(self, void **, 0x48);
    if (p != NULL) {
        func_02082040(p);
    }
    p = M2C_FIELD(self, void **, 0x4C);
    if (p != NULL) {
        M2C_FIELD(M2C_FIELD(p, void **, 0), void (**)(void *), 4)(p);
    }
    func_020e4ca0();
    return self;
}

void func_ov006_02215ae0(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    s8 *temp_r0;
    s8 temp_r3;

    temp_r0 = M2C_FIELD(arg0, void **, 0x10);
    data_ov006_02218e10[M2C_FIELD(temp_r0, s8 *, 0x38)] =
        data_ov006_02218345[M2C_FIELD(arg0, u8 *, 0) * 6];
    temp_r3 = (s8)(M2C_FIELD(temp_r0, s8 *, 0x38) + 1);
    if (temp_r3 >= 0 && temp_r3 < 12 &&
        (data_ov006_02218e10[temp_r3] != 0 ||
         (temp_r3 > 0 && data_ov006_02218e10[temp_r3 - 1] != 0))) {
        M2C_FIELD(temp_r0, s8 *, 0x38) = temp_r3;
    }
    func_0208fe30(0x1000D);
}

void func_ov006_02215b64(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov006_02215b78(void) {
    M2C_UNK func_ov006_022157a0();
    func_ov006_022157a0();
}

void func_ov006_02215dc4(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov006_02215dd8(void) {
    M2C_UNK func_ov006_022157a0();
    func_ov006_022157a0();
}

void func_ov006_02216188(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

