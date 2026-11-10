/* 29 functions from 0x02019E64 to 0x0201AE0C (main), found by ds-decomp. */
#include "common.h"
#include "tcp_socket.h"
static inline void seed_network_random(unsigned long long seed) { extern s32 gNetStack; M2C_FIELD(&gNetStack,unsigned long long *,0x68)=seed; M2C_FIELD(&gNetStack,unsigned long long *,0x70)=0x5d588b656c078965ULL; M2C_FIELD(&gNetStack,unsigned long long *,0x78)=0x269ec3; }
typedef struct { u8 dest[6],src[6];u16 type;u8 pad14,hw;u8 proto,pad17;u16 sizes;u8 pad20,op;u8 sender[6];u16 shi,slo;u8 target[6];u16 thi,tlo; } Packet0201ACA0;

typedef struct {
    u16 tag;
    u8 pad[4];
    u16 extra;
} Func0201A09CBuf;

s32 func_02019e64(void *out, s32 *outCount, s8 *input, s32 *inCount, s32 (*callback)(u16 *,s32 *,const char *,s32 *)) {
extern u16 data_020f5574[];
u16 units[4];
s32 produced, consumed;
s32 outPos,outLimit,inPos,inLimit;
s32 i;
s32 result=0;
if(!input) return 2;
inPos=0;outPos=0;
if(inCount && *inCount>=0) inLimit=*inCount; else inLimit=0x7fffffff;
if(out && outCount && *outCount>=0) outLimit=*outCount; else outLimit=0x7fffffff;
while(outPos<outLimit && inPos<inLimit){
u32 ch;
s8 *cur=(s8 *)input+inPos;
produced=0;
ch=(u8)*cur;
if(ch==0)break;
if(ch<=0x7e){units[0]=ch;produced=consumed=1;}
else if(ch>=0xa1 && ch<=0xdf){units[0]=ch+0x3ec0+0xc000;produced=consumed=1;}
else {
s32 valid=0;
if((u32)(((u8)*cur^0x20)-0xa1)<0x3c){
s32 next=cur[1];
if(next!=0x7f && (u8)(next-0x40)<=0xbc)valid=1;
}
if(valid){
consumed=2;
if(inPos+2<=inLimit){
s32 lead=ch-((ch>=0xe0?0x40:0)+0x81);
units[0]=data_020f5574[lead*0xc0+(u8)cur[1]-0x40];
produced=units[0]!=0;
}
}
}
if(!produced){
if(!callback){result=3;break;}
consumed=inLimit-inPos;
produced=4;
result=callback(units,&produced,(char *)input+inPos,&consumed);
if(result)break;
}
if(inPos+consumed>inLimit || outPos+produced>outLimit)break;
if(out){
for(i=0;i<produced;i++){
u16 value=units[i];
u8 *dst=(u8 *)out+(outPos+i)*2;
dst[0]=value;
dst[1]=value>>8;
}
}
outPos+=produced;
inPos+=consumed;
}
if(inCount)*inCount=inPos;
if(outCount)*outCount=outPos;
return result;
}

s32 func_0201a09c(u8 *r0) {
    void MI_CpuCopy8(void *, void *, s32);
    void func_020067c4(void *, s32);
    Func0201A09CBuf buf;
    if (r0 == NULL) return 0;
    if (*(u16 *)(r0 + 0x3C) == 0) return 0;
    MI_CpuCopy8(r0 + 0x50, &buf, 8);
    func_020067c4(&buf, 8);
    if (*(s32 *)(r0 + 0x44) == 0) {
        if (*(volatile u16 *)&buf.tag == 0x2348 || *(volatile u16 *)&buf.tag == 0xBD8A) {
            if (buf.extra == 4) return 1;
        }
    }
    return 0;
}

