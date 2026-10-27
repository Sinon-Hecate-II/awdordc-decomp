/* 23 functions from 0x020CAB8C to 0x020CBACC (main), found by ds-decomp. */
#include "common.h"
extern u8 data_0212b1b8[][4];

void func_020cab8c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b4a4;
    func_01ffa3dc(&data_0212b4a4, 7);
}

s32 func_020caba4(s32 a,s32 b,s32 c){
 extern void **gCurrentMap;
 s32 i=0;u8 *q;void *p;s32 x;
 do{
 if(c&data_0212b1b8[i][0]){
 p=*gCurrentMap;q=(u8 *)data_0212b1b8+((u32)i<<2);
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
 extern void **gCurrentMap;
 s32 n;void *p;
 p=*gCurrentMap;
 n=func_020ba1fc(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de),M2C_FIELD((M2C_FIELD(p,s32 *,0x52d0)+M2C_FIELD(arg0,s16 *,0x70)),u8 *,0xc));
 func_01ffb554((u8 *)*gCurrentMap+0x1e30);func_01ffb3d0(-1);
 p=*gCurrentMap;func_020cdf30(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de),n);func_0207a748(0);
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

s32 func_020cad1c(s32 *arg0, s32 arg1) {
    s32 func_020bcbd8(void);
    s32 func_020cac1c(s32, s32);
    s32 func_020cac3c(s32, s32);
    void func_020bda88(s32 *, s32);
    void func_0208fe30(s32);
    void func_020cf5ec(s32);
    s32 func_020bcb94(void);
    s32 func_020bdbf4(s32);
    extern void **gCurrentMap;
    extern s8 data_0212b1ba[];
    extern s8 data_0212b1bb[];
    s32 sp0;
    s32 old;
    s32 result_r6;
    void *map;

    sp0 = *arg0;
    old = *arg0;
    result_r6 = func_020bcbd8();
    if (result_r6 & 8) {
        sp0 = func_020cac1c(sp0, arg1);
    }
    if (result_r6 & 4) {
        sp0 = func_020cac3c(sp0, arg1);
    }
    func_020bda88(&sp0, arg1);
    if (sp0 != old) {
        *arg0 = sp0;
        func_0208fe30(0x1001A);
    }
    map = *gCurrentMap;
    M2C_FIELD(map, s16 *, 0x52C2) = (s16)(M2C_FIELD(map, s16 *, 0x52DC) + data_0212b1ba[sp0 * 4]);
    map = *gCurrentMap;
    M2C_FIELD(map, s16 *, 0x52C4) = (s16)(M2C_FIELD(map, s16 *, 0x52DE) + data_0212b1bb[sp0 * 4]);
    func_020cf5ec(1);
    result_r6 = func_020bcb94();
    result_r6 = result_r6 | func_020bdbf4(arg1);
    if (result_r6 & 0x20) {
        return 0x20;
    }
    if (result_r6 & 0x10) {
        return 0x10;
    }
    return 0;
}

void func_020caf3c(void *arg0) {
    M2C_UNK func_020d472c();
    s32 func_020c6384();
    s32 func_020c6414();
    M2C_UNK func_020c75cc();
    M2C_UNK func_020c9580(u8);
    M2C_UNK func_020d468c();
    M2C_UNK func_020a15e4();
    u8 func_020c9440(s16, s16, s32);
    M2C_UNK func_ov000_02199f50(s32, u8, u8, u8);
    extern void **gCurrentMap;
    void *base;
    s32 a, b;

    func_020d472c();
    if ((func_020c6384() == 0) || (func_020c6414() == 0)) {
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DC);
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DE);
        func_020c9580((u8) M2C_FIELD(arg0, s16 *, 0x70));
        func_020c75cc();
        return;
    }
    func_020d468c();
    func_020a15e4();
    base = *gCurrentMap;
    a = func_020c9440(M2C_FIELD(base, s16 *, 0x52DC), M2C_FIELD(base, s16 *, 0x52DE), 0);
    b = func_020c9440(M2C_FIELD(base, s16 *, 0x52DC), M2C_FIELD(base, s16 *, 0x52DE), 1);
    func_ov000_02199f50(8, M2C_FIELD(*gCurrentMap, u8 *, 0x52D4), (u8) a, (u8) b);
}

