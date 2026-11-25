/* 37 functions from 0x02183A20 to 0x02184960 (ov001), found by ds-decomp. */
#include "common.h"
#include "wfc.h"

#pragma opt_common_subs off
void func_ov001_02183a20(void) {
    s32 Ov001_HitScrollbarPart(void);
    void Ov001_PressScrollbarCap(s8);
    s32 Ov001_HitReleasedScrollbarCap(void);
    void Ov001_ScrollbarJumpToTouch(void);
    void Ov001_UpdateScrollbarDrag(void);
    void Ov001_PlaySound(s32);
    void Ov001_SetScrollDragSoundLevel(s32);
    void Ov001_ReadTouchPoint(M2C_UNK *);
    extern void *gOv001Scrollbar;
    s32 r;

    M2C_FIELD(gOv001Scrollbar, u8 *, 0x1d) = 0;
    switch ((u8)M2C_FIELD(gOv001Scrollbar, u8 *, 0x1c)) {
        case 0: {
            r = (s32)(u8)M2C_FIELD(gOv001Scrollbar, u8 *, 0x1e);
            if (r != 0) {
                return;
            }
            r = Ov001_HitScrollbarPart();
            switch (r) {
                case 1: {
                    if ((u8)M2C_FIELD(gOv001Scrollbar, u8 *, 0x1b) == 0) {
                        return;
                    }
                    Ov001_PlaySound(0x16);
                    Ov001_SetScrollDragSoundLevel(0);
                    M2C_FIELD(gOv001Scrollbar, u8 *, 0x1d) = 1;
                    Ov001_ReadTouchPoint((M2C_UNK *)((u8 *)gOv001Scrollbar + 0x14));
                    M2C_FIELD(gOv001Scrollbar, u8 *, 0x18) = M2C_FIELD(gOv001Scrollbar, u8 *, 0x1a);
                    M2C_FIELD(gOv001Scrollbar, u8 *, 0x1c) = 1;
                    return;
                }
                case 2:
                    Ov001_PressScrollbarCap(2);
                    return;
                case 3:
                    Ov001_PressScrollbarCap(3);
                    return;
                case 4:
                    Ov001_ScrollbarJumpToTouch();
                    return;
            }
            return;
        }
        case 1:
            Ov001_UpdateScrollbarDrag();
            return;
        case 2: {
            r = ((s32 (*)(s32))Ov001_HitReleasedScrollbarCap)(2);
            if (r != 2) {
                M2C_FIELD(gOv001Scrollbar, u8 *, 0x1d) = 5;
                M2C_FIELD(gOv001Scrollbar, u8 *, 0x1c) = 0;
                return;
            }
            r = Ov001_HitScrollbarPart();
            if (r != 2) {
                return;
            }
            Ov001_PressScrollbarCap(2);
            return;
        }
        case 3: {
            r = ((s32 (*)(s32))Ov001_HitReleasedScrollbarCap)(3);
            if (r != 3) {
                M2C_FIELD(gOv001Scrollbar, u8 *, 0x1d) = 7;
                M2C_FIELD(gOv001Scrollbar, u8 *, 0x1c) = 0;
                return;
            }
            r = Ov001_HitScrollbarPart();
            if (r != 3) {
                return;
            }
            Ov001_PressScrollbarCap(3);
            return;
        }
        default:
            return;
    }
}
#pragma opt_common_subs reset
/* The friend roster's scroll bar, drag state: while the stylus is down, move the
 * handle to follow its y (clamped into the track); once it lifts, stop the drag
 * sound and report the idle event. */
void Ov001_UpdateScrollbarDrag(void) {
    s32 TouchRectReleased(M2C_UNK *);
    void Ov001_ReadTouchPoint(M2C_UNK *);
    void Ov001_PlayScrollDragSound(s32);
    void Ov001_SetScrollbarHandlePos(s32);
    void Ov001_StopSound(void);
    extern void *gOv001Scrollbar;
    extern u8 gOv001ScrollbarHandleLengths[];
    extern u8 gTouchScreenRect[];
    M2C_UNK touch;
    void *bar;
    s32 handlePos;
    u16 touchX;
    u16 touchY;
    s32 dragXLimit;

    if (TouchRectReleased((M2C_UNK *)gTouchScreenRect) != 0) {
        Ov001_ReadTouchPoint(&touch);
        touchX = M2C_FIELD(&touch, u16 *, 0x0);
        bar = gOv001Scrollbar;
        dragXLimit = M2C_FIELD(bar, u16 *, OV001_SCROLLBAR_X) - 0x1e;
        if (touchX >= dragXLimit) {
            touchY = M2C_FIELD(&touch, u16 *, 0x2);
            handlePos = (s32)(u8)M2C_FIELD(bar, u8 *, OV001_SCROLLBAR_DRAG_OFFSET) + ((s32)touchY - (s32)(u16)M2C_FIELD(bar, u16 *, OV001_SCROLLBAR_H));
            if (handlePos < 0) {
                handlePos = 0;
            } else {
                s32 maxHandlePos = (s32)(u8)M2C_FIELD(bar, u8 *, OV001_SCROLLBAR_TRACK) - (s32)(u8)gOv001ScrollbarHandleLengths[(u8)M2C_FIELD(bar, u8 *, OV001_SCROLLBAR_KIND)];
                if (handlePos >= maxHandlePos) {
                    handlePos = maxHandlePos;
                }
            }
            Ov001_PlayScrollDragSound(handlePos);
            Ov001_SetScrollbarHandlePos(handlePos);
            M2C_FIELD(gOv001Scrollbar, u8 *, OV001_SCROLLBAR_EVENT) = 2;
            return;
        }
    }
    Ov001_StopSound();
    M2C_FIELD(gOv001Scrollbar, u8 *, OV001_SCROLLBAR_STATE) = 0;
    M2C_FIELD(gOv001Scrollbar, u8 *, OV001_SCROLLBAR_EVENT) = 3;
}

