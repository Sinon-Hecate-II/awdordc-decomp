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
    M2C_UNK MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
    M2C_UNK MI_CpuCopy8(s32, void *, s32);
    s32 func_0208206c();
    s32 func_02082088();
    s32 func_020c5400(void *);
    M2C_UNK func_ov009_02224d9c(M2C_UNK, void *, M2C_UNK, u16);
    u8 spC[0x1C];
    u8 sp0[0xC];
    s32 temp_r4;
    if (func_020c5400(sp0) == 0) return;
    MI_CpuFill8(spC,0,0x1A);
    temp_r4=func_0208206c();
    MI_CpuCopy8(temp_r4,spC,func_02082088()*2);
    func_ov009_02224d9c(0xF,sp0,0x28,(u16)(1<<arg0));
}

#pragma scheduling off
s32 func_ov009_02222348(s32 arg0) {
M2C_UNK MI_CpuCopy8(s32,void *,s32);
s32 ByteCompareN(s32,void *,s32);
extern M2C_UNK data_ov009_02226cc0, data_ov009_02226d80, data_ov009_02226d84;
s32 freeIndex; s32 i; u8 *p; s32 offset; s32 equal;
freeIndex=-1;i=0;p=(u8 *)&data_ov009_02226cc0;
do {
if(M2C_FIELD(p,s32*,0xc4)==0) { if(freeIndex<0)freeIndex=i; }
else {
if(ByteCompareN(arg0+4,p+4,6)==0) equal=1; else equal=0;
if(equal) {
MI_CpuCopy8(arg0,p,0xc0);
M2C_FIELD(p,u16*,0xc0)=0x1e0;
M2C_FIELD(p,s32*,0xc4)=1;
return 1;
}
}
i++;p+=0xc8;
}while(i<4);
if(freeIndex<0)return 0;
offset=freeIndex*0xc8;
MI_CpuCopy8(arg0,(u8 *)&data_ov009_02226cc0+offset,0xc0);
{
void *base = &data_ov009_02226d80;
*(u16 *)((char *)base + offset) = 0x1e0;
base = &data_ov009_02226d84;
*(s32 *)((char *)base + offset) = 1;
}
return 1;
}
#pragma scheduling on
s32 func_ov009_02222428(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0xC4);
}

void func_ov009_02222430(s32 arg0) {
    extern M2C_UNK gLinkState;
    M2C_FIELD(&gLinkState, s32 *, 0x5C) = arg0;
}

u32 func_ov009_02222440(void) {
    extern M2C_UNK gLinkState;
    s32 temp=M2C_FIELD(&gLinkState,s32 *,0x5C)*4+2;
    return M2C_FIELD(&gLinkState,u32 *,0x5C)=(u32)(temp*(temp+1))>>2;
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
 extern s32 gLinkState;
 extern s32 data_ov009_02226980;
 extern s32 data_ov009_022269b0;
 extern s32 data_ov009_022269e0;
 extern Ov009CallbackFn gLinkSession[];
 volatile s32 saved;
 void *node;
 Ov009CallbackFn a,b;
 saved=*(volatile u16 *)0x04000208;
 *(volatile u16 *)0x04000208=0;
 node=M2C_FIELD(&gLinkState,void **,0x64);
 if(node) do {
 M2C_FIELD(&gLinkState,void **,0x64)=M2C_FIELD(node,void **,0);
 func_ov009_02221338(node,M2C_FIELD(node,s32 *,12)+16);
 node=M2C_FIELD(&gLinkState,void **,0x64);
 } while(node);
 M2C_FIELD(&gLinkState,s32 *,0x68)=0;
 M2C_FIELD(&gLinkState,s32 *,0x64)=0;
 M2C_FIELD(&gLinkState,s32 *,0x6c)=0;
 (void)*(volatile u16 *)0x04000208;
 *(volatile u16 *)0x04000208=saved;
 a=gLinkSession[1];
 ov009CallRange((u8 *)&data_ov009_02226980,48,a);
 b=gLinkSession[2];
 ov009CallRange((u8 *)&data_ov009_022269b0,48,b);
}
#pragma optimization_level 4
#pragma cplusplus off

