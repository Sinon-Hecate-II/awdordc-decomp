/* 48 functions from 0x02031290 to 0x02032228 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"

M2C_UNK Wfc_GetWorkBlock(M2C_UNK);

/* Dispatch the next state depending on the current game mode. */
s32 Wfc_StepMatch(void) {
    s32 Wfc_GetLinkState();
    s32 Wfc_GetSessionState();
    s32 Wfc_StepFriendConnect(void *);
    s32 Wfc_StepCloseNetwork();
    M2C_UNK Wfc_AbortNetworkSession();
    s32 state;
    u32 tmp;
    void *ctx;

    state = Wfc_GetSessionState();
    ctx = (void *)Wfc_GetWorkBlock(0x10);
    if (Wfc_GetLinkState() == 9) {
        tmp = state - 0xA;
        switch (tmp) {                          /* switch 1 */
        default:                                /* switch 1 */
            break;
        case 0:                                 /* switch 1 */
            state = Wfc_StepStartHost(ctx);
            break;
        case 2:                                 /* switch 1 */
            state = Wfc_StepFriendConnect(ctx);
            break;
        case 3:                                 /* switch 1 */
            state = Wfc_StepHttpStartup();
            break;
        case 4:                                 /* switch 1 */
            state = Wfc_StepHttp(ctx);
            break;
        case 5:                                 /* switch 1 */
            state = func_02031518(ctx);
            break;
        case 1:                                 /* switch 1 */
            state = Wfc_StepCloseNetwork();
            break;
        }
    } else {
        switch (state) {                       /* switch 2; irregular */
        case 15:                               /* switch 2 */
            state = func_02031518(ctx);
            break;
        case 11:                               /* switch 2 */
            state = Wfc_StepCloseNetwork();
            break;
        case 14:                               /* switch 2 */
            Wfc_AbortNetworkSession();
            Wfc_ReleaseNetwork();
            /* fallthrough */
        default:                               /* switch 2 */
            state = 0xB;
            M2C_FIELD((ctx + (M2C_FIELD(ctx, u8 *, 0xD13) * 4)), s8 *, 0x444) = 2;
            break;
        }
    }
    return state;
}

/* WFC session step 0xA: build the host configuration (WFC work block
 * WFC_WORK_AUX) from the control block and the selected friend's save-slot player
 * codes, then start the network host.  Returns 0xC (the friend-connect step) when
 * the host started, or 0x11 (error, result code 2) when it would not. */
s32 Wfc_StepStartHost(M2C_UNK state) {
    s32 func_02021a90(s32);
    void Wfc_BuildHostConfig(M2C_UNK, M2C_UNK, M2C_UNK);
    extern s32 gNetTaskState;
    s32 config;
    s32 control;

    control = Wfc_GetWorkBlock(WFC_WORK_CONTROL);
    config = Wfc_GetWorkBlock(WFC_WORK_AUX);
    Wfc_BuildHostConfig(control, state, config);
    gNetTaskState = 4;
    if (func_02021a90(config) == 0) {
        return 0xC;
    }
    Wfc_SetResultCode(2);
    return 0x11;
}

/* Friend-connection step 12: once the console has a local IP address, prepare the
 * selected friend's player codes and return the next state -- 0xF to connect a
 * built-in access-point entry directly, 0xD for the matchmaking step.  Without an
 * address it waits WFC_ADDRESS_WAIT_SECONDS, then fails with 0xB and marks the
 * selected friend record's result. */
s32 Wfc_StepFriendConnect(void *state) {
    s32 GetLocalIpAddressNetworkOrder();
    void func_020316c4(void *);
    u64 GetSystemTick(void);
    u64 U64Divide(u64, u64);
    u32 selection;

    if (GetLocalIpAddressNetworkOrder() != 0) {
        func_020316c4(state);
        selection = (u32)(M2C_FIELD(state, u8 *, WFC_STATE_FLAGS) << 0x1A) >> 0x1E;
        return (selection == 1) ? 0xF : 0xD;
    }
    if (U64Divide((GetSystemTick() - M2C_FIELD(state, u64 *, WFC_STATE_TIMER)) << 6, TICKS_TO_SECONDS_DIVISOR) < (u64)WFC_ADDRESS_WAIT_SECONDS) {
        return 0xC;
    }
    M2C_FIELD(((u8 *)state + (M2C_FIELD(state, u8 *, WFC_STATE_RECORD_INDEX) * 4)), u8 *, WFC_STATE_RECORD_RESULT) = 1;
    return 0xB;
}