void func_0201a134(s32 arg0) {
    extern M2C_UNK gNetStack;
    extern M2C_UNK data_02137310;
    extern M2C_UNK gSocketManager;
    extern M2C_UNK data_021375b8;
    void MI_CpuFill8(void *, s32, s32);
    void TaskWake(s32);
    void func_02025298(void);
    s32 old;
    void *node;
    void *sub;
    u8 t;
    void *fld4;
    s32 i;
    u8 *p;
    void (*fp)(u32);
    u32 val;
    old = M2C_FIELD(&gNetStack, s32 *, 0x50);
    M2C_FIELD(&gNetStack, s32 *, 0x0C) = arg0;
    M2C_FIELD(&gNetStack, s32 *, 0x50) = 0;
    M2C_FIELD(&gNetStack, s32 *, 0x1C) = 0;
    M2C_FIELD(&gNetStack, s32 *, 0x2C) = 0;
    M2C_FIELD(&gNetStack, s32 *, 0x60) = 0;
    M2C_FIELD(&gNetStack, s32 *, 0x64) = 0;
    M2C_FIELD(&gNetStack, s32 *, 0x20) = 0;
    if (old == 0) {
        return;
    }
    MI_CpuFill8(&data_02137310, 0, 0x60);
    node = M2C_FIELD(&gSocketManager, void **, 0x08);
    while (node != 0) {
        sub = M2C_FIELD(node, void **, 0xA4);
        if (sub != 0) {
            if (M2C_FIELD(sub, void **, 0x00) != 0) {
                t = M2C_FIELD(sub, u8 *, 0x08);
                if (t != 0x0A && t != 0x0B) {
                    M2C_FIELD(sub, u8 *, 0x08) = 0;
                }
                fld4 = M2C_FIELD(sub, void **, 0x04);
                if (fld4 != 0) {
                    M2C_FIELD(sub, void **, 0x04) = 0;
                    TaskWake((s32)M2C_FIELD(sub, void **, 0x00));
                }
            }
        }
        node = M2C_FIELD(node, void **, 0x68);
    }
    i = 0;
    p = (u8 *)&data_021375b8;
    for (; i < 8; i++, p += 0x38) {
        if (M2C_FIELD(p, u16 *, 0x04) != 0) {
            fp = (void (*)(u32)) M2C_FIELD(&gNetStack, void **, 0x40);
            val = M2C_FIELD(p, u32 *, 0x34);
            fp(val);
            M2C_FIELD(p, u16 *, 0x04) = 0;
        }
    }
    func_02025298();
}

void func_0201a238(void) {
    extern M2C_UNK gNetStack;
    void TaskYield(void);
    void func_02006030(s32);
    s32 f = M2C_FIELD(&gNetStack, s32 *, 0x24);
    if (f == 0) {
        TaskYield();
    } else {
        func_02006030(f);
    }
}

void func_0201a260(void) {

}

s32 func_0201a264(void) {
    return 1;
}

