/* 23 functions from 0x0203AEB4 to 0x0203BE54 (main), found by ds-decomp. */
#include "common.h"
#include "net_session.h"

/* Return the player slot whose profile id is `profileId`, or -1 when there is no
 * match session or no player with that id. */
s32 GetSessionPlayerSlot(s32 profileId) {
 extern M2C_UNK gMatchSessionMgr; s32 GetSessionPlayerId(s32);
 s32 slot;
 if(!M2C_FIELD(&gMatchSessionMgr,void **,MATCH_SESSION_MGR_SESSION)||!profileId)return -1;
 for(slot=0;slot<M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,MATCH_SESSION_MGR_SESSION),s32 *,MATCH_SESSION_PLAYER_COUNT);slot++) {
 if(profileId==GetSessionPlayerId(slot))return slot;
 }return -1;
}

void MatchSession_ResetThinkTimer(void) {
 extern M2C_UNK gMatchSessionMgr; u64 GetSystemTick(void);
 u64 t; void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);
 if(!p)return;
 M2C_FIELD(p,s32 *,8)=0;
 t=GetSystemTick();
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u64 *,0xC)=t;
}

/* Sends the match session's GameSpy status and location strings to the lobby;
   a status of -1 and null strings fall back to the values cached on the
   connection.  Does nothing until the NAS login has completed. */
s32 SetGpiStatus(s32 status, void *statusString, void *locationString) {
    extern M2C_UNK gMatchSessionMgr;
    s32 IsNasLoginDone(void);
    s32 gpiSetStatusInfo(void *, s32, void *, void *);
    if (!M2C_FIELD(&gMatchSessionMgr, void **, 8) || !IsNasLoginDone()) return 0;
    if (status == -1) status = M2C_FIELD(*M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), void ***, MATCH_SESSION_CONNECTION), s32 *, GPI_CONN_CACHED_STATUS);
    if (!statusString) statusString = (u8 *)*M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), void ***, MATCH_SESSION_CONNECTION) + GPI_CONN_STATUS_STRING;
    if (!locationString) locationString = (u8 *)*M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), void ***, MATCH_SESSION_CONNECTION) + GPI_CONN_LOCATION_STRING;
    return gpiSetStatusInfo(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), void **, MATCH_SESSION_CONNECTION), status, statusString, locationString);
}

/* Tell the match session that player slot `slot` changed: run its slot-changed
 * callback unless the match is running, then, when it has an info callback, read
 * the slot's player info from the session's player record and hand it over. */
void NotifyPlayerSlotChanged(s32 slot) {
 extern M2C_UNK gMatchSessionMgr; s32 GetMatchPlayerRecordInfo(void *,void *);
 u32 infoOut[132]; void *p=M2C_FIELD(&gMatchSessionMgr,void **,8); s32 status;
 if(M2C_FIELD(p,void **,MATCH_SESSION_SLOT_CB)&&M2C_FIELD(p,s32 *,MATCH_SESSION_STATUS)!=MATCH_SESSION_STATUS_RUNNING)
 M2C_FIELD(p,void (**)(s32,s32),MATCH_SESSION_SLOT_CB)(slot,M2C_FIELD(p,s32 *,MATCH_SESSION_SLOT_DATA));
 p=M2C_FIELD(&gMatchSessionMgr,void **,8);
 if(!M2C_FIELD(p,void **,MATCH_SESSION_INFO_CB))return;
 status=GetMatchPlayerRecordInfo((u8 *)M2C_FIELD(p,void **,MATCH_SESSION_PLAYERS)+slot*MATCH_SESSION_PLAYER_SIZE,infoOut+66);
 p=M2C_FIELD(&gMatchSessionMgr,void **,8);
 M2C_FIELD(p,void (**)(s32,s32,void *,s32),MATCH_SESSION_INFO_CB)(slot,status,infoOut+66,M2C_FIELD(p,s32 *,MATCH_SESSION_INFO_DATA));
}

void func_0203b088(void) {
    extern M2C_UNK gMatchSessionMgr;
    M2C_FIELD(&gMatchSessionMgr, s32 *, 8) = 0;
}

