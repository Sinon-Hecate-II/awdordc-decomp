/* 28 functions from 0x020C3D34 to 0x020C4D28 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
typedef struct { u8 bytes[6]; u16 half[6]; } SetupColors;
typedef struct { u32 names[15]; } SetupNames;
typedef struct { s32 v[4]; } SaveDate;
typedef struct { s32 v[3]; } SaveTime;
extern const SaveDate gDefaultProfileDate;
static inline void SaveTime_Clear(SaveTime *p) { M2C_FIELD((u32)p,s32 *,0)=0; M2C_FIELD((u32)p,s32 *,4)=0; M2C_FIELD((u32)p,s32 *,8)=0; }
static inline s32 SaveTime_Get1(SaveTime *p) { return p->v[1]; }
static inline s32 SaveTime_Get2(SaveTime *p) { return p->v[2]; }

#pragma opt_strength_reduction off
void func_020c3d34(void) {
extern void **gCurrentMap;
extern void *gBreakCutIn;
extern u16 **gCur3DSpriteEngine;
extern u16 **g3DSpriteEngineSub;
extern const SetupColors data_020f4df4;
extern const SetupNames data_020f4e08;
extern u8 data_0212a464[],data_0212a46c[],data_0212a478[],data_0212a484[],data_0212a490[],data_0212a49c[];
extern u8 data_0212a4a8[],data_0212a4b4[],data_0212a4c0[],data_0212a4cc[],data_0212a4d8[],data_0212a4f0[];
s32 GetLocalizedFileName(void *);
void *HeapAllocBlock(s32);
char buf[96]; SetupNames names; SetupColors colors;
void *map=*gCurrentMap;
void *unit=(u8*)map+0x67a4+M2C_FIELD(map,u16*,0x52a4)*140;
u32 kindWord=M2C_FIELD(unit,u32*,0x6c); u8 kind;
u8 b3=data_020f4df4.bytes[3],b4=data_020f4df4.bytes[4],b5=data_020f4df4.bytes[5];
u16 **old; u8 alpha; s32 color; s16 x0,y0,x1,y1;
names=data_020f4e08;
colors.bytes[0]=data_020f4df4.bytes[0];colors.bytes[1]=data_020f4df4.bytes[1];colors.bytes[2]=data_020f4df4.bytes[2];colors.bytes[3]=b3;colors.bytes[4]=b4;colors.bytes[5]=b5;kind=kindWord;
colors.half[0]=data_020f4df4.half[0];colors.half[1]=data_020f4df4.half[1];colors.half[2]=data_020f4df4.half[2];colors.half[3]=data_020f4df4.half[3];colors.half[4]=data_020f4df4.half[4];colors.half[5]=data_020f4df4.half[5];

gBreakCutIn=HeapAllocBlock(40);
M2C_FIELD(gBreakCutIn,s32*,0)=0;
M2C_FIELD(gBreakCutIn,u32*,0x10)=0xc3200000;
M2C_FIELD(gBreakCutIn,s16*,0x14)=0;
M2C_FIELD(gBreakCutIn,s16*,0x16)=0;
M2C_FIELD(gBreakCutIn,s16*,0x18)=255;
M2C_FIELD(gBreakCutIn,s16*,0x1a)=0;
M2C_FIELD(gBreakCutIn,s16*,8)=kind;
M2C_FIELD(gBreakCutIn,s16*,0x24)=16;
M2C_FIELD(gBreakCutIn,s16*,0x1e)=22;
M2C_FIELD(gBreakCutIn,s16*,0x22)=138;
SetFileDirectory(data_0212a464);
old=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
Apply3DSpriteLayout(colors.half);
{u16 * volatile p0=*gCur3DSpriteEngine+0;*p0=(*p0&~0)|16;}
{u16 * volatile p1=*gCur3DSpriteEngine+0;*p1=(*p1&~0)|32;}
{u16 * volatile p2=*gCur3DSpriteEngine+0;*p2=(*p2&~0)|64;}
{u16 * volatile p3=*gCur3DSpriteEngine+0;*p3=(*p3&~0)|128;}
{u16 * volatile p4=*gCur3DSpriteEngine+0;*p4=(*p4&~0)|256;}
M2C_FIELD(*gCur3DSpriteEngine,u16*,6)=(M2C_FIELD(*gCur3DSpriteEngine,u16*,6)&~3)|2;
M2C_FIELD(*gCur3DSpriteEngine,u16*,8)=(M2C_FIELD(*gCur3DSpriteEngine,u16*,8)&~3)|3;
M2C_FIELD(*gCur3DSpriteEngine,u16*,10)=(M2C_FIELD(*gCur3DSpriteEngine,u16*,10)&~3)|1;
M2C_FIELD(*gCur3DSpriteEngine,u16*,12)=(M2C_FIELD(*gCur3DSpriteEngine,u16*,12)&~3)|0;
{u16 * volatile p5=*gCur3DSpriteEngine+0;*p5=(*p5&~0)|512;}
{u16 * volatile p6=*gCur3DSpriteEngine+0;*p6=(*p6&~1024)|0;}
{u16 * volatile p7=*gCur3DSpriteEngine+0;*p7=(*p7&~2048)|0;}
{u16 * volatile p8=*gCur3DSpriteEngine+7;*p8=(*p8&~1)|1;}
{u16 * volatile p9=*gCur3DSpriteEngine+7;*p9=(*p9&~0)|2;}
{u16 * volatile p10=*gCur3DSpriteEngine+7;*p10=(*p10&~0)|4;}
{u16 * volatile p11=*gCur3DSpriteEngine+7;*p11=(*p11&~0)|8;}
{u16 * volatile p12=*gCur3DSpriteEngine+7;*p12=(*p12&~0)|16;}
{u16 * volatile p13=*gCur3DSpriteEngine+8;*p13=(*p13&~1)|1;}
{u16 * volatile p14=*gCur3DSpriteEngine+8;*p14=(*p14&~0)|2;}
{u16 * volatile p15=*gCur3DSpriteEngine+8;*p15=(*p15&~0)|4;}
{u16 * volatile p16=*gCur3DSpriteEngine+8;*p16=(*p16&~0)|8;}
{u16 * volatile p17=*gCur3DSpriteEngine+8;*p17=(*p17&~0)|16;}
{u16 * volatile p18=*gCur3DSpriteEngine+7;*p18=(*p18&~0)|32;}
{u16 * volatile p19=*gCur3DSpriteEngine+8;*p19=(*p19&~0)|32;}
x0=M2C_FIELD(gBreakCutIn,s16*,20);y0=M2C_FIELD(gBreakCutIn,s16*,22);x1=M2C_FIELD(gBreakCutIn,s16*,24);y1=M2C_FIELD(gBreakCutIn,s16*,26);
M2C_FIELD(*gCur3DSpriteEngine,u8*,72)=x0;
M2C_FIELD(*gCur3DSpriteEngine,u8*,74)=y0;
M2C_FIELD(*gCur3DSpriteEngine,u8*,73)=x1;
M2C_FIELD(*gCur3DSpriteEngine,u8*,75)=y1;
{u16 * volatile p20=*gCur3DSpriteEngine+9;*p20=(*p20&~1)|1;}
{u16 * volatile p21=*gCur3DSpriteEngine+9;*p21=(*p21&~2)|0;}
{u16 * volatile p22=*gCur3DSpriteEngine+9;*p22=(*p22&~4)|0;}
{u16 * volatile p23=*gCur3DSpriteEngine+9;*p23=(*p23&~8)|0;}
{u16 * volatile p24=*gCur3DSpriteEngine+9;*p24=(*p24&~16)|0;}
{u16 * volatile p25=*gCur3DSpriteEngine+9;*p25=(*p25&~256)|0;}
{u16 * volatile p26=*gCur3DSpriteEngine+9;*p26=(*p26&~0)|512;}
{u16 * volatile p27=*gCur3DSpriteEngine+9;*p27=(*p27&~1024)|0;}
{u16 * volatile p28=*gCur3DSpriteEngine+9;*p28=(*p28&~2048)|0;}
{u16 * volatile p29=*gCur3DSpriteEngine+9;*p29=(*p29&~4096)|0;}
{u16 * volatile p30=*gCur3DSpriteEngine+9;*p30=(*p30&~192)|64;}
alpha=M2C_FIELD(gBreakCutIn,s16*,36);
M2C_FIELD(*gCur3DSpriteEngine,u8*,81)=alpha;
M2C_FIELD(*gCur3DSpriteEngine,u8*,82)=alpha;
color=((u8*)&colors)[M2C_FIELD(unit,u8*,29)];
LoadFileToSpriteBuffer(data_0212a46c,0,128);
LoadDecompressedFileTo(data_0212a478,M2C_FIELD(gCur3DSpriteEngine,void**,12));
LoadDecompressedFileTo(data_0212a484,M2C_FIELD(gCur3DSpriteEngine,void**,16));
LoadDecompressedFileAndDrawTilemapBlock(data_0212a490,M2C_FIELD(gCur3DSpriteEngine,void**,32),0,color);
LoadDecompressedFileAndDrawTilemapBlock(data_0212a49c,M2C_FIELD(gCur3DSpriteEngine,void**,36),0,color);
M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=1;
M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=2;
LoadDecompressedFileTo(data_0212a4a8,(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,20)+32);
LoadDecompressedFileAndDrawTilemapBlock(data_0212a4b4,(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,40)+448,0,(u16)color);
M2C_FIELD(gCur3DSpriteEngine,u8*,70)|=4;
color=names.names[kind];
StringFormat(buf,data_0212a4c0,color);
LoadFileToSpriteBuffer(buf,704,32);
StringFormat(buf,data_0212a4cc,color);
OpenNarcArchive(GetLocalizedFileName(data_0212a4d8));
LoadNarcFileDecompressed(GetLocalizedFileName(buf),(u8*)M2C_FIELD(g3DSpriteEngineSub,void**,28)+2048);
CloseNarcArchive();
MI_CpuFill32(0,M2C_FIELD(gCur3DSpriteEngine,void**,24),64);
LoadFaceTexture(M2C_FIELD(gBreakCutIn,s16*,8),8,(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,24)+64);
LoadFacePalette(M2C_FIELD(gBreakCutIn,s16*,8),8,3,0,0);
LoadFaceTexture(M2C_FIELD(gBreakCutIn,s16*,8),11,(u8*)M2C_FIELD(gCur3DSpriteEngine,void**,24)+0x7840);
LoadFacePalette(M2C_FIELD(gBreakCutIn,s16*,8),11,3,1,0);
SetFileDirectory(data_0212a4f0);
gCur3DSpriteEngine=old;
}
#pragma opt_strength_reduction reset
/* Break cut-in step that ends the wait once the cut-in has run 250 frames or the
 * player presses A: resets the step counter and resumes the sprite's animation. */
