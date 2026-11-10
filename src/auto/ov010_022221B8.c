/* 14 functions from 0x022221B8 to 0x02223114 (ov010), found by ds-decomp. */
#include "common.h"

typedef struct UnkOv010Header { s16 unk0; u8 unk2; u8 unk3; } UnkOv010Header;

static inline u8 Encode2BitSample(s16 sample,UnkOv010Header *state) {
 extern s16 data_ov010_0222bd78[];
 extern s8 data_ov010_0222bd5c[];
 s32 index=state->unk2,pred=state->unk0,step=data_ov010_0222bd78[index],diff=sample-pred,code;
 if(diff<0){code=2;diff=-diff;}else code=0;
 if(diff>=step)code|=1;
 if(!(code&1))step=0;
 if(code&2)step=-step;
 pred+=step;
 if(pred < -32768)pred=-32768;
 if(pred > 32767)pred=32767;
 index+=data_ov010_0222bd5c[code];
 if(index<0)index=0;else if(index>88)index=88;
 state->unk0=pred;state->unk2=index;
 return code;
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
void func_ov010_022221b8(void *arg0,s32 arg1,s32 arg2,void *arg3){
u32 i,n=(u32)arg2>>2;u8 packed;u8 *out=arg0;s16 *in=(s16*)arg1;
i=0;if(!n)return;do{
packed=Encode2BitSample(in[0],arg3);
packed|=Encode2BitSample(in[1],arg3)<<2;
packed|=Encode2BitSample(in[2],arg3)<<4;
packed|=Encode2BitSample(in[3],arg3)<<6;
*out++=packed;in+=4;i++;
}while(i<n);
}
#pragma pop
void func_ov010_022223e8(void *arg0,s32 arg1,s32 arg2,s32 arg3) {
void func_ov010_02221fa0(void *,s32,s32,UnkOv010Header *);
void func_ov010_02221600(void *,s32,s32,UnkOv010Header *);
void func_ov010_02221320(void *,s32,s32,UnkOv010Header *);
UnkOv010Header header;
header.unk0=M2C_FIELD(arg0,s16 *,0);
header.unk2=M2C_FIELD(arg0,u8 *,2);
switch(arg3) {
case 2: func_ov010_02221fa0((u8 *)arg0+4,arg1,arg2-4,&header); return;
case 3: func_ov010_02221600((u8 *)arg0+4,arg1,arg2-4,&header); return;
case 4: func_ov010_02221320((u8 *)arg0+4,arg1,arg2-4,&header); return;
}
}

void func_ov010_02222454(void *arg0,s32 arg1,s32 arg2,void *arg3,s32 arg4) {
void func_ov010_022221b8(void *,s32,s32,void *);
void func_ov010_02221a94(void *,s32,s32,void *);
void func_ov010_02221474(void *,s32,s32,void *);
M2C_FIELD(arg0,s16 *,0)=M2C_FIELD(arg3,s16 *,0);
M2C_FIELD(arg0,u8 *,2)=M2C_FIELD(arg3,u8 *,2);
M2C_FIELD(arg0,u8 *,3)=0;
switch(arg4) {
case 2: func_ov010_022221b8((u8 *)arg0+4,arg1,arg2,arg3); return;
case 3: func_ov010_02221a94((u8 *)arg0+4,arg1,arg2,arg3); return;
case 4: func_ov010_02221474((u8 *)arg0+4,arg1,arg2,arg3); return;
}
}

#pragma opt_strength_reduction off
s32 func_ov010_022224b4(void){
s32 func_020070a4(void); void func_ov010_02225174(void);void func_ov010_02223654(u32);void func_ov010_0222393c(void *,u32,s32);void func_ov010_022232e0(void);void func_ov010_02225288(void);
extern M2C_UNK data_ov010_0222c960,data_ov010_0222c000,data_ov010_0222edc0;extern u8 data_ov010_0222be2c[];extern void *data_ov010_0222c98c[];extern u8 data_ov010_0222c998[];
s32 i; s32 saved; s32 n; u8 x,y; u8 *t;
saved=func_020070a4();
M2C_FIELD(&data_ov010_0222c960,u16 *,0)=saved; data_ov010_0222c000=1;
M2C_FIELD(&data_ov010_0222c960,s32 *,0x20)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,4)=0;
if(M2C_FIELD(&data_ov010_0222edc0,s32 *,16)==1)M2C_FIELD(&data_ov010_0222c960,s32 *,0x1c)=0;
else M2C_FIELD(&data_ov010_0222c960,s32 *,0x1c)=4;
M2C_FIELD(&data_ov010_0222c960,s32 *,0x24)=0x440;
n=M2C_FIELD(&data_ov010_0222c960,s32 *,0x1c);
t=data_ov010_0222be2c+n*2;
x=t[1];
y=t[0];
M2C_FIELD(&data_ov010_0222c960,s32 *,12)=x+y*68+12;
M2C_FIELD(&data_ov010_0222c960,s32 *,3840)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,3844)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,3852)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,3848)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,3856)=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,3860)=0;
func_ov010_02225174();
i=0;goto test;loop:{data_ov010_0222c98c[i]=0;func_ov010_02223654(i);func_ov010_0222393c(data_ov010_0222c998+i*0x94,i,-1);i++;}test:if((u32)i<3)goto loop;
func_ov010_022232e0();func_ov010_02225288();return 1;
}
#pragma opt_strength_reduction reset
void func_ov010_022225b0(s32 arg0) {
    extern M2C_UNK data_ov010_0222c960;
    M2C_FIELD(&data_ov010_0222c960, void **, 0x20) = NULL;
}

