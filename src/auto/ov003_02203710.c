/* 1 function from 0x02203710 to 0x022048C0 (ov003), found by ds-decomp. */
#include "common.h"
static inline u8 MenuIsFixed(void *p) { u8 result;if(((u32)(M2C_FIELD(p,u8*,0x3a)<<26)>>26)==1)result=1;else result=0;return result; }
static inline void MenuCopyCursor(void *p) {
s32 func_020aae44(void*);s32 func_020aae10(void*);
void *sprite=M2C_FIELD(M2C_FIELD(p,void**,0x44),void**,0x10c);
s32 h=func_020aae44(sprite),w=func_020aae10(sprite);
s16 y=M2C_FIELD(sprite,s16*,0x36),x=M2C_FIELD(sprite,s16*,0x34);
void *cursor=M2C_FIELD(p,void**,0x4c);
M2C_FIELD(cursor,s16*,0x34)=x;M2C_FIELD(cursor,s16*,0x36)=y;
M2C_FIELD(cursor,u32*,0x40)=((M2C_FIELD(cursor,u32*,0x40)&~511)|(w&511))&0xfffc01ff | ((u32)(h<<23)>>14);
}
static inline void MenuDescribe(void *p) {
s32 func_ov003_02200d80(s32,u8);void func_0208b758(void*,s32);
void *ctx=M2C_FIELD(p,void**,0x44);
s32 kind=M2C_FIELD(M2C_FIELD(ctx,void**,0x10c),u16*,0x2e)&255;
s32 value=M2C_FIELD(ctx+kind*24,s32*,12);
switch(kind){
case 0:func_0208b758(M2C_FIELD(p,void**,0x58),0x47000000);break;
case 1:func_0208b758(M2C_FIELD(p,void**,0x58),func_ov003_02200d80(kind,value&255));break;
case 2:func_0208b758(M2C_FIELD(p,void**,0x58),func_ov003_02200d80(kind,value&255));break;
case 3:func_0208b758(M2C_FIELD(p,void**,0x58),0x4700000b);break;
case 4:func_0208b758(M2C_FIELD(p,void**,0x58),0x47000014);break;
case 5:func_0208b758(M2C_FIELD(p,void**,0x58),0x4700000a);break;
case 6:func_0208b758(M2C_FIELD(p,void**,0x58),func_ov003_02200d80(kind,value&255));break;
case 7:func_0208b758(M2C_FIELD(p,void**,0x58),0x47000015);break;
case 8:func_0208b758(M2C_FIELD(p,void**,0x58),0x47000018);break;
}
}
static inline void MenuAnimate(void *p){
if(M2C_FIELD(p,s8*,0x5a)>=0){
u16 n=((u32)(M2C_FIELD(p,u8*,0x59)<<28)>>28)+1;
M2C_FIELD(p,u32*,0x40)=(M2C_FIELD(p,u32*,0x40)&~0x3fc0000)|((u32)(n<<24)>>6);
M2C_FIELD(p,u8*,0x5a)=12;
}}
static inline void MenuClampValue(void *record){
if(M2C_FIELD(record,u8*,28)){
while(M2C_FIELD(record,volatile s32*,12)>M2C_FIELD(record,volatile s32*,16))M2C_FIELD(record,volatile s32*,12)-=M2C_FIELD(record,volatile s32*,16)-M2C_FIELD(record,volatile s32*,20)+1;
while(M2C_FIELD(record,volatile s32*,12)<M2C_FIELD(record,volatile s32*,20))M2C_FIELD(record,volatile s32*,12)+=M2C_FIELD(record,volatile s32*,16)-M2C_FIELD(record,volatile s32*,20)+1;
}else{
s32 v=M2C_FIELD(record,volatile s32*,12),max=M2C_FIELD(record,volatile s32*,16),min;
if(v>max)v=max;else {min=M2C_FIELD(record,volatile s32*,20);if(v<min)v=min;}
M2C_FIELD(record,volatile s32*,12)=v;
}}