void BreakCutInWaitOrSkip(M2C_UNK sprite) {
    extern u16 *gKeyState;
    extern void *gBreakCutIn;
    M2C_FIELD(gBreakCutIn, s32 *, 0)++;
    if ((M2C_FIELD(gBreakCutIn, s32 *, 0) < 250) && !(*gKeyState & KEY_A)) return;
    M2C_FIELD(gBreakCutIn, s32 *, 4) = 0;
    Sprite_ResumeAnimation(sprite);
}

/* Per-frame wait step of the break cut-in: advance the cut-in's frame counter
 * (capped at 250) and this step's own counter, then resume the sprite's animation
 * script once the step has run for 64 frames. */
void BreakCutInWaitFrames(void *sprite) {
    extern void *gBreakCutIn;
    M2C_FIELD(gBreakCutIn, s32 *, 0)++;
    M2C_FIELD(gBreakCutIn, s32 *, 4)++;
    if (M2C_FIELD(gBreakCutIn, s32 *, 0) >= 250) M2C_FIELD(gBreakCutIn, s32 *, 0) = 250;
    if (M2C_FIELD(gBreakCutIn, s32 *, 4) < 64) return;
    Sprite_ResumeAnimation(sprite);
}

/* Tear down the battle-start "break" cut-in: free its effect state and switch the
 * remaining layer flags off on the sub engine's sprite bank. */
