/* 11 functions from 0x02216518 to 0x022174F4 (ov005), found by ds-decomp. */
#include "common.h"
#include "ov005_menu.h"
#include "ds3dsprite.h"



#pragma opt_common_subs off
#pragma opt_strength_reduction off
void func_ov005_02216518(u32 arg0){
extern u16 *gKeyState;
M2C_UNK PlaySoundEffect(s32);void LockInactiveSpriteSlots(void);void func_020b2268(void);void Sprite_ResumeAnimation(u32);
void RecordsMenu_HandlePick(s16);void RecordsMenu_SelectPrevious(s16);void RecordsMenu_SelectNext(s16);s32 RecordsMenu_IsRecordAvailable(s32);void RecordsMenu_ShuffleList(s32);void func_ov005_02214148(void);void func_ov005_022141cc(void);

extern M2C_UNK gRecordsMenuState;
extern void *g3DSpriteEngineMain,*g3DSpriteEngineSub,*gCur3DSpriteEngine;
extern M2C_UNK data_ov005_022204e0;
void func_ov005_02214b98(void); void func_ov005_02214cdc(void);
M2C_UNK func_02090248(s32);void RecordsMenu_SelectNextEnabled(s16);void RecordsMenu_SelectNextInList(s32);
void RecordsMenu_DrawList(s32);void Show3DSprite(void *);void Hide3DSprite(void *);
s32 func_020b2714(void);void func_020b2738(void);void func_020b26f8(void);
void LoadSpriteResource(s32,s32,u8,s32);s32 FindObjectByClass(void *);
void MenuSpriteUpdate(void *);
s32 mode; void *saved;
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x86)>0){s16 n; s32 alpha; s32 beta; void *saved; u16 * volatile reg;
M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x86)--; n=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x86);if(n>=8)n=16-n;alpha=16-2*n;beta=16-alpha;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
reg=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12);*reg=(*reg&~0xc0)|0x40;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=alpha;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=beta;
{void *state=M2C_FIELD(&gRecordsMenuState,void **,8);gCur3DSpriteEngine=saved;if(M2C_FIELD(state,s16 *,0x86)==8)func_ov005_02214b98();}}
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x88)>0){s16 n; s32 alpha; s32 beta; void *saved; u16 * volatile reg;
M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x88)--; n=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x88);if(n>=8)n=16-n;alpha=16-2*n;beta=16-alpha;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
reg=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12);*reg=(*reg&~0xc0)|0x40;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=alpha;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=beta;
{void *state=M2C_FIELD(&gRecordsMenuState,void **,8);gCur3DSpriteEngine=saved;if(M2C_FIELD(state,s16 *,0x88)==8)func_ov005_02214cdc();}}
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)!=-1){if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0xa0)>=0)M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0xa0)--;if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0xa0)==0x25b)func_02090248(600);if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0xa0)==0){s32 v=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e);switch(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x92)){case 0:break;case 1:RecordsMenu_SelectNextEnabled((s16)v);break;case 2:RecordsMenu_SelectNextInList(v);break;}}}
{void *p=M2C_FIELD(&gRecordsMenuState,void **,8);if(M2C_FIELD(p,s16 *,0x9e)==0){s32 goal=M2C_FIELD(p,s16 *,0x98);s32 current=M2C_FIELD(p,s16 *,0x96);if(current!=goal*2){s32 d=goal*2-current;s16 step;if(d<0)d=-d;step=d>>1;if(step==0)step=1;M2C_FIELD(p,s16 *,0x96)=current>goal*2?M2C_FIELD(p,s16 *,0x96)-step:M2C_FIELD(p,s16 *,0x96)+step;M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x9e)=1;RecordsMenu_DrawList(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x96));}}else M2C_FIELD(p,s16 *,0x9e)=0;}
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),u16 *,0)&1){u16 * volatile a=*(u16 **)gCur3DSpriteEngine;u16 * volatile b;*a=*a|0x20;b=*(u16 **)gCur3DSpriteEngine;*b=*b|0x40;Show3DSprite(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x174));Show3DSprite(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x178));if(func_020b2714())func_020b2738();}
else {u16 * volatile a=*(u16 **)gCur3DSpriteEngine;u16 * volatile b;*a=*a&~0x20;b=*(u16 **)gCur3DSpriteEngine;*b=*b&~0x40;Hide3DSprite(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x174));Hide3DSprite(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x178));if(!func_020b2714())func_020b26f8();}
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)!=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8c)){mode=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)==-1?2:48;saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;LoadSpriteResource(0,0,(u8)mode,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x3700);M2C_FIELD(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x180),s16 *,0x3e)=0x1b8;gCur3DSpriteEngine=saved;}
M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8c)=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e);
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x98)==0){void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x174);u32 frame=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+2;{M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u32)((u16)frame<<24)>>6);M2C_FIELD(p,u8 *,0x5a)=0;}}
else {void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x174);u32 frame=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28);{M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u32)((u16)frame<<24)>>6);M2C_FIELD(p,u8 *,0x5a)=0;}}

