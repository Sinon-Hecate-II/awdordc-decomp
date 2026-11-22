/* 12 functions from 0x0221A59C to 0x0221B56C (ov007), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"
#include "battle_map.h"
extern u8 gHeapObjectVTable[];
static inline void InitTextDescriptor(u8 *sp) {
sp[32]=(u8)((u8)(sp[32]&~1)&~30);sp[32]=(sp[32]&~224)|64;
sp[40]&=~224;
M2C_FIELD(sp,void **,0)=gHeapObjectVTable;sp[4]=0;
M2C_FIELD(sp,u16 *,18)=0x140;sp[20]=8;sp[21]=8;sp[22]=1;sp[23]=8;sp[24]=8;
sp[33]=0;M2C_FIELD(sp,s32 *,36)=0;sp[41]=0;

}
struct TileNeighbors_0221 { s16 values[24]; };
struct TileCardinalNeighbors_0221 { s16 values[12]; };

void func_ov007_0221a59c(void) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub;extern void **gCurrentMap;
extern u8 gHeapObjectVTable[],gSpriteDesc16x16[],gSpriteDesc16x32[],gSpriteDesc32x16[],gSpriteDesc64x32[];
extern s32 gMapEditorMapNameTileWidth;extern u32 gFrameCounter;
void AddSprite(u16,u8,u16,void*,s32);void func_020a9774(void*,s32,s32,s32,s32);
s32 GetCachedPlayerUnitCount(s32);s32 GetMapEditorMode(void);s32 GetMapEditorUnitOwner(void);s32 MapEditor_GetPropertyCount(void);
void DrawFrameRectBorder(s32,s32,s32,s32);void SetTextSpriteValue(void*,s32);void DrawTextSprite(void*);
void DrawTileRow(u16,u8,u16,u16,s32);s32 MapEditor_PlayerHasTeam(s32);
u8 sp[44];void *saved;s32 i,x,tile,mode,width,height;
saved=gCur3DSpriteEngine;
M2C_FIELD(sp,void **,0)=gHeapObjectVTable;sp[4]=0;
M2C_FIELD(sp,u16 *,18)=0x140;sp[20]=8;sp[21]=8;sp[22]=1;sp[23]=8;sp[24]=8;
sp[33]=0;M2C_FIELD(sp,s32 *,36)=0;sp[41]=0;
sp[32]=(u8)((u8)(sp[32]&~1)&~30);sp[32]=(sp[32]&~224)|64;

sp[40]&=~224;
gCur3DSpriteEngine=g3DSpriteEngineSub;
for(i=0,x=0x85,tile=0x158;i<4;x+=0x1d,tile+=4,i++){
AddSprite((u16)(x&0x1ff),0x9e,(u16)(((u16)((i+5)<<12)|0x400)|(tile&0x3ff)),gSpriteDesc16x16,0);
func_020a9774(sp,x+0x18,0xa6,3,GetCachedPlayerUnitCount(i+1));
}
width=M2C_FIELD(*gCurrentMap,u16 *,0x5144);height=M2C_FIELD(*gCurrentMap,u16 *,0x5146);
DrawFrameRectBorder(64-((width*4)>>1),80-((height*4)>>1),0x80,1);
AddSprite(8,157,(u16)((0x3ff&(360>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(9<<12)),gSpriteDesc16x16,15);
AddSprite(72,141,(u16)((0x3ff&(364>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(10<<12)),gSpriteDesc16x32,15);
mode=GetMapEditorMode();
switch(mode){
case 0:
AddSprite(24,160,(u16)((0x3ff&(372>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(12<<12)),gSpriteDesc32x16,15);
AddSprite(88,160,(u16)((0x3ff&(380>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(11<<12)),gSpriteDesc32x16,15);
func_020a9774(sp,0x38,0x92,4,50-GetCachedPlayerUnitCount(GetMapEditorUnitOwner()));
func_020a9774(sp,0x78,0x92,3,99-MapEditor_GetPropertyCount());
break;
case 1:
AddSprite(24,160,(u16)((0x3ff&(372>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(11<<12)),gSpriteDesc32x16,15);
AddSprite(88,160,(u16)((0x3ff&(380>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(12<<12)),gSpriteDesc32x16,15);
func_020a9774(sp,0x38,0x92,3,50-GetCachedPlayerUnitCount(GetMapEditorUnitOwner()));
func_020a9774(sp,0x78,0x92,4,99-MapEditor_GetPropertyCount());
break;
}
M2C_FIELD(sp,u16 *,18)=0x14c;sp[33]=3;
SetTextSpriteValue(sp,M2C_FIELD(*gCurrentMap,s16 *,0x52c2));
M2C_FIELD(sp,s16 *,6)=0x1e;M2C_FIELD(sp,s16 *,8)=0xb5;DrawTextSprite(sp);
SetTextSpriteValue(sp,M2C_FIELD(*gCurrentMap,s16 *,0x52c4));
M2C_FIELD(sp,s16 *,6)=0x47;M2C_FIELD(sp,s16 *,8)=0xb5;DrawTextSprite(sp);
DrawTileRow((u16)((((0x70-gMapEditorMapNameTileWidth)>>1)+6)&0x1ff),0xff,(u16)gMapEditorMapNameTileWidth,(u16)((0x3ff&(0x1cc>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|0xe000),15);
if(MapEditor_PlayerHasTeam(-1)!=0){
if((gFrameCounter&63)<48){AddSprite(192,180,(u16)((0x3ff&(396>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(13<<12)),gSpriteDesc64x32,15);}
}else{AddSprite(192,180,(u16)((0x3ff&(428>>((u32)(**(u16**)gCur3DSpriteEngine<<17)>>30)))|(13<<12)),gSpriteDesc64x32,15);}
gCur3DSpriteEngine=saved;
}

void func_ov007_0221ab20(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_022200b0;
    CreateSpriteFromClass(&data_ov007_022200b0, 7);
}

void func_ov007_0221ab38(void) {
    M2C_UNK DeleteSpriteObjectsOfClass(M2C_UNK *);
    extern M2C_UNK data_ov007_022200b0;
    DeleteSpriteObjectsOfClass(&data_ov007_022200b0);
}

void MapEditor_RefreshGraphics(void) {
    M2C_UNK MapEditor_LoadPlayerPalettes();
    M2C_UNK func_ov007_02219d10();
    M2C_UNK MapEditor_LoadTerrainBrushGraphics();
    M2C_UNK func_ov007_0221a018();
    M2C_UNK MapEditor_RenderMapName();
    MapEditor_LoadTerrainBrushGraphics();
    func_ov007_0221a018();
    MapEditor_LoadPlayerPalettes();
    func_ov007_02219d10();
    MapEditor_RenderMapName();
}

/* Size the map editor's preview to the map: clear the top screen's third 3D
 * sprite layer and reload its texture, centre the layer's quad over the map's
 * cells (four pixels each), mark the layer changed and rebuild the editor
 * graphics. */
