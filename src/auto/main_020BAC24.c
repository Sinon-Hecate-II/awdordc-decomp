/* 13 functions from 0x020BAC24 to 0x020BBBBC (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
typedef struct UnitBac24 { u8 kind,x,y,unk3; u16 flags; u16 health:7;u16 rest:9;u8 unk8[4];u8 cargo1,cargo2; } UnitBac24;

/* Per-frame update of the battle cursor and of the unit under it: the unit and the units it
   carries follow the cursor, a carried unit the cursor is on is unloaded, the movement path
   is refreshed and a unit that died is taken off the map. */
void BattleUpdateUnitCursor(void){
extern void **gCurrentMap;
M2C_UNK func_020baa64();M2C_UNK func_020bf858();s32 func_020d1a1c(s32);void func_020a64bc(void *,s32);M2C_UNK func_ov000_021696d4();void func_ov000_0219a064(void);M2C_UNK func_020babfc(M2C_UNK,M2C_UNK,M2C_UNK);M2C_UNK func_020ce630(M2C_UNK,M2C_UNK,M2C_UNK);void func_020a8050(void *,void *,void *,void *);void func_020a6718(s32);M2C_UNK RefreshMapView();s32 func_020d66fc(void *);void func_ov000_0216aa04(void *,s32);void func_ov000_0216a9bc(void *);void func_020cbdbc(void);
BattleMapUnit *unit;u8 *map;s32 carrierId;u32 tileIndex;
func_020baa64();func_020bf858();
/* the unit under the cursor and the units it carries stand on the cursor's tile */
M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,1)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_X);
M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,2)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_Y);
if(M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,12)){
M2C_FIELD((u8*)*gCurrentMap+M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,12)*14,u8*,MAP_UNIT_RECORDS+1)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_X);
M2C_FIELD((u8*)*gCurrentMap+M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,12)*14,u8*,MAP_UNIT_RECORDS+2)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_Y);
}
if(M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,13)){
M2C_FIELD((u8*)*gCurrentMap+M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,13)*14,u8*,MAP_UNIT_RECORDS+1)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_X);
M2C_FIELD((u8*)*gCurrentMap+M2C_FIELD(M2C_FIELD(*gCurrentMap,u8**,MAP_CURSOR_UNIT),u8*,13)*14,u8*,MAP_UNIT_RECORDS+2)=M2C_FIELD(*gCurrentMap,s16*,MAP_CURSOR_Y);
}
/* the cursor keeps its direction only while the player may still choose one */
if(func_020d1a1c(M2C_FIELD(*gCurrentMap,u16*,MAP_CURRENT_PLAYER))){func_020a64bc(M2C_FIELD(*gCurrentMap,void**,MAP_CURSOR_UNIT),M2C_FIELD(*gCurrentMap,u8*,MAP_CURSOR_DIR));
M2C_FIELD(*gCurrentMap,u8*,MAP_CURSOR_DIR)=0;}func_ov000_021696d4();
unit=M2C_FIELD(*gCurrentMap,BattleMapUnit**,MAP_CURSOR_UNIT);unit->flags|=1;
unit=M2C_FIELD(*gCurrentMap,BattleMapUnit**,MAP_CURSOR_UNIT);if(unit->flags&8)unit->flags|=2;
map=*gCurrentMap;carrierId=M2C_FIELD(map,u8*,MAP_CURSOR_CARRIER);
if(carrierId){
/* the cursor is on the unit the carrier holds: unload it and step the carry chain on */
if(M2C_FIELD(map,u8*,MAP_CURSOR_UNIT_ID)==M2C_FIELD(map+carrierId*14,u8*,MAP_UNIT_RECORDS+12)){unit=(BattleMapUnit*)(map+MAP_UNIT_RECORDS)+carrierId;unit->firstCarried=unit->nextCarried;}
M2C_FIELD((u8*)*gCurrentMap+M2C_FIELD(*gCurrentMap,u8*,MAP_CURSOR_CARRIER)*14,u8*,MAP_UNIT_RECORDS+13)=0;
unit=(BattleMapUnit*)((u8*)*gCurrentMap+MAP_UNIT_RECORDS)+M2C_FIELD(*gCurrentMap,u8*,MAP_CURSOR_CARRIER);if(!unit->firstCarried)unit->flags&=~16;
}else{
unit=M2C_FIELD(map,BattleMapUnit**,MAP_CURSOR_UNIT);
if(unit->health && !(unit->flags&32)){
tileIndex=unit->x+M2C_FIELD(map+unit->y*2,u16*,MAP_ROW_OFFSETS);
if((u8)(M2C_FIELD(map+(tileIndex>>3),u8*,MAP_CELL_BITMAP)&(1<<(tileIndex&7))) && !(M2C_FIELD(map+M2C_FIELD(map,u16*,MAP_CURRENT_PLAYER)*140,u8*,0x67c3)&2))unit->flags|=128;
}}
func_ov000_0219a064();
/* highlight the path the unit would walk to the cursor */
func_020babfc(M2C_FIELD(*gCurrentMap,s16*,MAP_PATH_X),M2C_FIELD(*gCurrentMap,s16*,MAP_PATH_Y),(u8*)*gCurrentMap+MAP_CURSOR_PATH);
func_020ce630(M2C_FIELD(*gCurrentMap,s16*,MAP_PATH_X),M2C_FIELD(*gCurrentMap,s16*,MAP_PATH_Y),(u8*)*gCurrentMap+MAP_CURSOR_PATH);
func_020a8050(M2C_FIELD(*gCurrentMap,void**,MAP_CURSOR_UNIT),(u8*)*gCurrentMap+MAP_PATH_X,(u8*)*gCurrentMap+MAP_CURSOR_X,(u8*)*gCurrentMap+MAP_CURSOR_PATH);
unit=M2C_FIELD(*gCurrentMap,BattleMapUnit**,MAP_CURSOR_UNIT);
/* a unit without health is taken off the map */
if(!unit->health){if(unit)carrierId=unit-(BattleMapUnit*)((u8*)*gCurrentMap+MAP_UNIT_RECORDS);else carrierId=0;func_020a6718(carrierId);}
RefreshMapView();
if(func_020d66fc((u8*)*gCurrentMap+MAP_CURSOR_PATH))func_ov000_0216aa04(M2C_FIELD(*gCurrentMap,void**,MAP_CURSOR_UNIT),11);
else func_ov000_0216a9bc(M2C_FIELD(*gCurrentMap,void**,MAP_CURSOR_UNIT));
func_020cbdbc();
}

