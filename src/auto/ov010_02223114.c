/* 31 functions from 0x02223114 to 0x02224080 (ov010), found by ds-decomp. */
#include "common.h"

s32 func_ov010_02223114(void) {
    s32 func_ov010_02223420(void);
    s32 func_ov010_02223430(s32);
    M2C_UNK func_ov010_022223e8(void *, void *, s32);
    void *func_ov010_02223440(s32);
    M2C_UNK func_ov010_02223478(void *);
    void func_ov010_022235a4();
    M2C_UNK func_ov010_02223624(void *, void *, s32);
    s32 Link_InsertPacket(void *, u8);
    M2C_UNK Link_FreePacket();
    s32 i;
    s32 type;
    s32 count;
    s32 id;
    void *head;
    void *item;
    void *old;
    head = (void *)func_ov010_02223420();
    if (head == NULL) return 0;
    id = M2C_FIELD(head, u8 *, 0x11);
    count = func_ov010_02223430(id);
    i = 0;
    if (count > 0) {
        do {
            item = func_ov010_02223440(id);
            type = M2C_FIELD(item, s32 *, 0xC);
            if (type >= 2) {
                func_ov010_022223e8(M2C_FIELD(item, void **, 0x474), (s8 *)item + 0x1C, M2C_FIELD(item, s32 *, 0x14));
            } else {
                old = M2C_FIELD(item, void **, 0x474);
                if (type == 1) func_ov010_022235a4(old, (s8 *)item + 0x1C);
                else func_ov010_02223624(old, (s8 *)item + 0x1C, M2C_FIELD(item, s32 *, 0x14));
            }
            M2C_FIELD(item, void **, 0x474) = (s8 *)item + 0x1C;
            func_ov010_02223478(item);
            if (Link_InsertPacket(item, M2C_FIELD(item, u8 *, 0x11)) < 0) Link_FreePacket(item);
            i++;
        } while (i < count);
    }
    return count;
}

#pragma intrinsic on
s32 func_ov010_022231d4(void) {
M2C_UNK func_020444cc(u8,s32,s32);
s32 Link_BuildNextPacket(void);
extern M2C_UNK data_ov010_0222c960, gLinkConfig;
extern u8 data_ov010_0222be36[];
s32 t,k,idx,i; u8 n;
if(M2C_FIELD(&data_ov010_0222c960,s32*,0x20)==0)return 1;
if(M2C_FIELD(&data_ov010_0222c960,s32*,0xF08)==0){
t=Link_BuildNextPacket();M2C_FIELD(&data_ov010_0222c960,s32*,0xF08)=t;
if(t && M2C_FIELD(&data_ov010_0222c960,s32*,0x18)) t=0; else t=1; return t;
}
n=1;
if(M2C_FIELD(&gLinkConfig,s32*,0x10)==2){
idx=M2C_FIELD(&data_ov010_0222c960,s32*,0xF10)++;
n=(data_ov010_0222be36+M2C_FIELD(&data_ov010_0222c960,s32*,0xF14)*3)[idx];
}
i=0; goto test;
loop: {
u32 bits=M2C_FIELD(&data_ov010_0222c960,u32*,0xF0C);
k=__CLZ(bits);if(k==32)goto done;
M2C_FIELD(&data_ov010_0222c960,u32*,0xF0C)=bits&~(0x80000000U>>k);
func_020444cc((u8)(31-k),M2C_FIELD(&data_ov010_0222c960,s32*,0xF08),M2C_FIELD(&data_ov010_0222c960,s32*,12));
if(!M2C_FIELD(&data_ov010_0222c960,s32*,0xF0C)){
M2C_FIELD(&data_ov010_0222c960,s32*,0xF00)++;
M2C_FIELD(&data_ov010_0222c960,s32*,0xF08)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0xF0C)=0;
goto done;
}
}i++; test: if(i<n)goto loop; done: return 1;
}
void func_ov010_022232e0(void) {
    extern s32 data_ov010_0222d878;
    extern s32 data_ov010_0222d880[];
    s32 i;
    i = 0;
    M2C_FIELD(&data_ov010_0222d878, s32 *, 4) = 0;
    data_ov010_0222d878 = 0;
    do {
        data_ov010_0222d880[i] = 0;
        i++;
    } while (i < 3);
}

