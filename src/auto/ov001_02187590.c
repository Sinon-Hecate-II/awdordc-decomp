/* 37 functions from 0x02187590 to 0x0218851C (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_wh.h"
#include "ov001_link.h"

#pragma merge_duplicate_code off
/* Callback the multiboot command layer runs for the ov001 Download Play link.
 * Each event moves the child's bit between the link header's stage bitmaps as it
 * joins, reports its info block or leaves, and fills the child's work-block
 * record.  On teardown the pending multiboot requests are dropped; a status event
 * either fails the link or is ignored.  Events are MB_EVENT_* ids; packet is the
 * event's record (a join request or a status word) or NULL. */
void Ov001_HandleLinkEvent(s32 player, u32 event, const u8 *packet) {
    extern s16 *gOv001LinkWork;
    u16 Ov001_GetLinkStatus(void);
    void Ov001_SetLinkStatus(s16);
    s32 Ov001_GetPlayerStage(s32);
    void Ov001_TryStartTransfer(void);
    void Ov001_HandleChildPhase1(s32);
    void Ov001_HandleChildPhase0(s32);
    void Ov001_CompletePlayerLeave(s32);
    void *MultiBoot_GetPlayerInfo(s32);
    void *OS_DisableInterrupts();
    void OS_RestoreInterrupts(void *);
    s32 MI_CpuCopy8(void *, void *, s32);
    void SystemHalt(void);
    u16 *header;
    u8 *address;
    s32 offset;
    void *interrupts;
    void *child;
    u16 clearMask;
    u16 status;

    switch (event) {
    case MB_EVENT_JOIN:
        if (Ov001_GetLinkStatus() != 2) return;
        header = (u16 *)gOv001LinkWork;
        interrupts = OS_DisableInterrupts();
        header[OV001_LINK_JOINED / 2] |= 1 << player;
        OS_RestoreInterrupts(interrupts);
        offset = (player - 1) * OV001_LINK_RECORD_SIZE;
        address = (u8 *)gOv001LinkWork + OV001_LINK_RECORDS + OV001_LINK_RECORD_ADDRESS + offset;
        address[0] = packet[0xa];
        address[1] = packet[0xb];
        address[2] = packet[0xc];
        address[3] = packet[0xd];
        address[4] = packet[0xe];
        address[5] = packet[0xf];
        M2C_FIELD((u8 *)gOv001LinkWork + OV001_LINK_RECORDS + offset, u16 *, OV001_LINK_RECORD_ID) = player;
        return;
    case MB_EVENT_LEAVE:
        if (Ov001_GetPlayerStage(player) == 6) return;
        clearMask = ~(1 << player);
        interrupts = OS_DisableInterrupts();
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED) &= clearMask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICKED) &= clearMask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_PENDING) &= clearMask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_ANSWERED) &= clearMask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_READY) &= clearMask;
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED_COPY) &= clearMask;
        OS_RestoreInterrupts(interrupts);
        Ov001_TryStartTransfer();
        return;
    case MB_EVENT_PLAYER_DATA:
        if (Ov001_GetLinkStatus() != 2) {
            Ov001_HandleChildPhase0(player);
            return;
        }
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICKED) |= 1 << player;
        Ov001_HandleChildPhase1(player);
        child = MultiBoot_GetPlayerInfo(player);
        if (child == NULL) return;
        MI_CpuCopy8(child, (u8 *)gOv001LinkWork + OV001_LINK_RECORDS + (player - 1) * OV001_LINK_RECORD_SIZE, OV001_LINK_RECORD_INFO_SIZE);
        return;
    case MB_EVENT_GROUP_LEAVE:
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICKED) &= ~(1 << player);
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_PENDING) |= 1 << player;
        if (Ov001_GetLinkStatus() == 3) Ov001_CompletePlayerLeave(player);
        return;
    case MB_EVENT_CHUNK_ACK:
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_KICK_ANSWERED) &= ~(1 << player);
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_READY) |= 1 << player;
        return;
    case MB_EVENT_KICK:
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_READY) &= ~(1 << player);
        M2C_FIELD(gOv001LinkWork, u16 *, OV001_LINK_JOINED_COPY) |= 1 << player;
        Ov001_TryStartTransfer();
        return;
    case MB_EVENT_TEARDOWN: {
        u8 *tail;
        void *request;
        if (Ov001_GetLinkStatus() == 4) Ov001_SetLinkStatus(5);
        else Ov001_SetLinkStatus(0);
        /* drop the pending multiboot program (+0x144) and transfer (+0x140) requests */
        tail = (u8 *)gOv001LinkWork;
        tail += 0x1b000;
        request = M2C_FIELD(tail, void **, 0x144);
        if (request != NULL)
            M2C_FIELD(tail, void **, 0x144) = NULL;
        tail = (u8 *)gOv001LinkWork;
        tail += 0x1b000;
        request = M2C_FIELD(tail, void **, 0x140);
        if (request != NULL)
            M2C_FIELD(tail, void **, 0x140) = NULL;
        return;
    }
    case MB_EVENT_STATUS:
        status = *(const u16 *)packet;
        switch (status) {
        case 1:
        case 2:
        case 9:
            Ov001_SetLinkStatus(7);
            return;
        case 8:
        default:
            return;
        }
    case 1: break;
    case MB_EVENT_GROUP_REJECT: break;
    case MB_EVENT_GROUP_JOIN: break;
    case MB_EVENT_GROUP_DATA: break;
    case MB_EVENT_CHUNK_SENT: break;
    case MB_EVENT_ROSTER_DONE: break;
    default:
        SystemHalt();
        break;
    }
}
#pragma merge_duplicate_code reset
void Ov001_SetLinkStatus(s16 arg0) {
    extern s16 *gOv001LinkWork;
    *gOv001LinkWork = arg0;
}

