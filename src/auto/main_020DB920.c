/* 25 functions from 0x020DB920 to 0x020DC838 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

static inline void func_020dbe00(void *q) {
    s32 next;
    u32 base;
    u32 value;
    s32 test;
    base = (u32) (M2C_FIELD(q, u8 *, 0x59) << 28) >> 28;
    next = base + 2;
    if (next != (u16) ((u32) (M2C_FIELD(q, s32 *, 0x40) << 6) >> 24)) test = 1; else test = 0;
    if (test & 255) value = base << 16; else value = next << 16;
    M2C_FIELD(q, u32 *, 0x40) = (M2C_FIELD(q, u32 *, 0x40) & ~0x3fc0000) | (((value >> 16) << 24) >> 6);
}

static inline void func_020dbe10(void *q) {
    s32 next;
    u32 base;
    u32 value;
    s32 test;
    base = (u32) (M2C_FIELD(q, u8 *, 0x59) << 28) >> 28;
    next = base + 2;
    if (next != (u16) ((u32) (M2C_FIELD(q, s32 *, 0x40) << 6) >> 24)) test = 1; else test = 0;
    if (test & 255) value = base << 16; else value = next << 16;
    M2C_FIELD(q, u32 *, 0x40) = (M2C_FIELD(q, u32 *, 0x40) & ~0x3fc0000) | (((value >> 16) << 24) >> 6);
}

static inline void func_020dbe20(void *q) {
    u32 base;
    s32 next;
    s32 test;
    base = (u32) (M2C_FIELD(q, u8 *, 0x59) << 28) >> 28;
    next = base + 2;
    if (next != (u16) ((u32) (M2C_FIELD(q, s32 *, 0x40) << 6) >> 24)) test = 1; else test = 0;
    if (!(test & 255)) {
        M2C_FIELD(q, u32 *, 0x40) = (M2C_FIELD(q, u32 *, 0x40) & ~0x3fc0000) | ((u32) ((u16) base << 24) >> 6);
        *(volatile u8 *)((u8 *)q + 0x5a) = 0;
    }
}

typedef struct MenuSprite {
    u8 pad[0x40];
    unsigned field0:18;
    unsigned frame:8;
    unsigned field26:6;
    u8 pad44[0x15];
    u8 baseFrame:4;
    u8 alternate:1;
    u8 otherFlags:3;
} MenuSprite;
static inline u8 MenuSpriteIsActive(void *p) { return ((MenuSprite *)p)->baseFrame + 2 != (u16)((MenuSprite *)p)->frame; }
static inline void MenuSpriteSetFrame(void *p, u16 frame, s8 timer) { ((MenuSprite *)p)->frame = frame; M2C_FIELD(p, s8 *, 0x5a) = timer; }

/* Draw the communication player-list panel: scroll with the sprite animation,
   then draw the header record (our own when bit 0 of the flags is set, else the
   selected online player's) with its player counts, followed by one name row per
   player.  Sets bit 8/9 of the flags when the online record cannot be shown. */
