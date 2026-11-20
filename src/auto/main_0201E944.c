/* 35 functions from 0x0201E944 to 0x0201F89C (main), found by ds-decomp. */
#include "common.h"
#include "net_socket.h"
/* DNS wire format kinds, as used by the resolver in this file. */
#define DNS_MAX_NAME        60  /* longest name a query packet holds (name + length bytes) */
#define DNS_HEADER_BYTES    12  /* id, flags, question count, answer count */
#define DNS_QUESTION_CLASS  0x0100 /* u16 class (0x0100 swaps to IN on the wire) */
#define DNS_ANSWER_ADDRESS  1   /* answer type of an A record */
#define DNS_ANSWER_MX       12  /* answer type of an MX record: the host name it points at */
#define DNS_ANSWER_TYPE_MASK 0x0F /* flags byte low nibble: response type */
#define DNS_ANSWER_NXDOMAIN 3   /* flags byte: the name does not exist */
typedef struct DnsPacket0201e944 { u16 header[6]; u8 name[48]; } DnsPacket0201e944;
static inline u64 NextPacketRandom64(void) {
    extern M2C_UNK gNetStack;
    M2C_FIELD(&gNetStack, u64 *, 0x68) = M2C_FIELD(&gNetStack, u64 *, 0x70) * M2C_FIELD(&gNetStack, u64 *, 0x68) + M2C_FIELD(&gNetStack, u64 *, 0x78);
    return M2C_FIELD(&gNetStack, u64 *, 0x68);
}

#pragma push
#pragma opt_strength_reduction off
/* Sends a DNS query for host name `host` (type 1, or an MX lookup when the type is
   DNS_ANSWER_MX) and waits up to 15 ticks for the single answer.  An address is
   copied to out (result 1); an MX answer leaves its two name offsets in result
   (high, low half) when outLen is 0, or fails with 2 when the name does not fit in
   outLen bytes.  A "name does not exist" answer gives -1, a timeout 0. */
s32 DnsResolveName(M2C_UNK a,s32 b,M2C_UNK c,s32 d,u32 e) {
void SendNetPacket(void*,s32); s32 func_0201dbb8(void); void func_0201a238(void); u8 *func_0201d618(u32*); void func_0201d70c(u32); u8 *DnsSkipName(u8*); u64 GetSystemTick(void); void MI_CpuCopy8(void*,void*,u32);
extern M2C_UNK gNetStack;
u8 qname[48]; u16 packet[6]; u32 size; u8 *name=(u8*)a; s32 result; u32 start;u8 *label,*p,*end; s32 n; u8 ch; s32 questions; u16 len,type,v1,v2;
packet[0]=(c>>8)|(c<<8);if(b!=32)packet[1]=1;else packet[1]=0x1001;packet[2]=DNS_QUESTION_CLASS;packet[3]=0;label=qname;p=label;packet[4]=0;packet[5]=0;
size=0;++p;
ch=*name++;if(ch){n=size;
do{
if(ch!='.'){if(p-(u8*)packet>=DNS_MAX_NAME)return -1;n=++size;*p++=ch;}
else{*label=n;label=p++;size=0;n=0;}
ch=*name++;
}while(ch);
}
*label=size;p[0]=0;p[1]=(u32)b>>8;p[2]=b;p[3]=0;p[4]=1;
SendNetPacket(packet,p+5-(u8*)packet);
result=0;start=(u32)(GetSystemTick()>>16);
while(M2C_FIELD(&gNetStack,s32 (**)(void),0x48)()!=0 && result==0 && (s32)((u32)(GetSystemTick()>>16)-start)<15){
if(!func_0201dbb8()){func_0201a238();continue;}
p=func_0201d618(&size);
if(size>12 && c==(u16)((M2C_FIELD(p,u16*,0)>>8)|(M2C_FIELD(p,u16*,0)<<8))){
type=p[3]&DNS_ANSWER_TYPE_MASK;
if(type==DNS_ANSWER_NXDOMAIN)result=-1;
else if(type==0){
end=p+size;questions=(u16)((p[4]<<8)|p[5]);p+=DNS_HEADER_BYTES;
while(questions--!=0){p=DnsSkipName(p)+4;}
while(p<end){
p=DnsSkipName(p);len=(u16)((p[8]<<8)|p[9]);type=(u16)((p[0]<<8)|p[1]);
if(b==type){
if(b!=DNS_ANSWER_MX){label=p+8;p+=6;v1=(u16)((p[len]<<8)|p[len+1]);v2=(u16)((label[len]<<8)|label[len+1]);result=(v1<<16)|v2;}
else if(len>e)result=2;
else{MI_CpuCopy8(p+10,(void*)d,len);result=1;}
break;
}
p+=len+10;
}
}
}
func_0201d70c(size);
}
return result;
}
#pragma pop
s32 ParseDecimal(u8 *arg0, u8 **arg1) {
#pragma opt_propagation on
#pragma opt_common_subs on
    s32 var_ip;
    u8 *var_r0;
    u8 temp_r3;

    var_r0 = arg0;
    *arg1 = var_r0;
    var_ip = 0;
loop_1:
    temp_r3 = *var_r0 - 0x30;
    if ((u32) temp_r3 <= 9U) {
        var_ip = (0xA * var_ip) + temp_r3;
        var_r0 += 1;
        *arg1 = var_r0;
        goto loop_1;
    }
    return var_ip;
}

