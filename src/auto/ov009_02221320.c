/* 15 functions from 0x02221320 to 0x022222D0 (ov009), found by ds-decomp. */
#include "common.h"
#include "ov009_link.h"
typedef struct PacketBits215a4 { u8 low:4; u8 high:4; } PacketBits215a4;
extern u8 gLinkState[];
static inline u16 SwapIME215a4(u16 value) { u16 old=*(volatile u16*)0x4000208;*(volatile u16*)0x4000208=value;return old; }
static inline s32 QueueCount215a4(void) { u16 old=SwapIME215a4(0);s32 count=0;if(!M2C_FIELD(gLinkState,s32*,0x64)){SwapIME215a4(old);return count;}count=M2C_FIELD(gLinkState,s32*,0x6c);SwapIME215a4(old);return count; }
static inline u16 QueueMask215a4(void) { u16 old=SwapIME215a4(0);u16 mask=0;s32 p=M2C_FIELD(gLinkState,s32*,0x64);if(!p){SwapIME215a4(old);return mask;}mask=M2C_FIELD(p,u16*,0xa);SwapIME215a4(old);return mask; }
static inline u32 HeadSize215a4(void) { u16 old=SwapIME215a4(0);u32 size=0;s32 p=M2C_FIELD(gLinkState,s32*,0x64);if(!p){SwapIME215a4(old);return size;}size=M2C_FIELD(p,u32*,0xc);SwapIME215a4(old);return size; }
static inline u32 QueueSize215a4(void) { u16 old=SwapIME215a4(0);u32 size=0;if(!M2C_FIELD(gLinkState,s32*,0x64)){SwapIME215a4(old);return size;}size=HeadSize215a4();SwapIME215a4(old);return size; }


void FreeLinkBlock(s32,s32);
static inline void PopQueue215a4(s32 packet) { s32 WriteLinkPacketHeader(s32,s32,u32,u32,s32,u32,u16);s32 p,next;u16 old;
old=SwapIME215a4(0);
p=M2C_FIELD(gLinkState,s32*,0x64);
if(!p){SwapIME215a4(old);return;}
{
WriteLinkPacketHeader(packet,M2C_FIELD(p,u8*,8),M2C_FIELD(p,PacketBits215a4*,9).low,M2C_FIELD(p,PacketBits215a4*,9).high,p+16,M2C_FIELD(p,u32*,12),M2C_FIELD(p,u16*,10));
next=M2C_FIELD(p,s32*,0);
M2C_FIELD(gLinkState,s32*,0x64)=next;
if(!next)M2C_FIELD(gLinkState,s32*,0x68)=0;
FreeLinkBlock(p,M2C_FIELD(p,u32*,12)+16);
M2C_FIELD(gLinkState,s32*,0x6c)--;
}
SwapIME215a4(old);
}

extern u8 gLinkSession[];
typedef struct Queue21ae8 {s32 head,tail,count;} Queue21ae8;
typedef struct Node21ae8 {s32 next;u32 header[3];} Node21ae8;
typedef struct Descriptor21ae8 {u32 word;u8 type;PacketBits215a4 flags;u16 mask;u32 length;} Descriptor21ae8;
typedef struct Receive21ae8 {u8 pad[0x34];struct {u32 offset;s32 packet;} channels[4];} Receive21ae8;
extern Queue21ae8 data_ov009_02226980[],data_ov009_022269b0[];
s32 func_ov009_0222132c(s32,s32);
s32 WriteLinkPacketHeader(s32,s32,u32,u32,s32,u32,u16);
#pragma opt_propagation off
#pragma opt_common_subs off
static inline u32 Head21ae8(Queue21ae8 *q){u16 old=SwapIME215a4(0);u32 n=0;s32 p=q->head;if(!p){SwapIME215a4(old);return n;}n=M2C_FIELD(p,u32 *,12);SwapIME215a4(old);return n;}
static inline u32 Size21ae8(u8 channel){u16 old=SwapIME215a4(0);u32 n=0;Queue21ae8 *q=&data_ov009_02226980[(s16)channel];if(!q->head){SwapIME215a4(old);return n;}n=Head21ae8(q)+12;SwapIME215a4(old);return n;}
static inline void Pop21ae8(u8 channel,s32 packet){s32 p,next;u32 old=SwapIME215a4(0);Queue21ae8 *q=&data_ov009_02226980[(s16)channel];p=q->head;if(!p){SwapIME215a4(old);return;}
WriteLinkPacketHeader(packet,M2C_FIELD(p,u8 *,8),M2C_FIELD(p,PacketBits215a4 *,9).low,M2C_FIELD(p,PacketBits215a4 *,9).high,p+16,M2C_FIELD(p,u32 *,12),M2C_FIELD(p,u16 *,10));
next=M2C_FIELD(p,s32 *,0);q->head=next;if(!next)q->tail=0;
FreeLinkBlock(p,M2C_FIELD(p,u32 *,12)+16);q->count--;SwapIME215a4(old);}
static inline void Push21ae8(Queue21ae8 *queue,s32 channel,s32 packet){s32 p;u32 old=SwapIME215a4(0);p=func_ov009_0222132c(M2C_FIELD(packet,u32 *,8)+16,32);if(!p){SwapIME215a4(old);return;}MI_CpuFill8(p,0,16);
WriteLinkPacketHeader(p+4,M2C_FIELD(packet,u8 *,4),M2C_FIELD(packet,PacketBits215a4 *,5).low,M2C_FIELD(packet,PacketBits215a4 *,5).high,packet+12,M2C_FIELD(packet,u32 *,8),M2C_FIELD(packet,u16 *,6));
if(!queue[channel].head){queue[channel].tail=p;queue[channel].head=p;}else {M2C_FIELD(p,s32 *,0)=queue[channel].head;queue[channel].head=p;}queue[channel].count++;SwapIME215a4(old);}

