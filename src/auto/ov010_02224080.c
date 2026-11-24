/* 30 functions from 0x02224080 to 0x02224F94 (ov010), found by ds-decomp. */
#include "common.h"
typedef struct PoolEntry0222415c { u8 data[20]; struct PoolEntry0222415c *next; } PoolEntry0222415c;
extern s32 data_ov010_0222d920[4];
extern s32 data_ov010_0222d914[3];
extern u8 gControlReplyTypes[8];
extern u8 gDataReplyTypes[8];

/* Build the packet of an exchange step into the caller's buffer: check the
 * arguments and the step, write the packet header, and when the exchange starts
 * (step 0) set the context's peer mask and make sure no other exchange context
 * is waiting and that the first transition is allowed.  Returns 0 when the
 * packet may be sent, -1 for a bad argument and -3 for a refused step. */
s32 VoiceLink_BuildStepPacket(void *context, s32 step, void *packet, u32 size) {
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
    if ((step < 0) || (step >= 6)) {
        return -3;
    }
    ((VoiceLinkPacket *) packet)->kind = 0;
    VoiceLink_InitPacket(context, packet, (u8) step);
    if (step == 0) {
        if ((M2C_FIELD(&gLinkConfig, s32 *, LINK_CONFIG_MODE) == 1) && (((VoiceLinkContext *) context)->step == 4)) {
            if (VoiceLink_NoOtherContextWaiting(context) == 0) {
                return -3;
            }
        }
        ((VoiceLinkContext *) context)->peerMask = ((VoiceLinkContext *) context)->peerId ? (1 << ((VoiceLinkContext *) context)->peerId) : 1;
    }
    if (VoiceLink_CheckStartStep(context, packet) == 0) {
        return -3;
    }
    return 0;
}

s32 VoiceLink_TrySendStep(s32 arg0, s32 arg1) {
    s32 VoiceLink_SendPacket(void *, s32);
    extern M2C_UNK gLinkConfig;
    if (M2C_FIELD(&gLinkConfig, s32 *, 0x10) == 2) return -3;
    return VoiceLink_SendPacket(arg0, arg1);
}

#pragma opt_strength_reduction off
/* Initialise the voice-chat link from its config: use the caller's context pool
 * to build the state's free list, clear the working and scratch contexts, reset
 * the link state and seed the link's LCG. */
s32 VoiceLink_Init(VoiceLinkConfig *config) {
extern M2C_UNK gVoiceLinkState,gVoiceLinkContext,gVoiceLinkScratchContext,gLinkConfig;
void MI_CpuFill8(void*,s32,u32);u64 GetSystemTick(void);
u32 i,offset;void *pool=config->contextPool;
if(!pool||!config->contextCount||config->contextCount>VOICE_LINK_CONTEXT_MAX)return 0;
((VoiceLinkState *)&gVoiceLinkState)->freeList=config->contextPool;
MI_CpuFill8(pool,0,config->contextCount*sizeof(VoiceLinkContext));
MI_CpuFill8(&gVoiceLinkContext,0,sizeof(VoiceLinkContext));
MI_CpuFill8(&gVoiceLinkScratchContext,0,sizeof(VoiceLinkContext));
i=0;
if(config->contextCount-1){offset=0;do{
M2C_FIELD((u8 *)((VoiceLinkState *)&gVoiceLinkState)->freeList+offset,void**,0x14)=(u8 *)((VoiceLinkState *)&gVoiceLinkState)->freeList+ (++i)*sizeof(VoiceLinkContext);
offset+=sizeof(VoiceLinkContext);
}while(i<config->contextCount-1);}
M2C_FIELD((u8 *)((VoiceLinkState *)&gVoiceLinkState)->freeList+config->contextCount*sizeof(VoiceLinkContext),s32*,-4)=0;
((VoiceLinkState *)&gVoiceLinkState)->activeList=0;
((VoiceLinkState *)&gVoiceLinkState)->peerMask=0;
((VoiceLinkState *)&gVoiceLinkState)->unk00=0;
M2C_FIELD(&gLinkConfig,s32*,0x14)=0;
((VoiceLinkState *)&gVoiceLinkState)->getTick=GetSystemTick;
((VoiceLinkState *)&gVoiceLinkState)->randMul=0x5d588b65;
((VoiceLinkState *)&gVoiceLinkState)->randAdd=0x269ec3;
return 1;
}
#pragma opt_strength_reduction reset
void func_ov010_02224270(void) {
    extern M2C_UNK gVoiceLinkState;
    M2C_FIELD(&gVoiceLinkState, s32 *, 0x14) = 0;
    M2C_FIELD(&gVoiceLinkState, s32 *, 0x10) = 0;
}

