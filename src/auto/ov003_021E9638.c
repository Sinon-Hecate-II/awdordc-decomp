/* 28 functions from 0x021E9638 to 0x021EA57C (ov003), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
typedef struct {u8 pad[0x14];void *sprites[12];void *labels[12];void *last;void *main;} SpriteGroup9638;
static inline u8 E9638Mode(void *p, u32 n) { return ((u32)(M2C_FIELD(p,u8*,0x39)<<24)>>28)==n; }
static inline u8 E9638Toggle(void *p) { return ((u32)(M2C_FIELD(p,volatile u8*,0x3a)<<30)>>31)==0; }
static inline u8 E9638IsFF(u8 v) { return v==255; }
static inline u8 E9638Value(void *p) { return M2C_FIELD(p,s32*,0x18); }
#include "coordinate_bits.h"
#include "waypoint_panel.h"

/* Create the waypoint panel's sprites: the panel's main 3D sprite, one sprite
   per waypoint slot (12) and one label sprite per slot plus a trailing label,
   all allocated on the sub engine. */
void CreateWaypointPanelSprites(SpriteGroup9638 *group,void *panel) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub,*g3DSpriteEngineMain;extern u8 data_ov003_0220f896[];
void *CreateFaceSprite(void *);void *Create3DSprite(void *);void func_020990d4(void *,s32,u16);void SetFaceSpriteActive(void *,s32);void Hide3DSprite(void *);s32 GetFaceLayoutSize(s32);void SetFaceSpritePose(void *,s32,s32,s32);
void *savedEngine=gCur3DSpriteEngine;s32 slot;
gCur3DSpriteEngine=g3DSpriteEngineSub;
group->main=CreateFaceSprite(panel);
func_020990d4(group->main,0x4400,1);
SetFaceSpriteActive(group->main,1);
M2C_FIELD(group->main,u16 *,0x3c)=0x400;
Hide3DSprite(group->main);
gCur3DSpriteEngine=g3DSpriteEngineMain;
for(slot=0;slot<12;slot++){
group->sprites[slot]=CreateFaceSprite(panel);
func_020990d4(group->sprites[slot],0x5c00+slot*2*GetFaceLayoutSize(0),(u16)slot);
SetFaceSpritePose(group->sprites[slot],slot+1,0,0);
SetFaceSpriteActive(group->sprites[slot],1);
M2C_FIELD(group->sprites[slot],u16 *,0x3c)=0x400;
Hide3DSprite(group->sprites[slot]);
group->labels[slot]=Create3DSprite(panel);
M2C_FIELD(group->labels[slot],void **,0x44)=data_ov003_0220f896;
M2C_FIELD(group->labels[slot],u16 *,0x3e)=0x540;
M2C_FIELD(group->labels[slot],u16 *,0x3c)=0x800;
Hide3DSprite(group->labels[slot]);
}
group->last=Create3DSprite(panel);
M2C_FIELD(group->last,void **,0x44)=data_ov003_0220f896;
M2C_FIELD(group->last,u16 *,0x3e)=0x560;
M2C_FIELD(group->last,u16 *,0x3c)=0x800;
Hide3DSprite(group->last);
gCur3DSpriteEngine=savedEngine;
}

/* Move the 3D sprite actor `sprite` to (x, y) and give it a width x height size. */
void SetSpriteActorPositionAndSize(void *sprite, s16 x, s16 y, s32 width, s32 height) {
    SetSpriteActorRect(sprite, x, y, width, height);
}

void func_ov003_021e97fc(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x58) = arg1;
}

void func_ov003_021e9804(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x59) = 0;
}

void func_ov003_021e9810(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x3E) = arg1;
}

void func_ov003_021e9818(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (arg1 << 0x18) >> 6));
}

void func_ov003_021e9830(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0xE) = arg1;
    M2C_FIELD(arg0, s16 *, 0x10) = arg1;
    M2C_FIELD(arg0, s16 *, 0xC) = 0;
    M2C_FIELD(arg0, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 4);
}

