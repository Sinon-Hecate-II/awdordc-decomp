/* 15 functions from 0x0201AE0C to 0x0201BDE0 (main), found by ds-decomp. */
#include "common.h"
#include "tcp_socket.h"
#include "net_socket.h"

/* Updates the ARP cache for `ip`: refreshes the entry if the address is already
 * cached, otherwise (when `create`) stores `mac` in a free entry, or the oldest
 * one. Local, off-subnet and multicast addresses are ignored. */
void UpdateArpCache(void *mac,u32 ip,s32 create){
u64 GetSystemTick(void);s32 IsLocalSubnetAddress(u32);s32 IsMulticastAddress(u32);
M2C_UNK MI_CpuCopy8(M2C_UNK*,void*,M2C_UNK);
extern M2C_UNK gNetStack,gArpCache,gArpCacheAge;
u16 now;u32 i,best;u8 *entry;s32 age,off;s32 delta;
if(ip==0x7f000001 || ip==M2C_FIELD(&gNetStack,u32*,NETSTACK_LOCAL_IP))return;
if(!IsLocalSubnetAddress(ip))return;
if(IsMulticastAddress(ip))return;
now=GetSystemTick()>>16;
entry=(u8*)&gArpCache;
for(i=0;i<ARP_CACHE_COUNT;i++,entry+=ARP_CACHE_STRIDE){
if(ip==M2C_FIELD(entry,u32*,ARP_CACHE_ADDR)){
off=i*ARP_CACHE_STRIDE;M2C_FIELD(&gArpCacheAge,u16*,off)=now;
MI_CpuCopy8(mac,(u8*)&gArpCache+off+ARP_CACHE_MAC,6);return;
}}
if(!create)return;
age=0;entry=(u8*)&gArpCache;best=0;i=0;
do{
if(!M2C_FIELD(entry,u32*,ARP_CACHE_ADDR)){best=i;break;}
delta=now-M2C_FIELD(entry,u16*,ARP_CACHE_AGE);entry+=ARP_CACHE_STRIDE;
if(age<(s16)delta){best=i;age=(u16)delta;}
i++;
}while(i<ARP_CACHE_COUNT);
off=best*ARP_CACHE_STRIDE;M2C_FIELD(&gArpCache,u32*,off)=ip;
MI_CpuCopy8(mac,(u8*)&gArpCache+off+ARP_CACHE_MAC,6);
M2C_FIELD(&gArpCacheAge,u16*,off)=now;
}

#pragma scheduling off
/* Build the Ethernet II header in front of the IPv4 packet `payload` and send the
 * frame on the link.  The type goes at header offset ETH_TYPE (0x0C, i.e. 2 bytes
 * before the packet).  For a unicast destination the header takes the MAC the ARP
 * cache resolves for its next hop (asking with an ARP request when it is missing:
 * no MAC means the frame is dropped); a multicast destination gets the
 * 01:00:5e:xx:xx:xx MAC built from the address.  The source is the local MAC. */
