/* 29 functions from 0x020AA93C to 0x020AB884 (main), found by ds-decomp. */
#include "common.h"
#include "unit_sprite.h"
static inline u32 aaeb0State(void *p) {
    u32 q;
    q = M2C_FIELD(p, u32 *, 0);
    return (q != 0) ? M2C_FIELD((void *) q, u16 *, 8) : 0xFFFFFFFF;
}
static inline void *allocAAB(void) {
void *MemAlloc(s32); s32 HeapAllocBlock(s32); s32 MI_CpuFill8(s32,s32,s32);
    void *temp_r0;
    s32 temp_r0_2;
    temp_r0 = MemAlloc(0x24);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, s16 *, 0x10) = 1;
        M2C_FIELD(temp_r0, s8 *, 0x12) = 0;
        M2C_FIELD(temp_r0, s32 *, 0) = 0;
        M2C_FIELD(temp_r0, s32 *, 4) = 0;
        M2C_FIELD(temp_r0, s8 *, 8) = -1;
        M2C_FIELD(temp_r0, s8 *, 9) = -1;
        M2C_FIELD(temp_r0, s8 *, 0xA) = -1;
        M2C_FIELD(temp_r0, s8 *, 0xB) = -1;
        M2C_FIELD(temp_r0, u8 *, 0xD) = 0xFF;
        M2C_FIELD(temp_r0, s8 *, 0xC) = -1;
        M2C_FIELD(temp_r0, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0, u8 *, 0xF) = 0xFF;
        temp_r0_2 = HeapAllocBlock(0xC);
        M2C_FIELD(temp_r0, s32 *, 0x14) = temp_r0_2;
        MI_CpuFill8(temp_r0_2, 0, 0xC);
    }
    return temp_r0;
}
extern const u8 data_020f49f8[];
extern const u8 data_020f4aa0[];
extern const u8 data_020f4a94[];
extern const u8 data_020f4a04[];
extern const u8 data_020f4a1c[];
extern const u8 data_020f4a28[];
extern const u8 data_020f4a70[];
extern const u8 data_020f4a34[];
extern const u8 data_020f4a40[];
extern const u8 data_020f4a58[];
extern const u8 data_020f4a4c[];
extern const u8 data_020f4a64[];
extern const u8 data_020f4a88[];
extern const u8 data_020f4a7c[];
extern const u8 data_020f4aac[];
extern void *data_027e01d8;
extern void *gCur3DSpriteEngine;
typedef struct { u32 x:9; u32 y:9; u32 rest:14; } UnkAAFields;
typedef struct { u8 kind:7; u8 hidden:1; u8 style:4; u8 a:1; u8 b:1; u8 c:1; u8 d:1; } FlagsAAB;
typedef struct { u8 value:4; } E0194Bits;
typedef struct { u32 low:18; u32 value:8; u32 high:6; } E0B04Bits;

#pragma opt_dead_stores off
/* Return the UnitSpriteDef record for a unit kind.  Kinds that share a sprite
 * size and graphics set share one record; an unknown kind has no record. */
void *GetUnitSpriteDef(u32 unitKind) {
    switch(unitKind) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
        return (void *)data_020f49f8;
    case 53:
    case 54:
    case 55:
    case 56:
    case 58:
    case 59:
    case 60:
    case 61:
        return (void *)data_020f4aa0;
    case 19:
    case 20:
    case 57:
    case 62:
        return (void *)data_020f4a94;
    case 14:
    case 15:
    case 35:
    case 36:
    case 37:
    case 38:
        return (void *)data_020f4a04;
    case 21:
    case 22:
    case 23:
    case 24:
        return (void *)data_020f4a1c;
    case 28:
        return (void *)data_020f4a28;
    case 29:
        return (void *)data_020f4a70;
    case 16:
    case 17:
    case 32:
    case 33:
    case 34:
        return (void *)data_020f4a34;
    case 39:
    case 40:
    case 41:
        return (void *)data_020f4a40;
    case 30:
    case 31:
    case 42:
        return (void *)data_020f4a58;
    case 43:
    case 44:
    case 45:
    case 46:
        return (void *)data_020f4a4c;
    case 18:
    case 26:
    case 27:
    case 70:
        return (void *)data_020f4a64;
    case 12:
    case 13:
        return (void *)data_020f4a88;
    case 8:
    case 9:
    case 10:
    case 11:
        return (void *)data_020f4a7c;
    case 71:
        return (void *)data_020f4aac;
    default:return 0;
    }
}