#pragma push
#pragma scheduling off
void func_ov003_02203710(void *arg0,s32 arg1) {
void *func_020abb9c(void*);void *func_020abbb4(void*);void *func_020abbcc(void*);void *func_020abbe4(void*);
void func_ov003_02200dc8(void*,s32);void func_0208fe30(s32);
void *ctx=M2C_FIELD(arg0,void**,0x44),*entry,*next;
s32 old,index=M2C_FIELD(ctx,u8*,6),offset=(s16)index*(s16)24;
u8 state=M2C_FIELD(arg0,u8*,0x39),test;
old=M2C_FIELD(ctx+offset,s32*,12);
if((u8)(state==0)){
switch(arg1){
case 1:
next=func_020abb9c(M2C_FIELD(ctx,void**,0x10c));ctx=M2C_FIELD(arg0,void**,0x44);
old=M2C_FIELD(M2C_FIELD(ctx,void**,0x10c),u16*,0x2e)&255;
func_ov003_02200dc8(ctx,M2C_FIELD(next,u16*,0x2e)&255);
if(old==(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void**,0x44),void**,0x10c),u16*,0x2e)&255))return;
func_0208fe30(0x10019);MenuCopyCursor(arg0);if(MenuIsFixed(arg0))return;MenuDescribe(arg0);return;
case 2:
next=func_020abbb4(M2C_FIELD(ctx,void**,0x10c));ctx=M2C_FIELD(arg0,void**,0x44);
old=M2C_FIELD(M2C_FIELD(ctx,void**,0x10c),u16*,0x2e)&255;
func_ov003_02200dc8(ctx,M2C_FIELD(next,u16*,0x2e)&255);
if(old==(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void**,0x44),void**,0x10c),u16*,0x2e)&255))return;
func_0208fe30(0x10019);MenuCopyCursor(arg0);if(MenuIsFixed(arg0))return;MenuDescribe(arg0);return;
case 4:
next=func_020abbcc(M2C_FIELD(ctx,void**,0x10c));ctx=M2C_FIELD(arg0,void**,0x44);
old=M2C_FIELD(M2C_FIELD(ctx,void**,0x10c),u16*,0x2e)&255;
func_ov003_02200dc8(ctx,M2C_FIELD(next,u16*,0x2e)&255);
if(old==(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void**,0x44),void**,0x10c),u16*,0x2e)&255))return;
func_0208fe30(0x10019);MenuCopyCursor(arg0);if(MenuIsFixed(arg0))return;MenuDescribe(arg0);return;
case 8:
next=func_020abbe4(M2C_FIELD(ctx,void**,0x10c));ctx=M2C_FIELD(arg0,void**,0x44);
old=M2C_FIELD(M2C_FIELD(ctx,void**,0x10c),u16*,0x2e)&255;
func_ov003_02200dc8(ctx,M2C_FIELD(next,u16*,0x2e)&255);
if(old==(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void**,0x44),void**,0x10c),u16*,0x2e)&255))return;
func_0208fe30(0x10019);MenuCopyCursor(arg0);if(MenuIsFixed(arg0))return;MenuDescribe(arg0);return;
default:return;
}
}else if((u8)(state==1)){switch(arg1){case 1:
entry=ctx+index*24;M2C_FIELD(entry,s32*,12)+=M2C_FIELD(entry,s32*,24);MenuClampValue(entry);MenuAnimate(M2C_FIELD(M2C_FIELD(arg0,void**,0x40)+index*4,void**,8));
test=(u8)(index==1 || index==2 || index==6);
if(test&&!MenuIsFixed(arg0))MenuDescribe(arg0);
if(old==M2C_FIELD(M2C_FIELD(arg0,void**,0x44)+offset,s32*,12))return;
func_0208fe30(0x10011);return;
case 8:
test=(u8)((u8)(index+253)<=2);if(test){u8 i=0;do{ctx=M2C_FIELD(arg0,void**,0x44);entry=ctx+offset;M2C_FIELD(entry,s32*,12)+=M2C_FIELD(entry,s32*,24);MenuClampValue(entry);i++;}while(i<5);MenuAnimate(M2C_FIELD(M2C_FIELD(arg0,void**,0x40)+index*4,void**,8));}
test=0;switch((u8)(index+255)){case 0:case 1:case 5:test=1;break;}
if(test&&!MenuIsFixed(arg0))MenuDescribe(arg0);
if(old==M2C_FIELD(M2C_FIELD(arg0,void**,0x44)+offset,s32*,12))return;
func_0208fe30(0x10011);return;
case 2:
entry=ctx+index*24;M2C_FIELD(entry,s32*,12)-=M2C_FIELD(entry,s32*,24);MenuClampValue(entry);MenuAnimate(M2C_FIELD(M2C_FIELD(arg0,void**,0x40)+index*4,void**,40));
test=0;switch((u8)(index+255)){case 0:case 1:case 5:test=1;break;}
if(test&&!MenuIsFixed(arg0))MenuDescribe(arg0);
if(old==M2C_FIELD(M2C_FIELD(arg0,void**,0x44)+offset,s32*,12))return;
func_0208fe30(0x10011);return;
case 4:
test=(u8)((u8)(index+253)<=2);if(test){u8 i=0;do{ctx=M2C_FIELD(arg0,void**,0x44);entry=ctx+offset;M2C_FIELD(entry,s32*,12)-=M2C_FIELD(entry,s32*,24);MenuClampValue(entry);i++;}while(i<5);MenuAnimate(M2C_FIELD(M2C_FIELD(arg0,void**,0x40)+index*4,void**,40));}
test=0;switch((u8)(index+255)){case 0:case 1:case 5:test=1;break;}
if(test&&!MenuIsFixed(arg0))MenuDescribe(arg0);
if(old==M2C_FIELD(M2C_FIELD(arg0,void**,0x44)+offset,s32*,12))return;
func_0208fe30(0x10011);return;
default:return;}}}
#pragma pop