if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x98)==M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x9a)-6){void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x178);u32 frame=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+2;{M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u32)((u16)frame<<24)>>6);M2C_FIELD(p,u8 *,0x5a)=0;}}
else {void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x178);u32 frame=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28);{M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u32)((u16)frame<<24)>>6);M2C_FIELD(p,u8 *,0x5a)=0;}}

if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)!=-1 || FindObjectByClass(&data_ov005_022204e0)){{void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x184);u32 frame=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+2;if((u8)( (((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+2) != (u16)((M2C_FIELD(p,u32 *,0x40)<<6)>>24))){M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u32)((u16)frame<<24)>>6);M2C_FIELD(p,u8 *,0x5a)=0;}}
{void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x170);u32 frame=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28);if((u8)( (((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+2) != (u16)((M2C_FIELD(p,u32 *,0x40)<<6)>>24))==0){M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u32)((u16)frame<<24)>>6);M2C_FIELD(p,u8 *,0x5a)=0;}}
{void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x16c);u32 frame=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28);if((u8)( (((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+2) != (u16)((M2C_FIELD(p,u32 *,0x40)<<6)>>24))==0){M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u32)((u16)frame<<24)>>6);M2C_FIELD(p,u8 *,0x5a)=0;}}
}else {{void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x184);u32 frame=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28);if((u8)( (((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+2) != (u16)((M2C_FIELD(p,u32 *,0x40)<<6)>>24))==0){M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u32)((u16)frame<<24)>>6);M2C_FIELD(p,u8 *,0x5a)=0;}}
{void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x170);u32 frame=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+2;if((u8)( (((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+2) != (u16)((M2C_FIELD(p,u32 *,0x40)<<6)>>24))){M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u32)((u16)frame<<24)>>6);M2C_FIELD(p,u8 *,0x5a)=0;}}
{void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x16c);u32 frame=((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+2;if((u8)( (((u32)(M2C_FIELD(p,u8 *,0x59)<<28)>>28)+2) != (u16)((M2C_FIELD(p,u32 *,0x40)<<6)>>24))){M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0x3fc0000)|((u32)((u16)frame<<24)>>6);M2C_FIELD(p,u8 *,0x5a)=0;}}
}MenuSpriteUpdate(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x16c));
MenuSpriteUpdate(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x170));
MenuSpriteUpdate(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x174));
MenuSpriteUpdate(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x178));
MenuSpriteUpdate(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x17c));
MenuSpriteUpdate(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x180));
MenuSpriteUpdate(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x184));
if(M2C_FIELD(gKeyState,u16 *,0)&2){if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)!=-1){func_02090248(15);M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)=-1;RecordsMenu_DrawList(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x96));return;}if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x90)!=-1)return;PlaySoundEffect(0x1000f);LockInactiveSpriteSlots();func_020b2268();func_02090248(15);Sprite_ResumeAnimation(arg0);return;}
if(M2C_FIELD(gKeyState,u16 *,0)&4){if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),u16 *,0)&1)M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),u16 *,0)&=~1;else M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),u16 *,0)|=1;}
if(M2C_FIELD(gKeyState,u16 *,0)&1)RecordsMenu_HandlePick((s16)(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x98)+M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x94)));else {
void *state; u16 keys=M2C_FIELD(gKeyState,u16 *,0); arg0=0; state=M2C_FIELD(&gRecordsMenuState,void **,8);
if((keys&0x200)!=0&&((u8)((((u32)(M2C_FIELD(M2C_FIELD(state,void * *,0x170),u8 *,0x59)<<28)>>28)+2)!=(u16)((M2C_FIELD(M2C_FIELD(state,void * *,0x170),u32 *,0x40)<<6)>>24)))){s32 value=M2C_FIELD(state,s16 *,0x8e);if(value!=-1){arg0=1;PlaySoundEffect(0x10020);RecordsMenu_SelectPrevious((s16)value);}else{value=M2C_FIELD(state,s16 *,0x90);if(value!=-1){arg0=1;PlaySoundEffect(0x10020);RecordsMenu_SelectPrevious((s16)value);}}}
else if((keys&0x100)!=0&&((u8)((((u32)(M2C_FIELD(M2C_FIELD(state,void * *,0x16c),u8 *,0x59)<<28)>>28)+2)!=(u16)((M2C_FIELD(M2C_FIELD(state,void * *,0x16c),u32 *,0x40)<<6)>>24)))){s32 value=M2C_FIELD(state,s16 *,0x8e);if(value!=-1){arg0=1;PlaySoundEffect(0x10020);RecordsMenu_SelectNext((s16)value);}else{value=M2C_FIELD(state,s16 *,0x90);if(value!=-1){arg0=1;PlaySoundEffect(0x10020);RecordsMenu_SelectNext((s16)value);}}}
{void *state=M2C_FIELD(&gRecordsMenuState,void **,8);s32 selected=M2C_FIELD(state,s16 *,0x90);s32 row=M2C_FIELD(state,s16 *,0x98);s32 total=row+M2C_FIELD(state,s16 *,0x94);if(selected!=-1 && arg0==1 && total!=selected){do{
if(total>selected){if(row>0)M2C_FIELD(state,s16 *,0x98)--;else M2C_FIELD(state,s16 *,0x94)--;}else if(total<selected){if(row>=M2C_FIELD(state,s16 *,0x9a)-6)M2C_FIELD(state,s16 *,0x94)++;else M2C_FIELD(state,s16 *,0x98)++;}
state=M2C_FIELD(&gRecordsMenuState,void **,8);row=M2C_FIELD(state,s16 *,0x98);total=row+M2C_FIELD(state,s16 *,0x94);selected=M2C_FIELD(state,s16 *,0x90);
}while(total!=selected);}}}