void DestroyBreakCutIn(void) {
    M2C_UNK HeapFreeBlock(void *);
    extern void *gBreakCutIn;
    extern u16 **gCur3DSpriteEngine;
    extern u16 **g3DSpriteEngineSub;
    u16 **savedEngine;
    u16 * volatile mode5;
    u16 * volatile mode6;
    u16 * volatile mode7;

    if (gBreakCutIn != 0) {
        HeapFreeBlock(gBreakCutIn);
        gBreakCutIn = 0;
    }
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    mode5 = *gCur3DSpriteEngine;
    *mode5 = (*mode5 & ~DS3D_BANK_MODE5);
    mode6 = *gCur3DSpriteEngine;
    *mode6 = (*mode6 & ~DS3D_BANK_MODE6);
    mode7 = *gCur3DSpriteEngine;
    *mode7 = (*mode7 & ~DS3D_BANK_MODE7);
    gCur3DSpriteEngine = savedEngine;
}

void func_020c4764(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212a3cc;
    CreateSpriteObject(&data_0212a3cc, arg0);
}

s32 GetRecordProfileId(s32 arg0) {
 M2C_UNK *GetProfileSaveBlock(void);
 s32 GetPlayerRecordId(void *,s32);
 return GetPlayerRecordId((u8 *)GetProfileSaveBlock()+4,arg0);
}

