/* 19 functions from 0x02216C94 to 0x02217C80 (ov007), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ov007_map_editor.h"

typedef struct MapPoint { s16 x, y; } MapPoint;
typedef struct MapScan { u8 pad0[0xa10]; u16 cells[0x16a4]; u16 rows[0xcf6]; u16 width, height; } MapScan;

/* Pick two well-separated interior locations for the two sides (first and second headquarters/spawn points). */
void func_ov007_02216c94(M2C_UNK *first, M2C_UNK *second) {
    s32 Map_RandomScaledValue(s32 low, s32 high);
    s32 Map_PickRandomInteriorTile(s32 *x, s32 *y, s32 tileValue, void *avoidPoint);
    MapPoint Map_PlaceSideBase(s32 x, s32 y, s32 side, s32 radius, s32 distance);
    MapPoint func_ov007_02215a0c(s32 side, s32 radius, s32 distance);

    s32 x, y;
    s32 radius = Map_RandomScaledValue(2, 4);
    s32 distance = Map_RandomScaledValue(1, 3);

    if (Map_PickRandomInteriorTile(&x, &y, 1, 0) == 1) {
        MapPoint placed = Map_PlaceSideBase(x, y, 1, radius, distance);
        ((MapPoint *)first)->x = placed.x; ((MapPoint *)first)->y = placed.y;
    } else {
        MapPoint placed = func_ov007_02215a0c(1, radius, distance);
        ((MapPoint *)first)->x = placed.x; ((MapPoint *)first)->y = placed.y;
    }
    if (Map_PickRandomInteriorTile(&x, &y, 1, first) == 1) {
        MapPoint placed = Map_PlaceSideBase(x, y, 2, radius, distance);
        ((MapPoint *)second)->x = placed.x; ((MapPoint *)second)->y = placed.y;
    } else {
        MapPoint placed = func_ov007_02215a0c(2, radius, distance);
        ((MapPoint *)second)->x = placed.x; ((MapPoint *)second)->y = placed.y;
    }
}

M2C_UNK func_ov007_02216e08(M2C_UNK *arg0, M2C_UNK *arg1, M2C_UNK *out_a, M2C_UNK *out_b, M2C_UNK *out_c) {
    s32 Map_RandomScaledValue(s32, s32);
    s32 PickRandomTileNear(s32 *, s32 *, s32, void *, s32);
    s32 func_ov007_02215f6c(s32 *, s32 *, s32, s16 *, s16 *, s32);
    M2C_UNK Map_SetCellTile(s32, s32, s32);

    s32 x, y;
    s32 saved;
    s32 count;
    s32 mode;

    ((s16 *)out_c)[0] = (s16)0xff;
    ((s16 *)out_b)[0] = (s16)0xff;
    ((s16 *)out_a)[0] = (s16)0xff;
    count = 0;
    for (mode = 0; mode < 5; mode++) {
        switch (mode) {
            case 0: count = Map_RandomScaledValue(0, 5); break;
            case 1: count = Map_RandomScaledValue(3, 5); break;
            case 2: count = Map_RandomScaledValue(3, 7); break;
            case 3: count = Map_RandomScaledValue(0, 5); break;
            case 4: count = Map_RandomScaledValue(0, 3); break;
        }
        saved = 0;
        if (count <= 0) continue;
        do {
            switch (mode) {
            case 0:
                if (!PickRandomTileNear(&x, &y, 1, arg0, 10)) goto done_inner;
                Map_SetCellTile(x, y, 0x1c7);
                if (!PickRandomTileNear(&x, &y, 1, arg1, 10)) goto done_inner;
                Map_SetCellTile(x, y, 0x1cc);
                break;
            case 1:
                if (!PickRandomTileNear(&x, &y, 1, arg0, 8)) goto done_inner;
                Map_SetCellTile(x, y, 0x1c2);
                ((s16 *)out_a)[0] = (s16)x; ((s16 *)out_a)[1] = (s16)y;
                if (!PickRandomTileNear(&x, &y, 1, arg1, 8)) goto done_inner;
                Map_SetCellTile(x, y, 0x1c2);
                ((s16 *)out_b)[0] = (s16)x; ((s16 *)out_b)[1] = (s16)y;
                break;
            case 2:
                if (!func_ov007_02215f6c(&x, &y, 1, (s16 *)arg0, (s16 *)arg1, 10)) goto done_inner;
                Map_SetCellTile(x, y, 0x1c2);
                ((s16 *)out_c)[0] = (s16)x; ((s16 *)out_c)[1] = (s16)y;
                break;
            case 3:
                if (!func_ov007_02215f6c(&x, &y, 1, (s16 *)arg0, (s16 *)arg1, 5)) goto done_inner;
                Map_SetCellTile(x, y, 0x1b9);
                ((s16 *)out_c)[0] = (s16)x; ((s16 *)out_c)[1] = (s16)y;
                break;
            case 4:
                if (!func_ov007_02215f6c(&x, &y, 1, (s16 *)arg0, (s16 *)arg1, 5)) goto done_inner;
                Map_SetCellTile(x, y, 0x1d9);
                break;
            }
            saved++;
        } while (saved < count);
        done_inner:
        ;
    }
}

