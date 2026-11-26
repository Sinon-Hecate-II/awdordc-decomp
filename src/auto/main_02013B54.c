/* 17 functions from 0x02013B54 to 0x02014B34 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
typedef struct { u8 low:4; u8 high:4; } Packet14564;

/* Submit the local player's user info to the WFC firmware as command 20 request
 * 2: the user type (0..3) and, unless that type is 0, the 0x50-byte display name
 * to announce. Refuses until the command channel is open, flushes the name out
 * of the data cache, then posts the type and the name. Returns 2 once queued. */
s32 WFC_SubmitUserInfo(M2C_UNK channelHandler, u32 userType, s32 name) {
    M2C_UNK DC_CleanRange(s32, M2C_UNK);
    s32 result = WFC_CheckChannelOpen();
    if (result) return result;
    if (userType > WFC_SESSION_MODE_MAX) return WFC_CMD_BAD_PARAM;
    if (userType) {
        if (!name) return WFC_CMD_BAD_PARAM;
        DC_CleanRange(name, WFC_SESSION_NAME_LEN);
    }
    WFC_SetChannelParam(20, channelHandler);
    result = WFC_SendCommand(20, 2, userType, name);
    if (!result) result = WFC_CMD_OK;
    return result;
}

/* Submit the local player's match settings (mode, sub-mode and display name) to
 * the WFC server as command 39 request 3: refuse unless the command channel is
 * open and the mode is one of 0..3, flush the name out of the data cache, then
 * post the mode, the name and the sub-mode.  Returns 2 once the request is
 * queued. */
s32 WFC_SubmitMatchSettings(M2C_UNK channelHandler, u32 mode, s32 subMode, s32 name) {
    M2C_UNK DC_CleanRange(s32, M2C_UNK);
    s32 result = WFC_CheckChannelOpen();
    if (result) return result;
    if (mode > WFC_SESSION_MODE_MAX) return WFC_CMD_BAD_PARAM;
    if (mode) {
        if (!name) return WFC_CMD_BAD_PARAM;
        DC_CleanRange(name, WFC_SESSION_NAME_LEN);
    }
    WFC_SetChannelParam(39, channelHandler);
    result = WFC_SendCommand(39, 3, mode, name, subMode);
    if (!result) result = WFC_CMD_OK;
    return result;
}

/* Submit a download-play data block to the WFC channel: require the channel to be
 * in one of the states this request may be sent from, copy the caller's block
 * into the shared request buffer and hand it to the WFC driver as command 24. */
s32 WFC_SubmitDownloadData(s32 channelParam, void *data, u32 length, s32 sendCode, u16 sequence, u8 flags) {
    M2C_UNK CopyU16(s32, M2C_UNK *, u32);
    extern M2C_UNK gWfcRequestBuffer;
    s32 result = WFC_CheckChannelState(2, 7, 9);
    if (result) return result;
    if (!data) return 6;
    if (length > 112) return 6;
    CopyU16((s32) data, &gWfcRequestBuffer, length);
    DC_CleanRange(&gWfcRequestBuffer, length);
    WFC_SetChannelParam(24, channelParam);
    result = WFC_SendCommand(24, 5, &gWfcRequestBuffer, length, sendCode, (s32) sequence, (s32) flags);
    if (!result) result = 2;
    return result;
}

/* Tell the WFC firmware whether this console is the match's parent (host) via
 * command WFC_CMD_PARENT request 1.  Download play posts 1 (host), the online
 * session 0.  Refuses until the command channel is open and the flag is 0 or 1;
 * returns the channel's error, or WFC_CMD_OK once the request is queued. */
s32 WFC_SubmitParentMode(M2C_UNK channelHandler, s32 parentMode) {
    s32 WFC_CheckChannelOpen();
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = WFC_CheckChannelOpen();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if ((parentMode != 0) && (parentMode != 1)) {
        return WFC_CMD_BAD_PARAM;
    }
    WFC_SetChannelParam(WFC_CMD_PARENT, channelHandler);
    var_r0 = WFC_SendCommand(WFC_CMD_PARENT, 1, parentMode);
    if (var_r0 == 0) {
        var_r0 = WFC_CMD_OK;
    }
    return var_r0;
}

/* Post the WFC connection request (command WFC_CMD_CONNECT, request 4) with its
 * four connection parameters. Refuses until the command channel is open; returns
 * the channel's error, or WFC_CMD_OK once the request is queued. */