void SendEthernetFrame(void *payload, s32 payloadLen, M2C_UNK extraData, M2C_UNK extraLen, u32 dstIp, u16 ethType) {
M2C_UNK MI_CpuCopy8(M2C_UNK *,void *,M2C_UNK);
s32 GetIpNextHop(u32); s32 IsMulticastAddress(u32);
M2C_UNK SendLinkFrame(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK *FindArpMacAddress(void); M2C_UNK *ResolveArpMacAddress(s32);
extern M2C_UNK gLocalMacAddress;
M2C_UNK *destMac; s32 nextHop;
M2C_FIELD(payload,u16 *,-2)=(ethType>>8)|(ethType<<8);
if(!IsMulticastAddress(dstIp)){
nextHop=GetIpNextHop(dstIp);if(!nextHop)return;
destMac=FindArpMacAddress();
if(!destMac)destMac=ResolveArpMacAddress(nextHop);
if(!destMac)return;
MI_CpuCopy8(destMac,(u8 *)payload-14,6);
}else{
M2C_FIELD(payload,u8 *,-14)=1;
M2C_FIELD(payload,u8 *,-13)=0;
M2C_FIELD(payload,u8 *,-12)=0x5e;
M2C_FIELD(payload,u8 *,-11)=(dstIp>>16)&127;
M2C_FIELD(payload,u8 *,-10)=dstIp>>8;
M2C_FIELD(payload,u8 *,-9)=dstIp;
}
MI_CpuCopy8(&gLocalMacAddress,(u8 *)payload-8,6);
SendLinkFrame((u8 *)payload-14,payloadLen+14,extraData,extraLen);
}
#pragma scheduling on
/* Finish the IPv4 header of one outgoing fragment (total length and
 * flags/fragment offset), checksum it, then either send it on the link or,
 * for loopback and multicast destinations, queue a copy on the local stack. */
void SendIpFragment(void *payload,s32 payloadLen,void *extraData,s32 extraLen,u32 dstIp,s32 fragmentField){
s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);
M2C_UNK MI_CpuCopy8(M2C_UNK*,void*,M2C_UNK);
s32 Checksum(u8*,s32);s32 IsMulticastAddress(u32);
M2C_UNK NetStackQueuePacket(void*,void*,void*,s32,s32,s32);
extern M2C_UNK gNetStack,gLinkHeaderTemplate,gLocalMacAddress;
u16 totalLen,fragField;s32 sum,interrupts;
totalLen=payloadLen+IP_HEADER_SIZE+extraLen;fragField=fragmentField;
M2C_FIELD(payload,u16*,-IP_HEADER_SIZE+2)=((s32)totalLen>>8)|(totalLen<<8);
M2C_FIELD(payload,u16*,-IP_HEADER_SIZE+6)=((s32)fragField>>8)|(fragField<<8);
M2C_FIELD(payload,u16*,-IP_HEADER_SIZE+10)=0;
sum=Checksum(payload-IP_HEADER_SIZE,IP_HEADER_SIZE);
M2C_FIELD(payload,u16*,-IP_HEADER_SIZE+10)=(sum>>8)|(sum<<8);
if(dstIp!=IP_LOOPBACK && dstIp!=M2C_FIELD(&gNetStack,u32*,NETSTACK_LOCAL_IP))SendEthernetFrame(payload-IP_HEADER_SIZE,payloadLen+IP_HEADER_SIZE,extraData,extraLen,dstIp,ETH_TYPE_IPV4);
if(dstIp!=IP_LOOPBACK && dstIp!=M2C_FIELD(&gNetStack,u32*,NETSTACK_LOCAL_IP)){if(!IsMulticastAddress(dstIp))return;}
MI_CpuCopy8(&gLinkHeaderTemplate,payload-(IP_HEADER_SIZE+LINK_HEADER_SIZE),LINK_HEADER_SIZE);
interrupts=OS_DisableInterrupts();
NetStackQueuePacket(&gLocalMacAddress,&gLocalMacAddress,payload-(IP_HEADER_SIZE+LINK_HEADER_SIZE),payloadLen+IP_HEADER_SIZE+LINK_HEADER_SIZE,extraData,extraLen);
OS_RestoreInterrupts(interrupts);
}

/* Sends an IPv4 packet whose 20-byte header sits just before `payload`: fills
 * the header from the network stack (protocol, local source address, a fresh
 * identification) and fragments both data buffers into chunks of at most 1480
 * payload bytes addressed to dstIp. */
