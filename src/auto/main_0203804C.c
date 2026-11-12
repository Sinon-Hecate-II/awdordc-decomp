/* 18 functions from 0x0203804C to 0x02038F88 (main), found by ds-decomp. */
#include "common.h"

/* Initialize the global WFC session object: install the state callbacks, set up its transport,
   upload and connection sub-objects from the NAS config, and copy the game name and password
   into their global buffers. */
void InitNetSession(void *session,void *config,s32 gameId,char *gameName,char *gamePassword,s32 rxBufSize,s32 txBufSize,s32 userData,s32 timeout){
extern void *gNetSession;
extern u8 gSessionGameName[];
extern u8 gSessionGamePassword[];
void func_020375fc(void);
void ResetPlayerSlots(void);
void func_0203d910(void);
void func_02039838(void);
void func_02039844(void);
void func_02039b9c(void);
void func_02039478(void);
void func_02039be4(void *,void *,void *,s32,s32,void *,void *,s32);
void func_0203a9dc(void *,void *,void *,s32,s32);
void InitConnection(void *,void *,void *,void *,void *,void *,s32,s32);
void func_02044708(void *);
u32 len;
gNetSession=session;
func_020375fc();
M2C_FIELD(gNetSession,s32 *,0)=0;
M2C_FIELD(gNetSession,s32 *,4)=(s32)func_0203d910;
M2C_FIELD(gNetSession,s32 *,8)=(s32)func_02039838;
M2C_FIELD(gNetSession,s32 *,12)=(s32)func_02039844;
M2C_FIELD(gNetSession,s32 *,16)=(s32)func_02039b9c;
M2C_FIELD(gNetSession,s32 *,20)=rxBufSize?rxBufSize:0x2000;
M2C_FIELD(gNetSession,s32 *,24)=txBufSize?txBufSize:0x2000;
M2C_FIELD(gNetSession,s32 *,28)=0;
M2C_FIELD(gNetSession,s32 *,32)=(s32)config;
M2C_FIELD(gNetSession,s32 *,36)=0;
M2C_FIELD(gNetSession,s32 *,40)=0;
M2C_FIELD(gNetSession,u8 *,44)=0;
M2C_FIELD(gNetSession,u8 *,45)=0;
M2C_FIELD(gNetSession,s32 *,100)=0;
M2C_FIELD(gNetSession,s32 *,104)=(s32)gSessionGameName;
M2C_FIELD(gNetSession,s32 *,108)=(s32)gSessionGamePassword;
M2C_FIELD(gNetSession,s32 *,112)=0;M2C_FIELD(gNetSession,s32 *,116)=0;M2C_FIELD(gNetSession,s32 *,120)=0;M2C_FIELD(gNetSession,s32 *,124)=0;M2C_FIELD(gNetSession,s32 *,128)=0;M2C_FIELD(gNetSession,s32 *,132)=0;M2C_FIELD(gNetSession,s32 *,136)=0;M2C_FIELD(gNetSession,s32 *,140)=0;M2C_FIELD(gNetSession,s32 *,144)=0;M2C_FIELD(gNetSession,s32 *,148)=0;
ResetPlayerSlots();
func_02039be4((u8 *)gNetSession+0x98,config,(u8 *)gNetSession+0x1c,gameId,M2C_FIELD(config,s32 *,0x24),(u8 *)gNetSession+0x2e,func_02039478,0);
func_0203a9dc((u8 *)gNetSession+0x318,(u8 *)gNetSession+0x1c,(u8 *)gNetSession+0x2e,userData,timeout);
InitConnection((u8 *)gNetSession+0x374,(u8 *)gNetSession+0x1c,gNetSession,(u8 *)gNetSession+4,gSessionGameName,gSessionGamePassword,userData,timeout);
func_02044708((u8 *)gNetSession+0x7f8);
if((u32)StringLength(gameName)>=0x100)len=255;else len=StringLength(gameName);
MI_CpuCopy8(gameName,gSessionGameName,len);
gSessionGameName[len]=0;
if((u32)StringLength(gamePassword)>=0x100)len=255;else len=StringLength(gamePassword);
MI_CpuCopy8(gamePassword,gSessionGamePassword,len);
gSessionGamePassword[len]=0;
}

