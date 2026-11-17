/* 20 functions from 0x021858A4 to 0x021867AC (ov001), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
#include "net_session.h"
#include "ov001_menu.h"
typedef struct InitBlock68 { u32 words[17]; } InitBlock68;
typedef struct MessagePalette6 { u8 values[6]; } MessagePalette6;

void func_ov001_02185f38(u16 *);
void Ov001_MergeProfileList(u16 *);

#pragma opt_strength_reduction off
/* Second step of the ov001 option-menu close slide: slides rows 2..4 left by 8
 * pixels a frame until row 2 rests at x 80, then passes the slide task on to the
 * next step. */
void Ov001_SlideMenuCloseStep2(s32 task) {
extern s32 gOv001MenuLayout;
extern const u8 Ov001MenuRowPositions[];
M2C_UNK Ov001_GetSpritePosition(M2C_UNK,M2C_UNK,M2C_UNK *,M2C_UNK *);
M2C_UNK Ov001_MoveSpriteLayout(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK Ov001_SetSlideStep(M2C_UNK,M2C_UNK);
void Ov001_SlideMenuCloseStep3(s32);
s32 pos[2];s32 i;
Ov001_GetSpritePosition(M2C_FIELD(&gOv001MenuLayout,void ***,OV001_MENU_SPRITES)[2],0,&pos[1],&pos[0]);
pos[1]-=8;
if(pos[1]>80){
for(i=2;i<OV001_MENU_ROWS;i++)Ov001_MoveSpriteLayout(M2C_FIELD(&gOv001MenuLayout,void ***,OV001_MENU_SPRITES)[i],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);
return;
}
pos[1]=80;
for(i=2;i<OV001_MENU_ROWS;i++)Ov001_MoveSpriteLayout(M2C_FIELD(&gOv001MenuLayout,void ***,OV001_MENU_SPRITES)[i],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);
Ov001_SetSlideStep(task,(M2C_UNK)Ov001_SlideMenuCloseStep3);
}
#pragma opt_strength_reduction reset
/* Third step of the ov001 option-menu close slide: slides rows 1..4 left by 8
 * pixels a frame until row 1 rests at x 32, then passes the slide task on to the
 * last step. */
void Ov001_SlideMenuCloseStep3(s32 task) {
    extern M2C_UNK gOv001MenuLayout;
    extern const u8 Ov001MenuRowPositions[];
    M2C_UNK Ov001_GetSpritePosition(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    M2C_UNK Ov001_MoveSpriteLayout(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_SetSlideStep(M2C_UNK, M2C_UNK);
    void Ov001_SlideMenuCloseStep4(s32);
    s32 pos[2];
    s32 i;

    Ov001_GetSpritePosition(((s32 *)M2C_FIELD(&gOv001MenuLayout, void **, OV001_MENU_SPRITES))[1], 0, &pos[1], &pos[0]);
    pos[1] -= 8;
    if (pos[1] > 32) {
        for (i = 1; i < OV001_MENU_ROWS; i++) {
            Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout, void **, OV001_MENU_SPRITES))[i], -1, pos[1], ((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);
        }
        return;
    }
    pos[1] = 32;
    for (i = 1; i < OV001_MENU_ROWS; i++) {
        Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout, void **, OV001_MENU_SPRITES))[i], -1, pos[1], ((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);
    }
    Ov001_SetSlideStep(task, (M2C_UNK)Ov001_SlideMenuCloseStep4);
}

#pragma opt_strength_reduction off
/* Last step of the option-menu close slide: slide the five rows further left
 * until the first row has left the screen and wrapped in from the right edge
 * (x 0x1D6..0x100), then post the slide message, destroy the row sprites and
 * free the menu's allocation. */
void Ov001_SlideMenuCloseStep4(s32 task) {
extern s32 gOv001MenuLayout,data_ov001_02193e10;
extern const u8 Ov001MenuRowPositions[];
M2C_UNK Ov001_GetSpritePosition(M2C_UNK,M2C_UNK,M2C_UNK *,M2C_UNK *);
M2C_UNK Ov001_MoveSpriteLayout(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK Ov001_PostTaskMessage(M2C_UNK,M2C_UNK);
M2C_UNK Ov001_DestroySprite(M2C_UNK);
M2C_UNK Ov001_FreeAlloc(M2C_UNK);
s32 pos[2],i;
Ov001_GetSpritePosition(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,OV001_MENU_SPRITES))[0],0,&pos[1],&pos[0]);
pos[1]-=8;
for(i=0;i<OV001_MENU_ROWS;i++)Ov001_MoveSpriteLayout(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,OV001_MENU_SPRITES))[i],-1,pos[1],((const u16 (*)[2])Ov001MenuRowPositions)[i][1]);
if(pos[1]>0x1D6)return;
if(pos[1]<0x100)return;
Ov001_PostTaskMessage(0,task);
for(i=0;i<OV001_MENU_ROWS;i++)Ov001_DestroySprite(((s32 *)M2C_FIELD(&gOv001MenuLayout,void **,OV001_MENU_SPRITES))[i]);
Ov001_FreeAlloc(&data_ov001_02193e10);
}
#pragma opt_strength_reduction reset
s32 func_ov001_02185b34(void) {
    extern M2C_UNK gOv001MenuLayout;
    if (M2C_FIELD(&gOv001MenuLayout, void **, 4) == NULL) {
        return 1;
    }
    if (M2C_FIELD(M2C_FIELD(&gOv001MenuLayout, void **, 4), u8 *, 0x18) == 0) {
        return 1;
    }
    return 0;
}

