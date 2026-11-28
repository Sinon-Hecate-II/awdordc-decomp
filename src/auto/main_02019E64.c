/* 29 functions from 0x02019E64 to 0x0201AE0C (main), found by ds-decomp */
#include "common.h"
#include "tcp_socket.h"
static inline void seed_network_random(unsigned long long seed) { extern s32 gNetStack; M2C_FIELD(&gNetStack,unsigned long long *,0x68)=seed; M2C_FIELD(&gNetStack,unsigned long long *,0x70)=0x5d588b656c078965ULL; M2C_FIELD(&gNetStack,unsigned long long *,0x78)=0x269ec3; }
typedef struct { u8 dest[6],src[6];u16 type;u8 pad14,hw;u8 proto,pad17;u16 sizes;u8 pad20,op;u8 sender[6];u16 shi,slo;u8 target[6];u16 thi,tlo; } Packet0201ACA0;

/* Layout of the 0xC0-byte connection-data block Download Play peers exchange:
 * a 16-bit word count heads it, its payload carries an 8-byte header at +0x50,
 * and it may only be handed on once its status word is clear. */
#define LINK_DATA_LENGTH  0x3C /* u16: amount of transfer data in the block, 0 = nothing */
#define LINK_DATA_STATUS  0x44 /* s32: nonzero while the block is not ready to be used */
#define LINK_DATA_HEADER  0x50 /* the header of the carried data */
#define LINK_DATA_ID_A    0x2348
#define LINK_DATA_ID_B    0xBD8A
#define LINK_DATA_VERSION 4    /* format version the receiver accepts */
typedef struct {
    u16 tag;     /* LINK_DATA_ID_A or LINK_DATA_ID_B */
    u8 pad[4];
    u16 extra;   /* LINK_DATA_VERSION */
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

/* Tells whether a Download Play connection-data block holds a usable transfer:
 * it must carry data, not be marked busy, and its 8-byte header at +0x50 must
 * have a known id and the supported format version. */
s32 IsConnectionDataValid(u8 *connData) {
    void MI_CpuCopy8(void *, void *, s32);
    void DC_CleanRange(void *, s32);
    Func0201A09CBuf header;
    if (connData == NULL) return 0;
    if (*(u16 *)(connData + LINK_DATA_LENGTH) == 0) return 0;
    MI_CpuCopy8(connData + LINK_DATA_HEADER, &header, 8);
    DC_CleanRange(&header, 8);
    if (*(s32 *)(connData + LINK_DATA_STATUS) == 0) {
        if (*(volatile u16 *)&header.tag == LINK_DATA_ID_A || *(volatile u16 *)&header.tag == LINK_DATA_ID_B) {
            if (header.extra == LINK_DATA_VERSION) return 1;
        }
    }
    return 0;
}

void func_0201a134(s32 arg0) {
    extern M2C_UNK gNetStack;
    extern M2C_UNK gArpCache;
    extern M2C_UNK gSocketManager;
    extern M2C_UNK data_021375b8;
    void MI_CpuFill8(void *, s32, s32);
    void TaskWake(s32);
    void ClearTlsSessionCache(void);
    s32 old;
    void *node;
    void *sub;
    u8 t;
    void *fld4;
    s32 i;
    u8 *p;
    void (*fp)(u32);
    u32 val;
    old = M2C_FIELD(&gNetStack, s32 *, 0x50) != 0;
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
    MI_CpuFill8(&gArpCache, 0, 0x60);
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
    ClearTlsSessionCache();
}

/* Wait between network-stack polls: sleep for the stack's configured poll
 * interval (NETSTACK_WAIT_INTERVAL), or just yield the thread when it is 0. */
void NetStackWaitIdle(void) {
    extern M2C_UNK gNetStack;
    void TaskYield(void);
    void SleepMilliseconds(s32);
    s32 wait = M2C_FIELD(&gNetStack, s32 *, NETSTACK_WAIT_INTERVAL);
    if (wait == 0) {
        TaskYield();
    } else {
        SleepMilliseconds(wait);
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
    void TaskCreate(void *, void *, s32, void *, s32, s32);
    void TaskWake(s32);
    s32 func_0201a264(void);
    void func_0201a260(void);
    void NetReceiveThreadMain(void);
    void func_0201dd08(void);
    extern s32 gNetStack;
    extern s32 gLocalMacAddress;
    extern s32 gNetworkThreadPriority;
    extern s32 gNetReceiveThread;
    extern s32 gNetTaskState;
    extern s32 gNetworkTask;
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
        GetMacAddress((s32)&gLocalMacAddress);
    }

    M2C_FIELD((u8 *)&gNetStack, u8 *, 0x1) = 0;
    {
        TaskCreate((void *)&gNetReceiveThread, (void *)NetReceiveThreadMain, 0, (void *)&gNetTaskState, 0x800, gNetworkThreadPriority);
        TaskCreate((void *)&gNetworkTask, (void *)&func_0201dd08, 0, (void *)&data_021382c0, 0x800, gNetworkThreadPriority);
    }
    TaskWake((s32)&gNetReceiveThread);
    TaskWake((s32)&gNetworkTask);
}

#pragma opt_common_subs off
/* Checks whether the network worker has finished; if it is still running, queues its wakeup once. */
void *IsNetworkTaskFinished(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 TaskIsFinished(s32);
    void TaskWake(s32);
    extern M2C_UNK gNetworkTask;
    extern M2C_UNK gNetStack;
    s32 interruptState = OS_DisableInterrupts();
    s32 isFinished = TaskIsFinished((s32)&gNetworkTask);
    if (isFinished == 0 && M2C_FIELD(&gNetStack, s32 *, NETSTACK_WORKER_WAKE_PENDING) == 0) {
        M2C_FIELD(&gNetStack, s32 *, NETSTACK_WORKER_WAKE_PENDING) = 1;
        TaskWake((s32)&gNetworkTask);
    }
    OS_RestoreInterrupts(interruptState);
    return (void *)isFinished;
}
#pragma opt_common_subs on

/* Install the callback used by the network stack to reap closed sockets. */
void NetStackSetClosedSocketReaper(s32 reaperCallback) {
    extern M2C_UNK gNetStack;
    M2C_FIELD(&gNetStack, s32 *, NETSTACK_CLOSED_SOCKET_REAPER) = reaperCallback;
}

/* Stops the network workers: waits for the network task to finish and joins its
 * thread, terminates the receive thread, then clears the packet ring's reader
 * thread, buffer pointer and size so the stack is back to a stopped state. */
void NetworkStopWorkers(void){
void *IsNetworkTaskFinished(void);
void OS_JoinThread(void *);
void TerminateThread(void *);
void func_0201a134(s32);
extern M2C_UNK gNetworkTask,gNetReceiveThread,gNetStack;
IsNetworkTaskFinished();
OS_JoinThread(&gNetworkTask);
TerminateThread(&gNetReceiveThread);
M2C_FIELD(&gNetStack,s32 *,NETSTACK_RING_WAITER)=0;
func_0201a134(0);
M2C_FIELD(&gNetStack,s32 *,NETSTACK_RING_BUF)=0;
M2C_FIELD(&gNetStack,s32 *,NETSTACK_RING_SIZE)=0;
}

/* Set both network worker threads (the receive thread and the network task) to
 * `priority`, and remember it as the priority new workers are created with. */
void SetNetworkThreadPriority(s32 priority) {
    M2C_UNK SetThreadPriority(M2C_UNK *, s32);
    extern s32 gNetworkThreadPriority;
    extern M2C_UNK gNetworkTask;
    extern M2C_UNK gNetReceiveThread;

    gNetworkThreadPriority = priority;
    SetThreadPriority(&gNetReceiveThread, priority);
    SetThreadPriority(&gNetworkTask, priority);
}

/* Adds the 16-bit words of a buffer to a running one's-complement checksum and
 * folds the carries, so the caller can sum several buffers in a row before
 * ChecksumFinalize complements the total. Words are summed big-endian: a buffer
 * that starts at an odd address is summed byte by byte, an even one has its
 * host-order words byte-swapped around the sum, and a trailing odd byte counts as
 * the high half of a last word. */
u32 ChecksumAccumulate(u8 *data,u32 length,u32 sum){u32 folded;if((u32)data&1){while(length>1){sum+=(u16)((data[0]<<8)|data[1]);length-=2;data+=2;}}else{folded=(u16)sum;sum=(u16)(((s32)folded>>8)|(folded<<8));while(length>1){sum+=*(u16 *)data;data+=2;length-=2;}folded=((sum>>8)&0x00ff00ff)|((sum<<8)&0xff00ff00);sum=(folded>>16)|(folded<<16);}if(length)sum+=*data<<8;folded=(u16)sum+(sum>>16);folded+=folded>>16;return (u16)folded;}

/* Complement a running one's-complement checksum sum: returns ~sum, mapping a
 * zero result to 0xFFFF so a correct message still sums to CHECKSUM_VALID. */
s32 ChecksumFinalize(s32 sum) {
    u16 checksum;

    checksum = sum ^ 0xFFFF;
    if (checksum == 0) {
        checksum = 0xFFFF;
    }
    return (s32) checksum;
}

/* Compute the 16-bit one's-complement internet checksum of the `length` bytes at
 * `data` (RFC 1071): accumulate the words, then complement the sum, as a message
 * header's checksum field expects it. */
s32 Checksum(u8 *data, s32 length) {
    ChecksumFinalize((u16)ChecksumAccumulate(data, (u32)length, 0));
}

/* True when the one's-complement checksum of a TCP/UDP segment plus its IPv4
 * pseudo header (source and destination addresses, protocol and length) does not
 * come out to 0xFFFF, i.e. the received segment is corrupt. */
s32 IsTransportChecksumBad(u8 *segment,s32 length,u8 *ipHeader,u32 protocol){
    u32 sum;
    sum=ChecksumAccumulate(ipHeader+IP_HEADER_SRC_ADDR,8,ChecksumAccumulate(segment,length,protocol));
    sum+=length;
    if(sum&0x10000)sum=(u16)(sum+1);
    return sum!=65535;
}

/* True when an IPv4 address is the limited broadcast or loopback address, or is
 * in this host's own subnet (same network bits under NETSTACK_SUBNET_MASK). */
s32 IsLocalSubnetAddress(s32 address){
    extern M2C_UNK gNetStack;
    s32 isLocal = 1;
    if (address != IP_BROADCAST && address != IP_LOOPBACK) {
        s32 mask = M2C_FIELD(&gNetStack, s32 *, NETSTACK_SUBNET_MASK);
        if ((address & mask) != (M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP) & mask)) isLocal = 0;
    }
    return isLocal;
}

