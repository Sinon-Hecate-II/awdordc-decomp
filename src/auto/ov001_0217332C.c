/* 12 functions from 0x0217332C to 0x0217416C (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { u8 v[5]; } SpriteGroupCounts;
typedef struct { s32 x; u32 y; } Position;


void func_ov001_0217355c(u8 arg0, s32 arg1, s32 arg2, u32 arg3);
void func_ov001_0217385c(s32 arg0, s32 arg1);
s32 *func_ov001_0218a24c(s32 arg0, s32 arg1);
void func_ov001_0218c924(void *arg0, void *arg1);
extern void *gOv001MenuState;
extern u8 data_ov001_0218f314[];
extern u8 data_ov001_0218f318[];
extern u8 data_ov001_0218f36c[];
void func_ov001_02173ebc(void *arg0);
void func_ov001_02173f30(void *arg0);
void func_ov001_02173fa4(void *arg0);
void func_ov001_02174018(void *arg0);
void func_ov001_0217408c(int arg0);

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
void func_ov001_0217355c(u8 arg0,s32 arg1,s32 arg2,u32 arg3){
extern u8 data_ov001_0218f328[];
extern u16 data_ov001_0218f34c[],data_ov001_0218f344[];
void func_ov001_0218b200(s32,u16,s32,s32,s32);
s32 func_020020c4(s32,s32);
void func_ov001_0218a260(void *,s32,s32,s32);
M2C_UNK func_ov001_0218a384(s32,M2C_UNK,u16,u16);
SpriteGroupCounts a,b,c;
s32 index=arg1*12; s32 i,j;void *p;u16 tile;
a=*(SpriteGroupCounts *)(data_ov001_0218f328+17);
b=*(SpriteGroupCounts *)(data_ov001_0218f328+22);
c=*(SpriteGroupCounts *)(data_ov001_0218f328+12);
i=0;j=index;
for(i=0;i<a.v[arg1];i++){
tile=*(u16 *)(data_ov001_0218f36c+j*4);
p=M2C_FIELD((u8 *)gOv001MenuState+j*4,void **,0x30);
M2C_FIELD(p,u32 *,0)=M2C_FIELD(p,u32 *,0)&~0x3e000300U;
p=M2C_FIELD((u8 *)gOv001MenuState+j*4,void **,0x30);
M2C_FIELD(p,u32 *,0)=(M2C_FIELD(p,u32 *,0)&0xfe00ff00)|((u32)(tile<<23)>>7)|(arg2&255);
j++;
}
if(arg1<4)func_ov001_0218b200(M2C_FIELD((u8 *)gOv001MenuState+arg0*16+arg1*4,s32 *,0),*(u16 *)(data_ov001_0218f36c+index*4),arg2,M2C_FIELD((u8 *)gOv001MenuState+arg1*4,s32 *,0x104),2);
j=func_020020c4(arg1+3,4);
i=0;
if(i<b.v[arg1]){
j*=4;
tile=*(u16 *)((u8 *)data_ov001_0218f34c+j);
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
func_ov001_0218a260(M2C_FIELD((u8 *)gOv001MenuState+i*4,void **,0xfc),-1,0,0);
func_ov001_0218a384(M2C_FIELD((u8 *)gOv001MenuState+i*4,s32 *,0xfc),-1,data_ov001_0218f344[i*2],arg2);
}
}
#pragma opt_strength_reduction off
void Ov001_SetKeyboardPage(s8 arg0) {
s32 var_r4,var_r5,var_r6,var_r7;
var_r5=0;var_r6=0;var_r4=0;var_r7=0;
M2C_FIELD(gOv001MenuState,s8*,0x11d)=arg0;
do {
((void(*)(s8,s32,u16))func_ov001_0217355c)(arg0,var_r4,M2C_FIELD(data_ov001_0218f36c+var_r7*4,u16*,2));
var_r4++;var_r7+=12;
}while(var_r4<4);
if(arg0==2)var_r5=1;else if(arg0==1)var_r6=1;
func_ov001_0217385c(47,var_r5);func_ov001_0217385c(48,var_r6);
}
#pragma scheduling off
#pragma opt_common_subs off
void func_ov001_0217385c(s32 arg0,s32 arg1){
void func_ov001_0218a304(void *,s32,s32,u8);
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
func_ov001_0218a304(M2C_FIELD(gOv001MenuState+(arg0-0x33)*4,s32 *,0xfc),-1,0,data_ov001_0218f318[arg1]);
}
#pragma scheduling reset
#pragma opt_common_subs reset
void func_ov001_02173924(void) {
    s32 *func_ov001_0218a24c(s32, s32);
    M2C_UNK func_ov001_0218a384(s32, M2C_UNK, u16, u16);
    M2C_UNK func_ov001_0218a474(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a55c(M2C_UNK, M2C_UNK, s32);
    extern void *gOv001MenuState;
    extern u16 data_ov001_0218f428[];
    extern u16 data_ov001_0218f42a[];
    M2C_UNK var_r4;
    s32 temp_ip;

    switch (M2C_FIELD(gOv001MenuState, s8 *, 0x121) - 0x2F) {
    case 0:
        var_r4 = 0x42;
        break;
    case 1:
        var_r4 = 0x41;
        break;
    case 2:
        var_r4 = 0x43;
        break;
    case 3:
        var_r4 = 0x41;
        break;
    case 4:
    case 5:
        var_r4 = 0x45;
        break;
    default:
        var_r4 = 0x40;
        break;
    }
    func_ov001_0218a55c(0, var_r4, func_ov001_0218a24c(M2C_FIELD(gOv001MenuState, s32 *, 0x114), 0));
    func_ov001_0218a474(M2C_FIELD(gOv001MenuState, s32 *, 0x114), -1, 2);
    temp_ip = M2C_FIELD(gOv001MenuState, s8 *, 0x121) * 2;
    func_ov001_0218a384(M2C_FIELD(gOv001MenuState, s32 *, 0x114), -1, data_ov001_0218f428[temp_ip], data_ov001_0218f42a[temp_ip]);
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
func_ov001_02173924();Ov001_PlaySound(8);}

void func_ov001_02173e38(void *arg0) {
    typedef struct { s32 x; u32 y; } Position;
    extern void *gOv001MenuState;
    Position pos;
    s32 bits;

    bits = *func_ov001_0218a24c(M2C_FIELD(gOv001MenuState, s32 *, 0xFC), 0);
    pos.x = (u8)bits + 0xC;
    pos.y = (u32)(bits & 0x01FF0000) >> 0x10;
    func_ov001_0217355c(M2C_FIELD(gOv001MenuState, u8 *, 0x11D), 4, pos.x, pos.y);
    if (*(volatile s32 *)&pos.x < 0xC0) {
        return;
    }
    func_ov001_0218c924(arg0, &func_ov001_02173ebc);
}

void func_ov001_02173ebc(void *arg0) {
Position pos;
void *a=gOv001MenuState;
u32 bits=*M2C_FIELD(a,u32**,0xc0);
u8 b=M2C_FIELD(a,u8*,0x11d);
pos.y=(bits&0x1ff0000)>>16;pos.x=(u8)bits+12;
func_ov001_0217355c(b,3,pos.x,pos.y);
if(*(volatile s32 *)&pos.x<192)return;
func_ov001_0218c924(arg0,func_ov001_02173f30);
}

void func_ov001_02173f30(void *arg0) {
Position pos;
void *a=gOv001MenuState;
u32 bits=*M2C_FIELD(a,u32**,0x90);
u8 b=M2C_FIELD(a,u8*,0x11d);
pos.y=(bits&0x1ff0000)>>16;pos.x=(u8)bits+12;
func_ov001_0217355c(b,2,pos.x,pos.y);
if(*(volatile s32 *)&pos.x<192)return;
func_ov001_0218c924(arg0,func_ov001_02173fa4);
}

#pragma opt_strength_reduction off
void func_ov001_02173fa4(void *arg0) {
Position pos;
void *a=gOv001MenuState;
u32 bits=*M2C_FIELD(a,u32**,0x60);
u8 b=M2C_FIELD(a,u8*,0x11d);
pos.y=(bits&0x1ff0000)>>16;pos.x=(u8)bits+12;
func_ov001_0217355c(b,1,pos.x,pos.y);
if(*(volatile s32 *)&pos.x<192)return;
func_ov001_0218c924(arg0,func_ov001_02174018);
}
#pragma opt_strength_reduction reset
void func_ov001_02174018(void *arg0) {
    void func_ov001_0218c924(void *, void *);
    void func_ov001_0217355c(u8, s32, s32, u32);
    Position pos;
    void *a = gOv001MenuState;
    u32 bits = *M2C_FIELD(a, u32 **, 0x30);
    u8 b = M2C_FIELD(a, u8 *, 0x11d);
    pos.y = (bits & 0x01ff0000U) >> 16;
    pos.x = (u8)bits + 12;
    func_ov001_0217355c(b, 0, pos.x, pos.y);
    if (*(volatile s32 *)&pos.x < 0xc0) return;
    func_ov001_0218c924(arg0, &func_ov001_0217408c);
}

void func_ov001_0217408c(int arg0){
int i,j; unsigned int *ptr;
func_ov001_0218c92c(0,arg0);
for(i=0;i<3;i++){
for(j=0;j<4;j++){
ptr=(unsigned int *)gOv001MenuState;
func_ov001_0218ace0(((unsigned int (*)[4])ptr)[i][j]);
if(i==0)func_ov001_0218a1cc(M2C_FIELD(gOv001MenuState+j*4,void **,0x104));
}}
for(i=0;i<2;i++)func_ov001_0218a1cc(M2C_FIELD(gOv001MenuState+i*4,void **,0xfc));
for(i=0;i<4;i++)func_ov001_0218c104(M2C_FIELD(gOv001MenuState+i*4,void **,0xec));
for(i=0; i!=0x2f; ++i)func_ov001_0218c104(M2C_FIELD(gOv001MenuState+i*4,void **,0x30));
func_ov001_0218b71c(&gOv001MenuState);
}

