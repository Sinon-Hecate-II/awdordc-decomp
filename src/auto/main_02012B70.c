/* 19 functions from 0x02012B70 to 0x02013B54 (main), found by ds-decomp. */
#include "common.h"
#include "wfc_channel.h"
#pragma push
#pragma optimization_level 0
static inline u16 InitTransferState(s32 buffer,s32 channel,s32 flags,s32 count,s32 option,s32 mode) {
u16 *p=(u16 *)(buffer+0x800);
u16 bits;
p[4]=0;p[5]=0;p[6]=0;p[8]=count;p[11]=channel;p[7]=0;
bits=flags|(1<<mode);
p[12]=option!=0;p[7]=bits;
return bits;
}
#pragma pop


s32 func_02012b70(s32 arg0, void *arg1) {
void *WFC_GetInfoBlock(); s32 WFC_CheckReady(void *); s32 WFC_SetChannelParam(s32,s32); void CpuFill(s32,void *,s32); void func_02007e70(void *,void *,s32); s32 WFC_SendCommandPacket(void *,s32);
u32 buf[8]; s32 r;
r=WFC_CheckReady(WFC_GetInfoBlock()); if(r) return r;
WFC_SetChannelParam(0x23,arg0); CpuFill(0,buf,0x20);
*(u16 *)buf=0x23; func_02007e70(arg1,&buf[1],0x1c);
r=WFC_SendCommandPacket(buf,0x20); if(!r) r=2; return r;
}

void func_02012be4(s32 arg0, s16 arg1) {
void CpuFill(s32,void *,s32);
u32 buf[7];
CpuFill(0,buf,0x1c); buf[0]=3; ((s16 *)buf)[2]=arg1; ((s16 *)buf)[3]=arg1; func_02012b70(arg0,buf);
}

/* Queue a WFC data-send event for `len` bytes at `buf`: refuse when the link is
   not up or not ready, when the buffer is null, oversized, empty or the link's
   own receive buffer, write the buffer back to memory, then post the event. */
s32 WFC_SendChannelData(s32 a,s32 b,void *buf,u32 len,u16 c,u16 d,u16 e) {
void *WFC_GetInfoBlock(void);s32 WFC_CheckChannelState(s32,s32);s32 DC_InvalidateRange(s32,s32);void DC_CleanRange(void *,u32);s32 WFC_SendCommand(s32,s32);
u16 ready=1;void *link=M2C_FIELD(WFC_GetInfoBlock(),void **,4);s32 r;
r=((s32 (*)(s32,s32,s32))WFC_CheckChannelState)(2,9,10);if(r)return r;
DC_InvalidateRange((s32)link+0x3c,2);DC_InvalidateRange((s32)link+0x188,2);
if(M2C_FIELD(link,u16 *,0x188)==0){
DC_InvalidateRange((s32)link+0x182,2);ready=M2C_FIELD(link,u16 *,0x182);DC_InvalidateRange((s32)link+0x86,2);
}
if(!buf)return 6;if(!ready)return 7;
DC_InvalidateRange((s32)link+0x7c,2);if(buf==M2C_FIELD(link,void **,0x7c))return 6;
if(len>512)return 6;if(len==0)return 6;
DC_CleanRange(buf,len);
r=((s32 (*)(s32,s32,void *,u32,u16,u16,u16,s32,s32))WFC_SendCommand)(15,7,buf,len,c,d,e,a,b);
if(!r)r=2;return r;
}

s32 func_02012d64(s32 arg0) {
void *WFC_GetInfoBlock(); s32 WFC_CheckChannelState(s32,s32); s32 DC_InvalidateRange(s32,s32); s32 WFC_SetChannelParam(s32,s32); s32 WFC_SendCommand(s32,s32);
void *p; s32 r;
p=WFC_GetInfoBlock(); r=((s32 (*)(s32,s32,s32))WFC_CheckChannelState)(2,9,10); if(r) return r;
DC_InvalidateRange(M2C_FIELD(p,void **,4)+12,4);
if(M2C_FIELD(M2C_FIELD(p,void **,4),s32 *,12)==0) return 3;
WFC_SetChannelParam(16,arg0); r=WFC_SendCommand(16,0); if(!r) r=2; return r;
}

/* Send `length` bytes from `data` over the WFC data channel (command 17): refuse
 * when the link is not in the expected channel state, when it is in the request
 * mode, or when the payload is too small, write the buffer back to memory, then
 * post the command with `param` and the buffer. */
