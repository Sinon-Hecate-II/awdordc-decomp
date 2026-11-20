/* 12 functions from 0x0217332C to 0x0217416C (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { u8 v[5]; } SpriteGroupCounts;
typedef struct { s32 x; u32 y; } Position;


void Ov001_LayoutKeyboardRow(u8 arg0, s32 arg1, s32 arg2, u32 arg3);
void Ov001_SetKeyboardKeySelected(s32 arg0, s32 arg1);
s32 *Ov001_GetSpriteObjEntry(s32 arg0, s32 arg1);
void Ov001_SetSlideStep(void *arg0, void *arg1);
extern void *gOv001MenuState;
extern u8 data_ov001_0218f314[];
extern u8 data_ov001_0218f318[];
extern u8 gKeyboardCharKeyPos[];
void Ov001_KeyboardCloseStep4(void *arg0);
void Ov001_KeyboardCloseStep3(void *arg0);
void Ov001_KeyboardCloseStep2(void *arg0);
void Ov001_KeyboardCloseStep1(void *arg0);
void Ov001_KeyboardCloseDone(int arg0);

/* Handle the on-screen keyboard: move the cursor, emit the highlighted character or action and
 * switch between the lowercase, symbols and uppercase pages with X/Y. */
void Ov001_KeyboardInput(void) {
s32 KeyHeld(s32);s32 KeyPressed(s32);s32 KeyReleased(s32);
void Ov001_MoveMenuSelection(s32);void Ov001_SetKeyboardPage(s8);
void Ov001_ToggleKeyboardCase(void);void Ov001_ToggleKeyboardSymbols(void);void Ov001_PlaySound(s32);
extern u8 *gKeyboardCharTables[];
extern u8 gKeyboardSpecialChars[],gKeyboardActionChars[];
s32 selected;Ov001KeyboardState *p;
if(KeyHeld(KEY_LEFT))Ov001_MoveMenuSelection(0);
if(KeyHeld(KEY_UP))Ov001_MoveMenuSelection(1);
if(KeyHeld(KEY_RIGHT))Ov001_MoveMenuSelection(2);
if(KeyHeld(KEY_DOWN))Ov001_MoveMenuSelection(3);
if(KeyPressed(KEY_A)){
p=(Ov001KeyboardState *)gOv001MenuState;
selected=p->selectedKey;
if(selected<47){
if(!p->canAdd){Ov001_PlaySound(9);return;}
p->key=gKeyboardCharTables[p->page][selected];
if(((Ov001KeyboardState *)gOv001MenuState)->page==1)Ov001_SetKeyboardPage(0);
return;
}
if(selected-47<4){
switch(selected-47){
case 0:Ov001_ToggleKeyboardCase();return;
case 1:Ov001_ToggleKeyboardSymbols();return;
case 2:if(!p->canAdd){Ov001_PlaySound(9);return;}break;
case 3:if(!p->canDelete){Ov001_PlaySound(9);return;}break;
}
if(p->page==1)Ov001_SetKeyboardPage(0);
((Ov001KeyboardState *)gOv001MenuState)->key=gKeyboardSpecialChars[selected-47];
return;
}
p->key=gKeyboardActionChars[selected-51];
}
if(KeyHeld(KEY_B)){
p=(Ov001KeyboardState *)gOv001MenuState;
if(!p->canDelete){
if(p->deleteBuzzed)return;
Ov001_PlaySound(9);
((Ov001KeyboardState *)gOv001MenuState)->deleteBuzzed=1;
return;
}
p->key=KBD_KEY_DELETE;
}else if(KeyReleased(KEY_B))((Ov001KeyboardState *)gOv001MenuState)->deleteBuzzed=0;
if(KeyPressed(KEY_X))Ov001_ToggleKeyboardCase();
if(KeyPressed(KEY_Y))Ov001_ToggleKeyboardSymbols();
}

