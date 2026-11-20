/* 28 functions from 0x02011BB0 to 0x02012B70 (main), found by ds-decomp. */
#include "common.h"
#include "wfc_channel.h"
typedef struct {u8 kind,length; u16 pad; u8 *data;} ParsedItem;
typedef struct {u8 count; u8 pad[3]; ParsedItem items[16];} ParsedItems;
typedef struct { u32 flags; u16 a,b,c,d; u8 e,f,g,h; } PacketParams_02012a64;
/* Parameter block of a download-play (multiboot) session sent with WFC command 7. */
#define SESSION_PAYLOAD     0x00 /* void *: optional data copied to the child */
#define SESSION_PAYLOAD_LEN 0x04 /* u16: payload length in bytes */
#define SESSION_HEADER      0x14 /* u16: nonzero when the session carries an extra header */
#define SESSION_SIZE_A      0x34 /* u16: transfer A size, header included (max 512) */
#define SESSION_SIZE_B      0x36 /* u16: transfer B size, header included (max 512) */

/* Smallest payload a download-play (multiboot) transfer may use, in bytes: it has
 * to hold a 12-word header plus WFC_LINK_BLOCK_WORDS per player, times
 * WFC_LINK_PLAYERS players, plus 41 words of fixed overhead, rounded down to
 * 32 words and converted to bytes (hence always a multiple of 64).  Only players
 * whose WFC_LINK_RESET word is clear get the per-player term.  Returns 0 while
 * the channel is not in state 7 or 8, or while the link is being torn down. */
s32 MultiBoot_GetMinPayloadSize(void) {
    void *WFC_GetInfoBlock();
    void DC_InvalidateRange(void *, s32);
    void *info;
    void *link;
    s32 usePlayers;
    u16 blockWords;
    u16 players;
    info = WFC_GetInfoBlock();
    if (WFC_CheckChannelState(2, 7, 8) != 0) {
        return 0;
    }
    DC_InvalidateRange(M2C_FIELD(info, void **, WFC_INFO_LINK) + WFC_LINK_TEARDOWN, 4);
    link = M2C_FIELD(info, void **, WFC_INFO_LINK);
    if (M2C_FIELD(link, s32 *, WFC_LINK_TEARDOWN) == 1) {
        return 0;
    }
    DC_InvalidateRange((u8 *)link + WFC_LINK_RESET, 2);
    link = M2C_FIELD(info, void **, WFC_INFO_LINK);
    if (M2C_FIELD(link, u16 *, WFC_LINK_RESET) == 0) {
        usePlayers = 1;
    } else {
        usePlayers = 0;
    }
    DC_InvalidateRange((u8 *)link + WFC_LINK_BLOCK_WORDS, 2);
    link = M2C_FIELD(info, void **, WFC_INFO_LINK);
    blockWords = M2C_FIELD(link, u16 *, WFC_LINK_BLOCK_WORDS);
    if (usePlayers == 1) {
        DC_InvalidateRange((u8 *)link + WFC_LINK_PLAYERS, 2);
        link = M2C_FIELD(info, void **, WFC_INFO_LINK);
        players = M2C_FIELD(link, u16 *, WFC_LINK_PLAYERS);
        return (((blockWords + 0xC) * players + 0x29) & ~0x1F) << 1;
    } else {
        return ((blockWords + 0x51) & ~0x1F) << 1;
    }
}

/* Finds the multiboot command message that the ARM7's per-player batch `batch`
 * holds for player slot `player`: the batch's message count is at +4 and the
 * byte size of one nested message at +6, the messages start at +0xA and each
 * carries its player slot at +4.  Nothing is returned when the player's Wi-Fi
 * profile is not registered or the batch has no message for it. */
