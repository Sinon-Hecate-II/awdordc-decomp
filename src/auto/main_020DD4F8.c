/* 25 functions from 0x020DD4F8 to 0x020DE264 (main), found by ds-decomp. */
#include "common.h"
/* Menu that pages through the unit preview (ov009 3D view): the cursor picks one of the unit
 * slots, gUnitSlotIds turns the slot into a unit id and ov009 shows that unit in 3D. */
typedef struct UnitMenu {
    u8 pad00[0x34];
    s32 kind;             /* +0x34: screen that opened the menu (0 = map, 1/2 = others) */
    s32 variant;          /* +0x38: sub-kind used when kind == 0 */
    u8 pad3C[4];
    u8 step;              /* +0x40: screen step handed to the engine */
    s8 shownIndex;        /* +0x41: option last shown */
    s8 index;             /* +0x42: option the cursor points at */
    s8 slot;              /* +0x43: unit slot under the cursor, index into gUnitSlotIds */
    u8 pad44[4];
    u16 flags;            /* +0x48: bit0 accepted, bit1 input handled, bit5 redraw pending */
    u8 pad4A[6];
    void *cursorSprite;   /* +0x50: frame base+2 = highlighted */
    void *titleSprite;    /* +0x54 */
    void *backSprite;     /* +0x58: back button */
    void *confirmSprite;  /* +0x5C: confirm button of the no-slot-list variant */
    void *panelSprite;    /* +0x60 */
    void *unitSprite;     /* +0x64: previewed unit */
    void *animSprite;     /* +0x68 */
} UnitMenu;
typedef struct {u8 pad[0x59];u8 base:4;u8 pressed:1;u8 rest:3;} SpriteInput;
static inline u8 SpritePressed(void *p) {
void *q=M2C_FIELD(p,void **,0x64);s32 result=1;
if(M2C_FIELD(q,s8 *,11)!=1) {
if(((SpriteInput *)p)->pressed && M2C_FIELD(q,s8 *,12)==1) {}else result=0;
}
return result;
}
static inline u16 SpriteFrame(void *p) {return (M2C_FIELD(p,u32 *,0x40)<<6)>>24;}
static inline u32 SpriteBase(void *p) {return (u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28;}
static inline u8 SpriteAvailable(void *p) {u8 r;if(SpriteBase(p)+2!=SpriteFrame(p))r=1;else r=0;return r;}
static inline void SetSpriteFrame(void *p,u16 frame,s8 timer) {
M2C_FIELD(p,s32 *,0x40)=(M2C_FIELD(p,s32 *,0x40)&~0x03fc0000)|((u32)(frame<<24)>>6);
M2C_FIELD(p,s8 *,0x5a)=timer;
}
static inline void PressSprite(void *p) {if(M2C_FIELD(p,s8 *,0x5a)>=0)SetSpriteFrame(p,SpriteBase(p)+1,12);}


/* Input handler of the unit preview menu: the back button closes the 3D view, the cursor
   sprite shows whether the unit of the slot under the cursor exists and confirming picks
   that unit. */
void UnitPreviewMenuInput(void *arg0) {
void MenuSpriteUpdate(void *);void func_020d47f0(void);void SetSpriteAnimation(void *,s32);void PlaySoundEffect(s32);void func_01ffa6fc(void *);
s32 func_020b212c(void);M2C_UNK func_ov009_02224688(void);s32 func_ov009_022246ac(s32);
extern u16 *gKeyState;extern M2C_UNK gUnitSlotIds;
u16 keys;void *cursorSprite;
if(M2C_FIELD(arg0,void **,0x50))MenuSpriteUpdate(M2C_FIELD(arg0,void **,0x50));
if(M2C_FIELD(arg0,void **,0x54))MenuSpriteUpdate(M2C_FIELD(arg0,void **,0x54));
if(M2C_FIELD(arg0,void **,0x58))MenuSpriteUpdate(M2C_FIELD(arg0,void **,0x58));
keys=*gKeyState;
M2C_FIELD(arg0,u16 *,0x48)&=~32;
/* the back button closes the 3D view */
if((SpritePressed(M2C_FIELD(arg0,void **,0x58)) || (keys&2)) && !(M2C_FIELD(arg0,u16 *,0x48)&2)){
func_ov009_02224688();
PressSprite(M2C_FIELD(arg0,void **,0x58));
func_020d47f0();SetSpriteAnimation(arg0,1);PlaySoundEffect(0x1000f);return;
}
/* the cursor moved to another option */
if((M2C_FIELD(arg0,s8 *,0x41)>0 || M2C_FIELD(arg0,s8 *,0x42)>0) && M2C_FIELD(arg0,s8 *,0x41)!=M2C_FIELD(arg0,s8 *,0x42)){
PlaySoundEffect(M2C_FIELD(arg0,s8 *,0x41)<M2C_FIELD(arg0,s8 *,0x42)?0x122:0x123);
M2C_FIELD(arg0,s8 *,0x41)=M2C_FIELD(arg0,s8 *,0x42);
}
if(func_020b212c()<4){
/* the unit of the slot under the cursor: the cursor sprite shows it as available or not */
s32 unitId=(&gUnitSlotIds)[M2C_FIELD(arg0,s8 *,0x43)];
if(unitId<0)unitId=0;else unitId=func_ov009_022246ac(unitId);
if(unitId){void *cursorSprite=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(cursorSprite))SetSpriteFrame(cursorSprite,SpriteBase(cursorSprite),0);}
else {void *cursorSprite=M2C_FIELD(arg0,void **,0x50);if(SpriteAvailable(cursorSprite))SetSpriteFrame(cursorSprite,SpriteBase(cursorSprite)+2,0);}
cursorSprite=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(cursorSprite))return;
if(!(SpritePressed(cursorSprite) || (keys&1)))return;
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
PressSprite(cursorSprite);
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
M2C_FIELD(arg0,u16 *,0x48)&=~1;
M2C_FIELD(arg0,u16 *,0x48)|=2;
PlaySoundEffect(0x1000d);func_01ffa6fc(arg0);return;
}
cursorSprite=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(cursorSprite))SetSpriteFrame(cursorSprite,SpriteBase(cursorSprite),0);
cursorSprite=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(cursorSprite))return;
if(!(SpritePressed(cursorSprite) || (keys&1)))return;
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
PressSprite(M2C_FIELD(arg0,void **,0x5c));
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
M2C_FIELD(arg0,u16 *,0x48)|=1;
M2C_FIELD(arg0,u16 *,0x48)|=2;
PlaySoundEffect(0x1000d);func_01ffa6fc(arg0);
}

