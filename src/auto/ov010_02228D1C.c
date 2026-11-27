/* 42 functions from 0x02228D1C to 0x02229D0C (ov010), found by ds-decomp. */
#include "common.h"
#define ONLINE_USE_INTERRUPT_GUARD
#include "online_link.h"
typedef struct Ov010MemberCall { s32 function; s32 adjustment; } Ov010MemberCall;
static inline void ov010CallMember(void *object, volatile Ov010MemberCall *call) {
s32 adj=call->adjustment;
void *self=(u8 *)object+(adj>>1);
s32 fn;
fn=(adj&1)?*(s32 *)(*(u8 **)self+call->function):call->function;
((void (*)(void *))fn)(self);
}
static inline void ov010CallArray(u8 *first,s32 size,Ov010MemberCall call) {
Ov010MemberCall copy;
u8 *last=first+size;
copy.function=call.function;copy.adjustment=call.adjustment;
while(first!=last) { ov010CallMember(first,&copy); first+=0x6c; }
}
#pragma cplusplus on
class Ov010Callback { public: void run(); };
typedef void (Ov010Callback::*Ov010CallbackFn)();
static inline void ov010MarkActive(Ov010CallbackFn *dest,Ov010CallbackFn *src,u8 *state) { *dest=*src; state[0x107]=1; }
struct Ov010Functor {
 Ov010CallbackFn fn;
 explicit Ov010Functor(Ov010CallbackFn value):fn(value) {}
 void operator()(Ov010Callback *object) const { (object->*fn)(); }
};
static inline Ov010Functor ov010Apply(Ov010Callback *first, Ov010Callback *last, Ov010Functor fn) {
 for (; first != last; first=(Ov010Callback *)((u8 *)first+0x6c)) fn(first);
 return fn;
}
static inline Ov010CallbackFn ov010ForEach(Ov010Callback *first, Ov010Callback *last, Ov010CallbackFn fn) {
 for (; first != last; first = (Ov010Callback *)((u8 *)first + 0x6c)) (first->*fn)();
 return fn;
}
static inline Ov010MemberCall ov010VisitArray(u8 *first,u8 *last,Ov010MemberCall call) {
Ov010MemberCall copy=call;
while(first!=last){ov010CallMember(first,&copy);first+=0x6c;}
return copy;
}
typedef struct Ov010Member { s32 function; s32 delta; } Ov010Member;
#pragma cplusplus off
typedef struct QueueNode { struct QueueNode *next; u32 unk4; u8 kind; u8 low:4; u8 high:4; u16 value; s32 size; } QueueNode;

/* Create the online session's sprite object (owned by `owner`) once the session's
 * work block has been allocated (OV010_FLAG_STARTED); do nothing before that. */
void CreateOnlineSessionObject(M2C_UNK owner) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    extern M2C_UNK data_ov010_0222c218;
    if (IsOnlineSessionFlagSet(OV010_FLAG_STARTED) == 0) {
        return;
    }
    CreateSpriteObject(&data_ov010_0222c218, owner);
}