if((M2C_FIELD(gKeyState,u16 *,0)&0x400)&&((u8)((((u32)(M2C_FIELD(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x184),u8 *,0x59)<<28)>>28)+2)!=(u16)((M2C_FIELD(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x184),u32 *,0x40)<<6)>>24)))){M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x92)++;if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x92)>=3)M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x92)=0;switch(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x92)){case 0:mode=0x31;break;case 1:mode=0x34;break;case 2:mode=0x32;break;}
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;LoadSpriteResource(0,0,(u8)mode,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x3900);M2C_FIELD(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x184),s16 *,0x3e)=0x1c8;gCur3DSpriteEngine=saved;PlaySoundEffect(0x10011);}
if(!(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),u16 *,0)&1))return;
if(M2C_FIELD(gKeyState,u16 *,0)&0x800){s32 index=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x98)+M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x94);if(RecordsMenu_IsRecordAvailable(index)){u8 *marks=(u8 *)M2C_FIELD(&gRecordsMenuState,void **,8)+0xa2;
marks[index]=!marks[index];RecordsMenu_DrawList(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x96));RecordsMenu_ShuffleList(-1);}}
{void *state=M2C_FIELD(&gRecordsMenuState,void **,8);
{void *p=M2C_FIELD(state,void * *,0x174);void *anim=M2C_FIELD(p,void **,0x64);u8 done=1;if(M2C_FIELD(anim,s8 *,0xb)!=1 && (!((u32)(M2C_FIELD(p,u8 *,0x59)<<27)>>31) || M2C_FIELD(anim,s8 *,0xc)!=1))done=0;if(done & 0xff){func_ov005_02214148();return;}}
{void *p=M2C_FIELD(state,void * *,0x178);void *anim=M2C_FIELD(p,void **,0x64);u8 done=1;if(M2C_FIELD(anim,s8 *,0xb)!=1 && (!((u32)(M2C_FIELD(p,u8 *,0x59)<<27)>>31) || M2C_FIELD(anim,s8 *,0xc)!=1))done=0;if(done & 0xff)func_ov005_022141cc();}
}
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
void func_ov005_0221720c(void) {
s32 func_020b2714(void);
void func_020b2738(void);
void func_020842d4(void);
void HideAllSpriteSlots(void);
void HeapFreeBlock(void *);
void FreeUiGraphicsBank(s32);
void func_02082014(void);
void StartMusicTrack(s32);
extern M2C_UNK gRecordsMenuState;
if (func_020b2714()) func_020b2738();
func_020842d4();
HideAllSpriteSlots();
if (M2C_FIELD(&gRecordsMenuState, void **, 8)) {
HeapFreeBlock(M2C_FIELD(&gRecordsMenuState, void **, 8));
M2C_FIELD(&gRecordsMenuState, void **, 8) = 0;
}
FreeUiGraphicsBank(7);
func_02082014();
StartMusicTrack(4);
}

void func_ov005_02217264(M2C_UNK arg0) {
    M2C_UNK CreateSpriteObject(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov005_02220510;
    CreateSpriteObject(&data_ov005_02220510, arg0);
}

void func_ov005_0221727c(void) {
    M2C_UNK func_02090248(M2C_UNK);
    extern M2C_UNK gRecordsMenuState;
    func_02090248(0xF);
    M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s16 *, 0x8E) = -1;
}