void func_0201a26c(void *arg0) {
    void func_02000b9c(s32);
    unsigned long long GetSystemTick(void);
    void GetMacAddress(s32);
    void func_02005ac0(void *, void *, s32, void *, s32, s32);
    void TaskWake(s32);
    s32 func_0201a264(void);
    void func_0201a260(void);
    void func_0201cfdc(void);
    void func_0201dd08(void);
    extern s32 gNetStack;
    extern s32 data_02137778;
    extern s32 data_020faf74;
    extern s32 data_021374f8;
    extern s32 data_02138ac0;
    extern s32 data_02137438;
    extern s32 data_021382c0;

    func_02000b9c(0x2000bdc);

    {
        u32 lo; s32 hi;
hi=M2C_FIELD(arg0,s32 *,0x18);lo=M2C_FIELD(arg0,u32 *,0x14);
        if(hi || lo) {
 M2C_FIELD(&gNetStack,u32 *,0x68)=lo;
 M2C_FIELD(&gNetStack,u32 *,0x6c)=hi;
 M2C_FIELD(&gNetStack,u32 *,0x70)=0x6c078965;
 M2C_FIELD(&gNetStack,u32 *,0x74)=0x5d588b65;
 M2C_FIELD(&gNetStack,u32 *,0x78)=0x269ec3;
 M2C_FIELD(&gNetStack,u32 *,0x7c)=0;
 }
        else seed_network_random(GetSystemTick());
    }

    {
        s32 v4 = M2C_FIELD(arg0, s32 *, 0x4);
        if (v4 != 0 && M2C_FIELD(arg0, s32 *, 8) != 0) {
            M2C_FIELD((u8 *)&gNetStack, s32 *, 0x14) = v4;
            M2C_FIELD((u8 *)&gNetStack, s32 *, 0x40) = M2C_FIELD(arg0,s32 *,8);
        } else {
            M2C_FIELD((u8 *)&gNetStack, s32 *, 0x14) = (s32)func_0201a260;
            M2C_FIELD((u8 *)&gNetStack, s32 *, 0x40) = (s32)func_0201a260;
        }
    }

    M2C_FIELD((u8 *)&gNetStack, s32 *, 0x10) = M2C_FIELD(arg0, s32 *, 0x0);

    {
        s32 f24 = M2C_FIELD(arg0, s32 *, 0x24);
        if (f24 == 0) f24 = 0x5b4;
        M2C_FIELD((u8 *)&gNetStack, s16 *, 0x2) = (s16)f24;
    }
    M2C_FIELD((u8 *)&gNetStack, s32 *, 0x34) = M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD((u8 *)&gNetStack, s32 *, 0x24) = M2C_FIELD(arg0, s32 *, 0x2c);

    {
        s32 fc = M2C_FIELD(arg0, s32 *, 0xc);
        if (fc == 0) fc = (s32)func_0201a260;
        M2C_FIELD((u8 *)&gNetStack, s32 *, 0x18) = fc;
    }

    {
        s32 f10 = M2C_FIELD(arg0, s32 *, 0x10);
        if (f10 != 0) {
            M2C_FIELD((u8 *)&gNetStack, s32 *, 0x48) = f10;
        } else {
            M2C_FIELD((u8 *)&gNetStack, s32 *, 0x48) = (s32)func_0201a264;
        }
    }

    M2C_FIELD((u8 *)&gNetStack, s32 *, 0x58) = M2C_FIELD(arg0, s32 *, 0x1c);
    M2C_FIELD((u8 *)&gNetStack, s32 *, 0x5c) = M2C_FIELD(arg0, s32 *, 0x20);
    M2C_FIELD((u8 *)&gNetStack, s32 *, 0x30) = 0;
    M2C_FIELD((u8 *)&gNetStack, s32 *, 0x28) = 0;

    {
        unsigned long long state = M2C_FIELD((u8 *)&gNetStack, unsigned long long *, 0x68);
        state = state * M2C_FIELD((u8 *)&gNetStack, unsigned long long *, 0x70) + M2C_FIELD((u8 *)&gNetStack, unsigned long long *, 0x78);
        M2C_FIELD((u8 *)&gNetStack, unsigned long long *, 0x68) = state;
        M2C_FIELD((u8 *)&gNetStack, u16 *, 8) = (u16)((u32)(((state >> 32) * 0xf88) >> 32) + 0x400);
        GetMacAddress((s32)&data_02137778);
    }

    M2C_FIELD((u8 *)&gNetStack, u8 *, 0x1) = 0;
    {
        func_02005ac0((void *)&data_021374f8, (void *)func_0201cfdc, 0, (void *)&data_02138ac0, 0x800, data_020faf74);
        func_02005ac0((void *)&data_02137438, (void *)&func_0201dd08, 0, (void *)&data_021382c0, 0x800, data_020faf74);
    }
    TaskWake((s32)&data_021374f8);
    TaskWake((s32)&data_02137438);
}

#pragma opt_common_subs off
void *func_0201a4a8(void) {
s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);s32 func_02005d90(s32);void TaskWake(s32);
extern M2C_UNK data_02137438;extern M2C_UNK gNetStack;
s32 saved=OS_DisableInterrupts();
s32 result=func_02005d90((s32)&data_02137438);
if(result==0 && M2C_FIELD(&gNetStack,s32 *,0x44)==0) {
M2C_FIELD(&gNetStack,s32 *,0x44)=1;
TaskWake((s32)&data_02137438);
}
OS_RestoreInterrupts(saved);return (void *)result;
}
#pragma opt_common_subs on

void func_0201a4f8(s32 arg0) {
    extern M2C_UNK gNetStack;
    M2C_FIELD(&gNetStack, s32 *, 0x3C) = arg0;
}

void func_0201a508(void){void *func_0201a4a8(void);void func_02005d60(void *);void func_02005ccc(void *);void func_0201a134(s32);extern M2C_UNK data_02137438,data_021374f8,gNetStack;func_0201a4a8();func_02005d60(&data_02137438);func_02005ccc(&data_021374f8);M2C_FIELD(&gNetStack,s32 *,84)=0;func_0201a134(0);M2C_FIELD(&gNetStack,s32 *,88)=0;M2C_FIELD(&gNetStack,s32 *,92)=0;}

