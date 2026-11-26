/* 2 functions from 0x02016934 to 0x02017158 (main), found by ds-decomp. */
#include "common.h"
#include "wfc_channel.h"
typedef struct DispatchCtx169 { u8 pad0[0x40]; u8 buffer[0x4c4]; u32 value; u8 pad508[0x10]; u16 a; u16 b; u8 pad51c[0x10]; u16 flag; } DispatchCtx169;
typedef struct DispatchWork169 { u8 pad[0x131c]; u32 active; u8 pad1320[0x1c8]; u32 entries[15]; } DispatchWork169;
extern M2C_UNK gMbState;
extern M2C_UNK gMbParam;
void Mb_StartConnect(void);
int Mb_LinkExchangeReady(void);
void Mb_CancelLink(void *);
void *WFC_StartDownloadPlay(void *, void *);
void *WFC_StartChildIndication(void *, void *);
void *WFC_SubmitParentMode(void *, int);
void *WFC_EndLink(void *);
void *Mb_SubmitLinkDataTask(void *, int, int, void *, int, int, int, int, int, int, int);
void Mb_ReportPacketResult(int, void *);
void WaitCycles(int);
void SystemHalt(void);
void WFC_SetChannelHandler(int,int,int);
void WFC_SetGeneralHandler(int);

#pragma opt_propagation off
#pragma opt_strength_reduction off
/* Multiboot (DS Download Play) WFC general event handler: dispatches on the
 * event command (start, connect, download-play start, parent/child mode, load,
 * link close, ...), driving the link state machine and reporting results back
 * through the game's MB_CTX_CALLBACK or Mb_ReportPacketResult. */
void Mb_HandleWfcEvent(void *event) {
u32 i,playerCount; 
switch ((s32)M2C_FIELD(event,u16 *,0)) {
case 0: if(M2C_FIELD(event,u16 *,2)) {M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(256,event);} else Mb_StartConnect(); return;
case 29: if(M2C_FIELD(event,u16 *,2)) {M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(256,event);} else Mb_ReportPacketResult(7,WFC_StartDownloadPlay(Mb_HandleWfcEvent,M2C_FIELD(&gMbState,void **,MB_STATE_CTX))); return;
case 7: M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(21,event); Mb_ReportPacketResult(25,WFC_SubmitParentMode(Mb_HandleWfcEvent,1)); return;
case 25: if(M2C_FIELD(event,u16 *,2)){M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(256,event);} else Mb_ReportPacketResult(8,WFC_StartChildIndication(Mb_HandleWfcEvent,M2C_FIELD(&gMbParam,void **,12))); return;
case 8:
if(M2C_FIELD(event,u16 *,2)){M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(256,event);return;}
switch((s32)M2C_FIELD(event,u16 *,8)){
case 0: M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_PLAYERS)=0; M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_EXCHANGE)=0; return;
case 7:
if(M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_CLOSING)==1)return;
M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_PLAYERS)|=1<<M2C_FIELD(event,u16 *,16);
M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(0,event);
if(M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_EXCHANGE)==0 && M2C_FIELD(&gMbState,DispatchWork169 **,MB_STATE_WORK)->active==0){
M2C_FIELD(&gMbState,DispatchWork169 **,MB_STATE_WORK)->active=1;
{u32 flag=(M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,0x52c)==0); void *ctx=M2C_FIELD(&gMbState,void * volatile *,MB_STATE_CTX);Mb_ReportPacketResult(14,Mb_SubmitLinkDataTask(Mb_HandleWfcEvent,M2C_FIELD(ctx,u32 *,0x504),M2C_FIELD(ctx,u16 *,0x51a),(char*)ctx+0x40,M2C_FIELD(ctx,u16 *,0x518),(u16)flag,0,0,0,1,1));}return;
}
if(Mb_LinkExchangeReady()){M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(25,0);}return;
case 9: M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_PLAYERS)&=~(1<<M2C_FIELD(event,u16 *,16)); M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(1,event);return;
case 2: if(M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_CLOSING)==1)return; M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(28,event);return;
case 26: return;
default: M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(256,event);return;
}
case 14:
M2C_FIELD(&gMbState,DispatchWork169 **,MB_STATE_WORK)->active=0;
switch(M2C_FIELD(event,u16 *,4)){
case 10:M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_EXCHANGE)=1;if(M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_CLOSING)==0){M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(25,0);}return;
case 11:M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(3,M2C_FIELD(event,void **,8));return;
default:M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(256,event);return;
}
case 15:
if(M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_WORK),u32 *,0x74c8)){
playerCount=0;i=0;do {if(M2C_FIELD(&gMbState,DispatchWork169 **,MB_STATE_WORK)->entries[i]){playerCount++;if(playerCount>=2)break;}i++;}while(i<15);
if(playerCount==1)WaitCycles(0x32c8);
}
M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u8 *,MB_LINK_SEND_PENDING)=0;
if(M2C_FIELD(event,u16 *,2)==0){M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(2,event);if(M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_CLOSING)==0){M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(25,0);}return;}
if(M2C_FIELD(event,u16 *,2)==10){M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(42,event);return;}
M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(19,event);if(M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_CLOSING)==0){M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(25,0);}return;
case 1:
if(M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_WORK),u32 *,MB_WORK_STARTED)==0){
if(M2C_FIELD(event,u16 *,2)){M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_CLOSING)=0;M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(256,event);return;}
M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_PLAYERS)=0; M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_EXCHANGE)=0;Mb_ReportPacketResult(2,WFC_EndLink(Mb_HandleWfcEvent));return;
}
WFC_SetChannelHandler(1,0,0);WFC_SetGeneralHandler(0);
case 2:if(M2C_FIELD(event,u16 *,2)){M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_CLOSING)=0;M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(256,event);}else Mb_CancelLink(event);return;
case 13:if(M2C_FIELD(event,u16 *,2)==0)M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),u16 *,MB_LINK_PLAYERS)&=~M2C_FIELD(event,u16 *,10);return;
case 128:switch(M2C_FIELD(event,u16 *,4)){
case 16:M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(29,event);return;
case 17:M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(31,event);return;
case 18:M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(32,event);return;
case 19:M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(33,event);return;
case 22:SystemHalt();return;
case 23:break;
}break;
default:M2C_FIELD(M2C_FIELD(&gMbState,void **,MB_STATE_CTX),void (**)(int,void *),MB_CTX_CALLBACK)(256,event);return;
}
}
#pragma opt_strength_reduction reset
#pragma opt_propagation reset
/* Multiboot channel completion callback: drop an event whose result is nonzero,
 * ignore the join/leave and send-completion commands, and forward a completed
 * receive (command 21) to the manager's message callback as message 9. */
void HandleMbChannelEvent(void *event) {
    extern M2C_UNK gMbState;
    u16 command;

    if (M2C_FIELD(event, u16 *, WFC_EVENT_RESULT) != 0) {
        return;
    }
    command = M2C_FIELD(event, u16 *, WFC_EVENT_COMMAND);
    switch ((s32) command) {
    case 7:
    case 9:
    case 25:
    case 26:
        break;
    case 21:
        M2C_FIELD(M2C_FIELD(&gMbState, void **, 8), void (**)(s32, void *), 0x51C)(9, event);
        break;
    }
}
