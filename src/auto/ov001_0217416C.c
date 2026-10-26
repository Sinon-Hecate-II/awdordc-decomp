/* 18 functions from 0x0217416C to 0x02174F68 (ov001), found by ds-decomp. */
#include "common.h"


void func_ov001_021744a8(void) {
    extern void *data_ov001_02193d20;
    void func_ov001_021753c8(void);
    func_ov001_0218a1cc(M2C_FIELD(data_ov001_02193d20, s32 *, 0x58));
    func_ov001_0218c924(M2C_FIELD(data_ov001_02193d20, s32 *, 0x5c), func_ov001_021753c8);
}

u8 func_ov001_021744dc(void) {
    extern void *data_ov001_02193d20;
    return M2C_FIELD(data_ov001_02193d20, u8 *, 0x60);
}

void func_ov001_021744f0(s8 arg0) {
    extern void *data_ov001_02193d20;
    M2C_FIELD(data_ov001_02193d20, s8 *, 0x66) = arg0;
}

void func_ov001_02174504(s8 arg0) {
    extern void *data_ov001_02193d20;
    M2C_FIELD(data_ov001_02193d20, s8 *, 0x67) = arg0;
}

void func_ov001_02174518(s8 arg0){extern void *data_ov001_02193d20;M2C_FIELD(data_ov001_02193d20,s8*,0x68)=arg0;}

s32 func_ov001_0217452c(void) {
    extern void *data_ov001_02193d20;
    if (data_ov001_02193d20 != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02174548(s32 arg0){
extern void *data_ov001_02193d20;
void func_ov001_021745cc(s32);
u32 v; s32 pos[2];
v=M2C_FIELD(M2C_FIELD(data_ov001_02193d20,void**,16),u32*,0);
((volatile s32 *)pos)[1]=(v&0x1ff0000)>>16;
((volatile s32 *)pos)[0]=(v&255)-12;
if(pos[0]>76){func_ov001_02174f68(0,pos[0]);return;}
func_ov001_02174f68(0,76);
func_ov001_02174f68(1,192);
func_ov001_0218c924(arg0,func_ov001_021745cc);
}

void func_ov001_021745cc(s32 arg0){
extern void *data_ov001_02193d20;
void func_ov001_02174650(s32);
u32 v; s32 pos[2];
v=M2C_FIELD(M2C_FIELD(data_ov001_02193d20,void**,28),u32*,0);
((volatile s32 *)pos)[1]=(v&0x1ff0000)>>16;
((volatile s32 *)pos)[0]=(v&255)-12;
if(pos[0]>99){func_ov001_02174f68(1,pos[0]);return;}
func_ov001_02174f68(1,99);
func_ov001_02174f68(2,192);
func_ov001_0218c924(arg0,func_ov001_02174650);
}

void func_ov001_02174650(s32 arg0){
extern void *data_ov001_02193d20;
void func_ov001_021746d4(s32);
u32 v,y; s32 x,pos[2];
v=M2C_FIELD(M2C_FIELD(data_ov001_02193d20,void**,40),u32*,0);
y=v&0x1ff0000;
x=(v&255)-12;
((volatile s32 *)pos)[1]=y>>16;
((volatile s32 *)pos)[0]=x;
if(pos[0]>122){func_ov001_02174f68(2,pos[0]);return;}
func_ov001_02174f68(2,122);
func_ov001_02174f68(3,192);
func_ov001_0218c924(arg0,func_ov001_021746d4);
}

void func_ov001_021746d4(s32 arg0){
extern void *data_ov001_02193d20;
void func_ov001_02174758(s32);
u32 v; s32 pos[2];
v=M2C_FIELD(M2C_FIELD(data_ov001_02193d20,void**,52),u32*,0);
((volatile s32 *)pos)[1]=(v>>16)&511;
((volatile s32 *)pos)[0]=(u8)v-12;
if(pos[0]>145){func_ov001_02174f68(3,pos[0]);return;}
func_ov001_02174f68(3,145);
func_ov001_02174f68(4,192);
func_ov001_0218c924(arg0,func_ov001_02174758);
}

void func_ov001_02174758(s32 arg0){extern void *data_ov001_02193d20;
void func_ov001_021747cc(void);
s32 pos[2];
func_ov001_0218a4d4(M2C_FIELD(data_ov001_02193d20,s32*,0x40),0,&pos[1],&pos[0]);
pos[0]-=12;
if(pos[0]>170){func_ov001_02174f68(4,pos[0]);return;}
func_ov001_02174f68(4,170);func_ov001_02175290();func_ov001_0218c924(arg0,func_ov001_021747cc);
}

void func_ov001_021747cc(void) {
    M2C_UNK func_ov001_02174b90();
    M2C_UNK func_ov001_02174dcc();
    func_ov001_021747e4();
    func_ov001_021749c0();
    func_ov001_02174b90();
    func_ov001_02174dcc();
}

void func_ov001_02174d80(s32 arg0){extern void *data_ov001_02193d20;
if(arg0==M2C_FIELD(data_ov001_02193d20,s8*,0x62))return;
func_ov001_021751c8(arg0,1);
func_ov001_021751c8(M2C_FIELD(data_ov001_02193d20,s8*,0x62),0);
M2C_FIELD(data_ov001_02193d20,s8*,0x62)=arg0;
}

