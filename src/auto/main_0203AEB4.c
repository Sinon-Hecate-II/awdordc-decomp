/* 23 functions from 0x0203AEB4 to 0x0203BE54 (main), found by ds-decomp. */
#include "common.h"

s32 func_0203aeb4(s32 a) {
 extern M2C_UNK gMatchSessionMgr; s32 GetSessionPlayerId(s32);
 s32 i;
 if(!M2C_FIELD(&gMatchSessionMgr,void **,8)||!a)return -1;
 for(i=0;i<M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,0x14);i++) {
 if(a==GetSessionPlayerId(i))return i;
 }return -1;
}

void func_0203af18(void) {
 extern M2C_UNK gMatchSessionMgr; u64 GetSystemTick(void);
 u64 t; void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);
 if(!p)return;
 M2C_FIELD(p,s32 *,8)=0;
 t=GetSystemTick();
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u64 *,0xC)=t;
}

s32 SetGpiStatus(s32 a,void *b,void *c) {
 extern M2C_UNK gMatchSessionMgr;
 s32 func_0203a660(void); s32 gpiSetStatusInfo(void *,s32,void *,void *);
 if(!M2C_FIELD(&gMatchSessionMgr,void **,8)||!func_0203a660())return 0;
 if(a==-1)a=M2C_FIELD(*M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void ***,4),s32 *,0x214);
 if(!b)b=(u8 *)*M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void ***,4)+0x218;
 if(!c)c=(u8 *)*M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void ***,4)+0x318;
 return gpiSetStatusInfo(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),a,b,c);
}

void NotifyPlayerSlotChanged(s32 a) {
 extern M2C_UNK gMatchSessionMgr; s32 func_0203a68c(void *,void *);
 u32 out[132]; void *p=M2C_FIELD(&gMatchSessionMgr,void **,8); s32 n;
 if(M2C_FIELD(p,void **,0x44)&&M2C_FIELD(p,s32 *,0)!=1)
 M2C_FIELD(p,void (**)(s32,s32),0x44)(a,M2C_FIELD(p,s32 *,0x48));
 p=M2C_FIELD(&gMatchSessionMgr,void **,8);
 if(!M2C_FIELD(p,void **,0x34))return;
 n=func_0203a68c((u8 *)M2C_FIELD(p,void **,0x18)+a*12,out+66);
 p=M2C_FIELD(&gMatchSessionMgr,void **,8);
 M2C_FIELD(p,void (**)(s32,s32,void *,s32),0x34)(a,n,out+66,M2C_FIELD(p,s32 *,0x38));
}

void func_0203b088(void) {
    extern M2C_UNK gMatchSessionMgr;
    M2C_FIELD(&gMatchSessionMgr, s32 *, 8) = 0;
}

s32 func_0203b09c(void) {
 extern M2C_UNK gMatchSessionMgr; u64 GetSystemTick(void);
 u64 func_02072088(u64,u64);
 s32 func_0204db50(void *);
 s32 r=0; void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);
 if(func_02072088((GetSystemTick()-M2C_FIELD(p,u64 *,0xC))<<6,0x82EA) >=300) {
 M2C_FIELD(p,s32 *,8)++;
 r=func_0204db50(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4));
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u64 *,0xC)=GetSystemTick();
 }
 return r;
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
s32 func_0204e184(void *,s32 *);s32 func_0204e1b4(void *,s32,s32);s32 func_0204e3b0(void *,s32);
u32 ReportNetError();s32 GetSessionPlayerId(s32);s32 IsPlayerRecordJoined(void *);void AssignPlayerRecordId(void *,s32);void MarkPlayerRecordJoined(void *);
s32 func_0203b454(u8 *,s32,s32);s32 func_0204e2f4(void *,s32,s32 *);s32 DropSessionPlayer(s32);
s32 GetLocalPlayerInfo(void);s32 GetPlayerRecordId(s32,s32);void FormatPlayerNasId(s32,void *,void *);
void HandlePeerConnectResult(s32,void *,s32);s32 func_0204dd0c(void *,s32,s32,s32,s32,void *,s32,s32,void (*)(s32,void *,s32),s32);
s32 i,remoteCount,remoteIndex;u32 buddyInfo[132];u32 peerAddress[6];s32 slot,profileId;u8 *a=(u8 *)arg0;
if(!M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1e)){
ReportNetError(func_0204e184(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),&remoteCount));
#pragma opt_loop_invariants off
for(remoteIndex=0;remoteIndex<remoteCount;remoteIndex++){
ReportNetError(func_0204e1b4(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),remoteIndex,(s32)buddyInfo));
for(slot=0;slot<playerCount;slot++){
if((s32)buddyInfo[0]==GetSessionPlayerId(slot)){
if(!IsPlayerRecordJoined(a+slot*12)){
AssignPlayerRecordId(a+slot*12,buddyInfo[0]);MarkPlayerRecordJoined(a+slot*12);
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1d)=1;
}break;
}}
if(slot==playerCount){
ReportNetError(func_0204e3b0(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),buddyInfo[0]));
remoteCount--;remoteIndex--;
}}
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1e)=1;
}
while(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c)<playerCount){
profileId=GetSessionPlayerId(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c));
if(profileId){
if(!func_0203b454(a,M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c),profileId)){
ReportNetError(func_0204e2f4(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),profileId,&remoteIndex));
if(remoteIndex==-1)DropSessionPlayer(profileId);
}
}else{
if(GetPlayerRecordId(GetLocalPlayerInfo(),(s32)(a+M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c)*12))==-1){
FormatPlayerNasId(GetLocalPlayerInfo(),a+M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c)*12,peerAddress);
func_0204dd0c(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),0,0,0,0,peerAddress,0,0,HandlePeerConnectResult,M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1c));
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
void func_0203b3fc(u8 *a,u32 b,u32 c) {
extern M2C_UNK gMatchSessionMgr;void MI_CpuFill8(void*,s32,u32);
void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(!p)return;
MI_CpuFill8(a+b*12,0,12);
p=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(M2C_FIELD(p,void (**)(u32,u32,u32),0x3c))M2C_FIELD(p,void (**)(u32,u32,u32),0x3c)(b,c,M2C_FIELD(p,u32*,0x40));
}
#pragma opt_propagation reset
s32 func_0203b454(u8 *a,s32 b,s32 c) {
 extern M2C_UNK gMatchSessionMgr; s32 GetSessionPlayerId(s32); s32 IsPlayerRecordJoined(void *);
 s32 i,x;
 for(i=0;i<b;i++) {
 x=GetSessionPlayerId(i);
 if(x&&x==c) {
 if(IsPlayerRecordJoined(a+b*12)&&!IsPlayerRecordJoined(a+i*12))func_0203b3fc(a,i,b);
 else func_0203b3fc(a,b,i);
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,0x1D)=1;return 1;
 }
 }return 0;
}