void *MultiBoot_FindPlayerMessage(void *batch, u32 player) {
void *WFC_GetInfoBlock(); s32 WFC_CheckReady(); void DC_InvalidateRange(void *,s32);
s32 messages[15]; void *block=WFC_GetInfoBlock(); s32 i;
if(WFC_CheckReady())return 0;
if(player<1||player>15)return 0;
DC_InvalidateRange((u8 *)M2C_FIELD(block,void **,4)+0x182,2);
if(!(M2C_FIELD(M2C_FIELD(block,void **,4),u16 *,0x182)&(1<<player)))return 0;
if(!M2C_FIELD(batch,volatile u16 *,4))return 0;
messages[0]=(s32)batch+10;i=0;
do{
if(player==M2C_FIELD(messages[i],u16 *,4))return (void *)messages[i];
i++;
messages[i]=messages[i-1]+M2C_FIELD(batch,u16 *,6);
}while(i<M2C_FIELD(batch,volatile u16 *,4));
return 0;
}

u16 WFC_GetPlayerMask(void) {
    s32 WFC_CheckReady();
    if (WFC_CheckReady() != 0) {
        return 0x8000U;
    }
    return *(u16 *)0x027FFCFA;
}

/* The status value of the WFC link: 0 unless the link is in state 9, 10 or 11;
 * in state 9 it also needs a connected player in WFC_LINK_CONNECTED_MASK, and
 * the value is WFC_LINK_STATUS_VALUE of the (re-read) link object. */
u16 WFC_GetLinkStatusValue(void) {
 void *WFC_GetInfoBlock();
 s32 WFC_CheckReady();
 void DC_InvalidateRange(void *, s32);
 void *info = WFC_GetInfoBlock();
 void *link;
 u16 state;
 if (WFC_CheckReady()) return 0;
 DC_InvalidateRange(M2C_FIELD(info, void **, WFC_INFO_LINK), 2);
 link = M2C_FIELD(info, void **, WFC_INFO_LINK);
 state = M2C_FIELD(link, u16 *, WFC_LINK_STATE);
 switch (state) {
 case 9:
  DC_InvalidateRange((u8 *)link + WFC_LINK_CONNECTED_MASK, 2);
  link = M2C_FIELD(info, void **, WFC_INFO_LINK);
  if (!M2C_FIELD(link, u16 *, WFC_LINK_CONNECTED_MASK)) return 0;
 case 10:
 case 11:
  DC_InvalidateRange((u8 *)link + WFC_LINK_STATUS_VALUE, 2);
  return M2C_FIELD(M2C_FIELD(info, void **, WFC_INFO_LINK), u16 *, WFC_LINK_STATUS_VALUE);
 default: return 0;
 }
}

/* The download-play game group id this console advertises: a value in
 * [MB_GROUP_ID_FIRST, MB_GROUP_ID_FIRST + MB_GROUP_ID_COUNT) picked from the sum
 * of the six MAC address bytes and the shared frame counter. */
u16 GetGameGroupId(void) {
    void GetMacAddress(u8 *);
    u8 mac[6];
    u16 sum;
    s32 i;
    u8 *p;
    u16 value;
    GetMacAddress(mac);
    i = 0;
    p = mac;
    sum = 0;
    do {
        sum += *p++;
        i++;
    } while (i < 6);
    value = sum + *(s32 *)SHARED_FRAME_COUNTER;
    value = value * 7;
    return (s32)value % MB_GROUP_ID_COUNT + MB_GROUP_ID_FIRST;
}

/* Derive the console's 16-bit local id for the outgoing WFC records: the sum of
 * the six MAC address bytes plus the handshake word at 0x027FFC3C, times 13,
 * reduced into 30..39. */
u16 GetConsoleLocalId(void){void GetMacAddress(u8 *);u8 mac[6];s32 i;u16 sum;u8 *p;u16 value;GetMacAddress(mac);i=0;p=mac;sum=0;do{sum+=*p++;i++;}while(i<6);value=sum+*(s32 *)0x027ffc3c;value=value*13;return (s32)value%10+30;}

/* Parse the item list embedded in the input buffer into *out (at most 16 items). */
void func_02011f2c(ParsedItems *out, void *in) {
    ParsedItems result;
    u8 *p;
    s32 i;
    u8 used, limit, size;

    if (M2C_FIELD(in, u16 *, 60)) {
        result.count = 0;
        *out = result;
        return;
    }
    result.count = M2C_FIELD(in, u16 *, 62);
    if (result.count == 0) {
        *out = result;
        return;
    }
    if (result.count > 16)
        result.count = 16;
    used = 0;
    p = (u8 *)in + 64;
    limit = M2C_FIELD(in, u16 *, 0) * 2 - 64;
    for (i = 0; i < result.count; i++) {
        result.items[i].kind = p[0];
        result.items[i].length = p[1];
        result.items[i].data = p + 2;
        size = result.items[i].length + 2;
        used += size;
        if (used > limit) {
            result.count = 0;
            *out = result;
            return;
        }
        p += size;
    }
    *out = result;
}

