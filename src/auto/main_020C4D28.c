/* 50 functions from 0x020C4D28 to 0x020C5D0C (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov009_link.h"
static inline s32 IsNewerValue(u32 b, u32 a) {
register u32 result asm("lr") = a & 0xffff0000;
if(result==0xffff0000 && !(b&0xffff0000) && b!=0) result=0;
else if(!result && (b&0xffff0000)==0xffff0000 && a!=0) result=1;
else result=a>b;
return result;
}
extern void *gCur3DSpriteEngine;

/* Completion callback of the battle-save sprite: while the save task is still
 * running, wait for it; if the save archive turned out unusable, show the
 * missing-save-data message (which halts the game); otherwise continue the
 * sprite's animation. */
void FinishBattleSave(M2C_UNK sprite) {
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

/* Create the battle-save screen sprite for the new-game path: the sprite of
 * gBattleSaveSpriteClass is owned by `owner` when it is nonzero (a child of that
 * owner) or else is a layer-3 object, and the battle save block is bound to it at
 * +0x34.  A zero `saveBlock` means the local battle save block. */
M2C_UNK CreateBattleSaveSprite(s32 saveBlock, s32 owner) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *CreateSpriteObject(M2C_UNK *, s32);
    extern M2C_UNK gBattleSaveSpriteVtbl;
    extern M2C_UNK gBattleSaveSpriteClass;
    s32 block;
    void *sprite;
    void *sprite2;

    block = saveBlock;
    if (block == 0) {
        block = GetBattleSaveBlock();
    }
    if (owner != 0) {
        sprite = CreateSpriteObject(&gBattleSaveSpriteClass, owner);
        if (sprite == NULL) {
            return;
        }
        M2C_FIELD(sprite, M2C_UNK **, 0) = &gBattleSaveSpriteVtbl;
        M2C_FIELD(sprite, s32 *, 0x34) = block;
        return;
    }
    sprite2 = CreateSpriteFromClass(&gBattleSaveSpriteClass, 3);
    if (sprite2 != NULL) {
        M2C_FIELD(sprite2, M2C_UNK **, 0) = &gBattleSaveSpriteVtbl;
        M2C_FIELD(sprite2, s32 *, 0x34) = block;
    }
}

void CreateLocalBattleSaveSprite(M2C_UNK arg0) {
    M2C_UNK CreateBattleSaveSprite(M2C_UNK, M2C_UNK);
    CreateBattleSaveSprite(0, arg0);
}