void func_020382d0(void) {
    extern void *gNetSession;
    void Qr2_DestroyConnection(void *resource);
    void func_020614b0(void *resource);
    void func_0203bd0c(void);
    void func_02058c14(void);
    s32 func_0204db84(void *channel, s32 a, s32 b, s32 c);
    void func_0204db50(void *channel);
    void func_0204db34(void *channel);
    void func_02039e04(void);
    void func_0203b088(void);
    void func_0203e4e0(void);
    void func_020449dc(void);
    void func_0205ad60(void *resource);

    if (!gNetSession) return;
    if (M2C_FIELD(gNetSession, void **, 0x384)) {
        Qr2_DestroyConnection(M2C_FIELD(gNetSession, void **, 0x384));
        M2C_FIELD(gNetSession, void **, 0x384) = 0;
    }
    M2C_FIELD(gNetSession, u8 *, 0x38C) = 0;
    if (M2C_FIELD(gNetSession, void **, 0x458)) {
        func_020614b0(M2C_FIELD(gNetSession, void **, 0x458));
        M2C_FIELD(gNetSession, void **, 0x458) = 0;
    }
    func_0203bd0c();
    func_02058c14();
    if (M2C_FIELD(gNetSession, s32 *, 0x1C)) {
        func_0204db84(gNetSession + 0x1C, 0, 0, 0);
        func_0204db84(gNetSession + 0x1C, 3, 0, 0);
        func_0204db84(gNetSession + 0x1C, 1, 0, 0);
        func_0204db84(gNetSession + 0x1C, 2, 0, 0);
        func_0204db50(gNetSession + 0x1C);
        func_0204db34(gNetSession + 0x1C);
        M2C_FIELD(gNetSession, s32 *, 0x1C) = 0;
    }
    func_02039e04();
    func_0203b088();
    func_0203e4e0();
    func_020449dc();
    if (M2C_FIELD(gNetSession, void **, 0)) {
        func_0205ad60(M2C_FIELD(gNetSession, void **, 0));
        M2C_FIELD(gNetSession, void **, 0) = 0;
    }
    gNetSession = 0;
}

/* Advances the online connection state, installs callbacks after the availability check, and releases deferred network resources. */
void func_02038438(void) {
    extern void *gNetSession;
    extern M2C_UNK func_02039698;
    extern M2C_UNK func_020396d0;
    extern M2C_UNK func_0203ad24;
    extern M2C_UNK func_0203adcc;
    s32 func_02037bc4(void);
    void func_02039200(void);
    s32 HasNetError(void);
    s32 func_0204837c(void);
    s32 func_020392b8(s32);
    void SetNetState(s32);
    void func_02039c68(void);
    void func_02039ca0(void);
    void func_02039db4(s32, s32);
    void func_0203aabc(void);
    void func_0203cb38(s32);
    void UpdateTransferSlots(void);
    s32 func_0204db04(s32, s32, s32);
    s32 func_0204db84(void *, s32, s32, s32);
    void Qr2_DestroyConnection(void *);

    if (func_02037bc4()) func_02039200();
    if (!gNetSession || M2C_FIELD(gNetSession, s32 *, 0x24) == 0) return;
    if (HasNetError() != 0) return;
    switch (M2C_FIELD(gNetSession, s32 *, 0x24)) {
    case 1:
        switch (func_0204837c()) {
        case 1:
            if (func_020392b8(func_0204db04((s32)gNetSession + 0x1c, M2C_FIELD(gNetSession, s32 *, 0xa0), 0))) return;
            if (func_020392b8(func_0204db84((u8 *)gNetSession + 0x1c, 0, (s32)&func_02039698, 0))) return;
            if (func_020392b8(func_0204db84((u8 *)gNetSession + 0x1c, 3, (s32)&func_020396d0, 0))) return;
            if (func_020392b8(func_0204db84((u8 *)gNetSession + 0x1c, 1, (s32)&func_0203ad24, 0))) return;
            if (func_020392b8(func_0204db84((u8 *)gNetSession + 0x1c, 2, (s32)&func_0203adcc, 0))) return;
            SetNetState(2);
            func_02039c68();
            break;
        case 2:
            func_02039db4(3, -0x4e8e);
            return;
        case 3:
            func_02039db4(4, -0x4e85);
            return;
        }
        break;
    case 2:
        func_02039ca0();
        break;
    case 3:
    case 4:
        func_0203aabc();
        func_0203cb38(0);
        break;
    case 5:
        func_0203cb38(1);
        func_0203aabc();
        break;
    case 6:
        UpdateTransferSlots();
        func_0203aabc();
        if (M2C_FIELD(gNetSession, volatile u8 *, 0x389) == 2 || M2C_FIELD(gNetSession, volatile u8 *, 0x389) == 3) func_0203cb38(1);
        else if (M2C_FIELD(gNetSession, s32 *, 0) != 0) func_0203cb38(0);
        break;
    }
    if (M2C_FIELD(gNetSession, u8 *, 0x38c) == 1) {
        if (M2C_FIELD(gNetSession, s32 *, 0x384) != 0) {
            Qr2_DestroyConnection(M2C_FIELD(gNetSession, s32 *, 0x384));
            M2C_FIELD(gNetSession, s32 *, 0x384) = 0;
        }
        M2C_FIELD(gNetSession, u8 *, 0x38c) = 0;
    }
}

