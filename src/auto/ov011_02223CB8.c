/* 5 functions from 0x02223CB8 to 0x02224B9C (ov011), found by ds-decomp. */
#include "common.h"
typedef struct {u8 bytes[25];} IntroColors_022242dc;
extern const IntroColors_022242dc data_ov011_02227f64;
extern u8 data_02101f5c[],data_02101f0c[];
void G3_UpdateIntroTiles(void *,u8,s16,u16,void *);
void func_ov011_02223764(void *,s16,u8,void *);
void G3_SubmitSpriteQuad(void *,int,int,s16,s16);
int GetLanguage(void);
int EaseInterpolate(int,int,int,u16,int);
void func_0208ffe4(int,int,int);
void func_ov011_02224b9c(void *,int);
void func_ov011_02224aac(void *,int);
void func_ov011_0222491c(void *);
int PlaySoundEffect(int);
int func_02090034(int,int);
void func_01ffac9c(int,int,int,void *,int);
extern u16 gIntroAnimState[6];

/* Handles an entry's per-frame update across both screen buffers for states 2 and 3. */
void func_ov011_02223cb8(void *entry){
void LoadOpeningScreenAssets(void *,s32,s32);void func_ov011_02224f00(void *);void func_0208f7d0(s32);
extern s32 gCur3DSpriteEngine,g3DSpriteEngineMain,g3DSpriteEngineSub;
u8 color[2]={0};
s32 savedEngine,bufIndex,screenEngine;
M2C_FIELD(entry,u16 *,0x34)=0;
switch(M2C_FIELD(entry,u8 *,0x39)){
case 0:
{
u16 *volatile p0;u16 *volatile p1;u16 *volatile p2;u16 *volatile p3;u16 *volatile p4;
G3_SubmitSpriteQuad(entry,2,2,0x80,0x60);
LoadOpeningScreenAssets(entry,3,0);
G3_UpdateIntroTiles(entry,0,0,0,color);
savedEngine=gCur3DSpriteEngine;bufIndex=0;
do{
if(bufIndex==0)screenEngine=g3DSpriteEngineMain;else screenEngine=g3DSpriteEngineSub;
gCur3DSpriteEngine=screenEngine;
p0=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p0=*p0&~0x10;
p1=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p1=*p1&~0x20;
p2=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p2=*p2&~0x40;
p3=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p3=*p3&~0x80;
p4=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p4=*p4|0x100;
bufIndex++;
}while(bufIndex<2);
gCur3DSpriteEngine=savedEngine;
func_0208f7d0(0x1000E);
}
break;
case 2:
{
u16 *volatile p0;u16 *volatile p1;u16 *volatile p2;u16 *volatile p3;u16 *volatile p4;
func_ov011_02224aac(entry,0);
G3_UpdateIntroTiles(entry,0,0,0,color);
func_ov011_02223764(entry,0,0,0);
savedEngine=gCur3DSpriteEngine;bufIndex=0;
do{
if(bufIndex==0)screenEngine=g3DSpriteEngineMain;else screenEngine=g3DSpriteEngineSub;
gCur3DSpriteEngine=screenEngine;
p0=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p0=*p0&~0x10;
p1=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p1=*p1&~0x20;
p2=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p2=*p2|0x40;
p3=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p3=*p3|0x80;
p4=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p4=*p4&~0x100;
bufIndex++;
}while(bufIndex<2);
gCur3DSpriteEngine=savedEngine;
}
break;
case 4:
{
u16 *volatile p0;u16 *volatile p1;u16 *volatile p2;u16 *volatile p3;u16 *volatile p4;
func_ov011_02224aac(entry,5);
G3_SubmitSpriteQuad(entry,2,3,0x80,0x60);
G3_UpdateIntroTiles(entry,0,0,0,color);
func_ov011_02224f00(entry);
savedEngine=gCur3DSpriteEngine;bufIndex=0;
do{
if(bufIndex==0)screenEngine=g3DSpriteEngineMain;else screenEngine=g3DSpriteEngineSub;
gCur3DSpriteEngine=screenEngine;
p0=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p0=*p0&~0x10;
p1=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p1=*p1&~0x20;
p2=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p2=*p2&~0x40;
p3=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p3=*p3|0x80;
p4=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p4=*p4|0x100;
bufIndex++;
}while(bufIndex<2);
gCur3DSpriteEngine=savedEngine;
}
break;
case 6:
{
u16 *volatile p0;u16 *volatile p1;u16 *volatile p2;u16 *volatile p3;u16 *volatile p4;
G3_SubmitSpriteQuad(entry,2,2,0x80,0x60);
G3_SubmitSpriteQuad(entry,2,3,0x80,0x60);
func_ov011_02224b9c(entry,1);
G3_UpdateIntroTiles(entry,0,0,0,color);
func_ov011_02223764(entry,0,0,0);
savedEngine=gCur3DSpriteEngine;bufIndex=0;
do{
if(bufIndex==0)screenEngine=g3DSpriteEngineMain;else screenEngine=g3DSpriteEngineSub;
gCur3DSpriteEngine=screenEngine;
p0=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p0=*p0&~0x10;
p1=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p1=*p1&~0x20;
p2=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p2=*p2|0x40;
p3=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p3=*p3|0x80;
p4=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p4=*p4|0x100;
bufIndex++;
}while(bufIndex<2);
gCur3DSpriteEngine=savedEngine;
}
break;
case 8:
{
u16 *volatile p0;u16 *volatile p1;u16 *volatile p2;u16 *volatile p3;u16 *volatile p4;
func_ov011_02223764(entry,0,0,0);
LoadOpeningScreenAssets(entry,6,0);
G3_UpdateIntroTiles(entry,0,0,0,color);
savedEngine=gCur3DSpriteEngine;bufIndex=0;
do{
if(bufIndex==0)screenEngine=g3DSpriteEngineMain;else screenEngine=g3DSpriteEngineSub;
gCur3DSpriteEngine=screenEngine;
p0=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p0=*p0&~0x10;
p1=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p1=*p1&~0x20;
p2=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p2=*p2&~0x40;
p3=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p3=*p3&~0x80;
p4=(u16 *)(M2C_FIELD(gCur3DSpriteEngine,s32 *,0));*p4=*p4|0x100;
bufIndex++;
}while(bufIndex<2);
gCur3DSpriteEngine=savedEngine;
}
break;
case 9:
break;
}
}

