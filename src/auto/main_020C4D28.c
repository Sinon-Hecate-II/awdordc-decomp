/* 50 functions from 0x020C4D28 to 0x020C5D0C (main), found by ds-decomp. */
#include "common.h"
static inline s32 IsNewerValue(u32 b, u32 a) {
register u32 result asm("lr") = a & 0xffff0000;
if(result==0xffff0000 && !(b&0xffff0000) && b!=0) result=0;
else if(!result && (b&0xffff0000)==0xffff0000 && a!=0) result=1;
else result=a>b;
return result;
}
extern void *gCur3DSpriteEngine;

void func_020c4d28(M2C_UNK arg0) {
    M2C_UNK Sprite_ResumeAnimation(M2C_UNK);
    s32 func_020761f8();
    s32 func_02076208();
    M2C_UNK func_02076244();
    M2C_UNK GetLocalizedText(s32);
    if (func_020761f8() != 0) {
        return;
    }
    if (func_02076208() != 0) {
        GetLocalizedText(0xC000034C);
        func_02076244();
    }
    Sprite_ResumeAnimation(arg0);
}

M2C_UNK func_020c4d64(s32 arg0, s32 arg1) {
void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
void *CreateSpriteObject(M2C_UNK *, s32);
extern M2C_UNK data_0212a65c, data_0212a53c;
s32 var_r5;
void *temp_r0;
void *temp_r0_2;
var_r5=arg0;
if(var_r5==0) var_r5=GetBattleSaveBlock();
if(arg1!=0) {
temp_r0=CreateSpriteObject(&data_0212a65c,arg1);
if(temp_r0==NULL) return;
M2C_FIELD(temp_r0,M2C_UNK **,0)=&data_0212a53c;
M2C_FIELD(temp_r0,s32 *,0x34)=var_r5;
return;
}
temp_r0_2=CreateSpriteFromClass(&data_0212a65c,3);
if(temp_r0_2!=NULL) {
M2C_FIELD(temp_r0_2,M2C_UNK **,0)=&data_0212a53c;
M2C_FIELD(temp_r0_2,s32 *,0x34)=var_r5;
}
}