/* Play the scrollbar's drag sound for a handle moved from its current offset to
 * `handlePos`: the farther it moved, the louder and higher-pitched the tick; a
 * move under two pixels is silent and a move of six or more is full level. */
void Ov001_PlayScrollDragSound(s32 handlePos) {
    s32 HardwareDivide(s32, s32);
    void Ov001_SetScrollDragSoundLevel(M2C_UNK);
    void Ov001_SetScrollDragSoundPitch(s32, s32);
    extern void *gOv001Scrollbar;
    s32 current;
    s32 moved;
    s32 pitch;

    current = M2C_FIELD(gOv001Scrollbar, u8 *, OV001_SCROLLBAR_HANDLE_POS);
    moved = current - handlePos;
    if (moved < 0) {
        moved = -moved;
    }
    Ov001_SetScrollDragSoundLevel(moved < 2 ? 0 : (moved >= 6 ? 0x7F : HardwareDivide(0x7F, 6 - moved)));
    pitch = moved < 2 ? -256 : (moved >= 6 ? 0x100 : HardwareDivide(0x200, 6 - moved) - 0x100);
    Ov001_SetScrollDragSoundPitch(0xFFFF, pitch);
}

/* A scroll bar cap was pressed (`cap` is OV001_SCROLLBAR_PART_UP or _DOWN):
 * hold the bar in cap-scroll state and report the matching press event so the
 * owning list starts scrolling one page. */
void Ov001_PressScrollbarCap(s8 cap) {
    extern void *gOv001Scrollbar;
    s8 event;

    M2C_FIELD(gOv001Scrollbar, s8 *, OV001_SCROLLBAR_STATE) = cap;
    if (cap == OV001_SCROLLBAR_PART_UP) {
        event = OV001_SCROLLBAR_EVENT_UP_PRESS;
    } else {
        event = OV001_SCROLLBAR_EVENT_DOWN_PRESS;
    }
    M2C_FIELD(gOv001Scrollbar, s8 *, OV001_SCROLLBAR_EVENT) = event;
}

#pragma peephole off
/* A tap on the scrollbar track: move the handle so its middle sits under the
 * touch y, clamped into the track, and report the bar-scroll event. */
void Ov001_ScrollbarJumpToTouch(void) {
void Ov001_ReadTouchPoint(M2C_UNK *);
void Ov001_SetScrollbarHandlePos(s32);
extern void *gOv001Scrollbar;
extern u8 gOv001ScrollbarHandleLengths[];
M2C_UNK touch;
u32 handleLength;
u16 trackY,touchY;
s32 pos; u8 trackLength; s32 maxPos;
Ov001_ReadTouchPoint(&touch);
handleLength=gOv001ScrollbarHandleLengths[M2C_FIELD(gOv001Scrollbar,u8 *,OV001_SCROLLBAR_KIND)];
trackY=M2C_FIELD(gOv001Scrollbar,u16 *,OV001_SCROLLBAR_Y);
touchY=M2C_FIELD(&touch,u16 *,2);
pos=(s32)touchY-(s32)trackY;
pos-=(s32)(handleLength>>1);
if(pos<0) pos=0;
else {
trackLength=M2C_FIELD(gOv001Scrollbar,u8 *,OV001_SCROLLBAR_TRACK);
maxPos=(s32)trackLength-(s32)handleLength;
if(pos>=maxPos) pos=maxPos;
}
Ov001_SetScrollbarHandlePos(pos);
M2C_FIELD(gOv001Scrollbar,u8 *,OV001_SCROLLBAR_EVENT)=3;
}
#pragma peephole reset
/* Which part of the friend roster's scrollbar the stylus tapped: the handle, the
 * up or down cap, the track, or 0 when it missed the bar. */
