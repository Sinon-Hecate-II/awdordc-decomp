/* 25 functions from 0x0218851C to 0x021893E4 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_wh.h"
#include "wfc.h"
/* The ov001 profile / download-play setup state (gOv001ProfileState). */
#define PROFILE_STATE      0xA90 /* u8: current profile / download-play screen state */
#define PROFILE_PREV_STATE 0xA91 /* u8: state PROFILE_STATE held on the previous poll */
#define PROFILE_RESULT     0xAAC /* u8: result the state-2 list start acts on (1 start list, 2 leave) */
#define PROFILE_LINK_FRAMES 0xA98 /* u32: frames the download-play link step has been running */
#define PROFILE_STATE_TIMER 0xA9C /* u32: frames the current profile state has been held */
#define PROFILE_CHILD      0x64A /* u16: child the channel measurement picked (1..16, 0 = none) */
#define PROFILE_PROGRAM_ID 0x648 /* u16: program id the download-play parent starts this run with */
#define PROFILE_GROUP_ID   0xAC8 /* s32: group id handed to the WH link */
#define PROFILE_SAVE_DATA  0xAA4 /* void *: the save data (GetSaveData) */
#define PROFILE_SAVE_COPY  0xA50 /* u8[0x40]: copy of the save data header */
#define PROFILE_LINKED     0xA93 /* u8: the download-play link is connected */
#define PROFILE_LIST_TIMER 0x204 /* u32: frames the profile list has been shown */
#define PROFILE_STATE_DELAY 30   /* frames a state waits for the link task to settle before it advances */
extern M2C_UNK gWhWork;
extern M2C_UNK data_ov001_0219169c;
extern M2C_UNK data_ov001_0219166c, data_ov001_02191684, data_ov001_021916cc;

#pragma peephole off

#pragma peephole reset

/* Initialize the active map state pointed to by the global from the allocated buffer p and the config a. */

void func_ov001_021887ec(void *arg0) {
    M2C_UNK SystemHalt();
    if (M2C_FIELD(arg0, u16 *, 2) != 8) {
        return;
    }
    SetWhStatus(9);
    SystemHalt();
}

/* Start the WH connection's WFC command channel: mark the link busy and post the
 * start command with the overlay's completion callback; when the command cannot
 * be queued, report it through the WH error state and return 0. */
s32 Ov001_StartCommandChannel(void) {
    extern M2C_UNK gWhWork;
    extern M2C_UNK Ov001_HandleCommandChannelStartResult;
    s32 WFC_StartCommandChannel(void *, void *, s32);
    SetWhStatus(WH_STATUS_BUSY);
    if (WFC_StartCommandChannel((u8 *)M2C_FIELD(&gWhWork, void **, WH_WORK_CONNECTION) + WH_CMD_CHANNEL, &Ov001_HandleCommandChannelStartResult, 2) == WFC_CMD_OK) return 1;
    SetWhError();
    SetWhStatus(WH_STATUS_ERROR);
    return 0;
}

/* Completion callback of the WFC command-channel start for the WH (download-play)
 * session: a reported failure aborts the session, otherwise the overlay's general
 * WFC event handler is installed and the link goes idle. */
void Ov001_HandleCommandChannelStartResult(void *event) {
s32 WFC_SetGeneralHandler(void *);
if(M2C_FIELD(event,u16 *,WH_EVENT_STATUS)){SetWhError();SetWhStatus(WH_STATUS_ERROR);return;}
if(WFC_SetGeneralHandler((void *)func_ov001_021887ec)){SetWhError();SetWhStatus(WH_STATUS_ERROR);return;}
SetWhStatus(WH_STATUS_IDLE);
}