#pragma scheduling off
#pragma optimization_level 3
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
void Ov001_LayoutKeyboardRow(u8 arg0,s32 arg1,s32 arg2,u32 arg3){
extern u8 data_ov001_0218f328[];
extern u16 gKeyboardAuxKeyPos[],gKeyboardActionKeyPos[];
void Ov001_DrawTextPanelToSprite(s32,u16,s32,s32,s32);
s32 HardwareDivideRemainder(s32,s32);
void Ov001_SetSpriteEntryFlags(void *,s32,s32,s32);
M2C_UNK Ov001_MoveSpriteLayout(s32,M2C_UNK,u16,u16);
SpriteGroupCounts a,b,c;
s32 index=arg1*12; s32 i,j;void *p;u16 tile;
a=*(SpriteGroupCounts *)(data_ov001_0218f328+17);
b=*(SpriteGroupCounts *)(data_ov001_0218f328+22);
c=*(SpriteGroupCounts *)(data_ov001_0218f328+12);
i=0;j=index;
for(i=0;i<a.v[arg1];i++){
tile=*(u16 *)(gKeyboardCharKeyPos+j*4);
p=M2C_FIELD((u8 *)gOv001MenuState+j*4,void **,0x30);
M2C_FIELD(p,u32 *,0)=M2C_FIELD(p,u32 *,0)&~0x3e000300U;
p=M2C_FIELD((u8 *)gOv001MenuState+j*4,void **,0x30);
M2C_FIELD(p,u32 *,0)=(M2C_FIELD(p,u32 *,0)&0xfe00ff00)|((u32)(tile<<23)>>7)|(arg2&255);
j++;
}
if(arg1<4)Ov001_DrawTextPanelToSprite(M2C_FIELD((u8 *)gOv001MenuState+arg0*16+arg1*4,s32 *,0),*(u16 *)(gKeyboardCharKeyPos+index*4),arg2,M2C_FIELD((u8 *)gOv001MenuState+arg1*4,s32 *,0x104),2);
j=HardwareDivideRemainder(arg1+3,4);
i=0;
if(i<b.v[arg1]){
j*=4;
tile=*(u16 *)((u8 *)gKeyboardAuxKeyPos+j);
do{
p=M2C_FIELD((u8 *)gOv001MenuState+j,void **,0xec);
M2C_FIELD(p,u32 *,0)&=0xc1fffcff;
p=M2C_FIELD((u8 *)gOv001MenuState+j,void **,0xec);
M2C_FIELD(p,u32 *,0)=(M2C_FIELD(p,u32 *,0)&0xfe00ff00)|((tile&0x1ff)<<16)|(arg2&255);
i++;
}while(i<b.v[arg1]);
}
i=0;
for(i=0;i<c.v[arg1];i++){
Ov001_SetSpriteEntryFlags(M2C_FIELD((u8 *)gOv001MenuState+i*4,void **,0xfc),-1,0,0);
Ov001_MoveSpriteLayout(M2C_FIELD((u8 *)gOv001MenuState+i*4,s32 *,0xfc),-1,gKeyboardActionKeyPos[i*2],arg2);
}
}
#pragma opt_strength_reduction off
/* Switch the on-screen keyboard to a page (0 lowercase, 1 symbols, 2 uppercase):
 * remember it, lay every key row out at that page's position-table entry and set
 * the case/symbols toggle keys to show whether their page is the one now shown. */