void func_0201a550(s32 arg0) {
    M2C_UNK func_02005f80(M2C_UNK *, s32);
    extern s32 data_020faf74;
    extern M2C_UNK data_02137438;
    extern M2C_UNK data_021374f8;
    data_020faf74 = arg0;
    func_02005f80(&data_021374f8, arg0);
    func_02005f80(&data_02137438, arg0);
}

u32 ChecksumAccumulate(u8 *p,u32 n,u32 sum){u32 v;if((u32)p&1){while(n>1){sum+=(u16)((p[0]<<8)|p[1]);n-=2;p+=2;}}else{v=(u16)sum;sum=(u16)(((s32)v>>8)|(v<<8));while(n>1){sum+=*(u16 *)p;p+=2;n-=2;}v=((sum>>8)&0x00ff00ff)|((sum<<8)&0xff00ff00);sum=(v>>16)|(v<<16);}if(n)sum+=*p<<8;v=(u16)sum+(sum>>16);v+=v>>16;return (u16)v;}

s32 ChecksumFinalize(s32 arg0) {
    u16 var_r0;

    var_r0 = arg0 ^ 0xFFFF;
    if (var_r0 == 0) {
        var_r0 = 0xFFFF;
    }
    return (s32) var_r0;
}

void Checksum(M2C_UNK arg0, M2C_UNK arg1) {
    ChecksumFinalize((u16)ChecksumAccumulate((u8 *)arg0, (u32)arg1, 0));
}

s32 IsTransportChecksumBad(u8 *a,s32 b,u8 *c,u32 d){u32 r;r=ChecksumAccumulate(c+12,8,ChecksumAccumulate(a,b,d));r+=b;if(r&0x10000)r=(u16)(r+1);return r!=65535;}

s32 func_0201a6c4(s32 a){extern M2C_UNK gNetStack;s32 r=1;if(a!=-1&&a!=0x7f000001){s32 mask=M2C_FIELD(&gNetStack,s32 *,28);if((a&mask)!=(M2C_FIELD(&gNetStack,s32 *,80)&mask))r=0;}return r;}

s32 func_0201a704(s32 a){s32 func_0201a6c4(s32);extern M2C_UNK gNetStack;if(!func_0201a6c4(a))a=M2C_FIELD(&gNetStack,s32 *,44);return a;}

s32 func_0201a728(s32 a){extern M2C_UNK gNetStack;s32 r=0;if(func_0201a6c4(a)){s32 m=~M2C_FIELD(&gNetStack,s32 *,28);if(m==(m&a))r=1;}return r;}

s32 func_0201a764(s32 arg0) {
    if ((arg0 & 0xF0000000) == 0xE0000000) {
        return 1;
    }
    return 0;
}

s32 func_0201a778(s32 a){extern M2C_UNK gNetStack;s32 r=1,s=1,t=1,u=1; s32 own=M2C_FIELD(&gNetStack,s32 *,80);if(own!=0&&a!=own)u=0;if(!u&&a!=0x7f000001)t=0;if(!t&&!func_0201a728(a))s=0;if(!s&&!func_0201a764(a))r=0;return r;}

s32 func_0201a7f8(u16 *a,u16 *b){s32 i=0;do{if(*a++!=*b++)return 1;i++;}while(i<3);return 0;}

void func_0201a824(u8 *a,s32 b,s32 c,s32 d){void MI_CpuCopy8(void *,void *,s32);s32 func_02029848(void *,void *,s32,s32,s32);extern M2C_UNK gLinkHeaderTemplate,gNetStack;MI_CpuCopy8(&gLinkHeaderTemplate,a+6,6);M2C_FIELD(&gNetStack,u8 *,0)=func_02029848(a,a+6,b-6,c,d)<0;}

/* Append a link-layer frame to the network stack's transmit ring.  The record
 * is [u16 length][6-byte destination][6-byte source][frame+6 ..], where the
 * first six frame bytes (the SNAP header) are dropped and rebuilt from the link
 * addresses; an optional second buffer is appended as a trailer.  The frame must
 * carry the SNAP prefix and an IPv4 (0x0800) or ARP (0x0806) ethertype, and the
 * ring must have room for the whole record without wrapping it. */
