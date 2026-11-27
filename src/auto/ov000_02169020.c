/* 44 functions from 0x02169020 to 0x02169F94 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
#include "ov000_unit_move.h"

extern s32 *gCurrentMap;

static inline s8 ReadMovementCommand(void *p) {
    return ((s8 *)p + 0x58)[M2C_FIELD(p,u8*,0x40)++];
}

/* Unit-move state handler (UNIT_MOVE_STATE_WAIT_ATTACK): once the attack effect
 * on the unit's cell has finished, go back to holding for the step timer. */
void UnitMove_WaitForAttack(void *move) {
    s32 IsMapActionEffectActive();
    if (IsMapActionEffectActive() == 0) {
        M2C_FIELD(move, u8 *, UNIT_MOVE_STATE) = UNIT_MOVE_STATE_HOLD;
    }
}

/* Unit-move state handler for UNIT_MOVE_STATE_WAIT_SCROLL: once the map view has
 * stopped scrolling, go back to walking to the next tile. */
void UnitMove_WaitForScroll(void *move) {
    s32 IsMapViewScrolling();
    if (IsMapViewScrolling() == 0) {
        M2C_FIELD(move, u8 *, UNIT_MOVE_STATE) = UNIT_MOVE_STATE_WALK;
    }
}

void func_ov000_02169058(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0x48) = (u16) (M2C_FIELD(arg0, u16 *, 0x48) - 1);
}

void func_ov000_02169068(void) {

}

void func_ov000_0216906c(void) {

}

#pragma peephole off
void func_ov000_02169070(void *p) {
 extern s16 data_ov000_021ae960[];
 u16 t;
 s8 direction;
 M2C_FIELD(p,u16 *,0x48)+=M2C_FIELD(p,s16 *,0x4a);
 M2C_FIELD(p,s16 *,0x4c)+=M2C_FIELD(p,s16 *,0x4a)*data_ov000_021ae960[M2C_FIELD(p,s8 *,0x44)*2];
 M2C_FIELD(p,s16 *,0x4e)+=M2C_FIELD(p,s16 *,0x4a)*data_ov000_021ae960[M2C_FIELD(p,s8 *,0x44)*2+1];
 t=M2C_FIELD(p,u16 *,0x48);
 if(t<16)return;
 M2C_FIELD(p,u16 *,0x48)=t-16;
 direction=M2C_FIELD(p,s8 *,0x44);
 M2C_FIELD(p,s16 *,0x4c)-=M2C_FIELD(p,u16 *,0x48)*data_ov000_021ae960[direction*2];
 M2C_FIELD(p,s16 *,0x4e)-=M2C_FIELD(p,u16 *,0x48)*data_ov000_021ae960[M2C_FIELD(p,s8 *,0x44)*2+1];
 M2C_FIELD(p,u16 *,0x48)=0;
}
#pragma peephole reset
/* Read movement commands from the controller's stream until one changes its state:
   a MOVE_DIR_* step sets the facing and walks on, 5..8 face a direction without
   animating, 9 holds for the frames the next byte gives, MOVE_DIR_ATTACK fires at
   the unit's cell, MOVE_DIR_STOP finishes the move and MOVE_DIR_NONE deletes it. */
