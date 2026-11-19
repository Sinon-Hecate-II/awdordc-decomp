/* 27 functions from 0x02030348 to 0x02031290 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"

s32 func_02030348(void){void *Wfc_GetWorkBlock(s32);s32 func_0202f57c(void);s32 func_02030400(void *);void *p; s32 r;p=Wfc_GetWorkBlock(1);r=func_0202f57c();if(r<4)return func_02030398(r);else if(r<5)return func_020303dc();else if(r==5)return func_020303e4(p);else return func_02030400(p);}

s32 func_02030398(u32 a){switch(a){case 1:return -9;case 0:return -10;case 2:return -8;case 3:return -7;default:return 0;}}

s32 func_020303dc(void) {
    return -6;
}

s32 func_020303e4(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xB) == 0) {
        return 0xFFFF3C4D;
    }
    return 0xFFFF3865;
}

s32 func_02030400(void *a){s32 r;u8 t=M2C_FIELD(a,u8 *,0x16);if(t<10){t=M2C_FIELD(a,u8 *,0x14);if(t==3)r=0xffff3864-M2C_FIELD(a,u8 *,0x15);else if(t==4)r=-0xc800-M2C_FIELD(a,u8 *,0x15);else r=0xffff379c-M2C_FIELD(a,u8 *,0x15);}else if(t<13)r=0xffff34e0-M2C_FIELD(a,u8 *,0x15);else {r=M2C_FIELD(a,s32 *,0x10);if(r==0)r=0xffff3cb0-M2C_FIELD(a,u8 *,0x15);else if(r==-1)r=0xffff347c-M2C_FIELD(a,u8 *,0x15);else if(r==-2)r=0xffff3418-M2C_FIELD(a,u8 *,0x15);else if(r==-3)r=0xffff33b4-M2C_FIELD(a,u8 *,0x15);else if(r==-4)r=0xffff30f8-M2C_FIELD(a,u8 *,0x15);else if(r==-5)r=0xffff3094-M2C_FIELD(a,u8 *,0x15);else if(r==-6){r=0xffff3030-M2C_FIELD(a,u8 *,0x15);return r;}}return r;}

/* Rebuilds the WFC friend-list row table for one source: the save slots (0),
 * the connected friend records (1) or the FREESPOT configuration (2).  Returns
 * the number of rows the table now holds. */
s32 Wfc_BuildFriendEntries(s32 source) {
    void *Wfc_GetWorkBlock(s32);
    void CpuFill(s32, void *, s32);
    s32 Wfc_BuildFriendCodeEntries(void *);
    s32 Wfc_MarkRecordsToSend();
    s32 Wfc_FindFirstRecordToSend(void *);
    s32 Wfc_BuildFreespotEntries(void *);
    u8 *state = Wfc_GetWorkBlock(WFC_WORK_FRIENDS);
    switch (source) {
    case 0:
        CpuFill(0, state + WFC_STATE_ENTRIES, WFC_ENTRY_TABLE_SIZE);
        state[WFC_STATE_ENTRY_COUNT] = Wfc_BuildFriendCodeEntries(state);
        break;
    case 1:
        state[WFC_STATE_ENTRY_COUNT] = Wfc_MarkRecordsToSend(state);
        state[WFC_STATE_WORK_INDEX] = Wfc_FindFirstRecordToSend(state);
        break;
    case 2:
        CpuFill(0, state + WFC_STATE_ENTRIES, WFC_ENTRY_TABLE_SIZE);
        state[WFC_STATE_WORK_INDEX] = 0;
        state[WFC_STATE_ENTRY_COUNT] = Wfc_BuildFreespotEntries(state);
        break;
    }
    return state[WFC_STATE_ENTRY_COUNT];
}

s32 Wfc_MatchFreespotCode(u8 *a){void *Wfc_GetWorkBlock(s32);s32 StringCompareN(void *,void *,s32);extern M2C_UNK data_020ea84c;u32 v=(u32)(M2C_FIELD(Wfc_GetWorkBlock(16),u8 *,0xd0c)<<28)>>28;if(v==0||v==6){if(!StringCompareN(a+12,&data_020ea84c,8))return 8;}return 0;}

