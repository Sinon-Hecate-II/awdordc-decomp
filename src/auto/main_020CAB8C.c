/* 23 functions from 0x020CAB8C to 0x020CBACC (main), found by ds-decomp. */
#include "common.h"
extern u8 data_0212b1b8[][4];

void func_020cab8c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b4a4;
    func_01ffa3dc(&data_0212b4a4, 7);
}

s32 func_020caba4(s32 a,s32 b,s32 c){
 extern void **data_027e0058;
 s32 i=0;u8 *q;void *p;s32 x;
 do{
 if(c&data_0212b1b8[i][0]){
 p=*data_027e0058;q=(u8 *)data_0212b1b8+((u32)i<<2);
 x=M2C_FIELD(p,s16 *,0x52dc);
 if(a==x+M2C_FIELD(q,s8 *,2) && b==M2C_FIELD(p,s16 *,0x52de)+M2C_FIELD(q,s8 *,3))return i;
 } i++;
 }while(i<4);return -1;
}

s32 func_020cac1c(s32 a,s32 b){do{a=(a+1)&3;}while(!(b&data_0212b1b8[a][0]));return a;}

s32 func_020cac3c(s32 a,s32 b){do{a=(a-1)&3;}while(!(b&data_0212b1b8[a][0]));return a;}

void func_020cac5c(void *arg0) {
 M2C_UNK func_01ffb3d0(M2C_UNK); M2C_UNK func_01ffb554(void *); M2C_UNK func_0207a748(M2C_UNK);
 s32 func_020ba1fc(s16,s16,u8); M2C_UNK func_020cdf30(s16,s16,s32);
 extern void **data_027e0058;
 s32 n;void *p;
 p=*data_027e0058;
 n=func_020ba1fc(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de),M2C_FIELD((M2C_FIELD(p,s32 *,0x52d0)+M2C_FIELD(arg0,s16 *,0x70)),u8 *,0xc));
 func_01ffb554((u8 *)*data_027e0058+0x1e30);func_01ffb3d0(-1);
 p=*data_027e0058;func_020cdf30(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de),n);func_0207a748(0);
 M2C_FIELD(arg0,s16 *,0x6c)=n;M2C_FIELD(arg0,s16 *,0x6e)=3;
 M2C_FIELD(arg0,s16 *,0x6e)=func_020cac1c(M2C_FIELD(arg0,s16 *,0x6e),n);
}

void func_020cad00(s32 arg0) {
    M2C_UNK func_0208fb0c(M2C_UNK);
    if ((arg0 != 1) && (arg0 != 2)) {
        return;
    }
    func_0208fb0c(0x7C);
}

void func_020cb00c(void) {
    M2C_UNK func_0207a768();
    func_0207a768();
}

void func_020cb018(s16 arg0) {
    extern M2C_UNK data_0212b374;
    M2C_FIELD(func_01ffa3dc(&data_0212b374, 7), s16 *, 0x70) = arg0;
}

s32 func_020cb3a4(s32 a,s32 b){extern void **data_027e0058;s32 func_020a7e08(void *);u8 *base=*data_027e0058;u8 *start=base+0x59a4;u8 *p=start+(s16)base[a+((u16 *)(base+0x3758))[b]]*14;s32 index=p?(p-start)/14:0;if(M2C_FIELD(base,u16 *,0x52a8)==(index&0xc0) && func_020a7e08(p))return 1;return 0;}

u8 func_020cb6a4(void *arg0) {
s32 func_020a8604(u32);
u8 func_020c98d8(u8,u8,s32);
s32 func_020cb038(void *,s32);
s32 func_020cb170(void *,s32);
s32 n=0;
if(func_020a8604((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)==0) n+=func_020cb038(arg0,0);
n+=func_020cb170(arg0,0);
if(n==0) return n;
return func_020c98d8(M2C_FIELD(arg0,u8 *,1),M2C_FIELD(arg0,u8 *,2),2);
}

void func_020cb704(void *a){s32 func_020ba510(s32,s32);extern s32 data_0215be0c;extern void **data_027e0058;u16 i=0;data_0215be0c=0;do{void *p=*data_027e0058;s32 n=func_020ba510(M2C_FIELD(p,s16 *,0x52dc)+(s8)data_0212b1b8[i][2],M2C_FIELD(p,s16 *,0x52de)+(s8)data_0212b1b8[i][3]);data_0215be0c = (data_0212b1b8[i][0]*n) | data_0215be0c;i++;}while(i<4);M2C_FIELD(a,s16 *,0x34)=0;}

void func_020cb8cc(s32 a) {
extern M2C_UNK data_0212b3ac;
void *p=func_01ffa3dc(&data_0212b3ac,7);
if(a) M2C_FIELD(p,s16 *,0x36)=0;
else M2C_FIELD(p,s16 *,0x36)=1;
}

void func_020cb8f8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x50) = 1;
}