void SendIpPacket(void *payload,u32 dataLen,void *data,u32 dataLen2,u32 dstIp,u8 protocol){
extern M2C_UNK gNetStack;
u32 chunk;u16 dstIpLo,srcIpLo,srcIpHi,dstIpHi,fragOffset;s32 unused;u32 remaining2,remaining1;void *dataPtr,*firstData;
M2C_FIELD(payload,s8 *,-20)=0x45;
fragOffset=0;M2C_FIELD(payload,s8 *,-19)=0;
M2C_FIELD(&gNetStack,u16 *,NETSTACK_IP_ID)=(u16)(M2C_FIELD(&gNetStack,u16 *,NETSTACK_IP_ID)+1);
M2C_FIELD(payload,s16 *,-16)=(s16)(((s32)M2C_FIELD(&gNetStack,u16 *,NETSTACK_IP_ID)>>8)|(M2C_FIELD(&gNetStack,u16 *,NETSTACK_IP_ID)<<8));
M2C_FIELD(payload,u8 *,-12)=0x80;M2C_FIELD(payload,u8 *,-11)=protocol;
dstIpHi=(u16)(dstIp>>16);srcIpHi=(u16)(M2C_FIELD(&gNetStack,u32 *,NETSTACK_LOCAL_IP)>>16);
M2C_FIELD(payload,s16 *,-8)=(s16)(((s32)srcIpHi>>8)|(srcIpHi<<8));
srcIpLo=(u16)M2C_FIELD(&gNetStack,u32 *,NETSTACK_LOCAL_IP);dstIpLo=(u16)dstIp;
M2C_FIELD(payload,s16 *,-6)=(s16)(((s32)srcIpLo>>8)|(srcIpLo<<8));
remaining1=dataLen;M2C_FIELD(payload,s16 *,-4)=(s16)(((s32)dstIpHi>>8)|(dstIpHi<<8));
firstData=data;remaining2=dataLen2;
M2C_FIELD(payload,s16 *,-2)=(s16)(((s32)dstIpLo>>8)|(dstIpLo<<8));
if(remaining1>IP_MAX_FRAGMENT_PAYLOAD){
dataPtr=payload;
if(remaining1>IP_MAX_FRAGMENT_PAYLOAD){do{SendIpFragment(payload,0,dataPtr,IP_MAX_FRAGMENT_PAYLOAD,dstIp,fragOffset|IP_FLAG_MOREFRAGMENTS);dataPtr+=IP_MAX_FRAGMENT_PAYLOAD;remaining1-=IP_MAX_FRAGMENT_PAYLOAD;fragOffset+=IP_MAX_FRAGMENT_PAYLOAD/IP_FRAGMENT_UNIT;}while(remaining1>IP_MAX_FRAGMENT_PAYLOAD);}
if(remaining1){if(remaining2)SendIpFragment(payload,0,dataPtr,remaining1,dstIp,fragOffset|IP_FLAG_MOREFRAGMENTS);else SendIpFragment(payload,0,dataPtr,remaining1,dstIp,fragOffset);
fragOffset+=remaining1>>3;remaining1=0;}}
if(remaining1+remaining2>IP_MAX_FRAGMENT_PAYLOAD){do{chunk=IP_MAX_FRAGMENT_PAYLOAD-remaining1;SendIpFragment(payload,remaining1,firstData,chunk,dstIp,fragOffset|IP_FLAG_MOREFRAGMENTS);remaining2-=chunk;remaining1=0;firstData+=chunk;fragOffset+=IP_MAX_FRAGMENT_PAYLOAD/IP_FRAGMENT_UNIT;}while(remaining2>IP_MAX_FRAGMENT_PAYLOAD);}
if(remaining1+remaining2==0)return;
SendIpFragment(payload,remaining1,firstData,remaining2,dstIp,fragOffset);
}

#pragma opt_common_subs off
void func_0201b338(void *a,u32 b,void *c) {
u32 ChecksumAccumulate(void *,u32,u32); s32 ChecksumFinalize(s32); void SendIpPacket(void *,u32,void *,u32,u32,u8); extern M2C_UNK gSocketManager,gNetStack;
void *p=(void *)M2C_FIELD(c,u32 *,0x4c); u16 id; s32 sum;
M2C_FIELD(p,u16 *,0x22)=8;
M2C_FIELD(p,u16 *,0x26)=M2C_FIELD(&gSocketManager,u32 *,4);
id=M2C_FIELD(&gNetStack,u16 *,4);
M2C_FIELD(p,u16 *,0x24)=0;
M2C_FIELD(c,u16 *,10)=id;
M2C_FIELD(&gNetStack,u16 *,4)++;
M2C_FIELD(p,u16 *,0x28)=id;
sum=ChecksumAccumulate((u8 *)p+0x22,8,0); sum=ChecksumAccumulate(a,b,sum); sum=ChecksumFinalize((u16)sum);
M2C_FIELD(p,u16 *,0x24)=(sum>>8)|(sum<<8);
SendIpPacket((u8 *)p+0x22,8,a,b,M2C_FIELD(c,u32 *,0x1c),1);
}
#pragma opt_common_subs reset
/* Builds and sends one UDP datagram on `conn`: writes the 12-byte IPv4
 * pseudo-header followed by the 8-byte UDP header (local and remote port,
 * length and checksum), checksums the header together with the payload and
 * hands both to SendIpPacket with protocol 17. */
