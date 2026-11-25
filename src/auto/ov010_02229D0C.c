/* 47 functions from 0x02229D0C to 0x0222A9DC (ov010), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "string_storage.h"
typedef struct { u8 value; } UnkA750Flag;
typedef struct { u32 flag:1; u32 rest:31; } UnkA750Bits;
static inline void *GetTextA320(void *s) { if (!((UnkA750Bits *)s)->flag) return (u8 *)s+1; return M2C_FIELD(s,void **,8); }

void func_ov010_02229d0c(s32 arg0) {
extern M2C_UNK gOv010OnlineSession;
M2C_FIELD(&gOv010OnlineSession, void **, 0x18) = NULL;
}

void func_ov010_02229d20(void *arg0) {
    M2C_UNK Ov010Online_SubmitStartRecord(void *, s32);
    Ov010Online_SubmitStartRecord(arg0 + 0x38, M2C_FIELD(arg0, s32 *, 0x34));
}

void func_ov010_02229d34(s32 arg0) {
    M2C_UNK Ov010Online_IsStartAcknowledged(s32);
    Ov010Online_IsStartAcknowledged(arg0 + 0x38);
}

void func_ov010_02229d44(s32 arg0) {
    void func_ov010_02229d0c(s32);
    func_ov010_02229d0c(arg0 + 0x38);
}

/* Create the online (Wi-Fi) match start-request node tagged with `matchId` and
 * owned by `owner`, once the online session is running. */
M2C_UNK **Ov010Online_CreateStartRequest(s32 matchId, M2C_UNK owner) {
    M2C_UNK **CreateSpriteObject(M2C_UNK *, M2C_UNK);
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    extern M2C_UNK gOv010StartRequestClass;
    extern M2C_UNK gOv010StartRequestVtbl;
    M2C_UNK **node;

    if (IsOnlineSessionFlagSet(OV010_FLAG_RUNNING) == 0) return NULL;
    node = CreateSpriteObject(&gOv010StartRequestClass, owner);
    if (node != NULL) {
        *node = &gOv010StartRequestVtbl;
        M2C_FIELD(node, s32 *, 0x34) = matchId;
    }
    return node;
}

/* Start announcing the local player: while the online session is running, fill the
 * local player's join record with this console's player bit and whether its status
 * was published, then register that record with the session. */
M2C_UNK Ov010Online_AnnounceLocalPlayer(s32 record) {
    s32 GetOnlineTransportPlayerId();
    s8 PublishLocalPlayerStatus();
    extern M2C_UNK gOv010OnlineSession;
    if (IsOnlineSessionFlagSet(OV010_FLAG_RUNNING) == 0) return;
    M2C_FIELD(record, u16 *, OV010_PLAYER_MASK) = 1 << GetOnlineTransportPlayerId();
    M2C_FIELD(record, u8 *, OV010_PLAYER_JOINED) = PublishLocalPlayerStatus();
    M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_PLAYER) = record;
}

/* Check the online session's local-player join record: returns 1 when the
 * record says the join succeeded, the session is running, there is no network
 * error and the current peer mask holds more than the local player's own bit
 * (another peer is present).  Returns 0 otherwise, after running the host
 * check. */
s32 Ov010Online_IsPlayerJoined(s32 self) {
    s32 GetOnlinePeerMask();
    s32 GetNetErrorCode();
    extern M2C_UNK gOv010OnlineSession;
    s32 v, b, t;
    if (M2C_FIELD(&gOv010OnlineSession, void * volatile *, OV010_SESSION_PLAYER)) {
        v = GetOnlinePeerMask();
        t = GetOnlinePeerMask();
        if (v != (M2C_FIELD(M2C_FIELD(&gOv010OnlineSession, void **, OV010_SESSION_PLAYER), u16 *, OV010_PLAYER_MASK) & t)) {
            v = 1;
            goto ready;
        }
    }
    v = 0;
ready:
    if (!M2C_FIELD(M2C_FIELD(&gOv010OnlineSession, void **, OV010_SESSION_PLAYER), u8 *, OV010_PLAYER_JOINED)) v = 0;
    if (!IsOnlineSessionFlagSet(OV010_FLAG_RUNNING)) v = 0;
    if (GetNetErrorCode()) b = 1; else b = 0;
    if (b) v = 0;
    if (!v) IsOnlineSessionHost();
    return v;
}