/* The IPv4 address to send to in order to reach `destination`: the destination
 * itself when it is on this host's subnet, otherwise the default gateway. */
s32 GetIpNextHop(s32 destination) {
    s32 IsLocalSubnetAddress(s32);
    extern M2C_UNK gNetStack;
    if (!IsLocalSubnetAddress(destination)) destination = M2C_FIELD(&gNetStack, s32 *, NETSTACK_GATEWAY);
    return destination;
}

/* True when `address` is this subnet's directed broadcast address: a local-subnet
   address whose host bits (those outside NETSTACK_SUBNET_MASK) are all set. */
s32 IsBroadcastAddress(s32 address) {
    extern M2C_UNK gNetStack;
    s32 isBroadcast = 0;
    if (IsLocalSubnetAddress(address)) {
        s32 hostMask = ~M2C_FIELD(&gNetStack, s32 *, NETSTACK_SUBNET_MASK);
        if (hostMask == (hostMask & address)) isBroadcast = 1;
    }
    return isBroadcast;
}

/* True when `address` (host order) is an IPv4 multicast address (224.0.0.0/4). */
s32 IsMulticastAddress(u32 address) {
    if ((address & IP_MULTICAST_MASK) == IP_MULTICAST_PREFIX) {
        return 1;
    }
    return 0;
}