/* Return the index of the first battle-save slot whose summary names no player,
 * or -1 when there is no battle save block or every slot is taken. */
s32 FindFreeBattleSaveSlot(void) {
    M2C_UNK *GetBattleSaveBlock(void);
    s32 IsPlayerRecordPresent(s32);
    s32 block;
    s32 result = -1;
    s32 slot;
    s32 record;

    block = (s32)GetBattleSaveBlock();
    if (block == 0) return result;
    record = block + SAVE_SUMMARIES_OFFSET;
    slot = 0;
    do {
        if (IsPlayerRecordPresent(record) == 0) {
            result = slot;
            break;
        }
        slot++;
        record += SAVE_SLOT_SUMMARY_SIZE;
    } while (slot < SAVE_SLOT_COUNT);
    return result;
}

/* Fill `dateTime` with the current server clock as a 4-word date followed by a
 * 3-word time; nothing is written unless an online session (overlay 2) is up and
 * the server time is known. */
void GetServerDateTime(s32 *dateTime) {
 s32 GetActiveOverlay(void);
 s32 GetServerTime(s32 *,s32 *);
 s32 date[4];
 s32 time[3];
 if (GetActiveOverlay() != 2) return;
 if (!GetServerTime(date, time)) return;
 dateTime[0] = date[0]; dateTime[1] = date[1]; dateTime[2] = date[2]; dateTime[3] = date[3];
 dateTime[4] = time[0]; dateTime[5] = time[1]; dateTime[6] = time[2];
}

/* Seconds from a saved sync stamp (an RtcDate followed by an RtcTime) to the
 * given date and time records; -1 when the stamp is out of range. */
s64 GetElapsedSeconds(s32 syncStamp, s32 *date, s32 *time) {
    s64 MakeTime(void *, void *);
    s64 sinceSync = MakeTime((void *)syncStamp, (void *)(syncStamp + DATE_TIME_TIME));

    return MakeTime(date, time) - sinceSync;
}

void func_020c488c(void *arg0) {
    M2C_UNK CreateBattleSaveSprite(s32, void *);
    CreateProfileSaveSprite(M2C_FIELD(arg0, s32 *, 0x34), arg0);
    CreateBattleSaveSprite(M2C_FIELD(arg0, s32 *, 0x38), arg0);
}

/* Save/load screen step: if the profile save's id block fails its CRC (no save
 * yet, or it is corrupt), create fresh profile and battle save blocks; otherwise
 * move the screen on to its next animation step. */
