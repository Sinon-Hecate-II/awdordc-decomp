/* 29 functions from 0x020B4264 to 0x020B5258 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

/* Base of the current map data: the global map pointer holds it at offset 0. */
#define MAPBASE ((u8 *)M2C_FIELD(gCurrentMap, u8 **, 0))

/* Four consecutive words, copied as one 16-byte block. */
typedef struct { u32 w0; u32 w1; u32 w2; u32 w3; } MapQuad;

#pragma opt_strength_reduction off
s32 func_020b4264(u8 *arg0) {
    void LoadMapTileset(void);
    s32 GetMapPlayerCount(s32);
    s32 GetMapName(s32);
    void StringCopy(u8 *, s32);
    void LoadMapTileData(s32);
    void BuildMapRowOffsets(void);
    void FreeMapTileData(void);
    void ApplyTerrainBlast(s32, s32);
    void SetPlayerTeam(s32, s32);
    void SetPlayerIdForSlot(s32, s32);
    void SetPlayerArmyId(s32, s32);
    void func_020a233c(s32, s32);
    void func_020a44fc(u8 *, s32);
    void DecodeTerrainHitPoints(u8 *);
    extern void *gCurrentMap;
    extern M2C_UNK data_0215d9b8;
    extern M2C_UNK gMapConfig;
    extern M2C_UNK gMapData;
    u8 *src;
    u8 *dst;
    u8 *unit;
    u8 *ps;
    u8 *pd;
    u16 v;
    u32 n;
    s32 i;
    u8 *rec;
    s32 j;
    s32 x;
    s32 y;
    u8 *map;
    u32 namePairs;

    M2C_FIELD(MAPBASE, u16 *, 0x52B0) = 0xC;
    M2C_FIELD(MAPBASE, u16 *, 0x52A2) = M2C_FIELD(arg0, u16 *, 0x16);
    M2C_FIELD(MAPBASE, u16 *, 0x52A4) = M2C_FIELD(arg0, u16 *, 0x14);
    M2C_FIELD(&data_0215d9b8, u16 *, 6) = (u16)((M2C_FIELD(&data_0215d9b8, u16 *, 6) & ~0x380) | ((u32)(M2C_FIELD(arg0, u8 *, 0x125B) & 7) << 7));
    map = MAPBASE;
    M2C_FIELD(map, u16 *, 0x52C2) = M2C_FIELD(arg0, s16 *, 0x18);
    M2C_FIELD(map + 0xC2, u16 *, 0x5202) = M2C_FIELD(arg0, s16 *, 0x1A);
    M2C_FIELD(MAPBASE, u16 *, 0x52A6) = M2C_FIELD(MAPBASE, u16 *, 0x52A4) << 5;
    M2C_FIELD(MAPBASE, u16 *, 0x52A8) = (M2C_FIELD(MAPBASE, u16 *, 0x52A4) - 1) << 6;
    M2C_FIELD(MAPBASE, u16 *, 0x52B6) = M2C_FIELD(MAPBASE, u16 *, 0x52A4);
    src = arg0 + 0x2C;
    dst = MAPBASE + 0x5120;
    pd = dst;
    namePairs = 0x10;
    do {
        u8 a = src[0];
        u8 b = src[1];
        src += 2;
        pd[0] = a;
        pd[1] = b;
        pd += 2;
        namePairs -= 1;
    } while (namePairs != 0);
    M2C_FIELD(pd, u8 *, 0) = M2C_FIELD(src, u8 *, 0);
    M2C_FIELD(dst, u8 *, 0x21) = M2C_FIELD(arg0, u8 *, 0x4D);
    M2C_FIELD(dst, u16 *, 0x22) = M2C_FIELD(arg0, u16 *, 0x4E);
    M2C_FIELD(dst, u16 *, 0x24) = M2C_FIELD(arg0, u16 *, 0x50);
    M2C_FIELD(dst, u16 *, 0x26) = M2C_FIELD(arg0, u16 *, 0x52);
    M2C_FIELD(dst, u16 *, 0x28) = M2C_FIELD(arg0, s16 *, 0x54);
    M2C_FIELD(dst, u16 *, 0x2A) = M2C_FIELD(arg0, s16 *, 0x56);
    M2C_FIELD(dst, u16 *, 0x2C) = M2C_FIELD(arg0, s16 *, 0x58);
    M2C_FIELD(dst, u16 *, 0x2E) = M2C_FIELD(arg0, s16 *, 0x5A);
    M2C_FIELD(dst, u16 *, 0x30) = M2C_FIELD(arg0, u16 *, 0x5C);
    M2C_FIELD(dst, u16 *, 0x32) = M2C_FIELD(arg0, u16 *, 0x5E);
    M2C_FIELD(dst, u8 *, 0x34) = M2C_FIELD(arg0, u8 *, 0x60);
    M2C_FIELD(dst, u8 *, 0x35) = M2C_FIELD(arg0, u8 *, 0x61);
    M2C_FIELD(dst, u8 *, 0x36) = M2C_FIELD(arg0, u8 *, 0x62);
    M2C_FIELD(dst, u8 *, 0x37) = M2C_FIELD(arg0, u8 *, 0x63);
    M2C_FIELD(dst, u8 *, 0x38) = M2C_FIELD(arg0, u8 *, 0x64);
    M2C_FIELD(dst, u8 *, 0x39) = M2C_FIELD(arg0, u8 *, 0x65);
    M2C_FIELD(dst, u8 *, 0x3A) = M2C_FIELD(arg0, u8 *, 0x66);
    M2C_FIELD(dst, u8 *, 0x3B) = M2C_FIELD(arg0, u8 *, 0x67);
    M2C_FIELD(dst, u8 *, 0x3C) = M2C_FIELD(arg0, u8 *, 0x68);
    M2C_FIELD(dst, u8 *, 0x3D) = M2C_FIELD(arg0, u8 *, 0x69);
    M2C_FIELD(dst, u8 *, 0x3E) = M2C_FIELD(arg0, u8 *, 0x6A);
    M2C_FIELD(dst, u8 *, 0x3F) = M2C_FIELD(arg0, u8 *, 0x6B);
    src = arg0 + 0x6C;
    pd = dst + 0x40;
    n = 0xA1;
    do {
        u8 a = src[0];
        u8 b = src[1];
        src += 2;
        pd[0] = a;
        pd[1] = b;
        pd += 2;
        n -= 1;
    } while (n != 0);
    M2C_FIELD(&gMapConfig, u16 *, 0) = M2C_FIELD(arg0, u16 *, 0x1C);
    M2C_FIELD(&gMapConfig, u8 *, 2) = M2C_FIELD(arg0, u8 *, 0x1E);
    M2C_FIELD(&gMapConfig, u8 *, 3) = M2C_FIELD(arg0, u8 *, 0x1F);
    M2C_FIELD(&gMapConfig, u16 *, 4) = M2C_FIELD(arg0, u16 *, 0x20);
    M2C_FIELD(&gMapConfig, u16 *, 6) = M2C_FIELD(arg0, u16 *, 0x22);
    M2C_FIELD(&gMapConfig, u32 *, 8) = M2C_FIELD(arg0, u32 *, 0x24);
    M2C_FIELD(&gMapConfig, u32 *, 0xC) = M2C_FIELD(arg0, u32 *, 0x28);
    LoadMapTileset();
    dst = MAPBASE;
    M2C_FIELD(dst, u8 *, 0x5141) = GetMapPlayerCount(M2C_FIELD(dst, u16 *, 0x5142));
    dst = MAPBASE;
    StringCopy(dst + 0x5120, GetMapName(M2C_FIELD(dst, u16 *, 0x5142)));
    LoadMapTileData(M2C_FIELD(MAPBASE, u16 *, 0x5142));
    BuildMapRowOffsets();
    map = MAPBASE;
    for (y = 0; y < M2C_FIELD(map, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(map, u16 *, 0x5144); x++) {
            s32 index = x + M2C_FIELD(map + y * 2, u16 *, 0x3758);
            M2C_FIELD(map + index * 2, u16 *, 0xA10) =
                M2C_FIELD((u8 *)M2C_FIELD(&gMapData, u16 **, 0) + index * 2, u16 *, 2);
            map = MAPBASE;
        }
    }
    FreeMapTileData();
    {
    s32 x;
    u8 *map = MAPBASE;
    for (y = 0; y < M2C_FIELD(map, u16 *, 0x5146); y++) {
        for (x = 0; x < M2C_FIELD(map, u16 *, 0x5144); x++) {
            s32 row = M2C_FIELD(map + y * 2, u16 *, 0x3758);
            u16 tile = M2C_FIELD(map + (x + row) * 2, u16 *, 0xA10);
            M2C_FIELD(row + (map + x), u8 *, 0x1420) = M2C_FIELD(map + tile, u8 *, 0x6A60);
            map = MAPBASE;
        }
    }
    }
    rec = arg0 + 0xF08;
    for (i = 0; i < 0x63; i++) {
        v = M2C_FIELD(rec, u16 *, 2);
        x = M2C_FIELD(rec, u8 *, 0);
        y = M2C_FIELD(rec, u8 *, 1);
        if (v != 0xFFFF) {
            u8 *recordMap = MAPBASE;
            s32 index = x + M2C_FIELD(recordMap + y * 2, u16 *, 0x3758);
            u16 *tile = (u16 *)(recordMap + index * 2 + 0xA10);
            if ((M2C_FIELD(recordMap + *tile, u8 *, 0x6A60) & 0x1F) == 0x1C) {
                ApplyTerrainBlast(x, y);
            } else {
                *tile = v;
                recordMap = MAPBASE;
                M2C_FIELD(M2C_FIELD(recordMap + y * 2, u16 *, 0x3758) + (recordMap + x), u8 *, 0x1420) =
                    M2C_FIELD(recordMap + v, u8 *, 0x6A60);
            }
        }
        rec += 4;
    }
    src = arg0;
    for (j = 0; j < 4; j++) {
        dst = MAPBASE + 0x67A4 + (j + 1) * 0x8C;
        M2C_FIELD(dst, u32 *, 0) = M2C_FIELD(src, u32 *, 0x1B0);
        M2C_FIELD(dst, u32 *, 4) = M2C_FIELD(src, u32 *, 0x1B4);
        M2C_FIELD(dst, u32 *, 8) = M2C_FIELD(src, u32 *, 0x1B8);
        M2C_FIELD(dst, u32 *, 0xC) = M2C_FIELD(src, u32 *, 0x1BC);
        M2C_FIELD(dst, u8 *, 0x10) = M2C_FIELD(src, u8 *, 0x1C0);
        M2C_FIELD(dst, u8 *, 0x11) = M2C_FIELD(src, u8 *, 0x1C1);
        M2C_FIELD(dst, u8 *, 0x12) = M2C_FIELD(src, u8 *, 0x1C2);
        M2C_FIELD(dst, u8 *, 0x13) = M2C_FIELD(src, u8 *, 0x1C3);
        M2C_FIELD(dst, u8 *, 0x14) = M2C_FIELD(src, u8 *, 0x1C4);
        M2C_FIELD(dst, u8 *, 0x15) = M2C_FIELD(src, u8 *, 0x1C5);
        M2C_FIELD(dst, u8 *, 0x16) = M2C_FIELD(src, u8 *, 0x1C6);
        M2C_FIELD(dst, u8 *, 0x17) = M2C_FIELD(src, u8 *, 0x1C7);
        M2C_FIELD(dst, u8 *, 0x18) = M2C_FIELD(src, u8 *, 0x1C8);
        M2C_FIELD(dst, u8 *, 0x19) = M2C_FIELD(src, u8 *, 0x1C9);
        M2C_FIELD(dst, u16 *, 0x1A) = M2C_FIELD(src, u16 *, 0x1CA);
        M2C_FIELD(dst, u8 *, 0x1C) = M2C_FIELD(src, u8 *, 0x1CC);
        M2C_FIELD(dst, u8 *, 0x1D) = M2C_FIELD(src, u8 *, 0x1CD);
        M2C_FIELD(dst, u8 *, 0x1E) = M2C_FIELD(src, u8 *, 0x1CE);
        M2C_FIELD(dst, u8 *, 0x1F) = M2C_FIELD(src, u8 *, 0x1CF);
        M2C_FIELD(dst, u16 *, 0x20) = M2C_FIELD(src, u16 *, 0x1D0);
        M2C_FIELD(dst, u16 *, 0x22) = M2C_FIELD(src, u16 *, 0x1D2);
        M2C_FIELD(dst, s8 *, 0x24) = M2C_FIELD(src, s8 *, 0x1D4);
        M2C_FIELD(dst, u8 *, 0x25) = M2C_FIELD(src, u8 *, 0x1D5);
        M2C_FIELD(dst, u8 *, 0x26) = M2C_FIELD(src, u8 *, 0x1D6);
        M2C_FIELD(dst, u8 *, 0x27) = M2C_FIELD(src, u8 *, 0x1D7);
        M2C_FIELD(dst, u8 *, 0x28) = M2C_FIELD(src, u8 *, 0x1D8);
        M2C_FIELD(dst, u8 *, 0x29) = M2C_FIELD(src, u8 *, 0x1D9);
        M2C_FIELD(dst, u8 *, 0x2A) = M2C_FIELD(src, u8 *, 0x1DA);
        M2C_FIELD(dst, u8 *, 0x2B) = M2C_FIELD(src, u8 *, 0x1DB);
        M2C_FIELD(dst, u8 *, 0x2C) = M2C_FIELD(src, u8 *, 0x1DC);
        M2C_FIELD(dst, u8 *, 0x2D) = M2C_FIELD(src, u8 *, 0x1DD);
        M2C_FIELD(dst, u8 *, 0x2E) = M2C_FIELD(src, u8 *, 0x1DE);
        M2C_FIELD(dst, u8 *, 0x2F) = M2C_FIELD(src, u8 *, 0x1DF);
        M2C_FIELD(dst, u8 *, 0x30) = M2C_FIELD(src, u8 *, 0x1E0);
        M2C_FIELD(dst, u8 *, 0x31) = M2C_FIELD(src, u8 *, 0x1E1);
        M2C_FIELD(dst, u8 *, 0x32) = M2C_FIELD(src, u8 *, 0x1E2);
        ps = dst + 0x33;
        pd = src + 0x1E3;
        n = 0xD;
        do {
            u8 a = pd[0];
            u8 b = pd[1];
            pd += 2;
            ps[0] = a;
            ps[1] = b;
            ps += 2;
            n -= 1;
        } while (n != 0);
        M2C_FIELD(ps, u8 *, 0) = M2C_FIELD(pd, u8 *, 0);
        ps = dst + 0x4E;
        pd = src + 0x1FE;
        n = 0xD;
        do {
            u8 a = pd[0];
            u8 b = pd[1];
            pd += 2;
            ps[0] = a;
            ps[1] = b;
            ps += 2;
            n -= 1;
        } while (n != 0);
        M2C_FIELD(ps, u8 *, 0) = M2C_FIELD(pd, u8 *, 0);
        {
            u32 first = M2C_FIELD(src, u32 *, 0x21C);
            u32 second = M2C_FIELD(src, u32 *, 0x220);
            M2C_FIELD(dst, u32 *, 0x6C) = first;
            M2C_FIELD(dst, u32 *, 0x70) = second;
        }
        M2C_FIELD(dst, MapQuad *, 0x74) = M2C_FIELD(src, MapQuad *, 0x224);
        M2C_FIELD(dst, u32 *, 0x84) = M2C_FIELD(src, u32 *, 0x234);
        M2C_FIELD(dst, u32 *, 0x88) = M2C_FIELD(src, u32 *, 0x238);
        src += 0x8C;
    }
    M2C_FIELD(MAPBASE, u8 *, 0x67C1) = 0;
    i = 0;
    unit = arg0;
    for (; i < 4; i++) {
        SetPlayerTeam(i + 1, M2C_FIELD(unit, u8 *, 0x1CE));
        SetPlayerIdForSlot(i + 1, M2C_FIELD(unit, u8 *, 0x1CD));
        SetPlayerArmyId(i + 1, M2C_FIELD(unit, u8 *, 0x1D6));
        func_020a233c(i + 1, M2C_FIELD(unit, u8 *, 0x1E2));
        unit += 0x8C;
    }
    {
    s32 srcIndex = 0;
    s32 dstIndex = 0;
    for (y = 0; y < 4; y++, srcIndex += 0x33, dstIndex += 0x40) {
        ps = arg0 + srcIndex * 0xE;
        for (i = 0; i < 0x33; i++) {
            dst = MAPBASE + 0x59A4 + (i + dstIndex) * 0xE;
            M2C_FIELD(dst, u8 *, 0) = M2C_FIELD(ps, u8 *, 0x3E0);
            M2C_FIELD(dst, u8 *, 1) = M2C_FIELD(ps, u8 *, 0x3E1);
            M2C_FIELD(dst, u8 *, 2) = M2C_FIELD(ps, u8 *, 0x3E2);
            M2C_FIELD(dst, u16 *, 4) = M2C_FIELD(ps, u16 *, 0x3E4);
            M2C_FIELD(dst, u16 *, 6) = M2C_FIELD(ps, u16 *, 0x3E6);
            M2C_FIELD(dst, u16 *, 8) = M2C_FIELD(ps, u16 *, 0x3E8);
            M2C_FIELD(dst, u8 *, 0xA) = M2C_FIELD(ps, u8 *, 0x3EA);
            M2C_FIELD(dst, u8 *, 0xB) = M2C_FIELD(ps, u8 *, 0x3EB);
            {
                u8 a = M2C_FIELD(ps, u8 *, 0x3EC);
                u8 b = M2C_FIELD(ps, u8 *, 0x3ED);
                ps += 0xE;
                M2C_FIELD(dst, u8 *, 0xC) = a;
                M2C_FIELD(dst, u8 *, 0xD) = b;
            }
        }
    }
    }
    dst = arg0 + 0x1094;
    for (j = 0; j < 0x20; j++) {
        func_020a44fc(dst, j);
        dst += 8;
    }
    DecodeTerrainHitPoints(arg0 + 0x1194);
}
#pragma opt_strength_reduction reset
/* Save the battle prefix into `record`: the random seed, the 32 low event flags
 * (gEventFlagsLow) and the saved battle-view state, then let func_020b3c48 fill
 * in the map and unit data behind them. */
