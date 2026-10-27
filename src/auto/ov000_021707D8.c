/* 17 functions from 0x021707D8 to 0x02171774 (ov000), found by ds-decomp. */
#include "common.h"


void func_ov000_02170ca0(void) {
    M2C_UNK func_01ffa6fc(s32);
    s32 func_01ffa770(M2C_UNK *);
    M2C_UNK func_0208fe30(s32);
    extern M2C_UNK data_ov000_021b8b88;
    s32 temp_r4;
    temp_r4 = func_01ffa770(&data_ov000_021b8b88);
    func_0208fe30(0x10018);
    func_01ffa6fc(temp_r4);
}

#pragma opt_strength_reduction off
void func_ov000_02170ccc(void *p){
extern void *gCur3DSpriteEngine,*data_027e00c8;extern void **gCurrentMap;
extern M2C_UNK data_ov000_021b8bc8,data_ov000_021b8bd8,data_ov000_021b8be8,data_ov000_021b8bf8,data_ov000_021b8c08;
void func_020994e0(s32);M2C_UNK func_01ff9ce8(M2C_UNK);void func_0200bc5c(void *);void *func_020e3218(void *);void func_020814e4(void *);void func_02081590(void *,void *);void func_02080944(void *,s32,s32,s32);void func_02081528(void);void func_0208116c(void *,s32,s32);void func_020c0fac(void *);s32 func_020cfb94(void);void *func_ov000_0216ce10(s32);void *func_ov000_0216ce84(s32);void func_02007ef4(void *,void *,s32);void func_01ff9e44(void *,s32,s32);void func_020ae528(void *);void func_ov000_021707d8(void);
void *old=gCur3DSpriteEngine;s32 i;void *dst;u8 *u;s32 t,off;
gCur3DSpriteEngine=data_027e00c8;func_020994e0(0);func_01ff9ce8(1);func_01ff9ce8(2);
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x3a)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x42)=1;
func_0200bc5c(&data_ov000_021b8bc8);func_020814e4(func_020e3218(&data_ov000_021b8bd8));
func_02081590(func_020e3218(&data_ov000_021b8be8),M2C_FIELD(data_027e00c8,void **,0x14));
func_02081590(func_020e3218(&data_ov000_021b8bf8),M2C_FIELD(gCur3DSpriteEngine,void **,0x28));
func_02080944(M2C_FIELD(gCur3DSpriteEngine,void **,0x28),32,24,6);func_02081528();func_0208116c(&data_ov000_021b8c08,192,32);func_020c0fac(p);
i=0;if(func_020cfb94()>0){t=0x35c;do{
u=(u8 *)*gCurrentMap+0x67a4+(i+1)*140;dst=(u8 *)M2C_FIELD(data_027e00c8,void * volatile *,0x1c)+(t<<5);
func_02007ef4(func_ov000_0216ce10(u[0x27]),dst,128);
off=(i+27)<<5;func_01ff9e44(func_ov000_0216ce84(u[0x1d]),off,32);
if(u[0x1c])func_020ae528((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x30)+(off&~1));
i++;t+=4;}while(i<func_020cfb94());}
func_ov000_021707d8();M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;gCur3DSpriteEngine=old;
}
#pragma opt_strength_reduction reset
void func_ov000_02170ea4(void){
extern u16 *data_02101e84;extern void *gCur3DSpriteEngine,*data_027e00c8;extern void **gCurrentMap;extern M2C_UNK data_027e0064;
s32 func_020cfb94(void);void func_01ffaacc(s32,s32,u16,void *,s32);
void *old; s32 i;u8 *p;u32 bits;
if(*data_02101e84&2){func_ov000_02170ca0();return;}
old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
for(i=0;i<func_020cfb94();i++){
p=(u8 *)*gCurrentMap+i*140+0x67a4;
if(p[0xaa]&&!p[0xa5]){bits=(u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
func_01ffaacc(16,(46+i*24)&255,(u16)((((0x35c+i*4)>>bits)&1023)|(u16)((i+11)<<12)),&data_027e0064,0);}
}
gCur3DSpriteEngine=old;
}
#pragma opt_common_subs reset
void func_ov000_02170fc4(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_020cfd28();
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    func_020cfd28();
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_02171028(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8b88;
    func_01ffa3dc(&data_ov000_021b8b88, 7);
}

#pragma scheduling off
void func_ov000_02171040(void *p){
extern void *gCur3DSpriteEngine,*data_027e00c8;extern void **gCurrentMap;
extern M2C_UNK data_ov000_021b8c58,data_ov000_021b8c60,data_ov000_021b8c70,data_ov000_021b8c7c,data_ov000_021b8c88;
s32 func_020a8afc(s32);void func_0209b26c();
void func_0200bc5c(void *);void *func_020e3218(void *);
void func_020814e4(void *);void func_02081590(void *,void *);void func_020815fc(void *,s32,s32);
void func_02081528(void);void func_02091d4c(s32);
s32 func_01ff9c34(u8,s32);void func_01ff85b8(void *,u16,s32);void func_020c0fac(void *);
void *old=gCur3DSpriteEngine;s32 n;u16 v;
gCur3DSpriteEngine=data_027e00c8;
n=func_020a8afc(M2C_FIELD(*gCurrentMap,u16 *,0x5142));
func_02091d4c(0);func_0209b26c(5,8,1,n,0,64);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
func_0200bc5c(&data_ov000_021b8c58);
func_020814e4(func_020e3218(&data_ov000_021b8c60));
func_02081590(func_020e3218(&data_ov000_021b8c70),M2C_FIELD(gCur3DSpriteEngine,void **,0x14));
func_02081590(func_020e3218(&data_ov000_021b8c7c),M2C_FIELD(gCur3DSpriteEngine,void **,0x28));
func_020815fc(func_020e3218(&data_ov000_021b8c88),0x60,0x20);
func_02081528();
v=func_01ff9c34((u8)((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<29)>>29),2);
func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,void **,0x28),v,0x3000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
func_020c0fac(p);gCur3DSpriteEngine=old;
}
#pragma scheduling reset
void func_ov000_021711a4(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    func_0208fe30(0x10018);
}

void func_ov000_021711f0(s32 arg0) {
    M2C_UNK func_01ffa6fc(s32);
    extern u16 *data_02101e84;
    if (!(*data_02101e84 & 2)) return;
    func_01ffa6fc(arg0);
}

void func_ov000_02171214(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8c18;
    func_01ffa3dc(&data_ov000_021b8c18, 7);
}

void func_ov000_02171468(u8 *p){
extern void *gCur3DSpriteEngine,*data_027e00c8;
extern M2C_UNK data_ov000_021b8ce8,data_ov000_021b8cf0,data_ov000_021b8d00,data_ov000_021b8d0c;
void func_020e4c64(void);void func_0200bc5c(void *);void *func_020e3218(void *);
void func_020814e4(void *);void func_02081590(void *,void *);void func_020815fc(void *,s32,s32);
s32 func_ov000_0217122c(s32);void func_02081528(void);void func_02091d4c(s32);
s32 func_01ff9c34(u8,s32);void func_01ff85b8(void *,u16,s32);void func_020c0fac(void *);
void *old=gCur3DSpriteEngine;s32 i;
gCur3DSpriteEngine=data_027e00c8;
func_020e4c64();func_0200bc5c(&data_ov000_021b8ce8);
func_020814e4(func_020e3218(&data_ov000_021b8cf0));
func_02081590(func_020e3218(&data_ov000_021b8d00),M2C_FIELD(gCur3DSpriteEngine,void **,0x14));
func_020815fc(func_020e3218(&data_ov000_021b8d0c),0x60,0x20);
for(i=1;i<5;i++){if(func_ov000_0217122c(i))p[0x34+i]=1;else p[0x34+i]=0;}
func_02081528();func_02091d4c(0);
func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,void **,0x28),(u16)func_01ff9c34((u8)((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<29)>>29),2),0x3000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3a)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x42)=3;
func_020c0fac(p);gCur3DSpriteEngine=old;
}