#pragma optimization_level 2
s32 func_ov010_022225c4(void *p){
void func_ov010_0222393c(void*,u32,s32);
void func_ov010_02223654(u32);
void func_ov010_02224f28(void);
s32 func_020070a4(void);
extern s32 data_ov010_0222c960;
extern void *data_ov010_0222c98c[];
extern u8 data_ov010_0222c998[];
s32 i;
if(!p)return 0;
if(M2C_FIELD(&data_ov010_0222c960,s32*,0x20)==3)return 0;
if(M2C_FIELD(p,s32*,12)!=2&&M2C_FIELD(p,s32*,12)!=3)return 0;
i=0;goto test1;
loop1:if(data_ov010_0222c98c[i]==p)return 1;i++;
test1:if((u32)i<3)goto loop1;
i=0;goto test2;
loop2:if(!data_ov010_0222c98c[i]){data_ov010_0222c98c[i]=p;goto found;}i++;
test2:if((u32)i<3)goto loop2;
found:
M2C_FIELD(&data_ov010_0222c960,s32*,0x20)++;
M2C_FIELD(&data_ov010_0222c960,u32*,4)|=M2C_FIELD(p,u32*,8);
func_ov010_0222393c((void *)((s32)data_ov010_0222c998+i*0x94),i,M2C_FIELD(p,u8*,5));
func_ov010_02223654(i);
if(M2C_FIELD(p,s32*,12)!=2)return 1;
if(M2C_FIELD(&data_ov010_0222c960,s32*,0x20)==1){
func_ov010_02224f28();
M2C_FIELD(&data_ov010_0222c960,u16*,0)=func_020070a4();
M2C_FIELD(&data_ov010_0222c960,u16*,0x10)=0;
M2C_FIELD(&data_ov010_0222c960,u8*,0x12)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0x14)=1;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf00)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf04)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf0c)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf08)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf10)=0;
M2C_FIELD(&data_ov010_0222c960,s32*,0xf14)=0;
}
return 1;
}
#pragma optimization_level reset
void func_ov010_022226fc(void *arg0) {
extern void *data_ov010_0222c98c[]; extern u8 data_ov010_0222c998[]; extern M2C_UNK data_ov010_0222c960;
void func_ov010_022239c8(void *); void func_ov010_0222369c(u32); void func_ov010_02223314(u32); void func_ov010_02224f28(void);
u32 i;
for(i=0;i<3;i++) {
if(data_ov010_0222c98c[i]==arg0) {
s32 count=M2C_FIELD(&data_ov010_0222c960,s32 *,0x20);
data_ov010_0222c98c[i]=0;
M2C_FIELD(&data_ov010_0222c960,s32 *,0x20)=count-1;
func_ov010_022239c8(data_ov010_0222c998+i*0x94);
func_ov010_0222369c(i);
func_ov010_02223314(i);
M2C_FIELD(&data_ov010_0222c960,u32 *,4)=M2C_FIELD(&data_ov010_0222c960,u32 *,4) & ~M2C_FIELD(arg0,u32 *,8);
break;
}
}
if(M2C_FIELD(&data_ov010_0222c960,s32 *,0x20)==0) {
M2C_FIELD(&data_ov010_0222c960,s32 *,0x14)=1;
func_ov010_02224f28();
M2C_FIELD(&data_ov010_0222c960,s32 *,4)=0;
}
}

