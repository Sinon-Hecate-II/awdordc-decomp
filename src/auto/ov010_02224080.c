/* 30 functions from 0x02224080 to 0x02224F94 (ov010), found by ds-decomp. */
#include "common.h"
typedef struct PoolEntry0222415c { u8 data[20]; struct PoolEntry0222415c *next; } PoolEntry0222415c;
extern s32 data_ov010_0222d920[4];
extern s32 data_ov010_0222d914[3];
extern u8 data_ov010_0222be4c[8];
extern u8 data_ov010_0222be54[8];

s32 func_ov010_02224080(void *arg0, s32 arg1, void *arg2, u32 arg3) {
    M2C_UNK func_ov010_02224700(void *, void *, u8);
    s32 func_ov010_02224820(void *);
    s32 func_ov010_0222486c(void *, void *);
    extern M2C_UNK gLinkConfig;

    if (arg0 == NULL) {
        return -1;
    }
    if (arg3 < 0x10) {
        return -1;
    }
    if ((arg1 < 0) || (arg1 >= 6)) {
        return -3;
    }
    M2C_FIELD(arg2, u8 *, 4) = 0;
    func_ov010_02224700(arg0, arg2, (u8) arg1);
    if (arg1 == 0) {
        if ((M2C_FIELD(&gLinkConfig, s32 *, 0x10) == 1) && (M2C_FIELD(arg0, s32 *, 0xC) == 4)) {
            if (func_ov010_02224820(arg0) == 0) {
                return -3;
            }
        }
        M2C_FIELD(arg0, s32 *, 8) = M2C_FIELD(arg0, u8 *, 4) ? (1 << M2C_FIELD(arg0, u8 *, 4)) : 1;
    }
    if (func_ov010_0222486c(arg0, arg2) == 0) {
        return -3;
    }
    return 0;
}

s32 func_ov010_02224138(s32 arg0, s32 arg1) {
    s32 VoiceLink_SendPacket(void *, s32);
    extern M2C_UNK gLinkConfig;
    if (M2C_FIELD(&gLinkConfig, s32 *, 0x10) == 2) return -3;
    return VoiceLink_SendPacket(arg0, arg1);
}

#pragma opt_strength_reduction off
s32 func_ov010_0222415c(void *p){
extern M2C_UNK gVoiceLinkState,gVoiceLinkContext,gVoiceLinkScratchContext,gLinkConfig;
void MI_CpuFill8(void*,s32,u32);u64 GetSystemTick(void);
u32 i,offset;void *pool=M2C_FIELD(p,void**,0);
if(!pool||!M2C_FIELD(p,u32*,4)||M2C_FIELD(p,u32*,4)>8)return 0;
M2C_FIELD(&gVoiceLinkState,void**,16)=M2C_FIELD(p,void**,0);
MI_CpuFill8(pool,0,M2C_FIELD(p,u32*,4)*24);
MI_CpuFill8(&gVoiceLinkContext,0,24);
MI_CpuFill8(&gVoiceLinkScratchContext,0,24);
i=0;
if(M2C_FIELD(p,u32*,4)-1){offset=0;do{
M2C_FIELD(M2C_FIELD(&gVoiceLinkState,u8**,16)+offset,void**,20)=M2C_FIELD(&gVoiceLinkState,u8**,16)+ (++i)*24;
offset+=24;
}while(i<M2C_FIELD(p,u32*,4)-1);}
M2C_FIELD(M2C_FIELD(&gVoiceLinkState,u8**,16)+M2C_FIELD(p,u32*,4)*24,s32*,-4)=0;
M2C_FIELD(&gVoiceLinkState,s32*,20)=0;
M2C_FIELD(&gVoiceLinkState,s32*,4)=0;
M2C_FIELD(&gVoiceLinkState,s32*,0)=0;
M2C_FIELD(&gLinkConfig,s32*,20)=0;
M2C_FIELD(&gVoiceLinkState,u64(**)(void),24)=GetSystemTick;
M2C_FIELD(&gVoiceLinkState,u32*,28)=0x5d588b65;
M2C_FIELD(&gVoiceLinkState,u32*,32)=0x269ec3;
return 1;
}
#pragma opt_strength_reduction reset
void func_ov010_02224270(void) {
    extern M2C_UNK gVoiceLinkState;
    M2C_FIELD(&gVoiceLinkState, s32 *, 0x14) = 0;
    M2C_FIELD(&gVoiceLinkState, s32 *, 0x10) = 0;
}

