/* 10 functions from 0x02202DC8 to 0x02203710 (ov003), found by ds-decomp. */
#include "common.h"
static inline void SetVisible3368(u8 flag,void *p) { M2C_FIELD(p,u8 *,0x59)=flag?0:1; }
typedef struct { u8 pad[0x34]; s16 x,y; u8 pad38[8]; u32 width:9; u32 height:9; u32 flags:14; } SpriteFields3368;

/* One row of the setup menu's value table: the table starts 12 bytes into the
   menu context, each row is 0x18 bytes, and a D-pad press adds the row's step. */
typedef struct {
    s32 value;   /* current value */
    s32 maximum; /* clamp/wrap upper bound */
    s32 minimum; /* clamp/wrap lower bound */
    s32 step;    /* amount one press adds */
    u8  wrap;    /* wrap around at the ends instead of clamping */
    u8  pad[7];
} Ov003MenuEntry; /* size 0x18 */

/* The same row seen from the menu context: the value table starts 12 bytes in,
   so value/maximum/minimum/step/wrap sit at +0x0C/+0x10/+0x14/+0x18/+0x1C. */
typedef struct {
    s32 pad[3];
    s32 value;
    s32 maximum;
    s32 minimum;
    s32 step;
    u8  wrap;
} Ov003MenuRow;

/* One D-pad press on the selected setup-menu row: add the row's step to its
   value, then wrap between min/max if the row wraps, else clamp. */
void Ov003_IncreaseSelectedEntry(void *arg0, s32 arg1) {
 s32 value,limit;
#define F(o,t) (*(t *)((char *)arg0+(o)+arg1*24))  /* field at byte offset o of the row */
 ((Ov003MenuEntry *)((char *)arg0+12))[arg1].value+=M2C_FIELD((unsigned)arg0+arg1*24,s32 *,24);
 if(F(28,u8)){                                    /* row->wrap */
 if(F(12,s32)>F(16,s32)) { Ov003MenuRow *p=(Ov003MenuRow *)((char *)arg0+arg1*24); do { p->value-=p->maximum-p->minimum+1; } while(p->value>p->maximum); }
 if(F(12,s32)<F(20,s32)) { Ov003MenuRow *q=(Ov003MenuRow *)((char *)arg0+arg1*24); do { q->value+=q->maximum-q->minimum+1; } while(q->value<q->minimum); }
 }else{limit=F(16,s32);value=F(12,s32);if(value<=limit){limit=F(20,s32);if(value>=limit)limit=value;}F(12,s32)=limit;}
 #undef F
}

#pragma opt_common_subs off
u8 func_ov003_02202e94(s32 arg0, s32 arg1) {
    u8 temp = arg1 + 0xFF;
    u8 result = 0;
    if ((u32)temp <= 5U) {
        result = ((1 << temp) & 0x23) != 0;
    }
    return result;
}
#pragma scheduling off
void func_ov003_02202ec0(void *arg0, u32 arg1) {
    s32 Divide(u8, M2C_UNK);
    s32 Modulo(u8, M2C_UNK);
    M2C_UNK SetTileRectPalette(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK SetTextById(s32, s32);
    M2C_UNK PlaySoundEffect(s32);
    s32 GetUnitSpriteWidth(void *);
    s32 GetUnitSpriteHeight(void *);
    s32 Ov003_GetEntryValueTextId(u8, u8);
    M2C_UNK func_ov003_02200dc8(void *, u32);
    extern void *gCur3DSpriteEngine;
    s32 temp_r2_2;
    s32 temp_r3;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_4;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r1;
    s8 var_r1_2;
    s8 var_r1_3;
    u16 temp_r0;
    u16 temp_r0_3;
    u16 temp_r0_4;
    u8 temp_r0_2;
    u8 temp_r4;
    void *temp_r1;
    void *temp_r2;
    void *temp_r7;

    temp_r4 = (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), void **, 0x10C), u16 *, 0x2E);
    func_ov003_02200dc8(M2C_FIELD(arg0, void **, 0x44), arg1);
    if (temp_r4 != (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), void **, 0x10C), u16 *, 0x2E)) {
        PlaySoundEffect(0x10019);
        temp_r7 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), void **, 0x10C);
        temp_r4_2 = GetUnitSpriteHeight(temp_r7);
        temp_r3=GetUnitSpriteWidth(temp_r7);
