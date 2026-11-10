/* 30 functions from 0x0201CB4C to 0x0201DB20 (main), found by ds-decomp. */
#include "common.h"
#include "tcp_socket.h"

#pragma scheduling off
void *func_0201cb4c(void *packet,s32 *done){
extern u8 data_021375b8[];extern s32 gNetStack;u64 GetSystemTick(void);void MI_CpuCopy8(void *,void *,u32);
u16 id;u32 head;u8 *freeSlot=0,*slot;u32 covered;u32 offset,end,ip,finalEnd;u32 flags,len,i,count;u16 a,b,t;u32 first;
*done=0;t=M2C_FIELD(packet,u16 *,6);flags=(u16)(((s32)t>>8)|(t<<8));
if(!(flags&0x3fff))return packet;
a=M2C_FIELD(packet,u16 *,14);b=M2C_FIELD(packet,u16 *,12);first=M2C_FIELD(packet,u8 *,0);
b=(u16)(((s32)b>>8)|(b<<8));a=(u16)(((s32)a>>8)|(a<<8));head=(first<<28)>>26;ip=(b<<16)|a;
id=M2C_FIELD(packet,u16 *,4);
slot=data_021375b8;
for(i=0;i<8;i++,slot+=0x38){
count=M2C_FIELD(slot,u16 *,4);
if(count&&M2C_FIELD(slot,u32 *,0)==ip&&M2C_FIELD(slot,u16 *,6)==id)break;
if(!count&&!freeSlot)freeSlot=slot;
}
t=M2C_FIELD(packet,u16 *,2);len=(u16)(((s32)t>>8)|(t<<8))-head;
offset=flags&0x1fff;end=len+offset*8;
if(i==8){
if(!freeSlot||end>4096)return 0;
slot=freeSlot;
M2C_FIELD(freeSlot,void **,0x34)=M2C_FIELD(&gNetStack,void *(**)(u32),0x14)(head+0x100e);
if(!M2C_FIELD(freeSlot,void **,0x34))return 0;
M2C_FIELD(freeSlot,u32 *,0)=ip;M2C_FIELD(freeSlot,u16 *,6)=id;M2C_FIELD(freeSlot,u16 *,8)=0;
M2C_FIELD(freeSlot,u32 *,0x2c)=(u32)(GetSystemTick()>>16);
M2C_FIELD(freeSlot,void **,0x30)=(u8 *)M2C_FIELD(freeSlot,void **,0x34)+14+head;
MI_CpuCopy8(packet,(u8 *)M2C_FIELD(freeSlot,void **,0x34)+14,head);
}
if(M2C_FIELD(slot,u16 *,4)==8||end>4096){
void (*release)(void *)=M2C_FIELD(&gNetStack,void (**)(void *),0x40);M2C_FIELD(slot,u16 *,4)=0;release(M2C_FIELD(slot,void **,0x34));return 0;
}
count=offset+((len+7)>>3);
if(!(flags&0x2000)){M2C_FIELD(slot,u16 *,10)=end;M2C_FIELD(slot,u16 *,8)=count;}
M2C_FIELD(slot+M2C_FIELD(slot,u16 *,4)*2,u16 *,12)=offset;
M2C_FIELD(slot+M2C_FIELD(slot,u16 *,4)*2,u16 *,28)=count;
M2C_FIELD(slot,u16 *,4)++;
MI_CpuCopy8((u8 *)packet+head,(u8 *)M2C_FIELD(slot,void **,0x30)+offset*8,len);
id=M2C_FIELD(slot,u16 *,8);if(!id)return 0;
count=M2C_FIELD(slot,u16 *,4);i=covered=0;
while(i<count){u8 *p=slot+i*2;if(M2C_FIELD(p,u16 *,12)<=covered&&covered<M2C_FIELD(p,u16 *,28)){covered=M2C_FIELD(p,u16 *,28);i=0;}else i++;}
if(covered<id)return 0;
freeSlot=M2C_FIELD(slot,u8 **,0x34);
t=M2C_FIELD(slot,u16 *,10)+(M2C_FIELD(freeSlot,u8 *,14)&15)*4;
M2C_FIELD(freeSlot,u16 *,16)=((s32)t>>8)|(t<<8);
M2C_FIELD(slot,u16 *,4)=0;*done=1;return freeSlot+14;
}
#pragma scheduling on
void func_0201ce18(u8 *arg0, s32 arg1) {
    s32 Checksum(u8 *, u32);
    s32 func_0201a778(void);
    M2C_UNK func_0201ae0c(void *, M2C_UNK, s32);
    M2C_UNK func_0201bb88(void *, u8 *, M2C_UNK);
    M2C_UNK func_0201c820(void *, void *, s32);
    M2C_UNK UdpReceiveDatagram(void *, void *, s32);
    void *func_0201cb4c(void *, s32 *);
    extern M2C_UNK gNetStack;

    u32 left;
    u32 right;

    left = ((u32)(u16)((M2C_FIELD(arg0, u16 *, 0x10) >> 8) | (M2C_FIELD(arg0, u16 *, 0x10) << 8)) << 16) |
           (u16)((M2C_FIELD(arg0, u16 *, 0x12) >> 8) | (M2C_FIELD(arg0, u16 *, 0x12) << 8));
    right = ((u32)(u16)((M2C_FIELD(arg0, u16 *, 0xC) >> 8) | (M2C_FIELD(arg0, u16 *, 0xC) << 8)) << 16) |
            (u16)((M2C_FIELD(arg0, u16 *, 0xE) >> 8) | (M2C_FIELD(arg0, u16 *, 0xE) << 8));

    if (left != right) {
        u16 t2;
        u8 b0;
        u32 dataA, dataB;

        if (func_0201a778() == 0) {
            return;
        }
        t2 = M2C_FIELD(arg0, u16 *, 2);
        if (arg1 < (s32)(u16)((t2 >> 8) | (t2 << 8))) {
            return;
        }
        b0 = M2C_FIELD(arg0, u8 *, 0);
        if (Checksum(arg0, (u32)(b0 << 0x1C) >> 0x1A) != 0xFFFF) {
            return;
        }
        dataA = ((u32)(u16)((M2C_FIELD(arg0, u16 *, 0x10) >> 8) | (M2C_FIELD(arg0, u16 *, 0x10) << 8)) << 16) |
                (u16)((M2C_FIELD(arg0, u16 *, 0x12) >> 8) | (M2C_FIELD(arg0, u16 *, 0x12) << 8));
        if (M2C_FIELD(&gNetStack, s32 *, 0x50) == (s32)dataA) {
            dataB = ((u32)(u16)((M2C_FIELD(arg0, u16 *, 0xC) >> 8) | (M2C_FIELD(arg0, u16 *, 0xC) << 8)) << 16) |
                    (u16)((M2C_FIELD(arg0, u16 *, 0xE) >> 8) | (M2C_FIELD(arg0, u16 *, 0xE) << 8));
            func_0201ae0c(arg0 - 8, dataB, 1);
        }
    }

    {
        s32 sp0;
        void *rp;
        u8 type;
        u16 t2b;
        u8 b0;
        s32 off;
        void *ptr;
        s32 val;

        rp = func_0201cb4c(arg0, &sp0);
        if (rp == 0) {
            return;
        }
        type = M2C_FIELD(rp, u8 *, 9);
        t2b = M2C_FIELD(rp, u16 *, 2);
        b0 = M2C_FIELD(rp, u8 *, 0);
        off = (s32)((u32)(b0 << 0x1C) >> 0x1A);
        ptr = (u8 *)rp + off;
        val = (s32)(u16)((t2b >> 8) | (t2b << 8)) - off;

        if (type == 0x11) {
            UdpReceiveDatagram(rp, ptr, val);
        } else if (M2C_FIELD(&gNetStack, s32 *, 0x50) != 0) {
            if (type == 1) {
                func_0201bb88(rp, (u8 *)ptr, val);
            } else if (type == 6) {
                func_0201c820(rp, ptr, val);
            }
        }

        if (sp0 != 0) {
            M2C_FIELD(&gNetStack, M2C_UNK (**)(M2C_UNK), 0x40)((M2C_UNK)(rp - 0xE));
        }
    }
}