void DrawPlayerListPanel(void *arg0) {
extern void **gCur3DSpriteEngine, **g3DSpriteEngineMain;
extern s8 sLocalCountUnits[],sLocalCountTens[],sLocalCountFormat[],sOnlineCountUnits[],sOnlineCountTens[],sOnlineCountFormat[],sZeroPlayerText[];
extern s32 gUnitSlotIds[];
M2C_UNK UpdateSpriteAnimation(s32),SetSpriteSlotScroll(s32,s32),ClearTileRect(void *,s32,s32),DrawGlyphString(void *,s32,void *,s32,s32,u16,s32),StringFormat(char *,void *,s32,...),DrawTextLine(s32,s32,s32,char *,s32,u16),InitOnlinePlayerRecord(void *);
s32 GetSpriteAnimValue(s32),GetBattleSlotSummary(s32),GetMatchPlayerName(s32,u8 *,u8 *,void *,s32 *),IsOnlineSessionFlagSet(s32);
void *GetLocalPlayerStatus(void),*GetOnlinePlayerRecord(s32);
u32 GetLinkPlayerCount(void),GetConnectedPlayerCount(void);
void **savedEngine;
u8 playerCount, connectedCount;
s32 fitWidth;
char localText[16],onlineText[16];
u8 playerInfo[0x6c];
s32 anim, tile, rowY, rowIndex, row;
u16 scroll;
void *player;
UpdateSpriteAnimation(M2C_FIELD(arg0,s32 *,0x68));
anim=GetSpriteAnimValue(M2C_FIELD(arg0,s32 *,0x68));
SetSpriteSlotScroll(anim,0);
scroll=-anim;
savedEngine=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
M2C_FIELD(*g3DSpriteEngineMain,u16 *,0x3a)=scroll;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x42)=0;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x38)=scroll;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x40)=0;
tile=0x124+(*(u32 *)0x027ffc3c&1)*0x180;
if(M2C_FIELD(arg0,u16 *,0x48)&1){
player=GetLocalPlayerStatus();
playerCount=GetLinkPlayerCount();
connectedCount=GetConnectedPlayerCount();
ClearTileRect((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x86,20,2);
DrawGlyphString(player,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x10),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),9,3,2,tile);
StringFormat(localText,sLocalCountFormat,sLocalCountTens[0],sLocalCountUnits[1]+connectedCount,sLocalCountTens[0],sLocalCountUnits[1]+playerCount);
DrawTextLine(26,2,1,localText,0x9000,(u16)(tile+40));
tile+=52;
}else{
anim=GetBattleSlotSummary(gUnitSlotIds[M2C_FIELD(arg0,s8 *,0x43)]);
InitOnlinePlayerRecord(playerInfo);
if(GetMatchPlayerName(anim,&playerCount,&connectedCount,playerInfo,&fitWidth)!=6){M2C_FIELD(arg0,u16 *,0x48)|=0x100;return;}
if(!IsOnlineSessionFlagSet(3)&&(!(playerInfo[0x1a]&2)||playerCount==connectedCount)){M2C_FIELD(arg0,u16 *,0x48)|=0x200;return;}
ClearTileRect((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+0x86,20,2);
DrawGlyphString(playerInfo,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x10),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),9,3,2,tile);
StringFormat(onlineText,sOnlineCountFormat,sOnlineCountTens[0],sOnlineCountUnits[1]+connectedCount,sOnlineCountTens[0],sOnlineCountUnits[1]+playerCount);
DrawTextLine(26,2,1,onlineText,0x9000,(u16)(tile+40));
tile+=52;
}
for(rowY=7,rowIndex=0;rowIndex<playerCount;rowY+=3,rowIndex++){
player=GetOnlinePlayerRecord(rowIndex);
if(player&&GetConnectedPlayerCount()>=2){
ClearTileRect((u16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+7+(rowY<<5),20,2);
DrawGlyphString(player,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x10),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),9,7,(u16)rowY,tile);
tile+=40;
}else{
ClearTileRect((u16 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x24)+7+(rowY<<5),20,2);
DrawGlyphString(sZeroPlayerText,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x10),M2C_FIELD(gCur3DSpriteEngine,void **,0x24),9,7,(u16)rowY,tile);
tile+=40;
}}
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
gCur3DSpriteEngine=savedEngine;
}

void func_020dbd00(void) {
    M2C_UNK func_020db1a0();
    func_020db1a0();
}

void func_020dbd0c(void) {
    func_020db1a0();
}

void func_020dbd18(void) {
    M2C_UNK func_020db5e8();
    func_020db5e8();
}

void func_020dbd24(void) {
    func_020db5e8();
}

void func_020dbd30(void) {
    M2C_UNK func_020db914();
    func_020db914();
}

void func_020dbd3c(void) {
    func_020db914();
}

void func_020dbd48(void *arg0) {
    DrawPlayerListPanel(arg0);
}

void func_020dbd54(void *arg0) {
    DrawPlayerListPanel(arg0);
}

/* Step the player-list panel's scroll animation and shift the main engine's
 * sprite-bank layer offsets by the opposite amount. */
