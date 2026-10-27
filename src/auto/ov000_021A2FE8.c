/* 10 functions from 0x021A2FE8 to 0x021A3DAC (ov000), found by ds-decomp. */
#include "common.h"

typedef struct {
    u8 pad[8];
    u16 low : 14;
    u16 state : 2;
    u8 tail[4];
} UnkState_021a36e4;
#include "ov000_unit_entry.h"

s32 func_ov000_021a3210(void){
s32 func_0207c8ec(s32,s32);s32 func_020d2d18(u16,s32);
void func_ov000_021a07c0(s32);s32 func_ov000_021a2fe8(void);s32 func_ov000_021a6150(s32);s32 func_ov000_021a5ffc(s32);s32 func_ov000_021a88c8(s32);
extern void **gCurrentMap;extern void *data_ov000_021df580;extern void *data_ov000_021df578;extern void *data_ov000_021df57c;extern M2C_UNK data_ov000_021df7d0;
void *p=*gCurrentMap;u16 id=M2C_FIELD(p,u16 *,0x52a4);s32 r,t,v;u8 n;
if(func_020d2d18(id,19)*10>M2C_FIELD((u8 *)p+id*140,s32 *,0x67a4))return 0;
if(M2C_FIELD(data_ov000_021df580,u8 *,6)==1){n=M2C_FIELD(data_ov000_021df57c,u8 *,19);if(n && M2C_FIELD(*gCurrentMap,u16 *,0x52a2)>n)return 0;}
if(func_ov000_021a2fe8()==1)return 1;r=func_ov000_021a6150(2);if(r==-1){r=func_ov000_021a5ffc(2);if(r==-1)return 0;}
v=func_ov000_021a88c8(19);
n=M2C_FIELD(data_ov000_021df578,u8 *,8);if(!n)return 0;
if(func_0207c8ec(v*100,n)<M2C_FIELD(data_ov000_021df57c,u8 *,11)){
M2C_FIELD(&data_ov000_021df7d0,u8 *,6)=19;
}else{return 0;}
func_ov000_021a07c0(r);return 1;
}

s32 func_ov000_021a3364(void){
s32 func_0207c8ec(s32,s32);s32 func_020d2d18(u16,s32);
void func_ov000_021a07c0(s32);s32 func_ov000_021a61cc(s32);s32 func_ov000_021a88c8(s32);
extern void **gCurrentMap;extern void *data_ov000_021df578;extern void *data_ov000_021df57c;extern M2C_UNK data_ov000_021df7d0;
void *p=*gCurrentMap;u16 id=M2C_FIELD(p,u16 *,0x52a4);s32 r,t,v;u8 n;
if(func_020d2d18(id,13)*10>M2C_FIELD((u8 *)p+id*140,s32 *,0x67a4))return 0;
n=M2C_FIELD(data_ov000_021df57c,u8 *,18);
if(n && M2C_FIELD(*gCurrentMap,u16 *,0x52a2)>n)return 0;
r=func_ov000_021a61cc(1);if(r==-1)return 0;
t=func_ov000_021a88c8(13);v=t+func_ov000_021a88c8(19);
n=M2C_FIELD(data_ov000_021df578,u8 *,8);if(!n)return 0;
if(func_0207c8ec(v*100,n)<M2C_FIELD(data_ov000_021df57c,u8 *,12)){
M2C_FIELD(&data_ov000_021df7d0,u8 *,6)=13;
}else{return 0;}
func_ov000_021a07c0(r);return 1;
}

u8 func_ov000_021a3484(s32 a) {
extern M2C_UNK data_ov000_021b5bfc;
extern M2C_UNK data_0212616c;
u8 result;
u32 row = M2C_FIELD(&data_ov000_021b5bfc,u8 *,0xa92);
s8 *table = M2C_FIELD(&data_0212616c, s8 **, 0x64) + row*32;
if (table[a&31] > 0) result=1; else result=0;
return result;
}

