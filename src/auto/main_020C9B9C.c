/* 17 functions from 0x020C9B9C to 0x020CAB8C (main), found by ds-decomp. */
#include "common.h"

/* A selection menu (sprite object type 7): the highlighted entry and how many
   entries the menu has. */
typedef struct SelectionMenu {
    u8 pad00[0x6C];
    s16 selection;  /* +0x6C: highlighted entry */
    s16 count;      /* +0x6E: number of entries */
    s16 progress;   /* +0x70: animation/step counter */
} SelectionMenu;
static inline s32 RangeLeft(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0)); return M2C_FIELD(p,s16 *,0x52dc)-range;
}
static inline s32 RangeTop(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0)); return M2C_FIELD(p,s16 *,0x52de)-range;
}
static inline s32 RangeRight(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0)); return M2C_FIELD(p,s16 *,0x52dc)+range;
}
static inline s32 RangeRightLimit(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0));
s32 sum=M2C_FIELD(p,s16 *,0x52dc)+range;
s32 limit=M2C_FIELD(p,u16 *,0x5144)-1;
if(sum<limit)return RangeRight();
return limit;
}
static inline s32 RangeBottomLimit(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0));
s32 sum=M2C_FIELD(p,s16 *,0x52de)+range;
s32 limit=M2C_FIELD(p,u16 *,0x5146)-1;
if(sum<limit){
range=func_020a7714(M2C_FIELD(p,void **,0x52d0));
return M2C_FIELD(*gCurrentMap,s16 *,0x52de)+range;
}
return limit;
}
static inline s32 RangeBottom(void) {
extern void **gCurrentMap; s32 func_020a7714(void *);
void *p=*gCurrentMap; s32 range=func_020a7714(M2C_FIELD(p,void **,0x52d0)); return M2C_FIELD(p,s16 *,0x52de)+range;
}

#pragma push
#pragma opt_propagation off
#pragma opt_strength_reduction off
void func_020c9b9c(void *arg0) {
extern void **gCurrentMap;
extern u16 data_ov000_021aeee8[];
extern s8 gTerrainPropertyFlags[];
void func_0207ab84(s32,s32,u8); void func_0207ac54(s32,s32,s32);
void func_020cf2c8(void);void func_020cfd28(void);void func_020d2470(void);
u32 player; u16 i; u8 x,y; s32 kind,unit; u8 *map,*p,*rec,*tile;u32 old; u16 *rows; s32 row;
if(M2C_FIELD(arg0,s16 *,0x6e)!=2) player=0;
else {
map=(u8 *)*gCurrentMap;
p=map+0x67a4+M2C_FIELD(arg0,s16 *,0x6c)*0x8c;
tile=map+0x1420;
rows=(u16 *)(map+0x3758);
row=rows[p[0x2c]&127];
unit=(p[0x2b]&127)+row;
old=tile[unit];tile[unit]=data_ov000_021aeee8[M2C_FIELD(arg0,s16 *,0x6c)]|15;

map=(u8 *)*gCurrentMap;
p=map+0x67a4+M2C_FIELD(arg0,s16 *,0x6c)*0x8c;
player=(u32)((old&0xe0)<<11)>>16;
func_0207ab84(p[0x2b]&127,p[0x2c]&127,(u8)data_ov000_021aeee8[M2C_FIELD(arg0,s16 *,0x6c)]);
func_020cf2c8();
}
for(i=0;i<99;i++){
map=(u8 *)*gCurrentMap;
rec=map+i*6;
kind=M2C_FIELD(rec,u8 *,0x6c60);x=M2C_FIELD(rec,u8 *,0x6c61);y=M2C_FIELD(rec,u8 *,0x6c62);
if(kind==255)break;
kind&=31;
if(gTerrainPropertyFlags[kind]){
p=map+x+M2C_FIELD(map+y*2,u16 *,0x3758);
if(data_ov000_021aeee8[M2C_FIELD(arg0,s16 *,0x6c)]==(M2C_FIELD(p,u8 *,0x1420)&0xe0)){
if(player && (unit=*p)!=0){
if(M2C_FIELD(map+(unit>>6)*0x8c,u8 *,0x6856)==M2C_FIELD(map+player*0x8c,u8 *,0x67ca)){
p=map+0x59a4+unit*14;
M2C_FIELD(p,u16 *,6)&=~0xf800;
}
}
switch(kind){case 15:
map=(u8 *)*gCurrentMap;
M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0x1420)=data_ov000_021aeee8[player]|16;
func_0207ac54(x,y,0);
func_0207ab84(x,y,(u8)data_ov000_021aeee8[player]);
break;
default:
map=(u8 *)*gCurrentMap;
M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0x1420)=kind|data_ov000_021aeee8[player];
func_0207ab84(x,y,(u8)data_ov000_021aeee8[player]);
}
}
}
}
func_020cfd28();func_020cf2c8();func_020d2470();
M2C_FIELD(arg0,s16 *,0x70)=1;
}
#pragma pop
void func_020c9e14(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_020cbc88(void *, void *);
    extern void **gCurrentMap;
    extern u16 gPlayerUnitIdBase[];
    s16 temp_r1;
    if (M2C_FIELD(arg0, s16 *, 0x6E) & 0x11) {
        func_01ffa6fc(arg0);
        return;
    }
    while ((temp_r1 = M2C_FIELD(arg0, s16 *, 0x70)) < 0x33) {
        func_020cbc88((u8 *)*gCurrentMap + 0x59A4 + (temp_r1 + gPlayerUnitIdBase[M2C_FIELD(arg0, s16 *, 0x6C)]) * 0xE, arg0);
        M2C_FIELD(arg0, s16 *, 0x70) += 1;
        return;
    }
    func_01ffa6fc(arg0);
}

