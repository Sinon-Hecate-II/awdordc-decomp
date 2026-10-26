/* 71 functions from 0x02091E04 to 0x02092DF4 (main), found by ds-decomp. */
#include "common.h"
extern u16 data_ov000_021aeef4[];
extern void **data_027e0058;

u8 func_02091e04(void) {
    void *func_02091da8();
    return M2C_FIELD(func_02091da8(), u8 *, 0x4E);
}

s32 func_02091e14(void) {
    void *func_02091da8();
    return M2C_FIELD(func_02091da8(), u8 *, 0x49);
}

u8 func_02091e24(void) {
    if (func_02091e14() == 2) {
        return 0U;
    }
    return M2C_FIELD(func_02091da8(), u8 *, 0x49);
}

void func_02091e44(void) {
    M2C_UNK func_02091e14();
    func_02091e14();
}

s8 func_02091e50(void) {
    s32 func_02091db4();
    if (func_02091db4() == 2) {
        return 2;
    }
    return M2C_FIELD(func_02091da8(), s8 *, 0x4D);
}

s32 func_02091e70(s32 arg0) {
    s32 func_02091db4();
    s32 temp_r0;
    u8 temp_r0_2;
    void *temp_r4;
    temp_r4 = (void *)func_02091f18(arg0);
    temp_r0 = func_02091db4();
    switch (temp_r0) {
    case 1:
        temp_r0_2 = M2C_FIELD(temp_r4, u8 *, 7);
        if (temp_r0_2 == 1) return 2;
        if (temp_r0_2 == 0) return 8;
        break;
    case 0:
    case 2:
        return 2;
    }
    return 0;
}

u16 func_02091ecc(u16 arg0) {
    extern void **data_027e0058;
    if (arg0 != 5) {
        return arg0;
    }
    return M2C_FIELD(*data_027e0058, u16 *, 0x52A4);
}

s32 func_02091ef0(void) {
    return (M2C_FIELD(func_02091da8(), u8 *, 0x4A) * 2) + 2;
}

s32 func_02091f08(void) {
    s32 func_02091ef0();
    return func_02091ef0() * 8;
}

s32 func_02091f18(s32 arg0) {
    s32 var_r4;

    var_r4 = arg0;
    if (var_r4 == 3) {
        var_r4 = func_02091e50();
    }
    return (var_r4 * 0xC) + func_02091da8();
}

void func_02091f40(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
}