void MapEditor_FitPreviewToMap(void) {
    extern void **gCurrentMap;
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *saved = gCur3DSpriteEngine;
    void *map;
    u32 width, height;

    gCur3DSpriteEngine = g3DSpriteEngineSub;
    Clear3DSpriteLayer(2);
    DrawMapPreviewLayer(DS3D_ENGINE(gCur3DSpriteEngine)->layerVram[2], DS3D_ENGINE(gCur3DSpriteEngine)->layerTiles[2], 1, 14);
    map = *gCurrentMap;
    width = M2C_FIELD(map, u16 *, MAP_WIDTH);
    height = M2C_FIELD(map, u16 *, MAP_HEIGHT);
    DS3D_BANK(gCur3DSpriteEngine)->corner[2] = -(64 - ((s32) (width * 4) >> 1));
    DS3D_BANK(gCur3DSpriteEngine)->corner[6] = -(80 - ((s32) (height * 4) >> 1));
    DS3D_ENGINE(gCur3DSpriteEngine)->layerDirty |= 4;
    gCur3DSpriteEngine = saved;
    MapEditor_RefreshGraphics();
}

/* Set one edited map cell: write its tile id and terrain byte (indexed through
 * the row offsets), then remove the unit standing there if it cannot stand on
 * the new terrain. */
