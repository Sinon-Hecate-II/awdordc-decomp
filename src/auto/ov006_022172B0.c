/* 44 functions from 0x022172B0 to 0x02218200 (ov006), found by ds-decomp. */
#include "common.h"
typedef struct { s32 v[4]; } Ov006Date;
extern const Ov006Date data_ov006_02218394;

void func_ov006_022172b0(M2C_UNK arg0) {s8 func_020848c4(); u8 func_020848f8(); s32 func_020c7e58(M2C_UNK);
void *func_01ffa42c(void *,M2C_UNK);
extern M2C_UNK data_ov006_0221890c,data_ov006_02218918;
u8 i; void *p=func_01ffa42c(&data_ov006_02218918,arg0);
if(p) {
M2C_FIELD(p,void **,0)=&data_ov006_0221890c;
M2C_FIELD(p,u8 *,0x34)=3;
M2C_FIELD(p,s32 *,0x50)=0;M2C_FIELD(p,s32 *,0x54)=0;
M2C_FIELD(p,s8 *,0x4c)=func_020848c4();
M2C_FIELD(p,u8 *,0x4d)=func_020848f8();
M2C_FIELD(p,s32 *,0x38)=func_020c7e58(0);
i=0;
do {
if(M2C_FIELD(p,u8 *,0x4d)&(1<<i))
M2C_FIELD(p+i*4,s32 *,0x3c)=(s32)((u8 (*)[0x54])M2C_FIELD(p,s32 *,0x38)+i*0x32);
i++;
}while(i<4);
}
}

void func_ov006_0221734c(M2C_UNK arg0,s32 arg1,s32 arg2) {s8 func_020848c4(); u8 func_020848f8(); s32 func_020c7e58(M2C_UNK);
void *func_01ffa42c(void *,M2C_UNK);
extern M2C_UNK data_ov006_0221890c,data_ov006_02218918;
u8 i; void *p=func_01ffa42c(&data_ov006_02218918,arg0);
if(p) {
M2C_FIELD(p,void **,0)=&data_ov006_0221890c;
M2C_FIELD(p,u8 *,0x34)=4;
M2C_FIELD(p,s32 *,0x50)=0;M2C_FIELD(p,s32 *,0x54)=0;
M2C_FIELD(p,s8 *,0x4c)=func_020848c4();
M2C_FIELD(p,u8 *,0x4d)=func_020848f8();
M2C_FIELD(p,s32 *,0x38)=func_020c7e58(0);
i=0;
do {
if(M2C_FIELD(p,u8 *,0x4d)&(1<<i))
M2C_FIELD(p+i*4,s32 *,0x3c)=(s32)((u8 (*)[0x54])M2C_FIELD(p,s32 *,0x38)+i*0x32);
i++;
}while(i<4);
}
 M2C_FIELD(p,s32 *,0x50)=arg1;M2C_FIELD(p,s32 *,0x54)=arg2;}

s32 func_ov006_022173fc(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}

void func_ov006_02217410(void) {

}

void func_ov006_02217414(void) {
    s32 func_02082028(M2C_UNK);
    extern M2C_UNK data_ov006_02218e20;
    M2C_FIELD(&data_ov006_02218e20, s32 *, 4) = func_02082028(0x310);
    M2C_FIELD(&data_ov006_02218e20, s32 *, 8) = 0;
    M2C_FIELD(&data_ov006_02218e20, s8 *, 0) = 0;
}

void func_ov006_02217438(void) {extern M2C_UNK data_ov006_02218e20;
if(M2C_FIELD(&data_ov006_02218e20,s32 *,4)) {
func_02082040(M2C_FIELD(&data_ov006_02218e20,s32 *,4));
}
M2C_FIELD(&data_ov006_02218e20,s32 *,4)=0;
}

void func_ov006_02217464(M2C_UNK arg0) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov006_02218a48;
    func_01ffa3dc(&data_ov006_02218a48, arg0);
}