s32 Ov001_HitScrollbarPart(void) {
    void Ov001_GetScrollbarPartRect(s32, M2C_UNK *);
    s32 TouchRectPressed(M2C_UNK *);
    s32 TouchRectPressOrRepeat(M2C_UNK *);
    s32 rect[2];
    s32 part;

    Ov001_GetScrollbarPartRect(OV001_SCROLLBAR_PART_HANDLE, rect);
    if (TouchRectPressOrRepeat(rect) != 0) {
        return OV001_SCROLLBAR_PART_HANDLE;
    }
    part = OV001_SCROLLBAR_PART_UP;
loop_3:
    Ov001_GetScrollbarPartRect(part, rect);
    if (TouchRectPressOrRepeat(rect) != 0) {
        return part;
    }
    part += 1;
    if (part > OV001_SCROLLBAR_PART_DOWN) {
        Ov001_GetScrollbarPartRect(OV001_SCROLLBAR_PART_TRACK, rect);
        if (TouchRectPressed(rect) != 0) {
            return OV001_SCROLLBAR_PART_TRACK;
        }
        return 0;
    }
    goto loop_3;
}

/* Which scroll-bar cap a released touch hit: checks the up then the down cap and
 * returns its OV001_SCROLLBAR_PART_*, or 0 when the release missed both. */
s32 Ov001_HitReleasedScrollbarCap(void) {
    void Ov001_GetScrollbarPartRect(s32, M2C_UNK *);
    s32 TouchRectReleased(M2C_UNK *);
    s32 rect[2];
    s32 part;

    part = OV001_SCROLLBAR_PART_UP;
loop_1:
    Ov001_GetScrollbarPartRect(part, rect);
    if (TouchRectReleased(rect) != 0) {
        return part;
    }
    part += 1;
    if (part <= OV001_SCROLLBAR_PART_DOWN) {
        goto loop_1;
    }
    return 0;
}

/* Fill `rect` with the touch rectangle (left, top, right, bottom) of one part of
 * the friend roster's vertical scroll bar: the handle, the cap above or below
 * the track, or the track itself.  The bar is a 12-pixel-wide column. */
void Ov001_GetScrollbarPartRect(s32 part, M2C_UNK *rect) {
    extern void *gOv001Scrollbar;
    extern u8 gOv001ScrollbarHandleLengths[];
    u16 barX;

    barX = M2C_FIELD(gOv001Scrollbar, u16 *, OV001_SCROLLBAR_X);
    M2C_FIELD(rect, u16 *, RECT_LEFT) = barX;
    M2C_FIELD(rect, u16 *, RECT_RIGHT) = (u16)(barX + 0xC);
    switch (part) {
        case 0:
        default:
            break;
        case OV001_SCROLLBAR_PART_HANDLE: {
            M2C_FIELD(rect, u16 *, RECT_TOP) = (u16)(M2C_FIELD(gOv001Scrollbar, u16 *, OV001_SCROLLBAR_Y) + M2C_FIELD(gOv001Scrollbar, u8 *, OV001_SCROLLBAR_HANDLE_POS));
            M2C_FIELD(rect, u16 *, RECT_BOTTOM) = (u16)(M2C_FIELD(rect, u16 *, RECT_TOP) + (u16)gOv001ScrollbarHandleLengths[M2C_FIELD(gOv001Scrollbar, u8 *, OV001_SCROLLBAR_KIND)]);
            break;
        }
        case OV001_SCROLLBAR_PART_UP: {
            M2C_FIELD(rect, u16 *, RECT_TOP) = (u16)(M2C_FIELD(gOv001Scrollbar, u16 *, OV001_SCROLLBAR_Y) - 0xD);
            M2C_FIELD(rect, u16 *, RECT_BOTTOM) = M2C_FIELD(gOv001Scrollbar, u16 *, OV001_SCROLLBAR_Y);
            break;
        }
        case OV001_SCROLLBAR_PART_DOWN: {
            M2C_FIELD(rect, u16 *, RECT_TOP) = (u16)(M2C_FIELD(gOv001Scrollbar, u16 *, OV001_SCROLLBAR_Y) + M2C_FIELD(gOv001Scrollbar, u8 *, OV001_SCROLLBAR_TRACK));
            M2C_FIELD(rect, u16 *, RECT_BOTTOM) = (u16)(M2C_FIELD(rect, u16 *, RECT_TOP) + 0xD);
            break;
        }
        case OV001_SCROLLBAR_PART_TRACK: {
            u16 barY;
            barY = M2C_FIELD(gOv001Scrollbar, u16 *, OV001_SCROLLBAR_Y);
            M2C_FIELD(rect, u16 *, RECT_TOP) = barY;
            M2C_FIELD(rect, u16 *, RECT_BOTTOM) = (u16)(barY + M2C_FIELD(gOv001Scrollbar, u8 *, OV001_SCROLLBAR_TRACK));
            break;
        }
    }
}

/* Move the scrollbar's handle sprite to `handlePos` pixels down the track and
 * remember the new handle offset. */
