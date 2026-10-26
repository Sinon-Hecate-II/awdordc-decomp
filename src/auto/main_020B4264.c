/* 29 functions from 0x020B4264 to 0x020B5258 (main), found by ds-decomp. */
#include "common.h"

void func_020b4a44(void *arg0){s32 func_0207c2e0(); extern u8 data_02157718;extern M2C_UNK data_02168f68;s32 i;u8 *p;u8 v;
M2C_FIELD(arg0,s32 *,0)=func_0207c2e0();p=&data_02157718;i=0;do{v=*p++;M2C_FIELD(arg0+i,u8 *,4)=v;i++;}while(i<4);
M2C_FIELD(arg0,s16 *,8)=M2C_FIELD(&data_02168f68,s16 *,0);
M2C_FIELD(arg0,s16 *,10)=M2C_FIELD(&data_02168f68,s16 *,2);
M2C_FIELD(arg0,s16 *,12)=M2C_FIELD(&data_02168f68,s16 *,4);
M2C_FIELD(arg0,s16 *,14)=M2C_FIELD(&data_02168f68,s16 *,6);
M2C_FIELD(arg0,s32 *,16)=M2C_FIELD(&data_02168f68,s32 *,8);func_020b3c48(arg0);}

void func_020b4ab4(void *arg0) {
    M2C_UNK func_0207c2d0(s32);
    M2C_UNK func_020b4264();
    extern u8 data_02157718;
    extern M2C_UNK data_02168f68;
    s32 var_r1;
    u8 *var_r2;
    u8 temp_r0;

    func_020b4264();
    func_0207c2d0(M2C_FIELD(arg0, s32 *, 0));
    var_r2 = &data_02157718;
    var_r1 = 0;
    do {
        temp_r0 = M2C_FIELD((arg0 + var_r1), u8 *, 4);
        var_r1 += 1;
        *var_r2 = temp_r0;
        var_r2 += 1;
    } while (var_r1 < 4);
    M2C_FIELD(&data_02168f68, s16 *, 0) = (s16) M2C_FIELD(arg0, s16 *, 8);
    M2C_FIELD(&data_02168f68, s16 *, 2) = (s16) M2C_FIELD(arg0, s16 *, 0xA);
    M2C_FIELD(&data_02168f68, s16 *, 4) = (s16) M2C_FIELD(arg0, s16 *, 0xC);
    M2C_FIELD(&data_02168f68, s16 *, 6) = (s16) M2C_FIELD(arg0, s16 *, 0xE);
    M2C_FIELD(&data_02168f68, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
}

void func_020b4b20(void) {
    M2C_UNK func_0208f8ec(M2C_UNK, M2C_UNK);
    func_0208f8ec(0, 8);
}

void func_020b4b34(void) {
    M2C_UNK func_0208f8d8();
    func_0208f8d8();
}

void func_020b4b40(void *arg0){void *func_020be120();s32 func_020bf084(u8);s32 func_020bf0dc(s32,u8);u8 v=M2C_FIELD(arg0,s32 *,0x5c);func_020bee8c(v);if(!func_020bf084(v)){func_020bf0dc(0,v);func_020e4870();}func_020b4a44(func_020be120());func_020be438(v,func_020be120(),0x125c);}

void func_020b4b98(void *arg0) {
    if (func_020be4c0((u8) M2C_FIELD(arg0, s32 *, 0x5C)) == 0) {
        func_02086720(0xC000034C);
        return;
    }
    func_02086720(0);
}

void func_020b4bcc(s32 arg0, M2C_UNK arg1){extern u8 data_02168f0c;extern M2C_UNK data_0212882c;func_020b3c44();if(data_02168f0c)return;M2C_FIELD(func_01ffa444(&data_0212882c,arg1),s32 *,0x5c)=arg0;}

void func_020b4c08(u8 arg0){void *func_020be120();s32 func_020bf084(u8);s32 func_020bf0dc(s32,u8);extern M2C_UNK data_0215d9b8;extern void *data_027e0058;void (*fn)(void);
func_020be324(arg0,func_020be120());func_020b4ab4(func_020be120());if(!func_020bf084(arg0)){M2C_FIELD(&data_0215d9b8,u16 *,6)=(M2C_FIELD(&data_0215d9b8,u16 *,6)&~0x70)|((u32)((u16)func_020bf0dc(0,arg0)<<29)>>25);}
func_020cfd14();fn=M2C_FIELD(M2C_FIELD(data_027e0058,void **,4),void (**)(void),0x50);if(fn)fn();func_020cd8a8();func_020cfd28();func_020c0a1c(3);}

void func_020b4ca0(void) {
    s32 func_020bee64();
    func_020befd8();
    if (func_020bee64() == 0) {
        func_02086720(0xC000032D);
        return;
    }
    func_02086720(0xC000032E);
}

void func_020b4cd4(M2C_UNK arg0) {
    
    s32 temp_r0;

    temp_r0 = func_020befd8();
    if (temp_r0 == 0) {
        return;
    }
    func_020b4bcc(temp_r0, arg0);
}

void func_020b4cf4(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021286f4;
    func_01ffa3dc(&data_021286f4, 7);
}

void func_020b4d0c(void) {
    s32 func_020befd8();
    M2C_UNK func_020d4ac8();
    if (func_020befd8() == 0) {
        return;
    }
    func_020d4ac8();
}

void func_020b4d24(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021287b4;
    func_01ffa3dc(&data_021287b4, 7);
}

void func_020b4d3c(void *arg0) {
    M2C_UNK func_020e4870(s32);
    extern s32 data_0215d8a0;
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x5C);
    func_020bf054(0, temp_r4);
    func_020bef44();
    data_0215d8a0 = (data_0215d8a0 & ~0xF) | (temp_r4 & 0xF);
    func_020e4870(temp_r4);
    func_020bf798();
}