void func_ov006_0221747c(void *arg0) {
    s32 func_020e34bc(s32);
    M2C_UNK func_020e36dc(void *);
    M2C_FIELD(arg0, s32 *, 0x38) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C) = func_020e34bc(0x80);
    M2C_FIELD(arg0, s32 *, 0x48) = func_020e34bc(0x6F8);
    M2C_FIELD(arg0, s32 *, 0x4C) = func_020e34bc(0x2AC);
    func_020e36dc(arg0);
    func_02086608(4);
    func_02089728();
    func_020d47f0();
}

void func_ov006_022174d0(void *arg0) {
    func_020e36f4();
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x3C));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x48));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x4C));
    func_02086658(4);
    func_02089740();
}

void func_ov006_02217504(void *arg0) {
    M2C_UNK func_02084f2c(void *, M2C_UNK, M2C_UNK, void *, void *, void *);
    M2C_UNK func_020c8f0c(s32, s32);
    s32 func_020cfbdc(u16);
    func_020c8f0c(M2C_FIELD(arg0, s32 *, 0x3C), func_020cfbdc((u16) M2C_FIELD(arg0, s32 *, 0x34)));
    func_02084f2c(arg0 + 0x3C, 1, 0, arg0 + 0x40, arg0 + 0x44, arg0);
}

void func_ov006_02217554(void *p) {
extern M2C_UNK data_ov006_02218e20;
if(M2C_FIELD(&data_ov006_02218e20,s32 *,8)) {M2C_FIELD(p,s32 *,0x38)=1;return;}
func_020e38f0(M2C_FIELD(&data_ov006_02218e20,s32 *,4),p+0x38);
}

void func_ov006_02217588(void *arg0) {
    M2C_UNK func_01ffa8c4(void *, M2C_UNK);
    if (M2C_FIELD(arg0, s32 *, 0x44) == 0) {
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void func_ov006_022175a4(void *p) {
extern M2C_UNK data_ov006_02218e20;
if(M2C_FIELD(p,s32 *,0x38)) {
void *q=M2C_FIELD(&data_ov006_02218e20,void **,4);
s32 ready;
if(M2C_FIELD(q,s32 *,0x30c)==0) ready=0;
else if(M2C_FIELD(q,s32 *,4)==0) ready=0;
else ready=1;
if(ready) M2C_FIELD(&data_ov006_02218e20,u8 *,0)=1;
}
if(M2C_FIELD(&data_ov006_02218e20,u8 *,0)) func_02086720(0x46000017);
else func_02086720(0x46000016);
M2C_FIELD(&data_ov006_02218e20,s32 *,8)=1;
}

void func_ov006_02217794(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0x38) != 0) && (func_0208471c() == 0)) {
        return;
    }
    func_020d47f0();
    func_01ffa8c4(arg0, 2);
}

void func_ov006_022177c8(s32 arg0) {
    extern M2C_UNK data_ov006_02218aa8;
    M2C_FIELD(func_01ffa42c(&data_ov006_02218aa8), s32 *, 0x34) = arg0;
}

void func_ov006_022177e4(void) {
    M2C_UNK func_02089728();
    func_02086608(4);
    func_02089728();
    if (func_02086a30(0x21) == 0) {
        func_02086720(0x46000026);
        func_02086740(0x21, 1);
        return;
    }
    func_02086720(0);
}

void func_ov006_0221782c(void) {
    M2C_UNK func_02089740();
    func_02086658(4);
    func_02089740();
}

void func_ov006_02217840(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov006_02218a78;
    func_01ffa42c(&data_ov006_02218a78, arg0);
}

void func_ov006_02217858(void *arg0) {
s32 func_020c7eb8(s32);
M2C_FIELD(arg0,s32 *,0x4c)=func_020e34bc(0x1ea0);
M2C_FIELD(arg0,s32 *,0x50)=func_020e34bc(0x45b0);
M2C_FIELD(arg0,s32 *,0x54)=0;
func_020e36dc(arg0); func_02086608(4); func_02089728(); func_020d47f0();
if(func_020c7eb8(M2C_FIELD(arg0,s32 *,0x34))){
switch(M2C_FIELD(arg0,s32 *,0x38)){case 0:func_02086720(0x4600002c);return;case 1:func_02086720(0x4600002d);return;}
}else{
switch(M2C_FIELD(arg0,s32 *,0x38)){case 0:func_02086720(0x46000020);return;case 1:func_02086720(0x46000021);return;}
}
}

