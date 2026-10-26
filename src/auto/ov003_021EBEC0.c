/* 8 functions from 0x021EBEC0 to 0x021ECCD4 (ov003), found by ds-decomp. */
#include "common.h"

void func_ov003_021ec4e4(u8 *p) {
s32 func_020848c4(void);
s32 func_ov003_021e6cfc(void);
s32 func_ov003_021e6d28(void);
s32 func_ov003_021e6eb8(u8);
u8 v=p[9];
u8 t;
if(func_ov003_021e6cfc()!=0) {
t=(p+p[7])[0x74];
if(t!=func_020848c4()) {
if((u8)((p+p[7])[0x74]==255)==0)goto update;
}
}
if(func_ov003_021e6d28()!=0) {
t=(p+p[7])[0x74];
if(t!=func_020848c4())goto update;
}
if(func_ov003_021e6eb8(v)==0)return;
update:
(p+p[7])[10]=v;
p[8]=v;
}

void func_ov003_021ec780(u8 *p,s32 i) {p+=14;p[i]=p[i]==1?2:1;}

s32 func_ov003_021ecc68(M2C_UNK a,M2C_UNK b) {
s32 func_020846a4(void);
s32 func_ov003_021e6cfc(void);
s32 func_ov003_021e6e08(M2C_UNK);
M2C_UNK func_ov003_021e6e18(M2C_UNK);
s32 t;
if(func_020846a4()==0)return 1;
t=func_ov003_021e6e08(b);
func_ov003_021e6e18(b);
if(t==0||t==25||t==8)return 1;
if(t==4)return 0;
if(func_ov003_021e6cfc()!=0 && t==21)return 1;
return 0;
}