void UnitMove_ReadCommand(void *move) {
void func_020c98d8(s32,s32,s32);
s32 IsPlayerHuman(u32);
void AddRecordValue(s32,s32);
void UnitMove_Stop(void *);
void DeleteUnitMoveObject(void *);
void RefreshMapView(void);
void StepUnitMoveSound(void *);
void SetSpriteAnimFrame(s32,s32);
extern s32 *gCurrentMap;
s8 ReadMovementCommand(void *);
s16 command;
for (;;) {
command=ReadMovementCommand(move);
switch(command){
default: continue;
case 9:
M2C_FIELD(move,s16*,UNIT_MOVE_PHASE)=ReadMovementCommand(move);
M2C_FIELD(move,u8*,UNIT_MOVE_STATE)=UNIT_MOVE_STATE_HOLD;return;
case MOVE_DIR_ATTACK:
M2C_FIELD(move,u8*,UNIT_MOVE_STATE)=UNIT_MOVE_STATE_WAIT_ATTACK;
func_020c98d8(M2C_FIELD(move,s16*,UNIT_MOVE_X)>>4,M2C_FIELD(move,s16*,UNIT_MOVE_Y)>>4,0);
if(IsPlayerHuman(M2C_FIELD((void*)*gCurrentMap,u16*,MAP_CURRENT_PLAYER)))AddRecordValue(14,1);
return;
case MOVE_DIR_STOP:UnitMove_Stop(move);return;
case MOVE_DIR_NONE:DeleteUnitMoveObject(move);RefreshMapView();return;
case MOVE_DIR_LEFT:case MOVE_DIR_RIGHT:case MOVE_DIR_DOWN:case MOVE_DIR_UP:
StepUnitMoveSound(move);
if(command!=M2C_FIELD(move,s8*,UNIT_MOVE_DIRECTION)){
SetSpriteAnimFrame(M2C_FIELD(move,s32*,UNIT_MOVE_SPRITE),command);
SetSpriteAnimFrame(M2C_FIELD(move,s32*,UNIT_MOVE_SPRITE2),command+4);
M2C_FIELD(move,s8*,UNIT_MOVE_DIRECTION)=command;M2C_FIELD(move,u8*,UNIT_MOVE_STATE)=UNIT_MOVE_STATE_WALK;
}return;
case 5:case 6:case 7:case 8:
command-=5;
if(command!=M2C_FIELD(move,s8*,UNIT_MOVE_DIRECTION)){
SetSpriteAnimFrame(M2C_FIELD(move,s32*,UNIT_MOVE_SPRITE),command);
SetSpriteAnimFrame(M2C_FIELD(move,s32*,UNIT_MOVE_SPRITE2),command+4);
M2C_FIELD(move,s8*,UNIT_MOVE_DIRECTION)=command;
}continue;
}
}
}
#pragma optimization_level reset
void func_ov000_021692a8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s8 *, 0x41) = 1;
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
}

/* Per-frame update of a unit-move controller (its class's update callback):
 * with the step timer elapsed while walking (state 2) or holding (state 3) it
 * reads the next movement command from the stream, runs the current state's
 * handler, and redraws the moving unit when it may enter the cell it is over. */
void UnitMove_Update(void *move) {
    void UnitMove_ReadCommand(void *);
    s32 UnitMove_CanStepOntoCell(void *);
    void DrawUnitMoveSprite(void *);
    extern void (*gUnitMoveStateHandlers[])(void *);
    u32 state=M2C_FIELD(move,u8 *,UNIT_MOVE_STATE);
    if(state!=0) {
        if((u8)(state+0xFE)<=1 && M2C_FIELD(move,u16 *,UNIT_MOVE_PHASE)==0) {
            UnitMove_ReadCommand(move);
            if(M2C_FIELD(move,s32 *,DS3D_SPRITE_ALIVE)==0)return;
        }
        gUnitMoveStateHandlers[M2C_FIELD(move,u8 *,UNIT_MOVE_STATE)](move);
    }
    if(UnitMove_CanStepOntoCell(move))DrawUnitMoveSprite(move);
}

/* Destructor callback of the unit-move controller class: play the unit's move
 * sound, release its sprites and graphics buffers, and clear its slot in the
 * map's unit-move pool so the slot can be reused. */
void UnitMove_Destroy(void *move) {
    extern s32 *gCurrentMap;
    void UnitMove_FreeGraphics(void *);

    PlayUnitMoveSound(move);
    UnitMove_FreeGraphics(move);
    M2C_FIELD(gCurrentMap, u8 **, MAP_UNIT_MOVE_SLOTS)[M2C_FIELD(move, s8 *, UNIT_MOVE_SLOT)] = 0;
}

/* Clear the pool of active unit-move controllers (the map's third block pointer):
 * mark every slot of it as free. */
void ClearUnitMoveSlots(void) {
    u16 i = 0;
    u8 *slots;

    do {
        slots = M2C_FIELD(gCurrentMap, u8 **, MAP_UNIT_MOVE_SLOTS);
        slots[i] = 0;
        i++;
    } while (i < UNIT_MOVE_SLOT_COUNT);
}

void *CreateUnitMoveAt(s32,s32,s32,s32);
/* Attach a unit-move controller to an existing map unit: flag the unit as drawn
   by the controller, create the controller at the unit's tile with its owner and
   kind, remember the unit record in it and return the controller (NULL when no
   slot is free). */