s32 WFC_SubmitConnectRequest(M2C_UNK channelHandler, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, u16 arg4) {
    s32 error;
    s32 result;

    error = WFC_CheckChannelOpen();
    if (error != 0) {
        return error;
    }
    WFC_SetChannelParam(WFC_CMD_CONNECT, channelHandler);
    result = WFC_SendCommand(WFC_CMD_CONNECT, 4, arg1, arg2, arg3, (s32) arg4);
    if (result == 0) {
        result = WFC_CMD_OK;
    }
    return result;
}

/* Queue a channel occupancy measurement while the wireless manager is idle. */
s32 WFC_MeasureChannel(s32 callback, s16 ccaMode, s16 edThreshold, s16 channel, u16 measureTime) {
    s32 WFC_SendCommandPacket(void *, s32);
    s32 WFC_GetInfoBlock(void);
    WfcMeasureChannelRequest request;
    s32 result;

    WFC_GetInfoBlock();
    result = WFC_CheckChannelState(1, WFC_MEASURE_CHANNEL_IDLE_STATE);
    if (result) {
        return result;
    }
    WFC_SetChannelParam(WFC_CMD_MEASURE_CHANNEL, callback);
    request.command = WFC_CMD_MEASURE_CHANNEL;
    request.ccaMode = ccaMode;
    request.edThreshold = edThreshold;
    request.channel = channel;
    request.measureTime = measureTime;
    result = WFC_SendCommandPacket(&request, sizeof(request));
    if (!result) {
        result = WFC_CMD_OK;
    }
    return result;
}

/* Switch the link's download-transfer mode through WFC command 0x21: refuse
 * until the link is in one of the states the request may be sent from, install
 * `callback` as the command's completion handler and post the download flag.
 * Returns the channel's error, or WFC_CMD_OK once the request is queued. */
s32 WFC_SubmitDownloadMode(M2C_UNK callback, s32 downloadMode) {
    M2C_UNK WFC_SetChannelParam(M2C_UNK, M2C_UNK);
    s32 WFC_SendCommand(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 WFC_CheckChannelState(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 result;
    s32 commandResult;

    result = WFC_CheckChannelState(2, 7, 9);
    if (result != 0) {
        return result;
    }
    WFC_SetChannelParam(WFC_CMD_DOWNLOAD_MODE, callback);
    commandResult = WFC_SendCommand(WFC_CMD_DOWNLOAD_MODE, 1, downloadMode);
    if (commandResult == 0) {
        commandResult = WFC_CMD_OK;
    }
    return commandResult;
}

/* Set the multiboot match's event callback in the match work area, with
 * interrupts off so the link task cannot see a half-written pointer. */
void Mb_SetMatchEventCallback(void (*callback)(s32, s32, void *)) {
    s32 OS_DisableInterrupts();
    void OS_RestoreInterrupts(s32);
    extern s32 gMbWork;
    s32 saved = OS_DisableInterrupts();

    M2C_FIELD(gMbWork, s32 *, MB_EVENT_CALLBACK) = (s32)callback;
    OS_RestoreInterrupts(saved);
}

#pragma opt_strength_reduction off
/* Returns a copy of player `player`'s multiboot info block, or NULL when the
 * match work area is gone or the player id is not a valid one.  The copy is
 * made with interrupts off so the block cannot change under the caller. */
void *MultiBoot_GetPlayerInfo(s32 player) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 Mb_IsValidPlayer(s32);
    void MI_CpuCopy8(void *, void *, u32);
    extern s32 gMbWork;
    s32 state = OS_DisableInterrupts();

    if (gMbWork && Mb_IsValidPlayer(player)) {
        MI_CpuCopy8((void *)(gMbWork + MB_PLAYER_INFO + (player - 1) * MB_PLAYER_INFO_SIZE),
                    (void *)(gMbWork + MB_PLAYER_INFO_OUT), MB_PLAYER_INFO_SIZE);
        OS_RestoreInterrupts(state);
        return (void *)(gMbWork + MB_PLAYER_INFO_OUT);
    }
    OS_RestoreInterrupts(state);
    return 0;
}
#pragma opt_strength_reduction reset
/* True while the multiboot match work area is live and player `player` has
 * finished its setup (its slot state is MB_PLAYER_STATE_READY). */
s32 Mb_IsPlayerReady(s32 player) {
    extern s32 gMbWork;
    s32 Mb_IsValidPlayer();
    if (gMbWork && Mb_IsValidPlayer(player)) {
        if (M2C_FIELD(gMbWork + (player - 1) * 4, s32 *, MB_PLAYER_STATE_FIRST) == MB_PLAYER_STATE_READY) return 1;
    }
    return 0;
}

/* Notes that player `player` has acknowledged a step of the multiboot match
 * setup (phase 0..3): only if the player is in the expected state does its
 * per-player pending value change. Returns 1 when it did. */
s32 Mb_AckPlayerPhase(s32 player, u32 phase) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 Mb_IsValidPlayer(s32);
    extern s32 gMbWork;
    u32 pending; s32 expected; s32 saved;
    saved = OS_DisableInterrupts();
    switch (phase) {
    case 0: expected = 10; pending = 4; break;
    case 1: expected = 10; pending = 3; break;
    case 2: expected = 14; pending = 2; break;
    case 3: expected = 7; pending = 5; break;
    default:
        OS_RestoreInterrupts(saved);
        return 0;
    }
    if (gMbWork && Mb_IsValidPlayer(player)) {
        s32 idx = player - 1;
        u8 *base = (u8 *)gMbWork;
        if (expected == *(s32 *)(base + idx * 4 + 0x14e8)) {
            *(u16 *)(base + idx * 2 + 0x1754) = pending;
            OS_RestoreInterrupts(saved);
            return 1;
        }
    }
    OS_RestoreInterrupts(saved);
    return 0;
}

