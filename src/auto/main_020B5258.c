/* 29 functions from 0x020B5258 to 0x020B6168 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind:6; u8 rest:2; } UnitKindBits;
extern u8 data_ov000_021b5c0d[];
extern s32 *gCurrentMap;

u8 func_020b5258(void) {
    s32 func_0208c724();
    s32 func_020c306c();
    u8 var_r0;

    if (func_020c306c() != 0) {
        return 1U;
    }
    if (func_0208c724() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

M2C_UNK *func_020b5284(u32 arg0) {
    extern M2C_UNK data_02128e1c, data_02128e2c, data_02128e3c, data_02128e4c, data_02128e5c, data_02128e6c, data_02128e7c;
    switch (arg0) {
    case 0: case 1: case 2: return &data_02128e1c;
    case 3: return &data_02128e2c;
    case 4: return &data_02128e3c;
    case 5: return &data_02128e4c;
    case 6: case 7: return &data_02128e5c;
    case 8: return &data_02128e6c;
    case 9: return &data_02128e7c;
    default: return NULL;
    }
}

/* Draws one of several unit/map status overlays at position (x, y) depending on mode. */
void func_020b5314(u8 mode, s32 x, s32 y) {
    M2C_UNK func_0208fb0c(s32, s16, s16);
    void func_02080750(s32, s32, s32);
    void func_02080358(s32, s32, s32, s32);
    M2C_UNK func_0208fb54(s32, s32, s32, s32);
    typedef M2C_UNK (*Fb0c)(s32, s32, s32);
    switch (mode) {
    case 0:
    case 1:
    case 2:
        ((Fb0c)func_0208fb0c)(0x8a, x, y);
        func_02080750(1, 0x14, 0);
        return;
    case 3:
        ((Fb0c)func_0208fb0c)(0x6d, x, y);
        func_02080750(1, 0x14, 0);
        return;
    case 4:
        ((Fb0c)func_0208fb0c)(0x73, x, y);
        func_02080750(1, 0x14, 0);
        return;
    case 5:
        ((Fb0c)func_0208fb0c)(0x8a, x, y);
        func_02080750(0, 0xa, 0);
        return;
    case 6:
        ((Fb0c)func_0208fb0c)(0x8a, x, y);
        func_02080750(0, 5, 0);
        return;
    case 7:
        ((Fb0c)func_0208fb0c)(0x11f, x, y);
        func_02080750(0, 5, 0);
        return;
    case 8:
        func_0208fb54(0x10e, x, y, 0);
        func_0208fb54(0x10f, x, y, 0x1e);
        func_02080750(1, 0x14, 0);
        func_02080358(4, 0, 2, 0);
        return;
    case 9:
        ((Fb0c)func_0208fb0c)(0xfa, x, y);
        func_02080750(1, 0x1e, 0);
        func_02080358(8, 0, 4, 0);
        return;
    }
}

void func_020b5480(void *arg0) {
    s32 func_0208c1ec(void *);
    s32 func_0208c200(void *);
    void func_020b5314(u8, s32, s32);
    s32 temp_r4;
    u8 temp_r5;
    temp_r5 = (u8) M2C_FIELD(arg0, s32 *, 0x5C);
    if (M2C_FIELD(arg0, s32 *, 0x58) & 0xFF) return;
    temp_r4 = func_0208c1ec(arg0);
    func_020b5314(temp_r5, temp_r4, func_0208c200(arg0));
    M2C_FIELD(arg0, s32 *, 0x58) = 1;
}

void func_020b54c8(void *arg0) {
    s32 func_0208c1dc(void *);
    if ((u16)(M2C_FIELD(arg0, u32 *, 0x44) >> 26) == 0) func_020b5480(arg0);
    if (func_0208c1dc(arg0) == 0) return;
    func_020b5480(arg0);
}

void func_020b5504(void *arg0) {
    M2C_UNK func_0207b764(s32, s32);
    func_0207b764(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C));
}

void func_020b551c(void *arg0) {
    void *func_020b5188(void *, s32, s32, s32, s32, s32, void *);
    s32 temp_r4;
    void *temp_r0;
    void *obj;
    temp_r4 = M2C_FIELD(arg0, s32 *, 0x5C);
    temp_r0 = func_020b5284(temp_r4);
    if (temp_r0 == 0) return;
    obj = func_020b5188(temp_r0, M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), 0, 0, 0, arg0);
    M2C_FIELD(obj, s32 *, 0x58) = 0;
    M2C_FIELD(obj, s32 *, 0x5C) = temp_r4;
    M2C_FIELD(obj, void (**)(void *), 0x6C) = func_020b54c8;
    M2C_FIELD(obj, void (**)(void *), 0x70) = func_020b5480;
    M2C_FIELD(obj, u32 *, 0x44) = (M2C_FIELD(obj, u32 *, 0x44) & ~0x03000000) | 0x02000000;
}