void SaveBattleToRecord(void *record) {
    s32 GetRandomSeed();
    extern u8 gEventFlagsLow;
    extern M2C_UNK gBattleViewState;
    s32 i;
    u8 *p;
    u8 flagByte;

    M2C_FIELD(record, s32 *, 0) = GetRandomSeed();
    p = &gEventFlagsLow;
    i = 0;
    do {
        flagByte = *p++;
        M2C_FIELD(record + i, u8 *, 4) = flagByte;
        i++;
    } while (i < 4);
    M2C_FIELD(record, s16 *, 8) = M2C_FIELD(&gBattleViewState, s16 *, 0);
    M2C_FIELD(record, s16 *, 10) = M2C_FIELD(&gBattleViewState, s16 *, 2);
    M2C_FIELD(record, s16 *, 12) = M2C_FIELD(&gBattleViewState, s16 *, 4);
    M2C_FIELD(record, s16 *, 14) = M2C_FIELD(&gBattleViewState, s16 *, 6);
    M2C_FIELD(record, s32 *, 16) = M2C_FIELD(&gBattleViewState, s32 *, 8);
    func_020b3c48(record);
}

/* Restore the battle prefix from a save `record` (the inverse of SaveBattleToRecord):
 * rebuild the map, reseed the random generator, then put back the 32 low event
 * flags and the saved battle-view state. */