void *CreateUnitMoveForUnit(u8 *unit) {
    void *CreateUnitMoveAt(s32, s32, s32, s32);
    extern s32 *gCurrentMap;
    s32 unitIndex;
    void *move;

    M2C_FIELD(unit, u16 *, MAP_UNIT_FLAGS) |= UNIT_MOVE_UNIT_FLAGS;
    if (!unit) unitIndex = 0;
    else unitIndex = ((s32)unit - (s32)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE;
    move = CreateUnitMoveAt(unit[MAP_UNIT_X], unit[MAP_UNIT_Y],
                            (unitIndex >> MAP_UNIT_OWNER_SHIFT) + 1,
                            (u32)(unit[MAP_UNIT_KIND] << 26) >> 26);
    if (!move) return 0;
    M2C_FIELD(move, void **, UNIT_MOVE_UNIT) = unit;
    return move;
}

/* Create the controller that walks a map unit along a movement path: claim a
 * free slot in the map's move pool, create its sprite object in the unit layer
 * and fill in the slot, 1/16-tile position, kind, owner, facing and movement
 * speed, then build the two sprites.  Returns 0 when no slot is free. */
void *CreateUnitMove(s32 x,s32 y,s32 owner,s32 kind,s32 direction) {
 s32 FindFreeUnitMoveSlot(void);
 void *CreateSpriteFromClass(M2C_UNK *,s32);
 s32 GetUnitMoveSpeed(void *);
 void InitUnitMoveSprites(void *);
 extern M2C_UNK gUnitMoveClass;
 void *p;
 s32 slot=FindFreeUnitMoveSlot();
 if(slot==-1)return 0;
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,MAP_UNIT_MOVE_SLOTS),u8 *,slot)=1;
 p=CreateSpriteFromClass(&gUnitMoveClass,UNIT_MOVE_SPRITE_LAYER);
 M2C_FIELD(p,u8 *,UNIT_MOVE_SLOT)=slot;
 M2C_FIELD(p,u16 *,UNIT_MOVE_X)=x<<4;
 M2C_FIELD(p,u16 *,UNIT_MOVE_Y)=y<<4;
 M2C_FIELD(p,u8 *,UNIT_MOVE_KIND)=kind;
 M2C_FIELD(p,u8 *,UNIT_MOVE_OWNER)=owner;
 M2C_FIELD(p,u8 *,UNIT_MOVE_DIRECTION)=direction;
 M2C_FIELD(p,u16 *,UNIT_MOVE_SPEED)=GetUnitMoveSpeed(p);
 InitUnitMoveSprites(p);
 return p;
}

/* Create a unit-move controller at tile (tileX, tileY) for a unit of `owner` and
 * unit `kind`, starting in the direction the owner's units face. */
void *CreateUnitMoveAt(s32 tileX, s32 tileY, s32 owner, s32 kind) {
    void *CreateUnitMove(s32, s32, s32, s32, s32);

    return CreateUnitMove(tileX, tileY, owner, kind, GetPlayerUnitFacing(owner));
}

/* Direction (1 or 0) the player's units start a move facing: 1 when the player's
 * unit sprites are mirrored horizontally (PLAYER_REC_FLIP), 0 otherwise. */
s32 GetPlayerUnitFacing(s32 player) {
    extern s32 *gCurrentMap;
    if (M2C_FIELD(((player * MAP_PLAYER_STRIDE) + *gCurrentMap), u8 *, MAP_PLAYER_STATES + PLAYER_REC_FLIP) != 0) {
        return 1;
    }
    return 0;
}

/* Start the active unit-move controller moving along movement command stream
 * `commands`; does nothing when no unit is being moved. */
void BeginUnitMove(s32 commands) {
    void StartUnitMove(void *, s32);
    extern M2C_UNK gUnitMoveClass;
    void *move = (void *)FindObjectByClass(&gUnitMoveClass);
    if (!move) return;
    StartUnitMove(move, commands);
}

/* Starts moving the controller's unit along the movement command stream
 * `commands`: validates the path, marks the move active, scrolls the view onto
 * the unit, records the distance for a human player, copies the commands into
 * the controller and runs the first step.  The move is cancelled when the battle
 * has ended, the path is blocked, the unit is in the state that forbids moving,
 * or a dialog is up. */