#pragma push
#pragma opt_strength_reduction off
void func_020c4de4(void *arg0) {
    M2C_UNK MI_CpuFill8(void *, s32, s32);
    void *GetSaveRecordList(void);
    s32 GetSaveRecordCount(void);
    s32 GetSaveRecordSize(u16);
    s32 LoadSaveRecord(u16, void *);
    typedef struct { s32 v[4]; } SaveDate;
    typedef struct { s32 v[3]; } SaveTime;
    extern const SaveDate gDefaultProfileDate;
#define SaveTime_Clear(p) do { M2C_FIELD((u32)(p), s32 *, 0) = 0; M2C_FIELD((u32)(p), s32 *, 4) = 0; M2C_FIELD((u32)(p), s32 *, 8) = 0; } while (0)
    u8 *p, *best;
    s32 n, i, id;
    void *base;
    SaveDate initial;
    SaveTime b;
    SaveDate a;
    SaveTime d;
    SaveDate c;

    p = GetSaveRecordList();
    best = 0;
    n = GetSaveRecordCount();
    i = 0;
    if (n > 0) {
        do {
            if (p[2] == 2) {
                if (best) {
                    u32 bv=M2C_FIELD(best,u32 *,4), av=M2C_FIELD(p,u32 *,4);
                    s32 result=av & 0xffff0000;
                    if(result==0xffff0000 && !(bv&0xffff0000) && bv!=0)result=0;
                    else if(!result && (bv&0xffff0000)==0xffff0000 && av!=0)result=1;
                    else result=av>bv;
                    if(!result)goto skip_next;
                }
                best = p;
            }
            skip_next:
            i++;
            p += 0x28;
        } while (i < n);
    }
    if (best) id = *(u16 *)best; else id = -1;
    if (id != -1 && GetSaveRecordSize((u16)id) == 0x90) {
        LoadSaveRecord((u16)id, M2C_FIELD(arg0, void **, 0x34));
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x34), s32 *, 0) == 0x07090600) {
            return;
        }
    }
    base = M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(base, s32 *, 0) = 0x07090600;
    MI_CpuFill8((u8 *)base + 4, 0, 0x40);
    M2C_FIELD(base, s32 *, 0x44) = 0;
    M2C_FIELD(base, s32 *, 0x48) = 0;
    M2C_FIELD(base, s32 *, 0x4C) = 0;
    M2C_FIELD(base, s32 *, 0x50) = 0x5dc000;
    M2C_FIELD(base, s32 *, 0x54) = 0x5dc000;
    initial = gDefaultProfileDate;
    a = initial;
    M2C_FIELD(base, s32 *, 0x58) = a.v[0];
    M2C_FIELD(base, s32 *, 0x5C) = a.v[1];
    M2C_FIELD(base, s32 *, 0x60) = a.v[2];
    M2C_FIELD(base, s32 *, 0x64) = a.v[3];
    SaveTime_Clear(&b);
    M2C_FIELD(base, s32 *, 0x68) = 0;
    M2C_FIELD(base, s32 *, 0x6C) = b.v[1];
    M2C_FIELD(base, s32 *, 0x70) = b.v[2];
    c = initial;
    M2C_FIELD(base, s32 *, 0x74) = c.v[0];
    M2C_FIELD(base, s32 *, 0x78) = c.v[1];
    M2C_FIELD(base, s32 *, 0x7C) = c.v[2];
    M2C_FIELD(base, s32 *, 0x80) = c.v[3];
    SaveTime_Clear(&d);
    M2C_FIELD(base, s32 *, 0x84) = 0;
    M2C_FIELD(base, s32 *, 0x88) = d.v[1];
    M2C_FIELD(base, s32 *, 0x8C) = d.v[2];
}
#pragma pop
/* Completion callback of the profile-load sprite: while the load/save task is
 * still running, wait for it; if the save archive turned out unusable, show the
 * save-load failure message (which halts the game); otherwise continue the
 * sprite's animation. */
void FinishProfileLoad(M2C_UNK sprite) {
    if (IsSaveTaskRunning() != 0) {
        return;
    }
    if (IsSaveArchiveUnusable() != 0) {
        GetLocalizedText(TEXT_ID_SAVE_LOAD_FAILED);
        HaltWithMessage();
    }
    Sprite_ResumeAnimation(sprite);
}

/* Create the profile display sprite for the load/continue path: the sprite of
 * gProfileLoadSpriteClass is owned by `owner` when it is nonzero (a child of that
 * owner) or else is a layer-3 object, and the profile save block is bound to it at
 * +0x34.  A zero `profileBlock` means the local player's profile save block. */
void CreateProfileLoadSprite(s32 profileBlock, s32 owner) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *CreateSpriteObject(M2C_UNK *, s32);
    extern M2C_UNK gProfileLoadSpriteVtbl;
    extern M2C_UNK gProfileLoadSpriteClass;
    s32 block;
    void *sprite;
    void *sprite2;

    block = profileBlock;
    if (block == 0) {
        block = GetProfileSaveBlock();
    }
    if (owner != 0) {
        sprite = CreateSpriteObject(&gProfileLoadSpriteClass, owner);
        if (sprite == NULL) {
            return;
        }
        M2C_FIELD(sprite, M2C_UNK **, 0) = &gProfileLoadSpriteVtbl;
        M2C_FIELD(sprite, s32 *, 0x34) = block;
        return;
    }
    sprite2 = CreateSpriteFromClass(&gProfileLoadSpriteClass, 3);
    if (sprite2 != NULL) {
        M2C_FIELD(sprite2, M2C_UNK **, 0) = &gProfileLoadSpriteVtbl;
        M2C_FIELD(sprite2, s32 *, 0x34) = block;
    }
}

/* Restores the newest type-3 battle save into the save buffer at obj+0x34, or,
 * when there is no complete one, fills in an empty block: the magic word, 60
 * cleared slot summaries and 60 cleared slot records. */
