/* 19 functions from 0x0200BDA4 to 0x0200CD68 (main), found by ds-decomp. */
#include "common.h"

void func_0200beec(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0200b3ec(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0212fc14;
    func_0200b3ec(&data_0212fc14, arg0, arg1);
}

u32 func_0200bf0c(void *arg0) {s32 x=M2C_FIELD(arg0,s32 *,28);if(((u32)x>>24)&1) return (u32)(x<<8)>>8;return M2C_FIELD(arg0,u32 *,8);}

void func_0200bf28(void *arg0) {
    M2C_UNK func_020067a8(s32, s32);
    M2C_UNK func_0200681c(s32, s32);
    M2C_UNK func_02007f8c(s32, M2C_UNK, s32);
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;

    temp_r4 = M2C_FIELD(arg0, s32 *, 4);
    temp_r5 = M2C_FIELD(arg0, s32 *, 8);
    temp_r6 = temp_r5 + M2C_FIELD(arg0, s32 *, 0xC);
    func_0200681c(temp_r4, temp_r6);
    func_020067a8(temp_r4, temp_r6);
    func_02007f8c(temp_r4 + temp_r5, 0, temp_r6 - temp_r5);
}

void func_0200bf64(u32 *arg0,void *arg1) {extern M2C_UNK data_0212fc14;volatile u32 tmp[2];arg1=(void *)M2C_FIELD(arg1,u32 *,24);tmp[1]=(u32)arg1;arg0[0]=(u32)&data_0212fc14;tmp[0]=(u32)&data_0212fc14;arg0[1]=(u32)arg1;}

s32 func_0200c180(u32 arg0,s32 arg1,s32 arg2) {
M2C_UNK func_02007f8c(s32,M2C_UNK,s32);
void func_02008048();void func_0200cd68();
extern u32 data_020f5224[2];
u32 out[5];u8 work[64];u32 i;u32 *p;
func_02007f8c((s32)out,0,20);
func_02008048(data_020f5224[0],work,data_020f5224[1]);
func_0200cd68(out,arg1,arg2,work,data_020f5224[1]);
p=out;for(i=0;i<20;i+=4,p++) if(*p!=*(u32 *)(arg0+i)) break;
return i==20;
}

s32 func_0200c3f8(void) {
    M2C_UNK func_0200c308();
    func_0200c308();
    return 1;
}

s32 func_0200c408(s32 arg0,s32 arg1) {s32 func_0200c084();u8 temp[44];if(!func_0200c084(temp,arg0,arg1) || !((s32 (*)())func_0200c3f8)(temp)) return 0;return 1;}

void func_0200c454(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
}

void func_0200c9c8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
    M2C_FIELD(arg0, s32 *, 0x10) = 0xC3D2E1F0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
}