M2C_UNK func_020b5594(s32 a,s32 b,s32 c,s32 d) {
void *func_01ffa444(M2C_UNK *,s32); extern M2C_UNK data_02128c6c;
void *p=func_01ffa444(&data_02128c6c,d);
M2C_FIELD(p,s32 *,0x38)=a; M2C_FIELD(p,s32 *,0x3c)=b; M2C_FIELD(p,s32 *,0x5c)=c;
}

void func_020b55c4(void *arg0) {
s32 func_0208c1ec(void *); s32 func_0208c200(void *);
void func_020a6718(u8); void func_020a6728(u8);
void func_020b5314(u8,s32,s32); void func_020ca484(void); void func_ov000_0216ab2c(void);
s32 x; u8 a,b,c;
a=M2C_FIELD(arg0,s32 *,0x5c); b=M2C_FIELD(arg0,s32 *,0x60); c=M2C_FIELD(arg0,s32 *,0x64);
if(M2C_FIELD(arg0,s32 *,0x58)&255) return;
x=func_0208c1ec(arg0);
func_020b5314(a,x,func_0208c200(arg0));
if(b) func_020a6728(c); else func_020a6718(c);
func_020cfd28();
M2C_FIELD(arg0,s32 *,0x58)=1; func_020ca484(); func_ov000_0216ab2c();
}

void func_020b5640(void *arg0) {
    s32 func_0208c1dc(void *);
    if ((u16)(M2C_FIELD(arg0, u32 *, 0x44) >> 26) == 0) func_020b55c4(arg0);
    if (func_0208c1dc(arg0) == 0) return;
    func_020b55c4(arg0);
}

M2C_UNK func_020b567c(M2C_UNK a, s32 arg1) {
u8 *unit=(u8 *)a;
void *func_020b5134(void *,s16,s16,s32,s32,s32,void *);
s32 kind, index; void *p;
/* Spawns a managed unit object from a unit-table entry. */
if (!unit) return;
kind=data_ov000_021b5c0d[((UnitKindBits *)unit)->kind*0x70];
index=unit ? ((s32)unit-(*gCurrentMap+0x59A4))/14 : 0;
p=func_020b5284(kind);
if(!p) return;
p=func_020b5134(p,unit[1],unit[2],0,0,0,(void *)7);
M2C_FIELD(p,s32 *,0x58)=0;
M2C_FIELD(p,s32 *,0x5c)=kind;
M2C_FIELD(p,s32 *,0x60)=arg1;
M2C_FIELD(p,s32 *,0x64)=index;
M2C_FIELD(p,void (**)(void *),0x6c)=func_020b5640;
M2C_FIELD(p,void (**)(void *),0x70)=func_020b55c4;
M2C_FIELD(p,u32 *,0x44)=(M2C_FIELD(p,u32 *,0x44)&~0x3000000)|0x2000000;
}

void func_020b576c(M2C_UNK arg0) {
    M2C_UNK func_020b567c(M2C_UNK, M2C_UNK);
    func_020b567c(arg0, 1);
}

void func_020b577c(M2C_UNK arg0) {
    M2C_UNK func_020b567c(M2C_UNK, M2C_UNK);
    func_020b567c(arg0, 0);
}

void func_020b578c(void *arg0) {
    M2C_UNK func_020b5594(s32, s32, M2C_UNK, M2C_UNK);
    func_020b5594(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), 9, 7);
}

