/* 30 functions from 0x0202F37C to 0x02030348 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
typedef struct SelectionEntryFlag { u8 low:4; u8 high:4; } SelectionEntryFlag;
typedef struct SelectionFlagBlock { u8 pad[0xc00]; u8 low:6; u8 mode:2; } SelectionFlagBlock;

/* Free owned WFC work blocks in reverse order, ending with the allocation state itself. */
void Wfc_FreeWorkBlocks(void) {
    void *Wfc_GetWorkBlock(s32);
    WfcAllocationState *state = Wfc_GetWorkBlock(WFC_WORK_CONTROL);
    void *block;

    if (state->ownedMask & WFC_WORK_FRIENDS) {
        block = Wfc_GetWorkBlock(WFC_WORK_FRIENDS);
        state->ownedMask &= ~WFC_WORK_FRIENDS;
        state->freeBlock(WFC_WORK_FRIENDS, block, WFC_FRIENDS_SIZE);
    }
    if (state->ownedMask & WFC_WORK_CALLBACKS) {
        block = Wfc_GetWorkBlock(WFC_WORK_CALLBACKS);
        state->ownedMask &= ~WFC_WORK_CALLBACKS;
        state->freeBlock(WFC_WORK_CALLBACKS, block, WFC_CALLBACKS_SIZE);
    }
    if (state->ownedMask & WFC_WORK_AUX) {
        block = Wfc_GetWorkBlock(WFC_WORK_AUX);
        state->ownedMask &= ~WFC_WORK_AUX;
        state->freeBlock(WFC_WORK_AUX, block, WFC_AUX_SIZE);
    }
    if (state->ownedMask & WFC_WORK_SESSION) {
        block = Wfc_GetWorkBlock(WFC_WORK_SESSION);
        state->ownedMask &= ~WFC_WORK_SESSION;
        state->freeBlock(WFC_WORK_SESSION, block, WFC_SESSION_SIZE);
    }
    if (state->ownedMask & WFC_WORK_CONTROL) {
        state->ownedMask &= ~WFC_WORK_CONTROL;
        state->freeBlock(WFC_WORK_CONTROL, state, WFC_CONTROL_SIZE);
    }
}

/* Returns the WFC work block allocated for the given WFC_WORK_* tag (the manager
 * keeps them in reverse tag order), or 0 for a tag with no block. */
void *Wfc_GetWorkBlock(s32 tag) {
 extern M2C_UNK gWfcManager;
 if (tag & WFC_WORK_CONTROL) return ((WfcManager *)&gWfcManager)->control;
 if (tag & WFC_WORK_SESSION) return ((WfcManager *)&gWfcManager)->session;
 if (tag & WFC_WORK_AUX) return ((WfcManager *)&gWfcManager)->aux;
 if (tag & WFC_WORK_CALLBACKS) return ((WfcManager *)&gWfcManager)->callbacks;
 if (tag & WFC_WORK_FRIENDS) return ((WfcManager *)&gWfcManager)->friends;
 return 0;
}

void *Wfc_GetWorkBlock(s32);
u32 Wfc_FriendIdToSlot(u32);
/* Publish the WFC session state: store it in the control block and, when it is
 * higher than any state reached so far, remember it; for the friend
 * connection's link stages (above 7) also publish the selected friend's save
 * slot and its record's connection result. */
void Wfc_PublishState(u8 state) {
 void *control = Wfc_GetWorkBlock(WFC_WORK_CONTROL);
 void *friends = Wfc_GetWorkBlock(WFC_WORK_FRIENDS);
 M2C_FIELD(control,u8 *,WFC_CONTROL_STATE) = state;
 if (state < 0x10) {
  if (state > M2C_FIELD(control,u8 *,WFC_CONTROL_STATE_MAX)) {
   M2C_FIELD(control,u8 *,WFC_CONTROL_STATE_MAX) = state;
   if (state > 7) {
    M2C_FIELD(control,u8 *,WFC_CONTROL_SLOT) = Wfc_FriendIdToSlot(M2C_FIELD(friends,u8 *,WFC_STATE_RESULT_ID));
    M2C_FIELD(control,u8 *,WFC_CONTROL_RECORD_RESULT) = M2C_FIELD((u8 *)friends + M2C_FIELD(friends,u8 *,WFC_STATE_RECORD_INDEX)*4,u8 *,WFC_STATE_RECORD_RESULT);
   }
  }
 }
}

u8 Wfc_GetSessionState(void) {
    extern M2C_UNK gWfcManager;
    return M2C_FIELD(M2C_FIELD(&gWfcManager, void **, 0x10), u8 *, 9);
}

/* Record the result code of the current connection step in the WFC control
 * block, together with the session state the step ran in. */
void Wfc_SetResultCode(s32 resultCode) {
    void *Wfc_GetWorkBlock(M2C_UNK);
    void *control;

    control = Wfc_GetWorkBlock(WFC_WORK_CONTROL);
    M2C_FIELD(control, s32 *, WFC_CONTROL_RESULT) = resultCode;
    M2C_FIELD(control, s8 *, WFC_CONTROL_STEP_STATE) = Wfc_GetSessionState();
}