#pragma push
#pragma opt_common_subs off
s32 func_ov010_022227b0(void *src,s32 len){
extern M2C_UNK data_ov010_0222c960; extern void *data_ov010_0222c98c[];extern u8 data_ov010_0222cfa0[];
void func_02007ef4(void *,void *,s32);s64 func_02007004(void);s32 func_02072088(s64,s32,s32);
s32 found=0; s32 off;u8 *p;u16 n;s32 mode;u32 magic=0x5f564354;
if(len!=M2C_FIELD(&data_ov010_0222c960,s32 *,0x24))return found;
if(!M2C_FIELD(&data_ov010_0222c960,s32 *,0x20))return found;
{s32 i=0;goto test;loop:{if(data_ov010_0222c98c[i] && M2C_FIELD(data_ov010_0222c98c[i],s32 *,12)==2){found=1;goto done;}i++;}test:if((u32)i<3)goto loop;done:;}
if(!found)return 0;
if(M2C_FIELD(&data_ov010_0222c960,u32 *,0xf04)&1){magic=0x5f564354;off=0;}else{magic=0x5f564354;off=0x460;}
p=data_ov010_0222cfa0+off;
mode=M2C_FIELD(&data_ov010_0222c960,s32 *,0x1c);
M2C_FIELD(p,u32 *,0)=magic;
if(mode>=2)func_02007ef4(src,p+16,len);else func_02007ef4(src,p+12,len);
n=M2C_FIELD(&data_ov010_0222c960,u16 *,0);
M2C_FIELD(p,u8 *,4)=64;
M2C_FIELD(&data_ov010_0222c960,u16 *,0)=n+1;
M2C_FIELD(p,u16 *,6)=n;
M2C_FIELD(p,s32 *,8)=func_02072088(func_02007004(),64,0);
{u32 count=M2C_FIELD(&data_ov010_0222c960,u32 *,0xf04);M2C_FIELD(&data_ov010_0222c960,s32 *,0xf04)=count+1;}
return 1;
}

