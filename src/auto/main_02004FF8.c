/* 56 functions from 0x02004FF8 to 0x02005F80 (main), found by ds-decomp. */
#include "common.h"
static inline u8 *stack_end_02005968(void) {
extern M2C_UNK data_027e0000;
extern char data_00000800[];
return (u8 *)&data_027e0000+0x3f80-(s32)data_00000800;
}
static inline u8 *stack_start_02005968(void) {
extern char data_00000000[];
s32 size=(s32)data_00000000;
u8 *p;
if(size<=0)p=(u8 *)0x027e15e0;
else p=stack_end_02005968();
return p-size;
}

void func_02004ff8(u32 arg0, s32 arg1) {
    extern M2C_UNK data_0212dc1c;
    extern M2C_UNK data_027e0000;
    s32 i;
    s32 *entry;
    i = 0;
    do {
        if (arg0 & 1) {
            entry = NULL;
            if (i >= 8 && i <= 11) {
                entry = (s32 *)((s8 *)&data_0212dc1c + (i - 8) * sizeof(s32[3]));
            } else if (i >= 3 && i <= 6) {
                entry = (s32 *)((s8 *)&data_0212dc1c + (i + 1) * sizeof(s32[3]));
            } else {
                ((s32 *)&data_027e0000)[i] = arg1;
            }
            if (entry != NULL) {
                entry[0] = arg1;
                entry[2] = 0;
                entry[1] = 1;
            }
        }
        i++;
        arg0 >>= 1;
    } while (i < 22);
}

s32 func_02005080(u32 arg0) {
    extern M2C_UNK data_0212dc1c;
    extern s32 data_027e0000;
    s32 i;
    s32 *ptr;
    ptr = &data_027e0000;
    i = 0;
    do {
        if (arg0 & 1) {
            if (i >= 8 && i <= 11) {
                return M2C_FIELD(&data_0212dc1c, s32 *, (i - 8) * 12);
            }
            if (i >= 3 && i <= 6) {
                return M2C_FIELD(&data_0212dc1c, s32 *, (i + 1) * 12);
            }
            return *ptr;
        }
        i++;
        arg0 >>= 1;
        ptr++;
    } while (i < 22);
    return 0;
}

#pragma scheduling off
void func_0200510c(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_020051c8(s32);
    extern M2C_UNK data_0212dc1c;
    extern M2C_UNK data_0212dc20;
    extern M2C_UNK data_0212dc24;
    s32 offset;
    s32 shift;
    shift = arg0 + 8;
    offset = arg0 * 12;
    M2C_FIELD(&data_0212dc1c, s32 *, offset) = arg1;
    M2C_FIELD(&data_0212dc24, s32 *, offset) = arg2;
    M2C_FIELD(&data_0212dc20, s32 *, offset) = func_020051c8(1 << shift) & (1 << shift);
}
#pragma scheduling reset
void func_02005154(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_020051c8(s32);
    extern M2C_UNK data_0212dc4c;
    extern M2C_UNK data_0212dc50;
    extern M2C_UNK data_0212dc54;
    M2C_FIELD(&data_0212dc4c, s32 *, arg0 * 12) = arg1;
    M2C_FIELD(&data_0212dc54, s32 *, arg0 * 12) = arg2;
    func_020051c8(1U << (arg0 + 3));
    M2C_FIELD(&data_0212dc50, s32 *, arg0 * 12) = 1;
}
#pragma opt_lifetimes reset
s32 func_0200519c(s32 arg0) {
    s32 old;
    u16 ime;
    ime = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    old = *(volatile s32 *)0x04000210;
    *(volatile s32 *)0x04000210 = arg0;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = ime;
    return old;
}

s32 func_020051c8(s32 arg0) {
    s32 old;
    u16 ime;
    ime = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    old = *(volatile s32 *)0x04000210;
    *(volatile s32 *)0x04000210 = old | arg0;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = ime;
    return old;
}

s32 func_020051f8(s32 arg0) {
    s32 old;
    u16 ime;
    ime = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    old = *(volatile s32 *)0x04000210;
    *(volatile s32 *)0x04000210 = old & ~arg0;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = ime;
    return old;
}

s32 func_02005228(s32 arg0) {
    s32 old;
    u16 ime;
    ime = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    old = *(volatile s32 *)0x04000214;
    *(volatile s32 *)0x04000214 = arg0;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = ime;
    return old;
}

