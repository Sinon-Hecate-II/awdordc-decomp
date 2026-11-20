/* 48 functions from 0x02031290 to 0x02032228 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"

M2C_UNK Wfc_GetWorkBlock(M2C_UNK);

/* Dispatch the next state depending on the current game mode. */
s32 Wfc_StepMatch(void) {
    s32 Wfc_GetLinkState();
    s32 Wfc_GetSessionState();
    s32 Wfc_StepFriendConnect(void *);
    s32 func_0203152c();
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
            state = func_0203138c(ctx);
            break;
        case 2:                                 /* switch 1 */
            state = Wfc_StepFriendConnect(ctx);
            break;
        case 3:                                 /* switch 1 */
            state = func_02031480();
            break;
        case 4:                                 /* switch 1 */
            state = func_020314ac(ctx);
            break;
        case 5:                                 /* switch 1 */
            state = func_02031518(ctx);
            break;
        case 1:                                 /* switch 1 */
            state = func_0203152c();
            break;
        }
    } else {
        switch (state) {                       /* switch 2; irregular */
        case 15:                               /* switch 2 */
            state = func_02031518(ctx);
            break;
        case 11:                               /* switch 2 */
            state = func_0203152c();
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

s32 func_0203138c(M2C_UNK arg0) {
    s32 func_02021a90(s32);
    void Wfc_BuildHostConfig(M2C_UNK, M2C_UNK, M2C_UNK);
    extern s32 data_02138ac0;
    s32 temp_r0;
    s32 temp_r5;

    temp_r5 = Wfc_GetWorkBlock(1);
    temp_r0 = Wfc_GetWorkBlock(4);
    Wfc_BuildHostConfig(temp_r5, arg0, temp_r0);
    data_02138ac0 = 4;
    if (func_02021a90(temp_r0) == 0) {
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
    s32 func_020218bc();
    void func_020316c4(void *);
    u64 GetSystemTick(void);
    u64 U64Divide(u64, u64);
    u32 selection;

    if (func_020218bc() != 0) {
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

s32 func_02031480(void) {
    M2C_UNK Wfc_GetWorkBlock(M2C_UNK);
    M2C_UNK Wfc_SetResultCode(M2C_UNK);
    s32 Dwc_HttpStartup();
    Wfc_GetWorkBlock(8);
    if (Dwc_HttpStartup() == 0) {
        return 0xE;
    }
    Wfc_SetResultCode(3);
    return 0x11;
}

s32 func_020314ac(void *arg0) {
    s32 Wfc_FriendIdToSlot(u8);
    M2C_UNK Wfc_ReleaseNetwork();
    s32 func_020352ac();
    s32 func_020352ec();
    s32 temp_r0;
    void *temp_r4;

    temp_r4 = (void *)Wfc_GetWorkBlock(1);
    temp_r0 = func_020352ac();
    if (temp_r0 != 0) {
        if (M2C_FIELD(temp_r4, u8 *, 0x15) == Wfc_FriendIdToSlot(M2C_FIELD(arg0, u8 *, 0xD0D))) {
            M2C_FIELD(temp_r4, s32 *, 0x10) = func_020352ec();
        }
        Wfc_ReleaseNetwork();
        if (temp_r0 == 0xB) {
            return 0xF;
        }
        M2C_FIELD((arg0 + (M2C_FIELD(arg0, u8 *, 0xD13) * 4)), s8 *, 0x444) = 1;
        return 0xB;
    }
    return 0xE;
}

s32 func_02031518(void *arg0) {
    M2C_UNK func_0202f590(u8);
    func_0202f590(M2C_FIELD(arg0, u8 *, 0xD0D));
    return 0x10;
}

s32 func_0203152c(void) {
 s32 NetworkPollClosing(void);s32 func_02021c04(void);
 u32 v; if(NetworkPollClosing()!=0)return 11;
 v=func_02021c04();return v==0 || v==(u32)-39 ?9:11;
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

s32 Wfc_EncodePlayerCode(void *arg0) {
    u32 temp_r3;

    temp_r3 = 0;
    temp_r3 |= M2C_FIELD(arg0, u8 *, 0) << 0x18;
    temp_r3 |= M2C_FIELD(arg0, u8 *, 1) << 0x10;
    temp_r3 |= M2C_FIELD(arg0, u8 *, 2) << 0x8;
    temp_r3 |= M2C_FIELD(arg0, u8 *, 3);
    return ((temp_r3 << 0x18) & 0xFF000000) | (((temp_r3 << 8) & 0xFF0000) | ((u8) (temp_r3 >> 0x18) | ((temp_r3 >> 8) & 0xFF00)));
}

s32 Wfc_EncodeCodeMask(s32 arg0) {
    u32 var_r3;
    s32 var_r0;
    s32 temp_r1;

    temp_r1 = 0x20 - arg0;
    var_r3 = -1U;
    var_r0 = 0;
    if (temp_r1 > 0) {
        do {
            var_r0 += 1;
            var_r3 *= 2;
        } while (var_r0 < temp_r1);
    }
    return ((var_r3 << 0x18) & 0xFF000000) | (((var_r3 << 8) & 0xFF0000) | ((u8) (var_r3 >> 0x18) | ((var_r3 >> 8) & 0xFF00)));
}

#pragma opt_strength_reduction off
void func_020316c4(void *arg0) {
    void func_020218f4(M2C_UNK *, M2C_UNK *);
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
    func_020218f4(&sp4, &sp0);
}
#pragma opt_strength_reduction reset
s32 Wfc_IsSharedApCode(M2C_UNK arg0) {
    M2C_UNK func_0203182c(M2C_UNK, M2C_UNK *);
    s32 ByteCompareN(M2C_UNK, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fb2a4;
    M2C_UNK buf[6];

    func_0203182c(arg0, &buf[0]);
    if (ByteCompareN((M2C_UNK) &buf[0], &data_020fb2a4, 8) == 0) {
        return 1;
    }
    return 0;
}

void func_02031784(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0203182c(M2C_UNK, M2C_UNK *);
    void func_02031930(M2C_UNK *, M2C_UNK);
    M2C_UNK buf[6];

    func_0203182c(arg0, &buf[0]);
    func_02031930(&buf[0], arg1);
}

void func_020317ac(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0203182c(M2C_UNK, M2C_UNK *);
    s32 ByteCompareN(M2C_UNK, M2C_UNK *, M2C_UNK);
    void MI_CpuCopy8(void *, void *, u32);
    extern M2C_UNK data_020fb2a4;
    M2C_UNK buf0[2];
    M2C_UNK buf1[4];
    func_0203182c(arg0, buf0);
    if (ByteCompareN((M2C_UNK)buf0, &data_020fb2a4, 8) != 0) {
        return;
    }
    MI_CpuCopy8(buf1, (void *)arg1, 0xA);
}

s32 Wfc_IsUsbApCode(M2C_UNK arg0) {
    s32 ByteCompareN(M2C_UNK, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fb2b0;
    if (ByteCompareN(arg0, &data_020fb2b0, 8) == 0) {
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
M2C_UNK func_0203182c(M2C_UNK arg0, M2C_UNK *arg1) {
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
void func_02031930(M2C_UNK *arg0, M2C_UNK arg1) {
    M2C_UNK func_0200c454(M2C_UNK *);
    M2C_UNK func_0200c494(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_0200c55c(M2C_UNK *, M2C_UNK *);
    void MI_CpuCopy8(void *, void *, u32);
    u8 digest[20];
    u8 ctx[88];
    func_0200c454((M2C_UNK *)ctx);
    func_0200c494((M2C_UNK *)ctx, (M2C_UNK)arg0, 0x18);
    func_0200c55c((M2C_UNK *)digest, (M2C_UNK *)ctx);
    MI_CpuCopy8(digest + 3, (void *)arg1, 0xD);
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

s32 func_02031b28(u32 arg0) {
    if (arg0 >= 0x41U && arg0 <= 0x5AU) {
        return (s32)(arg0 - 0x41U);
    }
    if (arg0 >= 0x61U && arg0 <= 0x7AU) {
        s32 temp_r0 = (s32)(arg0 - 0x61U);
        return temp_r0 + 0x1A;
    }
    if (arg0 >= 0x30U && arg0 <= 0x39U) {
        s32 temp_r0 = (s32)(arg0 - 0x30U);
        return temp_r0 + 0x34;
    }
    if (arg0 == 0x2BU) {
        return 0x3E;
    }
    if (arg0 == 0x2FU) {
        return 0x3F;
    }
    if (arg0 == 0x3DU) {
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
s32 func_02031d00(M2C_UNK arg0)
{
  M2C_UNK func_02000b9c(s32);
  s32 func_02046884(M2C_UNK);
  M2C_UNK func_02047098(M2C_UNK);
  s32 func_02047320();
  u32 temp_r4;
  s32 var_r5;
  var_r5 = 0;
  func_02000b9c(0x02000C34);
  temp_r4 = (u32) func_02046884(arg0);
  if (func_02047320() != 0)
  {
    if (1)
    {
      func_02047098(arg0);
    }
    var_r5 = 1;
  }
  if ((s32) temp_r4 < 0)
  {
    if (var_r5 != 0)
    {
      return 2;
    }
    else
    {
      return 3;
    }
  }
  if (var_r5 != 0)
  {
    return 1;
  }
  return 0;
}

s32 func_02031d64(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    if (((u32) arg1 & ~(u32) arg3) != 0U) {
        return 0;
    }
    *(u32 *) arg0 = (*(u32 *) arg0 & ~((u32) arg3 << (u32) arg2)) | ((u32) arg1 << (u32) arg2);
    return 1;
}

u64 GetNasPlayerCode(void *arg0) {
    u32 hi = M2C_FIELD(arg0, u32 *, 0) & 0x7FF;
    u32 lo = M2C_FIELD(arg0, u32 *, 4);
    return ((u64) hi << 32) | lo;
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

void func_02031dd4(void *arg0, s32 arg1, M2C_UNK arg2) {
    func_02031d64((M2C_UNK)arg0, arg2, 0, 0x7FF);
    M2C_FIELD(arg0, s32 *, 4) = arg1;
}

void func_02031dfc(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
}

void func_02031e04(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 8) = arg2;
}

void func_02031e0c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = arg1;
}

s32 func_02031e14(u32 *arg0) {
    return 0x1FFFFF & ((u32) *arg0 >> 0xB);
}

s32 GetPlayerRecordKind(void) {
    s32 func_02031e14();
    return func_02031e14() & 3;
}

s32 IsPlayerRecordJoined(M2C_UNK arg0) {
    s32 var_r0;

    if (GetPlayerRecordKind() == 3) {
        if ((func_02031e14((u32 *)arg0) & 4) == 4) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    }
    return 0;
}

void GetPlayerRecordType(void) {
    M2C_UNK GetPlayerRecordKind();
    GetPlayerRecordKind();
}

#pragma optimization_level 2
void func_02031e7c(M2C_UNK a,M2C_UNK b) { M2C_UNK func_02031d64(M2C_UNK,M2C_UNK,M2C_UNK,s32); func_02031d64(a,b,11,0x1fffff); }
void func_02031e94(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_02031e14(u32 *);
    void func_02031e7c(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02031e14((u32 *) arg0);
    temp_r0 = temp_r0 & ~3;
    func_02031e7c(arg0, temp_r0 | arg1);
}

void MarkPlayerRecordJoined(M2C_UNK arg0) {
    s32 GetPlayerRecordKind();
    s32 func_02031e14(u32 *);
    void func_02031e7c(M2C_UNK, M2C_UNK);
    s32 res;

    if (GetPlayerRecordKind() != 3) {
        return;
    }
    res = func_02031e14((u32 *) arg0) | 4;
    func_02031e7c(arg0, res);
}

void func_02031ee4(M2C_UNK arg0) {
    if (GetPlayerRecordKind() != 3) {
        return;
    }
    func_02031e7c(arg0, func_02031e14((u32 *)arg0) & ~4);
}

u64 func_02031f14(s32 arg0, s32 arg1) {
    void func_02076698(u8 *, s32);
    s32 func_02076810(u8 *, s32 *, s32);
    u8 buf[0x100];
    s32 in[2];

    in[0] = arg0;
    in[1] = arg1;
    func_02076698(buf, 7);
    return (u32) arg0 | ((u64) (func_02076810(buf, in, 8) & 0x7f) << 32);
}

void func_02031f58(void *arg0, u64 arg1) {
s32 IsPlayerCodeValid(u64,s32);
IsPlayerCodeValid(arg1,M2C_FIELD(arg0,s32 *,0x24));
}
s32 IsPlayerCodeValid(u64 arg0,s32 arg2) {
void func_02076698(u8 *,s32);
s32 func_02076810(u8 *,s32 *,s32);
u8 buf[256]; s32 in[2]; s32 h;
if(arg0 & 0x80000000ULL) return 0;
in[0]=(s32)arg0; in[1]=arg2;
func_02076698(buf,7);
h=func_02076810(buf,in,8)&127;
return (s64)h == (arg0>>32);
}

#pragma opt_propagation off
s32 GetPlayerCodeId(u64 arg0,s32 arg2) {
s32 ok=IsPlayerCodeValid(arg0,arg2);
s32 mask=0;
if(ok) {mask--; mask=(u32)arg0 & mask;}
return mask;
}
#pragma opt_propagation reset
void func_02032004(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK StringFormatN(M2C_UNK, M2C_UNK, M2C_UNK *, ...);
    extern M2C_UNK data_020fb2bc;
    StringFormatN(arg0, 0xD, &data_020fb2bc, arg1, arg2);
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
void Base32Encode(u64 value, s32 arg2, char *arg3) {
 extern u8 gBase32Alphabet[];
 char *end;
 s32 c;
 s32 i;
 s8 *table=(s8 *)gBase32Alphabet;
 s32 count=(arg2+4)/5;
 i=0;
 if(count>0) {
 end=arg3+count;
 end--;
 do {
 c=table[value&31];
 *(end-i)=c;
 value>>=5;
 i++;
 }while(i<count);
 }
 arg3[count]=0;
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

void func_020321ac(void *arg0, s32 arg1) {
    void MI_CpuFill8(M2C_UNK, M2C_UNK, M2C_UNK);
    void InitNasLoginKey(void *);
    void func_02031e94(M2C_UNK, M2C_UNK);
    void func_02076794(M2C_UNK *, s32);
    s32 func_02076860(M2C_UNK *, void *, M2C_UNK);
    u32 table[256];

    MI_CpuFill8((M2C_UNK)arg0, 0, 0x40);
    M2C_FIELD(arg0, s32 *, 0) = 0x40;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = arg1;
    InitNasLoginKey((u8 *)arg0 + 4);
    func_02031e94((M2C_UNK)((u8 *)arg0 + 0x10), 0);
    func_02076794((M2C_UNK *)table, 0xEDB88320);
    M2C_FIELD(arg0, s32 *, 0x3C) = func_02076860((M2C_UNK *)table, arg0, 0x3C);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32)(M2C_FIELD(arg0, s32 *, 0x20) | 1);
}

