/* 4 functions from 0x02099B18 to 0x02099E6C (main), found by ds-decomp. */
#include "common.h"

u8 func_02099ae8(u8 *arg0);
u8 func_02099b00(u8 *arg0);
#pragma opt_propagation off
s32 func_02099b18(M2C_UNK arg0,M2C_UNK arg1,M2C_UNK arg2){
u8 *p=(u8 *)arg0;
s32 want=arg1;
s32 allow=arg2;
s32 base;
s32 step;
u32 c;
if(!p)return 0;
while((c=*p)!=0){
base=0;
step=base;
switch(c){
case 2:case 4:case 5:case 6:case 10:case 13:
step=base+1;if(!allow)return base;break;
case 3:step=base+2;break;
case 11:step=base+1;if((u8)(p[1]+0x80)<=1)step=base+2;break;
case 8:step=base+1;
if(c>=0x80 && c<=0x99)step=base+2;
else if(c>=0x9a && c<=0xb3)step++;
break;
case 16:
switch(p[2]){
case 0x80:step=base+5;break;
case 0x8d:step=base+4;break;
case 0x8c:step=base+4;break;
case 0x8a:step=base+3;break;
case 0x8b:step=base+3;break;
case 0x8e:step=base+3;break;
case 0x86:step=base+3;break;
case 0x88:step=base+3;break;
case 0x89:step=base+3;break;
}
break;
case 17:
switch(p[2]){
case 0x80:step=base+5;break;
case 0x81:step=base+4;break;
case 0x82:step=base+4;break;
case 0x83:step=base+4;break;
case 0x84:step=base+3;break;
case 0x85:step=base+3;break;
case 0x86:step=base+3;break;
case 0x87:step=base+5;break;
case 0x88:step=base+3;break;
case 0x89:step=base+3;break;
}
break;
case 18:case 26:case 30:step=base+1;break;
case 19:if(p[1]==0x80)step=base+2;else step=base+3;break;
case 20:step=base+3;break;
case 21:case 22:case 23:case 24:case 25:case 27:case 28:case 29:step=base+2;break;
default:
if(func_02099ae8(p))step+=2;
else if(func_02099b00(p))step+=2;
else step++;
goto advance;
}
if(want==c)return (s32)p;
advance:p+=step;
}
return 0;
}
#pragma opt_propagation reset
u8 func_02099dcc(M2C_UNK arg0) {
    s32 func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    u8 var_r0;

    if (func_02099b18(arg0, 5, 1) != 0) {
        return 0U;
    }
    if (func_02099b18(arg0, 6, 1) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_02099e10(M2C_UNK arg0) {
    s32 func_02099b18(M2C_UNK, M2C_UNK, M2C_UNK);
    void *temp_r0;
    u8 value;
    temp_r0 = (void *)func_02099b18(arg0, 0x15, 1);
    if (temp_r0 != NULL) {
        value = M2C_FIELD(temp_r0, u8 *, 1);
        if (value == 0x80) return 0;
        if (value == 0x81) return 1;
        if (value == 0x82) return 2;
    }
    return 1;
}

void func_02099e58(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x55) = 0;
    M2C_FIELD(arg0, s8 *, 0x54) = -2;
}
