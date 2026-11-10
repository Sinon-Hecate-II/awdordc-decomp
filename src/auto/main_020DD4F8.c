/* 25 functions from 0x020DD4F8 to 0x020DE264 (main), found by ds-decomp. */
#include "common.h"
typedef struct {u8 pad[0x59];u8 base:4;u8 pressed:1;u8 rest:3;} SpriteInput;
static inline u8 SpritePressed(void *p) {
void *q=M2C_FIELD(p,void **,0x64);s32 result=1;
if(M2C_FIELD(q,s8 *,11)!=1) {
if(((SpriteInput *)p)->pressed && M2C_FIELD(q,s8 *,12)==1) {}else result=0;
}
return result;
}
static inline u16 SpriteFrame(void *p) {return (M2C_FIELD(p,u32 *,0x40)<<6)>>24;}
static inline u32 SpriteBase(void *p) {return (u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28;}
static inline u8 SpriteAvailable(void *p) {u8 r;if(SpriteBase(p)+2!=SpriteFrame(p))r=1;else r=0;return r;}
static inline void SetSpriteFrame(void *p,u16 frame,s8 timer) {
M2C_FIELD(p,s32 *,0x40)=(M2C_FIELD(p,s32 *,0x40)&~0x03fc0000)|((u32)(frame<<24)>>6);
M2C_FIELD(p,s8 *,0x5a)=timer;
}
static inline void PressSprite(void *p) {if(M2C_FIELD(p,s8 *,0x5a)>=0)SetSpriteFrame(p,SpriteBase(p)+1,12);}


void func_020dd4f8(void *arg0) {
void func_020aacf0(void *);void func_020d47f0(void);void func_01ffa8c4(void *,s32);void func_0208fe30(s32);void func_01ffa6fc(void *);
s32 func_020b212c(void);M2C_UNK func_ov009_02224688(void);s32 func_ov009_022246ac(s32);
extern u16 *data_02101e84;extern M2C_UNK data_02168f7c;
u16 keys;void *p;
if(M2C_FIELD(arg0,void **,0x50))func_020aacf0(M2C_FIELD(arg0,void **,0x50));
if(M2C_FIELD(arg0,void **,0x54))func_020aacf0(M2C_FIELD(arg0,void **,0x54));
if(M2C_FIELD(arg0,void **,0x58))func_020aacf0(M2C_FIELD(arg0,void **,0x58));
keys=*data_02101e84;
M2C_FIELD(arg0,u16 *,0x48)&=~32;
if((SpritePressed(M2C_FIELD(arg0,void **,0x58)) || (keys&2)) && !(M2C_FIELD(arg0,u16 *,0x48)&2)){
func_ov009_02224688();
PressSprite(M2C_FIELD(arg0,void **,0x58));
func_020d47f0();func_01ffa8c4(arg0,1);func_0208fe30(0x1000f);return;
}
if((M2C_FIELD(arg0,s8 *,0x41)>0 || M2C_FIELD(arg0,s8 *,0x42)>0) && M2C_FIELD(arg0,s8 *,0x41)!=M2C_FIELD(arg0,s8 *,0x42)){
func_0208fe30(M2C_FIELD(arg0,s8 *,0x41)<M2C_FIELD(arg0,s8 *,0x42)?0x122:0x123);
M2C_FIELD(arg0,s8 *,0x41)=M2C_FIELD(arg0,s8 *,0x42);
}
if(func_020b212c()<4){
s32 v=(&data_02168f7c)[M2C_FIELD(arg0,s8 *,0x43)];
if(v<0)v=0;else v=func_ov009_022246ac(v);
if(v){void *p=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(p))SetSpriteFrame(p,SpriteBase(p),0);}
else {void *p=M2C_FIELD(arg0,void **,0x50);if(SpriteAvailable(p))SetSpriteFrame(p,SpriteBase(p)+2,0);}
p=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(p))return;
if(!(SpritePressed(p) || (keys&1)))return;
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
PressSprite(p);
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
M2C_FIELD(arg0,u16 *,0x48)&=~1;
M2C_FIELD(arg0,u16 *,0x48)|=2;
func_0208fe30(0x1000d);func_01ffa6fc(arg0);return;
}
p=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(p))SetSpriteFrame(p,SpriteBase(p),0);
p=M2C_FIELD(arg0,void **,0x50);if(!SpriteAvailable(p))return;
if(!(SpritePressed(p) || (keys&1)))return;
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
PressSprite(M2C_FIELD(arg0,void **,0x5c));
if(M2C_FIELD(arg0,u16 *,0x48)&2)return;
M2C_FIELD(arg0,u16 *,0x48)|=1;
M2C_FIELD(arg0,u16 *,0x48)|=2;
func_0208fe30(0x1000d);func_01ffa6fc(arg0);
}

