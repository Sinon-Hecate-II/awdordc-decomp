/* 37 functions from 0x02187590 to 0x0218851C (ov001), found by ds-decomp. */
#include "common.h"

void func_ov001_021878b4(s16 arg0) {
    extern s16 *data_ov001_02193e1c;
    *data_ov001_02193e1c = arg0;
}

u16 func_ov001_021878c8(void) {
    extern s16 *data_ov001_02193e1c;
    return *(u16 *)data_ov001_02193e1c;
}

u16 func_ov001_021878dc(s32 arg0) {
    extern s16 *data_ov001_02193e1c;
    extern struct { u16 *ptrs[6]; } data_ov001_02190c68;
    data_ov001_02190c68.ptrs[0] = (u16 *)data_ov001_02193e1c + 1;
    data_ov001_02190c68.ptrs[1] = (u16 *)data_ov001_02193e1c + 2;
    data_ov001_02190c68.ptrs[2] = (u16 *)data_ov001_02193e1c + 3;
    data_ov001_02190c68.ptrs[3] = (u16 *)data_ov001_02193e1c + 4;
    data_ov001_02190c68.ptrs[4] = (u16 *)data_ov001_02193e1c + 5;
    data_ov001_02190c68.ptrs[5] = (u16 *)data_ov001_02193e1c + 6;
    return **(u16 **)((s32)&data_ov001_02190c68 + arg0 * 4);
}

s32 func_ov001_02187934(s32 arg0) {
    void *func_0200751c(s32);
    void func_02007530(void *);
    s32 func_02008048(void *, void *, s32);
    extern s16 *data_ov001_02193e1c;
    u16 buf[7];
    u16 mask;
    s16 *gp;
    void *r;
    r = func_0200751c(arg0);
    gp = data_ov001_02193e1c;
    mask = (u16)(1 << arg0);
    if (!((u16)gp[1] & mask)) {
        func_02007530(r);
        return 0;
    }
    func_02008048(gp, buf, 0xE);
    func_02007530(r);
    if (buf[2] & mask) return 2;
    if (buf[3] & mask) return 3;
    if (buf[4] & mask) return 4;
    if (buf[5] & mask) return 5;
    if (buf[6] & mask) return 6;
    return 1;
}

s32 func_ov001_021879fc(s32 arg0) {
    extern s16 *data_ov001_02193e1c;
    if (!((u16)data_ov001_02193e1c[1] & (1 << arg0))) return 0;
    return (arg0 - 1) * 0x1E + (s32)((u8 *)data_ov001_02193e1c + 0xE);
}

u16 func_ov001_02187a30(u8 *arg0) {
    extern s16 *data_ov001_02193e1c;
    u8 *base;
    u16 i;
    s32 offset;
    u8 *entry;
    i = 1;
    base = (u8 *)data_ov001_02193e1c + 0x24;
    do {
        if ((u16)data_ov001_02193e1c[1] & (1 << i)) {
            offset = (i - 1) * 0x1E;
            entry = base + offset;
            if (arg0[0] == entry[0] && arg0[1] == entry[1] && arg0[2] == entry[2] && arg0[3] == entry[3] && arg0[4] == entry[4] && arg0[5] == entry[5]) {
                return M2C_FIELD((u8 *)data_ov001_02193e1c + offset, u16 *, 0x2A);
            }
        }
        i++;
    } while ((u32)i < 2);
    return 0;
}

void func_ov001_02187ad8(void *arg0) {
    extern M2C_UNK data_ov001_02193e20;
    M2C_FIELD(&data_ov001_02193e20, void **, 4) = arg0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 0x13A8) = 0;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 0x13AC) = 0;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 0x13B0) = 0;
}

void func_ov001_02187b14(s32 arg0) {
    extern M2C_UNK data_ov001_02193e20;
    extern s32 data_ov001_021914b0[];
    extern M2C_UNK data_ov001_02191590;
    extern M2C_UNK data_ov001_02191598;
    if (M2C_FIELD(&data_ov001_02193e20, void (**)(s32, void *, s32), 0) != NULL) {
        M2C_FIELD(&data_ov001_02193e20, void (**)(s32, void *, s32), 0)(0x08000000, &data_ov001_02191590, data_ov001_021914b0[M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 0x40)]);
    }
    M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 0x40) = arg0;
    if (M2C_FIELD(&data_ov001_02193e20, void (**)(s32, void *, s32), 0) == NULL) return;
    M2C_FIELD(&data_ov001_02193e20, void (**)(s32, void *, s32), 0)(0x08000000, &data_ov001_02191598, data_ov001_021914b0[M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 0x40)]);
}

s32 func_ov001_02187b90(arg0)
s32 arg0;
{
extern M2C_UNK data_ov001_02193e20;
void *p = M2C_FIELD(&data_ov001_02193e20, void **, 4);
if ((u32)(M2C_FIELD(p, s32 *, 0x40) - 9) > 1) M2C_FIELD(p, s32 *, 0x54) = arg0;
}