/* Paced think of the online match session: once every 300 tick units it bumps the
 * session's think counter, pumps its GameSpy connection and records the new tick;
 * returns the pump's result (nonzero tells the caller to stop this update pass). */
s32 MatchSession_Think(void) {
    extern M2C_UNK gMatchSessionMgr;
    u64 GetSystemTick(void);
    u64 U64Divide(u64, u64);
    s32 func_0204db50(void *);
    s32 result = 0;
    void *session = M2C_FIELD(&gMatchSessionMgr, void **, 8);

    if (U64Divide((GetSystemTick() - M2C_FIELD(session, u64 *, MATCH_SESSION_THINK_TICK)) << 6, 0x82EA) >= 300) {
        M2C_FIELD(session, s32 *, MATCH_SESSION_THINK_COUNT)++;
        result = func_0204db50(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), void **, MATCH_SESSION_CONNECTION));
        M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), u64 *, MATCH_SESSION_THINK_TICK) = GetSystemTick();
    }
    return result;
}

void func_0203b128(void) {
 extern M2C_UNK gMatchSessionMgr;
 if(!M2C_FIELD(&gMatchSessionMgr,void **,8))return;
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,0)=0;
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1E)=0;
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1F)=0;
}

#pragma opt_strength_reduction off
/* Match the session's local player table against the GameSpy buddy list:
 * confirm entries that are already buddies, drop stale buddies, and request
 * a buddy connection for each player whose address is still unknown. Runs as
 * one step of the session update and stops early when a request is pending. */
void SyncSessionPlayerConnections(M2C_UNK *arg0,s32 playerCount){
extern M2C_UNK gMatchSessionMgr;
s32 func_0204e184(void *,s32 *);s32 gpGetBuddyStatus(void *,s32,s32);s32 DeleteBuddyProfile(void *,s32);
u32 ReportNetError();s32 GetSessionPlayerId(s32);s32 IsPlayerRecordJoined(void *);void AssignPlayerRecordId(void *,s32);void MarkPlayerRecordJoined(void *);
s32 MatchSession_MergeDuplicatePlayer(u8 *,s32,s32);s32 gpiGetBuddyIndex(void *,s32,s32 *);s32 DropSessionPlayer(s32);
s32 GetLocalPlayerInfo(void);s32 GetPlayerRecordId(s32,s32);void FormatPlayerNasId(s32,void *,void *);
void HandlePeerConnectResult(s32,void *,s32);s32 gpiProfileSearch(void *,s32,s32,s32,s32,void *,s32,s32,void (*)(s32,void *,s32),s32);
s32 i,remoteCount,remoteIndex;u32 buddyInfo[132];u32 peerAddress[6];s32 slot,profileId;u8 *a=(u8 *)arg0;
if(!M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1e)){
ReportNetError(func_0204e184(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),&remoteCount));
#pragma opt_loop_invariants off
for(remoteIndex=0;remoteIndex<remoteCount;remoteIndex++){
ReportNetError(gpGetBuddyStatus(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),remoteIndex,(s32)buddyInfo));
for(slot=0;slot<playerCount;slot++){
if((s32)buddyInfo[0]==GetSessionPlayerId(slot)){
if(!IsPlayerRecordJoined(a+slot*12)){
AssignPlayerRecordId(a+slot*12,buddyInfo[0]);MarkPlayerRecordJoined(a+slot*12);
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1d)=1;
}break;
}}
if(slot==playerCount){
ReportNetError(DeleteBuddyProfile(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),buddyInfo[0]));
remoteCount--;remoteIndex--;
}}
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1e)=1;
}
while(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c)<playerCount){
profileId=GetSessionPlayerId(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c));
if(profileId){
if(!MatchSession_MergeDuplicatePlayer(a,M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c),profileId)){
ReportNetError(gpiGetBuddyIndex(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),profileId,&remoteIndex));
if(remoteIndex==-1)DropSessionPlayer(profileId);
}
}else{
if(GetPlayerRecordId(GetLocalPlayerInfo(),(s32)(a+M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c)*12))==-1){
FormatPlayerNasId(GetLocalPlayerInfo(),a+M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c)*12,peerAddress);
gpiProfileSearch(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),0,0,0,0,peerAddress,0,0,HandlePeerConnectResult,M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c));
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1e)=2;return;
}}
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c)++;
}
}
#pragma opt_strength_reduction reset
void func_0203b3c4(void) {
 extern M2C_UNK gMatchSessionMgr;
 void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);
 M2C_FIELD(p,void (**)(s32,u8,s32),0x2C)(0,M2C_FIELD(p,u8 *,0x1D),M2C_FIELD(p,s32 *,0x30));
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,0)=2;
}