void Ov001_SetScrollbarHandlePos(s32 handlePos) {
    s32 Ov001_MoveSpriteLayout(M2C_UNK, s32, u16, s32);
    extern void *gOv001Scrollbar;
    u16 trackX;
    u16 trackY;
    void *handle;
    void *bar;

    bar = gOv001Scrollbar;
    trackY = M2C_FIELD(bar, u16 *, OV001_SCROLLBAR_Y);
    trackX = M2C_FIELD(bar, u16 *, OV001_SCROLLBAR_X);
    handle = M2C_FIELD(bar, void **, OV001_SCROLLBAR_SPRITE);
    Ov001_MoveSpriteLayout(handle, -1, trackX, handlePos + (s32)trackY);
    M2C_FIELD(gOv001Scrollbar, s8 *, OV001_SCROLLBAR_HANDLE_POS) = (s8)handlePos;
}

/* Allocate the Wi-Fi friend roster buffer once, a 32-byte-aligned
 * WFC_FRIEND_ROSTER_SIZE block, and keep its handle in gWfcFriendRoster. */
void Ov001_AllocFriendRoster(void) {
    s32 Ov001_Alloc(s32, M2C_UNK);
    extern s32 gWfcFriendRoster;
    if (gWfcFriendRoster != 0) {
        return;
    }
    gWfcFriendRoster = Ov001_Alloc(WFC_FRIEND_ROSTER_SIZE, 0x20);
}

#pragma opt_common_subs off
#pragma pool_constants off
/* Free the Wi-Fi friend roster buffer once the WFC connection is up: the handle
 * Ov001_AllocFriendRoster allocated (the word just before gSaveData, which the
 * file reuses so the address shares its literal pool entry), or nothing when the
 * roster was never allocated. */
void Ov001_FreeFriendRoster(void) {
    u16 WFC_GetPlayerMask(void);
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern M2C_UNK gWfcFriendRoster; /* roster handle, 0 while not allocated */
    extern s32 gSaveData;

    if (*(volatile M2C_UNK *)&gWfcFriendRoster == 0) return;
    while (WFC_GetPlayerMask() != WFC_PLAYER_MASK_READY) {}
    Ov001_FreeAlloc(&gSaveData - 1);
}
#pragma pool_constants reset
#pragma opt_common_subs reset
/* Opens the friend roster: clears its slots, opens the WFC channel that fetches
 * the roster, waits for the reply, then builds the request packet from its
 * defaults and the local console id and sends it.  Returns 0 when the channel
 * or the request cannot be started. */
s32 Ov001_OpenFriendRoster(void) {
    s32 FillU16(s32, void *, s32);
    s32 WFC_StartCommandChannel(void *, void (*)(void), s32);
    s32 WFC_GetConnectionData(void *);
    u16 GetConsoleLocalId(void);
    s32 Ov001_SendFriendRosterRequest(void);
    void Ov001_HandleFriendRosterReply();
    extern s32 gWfcFriendRoster;
    extern u32 gFriendRosterRequestDefaults[];
    u8 *base;

    FillU16(0, (u8 *)gWfcFriendRoster + WFC_FRIEND_SLOTS, WFC_FRIEND_SLOTS_SIZE);
    if (WFC_StartCommandChannel((void *)gWfcFriendRoster, Ov001_HandleFriendRosterReply, 3) != WFC_CMD_OK)
        return 0;
    do {
        WFC_GetConnectionData((u8 *)gWfcFriendRoster + WFC_FRIEND_REPLY);
        base = (u8 *)gWfcFriendRoster;
    } while (*(u16 *)(base + WFC_FRIEND_REPLY) != WFC_REPLY_DONE);
    *(WfcFriendRosterRequest *)(base + WFC_FRIEND_REQUEST) = *(const WfcFriendRosterRequest *)gFriendRosterRequestDefaults;
    *(u8 **)(base + WFC_FRIEND_REQUEST) = base + 0xf00;
    *(u16 *)((u8 *)(*(s32 *)&gWfcFriendRoster) + WFC_FRIEND_REQUEST + 8) = GetConsoleLocalId();
    return Ov001_SendFriendRosterRequest() ? 1 : 0;
}

/* Ask the WFC server for the friend roster by posting the roster request packet
 * at WFC_FRIEND_REQUEST; returns 1 once the request is queued (WFC_CMD_OK). */
s32 Ov001_SendFriendRosterRequest(void) {
    s32 WFC_SendRequestPacket(void (*)(void), void *);
    void Ov001_HandleFriendRosterReply();
    extern s32 gWfcFriendRoster;
    void *roster = (void *)gWfcFriendRoster;

    if (WFC_SendRequestPacket(Ov001_HandleFriendRosterReply, (s8 *)roster + WFC_FRIEND_REQUEST) == WFC_CMD_OK) {
        return 1;
    }
    return 0;
}

/* End the friend-roster link: mark the roster as closing, read its reply block
 * (and, while the request is still in flight, queue the cancel and wait for the
 * reply to arrive), then end the WFC link. */