void func_ov006_0221791c(void *arg0) {
    M2C_UNK func_020e35cc(s32);
    M2C_UNK func_020e36f4();
    func_020e36f4();
    func_02086658(4);
    func_02089740();
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x4C));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x50));
}

void func_ov006_02217948(void *arg0) {
    M2C_UNK func_020e3b54(s32, M2C_UNK, void *);
    M2C_UNK func_020e3d6c(s32, void *, void *);
    M2C_UNK func_020e3f88(void *, s32, void *);
    s32 temp_r0;

    M2C_FIELD(arg0, s32 *, 0x3C) = 10;
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x38);
    switch (temp_r0) {                              /* irregular */
    case 0:
        func_020e3b54(M2C_FIELD(arg0, s32 *, 0x4C), 0x64, arg0 + 0x3C);
        return;
    case 1:
        func_020e3d6c(M2C_FIELD(arg0, s32 *, 0x4C), arg0 + 0x3C, arg0);
        return;
    case 2:
        func_020e3f88(arg0 + 0x48, M2C_FIELD(arg0, s32 *, 0x4C), arg0 + 0x3C);
        return;
    }
}

void func_ov006_022179b4(void *arg0) {
    s32 func_0207c2f0();
    u64 func_020720f0(s32, s32);
    s32 func_020c7a3c(s32);
    M2C_UNK func_020c7cd0(s32, s32);
    s32 func_020c8c6c(void *);
    s32 func_020c8cbc(s32);
    s32 func_02084cf8();
    M2C_UNK func_01ffa8c4(void *, M2C_UNK);
    s32 sp0;
    s32 temp_r1;
    s32 temp_r4;
    s32 temp_r7;
    s32 var_r0;
    s32 var_r3;
    s32 var_r6;
    s32 var_r8;
    s32 var_r9;
    u32 temp_r2;
    u32 var_r4;
    u32 var_r5;
    void *temp_r11;

    var_r6 = 0;
    sp0 = 0;
    var_r5 = 0;
    if ((u32) M2C_FIELD(arg0, u32 *, 0x3C) > 0U) {
        var_r8 = 0;
        var_r9 = 0;
        do {
            temp_r4 = M2C_FIELD(arg0, s32 *, 0x50);
            temp_r11 = M2C_FIELD(arg0, s32 *, 0x4C) + var_r8;
            func_020c7cd0(temp_r11 + 0x10, temp_r4 + var_r9);
            temp_r7 = M2C_FIELD(temp_r11, s32 *, 4);
            if (temp_r7 == func_02084cf8()) {
                var_r0 = 1;
            } else if (func_020c8c6c(temp_r11 + 0x50) != 0) {
                var_r0 = 1;
            } else {
                var_r0 = 0;
            }
            if ((var_r0 == 0) && (func_020c7a3c(temp_r4 + var_r9) != 0) && (func_020c8cbc(temp_r4 + var_r9) == 0)) {
                var_r6 |= 1 << var_r5;
                sp0 += 1;
            }
            var_r5 += 1;
            var_r8 += 0x310;
            var_r9 += 0x6F8;
        } while (var_r5 < (u32) M2C_FIELD(arg0, u32 *, 0x3C));
    }
    if (sp0 == 0) {
        func_01ffa8c4(arg0, 3);
        return;
    }
    temp_r1 = (s32)(func_020720f0(func_0207c2f0(), sp0) >> 32);
    temp_r2 = M2C_FIELD(arg0, u32 *, 0x3C);
    var_r3 = 0;
    var_r4 = 0;
    if (temp_r2 > 0U) {
loop_16:
        if (var_r6 & (1 << var_r4)) {
            if (var_r3 == (u32)temp_r1) {
                M2C_FIELD(arg0, s32 *, 0x54) = (s32) ((var_r4 * 0x6F8) + M2C_FIELD(arg0, s32 *, 0x50));
                goto done;
            } else {
                var_r3 += 1;
            }
        }
        var_r4 += 1;
        if (var_r4 < temp_r2) {
            goto loop_16;
        }
    }
done:
    if (M2C_FIELD(arg0, s32 *, 0x54) != 0) {
        return;
    }
    func_01ffa8c4(arg0, 3);
}