void Ov001_LoadMenuResource(s32 arg0) {
    s32 Ov001_LocalizePath(s32);
    s32 Ov001_LoadFile(s32, s32, s32);
    void func_ov001_02185ba8(s32);
    extern s32 data_ov001_02190be4[];
    extern s32 gOv001MenuLayout;
    gOv001MenuLayout = Ov001_LoadFile(Ov001_LocalizePath(data_ov001_02190be4[arg0]), 0, 4);
    Ov001_AddTask(1, func_ov001_02185ba8, 0, 0x78);
}

void func_ov001_02185ba8(s32 arg0) {
    extern s32 gOv001MenuLayout;
    DC_FlushRange(gOv001MenuLayout, 0x600);
    func_0200442c(gOv001MenuLayout, 0, 0x600);
    Ov001_FreeFile(gOv001MenuLayout);
    Ov001_PostTaskMessage(1, arg0);
}

#pragma opt_common_subs off
/* Allocate the ov001 connection state and enter the WFC server lobby: wait for
 * the library to be ready, fill the profile request block (game id, connection
 * settings, the console's own user id and user list) and start the profile
 * exchange.  The game's connection callback is called from the reply handler.
 * Returns 1 once the lobby was entered, 0 when connecting failed. */
s32 Ov001_ConnectToWfcServer(s32 callback){
void *Ov001_Alloc(s32,s32);u64 GetSystemTick(void);
s32 func_02012218(M2C_UNK,M2C_UNK,M2C_UNK);
s32 func_02011af8(void *);u16 func_02011e98(void);void func_02007740(void *);
void MI_CpuCopy8(void *,void *,s32);s32 Ov001_SendServerRequest(void);
M2C_UNK Ov001_AddTask(M2C_UNK,void (*)(void),M2C_UNK,M2C_UNK);
M2C_UNK Ov001_FreeAlloc(M2C_UNK);
void func_ov001_02185ea8();void Ov001_ReportConnectionState();
extern void *gOv001ConnectionState;extern s32 gOv001MenuLayout;extern const u8 data_ov001_0218fbfc[],gOv001GameId[];
u8 buf[0x54];void *p;u64 ts;void **state;
gOv001ConnectionState=Ov001_Alloc(0x1ba0,0x20);
M2C_FIELD(gOv001ConnectionState,s32 *,OV001_CONN_CALLBACK)=callback;
ts=GetSystemTick();
state=&gOv001ConnectionState;
p=*state;
M2C_FIELD(p,u32 *,OV001_CONN_START_TICK)=(u32)ts;M2C_FIELD(p,u32 *,OV001_CONN_START_TICK+4)=(u32)(ts>>32);
/* wait for the library to finish starting, then for its response block */
if(func_02012218((M2C_UNK)*state,(M2C_UNK)func_ov001_02185ea8,3)==2){
do {
func_02011af8((u8 *)*state+OV001_CONN_RESPONSE);
p=*state;
} while(M2C_FIELD(p,u16 *,OV001_CONN_RESPONSE)!=2);
{
/* connection settings of the profile request, and its user search list */
*(InitBlock68 *)((u8 *)p+OV001_CONN_PROFILE)=*(const InitBlock68 *)data_ov001_0218fbfc;
{void *base=(u8 *)p+0xf00;p=(u8 *)p+0x1000;M2C_FIELD(p,void **,0x374)=base;}
}
M2C_FIELD(gOv001ConnectionState,u16 *,0x137c)=func_02011e98();
func_02007740(buf);
MI_CpuCopy8((void *)gOv001GameId,(u8 *)gOv001ConnectionState+OV001_CONN_GAME_ID,8);
M2C_FIELD(gOv001ConnectionState,u8 *,OV001_CONN_USER_COUNT)=1;
MI_CpuCopy8(buf+4,(u8 *)gOv001ConnectionState+OV001_CONN_USERS,M2C_FIELD(buf,u16 *,0x1a)<<1);
if(Ov001_SendServerRequest()){
M2C_FIELD(gOv001ConnectionState,M2C_UNK *,OV001_CONN_TIMER)=Ov001_AddTask(0,Ov001_ReportConnectionState,0,0x78);
return 1;
}
}
Ov001_FreeAlloc((M2C_UNK)(&gOv001MenuLayout+2));return 0;
}
#pragma opt_common_subs reset
s32 Ov001_SendServerRequest(void) {
    s32 WFC_SendRequestPacket(void (*)(void), void *);
    void func_ov001_02185ea8();
    extern void *gOv001ConnectionState;
    if (WFC_SendRequestPacket(func_ov001_02185ea8, (s8 *)gOv001ConnectionState + 0x1374) == 2) {
        return 1;
    }
    return 0;
}