s32 Wfc_BuildFriendCodeEntries(void *a){u8 func_02030780(void *);void MI_CpuCopy8(void *,void *,s32);extern M2C_UNK data_020ea84c;u8 *p=(u8 *)a+0x300;u8 n=func_02030780(a);u32 v;p+=n*36;v=(u32)(M2C_FIELD(a,u8 *,0xd0c)<<28)>>28;if(v==0||v==6){MI_CpuCopy8(&data_020ea84c,p+4,8);p[3]=8;p[1]=8;n++;}return n;}

/* Build the friend-list rows of the FREESPOT connection: after the rows of the
 * shared friend code (func_02030780), append one row per enabled connection mode
 * - 6 = Wayport2, 9 = NINTENDOWFC, 10 = the game's own id - storing the mode's
 * code in the row.  Mode 0 of WFC_STATE_FLAGS builds all three. */
s32 Wfc_BuildFreespotEntries(void *a){
u8 func_02030780(void *);void MI_CpuCopy8(void *,void *,s32);
extern M2C_UNK data_020fb224,data_020ea844,data_020ea854;
u8 rows;u8 *entry;u32 mode;
entry=(u8*)a+WFC_STATE_ENTRIES;rows=func_02030780(a);
entry+=rows*WFC_ENTRY_STRIDE;
mode=(u32)(M2C_FIELD(a,u8 *,WFC_STATE_FLAGS)<<28)>>28;
if(mode==0||mode==4){MI_CpuCopy8(&data_020fb224,entry+WFC_ENTRY_CODE,8);entry[WFC_ENTRY_CODE_LEN]=8;entry[WFC_ENTRY_ID]=6;rows++;entry+=WFC_ENTRY_STRIDE;}
mode=(u32)(M2C_FIELD(a,u8 *,WFC_STATE_FLAGS)<<28)>>28;
if(mode==0||mode==7){MI_CpuCopy8(&data_020ea844,entry+WFC_ENTRY_CODE,8);entry[WFC_ENTRY_CODE_LEN]=8;entry[WFC_ENTRY_ID]=9;rows++;entry+=WFC_ENTRY_STRIDE;}
mode=(u32)(M2C_FIELD(a,u8 *,WFC_STATE_FLAGS)<<28)>>28;
if(mode==0||mode==8){MI_CpuCopy8(&data_020ea854,entry+WFC_ENTRY_CODE,11);entry[WFC_ENTRY_CODE_LEN]=11;entry[WFC_ENTRY_ID]=10;rows++;}
return rows;
}

u8 func_02030780(void *arg0) {
    u8 *base;
    u8 idx;
    void *ip;
    u8 result;
    u8 cfg;
    u8 count;
    u8 count2;
    u8 found;
    u8 found2;
    u8 temp;
    u8 temp2;
    u32 t;

    base = (u8 *)arg0;
    idx = 0;
    ip = (u8 *)arg0 + 0x300;
    result = 0;
    t = ((u8 *)arg0)[0xD0C];
    t = t << 28;
    t = t >> 28;
    cfg = (u8)t;

    do {
        if (cfg != 0 && cfg != (u8)(idx + 1)) goto done;
        if (base[0xE7] != 0xFF) {
            count = 0;
            do {
                temp = base[count + 0x40];
                if (temp == 0) break;
                ((u8 *)ip)[count + 4] = temp;
                count++;
            } while (count < 0x20);
            if (count == 0) found = 0;
            else {
                ((u8 *)ip)[3] = count;
                ((s8 *)ip)[1] = (s8)idx;
                found = 1;
            }
            if (found) {
                result++;
                ip = (u8 *)ip + 0x24;
            }
            if (base[0xE7] == 1) {
                count2 = 0;
                do {
                    temp2 = base[count2 + 0x60];
                    if (temp2 == 0) break;
                    ((u8 *)ip)[count2 + 4] = temp2;
                    count2++;
                } while (count2 < 0x20);
                if (count2 == 0) found2 = 0;
                else {
                    ((u8 *)ip)[3] = count2;
                    ((s8 *)ip)[1] = (s8)(idx + 3);
                    found2 = 1;
                }
                if (found2) {
                    result++;
                    ip = (u8 *)ip + 0x24;
                }
            }
        }
        idx++;
        base += 0x100;
    } while (idx < 3);

done:
    return result;
}

