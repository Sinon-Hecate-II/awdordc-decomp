/* 17 functions from 0x021707D8 to 0x02171774 (ov000), found by ds-decomp. */
#include "common.h"
#include "battle_map.h"


#pragma opt_strength_reduction off
void func_ov000_021707d8(void) {
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern void **gCurrentMap;
extern u8 gMapConfig[];
s32 func_020cd6d4(void);s32 func_020a8a84(u16);void *GetCurrentMapName(void);
void func_0209c048(s16,s16,void *,s32,s32,s32);
void func_0209c024(s16,s16,void *,void *,s32,s32);
s32 GetLanguage(void);s32 func_0207cb88(s32);s32 func_020cfb94(void);
s32 func_020d303c(s32);s32 func_020d30a8(s32);
void *func_020a8bc0(void);void *func_020a8bcc(void);
volatile s32 e;
void *old;
void *dst;
s32 c,d;u8 *dummy; s32 y,color,a,b,x;
u8 *p,*map;
old=gCur3DSpriteEngine;dst=M2C_FIELD(old,void **,0x24);
gCur3DSpriteEngine=g3DSpriteEngineMain;
if(func_020cd6d4()){
func_0209c048(3,1,dst,func_020a8a84(M2C_FIELD(*gCurrentMap,u16 *,0x5142)),0,0);
func_0209c024(5,1,dst,GetCurrentMapName(),0,0);
}else func_0209c024(2,1,dst,GetCurrentMapName(),0,0);
if(!GetLanguage()) x=26;
else x=30-(3-func_0207cb88(M2C_FIELD(*gCurrentMap,u16 *,0x52a2)));
func_0209c048((s16)x,1,dst,M2C_FIELD(*gCurrentMap,u16 *,0x52a2),0,0);
{s32 i=0;
if(func_020cfb94()>0){y=6;do{
x=i+1;p=(u8 *)*gCurrentMap+0x67a4+x*140;
if(p[0x1e] && !p[0x19]){
a=func_020d303c(x);if(a>999)a=999;
b=func_020d30a8(x);if(b>999)b=999;
x=M2C_FIELD(p,s32 *,0);c=p[0x18];if(c>999)c=999;d=M2C_FIELD(p,s32 *,8);if(d>999999)d=999999;e=x;if(x>999999)e=999999;
color=p[0x1c]?3:0;
func_0209c048(8,(s16)y,dst,a,0,color);
func_0209c048(12,(s16)y,dst,b,0,color);
if(p[0x1c]){
func_0209c024(16,(s16)y,dst,func_020a8bc0(),0,color);
func_0209c024(23,(s16)y,dst,func_020a8bc0(),0,color);
func_0209c024(30,(s16)y,dst,func_020a8bc0(),0,color);
}else{
map=*gCurrentMap;
if((!map[0x5156] && map[0x5158]!=2) || p[0x26]==map[0x67ca+M2C_FIELD(map,u16 *,0x52a4)*140]){
func_0209c048(16,(s16)y,dst,c,0,color);
func_0209c048(23,(s16)y,dst,d,0,color);
func_0209c048(30,(s16)y,dst,e,0,color);
}else{
if(gMapConfig[2]){
func_0209c048(16,(s16)y,dst,c,0,color);
func_0209c048(23,(s16)y,dst,d,0,color);
}else{
func_0209c024(16,(s16)y,dst,func_020a8bcc(),0,color);
func_0209c024(23,(s16)y,dst,func_020a8bcc(),0,color);
}
func_0209c024(30,(s16)y,dst,func_020a8bcc(),0,color);
}}
y+=3;
}i++;}while(i<func_020cfb94());}}
map=*gCurrentMap;
if((!map[0x5156] && map[0x5158]!=2)||gMapConfig[2]){
a=map[0x67bc];if(a>999)a=999;
func_0209c048(16,17,dst,a,0,0);
}else func_0209c024(16,17,dst,func_020a8bcc(),0,0);
gCur3DSpriteEngine=old;
}
void func_ov000_02170ca0(void) {
    M2C_UNK func_01ffa6fc(s32);
    s32 FindObjectByClass(M2C_UNK *);
    M2C_UNK PlaySoundEffect(s32);
    extern M2C_UNK data_ov000_021b8b88;
    s32 temp_r4;
    temp_r4 = FindObjectByClass(&data_ov000_021b8b88);
    PlaySoundEffect(0x10018);
    func_01ffa6fc(temp_r4);
}