#pragma cplusplus on
#pragma optimization_level 2
#pragma opt_dead_code off
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void func_ov010_02228d48(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    void func_ov010_02226a88(void);
    void Ov010Online_ClearStepFlag(s32);
    s32 Ov010_SetMatchEventCallback(s32);
    s32 SetOnlineScoreCallback(s32);
    void ClearOnlineEventFlags(void);
    s32 GetEarnedRecordTierTotal(void);
    s32 GetRecordRank(void);
    s32 GetFavouriteRecordGroup(void);
    s32 GetFavouriteRecordIndex(void);
    void *GetProfileSaveBlock(void);
    M2C_UNK PublishPlayerStatusLocation(M2C_UNK *, s32);
    s8 func_0203bf80(u32, s32, s32);
    s8 func_0203be54(s8, s32, s32);
    M2C_UNK StartHostingMatch(s32, s32, s32, s32, s32, s32);
    M2C_UNK StringFormatBuffer(M2C_UNK, s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void Ov010Online_ScoreMatch(void);
    void Ov010Online_OnHostJoinEvent(void);

    extern Ov010Member data_ov010_0222c128;
    extern M2C_UNK gOv010PlayerRecords;
    extern u8 data_ov010_0222f1dc[];
    extern u16 gOv010OnlineSession;
    extern M2C_UNK gLocalPlayerStatus;
    extern M2C_UNK data_ov010_0222c404;
    extern M2C_UNK data_ov010_0222c414;
    extern M2C_UNK data_ov010_0222c41c;
    extern M2C_UNK data_ov010_0222ef10;
    extern M2C_UNK data_ov010_0222c42c;
    extern M2C_UNK data_ov010_0222ef3c;
    extern M2C_UNK data_ov010_0222c438;
    extern M2C_UNK data_ov010_0222ef28;
    extern M2C_UNK data_ov010_0222c440;
    extern M2C_UNK data_ov010_0222ef08;
    extern M2C_UNK data_ov010_0222c44c;
    extern M2C_UNK data_ov010_0222c488;

    Ov010CallbackFn c, a, b;
volatile Ov010CallbackFn d;
#pragma opt_dead_assignments off
    u8 *p;
    u8 buf[0x80];

    func_ov010_02226a88();
    GetProfileSaveBlock();
    Ov010Online_ClearStepFlag(3);
    Ov010Online_ClearStepFlag(4);
    Ov010_SetMatchEventCallback(arg2);
    SetOnlineScoreCallback(arg4);
    ClearOnlineEventFlags();
    a = *(Ov010CallbackFn *)&data_ov010_0222c128;
    b = a;
    c = b;
    for (p = (u8 *)&gOv010PlayerRecords; p != (u8 *)data_ov010_0222f1dc; p += 0x6c) {
        (((Ov010Callback *)p)->*c)();
    }
    d = c;
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0x107) = 0;
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0x108) = (u8)arg0;
    GetEarnedRecordTierTotal();
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0x104) = (u8)GetRecordRank();
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0x105) = (u8)GetFavouriteRecordGroup();
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0x106) = (u8)GetFavouriteRecordIndex();
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x100) = M2C_FIELD(GetProfileSaveBlock(), s32 *, 0x54);
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0xfa) = 2 | M2C_FIELD(&gOv010OnlineSession,u8 *,0xfa);
    PublishPlayerStatusLocation(&gLocalPlayerStatus, 0x6c);

    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x30) = (s32)M2C_FIELD(&gOv010OnlineSession, s8 *, 0x107);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x5c) = (s32)M2C_FIELD(&gOv010OnlineSession, s8 *, 0x108);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x48) = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x100);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x28) = arg6;

    func_0203bf80(0, (u32)&data_ov010_0222c404, (s32)&data_ov010_0222c414);

    func_0203be54(0, (s32)&data_ov010_0222c41c, (s32)&data_ov010_0222ef10);
    func_0203be54(0, (s32)&data_ov010_0222c42c, (s32)&data_ov010_0222ef3c);
    func_0203be54(0, (s32)&data_ov010_0222c438, (s32)&data_ov010_0222ef28);
    func_0203be54(0, (s32)&data_ov010_0222c440, (s32)&data_ov010_0222ef08);

    s32 x = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x30); s32 y = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x5c);
    buf[0x7f] = 0;
    StringFormatBuffer((M2C_UNK)buf, 0x7f, (M2C_UNK)&data_ov010_0222c44c, (M2C_UNK)&data_ov010_0222c488,
                   x,
                   y);

    StartHostingMatch(arg1 & 0xff, (s32)buf, (s32)Ov010Online_OnHostJoinEvent, arg3, (s32)Ov010Online_ScoreMatch, arg5);
#pragma opt_dead_assignments reset
}
#pragma cplusplus off

#pragma cplusplus on
#pragma optimization_level 2
#pragma opt_dead_code off
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void func_ov010_02228f80(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    void func_ov010_02226a88(void);
    void Ov010Online_ClearStepFlag(s32);
    s32 Ov010_SetMatchEventCallback(s32);
    s32 SetOnlineScoreCallback(s32);
    void ClearOnlineEventFlags(void);
    s32 GetEarnedRecordTierTotal(void);
    s32 GetRecordRank(void);
    s32 GetFavouriteRecordGroup(void);
    s32 GetFavouriteRecordIndex(void);
    void *GetProfileSaveBlock(void);
    M2C_UNK PublishPlayerStatusLocation(M2C_UNK *, s32);
    s8 func_0203bf80(u32, s32, s32);
    s8 func_0203be54(s8, s32, s32);
    M2C_UNK func_020388d8(s32,s32,s32,s32,...);
    M2C_UNK StringFormatBuffer(M2C_UNK, s32, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void Ov010Online_ScoreMatch(void);
    void Ov010Online_OnHostJoinEvent(void);

    extern Ov010Member data_ov010_0222c128;
    extern M2C_UNK gOv010PlayerRecords;
    extern u8 data_ov010_0222f1dc[];
    extern u16 gOv010OnlineSession;
    extern M2C_UNK gLocalPlayerStatus;
    extern M2C_UNK data_ov010_0222c490;
    extern M2C_UNK data_ov010_0222c4a0;
    extern M2C_UNK data_ov010_0222c4a8;
    extern M2C_UNK data_ov010_0222ef10;
    extern M2C_UNK data_ov010_0222c4b8;
    extern M2C_UNK data_ov010_0222ef3c;
    extern M2C_UNK data_ov010_0222c4c4;
    extern M2C_UNK data_ov010_0222ef28;
    extern M2C_UNK data_ov010_0222c4cc;
    extern M2C_UNK data_ov010_0222ef08;
    extern M2C_UNK data_ov010_0222c44c;
    extern M2C_UNK data_ov010_0222c488;

    Ov010CallbackFn c, a, b;
volatile Ov010CallbackFn d;
#pragma opt_dead_assignments off
    u8 *p;
    

    func_ov010_02226a88();
    GetProfileSaveBlock();
    Ov010Online_ClearStepFlag(3);
    Ov010Online_ClearStepFlag(4);
    Ov010_SetMatchEventCallback(arg3);
    SetOnlineScoreCallback(arg5);
    ClearOnlineEventFlags();
    a = *(Ov010CallbackFn *)&data_ov010_0222c128;
    b = a;
    c = b;
    for (p = (u8 *)&gOv010PlayerRecords; p != (u8 *)data_ov010_0222f1dc; p += 0x6c) {
        (((Ov010Callback *)p)->*c)();
    }
    d = c;
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0x107) = 1;
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0x108) = (u8)arg0;
    GetEarnedRecordTierTotal();
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0x104) = (u8)GetRecordRank();
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0x105) = (u8)GetFavouriteRecordGroup();
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0x106) = (u8)GetFavouriteRecordIndex();
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x100) = M2C_FIELD(GetProfileSaveBlock(), s32 *, 0x54);
    M2C_FIELD(&gOv010OnlineSession, u8 *, 0xfa) = 2 | M2C_FIELD(&gOv010OnlineSession,u8 *,0xfa);
    PublishPlayerStatusLocation(&gLocalPlayerStatus, 0x6c);

    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x30) = (s32)M2C_FIELD(&gOv010OnlineSession, s8 *, 0x107);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x5c) = (s32)M2C_FIELD(&gOv010OnlineSession, s8 *, 0x108);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x48) = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x100);
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x28) = arg7;

    func_0203bf80(0, (u32)&data_ov010_0222c490, (s32)&data_ov010_0222c4a0);

    func_0203be54(0, (s32)&data_ov010_0222c4a8, (s32)&data_ov010_0222ef10);
    func_0203be54(0, (s32)&data_ov010_0222c4b8, (s32)&data_ov010_0222ef3c);
    func_0203be54(0, (s32)&data_ov010_0222c4c4, (s32)&data_ov010_0222ef28);
    func_0203be54(0, (s32)&data_ov010_0222c4cc, (s32)&data_ov010_0222ef08);

    arg3=arg6;
    func_020388d8(0,60,(u8)arg1,arg2,(s32)Ov010Online_OnHostJoinEvent,arg4,(s32)Ov010Online_ScoreMatch,arg3);
