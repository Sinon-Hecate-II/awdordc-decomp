/* 17 functions from 0x02179E74 to 0x0217AE38 (ov001), found by ds-decomp. */
#include "common.h"
void func_ov001_0217a880(void);

void func_ov001_02179e74(void) {
    extern s8 data_ov001_02193d94;
    void func_ov001_02179dc8(void);
    M2C_FIELD(&data_ov001_02193d94,u8 *,0) = M2C_FIELD(&data_ov001_02193d94,u8 *,0) + 1;
    if ((u32)M2C_FIELD(&data_ov001_02193d94,u8 *,0) < 120U) return;
    func_ov001_02175d54((M2C_UNK *)&func_ov001_02179dc8);
}

void func_ov001_02179ea8(void) {
    extern M2C_UNK data_ov001_02193d98;
    M2C_UNK func_ov001_0218b6f8(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175db4(M2C_UNK *, M2C_UNK);
    M2C_UNK func_ov001_02184170(M2C_UNK);
    void func_ov001_02179f80(void);
    void func_ov001_021722ac(void);
    M2C_UNK func_ov001_02171c24(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_02171dd0(M2C_UNK);
    void func_ov001_0217a0d4(void);
    void func_ov001_0217a17c(void);
    M2C_UNK func_ov001_0218ad0c(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218c884(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov001_0217ac18(void);
    void func_ov001_0217b130(void);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    void func_ov001_0217b0d4(void);
    void func_ov001_0217a2f0(void);
    s32 temp;

    M2C_FIELD(&data_ov001_02193d98, void **, 4) = func_ov001_0218b6f8((M2C_UNK)0x5c, (M2C_UNK)4);
    func_ov001_02175db4(&temp, 0);
    if (temp == 0) {
        M2C_FIELD(&data_ov001_02193d98, u8 *, 0) = 0;
        M2C_FIELD(&data_ov001_02193d98, u16 *, 2) = 0;
    }
        M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x51) =
            (u8)func_ov001_02184170(M2C_FIELD(&data_ov001_02193d98, void **, 4));
        func_ov001_02179f80();
        func_ov001_021722ac();
        func_ov001_02171c24((M2C_UNK)0x34, (M2C_UNK)(0x34 - 0x35), (M2C_UNK)0);
        func_ov001_02171dd0((M2C_UNK)2);
        func_ov001_0217a0d4();
        func_ov001_0217a17c();
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0xc) = (s32)func_ov001_0218ad0c((M2C_UNK)0, (M2C_UNK)0);
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0x3c) =
        (s32)func_ov001_0218c884((M2C_UNK)1, (M2C_UNK)func_ov001_0217b0d4, (M2C_UNK)0, (M2C_UNK)0x6e);
    func_ov001_0217ac18();
    func_ov001_0217b130();
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217a2f0);
}

void func_ov001_02179f80(void) {
    s32 func_ov001_02171d30(void *);
    M2C_UNK func_ov001_02171d90(M2C_UNK *, M2C_UNK *);
    s32 func_ov001_02189dc8(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02183694(M2C_UNK);
    M2C_UNK func_ov001_02183720(void);
    extern M2C_UNK data_ov001_0218f7ab;
    extern M2C_UNK data_ov001_0218f795;
    extern M2C_UNK data_ov001_021906e8;
    extern M2C_UNK func_020044ec;
    extern M2C_UNK data_ov001_02193d98;
    typedef struct { u8 bytes[25]; } Buf25;
    typedef struct { u8 bytes[22]; } Buf22;
    Buf25 buf25 = *(Buf25 *)&data_ov001_0218f7ab;
    Buf22 buf22 = *(Buf22 *)&data_ov001_0218f795;
    func_ov001_02171d90(&data_ov001_021906e8, &func_020044ec);
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 4) =
        func_ov001_02189dc8(func_ov001_02171d30(&buf25), 0, 4);
    func_ov001_02183694(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 4));
    func_ov001_02183720();
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 8) =
        func_ov001_02189dc8(func_ov001_02171d30(&buf22), 0, 4);
    M2C_FIELD((void *)0x04001008, u16 *, 0) = (M2C_FIELD((void *)0x04001008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x04001008, u16 *, 2) = (M2C_FIELD((void *)0x04001008, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x04000008, u16 *, 0) = (M2C_FIELD((void *)0x04000008, u16 *, 0) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 0) = (M2C_FIELD((void *)0x0400000A, u16 *, 0) & ~3) | 2;
    M2C_FIELD((void *)0x0400000A, u16 *, 2) = (M2C_FIELD((void *)0x0400000A, u16 *, 2) & ~3) | 3;
    M2C_FIELD((void *)0x0400000A, u16 *, 4) = (M2C_FIELD((void *)0x0400000A, u16 *, 4) & ~3) | 2;
}

void func_ov001_0217a0d4(void) {
    s32 func_02002088(s32, u16);
    M2C_UNK func_ov001_021838a8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_ov001_02193d98;
    s32 var_r0;
    s32 var_r4;
    u8 temp_r1;

    var_r0 = 0;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u16 *, 0x40) = (u16)((M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x51) - 4) * 0x1c);
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x51);
    if ((u32)temp_r1 <= 4U) {
        var_r4 = var_r0;
        M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x53) = var_r0;
    } else if ((u32)temp_r1 <= 8U) {
        M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x53) = 0x1f;
        var_r4 = 1;
    } else {
        M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x53) = 0x37;
        var_r4 = 2;
    }
    if (var_r4 != 0) {
        var_r0 = func_02002088(M2C_FIELD(&data_ov001_02193d98, u16 *, 2) * M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x53), M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u16 *, 0x40));
    }
    func_ov001_021838a8(var_r4, 0x55, 0xec, 0x3f, var_r0);
}

