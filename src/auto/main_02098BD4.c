/* 52 functions from 0x02098BD4 to 0x02099B18 (main), found by ds-decomp. */
#include "common.h"

typedef struct { s32 values[12]; } Unk02098BD4Table;
extern Unk02098BD4Table data_020f36bc;

s32 func_02098bd4(M2C_UNK arg0, u8 arg1) {
Unk02098BD4Table table=data_020f36bc;
s32 i=0;
switch(arg0) {
case 0: i=0; break;
case 1: i=2; break;
case 2: i=4; break;
case 3: i=4; break;
case 4: i=4; break;
case 5: i=6; break;
case 6: i=6; break;
case 7: i=6; break;
case 8: i=8; break;
case 9: i=8; break;
case 10: i=8; break;
case 11: i=10; break;
}
if(arg1) i++;
return table.values[i];
}

void func_02098cb8(M2C_UNK arg0, u16 arg1, u32 arg2, M2C_UNK arg3, u8 arg4, s32 arg5) {
    M2C_UNK func_01ffaacc(u16, u8, M2C_UNK, s32, s32);
    s32 func_02098bd4(M2C_UNK, u8);
    func_01ffaacc((u16)(arg1 & 0x1FF), (u8)arg2, arg3, func_02098bd4(arg0, arg4), arg5);
}

M2C_UNK func_02098d08(M2C_UNK arg0, s32 arg1) {
    M2C_UNK func_0200bc5c();
    M2C_UNK func_020814e4(M2C_UNK *);
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    s32 func_02098034(M2C_UNK);
    s32 func_020e3218(M2C_UNK *);
    extern M2C_UNK data_02103274, data_02103280;
    if (func_02098034(arg0) == 0) return;
    func_0200bc5c();
    func_020814e4(&data_02103274);
    func_02081590(func_020e3218(&data_02103280), arg1);
    func_02081528();
}

M2C_UNK func_02098d48(M2C_UNK arg0, u16 arg1) {
    M2C_UNK func_0200bc5c();
    M2C_UNK func_0208116c(M2C_UNK *, s32, M2C_UNK);
    s32 func_02098034(M2C_UNK);
    extern M2C_UNK data_02103288;
    if (func_02098034(arg0) == 0) return;
    func_0200bc5c();
    func_0208116c(&data_02103288, arg1 << 5, 0x20);
}

void func_02098d78(M2C_UNK arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02098d08(M2C_UNK, s32);
    M2C_UNK func_02098d48(M2C_UNK, u16);
    extern void *gCur3DSpriteEngine;
    func_02098d08(arg0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg1);
    func_02098d48(arg0, (u16) (arg2 + 0x10));
}

M2C_UNK *func_02098db4(void) {
    extern M2C_UNK data_020f3650;
    return &data_020f3650;
}

void func_02098dc0(s32 arg0, s32 arg1, M2C_UNK arg2, s32 arg3) {
 M2C_UNK func_01ffaacc(u16,u8,M2C_UNK,s32,s32);
 s32 result = (s32)func_02098db4();
 arg1 = (u8)arg1;
 arg0 &= 0x1FF;
 func_01ffaacc((u16)arg0,arg1,arg2,result,arg3);
}

void func_02098e04(void *arg0, u32 arg1, s32 arg2) {
    M2C_UNK func_02088da8();
    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg1 >> 5);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg2 << 0x18) >> 6));
    func_02088da8();
}

u8 func_02099014(void *);
void func_02098e2c(void *arg0, s32 arg1) {
extern void *gCur3DSpriteEngine, *data_027e00c4, *data_027e00c8;
void *old; void *v; s32 i; u32 mode;
M2C_FIELD(arg0,u8*,0x58)=arg1;
M2C_FIELD(arg0,u8*,0x49)=3;
M2C_FIELD(arg0,M2C_UNK **,0x44)=func_02098db4();
if (!func_02099014(arg0)) return;
old=gCur3DSpriteEngine; i=0;
do {
if(i==0) v=data_027e00c8; else v=data_027e00c4;
gCur3DSpriteEngine=v;
mode=((u32)M2C_FIELD(arg0,u8*,0x48)<<28)>>29;
if ((mode!=0 || v==data_027e00c8) && (mode!=1 || v==data_027e00c4) && (mode!=3 || v==old))
func_02098d78(arg1,M2C_FIELD(arg0,u16*,0x3e)<<5,(u16)((M2C_FIELD(arg0,u32*,0x40)<<6)>>24));
i++;
} while(i<2);
gCur3DSpriteEngine=old;
}

void func_02098f08(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x59) = arg1;
}

u8 func_02099014(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x58) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

M2C_UNK func_0209902c(void *arg0) {
 M2C_FIELD(arg0,s8 *,0x58)=0;
 M2C_FIELD(arg0,s8 *,0x59)=1;
}