#pragma opt_common_subs off
/* Switch the waypoint panel between its wide layout (all four player columns
 * visible, background strips spread out) and its compact one: store the layout
 * in the panel flags, show or hide the player-select sprites, retarget the three
 * strip tweens, re-lay the slot list, then move the target cursor onto the
 * selected unit and pick the description text for the selected slot. */
void SetWaypointPanelMode(void *panel, s32 layout)
{
  void Show3DSprite(void *);
  void Hide3DSprite(void *);
  s32 Show3DSpriteSlide(s32);
  s32 Hide3DSpriteSlide(s32);
  u32 SetTextById(s32, s32);
  s16 GetSpriteAnimValue(void *);
  s32 GetUnitSpriteWidth(void *);
  s32 GetUnitSpriteHeight(void *);
  u32 InRange(u8, M2C_UNK, M2C_UNK);
  s32 IsSessionGuest();
  void SetWaypointListLayout(void *, s32);
  s16 GetWaypointSlotX(u8);
  s32 IsLinkSessionActive();
  typedef struct
  {
    s32 slide;          /* +0x00 first player-select slide */
    s32 slideAlt;       /* +0x04 second player-select slide */
    void *tile[4];      /* +0x08 first sprite of each player column */
    void *tileAlt[4];   /* +0x18 second sprite of each player column */
  } WaypointSelectSprites;
  WaypointSelectSprites *selectSprites;
  WaypointSelectSprites *hiddenSprites;
  u32 flags;
  u32 width;
  s32 height;
  s32 isWide;
  s32 isCompact;
  u32 wide;
  u32 compact;
  u8 selectedSlot;
  u32 textEnabled;
  u32 layoutNow;
  u8 slotCount;
  s8 count;
  u8 slot;
  u8 hideSlot;
  s8 *panelBytes;
  void *unit;
  SpriteTween *strip;

  flags = (M2C_FIELD(panel, u8 *, WAYPOINT_PANEL_FLAGS) = ((M2C_FIELD(panel, u8 *, WAYPOINT_PANEL_FLAGS) & (~WAYPOINT_PANEL_LAYOUT_MASK)) | ((((u32) ((u8) layout)) << 0x1E) >> 0x1C)));
  if ((((u32) (((u8) flags) << 0x1C)) >> 0x1E) == 0)
  {
    isWide = 1;
  }
  else
  {
    isWide = 0;
  }
  if ((isWide & 0xFF) && (IsSessionGuest() != 0))
  {
    Show3DSprite(M2C_FIELD(panel, void **, WAYPOINT_PANEL_CURSOR));
    Show3DSpriteSlide(M2C_FIELD(panel, WaypointSelectSprites **, WAYPOINT_PANEL_SELECT_SPRITES)->slide);
  }
  selectSprites = M2C_FIELD(panel, WaypointSelectSprites **, WAYPOINT_PANEL_SELECT_SPRITES);
  count = (s32) (M2C_FIELD(M2C_FIELD(panel, void **, WAYPOINT_PANEL_LIST), s8 *, WAYPOINT_LIST_COUNT));
  slotCount = count & 0xffU;
  if (IsLinkSessionActive() == 0)
  {
    slot = 0;
    do
    {
      if (slot < slotCount)
      {
        Show3DSprite(selectSprites->tile[slot]);
        Show3DSprite(selectSprites->tileAlt[slot]);
      }
      slot = (u32) ((u8) (slot + 1));
    }
    while (slot < 4U);
  }
  strip = M2C_FIELD(panel, SpriteTween **, WAYPOINT_PANEL_STRIP_A);
  strip->from = GetSpriteAnimValue(strip);
  strip->to = 0;
  strip->duration = 0xC;
  strip->current = strip->start;
  panelBytes = (s8 *) panel;
  strip = M2C_FIELD(panelBytes, SpriteTween **, WAYPOINT_PANEL_STRIP_B);
  strip->from = GetSpriteAnimValue(strip);
  strip->to = 0x100;
  strip->duration = 0xC;
  strip->current = strip->start;
  strip = M2C_FIELD(panelBytes, SpriteTween **, WAYPOINT_PANEL_STRIP_C);
  strip->from = GetSpriteAnimValue(strip);
  strip->to = 0xC0;
  strip->duration = 0xC;
  strip->current = strip->start;
  if ((((u32) ((M2C_FIELD(panelBytes, u8 *, WAYPOINT_PANEL_FLAGS)) << 0x1C)) >> 0x1E) == 1)
  {
    isCompact = 1;
  }
  else
  {
    isCompact = 0;
  }
  if (isCompact & 0xFF)
  {
    if (IsSessionGuest() != 0)
    {
      Hide3DSprite(M2C_FIELD(panelBytes, void **, WAYPOINT_PANEL_CURSOR));
      Hide3DSpriteSlide(M2C_FIELD(panel, WaypointSelectSprites **, WAYPOINT_PANEL_SELECT_SPRITES)->slide);
    }
    hiddenSprites = M2C_FIELD(panel, WaypointSelectSprites **, WAYPOINT_PANEL_SELECT_SPRITES);
    hideSlot = 0;
    do
    {
      Hide3DSprite(hiddenSprites->tile[hideSlot]);
      Hide3DSprite(hiddenSprites->tileAlt[hideSlot]);
      hideSlot += 1;
    }
    while (((u32) hideSlot) < 4U);
    strip = M2C_FIELD(panel, SpriteTween **, WAYPOINT_PANEL_STRIP_A);
    strip->from = GetSpriteAnimValue(strip);
    strip->to = -0x100;
    strip->duration = 0xC;
    strip->current = strip->start;
    strip = M2C_FIELD(panel, SpriteTween **, WAYPOINT_PANEL_STRIP_B);
    strip->from = GetSpriteAnimValue(strip);
    strip->to = 0;
    strip->duration = 0xC;
    strip->current = strip->start;
    strip = M2C_FIELD(panelBytes, SpriteTween **, WAYPOINT_PANEL_STRIP_C);
    strip->from = GetSpriteAnimValue(strip);
    strip->to = 0x5E;
    strip->duration = 0xC;
    strip->current = strip->start;
  }
  SetWaypointListLayout(M2C_FIELD(panel, void **, WAYPOINT_PANEL_LIST), layout);
  unit = M2C_FIELD(M2C_FIELD(panelBytes, void **, WAYPOINT_PANEL_LIST), void **, WAYPOINT_LIST_UNIT);
  height = GetUnitSpriteHeight(unit);
  width = GetUnitSpriteWidth(unit);
  SetSpriteActorRect(M2C_FIELD(panel, void **, WAYPOINT_PANEL_CURSOR), M2C_FIELD(unit, s16 *, 0x34), M2C_FIELD(unit, s16 *, 0x36), width, height);
  M2C_FIELD(M2C_FIELD(panel, void **, WAYPOINT_PANEL_MARKER), s16 *, 0x34) = GetWaypointSlotX(M2C_FIELD(M2C_FIELD(panel, void **, WAYPOINT_PANEL_LIST), u8 *, WAYPOINT_LIST_SELECTED));
  textEnabled = ((u32) ((M2C_FIELD(panelBytes, u8 *, WAYPOINT_PANEL_TEXT_ENABLED)) << 0x1F)) >> 0x1F;
  if (textEnabled == 0)
  {
    return;
  }
  selectedSlot = M2C_FIELD(M2C_FIELD(M2C_FIELD(panelBytes, void **, WAYPOINT_PANEL_LIST), void **, WAYPOINT_LIST_UNIT), u16 *, 0x2E);
  if (InRange(selectedSlot, 0, 3) != 0)
  {
    SetTextById(M2C_FIELD(panelBytes, s32 *, WAYPOINT_PANEL_TEXT), WAYPOINT_TEXT_SLOTS_0_TO_3);
    return;
  }
  if (InRange(selectedSlot, 4, 7) != 0)
  {
    SetTextById(M2C_FIELD(panelBytes, s32 *, WAYPOINT_PANEL_TEXT), WAYPOINT_TEXT_SLOTS_4_TO_7);
    return;
  }
  if (InRange(selectedSlot, 8, 0x14) != 0)
  {
    SetTextById(M2C_FIELD(panelBytes, s32 *, WAYPOINT_PANEL_TEXT), WAYPOINT_TEXT_SLOTS_8_TO_20);
    return;
  }
  if (InRange(selectedSlot, 0x15, 0x18) != 0)
  {
    SetTextById(M2C_FIELD(panelBytes, s32 *, WAYPOINT_PANEL_TEXT), WAYPOINT_TEXT_SLOTS_21_TO_24);
    return;
  }
  if (selectedSlot != 0x19)
  {
    return;
  }
  layoutNow = ((u32) ((M2C_FIELD(panel, u8 *, WAYPOINT_PANEL_FLAGS)) << 0x1C)) >> 0x1E;
  if (layoutNow == 0)
  {
    wide = 1;
  }
  else
  {
    wide = 0;
  }
  if (wide & 0xFF)
  {
    SetTextById(M2C_FIELD(panelBytes, s32 *, WAYPOINT_PANEL_TEXT), WAYPOINT_TEXT_CONFIRM_WIDE);
    return;
  }
  if (layoutNow == 1)
  {
    compact = 1;
  }
  else
  {
    compact = 0;
  }
  if (!(compact & 0xFF))
  {
    return;
  }
  SetTextById(M2C_FIELD(panelBytes, s32 *, WAYPOINT_PANEL_TEXT), WAYPOINT_TEXT_CONFIRM_COMPACT);
}
#pragma opt_common_subs reset
u8 func_ov003_021e9c08(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s8 func_ov003_021e9c24(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x6C), s8 *, 4);
}

