/* 8 functions from 0x021A0624 to 0x021A11B0 (ov000), found by ds-decomp. */
#include "common.h"
#include "ov000_unit_entry.h"
extern u8 data_ov000_021e00ae[];
extern u8 data_ov000_021b5c0f[];
extern void **gCurrentMap;

u8 func_ov000_021a0624(s32 a,s32 b) {
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
s32 func_ov000_021a98a8(void);
s32 count=0;
s32 i;
void *base=*gCurrentMap;
u16 start=data_ov000_021aeef4[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++) {
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[i];
if(entry->unk0!=0 && i!=a && func_ov000_021a98a8()!=0 && b==entry->unkB_4) count++;
}
return count;
}

s32 func_ov000_021a06e4(M2C_UNK arg0) {
s32 func_ov000_021a98a8(); s32 func_ov000_021a98e4(M2C_UNK); s32 func_ov000_021a9904(M2C_UNK);
extern u16 data_02168f14; extern void **gCurrentMap; extern void *data_ov000_021df578;
void *p;
if(func_ov000_021a98a8()!=0 || func_ov000_021a9904(arg0)==2)return 0;
if(!(((u32)(data_02168f14<<29)>>29)&255)) {
p=*gCurrentMap;
switch(M2C_FIELD(p,u16*,0x5142)) {case 0xae: if(M2C_FIELD(p,u16*,0x52a4)==3)return 10; break;default:break;}
}
if(M2C_FIELD(data_ov000_021df578,u8*,2)==12)return 5;
p=*gCurrentMap;
if(M2C_FIELD(p,u8*,0x5156)!=0 || M2C_FIELD(p,u8*,0x5158)==2) {
if(func_ov000_021a98e4(arg0)==1)return 4;
}
return 0;
}

void func_ov000_021a07c0(s8 arg0) {
s32 func_ov000_021a43e8(); s32 func_ov000_021a98e4(M2C_UNK);
extern u8 data_ov000_021df7d0[]; extern void *data_ov000_021df578; extern u8 *data_ov000_021df580;
extern u8 data_ov000_021e00af[],data_ov000_021dfd98[],data_ov000_021dfd99[],data_ov000_021dfd9a[];
extern s8 data_ov000_021e00b0[];
register s32 offset; s32 index; register u32 flags;
data_ov000_021df7d0[7]=func_ov000_021a06e4(data_ov000_021df7d0[6]);
offset=arg0*12;
data_ov000_021e00af[offset]=252;
M2C_FIELD(data_ov000_021df578,u8*,7)++;
M2C_FIELD(data_ov000_021df578,u8*,4)=arg0;
flags=data_ov000_021b5c0f[(s16)data_ov000_021df7d0[6]*112];
if((flags&7) && func_ov000_021a43e8()==0){
if(func_ov000_021a98e4(data_ov000_021df7d0[6])==0){index=data_ov000_021e00b0[offset];data_ov000_021dfd98[index*8]++;}
if(func_ov000_021a98e4(data_ov000_021df7d0[6])==1){index=data_ov000_021e00b0[offset];data_ov000_021dfd99[index*8]++;}
if(data_ov000_021df7d0[6]==26){index=data_ov000_021e00b0[offset];data_ov000_021dfd9a[index*8]++;}
}
M2C_FIELD(data_ov000_021df578,u8*,3)=1;
*data_ov000_021df580=5;
}

