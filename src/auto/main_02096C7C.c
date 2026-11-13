/* 31 functions from 0x02096C7C to 0x02097C50 (main), found by ds-decomp. */
#include "common.h"
#include "ds3dsprite.h"

void func_02096c7c(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_020c9b70();
    M2C_UNK func_020c9ebc(s32, M2C_UNK);
    s32 IsPlayerActive(s32);
    s32 IsSameTeam(s32, s32);
    extern s32 *gCurrentMap;
    s32 temp_r2;
    s32 var_r5;
    s32 var_r6;
    s32 var_r7;
    void *temp_r3;

    var_r6 = 0x8C;
    var_r5 = 1;
    var_r7 = arg0 * 0x8C;
    do {
        if ((IsPlayerActive(var_r5) != 0) && (IsSameTeam(arg0, var_r5) == 0)) {
            temp_r2 = *gCurrentMap;
            temp_r3 = var_r7 + temp_r2;
            M2C_FIELD(temp_r3, u16 *, 0x67C6) = (u16) (M2C_FIELD(temp_r3, u16 *, 0x67C6) + M2C_FIELD((temp_r2 + var_r6), u8 *, 0x67D5));
            func_020c9ebc(var_r5, arg1);
        }
        var_r5 += 1;
        var_r6 += 0x8C;
    } while (var_r5 < 5);
    func_020c9b70();
}

void func_02096d0c(void) {
    M2C_UNK func_020822b8(u16 *);
    typedef struct { u16 a, b, c, d, e, f; } T;
    extern T data_020f3644;
    T sp0;

    sp0 = data_020f3644;
    func_020822b8((u16 *) &sp0);
}

void func_02096d5c(void) {
    M2C_UNK GX_SetBankForBG(M2C_UNK);
    M2C_UNK GX_SetBankForOBJ(M2C_UNK);
    M2C_UNK func_02002ab8(M2C_UNK);
    M2C_UNK func_02003124(M2C_UNK);
    M2C_UNK func_020031cc(M2C_UNK);
    M2C_UNK func_0200323c(M2C_UNK);
    M2C_UNK func_020032bc(M2C_UNK);
    M2C_UNK func_02082c84();
    func_02082c84();
    GX_SetBankForBG(1);
    GX_SetBankForOBJ(2);
    func_02003124(4);
    func_020031cc(8);
    func_02002ab8(0x10);
    func_02002bb8(0x20);
    func_0200323c(0x80);
    func_020032bc(0x100);
}

void func_02096da8(void) {
    M2C_UNK func_02002bb8(M2C_UNK);
    M2C_UNK func_020b1800();
    func_020b1800();
    func_02002bb8(0x40);
}

void func_02096dbc(void) {
    M2C_UNK func_020b17ec();
    func_020b17ec();
}

/* Enables the five layers of the 3D-sprite engine(s) whose display target matches
   the current selection (main, sub or the saved engine): configures the background
   banks, then ORs the layer-enable bits (0x10..0x100) into each matching engine. */
void EnableSpriteLayers(void) {
    void func_02096d5c(void);
    void func_02096d0c(void);
    M2C_UNK func_020aca8c(M2C_UNK);
    M2C_UNK func_01ff9e00(void);
    s32 func_02091e14(void);
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain;
    u16 *volatile layer0, *volatile layer1, *volatile layer2, *volatile layer3, *volatile layer4;
    void *savedEngine;
    s32 engineIndex;
    func_02096d5c();
    savedEngine = gCur3DSpriteEngine;
    engineIndex = 0;
    do {
        gCur3DSpriteEngine = (engineIndex == 0) ? g3DSpriteEngineMain : g3DSpriteEngineSub;
        if ((func_02091e14() != 0 || gCur3DSpriteEngine == g3DSpriteEngineMain) &&
            (func_02091e14() != 1 || gCur3DSpriteEngine == g3DSpriteEngineSub) &&
            (func_02091e14() != 3 || gCur3DSpriteEngine == savedEngine)) {
            func_02096d0c();
            layer0 = *(u16 **)gCur3DSpriteEngine; *layer0 = *layer0 | 0x10;
            layer1 = *(u16 **)gCur3DSpriteEngine; *layer1 = *layer1 | 0x20;
            layer2 = *(u16 **)gCur3DSpriteEngine; *layer2 = *layer2 | 0x40;
            layer3 = *(u16 **)gCur3DSpriteEngine; *layer3 = *layer3 | 0x80;
            layer4 = *(u16 **)gCur3DSpriteEngine; *layer4 = *layer4 | 0x100;
            func_020aca8c(3);
            func_01ff9e00();
        }
        engineIndex++;
    } while (engineIndex < 2);
    gCur3DSpriteEngine = savedEngine;
}