u8 func_ov003_021e9c30(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1C) >> 0x1E) == 1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Place the waypoint panel's target cursor over the selected slot's unit, sized
 * to that unit's sprite, and the slot marker at the selected slot's column. */
void PlaceWaypointPanelCursor(void *panel) {
 s32 GetUnitSpriteWidth(void *); s32 GetUnitSpriteHeight(void *); s16 GetWaypointSlotX(u8);
 void *unit; s32 width,height;
 unit = M2C_FIELD(M2C_FIELD(panel, void **, WAYPOINT_PANEL_LIST), void **, WAYPOINT_LIST_UNIT);
 height = GetUnitSpriteHeight(unit); width = GetUnitSpriteWidth(unit);
 SetSpriteActorRect(M2C_FIELD(panel, void **, WAYPOINT_PANEL_CURSOR), M2C_FIELD(unit, s16 *, SPRITE_ACTOR_X), M2C_FIELD(unit, s16 *, SPRITE_ACTOR_Y), width, height);
 M2C_FIELD(M2C_FIELD(panel, void **, WAYPOINT_PANEL_MARKER), s16 *, SPRITE_ACTOR_X) = GetWaypointSlotX(M2C_FIELD(M2C_FIELD(panel, void **, WAYPOINT_PANEL_LIST), u8 *, WAYPOINT_LIST_SELECTED));
}

