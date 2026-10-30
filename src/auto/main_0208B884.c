/* 33 functions from 0x0208B884 to 0x0208C830 (main), found by ds-decomp. */
#include "common.h"


typedef struct { u32 low:16, mode:3, a:1, b:1, c:1, d:2, e:2, high:6; } Flags0208;
typedef struct { u32 low:10, middle:11, high:11; } Flags0208B;

void func_0208b884(void *arg0) {
    extern void *gCur3DSpriteEngine;
    extern void *data_027e00c8;
    extern void *data_027e00c4;
    M2C_UNK func_0209b9a8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_01ff90e4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

    void *saved = gCur3DSpriteEngine;
    s32 r9;
    for (r9 = 0; r9 < 2; r9++) {
        if (r9 == 0) gCur3DSpriteEngine = data_027e00c8;
        else gCur3DSpriteEngine = data_027e00c4;
        func_0209b9a8(0, 0, 0, 0);
    }
    gCur3DSpriteEngine = saved;
    (void)arg0;
}

void func_0208bc00(void) {
    M2C_UNK func_0208b778();
    func_0208b778();
}

void func_0208bc0c(void) {
    M2C_UNK func_0208b878();
    func_0208b878();
}

void func_0208bc18(void) {
    M2C_UNK func_0208b868();
    func_0208b868();
}

void func_0208bc24(M2C_UNK arg0) {
    void *func_0208b630();
    extern M2C_UNK data_02102760;
    void *var_r0;

    var_r0 = func_01ffa3dc(&data_02102760, arg0);
    if (var_r0 != NULL) {
        var_r0 = func_0208b630();
    }
    M2C_FIELD(var_r0, u8 *, 0x48) = (u8) ((M2C_FIELD(var_r0, u8 *, 0x48) & ~0xE) | 2);
}

M2C_UNK func_0208bc58(void *p){
extern M2C_UNK data_0210264c;extern void *gCur3DSpriteEngine;extern void *data_027e00c8;
u8 equal;Flags0208 *f=(Flags0208 *)((char *)p+0x44);Flags0208B *g=(Flags0208B *)((char *)p+0x48);
M2C_FIELD(p,void **,0)=&data_0210264c;
M2C_FIELD(p,s32 *,0x34)=0;M2C_FIELD(p,s32 *,0x38)=0;M2C_FIELD(p,s32 *,0x3c)=0;M2C_FIELD(p,s32 *,0x40)=0x1000;
M2C_FIELD(p,u32 *,0x44)&=~0xffff;
equal=gCur3DSpriteEngine==data_027e00c8;
f->mode=equal!=1;f->a=0;f->b=0;f->c=0;f->d=0;f->e=0;g->low=0;g->high=0;
M2C_FIELD(p,s32 *,0x4c)=0;
M2C_FIELD(p,s32 *,0x50)=0;
M2C_FIELD(p,s32 *,0x54)=0;
M2C_FIELD(p,s32 *,0x58)=0;
M2C_FIELD(p,s32 *,0x5c)=0;
M2C_FIELD(p,s32 *,0x60)=0;
M2C_FIELD(p,s32 *,0x64)=0;
M2C_FIELD(p,s32 *,0x68)=0;
M2C_FIELD(p,s32 *,0x6c)=0;
M2C_FIELD(p,s32 *,0x70)=0;
}

void func_0208bd2c(void *arg0, M2C_UNK arg1, s32 arg2, u16 arg3, u8 arg4) {
    M2C_UNK func_02068c50(M2C_UNK *, s32);
    M2C_UNK func_02068d68(M2C_UNK *, M2C_UNK *);
    s32 func_020816f4(M2C_UNK);
    void func_0208be8c(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, u16, u8);
    void func_0208c69c(M2C_UNK);
    void func_0208c6fc(void);
    extern M2C_UNK data_02102840, data_02102848, data_02102850;
    M2C_UNK sp4C[8], sp2C[8], spC[8];
    s32 temp_r0;
    temp_r0 = func_020816f4(arg1);
    func_02068c50(sp4C, temp_r0);
    func_02068d68(sp4C, &data_02102840);
    func_02068c50(sp2C, temp_r0);
    func_02068d68(sp2C, &data_02102848);
    func_02068c50(spC, temp_r0);
    func_02068d68(spC, &data_02102850);
    func_0208c69c(arg1);
    func_0208be8c(arg0, (M2C_UNK)sp4C, (M2C_UNK)sp2C, (M2C_UNK)spC, arg2, arg3, arg4);
    func_0208c6fc();
}