void func_ov006_02217b08(void *arg0) {
    M2C_UNK func_020c9100();
    M2C_UNK func_020c9120(s32, s32);
    func_020c9100();
    func_020c9120(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x54));
}

void func_ov006_02217b24(void *arg0) {
    M2C_UNK func_0208999c(s32, M2C_UNK, s32);
    M2C_UNK func_02089b38(s32, M2C_UNK *);
    s32 func_0208b564();
    M2C_UNK func_0209ccb8(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020c8e40();
    extern M2C_UNK data_ov006_02218cd8;
    extern M2C_UNK func_ov003_021fef18;
    s32 temp_r0;

    temp_r0 = func_0208b564();
    func_0208999c(temp_r0, 2, 0x4600001F);
    func_02089b38(temp_r0, &data_ov006_02218cd8);
    func_02089b38(temp_r0, M2C_FIELD(arg0, s32 *, 0x54) + 6);
    func_020c8e40();
    func_0209ccb8(&func_ov003_021fef18, 6);
}

void func_ov006_02217b7c(M2C_UNK arg0) {
    s32 func_0208471c();
    M2C_UNK func_020d47f0();
    if (func_0208471c() == 0) {
        return;
    }
    func_020d47f0();
    func_01ffa8c4(arg0, 4);
}

void func_ov006_02217ba4(s32 arg0) {
    M2C_UNK func_0208ee60(void *, M2C_UNK, M2C_UNK);
    void *func_0208f3b0();
    void *temp_r0;

    temp_r0 = func_0208f3b0();
    func_0208ee60(temp_r0, 0xCC00, 0xF);
    M2C_FIELD(temp_r0, s32 *, 0x68) = (s32) (arg0 + 0x40);
    M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x5C) = 9;
    M2C_FIELD(temp_r0, s16 *, 0x34) = 0xA0;
    M2C_FIELD(temp_r0, s16 *, 0x36) = 0x58;
}

void func_ov006_02217bf0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3C) = 1;
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
    M2C_FIELD(arg0, s32 *, 0x38) = 2;
}

void func_ov006_02217c0c(s32 a) {
extern M2C_UNK data_ov006_02218bd8;
void *p=((void *(*)())func_01ffa42c)(&data_ov006_02218bd8);
M2C_FIELD(p,s32 *,0x34)=a;M2C_FIELD(p,s32 *,0x38)=0;
}

void func_ov006_02217c30(s32 a) { extern M2C_UNK data_ov006_02218bd8; void *p=((void *(*)())func_01ffa42c)(&data_ov006_02218bd8); M2C_FIELD(p,s32 *,0x34)=a; M2C_FIELD(p,s32 *,0x38)=1; }

void func_ov006_02217c54(void) {
    func_02086608(4);
}

void func_ov006_02217c64(void) {
    func_02086658(4);
}

void func_ov006_02217c74(M2C_UNK arg0) {
    M2C_UNK func_02086720(s32);
    M2C_UNK func_02086740(M2C_UNK, M2C_UNK);
    s32 func_02086a30(M2C_UNK);
    extern M2C_UNK data_ov006_02218ba8;
    if (func_02086a30(0x22) != 0) {
        return;
    }
    func_02086720(0x46000027);
    func_02086740(0x22, 1);
    func_01ffa42c(&data_ov006_02218ba8, arg0);
}

void func_ov006_02217cb8(M2C_UNK arg0) { M2C_UNK func_02086720(s32); M2C_UNK func_02086740(M2C_UNK,M2C_UNK); s32 func_02086a30(M2C_UNK); extern M2C_UNK data_ov006_02218ba8; if(func_02086a30(0x23)!=0)return; func_02086720(0x46000028); func_02086740(0x23,1); func_01ffa42c(&data_ov006_02218ba8,arg0); }