s32 Wfc_GetResultCode(void) {
 extern M2C_UNK gWfcManager;
 return M2C_FIELD(M2C_FIELD(&gWfcManager, void **, 0x10), s32 *, 0xC);
}

/* Publish the save slot of the friend id the WFC session is match-making with
 * into the control block. */
void Wfc_SetFriendSlot(u32 friendId) {
    extern M2C_UNK gWfcManager;
    M2C_FIELD(M2C_FIELD(&gWfcManager, void **, 0x10), u8 *, WFC_CONTROL_FRIEND_SLOT) = Wfc_FriendIdToSlot(friendId);
}

u32 Wfc_FriendIdToSlot(u32 arg0) {
 if (arg0 > 2) arg0 = (u8)(arg0 - 3);
 return arg0;
}

/* Release the WFC callbacks and friend-roster work blocks (the blocks a friend
 * session owns), leaving the session, control and auxiliary blocks allocated. */
void Wfc_ClearWorkFlags(void) {
 void Wfc_ReleaseWorkBlock(s32, void *, s32);
 extern M2C_UNK gWfcManager;
 Wfc_ReleaseWorkBlock(WFC_WORK_CALLBACKS, ((WfcManager *)&gWfcManager)->callbacks, WFC_CALLBACKS_SIZE);
 Wfc_ReleaseWorkBlock(WFC_WORK_FRIENDS, ((WfcManager *)&gWfcManager)->friends, WFC_FRIENDS_SIZE);
}

/* Whether the selected friend record may be connected to: returns 2 when another
 * record with a valid friend id carries the same code, 1 otherwise (also when the
 * selection resolves to no friend id). */
s32 Wfc_GetFriendConnectResult(void) {
 s32 StringCompareN(void *, void *, s32);
 extern M2C_UNK gWfcManager;
 s32 offset;
 void *base;
 u8 i;
 u8 selected;
 void *p;
 u8 count;
 p = M2C_FIELD(&gWfcManager, void **, 0);
 selected = M2C_FIELD(p,u8 *,WFC_STATE_RECORD_INDEX);
 base = p + WFC_STATE_RECORDS + WFC_RECORD_CODE_ALT;
 offset = (s16)selected * (s16)WFC_RECORD_STRIDE;
 if (M2C_FIELD(p,u8 *,WFC_STATE_RESULT_ID) >= 6) return 1;
 count = M2C_FIELD(p,u8 *,WFC_STATE_RECORD_COUNT);
 for (i=0;i<count;i++) {
  if (i != selected && M2C_FIELD(p + i*4,u8 *,WFC_STATE_RECORD_ID)<6) {
   s32 off = i*WFC_RECORD_STRIDE;
   if (StringCompareN(base+offset,base+off,M2C_FIELD(p+off,u16 *,WFC_STATE_RECORDS+WFC_RECORD_CODE_LEN))==0) return 2;
  }
 }
 return 1;
}

/* Applies an incoming friend message to the WFC friend roster: depending on the
   session state it either marks the friend id straight away (empty code) or
   matches the code against the friend rows (state 3), the friend records (state 4)
   or a single row (state 5), then updates and re-sorts the roster. */
void Wfc_HandleFriendMessage(s32 arg0) {
 void *msg=(void *)arg0;
 void *Wfc_GetWorkBlock(s32); u8 Wfc_GetSessionState(void);
 void Wfc_MarkFriendId(u16); s32 Wfc_MatchFriendEntry(void *,s32,void *); s32 Wfc_MatchFriendRecord(void *,void *);
 s32 Wfc_StoreFriendRecord(s32,void *,M2C_UNK,void *); void Wfc_SortFriendRoster(s32,s32);
 s32 result=-1; u8 friendId; void *wfc=Wfc_GetWorkBlock(16);
 M2C_FIELD(Wfc_GetWorkBlock(1),u8 *,11)=1;
 switch(Wfc_GetSessionState()) {
 case 3:
 friendId=M2C_FIELD(wfc,u8 *,WFC_STATE_FRIEND_ID);
 if(M2C_FIELD(msg,u16 *,10)==0 || M2C_FIELD(msg,u8 *,12)==0) {Wfc_MarkFriendId(M2C_FIELD(msg,u16 *,0x36));}
 else if(M2C_FIELD(msg,u16 *,10)==1 || M2C_FIELD(msg,u8 *,12)==WFC_CODE_LEN_FRIEND) {
 Wfc_MarkFriendId(M2C_FIELD(msg,u16 *,0x36));
 result=Wfc_MatchFriendEntry(msg,M2C_FIELD(wfc,u8 *,WFC_STATE_ENTRY_COUNT),wfc+WFC_STATE_ENTRIES);
 }else result=Wfc_MatchFriendEntry(msg,M2C_FIELD(wfc,u8 *,WFC_STATE_ENTRY_COUNT),wfc+WFC_STATE_ENTRIES);
 break;
 case 4:
 friendId=M2C_FIELD(wfc+M2C_FIELD(wfc,u8 *,WFC_STATE_WORK_INDEX)*WFC_RECORD_STRIDE,u16 *,0x4A6)-1;
 result=Wfc_MatchFriendRecord(msg,wfc);
 if(result>=0) M2C_FIELD(wfc+0x447+M2C_FIELD(wfc,u8 *,WFC_STATE_WORK_INDEX)*4,u8 *,0)|=0x80;
 break;
 case 5:
 friendId=M2C_FIELD(wfc,u8 *,WFC_STATE_FRIEND_ID);
 result=Wfc_MatchFriendEntry(msg,1,wfc+WFC_STATE_ENTRIES+M2C_FIELD(wfc,u8 *,WFC_STATE_WORK_INDEX)*WFC_ENTRY_STRIDE);
 if(result>=0) {
 s32 i=(s16)M2C_FIELD(wfc,u8 *,WFC_STATE_WORK_INDEX)*(s16)WFC_ENTRY_STRIDE; void *q=wfc+WFC_STATE_ENTRIES;
 M2C_FIELD(q+i,u8 *,0)=(M2C_FIELD(q+i,u8 *,0)&~15)|1;
 } break;
 default:return;
 }
 if(result>=0) Wfc_SortFriendRoster(Wfc_StoreFriendRecord(result,msg,friendId,wfc),(s32)wfc);
}

