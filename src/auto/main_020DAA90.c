/* 20 functions from 0x020DAA90 to 0x020DB920 (main), found by ds-decomp. */
#include "common.h"
typedef void DAACC_RET;
typedef void DAE_RET;
static inline u32 DisableUnitListIme(void) { u32 old=*(volatile u16 *)0x04000208; *(volatile u16 *)0x04000208=0; return old; }
static inline u32 RestoreUnitListIme(u32 old) { u16 previous; volatile u16 *reg=(volatile u16 *)0x04000208; previous=*reg; *reg=old; return previous; }

void func_020daa90(void) {
    M2C_UNK func_020daa0c();
    func_020daa0c();
}

void func_020daa9c(void) {
    func_020daa0c();
}

void func_020daaa8(void) {
    func_020daa0c();
}

void func_020daab4(void) {
    func_020daa90();
}

void func_020daac0(void) {
    func_020daa90();
}

#pragma opt_strength_reduction off
DAACC_RET func_020daacc(void *arg0) {
    M2C_UNK UpdateSpriteAnimation(s32);
    s32 GetSpriteAnimValue(s32);
    M2C_UNK func_020b1c44(s32, M2C_UNK);
    M2C_UNK func_020809c0(u16 *, s32, s32);
    M2C_UNK func_020e4cd8(u16 *, u32, u32, u32, u16, u16, u32);
    M2C_UNK StringFormat(void *, const char *, ...);
    M2C_UNK func_0209b2b4(s32, s32, s32, void *, s32, s32);
    s32 func_ov009_022246ac(s32);
    extern void **g3DSpriteEngineMain;
    extern void **gCur3DSpriteEngine;
    extern s32 gUnitSlotIds[];
    extern s8 data_0212d244[];
    extern s8 data_0212d248[];
    extern char data_0212d24c[];
    extern u16 data_0212d258[];
    extern char data_0212d270[];
    void *saved;
    void *unit;
    s32 temp_r0;
    u16 temp_r3;
    volatile u32 ime;
    u8 v6b;
    u8 v6c;
    s32 x;
    s32 y;
    s32 i;
    s32 z;
    s32 j;
    s8 buf2[16];
    s8 buf[16];

    UpdateSpriteAnimation(M2C_FIELD(arg0, s32 *, 0x68));
    temp_r0 = GetSpriteAnimValue(M2C_FIELD(arg0, s32 *, 0x68));
    func_020b1c44(temp_r0, 0);
    saved = gCur3DSpriteEngine;
    temp_r3 = 0 - temp_r0;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    M2C_FIELD(*g3DSpriteEngineMain, u16 *, 0x3A) = temp_r3;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0x38) = temp_r3;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x40) = 0;

    if (!(M2C_FIELD(arg0, u16 *, 0x48) & 2)) {
        M2C_FIELD(arg0, s8 *, 0x42) = 0;
        x = (*(s32 *)0x027ffc3c & 1) * 0x180 + 0x124;
        y = 2;
        z = 0x40;
        for (i = 0; i < 4; i++) {
            ime = *(volatile u16 *)0x04000208;
            *(volatile u16 *)0x04000208 = 0;
            unit = (void *)func_ov009_022246ac(i);
            if (unit == NULL) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                continue;
            }
            if (M2C_FIELD(unit, u8 *, 0x4A) != 0x60) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                continue;
            }
            if (!(M2C_FIELD(unit, u8 *, 0x4B) & 1)) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                continue;
            }
            if (!(M2C_FIELD(unit, u8 *, 0x66) & 2)) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                continue;
            }
            if (M2C_FIELD(arg0, s32 *, 0x38) != (s8)M2C_FIELD(unit, s8 *, 0x6D)) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                continue;
            }
            gUnitSlotIds[(s8)M2C_FIELD(arg0, s8 *, 0x42)] = i;
            v6b = M2C_FIELD(unit, u8 *, 0x6B);
            v6c = M2C_FIELD(unit, u8 *, 0x6C);
            func_020809c0((u16 *)(M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24) + 6 + (z << 1)), 0x14, 2);
            func_020e4cd8((u16 *)((u8 *)unit + 0x50), M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x10), M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24), 9, 3, (u16)y, x);
            StringFormat(buf2, data_0212d24c, data_0212d248[0], data_0212d244[1] + v6b, data_0212d248[0], data_0212d244[1] + v6c);
            func_0209b2b4(0x1A, (s16)y, 1, buf2, 0x9000, (u16)(x + 0x28));
            M2C_FIELD(arg0, s8 *, 0x42)++;
            x += 0x34;
            z += 0xA0;
            y += 5;
            if (M2C_FIELD(arg0, s8 *, 0x42) == 4) {
                (void)*(volatile u16 *)0x04000208;
                *(volatile u16 *)0x04000208 = ime;
                break;
            }
            (void)*(volatile u16 *)0x04000208;
            *(volatile u16 *)0x04000208 = ime;
        }
        for (j = M2C_FIELD(arg0, s8 *, 0x42); j < 4; j++) {
            gUnitSlotIds[j] = -1;
            func_020e4cd8(data_0212d258, M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x10), M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24), 9, 3, (u16)y, x);
            StringFormat(buf, data_0212d270);
            func_0209b2b4(0x1A, (s16)y, 1, buf, 0x9000, (u16)(x + 0x28));
            x += 0x34;
            y += 5;
        }
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    gCur3DSpriteEngine = saved;
    return;
}
M2C_UNK UpdateSpriteAnimation(s32);
M2C_UNK func_020dae28(void *arg0) {
    return UpdateSpriteAnimation(M2C_FIELD(arg0, s32 *, 0x68));
}

