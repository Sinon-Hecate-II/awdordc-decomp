/* 12 functions from 0x02017158 to 0x020180C8 (main), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_02136c40;

#pragma push
#pragma optimization_level 2
u32 func_02017984(void){u8 buf[6];s32 i;u32 sum;u8 *p;func_02007724(buf);i=0;p=&buf[i];sum=0;do{sum+=*p++;i++;}while(i<6);return ((sum+*(u32 *)0x27ffc3c)*7)%20;}
s32 func_02017bd0(u32 arg0, u32 arg1, s32 arg2) {
    if ((arg0 > 0x1FEU) || (arg0 < 0xE4U)) {
        return 0;
    }
    if ((arg1 > 0x10U) || (arg1 < 8U)) {
        return 0;
    }
    if ((s32) ((arg2 * (((arg1 + 0x20) * 4) + 0x70)) + (((arg0 + 0x26) * 4) + 0x14A)) < 0x15E0) {
        return 1;
    }
    return 0;
}

s32 func_02017c40(u32 a,u32 b){s32 t;void *p;t=func_0200751c();if(M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u8 *,0x50d)){func_02007530(t);return 0;}if(!func_02017bd0(a,8,b)){func_02007530(t);return 0;}p=&data_02136c40;M2C_FIELD(M2C_FIELD(p,void **,8),u16 *,16)=b;M2C_FIELD(M2C_FIELD(p,void **,8),u16 *,0x500)=a;M2C_FIELD(M2C_FIELD(p,void **,8),u16 *,0x502)=8;func_02007530(t);return 1;}

s32 func_02017cd8(void) {
s32 v; void *p;
M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u16 *,0x528)=0;
M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u16 *,0x52a)=0;
M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u16 *,0x526)=0;
M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u16 *,0x548)=0;
func_02018254(10); p=&data_02136c40;
if(!M2C_FIELD(M2C_FIELD(p,void **,12),s32 *,0x1320)){
v=func_02012218(M2C_FIELD(&data_02136c40,s32 *,4),M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),s32 *,0x508),M2C_FIELD(&data_02136c40,u16 *,0));
if(v==4)goto ready; if(v!=2)return 8;
ready:
func_020119dc(M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),s32 *,0x508));
M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u8 *,0x50d)=1;
return 0;
}
func_020119dc(M2C_FIELD(M2C_FIELD(p,void **,8),s32 *,0x508));
M2C_FIELD(M2C_FIELD(p,void **,8),u8 *,0x50d)=1;
func_020168a0();return 0;
}

void func_02017f90(s32 a){M2C_FIELD(M2C_FIELD(&data_02136c40,void **,12),s32 *,0x1320)=1;func_02017dac(a);}

s32 func_02017fb4(void) {
    s32 func_02012274(s32);
    M2C_UNK func_02018438(M2C_UNK, s32);
    extern M2C_UNK data_02136c40;
    s32 var_r4;

    var_r4 = func_02012274(M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 8), s32 *, 0x508));
    func_02018438(1, var_r4);
    if (var_r4 == 2) {
        var_r4 = 0;
    }
    return var_r4;
}

void func_02017fec(void) {
    M2C_UNK func_02017fb4();
    func_02017fb4();
}

s32 func_02017ff8(void){s32 t;u32 v=1;t=func_0200751c();if(!M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u8 *,0x50d))func_020168f0(0);else if(!M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u16 *,0x526)){M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),s32 *,0x5e4)=0;M2C_FIELD(M2C_FIELD(&data_02136c40,void **,8),u16 *,0x526)=v;v=func_0201871c();if(v){func_020188c8(func_02017fec);v=0;}else v=func_02017fb4();}func_02007530(t);return v;}
#pragma pop
void func_0201808c(void){s32 t=func_0200751c();if(!M2C_FIELD(M2C_FIELD(&data_02136c40,void **,12),s32 *,0x1320))func_02007958();func_02017ff8();func_02007530(t);}

