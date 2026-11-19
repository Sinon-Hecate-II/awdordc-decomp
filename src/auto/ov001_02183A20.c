/* 37 functions from 0x02183A20 to 0x02184960 (ov001), found by ds-decomp. */
#include "common.h"
#include "wfc.h"

#pragma optimization_level 2
void func_ov001_02183a20(void) {
    s32 Ov001_HitScrollbarPart(void);
    void func_ov001_02183cec(s8);
    s32 func_ov001_02183e0c(void);
    void func_ov001_02183d18(void);
    void Ov001_UpdateScrollbarDrag(void);
    void Ov001_PlaySound(s32);
    void func_ov001_02185048(s32);
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
                case 0:
                    break;
                case 1: {
                    if ((u8)M2C_FIELD(gOv001Scrollbar, u8 *, 0x1b) == 0) {
                        return;
                    }
                    Ov001_PlaySound(0x16);
                    func_ov001_02185048(0);
                    M2C_FIELD(gOv001Scrollbar, u8 *, 0x1d) = 1;
                    Ov001_ReadTouchPoint((M2C_UNK *)((u8 *)gOv001Scrollbar + 0x14));
                    M2C_FIELD(gOv001Scrollbar, u8 *, 0x18) = M2C_FIELD(gOv001Scrollbar, u8 *, 0x1a);
                    M2C_FIELD(gOv001Scrollbar, u8 *, 0x1c) = 1;
                    return;
                }
                case 2:
                    func_ov001_02183cec(2);
                    return;
                case 3:
                    func_ov001_02183cec(3);
                    return;
                case 4:
                    func_ov001_02183d18();
                    return;
                default:
                    return;
            }
            return;
        }
        case 1:
            Ov001_UpdateScrollbarDrag();
            return;
        case 2: {
            r = ((s32 (*)(s32))func_ov001_02183e0c)(2);
            if (r != 2) {
                M2C_FIELD(gOv001Scrollbar, u8 *, 0x1d) = 5;
                M2C_FIELD(gOv001Scrollbar, u8 *, 0x1c) = 0;
                return;
            }
            r = Ov001_HitScrollbarPart();
            if (r != 2) {
                return;
            }
            func_ov001_02183cec(2);
            return;
        }
        case 3: {
            r = ((s32 (*)(s32))func_ov001_02183e0c)(3);
            if (r != 3) {
                M2C_FIELD(gOv001Scrollbar, u8 *, 0x1d) = 7;
                M2C_FIELD(gOv001Scrollbar, u8 *, 0x1c) = 0;
                return;
            }
            r = Ov001_HitScrollbarPart();
            if (r != 3) {
                return;
            }
            func_ov001_02183cec(3);
            return;
        }
        default:
            return;
    }
}
#pragma optimization_level 4
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

void Ov001_PlayScrollDragSound(s32 arg0) {
    s32 HardwareDivide(s32, s32);
    void func_ov001_02185048(M2C_UNK);
    void func_ov001_02185068(s32, s32);
    extern void *gOv001Scrollbar;
    s32 field;
    s32 r4;
    s32 r1;

    field = M2C_FIELD(gOv001Scrollbar, u8 *, 0x1A);
    r4 = field - arg0;
    if (r4 < 0) {
        r4 = -r4;
    }
    func_ov001_02185048(r4 < 2 ? 0 : (r4 >= 6 ? 0x7F : HardwareDivide(0x7F, 6 - r4)));
    r1 = r4 < 2 ? -256 : (r4 >= 6 ? 0x100 : HardwareDivide(0x200, 6 - r4) - 0x100);
    func_ov001_02185068(0xFFFF, r1);
}

void func_ov001_02183cec(s8 arg0) {
    extern void *gOv001Scrollbar;
    s8 var_r1;

    M2C_FIELD(gOv001Scrollbar, s8 *, 0x1C) = arg0;
    if (arg0 == 2) {
        var_r1 = 4;
    } else {
        var_r1 = 6;
    }
    M2C_FIELD(gOv001Scrollbar, s8 *, 0x1D) = var_r1;
}