#pragma opt_propagation off
void func_02005254(void) {
    extern M2C_UNK data_027e0000;
    s32 off = 0x800;
    M2C_FIELD(&data_027e0000, s32 *, 0x3F7C) = 0xFDDB597D;
    *(s32 *)((u8 *)&data_027e0000 + 0x3F80 - off) = 0x7BF9DD5B;
}
#pragma opt_propagation reset
void func_02005288(void) {
extern s32 data_0212dc7c;
void WaitByLoop(s32); void func_020053a0(s32,s32,s32);void func_02005424(s32,s32,s32);void func_02007e54(s32,void *,s32);
volatile u8 *p=(volatile u8 *)0x027ffff0;
if(data_0212dc7c)return;
*(volatile s32 *)p=0;
*(s32 *)&data_0212dc7c=1;
func_020053a0(0x7e,0x027ffff0,0);
while(*(volatile u16 *)(p+6))WaitByLoop(0x400);
*(volatile s32 *)0x027fffb0=-1;
*(volatile s32 *)0x027fffb4=0xffff0000;
func_02007e54(0,(void *)0x027fffc0,0x28);
*(volatile u16 *)0x04000204|=0x800;
*(volatile u16 *)0x04000204|=0x80;
func_02005424(0x7e,0x027ffff0,0);
func_020053a0(0x7f,0x027ffff0,0);
}

M2C_UNK func_02005354(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    void WaitByLoop(s32);
    M2C_UNK func_02005434(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

    if (func_02005434(arg0, arg1, arg2, arg3) <= 0) return;
    do {
        WaitByLoop(0x400);
    } while (func_02005434(arg0, arg1, arg2, arg3) > 0);
}

void func_020053a0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02005354(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_02005354(arg0, arg1, arg2, 0);
}

s32 func_020053b0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 func_0200751c();
    M2C_UNK func_02007548();
    M2C_UNK func_0200755c(M2C_UNK);
    M2C_UNK func_02007530(M2C_UNK);
    s32 old;

    if (arg0 != M2C_FIELD((void *)arg1, u16 *, 4)) return -2;
    if (arg3 != 0) {
        old = func_02007548();
    } else {
        old = func_0200751c();
    }
    M2C_FIELD((void *)arg1, u16 *, 4) = 0;
    if (arg2 != 0) ((void (*)(void))arg2)();
    M2C_FIELD((void *)arg1, s32 *, 0) = 0;
    if (arg3 != 0) {
        func_0200755c(old);
    } else {
        func_02007530(old);
    }
    return 0;
}

void func_02005424(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020053b0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_020053b0(arg0, arg1, arg2, 0);
}

s32 func_02005434(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 func_0200751c();
    M2C_UNK func_02007548();
    M2C_UNK func_0200755c(M2C_UNK);
    M2C_UNK func_02007530(M2C_UNK);
    s32 func_020081c8(M2C_UNK, M2C_UNK);
    s32 old;
    s32 temp_r4;

    if (arg3 != 0) {
        old = func_02007548();
    } else {
        old = func_0200751c();
    }
    temp_r4 = func_020081c8(arg0, arg1);
    if (temp_r4 == 0) {
        if (arg2 != 0) ((void (*)(void))arg2)();
        M2C_FIELD((void *)arg1, s16 *, 4) = arg0;
    }
    if (arg3 != 0) {
        func_0200755c(old);
    } else {
        func_02007530(old);
    }
    return temp_r4;
}

void func_020054a0(M2C_UNK arg0) {
    M2C_UNK func_020053b0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_02005504(void);
    func_020053b0(arg0, 0x027FFFE8, (M2C_UNK)func_02005504, 1);
}

void func_020054c0(M2C_UNK arg0) {
    void func_020054a0(M2C_UNK);
    func_020054a0(arg0);
}

void func_020054cc(M2C_UNK arg0) {
    M2C_UNK func_02005434(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_020054ec(void);
    func_02005434(arg0, 0x027FFFE8, (M2C_UNK)func_020054ec, 1);
}

void func_020054ec(void) {
    *(u16 *)0x04000204 &= ~0x80;
}

void func_02005504(void) {
    *(u16 *)0x04000204 |= 0x80;
}

void func_0200551c(M2C_UNK arg0) {
    void func_02005554(void);
    func_020053a0(arg0, 0x027FFFE0, (M2C_UNK)func_02005554);
}

void func_02005538(M2C_UNK arg0) {
    void func_0200556c(void);
    func_02005424(arg0, 0x027FFFE0, (M2C_UNK)func_0200556c);
}

void func_02005554(void) {
    *(u16 *)0x04000204 &= ~0x800;
}

void func_0200556c(void) {
    *(u16 *)0x04000204 |= 0x800;
}

u16 func_02005584(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 4);
}