/* Session step 0xD: start the DWC HTTP matchmaking session on the WFC callback
 * block.  On success move on to the HTTP step (WFC_SESSION_STATE_HTTP); on
 * failure record result code 3 and go to the state that waits for the network
 * to come down (0x11). */
s32 Wfc_StepHttpStartup(void) {
    M2C_UNK Wfc_SetResultCode(M2C_UNK);
    s32 Dwc_HttpStartup(void *);

    if (Dwc_HttpStartup((void *)Wfc_GetWorkBlock(WFC_WORK_CALLBACKS)) == 0) {
        return WFC_SESSION_STATE_HTTP;
    }
    Wfc_SetResultCode(3);
    return 0x11;
}

/* HTTP matchmaking step: poll the network-check worker. While it is still running
 * stay in state 0xE; once it finishes, keep its result code when it was taken for the
 * selected friend's save slot, release the network and return 0xF on success, or mark
 * the selected record's result and fall back to 0xB. */
s32 Wfc_StepHttp(void *state) {
    s32 Wfc_FriendIdToSlot(u8);
    M2C_UNK Wfc_ReleaseNetwork();
    s32 Wfc_GetNetCheckState();
    s32 Wfc_GetNetResultCode();
    s32 checkState;
    void *control;

    control = (void *)Wfc_GetWorkBlock(WFC_WORK_CONTROL);
    checkState = Wfc_GetNetCheckState();
    if (checkState != 0) {
        if (M2C_FIELD(control, u8 *, WFC_CONTROL_SLOT) == Wfc_FriendIdToSlot(M2C_FIELD(state, u8 *, WFC_STATE_RESULT_ID))) {
            M2C_FIELD(control, s32 *, WFC_CONTROL_NET_RESULT) = Wfc_GetNetResultCode();
        }
        Wfc_ReleaseNetwork();
        if (checkState == 0xB) {
            return 0xF;
        }
        M2C_FIELD((state + (M2C_FIELD(state, u8 *, WFC_STATE_RECORD_INDEX) * 4)), s8 *, WFC_STATE_RECORD_RESULT) = 1;
        return 0xB;
    }
    return 0xE;
}

s32 func_02031518(void *arg0) {
    M2C_UNK Wfc_SetFriendSlot(u8);
    Wfc_SetFriendSlot(M2C_FIELD(arg0, u8 *, 0xD0D));
    return 0x10;
}

/* Session step 0xB (connection error): wait for the closing sockets to go, then
 * shut the network stack down.  Returns the link-wait state once it is down, but
 * stays in the error state while the teardown runs or when the shutdown fails. */
s32 Wfc_StepCloseNetwork(void) {
    s32 NetworkPollClosing(void);
    s32 ghiShutdown(void);
    u32 v;
    if (NetworkPollClosing() != 0) return WFC_SESSION_STATE_ERROR;
    v = ghiShutdown();
    return v == 0 || v == (u32)WFC_NET_ALREADY_DOWN ? WFC_SESSION_STATE_LINKING : WFC_SESSION_STATE_ERROR;
}

/* Build the WFC host configuration block (WFC work block 4) for the save slot the
 * selected friend code belongs to: start from the default template, give the record
 * the control block's allocator pair, then store the slot's four player codes and
 * the mask of its code's set-bit count. A slot with no player code is marked empty. */