/* Recognise a friend record whose code is one of the built-in connection codes:
 * when the roster's list mode includes it and the code carries the connection
 * flag, return the friend id of the NWCUSBAP USB access point (6) or of the
 * encoded NDWCSHAP shared access point (7); -1 for any other code. */
s32 Wfc_MatchFriendCode(void *record) {
 s32 Wfc_IsSharedApCode(void *);
 s32 Wfc_IsUsbApCode(void *);
 void *friends = Wfc_GetWorkBlock(WFC_WORK_FRIENDS);
 u32 mode = (u32)(M2C_FIELD(friends,u8 *,WFC_STATE_FLAGS)<<28)>>28;
 if ((mode==WFC_LIST_MODE_ALL || mode==WFC_LIST_MODE_USB_AP) && (((s32)M2C_FIELD(record,u16 *,WFC_RECORD_FLAGS)>>4)&1)==1 && Wfc_IsUsbApCode(record+WFC_RECORD_CODE)==1) return WFC_FRIEND_ID_USB_AP;
 mode = (u32)(M2C_FIELD(friends,u8 *,WFC_STATE_FLAGS)<<28)>>28;
 if ((mode==WFC_LIST_MODE_ALL || mode==WFC_LIST_MODE_SHARED_AP) && (((s32)M2C_FIELD(record,u16 *,WFC_RECORD_FLAGS)>>4)&1)==1 && Wfc_IsSharedApCode(record+WFC_RECORD_CODE)==1) return WFC_FRIEND_ID_SHARED_AP;
 return -1;
}

/* Match an incoming friend message against the first `count` rows of the WFC
 * friend-list `entries`: a row matches when its code length is the message's code
 * length and its code bytes are the same.  A friend code that is one of the
 * built-in connection codes is resolved first and wins when it is known; a matching
 * row returns its friend id, and no match at all returns -1. */
s32 Wfc_MatchFriendEntry(void *msg, s32 count, void *entries) {
    s32 StringCompareN(void *,void *,s32);
    s32 result; u8 codeLen; s32 row; u32 len; void *entry = entries;
    if (M2C_FIELD(msg,u16 *,WFC_MSG_CODE_LEN) == WFC_CODE_LEN_FRIEND) {
        result = Wfc_MatchFriendCode(msg);
        if (result > 0) return result;
    }
    row = 0;
    if (count > 0) {
        len = M2C_FIELD(msg,u16 *,WFC_MSG_CODE_LEN); codeLen = len;
        do {
            if (codeLen == M2C_FIELD(entry,u8 *,WFC_ENTRY_CODE_LEN) && StringCompareN((u8 *)msg + WFC_MSG_CODE, (u8 *)entry + WFC_ENTRY_CODE, len) == 0) return M2C_FIELD(entry,u8 *,WFC_ENTRY_ID);
            row++; entry = (u8 *)entry + WFC_ENTRY_STRIDE;
        } while (row < count);
    }
    return -1;
}

/* Matches an incoming friend message against the WFC friend records by the friend
 * code the message carries and returns the friend id the matching record resolved
 * to, or -1 when no record matches.  A 32-byte code is first tried against the
 * built-in connection codes. */
s32 Wfc_MatchFriendRecord(void *msg, void *friends) {
    s32 StringCompareN(void *, void *, s32);
    s32 t, i;
    void *p, *q;
    s32 len, n;

    if (M2C_FIELD(msg, u16 *, WFC_MSG_CODE_LEN) == WFC_CODE_LEN_FRIEND) {
        t = Wfc_MatchFriendCode(msg);
        if (t > 0) return t;
    }
    n = M2C_FIELD(friends, u8 *, WFC_STATE_RECORD_COUNT);
    i = 0;
    if (n > 0) {
        len = M2C_FIELD(msg, u16 *, WFC_MSG_CODE_LEN);
        p = friends;
        q = friends + WFC_STATE_RECORDS + WFC_RECORD_CODE;
        do {
            if (len == M2C_FIELD(p, u16 *, WFC_STATE_RECORDS + WFC_RECORD_CODE_LEN) &&
                StringCompareN(msg + WFC_MSG_CODE, q, len) == 0)
                return M2C_FIELD(friends + i * 4, u8 *, WFC_STATE_RECORD_ID);
            i++;
            p += WFC_RECORD_STRIDE;
            q += WFC_RECORD_STRIDE;
        } while (i < n);
    }
    return -1;
}