s32 func_02038688(u16 *text,s32 unused,s32 a,s32 b){
extern void *gNetSession;
s32 HasNetError(void); u32 Utf16StringLength(u16 *);
void FillU16(s32,void *,s32); void func_02007e20(void *,void *,s32);
s32 func_02037a0c(void);void func_02039db4(s32,s32);void SetNetState(s32);void InitServiceAvailabilityQuery(s32);
u32 n;
if(!text)return 0;
if(HasNetError() || M2C_FIELD(gNetSession,s32 *,36)!=0)return 0;
M2C_FIELD(gNetSession,s32 *,112)=a;
M2C_FIELD(gNetSession,s32 *,116)=b;
if(!text || !*text)n=0;
else{
FillU16(0,(u8 *)gNetSession+46,52);
if(Utf16StringLength(text)>25)n=25;else n=Utf16StringLength(text);
func_02007e20(text,(u8 *)gNetSession+46,n*2);
}
M2C_FIELD((u8 *)gNetSession+n*2,u16 *,46)=0;
if(func_02037a0c()!=4){func_02039db4(2,-60010);return 1;}
SetNetState(1);InitServiceAvailabilityQuery(M2C_FIELD(gNetSession,s32 *,104));return 1;
}

s32 func_02038790(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g){s32 HasNetError(void);void SetNetState(s32);void func_0203ac20(void *,void *,void *,s32,s32,s32,s32,s32);extern M2C_UNK func_020394d8;extern void *gNetSession;s32 state;if(HasNetError() || (state=M2C_FIELD(gNetSession,s32 *,36))<3 || state==4)return 0;M2C_FIELD(gNetSession,s32 *,120)=b;M2C_FIELD(gNetSession,s32 *,124)=c;SetNetState(4);func_0203ac20(gNetSession+224,gNetSession+480,&func_020394d8,0,d,e,f,g);return 1;}

s32 func_02038838(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f){s32 HasNetError(void);void ResetPlayerSlots(void);void SetNetState(s32);void StartHostMatch(s32,s32,void *,s32,s32,s32);extern M2C_UNK func_02039520;extern void *gNetSession;if(HasNetError() || M2C_FIELD(gNetSession,s32 *,36)!=3)return 0;ResetPlayerSlots();M2C_FIELD(gNetSession,s32 *,128)=c;M2C_FIELD(gNetSession,s32 *,132)=d;SetNetState(5);StartHostMatch((u8)(a-1),b,&func_02039520,0,e,f);return 1;}

/* Prepares the online session to join a match (it must be idle in the lobby),
   stores the event callback, and starts the join: with the supplied player list
   if there is one, otherwise with a shuffled list of every player slot. */