s32 ResolvePlayerSlot(u8 *a, s32 b, s32 c) {
    extern M2C_UNK gMatchSessionMgr;
    s32 GetSessionPlayerId(s32);
    s32 GetPlayerRecordType(void *);
    s32 IsPlayerRecordJoined(void *);
    void AssignPlayerRecordId(void *, s32);
    void MarkPlayerRecordJoined(void *);
    void func_0203b3fc(u8 *, u32, u32);

    s32 x, i, y, j;
    s32 result = -1;
    u8 *pj = a;
    u8 *pi = a;

    for (i = 0; i < b; i++, pi += 12, pj = pi) {
        x = GetSessionPlayerId(i);
        if (x == 0) {
            continue;
        }

        if (x == c) {
            result = i;
        }

        for (j = i + 1; j < b; j++) {
            pj = a + j * 12;
            y = GetSessionPlayerId(j);
            if (x != y) {
                continue;
            }

            if (GetPlayerRecordType(pi) != 2) {
                continue;
            }

            if (GetPlayerRecordType(pj) != 3) {
                continue;
            }

            AssignPlayerRecordId(pi, x);

            if (IsPlayerRecordJoined(pj) == 0) {
                continue;
            }

            MarkPlayerRecordJoined(pi);
            func_0203b3fc(a, j, i);

            M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), u8 *, 0x1D) = 1;
        }
    }

    return result;
}

s32 DropSessionPlayer(s32 a) {
 extern M2C_UNK gMatchSessionMgr; extern M2C_UNK data_020fc8ec;
 s32 func_0204df00(void *,s32,void *); u32 ReportNetError();
 s32 r=func_0204df00(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),a,&data_020fc8ec);
 ReportNetError(r); return r;
}

s32 func_0203b63c(s32 arg0,s32 arg1) {
extern M2C_UNK gMatchSessionMgr;
s32 func_0203a660(void); s32 GetLocalPlayerInfo(void); s32 GetPlayerRecordId(s32,s32);
s32 func_0204e2f4(void *,s32,s32 *); s32 func_0204e1b4(void *,s32,s32);
void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);
s32 b=arg1; s32 a=arg0; s32 out=0;
if(!p||!func_0203a660())return 0;
a=GetPlayerRecordId(GetLocalPlayerInfo(),a);
if(a>0)if(func_0204e2f4(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),a,&out))return 0;
if(a<=0||out==-1)return 0;
return (u32)func_0204e1b4(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,4),out,b) <= 0;
}

u32 ReportNetError(u32 a,u32 unused,u32 off){void func_0203accc(u32,u32);u32 ret=a;u32 code=ret;if(ret==0)return 0;switch(ret){case 1:code=9;off=code-10;break;case 2:code=9;off=code-11;break;case 3:code=6;off=code-16;break;case 4:code=6;off=code-26;break;}func_0203accc(code,off+0xfffeeaa8);return ret;}

/* Callback for a pending GPI peer connection: matches the returned profile ids
 * to slots in the online-match session's player table, drops peers that are no
 * longer known, and marks the session ready for the next setup step. */