/* Drops the voice-chat link's active exchange once it has been idle for longer
 * than gVoiceLinkTimeoutTicks: clear the activity stamp and the exchange state,
 * send a control packet and tell the link layer about the timeout. */
void VoiceLink_CheckTimeout(void) {
    u64 GetSystemTick(void);
    M2C_UNK VoiceLink_SendControl(s32);
    extern M2C_UNK gLinkConfig;
    extern M2C_UNK gVoiceLinkState;
    extern M2C_UNK gVoiceLinkTimeoutTicks;
    extern M2C_UNK gVoiceLinkContext;
    u64 now;
    u64 last;

    now = GetSystemTick();
    if (((LinkConfig *) &gLinkConfig)->mode != 2) {
        return;
    }
    if (((LinkConfig *) &gLinkConfig)->control == 0) {
        return;
    }
    last = ((VoiceLinkState *) &gVoiceLinkState)->lastActivity;
    if (last == 0) {
        return;
    }
    if (now - last <= M2C_FIELD(&gVoiceLinkTimeoutTicks, u64 *, 0)) {
        return;
    }
    M2C_FIELD(&gVoiceLinkState, s32 *, 8) = 0;
    M2C_FIELD(&gVoiceLinkState, s32 *, 0xC) = 0;
    ((VoiceLinkState *) &gVoiceLinkState)->sessionState = 0;
    ((VoiceLinkState *) &gVoiceLinkState)->substate = 0;
    VoiceLink_SendControl(0);
    ((LinkConfig *) &gLinkConfig)->notify(
        ((VoiceLinkState *) &gVoiceLinkState)->peerId, LINK_NOTIFY_TIMEOUT, &gVoiceLinkContext,
        ((LinkConfig *) &gLinkConfig)->notifyArg);
}

/* Receive dispatcher for a voice-chat link packet: accept only a full-size packet
 * sent by the expected player to this one, then hand a short-header packet to the
 * short-packet handler and a full one to the peer or control handler, chosen by
 * the link config.  Returns whether a reply has to be sent. */
s32 VoiceLink_HandlePacket(s32 peerId, VoiceLinkPacket *packet, s32 size, M2C_UNK reply) {
    s32 VoiceLink_HandlePeerPacket(void *, M2C_UNK);
    s32 VoiceLink_HandleControlPacket(void *, M2C_UNK);
    s32 VoiceLink_HandleShortPacket(void *, M2C_UNK);
    extern M2C_UNK gLinkConfig;

    if (size != VOICE_LINK_PACKET_SIZE) {
        return 0;
    }
    if ((packet->sender != peerId) || (packet->target != M2C_FIELD(&gLinkConfig, u8 *, LINK_CONFIG_LOCAL_ID))) {
        return 0;
    }
    if (packet->headerSize != VOICE_LINK_PACKET_SIZE) {
        return VoiceLink_HandleShortPacket(packet, reply);
    }
    if (M2C_FIELD(&gLinkConfig, s32 *, LINK_CONFIG_CONTROL) == 0) {
        return VoiceLink_HandlePeerPacket(packet, reply);
    }
    return VoiceLink_HandleControlPacket(packet, reply);
}