#pragma opt_strength_reduction off
s32 func_ov001_02185dac(void) {
    s32 func_02011af8(void *);
    s32 func_02012274(void (*)(void));
    s32 func_020122ac(void (*)(void));
    void func_ov001_02185ea8(u16 *);
    void func_ov001_0218c94c(s32,s32);
    M2C_UNK Ov001_FreeAlloc(M2C_UNK);
    extern void *gOv001ConnectionState;
extern s32 gOv001MenuLayout;
u32 state;

    *(u8 *)((s8 *)gOv001ConnectionState + 0x1b94) = 1;
    func_02011af8((s8 *)gOv001ConnectionState + 0x13b8);
    if (*(u16 *)((s8 *)gOv001ConnectionState + 0x13b8) != 2) {
        if (func_02012274((void (*)(void))func_ov001_02185ea8) != 2) {
            return 0;
        }
        do {
            func_02011af8((s8 *)gOv001ConnectionState + 0x13b8);
        } while (*(u16 *)((s8 *)gOv001ConnectionState + 0x13b8) != 2);
    }
    if (func_020122ac((void (*)(void))func_ov001_02185ea8) != 2) {
        return 0;
    }
    if (M2C_FIELD((s8*)gOv001ConnectionState+0x1000,s32*,0xb90) != 0) {
        func_ov001_0218c94c(0,M2C_FIELD((s8*)gOv001ConnectionState+0x1000,s32*,0xb90));
    }
    state=M2C_FIELD((s8*)gOv001ConnectionState+0x1000,u8*,0xb94);
if(state != 2) goto done;
    Ov001_FreeAlloc((M2C_UNK)(&gOv001MenuLayout+2));
done:
    return 1;
}
#pragma opt_strength_reduction reset
void Ov001_SetConnectionStatusCallback(s32 arg0) {
    extern void *gOv001ConnectionState;
    M2C_FIELD(gOv001ConnectionState, s32 *, 0x1370) = arg0;
}