void func_020dd97c(void) {

}

M2C_UNK func_020dd980(void *arg0) {
    void func_020aacf0(void *);
    void func_020d47f0(void);
    void func_01ffa8c4(void *, s32);
    void func_0208fe30(s32);
    void func_01ffa6fc(void *);
    s32 func_020b212c(void);
    extern u16 *data_02101e84;
    extern M2C_UNK data_02168f7c;

    void *temp_r4;
    u16 var_r5;
    s8 var_r1;
    s32 var_r3;
    void *temp_r0;
    void *temp_r2;
    u16 temp_h;
    s32 var_r0;
    s8 temp_r1_4;
    s8 temp_r0_2;
    s32 idx;
    s32 tableVal;
    void *sprite2;
    u8 low;
    u32 currentword;
    u32 currentfield;
    void *spriteA;
    s32 allow2;
    void *unitA;
    s8 ab;
    s8 ac;
    s8 a5a;
    u16 h;
    s32 mode;

    temp_r4 = arg0;

    if (M2C_FIELD(temp_r4, void **, 0x50)) func_020aacf0(M2C_FIELD(temp_r4, void **, 0x50));
    if (M2C_FIELD(temp_r4, void **, 0x54)) func_020aacf0(M2C_FIELD(temp_r4, void **, 0x54));
    if (M2C_FIELD(temp_r4, void **, 0x58)) func_020aacf0(M2C_FIELD(temp_r4, void **, 0x58));

    var_r5 = *data_02101e84;
    temp_h = M2C_FIELD(temp_r4, u16 *, 0x48);
    var_r3 = 1;
    M2C_FIELD(temp_r4, u16 *, 0x48) = (u16)(temp_h & ~0x0020);
    temp_r0 = M2C_FIELD(temp_r4, void **, 0x58);
    temp_r2 = M2C_FIELD(temp_r0, void **, 0x64);
    var_r1 = M2C_FIELD(temp_r2, s8 *, 0x0B);
    if (var_r1 == 1) {
        goto L510;
    }
    if (((u32)(M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1b) >> 0x1f) == 0) {
        goto L50C;
    }
    var_r1 = M2C_FIELD(temp_r2, s8 *, 0x0C);
    if (var_r1 == 1) {
        goto L510;
    }
    var_r3 = 0;
L50C:
L510:
    if (!(var_r3 & 0xff)) {
        if (!(var_r5 & 0x02)) {
            goto L5CC;
        }
    }
    temp_h = M2C_FIELD(temp_r4, u16 *, 0x48);
    if (temp_h & 0x02) {
        goto L5CC;
    }
    temp_r0 = M2C_FIELD(temp_r4, void **, 0x58);
    temp_r1_4 = M2C_FIELD(temp_r0, s8 *, 0x5A);
    if (temp_r1_4 >= 0) {
        M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03fc0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1c) >> 0x1c) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0, u8 *, 0x5A) = 0x0C;
    }
    func_020d47f0();
    mode = M2C_FIELD(temp_r4, s32 *, 0x38);
    if (mode == 0) {
        goto L588;
    }
    if (mode == 1) {
        goto L5AC;
    }
    goto L5C0;
L588:
    M2C_FIELD(temp_r4, u8 *, 0x40) = 0x26;
    temp_h = (u16)(M2C_FIELD(temp_r4, u16 *, 0x48) | 0x20);
    M2C_FIELD(temp_r4, u16 *, 0x48) = temp_h;
    func_01ffa8c4(temp_r4, 0x44);
    goto L5C0;
L5AC:
    M2C_FIELD(temp_r4, u8 *, 0x40) = 0x27;
    func_01ffa8c4(temp_r4, 1);
L5C0:
    func_0208fe30(0x1000F);
    return;