void func_ov010_02223314(s32 arg0) {
    void *func_ov010_02223440(s32);
    M2C_UNK func_ov010_02223478(void *);
    M2C_UNK Link_FreePacket();
    extern s32 data_ov010_0222d880[];
    void *item;
    item = func_ov010_02223440(arg0);
    if (item != NULL) {
        do {
            func_ov010_02223478(item);
            Link_FreePacket(item);
            item = func_ov010_02223440(arg0);
        } while (item != NULL);
    }
    data_ov010_0222d880[arg0] = 0;
}

void func_ov010_0222335c(void) {
M2C_UNK Link_FreePacket();
extern s32 data_ov010_0222d878;
extern s32 data_ov010_0222d880[];
void *p=(void *)data_ov010_0222d878;
s32 i;
while(p) { void *old=p; p=M2C_FIELD(p,void **,8); Link_FreePacket(old); }
for(i=0;i<3;i++) data_ov010_0222d880[i]=0;
}

s32 func_ov010_022233ac(void *a) {
extern s32 data_ov010_0222d878;
extern s32 data_ov010_0222d880[];
if(data_ov010_0222d878==0) {
data_ov010_0222d878=(s32)a;
M2C_FIELD(a,s32 *,4)=0;
M2C_FIELD((void *)data_ov010_0222d878,s32 *,8)=0;
M2C_FIELD(&data_ov010_0222d878,s32 *,4)=data_ov010_0222d878;
} else {
M2C_FIELD(a,s32 *,4)=M2C_FIELD(&data_ov010_0222d878,s32 *,4);
M2C_FIELD(a,s32 *,8)=0;
M2C_FIELD((void *)M2C_FIELD(&data_ov010_0222d878,s32 *,4),void **,8)=a;
M2C_FIELD(&data_ov010_0222d878,void **,4)=a;
}
data_ov010_0222d880[M2C_FIELD(a,u8 *,0x11)]++;
return data_ov010_0222d880[M2C_FIELD(a,u8 *,0x11)];
}

s32 func_ov010_02223420(void) {
    extern s32 data_ov010_0222d878;
    return data_ov010_0222d878;
}

s32 func_ov010_02223430(s32 arg0) {
    extern s32 data_ov010_0222d880[];
    return data_ov010_0222d880[arg0];
}

void *func_ov010_02223440(s32 a) {
extern s32 data_ov010_0222d878;
void *p=(void *)data_ov010_0222d878;
while(p) {
if(M2C_FIELD(p,u8 *,0x11)==a) return p;
p=M2C_FIELD(p,void **,8);
}
return NULL;
}

s32 func_ov010_02223478(void *a) {
extern s32 data_ov010_0222d878;
extern s32 data_ov010_0222d880[];
if(M2C_FIELD(a,void **,4)) M2C_FIELD(M2C_FIELD(a,void **,4),void **,8)=M2C_FIELD(a,void **,8);
else { void *p8=M2C_FIELD(a,void **,8);
data_ov010_0222d878=(s32)p8;
if(p8) M2C_FIELD(p8,s32 *,4)=0; }
if(M2C_FIELD(a,void **,8)) M2C_FIELD(M2C_FIELD(a,void **,8),void **,4)=M2C_FIELD(a,void **,4);
else { void *p4=M2C_FIELD(a,void **,4);
M2C_FIELD(&data_ov010_0222d878,s32 *,4)=(s32)p4;
if(p4) M2C_FIELD(p4,s32 *,8)=0; }
data_ov010_0222d880[M2C_FIELD(a,u8 *,0x11)]--;
return data_ov010_0222d880[M2C_FIELD(a,u8 *,0x11)];
}

void func_ov010_022234f8(u8 *out,s16 *in,u32 n) {
extern s32 data_ov010_0222c004[];
s32 seg,mask; u32 i; s32 sample,x,value; s32 *table;
for(i=0;i<n;i++) {
sample=in[i]; table=data_ov010_0222c004; x=sample>>2;
if(x<0) {mask=0x7f; x=-x;} else mask=0xff;
if(x>0x1fdf)x=0x1fdf;
for(seg=0;seg<8;seg++) if(x+33<=*table++)goto found;
seg=8;
found:
if(seg>=8)value=mask^0x7f;
else {value=(((x+33)>>(seg+1))&15)|(seg<<4);value^=mask;}
out[i]=value;
}
}