#pragma opt_common_subs reset
#pragma opt_propagation reset
void SetLinkPhase(void) {
    M2C_UNK SetLinkPhaseRaw();
    SetLinkPhaseRaw();
}

s32 func_ov009_0222132c(s32 size,s32 align) {
    M2C_UNK func_020e3580();
    return func_020e3580();
}

void FreeLinkBlock(s32 arg0, s32 arg1) {
    M2C_UNK HeapFreeBlock();
    if (arg0 == 0) {
        return;
    }
    HeapFreeBlock();
}

/* Reset a gLinkPlayers slot to its unset state: clear the 0x16-byte player
 * name, mark the slot not connected (flags 0, no player id) and set the state
 * bytes that follow the id to their unset values, then clear the 0x40-byte
 * record at +0x20.  InitLinkPlayerRecord is the same setup for a new player,
 * but returns the slot. */
void ResetLinkPlayerRecord(void *record) {
    M2C_UNK MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
    MI_CpuFill8(record, 0, 0x16);
    M2C_FIELD(record, s8 *, LINK_PLAYER_FLAGS) = 0;
    M2C_FIELD(record, s8 *, LINK_PLAYER_ID) = -1;
    M2C_FIELD(record, s8 *, LINK_PLAYER_RANK) = -1;
    M2C_FIELD(record, s8 *, LINK_PLAYER_FAV_GROUP) = -2;
    M2C_FIELD(record, s8 *, LINK_PLAYER_FAV_RECORD) = -2;
    M2C_FIELD(record, s8 *, 0x1B) = 0;
    M2C_FIELD(record, s8 *, 0x1C) = 0;
    M2C_FIELD(record, s8 *, 0x1D) = -1;
    MI_CpuFill8(record + 0x20, 0, 0x40);
}

/* Prepare a 0x60-byte gLinkPlayers slot for a new player: mark it not connected
 * with no player id, set the six state bytes that follow the id to their unset
 * values, then clear the slot's name area and the 0x40-byte record behind the
 * state bytes; returns the slot. */
void *InitLinkPlayerRecord(void *record) {
    M2C_FIELD(record, s8 *, LINK_PLAYER_FLAGS) = 0;
    M2C_FIELD(record, s8 *, LINK_PLAYER_ID) = -1;
    M2C_FIELD(record, s8 *, 0x18) = -1;
    M2C_FIELD(record, s8 *, 0x19) = -2;
    M2C_FIELD(record, s8 *, 0x1A) = -2;
    M2C_FIELD(record, s8 *, 0x1B) = 0;
    M2C_FIELD(record, s8 *, 0x1C) = 0;
    M2C_FIELD(record, s8 *, 0x1D) = -1;
    MI_CpuFill8(record, 0, 0x16);
    MI_CpuFill8(record + 0x20, 0, 0x40);
    return record;
}

void func_ov009_022213f0(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK CopyU16(M2C_UNK, M2C_UNK, M2C_UNK);
    CopyU16(arg1, arg0, 0x14);
}