/* True when an IPv4 destination address is one this host accepts: its own
 * address, loopback, a broadcast on its subnet, or a multicast group. */
s32 IsLocalDestinationAddress(s32 addr) {
    extern M2C_UNK gNetStack;
    s32 accepted = 1, broadcastOk = 1, loopbackOk = 1, ownOk = 1;
    s32 own = M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP);
    if (own != 0 && addr != own) ownOk = 0;
    if (!ownOk && addr != IP_LOOPBACK) loopbackOk = 0;
    if (!loopbackOk && !IsBroadcastAddress(addr)) broadcastOk = 0;
    if (!broadcastOk && !IsMulticastAddress(addr)) accepted = 0;
    return accepted;
}

/* Compare two six-byte MAC addresses a 16-bit word at a time: returns nonzero
 * when they differ, 0 when they are the same. */
s32 MacAddressesDiffer(u16 *macA, u16 *macB) {
    s32 i = 0;

    do {
        if (*macA++ != *macB++) return 1;
        i++;
    } while (i < 3);
    return 0;
}

/* Send one link-layer frame: rebuild its SNAP header from the shared template and
 * hand the frame to the WFC session, recording in the network stack whether the
 * send failed (a negative WFC result). */
void SendLinkFrame(u8 *frame, s32 frameLen, s32 extraData, s32 extraLen) {
    void MI_CpuCopy8(void *, void *, s32);
    s32 WFC_SendPacket(void *, void *, s32, s32, s32);
    extern M2C_UNK gLinkHeaderTemplate, gNetStack;
    MI_CpuCopy8(&gLinkHeaderTemplate, frame + 6, 6);
    M2C_FIELD(&gNetStack, u8 *, NETSTACK_SEND_FAILED) = WFC_SendPacket(frame, frame + 6, frameLen - 6, extraData, extraLen) < 0;
}

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

