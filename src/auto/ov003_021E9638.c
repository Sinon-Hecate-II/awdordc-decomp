/* 28 functions from 0x021E9638 to 0x021EA57C (ov003), found by ds-decomp. */
#include "common.h"
typedef struct {u8 pad[0x14];void *sprites[12];void *labels[12];void *last;void *main;} SpriteGroup9638;
static inline u8 E9638Mode(void *p, u32 n) { return ((u32)(M2C_FIELD(p,u8*,0x39)<<24)>>28)==n; }
static inline u8 E9638Toggle(void *p) { return ((u32)(M2C_FIELD(p,volatile u8*,0x3a)<<30)>>31)==0; }
static inline u8 E9638IsFF(u8 v) { return v==255; }
static inline u8 E9638Value(void *p) { return M2C_FIELD(p,s32*,0x18); }
#include "coordinate_bits.h"

void func_ov003_021e9638(SpriteGroup9638 *self,void *arg) {
extern void *gCur3DSpriteEngine,*data_027e00c4,*data_027e00c8;extern u8 data_ov003_0220f896[];
void *func_020993d4(void *);void *func_0208931c(void *);void func_020990d4(void *,s32,u16);void func_020991f4(void *,s32);void func_02088da8(void *);s32 func_02098588(s32);void func_020990fc(void *,s32,s32,s32);
void *old=gCur3DSpriteEngine;s32 i;
gCur3DSpriteEngine=data_027e00c4;
self->main=func_020993d4(arg);
func_020990d4(self->main,0x4400,1);
func_020991f4(self->main,1);
M2C_FIELD(self->main,u16 *,0x3c)=0x400;
func_02088da8(self->main);
gCur3DSpriteEngine=data_027e00c8;
for(i=0;i<12;i++){
self->sprites[i]=func_020993d4(arg);
func_020990d4(self->sprites[i],0x5c00+i*2*func_02098588(0),(u16)i);
func_020990fc(self->sprites[i],i+1,0,0);
func_020991f4(self->sprites[i],1);
M2C_FIELD(self->sprites[i],u16 *,0x3c)=0x400;
func_02088da8(self->sprites[i]);
self->labels[i]=func_0208931c(arg);
M2C_FIELD(self->labels[i],void **,0x44)=data_ov003_0220f896;
M2C_FIELD(self->labels[i],u16 *,0x3e)=0x540;
M2C_FIELD(self->labels[i],u16 *,0x3c)=0x800;
func_02088da8(self->labels[i]);
}
self->last=func_0208931c(arg);
M2C_FIELD(self->last,void **,0x44)=data_ov003_0220f896;
M2C_FIELD(self->last,u16 *,0x3e)=0x560;
M2C_FIELD(self->last,u16 *,0x3c)=0x800;
func_02088da8(self->last);
gCur3DSpriteEngine=old;
}

void func_ov003_021e97bc(void *p,s16 x,s16 y,s32 a,s32 b) { E9638Set(p,x,y,a,b); }

void func_ov003_021e97fc(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x58) = arg1;
}

void func_ov003_021e9804(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x59) = 0;
}

void func_ov003_021e9810(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x3E) = arg1;
}

void func_ov003_021e9818(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg1 << 0x18) >> 6));
}

void func_ov003_021e9830(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xE) = arg1;
    M2C_FIELD(arg0, s16 *, 0x10) = arg1;
    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 4);
}