void func_ov001_02185ea8(u16 *p) {
extern void *gOv001ConnectionState;u32 v;void *q;
if(p[1])return;q=gOv001ConnectionState;
v=M2C_FIELD(q,u8 *,0x1b94);
if(v){if(p[0]==2)M2C_FIELD(q,u8 *,0x1b94)=2;return;}
v=p[0];if(v!=38)return;
v=p[4];switch(v){case 5:if(M2C_FIELD(q,u8 *,0x1b96))Ov001_MergeProfileList(p);else func_ov001_02185f38(p);Ov001_SendServerRequest();break;
case 4:Ov001_SendServerRequest();break;default:SystemHalt(p);break;}
}

#pragma opt_strength_reduction off
void func_ov001_02185f38(u16 *arg0) {
    void DC_InvalidateRange(void *, s32);
    s32 ByteCompareN(void *, const void *, s32);
    void MI_CpuCopy8(void *, void *, s32);
    extern void *gOv001ConnectionState;
    extern const u8 gOv001GameId[];
    extern const u8 gWfcEmptySlotId[];
    register u8 *rec;
    s32 k;
    register u8 *slot;
    s32 j;

    for (j = 0; j < arg0[7]; j++) {
        rec = ((void **)arg0)[4 + j];
        DC_InvalidateRange(rec, 0xC0);
        if (ByteCompareN(rec + 0xC, gOv001GameId, 8) != 0) continue;
        { register u8 *const base = gOv001ConnectionState;
        slot = base + 0x1300;
        for (k = 0; k < 16; k++) {
            if (ByteCompareN(rec + 4, slot, 6) == 0) {
                if (*(u8 *)(base + k * 7 + 0x1306) != 0) goto next;
                if (!(rec[0x15] & 1)) goto next;
                if (M2C_FIELD(base, void **, 0x1370) != NULL) {
                    ((void (*)(s32))M2C_FIELD(base, void **, 0x1370))(1);
                }
                return;
            }
            slot += 7;
        }
        slot = base + 0x1300;
        for (k = 0; k < 16; k++) {
            if (ByteCompareN(slot, gWfcEmptySlotId, 6) == 0) {
                MI_CpuCopy8(rec + 4, base + 0x1300 + k * 7, 6);
                *(u8 *)((u8 *)gOv001ConnectionState + k * 7 + 0x1306) = (rec[0x15] & 1) ? 1 : 0;
                break;
            }
            slot += 7;
        }
        }
    next:;
    }
}
#pragma opt_strength_reduction reset
/* Merge a server profile-list reply (reply[7] = profile count, reply[4..] =
 * the profile records) into the 16 player slots.  When a reply arrived before
 * the roster was reported, report that first instead.  For each online profile
 * of this game whose user id is already in a slot, report the connection state
 * (1) once and mark the slot/flag so it is not reported again. */
void Ov001_MergeProfileList(u16 *reply) {
    void DC_InvalidateRange(void *, s32);
    s32 ByteCompareN(void *, const void *, s32);
    extern void *gOv001ConnectionState;
    extern const u8 gOv001GameId[];

    void *state = gOv001ConnectionState;
    u8 deferred = *((u8 *)state + WFC_CONN_SLOT_DEFERRED);
    if (deferred != 0) {
        void (*cb)(s32) = *(void (**)(s32))((u8 *)state + WFC_CONN_STATUS_CB);
        if (cb != 0) {
            cb(deferred);
        }
        return;
    }

    DC_InvalidateRange((u8 *)state + 0x0F00, 0x400);

    {
        u8 *profile;
        s32 i;
        s32 slot;
        u8 *slotId;
        u16 count = reply[7];

        i = 0;
        if (i < count) {
            state = gOv001ConnectionState;
            do {
                profile = ((void **)reply)[4 + i];
                if (ByteCompareN(profile + PROFILE_RECORD_GAME_ID, gOv001GameId, 8) != 0) {
                    goto next;
                }
                if (!(profile[PROFILE_RECORD_STATE] & 1)) {
                    goto next;
                }
                slotId = (u8 *)state + WFC_CONN_SLOTS;
                for (slot = 0; slot < WFC_CONN_SLOT_COUNT; slot = slot + 1) {
                    if (ByteCompareN(profile + PROFILE_RECORD_USBID, slotId, 6) == 0) {
                        if (M2C_FIELD((u8 *)state + slot * 7 + 0x1000, u8 *, 0x300 + WFC_CONN_SLOT_ONLINE) != 0) {
                            break;
                        }
                        {
                            void (*cb)(s32) = *(void (**)(s32))((u8 *)state + WFC_CONN_STATUS_CB);
                            if (cb == 0) {
                                *((u8 *)state + WFC_CONN_SLOT_DEFERRED) = 1;
                                return;
                            }
                            cb(1);
                            return;
                        }
                    }
                    slotId += WFC_CONN_SLOT_STRIDE;
                }
            next:
                i++;
            } while (i < count);
        }
    }
}