/* Matches an incoming friend message against the WFC friend records by the
 * message's 6-byte friend code.  A matching record is updated (func_0202fab4);
 * otherwise the message is stored as a new record (func_0202fa68) in the roster's
 * scratch slot and the record count grows.  Returns the record index the roster
 * must be re-sorted from (10 for a newly stored record). */
s32 Wfc_StoreFriendRecord(s32 friendSlot, void *msg, M2C_UNK friendId, void *wfc) {
    void func_0202fa68(u8, void *, s32, s32);
    void func_0202fab4(s32, void *, s32, void *);
    s32 i;
    s32 index;
    u8 count0;
    u8 recordCount;
    void *record;

    recordCount = M2C_FIELD(wfc, u8 *, WFC_STATE_RECORD_COUNT);
    index = -1;
    i = 0;
    if ((s32) recordCount > 0) {
        record = wfc + 0x474;
loop_2:
        if ((M2C_FIELD(msg, u8 *, 4) == M2C_FIELD(record, u8 *, 0)) && (M2C_FIELD(msg, u8 *, 5) == M2C_FIELD(record, u8 *, 1)) && (M2C_FIELD(msg, u8 *, 6) == M2C_FIELD(record, u8 *, 2)) && (M2C_FIELD(msg, u8 *, 7) == M2C_FIELD(record, u8 *, 3)) && (M2C_FIELD(msg, u8 *, 8) == M2C_FIELD(record, u8 *, 4)) && (M2C_FIELD(msg, u8 *, 9) == M2C_FIELD(record, u8 *, 5))) {
            index = i;
        } else {
            i += 1;
            record += 0xC0;
            if (i < (s32) recordCount) {
                goto loop_2;
            }
        }
    }
    if (index == -1) {
        func_0202fa68(friendSlot, msg, friendId, (s32)wfc);
        count0 = M2C_FIELD(wfc, u8 *, WFC_STATE_RECORD_COUNT);
        index = 0xA;
        if ((u32) count0 < 0xAU) {
            M2C_FIELD(wfc, u8 *, WFC_STATE_RECORD_COUNT) = (u8) (count0 + 1);
        }
    } else {
        func_0202fab4(index, msg, friendId, wfc);
    }
    return index;
}

