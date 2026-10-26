/* 10 functions from 0x020785B0 to 0x020793F0 (main), found by ds-decomp. */
#include "common.h"
extern u32 data_020edebc[][2];

extern u32 data_027e15bc;
extern u8 data_02140f70[24];

void func_020785b0(void) {
    s32 func_0207cfb8(s32);
    extern s32 *data_027e0058;
    s32 var_r0;
    if ((s32)(data_027e15bc % 140) < 60) {
        data_02140f70[1] = 0;
    } else {
        data_02140f70[1] = 1;
    }
    if (func_0207cfb8(*data_027e0058 + 0x6EF8) <= 0) {
        var_r0 = 0x10;
    } else {
        var_r0 = 0x18;
    }
    if (var_r0 == 0x10) {
        data_02140f70[1] = 0;
    }
}

void func_0207863c(void) {
    data_02140f70[2] = (data_027e15bc / 12) & 3;
}

void func_0207877c(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_0207ca38(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 func_0207cfb8(s32);
    s32 func_02090158(M2C_UNK, s32, M2C_UNK);
    M2C_UNK func_020901b0(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern s32 *data_027e0058;
    s32 temp_r0;
    s32 var_r5;
    s32 var_r6;

    var_r6 = arg2;
    temp_r0 = func_0207cfb8(*data_027e0058 + 0x6EF8);
    var_r5 = 0;
    if (var_r6 != 0) {
        if (var_r6 < 8) {
            var_r6 = 8;
        }
        var_r5 = func_0207ca38(0, 0, 0x7F, var_r6 * temp_r0, 0x1000);
        if (var_r5 > 0x7F) {
            var_r5 = 0x7F;
        } else if (var_r5 < 0) {
            var_r5 = 0;
        }
    }
    if (func_02090158(arg0, var_r5, 0xA) != 0) {
        return;
    }
    if (var_r5 == 0) {
        return;
    }
    func_020901b0(arg0, -1, arg1, var_r5);
}

void func_02079310(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h){
void func_02079db0(s32,s32,s32,s32,s32,s32);s32 func_020cfc0c(s32);
s32 flags; s32 mask,x=0,y=0;
if(f)mask=24;else{x+=16;mask=8;y=x;} flags=data_020edebc[c][0];
if(mask&(u16)flags)x+=func_020cfc0c(e);
if(d){func_02079db0(a,b,c,x,g,h);func_02079db0(a,b,d,y,g,h);return;}
func_02079db0(a,b,c,x,g,h);
}

