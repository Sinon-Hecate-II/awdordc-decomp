/* 11 functions from 0x02216518 to 0x022174F4 (ov005), found by ds-decomp. */
#include "common.h"



#pragma opt_common_subs off
#pragma opt_strength_reduction off
void func_ov005_02216518(u32 arg0){
extern u16 *gKeyState;
M2C_UNK PlaySoundEffect(s32);void func_020b21e0(void);void func_020b2268(void);void func_01ffa6fc(u32);
void func_ov005_02214fec(s16);void func_ov005_022150d8(s16);void func_ov005_02215168(s16);s32 func_ov005_022140f8(s32);void RecordsMenu_ShuffleList(s32);void func_ov005_02214148(void);void func_ov005_022141cc(void);

extern M2C_UNK gRecordsMenuState;
extern void *g3DSpriteEngineMain,*g3DSpriteEngineSub,*gCur3DSpriteEngine;
extern M2C_UNK data_ov005_022204e0;
void func_ov005_02214b98(void); void func_ov005_02214cdc(void);
M2C_UNK func_02090248(s32);void func_ov005_02215278(s16);void func_ov005_02215360(s32);
void RecordsMenu_DrawList(s32);void func_02088d94(void *);void func_02088da8(void *);
s32 func_020b2714(void);void func_020b2738(void);void func_020b26f8(void);
void func_020a9a30(s32,s32,u8,s32);s32 FindObjectByClass(void *);
void MenuSpriteUpdate(void *);
s32 mode; void *saved;
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x86)>0){s32 n; s32 alpha; s32 beta; void *saved; u16 * volatile reg;
M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x86)--; n=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x86);if(n>=8)n=16-n;alpha=16-2*n;beta=16-alpha;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
reg=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12);*reg=(*reg&~0xc0)|0x40;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=alpha;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=beta;
gCur3DSpriteEngine=saved;if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x86)==8)func_ov005_02214b98();}
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x88)>0){s32 n; s32 alpha; s32 beta; void *saved; u16 * volatile reg;
M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x88)--; n=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x88);if(n>=8)n=16-n;alpha=16-2*n;beta=16-alpha;
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineSub;
reg=(u16 *)((u8 *)*(void **)gCur3DSpriteEngine+0x12);*reg=(*reg&~0xc0)|0x40;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x51)=alpha;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x52)=beta;
gCur3DSpriteEngine=saved;if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x88)==8)func_ov005_02214cdc();}
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)!=-1){if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0xa0)>=0)M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0xa0)--;if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0xa0)==0x25b)func_02090248(600);if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0xa0)==0){s32 v=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e);switch(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x92)){case 0:break;case 1:func_ov005_02215278((s16)v);break;case 2:func_ov005_02215360(v);break;}}}
{void *p=M2C_FIELD(&gRecordsMenuState,void **,8);if(M2C_FIELD(p,s16 *,0x9e)==0){s32 goal=M2C_FIELD(p,s16 *,0x98);s32 current=M2C_FIELD(p,s16 *,0x96);if(current!=goal*2){s32 d=goal*2-current;s16 step;if(d<0)d=-d;step=d>>1;if(step==0)step=1;M2C_FIELD(p,s16 *,0x96)=current>goal*2?M2C_FIELD(p,s16 *,0x96)-step:M2C_FIELD(p,s16 *,0x96)+step;M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x9e)=1;RecordsMenu_DrawList(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x96));}}else M2C_FIELD(p,s16 *,0x9e)=0;}
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),u16 *,0)&1){u16 * volatile a=*(u16 **)gCur3DSpriteEngine;u16 * volatile b;*a=*a|0x20;b=*(u16 **)gCur3DSpriteEngine;*b=*b|0x40;func_02088d94(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x174));func_02088d94(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x178));if(func_020b2714())func_020b2738();}
else {u16 * volatile a=*(u16 **)gCur3DSpriteEngine;u16 * volatile b;*a=*a&~0x20;b=*(u16 **)gCur3DSpriteEngine;*b=*b&~0x40;func_02088da8(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x174));func_02088da8(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x178));if(!func_020b2714())func_020b26f8();}
if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)!=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8c)){mode=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)==-1?2:48;saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;func_020a9a30(0,0,(u8)mode,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x3700);M2C_FIELD(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x180),s16 *,0x3e)=0x1b8;gCur3DSpriteEngine=saved;}
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
if(M2C_FIELD(gKeyState,u16 *,0)&2){if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)!=-1){func_02090248(15);M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x8e)=-1;RecordsMenu_DrawList(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x96));return;}if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x90)!=-1)return;PlaySoundEffect(0x1000f);func_020b21e0();func_020b2268();func_02090248(15);func_01ffa6fc(arg0);return;}
if(M2C_FIELD(gKeyState,u16 *,0)&4){if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),u16 *,0)&1)M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),u16 *,0)&=~1;else M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),u16 *,0)|=1;}
if(M2C_FIELD(gKeyState,u16 *,0)&1)func_ov005_02214fec((s16)(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x98)+M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x94)));else {
void *state; u16 keys=M2C_FIELD(gKeyState,u16 *,0); arg0=0; state=M2C_FIELD(&gRecordsMenuState,void **,8);
if((keys&0x200)&&((u8)((((u32)(M2C_FIELD(M2C_FIELD(state,void * *,0x170),u8 *,0x59)<<28)>>28)+2)!=(u16)((M2C_FIELD(M2C_FIELD(state,void * *,0x170),u32 *,0x40)<<6)>>24)))){s32 value=M2C_FIELD(state,s16 *,0x8e);if(value!=-1){arg0=1;PlaySoundEffect(0x1000d);func_ov005_022150d8((s16)value);}else{value=M2C_FIELD(state,s16 *,0x90);if(value!=-1){arg0=1;PlaySoundEffect(0x1000d);func_ov005_022150d8((s16)value);}}}
else if((keys&0x100)&&((u8)((((u32)(M2C_FIELD(M2C_FIELD(state,void * *,0x16c),u8 *,0x59)<<28)>>28)+2)!=(u16)((M2C_FIELD(M2C_FIELD(state,void * *,0x16c),u32 *,0x40)<<6)>>24)))){s32 value=M2C_FIELD(state,s16 *,0x8e);if(value!=-1){arg0=1;PlaySoundEffect(0x1000d);func_ov005_02215168((s16)value);}else{value=M2C_FIELD(state,s16 *,0x90);if(value!=-1){arg0=1;PlaySoundEffect(0x1000d);func_ov005_02215168((s16)value);}}}
{void *state=M2C_FIELD(&gRecordsMenuState,void **,8);s32 selected=M2C_FIELD(state,s16 *,0x90);s32 row=M2C_FIELD(state,s16 *,0x98);s32 total=row+M2C_FIELD(state,s16 *,0x94);if(selected!=-1 && arg0==1 && total!=selected){do{
if(total>selected){if(row>0)M2C_FIELD(state,s16 *,0x98)--;else M2C_FIELD(state,s16 *,0x94)--;}else if(total<selected){if(row>=M2C_FIELD(state,s16 *,0x9a)-6)M2C_FIELD(state,s16 *,0x94)++;else M2C_FIELD(state,s16 *,0x98)++;}
state=M2C_FIELD(&gRecordsMenuState,void **,8);row=M2C_FIELD(state,s16 *,0x98);total=row+M2C_FIELD(state,s16 *,0x94);selected=M2C_FIELD(state,s16 *,0x90);
}while(total!=selected);}}}

