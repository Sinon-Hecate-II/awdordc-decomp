/* 42 functions from 0x02228D1C to 0x02229D0C (ov010), found by ds-decomp. */
#include "common.h"
typedef struct Ov010MemberCall { s32 function; s32 adjustment; } Ov010MemberCall;
static inline void ov010CallMember(void *object, volatile Ov010MemberCall *call) {
s32 adj=call->adjustment;
void *self=(u8 *)object+(adj>>1);
s32 fn;
fn=(adj&1)?*(s32 *)(*(u8 **)self+call->function):call->function;
((void (*)(void *))fn)(self);
}
static inline void ov010CallArray(u8 *first,s32 size,Ov010MemberCall call) {
Ov010MemberCall copy;
u8 *last=first+size;
copy.function=call.function;copy.adjustment=call.adjustment;
while(first!=last) { ov010CallMember(first,&copy); first+=0x6c; }
}
#pragma cplusplus on
class Ov010Callback { public: void run(); };
typedef void (Ov010Callback::*Ov010CallbackFn)();
static inline void ov010MarkActive(Ov010CallbackFn *dest,Ov010CallbackFn *src,u8 *state) { *dest=*src; state[0x107]=1; }
struct Ov010Functor {
 Ov010CallbackFn fn;
 explicit Ov010Functor(Ov010CallbackFn value):fn(value) {}
 void operator()(Ov010Callback *object) const { (object->*fn)(); }
};
static inline Ov010Functor ov010Apply(Ov010Callback *first, Ov010Callback *last, Ov010Functor fn) {
 for (; first != last; first=(Ov010Callback *)((u8 *)first+0x6c)) fn(first);
 return fn;
}
static inline Ov010CallbackFn ov010ForEach(Ov010Callback *first, Ov010Callback *last, Ov010CallbackFn fn) {
 for (; first != last; first = (Ov010Callback *)((u8 *)first + 0x6c)) (first->*fn)();
 return fn;
}
static inline Ov010MemberCall ov010VisitArray(u8 *first,u8 *last,Ov010MemberCall call) {
Ov010MemberCall copy=call;
while(first!=last){ov010CallMember(first,&copy);first+=0x6c;}
return copy;
}
typedef struct Ov010Member { s32 function; s32 delta; } Ov010Member;
#pragma cplusplus off
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

