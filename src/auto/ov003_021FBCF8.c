/* 8 functions from 0x021FBCF8 to 0x021FCB70 (ov003), found by ds-decomp. */
#include "common.h"
#include "panel.h"
#include "sound.h"
#include "list_widget.h"
typedef struct PanelFlagByte { unsigned char low:3; unsigned char mode:3; unsigned char pending:1; unsigned char high:1; } PanelFlagByte;
static inline void PanelDispatch(void *p, int slot) { ((void (**)(void *))*(void **)p)[slot](p); }

static inline u8 PanelModeIs(void *p, u32 mode) {
    return ((u32)(M2C_FIELD(p,u8 *,0x3b)<<28)>>28)==mode;
}

static inline s32 PanelCategory(u32 kind) {
    switch(kind) {
    case 28: return 7;
    case 6: return 1;
    case 22: case 23: return 3;
    case 12: return 5;
    case 5: case 7: return 0;
    case 24: return 2;
    case 8: return 6;
    case 14: return 9;
    case 15: return 10;
    case 16: return 11;
    case 17: return 12;
    default: return 4;
    }
}

/* Map-list scroll input: scroll the panel's list widget by `delta` and, when the
 * list's first-visible index actually moves, refresh the map preview and play the
 * scroll sound. */
void Ov003_ScrollMapList(void *panel, s32 delta, s32 force) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK ListWidgetScrollBy(void *, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov003_021f92f4(void *, M2C_UNK);
    s16 oldScroll;
    void *list;

    list = M2C_FIELD(panel, void **, 0x4C);
    oldScroll = (s16) M2C_FIELD(list, s32 *, LIST_WIDGET_SCROLL);
    ListWidgetScrollBy(list, delta, force, 1);
    if (oldScroll == (s16) M2C_FIELD(M2C_FIELD(panel, void **, 0x4C), s32 *, LIST_WIDGET_SCROLL)) {
        return;
    }
    func_ov003_021f92f4(panel, 0);
    PlaySoundEffect(0x10019);
}