/* Updates intro sequence states and effects */
void func_ov011_022242dc(void *p) {
 IntroColors_022242dc colors = data_ov011_02227f64;
 u8 mode;
 u16 time;
 switch (M2C_FIELD(p, u8 *, 0x39)) {
 case 0:
  G3_UpdateIntroTiles(p, 1, 0x7fff, 0x8052, colors.bytes);
  break;
 case 1:
  G3_UpdateIntroTiles(p, 1, 0x7ff, 0x8052, colors.bytes);
  break;
 case 2:
  if (M2C_FIELD(p, u16 *, 0x34) == 3) func_0208ffe4(0, -1, 300);
  func_ov011_02224aac(p, 2);
  break;
 case 3:
  if (M2C_FIELD(p, u16 *, 0x34) == 342) PlaySoundEffect(302);
  if (M2C_FIELD(p, u16 *, 0x34) == 343) func_02090034(0, 96);
  break;
 case 4:
  if (GetLanguage() == 5 || GetLanguage() == 4) G3_UpdateIntroTiles(p, 5, 108, 128, colors.bytes + 20);
  else G3_UpdateIntroTiles(p, 5, 108, 128, colors.bytes + 5);
  G3_SubmitSpriteQuad(p, 2, 3, 128, (s16)(32 + EaseInterpolate(0, 0, 64, M2C_FIELD(p, u16 *, 0x34), 796)));
  break;
 case 5:
  if ((int)M2C_FIELD(p, u16 *, 0x34) - 650 > 20) {
   if (GetLanguage() == 5 || GetLanguage() == 4) func_ov011_02223764(p, -108, 5, colors.bytes + 20);
   else func_ov011_02223764(p, -108, 5, colors.bytes + 5);
  } else {
   if (GetLanguage() == 5 || GetLanguage() == 4) G3_UpdateIntroTiles(p, 5, 0x7fff, 48, colors.bytes + 20);
   else G3_UpdateIntroTiles(p, 5, 0x7fff, 48, colors.bytes + 5);
  }
  G3_SubmitSpriteQuad(p, 2, 3, 128, (s16)(32 + EaseInterpolate(0, 0, 64, M2C_FIELD(p, u16 *, 0x34), 796)));
  break;
 case 6:
  mode = GetLanguage() == 4 ? 4 : 5;
  G3_UpdateIntroTiles(p, mode, 108, 128, colors.bytes + 10);
  if ((int)M2C_FIELD(p, u16 *, 0x34) <= 618) {
   G3_SubmitSpriteQuad(p, 2, 2, (s16)(256 - EaseInterpolate(0, 0, 128, M2C_FIELD(p, u16 *, 0x34), 618)), 96);
   G3_SubmitSpriteQuad(p, 2, 3, (s16)EaseInterpolate(0, 0, -128, M2C_FIELD(p, u16 *, 0x34), 618), 96);
  }
  break;
 case 7:
  mode = GetLanguage() == 4 ? 4 : 5;
  time = (u16)(M2C_FIELD(p, u16 *, 0x34) - 650);
  if (time == 0) { func_ov011_02224b9c(p, 4); func_0208ffe4(0, -1, 301); }
  if (time > 66) func_ov011_02223764(p, -98, mode, colors.bytes + 10);
  else if (time > 20) func_ov011_02224b9c(p, 3);
  G3_UpdateIntroTiles(p, (u8)(mode | 128), 0x7fff, 128, colors.bytes + 10);
  break;
 case 8:
  if (GetLanguage() == 2) G3_UpdateIntroTiles(p, 130, 286, 0x8052, colors.bytes + 15);
  else if (M2C_FIELD(p, u16 *, 0x34) > 108 && M2C_FIELD(p, u16 *, 0x34) <= 168) {
   func_01ffac9c(0, 82, 0, data_02101f5c, 0);
   func_01ffac9c(128, 82, 32, data_02101f5c, 0);
   if (GetLanguage() == 4) func_01ffac9c(0, 74, 128, data_02101f0c, 0);
  } else G3_UpdateIntroTiles(p, 2, 108, 0x8052, colors.bytes + 15);
  break;
 case 9:
  G3_UpdateIntroTiles(p, 130, 0x7fff, 0x8052, colors.bytes + 15);
  break;
 }
 func_ov011_0222491c(p);
 M2C_FIELD(p, u16 *, 0x34)++;
}