#pragma cplusplus on
#pragma optimization_level 2
#pragma opt_dead_code off
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void func_ov010_02228d48(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void func_ov010_02226a88(void);
    void func_ov010_022282d4(s32);
    s32 func_ov010_02229450(s32);
    s32 func_ov010_02229438(s32);
    void func_ov010_02229a50(void);
    s32 func_ov000_0216a470(void);
    s32 func_ov000_0216a564(void);
    s32 func_ov000_0216a76c(void);
    s32 func_ov000_0216a7c4(void);
    void *func_020c4acc(void);
    M2C_UNK func_0203a850(M2C_UNK *, s32);
    s8 func_0203bf80(u32, s32, s32);
    s8 func_0203be54(s8, s32, s32);
    M2C_UNK func_02038838(s32, s32, s32, s32, s32, s32);
    M2C_UNK func_020675bc(M2C_UNK, s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_ov010_02228050(void);
    void func_ov010_02227fac(void);

    extern Ov010Member data_ov010_0222c128;
    extern M2C_UNK data_ov010_0222f02c;
    extern u8 data_ov010_0222f1dc[];
    extern u16 data_ov010_0222eee0;
    extern M2C_UNK data_ov010_0222efc0;
    extern M2C_UNK data_ov010_0222c404;
    extern M2C_UNK data_ov010_0222c414;
    extern M2C_UNK data_ov010_0222c41c;
    extern M2C_UNK data_ov010_0222ef10;
    extern M2C_UNK data_ov010_0222c42c;
    extern M2C_UNK data_ov010_0222ef3c;
    extern M2C_UNK data_ov010_0222c438;
    extern M2C_UNK data_ov010_0222ef28;
    extern M2C_UNK data_ov010_0222c440;
    extern M2C_UNK data_ov010_0222ef08;
    extern M2C_UNK data_ov010_0222c44c;
    extern M2C_UNK data_ov010_0222c488;

    Ov010CallbackFn a, b, c, d;
    u8 *p;
    u8 buf[0x80];

    func_ov010_02226a88();
    func_020c4acc();
    func_ov010_022282d4(3);
    func_ov010_022282d4(4);
    func_ov010_02229450(arg2);
    func_ov010_02229438(arg4);
    func_ov010_02229a50();
    a = *(Ov010CallbackFn *)&data_ov010_0222c128;
    b = a;
    c = b;
    for (p = (u8 *)&data_ov010_0222f02c; p != (u8 *)data_ov010_0222f1dc; p += 0x6c) {
        (((Ov010Callback *)p)->*c)();
    }
    M2C_FIELD(&data_ov010_0222eee0, u8 *, 0x107) = 0;
    d = c;
    M2C_FIELD(&data_ov010_0222eee0, u8 *, 0x108) = (u8)arg0;
    func_ov000_0216a470();
    M2C_FIELD(&data_ov010_0222eee0, u8 *, 0x104) = (u8)func_ov000_0216a564();
    M2C_FIELD(&data_ov010_0222eee0, u8 *, 0x105) = (u8)func_ov000_0216a76c();
    M2C_FIELD(&data_ov010_0222eee0, u8 *, 0x106) = (u8)func_ov000_0216a7c4();
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x100) = M2C_FIELD(func_020c4acc(), s32 *, 0x54);
    M2C_FIELD(&data_ov010_0222eee0, u8 *, 0xfa) |= 2;
    func_0203a850(&data_ov010_0222efc0, 0x6c);

    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x30) = (s32)M2C_FIELD(&data_ov010_0222eee0, s8 *, 0x107);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x5c) = (s32)M2C_FIELD(&data_ov010_0222eee0, s8 *, 0x108);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x48) = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x100);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x28) = arg5;

    func_0203bf80(0, (u32)&data_ov010_0222c404, (s32)&data_ov010_0222c414);

    func_0203be54(0, (s32)&data_ov010_0222c41c, (s32)&data_ov010_0222ef10);
    func_0203be54(0, (s32)&data_ov010_0222c42c, (s32)&data_ov010_0222ef3c);
    func_0203be54(0, (s32)&data_ov010_0222c438, (s32)&data_ov010_0222ef28);
    func_0203be54(0, (s32)&data_ov010_0222c440, (s32)&data_ov010_0222ef08);

    buf[0x7f] = 0;
    func_020675bc((M2C_UNK)buf, 0x7f, (M2C_UNK)&data_ov010_0222c44c, (M2C_UNK)&data_ov010_0222c488,
                   (M2C_UNK)M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x30),
                   (M2C_UNK)M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x5c));

    func_02038838(arg1 & 0xff, (s32)buf, (s32)func_ov010_02227fac, arg3, (s32)func_ov010_02228050, arg5);
}
#pragma cplusplus off

void func_ov010_02228f80(void) { }

