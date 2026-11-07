/* 1 function from 0x02176E28 to 0x02177CE0 (ov000), found by ds-decomp. */
#include "common.h"
s32 func_ov000_021a98e4(s32);s32 func_ov000_021a98a8(s32);s32 func_ov000_02176e08(s32);s32 func_ov000_021a9214(void *,s32,s32);s32 func_ov000_021a97d0(s32,s32);s32 func_ov000_0217c9f4(void *);

extern void **gCurrentMap;extern u8 data_ov000_021b5c00[],data_ov000_021b5c0f[],data_ov000_021b5efc[],data_ov000_021df918[],data_ov000_021df9bc[],data_ov000_021dfc4c[],data_ov000_021dfba8[],data_ov000_021dfcf0[];extern u8 *data_ov000_021df644,*data_ov000_021df580;
void func_020d166c(s32,u16,void *);s32 func_020a7cfc(void *);s32 func_ov000_021a9904(s32);s32 func_0207c8ec(s32,s32);s32 func_ov000_021976ac(s32,s32,void *,s32);s32 func_ov000_021a90a8();s32 func_ov000_021a8a88(void *);
static inline u8 Tile76(s32 x,s32 y,s32 offset){u8 *map=*gCurrentMap;return M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,offset);}
static inline u8 Bit76(u8 *bits,s32 x,s32 y){u32 index=x+y*M2C_FIELD(*gCurrentMap,u16 *,0x5144);return bits[index>>3]&(1<<(index&7));}