s32 func_020388d8(s32 playerList, s32 listLength, s32 matchType, s32 flag, s32 eventCallback, s32 eventData, s32 resultCallback, s32 resultData) {
    s32 HasNetError(void); void ResetPlayerSlots(void); void SetNetState(s32);
    s32 func_0203ae50(void); u32 RandomBelow(u32);
    void StartJoinMatch(s32,s32,u8,s32,void *,s32,s32,s32);
    extern void *gNetSession; extern M2C_UNK func_02039520;
    u8 shuffledSlots[64]; u8 slotPool[64];
    if (HasNetError() != 0 || M2C_FIELD(gNetSession,s32 *,0x24) != NET_STATE_READY) return 0;
    ResetPlayerSlots();
    M2C_FIELD(gNetSession,s32 *,0x80)=eventCallback;
    M2C_FIELD(gNetSession,s32 *,0x84)=eventData;
    SetNetState(NET_STATE_STARTING);
    if(playerList != 0) {
        StartJoinMatch(playerList,listLength,(u8)(matchType-1),flag,&func_02039520,0,resultCallback,resultData);
    } else {
        u32 pick; u8 *shift; s32 slot, out;
        listLength=0; slot=listLength;
        while(slot<func_0203ae50()) { slotPool[slot]=(u8)slot; slot=(slot+1)&255; }
        out=0;
        while(out<func_0203ae50()) {
            pick=RandomBelow(func_0203ae50()-out);
            shuffledSlots[out]=slotPool[pick]; shift=&slotPool[pick]; listLength++;
            while(pick<func_0203ae50()-out-1) { *shift=shift[1]; shift++; pick++; }
            out=(out+1)&255;
        }
        StartJoinMatch((s32)shuffledSlots,listLength,(u8)(matchType-1),flag,&func_02039520,0,resultCallback,resultData);
    }
    return 1;
}

s32 func_02038a84(s32 a,s32 b,s32 c,s32 d,s32 e){s32 HasNetError(void);void ResetPlayerSlots(void);void SetNetState(s32);void func_0203c878(s32,void *,s32,s32,s32);extern M2C_UNK func_02039520;extern void *gNetSession;if(HasNetError() || M2C_FIELD(gNetSession,s32 *,36)!=3)return 0;ResetPlayerSlots();M2C_FIELD(gNetSession,s32 *,136)=b;M2C_FIELD(gNetSession,s32 *,140)=c;M2C_FIELD(gNetSession,u8 *,44)=0;SetNetState(5);func_0203c878((u8)(a-1),&func_02039520,0,d,e);return 1;}

/* Looks up the local player's match record, verifies its SCM and SCN fields,
   then either starts the online match or reports the failure through the
   event callback and the global network error record. */
s32 StartMatch(s32 playerSlot, s32 eventCallback, s32 eventData, s32 mode, s32 matchData) {
    s32 HasNetError(void);
    void ResetPlayerSlots(void);
    void SetNetState(s32);
    s32 GetSessionPlayerId(s32);
    s32 func_0204e364(void **, s32);
    s32 func_0204e2f4(void **, s32, s32 *);
    s32 func_0204e1b4(void **, s32, void *);
    s32 ExtractKeyValue(s8 *, s8 *, s8 *, s32);
    s32 func_0206abd8(s8 *, s32, s32);
    void func_0203c920(s32, M2C_UNK, M2C_UNK, s32, s32);
    void SetNetError(s32, s32);
    void func_0203af50(s32, void *, s32);
    extern void *gNetSession;
    extern M2C_UNK gKeySCM;
    extern M2C_UNK gKeySCN;
    extern M2C_UNK gEmptyString;
    extern M2C_UNK func_02039520;

    s32 status = mode;
    MatchPlayerInfo player;
    s32 playerIndex = -1;
    u8 valueText;
    u8 scmValue;
    u8 scnValue;
    s32 playerId;

    if (HasNetError() != 0 || M2C_FIELD(gNetSession, s32 *, 0x24) != NET_STATE_READY) return 0;

    ResetPlayerSlots();
    M2C_FIELD(gNetSession, s32 *, 0x88) = eventCallback;
    M2C_FIELD(gNetSession, s32 *, 0x8C) = eventData;
    SetNetState(NET_STATE_STARTING);

    playerId = GetSessionPlayerId(playerSlot);
    if (playerId == 0 || func_0204e364((void **)((char *)gNetSession + 0x1C), playerId) == 0) {
        status = 0x0B;
        goto tail;
    }

    func_0204e2f4((void **)((char *)gNetSession + 0x1C), playerId, &playerIndex);
    func_0204e1b4((void **)((char *)gNetSession + 0x1C), playerIndex, &player);

    if (player.status != 6) {
        status = 0x0B;
        goto tail;
    }

    valueText = 0x30;
    ExtractKeyValue(&gKeySCM, (s8 *)&valueText, (s8 *)player.fields, 0x2F);
    scmValue = (u8)func_0206abd8((s8 *)&valueText, 0, 10);

    ExtractKeyValue(&gKeySCN, (s8 *)&valueText, (s8 *)player.fields, 0x2F);
    scnValue = (u8)func_0206abd8((s8 *)&valueText, 0, 10);
    if (scnValue == scmValue) {
        status = 0x0D;
        goto tail;
    }

    func_0203c920(playerId, &func_02039520, 0, status, matchData);
    return 1;

tail:
    SetNetError(status, 0);
    {
        void *session = gNetSession;
        void *notify = *(void **)((char *)session + 0x88);
        ((void (*)(s32, s32, s32, s32, s32, s32))notify)(status, 0, 1, 0, 0, *(s32 *)((char *)session + 0x8C));
    }
    if (gNetSession != 0) {
        if (M2C_FIELD(gNetSession, s32 *, 0x24) == NET_STATE_STARTING) {
            SetNetState(NET_STATE_READY);
            func_0203af50(1, &gEmptyString, 0);
        }
    }
    return 1;
}

