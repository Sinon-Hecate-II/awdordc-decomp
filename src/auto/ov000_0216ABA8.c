/* 7 functions from 0x0216ABA8 to 0x0216B898 (ov000), found by ds-decomp. */
#include "common.h"
#pragma optimization_level 0
static inline u16 ScriptTurn16(void) { extern s32 *gCurrentMap; return M2C_FIELD(*gCurrentMap,u16*,0x52a2); }
static inline u16 ScriptPhase16(void) { extern s32 *gCurrentMap; return M2C_FIELD(*gCurrentMap,u16*,0x52a4); }
#pragma optimization_level reset
typedef struct ScriptPlayer16 { u8 pad[0x71]; u8 flag; u8 tail[26]; } ScriptPlayer16;
typedef struct ScriptPlayers16 { u8 pad[0x67a4]; ScriptPlayer16 players[4]; } ScriptPlayers16;
typedef struct ScriptMapNested16 { u8 pad[0x59a4]; struct { u8 entries[256][14]; } units; } ScriptMapNested16;

typedef struct ScriptUnit16 { u8 kind:6; u8 team:2; u8 rest[13]; } ScriptUnit16;
typedef struct ScriptMap16 { u8 pad[0x59a4]; ScriptUnit16 units[256]; } ScriptMap16;
#pragma optimization_level 0
typedef struct ScriptUnitsBlock16 { ScriptUnit16 entries[256]; } ScriptUnitsBlock16;
static inline ScriptUnitsBlock16 *ScriptBlock16(void) { extern s32 *gCurrentMap; return (ScriptUnitsBlock16*)&((ScriptMapNested16*)*gCurrentMap)->units; }
static inline ScriptUnit16 *ScriptUnits16(void) { return ScriptBlock16()->entries; }
static inline ScriptUnit16 *ScriptUnitAt16(s32 n) { return &ScriptBlock16()->entries[n]; }
static inline ScriptPlayer16 *ScriptPlayerAt16(s32 n) { extern s32 *gCurrentMap; return &((ScriptPlayers16*)*gCurrentMap)->players[n]; }
#pragma optimization_level reset

#pragma optimization_level 0
s32 func_ov000_0216aba8(u8 *p, u8 *u, u8 *v, s32 d, u8 e) {
u8 *func_ov000_0216b074(u8*); s32 func_02086b40(); void func_02086ae4(); void func_02094808(); s32 func_020a7cfc(); s32 func_020a32f4();
extern s32 *gCurrentMap;
s32 (*cb)(); s32 result=0; s32 ok;
while(p[0]!=34) {
switch(p[0]) {
case 0:case 1:case 2:
ok=0;
if(*(u16*)(p+2)==65535 || (*(u16*)(p+2)==0 && M2C_FIELD(*gCurrentMap,u16*,0x52a2)==0) || *(u16*)(p+2)==ScriptTurn16()){
if(p[1]==0 || p[1]==ScriptPhase16())ok=1;
}
if(!ok)p=func_ov000_0216b074(p);break;
case 23:case 24:case 25:
if(p[1]!=255 && func_02086b40(p[1])){p=func_ov000_0216b074(p);break;}
if(!e){result=1;break;}
if(*(s32*)(p+4)){func_02094808(*(s32*)(p+4));result=1;}
if(p[1]!=255)func_02086ae4(p[1],1);
break;
case 15:case 16:case 17:cb=*(s32(**)())(p+4);if(cb()!=1)p=func_ov000_0216b074(p);break;
case 18:case 19:case 20:cb=*(s32(**)())(p+4);if(cb()!=0)p=func_ov000_0216b074(p);break;
case 3:case 4:case 5:
if(!u || ((ScriptUnit16*)u)->kind!=p[1])p=func_ov000_0216b074(p);break;
case 26:
if(!u || p[1]!=(((u?((ScriptUnit16*)u-ScriptUnitAt16(0)):0)>>6)+1))p=func_ov000_0216b074(p);break;
case 27:if(!u || ((ScriptUnit16*)u)->kind!=p[1])p=func_ov000_0216b074(p);break;
case 28:if(!u || !func_020a7cfc(u))p=func_ov000_0216b074(p);break;
case 29:
if(!v || p[1]!=(((v?((ScriptUnit16*)v-ScriptUnitAt16(0)):0)>>6)+1))p=func_ov000_0216b074(p);break;
case 30:if(!v || ((ScriptUnit16*)v)->kind!=p[1])p=func_ov000_0216b074(p);break;
case 31:if(!v || !func_020a7cfc(v))p=func_ov000_0216b074(p);break;
case 32:if(!func_020a32f4(p[1]))p=func_ov000_0216b074(p);break;
case 33:if(ScriptPlayerAt16(p[1])->flag)p=func_ov000_0216b074(p);break;
case 12:case 13:case 14:if(p[1]!=d)p=func_ov000_0216b074(p);break;
case 6:case 7:case 8:if(!func_02086b40(p[1]))p=func_ov000_0216b074(p);break;
case 9:case 10:case 11:if(func_02086b40(p[1]))p=func_ov000_0216b074(p);break;
case 22:p=func_ov000_0216b074(p);break;
default:break;
}
p+=8;
}
return result;
}
u8 *func_ov000_0216b074(u8 *arg0) {
    while (*arg0 != 0x17 && *arg0 != 0x18 && *arg0 != 0x19) {
        if (*arg0 == 0x22) {
            return arg0;
        }
        arg0 += 8;
    }
    return arg0;
}
#pragma optimization_level reset
void *func_ov000_0216b0c8(void) {
    void *func_020a8b0c(u16);
    s32 func_020cd6d4();
    extern s32 *gCurrentMap;
    void *result;

    switch (func_020cd6d4()) {
    case 0:
        result = 0;
        break;
    default:
        result = func_020a8b0c(M2C_FIELD((*gCurrentMap + 0x5120), u16 *, 0x22));
        break;
    }
    return result;
}
#pragma optimization_level 0
s32 func_ov000_0216b104(void) {  void *p=func_ov000_0216b0c8(); if(p!=0 && M2C_FIELD(p,s32 *,0x28)!=0) {return func_ov000_0216aba8(M2C_FIELD(p,s32 *,0x28),0,0,0,0);}else return 0;}
#pragma optimization_level reset
s32 func_ov000_0216b154(void) {
    return 0;
}

