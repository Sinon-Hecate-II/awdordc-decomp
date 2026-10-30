/* 5 functions from 0x02223CB8 to 0x02224B9C (ov011), found by ds-decomp. */
#include "common.h"
typedef struct {u8 bytes[25];} IntroColors_022242dc;
extern const IntroColors_022242dc data_ov011_02227f64;
extern u8 data_02101f5c[],data_02101f0c[];
void func_ov011_022231f8(void *,u8,s16,u16,void *);
void func_ov011_02223764(void *,s16,u8,void *);
void G3_SubmitSpriteQuad(void *,int,int,s16,s16);
int func_020e31e0(void);
int func_0207ca38(int,int,int,u16,int);
void func_0208ffe4(int,int,int);
void func_ov011_02224b9c(void *,int);
void func_ov011_02224aac(void *,int);
void func_ov011_0222491c(void *);
int func_0208fe30(int);
int func_02090034(int,int);
void func_01ffac9c(int,int,int,void *,int);
extern u16 data_ov011_02228ce0[6];

/* Handles an entry's per-frame update across both screen buffers for states 2 and 3. */
s32 func_ov011_02223cb8() {
    return 0;
}

/* Updates intro sequence states and effects */
void func_ov011_022242dc(void *p) {
 IntroColors_022242dc colors = data_ov011_02227f64;
 u8 mode;
 u16 time;
 switch (M2C_FIELD(p, u8 *, 0x39)) {
 case 0:
  func_ov011_022231f8(p, 1, 0x7fff, 0x8052, colors.bytes);
  break;
 case 1:
  func_ov011_022231f8(p, 1, 0x7ff, 0x8052, colors.bytes);
  break;
 case 2:
  if (M2C_FIELD(p, u16 *, 0x34) == 3) func_0208ffe4(0, -1, 300);
  func_ov011_02224aac(p, 2);
  break;
 case 3:
  if (M2C_FIELD(p, u16 *, 0x34) == 342) func_0208fe30(302);
  if (M2C_FIELD(p, u16 *, 0x34) == 343) func_02090034(0, 96);
  break;
 case 4:
  if (func_020e31e0() == 5 || func_020e31e0() == 4) func_ov011_022231f8(p, 5, 108, 128, colors.bytes + 20);
  else func_ov011_022231f8(p, 5, 108, 128, colors.bytes + 5);
  G3_SubmitSpriteQuad(p, 2, 3, 128, (s16)(32 + func_0207ca38(0, 0, 64, M2C_FIELD(p, u16 *, 0x34), 796)));
  break;
 case 5:
  if ((int)M2C_FIELD(p, u16 *, 0x34) - 650 > 20) {
   if (func_020e31e0() == 5 || func_020e31e0() == 4) func_ov011_02223764(p, -108, 5, colors.bytes + 20);
   else func_ov011_02223764(p, -108, 5, colors.bytes + 5);
  } else {
   if (func_020e31e0() == 5 || func_020e31e0() == 4) func_ov011_022231f8(p, 5, 0x7fff, 48, colors.bytes + 20);
   else func_ov011_022231f8(p, 5, 0x7fff, 48, colors.bytes + 5);
  }
  G3_SubmitSpriteQuad(p, 2, 3, 128, (s16)(32 + func_0207ca38(0, 0, 64, M2C_FIELD(p, u16 *, 0x34), 796)));
  break;
 case 6:
  mode = func_020e31e0() == 4 ? 4 : 5;
  func_ov011_022231f8(p, mode, 108, 128, colors.bytes + 10);
  if ((int)M2C_FIELD(p, u16 *, 0x34) <= 618) {
   G3_SubmitSpriteQuad(p, 2, 2, (s16)(256 - func_0207ca38(0, 0, 128, M2C_FIELD(p, u16 *, 0x34), 618)), 96);
   G3_SubmitSpriteQuad(p, 2, 3, (s16)func_0207ca38(0, 0, -128, M2C_FIELD(p, u16 *, 0x34), 618), 96);
  }
  break;
 case 7:
  mode = func_020e31e0() == 4 ? 4 : 5;
  time = (u16)(M2C_FIELD(p, u16 *, 0x34) - 650);
  if (time == 0) { func_ov011_02224b9c(p, 4); func_0208ffe4(0, -1, 301); }
  if (time > 66) func_ov011_02223764(p, -98, mode, colors.bytes + 10);
  else if (time > 20) func_ov011_02224b9c(p, 3);
  func_ov011_022231f8(p, (u8)(mode | 128), 0x7fff, 128, colors.bytes + 10);
  break;
 case 8:
  if (func_020e31e0() == 2) func_ov011_022231f8(p, 130, 286, 0x8052, colors.bytes + 15);
  else if (M2C_FIELD(p, u16 *, 0x34) > 108 && M2C_FIELD(p, u16 *, 0x34) <= 168) {
   func_01ffac9c(0, 82, 0, data_02101f5c, 0);
   func_01ffac9c(128, 82, 32, data_02101f5c, 0);
   if (func_020e31e0() == 4) func_01ffac9c(0, 74, 128, data_02101f0c, 0);
  } else func_ov011_022231f8(p, 2, 108, 0x8052, colors.bytes + 15);
  break;
 case 9:
  func_ov011_022231f8(p, 130, 0x7fff, 0x8052, colors.bytes + 15);
  break;
 }
 func_ov011_0222491c(p);
 M2C_FIELD(p, u16 *, 0x34)++;
}