void func_ov011_022247f4(void *p){
void func_ov011_0222491c(void *);
extern const u16 gIntroStateDurations[];
switch(M2C_FIELD(p,u8 *,0x38)){
case 1:
M2C_FIELD(p,u16 *,0x34)++;
if(M2C_FIELD(p,u16 *,0x34)>120){
M2C_FIELD(p,u16 *,0x34)=32;
M2C_FIELD(p,u8 *,0x38)++;
func_01ffa6fc(p);return;
}break;
case 2:
M2C_FIELD(p,u16 *,0x34)++;
if(M2C_FIELD(p,u8 *,0x36)){
if(++M2C_FIELD(p,u8 *,0x36)>=1){
M2C_FIELD(p,u8 *,0x36)=0;SetSpriteAnimation(p,4);
}return;
}
if(M2C_FIELD(p,u16 *,0x34)>=0x528){
M2C_FIELD(p,u8 *,0x38)=3;
M2C_FIELD(p,u8 *,0x39)=0;SetSpriteAnimation(p,3);
}break;
case 3:
if(M2C_FIELD(p,u16 *,0x34)>gIntroStateDurations[M2C_FIELD(p,u8 *,0x39)]){
if(M2C_FIELD(p,u8 *,0x39)>10){
if(M2C_FIELD(p,s32 *,0x3c)==2)SetSpriteAnimation(p,4);
else SetSpriteAnimation(p,2);
return;
}
func_01ffa6fc(p);return;
}break;
}
func_ov011_0222491c(p);
}