void NetStackQueuePacket(s32 srcLink, s32 dstLink, s32 frame, s32 frameLen, s32 extraData, s32 extraLen) {
    extern M2C_UNK gNetStack;
    extern M2C_UNK gLinkHeaderTemplate;
    void MI_CpuCopy8(void *, void *, s32);
    u32 totalLen;
    u32 recordLen;
    u32 writeEnd;
    u32 nextWrite;
    u8 *ring;

    ring = M2C_FIELD(&gNetStack, u8 **, NETSTACK_RING_BUF);
    if (ring == NULL || M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_SIZE) == 0) {
        return;
    }
    totalLen = (u32)frameLen + (u32)extraLen;
    if (totalLen < 8 || totalLen > NETSTACK_MAX_PACKET) {
        return;
    }
    if (((u8 *)frame)[0] != M2C_FIELD(&gLinkHeaderTemplate, u8 *, 0) || ((u8 *)frame)[1] != M2C_FIELD(&gLinkHeaderTemplate, u8 *, 1) ||
        ((u8 *)frame)[2] != M2C_FIELD(&gLinkHeaderTemplate, u8 *, 2) || ((u8 *)frame)[6] != 8) {
        return;
    }
    if (((u8 *)frame)[7] != 0 && ((u8 *)frame)[7] != 6) {
        return;
    }
    recordLen = (u16)((totalLen + 9) & ~1);
    writeEnd = M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE) + recordLen;
    if (M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE) < M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_READ)) {
        if (M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_READ) <= writeEnd) {
            return;
        }
    }
    if (writeEnd == M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_SIZE)) {
        nextWrite = 0;
        if (M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_READ) == 0) {
            return;
        }
    } else if (writeEnd > M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_SIZE)) {
        nextWrite = recordLen;
        if (M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_READ) <= recordLen) {
            return;
        }
    } else {
        nextWrite = writeEnd;
    }
    if (M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE) + recordLen > M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_SIZE)) {
        if (M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_SIZE) - M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE) >= 2) {
            *(u16 *)(ring + M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE)) = 0;
        }
        M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE) = 0;
    }
    *(u16 *)(M2C_FIELD(&gNetStack, u8 **, NETSTACK_RING_BUF) + M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE)) = (u16)recordLen;
    MI_CpuCopy8((void *)dstLink, M2C_FIELD(&gNetStack, u8 **, NETSTACK_RING_BUF) + M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE) + 2, 6);
    MI_CpuCopy8((void *)srcLink, M2C_FIELD(&gNetStack, u8 **, NETSTACK_RING_BUF) + M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE) + 8, 6);
    MI_CpuCopy8((u8 *)frame + 6, M2C_FIELD(&gNetStack, u8 **, NETSTACK_RING_BUF) + M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE) + 0xe, frameLen - 6);
    if (extraData != 0 && extraLen != 0) {
        MI_CpuCopy8((void *)extraData, M2C_FIELD(&gNetStack, u8 **, NETSTACK_RING_BUF) + M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE) + 8 + frameLen, extraLen);
    }
    M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_WRITE) = nextWrite;
}

void func_0201aa74(s32 a,s32 b,s32 c,s32 d){void NetStackQueuePacket(s32,s32,s32,s32,s32,s32);s32 func_02005d90(s32);void TaskWake(s32);extern M2C_UNK gNetStack;NetStackQueuePacket(a,b,c,d,0,0);if(!M2C_FIELD(&gNetStack,volatile s32 *,84))return;if(func_02005d90(M2C_FIELD(&gNetStack,volatile s32 *,84)))return;TaskWake(M2C_FIELD(&gNetStack,volatile s32 *,84));}

