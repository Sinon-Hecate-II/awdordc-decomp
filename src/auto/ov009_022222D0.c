/* 30 functions from 0x022222D0 to 0x02223290 (ov009), found by ds-decomp. */
#include "common.h"

static inline u32 ov009DisableInterrupts(void) {
    u32 previous = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    return previous;
}
static inline u32 ov009RestoreInterrupts(u32 saved) {
    u32 previous = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = saved;
    return previous;
}
#pragma cplusplus on
class Ov009InterruptGuard {
    u32 saved;
public:
    Ov009InterruptGuard() : saved(ov009DisableInterrupts()) {}
    ~Ov009InterruptGuard() { ov009RestoreInterrupts(saved); }
};
class Ov009Callback { public: void run(); };
typedef void (Ov009Callback::*Ov009CallbackFn)();
struct Ov009Functor {
 Ov009CallbackFn fn;
 explicit Ov009Functor(Ov009CallbackFn p):fn(p) {}
 Ov009Functor(const Ov009Functor& other):fn(other.fn) {}
 void operator()(u8 *p) const { (((Ov009Callback *)p)->*fn)(); }
};
static inline void ov009Apply(u8 *first,u8 *end,s32 size,Ov009Functor fn) {
 if(size) do { fn(first); first+=12; } while(first!=end);
}
#pragma push
#pragma optimization_level 1
static inline void ov009CallRange(u8 *first,s32 size,Ov009CallbackFn fn) {
 if(size) { u8 *end=first+size; do { (((Ov009Callback *)first)->*fn)(); first+=12; } while(first!=end); }
}
#pragma pop
#pragma cplusplus off


void func_ov009_022222d0(s32 arg0) {
    M2C_UNK func_02007f8c(void *, M2C_UNK, M2C_UNK);
    M2C_UNK func_02008048(s32, void *, s32);
    s32 func_0208206c();
    s32 func_02082088();
    s32 func_020c5400(void *);
    M2C_UNK func_ov009_02224d9c(M2C_UNK, void *, M2C_UNK, u16);
    u8 spC[0x1C];
    u8 sp0[0xC];
    s32 temp_r4;
    if (func_020c5400(sp0) == 0) return;
    func_02007f8c(spC,0,0x1A);
    temp_r4=func_0208206c();
    func_02008048(temp_r4,spC,func_02082088()*2);
    func_ov009_02224d9c(0xF,sp0,0x28,(u16)(1<<arg0));
}

#pragma scheduling off
s32 func_ov009_02222348(s32 arg0) {
M2C_UNK func_02008048(s32,void *,s32);
s32 func_0206527c(s32,void *,s32);
extern M2C_UNK data_ov009_02226cc0, data_ov009_02226d80, data_ov009_02226d84;
s32 freeIndex; s32 i; u8 *p; s32 offset; s32 equal;
freeIndex=-1;i=0;p=(u8 *)&data_ov009_02226cc0;
do {
if(M2C_FIELD(p,s32*,0xc4)==0) { if(freeIndex<0)freeIndex=i; }
else {
if(func_0206527c(arg0+4,p+4,6)==0) equal=1; else equal=0;
if(equal) {
func_02008048(arg0,p,0xc0);
M2C_FIELD(p,u16*,0xc0)=0x1e0;
M2C_FIELD(p,s32*,0xc4)=1;
return 1;
}
}
i++;p+=0xc8;
}while(i<4);
if(freeIndex<0)return 0;
offset=freeIndex*0xc8;
func_02008048(arg0,(u8 *)&data_ov009_02226cc0+offset,0xc0);
p=(u8 *)&data_ov009_02226d80;
M2C_FIELD(p,u16*,offset)=0x1e0;
M2C_FIELD(&data_ov009_02226d84,s32*,offset)=1;
return 1;
}
#pragma scheduling on
s32 func_ov009_02222428(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xC4);
}

void func_ov009_02222430(s32 arg0) {
    extern M2C_UNK data_ov009_022268e0;
    M2C_FIELD(&data_ov009_022268e0, s32 *, 0x5C) = arg0;
}