void Ov001_SetKeyboardPage(s8 page) {
s32 row,caseActive,symbolsActive,keyIndex;
caseActive=0;symbolsActive=0;row=0;keyIndex=0;
M2C_FIELD(gOv001MenuState,s8*,0x11d)=page;
do {
((void(*)(s8,s32,u16))Ov001_LayoutKeyboardRow)(page,row,M2C_FIELD(gKeyboardCharKeyPos+keyIndex*4,u16*,2));
row++;keyIndex+=12;
}while(row<4);
if(page==2)caseActive=1;else if(page==1)symbolsActive=1;
Ov001_SetKeyboardKeySelected(47,caseActive);Ov001_SetKeyboardKeySelected(48,symbolsActive);
}
#pragma scheduling off
#pragma opt_common_subs off
void Ov001_SetKeyboardKeySelected(s32 arg0,s32 arg1){
void Ov001_SetSpriteAttrs(void *,s32,s32,u8);
s32 i; void *p;
if(arg0<0)return;
if(arg0<0x2f){
p=M2C_FIELD(gOv001MenuState+arg0*4,void **,0x30);
arg1=data_ov001_0218f314[arg1];
M2C_FIELD(p,s32 *,0)&=~0xc00;
M2C_FIELD(p,u16 *,4)=(M2C_FIELD(p,u16 *,4)&~0xf000)|(arg1<<12);
return;
}
{
i=arg0-0x2f;
if(i<4){
p=M2C_FIELD(gOv001MenuState+i*4,void **,0xec);
arg0=data_ov001_0218f314[arg1];
M2C_FIELD(p,s32 *,0)&=~0xc00;
M2C_FIELD(p,u16 *,4)=(M2C_FIELD(p,u16 *,4)&~0xf000)|(arg0<<12);
return;
}}
Ov001_SetSpriteAttrs(M2C_FIELD(gOv001MenuState+(arg0-0x33)*4,s32 *,0xfc),-1,0,data_ov001_0218f318[arg1]);
}
#pragma scheduling reset
#pragma opt_common_subs reset
/* Refreshes the on-screen keyboard's selection cursor: loads the obj layout that
 * matches the selected key's kind, sets its palette and moves it onto that key's
 * position from the per-key position table. */
void Ov001_UpdateKeyboardCursor(void) {
    s32 *Ov001_GetSpriteObjEntry(s32, s32);
    M2C_UNK Ov001_MoveSpriteLayout(s32, M2C_UNK, u16, u16);
    M2C_UNK Ov001_SetSpritePalette(s32, M2C_UNK, M2C_UNK);
    M2C_UNK Ov001_LoadSpriteObjLayout(M2C_UNK, M2C_UNK, s32);
    extern void *gOv001MenuState;
    extern u16 gKeyboardKeyCursorPosX[];
    extern u16 gKeyboardKeyCursorPosY[];
    M2C_UNK layout;
    s32 keyIndex;

    switch (M2C_FIELD(gOv001MenuState, s8 *, 0x121) - 0x2F) {
    case 0:
        layout = 0x42;
        break;
    case 1:
        layout = 0x41;
        break;
    case 2:
        layout = 0x43;
        break;
    case 3:
        layout = 0x41;
        break;
    case 4:
    case 5:
        layout = 0x45;
        break;
    default:
        layout = 0x40;
        break;
    }
    Ov001_LoadSpriteObjLayout(0, layout, Ov001_GetSpriteObjEntry(M2C_FIELD(gOv001MenuState, s32 *, 0x114), 0));
    Ov001_SetSpritePalette(M2C_FIELD(gOv001MenuState, s32 *, 0x114), -1, 2);
    keyIndex = M2C_FIELD(gOv001MenuState, s8 *, 0x121) * 2;
    Ov001_MoveSpriteLayout(M2C_FIELD(gOv001MenuState, s32 *, 0x114), -1, gKeyboardKeyCursorPosX[keyIndex], gKeyboardKeyCursorPosY[keyIndex]);
}

/* Moves the ov001 menu cursor by `direction` (0..3) using the per-state
 * transition table, then repairs the remembered selection for the special action
 * entries and refreshes the cursor. */