void func_020c9e94(u16 arg0, u16 arg1) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b304;
    void *temp_r0;

    temp_r0 = func_01ffa3dc(&data_0212b304, 7);
    M2C_FIELD(temp_r0, s16 *, 0x6C) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x6E) = arg1;
}

void func_020c9ebc(s32 arg0, s32 arg1) {
    M2C_UNK func_02091c20(s32, s32);
    s32 IsPlayerHuman(s32);
    extern void **gCurrentMap;
    void *temp_r2;
    s32 temp_lr;
    s32 current;
    temp_r2 = *gCurrentMap;
    temp_lr = arg0 * 0x8C;
    M2C_FIELD((u8 *)temp_r2 + temp_lr, u16 *, 0x67BE) = M2C_FIELD(temp_r2, u16 *, 0x52A2);
    M2C_FIELD((u8 *)*gCurrentMap + temp_lr, s8 *, 0x67C0) = arg1;
    if (IsPlayerHuman(arg0) != 0) func_02091c20(0x18, 1);
    current = M2C_FIELD(*gCurrentMap, u16 *, 0x52A4);
    if (current == arg0) return;
    if (IsPlayerHuman(current) == 0) return;
    if (arg1 & 0x11) func_02091c20(0x17, 1);
    if (!(arg1 & 2)) return;
    func_02091c20(0x16, 1);
}

void func_020c9f74(s32 arg0) {
    typedef struct { s32 entries[4]; } Table;
    M2C_UNK func_02096b50(s32);
    extern void **gCurrentMap;
    extern Table data_020f4e68;
    Table sp0;
    sp0 = data_020f4e68;
    func_02096b50(sp0.entries[M2C_FIELD((u8 *)*gCurrentMap + arg0 * 0x8C, u8 *, 0x67C1) - 1]);
}

void func_020c9fc8(s32 arg0, s32 arg1) {
    void func_020ca484(void);
    void func_020a3498(void);
    void func_020bbb08(void);
    extern void **gCurrentMap;
    func_020c9f74(arg0);
    func_020c9e94((u16)arg0, (u16)arg1);
    func_020c9ebc(arg0, arg1);
    if (M2C_FIELD(*gCurrentMap, u16 *, 0x52A4) == arg0) {
        func_020a3498();
        func_020bbb08();
    }
    if (arg1 != 2) return;
    func_020ca484();
}

void func_020ca030(void) {
    void func_020c9fc8(s32, s32);
    s32 IsPlayerActive(s16);
    s32 func_020d3248(s16);
    s32 func_020d336c(s16);
    s32 func_020d332c(s16);
    s32 func_020d32d4(s16);
    s16 var_r8;
    var_r8 = 1;
    do {
        if (IsPlayerActive(var_r8) != 0) {
            if (func_020d3248(var_r8) != 0) func_020c9fc8(var_r8, 8);
            else if (func_020d336c(var_r8) == 0) func_020c9fc8(var_r8, 0x10);
            else if (func_020d332c(var_r8) == 0) func_020c9fc8(var_r8, 1);
            else if (func_020d32d4(var_r8) == 0) func_020c9fc8(var_r8, 2);
        }
        var_r8 += 1;
    } while (var_r8 < 5);
}