void func_020dd97c(void) {

}

/* Input handler of the unit deployment menu: the back button closes the 3D view,
 * the cursor sprite shows whether the unit of the slot under the cursor exists
 * and confirming picks that unit. */
void UnitDeployMenuInput(void *arg0) {
void MenuSpriteUpdate(void *);void func_020d47f0(void);void SetSpriteAnimation(void *,s32);void PlaySoundEffect(s32);void func_01ffa6fc(void *);
s32 func_020b212c(void);M2C_UNK func_ov009_02224688(void);s32 func_ov009_022246ac(s32);
extern u16 *gKeyState;extern M2C_UNK gUnitSlotIds;
u16 keys;void *cursorSprite;
if(M2C_FIELD(arg0,void **,0x50))MenuSpriteUpdate(M2C_FIELD(arg0,void **,0x50));
if(M2C_FIELD(arg0,void **,0x54))MenuSpriteUpdate(M2C_FIELD(arg0,void **,0x54));
if(M2C_FIELD(arg0,void **,0x58))MenuSpriteUpdate(M2C_FIELD(arg0,void **,0x58));
keys=*gKeyState;
M2C_FIELD(arg0,u16 *,0x48)&=~32;
/* the back button closes the 3D view */
if((SpritePressed(M2C_FIELD(arg0,void **,0x58)) || (keys&2)) && !(M2C_FIELD(arg0,u16 *,0x48)&2)){
PressSprite(M2C_FIELD(arg0,void **,0x58));
func_020d47f0();
switch(M2C_FIELD(arg0,s32 *,0x38)) {
case 0: M2C_FIELD(arg0,u8 *,0x40)=0x26; M2C_FIELD(arg0,u16 *,0x48)|=32; SetSpriteAnimation(arg0,0x44); break;
case 1: M2C_FIELD(arg0,u8 *,0x40)=0x27; SetSpriteAnimation(arg0,1); break;
}
PlaySoundEffect(0x1000f);return;
}
/* the cursor moved to another option */
if((M2C_FIELD(arg0,s8 *,0x41)>0 || M2C_FIELD(arg0,s8 *,0x42)>0) && M2C_FIELD(arg0,s8 *,0x41)!=M2C_FIELD(arg0,s8 *,0x42)){
PlaySoundEffect(M2C_FIELD(arg0,s8 *,0x41)<M2C_FIELD(arg0,s8 *,0x42)?0x122:0x123);
M2C_FIELD(arg0,s8 *,0x41)=M2C_FIELD(arg0,s8 *,0x42);
}
if(func_020b212c()<4){
/* the unit of the slot under the cursor: the cursor sprite shows it as available or not */
if((&gUnitSlotIds)[func_020b212c()]>=0){void *cursorSprite=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(cursorSprite))SetSpriteFrame(cursorSprite,SpriteBase(cursorSprite),0);}
else {void *cursorSprite=M2C_FIELD(arg0,void **,0x50);if(SpriteAvailable(cursorSprite))SetSpriteFrame(cursorSprite,SpriteBase(cursorSprite)+2,0);}
cursorSprite=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(cursorSprite))return;
if(!(SpritePressed(cursorSprite) || (keys&1)))return;
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
PressSprite(cursorSprite);
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
M2C_FIELD(arg0,u16 *,0x48)&=~1;
M2C_FIELD(arg0,u16 *,0x48)|=2;
PlaySoundEffect(0x1000d);func_01ffa6fc(arg0);return;
}
cursorSprite=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(cursorSprite))SetSpriteFrame(cursorSprite,SpriteBase(cursorSprite),0);
cursorSprite=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(cursorSprite))return;
if(!(SpritePressed(cursorSprite) || (keys&1)))return;
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
PressSprite(M2C_FIELD(arg0,void **,0x5c));
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
M2C_FIELD(arg0,u16 *,0x48)|=1;
M2C_FIELD(arg0,u16 *,0x48)|=2;
PlaySoundEffect(0x1000d);func_01ffa6fc(arg0);
}