#pragma opt_strength_reduction off
/* Marks the friend records that still have to be sent for their current friend: a
 * record whose result is pending and whose friend id differs from the one stored
 * in its result entry loses its sent mark, every other record keeps it.  Returns
 * the number of records to send. */
s32 Wfc_MarkRecordsToSend(void *friends) {
    s32 i;
    u8 count;
    u8 *flags;
    void *record;

    count = 0;
    i = 0;
    if ((s32) M2C_FIELD(friends, u8 *, WFC_STATE_RECORD_COUNT) > 0) {
        record = friends;
        flags = (u8 *) friends + WFC_STATE_RECORD_FLAGS;
        do {
            if ((M2C_FIELD((u8 *) friends + i * 4, u8 *, WFC_STATE_RECORD_RESULT) == 0) && ((M2C_FIELD(record, u16 *, WFC_STATE_RECORDS + WFC_RECORD_FRIEND_ID) - 1) != ((u32) (*flags << 0x19) >> 0x19))) {
                *flags &= ~WFC_STATE_RECORD_SENT;
                count++;
            } else {
                *flags |= WFC_STATE_RECORD_SENT;
            }
            i++;
            flags += 4;
            record = (u8 *) record + WFC_RECORD_STRIDE;
        } while (i < (s32) M2C_FIELD(friends, u8 *, WFC_STATE_RECORD_COUNT));
    }
    return count;
}
#pragma opt_strength_reduction on
s32 Wfc_FindFirstRecordToSend(void *a) {
 u8 n;u8 i;u8 r;
 n=M2C_FIELD(a,u8 *,0xd12);r=0;i=0;
 if((u32)n>(u32)i) {
loop:
 if(((u32)(M2C_FIELD(a+i*4,u8 *,0x447)<<24)>>31)==0) r=i;
 else {i++;if((u32)i<n)goto loop;}
 }
 return r;
}

/* Chooses the next result code based on the current mode of the shared state. */
u8 Wfc_StepLink(void) {
    M2C_UNK WFC_ProcessConnectStep();
    M2C_UNK WFC_ProcessLinkStep();
    M2C_UNK WFC_ProcessLinkState();
    u32 Wfc_GetLinkState();
    void *Wfc_GetWorkBlock(M2C_UNK);
    M2C_UNK Wfc_SetResultCode(M2C_UNK);
    M2C_UNK Wfc_SendConnectionMessage(u8);
    u32 mode;
    u8 result;
    void *state;

    state = Wfc_GetWorkBlock(0x10);
    result = 9;
    mode = Wfc_GetLinkState();
    switch (mode) {
    default:
        break;
    case 3:
        result = M2C_FIELD(state, u8 *, 0xD0E);
        if (((u32) (M2C_FIELD(state, u8 *, 0xD0C) << 0x18) >> 0x1E) == 1) {
            result = 7;
            M2C_FIELD((state + (M2C_FIELD(state, u8 *, 0xD13) * 4)), s8 *, 0x444) = 0;
        } else if (((u32) result >= 3U) && ((u32) result <= 5U)) {
            Wfc_SendConnectionMessage(result);
        }
        break;
    case 6:
        WFC_ProcessConnectStep();
        break;
    case 9:
        WFC_ProcessLinkStep();
        break;
    case 12:
        WFC_ProcessLinkState();
        Wfc_SetResultCode(4);
        result = 0x11;
        break;
    case 11:
        Wfc_SetResultCode(0);
        result = 0x11;
        break;
    }
    return result;
}

/* Drives the WFC friend connection one step: asks for the chosen friend's code,
 * sends the friend records and the friend-list entries, and while the WFC link
 * is up hands each friend record whose result arrived over to the link step.
 * Returns the session state to continue in. */