void StartUnitMove(void *move, s32 commands){
s32 IsUnitSubmerged(void *);s32 IsUnitVisibleToTeamB(void *);s32 IsDialogActive(void);void StepMapViewToTile(s32,s32);s32 IsPlayerHuman(u32);void SetUnitMoveActiveFlag(void);
extern u8 gBattleEndState[];
s32 CountMovePathSteps(volatile s8 *);s32 MovePathEndsInAttack(s8 *);int IsMovePathValid(int,int,const signed char *);void CopyMovePath(void *,void *);void StepUnitMove(void);
s8 *path=(s8*)commands;
s32 x=M2C_FIELD(move,s16 *,UNIT_MOVE_X)/16,y=M2C_FIELD(move,s16 *,UNIT_MOVE_Y)/16;u8 ok;
if(CountMovePathSteps(path)==0 && MovePathEndsInAttack(path)==0)return;
M2C_FIELD(move,u8 *,UNIT_MOVE_COMMAND)=0;M2C_FIELD(move,u8 *,UNIT_MOVE_STATE)=4;M2C_FIELD(move,u8 *,UNIT_MOVE_ACTIVE)=1;
if(gBattleEndState[0]){
if(gBattleEndState[0]){if(M2C_FIELD((void*)*gCurrentMap,u16 *,0x52b0)!=19)ok=1;else ok=0;}else ok=0;
if(!(ok&255))M2C_FIELD(move,u8 *,UNIT_MOVE_ACTIVE)=0;
}
if(!IsMovePathValid(x,y,path))M2C_FIELD(move,u8 *,UNIT_MOVE_ACTIVE)=0;
if(M2C_FIELD(move,void **,UNIT_MOVE_UNIT) && IsUnitSubmerged(M2C_FIELD(move,void **,UNIT_MOVE_UNIT)) && !IsUnitVisibleToTeamB(M2C_FIELD(move,void **,UNIT_MOVE_UNIT)))M2C_FIELD(move,u8 *,UNIT_MOVE_ACTIVE)=0;
if(IsDialogActive())M2C_FIELD(move,u8 *,UNIT_MOVE_ACTIVE)=0;
if(M2C_FIELD(move,u8 *,UNIT_MOVE_ACTIVE))StepMapViewToTile(x,y);
if(IsPlayerHuman(M2C_FIELD((void*)*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)))AddRecordValue(15,CountMovePathSteps(path));
CopyMovePath(path,(u8*)move+UNIT_MOVE_COMMANDS);
SetUnitMoveActiveFlag();
((void(*)(void*))StepUnitMove)(move);
}

/* Create a unit-move controller at tile (tileX, tileY) for a unit of `owner` and
 * unit `kind` (a new controller faces the way the owner's units do, see
 * CreateUnitMoveAt), then start it moving along movement command stream
 * `commands`.  Returns the controller, or 0 when no move slot is free. */
void *CreateUnitMoveAndStart(s32 tileX, s32 tileY, s32 owner, s32 kind, s32 commands) {
    void StartUnitMove(void *, s32);
    void *move = CreateUnitMoveAt(tileX, tileY, owner, kind);
    if (!move) return 0;
    StartUnitMove(move, commands);
    return move;
}

/* Destroy every unit-move controller: find the first object of the class, delete
 * it and repeat.  Deleting one unlinks it, so each find returns the next. */
void DeleteAllUnitMoveObjects(void) {
    s32 FindObjectByClass(M2C_UNK *);
    void DeleteUnitMoveObject(void *);
    extern M2C_UNK gUnitMoveClass;
    void *move = (void *)FindObjectByClass(&gUnitMoveClass);
    if (!move) return;
    DeleteUnitMoveObject(move);
    DeleteAllUnitMoveObjects();
}

/* Delete a unit-move controller: clear the moving flag on the unit it walks (if it
 * still has one) and destroy its sprite. */
void DeleteUnitMoveObject(void *move) {
    void DeleteSpriteObject(void *);
    M2C_UNK ClearUnitMoveActiveFlag();
    void *unit = M2C_FIELD(move, void **, UNIT_MOVE_UNIT);
    if (unit) M2C_FIELD(unit, u16 *, MAP_UNIT_FLAGS) &= ~UNIT_MOVE_UNIT_FLAGS;
    DeleteSpriteObject(move);
    ClearUnitMoveActiveFlag();
}

/* Nonzero while a unit-move controller exists (an object of the unit-move
 * sprite class), i.e. a unit is being walked along its path. */
u8 IsUnitMoveControllerActive(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK gUnitMoveClass;
    u8 active;

    if (FindObjectByClass(&gUnitMoveClass) != 0) {
        active = 1;
    } else {
        active = 0;
    }
    return active;
}

/* End of a unit's move (MOVE_DIR_STOP): play the move sound, park the controller
 * in its idle state and clear the map's unit-move-active flag. */
void UnitMove_Stop(void *move) {
    M2C_UNK ClearUnitMoveActiveFlag();
    M2C_UNK PlayUnitMoveSound();
    PlayUnitMoveSound(move);
    M2C_FIELD(move, u8 *, UNIT_MOVE_STATE) = UNIT_MOVE_STATE_IDLE;
    ClearUnitMoveActiveFlag();
}

/* Find a free slot in the map's unit-move pool: the index of the first of its
 * UNIT_MOVE_SLOT_COUNT flagged bytes that is free (0), or -1 when all are taken. */
