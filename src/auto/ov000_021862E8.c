/* 8 functions from 0x021862E8 to 0x02187188 (ov000), found by ds-decomp. */
#include "common.h"

void func_ov000_021862e8(s32 arg0) {
void func_01ffb3d0(s32); void func_01ffb554(void *);
s32 func_020d1938(s32); s32 func_020d273c(u16,s32); void func_ov000_02186070(u8,s32);
extern void **gCurrentMap;
u16 saved; s32 i; void *base;
base=*gCurrentMap; saved=M2C_FIELD(base,u16 *,0x52b6);
func_01ffb554(base+0x2338); func_01ffb3d0(-1); func_01ffb554(*gCurrentMap+0x1e30);
for(i=1;i<5;i++){if(func_020d1938(i)!=0 && func_020d273c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),i)==0)func_ov000_02186070(i,arg0);}
M2C_FIELD(*gCurrentMap,u16 *,0x52b6)=saved;
}

void func_ov000_0218639c(void) {
}

M2C_UNK func_ov000_02186624(u8 arg0, u8 arg1) {
    (void)arg0; (void)arg1;
}

void func_ov000_02186940(void *arg0) {
    void func_ov000_021862e8();
    M2C_UNK func_ov000_02186624(u8, u8);
    func_ov000_021862e8();
    func_ov000_02186624(M2C_FIELD(arg0, u8 *, 1), M2C_FIELD(arg0, u8 *, 2));
}

u8 func_ov000_0218695c(void *arg0) {
s32 func_020a7cfc(void *); s32 func_ov000_021a8a88(void *); s32 func_ov000_021a98e4(u32);
extern u8 data_ov000_021b5c0f;
u16 flags; u8 result;
flags=M2C_FIELD(arg0,u16 *,4);
if(flags&8)return 0;
if(!(flags&1) && ((u32)(M2C_FIELD(arg0,u8 *,10)<<24)>>31)==0)return 0;
if(((u32)(M2C_FIELD(arg0,u16 *,6)<<16)>>27)!=0 && func_ov000_021a8a88(arg0)==1)return 1;
if(func_020a7cfc(arg0)!=0)return 1;
if(func_ov000_021a98e4((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)!=1)return 0;
result= !(*(&data_ov000_021b5c0f+(((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*0x70))&32);
return result;
}

void func_ov000_02186a18(void) { }

s32 func_ov000_02186d94(s32 a, s32 b, s32 c) {
    extern void **gCurrentMap;
    u8 func_ov000_021a9d8c(u32, s32);
    extern u8 data_ov000_021b5c0e[];
    extern M2C_UNK data_0212616c;
    void *p;
    u16 n;
    u8 idxByte;
    u8 dataByte;
    s8 *table;
    if (a < 0 || b < 0) return 0;
    p = *gCurrentMap;
    if (!(a < M2C_FIELD(p, u16 *, 0x5144) && b < M2C_FIELD(p, u16 *, 0x5146))) return 0;
    if (func_ov000_021a9d8c((s16)a, (s16)b) != 0) return 0;
    p = *gCurrentMap;
    n = M2C_FIELD((u8 *)p + b * 2, u16 *, 0x3758);
    idxByte = M2C_FIELD((u8 *)p + a + n, u8 *, 0x1420) & 0x1f;
    dataByte = data_ov000_021b5c0e[c * 0x70];
    table = M2C_FIELD(&data_0212616c, s8 **, 0x64);
    return (table[(dataByte << 5) + idxByte] >= 0) ? 1 : 0;
}

s32 func_ov000_02186e64(s32 x, s32 y) { return 0; }