/* Disables the 3D-sprite layers of the engine(s) matching the active screen
   selection: configures the background banks, then clears the five layer mode
   bits of the main and/or sub engine's sprite bank. */
void DisableSpriteLayers(void) {
M2C_UNK func_02082cb4();
M2C_UNK func_0208232c();
s32 func_02091e14();
M2C_UNK func_020aca8c(M2C_UNK);
extern void *gCur3DSpriteEngine,*g3DSpriteEngineSub,*g3DSpriteEngineMain;
u16 *volatile layer0;u16 *volatile layer1;u16 *volatile layer2;u16 *volatile layer3;u16 *volatile layer4;
void *savedEngine; s32 engineIndex;
func_02082cb4();
savedEngine=gCur3DSpriteEngine;
engineIndex=0;
do {
gCur3DSpriteEngine=engineIndex==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
if((func_02091e14()!=0||gCur3DSpriteEngine==g3DSpriteEngineMain)&&(func_02091e14()!=1||gCur3DSpriteEngine==g3DSpriteEngineSub)&&(func_02091e14()!=3||gCur3DSpriteEngine==savedEngine)){
func_0208232c();
layer0=*(u16 **)gCur3DSpriteEngine;*layer0=*layer0&~DS3D_BANK_MODE0;
layer1=*(u16 **)gCur3DSpriteEngine;*layer1=*layer1&~DS3D_BANK_MODE1;
layer2=*(u16 **)gCur3DSpriteEngine;*layer2=*layer2&~DS3D_BANK_MODE2;
layer3=*(u16 **)gCur3DSpriteEngine;*layer3=*layer3&~DS3D_BANK_MODE3;
layer4=*(u16 **)gCur3DSpriteEngine;*layer4=*layer4&~DS3D_BANK_MODE4;
func_020aca8c(3);
}
++engineIndex;
}while(engineIndex<2);
gCur3DSpriteEngine=savedEngine;
}