/* Generates the map's paths: one between the two main base points and, when the
 * three branch points are set, one from each of the first two to the junction.
 * Finally every cell the paths cross that is neither a property nor a straight
 * corridor is turned into plain ground. */
void Map_GeneratePaths(M2C_UNK *baseA, M2C_UNK *baseB, M2C_UNK *branchA, M2C_UNK *branchB, M2C_UNK *junction) {
    s32 Map_InitMarkerGrid(void);
    s32 PickPathEndpoints(s32, s32, s32, s32, s32, M2C_UNK *, M2C_UNK *, M2C_UNK *);
    M2C_UNK DrawOrthogonalPath(s16, s16, s16, s16, M2C_UNK);
    M2C_UNK Map_IsPropertyTile(s32, s32);
    M2C_UNK Map_PlaceStraightCorridor(s32, s32);
    M2C_UNK Map_SetCellTile(s32, s32, s32);
    extern void **gCurrentMap;
    extern s8 gMapMarkerGrid[];
    MapPoint pathStart, pathEnd;
    s32 orientation;
    MapScan *map;
    register s32 x, y;
    register s8 *markers;

    Map_InitMarkerGrid();
    if (PickPathEndpoints(((MapPoint *)baseA)->x, ((MapPoint *)baseA)->y, ((MapPoint *)baseB)->x, ((MapPoint *)baseB)->y, 4, (M2C_UNK *)&pathStart, (M2C_UNK *)&pathEnd, (M2C_UNK *)&orientation)) {
        DrawOrthogonalPath(pathStart.x, pathStart.y, pathEnd.x, pathEnd.y, (M2C_UNK)orientation);
    }
    if (((MapPoint *)branchA)->x != MAP_POINT_NONE && ((MapPoint *)branchB)->x != MAP_POINT_NONE && ((MapPoint *)junction)->x != MAP_POINT_NONE) {
        if (PickPathEndpoints(((MapPoint *)branchA)->x, ((MapPoint *)branchA)->y, ((MapPoint *)junction)->x, ((MapPoint *)junction)->y, 2, (M2C_UNK *)&pathStart, (M2C_UNK *)&pathEnd, (M2C_UNK *)&orientation)) {
            DrawOrthogonalPath(pathStart.x, pathStart.y, pathEnd.x, pathEnd.y, (M2C_UNK)orientation);
        }
        if (PickPathEndpoints(((MapPoint *)branchB)->x, ((MapPoint *)branchB)->y, ((MapPoint *)junction)->x, ((MapPoint *)junction)->y, 2, (M2C_UNK *)&pathStart, (M2C_UNK *)&pathEnd, (M2C_UNK *)&orientation)) {
            DrawOrthogonalPath(pathStart.x, pathStart.y, pathEnd.x, pathEnd.y, (M2C_UNK)orientation);
        }
    }

    y = 0;
    map = (MapScan *)*gCurrentMap;
    if ((s32)map->height <= 0) return;
    markers = gMapMarkerGrid;
    do {
        map = (MapScan *)*gCurrentMap;
        x = 0;
        if ((s32)map->width > 0) {
            do {
                if (markers[x] == MAP_MARKER_PATH) {
                    if (Map_IsPropertyTile(x, y) != 1) {
                        if (Map_PlaceStraightCorridor(x, y) != 1) {
                            Map_SetCellTile(x, y, 6);
                        }
                    }
                }
                x += 1;
                map = (MapScan *)*gCurrentMap;
            } while (x < (s32)map->width);
        }
        y += 1;
        markers += MAP_MARKER_STRIDE;
        map = (MapScan *)*gCurrentMap;
    } while (y < (s32)map->height);

    return;
}