int __clz(unsigned int);
#pragma intrinsic(__clz)
s32 func_0200558c(void){
u32 *p=(u32*)0x027fffb0;
u32 n=__builtin_arm_clz(*p);
s32 result=64;
if(n==32){p++;n=__builtin_arm_clz(*p);if(n==32)return -3;result=96;}
result+=n;*p=*p & ~(0x80000000U>>n);return result;
}
void func_020055f4(s32 a){u32 *p=(u32 *)0x027fffb0;u32 mask;if(a>=96)p++;if(a>=96)a-=96;else a-=64;mask=0x80000000U>>a;*p|=mask;}
#pragma optimization_level reset
void func_0200563c(s32 arg0, s32 arg1, ...) {
    void func_02005664();
    char *args;
    args = (char *)(((u32)&arg1 & ~3U) + 4);
    func_02005664(arg0, arg1, args);
}

void func_02005664(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    void func_020056a4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_020056a4(arg0, (M2C_UNK)0x7fffffff, arg1, arg2);
}

void func_0200567c(s32 arg0, s32 arg1, s32 arg2, ...) {
    void func_020056a4();
    char *args;
    args = (char *)(((u32)&arg2 & ~3U) + 4);
    func_020056a4(arg0, arg1, arg2, args);

}

void func_020056a4() {
    M2C_UNK func_020195e8();
    func_020195e8();
}

s32 func_020056b0(void){
extern s32 data_0212dc80;return ++M2C_FIELD(&data_0212dc80,s32 *,32);
}

void func_020056c8(void *a,void *b){
void *p=M2C_FIELD(a,void **,0);void *prev;
while(p!=NULL && M2C_FIELD(p,u32 *,0x70)<=M2C_FIELD(b,u32 *,0x70)){
if(p==b)return;p=M2C_FIELD(p,void **,0x80);
}
if(p==NULL){
prev=M2C_FIELD(a,void **,4);
if(prev==NULL)M2C_FIELD(a,void **,0)=b;else M2C_FIELD(prev,void **,0x80)=b;
M2C_FIELD(b,void **,0x7C)=prev;M2C_FIELD(b,void **,0x80)=NULL;M2C_FIELD(a,void **,4)=b;
}else{
prev=M2C_FIELD(p,void **,0x7C);
if(prev==NULL)M2C_FIELD(a,void **,0)=b;else M2C_FIELD(prev,void **,0x80)=b;
M2C_FIELD(b,void **,0x7C)=prev;M2C_FIELD(b,void **,0x80)=p;M2C_FIELD(p,void **,0x7C)=b;
}
}

void *func_02005740(void *arg0) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0);
    if (temp_r2 != NULL) {
        temp_r1 = M2C_FIELD(temp_r2, void **, 0x80);
        M2C_FIELD(arg0, void **, 0) = temp_r1;
        if (temp_r1 != NULL) {
            M2C_FIELD(temp_r1, s32 *, 0x7C) = 0;
        } else {
            M2C_FIELD(arg0, s32 *, 4) = 0;
            M2C_FIELD(temp_r2, s32 *, 0x78) = 0;
        }
    }
    return temp_r2;
}

void *func_02005774(void *a, void *b) {
void *p, *next, *head;
head=M2C_FIELD(a,void **,0); p=head;
while(p){ next=M2C_FIELD(p,void **,0x80); if(p==b){
void *prev=M2C_FIELD(p,void **,0x7c);
if(head==p) M2C_FIELD(a,void **,0)=next; else M2C_FIELD(prev,void **,0x80)=next;
if(M2C_FIELD(a,void **,4)==p) M2C_FIELD(a,void **,4)=prev; else M2C_FIELD(next,void **,0x7c)=prev; break;
} p=next;} return p;
}

void *func_020057c8(void *arg0) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0);
    if (temp_r2 != NULL) {
        temp_r1 = M2C_FIELD(temp_r2, void **, 0x10);
        M2C_FIELD(arg0, void **, 0) = temp_r1;
        if (temp_r1 != NULL) {
            M2C_FIELD(temp_r1, s32 *, 0x14) = 0;
        } else {
            M2C_FIELD(arg0, s32 *, 4) = 0;
        }
    }
    return temp_r2;
}