u16 Ov001_GetLinkStatus(void) {
    extern s16 *gOv001LinkWork;
    return *(u16 *)gOv001LinkWork;
}

#pragma common_subs off
u16 Ov001_GetLinkInfo(s32 arg0) {
extern s16 *gOv001LinkWork;extern u16 *data_ov001_02190c68[];
s16 *q=gOv001LinkWork;u16 **table=data_ov001_02190c68;
table[0]=(u16*)(q+1);table[1]=(u16*)(q+2);table[2]=(u16*)(q+3);
table[3]=(u16*)(q+4);table[4]=(u16*)(q+5);table[5]=(u16*)(q+6);
return *(u16 *)M2C_FIELD(data_ov001_02190c68,s32 *,arg0*4);
}
#pragma scheduling off
s32 Ov001_GetPlayerStage(s32 arg0) {
    void *OS_DisableInterrupts(s32);
    void OS_RestoreInterrupts(void *);
    s32 MI_CpuCopy8(void *, void *, s32);
    extern s16 *gOv001LinkWork;
    u16 buf[7];
    s16 *gp;
    u16 mask;
    void *r;
    r = OS_DisableInterrupts(arg0);
    gp = gOv001LinkWork;
    mask = 1 << arg0;
    if (!((u16)gp[1] & mask)) {
        OS_RestoreInterrupts(r);
        return 0;
    }
    MI_CpuCopy8(gp, buf, 14);
    OS_RestoreInterrupts(r);
    if (buf[2] & mask) return 2;
    if (buf[3] & mask) return 3;
    if (buf[4] & mask) return 4;
    if (buf[5] & mask) return 5;
    if (buf[6] & mask) return 6;
    return 1;
}
#pragma scheduling reset
s32 func_ov001_021879fc(s32 arg0) {
extern s16 *gOv001LinkWork;
if(((u16)gOv001LinkWork[1] & (1<<arg0)) !=0) {
return (arg0-1)*30+(s32)((u8 *)gOv001LinkWork+14);
}
return 0;
}