void EnsureSaveDataValid(void *sprite) {
    if (IsProfileIdBlockValid(M2C_FIELD(sprite, s32 *, SAVE_SPRITE_BLOCK)) == 0) {
        InitPlayerProfile(M2C_FIELD(sprite, s32 *, SAVE_SPRITE_BLOCK));
        InitBattleSaveRecords(M2C_FIELD(sprite, s32 **, SAVE_SPRITE_BATTLE_BLOCK));
        return;
    }
    GotoSpriteAnimationLabel(sprite, 1);
}

void func_020c48ec(void *arg0) {
    M2C_UNK CreateProfileLoadSprite(s32, void *);
    M2C_UNK CreateBattleLoadSprite(s32, void *);
    CreateProfileLoadSprite(M2C_FIELD(arg0, s32 *, 0x34), arg0);
    CreateBattleLoadSprite(M2C_FIELD(arg0, s32 *, 0x38), arg0);
}

/* Create the save/load screen object: give it its vtable and point it at the
 * local profile and battle save blocks that its save and load callbacks show. */
void CreateSaveLoadScreen(void) {
    void *CreateSpriteFromClass(M2C_UNK *, s32);
    extern M2C_UNK gSaveLoadScreenClass;
    extern M2C_UNK gSaveLoadScreenVtbl;
    extern M2C_UNK gProfileSaveBlock;
    extern M2C_UNK gBattleSaveBlock;
    void *screen = CreateSpriteFromClass(&gSaveLoadScreenClass, 7);

    if (screen == 0) return;
    M2C_FIELD(screen, M2C_UNK **, 0) = &gSaveLoadScreenVtbl;
    M2C_FIELD(screen, M2C_UNK **, 0x34) = &gProfileSaveBlock;
    M2C_FIELD(screen, M2C_UNK **, 0x38) = &gBattleSaveBlock;
}

/* Initialise the local player's profile save block: the save magic, a cleared
 * 0x40-byte profile-id block, the starting value at +0x50 and +0x54, and both
 * profile stamps set to the default date with a zeroed time. The profile-id
 * block is then filled in and its id strings formatted for the game id
 * 0x5957324A ("YW2J"). */
s32 InitPlayerProfile(s32 profile) {
void func_020323a4(void *,u32);
void func_0203287c(void *);
SaveDate defaultDate;
SaveTime timeA;
SaveDate dateA;
SaveTime timeB;
SaveDate dateB;
M2C_FIELD(profile,s32 *,0)=SAVE_BLOCK_MAGIC;
MI_CpuFill8(profile+PROFILE_ID_BLOCK,0,PROFILE_ID_BLOCK_SIZE);
M2C_FIELD(profile,s32 *,0x44)=0;
M2C_FIELD(profile,s32 *,0x48)=0;
M2C_FIELD(profile,s32 *,0x4c)=0;
M2C_FIELD(profile,s32 *,0x50)=0x5dc000;
M2C_FIELD(profile,s32 *,0x54)=0x5dc000;
defaultDate=gDefaultProfileDate;
dateA=defaultDate;
M2C_FIELD(profile,s32 *,0x58)=dateA.v[0];
M2C_FIELD(profile,s32 *,0x5c)=dateA.v[1];
M2C_FIELD(profile,s32 *,0x60)=dateA.v[2];
M2C_FIELD(profile,s32 *,0x64)=dateA.v[3];
SaveTime_Clear(&timeA);
M2C_FIELD(profile,s32 *,0x68)=0;
M2C_FIELD(profile,s32 *,0x6c)=timeA.v[1];
M2C_FIELD(profile,s32 *,0x70)=timeA.v[2];
dateB=defaultDate;
M2C_FIELD(profile,s32 *,0x74)=dateB.v[0];
M2C_FIELD(profile,s32 *,0x78)=dateB.v[1];
M2C_FIELD(profile,s32 *,0x7c)=dateB.v[2];
M2C_FIELD(profile,s32 *,0x80)=dateB.v[3];
SaveTime_Clear(&timeB);
M2C_FIELD(profile,s32 *,0x84)=0;
M2C_FIELD(profile,s32 *,0x88)=timeB.v[1];
M2C_FIELD(profile,s32 *,0x8c)=timeB.v[2];
 func_020323a4((void *)(profile+PROFILE_ID_BLOCK),PROFILE_GAME_ID_CODE);
func_0203287c((void *)(profile+PROFILE_ID_BLOCK));
return 1;
}