void func_0201cfdc(void) {
    u8 *func_0201aacc(s32 *);
    void func_0201ce18(u8 *, s32);
    void func_0201b840(u8 *, s32);
    void func_0201ab8c(void);

    s32 size;
    u8 *buf;
    u32 magic;

    for (;;) {
        buf = func_0201aacc(&size);
        if (size <= 0x22) {
            break;
        }
        magic = M2C_FIELD(buf, u16 *, 0xC);
        magic = (magic << 8) | (magic >> 8);
        magic = magic & 0xFFFF;
        if (magic == 0x800) {
            func_0201ce18(buf + 0xE, size - 0xE);
        } else if (magic == 0x806) {
            func_0201b840(buf + 0xE, size - 0xE);
            func_0201ab8c();
        }
    }
}

u16 func_0201d04c(void) {
    extern M2C_UNK gSocketManager;
    extern M2C_UNK gNetStack;

    u16 counter;
    u8 *node;
    u8 *child;
    s32 found;

    for (;;) {
        counter = M2C_FIELD(&gNetStack, u16 *, 8);
        counter = counter + 1;
        if (counter >= 0x400) {
            if (counter >= 0x1388) {
                counter = 0x400;
            }
        }
        M2C_FIELD(&gNetStack, u16 *, 8) = counter;

        node = M2C_FIELD(&gSocketManager, u8 *, 8);
        found = 0;
        if (node != 0) {
            do {
                child = M2C_FIELD(node, u8 *, 0xA4);
                if (child != 0) {
                    if (M2C_FIELD(child, s32 *, 0) != 0) {
                        if (M2C_FIELD(child, u16 *, 0xA) == counter) {
                            found = 1;
                            break;
                        }
                    }
                }
                node = M2C_FIELD(node, u8 *, 0x68);
            } while (node != 0);
        }
        if (found == 0) {
            break;
        }
    }
    return M2C_FIELD(&gNetStack, u16 *, 8);
}