#pragma opt_dead_assignments reset
}
#pragma cplusplus on
#pragma optimization_level 2
#pragma opt_dead_code off
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma opt_dead_assignments off
extern "C" void func_ov010_02229190(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 arg5) {
 void func_ov010_02226a88(void);
 void ClearOnlineEventFlags(void);
 s32 Ov010_SetMatchCallback(s32);
 s32 Ov010_SetPeerJoinedCallback(s32);
 void Ov010Online_ClearStepFlag(s32);
 s32 GetEarnedRecordTierTotal(void);
 s32 GetRecordRank(void);
 s32 GetFavouriteRecordGroup(void);
 s32 GetFavouriteRecordIndex(void);
 void *GetProfileSaveBlock(void);
 M2C_UNK PublishPlayerStatusLocation(M2C_UNK *,s32);
 void StartServingMatchSession(s32,void *,s32,void *,s32);
 void func_ov010_0222807c(void);
 void Ov010Online_OnPeerJoined(void);
 extern Ov010Member data_ov010_0222c128;
 extern M2C_UNK gOv010PlayerRecords;
 extern u8 data_ov010_0222f1dc[];
 extern u16 gOv010OnlineSession;
 extern M2C_UNK gLocalPlayerStatus;
 Ov010CallbackFn c, a, b;
 volatile Ov010CallbackFn d;
 u8 *p;
 func_ov010_02226a88();
 Ov010Online_ClearStepFlag(3);
 Ov010Online_ClearStepFlag(4);
 Ov010_SetMatchCallback(arg2);
 Ov010_SetPeerJoinedCallback(arg4);
 ClearOnlineEventFlags();
 a = *(Ov010CallbackFn *)&data_ov010_0222c128;
 b = a;
 c = b;
 for(p=(u8 *)&gOv010PlayerRecords;p!=data_ov010_0222f1dc;p+=0x6c) {
  (((Ov010Callback *)p)->*c)();
 }
 d=c;
 M2C_FIELD(&gOv010OnlineSession,u8 *,0x107)=1;
 M2C_FIELD(&gOv010OnlineSession,u8 *,0x108)=arg0;
 GetEarnedRecordTierTotal();
 M2C_FIELD(&gOv010OnlineSession,u8 *,0x104)=GetRecordRank();
 M2C_FIELD(&gOv010OnlineSession,u8 *,0x105)=GetFavouriteRecordGroup();
 M2C_FIELD(&gOv010OnlineSession,u8 *,0x106)=GetFavouriteRecordIndex();
 M2C_FIELD(&gOv010OnlineSession,s32 *,0x100)=M2C_FIELD(GetProfileSaveBlock(),s32 *,0x54);
 M2C_FIELD(&gOv010OnlineSession,u8 *,0xfa)=2 | M2C_FIELD(&gOv010OnlineSession,u8 *,0xfa);
 PublishPlayerStatusLocation(&gLocalPlayerStatus,0x6c);
 StartServingMatchSession(arg1&255,func_ov010_0222807c,arg3,Ov010Online_OnPeerJoined,arg5);
}
#pragma opt_dead_assignments reset
extern "C" void func_ov010_022292e4(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 arg5) {
 void func_ov010_02226a88(void);
 void ClearOnlineEventFlags(void);
 s32 Ov010_SetMatchCallback(s32);
 s32 Ov010_SetPeerJoinedCallback(s32);
 void Ov010Online_ClearStepFlag(s32);
 s32 GetEarnedRecordTierTotal(void);
 s32 GetRecordRank(void);
 s32 GetFavouriteRecordGroup(void);
 s32 GetFavouriteRecordIndex(void);
 void *GetProfileSaveBlock(void);
 M2C_UNK PublishPlayerStatusLocation(M2C_UNK *,s32);
 void StartMatch(s32,void *,s32,void *,s32);
 void func_ov010_0222807c(void);
 void Ov010Online_OnPeerJoined(void);
 extern Ov010Member data_ov010_0222c128;
 extern M2C_UNK gOv010PlayerRecords;
 extern u8 data_ov010_0222f1dc[];
 extern u16 gOv010OnlineSession;
 extern M2C_UNK gLocalPlayerStatus;
 Ov010CallbackFn c,a,b,d;
 u8 *p;
 func_ov010_02226a88();
 Ov010Online_ClearStepFlag(3);
 Ov010Online_ClearStepFlag(4);
 Ov010_SetMatchCallback(arg2);
 Ov010_SetPeerJoinedCallback(arg4);
 ClearOnlineEventFlags();
 a = *(Ov010CallbackFn *)&data_ov010_0222c128;
 b = a;
 c = b;
 for(p=(u8 *)&gOv010PlayerRecords;p!=data_ov010_0222f1dc;p+=0x6c) {
  (((Ov010Callback *)p)->*c)();
 }
 d = c;
 *(volatile u8 *)((u8 *)&gOv010OnlineSession + 0x107) = 1;
 *(volatile u8 *)((u8 *)&gOv010OnlineSession + 0x108) = (u8)arg0;
 GetEarnedRecordTierTotal();
 M2C_FIELD(&gOv010OnlineSession,u8 *,0x104)=GetRecordRank();
 M2C_FIELD(&gOv010OnlineSession,u8 *,0x105)=GetFavouriteRecordGroup();
 M2C_FIELD(&gOv010OnlineSession,u8 *,0x106)=GetFavouriteRecordIndex();
 M2C_FIELD(&gOv010OnlineSession,s32 *,0x100)=M2C_FIELD(GetProfileSaveBlock(),s32 *,0x54);
M2C_FIELD(&gOv010OnlineSession,u8 *,0xfa)=2|M2C_FIELD(&gOv010OnlineSession,u8 *,0xfa);
PublishPlayerStatusLocation(&gLocalPlayerStatus,0x6c);
StartMatch(arg1,(void *)func_ov010_0222807c,arg3,(void *)Ov010Online_OnPeerJoined,arg5);
}
#pragma cplusplus off