/* Take an idle exchange context off the link's free list, initialise it for peer
 * `peerId` and push it onto the active list. Returns NULL when the peer id is out
 * of range, is our own id, or no context is free. */
void *VoiceLink_AllocContext(u32 peerId) {
void VoiceLink_InitContext(); extern M2C_UNK gLinkConfig,gVoiceLinkState;
VoiceLinkContext *context;
if(peerId>=32)return 0;
if(peerId==M2C_FIELD(&gLinkConfig,u8 *,LINK_CONFIG_LOCAL_ID))return 0;
context=((VoiceLinkState *)&gVoiceLinkState)->freeList;
if(!context)return 0;
((VoiceLinkState *)&gVoiceLinkState)->freeList=context->next;
VoiceLink_InitContext(context,peerId);
context->next=((VoiceLinkState *)&gVoiceLinkState)->activeList;
((VoiceLinkState *)&gVoiceLinkState)->activeList=context;
return context;
}

/* Build the control packet (kind 0xFF) of one voice-link protocol step into a local
 * buffer and transmit it: the packet builder's error is returned as is, and a transmit
 * that reached no peer reports -4. */
s32 VoiceLink_SendControlPacket(void *context, s32 step) {
    s32 VoiceLink_BuildControlPacket(void *, M2C_UNK, void *, u32);
    s32 VoiceLink_TransmitPacket(void *, void *);
    u8 packet[0x10];
    s32 result;

    result = VoiceLink_BuildControlPacket(context, step, packet, 0x10);
    if (result != 0) {
        return result;
    }
    if (VoiceLink_TransmitPacket(context, packet) != 0) {
        return 0;
    }
    return -4;
}

/* Build the step packet of one voice-link protocol step into a local buffer and
 * transmit it: the packet builder's error is returned as is, and a transmit that
 * reached no peer reports -4. */
s32 VoiceLink_SendPacket(void *context, s32 step) {
    u8 packet[0x10];
    s32 result;
    s32 VoiceLink_TransmitPacket(void *, void *);

    result = VoiceLink_BuildStepPacket(context, step, packet, 0x10);
    if (result != 0) {
        return result;
    }
    if (VoiceLink_TransmitPacket(context, packet) != 0) {
        return 0;
    }
    return -4;
}

void VoiceLink_SetPacketFromContext(void *arg0, void *arg1) {
    extern M2C_UNK gVoiceLinkState;

    if (M2C_FIELD(arg1, u8 *, 0xa) != 1) {
        return;
    }
    M2C_FIELD(arg1, u8 *, 0xb) = M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg1, s32 *, 0xc) = M2C_FIELD(&gVoiceLinkState, s32 *, 4);
}

/* Send the reply packet to every connected peer except ourselves, counting the
 * sends that succeed; when the packet's flag asks for it, record the connected
 * peer set in the exchange context. Returns -4 when nothing could be sent. */
s32 VoiceLink_BroadcastPacket(void *context, void *packet) {
    s32 SendTransferToPeer(u8, void *, u32);
    void VoiceLink_SetPacketFromContext(void *, void *);
    extern M2C_UNK gLinkConfig;
    extern M2C_UNK gVoiceLinkState;
    M2C_UNK contextPtr;
    s32 mask;
    s32 sent;
    u8 peer;
    u8 flag;

    contextPtr = (M2C_UNK) context;
    sent = 0;
    VoiceLink_SetPacketFromContext(context, packet);
    peer = 0;
    do {
        if (peer != 0) {
            mask = 1 << peer;
        } else {
            mask = 1;
        }
        if ((M2C_FIELD(&gVoiceLinkState, u32 *, 4) & mask) &&
            (peer != M2C_FIELD(&gLinkConfig, u8 *, 0))) {
            M2C_FIELD(packet, u8 *, 9) = peer;
            if (SendTransferToPeer(peer, packet, 0x10) != 0) {
                sent += 1;
            }
        }
        peer += 1;
    } while (peer < 0x20);
    flag = M2C_FIELD(packet, u8 *, 0xa);
    if (flag == 1) {
        M2C_FIELD((void *) contextPtr, s32 *, 8) = M2C_FIELD(&gVoiceLinkState, s32 *, 4);
    } else if (flag == 0) {
        M2C_FIELD((void *) contextPtr, s32 *, 8) = 0;
    }
    if (sent == 0) {
        return -4;
    }
    return 0;
}

