/* 50 functions from 0x02092DF4 to 0x02093D9C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"

/* Map-script opcode: when the command's condition callback at +4 is absent or
 * reports true, enter the script block named by the command's wide operand,
 * pointing both the interpreter's block and its instruction pointer at it;
 * otherwise run the next command.  Returns 1 so the interpreter keeps running. */
s32 MapScriptEnterBlockIf(void *state) {
    s32 (*condition)();
    s32 takeBlock;
    void *block;

    condition = M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s32 (**)(), MAP_SCRIPT_PARAM);
    if (condition != NULL) {
        if (condition() != 0) takeBlock = 1; else takeBlock = 0;
    } else takeBlock = 1;
    if (takeBlock != 0) {
        block = M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), void **, MAP_SCRIPT_OPERAND2);
        M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = block;
        M2C_FIELD(state, void **, MAP_SCRIPT_STATE_BLOCK) = block;
    } else {
        M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE;
    }
    return 1;
}

/* Map-script opcode: give the player named by the command's first operand the
 * team in its second operand (SetPlayerTeam), record that value as the player's
 * control kind in the map's player record, then advance the script and keep running. */
s32 MapScriptSetPlayerTeam(void *state) {
 M2C_UNK SetPlayerTeam(u8, s16);
 extern void **gCurrentMap;
 u8 player;
 void *command;
 command = M2C_FIELD(state,void **,MAP_SCRIPT_STATE_IP);
 player = (u8) M2C_FIELD(command,s16 *,MAP_SCRIPT_OPERAND0);
 SetPlayerTeam((u8)player,M2C_FIELD(command,s16 *,MAP_SCRIPT_OPERAND1));
 M2C_FIELD((u8)player * MAP_PLAYER_STRIDE + (s32)*gCurrentMap,s8 *,PLAYER_CONTROL_OFF) = M2C_FIELD(M2C_FIELD(state,void **,MAP_SCRIPT_STATE_IP),s16 *,MAP_SCRIPT_OPERAND1);
 M2C_FIELD(state,void **,MAP_SCRIPT_STATE_IP) = M2C_FIELD(state,void **,MAP_SCRIPT_STATE_IP)+MAP_SCRIPT_COMMAND_SIZE;
 return 1;
}

/* Map-script opcode: copy the command's first operand into the map's battle-rule
 * flags, advance the script one command and keep running. */
s32 MapScriptSetBattleRules(void *state) {
    extern void **gCurrentMap;
    M2C_FIELD(*gCurrentMap, s8 *, MAP_BATTLE_RULES) = (s8) M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND0);
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: set the map's battle-rule flags from the command's first
 * operand, with the sub screen's 3D sprite engine selected while it runs, then
 * advance the script one command and keep running. */
s32 MapScriptSetBattleRulesSub(void *state) {
    extern void **gCurrentMap;
    extern s32 g3DSpriteEngineSub, gCur3DSpriteEngine;
    s32 savedEngine;

    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    M2C_FIELD(*gCurrentMap, s8 *, MAP_BATTLE_RULES) = M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND0);
    gCur3DSpriteEngine = savedEngine;
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE;
    return 1;
}

/* Map-script opcode: give the player named by the command's first operand the
 * army id in its second operand (the low byte of the player record's sprite
 * state), then advance the script and keep running. */
