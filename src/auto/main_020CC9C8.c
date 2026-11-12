/* 31 functions from 0x020CC9C8 to 0x020CD8A8 (main), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"


/* Starts a zoom-in or zoom-out of the map view: picks the new zoom level and
 * the view size it gives, clamps the view scroll so the cursor stays visible,
 * and initialises the transition object (start/end zoom and scroll, 16-frame
 * timer) that Func_020ccbc0 then animates. */
void BeginMapZoom(void *transition) {
 extern s32 *gCurrentMap;s32 GetViewZoom(s32);s32 GetViewHeightForZoom(s32);s32 GetViewWidthForZoom(s32);void PlaySoundEffect(s32);
 s32 oldHeight,oldWidth,newHeight,newWidth,x,y,width,height,map,dx,dy;
 if(GetViewZoom(*gCurrentMap+MAP_VIEW_ZOOM)==0) {M2C_FIELD(transition,s32 *,0x5c)=0;M2C_FIELD(transition,s32 *,0x60)=128;PlaySoundEffect(0x1001e);}
 else {M2C_FIELD(transition,s32 *,0x5c)=128;M2C_FIELD(transition,s32 *,0x60)=0;PlaySoundEffect(0x1001f);}
 oldHeight=GetViewHeightForZoom(M2C_FIELD(transition,s32 *,0x5c));oldWidth=GetViewWidthForZoom(M2C_FIELD(transition,s32 *,0x5c));
 newHeight=GetViewHeightForZoom(M2C_FIELD(transition,s32 *,0x60));newWidth=GetViewWidthForZoom(M2C_FIELD(transition,s32 *,0x60));
 map=*gCurrentMap;x=M2C_FIELD(map,s16 *,MAP_VIEW_X);y=M2C_FIELD(map,s16 *,MAP_VIEW_Y);
 dx=M2C_FIELD(map,s16 *,MAP_CURSOR_TARGET_X)-(x>>4);dy=M2C_FIELD(map,s16 *,MAP_CURSOR_TARGET_Y)-(y>>4);
 M2C_FIELD(transition,s16 *,0x6c)=M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_X);
 M2C_FIELD(transition,s16 *,0x6e)=M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_X);
 M2C_FIELD(transition,s16 *,0x70)=M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_Y);
 M2C_FIELD(transition,s16 *,0x72)=M2C_FIELD(*gCurrentMap,s16 *,MAP_VIEW_Y);
 if(dx>=newWidth-2) {
 map=*gCurrentMap;width=M2C_FIELD(map,u16 *,MAP_WIDTH);
 x=M2C_FIELD(map,s16 *,MAP_CURSOR_TARGET_X);if(x<width-3)width=x+3;
 M2C_FIELD(transition,s16 *,0x6e)=(width-newWidth)<<4;
 }
 if(dy>=newHeight-2) {
 map=*gCurrentMap;height=M2C_FIELD(map,u16 *,MAP_HEIGHT);
 y=M2C_FIELD(map,s16 *,MAP_CURSOR_TARGET_Y);if(y<height-3)height=y+3;
 M2C_FIELD(transition,s16 *,0x72)=(height-newHeight)<<4;
 }
 if(oldWidth<newWidth) {
 width=M2C_FIELD(*gCurrentMap,u16 *,MAP_WIDTH);
 if(width<newWidth+(M2C_FIELD(transition,s16 *,0x6e)>>4))M2C_FIELD(transition,s16 *,0x6e)=(width-newWidth)<<4;
 }
 if(oldHeight<newHeight) {
 height=M2C_FIELD(*gCurrentMap,u16 *,MAP_HEIGHT);
 if(height<newHeight+(M2C_FIELD(transition,s16 *,0x72)>>4))M2C_FIELD(transition,s16 *,0x72)=(height-newHeight)<<4;
 }
 M2C_FIELD(transition,s32 *,0x64)=0;M2C_FIELD(transition,s32 *,0x68)=15;
}