M2C_UNK VoiceLink_SendControl(s32 arg0) {
 extern M2C_UNK gVoiceLinkContext;
 M2C_UNK VoiceLink_InitPacket(void *,void *,u8);
 u8 sp0[0x10];
 sp0[4]=0xff;
 VoiceLink_InitPacket(&gVoiceLinkContext,sp0,4);
 sp0[0xa]=arg0;
 VoiceLink_BroadcastPacket(&gVoiceLinkContext,sp0);
}

#pragma opt_propagation off
/* Recycle an exchange context for peer `peerId`: clear all 0x18 bytes, mark it in
 * use with the link config's mode and reset its protocol step. */
void VoiceLink_InitContext(void *context, s32 peerId) {
 extern M2C_UNK gLinkConfig;
 u8 zero;
 u32 i;
 u8 *ptr;
 ptr=(u8 *)context;i=6;zero=0;
 do {ptr[0]=zero;ptr[1]=zero;ptr[2]=zero;ptr[3]=zero;ptr+=4;}while(--i);
 ((VoiceLinkContext *)context)->valid=M2C_FIELD(&gLinkConfig,s32 *,LINK_CONFIG_MODE);
 ((VoiceLinkContext *)context)->step=0;
 ((VoiceLinkContext *)context)->peerId=peerId;
}
#pragma opt_propagation reset
s32 VoiceLink_TransmitPacket(void *arg0,void *arg1) {
 s32 SendTransferToPeer(u8,void *,u32);
 if(M2C_FIELD(arg1,u8 *,4)==0xff && M2C_FIELD(arg1,u8 *,6)==4) {
 VoiceLink_BroadcastPacket(arg0,arg1);
 } else {
 if(SendTransferToPeer(M2C_FIELD(arg0,u8 *,4),arg1,0x10)==0) return 0;
 }
 return 1;
}

/* Works out the reply type for a voice-chat link packet: control packets and
   non-first data subtypes take theirs from the packet subtype tables, while the
   first data subtype picks it from the exchange's current step.  Every answer
   records the packet's peer id in the context and refreshes its peer mask. */
u8 VoiceLink_GetReplyType(u8 *a,u8 *b){
    VoiceLinkPacket *packet=(VoiceLinkPacket *)a;
    VoiceLinkContext *context=(VoiceLinkContext *)b;
    s32 step;
    context->packetPeerId = packet->peerId;
    if (packet->kind == 0xFF) {
        if (packet->subtype == 0) {
            context->peerMask = context->peerId ? (1 << context->peerId) : 1;
        }
        return gControlReplyTypes[packet->subtype];
    }
    if (packet->kind == 0) {
        if (packet->subtype == 0) {
            step = context->step;
            if (step == 1) {
                context->peerMask = context->peerId ? (1 << context->peerId) : 1;
                return 7;
            }
            if (step == 5) return 9;
            return 12;
        }
        return gDataReplyTypes[packet->subtype];
    }
    return 12;
}

/* Fill in the fixed header of a voice-link packet: the magic and header size, the
 * exchange step as the packet subtype, the local player as both sender and peer
 * id, the context's peer as the target, and a zero flag and sequence number. */