#pragma cplusplus on
extern "C" s32 func_ov009_02222638(s32 arg0) {
extern M2C_UNK gLinkState;
Ov009InterruptGuard guard;
void *node=M2C_FIELD(&gLinkState,void **,0x64);
while(node) {
if(arg0==M2C_FIELD(node,u8 *,8))return 1;
node=M2C_FIELD(node,void **,0);
}
return 0;
}
#pragma cplusplus off
void func_ov009_022226b8(void *arg0) {
    void SignalLinkEvent();
    void *FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gLinkActorClass;
    extern M2C_UNK gLinkState;
    void *temp;
    if(M2C_FIELD(arg0,u16 *,2)==8) {
        SignalLinkEvent();
        SetLinkPhase(8);
        SystemHalt();
    }
    switch((u32)(M2C_FIELD(arg0,u16 *,4)-0x10)) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: break;
    default: break;
    case 0:
        temp=FindObjectByClass(&gLinkActorClass);
        if(temp!=NULL) M2C_FIELD(temp,u16 *,0x34)=0;
        break;
    }
    if(M2C_FIELD(&gLinkState,void (**)(void *),0x3C)==NULL) return;
    M2C_FIELD(&gLinkState,void (**)(void *),0x3C)(arg0);
}

void SignalLinkEvent(arg0)
s32 arg0;
{
    s32 GetLinkPhase();
    extern M2C_UNK gLinkState;
    void *state;
    if (GetLinkPhase() == 8) return;
    if (GetLinkPhase() == 9) return;
    state=&gLinkState;
    M2C_FIELD(state,s32 *,0xC)=arg0;
    if (M2C_FIELD(state,void (**)(s32,s32),0x2C)==NULL) return;
    M2C_FIELD(state,void (**)(s32,s32),0x2C)(arg0,0);
}

s32 func_ov009_02222790(void) {
    s32 func_02012218(M2C_UNK *, M2C_UNK *, M2C_UNK);
    void SignalLinkError();
    extern M2C_UNK data_ov009_022277a0;
    extern M2C_UNK func_ov009_0222281c;
    SetLinkPhase(3);
    if (func_02012218(&data_ov009_022277a0, &func_ov009_0222281c, 2) == 2) {
        return 1;
    }
    SignalLinkError();
    SetLinkPhase(9);
    return 0;
}

void SignalLinkError(arg0)
s32 arg0;
{
    s32 GetLinkPhase();
    extern M2C_UNK gLinkState;
    void *state;
    if (GetLinkPhase() == 8) return;
    if (GetLinkPhase() == 9) return;
    state=&gLinkState;
    M2C_FIELD(state,s32 *,0xC)=arg0;
    if (M2C_FIELD(state,void (**)(s32,s32),0x2C)==NULL) return;
    M2C_FIELD(state,void (**)(s32,s32),0x2C)(arg0,0);
}

void func_ov009_0222281c(void *arg0) {
    s32 func_020119dc(M2C_UNK *);
    M2C_UNK func_ov009_022244d4(M2C_UNK);
    void func_ov009_022226b8(void *);
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SignalLinkEvent();
        SetLinkPhase(9);
        return;
    }
    if (func_020119dc((M2C_UNK *)func_ov009_022226b8) != 0) {
        SignalLinkEvent(M2C_FIELD(arg0, u16 *, 2));
        SetLinkPhase(9);
        return;
    }
    func_ov009_022244d4(0);
    SetLinkPhase(1);
}

s32 func_ov009_0222287c(u16 arg0) {
    s32 func_02011d58();
    void SignalLinkResult();
    void func_ov009_02222a00(M2C_UNK, M2C_UNK);
    void func_ov009_02222958(void *);
    s32 mask=func_02011d58();
    if(mask==0x8000) {
        SignalLinkError(3);
        SetLinkPhase(8);
        return 3;
    }
    if(mask==0) {
        SignalLinkResult(0x17);
        SetLinkPhase(8);
        return 0x19;
    }
    while(!(mask & (1 << (arg0-1)))) {
        if((u32)arg0++>=0x10) return 0x19;
    }
    func_ov009_02222a00((M2C_UNK)&func_ov009_02222958,arg0);
}

void SignalLinkResult(arg0)
s32 arg0;
{
    s32 GetLinkPhase();
    extern M2C_UNK gLinkState;
    void *state;
    if (GetLinkPhase() == 8) return;
    if (GetLinkPhase() == 9) return;
    state=&gLinkState;
    M2C_FIELD(state,s32 *,0xC)=arg0;
    if (M2C_FIELD(state,void (**)(s32,s32),0x2C)==NULL) return;
    M2C_FIELD(state,void (**)(s32,s32),0x2C)(arg0,0);
}