u8 func_ov003_021e9cd0(void *arg0) {
    return (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 0xE0), u16 *, 0x2E);
}

u8 func_ov003_021e9ce0(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x1F) >> 0x1F) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Switches the waypoint panel to a state (0 idle, 1..3 animations): stores the
 * state nibble and panel flags, enables the panel's own sprite layer in state 1
 * and shows or hides the trailing label sprite depending on the state. */
void SetWaypointPanelState(void *panel,s32 state){
extern void *gCur3DSpriteEngine; extern void *g3DSpriteEngineMain;
void Ov003_SetPanelPlayerFlagTile(s32,u8); void Sync3DSpriteToTarget(void*); void Show3DSprite(void*); void Hide3DSprite(void*);
void *savedEngine;
M2C_FIELD(panel,u8*,0x39)=(M2C_FIELD(panel,u8*,0x39)&~0xf0)|((u32)((u8)state<<28)>>24);
M2C_FIELD(panel,u8*,0x3a)=(M2C_FIELD(panel,u8*,0x3a)&~0x70)|0x10;
if(E9638Mode(panel,1)){
savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
Ov003_SetPanelPlayerFlagTile(25,M2C_FIELD(M2C_FIELD(panel,void**,0x6c),u8*,7));
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=16;gCur3DSpriteEngine=savedEngine;
}
if(E9638Mode(panel,1)||E9638Mode(panel,3))M2C_FIELD(M2C_FIELD(panel,void**,0x58),u8*,0x59)=0;
else M2C_FIELD(M2C_FIELD(panel,void**,0x58),u8*,0x59)=1;
if(E9638Mode(panel,2)){
void *waypoints=M2C_FIELD(panel,void**,0x6c);M2C_FIELD(waypoints,u8*,9)=M2C_FIELD(waypoints,u8*,8);
Sync3DSpriteToTarget(M2C_FIELD(panel,void**,0x5c));Show3DSprite(M2C_FIELD(panel,void**,0x5c));
}else Hide3DSprite(M2C_FIELD(panel,void**,0x5c));
}