#pragma opt_common_subs reset
void func_020aab24(void *arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, M2C_UNK);
    void *MemAlloc(M2C_UNK);
    M2C_UNK func_02088e68(void *, M2C_UNK);
    M2C_UNK func_02088e7c(void *, M2C_UNK);
    M2C_UNK func_020a9a30(M2C_UNK, M2C_UNK, u32, s32);
    void func_020aad18(void *);
    s32 func_020aae78(void *);
    s32 HeapAllocBlock(M2C_UNK);
    extern void *gCur3DSpriteEngine;
    void *temp_r0;
    s32 temp_r0_2;

    M2C_FIELD(arg0, s8 *, 0x5A) = 0;
    M2C_FIELD(arg0, u8 *, 0x58) = (u8) ((M2C_FIELD(arg0, u8 *, 0x58) & ~0x7F) | (arg1 & 0x7F));
    M2C_FIELD(arg0, u8 *, 0x59) = (u8) ((M2C_FIELD(arg0, u8 *, 0x59) & ~0xF) | (arg3 & 0xF));
    M2C_FIELD(arg0, u16 *, 0x5C) = arg2;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, u16 *, 0x68) = 0xFF00;
    M2C_FIELD(arg0, u16 *, 0x6A) = 0xFF00;
    M2C_FIELD(arg0, u16 *, 0x6C) = 0xFF00;
    M2C_FIELD(arg0, u16 *, 0x6E) = 0xFF00;
    M2C_FIELD(arg0, FlagsAAB *, 0x58).d = 1;
    M2C_FIELD(arg0, FlagsAAB *, 0x58).c = 0;
    M2C_FIELD(arg0, FlagsAAB *, 0x58).b = 0;
    M2C_FIELD(arg0, FlagsAAB *, 0x58).hidden = 0;
    M2C_FIELD(arg0, FlagsAAB *, 0x58).a = 0;
    { void *engine = *(void *volatile *)&gCur3DSpriteEngine;
      func_020a9a30(0, 0, (u32) (M2C_FIELD(arg0, volatile u8 *, 0x58) << 0x19) >> 0x19,
                    M2C_FIELD(engine, s32 *, 0x1C) + ((u32) M2C_FIELD(arg0, u16 *, 0x5C) << 5)); }
    if (arg4 != 0) {
        u8 style = M2C_FIELD(arg0, volatile FlagsAAB *, 0x58).style;
        void *engine = *(void *volatile *)&gCur3DSpriteEngine;
        u32 kind = M2C_FIELD(arg0, FlagsAAB *, 0x58).kind;
        func_020a9a30(0, 2, kind, M2C_FIELD(engine, s32 *, 0x30) + ((style + 16) << 5));
    }
    M2C_FIELD(arg0, s32 *, 0x44) = func_020aae78(arg0);
    M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (arg2 & ~0xF8000000);
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) (((u32) (M2C_FIELD(arg0, u8 *, 0x59) << 0x1C) >> 0x1C) << 0x18) >> 6));
    M2C_FIELD(arg0, s16 *, 0x3C) = 0;
    func_02088e68(arg0, 0xA);
    func_02088e7c(arg0, 6);
    temp_r0 = MemAlloc(0x24);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, s16 *, 0x10) = 1;
        M2C_FIELD(temp_r0, s8 *, 0x12) = 0;
        M2C_FIELD(temp_r0, s32 *, 0) = 0;
        M2C_FIELD(temp_r0, s32 *, 4) = 0;
        M2C_FIELD(temp_r0, s8 *, 8) = -1;
        M2C_FIELD(temp_r0, s8 *, 9) = -1;
        M2C_FIELD(temp_r0, s8 *, 0xA) = -1;
        M2C_FIELD(temp_r0, s8 *, 0xB) = -1;
        M2C_FIELD(temp_r0, u8 *, 0xD) = 0xFF;
        M2C_FIELD(temp_r0, s8 *, 0xC) = -1;
        M2C_FIELD(temp_r0, s8 *, 0xE) = 0;
        M2C_FIELD(temp_r0, u8 *, 0xF) = 0xFF;
        temp_r0_2 = HeapAllocBlock(0xC);
        M2C_FIELD(temp_r0, s32 *, 0x14) = temp_r0_2;
        MI_CpuFill8(temp_r0_2, 0, 0xC);
    }
    M2C_FIELD(arg0, void **, 0x64) = temp_r0;
    func_020aad18(arg0);
}
void MenuSpriteUpdate(void *arg0) {
    M2C_UNK func_02088044(s32);
    s32 func_02089064();
    void UpdateUnitSpriteFrame(void *);
    if (func_02089064() != 0) {
        func_02088044(M2C_FIELD(arg0, s32 *, 0x64));
    }
    UpdateUnitSpriteFrame(arg0);
}

