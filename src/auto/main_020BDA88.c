/* 31 functions from 0x020BDA88 to 0x020BE718 (main), found by ds-decomp. */
#include "common.h"
extern M2C_UNK gGameSettings,data_0215d990,data_0215d9b8;
typedef struct { s16 a,b,c,d; } EntryBE;

static inline s32 IsNewerValue(u32 b, u32 a) {
    register u32 result asm("lr") = a & 0xffff0000;
    if (result == 0xffff0000 && !(b & 0xffff0000) && b != 0) result = 0;
    else if (!result && (b & 0xffff0000) == 0xffff0000 && a != 0) result = 1;
    else result = a > b;
    return result;
}

/* Convert the polled touch point to map tile coordinates and, when a tile is under it, record the touched tile in the map context (and in the hover-from-tile state when applicable), notifying the caller of the chosen tile index. */
void func_020bda88(s32 *outTileIndex, s32 arg) {
    void ScreenToMapPosition(u16 touchX, u16 touchY, s32 *coords);
    s32 Divide(s32 value, s32 divisor);
    s32 IsTouchInputDisabled(void);
    s32 func_020caba4(s32 tileX, s32 tileY, s32 mask);
    void CreateTouchCursor(s16 x, s16 y);
    void DeleteTouchCursor(void);
    extern void *gTouchState;
    extern void **gCurrentMap;
    s32 coords[3];
    s32 pixelX, pixelY, tileIndex;
    u16 touchX = M2C_FIELD(gTouchState, u16 *, 0);
    u16 touchY = M2C_FIELD(gTouchState, u16 *, 2);
    void *map;
    if (IsTouchInputDisabled() != 0) return;
    if (M2C_FIELD(gTouchState, u8 *, 0x12) == 0) return;
    ScreenToMapPosition(touchX, touchY, coords);
    pixelX = Divide(coords[0], 0x300);
    pixelY = Divide(coords[1], 0x300);
    tileIndex = func_020caba4(pixelX, pixelY, arg);
    if (tileIndex >= 0) {
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = pixelX;
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = pixelY;
        *outTileIndex = tileIndex;
    }
    if (M2C_FIELD(gTouchState, u8 *, 0x14) != 0) {
        M2C_FIELD(*gCurrentMap, s16 *, 0x52CA) = pixelX;
        M2C_FIELD(*gCurrentMap, s16 *, 0x52CC) = pixelY;
        map = *gCurrentMap;
        CreateTouchCursor(M2C_FIELD(map, s16 *, 0x52CA), M2C_FIELD(map, s16 *, 0x52CC));
    }
    map = *gCurrentMap;
    if (M2C_FIELD(map, s16 *, 0x52CA) == pixelX && M2C_FIELD(map, s16 *, 0x52CC) == pixelY) return;
    DeleteTouchCursor();
    M2C_FIELD(*gCurrentMap, s16 *, 0x52CA) = 255;
    M2C_FIELD(*gCurrentMap, s16 *, 0x52CC) = 255;
}

s32 func_020bdbf4(s32 arg0) {
s32 IsTouchInputDisabled(void); void ScreenToMapPosition(u16,u16,s32 *); s32 Divide(s32,s32); void func_020bd104(void); s32 func_020caba4(s32,s32,s32); extern void *gTouchState; extern void **gCurrentMap;
s32 coords[3];u16 x,y;s32 scaledX,scaledY,result;
x=M2C_FIELD(gTouchState,u16 *,0);y=M2C_FIELD(gTouchState,u16 *,2);
if(IsTouchInputDisabled()!=0)return 0;
ScreenToMapPosition(x,y,coords);scaledX=Divide(coords[0],0x300);scaledY=Divide(coords[1],0x300);
if(M2C_FIELD(gTouchState,u8 *,0x16)==0)return 0;
if(scaledX==M2C_FIELD(*gCurrentMap,s16 *,0x52ca)&&scaledY==M2C_FIELD(*gCurrentMap,s16 *,0x52cc)){func_020bd104();if(func_020caba4(scaledX,scaledY,arg0)>=0)result=0x10;else result=0x20;}else result=0;return result;
}

s32 func_020bdcd0(void) {
    s32 IsTouchInputDisabled();
    extern void *gTouchState;
    if (IsTouchInputDisabled() != 0) {
        return 0;
    }
    if ((M2C_FIELD(gTouchState, u8 *, 0x12) == 0) || ((u32) M2C_FIELD(gTouchState, u8 *, 0x10) < 0x14U)) {
        return 0x20;
    }
    return 0;
}