void LoadOrInitBattleSave(void *obj){
M2C_UNK FillU16(s32,s32,s32);M2C_UNK MI_CpuFill8(void *,s32,s32);s32 LoadSaveRecord(u16,void *);s32 GetSaveRecordSize(u16);
void *GetSaveRecordList(void);s32 GetSaveRecordCount(void);
u8 *p,*best;s32 n,i,id,isNewer;s32 slot;void *slotRecord,*block;
p=GetSaveRecordList();best=0;n=GetSaveRecordCount();i=0;
if(n>0)do{if(p[SAVE_RECORD_TYPE]==SAVE_TYPE_BATTLE){if(best){isNewer=IsNewerValue(M2C_FIELD(best,u32 *,SAVE_RECORD_TIME),M2C_FIELD(p,u32 *,SAVE_RECORD_TIME));if(!isNewer)goto next;}best=p;}next:i++;p+=SAVE_RECORD_STRIDE;}while(i<n);
if(best)id=*(u16 *)best;else id=-1;
if(id!=-1 && GetSaveRecordSize((u16)id)==SAVE_BLOCK_SIZE){
LoadSaveRecord((u16)id,M2C_FIELD(obj,void **,0x34));
if(M2C_FIELD(M2C_FIELD(obj,void **,0x34),s32 *,0)==SAVE_BLOCK_MAGIC)return;
}
block=M2C_FIELD(obj,void **,0x34);*(s32 *)block=SAVE_BLOCK_MAGIC;MI_CpuFill8(block+SAVE_SUMMARIES_OFFSET,0,SAVE_SLOT_COUNT*SAVE_SLOT_SUMMARY_SIZE);
slot=0;slotRecord=block+SAVE_RECORDS_OFFSET;
do{FillU16(0,slotRecord,26);
M2C_FIELD(block,s16 *,0x2ee)=0;M2C_FIELD(block,s16 *,0x2f0)=0;M2C_FIELD(block,s16 *,0x2f2)=0;
M2C_FIELD(block,s8 *,0x2f4)=-1;M2C_FIELD(block,s8 *,0x2f5)=-2;slot++;M2C_FIELD(block,s8 *,0x2f6)=-2;slotRecord+=SAVE_SLOT_RECORD_SIZE;block+=SAVE_SLOT_RECORD_SIZE;
}while(slot<SAVE_SLOT_COUNT);
}

/* Completion callback of the battle-load sprite: while the load task is still
 * running, wait for it; if the save archive turned out unusable, show the
 * save-load failure message (which halts the game); otherwise continue the
 * sprite's animation. */
void FinishBattleLoad(M2C_UNK sprite) {
    if (IsSaveTaskRunning() != 0) {
        return;
    }
    if (IsSaveArchiveUnusable() != 0) {
        GetLocalizedText(TEXT_ID_SAVE_LOAD_FAILED);
        HaltWithMessage();
    }
    Sprite_ResumeAnimation(sprite);
}

/* Create the battle-save display sprite for the load/continue path: the sprite of
 * gBattleLoadSpriteClass is owned by `owner` when it is nonzero (a child of that
 * owner) or else is a layer-3 object, and the battle save block is bound to it at
 * +0x34.  A zero `saveBlock` means the local player's battle save block. */
M2C_UNK CreateBattleLoadSprite(s32 saveBlock, s32 owner) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *CreateSpriteObject(M2C_UNK *, s32);
    extern M2C_UNK gBattleLoadSpriteVtbl;
    extern M2C_UNK gBattleLoadSpriteClass;
    s32 block;
    void *sprite;
    void *sprite2;

    block = saveBlock;
    if (block == 0) {
        block = GetBattleSaveBlock();
    }
    if (owner != 0) {
        sprite = CreateSpriteObject(&gBattleLoadSpriteClass, owner);
        if (sprite == NULL) {
            return;
        }
        M2C_FIELD(sprite, M2C_UNK **, 0) = &gBattleLoadSpriteVtbl;
        M2C_FIELD(sprite, s32 *, 0x34) = block;
        return;
    }
    sprite2 = CreateSpriteFromClass(&gBattleLoadSpriteClass, 3);
    if (sprite2 != NULL) {
        M2C_FIELD(sprite2, M2C_UNK **, 0) = &gBattleLoadSpriteVtbl;
        M2C_FIELD(sprite2, s32 *, 0x34) = block;
    }
}

void func_020c52d8(M2C_UNK arg0) {
    M2C_UNK CreateBattleLoadSprite(M2C_UNK, M2C_UNK);
    CreateBattleLoadSprite(0, arg0);
}