void func_020dde30(void) {
    void UnitDeployMenuInput();
    UnitDeployMenuInput();
}

void func_020dde3c(void) {
    void UnitPreviewMenuInput();
    UnitPreviewMenuInput();
}

void func_020dde48(void) {
    void UnitPreviewMenuInput();
    UnitPreviewMenuInput();
}

void func_020dde54(void) {
    func_020dd97c();
}

void func_020dde60(void) {
    func_020dd97c();
}

void func_020dde6c(void) {
    void UnitDeployMenuInput();
    UnitDeployMenuInput();
}

void func_020dde78(void) {
    void UnitDeployMenuInput();
    UnitDeployMenuInput();
}

void func_020dde84(void) {
    func_020dde30();
}

void func_020dde90(void) {
    func_020dde30();
}

M2C_UNK func_020dde9c(void *arg0) {
    M2C_UNK func_ov009_02224688();
    M2C_UNK func_020b2178();
    M2C_UNK func_020b1c44(M2C_UNK, M2C_UNK);
    M2C_UNK func_02088ff4(s32);
    s16 GetSpriteAnimValue(void *);
    s16 temp_r0;
    void *temp_r2;
    u16 value;

    func_020b2178();
    func_020b1c44(0, 0);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x50));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x58));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x5C));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x64));
    temp_r0 = GetSpriteAnimValue(M2C_FIELD(arg0, void **, 0x68));
    temp_r2 = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(temp_r2, s16 *, 0xE) = temp_r0;
    M2C_FIELD(temp_r2, s16 *, 0x10) = -0xFF;
    M2C_FIELD(temp_r2, s16 *, 0xC) = 0xC;
    value = M2C_FIELD(temp_r2, u16 *, 4);
    M2C_FIELD(temp_r2, u16 *, 2) = value;
    return func_ov009_02224688();
}

void func_020ddf04(void) {

}

M2C_UNK func_020ddf08(void *arg0) {
    M2C_UNK func_020b2178();
    M2C_UNK func_020b1c44(M2C_UNK, M2C_UNK);
    M2C_UNK func_02088ff4(s32);
    s16 GetSpriteAnimValue(void *);
    s16 temp_r0;
    void *temp_r2;
    u16 value;

    func_020b2178();
    func_020b1c44(0, 0);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x50));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x58));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x5C));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x64));
    temp_r0 = GetSpriteAnimValue(M2C_FIELD(arg0, void **, 0x68));
    temp_r2 = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(temp_r2, s16 *, 0xE) = temp_r0;
    M2C_FIELD(temp_r2, s16 *, 0x10) = -0xFF;
    M2C_FIELD(temp_r2, s16 *, 0xC) = 0xC;
    value = M2C_FIELD(temp_r2, u16 *, 4);
    M2C_FIELD(temp_r2, u16 *, 2) = value;
    return value;
}

void func_020ddf6c(void) {
    M2C_UNK func_020ddf08();
    func_020ddf08();
}

void func_020ddf78(void) {
    M2C_UNK func_020dde9c();
    func_020dde9c();
}

void func_020ddf84(void) {
    M2C_UNK func_020dde9c();
    func_020dde9c();
}