void UdpSendSegment(void *payload,s32 dataLen,void *conn) {
u32 ChecksumAccumulate(void *,u32,u32);s32 ChecksumFinalize(s32);void SendIpPacket(void *,u32,void *,u32,u32,u8);
extern M2C_UNK gNetStack;
void *base=M2C_FIELD(conn,void **,SOCK_SEND_BUFFER);void *p=base+0x22;u16 a,b,c,d,len; s32 sum;
a=M2C_FIELD(&gNetStack,u32 *,NETSTACK_LOCAL_IP)>>16;
M2C_FIELD(p,u16 *,-12)=((s32)a>>8)|(a<<8);
b=M2C_FIELD(&gNetStack,u32 *,NETSTACK_LOCAL_IP);
M2C_FIELD(p,u16 *,-10)=((s32)b>>8)|(b<<8);
c=M2C_FIELD(conn,u32 *,SOCK_REMOTE_IP)>>16;
M2C_FIELD(p,u16 *,-8)=((s32)c>>8)|(c<<8);
d=M2C_FIELD(conn,u32 *,SOCK_REMOTE_IP);
M2C_FIELD(p,u16 *,-6)=((s32)d>>8)|(d<<8);
M2C_FIELD(p,u16 *,-4)=IP_PROTO_UDP<<8;
len=dataLen+UDP_HEADER_SIZE;M2C_FIELD(p,u16 *,4)=((s32)len>>8)|(len<<8);
M2C_FIELD(p,u16 *,-2)=M2C_FIELD(p,u16 *,4);
a=M2C_FIELD(conn,u16 *,SOCK_REMOTE_PORT);M2C_FIELD(p,u16 *,2)=((s32)a>>8)|(a<<8);
b=M2C_FIELD(conn,u16 *,SOCK_LOCAL_PORT);M2C_FIELD(base,u16 *,0x22)=((s32)b>>8)|(b<<8);
M2C_FIELD(p,u16 *,6)=0;
sum=ChecksumAccumulate(p-12,IP_PSEUDO_HEADER_SIZE+UDP_HEADER_SIZE,0);sum=ChecksumAccumulate(payload,dataLen,sum);
sum=ChecksumFinalize((u16)sum);M2C_FIELD(p,u16 *,6)=(sum>>8)|(sum<<8);
SendIpPacket(p,UDP_HEADER_SIZE,payload,dataLen,M2C_FIELD(conn,u32 *,SOCK_REMOTE_IP),IP_PROTO_UDP);
}

/* Build and send one TCP segment for a connection: fill in the TCP header (adding the MSS
   option on SYN), checksum the header together with its IP pseudo-header and the payload,
   then advance the connection's sequence number past the segment. */