M2C_UNK func_02099040(void *arg0) {
 void func_02088964(void *);
 void func_02088c78(void *);
 void func_020887ec(void *);
 if(func_02099014(arg0)==0) return;
 func_02088964(arg0);
 func_02088c78(arg0);
 func_020887ec(arg0);
}

void func_02099070(void) {
    M2C_UNK func_0209902c();
    func_0209902c();
}

void func_0209907c(void) {
    M2C_UNK func_02099040();
    func_02099040();
}

void **func_02099088(s32 arg0) {
    void **func_01ffa3dc(M2C_UNK *, s32);
    M2C_UNK func_02089108();
    extern M2C_UNK data_02102fd4, data_02102f8c;
    void **result;
    if (arg0 == 0) arg0 = 7;
    result = func_01ffa3dc(&data_02102fd4, arg0);
    if (result != 0) {
        func_02089108();
        *result = &data_02102f8c;
    }
    return result;
}

void func_020990c0(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02102fd4;
    func_01ffa9e4(&data_02102fd4);
}

void func_020990d4(void *arg0, u32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg1 >> 5);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg2 << 0x18) >> 6));
    func_02088da8();
}

void func_020990fc(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 func_02097ce4(s32);
    u8 func_02099320(void *);
    void func_020985b0(s32, s32, s32);
    void func_02098e2c(void *, s32);
    void func_02099204(void *);
    extern void *gCur3DSpriteEngine, *data_027e00c4, *data_027e00c8;

    void *old; void *v; s32 i; u32 mode;
    M2C_FIELD(arg0, u8 *, 0x58) = (u8)arg1;
    M2C_FIELD(arg0, u8 *, 0x59) = (u8)arg2;
    M2C_FIELD(arg0, u8 *, 0x49) = func_02097ce4(arg1);
    if (func_02099320(arg0)) {
        old = gCur3DSpriteEngine;
        i = 0;
        do {
            if (i == 0) v = data_027e00c8; else v = data_027e00c4;
            gCur3DSpriteEngine = v;
            mode = ((u32)M2C_FIELD(arg0, u8 *, 0x48) << 28) >> 29;
            if ((mode != 0 || v == data_027e00c8) &&
                (mode != 1 || v == data_027e00c4) &&
                (mode != 3 || v == old)) {
                func_020985b0(arg1, arg2, M2C_FIELD(v, s32 *, 0x1C) + (M2C_FIELD(arg0, u16 *, 0x3e) << 5));
            }
            i++;
        } while (i < 2);
        gCur3DSpriteEngine = old;
    }
    if (arg3) {
        func_02098e2c(M2C_FIELD(arg0, void **, 0x60), arg1);
    }
    func_02099204(arg0);
}

void func_020991f4(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5C) = arg1;
}

void func_020991fc(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5D) = arg1;
}

void func_02099310(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5A) = arg1;
}

void func_02099318(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x5B) = arg1;
}

u8 func_02099320(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x58) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

M2C_UNK func_02099338(void *arg0) {
 M2C_FIELD(arg0,s8 *,0x58)=0;
 M2C_FIELD(arg0,s8 *,0x59)=0;
 M2C_FIELD(arg0,s8 *,0x5A)=0;
 M2C_FIELD(arg0,s8 *,0x5B)=0;
 M2C_FIELD(arg0,s8 *,0x5C)=1;
 M2C_FIELD(arg0,s8 *,0x5D)=0;
 M2C_FIELD(arg0,void ***,0x60)=func_02099088((s32)arg0);
}

M2C_UNK func_0209936c(void *a){
 void func_02088964(void*);void func_02088c78(void*);
 s32 func_02098bd4(M2C_UNK,u8);
 void func_020887a8(void*,s32,s32,s32,s32);
 s32 v;if(!func_02099320(a))return;
 v=func_02098bd4(M2C_FIELD(a,u8*,0x59),M2C_FIELD(a,u8*,0x5b));
 func_02088964(a);func_02088c78(a);
 func_020887a8(a,M2C_FIELD(a,s16*,0x34),M2C_FIELD(a,s16*,0x36),M2C_FIELD(a,s8*,0x49),v);
}

void func_020993bc(void) {
    M2C_UNK func_02099338();
    func_02099338();
}

void func_020993c8(void) {
    M2C_UNK func_0209936c();
    func_0209936c();
}

void **func_020993d4(s32 arg0) {
    void **func_01ffa3dc(M2C_UNK *, s32);
    M2C_UNK func_02089108();
    extern M2C_UNK data_02102fac, data_02102fa0;
    void **result;
    if (arg0 == 0) arg0 = 7;
    result = func_01ffa3dc(&data_02102fac, arg0);
    if (result != 0) {
        func_02089108();
        *result = &data_02102fa0;
    }
    return result;
}

void func_0209940c(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02102fac;
    func_01ffa9e4(&data_02102fac);
}