void UpdatePlayerListPanelScroll(void *panel) {
    M2C_UNK UpdateSpriteAnimation(s32);
    s32 GetSpriteAnimValue(s32);
    M2C_UNK SetSpriteSlotScroll(s32, M2C_UNK);
    extern void **g3DSpriteEngineMain;
    extern void **gCur3DSpriteEngine;
    s32 scrollValue;
    u16 inverseScroll;
    void **savedEngine;

    UpdateSpriteAnimation(M2C_FIELD(panel, s32 *, 0x68));
    scrollValue = GetSpriteAnimValue(M2C_FIELD(panel, s32 *, 0x68));
    SetSpriteSlotScroll(scrollValue, 0);
    savedEngine = gCur3DSpriteEngine;
    inverseScroll = 0 - scrollValue;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    M2C_FIELD(*g3DSpriteEngineMain, u16 *, DS3D_SCROLL_LAYER_Y) = inverseScroll;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, DS3D_OFFSET2_Y) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, DS3D_SCROLL_LAYER_X) = inverseScroll;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, DS3D_OFFSET2_X) = 0;
    gCur3DSpriteEngine = savedEngine;
}

/* Step the second player-list view's scroll animation and shift the main engine's
 * sprite-bank layer offsets by the opposite amount (same as the first view). */
void UpdatePlayerListPanelScrollAlt(void *panel) {
    M2C_UNK UpdateSpriteAnimation(s32);
    s32 GetSpriteAnimValue(s32);
    M2C_UNK SetSpriteSlotScroll(s32, M2C_UNK);
    extern void **g3DSpriteEngineMain;
    extern void **gCur3DSpriteEngine;
    s32 scrollValue;
    u16 inverseScroll;
    void **savedEngine;

    UpdateSpriteAnimation(M2C_FIELD(panel, s32 *, 0x68));
    scrollValue = GetSpriteAnimValue(M2C_FIELD(panel, s32 *, 0x68));
    SetSpriteSlotScroll(scrollValue, 0);
    savedEngine = gCur3DSpriteEngine;
    inverseScroll = 0 - scrollValue;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    M2C_FIELD(*g3DSpriteEngineMain, u16 *, DS3D_SCROLL_LAYER_Y) = inverseScroll;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, DS3D_OFFSET2_Y) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, DS3D_SCROLL_LAYER_X) = inverseScroll;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, DS3D_OFFSET2_X) = 0;
    gCur3DSpriteEngine = savedEngine;
}

void func_020dbe68(void *arg0) {
    void UpdatePlayerListPanelScrollAlt(void *);
    UpdatePlayerListPanelScrollAlt(arg0);
}

void func_020dbe74(void *arg0) {
    void UpdatePlayerListPanelScroll(void *);
    UpdatePlayerListPanelScroll(arg0);
}

void func_020dbe80(void *arg0) {
    UpdatePlayerListPanelScroll(arg0);
}

void func_020dbe8c(void *arg0) {
    UpdatePlayerListPanelScrollAlt(arg0);
}

void func_020dbe98(void *arg0) {
    UpdatePlayerListPanelScrollAlt(arg0);
}

void func_020dbea4(void *arg0) {
    func_020dbe68(arg0);
}

void func_020dbeb0(void *arg0) {
    func_020dbe68(arg0);
}