#pragma peephole off
s32 func_ov001_021888a8(s32 mode, s32 option, s32 channel) {
    s32 Ov001_StartDownloadPlayConnection(void);
    if (M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, WH_LINK_STATUS) != WH_STATUS_IDLE) {
        SystemHalt();
    }

    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x12A4) = 0x180;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x12A0) = 0xE0;
    if (M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), WH_WORK_LOG)) {
        M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), WH_WORK_LOG)(
            WH_LOG_STATUS, &data_ov001_0219166c,
            M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x12A4));
    }
    if (M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), WH_WORK_LOG)) {
        M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), WH_WORK_LOG)(
            WH_LOG_STATUS, &data_ov001_02191684,
            M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x12A0));
    }

    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x44) = mode;
    SetWhStatus(WH_STATUS_BUSY);
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x0C) = option;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x32) = channel;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x18) = GetGameGroupId();
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x34) = 0xD0;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x36) = 0x44;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x10) = 2;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x16) = 0;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x12) = 0;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x0E) = 1;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x14) = mode == 2;

    if (mode == 0 || mode == 2 || mode == 4) {
        return Ov001_StartDownloadPlayConnection();
    }
    if (M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), WH_WORK_LOG)) {
        M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), WH_WORK_LOG)(
            WH_LOG_STATUS, &data_ov001_021916cc, mode);
    }
    return 0;
}
#pragma peephole reset
void func_ov001_02188a20(s32 arg0) {
    extern M2C_UNK gWhWork;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x4C) = arg0;
}

void Ov001_GetPlayerData(s32 arg0) {
extern M2C_UNK gWhWork;
void WFC_GetPlayerData(void *, void *, s32);
WFC_GetPlayerData((u8 *)M2C_FIELD(&gWhWork, void **, 4)+0x13E0,(u8 *)M2C_FIELD(&gWhWork, void **, 4)+0x1C00,arg0);
}

/* Step the DWC data-sharing exchange on the connection's channel: pass the step's
 * result to the WH state machine.  A progress result advances (returns 1); a
 * missing child or data set is logged and reported as a failure; any other result
 * fails through SetWhError. */
s32 DWCi_MOV_WH_StepDataSharing(void *arg0){
extern M2C_UNK gWhWork;
extern M2C_UNK sWhLogNoChild;
extern M2C_UNK sWhLogNoDataSet;
s32 func_02013248(void *,void *,void *);
s32 result=func_02013248((u8 *)M2C_FIELD(&gWhWork,void **,4)+WH_DS_CHANNEL,arg0,(u8 *)M2C_FIELD(&gWhWork,void **,4)+WH_DS_PLAYERS);
if(result==WH_DS_STEP_NO_CHILD){
if(M2C_FIELD(&gWhWork,void (**)(s32,void *),0))M2C_FIELD(&gWhWork,void (**)(s32,void *),0)(0x8000000,&sWhLogNoChild);
return 0;}
if(result==WH_DS_STEP_NO_DATASET){
if(M2C_FIELD(&gWhWork,void (**)(s32,void *),0))M2C_FIELD(&gWhWork,void (**)(s32,void *),0)(0x8000000,&sWhLogNoDataSet);
SetWhError(result);return 0;}
if(result==WH_DS_STEP_PROGRESS)return 1;
SetWhError();return 0;
}

void func_ov001_02188b04(void) {
    M2C_UNK SetWhStatus(M2C_UNK);
    s32 QueueWhStopCommand();
    if (QueueWhStopCommand() != 0) {
        return;
    }
    SetWhStatus(0xA);
}

void func_ov001_02188b20(void) {
extern M2C_UNK data_ov001_0219174c;
extern M2C_UNK data_ov001_02191770;
s32 Ov001_EndKeySharing(void); s32 Ov001_TeardownAndQueueSetup(void); s32 Ov001_CloseKeySharingChannel(void); s32 Ov001_ResetWhHostSession(void);
s32 state=M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 *,0x40);
if((state == 1) ? 1 : 0) {
void (*cb1)(s32,void *)=M2C_FIELD(&gWhWork,void (* volatile *)(s32,void *),0); if(cb1) cb1(0x8000000,&data_ov001_0219174c);
} else {
void (*cb2)(s32,void *)=M2C_FIELD(&gWhWork,void (* volatile *)(s32,void *),0); if(cb2) cb2(0x8000000,&data_ov001_02191770);
state=M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 *,0x40);
if(state!=6 && state!=5 && state!=4){SetWhStatus(3);func_ov001_02188b04();return;}
SetWhStatus(3);
switch(M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u32 *,0x44)){
case 3: if(!Ov001_EndKeySharing())func_ov001_02188b04();break;
case 1:case 5: if(!Ov001_TeardownAndQueueSetup())func_ov001_02188b04();break;
case 2: if(!Ov001_CloseKeySharingChannel())func_ov001_02188b04();break;
case 0:case 4: if(!Ov001_ResetWhHostSession())func_ov001_02188b04();break;
}
}
}

