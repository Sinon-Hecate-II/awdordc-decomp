/* 30 functions from 0x021717FC to 0x021724C0 (ov001), found by ds-decomp. */
#include "common.h"
void Ov001_FreeSpriteObjects(void);
extern s32 data_ov001_02193d14;
extern u8 data_ov001_021900e4[];
extern u8 *data_ov001_02190094[];
extern void *data_ov001_02193d18;
extern const u8 data_ov001_0218f30c[];
void func_ov001_02172418(s32);
s32 Ov001_AddTask(s32,void (*)(s32),s32,s32);
extern s32 gOv001ChoiceFrameSprites;
extern s8 gOv001MessagePanelActive;
extern u8 data_ov001_02193cd0[64];
extern const u8 data_ov001_0218f2f8[8];

void Ov001_IconRow_SlideOut(s32 a){
extern void *gOv001IconRow;
void Ov001_IconRow_IntroStep(s32);
void Ov001_GetSpritePosition(s32,s32,s32 *,s32 *);
void Ov001_IconRow_Layout(s32);
s32 pos[2];
Ov001_GetSpritePosition(M2C_FIELD(gOv001IconRow,s32 *,8),0,&pos[1],&pos[0]);
pos[0]-=4;Ov001_IconRow_Layout(pos[0]);
if(pos[0]>168)return;
Ov001_IconRow_Layout(168);Ov001_SetSlideStep(a,(M2C_UNK *)Ov001_IconRow_IntroStep);
}

void Ov001_IconRow_IntroStep(M2C_UNK arg0) {
    M2C_UNK Ov001_SetSlideStep(M2C_UNK, M2C_UNK *);
    extern void *gOv001IconRow;
    extern M2C_UNK Ov001_HandleIconRowTouch;
    M2C_FIELD(gOv001IconRow, s8 *, 0x16) = -1;
    M2C_FIELD(gOv001IconRow, u16 *, 0x14) = (u16) (M2C_FIELD(gOv001IconRow, u16 *, 0x14) + 1);
    if ((u32) M2C_FIELD(gOv001IconRow, u16 *, 0x14) < 4U) {
        return;
    }
    M2C_FIELD(gOv001IconRow, u16 *, 0x14) = 0U;
    Ov001_SetSlideStep(arg0, &Ov001_HandleIconRowTouch);
}

/* Handles a tap on the shared ov001 icon row: finds the touched bar, switches
 * it to its selected layout, moves it into place, and starts the timer that
 * restores the row after a moment. */
void Ov001_HandleIconRowTouch(void) {
    extern void *gOv001IconRow;
    extern const u8 gOv001IconRowCount[], gOv001IconRowSlot[][2], gOv001IconRowSize[], gOv001IconRowLayout[][2];
    extern const u16 gOv001IconRowX[], gOv001IconRowY[];
    void BuildTouchRect(const void *, const void *, void *);
    s32 TouchRectPressed(void *);
    void Ov001_MoveSpriteLayout(s32, s32, s32, s32);
    s32 Ov001_GetSpriteObjEntry(s32, s32);
    void Ov001_LoadSpriteObjLayout(s32, s32, s32);
    void Ov001_SetSpritePalette(s32, s32, s32);
    void Ov001_EndIconRowSelection(s32);
    s32 count, i, slot;
    u8 point[8];

    count = gOv001IconRowCount[((Ov001IconRow *)gOv001IconRow)->page];
    if (((Ov001IconRow *)gOv001IconRow)->inputLocked == 0) {
        if (((Ov001IconRow *)gOv001IconRow)->selected != -1) return;
        for (i = 0; i < count; i++) {
            BuildTouchRect((const u8 *)gOv001IconRowX + gOv001IconRowSlot[((Ov001IconRow *)gOv001IconRow)->page][i] * 4, gOv001IconRowSize, point);
            if (TouchRectPressed(point)) {
                if (((Ov001IconRow *)gOv001IconRow)->selectTimer) break;
                slot = gOv001IconRowLayout[((Ov001IconRow *)gOv001IconRow)->page][i];
                Ov001_LoadSpriteObjLayout(0, slot + 1, Ov001_GetSpriteObjEntry(((Ov001IconRow *)gOv001IconRow)->bars[i], 0));
                slot = gOv001IconRowSlot[((Ov001IconRow *)gOv001IconRow)->page][i];
                Ov001_MoveSpriteLayout(((Ov001IconRow *)gOv001IconRow)->bars[i], -1,
                    *(const u16 *)((const u8 *)gOv001IconRowX + slot * 4),
                    *(const u16 *)((const u8 *)gOv001IconRowY + slot * 4));
                Ov001_SetSpritePalette(((Ov001IconRow *)gOv001IconRow)->bars[i], -1, 1);
                ((Ov001IconRow *)gOv001IconRow)->selectTimer = Ov001_AddTask(0, Ov001_EndIconRowSelection, 0, 110);
                ((Ov001IconRow *)gOv001IconRow)->selected = i;
                return;
            }
        }
    }
    ((Ov001IconRow *)gOv001IconRow)->selected = -1;
}