/* Pick a random open (type-3) ground cell in the band between two map
 * points: the search rectangle starts near `a` and extends toward `b`,
 * clamped to the map. Returns 1 and writes the cell to `out` if one is
 * found; when several qualify, one is chosen at random. */
s32 Map_PickRandomGroundCellBetween(void *arg0, void *arg1, s16 *out) {
    extern void **gCurrentMap;
    s32 Map_ScoreNeighborPattern(s32, s32);
    s32 RandomIntRange(s32, s32);
    MapPoint *pa, *pb;
    s32 x, y, count;
    s32 aX, bX, bY, top, d;
    s32 left;
    s32 pick;
    s32 found;
    s32 aY;
    MapScan *map;

    pa = arg0;
    pb = arg1;
    found = 0;
    bX = pb->x;
    aX = pa->x;
    d = aX - bX;
    if (d < 0) d = -d;
    if ((u32) d < 5U) {
        if (aX < bX) { left = bX - 10; aX += 10; }
        else { left = aX - 10; aX = bX + 10; }
    } else {
        if (aX < bX) { left = aX; aX += 10; }
        else { left = aX - 10; }
    }
    bY = ((volatile MapPoint *)pb)->y;
    aY = ((volatile MapPoint *)pa)->y;
    d = aY - bY;
    if (d < 0) d = -d;
    if ((u32) d < 5U) {
        if (aY < bY) { top = bY - 10; aY += 10; }
        else { top = aY - 10; aY = bY + 10; }
    } else {
        if (aY < bY) { top = aY; aY += 10; }
        else { top = aY - 10; }
    }
    if (left < 0) left = 0;
    if (top < 0) top = 0;
    map = *gCurrentMap;
    if (aX >= (s32) map->width) aX = (s32) map->width - 1;
    if (aY >= (s32) map->height) aY = (s32) map->height - 1;
    count = 0;
    for (y = top; y < aY; y++) {
        for (x = left; x < aX; x++) {
            map = *gCurrentMap;
            if (map->cells[x + map->rows[y]] == 3) {
                if (Map_ScoreNeighborPattern(x, y) != -1) {
                    out[0] = x;
                    found = 1;
                    out[1] = (s16) y;
                    count++;
                }
            }
        }
    }
    if (count >= 2) {
        pick = RandomIntRange(0, count - 1);
        count = 0;
        for (y = top; y <= aY; y++) {
            for (x = left; x <= aX; x++) {
                map = *gCurrentMap;
                if (map->cells[x + map->rows[y]] == 3) {
                    if (Map_ScoreNeighborPattern(x, y) != -1) {
                        if (count < pick) {
                            count++;
                        } else {
                            out[0] = x;
                            out[1] = y;
                            break;
                        }
                    }
                }
            }
        }
    }
    return found;
}

/* Places one port for each side on a random open ground cell between the two
 * bases: side 1's port is picked from its base toward side 2, and vice versa. */
M2C_UNK Map_PlaceSidePorts(M2C_UNK *baseA, M2C_UNK *baseB) {
    s32 Map_PickRandomGroundCellBetween(void *, void *, s16 *);
    M2C_UNK Map_SetCellTile(s32, s32, s32);
    s16 portA[2], portB[2];
    if (!Map_PickRandomGroundCellBetween(baseA, baseB, portA)) return;
    if (!Map_PickRandomGroundCellBetween(baseB, baseA, portB)) return;
    Map_SetCellTile(portA[0], portA[1], 0x1c9);
    Map_SetCellTile(portB[0], portB[1], 0x1ce);
}