void func_020ccbc0(void *arg0) {
extern s32 *gCurrentMap;
s32 EaseInterpolate(s32,s32,s32,s32,s32);
void SetViewZoom(s32,s32);
void func_01ffa6fc(void *);
s32 base;
M2C_FIELD(arg0,s32 *,0x64)++;
SetViewZoom(*gCurrentMap+0x6ef8,EaseInterpolate(4,M2C_FIELD(arg0,s32 *,0x5c),M2C_FIELD(arg0,s32 *,0x60),M2C_FIELD(arg0,s32 *,0x64),M2C_FIELD(arg0,s32 *,0x68)));
base=*gCurrentMap+0x5120;
M2C_FIELD(base,s16 *,0x28)=EaseInterpolate(4,M2C_FIELD(arg0,s16 *,0x6c),M2C_FIELD(arg0,s16 *,0x6e),M2C_FIELD(arg0,s32 *,0x64),M2C_FIELD(arg0,s32 *,0x68));
base=*gCurrentMap+0x5120;
M2C_FIELD(base,s16 *,0x2a)=EaseInterpolate(4,M2C_FIELD(arg0,s16 *,0x70),M2C_FIELD(arg0,s16 *,0x72),M2C_FIELD(arg0,s32 *,0x64),M2C_FIELD(arg0,s32 *,0x68));
if(M2C_FIELD(arg0,s32 *,0x64)==M2C_FIELD(arg0,s32 *,0x68))func_01ffa6fc(arg0);
}

void func_020ccc94(void) {
    M2C_UNK func_020d8804();
    func_020d8804();
}

void func_020ccca0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b424;
    func_01ffa3dc(&data_0212b424, 7);
}

u8 func_020cccb8(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_0212b424;
    u8 var_r0;

    if (FindObjectByClass(&data_0212b424) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

#pragma opt_strength_reduction off
s32 func_020cccdc(void) {
extern s32 *gCurrentMap;
s32 func_020c1a80(s32);
s32 n=0,x,y,base=*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
if(func_020c1a80(M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,0x3758)+(base+x),u8 *,0x1420)&31) || M2C_FIELD(M2C_FIELD(*gCurrentMap+(y<<1),u16 *,0x3758)+(*gCurrentMap+x),u8 *,0x539c))n++;
base=*gCurrentMap;
}
}
if(n>=99)return 0;return 1;
}
#pragma opt_strength_reduction reset
void func_020ccdc0(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    func_02084ea0(0x474D4544, arg0);
}

void func_020ccdd8(s32 arg0) {
    void CreateSpriteObject(void *, s32);
    extern u8 gBattleEndState;
    extern M2C_UNK data_0212b7ec;
    if (gBattleEndState == 0) return;
    CreateSpriteObject(&data_0212b7ec, arg0);
}

void func_020cce04(s32 arg0) {
    void func_020a196c(void);
    void func_0209c8d4(void);
    void SetSpriteAnimation(s32, s32);
    u8 func_020cd6d4(void);
    u8 DidPlayerLose(void);
    func_020a196c();
    func_0209c8d4();
    if (func_020cd6d4() && DidPlayerLose()) {
        SetSpriteAnimation(arg0, 1);
    } else {
        SetSpriteAnimation(arg0, 0);
    }
}

void func_020cce4c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b894;
    func_01ffa3dc(&data_0212b894, 7);
}

/* Returns a player's battle outcome (BATTLE_RESULT_*): handles the link-battle
 * end conditions from the battle-end state first, otherwise counts the players
 * still active and compares armies to decide win/lose/draw. */