void Ov001_MoveMenuSelection(s32 direction) {
extern s8 gOv001MenuTransitions[];
void Ov001_PlaySound(s32);
s32 fromState = M2C_FIELD(gOv001MenuState,s8 *,0x121);
void *state; s32 toState;
M2C_FIELD(gOv001MenuState,s8 *,0x121)=*(gOv001MenuTransitions+fromState*4+direction);
state=gOv001MenuState;toState=M2C_FIELD(state,s8 *,0x121);
if(toState==46 && direction==3) M2C_FIELD(state,s8 *,0x120)=fromState;
else if(toState==51 && (direction==1 || direction==3)) M2C_FIELD(state,s8 *,0x120)=fromState;
else if(toState==52 && (direction==1 || direction==3)) {if(fromState!=46) M2C_FIELD(state,s8 *,0x120)=fromState;}
else if(toState==-1) {if(M2C_FIELD(state,s8 *,0x120)==35 || M2C_FIELD(state,s8 *,0x120)==50) M2C_FIELD(state,s8 *,0x121)=35;else M2C_FIELD(state,s8 *,0x121)=34;}
else if(toState==-2) {switch(M2C_FIELD(state,s8 *,0x120)) {case 0:case 49:M2C_FIELD(state,s8 *,0x121)=49;break;case 1:case 36:M2C_FIELD(state,s8 *,0x121)=36;break;case 3:case 38:M2C_FIELD(state,s8 *,0x121)=38;break;case 4:case 39:M2C_FIELD(state,s8 *,0x121)=39;break;case 5:case 40:M2C_FIELD(state,s8 *,0x121)=40;break;default:M2C_FIELD(state,s8 *,0x121)=37;break;}}
else if(toState==-3) {switch(M2C_FIELD(state,s8 *,0x120)) {case 6:case 41:M2C_FIELD(state,s8 *,0x121)=41;break;case 7:case 42:M2C_FIELD(state,s8 *,0x121)=42;break;case 9:case 44:M2C_FIELD(state,s8 *,0x121)=44;break;case 10:case 45:M2C_FIELD(state,s8 *,0x121)=45;break;case 11:case 34:case 35:case 50:M2C_FIELD(state,s8 *,0x121)=46;break;default:M2C_FIELD(state,s8 *,0x121)=43;break;}}
else if(toState==-4) {switch(M2C_FIELD(state,s8 *,0x120)) {case 0:case 49:M2C_FIELD(state,s8 *,0x121)=0;break;case 1:case 36:M2C_FIELD(state,s8 *,0x121)=1;break;case 3:case 38:M2C_FIELD(state,s8 *,0x121)=3;break;case 4:case 39:M2C_FIELD(state,s8 *,0x121)=4;break;case 5:case 40:M2C_FIELD(state,s8 *,0x121)=5;break;default:M2C_FIELD(state,s8 *,0x121)=2;break;}}
else if(toState==-5) {switch(M2C_FIELD(state,s8 *,0x120)) {case 6:case 41:M2C_FIELD(state,s8 *,0x121)=6;break;case 7:case 42:M2C_FIELD(state,s8 *,0x121)=7;break;case 9:case 44:M2C_FIELD(state,s8 *,0x121)=9;break;case 10:case 45:M2C_FIELD(state,s8 *,0x121)=10;break;case 11:case 34:M2C_FIELD(state,s8 *,0x121)=11;break;case 35:case 50:M2C_FIELD(state,s8 *,0x121)=50;break;default:M2C_FIELD(state,s8 *,0x121)=8;break;}}
Ov001_UpdateKeyboardCursor();Ov001_PlaySound(8);}

/* Last row of the keyboard close animation: slides the bottom action row 12
 * pixels to the right each frame until it has left the screen, then hands the
 * slide task to the row above it. */
void Ov001_KeyboardCloseStep5(void *task) {
    Position pos;
    s32 bits;

    bits = *Ov001_GetSpriteObjEntry((s32)((Ov001KeyboardState *)gOv001MenuState)->actionKeys[0], 0);
    pos.x = (u8)bits + 0xC;
    pos.y = (u32)(bits & OV001_SPRITE_POS_Y_MASK) >> OV001_SPRITE_POS_Y_SHIFT;
    Ov001_LayoutKeyboardRow(((Ov001KeyboardState *)gOv001MenuState)->page, KBD_ROW_ACTION, pos.x, pos.y);
    if (*(volatile s32 *)&pos.x < KBD_ROW_HIDDEN_X) {
        return;
    }
    Ov001_SetSlideStep(task, &Ov001_KeyboardCloseStep4);
}