#pragma opt_common_subs off
void func_ov001_0217a17c(void) {
void *func_ov001_0218a5f0(M2C_UNK, M2C_UNK);
void func_ov001_0218a55c(M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK data_ov001_02193d98;
extern u8 data_ov001_0218f814[];
extern u8 data_ov001_0218f818[];
s32 cnt = *(u8 *)((u8 *)((void **)M2C_FIELD(&data_ov001_02193d98, void **, 4)) + 0x51);

s32 i = 0;
if(cnt > 5) cnt = 5;
for(;i<cnt;i++){
((void **)M2C_FIELD(&data_ov001_02193d98, void **, 4))[4+i]=func_ov001_0218a5f0(0,0x2e);
((void **)M2C_FIELD(&data_ov001_02193d98, void **, 4))[9+i]=func_ov001_0218a5f0(0,0x18);
}
for(i=0;(u32)i<3;i++){
func_ov001_0218a55c(0,(M2C_UNK)data_ov001_0218f814[i],((void **)M2C_FIELD(&data_ov001_02193d98, void **, 4))[4]);
((u16 *)((void **)M2C_FIELD(&data_ov001_02193d98, void **, 4)))[0x21+i]=*(u16 *)((u8 *)((void **)M2C_FIELD(&data_ov001_02193d98, void **, 4))[4]+4)&0x3ff;
}
for(i=0;(u32)i<4;i++){
func_ov001_0218a55c(0,(M2C_UNK)data_ov001_0218f818[i],((void **)M2C_FIELD(&data_ov001_02193d98, void **, 4))[9]);
((u16 *)((void **)M2C_FIELD(&data_ov001_02193d98, void **, 4)))[0x24+i]=*(u16 *)((u8 *)((void **)M2C_FIELD(&data_ov001_02193d98, void **, 4))[9]+4)&0x3ff;
}
for(i=0;i<cnt;i++){
u16 *p=(u16 *)((u8 *)((void **)M2C_FIELD(&data_ov001_02193d98, void **, 4))[4+i]+4);
*p=(*p&~0xc00)|0xc00;
p=(u16 *)((u8 *)((void **)M2C_FIELD(&data_ov001_02193d98, void **, 4))[9+i]+4);
*p=(*p&~0xc00)|0xc00;
}
}
#pragma opt_common_subs reset
void func_ov001_0217a2f0(void) {
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b314(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    void func_ov001_0217a344(void);
    func_ov001_0218a824(2, 1, 1, 8);
    func_ov001_0218a824(2, 0, 0x1D, 8);
    func_ov001_0218b314(1, 1);
    func_ov001_0218b314(0, 0x1D);
    func_ov001_02175d54((M2C_UNK *)&func_ov001_0217a344);
}

void func_ov001_0217a344(void) {
    M2C_UNK func_ov001_02171e20(M2C_UNK);
    s32 func_ov001_0218a800(M2C_UNK);
    extern M2C_UNK func_ov001_0217a380;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (func_ov001_0218a800(0) != 0) {
        return;
    }
    func_ov001_02171e20(0);
    func_ov001_02175d54(&func_ov001_0217a380);
}

void func_ov001_0217a380(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171738();
    extern M2C_UNK func_ov001_0217a3a8;
    if (func_ov001_021716c4() == -2) {
        return;
    }
    func_ov001_02171738();
    func_ov001_02175d54(&func_ov001_0217a3a8);
}

void func_ov001_0217a3a8(void) {
M2C_UNK func_ov001_0217a3bc();M2C_UNK func_ov001_0217a610();
func_ov001_0217a3bc();func_ov001_0217a610();(func_ov001_0217a880)();
}

M2C_UNK func_ov001_0217a3bc(void) {
    return 0;
}

s32 func_ov001_0217a610(void) {
    return 0;
}

void func_ov001_0217a880(void) {
    s32 func_ov001_021716c4();
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02185024(M2C_UNK);
    void func_ov001_0217b3c0(void);
    s32 func_02002088(s32, u16);
    void func_ov001_02183a08(void);
    M2C_UNK func_ov001_021862d8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    void func_ov001_0217b3f0(void);
    void func_ov001_0217a98c(void);
    extern M2C_UNK data_ov001_02193d98;
    void *map;
    s32 r;
    map = M2C_FIELD(&data_ov001_02193d98, void **, 4);
    if (M2C_FIELD(map, M2C_UNK *, 0x38) != 0) return;
    if (M2C_FIELD(map, u8 *, 0x57) != 0) return;
    r = func_ov001_021716c4();
    switch (r) {
    case 0:
        func_ov001_02185024(7);
        goto done;
    case 1:
        if (M2C_FIELD(&data_ov001_02193d98, u8 *, 0) == 4) {
            map = M2C_FIELD(&data_ov001_02193d98, void **, 4);
            M2C_FIELD(map, u8 *, 0x54) = 1;
            func_ov001_02185024(6);
            func_ov001_0217b3c0();
            goto done;
        } else {
            u8 field28;
            s32 idx = (u8)M2C_FIELD(&data_ov001_02193d98, u8 *, 0) + func_02002088(M2C_FIELD(&data_ov001_02193d98, u16 *, 2), 0x1c);
            field28 = M2C_FIELD((u8 *)M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), void **, 0) + idx * 42, u8 *, 0x28);
            if (field28 == 2) {
                func_ov001_02185024(9);
                func_ov001_02183a08();
                func_ov001_02171750();
                func_ov001_021862d8(0xe, 1, 1, -1, 0);
                func_ov001_02175d54((M2C_UNK *)&func_ov001_0217b3f0);
                goto done;
            } else {
                void *map2 = M2C_FIELD(&data_ov001_02193d98, void **, 4);
                M2C_FIELD(map2, u8 *, 0x54) = 1;
                map = M2C_FIELD(&data_ov001_02193d98, void **, 4);
                M2C_FIELD(map, u8 *, 0x52) = (u8)idx;
                func_ov001_02185024(6);
                func_ov001_02175d54((M2C_UNK *)&func_ov001_0217a98c);
                goto done;
            }
        }
    default:
        return;
    }
done:
    return;
}