void CopyLinkPlayerRecordPayload(s32 arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK MI_CpuCopy8();
    MI_CpuCopy8(arg1, arg0 + 0x20, arg2);
}

/* Per-frame keep-alive for the Download Play link: every ~240 frames queue a
 * type-1 keep-alive packet (carrying the current send counter) to all connected
 * peers, then age each remote peer's last-heard counter and let the link actor
 * drop the session once a peer has gone too long without reporting in. */
void func_ov009_02221424(void *arg0) {
 s32 FX_Div(s32,s32);
 s32 Divide(s32,s32);
 s32 IsLinkPacketQueued(s32);
 M2C_UNK func_ov009_02223a24(u8);
 s32 GetConnectedPlayers();
 M2C_UNK QueueLinkPacket(s32,void *,s32,u16);
 s32 GetLinkLocalPlayerId();
 s32 elapsed,count,timeoutLimit,connected; u16 peers; u8 player;
 elapsed=FX_Div(0x3e8000,0x3c000);
 count=M2C_FIELD(arg0,s32 *,0x38)+1;
 elapsed=(count*elapsed)>>12;
 M2C_FIELD(arg0,s32 *,0x38)=count;
 if(elapsed>4000) {
 connected=GetConnectedPlayers();
 peers=connected & (-1 ^ (1U<<GetLinkLocalPlayerId()));
 if(peers && (peers & GetConnectedPlayers()) && !IsLinkPacketQueued(1))
 QueueLinkPacket(1,arg0+0x38,4,peers);
 M2C_FIELD(arg0,s32 *,0x38)=0;
 }
 timeoutLimit=Divide(0x1b7740,1000);
 player=0;
 do {
 if(player!=GetLinkLocalPlayerId() && (GetConnectedPlayers() & (1<<player))) {
 { void *entry=arg0+player*4;
 count=M2C_FIELD(entry,s32 *,0x3c)+1;
 M2C_FIELD(entry,s32 *,0x3c)=count; }
 if(count>timeoutLimit) {func_ov009_02223a24(player); ((s32 *)(arg0+0x3c))[player]=0;}
 }else ((s32 *)(arg0+0x3c))[player]=0;
 player++;
 }while(player<4);
}

/* Completion handler of a link channel transfer: report the peers whose transfer is
 * still outstanding to the live link sender (cleared outright when the end channel
 * reports its done result), then hand the completed packet on to the link. */
void HandleLinkSendComplete(void *completion) {
    void *FindObjectByClass(M2C_UNK *);
    M2C_UNK DeliverLinkSendResult(void *);
    extern M2C_UNK gLinkSenderClass;
    void *sender;

    sender = FindObjectByClass(&gLinkSenderClass);
    if (sender != NULL) {
        if ((M2C_FIELD(completion, u16 *, LINK_SEND_EVENT_CHANNEL) == LINK_SEND_END_CHANNEL) && (M2C_FIELD(completion, u16 *, LINK_SEND_EVENT_RESULT) == LINK_SEND_RESULT_DONE)) {
            M2C_FIELD(sender, u16 *, LINK_SENDER_OUTSTANDING) = 0U;
        } else {
            M2C_FIELD(sender, u16 *, LINK_SENDER_OUTSTANDING) = (u16) M2C_FIELD(completion, u16 *, LINK_SEND_EVENT_PEERS);
        }
    }
    DeliverLinkSendResult(completion);
}

void func_ov009_02221580(void *arg0) {
    FreeLinkBlock(M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40));
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
}

