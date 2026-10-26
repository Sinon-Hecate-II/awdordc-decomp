/* 9 functions from 0x0221C534 to 0x0221D008 (ov007), found by ds-decomp. */
#include "common.h"

/* Initialize the map scene: load map data, fill tile slots, and center the viewport. */
void func_ov007_0221c534(void) {
M2C_UNK func_0207b754(u32,u32); M2C_UNK func_020cf498(s16,s16);
M2C_UNK func_020cfd28(); M2C_UNK func_ov007_022121b0();
M2C_UNK func_ov007_022121d4(M2C_UNK); M2C_UNK func_ov007_0221ab68();
extern void **data_027e0058;
M2C_UNK func_020c857c(M2C_UNK); M2C_UNK func_ov007_0221c27c(M2C_UNK);
M2C_UNK func_ov007_0221bee4(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov007_0221c030(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK func_ov007_0221c250();
s32 slot1,slot2,slot3,slot1b,slot2b,slot3b; u32 viewX,viewY; void *state;
func_020c857c(M2C_FIELD(*data_027e0058,u16 *,0x5142));
slot1=func_ov007_0221c27c(1);slot2=func_ov007_0221c27c(2);slot3=func_ov007_0221c27c(3);
func_ov007_0221bee4(slot1,slot2,slot3,func_ov007_0221c27c(4));
slot1b=func_ov007_0221c27c(1);slot2b=func_ov007_0221c27c(2);slot3b=func_ov007_0221c27c(3);
func_ov007_0221c030(slot1b,slot2b,slot3b,func_ov007_0221c27c(4));
func_ov007_0221c250(); func_020cfd28(); func_ov007_022121b0(); func_ov007_0221ab68();
state=*data_027e0058;
viewX=(u32)M2C_FIELD(state,u16 *,0x5144)>>1;
viewY=(u32)M2C_FIELD(state,u16 *,0x5146)>>1;
func_020cf498((s16)viewX,(s16)viewY);func_0207b754(viewX,viewY);func_ov007_022121d4(0);
}

void func_ov007_0221c630(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_02220178;
    func_01ffa3dc(&data_ov007_02220178, 7);
}

void func_ov007_0221c648(M2C_UNK arg0) {
    M2C_UNK func_020bfebc(M2C_UNK);
    M2C_UNK func_020c002c(s32);
    s32 func_020c7e98(M2C_UNK);
    s32 func_020c7eb8();
    M2C_UNK func_020c857c(M2C_UNK);
    M2C_UNK func_ov007_02214814(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov007_0221bee4(s32, s32, s32, s32);
    M2C_UNK func_ov007_0221c030(s32, s32, s32, s32);
    M2C_UNK func_ov007_0221c250();
    s32 func_ov007_0221c27c(M2C_UNK);
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    s32 temp_r6_2;

    if (func_020c7eb8() == 0) {
        func_ov007_02214814(0x14, 0x14);
        return;
    }
    temp_r4 = func_020c7e98(arg0);
    func_020c857c(arg0);
    func_020c002c(temp_r4);
    func_020bfebc(0);
    temp_r6 = func_ov007_0221c27c(1);
    temp_r5 = func_ov007_0221c27c(2);
    temp_r4_2 = func_ov007_0221c27c(3);
    func_ov007_0221bee4(temp_r6, temp_r5, temp_r4_2, func_ov007_0221c27c(4));
    temp_r6_2 = func_ov007_0221c27c(1);
    temp_r5_2 = func_ov007_0221c27c(2);
    temp_r4_3 = func_ov007_0221c27c(3);
    func_ov007_0221c030(temp_r6_2, temp_r5_2, temp_r4_3, func_ov007_0221c27c(4));
    func_ov007_0221c250();
}

void func_ov007_0221cd5c(void) {
    M2C_UNK func_ov007_0221c718();
    func_ov007_0221c718();
}

void func_ov007_0221cfe8(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov007_0221cffc(void) {
    M2C_UNK func_ov007_0221c718();
    func_ov007_0221c718();
}