void Wfc_BuildHostConfig(M2C_UNK control, M2C_UNK state, M2C_UNK config) {
    extern u8 gWfcHostConfigDefaults[];
    void MI_CpuCopy8(void *, void *, u32);
    s32 Wfc_FriendIdToSlot(u8);
    s32 Wfc_EncodePlayerCode(void *);
    s32 Wfc_EncodeCodeMask(s32);
    u8 friendId;

    MI_CpuCopy8(gWfcHostConfigDefaults, (void *)config, WFC_AUX_SIZE);
    M2C_FIELD(config, s32 *, 4) = M2C_FIELD(control, s32 *, 0);
    M2C_FIELD(config, s32 *, 8) = M2C_FIELD(control, s32 *, 4);
    friendId = M2C_FIELD(state, u8 *, WFC_STATE_RESULT_ID);
    if (friendId >= WFC_FRIEND_CODE_IDS) {
        return;
    }
    state = (M2C_UNK) ((u8 *) state + (Wfc_FriendIdToSlot(friendId) << 8));
    if (M2C_FIELD(state, u8 *, SAVE_SLOT_PLAYER_CODES) != 0) {
        M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_NEW) = 0;
        M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_CODE0) = Wfc_EncodePlayerCode((u8 *) state + SAVE_SLOT_PLAYER_CODES);
        M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_MASK) = Wfc_EncodeCodeMask(M2C_FIELD(state, u8 *, SAVE_SLOT_CODE_BITS));
        M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_CODE1) = Wfc_EncodePlayerCode((u8 *) state + SAVE_SLOT_PLAYER_CODES + 4);
        M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_CODE2) = Wfc_EncodePlayerCode((u8 *) state + SAVE_SLOT_PLAYER_CODES + 8);
        M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_CODE3) = Wfc_EncodePlayerCode((u8 *) state + SAVE_SLOT_PLAYER_CODES + 0xC);
        return;
    }
    M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_NEW) = 1;
    M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_CODE0) = 0;
    M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_MASK) = 0;
    M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_CODE1) = 0;
    M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_CODE2) = 0;
    M2C_FIELD(config, s32 *, WFC_HOST_CONFIG_CODE3) = 0;
}

/* Wfc_BuildHostConfig (void) is written by compile_and_diff below */

/* Read the 4-byte big-endian player code at `code` and return it byte-swapped
 * into the little-endian word the WFC host config stores. */
s32 Wfc_EncodePlayerCode(void *code) {
    u32 word;

    word = 0;
    word |= M2C_FIELD(code, u8 *, 0) << 0x18;
    word |= M2C_FIELD(code, u8 *, 1) << 0x10;
    word |= M2C_FIELD(code, u8 *, 2) << 0x8;
    word |= M2C_FIELD(code, u8 *, 3);
    return ((word << 0x18) & 0xFF000000) | (((word << 8) & 0xFF0000) | ((u8) (word >> 0x18) | ((word >> 8) & 0xFF00)));
}

/* Build the WFC host config's player-code mask for a code with `codeBits` set
 * bits: the top codeBits bits of a big-endian word, byte-swapped like the codes
 * Wfc_EncodePlayerCode writes (0 set bits give 0, all 32 give -1). */
s32 Wfc_EncodeCodeMask(s32 codeBits) {
    u32 mask;
    s32 count;
    s32 shift;

    shift = 0x20 - codeBits;
    mask = -1U;
    count = 0;
    if (shift > 0) {
        do {
            count += 1;
            mask *= 2;
        } while (count < shift);
    }
    return ((mask << 0x18) & 0xFF000000) | (((mask << 8) & 0xFF0000) | ((u8) (mask >> 0x18) | ((mask >> 8) & 0xFF00)));
}

#pragma opt_strength_reduction off
void func_020316c4(void *arg0) {
    void SetDnsServerAddressesFromHostOrder(M2C_UNK *, M2C_UNK *);
    s32 Wfc_FriendIdToSlot(u8);
    s32 Wfc_EncodePlayerCode(void *);
    s32 sp4;
    s32 sp0;
    u8 *p;
    u8 c0;
    u32 sum;

    p = (u8 *) arg0;
    if (M2C_FIELD(p, u8 *, 0xD0D) >= 6) {
        return;
    }
    p += Wfc_FriendIdToSlot(M2C_FIELD(p, u8 *, 0xD0D)) << 8;
    c0 = M2C_FIELD(p, u8 *, 0xC0);
    sum = M2C_FIELD(p, u8 *, 0xC8) + M2C_FIELD(p, u8 *, 0xC9) + M2C_FIELD(p, u8 *, 0xCA) + M2C_FIELD(p, u8 *, 0xCB);
    if (c0 != 0) {
        return;
    }
    if (sum == 0) {
        return;
    }
    sp4 = Wfc_EncodePlayerCode(p + 0xC8);
    sp0 = Wfc_EncodePlayerCode(p + 0xCC);
    SetDnsServerAddressesFromHostOrder(&sp4, &sp0);
}
#pragma opt_strength_reduction reset
/* Decode a WFC connection code and report whether it is the built-in shared
 * access point code: the decoded bytes begin with the "NDWCSHAP" tag. */
s32 Wfc_IsSharedApCode(M2C_UNK connCode) {
    M2C_UNK Wfc_DecodeSharedApCode(M2C_UNK, M2C_UNK *);
    s32 ByteCompareN(M2C_UNK, M2C_UNK *, M2C_UNK);
    extern M2C_UNK gWfcSharedApCodeTag; /* "NDWCSHAP" */
    M2C_UNK decoded[6];

    Wfc_DecodeSharedApCode(connCode, &decoded[0]);
    if (ByteCompareN((M2C_UNK) &decoded[0], &gWfcSharedApCodeTag, 8) == 0) {
        return 1;
    }
    return 0;
}