u32 func_ov003_021e984c(void *arg0, u8 arg1) {
    void func_02088d94(void *);
    void func_02088da8(void *);
    s32 func_02088f1c(s32);
    s32 func_02088ff4(s32);
    u32 func_0208b758(s32, s32);
    s16 func_020a8ff4(void *);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    u32 func_ov003_021e6cac(u8, M2C_UNK, M2C_UNK);
    s32 func_ov003_021e6d28();
    M2C_UNK func_ov003_021e74ac(void *, u8);
    s16 func_ov003_022004a8(u8);
    s32 func_020846a4();
    s8 *temp_r4;
    s8 *temp_r4_5;
    s32 temp_r3;
    s32 temp_r4_9;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r1;
    u16 temp_r0_3;
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r0_4;
    u32 var_r0;
    u32 var_r8;
    u8 temp_r1;
    s8 temp_r7;
    u8 var_r7;
    void *temp_r1_2;
    void *temp_r4_2;
    void *temp_r4_3;
    void *temp_r4_4;
    void *temp_r4_6;
    void *temp_r4_7;
    void *temp_r4_8;
    void *temp_r5;

    temp_r1 = (M2C_FIELD(arg0, u8 *, 0x39) & ~0xC) | (((u8)(arg1 & 0xFF) << 0x1E) >> 0x1C);
    if (((u32) (temp_r1 << 0x1C) >> 0x1E) == 0) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    M2C_FIELD(arg0, u8 *, 0x39) = temp_r1;
    if ((var_r0_2 & 0xFF) && (func_ov003_021e6d28() != 0)) {
        func_02088d94(M2C_FIELD(arg0, void **, 0x58));
        func_02088f1c(*M2C_FIELD(arg0, s32 **, 0x64));
    }
    temp_r4 = (s8 *) M2C_FIELD(arg0, s32 **, 0x64);
    temp_r7 = (s8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4);
    if (func_020846a4() == 0) {
        var_r8 = 0;
        do {
            if (var_r8 < (u32)(u8)temp_r7) {
                func_02088d94(M2C_FIELD(temp_r4 + (var_r8 * 4), void **, 8));
                func_02088d94(M2C_FIELD(temp_r4 + (var_r8 * 4), void **, 0x18));
            }
            var_r8 = (u32) (u8) (var_r8 + 1);
        } while (var_r8 < 4U);
    }
    temp_r4_2 = M2C_FIELD(arg0, void **, 0x48);
    M2C_FIELD(temp_r4_2, s16 *, 0xE) = func_020a8ff4(temp_r4_2);
    M2C_FIELD(temp_r4_2, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r4_2, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r4_2, u16 *, 2) = (u16) M2C_FIELD(temp_r4_2, u16 *, 4);
    temp_r4_3 = M2C_FIELD(arg0, void **, 0x50);
    M2C_FIELD(temp_r4_3, s16 *, 0xE) = func_020a8ff4(temp_r4_3);
    M2C_FIELD(temp_r4_3, s16 *, 0x10) = 0x100;
    M2C_FIELD(temp_r4_3, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r4_3, u16 *, 2) = (u16) M2C_FIELD(temp_r4_3, u16 *, 4);
    temp_r4_4 = M2C_FIELD(arg0, void **, 0x4C);
    M2C_FIELD(temp_r4_4, s16 *, 0xE) = func_020a8ff4(temp_r4_4);
    M2C_FIELD(temp_r4_4, s16 *, 0x10) = 0xC0;
    M2C_FIELD(temp_r4_4, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r4_4, u16 *, 2) = (u16) M2C_FIELD(temp_r4_4, u16 *, 4);

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E) == 1) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (var_r0_3 & 0xFF) {
        if (func_ov003_021e6d28() != 0) {
            func_02088da8(M2C_FIELD(arg0, void **, 0x58));
            func_02088ff4(*M2C_FIELD(arg0, s32 **, 0x64));
        }
        temp_r4_5 = (s8 *) M2C_FIELD(arg0, s32 **, 0x64);
        var_r7 = 0;
        do {
            func_02088da8(M2C_FIELD(temp_r4_5 + (var_r7 * 4), void **, 8));
            func_02088da8(M2C_FIELD(temp_r4_5 + (var_r7 * 4), void **, 0x18));
            var_r7 += 1;
        } while ((u32) var_r7 < 4U);
        temp_r4_6 = M2C_FIELD(arg0, void **, 0x48);
        M2C_FIELD(temp_r4_6, s16 *, 0xE) = func_020a8ff4(temp_r4_6);
        M2C_FIELD(temp_r4_6, s16 *, 0x10) = -0x100;
        M2C_FIELD(temp_r4_6, s16 *, 0xC) = 0xC;
        M2C_FIELD(temp_r4_6, u16 *, 2) = (u16) M2C_FIELD(temp_r4_6, u16 *, 4);
        temp_r4_7 = M2C_FIELD(arg0, void **, 0x50);
        M2C_FIELD(temp_r4_7, s16 *, 0xE) = func_020a8ff4(temp_r4_7);
        M2C_FIELD(temp_r4_7, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r4_7, s16 *, 0xC) = 0xC;
        M2C_FIELD(temp_r4_7, u16 *, 2) = (u16) M2C_FIELD(temp_r4_7, u16 *, 4);
        temp_r4_8 = M2C_FIELD(arg0, void **, 0x4C);
        M2C_FIELD(temp_r4_8, s16 *, 0xE) = func_020a8ff4(temp_r4_8);
        M2C_FIELD(temp_r4_8, s16 *, 0x10) = 0x5E;
        M2C_FIELD(temp_r4_8, s16 *, 0xC) = 0xC;
        M2C_FIELD(temp_r4_8, u16 *, 2) = (u16) M2C_FIELD(temp_r4_8, u16 *, 4);
    }
    func_ov003_021e74ac(M2C_FIELD(arg0, void **, 0x6C), arg1);
    temp_r5 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0);
    temp_r4_9 = func_020aae44(temp_r5);
    temp_r3 = func_020aae10(temp_r5) & (-0x200U >> 0x17);
    temp_r1_2 = M2C_FIELD(arg0, void **, 0x58);
    M2C_FIELD(temp_r1_2, s16 *, 0x34) = (s16) M2C_FIELD(temp_r5, s16 *, 0x34);
    M2C_FIELD(temp_r1_2, s16 *, 0x36) = (s16) M2C_FIELD(temp_r5, s16 *, 0x36);
    M2C_FIELD(temp_r1_2, s32 *, 0x40) = (s32) ((((M2C_FIELD(temp_r1_2, s32 *, 0x40) & ~0x1FF) | temp_r3) & 0xFFFC01FF) | ((u32) (temp_r4_9 << 0x17) >> 0xE));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s16 *, 0x34) = func_ov003_022004a8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), u8 *, 7));
    temp_r0_2 = (u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1F) >> 0x1F;
    if (temp_r0_2 == 0) {
        return temp_r0_2;
    }
    temp_r0_3 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), void **, 0xE0), u16 *, 0x2E);
    if (func_ov003_021e6cac((u8) temp_r0_3, 0, 3) != 0) {
        return func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
    }
    if (func_ov003_021e6cac((u8) temp_r0_3, 4, 7) != 0) {
        return func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000012);
    }
    if (func_ov003_021e6cac((u8) temp_r0_3, 8, 0x14) != 0) {
        return func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000011);
    }
    temp_r0 = func_ov003_021e6cac((u8) temp_r0_3, 0x15, 0x18);
    if (temp_r0 != 0) {
        return func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000010);
    }
    if ((u8) temp_r0_3 != 0x19) {
        return temp_r0;
    }
    temp_r0_4 = (u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E;
    if (temp_r0_4 == 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    if (var_r1 & 0xFF) {
        return func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000016);
    }
    if (temp_r0_4 == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (!(var_r0 & 0xFF)) {
        return var_r0;
    }
    return func_0208b758(M2C_FIELD(arg0, s32 *, 0x54), 0x47000017);
}

u8 func_ov003_021e9c08(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s8 func_ov003_021e9c24(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4);
}

u8 func_ov003_021e9c30(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021e9c50(void *p) {
 s32 func_020aae10(void *); s32 func_020aae44(void *); s16 func_ov003_022004a8(u8);
 void *q; s32 a,b;
 q=M2C_FIELD(M2C_FIELD(p,void**,0x6c),void**,0xe0);
 b=func_020aae44(q); a=func_020aae10(q);
 E9638Set(M2C_FIELD(p,void**,0x58),M2C_FIELD(q,s16*,0x34),M2C_FIELD(q,s16*,0x36),a,b);
 M2C_FIELD(M2C_FIELD(p,void**,0x5c),s16*,0x34)=func_ov003_022004a8(M2C_FIELD(M2C_FIELD(p,void**,0x6c),u8*,7));
}

u8 func_ov003_021e9cd0(void *arg0) {
    return (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0xE0), u16 *, 0x2E);
}

u8 func_ov003_021e9ce0(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1F) >> 0x1F) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021e9cfc(void *p,s32 mode){
extern void *gCur3DSpriteEngine; extern void *data_027e00c8;
void func_ov003_022006b0(s32,u8); void func_02089438(void*); void func_02088d94(void*); void func_02088da8(void*);
void *old;
M2C_FIELD(p,u8*,0x39)=(M2C_FIELD(p,u8*,0x39)&~0xf0)|((u32)((u8)mode<<28)>>24);
M2C_FIELD(p,u8*,0x3a)=(M2C_FIELD(p,u8*,0x3a)&~0x70)|0x10;
if(E9638Mode(p,1)){
old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;
func_ov003_022006b0(25,M2C_FIELD(M2C_FIELD(p,void**,0x6c),u8*,7));
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=16;gCur3DSpriteEngine=old;
}
if(E9638Mode(p,1)||E9638Mode(p,3))M2C_FIELD(M2C_FIELD(p,void**,0x58),u8*,0x59)=0;
else M2C_FIELD(M2C_FIELD(p,void**,0x58),u8*,0x59)=1;
if(E9638Mode(p,2)){
void *q=M2C_FIELD(p,void**,0x6c);M2C_FIELD(q,u8*,9)=M2C_FIELD(q,u8*,8);
func_02089438(M2C_FIELD(p,void**,0x5c));func_02088d94(M2C_FIELD(p,void**,0x5c));
}else func_02088da8(M2C_FIELD(p,void**,0x5c));
}