void RestoreBattleFromRecord(void *record) {
    M2C_UNK SetRandomSeed(s32);
    M2C_UNK func_020b4264();
    extern u8 gEventFlagsLow;
    extern M2C_UNK gBattleViewState;
    s32 index;
    u8 *flagPtr;
    u8 flagByte;

    func_020b4264();
    SetRandomSeed(M2C_FIELD(record, s32 *, 0));
    flagPtr = &gEventFlagsLow;
    index = 0;
    do {
        flagByte = M2C_FIELD((record + index), u8 *, 4);
        index += 1;
        *flagPtr = flagByte;
        flagPtr += 1;
    } while (index < 4);
    M2C_FIELD(&gBattleViewState, s16 *, 0) = (s16) M2C_FIELD(record, s16 *, 8);
    M2C_FIELD(&gBattleViewState, s16 *, 2) = (s16) M2C_FIELD(record, s16 *, 0xA);
    M2C_FIELD(&gBattleViewState, s16 *, 4) = (s16) M2C_FIELD(record, s16 *, 0xC);
    M2C_FIELD(&gBattleViewState, s16 *, 6) = (s16) M2C_FIELD(record, s16 *, 0xE);
    M2C_FIELD(&gBattleViewState, s32 *, 8) = (s32) M2C_FIELD(record, s32 *, 0x10);
}