/* Install `callback` as the online session's matchmaking score callback
 * (OV010_SESSION_SCORE_CALLBACK); returns the callback it replaces. */
s32 SetOnlineScoreCallback(s32 callback) {
    extern u16 gOv010OnlineSession;
    s32 previous;

    previous = M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_SCORE_CALLBACK);
    M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_SCORE_CALLBACK) = callback;
    return previous;
}

/* Install `callback` as the running online match's event callback
 * (OV010_SESSION_CALLBACK) and return the callback it replaces. */
s32 Ov010_SetMatchEventCallback(s32 callback) {
    extern u16 gOv010OnlineSession;
    s32 previousCallback;
    previousCallback = M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_CALLBACK);
    M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_CALLBACK) = callback;
    return previousCallback;
}

/* Install `callback` as the online session's match event handler
 * (OV010_SESSION_MATCH_CALLBACK) and return the callback it replaces. */
s32 Ov010_SetMatchCallback(s32 callback) {
    extern u16 gOv010OnlineSession;
    s32 previousCallback;
    previousCallback = M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_MATCH_CALLBACK);
    M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_MATCH_CALLBACK) = callback;
    return previousCallback;
}

/* Install `callback` as the online session's peer-joined callback
 * (OV010_SESSION_PEER_JOINED_CALLBACK); returns the callback it replaces. */
s32 Ov010_SetPeerJoinedCallback(s32 callback) {
    extern u16 gOv010OnlineSession;
    s32 previous;

    previous = M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_PEER_JOINED_CALLBACK);
    M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_PEER_JOINED_CALLBACK) = callback;
    return previous;
}

/* Install `callback` as the online session's outgoing-packet callback
 * (OV010_SESSION_SEND_CALLBACK); returns the callback it replaces. */
s32 Ov010_SetSendCallback(s32 callback) {
    extern u16 gOv010OnlineSession;
    s32 previous;

    previous = M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_SEND_CALLBACK);
    M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_SEND_CALLBACK) = callback;
    return previous;
}