#pragma cplusplus on
#pragma optimization_level 2
#pragma opt_dead_code off
extern "C" void func_ov010_02229190(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 arg5) {
 void func_ov010_02226a88(void);
 void func_ov010_02229a50(void);
 s32 func_ov010_02229468(s32);
 s32 func_ov010_02229480(s32);
 void func_ov010_022282d4(s32);
 s32 func_ov000_0216a470(void);
 s32 func_ov000_0216a564(void);
 s32 func_ov000_0216a76c(void);
 s32 func_ov000_0216a7c4(void);
 void *func_020c4acc(void);
 M2C_UNK func_0203a850(M2C_UNK *,s32);
 void func_02038a84(s32,void *,s32,void *,s32);
 void func_ov010_0222807c(void);
 void func_ov010_0222815c(void);
 extern Ov010Member data_ov010_0222c128;
 extern M2C_UNK data_ov010_0222f02c;
 extern u8 data_ov010_0222f1dc[];
 extern u16 data_ov010_0222eee0;
 extern M2C_UNK data_ov010_0222efc0;
 Ov010CallbackFn a,b,c,d;
 u8 *p;
 func_ov010_02226a88();
 func_ov010_022282d4(3);
 func_ov010_022282d4(4);
 func_ov010_02229468(arg2);
 func_ov010_02229480(arg4);
 func_ov010_02229a50();
 a = *(Ov010CallbackFn *)&data_ov010_0222c128;
 b = a;
 c = b;
 for(p=(u8 *)&data_ov010_0222f02c;p!=data_ov010_0222f1dc;p+=0x6c) {
  (((Ov010Callback *)p)->*c)();
 }
 M2C_FIELD(&data_ov010_0222eee0,u8 *,0x107)=1;
 d=c;
 M2C_FIELD(&data_ov010_0222eee0,u8 *,0x108)=arg0;
 func_ov000_0216a470();
 M2C_FIELD(&data_ov010_0222eee0,u8 *,0x104)=func_ov000_0216a564();
 M2C_FIELD(&data_ov010_0222eee0,u8 *,0x105)=func_ov000_0216a76c();
 M2C_FIELD(&data_ov010_0222eee0,u8 *,0x106)=func_ov000_0216a7c4();
 M2C_FIELD(&data_ov010_0222eee0,s32 *,0x100)=M2C_FIELD(func_020c4acc(),s32 *,0x54);
 M2C_FIELD(&data_ov010_0222eee0,u8 *,0xfa)|=2;
 func_0203a850(&data_ov010_0222efc0,0x6c);
 func_02038a84(arg1&255,func_ov010_0222807c,arg3,func_ov010_0222815c,arg5);
}
#pragma cplusplus on
#pragma opt_dead_assignments off
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void func_ov010_022292e4(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 arg5) {
 void func_ov010_02226a88(void);
 void func_ov010_02229a50(void);
 s32 func_ov010_02229468(s32);
 s32 func_ov010_02229480(s32);
 void func_ov010_022282d4(s32);
 s32 func_ov000_0216a470(void);
 s32 func_ov000_0216a564(void);
 s32 func_ov000_0216a76c(void);
 s32 func_ov000_0216a7c4(void);
 void *func_020c4acc(void);
 M2C_UNK func_0203a850(M2C_UNK *,s32);
 void func_02038b1c(s32,void *,s32,void *,s32);
 void func_ov010_0222807c(void);
 void func_ov010_0222815c(void);
 extern Ov010Member data_ov010_0222c128;
 extern M2C_UNK data_ov010_0222f02c;
 extern u8 data_ov010_0222f1dc[];
 extern u16 data_ov010_0222eee0;
 extern M2C_UNK data_ov010_0222efc0;
 Ov010CallbackFn c,a,b,d;
 u8 *p;
 func_ov010_02226a88();
 func_ov010_022282d4(3);
 func_ov010_022282d4(4);
 func_ov010_02229468(arg2);
 func_ov010_02229480(arg4);
 func_ov010_02229a50();
 a = *(Ov010CallbackFn *)&data_ov010_0222c128;
 b = a;
 c = b;
 for(p=(u8 *)&data_ov010_0222f02c;p!=data_ov010_0222f1dc;p+=0x6c) {
  (((Ov010Callback *)p)->*c)();
 }
 d=c;
 M2C_FIELD(&data_ov010_0222eee0,u8 *,0x107)=1;
 M2C_FIELD(&data_ov010_0222eee0,u8 *,0x108)=arg0;
 func_ov000_0216a470();
 M2C_FIELD(&data_ov010_0222eee0,u8 *,0x104)=func_ov000_0216a564();
 M2C_FIELD(&data_ov010_0222eee0,u8 *,0x105)=func_ov000_0216a76c();
 M2C_FIELD(&data_ov010_0222eee0,u8 *,0x106)=func_ov000_0216a7c4();
 M2C_FIELD(&data_ov010_0222eee0,s32 *,0x100)=M2C_FIELD(func_020c4acc(),s32 *,0x54);
M2C_FIELD(&data_ov010_0222eee0,u8 *,0xfa)=2|M2C_FIELD(&data_ov010_0222eee0,u8 *,0xfa);
func_0203a850(&data_ov010_0222efc0,0x6c);
func_02038b1c(arg1,(void *)func_ov010_0222807c,arg3,(void *)func_ov010_0222815c,arg5);
}
#pragma cplusplus off

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