void func_ov010_02224288(void) {
    u64 GetSystemTick(void);
    M2C_UNK VoiceLink_SendControl(s32);
    extern M2C_UNK gLinkConfig;
    extern M2C_UNK gVoiceLinkState;
    extern M2C_UNK data_ov010_0222c024;
    extern M2C_UNK gVoiceLinkContext;
    u64 now;
    u64 last;

    now = GetSystemTick();
    if (M2C_FIELD(&gLinkConfig, s32 *, 0x10) != 2) {
        return;
    }
    if (M2C_FIELD(&gLinkConfig, s32 *, 0xC) == 0) {
        return;
    }
    last = M2C_FIELD(&gVoiceLinkState, u64 *, 8);
    if (last == 0) {
        return;
    }
    if (now - last <= M2C_FIELD(&data_ov010_0222c024, u64 *, 0)) {
        return;
    }
    M2C_FIELD(&gVoiceLinkState, s32 *, 8) = 0;
    M2C_FIELD(&gVoiceLinkState, s32 *, 0xC) = 0;
    M2C_FIELD(&gVoiceLinkState, s32 *, 0x3C) = 0;
    M2C_FIELD(&gVoiceLinkState, s32 *, 0x48) = 0;
    VoiceLink_SendControl(0);
    M2C_FIELD(&gLinkConfig, M2C_UNK (**)(u8, s32, M2C_UNK *, M2C_UNK), 4)(
        M2C_FIELD(&gVoiceLinkState, u8 *, 0x40), 9, &gVoiceLinkContext,
        M2C_FIELD(&gLinkConfig, M2C_UNK *, 8));
}

s32 func_ov010_02224334(s32 arg0, void *arg1, s32 arg2, M2C_UNK arg3) {
    s32 VoiceLink_HandlePeerPacket(void *, M2C_UNK);
    s32 VoiceLink_HandleControlPacket(void *, M2C_UNK);
    s32 func_ov010_02224c40(void *, M2C_UNK);
    extern M2C_UNK gLinkConfig;

    if (arg2 != 0x10) {
        return 0;
    }
    if ((M2C_FIELD(arg1, u8 *, 8) != arg0) || (M2C_FIELD(arg1, u8 *, 9) != M2C_FIELD(&gLinkConfig, u8 *, 0))) {
        return 0;
    }
    if (M2C_FIELD(arg1, u8 *, 5) != 0x10) {
        return func_ov010_02224c40(arg1, arg3);
    }
    if (M2C_FIELD(&gLinkConfig, s32 *, 0xC) == 0) {
        return VoiceLink_HandlePeerPacket(arg1, arg3);
    }
    return VoiceLink_HandleControlPacket(arg1, arg3);
}

void *VoiceLink_AllocContext(u32 arg0) {
void VoiceLink_InitContext(); extern M2C_UNK gLinkConfig,gVoiceLinkState;
void *p;
if(arg0>=32)return 0;
if(arg0==M2C_FIELD(&gLinkConfig,u8 *,0))return 0;
p=M2C_FIELD(&gVoiceLinkState,void **,16);
if(!p)return 0;
M2C_FIELD(&gVoiceLinkState,void **,16)=M2C_FIELD(p,void **,20);
VoiceLink_InitContext(p,arg0);
M2C_FIELD(p,void **,20)=M2C_FIELD(&gVoiceLinkState,void **,20);
M2C_FIELD(&gVoiceLinkState,void **,20)=p;
return p;
}

s32 func_ov010_0222441c(void *arg0, M2C_UNK arg1) {
    s32 func_ov010_02223fac(void *, M2C_UNK, void *, u32);
    s32 func_ov010_02224614(void *, void *);
    u8 sp0[0x10];
    s32 temp_r0;

    temp_r0 = func_ov010_02223fac(arg0, arg1, sp0, 0x10);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if (func_ov010_02224614(arg0, sp0) != 0) {
        return 0;
    }
    return -4;
}