/* Install `handler` as the online session's received-packet handler
 * (OV010_SESSION_RECEIVE_HANDLER, offered each packet from a channel's receive
 * queue); returns the handler it replaces. */
s32 Ov010_SetReceiveHandler(s32 handler) {
    extern u16 gOv010OnlineSession;
    s32 previous;

    previous = M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_RECEIVE_HANDLER);
    M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_RECEIVE_HANDLER) = handler;
    return previous;
}

/* Install `handler` as the online session's assembled-message handler
 * (OV010_SESSION_MESSAGE_HANDLER); returns the handler it replaces. */
s32 SetOnlineMessageHandler(s32 handler) {
    extern u16 gOv010OnlineSession;
    s32 previous;

    previous = M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_MESSAGE_HANDLER);
    M2C_FIELD(&gOv010OnlineSession, s32 *, OV010_SESSION_MESSAGE_HANDLER) = handler;
    return previous;
}

s32 Ov010Online_CanLeaveSession(void) {
    s32 CanLeaveOnlineSession();
    return CanLeaveOnlineSession();
}

/* Leave the running online match: clear the session's match flag, publish the
 * local player's record to the peers and close the match connection. */
s32 Ov010Online_LeaveMatch(void) {
    M2C_UNK PublishPlayerStatusLocation(M2C_UNK *, s32);
    s32 LeaveOnlineSession();
    extern u16 gOv010OnlineSession;
    extern M2C_UNK gLocalPlayerStatus;

    if (Ov010Online_CanLeaveSession() == 0) return 0;
    M2C_FIELD(&gOv010OnlineSession, u8 *, OV010_SESSION_FLAGS) =
        M2C_FIELD(&gOv010OnlineSession, u8 *, OV010_SESSION_FLAGS) & ~OV010_SESSION_FLAG_MATCH;
    PublishPlayerStatusLocation(&gLocalPlayerStatus, ONLINE_PLAYER_RECORD_SIZE);
    return LeaveOnlineSession();
}

/* Ask the network layer to start the online match from the ready screen: drop
 * the previous match's running flag, publish the local player's record to the
 * peers and request the start (the empty callback acknowledges nothing). */
void Ov010Online_RequestMatchStart(void) {
    M2C_UNK PublishPlayerStatusLocation(M2C_UNK *, s32);
    void RequestMatchStart(void *, s32);
    extern u16 gOv010OnlineSession;
    extern M2C_UNK gLocalPlayerStatus;
    void Ov010Online_MatchStartNoop(void);
    M2C_FIELD(&gOv010OnlineSession, u8 *, OV010_SESSION_FLAGS) =
        M2C_FIELD(&gOv010OnlineSession, u8 *, OV010_SESSION_FLAGS) & ~OV010_SESSION_FLAG_MATCH;
    PublishPlayerStatusLocation(&gLocalPlayerStatus, ONLINE_PLAYER_RECORD_SIZE);
    RequestMatchStart(&Ov010Online_MatchStartNoop, 0);
}

/* Allocate `size` bytes from the online overlay's heap, 32-byte aligned: the
 * block every queued online packet and session record is built in. */
void *Ov010_AllocBlock32(s32 size) {
    s32 Ov010_AllocBlock(s32, s32, s32);
    return (void *)Ov010_AllocBlock(0, size, ONLINE_BLOCK_ALIGNMENT);
}

/* Free a queued online packet: its payload bytes plus the 12-byte header. */
void Ov010Online_FreePacket(Ov010Packet *packet) {
    M2C_UNK Ov010_FreeBlock(M2C_UNK, void *, s32);

    Ov010_FreeBlock(0, packet, packet->size + ONLINE_PACKET_HEADER_SIZE);
}

/* Write a queued online packet's 12-byte header (magic, kind, channel/flags
 * nibbles, id and payload size), then copy `size` payload bytes in after it. */
Ov010Packet *Ov010Online_InitPacketHeader(void *packet, u8 kind, s32 channel, s32 flags, void *payload, s32 size, u16 id) {
    M2C_UNK MI_CpuCopy8(s32, s32, M2C_UNK);
    Ov010Packet *h = (Ov010Packet *)packet;
    h->magic = ONLINE_PACKET_MAGIC;
    h->kind = kind;
    M2C_FIELD(packet, u8 *, 5) = (M2C_FIELD(packet, u8 *, 5) & ~0xF) | (channel & 0xF);
    M2C_FIELD(packet, u8 *, 5) = (M2C_FIELD(packet, u8 *, 5) & ~0xF0) | ((flags & 0xF) << 4);
    h->id = id;
    h->size = size;
    if (payload != 0 && size != 0) MI_CpuCopy8((s32)payload, (s32)packet + ONLINE_PACKET_HEADER_SIZE, size);
    return h;
}