void func_020057f8(void *a) {
extern M2C_UNK data_0212dc80;
void *p, *prev, *head;
prev=0; head=M2C_FIELD(&data_0212dc80,void **,0x2c); p=head;
while(p && M2C_FIELD(p,u32 *,0x70)<M2C_FIELD(a,u32 *,0x70)){prev=p;p=M2C_FIELD(p,void **,0x68);}
if(!prev){M2C_FIELD(a,void **,0x68)=head;M2C_FIELD(&data_0212dc80,void **,0x2c)=a;}else{M2C_FIELD(a,void **,0x68)=M2C_FIELD(prev,void **,0x68);M2C_FIELD(prev,void **,0x68)=a;}
}

void func_02005858(void *a) {
extern M2C_UNK data_0212dc80;
void *prev=0,*p=M2C_FIELD(&data_0212dc80,void **,0x2c);
while(p && p!=a){prev=p;p=M2C_FIELD(p,void **,0x68);}
if(!prev){M2C_FIELD(&data_0212dc80,void **,0x2c)=M2C_FIELD(a,void **,0x68);}else{M2C_FIELD(prev,void **,0x68)=M2C_FIELD(a,void **,0x68);}
}

void func_020058a0(void) {
extern M2C_UNK data_0212dc80;
extern M2C_UNK data_0212dca4;
s32 func_02007580(void); void *func_02005e84(void); s32 func_02006224(void *); void func_02006270(s32);
void *state; void *a,*b; void (*cb)(void *,void *);
if(M2C_FIELD(&data_0212dc80,s32 *,4))return;
state=&data_0212dca4;
if(M2C_FIELD(&data_0212dc80,u16 *,0x26) || func_02007580()==18){M2C_FIELD(state,u16 *,0)=1;return;}
a=M2C_FIELD(M2C_FIELD(&data_0212dc80,void **,8),void **,0);
b=func_02005e84();
if(a==b || b==0)return;
if(M2C_FIELD(a,s32 *,0x64)!=2 && func_02006224(a))return;
cb=M2C_FIELD(&data_0212dc80,void (**)(void *,void *),0);if(cb)cb(a,b);
cb=M2C_FIELD(state,void (**)(void *,void *),12);if(cb)cb(a,b);
M2C_FIELD(&data_0212dc80,void **,0x28)=b;
func_02006270((s32)b);
}

#pragma peephole off
void func_02005968(void) {
extern M2C_UNK data_0212dc80,data_0212dca8,data_0212dd74,data_027e0000,data_0212dca4,data_0212dcb4,data_0212defc;
extern char data_00000000[],data_00000800[]; void func_02006120(void);
void func_02005ac0(void *,void *,s32,u8 *,u32,s32);
s32 size;u8 *end,*start;
if(M2C_FIELD(&data_0212dc80,s32 *,12))return;
M2C_FIELD(&data_0212dc80,s32 *,12)=1;
M2C_FIELD(&data_0212dc80,void **,8)=&data_0212dca8;
M2C_FIELD(&data_0212dc80,s32 *,356)=16;
M2C_FIELD(&data_0212dc80,s32 *,352)=0;
M2C_FIELD(&data_0212dc80,s32 *,344)=1;
M2C_FIELD(&data_0212dc80,s32 *,348)=0;
M2C_FIELD(&data_0212dc80,s32 *,360)=0;
M2C_FIELD(&data_0212dc80,void **,44)=&data_0212dd74;
M2C_FIELD(&data_0212dc80,void **,40)=&data_0212dd74;
size=(s32)data_00000000;
if(size<=0)start=(u8 *)0x027e15e0;else start=(u8 *)&data_027e0000+0x3f80-(s32)data_00000800;
start-=size;
end=(u8 *)&data_027e0000+0x3f80-(s32)data_00000800;
M2C_FIELD(&data_0212dc80,void **,392)=end;
M2C_FIELD(&data_0212dc80,void **,388)=start;
M2C_FIELD(&data_0212dc80,s32 *,396)=0;
*(u32 *)(end-4)=0xfddb597d;
*M2C_FIELD(&data_0212dc80,u32 **,388)=0x7bf9dd5b;
M2C_FIELD(&data_0212dc80,s32 *,404)=0;
M2C_FIELD(&data_0212dc80,s32 *,400)=0;
M2C_FIELD(&data_0212dc80,u16 *,36)=0;
M2C_FIELD(&data_0212dc80,u16 *,38)=0;
*(void **)0x027fffa0=&data_0212dca4;
func_020060f8(0);
func_02005ac0(&data_0212dcb4,func_02006120,0,(u8 *)&data_0212defc,200,31);
M2C_FIELD(&data_0212dc80,s32 *,164)=32;
M2C_FIELD(&data_0212dc80,s32 *,152)=1;
}
#pragma peephole reset
s32 func_02005ab0(void) {
    extern s32 data_0212dc8c;
    return data_0212dc8c;
}

