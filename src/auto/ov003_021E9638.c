/* 28 functions from 0x021E9638 to 0x021EA57C (ov003), found by ds-decomp. */
#include "common.h"
static inline u8 E9638IsFF(u8 v) { return v==255; }
static inline u8 E9638Value(void *p) { return M2C_FIELD(p,s32*,0x18); }
#include "coordinate_bits.h"

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

void func_ov003_021ea134(s32 arg0) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | (1 << arg0));
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
s32 temp_r2,var_r1;u8 var_r7,var_r0;void *temp_r8,*temp_r0;
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
}