void func_ov001_0217a98c(void) {
    M2C_UNK func_ov001_02171750();
    M2C_UNK func_ov001_02175d54(M2C_UNK *);
    M2C_UNK func_ov001_0218aa24(M2C_UNK);
    extern M2C_UNK func_ov001_0217a9ac;
    func_ov001_02171750();
    func_ov001_0218aa24(8);
    func_ov001_02175d54(&func_ov001_0217a9ac);
}

void func_ov001_0217a9ac(void) {
    M2C_UNK func_ov001_02171694();
    M2C_UNK func_ov001_0218a824(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_02193d98;
    extern M2C_UNK func_ov001_0217aa1c;
    if (func_ov001_0218a800(1) != 0) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x54) != 0) {
        func_ov001_02171694();
    } else {
        func_ov001_02171750();
    }
    func_ov001_0218a824(3, 1, 1, 8);
    func_ov001_0218a824(3, 0, 0x1D, 8);
    func_ov001_02175d54(&func_ov001_0217aa1c);
}

#pragma optimization_level 4
#pragma opt_strength_reduction off
void func_ov001_0217aa1c(void) {
extern s32 data_ov001_02193d98,data_ov001_02193d9c;
extern s32 func_ov001_02181a84,func_ov001_02180860,func_ov001_0217b444,func_ov001_021828ac;
s32 func_ov001_0218a800(s32);s32 func_ov001_0217170c(void);void *func_ov001_0218445c(void);
s32 i; void *p;
if(func_ov001_0218a800(1))return;
if(func_ov001_0218a800(0))return;
if(!func_ov001_0217170c())return;
func_ov001_0218c94c(1,M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4),s32 *,0x3c));
for(i=0;i<5;i++){
p=M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4)+i*4,void **,16);if(p)func_ov001_0218c104(p);
p=M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4)+i*4,void **,36);if(p)func_ov001_0218c104(p);
}
func_ov001_0218af0c(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4),void **,12));
func_ov001_02183980();func_ov001_02172184();func_ov001_02171cf8();func_ov001_021836f4();
func_ov001_02189ebc(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4),void **,4));
func_ov001_02189ebc(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4),void **,8));
func_ov001_0218b368(1,1);func_ov001_0218b368(0,29);
*(u32 *)0x04000010=0;*(u32 *)0x04000018=0;
if(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98,void **,4),u8 *,0x54)==0){
func_ov001_02183fa0();func_ov001_02184880(M2C_FIELD(func_ov001_0218445c(),u8 *,0xf4));func_ov001_02175d64(2,0);func_ov001_02175d54(&func_ov001_02181a84);
}else if(M2C_FIELD(&data_ov001_02193d98,u8 *,0)==4){
func_ov001_02183fa0();func_ov001_02175d64(0,1);func_ov001_02175d54(&func_ov001_02180860);
}else{
p=M2C_FIELD(&data_ov001_02193d98,void **,4);
func_ov001_02184498(M2C_FIELD(p,void **,0)+M2C_FIELD(p,u8 *,0x52)*42);
func_ov001_02175d64(0,0);
p=M2C_FIELD(&data_ov001_02193d98,void **,4);
if(M2C_FIELD(M2C_FIELD(p,void **,0)+M2C_FIELD(p,u8 *,0x52)*42,u8 *,40)){
func_ov001_02175d64(0,1);func_ov001_02175da0(1,1);func_ov001_02175d54(&func_ov001_0217b444);
}else{
func_ov001_02175d64(0,1);func_ov001_02175da0(0,1);func_ov001_02175d54(&func_ov001_021828ac);
}
}
func_ov001_0218b71c(&data_ov001_02193d9c);
}
void func_ov001_0217ac18(void) {
    s32 func_02002088(s32, u16);
          void func_ov001_0217acc0(s32, s32);
    M2C_UNK func_ov001_0217ae38(s32, s32);
    M2C_UNK func_ov001_0217aec4();
    M2C_UNK func_ov001_0218b1ec(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218b298(M2C_UNK);
    extern M2C_UNK data_ov001_02193d98;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;

    var_r7 = func_02002088(M2C_FIELD(&data_ov001_02193d98, u16 *, 2), 0x1c);
    var_r4 = M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), u8 *, 0x51);
    func_ov001_0218b1ec(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0xc), 0);
    if (var_r4 > 5) {
        var_r4 = 5;
    }
    var_r5 = var_r7;
    var_r6 = 0;
    if (var_r4 > 0) {
        do {
            func_ov001_0217acc0(var_r5, var_r6);
            var_r6 += 1;
            var_r5 += 1;
        } while (var_r6 < var_r4);
    }
    var_r5 = 0;
    if (var_r4 > 0) {
        do {
            func_ov001_0217ae38(var_r7, var_r5);
            var_r5 += 1;
            var_r7 += 1;
        } while (var_r5 < var_r4);
    }
    func_ov001_0218b298(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4), s32 *, 0xc));
    func_ov001_0217aec4();
}