void Map_SetTileAndRefresh(s32 x,s32 y,u16 terrain,u16 tileId) {
extern void **gCurrentMap;
s32 MapEditor_GetUnitKindAt(s32,s32);
s32 Map_CanUnitKindStandOnCell(s32,s32,s32);
void *p=*gCurrentMap;
s32 t;
M2C_FIELD((u8 *)p+2*(x+M2C_FIELD((u8 *)p+2*y,u16 *,MAP_ROW_OFFSETS)),s16 *,MAP_CELL_TILE_ID)=tileId;
p=*gCurrentMap;
M2C_FIELD((u8 *)p+(x+M2C_FIELD((u8 *)p+2*y,u16 *,MAP_ROW_OFFSETS)),s8 *,MAP_CELL_TERRAIN)=terrain;
t=MapEditor_GetUnitKindAt(x,y);
if(t<0)return;
if(Map_CanUnitKindStandOnCell(x,y,t)!=0)return;
MapEditor_DestroyUnitAt(x,y);
}

/* Map editor: returns 2 when the cell already holds this terrain kind and
 * direction, 1 when the tile may be painted there, 0 when it may not. */
s32 Map_CanPlaceTile(s32 x, s32 y, s32 kind, s32 dir) {
    s32 Map_IsTerrainKindPlaceable(s32, s32, s32);
    s32 MapEditor_CheckPlacementLimits(s32, s32, s32, s32);
    s32 Map_GetCellTerrainKind();
    s32 Map_GetCellTerrainOwner(s32, s32);
    if ((kind == Map_GetCellTerrainKind()) && (dir == Map_GetCellTerrainOwner(x, y))) {
        return 2;
    }
    if (Map_IsTerrainKindPlaceable(x, y, kind) == 0) {
        return 0;
    }
    if (MapEditor_CheckPlacementLimits(x, y, kind, dir) != 0) {
        return 1;
    }
    return 0;
}

s32 Map_IsTerrainKindPlaceable(s32 x,s32 y,s32 kind) {
 s32 Map_IsWastelandTile(s32,s32);
 s32 Map_IsBridgeableTile(s32,s32);
 extern u8 data_ov007_0221f544[],data_ov007_0221f52c[],data_ov007_0221f514[];
 s32 i;
 u8 count,diagonal,mask;
 struct TileNeighbors_0221 all;
 struct TileCardinalNeighbors_0221 cardinal, corners;
 u8 *p;
 i=0;count=0;diagonal=0;mask=0;
 switch(kind) {
 case 13:case 14:
 if(Map_IsWastelandTile(x,y))return 1;
 return (u8)(Map_IsBridgeableTile(x,y)!=0);
 case 10:case 12:
 all=*(const struct TileNeighbors_0221 *)data_ov007_0221f544;
 p=(u8 *)&all;
 for(i=0;i<8;i++,p+=6)
 if(!Map_IsWastelandTile(x+*(s16 *)p,y+*(s16 *)(p+2)))return 0;
 break;
 case 9:
 cardinal=*(const struct TileCardinalNeighbors_0221 *)data_ov007_0221f52c;
 p=(u8 *)&cardinal;
 for(i=0;i<4;i++,p+=6) {
 if(!Map_IsWastelandTile(x+*(s16 *)p,y+*(s16 *)(p+2))) {mask|=1<<i;count++;}
 }
 if(count==0)return 0;
 if(count==4)return 0;
 if(mask==9)return 0;
 if(mask==6)return 0;
 if(count==3)return 1;
 corners=*(const struct TileCardinalNeighbors_0221 *)data_ov007_0221f514;
 p=(u8 *)&corners;
 for(i=0;i<4;i++,p+=6)
 if(!Map_IsWastelandTile(x+*(s16 *)p,y+*(s16 *)(p+2)))diagonal|=1<<i;
 if(mask&1) {
 if(!(mask&2) && (diagonal&4))return 0;
 if(!(mask&4) && (diagonal&8))return 0;
 }
 if(mask&8) {
 if(!(mask&2) && (diagonal&1))return 0;
 if(!(mask&4) && (diagonal&2))return 0;
 }
 if(mask&2) {
 if(!(mask&1) && (diagonal&2))return 0;
 if(!(mask&8) && (diagonal&8))return 0;
 }
 if(mask&4) {
 if(!(mask&1) && (diagonal&1))return 0;
 if(!(mask&8) && (diagonal&4))return 0;
 }
 break;
 }
 return 1;
}