/* Decode the 32-character connection code of a friend record and store the
 * 13-byte MD5-based friend-code hash that the connection settings send for it
 * at `hash`. */
void Wfc_HashFriendConnectionCode(M2C_UNK code, void *hash) {
    M2C_UNK Wfc_DecodeSharedApCode(M2C_UNK, M2C_UNK *);
    void Wfc_ComputeFriendCodeHash(M2C_UNK *, M2C_UNK);
    u8 decoded[0x18];

    Wfc_DecodeSharedApCode(code, (M2C_UNK *)decoded);
    Wfc_ComputeFriendCodeHash((M2C_UNK *)decoded, (M2C_UNK)hash);
}

/* If `connCode` is a shared access point connection code, copies the 10-byte
 * access point code that follows its "NDWCSHAP" tag to `apCode`. */
void Wfc_GetSharedApCode(M2C_UNK connCode, M2C_UNK apCode) {
    M2C_UNK Wfc_DecodeSharedApCode(M2C_UNK, M2C_UNK *);
    s32 ByteCompareN(M2C_UNK, M2C_UNK *, M2C_UNK);
    void MI_CpuCopy8(void *, void *, u32);
    extern M2C_UNK gWfcSharedApCodeTag;
    M2C_UNK buf[6];

    Wfc_DecodeSharedApCode(connCode, buf);
    if (ByteCompareN((M2C_UNK)buf, &gWfcSharedApCodeTag, 8) != 0) {
        return;
    }
    MI_CpuCopy8(&buf[2], (void *)apCode, 0xA);
}

/* Whether `code` is the built-in access-point tag "NWCUSBAP" (the code of the
 * Nintendo Wi-Fi USB Connector used with a Download Play friend). */
s32 Wfc_IsUsbApCode(M2C_UNK code) {
    s32 ByteCompareN(M2C_UNK, M2C_UNK *, M2C_UNK);
    extern M2C_UNK gWfcUsbApCodeTag; /* "NWCUSBAP" */

    if (ByteCompareN(code, &gWfcUsbApCodeTag, 8) == 0) {
        return 1;
    }
    return 0;
}

void func_0203181c(s32 arg0, u8 *dst) {
    void func_0203197c(u8 *, u8 *);
    func_0203197c((u8 *)arg0 + 0xC, dst);
}

#pragma push
#pragma opt_strength_reduction off
M2C_UNK Wfc_DecodeSharedApCode(M2C_UNK arg0, M2C_UNK *arg1) {
    extern u8 data_020ea8ef[];
    extern signed char *data_020fb23c[];
    M2C_UNK func_02031b98(M2C_UNK, u8 *, s32, s32);
    u8 buf[0x18];
    u8 *p = (u8 *)arg1;
    u8 *src;
    u8 *dst;
    u32 n;
    s32 i;
    u8 cursor;
    u8 pos;
    s32 saved;
    s32 save;

    src = (u8 *)data_020ea8ef;
    dst = buf;
    n = 12;
    do {
        u8 a = src[0];
        u8 b = src[1];
        src += 2;
        dst[0] = a;
        dst[1] = b;
        dst += 2;
    } while (--n != 0);

    func_02031b98(arg0, p, 0x20, 0x18);

    for (i = 0; i < 0x18; i++) {
        p[i] = (u8)(p[i] ^ data_020fb23c[2][i]);
    }

    for (i = 0; i < 0x18; i++) {
        cursor = (u8)i;
        pos = cursor;
        saved = p[i];
        if (buf[cursor] != 0xFF) do {
            u8 *entry = &buf[pos];
            pos = buf[pos];
            save = p[pos];
            p[buf[cursor]] = (u8)saved;
            cursor = pos;
            *entry = 0xFF;
            saved = save;
        } while (buf[pos] != 0xFF);
    }

    for (i = 0; i < 0x18; i++) {
        p[i] = (u8)(p[i] ^ data_020fb23c[0][i]);
    }
}
#pragma pop
/* Build the 13-byte WFC friend-code check value from a decoded 24-byte
   friend-code block: MD5 it and keep digest bytes 3..15. */