s32 VoiceLink_SendPacket(void *arg0,s32 arg1) {
 u8 sp0[0x10]; s32 result;
 s32 func_ov010_02224614(void *,void *);
 result=func_ov010_02224080(arg0,arg1,sp0,0x10);
 if(result!=0) return result;
 if(func_ov010_02224614(arg0,sp0)!=0) return 0;
 return -4;
}

void func_ov010_022244a4(void *arg0, void *arg1) {
    extern M2C_UNK gVoiceLinkState;

    if (M2C_FIELD(arg1, u8 *, 0xa) != 1) {
        return;
    }
    M2C_FIELD(arg1, u8 *, 0xb) = M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg1, s32 *, 0xc) = M2C_FIELD(&gVoiceLinkState, s32 *, 4);
}

s32 func_ov010_022244cc(void *arg0, void *arg1) {
    s32 func_0204431c(u8, void *, u32);
    void func_ov010_022244a4(void *, void *);
    extern M2C_UNK gLinkConfig;
    extern M2C_UNK gVoiceLinkState;
    M2C_UNK sp0;
    s32 var_r1;
    s32 var_r8;
    u8 var_r9;
    u8 temp_r0;

    sp0 = (M2C_UNK) arg0;
    var_r8 = 0;
    func_ov010_022244a4(arg0, arg1);
    var_r9 = 0;
    do {
        if (var_r9 != 0) {
            var_r1 = 1 << var_r9;
        } else {
            var_r1 = 1;
        }
        if ((M2C_FIELD(&gVoiceLinkState, u32 *, 4) & var_r1) &&
            (var_r9 != M2C_FIELD(&gLinkConfig, u8 *, 0))) {
            M2C_FIELD(arg1, u8 *, 9) = var_r9;
            if (func_0204431c(var_r9, arg1, 0x10) != 0) {
                var_r8 += 1;
            }
        }
        var_r9 += 1;
    } while (var_r9 < 0x20);
    temp_r0 = M2C_FIELD(arg1, u8 *, 0xa);
    if (temp_r0 == 1) {
        M2C_FIELD((void *) sp0, s32 *, 8) = M2C_FIELD(&gVoiceLinkState, s32 *, 4);
    } else if (temp_r0 == 0) {
        M2C_FIELD((void *) sp0, s32 *, 8) = 0;
    }
    if (var_r8 == 0) {
        return -4;
    }
    return 0;
}

M2C_UNK VoiceLink_SendControl(s32 arg0) {
 extern M2C_UNK gVoiceLinkContext;
 M2C_UNK func_ov010_02224700(void *,void *,u8);
 u8 sp0[0x10];
 sp0[4]=0xff;
 func_ov010_02224700(&gVoiceLinkContext,sp0,4);
 sp0[0xa]=arg0;
 func_ov010_022244cc(&gVoiceLinkContext,sp0);
}

#pragma opt_propagation off
void VoiceLink_InitContext(void *arg0,s32 arg1) {
register u32 i; register u8 zero; u8 *ptr; extern M2C_UNK gLinkConfig;
ptr=arg0;i=6;zero=0;
do {ptr[0]=zero;ptr[1]=zero;ptr[2]=zero;ptr[3]=zero;ptr+=4;}while(--i);
M2C_FIELD(arg0,s32 *,0)=M2C_FIELD(&gLinkConfig,s32 *,0x10);
M2C_FIELD(arg0,s32 *,0xc)=0;M2C_FIELD(arg0,s8 *,4)=arg1;
}
#pragma opt_propagation reset
s32 func_ov010_02224614(void *arg0,void *arg1) {
 s32 func_0204431c(u8,void *,u32);
 if(M2C_FIELD(arg1,u8 *,4)==0xff && M2C_FIELD(arg1,u8 *,6)==4) {
 func_ov010_022244cc(arg0,arg1);
 } else {
 if(func_0204431c(M2C_FIELD(arg0,u8 *,4),arg1,0x10)==0) return 0;
 }
 return 1;
}

