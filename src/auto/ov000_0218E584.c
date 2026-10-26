/* 7 functions from 0x0218E584 to 0x0218F468 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0218edd8(void) {
    M2C_UNK func_ov000_0218dda4();
    M2C_UNK func_ov000_0218e340();
    M2C_UNK func_ov000_0218e9ac();
    M2C_UNK func_ov000_0218e584();
    s32 func_ov000_021a93a8(void *, u8, u8);
    s32 func_ov000_021a98a8(u32);
    extern void **data_027e0058;
    extern void *data_ov000_021df580;
    void *temp_r0;
    void *temp_r1;
    temp_r0 = M2C_FIELD(*data_027e0058, void **, 0x52D0);
    if (func_ov000_021a93a8(temp_r0, M2C_FIELD(temp_r0, u8 *, 1), M2C_FIELD(temp_r0, u8 *, 2)) == 0) {
        func_ov000_0218e340();
    }
    temp_r1 = M2C_FIELD(*data_027e0058, void **, 0x52D0);
    if (((u32)(M2C_FIELD(temp_r1, u16 *, 8) << 0x12) >> 0x1E) == 0) return;
    if (func_ov000_021a98a8((u32)(M2C_FIELD(temp_r1, u8 *, 0) << 0x1A) >> 0x1A) != 0) func_ov000_0218dda4();
    M2C_FIELD(data_ov000_021df580, u8 *, 7) = (u8)(M2C_FIELD(data_ov000_021df580, u8 *, 7) | 2);
    switch ((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058, void **, 0x52D0), u16 *, 8) << 0x12) >> 0x1E) {
    case 1: func_ov000_0218e9ac(); break;
    case 2: func_ov000_0218e584(); break;
    }
}

void func_ov000_0218eea8(void) {
    M2C_UNK func_ov000_0218dda4();
    M2C_UNK func_ov000_0218e340();
    M2C_UNK func_ov000_0218e9ac();
    s32 func_ov000_021a93a8(void *, u8, u8);
    s32 func_ov000_021a98a8(u32);
    extern void **data_027e0058;
    extern void *data_ov000_021df580;
    void *temp_r0;
    void *temp_r1;

    temp_r0 = M2C_FIELD(*data_027e0058, void **, 0x52D0);
    if (func_ov000_021a93a8(temp_r0, M2C_FIELD(temp_r0, u8 *, 1), M2C_FIELD(temp_r0, u8 *, 2)) == 0) {
        func_ov000_0218e340();
    }
    temp_r1 = M2C_FIELD(*data_027e0058, void **, 0x52D0);
    if (((u32) (M2C_FIELD(temp_r1, u16 *, 8) << 0x12) >> 0x1E) != 1) {
        return;
    }
    if (func_ov000_021a98a8((u32) (M2C_FIELD(temp_r1, u8 *, 0) << 0x1A) >> 0x1A) != 0) {
        func_ov000_0218dda4();
    }
    M2C_FIELD(data_ov000_021df580, u8 *, 7) = (u8) (M2C_FIELD(data_ov000_021df580, u8 *, 7) | 2);
    func_ov000_0218e9ac();
}

void func_ov000_0218f37c(void) {
extern void **data_027e0058;
s32 func_ov000_021a98a8(u32);
s32 func_ov000_021a8b78(void *);
void func_ov000_0217c3a4(void);
void func_ov000_02199d74(u32,u32,u32,u32,u32);
u8 *p;
u8 *base;
u8 *q;
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
if(!func_ov000_021a98a8((u32)(p[0]<<26)>>26))return;
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
if(!((u32)(M2C_FIELD(p,u16 *,6)<<16)>>27))return;
if(func_ov000_021a8b78(p)>=2) {
base=*data_027e0058;
p=M2C_FIELD(base,u8 **,0x52d0);
q=base+0x6c60+6*M2C_FIELD(base+(p[1]+M2C_FIELD(base+2*p[2],u16 *,0x3758)),s8 *,0x1928);
q[3]++;
}
func_ov000_0217c3a4();
p=M2C_FIELD(*data_027e0058,u8 **,0x52d0);
func_ov000_02199d74(p[1],p[2],3,0,0);
}