/* Set up a display object's buffers from three prepared lists. */
void func_0208be8c(void *obj, M2C_UNK list1, M2C_UNK list2, M2C_UNK list3, s32 value, u16 count, u8 flag) {
    s32 func_02080e30(M2C_UNK, M2C_UNK);
    s32 func_02081070(M2C_UNK, M2C_UNK);
    M2C_UNK func_0208143c(M2C_UNK, s32, M2C_UNK);
    void *func_02091270(s32, M2C_UNK, M2C_UNK);

    s32 size;
    void *sub;
    void *ptr;

    size = count << 5;
    M2C_FIELD(obj, s32 *, 0x54) = func_02080e30(list2, 1);
    if (flag != 0) {
        M2C_FIELD(obj, s32 *, 0x50) = func_02081070(list1, 1);
        func_0208143c(list3, size, 0x20);
    }
    sub = func_02091270(M2C_FIELD(obj, s32 *, 0x54), 0xD, 6);
    M2C_FIELD(obj, void **, 0x4C) = sub;
    func_02091700(sub, 0);
    M2C_FIELD(M2C_FIELD(obj, void **, 0x4C), s32 *, 0x30) = (s32) M2C_FIELD(obj, s32 *, 0x50);
    M2C_FIELD(M2C_FIELD(obj, void **, 0x4C), s32 *, 0x28) = value;
    M2C_FIELD(M2C_FIELD(obj, void **, 0x4C), s32 *, 0x2C) = size;
    ptr = M2C_FIELD(obj, void **, 0x4C);
    M2C_FIELD(ptr, u8 *, 0x22) = (u8) (M2C_FIELD(ptr, u8 *, 0x22) | 0x40);
    M2C_FIELD(obj, s32 *, 0x44) = (s32) ((M2C_FIELD(obj, s32 *, 0x44) & ~0xFC000000) | (func_02091ac0(M2C_FIELD(obj, void **, 0x4C)) << 0x1A));
    M2C_FIELD(obj, s32 *, 0x48) = (s32) ((M2C_FIELD(obj, s32 *, 0x48) & 0xFFE003FF) | ((u32) (func_02091a84(M2C_FIELD(obj, void **, 0x4C)) << 0x15) >> 0xB));
    M2C_FIELD(obj, s32 *, 0x44) = (s32) ((M2C_FIELD(obj, s32 *, 0x44) & ~0xC00000) | 0x400000);
}

void func_0208bf7c(void *obj, M2C_UNK a, M2C_UNK b, M2C_UNK *c,u32 value,u16 count,u8 flag){
s32 func_02080e30(M2C_UNK,M2C_UNK);s32 func_02081070(M2C_UNK,M2C_UNK);M2C_UNK func_0208116c(M2C_UNK *,s32,M2C_UNK);void *func_02091270(s32,M2C_UNK,M2C_UNK);
u16 packed;void *sub,*ptr;
packed=(u16)((0x3ff&(value>>5))+(u16)(count<<12));
M2C_FIELD(obj,s32 *,0x54)=func_02080e30(b,1);
if(flag){M2C_FIELD(obj,s32 *,0x50)=func_02081070(a,1);func_0208116c(c,(count+16)<<5,32);}
sub=func_02091270(M2C_FIELD(obj,s32 *,0x54),13,2);
M2C_FIELD(obj,void **,0x4c)=sub;func_02091700(sub,0);
M2C_FIELD(M2C_FIELD(obj,void **,0x4c),s32 *,0x30)=M2C_FIELD(obj,s32 *,0x50);
M2C_FIELD(M2C_FIELD(obj,void **,0x4c),s32 *,0x28)=packed;
ptr=M2C_FIELD(obj,void **,0x4c);M2C_FIELD(ptr,u8 *,0x22)|=0x40;
M2C_FIELD(obj,s32 *,0x44)=(M2C_FIELD(obj,s32 *,0x44)&~0xfc000000)|(func_02091ac0(M2C_FIELD(obj,void **,0x4c))<<26);
M2C_FIELD(obj,s32 *,0x48)=(M2C_FIELD(obj,s32 *,0x48)&0xffe003ff)|((u32)(func_02091a84(M2C_FIELD(obj,void **,0x4c))<<21)>>11);
M2C_FIELD(obj,s32 *,0x44)=(M2C_FIELD(obj,s32 *,0x44)&~0xc00000)|0x800000;
}

void func_0208c080(void *arg0) {
    M2C_UNK func_02091700(s32);
    s32 func_02091a84(s32);
    s32 func_02091ac0(s32);
    func_02091700(M2C_FIELD(arg0, s32 *, 0x4C));
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) ((M2C_FIELD(arg0, s32 *, 0x44) & ~0xFC000000) | (func_02091ac0(M2C_FIELD(arg0, s32 *, 0x4C)) << 0x1A));
    M2C_FIELD(arg0, s32 *, 0x48) = (s32) ((M2C_FIELD(arg0, s32 *, 0x48) & 0xFFE003FF) | ((u32) (func_02091a84(M2C_FIELD(arg0, s32 *, 0x4C)) << 0x15) >> 0xB));
}