s32 Wfc_StepSession(void) {
    void *Wfc_GetWorkBlock(s32);
    s32 Wfc_GetSessionState(void);
    u32 Wfc_GetLinkState(void);
    s32 Wfc_StartFriendCodeMessage(void *);
    s32 Wfc_StepFriendCodeMessage(void *);
    s32 Wfc_SendFriendRecords(void *);
    s32 Wfc_SendFriendEntries(void *);
    s32 Wfc_StepFriendResults(void *, s32);
    void *friends;
    s32 state;
    u32 link;

    friends = Wfc_GetWorkBlock(WFC_WORK_FRIENDS);
    state = Wfc_GetSessionState();
    link = Wfc_GetLinkState();
    if (state == WFC_STEP_FRIEND_CONNECT && link == 3) {
        state = Wfc_StartFriendCodeMessage(friends);
    } else if (state == WFC_STEP_FRIEND_RESULTS) {
        state = Wfc_StepFriendResults(friends, state);
    } else if (link == 3 || link == 6) {
        state = Wfc_StepFriendResults(friends, state);
        if (state != WFC_STEP_LINK) {
            if (state == WFC_STEP_FRIEND_CODE) {
                state = Wfc_StepFriendCodeMessage(friends);
            } else if (state == WFC_STEP_FRIEND_RECORDS) {
                state = Wfc_SendFriendRecords(friends);
            } else if (state == WFC_STEP_FRIEND_ENTRIES) {
                state = Wfc_SendFriendEntries(friends);
            }
        }
    }
    return state;
}

void Wfc_MarkFriendId(u32 a){void *Wfc_GetWorkBlock(s32);u8 *p=Wfc_GetWorkBlock(16);u32 v;p+=0xd00;if(a>13)a=13;v=M2C_FIELD(p,u16 *,22);a--;M2C_FIELD(p,u16 *,22)=v|(1<<a);}

s8 func_02030b30(s32 a) {
 void *Wfc_GetWorkBlock(s32);
 u16 mask=M2C_FIELD(Wfc_GetWorkBlock(16),u16 *,0xd16);
 u8 i,n;
 if(!mask)return -1;
 i=0;n=0;
 do {if(mask&(1<<i)){if(n==a)return (s8)i;n++;}i++;}while((u32)i<13U);
 return -1;
}

/* Friend-connection states 3..5: restarts the timeout and submits one message to
 * the WFC engine (Wfc_SubmitMessage) - state 3 the selected friend's code, state 4
 * the next friend record (its code and entry count minus one), state 5 the
 * next friend-list row.  data_020ea758 is the empty sender code, so these
 * messages carry no code of their own. */
s32 Wfc_SendConnectionMessage(u8 mode) {
    void *Wfc_GetWorkBlock(s32);
    u64 GetSystemTick(void);
    void Wfc_SubmitMessage(s32, s32, s32, s32);
    extern u8 data_020ea758[], data_020ea760[];
    void *state;
    s32 offset;

    state = Wfc_GetWorkBlock(16);
    switch (mode) {
    case 3:
        M2C_FIELD(state, u64 *, WFC_STATE_TIMER) = GetSystemTick();
        Wfc_SubmitMessage((s32) data_020ea758, (s32) data_020ea760, M2C_FIELD(state, s8 *, WFC_STATE_FRIEND_ID), 0x200000);
        break;
    case 4:
        M2C_FIELD(state, u64 *, WFC_STATE_TIMER) = GetSystemTick();
        offset = (s16) M2C_FIELD(state, u8 *, WFC_STATE_WORK_INDEX) * (s16) WFC_RECORD_STRIDE;
        Wfc_SubmitMessage((s32) ((u8 *) state + 0x474 + offset), (s32) ((u8 *) state + 0x47C + offset),
                      M2C_FIELD((u8 *) state + offset, u16 *, 0x4A6) - 1, 0x300000);
        break;
    case 5:
        M2C_FIELD(state, u64 *, WFC_STATE_TIMER) = GetSystemTick();
        Wfc_SubmitMessage((s32) data_020ea758,
                      (s32) ((u8 *) state + WFC_STATE_ENTRIES + WFC_ENTRY_CODE
                             + M2C_FIELD(state, u8 *, WFC_STATE_WORK_INDEX) * WFC_ENTRY_STRIDE),
                      M2C_FIELD(state, s8 *, WFC_STATE_FRIEND_ID), 0x300000);
        break;
    }
}

s32 Wfc_StartFriendCodeMessage(void *a) {
 u64 GetSystemTick(void);
 void Wfc_SubmitMessage(s32,s32,s32,s32);
 extern u8 data_020ea758[],data_020ea760[];
 M2C_FIELD(a,u64 *,0xcb0)=GetSystemTick();
 M2C_FIELD(a,s8 *,0xd11)=0;
 M2C_FIELD(a,u64 *,0xcb0)=GetSystemTick();
 Wfc_SubmitMessage((s32)data_020ea758,(s32)data_020ea760,M2C_FIELD(a,s8 *,0xd11),0x200000);
 return 3;
}