void func_ov006_02217cfc(s32 arg0) {
    extern s32 data_ov006_02218e2c;
    data_ov006_02218e2c = arg0;
}

s32 func_ov006_02217d0c(void) {extern s32 data_ov006_02218e2c;return (data_ov006_02218e2c*10)>>8;}

void func_ov006_02217d28(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x54) = func_020e34bc(0x1EA0);
    M2C_FIELD(arg0, s32 *, 0x44) = func_020e34bc(0x28);
    M2C_FIELD(arg0, s32 *, 0x48) = func_020e34bc(0x14);
    M2C_FIELD(arg0, s32 *, 0x4C) = func_020e34bc(0xA);
    M2C_FIELD(arg0, s32 *, 0x50) = func_020e34bc(6);
    M2C_FIELD(arg0, s8 *, 0x3B) = 0;
    func_020e36dc(arg0);
    func_02086608(4);
    func_02089728();
    func_ov006_02217cfc(0);
    func_020d47f0();
}

void func_ov006_02217d9c(void *arg0) {
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x54));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x44));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x48));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x4C));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x50));
    func_020e36f4(arg0);
    func_02086658(4);
    func_02089740();
}

void func_ov006_02217de4(void *arg0) {
    s32 func_02084cf8();
    s32 temp_r0_3;
    u8 temp_r0_2;
    void *temp_r0;

    temp_r0 = func_0208f3b0();
    func_0208ee60(temp_r0, 0x6B80, 0xB);
    M2C_FIELD(temp_r0, s32 *, 0x68) = (s32) (arg0 + 0x3C);
    temp_r0_2 = M2C_FIELD(arg0, u8 *, 0x3B);
    switch (temp_r0_2) {                            /* irregular */
    case 1:
        temp_r0_3 = func_02084cf8();
        M2C_FIELD(temp_r0, s32 *, 0x60) = temp_r0_3;
        M2C_FIELD(temp_r0, s32 *, 0x64) = (s32) (temp_r0_3 >> 0x1F);
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 9;
        M2C_FIELD(temp_r0, s16 *, 0x34) = 0xA0;
        M2C_FIELD(temp_r0, s16 *, 0x36) = 0x58;
        return;
    case 2:
        M2C_FIELD(temp_r0, s32 *, 0x60) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x64) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x5C) = 0x10;
        M2C_FIELD(temp_r0, s16 *, 0x34) = 0xC0;
        M2C_FIELD(temp_r0, s16 *, 0x36) = 0x58;
        return;
    }
}

void func_ov006_02217e78(void *arg0) {
M2C_UNK func_020675e4(void *,void *,s32,s32); M2C_UNK func_02084d1c(s32); M2C_UNK func_020899fc(void *,s32,s32,void *); s32 func_020c9244(s32,s32); s32 func_020c9268(s32,s32); 
extern M2C_UNK data_ov006_02218dd4;
u8 sp0[64]; s32 x,y; void *p;
switch(M2C_FIELD(arg0,u8 *,0x3b)) {
case 1: func_02084d1c(M2C_FIELD(arg0,s32 *,0x3c)); return;
case 2: x=func_020c9244(M2C_FIELD(arg0,s32 *,0x3c),M2C_FIELD(arg0,s32 *,0x40)); y=func_020c9268(M2C_FIELD(arg0,s32 *,0x3c),M2C_FIELD(arg0,s32 *,0x40)); func_02084d1c(x); func_020675e4(sp0,&data_ov006_02218dd4,x,y); p=(void *)func_0208b564(arg0); func_020899fc(p,2,0xcc00,sp0); M2C_FIELD(p,s32 *,0x58)|=0x400; return;
}}