s32 func_ov000_0216b15c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (((s32) (arg0 + arg2) < 0) || (arg0 > 0x100)) {
        return 0;
    }
    if (((s32) (arg1 + arg3) < 0) || (arg1 > 0xC0)) {
        return 0;
    }
    return 1;
}

void func_ov000_0216b194(void *arg0) {
    M2C_UNK func_01ff9e44(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_020808dc(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02080cfc(M2C_UNK *, s32);
    s32 func_02080e30(M2C_UNK *, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_02091d4c(M2C_UNK);
    M2C_UNK func_0209b59c(s32, M2C_UNK);
    M2C_UNK func_0209b5e4(s32, s32);
    s16 func_0209c268();
    s8 func_020a8ff4(s32);
    M2C_UNK func_020a92bc(void *, s32);
    s32 func_020cfb78();
    s32 func_020e31e0();
    s32 func_020e3218(M2C_UNK *);
    M2C_UNK func_020e35cc(s32);
    extern M2C_UNK data_02168f14;
    extern s32 *gCurrentMap;
    extern void *data_027e00c8;
    extern void *gCur3DSpriteEngine;
    extern M2C_UNK data_ov000_021b83b0;
    extern M2C_UNK data_ov000_021b83c4;
    extern M2C_UNK data_ov000_021b869c;
    extern M2C_UNK data_ov000_021b86a8;
    extern M2C_UNK data_ov000_021b86b0;
    extern M2C_UNK data_ov000_021b86b8;
    extern M2C_UNK data_ov000_021b86c4;
    extern M2C_UNK data_ov000_021b86cc;
    extern M2C_UNK data_ov000_021b86d4;
    extern M2C_UNK data_ov000_021b86e0;
    extern M2C_UNK data_ov000_021b86e8;
    extern M2C_UNK data_ov000_021b86f8;
    extern M2C_UNK data_ov000_021b8708;
    void *saved;
    s8 n0;
    s8 n1;
    s32 var_r0;
    s32 var_r3;
    s32 var_r3_2;
    s32 temp_r0_18;
    s32 temp_r0_23;
    s32 temp_r6_2;
    s32 temp_r6_3;
    s32 temp_r6_4;
    s32 temp_r6_5;
    s16 temp_r0_19;
    s32 var_r1;
    u8 temp_r0_20;
    u8 temp_r0_21;
    u8 temp_r0_22;

    func_0200bc5c(&data_ov000_021b869c);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s8 *, 0x16) = 0x10;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s8 *, 0x14) = 0x1A;
    if (M2C_FIELD(arg0, u8 *, 0x3D) != 0) {
        var_r1 = (M2C_FIELD(&data_02168f14, u8 *, 3) - M2C_FIELD(*gCurrentMap, u16 *, 0x52A2)) + 1;
    } else {
        var_r1 = M2C_FIELD(*gCurrentMap, u16 *, 0x52A2);
    }
    func_020a92bc(M2C_FIELD(arg0, void **, 0x40), var_r1);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), u8 *, 0x20) = (u8) ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), u8 *, 0x20) & ~0xE0) | 0x20);
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c8;
    M2C_FIELD(M2C_FIELD(data_027e00c8, void **, 0), u16 *, 0) |= 0x10;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) |= 0x20;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) &= ~0x40;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) |= 0x80;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0) |= 0x100;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    n0 = func_020a8ff4(*M2C_FIELD(arg0, s32 **, 0x44));
    n1 = func_020a8ff4(*M2C_FIELD(arg0, s32 **, 0x44));
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) = (u16) ((M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) & ~0xC0) | 0x40);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s8 *, 0x51) = n1;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s8 *, 0x52) = (s8) (0x10 - n0);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) &= ~1;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) &= ~2;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) &= ~4;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) |= 8;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) &= ~0x10;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) &= ~0x20;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) |= 0x100;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) |= 0x200;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) &= ~0x400;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) &= ~0x800;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) |= 0x1000;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), u16 *, 0x12) |= 0x2000;
    func_02080cfc(&data_ov000_021b86a8, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x6E80);
    func_02080cfc(&data_ov000_021b86b0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x8280);
    func_020e3218(&data_ov000_021b86b8);
    func_020814e4();
    temp_r6_2 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C);
    func_02081590(func_020e3218(&data_ov000_021b86c4), temp_r6_2 + 0x6B80);
    temp_r6_3 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C);
    func_02081590(func_020e3218(&data_ov000_021b86cc), temp_r6_3 + 0x8640);
    temp_r6_4 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C);
    func_02081590(func_020e3218(&data_ov000_021b86d4), temp_r6_4 + 0x87C0);
    func_02081528();
    temp_r0_18 = func_02080e30(&data_ov000_021b86e0, 1);
    func_01ff9e44(temp_r0_18 + (M2C_FIELD(arg0, u8 *, 0x3C) << 5), 0x360, 0x20);
    func_020e35cc(temp_r0_18);
    func_0209b59c(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + 0x8FC0, 0x60);
    temp_r6_5 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C);
    func_0209b5e4(temp_r6_5 + 0x8FC0, func_020cfb78());
    func_02091d4c(0x12);
    M2C_FIELD(arg0, s16 *, 0x3E) = 0x20;
    func_020cfb78();
    temp_r0_19 = func_0209c268();
    if ((s32) temp_r0_19 > 0x40) {
        M2C_FIELD(arg0, s16 *, 0x3E) = (s16) (M2C_FIELD(arg0, s16 *, 0x3E) - (temp_r0_19 - 0x40));
    }
    if (func_020e31e0() == 2) {
        temp_r0_20 = M2C_FIELD(arg0, u8 *, 0x3B);
        switch (temp_r0_20) {
        default:
            var_r0 = 0;
            break;
        case 1:
            var_r0 = 0;
            break;
        case 2:
            var_r0 = 1;
            break;
        case 3:
            var_r0 = 2;
            break;
        case 4:
            var_r0 = 3;
            break;
        case 5:
            var_r0 = 4;
            break;
        case 0:
            var_r0 = 4;
            break;
        }
        if (var_r0 == 0) {
            func_02080cfc(&data_ov000_021b86e8, M2C_FIELD(data_027e00c8, s32 *, 0x18));
            func_02080cfc(&data_ov000_021b86f8, M2C_FIELD(data_027e00c8, s32 *, 0x2C));
        } else {
            goto block_24;
        }
    } else {
block_24:
        temp_r0_21 = M2C_FIELD(arg0, u8 *, 0x3B);
        switch (temp_r0_21) {
        default:
            var_r3 = 0;
            break;
        case 1:
            var_r3 = 0;
            break;
        case 2:
            var_r3 = 1;
            break;
        case 3:
            var_r3 = 2;
            break;
        case 4:
            var_r3 = 3;
            break;
        case 5:
            var_r3 = 4;
            break;
        case 0:
            var_r3 = 4;
            break;
        }
        func_02080cfc(*(&data_ov000_021b83b0 + (var_r3 * 4)), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x18));
        temp_r0_22 = M2C_FIELD(arg0, u8 *, 0x3B);
        switch (temp_r0_22) {
        default:
            var_r3_2 = 0;
            break;
        case 1:
            var_r3_2 = 0;
            break;
        case 2:
            var_r3_2 = 1;
            break;
        case 3:
            var_r3_2 = 2;
            break;
        case 4:
            var_r3_2 = 3;
            break;
        case 5:
            var_r3_2 = 4;
            break;
        case 0:
            var_r3_2 = 4;
            break;
        }
        func_02080cfc(*(&data_ov000_021b83c4 + (var_r3_2 * 4)), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C));
    }
    func_020808dc(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x2C), 0x20, 0x20, 6);
    temp_r0_23 = func_02080e30(&data_ov000_021b8708, 1);
    func_01ff9e44(temp_r0_23 + (M2C_FIELD(arg0, u8 *, 0x3C) << 5), 0xC0, 0x20);
    func_020e35cc(temp_r0_23);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 8);
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x3E) = 0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine, void **, 0), s16 *, 0x46) = 0;
    gCur3DSpriteEngine = saved;
    M2C_FIELD(arg0, s8 *, 0x36) = 1;
}