u16 func_ov001_02187a30(u8 *arg0) {
    extern s16 *gOv001LinkWork;
    u8 *base;
    u16 i;
    s32 offset;
    u8 *entry;
    i = 1;
    base = (u8 *)gOv001LinkWork + 0x24;
    do {
        if ((u16)gOv001LinkWork[1] & (1 << i)) {
            offset = (i - 1) * 0x1E;
            entry = base + offset;
            if (arg0[0] == entry[0] && arg0[1] == entry[1] && arg0[2] == entry[2] && arg0[3] == entry[3] && arg0[4] == entry[4] && arg0[5] == entry[5]) {
                return M2C_FIELD((u8 *)gOv001LinkWork + offset, u16 *, 0x2A);
            }
        }
        i++;
    } while ((u32)i < 2);
    return 0;
}

void func_ov001_02187ad8(void *arg0) {
    extern M2C_UNK gWhWork;
    M2C_FIELD(&gWhWork, void **, 4) = arg0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x13A8) = 0;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x13AC) = 0;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x13B0) = 0;
}

void SetWhStatus(s32 arg0) {
    extern M2C_UNK gWhWork;
    extern s32 data_ov001_021914b0[];
    extern M2C_UNK data_ov001_02191590;
    extern M2C_UNK data_ov001_02191598;
    if (M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), 0) != NULL) {
        M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), 0)(0x08000000, &data_ov001_02191590, data_ov001_021914b0[M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x40)]);
    }
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x40) = arg0;
    if (M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), 0) == NULL) return;
    M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), 0)(0x08000000, &data_ov001_02191598, data_ov001_021914b0[M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x40)]);
}

s32 SetWhError(arg0)
s32 arg0;
{
extern M2C_UNK gWhWork;
void *p = M2C_FIELD(&gWhWork, void **, 4);
if ((u32)(M2C_FIELD(p, s32 *, 0x40) - 9) > 1) M2C_FIELD(p, s32 *, 0x54) = arg0;
}

s32 func_ov001_02187bb0(void) {
s32 WFC_StartDownloadPlay(void *, void *);
void func_ov001_02187bf4(void *);
extern M2C_UNK gWhWork;
SetWhStatus(3);
if (WFC_StartDownloadPlay((void *)func_ov001_02187bf4, M2C_FIELD(&gWhWork, void **, 4)) == 2) return 1;
SetWhError();
SetWhStatus(9);
return 0;
}

void func_ov001_02187bf4(void *arg0) {
s32 func_ov001_02187c60();
s32 func_ov001_02187cfc();
extern M2C_UNK gWhWork;
if (M2C_FIELD(arg0,u16 *,2)) {
SetWhError(M2C_FIELD(arg0,u16 *,2));
SetWhStatus(9); return;
}
if (M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 *,0x13AC)) {
if (func_ov001_02187c60()) return;
SetWhStatus(9); return;
}
if (func_ov001_02187cfc()) return;
SetWhStatus(9);
}

s32 func_ov001_02187c60(void) {
extern M2C_UNK gWhWork;
void func_ov001_02187cc4(void *);
s32 func_02013b54(void *,s32,void *);
void *p;
s32 value;
SetWhStatus(3);
p=M2C_FIELD(&gWhWork,void **,4);
value=M2C_FIELD(p,s32 (**)(void *,void *),0x13AC)((u8 *)p+0x13C0,p);
if(func_02013b54((void *)func_ov001_02187cc4,value,(u8 *)M2C_FIELD(&gWhWork,void **,4)+0x13C0)==2) return 1;
SetWhError(); SetWhStatus(9); return 0;
}

void func_ov001_02187cc4(void *arg0) {
    s32 func_ov001_02187cfc();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SetWhError();
        SetWhStatus(9);
        return;
    }
    if (func_ov001_02187cfc() != 0) {
        return;
    }
    SetWhStatus(9);
}