u16 func_02012084(void){
extern u32 data_020f5540;void func_0200ee70(void);s32 GetRtcTime(void *);
s32 a[3];
if(data_020f5540==0x10000){func_0200ee70();if(GetRtcTime(a)==0)data_020f5540=(u16)(a[2]+(a[1]<<8));}
data_020f5540=(u16)(data_020f5540+1);return (u16)data_020f5540;
}

s32 func_020120f8(M2C_UNK a){
s32 WFC_CheckChannelState(s32,s32); void *WFC_GetInfoBlock();s32 r;void *p;
r=WFC_CheckChannelState(1,0);if(r)return r;WFC_SetChannelParam(3,a);p=WFC_GetInfoBlock();r=WFC_SendCommand(3,3,M2C_FIELD(p,s32 *,0),M2C_FIELD(p,s32 *,4),M2C_FIELD(p,s32 *,16));if(!r)r=2;return r;
}

s32 func_02012158(M2C_UNK arg0) {
    s32 WFC_CheckChannelState(M2C_UNK, M2C_UNK);
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = WFC_CheckChannelState(1, 1);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    WFC_SetChannelParam(4, arg0);
    var_r0 = WFC_SendCommand(4, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02012198(M2C_UNK arg0) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = WFC_CheckChannelState(1, 1);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    WFC_SetChannelParam(5, arg0);
    var_r0 = WFC_SendCommand(5, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_020121d8(M2C_UNK arg0) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = WFC_CheckChannelState(1, 2);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    WFC_SetChannelParam(6, arg0);
    var_r0 = WFC_SendCommand(6, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02012218(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_02011034(M2C_UNK, M2C_UNK);
    void *WFC_GetInfoBlock();
    s32 temp_r0;
    s32 var_r0;
    void *temp_r0_2;

    temp_r0 = func_02011034(arg0, arg2);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    WFC_SetChannelParam(0, arg1);
    temp_r0_2 = WFC_GetInfoBlock();
    var_r0 = WFC_SendCommand(0, 3, M2C_FIELD(temp_r0_2, s32 *, 0), M2C_FIELD(temp_r0_2, s32 *, 4), M2C_FIELD(temp_r0_2, s32 *, 0x10));
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02012274(M2C_UNK arg0) {
    M2C_UNK WFC_SetChannelParam(M2C_UNK, M2C_UNK);
    s32 WFC_SendCommand();
    s32 func_0201146c();
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_0201146c();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    WFC_SetChannelParam(1, arg0);
    var_r0 = WFC_SendCommand(1, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 WFC_EndLink(M2C_UNK arg0) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = WFC_CheckChannelState(1, 2);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    WFC_SetChannelParam(2, arg0);
    var_r0 = WFC_SendCommand(2, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

/* Starts a download-play (multiboot) session on the ARM7: checks the parameters,
 * installs `handler` as the command-7 callback, writes the parameter block back to
 * memory and queues it.  Returns 0 on success (2 once queued), 6 for bad parameters,
 * or a Wi-Fi error code. */
s32 WFC_StartDownloadPlay(s32 handler, void *params) {
    s32 WFC_CheckChannelState(s32, s32);
    s32 WFC_ValidateStartParams(void *);
    void DC_CleanRange(void *, s32);
    s32 result = WFC_CheckChannelState(1, 2);

    if (result) return result;
    if (!params) return 6;
    if (M2C_FIELD(params, u16 *, SESSION_PAYLOAD_LEN) && !M2C_FIELD(params, void **, SESSION_PAYLOAD)) return 6;
    if (M2C_FIELD(params, u16 *, SESSION_SIZE_A) + (M2C_FIELD(params, u16 *, SESSION_HEADER) ? 42 : 0) > 512 ||
        M2C_FIELD(params, u16 *, SESSION_SIZE_B) + (M2C_FIELD(params, u16 *, SESSION_HEADER) ? 6 : 0) > 512) return 6;
    WFC_ValidateStartParams(params);
    WFC_SetChannelParam(7, handler);
    DC_CleanRange(params, 64);
    if (M2C_FIELD(params, u16 *, SESSION_PAYLOAD_LEN)) DC_CleanRange(M2C_FIELD(params, void **, SESSION_PAYLOAD), M2C_FIELD(params, u16 *, SESSION_PAYLOAD_LEN));
    result = WFC_SendCommand(7, 1, params);
    if (!result) result = 2;
    return result;
}

s32 WFC_ValidateStartParams(void *arg0) {
    u16 temp_r0;
    u16 temp_r1;

    if ((u32) M2C_FIELD(arg0, u16 *, 4) > 0x70U) {
        return 0;
    }
    temp_r1 = M2C_FIELD(arg0, u16 *, 0x18);
    if (((u32) temp_r1 < 0xAU) || ((u32) temp_r1 > 0x3E8U)) {
        return 0;
    }
    temp_r0 = M2C_FIELD(arg0, u16 *, 0x32);
    if (((u32) temp_r0 < 1U) || ((u32) temp_r0 > 0xEU)) {
        return 0;
    }
    return 1;
}

s32 func_02012418(M2C_UNK a,M2C_UNK b){void *WFC_GetInfoBlock();s32 r=WFC_CheckChannelState(1,2);void *p;if(r)return r;p=WFC_GetInfoBlock();M2C_FIELD(p,u16 *,0x150)=0;M2C_FIELD(p,s32 *,0x14c)=0;WFC_SetChannelParam(8,a);r=WFC_SendCommand(8,1,b);if(!r)r=2;return r;}

void func_02012474(M2C_UNK arg0) {
    M2C_UNK func_02012418(M2C_UNK, M2C_UNK);
    func_02012418(arg0, 1);
}

s32 func_02012484(M2C_UNK arg0) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = WFC_CheckChannelState(1, 7);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    WFC_SetChannelParam(9, arg0);
    var_r0 = WFC_SendCommand(9, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

/* Sends this player's multiboot match profile (command 10): validates the
 * profile block (match id, 1..14 players in the group and up to 14 info bytes)
 * and queues it in a 16-byte command-10 packet carrying the command handler,
 * match id, player count, info word and the info bytes.  Returns 0 on success
 * (2 once handed to the queue), 6 for a bad profile. */
s32 func_020124c4(s32 commandHandler,void *profile){
s32 WFC_CheckChannelState();s32 WFC_SendCommandPacket(void *,s32);
u32 packet[4];s32 result;u16 playerCount;
result=WFC_CheckChannelState(3,2,3,5);
if(result)return result;
if(!profile)return 6;
if(!M2C_FIELD(profile,u32 *,0))return 6;
playerCount=M2C_FIELD(profile,u16 *,4);
if(playerCount<1U||playerCount>14U)return 6;
WFC_SetChannelParam(10,commandHandler);
M2C_FIELD(packet,u16 *,0)=10;
M2C_FIELD(packet,u16 *,2)=M2C_FIELD(profile,u16 *,4);
M2C_FIELD(packet,u32 *,4)=M2C_FIELD(profile,u32 *,0);
M2C_FIELD(packet,u16 *,8)=M2C_FIELD(profile,u16 *,6);
M2C_FIELD(packet,u8 *,10)=M2C_FIELD(profile,u8 *,8);
M2C_FIELD(packet,u8 *,11)=M2C_FIELD(profile,u8 *,9);
M2C_FIELD(packet,u8 *,12)=M2C_FIELD(profile,u8 *,10);
M2C_FIELD(packet,u8 *,13)=M2C_FIELD(profile,u8 *,11);
M2C_FIELD(packet,u8 *,14)=M2C_FIELD(profile,u8 *,12);
M2C_FIELD(packet,u8 *,15)=M2C_FIELD(profile,u8 *,13);
result=WFC_SendCommandPacket(packet,16);
if(!result)result=2;
return result;
}

/* Wraps params into a packet and dispatches it to the host. */
s32 WFC_SendRequestPacket(s32 sendCode, void *params) {
s32 WFC_CheckChannelState();
s32 WFC_SendCommandPacket(void *, s32);
void MI_CpuCopy8(void *, void *, s32);
u16 packet[30];
s32 r;
u16 type;

r = WFC_CheckChannelState(3, 2, 3, 5);
if (r) return r;
if (!params) return 6;
if (!M2C_FIELD(params, u32 *, 0)) return 6;
if (M2C_FIELD(params, u16 *, 4) > 0x400U) return 6;
if (M2C_FIELD(params, u16 *, 18) > 32U) return 6;
type = M2C_FIELD(params, u16 *, 16);
if (type != 0 && type != 1 && type != 2 && type != 3) return 6;
if ((u16)(type + 0xfffe) <= 1U && M2C_FIELD(params, u16 *, 52) > 32U) return 6;
WFC_SetChannelParam(38, sendCode);
M2C_FIELD(packet, u16 *, 0) = 38;
M2C_FIELD(packet, u16 *, 2) = M2C_FIELD(params, u16 *, 6);
M2C_FIELD(packet, u32 *, 4) = M2C_FIELD(params, u32 *, 0);
M2C_FIELD(packet, u16 *, 8) = M2C_FIELD(params, u16 *, 4);
M2C_FIELD(packet, u16 *, 10) = M2C_FIELD(params, u16 *, 8);
MI_CpuCopy8((u8 *)params + 10, &packet[6], 6);
M2C_FIELD(packet, u16 *, 18) = M2C_FIELD(params, u16 *, 16);
M2C_FIELD(packet, u16 *, 54) = M2C_FIELD(params, u16 *, 52);
M2C_FIELD(packet, u16 *, 20) = M2C_FIELD(params, u16 *, 18);
MI_CpuCopy8((u8 *)params + 20, &packet[11], 32);
r = WFC_SendCommandPacket(packet, 60);
if (!r) r = 2;
return r;
}

s32 func_02012700(M2C_UNK arg0) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = WFC_CheckChannelState(1, 5);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    WFC_SetChannelParam(0xB, arg0);
    var_r0 = WFC_SendCommand(0xB, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

/* Sends this player's connection data to the ARM7 as WFC command 12: cleans
 * `connData` (a 16-bit word count followed by the data), clears the info block's
 * link fields, stores `commandHandler` as the command's completion callback, then
 * queues a 40-byte packet carrying the data pointer, a 24-byte `extraData` block
 * (zeroed when null) and the `option`/`flag` words. Returns 0 on success (2 once
 * queued), 6 for bad parameters, or a Wi-Fi error code. */
s32 WFC_SendConnectionData(s32 commandHandler,u16 *connData,void *extraData,s32 option,u16 flag){
void *WFC_GetInfoBlock(void);
void DC_CleanRange(void *,s32);void MI_CpuCopy8(void *,void *,s32);void MI_CpuFill8(void *,s32,s32);s32 WFC_SendCommandPacket(void *,s32);
u32 packet[10];s32 r;void *p;
r=WFC_CheckChannelState(1,2);if(r)return r;if(!connData)return 6;
DC_CleanRange(connData,*connData*2);p=WFC_GetInfoBlock();M2C_FIELD(p,u16 *,0x150)=0;M2C_FIELD(p,s32 *,0x14c)=0;WFC_SetChannelParam(12,commandHandler);
M2C_FIELD(packet,u16 *,0)=12;M2C_FIELD(packet,u16 **,4)=connData;
if(extraData)MI_CpuCopy8(extraData,&packet[2],24);else MI_CpuFill8(&packet[2],0,24);
M2C_FIELD(packet,s32 *,32)=option;M2C_FIELD(packet,u16 *,38)=flag;
r=WFC_SendCommandPacket(packet,40);if(!r)r=2;return r;
}

/* Register connection profile number `b` of type `a` in the Wi-Fi info block: check
 * the block is a connected (kind 7 or 9) one, then record the profile's bit.  Returns
 * 0 on success, or a Wi-Fi error code (2 = add failed, 6 = bad profile number,
 * 7 = profile not in the block's list). */
s32 func_0201280c(s32 a,u32 b){s32 WFC_CheckChannelState();void *WFC_GetInfoBlock();void DC_InvalidateRange(void *,s32);void *p=WFC_GetInfoBlock();void *q;s32 r=WFC_CheckChannelState(5,7,9,8,10,11);if(r)return r;q=M2C_FIELD(p,void **,4);if(M2C_FIELD(q,u16 *,0)==7 || M2C_FIELD(q,u16 *,0)==9){if(b<1 || b>15)return 6;DC_InvalidateRange((u8 *)q+0x182,2);if(!(M2C_FIELD(M2C_FIELD(p,void **,4),u16 *,0x182)&(1<<b)))return 7;}else if(b)return 6;WFC_SetChannelParam(13,a);r=WFC_SendCommand(13,1,1<<b);if(!r)r=2;return r;}

s32 func_020128f4(s32 index, s32 peer, s32 payloadSize, s32 param, u16 tag, void *data) {
    /* Register a pending uplink packet: validates camera/module state, builds packet header in a 64-byte buffer, returns status. */
    s32 WFC_CheckChannelState();
    void *WFC_GetInfoBlock();
    void DC_InvalidateRange(void *, s32);
    void CpuFill(s32, void *, s32);
    void MIi_CpuCopy32(void *, void *, s32);
    s32 WFC_SendCommandPacket(void *, s32);
    s32 func_02011b44();
    u32 packet[16];
    s32 rc;
    void *ctx;
    ctx = M2C_FIELD(WFC_GetInfoBlock(), void **, 4);
    rc = WFC_CheckChannelState(2, 7, 8);
    if (rc) return rc;
    DC_InvalidateRange(ctx + 0x188, 2);
    DC_InvalidateRange(ctx + 0xC6, 2);
    if (M2C_FIELD(ctx, u16 *, 0x188) && M2C_FIELD(ctx, u16 *, 0xC6) != 1) return 3;
    DC_InvalidateRange(ctx + 12, 4);
    if (M2C_FIELD(ctx, s32 *, 12) == 1) return 3;
    if (payloadSize & 63) return 6;
    if (tag & 31) return 6;
    DC_InvalidateRange(ctx + 0x9C, 2);
    if (!M2C_FIELD(ctx, u16 *, 0x9C)) {
        if (payloadSize < MultiBoot_GetMinPayloadSize()) return 6;
        if ((s32)tag < func_02011b44()) return 6;
    }
    WFC_SetChannelParam(14, index);
    CpuFill(0, packet, 64);
    M2C_FIELD(packet, u16 *, 0) = 14;
    packet[1] = peer;
    packet[2] = (u32)payloadSize >> 1;
    packet[3] = param;
    packet[4] = tag;
    CpuFill(0, &packet[5], 28);
    MIi_CpuCopy32(data, &packet[12], 16);
    rc = WFC_SendCommandPacket(packet, 64);
    if (!rc) rc = 2;
    return rc;
}

void func_02012a64(M2C_UNK a,M2C_UNK b,M2C_UNK c,M2C_UNK d,u16 e,u16 f,u16 g,s32 h,s32 i,s32 j,s32 k){void CpuFill();PacketParams_02012a64 x;CpuFill(0,&x,16); x.g=k;x.e=h;x.f=i;x.flags=0x1e03;x.d=g;x.a=f;x.b=f;if(j && f){x.flags|=4;x.c=f;} func_020128f4(a,b,c,d,e,&x);}

void func_02012b08(M2C_UNK a,M2C_UNK b,M2C_UNK c,M2C_UNK d,u16 e,u16 f){
void CpuFill();s32 func_020128f4(s32,s32,s32,s32,u16,void *);u32 x[4];
CpuFill(0,x,16);x[0]=3;M2C_FIELD(x,u16 *,4)=f;M2C_FIELD(x,u16 *,6)=f;func_020128f4(a,b,c,d,e,x);
}
typedef struct { u32 flags; u16 a,b,c,d; u8 e,f,g,h; } Packet_02012a64;