/* Updates the sprite entry for a unit: updates an existing slot when one is present, otherwise allocates a new one. */
void func_020aad18(void *unit) {
    void AddSpriteCell(void *, s16, s16, u16, u16, s32, u16);
    void func_02087d84(void *, s32, s32, s32, u16, u16);
    u32 func_020aae10(void *);
    u32 func_020aae44(void *);
    s32 func_020aae94(void *);
    u8 entry_count;
    s16 y;
    s16 x;
    u32 width;
    u32 height;
    u32 extra;
    u32 cond;

    entry_count = M2C_FIELD(M2C_FIELD(unit, void **, 0x64), u8 *, 0x12);
    cond = (entry_count != 0) ? 1 : 0;
    if (cond & 0xff) {
        cond = (entry_count != 0) ? 1 : 0;
        if (!(cond & 0xff)) {
            return;
        }
        y = M2C_FIELD(unit, s16 *, 0x52);
        x = M2C_FIELD(unit, s16 *, 0x50);
        width = func_020aae10(unit);
        height = func_020aae44(unit);
        func_02087d84(M2C_FIELD(unit, void **, 0x64), 1, x, y, (u16)width, (u16)height);
        return;
    }
    y = M2C_FIELD(unit, s16 *, 0x52);
    x = M2C_FIELD(unit, s16 *, 0x50);
    width = func_020aae10(unit);
    height = func_020aae44(unit);
    extra = func_020aae94(unit);
    AddSpriteCell(M2C_FIELD(unit, void **, 0x64), x, y, width, height, 1, (u16)extra);
}

u32 func_020aae10(void *arg0) {
    void *GetUnitSpriteDef(u32);
    u32 idx;
    void *ptr;
    u32 value;

    idx = (u32)(M2C_FIELD(arg0, u8 *, 0x58) << 25) >> 25;
    ptr = GetUnitSpriteDef(idx);
    value = M2C_FIELD(ptr, u8 *, 0);
    if (value == 0) {
        return M2C_FIELD(arg0, UnkAAFields *, 0x40).x;
    }
    return value;
}

u32 func_020aae44(void *arg0) {
 void *GetUnitSpriteDef(u32);
 u32 idx; void *ptr; u32 value;
 idx=(u32)(M2C_FIELD(arg0,u8 *,0x58)<<25)>>25;
 ptr=GetUnitSpriteDef(idx);value=M2C_FIELD(ptr,u8 *,1);
 if(value==0){return M2C_FIELD(arg0,UnkAAFields *,0x40).y;} return value;
}

s32 func_020aae78(void *arg0) {
    void *GetUnitSpriteDef(u32);
    return M2C_FIELD(GetUnitSpriteDef((u32)(M2C_FIELD(arg0, u8 *, 0x58) << 0x19) >> 0x19), s32 *, 4);
}

s32 func_020aae94(void *arg0) {
    void *GetUnitSpriteDef(u32);
    return M2C_FIELD(GetUnitSpriteDef((u32)(M2C_FIELD(arg0, u8 *, 0x58) << 0x19) >> 0x19), s32 *, 8);
}