void func_ov010_022235a4(const u8 *src,s16 *dst,u32 count) { u32 i; for(i=0;i<count;i++) { s32 v=~src[i]; s32 magnitude=(((v&15)<<3)+132)<<((v&0x70)>>4); if(v&0x80) magnitude=132-magnitude; else magnitude-=132; dst[i]=magnitude; } }

void func_ov010_022235f8(s8 *out,s16 *in,u32 n) {
u32 i; for(i=0;i<n;i++) out[i]=in[i]>>8;
}

#pragma opt_strength_reduction off
s32 func_ov010_02223624(void *src,void *dst,s32 count){u32 i;for(i=0;i<(u32)count;i++)((s16 *)dst)[i]=((s8 *)src)[i]<<8;}
#pragma opt_strength_reduction reset
void func_ov010_02223654(s32 arg0) {
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32);
extern s32 gLinkQueueIrq; extern s32 gLinkQueueHead[]; extern s32 gLinkQueueCount[]; extern s32 gLinkQueueTail[];
s32 *a=gLinkQueueCount; s32 *b=gLinkQueueHead; s32 v=OS_DisableInterrupts();
gLinkQueueIrq=v;
gLinkQueueTail[arg0]=0; b[arg0]=0; a[arg0]=0;
OS_RestoreInterrupts(v);
}

void func_ov010_0222369c(s32 arg0) {
    void *Link_PeekPacket(s32);
    M2C_UNK Link_PopPacket(s32);
    M2C_UNK Link_FreePacket(void *);
    extern s32 gLinkQueueCount[];
    void *item;
    item = Link_PeekPacket(arg0);
    if (item != NULL) {
        do {
            Link_PopPacket(arg0);
            Link_FreePacket(item);
            item = Link_PeekPacket(arg0);
        } while (item != NULL);
    }
    gLinkQueueCount[arg0] = 0;
}

void func_ov010_022236e4(void) {
 s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);M2C_UNK Link_FreePacket(void *);
 extern s32 gLinkQueueIrq,gLinkQueueHead[],gLinkQueueCount[];
 s32 i;void *node;void *next;
 gLinkQueueIrq=OS_DisableInterrupts();
 i=0;goto check;
 loop: node=(void *)gLinkQueueHead[i];while(node){next=M2C_FIELD(node,void **,8);gLinkQueueHead[i]=(s32)next;if(next)M2C_FIELD(next,s32 *,4)=0;Link_FreePacket(node);node=(void *)gLinkQueueHead[i];}gLinkQueueCount[i]=0;i++;
 check:if(i<3)goto loop;
 OS_RestoreInterrupts(gLinkQueueIrq);
}

#pragma opt_common_subs off
/* Insert a link packet into a channel's packet queue, keeping the queue ordered
   ascending by the packet's key field.  Returns the new queue length, or -1 for
   a null packet or a channel outside 0..LINK_CHANNEL_COUNT-1. */
