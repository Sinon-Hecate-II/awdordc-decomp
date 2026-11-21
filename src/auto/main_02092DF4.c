/* 50 functions from 0x02092DF4 to 0x02093D9C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"

s32 func_02092df4(void *arg0) {
 s32 (*temp_r0)();
 s32 var_r0;
 void *temp_r0_2;
 void *temp_r0_3;
 temp_r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 (**)(), 4);
 if (temp_r0 != NULL) {
  if (temp_r0() != 0) var_r0 = 1; else var_r0 = 0;
 } else var_r0 = 1;
 if (var_r0 != 0) {
  temp_r0_3 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0xC);
  M2C_FIELD(arg0, void **, 4) = temp_r0_3;
  M2C_FIELD(arg0, void **, 0) = temp_r0_3;
 } else {
  M2C_FIELD(arg0, void **, 4) = M2C_FIELD(arg0, void **, 4) + 0x10;
 }
 return 1;
}

s32 func_02092e4c(void *arg0) {
 M2C_UNK SetPlayerTeam(u8, s16);
 extern void **gCurrentMap;
 u8 temp_r0;
 void *temp_r1;
 temp_r1 = M2C_FIELD(arg0,void **,4);
 temp_r0 = (u8) M2C_FIELD(temp_r1,s16 *,8);
 SetPlayerTeam((u8)temp_r0,M2C_FIELD(temp_r1,s16 *,0xa));
 M2C_FIELD((u8)temp_r0 * 0x8c + (s32)*gCurrentMap,s8 *,0x67c2) = M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,0xa);
 M2C_FIELD(arg0,void **,4) = M2C_FIELD(arg0,void **,4)+0x10;
 return 1;
}

s32 func_02092ea8(void *arg0) {
    extern void **gCurrentMap;
    M2C_FIELD(*gCurrentMap, s8 *, 0x5155) = (s8) M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02092edc(void *arg0) {
 extern void **gCurrentMap;
 extern s32 g3DSpriteEngineSub, gCur3DSpriteEngine;
 s32 temp_ip;
 temp_ip=gCur3DSpriteEngine;
 gCur3DSpriteEngine=g3DSpriteEngineSub;
 M2C_FIELD(*gCurrentMap,s8 *,0x5155) = M2C_FIELD(M2C_FIELD(arg0,void **,4),s16 *,8);
 gCur3DSpriteEngine=temp_ip;
 M2C_FIELD(arg0,void **,4) = M2C_FIELD(arg0,void **,4)+0x10;
 return 1;
}

s32 func_02092f30(void *arg0){
extern void **gCurrentMap;
void *p=M2C_FIELD(arg0,void **,4);
s16 value=M2C_FIELD(p,s16 *,10);
void *dest=(u8 *)*gCurrentMap+0x67a4+M2C_FIELD(p,s16 *,8)*0x8c;
M2C_FIELD(dest,u32 *,0x6c)=(M2C_FIELD(dest,u32 *,0x6c)&~255)|(value&255);
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

/* Map-script opcode: set the map cursor to the command's two signed operands,
 * then record the new position as the current player's cursor.  Advances the
 * script and keeps running. */
s32 MapScriptSetCursor(void *state){
extern void **gCurrentMap;
M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)=M2C_FIELD(M2C_FIELD(state,void **,MAP_SCRIPT_STATE_IP),s16 *,MAP_SCRIPT_OPERAND0);
M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)=M2C_FIELD(M2C_FIELD(state,void **,MAP_SCRIPT_STATE_IP),s16 *,MAP_SCRIPT_OPERAND1);
M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE,u8 *,MAP_PLAYER_STATES+PLAYER_REC_CURSOR_X)=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X);
M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)*MAP_PLAYER_STRIDE,u8 *,MAP_PLAYER_STATES+PLAYER_REC_CURSOR_Y)=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y);
M2C_FIELD(state,s32 *,MAP_SCRIPT_STATE_IP)+=MAP_SCRIPT_COMMAND_SIZE;return 0;
}

/* Map-script opcode: move the map cursor by adding the command's two signed
 * operands to MAP_CURSOR_TARGET_X/Y, then record the new target as the current
 * player's cursor.  Advances the script and keeps running. */
s32 MapScriptMoveCursor(void *state) {
    extern void **gCurrentMap;
    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_X) += M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, 8);
    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_Y) += M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, 10);
    M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_CURSOR_X) = M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_X);
    M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_CURSOR_Y) = M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_TARGET_Y);
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 0;
}