s32 WFC_SendDataBuffer(s32 param, void *data, u32 length) {
void *WFC_GetInfoBlock(); s32 WFC_CheckChannelState(s32,s32); s32 DC_InvalidateRange(s32,s32); void DC_CleanRange(void *,u32); s32 WFC_SetChannelParam(s32,s32); s32 WFC_SendCommand(s32,s32);
void *info; s32 result;
info=WFC_GetInfoBlock(); result=WFC_CheckChannelState(1,8); if(result) return result;
DC_InvalidateRange(M2C_FIELD(info,void **,WFC_INFO_LINK)+16,4);
if(M2C_FIELD(M2C_FIELD(info,void **,WFC_INFO_LINK),s32 *,16)==1) return 3;
if(length<16) return 6; if(!data) return 6;
DC_CleanRange(data,length); WFC_SetChannelParam(17,param); result=((s32 (*)(s32,s32,void *,u32))WFC_SendCommand)(17,2,data,length); if(!result) result=2; return result;
}

/* Submit a WFC request: check the channel is in the expect-state, verify it is up
 * and the payload fits, clean the payload, store the request id as the command's
 * parameter and post command 18 with the 6-byte prefix and the payload. */
s32 WFC_SubmitRequest(s32 requestId,void *header,void *data,u32 length) {
 void *WFC_GetInfoBlock(); s32 WFC_CheckChannelState(s32,s32); s32 DC_InvalidateRange(s32,s32); void DC_CleanRange(void *,u32); s32 WFC_SetChannelParam(s32,s32); s32 WFC_SendCommand(s32,s32); void MI_CpuCopy8(void *,void *,u32);
 u32 prefix[2]; void *info; s32 result;
 info=WFC_GetInfoBlock();result=WFC_CheckChannelState(1,11);if(result)return result;
 DC_InvalidateRange(M2C_FIELD(info,void **,4)+16,4);
 if(M2C_FIELD(M2C_FIELD(info,void **,4),s32 *,16)==0)return 3;
 if(length>1508)return 6;
 DC_CleanRange(data,length);
 WFC_SetChannelParam(18,requestId);
 MI_CpuCopy8(header,prefix,6);
 result=((s32 (*)(s32,s32,u32,u32,void *,u32))WFC_SendCommand)(18,4,prefix[0],prefix[1],data,length);
 if(!result)result=2;return result;
}

