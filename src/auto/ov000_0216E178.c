/* 7 functions from 0x0216E178 to 0x0216ECC8 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0216e178(void *arg0) {
    return;
}

void func_ov000_0216ea10(void) {
    M2C_UNK func_ov000_0216e110();
    func_ov000_0216e110();
}

/* Handles up/down/LR input while a unit list menu is open. */
void func_ov000_0216ea1c(void) {
    extern u16 *data_02101e84;
    extern s32 data_ov000_021df5e0;
    M2C_UNK func_0208fe30(s32);
    void func_ov000_0216e09c(s32);
    void func_ov000_0216e054(void);
    void func_ov000_0216dd0c(void);
    void func_ov000_0216ebac(void);
    u16 keys = data_02101e84[0];
    if (keys & 2) { func_ov000_0216ebac(); return; }
    if (data_02101e84[1] & 0x10) {
        if (M2C_FIELD(data_ov000_021df5e0, u8 *, 0xd) == M2C_FIELD(data_ov000_021df5e0, u8 *, 0xc) - 1) {
            if (keys & 0x10) { func_0208fe30(0x10019); func_ov000_0216e09c(0); func_ov000_0216e054(); }
        } else { func_0208fe30(0x10019); func_ov000_0216e09c(M2C_FIELD(data_ov000_021df5e0, u8 *, 0xd) + 1); func_ov000_0216e054(); }
    }
    if (data_02101e84[1] & 0x20) {
        if (M2C_FIELD(data_ov000_021df5e0, u8 *, 0xd) == 0) {
            if (data_02101e84[0] & 0x20) { func_0208fe30(0x10019); func_ov000_0216e09c(M2C_FIELD(data_ov000_021df5e0, u8 *, 0xc) - 1); func_ov000_0216e054(); }
        } else { func_0208fe30(0x10019); func_ov000_0216e09c(M2C_FIELD(data_ov000_021df5e0, u8 *, 0xd) - 1); func_ov000_0216e054(); }
    }
    if ((data_02101e84[0] & 0x100) || (data_02101e84[0] & 0x200)) {
        func_0208fe30(0x10020);
        M2C_FIELD(data_ov000_021df5e0, u8 *, 0x10)++;
        M2C_FIELD(data_ov000_021df5e0, u8 *, 0x10) &= 1;
        func_ov000_0216dd0c();
    }
}

void func_ov000_0216eb7c(void) {
    M2C_UNK func_0209bfa8();
    M2C_UNK func_020e35cc();
    extern s32 data_ov000_021df5e0;
    if (data_ov000_021df5e0 != 0) {
        func_020e35cc();
        data_ov000_021df5e0 = 0;
    }
    func_0209bfa8();
}

void func_ov000_0216ebac(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020b21e0();
    M2C_UNK func_020b2268();
    extern M2C_UNK data_ov000_021b87b8;
    func_0208fe30(0x10018);
    func_020b21e0();
    func_020b2268();
    func_01ffa3dc(&data_ov000_021b87b8, 7);
}

void func_ov000_0216ebd8(M2C_UNK arg0) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern void **gCurrentMap;
    extern M2C_UNK data_ov000_021b87f0;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_ov000_021b87f0, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, u16 *, 0x6C) = (u16) M2C_FIELD(*gCurrentMap, u16 *, 0x52A4);
    M2C_FIELD(temp_r0, s16 *, 0x6E) = 0;
}

s32 func_ov000_0216ec1c(void){extern u8 *data_ov000_021df5e4[2];extern void **gCurrentMap;extern u16 data_ov000_021aeef4[];s32 i,n;void *base;u8 (*entries)[14];u16 start;for(i=0;i<64;i++)data_ov000_021df5e4[1][i]=0;base=*gCurrentMap;start=data_ov000_021aeef4[M2C_FIELD(base,u16 *,0x52a4)];for(i=start+1;i<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+51;i++){entries=base+0x59a4;if((u32)(entries[i][0]<<26)>>26)n++;}return n;}