/* Scatter rocks over the map: replace 20..40 random plain cells (tile id 1) with
 * MAP_TILE_ROCK, stopping early when no plain cell is left to pick. */
M2C_UNK Map_ScatterRocks(void) {
    s32 Map_RandomScaledValue(s32,s32);
    s32 Map_PickRandomTileOfValue(s32 *,s32 *,s32);
    M2C_UNK Map_SetCellTile(s32,s32,s32);
    s32 x; s32 y; s32 i; s32 n;
    n=Map_RandomScaledValue(20,40);
    for(i=0;i<n;i++){
        if(Map_PickRandomTileOfValue(&x,&y,1)==0)return;
        Map_SetCellTile(x,y,MAP_TILE_ROCK);
    }
}

/* Random-map generator pass: scatter 5..20 copies of terrain tile 385 (a
 * single-cell detail tile, terrain kind 6) over random plain cells.  The other
 * passes of func_ov007_02217a5c scatter MAP_TILE_ROCK and the wasteland debris. */
M2C_UNK Map_ScatterDetailTiles(void) {
    s32 Map_RandomScaledValue(s32, s32);
    s32 Map_PickRandomTileOfValue(s32 *, s32 *, s32);
    M2C_UNK Map_SetCellTile(s32, s32, s32);
    s32 x;
    s32 y;
    s32 i;
    s32 count;

    count = Map_RandomScaledValue(5, 20);
    for (i = 0; i < count; i++) {
        if (Map_PickRandomTileOfValue(&x, &y, 1) == 0) return;
        Map_SetCellTile(x, y, 385);
    }
}

/* Scatter rough ground over plain tiles, stopping early if the search fails. */
void Map_ScatterRoughGround(void) {
    s32 Map_RandomScaledValue(s32, s32);
    s32 Map_PickRandomTileOfValue(s32 *, s32 *, s32);
    M2C_UNK Map_SetCellTile(s32, s32, s32);
    s32 x;
    s32 y;
    s32 placed;
    s32 count;

    count = Map_RandomScaledValue(MAP_RANDOM_ROUGH_GROUND_COUNT_MIN, MAP_RANDOM_ROUGH_GROUND_COUNT_MAX);
    for (placed = 0; placed < count; placed++) {
        if (Map_PickRandomTileOfValue(&x, &y, MAP_TILE_PLAIN) == 0) {
            return;
        }
        Map_SetCellTile(x, y, MAP_TILE_ROUGH_GROUND);
    }
}

/* On every passable type-3 cell, randomly place tile 34 with a chance based on how many of its neighbors are open; then in a second pass place tile 34 on type-3 cells with exactly two open neighbors. */
void func_ov007_02217774(void) {
    extern void **gCurrentMap;
    s32 Map_ScoreNeighborPattern(s32 x, s32 y);
    s32 Map_RollTerrainGrowth(s32 count, s32 mode);
    M2C_UNK Map_SetCellTile(s32 x, s32 y, s32 value);
    s32 x, y, openNeighborCount;
    MapScan *map;
    map = *gCurrentMap;
    for (y = 0; y < (s32)map->height; y++) {
        for (x = 0; x < (s32)map->width; x++) {
            if (map->cells[x + map->rows[y]] == 3) {
                openNeighborCount = Map_ScoreNeighborPattern(x, y);
                if (openNeighborCount != -1 && Map_RollTerrainGrowth(openNeighborCount, 34))
                    Map_SetCellTile(x, y, 34);
            }
            map = *gCurrentMap;
        }
    }
    for (y = 0; y < (s32)map->height; y++) {
        for (x = 0; x < (s32)map->width; x++) {
            if (map->cells[x + map->rows[y]] == 3) {
                if (Map_ScoreNeighborPattern(x, y) == 2)
                    Map_SetCellTile(x, y, 34);
            }
            map = *gCurrentMap;
        }
    }
}