s32 FindFreeUnitMoveSlot(void) {
    u16 i = 0;
    u8 *slots = M2C_FIELD(gCurrentMap, u8 **, MAP_UNIT_MOVE_SLOTS);
    do {
        if (slots[i] == 0) return (s16)i;
        i++;
    } while (i < UNIT_MOVE_SLOT_COUNT);
    return -1;
}

s32 CountMovePathSteps(volatile s8 *p) {
 s32 count=0;
loop:
 switch(*p++) {
 case 9: p++; break;
 case -1: case 4: case 10: return count;
 case 0: case 1: case 2: case 3: count++; break;
 }
 goto loop;
}

void func_ov000_02169800(void) {

}

void CopyMovePath(void *arg0, void *arg1)
{
  s8 *src = arg0;
  s8 *dst = arg1;
  s8 token;
  loop:
  token = *src;

  if ((token == (-1)) || (token == 4))
  {
    goto end;
  }
  if (token != 9)
  {
    goto normal;
  }
  dst[0] = token;
  {
    s8 next = src[1];
    src += 2;
    dst[1] = next;
    dst += 2;
  }
  goto loop;
  end:
  *dst = *((volatile s8 *)src);
  return;

  normal:
  src++;

  *(dst++) = token;
  goto loop;
}

void func_ov000_02169850(void) {

}

extern u32* D_027E0058;
/* Check a pending movement path to (x,y): every step is valid while the path stays
 * on the current player's reachable-cell bitmap, unless the player's units may cross
 * any terrain.  An own unit on the destination (MOVE_DIR_ATTACK/10) is a valid move. */
int IsMovePathValid(int x,int y,const signed char *cmd) {
u8 *map=(u8 *)*gCurrentMap;
u32 pos;
if(*(u8 *)(map+*(u16 *)(map+MAP_CURRENT_PLAYER)*140+0x67c3)&2)return 1;
for(;;){
pos=x+*(u16 *)(map+y*2+MAP_ROW_OFFSETS);
if((u8)(map[(pos>>3)+MAP_CELL_BITMAP] & (1<<(pos&7))))return 1;
switch(*cmd++){
case 9:cmd++;break;   /* skip the step's extra byte */
case -1: case MOVE_DIR_STOP:return 0;
case MOVE_DIR_ATTACK:return 1;
case MOVE_DIR_LEFT:x--;break;
case MOVE_DIR_RIGHT:x++;break;
case MOVE_DIR_DOWN:y++;break;
case MOVE_DIR_UP:y--;break;
}
}
}

/* Whether a movement path ends by attacking the unit on its last cell: walk the
 * path, skipping the extra byte of each hold step (9), and stop at MOVE_DIR_ATTACK
 * (an attack) or at either end code (no attack). */
s32 MovePathEndsInAttack(s8 *path) {
 loop: switch (*path++) {
 case 9: path++; goto loop;   /* skip the step's extra byte */
 case MOVE_DIR_NONE: case MOVE_DIR_STOP: return 0;
 case MOVE_DIR_ATTACK: return 1;
 default: goto loop;
 }
}

#pragma opt_dead_code on
void MoveUnitRecordAlongPath(u8 *p,s8 *q) {
 loop: switch(*q++) {
 case 9: q++; goto loop;
 case -1: case 4: return;
 case 0: p[1]--;goto loop;
 case 1: p[1]++;goto loop;
 case 2: p[2]++;goto loop;
 case 3: p[2]--;goto loop;
 default: goto loop;
 }
}
#pragma opt_dead_code reset
void func_ov000_02169a24(void) {

}

/* Draws the moving unit's 3D sprite at its current position: picks the sprite
 * object and graphics-block size for the current view zoom (marking the
 * graphics for reload when the mode changed), then draws it with the map's
 * cell palette. */