void Wfc_ComputeFriendCodeHash(M2C_UNK *code, M2C_UNK out) {
    void MD5Init(M2C_UNK *);
    void MD5Update(M2C_UNK *, M2C_UNK, u32);
    void MD5Final(M2C_UNK *, M2C_UNK *);
    void MI_CpuCopy8(void *, void *, u32);
    u8 digest[20];
    u8 ctx[88];
    MD5Init((M2C_UNK *)ctx);
    MD5Update((M2C_UNK *)ctx, (M2C_UNK)code, 0x18);
    MD5Final((M2C_UNK *)digest, (M2C_UNK *)ctx);
    MI_CpuCopy8(digest + 3, (void *)out, 0xD);
}

void func_0203197c(u8 *src, u8 *dst) {
    u8 tmp[0x10];
    extern signed char *data_020fb23c[];
    extern u8 data_020ea908[];
    extern u8 data_020ea918[];
    void MI_CpuCopy8(void *, void *, u32);

    s32 i;
    for (i = 0; i < 0xD; i++) {
        dst[i] = (u8)(src[i] ^ src[(i % 7) + 0xD]);
    }
    for (i = 0; i < 0x7; i++) {
        dst[i + 0x3] = (u8)(dst[i + 0x3] ^ src[i + 0xD]);
    }
    for (i = 0; i < 0xD; i++) {
        dst[i] = (u8)(dst[i] ^ data_020fb23c[1][i]);
    }
    MI_CpuCopy8(dst, tmp, 0xD);
    for (i = 0; i < 0xD; i++) {
        dst[data_020ea908[i]] = tmp[i];
    }
    for (i = 0; i < 0xD; i++) {
        dst[i] = (u8)(dst[i] ^ data_020fb23c[3][i]);
    }
    for (i = 0; i < 0xD; i++) {
        u8 b = dst[i];
        u8 hi = (u8)((b >> 4) & 0x0F);
        u8 lo = (u8)(b & 0x0F);
        dst[i] = (u8)((data_020ea918[hi] << 4) | data_020ea918[lo]);
    }
    for (i = 0; i < 0x3; i++) {
        dst[i] = (u8)(dst[i] ^ dst[i + 0x6]);
        dst[i + 0x3] = (u8)(dst[i + 0x3] ^ dst[i + 0x9]);
        dst[i + 0x6] = (u8)(dst[i + 0x6] ^ dst[i + 0x3]);
        dst[i + 0x9] = (u8)(dst[i + 0x9] ^ dst[i]);
        dst[0xC] = (u8)(dst[0xC] ^ dst[i]);
    }
}

/* The 6-bit value of a base64 character (the standard alphabet A-Z, a-z, 0-9,
 * '+' and '/', with '=' accepted as padding), or -1 when it is not one. */
s32 Base64DecodeChar(u32 ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return (s32)(ch - 'A');
    }
    if (ch >= 'a' && ch <= 'z') {
        s32 digit = (s32)(ch - 'a');
        return digit + 26;
    }
    if (ch >= '0' && ch <= '9') {
        s32 digit = (s32)(ch - '0');
        return digit + 52;
    }
    if (ch == '+') {
        return 62;
    }
    if (ch == '/') {
        return 63;
    }
    if (ch == '=') {
        return 0;
    }
    return -1;
}

#pragma opt_strength_reduction off
s32 func_02031b98(s32 arg,u8 *dst,s32 n,s32 capacity){
u8 *src=(u8 *)arg;s32 full;u32 size=((u32)(n*3))>>2;s32 rem; s32 val; s32 pos; s32 j;s32 block;u32 word;u32 tail;u8 *in;u8 *out;
if((u32)capacity>=size){rem=n&3;full=n-rem;}else return -1;
pos=0;
if(full>0){block=0;do{
val=0;j=0;in=src+pos;
do{val|=func_02031b28(*in++)<<((3-j)*6);j++;}while(j<4);
j=0;word=val;out=dst+block*3;
do{*out++=((u8 *)&word)[2-j];j++;}while(j<3);
pos+=4;block++;
}while(pos<full);}
if(rem!=0){
val=0;j=0;tail=0;
if(rem>0){s32 accum=0;in=src+full;do{val|=func_02031b28(*in++)<<((3-j)*6);j++;accum|=val;}while(j<rem);tail=accum;}
j=0;if(rem>0){out=dst+(full*3)/4;do{*out++=((u8 *)&tail)[2-j];j++;}while(j<rem);}
}
return size;
}
#pragma opt_strength_reduction on
/* Check the save block and make sure the console has a WFC profile: verify the
 * save data, and when the profile is empty build one from the save.  Returns 3
 * when the save is bad and no profile could be made, 2 when the save is bad but a
 * profile was made, 1 when the save is good and a profile was made, 0 when both
 * were already fine. */