void HandlePeerConnectResult(s32 connection, void *result, s32 index) {
extern M2C_UNK gMatchSessionMgr;
s32 GetPlayerRecordType(void *); void MarkPlayerRecordJoined(void *); void AssignPlayerRecordId(void *,s32);
s32 func_0203b454(u8 *,s32,s32);s32 func_0204e2f4(void *,s32,s32 *);s32 DropSessionPlayer(s32);void NotifyPlayerSlotChanged(s32);
s32 peerIndex,entryOffset,slotOffset,entryBase;
if(M2C_FIELD(result,s32 *,0)==0 && M2C_FIELD(result,s32 *,4)!=0) {
slotOffset=index*MATCH_SESSION_PLAYER_SIZE;
if(GetPlayerRecordType(((u8 *)M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,MATCH_SESSION_PLAYERS)+slotOffset))!=0) {
if(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,MATCH_SESSION_STATUS)!=1)return;
peerIndex=0;if(M2C_FIELD(result,s32 *,4)>0){entryOffset=0;do {
if(func_0203b454(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,MATCH_SESSION_PLAYERS),index,M2C_FIELD((u8 *)M2C_FIELD(result,void **,0xc)+entryOffset,s32 *,0))) {
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_CURSOR)++;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,MATCH_SESSION_STATE)=1;
M2C_FIELD(result,s32 *,8)=0x601;
return;
}

peerIndex++;entryOffset+=0xac;
}while(peerIndex<M2C_FIELD(result,s32 *,4));}
entryOffset=0;if(M2C_FIELD(result,s32 *,4)>0){entryBase=entryOffset;do {
s32 profileId;
((u32 (*)(u32))ReportNetError)(func_0204e2f4((void *)connection,M2C_FIELD((u8 *)M2C_FIELD(result,void **,0xc)+entryBase,s32 *,0),&profileId));
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
void func_0203b9a8(void **conn, void *buf, s32 unused) {
    extern M2C_UNK gMatchSessionMgr;
    extern M2C_UNK data_020fc8f0;
    s32 GetPlayerRecordType(void *);
    s32 GetLocalPlayerInfo(void);
    void FormatPlayerNasId(s32, void *, void *);
    s32 StringCompare(void *, void *);
    s32 func_0204e074(void **, s32);
    void AssignPlayerRecordId(void *, s32);
    s32 GetPlayerRecordId(s32, s32);
    s32 func_0200567c(void *, s32, void *, ...);
    s32 ByteCompareN(void *, void *, s32);
    s32 DropSessionPlayer(s32);
    s32 func_0204e0c4(void **, s32);

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
                func_0204e074(conn, M2C_FIELD(buf, s32 *, 4));
                AssignPlayerRecordId((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, 0x18) + recordOffset, M2C_FIELD(buf, s32 *, 4));
                found = 1;
            }
        } else {
            if (GetPlayerRecordType((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, 0x18) + recordOffset) == 3 ||
                GetPlayerRecordType((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, 0x18) + recordOffset) == 2) {
                self = GetLocalPlayerInfo();
                selfKey = M2C_FIELD(self, u32 *, 0x24);
                func_0200567c(keyText, 5, &data_020fc8f0,
                              (selfKey >> 24) & 0xff,
                              (selfKey >> 16) & 0xff,
                              (selfKey >> 8) & 0xff,
                              selfKey & 0xff);
                messagePlayerId = M2C_FIELD(buf, s32 *, 4);
                self = GetLocalPlayerInfo();
                if (messagePlayerId == GetPlayerRecordId(self, (s32)((u8 *)M2C_FIELD(M2C_FIELD(manager, void **, 8), void **, 0x18) + recordOffset))) {
                    if (ByteCompareN(keyText, (u8 *)buf + 0x97, 4) == 0) {
                        func_0204e074(conn, messagePlayerId);
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
        func_0204e0c4(conn, M2C_FIELD(buf, s32 *, 4));
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
    s32 func_0203bd54();
    M2C_UNK DisconnectConnection();
    if (func_0203bd54() == 0) {
        return 0;
    }
    DisconnectConnection();
    return 1;
}

s32 func_0203bd54(void) {
    s32 HasNetError();
    s32 func_02038f6c();
    void *GetConnection();
    if (HasNetError() != 0) {
        return 0;
    }
    if ((GetConnection() == NULL) || (func_02038f6c() != 5) || (M2C_FIELD(GetConnection(), u8 *, 0x1A9) != 0)) {
        return 0;
    }
    return 1;
}

s32 func_0203bda0(void (*callback)(s32),s32 arg) {
s32 HasNetError(void);void *GetConnection(void);s32 func_02038f6c(void);void func_0203e410(void);
void *p;
if(HasNetError()!=0||!GetConnection()||M2C_FIELD(GetConnection(),u8 *,0x15)!=2||(func_02038f6c()!=5&&func_02038f6c()!=6))return 0;
if(M2C_FIELD(GetConnection(),s32 *,0x1a0)==10){
p=GetConnection();M2C_FIELD(p,u8 *,0x16)=M2C_FIELD(GetConnection(),u8 *,0xd);
func_0203e410();if(callback)callback(arg);
}else{
M2C_FIELD(GetConnection(),void (**)(s32),0x47c)=callback;
M2C_FIELD(GetConnection(),s32 *,0x480)=arg;
M2C_FIELD(GetConnection(),u8 *,0x1ae)=1;
}return 1;
}