s32 MapScriptSetPlayerArmy(void *state) {
    extern void **gCurrentMap;
    void *command = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP);
    s16 army = M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1);
    void *record = (u8 *)*gCurrentMap + MAP_PLAYER_STATES + M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0) * MAP_PLAYER_STRIDE;

    M2C_FIELD(record, u32 *, PLAYER_REC_SPRITE) = (M2C_FIELD(record, u32 *, PLAYER_REC_SPRITE) & ~255) | (army & 255);
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 1;
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
    s32 IsBattlePreviewActive();
    if (IsBattlePreviewActive() == 0) {
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

/* Map-script opcode: award the battle to the player named by the command's first
 * operand, drawing the defeat effects on the main screen (by pointing
 * gCur3DSpriteEngine at the main engine for the call), then advance the script
 * and keep running. */
s32 MapScriptAwardVictoryToPlayerMain(void *state) {
    s32 MapScriptResolvePlayer(s16);
    M2C_UNK AwardVictoryToPlayer(s32, M2C_UNK);
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 winner;
    s32 savedEngine;

    winner = MapScriptResolvePlayer(M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND0));
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    AwardVictoryToPlayer(winner, 0x80);
    gCur3DSpriteEngine = savedEngine;
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: award the battle to the player named by the command's first
 * operand, drawing the victory effects on the sub screen (by pointing
 * gCur3DSpriteEngine at the sub engine for the call), then advance the script and
 * keep running. */
s32 MapScriptAwardVictoryToPlayerSub(void *state) {
    s32 MapScriptResolvePlayer(s16);
    M2C_UNK AwardVictoryToPlayer(s32, M2C_UNK);
    extern s32 g3DSpriteEngineSub;
    extern s32 gCur3DSpriteEngine;
    s32 winner;
    s32 savedEngine;

    winner = MapScriptResolvePlayer(M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND0));
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    AwardVictoryToPlayer(winner, 0x80);
    gCur3DSpriteEngine = savedEngine;
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: redraw the team records of the player named by the command's
 * first operand, with gCur3DSpriteEngine pointed at the main screen's engine so the
 * records are laid out there, then advance the script and keep running. */
s32 MapScriptUpdateTeamRecordsMain(void *state) {
    s32 MapScriptResolvePlayer(s16);
    M2C_UNK UpdateTeamRecords(s32, M2C_UNK);
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 player;
    s32 savedEngine;

    player = MapScriptResolvePlayer(M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND0));
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    UpdateTeamRecords(player, 0x80);
    gCur3DSpriteEngine = savedEngine;
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: redraw the team records of the player named by the command's
 * first operand, with gCur3DSpriteEngine pointed at the sub screen's engine so the
 * records are laid out there, then advance the script and keep running. */
s32 MapScriptUpdateTeamRecordsSub(void *state) {
    s32 MapScriptResolvePlayer(s16);
    M2C_UNK UpdateTeamRecords(s32, M2C_UNK);
    extern s32 g3DSpriteEngineSub;
    extern s32 gCur3DSpriteEngine;
    s32 player;
    s32 savedEngine;

    player = MapScriptResolvePlayer(M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND0));
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    UpdateTeamRecords(player, 0x80);
    gCur3DSpriteEngine = savedEngine;
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: play the plain sound effect named by the command's wide
 * operand, unless a message box is up.  Advances the script and keeps running. */
s32 MapScriptPlaySoundEffect(void *state) {
    M2C_UNK PlaySoundEffect(s32);
    s32 soundId;

    soundId = M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_OPERAND2);
    if (IsMessageBoxActive() == 0) {
        PlaySoundEffect(soundId);
    }
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: play the slot-pending sound named by the command's wide
 * operand, unless a message box is up.  Advances the script and keeps running. */
s32 MapScriptPlaySlotSound(void *state) {
    M2C_UNK PlaySlotPendingSound(M2C_UNK, M2C_UNK, s32);
    s32 soundId;

    soundId = M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_OPERAND2);
    if (IsMessageBoxActive() == 0) {
        PlaySlotPendingSound(0, -1, soundId);
    }
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: stop the slot sound named by the command's wide operand on
 * sound slot 0 (any slot-0 sound while a message box is up).  Advances the script
 * and keeps running. */
s32 MapScriptStopSlotSound(void *state) {
    M2C_UNK StopSlotSound(M2C_UNK, s32);
    s32 soundId;

    soundId = M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_OPERAND2);
    if (IsMessageBoxActive() != 0) {
        soundId = 0;
    }
    StopSlotSound(0, soundId);
    M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: start the music track named by the command's wide
 * operand, unless a message box is up (the command is skipped then).  Advances
 * the script and keeps it running either way. */
s32 MapScriptPlayMusic(void *state) {
    s32 result;
    s32 track = M2C_FIELD(M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP), s32 *, MAP_SCRIPT_OPERAND2);
    if (IsMessageBoxActive() != 0) result = 1;
    else { PlayMusicTrack(track); result = 0; }
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return (s16)result;
}