u8 func_ov003_021e9e2c(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021e9e4c(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x59) = 1;
}

u8 func_ov003_021e9e58(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021e9e78(void *arg0, s8 arg1, s8 arg2) {
    M2C_FIELD(arg0, s8 *, 0x10) = arg1;
    M2C_FIELD(arg0, s8 *, 0x11) = arg2;
    M2C_FIELD(arg0, s8 *, 0xE) = arg1;
    M2C_FIELD(arg0, s8 *, 0xF) = arg2;
    M2C_FIELD(arg0, s8 *, 0xC) = arg1;
    M2C_FIELD(arg0, s8 *, 0xD) = arg2;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, s16 *, 8) = 0xA0;
    M2C_FIELD(arg0, s16 *, 0xA) = 0xA0;
    M2C_FIELD(arg0, s8 *, 0x12) = 1;
}

void func_ov003_021e9eb4(void *p) {
extern void *gCur3DSpriteEngine,*data_027e00c8;
s32 func_0207c928(s32,s32); s16 func_ov003_022004f0(s32); s32 func_ov003_022008b8(u8);
void func_020809c0(void*,s32,s32); void func_02098844(u32,s32,s32,s32,u16,u16,u8); void func_02098a34(s32,s32,s32,s32,u8);
void *old,*saved; u8 i,a; s16 b; s8 c; u16 v; u32 arg;
old=gCur3DSpriteEngine;
for(i=0;i<M2C_FIELD(M2C_FIELD(p,void**,0x6c),s8*,4);i++){
gCur3DSpriteEngine=data_027e00c8;
a=(func_0207c928(i,2)!=0);
if(i<2)b=0;
else b=(s32)(((u32)func_ov003_022004f0(2)<<16)>>3)>>16;
c=(s8)func_ov003_022008b8(M2C_FIELD((u8*)M2C_FIELD(p,void**,0x6c)+i,u8*,0xa));
if(c){
v=((u16)((((s8)(c-1))<<7)+2))>>1;
func_02098844(1,b,0,(s32)M2C_FIELD(gCur3DSpriteEngine,void**,0x20+a*4)+2,v,i,0);
}else{
func_020809c0((void*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0x20+a*4)+(b+1)*2),7,7);
}
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=1<<a;
gCur3DSpriteEngine=old;
}
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
for(i=0;i<M2C_FIELD(M2C_FIELD(p,void**,0x6c),s8*,4);i++){
a=(func_0207c928(i,2)!=0);
if(i>=2)func_ov003_022004f0(2);
c=(s8)func_ov003_022008b8(M2C_FIELD((u8*)M2C_FIELD(p,void**,0x6c)+i,u8*,0xa));
if(i==M2C_FIELD(M2C_FIELD(p,void**,0x6c),u8*,7)||!E9638Mode(p,2))arg=0;
else arg=1;
if(c)func_02098a34(c,1,a,i,arg);
}
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=1;
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
gCur3DSpriteEngine=saved;
M2C_FIELD(p,u8*,0x3a)=(M2C_FIELD(p,u8*,0x3a)&~0x70)&~0x8;
}