#pragma opt_propagation off
/* Clear the record of player slot `slot` and fold that player's battle stats
 * into the record of slot `targetSlot` through the session's stats callback.
 * Does nothing while no match session is running. */
void MatchSession_ClearPlayerRecord(u8 *playerRecords, u32 slot, u32 targetSlot) {
    extern M2C_UNK gMatchSessionMgr;
    void MI_CpuFill8(void *, s32, u32);
    void *p = M2C_FIELD(&gMatchSessionMgr, void **, MATCH_SESSION_MGR_SESSION);

    if (!p) return;
    MI_CpuFill8(playerRecords + slot * 12, 0, 12);
    p = M2C_FIELD(&gMatchSessionMgr, void **, MATCH_SESSION_MGR_SESSION);
    if (M2C_FIELD(p, void (**)(u32, u32, u32), MATCH_SESSION_STATS_CB))
        M2C_FIELD(p, void (**)(u32, u32, u32), MATCH_SESSION_STATS_CB)(slot, targetSlot, M2C_FIELD(p, u32 *, MATCH_SESSION_STATS_DATA));
}
#pragma opt_propagation reset
/* Look for the player `profileId` among the session's player records before
   `slot` and merge the duplicate: the record that is already joined survives and
   the other one (with its battle stats) is folded into it, then the player list
   is marked dirty. Returns 1 when the player was found, 0 otherwise. */
s32 MatchSession_MergeDuplicatePlayer(u8 *playerRecords, s32 slot, s32 profileId) {
 extern M2C_UNK gMatchSessionMgr; s32 GetSessionPlayerId(s32); s32 IsPlayerRecordJoined(void *);
 s32 i,id;
 for(i=0;i<slot;i++) {
 id=GetSessionPlayerId(i);
 if(id&&id==profileId) {
 if(IsPlayerRecordJoined(playerRecords+slot*12)&&!IsPlayerRecordJoined(playerRecords+i*12))MatchSession_ClearPlayerRecord(playerRecords,i,slot);
 else MatchSession_ClearPlayerRecord(playerRecords,slot,i);
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_DIRTY)=1;return 1;
 }
 }return 0;
}

s32 ResolvePlayerSlot(u8 *records, s32 count, s32 profileId) {
    extern M2C_UNK gMatchSessionMgr;
    s32 GetSessionPlayerId(s32);
    s32 GetPlayerRecordType(void *);
    s32 IsPlayerRecordJoined(void *);
    void AssignPlayerRecordId(void *, s32);
    void MarkPlayerRecordJoined(void *);
    void MatchSession_ClearPlayerRecord(u8 *, u32, u32);

    s32 id, i, j;
    u32 *typeRecord;
    u8 *current;
    u8 *duplicate;
    s32 result = -1;

    i = 0;
    if (count > 0) {
        typeRecord = (u32 *)records;
        current = records;
        do {
            id = GetSessionPlayerId(i);
            if (id != 0) {
                if (id == profileId) {
                    result = i;
                }
                j = i + 1;
                if (j < count) {
                    duplicate = records + j * 12;
                    do {
                        if (id == GetSessionPlayerId(j)) {
                            if (GetPlayerRecordType(typeRecord) == 2 &&
                                GetPlayerRecordType(duplicate) == 3) {
                                AssignPlayerRecordId(current, id);
                            }
                            if (IsPlayerRecordJoined(duplicate)) {
                                MarkPlayerRecordJoined(current);
                            }
                            MatchSession_ClearPlayerRecord(records, j, i);
                            M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), u8 *, 0x1D) = 1;
                        }
                        duplicate += 12;
                    } while (++j < count);
                }
            }
            typeRecord += 3;
            current += 12;
        } while (++i < count);
    }

    return result;
}

