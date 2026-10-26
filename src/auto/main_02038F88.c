/* 33 functions from 0x02038F88 to 0x02039EFC (main), found by ds-decomp. */
#include "common.h"

s32 func_02038f88(void) {
extern void *data_0213d1f8;
s32 func_02037eec(s32);s32 func_0205d4d8(s32,u16,s32);
s32 func_0205ad4c(void *,s32,s32,s32,void (*)(s32 *));
void func_02039ba8(s32 *); void func_0203d6c8(void); void func_0203d5d4(void);
void func_0205ada8(s32,void (*)(void));void func_0205b050(s32,void (*)(void));
u32 func_020393d4();
void *base; s32 result;u16 angle;
if(M2C_FIELD(data_0213d1f8,s32 *,0))return 0;
angle=func_02037eec(0x4000)+0xc000;
base=data_0213d1f8;
result=func_0205ad4c(data_0213d1f8,func_0205d4d8(0,angle,0),M2C_FIELD(base,s32 *,0x14),M2C_FIELD(base,s32 *,0x18),func_02039ba8);
if(func_020393d4(result))return result;
func_0205ada8(M2C_FIELD(data_0213d1f8,s32 *,0),func_0203d6c8);
func_0205b050(M2C_FIELD(data_0213d1f8,s32 *,0),func_0203d5d4);
return result;
}

s32 func_02039050(s32 arg0) {
    void *func_0205b094();
    extern void *data_0213d1f8;
    extern M2C_UNK data_0213d200;
    s32 i;
    if (data_0213d1f8 == NULL) return 0;
    for (i = 0; i < 32; i++) {
        if ((&data_0213d200)[i] != 0 && arg0 == M2C_FIELD(func_0205b094((&data_0213d200)[i]), u8 *, 1))
            return (&data_0213d200)[i];
    }
    return 0;
}

u8 func_020390b4(void) {
    void *func_0205b094();
    return M2C_FIELD(func_0205b094(), u8 *, 1);
}

u8 func_020390c4(void) {
    void *func_0205b094();
    return M2C_FIELD(func_0205b094(), u8 *, 0);
}

s32 func_020390d4(void) {
    extern M2C_UNK data_0213d200;
    s32 i;
    for (i = 0; i < 32; i++) {
        if ((&data_0213d200)[i] == 0) return i;
    }
    return -1;
}