void func_ov005_022172a0(void) {
    void func_ov005_02214f80(s16);
    void RecordsMenu_AdvanceFadeRecord(u8);
    extern M2C_UNK gRecordsMenuState;
    s16 val = M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s16 *, 0x90);
    func_ov005_02214f80(val);
    M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s16 *, 0x90) = -1;
    RecordsMenu_AdvanceFadeRecord((u8) M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), u8 *, 0x8A));
}

void RecordsMenu_BeginAction(s16 arg0, s8 arg1) {
void CreateSpriteFromClass(void *, s32);
s32 func_ov005_02215650(void);
extern M2C_UNK gRecordsMenuState;
extern M2C_UNK data_ov005_022204e0;
M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s16 *, 0x90) = arg0;
M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s8 *, 0x8a) = arg1;
CreateSpriteFromClass(&data_ov005_022204e0, func_ov005_02215650());
}

void SetOv005FileDirectory(void) {
    M2C_UNK SetFileDirectory(M2C_UNK *);
    extern M2C_UNK data_ov005_022208e0;
    SetFileDirectory(&data_ov005_022208e0);
}

u8 func_ov005_02217320(void) {
    extern u8 *gOv005MenuState;
    return *gOv005MenuState;
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
/* Highlight entry `selection` of the detail row: its sprite shows the alternate
 * pose frame (base frame + 1), all the others their base frame. */
void Ov005SetDetailSelection(s16 selection) {
    extern u8 *gOv005MenuState;
    s32 i;
    void *sprite;
    u32 frame;
    u32 word;

    M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_SELECTION) = selection;
    for (i = 0; i < OV005_MENU_DETAIL_COUNT; i++) {
        if (i == selection) {
            sprite = M2C_FIELD(gOv005MenuState + i * 4, void **, OV005_MENU_DETAIL_SPRITES);
            frame = ((u32)(M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 28) >> 28) + 1;
            word = M2C_FIELD(sprite, u32 *, MENU_SPRITE_FRAME);
        } else {
            sprite = M2C_FIELD(gOv005MenuState + i * 4, void **, OV005_MENU_DETAIL_SPRITES);
            frame = ((u32)(M2C_FIELD(sprite, u8 *, MENU_SPRITE_BASE) << 28) >> 28);
            word = M2C_FIELD(sprite, u32 *, MENU_SPRITE_FRAME);
        }
        M2C_FIELD(sprite, u32 *, MENU_SPRITE_FRAME) = (word & ~MENU_SPRITE_FRAME_MASK) | ((u32)(((u16)frame) << 24) >> 6);
    }
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
/* Load the face palettes of the CO the detail list starts at
 * (OV005_MENU_BASE_INDEX): the info portrait into the main screen's OBJ
 * palette page after the base slot and the body portrait into the sub screen's
 * second BG palette slot. */
void Ov005LoadEntryFacePalettes(void) {
    void LoadFacePaletteAt(s32, s32, s32, s32);
    void LoadFacePalette(s32, s32, s32, s32, u8);
    extern u8 *gOv005MenuState;
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern void *g3DSpriteEngineSub;
    void *savedEngine = gCur3DSpriteEngine;
    s32 coId = M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_BASE_INDEX);

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    LoadFacePaletteAt(coId, FACE_LAYOUT_INFO, (u16)(M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_BASE_INDEX) - 1), 0);
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    LoadFacePalette(coId, FACE_LAYOUT_BODY_N, 2, 0, 0);
    gCur3DSpriteEngine = savedEngine;
    SetOv005FileDirectory();
}

/* Loads the selected CO's name graphic from shogun_name.narc into the sub
 * screen's texture bank, or clears that bank while the CO is still locked. */
void Ov005RefreshNameGraphic(void) {
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    void SetShogunInfoFileDirectory();
    void *GetNameFileForFace(s32);
    s32 GetLocalizedFileName(M2C_UNK *);
    u32 IsCoUnlocked(s32);
    void SetOv005FileDirectory(void);
    extern u8 *gOv005MenuState;
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern M2C_UNK data_ov005_022208f4;
    void *nameFile;
    void *savedEngine;

    nameFile = GetNameFileForFace(M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_BASE_INDEX));
    savedEngine = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    if (IsCoUnlocked(M2C_FIELD(gOv005MenuState, s16 *, OV005_MENU_BASE_INDEX))) {
        SetShogunInfoFileDirectory();
        GetLocalizedFileName(&data_ov005_022208f4);
        OpenNarcArchive();
        LoadNarcFileDecompressed(GetLocalizedFileName(nameFile), M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x1C) + 0x2800);
        CloseNarcArchive();
        SetOv005FileDirectory();
    } else {
        MI_CpuFill32(0, M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x1C) + 0x2800, 0x800);
    }
    gCur3DSpriteEngine = savedEngine;
}