/* Store player `player`'s multiboot state and dispatch the matching event to the
 * work area's command callback: the state is only written for a valid player but
 * the event is dispatched either way. */
void Mb_SetPlayerState(s32 player, s32 state, M2C_UNK packet) {
    s32 Mb_IsValidPlayer(s32);
    extern s32 gMbWork;
    M2C_UNK Mb_DispatchPlayerEvent(s32, s32, M2C_UNK);
    if (Mb_IsValidPlayer(player) != 0) {
        M2C_FIELD((gMbWork + ((player - 1) * 4)), s32 *, MB_PLAYER_STATE_FIRST) = state;
    }
    Mb_DispatchPlayerEvent(player, state, packet);
}

/* Run the match's multiboot event callback (installed by
 * Mb_SetMatchEventCallback) for `player` with one of the MB_EVENT_* events,
 * passing `packet` along; nothing happens while no callback is installed. */
M2C_UNK Mb_DispatchPlayerEvent(s32 player, s32 event, M2C_UNK packet) {
    extern s32 gMbWork;
    void (*callback)(s32, s32, M2C_UNK) = M2C_FIELD(gMbWork, void (**)(s32, s32, M2C_UNK), MB_EVENT_CALLBACK);
    if (!callback) return;
    callback(player, event, packet);
}