s32 WFC_SubmitLinkRequest(M2C_UNK arg0) {
    M2C_UNK DC_InvalidateRange(s32, M2C_UNK);
    M2C_UNK WFC_SetChannelParam(M2C_UNK, M2C_UNK);
    s32 WFC_SendCommand(M2C_UNK, M2C_UNK);
    void *WFC_GetInfoBlock();
    s32 WFC_CheckChannelState(M2C_UNK, M2C_UNK);
    s32 temp_r0;
    s32 var_r0;
    void *temp_r4;

    temp_r4 = WFC_GetInfoBlock();
    temp_r0 = WFC_CheckChannelState(1, 0xB);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    DC_InvalidateRange(M2C_FIELD(temp_r4, void **, 4) + 0x10, 4);
    if (M2C_FIELD(M2C_FIELD(temp_r4, void **, 4), s32 *, 0x10) == 0) {
        return 3;
    }
    WFC_SetChannelParam(0x13, arg0);
    var_r0 = WFC_SendCommand(0x13, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_strength_reduction off
s32 func_02012fac(s32 buffer,s32 channel,s32 flags,s32 count,s32 option) {
s32 WFC_CheckChannelState();s32 func_02011934(void);s32 func_02011994(void);
void MI_CpuFill32(s32,void *,s32);s32 CountBits(s32);s32 WFC_SetChannelHandler(u16,s32,s32);
void WFC_ParentChannelHandler(void *);void WFC_ChildChannelHandler(void *);void WFC_OnChannelSendComplete(void *);
s32 mode,mask=1,result,i,opt;u32 bits;u16 *p;u8 *block;
result=WFC_CheckChannelState(2,9,10);if(result)return result;
if(!buffer)return 6;if((u32)channel>=16)return 6;if(!flags)return 6;
mode=func_02011934();if(!mode)mask=func_02011994();
MI_CpuFill32(0,(void *)buffer,0x820);
p=(u16 *)(buffer+0x800);
p[4]=0;p[5]=0;p[6]=0;p[8]=count;p[11]=channel;p[7]=0;
bits=flags|(1<<mode);
opt=option?1:0;((u16 *)(buffer+0x800))[12]=opt;
bits=(u16)bits;((u16 *)(buffer+0x800))[7]=bits;
result=CountBits(bits);p=(u16 *)(buffer+0x800);
p[9]=result;p[10]=count*result;
if((u32)p[10]>508){p[7]=0;return 6;}
p[10]+=4;p[14]=1;
if(!mode){
for(i=0;i<4;i++)*(u16 *)(buffer+(i<<9))=p[7]&(mask|1);
((s32 (*)(s32,s32,s32))WFC_SetChannelHandler)(channel,(s32)WFC_ParentChannelHandler,buffer);
p=(u16 *)(buffer+0x800);
block=(u8 *)buffer;
for(i=0;i<(p[12]==1?2:1);i++){
p[4]=(p[4]+1)&3;
result=WFC_SendChannelData((s32)WFC_OnChannelSendComplete,buffer,block,p[10],(u16)(p[7]&mask),p[11],1);
if(result==7){*(u16 *)(buffer+i*2+0x800)=0xffff;p[5]=(p[5]+1)&3;}
else if(result!=0&&result!=2){((u16 *)(buffer+0x800))[14]=5;return 1;}
block+=512;
}
}else{
p[5]=3;((s32 (*)(s32,s32,s32))WFC_SetChannelHandler)(channel,(s32)WFC_ChildChannelHandler,buffer);
}
return 0;
}
#pragma pop
s32 func_02013200(void *arg0) {
    M2C_UNK WFC_SetChannelHandler(u16, M2C_UNK, M2C_UNK);
    if (arg0 == NULL) {
        return 6;
    }
    if (M2C_FIELD(arg0, u16 *, 0x80E) == 0) {
        return 3;
    }
    WFC_SetChannelHandler(M2C_FIELD(arg0, u16 *, 0x816), 0, 0);
    M2C_FIELD(arg0, u16 *, 0x80E) = 0U;
    M2C_FIELD(arg0, s16 *, 0x81C) = 0;
    return 0;
}

s32 func_02013248(s32 arg0, void *arg1, void *arg2) {
    s32 WFC_CheckChannelState(s32, s32);
    s32 func_02011934(void);
    s32 func_02011994(void);
    s32 WFC_SendChannelData(s32, s32, void *, u32, u16, u16, u16);
    void CopyU16(void *, void *, u32);
    void WFC_StoreReceiveData(void *, u32, void *);
    void WFC_PostReceive(void *, s32);
    void WFC_OnChannelSendComplete(void *);
    s32 r5;
    s32 r4;
    s32 r7;
    s32 r6;
    s32 r11;
    s32 r10 = arg0;
    s32 r9 = arg1;
    s32 r8 = arg2;
    s32 ret, state;
    u16 *slot;

    ret = ((s32 (*)(s32, s32, s32))WFC_CheckChannelState)(2, 9, 10);
    if (ret != 0) return ret;
    if (r10 == 0) return 6;
    if (r9 == 0) return 6;
    if (r8 == 0) return 6;
    r5 = func_02011934();
    if (r5 == 0) r4 = func_02011994();
    state = M2C_FIELD(r10, u16 *, 0x81c);
    if (state == 5) return 1;
    if (state != 1 && state != 4) return 3;
    r7 = 5;
    if (r5 == 0) {
        r5 = 0;
        r11 = 0;
        if (state == 4) {
            M2C_FIELD(r10, u16 *, 0x81c) = 1;
            r6 = (M2C_FIELD(r10, u16 *, 0x808) + 3) & 3;
            ret = WFC_SendChannelData((s32)WFC_OnChannelSendComplete, r10, (void *)(r10 + (r6 << 9)), M2C_FIELD(r10, u16 *, 0x814), (u16)(M2C_FIELD(r10, u16 *, 0x80e) & r4), M2C_FIELD(r10, u16 *, 0x816), 1);
            if (ret == 7) {
                M2C_FIELD((void *)(r10 + (r6 << 1)), u16 *, 0x800) = 0xffff;
                M2C_FIELD(r10, u16 *, 0x80a) = (u16)((M2C_FIELD(r10, u16 *, 0x80a) + 1) & 3);
            } else if (ret != 0 && ret != 2) {
                M2C_FIELD(r10, u16 *, 0x81c) = 5;
                return 1;
            }
        }
        if (M2C_FIELD(r10, u16 *, 0x80c) != M2C_FIELD(r10, u16 *, 0x80a)) {
            r6 = M2C_FIELD(r10, u16 *, 0x80c);
            M2C_FIELD((void *)(r10 + (r6 << 9)), u16 *, 0) = (u16)(M2C_FIELD((void *)(r10 + (r6 << 9)), u16 *, 0) | 1);
            CopyU16((void *)(r10 + (M2C_FIELD(r10, u16 *, 0x80c) << 9)), r8, 0x200);
            M2C_FIELD(r10, u16 *, 0x81a) = M2C_FIELD((void *)(r10 + (M2C_FIELD(r10, u16 *, 0x80c) << 1)), u16 *, 0x800);
            M2C_FIELD(r10, u16 *, 0x80c) = (u16)((M2C_FIELD(r10, u16 *, 0x80c) + 1) & 3);
            r5 = 1;
            r7 = 0;
            if (M2C_FIELD(r10, u16 *, 0x818) == 0 && r4 != 0 && M2C_FIELD((void *)(r10 + (M2C_FIELD(r10, u16 *, 0x808) << 9)), u16 *, 0) == 1)
                r11 = r5;
        }
        WFC_PostReceive(r10, 0);
        if (r5 != 0) {
            WFC_StoreReceiveData(r10, 0, r9);
            if (M2C_FIELD(r10, u16 *, 0x818) == 0) WFC_PostReceive(r10, r11);
        }
    } else {
        r6 = 0;
        if (state == 4) {
            M2C_FIELD(r10, u16 *, 0x81c) = 1;
            r6 = 1;
        } else if (M2C_FIELD(r10, u16 *, 0x80c) != M2C_FIELD(r10, u16 *, 0x808)) {
            slot = (u16 *)(r10 + (M2C_FIELD(r10, u16 *, 0x80c) << 9));
            if ((*slot & 1) == 0) {
                *slot = (u16)(*slot | 1);
            } else {
                CopyU16(slot, r8, 0x200);
                M2C_FIELD(r10, u16 *, 0x81a) = M2C_FIELD((void *)(r10 + (M2C_FIELD(r10, u16 *, 0x80c) << 1)), u16 *, 0x800);
                M2C_FIELD(r10, u16 *, 0x80c) = (u16)((M2C_FIELD(r10, u16 *, 0x80c) + 1) & 3);
                r7 = 0;
                r6 = 1;
            }
        }
        if (r6 != 0) {
            slot = (u16 *)(r10 + (M2C_FIELD(r10, u16 *, 0x80a) << 9));
            CopyU16(r9, (u8 *)slot + 0x20, M2C_FIELD(r10, u16 *, 0x810));
            ret = WFC_SendChannelData((s32)WFC_OnChannelSendComplete, r10, (u8 *)slot + 0x20, M2C_FIELD(r10, u16 *, 0x810), M2C_FIELD(r10, u16 *, 0x80e), M2C_FIELD(r10, u16 *, 0x816), 1);
            M2C_FIELD(r10, u16 *, 0x80a) = (u16)((M2C_FIELD(r10, u16 *, 0x80a) + 1) & 3);
            if (ret != 0 && ret != 2) {
                M2C_FIELD(r10, u16 *, 0x81c) = 5;
                r7 = 1;
            }
        }
    }
    return r7;
}

/* Send-completion callback of a WFC channel: ignore events that are not for a
 * set-up channel; record the slot's start sequence when the parent's send went
 * through, rewind the slot when the receiver had no room, and mark the channel
 * failed on any other result. */
void WFC_OnChannelSendComplete(void *event) {
 void *WFC_GetInfoBlock(void); s32 func_02011934(void); void WFC_ParentChannelHandler(void *);void WFC_ChildChannelHandler(void *);
 void *channel=WFC_GetInfoBlock(); void *state; void *callback; s32 playerIndex;
 channel=(u8 *)channel+M2C_FIELD(event,u16 *,WFC_EVENT_CHANNEL)*4;
 callback=M2C_FIELD(channel,void **,WFC_INFO_CHANNEL_CALLBACK);
 state=M2C_FIELD(channel,void **,WFC_INFO_CHANNEL_OBJECT);
 if(callback!=(void *)WFC_ParentChannelHandler && callback!=(void *)WFC_ChildChannelHandler)return;
 if(!state)return;
 if(state!=M2C_FIELD(event,void **,WFC_EVENT_SEND_OBJECT))return;
 playerIndex=func_02011934();
 if(M2C_FIELD(event,u16 *,WFC_EVENT_RESULT)==WFC_EVENT_RESULT_DONE) {
 if(playerIndex)return;
 ((u16 *)((u8 *)state+WFC_CH_SENT_SEQUENCE))[M2C_FIELD(state,u16 *,WFC_CH_SEND_INDEX)]=M2C_FIELD(event,u16 *,WFC_EVENT_SEQUENCE)>>1;
 M2C_FIELD(state,u16 *,WFC_CH_SEND_INDEX)=(M2C_FIELD(state,u16 *,WFC_CH_SEND_INDEX)+1)&3;
 return;
 }
 if(M2C_FIELD(event,u16 *,WFC_EVENT_RESULT)==WFC_EVENT_RESULT_NO_ROOM) {
 if(playerIndex)M2C_FIELD(state,u16 *,WFC_CH_SEND_INDEX)=(M2C_FIELD(state,u16 *,WFC_CH_SEND_INDEX)+3)&3;
 M2C_FIELD(state,u16 *,WFC_CH_SEND_STATE)=WFC_CH_STATE_RETRY;
 } else M2C_FIELD(state,u16 *,WFC_CH_SEND_STATE)=WFC_CH_STATE_FAILED;
}

void WFC_ParentChannelHandler(void *p) {
void WFC_StoreReceiveData(void *,u32,void *);
s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);void WFC_PostReceive(void *,s32);
void *q=M2C_FIELD(p,void **,0x1c);s32 bit,irq;u32 one=1;u16 slot;
if(!q)return;
if(M2C_FIELD(p,u16 *,2)==0) {
switch((s32)M2C_FIELD(p,u16 *,4)) {
case 21:WFC_StoreReceiveData(q,M2C_FIELD(p,u16 *,0x12),M2C_FIELD(p,void **,12));WFC_PostReceive(q,0);break;
case 7:WFC_PostReceive(q,0);break;
case 25:break;
case 9:case 26:
bit=M2C_FIELD(p,u16 *,0x12);irq=OS_DisableInterrupts();
slot=M2C_FIELD(q,u16 *,0x808);
((u16 (*)[256])q)[slot][0]&=~(one<<bit);
if(M2C_FIELD(q,u16 *,0x818)==one){slot=(slot+1)&3;((u16 (*)[256])q)[slot][0]&=~(one<<bit);}
OS_RestoreInterrupts(irq);WFC_PostReceive(q,0);
if(M2C_FIELD(q,u16 *,0x818)==one)WFC_PostReceive(q,0);
break;
}
}else M2C_FIELD(q,u16 *,0x81c)=5;
}

void WFC_ChildChannelHandler(void *p) {
void CopyU16(void *,void *,u32);s32 func_02011934(void);
void *q=M2C_FIELD(p,void **,0x1C);u16 *data;u16 mask;u32 len;s32 bit;
if(!q)return;
if(M2C_FIELD(p,u16 *,2)==0) {
switch((s32)M2C_FIELD(p,u16 *,4)) {
case 7:case 9:
case 25:case 26:
case 21:
len=M2C_FIELD(p,u16 *,0x10);data=M2C_FIELD(p,u16 **,0xC);mask=*data;bit=func_02011934();
if(len!=M2C_FIELD(q,u16 *,0x814)){if(len>0x200)len=0x200;}
if(len<4)return;
if(!(mask&(1<<bit)))return;
CopyU16(data,q+(M2C_FIELD(q,u16 *,0x808)<<9),len);
M2C_FIELD(q+M2C_FIELD(q,u16 *,0x808)*2,u16 *,0x800)=(s32)M2C_FIELD(p,u16 *,0x1A)>>1;
M2C_FIELD(q,u16 *,0x808)=(M2C_FIELD(q,u16 *,0x808)+1)&3;
break;
}
}else M2C_FIELD(q,u16 *,0x81C)=5;
}

/* Stores a player's received payload into the channel's current transfer slot:
 * the payload goes to that player's copy of the slot's data; a null `src` zeroes
 * the copy instead. The player is then marked present in the slot and cleared
 * from the set of players the slot still misses. The host channel may hand the
 * data to the next slot when the current one is not marked for the player. */
void WFC_StoreReceiveData(void *state,u32 index,void *src) {
 void CopyU16(void *,void *,u32);void FillU16(s32,void *,u32);s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);
 u16 playerBit=1<<index; u16 slot; void *dst; s32 irq;
 if(!(M2C_FIELD(state,u16 *,WFC_CH_PLAYER_MASK)&playerBit))return;
 slot=M2C_FIELD(state,u16 *,WFC_CH_SLOT_INDEX);
 if(!(((u16 (*)[256])state)[slot][0]&playerBit)) {
 if(M2C_FIELD(state,u16 *,WFC_CH_PARENT_MODE)!=1)return;
 slot=(slot+1)&3;
 if(!(M2C_FIELD(state,u16 *,slot<<9)&playerBit))return;
 }
 dst=(void *)WFC_PlayerDataOffset(state,M2C_FIELD(state,u16 *,WFC_CH_PLAYER_MASK),(s32)&((u16 (*)[256])state)[slot][2],index);
 if(src)CopyU16(src,dst,M2C_FIELD(state,u16 *,WFC_CH_PAYLOAD_LEN));
 else FillU16(0,dst,M2C_FIELD(state,u16 *,WFC_CH_PAYLOAD_LEN));
 irq=OS_DisableInterrupts();
 M2C_FIELD(state,u16 *,slot<<9)&=~playerBit;
 ((u16 (*)[256])((u8 *)state+2))[slot][0]|=playerBit;
 OS_RestoreInterrupts(irq);
}