u8 func_ov003_021e9e2c(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 3) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021e9e4c(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x59) = 1;
}

u8 func_ov003_021e9e58(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 2) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Reset the waypoint panel's slot/option transition state to the selected slot
 * and option: all three keyframe pairs take those values, the transition counters
 * restart from zero, both amplitudes are 0xA0 and the state is marked ready. */
void InitWaypointOptionState(void *state, s8 slot, s8 option) {
    M2C_FIELD(state, s8 *, 0x10) = slot;
    M2C_FIELD(state, s8 *, 0x11) = option;
    M2C_FIELD(state, s8 *, 0xE) = slot;
    M2C_FIELD(state, s8 *, 0xF) = option;
    M2C_FIELD(state, s8 *, 0xC) = slot;
    M2C_FIELD(state, s8 *, 0xD) = option;
    M2C_FIELD(state, s16 *, 4) = 0;
    M2C_FIELD(state, s16 *, 6) = 0;
    M2C_FIELD(state, s16 *, 8) = 0xA0;
    M2C_FIELD(state, s16 *, 0xA) = 0xA0;
    M2C_FIELD(state, s8 *, 0x12) = 1;
}

#pragma optimization_level 3
void func_ov003_021e9eb4(void *p) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
s32 Modulo(s32,s32); s16 GetWaypointSlotOffsetX(s32); s32 GetWaypointOptionCoId(u8);
void ClearTileRect(void*,s32,s32); void FillFaceTileMap(u32,s32,s32,s32,u32,u16,u8); void LoadFacePalette(s32,s32,s32,s32,u8);
u8 i; void *old,*saved; u8 a; s8 c;
for(i=0;i<M2C_FIELD(M2C_FIELD(p,void**,0x6c),s8*,4);i++){
    s32 b;
old=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
a=(Modulo(i,2)!=0);
if(i>=2)b=(s32)(((u32)GetWaypointSlotOffsetX(2)<<16)>>3)>>16;
else b=0;
c=(s8)GetWaypointOptionCoId(M2C_FIELD((u8*)M2C_FIELD(p,void**,0x6c)+i,u8*,0xa));
if(c==0){
ClearTileRect((void*)((u8*)M2C_FIELD((u8*)gCur3DSpriteEngine+a*4,void**,0x20)+(b+1)*2),7,7);
}else{
FillFaceTileMap(1,b,0,(s32)M2C_FIELD((u8*)gCur3DSpriteEngine+a*4,void**,0x20)+2,((u32)((((s8)(c-1))<<7)+2)<<15>>16),i,0);
}
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=1<<a;
gCur3DSpriteEngine=old;
}
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
for(i=0;i<M2C_FIELD(M2C_FIELD(p,void**,0x6c),s8*,4);i++){
a=(Modulo(i,2)!=0);
if(i>=2)GetWaypointSlotOffsetX(2);
c=(s8)GetWaypointOptionCoId(M2C_FIELD((u8*)M2C_FIELD(p,void**,0x6c)+i,u8*,0xa));
if(i==M2C_FIELD(M2C_FIELD(p,void**,0x6c),u8*,7)||!E9638Mode(p,2)){
if(c)LoadFacePalette(c,1,a,i,0);
}else{
if(c)LoadFacePalette(c,1,a,i,1);
}
}
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=1;
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
gCur3DSpriteEngine=saved;
M2C_FIELD(p,u8*,0x3a)&=~0x70;
M2C_FIELD(p,u8*,0x3a)&=~0x8;
}
#pragma optimization_level reset
void func_ov003_021ea134(s32 arg0) {
    extern void *gCur3DSpriteEngine;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | (1 << arg0));
}