void Ov001_KeyboardCloseStep4(void *arg0) {
Position pos;
void *a=gOv001MenuState;
u32 bits=*M2C_FIELD(a,u32**,0xc0);
u8 b=M2C_FIELD(a,u8*,0x11d);
pos.y=(bits&0x1ff0000)>>16;pos.x=(u8)bits+12;
Ov001_LayoutKeyboardRow(b,3,pos.x,pos.y);
if(*(volatile s32 *)&pos.x<192)return;
Ov001_SetSlideStep(arg0,Ov001_KeyboardCloseStep3);
}

void Ov001_KeyboardCloseStep3(void *arg0) {
Position pos;
void *a=gOv001MenuState;
u32 bits=*M2C_FIELD(a,u32**,0x90);
u8 b=M2C_FIELD(a,u8*,0x11d);
pos.y=(bits&0x1ff0000)>>16;pos.x=(u8)bits+12;
Ov001_LayoutKeyboardRow(b,2,pos.x,pos.y);
if(*(volatile s32 *)&pos.x<192)return;
Ov001_SetSlideStep(arg0,Ov001_KeyboardCloseStep2);
}

#pragma opt_strength_reduction off
void Ov001_KeyboardCloseStep2(void *arg0) {
Position pos;
void *a=gOv001MenuState;
u32 bits=*M2C_FIELD(a,u32**,0x60);
u8 b=M2C_FIELD(a,u8*,0x11d);
pos.y=(bits&0x1ff0000)>>16;pos.x=(u8)bits+12;
Ov001_LayoutKeyboardRow(b,1,pos.x,pos.y);
if(*(volatile s32 *)&pos.x<192)return;
Ov001_SetSlideStep(arg0,Ov001_KeyboardCloseStep1);
}
#pragma opt_strength_reduction reset
void Ov001_KeyboardCloseStep1(void *arg0) {
    void Ov001_SetSlideStep(void *, void *);
    void Ov001_LayoutKeyboardRow(u8, s32, s32, u32);
    Position pos;
    void *a = gOv001MenuState;
    u32 bits = *M2C_FIELD(a, u32 **, 0x30);
    u8 b = M2C_FIELD(a, u8 *, 0x11d);
    pos.y = (bits & 0x01ff0000U) >> 16;
    pos.x = (u8)bits + 12;
    Ov001_LayoutKeyboardRow(b, 0, pos.x, pos.y);
    if (*(volatile s32 *)&pos.x < 0xc0) return;
    Ov001_SetSlideStep(arg0, &Ov001_KeyboardCloseDone);
}

void Ov001_KeyboardCloseDone(int arg0){
int i,j; unsigned int *ptr;
Ov001_PostTaskMessage(0,arg0);
for(i=0;i<3;i++){
for(j=0;j<4;j++){
ptr=(unsigned int *)gOv001MenuState;
func_ov001_0218ace0(((unsigned int (*)[4])ptr)[i][j]);
if(i==0)Ov001_DestroySprite(M2C_FIELD(gOv001MenuState+j*4,void **,0x104));
}}
for(i=0;i<2;i++)Ov001_DestroySprite(M2C_FIELD(gOv001MenuState+i*4,void **,0xfc));
for(i=0;i<4;i++)Ov001_ReleaseSprite(M2C_FIELD(gOv001MenuState+i*4,void **,0xec));
for(i=0; i!=0x2f; ++i)Ov001_ReleaseSprite(M2C_FIELD(gOv001MenuState+i*4,void **,0x30));
Ov001_FreeAlloc(&gOv001MenuState);
}