/* WFC friend-connection state 3: waits for the selected friend's code.  Every
 * WFC_FRIEND_CODE_WAIT_MS it moves on to the next friend id and resends the
 * empty-code request; when the ids run out it asks Wfc_NextFriendStep for the
 * next state.  Returns 3 (stay in this state). */
s32 Wfc_StepFriendCodeMessage(void *state) {
 u64 GetSystemTick(void);
 void Wfc_SubmitMessage(s32,s32,s32,s32);
 s32 Wfc_NextFriendStep(void *,s32);
 u64 U64Divide(u64,u64);
 extern u8 data_020ea758[],data_020ea760[];
 if(U64Divide((GetSystemTick()-M2C_FIELD(state,u64 *,WFC_STATE_TIMER))<<6,(u64)TICKS_TO_MS_DIVISOR)>=(u64)WFC_FRIEND_CODE_WAIT_MS){
 M2C_FIELD(state,s8 *,WFC_STATE_FRIEND_ID)+=2;
 if(M2C_FIELD(state,s8 *,WFC_STATE_FRIEND_ID)>=WFC_FRIEND_ID_COUNT)return Wfc_NextFriendStep(state,3);
 M2C_FIELD(state,u64 *,WFC_STATE_TIMER)=GetSystemTick();
 Wfc_SubmitMessage((s32)data_020ea758,(s32)data_020ea760,M2C_FIELD(state,s8 *,WFC_STATE_FRIEND_ID),0x200000);
 }
 return 3;
}

s32 Wfc_NextFriendPass(void *a) {
 u8 t;
 M2C_FIELD(a,u8 *,0xd15)=0;
 t=M2C_FIELD(a,u8 *,0xd0b);
 M2C_FIELD(a,u8 *,0xd0b)=(t&~0xf0)|((u32)((u8)(((u32)(t<<24)>>28)+1)<<28)>>24);
 Wfc_BuildFriendEntries(0);
 M2C_FIELD(a,s8 *,0xd11)=1;
 return 3;
}

/* WFC friend-connection state 4: sends the friend records one at a time.  A
 * record is sent once its slot is marked (bit 7 of its flag byte) or the send
 * times out, walking WFC_STATE_WORK_INDEX forward; when every record is done it
 * asks Wfc_NextFriendStep for the next state.  Each record lives at
 * WFC_STATE_RECORDS + index*WFC_RECORD_STRIDE and the code at +0xC is sent with
 * the u16 at +0x36 (minus one) as the entry count.  Returns the state to use. */
s32 Wfc_SendFriendRecords(void *state) {
void Wfc_SubmitMessage(s32,s32,s32,s32);u64 GetSystemTick(void);u64 U64Divide(u64,u64);s32 offset;
if(U64Divide((GetSystemTick()-M2C_FIELD(state,u64 *,WFC_STATE_TIMER))<<6,0x82eaULL)>=150ULL || (u32)(M2C_FIELD(state+M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)*4,u8 *,WFC_STATE_RECORD_FLAGS)<<24)>>31 ==1){
M2C_FIELD(state+WFC_STATE_RECORD_FLAGS,u8 *,M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)*4)|=128;
while(M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)<M2C_FIELD(state,u8 *,WFC_STATE_RECORD_COUNT)){
if(!((u32)(M2C_FIELD(state+M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)*4,u8 *,WFC_STATE_RECORD_FLAGS)<<24)>>31))break;
M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)++;
}
if(M2C_FIELD(state,u8 *,WFC_STATE_RECORD_COUNT)<=M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)){M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)=0;return Wfc_NextFriendStep(state,4);}
M2C_FIELD(state,u64 *,WFC_STATE_TIMER)=GetSystemTick();
offset=(s16)M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)*(s16)WFC_RECORD_STRIDE;
Wfc_SubmitMessage((s32)(state+0x474+offset),(s32)(state+0x47c+offset),M2C_FIELD(state+offset,u16 *,0x4a6)-1,0x300000);
}return 4;}

