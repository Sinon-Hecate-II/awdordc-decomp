/* 28 functions from 0x0200FC58 to 0x02010C14 (main), found by ds-decomp. */
#include "common.h"


void func_0200fc58(void) {
    extern void *data_0212fde0;
    extern void *data_0212fd80;
    extern u32 data_02130400[];
    void func_02007e98(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_020067e0(void *, u32);
    void MI_CpuCopy8(void *, void *, u32);
    void func_02005ac0(void *, void *, s32, u8 *, u32, s32);
    void TaskWake(void *);
    void func_02009e40(s32, void *);
    void func_0200fd90(s32);
    void func_02010cc4(void);
    void func_02010c90(s32, s32, s32);

    void *base = &data_0212fde0;
    u16 v;
    s32 n;

    *(s32 *)((u8 *)base + 8) = -3;
    *(s32 *)((u8 *)base + 0xC) = 0;
    *(s32 *)((u8 *)base + 0x18) = 0;
    *(void **)((u8 *)base + 0x0) = &data_0212fd80;

    func_02007e98(0, &data_0212fd80, 0x60);
    func_020067e0(&data_0212fd80, 0x60);

    *(s32 *)((u8 *)base + 0x118) = -1;
    *(s32 *)((u8 *)base + 0x11C) = -1;

    v = *(volatile u16 *)0x27ffc40;
    n = (v == 2) ? 1 : 0;
    if (n == 0) {
        MI_CpuCopy8((void *)0x27ffe00, (void *)(0x27ffe00 - 0x380), 0x160);
        *(s32 *)((u8 *)base + 0x108) = 4;
        *(s32 *)((u8 *)base + 0x14) = 0;
        *(s32 *)((u8 *)base + 0x10) = 0;
        *(s32 *)((u8 *)base + 0x110) = 0;
        *(s32 *)((u8 *)base + 0x10C) = 0;
        func_02005ac0((u8 *)base + 0x44, (void *)func_02010cc4, 0,
                      (u8 *)data_02130400, 0x400,
                      *(s32 *)((u8 *)base + 0x108));
        TaskWake((u8 *)base + 0x44);
    }

    func_02009e40(0xB, (void *)func_02010c90);

    v = *(volatile u16 *)0x27ffc40;
    n = (v == 2) ? 1 : 0;
    if (n == 0) {
        func_0200fd90(1);
    }
}

s32 func_0200fd68(void) {
    extern s32 data_0212fd60;
    return data_0212fd60;
}

void func_0200fd78(void) {
    M2C_UNK func_02007958();
    if (func_0200fd68() != 0) {
        return;
    }
    func_02007958();
}

void func_0200fd90(s32 arg0) {
    extern s32 data_0212fd60;
    data_0212fd60 = arg0;
}

s32 func_0200fda0(void) {
 extern void *data_0212fde0;
 s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); void OS_SleepThread(void *);
 void *p = &data_0212fde0;
 s32 state = OS_DisableInterrupts();
 goto test;
 loop: OS_SleepThread((u8 *)p + 0x10c);
 test: if (M2C_FIELD(p, u32 *, 0x114) & 4) goto loop;
 OS_RestoreInterrupts(state);
 return *M2C_FIELD(p, s32 **, 0) == 0;
}

s32 func_0200fdec(void) {
 extern void *data_0212fde0;
 return (M2C_FIELD(&data_0212fde0, u32 *, 0x114) & 4) == 0;
}

s32 func_0200fe08(void) {
 extern void *data_0212fde0;
 return M2C_FIELD(&data_0212fde0,u32 *,0x114) != 0;
}

void func_0200fe24(M2C_UNK arg0) {
    M2C_UNK func_0200551c(M2C_UNK);
    func_0200fb48(arg0, 1);
    func_0200551c(arg0);
}

void func_0200fe40(M2C_UNK arg0) {
    M2C_UNK func_02005538();
    M2C_UNK func_0200fbcc(M2C_UNK, M2C_UNK);
    func_02005538();
    func_0200fbcc(arg0, 1);
}