#pragma push
#pragma opt_strength_reduction off
void func_ov000_021a34bc(s32 arg0){
extern void **gCurrentMap;
u8 func_ov000_021a3484(s32);
s32 y,x; s8 value;void *base=*gCurrentMap;
y=0;
if(y>=M2C_FIELD(base,u16*,0x5146))return;
value=arg0;
do {
for(x=0;x<M2C_FIELD(base,u16*,0x5144);x++){
s8 *cell=M2C_FIELD((u8 *)base+y*4,s8 **,0x52e8)+x;
if(*cell>=0 && arg0!=*cell && func_ov000_021a3484(M2C_FIELD((u8 *)base+x+M2C_FIELD((u8 *)base+y*2,u16 *,0x3758),u8 *,0x1420))){
if(x!=0){cell=M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,0x52e8)+x; if(cell[-1]<0)cell[-1]=value;}
base=*gCurrentMap;
if(x!=M2C_FIELD(base,u16*,0x5144)-1){
cell=M2C_FIELD((u8 *)base+y*4,s8 **,0x52e8)+x;
if(cell[1]<0)cell[1]=value;
}
if(y!=0){cell=M2C_FIELD((u8 *)*gCurrentMap+y*4,s8 **,0x52e4);if(cell[x]<0)cell[x]=value;}
base=*gCurrentMap;
if(y!=M2C_FIELD(base,u16*,0x5146)-1){cell=M2C_FIELD((u8 *)base+y*4,s8 **,0x52ec);if(cell[x]<0)cell[x]=value;}
}
base=*gCurrentMap;
}
y++;
}while(y<M2C_FIELD(base,u16*,0x5146));
}
#pragma pop
s32 func_ov000_021a3644(s32 arg0) {
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
s32 count=0;
s32 i;
void *base=*gCurrentMap;
u16 start=data_ov000_021aeef4[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++) {
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)base+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && type==arg0 && entry->unkC[0]==0) count++;
}
return count;
}

s32 func_ov000_021a36e4(void) {
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
s32 func_ov000_021a98c8(s32);
s32 count=0;
s32 i;
void *base=*gCurrentMap;
u16 start=data_ov000_021aeef4[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++) {
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && func_ov000_021a98c8(type)!=0 && ((UnkState_021a36e4 *)entry)->state==2) count++;
}
return count;
}

s32 func_ov000_021a379c(void) {
extern void **gCurrentMap;
extern u16 data_ov000_021aeef4[];
s32 func_ov000_021a98c8(s32);
s32 count=0;
s32 i;
void *base=*gCurrentMap;
u16 start=data_ov000_021aeef4[M2C_FIELD(base,u16 *,0x52a4)];
for(i=start+1;i<data_ov000_021aeef4[M2C_FIELD(*gCurrentMap,u16 *,0x52a4)]+0x33;i++) {
UnkStruct_ov000_021A860C *entry=&((UnkStruct_ov000_021A860C *)((u8 *)*gCurrentMap+0x59a4))[i];
u32 type=entry->unk0;
if(type!=0 && func_ov000_021a98c8(type)==0 && ((UnkState_021a36e4 *)entry)->state==2) count++;
}
return count;
}

s32 func_ov000_021a3c84(void){
s32 func_020d2d18(u16,s32);s32 func_ov000_021a43a0(s32);s32 func_ov000_021a3854(void);
s32 func_ov000_021a6150(s32);s32 func_ov000_021a5ffc(s32);s32 func_ov000_021a88c8(s32);void func_ov000_021a07c0(s32);
extern void **gCurrentMap;extern M2C_UNK data_ov000_021df7d0;
void *p;u16 id;s32 r,a,b,n,x,y,z;
if(!func_ov000_021a43a0(1))return 0;
p=*gCurrentMap;id=M2C_FIELD(p,u16 *,0x52a4);
if(func_020d2d18(id,25)*10>M2C_FIELD((u8 *)p+id*140,s32 *,0x67a4))return 0;
if(func_ov000_021a3854()==1)return 1;
r=func_ov000_021a6150(3);if(r==-1){r=func_ov000_021a5ffc(3);if(r==-1)return 0;}
a=func_ov000_021a88c8(24);b=func_ov000_021a88c8(25);
n=func_ov000_021a36e4();if(!n)return 0;
if(a+b){x=func_ov000_021a3644(24);y=func_ov000_021a3644(25)+1;z=x-(func_ov000_021a379c()>>2);if(z<0)z=0;if(n<(y+z)*4)return 0;}
M2C_FIELD(&data_ov000_021df7d0,u8 *,6)=25;func_ov000_021a07c0(r);return 1;
}

