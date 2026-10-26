/* 13 functions from 0x0220BCAC to 0x0220C6C8 (ov003), found by ds-decomp. */
#include "common.h"

s8 func_ov003_0220bf68(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 0xB);
}

void func_ov003_0220bf70(void) {
    M2C_UNK func_01ff9d88(M2C_UNK);
    extern void *data_027e00c4;
    func_01ff9d88(1);
    M2C_FIELD(data_027e00c4, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e00c4, u8 *, 0x46) | 2);
}

void func_ov003_0220c0e8(void *arg0) {
    M2C_UNK func_020bf9f0(s16);
    M2C_UNK func_020bfa30(s16);
    func_020bf9f0(M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s16 *, 0x12));
    func_020bfa30(M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), s16 *, 0x12));
}

void func_ov003_0220c328(void *arg0, int arg1) {
 extern void *data_027e00c4;
 u8 *p=arg0; u8 *q; int v; u8 a,b;
 p[0x38]&=~2;
 q=*(u8 **)(p+0x3c); v=q[0x10];
 func_0208fe30(0x1000f);
 if((u8)((((unsigned int)p[0x36]<<24)>>28)==1) || (u8)((((unsigned int)p[0x36]<<24)>>28)==2)){p[0x35]=1;func_020d47f0();func_01ffa6fc(p);}
 p[0x38]&=~8;
 q=*(u8 **)(p+0x3c);q[q[0xf]]=arg1;
 if(v!=16){p[0x34]=30;func_ov003_0220a698(p,v);func_ov003_0220828c(p,5,255);func_01ff9d88(1);M2C_FIELD(data_027e00c4,u8 *,0x46)|=2;}
 else {func_020d47f0();func_01ffa6fc(p);}
}

void func_ov003_0220c6a4(void) {
    M2C_UNK func_ov003_022066d8();
    func_ov003_022066d8();
}

void func_ov003_0220c6b0(void) {
    M2C_UNK func_ov003_02209310();
    func_ov003_02209310();
}

void func_ov003_0220c6bc(void) {
    M2C_UNK func_ov003_02209cdc();
    func_ov003_02209cdc();
}

