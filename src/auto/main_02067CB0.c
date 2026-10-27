/* 6 functions from 0x02067CB0 to 0x02068C50 (main), found by ds-decomp. */
#include "common.h"

s32 func_02068a04(void *arg0, s32 arg1, s32 arg2) {
    s8 *temp_r1;
    s32 temp_r2;
    switch (arg2) {
    case 0:
        temp_r1 = M2C_FIELD(arg0, s8 **, 0);
        temp_r2 = *temp_r1;
        if (temp_r2 == 0) {
            M2C_FIELD(arg0, s32 *, 4) = 1;
            return -1;
        }
        M2C_FIELD(arg0, s8 **, 0) = temp_r1 + 1;
        return (u8)temp_r2;
    case 1:
        if (M2C_FIELD(arg0, s32 *, 4) != 0) {
            M2C_FIELD(arg0, s32 *, 4) = 0;
            goto done;
        } else {
            M2C_FIELD(arg0, s8 **, 0) -= 1;
        }
    done:
        return arg1;
    case 2:
        return M2C_FIELD(arg0, s32 *, 4);
    default:
        return 0;
    }
}

s32 func_02068a88(s8 *arg0, s32 arg1, s32 arg2) {
    s32 func_02068a04(void *, s32, s32);
    s32 func_02067cb0(s32 (*)(void *, s32, s32), void *, s32, s32, s32);
    struct { s8 *ptr; s32 eof; } state;
    state.ptr = arg0;
    if (arg0 == NULL || *arg0 == 0) return -1;
    state.eof = 0;
    return func_02067cb0(func_02068a04, &state, arg1, arg2, 0);
}

void func_02068adc(s32 arg0, s32 arg1, ...) {
    s32 func_02068a88(s8 *, s32, s32);
    char *args;
    args = (char *)(((u32)&arg1 & ~3U) + 4);
    func_02068a88(arg0, arg1, args);
}

s32 func_02068b04(s32 arg0) {
M2C_UNK func_02006564(M2C_UNK *);
M2C_UNK func_020065e8(M2C_UNK *);
s32 func_02006680(M2C_UNK *);
M2C_UNK func_02063e1c(M2C_UNK);
extern M2C_UNK data_0212dca4;
extern M2C_UNK data_0213e5d4;
extern s32 data_0213e5f8[9];
extern M2C_UNK data_0213e6c4;
extern M2C_UNK data_0213e9f8;
M2C_UNK (*cb)(s32);
s32 n;
if(arg0<1 || arg0>7) return -1;
if(func_02006680(&data_0213e6c4)==0) {
M2C_FIELD(&data_0213e5d4,s32 *,0x1c)=M2C_FIELD(M2C_FIELD(&data_0212dca4,void **,4),s32 *,0x6c);
data_0213e5f8[7]=1;
} else if(M2C_FIELD(&data_0213e5d4,s32 *,0x1c)==M2C_FIELD(M2C_FIELD(&data_0212dca4,void **,4),s32 *,0x6c)) {
n=data_0213e5f8[7]+1;
data_0213e5f8[7]=n;
} else {
func_02006564(&data_0213e6c4);
M2C_FIELD(&data_0213e5d4,s32 *,0x1c)=M2C_FIELD(M2C_FIELD(&data_0212dca4,void **,4),s32 *,0x6c);
data_0213e5f8[7]=1;
}
n=arg0-1;
cb=((M2C_UNK (**)(s32))&data_0213e9f8)[n];
if(cb!=(M2C_UNK (*)(s32))1) ((M2C_UNK (**)(s32))&data_0213e9f8)[n]=0;
n=data_0213e5f8[7]-1;
data_0213e5f8[7]=n;
if(n==0) func_020065e8(&data_0213e6c4);
if(cb==(M2C_UNK (*)(s32))1 || (cb==0 && arg0==1)) return 0;
if(cb==0) func_02063e1c(0);
cb(arg0);
return 0;
}

s32 func_02068c34(s8 *arg0) {
    s32 var_r2;
    s8 *var_r0;
    s8 temp_r1;

    var_r0 = arg0;
    var_r2 = -1;
    do {
        temp_r1 = *var_r0;
        var_r0 += 1;
        var_r2 += 1;
    } while (temp_r1 != 0);
    return var_r2;
}
