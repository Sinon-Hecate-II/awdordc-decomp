/* 19 functions from 0x0219F6D0 to 0x021A0624 (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 id:6; } UnitId6;

s32 func_ov000_0219f6d0(void) {
    extern void *data_ov000_021df580;
    extern s32 data_ov000_021e1468;
    data_ov000_021e1468 = 0;
    M2C_FIELD(data_ov000_021df580, s8 *, 1) = 7;
    return 1;
}

s32 func_ov000_0219f6fc(void) {
    extern void *data_ov000_021df580;
    extern s32 data_ov000_021e1468;
    data_ov000_021e1468 = 0;
    M2C_FIELD(data_ov000_021df580, s8 *, 1) = 7;
    return 1;
}

s32 func_ov000_0219f918(void) {
void func_020bb0d0(u8);
void func_020bb0ec(u8,u8);
extern u8 data_ov000_021df7d0[];
extern void *data_ov000_021df580;
if(data_ov000_021df7d0[0] == 4) func_020bb0d0(data_ov000_021df7d0[6]);
else func_020bb0ec(data_ov000_021df7d0[6],data_ov000_021df7d0[7]);
M2C_FIELD(data_ov000_021df580,s8 *,0)=2;
M2C_FIELD(data_ov000_021df580,s8 *,1)=0;
return 0;
}

s32 func_ov000_0219f968(void) {
void func_020bac24(void);
void func_020cc66c(u8,u8);
void func_020bbbbc(u8,u8,u8,u8,s32);
extern u8 data_ov000_021df7d0[];
extern void *data_ov000_021df580;
func_020bac24();
func_020cc66c(data_ov000_021df7d0[6],data_ov000_021df7d0[7]);
func_020bbbbc(data_ov000_021df7d0[2],data_ov000_021df7d0[3],data_ov000_021df7d0[6],data_ov000_021df7d0[7],7);
M2C_FIELD(data_ov000_021df580,s8 *,1)=5;
return 0;
}

s32 func_ov000_0219f9c0(void) {
void func_020bac24(void);
void func_020cc66c(u8,u8);
void func_020bbd98(u8,u8,s32);
extern u8 data_ov000_021df7d0[];
extern void *data_ov000_021df580;
func_020bac24();
func_020cc66c(data_ov000_021df7d0[6],data_ov000_021df7d0[7]);
func_020bbd98(data_ov000_021df7d0[6],data_ov000_021df7d0[7],0);
M2C_FIELD(data_ov000_021df580,s8 *,1)=5;
return 0;
}

s32 func_ov000_0219fa0c(void) {
extern void *data_ov000_021df580;
M2C_FIELD(data_ov000_021df580, s8 *, 0) = 2;
M2C_FIELD(data_ov000_021df580, s8 *, 1) = 0;
return 0;
}

s32 func_ov000_0219fa30(void) {
s32 func_020d4774(void);
void func_ov000_021696f8(void *);
void func_020bac24(void);
extern s32 data_ov000_021e1468;
extern void *data_ov000_021df580;
if(func_020d4774()==0) {
if(M2C_FIELD(&data_ov000_021e1468,void **,4)) func_ov000_021696f8(M2C_FIELD(&data_ov000_021e1468,void **,4));
if(M2C_FIELD(&data_ov000_021e1468,void **,8)) func_ov000_021696f8(M2C_FIELD(&data_ov000_021e1468,void **,8));
func_020bac24();
M2C_FIELD(data_ov000_021df580,u8 *,0)=2;
M2C_FIELD(data_ov000_021df580,u8 *,1)=0;
}
return 0;
}

s32 func_ov000_0219fa98(void) {
extern void *data_ov000_021df580;
M2C_FIELD(data_ov000_021df580, s8 *, 0) = 2;
M2C_FIELD(data_ov000_021df580, s8 *, 1) = 0;
return 0;
}

void func_ov000_0219fabc(s32 n) {
extern u8 data_ov000_021df7d6[];
extern void *data_ov000_021e146c[];
extern void **gCurrentMap;
extern u16 data_ov000_021df58c[],data_ov000_021df584[];
extern s32 data_0215be0c;
void *func_ov000_021696b0(u16,u16,s32,u32,void *);
void func_020cad00(u32,s32,s32);
void func_020bb608(s32);
s32 state=data_ov000_021df7d6[n];
data_ov000_021e146c[n]=0;
if(state==5){
u8 *map=*gCurrentMap;
u8 *unit=M2C_FIELD(map,u8 **,0x52d0);
s32 index=(s16)unit[n+12]*14;
u8 *base=map+0x59a4;
s32 player=0;
if(unit) player=((unit-base)/14)>>6;
data_ov000_021e146c[n]=func_ov000_021696b0(M2C_FIELD(map,u16 *,0x52dc),M2C_FIELD(map,u16 *,0x52de),player+1,((UnitId6 *)(base+index))->id,data_ov000_021df58c);
}else if(state!=0){
u8 *map;u8 *unit;s32 index;u8 *base;s32 player=0;
data_0215be0c=state-1;
map=*gCurrentMap;unit=M2C_FIELD(map,u8 **,0x52d0);
index=(s16)unit[n+12]*14;base=map+0x59a4;
if(unit) player=((unit-base)/14)>>6;
data_ov000_021e146c[n]=func_ov000_021696b0(M2C_FIELD(map,u16 *,0x52dc),M2C_FIELD(map,u16 *,0x52de),player+1,((UnitId6 *)(base+index))->id,data_ov000_021df584+data_0215be0c);
func_020cad00(((UnitId6 *)(base+index))->id,M2C_FIELD(*gCurrentMap,s16 *,0x52dc),M2C_FIELD(*gCurrentMap,s16 *,0x52de));
func_020bb608(n);
}}

void func_ov000_0219fc64(void) {
void func_020cbf94(u32);
s32 func_020d19b4(u16);
M2C_UNK func_02091c20(M2C_UNK,M2C_UNK);
extern void **gCurrentMap;
void *p;
func_020cbf94(((UnitId6 *)M2C_FIELD(*gCurrentMap,void **,0x52D0))->id);
p=M2C_FIELD(*gCurrentMap,void **,0x52D0);
M2C_FIELD(p,u16 *,4)|=0x20;
if(func_020d19b4(M2C_FIELD(*gCurrentMap,u16 *,0x52A4))) func_02091c20(0x26,1);
}

void func_ov000_0219fcdc(void) {
void func_020cbfa4(u32);
s32 func_020d19b4(u16);
M2C_UNK func_02091c20(M2C_UNK,M2C_UNK);
extern void **gCurrentMap;
void *p;
func_020cbfa4(((UnitId6 *)M2C_FIELD(*gCurrentMap,void **,0x52D0))->id);
p=M2C_FIELD(*gCurrentMap,void **,0x52D0);
M2C_FIELD(p,u16 *,4)&=~0x20;
if(func_020d19b4(M2C_FIELD(*gCurrentMap,u16 *,0x52A4))) func_02091c20(0x25,1);
}

void func_ov000_0219fd54(void) {
    M2C_UNK func_02091c20(M2C_UNK, M2C_UNK);
    M2C_UNK func_020b576c(s32);
    s32 func_020d19b4(u16);
    s32 func_ov000_0216aa44(M2C_UNK, s32);
    extern void **gCurrentMap;
    if (func_ov000_0216aa44(0x31, M2C_FIELD(*gCurrentMap, s32 *, 0x52D0)) != 0) {
        return;
    }
    func_020b576c(M2C_FIELD(*gCurrentMap, s32 *, 0x52D0));
    if (func_020d19b4(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) == 0) {
        return;
    }
    func_02091c20(0x11, 1);
}

void func_ov000_021a01c0(void) {
extern u8 *data_ov000_021df578;
extern u8 data_ov000_021dfd94[];
u8 *q=data_ov000_021df578;
s32 i;
u8 *p=data_ov000_021dfd94;
for(i=0;i<q[1];i++,p+=8) p[1]=0;
}

void func_ov000_021a0204(void) {
    extern u8 *data_ov000_021df578;
    extern u8 data_ov000_021e00ac;
    u8 *count;
    s32 i;
    u8 *p;
    u8 value;
    count = data_ov000_021df578;
    p = &data_ov000_021e00ac;
    i = 0;
    if ((s32)*count <= 0) return;
    do {
        value = p[3];
        i++;
        if ((u32)value >= 0xFD) p[3] = 0x7F;
        p += 12;
    } while (i < (s32)*count);
}

void func_ov000_021a0250(void) {
    extern u8 *data_ov000_021df578;
    extern u8 data_ov000_021e00ac;
    u8 *count;
    s32 i;
    u8 *p;
    u8 value;
    count = data_ov000_021df578;
    p = &data_ov000_021e00ac;
    i = 0;
    if ((s32)*count <= 0) return;
    do {
        value = p[3];
        i++;
        if ((u32)value > 0xFD) p[3] = 0x7F;
        p += 12;
    } while (i < (s32)*count);
}

void func_ov000_021a029c(void) {
    void func_ov000_021a0204(void);
    void func_ov000_021a01c0(void);
    func_ov000_021a01c0();
    func_ov000_021a0204();
}