void func_020ca0e0(void) {
    void func_020c9ebc(s32, s32);
    s32 IsPlayerActive(s16);
    s32 func_020d3248(s16);
    s32 func_020d336c(s16);
    s32 func_020d332c(s16);
    s32 func_020d32d4(s16);
    s16 var_r8;
    var_r8 = 1;
    do {
        if (IsPlayerActive(var_r8) != 0) {
            if (func_020d3248(var_r8) != 0) func_020c9ebc(var_r8, 8);
            else if (func_020d336c(var_r8) == 0) func_020c9ebc(var_r8, 0x10);
            else if (func_020d332c(var_r8) == 0) func_020c9ebc(var_r8, 1);
            else if (func_020d32d4(var_r8) == 0) func_020c9ebc(var_r8, 2);
        }
        var_r8 += 1;
    } while (var_r8 < 5);
}

s32 func_020ca190(void) {
    extern u8 gMapConfig[];
    extern void **gCurrentMap;
    u8 var_r0;
    if (gMapConfig[2] == 0) return 0;
    var_r0 = 1;
    do {
        if ((u32)M2C_FIELD((u8 *)*gCurrentMap + var_r0 * 0x8C, u8 *, 0x67BC) >= (u32)gMapConfig[2]) return var_r0;
        var_r0 += 1;
    } while (var_r0 < 5U);
    return 0;
}

s32 func_020ca1ec(void) {
extern void **gCurrentMap;
s32 i,j,mism; u8 buf[5]; u8 *cur; s32 offset; void **maps; s32 inner;
for(i=1;i<5;i++){buf[i]=0;if(IsPlayerActive(i)&&!func_020d3248(i)&&func_020d336c(i)&&func_020d332c(i)&&func_020d32d4(i))buf[i]=1;}
if(M2C_FIELD(*gCurrentMap,u8 *,0x5155)&4){
 for(i=1;i<5;i++){if(buf[i]){for(j=1;j<5;j++){if(i!=j&&IsPlayerActive(j)&&IsSameTeam(i,j)&&!buf[j]){buf[i]=0;func_020d31f0(i,1);}}}}
}
if(M2C_FIELD(*gCurrentMap,u8 *,0x5155)&16){
 for(i=1;i<5;i++){if(buf[i]){for(j=1;j<5;j++){if(i!=j&&IsPlayerHuman(j)&&IsSameTeam(i,j)&&!buf[j]){buf[i]=0;func_020d31f0(i,1);}}}}
}
maps=gCurrentMap; cur=buf+1; i=1; offset=140; do {if(*cur){mism=0;for(j=1,inner=140;j<5;j++,inner+=140){if(i==j)continue; if(!buf[j])continue; if(M2C_FIELD((u8 *)*maps+offset,u8 *,0x67ca)!=M2C_FIELD((u8 *)*maps+inner,u8 *,0x67ca))mism++;}if(mism==0)return 1;}cur++;offset+=140;}while(++i<5);
return 0;
}

void func_020ca484(void) {
    extern void **gCurrentMap;
    u16 temp_r2;
    void *temp_r0;

    temp_r0 = *gCurrentMap;
    temp_r2 = M2C_FIELD(temp_r0, u16 *, 0x52B0);
    if (temp_r2 == 0x10) {
        return;
    }
    M2C_FIELD(temp_r0, u16 *, 0x52B2) = temp_r2;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52B0) = 0x10;
}

void func_020ca4c0(void) {
    M2C_UNK func_02096c7c(s32, M2C_UNK);
    M2C_UNK func_020c9b70();
    void func_020ca030();
    void func_020ca0e0();
    s32 func_020ca190();
    s32 func_020ca1ec();
    s32 temp_r0;

    if (func_020ca1ec() != 0) {
        func_020ca0e0();
        func_020c9b70();
        return;
    }
    temp_r0 = func_020ca190();
    if (temp_r0 != 0) {
        func_02096c7c(temp_r0, 0x20);
        return;
    }
    func_020ca030();
}

