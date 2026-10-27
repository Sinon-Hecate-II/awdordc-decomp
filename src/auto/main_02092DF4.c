/* 50 functions from 0x02092DF4 to 0x02093D9C (main), found by ds-decomp. */
#include "common.h"

s32 func_02092df4(void *arg0) {
 s32 (*temp_r0)();
 s32 var_r0;
 void *temp_r0_2;
 void *temp_r0_3;
 temp_r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 (**)(), 4);
 if (temp_r0 != NULL) {
  if (temp_r0() != 0) var_r0 = 1; else var_r0 = 0;
 } else var_r0 = 1;
 if (var_r0 != 0) {
  temp_r0_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0xC);
  M2C_FIELD(arg0, void **, 4) = temp_r0_3;
  M2C_FIELD(arg0, void **, 0) = temp_r0_3;
 } else {
  M2C_FIELD(arg0, void **, 4) = M2C_FIELD(arg0, void **, 4) + 0x10;
 }
 return 1;
}

s32 func_02092e4c(void *arg0) {
 M2C_UNK func_020a23a4(u8, s16);
 extern void **gCurrentMap;
 u8 temp_r0;
 void *temp_r1;
 temp_r1 = M2C_FIELD(arg0,void **,4);
 temp_r0 = (u8) M2C_FIELD(temp_r1,s16 *,8);
 func_020a23a4((u8)temp_r0,M2C_FIELD(temp_r1,s16 *,0xa));
 M2C_FIELD((u8)temp_r0 * 0x8c + (s32)*gCurrentMap,s8 *,0x67c2) = M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,0xa);
 M2C_FIELD(arg0,void **,4) = M2C_FIELD(arg0,void **,4)+0x10;
 return 1;
}

s32 func_02092ea8(void *arg0) {
    extern void **gCurrentMap;
    M2C_FIELD(*gCurrentMap, s8 *, 0x5155) = (s8) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092edc(void *arg0) {
 extern void **gCurrentMap;
 extern s32 data_027e00c4, gCur3DSpriteEngine;
 s32 temp_ip;
 temp_ip=gCur3DSpriteEngine;
 gCur3DSpriteEngine=data_027e00c4;
 M2C_FIELD(*gCurrentMap,s8 *,0x5155) = M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,8);
 gCur3DSpriteEngine=temp_ip;
 M2C_FIELD(arg0,void **,4) = M2C_FIELD(arg0,void **,4)+0x10;
 return 1;
}

s32 func_02092f30(void *arg0){
extern void **gCurrentMap;
void *p=M2C_FIELD(arg0,void **,4);
s16 value=M2C_FIELD(p,s16 *,10);
void *dest=(u8 *)*gCurrentMap+0x67a4+M2C_FIELD(p,s16 *,8)*0x8c;
M2C_FIELD(dest,u32 *,0x6c)=(M2C_FIELD(dest,u32 *,0x6c)&~255)|(value&255);
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_02092f84(void *arg0){
extern void **gCurrentMap;
M2C_FIELD(*gCurrentMap,s16 *,0x52c2)=M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,8);
M2C_FIELD(*gCurrentMap,s16 *,0x52c4)=M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,10);
M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(*gCurrentMap,u16 *,0x52a4)*0x8c,u8 *,0x67d1)=M2C_FIELD(*gCurrentMap,s16 *,0x52c2);
M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(*gCurrentMap,u16 *,0x52a4)*0x8c,u8 *,0x67d2)=M2C_FIELD(*gCurrentMap,s16 *,0x52c4);
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02093018(void *arg0){
extern void **gCurrentMap;
M2C_FIELD(*gCurrentMap,s16 *,0x52c2)+=M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,8);
M2C_FIELD(*gCurrentMap,s16 *,0x52c4)+=M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,10);
M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(*gCurrentMap,u16 *,0x52a4)*0x8c,u8 *,0x67d1)=M2C_FIELD(*gCurrentMap,s16 *,0x52c2);
M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(*gCurrentMap,u16 *,0x52a4)*0x8c,u8 *,0x67d2)=M2C_FIELD(*gCurrentMap,s16 *,0x52c4);
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_020930bc(void *arg0) {
    s32 func_020cc7f8();
    if (func_020cc7f8() == 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    }
    return 0;
}

s32 func_020930e0(void *arg0) {
    M2C_UNK func_020bbb08();
    func_020bbb08();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 0;
}

