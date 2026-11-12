/* 19 functions from 0x020BBBBC to 0x020BCB94 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"
static inline s16 BC454Direction(s16 *p,s32 dir) { return p[dir*2]; }

void func_020bbbbc(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK func_02091c20(M2C_UNK, M2C_UNK);
    void *func_01ffa444(M2C_UNK *, M2C_UNK);
    s32 IsPlayerHuman(u16);
    extern s32 *gCurrentMap;
    extern M2C_UNK data_0212b00c;
    void *temp_r0;

    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) != 0) {
        func_02091c20(0xD, 1);
    }
    temp_r0 = func_01ffa444(&data_0212b00c, arg4);
    M2C_FIELD(temp_r0, s16 *, 0x6C) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x6E) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg2;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg3;
    M2C_FIELD(temp_r0, s16 *, 0x52) = 0x1E;
}

void func_020bbc2c(M2C_UNK arg0) {
    M2C_UNK func_02091c20(M2C_UNK, M2C_UNK);
    M2C_UNK func_020a348c(M2C_UNK);
    M2C_UNK RefreshMapView();
    s32 IsPlayerHuman(u16);
    extern s32 *gCurrentMap;

    if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) != 0) {
        func_02091c20(6, 1);
    }
    func_020a348c(arg0);
    RefreshMapView();
}

void func_020bbc74(void *arg0) {
    M2C_UNK BuildMovePath(M2C_UNK *, s32, s32, M2C_UNK *);
    M2C_UNK func_020a8050(M2C_UNK *, s16 *, s16 *, M2C_UNK *);
    M2C_UNK func_020a83e4(M2C_UNK *, M2C_UNK *);
    M2C_UNK func_ov000_0216939c(M2C_UNK *);
    M2C_UNK func_ov000_02169518(M2C_UNK *);
    s16 arr1[2];
    s16 arr0[2];
    M2C_UNK buf[5];
    M2C_UNK *temp_r4;

    temp_r4 = M2C_FIELD(arg0, M2C_UNK **, 0x54);
    BuildMovePath(temp_r4, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), buf);
    func_ov000_0216939c(temp_r4);
    func_ov000_02169518(buf);
    arr1[0] = M2C_FIELD(temp_r4, u8 *, 1);
    arr1[1] = M2C_FIELD(temp_r4, u8 *, 2);
    func_020a83e4(temp_r4, buf);
    arr0[0] = M2C_FIELD(temp_r4, u8 *, 1);
    arr0[1] = M2C_FIELD(temp_r4, u8 *, 2);
    func_020a8050(temp_r4, arr1, arr0, buf);
}

void func_020bbcec(s32 a) {
 void *func_01ffa3dc(M2C_UNK *,s32);
 extern s32 *gCurrentMap;
 extern s16 data_0212924c[];
 extern M2C_UNK data_0212929c;
 s32 base=*gCurrentMap;
 s32 x=data_0212924c[a*2];
 s32 y=data_0212924c[a*2+1];
 s32 xx=M2C_FIELD(base,s16 *,0x52dc)+x;
 s32 yy=M2C_FIELD(base,s16 *,0x52de)+y;
 s32 row=M2C_FIELD(base+yy*2,u16 *,0x3758);
 u8 id=M2C_FIELD(base+(xx+row),u8 *,0x508);
 void *p=(void *)(base+0x59a4+(s16)id*(s16)14);
 void *q;
 if(!p)return;
 q=func_01ffa3dc(&data_0212929c,7);
 M2C_FIELD(q,s32 *,0x34)=x*2;
 M2C_FIELD(q,s32 *,0x38)=y*2;
 M2C_FIELD(q,void **,0x54)=p;
}

void func_020bbd8c(void) {
    M2C_UNK func_020cab8c();
    func_020cab8c();
}

void func_020bbd98(void) {
 extern s32 *gCurrentMap;
 void *p;u16 v,n;
 func_020c79c4();
 p=M2C_FIELD(*gCurrentMap,void **,0x52d0);
 v=M2C_FIELD(p,u16 *,6);
 n=(u16)(((u32)(v<<21)>>28)+65535);
 M2C_FIELD(p,u16 *,6)=(v&~0x780)|((n&15)<<7);
 if(IsPlayerHuman(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)))func_02091c20(36,1);
}

void func_020bbe10(void){
void func_020c98d8(u8,u8,s32); void SetPlayerSelectedUnit(u16,void *); s32 func_020d2d50(u16,u32); void func_020d2b10(u16,s32); M2C_UNK func_02091c20(M2C_UNK,M2C_UNK);
extern s32 *gCurrentMap;
void *p;
p=M2C_FIELD(*gCurrentMap,void **,0x52d0);
func_020c98d8(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),3);
SetPlayerSelectedUnit(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),M2C_FIELD(*gCurrentMap,void **,0x52d0));
func_020d2b10(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),func_020d2d50(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),(u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,0)<<26)>>26));
if(IsPlayerHuman(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)))func_02091c20(27,1);
}

/* AI command 22: produce a kind-17 unit on the cursor unit's tile, chain it as
   that unit's cargo, spend one ammo and update the cursor style for the army of
   the unit's owner. */