void func_0200fe5c(M2C_UNK arg0) {
    M2C_UNK func_0200fb48(M2C_UNK, M2C_UNK);
    func_0200fb48(arg0, 2);
}

void func_0200fe6c(M2C_UNK arg0) {
 s32 func_02010590(void); void func_02010584(void);
 M2C_UNK func_0200fbcc(M2C_UNK, M2C_UNK);
 if (func_02010590() == 0) { func_02010584(); }
 func_0200fbcc(arg0, 2);
}

#pragma opt_common_subs off
void func_0200fe94(s32 value){
extern void *data_0212fde0;void MI_CpuFill8(void *,s32,s32);
u8 *p=data_0212fde0;u32 bit; s32 kind;
MI_CpuFill8(p+0x18,0,0x48);
M2C_FIELD(p,s32 *,4)=value;M2C_FIELD(p,u32 *,0x4c)=0x3f;
if(value==0)return;
bit=1<<((value>>8)&255);kind=value&255;
M2C_FIELD(p,u32 *,0x18)=bit;p[0x48]=255;
if(kind==1){
switch(bit){
case 0x200:M2C_FIELD(p,s32 *,0x20)=16;M2C_FIELD(p,s32 *,0x24)=1;M2C_FIELD(p,s32 *,0x28)=5;p[0x48]=240;break;
case 0x2000:M2C_FIELD(p,s32 *,0x20)=32;M2C_FIELD(p,s32 *,0x24)=2;M2C_FIELD(p,s32 *,0x28)=5;p[0x48]=0;break;
case 0x10000:M2C_FIELD(p,s32 *,0x20)=128;M2C_FIELD(p,s32 *,0x24)=2;M2C_FIELD(p,s32 *,0x28)=10;p[0x48]=0;break;
default:goto fail;}
M2C_FIELD(p,s32 *,0x1c)=M2C_FIELD(p,s32 *,0x20);M2C_FIELD(p,u32 *,0x4c)|=0x340;return;
}else if(kind==2){
switch(bit){
case 0x40000:case 0x80000:case 0x100000:
M2C_FIELD(p,s32 *,0x2c)=25;M2C_FIELD(p,s32 *,0x30)=300;M2C_FIELD(p,s32 *,0x44)=300;M2C_FIELD(p,s32 *,0x3c)=5000;M2C_FIELD(p,u32 *,0x4c)|=0x480;break;
case 0x200000:
M2C_FIELD(p,s32 *,0x2c)=23;M2C_FIELD(p,s32 *,0x30)=300;{s32 delay=500;M2C_FIELD(p,s32 *,0x3c)=delay;}M2C_FIELD(p,s32 *,0x34)=(M2C_FIELD(p,s32 *,0x40)=5000)*2;M2C_FIELD(p,s32 *,0x38)=60000;p[0x48]=0;M2C_FIELD(p,u32 *,0x4c)|=0x1480;break;
case 0x400000:
M2C_FIELD(p,s32 *,0x3c)=600;M2C_FIELD(p,s32 *,0x40)=3000;M2C_FIELD(p,s32 *,0x34)=23000;M2C_FIELD(p,s32 *,0x38)=800000;p[0x48]=0;M2C_FIELD(p,u32 *,0x4c)|=0x1000;break;
case 0x800000:
M2C_FIELD(p,s32 *,0x3c)=1000;M2C_FIELD(p,s32 *,0x40)=3000;M2C_FIELD(p,s32 *,0x34)=68000;M2C_FIELD(p,s32 *,0x38)=160000;p[0x48]=0;M2C_FIELD(p,u32 *,0x4c)|=0x1000;break;
default:goto fail;
}
M2C_FIELD(p,s32 *,0x1c)=0x10000;M2C_FIELD(p,s32 *,0x20)=256;M2C_FIELD(p,s32 *,0x24)=3;M2C_FIELD(p,s32 *,0x28)=5;M2C_FIELD(p,u32 *,0x4c)|=0xb40;return;
}else if(kind==3){if(bit==0x2000||bit==0x8000){M2C_FIELD(p,u32 *,0x20)=bit;M2C_FIELD(p,u32 *,0x1c)=bit;M2C_FIELD(p,s32 *,0x24)=2;p[0x48]=0;M2C_FIELD(p,u32 *,0x4c)|=0x340;return;}}
fail:M2C_FIELD(p,s32 *,0x18)=M2C_FIELD(p,s32 *,4)=0;M2C_FIELD(data_0212fde0,s32 *,0)=3;
}
#pragma opt_common_subs off
/* Task body of the chunked memory transfer: moves the task's remaining bytes between its source
 * and destination in chunks (through a bounce buffer for reads), then wakes the waiting thread
 * and calls the completion callback. */