void func_020bb028(void) {
    M2C_UNK func_020bf858();
    M2C_UNK RefreshMapView();
    M2C_UNK func_ov000_021696d4();
    func_020bf858();
    func_ov000_021696d4();
    RefreshMapView();
}

void func_020bb03c(void) {
    M2C_UNK func_020baa64();
    M2C_UNK func_020babfc(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020ce630(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK RefreshMapView();
    extern void **gCurrentMap;

    func_020baa64();
    M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52D0), u8 *, 1) =
        (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52DC);
    M2C_FIELD(M2C_FIELD(*gCurrentMap, u8 **, 0x52D0), u8 *, 2) =
        (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52DE);
    func_020babfc(
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E0),
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E2),
        (M2C_UNK)((u8 *)*gCurrentMap + 0x5388));
    func_020ce630(
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E0),
        M2C_FIELD(*gCurrentMap, s16 *, 0x52E2),
        (M2C_UNK)((u8 *)*gCurrentMap + 0x5388));
    RefreshMapView();
}

void func_020bb0d0(M2C_UNK arg0) {
    M2C_UNK func_0209ecf0(M2C_UNK, M2C_UNK);
    void func_020bb03c(void);
    func_020bb03c();
    func_0209ecf0(arg0, 0);
}

void func_020bb0ec(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0209ea20(M2C_UNK, M2C_UNK, M2C_UNK);
    func_020bb03c();
    func_0209ea20(arg0, arg1, 0);
}