void DrawUnitMoveSprite(void *move) {
 s32 GetViewZoom(void *);
 void SetSpritePaletteIndex(s32);
 void DrawSprite3D(void *,s32 *,s32,s32);
 s32 pos[3]; void *sprite; s32 gfxSize;
 u8 mode=GetViewZoom((void *)(*gCurrentMap+MAP_VIEW_ZOOM))<=0?MAP_SPRITE_ZOOM_SMALL:MAP_SPRITE_ZOOM_LARGE;
 if(mode==MAP_SPRITE_ZOOM_SMALL){sprite=M2C_FIELD(move,void **,UNIT_MOVE_SPRITE);gfxSize=MAP_SPRITE_GFX_SIZE_SMALL;}
 else{sprite=M2C_FIELD(move,void **,UNIT_MOVE_SPRITE2);gfxSize=MAP_SPRITE_GFX_SIZE_LARGE;}
 if(M2C_FIELD(move,u8 *,UNIT_MOVE_PALETTE_MODE)!=mode){M2C_FIELD(sprite,u8 *,0x22)|=1;M2C_FIELD(move,u8 *,UNIT_MOVE_PALETTE_MODE)=mode;}
 pos[0]=(M2C_FIELD(move,s16 *,UNIT_MOVE_X)+UNIT_MOVE_SPRITE_OFFSET_X)*MAP_SPRITE_CELL_SIZE;
 pos[1]=(M2C_FIELD(move,s16 *,UNIT_MOVE_Y)+UNIT_MOVE_SPRITE_OFFSET_Y)*MAP_SPRITE_CELL_SIZE;
 pos[2]=UNIT_MOVE_SPRITE_ATTR;
 SetSpritePaletteIndex(MAP_SPRITE_PALETTE);
 DrawSprite3D(sprite,pos,gfxSize,0);
}

/* Whether the moving unit may still step onto tile (cx,cy) and be drawn: open
 * fog (the owner's fog flag) or a visible cell the unit is allowed on.  While the
 * move is in its walking state, keeps the view centred on the unit. */
s32 UnitMove_CanStepOntoCell(void *p) {
    s32 IsUnitInSightAt(s32, s32, s32);
    void ScrollMapViewToPoint(s32, s32);
    s32 cx;
    s32 cy;
    u8 *base;
    u8 fogFlags;
    u32 unit;
    u32 idx;
    u8 hit;
    s32 visible;

    cx = (M2C_FIELD(p, s16 *, UNIT_MOVE_X) + 8) / 16;
    cy = (M2C_FIELD(p, s16 *, UNIT_MOVE_Y) + 8) / 16;
    base = (u8 *)*gCurrentMap;
    fogFlags = M2C_FIELD(base + M2C_FIELD(base + 0x5200, u16 *, 0xA4) * MAP_PLAYER_STRIDE, u8 *, 0x67C3);
    unit = M2C_FIELD(p, u32 *, UNIT_MOVE_UNIT);
    visible = 1;
    if (!(fogFlags & 2)) {
        idx = cx + M2C_FIELD(base + cy * 2 + 0x3700, u16 *, 0x58);
        hit = M2C_FIELD(base + (idx >> 3) + 0x5000, u8 *, 0x201) & (1 << (idx & 7));
        if (!hit || IsUnitInSightAt(unit, (s16)cx, (s16)cy) == 0) {
            visible = 0;
        }
    }
    if (M2C_FIELD(p, u8 *, UNIT_MOVE_STATE) == 2 && M2C_FIELD(p, u8 *, UNIT_MOVE_ACTIVE) != 0) {
        ScrollMapViewToPoint(M2C_FIELD(p, s16 *, UNIT_MOVE_X), M2C_FIELD(p, s16 *, UNIT_MOVE_Y));
    }
    return visible;
}

/* Create the two sprites that show the moving unit: load its tile graphics and
 * animation data, create both sprites, point them at the unit's tile and palette
 * offsets, select each one's frame from the facing direction (the second sprite
 * uses the next frame), and upload the owner's army palette to palette RAM. */
