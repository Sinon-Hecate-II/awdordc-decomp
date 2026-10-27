/* 16 functions from 0x020CE738 to 0x020CF69C (main), found by ds-decomp. */
#include "common.h"

void func_020ce9a0(void) {
extern void **gCurrentMap;
void func_020cd7bc(u8,u8); void func_020cd754(u8);void func_020ce738(void);
void *p=*gCurrentMap;
if(M2C_FIELD((u8 *)p+M2C_FIELD(p,u16 *,0x52a4)*0x8c,u8 *,0x67c3)==3)
func_020cd7bc(M2C_FIELD(p,u16 *,0x52b8),M2C_FIELD(p,u16 *,0x52ba));
else func_020cd754(M2C_FIELD(p,u16 *,0x52ba));
p=*gCurrentMap;
if(M2C_FIELD(p,u8 *,0x5156)!=0 || M2C_FIELD(p,u8 *,0x5158)==2)func_020ce738();
}

void func_020ceea8(void) {
    M2C_UNK func_020a15f8();
    M2C_UNK func_020a4d58();
    M2C_UNK func_020ced08();
    M2C_UNK func_020d1b80();
    M2C_UNK func_020d1f2c();
    M2C_UNK func_020d216c();
    func_020d216c();
    func_020d1f2c();
    func_020d1b80();
    func_020ced08();
    func_020a4d58();
    func_020a15f8();
}

void func_020ceffc(void) {
extern void **gCurrentMap;
s32 i;
for(i=0;i<M2C_FIELD(*gCurrentMap,u16 *,0x5146);i++)
M2C_FIELD((u8 *)*gCurrentMap+i*2,u16 *,0x3758)=i*M2C_FIELD(*gCurrentMap,u16 *,0x5144);
}

void func_020cf058(M2C_UNK arg0) {
    M2C_UNK func_020a231c(s32, s32);
    s32 func_020a8a4c(M2C_UNK, s32);
    s32 var_r5;

    var_r5 = 0;
    do {
        if (var_r5 == 0) {
            func_020a231c(var_r5, 0);
        } else {
            func_020a231c(var_r5, func_020a8a4c(arg0, var_r5));
        }
        var_r5 += 1;
    } while (var_r5 < 5);
}

void func_020cf278(s32 arg0) {
s32 func_020a8898(s32); void func_020ceec8(void);
extern void **gCurrentMap;
u8 old=M2C_FIELD(*gCurrentMap,u8 *,0x5157);
M2C_FIELD(*gCurrentMap,u8 *,0x5157)=func_020a8898(arg0);
func_020ceec8();
M2C_FIELD(*gCurrentMap,u8 *,0x5157)=old;
}

void func_020cf498(s16 arg0, s16 arg1) {
    extern void **gCurrentMap;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = arg0;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = arg1;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C6) = (s16) (arg0 * 0x10);
    M2C_FIELD(*gCurrentMap, s16 *, 0x52C8) = (s16) (arg1 * 0x10);
}

/* Advance the smoothed cursor position stored in the game state toward (targetX, targetY):
   snap to the target if farther than 16 pixels, otherwise step 4 pixels closer. */
void func_020cf4f0(s16 targetX, s16 targetY, s32 unusedArg2, s16 *outX, s16 *outY) {
    extern void **gCurrentMap;
    void *state = *gCurrentMap;
    u16 *cursor = (u16 *)((u8 *)state + 0x52C6);
    u16 curX = cursor[0];
    s32 dx = targetX - curX;
    u16 curY = cursor[1];
    s32 dy;
    s16 newX;
    s16 newY;

    if ((dx < 0 ? -dx : dx) > 0x10 || (dy = targetY - curY, (dy < 0 ? -dy : dy)) > 0x10) {
        curX = targetX;
        curY = targetY;
    } else {
        if ((dx < 0 ? -dx : dx) > 0) curX += (dx > 0 ? 1 : (dx < 0 ? -1 : 0)) * 4;
        if ((dy < 0 ? -dy : dy) > 0) curY += (dy > 0 ? 1 : (dy < 0 ? -1 : 0)) * 4;
    }
    newX = curX;
    newY = curY;
    cursor[0] = newX;
    cursor[1] = newY;
    *outX = newX;
    *outY = newY;
}

void func_020cf5ec(s32 arg0) {
    extern void **gCurrentMap;
    void func_020cf4f0(s16, s16, s32, s16 *, s16 *);
    s16 buf[2];
    func_020cf4f0(
        (s16)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0), s16 *, 0x52c2) << 4),
        (s16)(M2C_FIELD(M2C_FIELD(*gCurrentMap, void **, 0), s16 *, 0x52c4) << 4),
        arg0,
        &buf[1],
        &buf[0]
    );
    {
        void *p = M2C_FIELD(*gCurrentMap, void **, 0x4);
        void (*cb)(s16, s16, s32) = M2C_FIELD(p, void (**)(s16, s16, s32), 0x8);
        if (cb != 0) {
            cb(buf[1], buf[0], arg0);
        }
    }
}

void func_020cf674(s32 arg0,s32 arg1,s32 arg2) {
extern void **gCurrentMap;
void (*callback)(s32,s32,s32);
callback=M2C_FIELD(gCurrentMap[1],void (**)(s32,s32,s32),8);
if(!callback)return;
callback(arg0,arg1,arg2);
}

