/* 5 functions from 0x021E771C to 0x021E8654 (ov003), found by ds-decomp. */
#include "common.h"
extern u8 data_ov003_0220f12c[];
static inline void ov003_refresh_sprite(void *sprite) {
s32 func_020aae10(void *);s32 func_020aae44(void *);
void func_02087d84(void *,s32,s16,s16,u16,u16);
u8 active=M2C_FIELD(M2C_FIELD(sprite,void **,0x64),u8 *,0x12)!=0;
if(active){s16 y=M2C_FIELD(sprite,s16 *,0x52);s16 x=M2C_FIELD(sprite,s16 *,0x50);s32 w=func_020aae10(sprite);s32 h=func_020aae44(sprite);func_02087d84(M2C_FIELD(sprite,void **,0x64),1,x,y,(u16)w,(u16)h);}
}

#pragma opt_propagation off
static inline void ov003_normalize_setting(void *p) {
if(M2C_FIELD(p,u8*,0x28)){
while(M2C_FIELD(p,s32*,0x18)>M2C_FIELD(p,s32*,0x1c))
M2C_FIELD(p,s32*,0x18)-=M2C_FIELD(p,s32*,0x1c)-M2C_FIELD(p,s32*,0x20)+1;
while(M2C_FIELD(p,s32*,0x18)<M2C_FIELD(p,s32*,0x20))
M2C_FIELD(p,s32*,0x18)+=M2C_FIELD(p,s32*,0x1c)-M2C_FIELD(p,s32*,0x20)+1;
}else{
s32 x=M2C_FIELD(p,s32*,0x18),hi=M2C_FIELD(p,s32*,0x1c);
if(x<=hi){hi=M2C_FIELD(p,s32*,0x20);if(x>=hi)hi=x;}
M2C_FIELD(p,s32*,0x18)=hi;
}
}
#pragma opt_propagation on
#pragma opt_propagation on
static inline s8 ov003_find_player(void *p,u8 id) {
u8 i;for(i=0;i<M2C_FIELD(p,u8*,4);i++)if(M2C_FIELD(p+i,u8*,0x74)==id)return (s8)i;return -1;
}


static inline s32 ov003_entries_differ(void *arg0) {
 u8 i; s32 entry; s32 count;
 i=0; count=M2C_FIELD(arg0,s8*,4)-1;
 for(;i<count;i++){entry=arg0+i*24; if(M2C_FIELD(entry,s32*,0x18)!=M2C_FIELD(entry,s32*,0x30))return 1;}
 return 0;
}

