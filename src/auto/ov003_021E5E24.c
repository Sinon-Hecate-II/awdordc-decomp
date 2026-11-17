/* 35 functions from 0x021E5E24 to 0x021E6E18 (ov003), found by ds-decomp. */
#include "common.h"
typedef struct { u32 played:1;u32 rest:31; } MapPlayedFlag;
typedef struct {u32 first:8;u32 second:6;u32 third:6;u32 rest:12;} MapStampCounts;

void func_ov003_021e5e24(void *arg0,s32 slide) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub;extern u8 data_ov003_0220f60e[],gSpriteDesc16x16[];
void *GetMapRecord(s32);void *GetMapRecordStamp(s32);s32 GetMapIconFrameIndex(s32);s32 GetMapListIconTile(s32,s32);
void AddSprite(u16,u16,u16,void*,s32);void DrawFrameBorder(s16,s16,s16,s16,u16,s32,s32);
s32 captured=0,played=0,offset=0;void *record;void *saved;u16 tile;u8 row,column;s32 width,height,labelX;void *text;
record=GetMapRecord(225);
if(M2C_FIELD(record,u8*,0x2f))captured=1;
if(((MapPlayedFlag*)((u8*)record+0x38))->played)played=1;
if(captured){if(played)offset=-64;tile=(u16)((GetMapIconFrameIndex(7)<<4)+0x140);
AddSprite((u16)((slide+192+offset)&511),28,(u16)((1023&(tile>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0)<<17)>>30)))|0x6000),data_ov003_0220f60e,11);
}
if(played){tile=(u16)((GetMapIconFrameIndex(12)<<4)+0x140);
AddSprite((u16)((slide+192)&511),28,(u16)((1023&(tile>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0)<<17)>>30)))|0x6000),data_ov003_0220f60e,11);}
width=M2C_FIELD(arg0,s16*,0x62);height=M2C_FIELD(arg0,s16*,0x64);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0x38)=-(164-width/2+slide);
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0x40)=-(108-height/2);
DrawFrameBorder((s16)(163-M2C_FIELD(arg0,s16*,0x62)/2+slide),(s16)(107-M2C_FIELD(arg0,s16*,0x64)/2),(s16)(M2C_FIELD(arg0,s16*,0x62)+2),(s16)(M2C_FIELD(arg0,s16*,0x64)+2),(u16)((1023&(0x288>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0)<<17)>>30)))|0xa000),17,1);
tile=(u16)(GetMapListIconTile(7,225)*4+0x328);
AddSprite((u16)((slide+3)&511),21,(u16)((1023&(tile>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0)<<17)>>30)))|0x9800),gSpriteDesc16x16,17);
record=GetMapRecordStamp(225);labelX=slide+64;
for(row=0;row<2;row++){
s32 value;
switch(row){
case 0:
value=(u32)(M2C_FIELD(record,u32*,12)<<4)>>22;saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
SetTextSpriteValue(M2C_FIELD(arg0,s32*,0x50),value);
text=M2C_FIELD(arg0,void**,0x50);M2C_FIELD(text,u16*,6)=labelX;M2C_FIELD(text,u16*,8)=59;
DrawTextSprite(M2C_FIELD(arg0,void**,0x50));gCur3DSpriteEngine=saved;break;
case 1:
M2C_FIELD(M2C_FIELD(arg0,void**,0x50),u8*,0x29)=2;saved=gCur3DSpriteEngine;
for(column=0;column<3;column++){
if(column==0)value=((MapStampCounts*)((u8*)record+8))->first;else if(column==1)value=((MapStampCounts*)((u8*)record+8))->second;else if(column==2)value=((MapStampCounts*)((u8*)record+8))->third;
gCur3DSpriteEngine=g3DSpriteEngineSub;SetTextSpriteValue(M2C_FIELD(arg0,s32*,0x50),(s16)value);
text=M2C_FIELD(arg0,void**,0x50);M2C_FIELD(text,u16*,6)=column*22+slide+20;
M2C_FIELD(text,u16*,8)=69;
DrawTextSprite(M2C_FIELD(arg0,void**,0x50));gCur3DSpriteEngine=saved;
}M2C_FIELD(M2C_FIELD(arg0,void**,0x50),u8*,0x29)=0;break;
}
}
}

