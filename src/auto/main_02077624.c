/* 21 functions from 0x02077624 to 0x020785B0 (main), found by ds-decomp. */
#include "common.h"

void func_02077700(void) {
    M2C_UNK func_02001fb4(M2C_UNK, s32);
    extern M2C_UNK data_02140f70;
    func_02001fb4(0x60000, M2C_FIELD(&data_02140f70, s32 *, 0x18) * 3);
}

void func_02077720(void) {*(volatile u32 *)0x40004c0=0x7fffffff;*(volatile u32 *)0x40004c4=0x7fff4210;}

void func_02077a30(void) {
    M2C_UNK func_02003d8c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_02003d8c(0, 0, 0, 0);
}

void func_02077a4c(void) {extern M2C_UNK data_02140f70;M2C_FIELD(&data_02140f70,s32 *,4)=0;*(volatile u32 *)0x40004c8=0x20000000;*(volatile u32 *)0x40004cc=0x7fff;}

void func_02077a7c(void) {void func_02077c8c();void func_02077eb8(void);void func_02077ebc(void);void func_0207ce28();void func_0207cbb0();void func_0207749c();extern s32 *data_027e0058;
func_02077c8c();func_02077a4c();func_02077eb8();func_02077ebc();func_0207ce28(*data_027e0058+0x6ef8);func_0207cbb0();func_0207749c();}

void func_02077bb4(s32 arg0) {void func_02003a8c();void func_02001034();extern M2C_UNK data_02140f88;u8 temp[64];
*(volatile u32 *)0x4000440=0;*(volatile u32 *)0x4000454=0;func_02003a8c(&data_02140f88);func_02001034(arg0+28,temp);func_02003a8c(temp);*(volatile u32 *)0x4000440=2;*(volatile u32 *)0x4000454=0;}

void func_02077c10(void) {
    M2C_UNK func_02077ab8(s32);
    void func_02077bb4(s32);
    M2C_UNK func_0207cd0c(s32);
    M2C_UNK func_0207cddc(s32, M2C_UNK *);
    M2C_UNK func_0207ce54(s32);
    M2C_UNK func_0207d95c(M2C_UNK);
    extern M2C_UNK data_02140f88;
    extern s32 *data_027e0058;
    s32 temp_r4;

    temp_r4 = *data_027e0058 + 0x2F8;
    func_0207d95c(0);
    func_02077ab8(temp_r4 + 0x6C00);
    func_0207ce54(temp_r4 + 0x6C00);
    func_0207cd0c(temp_r4 + 0x6C00);
    func_0207cddc(temp_r4 + 0x6C00, &data_02140f88);
    func_02077bb4(temp_r4 + 0x6C00);
}

void func_02077c64(void) {
    M2C_UNK func_02003bd0();
    void func_02077720();
    M2C_UNK func_02078828();
    func_02003bd0();
    func_02078828();
    func_02077720();
}

void func_02077c78(void) {
    *(s32 *)0x04000540 = 0;
}

void func_02077eb8(void) {

}

/* Loads and prepares the animation/texture data tables used at startup. */
void func_02077ebc(void) {
    M2C_UNK func_02004b54();
    M2C_UNK func_02004bb0(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_02004cf0();
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02081384(M2C_UNK *, s32);
    M2C_UNK func_02081400(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4(M2C_UNK *);
    M2C_UNK func_02081528();
    M2C_UNK func_0208166c(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_0208168c(M2C_UNK *, s32);
    M2C_UNK *func_020e3218(M2C_UNK *);
    extern M2C_UNK data_02100ad8;
    extern M2C_UNK data_02100ae4;
    extern M2C_UNK data_02100af0;
    extern M2C_UNK data_02100afc;
    extern M2C_UNK data_02100b0c;
    extern M2C_UNK data_02100b1c;
    extern M2C_UNK data_02100b28;
    extern M2C_UNK data_02100b3c;
    extern M2C_UNK data_02100b50;
    extern M2C_UNK data_02100b60;
    extern M2C_UNK data_02100b70;
    extern M2C_UNK data_02100b7c;
    extern M2C_UNK data_02100b88;
    extern M2C_UNK data_02100b94;
    extern M2C_UNK data_02100b9c;
    extern M2C_UNK data_02100ba4;
    extern M2C_UNK data_02144cbc;
    s32 i;
    s32 j;

    func_02004b54();
    i = 0;
    do {
        func_02004bb0(&data_02144cbc, i + 0x329A0, 0x20);
        i += 0x20;
    } while (i < 0xD660);
    j = 0;
    do {
        func_02004bb0(&data_02144cbc, j + 0x30D20, 0x20);
        j += 0x20;
    } while (j < 0x1800);
    func_02004cf0();
    func_0200bc5c(&data_02100ad8);
    func_02081384(&data_02100ae4, 0x24D20);
    func_02081400(&data_02100af0, 0x1200, 0x200);
    func_02081384(func_020e3218(&data_02100afc), 0x20000);
    func_02081400(&data_02100b0c, 0x1400, 0x40);
    func_020814e4(&data_02100b1c);
    func_0208168c(&data_02100b28, 0x22F20);
    func_0208166c(&data_02100b3c, 0x1460, 0x40);
    func_0208168c(&data_02100b50, 0x21000);
    func_0208168c(&data_02100b60, 0x21980);
    func_0208166c(&data_02100b70, 0x1440, 0x20);
    func_0208168c(&data_02100b7c, 0x32520);
    func_0208168c(&data_02100b88, 0x325A0);
    func_0208166c(&data_02100b94, 0x1520, 0x20);
    func_0208168c(&data_02100b9c, 0x327A0);
    func_0208166c(&data_02100ba4, 0x1540, 0x20);
    func_02081528();
}

void func_02078528(void) {
    unsigned long long func_020722fc(unsigned long, unsigned long);
    extern u8 data_020ebd78[32];
    extern u32 data_027e15bc;
    extern u8 data_020ebd58[32];
    extern M2C_UNK data_02140f70;
    s32 idx = 0;
    s32 accum = 0;
    s32 sum = 0;
    s32 i = 0;
    u8 *p;
    u8 t;
    unsigned long long res;
    s32 rem;

    p = data_020ebd78;
    i = 0;
    do {
        t = *p++;
        i = i + 1;
        sum = sum + t;
    } while (i < 0x1E);

    res = func_020722fc(data_027e15bc, (unsigned long)sum);
    rem = (s32)(res >> 32);

    p = data_020ebd78;
    i = 0;
    for (;;) {
        t = *p;
        accum = accum + t;
        if (accum > rem) {
            idx = i;
            break;
        }
        i = i + 1;
        p = p + 1;
        if (i >= 0x1E) {
            break;
        }
    }

    *(u8 *)&data_02140f70 = data_020ebd58[idx];
}

