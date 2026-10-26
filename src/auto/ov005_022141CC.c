/* 12 functions from 0x022141CC to 0x02215168 (ov005), found by ds-decomp. */
#include "common.h"

s32 func_ov005_022141cc(void) {
extern M2C_UNK data_ov005_02221304;
s16 n=M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x98);
s32 next=n+6;
if(next>=M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x9a))return 0;
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x98)++;
func_0208fe30(0x10019);return 1;
}

s16 func_ov005_02214210(void) {
    extern M2C_UNK data_ov005_02221304;
    s16 temp_r3;
    s32 temp_r1;

    temp_r3 = M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98);
    M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) = (s16) (temp_r3 + 6);
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x9A) - 6;
    if ((s32) M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) > temp_r1) {
        M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) = (s16) temp_r1;
    }
    return (s16) (M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x98) - temp_r3);
}

void func_ov005_02214f80(s32 a) {
void *func_020ad570(s32);
extern M2C_UNK data_ov005_02221304;
func_020901e0(M2C_FIELD(func_020ad570(a),s32 *,0));
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x8e)=a;
if(M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x92)==0)
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xa0)=-1;
else M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xa0)=M2C_FIELD(func_020ad570(a),s32 *,8)+0x258;
func_ov005_022148f0(M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x96));
}

void func_ov005_02214fec(s32 a) {
s32 func_ov005_022140f8(s32);
void func_ov005_022172d8(s32,s32);
extern M2C_UNK data_ov005_02221304;
switch(M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x92)) {
case 0: case 1:
if(func_ov005_022140f8(a))func_ov005_022172d8(a,1);
break;
case 2:
if(func_ov005_022140f8(a)&&M2C_FIELD((char *)M2C_FIELD(&data_ov005_02221304,void **,8)+a,u8 *,0xa2)==1) {
func_ov005_02214e18(a);
func_ov005_022172d8(M2C_FIELD((s16 *)M2C_FIELD(&data_ov005_02221304,void **,8)+M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2),s16 *,0xe6),1);
} else if(func_ov005_022140f8(a)&&M2C_FIELD((char *)M2C_FIELD(&data_ov005_02221304,void **,8)+a,u8 *,0xa2)==0) {
func_ov005_02214e18(-1);
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2)=-1;
func_ov005_022172d8(a,1);
}
break;
}
}

void func_ov005_022150d8(s16 a) {
s32 func_ov005_022140f8(s32);
void func_ov005_022172d8(s32,s32);
void func_ov005_02215200(s16);
void func_ov005_022152ec(s16);
extern M2C_UNK data_ov005_02221304;
switch(M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x92)){
case 0:
M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x8e)=a;
do {
a--;
if(a==-1){
a=M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x8e);
break;
}
}while(!func_ov005_022140f8(a));
func_ov005_022172d8(a,1);break;
case 1:func_ov005_02215200(a);break;
case 2:func_ov005_022152ec(a);break;
}
}

