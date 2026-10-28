/* 12 functions from 0x02017158 to 0x020180C8 (main), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_02136c40;
extern M2C_UNK data_020f5550;

#pragma push
#pragma optimization_level 2
s32 func_02017158(M2C_UNK arg0) { return 0; }

u32 func_02017984(void){u8 buf[6];s32 i;u32 sum;u8 *p;func_02007724(buf);i=0;p=&buf[i];sum=0;do{sum+=*p++;i++;}while(i<6);return ((sum+*(u32 *)0x27ffc3c)*7)%20;}

s32 func_020179ec(u32 arg0, u8 *arg1, s32 arg2, u32 arg3, u32 arg4) {
    void func_02007e54(s32, void *, s32);
    void func_02007df8(s32, void *, s32);
    void func_02008048(void *, void *, s32);
    u16 func_02012084(void);
    s32 func_0200751c(void);
    u32 func_02017984(void);
    u32 a, b, id;
    u16 *d, *p, *s;
    u16 v;
    s32 t, i, j;

    if (M2C_FIELD(&data_02136c40, void **, 0xc) != NULL &&
        M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 0xc), u16 *, 0x1316) != 0)
        return 2;
    a = (arg0 + 0x1f) & ~0x1f;
    b = (a + 0x1e1f) & ~0x1f;
    id = arg3;
    if (arg3 == 0x10000)
        id = func_02012084();
    t = func_0200751c();
    M2C_FIELD(&data_020f5550, u16 *, 6) = 0xffff;
    M2C_FIELD(&data_020f5550, u16 *, 0) = 5;
    M2C_FIELD(&data_020f5550, u16 *, 2) = 0x28;
    M2C_FIELD(&data_020f5550, u16 *, 4) = 0x28;
    M2C_FIELD(&data_020f5550, s32 *, 0xc) = 1;
    M2C_FIELD(&data_02136c40, u16 *, 0) = arg4;
    M2C_FIELD(&data_02136c40, u32 *, 8) = a;
    M2C_FIELD(&data_02136c40, u32 *, 0xc) = b;
    func_02007e54(0, (void *)a, 0x1e00);
    func_02007df8(0, (void *)b, 0x1340);
    d = (u16 *)(a + 0x530);
    i = 0;
    if (arg1[1] > 0) {
        do {
            *d++ = M2C_FIELD(arg1 + 2, u16 *, i * 2);
            i++;
        } while (i < arg1[1]);
    }
    d = (u16 *)(a + 0x538);
    j = 0;
    p = M2C_FIELD(&data_020f5550, u16 **, 8);
    do {
        v = *p;
        if (v == 0)
            break;
        p++;
        M2C_FIELD(&data_020f5550, u16 **, 8) = p;
        *d++ = v;
        j++;
    } while (j < 16);
    func_02008048(arg1, (void *)(b + 0x1300), 0x16);
    if (arg1[1] < 10)
        M2C_FIELD((u8 *)b + 0x1302, u16 *, arg1[1] * 2) = 0;
    s = (u16 *)(a + 0x500);
    s[0] = 0x100;
    s[1] = 8;
    s[0xc] = 0;
    s[0xd] = 0;
    s[0x16] = 1;
    M2C_FIELD(a, u32 *, 0x504) = b + 0x400;
    M2C_FIELD(a, u16 *, 0xe) = 0;
    M2C_FIELD(a, u16 *, 0x12) = 0;
    M2C_FIELD(a, u16 *, 0x16) = 1;
    M2C_FIELD(a, u16 *, 0x14) = 0;
    M2C_FIELD(a, s32 *, 8) = arg2;
    M2C_FIELD(a, u16 *, 0xc) = id;
    M2C_FIELD(a, u16 *, 0x18) = func_02017984() + 0xc8;
    M2C_FIELD(a, u16 *, 0x10) = 0xf;
    M2C_FIELD(a, u8 *, 0x50c) = 0;
    M2C_FIELD(a, u8 *, 0x50d) = 0;
    M2C_FIELD(b, u16 *, 0x1316) = 1;
    M2C_FIELD(b, s32 *, 0x131c) = 0;
    func_02007530(t);
    return 0;
}

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

s32 func_02017dac(s32 arg0) {
    s32 func_0200751c(void);
    s32 func_02007530(s32);
    void func_02007df8(s32, void *, s32);
    void func_02013e70(s32);
    void func_02018910(s32);
    void func_02018940(void *);
    void func_02016200(void);
    s32 func_02017cd8(void);
    s32 func_02009e8c(s32, s32);
    void func_020140c4(void);
    void func_02016934(void);
    void func_02007f8c(void *, s32, s32);

    s32 state;
    s32 i;
    s32 res;

    state = func_0200751c();

    M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 0x8), u16 *, 0x32) = arg0;

    M2C_FIELD(&data_02136c40, u32 *, 0x4) =
        ((u32)M2C_FIELD(&data_02136c40, void **, 0xc) + 0x1F + 0x7D00) & ~0x1FU;

    {
        s32 r6 = M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0xc) + 0x1000, s32 *, 0x4E4);
        func_02007df8(0, (u8 *)M2C_FIELD(&data_02136c40, void **, 0xc) + 0x1340, 0x69C0);
        func_02013e70(r6);
    }

    M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0xc) + 0x1000, s32 *, 0x318) =
        M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0x8) + 0x500, u16 *, 0) - 6;

    func_02018910(M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0x8) + 0x500, u16 *, 2));

    func_02018940((u8 *)M2C_FIELD(&data_02136c40, void **, 0xc) + 0x1538);

    i = 0;
    do {
        M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0xc) + 0x1000, s32 *, 0x4E8 + i * 4) = 0;
        M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0xc) + i + 0x1000, s8 *, 0x526) = -1;
        i++;
    } while (i < 15);

    M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0xc) + 0x1000, u8 *, 0x524) = 0;

    M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0xc) + 0x1000, u32 *, 0x320) = 0;

    func_02007df8(0, (u8 *)M2C_FIELD(&data_02136c40, void **, 0xc) + 0x1788, 0x5D40);

    func_02007f8c((u8 *)M2C_FIELD(&data_02136c40, void **, 0xc) + 0x1754, 0, 0x1E);

    M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0x8) + 0x500, u16 *, 0x24) = 1;

    M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 0x8), s32 *, 0x51C) = (s32 *)func_020140c4;
    M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 0x8), s32 *, 0x508) = (s32 *)func_02016934;

    M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 0x8), u16 *, 0x34) =
        M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0x8) + 0x500, u16 *, 0);

    M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0x8) + 0x500, u16 *, 0x18) =
        (M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 0x8), u16 *, 0x34) + 0x23) & ~0x1FU;

    M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 0x8), u16 *, 0x36) =
        M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0x8) + 0x500, u16 *, 2);

    M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0x8) + 0x500, u16 *, 0x1A) =
        ((((M2C_FIELD(M2C_FIELD(&data_02136c40, void **, 0x8), u16 *, 0x36) + 0xE) * 15) + 0x29) & ~0x1FU) << 1;

    func_02016200();
    res = func_02017cd8();
    func_02007530(state);

    M2C_FIELD((u8 *)M2C_FIELD(&data_02136c40, void **, 0xc) + 0x7000, u32 *, 0x4C8) =
        func_02009e8c(0xF, 0x1);

    (void)i;
    return res;
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