s32 func_02093348(void *arg0) {
    M2C_UNK FadeOutMusicOverFrames(s32);
    FadeOutMusicOverFrames(M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0xC));
    M2C_FIELD(arg0, void **, 4) = (void *) (M2C_FIELD(arg0, void **, 4) + 0x10);
    return 0;
}

void func_02093370(void *arg0) {
    s32 IsMusicFadingOut();
    if (IsMusicFadingOut() == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0;
    }
}

s32 func_0209338c(void *arg0) {
 M2C_FIELD(arg0, void (**)(void *), 8) = func_02093370;
 M2C_FIELD(arg0, s32 *, 4) += 0x10;
 return 0;
}

/* Map-script command: fade the music to the volume the command's first operand
 * names, over the number of frames in its wide operand, then advance to the next
 * command. */
s32 MapScriptFadeMusicToVolume(void *script) {
    M2C_UNK FadeMusicToVolume(s16, s32);
    void *command;

    command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    FadeMusicToVolume(M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0), M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2));
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 0;
}

s32 func_020933d8(void *arg0) {
    M2C_UNK FadeMusicToHalfVolume();
    FadeMusicToHalfVolume();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 0;
}

s32 func_020933f8(void *arg0) {
    M2C_UNK FadeMusicToFullVolume();
    FadeMusicToFullVolume();
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) + 0x10);
    return 0;
}

/* Map-script command: fade the current music out and start the current player's
 * track, then advance the script and keep running. */
s32 MapScriptPlayPlayerMusic(void *state) {
    extern void **gCurrentMap;
    s32 GetPlayerMusicTrack(s32);
    void ChangeMusicTrackWithFade(s32);
    ChangeMusicTrackWithFade(GetPlayerMusicTrack(M2C_FIELD(*gCurrentMap, u16 *, MAP_CURRENT_PLAYER) & 255));
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 0;
}

/* Map-script command: while no message box is up, duck the music to half volume
 * when the track now playing is the current player's theme.  Advances the script
 * one command and keeps running. */
s32 MapScriptDuckPlayerMusic(void *state) {
extern void **gCurrentMap;
s32 GetPlayerMusicTrack(s32);
if(IsMessageBoxActive()==0) {
s32 v=GetCurrentMusicTrack();
if(v==GetPlayerMusicTrack(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)&255)) FadeMusicToHalfVolume();
}
M2C_FIELD(state,s32 *,MAP_SCRIPT_STATE_IP)+=MAP_SCRIPT_COMMAND_SIZE;return 0;
}

/* Map-script command: bring the music back to full volume when the track now
 * playing is the current player's theme.  Advances the script one command and
 * keeps running. */
s32 MapScriptRestorePlayerMusic(void *state) {
extern void **gCurrentMap;
s32 GetPlayerMusicTrack(s32);
s32 v=GetCurrentMusicTrack();
if(v==GetPlayerMusicTrack(M2C_FIELD(*gCurrentMap,u16 *,MAP_CURRENT_PLAYER)&255)) FadeMusicToFullVolume();
M2C_FIELD(state,s32 *,MAP_SCRIPT_STATE_IP)+=MAP_SCRIPT_COMMAND_SIZE;return 0;
}

/* Map-script command: skip the next OPERAND2 commands when the army id of the
 * player named by operand 0 differs from operand 1.  The resolved player index is
 * left in r0 for func_020a8c10 (the map player record's army id) to consume.
 * Always advances one command and keeps running. */
s32 MapScriptSkipIfArmyDiffers(void *script) {
    s32 func_020a8c10();
    s16 army;
    s32 skipCount;
    void *command;

    command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    army = M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1);
    skipCount = M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2);
    MapScriptResolvePlayer((s16) M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0) >> 1);
    if ((army != func_020a8c10()) && (skipCount > 0)) {
        do {
            skipCount -= 1;
            M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
        } while (skipCount > 0);
    }
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: set the event flag the command names in MAP_SCRIPT_OPERAND0,
 * then advance to the next command. */