void func_ov011_022247f4(void *p){
void func_ov011_0222491c(void *);
extern const u16 data_ov011_02227f50[];
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
M2C_FIELD(p,u8 *,0x36)=0;func_01ffa8c4(p,4);
}return;
}
if(M2C_FIELD(p,u16 *,0x34)>=0x528){
M2C_FIELD(p,u8 *,0x38)=3;
M2C_FIELD(p,u8 *,0x39)=0;func_01ffa8c4(p,3);
}break;
case 3:
if(M2C_FIELD(p,u16 *,0x34)>data_ov011_02227f50[M2C_FIELD(p,u8 *,0x39)]){
if(M2C_FIELD(p,u8 *,0x39)>10){
if(M2C_FIELD(p,s32 *,0x3c)==2)func_01ffa8c4(p,4);
else func_01ffa8c4(p,2);
return;
}
func_01ffa6fc(p);return;
}break;
}
func_ov011_0222491c(p);
}

void func_ov011_0222491c(void *entry) {
    M2C_UNK func_01ffa8c4(void *, M2C_UNK);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_02090034(M2C_UNK, M2C_UNK);
    M2C_UNK func_020ac998(s32);
    M2C_UNK func_020aca8c(s32);
    extern u16 *data_02101e84;
    extern void *data_02101e88;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    s32 savedContext;
    s32 savedContext2;
    s32 screenIndex;
    s32 screenIndex2;
    s32 chosenContext;
    s32 chosenContext2;
    u16 keys;
    u8 state;

    keys = *data_02101e84;
    if (!(keys & 1) && !(keys & 8) && (M2C_FIELD(data_02101e88, u8 *, 0x14) == 0)) {
        return;
    }
    if ((M2C_FIELD(entry, s32 *, 0x3C) == 2) && !(keys & 8) && (M2C_FIELD(data_02101e88, u8 *, 0x14) == 0)) {
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
                chosenContext = data_027e00c8;
            } else {
                chosenContext = data_027e00c4;
            }
            gCur3DSpriteEngine = chosenContext;
            func_020ac998(0);
            screenIndex += 1;
        } while (screenIndex < 2);
        gCur3DSpriteEngine = savedContext;
        func_0208fe30(0x1000D);
        M2C_FIELD(entry, s8 *, 0x36) = 1;
        M2C_FIELD(entry, u8 *, 0x37) = 4U;
        return;
    case 3:
        screenIndex2 = 0;
        savedContext2 = gCur3DSpriteEngine;
        do {
            if (screenIndex2 == 0) {
                chosenContext2 = data_027e00c8;
            } else {
                chosenContext2 = data_027e00c4;
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
            func_01ffa8c4(entry, 4);
            return;
        }
        func_01ffa8c4(entry, 2);
        return;
    }
}

/* Configure an overlay entry's display state: set up sprite slots, refresh masks, or tear down depending on the command. */
void func_ov011_02224aac(void *entry, s32 command) {
    s32 func_0207ca38(s32, s32, s32, u16, s32);
    void func_ov011_022216d8(void *, s32, s32, s32);
    void func_ov011_02222830(void *, s32, s32, s32, s32);
    void func_ov011_02223b70(void *, s32, s32);
    switch (command) {
    case 0:
        func_ov011_022216d8(entry, 11, 0, 2);
        func_ov011_022216d8(entry, 12, 1, 2);
        func_ov011_022216d8(entry, 17, 0, 3);
        func_ov011_022216d8(entry, 18, 1, 3);
        data_ov011_02228ce0[4] = 1;
    case 2:
        func_ov011_02222830(entry, 2, 3, 2, (u16)func_0207ca38(0, 16, 0, M2C_FIELD(entry, u16 *, 0x34), 0x154));
        return;
    case 5:
        func_ov011_02223b70(entry, 0, 2);
        func_ov011_02223b70(entry, 0, 3);
        return;
    }
}

