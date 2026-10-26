/* 42 functions from 0x02228D1C to 0x02229D0C (ov010), found by ds-decomp. */
#include "common.h"
typedef struct QueueNode { struct QueueNode *next; u32 unk4; u8 kind; u8 low:4; u8 high:4; u16 value; s32 size; } QueueNode;

void func_ov010_02228d1c(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    s32 func_ov010_022282b4(M2C_UNK);
    extern M2C_UNK data_ov010_0222c218;
    if (func_ov010_022282b4(0) == 0) {
        return;
    }
    func_01ffa42c(&data_ov010_0222c218, arg0);
}

s32 func_ov010_02229438(s32 arg0) {
    extern u16 data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 32);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 32) = arg0;
    return temp_r2;
}

s32 func_ov010_02229450(s32 arg0) {
    extern u16 data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 12);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 12) = arg0;
    return temp_r2;
}

s32 func_ov010_02229468(s32 arg0) {
    extern u16 data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 8);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 8) = arg0;
    return temp_r2;
}

s32 func_ov010_02229480(s32 arg0) {
    extern u16 data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 68);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 68) = arg0;
    return temp_r2;
}

s32 func_ov010_02229498(s32 arg0) {
    extern u16 data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x58);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x58) = arg0;
    return temp_r2;
}

s32 func_ov010_022294b0(s32 arg0) {
    extern u16 data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x1C);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x1C) = arg0;
    return temp_r2;
}

s32 func_ov010_022294c8(s32 arg0) {
    extern u16 data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x50);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x50) = arg0;
    return temp_r2;
}

s32 func_ov010_022294e0(void) {
    s32 func_0203bd54();
    return func_0203bd54();
}

s32 func_ov010_022294ec(void) {
    M2C_UNK func_0203a850(M2C_UNK *, s32);
    s32 func_0203bd34();
    extern u16 data_ov010_0222eee0;
    extern M2C_UNK data_ov010_0222efc0;
    if (func_ov010_022294e0() == 0) return 0;
    M2C_FIELD(&data_ov010_0222eee0, u8 *, 0xFA) = M2C_FIELD(&data_ov010_0222eee0, u8 *, 0xFA) & ~2;
    func_0203a850(&data_ov010_0222efc0, 0x6C);
    return func_0203bd34();
}

void func_ov010_0222952c(void) {
    M2C_UNK func_0203a850(M2C_UNK *, s32);
    void func_0203bda0(void *, s32);
    extern u16 data_ov010_0222eee0;
    extern M2C_UNK data_ov010_0222efc0;
    void func_ov010_0222817c(void);
    M2C_FIELD(&data_ov010_0222eee0, u8 *, 0xFA) = M2C_FIELD(&data_ov010_0222eee0, u8 *, 0xFA) & ~2;
    func_0203a850(&data_ov010_0222efc0, 0x6C);
    func_0203bda0(&func_ov010_0222817c, 0);
}

void func_ov010_02229568(M2C_UNK arg0) {
    M2C_UNK func_ov010_022268f4(M2C_UNK, M2C_UNK, M2C_UNK);
    func_ov010_022268f4(0, arg0, 0x20);
}

void func_ov010_02229580(void *arg0) {
    M2C_UNK func_ov010_02226908(M2C_UNK, void *, s32);
    func_ov010_02226908(0, arg0, M2C_FIELD(arg0, s32 *, 8) + 0xC);
}

void *func_ov010_0222959c(void *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u16 arg6) {
    M2C_UNK func_02008048(s32, s32, M2C_UNK);
    M2C_FIELD(arg0,s32 *,0) = 0x5F57464D;
    M2C_FIELD(arg0,s8 *,4) = arg1;
    M2C_FIELD(arg0,u8 *,5) = (M2C_FIELD(arg0,u8 *,5) & ~0xF) | (arg2 & 0xF);
    M2C_FIELD(arg0,u8 *,5) = (M2C_FIELD(arg0,u8 *,5) & ~0xF0) | ((arg3 & 0xF) << 4);
    M2C_FIELD(arg0,u16 *,6) = arg6;
    M2C_FIELD(arg0,s32 *,8) = arg5;
    if (arg4 != 0 && arg5 != 0) func_02008048(arg4,(s32)arg0 + 0xC,arg5);
    return arg0;
}

s32 func_ov010_02229850(void) {
    s32 func_ov010_022282b4(M2C_UNK);
    extern u16 data_ov010_0222eee0;
    s32 result;
    u16 saved;
    if (func_ov010_022282b4(3) == 0) return 1;
    result = 0;
    saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    if (M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x60) == 0) result = 1;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = saved;
    return result;
}