/* End the WH (download-play) connection: it must currently be idle, then the WFC
 * end-link command is issued (status BUSY) with Ov001_HandleEndLinkResult as its
 * callback.  Returns 1 when the command was queued, 0 when it failed. */
s32 Ov001_EndLink(void){
extern M2C_UNK gWhWork;
extern M2C_UNK Ov001_HandleEndLinkResult;
s32 WFC_EndLink(void *);
if(M2C_FIELD(M2C_FIELD(&gWhWork,void **,WH_WORK_CONNECTION),s32 *,WH_LINK_STATUS)!=WH_STATUS_IDLE)SystemHalt();
SetWhStatus(WH_STATUS_BUSY);
if(WFC_EndLink(&Ov001_HandleEndLinkResult)==2)return 1;
SetWhStatus(WH_STATUS_PARENT_START);return 0;
}

void func_ov001_02188c78(void *p, void *a) {
    extern void *gOv001ProfileState;
    void Ov001_InitLinkWork(void *);
    void FifoReadSaveSlots(void *);
    void *GetSaveData(void);
    gOv001ProfileState = p;
    Ov001_InitLinkWork((u8 *)p + 0xb00);
    M2C_FIELD(gOv001ProfileState, u16 *, 1608) = 0;
    M2C_FIELD(gOv001ProfileState, u16 *, 1610) = 0;
    M2C_FIELD(gOv001ProfileState, u8 *, 2704) = 1;
    M2C_FIELD(gOv001ProfileState, u8 *, 2705) = 1;
    M2C_FIELD(gOv001ProfileState, s32 *, 2716) = 0;
    Ov001_InitProfileSharing();
    M2C_FIELD(gOv001ProfileState, s32 *, 2740) = M2C_FIELD(a, s32 *, 0);
    M2C_FIELD(gOv001ProfileState, s32 *, 2744) = M2C_FIELD(a, s32 *, 4);
    M2C_FIELD(gOv001ProfileState, s32 *, 2748) = M2C_FIELD(a, s32 *, 8);
    M2C_FIELD(gOv001ProfileState, s32 *, 2752) = M2C_FIELD(a, s32 *, 12);
    M2C_FIELD(gOv001ProfileState, s32 *, 2756) = M2C_FIELD(a, s32 *, 16);
    M2C_FIELD(gOv001ProfileState, s32 *, 2760) = M2C_FIELD(a, s32 *, 20);
    M2C_FIELD(gOv001ProfileState, u8 *, 0xa92) = M2C_FIELD(a, u8 *, 24);
    M2C_FIELD(gOv001ProfileState, u8 *, 0xacc) = 2;
    GetSystemTick();
    FifoReadSaveSlots((u8 *)gOv001ProfileState + 0x64c);
    GetSystemTick();
    M2C_FIELD(gOv001ProfileState, void **, 0xaa4) = GetSaveData();
}

/* Leaves the profile / download-play setup screen from its current state: moves the
 * state machine on to an exit state (ending the multiboot transfer when a download-play
 * link is up) and returns whether the current state could be left. */
int Ov001_LeaveProfileSetup(void) {
    extern void *gOv001ProfileState;
    void MultiBoot_CloseLink(void);
    unsigned int state = M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE);

    /* idle / list wait states: go straight to the exit state */
    if (state == 1 || state == 20 || state == 23 || state == 26 || state == 29) {
        M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 34;
        M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_RESULT) = 0;
        return 1;
    }
    /* download-play / link states: end the transfer and leave through state 16 */
    if (state == 4 || state == 5 || state == 6 || state == 13) {
        if (state == 4 && M2C_FIELD(gOv001ProfileState, u32 *, PROFILE_LINK_FRAMES) < 6) return 0;
        MultiBoot_CloseLink();
        M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 16;
        M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_RESULT) = 2;
        return 1;
    }
    /* (u8)(state + 247) <= 1 is state 9 or 10: the profile list is up */
    if ((u8)(state + 247) <= 1) { M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 32; return 1; }
    if (state == 12) { M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 34; return 1; }
    return 0;
}

/* Begin a profile / download-play run: hand the saved group id to the link, set
 * the screen to its initial state, take a fresh program id, copy the save data
 * header into the link buffer and clear the link and list-timer flags. */