s32 CheckSaveAndWfcProfile(M2C_UNK arg0)
{
  M2C_UNK func_02000b9c(s32);
  s32 VerifySaveBlock(M2C_UNK);
  M2C_UNK CreateWfcProfile(M2C_UNK);
  s32 IsWfcProfileEmpty();
  u32 saveStatus;
  s32 profileCreated;
  profileCreated = 0;
  func_02000b9c(0x02000C34);
  saveStatus = (u32) VerifySaveBlock(arg0);
  if (IsWfcProfileEmpty() != 0)
  {
    if (1)
    {
      CreateWfcProfile(arg0);
    }
    profileCreated = 1;
  }
  if ((s32) saveStatus < 0)
  {
    if (profileCreated != 0)
    {
      return 2;
    }
    else
    {
      return 3;
    }
  }
  if (profileCreated != 0)
  {
    return 1;
  }
  return 0;
}

/* Write `value` into the `mask`-wide field at bit `shift` of the u32 type word
 * at *word (a player record's PLAYER_RECORD_TYPE).  Returns 0 without writing
 * anything when `value` has bits outside the field, 1 once it is written. */
s32 SetPlayerRecordTypeField(M2C_UNK word, M2C_UNK value, M2C_UNK shift, M2C_UNK mask) {
    if (((u32) value & ~(u32) mask) != 0U) {
        return 0;
    }
    *(u32 *) word = (*(u32 *) word & ~((u32) mask << (u32) shift)) | ((u32) value << (u32) shift);
    return 1;
}

/* Read the 43-bit player code of a NAS player record: its high 11 bits are the
 * low field of the record's type word, its low 32 bits the code word at +0x04. */
u64 GetNasPlayerCode(void *record) {
    u32 codeHigh = M2C_FIELD(record, u32 *, PLAYER_RECORD_TYPE) & PLAYER_CODE_HIGH_MASK;
    u32 codeLow = M2C_FIELD(record, u32 *, PLAYER_RECORD_CODE);
    return ((u64) codeHigh << 32) | codeLow;
}

s32 GetNasRecordCheckWord(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 8);
}

u64 GetPlayerCodeValue(void *arg0) {
    u32 hi;
    u32 lo;

    hi = M2C_FIELD(arg0, u32 *, 8);
    lo = M2C_FIELD(arg0, u32 *, 4);
    return ((u64) hi << 32) | lo;
}

s32 GetProfileRecordId(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4);
}

/* Set a NAS player record's 43-bit player code: its high 11 bits go into the type
 * word's low field (mask 0x7FF) and its low 32 bits into the code word at +0x04. */
void SetNasPlayerCode(void *record, s32 codeLow, M2C_UNK codeHigh) {
    SetPlayerRecordTypeField((M2C_UNK)record, codeHigh, 0, 0x7FF);
    M2C_FIELD(record, s32 *, 4) = codeLow;
}

void func_02031dfc(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
}

void SetPlayerCodeValue(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg2;
}

void SetProfileRecordId(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
}

s32 GetPlayerRecordTypeWord(u32 *arg0) {
    return 0x1FFFFF & ((u32) *arg0 >> 0xB);
}

s32 GetPlayerRecordKind(void) {
    s32 GetPlayerRecordTypeWord();
    return GetPlayerRecordTypeWord() & 3;
}

/* True when the player record at `record` is a profile record (its kind is
 * PLAYER_RECORD_KIND_PROFILE) whose player has joined the match: the joined
 * mark of its type word is set. */
s32 IsPlayerRecordJoined(void *record) {
    s32 GetPlayerRecordTypeWord(u32 *);

    if (GetPlayerRecordKind() == PLAYER_RECORD_KIND_PROFILE) {
        return (GetPlayerRecordTypeWord((u32 *)record) & PLAYER_RECORD_JOINED) == PLAYER_RECORD_JOINED;
    }
    return 0;
}

void GetPlayerRecordType(void) {
    M2C_UNK GetPlayerRecordKind();
    GetPlayerRecordKind();
}