#pragma opt_strength_reduction off
/* Draws the unit menu's four unit slots: walks the 60 candidate units, keeps those
 * matching the menu's variant (+0x38) and draws each one's portrait and two-glyph
 * name, then fills the unused rows with the empty-slot name. */
DAE_RET DrawUnitSlotList(void *menu) {
    M2C_UNK UpdateSpriteAnimation(s32);
    s32 GetSpriteAnimValue(s32);
    M2C_UNK func_020b1c44(s32, M2C_UNK);
    M2C_UNK func_020809c0(u16 *, s32, s32);
    M2C_UNK func_020e4cd8(u16 *, u32, u32, u32, u16, u16, u32);
    M2C_UNK StringFormat(void *, const char *, ...);
    M2C_UNK func_0209b2b4(s32, s32, s32, void *, s32, s32);
    s32 func_020c52ec(s32);
    s32 func_020c544c(s32);
    s32 func_0203a68c(s32, s32);
    void func_ov010_0222697c(void *);
    s32 func_0203a7c0(s32, u8 *, u8 *, void *, s32 *);
    extern void **g3DSpriteEngineMain;
    extern void **gCur3DSpriteEngine;
    extern s32 gUnitSlotIds[];
    extern s8 data_0212d278[];
    extern s8 data_0212d27c[];
    extern char gUnitListNameFormat[];
    extern u16 data_0212d28c[];
    extern char gUnitListEmptyName[];
    void *savedEngine;
    s32 unit, animValue;
    u16 scroll;
    u8 glyphA, glyphB;
    s32 code;
    s32 x, y, i, z, j;
    s8 nameBuf[16], emptyBuf[16];
    u8 info[108];

    UpdateSpriteAnimation(M2C_FIELD(menu, s32 *, 0x68));
    animValue = GetSpriteAnimValue(M2C_FIELD(menu, s32 *, 0x68));
    func_020b1c44(animValue, 0);
    savedEngine = gCur3DSpriteEngine;
    scroll = -animValue;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    M2C_FIELD(*g3DSpriteEngineMain, u16 *, 0x3a) = scroll;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0x38) = scroll;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x40) = 0;
    if (!(M2C_FIELD(menu, u16 *, 0x48) & 2)) {
        M2C_FIELD(menu, s8 *, 0x42) = 0;
        x = (*(s32 *)0x027ffc3c & 1) * 0x180 + 0x124;
        y = 2;
        z = 0x40;
        for (i = 0; i < 60; i++) {
            unit = func_020c52ec(i);
            if (!unit) continue;
            if (func_020c544c(unit) != 3) continue;
            if (func_0203a68c(unit, 0) != 6) continue;
            func_ov010_0222697c(info);
            if (func_0203a7c0(unit, &glyphA, &glyphB, info, &code) != 6) continue;
            if (!(info[0x1a] & 2) || glyphA == glyphB) continue;
            if (M2C_FIELD(menu, s32 *, 0x38) != M2C_FIELD(info, s8 *, 0x28)) continue;
            gUnitSlotIds[M2C_FIELD(menu, s8 *, 0x42)] = i;
            func_020809c0((u16 *)(M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24) + 6 + (z << 1)), 20, 2);
            func_020e4cd8((u16 *)info, M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x10), M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24), 9, 3, (u16)y, x);
            StringFormat(nameBuf, gUnitListNameFormat, data_0212d27c[0], data_0212d278[1] + glyphB, data_0212d27c[0], data_0212d278[1] + glyphA);
            func_0209b2b4(26, (s16)y, 1, nameBuf, 0x9000, (u16)(x + 0x28));
            M2C_FIELD(menu, s8 *, 0x42)++;
            x += 0x34;
            z += 0xa0;
            y += 5;
            if (M2C_FIELD(menu, s8 *, 0x42) == 4) break;
        }
        for (j = M2C_FIELD(menu, s8 *, 0x42); j < 4; j++) {
            gUnitSlotIds[j] = -1;
            func_020e4cd8(data_0212d28c, M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x10), M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24), 9, 3, (u16)y, x);
            StringFormat(emptyBuf, gUnitListEmptyName);
            func_0209b2b4(26, (s16)y, 1, emptyBuf, 0x9000, (u16)(x + 0x28));
            x += 0x34;
            y += 5;
        }
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    gCur3DSpriteEngine = savedEngine;
}
void func_020db134(void) {
    ((void (*)())DrawUnitSlotList)();
}