void func_ov003_021ea134(s32 arg0) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | (1 << arg0));
}

void func_ov003_021ea154(void *p){
extern void *gCur3DSpriteEngine; extern void *data_027e00c4;
void func_01ff9ce8(s32); s32 func_ov003_022008b8(u8); void func_02088da8(void*); void func_02088d94(void*); void func_020990fc(void*,s32,s32,s32); void *func_ov003_021e6e94(s32); void *func_02086680(void*); void func_0209b2b4(s32,s32,s32,void*,s32,u16);
void *old; s8 id,n; u8 flag;
old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;
func_01ff9ce8(3);
id=M2C_FIELD(M2C_FIELD(p,void**,0x40),s8*,15);
n=func_ov003_022008b8((u8)id);
if(!n)func_02088da8(M2C_FIELD(M2C_FIELD(p,void**,0x68),void**,0x78));
else {
if(((u32)(M2C_FIELD(p,u8*,0x3a)<<31)>>31))func_02088d94(M2C_FIELD(M2C_FIELD(p,void**,0x68),void**,0x78));
func_020990fc(M2C_FIELD(M2C_FIELD(p,void**,0x68),void**,0x78),n,8,0);
func_0209b2b4(1,8,3,func_02086680(func_ov003_021e6e94(id)),0x2000,(u16)(1+224*((u32)(M2C_FIELD(p,u8*,0x3a)<<30)>>31)));
}
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=8;gCur3DSpriteEngine=old;
flag=E9638Toggle(p);
M2C_FIELD(p,u8*,0x3a)=(M2C_FIELD(p,u8*,0x3a)&~2)|((u32)(flag<<31)>>30);
}