s32 func_020bdd18(void) {
 s32 IsTouchInputDisabled(void);
 void DeleteTouchCursor(void);
 void func_020bd104(void);
 extern void *gTouchState;
 extern void **gCurrentMap;
 if (IsTouchInputDisabled()) return 0;
 if (M2C_FIELD(gTouchState,u8 *,0x12) && M2C_FIELD(gTouchState,u8 *,0x10)==20) {
 DeleteTouchCursor();
 M2C_FIELD(*gCurrentMap,s16 *,0x52ca)=255;
 M2C_FIELD(*gCurrentMap,s16 *,0x52cc)=255;
 }
 if (M2C_FIELD(gTouchState,u8 *,0x16) &&
 M2C_FIELD(*gCurrentMap,s16 *,0x52c2)==M2C_FIELD(*gCurrentMap,s16 *,0x52ca) &&
 M2C_FIELD(*gCurrentMap,s16 *,0x52c4)==M2C_FIELD(*gCurrentMap,s16 *,0x52cc)) {
 func_020bd104(); return 16;
 }
 return 0;
}

/* Update the selection cursor from the current stylus position and return any resulting action code. */
s32 GetMapCursorTouchAction(void) {
    s32 IsTouchInputDisabled(void);
    s32 func_020bdef8(s32, s32);
    void DeleteTouchCursor(void);
    void func_020bd104(void);
    extern void *gTouchState;
    extern void **gCurrentMap;

    u16 touchX, touchY;
    touchX = M2C_FIELD(gTouchState, u16 *, 0);
    touchY = M2C_FIELD(gTouchState, u16 *, 2);
    if (IsTouchInputDisabled()) return 0;
    if (M2C_FIELD(gTouchState, u8 *, 0x14)) {
        if (func_020bdef8(touchX, touchY)) return 32;
    }
    if (M2C_FIELD(gTouchState, u8 *, 0x12) && M2C_FIELD(gTouchState, u8 *, 0x10) == 20) {
        DeleteTouchCursor();
        M2C_FIELD(*gCurrentMap, s16 *, 0x52ca) = 255;
        M2C_FIELD(*gCurrentMap, s16 *, 0x52cc) = 255;
    }
    if (M2C_FIELD(gTouchState, u8 *, 0x16) &&
        M2C_FIELD(*gCurrentMap, s16 *, 0x52c2) == M2C_FIELD(*gCurrentMap, s16 *, 0x52ca) &&
        M2C_FIELD(*gCurrentMap, s16 *, 0x52c4) == M2C_FIELD(*gCurrentMap, s16 *, 0x52cc)) {
        func_020bd104();
        return 16;
    }
    return 0;
}

s32 func_020bdecc(s32 arg0, s32 arg1) {
    if ((arg0 >= 0x70) && (arg0 <= 0x90) && (arg1 >= 0) && (arg1 <= 0x10)) {
        return 1;
    }
    return 0;
}

s32 func_020bdef8(s32 arg0, s32 arg1) {
    if ((arg0 >= 0x70) && (arg0 <= 0x90) && (arg1 >= 0) && (arg1 <= 0x10)) {
        return 1;
    }
    return 0;
}

s32 IsTouchOnNextButton(s32 arg0, s32 arg1) {
    if ((arg0 >= 0x70) && (arg0 <= 0x90) && (arg1 >= 0) && (arg1 <= 0x10)) {
        return 1;
    }
    return 0;
}

s32 func_020bdf50(s32 arg0, s32 arg1) {
    if ((arg0 >= 0x40) && (arg0 <= 0x60) && (arg1 >= 0) && (arg1 <= 0x10)) {
        return 1;
    }
    return 0;
}

s32 func_020bdf7c(s32 arg0, s32 arg1) {
    if ((arg0 >= 0xA0) && (arg0 <= 0xC0) && (arg1 >= 0) && (arg1 <= 0x10)) {
        return 1;
    }
    return 0;
}