/* Reset the local profile-id block (the one passed in, or the global profile
 * block): reinitialise it with the game-id salt, detach the local profile from
 * every present battle-save slot by clearing that slot's joined record, then
 * refresh the block's two formatted player-code ids. */
s32 ResetProfileIdBlock(void *profileBlock) {
    M2C_UNK *GetProfileSaveBlock(void);
    void func_020323a4(void *, u32);
    s32 GetBattleSlotSummary(s32);
    void ClearPlayerRecordJoined(void);
    void func_0203287c(void *);
    s32 i;

    if (profileBlock == 0) profileBlock = GetProfileSaveBlock();
    func_020323a4((u8 *)profileBlock + PROFILE_ID_BLOCK, PROFILE_GAME_ID_CODE);
    i = 0;
    do {
        if (GetBattleSlotSummary(i) != 0) ClearPlayerRecordJoined();
        i++;
    } while (i < SAVE_SLOT_COUNT);
    func_0203287c((u8 *)profileBlock + PROFILE_ID_BLOCK);
    return 1;
}

M2C_UNK *GetProfileSaveBlock(void) {
    extern M2C_UNK gProfileSaveBlock;
    return &gProfileSaveBlock;
}

s32 InitBattleSaveRecords(s32 *saveBlock) {
    M2C_UNK FillU16(M2C_UNK, void *, M2C_UNK);
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, M2C_UNK);
    register s32 recordIndex;
    register void *recordData;
    register s32 *recordBase;

    /* Clears and initializes all 60 fixed-size battle-save records in a save block. */
    recordBase = saveBlock;
    *recordBase = 0x07090600;
    MI_CpuFill8((s32)((u8*)recordBase + 4), 0, 0x2D0);
    recordIndex = 0;
    recordData = (u8*)recordBase + 0x2D4;
    do {
        FillU16(0, recordData, 0x1A);
        M2C_FIELD(recordBase, s16 *, 0x2EE) = 0;
        M2C_FIELD(recordBase, s16 *, 0x2F0) = 0;
        M2C_FIELD(recordBase, s16 *, 0x2F2) = 0;
        M2C_FIELD(recordBase, s8 *, 0x2F4) = -1;
        M2C_FIELD(recordBase, s8 *, 0x2F5) = -2;
        recordIndex += 1;
        M2C_FIELD(recordBase, s8 *, 0x2F6) = -2;
        recordData = (u8*)recordData + 0x28;
        recordBase = (s32*)((u8*)recordBase + 0x28);
    } while (recordIndex < 0x3C);
    return 1;
}

M2C_UNK *GetBattleSaveBlock(void) {
    extern M2C_UNK gBattleSaveBlock;
    return &gBattleSaveBlock;
}

s32 IsProfileIdBlockValid(s32 arg0) {
    M2C_UNK VerifyProfileIdBlockCrc(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = GetProfileSaveBlock();
    }
    VerifyProfileIdBlockCrc(var_r0 + 4);
}

void func_020c4b88(s32 arg0) {
    M2C_UNK IsLocalProfileRecord(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = GetProfileSaveBlock();
    }
    IsLocalProfileRecord(var_r0 + 4);
}

void func_020c4ba4(s32 arg0) {
    M2C_UNK HasResolvedNasProfileKey(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = GetProfileSaveBlock();
    }
    HasResolvedNasProfileKey(var_r0 + 4);
}

void IsProfileKeySet(s32 arg0) {
    M2C_UNK func_020324e4(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = GetProfileSaveBlock();
    }
    func_020324e4(var_r0 + 4);
}

void ClearProfileNasKey(s32 arg0) {
    M2C_UNK func_02032508(s32);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = GetProfileSaveBlock();
    }
    func_02032508(var_r0 + 4);
}

/* Save a profile-save sprite's local-play user data: clear the profile's NAS key,
 * keep only the newest profile record, then queue the 0x90-byte "LinkUserData"
 * record as the profile save and start writing it. */
