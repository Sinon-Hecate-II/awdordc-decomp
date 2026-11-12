/* 19 functions from 0x02211200 to 0x022121F8 (ov005), found by ds-decomp. */
#include "common.h"
typedef struct { u32 x:9; u32 y:9; u32 layer:8; u32 rest:6; } Menu005Flags;

#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
M2C_UNK func_ov005_02211200(M2C_UNK arg0) {
    M2C_UNK savedEngine;
    u32 tile;
    s32 i;
    s16 pos;
    extern s32 gCur3DSpriteEngine, data_027e00c4, data_027e00c8;
    extern void **gCurrentMap;
    extern u8 data_ov005_02220198[];
    extern u8 data_ov005_022201a0[];
    extern u8 data_ov005_022201b0[];
    extern u8 data_ov005_022201c0[];
    extern u8 data_ov005_022201d0[];
    void func_020885fc(void);
    void func_02082cb4(void);
    void func_0208232c(void);
    void Reset3DSpriteBankState(void);
    void *func_020896f0(void *);
    void func_02089424(void);
    void *func_020ab1c4(void *);
    void func_020aab24(void *, s32, s32, s32, s32);
    void func_02088e84(void *, s16, s16, s16, s32);
    s32 func_020aae10(void *);
    s32 func_020aae44(void *);
    void func_020ab150(void *, s32);
    void func_02088f1c(void *);
    void func_020aad18(void *);
    void func_02087d84(void *, s32, s32, s32, s32, s32);
    void func_020af04c(s32, s32, s32, s32);
    void SetFileDirectory(void *);
    s32 GetLocalizedFileName(void *);
    void OpenNarcArchive(void);
    void LoadNarcFileDecompressed(s32,s32);
    void LoadNarcFileToSpriteBuffer(s32,s32,s32);
    void CloseNarcArchive(void);
    void LoadBattleMap(u16);
    void func_ov003_021ff3d4(void *);
    void func_02089438(void *);
    void func_02086608(s32);

    func_020885fc();
    func_02082cb4();
    savedEngine = gCur3DSpriteEngine;
    i=0;do {
        gCur3DSpriteEngine = (i == 0) ? data_027e00c8 : data_027e00c4;
        func_0208232c();
        { u16 *volatile reg=*(u16 **)(void *)gCur3DSpriteEngine; *reg = *reg | 16; }
{ u16 *volatile reg=*(u16 **)(void *)gCur3DSpriteEngine; *reg = *reg | 32; }
{ u16 *volatile reg=*(u16 **)(void *)gCur3DSpriteEngine; *reg = *reg | 64; }
{ u16 *volatile reg=*(u16 **)(void *)gCur3DSpriteEngine; *reg = *reg | 128; }
{ u16 *volatile reg=*(u16 **)(void *)gCur3DSpriteEngine; *reg = *reg | 256; }
        Reset3DSpriteBankState(); i++;
    }while(i<2);
    gCur3DSpriteEngine = data_027e00c8;
    M2C_FIELD((void *)arg0, void **, 0x4C) = func_020896f0((void *)arg0);
    func_02089424();
    {
        void *p = M2C_FIELD((void *)arg0, void **, 0x4C);
        M2C_FIELD(p,Menu005Flags*,0x40).x=32;
        M2C_FIELD(p,Menu005Flags*,0x40).y=32;
    }
    tile=0x140;
    { void *sprite; sprite = func_020ab1c4((void *)arg0);
    func_020aab24(sprite, 0, tile, 3, 1);
    func_02088e84(sprite, 0xC0, 0xA0, 0xE0, 0xC0);
    if ((u8)(M2C_FIELD(M2C_FIELD(sprite, void **, 0x64), u8 *, 0x12)!=0)) {
        s16 a = M2C_FIELD(sprite, s16 *, 0x52);
        s16 b = M2C_FIELD(sprite, s16 *, 0x50);
        s32 w=func_020aae10(sprite);
        func_02087d84(M2C_FIELD(sprite, void **, 0x64),1,b,a,(u16)w,(u16)func_020aae44(sprite));
    }
    func_020ab150(sprite, 1);
    func_02088f1c(sprite);
    func_020aad18(sprite);

    }
    { void *sprite2; sprite2 = func_020ab1c4((void *)arg0);
    func_020aab24(sprite2, 3, 0x150, 3, 1);
    func_02088e84(sprite2, 0xE0, 0xA0, 0xC0, 0xC0);
    if ((u8)(M2C_FIELD(M2C_FIELD(sprite2, void **, 0x64), u8 *, 0x12)!=0)) {
        s16 a = M2C_FIELD(sprite2, s16 *, 0x52);
        s16 b = M2C_FIELD(sprite2, s16 *, 0x50);
        s32 w=func_020aae10(sprite2);
        func_02087d84(M2C_FIELD(sprite2, void **, 0x64),1,b,a,(u16)w,(u16)func_020aae44(sprite2));
    }
    func_020ab150(sprite2, 2);
    func_02088f1c(sprite2);
    func_020aad18(sprite2);

    }
    {
        s32 neg = -1;
        
        s32 r9 = 0;
        s32 r8 = 0x20;
        tile+=0x20;
        do {
            void *spSprite;
            M2C_FIELD((u8 *)(void *)arg0 + r9 * 4, void **, 0x38) = func_020ab1c4((void *)arg0);
            func_020aab24(M2C_FIELD((u8 *)(void *)arg0+r9*4,void**,0x38), (r9 + 0x3F) & 0xFF, tile, 3, 0);
            spSprite=M2C_FIELD((u8 *)(void *)arg0+r9*4,void**,0x38);
            pos = (s16)r8;
            func_02088e84(spSprite, pos, 0x58, pos, 0x58);
            if ((u8)(M2C_FIELD(M2C_FIELD(spSprite, void **, 0x64), u8 *, 0x12)!=0)) {
                s16 a = M2C_FIELD(spSprite, s16 *, 0x52);
                s16 b = M2C_FIELD(spSprite, s16 *, 0x50);
                s32 w=func_020aae10(spSprite);
        func_02087d84(M2C_FIELD(spSprite, void **, 0x64),1,b,a,(u16)w,(u16)func_020aae44(spSprite));
                }
            M2C_FIELD(spSprite, s16 *, 0x34) = pos;
            M2C_FIELD(spSprite, s16 *, 0x36) = 0x58;
            if ((u8)(M2C_FIELD(M2C_FIELD(spSprite, void **, 0x64), u8 *, 0x12)!=0)) {
                s16 a = M2C_FIELD(spSprite, s16 *, 0x52);
                s16 b = M2C_FIELD(spSprite, s16 *, 0x50);
                s32 w=func_020aae10(spSprite);
        func_02087d84(M2C_FIELD(spSprite, void **, 0x64),1,b,a,(u16)w,(u16)func_020aae44(spSprite));
            }
            M2C_FIELD(M2C_FIELD((u8 *)(void *)arg0+r9*4,void**,0x38),u8*,0x5a)=neg;
            func_020aad18(M2C_FIELD((u8 *)(void *)arg0+r9*4,void**,0x38));
            tile += 0x10;
            r8 += 0x28; r9++;
        }while(r9<5);
    }

    SetFileDirectory(data_ov005_02220198);
    GetLocalizedFileName(data_ov005_022201a0);
    OpenNarcArchive();
    LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_022201b0),M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x14));
    LoadNarcFileDecompressed(GetLocalizedFileName(data_ov005_022201c0),M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x28));
    LoadNarcFileToSpriteBuffer(GetLocalizedFileName(data_ov005_022201d0),0,0x20);
    CloseNarcArchive();
    {
        void *cur = (void *)gCur3DSpriteEngine;
        u8 val = M2C_FIELD(cur, u8 *, 0x46);
        val |= 0x04;
        M2C_FIELD(cur, u8 *, 0x46) = val;
        func_020af04c(3, 0x0F, 0x06, val);
    }
    gCur3DSpriteEngine = data_027e00c4;
    {
        void *map = *gCurrentMap;
        LoadBattleMap(M2C_FIELD(map, u16 *, 0x5142));
    }
    func_ov003_021ff3d4((void *)arg0);
    gCur3DSpriteEngine = savedEngine;
    M2C_FIELD((void *)arg0, s32 *, 0x34) = 2;
    {
        void *p = M2C_FIELD((void *)arg0, void **, 0x4C);
        M2C_FIELD(p, s16 *, 0x34) = (s16)M2C_FIELD((void*)arg0,s32*,0x34)*(s16)0x28+0x20;
        M2C_FIELD(p, s16 *, 0x36) = 0x58;
    }
    func_02089438(M2C_FIELD((void *)arg0, void **, 0x4C));
    func_02086608(4);
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
s32 func_ov005_0221174c(void) {
s32 func_02086658(s32); s32 func_020af1e4(); s32 func_ov003_021ff7ac(); s32 func_02088624();
func_02086658(4); func_020af1e4(); func_ov003_021ff7ac(); func_02088624();
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Input/update handler of a five-tab menu: move the selection with left/right,
   animate the five tab sprites and highlight the selected one, move the cursor
   sprite, and play the move sound plus the confirm or back animation. */
void UpdateTabMenu(void *menu) {
    void MenuSpriteUpdate(void *);
    void PlaySoundEffect(s32);
    void SetSpriteAnimation(void *, s32);
    extern KeyState *gKeyState;
    s32 confirm;
    s32 cancel;
    s32 previous;
    s32 i;
    s32 j;
    s32 selection;
    void *sprite;
    void *owner;
    u8 enabled;
    u8 isSelected;
    u16 keys;

    previous = M2C_FIELD(menu, s32 *, 0x34);
    confirm = 0;
    cancel = 0;
    if (gKeyState->repeat & KEY_LEFT) {
        if (previous > 0) {
            M2C_FIELD(menu, s32 *, 0x34) = previous - 1;
        } else if (gKeyState->pressed & KEY_LEFT) {
            M2C_FIELD(menu, s32 *, 0x34) = 4;
        }
    }
    if (gKeyState->repeat & KEY_RIGHT) {
        selection = M2C_FIELD(menu, s32 *, 0x34);
        if (selection < 4) {
            M2C_FIELD(menu, s32 *, 0x34) = selection + 1;
        } else if (gKeyState->pressed & KEY_RIGHT) {
            M2C_FIELD(menu, s32 *, 0x34) = 0;
        }
    }
    keys = gKeyState->pressed;
    if (keys & KEY_A) {
        confirm = 1;
    }
    if (keys & KEY_B) {
        cancel = 1;
    }
    for (i = 0; i < 5; i++) {
        MenuSpriteUpdate(M2C_FIELD((u8 *) menu + i * 4, void **, 0x38));
        sprite = M2C_FIELD((u8 *) menu + i * 4, void **, 0x38);
        isSelected = (M2C_FIELD(M2C_FIELD(sprite, void **, MENU_SPRITE_OWNER), s8 *, 0xC) == 1);
        if (isSelected) {
            M2C_FIELD(menu, s32 *, 0x34) = i;
        }
        enabled = 1;
        sprite = M2C_FIELD((u8 *) menu + i * 4, void **, 0x38);
        owner = M2C_FIELD(sprite, void **, MENU_SPRITE_OWNER);
        if (M2C_FIELD(owner, s8 *, 0xB) != 1
            && !((((u32) (M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 0x1B) >> 0x1F) != 0) && M2C_FIELD(owner, s8 *, 0xC) == 1)) {
            enabled = 0;
        }
        if (enabled & 0xFF) {
            confirm = 1;
        }
    }
    for (j = 0; j < 5; j++) {
        if (M2C_FIELD(menu, s32 *, 0x34) == j) {
            sprite = M2C_FIELD((u8 *) menu + j * 4, void **, 0x38);
            M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) = (s32) ((M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) & ~0x03FC0000)
                | ((u32) ((u16) (((u32) (*(volatile u8 *) ((u8 *) sprite + MENU_SPRITE_BASE) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        } else {
            sprite = M2C_FIELD((u8 *) menu + j * 4, void **, 0x38);
            M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) = (s32) ((M2C_FIELD(sprite, s32 *, MENU_SPRITE_FRAME) & ~0x03FC0000)
                | ((u32) ((u16) ((u32) (*(volatile u8 *) ((u8 *) sprite + MENU_SPRITE_BASE) << 0x1C) >> 0x1C) << 0x18) >> 6));
        }
    }
    if (M2C_FIELD(menu, s32 *, 0x34) != previous) {
        PlaySoundEffect(0x10019);
        sprite = M2C_FIELD(menu, void **, 0x4C);
        M2C_FIELD(sprite, u16 *, 0x34) = M2C_FIELD(menu, s32 *, 0x34) * 0x28 + 0x20;
        M2C_FIELD(sprite, u16 *, 0x36) = 0x58;
    }
    if (confirm) {
        PlaySoundEffect(0x1000D);
        SetSpriteAnimation(menu, 1);
    } else if (cancel) {
        PlaySoundEffect(0x1000F);
        SetSpriteAnimation(menu, 2);
    }
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
s32 func_ov005_02211988(void *arg0) {
s32 func_020c818c(s32,s32);
extern void **gCurrentMap;
return func_020c818c(M2C_FIELD(*gCurrentMap,u16 *,0x5142),M2C_FIELD(arg0,s32 *,0x34)+1);
}

void func_ov005_022119b4(void) {
    M2C_UNK func_ov005_02211200();
    func_ov005_02211200();
}

void func_ov005_022119c0(void) {
    M2C_UNK func_ov005_0221174c();
    func_ov005_0221174c();
}

void func_ov005_022119cc(void *arg0) {
    UpdateTabMenu(arg0);
}

void func_ov005_022119d8(void) {
    M2C_UNK func_ov005_02211988();
    func_ov005_02211988();
}

void func_ov005_022119e4(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    s32 func_020c80ec(u16);
    extern u8 gBattleEndState;
    extern void **gCurrentMap;
    extern M2C_UNK data_ov005_022200a0;
    if (gBattleEndState != 0) {
        return;
    }
    if (func_020c80ec(M2C_FIELD(*gCurrentMap, u16 *, 0x5142)) == 0) {
        return;
    }
    CreateSpriteObject(&data_ov005_022200a0, arg0);
}

s32 HistoryTabAt(s32 arg0) {
    extern s32 gHistoryMenu;
    return (0xA * arg0) + (gHistoryMenu + 0x10);
}

u8 func_ov005_02211a54(s32 arg0,s32 arg1) {
s32 GetRecordValue(s32,s32);
extern s32 gHistoryMenu;
u8 result;
if(M2C_FIELD(gHistoryMenu,u8 *,0)!=0)return 0;
if(GetRecordValue(arg0,arg1)==0)result=1;else result=0;
return result;
}

void func_ov005_02211a8c(void) {
extern s32 gHistoryMenu, g3DSpriteEngineSub;
extern s32 gCur3DSpriteEngine;
extern M2C_UNK data_ov005_02220270;
s32 GetRecordDefinition(s32,s32); s32 GetRecordTier(s32,s32);
void func_0208b758(s32,s32); void func_0208b698(s32,void *);
s32 q, index, old;
s32 p=gHistoryMenu;
s32 table = HistoryTabAt(M2C_FIELD(p,s8 *,1));
s32 a = M2C_FIELD(table,s16 *,2);
s8 b = M2C_FIELD(p,s8 *,2);
q = GetRecordDefinition(M2C_FIELD(p,s8 *,1), a+b);
index = GetRecordTier(M2C_FIELD(gHistoryMenu,s8 *,1), a+b);
old = gCur3DSpriteEngine;
gCur3DSpriteEngine = g3DSpriteEngineSub;
if (func_ov005_02211a54(M2C_FIELD(gHistoryMenu,s8 *,1),a+b)==0)
func_0208b758(M2C_FIELD(gHistoryMenu,s32 *,0x48),M2C_FIELD(q+index*4,s32 *,0x1c));
else func_0208b698(M2C_FIELD(gHistoryMenu,s32 *,0x48),&data_ov005_02220270);
gCur3DSpriteEngine = old;
}

void func_ov005_02211b4c(void) {
    s32 Divide(s32, s32);
    extern M2C_UNK data_0215d9b8;
    extern s32 gHistoryMenu;
    s32 timeVal;

    timeVal = M2C_FIELD(&data_0215d9b8, s32 *, 0x74);
    M2C_FIELD(gHistoryMenu, s32 *, 4) = Divide(timeVal, 0x34BC0);
    if (M2C_FIELD(gHistoryMenu, s32 *, 4) > 0x3E7) {
        M2C_FIELD(gHistoryMenu, s32 *, 4) = 0x3E7;
        M2C_FIELD(gHistoryMenu, s32 *, 8) = 0x3B;
        M2C_FIELD(gHistoryMenu, s32 *, 12) = 0x3B;
        return;
    }
    M2C_FIELD(gHistoryMenu, s32 *, 8) = Divide(timeVal, 0xE10) % 60;
    M2C_FIELD(gHistoryMenu, s32 *, 12) = Divide(timeVal, 0x3C) % 60;
}

void func_ov005_02211c24(s32 arg0) {
s32 p=HistoryTabAt(arg0);
s32 q=GetRecordDefinition(arg0,0);
M2C_FIELD(p,s16 *,8)=0; M2C_FIELD(p,s16 *,6)=0;
while(M2C_FIELD(q,s32 *,0)) {
if(!func_ov005_02211a54(arg0,M2C_FIELD(p,s16 *,8))) M2C_FIELD(p,s16 *,6)++;
M2C_FIELD(p,s16 *,8)++;
q+=0x30;
}
}

void func_ov005_02211c94(void) {
extern s32 gHistoryMenu;
M2C_FIELD(gHistoryMenu,s32 *,0x34)=func_ov000_0216a77c(func_ov000_0216a76c());
M2C_FIELD(gHistoryMenu,s32 *,0x38)=func_ov000_0216a7d4(func_ov000_0216a7c4());
M2C_FIELD(gHistoryMenu,u8 *,0x32)=func_ov000_0216a564(func_ov000_0216a470());
M2C_FIELD(gHistoryMenu,s32 *,0x3c)=func_ov000_0216a59c(func_ov000_0216a564(func_ov000_0216a470()));
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Recomputes the eight "medal earned" flags of the records menu from the
 * player's record values: single records reaching their top tier, whole-tab
 * tier sums, and combined tiers of specific unit records. */
void UpdateMedalFlags(void) {
 s32 GetRecordDefinition();
 s32 GetRecordTier();
 s32 HistoryTabAt();
 extern s32 gHistoryMenu;
 s32 total, i, k, j;
for(i=0;M2C_FIELD(GetRecordDefinition(0,i),u16 *,4)!=0;i++);
if(GetRecordTier(0,i)==3) ((HistoryMenu *)gHistoryMenu)->medals[0]=1; else ((HistoryMenu *)gHistoryMenu)->medals[0]=0;
for(i=0;M2C_FIELD(GetRecordDefinition(0,i),u16 *,4)!=2;i++);
if(GetRecordTier(0,i)==3) ((HistoryMenu *)gHistoryMenu)->medals[1]=1; else ((HistoryMenu *)gHistoryMenu)->medals[1]=0;
total=0; for(j=0;j<M2C_FIELD(HistoryTabAt(1),s16 *,8);j++) total+=GetRecordTier(1,j);
if(total>=50) ((HistoryMenu *)gHistoryMenu)->medals[2]=1; else ((HistoryMenu *)gHistoryMenu)->medals[2]=0;
j=0; for(total=0;total<M2C_FIELD(HistoryTabAt(2),s16 *,8);total++) j+=GetRecordTier(2,total);
if(j>=50) ((HistoryMenu *)gHistoryMenu)->medals[3]=1; else ((HistoryMenu *)gHistoryMenu)->medals[3]=0;
for(i=0;M2C_FIELD(GetRecordDefinition(0,i),u16 *,4)!=32;i++);
for(j=0;M2C_FIELD(GetRecordDefinition(0,j),u16 *,4)!=33;j++);
if(GetRecordTier(0,i)+GetRecordTier(0,j)>=4) ((HistoryMenu *)gHistoryMenu)->medals[4]=1; else ((HistoryMenu *)gHistoryMenu)->medals[4]=0;
for(i=0;M2C_FIELD(GetRecordDefinition(0,i),u16 *,4)!=25;i++);
if(GetRecordTier(0,i)==3) ((HistoryMenu *)gHistoryMenu)->medals[5]=1; else ((HistoryMenu *)gHistoryMenu)->medals[5]=0;
for(i=0;M2C_FIELD(GetRecordDefinition(0,i),u16 *,4)!=26;i++);
if(GetRecordTier(0,i)==3) ((HistoryMenu *)gHistoryMenu)->medals[6]=1; else ((HistoryMenu *)gHistoryMenu)->medals[6]=0;
for(i=0;M2C_FIELD(GetRecordDefinition(0,i),u16 *,4)!=29;i++);
for(j=0;M2C_FIELD(GetRecordDefinition(0,j),u16 *,4)!=30;j++);
for(k=0;M2C_FIELD(GetRecordDefinition(0,k),u16 *,4)!=31;k++);
if(GetRecordTier(0,k)+(GetRecordTier(0,i)+GetRecordTier(0,j))>=5) ((HistoryMenu *)gHistoryMenu)->medals[7]=1; else ((HistoryMenu *)gHistoryMenu)->medals[7]=0;
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
s32 HistoryScrollUp(void) {
extern s32 gHistoryMenu;
void PlaySoundEffect(s32);
s32 p=HistoryTabAt(M2C_FIELD(gHistoryMenu,s8 *,1));
s32 n=M2C_FIELD(p,s16 *,2);
if(!n)return 0;
M2C_FIELD(p,s16 *,2)=n-1;
PlaySoundEffect(0x10019);func_ov005_02211a8c();return 1;
}

s16 HistoryPageUp(void) {
extern s32 gHistoryMenu;
s32 p=HistoryTabAt(M2C_FIELD(gHistoryMenu,s8 *,1));
s16 old=M2C_FIELD(p,s16 *,2);
M2C_FIELD(p,s16 *,2)=old-7;
if(M2C_FIELD(p,s16 *,2)<0)M2C_FIELD(p,s16 *,2)=0;
return M2C_FIELD(p,s16 *,2)-old;
}

s32 HistoryScrollDown(void) {
extern s32 gHistoryMenu;
void PlaySoundEffect(s32);
s32 p=HistoryTabAt(M2C_FIELD(gHistoryMenu,s8 *,1));
s16 n=M2C_FIELD(p,s16 *,2);
s32 next=n+7;
if(next>=M2C_FIELD(p,s16 *,8))return 0;
M2C_FIELD(p,s16 *,2)++;
PlaySoundEffect(0x10019);
func_ov005_02211a8c();
return 1;
}