#pragma opt_propagation off
#pragma opt_common_subs off
void func_ov009_022215a4(void *arg0){
s32 GetLinkPhase(void);
s32 GetLinkLocalPlayerId(void);
s32 func_ov009_02224d0c(u32);
s32 WriteLinkPacketHeader(s32,s32,u32,u32,s32,u32,u16);
s32 p,packet,count,i,me;
u32 length;
u16 old;
s32 mask;
void (*callback)(u16,s32);
if(GetLinkPhase()!=4 && GetLinkPhase()!=5)return;
me=GetLinkLocalPlayerId();
if(!M2C_FIELD(arg0,s32*,0x38)){
count=QueueCount215a4();if(!count)return;
}
p=M2C_FIELD(arg0,s32*,0x38);
if(p){
M2C_FIELD(arg0,u16*,0x44)=M2C_FIELD(p,u16*,6);
M2C_FIELD(arg0,u16*,0x44)&=GetConnectedPlayers();
i=0;do{if(me!=i && (M2C_FIELD(arg0,u16*,0x44)&(1<<i)) && (M2C_FIELD(arg0,u16*,0x46)&(1<<i)))return;i++;}while(i<4);
if(M2C_FIELD(arg0,u32*,0x34)!=M2C_FIELD(M2C_FIELD(arg0,s32*,0x38),u32*,8)){
length=M2C_FIELD(M2C_FIELD(arg0,s32*,0x38),u32*,8)-M2C_FIELD(arg0,u32*,0x34);
if(length>180)length=180;
packet=func_ov009_02224d0c(length+12);
p=M2C_FIELD(arg0,s32*,0x38);
WriteLinkPacketHeader(packet,9,M2C_FIELD(p,PacketBits215a4*,5).low,M2C_FIELD(p,PacketBits215a4*,5).high,p+12+M2C_FIELD(arg0,u32*,0x34),length,M2C_FIELD(p,u16*,6));
M2C_FIELD(arg0,u32*,0x34)+=length;
M2C_FIELD(arg0,s32*,0x3c)=packet;
M2C_FIELD(arg0,u32*,0x40)=M2C_FIELD(packet,u32*,8)+12;
}else{
packet=func_ov009_02224d0c(12);
p=M2C_FIELD(arg0,s32*,0x38);
WriteLinkPacketHeader(packet,10,M2C_FIELD(p,PacketBits215a4*,5).low,M2C_FIELD(p,PacketBits215a4*,5).high,0,0,M2C_FIELD(p,u16*,6));
M2C_FIELD(arg0,s32*,0x3c)=packet;
M2C_FIELD(arg0,u32*,0x40)=M2C_FIELD(packet,u32*,8)+12;
M2C_FIELD(arg0,u32*,0x34)=0;
p=M2C_FIELD(arg0,s32*,0x38);
if(p){FreeLinkPacket(p);M2C_FIELD(arg0,s32*,0x38)=0;}
func_ov009_02224cd8();
}
}else{
M2C_FIELD(arg0,u16*,0x44)=QueueMask215a4();
M2C_FIELD(arg0,u16*,0x44)&=GetConnectedPlayers();
for(i=0;i<4;i++)if(me!=i && (M2C_FIELD(arg0,u16*,0x44)&(1<<i)) && (M2C_FIELD(arg0,u16*,0x46)&(1<<i)))return;
length=QueueSize215a4()+12;
M2C_FIELD(arg0,u32*,0x40)=length;
packet=func_ov009_02224d0c(length);
M2C_FIELD(arg0,s32*,0x3c)=packet;
PopQueue215a4(packet);
if(M2C_FIELD(arg0,u32*,0x40)>192){
func_ov009_02224ca4();
p=M2C_FIELD(arg0,s32*,0x3c);
M2C_FIELD(arg0,u32*,0x34)=0;
M2C_FIELD(arg0,s32*,0x38)=p;
packet=func_ov009_02224d0c(24);
p=M2C_FIELD(arg0,s32*,0x38);
WriteLinkPacketHeader(packet,8,M2C_FIELD(p,PacketBits215a4*,5).low,M2C_FIELD(p,PacketBits215a4*,5).high,p,12,M2C_FIELD(p,u16*,6));
M2C_FIELD(arg0,s32*,0x3c)=packet;
M2C_FIELD(arg0,u32*,0x40)=M2C_FIELD(packet,u32*,8)+12;
}
}
callback=M2C_FIELD(gLinkState,void(**)(u16,s32),0x18);
if(callback)callback(M2C_FIELD(arg0,u16*,0x44),M2C_FIELD(arg0,s32*,0x3c));
mask=1<<me;
if(M2C_FIELD(arg0,u16*,0x44)&(1<<me)){
DispatchLinkPacket(M2C_FIELD(arg0,s32*,0x3c),M2C_FIELD(arg0,u32*,0x40),(u16)mask);
HandleLinkChannelCommand(21,(u8)me,M2C_FIELD(arg0,s32*,0x3c),M2C_FIELD(arg0,u32*,0x40));
}
M2C_FIELD(arg0,u16*,0x44)&=(-1 ^ mask);
if(M2C_FIELD(arg0,u16*,0x44)){
M2C_FIELD(arg0,u16*,0x46)=M2C_FIELD(arg0,u16*,0x44);
packet=M2C_FIELD(arg0,s32*,0x3c);
switch(M2C_FIELD(packet,PacketBits215a4*,5).high){
case 0:SendLinkChannelData(12,M2C_FIELD(arg0,u16*,0x44),packet,(u16)M2C_FIELD(arg0,u32*,0x40),HandleLinkSendComplete);break;
case 1:SendLinkChannelData(4,M2C_FIELD(arg0,u16*,0x44),packet,(u16)M2C_FIELD(arg0,u32*,0x40),HandleLinkSendComplete);break;
}
Sprite_ResumeAnimation(arg0);
}else{
FreeLinkPacket(M2C_FIELD(arg0,s32*,0x3c));
M2C_FIELD(arg0,s32*,0x3c)=0;M2C_FIELD(arg0,u32*,0x40)=0;
}
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
/* Send-completion step of the link actor: while any peer the packet was
 * addressed to still has its transfer outstanding (bits in both +0x44 and
 * +0x46) it waits; once none is left it frees the sent packet, clears the send
 * state and resumes the sender sprite's animation. */
void CompleteLinkSend(void *sender) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK FreeLinkPacket(s32);
    s32 peer;

    peer = 0;
loop:
    if ((M2C_FIELD(sender, u16 *, 0x44) & (1 << peer)) && (M2C_FIELD(sender, u16 *, 0x46) & (1 << peer))) {
        return;
    }
    peer += 1;
    if (peer >= 4) {
        FreeLinkPacket(M2C_FIELD(sender, s32 *, 0x3C));
        M2C_FIELD(sender, s32 *, 0x3C) = 0;
        M2C_FIELD(sender, s32 *, 0x40) = 0;
        Sprite_ResumeAnimation(sender);
        return;
    }
    goto loop;
}