u32 func_ov009_02222440(void) {
    extern M2C_UNK data_ov009_022268e0;
    s32 temp=M2C_FIELD(&data_ov009_022268e0,s32 *,0x5C)*4+2;
    return M2C_FIELD(&data_ov009_022268e0,u32 *,0x5C)=(u32)(temp*(temp+1))>>2;
}

void func_ov009_02222468(void *a) {
M2C_UNK func_ov009_02221338(void *,s32);
volatile u32 saved; u32 temp; void *p;
temp=*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=0;
p=M2C_FIELD(a,void **,0); saved=temp;
while(p!=0) {M2C_FIELD(a,void **,0)=M2C_FIELD(p,void **,0);func_ov009_02221338(p,M2C_FIELD(p,s32 *,12)+16);p=M2C_FIELD(a,void **,0);}
M2C_FIELD(a,s32 *,4)=0;M2C_FIELD(a,s32 *,0)=0;M2C_FIELD(a,s32 *,8)=0;
(void)*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=saved;
}

#pragma cplusplus on
#pragma optimization_level 2
extern "C" void func_ov009_022224e0(void) {
 s32 func_ov009_02221338(void *,s32);
 extern s32 data_ov009_022268e0;
 extern s32 data_ov009_02226980;
 extern s32 data_ov009_022269b0;
 extern s32 data_ov009_022269e0;
 extern Ov009CallbackFn data_ov009_022263e0[];
 volatile s32 saved;
 void *node;
 Ov009CallbackFn a,b;
 saved=*(volatile u16 *)0x04000208;
 *(volatile u16 *)0x04000208=0;
 node=M2C_FIELD(&data_ov009_022268e0,void **,0x64);
 if(node) do {
 M2C_FIELD(&data_ov009_022268e0,void **,0x64)=M2C_FIELD(node,void **,0);
 func_ov009_02221338(node,M2C_FIELD(node,s32 *,12)+16);
 node=M2C_FIELD(&data_ov009_022268e0,void **,0x64);
 } while(node);
 M2C_FIELD(&data_ov009_022268e0,s32 *,0x68)=0;
 M2C_FIELD(&data_ov009_022268e0,s32 *,0x64)=0;
 M2C_FIELD(&data_ov009_022268e0,s32 *,0x6c)=0;
 (void)*(volatile u16 *)0x04000208;
 *(volatile u16 *)0x04000208=saved;
 a=data_ov009_022263e0[1];
 ov009CallRange((u8 *)&data_ov009_02226980,48,a);
 b=data_ov009_022263e0[2];
 ov009CallRange((u8 *)&data_ov009_022269b0,48,b);
}
#pragma optimization_level 4
#pragma cplusplus off

#pragma cplusplus on
extern "C" s32 func_ov009_02222638(s32 arg0) {
extern M2C_UNK data_ov009_022268e0;
Ov009InterruptGuard guard;
void *node=M2C_FIELD(&data_ov009_022268e0,void **,0x64);
while(node) {
if(arg0==M2C_FIELD(node,u8 *,8))return 1;
node=M2C_FIELD(node,void **,0);
}
return 0;
}
#pragma cplusplus off
void func_ov009_022226b8(void *arg0) {
    void func_ov009_02222748();
    void *func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov009_022264b8;
    extern M2C_UNK data_ov009_022268e0;
    void *temp;
    if(M2C_FIELD(arg0,u16 *,2)==8) {
        func_ov009_02222748();
        func_ov009_02221320(8);
        func_02007958();
    }
    switch((u32)(M2C_FIELD(arg0,u16 *,4)-0x10)) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: break;
    default: break;
    case 0:
        temp=func_01ffa770(&data_ov009_022264b8);
        if(temp!=NULL) M2C_FIELD(temp,u16 *,0x34)=0;
        break;
    }
    if(M2C_FIELD(&data_ov009_022268e0,void (**)(void *),0x3C)==NULL) return;
    M2C_FIELD(&data_ov009_022268e0,void (**)(void *),0x3C)(arg0);
}