void func_020bdfa8(void) {
    M2C_UNK func_020be0ac(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    func_020be0ac(0x70, 0, 0x20, 0x10, 0x9000, 0x1F0);
}

void func_020bdfdc(void) {
    func_020be0ac(0x70, 0, 0x20, 0x10, 0x9000, 0x1F8);
}

void func_020be010(void) {
    func_020be0ac(0x70, 0, 0x20, 0x10, 0x9000, 0x1E8);
}

void func_020be044(void) {
    func_020be0ac(0x40, 0, 0x20, 0x10, 0x9000, 0x200);
}

void func_020be078(void) {
    func_020be0ac(0xA0, 0, 0x20, 0x10, 0x9000, 0x208);
}

M2C_UNK func_020be0ac(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f) {
s32 GetSpriteDescForSize(s32,s32);M2C_UNK func_01ff883c(u16,u8,u16,s32);extern u16 **gCur3DSpriteEngine;
s32 v;u32 x;u32 shift;u32 flags;
v=GetSpriteDescForSize(c,d);
x=a&511;b=(u8)b;
shift=(u32)(**gCur3DSpriteEngine<<17)>>30;
flags=e|((f>>shift)&1023);
return func_01ff883c((u16)x,(u8)b,(u16)flags,v);
}

M2C_UNK *func_020be120(void) {
    extern M2C_UNK data_0215deec;
    return &data_0215deec;
}

void func_020be12c(void) {

}

void func_020be130(void *arg0) {
    s32 func_02076208();
    M2C_UNK func_02076244();
    M2C_UNK GetLocalizedText(s32);
    M2C_UNK HeapFreeBlock(s32);
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x54);
    if (func_02076208() != 0) {
        GetLocalizedText(0xC000034C);
        func_02076244();
    }
    if (temp_r4 == 0) {
        return;
    }
    HeapFreeBlock(temp_r4);
}

void func_020be168(M2C_UNK arg0) {
    s32 func_020761f8();
    M2C_UNK DeleteSpriteObject(M2C_UNK);
    if (func_020761f8() != 0) {
        return;
    }
    DeleteSpriteObject(arg0);
}

void func_020be188(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212948c;
    M2C_FIELD(func_01ffa3dc(&data_0212948c, 6), s32 *, 0x54) = arg0;
}

u8 func_020be1a8(void) {
 s32 FindObjectByClass(M2C_UNK *);
 extern M2C_UNK data_0212948c;
 u8 result;
 if (FindObjectByClass(&data_0212948c)) return 1;
 if (func_020761f8()) result=1; else result=0;
 return result;
}

void func_020be1dc(s32 arg0) {
void *GetSaveRecordList(void);s32 GetSaveRecordCount(void);
M2C_UNK PruneSaveRecords(s32,s32);M2C_UNK DeleteSaveRecord(u16);
u8 *p,*best;s32 n,i,id;
switch(arg0){case 2:case 3:case 4:PruneSaveRecords(arg0,1);return;}
p=GetSaveRecordList();best=0;n=GetSaveRecordCount();i=0;
if(n>0)do{if(arg0==p[2]){if(best){if(!IsNewerValue(M2C_FIELD(best,u32 *,4),M2C_FIELD(p,u32 *,4))) goto next;}best=p;}next:i++;p+=40;}while(i<n);
if(best)id=*(u16 *)best;else id=-1;
if(id==-1)return;
DeleteSaveRecord((u16)id);
}

void func_020be2e0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02075fd8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_02075fd8(arg0, 0, arg1, arg2);
}

void func_020be2f8(M2C_UNK arg0) {
    M2C_UNK func_020be718();
    func_020be718();
    func_020be1dc(4);
    func_020be2e0(arg0, 0x5CC, 4);
}

u8 func_020be324(s32 arg0,M2C_UNK arg1){
void *GetSaveRecordList(void);s32 GetSaveRecordCount(void);s32 LoadSaveRecord(u16,M2C_UNK);s32 func_02076208(void);M2C_UNK GetLocalizedText(s32);M2C_UNK func_02076244();
u8 *p,*best;s32 n,i,id; s32 better; u32 high;u32 b,a;u8 result;
p=GetSaveRecordList();best=0;n=GetSaveRecordCount();i=0;
if(n>0)do{if(arg0==p[2]){if(best){better=IsNewerValue(M2C_FIELD(best,u32 *,4),M2C_FIELD(p,u32 *,4));
if(!better)goto next;
}best=p;}next:i++;p+=40;}while(i<n);
if(best)id=*(u16 *)best;else id=-1;
if(id==-1)return 0;
result=LoadSaveRecord(id,arg1);
if(func_02076208()){GetLocalizedText(0xc000034d);func_02076244();}
return result;
}