M2C_UNK VoiceLink_InitPacket(void *context, void *packet, u8 step) {
    extern M2C_UNK gLinkConfig;
    VoiceLinkPacket *p = packet;
    VoiceLinkContext *ctx = context;

    p->magic = VOICE_LINK_PACKET_MAGIC;
    p->headerSize = VOICE_LINK_PACKET_SIZE;
    p->subtype = step;
    p->sender = ((LinkConfig *) &gLinkConfig)->localId;
    p->target = ctx->peerId;
    p->flag = 0;
    p->peerId = ((LinkConfig *) &gLinkConfig)->localId;
    p->sequence = 0;
    return 0;
}

s32 VoiceLink_AdvanceStep(void *a, void *b) {
extern M2C_UNK gLinkConfig;
extern s8 data_ov010_0222bf22[],data_ov010_0222be5c[];
s32 VoiceLink_SendPacket(void *,s32);
s32 i=M2C_FIELD(b,u8 *,6);
s8 v;
s8 *t;
if(M2C_FIELD(b,u8 *,4)==0)i+=5;
if(i<0 || i>=11)i=-1;
if(i<0)return -1;
t=M2C_FIELD(&gLinkConfig,s32 *,16)==1?data_ov010_0222bf22:data_ov010_0222be5c;
v=*(i+(M2C_FIELD(a,u32 *,12)*11U+t));
switch(v) {
default: return v;
case -2: VoiceLink_SendPacket(a,1); M2C_FIELD(a,s32 *,12)=0;M2C_FIELD(a,s32 *,0)=0;return v;
case -3: VoiceLink_SendPacket(a,3); M2C_FIELD(a,s32 *,12)=0;M2C_FIELD(a,s32 *,0)=0;return v;
case -1: break;
}
return v;
}

/* Returns 1 when no exchange context other than `context` is waiting on
 * handshake step 2, i.e. when no other exchange has a reply in flight. */
s32 VoiceLink_NoOtherContextWaiting(void *context) {
    extern M2C_UNK gVoiceLinkState;
    VoiceLinkContext *p = ((VoiceLinkState *) &gVoiceLinkState)->activeList;
    while (p) {
        if (p->valid && p->step == 2 && context != (void *) p) {
            return 0;
        }
        p = p->next;
    }
    return 1;
}

#pragma opt_propagation off
s32 VoiceLink_CheckStartStep(void *a,void *b){
extern M2C_UNK gLinkConfig; extern s8 data_ov010_0222be9e[]; extern s8 data_ov010_0222bee0[];
s32 i=M2C_FIELD(b,u8*,6);s8 *t;s8 v;u32 row;
if(M2C_FIELD(b,u8*,4)==0)i+=5;
if(i<0||i>=11)i=-1;
if(i<0)return -1;
t=M2C_FIELD(&gLinkConfig,s32*,16)==1?data_ov010_0222be9e:data_ov010_0222bee0;
row=M2C_FIELD(a,u32*,12);v=*(i+(t+row*(u32)11));
if(v==-1)return 1;
if(v==-2)return 0;
M2C_FIELD(a,s32*,12)=v;return 1;
}
#pragma opt_propagation reset
/* Find the exchange context serving peerId: link mode 2 keeps one shared context
 * (returned only for the peer being served), otherwise search the active list. */
s32 *VoiceLink_FindContext(u8 peerId){
extern M2C_UNK gLinkConfig;extern M2C_UNK gVoiceLinkState;extern M2C_UNK gVoiceLinkContext;
VoiceLinkContext *p=((VoiceLinkState *)&gVoiceLinkState)->activeList;
if(((LinkConfig *)&gLinkConfig)->mode==2){
if(((VoiceLinkState *)&gVoiceLinkState)->sessionState&&((VoiceLinkState *)&gVoiceLinkState)->peerId==peerId)return (s32 *)&gVoiceLinkContext;
return 0;}
while(p){if(p->valid&&p->peerId==peerId)return (s32 *)p;p=p->next;}return 0;
}

/* Serve a voice-chat peer packet: dispatch it to the exchange context of its
 * sender (starting one when there is none), advance the handshake and fill the
 * reply with the reply type and the context. Returns nonzero when there is a
 * reply to send. */