void func_ov006_02217f20(void *arg0) {
s32 func_02084cf8(); s32 func_02086980(s32); void *func_020c7e88(s32);
s32 i,j,k;
for(i=0;i<10;i++){
M2C_FIELD(arg0,s32 **,0x44)[i]=0;
M2C_FIELD(arg0,u16 **,0x48)[i]=0;
M2C_FIELD(arg0,u8 **,0x4c)[i]=0;
}
M2C_FIELD(arg0,s32 **,0x44)[0]=func_02084cf8();
M2C_FIELD(arg0,u32 *,0x34)=1; M2C_FIELD(arg0,u8 *,0x38)=1;
for(k=0;k<50;k++){
if(func_02086980(k)){
j=k+0xe1;
M2C_FIELD(arg0,s32 **,0x44)[M2C_FIELD(arg0,u32 *,0x34)]=M2C_FIELD(func_020c7e88(j),s32 *,0x10);
M2C_FIELD(arg0,u16 **,0x48)[M2C_FIELD(arg0,u32 *,0x34)]=j;
M2C_FIELD(arg0,u32 *,0x34)++;
M2C_FIELD(arg0,u8 *,0x38)++;
if(M2C_FIELD(arg0,u32 *,0x34)>=10)break;
}
}
func_020e3f88(M2C_FIELD(arg0,void **,0x44),M2C_FIELD(arg0,s32 *,0x54),(u8 *)arg0+0x34,arg0);
}

void func_ov006_02217ff8(void *a){
void *func_020c7e6c(s32);void *func_020c7e88(s32);s32 func_02084cf8(void);s32 func_020c8c6c(void *);s32 func_020c8b0c(void *,void *);
void *entry,*info;s32 j,owner,off,i,id,flag;void *q;
i=0;M2C_FIELD(a,u8 *,0x39)=0;M2C_FIELD(a,u8 *,0x3a)=0;
if((s32)M2C_FIELD(a,u8 *,0x38)<=0)return;
do{
id=M2C_FIELD(a,u16 **,0x48)[i];q=func_020c7e6c(id);info=func_020c7e88(id);
j=0;
if((u32)j<M2C_FIELD(a,u32 *,0x34)){do{off=j*0x310;
entry=M2C_FIELD(a,u8 **,0x54)+off;
owner=M2C_FIELD(entry,s32 *,4);
if(owner==func_02084cf8())flag=1;else flag=func_020c8c6c(entry+0x50)!=0;
if(flag==0 && M2C_FIELD(info,s32 *,0x10)==M2C_FIELD(entry,s32 *,0x60)){
if(func_020c8b0c(q,entry+0x10)==0)M2C_FIELD(a,u8 **,0x4c)[i]=2;
else{M2C_FIELD(a,u8 **,0x4c)[i]=1;M2C_FIELD(a,u16 **,0x50)[M2C_FIELD(a,u8 *,0x39)]=id;M2C_FIELD(a,u8 *,0x39)++;}
break;
}
j++;
}while((u32)j<M2C_FIELD(a,u32 *,0x34));}
if(M2C_FIELD(a,u8 *,0x39)>=3)return;
i++;
}while(i<(s32)M2C_FIELD(a,u8 *,0x38));
}

void func_ov006_02218128(void *p) {
void *func_020c7e88(s32); u32 i; u16 id; void *q; u32 flags; void *out; s32 value;
i=M2C_FIELD(p,u8 *,0x3a);
if(i>=M2C_FIELD(p,u8 *,0x39)){func_01ffa6fc(p);return;}
M2C_FIELD(p,u8 *,0x3a)=i+1;
id=M2C_FIELD(p,u16 **,0x50)[i]; func_020c7e6c(id); q=func_020c7e88(id);
flags=(M2C_FIELD(q,u32 *,0xc)>>29)<<8;
value=M2C_FIELD(q,s32 *,0x10); out=p+0x58;
if(M2C_FIELD(p,u8 *,0x3a)==M2C_FIELD(p,u8 *,0x39)) func_020e40e0(value,flags,out,p);
else func_020e4174(value,flags,out,p);
}

void func_ov006_022181a4(void *p) { s32 i; for(i=0;i<M2C_FIELD(p,u8 *,0x38);i++){u16 b=M2C_FIELD(p,u16 **,0x48)[i]; s32 a=M2C_FIELD(p,u8 **,0x4c)[i]; if(a==1)goto call; if(a!=2)continue; call: func_020868ac(b-0xe1,0);}}