void TcpSendSegment(void *payload,u32 dataLen,void *conn,u32 flags){
u32 ChecksumAccumulate(void *,u32,u32);s32 ChecksumFinalize(s32);
extern M2C_UNK gSocketManager,data_021374f8,data_021377a2,gNetStack;
void *seg;u32 hdrLen;s32 sum;u16 srcIpHi,srcIpLo,dstIpHi,dstIpLo,srcPort,dstPort,seqHi,seqLo,ackHi,ackLo,window,mssHi,mssLo,totalLen;
if(!M2C_FIELD(conn,u8 *,8))return;
/* No interface yet: write into the built-in scratch packet rather than the connection's buffer. */
if(M2C_FIELD(&gSocketManager,void **,4)==&data_021374f8)seg=&data_021377a2;else seg=M2C_FIELD(conn,void **,0x4c)+0x22;
hdrLen=(flags&2)?24:20;totalLen=hdrLen+dataLen;
/* IP pseudo-header at seg-12: source IP, destination IP, zero+protocol, TCP length. */
srcIpHi=M2C_FIELD(&gNetStack,u32 *,80)>>16;M2C_FIELD(seg,u16 *,-12)=((s32)srcIpHi>>8)|(srcIpHi<<8);
srcIpLo=M2C_FIELD(&gNetStack,u32 *,80);M2C_FIELD(seg,u16 *,-10)=((s32)srcIpLo>>8)|(srcIpLo<<8);
dstIpHi=M2C_FIELD(conn,u32 *,28)>>16;M2C_FIELD(seg,u16 *,-8)=((s32)dstIpHi>>8)|(dstIpHi<<8);
dstIpLo=M2C_FIELD(conn,u32 *,28);M2C_FIELD(seg,u16 *,-6)=((s32)dstIpLo>>8)|(dstIpLo<<8);
M2C_FIELD(seg,u16 *,-4)=0x600;M2C_FIELD(seg,u16 *,-2)=((s32)totalLen>>8)|(totalLen<<8);
/* TCP header: ports, sequence, acknowledgement, data offset/flags, window, checksum, urgent. */
srcPort=M2C_FIELD(conn,u16 *,10);M2C_FIELD(seg,u16 *,0)=((s32)srcPort>>8)|(srcPort<<8);
dstPort=M2C_FIELD(conn,u16 *,24);M2C_FIELD(seg,u16 *,2)=((s32)dstPort>>8)|(dstPort<<8);
seqHi=M2C_FIELD(conn,u32 *,40)>>16;M2C_FIELD(seg,u16 *,4)=((s32)seqHi>>8)|(seqHi<<8);
seqLo=M2C_FIELD(conn,u32 *,40);M2C_FIELD(seg,u16 *,6)=((s32)seqLo>>8)|(seqLo<<8);
ackHi=M2C_FIELD(conn,u32 *,36)>>16;M2C_FIELD(seg,u16 *,8)=((s32)ackHi>>8)|(ackHi<<8);
ackLo=M2C_FIELD(conn,u32 *,36);M2C_FIELD(seg,u16 *,10)=((s32)ackLo>>8)|(ackLo<<8);
M2C_FIELD(seg,u8 *,12)=(hdrLen>>2)<<4;M2C_FIELD(seg,u8 *,13)=flags;
window=M2C_FIELD(conn,u32 *,60)-M2C_FIELD(conn,u32 *,68);M2C_FIELD(seg,u16 *,14)=((s32)window>>8)|(window<<8);
M2C_FIELD(seg,u16 *,16)=0;M2C_FIELD(seg,u16 *,18)=0;
/* SYN carries a 4-byte MSS option (kind 2, length 4, current MSS). */
if(flags&2){mssHi=(M2C_FIELD(&gNetStack,u16 *,2)+0x2040000U)>>16;M2C_FIELD(seg,u16 *,20)=((s32)mssHi>>8)|(mssHi<<8);mssLo=M2C_FIELD(&gNetStack,u16 *,2)+0x2040000;M2C_FIELD(seg,u16 *,22)=((s32)mssLo>>8)|(mssLo<<8);}
sum=ChecksumAccumulate(seg-12,hdrLen+12,0);sum=ChecksumAccumulate(payload,dataLen,sum);sum=ChecksumFinalize((u16)sum);M2C_FIELD(seg,u16 *,16)=(sum>>8)|(sum<<8);
SendIpPacket(seg,hdrLen,payload,dataLen,M2C_FIELD(conn,u32 *,28),6);
M2C_FIELD(conn,u32 *,40)+=dataLen;if(flags&3)M2C_FIELD(conn,u32 *,40)+=1;
}

void SendArpReply(void *arg0) {
    M2C_UNK MI_CpuCopy8(M2C_UNK *, void *, M2C_UNK);
    M2C_UNK SendLinkFrame(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK gNetStack;
    extern M2C_UNK gLocalMacAddress;
    u16 temp_ip;
    u16 temp_ip_2;

    M2C_FIELD(arg0, s16 *, 6) = 0x200;
    MI_CpuCopy8(arg0 + 8, arg0 + 0x12, 0xA);
    MI_CpuCopy8(&gLocalMacAddress, arg0 + 8, 6);
    temp_ip = (u16) ((u32) M2C_FIELD(&gNetStack, u32 *, 0x50) >> 0x10);
    M2C_FIELD(arg0, s16 *, 0xE) = (s16) ((temp_ip >> 8) | (temp_ip << 8));
    temp_ip_2 = (u16) M2C_FIELD(&gNetStack, u32 *, 0x50);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) ((temp_ip_2 >> 8) | (temp_ip_2 << 8));
    MI_CpuCopy8(arg0 + 0x12, arg0 - 0xE, 6);
    MI_CpuCopy8(&gLocalMacAddress, arg0 - 8, 6);
    SendLinkFrame(arg0 - 0xE, 0x2A, 0, 0);
}