#pragma opt_strength_reduction off
/* Loads the map "situation" screen: opens the situation archive, uploads the
 * character, sprite and palette data, gives every player its portrait tile and
 * army colour palette, then refreshes the situation panel. */
void LoadSituationScreen(void *object){
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;extern void **gCurrentMap;
extern M2C_UNK sSituationDir,sSituationNarcName,sSituationCgName,sSituationScName,sSituationClName;
void func_020994e0(s32);M2C_UNK Clear3DSpriteLayer(M2C_UNK);void SetFileDirectory(void *);void *GetLocalizedFileName(void *);void OpenNarcArchive(void *);void LoadNarcFileDecompressed(void *,void *);void func_02080944(void *,s32,s32,s32);void CloseNarcArchive(void);void LoadFileToSpriteBuffer(void *,s32,s32);void func_020c0fac(void *);s32 func_020cfb94(void);void *func_ov000_0216ce10(s32);void *func_ov000_0216ce84(s32);void func_02007ef4(void *,void *,s32);void func_01ff9e44(void *,s32,s32);void func_020ae528(void *);void func_ov000_021707d8(void);
void *oldEngine=gCur3DSpriteEngine;s32 i;void *dest;u8 *player;s32 tile,paletteOff;
gCur3DSpriteEngine=g3DSpriteEngineMain;func_020994e0(0);Clear3DSpriteLayer(1);Clear3DSpriteLayer(2);
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x3a)=0;
M2C_FIELD(*(void **)gCur3DSpriteEngine,u16 *,0x42)=1;
SetFileDirectory(&sSituationDir);OpenNarcArchive(GetLocalizedFileName(&sSituationNarcName));
LoadNarcFileDecompressed(GetLocalizedFileName(&sSituationCgName),M2C_FIELD(g3DSpriteEngineMain,void **,0x14));
LoadNarcFileDecompressed(GetLocalizedFileName(&sSituationScName),M2C_FIELD(gCur3DSpriteEngine,void **,0x28));
func_02080944(M2C_FIELD(gCur3DSpriteEngine,void **,0x28),32,24,6);CloseNarcArchive();LoadFileToSpriteBuffer(&sSituationClName,192,32);func_020c0fac(object);
i=0;if(func_020cfb94()>0){tile=0x35c;do{
player=(u8 *)*gCurrentMap+MAP_PLAYER_STATES+(i+1)*MAP_PLAYER_STRIDE;dest=(u8 *)M2C_FIELD(g3DSpriteEngineMain,void * volatile *,0x1c)+(tile<<5);
func_02007ef4(func_ov000_0216ce10(player[PLAYER_REC_ARMY_STATE]),dest,128);
paletteOff=(i+27)<<5;func_01ff9e44(func_ov000_0216ce84(player[PLAYER_REC_ARMY_INDEX]),paletteOff,32);
if(player[0x1c])func_020ae528((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x30)+(paletteOff&~1));
i++;tile+=4;}while(i<func_020cfb94());}
func_ov000_021707d8();M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;gCur3DSpriteEngine=oldEngine;
}
#pragma opt_strength_reduction reset
void func_ov000_02170ea4(void){
extern u16 *gKeyState;extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;extern void **gCurrentMap;extern M2C_UNK gSpriteDesc16x16;
s32 func_020cfb94(void);void AddSprite(s32,s32,u16,void *,s32);
void *old; s32 i;u8 *p;u32 bits;
if(*gKeyState&2){func_ov000_02170ca0();return;}
old=gCur3DSpriteEngine;gCur3DSpriteEngine=g3DSpriteEngineMain;
for(i=0;i<func_020cfb94();i++){
p=(u8 *)*gCurrentMap+i*140+0x67a4;
if(p[0xaa]&&!p[0xa5]){bits=(u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30;
AddSprite(16,(46+i*24)&255,(u16)((((0x35c+i*4)>>bits)&1023)|(u16)((i+11)<<12)),&gSpriteDesc16x16,0);}
}
gCur3DSpriteEngine=old;
}
#pragma opt_common_subs reset
void func_ov000_02170fc4(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK func_020cfd28();
    extern void *g3DSpriteEngineMain;
    extern void *gCur3DSpriteEngine;
    void *temp_r4;
    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = g3DSpriteEngineMain;
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    func_020cfd28();
    gCur3DSpriteEngine = temp_r4;
}

void func_ov000_02171028(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8b88;
    func_01ffa3dc(&data_ov000_021b8b88, 7);
}

#pragma opt_common_subs off
void func_ov000_02171040(void *p){
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;extern void **gCurrentMap;
extern M2C_UNK data_ov000_021b8c58,data_ov000_021b8c60,data_ov000_021b8c70,data_ov000_021b8c7c,data_ov000_021b8c88;
s32 func_020a8afc(s32);void func_0209b26c(s32,s32,s32,s32,u16,u16);
void SetFileDirectory(void *);void *GetLocalizedFileName(void *);
void OpenNarcArchive(void *);void LoadNarcFileDecompressed(void *,void *);void LoadNarcFileToSpriteBuffer(void *,s32,s32);
void CloseNarcArchive(void);void func_02091d4c(s32);
s32 Get3DSpriteLayerSize(u8,s32);void AddToU16Array(void *,u16,s32);void func_020c0fac(void *);
void *old=gCur3DSpriteEngine;s32 n;u16 v;
gCur3DSpriteEngine=g3DSpriteEngineMain;
n=func_020a8afc(M2C_FIELD(*gCurrentMap,u16 *,0x5142));
func_02091d4c(0);func_0209b26c(5,8,1,n,0,64);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
SetFileDirectory(&data_ov000_021b8c58);
OpenNarcArchive(GetLocalizedFileName(&data_ov000_021b8c60));
LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov000_021b8c70),M2C_FIELD(gCur3DSpriteEngine,void **,0x14));
LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov000_021b8c7c),M2C_FIELD(gCur3DSpriteEngine,void **,0x28));
LoadNarcFileToSpriteBuffer(GetLocalizedFileName(&data_ov000_021b8c88),0x60,0x20);
CloseNarcArchive();
v=Get3DSpriteLayerSize((u8)((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<29)>>29),2);
AddToU16Array(M2C_FIELD(gCur3DSpriteEngine,void **,0x28),v,0x3000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
func_020c0fac(p);gCur3DSpriteEngine=old;
}
#pragma opt_common_subs reset
void func_ov000_021711a4(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK PlaySoundEffect(s32);
    extern void *gCur3DSpriteEngine;
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 4);
    PlaySoundEffect(0x10018);
}