void func_ov010_02229e70(s32 arg0) {
extern M2C_UNK gOv010OnlineSession;
M2C_FIELD(&gOv010OnlineSession, void **, 0x24) = NULL;
}

void func_ov010_02229e84(s32 arg0) {
    M2C_UNK Ov010Online_AnnounceLocalPlayer(s32);
    Ov010Online_AnnounceLocalPlayer(arg0 + 0x34);
}

void func_ov010_02229e94(s32 arg0) {
    M2C_UNK Ov010Online_IsPlayerJoined(s32);
    Ov010Online_IsPlayerJoined(arg0 + 0x34);
}

void func_ov010_02229ea4(s32 arg0) {
    void func_ov010_02229e70(s32);
    func_ov010_02229e70(arg0 + 0x34);
}

/* Spawn the online (Wi-Fi) player-announce sprite under `owner`: it refreshes the
 * other players' view of this console's status as it changes.  Returns NULL unless
 * the online session is running. */
M2C_UNK **SpawnOnlinePlayerAnnounce(M2C_UNK owner) {
    M2C_UNK **CreateSpriteObject(M2C_UNK *, M2C_UNK);
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    extern M2C_UNK gOnlinePlayerAnnounceClass;
    extern M2C_UNK gOnlinePlayerAnnounceVtbl;
    M2C_UNK **announce;

    if (IsOnlineSessionFlagSet(OV010_FLAG_RUNNING) == 0) {
        return NULL;
    }
    announce = CreateSpriteObject(&gOnlinePlayerAnnounceClass, owner);
    if (announce != NULL) {
        *announce = &gOnlinePlayerAnnounceVtbl;
    }
    return announce;
}

/* Start the WFC match query that looks up `count` player names on the WFC
 * connection: clears the caller's per-player flag buffer and count, then creates
 * the query with the default encoding.  Returns 0 when the connection is not up
 * or the query cannot be started. */
s32 Ov010_RequestWfcMatch(s32 names,s32 count,s32 timeout,s32 flagsOut,s32 countOut){s32 CreateWfcMatchForRegion(s32,s32,s32,s32,s32,s32,s32);if(!IsOnlineSessionFlagSet(OV010_FLAG_CONNECTED))return 0;MI_CpuFill8(flagsOut,0,count);M2C_FIELD(countOut,s32 *,0)=0;return CreateWfcMatchForRegion(names,count,0,timeout,flagsOut,countOut,255);}

s32 Ov010_IsWfcMatchRunning(void) {
    u32 PollWfcMatchRequest();
    s32 var_r4;
    u32 temp_r0;

    var_r4 = 0;
    temp_r0 = PollWfcMatchRequest();
    switch (temp_r0) {
    case 0:
    case 2:
    case 3:
        break;
    default:
        break;
    case 1:
        var_r4 = 1;
        break;
    }
    return var_r4;
}

void func_ov010_02229f98(void *arg0) {
    M2C_UNK Ov010_RequestWfcMatch(s32, s32, s32, s32, s32);
    Ov010_RequestWfcMatch(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40), M2C_FIELD(arg0, s32 *, 0x44));
}

void func_ov010_02229fc0(void) {
    M2C_UNK Ov010_IsWfcMatchRunning();
    Ov010_IsWfcMatchRunning();
}

void func_ov010_02229fcc(void) {

}

/* Creates the online overlay's match-request node, a 3D sprite that searches WFC
 * for a hosted game when it is stepped.  Returns NULL unless the WFC connection is
 * up or the node cannot be made; `owner` is the sprite it is parented to. */