void RunTransferTask(void *arg0) {
    void func_02000b9c(s32);
    void OS_WakeupThread(void *);
    void DC_InvalidateRange(void *, s32);
    void TaskWake(void *);
    void func_020067e0(void *, u32);
    void func_02006804();
    s32 OS_DisableInterrupts();
    void OS_RestoreInterrupts(s32);
    void MI_CpuCopy8(void *, void *, u32);
    void func_02010d14(void *, s32, s32);
    register u32 irq;
    s32 callbackArg;
    M2C_UNK (*callback)(s32);
    register u32 mode, chunk;
    register void *buffer;
    register s32 type;
    register u32 count;
    register s32 retries;

    u32 left;


    type = M2C_FIELD(arg0, s32 *, 0x2C);
    mode = M2C_FIELD(arg0, u32 *, 0x34);
    retries = M2C_FIELD(arg0, s32 *, 0x30);
    chunk = 0x100;
    func_02000b9c(0x02000BC4);
    if (type == 0xB) {
        chunk = func_02010438();
    }
    buffer = arg0 + 0x120;
loop_3:
    count = M2C_FIELD(arg0, u32 *, 0x24);
    if (chunk < count) {
        count = chunk;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), u32 *, 0x14) = count;
    if (M2C_FIELD(arg0, volatile s32 *, 0x114) & 0x40) {
        M2C_FIELD(arg0, s32 *, 0x114) = (s32) (M2C_FIELD(arg0, s32 *, 0x114) & ~0x40);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0) = 7;
    } else {
        switch (mode) {
        default:
            break;
        case 0:
            DC_InvalidateRange(buffer, count);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0xC) = (void *) M2C_FIELD((u32)arg0, void **, 0x1C);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x10) = buffer;
            break;
        case 1:
        case 2:
            MI_CpuCopy8(M2C_FIELD(arg0, void **, 0x1C), buffer, count);
            func_020067e0(buffer, count);
            func_02006804();
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0xC) = buffer;
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x10) = (void *) M2C_FIELD(arg0, void **, 0x20);
            break;
        case 3:
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0xC) = (void *) M2C_FIELD(arg0, void **, 0x1C);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0x10) = (void *) M2C_FIELD(arg0, void **, 0x20);
            break;
        }
        if (((s32 (*)(void *, s32, s32))func_02010d14)(arg0, type, retries) != 0) {
            if (mode == 2) {
                if (((s32 (*)(void *, s32, s32))func_02010d14)(arg0, 9, 1) != 0) {
                    goto block_23;
                }
            } else {
                if (mode == 0) {
                    MI_CpuCopy8(buffer, M2C_FIELD(arg0, void **, 0x20), count);
                }
block_23:
                M2C_FIELD(arg0, void **, 0x1C) = (void *) (M2C_FIELD(arg0, void **, 0x1C) + count);
                M2C_FIELD(arg0, void **, 0x20) = (void *) (M2C_FIELD(arg0, void **, 0x20) + count);
                left = M2C_FIELD(arg0, u32 *, 0x24) - count;
                M2C_FIELD(arg0, u32 *, 0x24) = left;
                if (left) {
                    goto loop_3;
                }
            }
        }
    }
    callback = M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x38);
    callbackArg = M2C_FIELD(arg0, s32 *, 0x3C);
    irq = OS_DisableInterrupts();
    M2C_FIELD(arg0, s32 *, 0x114) = (s32) (M2C_FIELD(arg0, s32 *, 0x114) & ~0x4C);
    OS_WakeupThread(arg0 + 0x10C);
    if (M2C_FIELD(arg0, s32 *, 0x114) & 0x10) {
        TaskWake(arg0 + 0x44);
    }
    OS_RestoreInterrupts(irq);
    if (callback == NULL) {
        return;
    }
    callback(callbackArg);
}
#pragma opt_common_subs reset
s32 func_0201033c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    extern void *data_0212fde0;
    extern M2C_UNK gSocketManager;
    void func_02000b9c(s32);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void OS_SleepThread(void *);
    void func_0200fb0c(void *);
    void RunTransferTask(void *);
    void *p = &data_0212fde0;
    s32 state;
    u32 oldf;
    u32 nf;
    s32 a4;
    s32 a6, a7, a8, a5;

    func_02000b9c(0x2000bc4);
    state = OS_DisableInterrupts();
    while (M2C_FIELD(p, u32 *, 0x114) & 0x4) {
        OS_SleepThread((u8 *)p + 0x10c);
    }
    oldf = M2C_FIELD(p, u32 *, 0x114);
    a4 = arg4;
    a6 = arg6;
    a7 = arg7;
    a8 = arg8;
    a5 = arg5;
    nf = oldf | 0x4;
    M2C_FIELD(p, u32 *, 0x114) = nf;
    M2C_FIELD(p, s32 *, 0x38) = arg3;
    M2C_FIELD(p, s32 *, 0x3c) = a4;
    OS_RestoreInterrupts(state);
    M2C_FIELD(p, s32 *, 0x1c) = arg0;
    M2C_FIELD(p, s32 *, 0x20) = arg1;
    M2C_FIELD(p, s32 *, 0x24) = arg2;
    M2C_FIELD(p, s32 *, 0x2c) = a6;
    M2C_FIELD(p, s32 *, 0x30) = a7;
    M2C_FIELD(p, s32 *, 0x34) = a8;
    if (a5 != 0) {
        func_0200fb0c((void *)RunTransferTask);
        return 1;
    }
    M2C_FIELD(&data_0212fde0, u32 *, 0x104) = M2C_FIELD(&gSocketManager, u32 *, 0x4);
    RunTransferTask(p);
    return *M2C_FIELD(p, s32 **, 0) == 0;
}