s32 DropSessionPlayer(s32 a) {
 extern M2C_UNK gMatchSessionMgr; extern M2C_UNK data_020fc8ec;
 s32 func_0204df00(void *,s32,void *); u32 ReportNetError();
 s32 r=func_0204df00(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),a,&data_020fc8ec);
 ReportNetError(r); return r;
}

s32 FetchMatchPlayerInfo(s32 arg0,s32 arg1) {
extern M2C_UNK gMatchSessionMgr;
s32 IsNasLoginDone(void); s32 GetLocalPlayerInfo(void); s32 GetPlayerRecordId(s32,s32);
s32 gpiGetBuddyIndex(void *,s32,s32 *); s32 gpGetBuddyStatus(void *,s32,s32);
void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);
s32 b=arg1; s32 a=arg0; s32 out=0;
if(!p||!IsNasLoginDone())return 0;
a=GetPlayerRecordId(GetLocalPlayerInfo(),a);
if(a>0)if(gpiGetBuddyIndex(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),a,&out))return 0;
if(a<=0||out==-1)return 0;
return (u32)gpGetBuddyStatus(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),out,b) <= 0;
}

/* Converts a GameSpy Presence failure to a matchmaking error and returns the original result. */
u32 ReportNetError(u32 result, u32 unused, u32 detailOffset) {
    void ReportMatchSessionError(u32, u32);
    u32 status = result;
    u32 errorCode = status;

    if (status == GP_NO_ERROR) return GP_NO_ERROR;

    switch (status) {
    case GP_MEMORY_ERROR:
        errorCode = 9;
        detailOffset = errorCode - 10;
        break;
    case GP_PARAMETER_ERROR:
        errorCode = 9;
        detailOffset = errorCode - 11;
        break;
    case GP_NETWORK_ERROR:
        errorCode = 6;
        detailOffset = errorCode - 16;
        break;
    case GP_SERVER_ERROR:
        errorCode = 6;
        detailOffset = errorCode - 26;
        break;
    }

    ReportMatchSessionError(errorCode, detailOffset + NET_MATCH_STATUS_DETAIL_BASE);
    return status;
}

/* Callback for a pending GPI peer connection: matches the returned profile ids
 * to slots in the online-match session's player table, drops peers that are no
 * longer known, and marks the session ready for the next setup step. */
void HandlePeerConnectResult(s32 connection, void *result, s32 index) {
extern M2C_UNK gMatchSessionMgr;
s32 GetPlayerRecordType(void *); void MarkPlayerRecordJoined(void *); void AssignPlayerRecordId(void *,s32);
s32 MatchSession_MergeDuplicatePlayer(u8 *,s32,s32);s32 gpiGetBuddyIndex(void *,s32,s32 *);s32 DropSessionPlayer(s32);void NotifyPlayerSlotChanged(s32);
s32 peerIndex,entryOffset,slotOffset,entryBase;
if(M2C_FIELD(result,s32 *,0)==0 && M2C_FIELD(result,s32 *,4)!=0) {
slotOffset=index*MATCH_SESSION_PLAYER_SIZE;
if(GetPlayerRecordType(((u8 *)M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,MATCH_SESSION_PLAYERS)+slotOffset))!=0) {
if(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,MATCH_SESSION_STATUS)!=1)return;
peerIndex=0;if(M2C_FIELD(result,s32 *,4)>0){entryOffset=0;do {
if(MatchSession_MergeDuplicatePlayer(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,MATCH_SESSION_PLAYERS),index,M2C_FIELD((u8 *)M2C_FIELD(result,void **,0xc)+entryOffset,s32 *,0))) {
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_CURSOR)++;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_STATE)=1;
M2C_FIELD(result,s32 *,8)=0x601;
return;
}