/* Post the next slot of the WFC receive ring: when the slot currently being
 * received into is still free, clear the next slot, mark the freed slot ready
 * to be sent to every connected peer, advance the ring and submit a new
 * receive on the freed slot. dropSelf clears the self bit so the slot is not
 * looped back. */
void WFC_PostReceive(void *state, s32 dropSelf) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 func_02011994(void);
    void FillU16(s32, void *, u32);
    s32 savedIrq = OS_DisableInterrupts();
    s32 freeSlot, nextSlot, curSlot, peerMask, result;
    if (((u16 (*)[256])state)[M2C_FIELD(state, u16 *, 0x808)][0] == 0) {
        peerMask = func_02011994();
        curSlot = M2C_FIELD(state, u16 *, 0x808);
        nextSlot = (curSlot + 1) & 3;
        if (M2C_FIELD(state, u16 *, 0x818) == 1) freeSlot = (nextSlot + 1) & 3;
        else freeSlot = nextSlot;
        FillU16(0, state + (freeSlot << 9), 512);
        ((u16 (*)[256])state)[freeSlot][0] = M2C_FIELD(state, u16 *, 0x80e) & (peerMask | 1);
        M2C_FIELD(state, u16 *, 0x808) = nextSlot;
        ((u16 (*)[256])state)[curSlot][0] = M2C_FIELD(state, u16 *, 0x80e);
        if (dropSelf == 1) ((u16 (*)[256])state)[curSlot][0] &= ~1;
        OS_RestoreInterrupts(savedIrq);
        result = WFC_SendChannelData((s32)WFC_OnChannelSendComplete, (s32)state, state + (curSlot << 9), M2C_FIELD(state, u16 *, 0x814), (u16)(M2C_FIELD(state, u16 *, 0x80e) & peerMask), M2C_FIELD(state, u16 *, 0x816), 1);
        if (result == 7) {
            M2C_FIELD(state + curSlot * 2, u16 *, 0x800) = 0xffff;
            M2C_FIELD(state, u16 *, 0x80a) = (M2C_FIELD(state, u16 *, 0x80a) + 1) & 3;
            return;
        }
        if (result == 0 || result == 2) return;
        M2C_FIELD(state, u16 *, 0x81c) = 5;
    } else OS_RestoreInterrupts(savedIrq);
}

#pragma scheduling off
s32 func_02013aa8(void *arg0, void *arg1, s32 arg2) {
u16 a=M2C_FIELD(arg1,u16 *,0); u16 b=M2C_FIELD(arg1,u16 *,2);
u32 mask=1u<<arg2;
if(!arg0) return 0; if(!arg1) return 0;
if(!(a & mask)) return 0;
if(!(b & mask)) return 0;
return WFC_PlayerDataOffset(arg0,a,(s32)arg1+4,arg2);
}
#pragma scheduling reset
s32 WFC_PlayerDataOffset(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 CountBits(s32);
    return (M2C_FIELD(arg0, u16 *, 0x810) * CountBits(arg1 & ((1 << arg3) - 1))) + arg2;
}

void func_02013b2c(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02012fac(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02012fac(arg0, arg1, 0xFFFF, 2, 1);
}

void func_02013b48(void) {
    M2C_UNK func_02013200();
    func_02013200();
}