#pragma opt_common_subs off
void UpdateUnitSpriteFrame(void *arg0) {
    u32 nibble;
    s8 v5a;
    s32 test;
    void *p;

    v5a = M2C_FIELD(arg0, s8 *, 0x5A);
    if (v5a < 0) {
        return;
    }
    nibble = M2C_FIELD(arg0, E0194Bits *, 0x59).value;
    if (nibble + 2 != (u16) ((M2C_FIELD(arg0, u32 *, 0x40) << 6) >> 24)) test = 1; else test = 0;
    if (test & 255) {
        p = M2C_FIELD(arg0, void **, 0x64);
        if (M2C_FIELD(p, s8 *, 0xC) == 1 || aaeb0State(p) == 1) {
            M2C_FIELD(arg0, E0B04Bits *, 0x40).value = (u16) (nibble + 1);
        } else if (v5a == 0) {
            M2C_FIELD(arg0, E0B04Bits *, 0x40).value = (u16) nibble;
        }
    }
    v5a = M2C_FIELD(arg0, s8 *, 0x5A);
    if (v5a > 0) {
        M2C_FIELD(arg0, s8 *, 0x5A) = (s8) (v5a - 1);
    }
}
M2C_UNK *func_020aaf74(void) {
    extern M2C_UNK data_02126b0c;
    return &data_02126b0c;
}

/* Per-frame update of the unit sprite on a list task: validates the sprite
 * state, advances the idle frame on its timer and plays the press animation when
 * the sprite's button is held. */
void UpdateUnitSpriteAnimation(void *task) {
    s32 func_01ffa14c(void *);s32 func_020890d4(void *);s32 func_02089080(void *);
    s32 func_020ad3f0(void);u8 func_020ab2a4(void);
    void MenuSpriteUpdate(void *);void UpdateUnitSpriteFrame(void *);
    u16 GetSpriteButtonMask(void *);void func_020819e8(u16);
    void *GetUnitSpriteDef(u32);
    extern volatile u16 *gKeyState;
    void *sprite=M2C_FIELD(task,void **,0x34);
    void *owner;
    u32 cond,frame,bits;
    u16 keys;
    if(func_01ffa14c(M2C_FIELD(sprite,void **,0x18))==0) {
        cond=M2C_FIELD(M2C_FIELD(sprite,void **,0x18),u8 *,0x31)!=0?1:0;
        if(cond&255)goto fail;
    }
    if(func_020890d4(sprite)!=0)goto fail;
    if(func_02089080(sprite)!=0)goto fail;
    if(func_020ad3f0()!=0)goto fail;
    cond=M2C_FIELD(M2C_FIELD(sprite,void **,MENU_SPRITE_OWNER),u8 *,0x12)!=0?1:0;
    if(!(cond&255))goto fail;
    if(func_020ab2a4()!=0)goto fail;
    MenuSpriteUpdate(sprite);
    owner=M2C_FIELD(sprite,void **,MENU_SPRITE_OWNER);
    cond=1;
    if(M2C_FIELD(owner,s8 *,11)!=1 &&
        (!((u32)(M2C_FIELD(sprite,u8 *,MENU_SPRITE_BASE)<<27)>>31) || M2C_FIELD(owner,s8 *,12)!=1))cond=0;
    if(cond&255) {
        if(M2C_FIELD(sprite,s8 *,MENU_SPRITE_TIMER)>=0){
            frame=(u16)(((u32)(M2C_FIELD(sprite,u8 *,MENU_SPRITE_BASE)<<28)>>28)+1);
            bits=M2C_FIELD(sprite,u32 *,MENU_SPRITE_FRAME);
            M2C_FIELD(sprite,u32 *,MENU_SPRITE_FRAME)=(bits&~0x03fc0000)|((frame<<24)>>6);
            M2C_FIELD(sprite,s8 *,MENU_SPRITE_TIMER)=12;
        }
        if(GetSpriteButtonMask(sprite)!=0)func_020819e8(GetSpriteButtonMask(sprite));
        return;
    }
    if(GetSpriteButtonMask(sprite)==0)return;
    keys=gKeyState[0];
    if(M2C_FIELD(GetUnitSpriteDef((u32)(M2C_FIELD(sprite,u8 *,0x58)<<25)>>25),u32 *,8)&16)
        keys=gKeyState[1];
    if(!(keys&GetSpriteButtonMask(sprite)))return;
    if(M2C_FIELD(sprite,s8 *,MENU_SPRITE_TIMER)<0)return;
    frame=(u16)(((u32)(M2C_FIELD(sprite,u8 *,MENU_SPRITE_BASE)<<28)>>28)+1);
    bits=M2C_FIELD(sprite,u32 *,MENU_SPRITE_FRAME);
    M2C_FIELD(sprite,u32 *,MENU_SPRITE_FRAME)=(bits&~0x03fc0000)|((frame<<24)>>6);
    M2C_FIELD(sprite,s8 *,MENU_SPRITE_TIMER)=12;
    return;
fail:
    UpdateUnitSpriteFrame(sprite);
}