s32 func_ov001_02187cfc(void) {
extern M2C_UNK gWhWork;
extern M2C_UNK HandleChildIndicate;
s32 func_02012474(void *);
if((u32)(M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 *,0x40)-4)<=2) return 1;
if(func_02012474(&HandleChildIndicate)!=2) {SetWhError();return 0;}
M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,0x50)=0;
M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,0x52)=1;
return 1;
}

#pragma push
#pragma opt_propagation off
/* Callback for the DWC child-connection indications: marks or clears the child's
   bit in the connection bitmap as it connects (kind 7) or disconnects (kind 9),
   handling the transport's request callback on connect and advancing the state on
   the other indication kinds. */
void HandleChildIndicate(void *event) {
extern M2C_UNK gWhWork;
extern M2C_UNK data_ov001_0219159c,data_ov001_021915c8,data_ov001_021915f4;
s32 SetWhError();
s32 func_0201280c(void (*)(void *),s32);
register s32 childId;
u16 childMask;
register void (*logCallback)();
register s32 indicateKind;
s32 error;
childId=M2C_FIELD(event,u16 *,0x10);
childMask=(u16)(1U<<childId);
error=M2C_FIELD(event,u16 *,2);
if(error){
((s32 (*)(s32))SetWhError)(error);SetWhStatus(9);return;
}
indicateKind=M2C_FIELD(event,u16 *,8);
switch(indicateKind){
case 7:
logCallback=M2C_FIELD(&gWhWork,void (**)(),0);
if(logCallback)logCallback(0x8000000,&data_ov001_0219159c,childId);
if(M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 (**)(void *),0x4c)&& !M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 (**)(void *),0x4c)(event)){
error=func_0201280c(0,M2C_FIELD(event,u16 *,0x10));
if(error==2)return;
SetWhError();SetWhStatus(9);return;
}
M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,0x52)|=childMask;
break;
case 9:
logCallback=M2C_FIELD(&gWhWork,void (**)(),0);
if(logCallback)logCallback(0x8000000,&data_ov001_021915c8,childId);
M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),u16 *,0x52)&=~childMask;
break;
case 0:
if(func_ov001_02187ed0()==0)SetWhStatus(9);
break;
case 2:break;
default:
logCallback=M2C_FIELD(&gWhWork,void (**)(),0);
if(logCallback)((void (*)(s32,void *,s32))logCallback)(0x8000000,&data_ov001_021915f4,indicateKind);
break;
}
}
#pragma pop
s32 func_ov001_02187ed0(void) {
extern M2C_UNK gWhWork;
extern M2C_UNK HandleParentStartResult;
s32 func_02012b08(void *,void *,u16,void *,u16,s32);
void *p;
if((u32)(M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 *,0x40)-4)<=2) return 1;
SetWhStatus(4);
p=M2C_FIELD(&gWhWork,void **,4);
if(func_02012b08(&HandleParentStartResult,(u8 *)p+0x1060,(u16)M2C_FIELD(p,s32 *,0x12A4),(u8 *)p+0xF80,(u16)M2C_FIELD(p,s32 *,0x12A0),1)==2)return 1;
SetWhError(); return 0;
}

/* Completion callback of the WH parent-start task begun by the connect step:
 * on success it advances the connection to key sharing (status CONNECTED) or
 * data sharing, on failure it records the error and moves to the failure
 * status.  Command 10 is the parent task's completion; the other commands are
 * only logged. */