void func_ov001_02171a44(s32 a){
extern void *gOv001IconRow;
void func_ov001_02171aa8(s32);
s32 pos[2];
Ov001_GetSpritePosition(M2C_FIELD(gOv001IconRow,s32 *,8),0,&pos[1],&pos[0]);
pos[0]+=4;Ov001_IconRow_Layout(pos[0]);
if(pos[0]<192)return;
Ov001_SetSlideStep(a,(M2C_UNK *)func_ov001_02171aa8);
}

#pragma optimize_for_size on
void func_ov001_02171aa8(s32 a){
extern void *gOv001IconRow;
void Ov001_PostTaskMessage(s32,s32);
void Ov001_DestroySprite(s32);
s32 i;
Ov001_PostTaskMessage(0,a);
if(M2C_FIELD(gOv001IconRow,s32 *,16))Ov001_PostTaskMessage(0,M2C_FIELD(gOv001IconRow,s32 *,16));
for(i=0;i<2;i++)if(((s32 *)gOv001IconRow)[i])Ov001_DestroySprite(((s32 *)gOv001IconRow)[i]);
Ov001_DestroySprite(M2C_FIELD(gOv001IconRow,s32 *,8));
Ov001_FreeAlloc(&gOv001IconRow);
}
#pragma optimize_for_size reset
/* Frame handler of a touch on the shared ov001 icon row: after 16 frames it
 * restores the page's bar sprites to their unselected layouts, slides the row
 * back out, clears the selection and, if a task was waiting on it, posts the
 * selection result back to that task. */
void Ov001_EndIconRowSelection(s32 message){
extern void *gOv001IconRow;extern const u8 gOv001IconRowCount[],gOv001IconRowLayout[][2];
s32 Ov001_GetSpriteObjEntry(s32,s32);void Ov001_LoadSpriteObjLayout(s32,s32,s32);void Ov001_SetSpritePalette(s32,s32,s32);
void Ov001_PostTaskMessage(s32,s32);void Ov001_IconRow_SlideOut(s32);
s32 n,i,slot;
M2C_FIELD(gOv001IconRow,u16 *,20)++;
if(M2C_FIELD(gOv001IconRow,u16 *,20)<16U)return;
n=gOv001IconRowCount[M2C_FIELD(gOv001IconRow,u8 *,23)];
for(i=0;i<n;i++){
slot=gOv001IconRowLayout[M2C_FIELD(gOv001IconRow,u8 *,23)][i];
Ov001_LoadSpriteObjLayout(0,slot,Ov001_GetSpriteObjEntry(((s32*)gOv001IconRow)[i],0));
Ov001_SetSpritePalette(((s32*)gOv001IconRow)[i],-1,1);
}
Ov001_IconRow_Layout(168);
M2C_FIELD(gOv001IconRow,u16 *,20)=0;
M2C_FIELD(gOv001IconRow,s8 *,22)=-1;
if(M2C_FIELD(gOv001IconRow,s32 *,16)){M2C_FIELD(gOv001IconRow,s32 *,16)=0;Ov001_PostTaskMessage(0,message);}
}

void func_ov001_02171c10(void) {
    extern s8 gOv001MessagePanelActive;
    gOv001MessagePanelActive = 0;
}