void func_0209707c(void) {
    s32 Get3DSpriteTarget();
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    s32 var_r5;
    void *var_r0;

    temp_r4 = gCur3DSpriteEngine;
    var_r5 = 0;
    do {
        if (var_r5 == 0) {
            var_r0 = g3DSpriteEngineMain;
        } else {
            var_r0 = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = var_r0;
        if (((Get3DSpriteTarget() != 0) || (gCur3DSpriteEngine == g3DSpriteEngineMain)) && ((Get3DSpriteTarget() != 1) || (gCur3DSpriteEngine == g3DSpriteEngineSub)) && ((Get3DSpriteTarget() != 3) || (gCur3DSpriteEngine == temp_r4))) {
            M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
        }
        var_r5 += 1;
    } while (var_r5 < 2);
    gCur3DSpriteEngine = temp_r4;
}

void func_02097128(s8 arg0) {
    void *Get3DSpriteManager();
    M2C_FIELD(Get3DSpriteManager(), s8 *, 0x4A) = arg0;
}

void func_0209713c(s8 arg0) {
    M2C_FIELD(Get3DSpriteManager(), s8 *, 0x4C) = arg0;
}

void func_02097150(M2C_UNK arg0, s16 arg1) {
    s32 *func_02091f18();
    M2C_FIELD(func_02091f18(), s16 *, 4) = arg1;
}

void func_02097164(s32 a,s8 b) { s32 *func_02091f18(); M2C_FIELD(func_02091f18(),s8 *,6)=b; }

void func_02097178(s32 a,s32 b) { s32 *func_02091f18(); s32 p; M2C_FIELD(func_02091f18(),u8 *,7)=b; p=func_0209e9dc((u16)a); if(!p)return; if(b==1)func_0209e2b8(p,1);else func_0209e2b8(p,0); }

void func_020971c0(s32 a,s32 b) { s32 p; void *q; s32 r; p=func_0209e9dc((u16)a);if(!p)return;q=Get3DSpriteChild(p,0);r=M2C_FIELD(q,s32 *,0x60);if(b)func_02098e2c(r,0);else func_02098e2c(r,M2C_FIELD(q,u8 *,0x58));func_0209e320(p); }

void func_02097214(s32 a,s32 b,s32 c) { s32 func_02091e04(void); void func_020991fc(void *,u32);void func_020990fc(void *,s32,s32,s32);s32 p,r;void *q;p=func_0209e9dc((u16)a);if(!p)return;q=Get3DSpriteChild(p,0);r=M2C_FIELD(q,s32 *,0x60);func_020991fc(q,(u8)func_02091e04());func_020990fc(q,b,c+5,1);func_02098e2c(r,b);func_0209e320(p); }

void func_02097280(s32 arg0) {
    M2C_UNK func_02088db8(void *, s32);
    M2C_UNK func_02088d94(s32);
    M2C_UNK func_02088ea8(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    s32 func_020abe90(u8);
    void *temp_r0;
    void *temp_r7;
    s32 var_r8;
    s32 temp_r4;

    temp_r0 = func_0209e9dc(2);
    if (temp_r0 == NULL) {
        return;
    }
    temp_r7 = Get3DSpriteChild(temp_r0, arg0);
    var_r8 = 8;
    temp_r4 = M2C_FIELD(temp_r7, s32 *, 0x60);
    if (func_020abe90((u8) ((u32) (M2C_FIELD(temp_r0, u8 *, 0x48) << 0x1C) >> 0x1D)) == 1) {
        var_r8 = 0;
    }
    switch (arg0) {                                 /* irregular */
    case 0:
        func_02088ea8(temp_r7, -0x40, 0, 0, 0, var_r8);
        func_02088db8(temp_r7, var_r8);
        break;
    case 1:
        func_02088ea8(temp_r7, 0xA0, 0, 0x60, 0, var_r8);
        func_02088db8(temp_r7, var_r8);
        break;
    }
    func_02088d94(temp_r4);
    func_0209e320(temp_r0);
}

void func_02097348(s32 arg0) {
    M2C_UNK func_02088f8c(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_02088e0c(void *, s32);
    s32 func_020abe90(u8);
    void *temp_r0;
    register void *temp_r7;
    long var_r8;
    register unsigned temp_r4;

    temp_r0 = func_0209e9dc(2);
    if (temp_r0 == NULL) {
        return;
    }
    temp_r7 = Get3DSpriteChild(temp_r0, arg0);
    var_r8 = 8;
    temp_r4 = M2C_FIELD(temp_r7, s32 *, 0x60);
    if (func_020abe90((u8) ((u32) (M2C_FIELD(temp_r0, u8 *, 0x48) << 0x1C) >> 0x1D)) == 1) {
        var_r8 = 0;
    }
    switch (arg0) {                                 /* irregular */
    case 0:
        func_02088f8c(temp_r7, 0, 0, -0x40, 0, var_r8);
        func_02088e0c(temp_r7, var_r8);
        break;
    case 1:
        func_02088f8c(temp_r7, 0x60, 0, 0xA0, 0, var_r8);
        func_02088e0c(temp_r7, var_r8);
        break;
    }
    func_02088da8(temp_r4);
    func_0209e320(temp_r0);
}

void func_02097410(void) {

}

void func_02097414(s32 a,s32 b,s32 c) { s32 func_02091e04(void); void func_020991fc(void *,u32);void func_020990fc(void *,s32,s32,s32);s32 p,r;void *q;p=func_0209e9dc(2);if(!p)return;q=Get3DSpriteChild(p,a);r=M2C_FIELD(q,s32 *,0x60);func_020991fc(q,(u8)func_02091e04());func_020990fc(q,b,c+8,1);func_02098e2c(r,b); }

void func_0209747c(M2C_UNK arg0, s32 arg1) {
    s32 temp_r0;
    s32 temp_r0_3;
    void *temp_r0_2;

    temp_r0 = func_0209e9dc(2);
    if (temp_r0 == 0) {
        return;
    }
    temp_r0_2 = Get3DSpriteChild(temp_r0, arg0);
    temp_r0_3 = M2C_FIELD(temp_r0_2, s32 *, 0x60);
    if (arg1 != 0) {
        func_02098e2c(temp_r0_3, 0U);
    } else {
        func_02098e2c(temp_r0_3, M2C_FIELD(temp_r0_2, u8 *, 0x58));
    }
    func_0209e320(temp_r0);
}

/* Builds the 3D sprite cells for the current sprite mode on both screens:
   1 sprite, a 3x2 cell grid, or 2 sprites, all sharing the given sprite data. */
void Build3DSpriteScene(s32 spriteData) {
    s32 Get3DSpriteCount();
    s32 Get3DSpriteTarget();
    void func_020943a8(s32);
    M2C_UNK func_02098e04(void *, s32, u16);
    M2C_UNK func_020990d4(void *, s32, u16);
    M2C_UNK func_0209e184(void *, M2C_UNK, M2C_UNK, u16);
    void *Alloc3DSprite(s32);
    extern void *g3DSpriteEngineSub;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    void *savedEngine;
    s32 screen;
    s32 row;
    s32 unused;
    void **enginePtr;
    s32 nextScreen;
    s32 spriteCount;
    s32 nextRow;
    void *part;
    void *part2;
    u16 rowId;
    s32 slot;
    s32 slot2;
    void *child;
    void *child2;
    s32 yOff;
    s32 yOff2;
    s32 tileOff;
    s32 tileOff2;
    void *sprite;
    void *sprite1;
    void *sprite2;

    unused = spriteData;
    savedEngine = (void *)gCur3DSpriteEngine;
    screen = 0;
    do {
        if (screen == 0) {
            enginePtr = &g3DSpriteEngineMain;
        } else {
            enginePtr = &g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = *enginePtr;
        if (((Get3DSpriteTarget() != 0) || (gCur3DSpriteEngine == g3DSpriteEngineMain)) && ((Get3DSpriteTarget() != 1) || (gCur3DSpriteEngine == g3DSpriteEngineSub)) && ((Get3DSpriteTarget() != 3) || (gCur3DSpriteEngine == (void *)savedEngine))) {
            spriteCount = Get3DSpriteCount();
            switch (spriteCount) {                  /* irregular */
            case 0:
                sprite = Alloc3DSprite(unused);
                func_0209e184(sprite, 1, 0, 8U);
                M2C_FIELD(sprite, s16 *, 0x2E) = 2;
                M2C_FIELD(sprite, s16 *, 0x3C) = 0x400;
                break;
            case 1:
                row = 0;
                yOff = 0x9000;
                tileOff = 0x9800;
                do {
                    sprite1 = Alloc3DSprite(unused);
                    func_0209e184(sprite1, 1, 0x8000, (u16) (row + 0xD));
                    slot = 0;
                    rowId = (u16) row;
                    M2C_FIELD(sprite1, u16 *, 0x2E) = rowId;
                    M2C_FIELD(sprite1, s16 *, 0x3C) = 0x400;
loop_17:
                    part = Get3DSpriteChild(sprite1, slot);
                    child = M2C_FIELD(part, void **, 0x60);
                    func_02098e04(child, yOff, (u16) (row + 0xA));
                    func_020990d4(part, tileOff, rowId);
                    M2C_FIELD(child, s16 *, 0x3C) = 0x400;
                    slot += 1;
                    M2C_FIELD(part, s16 *, 0x3C) = 0x400;
                    if ((s32) slot < 2) {
                        goto loop_17;
                    }
                    yOff += 0x200;
                    nextRow = row + 1;
                    row = nextRow;
                    tileOff += 0xA00;
                } while (nextRow < 3);
                break;
            case 2:
                sprite2 = Alloc3DSprite(unused);
                func_0209e184(sprite2, 2, 0, 0xDU);
                M2C_FIELD(sprite2, s16 *, 0x2E) = 2;
                M2C_FIELD(sprite2, s16 *, 0x3C) = 0x400;
                slot2 = 0;
                yOff2 = 0x1800;
                tileOff2 = 0x2000;
                do {
                    part2 = Get3DSpriteChild(sprite2, slot2);
                    child2 = M2C_FIELD(part2, void **, 0x60);
                    func_02098e04(child2, yOff2, (u16) (slot2 + 0xA));
                    func_020990d4(part2, tileOff2, slot2);
                    M2C_FIELD(child2, s16 *, 0x3C) = 0x400;
                    M2C_FIELD(part2, s16 *, 0x3C) = 0x400;
                    yOff2 += 0x200;
                    tileOff2 += 0x8000;
                    slot2 += 1;
                } while ((s32) slot2 < 2);
                break;
            }
        }
        nextScreen = screen + 1;
        screen = nextScreen;
    } while (nextScreen < 2);
    gCur3DSpriteEngine = savedEngine;
    func_020943a8(-1);
}

void func_02097768(void) {

}

s32 func_0209776c(s32 arg0) {
    s32 func_02089064(void);
    s32 func_020abe90(u8);
    M2C_UNK func_02088ea8(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_0209e9dc(M2C_UNK);
    void func_0209e1b0(void *);
    s32 *func_02091f18();
    s32 func_02091f08(void);
    void func_02091d4c(M2C_UNK);
    s32 GetMenuCursor(void);
    void func_020943a8(s32);
    void *temp_r4;
    s32 var_r6;
    s32 *temp_r5;

    temp_r4 = (void *) func_0209e9dc((u16) arg0);
    if (temp_r4 != NULL && func_02089064() == 0) {
        func_0209e1b0(temp_r4);
        var_r6 = 8;
        if (func_020abe90((u8) ((u32) (M2C_FIELD(temp_r4, u8 *, 0x48) << 0x1C) >> 0x1D)) == 1) {
            var_r6 = 0;
        }
        switch (arg0) {
        case 0:
            func_02088ea8(temp_r4, 0, -0x40, 0, 0, var_r6);
            break;
        case 1:
            func_02088ea8(temp_r4, -0x100, 0x40, 0, 0x40, var_r6);
            break;
        case 2:
            func_02088ea8(temp_r4, 0, 0xc0, 0, 0x80, var_r6);
            break;
        }
        temp_r5 = func_02091f18(arg0);
        M2C_FIELD(temp_r5, u16 *, 0x8) = (u16) func_02091f08();
        func_02091d4c(M2C_FIELD(temp_r5, u8 *, 0x6));
        if (GetMenuCursor() < 0) {
            func_020943a8(arg0);
        }
        return 1;
    }
    return 0;
}

s32 func_0209787c(s32 arg0) {
    s32 func_02089064(void);
    s32 func_020abe90(u8);
    M2C_UNK func_02088f8c(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void func_02097bac(s32);
    void *temp_r4;
    s32 var_r5;

    temp_r4 = (void *) func_0209e9dc((u16) arg0);
    if (temp_r4 != NULL && func_02089064() != 0) {
        var_r5 = 8;
        if (func_020abe90((u8) ((u32) (M2C_FIELD(temp_r4, u8 *, 0x48) << 0x1C) >> 0x1D)) == 1) {
            var_r5 = 0;
        }
        switch (arg0) {
        case 0:
            func_02088f8c(temp_r4, 0, 0, 0, -0x40, var_r5);
            break;
        case 1:
            func_02088f8c(temp_r4, 0, 0x40, 0x100, 0x40, var_r5);
            break;
        case 2:
            func_02088f8c(temp_r4, 0, 0x80, 0, 0xc0, var_r5);
            break;
        }
        func_02097bac(arg0);
        return 1;
    }
    return 0;
}

s32 func_02097964(void) {
    s32 func_0209787c(M2C_UNK);
    s32 var_r4;

    var_r4 = 0;
    if (func_0209787c(0) != 0) {
        var_r4 = 1;
    }
    if (func_0209787c(1) != 0) {
        var_r4 = 1;
    }
    if (func_0209787c(2) != 0) {
        var_r4 = 1;
    }
    return var_r4;
}

s32 func_020979a4(s32 a) { s32 *func_02091f18();s32 i,q,p,b;for(i=0;i<3;i++){q=func_02091f18(i);p=func_0209e9dc((u16)i);if(p){b=0;if(i==a)b=1;func_02091d6c(M2C_FIELD(q,u8 *,6),b);func_0209e26c(p,b);func_0209e320(p);}}func_020943a8(a);func_02094ba0(a);func_0209707c();return 1;}

void func_02097a2c(s32 arg0) {
    s32 Get3DSpriteCount();
    M2C_UNK func_020991f4(s32, s32);
    M2C_UNK func_02099204(s32);
    long var_r6;
    s32 temp_r0;
    s32 temp_r0_2;

    if (Get3DSpriteCount() != 2) {
        return;
    }
    temp_r0 = func_0209e9dc(2);
    if (!temp_r0) {
        return;
    }
    var_r6 = 0;
    do {
        temp_r0_2 = Get3DSpriteChild(temp_r0, var_r6);
        if (var_r6 == arg0) {
            func_020991f4(temp_r0_2, 1);
        } else {
            func_020991f4(temp_r0_2, 0);
        }
        func_02099204(temp_r0_2);
        var_r6++;
    } while (2 > var_r6);
    func_0209e320(temp_r0);
}

void func_02097aa8(void) {

}

void func_02097aac(s32 arg0, u8 arg1) {
    s32 Get3DSpriteTarget();
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern void *g3DSpriteEngineSub;
    void *saved;
    void *engine;
    s32 engineIndex;
    u16 *base;
    s32 rows;
    s32 col;
    s32 row;
    saved=gCur3DSpriteEngine;
    rows=arg1*2+1;
    base=(u16 *)arg0;
    engineIndex=0;
    do {
        if(engineIndex==0)engine=g3DSpriteEngineMain;
        else engine=g3DSpriteEngineSub;
        gCur3DSpriteEngine=engine;
        if(((Get3DSpriteTarget()!=0)||(gCur3DSpriteEngine==g3DSpriteEngineMain)) &&
           ((Get3DSpriteTarget()!=1)||(gCur3DSpriteEngine==g3DSpriteEngineSub)) &&
           ((Get3DSpriteTarget()!=3)||(gCur3DSpriteEngine==saved))) {
            for(row=1;row<rows;row++){
                for(col=0;col<32;col++)base[row*32+col]=0;
            }
        }
        engineIndex++;
    }while(engineIndex<2);
    gCur3DSpriteEngine=saved;
}

void func_02097bac(M2C_UNK arg0) {
    s32 func_02091e70(M2C_UNK);
    s32 *func_02091f18();
    void func_02097aac(s32, u8);
    s32 *temp_r5;
    s32 temp_r4;

    temp_r5 = func_02091f18();
    temp_r4 = func_02091e70(arg0);
    func_02097aac(*temp_r5 + (temp_r4 * 2), M2C_FIELD(Get3DSpriteManager(), u8 *, 0x4A));
}

s32 func_02097be0(void) {
s32 func_020890d4(s32);
s32 i,p,j;
i=0;do {p=func_0209e9dc((u16)i);if(p) {
if(func_020890d4(p))return 1;
j=0;do {if(func_020890d4(Get3DSpriteChild(p,j)))return 1;j++;}while(j<2);
}i++;}while(i<3);return 0;
}