s32 func_ov010_02229920(s32 a, void *b) {
extern QueueNode *data_ov010_0222ef88;
extern s32 data_ov010_0222ef8c, data_ov010_0222ef90;
s32 offset=a*12;
u32 saved;

QueueNode *p;
QueueNode **head=(QueueNode **)((char *)&data_ov010_0222ef88+offset);
saved=*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=0;
p=*head;
if(!p){(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;return 0;}
func_ov010_0222959c(b,p->kind,p->low,p->high,(s32)(p+1),p->size,p->value);
if(!(*head=p->next))M2C_FIELD(&data_ov010_0222ef8c,s32 *,offset)=0;
func_ov010_02226908(0,p,p->size+16);
M2C_FIELD(&data_ov010_0222ef90,s32 *,offset)--;
(void)*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=saved;
return M2C_FIELD(b,s32 *,8)+12;
}

s32 func_ov010_02229a08(void) {
    s32 func_02038e94();
    return func_02038e94();
}

u8 func_ov010_02229a14(void) {
    extern u16 data_ov010_0222eee0;
    return M2C_FIELD(&data_ov010_0222eee0, u8 *, 0xFB);
}

u16 func_ov010_02229a24(void) {
    s32 func_02038f00();
    return (u16)func_02038f00();
}

s32 func_ov010_02229a38(void) {
    return 2;
}

s32 func_ov010_02229a40(void) {
    s32 func_02038e4c();
    return func_02038e4c() & 0xFF;
}

void func_ov010_02229a50(void) {
    extern u16 data_ov010_0222eee0;
    data_ov010_0222eee0 = 0;
}

u16 func_ov010_02229a64(void) {
    extern u16 data_ov010_0222eee0;
    return data_ov010_0222eee0;
}

void func_ov010_02229a74(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_ov010_022269f8(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov010_0222efc0;
    func_ov010_022269f8(&data_ov010_0222efc0, arg0, arg1);
}

s32 func_ov010_02229a94(void) {
extern M2C_UNK data_ov010_0222efc0;
if(func_ov010_022282b4(2)) {
if(!func_0203a850(&data_ov010_0222efc0,0x6c))return 0;
}
if(func_ov010_022282b4(3)) {
func_ov010_02227f88(func_ov010_02229a08(),&data_ov010_0222efc0);
func_ov010_02229608(7,&data_ov010_0222efc0,0x6c,0xffff);
}
return 1;
}

M2C_UNK *func_ov010_02229b00(void) {
    extern M2C_UNK data_ov010_0222efc0;
    return &data_ov010_0222efc0;
}

s32 func_ov010_02229b0c(s32 a) {
extern M2C_UNK data_ov010_0222f02c;
s32 p;
if(!(func_ov010_02229a24()&(1<<a)))return 0;
p=(s32)&data_ov010_0222f02c+a*0x6c;
if(!(M2C_FIELD(p,u8 *,0x1a)&1))p=0;
return p;
}

s32 func_ov010_02229b48(s32 arg0) {
    extern M2C_UNK data_ov010_0222f02c;
    return (0x6C * arg0) + (s32) &data_ov010_0222f02c;
}

s32 func_ov010_02229b5c(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_02008048(s32, s32, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_ov010_02229b00();
    if (temp_r0 == 0) {
        return 0;
    }
    func_02008048(temp_r0 + 0x2C, arg0, arg1);
    return arg0;
}

s32 func_ov010_02229b90(void) {
    s32 func_ov010_02229b0c();
    s32 temp_r0;

    temp_r0 = func_ov010_02229b0c();
    if (temp_r0 != 0) {
        return temp_r0 + 0x2C;
    }
    return 0;
}

s32 func_ov010_02229ba8(s32 a,s32 b,s32 c) {
s32 p=func_ov010_02229b0c(a);
if(!p)return 0;func_02008048(p+0x2c,b,c);return b;
}

s32 func_ov010_02229bdc(void) {
    if (func_ov010_02229a08() == 0) return 1;
    return 0;
}

s32 func_ov010_02229bf4(void) {
    if (func_ov010_02229a08() != 0) return 1;
    return 0;
}

void func_ov010_02229c0c(void *p,s32 a) {
extern u16 data_ov010_0222eee0;
if(!func_ov010_022282b4(3))return;
M2C_FIELD(p,s32 *,0)=a;
M2C_FIELD(p,s16 *,4)=1<<func_ov010_02229a08();
M2C_FIELD(&data_ov010_0222eee0,void **,0x18)=p;
if(!func_ov010_02229bdc())return;
func_ov010_02229608(2,M2C_FIELD(&data_ov010_0222eee0,void **,0x18),8,0xffff);
}

s32 func_ov010_02229c74(void) {
    u16 func_ov010_02229a24();
    s32 func_ov010_022282b4(s32);
    s32 func_ov010_022282f8();
    s32 func_ov010_02229bdc();
    M2C_UNK func_ov010_02229608(M2C_UNK, void *, s32, s32);
    extern u16 data_ov010_0222eee0;
    s32 temp_r4;
    s32 var_r5;
    s32 t;
    temp_r4 = func_ov010_02229a24();
    var_r5 = 0;
    if (M2C_FIELD(&data_ov010_0222eee0, void **, 0x18) != NULL &&
        temp_r4 != (temp_r4 & M2C_FIELD(M2C_FIELD(&data_ov010_0222eee0, void **, 0x18), u16 *, 4))) var_r5 = 1;
    if (func_ov010_022282b4(3) == 0) var_r5 = 0;
    t = (func_ov010_022282f8() != 0);
    if (t) var_r5 = 0;
    if (!(temp_r4 & 1)) var_r5 = 0;
    if (var_r5 == 0 && func_ov010_02229bdc() != 0)
        func_ov010_02229608(3, M2C_FIELD(&data_ov010_0222eee0, void **, 0x18), 8, 0xFFFF);
    return var_r5;
}