void func_020b4b20(void) {
    M2C_UNK func_0208f8ec(M2C_UNK, M2C_UNK);
    func_0208f8ec(0, 8);
}

void func_020b4b34(void) {
    M2C_UNK FadeMusicToFullVolume();
    FadeMusicToFullVolume();
}

/* Save step: stamp the battle record with the current date and day count, and when
 * the screen's save type has a slot select that slot; then write the battle prefix
 * (SaveBattleToRecord) into the save record buffer and store the whole 0x125c-byte
 * battle record under the screen's save type. */
void SaveCurrentBattle(void *state) {
    void *GetSaveRecordBuffer();
    s32 SaveTypeHasNoSlot(u8);
    s32 GetSaveSlot(s32, u8);
    u8 saveType = M2C_FIELD(state, s32 *, 0x5c);
    StampBattleRecord(saveType);
    if (!SaveTypeHasNoSlot(saveType)) {
        GetSaveSlot(0, saveType);
        func_020e4870();
    }
    SaveBattleToRecord(GetSaveRecordBuffer());
    func_020be438(saveType, GetSaveRecordBuffer(), 0x125c);
}

void func_020b4b98(void *arg0) {
    if (func_020be4c0((u8) M2C_FIELD(arg0, s32 *, 0x5C)) == 0) {
        SetUiMessageText(0xC000034C);
        return;
    }
    SetUiMessageText(0);
}