s32 func_ov001_02187bb0(void) {
s32 func_020122ec(void *, void *);
void func_ov001_02187bf4(void *);
extern M2C_UNK data_ov001_02193e20;
func_ov001_02187b14(3);
if (func_020122ec((void *)func_ov001_02187bf4, M2C_FIELD(&data_ov001_02193e20, void **, 4)) == 2) return 1;
func_ov001_02187b90();
func_ov001_02187b14(9);
return 0;
}

void func_ov001_02187bf4(void *arg0) {
s32 func_ov001_02187c60();
s32 func_ov001_02187cfc();
extern M2C_UNK data_ov001_02193e20;
if (M2C_FIELD(arg0,u16 *,2)) {
func_ov001_02187b90(M2C_FIELD(arg0,u16 *,2));
func_ov001_02187b14(9); return;
}
if (M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,0x13AC)) {
if (func_ov001_02187c60()) return;
func_ov001_02187b14(9); return;
}
if (func_ov001_02187cfc()) return;
func_ov001_02187b14(9);
}

s32 func_ov001_02187c60(void) {
extern M2C_UNK data_ov001_02193e20;
void func_ov001_02187cc4(void *);
s32 func_02013b54(void *,s32,void *);
s32 (*callback)();
void *p;
s32 value;
func_ov001_02187b14(3);
p=M2C_FIELD(&data_ov001_02193e20,void **,4);
callback=M2C_FIELD(p,s32 (**)(),0x13AC);
p=(u8 *)p+0x13C0;
value=callback(p);
if(func_02013b54((void *)func_ov001_02187cc4,value,(u8 *)M2C_FIELD(&data_ov001_02193e20,void **,4)+0x13C0)==2) return 1;
func_ov001_02187b90(); func_ov001_02187b14(9); return 0;
}

void func_ov001_02187cc4(void *arg0) {
    s32 func_ov001_02187cfc();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov001_02187b90();
        func_ov001_02187b14(9);
        return;
    }
    if (func_ov001_02187cfc() != 0) {
        return;
    }
    func_ov001_02187b14(9);
}

s32 func_ov001_02187cfc(void) {
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK func_ov001_02187d60;
s32 func_02012474(void *);
if((u32)(M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,0x40)-4)<=2) return 1;
if(func_02012474(&func_ov001_02187d60)!=2) {func_ov001_02187b90();return 0;}
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,0x50)=0;
M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),u16 *,0x52)=1;
return 1;
}

s32 func_ov001_02187ed0(void) {
extern M2C_UNK data_ov001_02193e20;
extern M2C_UNK func_ov001_02187f68;
s32 func_02012b08(void *,void *,u16,void *,u16,s32);
void *p;
if((u32)(M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,0x40)-4)<=2) return 1;
func_ov001_02187b14(4);
p=M2C_FIELD(&data_ov001_02193e20,void **,4);
if(func_02012b08(&func_ov001_02187f68,(u8 *)p+0x1060,(u16)M2C_FIELD(p,s32 *,0x12A4),(u8 *)p+0xF80,(u16)M2C_FIELD(p,s32 *,0x12A0),1)==2)return 1;
func_ov001_02187b90(); return 0;
}

s32 func_ov001_02188094(void){extern M2C_UNK data_ov001_02193e20;s32 func_02013b2c(void *,s32);func_ov001_02187b14(6);if(func_02013b2c((u8 *)M2C_FIELD(&data_ov001_02193e20,void **,4)+0x1e00,13)==2)return 1;func_ov001_02187b90();return 0;}

s32 func_ov001_021880d0(void){extern M2C_UNK data_ov001_02193e20;s32 func_02013b48(void *);if(func_02013b48((u8 *)M2C_FIELD(&data_ov001_02193e20,void **,4)+0x1e00)==2)return 1;func_ov001_02187b90();return 0;}

s32 func_ov001_02188100(void) {
    s32 func_02012d64(M2C_UNK *);
    extern M2C_UNK func_ov001_02188130;
    func_ov001_02187b14(3);
    if (func_02012d64(&func_ov001_02188130) == 2) {
        return 1;
    }
    func_ov001_02187b90();
    return 0;
}

void func_ov001_02188130(void *a){extern M2C_UNK data_ov001_02193e20;extern M2C_UNK data_ov001_02191644;M2C_UNK func_ov001_02188b04();if(M2C_FIELD(a,u16 *,2)){func_ov001_02187b90();func_ov001_02188b04();return;}if(func_ov001_02188184())return;if(M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *),0))M2C_FIELD(&data_ov001_02193e20,void (**)(s32,void *),0)(0x8000000,&data_ov001_02191644);func_ov001_02188b04();}