/* Queue a network packet and wake the waiting sender task if it is still active. */
void NetStackQueueAndWakeSender(s32 sourceLink, s32 destinationLink, s32 frame, s32 frameLength) {
    void NetStackQueuePacket(s32, s32, s32, s32, s32, s32);
    s32 TaskIsFinished(s32);
    void TaskWake(s32);
    extern M2C_UNK gNetStack;

    NetStackQueuePacket(sourceLink, destinationLink, frame, frameLength, 0, 0);
    if (!M2C_FIELD(&gNetStack, volatile s32 *, NETSTACK_RING_WAITER)) return;
    if (TaskIsFinished(M2C_FIELD(&gNetStack, volatile s32 *, NETSTACK_RING_WAITER))) return;
    TaskWake(M2C_FIELD(&gNetStack, volatile s32 *, NETSTACK_RING_WAITER));
}

/* Wait until a frame record is queued in the network stack's transmit ring,
   then return a pointer to its Ethernet frame (past the u16 record length) and
   store the frame length.  The record is left for the reader to consume. */
u8 *NetStackPeekFrame(s32 *out){
 s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);void OS_SleepThread(s32);
 extern M2C_UNK gNetStack,gSocketManager;
 s32 key;u32 size;u8 *ring;u32 len;
 key=OS_DisableInterrupts();
 while(M2C_FIELD(&gNetStack,u32 *,NETSTACK_RING_READ)==M2C_FIELD(&gNetStack,u32 *,NETSTACK_RING_WRITE)){
  M2C_FIELD(&gNetStack,s32 *,NETSTACK_RING_WAITER)=M2C_FIELD(&gSocketManager,s32 *,4);
  OS_SleepThread(0);
  M2C_FIELD(&gNetStack,s32 *,NETSTACK_RING_WAITER)=0;
 }
 OS_RestoreInterrupts(key);
 ring=M2C_FIELD(&gNetStack,u8 **,NETSTACK_RING_BUF);
 do{
  size=M2C_FIELD(&gNetStack,u32 *,NETSTACK_RING_SIZE);
  if(size-M2C_FIELD(&gNetStack,u32 *,NETSTACK_RING_READ)<2)M2C_FIELD(&gNetStack,u32 *,NETSTACK_RING_READ)=0;
  len=M2C_FIELD(ring,u16 *,M2C_FIELD(&gNetStack,u32 *,NETSTACK_RING_READ));
  if(!len)M2C_FIELD(&gNetStack,u32 *,NETSTACK_RING_READ)=0;
 }while(!len);
 *out=len-2;
 return M2C_FIELD(&gNetStack,u8 **,NETSTACK_RING_BUF)+M2C_FIELD(&gNetStack,u32 *,NETSTACK_RING_READ)+2;
}

#pragma opt_strength_reduction off
/* Release the record at the network stack ring's read position: advance the read
 * offset by the record's leading u16 length and wrap it to the start once it
 * reaches the end of the ring, with interrupts disabled against the producer. */