s32 Link_InsertPacket(void *packet, u8 channel){
s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);
extern s32 gLinkQueueHead[],gLinkQueueTail[],gLinkQueueCount[];
extern s32 gLinkQueueIrq;
void *node;
if(!packet)return -1;
if(channel>=3)return -1;
gLinkQueueIrq=OS_DisableInterrupts();
if(!gLinkQueueHead[channel]){
gLinkQueueHead[channel]=(s32)packet;
M2C_FIELD(packet,s32*,LINK_PACKET_PREV)=0;
M2C_FIELD((void*)gLinkQueueHead[channel],s32*,LINK_PACKET_NEXT)=0;
gLinkQueueTail[channel]=gLinkQueueHead[channel];
}else{
node=(void*)gLinkQueueTail[channel];
while(node){
if(M2C_FIELD(node,u32*,LINK_PACKET_KEY)<M2C_FIELD(packet,u32*,LINK_PACKET_KEY)){
M2C_FIELD(packet,s32*,LINK_PACKET_PREV)=(s32)node;
M2C_FIELD(packet,s32*,LINK_PACKET_NEXT)=M2C_FIELD(node,s32*,LINK_PACKET_NEXT);
M2C_FIELD(node,s32*,LINK_PACKET_NEXT)=(s32)packet;
if(M2C_FIELD(packet,s32*,LINK_PACKET_NEXT))M2C_FIELD((void*)M2C_FIELD(packet,s32*,LINK_PACKET_NEXT),s32*,LINK_PACKET_PREV)=(s32)packet;
if(node==(void*)gLinkQueueTail[channel])gLinkQueueTail[channel]=(s32)packet;
goto done;
}
node=(void*)M2C_FIELD(node,s32*,LINK_PACKET_PREV);
}
M2C_FIELD(packet,s32*,LINK_PACKET_PREV)=0;
M2C_FIELD(packet,s32*,LINK_PACKET_NEXT)=gLinkQueueHead[channel];
M2C_FIELD((void*)gLinkQueueHead[channel],s32*,LINK_PACKET_PREV)=(s32)packet;
gLinkQueueHead[channel]=(s32)packet;
}
done:
gLinkQueueCount[channel]++;
OS_RestoreInterrupts(gLinkQueueIrq);
return gLinkQueueCount[channel];
}
void *Link_PeekPacket(s32 arg0) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern s32 gLinkQueueIrq;
    extern s32 gLinkQueueHead[];
    gLinkQueueIrq = OS_DisableInterrupts();
    if (gLinkQueueHead[arg0] != 0) {
        OS_RestoreInterrupts(gLinkQueueIrq);
        return (void *)gLinkQueueHead[arg0];
    }
    OS_RestoreInterrupts(gLinkQueueIrq);
    return NULL;
}

s32 Link_PopPacket(s32 arg0) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern s32 gLinkQueueIrq;
    extern s32 gLinkQueueHead[];
    extern s32 gLinkQueueCount[];
    void *temp;
    gLinkQueueIrq = OS_DisableInterrupts();
    temp = (void *)gLinkQueueHead[arg0];
    if (temp != NULL) {
        void *next = M2C_FIELD(temp, void **, 8);
        gLinkQueueHead[arg0] = (s32)next;
        gLinkQueueCount[arg0] = gLinkQueueCount[arg0] - 1;
        if (next != NULL) {
            M2C_FIELD(next, s32 *, 4) = 0;
        }
    }
    OS_RestoreInterrupts(gLinkQueueIrq);
    return gLinkQueueCount[arg0];
}

s32 Link_GetQueueCount(s32 arg0) {
    extern s32 gLinkQueueCount[];
    return gLinkQueueCount[arg0];
}

void func_ov010_0222393c(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
    MI_CpuFill8(arg0, 0, 0x28);
    M2C_FIELD(arg0, s32 *, 4) = 0x134DF;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = arg1;
    M2C_FIELD(arg0, s32 *, 0x38) = arg2;
    M2C_FIELD(arg0, s32 *, 0x7C) = 0;
    M2C_FIELD(arg0, s32 *, 0x80) = 0;
    M2C_FIELD(arg0, s32 *, 0x84) = 0;
    M2C_FIELD(arg0, s32 *, 0x88) = 0;
    M2C_FIELD(arg0, s32 *, 0x8C) = 0x134DF;
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 1;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
}

void func_ov010_022239c8(void *arg0) {
    M2C_UNK Link_FreePacket();
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        Link_FreePacket();
        M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    }
    M2C_FIELD(arg0, s32 *, 0x38) = -1;
}

void Link_AdvancePacket(void *arg0, s32 arg1) {
    M2C_UNK Link_PopPacket(s32);
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        Link_FreePacket();
    }
    M2C_FIELD(arg0, s32 *, 0x3C) = arg1;
    Link_PopPacket(M2C_FIELD(arg0, s32 *, 0x34));
}

void Link_ResetChannelSequence(void *arg0, u32 arg1) {
    M2C_FIELD(arg0, s16 *, 0x68) = (s16)arg1;
    M2C_FIELD(arg0, s32 *, 0x64) = 0x10001;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
}