u8 *func_0201aacc(s32 *out){s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);void OS_SleepThread(s32);extern M2C_UNK gNetStack,gSocketManager;s32 key;u32 size;u8 *p;u32 len;key=OS_DisableInterrupts();while(M2C_FIELD(&gNetStack,u32 *,48)==M2C_FIELD(&gNetStack,u32 *,40)){M2C_FIELD(&gNetStack,s32 *,84)=M2C_FIELD(&gSocketManager,s32 *,4);OS_SleepThread(0);M2C_FIELD(&gNetStack,s32 *,84)=0;}OS_RestoreInterrupts(key);p=M2C_FIELD(&gNetStack,u8 **,88);do{size=M2C_FIELD(&gNetStack,u32 *,92);if(size-M2C_FIELD(&gNetStack,u32 *,48)<2)M2C_FIELD(&gNetStack,u32 *,48)=0;len=M2C_FIELD(p,u16 *,M2C_FIELD(&gNetStack,u32 *,48));if(!len)M2C_FIELD(&gNetStack,u32 *,48)=0;}while(!len);*out=len-2;return M2C_FIELD(&gNetStack,u8 **,88)+M2C_FIELD(&gNetStack,u32 *,48)+2;}

#pragma opt_strength_reduction off
void func_0201ab8c(void){
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gNetStack;
    s32 key;
    u32 old;
    u8 *buf;
    key = OS_DisableInterrupts();
    old = M2C_FIELD(&gNetStack, volatile u32 *, 0x30);
    buf = (u8 *)M2C_FIELD(&gNetStack, u8 **, 0x58);
    M2C_FIELD(&gNetStack, volatile u32 *, 0x30) = old + M2C_FIELD(buf, u16 *, M2C_FIELD(&gNetStack, volatile u32 *, 0x30));
    if (M2C_FIELD(&gNetStack, volatile u32 *, 0x30) >= M2C_FIELD(&gNetStack, u32 *, 0x5c)) M2C_FIELD(&gNetStack, volatile u32 *, 0x30) = 0;
    OS_RestoreInterrupts(key);
}
#pragma opt_strength_reduction reset
s32 func_0201abd0(s32 a){extern M2C_UNK gNetStack,data_02137778,data_020faf78,data_02137310,data_0213731a;s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);u64 GetSystemTick(void);s32 irq=OS_DisableInterrupts();u32 i;void *r=0;u8 *p;if(a==0x7f000001 || a==M2C_FIELD(&gNetStack,s32 *,0x50))r=&data_02137778;else if(func_0201a728(a)||func_0201a764(a))r=&data_020faf78;else{p=(u8 *)&data_02137310;for(i=0;i<8;i++,p+=12){if(a==*(s32 *)p){a=GetSystemTick()>>16;M2C_FIELD(&data_0213731a,u16 *,i*12)=a;r=(u8 *)&data_02137310+i*12+4;break;}}}OS_RestoreInterrupts(irq);return (s32)r;}

/* Build and send a 42-byte ARP-style announcement packet for `nodeId`, swapping byte order in the id fields. */
void func_0201aca0(s32 nodeId) {
    extern M2C_UNK data_02137778;
    extern M2C_UNK gNetStack;
    void MI_CpuFill8(void *, s32, s32);
    void MI_CpuCopy8(void *, void *, s32);
    Packet0201ACA0 packet;
    s32 hi;
    s32 lo;
    s32 ahi;
    s32 alo;
    u32 own;
    MI_CpuFill8(&packet, 0, 42);
    MI_CpuFill8(packet.dest, 255, 6);
    MI_CpuCopy8(&data_02137778, packet.src, 6);
    packet.type = 0x608;
    packet.hw = 1;
    packet.proto = 8;
    packet.sizes = 0x406;
    packet.op = 1;
    MI_CpuCopy8(&data_02137778, packet.sender, 6);
    own = M2C_FIELD(&gNetStack, u32 *, 80);
    hi = (u16)(own >> 16);
    lo = (u16)own;
    ahi = (u16)((u32)nodeId >> 16);
    alo = (u16)nodeId;
    packet.shi = (hi >> 8) | (hi << 8);
    packet.slo = (lo >> 8) | (lo << 8);
    packet.thi = (ahi >> 8) | (ahi << 8);
    packet.tlo = (alo >> 8) | (alo << 8);
    func_0201a824((u8 *)&packet, 42, 0, 0);
}

s32 func_0201ad9c(s32 a){void func_0201aca0(s32);void func_02006030(s32);s32 func_0201abd0(s32);extern M2C_UNK gNetStack;u32 i,j;s32 r;for(i=0;i<8;i++){func_0201aca0(a);for(j=0;j<20;j++){if(!M2C_FIELD(&gNetStack,s32 *,80))return 0;func_02006030(100);r=func_0201abd0(a);if(r)return r;}}return 0;}