void func_ov003_021e771c(void *arg0, s32 arg1) {
s32 func_020cfb94(void); s32 func_020a22fc(s32); s32 func_ov003_02200808(u8);
s32 IsLinkSessionActive(void);u8 *func_02084e64(void);s32 GetReadyPlayerMask(void);
u8 *func_02084e24(s32); u8 GetLocalPlayerIdForOverlay(void);s32 GetPlayerTeam(s32);s32 func_020a2370(s32);
s32 InRange(s16,s16,s16); void StepCounter(s32,s32,s32);
void *func_020ab1c4(s32);s16 func_ov003_022004a8(u8);s32 Modulo(s32,s32);s32 Divide(s32,s32);
void func_020aab24(void *,s32,s32,s32,s32);void func_02088e84(void *,s32,s32,s32,s32);void MI_CpuCopy8(void *,void *,s32);u16 func_ov003_021e6e28(u8);void func_ov003_021e8354(s32,s32,s32);
s32 func_020aae10(void *);s32 func_020aae44(void *);void func_02087d84(void *,s32,s16,s16,u16,u16);
u8 *p=arg0,*remote,*q;void *sprite;u16 bounds[4];u16 first;s16 x,y,w,h;s32 next;u8 i,j,k,tmp,n; s8 id; s32 mask;
p[4]=func_020cfb94();p[5]=255;if(p[4]<2)p[4]=2;
for(i=0;i<4;i++)p[10+i]=func_ov003_02200808((u8)func_020a22fc(i+1));
if(IsLinkSessionActive()){
remote=func_02084e64();
for(i=0;i<4;i++){p[0x74+i]=255;p[10+i]=remote?remote[0x12+i]:12;}
i=0;mask=GetReadyPlayerMask();
for(id=0;id<4;id++){
if(mask&(1<<id)){
p[0x74+i]=(u8)id;
remote=func_02084e24(id);
tmp=remote?remote[13]:p[10+(u8)ov003_find_player(p,(u8)id)];
if(i!=id)p[10+(u8)id]=p[10+i];
p[10+i]=tmp;i++;
}
}
for(i=0;i<p[4];i++){
tmp=p[0x74+i];
if(tmp!=255&&i!=tmp&&tmp<=p[4]-1&&p[0x74+tmp]==255){
p[0x74+tmp]=tmp;p[0x74+i]=255;
n=p[10+i];p[10+i]=p[10+tmp];p[10+tmp]=n;
}
}
}
if(IsLinkSessionActive())p[7]=ov003_find_player(p,GetLocalPlayerIdForOverlay());else p[7]=0;
for(i=0;i<4;i++){
if(IsLinkSessionActive()){u8 empty=p[0x74+i]==255;p[14+i]=empty?2:1;}
else p[14+i]=GetPlayerTeam(i+1)==1?1:2;
q=p+i*24;ov003_normalize_setting(q);
M2C_FIELD(q,s32*,0x20)=1;ov003_normalize_setting(q);
q[0x28]=1;M2C_FIELD(q,s32*,0x18)=func_020a2370(i+1);ov003_normalize_setting(q);
}
if(!ov003_entries_differ(p)){
n=p[4]-1;
q=p+(s16)n*24;
next=M2C_FIELD(q,s32*,0x18)+1;
InRange((s16)next,(s16)M2C_FIELD(q,s32*,0x20),(s16)M2C_FIELD(q,s32*,0x1c));
M2C_FIELD(q,s32*,0x18)=next;ov003_normalize_setting(q);
if(!ov003_entries_differ(p)){StepCounter((s32)q+0x14,1,1);
if(!ov003_entries_differ(p)){StepCounter((s32)q+0x14,1,1);
if(!ov003_entries_differ(p)){StepCounter((s32)q+0x14,1,1);
if(!ov003_entries_differ(p)){StepCounter((s32)q+0x14,1,1);
if(!ov003_entries_differ(p)){StepCounter((s32)q+0x14,1,1);
if(!ov003_entries_differ(p))func_ov003_021e8354((s32)p,n,1);
}}}}}
}
tmp=p[10+p[7]];p[9]=tmp;p[8]=tmp;
for(i=0;i<26;i++){
M2C_FIELD(p+i*4,void **,0x78)=func_020ab1c4(arg1);
switch(i){
case 0:case 1:case 2:case 3:x=func_ov003_022004a8(i);y=16;w=56;h=56;break;
case 4:case 5:case 6:case 7:x=func_ov003_022004a8(i-4);y=72;w=56;h=16;break;
case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:
next=i-8;x=Modulo(next,4)*49+31;y=Divide(next,4)*18+90;w=47;h=16;break;
case 20:x=178;y=144;w=47;h=16;break;
case 21:case 22:case 23:case 24:x=func_ov003_022004a8(i-21)-1;y=128;w=58;h=16;break;
case 25:x=96;y=164;w=64;h=24;break;
}
sprite=M2C_FIELD(p+i*4,void **,0x78);
M2C_FIELD(sprite,u16 *,0x2e)=i;
func_020aab24(sprite,71,384,0,0);
sprite=M2C_FIELD(p+i*4,void **,0x78);
func_02088e84(sprite,x,y,x,y);ov003_refresh_sprite(sprite);
M2C_FIELD(sprite,s16 *,0x34)=x;M2C_FIELD(sprite,s16 *,0x36)=y;ov003_refresh_sprite(sprite);
M2C_FIELD(sprite,u32 *,0x40)=(((M2C_FIELD(sprite,u32 *,0x40)&~511)|(w&511))&0xfffc01ff)|((u32)(h<<23)>>14);
ov003_refresh_sprite(sprite);
MI_CpuCopy8(data_ov003_0220f12c+i*8,bounds,8);
if(IsLinkSessionActive()){
first=bounds[0];if(InRange((s16)first,4,7))bounds[0]=func_ov003_021e6e28((u8)first);
if(InRange((s16)bounds[1],4,7))bounds[1]=25;
}
sprite=M2C_FIELD(p+i*4,void **,0x78);
M2C_FIELD(sprite,u16 *,0x68)=bounds[0];M2C_FIELD(sprite,u16 *,0x6a)=bounds[1];M2C_FIELD(sprite,u16 *,0x6c)=bounds[2];M2C_FIELD(sprite,u16 *,0x6e)=bounds[3];
}
}

void func_ov003_021e82f0(s32 arg0, s32 arg1, s8 arg2) {
    M2C_FIELD((arg0 + arg1), s8 *, 0xA) = arg2;
}

u8 func_ov003_021e82fc(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg0 + arg1), u8 *, 0xA);
}

s32 EntriesDiffer(void *arg0) {
    u8 i;
    s32 entry;
    s32 count;
    i = 0;
    count = M2C_FIELD(arg0, s8 *, 4) - 1;
    for (; i < count; i++) {
        entry = (s32)arg0 + i * 0x18;
        if (M2C_FIELD(entry, s32 *, 0x18) != M2C_FIELD(entry, s32 *, 0x30)) return 1;
    }
    return 0;
}