#pragma optimization_level 2
#pragma opt_common_subs off
/* Handle a received ARP packet `frame` of `len` bytes that is not our own: if
 * it is a well-formed IPv4 ARP packet, learn the sender in the ARP cache,
 * answer a request addressed to our local address with a reply, and mark the
 * link ARP-resolved when the reply announcing our address arrives. */
void HandleArpPacket(void *frame, u32 len) {
    s32 MacAddressesDiffer(void *, void *);
    extern M2C_UNK gNetStack, gLocalMacAddress;
    u16 opcode, senderIpLo, senderIpHi, targetIpLo, targetIpHi, rawOpcode;
    u32 srcIp, dstIp, localIp;
    s32 isSelf, isTarget;

    if (len < ARP_PACKET_SIZE) return;
    if (MacAddressesDiffer((u8 *)frame + ARP_SENDER_MAC, &gLocalMacAddress) && M2C_FIELD(&gNetStack, u32 *, NETSTACK_LOCAL_IP)) {
        if (M2C_FIELD(frame, u16 *, ARP_HTYPE) == 0x100 && M2C_FIELD(frame, u16 *, ARP_PTYPE) == 8 && M2C_FIELD(frame, u16 *, ARP_HLEN) == 0x406) {
            rawOpcode = M2C_FIELD(frame, u16 *, ARP_OPCODE);
            opcode = ((s32)rawOpcode >> 8) | (rawOpcode << 8);
            if (opcode != ARP_OPCODE_REQUEST && opcode != ARP_OPCODE_REPLY) return;
            senderIpLo = M2C_FIELD(frame, u16 *, ARP_SENDER_IP + 2);
            senderIpHi = M2C_FIELD(frame, u16 *, ARP_SENDER_IP);
            targetIpLo = M2C_FIELD(frame, u16 *, ARP_TARGET_IP + 2);
            targetIpHi = M2C_FIELD(frame, u16 *, ARP_TARGET_IP);
            srcIp = ((u16)(((s32)senderIpHi >> 8) | (senderIpHi << 8)) << 16) | (u16)(((s32)senderIpLo >> 8) | (senderIpLo << 8));
            localIp = M2C_FIELD(&gNetStack, u32 *, NETSTACK_LOCAL_IP);
            isSelf = srcIp == localIp;
            dstIp = ((u16)(((s32)targetIpHi >> 8) | (targetIpHi << 8)) << 16) | (u16)(((s32)targetIpLo >> 8) | (targetIpLo << 8));
            isTarget = localIp == dstIp;
            if (!isSelf) UpdateArpCache((u8 *)frame + ARP_SENDER_MAC, srcIp, isTarget);
            if (opcode == ARP_OPCODE_REQUEST && isTarget) {
                SendArpReply(frame);
                return;
            }
            if (opcode == ARP_OPCODE_REPLY && isTarget && isSelf) M2C_FIELD(&gNetStack, u8 *, NETSTACK_ARP_RESOLVED) = 1;
        }
    }
}
#pragma opt_common_subs reset
#pragma optimization_level 4
/* Answers an ICMP echo request: `ipHeader` is the received IPv4 header and
 * `icmp`/`len` the request message.  Resolve the sender's link address (asking
 * for it over ARP when the cache has no entry), then turn the message into an
 * echo reply with a fresh checksum and send it back. */
M2C_UNK SendIcmpEchoReply(void *ipHeader,u8 *icmp,s32 len){
s32 Checksum(u8 *,s32);s32 GetIpNextHop(u32);M2C_UNK *FindArpMacAddress();void SendArpRequest(s32);void SendIpPacket(void *,u32,void *,u32,u32,u8);
s32 nextHop,sum;u16 hi,lo;u32 sender;
lo=M2C_FIELD(ipHeader,u16*,14);hi=M2C_FIELD(ipHeader,u16*,12);
sender=((u16)(((s32)hi>>8)|(hi<<8))<<16)|(u16)(((s32)lo>>8)|(lo<<8));
nextHop=GetIpNextHop(sender);if(!nextHop)return;if(!FindArpMacAddress()){SendArpRequest(nextHop);return;}
icmp[0]=0;M2C_FIELD(icmp,u16*,2)=0;sum=Checksum(icmp,len);M2C_FIELD(icmp,u16*,2)=(sum>>8)|(sum<<8);
lo=M2C_FIELD(ipHeader,u16*,14);hi=M2C_FIELD(ipHeader,u16*,12);
sender=((u16)(((s32)hi>>8)|(hi<<8))<<16)|(u16)(((s32)lo>>8)|(lo<<8));
SendIpPacket(icmp,len,0,0,sender,1);
}
#pragma optimization_level 4
/* Hand a received ICMP echo reply's payload to the socket waiting for it: the
 * first ICMP socket with the reply's id and remote address that holds no
 * pending datagram gets it (up to its capacity), and its task is woken. */