s32 QueueOnlineLinkPacket(u8 arg0, void *arg1, s32 arg2, u16 arg3) {
    s32 IsOnlineSessionFlagSet(s32);
    u16 GetOnlinePeerMask();
    s32 GetOnlineTransportPlayerId();
    M2C_UNK Ov010_AllocBlock(M2C_UNK, s32, s32);
    void MI_CpuFill8(void *, s32, s32);
    extern u16 gOv010OnlineSession;
    QueueNode *node;
    s32 mode;
    u32 saved;
    u32 previous;
    s32 ret;
    u32 result;

    if (IsOnlineSessionFlagSet(3) == 0) return 0;
    arg3 &= GetOnlinePeerMask();
    arg3 = (u16)(arg3 & (-1 ^ (1 << GetOnlineTransportPlayerId())));
    mode = GetOnlineTransportPlayerId();
    previous = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    saved = previous;
    node = (QueueNode *)Ov010_AllocBlock(0, arg2 + 0x10, 0x20);
    if (node == NULL) {
        volatile u16 *ime = (volatile u16 *)0x04000208;
        u32 restore = *(volatile u32 *)&saved;
        u32 ignored = *ime;
        *ime = restore;
        (void)ignored;
        ret = 0;
    } else {
        s32 queued;
        MI_CpuFill8(node, 0, 0x10);
        Ov010Online_InitPacketHeader((u8 *)node + 4, arg0, mode, 0, (s32)arg1, arg2, arg3);
        if (M2C_FIELD(&gOv010OnlineSession, QueueNode **, 0x64) == NULL) {
            M2C_FIELD(&gOv010OnlineSession, QueueNode **, 0x64) = node;
            M2C_FIELD(&gOv010OnlineSession, QueueNode **, 0x60) = node;
        } else {
            M2C_FIELD(M2C_FIELD(&gOv010OnlineSession, QueueNode **, 0x64), QueueNode **, 0) = node;
            M2C_FIELD(&gOv010OnlineSession, QueueNode **, 0x64) = node;
        }
        previous = *(volatile u32 *)&saved;
        queued = M2C_FIELD(&gOv010OnlineSession, s32 *, 0x68);
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x68) = queued + 1;
        (void)*(volatile u16 *)0x04000208;
        ret = 1;
        *(volatile u16 *)0x04000208 = previous;
    }
    result = ret;
    if (result == 0) return 0;
    return 1;
}

s32 QueueOnlinePacket(u8 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 IsOnlineSessionFlagSet(s32);
    u16 GetOnlinePeerMask();
    s32 GetOnlineTransportPlayerId();
    M2C_UNK Ov010_AllocBlock(s32, s32, s32);
    void MI_CpuFill8(void *, s32, s32);
    extern u16 gOv010OnlineSession;
    void *node;
    s32 mode;
    volatile s32 saved;
    u16 v;
    s32 ret;

    if (IsOnlineSessionFlagSet(3) == 0) return 0;
    arg3 = arg3 & GetOnlinePeerMask();
    v = (u16)(arg3 & (-1 ^ (1 << GetOnlineTransportPlayerId())));
    mode = GetOnlineTransportPlayerId();
    saved = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    node = (void *)Ov010_AllocBlock(0, arg2 + 0x10, 0x20);
    if (node == NULL) {
        (void)*(volatile u16 *)0x04000208;
        *(volatile u16 *)0x04000208 = saved;
        ret = 0;
    } else {
        MI_CpuFill8(node, 0, 0x10);
        Ov010Online_InitPacketHeader((u8 *)node + 4, arg0, mode, 1, (s32)arg1, arg2, v);
        if (M2C_FIELD(&gOv010OnlineSession, void **, 0x64) == 0) {
            M2C_FIELD(&gOv010OnlineSession, void **, 0x64) = node;
            M2C_FIELD(&gOv010OnlineSession, void **, 0x60) = node;
        } else {
            M2C_FIELD(M2C_FIELD(&gOv010OnlineSession, void **, 0x64), void **, 0) = node;
            M2C_FIELD(&gOv010OnlineSession, void **, 0x64) = node;
        }
        M2C_FIELD(&gOv010OnlineSession, s32 *, 0x68)++;
        (void)*(volatile u16 *)0x04000208;
        *(volatile u16 *)0x04000208 = saved;
        ret = 1;
    }
    return ret != 0;
}

/* Whether the online session's outbound packet queue is empty.  an empty result
 * counts as empty.  The queue head (ONLINE_SESSION_QUEUE) is read with
 * interrupts disabled so a queued packet cannot slip in mid-check. */
s32 Ov010Online_IsSendQueueEmpty(void) {
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    extern u16 gOv010OnlineSession;
    s32 result;
    u16 savedIme;
    if (IsOnlineSessionFlagSet(3) == 0) return 1;
    result = 0;
    savedIme = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    if (M2C_FIELD(&gOv010OnlineSession, s32 *, ONLINE_SESSION_QUEUE) == 0) result = 1;
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = savedIme;
    return result;
}