void func_020b4bcc(s32 arg0, M2C_UNK arg1){extern u8 gBattleEndState;extern M2C_UNK data_0212882c;func_020b3c44();if(gBattleEndState)return;M2C_FIELD(CreateSpriteForOwner(&data_0212882c,arg1),s32 *,0x5c)=arg0;}

/* Resume a saved battle: load the newest save record of `saveType`, restore the
 * map and the battle state (random seed, saved settings and view) from it,
 * remember the saved-battle slot the record belongs to (types 5..7; type 8 has
 * no slot), then rebuild the map's AI state, player teams and view. */
void ResumeSavedBattle(u8 saveType) {
    s32 SaveTypeHasNoSlot(u8);
    s32 GetSaveSlot(s32, u8);
    extern M2C_UNK data_0215d9b8;
    extern void *gCurrentMap;
    void (*callback)(void);

    LoadNewestSaveRecord(saveType, GetSaveRecordBuffer());
    RestoreBattleFromRecord(GetSaveRecordBuffer());
    if (!SaveTypeHasNoSlot(saveType)) {
        M2C_FIELD(&data_0215d9b8, u16 *, 6) = (M2C_FIELD(&data_0215d9b8, u16 *, 6) & ~0x70) | ((u32) ((u16) GetSaveSlot(0, saveType) << 29) >> 25);
    }
    func_020cfd14();
    callback = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(void), 0x50);
    if (callback) callback();
    SetupPlayerTeams();
    RefreshMapView();
    func_020c0a1c(3);
}