/* Return battle-save slot `slot`'s 12-byte summary, or NULL when there is no
 * battle save block or the slot holds no player record. */
s32 GetBattleSlotSummary(s32 slot) {
    s32 GetBattleSaveBlock();
    s32 block;
    s32 summary;

    block = GetBattleSaveBlock();
    if (block == 0) {
        return 0;
    }
    summary = (slot * SAVE_SLOT_SUMMARY_SIZE) + (block + SAVE_SUMMARIES_OFFSET);
    if (IsPlayerRecordPresent(summary) == 0) {
        summary = 0;
    }
    return summary;
}

#pragma optimize_for_size off
/* Return the 40-byte battle-save slot record for `slot` (SAVE_SLOT_RECORD_SIZE
 * bytes at SAVE_RECORDS_OFFSET), or NULL when there is no battle save block or
 * the slot holds no player record. */
s32 GetBattleSlotRecord(s32 slot) {
s32 block=GetBattleSaveBlock();
if(block==0) return 0;
if(!IsPlayerRecordPresent(slot*SAVE_SLOT_SUMMARY_SIZE+(block+SAVE_SUMMARIES_OFFSET))) { block=0; return block; }
return slot*SAVE_SLOT_RECORD_SIZE+(block+SAVE_RECORDS_OFFSET);
}
#pragma optimize_for_size reset
/* Copy the 0x18-byte player record at `record` into battle-save slot `slot`'s
 * record (SAVE_SLOT_RECORD_SIZE bytes at SAVE_RECORDS_OFFSET) and return that
 * slot record, or NULL when there is no battle save block. */
s32 SetBattleSlotRecord(s32 slot, M2C_UNK record) {
    M2C_UNK CopyU16(M2C_UNK, s32, M2C_UNK);
    s32 block;
    s32 offset;
    s32 recordBase;

    block = GetBattleSaveBlock();
    if (block == 0) {
        return 0;
    }
    offset = slot * SAVE_SLOT_RECORD_SIZE;
    recordBase = block + SAVE_RECORDS_OFFSET;
    CopyU16(record, recordBase + offset, 0x18);
    return recordBase + offset;
}

/* Return battle-save slot `slot`'s custom name text (the 26-byte text at the
 * start of its 0x28-byte slot record), or NULL when there is no battle save
 * block or the slot holds no custom name. */
s32 GetBattleSlotCustomName(s32 slot) {
    s32 records = GetBattleSaveBlock();
    if (!records) return 0;
    records += SAVE_RECORDS_OFFSET;
    if (M2C_FIELD(records + slot * SAVE_SLOT_RECORD_SIZE, u16 *, 0) == 0) return 0;
    return records + slot * SAVE_SLOT_RECORD_SIZE;
}

void GetOwnFriendCode(s32 arg0) {
    M2C_UNK BuildProfilePlayerCode(s32);
    s32 GetProfileSaveBlock();
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = GetProfileSaveBlock();
    }
    BuildProfilePlayerCode(var_r0 + 4);
}

/* Copy the local player's 12-byte identity record out of the profile save
 * block's profile-id block into `record`, and return whether that record is
 * present (its kind is nonzero). */
s32 CopyLocalPlayerRecord(void *record) {
    M2C_UNK IsPlayerRecordPresent(M2C_UNK);
    M2C_UNK GetLocalPlayerRecord(s32, M2C_UNK);
    GetLocalPlayerRecord(GetProfileSaveBlock() + PROFILE_ID_BLOCK, record);
    return IsPlayerRecordPresent(record);
}

void func_020c5424(void) {
    M2C_UNK InitPlayerCodeRecord();
    InitPlayerCodeRecord();
}

u64 GetBattleSlotMapCode(s32 arg0) {
u64 GetPlayerRecordCode();
if(arg0==0)return 0;
return GetPlayerRecordCode();
}

s32 func_020c544c(s32 arg0) {
    s32 GetPlayerRecordType();
    if (arg0 == 0) {
        return 0;
    }
    return GetPlayerRecordType();
}

void func_020c5464(void) {
    M2C_UNK func_020c544c();
    M2C_UNK GetBattleSlotSummary();
    GetBattleSlotSummary();
    func_020c544c();
}