/* Map editor placement limits: a terrain kind that is not one of the countable
 * property kinds is always placeable; an HQ (0xF) is refused when its owner
 * already has one; and once the map holds the property maximum (99) a new
 * property may only replace an existing property tile.  Returns 0 when refused. */
s32 MapEditor_CheckPlacementLimits(s32 x, s32 y, s32 kind, s32 owner) {
    s32 IsDestroyedPipeTile(s32);
    s32 Map_GetCellTerrainKind(s32, s32);
    s32 GetEditorUnitCategoryCount(s32, s32);
    s32 MapEditor_GetPropertyCount(void);
    if (IsDestroyedPipeTile(kind) == 0) {
        goto ret1;
    }
    if (kind == 0xF) {
        if (GetEditorUnitCategoryCount(0, owner) > 0) {
            return 0;
        }
    }
    if (MapEditor_GetPropertyCount() < 0x63) {
        goto ret1;
    }
    if (IsDestroyedPipeTile(Map_GetCellTerrainKind(x, y)) == 0) {
        return 0;
    }
ret1:
    return 1;
}

/* Paint tile/direction (tile, dir) at cell (x,y) unless the editor forbids it,
 * then optionally re-evaluate the eight neighbouring cells and redraw the 4x4
 * cells around the edited one. */
s32 Map_PaintTile(s32 x, s32 y, s32 tile, s32 dir, u8 refresh) {
    s32 TerrainByteToTileId(s32);
    void func_02076980(s32, s32, s32, s32);
    void func_0207843c(s32, s32, s32, s32);
    s32 Map_CanPlaceTile(s32, s32, s32, s32);
    void Map_SetTileAndRefresh(s32, s32, u16, u16);
    void Map_RefreshCellTile(s32, s32);
    s32 Map_IsWastelandTile(s32, s32);
    s32 Map_IsBridgeableTile(s32, s32);
    extern void **gCurrentMap;
    extern u8 data_ov007_0221f574[];

    s32 encodedTile;
    s32 graphic;
    struct TileNeighbors_0221 neighbors;
    s32 result;
    s32 i;
    u8 *offset;

    encodedTile = tile | (dir << 5);
    graphic = TerrainByteToTileId(encodedTile);

    result = Map_CanPlaceTile(x, y, tile, dir);
    if (result != 1) {
        return result;
    }
    switch (tile) {
    case 0x1b:
        if (Map_IsWastelandTile(x, y) != 0) {
            encodedTile = 0x3b;
            graphic = 0x146;
        }
        break;
    case 0x1c:
        if (Map_IsWastelandTile(x, y) != 0) {
            encodedTile = 0x3c;
            graphic = 0x166;
        }
        break;
    case 0x0d:
        if (Map_IsBridgeableTile(x, y) != 0) {
            encodedTile = 0x0e;
            graphic = 0x25;
        }
        break;
    }

    Map_SetTileAndRefresh(x, y, (u16)encodedTile, (u16)graphic);

    if (refresh != 0) {

    neighbors = *(const struct TileNeighbors_0221 *)data_ov007_0221f574;
    offset = (u8 *)&neighbors;
    i = 0;
    do {
        s32 nx = x + *(s16 *)offset;
        s32 ny = y + *(s16 *)(offset + 2);
        if (nx >= 0 && ny >= 0) {
            void *map = *gCurrentMap;
            if (nx < (s32) M2C_FIELD(map, u16 *, 0x5144) && ny < (s32) M2C_FIELD(map, u16 *, 0x5146)) {
                Map_RefreshCellTile(nx, ny);
            }
        }
        i++;
        offset += 6;
    } while (i < 8);

    func_02076980(x - 2, y - 2, x + 2, y + 2);
    func_0207843c(x - 2, y - 2, x + 2, y + 2);

    }
    return 1;
}