void *CreateOnlineMatchRequest(s32 names, s32 nameCount, s32 type, s32 timeout, s32 flags, s32 owner) {
    extern M2C_UNK gOnlineMatchRequestClass;
    extern M2C_UNK gOnlineMatchRequestVtbl;
    void *request;

    if (IsOnlineSessionFlagSet(OV010_FLAG_CONNECTED) == 0) {
        return NULL;
    }
    request = CreateSpriteObject(&gOnlineMatchRequestClass, owner);
    if (request == NULL) {
        return request;
    }
    M2C_FIELD(request, M2C_UNK **, 0) = &gOnlineMatchRequestVtbl;
    M2C_FIELD(request, s32 *, MATCH_REQUEST_NAMES) = names;
    M2C_FIELD(request, s32 *, MATCH_REQUEST_NAME_COUNT) = nameCount;
    M2C_FIELD(request, s32 *, MATCH_REQUEST_TYPE) = type;
    M2C_FIELD(request, s32 *, MATCH_REQUEST_TIMEOUT) = timeout;
    M2C_FIELD(request, s32 *, MATCH_REQUEST_FLAGS) = flags;
    return request;
}

void func_ov010_0222a038(void) {

}

s32 func_ov010_0222a03c(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void *func_ov010_0222a050(void *arg0) {
    M2C_UNK Ov010Online_FreePacket();
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        Ov010Online_FreePacket();
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
    }
    return arg0;
}

void *func_ov010_0222a078(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        Ov010Online_FreePacket();
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
    }
    MemFree(arg0);
    return arg0;
}