void func_020b57ac(void *arg0) {
    s32 x = M2C_FIELD(arg0, s32 *, 0x38);
    s32 y = M2C_FIELD(arg0, s32 *, 0x3C);
    {
        void *base = (void *)*gCurrentMap;
        u16 row = *(u16 *)((char *)base + 0x3758 + y * 2);
        *(u16 *)((char *)base + 0xA10 + ((x - 1) + row) * 2) += 0x60;
    }
    {
        void *base = (void *)*gCurrentMap;
        u16 row = *(u16 *)((char *)base + 0x3758 + y * 2);
        *(u16 *)((char *)base + 0xA10 + (x + row) * 2) += 0x60;
    }
    {
        void *base = (void *)*gCurrentMap;
        u16 row = *(u16 *)((char *)base + 0x3758 + y * 2);
        *(u16 *)((char *)base + 0xA10 + ((x + 1) + row) * 2) += 0x60;
    }
    {
        void *base = (void *)*gCurrentMap;
        u16 row = *(u16 *)((char *)base + 0x3758 + (y - 1) * 2);
        *(u16 *)((char *)base + 0xA10 + ((x - 1) + row) * 2) += 0x60;
    }
    {
        void *base = (void *)*gCurrentMap;
        u16 row = *(u16 *)((char *)base + 0x3758 + (y - 1) * 2);
        *(u16 *)((char *)base + 0xA10 + (x + row) * 2) += 0x60;
    }
    {
        void *base = (void *)*gCurrentMap;
        u16 row = *(u16 *)((char *)base + 0x3758 + (y - 1) * 2);
        *(u16 *)((char *)base + 0xA10 + ((x + 1) + row) * 2) += 0x60;
    }
    {
        void *q = (void *)gCurrentMap;
        s32 yr = y - 2;
        void *base = (void *)*(s32 *)q;
        u16 row = *(u16 *)((char *)base + 0x3758 + yr * 2);
        *(u16 *)((char *)base + 0xA10 + ((x - 1) + row) * 2) += 0x60;
    }
    {
        void *base = (void *)*gCurrentMap;
        u16 row = *(u16 *)((char *)base + 0x3758 + (y - 2) * 2);
        *(u16 *)((char *)base + 0xA10 + (x + row) * 2) += 0x60;
    }
    {
        void *base = (void *)*gCurrentMap;
        u16 row = *(u16 *)((char *)base + 0x3758 + (y - 2) * 2);
        *(u16 *)((char *)base + 0xA10 + ((x + 1) + row) * 2) += 0x60;
    }
    func_020cfd28();
}

void func_020b5964(s32 a,s32 b) {
void func_020a488c(s32,s16 *); void *func_01ffa42c(M2C_UNK *,s32); extern M2C_UNK data_02128c34;
s16 xy[2]; void *p;
func_020a488c(a,xy); p=func_01ffa42c(&data_02128c34,b);
M2C_FIELD(p,s32 *,0x38)=xy[0]; M2C_FIELD(p,s32 *,0x3c)=xy[1];
}

void func_020b59a0(void *arg0) {
    func_020b5594(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), 9, 7);
}

void func_020b5d94(u8 *arg0,s32 arg1) {
void *func_01ffa42c(M2C_UNK *,s32); extern M2C_UNK data_02128bc4;
void *p=func_01ffa42c(&data_02128bc4,arg1);
M2C_FIELD(p,s32 *,0x38)=arg0[0]; M2C_FIELD(p,s32 *,0x3c)=arg0[1]; M2C_FIELD(p,void **,0x34)=arg0;
}

void func_020b5dc0(void *arg0) {
    func_020b5594(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), 8, 7);
}

void func_020b5de0(void *arg0) {
    M2C_UNK func_020a17c0(s32, s32);
    M2C_UNK func_020cf2c8();
    M2C_UNK func_020cfd28();
    func_020a17c0(M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C));
    func_020cfd28();
    func_020cf2c8();
}

void func_020b5e00(s32 arg0, s32 arg1, M2C_UNK arg2) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02128bfc;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_02128bfc, arg2);
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg1;
}

void func_020b5e28(void *arg0) {
    M2C_UNK func_0208c080(void *, M2C_UNK);
    void *func_020b5134(void *, s16, s16, M2C_UNK, s32, s32, void *);
    M2C_UNK func_020b51dc();
    M2C_UNK func_020b5200(s32, M2C_UNK);
    M2C_UNK func_0208fb0c(s32, s16, s16);
    void *temp_r0;
    func_020b51dc();
    func_020b5200(arg0 + 0x34, 0);
    func_0208c080(func_020b5134(arg0 + 0x34, M2C_FIELD(arg0,s16 *,0x44), M2C_FIELD(arg0,s16 *,0x46),0x10,0,0,arg0),3);
    temp_r0 = func_020b5134(arg0 + 0x34, M2C_FIELD(arg0,s16 *,0x44), M2C_FIELD(arg0,s16 *,0x46),0x10,0,0,arg0);
    M2C_FIELD(arg0,void **,0x60) = temp_r0;
    func_0208c080(temp_r0,4);
    M2C_FIELD(arg0,s16 *,0x48)=0;
    M2C_FIELD(arg0,s16 *,0x4A)=0x40;
    M2C_FIELD(arg0,s32 *,0x54)=M2C_FIELD(M2C_FIELD(arg0,void **,0x60),s32 *,0x38);
    M2C_FIELD(arg0,s32 *,0x58)=M2C_FIELD(M2C_FIELD(arg0,void **,0x60),s32 *,0x38)-0x1E00;
    func_0208fb0c(0x94,M2C_FIELD(arg0,s16 *,0x44),M2C_FIELD(arg0,s16 *,0x46));
}