M2C_UNK func_ov003_021e6204(M2C_UNK arg0) {
    M2C_UNK SetOv003SceneState(s32);
    M2C_UNK func_ov006_02218328(M2C_UNK);
    SetOv003SceneState(1);
    return func_ov006_02218328(arg0);
}

void func_ov003_021e6220(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0xC)(arg0);
}

/* Sets up rendering layer 0xE1 and its dimensions for the given object. */
void func_ov003_021e6234(void *obj) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK ClearTileRect(s32, M2C_UNK, M2C_UNK);
    M2C_UNK DrawTextLine(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    M2C_UNK ResetMapUnits();
    M2C_UNK SetTextSpriteValue(s32, s32);
    M2C_UNK func_020c12f8(s32, s32, s32, M2C_UNK);
    M2C_UNK func_020c1878(s32);
    M2C_UNK LoadBattleMap(M2C_UNK);
    M2C_UNK func_020cf278(M2C_UNK);
    s32 GetMapName(M2C_UNK);
    s32 func_ov006_02217d0c();
    extern void **gCurrentMap;
    extern void *g3DSpriteEngineSub;
    extern void *gCur3DSpriteEngine;
    void *savedContext;

    ResetMapUnits();
    func_020cf278(0xE1);
    LoadBattleMap(0xE1);
    M2C_FIELD(obj, s16 *, 0x62) = (s16) (M2C_FIELD(*gCurrentMap, u16 *, 0x5144) * 4);
    M2C_FIELD(obj, s16 *, 0x64) = (s16) (M2C_FIELD(*gCurrentMap, u16 *, 0x5146) * 4);
    func_020c1878(M2C_FIELD(obj, s32 *, 0x68) + 4);
    savedContext = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    ClearTileRect(M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x2C), 9, 2);
    DrawTextLine(0, 0, 3, GetMapName(0xE1), 0x9000, 0x11);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
    Clear3DSpriteLayer(0);
    func_020c12f8(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0xC), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), 0x143, 5);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    gCur3DSpriteEngine = savedContext;
    SetTextSpriteValue(M2C_FIELD(obj, s32 *, 0x58), func_ov006_02217d0c());
}

void func_ov003_021e635c(void) {
    M2C_UNK func_ov003_021e583c();
    func_ov003_021e583c();
}

void func_ov003_021e6368(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x14)(arg0);
}

void func_ov003_021e637c(void *arg0) {
    M2C_UNK func_02088f1c(s32);
    void *temp_r1;
    void *temp_r3;
    void *temp_r3_2;

    temp_r3 = M2C_FIELD(arg0, void **, 0x3C);
    M2C_FIELD(temp_r3, s16 *, 0xE) = 0x100;
    M2C_FIELD(temp_r3, s16 *, 0x10) = 0;
    M2C_FIELD(temp_r3, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r3, u16 *, 2) = (u16) M2C_FIELD(temp_r3, u16 *, 4);
    temp_r3_2 = M2C_FIELD(arg0, void **, 0x40);
    M2C_FIELD(temp_r3_2, s16 *, 0xE) = 0xC0;
    M2C_FIELD(temp_r3_2, s16 *, 0x10) = 0x68;
    M2C_FIELD(temp_r3_2, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r3_2, u16 *, 2) = (u16) M2C_FIELD(temp_r3_2, u16 *, 4);
    temp_r1 = M2C_FIELD(arg0, void **, 0x44);
    M2C_FIELD(temp_r1, s16 *, 0xE) = 0xC0;
    M2C_FIELD(temp_r1, s16 *, 0x10) = 0x90;
    M2C_FIELD(temp_r1, s16 *, 0xC) = 0xC;
    M2C_FIELD(temp_r1, u16 *, 2) = (u16) M2C_FIELD(temp_r1, u16 *, 4);
    func_02088f1c(M2C_FIELD(arg0, s32 *, 0x5C));
    func_02088f1c(*M2C_FIELD(arg0, s32 **, 0x48));
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
}

void func_ov003_021e6404(void) {
    M2C_UNK func_ov003_021e5b18();
    func_ov003_021e5b18();
}

void func_ov003_021e6410(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x18)(arg0);
}

void func_ov003_021e6424(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x60)) return;
}

void func_ov003_021e6430(void **arg0) {
    M2C_FIELD(*arg0, void (**)(void *), 0x10)(arg0);
}