s32 func_0201d0f4(void) {
    extern M2C_UNK gNetStack;
    u64 mult;
    u64 val;
    u64 add;
    u64 res;

    mult = M2C_FIELD(&gNetStack, u64 *, 0x70);
    val = M2C_FIELD(&gNetStack, u64 *, 0x68);
    add = M2C_FIELD(&gNetStack, u64 *, 0x78);
    res = mult * val + add;
    M2C_FIELD(&gNetStack, u64 *, 0x68) = res;
    return (s32)(res >> 32);
}

void func_0201d138(s32 arg0) {
    extern M2C_UNK gSocketManager;
    M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), s32 *, 0xA4) = arg0;
}

void func_0201d14c(void) {
    extern M2C_UNK gSocketManager;
    M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), s32 *, 0xA4) = 0;
}

void func_0201d164(void) {
    extern M2C_UNK gSocketManager;
    M2C_UNK *inner;
    M2C_UNK *q;
    inner = (M2C_UNK *)M2C_FIELD(&gSocketManager, void **, 4);
    q = (M2C_UNK *)M2C_FIELD(inner, void **, 0xA4);
    if (q == 0) {
        return;
    }
    M2C_FIELD(q, u8 *, 8) = 0xA;
    M2C_FIELD(q, s32 *, 0x44) = 0;
}