/* Draw the selected waypoint option's icon and description on the sub engine,
 * then flip the text palette colour for the next frame. */
void DrawWaypointOption(void *p){
extern void *gCur3DSpriteEngine; extern void *g3DSpriteEngineSub;
void Clear3DSpriteLayer(s32); s32 GetWaypointOptionCoId(u8); void Hide3DSprite(void*); void Show3DSprite(void*); void SetFaceSpritePose(void*,s32,s32,s32); void *GetWaypointOptionTextId(s32); void *GetLocalizedText(void*); void DrawTextLine(s32,s32,s32,void*,s32,u16);
void *savedEngine; s8 optionIndex,iconIndex; u8 paletteBit;
savedEngine=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
Clear3DSpriteLayer(3);
optionIndex=M2C_FIELD(M2C_FIELD(p,void**,0x40),s8*,15);
iconIndex=GetWaypointOptionCoId((u8)optionIndex);
if(!iconIndex)Hide3DSprite(M2C_FIELD(M2C_FIELD(p,void**,0x68),void**,0x78));
else {
if(((u32)(M2C_FIELD(p,u8*,0x3a)<<31)>>31))Show3DSprite(M2C_FIELD(M2C_FIELD(p,void**,0x68),void**,0x78));
SetFaceSpritePose(M2C_FIELD(M2C_FIELD(p,void**,0x68),void**,0x78),iconIndex,8,0);
DrawTextLine(1,8,3,GetLocalizedText(GetWaypointOptionTextId(optionIndex)),0x2000,(u16)(1+224*((u32)(M2C_FIELD(p,u8*,0x3a)<<30)>>31)));
}
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=8;gCur3DSpriteEngine=savedEngine;
paletteBit=E9638Toggle(p);
M2C_FIELD(p,u8*,0x3a)=(M2C_FIELD(p,u8*,0x3a)&~2)|((u32)(paletteBit<<31)>>30);
}

void func_ov003_021ea27c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK LoadSpriteResource(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    LoadSpriteResource(arg0, 0, arg1, arg2);
}

void func_ov003_021ea294(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    LoadSpriteResource(arg0, 2, arg1, arg2);
}

/* Reset the display state of the current 3D sprite engine's bank: clear the
 * OBJ priority bits so the sprite draws on top, un-split the cell grid and
 * clear the display blend. */
void Reset3DSpriteBankDisplay(void) {
    extern void *gCur3DSpriteEngine;
    u16 *volatile oamAttr;
    oamAttr = (u16 *)((s8 *)M2C_FIELD(gCur3DSpriteEngine, void **, 0) + DS3D_BANK_OAMATTR);
    *oamAttr = (u16)(*oamAttr & ~DS3D_BANK_OAMATTR_PRIORITY);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_ROWS_ABOVE) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_ROWS_BELOW) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u8 *, DS3D_BANK_BLEND) = 0;
}

/* Link (overlay 9/10) side of the wireframe/cutscene sync: mark the local side
 * flag when the active player kind is 2, hand the overlay the current slots,
 * mark the record ready (and clear its second half) when this is the first slot,
 * spend the rest of the frame stepping slot turns, then finish with the
 * overlay's post-sync hook. */
void Ov003_SyncLinkSlots(void *p) {
s32 func_020cfb94(void); s32 Link_ReceivePacket(void*,s32); void Link_SendPacket(void*,s32); void Link_FlushSend(void); void Sprite_ResumeAnimation(void*); s32 GetSessionPlayerCount(void); s32 GetSceneEntryOffset(void);
u32 buf[9]; u8 flag, n, start;
if(func_020cfb94()==2) M2C_FIELD(p,u8*,0x39)=(M2C_FIELD(p,u8*,0x39)&~1)|1;
if(!Link_ReceivePacket(buf,0x24))return;
flag=(((u32)(M2C_FIELD(p,u8*,0x39)<<31)>>31)==0);
if(flag && GetSceneEntryOffset()==-256) M2C_FIELD(buf,u8*,8)=1;
else {M2C_FIELD(buf,u8*,8)=0;buf[6]=0;}
buf[0]=0;buf[1]=0;
start=GetSessionPlayerCount(); n=0;
if(func_020cfb94()-start>0)do{n++;}while(n<func_020cfb94()-start);
Link_SendPacket(buf,0x24);Link_FlushSend();Sprite_ResumeAnimation(p);
}