peerIndex++;entryOffset+=0xac;
}while(peerIndex<M2C_FIELD(result,s32 *,4));}
entryOffset=0;if(M2C_FIELD(result,s32 *,4)>0){entryBase=entryOffset;do {
s32 profileId;
((u32 (*)(u32))ReportNetError)(gpiGetBuddyIndex((void *)connection,M2C_FIELD((u8 *)M2C_FIELD(result,void **,0xc)+entryBase,s32 *,0),&profileId));
if(profileId==-1)DropSessionPlayer(M2C_FIELD((u8 *)M2C_FIELD(result,void **,0xc)+entryBase,s32 *,0));
else {
AssignPlayerRecordId(((u8 *)M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,MATCH_SESSION_PLAYERS)+slotOffset),M2C_FIELD(M2C_FIELD(result,void **,0xc),s32 *,0));
MarkPlayerRecordJoined(((u8 *)M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,MATCH_SESSION_PLAYERS)+slotOffset));NotifyPlayerSlotChanged(index);
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_CURSOR)++;M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_STATE)=1;
M2C_FIELD(result,s32 *,8)=0x601;M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_DIRTY)=1;return;
}

entryOffset++;entryBase+=0xac;
}while(entryOffset<M2C_FIELD(result,s32 *,4));}
if(M2C_FIELD(result,s32 *,8)!=0x600) {M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_CURSOR)++;M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_STATE)=1;}
return;
}
}
if(M2C_FIELD(result,s32 *,0)!=0) {
if(((u32 (*)(u32))ReportNetError)(M2C_FIELD(result,s32 *,0)))return;
return;
}
if(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,MATCH_SESSION_STATUS)==1 || !GetPlayerRecordType((u8 *)M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,MATCH_SESSION_PLAYERS)+index*MATCH_SESSION_PLAYER_SIZE)){
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_CURSOR)++;M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_STATE)=1;
}
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
/* Callback for an incoming session-player message (buf): walk the online-session
   player records and, for a record whose peer name or key matches the message's
   name (+0x8e) or key (+0x97), register the peer on the connection and mark it
   joined; then remove the message's player from the session if it matched, or
   reject it otherwise. Ignores messages that are not type 0. */