void func_020ab150(void *arg0, s16 arg1) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02126b28;
    extern M2C_UNK data_02126bd0;
    void *temp_r0;

    DeleteSpriteObject(M2C_FIELD(arg0, void **, 0x60));
    temp_r0 = func_01ffa3dc(&data_02126b28, 4);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_02126bd0;
    }
    M2C_FIELD(temp_r0, void **, 0x34) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x38) = arg1;
    M2C_FIELD(arg0, void **, 0x60) = temp_r0;
}

u16 GetSpriteButtonMask(void *arg0) {
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0x60);
    if (temp_r0 != NULL) {
        return M2C_FIELD(temp_r0, u16 *, 0x38);
    }
    return 0U;
}

void func_020ab1a8(void *arg0) {
    M2C_UNK DeleteSpriteObject(s32);
    M2C_UNK (*fp)(s32) = (M2C_UNK (*)(s32))DeleteSpriteObject;
    M2C_UNK v = M2C_FIELD(arg0, s32 *, 0x60);
    fp(v);
}

void func_020ab1b8(void) {
    M2C_UNK func_020892f0();
    func_020892f0();
}

void *func_020ab1c4(s32 arg0) {
 extern M2C_UNK data_02126b94, data_02126be4;
 void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
 void func_02089108(void *);
 void *result = func_01ffa3dc(&data_02126b94,arg0);
 if (result != NULL) {
 func_02089108(result);
 M2C_FIELD(result,M2C_UNK **,0)=&data_02126be4;
 M2C_FIELD(result,s32 *,0x64)=0;
 }
 return result;
}

void func_020ab200(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02126b94;
    M2C_UNK (*fp)(M2C_UNK *) = (M2C_UNK (*)(M2C_UNK *))func_01ffa9e4;
    M2C_UNK *p = &data_02126b94;
    fp(p);
}

void func_020ab214(void *arg0) {
 extern u8 data_0215c3a0;
 register unsigned test = M2C_FIELD(M2C_FIELD(arg0,void **,0x64),s8 *,12)==1;
 if ((u8)test) *(&data_0215c3a0+1)=1;
}

u32 func_020ab240(void) {
    extern u8 data_0215c3a0;
    extern M2C_UNK data_02126b94;
    void func_01ffa928(M2C_UNK *, void (*)(void *));
    *(volatile u8 *)(&data_0215c3a0 + 1) = 0;
    func_01ffa928(&data_02126b94, func_020ab214);
    return *(volatile u8 *)(&data_0215c3a0 + 1);
}

void func_020ab274(void) {
    extern u8 data_0215c3a0;
    data_0215c3a0 += 1;
}

void func_020ab28c(void) {
 extern u8 data_0215c3a0;
 data_0215c3a0 -= 1;
}

u8 func_020ab2a4(void) {
    extern u8 data_0215c3a0;
    return data_0215c3a0 != 0;
}

