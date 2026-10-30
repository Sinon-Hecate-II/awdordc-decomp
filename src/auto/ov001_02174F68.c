/* 35 functions from 0x02174F68 to 0x02175F60 (ov001), found by ds-decomp. */
#include "common.h"

typedef struct { s32 x; u32 y; } Position;


void func_ov001_02174f68(s32 arg0, Position arg1) {
    (void)arg0;
    (void)arg1;
}

void func_ov001_021751c8(s32 arg0, s32 arg1) {
void func_ov001_0218a304(s32,s32,s32,u8);
extern void *data_ov001_02193d20;
extern u8 data_ov001_0218f5e4[],data_ov001_0218f5d8[];
void *p;u32 color;s32 index;
if(arg0<0)return;
if(arg0<10){
p=M2C_FIELD((u8 *)data_ov001_02193d20+arg0*4,void **,0x10);
color=((volatile u8 *)data_ov001_0218f5e4)[arg1];
M2C_FIELD(p,u32 *,0)&=~0xc00;
M2C_FIELD(p,u16 *,4)=(M2C_FIELD(p,u16 *,4)&~0xf000)|(color<<12);
return;
}
index=arg0-10;
if(index<2){
p=M2C_FIELD((u8 *)data_ov001_02193d20+index*4,void **,0x38);
color=((volatile u8 *)data_ov001_0218f5e4)[arg1];
M2C_FIELD(p,u32 *,0)&=~0xc00;
M2C_FIELD(p,u16 *,4)=(M2C_FIELD(p,u16 *,4)&~0xf000)|(color<<12);
return;
}
func_ov001_0218a304(M2C_FIELD((u8 *)data_ov001_02193d20+(arg0-12)*4,s32 *,0x40),-1,0,data_ov001_0218f5d8[arg1]);
}

void func_ov001_02175290(void) {
    s32 func_ov001_0218a24c(s32, M2C_UNK);
    M2C_UNK func_ov001_0218a384(s32, M2C_UNK, u16, u16);
    M2C_UNK func_ov001_0218a474(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a55c(M2C_UNK, M2C_UNK, s32);
    extern u16 data_ov001_0218f66a[];
    extern u16 data_ov001_0218f66c[];
    extern void *data_ov001_02193d20;
    M2C_UNK var_r4;
    s32 temp_ip;
    if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) <= 0xB) var_r4 = 0x44;
    else var_r4 = 0x45;
    func_ov001_0218a55c(0, var_r4, func_ov001_0218a24c(M2C_FIELD(data_ov001_02193d20, s32 *, 0x58), 0));
    func_ov001_0218a474(M2C_FIELD(data_ov001_02193d20, s32 *, 0x58), -1, 2);
    temp_ip = M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) * 2;
    func_ov001_0218a384(M2C_FIELD(data_ov001_02193d20, s32 *, 0x58), -1, data_ov001_0218f66a[temp_ip], data_ov001_0218f66c[temp_ip]);
}

void func_ov001_0217531c(s32 arg0) {
    void func_ov001_02185024(s32);
    extern s8 data_ov001_0218f6a2[][4];
    extern void *data_ov001_02193d20;
    s8 old;
    s8 current;
    old = M2C_FIELD(data_ov001_02193d20, s8 *, 0x63);
    M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) = data_ov001_0218f6a2[old][arg0];
    current = M2C_FIELD(data_ov001_02193d20, s8 *, 0x63);
    if (current == 13 && (arg0 == 1 || arg0 == 3)) {
        M2C_FIELD(data_ov001_02193d20, s8 *, 0x64) = old;
    } else if (current == -1) {
        if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x64) == 1 || M2C_FIELD(data_ov001_02193d20, s8 *, 0x64) == 10)
            M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) = 10;
        else M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) = 11;
    } else if (current == -2) {
        if (M2C_FIELD(data_ov001_02193d20, s8 *, 0x64) == 1 || M2C_FIELD(data_ov001_02193d20, s8 *, 0x64) == 10)
            M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) = 1;
        else M2C_FIELD(data_ov001_02193d20, s8 *, 0x63) = 2;
    }
    func_ov001_02175290();
    func_ov001_02185024(8);
}

void func_ov001_021753c8(M2C_UNK arg0) {
    void func_ov001_02174f68(s32, Position);
    M2C_UNK func_ov001_0218c924(M2C_UNK, void (*)(M2C_UNK));
    void func_ov001_02175440(M2C_UNK);
    extern void *data_ov001_02193d20;
    s32 temp_r2 = *(s32 *)func_ov001_0218a24c(M2C_FIELD(data_ov001_02193d20, s32 *, 0x40), 0);
    Position pos = { (u8)temp_r2 + 12, (u32)(temp_r2 & 0x01FF0000) >> 16 };
    func_ov001_02174f68(4, pos);
    if (pos.x < 192) return;
    func_ov001_0218c924(arg0, func_ov001_02175440);
}

void func_ov001_02175440(M2C_UNK arg0) {
M2C_UNK func_ov001_0218c924(M2C_UNK,void(*)(M2C_UNK));void func_ov001_021754b0(M2C_UNK);extern void *data_ov001_02193d20;
s32 bits=*M2C_FIELD(data_ov001_02193d20,s32 **,0x34);
Position pos;
pos.y=(u32)(bits&0x01ff0000)>>16;pos.x=(u8)bits+12;
((void(*)(s32))func_ov001_02174f68)(3);
if(*(volatile s32*)&pos.x<192)return;func_ov001_0218c924(arg0,func_ov001_021754b0);
}

void func_ov001_021754b0(M2C_UNK arg0) {
M2C_UNK func_ov001_0218c924(M2C_UNK,void(*)(M2C_UNK));void func_ov001_02175520(M2C_UNK);extern void *data_ov001_02193d20;
s32 bits=*M2C_FIELD(data_ov001_02193d20,s32 **,0x28);
Position pos;
pos.y=(u32)(bits&0x01ff0000)>>16;pos.x=(u8)bits+12;
((void(*)(s32))func_ov001_02174f68)(2);
if(*(volatile s32*)&pos.x<192)return;func_ov001_0218c924(arg0,func_ov001_02175520);
}

void func_ov001_02175520(M2C_UNK arg0) {
M2C_UNK func_ov001_0218c924(M2C_UNK,void(*)(M2C_UNK));void func_ov001_02175590(M2C_UNK);extern void *data_ov001_02193d20;
s32 bits=*M2C_FIELD(data_ov001_02193d20,s32 **,0x1c);
Position pos;
pos.y=(u32)(bits&0x01ff0000)>>16;pos.x=(u8)bits+12;
((void(*)(s32))func_ov001_02174f68)(1);
if(*(volatile s32*)&pos.x<192)return;func_ov001_0218c924(arg0,func_ov001_02175590);
}

void func_ov001_02175590(M2C_UNK arg0) {
M2C_UNK func_ov001_0218c924(M2C_UNK,void(*)(M2C_UNK));void func_ov001_02175600(M2C_UNK);extern void *data_ov001_02193d20;
s32 bits=*M2C_FIELD(data_ov001_02193d20,s32 **,0x10);
Position pos;
pos.y=(u32)(bits&0x01ff0000)>>16;pos.x=(u8)bits+12;
((void(*)(s32))func_ov001_02174f68)(0);
if(*(volatile s32*)&pos.x<192)return;func_ov001_0218c924(arg0,func_ov001_02175600);
}