void func_020b4ca0(void) {
    s32 IsUnitAvailable();
    GetCurrentSaveType();
    if (IsUnitAvailable() == 0) {
        SetUiMessageText(0xC000032D);
        return;
    }
    SetUiMessageText(0xC000032E);
}

void func_020b4cd4(M2C_UNK arg0) {
    
    s32 temp_r0;

    temp_r0 = GetCurrentSaveType();
    if (temp_r0 == 0) {
        return;
    }
    func_020b4bcc(temp_r0, arg0);
}

void func_020b4cf4(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021286f4;
    CreateSpriteFromClass(&data_021286f4, 7);
}

void func_020b4d0c(void) {
    s32 GetCurrentSaveType();
    M2C_UNK func_020d4ac8();
    if (GetCurrentSaveType() == 0) {
        return;
    }
    func_020d4ac8();
}

void func_020b4d24(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021287b4;
    CreateSpriteFromClass(&data_021287b4, 7);
}

void func_020b4d3c(void *arg0) {
    M2C_UNK func_020e4870(s32);
    extern s32 gSaveSlotSummary;
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x5C);
    GetSaveType(0, temp_r4);
    StartBattleRecord();
    gSaveSlotSummary = (gSaveSlotSummary & ~0xF) | (temp_r4 & 0xF);
    func_020e4870(temp_r4);
    func_020bf798();
}