L5CC:
    temp_r1_4 = M2C_FIELD(temp_r4, s8 *, 0x41);
    if (temp_r1_4 <= 0) {
        temp_r0_2 = M2C_FIELD(temp_r4, s8 *, 0x42);
        if (temp_r0_2 <= 0) {
            goto L600;
        }
    }
    temp_r0_2 = M2C_FIELD(temp_r4, s8 *, 0x42);
    if (temp_r1_4 == temp_r0_2) {
        goto L600;
    }
    if (temp_r1_4 < temp_r0_2) {
        func_0208fe30(0x122);
    } else {
        func_0208fe30(0x123);
    }
    M2C_FIELD(temp_r4, s8 *, 0x41) = temp_r0_2;
L600:
    if (func_020b212c() >= 4) {
        goto L7C4;
    }
    idx = func_020b212c();
    sprite2 = M2C_FIELD(temp_r4, void **, 0x50);
    tableVal = *(&data_02168f7c + idx);
    low = (u8)(((u32)(M2C_FIELD(sprite2, u8 *, 0x59) << 0x1c)) >> 0x1c);
    if (tableVal < 0) {
        goto L680;
    }
    currentword = M2C_FIELD(sprite2, u32 *, 0x40);
    currentfield = ((currentword << 6) >> 0x18);
    if (currentfield != ((u32)low + 2U)) {
        goto L6D4;
    }
    M2C_FIELD(sprite2, s32 *, 0x40) = (s32) ((M2C_FIELD(sprite2, s32 *, 0x40) & ~0x03fc0000) | ((u32) ((u16) (((u32) (M2C_FIELD(sprite2, u8 *, 0x59) << 0x1c) >> 0x1c) + 1) << 0x18) >> 6));
    M2C_FIELD(sprite2, u8 *, 0x5A) = 0;
    goto L6D4;
L680:
    M2C_FIELD(sprite2, s32 *, 0x40) = (s32) ((M2C_FIELD(sprite2, s32 *, 0x40) & ~0x03fc0000) | ((u32) ((u16) (((u32) (M2C_FIELD(sprite2, u8 *, 0x59) << 0x1c) >> 0x1c)) << 0x18) >> 6));
    M2C_FIELD(sprite2, u8 *, 0x5A) = 0;
L6D4:
    sprite2 = M2C_FIELD(temp_r4, void **, 0x50);
    low = (u8)(((u32)(M2C_FIELD(sprite2, u8 *, 0x59) << 0x1c)) >> 0x1c);
    currentword = M2C_FIELD(sprite2, u32 *, 0x40);
    currentfield = ((currentword << 6) >> 0x18);
    if (currentfield == ((u32)low + 2U)) {
        return;
    }

L7C4:
    spriteA = M2C_FIELD(temp_r4, void **, 0x50);
    allow2 = 1;
    unitA = M2C_FIELD(spriteA, void **, 0x64);
    ab = M2C_FIELD(unitA, s8 *, 0x0B);
    if (ab != 1) {
        if (((u32)(M2C_FIELD(spriteA, u8 *, 0x59) << 0x1b) >> 0x1f) == 0) {
            goto L73C;
        }
        ac = M2C_FIELD(unitA, s8 *, 0x0C);
        if (ac == 1) {
            goto L740;
        }
L73C:
        allow2 = 0;
    }
L740:
    if (!(allow2 & 0xff)) {
        if (!(var_r5 & 0x01)) {
            return;
        }
        h = M2C_FIELD(temp_r4, u16 *, 0x48);
        if (h & 0x02) {
            return;
        }
    }
    spriteA = M2C_FIELD(temp_r4, void **, 0x50);
    a5a = M2C_FIELD(spriteA, s8 *, 0x5A);
    if (a5a >= 0) {
        M2C_FIELD(spriteA, s32 *, 0x40) = (s32) ((M2C_FIELD(spriteA, s32 *, 0x40) & ~0x03fc0000) | ((u32) ((u16) (((u32) (M2C_FIELD(spriteA, u8 *, 0x59) << 0x1c) >> 0x1c) + 1) << 0x18) >> 6));
        M2C_FIELD(spriteA, u8 *, 0x5A) = 0x0C;
    }
    h = M2C_FIELD(temp_r4, u16 *, 0x48);
    if (h & 0x02) {
        return;
    }
    h = (u16)(h & ~0x0001);
    M2C_FIELD(temp_r4, u16 *, 0x48) = h;
    h = (u16)(h | 0x0002);
    M2C_FIELD(temp_r4, u16 *, 0x48) = h;
    func_0208fe30(0x1000D);
    func_01ffa6fc(temp_r4);
    return;
}

