/* 9 functions from 0x021816C4 to 0x02181C88 (ov000), found by ds-decomp. */
#include "common.h"

/* Update the active state and dispatch the appropriate handler. */
void func_ov000_021816c4(void) {
    extern void **data_027e0058;
    void *state;

    if (func_ov000_02180410() != 0) {
        func_ov000_0218046c();
        return;
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058, void **, 0x52D0), u8 *, 0xB) << 28) >> 28) == 6) {
        return;
    }
    func_ov000_02198c60();
    func_ov000_0218edd8();
    if (((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058, void **, 0x52D0), u8 *, 0) << 26) >> 26) == 25) {
        func_ov000_0218ca94();
    }
    state = *data_027e0058;
    if (M2C_FIELD(state + M2C_FIELD(state, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE)) {
        func_ov000_02186a18();
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058, void **, 0x52D0), u8 *, 0xB) << 28) >> 28) == 8) {
        func_ov000_021962f8();
        func_ov000_0218b02c();
        return;
    }
    func_ov000_02193d6c(0);
    func_ov000_02191970();
    func_ov000_02193d6c(1);
    func_ov000_02192018();
    func_ov000_0218b02c();
}

void func_ov000_021817c0(void) {
extern void **data_027e0058;
if(func_ov000_02180410()!=0)return;
if(((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058,void **,0x52d0),u8 *,11)<<28)>>28)==6)return;
func_ov000_02198c60();
if(((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058,void **,0x52d0),u8 *,11)<<28)>>28)==8)func_ov000_021962f8();else func_ov000_0219234c();
}

void func_ov000_02181838(void) {
    extern void **data_027e0058;
    void *p;

    if (func_ov000_02180410() != 0) {
        return;
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058, void **, 0x52D0), u8 *, 0xB) << 28) >> 28) == 6) {
        return;
    }
    func_ov000_02198c60();
    if (((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058, void **, 0x52D0), u8 *, 0) << 26) >> 26) == 25) {
        func_ov000_0218ca94();
    }
    p = *data_027e0058;
    if (M2C_FIELD(p + M2C_FIELD(p, u16 *, 0x52A4) * 0x8C, u8 *, 0x67CE)) {
        func_ov000_02186a18();
    }
    if (((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058, void **, 0x52D0), u8 *, 0xB) << 28) >> 28) == 8) {
        func_ov000_021962f8();
    } else {
        func_ov000_02192d88();
    }
}

void func_ov000_02181b34(void) {
    M2C_UNK func_ov000_0218ef40();
    M2C_UNK func_ov000_02198c08();
    M2C_UNK func_ov000_02198c60();
    extern void **data_027e0058;
    u32 temp_r0;

    if (func_ov000_02180410() != 0) {
        return;
    }
    temp_r0 = (u32) (M2C_FIELD(M2C_FIELD(*data_027e0058, void **, 0x52D0), u8 *, 0xB) << 0x1C) >> 0x1C;
    if (temp_r0 == 6) {
        return;
    }
    if (temp_r0 != 1) {
        func_ov000_02198c60();
    } else {
        func_ov000_02198c08();
    }
    func_ov000_0218ef40();
}

void func_ov000_02181b8c(void) {
    M2C_UNK func_ov000_02196bd8();
    if (func_ov000_02180410() != 0) {
        return;
    }
    func_ov000_02196bd8();
}

void func_ov000_02181ba4(void) {
extern void **data_027e0058;
M2C_UNK func_ov000_02199d74(u8,u8,s32,s32,s32);
void *p;
if(func_ov000_02180410()!=0)return;
p=*data_027e0058;
if(func_020a8a14(M2C_FIELD(p,u16 *,0x5142),M2C_FIELD(p,u16 *,0x52a4)) & 0x40)return;
p=M2C_FIELD(*data_027e0058,void **,0x52d0);
func_ov000_02199d74(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),0x16,0,0);
}

void func_ov000_02181c10(void) {
s32 func_ov000_0218cb20(void);
s32 func_ov000_021aa3bc(void);
extern void *data_ov000_021df57c;
extern void *data_ov000_021df580;
s32 (*callback)(void);
if(func_ov000_02180410()!=0)return;
func_ov000_02198c60();
if(func_ov000_0218cb20()!=0)return;
callback=M2C_FIELD(data_ov000_021df57c,s32 (**)(void),4);
if(callback==NULL) {if(!func_ov000_021aa3bc())return;} else {if(!callback())return;}
M2C_FIELD(data_ov000_021df580,u16 *,8)|=0x100;
func_ov000_0218d040(0);
}