temp_r1=M2C_FIELD(arg0,void **,0x4c);
{
s16 y=M2C_FIELD(temp_r7,s16 *,0x36);s16 x=M2C_FIELD(temp_r7,s16 *,0x34);
((SpriteFields3368 *)temp_r1)->x=x;((SpriteFields3368 *)temp_r1)->y=y;
((SpriteFields3368 *)temp_r1)->width=temp_r3;
((SpriteFields3368 *)temp_r1)->height=temp_r4_2;
}
        if (((u32) (M2C_FIELD(arg0, u8 *, 0x3A) << 0x1A) >> 0x1A) == 1) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        if (!(var_r0 & 0xFF)) {
            temp_r2 = M2C_FIELD(arg0, void **, 0x44);
            temp_r0 = M2C_FIELD(M2C_FIELD(temp_r2, void **, 0x10C), u16 *, 0x2E);
            temp_r2_2 = M2C_FIELD((((u8) temp_r0 * 0x18) + (s32) temp_r2), s32 *, 0xC);
            switch ((u8) temp_r0) {
            default:
                break;
            case 0:
                SetTextById(M2C_FIELD(arg0, s32 *, 0x58), 0x47000000);
                break;
            case 1:
                SetTextById(M2C_FIELD(arg0, s32 *, 0x58), Ov003_GetEntryValueTextId((u8) temp_r0, (u8) temp_r2_2));
                break;
            case 2:
                SetTextById(M2C_FIELD(arg0, s32 *, 0x58), Ov003_GetEntryValueTextId((u8) temp_r0, (u8) temp_r2_2));
                break;
            case 3:
                SetTextById(M2C_FIELD(arg0, s32 *, 0x58), 0x4700000B);
                break;
            case 4:
                SetTextById(M2C_FIELD(arg0, s32 *, 0x58), 0x47000014);
                break;
            case 5:
                SetTextById(M2C_FIELD(arg0, s32 *, 0x58), 0x4700000A);
                break;
            case 6:
                SetTextById(M2C_FIELD(arg0, s32 *, 0x58), Ov003_GetEntryValueTextId((u8) temp_r0, (u8) temp_r2_2));
                break;
            case 7:
                SetTextById(M2C_FIELD(arg0, s32 *, 0x58), 0x47000015);
                break;
            case 8:
                SetTextById(M2C_FIELD(arg0, s32 *, 0x58), 0x47000018);
                break;
            }
        }
    }
    if (arg1 < 8U) {
        PlaySoundEffect(0x1000D);
        temp_r0_2 = M2C_FIELD(arg0, u8 *, 0x39);
        if (temp_r0_2 == 0) {
            var_r1 = 1;
        } else {
            var_r1 = 0;
        }
        if (var_r1 & 0xFF) {
            var_r0_2 = 1;
            M2C_FIELD(arg0, u8 *, 0x39) = var_r0_2;
            if (M2C_FIELD(arg0,u8 *,0x39) == 1) var_r0_2 = 1; else var_r0_2 = 0;
        if (var_r0_2 & 0xff) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8 *, 0x59) = 0;
        else M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8 *, 0x59) = 1;
            SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C), 0x20, 0x20, 0);
            if (M2C_FIELD(arg0, u8 *, 0x39) == 1) {
                var_r0_3 = 1;
            } else {
                var_r0_3 = 0;
            }
            if (var_r0_3 & 0xFF) {
                temp_r0_3 = (u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), void **, 0x10C), u16 *, 0x2E);
                temp_r4_3 = Modulo(temp_r0_3, 4);
                temp_r2_2 = Divide(temp_r0_3, 4);
                temp_r4_3 = temp_r4_3 * 8 + 0x60;
                SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x2c)+((u32)((temp_r2_2*0x120+temp_r4_3)<<16)>>15),8,8,1);
            }
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
            return;
        }
        if (temp_r0_2 == 1) {
            var_r0_4 = 1;
        } else {
            var_r0_4 = 0;
        }
        if (!(var_r0_4 & 0xFF)) {
            return;
        }
        var_r0_5 = 0;
        M2C_FIELD(arg0, u8 *, 0x39) = var_r0_5;
        if (M2C_FIELD(arg0,u8 *,0x39) == 1) var_r0_5 = 1; else var_r0_5 = 0;
        if (var_r0_5 & 0xff) M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8 *, 0x59) = 0;
        else M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s8 *, 0x59) = 1;
        SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C), 0x20, 0x20, 0);
        if (M2C_FIELD(arg0, u8 *, 0x39) == 1) {
            var_r0_6 = 1;
        } else {
            var_r0_6 = 0;
        }
        if (var_r0_6 & 0xFF) {
            temp_r0_4 = (u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x44), void **, 0x10C), u16 *, 0x2E);
            temp_r4_4 = Modulo(temp_r0_4, 4);
                temp_r2_2 = Divide(temp_r0_4, 4);
                temp_r4_4 = temp_r4_4 * 8 + 0x60;
                SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x2c)+((u32)((temp_r2_2*0x120+temp_r4_4)<<16)>>15),8,8,1);
        }
        M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
        return;
    }
    if (arg1 != 8) {
        return;
    }
    ((void (***)(void *))arg0)[0][7](arg0);
}
#pragma scheduling reset
void func_ov003_02203280(void *arg0) {
    M2C_UNK Sprite_ResumeAnimation(void *);
    M2C_UNK Hide3DSprite(s32);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK EnableMapConfirm();
    M2C_UNK SetOv003SceneState(M2C_UNK);
    M2C_UNK Ov003_SetMapConfirmEnabled();
    s32 func_ov003_02200c7c();
    M2C_UNK func_ov003_02204fac(void *);
    extern u16 gMapConfig;
    void *self;
    void *temp_r0;
    void *base;
    u8 var_r7;

    self = arg0;
    EnableMapConfirm();
    PlaySoundEffect(0x1000E);
    temp_r0 = M2C_FIELD(M2C_FIELD(self, void **, 0x40), void **, 4);
    if ((s32) M2C_FIELD(temp_r0, s8 *, 0x5A) >= 0) {
        M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0, s8 *, 0x5A) = 0xC;
    }
    Ov003_SetMapConfirmEnabled();
    base = M2C_FIELD(self, void **, 0x44);
    var_r7 = 0;
    do {
        s32 value = M2C_FIELD(((var_r7 * 0x18) + base), s32 *, 0xC);
        void **temp_r0_2 = M2C_FIELD((base + (var_r7 * 4)), void ***, 0xC8);
        M2C_FIELD(*temp_r0_2, M2C_UNK (**)(void **, s32), 0x1C)(temp_r0_2, value);
        var_r7 += 1;
    } while ((u32) var_r7 < 8U);
    gMapConfig |= 0x2000;
    Hide3DSprite(M2C_FIELD(self, s32 *, 0x4C));
    SetOv003SceneState(2);
    M2C_FIELD(self, s8 *, 0x38) = 0;
    Sprite_ResumeAnimation(self);
    if (func_ov003_02200c7c() == 0) {
        return;
    }
    func_ov003_02204fac(self);
}

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
/* Applies a setup-menu entry change on the battle-setup scene `scene`: selects
 * entry `entryIndex` in the scene's setup menu, and when the shown entry changed
 * resizes its panel sprite to the entry sprite and rewrites the entry's value
 * text, then hides the option-description panel. */