s32 func_02010424(void) {
    extern void *data_0212fde0;
    return M2C_FIELD(data_0212fde0, s32 *, 4);
}

s32 func_02010438(void) {
    extern void *data_0212fde0;
    return M2C_FIELD(data_0212fde0, s32 *, 0x1C);
}

s32 func_0201044c(s32 arg0) {
extern void *data_0212fde0;extern M2C_UNK gSocketManager;
void func_02000b9c(s32);s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);void OS_SleepThread(void *);void OS_WakeupThread(void *);void TaskWake(void *);void func_0200fe94(s32);void func_02010d14(void *,s32,s32);M2C_UNK func_02007958();
void *p=&data_0212fde0; s32 state,state2;s32 value;void (*callback)(s32);
func_02000b9c(0x2000bc4);
if(arg0==0)func_02007958();
func_0200fd78();
state=OS_DisableInterrupts();
while(M2C_FIELD(p,u32 *,0x114)&4)OS_SleepThread(p+0x10c);
{
s32 zero=0;
M2C_FIELD(p,u32 *,0x114)|=4;
M2C_FIELD(p,s32 *,0x38)=zero;M2C_FIELD(p,s32 *,0x3c)=zero;
}
OS_RestoreInterrupts(state);
func_0200fe94(arg0);
M2C_FIELD(&data_0212fde0,s32 *,0x104)=M2C_FIELD(&gSocketManager,s32 *,4);
func_02010d14(p,2,1);
M2C_FIELD(*(void **)p,s32 *,0xc)=0;
M2C_FIELD(*(void **)p,void **,0x10)=p+0x120;
M2C_FIELD(*(void **)p,s32 *,0x14)=1;
func_02010d14(p,6,1);
callback=M2C_FIELD(p,void (**)(s32),0x38);value=M2C_FIELD(p,s32 *,0x3c);
state2=OS_DisableInterrupts();
M2C_FIELD(p,u32 *,0x114)&=~0x4c;
OS_WakeupThread(p+0x10c);
if(M2C_FIELD(p,u32 *,0x114)&0x10)TaskWake(p+0x44);
OS_RestoreInterrupts(state2);
if(callback)callback(value);
return **(s32 **)p==0;
}