if((M2C_FIELD(gKeyState,u16 *,0)&0x400)&&((u8)((((u32)(M2C_FIELD(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x184),u8 *,0x59)<<28)>>28)+2)!=(u16)((M2C_FIELD(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x184),u32 *,0x40)<<6)>>24)))){M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x92)++;if(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x92)>=3)M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x92)=0;switch(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x92)){case 0:mode=0x31;break;case 1:mode=0x34;break;case 2:mode=0x32;break;}
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;func_020a9a30(0,0,(u8)mode,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c)+0x3900);M2C_FIELD(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x184),s16 *,0x3e)=0x1c8;gCur3DSpriteEngine=saved;PlaySoundEffect(0x10011);}
if(!(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),u16 *,0)&1))return;
if(M2C_FIELD(gKeyState,u16 *,0)&0x800){s32 index=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x98)+M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x94);if(func_ov005_022140f8(index)){M2C_FIELD((u8 *)M2C_FIELD(&gRecordsMenuState,void **,8)+0xa2,u8 *,index)=!M2C_FIELD((u8 *)M2C_FIELD(&gRecordsMenuState,void **,8)+0xa2,u8 *,index);RecordsMenu_DrawList(M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),s16 *,0x96));RecordsMenu_ShuffleList(-1);}}
{void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x174);void *anim=M2C_FIELD(p,void **,0x64);u8 done=1;if(M2C_FIELD(anim,s8 *,0xb)!=1 && (!((u32)(M2C_FIELD(p,u8 *,0x59)<<27)>>31) || M2C_FIELD(anim,s8 *,0xc)!=1))done=0;if(done){func_ov005_02214148();return;}}
{void *p=M2C_FIELD(M2C_FIELD(&gRecordsMenuState,void **,8),void * *,0x178);void *anim=M2C_FIELD(p,void **,0x64);u8 done=1;if(M2C_FIELD(anim,s8 *,0xb)!=1 && (!((u32)(M2C_FIELD(p,u8 *,0x59)<<27)>>31) || M2C_FIELD(anim,s8 *,0xc)!=1))done=0;if(done)func_ov005_022141cc();}
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
void func_ov005_0221720c(void) {
s32 func_020b2714(void);
void func_020b2738(void);
void func_020842d4(void);
void func_020b2178(void);
void HeapFreeBlock(void *);
void func_02086658(s32);
void func_02082014(void);
void func_020901e0(s32);
extern M2C_UNK gRecordsMenuState;
if (func_020b2714()) func_020b2738();
func_020842d4();
func_020b2178();
if (M2C_FIELD(&gRecordsMenuState, void **, 8)) {
HeapFreeBlock(M2C_FIELD(&gRecordsMenuState, void **, 8));
M2C_FIELD(&gRecordsMenuState, void **, 8) = 0;
}
func_02086658(7);
func_02082014();
func_020901e0(4);
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
    void func_ov005_02214a84(u8);
    extern M2C_UNK gRecordsMenuState;
    s16 val = M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s16 *, 0x90);
    func_ov005_02214f80(val);
    M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s16 *, 0x90) = -1;
    func_ov005_02214a84((u8) M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), u8 *, 0x8A));
}