void func_ov009_02222748(arg0)
s32 arg0;
{
    s32 func_ov009_02224194();
    extern M2C_UNK data_ov009_022268e0;
    void *state;
    if (func_ov009_02224194() == 8) return;
    if (func_ov009_02224194() == 9) return;
    state=&data_ov009_022268e0;
    M2C_FIELD(state,s32 *,0xC)=arg0;
    if (M2C_FIELD(state,void (**)(s32,s32),0x2C)==NULL) return;
    M2C_FIELD(state,void (**)(s32,s32),0x2C)(arg0,0);
}

s32 func_ov009_02222790(void) {
    s32 func_02012218(M2C_UNK *, M2C_UNK *, M2C_UNK);
    void func_ov009_022227d4();
    extern M2C_UNK data_ov009_022277a0;
    extern M2C_UNK func_ov009_0222281c;
    func_ov009_02221320(3);
    if (func_02012218(&data_ov009_022277a0, &func_ov009_0222281c, 2) == 2) {
        return 1;
    }
    func_ov009_022227d4();
    func_ov009_02221320(9);
    return 0;
}

void func_ov009_022227d4(arg0)
s32 arg0;
{
    s32 func_ov009_02224194();
    extern M2C_UNK data_ov009_022268e0;
    void *state;
    if (func_ov009_02224194() == 8) return;
    if (func_ov009_02224194() == 9) return;
    state=&data_ov009_022268e0;
    M2C_FIELD(state,s32 *,0xC)=arg0;
    if (M2C_FIELD(state,void (**)(s32,s32),0x2C)==NULL) return;
    M2C_FIELD(state,void (**)(s32,s32),0x2C)(arg0,0);
}

void func_ov009_0222281c(void *arg0) {
    s32 func_020119dc(M2C_UNK *);
    M2C_UNK func_ov009_022244d4(M2C_UNK);
    void func_ov009_022226b8(void *);
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov009_02222748();
        func_ov009_02221320(9);
        return;
    }
    if (func_020119dc((M2C_UNK *)func_ov009_022226b8) != 0) {
        func_ov009_02222748(M2C_FIELD(arg0, u16 *, 2));
        func_ov009_02221320(9);
        return;
    }
    func_ov009_022244d4(0);
    func_ov009_02221320(1);
}

s32 func_ov009_0222287c(u16 arg0) {
    s32 func_02011d58();
    void func_ov009_02222910();
    void func_ov009_02222a00(M2C_UNK, M2C_UNK);
    void func_ov009_02222958(void *);
    s32 mask=func_02011d58();
    if(mask==0x8000) {
        func_ov009_022227d4(3);
        func_ov009_02221320(8);
        return 3;
    }
    if(mask==0) {
        func_ov009_02222910(0x17);
        func_ov009_02221320(8);
        return 0x19;
    }
    while(!(mask & (1 << (arg0-1)))) {
        if((u32)arg0++>=0x10) return 0x19;
    }
    func_ov009_02222a00((M2C_UNK)&func_ov009_02222958,arg0);
}

void func_ov009_02222910(arg0)
s32 arg0;
{
    s32 func_ov009_02224194();
    extern M2C_UNK data_ov009_022268e0;
    void *state;
    if (func_ov009_02224194() == 8) return;
    if (func_ov009_02224194() == 9) return;
    state=&data_ov009_022268e0;
    M2C_FIELD(state,s32 *,0xC)=arg0;
    if (M2C_FIELD(state,void (**)(s32,s32),0x2C)==NULL) return;
    M2C_FIELD(state,void (**)(s32,s32),0x2C)(arg0,0);
}