void func_02010584(void) {
    M2C_UNK func_0200fda0();
    func_0200fda0();
}

s32 func_02010590(void) {
    M2C_UNK func_0200fdec();
    return func_0200fdec();
}

#pragma optimization_level 3
s32 func_0201059c(void *arg0){
extern void *data_0212fde0; void MI_CpuCopy8(void *,void *,u32);
void *p=&data_0212fde0; u32 base=M2C_FIELD(p,volatile u32*,0x1c)&~0x1ff;
if(base==M2C_FIELD(arg0,u32*,8)){
u32 offset=M2C_FIELD(p,volatile u32*,0x1c)-base;u32 size=0x200-offset;s32 a,b,c;
if(size>M2C_FIELD(p,u32*,0x24))size=M2C_FIELD(p,u32*,0x24);
MI_CpuCopy8((u8*)arg0+0x20+offset,M2C_FIELD(p,void**,0x20),size);
a=M2C_FIELD(p,volatile s32*,0x1c)+(s32)size;b=M2C_FIELD(p,volatile s32*,0x20)+(s32)size;c=M2C_FIELD(p,volatile s32*,0x24)-(s32)size;
M2C_FIELD(p,u32*,0x1c)=a;M2C_FIELD(p,u32*,0x20)=b;M2C_FIELD(p,u32*,0x24)=c;
}return M2C_FIELD(p,volatile u32*,0x24)!=0;
}
#pragma optimization_level 4
void func_02010628(u32 arg0,u32 arg1) {
 volatile u8 *p=(volatile u8 *)0x040001A1;
 while (*(volatile u32 *)0x040001A4 & 0x80000000) {}
 p[0]=0xC0;
 p[7]=arg0>>24; p[8]=arg0>>16; p[9]=arg0>>8; p[10]=arg0;
 p[11]=arg1>>24; p[12]=arg1>>16; p[13]=arg1>>8; p[14]=arg1;
}