#pragma push
#pragma opt_lifetimes off
M2C_UNK func_020dbebc(void *arg0) {
extern void **gCur3DSpriteEngine, **g3DSpriteEngineMain;
extern M2C_UNK data_0212d358, data_0212d360, data_0212d370, data_0212c658;
M2C_UNK Clear3DSpriteLayer(s32), SetFileDirectory(void *);
s32 GetLocalizedFileName(void *);
M2C_UNK OpenNarcArchive(void), CloseNarcArchive(void);
M2C_UNK LoadNarcFileDecompressed(s32,s32), AddTileRectPalette(s32,s32,s32,s32);
s32 FindSpriteSlotById(s32);
void *AddSpriteSlot(s32,s32,void *,s32), *SelectSpriteSlot(s32);
M2C_UNK SetTileRectPalette(s32,s32,u16,u16);
M2C_UNK PlaySoundEffect(s32), SetSpriteSlotScroll(s32,s32);
M2C_UNK Show3DSpriteSlide(void *), SetTextById(void *,s32);
s32 GetSpriteAnimValue(s32);
void *sp4;
void **sp0;
s32 i, x, test;
s32 i2;
void *item;
s32 y, end;
s32 color;
u8 selected;
void *p;
void **saved;
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
Clear3DSpriteLayer(1);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
SetFileDirectory(&data_0212d358);
GetLocalizedFileName(&data_0212d360);
OpenNarcArchive();
LoadNarcFileDecompressed(GetLocalizedFileName(&data_0212d370),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20));
CloseNarcArchive();
AddTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20),32,24,5);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
gCur3DSpriteEngine=saved;
M2C_FIELD(arg0,u16 *,0x48)|=32;
if(FindSpriteSlotById(0)==0) test=1; else test=0;
if(test) {
i=0; x=0;
do {
p=AddSpriteSlot(0,x,&data_0212c658,i);
i++;
M2C_FIELD(p,void **,0x10)=arg0;
x+=40;
} while(i<2);
}
item=SelectSpriteSlot(M2C_FIELD(arg0,s32 *,0x3c));
if(item) {
sp4=M2C_FIELD(item,void **,0x10);
sp0=gCur3DSpriteEngine;
y=10;
gCur3DSpriteEngine=g3DSpriteEngineMain;
end=14; i2=0;
do {
if(M2C_FIELD(item,u8 *,0)!=i2) color=7; else color=8;
SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20)+8+(y<<6),24,(u16)(end-y),(u16)color);
i2++; y=(s16)(y+5); end=(s16)(end+5);
} while(i2<2);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
gCur3DSpriteEngine=sp0;
selected=M2C_FIELD(item,u8 *,0);
if(selected!=M2C_FIELD(sp4,s32 *,0x3c)) {
M2C_FIELD(sp4,s32 *,0x3c)=selected;
PlaySoundEffect(0x10019);
}
}
SetSpriteSlotScroll(0,0);
p=M2C_FIELD(arg0,void **,0x50);
Show3DSpriteSlide(p);
p=M2C_FIELD(arg0,void **,0x50);
func_020dbe00(p);
M2C_FIELD(p,u8 *,0x5a)=0;
p=M2C_FIELD(arg0,void **,0x58);
Show3DSpriteSlide(p);
p=M2C_FIELD(arg0,void **,0x58);
func_020dbe10(p);
M2C_FIELD(p,u8 *,0x5a)=0;
do {
func_020dbe20(M2C_FIELD(arg0,void **,0x50));
} while(0);
SetTextById(M2C_FIELD(arg0,void **,0x64),0x4400000e);
Show3DSpriteSlide(M2C_FIELD(arg0,void **,0x64));
if(GetSpriteAnimValue(M2C_FIELD(arg0,s32 *,0x68))) {
s32 result=GetSpriteAnimValue(M2C_FIELD(arg0,s32 *,0x68));
p=M2C_FIELD(arg0,void **,0x68);
M2C_FIELD(p,u16 *,0xe)=result;
M2C_FIELD(p,u16 *,0x10)=0;
M2C_FIELD(p,u16 *,0xc)=12;
M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);
}
M2C_FIELD(arg0,u16 *,0x48)&=~4;
}
#pragma pop
M2C_UNK func_020dc250(arg0)
void *arg0;
{
    M2C_UNK Clear3DSpriteLayer(s32), SetFileDirectory(void *);
    s32 GetLocalizedFileName(void *);
    M2C_UNK OpenNarcArchive(void), CloseNarcArchive(void);
    M2C_UNK LoadNarcFileDecompressed(s32,s32), AddTileRectPalette(s32,s32,s32,s32);
    s32 FindSpriteSlotById(s32);
    void *AddSpriteSlot(s32,s32,void *,s32), *SelectSpriteSlot(s32);
    M2C_UNK SetTileRectPalette(s32,s32,u16,u16);
    M2C_UNK PlaySoundEffect(s32), SetSpriteSlotScroll(s32,s32);
    M2C_UNK Show3DSpriteSlide(void *), SetTextById(void *,s32);
    s32 GetSpriteAnimValue(s32);
    extern void **gCur3DSpriteEngine, **g3DSpriteEngineMain;
    extern M2C_UNK data_0212d380, data_0212d388, data_0212d398, data_0212c658;
    void **saved;
    void *sp4;
    void **sp0;
    s32 i, x, test;
    s32 i2;
    void *item;
    s32 y, end;
    s32 color;
    s32 selected;
    void *p;
    saved=gCur3DSpriteEngine;
    gCur3DSpriteEngine=g3DSpriteEngineMain;
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
    SetFileDirectory(&data_0212d380);
    GetLocalizedFileName(&data_0212d388);
    OpenNarcArchive();
    LoadNarcFileDecompressed(GetLocalizedFileName(&data_0212d398),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20));
    CloseNarcArchive();
    AddTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20),32,24,5);
    M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
    gCur3DSpriteEngine=saved;
    M2C_FIELD(arg0,u16 *,0x48)|=32;
    if(FindSpriteSlotById(0)==0) test=1; else test=0;
    if(test) {
        i=0; x=0;
        do {
            p=AddSpriteSlot(0,x,&data_0212c658,i);
            i++;
            M2C_FIELD(p,void **,0x10)=arg0;
            x+=40;
        } while(i<2);
    }
    item=SelectSpriteSlot(M2C_FIELD(arg0,s32 *,0x3c));
    if(item) {
        sp4=M2C_FIELD(item,void **,0x10);
        sp0=gCur3DSpriteEngine;
        y=10;
        gCur3DSpriteEngine=g3DSpriteEngineMain;
        end=14; i2=0;
        do {
            if(M2C_FIELD(item,u8 *,0)!=i2) color=7; else color=8;
            SetTileRectPalette(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x20)+8+(y<<6),24,(u16)(end-y),(u16)color);
            i2++; y=(s16)(y+5); end=(s16)(end+5);
        } while(i2<2);
        M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=1;
        gCur3DSpriteEngine=sp0;
        selected=M2C_FIELD(item,u8 *,0);
        if(selected!=M2C_FIELD(sp4,s32 *,0x3c)) {
            M2C_FIELD(sp4,s32 *,0x3c)=selected;
            PlaySoundEffect(0x10019);
        }
    }
    SetSpriteSlotScroll(0,0);
    p=M2C_FIELD(arg0,void **,0x50);
    Show3DSpriteSlide(p);
    p=M2C_FIELD(arg0,void **,0x50);
    func_020dbe00(p);
    M2C_FIELD(p,u8 *,0x5a)=0;
    p=M2C_FIELD(arg0,void **,0x58);
    Show3DSpriteSlide(p);
    p=M2C_FIELD(arg0,void **,0x58);
    func_020dbe10(p);
    M2C_FIELD(p,u8 *,0x5a)=0;
    func_020dbe20(M2C_FIELD(arg0,void **,0x50));
    SetTextById(M2C_FIELD(arg0,void **,0x64),0x4400000e);
    Show3DSpriteSlide(M2C_FIELD(arg0,void **,0x64));
    if(GetSpriteAnimValue(M2C_FIELD(arg0,s32 *,0x68))) {
        s32 result=GetSpriteAnimValue(M2C_FIELD(arg0,s32 *,0x68));
        p=M2C_FIELD(arg0,void **,0x68);
        M2C_FIELD(p,u16 *,0xe)=result;
        M2C_FIELD(p,u16 *,0x10)=0;
        M2C_FIELD(p,u16 *,0xc)=12;
        M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);
    }
    M2C_FIELD(arg0,u16 *,0x48)&=~4;
    return 0;
}