#pragma opt_scheduling off
#pragma opt_common_subs off
void func_020140c4(s32 a, void *b) {
extern s32 gMbWork;
void ProcessGroupStartMessages(s32); void MI_CpuFill8(); void MultiBoot_ClearRecordSlot(); void func_02015008(); void DownloadFileSetRoster(); s32 func_02018390(); s32 func_020183a4(); s32 Mb_GetDownloadSendFlags(); void DownloadSendStep(); void func_02015230(); void MI_CpuFill32();
s32 id, idx, off, group; u8 i; s32 x,y,z;
switch(a) {
case 17: break;
case 21: Mb_SetPlayerState(0,1,(s32)b); break;
case 0: if(*(u16*)((u8*)b+16)!=0 && *(u16*)((u8*)b+16)<16) Mb_SetPlayerState(*(u16*)((u8*)b+16),2,(s32)b); break;
case 1:
if(*(u16*)((u8*)b+16)==0 || *(u16*)((u8*)b+16)>=16) break;
M2C_FIELD(gMbWork+(*(u16*)((u8*)b+16)-1)*2,u16*,0x148a)=0;
MI_CpuFill8(gMbWork+0x14a8+(*(u16*)((u8*)b+16)-1)*4,0,4);
MI_CpuFill8(gMbWork+0x1340+(*(u16*)((u8*)b+16)-1)*22,0,22);
MultiBoot_ClearRecordSlot(*(u16*)((u8*)b+16));
M2C_FIELD(gMbWork+(*(u16*)((u8*)b+16)-1)*2,u16*,0x1754)=0;
id=*(u16*)((u8*)b+16); idx=id-1;
group=M2C_FIELD(gMbWork+idx,s8*,0x1526);
if(group!=-1) {
off=(u8)group*0x5d4;
M2C_FIELD(gMbWork+off,u16*,0x1d4e)&=~(1<<id);
M2C_FIELD(gMbWork+off,u16*,0x1d50)|=1<<id;
M2C_FIELD(gMbWork+idx,s8*,0x1526)=-1;
M2C_FIELD(gMbWork+off,u16*,0x1d4c)&=~(1<<id);
}
if(M2C_FIELD(gMbWork,u16*,0x1536)&(1<<*(u16*)((u8*)b+16))) {
M2C_FIELD(gMbWork,u8*,0x1535)--;
M2C_FIELD(gMbWork,u16*,0x1536)&=~(1<<*(u16*)((u8*)b+16));
}
if(M2C_FIELD(gMbWork+(*(u16*)((u8*)b+16)-1)*4,s32*,0x14e8)==8) Mb_SetPlayerState(*(u16*)((u8*)b+16),9,0);
Mb_SetPlayerState(*(u16*)((u8*)b+16),3,(s32)b);
M2C_FIELD(gMbWork+(*(u16*)((u8*)b+16)-1)*4,s32*,0x14e8)=0;
break;
case 3: ProcessGroupStartMessages((s32)b); break;
case 25: func_02015008(); break;
case 28:
for(i=0;i<16;i++){
off=i*0x5d4;
if(M2C_FIELD(gMbWork+off,u8*,0x1d52) && M2C_FIELD(gMbWork+off,u16*,0x1d50)){
DownloadFileSetRoster(gMbWork+0x186c+off,gMbWork+0x1340,M2C_FIELD(gMbWork+off,u16*,0x1d4e),M2C_FIELD(gMbWork+off,u16*,0x1d50));
M2C_FIELD(gMbWork+off,u16*,0x1d50)=0;
}}
x=func_02018390(); y=func_020183a4(); z=Mb_GetDownloadSendFlags(); DownloadSendStep(x,y,z); break;
case 255:
switch(*(u16*)((u8*)b+2)){case 1:case 4:case 5:case 6:case 8:case 9:func_02015230(0,9);break;case 0:case 2:case 3:case 7:case 10:case 11:case 12:case 13:case 14:case 15:default:func_02015230(0,8);break;} break;
case 256:
switch(*(u16*)b){case 0:case 7:case 8:case 13:case 14:case 15:case 17:case 18:case 21:case 25:case 29:func_02015230(0,9);break;case 1:case 2:case 3:case 4:case 5:case 6:case 9:case 10:case 11:case 12:case 16:case 19:case 20:case 22:case 23:case 24:case 26:case 27:case 28:default:func_02015230(0,8);break;} break;
}
if(a==17){void (*cb)(s32,s32,s32)=M2C_FIELD(gMbWork,void (**)(s32,s32,s32),0x14e4);MI_CpuFill32(0,gMbWork,0x7d00);gMbWork=0;if(cb)cb(0,12,0);}
}
#pragma opt_scheduling on
#pragma opt_common_subs on
void MultiBoot_HandlePlayerPacket(void *arg0,u16 n) {
void *MultiBoot_DecodePacket(); void MI_CpuCopy8(); u16 func_02015204(); extern s32 gMbWork; extern s32 gGroupChunkPendingMask;
s32 state; u8 *p; u32 group; u8 count,i; u8 header[20]; u8 packet[32];
if(!n)return; if(n>15)return;
p=MultiBoot_DecodePacket((u8 *)arg0+10,header,n);
state=M2C_FIELD(gMbWork+((u32)n-1)*4,s32 *,0x14e8);
switch(header[0]){
case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 11: break;
case 7:
if(state==2){
if(!p)return;
MI_CpuCopy8(p,packet,29);
M2C_FIELD(gMbWork+(n-1)*4,u32 *,0x14a8)=*(u32 *)packet;
M2C_FIELD(gMbWork+(n-1)*2,u16 *,0x148a)=*(u16 *)(packet+26);
MI_CpuCopy8(packet+4,(void *)(gMbWork+0x1340+(n-1)*22),22);
((Packet14564 *)(gMbWork+0x1340+((u32)n-1)*22))->high=(u8)n;
Mb_SetPlayerState(n,10,(M2C_UNK)(packet+4));
}
if(state!=10)return;
group=p[28]; count=0;
if(group>=16 || !M2C_FIELD(gMbWork+group*0x5d4,u8 *,0x1d52) || M2C_FIELD(gMbWork+(n-1)*4,u32 *,0x14a8)!=M2C_FIELD(M2C_FIELD(gMbWork+group*0x5d4,u32 *,0x1d40),u32 *,20)){
M2C_FIELD(gMbWork+(n-1)*2,u16 *,0x1754)=4;
}else{
for(i=0;i<16;i++)if(M2C_FIELD(gMbWork+group*0x5d4,u16 *,0x1d4e)&(1<<i))count++;
if(count>=M2C_FIELD(M2C_FIELD(gMbWork+group*0x5d4,u32 *,0x1d40),u8 *,24)){
M2C_FIELD(gMbWork+(n-1)*2,u16 *,0x1754)=0;Mb_SetPlayerState(n,11,0);return;}
}
switch(M2C_FIELD(gMbWork+(n-1)*2,u16 *,0x1754)){
case 3:
if(M2C_FIELD(gMbWork,u16 *,0x1536)&(1<<n))return;
M2C_FIELD(gMbWork,u8 *,0x1535)++;
M2C_FIELD(gMbWork,u16 *,0x1536)|=1<<n;
M2C_FIELD(gMbWork+n-1,u8 *,0x1526)=group;
M2C_FIELD(gMbWork+group*0x5d4,u16 *,0x1d4e)|=1<<n;
M2C_FIELD(gMbWork+group*0x5d4,u16 *,0x1d50)|=1<<n;
M2C_FIELD(gMbWork+(n-1)*2,u16 *,0x1754)=0;Mb_SetPlayerState(n,5,0);return;
case 4:M2C_FIELD(gMbWork+(n-1)*2,u16 *,0x1754)=0;Mb_SetPlayerState(n,4,0);return;
}break;
case 8:
if(state==5){Mb_SetPlayerState(n,14,0);return;}
if(state!=14)return;
if(M2C_FIELD(gMbWork+(n-1)*2,u16 *,0x1754)!=2)return;
group=M2C_FIELD(gMbWork+n-1,u8 *,0x1526);
M2C_FIELD(gMbWork+group*0x5d4,u16 *,0x1d4c)|=1<<n;
M2C_FIELD(gMbWork+group*0x5d4,u16 *,0x1d48)=0;
M2C_FIELD(gMbWork+(n-1)*2,u16 *,0x1754)=0;Mb_SetPlayerState(n,6,0);break;
case 9:
if(state!=6)return;
group=M2C_FIELD(gMbWork+n-1,u8 *,0x1526);if(group==255)return;
M2C_FIELD(gMbWork+group*0x5d4,u16 *,0x1d4a)=func_02015204(M2C_FIELD(gMbWork+group*0x5d4,u16 *,0x1d4a),*(u16 *)(header+2));
gGroupChunkPendingMask|=1<<group;break;
case 10:
if(state==6){group=M2C_FIELD(gMbWork+n-1,u8 *,0x1526);if(group==255)return;M2C_FIELD(gMbWork+group*0x5d4,u16 *,0x1d4c)&=~(1<<n);Mb_SetPlayerState(n,7,0);return;}
if(state!=7)return;
if(M2C_FIELD(gMbWork+(n-1)*2,u16 *,0x1754)!=5)return;
M2C_FIELD(gMbWork+(n-1)*2,u16 *,0x1754)=0;Mb_SetPlayerState(n,8,0);break;
}
}
#pragma opt_strength_reduction reset
/* Group-start event: forgets each active group's pending chunk transfer, then
   hands every player's queued multiboot message to the packet handler. */