void func_02091f5c(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_02091f78(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
}

void func_02091f94(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
}

void func_02091fb0(void) {

}

void (*func_02091fb4(u32 arg0))(void) {
    void func_02091f5c(void);
    void func_02091f78(void);
    switch (arg0) {
    case 0: return func_02091f40;
    case 1: return func_02091f5c;
    case 2: return func_02091f78;
    case 3: return func_02091f94;
    case 4: return func_02091fb0;
    default: return 0;
    }
}

s32 func_02092018(void *arg0) {
    s32 func_0209600c();
    if (func_0209600c() == 0) {
        M2C_FIELD(arg0, s16 *, 0xC) = (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC);
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_02092048(void *arg0) {
    s16 var_r0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), void (**)(void *), 4)(arg0);
    M2C_FIELD(arg0, void **, 4) = (void *)(M2C_FIELD(arg0, void **, 4) + 0x10);
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s16 func_02092084(void *arg0) {
    s16 var_r0;
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r1, M2C_UNK (**)(s32), 4)(M2C_FIELD(temp_r1, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020920c4(void *arg0) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02102a70;
    if (func_01ffa770(&data_02102a70) == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_020920e8(void *arg0) {
    M2C_UNK func_01ffa3dc(s32, s32);
    extern M2C_UNK data_02102a70;
    s32 temp_r0;
    temp_r0 = func_01ffa3dc((s32)&data_02102a70, 7);
    M2C_FIELD(arg0, void (**)(void *), 8) = func_020920c4;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), void (**)(s32), 4)(temp_r0);
    M2C_FIELD(arg0, void **, 4) = (void *)(M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_0209212c(void *arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 (**)(), 4)() != 0) {
        return 0;
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092160(void *arg0) {
    M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_02092180(void *arg0) {
    s32 func_02092048(void *);
    if (func_0209600c() == 0) {
        return func_02092048(arg0);
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_020921b4(void) {
    M2C_UNK func_020947d0();
    func_020947d0();
    return 0;
}

s32 func_020921c4(void) {
    return 0;
}

s32 func_020921cc(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, s8 **, 4) = (s8) M2C_FIELD(temp_r1, s32 *, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020921f0(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, s16 **, 4) = (s16) M2C_FIELD(temp_r1, s32 *, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092214(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, s32 **, 4) = M2C_FIELD(temp_r1, s32 *, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092238(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, u8 **, 4) = *M2C_FIELD(temp_r1, u8 **, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092260(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, u16 **, 4) = *M2C_FIELD(temp_r1, u16 **, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092288(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    *M2C_FIELD(temp_r1, s32 **, 4) = *M2C_FIELD(temp_r1, s32 **, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

void func_020922b0(void *arg0) {
    s32 func_0207b7c4();
    if (func_0207b7c4() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_020922cc(void *arg0) {
    s32 func_0209600c();
    M2C_UNK func_0207b764(s16, s16);
    M2C_UNK func_0207b774(s16, s16);
    void *temp_r1;

    if (func_0209600c() == 0) {
        temp_r1 = M2C_FIELD(arg0, void **, 4);
        if (M2C_FIELD(temp_r1, s32 *, 0xC) != 0) {
            func_0207b774(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s16 *, 0xA));
        } else {
            func_0207b764(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s16 *, 0xA));
        }
        M2C_FIELD(arg0, void (**)(void *), 8) = func_020922b0;
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_02092324(void *arg0) {
    M2C_UNK func_0207b744(s16, s16);
    M2C_UNK func_0207b754(s16, s16);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    if (M2C_FIELD(temp_r1, s32 *, 0xC) != 0) {
        func_0207b754(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s16 *, 0xA));
    } else {
        func_0207b744(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s16 *, 0xA));
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092364(void *arg0) {
s32 func_0209600c(void);
s32 func_0207b774(s16,s16);
s32 func_0207b764(s16,s16);
s32 i,limit; void *p,*entry; u8 (*entries)[14]; u32 bits;
if(!func_0209600c()){
p=M2C_FIELD(arg0,void **,4);
for(i=data_ov000_021aeef4[M2C_FIELD(p,s16 *,8)]+1;i<data_ov000_021aeef4[M2C_FIELD(p,s16 *,8)]+0x33;i++){
entries=(void *)((u8 *)*data_027e0058+0x59a4);
entry=entries[i];
bits=(u32)(M2C_FIELD(entry,u8 *,0)<<26)>>26;
if(bits && (M2C_FIELD(p,s16 *,10)==0 || bits==M2C_FIELD(p,s16 *,10))){
if(M2C_FIELD(p,s32 *,12))func_0207b774(M2C_FIELD(entry,u8 *,1),M2C_FIELD(entry,u8 *,2));
else func_0207b764(M2C_FIELD(entry,u8 *,1),M2C_FIELD(entry,u8 *,2));
M2C_FIELD(arg0,void **,8)=(void *)func_020922b0;
break;
}
}
}
M2C_FIELD(arg0,s32 *,4)+=16;
return 0;
}

s32 func_02092434(void *arg0) {
    M2C_UNK func_01ffa3dc(s32, s32);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    func_01ffa3dc(M2C_FIELD(temp_r1, s32 *, 4), M2C_FIELD(temp_r1, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092460(void *arg0) {
    if (func_01ffa770(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4)) != 0) {
        return 0;
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092494(void *arg0) {
    s32 func_01ffa7b4(s32);
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    void *temp_r5;
    u8 var_r1;

    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    if (func_01ffa7b4(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4)) != 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    gCur3DSpriteEngine = temp_r5;
    if (var_r1 != 0) {
        return 0;
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020924f8(void *arg0) {
    s32 func_01ffa7b4(s32);
    extern void *data_027e00c4;
    extern void *gCur3DSpriteEngine;
    void *temp_r5;
    u8 var_r1;

    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    if (func_01ffa7b4(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4)) != 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    gCur3DSpriteEngine = temp_r5;
    if (var_r1 != 0) {
        return 0;
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_0209255c(void *arg0) {
    s32 func_01ffa7b4(s32);
    if (func_01ffa7b4(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 4)) != 0) {
        return 0;
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092590(void *arg0) {
    M2C_UNK func_020d8f1c(s16, M2C_UNK);
    func_020d8f1c(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8), 0);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020925bc(void *arg0) {
    extern M2C_UNK data_02168f14;
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(&data_02168f14, s16 *, 4) = (s16) M2C_FIELD(temp_r1, s32 *, 0xC);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020925e4(void *arg0) {
    extern M2C_UNK data_02168f14;
    M2C_FIELD(&data_02168f14, s16 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02092608(void *arg0) {
extern void **data_027e0058;
s32 func_020a6658(s32,s32,s32,s32);void func_020cfd28(s32);
void *p=M2C_FIELD(arg0,void **,4);
func_020cfd28(func_020a6658(M2C_FIELD(p,s16 *,8),M2C_FIELD(p,s16 *,10),M2C_FIELD(p,s32 *,12),M2C_FIELD(*data_027e0058,u16 *,0x52a4)));
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02092654(void *arg0) {
    M2C_UNK func_020947ac();
    func_020947ac();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02092674(void *arg0) {
    M2C_UNK func_02094798();
    func_02094798();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 func_02092694(void *arg0) {
extern M2C_UNK data_02157fe8;
s32 func_020947d0();
s32 n=((s32)arg0-(s32)&data_02157fe8)/24;
u8 i=0;
do {if(i!=n)func_020947d0((u8 *)&data_02157fe8+i*24);i++;}while(i<8);
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

void func_02092888(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102a58;
    func_01ffa42c(&data_02102a58, arg0);
}

void func_020928a0(void *arg0) {
    s32 func_0209bf28();
    if (func_0209bf28() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_020928bc(M2C_UNK arg0,s32 arg1) {
s32 func_020926f8(s32);void func_020928a0(void *);
s32 v=func_020926f8(arg1);
if(v==0)M2C_FIELD(arg0,void (**)(void *),8)=func_020928a0;
M2C_FIELD(arg0,s32 *,4)+=16;return (s16)v;
}

void func_020928f4(void *arg0) {
    func_020928bc(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
}

void func_02092908(M2C_UNK arg0) {
    M2C_UNK func_020928bc(M2C_UNK, M2C_UNK);
    func_020928bc(arg0, -1);
}

s32 func_02092918(void *arg0) {
s32 func_0209600c();M2C_UNK func_02097bac(M2C_UNK);M2C_UNK func_0209707c();
s32 v;
if(func_0209600c()!=0)v=1;
else {func_02097bac(3);func_0209707c();v=0;}
M2C_FIELD(arg0,s32 *,4)+=16;return (s16)v;
}

s32 func_02092958(void *arg0) {
    M2C_UNK func_02086608(u8);
    func_02086608((u8) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_02092984(void *arg0) {
    M2C_UNK func_02086658(u8);
    func_02086658((u8) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_020929b0(void *arg0) {
M2C_UNK func_020867dc(u8,M2C_UNK);M2C_UNK func_0208fe30(s32);M2C_UNK func_020ae124(u8);
s32 func_020ae1a4();s32 func_020d8db0();s32 func_020d8f4c();M2C_UNK func_020d8f1c(s16,s32);
u8 v=(u8)M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,8);
void *p;
func_020867dc(v,1);p=M2C_FIELD(arg0,void **,4);
if(M2C_FIELD(p,s32 *,12)==0){M2C_FIELD(arg0,void **,4)=p+16;return 1;}
if(func_020d8db0()!=0)return 0;
if(func_020d8f4c()==2){if(func_020ae1a4()==0)return 0;func_020ae124(v);}
else func_020d8f1c(2,v);
func_0208fe30(0x121);M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02092a54(void *arg0) {
extern M2C_UNK data_02168f14;
M2C_FIELD(&data_02168f14,s16 *,0)=(s16)(M2C_FIELD(&data_02168f14,u16 *,0)|0x400);
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_02092a7c(void *arg0) {
extern M2C_UNK data_02168f14;
M2C_FIELD(&data_02168f14,s16 *,0)=(s16)(M2C_FIELD(&data_02168f14,u16 *,0)&~0x400);
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_02092aa4(void *arg0) {
extern void **data_027e0058;
if(M2C_FIELD(*data_027e0058,u16 *,0x52b0)!=12)return 0;
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_02092adc(void *arg0) {
extern void **data_027e0058;
if(M2C_FIELD(*data_027e0058,u16 *,0x52b0)==12)return 0;
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

void func_02092b14(void *arg0) {
extern void **data_027e0058;
void *p=*data_027e0058;
s32 v;
if(M2C_FIELD(p,u16 *,0x52b0)!=12)return;
v=M2C_FIELD(arg0,s16 *,0x12);
if(v>=0 && v!=M2C_FIELD(p,u16 *,0x52a2))return;
if(M2C_FIELD(p,u16 *,0x52a4)==M2C_FIELD(arg0,u8 *,0x11))M2C_FIELD(arg0,s32 *,8)=0;
}

s32 func_02092b68(void *arg0) {
void func_02092b14(void *);
M2C_FIELD(arg0,s8 *,0x11)=M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,8);
M2C_FIELD(arg0,s16 *,0x12)=M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,10);
M2C_FIELD(arg0,void (**)(void *),8)=func_02092b14;
func_02092b14(arg0);
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

void func_02092bac(void *arg0) {
extern void **data_027e0058;
int func_020d1a74(u8);
if(M2C_FIELD(*data_027e0058,u16 *,0x52b0)!=12)return;
if(!func_020d1a74(M2C_FIELD(arg0,u8 *,0x11)))return;
if(M2C_FIELD(*data_027e0058,u16 *,0x52a4)==1)M2C_FIELD(arg0,s32 *,8)=0;
}

s32 func_02092c08(void *arg0) {
void func_02092bac(void *);
M2C_FIELD(arg0,s8 *,0x11)=M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,8);
M2C_FIELD(arg0,void (**)(void *),8)=func_02092bac;
func_02092bac(arg0);M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02092c40(void *arg0) {
extern u16 *data_02101e84;
void *p=M2C_FIELD(arg0,void **,4);
u32 keys=*data_02101e84;
u32 mask=M2C_FIELD(p,u32 *,12);
void (*callback)(u32)=M2C_FIELD(p,void (**)(u32),4);
if(keys&mask)callback(mask);else return 0;
func_02094798();M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02092c94(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 1;
}

s32 *func_02092ca8(s32 **arg0,s32 arg1) {
s32 *p=*arg0;
while(*p!=7){if(*p==29 && p[3]==arg1)return p;p+=4;}
return NULL;
}

s32 func_02092cdc(void *arg0) {
u8 flag;
void *p=M2C_FIELD(arg0,void **,4);
s32 (*callback)(void)=M2C_FIELD(p,s32 (**)(void),4);
void *next;
if(callback){if(callback())flag=1;else flag=0;p=M2C_FIELD(arg0,void **,4);if(M2C_FIELD(p,s16 *,8))flag=(u8)!flag;}else flag=1;
if(flag){next=func_02092ca8(arg0,M2C_FIELD(p,s32 *,12));if(next)M2C_FIELD(arg0,void **,4)=next;else M2C_FIELD(arg0,s32 *,4)+=16;}else M2C_FIELD(arg0,s32 *,4)+=16;
return 1;
}

s32 func_02092d70(void *arg0) {
s32 func_02086b40(s16);
u8 flag;
void *p,*next;
if(func_02086b40(M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,8)))flag=1;else flag=0;
p=M2C_FIELD(arg0,void **,4);
if(M2C_FIELD(p,s16 *,10)){if(flag)flag=0;else flag=1;}
if(flag){next=func_02092ca8(arg0,M2C_FIELD(p,s32 *,12));if(next)M2C_FIELD(arg0,void **,4)=next;else M2C_FIELD(arg0,s32 *,4)+=16;}else M2C_FIELD(arg0,s32 *,4)+=16;
return 1;
}