s32 func_ov010_0222a0a8(s32 arg0) {
    M2C_UNK DestroyArray(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK func_ov010_02228a48;
    DestroyArray(arg0 + 0x34, 4, 8, &func_ov010_02228a48);
    return arg0;
}

s32 func_ov010_0222a0d0(s32 arg0) {
    M2C_UNK DestroyArray(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK func_ov010_02228a48;
    DestroyArray(arg0 + 0x34, 4, 8, &func_ov010_02228a48);
    MemFree(arg0);
    return arg0;
}

void func_ov010_0222a100(void) {

}

s32 func_ov010_0222a104(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov010_0222a118(void) {

}

s32 func_ov010_0222a11c(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov010_0222a130(void) {

}

s32 func_ov010_0222a134(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov010_0222a148(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

/* Per-frame network error check: while an error is pending, report it once — mark
   the session's error flag and hand the error code, detail and category to the
   owner's error callback, if it has one. */
void ReportNetErrorToCallback(void *self) {
    s32 GetNetErrorCode();
    s32 func_ov010_02228314(s32 *, u32 *);
    s32 errorDetail;
    u32 errorType;
    void (*callback)(s32, s32, u32, s32);
    s32 errorCode, reported;
    if (GetNetErrorCode()) reported = 1; else reported = 0;
    if (!reported) return;
    errorCode = func_ov010_02228314(&errorDetail, &errorType);
    if (IsOnlineSessionFlagSet(OV010_FLAG_ERROR)) return;
    switch (errorType) {
    case 0:
        break;
    case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        SetOnlineSessionFlag(OV010_FLAG_ERROR);
        callback = M2C_FIELD(self, void (**)(s32, s32, u32, s32), 0x34);
        if (!callback) return;
        callback(errorCode, errorDetail, errorType, M2C_FIELD(self, s32 *, 0x18));
        break;
    default:
        break;
    }
}

void func_ov010_0222a20c(s32 arg0) {
    void *CreateSpriteFromClass(void *);
    extern M2C_UNK data_ov010_0222c544, data_ov010_0222c900;
    void *temp_r0;
    temp_r0 = CreateSpriteFromClass(&data_ov010_0222c544);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, void **, 0) = &data_ov010_0222c900;
        M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    }
}

void func_ov010_0222a238(void) {
    M2C_UNK IncrementSpriteChildCount();
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_ov010_0222c544;
    if (FindObjectByClass(&data_ov010_0222c544) == 0) {
        return;
    }
    IncrementSpriteChildCount();
}

void Ov010Online_ReleaseTextLayer(void) {
    M2C_UNK DecrementSpriteChildCount();
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_ov010_0222c544;
    if (FindObjectByClass(&data_ov010_0222c544) == 0) {
        return;
    }
    DecrementSpriteChildCount();
}

void func_ov010_0222a278(void) {
    M2C_UNK DeleteSpriteObject();
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_ov010_0222c544;
    if (FindObjectByClass(&data_ov010_0222c544) == 0) {
        return;
    }
    DeleteSpriteObject();
}

u8 func_ov010_0222a298(void) {
    s32 IsScreenFadeActive();
    u8 var_r0;

    if (IsScreenFadeActive() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Online match screen update: start the split-screen fade on each screen whose
 * earlier split transition has finished.  Bits 1 and 2 of the sprite's flags
 * byte mark the main and sub screens that are waiting for their fade. */
void StartOnlineMatchSplitFades(void *sprite) {
    s32 GetScreenFlag(M2C_UNK);
    M2C_UNK StartScreenFadeChildren(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if ((M2C_FIELD(sprite, u8 *, 0x34) & 1) && (GetScreenFlag(0) == 0)) {
        StartScreenFadeChildren(2, 8, 0, sprite);
    }
    if (!(M2C_FIELD(sprite, u8 *, 0x34) & 2)) {
        return;
    }
    if (GetScreenFlag(1) != 0) {
        return;
    }
    StartScreenFadeChildren(2, 8, 1, sprite);
}

#pragma opt_common_subs off
#pragma scheduling on
void func_ov010_0222a320(void *a){
extern u8 data_ov010_0222c8f4[];extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub,g3DSpriteEngineMain;
void *func_ov010_0222832c(void *,void *);void *GetLocalizedText(void *);void func_ov010_0222bc54(void *,void *);void func_0206f8b8(s32,void *,s32);void StringStorageConcat(void *,void *,void *);void StringStorageAssign(void *,void *);void func_0206fa14(void *);s32 FindTextLayer(void);void StartWindowClose(void);void *CreateTextLayer(void *);void RenderTextLayer(void *,s32,s32,void *);void func_ov010_0222a238(void);void func_ov010_0222a278(void);
u8 sp[0x44];s32 v;
func_ov010_0222bc54((u8 *)a+0x44,GetLocalizedText(func_ov010_0222832c(M2C_FIELD(a,void **,0x3c),M2C_FIELD(a,void **,0x40))));
v=M2C_FIELD(a,s32 *,0x3c);if(v<0)v=-v;func_0206f8b8(v,sp+0x24,10);
StringStorageConcat(sp+0x18,(u8 *)a+0x44,data_ov010_0222c8f4);
StringStorageConcat(sp+0xc,sp+0x18,GetLocalizedText((void *)0x42000000));
StringStorageConcat(sp,sp+0xc,sp+0x24);
StringStorageAssign((u8 *)a+0x44,sp);func_0206fa14(sp);func_0206fa14(sp+0xc);func_0206fa14(sp+0x18);
if(!M2C_FIELD(a,s32 *,0x38))return;
switch(M2C_FIELD(a,s32 *,0x40)){
case 0:case 1:func_ov010_0222a238();return;
case 2:{
s32 old;void *text;s32 i;u32 current;s8 mode;void *p;
if(FindTextLayer())StartWindowClose();
if(((UnkA750Bits *)((u8 *)a+0x44))->flag)text=M2C_FIELD(a,void **,0x4c);else text=(u8 *)a+0x45;
old=gCur3DSpriteEngine;i=0;do{
if(i==0)current=g3DSpriteEngineMain;else current=g3DSpriteEngineSub;
gCur3DSpriteEngine=current;mode=M2C_FIELD(a,s8 *,0x35);
if(mode==0&&current!=g3DSpriteEngineMain)continue;
if(mode==1&&current!=g3DSpriteEngineSub)continue;
if(mode==3&&current!=old)continue;
p=CreateTextLayer(a);RenderTextLayer(p,2,M2C_FIELD(a,u16 *,0x36)<<5,text);M2C_FIELD(p,u32 *,0x58)|=0x1400;
}while(++i<2);
gCur3DSpriteEngine=old;func_ov010_0222a238();return;
}
case 3:case 4:case 5:case 6:{
s32 old;void *text;s32 i;u32 current;s8 mode;void *p;
if(FindTextLayer())StartWindowClose();
if(((UnkA750Bits *)((u8 *)a+0x44))->flag)text=M2C_FIELD(a,void **,0x4c);else text=(u8 *)a+0x45;
old=gCur3DSpriteEngine;i=0;do{
if(i==0)current=g3DSpriteEngineMain;else current=g3DSpriteEngineSub;
gCur3DSpriteEngine=current;mode=M2C_FIELD(a,s8 *,0x35);
if(mode==0&&current!=g3DSpriteEngineMain)continue;
if(mode==1&&current!=g3DSpriteEngineSub)continue;
if(mode==3&&current!=old)continue;
p=CreateTextLayer(a);RenderTextLayer(p,2,M2C_FIELD(a,u16 *,0x36)<<5,text);M2C_FIELD(p,u32 *,0x58)|=0x1400;
}while(++i<2);
gCur3DSpriteEngine=old;func_ov010_0222a278();return;
}
case 7:{
s32 old;void *text;s32 i;u32 current;s8 mode;void *p;
if(FindTextLayer())StartWindowClose();
if(((UnkA750Bits *)((u8 *)a+0x44))->flag)text=M2C_FIELD(a,void **,0x4c);else text=(u8 *)a+0x45;
old=gCur3DSpriteEngine;i=0;do{
if(i==0)current=g3DSpriteEngineMain;else current=g3DSpriteEngineSub;
gCur3DSpriteEngine=current;mode=M2C_FIELD(a,s8 *,0x35);
if(mode==0&&current!=g3DSpriteEngineMain)continue;
if(mode==1&&current!=g3DSpriteEngineSub)continue;
if(mode==3&&current!=old)continue;
p=CreateTextLayer(a);RenderTextLayer(p,0,M2C_FIELD(a,u16 *,0x36)<<5,text);M2C_FIELD(p,u32 *,0x58)|=0x1c00;
}while(++i<2);
gCur3DSpriteEngine=old;func_ov010_0222a278();return;
}
default:func_ov010_0222a238();return;}}
#pragma opt_common_subs reset
#pragma scheduling reset
/* Net-error sprite frame: release the text layer the text error classes (0..2)
 * left up so the sprite can draw the next error; the match-label classes (3..7)
 * keep their label and need nothing here. */
void Ov010Online_ReleaseNetErrorText(void *error){
 u32 errorClass;
 if(!M2C_FIELD(error,s32 *,NET_ERROR_CODE))return;
 errorClass=M2C_FIELD(error,u32 *,NET_ERROR_CLASS);
 switch(errorClass){
 case 0:case 1:case 2:Ov010Online_ReleaseTextLayer();return;
 default:Ov010Online_ReleaseTextLayer();return;
 case 3:case 4:case 5:case 6:case 7:return;
 }
}

/* Online net-error screen update: create the split-screen transition on each
 * screen whose transition flag is set, and set that screen's bit (1 main, 2 sub)
 * in the sprite's flags so the split fade starts once the transition finishes. */
void StartNetErrorSplitTransitions(void *sprite) {
    M2C_UNK CreateScreenTransitionChildren(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if (GetScreenFlag(0) == 1) {
        CreateScreenTransitionChildren(2, 8, 0, sprite);
        M2C_FIELD(sprite, u8 *, 0x34) = (u8) (M2C_FIELD(sprite, u8 *, 0x34) | 1);
    }
    if (GetScreenFlag(1) != 1) {
        return;
    }
    CreateScreenTransitionChildren(2, 8, 1, sprite);
    M2C_FIELD(sprite, u8 *, 0x34) = (u8) (M2C_FIELD(sprite, u8 *, 0x34) | 2);
}

/* Builds the text string `out` as `first` (a stored text string, inline or on the
 * heap) followed by the plain string `last`: clears `out`, reserves room for both,
 * then inserts `first` at position 0 and `last` right after it. */
void StringStorageConcat(void *out, void *first, void *last) {
    s32 StringLength(void *);
    void *StringStorageReplace(void *, s32, s32, void *, void *, UnkA750Flag);
    u32 i, firstLen;
    void *firstData;
    s32 lastLen;
    UnkA750Flag flags[2];
    void *r;

    for (i = 0; i < 3; i++) ((u32 *)out)[i] = 0;
    lastLen = StringLength(last);
    if (((StringStorage *)first)->large.flag) {
        firstData = ((StringStorage *)first)->large.data;
        firstLen = ((StringStorage *)first)->large.length;
    } else {
        firstData = ((StringStorage *)first)->small.data;
        firstLen = ((StringStorage *)first)->small.length;
    }
    StringStorageReserve(out, firstLen + lastLen);
    r = StringStorageReplace(out, 0, 0, firstData, firstData + firstLen, flags[1]);
    StringStorageReplace(r, firstLen, 0, last, last + lastLen, flags[0]);
}

/* Create the sprite showing a network error on an online screen: a text layer of
 * the net-error class with the given engine, text value, error code, error
 * parameter and error class.  A zero error code means no sprite is created. */
void CreateNetErrorSprite(s8 engine, u16 value, s32 errorCode, s32 errorParam, u32 errorClass, void *owner) {
 extern M2C_UNK gNetErrorSpriteClass, gNetErrorSpriteVTable;
 void *CreateSpriteForOwner(void *, void *);
 void *sprite;
 u32 i;
 u32 *extra;
 if (!errorCode) return;
 sprite = CreateSpriteForOwner(&gNetErrorSpriteClass, owner);
 if (!sprite) return;
 M2C_FIELD(sprite, void **, 0) = &gNetErrorSpriteVTable;
 M2C_FIELD(sprite, u8 *, TEXT_LAYER_FLAGS) = 0;
 M2C_FIELD(sprite, s8 *, TEXT_LAYER_ENGINE) = engine;
 M2C_FIELD(sprite, u16 *, TEXT_LAYER_VALUE) = value;
 M2C_FIELD(sprite, s32 *, 0x38) = errorCode;
 M2C_FIELD(sprite, s32 *, 0x3c) = errorParam;
 M2C_FIELD(sprite, u32 *, 0x40) = errorClass;
 extra = sprite + 0x44;
 for (i = 0; i < 3; i++) extra[i] = 0;
}

/* Net-error sprite update: start the split-screen fade on each screen whose
 * earlier split transition has finished.  Bits 1 and 2 of the sprite's flags
 * byte mark the main and sub screens that are waiting for their fade. */
void StartNetErrorSplitFades(void *sprite) {
    s32 GetScreenFlag(M2C_UNK);
    M2C_UNK StartScreenFadeChildren(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if ((M2C_FIELD(sprite, u8 *, 0x34) & 1) && (GetScreenFlag(0) == 0)) {
        StartScreenFadeChildren(2, 8, 0, sprite);
    }
    if (!(M2C_FIELD(sprite, u8 *, 0x34) & 2)) {
        return;
    }
    if (GetScreenFlag(1) != 0) {
        return;
    }
    StartScreenFadeChildren(2, 8, 1, sprite);
}

/* Show the network error held by an online screen object (+0x38 code, +0x3C
 * parameter, +0x40 class): spawn its error sprite, and for error classes 3..7
 * also create the online match's name label. A screen with no error does
 * nothing. */
void Ov010Online_ShowNetError(void *error) {
M2C_UNK CreateOnlineMatchNameLabel(s32,u16,void *);
if(!M2C_FIELD(error,volatile s32 *,0x38))return;
CreateNetErrorSprite(M2C_FIELD(error,s8 *,0x35),M2C_FIELD(error,u16 *,0x36),M2C_FIELD(error,s32 *,0x38),M2C_FIELD(error,s32 *,0x3c),M2C_FIELD(error,u32 *,0x40),error);
switch(M2C_FIELD(error,u32 *,0x40)){case 0:case 1:case 2:break;case 3:case 4:case 5:case 6:case 7:CreateOnlineMatchNameLabel(-1,M2C_FIELD(error,u16 *,0x36),error);break;default:break;}}

void func_ov010_0222a96c(void) {

}

/* Online match screen update: create the split-screen transition on each screen
 * whose transition flag is set, and set that screen's bit (1 main, 2 sub) in the
 * sprite's flags so the split fade (StartOnlineMatchSplitFades) starts once the
 * transition finishes. */
void StartOnlineMatchSplitTransitions(void *sprite) {
    M2C_UNK CreateScreenTransitionChildren(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if (GetScreenFlag(0) == 1) {
        CreateScreenTransitionChildren(2, 8, 0, sprite);
        M2C_FIELD(sprite, u8 *, 0x34) = (u8) (M2C_FIELD(sprite, u8 *, 0x34) | 1);
    }
    if (GetScreenFlag(1) != 1) {
        return;
    }
    CreateScreenTransitionChildren(2, 8, 1, sprite);
    M2C_FIELD(sprite, u8 *, 0x34) = (u8) (M2C_FIELD(sprite, u8 *, 0x34) | 2);
}

