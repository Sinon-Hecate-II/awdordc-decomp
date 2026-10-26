/* 3 functions from 0x02197814 to 0x02197A8C (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_0219798c(void) {

}

void func_ov000_02197990(void){extern void **data_027e0058;void *p;u8 t;u32 k,j;if(!func_ov000_021973f8((u32)(*M2C_FIELD(*data_027e0058,u8 **,0x52d0)<<26)>>26))return;func_01ffb554(*data_027e0058+0x2d48);p=*data_027e0058+0x58a4;while((u32)(M2C_FIELD(p,u16 *,2)<<22)>>28){if(M2C_FIELD(p,s8 *,6)==1){t=M2C_FIELD(p,u8 *,5);j=(u32)(t<<28);if((j>>31)!=0 || (k=(u32)(t<<29)>>29)==0 || !func_020d273c(M2C_FIELD(*data_027e0058,u16 *,0x52a4),k))func_020a5364(p,-1,0);}p+=8;}func_01ffb554(*data_027e0058+0x1e30);}