void func_020c4dd0(M2C_UNK arg0) {
    M2C_UNK func_020c4d64(M2C_UNK, M2C_UNK);
    func_020c4d64(0, arg0);
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
void func_020c4ff4(M2C_UNK arg0) {
    if (func_020761f8() != 0) {
        return;
    }
    if (func_02076208() != 0) {
        GetLocalizedText(0xC000034D);
        func_02076244();
    }
    Sprite_ResumeAnimation(arg0);
}

void func_020c5030(s32 arg0, s32 arg1) {
    void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void *CreateSpriteObject(M2C_UNK *, s32);
    extern M2C_UNK data_0212a500;
    extern M2C_UNK data_0212a55c;
    s32 var_r5;
    void *temp_r0;
    void *temp_r0_2;

    var_r5 = arg0;
    if (var_r5 == 0) {
        var_r5 = func_020c4acc();
    }
    if (arg1 != 0) {
        temp_r0 = CreateSpriteObject(&data_0212a55c, arg1);
        if (temp_r0 == NULL) {
            return;
        }
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_0212a500;
        M2C_FIELD(temp_r0, s32 *, 0x34) = var_r5;
        return;
    }
    temp_r0_2 = CreateSpriteFromClass(&data_0212a55c, 3);
    if (temp_r0_2 != NULL) {
        M2C_FIELD(temp_r0_2, M2C_UNK **, 0) = &data_0212a500;
        M2C_FIELD(temp_r0_2, s32 *, 0x34) = var_r5;
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

void func_020c5230(M2C_UNK arg0) {
    if (func_020761f8() != 0) {
        return;
    }
    if (func_02076208() != 0) {
        GetLocalizedText(0xC000034D);
        func_02076244();
    }
    Sprite_ResumeAnimation(arg0);
}

M2C_UNK func_020c526c(s32 arg0, s32 arg1) {
void *CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
void *CreateSpriteObject(M2C_UNK *, s32);
extern M2C_UNK data_0212a594, data_0212a528;
s32 var_r5;
void *temp_r0;
void *temp_r0_2;
var_r5=arg0;
if(var_r5==0) var_r5=GetBattleSaveBlock();
if(arg1!=0) {
temp_r0=CreateSpriteObject(&data_0212a594,arg1);
if(temp_r0==NULL) return;
M2C_FIELD(temp_r0,M2C_UNK **,0)=&data_0212a528;
M2C_FIELD(temp_r0,s32 *,0x34)=var_r5;
return;
}
temp_r0_2=CreateSpriteFromClass(&data_0212a594,3);
if(temp_r0_2!=NULL) {
M2C_FIELD(temp_r0_2,M2C_UNK **,0)=&data_0212a528;
M2C_FIELD(temp_r0_2,s32 *,0x34)=var_r5;
}
}

void func_020c52d8(M2C_UNK arg0) {
    M2C_UNK func_020c526c(M2C_UNK, M2C_UNK);
    func_020c526c(0, arg0);
}

s32 GetBattleSlotSummary(s32 arg0) {
    s32 GetBattleSaveBlock();
    s32 temp_r0;
    s32 var_r4;

    temp_r0 = GetBattleSaveBlock();
    if (temp_r0 == 0) {
        return 0;
    }
    var_r4 = (arg0 * 0xC) + (temp_r0 + 4);
    if (IsPlayerRecordPresent(var_r4) == 0) {
        var_r4 = 0;
    }
    return var_r4;
}

#pragma optimize_for_size off
s32 func_020c5328(s32 arg0) {
s32 p=GetBattleSaveBlock();
if(p==0) return 0;
if(!IsPlayerRecordPresent(arg0*12+(p+4))) { p=0; return p; }
return arg0*40+(p+0x2d4);
}
#pragma optimize_for_size reset
s32 func_020c536c(s32 arg0, M2C_UNK arg1) {
    M2C_UNK CopyU16(M2C_UNK, s32, M2C_UNK);
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r5;

    temp_r0 = GetBattleSaveBlock();
    if (temp_r0 == 0) {
        return 0;
    }
    temp_r4 = arg0 * 0x28;
    temp_r5 = temp_r0 + 0x2D4;
    CopyU16(arg1, temp_r5 + temp_r4, 0x18);
    return temp_r5 + temp_r4;
}

s32 func_020c53ac(s32 arg0) {
s32 p=GetBattleSaveBlock();
if(!p)return 0;
p+=0x2d4;
if(M2C_FIELD(p+arg0*0x28,u16 *,0)==0)return 0;
return p+arg0*0x28;
}

void func_020c53e4(s32 arg0) {
    M2C_UNK func_02032604(s32);
    s32 func_020c4acc();
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 == 0) {
        var_r0 = func_020c4acc();
    }
    func_02032604(var_r0 + 4);
}

void CopyLocalPlayerRecord(M2C_UNK arg0) {
    M2C_UNK IsPlayerRecordPresent(M2C_UNK);
    M2C_UNK func_02032670(s32, M2C_UNK);
    func_02032670(func_020c4acc() + 4, arg0);
    IsPlayerRecordPresent(arg0);
}

void func_020c5424(void) {
    M2C_UNK func_02032634();
    func_02032634();
}

u64 GetBattleSlotMapCode(s32 arg0) {
u64 func_02032558();
if(arg0==0)return 0;
return func_02032558();
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

void func_020c5474(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02031f58(s32, M2C_UNK, M2C_UNK);
    func_02031f58(func_020c4acc() + 4, arg0, arg1);
}

s32 FormatMapCodeString(s32 arg0) {
    M2C_UNK func_02032004();
    func_02032004();
    return arg0;
}

void func_020c54ac(void) {
    M2C_UNK ParseFriendCodeDigits();
    ParseFriendCodeDigits();
}

s32 CanModifyBattleSave(void) {
    s32 func_0203a8dc();
    s32 GetActiveOverlay();
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    if (GetActiveOverlay() != 2) {
        return 1;
    }
    if (IsOnlineSessionFlagSet(2) == 0) {
        return 1;
    }
    return func_0203a8dc();
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

void func_020c5618(s32 arg0) {
u8 sp0[12];
func_02032634(sp0);
CreateBattleSaveSlot(arg0,(s32)sp0);
}

s32 func_020c5640(M2C_UNK arg0) {
    s32 func_020c4798();
    s32 CreateBattleSaveSlot(s32, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_020c4798();
    if (temp_r0 < 0) {
        return -1;
    }
    return CreateBattleSaveSlot(temp_r0, arg0);
}

#pragma opt_common_subs off
s32 func_020c5664(s32 arg0) {
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
s32 func_020c5708(s32 arg0) {
    s32 GetRecordProfileId(s32);
    s32 temp_r0;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;

    var_r4 = -1;
    if (arg0 < 0) {
        return -1;
    }
    temp_r0 = GetBattleSaveBlock();
    if (temp_r0 == 0) {
        return -1;
    }
    var_r6 = temp_r0 + 4;
    var_r5 = 0;
loop_5:
    if ((IsPlayerRecordPresent(var_r6) != 0) && (arg0 == GetRecordProfileId(var_r6))) {
        var_r4 = var_r5;
    } else {
        var_r5 += 1;
        var_r6 += 0xC;
        if (var_r5 < 0x3C) {
            goto loop_5;
        }
    }
    return var_r4;
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

void func_020c5b24(void) {
    extern M2C_UNK gBattleHelpPanel;
    extern void **gCurrentMap;
    M2C_FIELD(&gBattleHelpPanel, s16 *, 2) = (s16) M2C_FIELD(*gCurrentMap, s16 *, 0x52D8);
    M2C_FIELD(&gBattleHelpPanel, s16 *, 4) = (s16) M2C_FIELD(*gCurrentMap, s16 *, 0x52DA);
}

void func_020c5b5c(void) {
extern M2C_UNK gBattleHelpPanel;
extern void **gCurrentMap;
M2C_FIELD(*gCurrentMap,s16 *,0x52d8)=M2C_FIELD(&gBattleHelpPanel,s16 *,2);
M2C_FIELD(*gCurrentMap,s16 *,0x52da)=M2C_FIELD(&gBattleHelpPanel,s16 *,4);
}

#pragma opt_common_subs off
M2C_UNK func_020c5b98(s32 a) {
 void func_020c08f8(s32,s32,s32,s32,s32);void func_0209bfa8(void);void ClearTileRect(void*,s32,s32);void func_0209b26c(s32,s32,s32,s32,s32,u16);
 extern M2C_UNK gBattleHelpPanel;
 s32 tile; s16 index;
 func_020c08f8(7,18,18,6,1);
 func_0209bfa8();
 ClearTileRect((u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0x24)+0x48e,18,6);
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0x3a)=0;
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0x42)=0;
 M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
 if(a) { index=M2C_FIELD(&gBattleHelpPanel,u8*,0); tile=index*(s16)56+0x124; func_0209b26c(8,19,1,a,0,(u16)tile); }
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

s32 func_020c5cac(void) {
    extern u16 gMapConfig;
    if ((u8) ((u32) (gMapConfig << 0x1D) >> 0x1D) == 1) {
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