void func_020ca4fc(void *arg0) {
    void PlaySoundEffect(s32);
    s16 func_0209f8d4(void);
    void *GetTargetPosition(s16);
    void func_020cbdbc(void);
    extern void **gCurrentMap;
    s16 temp_r4;
    s16 temp_r5;
    void *temp_r0;
    void *temp_r1;
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = func_0209f8d4();
    temp_r1 = *gCurrentMap;
    temp_r4 = M2C_FIELD(temp_r1, s16 *, 0x52C2);
    temp_r5 = M2C_FIELD(temp_r1, s16 *, 0x52C4);
    temp_r0 = GetTargetPosition(M2C_FIELD(arg0, s16 *, 0x6C));
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(temp_r0, s16 *, 4);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(temp_r0, s16 *, 6);
    func_020cbdbc();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = temp_r4;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = temp_r5;
    PlaySoundEffect(0x10019);
}

/* Per-frame update of the target-list selection menu: read the confirm, cancel
   and menu keys plus the touch state, then move the map cursor to the selected
   entry or close the menu. */
void UpdateUnitSelectionMenu(void *dialog) {
    M2C_UNK func_020be010(void);
    s32 func_0207b7c4(void);
    s32 func_020cccb8(void);
    s32 GetKeyActionFlags(void);
    s32 GetTouchActionFlags(s16);
    s32 func_020d46cc(void);
    M2C_UNK DeleteSpriteObject(void *);
    M2C_UNK func_0207b764(s16, s16);
    void *GetTargetPosition(s16);
    M2C_UNK func_020cc66c(s16, s16);
    s32 func_020ccca0(void);
    void func_020d8fa0(void);
    void MoveSelectionWithKeys(void *, s16);
    void UpdateSelectionFromTouch(void *, s16);
    void PlaySoundEffect(s32);
    void MoveMapCursorToTarget(s32);
    void DrawUnitInfoPanel(s32);
    M2C_UNK func_020cf828(M2C_UNK);
    M2C_UNK func_0207a7a4(s32, s32);
    M2C_UNK func_020cf69c(s32, s32);
    extern void **gCurrentMap;
    extern s32 data_0215be0c;

    s32 saved = ((SelectionMenu *)dialog)->selection;
    s32 flags = 0;
    s16 count = ((SelectionMenu *)dialog)->count;
    s32 merged;
    s32 oldval;
    void *target;

    if (count > 1) {
        func_020be010();
    }
    if (func_0207b7c4() != 0) return;
    if (func_020cccb8() != 0) return;

    flags |= GetKeyActionFlags();
    merged = flags | GetTouchActionFlags(count);

    if (merged & 0x20) {
        if (!func_020d46cc()) {
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DC);
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DE);
        }
        data_0215be0c = -1;
        DeleteSpriteObject(dialog);
        func_0207b764(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                      M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
        return;
    }
    if (merged & 0x10) {
        void *target;
        data_0215be0c = ((SelectionMenu *)dialog)->selection;
        target = GetTargetPosition(((SelectionMenu *)dialog)->selection);
        func_020cc66c(M2C_FIELD(target, s16 *, 0x4), M2C_FIELD(target, s16 *, 0x6));
        DeleteSpriteObject(dialog);
        return;
    }
    if (merged & 0x100) {
        func_020ccca0();
        return;
    }
    if (merged & 0x40) {
        func_020d8fa0();
    }
    oldval = saved;
    MoveSelectionWithKeys(&saved, count);
    UpdateSelectionFromTouch(&saved, count);
    if (oldval != saved) {
        PlaySoundEffect(0x10019);
    }
    ((SelectionMenu *)dialog)->selection = (s16)saved;
    target = GetTargetPosition(((SelectionMenu *)dialog)->selection);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(target, s16 *, 0x4);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(target, s16 *, 0x6);
    func_0207b764(M2C_FIELD(target, s16 *, 0x4), M2C_FIELD(target, s16 *, 0x6));
    if (func_0207b7c4() != 0) return;
    MoveMapCursorToTarget(2);
    DrawUnitInfoPanel(1);
}