/* Initializes a managed memory-block object (obj) backed by buffer (buf) of (bufLen) bytes, with priority (priority) and callback (callback); registers it in the global block list. */
void func_02005ac0(void *obj,void *callback,s32 owner,u8 *buf,u32 bufLen,s32 priority) {
s32 func_0200751c(void); s32 func_02007530(s32);
void func_020061a0(); void func_02006198();
void func_02007e54(s32,void *,s32); void func_02005bbc(void);
s32 state; s32 id; u8 *base;
state=func_0200751c();
id=func_020056b0();
M2C_FIELD(obj,s32 *,0x70)=priority;
M2C_FIELD(obj,s32 *,0x6c)=id;
M2C_FIELD(obj,s32 *,0x74)=M2C_FIELD(obj,s32 *,0x64)=0;
func_020057f8(obj);
M2C_FIELD(obj,u8 **,0x94)=buf;
base=buf-bufLen;
M2C_FIELD(obj,u8 **,0x90)=base;
M2C_FIELD(obj,s32 *,0x98)=0;
*(u32 *)(M2C_FIELD(obj,u8 **,0x94)-4)=0xFDDB597D;
*M2C_FIELD(obj,u32 **,0x90)=0x7BF9DD5B;
M2C_FIELD(obj,s32 *,0x9c)=M2C_FIELD(obj,s32 *,0xa0)=0;
func_020061a0(obj,callback,buf-4);
M2C_FIELD(obj,s32 *,4)=owner;
M2C_FIELD(obj,void (**)(void),0x3c)=func_02005bbc;
func_02007e54(0,base+4,bufLen-8);
M2C_FIELD(obj,s32 *,0x8c)=M2C_FIELD(obj,s32 *,0x88)=M2C_FIELD(obj,s32 *,0x84)=0;
func_02006198(obj,0);
M2C_FIELD(obj,s32 *,0x78)=0;
M2C_FIELD(obj,s32 *,0x80)=0;
M2C_FIELD(obj,s32 *,0x7c)=0;
func_02007e54(0,(u8 *)obj+0xa4,12);
M2C_FIELD(obj,s32 *,0xb0)=0;
func_02007530(state);
}

void func_02005bbc(void) {
    M2C_UNK func_02005bdc(s32, M2C_UNK);
    extern M2C_UNK data_0212dc80;
    func_0200751c();
    func_02005bdc(M2C_FIELD(&data_0212dc80, s32 *, 0x28), 0);
}

M2C_UNK func_02005bdc(s32 a,s32 b){
extern s32 data_0212dc80;
void func_02005c38(s32);
void func_020061a0();
void func_02006270(s32);
if(M2C_FIELD(&data_0212dc80,s32 *,28)){
func_020061a0(a,func_02005c38);
M2C_FIELD(a,s32 *,4)=b;
M2C_FIELD(a,s32 *,0)|=128;
M2C_FIELD(a,s32 *,100)=1;
func_02006270(a);
}else func_02005c38(b);
}

void func_02005c38(s32 a){
extern s32 data_0212dc80;
void func_02005c70(void);
void *p=*M2C_FIELD(&data_0212dc80,void ***,8);
void (*cb)(s32)=M2C_FIELD(p,void (**)(s32),0xB4);
if(cb){M2C_FIELD(p,void (**)(s32),0xB4)=NULL;cb(a);
func_0200751c();}func_02005c70();
}

void func_02005c70(void){
extern s32 data_0212dc80;
void func_02006130(void);
void func_02006644(void *);
void func_02005858(void *);
void func_02005df4(void *);
void func_02006164(void);
void func_02007958(void);
void func_02005eac(void);
void *p=*M2C_FIELD(&data_0212dc80,void ***,8);
func_02006130();func_02006644(p);
if(M2C_FIELD(p,void **,120)){func_02005774(M2C_FIELD(p,void **,120),p);}func_02005858(p);
M2C_FIELD(p,s32 *,100)=2;
func_02005df4(p+156);func_02006164();func_02005eac();func_02007958();
}