void func_ov003_021ea27c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_020a9a30(arg0, 0, arg1, arg2);
}

void func_ov003_021ea294(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_020a9a30(arg0, 2, arg1, arg2);
}

void func_ov003_021ea2ac(void) {
    extern void *gCur3DSpriteEngine;
    u16 *volatile p;
    p = (u16 *)((s8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) + 0x12);
    *p = (u16)(*p & ~0xC0);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x51) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x52) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, 0x53) = 0;
}

void func_ov003_021ea314(void *p) {
s32 func_020cfb94(void); s32 func_02084d3c(void*,s32); void func_02084d88(void*,s32); void func_02084e74(void); void func_01ffa6fc(void*); s32 func_02084a0c(void); s32 func_ov003_021f153c(void);
u32 buf[9]; u8 flag, n, start;
if(func_020cfb94()==2) M2C_FIELD(p,u8*,0x39)=(M2C_FIELD(p,u8*,0x39)&~1)|1;
if(!func_02084d3c(buf,0x24))return;
flag=(((u32)(M2C_FIELD(p,u8*,0x39)<<31)>>31)==0);
if(flag && func_ov003_021f153c()==-256) M2C_FIELD(buf,u8*,8)=1;
else {M2C_FIELD(buf,u8*,8)=0;buf[6]=0;}
buf[0]=0;buf[1]=0;
start=func_02084a0c(); n=0;
if(func_020cfb94()-start>0)do{n++;}while(n<func_020cfb94()-start);
func_02084d88(buf,0x24);func_02084e74();func_01ffa6fc(p);
}

