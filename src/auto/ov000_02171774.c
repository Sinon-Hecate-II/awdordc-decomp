/* 22 functions from 0x02171774 to 0x02172754 (ov000), found by ds-decomp. */
#include "common.h"
static inline void InitEntry724dc(void *q) {
s32 j;void *t;
M2C_FIELD(q,s32 *,0)=0; M2C_FIELD(q,s32 *,4)=0; M2C_FIELD(q,s32 *,8)=0; M2C_FIELD(q,s32 *,12)=0;
M2C_FIELD(q,s32 *,0x28)=1; M2C_FIELD(q,s32 *,0x2c)=0;
M2C_FIELD(q,u8 *,0x30)=0; M2C_FIELD(q,u8 *,0x31)=0; M2C_FIELD(q,u8 *,0x33)=0;
j=0; M2C_FIELD(q,u8 *,0x34)=0;
inner: t=(u8*)q+(j<<2); j++; M2C_FIELD(t,s32 *,0x10)=0; if(j<6) goto inner;

}

void func_ov000_02171774(void *p) {
#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma scheduling off
 extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;extern void **gCurrentMap;
 extern u8 data_ov000_021b8d60[],data_ov000_021b8d68[],data_ov000_021b8d7c[],data_ov000_021b8d8c[],data_ov000_021b8d9c[],data_ov000_021b8dac[],data_ov000_021b8db4[],data_ov000_021b8dc4[],data_ov000_021b8dd4[],data_ov000_021b8de4[];
 void *func_020e3218(void*);void *func_ov000_0216ce10(s32);void *func_ov000_0216ce84(s32);
 void func_0200bc5c(void*);void func_020814e4(void*);void func_02081590(void*,void*);void func_020815fc(void*,s32,s32);void func_02081528(void);
 s32 func_01ff9c34(u8,s32);void func_01ff85b8(void*,u16,s32);
 s32 func_020d1980(s32);s32 func_020d1938(s32);void func_02080a14(void*,s32,s32,void*);
 void func_02007ef4(void*,void*,s32);void func_01ff9e44(void*,s32,s32);void func_020ae528(void*);
 void func_020a9a30(s32,s32,s32,void*);void func_02080cfc(void*,void*);void func_0208116c(void*,s32,s32);void func_020c0fac(void*);
 void *old=gCur3DSpriteEngine;
 s32 k;void *object=p;s32 i,idx,a,b,pal,t;void *dst;
 gCur3DSpriteEngine=g3DSpriteEngineMain;
 func_0200bc5c(data_ov000_021b8d60);
 func_020814e4(func_020e3218(data_ov000_021b8d68));
 func_02081590(func_020e3218(data_ov000_021b8d7c),M2C_FIELD(gCur3DSpriteEngine,void**,0x14));
 func_02081590(func_020e3218(data_ov000_021b8d8c),M2C_FIELD(gCur3DSpriteEngine,void* volatile *,0x28));
 func_020815fc(func_020e3218(data_ov000_021b8d9c),96,32);
 func_02081528();
 {u16 v=func_01ff9c34((u8)((u32)(M2C_FIELD(*(void**)gCur3DSpriteEngine,u16*,0)<<29)>>29),2);
 func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,void* volatile *,0x28),v,0x3000);}
 i=1;k=140;do{
  if(func_020d1980(i)){
   a=M2C_FIELD((u8*)*gCurrentMap+k,u8*,0x67cb);
   b=M2C_FIELD((u8*)*gCurrentMap+k,u8*,0x67c1);
   idx=i-1;t=idx<<3;
   func_02080a14((u8*)M2C_FIELD(gCur3DSpriteEngine,void* volatile *,0x28)+(t<<1)+0x80,8,6,(u8*)M2C_FIELD(gCur3DSpriteEngine,void* volatile *,0x28)+(t<<1)+0x680);
   dst=(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+((idx*4+0x35c)<<5);
   func_02007ef4(func_ov000_0216ce10(a),dst,0x80);
   pal=(idx+0x1b)<<5;
   func_01ff9e44(func_ov000_0216ce84(b),pal,32);
   if(func_020d1938(i))M2C_FIELD((u8*)object+i,u8*,0x34)=1;
   else{M2C_FIELD((u8*)object+i,u8*,0x34)=0;func_020ae528((u8*)M2C_FIELD(gCur3DSpriteEngine,void* volatile *,0x30)+(pal&~1));}
  }
 i++;k+=140;}while(i<5);
 M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=4;
 func_020a9a30(1,0,3,(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x6d80);
 func_020a9a30(1,2,0,(u8*)M2C_FIELD(gCur3DSpriteEngine,void* volatile *,0x30)+0x3e0);
 func_0200bc5c(data_ov000_021b8dac);
 func_02080cfc(func_020e3218(data_ov000_021b8db4),(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x7400);
 func_02080cfc(func_020e3218(data_ov000_021b8dc4),(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x7e00);
 func_02080cfc(func_020e3218(data_ov000_021b8dd4),(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0x1c)+0x8600);
 func_0208116c(data_ov000_021b8de4,0x340,32);
 dst=(u8*)M2C_FIELD(gCur3DSpriteEngine,void* volatile *,0x30)+0x240;
 func_02007ef4((u8*)M2C_FIELD(gCur3DSpriteEngine,void* volatile *,0x30)+0x340,dst,32);
 func_020ae528((u8*)M2C_FIELD(gCur3DSpriteEngine,void* volatile *,0x30)+0x240);
 func_020c0fac(object);gCur3DSpriteEngine=old;
}

#pragma opt_strength_reduction off
void func_ov000_02171a68(void *arg0) {
s32 func_020d1980(s32); s32 func_020d19e8(s32); s32 func_ov000_02171768(s32);
void func_020a947c(void *,u32); void func_020a92bc(void *,s32); void func_020a94fc(void *);
void AddSprite(u16,u8,u16,void *,s32);
extern void *g3DSpriteEngineMain,*gCur3DSpriteEngine; extern void **gCurrentMap;
extern u8 data_02129870[],data_027e0064[],data_02101f1c[],data_02168f14[];
u8 sp[44]; void *saved; s32 i,idx,unit,pal,tile,k; s32 one;
M2C_FIELD(sp,u8 *,32)=(u8)((u8)(sp[32]&~1)&~30);
sp[32]=(sp[32]&~224)|64;

saved=gCur3DSpriteEngine; gCur3DSpriteEngine=g3DSpriteEngineMain;
M2C_FIELD(sp,void **,0)=data_02129870;sp[4]=0;
M2C_FIELD(sp,u16 *,18)=0;sp[20]=8;sp[21]=8;sp[22]=1;one=1;sp[23]=8;sp[24]=8;
sp[33]=0;M2C_FIELD(sp,s32 *,36)=0;sp[40]&=~224;sp[41]=0;
func_020a947c(sp,3);M2C_FIELD(sp,u16 *,18)=0x36c;sp[33]=15;sp[32]=(sp[32]&~224)|32;
for(i=one,k=0x8c;i<5;k+=0x8c,i++){ if(func_020d1980(i)){
idx=i-1;unit=M2C_FIELD((u8*)*gCurrentMap+k+0x6000,u8 *,0x7ca)-1;
AddSprite((u16)(idx*64+5),23,(u16)((0x3ff&((idx*4+0x35c)>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(u16)((idx+11)<<12)),data_027e0064,11);
pal=M2C_FIELD((u8*)arg0+i,u8 *,0x34)?10:2;
if(!func_020d19e8(i)) tile=idx*16+0x3a0; else tile=0x3e0;
AddSprite((u16)(idx*64+4),23,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(u16)(pal<<12)),data_02101f1c,11);
AddSprite((u16)(idx*64),40,(u16)((0x3ff&((unit*16+0x3f0)>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(u16)(pal<<12)),data_02101f1c,11);
}}
if(M2C_FIELD(*gCurrentMap,u8 *,0x5156)){tile=func_ov000_02171768(0);AddSprite(0,104,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);}else{tile=func_ov000_02171768(1);AddSprite(0,104,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);}if(M2C_FIELD(*gCurrentMap,u8 *,0x5159)==1){tile=func_ov000_02171768(10);AddSprite(64,104,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);}else switch(M2C_FIELD(*gCurrentMap,u8 *,0x515b)){case 0: tile=func_ov000_02171768(6);AddSprite(64,104,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;case 1: tile=func_ov000_02171768(8);AddSprite(64,104,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;case 2: tile=func_ov000_02171768(7);AddSprite(64,104,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;case 3: tile=func_ov000_02171768(9);AddSprite(64,104,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;}switch(M2C_FIELD(*gCurrentMap,u8 *,0x5157)){case 1: tile=func_ov000_02171768(4);AddSprite(128,104,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;case 2: tile=func_ov000_02171768(5);AddSprite(128,104,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;case 3: tile=func_ov000_02171768(3);AddSprite(128,104,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;default:tile=func_ov000_02171768(2);AddSprite(128,104,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;}func_020a92bc(sp,data_02168f14[3]);M2C_FIELD(sp,s16 *,6)=224;M2C_FIELD(sp,s16 *,8)=104;
if(!data_02168f14[3]){sp[32]=((u8)((sp[32]&~1)|1)&~30)|20;func_020a94fc(sp);sp[32]&=~1;}else func_020a94fc(sp);
func_020a92bc(sp,M2C_FIELD(data_02168f14,s32 *,8));M2C_FIELD(sp,s16 *,6)=32;M2C_FIELD(sp,s16 *,8)=144;func_020a94fc(sp);
func_020a92bc(sp,M2C_FIELD(data_02168f14,u16 *,6));M2C_FIELD(sp,s16 *,6)=96;M2C_FIELD(sp,s16 *,8)=144;func_020a94fc(sp);
switch((u32)(M2C_FIELD(data_02168f14,u16 *,0)<<26)>>29){case 0:tile=func_ov000_02171768(11);AddSprite(128,144,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;case 1:tile=func_ov000_02171768(12);AddSprite(128,144,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;case 2:tile=func_ov000_02171768(13);AddSprite(128,144,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;case 3:tile=func_ov000_02171768(14);AddSprite(128,144,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);break;}if((u32)(M2C_FIELD(data_02168f14,u16 *,0)<<23)>>31){tile=func_ov000_02171768(0);AddSprite(192,144,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);}else{tile=func_ov000_02171768(1);AddSprite(192,144,(u16)((0x3ff&(tile>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xa000),data_02101f1c,11);}gCur3DSpriteEngine=saved;}
#pragma opt_strength_reduction reset
void func_ov000_021723bc(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(1);
    func_01ff9ce8(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    func_0208fe30(0x10018);
}

void func_ov000_02172408(s32 arg0) {
    M2C_UNK func_01ffa6fc(s32);
    extern u16 *data_02101e84;
    if (!(*data_02101e84 & 2)) return;
    func_01ffa6fc(arg0);
}

void func_ov000_0217242c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8d18;
    func_01ffa3dc(&data_ov000_021b8d18, 7);
}

void func_ov000_02172444(void) {

}

void func_ov000_02172448(void) {

}

M2C_UNK *func_ov000_0217244c(void) {
    extern M2C_UNK data_ov000_021df5ec;
    return &data_ov000_021df5ec;
}

s32 func_ov000_02172458(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add1c[];
    return M2C_FIELD(data_ov000_021add1c, s32 *, arg1 << 5);
}

s32 func_ov000_02172468(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add20[];
    return M2C_FIELD(data_ov000_021add20, s32 *, arg1 << 5);
}

s32 func_ov000_02172478(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add24[];
    return M2C_FIELD(data_ov000_021add24, s32 *, arg1 << 5);
}

s32 func_ov000_02172488(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add28[];
    return M2C_FIELD(data_ov000_021add28, s32 *, arg1 << 5);
}

s32 func_ov000_02172498(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add2c[];
    return M2C_FIELD(data_ov000_021add2c, s32 *, arg1 << 5);
}

s32 func_ov000_021724a8(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add30[];
    return M2C_FIELD(data_ov000_021add30, s32 *, arg1 << 5);
}

s16 func_ov000_021724b8(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add34[];
    return M2C_FIELD(data_ov000_021add34, s16 *, arg1 << 5);
}

s32 func_ov000_021724cc(void *arg0, s32 arg1) {
    extern u8 data_ov000_021add38[];
    return M2C_FIELD(data_ov000_021add38, s32 *, arg1 << 5);
}

#pragma opt_strength_reduction off
void *func_ov000_021724dc(void *arg0) {
void *MemAlloc(s32);
s32 i,j,k; void *p,*q,*t;
M2C_FIELD(arg0,s32 *,0)=0; M2C_FIELD(arg0,s32 *,4)=0;
M2C_FIELD(arg0,s32 *,12)=0; M2C_FIELD(arg0,s32 *,16)=0; M2C_FIELD(arg0,u8 *,20)=0;
p=MemAlloc(0x11c);
if(p){
M2C_FIELD(p,s32 *,0)=1; M2C_FIELD(p,s32 *,4)=0; M2C_FIELD(p,s32 *,8)=0; i=0;
q=(u8*)p+0x3c;
do {
InitEntry724dc(q);
q=(u8*)q+0x38;
}while((u32)q<(u32)((u8*)p+0x11c));
loop1:t=(u8*)p+(i<<2);i++;M2C_FIELD(t,s32 *,12)=9;if(i<4)goto loop1;
k=0;loop2:t=(u8*)p+(k<<2);k++;M2C_FIELD(t,s32 *,0x1c)=0;if(k<8)goto loop2;
}
M2C_FIELD(arg0,void **,0x18)=p;func_ov000_02172754(arg0);return arg0;
}
#pragma opt_strength_reduction reset

void *func_ov000_021725c8(void *arg0) {
    M2C_UNK MemFree(s32);
    MemFree(M2C_FIELD(arg0, s32 *, 0x18));
    return arg0;
}

void func_ov000_021725e0(void *arg0) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    func_01ff9ce8(2);
    func_01ff9ce8(1);
    func_01ff9ce8(0);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(arg0, s32 *, 4) = 2;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_02172648(void) {
    M2C_UNK func_020c127c();
    func_020c127c();
}

/* Update an entry's state machine: handle pending states, refresh data, re-evaluate readiness. */
void func_ov000_02172654(void *entry) {
    extern void *g3DSpriteEngineSub;
    switch (M2C_FIELD(entry, s32 *, 4)) {
    case 0:
        break;
    case 1:
        func_020c127c(entry);
        func_020809c0(M2C_FIELD(g3DSpriteEngineSub, void **, 0x24), 32, 32);
        func_ov000_02173290(entry);
        func_ov000_021732c0(entry);
        M2C_FIELD(entry, s32 *, 8) = 0;
        M2C_FIELD(entry, s32 *, 12) = 0;
        M2C_FIELD(entry, s32 *, 4) = 0;
        break;
    case 2:
        func_ov000_02173290(entry);
        func_ov000_021732c0(entry);
        M2C_FIELD(entry, s32 *, 8) = 0;
        M2C_FIELD(entry, s32 *, 12) = 0;
        M2C_FIELD(entry, s32 *, 4) = 0;
        break;
    }
    func_ov000_02173468(entry);
    if (!func_ov000_02172468(func_ov000_0217244c(), *M2C_FIELD(entry, s32 **, 0x18))
        && !M2C_FIELD(entry, u8 *, 0x15)) {
        func_ov000_02172dc0(entry);
    }
    func_ov000_02172e90(entry);
    if (func_ov000_02172754(entry)) {
        M2C_FIELD(entry, s32 *, 4) = 1;
    }
}

void func_ov000_0217272c(void *arg0, s32 arg1) {
    M2C_UNK func_ov000_02172754(void *);
    *M2C_FIELD(arg0, s32 **, 0x18) = arg1;
    func_ov000_02172754(arg0);
    if (M2C_FIELD(arg0, s32 *, 4) == 0) {
        M2C_FIELD(arg0, s32 *, 4) = 1;
    }
}