u8 func_ov003_021e6444(void *arg0) {
    s32 var_r0_2;
    u8 var_r0;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x3C);
    if (M2C_FIELD(temp_r0, u16 *, 2) == M2C_FIELD(temp_r0, s16 *, 0xC)) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (!(var_r0_2 & 0xFF)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021e6470(void) {
    M2C_UNK func_ov003_021e6204();
    func_ov003_021e6204();
}

u8 func_ov003_021e647c(void *arg0) {
    s32 IsMapConfirmEnabled();
    M2C_FIELD(arg0, u8 *, 0x60) = 0;
    M2C_FIELD(arg0, u8 *, 0x60) = IsMapConfirmEnabled() == 0;
    return M2C_FIELD(arg0, u8 *, 0x60);
}

void func_ov003_021e64a8(M2C_UNK arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    M2C_UNK **MemAlloc(M2C_UNK);
    M2C_UNK func_020e4c64();
    M2C_UNK func_ov003_021f13ec(M2C_UNK *);
    extern M2C_UNK data_02102174;
    extern M2C_UNK gHeapObjectVTable;
    extern M2C_UNK data_ov003_0220f48c;
    extern M2C_UNK data_ov003_0220f650;
    extern M2C_UNK data_ov003_0220f6f8;
    extern M2C_UNK data_ov003_0220f700;
    extern M2C_UNK data_ov003_0220f710;
    extern M2C_UNK gOv003SceneVTable;
    extern M2C_UNK gOv003SceneIfaceVTable;
    M2C_UNK **temp_ip;
    M2C_UNK **temp_ip_2;
    M2C_UNK **temp_r0_10;
    M2C_UNK **temp_r0_2;
    M2C_UNK **temp_r0_3;
    M2C_UNK **temp_r0_4;
    M2C_UNK **temp_r0_5;
    M2C_UNK **temp_r0_6;
    M2C_UNK **temp_r0_7;
    M2C_UNK **temp_r0_8;
    M2C_UNK **temp_r0_9;
    M2C_UNK **temp_r2;
    M2C_UNK **temp_r2_2;
    M2C_UNK **temp_r2_3;
    M2C_UNK **temp_r2_4;
    void *temp_r0;

    func_ov003_021f13ec(&data_ov003_0220f650);
    temp_r0 = func_01ffa3dc(&data_ov003_0220f650, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02102174;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &data_ov003_0220f48c;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &gOv003SceneVTable;
    M2C_FIELD(temp_r0, M2C_UNK **, 0x34) = &gOv003SceneIfaceVTable;
    M2C_FIELD(temp_r0, s8 *, 0x38) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x39) = 0;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x4C) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x54) = NULL;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x58) = NULL;
    M2C_FIELD(temp_r0, s32 *, 0x5C) = 0;
    M2C_FIELD(temp_r0, s8 *, 0x60) = 0;
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x68) = NULL;
    func_020e4c64();
    temp_r0_2 = MemAlloc(0x40);
    if (temp_r0_2 != NULL) {
        *temp_r0_2 = &data_ov003_0220f710;
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x68) = temp_r0_2;
    temp_r0_3 = MemAlloc(0x12);
    if (temp_r0_3 != NULL) {
        M2C_FIELD(temp_r0_3, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_3, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_3, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_3, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_3, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_3, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_3, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_3, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_3, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_3, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_3, u16 *, 2) = (u16) M2C_FIELD(temp_r0_3, u16 *, 4);
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x3C) = temp_r0_3;
    temp_r0_4 = MemAlloc(0x12);
    if (temp_r0_4 != NULL) {
        M2C_FIELD(temp_r0_4, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_4, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_4, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_4, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_4, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_4, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_4, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_4, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_4, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_4, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_4, u16 *, 2) = (u16) M2C_FIELD(temp_r0_4, u16 *, 4);
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x40) = temp_r0_4;
    temp_r0_5 = MemAlloc(0x12);
    if (temp_r0_5 != NULL) {
        M2C_FIELD(temp_r0_5, s8 *, 0) = 4;
        M2C_FIELD(temp_r0_5, s8 *, 1) = 0;
        M2C_FIELD(temp_r0_5, u16 *, 2) = 0U;
        M2C_FIELD(temp_r0_5, u16 *, 4) = 0U;
        M2C_FIELD(temp_r0_5, s16 *, 6) = 1;
        M2C_FIELD(temp_r0_5, s16 *, 8) = 0;
        M2C_FIELD(temp_r0_5, s16 *, 0xA) = 1;
        M2C_FIELD(temp_r0_5, s16 *, 0xC) = 1;
        M2C_FIELD(temp_r0_5, s16 *, 0xE) = 0;
        M2C_FIELD(temp_r0_5, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r0_5, u16 *, 2) = (u16) M2C_FIELD(temp_r0_5, u16 *, 4);
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x44) = temp_r0_5;
    temp_r0_6 = MemAlloc(4);
    if (temp_r0_6 != NULL) {
        *temp_r0_6 = NULL;
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x48) = temp_r0_6;
    temp_r0_7 = MemAlloc(0x2C);
    if (temp_r0_7 != NULL) {
        M2C_FIELD(temp_r0_7, M2C_UNK **, 0) = &gHeapObjectVTable;
        M2C_FIELD(temp_r0_7, s8 *, 4) = 0;
        M2C_FIELD(temp_r0_7, s16 *, 0x12) = 0;
        M2C_FIELD(temp_r0_7, s8 *, 0x14) = 8;
        M2C_FIELD(temp_r0_7, s8 *, 0x15) = 8;
        M2C_FIELD(temp_r0_7, s8 *, 0x16) = 1;
        M2C_FIELD(temp_r0_7, s8 *, 0x17) = 8;
        M2C_FIELD(temp_r0_7, s8 *, 0x18) = 8;
        M2C_FIELD(temp_r0_7, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_7, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
        M2C_FIELD(temp_r0_7, s8 *, 0x21) = 0;
        M2C_FIELD(temp_r0_7, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r0_7, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_7, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(temp_r0_7, s8 *, 0x29) = 0;
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x4C) = temp_r0_7;
    M2C_FIELD(temp_r0_7, s8 *, 0x16) = 2;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x4C), s8 *, 0x14) = 8;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x4C), s8 *, 0x17) = 8;
    SetTextSpriteValue(M2C_FIELD(temp_r0, M2C_UNK ***, 0x4C), 0);
    temp_r2 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x4C);
    M2C_FIELD(temp_r2, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r2, u8 *, 0x20) & ~0xE0) | 0x40);
    temp_r2_2 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x4C);
    M2C_FIELD(temp_r2_2, u8 *, 0x28) = (u8) ((M2C_FIELD(temp_r2_2, u8 *, 0x28) & ~0xE0) | 0x20);
    temp_r0_8 = MemAlloc(0x2C);
    if (temp_r0_8 != NULL) {
        M2C_FIELD(temp_r0_8, M2C_UNK **, 0) = &gHeapObjectVTable;
        M2C_FIELD(temp_r0_8, s8 *, 4) = 0;
        M2C_FIELD(temp_r0_8, s16 *, 0x12) = 0;
        M2C_FIELD(temp_r0_8, s8 *, 0x14) = 8;
        M2C_FIELD(temp_r0_8, s8 *, 0x15) = 8;
        M2C_FIELD(temp_r0_8, s8 *, 0x16) = 1;
        M2C_FIELD(temp_r0_8, s8 *, 0x17) = 8;
        M2C_FIELD(temp_r0_8, s8 *, 0x18) = 8;
        M2C_FIELD(temp_r0_8, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_8, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
        M2C_FIELD(temp_r0_8, s8 *, 0x21) = 0;
        M2C_FIELD(temp_r0_8, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r0_8, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_8, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(temp_r0_8, s8 *, 0x29) = 0;
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x50) = temp_r0_8;
    M2C_FIELD(temp_r0_8, s8 *, 0x16) = 2;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x50), s8 *, 0x14) = 8;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x50), s8 *, 0x17) = 8;
    SetTextSpriteValue(M2C_FIELD(temp_r0, M2C_UNK ***, 0x50), 0);
    temp_ip = M2C_FIELD(temp_r0, M2C_UNK ***, 0x50);
    M2C_FIELD(temp_ip, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_ip, u8 *, 0x20) & ~0xE0) | 0x40);
    temp_ip_2 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x50);
    M2C_FIELD(temp_ip_2, u8 *, 0x28) = (u8) (M2C_FIELD(temp_ip_2, u8 *, 0x28) & ~0xE0);
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x50), s16 *, 0x12) = 0x270;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x50), s8 *, 0x21) = 9;
    temp_r0_9 = MemAlloc(0x2C);
    if (temp_r0_9 != NULL) {
        M2C_FIELD(temp_r0_9, M2C_UNK **, 0) = &gHeapObjectVTable;
        M2C_FIELD(temp_r0_9, s8 *, 4) = 0;
        M2C_FIELD(temp_r0_9, s16 *, 0x12) = 0;
        M2C_FIELD(temp_r0_9, s8 *, 0x14) = 8;
        M2C_FIELD(temp_r0_9, s8 *, 0x15) = 8;
        M2C_FIELD(temp_r0_9, s8 *, 0x16) = 1;
        M2C_FIELD(temp_r0_9, s8 *, 0x17) = 8;
        M2C_FIELD(temp_r0_9, s8 *, 0x18) = 8;
        M2C_FIELD(temp_r0_9, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_9, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
        M2C_FIELD(temp_r0_9, s8 *, 0x21) = 0;
        M2C_FIELD(temp_r0_9, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r0_9, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_9, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(temp_r0_9, s8 *, 0x29) = 0;
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x58) = temp_r0_9;
    M2C_FIELD(temp_r0_9, s16 *, 0x12) = 0x1E8;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x58), s8 *, 0x16) = 0x10;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x58), s8 *, 0x14) = 0x1A;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x58), s8 *, 0x15) = 0x20;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x58), s8 *, 0x17) = 0x22;
    temp_r2_3 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x58);
    M2C_FIELD(temp_r2_3, u8 *, 0x20) = (u8) (M2C_FIELD(temp_r2_3, u8 *, 0x20) & ~0xE0);
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x58), s8 *, 0x21) = 7;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x58), s8 *, 0x29) = 2;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x58), s16 *, 8) = 0x80;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x58), M2C_UNK **, 0x24) = &data_ov003_0220f700;
    temp_r0_10 = MemAlloc(0x2C);
    if (temp_r0_10 != NULL) {
        M2C_FIELD(temp_r0_10, M2C_UNK **, 0) = &gHeapObjectVTable;
        M2C_FIELD(temp_r0_10, s8 *, 4) = 0;
        M2C_FIELD(temp_r0_10, s16 *, 0x12) = 0;
        M2C_FIELD(temp_r0_10, s8 *, 0x14) = 8;
        M2C_FIELD(temp_r0_10, s8 *, 0x15) = 8;
        M2C_FIELD(temp_r0_10, s8 *, 0x16) = 1;
        M2C_FIELD(temp_r0_10, s8 *, 0x17) = 8;
        M2C_FIELD(temp_r0_10, s8 *, 0x18) = 8;
        M2C_FIELD(temp_r0_10, u8 *, 0x20) = (u8) (((u8) ((u8) (M2C_FIELD(temp_r0_10, u8 *, 0x20) & ~1) & ~0x1E) & ~0xE0) | 0x40);
        M2C_FIELD(temp_r0_10, s8 *, 0x21) = 0;
        M2C_FIELD(temp_r0_10, s32 *, 0x24) = 0;
        M2C_FIELD(temp_r0_10, u8 *, 0x28) = (u8) (M2C_FIELD(temp_r0_10, u8 *, 0x28) & ~0xE0);
        M2C_FIELD(temp_r0_10, s8 *, 0x29) = 0;
    }
    M2C_FIELD(temp_r0, M2C_UNK ***, 0x54) = temp_r0_10;
    M2C_FIELD(temp_r0_10, s16 *, 0x12) = 0x1B4;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x54), s8 *, 0x16) = 4;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x54), s8 *, 0x14) = 0x10;
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x54), s8 *, 0x17) = 0xB;
    temp_r2_4 = M2C_FIELD(temp_r0, M2C_UNK ***, 0x54);
    M2C_FIELD(temp_r2_4, u8 *, 0x20) = (u8) ((M2C_FIELD(temp_r2_4, u8 *, 0x20) & ~0xE0) | 0x40);
    M2C_FIELD(M2C_FIELD(temp_r0, M2C_UNK ***, 0x54), M2C_UNK **, 0x24) = &data_ov003_0220f6f8;
}