void Ov003_RefreshSelectedEntry(void *scene,u32 entryIndex) {
 s32 Divide(u8, M2C_UNK);
 s32 Modulo(u8, M2C_UNK);
 M2C_UNK SetTileRectPalette(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 M2C_UNK SetTextById(s32, s32);
 M2C_UNK PlaySoundEffect(s32);
 s32 GetUnitSpriteWidth(void *);
 s32 GetUnitSpriteHeight(void *);
 s32 Ov003_GetEntryValueTextId(u8, u8);
 M2C_UNK func_ov003_02200dc8(void *,u32);
 extern void *gCur3DSpriteEngine;
 void *self = scene;
 u8 oldEntry;
 s32 entryHeight;
 s32 entryWidth;
 void *entry;
 void *panelSprite;
 void *menu;
 u8 entryId;
 s32 entryValue;
 s32 stateIsOne;
 s32 panelFlag;
 s32 panelFlag2;
 u16 entryId2;
 s32 tileX;
oldEntry = (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(self, void **, 0x44), void **, SETUP_MENU_CURRENT), u16 *, 0x2E);
func_ov003_02200dc8(M2C_FIELD(self,void **,0x44),entryIndex);
if (oldEntry != (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(self, void **, 0x44), void **, SETUP_MENU_CURRENT), u16 *, 0x2E)) {
PlaySoundEffect(0x10019);
entry = M2C_FIELD(M2C_FIELD(self, void **, 0x44), void **, SETUP_MENU_CURRENT);
entryHeight = GetUnitSpriteHeight(entry);
entryWidth=GetUnitSpriteWidth(entry);
panelSprite=M2C_FIELD(self,void **,0x4c);
{
s16 y=M2C_FIELD(entry,s16 *,0x36);s16 x=M2C_FIELD(entry,s16 *,0x34);
((SpriteFields3368 *)panelSprite)->x=x;((SpriteFields3368 *)panelSprite)->y=y;
((SpriteFields3368 *)panelSprite)->width=entryWidth;
((SpriteFields3368 *)panelSprite)->height=entryHeight;
}
if (((u32)(M2C_FIELD(self, u8 *, 0x3A) << 0x1A) >> 0x1A) == 1) {
stateIsOne = 1;
} else {
stateIsOne = 0;
}
if (!(stateIsOne & 0xFF)) {
menu = M2C_FIELD(self, void **, 0x44);
entryId = (u8) M2C_FIELD(M2C_FIELD(menu, void **, SETUP_MENU_CURRENT), u16 *, 0x2E);
entryValue = M2C_FIELD((((u8) entryId * 0x18) + (s32) menu), s32 *, 0xC);
switch (entryId) {
default: break;
case 0: SetTextById(M2C_FIELD(self, s32 *, 0x58), 0x47000000); break;
case 1: SetTextById(M2C_FIELD(self, s32 *, 0x58), Ov003_GetEntryValueTextId(entryId, (u8) entryValue)); break;
case 2: SetTextById(M2C_FIELD(self, s32 *, 0x58), Ov003_GetEntryValueTextId(entryId, (u8) entryValue)); break;
case 3: SetTextById(M2C_FIELD(self, s32 *, 0x58), 0x4700000B); break;
case 4: SetTextById(M2C_FIELD(self, s32 *, 0x58), 0x47000014); break;
case 5: SetTextById(M2C_FIELD(self, s32 *, 0x58), 0x4700000A); break;
case 6: SetTextById(M2C_FIELD(self, s32 *, 0x58), Ov003_GetEntryValueTextId(entryId, (u8) entryValue)); break;
case 7: SetTextById(M2C_FIELD(self, s32 *, 0x58), 0x47000015); break;
case 8: SetTextById(M2C_FIELD(self, s32 *, 0x58), 0x47000018); break;
}
}
}
panelFlag = 0;
M2C_FIELD(self, u8 *, 0x39) = 0U;
if (M2C_FIELD(self,u8 *,0x39) == 1) panelFlag = 1;
if (panelFlag & 0xff) M2C_FIELD(M2C_FIELD(self, void **, 0x4c), s8 *, MENU_SPRITE_BASE) = 0;
else M2C_FIELD(M2C_FIELD(self, void **, 0x4c), s8 *, MENU_SPRITE_BASE) = 1;
SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C), 0x20, 0x20, 0);
if (M2C_FIELD(self, u8 *, 0x39) == 1) panelFlag2 = 1; else panelFlag2 = 0;
if (panelFlag2 & 0xFF) {
entryId2 = (u8) M2C_FIELD(M2C_FIELD(M2C_FIELD(self, void **, 0x44), void **, SETUP_MENU_CURRENT), u16 *, 0x2E);
tileX = Modulo(entryId2, 4);
entryValue=Divide(entryId2,4);
tileX=tileX*8+0x60;
SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x2c)+((u32)((entryValue*0x120+tileX)<<16)>>15),8,8,1);
}
M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
}
#pragma opt_common_subs on
/* One D-pad press on the selected setup-menu row: subtract the row's step from its
   value, then wrap between min/max if the row wraps, else clamp. */