void func_020ddf90(void) {
    func_020ddf04();
}

void func_020ddf9c(void) {
    func_020ddf04();
}

void func_020ddfa8(void) {
    M2C_UNK func_020ddf08();
    func_020ddf08();
}

void func_020ddfb4(void) {
    M2C_UNK func_020ddf08();
    func_020ddf08();
}

void func_020ddfc0(void) {
    func_020ddf6c();
}

void func_020ddfcc(void) {
    func_020ddf6c();
}

/* Prepares the ov009 3D unit preview: switches to the main screen's engine,
   loads the palette/texture set for the menu's screen kind, resets the menu
   sprites, then queues either the confirm action or the slot's unit preview. */
void SetupUnitPreviewScene(UnitMenu *menu, M2C_UNK side) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK SetFileDirectory(M2C_UNK *);
    s32 func_02012084();
    M2C_UNK func_02080944(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_02088f1c(s32);
    M2C_UNK SetTextById(s32, s32);
    s16 GetSpriteAnimValue(void *);
    s32 GetLocalizedFileName(M2C_UNK *);
    s32 func_ov009_0222429c();
    s32 func_ov009_022246ac(s32);
    M2C_UNK func_ov009_02224730(M2C_UNK, M2C_UNK, s32, s32, s32);
    M2C_UNK func_ov009_022249a4(M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_0212d3f0;
    extern M2C_UNK data_0212d3f8;
    extern M2C_UNK data_0212d408;
    extern M2C_UNK data_0212d418;
    extern M2C_UNK gUnitSlotIds;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    s32 kind;
    s32 kind2;
    s32 unitId;
    s32 id;
    s32 layout;
    s32 layout2;
    void *titleSprite;
    void *animSprite;
    void *savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    SetFileDirectory(&data_0212d3f0);
    GetLocalizedFileName(&data_0212d3f8);
    OpenNarcArchive();
    kind = menu->kind;
    layout = -1;
    switch (kind) {                                 /* switch 1; irregular */
    case 1:                                         /* switch 1 */
    case 2:                                         /* switch 1 */
        layout = 2;
        break;
    case 0:                                         /* switch 1 */
        switch(menu->variant){case 1:layout=2;break;default:layout=4;break;}
        break;
    }
    if (layout != 2) {
        if (layout == 4) {
            LoadNarcFileDecompressed(GetLocalizedFileName(&data_0212d408), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
        }
    } else {
        LoadNarcFileDecompressed(GetLocalizedFileName(&data_0212d418), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
    }
    CloseNarcArchive();
    func_02080944(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), 0x20, 0x18, 5);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    gCur3DSpriteEngine = savedEngine;
    menu->flags = (u16) (menu->flags | 0x20);
    titleSprite = menu->titleSprite;
    M2C_FIELD(titleSprite, s32 *, 0x40) = (s32) ((M2C_FIELD(titleSprite, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(titleSprite, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(titleSprite, s8 *, 0x5A) = 0;
    func_02088f1c((s32)menu->backSprite);
    func_02088da8((s32)menu->panelSprite);
    SetTextById((s32)menu->unitSprite, 0x44000011);
    func_02088f1c((s32)menu->unitSprite);
    if (GetSpriteAnimValue(menu->animSprite) != 0) {
        id=GetSpriteAnimValue(menu->animSprite);
        animSprite = menu->animSprite;
        M2C_FIELD(animSprite, s16 *, 0xE) = id;
        M2C_FIELD(animSprite, s16 *, 0x10) = 0;
        M2C_FIELD(animSprite, s16 *, 0xC) = 0xC;
        M2C_FIELD(animSprite, u16 *, 2) = (u16) M2C_FIELD(animSprite, u16 *, 4);
    }
    menu->flags = (u16) (menu->flags & ~0x100);
    menu->flags = (u16) (menu->flags & ~0x200);
    menu->shownIndex = 0;
    if (menu->flags & 1) {
        kind2 = menu->kind;
        layout2 = -1;
        switch (kind2) {                            /* switch 2; irregular */
        case 1:                                     /* switch 2 */
        case 2:                                     /* switch 2 */
            layout2 = 2;
            break;
        case 0:                                     /* switch 2 */
            switch(menu->variant){case 1:layout2=2;break;default:layout2=4;break;}
            break;
        }
        id = func_02012084();
        func_ov009_02224730(0, side, id, func_ov009_0222429c(), (u8)layout2);
        return;
    }
    unitId = func_ov009_022246ac(*(&gUnitSlotIds + menu->slot));
    if (unitId == 0) {
        return;
    }
    func_ov009_022249a4(1, side, unitId);
}