void func_ov000_021711f0(s32 arg0) {
    M2C_UNK func_01ffa6fc(s32);
    extern u16 *gKeyState;
    if (!(*gKeyState & 2)) return;
    func_01ffa6fc(arg0);
}

void func_ov000_02171214(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8c18;
    func_01ffa3dc(&data_ov000_021b8c18, 7);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_strength_reduction on
s32 func_ov000_0217122c(s32 arg0) {
extern void **gCurrentMap;extern void *gCur3DSpriteEngine;extern M2C_UNK data_ov000_021b8cdc;
s32 IsPlayerPresent(s32);s32 IsPlayerCpu(s32);s32 IsPlayerActive(s32);
void *GetLocalizedFileName(void *);void LoadNarcFileDecompressed(void *,void *);
s32 func_02084b08(s32);void func_ov000_0216a30c(s32,s32,s32);
void *func_ov000_0216ce10(s32);void *func_ov000_0216ce84(s32);
void func_02007ef4(void *,void *,s32);void func_01ff9e44(void *,s32,s32);void func_020ae528(void *);
s32 func_02084ac0(s32);void func_020e4cd8(s32,void *,void *,s32,s32,u16,s32);
s32 func_02084b58(s32);s32 func_02084ba8(s32);s32 func_ov000_0216a77c(s32);s32 func_ov000_0216a7d4(s32);s32 GetLocalizedText(s32);
void func_0209b32c(s32,s16,s32,s32,s32,u16,u16);
s32 i=arg0-1,off;u8 *p=(u8 *)*gCurrentMap+0x67a4+arg0*140;
s32 n=i*5,a=p[0x27],b=p[0x1d],t,color;void *dst,*engine;
if(!IsPlayerPresent(arg0))return 0;
if(IsPlayerCpu(arg0))return 0;
LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov000_021b8cdc),(u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x28)+(n<<6));
t=i*12;off=t+0x35c;
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
func_ov000_0216a30c(func_02084b08(i),off<<5,11);
dst=(u8 *)M2C_FIELD(gCur3DSpriteEngine,void * volatile *,0x1c)+((t+0x364)<<5);
func_02007ef4(func_ov000_0216ce10(a),dst,128);
off=(i+28)<<5;
func_01ff9e44(func_ov000_0216ce84(b),off,32);
if(!IsPlayerActive(arg0))func_020ae528((u8 *)M2C_FIELD(gCur3DSpriteEngine,void **,0x30)+(off&~1));
color=IsPlayerActive(arg0)?0:3;off=(i<<7)+16;engine=*(void * volatile *)&gCur3DSpriteEngine;
func_020e4cd8(func_02084ac0(i),M2C_FIELD(engine,void **,0x10),M2C_FIELD(engine,void **,0x24),0,9,(u16)(n+1),off);
func_0209b32c(13,(s16)(n+3),1,GetLocalizedText(func_ov000_0216a77c(func_02084b58(i))),0,(u16)color,(u16)(off+80));
func_0209b32c(19,(s16)(n+3),1,GetLocalizedText(func_ov000_0216a7d4(func_02084ba8(i))),0,(u16)color,(u16)(off+96));
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;return 1;
}
#pragma pop
void func_ov000_02171468(u8 *p){
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern M2C_UNK data_ov000_021b8ce8,data_ov000_021b8cf0,data_ov000_021b8d00,data_ov000_021b8d0c;
void func_020e4c64(void);void SetFileDirectory(void *);void *GetLocalizedFileName(void *);
void OpenNarcArchive(void *);void LoadNarcFileDecompressed(void *,void *);void LoadNarcFileToSpriteBuffer(void *,s32,s32);
s32 func_ov000_0217122c(s32);void CloseNarcArchive(void);void func_02091d4c(s32);
s32 Get3DSpriteLayerSize(u8,s32);void AddToU16Array(void *,u16,s32);void func_020c0fac(void *);
void *old=gCur3DSpriteEngine;s32 i;
gCur3DSpriteEngine=g3DSpriteEngineMain;
func_020e4c64();SetFileDirectory(&data_ov000_021b8ce8);
OpenNarcArchive(GetLocalizedFileName(&data_ov000_021b8cf0));
LoadNarcFileDecompressed(GetLocalizedFileName(&data_ov000_021b8d00),M2C_FIELD(gCur3DSpriteEngine,void **,0x14));
LoadNarcFileToSpriteBuffer(GetLocalizedFileName(&data_ov000_021b8d0c),0x60,0x20);
for(i=1;i<5;i++){if(func_ov000_0217122c(i))p[0x34+i]=1;else p[0x34+i]=0;}
CloseNarcArchive();func_02091d4c(0);
AddToU16Array(M2C_FIELD(gCur3DSpriteEngine,void **,0x28),(u16)Get3DSpriteLayerSize((u8)((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<29)>>29),2),0x3000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=4;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x3a)=0;
M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0x42)=3;
func_020c0fac(p);gCur3DSpriteEngine=old;
}