#pragma optimization_level 2
void SetPlayerRecordTypeWord(M2C_UNK a,M2C_UNK b) { M2C_UNK SetPlayerRecordTypeField(M2C_UNK,M2C_UNK,M2C_UNK,s32); SetPlayerRecordTypeField(a,b,11,0x1fffff); }
void SetPlayerRecordKind(M2C_UNK arg0, M2C_UNK arg1) {
    s32 GetPlayerRecordTypeWord(u32 *);
    void SetPlayerRecordTypeWord(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = GetPlayerRecordTypeWord((u32 *) arg0);
    temp_r0 = temp_r0 & ~3;
    SetPlayerRecordTypeWord(arg0, temp_r0 | arg1);
}

/* Mark the player record at `record` as joined when it is a profile record
 * (PLAYER_RECORD_KIND_PROFILE): set its type word's PLAYER_RECORD_JOINED bit.
 * A record of any other kind is left alone. */
void MarkPlayerRecordJoined(M2C_UNK record) {
    s32 GetPlayerRecordTypeWord(u32 *);
    void SetPlayerRecordTypeWord(M2C_UNK, M2C_UNK);
    s32 typeWord;

    /* GetPlayerRecordKind (above) takes no declared argument, so `record` is
     * still in r0 from the call: it reads this record's kind. */
    if (GetPlayerRecordKind() != PLAYER_RECORD_KIND_PROFILE) {
        return;
    }
    typeWord = GetPlayerRecordTypeWord((u32 *) record) | PLAYER_RECORD_JOINED;
    SetPlayerRecordTypeWord(record, typeWord);
}

/* Clear the joined mark of a profile-type player record: the inverse of
 * MarkPlayerRecordJoined.  Other record kinds are left alone. */
void ClearPlayerRecordJoined(M2C_UNK record) {
    if (GetPlayerRecordKind() != PLAYER_RECORD_KIND_PROFILE) {
        return;
    }
    SetPlayerRecordTypeWord(record, GetPlayerRecordTypeWord((u32 *)record) & ~PLAYER_RECORD_JOINED);
}

/* Build a 64-bit player code from a GameSpy profile id and the game id: the low
 * word is the profile id, the high word the 7-bit CRC-8 check over { profile id,
 * game id }.  The inverse of IsPlayerCodeValid. */
u64 BuildPlayerCode(s32 profileId, s32 gameId) {
    void BuildCrc8Table(u8 *, s32);
    s32 Crc8Block(u8 *, s32 *, s32);
    u8 buf[0x100];
    s32 in[2];

    in[0] = profileId;
    in[1] = gameId;
    BuildCrc8Table(buf, 7);
    return (u32) profileId | ((u64) (Crc8Block(buf, in, 8) & 0x7f) << 32);
}

/* Whether `code` is a valid player code for the game id held at +0x24 of the
 * profile record `profile`; the check itself is IsPlayerCodeValid. */
s32 IsPlayerCodeValidForGameId(void *profile, u64 code) {
    s32 IsPlayerCodeValid(u64, s32);
    return IsPlayerCodeValid(code, M2C_FIELD(profile, s32 *, 0x24));
}
/* Whether `code` is a valid player code for game id `gameId`: the code's low word
 * must have bit 31 clear and its high word must hold the 7-bit CRC-8 check of the
 * low word and the game id. */
s32 IsPlayerCodeValid(u64 code,s32 gameId) {
void BuildCrc8Table(u8 *,s32);
s32 Crc8Block(u8 *,s32 *,s32);
u8 table[256]; s32 data[2]; s32 check;
if(code & 0x80000000ULL) return 0;
data[0]=(s32)code; data[1]=gameId;
BuildCrc8Table(table,7);
check=Crc8Block(table,data,8)&127;
return (s64)check == (code>>32);
}

#pragma opt_propagation off
/* Return the profile id in the low word of player `code` when the code is valid
 * for `gameId` (see IsPlayerCodeValid), or -1 when it is not. */
s32 GetPlayerCodeId(u64 code, s32 gameId) {
    s32 ok = IsPlayerCodeValid(code, gameId);
    s32 mask = 0;

    if (ok) { mask--; mask = (u32)code & mask; }
    return mask;
}
#pragma opt_propagation reset
/* Format a player code as its 12-digit zero-padded decimal text at `out` (the
 * 64-bit code arrives as its low and high words). */
void FormatPlayerCode(char *out, u32 codeLow, u32 codeHigh) {
    M2C_UNK StringFormatN(M2C_UNK, M2C_UNK, M2C_UNK *, ...);
    extern u8 gFmtPlayerCode[];
    StringFormatN(out, 0xD, gFmtPlayerCode, codeLow, codeHigh);
}

#pragma opt_strength_reduction off
/* Parses the 12 ASCII digits at text[0..11] as a decimal u64, least significant
 * digit first.  Returns 0 if any byte is not a digit. */
u64 ParseFriendCodeDigits(void *text)
{
  s32 digitIndex;
  u64 value = 0;
  u64 placeValue = 1;
  s32 digitChar;
  text = (signed char *) text;
  text = text + (FRIEND_CODE_LENGTH - 1);
  digitIndex = 0;
  do
  {
    digitChar = *(((signed char *) text) - digitIndex);
    if (((digitChar < '0') || (digitChar > '9')) != 0)
    {
      return 0;
    }
    value += ((u64) (digitChar - '0')) * placeValue;
    placeValue *= 10;
    digitIndex++;
  }
  while (digitIndex < FRIEND_CODE_LENGTH);
  return value;
}
#pragma opt_strength_reduction reset
/* Render `value` in base 32 (the 0-9a-v alphabet), least significant digit last:
 * write one digit per BASE32_DIGIT_BITS of `bitCount` from the end of `out`, then
 * terminate the string. */
void Base32Encode(u64 value, s32 bitCount, char *out) {
    extern u8 gBase32Alphabet[];
    char *end;
    s32 digit;
    s32 index;
    s8 *alphabet = (s8 *)gBase32Alphabet;
    s32 length = (bitCount + BASE32_DIGIT_BITS - 1) / BASE32_DIGIT_BITS;

    index = 0;
    if (length > 0) {
        end = out + length;
        end--;
        do {
            digit = alphabet[value & BASE32_DIGIT_MASK];
            *(end - index) = digit;
            value >>= BASE32_DIGIT_BITS;
            index++;
        } while (index < length);
    }
    out[length] = 0;
}

/* Render a NAS player/key record as the text id the server exchanges: the 43-bit
 * player code and the 32-bit check word in base 32, with the four bytes of the
 * key kind in between ("%s%c%c%c%c%s"). */
void FormatNasId(void *record, u32 keyType, void *out) {
u64 GetNasPlayerCode(void *); s32 GetNasRecordCheckWord(void *);
void Base32Encode(u64,s32,char *);
M2C_UNK StringFormatN(M2C_UNK,M2C_UNK,M2C_UNK *,...);
extern M2C_UNK sNasIdFormat;
char code[NAS_ID_TEXT_SIZE]; char check[NAS_ID_TEXT_SIZE];
Base32Encode(GetNasPlayerCode(record),NAS_ID_CODE_BITS,code);
Base32Encode((u64)(u32)GetNasRecordCheckWord(record),NAS_ID_CHECK_BITS,check);
StringFormatN((M2C_UNK)out,NAS_ID_TEXT_SIZE,&sNasIdFormat,code,(keyType>>24)&255,(keyType>>16)&255,(keyType>>8)&255,keyType&255,check);
}

/* Build the 0x40-byte profile-id block: clear it, store its size and the game
 * id, create the NAS login key at +4, mark the key record at +0x10 unresolved
 * and store the CRC32 of the block's first 0x3C bytes at +0x3C. */
void InitProfileIdBlock(void *block, s32 gameId) {
    void MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    void InitNasLoginKey(void *);
    void SetPlayerRecordKind(M2C_UNK, M2C_UNK);
    void BuildCrc32Table(M2C_UNK *, s32);
    s32 Crc32Block(M2C_UNK *, void *, M2C_UNK);
    u32 table[256];

    MI_CpuFill8((M2C_UNK)block, 0, PROFILE_ID_BLOCK_SIZE);
    M2C_FIELD(block, s32 *, 0) = PROFILE_ID_BLOCK_SIZE;
    M2C_FIELD(block, s32 *, 0x1C) = 0;
    M2C_FIELD(block, s32 *, PROFILE_ID_BLOCK_GAME_ID) = gameId;
    InitNasLoginKey((u8 *)block + 4);
    SetPlayerRecordKind((M2C_UNK)((u8 *)block + 0x10), 0);
    BuildCrc32Table((M2C_UNK *)table, 0xEDB88320);
    M2C_FIELD(block, s32 *, 0x3C) = Crc32Block((M2C_UNK *)table, block, 0x3C);
    M2C_FIELD(block, s32 *, 0x20) = (s32)(M2C_FIELD(block, s32 *, 0x20) | 1);
}

