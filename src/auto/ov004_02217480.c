/* 5 functions from 0x02217480 to 0x02217F5C (ov004), found by ds-decomp. */
#include "common.h"
extern u32 data_0215d8a8[];
typedef struct Flags175 { u32 low:3; u32 middle:23; u32 previous:3; u32 current:3; } Flags175;
extern u8 data_ov004_0223c678[], data_ov004_0223c63c[];
static inline void *Entry175(void *base, s32 i) { if(i<0)return 0; if(i>=64)return 0; return (u8 *)base+i*32; }
static inline u8 Flag175(void *p,u32 mask) { return (M2C_FIELD(p,u8 *,4)&mask)?1:0; }
static inline u8 Available175(void *p) { return Flag175(p,4)?0:1; }
static inline void *Child175(void *p) { void *q; s32 i; for(i=0;i<4;i++){q=M2C_FIELD((u8 *)p+i*4,void **,16);if(q && Available175(q))return q;}return 0; }
static inline void *Selected175(void *base) { void *q;u8 *cursor=base;s32 i;for(i=0;i<64;i++,cursor+=32){if(i<0)q=0;else if(i>=64)q=0;else q=cursor;if(Flag175(q,2))return q;}return 0; }

/* Updates the zoom state: toggles between 1.0 (0x1000) and 0.5 (0x800) scale,
   recomputes the clipped target position, and clamps the source rectangle. */
void func_ov004_02217480(void *state) {
void func_01ffa8c4(void *, s32);
void *entry; s32 i, offset; void *base; u32 flags; s16 x,y;
i=0;
M2C_FIELD(state,u8 *,0x36)=0;
M2C_FIELD(state,u8 *,0x35)=0;
base=M2C_FIELD(state,void **,0x5c);
offset=0;
do {
if(i<0) entry=0; else if(i>=64) entry=0; else entry=base+offset;
flags=data_0215d8a8[M2C_FIELD(entry,u8 *,7)];
if((flags>>29)!=((flags<<3)>>29)){
M2C_FIELD(state,u8 *,0x37)=i;
if(entry==0)return;
y=M2C_FIELD(entry,s16 *,2); x=M2C_FIELD(entry,s16 *,0);
M2C_FIELD(state,s16 *,0x48)=x;M2C_FIELD(state,s16 *,0x4a)=y;
return;
}
i++;offset+=32;
}while(i<64);
func_01ffa8c4(state,1);
}

