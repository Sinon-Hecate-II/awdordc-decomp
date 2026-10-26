/* 12 functions from 0x021A11B0 to 0x021A2100 (ov000), found by ds-decomp. */
#include "common.h"

s32 func_ov000_021a18d8(void) {
s32 func_020cf878(u8,u8);
extern void **data_027e0058;
extern s8 data_ov000_021b55a0[];
extern u8 data_ov000_021e00ac[];
s32 n=0;u8 *p;u8 *dst; u8 *base;
dst=data_ov000_021e00ac; base=*data_027e0058;p=base+0x6c60;
if(base[0x6c60]!=255) do {
if(func_020cf878(p[1],p[2])==1) {
n++;dst[0]=p[1];dst[1]=p[2];dst[2]=data_ov000_021b55a0[p[0]];
if((p[0]&31)==16)dst[2]=1;
dst[3]=127;M2C_FIELD(dst,s8 *,4)=-1;dst[5]=0;dst[6]=0;dst[7]=255;dst[8]=255;dst[9]=255;dst[10]=255;dst+=12;
}p+=6;
}while(*p!=255);
return n;
}

s32 func_ov000_021a1ab8(void) {
 s32 func_ov000_021a64c4(); M2C_UNK func_ov000_021a7ac0(s32); s32 func_ov000_021a8438(s32); M2C_UNK func_ov000_021a07c0(s32);
 extern u8 data_ov000_021e00af[];
 s32 x=func_ov000_021a64c4();
 if(x==-1) return 0;
 func_ov000_021a7ac0(x);
 if(func_ov000_021a8438(x)!=-1) {func_ov000_021a07c0(x); return 1;}
 data_ov000_021e00af[x*12]=253;
 return 0;
}

/* Tries to activate candidate 0x17: checks flags, availability and resources, then records it. */
s32 func_ov000_021a1c24(void) {
    s32 func_020b9e20(u16, M2C_UNK);
    s32 func_020d2d18(u16, M2C_UNK);
    s32 func_ov000_021a6940();
    M2C_UNK func_ov000_021a07c0();
    extern void **data_027e0058;
    extern void *data_ov000_021df57c;
    extern void *data_ov000_021df580;
    extern M2C_UNK data_ov000_021df7d0;
    void *base;
    u16 id;
    s32 result;
    if (!(((u32) (M2C_FIELD(data_ov000_021df580, u16 *, 0xA) << 0x14) >> 0x1D) & 4)) return 0;
    if (M2C_FIELD(data_ov000_021df57c, u8 *, 0x11C) == 0) return 0;
    if (func_020b9e20(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), 0x17) == 0) return 0;
    base = *data_027e0058;
    id = M2C_FIELD(base, u16 *, 0x52A4);
    if ((s32) (func_020d2d18(id, 0x17) * 0xA) > M2C_FIELD(((id * 0x8C) + (s32) base), s32 *, 0x67A4)) return 0;
    result = func_ov000_021a6940();
    if (result == -1) return 0;
    M2C_FIELD(&data_ov000_021df7d0, s8 *, 6) = 0x17;
    func_ov000_021a07c0(result);
    return 1;
}

/* Tries to activate candidate 0x17, using a stricter resource threshold (func_ov000_021a6a00). */
s32 func_ov000_021a1d08(void) {
    s32 func_020b9e20(u16, M2C_UNK);
    s32 func_020d2d18(u16, M2C_UNK);
    s32 func_ov000_021a6a00();
    M2C_UNK func_ov000_021a07c0();
    extern void **data_027e0058;
    extern void *data_ov000_021df57c;
    extern void *data_ov000_021df580;
    extern M2C_UNK data_ov000_021df7d0;
    void *base;
    u16 id;
    s32 result;
    if (!(((u32) (M2C_FIELD(data_ov000_021df580, u16 *, 0xA) << 0x14) >> 0x1D) & 4)) return 0;
    if (M2C_FIELD(data_ov000_021df57c, u8 *, 0x11C) == 0) return 0;
    if (func_020b9e20(M2C_FIELD(*data_027e0058, u16 *, 0x52A4), 0x17) == 0) return 0;
    base = *data_027e0058;
    id = M2C_FIELD(base, u16 *, 0x52A4);
    if ((s32) (func_020d2d18(id, 0x17) * 0xA) > M2C_FIELD(((id * 0x8C) + (s32) base), s32 *, 0x67A4)) return 0;
    result = func_ov000_021a6a00();
    if (result == -1) return 0;
    M2C_FIELD(&data_ov000_021df7d0, s8 *, 6) = 0x17;
    func_ov000_021a07c0(result);
    return 1;
}

s32 func_ov000_021a1dec(void) {
s32 func_020b9e20(u16,M2C_UNK);s32 func_020d2d18(u16,M2C_UNK);s32 func_ov000_021a6ac0();M2C_UNK func_ov000_021a07c0();
extern void **data_027e0058;extern void *data_ov000_021df57c,*data_ov000_021df580;extern M2C_UNK data_ov000_021df7d0;
void *base;u16 id;s32 result;
if(!(((u32)(M2C_FIELD(data_ov000_021df580,u16 *,0xa)<<20)>>29)&4))return 0;
if(M2C_FIELD(data_ov000_021df57c,u8 *,0x110)==0)return 0;
if(func_020b9e20(M2C_FIELD(*data_027e0058,u16 *,0x52a4),0x16)==0)return 0;
base=*data_027e0058;id=M2C_FIELD(base,u16 *,0x52a4);
if((s32)(func_020d2d18(id,0x16)*10)>M2C_FIELD(id*0x8c+(s32)base,s32 *,0x67a4))return 0;
result=func_ov000_021a6ac0();if(result==-1)return 0;
M2C_FIELD(&data_ov000_021df7d0,s8 *,6)=0x16;
func_ov000_021a07c0(result);return 1;
}

s32 func_ov000_021a1ed0(void) {
 extern void **data_027e0058; extern void *data_ov000_021df57c;
 s32 r=0; u16 x;
 x=M2C_FIELD(*data_027e0058,u16 *,0x52a2);
 if((s32)x>3) {r=M2C_FIELD(data_ov000_021df57c,u8 *,10)*x; if(r>80) r=80;}
 return r;
}

s32 func_ov000_021a20d4(void) {
    M2C_UNK func_ov000_021a07c0();
    M2C_UNK func_ov000_021a7d08();
    s32 func_ov000_021a7f1c(M2C_UNK);
    func_ov000_021a7d08();
    if (func_ov000_021a7f1c(1) == -1) {
        return 0;
    }
    func_ov000_021a07c0();
    return 1;
}