/* Show the one-shot ov001 message panel for `messageId`, filling `value` and
 * `index` into its text, unless one is already on screen.  Returns 1 when the
 * panel was built, 0 when it was already showing. */
s32 Ov001_ShowMessagePanel(s32 messageId,s32 value,s32 index){
extern u8 data_ov001_0218feb0[];extern s32 gOv001MessageArchive;void func_0200436c(s32,s32,s32);
void Ov001_LoadAsset(u8 *,void (*)(s32,s32,s32));s32 CreateTextPanel(s32,s32);s32 func_ov001_02175f60(s32,s32,s32,s32);s32 func_ov001_02171f88(void);s32 DrawPanelText(s32,s32,s32,s32,s32,s32,s32,s32);s32 CloseTextPanel(s32);
s32 panel,text;
if(*(u8 *)&gOv001MessagePanelActive)return 0;
Ov001_LoadAsset(data_ov001_0218feb0,func_0200436c);
*(volatile u32 *)0x4001010=0x1920000;
panel=CreateTextPanel(1,0);text=func_ov001_02175f60(gOv001MessageArchive,messageId,value,index);
DrawPanelText(panel,20,0,216,64,2,func_ov001_02171f88(),text);CloseTextPanel(panel);
gOv001MessagePanelActive=1;return 1;
}

s32 Ov001_FreeOptionBackground(void) {
 void func_ov001_0218af70(s32);
 if((u8)gOv001MessagePanelActive==0) return 0;
 func_ov001_0218af70(1);
 gOv001MessagePanelActive=0;
 return 1;
}

void *Ov001_LocalizePath(u8 *arg0) {
 void StringCopyPad(void *,void *,s32);
 s32 Ov001_GetLanguage(s32);
 s32 value;
 StringCopyPad(data_ov001_02193cd0,arg0,63);
 if(arg0[5]==120) return data_ov001_02193cd0;
 value=Ov001_GetLanguage(arg0[5]);
 if(arg0[5]==121 && value!=0) return data_ov001_02193cd0;
 data_ov001_02193cd0[5]=data_ov001_0218f2f8[value];
 return data_ov001_02193cd0;
}

void Ov001_LoadAsset(u8 *arg0,void (*arg1)(s32,s32,s32)) {
 void DC_FlushRange(s32,s32);
 s32 Ov001_LoadFile(void *,s32 *,s32);
 void Ov001_FreeFile(s32);
 s32 size;
 s32 p=Ov001_LoadFile(Ov001_LocalizePath(arg0),&size,4);
 DC_FlushRange(p,size);
 arg1(p,0,size);
 Ov001_FreeFile(p);
}

void func_ov001_02171dd0(s32 a){
s32 x;func_ov001_02175d78(&x,0);
if(x==1){Ov001_OpenMenu(a);return;}
if(x==2)Ov001_LoadMenuRows(a);
}

void func_ov001_02171e20(M2C_UNK arg0) {
    M2C_UNK func_ov001_0217159c(M2C_UNK);
    M2C_UNK func_ov001_02175d78(M2C_UNK, s32 *);
    s32 sp0;

    func_ov001_02175d78(0, &sp0);
    if (sp0 != 1) {
        return;
    }
    func_ov001_0217159c(arg0);
}

void func_ov001_02171e58(M2C_UNK arg0) {
    s32 func_ov001_02171f88();
    s32 func_ov001_02175f48(s32, M2C_UNK);
    s32 CreateTextPanel(M2C_UNK, M2C_UNK);
    M2C_UNK DrawPanelText(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32);
    M2C_UNK CloseTextPanel(s32);
    extern s32 gOv001MessageArchive;
    s32 temp_r4;
    s32 temp_r5;

    temp_r5 = CreateTextPanel(0, 0);
    temp_r4 = func_ov001_02175f48(gOv001MessageArchive, arg0);
    DrawPanelText(temp_r5, 0xD, 0x28, 0xE6, 0x70, 2, func_ov001_02171f88(), temp_r4);
    CloseTextPanel(temp_r5);
}