#pragma opt_strength_reduction off
void func_ov004_02217514(void *state) {
void *func_0208c54c(void *);
void func_0208bd2c(void *,void *,s32,s32,s32);
s32 func_02001fb4(s32,s32);
M2C_UNK func_0208fe30(s32);
u8 func_0207ca38(M2C_UNK,s16,s16,u8,s32);
void func_020ceb48(void);void func_020cf278(s32);void func_020cf0a8(s32);void func_ov003_021ff36c(void);
s32 func_020a8958(s32);void func_01ffa8c4(void *,s32);M2C_UNK func_01ffa6fc(void *);
s32 i,value,id,ok; void *entry,*sprite,*q,*base; u32 old;u8 selected;s16 x,y;u8 *cursor;
entry=Entry175(M2C_FIELD(state,void **,0x5c),M2C_FIELD(state,u8 *,0x37));
switch(M2C_FIELD(state,u8 *,0x35)){
case 0:
sprite=func_0208c54c(state);func_0208bd2c(sprite,data_ov004_0223c678,0x3a800,25,1);
y=M2C_FIELD(entry,s16 *,2);x=M2C_FIELD(entry,s16 *,0);
M2C_FIELD(sprite,s32 *,0x34)=x;M2C_FIELD(sprite,s32 *,0x38)=y;
M2C_FIELD(sprite,s32 *,0x3c)=9;
M2C_FIELD(sprite,s32 *,0x40)=func_02001fb4(4096,M2C_FIELD(state,s32 *,0x40));
func_0208fe30(238);M2C_FIELD(state,u8 *,0x35)=1;return;
case 1:
sprite=func_0208c54c(state);func_0208bd2c(sprite,data_ov004_0223c63c,0x3a800,25,1);
y=M2C_FIELD(entry,s16 *,2);x=M2C_FIELD(entry,s16 *,0);
M2C_FIELD(sprite,s32 *,0x34)=x;M2C_FIELD(sprite,s32 *,0x38)=y;
M2C_FIELD(sprite,s32 *,0x3c)=9;
M2C_FIELD(sprite,s32 *,0x40)=func_02001fb4(4096,M2C_FIELD(state,s32 *,0x40));
M2C_FIELD(sprite,u32 *,0x44)=(M2C_FIELD(sprite,u32 *,0x44)&~0x3000000)|0x2000000;
M2C_FIELD(entry,u8 *,5)=data_0215d8a8[M2C_FIELD(entry,u8 *,7)]>>29;
M2C_FIELD(state,u8 *,0x36)=0;M2C_FIELD(state,u8 *,0x35)=2;return;
case 2: { s32 i;
M2C_FIELD(state,u8 *,0x35)=5;
for(i=0;i<4;i++){q=M2C_FIELD((u8 *)entry+i*4,void **,16);if(q && !Flag175(q,1)){
M2C_FIELD(q,u8 *,4)|=1;M2C_FIELD(q,s32 *,8)=0;
if(Available175(q))M2C_FIELD(entry,s32 *,12)=0;
M2C_FIELD(state,u8 *,0x35)=3;}}return;}
case 3:
if(M2C_FIELD(state,u8 *,0x36)==0)func_0208fe30(239);
M2C_FIELD(state,u8 *,0x36)++;
value=func_0207ca38(4,0,4096,M2C_FIELD(state,u8 *,0x36),16);
for(i=0;i<4;i++){q=M2C_FIELD((u8 *)entry+i*4,void **,16);if(q && M2C_FIELD(q,s32 *,8)!=4096)M2C_FIELD(q,s32 *,8)=value;}
if(M2C_FIELD(state,u8 *,0x36)!=16)return;
M2C_FIELD(state,u8 *,0x36)=0;q=Child175(entry);
if(q && M2C_FIELD(entry,s32 *,12)==0)M2C_FIELD(state,u8 *,0x35)=4;else M2C_FIELD(state,u8 *,0x35)=5;return;
case 4:
M2C_FIELD(state,u8 *,0x36)++;
value=func_0207ca38(0,0,4096,M2C_FIELD(state,u8 *,0x36),16);
if(M2C_FIELD(entry,s32 *,12)!=4096)M2C_FIELD(entry,s32 *,12)=value;
if(M2C_FIELD(state,u8 *,0x36)!=16)return;
q=Child175(entry);base=M2C_FIELD(state,void **,0x5c);
if(q && q!=Selected175(base) && Flag175(q,1)){
for(i=0,cursor=base;i<64;i++,cursor+=32){void *p;if(i<0)p=0;else if(i>=64)p=0;else p=cursor;M2C_FIELD(p,u8 *,4)&=~2;}
M2C_FIELD(q,u8 *,4)|=2;ok=1;
}else ok=0;
if(ok){
if(q){y=M2C_FIELD(q,s16 *,2);x=M2C_FIELD(q,s16 *,0);M2C_FIELD(state,s16 *,0x48)=x;M2C_FIELD(state,s16 *,0x4a)=y;}
q=Selected175(M2C_FIELD(state,void **,0x5c));
if(q){func_020ceb48();func_020cf278(M2C_FIELD(q,u8 *,7)+161);func_020cf0a8(M2C_FIELD(q,u8 *,7)+161);func_ov003_021ff36c();}
M2C_FIELD(state,s16 *,0x4c)=0;M2C_FIELD(state,s16 *,0x4e)=0;func_0208fe30(240);
}
M2C_FIELD(state,u8 *,0x36)=0;M2C_FIELD(state,u8 *,0x35)=5;return;
case 5:
old=(data_0215d8a8[M2C_FIELD(entry,u8 *,7)]<<3)>>29;
for(i=0;i<4;i++){q=M2C_FIELD((u8 *)entry+i*4,void **,16);if(q && (((Flags175 *)data_0215d8a8)[M2C_FIELD(q,u8 *,7)].low)==0){
data_0215d8a8[M2C_FIELD(q,u8 *,7)]=(data_0215d8a8[M2C_FIELD(q,u8 *,7)]&~7)|1;
id=M2C_FIELD(q,u8 *,7);value=func_020a8958(id+161);selected=Flag175(q,2);
M2C_FIELD(q,u8 *,4)=0;
if(value==2)M2C_FIELD(q,u8 *,4)|=4;
if((((Flags175 *)data_0215d8a8)[id].low)!=0)M2C_FIELD(q,u8 *,4)|=1;
if((((Flags175 *)data_0215d8a8)[id].low)==1)M2C_FIELD(q,u8 *,4)|=16;
if((((Flags175 *)data_0215d8a8)[id].low)==3)M2C_FIELD(q,u8 *,4)|=8;
if(selected)M2C_FIELD(q,u8 *,4)|=2;
M2C_FIELD(q,u8 *,5)=(data_0215d8a8[id]<<3)>>29;
}}
id=M2C_FIELD(entry,u8 *,7);
((Flags175 *)data_0215d8a8)[id].previous=((Flags175 *)data_0215d8a8)[id].current;
if(M2C_FIELD(entry,u8 *,7)+161==186 && old==0)func_0208fe30(286);
func_01ffa8c4(state,3);return;
default:func_01ffa6fc(state);return;
}
}
#pragma opt_strength_reduction reset
void func_ov004_02217bb8(void *state) {
    s32 func_0207c8ec(s32, M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    s32 scale;
    s32 scale2;
    s32 savedScale;

    M2C_FIELD(state, s8 *, 0x36) = 0;
    savedScale = M2C_FIELD(state, s32 *, 0x40);
    M2C_FIELD(state, s16 *, 0x54) = (s16) M2C_FIELD(state, s16 *, 0x50);
    M2C_FIELD(state, s16 *, 0x56) = (s16) M2C_FIELD(state, s16 *, 0x52);
    if (M2C_FIELD(state, s32 *, 0x40) == 0x1000) {
        M2C_FIELD(state, s8 *, 0x3A) = 1;
        M2C_FIELD(state, s32 *, 0x40) = 0x800;
        func_0208fe30(0x1001F);
    } else {
        M2C_FIELD(state, s8 *, 0x3A) = -1;
        M2C_FIELD(state, s32 *, 0x40) = 0x1000;
        M2C_FIELD(state, s16 *, 0x44) = (s16) M2C_FIELD(state, s16 *, 0x48);
        M2C_FIELD(state, s16 *, 0x46) = (s16) M2C_FIELD(state, s16 *, 0x4A);
        func_0208fe30(0x1001E);
    }
    scale = M2C_FIELD(state, s32 *, 0x40);
    if ((scale != 0x800) && (scale != 0x1000)) {

    } else {
        if ((s32) M2C_FIELD(state, s16 *, 0x50) < (s32) (0x60 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x44) * scale, 0x1000))) {
            M2C_FIELD(state, s16 *, 0x50) = (s16) (0x60 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x44) * M2C_FIELD(state, s32 *, 0x40), 0x1000));
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x52) < (s32) (0x39 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x46) * M2C_FIELD(state, s32 *, 0x40), 0x1000))) {
            M2C_FIELD(state, s16 *, 0x52) = (s16) (0x39 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x46) * M2C_FIELD(state, s32 *, 0x40), 0x1000));
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x50) > (s32) (0xA0 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x44) * M2C_FIELD(state, s32 *, 0x40), 0x1000))) {
            M2C_FIELD(state, s16 *, 0x50) = (s16) (0xA0 - func_0207c8ec(M2C_FIELD(state, s16 *, 0x44) * M2C_FIELD(state, s32 *, 0x40), 0x1000));
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x52) > (s32) (0x5F - func_0207c8ec(M2C_FIELD(state, s16 *, 0x46) * M2C_FIELD(state, s32 *, 0x40), 0x1000))) {
            M2C_FIELD(state, s16 *, 0x52) = (s16) (0x5F - func_0207c8ec(M2C_FIELD(state, s16 *, 0x46) * M2C_FIELD(state, s32 *, 0x40), 0x1000));
        }
    }
    scale2 = M2C_FIELD(state, s32 *, 0x40);
    if ((scale2 != 0x800) && (scale2 != 0x1000)) {

    } else {
        if ((s32) M2C_FIELD(state, s16 *, 0x44) < 0) {
            M2C_FIELD(state, s16 *, 0x44) = 0;
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x46) < 0) {
            M2C_FIELD(state, s16 *, 0x46) = 0;
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x44) > 0x200) {
            M2C_FIELD(state, s16 *, 0x44) = 0x200;
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x46) > 0x130) {
            M2C_FIELD(state, s16 *, 0x46) = 0x130;
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x50) < (s32) (0x100 - func_0207c8ec(M2C_FIELD(state, s32 *, 0x40) << 9, 0x1000))) {
            M2C_FIELD(state, s16 *, 0x50) = (s16) (0x100 - func_0207c8ec(M2C_FIELD(state, s32 *, 0x40) << 9, 0x1000));
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x52) < (s32) (0xC0 - func_0207c8ec(M2C_FIELD(state, s32 *, 0x40) * 0x158, 0x1000))) {
            M2C_FIELD(state, s16 *, 0x52) = (s16) (0xC0 - func_0207c8ec(M2C_FIELD(state, s32 *, 0x40) * 0x158, 0x1000));
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x50) > 0) {
            M2C_FIELD(state, s16 *, 0x50) = 0;
        }
        if ((s32) M2C_FIELD(state, s16 *, 0x52) > 0) {
            M2C_FIELD(state, s16 *, 0x52) = 0;
        }
    }
    M2C_FIELD(state, s16 *, 0x58) = (s16) M2C_FIELD(state, s16 *, 0x50);
    M2C_FIELD(state, s16 *, 0x5A) = (s16) M2C_FIELD(state, s16 *, 0x52);
    M2C_FIELD(state, s16 *, 0x50) = (s16) M2C_FIELD(state, s16 *, 0x54);
    M2C_FIELD(state, s16 *, 0x52) = (s16) M2C_FIELD(state, s16 *, 0x56);
    M2C_FIELD(state, s32 *, 0x40) = savedScale;
}