void func_020cb00c(void) {
    M2C_UNK func_0207a768();
    func_0207a768();
}

void func_020cb018(s16 arg0) {
    extern M2C_UNK data_0212b374;
    M2C_FIELD(func_01ffa3dc(&data_0212b374, 7), s16 *, 0x70) = arg0;
}

s32 func_020cb170(void *arg0, s32 arg1) {
    s32 func_0207c8ec(s32, M2C_UNK);
    M2C_UNK func_020d2b10(u16, u16);
    extern void **gCurrentMap;
    extern M2C_UNK data_ov000_021b5bfc;
    u8 *tab;
    s32 var_r7;
    u32 temp_r0;
    u16 temp_r8;
    u16 temp_r0_2;
    u8 temp_r1_2;
    void *temp_r1;

    var_r7 = 0;
    temp_r0 = (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19;
    temp_r8 = temp_r0 ? (func_0207c8ec(temp_r0 - 1, 0xA) + 1) : var_r7;
    tab = (u8 *) &data_ov000_021b5bfc;
loop_4:
    if (((u32) (M2C_FIELD(arg0, u8 *, 0xA) << 0x19) >> 0x19) != tab[((u32) (M2C_FIELD(arg0, u8 *, 0) << 0x1A) >> 0x1A) * 0x70 + 0xE]) {
        if (arg1 != 0) {
            temp_r1 = *gCurrentMap;
            temp_r0_2 = M2C_FIELD(temp_r1, u16 *, 0x52A4);
            if ((s32) M2C_FIELD(((temp_r0_2 * 0x8C) + (s32) temp_r1), s32 *, 0x67A4) >= (s32) temp_r8) {
                func_020d2b10(temp_r0_2, temp_r8);
                goto block_8;
            }
        } else {
block_8:
            temp_r1_2 = M2C_FIELD(arg0, u8 *, 0xA);
            var_r7 += temp_r8;
            M2C_FIELD(arg0, u8 *, 0xA) = (u8) ((temp_r1_2 & ~0x7F) | ((u8) (((u32) (temp_r1_2 << 0x19) >> 0x19) + 1) & 0x7F));
            goto loop_4;
        }
    }
    return var_r7;
}

s32 func_020cb3a4(s32 a,s32 b){extern void **gCurrentMap;s32 func_020a7e08(void *);u8 *base=*gCurrentMap;u8 *start=base+0x59a4;u8 *p=start+(s16)base[a+((u16 *)(base+0x3758))[b]]*14;s32 index=p?(p-start)/14:0;if(M2C_FIELD(base,u16 *,0x52a8)==(index&0xc0) && func_020a7e08(p))return 1;return 0;}

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

void func_020cb704(void *a){s32 func_020ba510(s32,s32);extern s32 data_0215be0c;extern void **gCurrentMap;u16 i=0;data_0215be0c=0;do{void *p=*gCurrentMap;s32 n=func_020ba510(M2C_FIELD(p,s16 *,0x52dc)+(s8)data_0212b1b8[i][2],M2C_FIELD(p,s16 *,0x52de)+(s8)data_0212b1b8[i][3]);data_0215be0c = (data_0212b1b8[i][0]*n) | data_0215be0c;i++;}while(i<4);M2C_FIELD(a,s16 *,0x34)=0;}

void func_020cb8cc(s32 a) {
extern M2C_UNK data_0212b3ac;
void *p=func_01ffa3dc(&data_0212b3ac,7);
if(a) M2C_FIELD(p,s16 *,0x36)=0;
else M2C_FIELD(p,s16 *,0x36)=1;
}

void func_020cb8f8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x50) = 1;
}