void func_020b4d80(void) {
    M2C_UNK SetUiMessageText(s32);
    s32 func_020be4c0(M2C_UNK);
    if (func_020be4c0(4) == 0) {
        SetUiMessageText(0xC000034C);
        return;
    }
    SetUiMessageText(0);
}

void func_020b4db0(s32 arg0) {
    extern M2C_UNK data_0212895c;
    M2C_FIELD(CreateSpriteForOwner(&data_0212895c), s32 *, 0x5C) = arg0;
}

void func_020b4dcc(void *arg0) {
    M2C_UNK StartBattleRecord();
    M2C_UNK GetSaveType(M2C_UNK, s32);
    M2C_UNK func_020bf798();
    M2C_UNK ClearSaveRecordHeader(s32);
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x5C);
    GetSaveType(0, temp_r4);
    StartBattleRecord();
    ClearSaveRecordHeader(temp_r4);
    func_020bf798();
}

void func_020b4df4(s32 arg0) {
    extern M2C_UNK data_0212874c;
    M2C_FIELD(CreateSpriteForOwner(&data_0212874c), s32 *, 0x5C) = arg0;
}

void func_020b4e10(M2C_UNK arg0) {
    M2C_UNK CreateSpriteForOwner(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02128a0c;
    CreateSpriteForOwner(&data_02128a0c, arg0);
}

/* Set up the 3D-sprite overlay of both screens for the map: reset each engine's
 * sprite-bank control bits and split rows, then reload the map's palette. */
void Init3DSpriteDisplay(void) {
    void Set3DSpriteVramBanks(void);
    void Apply3DSpriteDisplayConfig(void);
    void func_020d4d78(void);
    void func_020994e0(s32);
    void func_020c0a88(void);
    void CopyToObjPaletteShadow(void *, s32, s32);
    void func_020af1c0(s32, s32);
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain, *g3DSpriteBankMain;
    extern u16 gMapSpritePalette[];
    u16 *volatile ctrl200, *volatile ctrl400, *volatile ctrl800, *volatile oamAttr;
    u16 *volatile ctrl10, *volatile ctrl20, *volatile ctrl40, *volatile ctrl80, *volatile ctrl100;
    void *saved;
    s32 i;

    Set3DSpriteVramBanks();
    saved = gCur3DSpriteEngine;
    i = 0;
    do {
        gCur3DSpriteEngine = i == 0 ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        Apply3DSpriteDisplayConfig();
        ctrl200 = *(u16 **)gCur3DSpriteEngine; *ctrl200 = *ctrl200 & ~0x200;
        ctrl400 = *(u16 **)gCur3DSpriteEngine; *ctrl400 = *ctrl400 & ~0x400;
        ctrl800 = *(u16 **)gCur3DSpriteEngine; *ctrl800 = *ctrl800 & ~0x800;
        oamAttr = &((DS3DSpriteBank *)*(void **)gCur3DSpriteEngine)->oamAttr; *oamAttr = *oamAttr & ~0xC0;
        ((DS3DSpriteBank *)*(void **)gCur3DSpriteEngine)->rowsAbove = 0;
        ((DS3DSpriteBank *)*(void **)gCur3DSpriteEngine)->rowsBelow = 0;
        ((DS3DSpriteBank *)*(void **)gCur3DSpriteEngine)->filler_53 = 0;
        ctrl10 = *(u16 **)gCur3DSpriteEngine; *ctrl10 = *ctrl10 | 0x10;
        ctrl20 = *(u16 **)gCur3DSpriteEngine; *ctrl20 = *ctrl20 | 0x20;
        ctrl40 = *(u16 **)gCur3DSpriteEngine; *ctrl40 = *ctrl40 | 0x40;
        ctrl80 = *(u16 **)gCur3DSpriteEngine; *ctrl80 = *ctrl80 | 0x80;
        ctrl100 = *(u16 **)gCur3DSpriteEngine; *ctrl100 = *ctrl100 | 0x100;
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = saved;
    func_020d4d78();
    M2C_FIELD(g3DSpriteBankMain, u16 *, 4) = (M2C_FIELD(g3DSpriteBankMain, u16 *, 4) & ~1) | 1;
    func_020994e0(0);
    func_020c0a88();
    CopyToObjPaletteShadow(gMapSpritePalette, 32, 32);
    func_020af1c0(3, 15);
}

/* Places the map sprite object created from `kind` at map cell (x, y) and has the
 * sprite loader draw its tile: flags bit 5 says the coordinates are already in
 * pixels, bits 0..1 choose the orientation, bit 3 selects the runtime control
 * value at +0x40, bit 6 clears control bit 0x80000, and bit 4 picks the sprite
 * bank passed to the loader. */
s32 PlaceMapSprite(s32 sprite,s32 kind,s32 x,s32 y,s32 rawFlags,s32 base,s32 tileIndex){
s32 GetFrameStep(void);u32 flags=*(u16 *)&rawFlags;u16 tile;s32 saved=*(volatile s32 *)&tileIndex;
if(!(flags&32)){x<<=4;y<<=4;}
switch(flags&3){
case 1:x=(x+8)*48;y=(y+16)*48;break;
case 0:x=(x+8)*48;y=(y+8)*48;break;
case 2:x*=48;y*=48;break;
}
M2C_FIELD(sprite,s32 *,0x34)=x;M2C_FIELD(sprite,s32 *,0x38)=y;M2C_FIELD(sprite,s32 *,0x3c)=0x8b1;
M2C_FIELD(sprite,s32 *,0x40)=flags&8?GetFrameStep():0x20000;
if(flags&64)M2C_FIELD(sprite,u32 *,0x44)&=~0x80000;
else M2C_FIELD(sprite,u32 *,0x44)|=0x80000;
tile=(u16)(saved+0xab);
if(flags&16)LoadAnimatedSpriteAssetsFromNarc(sprite,kind,base+0x329a0,tile,0);
else LoadAnimatedSpriteAssetsFromNarc(sprite,kind,base+0x329a0,tile,1);
}

/* Create an animated map sprite of class `name` for `owner` (a layer index or a
 * parent sprite) and place it at map cell (tileX, tileY) with `rawFlags`, the
 * graphic offset into its sheet and its tile index.  Returns the new sprite. */
s32 CreateAnimatedMapSprite(M2C_UNK name, M2C_UNK tileX, M2C_UNK tileY, s32 rawFlags, s32 graphicOffset, u16 tileIndex, s32 owner) {
    s32 CreateAnimatedSpriteObject(s32);
    M2C_UNK PlaceMapSprite(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    s32 sprite;

    sprite = CreateAnimatedSpriteObject(owner);
    PlaceMapSprite(sprite, name, tileX, tileY, rawFlags, graphicOffset, (s32) tileIndex);
    return sprite;
}

/* Create a battle-effect map sprite of class `name` attached to `owner` and place
 * it at map cell (tileX, tileY) with `rawFlags`, the graphic offset into its
 * sheet and its tile index.  Returns the new sprite. */
s32 CreateEffectMapSprite(M2C_UNK name, M2C_UNK tileX, M2C_UNK tileY, s32 rawFlags, s32 graphicOffset, u16 tileIndex, s32 owner) {
    s32 CreateEffectSpriteObject(s32);
    s32 sprite;

    sprite = CreateEffectSpriteObject(owner);
    PlaceMapSprite(sprite, name, tileX, tileY, rawFlags, graphicOffset, (s32) tileIndex);
    return sprite;
}

void ResetEffectSpritePool(void) {
    extern s32 gEffectSpritePoolUsed;
    gEffectSpritePoolUsed = 0;
}

s32 GetEffectSpritePoolOffset(void) {
    extern s32 gEffectSpritePoolUsed;
    return gEffectSpritePoolUsed;
}

s32 LoadEffectSpriteSheet(s32 arg0,s32 arg1){s32 LoadSpriteGraphics(s32,s32,u16);extern s32 gEffectSpritePoolUsed;s32 old=gEffectSpritePoolUsed;gEffectSpritePoolUsed+=LoadSpriteGraphics(arg0,old+0x329a0,(u16)(arg1+0xab));return old;}

void func_020b5240(void) {
    M2C_UNK OpenEffectNarcArchive();
    OpenEffectNarcArchive();
}

void func_020b524c(void) {
    M2C_UNK CloseEffectNarcArchive();
    CloseEffectNarcArchive();
}