void func_0201d190(s32 arg0, s32 arg1, s32 arg2) {
    extern M2C_UNK gSocketManager;
    extern M2C_UNK gNetStack;
    u16 func_0201d04c(void);
    M2C_UNK *inner;
    M2C_UNK *q;
    s32 temp;
    inner = (M2C_UNK *)M2C_FIELD(&gSocketManager, void **, 4);
    q = (M2C_UNK *)M2C_FIELD(inner, void **, 0xA4);
    if (q == 0) {
        return;
    }
    if (arg2 == 0x7F000001) {
        temp = M2C_FIELD(&gNetStack, s32 *, 0x50);
    } else {
        temp = arg2;
    }
    M2C_FIELD(q, u16 *, 0x1A) = (u16)arg1;
    M2C_FIELD(q, u16 *, 0x18) = M2C_FIELD(q, u16 *, 0x1A);
    M2C_FIELD(q, s32 *, 0x20) = temp;
    M2C_FIELD(q, s32 *, 0x1C) = temp;
    if (arg0 != 0) {
        M2C_FIELD(q, s16 *, 0x0A) = (s16)arg0;
        return;
    }
    M2C_FIELD(q, s16 *, 0x0A) = func_0201d04c();
}

void func_0201d1f0(void) {
    extern M2C_UNK gSocketManager;
    M2C_UNK *inner;
    M2C_UNK *q;
    inner = (M2C_UNK *)M2C_FIELD(&gSocketManager, void **, 4);
    q = (M2C_UNK *)M2C_FIELD(inner, void **, 0xA4);
    if (q == 0) {
        return;
    }
    M2C_FIELD(q, void **, 0) = (void *)inner;
    M2C_FIELD(q, u8 *, 8) = 0;
    M2C_FIELD(q, s32 *, 0x44) = 0;
    M2C_FIELD(q, s32 *, 0x60) = 0;
    M2C_FIELD(q, s32 *, 0x38) = 0;
}

void func_0201d224(void) {
    extern M2C_UNK gSocketManager;
    void *x = M2C_FIELD(&gSocketManager, void **, 4);
    s32 *q = M2C_FIELD(x, s32 **, 0xa4);
    if (q != 0) {
        *q = 0;
    }
}

void func_0201d244(void *arg0) {
    extern M2C_UNK gSocketManager;
    M2C_FIELD(arg0, void **, 0xA4) = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, 0xA4);
}

void func_0201d25c(void *arg0) {
    M2C_UNK OS_SleepThread(M2C_UNK);
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 func_0201d0f4();
    s32 temp_r0;
    s32 temp_r4;

    temp_r0 = func_0201d0f4();
    M2C_FIELD(arg0, s32 *, 0x28) = temp_r0;
    M2C_FIELD(arg0, s32 *, 0x30) = temp_r0;
    M2C_FIELD(arg0, s8 *, 8) = 1;
    temp_r4 = OS_DisableInterrupts();
    M2C_FIELD(arg0, s32 *, 4) = 1;
    OS_SleepThread(0);
    OS_RestoreInterrupts(temp_r4);
}

void func_0201d29c(s32 arg0) {
    extern M2C_UNK gSocketManager;
    void *x = M2C_FIELD(&gSocketManager, void **, 4);
    s32 *q = M2C_FIELD(x, s32 **, 0xa4);
    if (q != 0) {
        M2C_FIELD(q, s32 *, 0x38) = arg0;
    }
}

void func_0201d2b8(void) {
    void func_02024b24(void);
    void func_0201d25c(void *);
    extern M2C_UNK gSocketManager;
    void *p = (void *) M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, 0xA4);
    if (p == 0) {
        return;
    }
    if (*((u8 *) p + 9) != 0) {
        func_02024b24();
    } else {
        func_0201d25c(p);
    }
}