s32 InRange(s16,s16,s16);
void StepCounter(s32,s32,s32);
#pragma push
#pragma opt_propagation off
void func_ov003_021e8354(s32 arg0,s32 arg1,s32 arg2){register s32 n=M2C_FIELD(arg0+0x18,s32*,arg1*24)+1;
if(InRange((s16)n,(s16)M2C_FIELD(arg0+0x20,s32*,arg1*24),(s16)M2C_FIELD(arg0+0x1c,s32*,arg1*24))||arg2){M2C_FIELD(arg0+0x18,s32*,arg1*24)=n;if (((u8 (*)[24])arg0)[arg1][0x28]) {
if(M2C_FIELD(arg0+0x18,s32*,arg1*24)>M2C_FIELD(arg0+0x1c,s32*,arg1*24)) {s32 p=arg0+arg1*24; do {M2C_FIELD(p,s32*,0x18)-=M2C_FIELD(p,s32*,0x1c)-M2C_FIELD(p,s32*,0x20)+1;}while(M2C_FIELD(p,s32*,0x18)>M2C_FIELD(p,s32*,0x1c));}
if(M2C_FIELD(arg0+0x18,s32*,arg1*24)<M2C_FIELD(arg0+0x20,s32*,arg1*24)) {s32 p=arg0+arg1*24; do {M2C_FIELD(p,s32*,0x18)+=M2C_FIELD(p,s32*,0x1c)-M2C_FIELD(p,s32*,0x20)+1;}while(M2C_FIELD(p,s32*,0x18)<M2C_FIELD(p,s32*,0x20));}
} else {
M2C_FIELD(arg0+0x18,s32*,arg1*24)=M2C_FIELD(arg0+0x18,s32*,arg1*24)>M2C_FIELD(arg0+0x1c,s32*,arg1*24)?M2C_FIELD(arg0+0x1c,s32*,arg1*24):(M2C_FIELD(arg0+0x18,s32*,arg1*24)<M2C_FIELD(arg0+0x20,s32*,arg1*24)?M2C_FIELD(arg0+0x20,s32*,arg1*24):M2C_FIELD(arg0+0x18,s32*,arg1*24));
}}else{
if(n>M2C_FIELD(arg0+0x1c,s32*,arg1*24))n=M2C_FIELD(arg0+0x1c,s32*,arg1*24);else n=n<M2C_FIELD(arg0+0x20,s32*,arg1*24)?M2C_FIELD(arg0+0x20,s32*,arg1*24):n;
M2C_FIELD(arg0+0x18,s32*,arg1*24)=n;if (((u8 (*)[24])arg0)[arg1][0x28]) {
if(M2C_FIELD(arg0+0x18,s32*,arg1*24)>M2C_FIELD(arg0+0x1c,s32*,arg1*24)) {s32 p=arg0+arg1*24; do {M2C_FIELD(p,s32*,0x18)-=M2C_FIELD(p,s32*,0x1c)-M2C_FIELD(p,s32*,0x20)+1;}while(M2C_FIELD(p,s32*,0x18)>M2C_FIELD(p,s32*,0x1c));}
if(M2C_FIELD(arg0+0x18,s32*,arg1*24)<M2C_FIELD(arg0+0x20,s32*,arg1*24)) {s32 p=arg0+arg1*24; do {M2C_FIELD(p,s32*,0x18)+=M2C_FIELD(p,s32*,0x1c)-M2C_FIELD(p,s32*,0x20)+1;}while(M2C_FIELD(p,s32*,0x18)<M2C_FIELD(p,s32*,0x20));}
} else {
M2C_FIELD(arg0+0x18,s32*,arg1*24)=M2C_FIELD(arg0+0x18,s32*,arg1*24)>M2C_FIELD(arg0+0x1c,s32*,arg1*24)?M2C_FIELD(arg0+0x1c,s32*,arg1*24):(M2C_FIELD(arg0+0x18,s32*,arg1*24)<M2C_FIELD(arg0+0x20,s32*,arg1*24)?M2C_FIELD(arg0+0x20,s32*,arg1*24):M2C_FIELD(arg0+0x18,s32*,arg1*24));
}}
if(ov003_entries_differ(arg0))return;StepCounter(arg0+0x14+arg1*24,1,arg2);
if(ov003_entries_differ(arg0))return;StepCounter(arg0+0x14+arg1*24,1,arg2);
if(EntriesDiffer((void*)arg0))return;StepCounter(arg0+0x14+arg1*24,1,arg2);
if(EntriesDiffer((void*)arg0))return;StepCounter(arg0+0x14+arg1*24,1,arg2);
if(EntriesDiffer((void*)arg0))return;func_ov003_021e8354(arg0,arg1,arg2);}
#pragma pop
