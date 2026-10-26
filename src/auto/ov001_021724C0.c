/* 18 functions from 0x021724C0 to 0x0217332C (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_02172824(void) {
 extern void *data_ov001_02193d1c;
 void func_ov001_02173e38(void);
 func_ov001_0218a1cc(M2C_FIELD(data_ov001_02193d1c, s32 *, 0x114));
 func_ov001_0218c924(M2C_FIELD(data_ov001_02193d1c, s32 *, 0x118), func_ov001_02173e38);
}

u8 func_ov001_02172858(void) {
    extern void *data_ov001_02193d1c;
    return M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11C);
}

void func_ov001_0217286c(s8 arg0) {
    extern void *data_ov001_02193d1c;
    M2C_FIELD(data_ov001_02193d1c, s8 *, 0x123) = arg0;
}

void func_ov001_02172880(s8 arg0) {
 extern void *data_ov001_02193d1c;
 M2C_FIELD(data_ov001_02193d1c, s8 *, 0x124) = arg0;
}

s32 func_ov001_02172894(void) {
 extern void *data_ov001_02193d1c;
 if (data_ov001_02193d1c != 0) return 1;
 return 0;
}

void func_ov001_021728b0(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_02172944();
 struct { s32 x, y; } xy, *pos = &xy;
 u32 value = *M2C_FIELD(data_ov001_02193d1c, u32 **, 0x30);
 pos->y = (value & 0x1FF0000) >> 16;
 pos->x = value & 0xFF;
 pos->x -= 12;
 if (pos->x > 0x51) {
  func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 0, pos->x);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 0, 0x51);
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 1, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_02172944);
}

void func_ov001_02172944(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_021729d8();
 struct { s32 x, y; } xy, *pos = &xy;
 u32 value = *M2C_FIELD(data_ov001_02193d1c, u32 **, 0x60);
 pos->y = (value & 0x1FF0000) >> 16;
 pos->x = value & 0xFF;
 pos->x -= 12;
 if (pos->x > 0x67) {
  func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 1, pos->x);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 1, 0x67);
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 2, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_021729d8);
}

void func_ov001_021729d8(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_02172a6c();
 struct { s32 x, y; } xy, *pos = &xy;
 u32 value = *M2C_FIELD(data_ov001_02193d1c, u32 **, 0x90);
 pos->y = (value & 0x1FF0000) >> 16;
 pos->x = value & 0xFF;
 pos->x -= 12;
 if (pos->x > 0x7D) {
  func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 2, pos->x);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 2, 0x7D);
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 3, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_02172a6c);
}

void func_ov001_02172a6c(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_02172b00();
 struct { s32 x, y; } xy, *pos = &xy;
 u32 value = *M2C_FIELD(data_ov001_02193d1c, u32 **, 0xC0);
 pos->y = (value & 0x1FF0000) >> 16;
 pos->x = value & 0xFF;
 pos->x -= 12;
 if (pos->x > 0x93) {
  func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 3, pos->x);
  return;
 }
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 3, 0x93);
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c, u8 *, 0x11D), 4, 0xC0);
 func_ov001_0218c924(arg0, func_ov001_02172b00);
}

void func_ov001_02172b00(s32 arg0) {
 extern void *data_ov001_02193d1c;
 void func_ov001_02172b8c(void);
 s32 pos[2];
 func_ov001_0218a4d4(M2C_FIELD(data_ov001_02193d1c,s32 *,0xfc),0,&pos[1],&pos[0]);
 pos[0]-=12;
 if(pos[0]>170) {func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c,u8 *,0x11d),4,pos[0]);return;}
 func_ov001_0217355c(M2C_FIELD(data_ov001_02193d1c,u8 *,0x11d),4,170);
 func_ov001_02173924(); func_ov001_0218c924(arg0,func_ov001_02172b8c);
}

void func_ov001_02172b8c(void) {
    M2C_UNK func_ov001_021730d4();
    M2C_UNK func_ov001_0217332c();
    func_ov001_02172ba4();
    func_ov001_02172d8c();
    func_ov001_021730d4();
    func_ov001_0217332c();
}

void func_ov001_02173074(void) {
 extern void *data_ov001_02193d1c;
 s32 n;
 n=M2C_FIELD(data_ov001_02193d1c,u8 *,0x11d)==2?0:2;
 func_ov001_021737d8(n); func_ov001_02185024(1);
}

void func_ov001_021730a4(void) {
 extern void *data_ov001_02193d1c;
 func_ov001_021737d8(M2C_FIELD(data_ov001_02193d1c,u8 *,0x11d)!=1);
 func_ov001_02185024(1);
}

void func_ov001_021732d8(s32 arg0) {
 extern void *data_ov001_02193d1c;
 if(arg0==M2C_FIELD(data_ov001_02193d1c,s8 *,0x11f)) return;
 func_ov001_0217385c(arg0,1);
 func_ov001_0217385c(M2C_FIELD(data_ov001_02193d1c,s8 *,0x11f),0);
 M2C_FIELD(data_ov001_02193d1c,s8 *,0x11f)=arg0;
}

