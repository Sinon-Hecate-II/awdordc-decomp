/* 57 functions from 0x02093D9C to 0x02094D8C (main), found by ds-decomp. */
#include "common.h"

void *func_02091da8(void);

s32 func_02093d9c(void *arg0) {
    s32 func_02091e14();
    M2C_UNK func_020d4bd4();
    M2C_UNK func_020d9394();
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
        func_020d4bd4();
        break;
    case 1:
        func_020d9394();
        break;
    case 2:
        func_020d4bd4();
        func_020d9394();
        break;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02093e2c(void *arg0) {
    M2C_UNK func_020a48ec(u8, u8, u8, u8, s32, s32, s32, s32);
    s16 temp_ip;
    s16 temp_r2;
    void *temp_lr;

    temp_lr = M2C_FIELD(arg0, void **, 4);
    temp_ip = M2C_FIELD(temp_lr, s16 *, 0xA);
    temp_r2 = M2C_FIELD(temp_lr, s16 *, 8);
    func_020a48ec((u8) temp_r2, (u8) (temp_r2 >> 8), (u8) temp_ip, (u8) (temp_ip >> 8), 3, 0, 0, M2C_FIELD(temp_lr, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093e94(void *arg0) {
    s32 func_020a4678(u8, u8, M2C_UNK);
    M2C_UNK func_020a4a68();
    s16 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8);
    if (func_020a4678((u8) temp_r0, (u8) (temp_r0 >> 8), 3) != 0) {
        func_020a4a68();
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093ed8(void *arg0) {
    M2C_UNK func_0208fa00(s32, M2C_UNK);
    s16 temp_ip;
    s32 temp_r5;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 4);
    temp_ip = M2C_FIELD(temp_r0, s16 *, 8);
    temp_r5 = M2C_FIELD(temp_r0, s32 *, 0xC);
    func_020a48ec((u8) temp_ip, (u8) (temp_ip >> 8), 1, 1, 9, 0, 0, temp_r5);
    if (temp_r5 == 6) {
        func_0208fa00(0x10025, 0x16);
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093f50(void *arg0) {
    s16 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8);
    if (func_020a4678((u8) temp_r0, (u8) (temp_r0 >> 8), 9) != 0) {
        func_020a4a68();
    }
    func_0208fa28();
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093f98(void *arg0) {
    M2C_UNK func_0208fa28();
    func_0208fa28();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02093fb8(void *arg0) {
    M2C_UNK func_020a4af0(s16, s16, s32);
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 4);
    func_020a4af0(M2C_FIELD(temp_r2, s16 *, 8), M2C_FIELD(temp_r2, s16 *, 0xA), M2C_FIELD(temp_r2, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093fe8(void *arg0) {
 M2C_UNK func_020a4b48(u8,u8,s32,u8,u8);
 M2C_UNK func_020a4b94(u8,u8,s32,u8,u8);
 s16 temp_ip, temp_r2;
 void *temp_lr;
 u8 t0,t1,t2,t3;
 s32 val;
 temp_lr=M2C_FIELD(arg0,void **,4);
 temp_ip=M2C_FIELD(temp_lr,s16 *,0xA);
 temp_r2=M2C_FIELD(temp_lr,s16 *,8);
 t1=(u8)(temp_r2>>8);
 t2=(u8)temp_ip;
 t0=(u8)temp_r2;
 t3=(u8)(temp_ip>>8);
 val=M2C_FIELD(temp_lr,s32 *,0xC);
 if(M2C_FIELD(temp_lr,s32 *,4)==0) func_020a4b48(t0,t1,val,t2,t3);
 else func_020a4b94(t0,t1,val,t2,t3);
 M2C_FIELD(arg0,void **,4)+=0x10;
 return 1;
}

s32 func_02094050(void *arg0) {
 M2C_UNK func_020a4be0(u8,u8,s32,u8,u8);
 M2C_UNK func_020a4c30(u8,u8,s32,u8,u8);
 s16 temp_ip, temp_r2;
 void *temp_lr;
 u8 t0,t1,t2,t3;
 s32 val;
 temp_lr=M2C_FIELD(arg0,void **,4);
 temp_ip=M2C_FIELD(temp_lr,s16 *,0xA);
 temp_r2=M2C_FIELD(temp_lr,s16 *,8);
 t1=(u8)(temp_r2>>8);
 t2=(u8)temp_ip;
 t0=(u8)temp_r2;
 t3=(u8)(temp_ip>>8);
 val=M2C_FIELD(temp_lr,s32 *,0xC);
 if(M2C_FIELD(temp_lr,s32 *,4)==0) func_020a4be0(t0,t1,val,t2,t3);
 else func_020a4c30(t0,t1,val,t2,t3);
 M2C_FIELD(arg0,void **,4)+=0x10;
 return 1;
}

s32 func_020940b8(void *arg0) {
    M2C_UNK func_020d2bc0(s16, s32);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    func_020d2bc0(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020940e4(void *arg0) {
    M2C_UNK func_02086680(s32);
    M2C_UNK func_02095f94();
    func_02086680(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
    func_02095f94();
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02094110(void *arg0) {
    M2C_UNK func_02095fc0();
    func_02095fc0();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02094130(void *arg0) {
    M2C_UNK func_02096b50(s32);
    M2C_UNK func_02096b6c(s32);
    M2C_UNK func_02096b88(s32);
    s16 temp_r0;
    void *temp_r1;

    if (func_0209600c() == 0) {
        temp_r1 = M2C_FIELD(arg0, void **, 4);
        temp_r0 = M2C_FIELD(temp_r1, s16 *, 8);
        switch (temp_r0) {                          /* irregular */
        case 0:
            func_02096b50(M2C_FIELD(temp_r1, s32 *, 0xC));
            break;
        case 1:
            func_02096b6c(M2C_FIELD(temp_r1, s32 *, 0xC));
            break;
        case 2:
            func_02096b88(M2C_FIELD(temp_r1, s32 *, 0xC));
            break;
        }
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_0209419c(void *arg0) {
    extern M2C_UNK data_02168f14;
    M2C_FIELD(&data_02168f14, s32 *, 0xC) = (s32) (M2C_FIELD(&data_02168f14, s32 *, 0xC) | (1 << (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC)));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020941d4(void *arg0) {
    extern M2C_UNK data_02168f14;
    M2C_FIELD(&data_02168f14, s32 *, 0xC) = (s32) (M2C_FIELD(&data_02168f14, s32 *, 0xC) & (-1 ^ (1 << (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC))));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02094214(void *arg0) {
    M2C_UNK func_0207843c(s32, s32, s32, s32);
    s16 func_0207f460(s32);
    extern s32 *gCurrentMap;

    s16 packed;
    s32 base;
    s32 x, value;
    u32 y;
    void *cmd;

    cmd = M2C_FIELD(arg0, void **, 4);
    packed = M2C_FIELD(cmd, s16 *, 8);
    value = M2C_FIELD(cmd, s32 *, 0xC);
    y = (u8)(packed >> 8);
    base = *gCurrentMap;
    x = (u8)packed;
    M2C_FIELD(base + (x + M2C_FIELD(base + y * 2, u16 *, 0x3758)), s8 *, 0x1420) = value;
    base = *gCurrentMap;
    M2C_FIELD(base + (x + M2C_FIELD(base + y * 2, u16 *, 0x3758)) * 2, s16 *, 0xA10) = func_0207f460(value);
    func_0207843c(x - 1, y - 1, x + 1, y + 1);
    M2C_FIELD(arg0, void **, 4) += 16;
    return 1;
}

s32 func_020942b0(void *arg0) {
    M2C_UNK func_0209600c();
    s32 temp_r0;

    if (func_0209600c() != 0) {
        do {
            temp_r0 = *M2C_FIELD(arg0, s32 **, 4);
            switch (temp_r0) {
            case 0x6B:
                return 1;
            case 7:
                return 1;
            default:
                M2C_FIELD(arg0, s32 **, 4) += 4;
                break;
            }
        } while (1);
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02094310(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02094324(void *arg0) {
    if (func_0209600c() != 0) {
        func_02095ff8(0);
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02094354(void *arg0) {
    if (func_0209600c() == 0) {
        func_02095ff8(0);
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02094384(void *arg0) {
    M2C_UNK func_02095ff8(M2C_UNK);
    func_02095ff8(3);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

void func_020943a8(s8 arg0) {
    void *func_02091da8();
    M2C_FIELD(func_02091da8(), s8 *, 0x4D) = arg0;
}

void func_020943bc(s8 arg0) {
    void *func_02091da8(void);
    M2C_FIELD(func_02091da8(), s8 *, 0x49) = arg0;
}

void func_020943d0(void) {
    func_020943bc(1);
}

void func_020943e0(s8 arg0) {
    void *func_02091da8(void);
    M2C_FIELD(func_02091da8(), s8 *, 0x48) = arg0;
}

void func_020943f4(s32 arg0,s8 arg1) { void *func_02091da8(); M2C_FIELD(func_02091da8()+arg0,s8 *,0x44)=arg1; }

void func_02094410(s8 arg0) { void *func_02091da8(); M2C_FIELD(func_02091da8(),s8 *,0x4E)=arg0; }

void func_02094424(void) {
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c8;
    extern s32 data_027e00c4;
    M2C_UNK func_02091db4(void);
    M2C_UNK func_02091e24(void);
    void *func_02091da8(void);
    M2C_UNK func_02097128(M2C_UNK);
    M2C_UNK func_0209713c(M2C_UNK);
    M2C_UNK func_02097150(M2C_UNK, M2C_UNK);
    M2C_UNK func_02097164(M2C_UNK, M2C_UNK);
    M2C_UNK func_02097178(M2C_UNK, M2C_UNK);
    M2C_UNK func_020971c0(M2C_UNK, M2C_UNK);

    s32 saved;
    s32 i;
    s32 j;
    s32 base;

    saved = gCur3DSpriteEngine;
    for (i = 0; i < 2; i = i + 1) {
        if (i == 0) {
            gCur3DSpriteEngine = data_027e00c8;
        } else {
            gCur3DSpriteEngine = data_027e00c4;
        }

        if (((func_02091e24() != 0) || (gCur3DSpriteEngine == data_027e00c8)) &&
            ((func_02091e24() != 1) || (gCur3DSpriteEngine == data_027e00c4)) &&
            ((func_02091e24() != 3) || (gCur3DSpriteEngine == saved))) {
            func_02097128(2);
            func_0209713c(1);

            M2C_FIELD(M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0), u16 *, 0x3A) = 0;
            M2C_FIELD(M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0), u16 *, 0x42) = 0;

            switch (func_02091db4()) {
            case 0:
            case 1: {
                void *da;
                da = func_02091da8();
                M2C_FIELD(da, void **, 0) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0);
                da = func_02091da8();
                M2C_FIELD(da, void **, 0xC) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0);
                da = func_02091da8();
                M2C_FIELD(da, void **, 0x18) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0x480);
                break;
            }
            case 2: {
                void *da;
                da = func_02091da8();
                M2C_FIELD(da, void **, 0) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0x40);
                da = func_02091da8();
                M2C_FIELD(da, void **, 0xC) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0x240);
                da = func_02091da8();
                M2C_FIELD(da, void **, 0x18) = (void *)((s8 *)M2C_FIELD((void *)gCur3DSpriteEngine, void **, 0x24) + 0x440);
                break;
            }
            }

            base = 0x124;
            for (j = 0; j < 3; j = j + 1) {
                func_02097150(j, base);
                func_02097164(j, 0);
                func_02097178(j, 0);
                func_020971c0(j, 0);
                base = base + 0x80;
            }
        }
    }

    gCur3DSpriteEngine = saved;
}

void func_020947ac(void);
void func_020945f8(void) {
 extern M2C_UNK data_02157fe8;
 void *func_02091f18(s32);
 s16 i; u8 *p;
 M2C_FIELD(func_02091da8(),u8*,0x4b)=0;
 p=(u8*)&data_02157fe8;
 for(i=0;i<8;i++,p+=0x18)*(s32*)p=0;
 for(i=0;i<8;) { p=func_02091da8(); p+=(u32)i*4; i++; M2C_FIELD(p,s32*,0x24)=0; }
 func_02086ac0();func_020947ac();func_02095fd4();
 for(i=0;i<3;i++)M2C_FIELD(func_02091f18(i),s16*,8)=0;
 for(i=0;i<2;i++)func_020943f4(i,2);
 func_020943a8(-1);func_020943bc(3);func_020943e0(0);func_02094410(0);func_02094424();
}

s32 func_020946d0(void) {
 extern M2C_UNK data_02157fe8;
 s32 i;
 u8 *p;
 p=(u8 *)&data_02157fe8;i=0;
 do {
 if(M2C_FIELD(p,s32 *,0)) return 1;
 i++;p+=24;
 }while(i<8);
 return 0;
}

u8 func_02094704(void) {
    s32 func_02094724();
    u8 var_r0;

    if (func_02094724() != -1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_02094724(s32 value) {
 extern M2C_UNK data_02157fe8;
 s32 i;
 u8 *p;
 p=(u8 *)&data_02157fe8;i=0;
 do {
 if(M2C_FIELD(p,s32 *,0)==value) return i;
 i++;p+=24;
 }while(i<8);
 return -1;
}

void func_02094758(void) {
 void *func_02091da8(void);
 void *p=func_02091da8();
 M2C_FIELD(p,s8 *,0x4B)++;
}

void func_02094770(void) {
 void *func_02091da8(void);
 void *p=func_02091da8();
 M2C_FIELD(p,s8 *,0x4B)--;
}

u8 func_02094788(void) {
    void *func_02091da8();
    return M2C_FIELD(func_02091da8(), u8 *, 0x4B);
}

void func_02094798(void) {
    M2C_FIELD(func_02091da8(), s8 *, 0x47) = 1;
}

void func_020947ac(void) {
    M2C_FIELD(func_02091da8(), s8 *, 0x47) = 0;
}

u8 func_020947c0(void) {
    return M2C_FIELD(func_02091da8(), u8 *, 0x47);
}

void func_020947d0(s32 *arg0) {
    s32 func_020946d0();
    void func_02094860(void);
    M2C_UNK func_02095fd4();
    M2C_UNK func_020d472c();
    if (*arg0 == 0) {
        return;
    }
    *arg0 = 0;
    if (func_020946d0() == 0) {
        func_020947ac();
        func_02095fd4();
        func_02094860();
    }
    func_020d472c();
}

void func_02094808(s32 value) {
   void *func_020948c4(s32);
   s32 i;
   if(!func_020946d0()) {func_020948c4(value);return;}
   for(i=0;i<8;i++) {
   if(!M2C_FIELD(func_02091da8()+((u32)i*4),s32 *,0x24)) {
   M2C_FIELD(func_02091da8()+((u32)i*4),s32 *,0x24)=value;
   return;
   }}
}

void func_02094860(void) {
   void *func_020948c4(s32);
 s32 i;
 void *p;
 if(!M2C_FIELD(func_02091da8(),s32 *,0x24)) return;
 func_020948c4(M2C_FIELD(func_02091da8(),s32 *,0x24));
 i=0;
 do {
 p=func_02091da8();
 M2C_FIELD(p+((u32)i*4),s32 *,0x24)=M2C_FIELD(func_02091da8()+((u32)(i+1)*4),s32 *,0x24);
 i++;
 }while(i<7);
 M2C_FIELD(func_02091da8()+((u32)i*4),s32 *,0x24)=0;
}

void *func_020948c4(s32 arg0) {
    s32 func_02094724(s32);
    void func_020943a8(s8);
    void func_020943bc(s8);
    void func_020943e0(s8);
    void func_02094410(s8);
    M2C_UNK func_02095fd4(void);
    void func_02094798(void);
    void func_020d4704(void);
    extern M2C_UNK data_02157fe8;
    extern M2C_UNK data_02157fec;
    extern M2C_UNK data_02157ff0;
    extern M2C_UNK data_02157ff4;
    s32 temp_ip;
    s16 temp_r0;

    temp_r0 = (s16)func_02094724(0);
    if (temp_r0 == -1) {
        return NULL;
    }
    func_020943a8(-1);
    func_020943bc(3);
    func_020943e0(0);
    func_02094410(0);
    func_02095fd4();
    func_02094798();
    func_020d4704();
    temp_ip = (s32)temp_r0 * (s32)0x18;
    *(s32 *)((u8 *)&data_02157fe8 + temp_ip) = arg0;
    *(s32 *)((u8 *)&data_02157ff0 + temp_ip) = 0;
    *(s32 *)((u8 *)&data_02157fec + temp_ip) = arg0;
    *(u16 *)((u8 *)&data_02157ff4 + temp_ip) = 0;
    return (void *)((u8 *)&data_02157fe8 + temp_ip);
}

void func_02094958(void *arg0) {
    s32 func_02096064(void);
    extern void *data_02102b50[];
    void **p;
    s32 (*fn)(void *);
    s32 idx;

    if (M2C_FIELD(arg0, s32 *, 0) == 0) {
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0xC) != 0) {
        s32 temp;
        if (func_02096064() != 0) {
            temp = 0;
        } else {
            temp = M2C_FIELD(arg0, u16 *, 0xC) - 1;
        }
        M2C_FIELD(arg0, u16 *, 0xC) = (u16) temp;
        if (M2C_FIELD(arg0, u16 *, 0xC) != 0) {
            return;
        }
    }
    if (M2C_FIELD(arg0, s32 *, 8) != 0) {
        return;
    }
    if (M2C_FIELD(arg0, void **, 4) == NULL) {
        return;
    }
    for (;;) {
        p = M2C_FIELD(arg0, void **, 4);
        idx = *(s32 *) p;
        fn = (s32 (*)(void *)) data_02102b50[idx];
        if (fn == 0) {
            M2C_FIELD(arg0, void **, 4) = (void *) ((u8 *) M2C_FIELD(arg0, void **, 4) + 0x10);
        } else {
            s32 result = fn(arg0);
            if (!result) {
                return;
            }
        }
    }
}

void func_020949f8(void) {
    s32 func_0207b7c4();
    void func_02094958(void *);
    s32 func_020d8db0();
    extern M2C_UNK data_02157fe8;
    M2C_UNK (*temp_r1)(void *);
    u8 *var_r4;
    s32 var_r5;

    if (func_020946d0() == 0) {
        return;
    }
    if (func_02094788() != 0) {
        return;
    }
    if (func_0207b7c4() != 0) {
        return;
    }
    if (func_020d8db0() != 0) {
        return;
    }
    var_r4 = (u8 *) &data_02157fe8;
    var_r5 = 0;
    do {
        if (M2C_FIELD(var_r4, s32 *, 0) != 0) {
            temp_r1 = M2C_FIELD(var_r4, M2C_UNK (**)(void *), 8);
            if (temp_r1 != NULL) {
                temp_r1(var_r4);
            }
            func_02094958(var_r4);
        }
        var_r5 += 1;
        var_r4 += 0x18;
    } while (var_r5 < 8);
}

void func_02094a74(M2C_UNK arg0) {
    s32 func_0209600c();
    M2C_UNK func_0209776c(M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_0209776c(arg0);
}

void func_02094a94(s32 arg0) {
    void *func_02091f18(s32);
    M2C_UNK func_0209787c(s32);
    s32 var_r4;

    if (func_0209600c() != 0) {
        var_r4 = 0;
        do {
            if (M2C_FIELD(func_02091f18(var_r4), s16 *, 8) != 0) {
                func_0209787c(var_r4);
            }
            var_r4 += 1;
        } while (var_r4 < 3);
        return;
    }
    if (M2C_FIELD(func_02091f18(arg0), s16 *, 8) == 0) {
        return;
    }
    func_0209787c(arg0);
}

void func_02094af8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02097214(M2C_UNK, M2C_UNK, M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_02097214(arg0, arg1, arg2);
}

void func_02094b28(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02097aa8(M2C_UNK, M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_02097aa8(arg0, arg1);
}

void func_02094b50(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02097178(M2C_UNK, M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_02097178(arg0, arg1);
}

void func_02094b78(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_020971c0(M2C_UNK, M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_020971c0(arg0, arg1);
}

void func_02094ba0(M2C_UNK arg0) {
    M2C_UNK func_02097bac(M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_02097bac(arg0);
}

void func_02094bc0(M2C_UNK arg0) {
    M2C_UNK func_02097280(M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_02097280(arg0);
}

void func_02094be0(M2C_UNK arg0) {
    M2C_UNK func_02097348(M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_02097348(arg0);
}

void func_02094c00(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_02097410(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_02097410(arg0, arg1, arg2, arg3);
}

void func_02094c38(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02097414(M2C_UNK, M2C_UNK, M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_02097414(arg0, arg1, arg2);
}

void func_02094c68(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0209747c(M2C_UNK, M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_0209747c(arg0, arg1);
}

/* Builds a battle action entry for the given slot and submits it. */
void func_02094c90(s32 slot, s32 arg1) {
 extern s32 gCur3DSpriteEngine;
 s32 func_0209600c(); s32 func_020979a4(); s32 func_02091e50(); s32 func_02091e70();
 void *func_02091f18(s32);
 s32 value; void *ptrA,*ptrB,*ptrC,*ptrD;
 if(func_0209600c()!=0)return;
 if(func_020979a4(slot)!=1)return;
 func_02097cb8(func_02091e50());
 if(func_02091e50()<0)return;
 if(func_02091e50()>=3)return;
 value=func_02091e70(3);
 ptrA=func_02091da8();ptrB=func_02091da8();ptrC=func_02091f18(3);ptrD=func_02091f18(3);
 func_0209bee0(arg1,(s16)value,1,M2C_FIELD(ptrA,u8*,0x4c),M2C_FIELD((u8*)gCur3DSpriteEngine+M2C_FIELD(ptrB,u8*,0x4c)*4,s32*,0xc),M2C_FIELD(ptrC,s32*,0),(u16)((M2C_FIELD(ptrD,u8*,6)&15)<<12),M2C_FIELD(func_02091f18(3),u16*,4));
}