/* Scatter reefs over suitable sea cells until the map-scaled count is reached. */
void Map_ScatterReefs(void) {
    s32 Map_RandomScaledValue(s32, s32);
    s32 Map_PickRandomSeaAreaTile(s32 *, s32 *, s32);
    M2C_UNK Map_SetCellTile(s32, s32, s32);
    s32 x;
    s32 y;
    s32 placed;
    s32 count;

    count = Map_RandomScaledValue(MAP_RANDOM_REEF_COUNT_MIN, MAP_RANDOM_REEF_COUNT_MAX);
    for (placed = 0; placed < count; placed++) {
        if (Map_PickRandomSeaAreaTile(&x, &y, MAP_TILE_SEA) == 0) {
            return;
        }
        Map_SetCellTile(x, y, MAP_TILE_REEF);
    }
}

/* Random-map generator pass: scatter 5..10 single-cell wasteland decorations
 * (tile id 39) over random wasteland (tile 3) cells, stopping early when no
 * suitable cell is left to pick. */
M2C_UNK func_ov007_0221796c(void) {
    s32 Map_RandomScaledValue(s32, s32);
    s32 Map_PickRandomSeaAreaTile(s32 *, s32 *, s32);
    M2C_UNK Map_SetCellTile(s32, s32, s32);
    s32 x;
    s32 y;
    s32 i;
    s32 count;

    count = Map_RandomScaledValue(5, 10);
    for (i = 0; i < count; i++) {
        if (Map_PickRandomSeaAreaTile(&x, &y, MAP_TILE_WASTELAND) == 0) return;
        Map_SetCellTile(x, y, 39);
    }
}

/* Scatter 8..15 single-cell decorations over the map's wasteland areas:
 * replace a random wasteland cell (tile id 3) with tile id 7 each time. */
M2C_UNK Map_ScatterWastelandDebris(void){
s32 Map_RandomScaledValue(s32,s32);s32 Map_PickRandomSeaAreaTile(s32 *,s32 *,s32);M2C_UNK Map_SetCellTile(s32,s32,s32);
s32 x,y,i,count;
count=Map_RandomScaledValue(8,15);
for(i=0;i<count;i++){
if(!Map_PickRandomSeaAreaTile(&x,&y,3))return;
Map_SetCellTile(x,y,7);
}
}

/* Fill every tile of the current map with type 1, then populate enemies, items and other map content. */
void func_ov007_02217a5c(void) {
    M2C_UNK SeedRandomFromRtc();
    M2C_UNK Map_SetCellTile(s32, s32, M2C_UNK);
    M2C_UNK Map_GenerateWastelandTerrain();
    M2C_UNK Map_GenerateWoodsTerrain();
    M2C_UNK func_ov007_02216e08(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *);
    void Map_GeneratePaths(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *);
    M2C_UNK Map_PlaceSidePorts(M2C_UNK *, M2C_UNK *);
    M2C_UNK Map_ScatterRocks(void);
    M2C_UNK Map_ScatterDetailTiles();
    M2C_UNK func_ov007_0221796c();
    M2C_UNK Map_ScatterWastelandDebris();
    extern void **gCurrentMap;
    M2C_UNK sp14;
    M2C_UNK sp10;
    M2C_UNK spC;
    M2C_UNK sp8;
    M2C_UNK sp4;
    s32 x;
    s32 y;
    void *map;

    SeedRandomFromRtc();
    y = 0;
    map = *gCurrentMap;
    if ((s32) M2C_FIELD(map, u16 *, 0x5146) > 0) {
        do {
            x = 0;
            if ((s32) M2C_FIELD(map, u16 *, 0x5144) > 0) {
                do {
                    Map_SetCellTile(x, y, 1);
                    x += 1;
                    map = *gCurrentMap;
                } while (x < (s32) M2C_FIELD(map, u16 *, 0x5144));
            }
            y += 1;
        } while (y < (s32) M2C_FIELD(map, u16 *, 0x5146));
    }
    Map_GenerateWastelandTerrain();
    Map_GenerateWoodsTerrain();
    func_ov007_02216c94(&sp14, &sp10);
    func_ov007_02216e08(&sp14, &sp10, &spC, &sp8, &sp4);
    Map_GeneratePaths(&sp14, &sp10, &spC, &sp8, &sp4);
    Map_PlaceSidePorts(&sp14, &sp10);
    Map_ScatterRocks();
    Map_ScatterDetailTiles();
    Map_ScatterRoughGround();
    func_ov007_02217774();
    Map_ScatterReefs();
    func_ov007_0221796c();
    Map_ScatterWastelandDebris();
}