void func_ov009_02222958(void *arg0) {
    M2C_UNK func_ov009_02221320(M2C_UNK);
    void func_ov009_02222748();
    s32 func_ov009_0222287c(u16);
    extern M2C_UNK data_ov009_022268e0;
    u16 temp_r1;
    u16 temp_r3;
    u16 temp_r2;
    u16 temp_ip;
    s32 temp_r0;

    temp_r1 = M2C_FIELD(arg0, u16 *, 2);
    if (temp_r1 != 0) {
        func_ov009_02222748(temp_r1);
        func_ov009_02221320(8);
        return;
    }
    temp_r3 = M2C_FIELD(arg0, u16 *, 0xA);
    temp_r2 = M2C_FIELD(&data_ov009_022268e0, u16 *, 0xA);
    temp_ip = M2C_FIELD(arg0, u16 *, 8);
    if (temp_r2 > temp_r3) {
        M2C_FIELD(&data_ov009_022268e0, u16 *, 0xA) = temp_r3;
        M2C_FIELD(&data_ov009_022268e0, u16 *, 4) = (u16) (1 << (temp_ip - 1));
    } else if (temp_r2 == temp_r3) {
        M2C_FIELD(&data_ov009_022268e0, u16 *, 4) = (u16) (M2C_FIELD(&data_ov009_022268e0, u16 *, 4) | (1 << (temp_ip - 1)));
    }
    temp_r0 = func_ov009_0222287c((u16) (temp_ip + 1));
    if (temp_r0 == 0x19) {
        func_ov009_02221320(6);
        return;
    }
    if (temp_r0 == 2) return;
    func_ov009_02221320(8);
}

void func_ov009_02222a00(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02013dac(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02013dac(arg0, 3, 0x11, arg1, 0x1E);
}

s16 func_ov009_02222a20(s32 arg0) {
    u32 func_02076614();
    u32 func_ov009_02222440();
    s16 result = 0;
    u32 temp = func_02076614();
    s32 n;
    u16 count;
    s32 i;
    if (temp == 1) {
        u32 z = (u32)(~arg0 & (arg0 - 1));
        n = 0x20 - (s32)_clz(z);
        result = n + 1;
    } else if (temp > 1U) {
        count = (temp * (func_ov009_02222440() & 0xFF)) >> 8;
        for (i = 0; i < 0x10; i++) {
            if ((arg0 & (1 << i)) != 0 && count-- == 0) {
                result = i + 1;
                break;
            }
        }
    }
    return result;
}

s32 func_ov009_02222ac4(void) {
    s32 func_020122ec(M2C_UNK *, M2C_UNK *);
    void func_ov009_022227d4();
    extern M2C_UNK data_ov009_022269e0;
    extern M2C_UNK func_ov009_02222b04;
    func_ov009_02221320(3);
    if (func_020122ec(&func_ov009_02222b04, &data_ov009_022269e0) == 2) return 1;
    func_ov009_022227d4();
    func_ov009_02221320(8);
    return 0;
}

void func_ov009_02222b04(void *arg0) {
    s32 func_ov009_02222b3c();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov009_02222748();
        func_ov009_02221320(8);
        return;
    }
    if (func_ov009_02222b3c() != 0) {
        return;
    }
    func_ov009_02221320(8);
}

s32 func_ov009_02222b3c(void) {
    s32 func_02012474(M2C_UNK *);
    M2C_UNK func_ov009_02224164(s32);
    M2C_UNK func_ov009_02225480();
    void func_ov009_022227d4();
    extern M2C_UNK func_ov009_02222b8c;
    s32 state = func_ov009_02224194();
    switch (state) {
    case 4:
    case 5: return 1;
    default:
        if (func_02012474(&func_ov009_02222b8c) != 2) {
            func_ov009_022227d4();
            return 0;
        }
        func_ov009_02224164(1);
        func_ov009_02225480();
        return 1;
    }
}

void func_ov009_02222b8c(void *arg0) {
    (void)arg0;
}