M2C_UNK IcmpSocketReceive(void *packet,u8 *ip,M2C_UNK ipLen) {
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); void TaskWake(s32); M2C_UNK MI_CpuCopy8(M2C_UNK *,void *,M2C_UNK);
extern M2C_UNK gSocketManager;
void *entry; s32 saved,id; void *node; u16 low,high; u32 max,len;
saved=OS_DisableInterrupts();
node=M2C_FIELD(&gSocketManager,void **,8);
while(node){
entry=M2C_FIELD(node,void **,0xa4);
if(entry && (id=M2C_FIELD(entry,s32 *,0))!=0){
if(M2C_FIELD(entry,u8 *,8)==11 && M2C_FIELD(ip,u16 *,4)==(u16)id && M2C_FIELD(entry,u16 *,10)==M2C_FIELD(ip,u16 *,6) && M2C_FIELD(entry,u32 *,68)==0){
low=M2C_FIELD(packet,u16 *,14);high=M2C_FIELD(packet,u16 *,12);
if(M2C_FIELD(entry,u32 *,28)==(((u16)(((s32)high>>8)|(high<<8))<<16)|(u16)(((s32)low>>8)|(low<<8)))){
max=M2C_FIELD(entry,u32 *,60);len=ipLen-8;
if(len>max)M2C_FIELD(entry,u32 *,68)=max;else M2C_FIELD(entry,u32 *,68)=len;
MI_CpuCopy8((M2C_UNK *)(ip+8),M2C_FIELD(entry,void **,64),M2C_FIELD(entry,u32 *,68));
if(M2C_FIELD(entry,s32 *,4)==3){M2C_FIELD(entry,s32 *,4)=0;TaskWake(M2C_FIELD(entry,s32 *,0));}
break;
}
}
}
node=M2C_FIELD(node,void **,104);
}
OS_RestoreInterrupts(saved);
}

s32 IsValidIpAddressPair(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 != -1) && (arg1 != 0) && (arg1 != -1)) {
        return 1;
    }
    return 0;
}

/* Handle a received ICMP message: `ipHeader` is the IPv4 header in front of the
 * `icmp` message of `len` bytes.  Drop the message unless its checksum is valid
 * and both of the header's addresses are usable; then give an echo reply to the
 * ICMP socket waiting for it, or answer an echo request. */
void HandleIcmpPacket(void *ipHeader, u8 *icmp, M2C_UNK len) {
    s32 Checksum(u8 *, M2C_UNK);
    M2C_UNK SendIcmpEchoReply(void *, u8 *, M2C_UNK);
    M2C_UNK IcmpSocketReceive(void *, u8 *, M2C_UNK);
    u16 dstIpLo;
    u16 dstIpHi;
    u16 srcIpLo;
    u16 srcIpHi;
    u32 srcIp;
    u32 dstIp;

    if (Checksum(icmp, len) != CHECKSUM_VALID) {
        return;
    }
    dstIpLo = M2C_FIELD(ipHeader, u16 *, IPH_DST_IP_LO);
    dstIpHi = M2C_FIELD(ipHeader, u16 *, IPH_DST_IP_HI);
    srcIpLo = M2C_FIELD(ipHeader, u16 *, IPH_SRC_IP_LO);
    srcIpHi = M2C_FIELD(ipHeader, u16 *, IPH_SRC_IP_HI);
    srcIp = ((u32)(u16)((srcIpHi >> 8) | (srcIpHi << 8)) << 16) | (u16)((srcIpLo >> 8) | (srcIpLo << 8));
    dstIp = ((u32)(u16)((dstIpHi >> 8) | (dstIpHi << 8)) << 16) | (u16)((dstIpLo >> 8) | (dstIpLo << 8));
    if (IsValidIpAddressPair(srcIp, dstIp) == 0) {
        return;
    }
    switch (*icmp) {
        case ICMP_TYPE_ECHO_REPLY:
            IcmpSocketReceive(ipHeader, icmp, len);
            return;
        case ICMP_TYPE_ECHO_REQUEST:
            SendIcmpEchoReply(ipHeader, icmp, len);
            return;
        default:
            return;
    }
}