/* Keys an incoming link packet with its 32-bit sequence number: the wire carries
 * only the low 16 bits, so the channel's last sequence (+0x68) and its 0x10000
 * rollover accumulator (+0x60) extend it, and the result is stored as the
 * packet's ordering key (+0x18). A sequence just behind the last one is expected
 * after a gap (+0x64); anything else out of order returns 0 without keying. */
s32 Link_AssignPacketSequence(void *channel, void *packet, u32 seq) {
    u16 lastSeq;
    u16 delta;

    lastSeq = M2C_FIELD(channel, u16 *, 0x68);
    delta = (u16)(seq - lastSeq);
    if (delta < 0xBB8U) {
        if (seq < (u32)lastSeq) {
            M2C_FIELD(channel, s32 *, 0x60) = M2C_FIELD(channel, s32 *, 0x60) + 0x10000;
        }
        M2C_FIELD(channel, u16 *, 0x68) = (u16)seq;
    } else if (delta <= 0xFF9CU) {
        if (seq == M2C_FIELD(channel, s32 *, 0x64)) {
            Link_ResetChannelSequence(channel, seq);
            M2C_FIELD(channel, s32 *, 0x54) = (s32)(u16)(seq - 1);
        } else {
            M2C_FIELD(channel, s32 *, 0x64) = (s32)(u16)(seq + 1);
            return 0;
        }
    } else {
        u32 extendedSeq = seq + M2C_FIELD(channel, s32 *, 0x60);
        if (extendedSeq > (u32)(M2C_FIELD(channel, s32 *, 0x54) + 0xFF9C)) {
            M2C_FIELD(packet, s32 *, 0x18) = (s32)(extendedSeq - 0x10000);
            return 1;
        }
    }
    M2C_FIELD(packet, s32 *, 0x18) = (s32)(seq + M2C_FIELD(channel, s32 *, 0x60));
    return 1;
}

