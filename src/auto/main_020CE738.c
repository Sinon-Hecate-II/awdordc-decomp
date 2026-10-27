/* 16 functions from 0x020CE738 to 0x020CF69C (main), found by ds-decomp. */
#include "common.h"
extern u8 data_0212bcd4[],data_0212bce0[],data_0212bcf0[],data_0212bd04[],data_0212bd14[],data_0212bd28[],data_0212bd38[],data_0212bd48[];

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

void func_020cea28(void){
s32 func_020d1938(s32);
s32 func_020d273c(u16,s32);
s32 func_020a600c(u16);
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
s32 player,i,id;u8 *unit;
for(player=1;player<5;player++){
if(func_020d1938(player)){
for(i=data_ov000_021aeef4[player]+1;i<data_ov000_021aeef4[player]+0x33;i++){
unit=(u8*)*gCurrentMap+0x59a4+i*14;
if(((u32)(unit[0]<<26)>>26)!=0){
M2C_FIELD(unit,u16*,4)&=~0xc0;
if(!func_020d273c(M2C_FIELD(*gCurrentMap,u16*,0x52a4),player)&&(M2C_FIELD(unit,u16*,4)&0x20)){
if(!unit)id=0;else id=((s32)unit-(s32)((u8*)*gCurrentMap+0x59a4))/14;
if(func_020a600c((u16)id))M2C_FIELD(unit,u16*,4)|=0x40;
}
}
}
}
}
}

void func_020ced08(void) {
    extern void **gCurrentMap;
    extern s8 data_ov000_021b56c0[];
    extern u16 data_ov000_021aeee8[];
    void func_020cf2c8(void);
    s32 func_020d1980(s32);
    void func_0207ab84(s32, s32, u8);

    s32 r8;
    s32 counter;
    void *p;
    u8 tile;
    u8 xc;
    u8 yc;
    u16 *rowTable;
    u16 row;
    u8 posTile;
    s32 i;
    s32 found;
    void *p2;
    u16 *rt2;
    u16 row2;
    u8 pos2;
    void *p3;
    u16 *rt3;
    u16 row3;

    func_020cf2c8();
    r8 = 0;
    counter = 0;
    found = 0;
    for (;;) {
        p = *gCurrentMap;
        tile = ((u8 *)p)[r8 + 0x6C60];
        xc = ((u8 *)p)[r8 + 0x6C61];
        yc = ((u8 *)p)[r8 + 0x6C62];

        if (tile == 0xFF) {
            return;
        }
        if (data_ov000_021b56c0[tile & 0x1F] != 0) {
            rowTable = (u16 *)((u8 *)p + 0x3758);
            row = rowTable[yc];
            posTile = ((u8 *)p)[xc + row + 0x1420];
            if ((posTile & 0xE0) != 0) {
                found = 0;
                for (i = 1; i < 5; i++) {
                    if (func_020d1980(i) != 0) {
                        p2 = *gCurrentMap;
                        rt2 = (u16 *)((u8 *)p2 + 0x3758);
                        row2 = rt2[yc];
                        pos2 = ((u8 *)p2)[xc + row2 + 0x1420];
                        if (data_ov000_021aeee8[i] == (pos2 & 0xE0)) {
                            found = 1;
                            break;
                        }
                    }
                }
                if (found == 0) {
                    if (tile == 0x0F) {
                        p3 = *gCurrentMap;
                        rt3 = (u16 *)((u8 *)p3 + 0x3758);
                        row3 = rt3[yc];
                        ((u8 *)p3)[xc + row3 + 0x1420] = 0x10;
                        row3 = rt3[yc];
                        *((u16 *)((u8 *)p3 + (xc + row3) * 2 + 0xA10)) = 0x1C2;
                    } else {
                        ((u8 *)p)[xc + (s32)row + 0x1420] = (u8)tile;
                        func_0207ab84(xc, yc, 0);
                    }
                }
            }
        }

        r8 += 6;
        counter++;
        if (counter >= 99) {
            break;
        }
    }
}

void func_020ceea8(void) {
    M2C_UNK func_020a15f8();
    M2C_UNK func_020a4d58();
    void func_020ced08(void);
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

void func_020ceec8(void) {
extern void **gCurrentMap;
s32 func_0207dbfc(void);void func_0200bc5c(void*);void func_02080cfc(void*,void*);void func_0207db18(u8);
u8 *p=(u8*)*gCurrentMap+0x5120;
s32 value=func_0207dbfc();
if(value==p[0x37])return;
p=(u8*)*gCurrentMap+0xa60;
func_0200bc5c(data_0212bcd4);
switch(M2C_FIELD(*gCurrentMap,u8*,0x5157)){
case 4:func_02080cfc(data_0212bce0,p+0x6000);break;
case 5:func_02080cfc(data_0212bcf0,p+0x6000);break;
case 6:func_02080cfc(data_0212bd04,p+0x6000);break;
case 7:func_02080cfc(data_0212bd14,p+0x6000);break;
case 8:func_02080cfc(data_0212bd28,p+0x6000);break;
case 9:func_02080cfc(data_0212bd38,p+0x6000);break;
default:func_02080cfc(data_0212bd48,p+0x6000);break;
}
func_0207db18(M2C_FIELD(*gCurrentMap,u8*,0x5157));
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