void func_ov009_02222958(void *arg0) {
    M2C_UNK SetLinkPhase(M2C_UNK);
    void SignalLinkEvent();
    s32 func_ov009_0222287c(u16);
    extern M2C_UNK gLinkState;
    u16 temp_r1;
    u16 temp_r3;
    u16 temp_r2;
    u16 temp_ip;
    s32 temp_r0;

    temp_r1 = M2C_FIELD(arg0, u16 *, 2);
    if (temp_r1 != 0) {
        SignalLinkEvent(temp_r1);
        SetLinkPhase(8);
        return;
    }
    temp_r3 = M2C_FIELD(arg0, u16 *, 0xA);
    temp_r2 = M2C_FIELD(&gLinkState, u16 *, 0xA);
    temp_ip = M2C_FIELD(arg0, u16 *, 8);
    if (temp_r2 > temp_r3) {
        M2C_FIELD(&gLinkState, u16 *, 0xA) = temp_r3;
        M2C_FIELD(&gLinkState, u16 *, 4) = (u16) (1 << (temp_ip - 1));
    } else if (temp_r2 == temp_r3) {
        M2C_FIELD(&gLinkState, u16 *, 4) = (u16) (M2C_FIELD(&gLinkState, u16 *, 4) | (1 << (temp_ip - 1)));
    }
    temp_r0 = func_ov009_0222287c((u16) (temp_ip + 1));
    if (temp_r0 == 0x19) {
        SetLinkPhase(6);
        return;
    }
    if (temp_r0 == 2) return;
    SetLinkPhase(8);
}

void func_ov009_02222a00(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02013dac(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02013dac(arg0, 3, 0x11, arg1, 0x1E);
}

s32 __clz(u32);
s32 __cntlz(u32);
s32 _CountLeadingZeros(u32);
s32 __builtin_clz(u32);
#pragma intrinsic(__builtin_clz)
s16 func_ov009_02222a20(s32 arg0) {
u32 CountBits();u32 func_ov009_02222440();s32 __builtin_clz(u32);
s16 result=0;u32 temp=CountBits();s32 n;u16 count;s32 i;
if(temp==1){n=0x20-__builtin_clz(~arg0&(arg0-1));result=n+1;}
else if(temp>1U){
count=(temp*(func_ov009_02222440()&255))>>8;
i=result;goto test;
loop: {if((arg0&(1<<i))!=0 && count--==0){result=i+1;goto done;}i++;}
test:if(i<16)goto loop;
}
done:return result;
}
s32 func_ov009_02222ac4(void) {
    s32 func_020122ec(M2C_UNK *, M2C_UNK *);
    void SignalLinkError();
    extern M2C_UNK data_ov009_022269e0;
    extern M2C_UNK func_ov009_02222b04;
    SetLinkPhase(3);
    if (func_020122ec(&func_ov009_02222b04, &data_ov009_022269e0) == 2) return 1;
    SignalLinkError();
    SetLinkPhase(8);
    return 0;
}

void func_ov009_02222b04(void *arg0) {
    s32 func_ov009_02222b3c();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SignalLinkEvent();
        SetLinkPhase(8);
        return;
    }
    if (func_ov009_02222b3c() != 0) {
        return;
    }
    SetLinkPhase(8);
}

s32 func_ov009_02222b3c(void) {
    s32 func_02012474(M2C_UNK *);
    M2C_UNK SetConnectedPlayers(s32);
    M2C_UNK func_ov009_02225480();
    void SignalLinkError();
    extern M2C_UNK func_ov009_02222b8c;
    s32 state = GetLinkPhase();
    switch (state) {
    case 4:
    case 5: return 1;
    default:
        if (func_02012474(&func_ov009_02222b8c) != 2) {
            SignalLinkError();
            return 0;
        }
        SetConnectedPlayers(1);
        func_ov009_02225480();
        return 1;
    }
}

void func_ov009_02222b8c(void *arg0) {
    (void)arg0;
}

s32 func_ov009_02222e1c(void) {
void func_ov009_02223ac8(void *); void func_ov009_02222f0c(void *);
s32 GetLinkPhase(void); M2C_UNK SetLinkPhase(s32);
s32 func_02011a20(s32,void (*)(void *),s32);
s32 func_02012b08(void (*)(void *),M2C_UNK *,u16,M2C_UNK *,u16,s32);
extern M2C_UNK gLinkState,data_ov009_022270e0,data_ov009_02227000;
s32 n=GetLinkPhase();switch(n){case 4:case 5:return 1;default:break;}
if(func_02011a20(4,func_ov009_02223ac8,0)!=0) {SignalLinkError();return 0;}
if(func_02011a20(12,func_ov009_02223ac8,0)!=0) {SignalLinkError();return 0;}
M2C_FIELD(&gLinkState,u8 *,0)=0;
SetLinkPhase(4);
if(func_02012b08(func_ov009_02222f0c,&data_ov009_022270e0,(u16)M2C_FIELD(&gLinkState,u32 *,0x34),&data_ov009_02227000,(u16)M2C_FIELD(&gLinkState,u32 *,0x14),1)==2)return 1;
SignalLinkError();return 0;
}