/* Return the raw connection of the listening TCP socket a received SYN is for:
 * walk the socket manager's list and take the first listening socket whose local
 * port is the segment's destination port and, when the socket is bound to a
 * peer, whose remote port and address are the segment's source. */
void *TcpFindListeningSocket(void *ipHeader, void *tcpHeader) {
extern M2C_UNK gSocketManager;
void *entry,*node; u16 localPort,remotePort,srcPort,srcIpLo,srcIpHi;
node=M2C_FIELD(&gSocketManager,void **,SOCKMGR_SOCKETS);
while(node){
entry=M2C_FIELD(node,void **,SOCK_OBJECT_RAW);
if(entry && M2C_FIELD(entry,s32 *,CONN_ID) && M2C_FIELD(entry,u8 *,CONN_STATE)==CONN_STATE_LISTEN){
localPort=M2C_FIELD(tcpHeader,u16 *,TCPH_DST_PORT);
if(M2C_FIELD(entry,u16 *,CONN_LOCAL_PORT)!=(u16)(((s32)localPort>>8)|(localPort<<8)))goto next;
remotePort=M2C_FIELD(entry,u16 *,CONN_REMOTE_PORT);
if(remotePort){srcPort=M2C_FIELD(tcpHeader,u16 *,TCPH_SRC_PORT);if(remotePort!=(u16)(((s32)srcPort>>8)|(srcPort<<8)))goto next;}
if(M2C_FIELD(entry,u32 *,CONN_REMOTE_IP)){
srcIpLo=M2C_FIELD(ipHeader,u16 *,IPH_SRC_IP_LO);srcIpHi=M2C_FIELD(ipHeader,u16 *,IPH_SRC_IP_HI);
if(M2C_FIELD(entry,u32 *,CONN_REMOTE_IP)!=(((u16)(((s32)srcIpHi>>8)|(srcIpHi<<8))<<16)|(u16)(((s32)srcIpLo>>8)|(srcIpLo<<8))))goto next;
}
return entry;
}
next: node=M2C_FIELD(node,void **,SOCK_OBJECT_NEXT);
}
return 0;
}

/* Whether the received TCP segment `segment` of the IP packet `ipHeader` belongs
 * to the connection `conn`: the segment's destination port must be the
 * connection's local port, and its source port and address the connection's
 * remote ones.  A UDP or ICMP socket never matches. */
s32 TcpConnectionMatchesSegment(void *ipHeader, void *segment, void *conn) {
    s32 matches, isTcp, portOk, peerOk;
    u16 dstPort, srcPort, srcIpHi, srcIpLo;
    u8 transport;

    transport = M2C_FIELD(conn, u8 *, SOCK_TRANSPORT);
    matches = 0;
    isTcp = 0;
    peerOk = 0;
    portOk = 0;
    if (transport != SOCK_KIND_UDP && transport != SOCK_KIND_ICMP) isTcp = 1;
    if (isTcp) {
        dstPort = M2C_FIELD(segment, u16 *, TCPH_DST_PORT);
        if (M2C_FIELD(conn, u16 *, CONN_LOCAL_PORT) == (u16)((dstPort >> 8) | (dstPort << 8))) portOk = 1;
    }
    if (portOk) {
        srcPort = M2C_FIELD(segment, u16 *, TCPH_SRC_PORT);
        if (M2C_FIELD(conn, u16 *, CONN_REMOTE_PORT) == (u16)((srcPort >> 8) | (srcPort << 8))) peerOk = 1;
    }
    if (peerOk) {
        srcIpHi = M2C_FIELD(ipHeader, u16 *, IPH_SRC_IP_HI);
        srcIpLo = M2C_FIELD(ipHeader, u16 *, IPH_SRC_IP_LO);
        if (M2C_FIELD(conn, u32 *, CONN_REMOTE_IP) == (((u16)((srcIpHi >> 8) | (srcIpHi << 8)) << 16) | (u16)((srcIpLo >> 8) | (srcIpLo << 8)))) matches = 1;
    }
    return matches;
}