void AiProduceCargoUnit(void) {
    void *ProduceUnit(u8,u8,s32);
    void func_020c98d8(u8,u8,s32);
    extern s32 *gCurrentMap;
    BattleMapUnit *produced;
    BattleMapUnit *cursor;
    s32 cargoIndex;
    u16 hpWord;
    u32 ammo;

    cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    produced = (BattleMapUnit *)ProduceUnit(cursor->x, cursor->y, 17);
    produced->flags |= 10;
    cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    if (cursor->firstCarried == 0) {
        cargoIndex = produced ? ((s32)produced - (*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE : 0;
        cursor->firstCarried = cargoIndex;
    } else {
        cargoIndex = produced ? ((s32)produced - (*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE : 0;
        cursor->nextCarried = cargoIndex;
    }
    cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    cursor->flags |= 16;
    cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
    hpWord = M2C_FIELD(cursor, u16 *, MAP_UNIT_HEALTH);
    ammo = (u32)(hpWord << 21) >> 28;
    if (ammo) {
        ammo = (u16)(ammo + 65535);
        M2C_FIELD(cursor, u16 *, MAP_UNIT_HEALTH) = (hpWord & ~0x780) | ((ammo & 15) << 7);
    }
    cargoIndex = produced ? ((s32)produced - (*gCurrentMap + MAP_UNIT_RECORDS)) / MAP_UNIT_STRIDE : 0;
    switch (M2C_FIELD(*gCurrentMap + ((cargoIndex >> 6) + 1) * MAP_PLAYER_STRIDE, u8 *, MAP_PLAYER_STATES + PLAYER_REC_ARMY_INDEX)) {
    case 1:
        cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
        func_020c98d8(cursor->x, cursor->y, 4);
        break;
    case 2:
        cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
        func_020c98d8(cursor->x, cursor->y, 5);
        break;
    case 3:
        cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
        func_020c98d8(cursor->x, cursor->y, 6);
        break;
    case 4:
        cursor = (BattleMapUnit *)M2C_FIELD(*gCurrentMap, void **, MAP_CURSOR_UNIT);
        func_020c98d8(cursor->x, cursor->y, 7);
        break;
    }
}

void func_020bc0e0(void) {
}

#pragma push
#pragma opt_strength_reduction off
/* Auto-repeat handler for the map cursor: takes the held D-pad direction, pins
 * the cursor target cell to the matching edge of the visible window, clamps it
 * to the map and then steps it one cell along the direction. */
void MoveMapCursorWithKeys(void) {
s32 func_0207d0b8(void); s32 func_0207d0d4(void); void ClampCursorToMap(void);
extern s32 *gCurrentMap; extern void *gKeyState; extern s16 gDirectionStepX; extern s16 gDirectionStepY;
s32 dir=(M2C_FIELD(gKeyState,u16 *,6)>>4)&15;
s32 viewW=func_0207d0b8(), viewH=func_0207d0d4(), n;
if(M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH)<viewW)viewW=M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);
if(M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT)<viewH)viewH=M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);
if(((s16 (*)[2])&gDirectionStepX)[dir][0]<0)M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)=(M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_X)>>4)+1;
if(((s16 (*)[2])&gDirectionStepX)[dir][0]>0)M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)=(viewW-2)+(M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_X)>>4);
if(((s16 (*)[2])&gDirectionStepY)[dir][0]<0)M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)=(M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_Y)>>4)+1;
if(((s16 (*)[2])&gDirectionStepY)[dir][0]>0)M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)=(viewH-2)+(M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_Y)>>4);
ClampCursorToMap();
n=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)+((s16 (*)[2])&gDirectionStepX)[dir][0];
if(n>=0 && n<M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH))M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_X)=n;
n=M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)+((s16 (*)[2])&gDirectionStepY)[dir][0];
if(n>=0 && n<M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT))M2C_FIELD(*gCurrentMap,s16 *,MAP_CURSOR_TARGET_Y)=n;
}
#pragma pop
void func_020bc610(void *arg0) {
    void PlaySoundEffect(void *);
    extern void *gKeyState;
    extern s32 *data_027e0058;
    extern s16 gDirectionStepX;
    extern s16 gDirectionStepY;
    s32 raw;
    s32 dir;
    void *p;
    s32 n;
    raw = (s32)M2C_FIELD(gKeyState, u16 *, 4);
    dir = (raw >> 4) & 15;
    p = (void *)*data_027e0058;
    n = M2C_FIELD(p, s16 *, 0x52c2) + ((volatile s16 (*)[2])&gDirectionStepX)[dir][0];
    if (n >= 0 && n < M2C_FIELD(p, u16 *, 0x5144)) {
        M2C_FIELD(p, s16 *, 0x52c2) = n;
        if (((volatile s16 (*)[2])&gDirectionStepX)[dir][0] != 0) PlaySoundEffect(arg0);
    }
    p = (void *)*data_027e0058;
    n = M2C_FIELD(p, s16 *, 0x52c4) + ((volatile s16 (*)[2])&gDirectionStepY)[dir][0];
    if (n >= 0 && n < M2C_FIELD(p, u16 *, 0x5146)) {
        M2C_FIELD(p, s16 *, 0x52c4) = n;
        if (((volatile s16 (*)[2])&gDirectionStepY)[dir][0] != 0) PlaySoundEffect(arg0);
    }
}