u8 VoiceLink_GetReplyType(u8 *a,u8 *b){s32 n,v;b[5]=a[11];if(a[4]==255){if(a[6]==0){M2C_FIELD(b,s32 *,8)=b[4]?(1<<b[4]):1;}return data_ov010_0222be4c[a[6]];}if(a[4]==0){if(a[6]==0){n=M2C_FIELD(b,s32 *,12);if(n==1){M2C_FIELD(b,s32 *,8)=b[4]?(1<<b[4]):1;return 7;}if(n==5)return 9;return 12;}return data_ov010_0222be54[a[6]];}return 12;}

M2C_UNK func_ov010_02224700(void *a,void *b,u8 c){extern M2C_UNK gLinkConfig;M2C_FIELD(b,s32 *,0)=0x5f564354;M2C_FIELD(b,u8 *,5)=16;M2C_FIELD(b,u8 *,6)=c;M2C_FIELD(b,u8 *,8)=M2C_FIELD(&gLinkConfig,u8 *,0);M2C_FIELD(b,u8 *,9)=M2C_FIELD(a,u8 *,4);M2C_FIELD(b,u8 *,10)=0;M2C_FIELD(b,u8 *,11)=M2C_FIELD(&gLinkConfig,u8 *,0);M2C_FIELD(b,s32 *,12)=0;return 0;}

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
case -2: VoiceLink_SendPacket(a,1); M2C_FIELD(a,s32 *,12)=0;M2C_FIELD(a,s32 *,0)=0;return v;
case -3: VoiceLink_SendPacket(a,3); M2C_FIELD(a,s32 *,12)=0;M2C_FIELD(a,s32 *,0)=0;return v;
case -1: break;
default: break;
}
return v;
}

s32 func_ov010_02224820(void *a){extern M2C_UNK gVoiceLinkState;void *p=M2C_FIELD(&gVoiceLinkState,void **,20);while(p){if(M2C_FIELD(p,s32 *,0)&&M2C_FIELD(p,s32 *,12)==2&&a!=p)return 0;p=M2C_FIELD(p,void **,20);}return 1;}