void func_ov000_021715a4(u8 *p){
extern void *gCur3DSpriteEngine,*g3DSpriteEngineMain;
extern M2C_UNK gSpriteDesc16x16;
void func_ov000_0216a374(s32,u16,u16,s32);
void AddSprite(s32,s32,u16,void *,s32);
void *old=gCur3DSpriteEngine;s32 i;
gCur3DSpriteEngine=g3DSpriteEngineMain;
for(i=1;i<5;i++){
if(p[0x34+i]){
s32 n=i-1;
func_ov000_0216a374(0x42,(u16)((n*40+21)&511),(u16)(((n*12+0x35c)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|0xb000),11);
AddSprite(8,(n*40+14)&255,(u16)(((n*12+0x364)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),u16 *,0)<<17)>>30)&1023)|(u16)((n+12)<<12)),&gSpriteDesc16x16,11);
}
}
gCur3DSpriteEngine=old;
}

void func_ov000_021716c0(void) {
    M2C_UNK Clear3DSpriteLayer(M2C_UNK);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_020e4ca0();
    extern void *gCur3DSpriteEngine;
    Clear3DSpriteLayer(1);
    Clear3DSpriteLayer(2);
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 2;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) |= 4;
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0x3a) = 0;
    M2C_FIELD(*(void **)gCur3DSpriteEngine, u16 *, 0x42) = 0;
    func_020e4ca0();
    PlaySoundEffect(0x10018);
}

void func_ov000_0217172c(s32 arg0) {
    M2C_UNK func_01ffa6fc(s32);
    extern u16 *gKeyState;
    if (!(*gKeyState & 2)) return;
    func_01ffa6fc(arg0);
}

void func_ov000_02171750(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov000_021b8c94;
    func_01ffa3dc(&data_ov000_021b8c94, 7);
}

s32 func_ov000_02171768(s32 arg0) {
    return (arg0 * 0x10) + 0x430;
}