void Ov001_BeginProfileTransfer(void) {
extern void *gOv001ProfileState;
func_ov001_0218836c(M2C_FIELD(gOv001ProfileState,s32 *,PROFILE_GROUP_ID));
M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_STATE)=1;
M2C_FIELD(gOv001ProfileState,u16 *,PROFILE_PROGRAM_ID)=WM_GetNextTgid();
MI_CpuCopy8(M2C_FIELD(gOv001ProfileState,void **,PROFILE_SAVE_DATA),(u8 *)gOv001ProfileState+PROFILE_SAVE_COPY,0x40);
M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_LINKED)=0;
M2C_FIELD(gOv001ProfileState,s32 *,PROFILE_LIST_TIMER)=0;
M2C_FIELD(gOv001ProfileState,u16 *,PROFILE_PROGRAM_ID)++;
}

/* Start a profile / download-play transfer from one of the setup screen's idle
 * states: reset the profile run and the WH link work and move the screen to its
 * child-search state.  Returns 0 when the screen is in no state that may start a
 * transfer. */
s32 Ov001_StartProfileTransfer(void) {
extern void *gOv001ProfileState;
u32 state=M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_STATE);
if(state!=1 && state!=26 && state!=29) return 0;
Ov001_BeginProfileTransfer();Ov001_ResetLinkWork();
M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_STATE)=2;return 1;
}

/* Leave the download-play link's joining state: move the profile setup from state
 * 5 on to state 6 and drop the players that never acknowledged, so the setup's
 * update task can carry on.  Returns 1 when the state allowed the move. */
s32 Ov001_AdvanceLinkState(void) {
extern void *gOv001ProfileState;
void Ov001_DropUnacknowledgedPlayers(void);
if (M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) != 5) return 0;
M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 6;
Ov001_DropUnacknowledgedPlayers();
return 1;
}

/* Per-frame state machine of the ov001 profile / download-play setup screen.
 * It walks the screen states: wait for the list, find and connect to a
 * download-play child, run the profile list task, and then run the teardown
 * sequence that ends the WFC link (each step gives the link task
 * PROFILE_STATE_DELAY frames to settle before Ov001_EndLink closes it). */
void Ov001_UpdateProfileSetup(void) {
    s32 Ov001_StartProfileTransfer(void);
    void Ov001_UpdateChildSearch(void);
    void func_ov001_021893c0(void);
    void Ov001_UpdateLinkState(void);
    void func_ov001_0218959c(void);
    void Ov001_UpdateProfileTask(void);
    void func_ov001_021897a4(void);
    s32 Ov001_FinishLinkTeardown(void);
    s32 Ov001_GetTaskStep(void);
    s32 Ov001_EndLink(void);
    void func_ov001_02188b20(void);
    void MultiBoot_CloseLink(void);
    extern void *gOv001ProfileState;
    u8 *state = gOv001ProfileState;
    switch (state[PROFILE_STATE]) {
    case 1:
        if (state[PROFILE_RESULT] == 1) {
            state[PROFILE_RESULT] = 0;
            Ov001_StartProfileTransfer();
        } else if (state[PROFILE_RESULT] == 2) {
            state[PROFILE_RESULT] = 0;
            ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 34;
        }
        return;
    case 2:
        Ov001_UpdateChildSearch();
        return;
    case 3:
        func_ov001_021893c0();
        ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 4;
        return;
    case 4:
        (*(u32 *)(state + PROFILE_LINK_FRAMES))++;
        Ov001_UpdateLinkState();
        return;
    case 5:
    case 6:
        Ov001_UpdateLinkState();
        return;
    case 7:
        func_ov001_0218959c();
        return;
    case 8:
    case 9:
    case 10:
        Ov001_UpdateProfileTask();
        return;
    case 11:
        func_ov001_021897a4();
        return;
    case 16:
        *(u32 *)(state + PROFILE_STATE_TIMER) = 0;
        ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 17;
        return;
    case 17:
        if ((*(u32 *)(state + PROFILE_STATE_TIMER))++ > PROFILE_STATE_DELAY)
            Ov001_FinishLinkTeardown();
        return;
    case 18:
        MultiBoot_CloseLink();
        *(u32 *)((u8 *)gOv001ProfileState + PROFILE_STATE_TIMER) = 0;
        ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 22;
        return;
    case 19:
        if ((*(u32 *)(state + PROFILE_STATE_TIMER))++ > PROFILE_STATE_DELAY && Ov001_GetTaskStep() == WH_STATUS_IDLE) {
            Ov001_EndLink();
            ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 20;
        }
        return;
    case 21:
        func_ov001_02188b20();
        *(u32 *)((u8 *)gOv001ProfileState + PROFILE_STATE_TIMER) = 0;
        ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 22;
        return;
    case 22:
        if ((*(u32 *)(state + PROFILE_STATE_TIMER))++ > PROFILE_STATE_DELAY && Ov001_GetTaskStep() == WH_STATUS_IDLE) {
            Ov001_EndLink();
            ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 23;
        }
        return;
    case 24:
        func_ov001_02188b20();
        *(u32 *)((u8 *)gOv001ProfileState + PROFILE_STATE_TIMER) = 0;
        ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 25;
        return;
    case 25:
        if ((*(u32 *)(state + PROFILE_STATE_TIMER))++ > PROFILE_STATE_DELAY && Ov001_GetTaskStep() == WH_STATUS_IDLE) {
            Ov001_EndLink();
            ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 26;
        }
        return;
    case 27:
        func_ov001_02188b20();
        *(u32 *)((u8 *)gOv001ProfileState + PROFILE_STATE_TIMER) = 0;
        ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 28;
        return;
    case 28:
        if ((*(u32 *)(state + PROFILE_STATE_TIMER))++ <= PROFILE_STATE_DELAY)
            return;
        if (Ov001_GetTaskStep() == WH_STATUS_IDLE) {
            Ov001_EndLink();
            ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 29;
            return;
        }
        {
            u32 ticks = *(u32 *)((u8 *)gOv001ProfileState + PROFILE_STATE_TIMER);
            if (ticks % PROFILE_STATE_DELAY == 1 && ticks > 55)
                func_ov001_02188b20();
        }
        return;
    case 32:
        func_ov001_02188b20();
        *(u32 *)((u8 *)gOv001ProfileState + PROFILE_STATE_TIMER) = 0;
        ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 33;
        return;
    case 33:
        if ((*(u32 *)(state + PROFILE_STATE_TIMER))++ > PROFILE_STATE_DELAY && Ov001_GetTaskStep() == WH_STATUS_IDLE) {
            Ov001_EndLink();
            ((u8 *)gOv001ProfileState)[PROFILE_STATE] = 34;
        }
        return;
    case 30:
        func_ov001_02188b20();
        return;
    case 34:
    default:
        return;
    }
}