s32 VoiceLink_HandlePeerPacket(void *packet, M2C_UNK reply) {
void VoiceLink_ReleaseContext(void *);
extern M2C_UNK gVoiceLinkScratchContext;
VoiceLinkPacket *pkt=packet;
VoiceLinkReply *out=(VoiceLinkReply *)reply;
void *link,*context; s32 step,step2;
if(pkt->kind==255){
if(pkt->subtype==4)return VoiceLink_HandleConnectPacket(packet,(void*)reply);
if(pkt->subtype==3)return 0;
}
link=VoiceLink_FindContext(pkt->sender);
if(link){
step=VoiceLink_AdvanceStep(link,packet);
if(step!=-2){if(step==-1)return 0;}else{out->type=12;((VoiceLinkContext *)link)->valid=0;out->context=(VoiceLinkContext *)link;return 1;
}
out->type=VoiceLink_GetReplyType(packet,(u8*)link);
out->context=(VoiceLinkContext *)link;((VoiceLinkContext *)link)->step=step;
return out->type!=0;
}
context=VoiceLink_AllocContext(pkt->sender);
if(!context){VoiceLink_InitContext(&gVoiceLinkScratchContext,pkt->sender);VoiceLink_SendPacket(&gVoiceLinkScratchContext,3);return 0;}
step2=VoiceLink_AdvanceStep(context,packet);
if((u32)(step2+2)<=1){VoiceLink_ReleaseContext(context);return 0;}
out->type=VoiceLink_GetReplyType(packet,(u8*)context);out->context=(VoiceLinkContext *)context;((VoiceLinkContext *)context)->step=step2;
return out->type!=0;
}

/* Serve a voice-chat control packet: match it to the active exchange (or start
 * one for its sender), advance the handshake step, and fill out[0] with the
 * reply packet type and out[4] with the exchange context. */
s32 VoiceLink_HandleControlPacket(void *arg0,M2C_UNK out) {
extern s32 gVoiceLinkState,gVoiceLinkContext;
u64 GetSystemTick(void);
s32 n;u32 mask; u8 *p=arg0;
if(((VoiceLinkState *)&gVoiceLinkState)->sessionState==2){
if(((VoiceLinkState *)&gVoiceLinkState)->peerId==((VoiceLinkPacket *)p)->sender){
n=VoiceLink_AdvanceStep(&gVoiceLinkContext,p);
switch(n){case -2:M2C_FIELD(out,s32 *,0)=12;M2C_FIELD(out,s32 *,4)=0;return 1;case -3:case -1:return 0;default:break;}
M2C_FIELD(out,s32 *,0)=VoiceLink_GetReplyType(p,(u8 *)&gVoiceLinkContext);
M2C_FIELD(out,void **,4)=&gVoiceLinkContext;
((VoiceLinkContext *)&gVoiceLinkContext)->step=n;
}else{VoiceLink_SendControl(1);return 0;}
}else{
mask=((VoiceLinkPacket *)p)->sender?(1<<((VoiceLinkPacket *)p)->sender):1;
if(!(((VoiceLinkState *)&gVoiceLinkState)->peerMask&mask))return 0;
((VoiceLinkState *)&gVoiceLinkState)->peerId=((VoiceLinkPacket *)p)->sender;
((VoiceLinkState *)&gVoiceLinkState)->sessionState=2;
((VoiceLinkState *)&gVoiceLinkState)->substate=0;
n=VoiceLink_AdvanceStep(&gVoiceLinkContext,p);
switch(n){case -3:case -2:case -1:((VoiceLinkState *)&gVoiceLinkState)->sessionState=0;return 0;default:break;}
M2C_FIELD(out,s32 *,0)=VoiceLink_GetReplyType(p,(u8 *)&gVoiceLinkContext);
M2C_FIELD(out,void **,4)=&gVoiceLinkContext;
((VoiceLinkContext *)&gVoiceLinkContext)->step=n;
}
if(M2C_FIELD(out,s32 *,0)==10){VoiceLink_SendControl(1);((VoiceLinkState *)&gVoiceLinkState)->lastActivity=GetSystemTick();}
else{VoiceLink_SendControl(0);((VoiceLinkState *)&gVoiceLinkState)->lastActivity=0;}
return 1;
}