void func_020ab2c4(void *arg0) {
    M2C_UNK UpdateSpriteAnimation(void *);
    s32 GetSpriteAnimValue(void *);
    s16 temp_r4;
    s32 var_r0;

    temp_r4 = M2C_FIELD(arg0, s16 *, 0x2A);
    if (temp_r4 != GetSpriteAnimValue(arg0 + 0x30)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (!(var_r0 & 0xFF)) {
        M2C_FIELD(arg0, s8 *, 0x54) = 4;
    }
    UpdateSpriteAnimation(arg0 + 0x30);
    UpdateSpriteAnimation(arg0 + 0x42);
    UpdateSpriteAnimation(arg0 + 0x54);
}

#pragma opt_propagation off
s16 GetScrollLimit(void *arg0) {
    s16 c = M2C_FIELD(arg0, s16 *, 0xc);
    s16 a = M2C_FIELD(arg0, s16 *, 6);
    s16 b = M2C_FIELD(arg0, s16 *, 8);
    s32 limit = M2C_FIELD(arg0, s32 *, 0x18);
    s16 n = c + (s16)(a * b) - 1;
    if (limit < n) n = limit;
    return n;
}
#pragma opt_propagation reset
void ScrollListTo(void *arg0,s16 arg1,s32 arg2){
 s32 Divide(s16,s16);s32 GetSpriteAnimValue(void *);
 s32 mul;s16 r6,r7,v;
 M2C_FIELD(arg0,s16 *,12)=arg1;
 mul=M2C_FIELD(arg0,u8 *,10)*(s16)Divide(M2C_FIELD(arg0,s16 *,12),M2C_FIELD(arg0,s16 *,8));
 M2C_FIELD(arg0,s16 *,40)=0;M2C_FIELD(arg0,s16 *,42)=-mul;
 r6=M2C_FIELD(arg0,s16 *,42);r7=M2C_FIELD(arg0,s16 *,60);
 M2C_FIELD(arg0,s16 *,62)=GetSpriteAnimValue((u8 *)arg0+48);
 M2C_FIELD(arg0,s16 *,64)=r6;M2C_FIELD(arg0,s16 *,60)=r7;
 M2C_FIELD(arg0,u16 *,50)=M2C_FIELD(arg0,u16 *,52);
 if(arg2==1){v=M2C_FIELD(arg0,s16 *,42);M2C_FIELD(arg0,s16 *,64)=v;M2C_FIELD(arg0,s16 *,62)=v;}
}

#pragma opt_common_subs off
void func_020ab3b0(void *p,s32 value,s32 flag){
s32 Divide(s16,s16);s32 Modulo(s16,s16);void UpdateListScroll(void *);
s32 limit,v,y; s16 a,b;
*(volatile s32 *)((s8 *)p+0x14)=value;
if(*(u8 *)((s8 *)p+0x24)){
limit=*(volatile s32 *)((s8 *)p+0x18); v=*(volatile s32 *)((s8 *)p+0x14);
while(v>limit){v=*(volatile s32 *)((s8 *)p+0x1c); value=*(volatile s32 *)((s8 *)p+0x14); v=value-(limit-v+1); *(volatile s32 *)((s8 *)p+0x14)=v;limit=*(volatile s32 *)((s8 *)p+0x18);}
limit=*(volatile s32 *)((s8 *)p+0x1c);
while(v<limit){v=*(volatile s32 *)((s8 *)p+0x18);value=*(volatile s32 *)((s8 *)p+0x14);v=value+(v-limit+1);*(volatile s32 *)((s8 *)p+0x14)=v;limit=*(volatile s32 *)((s8 *)p+0x1c);}
}else{limit=*(volatile s32 *)((s8 *)p+0x18);v=*(volatile s32 *)((s8 *)p+0x14);if(v<=limit){limit=*(volatile s32 *)((s8 *)p+0x1c);if(v>=limit)limit=v;}*(volatile s32 *)((s8 *)p+0x14)=limit;}
y=*(volatile u8 *)((s8 *)p+0xa)*(s16)Divide((s16)*(volatile s32 *)((s8 *)p+0x14),*(s16 *)((s8 *)p+8));
*(volatile s16 *)((s8 *)p+0x2c)=*(volatile u8 *)((s8 *)p+0xb)*(s16)Modulo((s16)*(volatile s32 *)((s8 *)p+0x14),*(s16 *)((s8 *)p+8));
*(volatile s16 *)((s8 *)p+0x2e)=y;UpdateListScroll(p);if(flag!=1)return;
a=*(s16 *)((s8 *)p+0x2c);*(s16 *)((s8 *)p+0x52)=a;*(s16 *)((s8 *)p+0x50)=a;
b=*(s16 *)((s8 *)p+0x2e);*(s16 *)((s8 *)p+0x64)=b;*(s16 *)((s8 *)p+0x62)=b;}
#pragma opt_common_subs reset