void SaveProfileLinkUserData(void *sprite) {
    extern M2C_UNK sLinkUserDataName;
    ClearProfileNasKey(M2C_FIELD(sprite, s32 *, SAVE_SPRITE_BLOCK));
    PruneSaveRecords(SAVE_TYPE_PLAYER, 1);
    SaveList_QueueUpdate(M2C_FIELD(sprite, s32 *, SAVE_SPRITE_BLOCK), &sLinkUserDataName, 0x90, SAVE_TYPE_PLAYER);
    SaveList_StartFlush();
}

/* Completion callback of the profile-save sprite: while the save task is still
 * running, wait for it; if the save archive turned out unusable, show the
 * missing-save-data message (which halts the game); otherwise continue the
 * sprite's animation. */
void FinishProfileSave(M2C_UNK sprite) {
    M2C_UNK Sprite_ResumeAnimation(M2C_UNK);
    s32 IsSaveTaskRunning();
    s32 IsSaveArchiveUnusable();
    M2C_UNK HaltWithMessage();
    M2C_UNK GetLocalizedText(s32);

    if (IsSaveTaskRunning() != 0) {
        return;
    }
    if (IsSaveArchiveUnusable() != 0) {
        GetLocalizedText(TEXT_ID_NO_SAVE_DATA);
        HaltWithMessage();
    }
    Sprite_ResumeAnimation(sprite);
}

/* Create the profile-save screen sprite for the new-game path: the sprite of
 * gProfileSaveSpriteClass is owned by `owner` when it is nonzero (a child of that
 * owner) or else is a layer-3 object, and the profile save block is bound to it
 * at +0x34.  A zero `saveBlock` means the local player's profile save block. */
M2C_UNK CreateProfileSaveSprite(s32 saveBlock, s32 owner) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    M2C_UNK CreateSpriteObject(M2C_UNK *, s32);
    extern M2C_UNK gProfileSaveSpriteVtbl;
    extern M2C_UNK gProfileSaveSpriteClass;
    s32 block;
    void *sprite;
    void *sprite2;

    block = saveBlock;
    if (block == 0) {
        block = (s32)GetProfileSaveBlock();
    }
    if (owner != 0) {
        sprite = (void *)CreateSpriteObject(&gProfileSaveSpriteClass, owner);
        if (sprite == NULL) {
            return;
        }
        M2C_FIELD(sprite, M2C_UNK **, 0) = &gProfileSaveSpriteVtbl;
        M2C_FIELD(sprite, s32 *, 0x34) = block;
        return;
    }
    sprite2 = CreateSpriteFromClass(&gProfileSaveSpriteClass, 3);
    if (sprite2 != NULL) {
        M2C_FIELD(sprite2, M2C_UNK **, 0) = &gProfileSaveSpriteVtbl;
        M2C_FIELD(sprite2, s32 *, 0x34) = block;
    }
}

void CreateLocalProfileSaveSprite(M2C_UNK arg0) {
    M2C_UNK CreateProfileSaveSprite(M2C_UNK, M2C_UNK);
    CreateProfileSaveSprite(0, arg0);
}

/* Write the whole battle save block held by save-screen sprite `sprite` (its block
 * is at SAVE_SPRITE_BLOCK) as the "LinkFriendData" section: keep only the newest
 * battle record, then queue and start writing the block. */
void SaveBattleSaveBlock(void *sprite) {
    M2C_UNK SaveList_QueueUpdate(s32, M2C_UNK *, s32, M2C_UNK);
    M2C_UNK PruneSaveRecords(M2C_UNK, M2C_UNK);
    M2C_UNK SaveList_StartFlush();
    extern M2C_UNK sLinkFriendDataName;

    PruneSaveRecords(SAVE_TYPE_BATTLE, 1);
    SaveList_QueueUpdate(M2C_FIELD(sprite, s32 *, SAVE_SPRITE_BLOCK), &sLinkFriendDataName, SAVE_BLOCK_SIZE, SAVE_TYPE_BATTLE);
    SaveList_StartFlush();
}