s32 Ov001_CloseFriendRoster(void) {
    s32 WFC_GetConnectionData(void *);
    s32 WFC_SendCommand1(void (*)(void));
    s32 WFC_EndLink(void (*)(void));
    void Ov001_HandleFriendRosterReply();
    extern s32 gWfcFriendRoster;

    *(u8 *)((s8 *)gWfcFriendRoster + WFC_FRIEND_CLOSING) = 1;
    WFC_GetConnectionData((void *)((s8 *)gWfcFriendRoster + WFC_FRIEND_REPLY));
    if (*(u16 *)((s8 *)gWfcFriendRoster + WFC_FRIEND_REPLY) != WFC_REPLY_DONE) {
        if (WFC_SendCommand1(Ov001_HandleFriendRosterReply) != WFC_CMD_OK) {
            return 0;
        }
        do {
            WFC_GetConnectionData((void *)((s8 *)gWfcFriendRoster + WFC_FRIEND_REPLY));
        } while (*(u16 *)((s8 *)gWfcFriendRoster + WFC_FRIEND_REPLY) != WFC_REPLY_DONE);
    }
    if (WFC_EndLink(Ov001_HandleFriendRosterReply) != WFC_CMD_OK) {
        return 0;
    }
    return 1;
}

s32 Ov001_GetFriendSlots(void **arg0) {
    s32 ByteCompareN(M2C_UNK, M2C_UNK, s32);
    extern u8 data_ov001_0218fb64[];
    extern s32 gWfcFriendRoster;
    WfcFriendSlot *p;
    u8 *emptyCode;
    s32 count;
    s32 i;

    count = 0;
    p = (WfcFriendSlot *)((u8 *)gWfcFriendRoster + WFC_FRIEND_SLOTS);
    *arg0 = p;
    emptyCode = data_ov001_0218fb64;
    for (i = 0; i < WFC_FRIEND_SLOT_COUNT; i++) {
        if (ByteCompareN((M2C_UNK)p->code, (M2C_UNK)emptyCode, sizeof(p->code)) != 0) {
            count = count + 1;
        }
        p++;
    }
    return count;
}

/* Completion callback of the friend-roster request: ignore a failed reply, then,
 * unless the roster link is closing, answer the server's operation - a profile
 * list is parsed into the roster slots and polling continues, the accepted "next"
 * operation just polls again, and any other operation halts the system. */
void Ov001_HandleFriendRosterReply(u16 *reply) {
    s32 Ov001_SendFriendRosterRequest(void);
    void Ov001_ParseFriendRosterReply(u16 *);
    void SystemHalt(u16 *);
    extern s32 gWfcFriendRoster;
    u8 *q;

    if (reply[WFC_REPLY_RESULT]) {
        return;
    }
    q = (u8 *)gWfcFriendRoster + 0x1000;
    if (q[WFC_FRIEND_CLOSING - 0x1000] == 0 && reply[WFC_REPLY_COMMAND] == WFC_REQUEST_COMMAND) {
        switch (reply[WFC_REPLY_OP]) {
            case WFC_REQUEST_OP_PROFILE_LIST:
                Ov001_ParseFriendRosterReply(reply);
                Ov001_SendFriendRosterRequest();
                break;
            case WFC_REQUEST_OP_NEXT:
                Ov001_SendFriendRosterRequest();
                break;
            default:
                SystemHalt(reply);
                break;
        }
    }
}