void func_020b4d80(void) {
    M2C_UNK func_02086720(s32);
    s32 func_020be4c0(M2C_UNK);
    if (func_020be4c0(4) == 0) {
        func_02086720(0xC000034C);
        return;
    }
    func_02086720(0);
}

void func_020b4db0(s32 arg0) {
    extern M2C_UNK data_0212895c;
    M2C_FIELD(func_01ffa444(&data_0212895c), s32 *, 0x5C) = arg0;
}

void func_020b4dcc(void *arg0) {
    M2C_UNK func_020bef44();
    M2C_UNK func_020bf054(M2C_UNK, s32);
    M2C_UNK func_020bf798();
    M2C_UNK func_020e4818(s32);
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x5C);
    func_020bf054(0, temp_r4);
    func_020bef44();
    func_020e4818(temp_r4);
    func_020bf798();
}

void func_020b4df4(s32 arg0) {
    extern M2C_UNK data_0212874c;
    M2C_FIELD(func_01ffa444(&data_0212874c), s32 *, 0x5C) = arg0;
}

void func_020b4e10(M2C_UNK arg0) {
    M2C_UNK func_01ffa444(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02128a0c;
    func_01ffa444(&data_02128a0c, arg0);
}

s32 func_020b5134(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, u16 arg5, s32 arg6) {
    s32 func_0208c528(s32);
    M2C_UNK func_020b501c(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    s32 temp_r0;

    temp_r0 = func_0208c528(arg6);
    func_020b501c(temp_r0, arg0, arg1, arg2, arg3, arg4, (s32) arg5);
    return temp_r0;
}

s32 func_020b5188(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, u16 arg5, s32 arg6) {
    s32 func_0208c54c(s32);
    s32 temp_r0;

    temp_r0 = func_0208c54c(arg6);
    func_020b501c(temp_r0, arg0, arg1, arg2, arg3, arg4, (s32) arg5);
    return temp_r0;
}

void func_020b51dc(void) {
    extern s32 data_0215d848;
    data_0215d848 = 0;
}

s32 func_020b51f0(void) {
    extern s32 data_0215d848;
    return data_0215d848;
}

s32 func_020b5200(s32 arg0,s32 arg1){s32 func_0208c570(s32,s32,u16);extern s32 data_0215d848;s32 old=data_0215d848;data_0215d848+=func_0208c570(arg0,old+0x329a0,(u16)(arg1+0xab));return old;}

void func_020b5240(void) {
    M2C_UNK func_0208c69c();
    func_0208c69c();
}

void func_020b524c(void) {
    M2C_UNK func_0208c6fc();
    func_0208c6fc();
}