s32 MapScriptSetEventFlag(void *script) {
    M2C_UNK SetEventFlag(s16, M2C_UNK);
    SetEventFlag(M2C_FIELD(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND0), 1);
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script opcode: clear the event flag the command names in
 * MAP_SCRIPT_OPERAND0, then advance to the next command. */
s32 MapScriptClearEventFlag(void *script) {
    SetEventFlag(M2C_FIELD(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP), s16 *, MAP_SCRIPT_OPERAND0), 0);
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *)(M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
    return 1;
}

/* Map-script command: load the deployment (CO) file named by the command's +4
 * word, letting its units displace the ones already placed when the low byte at
 * +0xC is set, then advance the script and keep running. */
s32 MapScriptLoadDeployment(void *script) {
    void LoadDeploymentFile(s32, u8);
    void *command;

    command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    LoadDeploymentFile(M2C_FIELD(command, s32 *, 4), (u8) M2C_FIELD(command, s32 *, 0xC));
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
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
    M2C_UNK BuildMovePathForTile(M2C_UNK, M2C_UNK, s32);
    s32 CreateUnitMoveForUnit();
    M2C_UNK StartUnitMove(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov000_02169998(M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;
    u8 *u = unit;
    signed char *ptr;
    void *move;

    FloodFillUnitRange(u[1], u[2], (u32) (u[0] << 0x1A) >> 0x1A, 0x6E, 1);
    BuildMovePathForTile(x, y, (s32) *gCurrentMap + MAP_CURSOR_PATH);
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

/* Map-script command: silently remove the unit standing on the command's tile
 * (no removal effect) and refresh the map view, then advance the script. */
s32 MapScriptRemoveUnitAtCellNoEffect(void *script) {
    extern void **gCurrentMap;
    void *command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    s32 tileY = M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1);
    s32 tileX = M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0);
    void *map = *gCurrentMap;
    u8 unitId = M2C_FIELD((u8 *)map + (tileX + M2C_FIELD((u8 *)map + tileY * 2, u16 *, MAP_ROW_OFFSETS)), u8 *, MAP_CELL_UNIT_ID);
    if (unitId) {
        RefreshMapView(RemoveUnit(unitId));
    }
    M2C_FIELD(script, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 1;
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

/* Map-script command: set the turn-skip flag (PLAYER_REC_SKIP_TURN) of the
 * player named by operand 0 to the command's wide operand, then advance the
 * script and keep running. */
s32 MapScriptSetPlayerSkipTurn(void *state) {
    extern void **gCurrentMap;
    void *command = M2C_FIELD(state, void **, MAP_SCRIPT_STATE_IP);
    M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_SKIP_TURN) = M2C_FIELD(command, u32 *, MAP_SCRIPT_OPERAND2);
    M2C_FIELD(state, s32 *, MAP_SCRIPT_STATE_IP) += MAP_SCRIPT_COMMAND_SIZE;
    return 1;
}

/* Map-script command: start a screen transition (operand 0 = 0) or a fade
 * (operand 0 = 1) in the mode of operand 1, lasting the command's wide operand
 * at +0xC frames, then advance the script and keep running. */
s32 MapScriptStartScreenTransition(void *script) {
    void StartScriptedScreenTransition(s16, s16, s32);
    void *command;

    command = M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP);
    StartScriptedScreenTransition(M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND0), M2C_FIELD(command, s16 *, MAP_SCRIPT_OPERAND1), M2C_FIELD(command, s32 *, MAP_SCRIPT_OPERAND2));
    M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) = (void *) (M2C_FIELD(script, void **, MAP_SCRIPT_STATE_IP) + MAP_SCRIPT_COMMAND_SIZE);
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
    M2C_UNK ShutdownBattleMapPresentation();
    M2C_UNK RebuildSubScreenUi();
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
        ShutdownBattleMapPresentation();
        break;
    case DS3D_TARGET_SUB:
        RebuildSubScreenUi();
        break;
    case DS3D_TARGET_BOTH:
        RebuildSubScreenUi();
        ShutdownBattleMapPresentation();
        break;
    }
    M2C_FIELD(script, s32 *, 4) = (s32) (M2C_FIELD(script, s32 *, 4) + 0x10);
    return 0;
}