void func_020db140(void) {
    DAACC_RET func_020daacc();
    func_020daacc();
}

void func_020db14c(void) {
    DAACC_RET func_020daacc();
    func_020daacc();
}

void func_020db158(void *arg0) {
    M2C_UNK func_020dae28();
    func_020dae28(arg0);
}

void func_020db164(void *arg0) {
    func_020dae28(arg0);
}

void func_020db170(void) {
    ((M2C_UNK (*)())DrawUnitSlotList)();
}

void func_020db17c(void) {
    func_020db134();
}

void func_020db188(void) {
    ((M2C_UNK (*)())DrawUnitSlotList)();
}

void func_020db194(void) {
    func_020db134();
}

#pragma opt_propagation off
void func_020db1a0(void *arg0) {
 M2C_UNK UpdateSpriteAnimation(s32);s32 GetSpriteAnimValue(s32);
 M2C_UNK func_020b1c44(s32,M2C_UNK);M2C_UNK func_020809c0(u16 *,s32,s32);
 M2C_UNK func_020e4cd8(u16 *,u32,u32,u32,u16,u16,u32);
 M2C_UNK StringFormat(void *,const char *,...);M2C_UNK func_0209b2b4(s32,s32,s32,void *,s32,s32);
 s32 func_ov009_02224064(void);s32 func_ov009_022246ac(s32);s32 func_ov009_02225470(void);s32 GetLinkPhase(void);s32 func_ov009_022241b4(void);s32 func_ov009_02224070(s32);
 extern void **gCur3DSpriteEngine,**g3DSpriteEngineMain;
 extern s32 gUnitSlotIds[];
 extern s8 data_0212d2ac[],data_0212d2b0[],data_0212d2c0[],data_0212d2c4[];
 extern char data_0212d2b4[],data_0212d2c8[];extern u16 data_0212d2d4[];
 s8 buf0[16],buf1[16];
 volatile s32 ime;
 void *saved,*unit;
 s32 anim,x,glyphA,glyphB,y,i,z,count,mode;
 u16 scroll;
 UpdateSpriteAnimation(M2C_FIELD(arg0,s32 *,0x68));anim=GetSpriteAnimValue(M2C_FIELD(arg0,s32 *,0x68));
 func_020b1c44(anim,0);scroll=-anim;
 saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
 M2C_FIELD(*g3DSpriteEngineMain,u16 *,0x3a)=scroll;
 M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x42)=0;
 M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x38)=scroll;
 M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x40)=0;
 x=(*(s32 *)0x027ffc3c&1)*0x180+0x124;
 if(M2C_FIELD(arg0,u16 *,0x48)&1) {
 unit=(void *)func_ov009_02224064();count=M2C_FIELD(unit,u8 *,0x1c);glyphA=M2C_FIELD(unit,u8 *,0x1b);
 func_020809c0((u16 *)(M2C_FIELD(gCur3DSpriteEngine,u32 *,0x24)+0x86),20,2);
 func_020e4cd8(unit,M2C_FIELD(gCur3DSpriteEngine,u32 *,0x10),M2C_FIELD(gCur3DSpriteEngine,u32 *,0x24),9,3,2,x);
 StringFormat(buf0,data_0212d2b4,data_0212d2b0[0],data_0212d2ac[1]+glyphA,data_0212d2b0[0],data_0212d2ac[1]+count);
 func_0209b2b4(26,2,1,buf0,0x9000,(u16)(x+40));x+=52;
 } else {
 ime=DisableUnitListIme();
 unit=(void *)func_ov009_022246ac(gUnitSlotIds[M2C_FIELD(arg0,s8 *,0x43)]);
 if(!unit) {M2C_FIELD(arg0,u16 *,0x48)|=0x100;{u32 oldIme=ime;RestoreUnitListIme(oldIme);}return;}
 if((u32)M2C_FIELD(unit,u8 *,0x4a)!=0x60U){{u32 oldIme=ime;RestoreUnitListIme(oldIme);}return;}
 count=M2C_FIELD(unit,u8 *,0x6c);glyphA=func_ov009_02225470();
 if(GetLinkPhase()==7) {
 switch(func_ov009_022241b4()) {case 12:M2C_FIELD(arg0,u16 *,0x48)|=0x200;break;case 1:case 11:case 21:M2C_FIELD(arg0,u16 *,0x48)|=0x100;break;default:M2C_FIELD(arg0,u16 *,0x48)|=0x200;break;}
 {u32 oldIme=ime;RestoreUnitListIme(oldIme);}return;
 }
 func_020809c0((u16 *)(M2C_FIELD(gCur3DSpriteEngine,u32 *,0x24)+0x86),20,2);
 func_020e4cd8((u16 *)((u8 *)unit+0x50),M2C_FIELD(gCur3DSpriteEngine,u32 *,0x10),M2C_FIELD(gCur3DSpriteEngine,u32 *,0x24),9,3,2,x);
 StringFormat(buf1,data_0212d2c8,data_0212d2c4[0],data_0212d2c0[1]+glyphA,data_0212d2c4[0],data_0212d2c0[1]+count);
 func_0209b2b4(26,2,1,buf1,0x9000,(u16)(x+40));
 {u32 oldIme=ime;RestoreUnitListIme(oldIme);}x+=52;
 }
 y=7;i=0;
 if(count>0){ z=0xe0;
 do {
 unit=(void *)func_ov009_02224070(i);
 if(unit&&func_ov009_02225470()>=2U) {
 func_020809c0((u16 *)(M2C_FIELD(gCur3DSpriteEngine,u32 *,0x24)+14+(z<<1)),20,2);
 func_020e4cd8(unit,M2C_FIELD(gCur3DSpriteEngine,u32 *,0x10),M2C_FIELD(gCur3DSpriteEngine,u32 *,0x24),9,7,(u16)y,x);
 x+=40;
 } else {
 func_020809c0((u16 *)(M2C_FIELD(gCur3DSpriteEngine,u32 *,0x24)+14+(z<<1)),20,2);
 func_020e4cd8(data_0212d2d4,M2C_FIELD(gCur3DSpriteEngine,u32 *,0x10),M2C_FIELD(gCur3DSpriteEngine,u32 *,0x24),9,7,(u16)y,x);
 x+=40;
 }
 z+=0x60;y+=3;i++;
 }while(i<count);
 }
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;gCur3DSpriteEngine=saved;
}
#pragma opt_propagation reset
M2C_UNK func_020db5e8(void *arg0) {
    M2C_UNK UpdateSpriteAnimation(s32);
    s32 GetSpriteAnimValue(s32);
    M2C_UNK func_020b1c44(s32, M2C_UNK);
    M2C_UNK func_020809c0(u16 *, s32, s32);
    M2C_UNK func_020e4cd8(u16 *, u32, u32, u32, u16, u16, u32);
    M2C_UNK StringFormat(void *, const char *, ...);
    M2C_UNK func_0209b2b4(s32, s32, s32, void *, s32, s32);
    M2C_UNK func_ov010_02229b00(void);
    s32 func_ov010_02229a38(void);
    s32 func_ov010_02229a40(void);
    u32 func_ov010_02229b0c(s32);
    s32 func_ov010_022282b4(s32);
    s32 func_ov010_02229bdc(void);
    M2C_UNK DrawTimerDigits(s32, s32, u16, s32, s32);
    extern void **gCur3DSpriteEngine;
    extern void **g3DSpriteEngineMain;
    extern void **g3DSpriteEngineSub;
    extern s8 data_0212d2ec[];
    extern s8 data_0212d2f0[];
    extern char data_0212d2f4[];
    extern u16 data_0212d300[];

    void *saved;
    s32 temp;
    u16 scroll;
    s32 x;
    s32 r5, r7, r8, r9, r10;
    s32 threshold;
    s8 buf[16];
    s16 vval;
    u16 f0;
    u32 r3;
    u32 r2;

    UpdateSpriteAnimation(M2C_FIELD(arg0, s32 *, 0x68));
    temp = GetSpriteAnimValue(M2C_FIELD(arg0, s32 *, 0x68));
    func_020b1c44(temp, 0);
    saved = gCur3DSpriteEngine;
    scroll = (u16)(-temp);
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    M2C_FIELD(*g3DSpriteEngineMain, u16 *, 0x3A) = scroll;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x42) = 0;
    M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0x38) = scroll;
    M2C_FIELD(*gCur3DSpriteEngine, s16 *, 0x40) = 0;
    x = (*(s32 *)0x027ffc3c & 1) * 0x180 + 0x124;
    r5 = (s32)func_ov010_02229b00();
    r10 = func_ov010_02229a38();
    threshold = func_ov010_02229a40();
    func_020809c0((u16 *)(M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24) + 0x86), 0x14, 2);
    func_020e4cd8((u16 *)r5, M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x10), M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24), 9, 3, 2, x);
    StringFormat(buf, data_0212d2f4, data_0212d2f0[0], data_0212d2ec[1] + threshold, data_0212d2f0[0], data_0212d2ec[1] + r10);
    func_0209b2b4(0x1a, 2, 1, buf, 0x9000, (u16)(x + 0x28));
    x = x + 0x34;

    if (r10 > 0) {
        r9 = 0xe0;
        r7 = 7;
        r8 = 0;
        while (r8 < r10) {
            r5 = (s32)func_ov010_02229b0c(r8);
            if (r5 != 0 && func_ov010_02229a40() >= 2) {
                func_020809c0((u16 *)(M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24) + 0x0e + (r9 << 1)), 0x14, 2);
                func_020e4cd8((u16 *)r5, M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x10), M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24), 9, 7, (u16)r7, x);
            } else {
                func_020809c0((u16 *)(M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24) + 0x0e + (r9 << 1)), 0x14, 2);
                func_020e4cd8((u16 *)data_0212d300, M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x10), M2C_FIELD(gCur3DSpriteEngine, u32 *, 0x24), 9, 7, (u16)r7, x);
            }
            x = x + 0x28;
            r9 = r9 + 0x60;
            r7 = r7 + 3;
            r8 = r8 + 1;
        }
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    gCur3DSpriteEngine = g3DSpriteEngineSub;

    if (func_ov010_02229a40() >= 2) {
        if (func_ov010_022282b4(3) != 0) {
            if (func_ov010_02229bdc() != 0) {
                vval = (s16)M2C_FIELD(arg0, s16 *, 0x4c);
                if (vval < 0x708) {
                    f0 = M2C_FIELD(*gCur3DSpriteEngine, u16 *, 0x00);
                    r3 = ((u32)f0 << 17) >> 30;
                    r2 = (u32)(0x3ff & (0x1e0 >> (s32)r3));
                    r2 = r2 | 0x7000;
                    DrawTimerDigits(0xc0, 0xa4, (u16)r2, 0, vval);
                    gCur3DSpriteEngine = saved;
                    if (func_ov010_02229a40() >= 2) {
                        return 0;
                    }
                }
            }
        }
    }
    if (func_ov010_022282b4(3) != 0) {
        M2C_FIELD(arg0, u16 *, 0x48) |= 0x100;
    }
    return 0;
}
void func_020db914(void) {
    M2C_UNK func_020db5e8();
    func_020db5e8();
}