s32 GetPlayerResult(s32 player) {
extern s32 *gCurrentMap; extern u8 gBattleEndState;
s32 IsPlayerPresent(s32);s32 IsPlayerHuman(s32);s32 IsPlayerActive(s32);s32 GetLinkMode(void);s32 IsOverlayEventSet(s32);
s32 totalCount=0, activeCount=0,inactiveCount=0;u8 army=M2C_FIELD((u8*)*gCurrentMap+player*MAP_PLAYER_STRIDE,u8*,PLAYER_ARMY_OFF);s32 active,i,off;
if(!IsPlayerPresent(player))return BATTLE_RESULT_NONE;
if((&gBattleEndState)[BATTLE_END_ENDED]){
active=1;for(i=1;i<5;i++)if(IsPlayerHuman(i))active=i;
if(GetLinkMode()==1){if((&gBattleEndState)[BATTLE_END_FLAG1])return BATTLE_RESULT_DRAW;if((&gBattleEndState)[BATTLE_END_FLAG2])return BATTLE_RESULT_DRAW;}
if(GetLinkMode()==2){
if(active==player){
if((&gBattleEndState)[BATTLE_END_FLAG1])return BATTLE_RESULT_LOSE;
if((&gBattleEndState)[BATTLE_END_FLAG2]){
if(!(&gBattleEndState)[BATTLE_END_FLAG3])return BATTLE_RESULT_LOSE;
{s32 other,otherStep;for(other=1,otherStep=MAP_PLAYER_STRIDE;other<5;other++,otherStep+=MAP_PLAYER_STRIDE)if(IsPlayerPresent(other)&&IsOverlayEventSet(other-1)){if(army==M2C_FIELD((u8*)*gCurrentMap+otherStep,u8*,PLAYER_ARMY_OFF))return BATTLE_RESULT_LOSE;}
}return BATTLE_RESULT_WIN;
}
}else{
if((&gBattleEndState)[BATTLE_END_FLAG1]){if(army!=M2C_FIELD((u8*)*gCurrentMap+active*MAP_PLAYER_STRIDE,u8*,PLAYER_ARMY_OFF))return BATTLE_RESULT_WIN;return BATTLE_RESULT_LOSE;}
if((&gBattleEndState)[BATTLE_END_FLAG2]){
if(!(&gBattleEndState)[BATTLE_END_FLAG3]){if(army!=M2C_FIELD((u8*)*gCurrentMap+active*MAP_PLAYER_STRIDE,u8*,PLAYER_ARMY_OFF))return BATTLE_RESULT_WIN;return BATTLE_RESULT_LOSE;}
if(IsOverlayEventSet(player-1))return BATTLE_RESULT_LOSE;
{s32 other,otherStep;for(other=1,otherStep=MAP_PLAYER_STRIDE;other<5;other++,otherStep+=MAP_PLAYER_STRIDE)if(IsPlayerPresent(other)&&IsOverlayEventSet(other-1)){if(army==M2C_FIELD((u8*)*gCurrentMap+otherStep,u8*,PLAYER_ARMY_OFF))return BATTLE_RESULT_LOSE;}
}return BATTLE_RESULT_WIN;
}
}
}
}
for(i=1;i<5;i++)if(IsPlayerPresent(i)){if(IsPlayerActive(i))activeCount++;else inactiveCount++;totalCount++;}
if(activeCount==totalCount)return BATTLE_RESULT_DRAW;if(inactiveCount==totalCount)return BATTLE_RESULT_DRAW;
{s32 other,otherStep;for(other=1,otherStep=MAP_PLAYER_STRIDE;other<5;other++,otherStep+=MAP_PLAYER_STRIDE)if(IsPlayerPresent(other)&&IsPlayerActive(other)){if(army==M2C_FIELD((u8*)*gCurrentMap+otherStep,u8*,PLAYER_ARMY_OFF))return BATTLE_RESULT_WIN;}
}return BATTLE_RESULT_LOSE;
}

s32 func_020cd164(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 base;
    if (!IsPlayerPresent(arg0)) return 0;
    if (!IsPlayerPresent(arg1)) return 0;
    if (arg0 == arg1) return 0;
    base = *gCurrentMap + 0x67A4;
    if (M2C_FIELD(arg0 * 0x8C + base, u8 *, 0x26) == M2C_FIELD(arg1 * 0x8C + base, u8 *, 0x26)) return 0;
    return GetPlayerResult(arg0);
}