s32 IsCellEnterable(s32 a,s32 b) {
 extern s32 *gCurrentMap;
 s32 p=*gCurrentMap;
 s32 v=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),s8 *,0x1e30);
 if(v>=0 && v<=110)return 1;
 return 0;
}

u8 IsCellOccupied(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 temp_r2;
    u8 var_r0;

    temp_r2 = *gCurrentMap;
    if ((s32) M2C_FIELD((temp_r2 + (arg0 + M2C_FIELD((temp_r2 + (arg1 * 2)), u16 *, 0x3758))), s8 *, 0x1E30) > 0x6E) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

#pragma opt_strength_reduction off
/* Auto-repeat cursor move: step the aimed tile one cell along the held D-pad
 * direction and play the move sound. On a frame without a fresh key press the
 * step is refused when it would leave enterable terrain for blocked terrain, or
 * leave a unit for a cell that holds none. */
void MoveMapCursorByDirection(void *arg0) {
    void PlaySoundEffect(void *);
    extern void *gKeyState;
    extern s32 *gCurrentMap;
    extern s16 gDirectionStepX, gDirectionStepY;
    s32 dir;
    u16 keys;
    s16 x, y;
    void *p;
    s32 n;

    dir = (M2C_FIELD(gKeyState, volatile u16 *, 4) >> 4) & 15;
    keys = M2C_FIELD(gKeyState, u16 *, 0);
    p = (void *)*gCurrentMap;
    x = M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_X) + ((s16 (*)[2])&gDirectionStepX)[dir][0];
    y = M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_Y) + ((s16 (*)[2])&gDirectionStepY)[dir][0];
    if (!keys) {
        if (IsCellEnterable(M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_X), M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_Y)) && !IsCellEnterable(x, y)) {
            if (!IsCellOccupied(x, y)) return;
        }
        p = (void *)*gCurrentMap;
        if (IsCellOccupied(M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_X), M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_Y))) {
            if (!IsCellOccupied(x, y)) return;
        }
    }
    p = (void *)*gCurrentMap;
    n = M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_X) + ((s16 (*)[2])&gDirectionStepX)[dir][0];
    if (n >= 0 && n < M2C_FIELD(p, u16 *, MAP_WIDTH)) {
        M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_X) = n;
        if (((s16 (*)[2])&gDirectionStepX)[dir][0]) PlaySoundEffect(arg0);
    }
    p = (void *)*gCurrentMap;
    n = M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_Y) + ((s16 (*)[2])&gDirectionStepY)[dir][0];
    if (n >= 0 && n < M2C_FIELD(p, u16 *, MAP_HEIGHT)) {
        M2C_FIELD(p, s16 *, MAP_CURSOR_TARGET_Y) = n;
        if (((s16 (*)[2])&gDirectionStepY)[dir][0]) PlaySoundEffect(arg0);
    }
}
#pragma opt_strength_reduction reset
s32 func_020bc910(void) {
    void func_020d549c(void *);
    void func_020c752c(void);
    void func_020ccca0(void);
    void func_020d8fa0(void);
    void *func_020d2e3c(u16);
    void PlaySoundEffect(void *);
    s32 func_0207b764(u8, u8);
    s32 ConfirmCursorTile(s16, s16, s32, s32, u8);
    void SelectCursorTarget(s32, s32);

    extern s32 *gCurrentMap;
    extern void *gKeyState;

    s32 *map = *gCurrentMap;
    s16 x = M2C_FIELD(map, s16 *, 0x52C2);
    s16 y = M2C_FIELD(map, s16 *, 0x52C4);
    u16 flags = M2C_FIELD(gKeyState, u16 *, 0);

    if (flags & 0x8) {
        func_020d549c((char *)map + 0x5200);
        return 1;
    }
    if (flags & 0x4) {
        func_020c752c();
        return 1;
    }
    if (flags & 0x100) {
        func_020ccca0();
        return 1;
    }
    if (flags & 0x400) {
        func_020d8fa0();
        return 0;
    }
    if (flags & 0x200) {
        u16 w = M2C_FIELD(map, u16 *, 0x52A4);
        void *r6 = func_020d2e3c(w);
        if (r6 != 0) {
            PlaySoundEffect((void *)0x1001A);
            return func_0207b764(*(u8 *)((char *)r6 + 1), *(u8 *)((char *)r6 + 2));
        }
    }

    {
        u16 infoFlags = M2C_FIELD(gKeyState, u16 *, 0);
        if (infoFlags & 0x1) {
            s32 res = ConfirmCursorTile(x, y, 1, 1, 0);
            if (res != 0) {
                return 1;
            }
        }
        if (!(infoFlags & 0x2)) {
            return 0;
        }
    }
    {
        s32 *map2 = *gCurrentMap;
        s16 xx = M2C_FIELD(map2, s16 *, 0x52C2);
        s16 yy = M2C_FIELD(map2, s16 *, 0x52C4);
        SelectCursorTarget(xx, yy);
    }
    return 1;
}