s32 func_02093100(void *arg0) {
    s32 func_02091ecc(s16);
    M2C_UNK func_02096c7c(s32, M2C_UNK);
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r0;
    s32 temp_r5;

    temp_r0 = func_02091ecc(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8));
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_02096c7c(temp_r0, 0x80);
    gCur3DSpriteEngine = temp_r5;
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093154(void *arg0) {
    s32 func_02091ecc(s16);
    M2C_UNK func_02096c7c(s32, M2C_UNK);
    extern s32 data_027e00c4;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r0;
    s32 temp_r5;

    temp_r0 = func_02091ecc(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8));
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_02096c7c(temp_r0, 0x80);
    gCur3DSpriteEngine = temp_r5;
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020931a8(void *arg0) {
    s32 func_02091ecc(s16);
    M2C_UNK func_02096ba4(s32, M2C_UNK);
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r0;
    s32 temp_r5;

    temp_r0 = func_02091ecc(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8));
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_02096ba4(temp_r0, 0x80);
    gCur3DSpriteEngine = temp_r5;
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020931fc(void *arg0) {
    s32 func_02091ecc(s16);
    M2C_UNK func_02096ba4(s32, M2C_UNK);
    extern s32 data_027e00c4;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r0;
    s32 temp_r5;

    temp_r0 = func_02091ecc(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8));
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    func_02096ba4(temp_r0, 0x80);
    gCur3DSpriteEngine = temp_r5;
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093250(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    s32 func_0209600c();
    s32 temp_r4;

    temp_r4 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC);
    if (func_0209600c() == 0) {
        func_0208fe30(temp_r4);
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093288(void *arg0) {
    M2C_UNK func_0208ffe4(M2C_UNK, M2C_UNK, s32);
    s32 temp_r4;

    temp_r4 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC);
    if (func_0209600c() == 0) {
        func_0208ffe4(0, -1, temp_r4);
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020932c8(void *arg0) {
    M2C_UNK func_02090034(M2C_UNK, s32);
    s32 var_r4;

    var_r4 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC);
    if (func_0209600c() != 0) {
        var_r4 = 0;
    }
    func_02090034(0, var_r4);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093304(void *arg0) {
s32 v;
s32 temp=M2C_FIELD(M2C_FIELD(arg0,void **,4),s32 *,12);
if(func_0209600c()!=0) v=1;
else {func_0208f780(temp);v=0;}
M2C_FIELD(arg0,s32 *,4)+=16;return (s16)v;
}

s32 func_02093348(void *arg0) {
    M2C_UNK func_0208f844(s32);
    func_0208f844(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

void func_02093370(void *arg0) {
    s32 func_0208f8a0();
    if (func_0208f8a0() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_0209338c(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 8) = func_02093370;
 M2C_FIELD(arg0, s32 *, 4) += 0x10;
 return 0;
}

s32 func_020933ac(void *arg0) {
    M2C_UNK func_0208f8ec(s16, s32);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    func_0208f8ec(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_020933d8(void *arg0) {
    M2C_UNK func_0208f8c4();
    func_0208f8c4();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 0;
}

s32 func_020933f8(void *arg0) {
    M2C_UNK func_0208f8d8();
    func_0208f8d8();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 0;
}

s32 func_02093418(void *arg0) {
extern void **gCurrentMap;
s32 func_020a2b00(s32);
func_0208f7d0(func_020a2b00(M2C_FIELD(*gCurrentMap,u16 *,0x52A4)&255));
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02093458(void *arg0) {
extern void **gCurrentMap;
s32 func_020a2b00(s32);
if(func_0209600c()==0) {
s32 v=func_0208f770();
if(v==func_020a2b00(M2C_FIELD(*gCurrentMap,u16 *,0x52A4)&255)) func_0208f8c4();
}
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_020934b4(void *arg0) {
extern void **gCurrentMap;
s32 func_020a2b00(s32);
s32 v=func_0208f770();
if(v==func_020a2b00(M2C_FIELD(*gCurrentMap,u16 *,0x52A4)&255)) func_0208f8d8();
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02093504(void *arg0) {
    s32 func_020a8c10();
    s16 temp_r5;
    s32 var_r6;
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    temp_r5 = M2C_FIELD(temp_r1, s16 *, 0xA);
    var_r6 = M2C_FIELD(temp_r1, s32 *, 0xC);
    func_02091ecc((s16) M2C_FIELD(temp_r1, s16 *, 8) >> 1);
    if ((temp_r5 != func_020a8c10()) && (var_r6 > 0)) {
        do {
            var_r6 -= 1;
            M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
        } while (var_r6 > 0);
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093564(void *arg0) {
    M2C_UNK func_02086ae4(s16, M2C_UNK);
    func_02086ae4(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8), 1);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093590(void *arg0) {
    func_02086ae4(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8), 0);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020935bc(void *arg0) {
    M2C_UNK func_0209656c(s32, u8);
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 4);
    func_0209656c(M2C_FIELD(temp_r0, s32 *, 4), (u8) M2C_FIELD(temp_r0, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

void func_020935ec(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_ov000_0216939c();
    M2C_UNK func_ov000_02169540(s32, M2C_UNK);
    M2C_UNK func_ov000_02169998(M2C_UNK, M2C_UNK);
    func_ov000_02169540(func_ov000_0216939c(), arg1);
    func_ov000_02169998(arg0, arg1);
}

void func_02093614(void *arg0, u8 arg1, u8 arg2) {
    M2C_UNK func_01ffada0(u8, u8, u32, s32, s32);
    M2C_UNK func_01ffc4b8(M2C_UNK, M2C_UNK, s32);
    s32 func_ov000_0216939c();
    M2C_UNK func_ov000_02169540(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov000_02169998(M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;
    u8 *r4 = arg0;
    signed char *ptr;
    void *q;

    func_01ffada0(r4[1], r4[2], (u32) (r4[0] << 0x1A) >> 0x1A, 0x6E, 1);
    func_01ffc4b8(arg1, arg2, (s32) *gCurrentMap + 0x5388);
    ptr = (signed char *) *gCurrentMap + 0x5388;
    while (*ptr != 4 && *ptr != -1) {
        ptr++;
    }
    *ptr = (signed char) -1;
    q = (void *) func_ov000_0216939c(r4);
    func_ov000_02169540(q, (s32) *gCurrentMap + 0x5388);
    func_ov000_02169998(r4, (s32) *gCurrentMap + 0x5388);
}

s32 func_020936ec(void *arg0){
extern void **gCurrentMap;
void *p=M2C_FIELD(arg0,void **,4);
void *base=*gCurrentMap;
u32 index=M2C_FIELD((u8 *)base+ (M2C_FIELD(p,s16 *,8)+M2C_FIELD((u8 *)base+M2C_FIELD(p,s16 *,10)*2,u16 *,0x3758)),u8 *,0x508);
if(index)func_020935ec((u8 *)base+0x59a4+index*14,M2C_FIELD(p,s32 *,4));
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_0209375c(void *arg0){
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
void *p=M2C_FIELD(arg0,void **,4);
s32 start=data_ov000_021aeef4[M2C_FIELD(p,s16 *,8)];
void *found=0;
s32 i;

for(i=start+1;i<start+51;i++){
void *base=(u8 *)*gCurrentMap+0x59a4;
void *entry=(u8 *)base+i*14;
u32 kind=(u32)(M2C_FIELD(entry,u8 *,0)<<26)>>26;
if(kind && (!M2C_FIELD(p,s16 *,10)||kind==M2C_FIELD(p,s16 *,10))){found=(u8 *)base+i*14;break;}
}
if(found)func_020935ec(found,M2C_FIELD(p,s32 *,4));
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_0209380c(void *arg0){
extern void **gCurrentMap;
void *p=M2C_FIELD(arg0,void **,4);
void *base=*gCurrentMap;
u32 packed=M2C_FIELD(p,u32 *,12);
u32 a=packed&255;
u32 b=(packed>>8)&255;
u32 index=M2C_FIELD((u8 *)base+ (M2C_FIELD(p,s16 *,8)+M2C_FIELD((u8 *)base+M2C_FIELD(p,s16 *,10)*2,u16 *,0x3758)),u8 *,0x508);
if(index)func_02093614((u8 *)base+0x59a4+index*14,a,b);
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_02093888(void *arg0) {
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
void *p=M2C_FIELD(arg0,void **,4);
u32 v=M2C_FIELD(p,s32 *,12);
void *found=0;
s32 i=data_ov000_021aeef4[M2C_FIELD(p,s16 *,8)]+1;
s32 end=data_ov000_021aeef4[M2C_FIELD(p,s16 *,8)]+0x33;
u8 a=v,b=v>>8;
if(i<end) {
u8 *base=(u8 *)*gCurrentMap+0x59A4;
u8 *entry=base+i*14;
do {
u32 bits=(u32)(*entry<<26)>>26;
if(bits && (M2C_FIELD(p,s16 *,10)==0 || bits==M2C_FIELD(p,s16 *,10))) {found=base+i*14;break;}
i++;entry+=14;
}while(i<end);
}
if(found)func_02093614(found,a,b);
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

void func_02093944(void *arg0) {
    s32 func_ov000_0216971c();
    if (func_ov000_0216971c() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_02093960(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 8) = func_02093944;
 M2C_FIELD(arg0, s32 *, 4) += 0x10;
 return 0;
}

s32 func_02093980(void *arg0) {
extern void **gCurrentMap;
void *p=M2C_FIELD(arg0,void **,4);
s32 y=M2C_FIELD(p,s16 *,10);
s32 x=M2C_FIELD(p,s16 *,8);
void *base=*gCurrentMap;
u8 id=M2C_FIELD((u8 *)base+(x+M2C_FIELD((u8 *)base+y*2,u16 *,0x3758)),u8 *,0x508);
if(id) {func_020cfd28(func_020a6718(id));}
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_020939e0(void *arg0) {
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
void *p=M2C_FIELD(arg0,void **,4);
s32 i;
for(i=data_ov000_021aeef4[M2C_FIELD(p,s16 *,8)]+1;i<data_ov000_021aeef4[M2C_FIELD(p,s16 *,8)]+0x33;i++){
u32 bits=(u32)(M2C_FIELD((u8 *)*gCurrentMap+i*14,u8 *,0x59A4)<<26)>>26;
if(bits && (M2C_FIELD(p,s16 *,10)==0 || bits==M2C_FIELD(p,s16 *,10))) {
func_020a6718(i);p=M2C_FIELD(arg0,void **,4);
if(M2C_FIELD(p,s32 *,12)!=0)break;
}
}
func_020cfd28();
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_02093aa0(void *arg0) {
extern void **gCurrentMap;
void *p=M2C_FIELD(arg0,void **,4);
s32 y=M2C_FIELD(p,s16 *,10);
s32 x=M2C_FIELD(p,s16 *,8);
void *base=*gCurrentMap;
u8 id=M2C_FIELD((u8 *)base+(x+M2C_FIELD((u8 *)base+y*2,u16 *,0x3758)),u8 *,0x508);
if(id) {func_020b577c((u8 *)base+0x59A4+id*14);}
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

void func_02093b0c(void *arg0) {
    s32 func_020b5258();
    if (func_020b5258() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_02093b28(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 8) = func_02093b0c;
 M2C_FIELD(arg0, s32 *, 4) += 0x10;
 return 0;
}

s32 func_02093b48(void *arg0) {
    extern u16 data_ov000_021aeef4[];
    extern void **gCurrentMap;
    s32 *func_02092ca8(s32 **, s32);
    void *p = M2C_FIELD(arg0, void **, 4);
    s16 start_field = M2C_FIELD(p, s16 *, 8);
    s32 start = data_ov000_021aeef4[start_field];
    s32 i = start + 1;
    s32 limit = start + 0x33;
    s32 found = 0;
    u8 *base = (u8 *)*gCurrentMap + 0x59a4;
    u8 *entry = base + i * 14;
    for (; i < limit; i++) {
        u32 bits = ((u32)(*entry) << 26) >> 26;
        if (bits) {
            s16 p10 = M2C_FIELD(p, s16 *, 10);
            if (p10 == 0 || bits == (u32)p10) {
                found = 1;
                break;
            }
        }
        entry += 14;
    }
    if (M2C_FIELD(p, void **, 4) != 0) {
        M2C_FIELD(arg0, void **, 4) = (void *)((u8 *)M2C_FIELD(arg0, void **, 4) + 0x10);
    } else if (!found) {
        s32 *res = func_02092ca8((s32 **)arg0, M2C_FIELD(p, s32 *, 12));
        if (res != 0) {
            M2C_FIELD(arg0, void **, 4) = (void *)res;
        } else {
            M2C_FIELD(arg0, void **, 4) = (void *)((u8 *)M2C_FIELD(arg0, void **, 4) + 0x10);
        }
    } else {
        M2C_FIELD(arg0, void **, 4) = (void *)((u8 *)M2C_FIELD(arg0, void **, 4) + 0x10);
    }
    return 1;
}

s32 func_02093c2c(void *arg0){
extern void **gCurrentMap;
void *p=M2C_FIELD(arg0,void **,4);
M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(p,s16 *,8)*0x8c,u8 *,0x67bd)=M2C_FIELD(p,u32 *,12);
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_02093c6c(void *arg0) {
    M2C_UNK func_020952ec(s16, s16, s32);
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 4);
    func_020952ec(M2C_FIELD(temp_r2, s16 *, 8), M2C_FIELD(temp_r2, s16 *, 0xA), M2C_FIELD(temp_r2, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

void func_02093c9c(void *arg0) {
    s32 func_020953e8();
    if (func_020953e8() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_02093cb8(void *arg0){func_020953d0();M2C_FIELD(arg0,void (**)(void *),8)=func_02093c9c;M2C_FIELD(arg0,s32 *,4)+=16;return 0;}

s32 func_02093ce4(void *arg0) {
    M2C_UNK func_020943bc(s32);
    func_020943bc(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093d0c(void *arg0) {
    M2C_UNK func_02091e14();
    M2C_UNK func_020d4ba4();
    M2C_UNK func_020d8e28();
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    s32 var_r0;
    u8 var_r0_2;

    var_r0 = func_02091e14();
    if (var_r0 == 3) {
        if (gCur3DSpriteEngine == data_027e00c8) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        if (var_r0_2 != 1) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
    }
    switch (var_r0) {                               /* irregular */
    case 0:
        func_020d4ba4();
        break;
    case 1:
        func_020d8e28();
        break;
    case 2:
        func_020d8e28();
        func_020d4ba4();
        break;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 0;
}