void func_ov003_021ea3f4(void *arg0) {
 void *func_02084e24(u8);
 M2C_UNK func_02088ff4(s32);
 s32 temp_r2,var_r1;
 u8 var_r0,var_r8;
 void *temp_r0,*temp_r1,*temp_r4;
 temp_r4=M2C_FIELD(arg0,void**,0x64);
 func_02088ff4(M2C_FIELD(temp_r4,s32*,0));
 func_02088ff4(M2C_FIELD(temp_r4,s32*,4));
 var_r8=0;
 if(M2C_FIELD(M2C_FIELD(arg0,void**,0x6c),s8*,4)<=0)return;
 do {
 var_r0=M2C_FIELD((u8*)M2C_FIELD(arg0,void**,0x6c)+var_r8,u8*,0x74);
 var_r1=E9638IsFF(var_r0);
 if(var_r1)var_r0=M2C_FIELD(M2C_FIELD(arg0,void**,0x6c),u8*,0x74);
 temp_r0=func_02084e24(var_r0);
 if(temp_r0==0)return;
 temp_r2=E9638Value(temp_r0);
 temp_r1=(u8*)M2C_FIELD(arg0,void**,0x68)+var_r8;
 if(M2C_FIELD(temp_r1,u8*,0x7c)!=0) {
 if(temp_r2==0)M2C_FIELD(temp_r1,u8*,0x7c)=0;
 }else if(temp_r2!=0)M2C_FIELD(temp_r1,u8*,0x7c)=1;
 var_r8++;
 }while(var_r8<M2C_FIELD(M2C_FIELD(arg0,void**,0x6c),s8*,4));
}

void func_ov003_021ea4a8(void *arg0,s32 arg1){
void *func_02084e24(u8);M2C_UNK func_0208fe30(s32);
s32 dummy=0;
u8 var_r7,var_r0;
s32 temp_r2,var_r1;
void *temp_r0,*temp_r8;
var_r7=0;
if(M2C_FIELD(M2C_FIELD(arg0,void**,0x6c),s8*,4)<=0)return;
do{
var_r0=M2C_FIELD((u8*)M2C_FIELD(arg0,void**,0x6c)+var_r7,u8*,0x74);
var_r1=E9638IsFF(var_r0);
if(var_r1)var_r0=M2C_FIELD(M2C_FIELD(arg0,void**,0x6c),u8*,0x74);
temp_r0=func_02084e24(var_r0);if(!temp_r0)return;
temp_r2=E9638Value(temp_r0);
temp_r8=(u8*)M2C_FIELD(arg0,void**,0x68)+var_r7;
if(M2C_FIELD(temp_r8,u8*,0x7c)){
if(!temp_r2){if(arg1)func_0208fe30(0x1000f);M2C_FIELD(temp_r8,u8*,0x7c)=0;}
}else if(temp_r2){if(arg1)func_0208fe30(0x1000d);M2C_FIELD(temp_r8,u8*,0x7c)=1;}
var_r7++;
}while(var_r7<M2C_FIELD(M2C_FIELD(arg0,void**,0x6c),s8*,4));
dummy=dummy+1;
}