s32 DidPlayerWin(void) {
    s32 IsPlayerHuman(s32);
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;

    var_r4 = 1;
loop_1:
    if ((IsPlayerHuman(var_r4) != 0) && (GetPlayerResult(var_r4) == 1)) {
        return 1;
    }
    var_r4 += 1;
    if (var_r4 >= 5) {
        var_r4_2 = 1;
loop_6:
        if ((IsPlayerHuman(var_r4_2) != 0) && (GetPlayerResult(var_r4_2) == 2)) {
            return 0;
        }
        var_r4_2 += 1;
        if (var_r4_2 >= 5) {
            var_r4_3 = 1;
loop_11:
            if ((IsPlayerPresent(var_r4_3) != 0) && (GetPlayerResult(var_r4_3) == 1)) {
                return 1;
            }
            var_r4_3 += 1;
            if (var_r4_3 >= 5) {
                return 0;
            }
            goto loop_11;
        }
        goto loop_6;
    }
    goto loop_1;
}

u8 DidPlayerLose(void) {
    s32 IsBattleDraw();
    s32 DidPlayerWin();
    u8 var_r0;

    if (IsBattleDraw() != 0) {
        return 0U;
    }
    if (DidPlayerWin() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 IsBattleDraw(void) {
    s32 GetPlayerResult(s32);
    s32 IsPlayerPresent(s32);
    s32 var_r4;

    var_r4 = 1;
loop_1:
    if ((IsPlayerPresent(var_r4) != 0) && (GetPlayerResult(var_r4) == 3)) {
        return 1;
    }
    var_r4 += 1;
    if (var_r4 >= 5) {
        return 0;
    }
    goto loop_1;
}

s32 GetWinningPlayer(void){
extern u8 gBattleEndState;extern s32 *gCurrentMap;s32 i;
if(!gBattleEndState && GetPlayerResult(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))==1)return M2C_FIELD(*gCurrentMap,u16 *,0x52a4);
for(i=1;i<5;i++)if(IsPlayerHuman(i) && GetPlayerResult(i)==1)return i;
for(i=1;i<5;i++)if(IsPlayerPresent(i) && GetPlayerResult(i)==1)return i;
return 0;
}

s32 GetLosingPlayer(void){
extern u8 gBattleEndState;extern s32 *gCurrentMap;s32 i;
if(!gBattleEndState && GetPlayerResult(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))==2)return M2C_FIELD(*gCurrentMap,u16 *,0x52a4);
for(i=1;i<5;i++)if(IsPlayerHuman(i) && GetPlayerResult(i)==2)return i;
for(i=1;i<5;i++)if(IsPlayerPresent(i) && GetPlayerResult(i)==2)return i;
return 0;
}

void func_020cd544(s32);
void func_020cd480(s32 a){
extern u16 gMapConfig;extern s32 *data_027e0058;extern M2C_UNK data_0212b804;extern u32 data_0215d8a0[];u32 v;
func_02088634();if(func_020e4b28(a)){func_020cd544(a);return;}
func_020e49ec();data_0215d8a0[0]=(data_0215d8a0[0]&~15)|(a&15);
v=data_0215d8a0[0]&~240;*(volatile u32 *)data_0215d8a0=v;
gMapConfig &= ~7;
v&=~0xff0000;
v&=~0xff00;
data_0215d8a0[1]=(u16)(data_0215d8a0[1]&0xffff0000);
data_0215d8a0[0]=v&~0xff000000;
M2C_FIELD(*data_027e0058,u16 *,0x5142)=161;func_02086810(161,1);func_01ffa3dc(&data_0212b804,7);
}

void func_020cd544(s32 arg0) {
    extern u16 gMapConfig;
    extern M2C_UNK data_0212b844;
    s32 func_020bf054(s32, s32);
    s32 IsUnitAvailable(s32);
    u8 value;
    func_02088634();
    value = func_020bf054(0, arg0);
    gMapConfig &= ~7;
    func_020e4a18(arg0);
    if (IsUnitAvailable(value)) {
        func_020d4ac8(value);
    } else {
        func_01ffa3dc(&data_0212b844, 7);
    }
}