void HandleParentStartResult(void *event) {
    s32 SetWhError();
    void SetWhStatus(s32);
    s32 func_ov001_02188094(void);
    s32 func_02012fac(void *, s32, s32, s32, s32);
    extern M2C_UNK gWhWork;
    extern M2C_UNK data_ov001_02191614;
    extern M2C_UNK data_ov001_021915f4;
    void *connection;
    s32 error;
    u16 command;

    if (M2C_FIELD(event, u16 *, WH_EVENT_STATUS) != 0) {
        SetWhError(M2C_FIELD(event, u16 *, WH_EVENT_STATUS));
        SetWhStatus(WH_STATUS_PARENT_START);
        return;
    }
    command = M2C_FIELD(event, u16 *, WH_EVENT_COMMAND);
    switch (command) {
    case 10:
        connection = M2C_FIELD(&gWhWork, void **, 4);
        if (M2C_FIELD(connection, s32 *, 0x44) == 2) {
            if (M2C_FIELD(connection, s32 *, 0x40) == WH_STATUS_CONNECTED) {
                if (func_ov001_02188094() != 0) return;
                if (M2C_FIELD(&gWhWork, void (**)(s32, void *), 0) != 0) {
                    M2C_FIELD(&gWhWork, void (**)(s32, void *), 0)(0x08000000, &data_ov001_02191614);
                }
                SetWhStatus(WH_STATUS_PARENT_START);
                return;
            }
            if (M2C_FIELD(connection, s32 *, 0x40) == WH_STATUS_KEYSHARING) return;
        } else if (M2C_FIELD(connection, s32 *, 0x44) == 4) {
            error = func_02012fac((u8 *)connection + 0x13E0, 13, 7, 0x44, 1);
            if (error != 0) {
                SetWhError(error);
                SetWhStatus(WH_STATUS_PARENT_START);
                return;
            }
            SetWhStatus(WH_STATUS_DATASHARING);
            return;
        }
        SetWhStatus(WH_STATUS_CONNECTED);
        return;
    case 11:
        break;
    case 12:
    case 13:
    default:
        if (M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), 0) != 0) {
            M2C_FIELD(&gWhWork, void (**)(s32, void *, s32), 0)(0x08000000, &data_ov001_021915f4, command);
        }
        return;
    }
}

s32 func_ov001_02188094(void){extern M2C_UNK gWhWork;s32 func_02013b2c(void *,s32);SetWhStatus(6);if(func_02013b2c((u8 *)M2C_FIELD(&gWhWork,void **,4)+0x1e00,13)==2)return 1;SetWhError();return 0;}

s32 func_ov001_021880d0(void){extern M2C_UNK gWhWork;s32 func_02013b48(void *);if(func_02013b48((u8 *)M2C_FIELD(&gWhWork,void **,4)+0x1e00)==2)return 1;SetWhError();return 0;}

s32 func_ov001_02188100(void) {
    s32 func_02012d64(M2C_UNK *);
    extern M2C_UNK func_ov001_02188130;
    SetWhStatus(3);
    if (func_02012d64(&func_ov001_02188130) == 2) {
        return 1;
    }
    SetWhError();
    return 0;
}

void func_ov001_02188130(void *a){extern M2C_UNK gWhWork;extern M2C_UNK data_ov001_02191644;M2C_UNK func_ov001_02188b04();if(M2C_FIELD(a,u16 *,2)){SetWhError();func_ov001_02188b04();return;}if(func_ov001_02188184())return;if(M2C_FIELD(&gWhWork,void (**)(s32,void *),0))M2C_FIELD(&gWhWork,void (**)(s32,void *),0)(0x8000000,&data_ov001_02191644);func_ov001_02188b04();}

s32 func_ov001_02188184(void) {
    s32 func_02012484(void (*)(void *));
    void func_ov001_021881ac(void *);
    if (func_02012484(func_ov001_021881ac) == 2) return 1;
    SetWhError();
    return 0;
}

void func_ov001_021881ac(void *arg0) {
    void SetWhStatus(M2C_UNK);
    M2C_UNK SetWhError();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SetWhError();
        return;
    }
    SetWhStatus(1);
}