/* Connection-watch timer callback: once the watch delay after the connection
 * started has passed, scan the 16 player slots and report the final state
 * (none, all online, or mixed) through the status callback, then stop the
 * timer and mark the watch done. */
void Ov001_ReportConnectionState(s32 arg0) {
    u64 GetSystemTick(void);
    s32 ByteCompareN(void *, const void *, s32);
    M2C_UNK Ov001_PostTaskMessage(M2C_UNK, M2C_UNK);
    extern void *gOv001ConnectionState;
    extern const u8 gWfcEmptySlotId[];
    u64 now;
    s32 i;
    s32 hasOnline;
    s32 hasOffline;
    u8 *slotId;
    u8 *slot;
    u8 *state;

    now = GetSystemTick();
    state = gOv001ConnectionState;
    if (now < M2C_FIELD(state, u64 *, WFC_CONN_WATCH_START) + 0x17F898) {
        return;
    }
    hasOffline = 0;
    hasOnline = 0;
    i = 0;
    slot = state;
    slotId = state + WFC_CONN_SLOTS;
    for (; i < WFC_CONN_SLOT_COUNT; i++) {
        if (ByteCompareN(slotId, gWfcEmptySlotId, 6) != 0) {
            if (M2C_FIELD(slot, u8 *, WFC_CONN_SLOTS + WFC_CONN_SLOT_ONLINE) != 0) {
                hasOnline = 1;
            } else {
                hasOffline = 1;
            }
        }
        slotId += WFC_CONN_SLOT_STRIDE;
        slot += WFC_CONN_SLOT_STRIDE;
    }
    if (hasOnline && hasOffline) {
        if (M2C_FIELD(state, void **, WFC_CONN_STATUS_CB) != NULL) {
            ((void (*)(s32)) M2C_FIELD(state, void **, WFC_CONN_STATUS_CB))(WFC_CONN_STATUS_MIXED);
        }
    } else if (hasOnline) {
        if (M2C_FIELD(state, void **, WFC_CONN_STATUS_CB) != NULL) {
            ((void (*)(s32)) M2C_FIELD(state, void **, WFC_CONN_STATUS_CB))(WFC_CONN_STATUS_ONLINE);
        }
    } else if (!hasOffline) {
        if (M2C_FIELD(state, void **, WFC_CONN_STATUS_CB) != NULL) {
            ((void (*)(s32)) M2C_FIELD(state, void **, WFC_CONN_STATUS_CB))(WFC_CONN_STATUS_NONE);
        }
    }
    M2C_FIELD(gOv001ConnectionState, s32 *, WFC_CONN_WATCH_TIMER) = 0;
    M2C_FIELD(gOv001ConnectionState, u8 *, WFC_CONN_WATCH_DONE) = 1;
    Ov001_PostTaskMessage(0, arg0);
}