/* Whether `code` is a valid player (friend) code for this profile's game id: the
 * game id is read from the profile-id block GetProfileSaveBlock returns. */
s32 IsPlayerCodeValidForProfile(u64 code) {
    M2C_UNK func_02031f58(s32, u64);
    return func_02031f58(GetProfileSaveBlock() + 4, code);
}

s32 FormatMapCodeString(s32 arg0) {
    M2C_UNK FormatPlayerCode();
    FormatPlayerCode();
    return arg0;
}

void func_020c54ac(void) {
    M2C_UNK ParseFriendCodeDigits();
    ParseFriendCodeDigits();
}

/* Whether the battle save may be modified right now: always outside an online
 * session, and inside one only while it is still making a match (once the match
 * session has settled the save is locked). */
s32 CanModifyBattleSave(void) {
    s32 MatchSession_IsSettled();
    s32 GetActiveOverlay();
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    if (GetActiveOverlay() != NET_OVERLAY_ONLINE) {
        return 1;
    }
    if (IsOnlineSessionFlagSet(OV010_FLAG_MATCHMAKING) == 0) {
        return 1;
    }
    return MatchSession_IsSettled();
}

/* Whether the battle save block already holds a slot for this 12-byte NAS player
 * record: a valid slot summary that equals the record, or carries the same
 * profile id, means the player already has a battle save. */
s32 BattleSaveSlotInUse(s32 playerRecord) {
    s32 PlayerRecordsEqual(s32, s32);
    s32 summary, result = 0, slot, profileId;

    summary = GetBattleSaveBlock();
    if (summary == 0) return result;
    slot = result;
    profileId = GetRecordProfileId(playerRecord);
    summary += SAVE_SUMMARIES_OFFSET;
    do {
        if (IsPlayerRecordPresent(summary) != 0 && (PlayerRecordsEqual(summary, playerRecord) != 0 || (profileId > 0 && profileId == GetRecordProfileId(summary)))) { result = 1; break; }
        slot++;
        summary += SAVE_SLOT_SUMMARY_SIZE;
    } while (slot < SAVE_SLOT_COUNT);
    return result;
}

/* Registers a battle save in a slot: stores the 12-byte slot summary and
 * clears the slot's record, marking its tail fields empty. Returns the slot
 * index, or -1 when saving is not allowed or the slot is already in use. */
s32 CreateBattleSaveSlot(s32 slot, M2C_UNK summary) {
    M2C_UNK FillU16(M2C_UNK, s32, M2C_UNK);
    M2C_UNK MI_CpuCopy8(M2C_UNK, s32, u32);
    s32 CanModifyBattleSave(void);
    s32 BattleSaveSlotInUse(M2C_UNK);
    s32 GetBattleSaveBlock(void);
    void *block;
    s32 offset;

    if (CanModifyBattleSave() == 0) return -1;
    if (BattleSaveSlotInUse(summary) != 0) return -1;
    block = (void *)GetBattleSaveBlock();
    if (!block) return -1;
    MI_CpuCopy8(summary, block + SAVE_SUMMARIES_OFFSET + slot * SAVE_SLOT_SUMMARY_SIZE, SAVE_SLOT_SUMMARY_SIZE);
    offset = slot * SAVE_SLOT_RECORD_SIZE;
    FillU16(0, block + SAVE_RECORDS_OFFSET + offset, 0x1a);
    {
        /* the record's tail: counts at +0x1A..+0x1E, then three empty markers */
        void *record = block + offset;
        M2C_FIELD(record, s16 *, 0x2ee) = 0;
        M2C_FIELD(record, s16 *, 0x2f0) = 0;
        M2C_FIELD(record, s16 *, 0x2f2) = 0;
        M2C_FIELD(record, s8 *, 0x2f4) = -1;
        M2C_FIELD(record, s8 *, 0x2f5) = -2;
        M2C_FIELD(record, s8 *, 0x2f6) = -2;
    }
    return slot;
}

/* Create a battle save in `slot` under the 64-bit player code given as its low
 * and high words: build the slot's player-code record and register it. */
void CreateBattleSaveSlotForPlayer(s32 slot, u32 codeLow, u32 codeHigh) {
    u8 summary[12];

    InitPlayerCodeRecord(summary, codeLow, codeHigh);
    CreateBattleSaveSlot(slot, (s32) summary);
}