void func_ov001_02171ecc(s32 a,s32 b){
extern s32 gOv001MessageArchive;
s32 Ov001_GetLanguage(s32);
extern u16 data_ov001_0218f2de[],data_ov001_0218f2dc[];

void func_ov001_0218af94(s32,s32,s32,s32,s32,s32);
s32 p,t,x,y;
p=CreateTextPanel(0,0);t=func_ov001_02175f48(gOv001MessageArchive,b);
DrawPanelText(p,13,60,230,94,2,func_ov001_02171f88(),t);
x=((s32 (*)(void))Ov001_GetLanguage)();y=((s32 (*)(void))Ov001_GetLanguage)();
func_ov001_0218af94(p,data_ov001_0218f2dc[x*2],data_ov001_0218f2de[y*2],2,0x209,a);
CloseTextPanel(p);
}

s32 func_ov001_02171f88(void) {
    s32 Ov001_GetLanguage(s32);
    extern s32 data_ov001_0218f2c0[];
    s32 index = ((s32 (*)(void))Ov001_GetLanguage)();
    return data_ov001_0218f2c0[index];
}

void func_ov001_02171fa0(void) {
 s32 Ov001_Alloc(s32,s32);
 gOv001ChoiceFrameSprites=Ov001_Alloc(16,4);
}

void func_ov001_02171fc0(void) {
    void Ov001_FreeSpriteObjects();
    extern M2C_UNK gOv001ChoiceFrameSprites;
    Ov001_FreeSpriteObjects();
    Ov001_FreeAlloc(&gOv001ChoiceFrameSprites);
}

void func_ov001_02171fd8(s32 a,s32 b,s32 c,s32 d){
extern u8 data_ov001_0218f300[];
extern s32 gOv001ChoiceFrameSprites;
s32 Ov001_CreateSprite(s32,s32,s32);
void Ov001_SetSpritePalette(s32,s32,s32);
void Ov001_MoveSpriteLayout(s32,s32,s32,s32);
s32 i;u8 *p;
Ov001_FreeSpriteObjects();
p=&data_ov001_0218f300[a*2];
for(i=0;i<2;i++){
((s32 *)gOv001ChoiceFrameSprites)[i]=Ov001_CreateSprite(0,*p++,1);
Ov001_SetSpritePalette(((s32 *)gOv001ChoiceFrameSprites)[i],-1,1);
}
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[0],-1,b,d);
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[1],-1,c,d);
}

/* Rebuilds the four sprites of the ov001 choice frame (corner pieces 7..10:
 * top-left, top-right, bottom-left, bottom-right) and places them at the given
 * left, right, top and bottom edges. */
void Ov001_LayoutChoiceFrame(s32 left,s32 right,s32 top,s32 bottom){
extern s32 gOv001ChoiceFrameSprites;
s32 Ov001_CreateSprite(s32,s32,s32);void Ov001_SetSpritePalette(s32,s32,s32);void Ov001_MoveSpriteLayout(s32,s32,s32,s32);
s32 j=6,i;Ov001_FreeSpriteObjects();
for(i=0;i<4;i++,j++){
((s32 *)gOv001ChoiceFrameSprites)[i]=Ov001_CreateSprite(0,j,1);
Ov001_SetSpritePalette(((s32 *)gOv001ChoiceFrameSprites)[i],-1,1);
}
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[0],-1,left,top);
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[1],-1,right,top);
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[2],-1,left,bottom);
Ov001_MoveSpriteLayout(((s32 *)gOv001ChoiceFrameSprites)[3],-1,right,bottom);
}

void Ov001_FreeSpriteObjects(void) {
 void Ov001_DestroySprite(s32);
 extern s32 gOv001ChoiceFrameSprites;
 s32 i,v;
 for(i=0;i<4;i++){
 v=((s32*)gOv001ChoiceFrameSprites)[i];
 if(v){Ov001_DestroySprite(v);((s32*)gOv001ChoiceFrameSprites)[i]=0;}
 }
}

void func_ov001_021721c4(void) {
 void func_0200460c(s32,s32,s32);
 void func_020043cc(s32,s32,s32);
 s32 Ov001_GetScreenLayout(void);
 data_ov001_02193d14=Ov001_Alloc(192,4);
 Ov001_LoadAsset(data_ov001_021900e4,func_0200460c);
 switch(Ov001_GetScreenLayout()) {
 case 0: Ov001_LoadAsset(data_ov001_02190094[0],func_020043cc); return;
 case 1: Ov001_LoadAsset(data_ov001_02190094[1],func_020043cc); return;
 }
}