/* Advances the zoom/pan interpolation one step and finalizes the transition. */
void func_ov004_02217e50(void *state) {
    M2C_UNK func_01ffa6fc(void *);
    u8 func_0207ca38(M2C_UNK, s16, s16, u8, s32);
    u8 step;

    M2C_FIELD(state, u8 *, 0x36) = (u8) (M2C_FIELD(state, u8 *, 0x36) + 1);
    step = func_0207ca38(4, 0, 0x3E8, M2C_FIELD(state, u8 *, 0x36), 0x10);
    if ((s32) M2C_FIELD(state, s8 *, 0x3A) > 0) {
        M2C_FIELD(state, s32 *, 0x40) = (s32) func_0207ca38(0, 0x1000, 0x800, step, 0x3E8);
    }
    if ((s32) M2C_FIELD(state, s8 *, 0x3A) < 0) {
        M2C_FIELD(state, s32 *, 0x40) = (s32) func_0207ca38(0, 0x800, 0x1000, step, 0x3E8);
    }
    M2C_FIELD(state, s16 *, 0x50) = (s16) func_0207ca38(0, M2C_FIELD(state, s16 *, 0x54), M2C_FIELD(state, s16 *, 0x58), step, 0x3E8);
    M2C_FIELD(state, s16 *, 0x52) = (s16) func_0207ca38(0, M2C_FIELD(state, s16 *, 0x56), M2C_FIELD(state, s16 *, 0x5A), step, 0x3E8);
    if ((s32) M2C_FIELD(state, u8 *, 0x36) < 0x10) {
        return;
    }
    func_01ffa6fc(state);
}

void func_ov004_02217f34(void) {
    M2C_UNK func_0209cd00(M2C_UNK *);
    M2C_UNK func_020ab200();
    M2C_UNK func_ov003_021ff3ac();
    extern M2C_UNK func_ov004_022148a4;
    extern M2C_UNK func_ov004_02214904;
    func_ov003_021ff3ac();
    func_020ab200();
    func_0209cd00(&func_ov004_022148a4);
    func_0209cd00(&func_ov004_02214904);
}