void func_ov009_02222f0c(void *arg0) {
 s8 func_ov009_02225450();
 extern M2C_UNK gLinkState;
 u16 state = M2C_FIELD(arg0,u16 *,2);
 if(state != 0) {
 SignalLinkEvent(state);
 SetLinkPhase(8);
 return;
 }
 switch(M2C_FIELD(arg0,u16 *,4)) {
 case 10:
 SetLinkPhase(4);
 M2C_FIELD(&gLinkState,u8 *,0x156) = M2C_FIELD(&gLinkState,u8 *,0x156) | 1;
 M2C_FIELD(&gLinkState,u8 *,0x157) = func_ov009_02225450();
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
extern M2C_UNK gLinkState; extern M2C_UNK data_ov009_02226a80; extern M2C_UNK data_ov009_02226960; extern M2C_UNK func_ov009_02223078;
s32 bits; s32 result;
bits=func_02011d58();
if(bits==0x8000) {SignalLinkError(3);return 0;}
if(bits==0) {SignalLinkResult(0x17);return 0;}
if(M2C_FIELD(&gLinkState,u16 *,6)==0) {
do {
M2C_FIELD(&gLinkState,u16 *,0x84)++;
if(M2C_FIELD(&gLinkState,u16 *,0x84)>14) M2C_FIELD(&gLinkState,u16 *,0x84)=1;
} while(!(bits&(1<<(M2C_FIELD(&gLinkState,u16 *,0x84)-1))));
} else M2C_FIELD(&gLinkState,u16 *,0x84)=M2C_FIELD(&gLinkState,u16 *,6);
M2C_FIELD(&gLinkState,u16 *,0x86)=func_02011e98();
M2C_FIELD(&gLinkState,void **,0x80)=&data_ov009_02226a80;
result=func_020124c4(&func_ov009_02223078,&data_ov009_02226960);
if(result==2) return 1;
SignalLinkError(result);
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
    void SignalLinkEvent(s32);
    M2C_UNK SetLinkPhase(M2C_UNK);
    s32 GetLinkPhase(void);
    s32 func_ov009_02223244(void);
    void DC_InvalidateRange(void *, s32);
    s32 func_0201a09c(void *);
    s32 func_ov009_02222f84(void);
    s32 func_ov009_02222348(s32);
    extern Ov009CallbackFn gLinkSession[];
    extern M2C_UNK data_ov009_02226cc0;
    extern M2C_UNK data_ov009_02226fe0;
    extern M2C_UNK data_ov009_02226a80;
    extern M2C_UNK gLinkState;

    s32 buf[8];
    u8 *r5;
    s32 *r6 = buf;
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
        s32 a = M2C_FIELD(&gLinkSession, u32 *, 0x18);
        s32 b = M2C_FIELD(&gLinkSession, u32 *, 0x1c);
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
        SignalLinkEvent(arg2v);
        SetLinkPhase(8);
        return;
    }

    if (GetLinkPhase() != 2) {
        if (func_ov009_02223244() != 0) return;
        SetLinkPhase(8);
        return;
    }

    t8 = M2C_FIELD(arg0, u16 *, 8);
    if(t8==3 || t8==4) goto done;
    if (t8 == 5) {
        DC_InvalidateRange(&data_ov009_02226a80, 0xc0);
        if (M2C_FIELD(&gLinkState, s32 *, 0x30) != 0 &&
            func_0201a09c(&data_ov009_02226a80) != 0) {
            cb = M2C_FIELD(&gLinkState, void (**)(void *), 0x4c);
            if (cb != 0) cb(&data_ov009_02226a80);
        } else {
            v36 = M2C_FIELD(arg0, u16 *, 0x36);
            cond = 0;
            if (v36 >= 0x10) {
                v38 = M2C_FIELD(arg0, u16 *, 0x38);
                cond = (v38 == 1);
            }
            if (cond) {
                rhs = M2C_FIELD(&gLinkState, u32 *, 0x108);
                if (M2C_FIELD(arg0, u32 *, 0x3c) == rhs) {
                    bb = M2C_FIELD(arg0, u8 *, 0x43);
                    if ((bb & 1) && !(bb & 2)) {
                        func_ov009_02222348((s32)&data_ov009_02226a80);
                        cb2 = M2C_FIELD(&gLinkState, void (**)(void *), 0x4c);
                        if (cb2 != 0) cb2(&data_ov009_02226a80);
                    }
                }
            }
        }
    }

done:
    res = func_ov009_02222f84();
    if (res != 0) return;
    SetLinkPhase(8);
}
#pragma scheduling reset
s32 func_ov009_02223244(void) {
    s32 func_02012700(void (*)(void *));
    void func_ov009_0222326c(void *);
    if (func_02012700(func_ov009_0222326c) == 2) return 1;
    SignalLinkError();
    return 0;
}

void func_ov009_0222326c(void *arg0) {
    M2C_UNK SetLinkPhase(M2C_UNK);
    void SignalLinkEvent();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SignalLinkEvent();
        return;
    }
    SetLinkPhase(1);
}