void func_ov003_021fbd48(void *arg0, s32 arg1) {
    s32 GetSpriteAnimValue(void *);
    u32 GetMapCategory();
    s32 func_ov003_021f3fe4(s32, M2C_UNK, s16);
    M2C_UNK func_ov003_021f9b30(void *);
    s32 animValue;
    s16 temp_r1_3;
    s16 temp_r2;
    s16 temp_r3;
    s16 var_r5;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r0_7;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 var_r0;
    s16 var_r0_2;
    s32 var_r1;
    s32 var_r1_2;
    s16 var_r1_3;
    s32 var_r2;
    s32 var_r2_2;
    s32 var_r2_3;
    s32 var_r6;
    u32 temp_r0;
    u32 temp_r0_2;
    u8 temp_r4;
    u8 temp_r4_2;
    void *temp_r0_3;
    void *temp_r4_3;

    temp_r4 = (u8) (s16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 *, 0x14);
    temp_r0 = GetMapCategory();
    switch (temp_r0) {                              /* switch 1 */
    case 28:                                        /* switch 1 */
        var_r2 = 7;
        break;
    case 6:                                         /* switch 1 */
        var_r2 = 1;
        break;
    case 22:                                        /* switch 1 */
    case 23:                                        /* switch 1 */
        var_r2 = 3;
        break;
    case 12:                                        /* switch 1 */
        var_r2 = 5;
        break;
    case 5:                                         /* switch 1 */
    case 7:                                         /* switch 1 */
        var_r2 = 0;
        break;
    case 24:                                        /* switch 1 */
        var_r2 = 2;
        break;
    case 8:                                         /* switch 1 */
        var_r2 = 6;
        break;
    case 14:                                        /* switch 1 */
        var_r2 = 9;
        break;
    case 15:                                        /* switch 1 */
        var_r2 = 0xA;
        break;
    case 16:                                        /* switch 1 */
        var_r2 = 0xB;
        break;
    case 17:                                        /* switch 1 */
        var_r2 = 0xC;
        break;
    default: var_r2=4;break;
    }
    M2C_FIELD(((u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4)+((var_r2 * 0xC) + M2C_FIELD(arg0, s32 *, 0x48))), u8 *, 0xA9) = temp_r4;
    temp_r4_2 = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s16 *, 0xC);
    temp_r0_2 = GetMapCategory();
    switch (temp_r0_2) {                            /* switch 2 */
    case 28:                                        /* switch 2 */
        var_r2_2 = 7;
        break;
    case 6:                                         /* switch 2 */
        var_r2_2 = 1;
        break;
    case 22:                                        /* switch 2 */
    case 23:                                        /* switch 2 */
        var_r2_2 = 3;
        break;
    case 12:                                        /* switch 2 */
        var_r2_2 = 5;
        break;
    case 5:                                         /* switch 2 */
    case 7:                                         /* switch 2 */
        var_r2_2 = 0;
        break;
    case 24:                                        /* switch 2 */
        var_r2_2 = 2;
        break;
    case 8:                                         /* switch 2 */
        var_r2_2 = 6;
        break;
    case 14:                                        /* switch 2 */
        var_r2_2 = 9;
        break;
    case 15:                                        /* switch 2 */
        var_r2_2 = 0xA;
        break;
    case 16:                                        /* switch 2 */
        var_r2_2 = 0xB;
        break;
    case 17:                                        /* switch 2 */
        var_r2_2 = 0xC;
        break;
    default: var_r2_2=4;break;
    }
    M2C_FIELD(((u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 4)+((var_r2_2 * 0xC) + M2C_FIELD(arg0, s32 *, 0x48))), u8 *, 0xD) = temp_r4_2;
    temp_r0_3 = M2C_FIELD(arg0, void **, 0x5C);
    M2C_FIELD(temp_r0_3, s32 *, 4) = (s32) (M2C_FIELD(temp_r0_3, s32 *, 4) + arg1);
    if (M2C_FIELD(temp_r0_3, u8 *, 0x14) != 0) {
        var_r1 = M2C_FIELD(temp_r0_3, s32 *, 4);
        if (var_r1 > (s32) M2C_FIELD(temp_r0_3, s32 *, 8)) {
            do {
                var_r1 = M2C_FIELD(temp_r0_3, s32 *, 4) - ((M2C_FIELD(temp_r0_3, s32 *, 8) - M2C_FIELD(temp_r0_3, s32 *, 0xC)) + 1);
                M2C_FIELD(temp_r0_3, s32 *, 4) = var_r1;
            } while (var_r1 > (s32) M2C_FIELD(temp_r0_3, s32 *, 8));
        }
        if (var_r1 < (s32) M2C_FIELD(temp_r0_3, s32 *, 0xC)) {
            do {
                temp_r1 = M2C_FIELD(temp_r0_3, s32 *, 4) + ((M2C_FIELD(temp_r0_3, s32 *, 8) - M2C_FIELD(temp_r0_3, s32 *, 0xC)) + 1);
                M2C_FIELD(temp_r0_3, s32 *, 4) = temp_r1;
            } while (temp_r1 < (s32) M2C_FIELD(temp_r0_3, s32 *, 0xC));
        }
    } else {
        temp_r1_2 = M2C_FIELD(temp_r0_3, s32 *, 4);
        var_r2_3 = M2C_FIELD(temp_r0_3, s32 *, 8);
        if (temp_r1_2 <= var_r2_3) {
            var_r2_3 = M2C_FIELD(temp_r0_3, s32 *, 0xC);
            if (temp_r1_2 >= var_r2_3) {
                var_r2_3 = temp_r1_2;
            }
        }
        M2C_FIELD(temp_r0_3, s32 *, 4) = var_r2_3;
    }
    func_ov003_021f9b30(arg0);
    temp_r4_3 = M2C_FIELD(arg0, void **, 0x60);
    M2C_FIELD(temp_r4_3, s32 *, 0xC) = (s32) (s16) (arg1 + (s16) M2C_FIELD(temp_r4_3, s32 *, 0xC));
    if (M2C_FIELD(temp_r4_3, u8 *, 0x1C) != 0) {
        var_r0 = M2C_FIELD(temp_r4_3, s32 *, 0xC);
        if (var_r0 > (s32) M2C_FIELD(temp_r4_3, s32 *, 0x10)) {
            do {
                var_r0 = M2C_FIELD(temp_r4_3, s32 *, 0xC) - ((M2C_FIELD(temp_r4_3, s32 *, 0x10) - M2C_FIELD(temp_r4_3, s32 *, 0x14)) + 1);
                M2C_FIELD(temp_r4_3, s32 *, 0xC) = var_r0;
            } while (var_r0 > (s32) M2C_FIELD(temp_r4_3, s32 *, 0x10));
        }
        if (var_r0 < (s32) M2C_FIELD(temp_r4_3, s32 *, 0x14)) {
            do {
                temp_r0_4 = M2C_FIELD(temp_r4_3, s32 *, 0xC) + ((M2C_FIELD(temp_r4_3, s32 *, 0x10) - M2C_FIELD(temp_r4_3, s32 *, 0x14)) + 1);
                M2C_FIELD(temp_r4_3, s32 *, 0xC) = temp_r0_4;
            } while (temp_r0_4 < (s32) M2C_FIELD(temp_r4_3, s32 *, 0x14));
        }
    } else {
        var_r1_2 = M2C_FIELD(temp_r4_3, s32 *, 0x10);
        temp_r0_5 = M2C_FIELD(temp_r4_3, s32 *, 0xC);
        if (temp_r0_5 <= var_r1_2) {
            var_r1_2 = M2C_FIELD(temp_r4_3, s32 *, 0x14);
            if (temp_r0_5 >= var_r1_2) {
                var_r1_2 = temp_r0_5;
            }
        }
        M2C_FIELD(temp_r4_3, s32 *, 0xC) = var_r1_2;
    }
    temp_r0_6 = func_ov003_021f3fe4(GetSpriteAnimValue(temp_r4_3 + 0x20), 0, (s16) ((s16)((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * M2C_FIELD(temp_r4_3, s16 *, 4)));
    temp_r2 = M2C_FIELD(temp_r4_3, s16 *, 4);
    temp_r1_3 = (s16) M2C_FIELD(temp_r4_3, s32 *, 0xC) * temp_r2;
    if (temp_r0_6 <= (s32) temp_r1_3) {
        var_r0_2 = (temp_r1_3 - temp_r0_6);
        var_r1_3 = (temp_r0_6 + ((s16) ((s16) (s16)((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * temp_r2) - temp_r1_3));
    } else {
        var_r0_2 = (((s16) ((s16) (s16)((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * temp_r2) - temp_r0_6) + temp_r1_3);
        var_r1_3 = (temp_r0_6 - temp_r1_3);
    }
    var_r6=0;
    if(var_r0_2>var_r1_3)var_r6=1;
    animValue=GetSpriteAnimValue(temp_r4_3+0x20);
    temp_r3 = M2C_FIELD(temp_r4_3, s16 *, 4);
    var_r5 = (s16) M2C_FIELD(temp_r4_3, s32 *, 0xC) * temp_r3;
    temp_r0_7 = func_ov003_021f3fe4(animValue, 0, (s16) ((s16)((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * temp_r3));
    if ((s8)var_r6 == 0) {
        if (temp_r0_7 > (s32) var_r5) {
            var_r5 += (s16) ((s16)((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * M2C_FIELD(temp_r4_3, s16 *, 4));
        }
    } else if (temp_r0_7 < (s32) var_r5) {
        var_r5 -= (s16) ((s16)((s16) M2C_FIELD(temp_r4_3, s32 *, 0x10) + 1) * M2C_FIELD(temp_r4_3, s16 *, 4));
    }
    temp_r1_3=M2C_FIELD(temp_r4_3,s16 *,0x2C);
    M2C_FIELD(temp_r4_3, s16 *, 0x2E) = (s16) temp_r0_7;
    M2C_FIELD(temp_r4_3, s16 *, 0x30) = var_r5;
    M2C_FIELD(temp_r4_3, s16 *, 0x2C) = temp_r1_3;
    M2C_FIELD(temp_r4_3, u16 *, 0x22) = (u16) M2C_FIELD(temp_r4_3, u16 *, 0x24);
    PlaySoundEffect(0x10020);
}
#pragma opt_strength_reduction off
void func_ov003_021fc26c(void *arg0) {
 s32 CountMapPicks(void *,void *);
 void SetMenuPanelState(void *,u32);
 M2C_UNK PlaySoundEffect(s32);
 u32 GetMapCategory(void);
 M2C_UNK func_ov003_021f92f4(void *,s32);
 void Ov003_SetMapConfirmEnabled(void);
 void func_020d8ccc(u16);
 void EnableMapConfirm(void);
 void func_ov003_021f2848(void *);
 s32 func_ov003_021f4038(void);
 void *GetMapRecord(u16);
 void MapSettings_Apply(void *);
 void func_ov003_021fc820(void *);
 void Ov003_CloseMapPanel(void *);
 u8 value;
 s32 category;
 u16 selected;
 void *sprite;
 s32 index;
 s32 row;
 if(PanelModeIs(arg0,4)) {
  if(!CountMapPicks((u8 *)M2C_FIELD(arg0,void **,0x44)+4,(u8 *)M2C_FIELD(arg0,void **,0x44)+8) &&
     !CountMapPicks((u8 *)M2C_FIELD(arg0,void **,0x44)+4,(u8 *)M2C_FIELD(arg0,void **,0x44)+0x12)) {
   PlaySoundEffect(0x1001d);
   SetMenuPanelState(arg0,6);
   return;
  }
 }
 value=(u8)(s16)M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s32 *,0x14);
 switch(GetMapCategory()) {
 case 28: category=7;break;
 case 6: category=1;break;
 case 22:case 23:category=3;break;
 case 12:category=5;break;
 case 5:case 7:category=0;break;
 case 24:category=2;break;
 case 8:category=6;break;
 case 14:category=9;break;
 case 15:category=10;break;
 case 16:category=11;break;
 case 17:category=12;break;
 default:category=4;break;
}
 category=(s32)M2C_FIELD(arg0,void **,0x48)+category*12;
 M2C_FIELD(category+(u8)M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),s32 *,4),u8 *,0xa9)=value;
 value=(u8)M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s16 *,0xc);
 switch(GetMapCategory()) {
 case 28: category=7;break;
 case 6: category=1;break;
 case 22:case 23:category=3;break;
 case 12:category=5;break;
 case 5:case 7:category=0;break;
 case 24:category=2;break;
 case 8:category=6;break;
 case 14:category=9;break;
 case 15:category=10;break;
 case 16:category=11;break;
 case 17:category=12;break;
 default:category=4;break;
}
 category=(s32)M2C_FIELD(arg0,void **,0x48)+category*12;
 M2C_FIELD(category+(u8)M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),s32 *,4),u8 *,0xd)=value;
 value=(u8)M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),s32 *,4);
 switch(GetMapCategory()) {
 case 28: category=7;break;
 case 6: category=1;break;
 case 22:case 23:category=3;break;
 case 12:category=5;break;
 case 5:case 7:category=0;break;
 case 24:category=2;break;
 case 8:category=6;break;
 case 14:category=9;break;
 case 15:category=10;break;
 case 16:category=11;break;
 case 17:category=12;break;
 default:category=4;break;
}
 M2C_FIELD(M2C_FIELD(arg0,void **,0x48),u8 *,category)=value;
 func_ov003_021f92f4(arg0,1);
 if(PanelModeIs(arg0,0)||PanelModeIs(arg0,2)||PanelModeIs(arg0,3)||PanelModeIs(arg0,4)||PanelModeIs(arg0,6)||PanelModeIs(arg0,7)||PanelModeIs(arg0,8)) {
  index=(s16)M2C_FIELD(M2C_FIELD(arg0,void **,0x4c),s32 *,0x14);
  row=M2C_FIELD(M2C_FIELD(arg0,void **,0x5c),s32 *,4);
  row=(u32)M2C_FIELD(arg0,void **,0x44)+((u8)row<<9);
  selected=M2C_FIELD(row+(u16)index*2,u16 *,0x2e);
 } else selected=M2C_FIELD(arg0,u16 *,0x3c);
 sprite=M2C_FIELD(M2C_FIELD(arg0,void **,0x68),void **,0);
 if(M2C_FIELD(sprite,s8 *,0x5a)>=0) {
  M2C_FIELD(sprite,u32 *,0x40)=(M2C_FIELD(sprite,u32 *,0x40)&~0x03fc0000)|((u32)(u16)(((u32)(M2C_FIELD(sprite,u8 *,0x59)<<28)>>28)+1)<<24>>6);
  M2C_FIELD(sprite,s8 *,0x5a)=12;
 }
 Ov003_SetMapConfirmEnabled();
 Ov003_CloseMapPanel(arg0);
 func_020d8ccc(selected);
 EnableMapConfirm();
 if(PanelModeIs(arg0,4)||PanelModeIs(arg0,2)) PlaySoundEffect(0x1000e);
 else PlaySoundEffect(0x1000d);
 if(PanelModeIs(arg0,4)) func_ov003_021f2848((u8 *)M2C_FIELD(arg0,void **,0x44)+4);
 else if(func_ov003_021f4038()) func_ov003_021fc820(arg0);
 if(PanelModeIs(arg0,0) && selected>=0xe1 && selected<0x1a9) {
  if((u32)(M2C_FIELD(GetMapRecord(selected),u32 *,0x38)<<31)>>31)
   MapSettings_Apply((u8 *)GetMapRecord(selected)+0x30);
 }
}
#pragma opt_strength_reduction reset
void func_ov003_021fc820(void *arg0) {
    s32 Link_ReceivePacket(s32 *, M2C_UNK);
    M2C_UNK Link_SendPacket(s32 *, M2C_UNK);
    M2C_UNK Link_FlushSend();
    s32 buffer[9];

    if (Link_ReceivePacket(buffer, 0x24) == 0) {
        return;
    }
    buffer[0] = 1;
    Link_SendPacket(buffer, 0x24);
    Link_FlushSend();
}

/* Back action of the ov003 map-select panel: flash the back button, hide the
 * panel and return to the scene, play the cancel sound unless this is a link
 * map screen (modes 6-8, or mode 4 in an online session) with an active link,
 * then clear the map-confirm flag. */
void Ov003_LeaveMapPanel(void *panelObj) {
    void Ov003_SetMapConfirmDisabled(void);
    void Ov003_CloseMapPanel(void *);
    s32 GetActiveOverlay(void);
    s32 IsLinkSessionActive(void);
    M2C_UNK PlaySoundEffect(s32);
    void DisableMapConfirm(void);

    Panel *panel;
    PanelSprite *backButton;
    s8 timer;
    u8 step;
    u32 mode;
    s32 linkBack;

    panel = panelObj;
    backButton = panel->buttons[3];
    timer = backButton->timer;
    if (timer >= 0) {
        step = backButton->colorStep;
        backButton->color = (backButton->color & ~0x03FC0000) | ((u32) ((u16) (((u32) (step << 0x1C) >> 0x1C) + 1) << 0x18) >> 6);
        backButton->timer = 0xC;
    }
    Ov003_SetMapConfirmDisabled();
    Ov003_CloseMapPanel(panel);

    mode = (u32) (panel->modeBits << 0x1C) >> 0x1C;
    if (((mode == 6 ? 1 : 0) & 0xff) ||
        ((mode == 7 ? 1 : 0) & 0xff) ||
        ((mode == 8 ? 1 : 0) & 0xff)) {
        linkBack = 1;
    } else {
        if (((mode == 4 ? 1 : 0) & 0xff) && GetActiveOverlay() == 2) {
            linkBack = 1;
        } else {
            linkBack = 0;
        }
    }
    if (linkBack == 0 || IsLinkSessionActive() == 0) {
        PlaySoundEffect(SOUND_MENU_CANCEL);
    }
    DisableMapConfirm();
}

void Ov003_CloseMapPanel(void *arg0) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK Hide3DSprite(s32);
    M2C_UNK SetOv003SceneState(M2C_UNK);
    Hide3DSprite(*M2C_FIELD(arg0, s32 **, 0x6C));
    SetOv003SceneState(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    Sprite_ResumeAnimation(arg0);
}

#pragma scheduling off
void SetMenuPanelState(void *panel, u32 state) {
void *CreateTextLayer(void *);
void RenderTextLayerMessage(void *, s32, s32, u32);
u8 byte;
u32 stateByte;
u32 stateBits;
u32 merged;
u32 flags;
void *textLayer;
byte = M2C_FIELD(panel, u8 *, 0x3E);
stateByte = (u8)state;
stateBits = stateByte << 0x1D;
M2C_FIELD(panel, u8 *, 0x3E) = byte | 0x40u;
merged = M2C_FIELD(panel, u8 *, 0x3E);
flags = merged & ~0x38u;
M2C_FIELD(panel, u8 *, 0x3E) = (u8)(flags | (stateBits >> 0x1Au));
switch (state) {
case 3:
    textLayer = CreateTextLayer(panel);
    RenderTextLayerMessage(textLayer, 3, 0xDC00, 0x4200001D);
    M2C_FIELD(textLayer, s32 *, 0x58) = M2C_FIELD(textLayer, s32 *, 0x58) | 0x400;
    return;
case 4:
    textLayer = CreateTextLayer(panel);
    RenderTextLayerMessage(textLayer, 2, 0xDC00, 0x4700001E);
    M2C_FIELD(textLayer, s32 *, 0x58) = M2C_FIELD(textLayer, s32 *, 0x58) | 0x400;
    return;
case 5:
    textLayer = CreateTextLayer(panel);
    RenderTextLayerMessage(textLayer, 2, 0xDC00, 0x47000020);
    M2C_FIELD(textLayer, s32 *, 0x58) = M2C_FIELD(textLayer, s32 *, 0x58) | 0x400;
    return;
case 6:
    textLayer = CreateTextLayer(panel);
    RenderTextLayerMessage(textLayer, 2, 0xDC00, 0x47000021);
    M2C_FIELD(textLayer, s32 *, 0x58) = M2C_FIELD(textLayer, s32 *, 0x58) | 0x400;
    return;
default:
    return;
}
}
void func_ov003_021fca84(void *arg0) {
 s32 IsMapConfirmEnabled(); M2C_UNK Clear3DSpriteLayer(M2C_UNK); M2C_UNK MI_CpuFill8(s32,M2C_UNK,M2C_UNK); M2C_UNK func_020c8e40(); extern void *gCur3DSpriteEngine;
 PanelFlagByte *flags=(PanelFlagByte *)((u8 *)arg0+0x3e);
 if(!flags->pending)return;
 flags->pending=0;
 switch(flags->mode) {
 case 0: if(!IsMapConfirmEnabled())return; Clear3DSpriteLayer(0); M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1; MI_CpuFill8(M2C_FIELD(arg0,s32 *,0x44)+0x186c,0,13); func_020c8e40(); func_ov003_021f92f4(arg0,0); return;
 case 1: case 2: if(!IsMapConfirmEnabled())return; { register void *self = arg0; ((void (**)(void *))*(void **)self)[7](self); }; return;
 case 3: if(!IsMapConfirmEnabled())return; { register void *self = arg0; ((void (**)(void *))*(void **)self)[8](self); }; return;
 case 4: case 5: case 6: default: return;
 }
}
#pragma opt_instruction_scheduling reset