#pragma opt_lifetimes off
#pragma opt_loop_invariants off
void Ov001_ParseFriendRosterReply(u16 *arg0) {
    void DC_InvalidateRange(void *, s32);
    void MI_CpuCopy8(void *, void *, u32);
    s32 ByteCompareN(M2C_UNK, M2C_UNK, s32);
    void func_02011f2c(M2C_UNK *, M2C_UNK *);
    extern s32 gWfcFriendRoster;
    extern u8 data_ov001_0218fb64[];
    extern u8 data_ov001_0218fb60[];

    typedef struct { u8 kind; u8 length; u8 pad[2]; void *data; } ParsedItem;
    typedef struct { u8 count; u8 pad[3]; ParsedItem items[16]; } ParsedItems;
    typedef struct { WfcFriendSlot *slots; ParsedItems parsed; } Work;

    typedef struct { u8 pad[14]; u16 count; u8 *records[16]; u16 values[16]; } ScanResults;
    ScanResults *results = (ScanResults *)arg0;
    s32 i;
    register u8 *record;
    Work work;

    {
        u8 *roster = (u8 *)gWfcFriendRoster;
        void *cache = roster + 0xf00;
        work.slots = (WfcFriendSlot *)(roster + WFC_FRIEND_SLOTS);
        DC_InvalidateRange(cache, 0x400);
    }

    i = 0;
    if ((s32)results->count <= 0) {
        return;
    }
    do {
        record = results->records[i];
        if (record[0xc] != 0 && *(u16 *)(record + 0x3c) == 0) {
            WfcFriendSlot *searchSlot;
            s32 j;
            register s32 codeLength;

            searchSlot = work.slots;
            j = 0;
            codeLength = sizeof(searchSlot->code);
            do {
                if (ByteCompareN((M2C_UNK)(record + 4), (M2C_UNK)(searchSlot->code), codeLength) == 0) {
                    break;
                }
                j++;
                searchSlot++;
            } while (j < 20);

            if (j == 20) {
                register u8 *fallbackName;
                WfcFriendSlot *fallbackSlot;
                fallbackName = data_ov001_0218fb64;
                fallbackSlot = work.slots;
                j = 0;
            codeLength = sizeof(searchSlot->code);
                do {
                    if (ByteCompareN((M2C_UNK)(fallbackSlot->code), (M2C_UNK)fallbackName, codeLength) == 0) {
                        break;
                    }
                    j++;
                    fallbackSlot++;
                } while (j < 20);
                if (j == 20) {
                    return;
                }
            }

            {
                WfcFriendSlot *dest;
                ParsedItems *parsed;
                s32 k;
                s32 parsedCount;
                const u8 *signature;
                dest = &work.slots[j];
                MI_CpuCopy8((void *)(record + 4), (void *)(dest->code), 6);
                MI_CpuCopy8((void *)(record + 0xc), (void *)dest, 0x20);
                dest->unk26 = results->values[i];

                if ((*(u16 *)(record + 0x2c) & 0x10) == 0) {
                    dest->status = 0;
                } else {
                    dest->status = 1;
                    func_02011f2c((M2C_UNK *)&work.parsed, (M2C_UNK *)record);
                    parsedCount = work.parsed.count;
                    k = 0;
                    if (parsedCount <= 0) {
                        goto nextRecord;
                    }
                    parsed = &work.parsed;
                    signature = data_ov001_0218fb60;
                    do {
                        if (parsed->items[k].kind == 0x30) {
                            dest->status = 2;
                            break;
                        }
                        if (parsed->items[k].kind == 0xdd &&
                            parsed->items[k].length >= 4 &&
                            ByteCompareN((M2C_UNK)parsed->items[k].data,
                                          (M2C_UNK)signature, 4) == 0) {
                            dest->status = 2;
                            break;
                        }
                        k++;
                    } while (k < parsedCount);
                }
            }
        }
nextRecord:
        i++;
    } while (i < results->count);
}
#pragma opt_loop_invariants reset
#pragma opt_lifetimes reset
/* Allocate the ov001 save data block, build its CRC16 lookup table and read the
 * four saved slots from the ARM7 save area into it. */
void Ov001_AllocSaveData(void) {
    s32 Ov001_Alloc(s32, M2C_UNK);
    void BuildCrc16Table(u16 *, u32);
    s32 FifoReadSaveSlots(M2C_UNK);
    extern s32 gSaveData;

    gSaveData = Ov001_Alloc(SAVE_DATA_SIZE, 0x20);
    BuildCrc16Table((u16 *)(gSaveData + SAVE_CRC_TABLE), CRC16_POLYNOMIAL);
    FifoReadSaveSlots((M2C_UNK)gSaveData);
}

void Ov001_FreeSaveData(void) {
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern M2C_UNK gSaveData;
    Ov001_FreeAlloc(&gSaveData);
}

s32 GetCurrentMapRecord(void) {
    extern s32 gSaveData;
    return gSaveData + 0x400;
}

void Ov001_SetSaveExtraEmptyA(s8 arg0) {
    extern s32 gSaveData;
    M2C_FIELD((void *)gSaveData, s8 *, 0x4f5) = arg0;
}

void Ov001_SetSaveExtraEmptyB(s8 arg0) {
    extern s32 gSaveData;
    M2C_FIELD((void *)gSaveData, s8 *, 0x4f6) = arg0;
}

/* Store a 32-byte map name in the working save slot and mark the slot unwritten. */
void Ov001_SetSaveMapName(void *name) {
    void MI_CpuCopy8(void *, void *, u32);
    extern s32 gSaveData;

    MI_CpuCopy8(name, (void *)((s8 *)gSaveData + SAVE_MAP_NAME), SAVE_MAP_NAME_SIZE);
    *(u8 *)((s8 *)gSaveData + SAVE_SLOT_STATUS) = 0;
}

/* Store a player name in the working save slot: even-length hex text is decoded
 * two digits per byte, anything else is copied raw; the slot's mode bits record
 * the name-length class and whether the name was stored raw. */