#pragma scheduling on
#pragma opt_strength_reduction off
#pragma opt_propagation off
void Ov001_ShowMessage(void *a, s32 b, void *c, s32 d, s32 e) {
void *func_ov001_02175f60(void*,s32,s32,s32);void *Ov001_Alloc(s32,s32);
void GX_SetBlendControl(s32,s32,s32);s32 Ov001_CreateSprite(s32,s32,s32);
s32 Ov001_MoveSpriteLayout(s32,s32,s32,s32);void Ov001_SetSpritePalette(s32,s32,s32);
s32 CreatePooledTextPanel(s32,s32,s32,s32,s32*,s32);s32 func_ov001_0218a070(s32,s32,s32);
s32 Ov001_GetTextFontId(void);void DrawPanelText(s32,s32,s32,s32,s32,s32,s32,void*);
void func_ov001_0218b200(s32,s32,s32,s32,s32);void func_ov001_0218b4dc(s32,s32,s32,s32);
void SetWindowRect(s32,s32,const void*);s32 Ov001_SetRegionMenuY(s32);
s32 Ov001_AddTask(s32,void(*)(),s32,s32);void func_ov001_02186678();void Ov001_SlideRegionMenuIn();
extern const u8 data_ov001_0218fc40[],data_ov001_0218fcf4[],data_ov001_0218fc66[],data_ov001_0218fc4a[];
extern u8 gOv001RegionItemCount[];
extern const u16 data_ov001_0218fc86[],data_ov001_0218fc84[];
extern void *gOv001RegionMenu,*gOv001MessageArchive;
u8 palette[6];
register void **archiveAddress = &gOv001MessageArchive;
s32 layout;void *text; s32 i;const u8 *items;
void *messageArchive=*archiveAddress;
palette[0]=data_ov001_0218fc40[4];
palette[1]=data_ov001_0218fc40[5];
palette[2]=data_ov001_0218fc40[6];
palette[3]=data_ov001_0218fc40[7];
palette[4]=data_ov001_0218fc40[8];
palette[5]=data_ov001_0218fc40[9];
text=func_ov001_02175f60(messageArchive,(s32)a,d,e);
gOv001RegionMenu=Ov001_Alloc(32,4);
M2C_FIELD(gOv001RegionMenu,u8*,0x1c)=b;
M2C_FIELD(gOv001RegionMenu,s8*,0x1b)=-2;
M2C_FIELD(gOv001RegionMenu,u8*,0x1e)=(s32)c;
GX_SetBlendControl(0x4000050,31,0);
M2C_FIELD(gOv001RegionMenu,s32*,0)=Ov001_CreateSprite(0,data_ov001_0218fcf4[b],0);
Ov001_MoveSpriteLayout(M2C_FIELD(gOv001RegionMenu,s32*,0),-1,256,0);
Ov001_SetSpritePalette(M2C_FIELD(gOv001RegionMenu,s32*,0),-1,0);
i=0;if(i<gOv001RegionItemCount[b]){items=data_ov001_0218fc66+b*2;do{
M2C_FIELD((u8*)gOv001RegionMenu+i*4,s32*,8)=Ov001_CreateSprite(0,*items++,0);
Ov001_MoveSpriteLayout(M2C_FIELD((u8*)gOv001RegionMenu+i*4,s32*,8),-1,256,0);
Ov001_SetSpritePalette(M2C_FIELD((u8*)gOv001RegionMenu+i*4,s32*,8),-1,0);
i++;}while(i<gOv001RegionItemCount[b]);}
M2C_FIELD(gOv001RegionMenu,s32*,0x10)=CreatePooledTextPanel(0,32,12,1,&layout,0);
M2C_FIELD(gOv001RegionMenu,s32*,4)=func_ov001_0218a070(0,layout,0);
DrawPanelText(M2C_FIELD(gOv001RegionMenu,s32*,0x10),0,0,data_ov001_0218fc84[b*2],data_ov001_0218fc86[b*2],2,Ov001_GetTextFontId(),text);
func_ov001_0218b200(M2C_FIELD(gOv001RegionMenu,s32*,0x10),256,0,M2C_FIELD(gOv001RegionMenu,s32*,4),0);
func_ov001_0218b4dc(0,0,31,0);
func_ov001_0218b4dc(0,1,31,palette[M2C_FIELD(gOv001RegionMenu,u8*,0x1c)]);
func_ov001_0218b4dc(0,3,31,1);
SetWindowRect(0,1,data_ov001_0218fc4a);
Ov001_SetRegionMenuY(192);
*(volatile u32*)0x4000000=(*(volatile u32*)0x4000000&~0xe000)|0x6000;
if(c) M2C_FIELD(gOv001RegionMenu,s32*,0x14)=Ov001_AddTask(1,func_ov001_02186678,0,120);
else M2C_FIELD(gOv001RegionMenu,s32*,0x14)=Ov001_AddTask(1,Ov001_SlideRegionMenuIn,0,120);
}
#pragma scheduling reset
void func_ov001_02186604(void) {
extern void *gOv001RegionMenu;void func_ov001_02186c68();s32 Ov001_AddTask(s32,void (*)(),s32,s32);
Ov001_PostTaskMessage(0,M2C_FIELD(gOv001RegionMenu,s32 *,20));
M2C_FIELD(gOv001RegionMenu,s32 *,20)=Ov001_AddTask(1,func_ov001_02186c68,0,120);
}