s32 func_020bca68(void) {
 extern void *gKeyState;
 extern u8 data_02164d5d;
 u16 v=M2C_FIELD(gKeyState,u16 *,0);
 if(v&1){data_02164d5d=0;return 16;}
 if(v&2)return 32;
 if(v&256)return 256;
 if(v&1024)return 64;
 return 0;
}

s32 func_020bcac0(void) {
    extern void *gKeyState;
    if (M2C_FIELD(gKeyState, u16 *, 0) & 2) {
        return 0x20;
    }
    if (M2C_FIELD(gKeyState, u16 *, 6) & 2) {
        return 0;
    }
    return 0x20;
}

s32 func_020bcaf0(void) {
    extern void *gKeyState;
    u16 temp_r0;

    temp_r0 = M2C_FIELD(gKeyState, u16 *, 0);
    if (temp_r0 & 1) {
        return 0x10;
    }
    if (temp_r0 & 2) {
        return 0x20;
    }
    if (temp_r0 & 0x100) {
        return 0x100;
    }
    if (temp_r0 & 0x400) {
        return 0x40;
    }
    return 0;
}

void MoveSelectionWithKeys(s32 *arg0,s32 arg1) {
extern void *gKeyState;
if(M2C_FIELD(gKeyState,u16 *,2)&0x90) {
(*arg0)++;
if(*arg0==arg1) *arg0=0;
}
if(M2C_FIELD(gKeyState,u16 *,2)&0x60) {
if(*arg0<=0) *arg0=arg1;
(*arg0)--;
}
}