void Ov003_DecreaseSelectedEntry(void *menu, s32 row) {
 s32 value,limit;
#define F(o,t) (*(t *)((char *)menu+(o)+row*24))  /* field at byte offset o of the row */
 ((Ov003MenuEntry *)((char *)menu+12))[row].value-=M2C_FIELD((unsigned)menu+row*24,s32 *,24);
 if(F(28,u8)){                                    /* row->wrap */
 if(F(12,s32)>F(16,s32)) { Ov003MenuRow *p=(Ov003MenuRow *)((char *)menu+row*24); do { p->value-=p->maximum-p->minimum+1; } while(p->value>p->maximum); }
 if(F(12,s32)<F(20,s32)) { Ov003MenuRow *q=(Ov003MenuRow *)((char *)menu+row*24); do { q->value+=q->maximum-q->minimum+1; } while(q->value<q->minimum); }
 }else{limit=F(16,s32);value=F(12,s32);if(value<=limit){limit=F(20,s32);if(value>=limit)limit=value;}F(12,s32)=limit;}
 #undef F
}
#pragma opt_common_subs off
u8 func_ov003_022036c8(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s8 *, 4) != -1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s8 func_ov003_022036e4(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 4);
}

u8 func_ov003_022036ec(void *arg0) { u8 var_r0; if (M2C_FIELD(arg0, s8 *, 5) != -1) { var_r0 = 1; } else { var_r0 = 0; } return var_r0; }

s8 func_ov003_02203708(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 5);
}