void func_020be438(s32 a,s32 b,s32 c) {
 s32 HeapAllocBlock(s32);
 s32 v=0;
 func_020be1dc(a);
 func_020be2e0(b,c,(u8)a);
 if(a!=4) {v=HeapAllocBlock(0x6000);func_020be2f8(v);}
 func_02076198();
 func_020be188(v);
}

void func_020be488(s32 a) {
    s32 HeapAllocBlock(s32);
    s32 v=0;
    func_020be1dc(a);
    if(a!=4) {
        v=HeapAllocBlock(0x6000);
        func_020be2f8(v);
    }
    func_02076198();
    func_020be188(v);
}

s32 func_020be4c0(s32 arg0) { void *GetSaveRecordList(void); s32 GetSaveRecordCount(void); u8 *p,*best; s32 n,i,better,id;u32 b,a,high;
p=GetSaveRecordList();best=0;n=GetSaveRecordCount();i=0;
if(n>0)do{if(arg0==p[2]){if(best){a=M2C_FIELD(p,u32 *,4);b=M2C_FIELD(best,u32 *,4);high=a&0xffff0000;
if(high==0xffff0000 && !(b&0xffff0000) && b!=0)better=0;
else if(high==0 && (b&0xffff0000)==0xffff0000 && a!=0)better=1;
else better=a>b;
if(!better)goto next;
}best=p;}next:i++;p+=40;}while(i<n);
if(best)id=*(u16 *)best;else id=-1;return id!=-1; }

void func_020be59c(void) {
    M2C_UNK PruneSaveRecords(s32, M2C_UNK);
    M2C_UNK func_02076198();
    s32 var_r5;

    var_r5 = 4;
    do {
        PruneSaveRecords(var_r5, 0);
        var_r5 += 1;
    } while (var_r5 < 0x3B);
    func_02076198();
    func_020be188(0);
}

/* Restore the game settings to their defaults: mark the settings block valid,
 * clear and re-stamp the option/zoom word, reset the army/unit option tables
 * and the save records, set the default slot words and clear the per-slot
 * setting words. Runs at startup and whenever the settings magic is missing. */
void InitDefaultGameSettings(void) {
M2C_UNK func_02086b9c();M2C_UNK func_02091bcc();M2C_UNK func_020bf814(M2C_UNK);M2C_UNK func_020bf8ac(s32,s32);M2C_UNK func_020bf8fc(s32,s32);M2C_UNK func_020bf9f0(M2C_UNK);M2C_UNK func_020bfa30(M2C_UNK);M2C_UNK func_020bfa80(M2C_UNK);M2C_UNK func_020e47f8();M2C_UNK func_020e49ec();
s32 i,slot,entry; s32 flagOff,modeOff;
M2C_FIELD(&gGameSettings,s32 *,0x128)=GAME_SETTINGS_MAGIC;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~15;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0x70;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0xc00;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0x3000;
M2C_FIELD(&data_0215d990,u16 *,0x2e)|=0x4000;
M2C_FIELD(&data_0215d990,u16 *,0x2e)&=~0x8000;
func_020bfa80(0);
i=0;flagOff=0;modeOff=0;
do{func_020bf8ac(i,flagOff);func_020bf8fc(i,modeOff);++i;}while(i<15);
func_020bf814(0);func_020e47f8();func_020e49ec();func_02086b9c();func_02091bcc();
M2C_FIELD(&data_0215d990,u16 *,0x2e)=(M2C_FIELD(&data_0215d990,u16 *,0x2e)&~0x380)|0x80;
func_020bf9f0(95);func_020bfa30(95);
slot=0;
M2C_FIELD(&gGameSettings,s32 *,0x140)=0;
M2C_FIELD(&gGameSettings,s32 *,0x144)=1;
M2C_FIELD(&gGameSettings,s32 *,0x148)=1;
M2C_FIELD(&gGameSettings,s32 *,0x14c)=6;
M2C_FIELD(&gGameSettings,s32 *,0x150)=0;
M2C_FIELD(&gGameSettings,s32 *,0x154)=0;
M2C_FIELD(&gGameSettings,s32 *,0x158)=0;
do{M2C_FIELD((u8 *)&data_0215d9b8+(u32)slot*8,s16 *,0x36)=0;++slot;}while(slot<4);
entry=0;
do{M2C_FIELD((u8 *)&data_0215d9b8+(u32)entry*2,s16 *,8)=0;++entry;}while(entry<4);
}