#pragma cplusplus on
static inline unsigned int ReadQueuedPayloadSize(QueueNode **entry) {
    Ov010InterruptGuard guard;
    if (*entry == NULL)
        return 0;
    return (*entry)->size;
}
#pragma cplusplus off
extern struct QueueNode *data_ov010_0222ef88;
#pragma cplusplus on
/* Bytes needed to pop the next packet queued for `channel`: 0 when that
 * channel's queue (the 12-byte entry data_ov010_0222ef88[channel]) is empty,
 * otherwise the queued payload size plus the 12-byte Ov010Packet header. */
extern "C" unsigned int Ov010Online_GetQueuedPacketSize(unsigned int channel) {
    Ov010InterruptGuard guard;
    QueueNode **queue = (QueueNode **)((u8 *)&data_ov010_0222ef88 + channel * 12);
    if (*queue == NULL)
        return 0;
    return ReadQueuedPayloadSize(queue) + 12;
}
#pragma cplusplus off
s32 func_ov010_02229920(s32 a, void *b) {
extern QueueNode *data_ov010_0222ef88;
extern s32 data_ov010_0222ef8c, data_ov010_0222ef90;
QueueNode *p;
s32 offset=a*12;
volatile u32 saved;
u32 previous=*(volatile u16 *)0x4000208;
s32 result;

QueueNode **head;
head=(QueueNode **)((char *)&data_ov010_0222ef88+offset);
*(volatile u16 *)0x4000208=0;
p=*head;
saved=previous;
if(!p){(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=previous;return 0;}
Ov010Online_InitPacketHeader(b,p->kind,p->low,p->high,(s32)(p+1),p->size,p->value);
if(!(*head=p->next))M2C_FIELD(&data_ov010_0222ef8c,s32 *,offset)=0;
Ov010_FreeBlock(0,p,p->size+16);
previous=saved;
M2C_FIELD(&data_ov010_0222ef90,s32 *,offset)--;
(void)*(volatile u16 *)0x4000208;
result=M2C_FIELD(b,s32 *,8)+12;
*(volatile u16 *)0x4000208=previous;
return result;
}

s32 GetOnlineTransportPlayerId(void) {
    s32 GetLocalPlayerId();
    return GetLocalPlayerId();
}

u8 GetOnlineLocalPlayerSlot(void) {
    extern u16 gOv010OnlineSession;
    return M2C_FIELD(&gOv010OnlineSession, u8 *, 0xFB);
}

u16 GetOnlinePeerMask(void) {
    s32 GetOnlinePlayerMask();
    return (u16)GetOnlinePlayerMask();
}

s32 GetLinkPlayerCount(void) {
    return 2;
}

s32 GetConnectedPlayerCount(void) {
    s32 GetNetSessionPlayerCount();
    return GetNetSessionPlayerCount() & 0xFF;
}

void ClearOnlineEventFlags(void) {
    extern u16 gOv010OnlineSession;
    gOv010OnlineSession = 0;
}

u16 GetOnlineEventFlags(void) {
    extern u16 gOv010OnlineSession;
    return gOv010OnlineSession;
}

/* Online overlay's Link_SendPacket path: stage a buffer of `size` bytes as this
 * console's player panel in the online local-player record. */
void StageOnlineLocalPlayerRecord(void *source, u32 size) {
    M2C_UNK CopyLocalPlayerPanel(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK gLocalPlayerStatus;
    CopyLocalPlayerPanel(&gLocalPlayerStatus, source, size);
}

/* Publish the local player's status: while matchmaking has started, store it in
 * the online player record array; once the session is running, also record it
 * under the local player's id and broadcast it to every peer. */
s32 PublishLocalPlayerStatus(void) {
extern M2C_UNK gLocalPlayerStatus;
if(IsOnlineSessionFlagSet(OV010_FLAG_MATCHMAKING)) {
if(!PublishPlayerStatusLocation(&gLocalPlayerStatus,ONLINE_PLAYER_RECORD_SIZE))return 0;
}
if(IsOnlineSessionFlagSet(OV010_FLAG_RUNNING)) {
SetOnlinePlayerRecord(GetOnlineTransportPlayerId(),&gLocalPlayerStatus);
QueueOnlineLinkPacket(ONLINE_PACKET_PLAYER_STATUS,&gLocalPlayerStatus,ONLINE_PLAYER_RECORD_SIZE,0xffff);
}
return 1;
}

M2C_UNK *GetLocalPlayerStatus(void) {
    extern M2C_UNK gLocalPlayerStatus;
    return &gLocalPlayerStatus;
}

/* Online player record of `playerId`: NULL when that player is not a connected
 * peer or its record is not marked connected. */
s32 GetOnlinePlayerRecord(s32 playerId) {
extern M2C_UNK gOv010PlayerRecords;
s32 record;
if(!(GetOnlinePeerMask()&(1<<playerId)))return 0;
record=(s32)&gOv010PlayerRecords+playerId*ONLINE_PLAYER_RECORD_SIZE;
if(!(M2C_FIELD(record,u8 *,ONLINE_PLAYER_FLAGS)&ONLINE_PLAYER_FLAG_CONNECTED))record=0;
return record;
}

/* Address of the online player record kept for player slot `slotIndex`. */
s32 GetOnlinePlayerSlot(s32 slotIndex) {
    extern M2C_UNK gOv010PlayerRecords;
    return (ONLINE_PLAYER_RECORD_SIZE * slotIndex) + (s32) &gOv010PlayerRecords;
}

/* Copy the local player's network panel record (the ONLINE_PLAYER_PANEL block of
 * the player status) into `buffer`, `length` bytes, and return `buffer`; 0 when
 * there is no local player status. */
s32 CopyOnlineLocalPlayerRecord(s32 buffer, M2C_UNK length) {
    M2C_UNK MI_CpuCopy8(s32, s32, M2C_UNK);
    s32 panel;

    panel = GetLocalPlayerStatus();
    if (panel == 0) {
        return 0;
    }
    MI_CpuCopy8(panel + ONLINE_PLAYER_PANEL, buffer, length);
    return buffer;
}

/* Network panel record of the active online player (the record of the player
 * this console plays as), or NULL when that player has no connected record. */
s32 GetActiveOnlinePlayerRecord(void) {
    s32 GetOnlinePlayerRecord();
    s32 record;

    record = GetOnlinePlayerRecord();
    if (record != 0) {
        return record + ONLINE_PLAYER_PANEL;
    }
    return 0;
}

/* Copy the network panel record (the ONLINE_PLAYER_PANEL block) of player
 * `playerId` into `buffer`, `length` bytes, and return `buffer`; 0 when that
 * player has no connected record. */
s32 CopyActiveOnlinePlayerRecord(s32 playerId, s32 buffer, s32 length) {
    M2C_UNK MI_CpuCopy8(s32, s32, M2C_UNK);
    s32 record;

    record = GetOnlinePlayerRecord(playerId);
    if (record == 0) {
        return 0;
    }
    MI_CpuCopy8(record + ONLINE_PLAYER_PANEL, buffer, length);
    return buffer;
}

/* Whether this console is the online session's host: the host is the transport
 * player with id 0 (see IsOnlineGuest for the other side of the check). */
s32 IsOnlineSessionHost(void) {
    if (GetOnlineTransportPlayerId() == 0) {
        return 1;
    }
    return 0;
}

/* Whether this console joins the online session as a guest rather than hosting
 * it: any transport player id other than 0 (see IsOnlineSessionHost). */
s32 IsOnlineGuest(void) {
    if (GetOnlineTransportPlayerId() != 0) {
        return 1;
    }
    return 0;
}

/* Fills the online match-start record for match `matchId`: marks this console's
 * acknowledgement bit, records it as the session's start record and, when this
 * console is the host, sends the start request to the peers. */
void Ov010Online_SubmitStartRecord(void *record, s32 matchId) {
    extern u16 gOv010OnlineSession;
    if (!IsOnlineSessionFlagSet(OV010_FLAG_RUNNING)) return;
    M2C_FIELD(record, s32 *, OV010_START_RECORD_ID) = matchId;
    M2C_FIELD(record, u16 *, OV010_START_RECORD_ACKS) = 1 << GetOnlineTransportPlayerId();
    M2C_FIELD(&gOv010OnlineSession, void **, OV010_SESSION_START_RECORD) = record;
    if (!IsOnlineSessionHost()) return;
    QueueOnlineLinkPacket(ONLINE_PACKET_START_REQUEST, M2C_FIELD(&gOv010OnlineSession, void **, OV010_SESSION_START_RECORD), 8, 0xffff);
}

/* Reports whether the online match-start request has been acknowledged by every
 * connected player: there must be a start record whose ack mask covers the
 * connected peers, the session must be running, there must be no network error
 * and this console must be connected as player 0.  When that is not the case,
 * the session's host re-sends the pending start packet to everyone. */
s32 Ov010Online_IsStartAcknowledged(void) {
    u16 GetOnlinePeerMask();
    s32 IsOnlineSessionFlagSet(s32);
    s32 GetNetErrorCode();
    s32 IsOnlineSessionHost();
    extern u16 gOv010OnlineSession;
    s32 peerMask;
    s32 acknowledged;
    s32 netError;

    peerMask = GetOnlinePeerMask();
    acknowledged = 0;
    if (M2C_FIELD(&gOv010OnlineSession, void **, OV010_SESSION_START_RECORD) != NULL &&
        peerMask != (peerMask & M2C_FIELD(M2C_FIELD(&gOv010OnlineSession, void **, OV010_SESSION_START_RECORD), u16 *, OV010_START_RECORD_ACKS))) acknowledged = 1;
    if (IsOnlineSessionFlagSet(3) == 0) acknowledged = 0;
    netError = (GetNetErrorCode() != 0);
    if (netError) acknowledged = 0;
    if (!(peerMask & 1)) acknowledged = 0;
    if (acknowledged == 0 && IsOnlineSessionHost() != 0)
        QueueOnlineLinkPacket(3, M2C_FIELD(&gOv010OnlineSession, void **, OV010_SESSION_START_RECORD), 8, 0xFFFF);
    return acknowledged;
}