/* Whether the map cell at (x,y) is in bounds and holds the given terrain kind
 * and owner/direction, as the map editor's flood fill compares them. */
s32 Map_IsCellTileAndOwner(s32 x,s32 y,s32 kind,s32 owner) {
extern void **gCurrentMap;
s32 Map_GetCellTerrainKind(s32,s32);
s32 Map_GetCellTerrainOwner(s32,s32);
void *map;
if(x>=0 && y>=0) {
map=*gCurrentMap;
if(x<M2C_FIELD(map,u16 *,MAP_WIDTH)&&y<M2C_FIELD(map,u16 *,MAP_HEIGHT)) goto valid;
}
return 0;
valid:
if(kind!=Map_GetCellTerrainKind(x,y))return 0;
return (u8)(owner==Map_GetCellTerrainOwner(x,y));
}

/* Flood-fills a connected 30x30 region of tiles currently matching oldTile/oldDir,
   converting each one to newTile/newDir (and extending to its neighbours). */
s32 func_ov007_0221b2cc(s32 x, s32 y, M2C_UNK newTile, M2C_UNK newDir, s32 oldTile, s32 oldDir) {
    s32 Map_PaintTile(s32, s32, M2C_UNK, M2C_UNK, u8);
    s32 Map_IsCellTileAndOwner(s32, s32, s32, s32);
    s32 rightX;
    s32 bottomY;
    s32 topY;
    s32 nextY;
    s32 iLeft;
    s32 iRight;
    s32 iUp;
    s32 iDown;
    s32 leftX;

    if (Map_IsCellTileAndOwner(x, y, oldTile, oldDir) == 0) {
        return 0;
    }
    if (Map_PaintTile(x, y, newTile, newDir, 0) == 0) {
        return 0;
    }
    leftX = x;
    rightX = x;
    topY = y;
    bottomY = y;
    iLeft = x - 1;
    if (iLeft >= 0) {
loop_5:
        if ((Map_IsCellTileAndOwner(iLeft, y, oldTile, oldDir) != 0) && (Map_PaintTile(iLeft, y, newTile, newDir, 0) != 0)) {
            leftX = iLeft;
            iLeft -= 1;
            if (iLeft >= 0) {
                goto loop_5;
            }
        }
    }
    iRight = x + 1;
    if (iRight < 0x1E) {
loop_9:
        if ((Map_IsCellTileAndOwner(iRight, y, oldTile, oldDir) != 0) && (Map_PaintTile(iRight, y, newTile, newDir, 0) != 0)) {
            rightX = iRight;
            iRight += 1;
            if (iRight < 0x1E) {
                goto loop_9;
            }
        }
    }
    iUp = y - 1;
    if (iUp >= 0) {
loop_13:
        if ((Map_IsCellTileAndOwner(x, iUp, oldTile, oldDir) != 0) && (Map_PaintTile(x, iUp, newTile, newDir, 0) != 0)) {
            topY = iUp;
            iUp -= 1;
            if (iUp >= 0) {
                goto loop_13;
            }
        }
    }
    iDown = y + 1;
    if (iDown < 0x1E) {
loop_17:
        if ((Map_IsCellTileAndOwner(x, iDown, oldTile, oldDir) != 0) && (Map_PaintTile(x, iDown, newTile, newDir, 0) != 0)) {
            bottomY = iDown;
            iDown += 1;
            if (iDown < 0x1E) {
                goto loop_17;
            }
        }
    }
    if (leftX <= rightX) {
        do {
            func_ov007_0221b2cc(leftX, y - 1, newTile, newDir, oldTile, oldDir);
            func_ov007_0221b2cc(leftX, y + 1, newTile, newDir, oldTile, oldDir);
            leftX += 1;
        } while (leftX <= rightX);
    }
    if (topY <= bottomY) {
        do {
            func_ov007_0221b2cc(x - 1, topY, newTile, newDir, oldTile, oldDir);
            func_ov007_0221b2cc(x + 1, topY, newTile, newDir, oldTile, oldDir);
            nextY = topY + 1;
            topY = nextY;
        } while (nextY <= bottomY);
    }
    return 1;
}