/* The map editor's palette entry table for `page` (MAP_EDITOR_PAGE_TERRAIN or
 * MAP_EDITOR_PAGE_UNIT): MAP_EDITOR_PALETTE_ENTRY_SIZE-byte entry records that
 * start with the kind and end with a negative kind. */
s8 *MapEditor_GetPaletteEntries(s32 page) {
    extern s8 *gMapEditorPaletteEntries[2];
    s8 *tables[2];
    tables[0] = gMapEditorPaletteEntries[0];
    tables[1] = gMapEditorPaletteEntries[1];
    return tables[page];
}

/* Index of `kind` in the map editor's palette entries for `page`
 * (MAP_EDITOR_PAGE_TERRAIN or MAP_EDITOR_PAGE_UNIT), or -1 when the page has no
 * entry for it.  Entries are MAP_EDITOR_PALETTE_ENTRY_SIZE bytes and their first
 * byte is the kind; a negative kind ends the list. */
s32 MapEditor_FindPaletteEntryIndex(s32 page, s32 kind) {
    s8 *entry = MapEditor_GetPaletteEntries(page);
    s32 index = 0;

    while (*entry >= 0) {
        if (*entry == kind) return index;
        entry += MAP_EDITOR_PALETTE_ENTRY_SIZE;
        index++;
    }
    return -1;
}

s32 MapEditor_GetPaletteKind(s32 a,s32 b){
 s8 *MapEditor_GetPaletteEntries(s32);
 return MapEditor_GetPaletteEntries(a)[b*5];
}

/* The palette row the icon of palette entry `index` on `page` is drawn with:
 * the entry is painted in the owner's army colour when its record says so (the
 * terrain page's entries are), giving `owner`'s colour slot; otherwise row 0. */
u8 MapEditor_GetPaletteOwner(s32 page, s32 index, s32 owner) {
    extern u8 gMapEditorOwnerByColor;
    u8 *entry = (u8 *)MapEditor_GetPaletteEntries(page) + index * MAP_EDITOR_PALETTE_ENTRY_SIZE;
    if (entry[4] == 1) return (&gMapEditorOwnerByColor)[owner];
    return 0;
}

/* Map editor palette lookup: the owner/colour index the palette panel uses for
 * owner byte `owner` (index into gMapEditorOwnerByColor), or -1 when it has no
 * colour slot. */
s32 MapEditor_GetOwnerColorIndex(s32 owner) {
    extern u8 gMapEditorOwnerByColor;
    s32 index;
    u8 *entry;

    entry = &gMapEditorOwnerByColor;
    index = 0;
loop_1:
    if (*entry == owner) {
        return index;
    }
    index += 1;
    entry += 1;
    if (index >= MAP_EDITOR_OWNER_COLOR_COUNT) {
        return -1;
    }
    goto loop_1;
}

/* Number of owner/colour slots the palette panel's current page shows: five on
 * the terrain page (four army colours plus neutral) and four on the unit page. */
s32 MapEditor_GetPageOwnerColorCount(void *editor) {
    u8 page;

    page = M2C_FIELD(editor, u8 *, MAP_EDITOR_PANEL_PAGE);
    switch (page) {
    case MAP_EDITOR_PAGE_TERRAIN:
        return 5;
    case MAP_EDITOR_PAGE_UNIT:
        return 4;
    default:
        return 0;
    }
}