void func_020ca77c(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b1fc;
    CreateSpriteObject(&data_0212b1fc, arg0);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_strength_reduction off
#pragma opt_propagation off
void func_020ca794(void *arg0) {
extern void **gCurrentMap;
void func_0209f8c0(void);void FillMapLayer(s32);s32 func_020a7714(void *);void func_0209f8f8(s32,s32,s32,s32);s16 func_0209f8d4(void);void PlaySoundEffect(s32);
s32 y1,x0,x1,dist,v,x,y; void *p; s32 range; void *centre;
M2C_FIELD(arg0,s16*,0x6c)=0;
func_0209f8c0();FillMapLayer(-1);
p=*gCurrentMap;range=func_020a7714(M2C_FIELD(p,void **,0x52d0));
if(M2C_FIELD(p,s16 *,0x52dc)-range<0)x0=0;
else {p=*gCurrentMap;range=func_020a7714(M2C_FIELD(p,void **,0x52d0));x0=M2C_FIELD(p,s16 *,0x52dc)-range;}
centre=*gCurrentMap;range=func_020a7714(M2C_FIELD(p,void **,0x52d0));
if(M2C_FIELD(centre,s16 *,0x52de)-range<0)y=0;
else {p=*gCurrentMap;range=func_020a7714(M2C_FIELD(p,void **,0x52d0));y=M2C_FIELD(p,s16 *,0x52de)-range;}
x1=RangeRightLimit();
y1=RangeBottomLimit();
for(;y<=y1;y++){for(x=x0;x<=x1;x++){
p=*gCurrentMap;
v=M2C_FIELD(p,s16*,0x52dc)-x;if(v<=0)v=x-M2C_FIELD(p,s16*,0x52dc);dist=0;dist+=v;
v=M2C_FIELD(p,s16*,0x52de)-y;if(v<=0)v=y-M2C_FIELD(p,s16*,0x52de);dist=dist+v;
if(dist<0)continue; if(dist<=func_020a7714(M2C_FIELD(p,void **,0x52d0))){
func_0209f8f8(x,y,0,0);
M2C_FIELD((u8*)*gCurrentMap+y*4,u8 **,0x52e8)[x]=1;
}
}}
M2C_FIELD(arg0,s16*,0x6e)=func_0209f8d4();
PlaySoundEffect(0x10019);
M2C_FIELD(*gCurrentMap,s16*,0x52c2)=M2C_FIELD(*gCurrentMap,s16*,0x52dc);
M2C_FIELD(*gCurrentMap,s16*,0x52c4)=M2C_FIELD(*gCurrentMap,s16*,0x52de);
}
#pragma pop
/* Handles a confirmation-style selection menu: moves the cursor, opens detail view on confirm, or signals cancel. */
void func_020caa34(void *dialog) {
    M2C_UNK func_020bdfdc(void);
    s32 func_020d4dd0(void);
    s32 func_020bcc34(void);
    s32 func_020bddd4(void);
    M2C_UNK func_0207b764(s16, s16);
    M2C_UNK func_01ffa6fc(void *);
    s32 func_0209f944(s16, s16);
    M2C_UNK func_020d468c(void);
    M2C_UNK func_020cc66c(s16, s16);
    M2C_UNK func_ov000_02199f50(s32, u8, u8, u8);
    M2C_UNK DeleteSpriteObject(void *);
    M2C_UNK func_020ccca0(void);
    M2C_UNK func_020cf828(M2C_UNK);
    M2C_UNK func_0207a7a4(s32, s32);
    M2C_UNK func_020cf69c(s32, s32);
    extern void **gCurrentMap;
    extern s32 data_0215be0c;

    s32 flags = 0;

    func_020bdfdc();
    if (func_020d4dd0() != 0) {
        flags |= func_020bcc34();
        flags |= func_020bddd4();
        if (flags & 0x20) {
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DC);
            M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DE);
            data_0215be0c = -1;
            func_0207b764(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                          M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
            func_01ffa6fc(dialog);
            return;
        }
        if (flags & 0x10) {
            if (func_0209f944(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                               M2C_FIELD(*gCurrentMap, s16 *, 0x52C4)) != 0) {
                func_020d468c();
                func_020cc66c(M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                              M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
                func_ov000_02199f50(0x15,
                    M2C_FIELD(*gCurrentMap, u8 *, 0x52D4),
                    (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52C2),
                    (u8)M2C_FIELD(*gCurrentMap, s16 *, 0x52C4));
                DeleteSpriteObject(dialog);
                return;
            }
        }
        if (flags & 0x100) {
            func_020ccca0();
            return;
        }
    }
    func_020cf828(0x1001a);
    func_0207a7a4(1, 4);
    func_020cf69c(2, 10);
}