/* Handle a voice-link packet whose header is shorter than a full packet: a
 * connect packet is ignored; otherwise the sender's exchange context (or the
 * scratch context when it has none) is released with a step-2 packet, and a
 * reply is queued when the sender has a context. */
s32 VoiceLink_HandleShortPacket(void *arg0, M2C_UNK arg1) {
    void VoiceLink_InitContext();
    s32 *VoiceLink_FindContext(u8);
    s32 VoiceLink_SendPacket(void *, s32);
    extern M2C_UNK gVoiceLinkScratchContext;
    VoiceLinkPacket *packet = (VoiceLinkPacket *) arg0;
    VoiceLinkReply *reply = (VoiceLinkReply *) arg1;
    s32 *context;

    if (packet->kind == 0xFF && packet->subtype == 4) {
        return 0;
    }
    context = VoiceLink_FindContext(packet->sender);
    if (context) {
        reply->type = 2;
        reply->context = (VoiceLinkContext *) context;
        *context = 0;
        VoiceLink_SendPacket(context, 2);
        return 1;
    }
    VoiceLink_InitContext(&gVoiceLinkScratchContext, packet->sender);
    VoiceLink_SendPacket(&gVoiceLinkScratchContext, 2);
    return 0;
}

/* Serve a voice-chat connect packet: set the reply's type and context for the
 * exchange (9/5 on a peer's connect, 7/6 on ours) and advance the link state's
 * session/substate machine; a packet flag other than 0 or 1 is ignored. */
s32 VoiceLink_HandleConnectPacket(void *packet,void *reply){
extern M2C_UNK gLinkConfig,gVoiceLinkState,gVoiceLinkContext;
if(M2C_FIELD(&gLinkConfig,s32*,16)!=2)return 0;
if(M2C_FIELD(&gLinkConfig,u8*,1)!=M2C_FIELD(packet,u8*,8))return 0;
switch(M2C_FIELD(packet,u8*,10)){
case 0:
if(!M2C_FIELD(&gVoiceLinkState,s32*,0x3c))return 0;
if(M2C_FIELD(&gVoiceLinkState,s32*,0x48)==5||M2C_FIELD(&gVoiceLinkState,s32*,0x48)==2)M2C_FIELD(reply,s32*,0)=9;
else M2C_FIELD(reply,s32*,0)=5;
M2C_FIELD(&gVoiceLinkState,s32*,0x3c)=0;
M2C_FIELD(&gVoiceLinkState,s32*,0x48)=0;
M2C_FIELD(reply,void**,4)=&gVoiceLinkContext;
break;
case 1:
M2C_FIELD(&gVoiceLinkState,s32*,0x3c)=2;
if(M2C_FIELD(packet,u8*,11)==M2C_FIELD(&gLinkConfig,u8*,0)){
M2C_FIELD(&gVoiceLinkState,s32*,0x48)=2;M2C_FIELD(reply,s32*,0)=7;
M2C_FIELD(&gVoiceLinkState,u32*,0x44)=M2C_FIELD(packet,u32*,12);
}else{
M2C_FIELD(&gVoiceLinkState,s32*,0x48)=3;M2C_FIELD(reply,s32*,0)=6;
M2C_FIELD(&gVoiceLinkState,u32*,0x44)=M2C_FIELD(packet,u8*,11)?1<<M2C_FIELD(packet,u8*,11):1;
}
M2C_FIELD(&gVoiceLinkState,u8*,0x41)=M2C_FIELD(packet,u8*,11);
M2C_FIELD(reply,void**,4)=&gVoiceLinkContext;
break;
default:return 0;
}
return 1;
}