/* Read the profile screen's current state and whether it changed since the last
 * poll, then remember it as the previous state. */
void Ov001_PollProfileState(u8 *stateOut,u8 *changedOut) {
extern void *gOv001ProfileState;
*stateOut=M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_STATE);
if(M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_STATE)!=M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_PREV_STATE)) *changedOut=1; else *changedOut=0;
M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_PREV_STATE)=M2C_FIELD(gOv001ProfileState,u8 *,PROFILE_STATE);
}

void func_ov001_02189308(void) {
    MultiBoot_GetPlayerInfo(1);
}

/* Step the download-play child search from the wireless task status: while idle
 * start scanning the children's channels, once the measurement has picked the
 * best child remember it and keep the state on the search step, and report a
 * failed setup. */
void Ov001_UpdateChildSearch(void) {
    M2C_UNK SystemHalt();
    extern void *gOv001ProfileState;
    s32 child;
    switch (Ov001_GetTaskStep()) {
    case WH_STATUS_IDLE:
        WhStartChildScan();
        return;
    case WH_STATUS_MEASURECHAN:
        child = WhChooseChild();
        M2C_FIELD(gOv001ProfileState, u16 *, PROFILE_CHILD) = child;
        M2C_FIELD(gOv001ProfileState, s32 *, PROFILE_LINK_FRAMES) = 0;
        M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 3;
        return;
    case WH_STATUS_STOP:
        M2C_FIELD(gOv001ProfileState, s32 *, PROFILE_LINK_FRAMES) = 0;
        M2C_FIELD(gOv001ProfileState, u8 *, PROFILE_STATE) = 3;
        return;
    case WH_STATUS_PARENT_START:
        func_ov001_02188b04();
        return;
    case WH_STATUS_BUSY:
        break;
    default:
        SystemHalt();
        return;
    }
}

void func_ov001_021893c0(void) {
    M2C_UNK Ov001_StartDownloadPlay(s32, u16);
    extern void *gOv001ProfileState;
    Ov001_StartDownloadPlay(M2C_FIELD(gOv001ProfileState, s32 *, 0xAC8), M2C_FIELD(gOv001ProfileState, u16 *, 0x648));
}