/* WFC friend-connection state 5: sends the friend-list entries one at a time,
   clearing each entry's mark as it goes and advancing WFC_STATE_WORK_INDEX; at the
   end of the list it picks the next friend with func_02030b30.  When no friend is
   left it asks Wfc_NextFriendStep for the next state.  Returns the state to use. */
s32 Wfc_SendFriendEntries(void *state){
void Wfc_SubmitMessage(s32,s32,s32,s32);u64 GetSystemTick(void);u64 U64Divide(u64,u64);extern u8 data_020ea758[];
if(U64Divide((GetSystemTick()-M2C_FIELD(state,u64 *,WFC_STATE_TIMER))<<6,0x82eaULL)>=150ULL || (u32)(M2C_FIELD(state+M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)*WFC_ENTRY_STRIDE,u8 *,WFC_STATE_ENTRIES+WFC_ENTRY_FLAGS)<<28)>>28 ==1){
M2C_FIELD(state+WFC_STATE_ENTRIES,u8 *,(s16)M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)*(s16)WFC_ENTRY_STRIDE)&=~15;
M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)++;
if(M2C_FIELD(state,u8 *,WFC_STATE_ENTRY_COUNT)<=M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)){
M2C_FIELD(state,u8 *,WFC_STATE_CONN_RETRY)++;M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)=0;
M2C_FIELD(state,s8 *,WFC_STATE_FRIEND_ID)=func_02030b30(M2C_FIELD(state,u8 *,WFC_STATE_CONN_RETRY));
}
if(M2C_FIELD(state,s8 *,WFC_STATE_FRIEND_ID)<0){M2C_FIELD(state,u8 *,WFC_STATE_CONN_RETRY)=0;return Wfc_NextFriendStep(state,5);}
M2C_FIELD(state,u64 *,WFC_STATE_TIMER)=GetSystemTick();
Wfc_SubmitMessage((s32)data_020ea758,(s32)(state+WFC_STATE_ENTRIES+WFC_ENTRY_CODE+M2C_FIELD(state,u8 *,WFC_STATE_WORK_INDEX)*WFC_ENTRY_STRIDE),M2C_FIELD(state,s8 *,WFC_STATE_FRIEND_ID),0x300000);
}return 5;}

/* Choose the friend-connection step that follows `finishedStep` (the friend
 * code, the friend records or the friend entries) and submit the message the
 * new step starts: the next friend's entries, the record/result collection, or
 * another pass over the friends.  Returns the step chosen. */
s32 Wfc_NextFriendStep(void *state, s32 finishedStep) {
    M2C_UNK Wfc_BuildFriendEntries(M2C_UNK);
    s32 Wfc_SelectNextFriend(void *);
    s32 Wfc_NextFriendPass(void *);
    M2C_UNK Wfc_SendConnectionMessage(u8);
    s32 step = finishedStep;
    switch (step) {
    case WFC_STEP_FRIEND_CODE:
        if (M2C_FIELD(state, u8 *, WFC_STATE_RECORD_COUNT) != 0 || M2C_FIELD(state, u16 *, WFC_STATE_FRIEND_MASK) != 0) {
            if (Wfc_BuildFriendEntries(1) != 0) {
                step = WFC_STEP_FRIEND_RECORDS;
            } else {
                step = Wfc_SelectNextFriend(state);
            }
        } else {
            /* high nibble of WFC_STATE_CONN_FLAGS: the friend passes made so far */
            if ((u32)((u32)(M2C_FIELD(state, u8 *, WFC_STATE_CONN_FLAGS) << 0x18) >> 0x1C) >= 1U) {
                step = WFC_STEP_FRIEND_RESULTS;
            } else {
                step = Wfc_NextFriendPass(state);
            }
        }
        break;
    case WFC_STEP_FRIEND_RECORDS:
        step = Wfc_SelectNextFriend(state);
        break;
    case WFC_STEP_FRIEND_ENTRIES:
        if ((u32)((u32)(M2C_FIELD(state, u8 *, WFC_STATE_CONN_FLAGS) << 0x18) >> 0x1C) >= 1U) {
            step = WFC_STEP_FRIEND_RESULTS;
        } else {
            step = Wfc_NextFriendPass(state);
        }
        break;
    }
    ((M2C_UNK(*)(M2C_UNK))Wfc_SendConnectionMessage)(step);
    return step;
}

