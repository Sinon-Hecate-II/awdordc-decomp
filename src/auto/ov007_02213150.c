/* 22 functions from 0x02213150 to 0x02213E88 (ov007), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
#include "ds3dsprite.h"
static inline void SyncSprite13554(s32 p) {
s32 GetUnitSpriteWidth(s32);s32 GetUnitSpriteHeight(s32);
void func_02087d84(s32,s32,s32,s32,s32,s32);
s16 y,x;s32 w;
if((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)){
y=M2C_FIELD(p,s16*,0x52);x=M2C_FIELD(p,s16*,0x50);w=GetUnitSpriteWidth(p);
func_02087d84(M2C_FIELD(p,s32*,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));
}
}

/* Refreshes 8 sprites for the current mode, then runs mode post-processing. */
void func_ov007_02213150(void) {
    M2C_UNK func_02088eec(s32, M2C_UNK);
    M2C_UNK func_ov007_02212dcc();
    void func_ov007_0221327c();
    extern M2C_UNK data_ov007_02221a50;
    s32 mode;

    func_ov007_0221327c();
    mode = GetMapEditorMode();
    if (mode != 0) {
        if (mode == 1) {
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 8), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 4), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0xC), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x10), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x14), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x18), 6);
            func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x1C), 6);
        }
    } else {
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 8), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 4), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x20), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x24), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x28), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x2C), 6);
        func_02088eec(M2C_FIELD(&data_ov007_02221a50, s32 *, 0x30), 6);
    }
    func_ov007_02212dcc();
}

void func_ov007_0221327c(void) {
    M2C_UNK Start3DSpriteSlideOut(s32, M2C_UNK);
    s32 Is3DSpriteVisible(s32);
    extern M2C_UNK data_ov007_02221a50;
    s32 i;
    i = 0;
    do {
        if (Is3DSpriteVisible(((s32 *)&data_ov007_02221a50)[i]) != 0)
            Start3DSpriteSlideOut(((s32 *)&data_ov007_02221a50)[i], 4);
        i++;
    } while (i < 13);
}

void func_ov007_022132bc(void) {
    M2C_UNK SetMapEditorMode(M2C_UNK);
    s32 GetMapEditorMode();
    M2C_UNK SetMapEditorTool(M2C_UNK);
    M2C_UNK MapEditor_RefreshGraphics();
    s32 temp_r0;

    temp_r0 = GetMapEditorMode();
    if (temp_r0 != 0) {
        if (temp_r0 == 1) {
            SetMapEditorMode(0);
            SetMapEditorTool(0);
        }
    } else {
        SetMapEditorMode(1);
        SetMapEditorTool(0);
    }
    MapEditor_RefreshGraphics();
    PlaySoundEffect(0x10020);
}

void func_ov007_0221330c(void) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f6b0;
    CreateSpriteFromClass(&data_ov007_0221f6b0, 7);
}