void AddBuddyProfileCallback(void **conn, void *buf, s32 unused) {
    extern M2C_UNK gMatchSessionMgr;
    extern M2C_UNK data_020fc8f0;
    s32 GetPlayerRecordType(void *);
    s32 GetLocalPlayerInfo(void);
    void FormatPlayerNasId(s32, void *, void *);
    s32 StringCompare(void *, void *);
    s32 gpiAddProfile(void **, s32);
    void AssignPlayerRecordId(void *, s32);
    s32 GetPlayerRecordId(s32, s32);
    s32 StringFormatN(void *, s32, void *, ...);
    s32 ByteCompareN(void *, void *, s32);
    s32 DropSessionPlayer(s32);
    s32 gpiReleaseProfile(void **, s32);

    u8 keyText[0x1c];
    void *manager;
    void *session;
    s32 slot;
    s32 found;
    s32 recordOffset;
    s32 messagePlayerId;
    s32 self;
    u32 selfKey;

    found = 0;
    if (M2C_FIELD(buf, s32 *, 0) != 0) {
        return;
    }
    manager = &gMatchSessionMgr;
    slot = 0;
    session = M2C_FIELD(manager, void **, 8);
    if (M2C_FIELD(session, s32 *, 0x14) <= 0) {
        goto after_loop;
    }
    recordOffset = 0;

    do {
        if (GetPlayerRecordType((u8 *)M2C_FIELD(session, void **, 0x18) + recordOffset) == 1) {
            self = GetLocalPlayerInfo();
            FormatPlayerNasId(self, (u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, 0x18) + recordOffset, keyText + 5);
            if (StringCompare(keyText + 5, (u8 *)buf + 0x8e) == 0) {
                gpiAddProfile(conn, M2C_FIELD(buf, s32 *, 4));
                AssignPlayerRecordId((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, 0x18) + recordOffset, M2C_FIELD(buf, s32 *, 4));
                found = 1;
            }
        } else {
            if (GetPlayerRecordType((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, 0x18) + recordOffset) == 3 ||
                GetPlayerRecordType((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, 0x18) + recordOffset) == 2) {
                self = GetLocalPlayerInfo();
                selfKey = M2C_FIELD(self, u32 *, 0x24);
                StringFormatN(keyText, 5, &data_020fc8f0,
                              (selfKey >> 24) & 0xff,
                              (selfKey >> 16) & 0xff,
                              (selfKey >> 8) & 0xff,
                              selfKey & 0xff);
                messagePlayerId = M2C_FIELD(buf, s32 *, 4);
                self = GetLocalPlayerInfo();
                if (messagePlayerId == GetPlayerRecordId(self, (s32)((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, 0x18) + recordOffset))) {
                    if (ByteCompareN(keyText, (u8 *)buf + 0x97, 4) == 0) {
                        gpiAddProfile(conn, messagePlayerId);
                        found = 1;
                    }
                }
            }
        }
        session = M2C_FIELD(manager, void **, 8);
        recordOffset += 0xc;
        slot++;
    } while (slot < M2C_FIELD(session, s32 *, 0x14));

after_loop:
    if (found) {
        DropSessionPlayer(M2C_FIELD(buf, s32 *, 4));
    } else {
        gpiReleaseProfile(conn, M2C_FIELD(buf, s32 *, 4));
    }
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
#pragma opt_propagation reset

/* gpiGetInfo callback for one player's info: walks the match session's player
 * records and fills in the id of each record that is still unassigned, matching
 * it by formatted NAS id (type-1 records) or by player id (type-2/3 records).
 * When a record was filled, resolves the player's slot and marks the session
 * dirty. Messages with a nonzero status are ignored. */
void HandleGpiPlayerInfo(s32 unused, void *message) {
    extern M2C_UNK gMatchSessionMgr;
    s32 GetPlayerRecordType(void *);
    s32 GetLocalPlayerInfo(void);
    void FormatPlayerNasId(s32, void *, void *);
    s32 StringCompare(void *, void *);
    void AssignPlayerRecordId(void *, s32);
    void MarkPlayerRecordJoined(void *);
    s32 GetPlayerRecordId(s32, s32);
    s32 IsPlayerRecordJoined(void *);
    s32 ResolvePlayerSlot(u8 *, s32, s32);
    void NotifyPlayerSlotChanged(s32);

    u8 nasIdText[0x18];
    void *manager;
    void *nasId;
    s32 slot;
    s32 claimed;
    s32 alreadyJoined;
    s32 recordOffset;
    s32 one;
    s32 temp, result;

    claimed = 0;
    alreadyJoined = 0;
    if (M2C_FIELD(message, s32 *, GPI_INFO_STATUS) != 0) {
        return;
    }
    manager = &gMatchSessionMgr;
    slot = 0;
    if (M2C_FIELD(M2C_FIELD(manager, void **, 8), s32 *, MATCH_SESSION_PLAYER_COUNT) <= 0) {
        goto after_loop;
    }
    recordOffset = 0;
    one = 1;

    do {
        nasId = nasIdText;
        temp = GetPlayerRecordType((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, MATCH_SESSION_PLAYERS) + recordOffset);
        if (temp == 1) {
            temp = GetLocalPlayerInfo();
            FormatPlayerNasId(temp, (u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, MATCH_SESSION_PLAYERS) + recordOffset, nasId);
            if (StringCompare(nasId, (u8 *)message + GPI_INFO_NAS_ID) == 0) {
                AssignPlayerRecordId((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, MATCH_SESSION_PLAYERS) + recordOffset, M2C_FIELD(message, s32 *, GPI_INFO_PLAYER_ID));
                MarkPlayerRecordJoined((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, MATCH_SESSION_PLAYERS) + recordOffset);
                claimed = one;
            }
        } else {
            if (GetPlayerRecordType((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, MATCH_SESSION_PLAYERS) + recordOffset) == 3 ||
                GetPlayerRecordType((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, MATCH_SESSION_PLAYERS) + recordOffset) == 2) {
                temp = GetLocalPlayerInfo();
                result = GetPlayerRecordId(temp, (s32)((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, MATCH_SESSION_PLAYERS) + recordOffset));
                if (M2C_FIELD(message, s32 *, GPI_INFO_PLAYER_ID) == result) {
                    if (IsPlayerRecordJoined((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, MATCH_SESSION_PLAYERS) + recordOffset) == 1) {
                        alreadyJoined = 1;
                    } else {
                        AssignPlayerRecordId((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, MATCH_SESSION_PLAYERS) + recordOffset, M2C_FIELD(message, s32 *, GPI_INFO_PLAYER_ID));
                        MarkPlayerRecordJoined((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, MATCH_SESSION_PLAYERS) + recordOffset);
                        claimed = 1;
                    }
                }
            }
        }
        slot++;
        recordOffset += MATCH_SESSION_PLAYER_SIZE;
    } while (slot < M2C_FIELD(M2C_FIELD(manager, void **, 8), s32 *, MATCH_SESSION_PLAYER_COUNT));

after_loop:
    if (claimed == 0) {
        return;
    }

    result = ResolvePlayerSlot((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, MATCH_SESSION_PLAYERS),
                        M2C_FIELD(M2C_FIELD(manager, void **, 8), s32 *, MATCH_SESSION_PLAYER_COUNT),
                        M2C_FIELD(message, s32 *, GPI_INFO_PLAYER_ID));
    if (alreadyJoined == 0) {
        NotifyPlayerSlotChanged(result);
    }
    M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), u8 *, MATCH_SESSION_DIRTY) = 1;
}