/* Build the link's packet free list: the caller's 32-byte aligned buffer of
 * size bytes is cleared and carved into LINK_PACKET_SIZE-byte packets that are
 * threaded onto gLinkPacketPool.freeList. The packet count must be within
 * LINK_PACKET_POOL_MIN..LINK_PACKET_POOL_MAX. Returns 1 on success, 0 when the
 * buffer or its size is unusable. */
s32 VoiceLink_InitPacketPool(void *buf,u32 size) {
extern M2C_UNK gLinkPacketPool;
void MI_CpuFill32(s32,void *,u32);
u32 count=size/LINK_PACKET_SIZE; s32 i;
((LinkPacketPool *)&gLinkPacketPool)->base=buf;
if(count<LINK_PACKET_POOL_MIN||count>LINK_PACKET_POOL_MAX)return 0;
if(!buf)return 0;
if((u32)buf&31){((LinkPacketPool *)&gLinkPacketPool)->base=0;return 0;}
MI_CpuFill32(0,buf,size);
for(i=0;i<count-1;i++) {
void *base=((LinkPacketPool *)&gLinkPacketPool)->base;
M2C_FIELD(base+i*LINK_PACKET_SIZE,void **,0)=base+(i+1U)*LINK_PACKET_SIZE;
}
M2C_FIELD(((LinkPacketPool *)&gLinkPacketPool)->base+count*LINK_PACKET_SIZE,void **,-LINK_PACKET_SIZE)=0;
((LinkPacketPool *)&gLinkPacketPool)->freeList=((LinkPacketPool *)&gLinkPacketPool)->base;
return 1;
}

void func_ov010_02224ea0(void) {
    extern M2C_UNK gLinkPacketPool;
    M2C_FIELD(&gLinkPacketPool, s32 *, 4) = 0;
    M2C_FIELD(&gLinkPacketPool, s32 *, 8) = 0;
}

void *func_ov010_02224eb8(void) {
extern M2C_UNK gLinkPacketPool;
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32);
void *r=0; void *p;
M2C_FIELD(&gLinkPacketPool,s32 *,0)=OS_DisableInterrupts();
p=M2C_FIELD(&gLinkPacketPool,void **,4);
if(p){r=p;M2C_FIELD(&gLinkPacketPool,void **,4)=M2C_FIELD(p,void **,0);}
OS_RestoreInterrupts(M2C_FIELD(&gLinkPacketPool,s32 *,0));return r;
}

void Link_FreePacket(void *p){extern M2C_UNK gLinkPacketPool;s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);M2C_FIELD(&gLinkPacketPool,s32 *,0)=OS_DisableInterrupts();M2C_FIELD(p,void **,0)=M2C_FIELD(&gLinkPacketPool,void **,4);M2C_FIELD(&gLinkPacketPool,void **,4)=p;OS_RestoreInterrupts(M2C_FIELD(&gLinkPacketPool,s32 *,0));}

#pragma optimization_level 3
#pragma peephole off
void func_ov010_02224f28(void) {
extern M2C_UNK data_ov010_0222c02c;
s32 i;
for(i=0;i<4;i++)data_ov010_0222d920[i]=0x1000000;
data_ov010_0222d914[1]=0;
data_ov010_0222d914[0]=0;
M2C_FIELD(&data_ov010_0222c02c,s32 *,0)=0;
M2C_FIELD(&data_ov010_0222c02c,s32 *,4)=0;
data_ov010_0222d914[2]=0;
}
#pragma scheduling reset
#pragma opt_common_subs reset
#pragma peephole reset
#pragma optimization_level 4
void func_ov010_02224f74(s32 arg0) {
    M2C_UNK MI_CpuCopy8(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_ov010_0222c02c;
    if (arg0 == 0) {
        return;
    }
    MI_CpuCopy8(&data_ov010_0222c02c, arg0, 0x10);
}