s32 func_ov001_02188184(void) {
    s32 func_02012484(void (*)(void *));
    void func_ov001_021881ac(void *);
    if (func_02012484(func_ov001_021881ac) == 2) return 1;
    func_ov001_02187b90();
    return 0;
}

void func_ov001_021881ac(void *arg0) {
    void func_ov001_02187b14(M2C_UNK);
    M2C_UNK func_ov001_02187b90();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov001_02187b90();
        return;
    }
    func_ov001_02187b14(1);
}

s32 func_ov001_021881d0(void){extern M2C_UNK data_ov001_02193e20;s32 func_02013b48(void *);if(M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,0x40)!=6)return 0;func_ov001_02187b14(3);if(func_02013b48((u8 *)M2C_FIELD(&data_ov001_02193e20,void **,4)+0x1e00)==2)return 1;func_ov001_02187b90();return 0;}

s32 func_ov001_02188220(void) {
    extern M2C_UNK func_ov001_02188250;
    func_ov001_02187b14(3);
    if (func_02012d64(&func_ov001_02188250) == 2) {
        return 1;
    }
    func_ov001_02187b90();
    return 0;
}

void func_ov001_02188250(void *arg0) {
    s32 func_ov001_02188284();
    M2C_UNK func_ov001_02188b20();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov001_02187b90();
        func_ov001_02188b20();
        return;
    }
    if (func_ov001_02188284() != 0) {
        return;
    }
    func_ov001_02187b14(9);
}

s32 func_ov001_02188284(void) {
    s32 func_0201280c(void (*)(void *), s32);
    void func_ov001_021882bc(void *);
    M2C_UNK func_ov001_02188b04();
    func_ov001_02187b14(3);
    if (func_0201280c(func_ov001_021882bc, 0) == 2) return 1;
    func_ov001_02187b90();
    func_ov001_02188b04();
    return 0;
}

void func_ov001_021882bc(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov001_02187b90();
        return;
    }
    func_ov001_02187b14(1);
}

s32 func_ov001_021882e0(void) {
    s32 func_02012274(M2C_UNK *);
    extern M2C_UNK func_ov001_02188310;
    func_ov001_02187b14(3);
    if (func_02012274(&func_ov001_02188310) == 2) {
        return 1;
    }
    func_ov001_02187b90();
    return 0;
}

void func_ov001_02188310(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov001_02187b14(9);
        func_ov001_02187b90(M2C_FIELD(arg0, u16 *, 2));
        return;
    }
    func_ov001_02187b14(1);
}

void func_ov001_02188344(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov001_02187b14(0xA);
        return;
    }
    func_ov001_02187b14(0);
}

void func_ov001_0218836c(s32 arg0) {
    extern M2C_UNK data_ov001_02193e20;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 8) = arg0;
}

u16 func_ov001_02188380(void) {
extern M2C_UNK data_ov001_02193e20;
return M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), u16 *, 0x52);
}

s32 func_ov001_02188394(void) {
extern M2C_UNK data_ov001_02193e20;
return M2C_FIELD(M2C_FIELD(&data_ov001_02193e20,void **,4),s32 *,0x40);
}

s32 func_ov001_021883a8(void) {
    void func_02007724(u8 *);
    void func_ov001_02187b14(s32);
    u16 func_ov001_02188480(u16);
    s32 func_ov001_02187b90(s32);
    extern M2C_UNK data_ov001_02193e20;
    u16 buf[3];
    u16 rv;

    func_02007724((u8 *)buf);
    M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 0x58) =
        buf[0] + *(s32 *)0x027ffc3c + buf[1] + buf[2];
    M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 0x58) =
        M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), s32 *, 0x58) * 0x10dcd + 0x39 + 0x3000;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), u16 *, 0x5c) = 0;
    M2C_FIELD(M2C_FIELD(&data_ov001_02193e20, void **, 4), u16 *, 0x5e) = 0x65;
    func_ov001_02187b14(3);
    rv = func_ov001_02188480(1);
    if (rv == 0x18) {
        func_ov001_02187b90(0x18);
        func_ov001_02187b14(9);
        return 0;
    }
    if (rv == 2) {
        return 1;
    }
    func_ov001_02187b90(rv);
    func_ov001_02187b14(9);
    return 0;
}

u16 func_ov001_02188480(u16 arg0) {
s32 func_02011d58();
s32 func_ov001_021885f4(void *,u16);
extern M2C_UNK func_ov001_0218851c;
s32 mask=func_02011d58();
if(mask==0x8000) {func_ov001_02187b90(3);func_ov001_02187b14(9);return 3;}
if(mask==0) {func_ov001_02187b90(0x16);func_ov001_02187b14(9);return 0x18;}
while(!(mask & (1 << (arg0-1)))) {
arg0++;
if((u32)arg0>0x10) return 0x18;
}
return (u16)func_ov001_021885f4(&func_ov001_0218851c,arg0);
}