s32 func_0201d2f0(void *arg0) {
    u64 GetSystemTick();
    M2C_UNK func_0201bee4(void *, M2C_UNK, M2C_UNK);
    extern M2C_UNK gNetStack;
    u32 var_r7;
    s32 temp_r8;
    s32 temp_r9;

    temp_r8 = func_0201d0f4();
    var_r7 = 0;
loop_1:
    M2C_FIELD(arg0, s32 *, 0x28) = temp_r8;
    M2C_FIELD(arg0, u8 *, 8) = 2U;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32)(GetSystemTick() >> 16);
    func_0201bee4(arg0, 2, 0x18);
    temp_r9 = OS_DisableInterrupts();
    if ((M2C_FIELD(arg0, u8 *, 8) == 2) && (M2C_FIELD(&gNetStack, s32 *, 0x50) != 0)) {
        M2C_FIELD(arg0, s32 *, 4) = 1;
        OS_SleepThread(0);
    }
    OS_RestoreInterrupts(temp_r9);
    if (M2C_FIELD(arg0, u8 *, 8) == 4) {
        return 0;
    }
    if ((M2C_FIELD(&gNetStack, s32 *, 0x50) == 0) || (++var_r7 >= 3U)) {
        return 1;
    }
    goto loop_1;
}

s32 func_0201d3a4(void){extern M2C_UNK gSocketManager;s32 func_02024c60(void*);void *p;p=M2C_FIELD(M2C_FIELD(&gSocketManager,void**,4),void**,0xa4);if(p){if(M2C_FIELD(p,u8*,9))return func_02024c60(p);return func_0201d2f0(p);}return 1;}

s32 func_0201d3e4(u16 *arg0,u32 *arg1) {
extern M2C_UNK gSocketManager;
void *p=M2C_FIELD(M2C_FIELD(&gSocketManager,void**,4),void**,0xa4);
if(p!=0&&(M2C_FIELD(p,u8*,8)==4||M2C_FIELD(p,u8*,8)==10)){
if(arg0!=0)*arg0=M2C_FIELD(p,u16*,0x18);
if(arg1!=0)*arg1=M2C_FIELD(p,u32*,0x14);
return M2C_FIELD(p,s32*,0x1c);
}
return 0;
}

void func_0201d434(void *arg0) {
    M2C_UNK TaskYield();
    M2C_UNK TcpSendAck(void *, M2C_UNK);
    M2C_UNK TcpSendFinAck(void *, M2C_UNK);
    u8 temp_r1;

    TaskYield();
    temp_r1 = M2C_FIELD(arg0, u8 *, 8);
    if ((u32) (u8) (temp_r1 + 0xFD) <= 1U) {
        TcpSendFinAck(arg0, 0x19);
        M2C_FIELD(arg0, u8 *, 8) = 7U;
        return;
    }
    if (temp_r1 == 0) {
        return;
    }
    TcpSendAck(arg0, 0x1A);
}

void func_0201d484(void) {
void func_020250d0(void *);
void func_0201d434(void *);
extern M2C_UNK gSocketManager;
void *p=M2C_FIELD(M2C_FIELD(&gSocketManager,void**,4),void**,0xa4);
if(p==0)return;
if(M2C_FIELD(p,u8*,9)!=0)func_020250d0(p);
func_0201d434(p);
}

void func_0201d4c0(void) {
extern M2C_UNK gSocketManager,gNetStack;
void func_02025150(void *);M2C_UNK func_0201a238();u64 GetSystemTick(void);
void *inner=M2C_FIELD(&gSocketManager,void **,4);
void *node=M2C_FIELD(inner,void **,0xa4);
s32 start;
if(!node)return;
if(M2C_FIELD(node,u8 *,9)){func_02025150(node);}
start=(u32)(GetSystemTick()>>16);
goto check;
loop:func_0201a238();
check:
if(!M2C_FIELD(&gNetStack,s32 (**)(void),0x48)() || !M2C_FIELD(node,u8 *,8))goto done;
if((s32)((u32)(GetSystemTick()>>16)-start)<39)goto loop;
done:M2C_FIELD(node,u8 *,8)=0;
}

s32 func_0201d548(s32 *arg0, void *arg1) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_SleepThread(M2C_UNK);
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 var_r6;
    s32 temp_r7;

    temp_r7 = OS_DisableInterrupts();
    var_r6 = M2C_FIELD(arg1, s32 *, 0x44);
    while (var_r6 == 0) {
        M2C_FIELD(arg1, s32 *, 4) = 3;
        OS_SleepThread(0);
        var_r6 = M2C_FIELD(arg1, s32 *, 0x44);
    }
    OS_RestoreInterrupts(temp_r7);
    *arg0 = var_r6;
    return M2C_FIELD(arg1, s32 *, 0x40);
}