/* Find a free battle-save slot and register a battle save there from the 12-byte
 * slot summary `summary`; returns the slot index, or -1 when no slot is free. */
s32 CreateBattleSaveInFreeSlot(void *summary) {
    s32 FindFreeBattleSaveSlot();
    s32 CreateBattleSaveSlot(s32, M2C_UNK);
    s32 slot;

    slot = FindFreeBattleSaveSlot();
    if (slot < 0) {
        return -1;
    }
    return CreateBattleSaveSlot(slot, (M2C_UNK) summary);
}

#pragma opt_common_subs off
s32 DeleteBattleSaveSlot(s32 arg0) {
s32 base,p,off,result;
if(!CanModifyBattleSave()) return 0;
result=0;
base=GetBattleSaveBlock();
if(!base)return result;
p=GetBattleSlotSummary(arg0);
if(p && IsPlayerRecordPresent(p)) {
ReleasePlayerRecord(p);
off=arg0*0x28;
FillU16(result,base+0x2d4+off,0x1a);
p=base+off;
M2C_FIELD(p,s16 *,0x2ee)=result;
M2C_FIELD(p,s16 *,0x2f0)=result;
M2C_FIELD(p,s16 *,0x2f2)=result;
M2C_FIELD(p,s8 *,0x2f4)=result-1;
M2C_FIELD(p,s8 *,0x2f5)=result-2;
M2C_FIELD(p,s8 *,0x2f6)=result-2;
result=1;
}
return result;
}
#pragma opt_common_subs reset
/* Return the index of the battle-save slot whose summary carries this profile
 * id, or -1 when there is no battle save block or no slot has the player. */
s32 FindBattleSaveSlotByProfileId(s32 profileId) {
    s32 GetRecordProfileId(s32);
    s32 block;
    s32 result;
    s32 slot;
    s32 summary;

    result = -1;
    if (profileId < 0) {
        return -1;
    }
    block = GetBattleSaveBlock();
    if (block == 0) {
        return -1;
    }
    summary = block + SAVE_SUMMARIES_OFFSET;
    slot = 0;
loop:
    if ((IsPlayerRecordPresent(summary) != 0) && (profileId == GetRecordProfileId(summary))) {
        result = slot;
    } else {
        slot += 1;
        summary += SAVE_SLOT_SUMMARY_SIZE;
        if (slot < SAVE_SLOT_COUNT) {
            goto loop;
        }
    }
    return result;
}

double func_0206e2d8(double, double);
s32 FX_Div(s32, s32);
s32 func_02001fc4(s32);
void ConvergeSyncedPositions(s32 mode, s32 *first, s32 *second)
{
    s32 start, end, forward, backward;

    end = *second;
    start = *first;
    forward = FX_Div(end - start, POS_CONVERGE_SCALE);
    backward = FX_Div(start - end, POS_CONVERGE_SCALE);
    {
        float rounded;
        if ((float)func_0206e2d8(10.0, (double)((float)forward / 4096.0f)) > 0.0f) {
            rounded = 0.5f + 4096.0f * (float)func_0206e2d8(10.0, (double)((float)forward / 4096.0f));
        } else {
            rounded = 4096.0f * (float)func_0206e2d8(10.0, (double)((float)forward / 4096.0f)) - 0.5f;
        }
        forward = (s32)rounded;
    }
    {
        float rounded;
        if ((float)func_0206e2d8(10.0, (double)((float)backward / 4096.0f)) > 0.0f) {
            rounded = 0.5f + 4096.0f * (float)func_0206e2d8(10.0, (double)((float)backward / 4096.0f));
        } else {
            rounded = 4096.0f * (float)func_0206e2d8(10.0, (double)((float)backward / 4096.0f)) - 0.5f;
        }
        backward = (s32)rounded;
    }
    forward = func_02001fc4(forward + POS_FX_ONE);
    backward = func_02001fc4(backward + POS_FX_ONE);
    switch (mode) {
    case 0:
        *first += (s32)(((long long)(POS_FX_ONE - forward) * POS_CONVERGE_CELL + 0x800) >> 12);
        *second += (s32)(((long long)-backward * POS_CONVERGE_CELL + 0x800) >> 12);
        break;
    case 1:
        *first += (s32)(((long long)-forward * POS_CONVERGE_CELL + 0x800) >> 12);
        *second += (s32)(((long long)(POS_FX_ONE - backward) * POS_CONVERGE_CELL + 0x800) >> 12);
        break;
    case 2:
        *first += (s32)(((long long)(POS_FX_HALF - forward) * POS_CONVERGE_CELL + 0x800) >> 12);
        *second += (s32)(((long long)(POS_FX_HALF - backward) * POS_CONVERGE_CELL + 0x800) >> 12);
        break;
    }
}