void InitUnitMoveSprites(void *move){
s32 CreateSpriteAnim(s32,s32,s32);void SetSpriteAnimFrame(s32,s32);void QueueMainOBJExtPaletteCopy(void *,s32,s32,s32);
extern u8 gArmyPalettes[];
void *player;s32 paletteOffset;
M2C_FIELD(move,s32 *,UNIT_MOVE_GFX)=LoadUnitMoveGfx((s32)move);
M2C_FIELD(move,s32 *,UNIT_MOVE_ANIM)=LoadUnitMoveAnim(move);
M2C_FIELD(move,s32 *,UNIT_MOVE_SPRITE)=CreateSpriteAnim(M2C_FIELD(move,s32 *,UNIT_MOVE_ANIM),15,14);
M2C_FIELD(move,s32 *,UNIT_MOVE_SPRITE2)=CreateSpriteAnim(M2C_FIELD(move,s32 *,UNIT_MOVE_ANIM),15,14);
M2C_FIELD(move,u8 *,UNIT_MOVE_PALETTE_MODE)=0;
SetSpriteAnimFrame(M2C_FIELD(move,s32 *,UNIT_MOVE_SPRITE),M2C_FIELD(move,s8 *,UNIT_MOVE_DIRECTION));
M2C_FIELD(M2C_FIELD(move,void **,UNIT_MOVE_SPRITE),s32 *,0x30)=M2C_FIELD(move,s32 *,UNIT_MOVE_GFX);
M2C_FIELD(M2C_FIELD(move,void **,UNIT_MOVE_SPRITE),s32 *,0x28)=UnitMoveTileOffset(move);
M2C_FIELD(M2C_FIELD(move,void **,UNIT_MOVE_SPRITE),s32 *,0x2c)=UnitMovePaletteOffset(move);
SetSpriteAnimFrame(M2C_FIELD(move,s32 *,UNIT_MOVE_SPRITE2),M2C_FIELD(move,s8 *,UNIT_MOVE_DIRECTION)+4);
M2C_FIELD(M2C_FIELD(move,void **,UNIT_MOVE_SPRITE2),s32 *,0x30)=M2C_FIELD(move,s32 *,UNIT_MOVE_GFX);
M2C_FIELD(M2C_FIELD(move,void **,UNIT_MOVE_SPRITE2),s32 *,0x28)=UnitMoveTileOffset(move);
M2C_FIELD(M2C_FIELD(move,void **,UNIT_MOVE_SPRITE2),s32 *,0x2c)=UnitMovePaletteOffset(move);
player=(u8*)M2C_FIELD(gCurrentMap,void **,0)+MAP_PLAYER_STATES+M2C_FIELD(move,u8 *,UNIT_MOVE_OWNER)*MAP_PLAYER_STRIDE;
paletteOffset=UnitMovePaletteOffset(move);
QueueMainOBJExtPaletteCopy(gArmyPalettes+(M2C_FIELD(player,u8 *,PLAYER_REC_ARMY_INDEX)-1)*32,paletteOffset,32,0);
}

/* Release the controller's two unit sprites and the tile-graphics and animation
 * buffers they were loaded from. */
void UnitMove_FreeGraphics(void *move) {
    void Sprite_ClearHandle(s32 *);
    M2C_UNK HeapFreeBlock(s32);

    Sprite_ClearHandle(M2C_FIELD(move, s32 *, UNIT_MOVE_SPRITE));
    Sprite_ClearHandle(M2C_FIELD(move, s32 *, UNIT_MOVE_SPRITE2));
    HeapFreeBlock(M2C_FIELD(move, s32 *, UNIT_MOVE_ANIM));
    HeapFreeBlock(M2C_FIELD(move, s32 *, UNIT_MOVE_GFX));
}

/* Load the moving unit's tile graphics: switch to the unit-move graphics
 * directory ("/mu") and decompress the file of the move controller's variant. */
s32 LoadUnitMoveGfx(M2C_UNK move) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    M2C_UNK LoadDecompressedFile(s32, M2C_UNK);
    s32 GetUnitMoveGfxFileId(M2C_UNK);
    extern M2C_UNK gOv000UnitMoveGfxDir;

    SetFileDirectory(&gOv000UnitMoveGfxDir);
    LoadDecompressedFile(GetUnitMoveGfxFileId(move), 1);
}

/* Load the move-animation data of the unit the move controller walks (its kind
   is at UNIT_MOVE_KIND) and return the buffer. */
s32 LoadUnitMoveAnim(void *move) {
    M2C_UNK LoadFileToBuffer(s32, M2C_UNK);
    s32 GetUnitMoveAnimFileId(u8);
    extern M2C_UNK sUnitMoveAnimDir;
    SetFileDirectory(&sUnitMoveAnimDir);
    LoadFileToBuffer(GetUnitMoveAnimFileId(M2C_FIELD(move, u8 *, UNIT_MOVE_KIND)), 1);
}

s32 UnitMoveTileOffset(void *arg0) {
    return (M2C_FIELD(arg0, s8 *, 0x45) << 0xB) + 0x30D20;
}

s32 UnitMovePaletteOffset(void *arg0) {
    return (M2C_FIELD(arg0, s8 *, 0x45) << 5) + 0x14C0;
}

#pragma push
#pragma opt_common_subs off
/* Pans the map view so the point (x, y), in 1/16-cell units, stays on screen:
 * a point within one cell of the view edge scrolls the view to put it one cell
 * in (two cells from the far edge), and the result is clamped to the map. */