u8 func_ov007_02213324(void) {
    s32 IsCampaignMapRecordValid(u16);
    extern void **gCurrentMap;
    u8 var_r0;

    if (IsCampaignMapRecordValid(M2C_FIELD(*gCurrentMap, u16 *, 0x5142)) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov007_02213358(void) {
    return 2;
}

void func_ov007_02213360(void) {
    M2C_UNK func_ov007_0221c51c();
    func_ov007_0221c51c();
}

void func_ov007_0221336c(void) {
    M2C_UNK func_ov007_0221c630();
    func_ov007_0221c630();
}

void func_ov007_02213378(void *arg0) {
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK RefreshMapView();
    M2C_UNK RefreshMapEditor();
    M2C_UNK MapEditor_SetMapModified(M2C_UNK);
    M2C_UNK FillMapTerrain(s32);
    M2C_UNK MapEditor_FitPreviewToMap();
    FillMapTerrain(M2C_FIELD(arg0, s32 *, 0x5C));
    RefreshMapView();
    RefreshMapEditor();
    MapEditor_FitPreviewToMap();
    MapEditor_SetMapModified(1);
    PlaySoundEffect(0x11D);
}

void func_ov007_022133a8(s32 arg0, s32 arg1) {
    M2C_UNK CreateSpriteFromClass(M2C_UNK *, M2C_UNK);
    void SetUiMessageText(s32);
    extern M2C_UNK data_ov007_0221f7c0;
    SetUiMessageText(arg0);
    M2C_FIELD(CreateSpriteFromClass(&data_ov007_0221f7c0, 7), s32 *, 0x5C) = arg1;
}

void func_ov007_022133cc(void) {
    void func_ov007_022133a8(M2C_UNK, M2C_UNK);
    func_ov007_022133a8(0x46000000, 8);
}

void func_ov007_022133e0(void) {
    func_ov007_022133a8(0x46000001, 1);
}

void func_ov007_022133f8(void) {
    func_ov007_022133a8(0x46000002, 4);
}

void func_ov007_02213410(void) {
    func_ov007_022133a8(0x46000003, 3);
}

void func_ov007_02213428(void) {
    func_ov007_022133a8(0x46000004, -1);
}

void func_ov007_02213440(M2C_UNK arg0, M2C_UNK arg1) {
M2C_UNK func_020c0b88(M2C_UNK);
M2C_UNK PopCarriedUnitMenuState();
func_020c0b88(arg1);
DeleteMapMenuSprites();
PopCarriedUnitMenuState();
}

/* Opens the map editor's map-fill menu: saves the carried-unit menu, hides the
   map's menu sprites and the editor's sprite layer and refreshes the map view,
   then builds the menu from the fill-preset entries at its saved selection. */
void OpenMapEditorFillMenu(void) {
    M2C_UNK PushCarriedUnitMenuState();
    M2C_UNK DeleteMapMenuSprites();
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK RefreshMapView();
    s32 func_020c0b9c();
    M2C_UNK func_020c0634(M2C_UNK *, s32, s32, u16, s32);
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK gMapEditorFillMenuEntries;
    PushCarriedUnitMenuState();
    DeleteMapMenuSprites();
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, DS3D_ENGINE_DIRTY) |= DS3D_DIRTY_LAYER1;
    RefreshMapView();
    func_020c0634(&gMapEditorFillMenuEntries, 0x60, 0x30, (u16)func_020c0b9c(), 0x50);
}

/* Apply the map size chosen in the map-size panel (request->38 width,
 * request->3C height): rebuild the editor map, refresh both views, center the
 * map view on the new map and update the view's zoom colours. */
void MapEditor_ApplyMapSize(void *request) {
    M2C_UNK LoadMapFromExport(s32, s32);
    M2C_UNK SetMapViewPositionToTileCentered(u32, u32);
    M2C_UNK UpdateViewForZoom(void *);
    extern void **gCurrentMap;
    void *map;

    LoadMapFromExport(M2C_FIELD(request, s32 *, 0x38), M2C_FIELD(request, s32 *, 0x3C));
    RefreshMapView();
    RefreshMapEditor();
    MapEditor_FitPreviewToMap();
    MapEditor_SetMapModified(1);
    map = *gCurrentMap;
    SetMapViewPositionToTileCentered((u32)M2C_FIELD(map, u16 *, MAP_WIDTH) >> 1, (u32)M2C_FIELD(map, u16 *, MAP_HEIGHT) >> 1);
    UpdateViewForZoom((u8 *)*gCurrentMap + MAP_VIEW_ZOOM);
    PlaySoundEffect(0x11D);
}

void func_ov007_0221352c(s32 arg0, s32 arg1) {
    extern M2C_UNK data_ov007_0221f740;
    void *temp_r0;

    temp_r0 = CreateSpriteFromClass(&data_ov007_0221f740, 7);
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg1;
}

#pragma push
#pragma opt_propagation off
void func_ov007_02213554(void *arg0) {
    M2C_UNK SetFileDirectory(M2C_UNK);
    void *GetLocalizedFileName(M2C_UNK);
    void OpenNarcArchive(M2C_UNK);
    void LoadNarcFileDecompressed(M2C_UNK, M2C_UNK);
    void CloseNarcArchive(void);
    void LoadFileToSpriteBuffer(M2C_UNK, M2C_UNK, M2C_UNK);
    void *CreateFrameBorderSprite(M2C_UNK);
    void func_02089424(void*);
    M2C_UNK LoadSpriteResource(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void *func_020ab1c4(M2C_UNK);
    void InitUnitSprite(M2C_UNK, u8, u16, u8, u8);
    void Set3DSpriteSlideTargetAndStart(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK GetUnitSpriteWidth(M2C_UNK);
    M2C_UNK GetUnitSpriteHeight(M2C_UNK);
    void func_02087d84(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_020ab150(M2C_UNK, M2C_UNK);
    void Show3DSpriteSlide(M2C_UNK);
    extern M2C_UNK data_ov007_0221fdb0, data_ov007_0221fdbc, data_ov007_0221fdcc, data_ov007_0221fdd8, data_ov007_0221fde4;
    extern void *gCur3DSpriteEngine;
    extern void **gCurrentMap;

    void *r4 = arg0;
    u16 tile;
    s16 y,x;
    s32 w, p;

    SetFileDirectory(&data_ov007_0221fdb0);
    M2C_FIELD(*(void **) gCur3DSpriteEngine, u16 *, 0x3A) = 0;
    M2C_FIELD(*(void **) gCur3DSpriteEngine, u16 *, 0x42) = 0;
    OpenNarcArchive(GetLocalizedFileName(&data_ov007_0221fdbc));
    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov007_0221fdcc), M2C_FIELD(gCur3DSpriteEngine, void **, 0x10));
    LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov007_0221fdd8), M2C_FIELD(gCur3DSpriteEngine, void **, 0x24));
    CloseNarcArchive();
    LoadFileToSpriteBuffer(&data_ov007_0221fde4, 0, 0x20);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(r4, s32 *, 0x34) = M2C_FIELD(*gCurrentMap, u16 *, 0x5144);
    M2C_FIELD(r4, s32 *, 0x38) = M2C_FIELD(*gCurrentMap, u16 *, 0x5146);
    M2C_FIELD(r4, s32 *, 0x3C) = 0;
    func_02089424(CreateFrameBorderSprite(r4));
    {void *engine=gCur3DSpriteEngine;LoadSpriteResource(1, 0, 3, M2C_FIELD(engine,s32*,0x1C)+0x6B80);}
    {void *engine=gCur3DSpriteEngine;LoadSpriteResource(1, 2, 0, M2C_FIELD(engine,s32*,0x30)+0x360);}
    tile=0x39c;{void *engine=gCur3DSpriteEngine;LoadSpriteResource(0, 2, 0x47, M2C_FIELD(engine,s32*,0x30)+0x260);}
M2C_FIELD(r4,void**,64)=func_020ab1c4(r4);InitUnitSprite(M2C_FIELD(r4,void**,64),8,tile,3,0);{s32 p=M2C_FIELD(r4,s32*,64);Set3DSpriteSlideTargetAndStart(p,88,80,88,80);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) {
        y = M2C_FIELD(p,s16*,0x52);
        x = M2C_FIELD(p,s16*,0x50);
        w = GetUnitSpriteWidth(p);
        func_02087d84(M2C_FIELD(p,s32*,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));
    }M2C_FIELD(p,s16*,0x34)=88;M2C_FIELD(p,s16*,0x36)=80;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) {
        y = M2C_FIELD(p,s16*,0x52);
        x = M2C_FIELD(p,s16*,0x50);
        w = GetUnitSpriteWidth(p);
        func_02087d84(M2C_FIELD(p,s32*,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));
    }}func_020ab150(M2C_FIELD(r4,s32*,64),0);tile=(u16)(tile+8);M2C_FIELD(r4,void**,68)=func_020ab1c4(r4);InitUnitSprite(M2C_FIELD(r4,void**,68),9,tile,3,0);{s32 p=M2C_FIELD(r4,s32*,68);Set3DSpriteSlideTargetAndStart(p,88,112,88,112);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) {
        y = M2C_FIELD(p,s16*,0x52);
        x = M2C_FIELD(p,s16*,0x50);
        w = GetUnitSpriteWidth(p);
        func_02087d84(M2C_FIELD(p,s32*,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));
    }M2C_FIELD(p,s16*,0x34)=88;M2C_FIELD(p,s16*,0x36)=112;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) {
        y = M2C_FIELD(p,s16*,0x52);
        x = M2C_FIELD(p,s16*,0x50);
        w = GetUnitSpriteWidth(p);
        func_02087d84(M2C_FIELD(p,s32*,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));
    }}func_020ab150(M2C_FIELD(r4,s32*,68),0);tile=(u16)(tile+8);M2C_FIELD(r4,void**,72)=func_020ab1c4(r4);InitUnitSprite(M2C_FIELD(r4,void**,72),8,tile,3,0);{s32 p=M2C_FIELD(r4,s32*,72);Set3DSpriteSlideTargetAndStart(p,136,80,136,80);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) {
        y = M2C_FIELD(p,s16*,0x52);
        x = M2C_FIELD(p,s16*,0x50);
        w = GetUnitSpriteWidth(p);
        func_02087d84(M2C_FIELD(p,s32*,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));
    }M2C_FIELD(p,s16*,0x34)=136;M2C_FIELD(p,s16*,0x36)=80;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) {
        y = M2C_FIELD(p,s16*,0x52);
        x = M2C_FIELD(p,s16*,0x50);
        w = GetUnitSpriteWidth(p);
        func_02087d84(M2C_FIELD(p,s32*,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));
    }}func_020ab150(M2C_FIELD(r4,s32*,72),0);tile=(u16)(tile+8);M2C_FIELD(r4,void**,76)=func_020ab1c4(r4);InitUnitSprite(M2C_FIELD(r4,void**,76),9,tile,3,0);{s32 p=M2C_FIELD(r4,s32*,76);Set3DSpriteSlideTargetAndStart(p,136,112,136,112);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) {
        y = M2C_FIELD(p,s16*,0x52);
        x = M2C_FIELD(p,s16*,0x50);
        w = GetUnitSpriteWidth(p);
        func_02087d84(M2C_FIELD(p,s32*,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));
    }M2C_FIELD(p,s16*,0x34)=136;M2C_FIELD(p,s16*,0x36)=112;if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) {
        y = M2C_FIELD(p,s16*,0x52);
        x = M2C_FIELD(p,s16*,0x50);
        w = GetUnitSpriteWidth(p);
        func_02087d84(M2C_FIELD(p,s32*,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));
    }}func_020ab150(M2C_FIELD(r4,s32*,76),0);tile=(u16)(tile+8);{p=(s32)func_020ab1c4(r4);InitUnitSprite(p,0,tile,3,0);Set3DSpriteSlideTargetAndStart(p,192,160,256,160);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) {
        y = M2C_FIELD(p,s16*,0x52);
        x = M2C_FIELD(p,s16*,0x50);
        w = GetUnitSpriteWidth(p);
        func_02087d84(M2C_FIELD(p,s32*,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));
    }func_020ab150(p,1);Show3DSpriteSlide(p);}{p=(s32)func_020ab1c4(r4);InitUnitSprite(p,2,(u16)(tile+16),3,0);Set3DSpriteSlideTargetAndStart(p,224,160,256,160);if ((u8)(M2C_FIELD(M2C_FIELD(p,void**,0x64),u8*,0x12)!=0)) {
        y = M2C_FIELD(p,s16*,0x52);
        x = M2C_FIELD(p,s16*,0x50);
        w = GetUnitSpriteWidth(p);
        func_02087d84(M2C_FIELD(p,s32*,0x64),1,x,y,(u16)w,(u16)GetUnitSpriteHeight(p));
    }func_020ab150(p,2);Show3DSpriteSlide(p);}}