/* Parses a dotted-decimal IPv4 address ("a.b.c.d", each part 0..255) and stores
 * its packed big-endian address; returns 1, or 0 when the text is not a complete
 * address. */
s32 ParseIpAddress(u8 *text, s32 *address) {
    u8 *end;
    s32 value = 0;
    s32 octet = 0;
    u32 part;
    for (; octet < 4; octet++) {
        part = ParseDecimal(text, &end);
        if (text == end) return 0;
        text = end;
        if (part > 255 || (octet != 3 && *text++ != '.') || (octet == 3 && *text != 0)) return 0;
        value = part | (value << 8);
    }
    *address = value;
    return 1;
}

s32 func_0201ecbc(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK func_0201d164();
    M2C_UNK SetConnectionEndpoint(M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_0201d1f0();
    M2C_UNK func_0201d224();
    s32 DnsResolveName();
    s32 result;
    if (arg1 == 0) return -1;
    func_0201d1f0();
    func_0201d164();
    SetConnectionEndpoint(0, 0x35, arg1);
    result = DnsResolveName(arg0, 1, arg2, 0, 0);
    func_0201d224();
    return result;
}

#pragma push
#pragma opt_strength_reduction off
#pragma peephole off
s32 DnsLookupAddress(s32 arg0) {
extern M2C_UNK data_021372f0;
extern M2C_UNK gNetStack;
u8 flags[2]; s32 out; u16 rnd[2];
u64 state, mul, inc; s32 i,j; u8 *p;
state=M2C_FIELD(&gNetStack,u64*,0x68);
mul=M2C_FIELD(&gNetStack,u64*,0x70);
inc=M2C_FIELD(&gNetStack,u64*,0x78);
state*=mul;
state+=inc;
M2C_FIELD(&gNetStack,u32*,0x68)=(u32)state;
M2C_FIELD(&gNetStack,u32*,0x6c)=state>>32;
rnd[0]=((u64)(u32)(state>>32)<<16)>>32;
state*=mul;
state+=inc;
M2C_FIELD(&gNetStack,u32*,0x68)=(u32)state;
M2C_FIELD(&gNetStack,u32*,0x6c)=state>>32;
rnd[1]=((u64)(u32)(state>>32)<<16)>>32;
if(ParseIpAddress((u8*)arg0,&out)) return out;
flags[0]=1; flags[1]=1;
for(i=0;i<3;i++){
for(j=0,p=flags;j<2;j++,p++){
if(*p){
out=func_0201ecbc(arg0,M2C_FIELD(&data_021372f0,s32*,j*4),rnd[j]);
if(out!=0 && out!=-1) goto done;
if(out==-1)*p=0;
}
}}
done:
if(out==-1)out=0;
return out;
}
#pragma pop
s32 func_0201ee58(s32 arg0) {
    M2C_UNK func_02000b9c(s32);
    s32 func_0201ee94();
    void func_0201eed4(void);
    extern s32 gNetAllocator;
    func_02000b9c(0x02000BF4);
    if (gNetAllocator != 0) {
        return 0;
    }
    gNetAllocator = arg0;
    func_0201eed4();
    return func_0201ee94();
}

s32 func_0201ee94(void) {
    s32 NetworkAllocTaskPool(s32);
    s32 SocketCreateFromConfig();
    extern s32 gNetAllocator;
    extern M2C_UNK data_020fafd0;
    extern M2C_UNK data_02138ac0;
    s32 result;
    result = NetworkAllocTaskPool(M2C_FIELD(gNetAllocator, s32 *, 0x20));
    if (result >= 0) {
        M2C_FIELD(&data_02138ac0, s32 *, 0xC) = SocketCreateFromConfig(&data_020fafd0);
    }
    return result;
}

void func_0201eed4(void) {
    void func_02007f8c(void *, s32, s32);
    void func_0201a4f8(s32);
    void func_0201a550(s32);
    void func_0201f030(void);
    void func_0201f09c(void);
    void func_02029828(s32);
    void func_0201a26c(void *);
    void func_0201aa74(s32, s32, s32, s32);
    s32 func_02020f30(void);
    s32 func_0201f0b4(void);
    extern s32 data_020faf98;
    extern s32 data_02138ad0;
    extern s32 data_02138ac0;
    extern s32 data_020fafb8;
    extern s32 data_021372e0;
    void *base;
    void *ctx;
    s32 tmp;
    base = (void *)&data_02138ad0;
    ctx = (void *)data_020faf98;
    func_02007f8c(base, 0, 0x30);
    M2C_FIELD(&data_02138ac0, s32 *, 0x14) = M2C_FIELD(ctx, s32 *, 0x18);
    M2C_FIELD(&data_02138ac0, s32 *, 0x18) = M2C_FIELD(ctx, s32 *, 0x1C);
    M2C_FIELD(&data_02138ac0, s32 *, 0x20) = (s32)func_0201f0b4;
    M2C_FIELD(&data_02138ac0, s32 *, 0x24) = 0;
    M2C_FIELD(&data_02138ac0, s32 *, 0x28) = 0;
    M2C_FIELD(&data_02138ac0, s32 *, 0x3C) = M2C_FIELD(&data_02138ac0, s32 *, 0x0);
    tmp = M2C_FIELD(ctx, s32 *, 0x24);
    if (tmp == 0) tmp = 0x4000;
    M2C_FIELD(base, s32 *, 0x20) = tmp;
    if (M2C_FIELD(ctx, s32 *, 0x28) == 0) {
        M2C_FIELD(base, s32 *, 0x1C) = ((s32 (*)(s32))M2C_FIELD(ctx, s32 *, 0x18))(M2C_FIELD(base, s32 *, 0x20));
    }
    {
        s32 v30 = M2C_FIELD(ctx, s32 *, 0x30);
        s32 lr = M2C_FIELD(ctx, s32 *, 0x34);
        s32 r12;
        if (v30 == 0) v30 = 0x240;
        r12 = v30 - 0x28;
        if (lr == 0) lr = 0x10C0;
        M2C_FIELD(&data_020fafb8, s16 *, 0x2) = (s16)lr;
        M2C_FIELD(&data_020fafb8, s16 *, 0x4) = (s16)((lr + (lr >> 31)) >> 1);
        M2C_FIELD(base, s32 *, 0x24) = r12;
        M2C_FIELD(&data_021372e0, s32 *, 0x0) = 0;
        if (M2C_FIELD(ctx, s32 *, 0x0) != 0) {
            M2C_FIELD(base, s32 *, 0x0) = 0;
            M2C_FIELD(base, s32 *, 0xC) = (s32)func_0201f09c;
            M2C_FIELD(&data_02138ac0, s32 *, 0x8) = 1;
            M2C_FIELD(base, s32 *, 0x28) = M2C_FIELD(&data_02138ac0, s32 *, 0x4);
        } else {
            M2C_FIELD(&data_02138ac0, s32 *, 0x8) = 0;
            M2C_FIELD(base, s32 *, 0x0) = 1;
            M2C_FIELD(base, s32 *, 0xC) = (s32)func_0201f030;
        }
    }
    {
        s32 r0v = M2C_FIELD(ctx, s32 *, 0x2C);
        if (r0v == 0) r0v = 0xB;
        func_0201a550(r0v);
    }
    func_02029828((s32)func_0201aa74);
    func_0201a4f8((s32)func_02020f30);
    func_0201a26c(base);
}

#pragma opt_strength_reduction off
void func_0201f030(void) {
    extern s32 gNetAllocator;
    extern s32 gLocalIpAddress, data_021372ac, data_021372bc;
    extern M2C_UNK data_021372f0;
    extern M2C_UNK data_02138ac0;
    s32 *src;
    s32 *dst;
    src = (s32 *)gNetAllocator;
    dst = &gLocalIpAddress;
    *dst = src[1];
    dst = &data_021372ac;
    *dst = src[2];
    dst = &data_021372bc;
    *dst = src[3];
    dst = (s32 *)&data_021372f0;
    dst[0] = src[4];
    dst[1] = src[5];
    dst = (s32 *)&data_02138ac0;
    dst[2] |= 2;
}
#pragma opt_strength_reduction reset
void func_0201f09c(void) {
    extern M2C_UNK data_02138ac0;
    M2C_FIELD(&data_02138ac0, s32 *, 8) = (s32) (M2C_FIELD(&data_02138ac0, s32 *, 8) | 2);
}

s32 func_0201f0b4(void) {
    s32 func_02029784();
    if (func_02029784() != 0) {
        return 1;
    }
    return 0;
}

/* Create the socket task pool: allocate one block holding `count` message-queue
 * words followed by `count` TASK_BYTES task slots, initialise the free-task
 * queue over the block with room for `count` tasks, post every task slot to it,
 * and keep the block in gSocketTaskPool.
 * Returns 0, or -1 when the net allocator fails. */
s32 NetworkAllocTaskPool(s32 count) {
    void SocketFreeTask(s32);
    M2C_UNK OS_InitMessageQueue(s32, s32, s32);
    extern s32 gNetAllocator;
    extern M2C_UNK gSocketTaskPool, gSocketTaskQueue;
    s32 queueBytes;
    s32 block;
    s32 remaining;
    s32 task;
    s32 taskBytes;

    remaining = count;
    queueBytes = ((remaining * 4) + 3) & ~3;
    taskBytes = ((remaining * TASK_BYTES) + 3) & ~3;
    block = M2C_FIELD(gNetAllocator, s32 (**)(s32), NET_ALLOC_ALLOC)(taskBytes + queueBytes);
    if (block == 0) return -1;
    OS_InitMessageQueue((s32) &gSocketTaskQueue, block, remaining);
    task = block + queueBytes;
    if (remaining > 0) {
        do {
            SocketFreeTask(task);
            remaining -= 1;
            task += TASK_BYTES;
        } while (remaining > 0);
    }
    M2C_FIELD(&gSocketTaskPool, s32 *, 0) = block;
    return 0;
}

s32 NetworkFreeTaskPool(void) {
    extern s32 gNetAllocator;
    extern M2C_UNK gSocketTaskPool;
    if (M2C_FIELD(&gSocketTaskPool, s32 *, 0x20) < M2C_FIELD(&gSocketTaskPool, s32 *, 0x18)) return -1;
    M2C_FIELD(gNetAllocator, void (**)(s32), 0x1C)(M2C_FIELD(&gSocketTaskPool, s32 *, 0));
    M2C_FIELD(&gSocketTaskPool, s32 *, 0) = 0;
    return 0;
}

s32 func_0201f1a8(s32 arg0) {
    s32 OS_ReceiveMessage(M2C_UNK *, s32 *, s32);
    extern M2C_UNK gSocketTaskQueue;
    s32 result;
    if (OS_ReceiveMessage(&gSocketTaskQueue, &result, arg0) != 0) return result;
    return 0;
}

s32 SocketAllocTask(M2C_UNK *arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_r0 = func_0201f1a8(arg2);
    if (temp_r0 == 0) return temp_r0;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = arg0;
    M2C_FIELD(temp_r0, s32 *, 4) = arg1;
    M2C_FIELD(temp_r0, s32 *, 8) = 0;
    M2C_FIELD(temp_r0, s8 *, 0xC) = M2C_FIELD(arg1, s8 *, 0x73);
    M2C_FIELD(temp_r0, s8 *, 0xD) = arg2;
    return temp_r0;
}

void SocketFreeTask(s32 arg0) {
    M2C_UNK OS_SendMessage(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK gSocketTaskQueue;
    if (arg0 == 0) {
        return;
    }
    OS_SendMessage(&gSocketTaskQueue, arg0, 0);
}

s32 func_0201f230(void *arg0) {
    s32 var_r1;

    var_r1 = M2C_FIELD(arg0, s32 *, 0x64);
    if (var_r1 == 0) {
        var_r1 = M2C_FIELD(arg0, s32 *, 0x68);
    }
    return var_r1;
}

s32 SocketQueueTask(M2C_UNK arg0, void *arg1) {
    M2C_UNK var_r2;
    s32 temp_r0;

    if ((arg1 == NULL) || (M2C_FIELD(arg1, s8 *, 0xD) & 1)) {
        var_r2 = 1;
    } else {
        var_r2 = 0;
    }
    temp_r0 = OS_SendMessage(arg0, arg1, var_r2);
    if (temp_r0 == 0) {
        SocketFreeTask(arg1);
    }
    if (temp_r0 != 0) {
        return 0;
    }
    return -0x2A;
}

s32 SocketSubmitTask(void *arg0, void *arg1) {
    return SocketQueueTask(func_0201f230(arg0), arg1);
}

s32 func_0201f2a8(arg0, arg1)
s32 arg0;
void *arg1;
{
    M2C_UNK OS_InitMessageQueue(s32, s32, s32);
    s32 OS_ReceiveMessage(M2C_UNK *, s32 *, s32);
    u8 queue[0x20];
    s32 result;
    s32 message;
    if (M2C_FIELD(arg1, s8 *, 0xD) == 1) {
        OS_InitMessageQueue((s32)queue, (s32)&message, 1);
        M2C_FIELD(arg1, void **, 8) = queue;
        SocketQueueTask(arg0, arg1);
        OS_ReceiveMessage((M2C_UNK *)queue, &result, 1);
    } else {
        M2C_FIELD(arg1, void **, 8) = NULL;
        result = SocketQueueTask(arg0, arg1);
    }
    return result;
}

void func_0201f318(void *arg0) {
    M2C_UNK func_0201f2a8();
    func_0201f2a8(M2C_FIELD(arg0, s32 *, 0x64));
}

void SocketSubmitSendTask(void *arg0) {
    func_0201f2a8(M2C_FIELD(arg0, s32 *, 0x68));
}

s32 func_0201f338(s32 arg0, s32 arg1) {
    s32 func_0201f2a8();
    return func_0201f2a8(func_0201f230(arg0), arg1);
}

void func_0201f350(s32 arg0) { s32 p,old,v; loop: OS_ReadMessage(arg0,&p,1); if(!p)goto done; v=M2C_FIELD(p,s32 (**)(s32),0)(p);
old=OS_DisableInterrupts();
OS_DisableScheduler();
OS_ReceiveMessage(arg0,0,0);
if(M2C_FIELD(p,s32*,4))M2C_FIELD(M2C_FIELD(p,s32*,4),s32*,0x6c)=v;
if(M2C_FIELD(p,s32*,8))OS_SendMessage(M2C_FIELD(p,s32*,8),v,0);
SocketFreeTask(p);OS_EnableScheduler();OS_RestoreInterrupts(old); goto loop; done: return; }

s32 SocketCreateFromConfig(void) {
    s32 SocketAllocTask(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_0201f338(s32, s32);
    s32 func_0201f4b0();
    extern M2C_UNK func_0201f43c;
    s32 temp_r0;

    temp_r0 = func_0201f4b0();
    if (temp_r0 == 0) {
        return -0x31;
    }
    func_0201f338(temp_r0, SocketAllocTask(&func_0201f43c, temp_r0, 1));
    return temp_r0;
}

s32 func_0201f43c(void *arg0) {
M2C_UNK SetCurrentRawConnection(void *);
M2C_UNK func_0201d164();
M2C_UNK func_0201d1f0();
M2C_UNK func_0201d244(s32);
M2C_UNK SocketSetReceiveCallback(M2C_UNK *);
extern M2C_UNK SocketQueueReceivedData;
void *p=M2C_FIELD(arg0,void**,4);
s32 v;
SetCurrentRawConnection(p);
v=M2C_FIELD(p,s32*,0x68);
switch(M2C_FIELD(p,s8*,0x73)){
case 0:case 4:func_0201d244(v+0x20);func_0201d1f0();break;
case 1:func_0201d1f0();func_0201d164();SocketSetReceiveCallback(&SocketQueueReceivedData);break;
case 2:func_0201d164();break;
}
M2C_FIELD(p,s16*,0x70)=1;return 0;
}

s32 func_0201f4b0(arg0)
void *arg0;
{
extern s32 gNetAllocator;
s32 p,old,size;
size=GetSocketConfigSize(arg0);
old=OS_DisableInterrupts();
p=M2C_FIELD(gNetAllocator,s32 (**)(s32),0x18)(size);
if(p){MI_CpuFill8(p,0,size);func_0201f5c0(p,arg0);func_020213f0(p);}
OS_RestoreInterrupts(old);return p;
}

/* Bytes of the socket object SocketCreateFromConfig allocates for a socket
 * config template: a fixed header plus, for each enabled direction, the
 * connection header, its buffer sizes and its task's queue and stack. */
s32 GetSocketConfigSize(SocketConfigTemplate *config) {
    s32 AlignSize4(s32);
    s32 GetSocketTaskBlockSize(void *);
    s32 size = 0x80;
    u32 bytes;
    bytes = config->rxBytes;
    if (bytes) {
        size += 0x114;
        size += AlignSize4(bytes);
        size += AlignSize4(config->rxPendingBytes);
        size += GetSocketTaskBlockSize(&config->rxTask);
    }
    bytes = config->txBytes;
    if (bytes) {
        size += 0x110;
        size += AlignSize4(bytes);
        size += AlignSize4(config->txBytes2);
        size += AlignSize4(config->txRingBytes);
        size += GetSocketTaskBlockSize(&config->txTask);
    }
    return size;
}

s32 GetSocketTaskBlockSize(void *arg0) {
    s32 temp_r4;

    temp_r4 = AlignSize4(M2C_FIELD(arg0, u8 *, 3) * 4);
    return temp_r4 + AlignSize4(M2C_FIELD(arg0, u16 *, 0));
}

/* Duplicate the sprite/frame data referenced by `src` into `dst`, advancing the cursor. */
s32 func_0201f5c0(void *dst, void *src) {
    extern void *gClosingSocket;
    void *p;
    void *q;
    void *r0;
    void *cur;

    cur = dst + 0x80;
    M2C_FIELD(dst, s8 *, 0x73) = M2C_FIELD(src, s8 *, 0);
    M2C_FIELD(dst, s8 *, 0x72) = M2C_FIELD(src, s8 *, 1);

    if (M2C_FIELD(src, u16 *, 2) != 0) {
        M2C_FIELD(dst, void **, 0x64) = cur;
        M2C_FIELD(cur, u16 *, 0xFC) = M2C_FIELD(src, u16 *, 4);
        p = cur;
        r0 = (void *)func_0201f6bc(func_0201f6bc(func_0201f6e4((s32)(cur + 0x114), (s32)cur, src + 0x10), dst + 0x3C, M2C_FIELD(src, u16 *, 2)), dst + 0x50, M2C_FIELD(src, u16 *, 8));
        cur = r0;
        M2C_FIELD(p + 0x100, u16 *, 0x0A) = M2C_FIELD(src, u16 *, 0x0E);
        M2C_FIELD(p, s32 *, 0x110) = 0;
        M2C_FIELD(p, s32 *, 0x10C) = 0;
    }

    if (M2C_FIELD(src, u16 *, 6) != 0) {
        M2C_FIELD(dst, void **, 0x68) = cur;
        q = cur;
        M2C_FIELD(cur, void **, 0x10C) = dst;
        r0 = (void *)func_0201f6bc(func_0201f6bc(func_0201f6bc(func_0201f6e4((s32)(cur + 0x110), (s32)cur, src + 0x14), dst + 0x48, M2C_FIELD(src, u16 *, 6)), dst + 0x58, M2C_FIELD(src, u16 *, 0x0A)), cur + 0xF8, M2C_FIELD(src, u16 *, 0x0C));
        cur = r0;
        M2C_FIELD(q, s32 *, 0x108) = 0;
        M2C_FIELD(q, s32 *, 0x104) = 0;
    } else {
        M2C_FIELD(dst, void **, 0x68) = M2C_FIELD(gClosingSocket, void **, 0x68);
    }

    return (s32)cur;
}

s32 func_0201f6bc(s32 arg0, void *arg1, s32 arg2) {
    s32 temp_r4;
    s32 var_r0;

    var_r0 = arg0;
    temp_r4 = var_r0;
    if (arg2 == 0) {
        var_r0 = 0;
    }
    M2C_FIELD(arg1, s32 *, 4) = var_r0;
    M2C_FIELD(arg1, s32 *, 0) = arg2;
    return temp_r4 + AlignSize4(arg2);
}

s32 func_0201f6e4(s32 arg0, s32 arg1, void *arg2) {
    M2C_UNK TaskCreate(s32, M2C_UNK *, s32, s32, s32, s32);
    M2C_UNK TaskWake(s32);
    M2C_UNK OS_InitMessageQueue(s32, s32, s32);
    M2C_UNK InitMutex(s32);
    s32 GetSocketTaskBlockSize(void *);
    void func_0201f350();
    s32 temp_r4;

    temp_r4 = GetSocketTaskBlockSize(arg2);
    OS_InitMessageQueue(arg1, arg0, M2C_FIELD(arg2, u8 *, 3));
    InitMutex(arg1 + 0xE0);
    TaskCreate(arg1 + 0x20, (M2C_UNK *)&func_0201f350, arg1, arg0 + temp_r4, (s32) M2C_FIELD(arg2, u16 *, 0), (s32) M2C_FIELD(arg2, u8 *, 2));
    TaskWake(arg1 + 0x20);
    return arg0 + temp_r4;
}

/* Check a socket is usable: the stack is registered, the socket is initialised,
 * no task is running on it, it is in a duplex state and it may block. Returns 0
 * when usable, otherwise the socket error that rejected it. */
s32 SocketCheckReady(void *sock) {
s32 SocketIsUnregistered();
s32 ready,duplex; s8 state;
if(SocketIsUnregistered()!=0)return SOCK_ERROR;
ready=0;
if(sock!=0) ready=(M2C_FIELD(sock,volatile s16*,SOCK_FLAGS)&SOCK_FLAG_READY)!=0;
if(!ready)return SOCK_NOT_READY;
if(M2C_FIELD(sock,s16*,SOCK_FLAGS)&SOCK_FLAG_BUSY)return SOCK_ERROR;
state=M2C_FIELD(sock,s8*,SOCK_STATE);duplex=1;
if(state!=SOCK_STATE_IDLE && state!=SOCK_STATE_CONNECTED)duplex=0;
if(!duplex)return SOCK_ERROR;
return M2C_FIELD(sock,s8*,SOCK_BLOCKING)==SOCK_BLOCKING_ON?0:SOCK_WOULD_BLOCK;
}

/* Validate the template socket, create the real TCP socket from
 * gTcpSocketConfig on the template's receive port and put it into listen,
 * returning the new socket handle and the peer endpoint it ends up with. */
s32 SocketCreateListen(void *tmpl, u16 *peerPort, s32 *peerAddr) {
    s32 SocketIsUnregistered();
    s32 SocketCreateFromConfig();
    s32 SocketBind();
    s32 SocketListen();
    extern M2C_UNK gTcpSocketConfig;
    s32 ready, usable, result, sock;
    s8 state;

    if (SocketIsUnregistered() != 0) return -28;
    ready = 0;
    if (tmpl != 0) ready = (M2C_FIELD(tmpl, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_READY) != 0;
    if (!ready) return -39;
    if (M2C_FIELD(tmpl, s16 *, SOCK_FLAGS) & SOCK_FLAG_BUSY) return -28;
    state = M2C_FIELD(tmpl, s8 *, SOCK_STATE);
    usable = 1;
    if (state != 0 && state != 4) usable = 0;
    if (!usable) return -28;
    if (M2C_FIELD(tmpl, s8 *, SOCK_BLOCKING) != SOCK_BLOCKING_ON) return -6;
    sock = SocketCreateFromConfig(&gTcpSocketConfig);
    if (sock < 0) return sock;
    result = SocketBind(sock, M2C_FIELD(tmpl, u16 *, SOCK_RECV_PORT));
    if (result < 0) return result;
    result = SocketListen(sock, peerPort, peerAddr);
    if (result < 0) return result;
    return sock;
}