void StorePlayerName(u8 *arg0) {
    void MI_CpuFill8(void *, s32, u32);
    void MI_CpuCopy8(void *, void *, u32);
    s32 StringLengthUpTo(u8 *, s32);
    s32 HexCharValue(u8);
    extern s32 gSaveData;

    register s32 i;
    register s32 length;
    register s32 highNibble;
    register u8 *dest;
    s32 lowNibble;

    MI_CpuFill8((u8 *)gSaveData + SAVE_PLAYER_NAMES, 0, SAVE_NAME_SIZE);
    length = StringLengthUpTo(arg0, SAVE_NAME_TEXT_MAX);

    switch (length) {
        case 0:
        case 10:
        case 0x1a:
        case 0x20: {
            i = 0;
            ((u8 *)gSaveData)[SAVE_NAME_FLAGS] = (u8)(((u8 *)gSaveData)[SAVE_NAME_FLAGS] & ~SAVE_NAME_FLAGS_MASK);
            dest = (u8 *)gSaveData + SAVE_PLAYER_NAMES;
            if (length > 0) {
                do {
                    highNibble = HexCharValue(arg0[i]);
                    lowNibble = HexCharValue(arg0[i + 1]);
                    *dest++ = (u8)((highNibble << 4) + lowNibble);
                    i += 2;
                } while (i < length);
            }
            break;
        }
        default:
            ((u8 *)gSaveData)[SAVE_NAME_FLAGS] = (u8)((((u8 *)gSaveData)[SAVE_NAME_FLAGS] & ~SAVE_NAME_FLAGS_MASK) | SAVE_NAME_RAW);
            MI_CpuCopy8(arg0, (u8 *)gSaveData + SAVE_PLAYER_NAMES, SAVE_NAME_SIZE);
            break;
    }

    switch (length) {
        case 0:
            ((u8 *)gSaveData)[SAVE_NAME_FLAGS] = (u8)(((u8 *)gSaveData)[SAVE_NAME_FLAGS] & ~SAVE_NAME_MODE_MASK);
            break;
        case 5:
        case 10:
            ((u8 *)gSaveData)[SAVE_NAME_FLAGS] = (u8)((((u8 *)gSaveData)[SAVE_NAME_FLAGS] & ~SAVE_NAME_MODE_MASK) | 0x01);
            break;
        case 13:
        case 0x1a:
            ((u8 *)gSaveData)[SAVE_NAME_FLAGS] = (u8)((((u8 *)gSaveData)[SAVE_NAME_FLAGS] & ~SAVE_NAME_MODE_MASK) | 0x02);
            break;
        default:
            ((u8 *)gSaveData)[SAVE_NAME_FLAGS] = (u8)((((u8 *)gSaveData)[SAVE_NAME_FLAGS] & ~SAVE_NAME_MODE_MASK) | 0x03);
            break;
    }
}

void func_ov001_02184660(u8 *arg0) {
    void ParsePlayerCode(u8 *, u8 *);
    extern s32 gSaveData;
    ParsePlayerCode(arg0, (u8 *)gSaveData + 0x4c0);
}

void func_ov001_0218467c(u8 *arg0) {
    void ParsePlayerCode(u8 *, u8 *);
    extern s32 gSaveData;
    ParsePlayerCode(arg0, (u8 *)gSaveData + 0x4f0);
}

void func_ov001_02184698(u8 *arg0) {
    void ParsePlayerCode(u8 *, u8 *);
    extern s32 gSaveData;
    ParsePlayerCode(arg0, (u8 *)gSaveData + 0x4c4);
}

void func_ov001_021846b8(u8 *arg0) {
    void ParsePlayerCode(u8 *, u8 *);
    extern s32 gSaveData;
    ParsePlayerCode(arg0, (u8 *)gSaveData + 0x4c8);
}

void func_ov001_021846d8(u8 *arg0) {
    void ParsePlayerCode(u8 *, u8 *);
    extern s32 gSaveData;
    ParsePlayerCode(arg0, (u8 *)gSaveData + 0x4cc);
}

void func_ov001_021846f8(u8 *arg0) {
    void MI_CpuCopy8(void *, void *, u32);
    extern s32 gSaveData;
    MI_CpuCopy8((void *)((u8 *)gSaveData + 0x440), arg0, 0x20);
}

/* Format the first saved player-code value (SAVE_PLAYER_CODES) as four decimal
 * groups for the UI. */
void Ov001_FormatSavePlayerCode1(s32 output) {
    void func_0200563c(s32, s32, ...);
    extern s32 gSaveData;
    extern char gOv001CodeFormat[];
    u8 *saveData = (u8 *)gSaveData;
    u8 *playerCode = saveData + SAVE_PLAYER_CODES;
    u8 group2 = playerCode[2];
    u8 group3 = playerCode[3];
    func_0200563c(output, (s32)gOv001CodeFormat, saveData[SAVE_PLAYER_CODES], playerCode[1], group2, group3);
}

/* Format the working save copy's 4-byte verification code (SAVE_CODE) as four
 * decimal groups for the UI. */
void Ov001_FormatSaveCode(s32 output) {
    void func_0200563c(s32, s32, ...);
    extern s32 gSaveData;
    extern char gOv001CodeFormat[];
    u8 *saveData = (u8 *)gSaveData;
    u8 group2 = saveData[SAVE_CODE + 2];
    u8 group3 = saveData[SAVE_CODE + 3];
    func_0200563c(output, (s32)gOv001CodeFormat, saveData[SAVE_CODE], saveData[SAVE_CODE + 1], group2, group3);
}