/* The ov003 scene's destructor slot: install the destruction vtables, release the
 * scene's heap reference, destroy each attached sub-object through the vtable
 * pointer at its start, free the owned buffers and sprites, and leave the scene
 * in state 4 without freeing the object itself. */
void *Ov003Scene_Destructor(void *scene) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK func_020c127c();
    M2C_UNK func_020c8e40();
    M2C_UNK func_020e4ca0();
    extern M2C_UNK gOv003SceneVTable;
    extern M2C_UNK gOv003SceneIfaceVTable;
    M2C_UNK SetOv003SceneState(s32);
    M2C_UNK MemFree();
    s32 *spriteHolder;
    void **child68;
    void **child4C;
    void **child50;
    void **child58;
    void **child54;

    M2C_FIELD(scene, M2C_UNK **, 0) = &gOv003SceneVTable;
    M2C_FIELD(scene, M2C_UNK **, 0x34) = &gOv003SceneIfaceVTable;
    func_020e4ca0();
    child68 = M2C_FIELD(scene, void ***, 0x68);
    if (child68 != NULL) {
        M2C_FIELD(*child68, void (**)(void *), 4)(child68);
    }
    if (M2C_FIELD(scene, s32 *, 0x3C) != 0) {
        MemFree();
    }
    if (M2C_FIELD(scene, s32 *, 0x40) != 0) {
        MemFree();
    }
    if (M2C_FIELD(scene, s32 *, 0x44) != 0) {
        MemFree();
    }
    spriteHolder = M2C_FIELD(scene, s32 **, 0x48);
    if (spriteHolder != NULL) {
        if (*spriteHolder != 0) {
            DeleteSpriteObject();
        }
        MemFree(spriteHolder);
    }
    child4C = M2C_FIELD(scene, void ***, 0x4C);
    if (child4C != NULL) {
        M2C_FIELD(*child4C, void (**)(void *), 4)(child4C);
    }
    child50 = M2C_FIELD(scene, void ***, 0x50);
    if (child50 != NULL) {
        M2C_FIELD(*child50, void (**)(void *), 4)(child50);
    }
    child58 = M2C_FIELD(scene, void ***, 0x58);
    if (child58 != NULL) {
        M2C_FIELD(*child58, void (**)(void *), 4)(child58);
    }
    child54 = M2C_FIELD(scene, void ***, 0x54);
    if (child54 != NULL) {
        M2C_FIELD(*child54, void (**)(void *), 4)(child54);
    }
    if (M2C_FIELD(scene, s32 *, 0x5C) != 0) {
        DeleteSpriteObject();
    }
    func_020c127c();
    SetOv003SceneState(4);
    func_020c8e40();
    return scene;
}

