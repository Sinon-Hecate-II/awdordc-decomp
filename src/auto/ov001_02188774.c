/* 25 functions from 0x0218851C to 0x021893E4 (ov001), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK data_ov001_0219169c;
extern M2C_UNK data_ov001_0219166c, data_ov001_02191684, data_ov001_021916cc;

#pragma peephole off

#pragma peephole reset

/* Initialize the active map state pointed to by the global from the allocated buffer p and the config a. */

s32 func_ov001_02188774(void) {
extern M2C_UNK data_ov001_02193e20;
s32 func_ov001_0218880c(void);
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,4772)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,4768)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,72)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),u16 *,80)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),u16 *,82)=1;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,84)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,0)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),u16 *,4)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4),s32 *,76)=0;
return func_ov001_0218880c()!=0;
}