void func_ov001_0217223c(void) {
    M2C_UNK Ov001_FreeAlloc(M2C_UNK *);
    extern M2C_UNK data_ov001_02193d14;
    Ov001_FreeAlloc(&data_ov001_02193d14);
}

void func_ov001_021722dc(s32);
M2C_UNK func_ov001_02172250(s32 a) {
 void MI_CpuCopy32(s32,s32,s32);
 s32 p=Ov001_LoadFile(Ov001_LocalizePath(data_ov001_02190094[a]),0,4);
 MI_CpuCopy32(p,data_ov001_02193d14,192);
 Ov001_FreeFile(p);
 Ov001_AddTask(1,func_ov001_021722dc,0,120);
}

void func_ov001_021722ac(void) {
    M2C_UNK func_ov001_02172250(s32);
    void *GetCurrentMapRecord();
    func_ov001_02172250(M2C_FIELD(GetCurrentMapRecord(), u8 *, 0xF4) + 5);
}

void func_ov001_021722c4(void) {
    func_ov001_02172250(M2C_FIELD(GetCurrentMapRecord(), u8 *, 0xF4) + 2);
}

void func_ov001_021722dc(s32 a) {
 void func_020043cc(s32,s32,s32);
 void Ov001_PostTaskMessage(s32,s32);
 DC_FlushRange(data_ov001_02193d14,192);
 func_020043cc(data_ov001_02193d14,0,192);
 Ov001_PostTaskMessage(1,a);
}

void func_ov001_0217231c(s8 a) {
 s32 *func_ov001_0218a5f0(s32,u8);
 s32 *p;
 s32 *q;
 void *v;
 if(data_ov001_02193d18!=NULL) return;
 v=(void *)Ov001_Alloc(12,4);
 data_ov001_02193d18=v;
 M2C_FIELD(v,s8 *,8)=a;
 M2C_FIELD(data_ov001_02193d18,s32 **,0)=func_ov001_0218a5f0(0,data_ov001_0218f30c[a*4]);
 p=M2C_FIELD(data_ov001_02193d18,s32 **,0);
 *p=(*p&0xFE00FF00)|0xE50026;
 q=M2C_FIELD(data_ov001_02193d18,s32 **,0);
 M2C_FIELD(q,u16 *,4)=(M2C_FIELD(q,u16 *,4)&~0xC00)|0x800;
 M2C_FIELD(data_ov001_02193d18,s32 *,4)=Ov001_AddTask(0,func_ov001_02172418,0,120);
}

void func_ov001_021723d4(void) {
 void func_ov001_0218c94c(s32,s32);
 void Ov001_ReleaseSprite(s32);
 if(data_ov001_02193d18==NULL) return;
 func_ov001_0218c94c(0,M2C_FIELD(data_ov001_02193d18,s32 *,4));
 Ov001_ReleaseSprite(M2C_FIELD(data_ov001_02193d18,s32 *,0));
 Ov001_FreeAlloc((M2C_UNK *)&data_ov001_02193d18);
}

void func_ov001_02172418(s32 a) {
 s32 func_02011d58(void);
 s32 func_02011d78(void);
 void Ov001_LoadSpriteObjLayout(s32,s32,s32);
 volatile u16 *ime=(volatile u16 *)0x4000208;
 u16 old=*ime;
 s32 offset=0;
 s32 *p; s32 *q;
 *ime=0;
 if(func_02011d58()!=0x8000) offset=func_02011d78();
 (void)*ime;
 *ime=old;
 Ov001_LoadSpriteObjLayout(0,(data_ov001_0218f30c+M2C_FIELD(data_ov001_02193d18,s8 *,8)*4)[offset],M2C_FIELD(data_ov001_02193d18,s32 *,0));
 p=M2C_FIELD(data_ov001_02193d18,s32 **,0);
 *p=(*p&0xFE00FF00)|0xE50026;
 q=M2C_FIELD(data_ov001_02193d18,s32 **,0);
 M2C_FIELD(q,u16 *,4)=(M2C_FIELD(q,u16 *,4)&~0xC00)|0x800;
}