#pragma optimization_level 3
s32 func_ov010_022228c0(void *dst,s32 size,u32 group,s32 *flag){
s32 func_ov010_0222392c(s32);
s64 func_02007004(void);
void *func_ov010_02223878(s32);
s32 func_ov010_022239f4(void *,void *);
void func_02007ef4(void *,void *,s32);
void func_ov010_02224ef8(void *);
extern u8 data_ov010_0222c998[];
s32 count;
void *item;
void *state=data_ov010_0222c998+group*0x94;
s32 first=1;
u64 now;
count=func_ov010_0222392c(group);
while(count!=0){
now=func_02007004();
item=func_ov010_02223878(group);
if(!item)goto empty;
if(M2C_FIELD(item,u64 *,0x46c)>now+0x34){
if(M2C_FIELD(item,s32 *,0x45c)==0 && M2C_FIELD(state,void **,0x3c)!=0){
M2C_FIELD(state,s32 *,0x20)++;
func_02007ef4(M2C_FIELD(M2C_FIELD(state,void **,0x3c),void **,0x474),dst,size);
func_ov010_02224ef8(M2C_FIELD(state,void **,0x3c));
M2C_FIELD(state,void **,0x3c)=0;
if(flag)*flag|=1<<M2C_FIELD(item,u8 *,0x10);
return 1;
}
return 0;
}
if(now>M2C_FIELD(item,u64 *,0x46c)+0x8b4c){
M2C_FIELD(state,u32 *,0x58)=M2C_FIELD(item,u32 *,0x18);
count=func_ov010_022239f4(state,item);
func_ov010_02223878(group);
first=0;
}else{

if(M2C_FIELD(state,u32 *,0x58)+1!=M2C_FIELD(item,u32 *,0x18) && M2C_FIELD(state,u32 *,0x58)!=0 && M2C_FIELD(state,u32 *,0x58)<=M2C_FIELD(item,u32 *,0x18)){
if(M2C_FIELD(item,s32 *,0x45c)==0)M2C_FIELD(state,s32 *,0x14)++;
}
M2C_FIELD(state,u32 *,0x58)=M2C_FIELD(item,u32 *,0x18);
if(first && M2C_FIELD(state,s32 *,0x70)){
count=func_ov010_022239f4(state,item);
func_ov010_02223878(group);
M2C_FIELD(state,s32 *,0x70)--;
}else{
u32 t=(u32)(now-M2C_FIELD(item,u64 *,0x464));
u32 x=M2C_FIELD(state,u32 *,0x28);
u32 z=t-x;
M2C_FIELD(state,u32 *,0x28)=t;
z-=M2C_FIELD(state,u32 *,0x28);
{u32 smooth=t+(z>>4);M2C_FIELD(state,u32 *,0x2c)=smooth;M2C_FIELD(state,u32 *,0)=smooth;}
func_02007ef4(M2C_FIELD(item,void **,0x474),dst,size);
func_ov010_022239f4(state,item);
if(flag)*flag|=1<<M2C_FIELD(item,u8 *,0x10);
return 1;
}
}
continue;
empty:
M2C_FIELD(state,s32 *,8)=count;return 0;
}
if(M2C_FIELD(state,void **,0x3c)){func_ov010_02224ef8(M2C_FIELD(state,void **,0x3c));M2C_FIELD(state,void **,0x3c)=0;}
return 0;
}
#pragma optimization_level reset
s32 func_ov010_02222b0c(void *p,s32 size,s32 *out){
s32 func_ov010_022228c0(void*,s32,u32,s32*);
void func_ov010_02225558(void*,void*,void*,s32);
void func_02007e98(s32,void*,s32);
void func_ov010_02225304(void*,s32);
extern s32 data_ov010_0222c960;
extern u8 data_ov010_0222cb54[];
s32 result;u32 i,j;
if(out)*out=0;
result=0;
if(size==M2C_FIELD(&data_ov010_0222c960,s32*,0x24)&&M2C_FIELD(&data_ov010_0222c960,s32*,0x20)){
for(i=0;i<3;i++){
if(func_ov010_022228c0(p,size,i,out)==1){result=1;break;}
}
if(result){
j=i+1;
if(j==3)result=1;
else for(;j<3;j++){
if(func_ov010_022228c0(data_ov010_0222cb54,size,j,out)==1)
func_ov010_02225558(p,data_ov010_0222cb54,p,size);
}
}else func_02007e98(0,p,size);
}else{func_02007e98(0,p,size);result=0;}
if(M2C_FIELD(&data_ov010_0222c960,s32*,0x18))func_ov010_02225304(p,size);
return result;
}

#pragma pop
s32 func_ov010_02222c28(s32 arg0) {
extern M2C_UNK data_ov010_0222edc0; extern u8 data_ov010_0222be2d[]; extern u8 data_ov010_0222be2c[]; extern M2C_UNK data_ov010_0222c960;
if(arg0>=5) return 0;
if(M2C_FIELD(&data_ov010_0222edc0,s32 *,0x10)!=1 && (u32)arg0<=1) return 0;
M2C_FIELD(&data_ov010_0222c960,s32 *,12)=data_ov010_0222be2d[arg0*2]+data_ov010_0222be2c[arg0*2]*68+12;
M2C_FIELD(&data_ov010_0222c960,s32 *,0x1c)=arg0;
M2C_FIELD(&data_ov010_0222c960,s16 *,0x10)=0;
M2C_FIELD(&data_ov010_0222c960,u8 *,0x12)=0;
return 1;
}

void func_ov010_02222c9c(s32 arg0) {
    extern M2C_UNK data_ov010_0222c960;
    M2C_FIELD(&data_ov010_0222c960, s32 *, 0x18) = arg0;
}