void func_0202fa68(u8 arg0,void *arg1,s32 arg2,s32 arg3) {
M2C_UNK MIi_CpuCopy32(void *,s32,M2C_UNK);
s32 value;
u8 byte;
u16 code;
void *p;
p=(void *)(arg3+0x6c);
M2C_FIELD(p,u8 *,0x401)=arg0;
code=M2C_FIELD(arg1,u16 *,2);
value=(s32)code>>2;
if(!(code&2))value+=25;
M2C_FIELD(p,volatile u8 *,0x402)=(u8)(value & 0xff);
M2C_FIELD(p,u8 *,0x403)=(M2C_FIELD(p,u8 *,0x403)&~127)|(arg2&127);
MIi_CpuCopy32(arg1,arg3+0xbf0,0xc0);
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma optimization_level 2
void func_0202fab4(s32 arg0, void *arg1, s32 arg2, void *arg3) {
 M2C_UNK MIi_CpuCopy32(void *, s32, M2C_UNK);
 s32 n; void *base; s32 offset; void *p; u16 v;
 v=M2C_FIELD(arg1,u16 *,2);
 base=(u8 *)arg3+0x444;
 offset=arg0*0xC0;
 arg0=(s32)((u8 *)base+arg0*4);
 p=(void *)arg0;
 n=(s32)v>>2;
 n += (v & 2) ? 0 : 25;
 n=(u8)n;
 arg3=(u8 *)arg3+0x470;
 if((u32)(u8)n>M2C_FIELD(p,u8 *,2)) {
 M2C_FIELD(p,u8 *,2)=n;
 M2C_FIELD(p,u8 *,3)=(M2C_FIELD(p,u8 *,3)&~0x7F)|(arg2&0x7F);
 }
 MIi_CpuCopy32(arg1,(s32)arg3+offset,0xC0);
}
#pragma opt_common_subs off
/* Bubble-sorts the WFC friend roster backwards from `count`-1: while the entry
 * in front has the same or a lower byte at +0x2 than the one before it, the two
 * per-record result entries (WFC_STATE_RECORD_RESULT, 4 bytes each) and their
 * 0xC0-byte friend records (WFC_STATE_RECORDS) are swapped through the stack,
 * so the roster ends up ordered with its best entry at index 0.  Clears the
 * last result entry and the last record. */
void Wfc_SortFriendRoster(s32 count, s32 base) {
    M2C_UNK CpuFill(M2C_UNK, s32, M2C_UNK);
    M2C_UNK MIi_CpuCopy32(void *, s32, s32);
    u8 recordTemp[0xc0];
    M2C_UNK resultTemp;
    s32 index; M2C_UNK *curResult; s32 prev; s32 results, records; s32 prevResult; s32 prevRecord, curOffset;

    index = count;
    results = base + WFC_STATE_RECORD_RESULT;
    records = base + WFC_STATE_RECORDS;
    prev = index - 1;
    if (prev >= 0) {
        prevRecord = (prev * WFC_RECORD_STRIDE) + records;
        prevResult = results + prev*4;
loop_2:
        if ((u32) M2C_FIELD((results + (index * 4)), u8 *, 2) >= (u32) M2C_FIELD((results + (prev * 4)), u8 *, 2)) {
            MIi_CpuCopy32((void *)prevResult, (s32)&resultTemp, 4);
            curResult = (M2C_UNK *) (results + (index * 4));
            MIi_CpuCopy32(curResult, (s32)prevResult, 4);
            MIi_CpuCopy32(&resultTemp, (s32)curResult, 4);
            MIi_CpuCopy32((M2C_UNK *) prevRecord, (s32)recordTemp, 0xC0);
            curOffset = index * WFC_RECORD_STRIDE;
            MIi_CpuCopy32((void *)(records + curOffset), prevRecord, 0xC0);
            MIi_CpuCopy32(&recordTemp, records + curOffset, 0xC0);
            index = prev;
            prevResult=prevResult-4;
            prevRecord -= WFC_RECORD_STRIDE;
            --prev;
            if (prev >= 0) {
                goto loop_2;
            }
        }
    }
    CpuFill(0, results + 0x28, 4);
    CpuFill(0, records + 0x780, 0xC0);
}
#pragma opt_common_subs reset
/* Step callback of the WFC connect step: a connection-status message stores its
 * outcome as the friend connection's event (cancelled, reported, finished, or the
 * fourth event for any other code), and the peer's friend message is handed to the
 * friend roster's handler. */
void Wfc_HandleConnectMessage(void *msg) {
 void Wfc_HandleFriendMessage(s32);
 void *wfc=Wfc_GetWorkBlock(WFC_WORK_FRIENDS);
 s16 type=M2C_FIELD(msg,s16 *,WFC_MSG_TYPE);
 if(type==WFC_MSG_TYPE_STATUS) {
 if(M2C_FIELD(msg,s16 *,WFC_MSG_HAS_RESULT)==0) return;
 switch(M2C_FIELD(msg,s32 *,WFC_MSG_RESULT)) {
 case WFC_RESULT_CANCELLED: M2C_FIELD(wfc,u8 *,WFC_STATE_CONN_EVENT)=WFC_CONN_EVENT_CANCELLED; return;
 case WFC_RESULT_REPORTED: M2C_FIELD(wfc,u8 *,WFC_STATE_CONN_EVENT)=WFC_CONN_EVENT_REPORTED; return;
 case WFC_RESULT_FINISHED: M2C_FIELD(wfc,u8 *,WFC_STATE_CONN_EVENT)=WFC_CONN_EVENT_FINISHED; return;
 default: M2C_FIELD(wfc,u8 *,WFC_STATE_CONN_EVENT)=WFC_CONN_EVENT_OTHER; return;
 }
 } else if(type==WFC_MSG_TYPE_FRIEND) Wfc_HandleFriendMessage(M2C_FIELD(msg,s32 *,WFC_MSG_PEER));
}

/* WFC friend-connection dispatch: the state-7 step resolves the selected friend
 * and starts its link (Wfc_StepFriendLink), the state-8 step advances the friend
 * connection that is opening (Wfc_UpdateFriendConnection); any other state is
 * returned unchanged.  The work-block call feeds the friend block to the step
 * implicitly in r0. */
s32 Wfc_StepFriends(void) {
    s32 Wfc_StepFriendLink();
    s32 Wfc_UpdateFriendConnection();
    s32 state;

    state = Wfc_GetSessionState();
    Wfc_GetWorkBlock(WFC_WORK_FRIENDS);
    switch (state) {
    case WFC_STEP_LINK:
        state = Wfc_StepFriendLink();
        break;
    case WFC_STEP_LINK_WAIT:
        state = Wfc_UpdateFriendConnection();
        break;
    }
    return state;
}

/* Polls/refreshes the current entry for state 'p': clears the D0D slot, zeroes a temp buffer,
   calls func_020300e8 to (re)validate, then updates the D0B flags and reports 9 or 8. */
s32 Wfc_StepFriendLink(void *p) {
void MI_CpuFill8(void *,s32,s32); u8 Wfc_ResolveFriendSelection(void *);
void *q=p+0x470+M2C_FIELD(p,u8 *,0xD13)*0xC0;
s32 ok;
M2C_FIELD(p,u8 *,0xD0D)=Wfc_ResolveFriendSelection(p);
MI_CpuFill8(p+0xCB8,0,0x52);
ok=func_020300e8(p,M2C_FIELD(p,u8 *,0xD0D),p+0xCB8);
if(ok) {
M2C_FIELD(p,u8 *,0xD0B)=(M2C_FIELD(p,u8 *,0xD0B)&~12)|4;
if(!(((s32)M2C_FIELD(q,u16 *,0x2C)>>4)&1)) {M2C_FIELD(p+M2C_FIELD(p,u8 *,0xD13)*4,u8 *,0x444)=3;return 9;}
if(M2C_FIELD(p,u8 *,0xD0D)==6 && M2C_FIELD(q,u8 *,0x15)==0) {M2C_FIELD(p+M2C_FIELD(p,u8 *,0xD13)*4,u8 *,0x444)=3;return 9;}
} else {
M2C_FIELD(p,u8 *,0xD0B)=M2C_FIELD(p,u8 *,0xD0B)&~12;
if((((s32)M2C_FIELD(q,u16 *,0x2C)>>4)&1)==1) {M2C_FIELD(p+M2C_FIELD(p,u8 *,0xD13)*4,u8 *,0x444)=3;return 9;}
}
M2C_FIELD(p,u8 *,0xD15)=0;M2C_FIELD(p,u8 *,0xD14)=0;return 8;
}

#pragma dont_inline on
s32 Wfc_GetConnectFlags(void *);
/* One step of the WFC friend-connection phase (state 8): while the link is up it
 * hands the selected friend record and the outgoing command buffer to
 * WFC_StartConnection, retrying up to three times; a reported outcome (event
 * 1/2/3) either clears the pending connection flags or stores the record's
 * result and finishes the step; when the link has dropped (state 9) it stamps
 * the start time and advances. */
s32 Wfc_UpdateFriendConnection(u8 *wfc) {
u32 Wfc_GetLinkState(); s32 Wfc_GetConnectFlags(void *); s32 Wfc_GetConnectModeFlags(void *);
void WFC_StartConnection(void *,void *,s32); unsigned long long GetSystemTick(void);
s32 state=Wfc_GetLinkState(wfc); s32 off; u8 *base; s32 flags; base=wfc+WFC_STATE_RECORDS; off=(s16)wfc[WFC_STATE_RECORD_INDEX]*(s16)WFC_RECORD_STRIDE;
if(state==3) {
{ s32 (*getFlags)(void *)=Wfc_GetConnectFlags; flags=getFlags(wfc); }
wfc[WFC_STATE_CONN_RETRY]++;
if(wfc[WFC_STATE_CONN_RETRY]>3){wfc[WFC_STATE_CONN_RETRY]=0;M2C_FIELD(wfc+wfc[WFC_STATE_RECORD_INDEX]*4,u8 *,WFC_STATE_RECORD_RESULT)=1;return 9;}
if(wfc[WFC_STATE_CONN_RETRY]!=1) {
if(wfc[WFC_STATE_CONN_EVENT]==1)wfc[WFC_STATE_CONN_FLAGS]&=~12;
else if(wfc[WFC_STATE_CONN_EVENT]==2){wfc[WFC_STATE_CONN_RETRY]=0;M2C_FIELD(wfc+wfc[WFC_STATE_RECORD_INDEX]*4,u8 *,WFC_STATE_RECORD_RESULT)=3;return 9;}
else if(wfc[WFC_STATE_CONN_EVENT]==3){wfc[WFC_STATE_CONN_RETRY]=0;M2C_FIELD(wfc+wfc[WFC_STATE_RECORD_INDEX]*4,u8 *,WFC_STATE_RECORD_RESULT)=4;return 9;}
else if(wfc[WFC_STATE_CONN_RETRY]==3)wfc[WFC_STATE_CONN_FLAGS]&=~12;
}
WFC_StartConnection(base+off,wfc+WFC_STATE_CMD_BUFFER,flags|Wfc_GetConnectModeFlags(wfc));
} else if(state==9) {wfc[WFC_STATE_CONN_RETRY]=0;M2C_FIELD(wfc,unsigned long long *,WFC_STATE_TIMER)=GetSystemTick();return 10;}
return 8;
}

/* Resolves which friend-list row the selected friend record corresponds to.  In
 * collect mode (selection mode 0) it returns the id of the first row whose code
 * matches the record and marks the duplicate rows; in commit mode it clears the
 * mark of the single selected row, returns its id and resets the mode. */
u8 Wfc_ResolveFriendSelection(void *arg0) {
    s32 Wfc_MatchFriendCode(void *);
    s32 Wfc_MatchFreespotCode(s32);
    s32 StringCompareN(void *, void *, s32);
    s32 friendId;
    s32 result;
    s32 match;
    s32 record;
    u8 *entryFlags2;
    void *entryBase;
    s32 matchCount2;
    s32 i;
    s32 i2;
    s32 matchCount;
    u16 codeLen;
    u8 entryFlag;
    void *modeBlock;
    void *entry;
    void *entryCode;
    u8 *entryFlags;

    record = (M2C_FIELD(arg0, u8 *, WFC_STATE_RECORD_INDEX) * WFC_RECORD_STRIDE) + (s32) (arg0 + WFC_STATE_RECORDS);
    friendId = 0;
    if (((u32) (M2C_FIELD(arg0, u8 *, WFC_STATE_FLAGS) << 0x18) >> 0x1E) == 0) {
        codeLen = M2C_FIELD(record, u16 *, WFC_RECORD_CODE_LEN);
        matchCount = friendId;
        if (codeLen == WFC_CODE_LEN_FRIEND) {
            result = Wfc_MatchFriendCode((void*)record);
            friendId = result;
            if (result > 0) { matchCount += 1; } else { friendId = 0; }
        } else if (codeLen == WFC_CODE_LEN_FREESPOT) {
            match = Wfc_MatchFreespotCode(record);
            friendId = match;
            if (match != 0) { matchCount += 1; } else { friendId = 0; }
        }
        i = 0;
        if ((s32) M2C_FIELD(arg0, u8 *, WFC_STATE_ENTRY_COUNT) > 0) {
            entry = arg0;
            entryCode = arg0 + WFC_STATE_ENTRIES + WFC_ENTRY_CODE;
            entryFlags = arg0 + WFC_STATE_ENTRIES;
            modeBlock = arg0 + 0x10C;
            do {
                if ((M2C_FIELD(record, u16 *, WFC_RECORD_CODE_LEN) == M2C_FIELD(entry, u8 *, WFC_STATE_ENTRIES + WFC_ENTRY_CODE_LEN)) && (StringCompareN((void*)(record + WFC_RECORD_CODE), entryCode, M2C_FIELD(record,u16*,WFC_RECORD_CODE_LEN)) == 0)) {
                    if (matchCount == 0) {
                        friendId = (s32) M2C_FIELD(entry, u8 *, WFC_STATE_ENTRIES + WFC_ENTRY_ID);
                    } else {
                        *entryFlags = (*entryFlags & ~0xF0) | WFC_ENTRY_MARK;
                        ((SelectionFlagBlock*)modeBlock)->mode=1;
                    }
                    matchCount += 1;
                }
                i += 1;
                entry += WFC_ENTRY_STRIDE;
                entryCode += WFC_ENTRY_STRIDE;
                entryFlags += WFC_ENTRY_STRIDE;
            } while (i < (s32) M2C_FIELD(arg0, u8 *, WFC_STATE_ENTRY_COUNT));
        }
    } else {
        i2 = friendId;
        matchCount2 = i2;
        if ((s32) M2C_FIELD(arg0, u8 *, WFC_STATE_ENTRY_COUNT) > 0) {
            entryBase = arg0;
            entryFlags2 = arg0 + WFC_STATE_ENTRIES;
            do {
                entryFlag = *entryFlags2;
                if (((SelectionEntryFlag*)entryFlags2)->high == 1) {
                    if (matchCount2 == 0) {
                        ((SelectionEntryFlag*)entryFlags2)->high=0;
                        friendId = (s32) M2C_FIELD(entryBase, u8 *, WFC_STATE_ENTRIES + WFC_ENTRY_ID);
                    }
                    matchCount2 += 1;
                }
                i2 += 1;
                entryFlags2 += WFC_ENTRY_STRIDE;
                entryBase += WFC_ENTRY_STRIDE;
            } while (i2 < (s32) M2C_FIELD(arg0, u8 *, WFC_STATE_ENTRY_COUNT));
        }
        if (matchCount2 == 1) {
            M2C_FIELD(arg0, u8 *, WFC_STATE_FLAGS) = (u8) (M2C_FIELD(arg0, u8 *, WFC_STATE_FLAGS) & ~WFC_STATE_SELECT_MODE);
        }
    }
    return (u8) friendId;
}

#pragma dont_inline reset
/* Connection flags for WFC_StartConnection: bits 2-3 of WFC_STATE_CONN_FLAGS
 * say whether the selected friend's record has been validated, in which case the
 * connection status is also marked valid. */
s32 Wfc_GetConnectFlags(void *wfc) {
    if (((u32) (M2C_FIELD(wfc, u8 *, WFC_STATE_CONN_FLAGS) << 0x1E) >> 0x1E) == 1) {
        return WFC_STATUS_CONNECT | WFC_STATUS_CONNECT_VALID;
    }
    return WFC_STATUS_CONNECT;
}

/* The connection-mode flags to hand WFC_StartConnection: when the friend
 * record has been validated (bits 2-3 of WFC_STATE_CONN_FLAGS are 1) they also
 * set connection status bit 0x40000, giving 0xC0000; otherwise 0x80000. */
s32 Wfc_GetConnectModeFlags(void *wfc) {
    if (((u32) (M2C_FIELD(wfc, u8 *, WFC_STATE_CONN_FLAGS) << 0x1C) >> 0x1E) == 1) {
        return 0xC0000;
    }
    return 0x80000;
}

/* Builds an outgoing command/payload at `out` from game state `state` using mode `type` (0..9); returns whether out[0] is nonzero. */
s32 func_020300e8(void *state, u32 type, void *out) {
void MI_CpuCopy8(void *,void *,s32);
void func_0203181c(s32,void *);
void Wfc_HashFriendConnectionCode(s32,void *);
switch(type) {
case 2:state+=0x100;
case 1:state+=0x100;
case 0:M2C_FIELD(out,u8 *,0)=(u32)(M2C_FIELD(state,u8 *,0xE6)<<30)>>30;MI_CpuCopy8(state+0x80,out+2,0x50);break;
case 5:state+=0x100;
case 4:state+=0x100;
case 3:M2C_FIELD(out,u8 *,0)=1;MI_CpuCopy8(state+0xD1,out+2,0x14);M2C_FIELD(out,u8 *,0x16)=0;break;
case 6:M2C_FIELD(out,u8 *,0)=2;func_0203181c(M2C_FIELD(state,u8 *,0xD13)*0xC0+(s32)(state+0x47C),out+2);break;
case 7:M2C_FIELD(out,u8 *,0)=2;Wfc_HashFriendConnectionCode(M2C_FIELD(state,u8 *,0xD13)*0xC0+(s32)(state+0x47C),out+2);break;
case 8:case 9:break;
}return M2C_FIELD(out,u8 *,0)!=0;
}

/* Drive one step of the session state the pointer addresses: let Wfc_UpdateSession
 * run a session that is still starting, abort the HTTP matchmaking session once
 * it has been opened, and start a new match once the network has gone down.
 * Returns 1 when the session has ended (state 0 or 18), 0 while it continues. */
s32 Wfc_AdvanceSessionState(s32 stateAddress) {
    s32 Wfc_UpdateSession(void); void Wfc_AbortNetworkSession(void); void Wfc_ReleaseNetwork(void); s32 Wfc_IsNetworkDown(void);
    u8 *state=(u8 *)stateAddress;
    u32 current=*state;
    if(current<=WFC_SESSION_STATE_MATCHMAKING) {
        current=Wfc_UpdateSession();
        if(current==1) {*state=WFC_SESSION_STATE_NONE; return 1;}
        if(current==-1) {*state=WFC_SESSION_STATE_ENDED;return 1;}
    } else if(current==WFC_SESSION_STATE_HTTP) {
        Wfc_AbortNetworkSession();Wfc_ReleaseNetwork();*state=WFC_SESSION_STATE_LINKED;
    } else if(current<WFC_SESSION_STATE_ENDED) {
        current=Wfc_IsNetworkDown(); if(current==1) *state=WFC_SESSION_STATE_MATCHMAKING;
    }
    return 0;
}

/* Drives the WFC session one step in whatever state it is in: releases a session
 * that has only just started, begins the wireless operation once it is ready,
 * runs the connect, link-wait and linked steps, and records result code 0 when
 * the session failed.  Returns 1 when the session is gone, -1 when it failed and
 * 0 while it is still running. */
s32 Wfc_UpdateSession(void) {
    void Wfc_ReleaseSession(void);
    void WFC_StartWirelessStep(void);
    void WFC_ProcessConnectStep(void);
    void WFC_ProcessLinkStep(void);
    void WFC_ProcessLinkState(void);
    u32 Wfc_GetLinkState(void);
    switch (Wfc_GetLinkState()) {
    case WFC_SESSION_STATE_NONE:
        return 1;
    case WFC_SESSION_STATE_STARTED:
        Wfc_ReleaseSession();
        break;
    case WFC_SESSION_STATE_READY:
        WFC_StartWirelessStep();
        break;
    case WFC_SESSION_STATE_CONNECTING:
        WFC_ProcessConnectStep();
        break;
    case WFC_SESSION_STATE_LINKING:
        WFC_ProcessLinkStep();
        break;
    case WFC_SESSION_STATE_LINKED:
        WFC_ProcessLinkState();
        break;
    case WFC_SESSION_STATE_ERROR:
        Wfc_SetResultCode(0);
        return -1;
    }
    return 0;
}

/* Whether the network stack is down: nothing is being closed and shutting it
 * down reports success (or that it was not up in the first place). */
s32 Wfc_IsNetworkDown(void) {
    s32 NetworkPollClosing(void);
    s32 ghiShutdown(void);
    s32 status;

    if (NetworkPollClosing() != 0) return 0;
    status = ghiShutdown();
    return status == 0 || status == WFC_NET_ALREADY_DOWN;
}

/* The waiting step that follows the finished friend connection (WFC_STEP_DONE at
 * WFC_CONTROL_STEP_STATE): advance the underlying WFC session and, once it has
 * ended, move on to WFC_SESSION_STATE_ENDED; otherwise stay at WFC_STEP_DONE. */
s32 Wfc_StepWait(void) {
    s32 Wfc_AdvanceSessionState(s32);
    if (Wfc_AdvanceSessionState((s32)(Wfc_GetWorkBlock(WFC_WORK_CONTROL) + WFC_CONTROL_STEP_STATE)) == 1) {
        return WFC_SESSION_STATE_ENDED;
    }
    return WFC_STEP_DONE;
}

