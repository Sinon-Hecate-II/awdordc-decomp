/* 28 functions from 0x020AF760 to 0x020B0658 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 x,y,z; } VecAff;
extern u8 data_02122d08[],data_021213e0[];
extern s32 data_027e15bc;

void func_020af760(void) {
M2C_UNK func_02090448(s32); extern M2C_UNK gPlayerSettings;
s32 i=0; u8 *p=(u8*)&gPlayerSettings;
do { s32 v=*M2C_FIELD(M2C_FIELD(p,void **,4),s32 **,0x34); if(v)func_02090448(v); i++; p+=0x18; }while(i<2);
}

void func_020af79c(void) {
    M2C_UNK func_02090480(M2C_UNK);
    func_02090480(0);
}

void func_020af7ac(void) {
extern u8 data_0215c430; extern u8 data_0215c42c;
s32 i=0; volatile u8 *p=&data_0215c430; volatile u8 *q=&data_0215c42c; u8 zero=0;
do { i++; *p++=zero; *q++=zero; } while(i<2);
}

void func_020af7dc(void) {
    extern u8 data_0215c42c;
    extern u8 data_0215c430;
    s32 var_r1;
    u8 *var_r2;
    u8 *var_r3;
    u8 temp_r0;
    u8 temp_r0_2;

    var_r2 = &data_0215c430;
    var_r3 = &data_0215c42c;
    var_r1 = 0;
    do {
        temp_r0 = *var_r2;
        var_r1 += 1;
        if (temp_r0 != 0) {
            *var_r2 = temp_r0 - 1;
        }
        temp_r0_2 = *var_r3;
        var_r2 += 1;
        if (temp_r0_2 != 0) {
            *var_r3 = temp_r0_2 - 1;
        }
        var_r3 += 1;
    } while (var_r1 < 2);
}

void func_020af828(s32 arg0, s32 arg1) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_0208ff94(M2C_UNK);
    if (arg1 == 0) {
        return;
    }
    func_0208fe30(arg1);
    if (arg0 == 0) {
        func_0208ff94(-0x80);
        return;
    }
    func_0208ff94(0x7F);
}

void func_020af860(s32 arg0,s32 arg1) {
M2C_UNK func_0208ffe4(s32,s32); M2C_UNK func_02090100(s32,s32); void func_020af8c8(s32,s32);
extern M2C_UNK data_ov002_021f30f4;
s32 value; void *base=(u8*)&data_ov002_021f30f4+arg0*0x18;
value=M2C_FIELD(M2C_FIELD(*(void **)base,void **,0x34),s32 *,4);
if(value==0)return;
func_0208ffe4(arg0,-1);
if(arg0==0)func_02090100(arg0,-128);else func_02090100(arg0,127);
func_020af8c8(arg0,arg1);
}

void func_020af8c8(s32 arg0, s32 arg1) {
    M2C_UNK func_020900a4(s32, s32, M2C_UNK);
    M2C_UNK func_02090158(s32, u8, M2C_UNK);
    extern M2C_UNK data_02127ed8;
    extern M2C_UNK data_ov002_021f2f44;
    extern M2C_UNK data_ov002_021f30f4;
    extern M2C_UNK data_ov002_021f314e;
    s32 var_r1;
    s32 var_r1_2;
    s32 var_r2;
    s32 var_r3;
    u8 temp_r0;
    void *temp_r1;

    temp_r1 = *(void **)((u8 *)&data_ov002_021f30f4 + (arg0 * 0x18));
    if (M2C_FIELD(M2C_FIELD(temp_r1, void **, 0x34), s32 *, 4) == 0) {
        return;
    }
    if (M2C_FIELD(temp_r1, u8 *, 0x3D) == 3) {
        var_r1 = 7;
    } else if (*((u8 *)&data_ov002_021f314e + (arg0 * 0x2C)) != 0 && arg1 != 0) {
        var_r1 = 7;
    } else if (arg1 <= 0) {
        var_r1 = 0;
    } else if (arg1 <= 1) {
        var_r1 = 1;
    } else if (arg1 <= 3) {
        var_r1 = 3;
    } else {
        var_r1 = 7;
    }
    func_020900a4(arg0, ~var_r1, 2);
    var_r2 = 5;
    if (*((u8 *)&data_ov002_021f314e + (arg0 * 0x2C)) != 0) {
        var_r2 = 0;
    } else {
        var_r3 = (arg0 * 0x68) + (s32) &data_ov002_021f2f44;
        var_r1_2 = 0;
        do {
            temp_r0 = M2C_FIELD(var_r3, u8 *, 0x12);
            var_r3 += 1;
            if ((s32) temp_r0 < arg1) {
                var_r2 = var_r1_2;
            }
            var_r1_2 += 1;
        } while (var_r1_2 < var_r2);
    }
    func_02090158(arg0, *((u8 *)&data_02127ed8 + var_r2), 0);
}

void func_020af9cc(s32 arg0,s32 arg1,s32 arg2) {
M2C_UNK func_02090034(s32,s32); extern M2C_UNK data_ov002_021f30f4;
if(arg2==0 && M2C_FIELD(*(void **)((u8*)&data_ov002_021f30f4+arg0*0x18),u8 *,0x3d)==3)return;
func_02090034(arg0,arg1);
}

void func_020afa00(s32 a){extern M2C_UNK data_ov002_021f30f4;extern u8 data_ov002_021f3103;extern u8 data_0215c430;u32 n=*((u8 *)&data_ov002_021f3103+a*24);void *p=*(void **)((u8 *)&data_ov002_021f30f4+a*24);if(M2C_FIELD((u8 *)p+n,u8 *,0x3e)==1){if((&data_0215c430)[a])return;(&data_0215c430)[a]=4;}func_020af828(a,M2C_FIELD((u8 *)M2C_FIELD(p,void **,0x34)+n*4,s32 *,8));}

void func_020afa64(s32 a){extern M2C_UNK data_ov002_021f30f4;s32 b;if(a==0)b=1;else b=0;func_020af828(a,M2C_FIELD(M2C_FIELD(*(void **)((u8 *)&data_ov002_021f30f4+b*24),void **,0x34),s32 *,0x10));}

void func_020afa98(s32 a){extern M2C_UNK data_ov002_021f30f4;extern u8 data_ov002_021f3103;extern u8 data_0215c42c;s32 n;if(M2C_FIELD((u8 *)*(void **)((u8 *)&data_ov002_021f30f4+(a==0?1:0)*24)+*((u8 *)&data_ov002_021f3103+(a==0?1:0)*24),u8 *,0x3e)==1){if((&data_0215c42c)[a])return;(&data_0215c42c)[a]=4;n=1;}else n=0;func_020af828(a,M2C_FIELD((u8 *)M2C_FIELD(*(void **)((u8 *)&data_ov002_021f30f4+a*24),void **,0x34)+n*4,s32 *,0x14));}

void func_020afb34(s32 a){extern M2C_UNK data_ov002_021f30f4;switch(M2C_FIELD(*(void **)((u8 *)&data_ov002_021f30f4+a*24),u8 *,0x3d)){case 2:func_020af828(a,0x2000b);return;case 3:func_020af828(a,0x2000c);return;default:func_020af828(a,0x2000a);return;}}

void func_020afb94(s32 arg0) {
extern M2C_UNK data_ov002_021f30f4;
void func_020afb34(s32);
s32 v=M2C_FIELD(M2C_FIELD(*(void **)((u8*)&data_ov002_021f30f4+arg0*24),void **,0x34),s32 *,0x1c);
if(v){func_020af828(arg0,v);return;}func_020afb34(arg0);
}

void func_020afbcc(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_020afbe8(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
}

void func_020afc04(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
}

void func_020afc20(void) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
}

void func_020afc3c(void) {

}

void func_020afc40(void) {

}

void func_020afc44(s32 arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4, s32 arg5, s32 arg6) {
    void func_0209107c(void *, s32, s32, VecAff *, s32, s32, s32, s32, s32);
    extern s32 data_027e15bc;
    volatile s32 sp30;
    volatile s32 sp2C;
    volatile s32 sp28;
    volatile s32 sp24;
    volatile s32 sp20;
    volatile s32 sp1C;
    volatile s32 sp18;
    volatile s32 sp14;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 var_r11;
    s32 var_r11_2;
    s32 var_r11_3;
    s32 var_r11_4;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;
    s32 var_r4_4;

    temp_r4 = arg0 * 0x30;
    sp14 = arg0;
    sp2C = (arg1 - (arg2 * 0x10)) * 0x30;
    sp30 = 0x8A1;
    sp28 = temp_r4;
    func_0209107c(arg3, 0x14, data_027e15bc, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
    sp2C = (arg1 + (arg2 * 0x10)) * 0x30;
    sp28 = temp_r4;
    func_0209107c(arg3, 0x15, data_027e15bc, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
    temp_r4_2 = arg1 * 0x30;
    sp28 = (sp14 - (arg2 * 0x10)) * 0x30;
    sp2C = temp_r4_2;
    func_0209107c(arg3, 0x16, data_027e15bc, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
    sp2C = temp_r4_2;
    sp28 = (sp14 + (arg2 * 0x10)) * 0x30;
    func_0209107c(arg3, 0x17, data_027e15bc, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
    temp_r0 = arg2 - 1;
    var_r11 = 1;
    sp18 = temp_r0;
    if (temp_r0 >= 1) {
        var_r4 = 0x10;
        do {
            sp28 = (sp14 - var_r4) * 0x30;
            sp2C = (arg1 - ((arg2 - var_r11) * 0x10)) * 0x30;
            func_0209107c(arg3, 0x18, data_027e15bc, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
            var_r11 += 1;
            var_r4 += 0x10;
        } while (var_r11 <= sp18);
    }
    temp_r0_2 = arg2 - 1;
    sp1C = temp_r0_2;
    var_r4_2 = 1;
    if (temp_r0_2 >= 1) {
        var_r11_2 = sp14 + 0x10;
        do {
            sp28 = var_r11_2 * 0x30;
            sp2C = (arg1 - ((arg2 - var_r4_2) * 0x10)) * 0x30;
            func_0209107c(arg3, 0x19, data_027e15bc, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
            var_r4_2 += 1;
            var_r11_2 += 0x10;
        } while (var_r4_2 <= sp1C);
    }
    temp_r0_3 = arg2 - 1;
    sp20 = temp_r0_3;
    var_r4_3 = 1;
    if (temp_r0_3 >= 1) {
        var_r11_3 = 0x10;
        do {
            sp28 = (sp14 - var_r11_3) * 0x30;
            sp2C = (arg1 + ((arg2 - var_r4_3) * 0x10)) * 0x30;
            func_0209107c(arg3, 0x1A, data_027e15bc, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
            var_r4_3 += 1;
            var_r11_3 += 0x10;
        } while (var_r4_3 <= sp20);
    }
    temp_r0_4 = arg2 - 1;
    sp24 = temp_r0_4;
    var_r4_4 = 1;
    if (temp_r0_4 < 1) {
        return;
    }
    var_r11_4 = sp14 + 0x10;
    do {
        sp28 = var_r11_4 * 0x30;
        sp2C = (arg1 + ((arg2 - var_r4_4) * 0x10)) * 0x30;
        func_0209107c(arg3, 0x1B, data_027e15bc, (VecAff *)&sp28, arg4, arg5, arg6, 0, 0);
        var_r4_4 += 1;
        var_r11_4 += 0x10;
    } while (var_r4_4 <= sp24);
}

void func_020affac(s32 x,s32 y){
s32 func_0207b9f4(s32,s32);
s32 func_0207cfb8(s32);
void func_02091248(s32);
void func_020afc44(s32,s32,s32,void *,s32,s32,s32);
void func_0209107c(void *,s32,s32,VecAff *,s32,s32,s32,s32,s32);
extern s32 *gCurrentMap;
VecAff v;
s32 c;void *b;s32 a; s32 n; s32 mode;
n=func_0207b9f4(x+8,y+8);
mode=func_0207cfb8(*gCurrentMap+0x6ef8)<=0?16:24;
if(mode==16){a=0x21000;b=data_021213e0;c=0x30000;}
else {a=0x21980;b=data_02122d08;c=0x20000;}
func_02091248(31);
if(n>19){func_020afc44(x+8,y+8,n-19,b,a,0x1440,c);return;}
v.x=(x+8)*48;v.y=(y+8)*48;v.z=0x8a1;
func_0209107c(b,n,data_027e15bc,&v,a,0x1440,c,0,0);
}

void func_020b00c0(void) {
    M2C_UNK func_0207ce54(s32);
    extern s32 *gCurrentMap;
    func_0207ce54(*gCurrentMap + 0x6EF8);
}

void func_020b00e4(void) {

}

void func_020b00e8(void) {

}

void func_020b00ec(void) { extern void *gCur3DSpriteEngine;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)&~3)|3;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)&~3)|0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)&~3)|1;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)&~3)|2;
}

void func_020b0154(void) { extern void *gCur3DSpriteEngine;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,6)&~3)|1;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,8)&~3)|0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,10)&~3)|2;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)=(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,12)&~3)|3;
}

void func_020b01bc(s32 a, s32 b, s32 c, s32 d, s32 e) { (void)a;(void)b;(void)c;(void)d;(void)e; }

void func_020b0408(void) {
    void func_020b0154(void);
    void Reset3DSpriteEngineState(void);
    extern s32 *gCurrentMap;
    extern void *gCur3DSpriteEngine;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    u16 *volatile sp0;
    u8 v51;
    u8 v52;
    u8 v0 = 0;

    func_020b0154();
    if (*(u8 *)((s32)*gCurrentMap + 0x5157) == 1) {
        v51 = 0xa;
        v52 = 0x8;
    } else {
        v51 = 0x6;
        v52 = 0x10;
    }
    sp30 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp30 = (*sp30 & ~0xc0) | 0x40;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x51) = v51;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x52) = v52;
    *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x53) = v0;
    sp2C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp2C = (*sp2C & ~1) | 1;
    sp28 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp28 = *sp28 & ~2;
    sp24 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp24 = *sp24 & ~4;
    sp20 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp20 = *sp20 & ~8;
    sp1C = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp1C = *sp1C & ~0x10;
    sp18 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp18 = *sp18 & ~0x20;
    sp14 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp14 = *sp14 & ~0x100;
    sp10 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp10 = *sp10 & ~0x200;
    spC = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *spC = *spC | 0x400;
    sp8 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp8 = *sp8 | 0x800;
    sp4 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp4 = *sp4 | 0x1000;
    sp0 = (u16 *)(*(u8 **)gCur3DSpriteEngine + 0x12);
    *sp0 = *sp0 | 0x2000;
    Reset3DSpriteEngineState();
}