s32 func_ov009_02222e1c(void) {
void func_ov009_02223ac8(void *); void func_ov009_02222f0c(void *);
s32 func_ov009_02224194(void); M2C_UNK func_ov009_02221320(s32);
s32 func_02011a20(s32,void (*)(void *),s32);
s32 func_02012b08(void (*)(void *),M2C_UNK *,u16,M2C_UNK *,u16,s32);
extern M2C_UNK data_ov009_022268e0,data_ov009_022270e0,data_ov009_02227000;
s32 n=func_ov009_02224194();switch(n){case 4:case 5:return 1;default:break;}
if(func_02011a20(4,func_ov009_02223ac8,0)!=0) {func_ov009_022227d4();return 0;}
if(func_02011a20(12,func_ov009_02223ac8,0)!=0) {func_ov009_022227d4();return 0;}
M2C_FIELD(&data_ov009_022268e0,u8 *,0)=0;
func_ov009_02221320(4);
if(func_02012b08(func_ov009_02222f0c,&data_ov009_022270e0,(u16)M2C_FIELD(&data_ov009_022268e0,u32 *,0x34),&data_ov009_02227000,(u16)M2C_FIELD(&data_ov009_022268e0,u32 *,0x14),1)==2)return 1;
func_ov009_022227d4();return 0;
}

void func_ov009_02222f0c(void *arg0) {
 s8 func_ov009_02225450();
 extern M2C_UNK data_ov009_022268e0;
 u16 state = M2C_FIELD(arg0,u16 *,2);
 if(state != 0) {
 func_ov009_02222748(state);
 func_ov009_02221320(8);
 return;
 }
 switch(M2C_FIELD(arg0,u16 *,4)) {
 case 10:
 func_ov009_02221320(4);
 M2C_FIELD(&data_ov009_022268e0,u8 *,0x156) = M2C_FIELD(&data_ov009_022268e0,u8 *,0x156) | 1;
 M2C_FIELD(&data_ov009_022268e0,u8 *,0x157) = func_ov009_02225450();
 func_ov009_02223fbc();
 return;
 case 11: return;
 case 12: return;
 case 13: return;
 default: return;
 }
}

s32 func_ov009_02222f84(void) {
s32 func_02011d58(void); s32 func_02011e98(void); s32 func_020124c4(void *,void *);
extern M2C_UNK data_ov009_022268e0; extern M2C_UNK data_ov009_02226a80; extern M2C_UNK data_ov009_02226960; extern M2C_UNK func_ov009_02223078;
s32 mask; s32 result; u16 *state;
mask=func_02011d58();
if(mask==0x8000) {func_ov009_022227d4(3);return 0;}
if(mask==0) {func_ov009_02222910(0x17);return 0;}
state=(u16 *)&data_ov009_022268e0;
if(state[3]==0) {
do {
state[66]++;
if(state[66]>14) state[66]=1;
if(mask&(1<<(state[66]-1))) goto selected;
}while(1);
} else state[66]=state[3];
selected:
M2C_FIELD(&data_ov009_022268e0,u16 *,0x86)=func_02011e98();
M2C_FIELD(&data_ov009_022268e0,void **,0x80)=&data_ov009_02226a80;
result=func_020124c4(&func_ov009_02223078,&data_ov009_02226960);
if(result==2) return 1;
func_ov009_022227d4(result);
return 0;
}

void func_ov009_0222304c(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (M2C_FIELD(arg0, s16 *, 0xC0) - 1);
    if ((s32) M2C_FIELD(arg0, s16 *, 0xC0) <= 0) {
        M2C_FIELD(arg0, s32 *, 0xC4) = 0;
    }
}

void func_ov009_0222306c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0xC4) = 0;
}