s32 func_020930bc(void *arg0) {
    s32 func_020cc7f8();
    if (func_020cc7f8() == 0) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    }
    return 0;
}

s32 func_020930e0(void *arg0) {
    M2C_UNK EndPlayerTurn();
    EndPlayerTurn();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 0;
}

s32 func_02093100(void *arg0) {
    s32 func_02091ecc(s16);
    M2C_UNK AwardVictoryToPlayer(s32, M2C_UNK);
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r0;
    s32 temp_r5;

    temp_r0 = func_02091ecc(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8));
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    AwardVictoryToPlayer(temp_r0, 0x80);
    gCur3DSpriteEngine = temp_r5;
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093154(void *arg0) {
    s32 func_02091ecc(s16);
    M2C_UNK AwardVictoryToPlayer(s32, M2C_UNK);
    extern s32 g3DSpriteEngineSub;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r0;
    s32 temp_r5;

    temp_r0 = func_02091ecc(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8));
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    AwardVictoryToPlayer(temp_r0, 0x80);
    gCur3DSpriteEngine = temp_r5;
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020931a8(void *arg0) {
    s32 func_02091ecc(s16);
    M2C_UNK UpdateTeamRecords(s32, M2C_UNK);
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r0;
    s32 temp_r5;

    temp_r0 = func_02091ecc(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8));
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    UpdateTeamRecords(temp_r0, 0x80);
    gCur3DSpriteEngine = temp_r5;
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020931fc(void *arg0) {
    s32 func_02091ecc(s16);
    M2C_UNK UpdateTeamRecords(s32, M2C_UNK);
    extern s32 g3DSpriteEngineSub;
    extern s32 gCur3DSpriteEngine;
    s32 temp_r0;
    s32 temp_r5;

    temp_r0 = func_02091ecc(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8));
    temp_r5 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    UpdateTeamRecords(temp_r0, 0x80);
    gCur3DSpriteEngine = temp_r5;
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093250(void *arg0) {
    M2C_UNK PlaySoundEffect(s32);
    s32 IsMessageBoxActive();
    s32 temp_r4;

    temp_r4 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC);
    if (IsMessageBoxActive() == 0) {
        PlaySoundEffect(temp_r4);
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093288(void *arg0) {
    M2C_UNK PlaySlotPendingSound(M2C_UNK, M2C_UNK, s32);
    s32 temp_r4;

    temp_r4 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC);
    if (IsMessageBoxActive() == 0) {
        PlaySlotPendingSound(0, -1, temp_r4);
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020932c8(void *arg0) {
    M2C_UNK func_02090034(M2C_UNK, s32);
    s32 var_r4;

    var_r4 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC);
    if (IsMessageBoxActive() != 0) {
        var_r4 = 0;
    }
    func_02090034(0, var_r4);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093304(void *arg0) {
s32 v;
s32 temp=M2C_FIELD(M2C_FIELD(arg0,void **,4),s32 *,12);
if(IsMessageBoxActive()!=0) v=1;
else {PlayMusicTrack(temp);v=0;}
M2C_FIELD(arg0,s32 *,4)+=16;return (s16)v;
}

s32 func_02093348(void *arg0) {
    M2C_UNK func_0208f844(s32);
    func_0208f844(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

void func_02093370(void *arg0) {
    s32 func_0208f8a0();
    if (func_0208f8a0() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_0209338c(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 8) = func_02093370;
 M2C_FIELD(arg0, s32 *, 4) += 0x10;
 return 0;
}

s32 func_020933ac(void *arg0) {
    M2C_UNK func_0208f8ec(s16, s32);
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    func_0208f8ec(M2C_FIELD(temp_r1, s16 *, 8), M2C_FIELD(temp_r1, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

s32 func_020933d8(void *arg0) {
    M2C_UNK func_0208f8c4();
    func_0208f8c4();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 0;
}

s32 func_020933f8(void *arg0) {
    M2C_UNK func_0208f8d8();
    func_0208f8d8();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 0;
}

s32 func_02093418(void *arg0) {
extern void **gCurrentMap;
s32 GetPlayerMusicTrack(s32);
func_0208f7d0(GetPlayerMusicTrack(M2C_FIELD(*gCurrentMap,u16 *,0x52A4)&255));
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02093458(void *arg0) {
extern void **gCurrentMap;
s32 GetPlayerMusicTrack(s32);
if(IsMessageBoxActive()==0) {
s32 v=func_0208f770();
if(v==GetPlayerMusicTrack(M2C_FIELD(*gCurrentMap,u16 *,0x52A4)&255)) func_0208f8c4();
}
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_020934b4(void *arg0) {
extern void **gCurrentMap;
s32 GetPlayerMusicTrack(s32);
s32 v=func_0208f770();
if(v==GetPlayerMusicTrack(M2C_FIELD(*gCurrentMap,u16 *,0x52A4)&255)) func_0208f8d8();
M2C_FIELD(arg0,s32 *,4)+=16;return 0;
}

s32 func_02093504(void *arg0) {
    s32 func_020a8c10();
    s16 temp_r5;
    s32 var_r6;
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 4);
    temp_r5 = M2C_FIELD(temp_r1, s16 *, 0xA);
    var_r6 = M2C_FIELD(temp_r1, s32 *, 0xC);
    func_02091ecc((s16) M2C_FIELD(temp_r1, s16 *, 8) >> 1);
    if ((temp_r5 != func_020a8c10()) && (var_r6 > 0)) {
        do {
            var_r6 -= 1;
            M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
        } while (var_r6 > 0);
    }
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093564(void *arg0) {
    M2C_UNK func_02086ae4(s16, M2C_UNK);
    func_02086ae4(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8), 1);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_02093590(void *arg0) {
    func_02086ae4(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 8), 0);
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

s32 func_020935bc(void *arg0) {
    M2C_UNK func_0209656c(s32, u8);
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 4);
    func_0209656c(M2C_FIELD(temp_r0, s32 *, 4), (u8) M2C_FIELD(temp_r0, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

void func_020935ec(M2C_UNK arg0, M2C_UNK arg1) {
    s32 CreateUnitMoveForUnit();
    M2C_UNK StartUnitMove(s32, M2C_UNK);
    M2C_UNK func_ov000_02169998(M2C_UNK, M2C_UNK);
    StartUnitMove(CreateUnitMoveForUnit(), arg1);
    func_ov000_02169998(arg0, arg1);
}

/* Send a unit along the path to tile (x, y): build the unit's movement range
   over the whole map, build the path back from the target into the map's cursor
   path, end that path with the -1 sentinel, start the unit's move along it and
   move the unit record to the target. */
void MoveUnitToTile(void *unit, u8 x, u8 y) {
    M2C_UNK FloodFillUnitRange(u8, u8, u32, s32, s32);
    M2C_UNK func_01ffc4b8(M2C_UNK, M2C_UNK, s32);
    s32 CreateUnitMoveForUnit();
    M2C_UNK StartUnitMove(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov000_02169998(M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;
    u8 *u = unit;
    signed char *ptr;
    void *move;

    FloodFillUnitRange(u[1], u[2], (u32) (u[0] << 0x1A) >> 0x1A, 0x6E, 1);
    func_01ffc4b8(x, y, (s32) *gCurrentMap + MAP_CURSOR_PATH);
    ptr = (signed char *) *gCurrentMap + MAP_CURSOR_PATH;
    while (*ptr != 4 && *ptr != -1) {
        ptr++;
    }
    *ptr = (signed char) -1;
    move = (void *) CreateUnitMoveForUnit(u);
    StartUnitMove(move, (s32) *gCurrentMap + MAP_CURSOR_PATH);
    func_ov000_02169998(u, (s32) *gCurrentMap + MAP_CURSOR_PATH);
}

/* Map-script command: find the unit standing on the command's tile (operand 0
 * is its x, operand 1 its y) and start moving it along the path the command
 * points at in its +4 word, then advance the script to the next command. */
s32 StartUnitMoveAtCell(void *script) {
    extern void **gCurrentMap;
    void *command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    void *map = *gCurrentMap;
    u32 unitIndex = M2C_FIELD((u8 *)map + (M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0) + M2C_FIELD((u8 *)map + M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1) * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_UNIT_ID);

    if (unitIndex)
        func_020935ec((u8 *)map + MAP_UNIT_RECORDS + unitIndex * MAP_UNIT_STRIDE, M2C_FIELD(command, s32 *, 4));
    M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 1;
}

s32 func_0209375c(void *arg0) {
extern void **gCurrentMap; extern u16 gPlayerUnitIdBase[];
void *p=M2C_FIELD(arg0,void **,4);
s32 start=gPlayerUnitIdBase[M2C_FIELD(p,s16 *,8)];
void *found=0; s32 i; void *entry; u8 (*entries)[14]; u32 kind;
for(i=start+1;i<start+0x33;i++){
entries=(void *)((u8 *)*gCurrentMap+0x59a4);
entry=entries[i];
kind=(u32)(M2C_FIELD(entry,u8 *,0)<<26)>>26;
if(kind && (!M2C_FIELD(p,s16 *,10)||kind==M2C_FIELD(p,s16 *,10))){found=(u8 *)*gCurrentMap+0x59a4+i*14;break;}
}
if(found)func_020935ec(found,M2C_FIELD(p,s32 *,4));
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

#pragma opt_propagation off
s32 func_0209380c(void *arg0) {
extern void **gCurrentMap;
void *p=M2C_FIELD(arg0,void **,4);
void *base=*gCurrentMap;
s32 packed=M2C_FIELD(p,s32 *,12);
u8 a=packed,b=(u32)packed>>8;
u32 index=M2C_FIELD((u8 *)base+(M2C_FIELD(p,s16 *,8)+M2C_FIELD((u8 *)base+M2C_FIELD(p,s16 *,10)*2,u16 *,0x3758)),u8 *,0x508);
if(index)MoveUnitToTile((u8 *)base+0x59a4+index*14,a,b);
M2C_FIELD(arg0,s32 *,4)+=16;
return 1;
}
#pragma opt_propagation reset
s32 func_02093888(void *arg0) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
s32 i, end;
u8 a,b;
void *p=M2C_FIELD(arg0,void **,4);
u32 v=M2C_FIELD(p,s32 *,12);
void *found=0;
i=gPlayerUnitIdBase[M2C_FIELD(p,s16 *,8)]+1;
end=gPlayerUnitIdBase[M2C_FIELD(p,s16 *,8)]+0x33;
a=(u8)v;
b=(u8)(v>>8);
if(i<end) {
u8 *base=(u8 *)*gCurrentMap+0x59A4;
u8 *entry=base+i*14;
do {
u32 bits=(u32)(*entry<<26)>>26;
if(bits && (M2C_FIELD(p,s16 *,10)==0 || bits==M2C_FIELD(p,s16 *,10))) {found=base+i*14;break;}
i++;entry+=14;
}while(i<end);
}
if(found)MoveUnitToTile(found,a,b);
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

void func_02093944(void *arg0) {
    s32 func_ov000_0216971c();
    if (func_ov000_0216971c() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_02093960(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 8) = func_02093944;
 M2C_FIELD(arg0, s32 *, 4) += 0x10;
 return 0;
}

s32 func_02093980(void *arg0) {
extern void **gCurrentMap;
void *p=M2C_FIELD(arg0,void **,4);
s32 y=M2C_FIELD(p,s16 *,10);
s32 x=M2C_FIELD(p,s16 *,8);
void *base=*gCurrentMap;
u8 id=M2C_FIELD((u8 *)base+(x+M2C_FIELD((u8 *)base+y*2,u16 *,0x3758)),u8 *,0x508);
if(id) {RefreshMapView(RemoveUnit(id));}
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

/* Battle event command: remove units from the current player's group, optionally
 * only those of one kind (kind 0 matches any unit).  A non-zero argument word
 * removes just the first match; the map view is refreshed afterwards. */
s32 RemovePlayerUnitsOfKind(void *ctx) {
extern void **gCurrentMap;
extern u16 gPlayerUnitIdBase[];
void *cmd=M2C_FIELD(ctx,void **,4);
s32 i;
for(i=gPlayerUnitIdBase[M2C_FIELD(cmd,s16 *,8)]+1;i<gPlayerUnitIdBase[M2C_FIELD(cmd,s16 *,8)]+MAP_UNIT_GROUP_SCAN;i++){
u32 kind=(u32)(M2C_FIELD((u8 *)*gCurrentMap+i*MAP_UNIT_STRIDE,u8 *,MAP_UNIT_RECORDS)<<26)>>26;
if(kind && (M2C_FIELD(cmd,s16 *,10)==0 || kind==M2C_FIELD(cmd,s16 *,10))) {
RemoveUnit(i);cmd=M2C_FIELD(ctx,void **,4);
if(M2C_FIELD(cmd,s32 *,12)!=0)break;
}
}
RefreshMapView();
M2C_FIELD(ctx,s32 *,4)+=MAP_SCRIPT_COMMAND_SIZE;
return 1;
}

/* Map-script command: play the unit-removal effect for the unit standing on the
 * command's tile (operand 0 is its x, operand 1 its y), then advance the script. */
s32 MapScriptRemoveUnitAtCell(void *script) {
    extern void **gCurrentMap;
    void *command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    s32 tileY = M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1);
    s32 tileX = M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0);
    void *map = *gCurrentMap;
    u8 unitId = M2C_FIELD((u8 *)map + (tileX + M2C_FIELD((u8 *)map + tileY * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_UNIT_ID);
    if (unitId) {
        RemoveUnitWithEffect((u8 *)map + MAP_UNIT_RECORDS + unitId * MAP_UNIT_STRIDE);
    }
    M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 1;
}

void func_02093b0c(void *arg0) {
    s32 IsBattleEffectActive();
    if (IsBattleEffectActive() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_02093b28(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 8) = func_02093b0c;
 M2C_FIELD(arg0, s32 *, 4) += 0x10;
 return 0;
}

s32 func_02093b48(void *arg0) {
    extern u16 gPlayerUnitIdBase[];
    extern void **gCurrentMap;
    s32 *MapScriptFindLabel(s32 **, s32);
    void *p = M2C_FIELD(arg0, void **, 4);
    s32 i;
    u32 found = 0;
    u8 (*units)[MAP_UNIT_STRIDE];
    u32 kind;

    for (i = gPlayerUnitIdBase[M2C_FIELD(p, s16 *, 8)] + 1; i < gPlayerUnitIdBase[M2C_FIELD(p, s16 *, 8)] + MAP_UNIT_GROUP_SCAN; i++) {
        units = (void *)((u8 *)*gCurrentMap + MAP_UNIT_RECORDS);
        kind = (u32)(units[i][MAP_UNIT_KIND] << 26) >> 26;
        if (kind && (M2C_FIELD(p, s16 *, 10) == 0 || kind == M2C_FIELD(p, s16 *, 10))) {
            found = 1;
            break;
        }
    }
    if (0 == M2C_FIELD(p, s32 *, 4)) {
        found = found ? 0 : 1;
    }
    if (found) {
        s32 *label = MapScriptFindLabel((s32 **)arg0, M2C_FIELD(p, s32 *, 12));
        if (label)
            M2C_FIELD(arg0, void **, 4) = label;
        else
            M2C_FIELD(arg0, s32 *, 4) += 0x10;
    } else {
        M2C_FIELD(arg0, s32 *, 4) += 0x10;
    }
    return 1;
}

s32 func_02093c2c(void *arg0){
extern void **gCurrentMap;
void *p=M2C_FIELD(arg0,void **,4);
M2C_FIELD((u8 *)*gCurrentMap+M2C_FIELD(p,s16 *,8)*0x8c,u8 *,0x67bd)=M2C_FIELD(p,u32 *,12);
M2C_FIELD(arg0,s32 *,4)+=16;return 1;
}

s32 func_02093c6c(void *arg0) {
    M2C_UNK StartScriptedScreenTransition(s16, s16, s32);
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 4);
    StartScriptedScreenTransition(M2C_FIELD(temp_r2, s16 *, 8), M2C_FIELD(temp_r2, s16 *, 0xA), M2C_FIELD(temp_r2, s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

void func_02093c9c(void *arg0) {
    s32 func_020953e8();
    if (func_020953e8() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_02093cb8(void *arg0){func_020953d0();M2C_FIELD(arg0,void (**)(void *),8)=func_02093c9c;M2C_FIELD(arg0,s32 *,4)+=16;return 0;}

s32 func_02093ce4(void *arg0) {
    M2C_UNK func_020943bc(s32);
    func_020943bc(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 1;
}

/* Map-script command: rebuild the scene's 3D sprites (the battle view and/or the
 * sub-screen UI) on the engine the scene is drawn into; DS3D_TARGET_ACTIVE means
 * whichever engine gCur3DSpriteEngine already holds.  Advances the script. */
s32 ScriptCmd_RebuildScene(void *script) {
    M2C_UNK Get3DSpriteTargetMode();
    M2C_UNK func_020d4ba4();
    M2C_UNK func_020d8e28();
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 target;
    u8 isMain;

    target = Get3DSpriteTargetMode();
    if (target == DS3D_TARGET_ACTIVE) {
        if (gCur3DSpriteEngine == g3DSpriteEngineMain) {
            isMain = 1;
        } else {
            isMain = 0;
        }
        if (isMain != 1) {
            target = DS3D_TARGET_SUB;
        } else {
            target = DS3D_TARGET_MAIN;
        }
    }
    switch (target) {                               /* irregular */
    case DS3D_TARGET_MAIN:
        func_020d4ba4();
        break;
    case DS3D_TARGET_SUB:
        func_020d8e28();
        break;
    case DS3D_TARGET_BOTH:
        func_020d8e28();
        func_020d4ba4();
        break;
    }
    M2C_FIELD(script, s32 *, 4) = (s32) (M2C_FIELD(script, s32 *, 4) + 0x10);
    return 0;
}