void func_02099420(void) {

}

s32 func_02099424(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_02099438(void) {

}

s32 func_0209943c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

M2C_UNK func_02099450(s32 a,s32 b,s32 c){
 extern void *gCur3DSpriteEngine;extern M2C_UNK data_0211e9dc,data_0211f0dc;
 void func_02007ef4(void*,void*,s32);
 void *p=M2C_FIELD(gCur3DSpriteEngine,void**,0x50);
 M2C_FIELD(p,u16*,0x300)=b+100;M2C_FIELD(p,u8*,0)=1;M2C_FIELD(p,u8*,0x302)=a;
 switch(c){
 case 0:func_02007ef4(&data_0211e9dc,(u8*)M2C_FIELD((u8*)gCur3DSpriteEngine+a*4,void**,12)+((b+16)<<5),0x700);break;
 case 1:func_02007ef4(&data_0211f0dc,(u8*)M2C_FIELD((u8*)gCur3DSpriteEngine+a*4,void**,12)+((b+16)<<5),0x700);break;
 }
}

void func_020994e0(M2C_UNK arg0) {
    M2C_UNK func_02099450(M2C_UNK, M2C_UNK, M2C_UNK);
    func_02099450(1, arg0, 0);
}

void func_020994f8(u16 *a,s32 b,s32 c){
 s32 i;for(i=0;i<c;i++){a[i]=b+i*2;a[i+32]=b+(i*2+1);}
}

u8 func_02099818(s32 arg0,M2C_UNK arg1,M2C_UNK arg2,s32 arg3) {
 M2C_UNK func_020996d0(s32,u8,M2C_UNK,M2C_UNK,s32);
 extern u8 data_ov000_021b7e7c[];
 extern s32 data_ov000_021b7f7c[];
 func_020996d0(data_ov000_021b7f7c[arg0],data_ov000_021b7e7c[arg0],arg1,arg2,arg3);
 return data_ov000_021b7e7c[arg0];
}

u8 func_020999b8(void *arg0) {
    s32 func_0209600c();
    u8 var_r0;

    if (func_0209600c() == 0) {
        return 0U;
    }
    if (M2C_FIELD(arg0, u8 *, 0x5C) & 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020999e8(void *a){
 u16 *base=M2C_FIELD(a,u16**,0x40);s32 x,y;
 if(!base)return 0;
 x=M2C_FIELD(a,u8*,0x4a);y=M2C_FIELD(a,u8*,0x4b);
 return (s32)(base+x+(y<<5));
}

u16 *func_02099a0c(void *arg0) {
 u16 *base=M2C_FIELD(arg0,u16 **,0x40);
 if(base==0) return 0;
 return base + M2C_FIELD(arg0,u8 *,0x48) + (M2C_FIELD(arg0,u8 *,0x49)<<5);
}

void func_02099a30(void *arg0) {
 M2C_UNK func_020809c0(s32,u8,u8);
 u16 *base=M2C_FIELD(arg0,u16 **,0x40);
 if(base==0) return;
 func_020809c0((s32)(base+M2C_FIELD(arg0,u8 *,0x48)+(M2C_FIELD(arg0,u8 *,0x49)<<5)),M2C_FIELD(arg0,u8 *,0x58),M2C_FIELD(arg0,u8 *,0x59));
 M2C_FIELD(arg0,M2C_UNK (**)(),0x50)();
}

M2C_UNK func_02099a6c(void *arg0) {
 s32 n=M2C_FIELD(arg0,u8 *,0x4A)-M2C_FIELD(arg0,u8 *,0x48)+2;
 if(M2C_FIELD(arg0,u8 *,0x58)<n) M2C_FIELD(arg0,u8 *,0x58)=n;
 M2C_FIELD(arg0,u8 *,0x4A)=M2C_FIELD(arg0,u8 *,0x48);
 M2C_FIELD(arg0,u8 *,0x56)=0;
}

M2C_UNK func_02099a9c(void *a){
 s32 n=M2C_FIELD(a,u8*,0x4b)-M2C_FIELD(a,u8*,0x49)+2;
 if(M2C_FIELD(a,u8*,0x59)<n)M2C_FIELD(a,u8*,0x59)=n;
 M2C_FIELD(a,u8*,0x4b)=M2C_FIELD(a,u8*,0x49);
}

void func_02099ac4(void *arg0) {
    M2C_UNK func_02099a6c();
    M2C_UNK func_02099a9c(void *);
    func_02099a6c();
    func_02099a9c(arg0);
    M2C_FIELD(arg0, u8 *, 0x5C) = (u8) (M2C_FIELD(arg0, u8 *, 0x5C) | 2);
}

u8 func_02099ae8(u8 *arg0) {
    u8 var_r0;

    if (*arg0 & 0x80) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_02099b00(u8 *arg0) {
    u8 var_r0;

    if (*arg0 == 0x1F) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