s32 func_0201d59c(u32 *arg0, M2C_UNK arg1) {
    s32 OS_DisableInterrupts(void);
    M2C_UNK OS_SleepThread(M2C_UNK);
    M2C_UNK OS_RestoreInterrupts(s32);
    M2C_UNK TaskYield(void);
    s32 temp_r8;
    s32 temp_r0;

    if (M2C_FIELD((void *)arg1, s32 *, 0x44) == 0 && M2C_FIELD((void *)arg1, u8 *, 0x8) == 4) {
        temp_r8 = OS_DisableInterrupts();
        while (M2C_FIELD((void *)arg1, s32 *, 0x44) == 0 && M2C_FIELD((void *)arg1, u8 *, 0x8) == 4) {
            M2C_FIELD((void *)arg1, s32 *, 0x4) = 2;
            OS_SleepThread(0);
        }
        OS_RestoreInterrupts(temp_r8);
    } else {
        TaskYield();
    }
    temp_r0 = M2C_FIELD((void *)arg1, s32 *, 0x44);
    *arg0 = (u32)temp_r0;
    if (temp_r0 != 0) {
        return M2C_FIELD((void *)arg1, s32 *, 0x40);
    }
    return 0;
}

s32 func_0201d618(s32 *arg0) {
    s32 func_0201d548(s32 *, void *);
    s32 func_0201d59c(u32 *, M2C_UNK);
    s32 func_02024cb4(s32 *, void *);
    extern M2C_UNK gSocketManager;
    void *inner;
    void *q;
    u8 v;

    inner = M2C_FIELD(&gSocketManager, void **, 0x4);
    q = M2C_FIELD(inner, void **, 0xA4);
    if (q == 0) goto fail;
    v = (u8)(((u8 *)q)[8] + 0xF6);
    if (v <= 1) {
        return func_0201d548(arg0, q);
    }
    if (((u8 *)q)[9] != 0) {
        return func_02024cb4(arg0, q);
    }
    return func_0201d59c((u32 *)arg0, (M2C_UNK)q);

fail:
    *arg0 = 0;
    return 0;
}

void func_0201d67c(u32 arg0, void *arg1) {
    M2C_UNK OS_DisableInterrupts(void);
    M2C_UNK OS_RestoreInterrupts(M2C_UNK);
    M2C_UNK func_020651c4(M2C_UNK, M2C_UNK);
    M2C_UNK TcpSendAck(void *, M2C_UNK);
    u8 kind;
    u32 var_r6;
    u32 left;
    M2C_UNK irq;

    irq = OS_DisableInterrupts();
    left = M2C_FIELD(arg1, u32 *, 0x44);
    var_r6 = 0;
    if ((left == M2C_FIELD(arg1, u32 *, 0x3C)) && (arg0 != 0)) {
        var_r6 = 1;
    }
    if (arg0 >= left) {
        M2C_FIELD(arg1, u32 *, 0x44) = 0;
    } else {
        s32 base = M2C_FIELD(arg1, s32 *, 0x40);
        M2C_FIELD(arg1, u32 *, 0x44) = left - arg0;
        func_020651c4(base, base + arg0);
    }
    OS_RestoreInterrupts(irq);
    kind = M2C_FIELD(arg1, u8 *, 8);
    if (kind != 0xA && kind != 0xB) {
        if (M2C_FIELD(arg1, u32 *, 0x44) != 0) {
            if (var_r6 == 0) {
                return;
            }
            TcpSendAck(arg1, 0x1B);
        }
    }
}

void func_0201d70c(u32 arg0) {
void func_02024d8c(u32,void *);
void func_0201d67c(u32,void *);
extern M2C_UNK gSocketManager;
void *p=M2C_FIELD(M2C_FIELD(&gSocketManager,void**,4),void**,0xa4);
if(p==0)return;
if(M2C_FIELD(p,u8*,9)!=0)func_02024d8c(arg0,p);
else func_0201d67c(arg0,p);
}