s32 func_ov010_02229608(u8 arg0, void *arg1, s32 arg2, u16 arg3) {
    s32 func_ov010_022282b4(s32);
    u16 func_ov010_02229a24();
    s32 func_ov010_02229a08();
    M2C_UNK func_ov010_022268f4(M2C_UNK, s32, s32);
    void func_02007f8c(void *, s32, s32);
    extern u16 data_ov010_0222eee0;
    QueueNode *node;
    s32 mode;
    volatile s32 saved;
    s32 ret;

    if (func_ov010_022282b4(3) == 0) return 0;
    arg3 &= func_ov010_02229a24();
    arg3 = (u16)(arg3 & (-1 ^ (1 << func_ov010_02229a08())));
    mode = func_ov010_02229a08();
    saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    node = (QueueNode *)func_ov010_022268f4(0, arg2 + 0x10, 0x20);
    if (node == NULL) {
        (void)*(volatile u16 *)0x04000208;
        ret = 0;
        *(volatile u16 *)0x04000208 = saved;
    } else {
        func_02007f8c(node, 0, 0x10);
        func_ov010_0222959c((u8 *)node + 4, arg0, mode, 0, (s32)arg1, arg2, arg3);
        if (M2C_FIELD(&data_ov010_0222eee0, QueueNode **, 0x64) == NULL) {
            M2C_FIELD(&data_ov010_0222eee0, QueueNode **, 0x64) = node;
            M2C_FIELD(&data_ov010_0222eee0, QueueNode **, 0x60) = node;
        } else {
            M2C_FIELD(M2C_FIELD(&data_ov010_0222eee0, QueueNode **, 0x64), QueueNode **, 0) = node;
            M2C_FIELD(&data_ov010_0222eee0, QueueNode **, 0x64) = node;
        }
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x68)++;
        (void)*(volatile u16 *)0x04000208;
        ret = 1;
        *(volatile u16 *)0x04000208 = saved;
    }
    return ret != 0;
}

s32 func_ov010_0222972c(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 func_ov010_022282b4(s32);
    u16 func_ov010_02229a24();
    s32 func_ov010_02229a08();
    M2C_UNK func_ov010_022268f4(M2C_UNK, s32, s32);
    void func_02007f8c(void *, s32, s32);
    void *func_ov010_0222959c(void *, u8, s32, s32, s32, s32, u16);
    extern u16 data_ov010_0222eee0;
    QueueNode *node;
    s32 mode;
    volatile s32 saved;
    s32 ret;

    if (func_ov010_022282b4(3) == 0) return 0;
    arg3 = arg3 & func_ov010_02229a24();
    arg3 = (s32)(u16)(arg3 & (-1 ^ (1 << func_ov010_02229a08())));
    mode = func_ov010_02229a08();
    saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    node = (QueueNode *)func_ov010_022268f4(0, arg2 + 0x10, 0x20);
    if (node == NULL) {
        (void)*(volatile u16 *)0x04000208;
        *(volatile u16 *)0x04000208 = saved;
        ret = 0;
    } else {
        func_02007f8c(node, 0, 0x10);
        func_ov010_0222959c((u8 *)node + 4, arg0, mode, 1, (s32)arg1, arg2, (u16)arg3);
        if (M2C_FIELD(&data_ov010_0222eee0, QueueNode **, 0x64) == 0) {
            M2C_FIELD(&data_ov010_0222eee0, QueueNode **, 0x64) = node;
            M2C_FIELD(&data_ov010_0222eee0, QueueNode **, 0x60) = node;
        } else {
            M2C_FIELD(M2C_FIELD(&data_ov010_0222eee0, QueueNode **, 0x64), QueueNode **, 0) = node;
            M2C_FIELD(&data_ov010_0222eee0, QueueNode **, 0x64) = node;
        }
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x68)++;
        (void)*(volatile u16 *)0x04000208;
        *(volatile u16 *)0x04000208 = saved;
        ret = 1;
    }
    return ret != 0;
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

