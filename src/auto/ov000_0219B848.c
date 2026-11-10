/* 11 functions from 0x0219B848 to 0x0219C7EC (ov000), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern u8 data_ov000_021e00ac;
extern s8 data_ov000_021b5580[],data_ov000_021b55a0[],data_ov000_021b5500[],data_ov000_021e0f60[];
extern u16 gPlayerUnitIdBase[];
extern u8 data_ov000_021df41c[],data_ov000_021df424[];
s32 func_ov000_0219b848(void) {
s32 func_020a8a14(u16,u16); s32 func_020d27ec(s16,u8);
s32 func_ov000_021a8d7c(s32,s32,s32);
s32 func_020d273c(u16,s32); s32 func_020d1938(s32);
s32 func_ov000_021a98a8(s32); s32 func_ov000_021a8984(s32);
void func_01ffb554(void *); void func_01ffada0(s32,s32,s32,s32,s32);
u8 *out;
u8 *entry; s32 enemyIndex,enemyPlayer,index; u8 *enemyUnit; u8 *unit; u8 *candidate,*scan,*best; void *map; s32 player,count,pass,i,cost,oldpass,bestcost,price,allow,relation,delta,bestdelta; s32 row,propertyChosen; u8 funds,penalty; u32 kind;
s32 func_ov000_0217a59c(s32,s32,s32,s32); s32 func_ov000_021a9a28(s32,s32,s32); s32 func_ov000_0219b648(s32,s32); s32 func_020d2d18(u16,u8); s32 func_ov000_021a911c(s16,s32,s32); void func_ov000_021a07c0(s32);
count=0;out=&data_ov000_021e00ac;
if(func_020a8a14(M2C_FIELD(*gCurrentMap,u16 *,0x5142),M2C_FIELD(*gCurrentMap,u16 *,0x52a4))&4)return 0;

entry=(u8 *)*gCurrentMap+0x6c60;
while(entry[0]!=255){
if(entry[0]==15){
if(func_020a8a14(M2C_FIELD(*gCurrentMap,u16 *,0x5142),M2C_FIELD(*gCurrentMap,u16 *,0x52a4))&2)goto nextEntry;
map=*gCurrentMap;
if(func_020d27ec(M2C_FIELD(map,s16 *,0x52a8),M2C_FIELD(map+entry[1]+M2C_FIELD(map+entry[2]*2,u16 *,0x3758),u8 *,0x1420)))goto nextEntry;
}else{
if(!data_ov000_021b5580[entry[0]&31])goto nextEntry;
map=*gCurrentMap;
if(M2C_FIELD(map+entry[1]+M2C_FIELD(map+entry[2]*2,u16 *,0x3758),u8 *,0x1420)&224)goto nextEntry;
}
if(func_ov000_021a8d7c(entry[1],entry[2],5))goto nextEntry;
for(player=1;player<5;player++){
if(func_020d273c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),player)&&func_020d1938(player)&&M2C_FIELD(*gCurrentMap+player*140,u8 *,0x67c2)==2){
for(index=gPlayerUnitIdBase[player]+1;index<gPlayerUnitIdBase[player]+51;index++){
unit=(u8 *)*gCurrentMap+0x59a4+index*14;
kind=(u32)(unit[0]<<26)>>26;
if(!kind||!func_ov000_021a98a8(kind)||func_ov000_021a8984((u32)(unit[11]<<28)>>28))continue;
if(unit[1]==entry[1]&&unit[2]==entry[2]&&((u32)(M2C_FIELD(unit,u16 *,6)<<16)>>27))goto nextEntry;
if(((u32)(M2C_FIELD(unit,u16 *,6)<<25)>>25)>60&&((u32)(M2C_FIELD(unit,u16 *,8)<<26)>>26)==entry[1]&&((u32)(M2C_FIELD(unit,u16 *,8)<<20)>>26)==entry[2])goto nextEntry;
if(((u32)(unit[11]<<28)>>28)&&((u32)(M2C_FIELD(unit,u16 *,8)<<26)>>26)!=63){
func_01ffb554(data_ov000_021e0f60);
func_01ffada0(((u32)(M2C_FIELD(unit,u16 *,8)<<26)>>26),((u32)(M2C_FIELD(unit,u16 *,8)<<20)>>26),1,3,0);
func_01ffb554((u8 *)*gCurrentMap+0x1e30);
if(data_ov000_021e0f60[entry[1]+entry[2]*M2C_FIELD(*gCurrentMap,u16 *,0x5144)]>=0)goto nextEntry;
}
}
}
}
out[0]=entry[1];out[1]=entry[2];out[2]=data_ov000_021b55a0[entry[0]];out[5]=255;out[4]=255;
for(pass=0;pass<5;pass++){
func_ov000_0217a59c(entry[1],entry[2],data_ov000_021df41c[pass],110);
if(data_ov000_021df41c[pass]!=13){
allow=1;
if(data_ov000_021df41c[pass]==19){
price=func_020d2d18(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),data_ov000_021df41c[pass]);
price=(price+func_020d2d18(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),1))*10;
}else price=func_020d2d18(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),data_ov000_021df41c[pass])*10;
map=*gCurrentMap;candidate=map+0x67a4+M2C_FIELD(map,u16 *,0x52a4)*140;
funds=M2C_FIELD(candidate,s32 *,0)>=price;
if(!funds&&M2C_FIELD(candidate,s32 *,8)<price)allow=0;
candidate=map+0x6c60;
while(candidate[0]!=255){
if(data_ov000_021b55a0[candidate[0]]==data_ov000_021df424[pass]){
map=*gCurrentMap;
row=M2C_FIELD(map+candidate[2]*2,u16 *,0x3758);
scan=map+candidate[1]+row;
kind=M2C_FIELD(scan,u8 *,0x1420)&224;
if(!kind)goto nextProperty;
cost=M2C_FIELD(scan,s8 *,0x2338);if(cost<0)goto nextProperty;
if(kind==M2C_FIELD(map,u16 *,0x52a6)){
if(!allow||!funds)goto nextProperty;
cost++;if(out[4]<cost)goto nextProperty;
out[4]=cost;propertyChosen=1;
}else{
cost++;if(out[5]<cost)goto nextProperty;
out[5]=cost;relation=func_ov000_021a911c(M2C_FIELD(*gCurrentMap,s16 *,0x52a8),candidate[1],candidate[2]);
}
}
nextProperty:candidate+=6;
}
}
map=*gCurrentMap;
for(index=gPlayerUnitIdBase[M2C_FIELD(map,u16 *,0x52a4)]+1;index<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+51;index++){
unit=map+0x59a4+index*14;
kind=(u32)(unit[0]<<26)>>26;
if(!kind||kind!=data_ov000_021df41c[pass]||((u32)(unit[11]<<28)>>28))goto nextOwn;
cost=M2C_FIELD(map+unit[1]+M2C_FIELD(map+unit[2]*2,u16 *,0x3758),s8 *,0x2338);
if(cost<0||(M2C_FIELD(unit,u16 *,4)&8))goto nextOwn;
if(((u32)(M2C_FIELD(unit,u16 *,6)<<16)>>27)&&func_ov000_021a98a8(kind)){
map=*gCurrentMap;
kind=M2C_FIELD(map+unit[1]+M2C_FIELD(map+unit[2]*2,u16 *,0x3758),u8 *,0x1420)&31;
if(data_ov000_021b5500[kind])goto nextOwn;
}
if(data_ov000_021df41c[pass]==13||((u32)(unit[0]<<26)>>26)==19){
if(!unit[12]&&func_ov000_021a9a28(19,unit[1],unit[2]))goto nextOwn;
out[7]=func_ov000_0219b648(unit[1],unit[2]);
if((s8)out[7]==0)goto nextOwn;
map=*gCurrentMap;cost=1+M2C_FIELD(map+unit[1]+M2C_FIELD(map+unit[2]*2,u16 *,0x3758),s8 *,0x2338);
if(out[4]<cost)goto nextOwn;
out[4]=cost;
out[6]=unit?(unit-((u8 *)*gCurrentMap+0x59a4))/14:0;
propertyChosen=0;out[3]=(u32)(unit[0]<<26)>>26;
}else{
map=*gCurrentMap;cost=M2C_FIELD(map+unit[1]+M2C_FIELD(map+unit[2]*2,u16 *,0x3758),s8 *,0x2338);
if(out[4]<cost)goto nextOwn;
out[4]=cost;
out[6]=unit?(unit-((u8 *)*gCurrentMap+0x59a4))/14:0;
propertyChosen=0;out[3]=(u32)(unit[0]<<26)>>26;
}
nextOwn:map=*gCurrentMap;
}
for(enemyPlayer=1;enemyPlayer<5;enemyPlayer++){
if(!func_020d1938(enemyPlayer)||enemyPlayer==M2C_FIELD(*gCurrentMap,u16 *,0x52a4))continue;
for(enemyIndex=gPlayerUnitIdBase[enemyPlayer]+1;enemyIndex<gPlayerUnitIdBase[enemyPlayer]+51;enemyIndex++){
map=*gCurrentMap;enemyUnit=map+0x59a4+enemyIndex*14;
kind=(u32)(enemyUnit[0]<<26)>>26;
if(!kind||kind!=data_ov000_021df41c[pass])continue;
row=M2C_FIELD(map+enemyUnit[2]*2,u16 *,0x3758);cost=M2C_FIELD(map+enemyUnit[1]+row,s8 *,0x2338);
if(cost<0||(M2C_FIELD(enemyUnit,u16 *,4)&8))continue;
if(kind==19){
if(!enemyUnit[12]&&func_ov000_021a9a28(19,enemyUnit[1],enemyUnit[2]))continue;
map=*gCurrentMap;cost=1+M2C_FIELD(map+enemyUnit[1]+M2C_FIELD(map+enemyUnit[2]*2,u16 *,0x3758),s8 *,0x2338);
if(out[5]<cost)continue;out[5]=cost;
}else {if(out[5]<cost)continue;out[5]=cost;}
relation=func_020d273c(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),enemyPlayer);
}
}
}
if(out[4]==255)goto nextEntry;
if(relation){if((u32)out[4]>out[5])goto nextEntry;}else if(out[4]>out[5]+1)goto nextEntry;
if(propertyChosen)goto nextEntry;
count++;out+=12;
nextEntry:entry+=6;
}
if(!count)return 0;
best=0;bestdelta=255;out=&data_ov000_021e00ac;
for(i=0;i<count;i++,out+=12){
if(out[5]==255)delta=255;else {delta=(s32)out[4]-out[5];if(delta<0)delta=-delta;}
if(best){
if(bestdelta<delta)continue;
if(bestdelta==delta){
if(best[2]<out[2])continue;
if(best[2]==out[2]&&best[4]<=out[4])continue;
}
}
best=out;bestdelta=delta;
}
if(!best)return 0;
if(best[3]==13||best[3]==19){
unit=(u8 *)*gCurrentMap+0x59a4+best[6]*14;
unit[11]=(unit[11]&~15)|1;
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~63)|(best[0]&63);
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~0xfc0)|((u32)(best[1]<<26)>>20);
unit=(u8 *)*gCurrentMap+0x59a4+best[7]*14;
unit[11]=(unit[11]&~15)|2;
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~63)|(best[0]&63);
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~0xfc0)|((u32)(best[1]<<26)>>20);
}else{
unit=(u8 *)*gCurrentMap+0x59a4+best[6]*14;
unit[11]=(unit[11]&~15)|1;
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~63)|(best[0]&63);
M2C_FIELD(unit,u16 *,8)=(M2C_FIELD(unit,u16 *,8)&~0xfc0)|((u32)(best[1]<<26)>>20);
}
return 1;
}
extern u8 *data_ov000_021df580;
extern u16 data_02168f14;
extern void **gCurrentMap;

extern u8 *data_ov000_021df580;
extern u8 data_02168f0c[8];

void func_ov000_0219c444(void){extern void **gCurrentMap;extern u16 gPlayerUnitIdBase[];s32 found=0,i;void *base=*gCurrentMap;u16 start=gPlayerUnitIdBase[M2C_FIELD(base,u16 *,0x52a4)];u8 *p;u32 type;for(i=start+1;i<gPlayerUnitIdBase[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+51;i++){p=((u8 (*)[14])(base+0x59a4))[i];type=(u32)(p[0]<<26)>>26;if(type!=0&&(u8)(type+255)<=2&&((u32)(p[11]<<28)>>28)==0){found=1;break;}}if(!found)return;while(func_ov000_0219b848()){} }

void func_ov000_0219c508(s8 *arg0, s8 arg1) {
extern void **gCurrentMap;
s8 *rows[40]; s32 y, x;
for(y=0; y<M2C_FIELD(*gCurrentMap, u16 *, 0x5146); y++) {
 void *base=*gCurrentMap;
 rows[y] = (s8 *)(arg0 + ((u16 *)base)[y + 0x1bac]);
}
for(y=0; y<M2C_FIELD(*gCurrentMap, u16 *, 0x5146); y++) {
 for(x=0; x<M2C_FIELD(*gCurrentMap, u16 *, 0x5144); x++) {
  rows[y][x] = arg1;
 }
}
func_01ffb554((void *)*gCurrentMap + 0x1e30);
}

void func_ov000_0219c5d4(void){for(;;){switch(*data_ov000_021df580){case 0:func_ov000_0219a1f4();break;case 1:func_ov000_0219e848();break;case 2:func_ov000_0219997c();break;case 4:if(((u32)data_02168f14<<22)>>31){if(func_020d19b4(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))){M2C_FIELD(*gCurrentMap,u16 *,0x52b0)=13;return;}}func_ov000_0219fdc8();return;default:return;}}}

s32 func_ov000_0219c680(void){switch(*data_ov000_021df580){case 0:case 1:case 2:case 4:return 1;default:return 0;}}

u8 func_ov000_0219c6c0(void) {
    s32 func_0209e0dc(M2C_UNK);
    u8 var_r0;

    if (func_0209e0dc(6) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov000_0219c774(void);
void func_ov000_0219c6e0(void){if(func_020946d0())return;if(func_0209e0dc(6))return;if(func_ov000_0219c680()){func_0209e044(func_ov000_0219c5d4,6,0x2000,17,0);return;}switch(*data_ov000_021df580){case 3:func_ov000_0219e948();return;case 5:func_ov000_021a02ac();return;case 6:func_ov000_0219c774();return;}}

void func_ov000_0219c774(void) {
    func_ov000_0219a0e0();
    func_020bbb08();
    data_ov000_021df580[0] = 0;
    if (data_02168f0c[0] != 0) {
        func_020844f8();
    }
}

u8 func_ov000_0219c7b0(void) {
    extern u8 *data_ov000_021df580;
    return *data_ov000_021df580;
}

void func_ov000_0219c7c4(u8 a){*data_ov000_021df580=a;}

void func_ov000_0219c7d8(u8 arg0) {
    data_ov000_021df580[1] = arg0;
}