s32 func_02038d14(s32 a,s32 b){extern void *gNetSession;if(!gNetSession)return 0;M2C_FIELD(gNetSession,s32 *,144)=a;M2C_FIELD(gNetSession,s32 *,148)=b;return 1;}

s32 func_02038d40(void){extern void *gNetSession;extern M2C_UNK gEmptyString;s32 HasNetError(void);void func_0203af50(s32,void *,s32);void func_0203bd0c(void);void SetNetState(s32);void func_0205afec(void *);s32 state;if(!gNetSession || HasNetError() || ((state=M2C_FIELD(gNetSession,s32 *,0x24))!=5 && state!=6))return -1;if(!M2C_FIELD(gNetSession,u8 *,0x381)){func_0203af50(1,&gEmptyString,0);func_0203bd0c();SetNetState(3);return 1;}M2C_FIELD(gNetSession,u8 *,0x2d)=1;func_0205afec(M2C_FIELD(gNetSession,void **,0));M2C_FIELD(gNetSession,u8 *,0x2d)=0;return 0;}

s32 func_02038de4(s32 a){extern void *gNetSession;s32 HasNetError(void);void *FindPlayerConnection(s32);void func_0205afcc(void *);s32 state;void *p;if(!gNetSession || HasNetError() || ((state=M2C_FIELD(gNetSession,s32 *,0x24))!=5 && state!=6))return -1;p=FindPlayerConnection(a);if(!p)return -2;func_0205afcc(p);return 0;}

s32 func_02038e4c(void){extern void *gNetSession;s32 func_0203e2c4(void);s32 func_0203e2a4(void);if(!gNetSession)return 0;if(M2C_FIELD(gNetSession,volatile u8 *,0x389)==2 || M2C_FIELD(gNetSession,volatile u8 *,0x389)==3)return func_0203e2c4()+1;return func_0203e2a4()+1;}

u8 GetLocalPlayerId(void) {
    extern void *gNetSession;
    if (gNetSession != NULL) {
        return M2C_FIELD(gNetSession, u8 *, 0x2C);
    }
    return 0U;
}

s32 GetActiveConnectionList(s32 *a){extern void *gNetSession;s32 func_0203e36c(s32 *);s32 func_0203e338(s32 *);if(!gNetSession)return 0;*a=(s32)(gNetSession+0x644);if(M2C_FIELD(gNetSession,volatile u8 *,0x389)==2 || M2C_FIELD(gNetSession,volatile u8 *,0x389)==3)return func_0203e36c(a);return func_0203e338(a);}

s32 func_02038f00(void){extern void *gNetSession;s32 GetActiveConnectionList(s32 *);s32 func_02039284(s32,s32);s32 a,b;if(!gNetSession)return 0;b=GetActiveConnectionList(&a);return func_02039284(a,b);}

s32 IsConnectionActive(s32 a){extern void *gNetSession;s32 func_020391b8(s32);if(!gNetSession)return 0;if(!(M2C_FIELD(gNetSession,u32 *,0x664)&(1<<a)))return 0;return func_020391b8(a);}

s32 func_02038f6c(void) {
    extern void *gNetSession;
    if (gNetSession != NULL) {
        return M2C_FIELD(gNetSession, s32 *, 0x24);
    }
    return 0;
}