void func_ov001_0217acc0(s32 arg0, s32 arg1) {
extern M2C_UNK data_ov001_02193d98;
s32 func_ov001_0218c3e0(u8 *,s32);
M2C_UNK func_02007f8c(void *,s32,s32);
M2C_UNK func_ov001_0218b080(void *,s32,s32,s32,s32,u16 *,s32);
u16 buf[17];
s32 offset=arg0*42;
s32 len=func_ov001_0218c3e0(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4),u8 **,0)+offset,32);
s32 y=arg1*28;
s32 n,i;
void *ctx;
if(arg0>=M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4),u8 *,0x51))return;
if(len<=16)y+=6;
func_02007f8c(buf,0,34);
n=len<=16?len:16;
i=0;
if(n>0){ctx=M2C_FIELD(&data_ov001_02193d98, void **, 4);
do {buf[i]=M2C_FIELD(ctx,u8 **,0)[offset+i];}while(++i<n);
}
func_ov001_0218b080(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4),void **,12),10,y,2,10,buf,1);
if(len<=16)return;
func_02007f8c(buf,0,34);
len-=16;
arg0=0;
if(len>0){ctx=M2C_FIELD(&data_ov001_02193d98, void **, 4);
do {buf[arg0]=M2C_FIELD(ctx,u8 **,0)[offset+arg0+16];}while(++arg0<len);
}
func_ov001_0218b080(M2C_FIELD(M2C_FIELD(&data_ov001_02193d98, void **, 4),void **,12),10,y+12,2,10,buf,1);
}