s32 func_ov000_021a90a8();
s32 func_ov000_02176e28(u32 arg0,u32 arg1){
u8 *a,*b,*map; s16 *pos=(s16 *)arg1;s32 va,vb,value=1,cost,index,ka,kb,attr,attra,attrb,n;u32 terrain;
func_020d166c(M2C_FIELD((*gCurrentMap),u8 *,21204),(u16)arg0,pos);
if(!M2C_FIELD((*gCurrentMap),s16 *,28374))return 0;
a=M2C_FIELD((*gCurrentMap),u8 * *,28344);b=M2C_FIELD((*gCurrentMap),u8 * *,28376);
if(((u32)(M2C_FIELD(M2C_FIELD((*gCurrentMap),u8 * *,21200),u8 *,11)<<28)>>28)==10 && func_020a7cfc(b))return 0xffff;
if(((u32)(a[0]<<26)>>26)==25&&M2C_FIELD((*gCurrentMap),s16 *,28390)&&func_ov000_021a9904(((u32)(b[0]<<26)>>26))==2)return 0;
if(arg0&0x20000){if(M2C_FIELD((*gCurrentMap),s16 *,28370)>=10)return 0;if(!M2C_FIELD((*gCurrentMap),s16 *,28358))return 0;}
if(arg0&0x10000){if(func_ov000_021a9904(((u32)(b[0]<<26)>>26))==2)return 0;if(M2C_FIELD((*gCurrentMap),s16 *,28390)&&M2C_FIELD((*gCurrentMap),s16 *,28402)<30)return 0;}
va=func_0207c8ec(M2C_FIELD(data_ov000_021b5c00+((u32)(a[0]<<26)>>26)*112,u16 *,0)*((s32)((u32)(M2C_FIELD(a,u16 *,6)<<25)>>25)-M2C_FIELD((*gCurrentMap),s16 *,28358)),100);
vb=func_0207c8ec(M2C_FIELD(data_ov000_021b5c00+((u32)(b[0]<<26)>>26)*112,u16 *,0)*((s32)((u32)(M2C_FIELD(b,u16 *,6)<<25)>>25)-M2C_FIELD((*gCurrentMap),s16 *,28390)),100);
if(func_020a7cfc(b)&&!M2C_FIELD((*gCurrentMap),s16 *,28390))vb=M2C_FIELD(data_ov000_021b5c00+((u32)(b[0]<<26)>>26)*112,u16 *,0);
cost=func_ov000_021976ac(pos[0],pos[1],b,M2C_FIELD((*gCurrentMap),s16 *,28390));
if((u32)(M2C_FIELD(b,u16 *,6)<<16)>>27){
map=*gCurrentMap;index=b[1]+M2C_FIELD(map+b[2]*2,u16 *,0x3758);terrain=M2C_FIELD(map+index,u8 *,0x1420)&31;
if(terrain==15){index=a[1]+M2C_FIELD(map+a[2]*2,u16 *,0x3758);if(!func_ov000_021a90a8(M2C_FIELD(map+index,u8 *,0x508),b[1],b[2])&&func_ov000_021a8a88(b)==1)goto special;}
}
if(arg0&0x40000){if(func_ov000_021a9904(((u32)(b[0]<<26)>>26))==2)return 0;if(vb<func_0207c8ec(M2C_FIELD(data_ov000_021b5efc,u16 *,20)*60,100))return 0;}
if(arg0&0xc00000){
if(((u32)(M2C_FIELD(a,u16 *,6)<<25)>>25)>=40){
if(Bit76(data_ov000_021df918,pos[0],pos[1]))goto passed;
ka=((u32)(a[0]<<26)>>26);
if((ka==14||ka==16)&&(((u32)(b[0]<<26)>>26)==14||((u32)(b[0]<<26)>>26)==15||((u32)(b[0]<<26)>>26)==16||((u32)(b[0]<<26)>>26)==17))goto passed;
if(ka==22&&(((u32)(b[0]<<26)>>26)==20||((u32)(b[0]<<26)>>26)==21))goto passed;
}
map=*gCurrentMap;index=M2C_FIELD(map+pos[1]*2,u16 *,0x3758)+pos[0];terrain=M2C_FIELD(map+index,u8 *,0x2d48);
if(M2C_FIELD((*gCurrentMap),s16 *,28358)<=cost+(s32)terrain)return 0;
if(terrain>=data_ov000_021df644[2])return 0;
if(cost>=data_ov000_021df644[1]){
attr=data_ov000_021b5c0f[((u32)(a[0]<<26)>>26)*112];
if((attr&7)&&!Bit76(data_ov000_021df9bc,pos[0],pos[1]))return 0;
if((attr&16)&&!Bit76(data_ov000_021dfc4c,pos[0],pos[1]))return 0;
}
}
passed:
if(((u32)(M2C_FIELD(data_ov000_021df580,u16 *,10)<<20)>>29)&1 && (arg0&0x200000)){
if(func_ov000_021a98e4(((u32)(b[0]<<26)>>26))!=1||((u32)(b[0]<<26)>>26)==26){
attra=data_ov000_021b5c0f[((u32)(a[0]<<26)>>26)*112];attr=attra&16;
if(attr&&(data_ov000_021b5c0f[((u32)(b[0]<<26)>>26)*112]&7)&&!Bit76(data_ov000_021dfba8,pos[0],pos[1])){if(cost>=data_ov000_021df644[1])return 0;if(M2C_FIELD((u8 *)(*gCurrentMap)+(pos[0]+M2C_FIELD((u8 *)(*gCurrentMap)+pos[1]*2,u16 *,0x3758)),u8 *,0x2d48)>=data_ov000_021df644[2])return 0;}
attrb=data_ov000_021b5c0f[((u32)(b[0]<<26)>>26)*112];
if((attrb&7)&&Bit76(data_ov000_021dfcf0,pos[0],pos[1]))goto combat_check;
if((attrb&16)&&Bit76(data_ov000_021dfba8,pos[0],pos[1]))goto combat_check;
if((attra&7)&&Bit76(data_ov000_021df9bc,pos[0],pos[1]))goto combat_check;
if(attr&&Bit76(data_ov000_021dfc4c,pos[0],pos[1]))goto combat_check;
if(cost>=data_ov000_021df644[1])return 0;
if(M2C_FIELD((u8 *)(*gCurrentMap)+(pos[0]+M2C_FIELD((u8 *)(*gCurrentMap)+pos[1]*2,u16 *,0x3758)),u8 *,0x2d48)>=data_ov000_021df644[2])return 0;
}}
if((arg0&0x80000)&&!func_ov000_021a98a8(((u32)(a[0]<<26)>>26))&&((u32)(a[0]<<26)>>26)!=4){
if(func_ov000_021a9904(((u32)(b[0]<<26)>>26))==2)return 0;
if(M2C_FIELD(data_ov000_021b5efc,u16 *,244)<=M2C_FIELD(data_ov000_021b5c00+((u32)(a[0]<<26)>>26)*112,u16 *,0)){if(vb<func_0207c8ec(M2C_FIELD(data_ov000_021b5efc,u16 *,244)*40,100))return 0;}
else if(vb<func_0207c8ec(M2C_FIELD(data_ov000_021b5efc,u16 *,20)*40,100))return 0;
if(M2C_FIELD((*gCurrentMap),s16 *,28390)&&M2C_FIELD((*gCurrentMap),s16 *,28402)<20)return 0;
if(M2C_FIELD((u8 *)(*gCurrentMap)+M2C_FIELD((*gCurrentMap),u16 *,21156)*140,u8 *,0x67ce)==3)return 0;
}
if((arg0&0x100000)&&((u32)(b[0]<<26)>>26)!=22&&M2C_FIELD((u8 *)(*gCurrentMap)+M2C_FIELD((*gCurrentMap),u16 *,21156)*140,u8 *,0x67ce)!=0){
if(M2C_FIELD((*gCurrentMap),s16 *,28390)&&M2C_FIELD((*gCurrentMap),s16 *,28402)<20)return 0;
if(func_ov000_021a9904(((u32)(b[0]<<26)>>26))==2&&(data_ov000_021b5c0f[((u32)(b[0]<<26)>>26)*112]&32))return 0;
}
combat_check:
if(M2C_FIELD((*gCurrentMap),s16 *,28390)&&(s32)((u32)(M2C_FIELD(b,u16 *,6)<<25)>>25)-M2C_FIELD((*gCurrentMap),s16 *,28390)<=10)vb>>=2;
if((s32)((u32)(M2C_FIELD(a,u16 *,6)<<25)>>25)-M2C_FIELD((*gCurrentMap),s16 *,28358)>=70 && M2C_FIELD((u8 *)(*gCurrentMap)+M2C_FIELD((*gCurrentMap),u16 *,21156)*140,u8 *,0x67ce)!=0)vb>>=2;
special:
if((func_ov000_02176e08(((u32)(a[0]<<26)>>26))&&func_ov000_02176e08(((u32)(b[0]<<26)>>26)))||(((u32)(a[0]<<26)>>26)==15&&((u32)(b[0]<<26)>>26)==23)||(((u32)(a[0]<<26)>>26)==15&&((u32)(b[0]<<26)>>26)==6)||(((u32)(a[0]<<26)>>26)==23&&((u32)(b[0]<<26)>>26)==22)){vb+=vb>>1;va>>=1;}
ka=((u32)(a[0]<<26)>>26);attr=data_ov000_021b5c0f[((u32)(a[0]<<26)>>26)*112]&7;
if(attr&&((u32)(b[0]<<26)>>26)==9){vb+=vb>>1;if(ka==9)va>>=1;}
if(attr&&((u32)(b[0]<<26)>>26)==26){vb+=vb>>1;if((u8)(ka+248)<=1)va>>=1;}
if(func_020a7cfc(b))vb<<=1;
if(!M2C_FIELD((*gCurrentMap),s16 *,28390)&&func_ov000_021a9214(b,b[1],b[2])==1)vb+=func_0207c8ec(M2C_FIELD(data_ov000_021b5c00+((u32)(b[0]<<26)>>26)*112,u16 *,0)*20,100);
if(func_ov000_021a98a8(((u32)(b[0]<<26)>>26))){
if(((u32)(b[0]<<26)>>26)==1)vb<<=1;else vb=(vb*3)>>1;
if((u32)(M2C_FIELD(b,u16 *,6)<<16)>>27){
map=*gCurrentMap;index=a[1]+M2C_FIELD(map+a[2]*2,u16 *,0x3758);
if(func_ov000_021a90a8(M2C_FIELD(map+index,u8 *,0x508),b[1],b[2])!=1){
map=*gCurrentMap;index=b[1]+M2C_FIELD(map+b[2]*2,u16 *,0x3758);terrain=M2C_FIELD(map+index,u8 *,0x1420)&31;
if(terrain==15)value<<=3;else if(terrain==17)value<<=2;else if(terrain==18||terrain==19||terrain==22)value<<=1;
if(func_ov000_021a8a88(b)==1){
if(!M2C_FIELD((*gCurrentMap),s16 *,28390)&&((u32)(M2C_FIELD(b,u16 *,6)<<25)>>25)<50)vb=func_0207c8ec(vb*50,((u32)(M2C_FIELD(b,u16 *,6)<<25)>>25));
value<<=1;
map=*gCurrentMap;index=b[1]+M2C_FIELD(map+b[2]*2,u16 *,0x3758);
if((M2C_FIELD(map+index,u8 *,0x1420)&31)==15)value<<=1;
}
}
}
}
if(((u32)(b[0]<<26)>>26)==21)value*=3;
else if(func_ov000_021a9904(((u32)(b[0]<<26)>>26))==2){if(!b[12])vb>>=2;else if(M2C_FIELD((*gCurrentMap),s16 *,28390))vb>>=1;}
else {if(func_ov000_021a98e4(((u32)(b[0]<<26)>>26))==0)value<<=1;else if(func_ov000_021a98e4(((u32)(b[0]<<26)>>26))==1)value*=3;}
if(vb*value-va*2<0){if(func_ov000_021a97d0(((u32)(b[0]<<26)>>26),((u32)(a[0]<<26)>>26))>1)goto failed;if(M2C_FIELD((*gCurrentMap),s16 *,28358))va=0;else {failed:return 0;}}
vb+=(vb*func_ov000_0217c9f4(b))>>5;
if(cost<=50&&!M2C_FIELD((u8 *)(*gCurrentMap)+(pos[0]+M2C_FIELD((u8 *)(*gCurrentMap)+pos[1]*2,u16 *,0x3758)),u8 *,0x2d48)&&!(M2C_FIELD(a,u16 *,4)&32)){n=M2C_FIELD(data_ov000_021b5c00+((u32)(b[0]<<26)>>26)*112,u16 *,0);if((u32)n<800)vb+=n;else vb+=800;}
n=(vb*value-va*2)>>3;if(n&~0xffff)n=0xffff;if(!n)n=1;return n;
}