void func_020dde30(void) {
    M2C_UNK func_020dd980();
    func_020dd980();
}

void func_020dde3c(void) {
    void func_020dd4f8();
    func_020dd4f8();
}

void func_020dde48(void) {
    void func_020dd4f8();
    func_020dd4f8();
}

void func_020dde54(void) {
    func_020dd97c();
}

void func_020dde60(void) {
    func_020dd97c();
}

void func_020dde6c(void) {
    M2C_UNK func_020dd980();
    func_020dd980();
}

void func_020dde78(void) {
    M2C_UNK func_020dd980();
    func_020dd980();
}

void func_020dde84(void) {
    func_020dde30();
}

void func_020dde90(void) {
    func_020dde30();
}

M2C_UNK func_020dde9c(void *arg0) {
    M2C_UNK func_ov009_02224688();
    M2C_UNK func_020b2178();
    M2C_UNK func_020b1c44(M2C_UNK, M2C_UNK);
    M2C_UNK func_02088ff4(s32);
    s16 GetSpriteAnimValue(void *);
    s16 temp_r0;
    void *temp_r2;
    u16 value;

    func_020b2178();
    func_020b1c44(0, 0);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x50));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x58));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x5C));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x64));
    temp_r0 = GetSpriteAnimValue(M2C_FIELD(arg0, void **, 0x68));
    temp_r2 = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(temp_r2, s16 *, 0xE) = temp_r0;
    M2C_FIELD(temp_r2, s16 *, 0x10) = -0xFF;
    M2C_FIELD(temp_r2, s16 *, 0xC) = 0xC;
    value = M2C_FIELD(temp_r2, u16 *, 4);
    M2C_FIELD(temp_r2, u16 *, 2) = value;
    return func_ov009_02224688();
}

void func_020ddf04(void) {

}

M2C_UNK func_020ddf08(void *arg0) {
    M2C_UNK func_020b2178();
    M2C_UNK func_020b1c44(M2C_UNK, M2C_UNK);
    M2C_UNK func_02088ff4(s32);
    s16 GetSpriteAnimValue(void *);
    s16 temp_r0;
    void *temp_r2;
    u16 value;

    func_020b2178();
    func_020b1c44(0, 0);
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x50));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x58));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x5C));
    func_02088ff4(M2C_FIELD(arg0, s32 *, 0x64));
    temp_r0 = GetSpriteAnimValue(M2C_FIELD(arg0, void **, 0x68));
    temp_r2 = M2C_FIELD(arg0, void **, 0x68);
    M2C_FIELD(temp_r2, s16 *, 0xE) = temp_r0;
    M2C_FIELD(temp_r2, s16 *, 0x10) = -0xFF;
    M2C_FIELD(temp_r2, s16 *, 0xC) = 0xC;
    value = M2C_FIELD(temp_r2, u16 *, 4);
    M2C_FIELD(temp_r2, u16 *, 2) = value;
    return value;
}

void func_020ddf6c(void) {
    M2C_UNK func_020ddf08();
    func_020ddf08();
}

void func_020ddf78(void) {
    M2C_UNK func_020dde9c();
    func_020dde9c();
}

void func_020ddf84(void) {
    M2C_UNK func_020dde9c();
    func_020dde9c();
}

void func_020ddf90(void) {
    func_020ddf04();
}

void func_020ddf9c(void) {
    func_020ddf04();
}

void func_020ddfa8(void) {
    M2C_UNK func_020ddf08();
    func_020ddf08();
}

void func_020ddfb4(void) {
    M2C_UNK func_020ddf08();
    func_020ddf08();
}

void func_020ddfc0(void) {
    func_020ddf6c();
}

void func_020ddfcc(void) {
    func_020ddf6c();
}