/* Friend-connection results step: find the first friend record whose result is
 * still pending.  In the results state, report the end once every record has an
 * answer; otherwise, if that pending record's score is high enough, remember its
 * index and hand over to the link step - parking the session state first when
 * the WFC engine is not idle (WFC_ProcessConnectStep). */
s32 Wfc_StepFriendResults(void *friends, s32 state) {
    s32 WFC_ProcessConnectStep(void);
    M2C_UNK Wfc_SetResultCode(M2C_UNK);
    s32 result = state;
    u8 count;
    u8 index;

    if (result == WFC_STEP_DONE) return result;
    count = M2C_FIELD(friends, u8 *, WFC_STATE_RECORD_COUNT);
    index = 0;
    if (count > (u32)index) {
loop_next:
        if (M2C_FIELD(friends + index * 4, u8 *, WFC_STATE_RECORD_RESULT) != 0) {
            index++;
            if ((u32)index < count) goto loop_next;
        }
    }
    if (result == WFC_STEP_FRIEND_RESULTS) {
        if (count == index) {
            if (index == 0) Wfc_SetResultCode(5); else Wfc_SetResultCode(6);
            return WFC_STEP_DONE;
        }
        goto start_link;
    }
    if (count == 0) return result;
    if (count == index) return result;
    if ((u32)M2C_FIELD(friends + index * 4, u8 *, WFC_STATE_RECORD_SCORE) < WFC_MIN_CONNECT_SCORE) return result;
start_link:
    M2C_FIELD(friends, u8 *, WFC_STATE_RECORD_INDEX) = index;
    if (WFC_ProcessConnectStep() != 1) {
        M2C_FIELD(friends, s8 *, WFC_STATE_LINK_RETURN) = result;
        result = WFC_STEP_LINK;
    }
    return result;
}

s32 Wfc_SelectNextFriend(void *arg0) {
    s32 Wfc_BuildFriendEntries(M2C_UNK);
    s8 func_02030b30(M2C_UNK);
    s32 Wfc_NextFriendPass(void *);
    if ((M2C_FIELD(arg0, u16 *, 0xD16) != 0) && (Wfc_BuildFriendEntries(2) != 0)) {
        M2C_FIELD(arg0, s8 *, 0xD11) = func_02030b30(0);
        return 5;
    }
    if ((u32) ((u32) (M2C_FIELD(arg0, u8 *, 0xD0B) << 0x18) >> 0x1C) >= 1U) {
        return 6;
    }
    return Wfc_NextFriendPass(arg0);
}

void Wfc_SubmitMessage(s32 a,s32 b,s32 c,s32 d){void func_02027518(s32,s32,s32);extern M2C_UNK data_020ea860;if(c>12)c=12;func_02027518(a,b,d|M2C_FIELD(&data_020ea860,s32 *,c*4));}

/* First step of a WFC friend connection: while the session has only started,
 * rebuild the friend-list rows from the save slots and ask the WFC engine to
 * open the connection with the stored connection mode.  A connect step that
 * cannot start (status 1) or fails (status 4 and above) records result 1 and
 * finishes the connection; otherwise the friend session runs from state 2. */
s32 Wfc_StepConnect(void) {
    u32 Wfc_GetLinkState(void);
    void *Wfc_GetWorkBlock(s32);
    s32 WFC_ConnectStep(s32 *, void *);
    s32 Wfc_SetResultCode(s32);
    extern M2C_UNK Wfc_HandleConnectMessage;
    s32 request[4];
    s32 state = Wfc_GetLinkState();
    void *friends = Wfc_GetWorkBlock(WFC_WORK_FRIENDS);

    if (state == WFC_SESSION_STATE_STARTED) {
        request[0] = M2C_FIELD(friends, u8 *, WFC_STATE_CONN_MODE);
        request[1] = 0;
        request[2] = 0;
        request[3] = 0;
        Wfc_BuildFriendEntries(WFC_ENTRY_SOURCE_SAVE_SLOTS);
        state = WFC_ConnectStep(request, &Wfc_HandleConnectMessage);
        if (state == 1 || state >= 4) {
            Wfc_SetResultCode(1);
            return WFC_STEP_DONE;
        }
    } else {
        return WFC_SESSION_STATE_STARTED;
    }
    return WFC_STEP_FRIEND_CONNECT;
}