void func_02039100(void) {
    M2C_UNK func_02007e54(M2C_UNK, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0213d200;
    extern M2C_UNK data_0213d280;
    func_02007e54(0, &data_0213d200, 0x80);
    func_02007e54(0, &data_0213d280, 0x100);
}

void *func_02039130(s32 arg0) {
    extern M2C_UNK data_0213d200;
    return &data_0213d200 + arg0;
}

void *func_02039140(s32 arg0, s32 arg1) {
    extern void *data_0213d1f8;
    s32 func_02039050(s32);
    u8 func_020390c4(void);
    void *func_02039130(s32);
    u8 i;
    for (i = 0; i < arg1; i++) {
        if (arg0 == ((u32 *)((u8 *)data_0213d1f8 + 0x468))[i]) {
            break;
        }
    }
    if (i >= arg1) {
        return 0;
    }
    func_02039050(*((u8 *)data_0213d1f8 + i + 0x644));
    return func_02039130(func_020390c4());
}

void *func_020391a8(s32 arg0) {
    extern M2C_UNK data_0213d280;
    return &data_0213d280 + arg0 * 2;
}

s32 func_020391b8(s32 arg0) {
    void *func_0205b094(void *);
    extern M2C_UNK data_0213d200;
    s32 i;
    for (i = 0; i < 32; i++) {
        if ((&data_0213d200)[i] != 0) {
            if (M2C_FIELD(func_0205b094((void *)(&data_0213d200)[i]), u8 *, 1) == arg0) {
                return 1;
            }
        }
    }
    return 0;
}

void func_02039200(void) {

}

void func_02039204(s32 arg0) {
    extern void *data_0213d1f8;
    M2C_FIELD(data_0213d1f8, s32 *, 0x28) = (s32) M2C_FIELD(data_0213d1f8, s32 *, 0x24);
    M2C_FIELD(data_0213d1f8, s32 *, 0x24) = arg0;
}

s32 func_02039224(s32 arg0) {
    s32 func_0203e0ec();
    s32 func_0203e338(u8 **);
    u8 *sp0;
    s32 temp_r0;
    s32 var_r0;
    u8 *var_r3;

    temp_r0 = func_0203e338(&sp0);
    var_r0 = 0;
    if (temp_r0 > 0) {
        var_r3 = sp0;
loop_2:
        if (arg0 != *var_r3) {
            var_r0 += 1;
            var_r3 += 1;
            if (var_r0 < temp_r0) {
                goto loop_2;
            }
        }
    }
    if (var_r0 == temp_r0) {
        return 0;
    }
    return func_0203e0ec();
}

u32 func_02039284(u8 *src, s32 n) {
    u32 acc = 0;
    u32 i = 0;
    if (n > 0) {
        u32 bit = 1;
        do {
            acc |= bit << (u32)src[i];
            i = i + 1;
        } while (i < (u32)n);
    }
    return acc;
}

u32 func_020393d4(u32 a, u32 unused, u32 off) {
    u32 ret = a;
    u32 code;
    code = ret;
    if (ret == 0) return 0;
    switch (ret) {
    case 1: code = 9; off = code - 10; break;
    case 2:
    case 5: code = 0; off = code; ret = code; break;
    case 3: code = 6; off = code - 16; break;
    case 4: code = 6; off = code - 36; break;
    case 6: code = 6; off = code - 76; break;
    case 7: code = 6; off = code - 86; break;
    }
    if (code) func_02039db4(code, (s32)(off + 0xFFFEFA48));
    return ret;
}

void func_02039478(s32 arg0, s32 arg1) {
    void func_02039204(s32);
    void func_0203af18(void);
    extern void *data_0213d1f8;
    if (arg0 == 0) {
        M2C_FIELD(data_0213d1f8, s32 *, 0x64) = arg1;
        func_02039204(3);
        func_0203af18();
    } else {
        func_02039204(0);
    }
    {
        void *p = data_0213d1f8;
        void (*cb)(s32, s32, s32) = (void (*)(s32, s32, s32))M2C_FIELD(p, void **, 0x70);
        if (cb != NULL) {
            cb(arg0, arg1, M2C_FIELD(p, s32 *, 0x74));
        }
    }
}

void func_020394d8(s32 arg0, s32 arg1) {
    void func_02039204(s32);
    extern void *data_0213d1f8;
    s32 v = M2C_FIELD(data_0213d1f8, s32 *, 0x28);
    if (v == 4) goto done;
    func_02039204(v);
    M2C_FIELD(data_0213d1f8, void (**)(s32, s32, s32), 0x78)(arg0, arg1, M2C_FIELD(data_0213d1f8, s32 *, 0x7c));
done:
    ;
}

void func_02039698(s32 unused, void *arg1) {
    M2C_UNK func_020392b8(M2C_UNK);
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg1, s32 *, 4);
    if ((temp_r1 != 0x603) && (temp_r1 != 0x901) && (temp_r1 != 0xB01)) {
        func_020392b8(3);
    }
}

void func_02039838(void) {
    M2C_UNK func_02044744();
    func_02044744();
}

void func_02039b9c(void) {
    M2C_UNK func_02044780();
    func_02044780();
}

void func_02039ba8(s32 *arg0) {
    extern void *data_0213d1f8;
    void func_02037638(s32, s32);
    s32 func_0205b048(s32 *);
    s32 func_02049900(void);
    func_0205b048(arg0);
    M2C_FIELD(&data_0213d1f8, s32 *, 4) = func_02049900();
    func_02037638(9, 0xfffe8515);
    M2C_FIELD(M2C_FIELD(&data_0213d1f8, s32 *, 0), s32 *, 0) = 0;
}

void func_02039be4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    extern M2C_UNK data_0213d380;
    M2C_UNK func_02007f8c(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_FIELD(&data_0213d380, s32 *, 4) = arg0;
    func_02007f8c(arg0, 0, 0x280);
    M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 0) = arg2;
    M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 4) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 8) = arg3;
    M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 0xc) = arg4;
    M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 0x10) = arg5;
    M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 0x14) = arg6;
    M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 0x18) = arg7;
    M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 0x1c) = arg1;
}