void func_020ddfd8(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_01ff9ce8(M2C_UNK);
    M2C_UNK func_0200bc5c(M2C_UNK *);
    s32 func_02012084();
    M2C_UNK func_02080944(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_020814e4();
    M2C_UNK func_02081528();
    M2C_UNK func_02081590(s32, s32);
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_02088f1c(s32);
    M2C_UNK func_0208b758(s32, s32);
    s16 GetSpriteAnimValue(void *);
    s32 func_020e3218(M2C_UNK *);
    s32 func_ov009_0222429c();
    s32 func_ov009_022246ac(s32);
    M2C_UNK func_ov009_02224730(M2C_UNK, M2C_UNK, s32, s32, s32);
    M2C_UNK func_ov009_022249a4(M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_0212d3f0;
    extern M2C_UNK data_0212d3f8;
    extern M2C_UNK data_0212d408;
    extern M2C_UNK data_0212d418;
    extern M2C_UNK data_02168f7c;
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    s32 temp_r0;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r6;
    s32 var_r1;
    s32 var_r4;
    void *temp_r0_2;
    void *temp_r2;
    void *temp_r4;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    func_01ff9ce8(1);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    func_0200bc5c(&data_0212d3f0);
    func_020e3218(&data_0212d3f8);
    func_020814e4();
    temp_r0 = M2C_FIELD(arg0, s32 *, 0x34);
    var_r1 = -1;
    switch (temp_r0) {                              /* switch 1; irregular */
    case 1:                                         /* switch 1 */
    case 2:                                         /* switch 1 */
        var_r1 = 2;
        break;
    case 0:                                         /* switch 1 */
        switch(M2C_FIELD(arg0,s32 *,0x38)){case 1:var_r1=2;break;default:var_r1=4;break;}
        break;
    }
    if (var_r1 != 2) {
        if (var_r1 == 4) {
            func_02081590(func_020e3218(&data_0212d408), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
        }
    } else {
        func_02081590(func_020e3218(&data_0212d418), M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20));
    }
    func_02081528();
    func_02080944(M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x20), 0x20, 0x18, 5);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 1);
    gCur3DSpriteEngine = temp_r4;
    M2C_FIELD(arg0, u16 *, 0x48) = (u16) (M2C_FIELD(arg0, u16 *, 0x48) | 0x20);
    temp_r0_2 = M2C_FIELD(arg0, void **, 0x54);
    M2C_FIELD(temp_r0_2, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0_2, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0_2, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(temp_r0_2, s8 *, 0x5A) = 0;
    func_02088f1c(M2C_FIELD(arg0, s32 *, 0x58));
    func_02088da8(M2C_FIELD(arg0, s32 *, 0x60));
    func_0208b758(M2C_FIELD(arg0, s32 *, 0x64), 0x44000011);
    func_02088f1c(M2C_FIELD(arg0, s32 *, 0x64));
    if (GetSpriteAnimValue(M2C_FIELD(arg0, void **, 0x68)) != 0) {
        temp_r0=GetSpriteAnimValue(M2C_FIELD(arg0, void **, 0x68));
        temp_r2 = M2C_FIELD(arg0, void **, 0x68);
        M2C_FIELD(temp_r2, s16 *, 0xE) = temp_r0;
        M2C_FIELD(temp_r2, s16 *, 0x10) = 0;
        M2C_FIELD(temp_r2, s16 *, 0xC) = 0xC;
        M2C_FIELD(temp_r2, u16 *, 2) = (u16) M2C_FIELD(temp_r2, u16 *, 4);
    }
    M2C_FIELD(arg0, u16 *, 0x48) = (u16) (M2C_FIELD(arg0, u16 *, 0x48) & ~0x100);
    M2C_FIELD(arg0, u16 *, 0x48) = (u16) (M2C_FIELD(arg0, u16 *, 0x48) & ~0x200);
    M2C_FIELD(arg0, s8 *, 0x41) = 0;
    if (M2C_FIELD(arg0, u16 *, 0x48) & 1) {
        temp_r0_3 = M2C_FIELD(arg0, s32 *, 0x34);
        var_r4 = -1;
        switch (temp_r0_3) {                        /* switch 2; irregular */
        case 1:                                     /* switch 2 */
        case 2:                                     /* switch 2 */
            var_r4 = 2;
            break;
        case 0:                                     /* switch 2 */
            switch(M2C_FIELD(arg0,s32 *,0x38)){case 1:var_r4=2;break;default:var_r4=4;break;}
            break;
        }
        temp_r6 = func_02012084();
        func_ov009_02224730(0, arg1, temp_r6, func_ov009_0222429c(), (u8)var_r4);
        return;
    }
    temp_r0_4 = func_ov009_022246ac(*(&data_02168f7c + M2C_FIELD(arg0, s8 *, 0x43)));
    if (temp_r0_4 == 0) {
        return;
    }
    func_ov009_022249a4(1, arg1, temp_r0_4);
}

