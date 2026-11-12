/* 35 functions from 0x02174F68 to 0x02175F60 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { u8 v[5]; } Counts4F68;
extern u8 gKeypadLayout[];
extern u16 gKeypadDigitRects[], gKeypadAuxRects[], gKeypadActionRects[];
extern void *gOv001Keypad;

typedef struct { s32 x; u32 y; } Position;


#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
void func_ov001_02174f68(s32 arg0, s32 arg1) {
 void func_ov001_0218b200(s32,u16,s32,s32,s32);
 void func_ov001_0218a260(s32,s32,s32,s32);
 s32 Ov001_MoveSpriteLayout(s32,s32,u16,u16);
 volatile u8 a[5]={gKeypadLayout[21],gKeypadLayout[22],gKeypadLayout[23],gKeypadLayout[24],gKeypadLayout[25]};
 volatile u8 b[5]={gKeypadLayout[26],gKeypadLayout[27],gKeypadLayout[28],gKeypadLayout[29],gKeypadLayout[30]};
 volatile u8 c[5]={gKeypadLayout[16],gKeypadLayout[17],gKeypadLayout[18],gKeypadLayout[19],gKeypadLayout[20]};
 s32 i,j=arg0*3; void *p; u16 y;
 for(i=0;i<a[arg0];i++){
 p=M2C_FIELD((u8 *)gOv001Keypad+j*4,void **,0x10);
 y=gKeypadDigitRects[j*2];
 *(u32 *)p &= 0xc1fffcff;
 p=M2C_FIELD((u8 *)gOv001Keypad+j*4,void **,0x10);
 *(u32 *)p=(*(u32 *)p&0xfe00ff00)|(arg1&255)|((y&511)<<16);
 j++;
 }
 if(arg0<4) func_ov001_0218b200(M2C_FIELD((u8 *)gOv001Keypad+arg0*4,s32 *,0),gKeypadDigitRects[arg0*6],arg1,M2C_FIELD((u8 *)gOv001Keypad+arg0*4,s32 *,0x48),2);
 for(i=0;i<b[arg0];i++){
 p=M2C_FIELD((u8 *)gOv001Keypad+i*4,void **,0x38);
 y=gKeypadAuxRects[i*2];
 *(u32 *)p &= 0xc1fffcff;
 p=M2C_FIELD((u8 *)gOv001Keypad+i*4,void **,0x38);
 *(u32 *)p=(*(u32 *)p&0xfe00ff00)|(arg1&255)|((y&511)<<16);
 }
 for(i=0;i<c[arg0];i++){
 func_ov001_0218a260(M2C_FIELD((u8 *)gOv001Keypad+i*4,s32 *,0x40),-1,0,0);
 Ov001_MoveSpriteLayout(M2C_FIELD((u8 *)gOv001Keypad+i*4,s32 *,0x40),-1,gKeypadActionRects[i*2],arg1);
 }
}
#pragma pop
void func_ov001_021751c8(s32 arg0, s32 arg1) {
void func_ov001_0218a304(s32,s32,s32,u8);
extern void *gOv001Keypad;
extern u8 data_ov001_0218f5e4[],data_ov001_0218f5d8[];
void *p;u32 color;s32 index;
if(arg0<0)return;
if(arg0<10){
p=M2C_FIELD((u8 *)gOv001Keypad+arg0*4,void **,0x10);
color=((volatile u8 *)data_ov001_0218f5e4)[arg1];
M2C_FIELD(p,u32 *,0)&=~0xc00;
M2C_FIELD(p,u16 *,4)=(M2C_FIELD(p,u16 *,4)&~0xf000)|(color<<12);
return;
}
index=arg0-10;
if(index<2){
p=M2C_FIELD((u8 *)gOv001Keypad+index*4,void **,0x38);
color=((volatile u8 *)data_ov001_0218f5e4)[arg1];
M2C_FIELD(p,u32 *,0)&=~0xc00;
M2C_FIELD(p,u16 *,4)=(M2C_FIELD(p,u16 *,4)&~0xf000)|(color<<12);
return;
}
func_ov001_0218a304(M2C_FIELD((u8 *)gOv001Keypad+(arg0-12)*4,s32 *,0x40),-1,0,data_ov001_0218f5d8[arg1]);
}

void Ov001KeypadCommitKey(void) {
    s32 Ov001_GetSpriteObjEntry(s32, M2C_UNK);
    M2C_UNK Ov001_MoveSpriteLayout(s32, M2C_UNK, u16, u16);
    M2C_UNK Ov001_SetSpritePalette(s32, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_LoadSpriteObjLayout(M2C_UNK, M2C_UNK, s32);
    extern u16 data_ov001_0218f66a[];
    extern u16 data_ov001_0218f66c[];
    extern void *gOv001Keypad;
    M2C_UNK var_r4;
    s32 temp_ip;
    if (M2C_FIELD(gOv001Keypad, s8 *, 0x63) <= 0xB) var_r4 = 0x44;
    else var_r4 = 0x45;
    Ov001_LoadSpriteObjLayout(0, var_r4, Ov001_GetSpriteObjEntry(M2C_FIELD(gOv001Keypad, s32 *, 0x58), 0));
    Ov001_SetSpritePalette(M2C_FIELD(gOv001Keypad, s32 *, 0x58), -1, 2);
    temp_ip = M2C_FIELD(gOv001Keypad, s8 *, 0x63) * 2;
    Ov001_MoveSpriteLayout(M2C_FIELD(gOv001Keypad, s32 *, 0x58), -1, data_ov001_0218f66a[temp_ip], data_ov001_0218f66c[temp_ip]);
}

void func_ov001_0217531c(s32 arg0) {
    void Ov001_PlaySound(s32);
    extern s8 data_ov001_0218f6a2[][4];
    extern void *gOv001Keypad;
    s8 old;
    s8 current;
    old = M2C_FIELD(gOv001Keypad, s8 *, 0x63);
    M2C_FIELD(gOv001Keypad, s8 *, 0x63) = data_ov001_0218f6a2[old][arg0];
    current = M2C_FIELD(gOv001Keypad, s8 *, 0x63);
    if (current == 13 && (arg0 == 1 || arg0 == 3)) {
        M2C_FIELD(gOv001Keypad, s8 *, 0x64) = old;
    } else if (current == -1) {
        if (M2C_FIELD(gOv001Keypad, s8 *, 0x64) == 1 || M2C_FIELD(gOv001Keypad, s8 *, 0x64) == 10)
            M2C_FIELD(gOv001Keypad, s8 *, 0x63) = 10;
        else M2C_FIELD(gOv001Keypad, s8 *, 0x63) = 11;
    } else if (current == -2) {
        if (M2C_FIELD(gOv001Keypad, s8 *, 0x64) == 1 || M2C_FIELD(gOv001Keypad, s8 *, 0x64) == 10)
            M2C_FIELD(gOv001Keypad, s8 *, 0x63) = 1;
        else M2C_FIELD(gOv001Keypad, s8 *, 0x63) = 2;
    }
    Ov001KeypadCommitKey();
    Ov001_PlaySound(8);
}

#pragma scheduling off
void func_ov001_021753c8(M2C_UNK arg0) {
    #pragma scheduling off
    M2C_UNK func_ov001_0218c924(M2C_UNK, void (*)(M2C_UNK));
    void func_ov001_02175440(M2C_UNK);
    extern void *gOv001Keypad;
    Position pos;
    s32 bits;
    bits = *(s32 *)Ov001_GetSpriteObjEntry(M2C_FIELD(gOv001Keypad, s32 *, 0x40), 0);
    pos.y = (u32)(bits & 0x01ff0000) >> 16;
    pos.x = (u8)bits + 12;
    ((void(*)(s32,s32,u32))func_ov001_02174f68)(4, pos.x, pos.y);
    if (*(volatile s32 *)&pos.x < 0xc0) return;
    func_ov001_0218c924(arg0, func_ov001_02175440);
}
#pragma scheduling reset
void func_ov001_02175440(M2C_UNK arg0) {
M2C_UNK func_ov001_0218c924(M2C_UNK,void(*)(M2C_UNK));void func_ov001_021754b0(M2C_UNK);extern void *gOv001Keypad;
s32 bits=*M2C_FIELD(gOv001Keypad,s32 **,0x34);
Position pos;
pos.y=(u32)(bits&0x01ff0000)>>16;pos.x=(u8)bits+12;
((void(*)(s32))func_ov001_02174f68)(3);
if(*(volatile s32*)&pos.x<192)return;func_ov001_0218c924(arg0,func_ov001_021754b0);
}

void func_ov001_021754b0(M2C_UNK arg0) {
M2C_UNK func_ov001_0218c924(M2C_UNK,void(*)(M2C_UNK));void func_ov001_02175520(M2C_UNK);extern void *gOv001Keypad;
s32 bits=*M2C_FIELD(gOv001Keypad,s32 **,0x28);
Position pos;
pos.y=(u32)(bits&0x01ff0000)>>16;pos.x=(u8)bits+12;
((void(*)(s32))func_ov001_02174f68)(2);
if(*(volatile s32*)&pos.x<192)return;func_ov001_0218c924(arg0,func_ov001_02175520);
}

void func_ov001_02175520(M2C_UNK arg0) {
M2C_UNK func_ov001_0218c924(M2C_UNK,void(*)(M2C_UNK));void func_ov001_02175590(M2C_UNK);extern void *gOv001Keypad;
s32 bits=*M2C_FIELD(gOv001Keypad,s32 **,0x1c);
Position pos;
pos.y=(u32)(bits&0x01ff0000)>>16;pos.x=(u8)bits+12;
((void(*)(s32))func_ov001_02174f68)(1);
if(*(volatile s32*)&pos.x<192)return;func_ov001_0218c924(arg0,func_ov001_02175590);
}

void func_ov001_02175590(M2C_UNK arg0) {
M2C_UNK func_ov001_0218c924(M2C_UNK,void(*)(M2C_UNK));void func_ov001_02175600(M2C_UNK);extern void *gOv001Keypad;
s32 bits=*M2C_FIELD(gOv001Keypad,s32 **,0x10);
Position pos;
pos.y=(u32)(bits&0x01ff0000)>>16;pos.x=(u8)bits+12;
((void(*)(s32))func_ov001_02174f68)(0);
if(*(volatile s32*)&pos.x<192)return;func_ov001_0218c924(arg0,func_ov001_02175600);
}