#pragma push
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
s32 func_ov010_02222cac(void) {
extern M2C_UNK data_ov010_0222c960;
extern u8 data_ov010_0222cfa0[];
extern s32 data_ov010_0222c000;
extern M2C_UNK data_ov010_0222c970;
extern M2C_UNK data_ov010_0222edc0;
u32 func_ov010_0222519c(void *,u32);
void func_ov010_02225538(void *,u32,u32);
s32 func_ov010_02224f94(u32,u32,s32);
void func_ov010_022234f8(void *,void *,u32);
void func_ov010_022235f8(void *,void *,u32);
s32 func_02076614(void);
u32 count;
u32 flags;
u8 *buffer,*packet;
u32 value,hardware;
s32 mode;
mode=M2C_FIELD(&data_ov010_0222c960,s32 *,0x1c);
count=M2C_FIELD(&data_ov010_0222c960,u32 *,0xf04)-M2C_FIELD(&data_ov010_0222c960,u32 *,0xf00);
if(count>1){M2C_FIELD(&data_ov010_0222c960,u32 *,0xf00)=M2C_FIELD(&data_ov010_0222c960,u32 *,0xf04)-1;count=1;}
if(count==0)return 0;
packet=data_ov010_0222cfa0+((M2C_FIELD(&data_ov010_0222c960,u32 *,0xf00)&1)?0:0x460);
buffer=packet+12;
if(mode>=2)buffer+=4;
value=func_ov010_0222519c(buffer,M2C_FIELD(&data_ov010_0222c960,u32 *,0x24));
*(volatile u16 *)0x040002b0=0;
*(volatile u32 *)0x040002b8=value;
while(*(volatile u16 *)0x040002b0&0x8000){}
hardware=*(volatile u32 *)0x040002b4;
if(M2C_FIELD(&data_ov010_0222c960,s32 *,0x18))func_ov010_02225538(buffer,M2C_FIELD(&data_ov010_0222c960,u32 *,0x24),hardware);
packet[5]=mode;
if(data_ov010_0222c000){
s32 result=func_ov010_02224f94(value,hardware,0);
M2C_FIELD(&data_ov010_0222c960,s32 *,0x28)=result;
switch(result){
case 0: count=M2C_FIELD(&data_ov010_0222c960,u32 *,0xf00)+1;M2C_FIELD(&data_ov010_0222c960,u32 *,0xf00)=count;return 0;
case 1: packet[5]|=0x80;break;
case 3: packet[4]=0x41;break;
}
}
if(!data_ov010_0222c000 && M2C_FIELD(&data_ov010_0222c960,s32 *,8)){
flags=packet[5];M2C_FIELD(&data_ov010_0222c960,s32 *,8)=0;packet[5]=flags|0x80;
}
if(M2C_FIELD(&data_ov010_0222c960,s32 *,0x14)){
flags=packet[5];M2C_FIELD(&data_ov010_0222c960,s32 *,0x14)=0;packet[5]=flags|0x80;
}
if(mode>=2){
if(packet[5]&0x80){M2C_FIELD(&data_ov010_0222c960,s16 *,0x10)=0;M2C_FIELD(&data_ov010_0222c960,u8 *,0x12)=0;}
func_ov010_02222454(buffer-4,(s32)buffer,M2C_FIELD(&data_ov010_0222c960,u32 *,0x24)>>1,&data_ov010_0222c970,mode);
}else if(mode==1){
func_ov010_022234f8(buffer,buffer,M2C_FIELD(&data_ov010_0222c960,u32 *,0x24)>>1);
}else if(mode==0){
func_ov010_022235f8(buffer,buffer,M2C_FIELD(&data_ov010_0222c960,u32 *,0x24)>>1);
}
count=M2C_FIELD(&data_ov010_0222c960,u32 *,4);
M2C_FIELD(&data_ov010_0222c960,u32 *,0xf0c)=count;
count&=~(1U<<M2C_FIELD(&data_ov010_0222edc0,u8 *,0));
M2C_FIELD(&data_ov010_0222c960,u32 *,0xf0c)=count;
M2C_FIELD(&data_ov010_0222c960,s32 *,0xf14)=func_02076614()-1;
if(M2C_FIELD(&data_ov010_0222c960,s32 *,0xf14)>7)return 0;
M2C_FIELD(&data_ov010_0222c960,s32 *,0xf10)=0;
return (s32)packet;
}
#pragma pop
s32 func_ov010_02222f28(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *func_ov010_02224eb8(void);
    void func_ov010_0222369c(u32);
    void func_ov010_02223314(u32);
    void func_ov010_022236e4(void);
    void func_ov010_0222335c(void);
    s32 func_ov010_02223b18(void *, void *);
    void func_ov010_022233ac(void *);
    void func_ov010_02224ef8(void *);
    void MI_CpuCopy8(void *, void *, s32);
    extern M2C_UNK data_ov010_0222c960;
    extern u8 data_ov010_0222c998[];
    extern u8 data_ov010_0222be2d[];
    extern u8 data_ov010_0222be2c[];

    void *item;
    u8 *slot;
    s32 id;
    s32 a4;
    s32 a2;
    s32 a1;
    s32 a0;
    s32 a3;
    u32 i;
    u8 *p;
    s32 len;
    void *src;

    a4 = arg4;
    a2 = arg2;
    a1 = (s32)arg1;
    a0 = arg0;
    a3 = arg3;

    slot = 0;
    if (M2C_FIELD(&data_ov010_0222c960, s32 *, 0x20) == 0)
        return (s32)slot;

    p = data_ov010_0222c998;
    i = 0;
    do {
        if (a0 == M2C_FIELD(p, s32 *, 0x38)) {
            slot = data_ov010_0222c998 + i * 0x94;
            break;
        }
        i++;
        p += 0x94;
    } while (i < 3);
    if (!slot)
        return 0;

    if (M2C_FIELD(a1, u8 *, 4) == 0x41) {
        M2C_FIELD(slot, s32 *, 0x30) = M2C_FIELD(a1, u16 *, 6);
        M2C_FIELD(slot, s32 *, 0x4c) = 0;
        M2C_FIELD(slot, s32 *, 0x6c) = 1;
        return 0;
    }
    if (M2C_FIELD(a1, u8 *, 4) != 0x40)
        return 0;

    id = M2C_FIELD(a1, u8 *, 5) & 0x7f;
    M2C_FIELD(slot, s32 *, 0x24) = id;
    if (id >= 5)
        return 0;

    if (a2 != (s32)data_ov010_0222be2d[id * 2] +
                (s32)data_ov010_0222be2c[id * 2] * 0x44 + 0xc)
        return 0;

    if (!(M2C_FIELD(&data_ov010_0222c960, u32 *, 4) &
          (a0 ? (1u << a0) : 1u)))
        return 0;

    item = func_ov010_02224eb8();
    if (!item) {
        func_ov010_0222369c((u32)M2C_FIELD(slot, s32 *, 0x34));
        func_ov010_02223314((u32)M2C_FIELD(slot, s32 *, 0x34));
        item = func_ov010_02224eb8();
        if (!item) {
            func_ov010_022236e4();
            func_ov010_0222335c();
            item = func_ov010_02224eb8();
        }
    }
    if (!item)
        return 0;

    len = a2 - 0xc;
    src = (u8 *)item + 0x45c - len;
    MI_CpuCopy8((u8 *)a1 + 0xc, src, len);

    M2C_FIELD(item, u8 *, 0x11) = (u8)M2C_FIELD(slot, s32 *, 0x34);
    M2C_FIELD(item, s32 *, 0xc) = id;
    M2C_FIELD(item, void **, 0x474) = src;
    M2C_FIELD(item, s32 *, 0x14) = len;
    M2C_FIELD(item, s32 *, 0x464) = a3;
    M2C_FIELD(item, s32 *, 0x468) = a4;
    M2C_FIELD(item, u8 *, 0x10) = (u8)a0;
    M2C_FIELD(item, u32 *, 0x45c) = (u32)(M2C_FIELD(a1, u8 *, 5) & 0x80);
    M2C_FIELD(item, u32 *, 0x460) = M2C_FIELD(a1, u32 *, 8);
    M2C_FIELD(item, u32 *, 0x18) = M2C_FIELD(a1, u16 *, 6);

    if (func_ov010_02223b18(slot, item) == 0) {
        func_ov010_02224ef8(item);
        return 0;
    }
    func_ov010_022233ac(item);
    return 1;
}