void func_ov011_0222491c(void *entry) {
    M2C_UNK SetSpriteAnimation(void *, M2C_UNK);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_02090034(M2C_UNK, M2C_UNK);
    M2C_UNK func_020ac998(s32);
    M2C_UNK func_020aca8c(s32);
    extern u16 *gKeyState;
    extern void *gTouchState;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 gCur3DSpriteEngine;
    s32 savedContext;
    s32 savedContext2;
    s32 screenIndex;
    s32 screenIndex2;
    s32 chosenContext;
    s32 chosenContext2;
    u16 keys;
    u8 state;

    keys = *gKeyState;
    if (!(keys & 1) && !(keys & 8) && (M2C_FIELD(gTouchState, u8 *, 0x14) == 0)) {
        return;
    }
    if ((M2C_FIELD(entry, s32 *, 0x3C) == 2) && !(keys & 8) && (M2C_FIELD(gTouchState, u8 *, 0x14) == 0)) {
        return;
    }
    state = M2C_FIELD(entry, u8 *, 0x38);
    switch (state) {                              /* irregular */
    case 1:
        return;
    case 2:
        if (M2C_FIELD(entry, u8 *, 0x37) != 0x20) {
            return;
        }
        screenIndex = 0;
        savedContext = gCur3DSpriteEngine;
        do {
            if (screenIndex == 0) {
                chosenContext = g3DSpriteEngineMain;
            } else {
                chosenContext = g3DSpriteEngineSub;
            }
            gCur3DSpriteEngine = chosenContext;
            func_020ac998(0);
            screenIndex += 1;
        } while (screenIndex < 2);
        gCur3DSpriteEngine = savedContext;
        PlaySoundEffect(0x1000D);
        M2C_FIELD(entry, s8 *, 0x36) = 1;
        M2C_FIELD(entry, u8 *, 0x37) = 4U;
        return;
    case 3:
        screenIndex2 = 0;
        savedContext2 = gCur3DSpriteEngine;
        do {
            if (screenIndex2 == 0) {
                chosenContext2 = g3DSpriteEngineMain;
            } else {
                chosenContext2 = g3DSpriteEngineSub;
            }
            gCur3DSpriteEngine = chosenContext2;
            func_020aca8c(0);
            screenIndex2 += 1;
        } while (screenIndex2 < 2);
        gCur3DSpriteEngine = savedContext2;
        if ((u32) (u8) (M2C_FIELD(entry, u8 *, 0x39) + 0xFE) <= 1U) {
            func_02090034(0, 3);
        }
        if (M2C_FIELD(entry, s32 *, 0x3C) == 2) {
            SetSpriteAnimation(entry, 4);
            return;
        }
        SetSpriteAnimation(entry, 2);
        return;
    }
}

/* Configure an overlay entry's display state: set up sprite slots, refresh masks, or tear down depending on the command. */
void func_ov011_02224aac(void *entry, s32 command) {
    s32 EaseInterpolate(s32, s32, s32, u16, s32);
    void func_ov011_022216d8(void *, s32, s32, s32);
    void func_ov011_02222830(void *, s32, s32, s32, s32);
    void G3_SetSpriteTransformScale(void *, s32, s32);
    switch (command) {
    case 0:
        func_ov011_022216d8(entry, 11, 0, 2);
        func_ov011_022216d8(entry, 12, 1, 2);
        func_ov011_022216d8(entry, 17, 0, 3);
        func_ov011_022216d8(entry, 18, 1, 3);
        gIntroAnimState[4] = 1;
    case 2:
        func_ov011_02222830(entry, 2, 3, 2, (u16)EaseInterpolate(0, 16, 0, M2C_FIELD(entry, u16 *, 0x34), 0x154));
        return;
    case 5:
        G3_SetSpriteTransformScale(entry, 0, 2);
        G3_SetSpriteTransformScale(entry, 0, 3);
        return;
    }
}