#pragma opt_peephole off
/* Format the second saved player-code value (SAVE_PLAYER_CODES + 4) as four
 * decimal groups for the UI. */
void Ov001_FormatSavePlayerCode2(s32 output) {
    void func_0200563c(s32, s32, ...);
    extern s32 gSaveData;
    extern char gOv001CodeFormat[];
    u8 *saveData = (u8 *)gSaveData;
    u8 *playerCode = saveData + SAVE_PLAYER_CODES + 4;
    u8 group2 = playerCode[2];
    u8 group3 = playerCode[3];
    func_0200563c(output, (s32)gOv001CodeFormat, saveData[SAVE_PLAYER_CODES + 4], playerCode[1], group2, group3);
}
#pragma opt_peephole reset
/* Format the fourth saved player-code value as four decimal groups for the UI. */
void Ov001_FormatSavePlayerCode3(s32 output) {
    void func_0200563c(s32, s32, ...);
    extern s32 gSaveData;
    extern char gOv001CodeFormat[];
    u8 *saveData = (u8 *)gSaveData;
    u8 *playerCode = saveData + SAVE_PLAYER_CODES + 8;
    u8 group2 = playerCode[2];
    u8 group3 = playerCode[3];
    func_0200563c(output, (s32)gOv001CodeFormat, saveData[SAVE_PLAYER_CODES + 8], playerCode[1], group2, group3);
}

#pragma opt_strength_reduction off
/* Format the fourth saved player-code value (SAVE_PLAYER_CODES + 12) as four
 * decimal groups for the UI. */
void Ov001_FormatSavePlayerCode4(s32 output) {
    void func_0200563c(s32, s32, ...);
    extern s32 gSaveData;
    extern char gOv001CodeFormat[];
    u8 *saveData = (u8 *)gSaveData;
    u8 *playerCode = saveData + SAVE_PLAYER_CODES + 12;
    u8 group2 = playerCode[2];
    u8 group3 = playerCode[3];
    func_0200563c(output, (s32)gOv001CodeFormat, saveData[SAVE_PLAYER_CODES + 12], playerCode[1], group2, group3);
}
#pragma opt_strength_reduction reset
u8 Ov001_GetSaveSlotStatus(s32 arg0) {
    extern s32 gSaveData;
    return *((u8 *)((s8 *)gSaveData + (arg0 << 8) + 0xe7));
}

#pragma opt_common_subs off
/* Loads physical save slot `slotIndex` into the working copy: copies the slot
 * image, records which slot it is, marks absent player codes from the zero
 * sentinel, and rebuilds the working code from the slot's set-bit count. */
void LoadSaveSlot(s32 slotIndex) {
    s32 ByteCompareN(M2C_UNK, M2C_UNK, M2C_UNK);
    void BuildSaveCodeWord(u8, M2C_UNK *);
    extern s32 gSaveData;
    extern u8 gEmptyPlayerCode[];
    u32 count;
    u8 *page;
    u8 *dst;
    u8 *src;
    u8 *base;

    count = SAVE_SLOT_IMAGE_SIZE / 2;
    base = (u8 *)gSaveData;
    page = base + (slotIndex << 8);
    src = page;
    dst = base + SAVE_WORK_SLOT;
    do {
        u8 a = src[0];
        u8 b = src[1];
        src += 2;
        count--;
        dst[0] = a;
        dst[1] = b;
        dst += 2;
    } while (count != 0);
    base[SAVE_SLOT_INDEX] = (u8)slotIndex;
    if (ByteCompareN((M2C_UNK)(page + SAVE_SLOT_PLAYER_CODES), (M2C_UNK)gEmptyPlayerCode, 4) != 0) {
        ((u8 *)gSaveData)[SAVE_EXTRA_EMPTY_A] = 0;
    } else {
        ((u8 *)gSaveData)[SAVE_EXTRA_EMPTY_A] = 1;
    }
    if (ByteCompareN((M2C_UNK)(page + SAVE_SLOT_PLAYER_CODES + 8), (M2C_UNK)gEmptyPlayerCode, 4) != 0 ||
        ByteCompareN((M2C_UNK)(page + SAVE_SLOT_PLAYER_CODES + 12), (M2C_UNK)gEmptyPlayerCode, 4) != 0) {
        ((u8 *)gSaveData)[SAVE_EXTRA_EMPTY_B] = 0;
    } else {
        ((u8 *)gSaveData)[SAVE_EXTRA_EMPTY_B] = 1;
    }
    BuildSaveCodeWord(page[SAVE_SLOT_CODE_BITS], (M2C_UNK *)((u8 *)gSaveData + SAVE_CODE));
}
#pragma opt_common_subs reset