void func_ov000_021a08fc(void) {
s32 func_ov000_021a18d8(void);s32 func_ov000_021a0bec(void);
extern void *data_ov000_021df578;extern u16 data_ov000_021aeef4[];
s32 i;UnkStruct_ov000_021A860C *entry;
M2C_FIELD(data_ov000_021df578,u8 *,0)=func_ov000_021a18d8();
M2C_FIELD(data_ov000_021df578,u8 *,1)=func_ov000_021a0bec();
M2C_FIELD(data_ov000_021df578,u8 *,7)=0;
M2C_FIELD(data_ov000_021df578,s32 *,16)=0;
for(i=data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+1;i<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++){
entry=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[i];
if(entry->unk0){
M2C_FIELD(data_ov000_021df578,u8 *,7)++;
if(entry->unk0==21){
if(M2C_FIELD(entry,u8 *,12))M2C_FIELD(data_ov000_021df578,s32 *,16)+=func_ov000_021a0b20(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),0,(u8 *)*gCurrentMap+0x59a4+M2C_FIELD(entry,u8 *,12)*14);
if(M2C_FIELD(entry,u8 *,13))M2C_FIELD(data_ov000_021df578,s32 *,16)+=func_ov000_021a0b20(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),0,(u8 *)*gCurrentMap+0x59a4+M2C_FIELD(entry,u8 *,13)*14);
}
M2C_FIELD(data_ov000_021df578,s32 *,16)+=func_ov000_021a0b20(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),0,entry);
}
}
M2C_FIELD(data_ov000_021df578,s32 *,16)=M2C_FIELD(data_ov000_021df578,s32 *,16)*3>>1;
if(M2C_FIELD(data_ov000_021df578,s32 *,16)<1000)M2C_FIELD(data_ov000_021df578,s32 *,16)=1000;
M2C_FIELD(data_ov000_021df578,s32 *,20)=0;
M2C_FIELD(data_ov000_021df578,u8 *,5)=2;
M2C_FIELD(data_ov000_021df578,u8 *,12)=0;
}

s32 func_ov000_021a0aec(s32 a,s32 unused,s32 c) {
s32 func_020a7bbc(s32);
s32 func_020a886c(s32,s32);
s32 func_0207c8ec(s32,s32);
s32 n=func_020a7bbc(c);
return func_0207c8ec(n*(func_020a886c(a,0)+100),100);
}

s32 func_ov000_021a0b20(M2C_UNK arg0, M2C_UNK arg1, void *arg2) {
s32 func_0207c8ec(s32,M2C_UNK);
s32 func_020a2668(void *,u8,u8);
s32 func_020a7558(void *);
s32 func_ov000_021a0aec(M2C_UNK,M2C_UNK,s32);
s32 func_ov000_021a9214(void *,u8,u8);
s32 max,v,total;u32 n;
if(((u32)(M2C_FIELD(arg2,u16 *,6)<<25)>>25)>=91)return 0;
total=0;
if(!(M2C_FIELD(arg2,u16 *,4)&8))total+=func_020a2668(arg2,M2C_FIELD(arg2,u8 *,1),M2C_FIELD(arg2,u8 *,2));
if(func_ov000_021a9214(arg2,M2C_FIELD(arg2,u8 *,1),M2C_FIELD(arg2,u8 *,2)))total+=func_020a7558(arg2);
if(total==0)return 0;
n=(u32)(M2C_FIELD(arg2,u16 *,6)<<25)>>25;
if(n==0)v=0;else v=func_0207c8ec(n-1,10)+1;
max=10-v;
if(total>max)total=max;
return total*func_ov000_021a0aec(arg0,arg1,(u32)(M2C_FIELD(arg2,u8 *,0)<<26)>>26);
}

s32 func_ov000_021a10e4(s32 arg0,void *arg1) {
u32 type=data_ov000_021e00ae[arg0*12];
if(type==1){
u32 flags=data_ov000_021b5c0f[((u32)(M2C_FIELD(arg1,u8 *,0)<<26)>>26)*112];
if(flags&7){
void *base=*gCurrentMap;
s8 *row=((s8 **)((u8 *)base+0x52e8))[M2C_FIELD(arg1,u8 *,2)];
if(row[M2C_FIELD(arg1,u8 *,1)]<0)return 0;
}
if((flags&32) && M2C_FIELD(arg1,u8 *,12)==0)return 0;
}
if(type==3){
if(data_ov000_021b5c0f[((u32)(M2C_FIELD(arg1,u8 *,0)<<26)>>26)*112]&7)return 0;
}
return 1;
}