#pragma peephole off
void func_ov001_02183d18(void) {
void Ov001_ReadTouchPoint(M2C_UNK *);
void Ov001_SetScrollbarHandlePos(s32);
extern void *gOv001Scrollbar;
extern u8 gOv001ScrollbarHandleLengths[];
M2C_UNK sp0;
u32 arrval;
u16 field12,sp_half;
s32 v; u8 field19; s32 lim;
Ov001_ReadTouchPoint(&sp0);
arrval=gOv001ScrollbarHandleLengths[M2C_FIELD(gOv001Scrollbar,u8 *,0x1b)];
field12=M2C_FIELD(gOv001Scrollbar,u16 *,0x12);
sp_half=M2C_FIELD(&sp0,u16 *,2);
v=(s32)sp_half-(s32)field12;
v-=(s32)(arrval>>1);
if(v<0) v=0;
else {
field19=M2C_FIELD(gOv001Scrollbar,u8 *,0x19);
lim=(s32)field19-(s32)arrval;
if(v>=lim) v=lim;
}
Ov001_SetScrollbarHandlePos(v);
M2C_FIELD(gOv001Scrollbar,u8 *,0x1d)=3;
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

s32 func_ov001_02183e0c(void) {
    void Ov001_GetScrollbarPartRect(s32, M2C_UNK *);
    s32 TouchRectReleased(M2C_UNK *);
    s32 sp0[2];
    s32 var_r5;

    var_r5 = 2;
loop_1:
    Ov001_GetScrollbarPartRect(var_r5, sp0);
    if (TouchRectReleased(sp0) != 0) {
        return var_r5;
    }
    var_r5 += 1;
    if (var_r5 <= 3) {
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

void Ov001_SetScrollbarHandlePos(s32 arg0) {
    s32 Ov001_MoveSpriteLayout(M2C_UNK, s32, u16, s32);
    extern void *gOv001Scrollbar;
    u16 f10;
    u16 f12;
    void *nested;
    void *base;

    base = gOv001Scrollbar;
    f12 = M2C_FIELD(base, u16 *, 0x12);
    f10 = M2C_FIELD(base, u16 *, 0x10);
    nested = M2C_FIELD(base, void **, 0x0);
    Ov001_MoveSpriteLayout(nested, -1, f10, arg0 + (s32)f12);
    M2C_FIELD(gOv001Scrollbar, s8 *, 0x1A) = (s8)arg0;
}

void func_ov001_02183f6c(void) {
    s32 Ov001_Alloc(s32, M2C_UNK);
    extern s32 gWfcFriendRoster;
    if (gWfcFriendRoster != 0) {
        return;
    }
    gWfcFriendRoster = Ov001_Alloc(0x1E60, 0x20);
}

#pragma opt_common_subs off
#pragma pool_constants off
void func_ov001_02183fa0(void) {
 u16 WFC_GetPlayerMask(void); M2C_UNK Ov001_FreeAlloc(M2C_UNK *); extern M2C_UNK gWfcFriendRoster; extern s32 gSaveData;
 if(*(volatile M2C_UNK *)&gWfcFriendRoster==0)return;
 while(WFC_GetPlayerMask()!=0x8000){}
 Ov001_FreeAlloc(&gSaveData-1);
}
#pragma pool_constants reset
#pragma opt_common_subs reset
/* Opens the friend roster: clears its slots, opens the WFC channel that fetches
 * the roster, waits for the reply, then builds the request packet from its
 * defaults and the local console id and sends it.  Returns 0 when the channel
 * or the request cannot be started. */
s32 Ov001_OpenFriendRoster(void) {
    s32 FillU16(s32, void *, s32);
    s32 func_02012218(void *, void (*)(void), s32);
    s32 func_02011af8(void *);
    u16 GetConsoleLocalId(void);
    s32 Ov001_SendFriendRosterRequest(void);
    void Ov001_HandleFriendRosterReply();
    extern s32 gWfcFriendRoster;
    extern u32 gFriendRosterRequestDefaults[];
    u8 *base;

    FillU16(0, (u8 *)gWfcFriendRoster + WFC_FRIEND_SLOTS, WFC_FRIEND_SLOTS_SIZE);
    if (func_02012218((void *)gWfcFriendRoster, Ov001_HandleFriendRosterReply, 3) != WFC_CMD_OK)
        return 0;
    do {
        func_02011af8((u8 *)gWfcFriendRoster + WFC_FRIEND_REPLY);
        base = (u8 *)gWfcFriendRoster;
    } while (*(u16 *)(base + WFC_FRIEND_REPLY) != WFC_REPLY_DONE);
    *(WfcFriendRosterRequest *)(base + WFC_FRIEND_REQUEST) = *(const WfcFriendRosterRequest *)gFriendRosterRequestDefaults;
    *(u8 **)(base + WFC_FRIEND_REQUEST) = base + 0xf00;
    *(u16 *)((u8 *)(*(s32 *)&gWfcFriendRoster) + WFC_FRIEND_REQUEST + 8) = GetConsoleLocalId();
    return Ov001_SendFriendRosterRequest() ? 1 : 0;
}

s32 Ov001_SendFriendRosterRequest(void) {
    s32 WFC_SendRequestPacket(void (*)(void), void *);
    void Ov001_HandleFriendRosterReply();
    extern s32 gWfcFriendRoster;
    void *base = (void *)gWfcFriendRoster;
    if (WFC_SendRequestPacket(Ov001_HandleFriendRosterReply, (s8 *)base + 0x1648) == 2) {
        return 1;
    }
    return 0;
}

/* End the friend-roster link: mark the roster as closing, read its reply block
 * (and, while the request is still in flight, queue the cancel and wait for the
 * reply to arrive), then end the WFC link. */
s32 Ov001_CloseFriendRoster(void) {
    s32 func_02011af8(void *);
    s32 func_02012274(void (*)(void));
    s32 WFC_EndLink(void (*)(void));
    void Ov001_HandleFriendRosterReply();
    extern s32 gWfcFriendRoster;

    *(u8 *)((s8 *)gWfcFriendRoster + WFC_FRIEND_CLOSING) = 1;
    func_02011af8((void *)((s8 *)gWfcFriendRoster + WFC_FRIEND_REPLY));
    if (*(u16 *)((s8 *)gWfcFriendRoster + WFC_FRIEND_REPLY) != WFC_REPLY_DONE) {
        if (func_02012274(Ov001_HandleFriendRosterReply) != WFC_CMD_OK) {
            return 0;
        }
        do {
            func_02011af8((void *)((s8 *)gWfcFriendRoster + WFC_FRIEND_REPLY));
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
    u8 *p;
    s32 count;
    s32 i;

    p = (u8 *)gWfcFriendRoster + 0x1300;
    *arg0 = p;
    count = 0;
    for (i = 0; i < 20; i++) {
        if (ByteCompareN((M2C_UNK)(p + 0x20), (M2C_UNK)data_ov001_0218fb64, 6) != 0) {
            count = count + 1;
        }
        p = p + 0x2a;
    }
    return count;
}

void Ov001_HandleFriendRosterReply(u16 *p) {
    s32 Ov001_SendFriendRosterRequest(void);
    void func_ov001_02184230(u16 *);
    void SystemHalt(u16 *);
    extern s32 gWfcFriendRoster;
    u8 *q;

    if (p[1]) {
        return;
    }
    q = (u8 *)gWfcFriendRoster + 0x1000;
    if (q[0xe5c] == 0 && p[0] == 0x26) {
        switch (p[4]) {
            case 5:
                func_ov001_02184230(p);
                Ov001_SendFriendRosterRequest();
                break;
            case 4:
                Ov001_SendFriendRosterRequest();
                break;
            default:
                SystemHalt(p);
                break;
        }
    }
}

#pragma scheduling off
void func_ov001_02184230(u16 *arg0) {
    void DC_InvalidateRange(void *, s32);
    void MI_CpuCopy8(void *, void *, u32);
    s32 ByteCompareN(M2C_UNK, M2C_UNK, s32);
    void func_02011f2c(M2C_UNK *, M2C_UNK *);
    extern s32 gWfcFriendRoster;
    extern u8 data_ov001_0218fb64[];
    extern u8 data_ov001_0218fb60[];

    typedef struct { u8 kind; u8 length; u8 pad[2]; void *data; } ParsedItem;
    typedef struct { u8 count; u8 pad[3]; ParsedItem items[16]; } ParsedItems;
    typedef struct { u8 *slots; ParsedItems parsed; } Work;

    s32 i;
    register u8 *record;
    Work work;

    work.slots = (u8 *)gWfcFriendRoster + 0x1300;
    DC_InvalidateRange((u8 *)gWfcFriendRoster + 0xf00, 0x400);

    i = 0;
    if ((s32)*(u16 *)((u8 *)arg0 + 0xe) <= 0) {
        return;
    }
    do {
        record = *(u8 **)((u8 *)arg0 + 0x10 + i * 4);
        if (record[0xc] != 0 && *(u16 *)(record + 0x3c) == 0) {
            register s32 j;
            register u8 *searchSlot;

            searchSlot = work.slots;
            j = 0;
            do {
                if (ByteCompareN((M2C_UNK)(record + 4), (M2C_UNK)(searchSlot + 0x20), 6) == 0) {
                    break;
                }
                j++;
                searchSlot += 0x2a;
            } while (j < 20);

            if (j == 20) {
                register u8 *fallbackName;
                register u8 *fallbackSlot;
                fallbackName = data_ov001_0218fb64;
                fallbackSlot = work.slots;
                j = 0;
                do {
                    if (ByteCompareN((M2C_UNK)(fallbackSlot + 0x20), (M2C_UNK)fallbackName, 6) == 0) {
                        break;
                    }
                    j++;
                    fallbackSlot += 0x2a;
                } while (j < 20);
                if (j == 20) {
                    return;
                }
            }

            {
                register u8 *dest;
                s32 parsedCount;
                s32 k;
                dest = work.slots + j * 0x2a;
                MI_CpuCopy8((void *)(record + 4), (void *)(dest + 0x20), 6);
                MI_CpuCopy8((void *)(record + 0xc), (void *)dest, 0x20);
                *(u16 *)(dest + 0x26) = *(u16 *)((u8 *)arg0 + 0x50 + i * 2);

                if ((*(u16 *)(record + 0x2c) & 0x10) == 0) {
                    dest[0x28] = 0;
                } else {
                    dest[0x28] = 1;
                    func_02011f2c((M2C_UNK *)&work.parsed, (M2C_UNK *)record);
                    parsedCount = work.parsed.count;
                    k = 0;
                    if (parsedCount <= 0) {
                        continue;
                    }
                    do {
                        if (work.parsed.items[k].kind == 0x30) {
                            dest[0x28] = 2;
                            break;
                        }
                        if (work.parsed.items[k].kind == 0xdd &&
                            work.parsed.items[k].length >= 4 &&
                            ByteCompareN((M2C_UNK)work.parsed.items[k].data,
                                          (M2C_UNK)data_ov001_0218fb60, 4) == 0) {
                            dest[0x28] = 2;
                            break;
                        }
                        k++;
                    } while (k < parsedCount);
                }
            }
        }
        i++;
    } while (i < *(u16 *)((u8 *)arg0 + 0xe));
}
#pragma scheduling reset
void func_ov001_02184404(void) {
    s32 Ov001_Alloc(s32, M2C_UNK);
    void func_02076710(u16 *, u32);
    s32 func_02045eb4(M2C_UNK);
    extern s32 gSaveData;

    gSaveData = Ov001_Alloc(0x6f8, 0x20);
    func_02076710((u16 *)(gSaveData + 0x4f8), 0xa001);
    func_02045eb4((M2C_UNK)gSaveData);
}

void func_ov001_02184448(void) {
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern M2C_UNK gSaveData;
    Ov001_FreeAlloc(&gSaveData);
}

s32 GetCurrentMapRecord(void) {
    extern s32 gSaveData;
    return gSaveData + 0x400;
}

void func_ov001_02184470(s8 arg0) {
    extern s32 gSaveData;
    M2C_FIELD((void *)gSaveData, s8 *, 0x4f5) = arg0;
}

void func_ov001_02184484(s8 arg0) {
    extern s32 gSaveData;
    M2C_FIELD((void *)gSaveData, s8 *, 0x4f6) = arg0;
}

void func_ov001_02184498(void *arg0) {
    void MI_CpuCopy8(void *, void *, u32);
    extern s32 gSaveData;
    MI_CpuCopy8(arg0, (void *)((s8 *)gSaveData + 0x440), 0x20);
    *(u8 *)((s8 *)gSaveData + 0x4e7) = 0;
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
    void func_ov001_02184ec4(u8 *, u8 *);
    extern s32 gSaveData;
    func_ov001_02184ec4(arg0, (u8 *)gSaveData + 0x4c0);
}

void func_ov001_0218467c(u8 *arg0) {
    void func_ov001_02184ec4(u8 *, u8 *);
    extern s32 gSaveData;
    func_ov001_02184ec4(arg0, (u8 *)gSaveData + 0x4f0);
}

void func_ov001_02184698(u8 *arg0) {
    void func_ov001_02184ec4(u8 *, u8 *);
    extern s32 gSaveData;
    func_ov001_02184ec4(arg0, (u8 *)gSaveData + 0x4c4);
}

void func_ov001_021846b8(u8 *arg0) {
    void func_ov001_02184ec4(u8 *, u8 *);
    extern s32 gSaveData;
    func_ov001_02184ec4(arg0, (u8 *)gSaveData + 0x4c8);
}

void func_ov001_021846d8(u8 *arg0) {
    void func_ov001_02184ec4(u8 *, u8 *);
    extern s32 gSaveData;
    func_ov001_02184ec4(arg0, (u8 *)gSaveData + 0x4cc);
}

void func_ov001_021846f8(u8 *arg0) {
    void MI_CpuCopy8(void *, void *, u32);
    extern s32 gSaveData;
    MI_CpuCopy8((void *)((u8 *)gSaveData + 0x440), arg0, 0x20);
}

void func_ov001_0218471c(s32 arg0) {
    void func_0200563c(s32, s32, ...);
    extern s32 gSaveData;
    extern char data_ov001_02190b58[];
    u8 *p = (u8 *)gSaveData;
    u8 t0 = p[0x4c2];
    u8 t1 = p[0x4c3];
    func_0200563c(arg0, (s32)data_ov001_02190b58, p[0x4c0], p[0x4c1], t0, t1);
}

void func_ov001_0218475c(s32 arg0) {
    void func_0200563c(s32, s32, ...);
    extern s32 gSaveData;
    extern char data_ov001_02190b58[];
    u8 *p = (u8 *)gSaveData;
    u8 t0 = p[0x4f2];
    u8 t1 = p[0x4f3];
    func_0200563c(arg0, (s32)data_ov001_02190b58, p[0x4f0], p[0x4f1], t0, t1);
}

#pragma opt_peephole off
void func_ov001_0218479c(s32 arg0) {
    void func_0200563c(s32, s32, ...);
    extern s32 gSaveData;
    extern char data_ov001_02190b58[];
    u8 *p = (u8 *)gSaveData;
    u8 *q = p + 0x4c4;
    u8 t0 = q[2];
    u8 t1 = q[3];
    func_0200563c(arg0, (s32)data_ov001_02190b58, p[0x4c4], q[1], t0, t1);
}
#pragma opt_peephole reset
void func_ov001_021847e0(s32 arg0) {
    void func_0200563c(s32, s32, ...);
    extern s32 gSaveData;
    extern char data_ov001_02190b58[];
    u8 *p = (u8 *)gSaveData;
    u8 *q = p + 0x4c8;
    u8 t0 = q[2];
    u8 t1 = q[3];
    func_0200563c(arg0, (s32)data_ov001_02190b58, p[0x4c8], q[1], t0, t1);
}

#pragma opt_strength_reduction off
void func_ov001_02184824(s32 arg0) {
    void func_0200563c(s32, s32, ...);
    extern s32 gSaveData;
    extern char data_ov001_02190b58[];
    u8 *p = (u8 *)gSaveData;
    u8 *q = p + 0x4cc;
    u8 t0 = q[2];
    u8 t1 = q[3];
    func_0200563c(arg0, (s32)data_ov001_02190b58, p[0x4cc], q[1], t0, t1);
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
    void func_02046058(u8, M2C_UNK *);
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
    func_02046058(page[SAVE_SLOT_CODE_BITS], (M2C_UNK *)((u8 *)gSaveData + SAVE_CODE));
}
#pragma opt_common_subs reset