void func_02039c68(void) {
    void func_0203a034(void);
    void func_0203a0e8(void *, s32);
    extern M2C_UNK data_0213d380;
    func_0203a0e8(func_0203a034, 0);
    M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 4) = 1;
    M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 0x30) = 0;
}

void func_02039ca0(void) {
extern M2C_UNK data_0213d380;
s32 func_0203761c(void);void func_0203a2b4(void);void func_0204db50(void *);
u64 func_02007004(void); u64 func_02072088(u64,u64);
void *p;
if(!M2C_FIELD(&data_0213d380,void **,4))return;
if(func_0203761c())return;
p=M2C_FIELD(&data_0213d380,void **,4);
switch(M2C_FIELD(p,u32 *,4)){
case 0:break;
case 1:func_0203a2b4();return;
case 2:case 3:case 4:
p=M2C_FIELD(p,void **,0);
if(p && M2C_FIELD(p,s32 *,0))func_0204db50(p);
p=M2C_FIELD(&data_0213d380,void **,4);
if(!M2C_FIELD(p,s32 *,0x30))return;
if(func_02072088((func_02007004()-M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),u64 *,0x34))<<6,0x82eaULL)>60000ULL){
func_02039db4(6,-61070);
M2C_FIELD(M2C_FIELD(&data_0213d380,void **,4),s32 *,0x30)=0;
}
return;
case 5:break;
default:break;
}
}

s32 func_02039d98(void) {
    extern M2C_UNK data_0213d380;
    if (M2C_FIELD(&data_0213d380, void **, 4) != NULL) {
        return M2C_FIELD(M2C_FIELD(&data_0213d380, void **, 4), s32 *, 0x1C);
    }
    return 0;
}

s32 func_02039db4(u32 arg0, s32 arg1) {
    extern M2C_UNK data_0213d380;
    void func_02037638(s32, s32);
    void func_02039e60(void);
    void *p;
    p = (void *)M2C_FIELD(&data_0213d380, void **, 4);
    if (p == NULL || arg0 == 0) return;
    func_02037638(arg0, arg1);
    p = (void *)M2C_FIELD(&data_0213d380, void **, 4);
    if (M2C_FIELD(p, void (**)(s32, u8, s32), 0x14) != NULL) {
        M2C_FIELD(p, void (**)(s32, u8, s32), 0x14)(arg0, 0, M2C_FIELD(p, s32 *, 0x18));
    }
    func_02039e60();
}

void func_02039e04(void) {
    extern M2C_UNK data_0213d380;
    M2C_UNK func_020376d8(s32, s32, s32);
    void func_02032a84(void);
    void func_02032b10(void);
    if (M2C_FIELD(M2C_FIELD(&data_0213d380, s32 *, 4), s32 *, 0x24)) {
        func_02032a84();
        func_02032b10();
        func_020376d8(0, M2C_FIELD(M2C_FIELD(&data_0213d380, s32 *, 4), s32 *, 0x24), 0);
        M2C_FIELD(M2C_FIELD(&data_0213d380, s32 *, 4), s32 *, 0x24) = 0;
        M2C_FIELD(&data_0213d380, s32 *, 4) = 0;
    }
}

void func_02039e60(void) {
    extern M2C_UNK data_0213d380;
    M2C_UNK *p;
    p = (M2C_UNK *)M2C_FIELD(&data_0213d380, void **, 4);
    if (p == NULL) return;
    M2C_FIELD(p, s32 *, 4) = 0;
    p = (M2C_UNK *)M2C_FIELD(&data_0213d380, void **, 4);
    M2C_FIELD(p, s32 *, 0x30) = 0;
}

u32 func_02039e88(u32 a, u32 unused, u32 off) {
    u32 ret = a;
    u32 code;
    if (ret == 0) return 0;
    switch (ret) {
    case 1: code = 9; off = code - 0xa; break;
    case 2: code = 9; off = code - 0xb; break;
    case 3: code = 6; off = code - 0x10; break;
    case 4: code = 6; off = code - 0x1a; break;
    }
    func_02039db4(code, off + 0xffff11b8);
    return ret;
}