void func_0208c0d0(void *arg0, u8 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), u8 *, 0x21) = arg1;
}

/* Compute an interpolation factor from the object's mode/position fields and store it as a byte at +0x4C/0x21. */
void func_0208c0dc(void *obj) {
    s32 func_0207ca38(s32, s32, s32, s32, s32); void func_0208c0d0(void *, u8);
    u16 n = ((Flags0208B *)((char *)obj + 0x48))->middle;
    u16 mode = ((Flags0208 *)((char *)obj + 0x44))->e;
    u16 pos = ((Flags0208B *)((char *)obj + 0x48))->high;
    s32 half = n >> 1; s32 v = 31;
    switch (mode) {
        case 1: if (pos < half) v = func_0207ca38(0, 0, 31, pos, half); break;
        case 2: if (pos > half) v = func_0207ca38(0, 31, 0, pos - half, half); break;
        case 3: half = (s32)((s32)n + ((u32)(s32)n >> 31)) >> 1; if (pos < half) v = func_0207ca38(0, 0, 31, pos, half); else v = func_0207ca38(0, 31, 0, pos - half, half); break;
    }
    func_0208c0d0(obj, (u8)v);
}

s32 func_0208c1dc(void *arg0) {
    s32 func_02091a70(s32);
    return func_02091a70(M2C_FIELD(arg0, s32 *, 0x4C));
}

s32 func_0208c1ec(void *arg0) {
    M2C_UNK func_0207c8ec(s32, M2C_UNK);
    return func_0207c8ec(M2C_FIELD(arg0, s32 *, 0x34), 0x300);
}

s32 func_0208c200(void *arg0) {
    M2C_UNK func_0207c8ec(s32, M2C_UNK);
    return func_0207c8ec(M2C_FIELD(arg0, s32 *, 0x38), 0x300);
}

s32 func_0208c214(void *arg0) {
    s32 func_02094758();
    M2C_UNK func_020d4704();
    M2C_UNK (*temp_r1)(void *);
    u32 temp_r0;
    temp_r1 = M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x68);
    if (temp_r1 != NULL) temp_r1(arg0);
    temp_r0 = (u32)(M2C_FIELD(arg0, u32 *, 0x44) << 12) >> 31;
    if (temp_r0 == 0) return temp_r0;
    func_020d4704();
    return func_02094758();
}

M2C_UNK func_0208c248(void) {
    return 0;
}

s32 func_0208c49c(void *arg0) {
    void func_020912a4(s32 *);
    s32 func_02094770();
    M2C_UNK func_020d472c();
    M2C_UNK func_020e35cc(s32);
    s32 (*temp_r1)(void *);
    s32 var_r0;
    if (M2C_FIELD(arg0, s32 *, 0x4C) != 0) func_020912a4(M2C_FIELD(arg0, s32 *, 0x4C));
    if (M2C_FIELD(arg0, s32 *, 0x50) != 0) func_020e35cc(M2C_FIELD(arg0, s32 *, 0x50));
    if (M2C_FIELD(arg0, s32 *, 0x54) != 0) func_020e35cc(M2C_FIELD(arg0, s32 *, 0x54));
    var_r0 = (u32)(M2C_FIELD(arg0, u32 *, 0x44) << 12) >> 31;
    if (var_r0 != 0) {
        func_020d472c();
        var_r0 = func_02094770();
    }
    temp_r1 = M2C_FIELD(arg0, s32 (**)(void *), 0x70);
    if (temp_r1 == NULL) return var_r0;
    return temp_r1(arg0);
}

void func_0208c504(void) {
    M2C_UNK func_0208c214();
    func_0208c214();
}

void func_0208c510(void) {
    M2C_UNK func_0208c49c();
    func_0208c49c();
}

void func_0208c51c(void) {
    M2C_UNK func_0208c248();
    func_0208c248();
}