s32 func_0201d744(M2C_UNK arg0, s32 arg1, M2C_UNK arg2, s32 arg3) {
    extern M2C_UNK gNetStack;
    M2C_UNK TcpSendSegment(M2C_UNK, s32, M2C_UNK, s32, s32);
    M2C_UNK TaskYield(void);

    M2C_UNK v8;
    s32 v11;
    M2C_UNK v10;
    s32 v9;
    s32 v6;
    s32 v5;
    s32 v7;
    s32 v4;
    s32 v1;
    s32 sum;
    u16 global;
    s32 zero;

    v8 = arg2;
    v11 = arg3;
    v10 = arg0;
    v9 = arg1;
    v6 = M2C_FIELD(v8, s32 *, 0x34);
    if (v11 != 0) {
        v5 = 1;
    } else {
        v5 = M2C_FIELD(v8, u16 *, 0x2C);
    }
    v7 = (v6 << 1) + 4;

    for (;;) {
        v4 = M2C_FIELD(v8, u16 *, 0x2E);
        global = M2C_FIELD(&gNetStack, u16 *, 0x2);
        v1 = M2C_FIELD(v8, s32 *, 0x34);
        if ((u32)v4 >= (u32)v5) {
            v4 = v5;
        }
        if ((u32)global < (u32)v4) {
            v4 = global;
        }
        if (v11 == 0) {
            v4 &= ~1;
        }
        if (v9 < v4) {
            v4 = v9;
        }
        sum = v7 + (v1 - v6);
        if (sum == 0) {
            v4 = 0;
        }
        v6 = v1;
        v7 = sum - 1;
        if (v4 == 0) {
            break;
        }
        zero = 0;
        v5 = v5 - v4;
        TcpSendSegment(v10, v4, v8, 0x18, zero);
        TaskYield();
        v10 = (M2C_UNK)((u8 *)v10 + v4);
        v9 = v9 - v4;
        if (v9 == 0) {
            break;
        }
        if (M2C_FIELD(v8, u8 *, 8) != 4) {
            break;
        }
    }
    return v4;
}