void func_020b5edc(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    s32 func_0207ca38(M2C_UNK, s32, s32, s16, s32);
    M2C_FIELD(arg0, s16 *, 0x48) = (s16) (M2C_FIELD(arg0, s16 *, 0x48) + 1);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s32 *, 0x38) = func_0207ca38(0, M2C_FIELD(arg0, s32 *, 0x54), M2C_FIELD(arg0, s32 *, 0x58), M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
    if ((s32) M2C_FIELD(arg0, s16 *, 0x48) < (s32) M2C_FIELD(arg0, s16 *, 0x4A)) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_020b5f3c(s16 arg0, s16 arg1, M2C_UNK arg2) {
    M2C_UNK func_02068c50(void *, M2C_UNK *);
    extern M2C_UNK data_02128b04;
    extern M2C_UNK data_02128e8c;
    void *temp_r0;

    temp_r0 = func_01ffa42c(&data_02128b04, arg2);
    M2C_FIELD(temp_r0, s16 *, 0x44) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x46) = arg1;
    func_02068c50(temp_r0 + 0x34, &data_02128e8c);
}

void func_020b5f74(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 temp_ip;
    s32 temp_lr;
    s32 temp_r3;

    temp_lr = *gCurrentMap;
    temp_ip = arg0 + M2C_FIELD((temp_lr + (arg1 * 2)), u16 *, 0x3758);
    if (M2C_FIELD((temp_lr + (temp_ip * 2)), u16 *, 0xA10) == 0x180) {
        M2C_FIELD((temp_lr + temp_ip), s8 *, 0x1420) = 0x19;
        temp_r3 = *gCurrentMap;
        M2C_FIELD((temp_r3 + ((arg0 + M2C_FIELD((temp_r3 + (arg1 * 2)), u16 *, 0x3758)) * 2)), s16 *, 0xA10) = 0x1A0;
    }
    func_020cfd28();
}

void func_020b5fec(void *arg0) {
    M2C_UNK func_0208c080(void *, M2C_UNK);
    void *func_020b5134(void *, s16, s16, M2C_UNK, s32, s32, void *);
    M2C_UNK func_020b51dc();
    M2C_UNK func_020b5200(s32, M2C_UNK);
    M2C_UNK func_020b5240(s32);
    M2C_UNK func_020cc66c(s16, s16);
    void *temp_r0;

    func_020b5240(arg0 + 0x34);
    func_020b51dc();
    func_020b5200(arg0 + 0x34, 0);
    temp_r0 = func_020b5134(arg0 + 0x34, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46), 0x10, 0, 0, arg0);
    M2C_FIELD(arg0, void **, 0x60) = temp_r0;
    func_0208c080(temp_r0, 0);
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
    M2C_FIELD(arg0, s16 *, 0x4A) = 0x20;
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) (M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s32 *, 0x38) - 0x1E00);
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s32 *, 0x38);
    func_020cc66c(M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46));
}

void func_020b607c(void *arg0) {
    M2C_UNK func_01ffa574(void *);
    M2C_UNK func_0208fb0c(s32, s16, s16);
    s32 temp_r0;

    M2C_FIELD(arg0, s16 *, 0x48) = (s16) (M2C_FIELD(arg0, s16 *, 0x48) + 1);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s32 *, 0x38) = func_0207ca38(0, M2C_FIELD(arg0, s32 *, 0x54), M2C_FIELD(arg0, s32 *, 0x58), M2C_FIELD(arg0, s16 *, 0x48), (s32) M2C_FIELD(arg0, s16 *, 0x4A));
    if ((s32) M2C_FIELD(arg0, s16 *, 0x48) < (s32) M2C_FIELD(arg0, s16 *, 0x4A)) {
        return;
    }
    func_0208c080(func_020b5134(arg0 + 0x34, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46), 0x10, 0, 0, arg0), 1);
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x50);
    if (temp_r0 != 0) {
        func_0208fb0c(temp_r0, M2C_FIELD(arg0, s16 *, 0x44), M2C_FIELD(arg0, s16 *, 0x46));
    }
    func_01ffa574(M2C_FIELD(arg0, void **, 0x60));
    func_01ffa6fc(arg0);
}

void func_020b6124(void *arg0) {
    M2C_UNK func_02076910(s32, s32);
    M2C_UNK func_020a71a0(s32, s32, s32);
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;

    if ((u16) ((u32) M2C_FIELD(arg0, u32 *, 0x48) >> 0x15) != 0) {
        return;
    }
    temp_r5 = M2C_FIELD(arg0, s32 *, 0x5C);
    temp_r4 = M2C_FIELD(arg0, s32 *, 0x58);
    temp_r6 = M2C_FIELD(arg0, s32 *, 0x60);
    func_02076910(temp_r4, temp_r5);
    func_020a71a0(temp_r4, temp_r5, temp_r6);
}