void func_ov005_022172d8(s16 arg0, s8 arg1) {
void func_01ffa3dc(void *, s32);
s32 func_ov005_02215650(void);
extern M2C_UNK gRecordsMenuState;
extern M2C_UNK data_ov005_022204e0;
M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s16 *, 0x90) = arg0;
M2C_FIELD(M2C_FIELD(&gRecordsMenuState, void **, 8), s8 *, 0x8a) = arg1;
func_01ffa3dc(&data_ov005_022204e0, func_ov005_02215650());
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
void func_ov005_02217334(s16 arg0) {
    extern u8 *gOv005MenuState;
    s32 i;
    void *p;
    u32 frame;
    u32 word;

    M2C_FIELD(gOv005MenuState, s16 *, 0x12) = arg0;
    for (i = 0; i < 4; i++) {
        if (i == arg0) {
            p = M2C_FIELD(gOv005MenuState + i * 4, void **, 0x2c);
            frame = ((u32)(M2C_FIELD(p, u8 *, 0x59) << 28) >> 28) + 1;
            word = M2C_FIELD(p, u32 *, 0x40);
        } else {
            p = M2C_FIELD(gOv005MenuState + i * 4, void **, 0x2c);
            frame = ((u32)(M2C_FIELD(p, u8 *, 0x59) << 28) >> 28);
            word = M2C_FIELD(p, u32 *, 0x40);
        }
        M2C_FIELD(p, u32 *, 0x40) = (word & ~0x3fc0000) | ((u32)(((u16)frame) << 24) >> 6);
    }
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
void Ov005DrawEntryList(void) {
    void func_02098ac0(s32, s32, s32, s32);
    void func_02098a34(s32, s32, s32, s32, u8);
    extern u8 *gOv005MenuState;
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineMain;
    extern void *g3DSpriteEngineSub;
    void *saved = gCur3DSpriteEngine;
    s32 value = M2C_FIELD(gOv005MenuState, s16 *, 0x10);

    gCur3DSpriteEngine = g3DSpriteEngineMain;
    func_02098ac0(value, 0, (u16)(M2C_FIELD(gOv005MenuState, s16 *, 0x10) - 1), 0);
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    func_02098a34(value, 8, 2, 0, 0);
    gCur3DSpriteEngine = saved;
    SetOv005FileDirectory();
}

void func_ov005_02217440(void) {
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, M2C_UNK);
    M2C_UNK OpenNarcArchive();
    M2C_UNK CloseNarcArchive();
    M2C_UNK LoadNarcFileDecompressed(s32, s32);
    void func_020e3004();
    void *func_020e3018(s32);
    s32 GetLocalizedFileName(M2C_UNK *);
    u32 func_020bf894(s32);
    void SetOv005FileDirectory(void);
    extern u8 *gOv005MenuState;
    extern void *gCur3DSpriteEngine;
    extern void *g3DSpriteEngineSub;
    extern M2C_UNK data_ov005_022208f4;
    void *temp_r5;
    void *saved;

    temp_r5 = func_020e3018(M2C_FIELD(gOv005MenuState, s16 *, 0x10));
    saved = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineSub;
    if (func_020bf894(M2C_FIELD(gOv005MenuState, s16 *, 0x10))) {
        func_020e3004();
        GetLocalizedFileName(&data_ov005_022208f4);
        OpenNarcArchive();
        LoadNarcFileDecompressed(GetLocalizedFileName(temp_r5), M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x1C) + 0x2800);
        CloseNarcArchive();
        SetOv005FileDirectory();
    } else {
        MI_CpuFill32(0, M2C_FIELD(g3DSpriteEngineSub, s32 *, 0x1C) + 0x2800, 0x800);
    }
    gCur3DSpriteEngine = saved;
}