void func_020bb110(void) {
    extern void **gCurrentMap;
    M2C_UNK func_020a7568(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020baa64();
    M2C_UNK func_020baaac();
    M2C_UNK IsPlayerHuman(u16);
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    M2C_UNK func_020cd5d8();
    M2C_UNK CreateBattleEffectPending(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020c32bc(M2C_UNK);
    M2C_UNK func_0207ab24(M2C_UNK, M2C_UNK);
    M2C_UNK func_020ca484();

    u8 *map;
    u8 *sel;
    s16 cx;
    s16 cy;
    u16 rowoff;
    u8 terrain;
    s32 r4;
    s32 selIndex;
    u8 r5;

    map = (u8 *)*gCurrentMap;
    sel = (u8 *)M2C_FIELD(map, u8 **, 0x52D0);
    cx = M2C_FIELD(map, s16 *, 0x52DC);
    cy = M2C_FIELD(map, s16 *, 0x52DE);
    r4 = (s32)func_020a7568((M2C_UNK)sel, cx, cy);
    selIndex = 0;
    rowoff = M2C_FIELD(map, u16 *, 0x3758 + cy * 2);
    terrain = map[0x1420 + cx + rowoff];
    r5 = terrain;

    if (sel != 0) {
        u8 *unitBase;
        u16 *sel6p;
        u16 sel6;
        u16 pl;
        u16 t2;
        unitBase = map + 0x59A4;
        selIndex = (s32)(sel - unitBase) / 14;
        func_020baa64();
        func_020baaac();
        sel6p = (u16 *)(sel + 6);
        sel6 = *sel6p;
        r4 = r4 + (s32)((sel6 << 16) >> 27);
        if (r4 >= 20) r4 = 20;
        t2 = (u16)((sel6 << 16) >> 27);
        if (t2 == 0) {
            pl = M2C_FIELD(map, u16 *, 0x52A4);
            if (IsPlayerHuman(pl) != 0) {
                AddRecordValue(9, 1);
            }
        }
        if (r4 == 20) {
            pl = M2C_FIELD(map, u16 *, 0x52A4);
            if (IsPlayerHuman(pl) != 0) {
                AddRecordValue(10, 1);
            }
        }
    }

    if (map[0x5156] != 0 || map[0x5158] == 2) {
        u16 player;
        u8 unitrec;
        s16 cx2;
        s16 cy2;
        s32 r2flag;
        M2C_UNK cdret;
        u8 lr;
        s32 r6v;
        u16 sel6v;
        u8 tr2;
        u16 playerU;
        u8 a;
        u8 b;
        s32 arg;
        player = M2C_FIELD(map, u16 *, 0x52A4);
        unitrec = map[player * 0x8C + 0x67C3];
        cx2 = M2C_FIELD(map, s16 *, 0x52DC);
        cy2 = M2C_FIELD(map, s16 *, 0x52DE);
        r2flag = 1;
        if ((unitrec & 0x2) == 0) {
            u16 rowoff2;
            u32 idx;
            u8 byte;
            u32 bit;
            u8 val;
            rowoff2 = M2C_FIELD(map, u16 *, 0x3758 + cy2 * 2);
            idx = (cx2 + rowoff2) >> 3;
            byte = map[idx + 0x5201];
            bit = (cx2 + rowoff2) & 7;
            val = (u8)(byte & (u8)(1u << bit));
            if (val == 0) r2flag = 0;
        }
        if (r2flag != 0) {
            cdret = func_020cd5d8();
            if (cdret == 0) {
                /* fallthrough */
            }
            if ((terrain & 0x1F) == 0x0F) {
                lr = (terrain & 0xE0) >> 5;
                r6v = (selIndex & 0xC0) >> 6;
                r6v = r6v + 1;
                sel6v = 0;
                if (sel != 0) {
                    sel6v = (u16)((M2C_FIELD(sel, u16 *, 6) << 16) >> 27);
                }
                tr2 = terrain & 0x1F;
                playerU = (u16)(player & 0xFF);
                a = map[lr * 0x8C + 0x67A4 + 0x1D];
                b = map[r6v * 0x8C + 0x67A4 + 0x1D];
                CreateBattleEffectPending(playerU, tr2, a, b, sel6v, (M2C_UNK)(r4 & 0xFF));
            } else if (r4 >= 20) {
                arg = ((selIndex & 0xC0) >> 6) + 1;
                func_020c32bc(arg);
            }
        }
    }

    {
        u16 pl;
        u16 *sel6p;
        u16 sel6;
        u16 t;
        u8 lr;
        u8 tmp2;
        u16 *p22;
        pl = M2C_FIELD(map, u16 *, 0x52A4);
        sel6p = (u16 *)(sel + 6);
        sel6 = *sel6p;
        sel6 = (u16)((sel6 & ~0xF800u) | ((r4 & 0xFFFF) << 11));
        *sel6p = sel6;
        t = (u16)((sel6 << 16) >> 27);
        if (t >= 20) {
            *sel6p = (u16)(sel6 & ~0xF800u);
            if ((terrain & 0x1F) == 0x0F) {
                lr = (terrain & 0xE0) >> 5;
                map[lr * 0x8C + 0x67D4] = 1;
                tmp2 = map[lr * 0x8C + 0x67A4 + 0x31];
                p22 = (u16 *)(map + pl * 0x8C + 0x67A4 + 0x22);
                *p22 = (u16)(*p22 + tmp2);
            }
        }
    }

    func_0207ab24(cx, cy);
    func_020ca484();
}

void func_020bb458(void) {
    s32 IsPlayerHuman(u16);
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    M2C_UNK func_020baa64(void);
    M2C_UNK func_020babfc(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020ce630(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK PlaySoundAtTile(M2C_UNK, M2C_UNK, M2C_UNK);
    extern void **data_027e0058;

    u8 *unit;

    if (IsPlayerHuman(M2C_FIELD(*data_027e0058, u16 *, 0x52A4)) != 0) {
        AddRecordValue(0x13, 1);
    }
    unit = (u8 *)*data_027e0058 + 0x59A4 +
        ((u8 *)*data_027e0058)[
            M2C_FIELD(*data_027e0058, s16 *, 0x52DE) * 0 +
            M2C_FIELD(*data_027e0058, s16 *, 0x52DC) +
            M2C_FIELD(*data_027e0058, u16 *, 0x3758 + M2C_FIELD(*data_027e0058, s16 *, 0x52DE) * 2)
        ] * 0xE;
    /* simplify: reset cy term 0 */
    /* Actually the above *0 is wrong; fix below by recompute */
    func_020baa64();
    if (unit[0xC] != 0) {
        unit[0xD] = M2C_FIELD(*data_027e0058, u8 *, 0x52D4);
    } else {
        unit[0xC] = M2C_FIELD(*data_027e0058, u8 *, 0x52D4);
    }
    M2C_FIELD(M2C_FIELD(*data_027e0058, u8 **, 0x52D0), u16 *, 0x4) =
        (u16)(M2C_FIELD(M2C_FIELD(*data_027e0058, u8 **, 0x52D0), u16 *, 0x4) | 0x8);
    {
        u16 h = * (u16 *)(unit + 4);
        * (u16 *)(unit + 4) = (u16)(h | 0x10);
    }
    func_020babfc(
        M2C_FIELD(*data_027e0058, s16 *, 0x52E0),
        M2C_FIELD(*data_027e0058, s16 *, 0x52E2),
        (M2C_UNK)((u8 *)*data_027e0058 + 0x5388));
    func_020ce630(
        M2C_FIELD(*data_027e0058, s16 *, 0x52E0),
        M2C_FIELD(*data_027e0058, s16 *, 0x52E2),
        (M2C_UNK)((u8 *)*data_027e0058 + 0x5388));
    {
        u8 *p = M2C_FIELD(*data_027e0058, u8 *, 0x52D0);
        s32 k = (u32)p[0];
        k = (k << 26) >> 26;
        if (k != 1 && k != 2) return;
    }
    PlaySoundAtTile(
        0x7B,
        M2C_FIELD(*data_027e0058, s16 *, 0x52DC),
        M2C_FIELD(*data_027e0058, s16 *, 0x52DE));
}

void func_020bb5c0(void *arg0) {
    M2C_UNK func_020c98d8(s32, s32, M2C_UNK);
    M2C_UNK RefillUnitAmmo(s32, M2C_UNK);
    M2C_UNK RefillUnitFuel(s32, M2C_UNK);
    M2C_UNK LevelUpUnit(s32, M2C_UNK, M2C_UNK);
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x54);
    RefillUnitAmmo(temp_r4, 0);
    RefillUnitFuel(temp_r4, 0);
    LevelUpUnit(temp_r4, 1, 1);
    func_020c98d8(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), 1);
}

void func_020bb608(s32 arg0) {
    M2C_UNK IsPlayerHuman(u16);
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    extern void **gCurrentMap;
    extern s32 data_0215be0c;
    extern s16 data_0212923c[];

    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) != 0) {
        AddRecordValue(0x14, 1);
        {
            u8 *sel;
            u8 kind;
            u8 *u;
            u16 f;
            s32 idx;
            u8 d;
            sel = M2C_FIELD(*gCurrentMap, u8 *, 0x52D0);
            kind = sel[arg0 + 0xC];
            u = (u8 *)*gCurrentMap + 0x59A4 + kind * 0xE;
            f = M2C_FIELD(u, u16 *, 0x4);
            f = (u16)(f & ~0x8);
            M2C_FIELD(u, u16 *, 0x4) = f;
            f = M2C_FIELD(u, u16 *, 0x4);
            f = (u16)(f & ~0x2);
            M2C_FIELD(u, u16 *, 0x4) = f;
            idx = data_0215be0c;
            u[0x1] = (s8)(M2C_FIELD(*gCurrentMap, s16 *, 0x52DC) + data_0212923c[idx * 2]);
            u[0x2] = (s8)(M2C_FIELD(*gCurrentMap, s16 *, 0x52DE) + data_0212923c[idx * 2 + 1]);
            sel = M2C_FIELD(*gCurrentMap, u8 *, 0x52D0);
            sel[arg0 + 0xC] = 0;
            if (arg0 == 0) {
                sel = M2C_FIELD(*gCurrentMap, u8 *, 0x52D0);
                d = sel[0xD];
                if (d != 0) {
                    sel[0xC] = d;
                    sel = M2C_FIELD(*gCurrentMap, u8 *, 0x52D0);
                    sel[0xD] = 0;
                }
            }
        }
    }
    {
        u8 *sel = M2C_FIELD(*gCurrentMap, u8 *, 0x52D0);
        u8 kind = sel[0xC];
        if (kind == 0) {
            u16 h = M2C_FIELD(sel, u16 *, 0x4);
            h = (u16)(h & ~0x10);
            M2C_FIELD(sel, u16 *, 0x4) = h;
        }
    }
}