void ProcessGroupStartMessages(s32 batch) {
 extern s32 gMbWork; extern s32 gGroupChunkPendingMask;
 void *MultiBoot_FindPlayerMessage(s32,u16); void MultiBoot_HandlePlayerPacket(void *,u16);
 u16 i; void *p;
 for(i=0;i<16;i++) {
 p=(void *)(gMbWork+i*MB_GROUP_STRIDE);
 if(M2C_FIELD(p,u8 *,MB_GROUPS+MB_GROUP_ACTIVE)) M2C_FIELD(p,u16 *,MB_GROUPS+MB_GROUP_CHUNK_GOAL)=0;
 }
 gGroupChunkPendingMask=0;
 for(i=1;i<=15;i++) {
 p=MultiBoot_FindPlayerMessage(batch,i);
 if(p && M2C_FIELD(p,u16 *,0)!=0xffff && M2C_FIELD(p,u16 *,0)!=0) MultiBoot_HandlePlayerPacket(p,i);
 }
}

/* Send a bare multiboot control command (only its type byte set) to every player
 * in `playerMask`: serialize the command into the work area's outgoing command
 * buffer and send the resulting 6-byte packet. */
void Mb_SendPlayerCommand(u8 command, u16 playerMask) {
 void SerializeCommand(u8 *,s32); s32 SendMatchPacket(s32,s32,s32);
 extern s32 gMbWork;
 u8 packet[8];
 packet[0]=command;
 SerializeCommand(packet,gMbWork);
 SendMatchPacket(6,playerMask,gMbWork);
}