s32 func_0203bcf8(void) {
 extern M2C_UNK gMatchSessionMgr;
 return M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,0x20);
}

void func_0203bd0c(void) {
    M2C_UNK func_0205d8f4();
    extern M2C_UNK gConnectionMgr;
    if (M2C_FIELD(&gConnectionMgr, s32 *, 0x10) != 0) {
        M2C_FIELD(&gConnectionMgr, s32 *, 0xC) = 1;
        return;
    }
    func_0205d8f4();
}

s32 func_0203bd34(void) {
    s32 CanLeaveOnlineSession();
    M2C_UNK DisconnectConnection();
    if (CanLeaveOnlineSession() == 0) {
        return 0;
    }
    DisconnectConnection();
    return 1;
}

/* Nonzero when the online match session can be left cleanly: no network error,
 * a connection is open, the network session is online (NET_STATE_SESSION) and no
 * connection change is in progress (CONN_SESSION_BUSY). */
s32 CanLeaveOnlineSession(void) {
    s32 HasNetError();
    s32 GetNetSessionState();
    void *GetConnection();
    if (HasNetError() != 0) {
        return 0;
    }
    if ((GetConnection() == NULL) || (GetNetSessionState() != NET_STATE_SESSION) || (M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_BUSY) != 0)) {
        return 0;
    }
    return 1;
}

/* Ask for the hosted match to start once its online session is up: if the
 * connection is already in the match state, fix the session capacity at the
 * current player count, publish the session status and run the callback;
 * otherwise remember the callback and let the connection update start the
 * match when it reaches CONN_STATE_MATCH. */
s32 RequestMatchStart(void (*callback)(s32), s32 data) {
    s32 HasNetError(void);
    void *GetConnection(void);
    s32 GetNetSessionState(void);
    void ReportGpiSessionStatus(void);
    void *connection;

    if (HasNetError() != 0 || !GetConnection() ||
        M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MODE) != 2 ||
        (GetNetSessionState() != NET_STATE_STARTING && GetNetSessionState() != NET_STATE_MATCH)) {
        return 0;
    }
    if (M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_STATE) == CONN_STATE_MATCH) {
        connection = GetConnection();
        M2C_FIELD(connection, u8 *, CONN_SESSION_CAPACITY) = M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_PLAYER_COUNT);
        ReportGpiSessionStatus();
        if (callback) callback(data);
    } else {
        M2C_FIELD(GetConnection(), void (**)(s32), CONN_SESSION_MATCH_START_CALLBACK) = callback;
        M2C_FIELD(GetConnection(), s32 *, CONN_SESSION_MATCH_START_DATA) = data;
        M2C_FIELD(GetConnection(), u8 *, CONN_SESSION_MATCH_START_PENDING) = 1;
    }
    return 1;
}