s32 func_020c5aac(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_020c5ac0(void) {

}

void func_020c5ac4(void) {

}

s32 func_020c5ac8(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_020c5adc(void) {

}

s32 func_020c5ae0(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_020c5af4(void) {

}

s32 func_020c5af8(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_020c5b0c(void) {

}

s32 func_020c5b10(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

/* Remember where the battle cursor was (the map's pre-move cursor position) so
 * RestoreBattleCursorPosition can put it back after the help panel has moved it. */
void SaveBattleCursorPosition(void) {
    extern M2C_UNK gBattleHelpPanel;
    extern void **gCurrentMap;
    M2C_FIELD(&gBattleHelpPanel, s16 *, MAP_HELP_SAVED_X) = (s16) M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_OLD_X);
    M2C_FIELD(&gBattleHelpPanel, s16 *, MAP_HELP_SAVED_Y) = (s16) M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_OLD_Y);
}

/* Put the battle cursor back where it was before the help panel took it over,
 * from the position SaveBattleCursorPosition saved. */
void RestoreBattleCursorPosition(void) {
    extern M2C_UNK gBattleHelpPanel;
    extern void **gCurrentMap;

    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_OLD_X) = M2C_FIELD(&gBattleHelpPanel, s16 *, MAP_HELP_SAVED_X);
    M2C_FIELD(*gCurrentMap, s16 *, MAP_CURSOR_OLD_Y) = M2C_FIELD(&gBattleHelpPanel, s16 *, MAP_HELP_SAVED_Y);
}

#pragma opt_common_subs off
M2C_UNK func_020c5b98(s32 a) {
 void DrawWindowFrame(s32,s32,s32,s32,s32);void DeleteTextLineSprites(void);void ClearTileRect(void*,s32,s32);void DrawLocalizedText(s32,s32,s32,s32,s32,u16);
 extern M2C_UNK gBattleHelpPanel;
 s32 tile; s16 index;
 DrawWindowFrame(7,18,18,6,1);
 DeleteTextLineSprites();
 ClearTileRect((u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0x24)+0x48e,18,6);
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0x3a)=0;
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0x42)=0;
 M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
 if(a) { index=M2C_FIELD(&gBattleHelpPanel,u8*,0); tile=index*(s16)56+0x124; DrawLocalizedText(8,19,1,a,0,(u16)tile); }
 M2C_FIELD(&gBattleHelpPanel,u8*,0)=(M2C_FIELD(&gBattleHelpPanel,u8*,0)+1)&1;
}
#pragma opt_common_subs reset
void func_020c5c78(void *arg0) {
    
    func_020c5b98(M2C_FIELD(arg0, s32 *, 0x20));
}

void func_020c5c88(void) {
    M2C_UNK DeleteMapMenuSprites();
    DeleteMapMenuSprites();
}

void func_020c5c94(M2C_UNK arg0, M2C_UNK arg1) {
M2C_UNK func_020c0b88(M2C_UNK);
M2C_UNK func_020c7568();
func_020c0b88(arg1);
DeleteMapMenuSprites();
func_020c7568();
}

/* Availability of a battle-menu entry that only free-play battles offer: 0
 * (available) when gMapConfig's battle mode is free play, 2 (hidden) in any
 * other mode. */
s32 CanUseFreePlayOnlyCommand(void) {
    extern u16 gMapConfig;

    if ((u8) ((u32) (M2C_FIELD(&gMapConfig, u16 *, MAPCONFIG_MODE) << 0x1D) >> 0x1D) == MAPDATA_MODE_FREE_PLAY) {
        return 0;
    }
    return 2;
}

s32 func_020c5cd4(void) {
    extern u8 gBattleEndState;
    if (gBattleEndState != 0) {
        return 0;
    }
    return 2;
}

s32 func_020c5cf0(void) {
extern u8 gBattleEndState;
if(gBattleEndState) return 2;
return 0;
}