void func_020dc5e4(void *arg0) {
    M2C_UNK func_020dbebc(void *);
    func_020dbebc(arg0);
}

void func_020dc5f0(void *arg0) {
    func_020dbebc(arg0);
}

void func_020dc5fc(void) {
    M2C_UNK func_020dc250();
    func_020dc250();
}

void func_020dc608(void) {
    func_020dc250();
}

/* Input handler of a menu screen: updates its sprites and turns the A/B presses
 * into the confirm and back animations of the highlighted option. */
void MenuConfirmInput(void *menu) {
    void MenuSpriteUpdate(void *);
    void DisableMapConfirm(void);
    void SetSpriteAnimation(void *, s32);
    s32 PlaySoundEffect(s32);
    void Sprite_ResumeAnimation(void *);
    extern u16 *gKeyState;
    typedef struct { u32 low:18; u32 frame:8; u32 high:6; } SpriteFrameBits;
    typedef struct { unsigned char base:4; } SpriteBaseBits;

    u32 keys;
    void *backSprite;
    u8 optionEnabled;

    if (M2C_FIELD(menu, void **, 0x50)) MenuSpriteUpdate(M2C_FIELD(menu, void **, 0x50));
    if (M2C_FIELD(menu, void **, 0x54)) MenuSpriteUpdate(M2C_FIELD(menu, void **, 0x54));
    if (M2C_FIELD(menu, void **, 0x58)) MenuSpriteUpdate(M2C_FIELD(menu, void **, 0x58));

    keys = *gKeyState;
    M2C_FIELD(menu, u16 *, 0x48) &= ~0x20;

    backSprite = M2C_FIELD(menu, void **, 0x58);
    optionEnabled = 1;
    if (M2C_FIELD(M2C_FIELD(backSprite, void **, MENU_SPRITE_OWNER), s8 *, 0xb) != 1) {
        if (!((u32)(M2C_FIELD(backSprite, u8 *, MENU_SPRITE_BASE) << 27) >> 31) || M2C_FIELD(M2C_FIELD(backSprite, void **, MENU_SPRITE_OWNER), s8 *, 0xc) != 1)
            optionEnabled = 0;
    }

    if ((u8)(optionEnabled & 0xff) == 0) {
        if (!(keys & 0x2)) goto skip1;
    }
    if (M2C_FIELD(menu, u16 *, 0x48) & 0x4) goto skip1;

    if (M2C_FIELD(backSprite, s8 *, MENU_SPRITE_TIMER) >= 0) {
        M2C_FIELD(backSprite, SpriteFrameBits *, MENU_SPRITE_FRAME).frame = (u16)(M2C_FIELD(backSprite, SpriteBaseBits *, MENU_SPRITE_BASE).base + 1);
        M2C_FIELD(backSprite, u8 *, MENU_SPRITE_TIMER) = 12;
    }
    DisableMapConfirm();
    switch(M2C_FIELD(menu,s32*,0x38)){
    case 0: M2C_FIELD(menu,u8*,0x40)=0x1c; break;
    case 1: M2C_FIELD(menu,u8*,0x40)=0x1d; break;
    }
    M2C_FIELD(menu, u16 *, 0x48) |= 0x20;
    SetSpriteAnimation(menu, 0x44);
    PlaySoundEffect(0x1000f);
    return;

skip1:
    {
        void *optionSprite = M2C_FIELD(menu, void **, 0x50);
        u32 baseFrame = M2C_FIELD(optionSprite, SpriteBaseBits *, MENU_SPRITE_BASE).base;
        u16 frame = (M2C_FIELD(optionSprite, u32 *, MENU_SPRITE_FRAME) << 6) >> 24;
        s32 changed;
        if (baseFrame + 2 != frame) changed=1; else changed=0;
        if (changed & 0xff) {
            u8 optionEnabled2 = 1;
            void *owner = M2C_FIELD(optionSprite, void **, MENU_SPRITE_OWNER);
            if (M2C_FIELD(owner, s8 *, 0xb) != 1) {
                if (!((u32)(M2C_FIELD(optionSprite, u8 *, MENU_SPRITE_BASE) << 27) >> 31) || M2C_FIELD(owner, s8 *, 0xc) != 1)
                    optionEnabled2 = 0;
            }
            if ((u8)(optionEnabled2 & 0xff) == 0) {
                if (!(keys & 0x1)) return;
            }
            if (M2C_FIELD(menu, u16 *, 0x48) & 0x4) return;
            if (M2C_FIELD(optionSprite, s8 *, MENU_SPRITE_TIMER) >= 0) {
                M2C_FIELD(optionSprite, SpriteFrameBits *, MENU_SPRITE_FRAME).frame = (u16)(baseFrame + 1);
                M2C_FIELD(optionSprite, u8 *, MENU_SPRITE_TIMER) = 12;
            }
            if (M2C_FIELD(menu, u16 *, 0x48) & 0x4) return;
            PlaySoundEffect(0x1000e);
            M2C_FIELD(menu, u16 *, 0x48) |= 0x4;
            Sprite_ResumeAnimation(menu);
        }
    }
}