void NetStackConsumeFrame(void){
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gNetStack;
    s32 interruptState;
    u32 readPos;
    u8 *ring;
    interruptState = OS_DisableInterrupts();
    readPos = M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_READ);
    ring = (u8 *)M2C_FIELD(&gNetStack, u8 **, NETSTACK_RING_BUF);
    M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_READ) = readPos + M2C_FIELD(ring, u16 *, M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_READ));
    if (M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_READ) >= M2C_FIELD(&gNetStack, u32 *, NETSTACK_RING_SIZE)) M2C_FIELD(&gNetStack, volatile u32 *, NETSTACK_RING_READ) = 0;
    OS_RestoreInterrupts(interruptState);
}
#pragma opt_strength_reduction reset
/* Find the MAC address to send a frame to IPv4 address `ip`: our own for the
 * loopback or local address, the broadcast address for the broadcast and
 * multicast ones, else the ARP cache entry for the peer (whose age is
 * refreshed).  Returns 0 when the address has no cache entry. */
s32 FindArpMacAddress(s32 ip) {
    extern M2C_UNK gNetStack, gLocalMacAddress, gBroadcastMacAddress, gArpCache, gArpCacheAge;
    s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); u64 GetSystemTick(void);
    s32 irq = OS_DisableInterrupts();
    u32 i;
    void *mac = 0;
    u8 *entry;
    if (ip == IP_LOOPBACK || ip == M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP)) mac = &gLocalMacAddress;
    else if (IsBroadcastAddress(ip) || IsMulticastAddress(ip)) mac = &gBroadcastMacAddress;
    else {
        entry = (u8 *)&gArpCache;
        for (i = 0; i < ARP_CACHE_COUNT; i++, entry += ARP_CACHE_STRIDE) {
            if (ip == *(s32 *)entry) {
                ip = (s32)(GetSystemTick() >> 16);
                M2C_FIELD(&gArpCacheAge, u16 *, i * ARP_CACHE_STRIDE) = ip;
                mac = (u8 *)&gArpCache + i * ARP_CACHE_STRIDE + 4;
                break;
            }
        }
    }
    OS_RestoreInterrupts(irq);
    return (s32)mac;
}

/* Build and send a 42-byte ARP-style announcement packet for `nodeId`, swapping byte order in the id fields. */
void SendArpRequest(s32 nodeId) {
    extern M2C_UNK gLocalMacAddress;
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
    MI_CpuCopy8(&gLocalMacAddress, packet.src, 6);
    packet.type = 0x608;
    packet.hw = 1;
    packet.proto = 8;
    packet.sizes = 0x406;
    packet.op = 1;
    MI_CpuCopy8(&gLocalMacAddress, packet.sender, 6);
    own = M2C_FIELD(&gNetStack, u32 *, 80);
    hi = (u16)(own >> 16);
    lo = (u16)own;
    ahi = (u16)((u32)nodeId >> 16);
    alo = (u16)nodeId;
    packet.shi = (hi >> 8) | (hi << 8);
    packet.slo = (lo >> 8) | (lo << 8);
    packet.thi = (ahi >> 8) | (ahi << 8);
    packet.tlo = (alo >> 8) | (alo << 8);
    SendLinkFrame((u8 *)&packet, 42, 0, 0);
}

/* Find the MAC address of the peer at `ip`: announce ourselves up to
 * ARP_RESOLVE_ATTEMPTS times and, after each one, poll the ARP cache every
 * ARP_RETRY_MS for ARP_RESOLVE_WAITS rounds.  Gives up (0) if the local
 * address is torn down meanwhile or the peer never answers. */
s32 ResolveArpMacAddress(s32 ip) {
    void SendArpRequest(s32);
    void SleepMilliseconds(s32);
    s32 FindArpMacAddress(s32);
    extern M2C_UNK gNetStack;
    u32 attempt, wait;
    s32 mac;
    for (attempt = 0; attempt < ARP_RESOLVE_ATTEMPTS; attempt++) {
        SendArpRequest(ip);
        for (wait = 0; wait < ARP_RESOLVE_WAITS; wait++) {
            if (!M2C_FIELD(&gNetStack, s32 *, NETSTACK_LOCAL_IP)) return 0;
            SleepMilliseconds(ARP_RETRY_MS);
            mac = FindArpMacAddress(ip);
            if (mac) return mac;
        }
    }
    return 0;
}

