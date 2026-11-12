/* 9 functions from 0x0221C534 to 0x0221D008 (ov007), found by ds-decomp. */
#include "common.h"

extern u32 gMapEditObjectList[];
int func_020194e0(const void*,const void*);
static inline void SetTextIndex(void *p,s8 n) {
if(n<0 || n>=17)return;
if(n<17 && gMapEditObjectList[n]!=0) goto valid;
if(n<=0)return;
if(gMapEditObjectList[n-1]==0)return;
valid: M2C_FIELD(p,s8 *,0x3c)=n;
}
static inline int FindTextIndex(void *p) {
s32 result,i;u32 *needle;u32 *table;
if(M2C_FIELD(p,s8 *,0x3c)==0)return -1;
table=M2C_FIELD(p,u32 **,0x34);needle=gMapEditObjectList+(M2C_FIELD(p,s8 *,0x3c)-1);result=-1;
for(i=0;i<75;i++)if(func_020194e0(needle,(void*)table[i])==0){result=i;break;}
return result;
}


/* Initialize the map scene: load map data, fill tile slots, and center the viewport. */
void func_ov007_0221c534(void) {
M2C_UNK func_0207b754(u32,u32); M2C_UNK func_020cf498(s16,s16);
M2C_UNK RefreshMapView(); M2C_UNK func_ov007_022121b0();
M2C_UNK func_ov007_022121d4(M2C_UNK); M2C_UNK func_ov007_0221ab68();
extern void **gCurrentMap;
M2C_UNK func_020c857c(M2C_UNK); M2C_UNK GetSlotForPlayerId(M2C_UNK);
M2C_UNK RemapUnitGroups(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK Map_ReassignPropertyOwners(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
M2C_UNK ResetPlayerOrder();
s32 slot1,slot2,slot3,slot1b,slot2b,slot3b; u32 viewX,viewY; void *state;
func_020c857c(M2C_FIELD(*gCurrentMap,u16 *,0x5142));
slot1=GetSlotForPlayerId(1);slot2=GetSlotForPlayerId(2);slot3=GetSlotForPlayerId(3);
RemapUnitGroups(slot1,slot2,slot3,GetSlotForPlayerId(4));
slot1b=GetSlotForPlayerId(1);slot2b=GetSlotForPlayerId(2);slot3b=GetSlotForPlayerId(3);
Map_ReassignPropertyOwners(slot1b,slot2b,slot3b,GetSlotForPlayerId(4));
ResetPlayerOrder(); RefreshMapView(); func_ov007_022121b0(); func_ov007_0221ab68();
state=*gCurrentMap;
viewX=(u32)M2C_FIELD(state,u16 *,0x5144)>>1;
viewY=(u32)M2C_FIELD(state,u16 *,0x5146)>>1;
func_020cf498((s16)viewX,(s16)viewY);func_0207b754(viewX,viewY);func_ov007_022121d4(0);
}

void func_ov007_0221c630(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_02220178;
    func_01ffa3dc(&data_ov007_02220178, 7);
}

void func_ov007_0221c648(M2C_UNK arg0) {
    M2C_UNK func_020bfebc(M2C_UNK);
    M2C_UNK MapSettings_Apply(s32);
    s32 func_020c7e98(M2C_UNK);
    s32 func_020c7eb8();
    M2C_UNK func_020c857c(M2C_UNK);
    M2C_UNK ResizeMap(M2C_UNK, M2C_UNK);
    M2C_UNK RemapUnitGroups(s32, s32, s32, s32);
    M2C_UNK Map_ReassignPropertyOwners(s32, s32, s32, s32);
    M2C_UNK ResetPlayerOrder();
    s32 GetSlotForPlayerId(M2C_UNK);
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r6;
    s32 temp_r6_2;

    if (func_020c7eb8() == 0) {
        ResizeMap(0x14, 0x14);
        return;
    }
    temp_r4 = func_020c7e98(arg0);
    func_020c857c(arg0);
    MapSettings_Apply(temp_r4);
    func_020bfebc(0);
    temp_r6 = GetSlotForPlayerId(1);
    temp_r5 = GetSlotForPlayerId(2);
    temp_r4_2 = GetSlotForPlayerId(3);
    RemapUnitGroups(temp_r6, temp_r5, temp_r4_2, GetSlotForPlayerId(4));
    temp_r6_2 = GetSlotForPlayerId(1);
    temp_r5_2 = GetSlotForPlayerId(2);
    temp_r4_3 = GetSlotForPlayerId(3);
    Map_ReassignPropertyOwners(temp_r6_2, temp_r5_2, temp_r4_3, GetSlotForPlayerId(4));
    ResetPlayerOrder();
}

#pragma opt_strength_reduction off
void func_ov007_0221c718(void *self){
extern void *gKeyState;
extern void *gTouchState;
extern void *gCur3DSpriteEngine;
extern void *g3DSpriteEngineMain;
extern void *g3DSpriteEngineSub;
extern u32 data_ov007_0222076c;
extern u32 data_ov007_02220ab8;
s32 func_020b212c(void);
void MI_CpuCopy32(const void*,void*,u32);
void func_02019424(void*,u32);
int func_02099ae8(void*);
int func_0209c268(void*);
int func_020b2e78(u16,u16,void*);
M2C_UNK func_020808dc(s32,s32,s32,s32);
void *old,*state;u32 pressed; s16 rect[4];u32 copy[17];s32 screen,kind,index,i,width,oldIndex;u32 text,*table,*cursor;u8 ok;
pressed=M2C_FIELD(gKeyState,u16 *,6)&1;old=gCur3DSpriteEngine;state=M2C_FIELD(self,void * *,0x10);
for(screen=0;screen<2;screen++){
gCur3DSpriteEngine=screen==0?g3DSpriteEngineMain:g3DSpriteEngineSub;
if(M2C_FIELD(self,u8 *,2)==0&&gCur3DSpriteEngine!=g3DSpriteEngineMain)continue;
if(M2C_FIELD(self,u8 *,2)==1&&gCur3DSpriteEngine!=g3DSpriteEngineSub)continue;
if(M2C_FIELD(self,u8 *,2)==3&&gCur3DSpriteEngine!=old)continue;
if(!M2C_FIELD(self,u8 *,1))continue;
rect[0]=M2C_FIELD(self,s16 *,0x14);rect[1]=M2C_FIELD(self,s16 *,0x16);rect[2]=M2C_FIELD(self,s16 *,0x18);rect[3]=M2C_FIELD(self,s16 *,0x1a);
kind=M2C_FIELD(self,u8 *,0);if((s32)kind<0)kind=func_020b212c();
if(kind<0||kind>99)ok=1;else{
table=M2C_FIELD(state,u32 * *,0x34);text=table[kind];oldIndex=M2C_FIELD(state,s8 *,0x3c);
if(func_020194e0(text,&data_ov007_0222076c)==0){index=FindTextIndex(state);if(index<0){ok=0;goto checked;}SetTextIndex(state,M2C_FIELD(state,s8 *,0x3c)-1);
table=M2C_FIELD(state,u32 * *,0x34);
if(func_020194e0(gMapEditObjectList+M2C_FIELD(state,s8 *,0x3c),(void*)table[index+75])==0){SetTextIndex(state,oldIndex);ok=0;goto checked;}
text=table[index+75];}
else if(func_020194e0(text,&data_ov007_02220ab8)==0){index=FindTextIndex(state);if(index<0){ok=0;goto checked;}SetTextIndex(state,M2C_FIELD(state,s8 *,0x3c)-1);
table=M2C_FIELD(state,u32 * *,0x34);
if(func_020194e0(gMapEditObjectList+M2C_FIELD(state,s8 *,0x3c),(void*)table[index+150])==0){SetTextIndex(state,oldIndex);ok=0;goto checked;}
text=table[index+150];}
if(M2C_FIELD(state,s8 *,0x3c)>=16){SetTextIndex(state,oldIndex);ok=0;goto checked;}
MI_CpuCopy32(gMapEditObjectList,copy,0x44);
copy[M2C_FIELD(state,s8 *,0x3c)]=0;
func_02019424(copy+M2C_FIELD(state,s8 *,0x3c),text);
width=0;cursor=copy;
if(*cursor){do{if(!func_02099ae8(cursor)&&width)width++;width+=func_0209c268(cursor);cursor++;}while(*cursor);}
width=(s16)width;SetTextIndex(state,oldIndex);ok=width<=64;
}
checked:
if(!ok){func_020808dc((s32)((u8*)M2C_FIELD(gCur3DSpriteEngine,void * *,0x24)+(M2C_FIELD(self,s16 *,0x14)>>3)*2+(M2C_FIELD(self,s16 *,0x16) >>3)*64),(u16)(M2C_FIELD(self,s16 *,0x18)>>3),(u16)(M2C_FIELD(self,s16 *,0x1a)>>3),6);}else{
if((M2C_FIELD(gTouchState,u8 *,0x12)&&func_020b2e78(M2C_FIELD(gTouchState,u16 *,0),M2C_FIELD(gTouchState,u16 *,2),rect))||(M2C_FIELD(self,u8 *,0)==func_020b212c()&&pressed)){func_020808dc((s32)((u8*)M2C_FIELD(gCur3DSpriteEngine,void * *,0x24)+(M2C_FIELD(self,s16 *,0x14)>>3)*2+(M2C_FIELD(self,s16 *,0x16) >>3)*64),(u16)(M2C_FIELD(self,s16 *,0x18)>>3),(u16)(M2C_FIELD(self,s16 *,0x1a)>>3),7);}else{func_020808dc((s32)((u8*)M2C_FIELD(gCur3DSpriteEngine,void * *,0x24)+(M2C_FIELD(self,s16 *,0x14)>>3)*2+(M2C_FIELD(self,s16 *,0x16) >>3)*64),(u16)(M2C_FIELD(self,s16 *,0x18)>>3),(u16)(M2C_FIELD(self,s16 *,0x1a)>>3),5);}
}
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
}
gCur3DSpriteEngine=old;
}
#pragma opt_strength_reduction reset
void func_ov007_0221cd5c(void) {
    void func_ov007_0221c718();
    func_ov007_0221c718();
}

void func_ov007_0221cd68(void *arg0) {
M2C_UNK SetFileDirectory(M2C_UNK *);
M2C_UNK func_020808dc(s32,s32,s32,s32);
M2C_UNK OpenNarcArchive();
M2C_UNK CloseNarcArchive();
M2C_UNK LoadNarcFileDecompressed(s32,s32);
s32 func_020e32e8(M2C_UNK *);
M2C_UNK PlaySoundEffect(s32);
extern void *g3DSpriteEngineMain;
extern void *gCur3DSpriteEngine;
extern M2C_UNK gMapEditPath;
extern s32 gSoftKeyLayouts[];
extern M2C_UNK gSoftKeyNarcName;
extern M2C_UNK gSoftKeyEuFileName;
extern M2C_UNK gSoftKeyUsFileName;
extern M2C_UNK gSoftKeyJpFileName;
s32 kind;
void *p;
void *saved;
s32 old;
kind=M2C_FIELD(arg0,u8 *,0);
p=M2C_FIELD(arg0,void **,0x10);
old=M2C_FIELD(p,s32 *,0x34);
if((s32)kind>=100 && (s32)kind<103) M2C_FIELD(p,s32 *,0x34)=gSoftKeyLayouts[kind-100];
if(old==M2C_FIELD(p,s32 *,0x34))return;
SetFileDirectory(&gMapEditPath);
saved=gCur3DSpriteEngine;
gCur3DSpriteEngine=g3DSpriteEngineMain;
func_020e32e8(&gSoftKeyNarcName);
OpenNarcArchive();
switch(kind){
case 102:LoadNarcFileDecompressed(func_020e32e8(&gSoftKeyJpFileName),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24));break;
case 100:LoadNarcFileDecompressed(func_020e32e8(&gSoftKeyUsFileName),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24));break;
case 101:LoadNarcFileDecompressed(func_020e32e8(&gSoftKeyEuFileName),M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24));break;
}
CloseNarcArchive();
func_020808dc(M2C_FIELD(gCur3DSpriteEngine,s32 *,0x24),32,24,5);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
gCur3DSpriteEngine=saved;
PlaySoundEffect(0x10011);
}