void func_0208c528(M2C_UNK arg0) {
    s32 func_01ffa3dc(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0208bc58();
    extern M2C_UNK data_02102790;
    if (func_01ffa3dc(&data_02102790, arg0) == 0) {
        return;
    }
    func_0208bc58();
}

void func_0208c54c(M2C_UNK arg0) {
    s32 func_01ffa42c(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0208bc58();
    extern M2C_UNK data_02102790;
    if (func_01ffa42c(&data_02102790, arg0) == 0) {
        return;
    }
    func_0208bc58();
}

s32 func_0208c570(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_02068c50(M2C_UNK *, s32);
    M2C_UNK func_02068d68(M2C_UNK *, M2C_UNK *);
    s32 func_020813c4(M2C_UNK *, M2C_UNK);
    M2C_UNK func_0208143c(M2C_UNK, s32, M2C_UNK);
    s32 func_020816f4();
    void func_0208c69c(M2C_UNK);
    void func_0208c6fc(void);
    extern M2C_UNK data_02102864, data_0210286c;
    M2C_UNK sp20[8], sp0[8];
    s32 temp_r0, temp_r4;
    temp_r0 = func_020816f4();
    func_02068c50(sp20, temp_r0);
    func_02068d68(sp20, &data_02102864);
    func_02068c50(sp0, temp_r0);
    func_02068d68(sp0, &data_0210286c);
    func_0208c69c(arg0);
    temp_r4 = func_020813c4(sp20, arg1);
    func_0208143c((M2C_UNK)sp0, arg2 << 5, 0x20);
    func_0208c6fc();
    return temp_r4;
}

s32 func_0208c5fc(M2C_UNK arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02068c50(M2C_UNK *, s32);
    M2C_UNK func_02068d68(M2C_UNK *, M2C_UNK *);
    s32 func_02080cfc(M2C_UNK *, s32);
    M2C_UNK func_0208116c(M2C_UNK *, s32, M2C_UNK);
    s32 func_020816f4();
    void func_0208c69c(M2C_UNK);
    void func_0208c6fc(void);
    extern M2C_UNK data_02102870;
    extern M2C_UNK data_02102874;
    extern void *gCur3DSpriteEngine;
    M2C_UNK sp20[8], sp0[8];
    s32 temp_r0;
    s32 temp_r4;

    temp_r0 = func_020816f4();
    func_02068c50(sp20, temp_r0);
    func_02068d68(sp20, &data_02102870);
    func_02068c50(sp0, temp_r0);
    func_02068d68(sp0, &data_02102874);
    func_0208c69c(arg0);
    temp_r4 = func_02080cfc(sp20, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg1);
    func_0208116c(sp0, (arg2 + 0x10) << 5, 0x20);
    func_0208c6fc();
    return temp_r4;
}

void func_0208c69c(M2C_UNK arg0) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02068c50(M2C_UNK *, s32);
    M2C_UNK func_02068d68(M2C_UNK *, M2C_UNK *);
    M2C_UNK func_020814e4(M2C_UNK *);
    extern M2C_UNK data_02102878;
    extern M2C_UNK data_02102880;
    extern u8 data_021577e0;
    M2C_UNK sp0[8];
    u8 temp_r3;

    temp_r3 = data_021577e0;
    data_021577e0 = temp_r3 + 1;
    if (temp_r3 != 0) {
        return;
    }
    func_02068c50(sp0, arg0);
    func_02068d68(sp0, &data_02102878);
    func_0200bc5c(&data_02102880);
    func_020814e4(sp0);
}

void func_0208c6fc(void) {
    M2C_UNK func_02081528();
    extern u8 data_021577e0;
    u32 temp_r1;

    temp_r1 = data_021577e0 - 1;
    data_021577e0 = (u8) temp_r1;
    if (temp_r1 & 0xFF) {
        return;
    }
    func_02081528();
}

u8 func_0208c724(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02102790;
    u8 var_r0;

    if (func_01ffa770(&data_02102790) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0208c748(void)
{
  M2C_UNK func_01ffa9e4(M2C_UNK *);
  M2C_UNK *new_var;
  extern M2C_UNK data_02102790;
  new_var = &data_02102790;
  func_01ffa9e4(new_var);
}

void func_0208c75c(void *arg0, s32 arg1) {
    extern void *gCur3DSpriteEngine;
    u16 *src;
    s32 i;
    src = (u16 *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + ((arg1 << 5) & ~1));
    for (i = 0; i < 15; i++) {
        ((u16 *)arg0)[i + 0x2B] = src[i + 1];
    }
}

void func_0208c79c(void *arg0, s16 arg1) {
    s32 i;
    for (i = 0; i < 15; i++) {
        ((s16 *)arg0)[i + 0x1C] = arg1;
    }
}

void func_0208c7b8(void *arg0, s8 arg1) {
    extern void *gCur3DSpriteEngine;
    s32 i;
    u16 *dest;
    if (arg1 == 0) {
        dest = (u16 *)(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + ((M2C_FIELD(arg0, u8 *, 0x34) << 5) & ~1));
        for (i = 0; i < 15; i++) {
            dest[i + 1] = ((u16 *)arg0)[i + 0x1C];
        }
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 0x10;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x36) = 0;
    M2C_FIELD(arg0, s8 *, 0x37) = arg1;
    M2C_FIELD(arg0, s8 *, 0x35) = 3;
}