#pragma scheduling off
void func_ov009_02223078(void *arg0) {
    void func_ov009_02222748(s32);
    M2C_UNK func_ov009_02221320(M2C_UNK);
    s32 func_ov009_02224194(void);
    s32 func_ov009_02223244(void);
    void func_020067a8(void *, s32);
    s32 func_0201a09c(void *);
    s32 func_ov009_02222f84(void);
    s32 func_ov009_02222348(s32);
    extern Ov009CallbackFn data_ov009_022263e0[];
    extern M2C_UNK data_ov009_02226cc0;
    extern M2C_UNK data_ov009_02226fe0;
    extern M2C_UNK data_ov009_02226a80;
    extern M2C_UNK data_ov009_022268e0;

    u32 buf[8];
    u8 *r5;
    u32 *r6 = buf;
    s32 x;
    u8 *r7;
    void *elem;
    void **tbl;
    void (*fn)(void *);
    u16 arg2v;
    u16 t8;
    s32 res;
    u16 v36;
    u32 cond;
    u16 v38;
    u32 rhs;
    u8 bb;
    void (*cb)(void *);
    void (*cb2)(void *);

    {
        s32 a = M2C_FIELD(&data_ov009_022263e0, u32 *, 0x18);
        s32 b = M2C_FIELD(&data_ov009_022263e0, u32 *, 0x1c);
        r6[3] = b;
        r6[2] = a;
        r6[4] = a;
        r6[5] = b;
        r6[0] = a;
        r6[1] = b;
    }
    r7 = (u8 *)&data_ov009_02226cc0;
    r5 = (u8 *)&data_ov009_02226fe0;
    goto test;
loop: {
        x = (s32)r6[1];
        elem = (void *)(r7 + (x >> 1));
        if (!(x & 1)) {
            fn = (void (*)(void *))r6[0];
        } else {
        tbl = *(void **)elem;
        fn = *(void (**)(void *))((u8 *)tbl+(s32)r6[0]);
        }
        fn(elem);
        r7 += 0xc8;
    }
test:
    if(r7 != r5) goto loop;

    arg2v = M2C_FIELD(arg0, u16 *, 2);
    buf[6] = buf[0];
    buf[7] = buf[1];

    if (arg2v != 0) {
        func_ov009_02222748(arg2v);
        func_ov009_02221320(8);
        return;
    }

    if (func_ov009_02224194() != 2) {
        if (func_ov009_02223244() != 0) return;
        func_ov009_02221320(8);
        return;
    }

    t8 = M2C_FIELD(arg0, u16 *, 8);
    if(t8==3 || t8==4) goto done;
    if (t8 == 5) {
        func_020067a8(&data_ov009_02226a80, 0xc0);
        if (M2C_FIELD(&data_ov009_022268e0, s32 *, 0x30) != 0 &&
            func_0201a09c(&data_ov009_02226a80) != 0) {
            cb = M2C_FIELD(&data_ov009_022268e0, void (**)(void *), 0x4c);
            if (cb != 0) cb(&data_ov009_02226a80);
        } else {
            v36 = M2C_FIELD(arg0, u16 *, 0x36);
            cond = 0;
            if (v36 >= 0x10) {
                v38 = M2C_FIELD(arg0, u16 *, 0x38);
                cond = (v38 == 1);
            }
            if (cond) {
                rhs = M2C_FIELD(&data_ov009_022268e0, u32 *, 0x108);
                if (M2C_FIELD(arg0, u32 *, 0x3c) == rhs) {
                    bb = M2C_FIELD(arg0, u8 *, 0x43);
                    if ((bb & 1) && !(bb & 2)) {
                        func_ov009_02222348((s32)&data_ov009_02226a80);
                        cb2 = M2C_FIELD(&data_ov009_022268e0, void (**)(void *), 0x4c);
                        if (cb2 != 0) cb2(&data_ov009_02226a80);
                    }
                }
            }
        }
    }

done:
    res = func_ov009_02222f84();
    if (res != 0) return;
    func_ov009_02221320(8);
}
#pragma scheduling reset
s32 func_ov009_02223244(void) {
    s32 func_02012700(void (*)(void *));
    void func_ov009_0222326c(void *);
    if (func_02012700(func_ov009_0222326c) == 2) return 1;
    func_ov009_022227d4();
    return 0;
}

void func_ov009_0222326c(void *arg0) {
    M2C_UNK func_ov009_02221320(M2C_UNK);
    void func_ov009_02222748();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_ov009_02222748();
        return;
    }
    func_ov009_02221320(1);
}