#pragma opt_propagation off
#pragma optimization_level 3
s32 func_ov010_02223b18(void *arg0, void *arg1) {
    u64 GetSystemTick(void);
    register void *channel = arg0;
    register void *packet = arg1;
    u32 seq, lastSeq;
    s32 drift;
    s32 reset = 0;
    u32 elapsed;
    s32 deviation, delay, window, margin, low, driftLimit, baseline, negativeLimit, tickDelta;
    u64 now;
    if (M2C_FIELD(channel, s32 *, 0x5c)) {
        Link_ResetChannelSequence(channel, (u16)M2C_FIELD(packet, u32 *, 0x18));
    } else {
        if (!Link_AssignPacketSequence(channel, packet, (u16)M2C_FIELD(packet, u32 *, 0x18))) {
            M2C_FIELD(channel, u32 *, 0x14)++;
            return reset;
        }
        M2C_FIELD(channel, u32 *, 0x10) = M2C_FIELD(packet, u32 *, 0x18);
        seq = M2C_FIELD(packet, u32 *, 0x18);
        lastSeq = M2C_FIELD(channel, u32 *, 0x54);
        if (lastSeq == seq) {
            M2C_FIELD(channel, u32 *, 0x14)++;
            return reset;
        }
        if (lastSeq + 1 != seq && !M2C_FIELD(packet, s32 *, 0x45c)) {
            s32 gap = seq - lastSeq;
            if (gap < 0) gap = -gap;
            if (gap > 100) {
                M2C_FIELD(channel, u32 *, 0x54) = seq;
                return 0;
            }
            if (lastSeq > seq) M2C_FIELD(channel, u32 *, 0x1c)++;
        }
    }
    M2C_FIELD(channel, u32 *, 0x54) = M2C_FIELD(packet, u32 *, 0x18);
    if (M2C_FIELD(channel, u32 *, 0x4c) == 0) {
        M2C_FIELD(channel, u32 *, 0x4c) = M2C_FIELD(packet, u32 *, 0x460);
        M2C_FIELD(channel, u64 *, 0x44) = M2C_FIELD(packet, u64 *, 0x464);
        M2C_FIELD(channel, u32 *, 0x6c) = 0;
    }
    elapsed = (M2C_FIELD(packet, u32 *, 0x460) - M2C_FIELD(channel, u32 *, 0x4c)) << 6;
    tickDelta = M2C_FIELD(packet, u32 *, 0x464) - M2C_FIELD(channel, u32 *, 0x44);
    drift = elapsed - tickDelta;
    baseline = M2C_FIELD(channel, s32 *, 0x80);
    if (baseline != 0) {
        if (M2C_FIELD(packet, s32 *, 0x45c)) {
            M2C_FIELD(channel, s32 *, 0x80) = drift;
            goto timestamp;
        }
    } else {
        M2C_FIELD(channel, s32 *, 0x80) = drift;
    }
    deviation = drift - baseline;
    if (deviation < 0) deviation = -deviation;
    if ((u64)(s64)deviation > (u64)(s64)((M2C_FIELD(channel, s32 *, 0x7c) + 35608) * 2) + 52365) {
        M2C_FIELD(channel, s32 *, 0x84) = deviation / 35608 + 2;
    }
    if (M2C_FIELD(channel, s32 *, 0x84) <= 0) {
        delay = M2C_FIELD(channel, s32 *, 0x7c);
        delay += (deviation - delay) >> 4;
        M2C_FIELD(channel, s32 *, 0x7c) = delay;
        M2C_FIELD(channel, s32 *, 0x18) = delay;
    }
timestamp:
    M2C_FIELD(packet, u64 *, 0x46c) = elapsed + M2C_FIELD(channel, u64 *, 0x44) + M2C_FIELD(channel, u32 *, 4);
    now = GetSystemTick();
    if (M2C_FIELD(packet, u64 *, 0x46c) + 35608 < now) return 0;
    if (M2C_FIELD(packet, u64 *, 0x46c) > now + 523656) return 0;
    if (M2C_FIELD(channel, s32 *, 0x84) <= 0) {
        margin = M2C_FIELD(channel, s32 *, 0x7c) * 3;
        window = margin / 35608;
        if ((u32)margin > M2C_FIELD(channel, u32 *, 0x8c)) {
            M2C_FIELD(channel, s32 *, 0x8c) = (window + 1) * 35608 + 79071;
            M2C_FIELD(channel, s32 *, 0x88) = M2C_FIELD(channel, s32 *, 0x8c) - 53412;
            M2C_FIELD(channel, u32 *, 4) = window * 35608 + 79071;
            M2C_FIELD(channel, u32 *, 0x90) = 0;
        } else if (margin < M2C_FIELD(channel, s32 *, 0x88)) {
            M2C_FIELD(channel, u32 *, 0x90)++;
            if (M2C_FIELD(channel, u32 *, 0x90) > 70) {
                M2C_FIELD(channel, s32 *, 0x8c) = (window + 1) * 35608 + 79071;
                low = window * 35608 - 17804;
                M2C_FIELD(channel, s32 *, 0x88) = low;
                if (low < 0) M2C_FIELD(channel, s32 *, 0x88) = 0;
                M2C_FIELD(channel, u32 *, 4) = window * 35608 + 79071;
                M2C_FIELD(channel, u32 *, 0x90) = 0;
            }
        }
        if (M2C_FIELD(channel, u32 *, 4) > 427296) M2C_FIELD(channel, u32 *, 4) = 427296;
        if (M2C_FIELD(channel, u32 *, 0x6c) < 16) {
            M2C_FIELD(channel, u32 *, 0x6c)++;
            M2C_FIELD(channel, s32 *, 0x74) = drift;
            M2C_FIELD(channel, s32 *, 0x78) = drift;
        } else {
            M2C_FIELD(channel, s32 *, 0x74) = (drift + M2C_FIELD(channel, s32 *, 0x74) * 31) / 32;
        }
        driftLimit = M2C_FIELD(channel, s32 *, 0x78) - M2C_FIELD(channel, s32 *, 0x74);
        M2C_FIELD(channel, s32 *, 0xc) = driftLimit;
        negativeLimit = -0x8701;
        if (driftLimit > 0x8701) reset = 1;
        if (driftLimit < negativeLimit) {
            reset = negativeLimit + 0x8700;
            M2C_FIELD(channel, u32 *, 0x70)++;
        }
        if (reset) {
            M2C_FIELD(channel, u32 *, 0x6c) = 0;
            M2C_FIELD(channel, u32 *, 0x4c) = 0;
        }
    }
    M2C_FIELD(channel, s32 *, 0x84)--;
    return 1;
}
#pragma opt_propagation reset
#pragma optimization_level reset
s32 func_ov010_02223ec8(s32 a) {
s32 VoiceLink_AllocContext(s32);
extern s32 gLinkConfig;
s32 state=M2C_FIELD(&gLinkConfig,s32 *,0x10);
if(state==0 || state==2) return 0;
return VoiceLink_AllocContext(a);
}