s32 func_ov001_021881d0(void){extern M2C_UNK gWhWork;s32 func_02013b48(void *);if(M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 *,0x40)!=6)return 0;SetWhStatus(3);if(func_02013b48((u8 *)M2C_FIELD(&gWhWork,void **,4)+0x1e00)==2)return 1;SetWhError();return 0;}

s32 func_ov001_02188220(void) {
    extern M2C_UNK func_ov001_02188250;
    SetWhStatus(3);
    if (func_02012d64(&func_ov001_02188250) == 2) {
        return 1;
    }
    SetWhError();
    return 0;
}

void func_ov001_02188250(void *arg0) {
    s32 func_ov001_02188284();
    M2C_UNK func_ov001_02188b20();
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SetWhError();
        func_ov001_02188b20();
        return;
    }
    if (func_ov001_02188284() != 0) {
        return;
    }
    SetWhStatus(9);
}

s32 func_ov001_02188284(void) {
    s32 func_0201280c(void (*)(void *), s32);
    void func_ov001_021882bc(void *);
    M2C_UNK func_ov001_02188b04();
    SetWhStatus(3);
    if (func_0201280c(func_ov001_021882bc, 0) == 2) return 1;
    SetWhError();
    func_ov001_02188b04();
    return 0;
}

void func_ov001_021882bc(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SetWhError();
        return;
    }
    SetWhStatus(1);
}

s32 func_ov001_021882e0(void) {
    s32 func_02012274(M2C_UNK *);
    extern M2C_UNK func_ov001_02188310;
    SetWhStatus(3);
    if (func_02012274(&func_ov001_02188310) == 2) {
        return 1;
    }
    SetWhError();
    return 0;
}

void func_ov001_02188310(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SetWhStatus(9);
        SetWhError(M2C_FIELD(arg0, u16 *, 2));
        return;
    }
    SetWhStatus(1);
}

void func_ov001_02188344(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        SetWhStatus(0xA);
        return;
    }
    SetWhStatus(0);
}

void func_ov001_0218836c(s32 arg0) {
    extern M2C_UNK gWhWork;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 8) = arg0;
}

u16 func_ov001_02188380(void) {
extern M2C_UNK gWhWork;
return M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x52);
}

s32 Ov001_GetTaskStep(void) {
extern M2C_UNK gWhWork;
return M2C_FIELD(M2C_FIELD(&gWhWork,void **,4),s32 *,0x40);
}

s32 WhStartChildScan(void) {
    void GetMacAddress(u8 *);
    void SetWhStatus(s32);
    u16 ScanNextChild(u16);
    s32 SetWhError(s32);
    extern M2C_UNK gWhWork;
    u16 buf[3];
    u16 rv;

    GetMacAddress((u8 *)buf);
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x58) =
        buf[0] + *(s32 *)0x027ffc3c + buf[1] + buf[2];
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x58) =
        M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), s32 *, 0x58) * 0x10dcd + 0x39 + 0x3000;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x5c) = 0;
    M2C_FIELD(M2C_FIELD(&gWhWork, void **, 4), u16 *, 0x5e) = 0x65;
    SetWhStatus(3);
    rv = ScanNextChild(1);
    if (rv == 0x18) {
        SetWhError(0x18);
        SetWhStatus(9);
        return 0;
    }
    if (rv == 2) {
        return 1;
    }
    SetWhError(rv);
    SetWhStatus(9);
    return 0;
}

u16 ScanNextChild(u16 arg0) {
s32 WFC_GetPlayerMask();
s32 func_ov001_021885f4(void *,u16);
extern M2C_UNK HandleChildScanResult;
s32 mask=WFC_GetPlayerMask();
if(mask==0x8000) {SetWhError(3);SetWhStatus(9);return 3;}
if(mask==0) {SetWhError(0x16);SetWhStatus(9);return 0x18;}
while(!(mask & (1 << (arg0-1)))) {
arg0++;
if((u32)arg0>0x10) return 0x18;
}
return (u16)func_ov001_021885f4(&HandleChildScanResult,arg0);
}