#pragma pop
void func_ov007_02213cf4(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    Clear3DSpriteLayer(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

/* Configures the 3D sprite engine for the requested unit selection mode (arg0->0x3c, 0 or 1), then draws a tile-selection panel sprite via DrawTextSprite. */
void func_ov007_02213d1c(void *obj) {
    void *FindFrameBorderSprite(void);
    extern u8 gHeapObjectVTable[];
    u32 sp[11];
    void *engine = FindFrameBorderSprite();
    switch (M2C_FIELD(obj, s32 *, 0x3c)) {
    case 0:
        M2C_FIELD(engine, s16 *, 0x34) = 0x5c;
        M2C_FIELD(engine, s16 *, 0x36) = 0x60;
        M2C_FIELD(engine, s32 *, 0x40) = (M2C_FIELD(engine, s32 *, 0x40) & ~0x1ff) | 0x18;
        M2C_FIELD(engine, s32 *, 0x40) = (M2C_FIELD(engine, s32 *, 0x40) & 0xfffc01ff) | 0x2000;
        break;
    case 1:
        M2C_FIELD(engine, s16 *, 0x34) = 0x8c;
        M2C_FIELD(engine, s16 *, 0x36) = 0x60;
        M2C_FIELD(engine, s32 *, 0x40) = (M2C_FIELD(engine, s32 *, 0x40) & ~0x1ff) | 0x18;
        M2C_FIELD(engine, s32 *, 0x40) = (M2C_FIELD(engine, s32 *, 0x40) & 0xfffc01ff) | 0x2000;
        break;
    }
    M2C_FIELD(sp, void **, 0) = gHeapObjectVTable;
    M2C_FIELD(sp, u8 *, 4) = 0;
    M2C_FIELD(sp, u8 *, 0x14) = 8;
    M2C_FIELD(sp, u8 *, 0x15) = 8;
    M2C_FIELD(sp, u8 *, 0x16) = 1;
    M2C_FIELD(sp, u8 *, 0x17) = 8;
    M2C_FIELD(sp, u8 *, 0x18) = 8;
    M2C_FIELD(sp, u8 *, 0x20) = ((u8)((u8)(M2C_FIELD(sp, u8 *, 0x20) & ~1) & ~0x1e) & ~0xe0) | 0x40;
    M2C_FIELD(sp, u32 *, 0x24) = 0;
    M2C_FIELD(sp, u8 *, 0x29) = 0;
    M2C_FIELD(sp, u16 *, 0x12) = 0x35c;
    M2C_FIELD(sp, u8 *, 0x21) = 11;
    M2C_FIELD(sp, u8 *, 0x28) = ((u8)(M2C_FIELD(sp, u8 *, 0x28) & ~0xe0) & ~0x1f) | 0x11;
    SetTextSpriteFont(sp, 3);
    SetTextSpriteValue(sp, M2C_FIELD(obj, s32 *, 0x34));
    M2C_FIELD(sp, s16 *, 6) = 0x75;
    M2C_FIELD(sp, s16 *, 8) = 0x60;
    DrawTextSprite(sp);
    SetTextSpriteValue(sp, M2C_FIELD(obj, s32 *, 0x38));
    M2C_FIELD(sp, s16 *, 6) = 0xa5;
    M2C_FIELD(sp, s16 *, 8) = 0x60;
    DrawTextSprite(sp);
}