void func_020cd5ac(void) {
    extern M2C_UNK data_0212b844;
    extern u16 gMapConfig;
    gMapConfig &= ~7;
    func_01ffa3dc(&data_0212b844, 7);
}

s32 func_020cd5d8(void) {
    extern M2C_UNK data_0215d9b8;
    switch ((u32)(M2C_FIELD(&data_0215d9b8, u16 *, 6) << 20) >> 30) {
    case 0: return 1;
    case 1: return 1;
    default: return 0;
    }
}

s32 func_020cd614(void) {
    extern M2C_UNK data_0215d9b8;
    extern s32 *gCurrentMap;
    s32 IsPlayerHuman(s32);
    switch ((u32)(M2C_FIELD(&data_0215d9b8, u16 *, 6) << 18) >> 30) {
    case 0: return 1;
    case 1:
        if (IsPlayerHuman(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4))) return 1;
    }
    return 0;
}

s32 IsFastAnimation(void) {
    extern M2C_UNK data_0215d9b8;
    switch ((u32)(M2C_FIELD(&data_0215d9b8, u16 *, 6) << 20) >> 30) {
    case 2: return 1;
    case 1: return 1;
    }
    return 0;
}

u8 func_020cd6b0(void) {
    extern M2C_UNK data_0215d9b8;
    u8 var_r0;

    if (((u32) (M2C_FIELD(&data_0215d9b8, u16 *, 6) << 0x11) >> 0x1F) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020cd6d4(void) {
    extern M2C_UNK gMapData;
    u8 var_r0;

    if (!(((u32) (M2C_FIELD(&gMapData, u16 *, 0xC) << 0x1D) >> 0x1D) & 0xFF)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020cd6fc(void) {
    extern M2C_UNK gMapData;
    u8 value;
    if ((u8)((u32)(M2C_FIELD(&gMapData, u16 *, 0xC) << 29) >> 29) == 1) value = 1;
    else value = 0;
    return value;
}

u8 func_020cd728(void) {
    extern M2C_UNK gMapData;
    u8 value;
    if ((u8)((u32)(M2C_FIELD(&gMapData, u16 *, 12) << 29) >> 29) == 2) value = 1;
    else value = 0;
    return value;
}

#pragma push
#pragma opt_common_subs off
void func_020cd754(s32 arg0) {
    extern s32 *gCurrentMap;
    void MI_CpuFill8(s32, s32, s32);
    s32 base = *gCurrentMap;
    if (M2C_FIELD(base, u8 *, 0x5156) == 0 && M2C_FIELD(base, u8 *, 0x5158) != 2) {
        MI_CpuFill8(base + 0x5160 + 0xA1 * arg0, 255, 0xA1);
    } else {
        MI_CpuFill8(base + 0x5160 + 0xA1 * arg0, 0, 0xA1);
    }
}
#pragma pop
void func_020cd7bc(s32 arg0, s32 arg1) {
 extern s32 *gCurrentMap;
 void MI_CpuCopy8(s32,s32);
 s32 base=*gCurrentMap+0x160;
 s32 size=0xa1;
 base=base+0x5000;
 MI_CpuCopy8(size*arg0+base,size*arg1+base);
}

s32 GetPlayerRelation(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 temp_r0;

    if (IsPlayerPresent(arg1) == 0) {
        return 0;
    }
    temp_r0 = *gCurrentMap + 0x67A4;
    if (M2C_FIELD(((arg0 * 0x8C) + temp_r0), u8 *, 0x26) != M2C_FIELD(((arg1 * 0x8C) + temp_r0), u8 *, 0x26)) {
        return 1;
    }
    return 2;
}

s32 PlayerHasHumanAlly(s32 arg0) {
 s32 i, v, n;
 n = arg0 + 1;
 i = 1;
 do {
 v = n;
 if (n >= 5) v = n - 4;
 if (GetPlayerRelation(arg0, (u16)v) == 2 && IsPlayerHuman(v) != 0) return 1;
 i++;
 n++;
 } while(i < 4);
 return 0;
}