void func_02005ccc(void *p){
void func_02005d48(void *);
void func_02005eac(void);
extern s32 data_0212dc80;
s32 old=func_0200751c();
if(M2C_FIELD(&data_0212dc80,void **,40)==p)func_02005c70();
func_02006130();func_02006644(p);func_02005d48(p);
if(M2C_FIELD(p,void **,120)){func_02005774(M2C_FIELD(p,void **,120),p);}func_02005858(p);
M2C_FIELD(p,s32 *,100)=2;
func_02005df4(p+156);func_02006164();func_02007530(old);func_02005eac();
}

void func_02005d48(void *arg0) {
    M2C_UNK func_02007338();
    if (M2C_FIELD(arg0, s32 *, 0xB0) == 0) {
        return;
    }
    func_02007338();
}

void func_02005d60(void *arg0) {
    M2C_UNK func_02005da4(void *);
    s32 temp_r4;

    temp_r4 = func_0200751c();
    if (M2C_FIELD(arg0, s32 *, 0x64) != 2) {
        func_02005da4(arg0 + 0x9C);
    }
    func_02007530(temp_r4);
}

s32 func_02005d90(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x64) == 2) {
        return 1;
    }
    return 0;
}

M2C_UNK func_02005da4(void *a){
extern M2C_UNK data_0212dc80;
s32 irq=func_0200751c();
void *p=M2C_FIELD(M2C_FIELD(&data_0212dc80,void **,8),void **,0);
if(a){M2C_FIELD(p,void **,0x78)=a;func_020056c8(a,p);}
M2C_FIELD(p,s32 *,0x64)=0;func_020058a0();func_02007530(irq);
}

M2C_UNK func_02005df4(void *a){
s32 irq=func_0200751c();
if(M2C_FIELD(a,s32 *,0)){
while(M2C_FIELD(a,s32 *,0)){
void *p=func_02005740(a);
M2C_FIELD(p,s32 *,0x64)=1;M2C_FIELD(p,s32 *,0x78)=0;M2C_FIELD(p,s32 *,0x80)=0;M2C_FIELD(p,s32 *,0x7c)=0;
}
M2C_FIELD(a,s32 *,4)=0;M2C_FIELD(a,s32 *,0)=0;func_020058a0();
}func_02007530(irq);
}

void func_02005e5c(void *arg0) {
    s32 temp_r4;

    temp_r4 = func_0200751c();
    M2C_FIELD(arg0, s32 *, 0x64) = 1;
    func_020058a0();
    func_02007530(temp_r4);
}

void *func_02005e84(void) {
extern M2C_UNK data_0212dc80;
void *p = M2C_FIELD(&data_0212dc80, void **, 0x2c);
while (p && M2C_FIELD(p, s32 *, 0x64) != 1) p = M2C_FIELD(p, void **, 0x68);
return p;
}

void func_02005eac(void) {

    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    s32 temp_r4;

    temp_r4 = func_0200751c();
    func_020058a0();
    func_02007530(temp_r4);
}

void func_02005ec8(void){
extern M2C_UNK data_0212dc80;
void *prev=0,*last=0; s32 count=0;
s32 irq;
void *cur=M2C_FIELD(&data_0212dc80,void **,0x28);
void *p,*before;
irq=func_0200751c();
p=M2C_FIELD(&data_0212dc80,void **,0x2c);before=0;
while(p){
if(p==cur)prev=before;
if(M2C_FIELD(cur,u32 *,0x70)==M2C_FIELD(p,u32 *,0x70)){last=p;count++;}
before=p;p=M2C_FIELD(p,void **,0x68);
}
if(count<=1 || last==cur){func_02007530(irq);return;}
if(!prev)M2C_FIELD(&data_0212dc80,void **,0x2c)=M2C_FIELD(cur,void **,0x68);
else M2C_FIELD(prev,void **,0x68)=M2C_FIELD(cur,void **,0x68);
M2C_FIELD(cur,void **,0x68)=M2C_FIELD(last,void **,0x68);M2C_FIELD(last,void **,0x68)=cur;
func_020058a0();func_02007530(irq);
}