void func_ov000_021715a4(u8 *p){
extern void *gCur3DSpriteEngine,*data_027e00c8;
extern M2C_UNK data_027e0064;
void func_ov000_0216a374(s32,u16,u16,s32);
void func_01ffaacc(s32,s32,u16,void *,s32);
void *old=gCur3DSpriteEngine;s32 i;
gCur3DSpriteEngine=data_027e00c8;
for(i=1;i<5;i++){
if(p[0x34+i]){
s32 n=i-1;
func_ov000_0216a374(0x42,(u16)((n*40+21)&511),(u16)(((n*12+0x35c)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0xb000),11);
func_01ffaacc(8,(n*40+14)&255,(u16)(((n*12+0x364)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|(u16)((n+12)<<12)),&data_027e0064,11);
}
}
gCur3DSpriteEngine=old;
}

void func_ov000_021716c0(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020e4ca0();
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0x3a) = 0;
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0x42) = 0;
    func_020e4ca0();
    func_0208fe30(0x10018);
}

void func_ov000_0217172c(s32 arg0) {
    M2C_UNK func_01ffa6fc(s32);
    extern u16 *data_02101e84;
    if (!(*data_02101e84 & 2)) return;
    func_01ffa6fc(arg0);
}

void func_ov000_02171750(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8c94;
    func_01ffa3dc(&data_ov000_021b8c94, 7);
}

s32 func_ov000_02171768(s32 arg0) {
    return (arg0 * 0x10) + 0x430;
}