s32 func_ov003_021e6af0(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov003_021e6b04(s32 arg0) {

}

/* Tear down an ov003 scene object: install the destruction vtables, release the
 * scene's heap reference, destroy each attached sub-object through the vtable
 * pointer at its start, free the owned buffers, set the scene back to state 4
 * and finally free the scene itself. */
void *DestroyOv003Scene(void *scene) {
    M2C_UNK DeleteSpriteObject();
    M2C_UNK func_020c127c();
    M2C_UNK func_020c8e40();
    M2C_UNK func_020e4ca0();
    extern M2C_UNK gOv003SceneVTable;
    extern M2C_UNK gOv003SceneIfaceVTable;
    M2C_UNK SetOv003SceneState(s32);
    M2C_UNK MemFree();
    s32 *spriteHolder;
    void **child68;
    void **child4C;
    void **child50;
    void **child58;
    void **child54;

    M2C_FIELD(scene, M2C_UNK **, 0) = &gOv003SceneVTable;
    M2C_FIELD(scene, M2C_UNK **, 0x34) = &gOv003SceneIfaceVTable;
    func_020e4ca0();
    child68 = M2C_FIELD(scene, void ***, 0x68);
    if (child68 != NULL) {
        M2C_FIELD(*child68, void (**)(void *), 4)(child68);
    }
    if (M2C_FIELD(scene, s32 *, 0x3C) != 0) {
        MemFree();
    }
    if (M2C_FIELD(scene, s32 *, 0x40) != 0) {
        MemFree();
    }
    if (M2C_FIELD(scene, s32 *, 0x44) != 0) {
        MemFree();
    }
    spriteHolder = M2C_FIELD(scene, s32 **, 0x48);
    if (spriteHolder != NULL) {
        if (*spriteHolder != 0) {
            DeleteSpriteObject();
        }
        MemFree(spriteHolder);
    }
    child4C = M2C_FIELD(scene, void ***, 0x4C);
    if (child4C != NULL) {
        M2C_FIELD(*child4C, void (**)(void *), 4)(child4C);
    }
    child50 = M2C_FIELD(scene, void ***, 0x50);
    if (child50 != NULL) {
        M2C_FIELD(*child50, void (**)(void *), 4)(child50);
    }
    child58 = M2C_FIELD(scene, void ***, 0x58);
    if (child58 != NULL) {
        M2C_FIELD(*child58, void (**)(void *), 4)(child58);
    }
    child54 = M2C_FIELD(scene, void ***, 0x54);
    if (child54 != NULL) {
        M2C_FIELD(*child54, void (**)(void *), 4)(child54);
    }
    if (M2C_FIELD(scene, s32 *, 0x5C) != 0) {
        DeleteSpriteObject();
    }
    func_020c127c();
    SetOv003SceneState(4);
    func_020c8e40();
    MemFree(scene);
    return scene;
}

void func_ov003_021e6c28(void) {

}

#pragma opt_strength_reduction off
void *func_ov003_021e6c2c(void *p) {
    void *DestroyOv003Scene(void *);
    return DestroyOv003Scene((char *)p - 0x34);
}
#pragma opt_strength_reduction reset
void func_ov003_021e5c68(void *);
void func_ov003_021e6c3c(void *p) {
    void func_ov003_021e5c68(void *);
    func_ov003_021e5c68((char *)p - 52);
}

#pragma opt_peephole off
void func_ov003_021e6c4c(s32 arg0) {
    ((void(*)(s32))func_ov003_021e6b04)(arg0 - 52);
}
#pragma opt_peephole reset
void func_ov003_021e5c8c(s32);
void func_ov003_021e6c5c(s32 arg0) { func_ov003_021e5c8c((s32)((char *)arg0 - 52)); }

void func_ov003_021e6c6c(void *arg0) {
    void func_ov003_021e6424(void *);
    ((void (*)(void *))func_ov003_021e6424)((char *)arg0 + 0xFFFFFFCC);
}

void func_ov003_021e6c7c(void *arg0) {
    void func_ov003_021e637c(void *);
    ((void (*)(void *))func_ov003_021e637c)((char *)arg0 + 0xFFFFFFCC);
}

s32 func_ov003_021e6c8c(s32 arg0) {
    s32 func_ov003_021e5118(s32);
    return func_ov003_021e5118((s32)((u32)arg0 + 0xFFFFFFCC));
}

void *func_ov003_021e6c9c(void *arg0) {
    void *Ov003Scene_Destructor(void *);
    return Ov003Scene_Destructor((void *)((u32)arg0 + 0xFFFFFFCC));
}

u8 InRange(s32 arg0, s32 arg1, s32 arg2) {
 s32 result;
 if ((arg1 <= arg0) && (arg0 <= arg2)) result = 1;
 else result = 0;
 return result;
}

s32 func_ov003_021e6cc4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((s32) (arg0 + arg2) < 0) || (arg0 > 0x100)) {
        return 0;
    }
    if (((s32) (arg1 + arg3) < 0) || (arg1 > 0xC0)) {
        return 0;
    }
    return 1;
}