#pragma opt_lifetimes off
void func_ov009_02221ae8(Receive21ae8 *state){
s32 GetLinkPhase(void);s32 func_ov009_02224d0c(u32);M2C_UNK FreeLinkPacket(s32);
s32 IsLinkHost(void);s32 QueueHostLinkPacket(s32,s32,s32,u16);s32 ClearPlayerActive(s32,s32,s32,u8,s32);
s32 SetConnectedPlayers(u16);s32 GetConnectedPlayers(void);s32 func_ov009_02224ca4(void);s32 func_ov009_02224cd8(void);
M2C_UNK MI_CpuCopy8();void SetLinkPlayerRecord(s32,M2C_UNK);
s32 GetLinkLocalPlayerId(void);s32 GetLinkPlayerSlot(void);s32 GetBattleSaveBlock(void);s32 func_020c5640(s32);s32 SetBattleSlotRecord(s32,s32);s32 SendLinkPlayerInfo(u8);
u32 func_ov009_022250f8(u8);s32 func_ov009_02225178(u8,s32);
s32 i,packet,channel,n,value,keep;u8 *p;u32 size;Descriptor21ae8 desc;s32 (*callback)(u8,s32);
if(GetLinkPhase()!=4 && GetLinkPhase()!=5)return;
for(i=0;i<4;i++){
size=Size21ae8((u8)i);if(!size)continue;
keep=1;packet=func_ov009_02224d0c(size);Pop21ae8((u8)i,packet);
channel=M2C_FIELD(packet,PacketBits215a4 *,5).low;
switch(M2C_FIELD(packet,u8 *,4)){
case 2:
value=IsLinkHost();p=M2C_FIELD(gLinkState,s32 *,0x48);
if(value){if(p && M2C_FIELD(p,u32 *,0)==M2C_FIELD(packet,u32 *,12))QueueHostLinkPacket(2,p,8,(u16)(1<<channel));}
else if(p && M2C_FIELD(p,u32 *,0)==M2C_FIELD(packet,u32 *,12))QueueHostLinkPacket(3,p,8,(u16)(1<<channel));
else QueueHostLinkPacket(2,packet+12,8,(u16)(1<<channel));break;
case 3:
value=IsLinkHost();p=M2C_FIELD(gLinkState,s32 *,0x48);
if(value){if(p && M2C_FIELD(p,u32 *,0)==M2C_FIELD(packet,u32 *,12))M2C_FIELD(p,u16 *,4)|=1<<channel;}
else if(p && M2C_FIELD(p,u32 *,0)==M2C_FIELD(packet,u32 *,12))M2C_FIELD(p,u16 *,4)=0xffff;break;
case 4:
ClearPlayerActive(M2C_FIELD(packet,s32 *,12),M2C_FIELD(packet,s32 *,16),M2C_FIELD(packet,s32 *,20),M2C_FIELD(packet,u8 *,24),0);break;
case 5:
QueueHostLinkPacket(6,(s32)gLinkSession,2,(u16)(1<<channel));break;
case 6:
SetConnectedPlayers(M2C_FIELD(packet,u16 *,12));p=M2C_FIELD(gLinkState,s32 *,0x24);
if(p){M2C_FIELD(p,u8 *,0)=1;M2C_FIELD(M2C_FIELD(gLinkState,s32 *,0x24),u16 *,2)=GetConnectedPlayers();}break;
case 7:SetConnectedPlayers(M2C_FIELD(packet,u16 *,12));break;
case 8:
func_ov009_02224ca4();MI_CpuCopy8(packet+12,&desc,12);p=func_ov009_02224d0c(desc.length+12);
WriteLinkPacketHeader(p,desc.type,desc.flags.low,desc.flags.high,0,desc.length,desc.mask);
state->channels[channel].offset=0;state->channels[channel].packet=p;break;
case 9:
n=M2C_FIELD(packet,u32 *,8);p=state->channels[channel].packet;
MI_CpuCopy8(packet+12,p+12+state->channels[channel].offset,n);state->channels[channel].offset+=n;break;
case 10:
p=state->channels[channel].packet;
if(M2C_FIELD(p,u8 *,4)<16)Push21ae8(data_ov009_02226980,channel,p);else Push21ae8(data_ov009_022269b0,channel,p);
state->channels[channel].offset=0;p=state->channels[channel].packet;
if(p){FreeLinkPacket(p);state->channels[channel].packet=0;}func_ov009_02224cd8();break;
case 11:
SetLinkPlayerRecord((u8)channel,packet+12);GetLinkLocalPlayerId();p=GetLinkPlayerSlot();QueueHostLinkPacket(12,p,96,(u16)(1<<channel));break;
case 12:
SetLinkPlayerRecord((u8)channel,packet+12);p=M2C_FIELD(gLinkState,s32 *,32);if(p)M2C_FIELD(p,u16 *,2)|=1<<channel;break;
case 13:
if(GetBattleSaveBlock()){value=func_020c5640(packet+12);if(value>=0)SetBattleSlotRecord(value,packet+24);SendLinkPlayerInfo((u8)channel);}
else QueueHostLinkPacket(14,0,0,0xffff);break;
case 14:
p=M2C_FIELD(gLinkState,s32 *,40);if(p)M2C_FIELD(p,u16 *,0)|=1<<channel;break;
case 15:
if(GetBattleSaveBlock()){value=func_020c5640(packet+12);if(value>=0)SetBattleSlotRecord(value,packet+24);}
p=M2C_FIELD(gLinkState,s32 *,40);if(p)M2C_FIELD(p,u16 *,0)|=1<<channel;break;
}
callback=M2C_FIELD(gLinkState,s32 (**)(u8,s32),0x44);if(callback)keep=callback((u8)channel,packet);
if(keep)FreeLinkPacket(packet);
}
if(M2C_FIELD(gLinkState,s32 *,0x54)){
for(i=0;i<4;i++){
size=func_ov009_022250f8((u8)i);if(size){
keep=1;packet=func_ov009_02224d0c(size);func_ov009_02225178((u8)i,packet);
channel=M2C_FIELD(packet,PacketBits215a4 *,5).low;
callback=M2C_FIELD(gLinkState,s32 (**)(u8,s32),0x54);if(callback)keep=callback((u8)channel,packet);if(keep)FreeLinkPacket(packet);
}}
}
}
#pragma opt_lifetimes reset
void SetLinkPlayerRecord(s32 arg0, M2C_UNK arg1) {
    M2C_UNK MI_CpuCopy8(M2C_UNK, s32);
    extern M2C_UNK gLinkPlayers;
    MI_CpuCopy8(arg1, (arg0 * 0x60) + (s32) &gLinkPlayers);
}

s32 func_ov009_0222229c(s32 arg0, s32 arg1) {
    s32 GetLinkPhase();
    switch (GetLinkPhase()) {
    case 8:
    case 9:
        return 0;
    default:
        return arg1 != GetLinkPhase();
    }
}