#pragma opt_propagation off
void func_02010688(void) {
 extern void *data_0212fde0; extern u32 data_02130420[];
 void func_02008538(u32,void *,u32,u32);
 u32 *p=(u32 *)&data_0212fde0; u32 *q=data_02130420;
 func_02008538(p[10],(void *)0x04100010,p[8],512);
 func_02010628((p[7]>>8)|0xB7000000,p[7]<<24);
 *(volatile u32 *)0x040001A4 = q[1];
}
#pragma opt_propagation on
void func_020106dc(void) {
    s32 func_02007ca4(s32);
    void func_020051f8(s32);
    void func_02005228(s32);
    s32 func_02010a28(void);
    void func_02010f84(s32);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void OS_WakeupThread(void *);
    void TaskWake(void *);
    void func_02010688(void);
    extern void *data_0212fde0;
    s32 a;
    s32 c;
    s32 b;
    s32 flag;
    s32 r;
    s32 r5;
    s32 r6;
    s32 state;
    void *q;
    void *p;

    func_02007ca4(M2C_FIELD(&data_0212fde0, s32 *, 0x28));
    q = &data_0212fde0;
    a = M2C_FIELD(q, s32 *, 0x24);
    b = M2C_FIELD(q, s32 *, 0x1c) + 0x200;
    c = M2C_FIELD(q, s32 *, 0x20) + 0x200;
    a = a - 0x200;
    M2C_FIELD(q, s32 *, 0x24) = a;
    if (a != 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    M2C_FIELD(q, s32 *, 0x1c) = b;
    M2C_FIELD(q, s32 *, 0x20) = c;
    if (flag) goto fail;
    func_020051f8(0x80000);
    func_02005228(0x80000);
    p = &data_0212fde0;
    r = func_02010a28();
    func_02010f84(r);
    M2C_FIELD(M2C_FIELD(p, s32 **, 0), s32 *, 0) = 0;
    r5 = M2C_FIELD(p, s32 *, 0x38);
    r6 = M2C_FIELD(p, s32 *, 0x3c);
    state = OS_DisableInterrupts();
    M2C_FIELD(p, u32 *, 0x114) = M2C_FIELD(p, u32 *, 0x114) & ~0x4c;
    OS_WakeupThread((u8 *)p + 0x10c);
    if (M2C_FIELD(p, u32 *, 0x114) & 0x10) {
        TaskWake((u8 *)p + 0x44);
    }
    OS_RestoreInterrupts(state);
    if (r5 != 0) {
        ((void (*)(s32))r5)(r6);
    }
    return;
fail:
    func_02010688();
}

s32 func_020107ac(void *arg0) {
    extern void *data_0212fde0;
    void *p = &data_0212fde0;
    s32 r6 = 0;
    s32 r9 = *(s32 *)((u8 *)p + 0x20);
    void *r11 = arg0;
    s32 r7 = 0;
    s32 r8 = 0;
    s32 r1 = 0;
    s32 r10 = r9 & 0x1f;
    s32 r5 = *(s32 *)((u8 *)p + 0x24);
    s32 r0;
    
    if (r10 == 0) {
        r0 = *(s32 *)((u8 *)p + 0x28);
        if (r0 <= 3) {
            r1 = 1;
        }
        if (r1 != 0) {
            s32 func_02006c8c(void);
            func_02006c8c();
            // ...
        }
    }
    return r6;
}

void func_02010938(void *arg0) {
    extern void *data_0212fde0;
    void func_02010628(u32, u32);
    s32 func_0201059c(void *);
    void *p;
    u32 aligned_src;
    register void *dst_buf;
    register u32 counter;
    register u32 byte_counter;
    u32 ctrl_val;
    u32 data;

    p = &data_0212fde0;
    aligned_src = M2C_FIELD(p, u32 *, 0x1c) & ~0x1FF;
    if (aligned_src != M2C_FIELD(p, u32 *, 0x1c)) goto fail;
    if (M2C_FIELD(p, u32 *, 0x20) & 3) goto fail;
    if (M2C_FIELD(p, u32 *, 0x24) >= 0x200) goto fail;

    M2C_FIELD(arg0, u32 *, 0x8) = aligned_src;
    dst_buf = (u8 *)arg0 + 0x20;

    func_02010628((aligned_src >> 8) | 0xB7000000, aligned_src << 24);

    counter = 0;
    byte_counter = 0;
    *(volatile u32 *)0x040001A4 = M2C_FIELD(arg0, u32 *, 0x4);
    ctrl_val = *(volatile u32 *)0x040001A4;

    if (ctrl_val & 0x00800000) {
        do {
            data = *(volatile u32 *)0x04100010;
            if (byte_counter < 0x200) {
                *(u32 *)((u8 *)dst_buf + counter * 4) = data;
                byte_counter += 4;
                counter += 1;
            }
            if (ctrl_val & 0x80000000) {
                ctrl_val = *(volatile u32 *)0x040001A4;
            } else {
                break;
            }
        } while (ctrl_val & 0x00800000);
    }

    if (dst_buf != (void *)M2C_FIELD(p, u32 *, 0x20)) goto fail;

    p = &data_0212fde0;
    M2C_FIELD(p, u32 *, 0x1c) = M2C_FIELD(p, u32 *, 0x1c) + 0x200;
    M2C_FIELD(p, u32 *, 0x20) = M2C_FIELD(p, u32 *, 0x20) + 0x200;
    M2C_FIELD(p, u32 *, 0x24) = M2C_FIELD(p, u32 *, 0x24) - 0x200;

    if (M2C_FIELD(p, u32 *, 0x24) != 0) goto fail;

fail:
    while (func_0201059c(arg0) != 0) { }
}

s32 func_02010a28(void) {
 extern void *data_020f553c;
 func_02010628(0xB8000000,0);
 *(volatile u32 *)0x040001A4=((M2C_FIELD(data_020f553c,u32 *,0x60)&~0x07000000)|0xA7000000)&~0x1FFF;
 while (!(*(volatile u32 *)0x040001A4 & 0x800000)) {}
 return *(volatile s32 *)0x04100010;
}

void func_02010a84(void) {
    s32 func_0201059c(void *);
    s32 func_02010a28(void);
    void func_02010f84(s32);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void OS_WakeupThread(void *);
    void TaskWake(void *);
    extern u32 data_02130420[];
    extern void *data_0212fde0;

    void *p0 = &data_02130420[0];
    s32 r;
    void *p1;
    s32 r5, r6;
    s32 state;

    r = func_0201059c(p0);
    if (r != 0) {
        void (*fp)(void *) = M2C_FIELD(p0, void (**)(void *), 0);
        fp(p0);
    }
    p1 = &data_0212fde0;
    r = func_02010a28();
    func_02010f84(r);
    M2C_FIELD(M2C_FIELD(p1, s32 **, 0), s32 *, 0) = 0;
    r5 = M2C_FIELD(p1, s32 *, 0x38);
    r6 = M2C_FIELD(p1, s32 *, 0x3c);
    state = OS_DisableInterrupts();
    M2C_FIELD(p1, u32 *, 0x114) = M2C_FIELD(p1, u32 *, 0x114) & ~0x4c;
    OS_WakeupThread((u8 *)p1 + 0x10c);
    if (M2C_FIELD(p1, u32 *, 0x114) & 0x10) {
        TaskWake((u8 *)p1 + 0x44);
    }
    OS_RestoreInterrupts(state);
    if (r5 != 0) {
        ((void (*)(s32))r5)(r6);
    }
}

void func_02010b1c(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, s32 arg6) {
    extern u32 data_02130420[];
    extern void *data_0212fde0;
    extern u32 data_02130400[];
    extern M2C_UNK gSocketManager;
    void func_0200fd78(void);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void OS_SleepThread(void *);
    s32 func_02007ca4(s32);
    s32 func_020107ac(void *);
    void func_02010c78(void);
    void func_0200fb0c(void *);
    void func_02010a84(void);

    void *r4 = data_02130420;
    void *r5 = &data_0212fde0;
    u32 r10 = arg0;
    s32 r9 = arg1;
    s32 r8 = arg2;
    s32 r7 = arg3;
    s32 state;
    s32 r;

    func_0200fd78();
    state = OS_DisableInterrupts();
    goto test;
loop:
    OS_SleepThread((u8 *)r5 + 0x10c);
test:
    if (M2C_FIELD(r5, volatile u32 *, 0x114) & 4) goto loop;
    {
        volatile u32 *_fp = (volatile u32 *)((u8 *)r5 + 0x114);
        u32 _v = *_fp;
        *_fp = _v | 4;
    }
    M2C_FIELD(r5, s32 *, 0x38) = arg4;
    M2C_FIELD(r5, void **, 0x3c) = arg5;
    OS_RestoreInterrupts(state);
    {
        u32 *_dp = data_02130400;
        M2C_FIELD(r5, u32 *, 0x28) = r10;
        {
            u32 _dv = _dp[0];
            M2C_FIELD(r5, u32 *, 0x20) = r8;
            M2C_FIELD(r5, u32 *, 0x1c) = r9 + _dv;
        }
    }
    M2C_FIELD(r5, u32 *, 0x24) = r7;
    if (r10 <= 3) {
        func_02007ca4(r10);
    }
    r = func_020107ac(r4);
    if (r != 0) {
        if (arg6 != 0) {
            return;
        }
        func_02010c78();
        return;
    }
    if (arg6 != 0) {
        func_0200fb0c((void *)func_02010a84);
        return;
    }
    M2C_FIELD(r5, u32 *, 0x104) = M2C_FIELD(&gSocketManager, u32 *, 4);
    func_02010a84();
}