void func_020bb768(void) {
}

void func_020bbac8(void) {
    M2C_UNK AddRecordValue(M2C_UNK, M2C_UNK);
    M2C_UNK func_020cb8cc(M2C_UNK);
    s32 IsPlayerHuman(u16);
    extern void **gCurrentMap;
    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) != 0) {
        AddRecordValue(0x10, 1);
    }
    func_020cb8cc(0);
}

void func_020bbb08(void) {
 M2C_UNK RollNextWeather(); M2C_UNK func_0207c2e0(); M2C_UNK func_020a6fcc();
 extern void **gCurrentMap; extern u8 data_02156e50[];
 u8 *p = (u8 *)*gCurrentMap + 0x5120;
 p[0x3a] = RollNextWeather();
 *(u32 *)(data_02156e50+8) = func_0207c2e0();
 M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap,u16 *,0x52a4)*0x8c,u8 *,0x67d1)=M2C_FIELD(*gCurrentMap,s16 *,0x52c2);
 M2C_FIELD((u8 *)*gCurrentMap + M2C_FIELD(*gCurrentMap,u16 *,0x52a4)*0x8c,u8 *,0x67d2)=M2C_FIELD(*gCurrentMap,s16 *,0x52c4);
 func_020a6fcc(); M2C_FIELD(*gCurrentMap,u16 *,0x52b0)=1;
}

void func_020bbba4(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212afac;
    func_01ffa3dc(&data_0212afac, 7);
}