#pragma opt_propagation off
s32 func_ov010_0222486c(void *a,void *b){
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
s32 *VoiceLink_FindContext(u8 a){
extern M2C_UNK gLinkConfig;extern M2C_UNK gVoiceLinkState;extern M2C_UNK gVoiceLinkContext;
void *p=M2C_FIELD(&gVoiceLinkState,void **,20);
if(M2C_FIELD(&gLinkConfig,s32 *,16)==2){
if(M2C_FIELD(&gVoiceLinkState,s32 *,60)&&M2C_FIELD(&gVoiceLinkState,u8 *,64)==a)return (s32 *)&gVoiceLinkContext;
return 0;}
while(p){if(M2C_FIELD(p,s32 *,0)&&M2C_FIELD(p,u8 *,4)==a)return p;p=M2C_FIELD(p,void **,20);}return 0;
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

s32 func_ov010_02224c40(void *arg0, M2C_UNK arg1) {
void VoiceLink_InitContext();extern M2C_UNK gVoiceLinkScratchContext;
s32 *p;
if(M2C_FIELD(arg0,u8 *,4)==255 && M2C_FIELD(arg0,u8 *,6)==4)return 0;
p=VoiceLink_FindContext(M2C_FIELD(arg0,u8 *,8));
if(p){M2C_FIELD(arg1,s32 *,0)=2;M2C_FIELD(arg1,s32 **,4)=p;*p=0;VoiceLink_SendPacket(p,2);return 1;}
VoiceLink_InitContext(&gVoiceLinkScratchContext,M2C_FIELD(arg0,u8 *,8));VoiceLink_SendPacket(&gVoiceLinkScratchContext,2);return 0;
}

s32 VoiceLink_HandleConnectPacket(void *p,void *out){
extern M2C_UNK gLinkConfig,gVoiceLinkState,gVoiceLinkContext;
if(M2C_FIELD(&gLinkConfig,s32*,16)!=2)return 0;
if(M2C_FIELD(&gLinkConfig,u8*,1)!=M2C_FIELD(p,u8*,8))return 0;
switch(M2C_FIELD(p,u8*,10)){
case 0:
if(!M2C_FIELD(&gVoiceLinkState,s32*,0x3c))return 0;
if(M2C_FIELD(&gVoiceLinkState,s32*,0x48)==5||M2C_FIELD(&gVoiceLinkState,s32*,0x48)==2)M2C_FIELD(out,s32*,0)=9;
else M2C_FIELD(out,s32*,0)=5;
M2C_FIELD(&gVoiceLinkState,s32*,0x3c)=0;
M2C_FIELD(&gVoiceLinkState,s32*,0x48)=0;
M2C_FIELD(out,void**,4)=&gVoiceLinkContext;
break;
case 1:
M2C_FIELD(&gVoiceLinkState,s32*,0x3c)=2;
if(M2C_FIELD(p,u8*,11)==M2C_FIELD(&gLinkConfig,u8*,0)){
M2C_FIELD(&gVoiceLinkState,s32*,0x48)=2;M2C_FIELD(out,s32*,0)=7;
M2C_FIELD(&gVoiceLinkState,u32*,0x44)=M2C_FIELD(p,u32*,12);
}else{
M2C_FIELD(&gVoiceLinkState,s32*,0x48)=3;M2C_FIELD(out,s32*,0)=6;
M2C_FIELD(&gVoiceLinkState,u32*,0x44)=M2C_FIELD(p,u8*,11)?1<<M2C_FIELD(p,u8*,11):1;
}
M2C_FIELD(&gVoiceLinkState,u8*,0x41)=M2C_FIELD(p,u8*,11);
M2C_FIELD(out,void**,4)=&gVoiceLinkContext;
break;
default:return 0;
}
return 1;
}

s32 func_ov010_02224dd8(void *p,u32 size) {
extern M2C_UNK data_ov010_0222d908;
void MI_CpuFill32(s32,void *,u32);
u32 n=size/0x478; s32 i;
M2C_FIELD(&data_ov010_0222d908,void **,8)=p;
if(n<4 || n>0x48)return 0;
if(!p)return 0;
if((u32)p&31){M2C_FIELD(&data_ov010_0222d908,void **,8)=0;return 0;}
MI_CpuFill32(0,p,size);
for(i=0;i<n-1;i++) {
void *base=M2C_FIELD(&data_ov010_0222d908,void **,8);
M2C_FIELD(base+i*0x478,void **,0)=base+(i+1U)*0x478;
}
M2C_FIELD(M2C_FIELD(&data_ov010_0222d908,void **,8)+n*0x478,void **,-0x478)=0;
M2C_FIELD(&data_ov010_0222d908,void **,4)=M2C_FIELD(&data_ov010_0222d908,void **,8);
return 1;
}

void func_ov010_02224ea0(void) {
    extern M2C_UNK data_ov010_0222d908;
    M2C_FIELD(&data_ov010_0222d908, s32 *, 4) = 0;
    M2C_FIELD(&data_ov010_0222d908, s32 *, 8) = 0;
}

void *func_ov010_02224eb8(void) {
extern M2C_UNK data_ov010_0222d908;
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32);
void *r=0; void *p;
M2C_FIELD(&data_ov010_0222d908,s32 *,0)=OS_DisableInterrupts();
p=M2C_FIELD(&data_ov010_0222d908,void **,4);
if(p){r=p;M2C_FIELD(&data_ov010_0222d908,void **,4)=M2C_FIELD(p,void **,0);}
OS_RestoreInterrupts(M2C_FIELD(&data_ov010_0222d908,s32 *,0));return r;
}

void Link_FreePacket(void *p){extern M2C_UNK data_ov010_0222d908;s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);M2C_FIELD(&data_ov010_0222d908,s32 *,0)=OS_DisableInterrupts();M2C_FIELD(p,void **,0)=M2C_FIELD(&data_ov010_0222d908,void **,4);M2C_FIELD(&data_ov010_0222d908,void **,4)=p;OS_RestoreInterrupts(M2C_FIELD(&data_ov010_0222d908,s32 *,0));}

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