/* Refreshes the waypoint panel's per-player ready flags from the link player
 * records, silently: retracts the two player-select slides, then for every slot in
 * use looks the slot's player record up (an empty slot shows the first slot's
 * player) and records whether its data has arrived. */
void WaypointPanel_RefreshPlayerReady(void *panel) {
 void *GetNetworkPlayerRecord(u8);
 M2C_UNK Hide3DSpriteSlide(s32);
 s32 temp_r2,var_r1;
 u8 var_r0,var_r8;
 void *temp_r0,*temp_r1,*temp_r4;
 temp_r4=M2C_FIELD(panel,void**,WAYPOINT_PANEL_SELECT_SPRITES);
 Hide3DSpriteSlide(M2C_FIELD(temp_r4,s32*,0));
 Hide3DSpriteSlide(M2C_FIELD(temp_r4,s32*,4));
 var_r8=0;
 if(M2C_FIELD(M2C_FIELD(panel,void**,WAYPOINT_PANEL_LIST),s8*,WAYPOINT_LIST_COUNT)<=0)return;
 do {
 var_r0=M2C_FIELD((u8*)M2C_FIELD(panel,void**,WAYPOINT_PANEL_LIST)+var_r8,u8*,WAYPOINT_LIST_IDS);
 var_r1=E9638IsFF(var_r0);
 if(var_r1)var_r0=M2C_FIELD(M2C_FIELD(panel,void**,WAYPOINT_PANEL_LIST),u8*,WAYPOINT_LIST_IDS);
 temp_r0=GetNetworkPlayerRecord(var_r0);
 if(temp_r0==0)return;
 temp_r2=E9638Value(temp_r0);
 temp_r1=(u8*)M2C_FIELD(panel,void**,WAYPOINT_PANEL_GROUP)+var_r8;
 if(M2C_FIELD(temp_r1,u8*,WAYPOINT_GROUP_READY)!=0) {
 if(temp_r2==0)M2C_FIELD(temp_r1,u8*,WAYPOINT_GROUP_READY)=0;
 }else if(temp_r2!=0)M2C_FIELD(temp_r1,u8*,WAYPOINT_GROUP_READY)=1;
 var_r8++;
 }while(var_r8<M2C_FIELD(M2C_FIELD(panel,void**,WAYPOINT_PANEL_LIST),s8*,WAYPOINT_LIST_COUNT));
}

#pragma opt_loop_invariants off
void func_ov003_021ea4a8(void *arg0,s32 arg1){
void *func_02084e24(u8);M2C_UNK func_0208fe30(s32);
s32 temp_r2,var_r1;u8 var_r0,var_r7;void *temp_r0,*temp_r8;
var_r7=0;
if(M2C_FIELD(M2C_FIELD(arg0,void**,0x6c),s8*,4)<=0)return;
do{
var_r0=M2C_FIELD((u8*)M2C_FIELD(arg0,void**,0x6c)+var_r7,u8*,0x74);
var_r1=E9638IsFF(var_r0);
if(var_r1)var_r0=M2C_FIELD(M2C_FIELD(arg0,void**,0x6c),u8*,0x74);
temp_r0=func_02084e24(var_r0);if(!temp_r0)return;
temp_r2=E9638Value(temp_r0);
temp_r8=(u8*)M2C_FIELD(arg0,void**,0x68)+var_r7;
if(M2C_FIELD(temp_r8,u8*,0x7c)){
if(!temp_r2){if(arg1)func_0208fe30(0x1000f);M2C_FIELD(temp_r8,u8*,0x7c)=0;}
}else if(temp_r2){if(arg1)func_0208fe30(0x1000d);M2C_FIELD(temp_r8,u8*,0x7c)=1;}
var_r7++;
}while(var_r7<M2C_FIELD(M2C_FIELD(arg0,void**,0x6c),s8*,4));
}
#pragma opt_loop_invariants reset