u8 func_ov003_021e6cfc(void) {
    s32 IsLinkSessionActive();
    s32 func_0208485c();
    s32 result;
    if (IsLinkSessionActive() && func_0208485c()) result = 1;
    else result = 0;
    return result;
}

u8 func_ov003_021e6d28(void) {
    s32 IsLinkSessionActive();
    s32 func_02084890();
    s32 result;
    if (IsLinkSessionActive() && func_02084890()) result = 1;
    else result = 0;
    return result;
}

void func_ov003_021e6d54(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    func_02084ea0(0x4D4C5342, arg0);
}

u8 *func_ov003_021e6d6c(void *arg0) {
    extern u16 data_ov003_0220f0b8[];
    s32 var_r4 = 0;

    if (InRange(arg0, 0, 3) == 0) {
        if (InRange(arg0, 4, 7) != 0) {
            var_r4 = 1;
        } else if (InRange(arg0, 8, 0x14) != 0) {
            var_r4 = 2;
        } else if (InRange(arg0, 0x15, 0x18) != 0) {
            var_r4 = 3;
        } else if (InRange(arg0, 0x19, 0x19) != 0) {
            var_r4 = 4;
        }
    }
    return (u8 *) &data_ov003_0220f0b8[var_r4];
}

u8 func_ov003_021e6e08(void) {
    u8 *func_ov003_021e6d6c();
    return *func_ov003_021e6d6c();
}