s8 func_ov001_02186648(void) {
    extern void *gOv001RegionMenu;
    return M2C_FIELD(gOv001RegionMenu, s8 *, 0x1B);
}

s32 func_ov001_0218665c(void) {
    extern void *gOv001RegionMenu;
    if (gOv001RegionMenu != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02186678(s32 a) {
extern void *gOv001RegionMenu;void Ov001_SlideRegionMenuIn();
M2C_FIELD(gOv001RegionMenu,s8 *,26)--;
GX_SetBlendY(0x4000050,M2C_FIELD(gOv001RegionMenu,s8 *,26));
if(M2C_FIELD(gOv001RegionMenu,s8 *,26)<=-12)Ov001_SetSlideStep(a,Ov001_SlideRegionMenuIn);
}

/* Open step of the ov001 region-column menu: slide the column up from the bottom
 * of the screen 12 pixels a frame until it rests at the selected region's y, then
 * hand the menu to its input task (or, for the region without items, to the
 * timeout task) and report the open step to the task that drives it. */
void Ov001_SlideRegionMenuIn(s32 task) {
    extern void *gOv001RegionMenu;
    extern const u16 gOv001RegionYs[];
    M2C_UNK Ov001_SetRegionMenuY(M2C_UNK);
    void Ov001_RegionMenuEmptyTimeout(void);
    void Ov001_UpdateRegionMenuInput(void);
    M2C_UNK Ov001_AddTask(M2C_UNK, void (*)(void), M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_PostTaskMessage(M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_GetSpritePosition(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *);
    s32 pos[2];

    Ov001_GetSpritePosition(M2C_FIELD(gOv001RegionMenu, s32 *, OV001_REGION_SPRITE_TOP), 0, &pos[1], &pos[0]);
    pos[0] -= OV001_REGION_OPEN_STEP;
    if (pos[0] > gOv001RegionYs[M2C_FIELD(gOv001RegionMenu, u8 *, OV001_REGION_INDEX) << 1]) {
        Ov001_SetRegionMenuY(pos[0]);
        return;
    }
    Ov001_SetRegionMenuY(gOv001RegionYs[M2C_FIELD(gOv001RegionMenu, u8 *, OV001_REGION_INDEX) << 1]);
    if (M2C_FIELD(gOv001RegionMenu, u8 *, OV001_REGION_INDEX) == OV001_REGION_EMPTY) {
        M2C_FIELD(gOv001RegionMenu, s32 *, OV001_REGION_TASK) =
            (M2C_UNK)Ov001_AddTask(0, (void (*)(void))Ov001_RegionMenuEmptyTimeout, 0, 0x78);
    } else {
        M2C_FIELD(gOv001RegionMenu, s32 *, OV001_REGION_TASK) =
            (M2C_UNK)Ov001_AddTask(0, (void (*)(void))Ov001_UpdateRegionMenuInput, 0, 0x78);
    }
    Ov001_PostTaskMessage(1, task);
}