void func_0201d808(M2C_UNK arg0, s32 arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_0201d744(M2C_UNK, s32, s32, s32);
    if ((func_0201d744(arg0, arg1, arg4, arg5) != 0) && (arg3 != 0)) {
        func_0201d744(arg2, arg3, arg4, 0);
    }
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
/* Sends up to two buffers through the TCP socket until the link stops accepting
 * data or 0x9F ticks pass without progress; returns the number of bytes sent. */
s32 TcpSendData(s32 src1, s32 len1, s32 src2, s32 len2, void *sock) {
    u64 GetSystemTick();
    M2C_UNK func_0201a238();
    extern M2C_UNK gNetStack;
    s32 total;
    u32 lastSend;
    s32 left2;
    s32 split;
    s32 sendStart;
    s32 waitStart;
    s32 ptr1;
    u32 progress;
    s32 waited;
    u32 pollStart;
    s32 ptr2;
    u32 now1;
    u32 now2;
    s32 left1;

    ptr1 = src1;
    total = 0;
    left1 = len1;
    ptr2 = src2;
    left2 = len2;
    waited = 0;
    M2C_FIELD(sock, s32 *, TCP_SOCK_RESULT) = 0;
    lastSend = (u32)(GetSystemTick() >> 16);
    goto gate;
body:
    sendStart = M2C_FIELD(sock, s32 *, TCP_SOCK_SENDPOS);
    func_0201d808(ptr1, left1, ptr2, left2, sock, waited);
    pollStart = (u32)(GetSystemTick() >> 16);
loop_2:
    func_0201a238();
    if ((M2C_FIELD(&gNetStack, s32 (**)(), NETSTACK_POLL)() != 0) && (M2C_FIELD(sock, u8 *, TCP_SOCK_STATE) == 4) && (M2C_FIELD(sock, s32 *, TCP_SOCK_SENDPOS) != M2C_FIELD(sock, s32 *, TCP_SOCK_SENTPOS))) {
        now1 = (u32)(GetSystemTick() >> 16);
        if ((s32)(now1 - pollStart) < 0xF) {
            if (!((waited != 0) && (M2C_FIELD(sock, u16 *, TCP_SOCK_ACKFLAG) != 0))) {
                goto loop_2;
            }
        }
    }
    progress = M2C_FIELD(sock, s32 *, TCP_SOCK_SENTPOS) - sendStart;
    if (progress > (u32)(M2C_FIELD(sock, s32 *, TCP_SOCK_SENDPOS) - sendStart)) {
        progress = 0;
    }
    total += progress;
    if (progress != 0) {
        lastSend = (u32)(GetSystemTick() >> 16);
    }
    M2C_FIELD(sock, s32 *, TCP_SOCK_SENDPOS) = (s32)M2C_FIELD(sock, s32 *, TCP_SOCK_SENTPOS);
    if ((M2C_FIELD(sock, u8 *, TCP_SOCK_STATE) == 4) && (M2C_FIELD(sock, u16 *, TCP_SOCK_ACKFLAG) == 0) && (progress == 0)) {
        if (waited == 0) {
            waitStart = (s32)(u32)(GetSystemTick() >> 16);
            goto check_22;
loop_22:
            func_0201a238();
            if (M2C_FIELD(sock, u16 *, TCP_SOCK_ACKFLAG) != 0) goto done_22;
check_22:
            if (M2C_FIELD(&gNetStack, s32 (**)(), NETSTACK_POLL)() != 0) {
                now2 = (u32)(GetSystemTick() >> 16);
                if ((s32)(now2 - waitStart) < 0xF) {
                    goto loop_22;
                }
            }
done_22:
            if (M2C_FIELD(sock, u16 *, TCP_SOCK_ACKFLAG) == 0) {
                waited = 1;
            }
        }
    } else {
        waited = 0;
    }
    if (progress < (u32)left1) {
        ptr1 += (s32)progress;
        left1 -= (s32)progress;
    } else {
        split = (s32)progress - left1;
        ptr1 = ptr2 + split;
        ptr2 = 0;
        left1 = left2 - split;
        left2 = 0;
    }
    goto gate;
gate:
    if ((M2C_FIELD(&gNetStack, s32 (**)(), NETSTACK_POLL)() == 0) || (left1 == 0)) {
        goto ret;
    }
    if (M2C_FIELD(sock, u8 *, TCP_SOCK_STATE) != 4) {
        goto ret;
    }
    progress = (u32)(GetSystemTick() >> 16);
    if ((s32)(progress - lastSend) >= 0x9F) {
        goto ret;
    }
    goto body;
ret:
    return total;
}
#pragma pop
s32 func_0201da4c(s32 a,s32 b,s32 c,s32 d){
extern M2C_UNK gSocketManager;extern M2C_UNK gNetStack;
void func_0201b3e8(s32,s32,void *);void func_0201b338(s32,s32,void *);s32 func_02024f9c(s32,s32,s32,s32,void *);s32 TcpSendData(s32,s32,s32,s32,void *);
void *p; s32 result;
p=M2C_FIELD(M2C_FIELD(&gSocketManager,void **,4),void **,0xa4);
if(p!=0){
if(M2C_FIELD(p,u8 *,8)==10){if(b)func_0201b3e8(a,b,p);if(d)func_0201b3e8(c,d,p);result=b+d;}
else if(M2C_FIELD(p,u8 *,8)==11){if(b)func_0201b338(a,b,p);if(d)func_0201b338(c,d,p);result=b+d;}
else if(M2C_FIELD(p,u8 *,9))result=func_02024f9c(a,b,c,d,p);
else result=TcpSendData(a,b,c,d,p);
if(M2C_FIELD(&gNetStack,u8 *,0)==0)return result;
}return 0;
}