/* Release a voice-chat context: clear its valid flag and put it back at the head
 * of the link state's free list (unlinking it from the active list), or in the
 * link's single-context mode only clear the global context's session state. */
s32 VoiceLink_ReleaseContext(VoiceLinkContext *context) {
    extern M2C_UNK gVoiceLinkState;
    extern M2C_UNK gVoiceLinkContext;
    extern M2C_UNK gLinkConfig;
    VoiceLinkContext *prev;
    VoiceLinkContext *ctx;

    prev = NULL;
    ctx = ((VoiceLinkState *)&gVoiceLinkState)->activeList;
    if (context == NULL) {
        return 0;
    }
    if (M2C_FIELD(&gLinkConfig, s32 *, LINK_CONFIG_MODE) == 2) {
        if (context == (VoiceLinkContext *)&gVoiceLinkContext) {
            ((VoiceLinkState *)&gVoiceLinkState)->sessionState = 0;
        }
        return 1;
    }
    while (ctx != NULL) {
        if (ctx == context) {
            VoiceLinkContext *next;
            context->valid = 0;
            if (prev != NULL) {
                prev->next = context->next;
            } else {
                next = ctx->next;
                if (next != NULL) {
                    ((VoiceLinkState *)&gVoiceLinkState)->activeList = next;
                } else {
                    ((VoiceLinkState *)&gVoiceLinkState)->activeList = NULL;
                }
            }
            context->next = ((VoiceLinkState *)&gVoiceLinkState)->freeList;
            ((VoiceLinkState *)&gVoiceLinkState)->freeList = context;
            return 1;
        }
        prev = ctx;
        ctx = ctx->next;
    }
    return 0;
}

/* Build one control packet (kind 0xFF) for a voice-link protocol step: check the
 * context and the buffer, write the packet header for `step` and check that step
 * against the protocol table.  In link mode 1 starting an exchange is refused
 * while another context is still waiting.  Returns 0 on success, -1 for a bad
 * argument and -3 when the link refuses the step. */
s32 VoiceLink_BuildControlPacket(void *context, s32 step, void *packet, u32 size) {
    M2C_UNK VoiceLink_InitPacket(void *, void *, u8);
    s32 VoiceLink_NoOtherContextWaiting(void *);
    s32 VoiceLink_CheckStartStep(void *, void *);
    extern M2C_UNK gLinkConfig;

    if (context == NULL) {
        return -1;
    }
    if (size < 0x10) {
        return -1;
    }
    if (M2C_FIELD(&gLinkConfig, s32 *, LINK_CONFIG_CONTROL) == 1) {
        return -3;
    }
    if ((step < 0) || (step >= 5)) {
        return -3;
    }
    ((VoiceLinkPacket *)packet)->kind = 0xFF;
    VoiceLink_InitPacket(context, packet, (u8) step);
    if (VoiceLink_CheckStartStep(context, packet) == 0) {
        return -3;
    }
    if ((M2C_FIELD(&gLinkConfig, s32 *, LINK_CONFIG_MODE) == 1) && (step == 0)) {
        if (VoiceLink_NoOtherContextWaiting(context) == 0) {
            return -3;
        }
    }
    return 0;
}

s32 func_ov010_0222405c(s32 arg0, s32 arg1) {
    s32 func_ov010_0222441c(s32, s32);
    extern M2C_UNK gLinkConfig;
    if (M2C_FIELD(&gLinkConfig, s32 *, 0x10) == 2) return -3;
    return func_ov010_0222441c(arg0, arg1);
}

