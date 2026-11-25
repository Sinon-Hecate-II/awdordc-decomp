/* 14 functions from 0x022221B8 to 0x02223114 (ov010), found by ds-decomp. */
#include "common.h"

typedef struct UnkOv010Header { s16 unk0; u8 unk2; u8 unk3; } UnkOv010Header;

static inline u8 Encode2BitSample(s16 sample,UnkOv010Header *state) {
 extern s16 gAdpcmStepTable[];
 extern s8 gAdpcmIndexTable2[];
 s32 index=state->unk2,pred=state->unk0,step=gAdpcmStepTable[index],diff=sample-pred,code;
 if(diff<0){code=2;diff=-diff;}else code=0;
 if(diff>=step)code|=1;
 if(!(code&1))step=0;
 if(code&2)step=-step;
 pred+=step;
 if(pred < -32768)pred=-32768;
 if(pred > 32767)pred=32767;
 index+=gAdpcmIndexTable2[code];
 if(index<0)index=0;else if(index>88)index=88;
 state->unk0=pred;state->unk2=index;
 return code;
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
void EncodeAdpcm2Bit(void *arg0,s32 arg1,s32 arg2,void *arg3){
u32 i,n=(u32)arg2>>2;u8 packed;u8 *out=arg0;s16 *in=(s16*)arg1;
i=0;if(!n)return;do{
packed=Encode2BitSample(in[0],arg3);
packed|=Encode2BitSample(in[1],arg3)<<2;
packed|=Encode2BitSample(in[2],arg3)<<4;
packed|=Encode2BitSample(in[3],arg3)<<6;
*out++=packed;in+=4;i++;
}while(i<n);
}
#pragma pop
/* Decode one voice-chat packet: read the ADPCM codec state from the packet's
 * 4-byte header (predicted sample at +0x00, step-table index at +0x02) and decode
 * the payload after it with the codec named by `codecMode` (VOICE_CODEC_*). */
void VoiceChat_DecodePacket(void *packet,s32 samples,s32 payloadBytes,s32 codecMode) {
void DecodeAdpcm2Bit(void *,s32,s32,UnkOv010Header *);
void DecodeAdpcm3Bit(void *,s32,s32,UnkOv010Header *);
void DecodeAdpcm4Bit(void *,s32,s32,UnkOv010Header *);
UnkOv010Header codecState;
codecState.unk0=M2C_FIELD(packet,s16 *,0);
codecState.unk2=M2C_FIELD(packet,u8 *,2);
switch(codecMode) {
case VOICE_CODEC_ADPCM2: DecodeAdpcm2Bit((u8 *)packet+4,samples,payloadBytes-4,&codecState); return;
case VOICE_CODEC_ADPCM3: DecodeAdpcm3Bit((u8 *)packet+4,samples,payloadBytes-4,&codecState); return;
case VOICE_CODEC_ADPCM4: DecodeAdpcm4Bit((u8 *)packet+4,samples,payloadBytes-4,&codecState); return;
}
}

/* Build a voice audio packet: copy the codec state into the packet's 4-byte
 * ADPCM header and encode `sampleCount` samples into the body with the encoder
 * for `codecMode` (VOICE_CODEC_ADPCM2/3/4). */
void VoiceChat_EncodePacket(void *packet,s32 samples,s32 sampleCount,void *codecState,s32 codecMode) {
void EncodeAdpcm2Bit(void *,s32,s32,void *);
void EncodeAdpcm3Bit(void *,s32,s32,void *);
void EncodeAdpcm4Bit(void *,s32,s32,void *);
M2C_FIELD(packet,s16 *,VOICE_ADPCM_PREDICTOR)=M2C_FIELD(codecState,s16 *,VOICE_ADPCM_PREDICTOR);
M2C_FIELD(packet,u8 *,VOICE_ADPCM_STEP_INDEX)=M2C_FIELD(codecState,u8 *,VOICE_ADPCM_STEP_INDEX);
M2C_FIELD(packet,u8 *,VOICE_ADPCM_RESERVED)=0;
switch(codecMode) {
case VOICE_CODEC_ADPCM2: EncodeAdpcm2Bit((u8 *)packet+4,samples,sampleCount,codecState); return;
case VOICE_CODEC_ADPCM3: EncodeAdpcm3Bit((u8 *)packet+4,samples,sampleCount,codecState); return;
case VOICE_CODEC_ADPCM4: EncodeAdpcm4Bit((u8 *)packet+4,samples,sampleCount,codecState); return;
}
}

#pragma opt_strength_reduction off
s32 func_ov010_022224b4(void){
s32 func_020070a4(void); void func_ov010_02225174(void);void func_ov010_02223654(u32);void Link_InitChannelState(void *,u32,s32);void Link_InitPendingPackets(void);void VoiceCodec_ResetState(void);
extern M2C_UNK gVoiceChatState,data_ov010_0222c000,gLinkConfig;extern u8 gVoiceModePayloadUnits[];extern void *gVoiceChatContexts[];extern u8 gLinkChannelStates[];
s32 i; s32 saved; s32 n, x, y; u8 *t;
saved=func_020070a4();
M2C_FIELD(&gVoiceChatState,u16 *,0)=saved; data_ov010_0222c000=1;
M2C_FIELD(&gVoiceChatState,s32 *,0x20)=0;
M2C_FIELD(&gVoiceChatState,s32 *,4)=0;
if(M2C_FIELD(&gLinkConfig,s32 *,16)==1)M2C_FIELD(&gVoiceChatState,s32 *,0x1c)=0;
else M2C_FIELD(&gVoiceChatState,s32 *,0x1c)=4;
M2C_FIELD(&gVoiceChatState,s32 *,0x24)=0x440;
n=M2C_FIELD(&gVoiceChatState,s32 *,0x1c) * 2;
t=&gVoiceModePayloadUnits[n];
x=t[1];
y=gVoiceModePayloadUnits[n];
M2C_FIELD(&gVoiceChatState,s32 *,12)=x+y*68+12;
M2C_FIELD(&gVoiceChatState,s32 *,3840)=0;
M2C_FIELD(&gVoiceChatState,s32 *,3844)=0;
M2C_FIELD(&gVoiceChatState,s32 *,3852)=0;
M2C_FIELD(&gVoiceChatState,s32 *,3848)=0;
M2C_FIELD(&gVoiceChatState,s32 *,3856)=0;
M2C_FIELD(&gVoiceChatState,s32 *,3860)=0;
func_ov010_02225174();
i=0;goto test;loop:{gVoiceChatContexts[i]=0;func_ov010_02223654(i);Link_InitChannelState(gLinkChannelStates+i*0x94,i,-1);i++;}test:if((u32)i<3)goto loop;
Link_InitPendingPackets();VoiceCodec_ResetState();return 1;
}
#pragma opt_strength_reduction reset
void func_ov010_022225b0(s32 arg0) {
    extern M2C_UNK gVoiceChatState;
    M2C_FIELD(&gVoiceChatState, void **, 0x20) = NULL;
}

#pragma optimization_level 2
/* Attach a voice-exchange context (VoiceLinkContext: +5 packet peer id, +8 peer
 * mask, +0xC protocol step) to the voice chat.  Reject when three contexts are
 * already attached or the context is not at step 2 or 3; reuse the context if it
 * is already attached, otherwise take a free one of the three slots, OR its peer
 * mask into the aggregate mask and initialise the matching link channel.  The
 * first step-2 context starts the voice stream and clears its statistics.
 * Returns 1 when the context is attached. */
s32 VoiceChat_AttachContext(void *p)
{
    void Link_InitChannelState(void*,u32,s32);
    void func_ov010_02223654(u32);
    void func_ov010_02224f28(void);
    s32 func_020070a4(void);
    extern s32 gVoiceChatState;
    extern void *gVoiceChatContexts[];
    extern u8 gLinkChannelStates[];
    s32 i;
    s32 *state;
    void *channel;
    u32 oldMask, newMask;

    if (!p) return 0;
    if (M2C_FIELD(&gVoiceChatState,s32*,VOICE_CHAT_CONTEXT_COUNT) == VOICE_CHAT_CONTEXT_MAX) return 0;
    if (M2C_FIELD(p,s32*,12) != 2 && M2C_FIELD(p,s32*,12) != 3) return 0;
    i = 0;
    goto checkExisting;
existing:
    if (gVoiceChatContexts[i] == p) return 1;
    i++;
checkExisting:
    if ((u32)i < VOICE_CHAT_CONTEXT_MAX) goto existing;
    i = 0;
    goto checkFree;
freeSlot:
    if (!gVoiceChatContexts[i]) {
        gVoiceChatContexts[i] = p;
        goto found;
    }
    i++;
checkFree:
    if ((u32)i < VOICE_CHAT_CONTEXT_MAX) goto freeSlot;
found:
    state = &gVoiceChatState;
    channel = gLinkChannelStates + i * LINK_CHANNEL_STRIDE;
    state[8]++;
    oldMask = (u32)state[1];
    newMask = M2C_FIELD(p,u32*,8);
    state[1] = oldMask | newMask;
    Link_InitChannelState(channel,i,M2C_FIELD(p,u8*,5));
    func_ov010_02223654(i);
    if (M2C_FIELD(p,s32*,12) != 2) return 1;
    if (M2C_FIELD(&gVoiceChatState,s32*,VOICE_CHAT_CONTEXT_COUNT) == 1) {
        func_ov010_02224f28();
        M2C_FIELD(&gVoiceChatState,u16*,VOICE_CHAT_STREAM_TICK) = func_020070a4();
        M2C_FIELD(&gVoiceChatState,u16*,VOICE_CHAT_ADPCM_PREDICTOR) = 0;
        M2C_FIELD(&gVoiceChatState,u8*,VOICE_CHAT_ADPCM_STEP_INDEX) = 0;
        M2C_FIELD(&gVoiceChatState,s32*,VOICE_CHAT_ACTIVE) = 1;
        M2C_FIELD(&gVoiceChatState,s32*,VOICE_CHAT_STREAM_STATS + 0x00) = 0;
        M2C_FIELD(&gVoiceChatState,s32*,VOICE_CHAT_STREAM_STATS + 0x04) = 0;
        M2C_FIELD(&gVoiceChatState,s32*,VOICE_CHAT_STREAM_STATS + 0x0C) = 0;
        M2C_FIELD(&gVoiceChatState,s32*,VOICE_CHAT_STREAM_STATS + 0x08) = 0;
        M2C_FIELD(&gVoiceChatState,s32*,VOICE_CHAT_STREAM_STATS + 0x10) = 0;
        M2C_FIELD(&gVoiceChatState,s32*,VOICE_CHAT_STREAM_STATS + 0x14) = 0;
    }
    return 1;
}
#pragma optimization_level reset
void VoiceChat_RemoveChannel(void *arg0) {
extern void *gVoiceChatContexts[]; extern u8 gLinkChannelStates[]; extern M2C_UNK gVoiceChatState;
void func_ov010_022239c8(void *); void Link_FreeChannelQueuedPackets(u32); void Link_FreeChannelPendingPackets(u32); void func_ov010_02224f28(void);
u32 i;
for(i=0;i<3;i++) {
if(gVoiceChatContexts[i]==arg0) {
void *channel = gLinkChannelStates + i * 0x94;
s32 count=M2C_FIELD(&gVoiceChatState,s32 *,0x20);
void *empty = 0;
gVoiceChatContexts[i]=empty;
M2C_FIELD(&gVoiceChatState,s32 *,0x20)=count-1;
func_ov010_022239c8(channel);
Link_FreeChannelQueuedPackets(i);
Link_FreeChannelPendingPackets(i);
{
    u32 *state = (u32 *)&gVoiceChatState;
    u32 flags = state[1];
    u32 mask = M2C_FIELD(arg0,u32 *,8);
    mask = ~mask;
    mask &= flags;
    state[1] = mask;
}
break;
}
}
if(M2C_FIELD(&gVoiceChatState,s32 *,0x20)!=0) return;
{
M2C_FIELD(&gVoiceChatState,s32 *,0x14)=1;
func_ov010_02224f28();
M2C_FIELD(&gVoiceChatState,s32 *,4)=0;
}
}

#pragma push
#pragma opt_strength_reduction off
s32 VoiceStream_SendAudio(void *src,s32 len){
extern M2C_UNK gVoiceChatState; extern void *gVoiceChatContexts[];extern u8 gLinkPacketBuffers[];
void MI_CpuCopy32(void *,void *,s32);s64 GetSystemTick(void);s32 U64Divide(s64,s32,s32);
u32 i; s32 found=0; s32 off;u8 *p;u16 n;s32 mode;u32 magic=0x5f564354;
if(len!=M2C_FIELD(&gVoiceChatState,s32 *,0x24))return found;
if(!M2C_FIELD(&gVoiceChatState,s32 *,0x20))return found;
{i=0;goto test;loop:{if(gVoiceChatContexts[i] && M2C_FIELD(gVoiceChatContexts[i],s32 *,12)==2){found=1;goto done;}i++;}test:if((u32)i<3)goto loop;done:;}
if(!found)return 0;
p=gLinkPacketBuffers;
off = (M2C_FIELD(&gVoiceChatState,u32 *,0xf04)&1) ? 0 : 0x460;
mode=M2C_FIELD(&gVoiceChatState,s32 *,0x1c);
M2C_FIELD(p+off,u32 *,0)=magic;
p=(u8 *)((u32)p+off);
if(mode>=2)MI_CpuCopy32(src,p+16,len);else MI_CpuCopy32(src,p+12,len);
n=M2C_FIELD(&gVoiceChatState,u16 *,0);
M2C_FIELD(p,u8 *,4)=64;
M2C_FIELD(&gVoiceChatState,u16 *,0)=n+1;
M2C_FIELD(p,u16 *,6)=n;
M2C_FIELD(p,s32 *,8)=U64Divide(GetSystemTick(),64,0);
{u32 count=M2C_FIELD(&gVoiceChatState,u32 *,0xf04);M2C_FIELD(&gVoiceChatState,s32 *,0xf04)=count+1;}
return 1;
}
/* Pulls the next queued packet for one link channel and plays it into `dst`:
 * keeps the channel's playback clock in step with the packet timestamps, skips
 * packets that arrived too late, and reports the packet's player bit in `flag`.
 * Returns 1 when a packet was delivered. */
s32 Link_PullChannelPacket(void *dst,s32 size,u32 channel,s32 *flag){
s32 Link_GetQueueCount(s32);
s64 GetSystemTick(void);
void *Link_PeekPacket(s32);
s32 Link_AdvancePacket(void *,void *);
void MI_CpuCopy32(void *,void *,s32);
void Link_FreePacket(void *);
extern u8 gLinkChannelStates[];
s32 count;
void *packet;
void *state=gLinkChannelStates+channel*LINK_CHANNEL_STRIDE;
s32 first=1;
u64 now;
count=Link_GetQueueCount(channel);
while(count!=0){
now=GetSystemTick();
packet=Link_PeekPacket(channel);
if(!packet)goto empty;
if(M2C_FIELD(packet,u64 *,0x46c)>now+0x34){
if(M2C_FIELD(packet,s32 *,0x45c)==0 && M2C_FIELD(state,void **,0x3c)!=0){
M2C_FIELD(state,s32 *,0x20)++;
MI_CpuCopy32(M2C_FIELD(M2C_FIELD(state,void **,0x3c),void **,0x474),dst,size);
Link_FreePacket(M2C_FIELD(state,void **,0x3c));
M2C_FIELD(state,void **,0x3c)=0;
if(flag)*flag|=1<<M2C_FIELD(packet,u8 *,0x10);
return 1;
}
return 0;
}
if(now>M2C_FIELD(packet,u64 *,0x46c)+0x8b4c){
M2C_FIELD(state,u32 *,0x58)=M2C_FIELD(packet,u32 *,0x18);
count=Link_AdvancePacket(state,packet);
Link_PeekPacket(channel);
first=0;
}else{

if(M2C_FIELD(state,u32 *,0x58)+1!=M2C_FIELD(packet,u32 *,0x18) && M2C_FIELD(state,u32 *,0x58)!=0 && M2C_FIELD(state,u32 *,0x58)<=M2C_FIELD(packet,u32 *,0x18)){
if(M2C_FIELD(packet,s32 *,0x45c)==0)M2C_FIELD(state,s32 *,0x14)++;
}
M2C_FIELD(state,u32 *,0x58)=M2C_FIELD(packet,u32 *,0x18);
if(first && M2C_FIELD(state,s32 *,0x70)){
count=Link_AdvancePacket(state,packet);
Link_PeekPacket(channel);
M2C_FIELD(state,s32 *,0x70)--;
}else{
u32 t=(u32)(now-M2C_FIELD(packet,u64 *,0x464));
u32 x=M2C_FIELD(state,u32 *,0x28);
u32 z=t-x;
M2C_FIELD(state,u32 *,0x28)=t;
z-=M2C_FIELD(state,u32 *,0x28);
{u32 smooth=t+(z>>4);M2C_FIELD(state,u32 *,0x2c)=smooth;M2C_FIELD(state,u32 *,0)=smooth;}
MI_CpuCopy32(M2C_FIELD(packet,void **,0x474),dst,size);
Link_AdvancePacket(state,packet);
if(flag)*flag|=1<<M2C_FIELD(packet,u8 *,0x10);
return 1;
}
}
continue;
empty:
M2C_FIELD(state,s32 *,8)=count;return 0;
}
if(M2C_FIELD(state,void **,0x3c)){Link_FreePacket(M2C_FIELD(state,void **,0x3c));M2C_FIELD(state,void **,0x3c)=0;}
return 0;
}
#pragma optimization_level reset
/* Receive one link packet of packetSize bytes into buffer: try each of the three
 * channels in turn; when one delivers, pull the other channels' queued packets into a
 * scratch buffer and merge them into the same packet. `players` collects the bits of
 * the players whose packets were used. Returns 1 when a packet was received. */
s32 VoiceStream_ReceiveAudio(void *buffer,s32 packetSize,s32 *players){
s32 Link_PullChannelPacket(void*,s32,u32,s32*);
void func_ov010_02225558(void*,void*,void*,s32);
void MI_CpuFill32(s32,void*,s32);
void func_ov010_02225304(void*,s32);
extern s32 gVoiceChatState;
extern u8 data_ov010_0222cb54[];
s32 received;u32 channel,nextChannel;
if(players)*players=0;
received=0;
if(packetSize==M2C_FIELD(&gVoiceChatState,s32*,0x24)&&M2C_FIELD(&gVoiceChatState,s32*,0x20)){
for(channel=0;channel<3;channel++){
if(Link_PullChannelPacket(buffer,packetSize,channel,players)==1){received=1;break;}
}
if(received){
nextChannel=channel+1;
if(nextChannel==3)received=1;
else for(;nextChannel<3;nextChannel++){
if(Link_PullChannelPacket(data_ov010_0222cb54,packetSize,nextChannel,players)==1)
func_ov010_02225558(buffer,data_ov010_0222cb54,buffer,packetSize);
}
}else MI_CpuFill32(0,buffer,packetSize);
}else{MI_CpuFill32(0,buffer,packetSize);received=0;}
if(M2C_FIELD(&gVoiceChatState,s32*,0x18))func_ov010_02225304(buffer,packetSize);
return received;
}

#pragma pop
/* Selects the voice codec, records its wire packet size and resets the ADPCM encoder state. */
s32 VoiceChat_SetCodecMode(s32 codecMode) {
    extern M2C_UNK gLinkConfig;
    extern u8 gVoiceModePayloadExtraBytes[];
    extern u8 gVoiceModePayloadUnits[];
    extern M2C_UNK gVoiceChatState;

    if (codecMode >= VOICE_CODEC_MODE_COUNT) return 0;
    if (M2C_FIELD(&gLinkConfig, s32 *, LINK_CONFIG_MODE) != 1 &&
        (u32)codecMode <= VOICE_CODEC_MULAW) return 0;

    M2C_FIELD(&gVoiceChatState, s32 *, VOICE_CHAT_WIRE_PACKET_BYTES) =
        gVoiceModePayloadExtraBytes[codecMode * VOICE_CODEC_SIZE_ENTRY_BYTES] +
        gVoiceModePayloadUnits[codecMode * VOICE_CODEC_SIZE_ENTRY_BYTES] * VOICE_CODEC_PAYLOAD_UNIT_BYTES +
        VOICE_AUDIO_HEADER_BYTES;
    M2C_FIELD(&gVoiceChatState, s32 *, VOICE_CHAT_CODEC_MODE) = codecMode;
    M2C_FIELD(&gVoiceChatState, s16 *, VOICE_CHAT_ADPCM_PREDICTOR) = 0;
    M2C_FIELD(&gVoiceChatState, u8 *, VOICE_CHAT_ADPCM_STEP_INDEX) = 0;
    return 1;
}

void func_ov010_02222c9c(s32 arg0) {
    extern M2C_UNK gVoiceChatState;
    M2C_FIELD(&gVoiceChatState, s32 *, 0x18) = arg0;
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
/* Build and encode the next outgoing wireless-link packet: pick the next
 * queued sequence, measure the payload energy and its hardware square root,
 * set the header flags from the link state, encode the payload for the
 * current mode and update the sequence/timer state. Returns the packet to
 * transmit, or 0 when there is nothing to send. */
s32 Link_BuildNextPacket(void) {
extern M2C_UNK gVoiceChatState;
extern u8 gLinkPacketBuffers[];
extern s32 data_ov010_0222c000;
extern M2C_UNK gLinkCodecState;
extern M2C_UNK gLinkConfig;
u32 func_ov010_0222519c(void *,u32);
void func_ov010_02225538(void *,u32,u32);
s32 func_ov010_02224f94(u32,u32,s32);
void VoiceCodec_EncodeMuLaw(void *,void *,u32);
void VoiceCodec_EncodePcm8(void *,void *,u32);
s32 CountBits(void);
u32 n;
u32 packetFlags;
u8 *payload,*packet;
u32 energy,energyRoot;
s32 mode;
mode=M2C_FIELD(&gVoiceChatState,s32 *,0x1c);
n=M2C_FIELD(&gVoiceChatState,u32 *,0xf04)-M2C_FIELD(&gVoiceChatState,u32 *,0xf00);
if(n>1){M2C_FIELD(&gVoiceChatState,u32 *,0xf00)=M2C_FIELD(&gVoiceChatState,u32 *,0xf04)-1;n=1;}
if(n==0)return 0;
packet=gLinkPacketBuffers+((M2C_FIELD(&gVoiceChatState,u32 *,0xf00)&1)?0:0x460);
payload=packet+12;
if(mode>=2)payload+=4;
energy=func_ov010_0222519c(payload,M2C_FIELD(&gVoiceChatState,u32 *,0x24));
*(volatile u16 *)0x040002b0=0;
*(volatile u32 *)0x040002b8=energy;
while(*(volatile u16 *)0x040002b0&0x8000){}
energyRoot=*(volatile u32 *)0x040002b4;
if(M2C_FIELD(&gVoiceChatState,s32 *,0x18))func_ov010_02225538(payload,M2C_FIELD(&gVoiceChatState,u32 *,0x24),energyRoot);
packet[5]=mode;
if(data_ov010_0222c000){
s32 energyCheck=func_ov010_02224f94(energy,energyRoot,0);
M2C_FIELD(&gVoiceChatState,s32 *,0x28)=energyCheck;
switch(energyCheck){
case 0: n=M2C_FIELD(&gVoiceChatState,u32 *,0xf00)+1;M2C_FIELD(&gVoiceChatState,u32 *,0xf00)=n;return 0;
case 1: packet[5]|=0x80;break;
case 3: packet[4]=0x41;break;
}
}
if(!data_ov010_0222c000 && M2C_FIELD(&gVoiceChatState,s32 *,8)){
packetFlags=packet[5];M2C_FIELD(&gVoiceChatState,s32 *,8)=0;packet[5]=packetFlags|0x80;
}
if(M2C_FIELD(&gVoiceChatState,s32 *,0x14)){
packetFlags=packet[5];M2C_FIELD(&gVoiceChatState,s32 *,0x14)=0;packet[5]=packetFlags|0x80;
}
if(mode>=2){
if(packet[5]&0x80){M2C_FIELD(&gVoiceChatState,s16 *,0x10)=0;M2C_FIELD(&gVoiceChatState,u8 *,0x12)=0;}
VoiceChat_EncodePacket(payload-4,(s32)payload,M2C_FIELD(&gVoiceChatState,u32 *,0x24)>>1,&gLinkCodecState,mode);
}else if(mode==1){
VoiceCodec_EncodeMuLaw(payload,payload,M2C_FIELD(&gVoiceChatState,u32 *,0x24)>>1);
}else if(mode==0){
VoiceCodec_EncodePcm8(payload,payload,M2C_FIELD(&gVoiceChatState,u32 *,0x24)>>1);
}
n=M2C_FIELD(&gVoiceChatState,u32 *,4);
M2C_FIELD(&gVoiceChatState,u32 *,0xf0c)=n;
n&=~(1U<<M2C_FIELD(&gLinkConfig,u8 *,0));
M2C_FIELD(&gVoiceChatState,u32 *,0xf0c)=n;
M2C_FIELD(&gVoiceChatState,s32 *,0xf14)=CountBits()-1;
if(M2C_FIELD(&gVoiceChatState,s32 *,0xf14)>7)return 0;
M2C_FIELD(&gVoiceChatState,s32 *,0xf10)=0;
return (s32)packet;
}
#pragma pop
s32 func_ov010_02222f28(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *Link_AllocPacket(void);
    void Link_FreeChannelQueuedPackets(u32);
    void Link_FreeChannelPendingPackets(u32);
    void Link_FreeAllQueuedPackets(void);
    void Link_FreeAllPendingPackets(void);
    s32 func_ov010_02223b18(void *, void *);
    void Link_AppendPendingPacket(void *);
    void Link_FreePacket(void *);
    void MI_CpuCopy8(void *, void *, s32);
    extern M2C_UNK gVoiceChatState;
    extern u8 gLinkChannelStates[];
    extern u8 gVoiceModePayloadExtraBytes[];
    extern u8 gVoiceModePayloadUnits[];

    void *item;
    u8 *slot;
    s32 id;
    s32 a4;
    s32 a2;
    s32 a1;
    s32 a0;
    s32 a3;
    u32 i;
    u8 *p;
    s32 len;
    void *src;

    a4 = arg4;
    a2 = arg2;
    a1 = (s32)arg1;
    a0 = arg0;
    a3 = arg3;

    slot = 0;
    if (M2C_FIELD(&gVoiceChatState, s32 *, 0x20) == 0)
        return (s32)slot;

    p = gLinkChannelStates;
    i = 0;
    do {
        if (a0 == M2C_FIELD(p, s32 *, 0x38)) {
            slot = gLinkChannelStates + i * 0x94;
            break;
        }
        i++;
        p += 0x94;
    } while (i < 3);
    if (!slot)
        return 0;

    if (M2C_FIELD(a1, u8 *, 4) == 0x41) {
        M2C_FIELD(slot, s32 *, 0x30) = M2C_FIELD(a1, u16 *, 6);
        M2C_FIELD(slot, s32 *, 0x4c) = 0;
        M2C_FIELD(slot, s32 *, 0x6c) = 1;
        return 0;
    }
    if (M2C_FIELD(a1, u8 *, 4) != 0x40)
        return 0;

    id = M2C_FIELD(a1, u8 *, 5) & 0x7f;
    M2C_FIELD(slot, s32 *, 0x24) = id;
    if (id >= 5)
        return 0;

    if (a2 != (s32)gVoiceModePayloadExtraBytes[id * 2] +
                (s32)gVoiceModePayloadUnits[id * 2] * 0x44 + 0xc)
        return 0;

    if (!(M2C_FIELD(&gVoiceChatState, u32 *, 4) &
          (a0 ? (1u << a0) : 1u)))
        return 0;

    item = Link_AllocPacket();
    if (!item) {
        Link_FreeChannelQueuedPackets((u32)M2C_FIELD(slot, s32 *, 0x34));
        Link_FreeChannelPendingPackets((u32)M2C_FIELD(slot, s32 *, 0x34));
        item = Link_AllocPacket();
        if (!item) {
            Link_FreeAllQueuedPackets();
            Link_FreeAllPendingPackets();
            item = Link_AllocPacket();
        }
    }
    if (!item)
        return 0;

    len = a2 - 0xc;
    src = (u8 *)item + 0x45c - len;
    MI_CpuCopy8((u8 *)a1 + 0xc, src, len);

    M2C_FIELD(item, u8 *, 0x11) = (u8)M2C_FIELD(slot, s32 *, 0x34);
    M2C_FIELD(item, s32 *, 0xc) = id;
    M2C_FIELD(item, void **, 0x474) = src;
    M2C_FIELD(item, s32 *, 0x14) = len;
    M2C_FIELD(item, s32 *, 0x464) = a3;
    M2C_FIELD(item, s32 *, 0x468) = a4;
    M2C_FIELD(item, u8 *, 0x10) = (u8)a0;
    M2C_FIELD(item, u32 *, 0x45c) = (u32)(M2C_FIELD(a1, u8 *, 5) & 0x80);
    M2C_FIELD(item, u32 *, 0x460) = M2C_FIELD(a1, u32 *, 8);
    M2C_FIELD(item, u32 *, 0x18) = M2C_FIELD(a1, u16 *, 6);

    if (func_ov010_02223b18(slot, item) == 0) {
        Link_FreePacket(item);
        return 0;
    }
    Link_AppendPendingPacket(item);
    return 1;
}