void ScrollMapViewToPoint(s32 x,s32 y){
s32 GetMapViewWidth(void);s32 GetMapViewHeight(void);
s32 viewW=GetMapViewWidth(),viewH=GetMapViewHeight();
s16 scrollX=MAP_VIEW_NO_SCROLL,scrollY=MAP_VIEW_NO_SCROLL;
void *map=M2C_FIELD(gCurrentMap,void **,0);s16 viewX=M2C_FIELD(map,s16 *,MAP_VIEW_X),viewY; s32 dx=x-viewX,dy;void (*scrollDone)(void);
if(dx<MAP_VIEW_MARGIN)scrollX=x-MAP_VIEW_MARGIN;
if(dx>((viewW-2)<<4))scrollX=x-((viewW-2)<<4);
viewY=M2C_FIELD(map,s16 *,MAP_VIEW_Y);dy=y-viewY;
if(dy<MAP_VIEW_MARGIN)scrollY=y-MAP_VIEW_MARGIN;
if(dy>((viewH-2)<<4))scrollY=y-((viewH-2)<<4);
if(scrollX==MAP_VIEW_NO_SCROLL && scrollY==MAP_VIEW_NO_SCROLL)return;
if(scrollX==MAP_VIEW_NO_SCROLL)scrollX=viewX;
else if(scrollX<0)scrollX=0;
else if(scrollX>((M2C_FIELD(map,u16 *,MAP_WIDTH)-viewW)<<4))scrollX=(M2C_FIELD(map,u16 *,MAP_WIDTH)-viewW)<<4;
if(scrollY==MAP_VIEW_NO_SCROLL)scrollY=viewY;
else if(scrollY<0)scrollY=0;
else if(scrollY>((M2C_FIELD(map,u16 *,MAP_HEIGHT)-viewH)<<4))scrollY=(M2C_FIELD(map,u16 *,MAP_HEIGHT)-viewH)<<4;
M2C_FIELD(map,s16 *,MAP_VIEW_X)=scrollX;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,MAP_VIEW_Y)=scrollY;
scrollDone=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),MAPVIEW_SCROLL_DONE);
if(scrollDone)scrollDone();
}
#pragma pop
/* File id of the move-graphics file (LoadUnitMoveGfx) of the unit-move's variant:
 * the variant is picked from the unit's kind and its owner's cached sprite state,
 * and its entry in gUnitMoveGfxFileIds is UNIT_MOVE_SOUND_RECORD_SIZE bytes long. */
s32 GetUnitMoveGfxFileId(M2C_UNK move) {
    s32 GetUnitVariantIndex(s32,s32);
    extern s32 gUnitMoveGfxFileIds[];
    return M2C_FIELD(gUnitMoveGfxFileIds,s32 *,GetUnitVariantIndex(M2C_FIELD(move,u8 *,UNIT_MOVE_KIND),M2C_FIELD(*gCurrentMap+M2C_FIELD(move,u8 *,UNIT_MOVE_OWNER)*MAP_PLAYER_STRIDE,u8 *,PLAYER_SPRITE_STATE_OFF))*UNIT_MOVE_SOUND_RECORD_SIZE);
}

/* The variant's unit-move speed: the step duration in frames from the unit-variant
 * move record, doubled while fast animation is on, returned as a signed half. */
s32 GetUnitMoveSpeed(void *move) {
 s32 GetUnitVariantIndex(s32,s32);
 s32 IsFastAnimation(void);
 extern M2C_UNK gUnitMoveStepSpeeds;
 s32 value;
 void *map=M2C_FIELD(gCurrentMap,void **,0);
 s32 variant=GetUnitVariantIndex(M2C_FIELD(move,u8 *,UNIT_MOVE_KIND),M2C_FIELD(map+M2C_FIELD(move,u8 *,UNIT_MOVE_OWNER)*MAP_PLAYER_STRIDE,u8 *,PLAYER_SPRITE_STATE_OFF));
 value=M2C_FIELD(&gUnitMoveStepSpeeds,u8 *,variant*UNIT_MOVE_SOUND_RECORD_SIZE);
 if(IsFastAnimation()!=0)value<<=1;
 return (s16)value;
}

/* File id of the move-animation file (LoadUnitMoveAnim) for a unit kind: the
 * kind's variant is looked up with a fixed sprite state, and its
 * UNIT_MOVE_SOUND_RECORD_SIZE-byte entry in gUnitMoveAnimFileIds starts with the
 * animation file id. */
s32 GetUnitMoveAnimFileId(u8 kind) {
    s32 GetUnitVariantIndex(s32,s32);
    extern s32 gUnitMoveAnimFileIds[];
    return M2C_FIELD(gUnitMoveAnimFileIds,s32 *,GetUnitVariantIndex(kind,1)*UNIT_MOVE_SOUND_RECORD_SIZE);
}

void StepUnitMove(void) {
    M2C_UNK PlayUnitStepSound();
    PlayUnitStepSound();
}