void func_ov007_0221ce9c(u8 *arg0) {
M2C_UNK FocusSpriteSlotById(u8);
extern void *gKeyState;
u16 held,pressed;
u8 current,old;
old=*arg0;
pressed=M2C_FIELD(gKeyState,u16 *,0);
current=old;
held=M2C_FIELD(gKeyState,u16 *,2);
if(pressed&1){func_ov007_0221cd68(arg0);return;}
if(held&0x40){
switch(old){
case 100:if(held==pressed)current=60;break;
case 101:if(held==pressed)current=61;break;
case 102:if(held==pressed)current=62;break;
}
if(current>=100U){ if(current>=103U){} else goto horizontal; }
}else if(held&0x80){
switch(old){
case 100:if(held==pressed)current=0;break;
case 101:if(held==pressed)current=1;break;
case 102:if(held==pressed)current=2;break;
}
if(current>=100U && current<103U)goto horizontal;
}else{
horizontal:
if(held&0x20){
switch(current){
case 101:case 102:current--;break;
case 100:if(held==pressed)current=106;break;
}
if(current>=100U && current<103U)goto done;
}else if(held&0x10){
switch(current){
case 100:case 101:current++;break;
case 102:current=103;break;
}
}
}
done:
if(old==current)return;
FocusSpriteSlotById(current);
}

void func_ov007_0221cfe8(void) {
    M2C_UNK PlaySoundEffect(s32);
    PlaySoundEffect(0x10019);
}

void func_ov007_0221cffc(void) {
    void func_ov007_0221c718();
    func_ov007_0221c718();
}

