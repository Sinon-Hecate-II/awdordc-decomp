/* 1 function from 0x02203710 to 0x022048C0 (ov003), found by ds-decomp. */
#include "common.h"
static inline u8 MenuIsFixed(void *p) { u8 result;if(((u32)(M2C_FIELD(p,u8*,0x3a)<<26)>>26)==1)result=1;else result=0;return result; }
static inline void MenuCopyCursor(void *p) {
s32 GetUnitSpriteHeight(void*);s32 GetUnitSpriteWidth(void*);
void *sprite=M2C_FIELD(M2C_FIELD(p,void**,0x44),void**,0x10c);
s32 h=GetUnitSpriteHeight(sprite),w=GetUnitSpriteWidth(sprite);
s16 y=M2C_FIELD(sprite,s16*,0x36),x=M2C_FIELD(sprite,s16*,0x34);
void *cursor=M2C_FIELD(p,void**,0x4c);
M2C_FIELD(cursor,s16*,0x34)=x;M2C_FIELD(cursor,s16*,0x36)=y;
M2C_FIELD(cursor,u32*,0x40)=((M2C_FIELD(cursor,u32*,0x40)&~511)|(w&511))&0xfffc01ff | ((u32)(h<<23)>>14);
}
static inline void MenuDescribe(void *p) {
s32 Ov003_GetEntryValueTextId(s32,u8);void SetTextById(void*,s32);
void *ctx=M2C_FIELD(p,void**,0x44);
s32 kind=M2C_FIELD(M2C_FIELD(ctx,void**,0x10c),u16*,0x2e)&255;
s32 value=M2C_FIELD(ctx+kind*24,s32*,12);
switch(kind){
case 0:SetTextById(M2C_FIELD(p,void**,0x58),0x47000000);break;
case 1:SetTextById(M2C_FIELD(p,void**,0x58),Ov003_GetEntryValueTextId(kind,value&255));break;
case 2:SetTextById(M2C_FIELD(p,void**,0x58),Ov003_GetEntryValueTextId(kind,value&255));break;
case 3:SetTextById(M2C_FIELD(p,void**,0x58),0x4700000b);break;
case 4:SetTextById(M2C_FIELD(p,void**,0x58),0x47000014);break;
case 5:SetTextById(M2C_FIELD(p,void**,0x58),0x4700000a);break;
case 6:SetTextById(M2C_FIELD(p,void**,0x58),Ov003_GetEntryValueTextId(kind,value&255));break;
case 7:SetTextById(M2C_FIELD(p,void**,0x58),0x47000015);break;
case 8:SetTextById(M2C_FIELD(p,void**,0x58),0x47000018);break;
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


#pragma opt_common_subs off
void func_ov003_02203710(void *arg0,s32 arg1) {
void *GetUnitSpriteAbove(void*);void *GetUnitSpriteBelow(void*);void *GetUnitSpriteLeft(void*);void *GetUnitSpriteRight(void*);
void func_ov003_02200dc8(void*,s32);void PlaySoundEffect(s32);
void *ctx=M2C_FIELD(arg0,void**,0x44),*entry,*next;
s32 old;
u8 index=M2C_FIELD(ctx,u8*,6);
s32 offset=(s16)index*(s16)24;
u8 state=M2C_FIELD(arg0,u8*,0x39),test;
old=M2C_FIELD(ctx+offset,s32*,12);
if((u8)(state==0)){
switch(arg1){
case 1:
next=GetUnitSpriteAbove(M2C_FIELD(ctx,void**,0x10c));ctx=M2C_FIELD(arg0,void**,0x44);
old=M2C_FIELD(M2C_FIELD(ctx,void**,0x10c),u16*,0x2e)&255;
func_ov003_02200dc8(ctx,M2C_FIELD(next,u16*,0x2e)&255);
if(old==(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void**,0x44),void**,0x10c),u16*,0x2e)&255))return;
PlaySoundEffect(0x10019);MenuCopyCursor(arg0);if (MenuIsFixed(arg0) == 0) MenuDescribe(arg0); return;
case 2:
next=GetUnitSpriteBelow(M2C_FIELD(ctx,void**,0x10c));ctx=M2C_FIELD(arg0,void**,0x44);
old=M2C_FIELD(M2C_FIELD(ctx,void**,0x10c),u16*,0x2e)&255;
func_ov003_02200dc8(ctx,M2C_FIELD(next,u16*,0x2e)&255);
if(old==(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void**,0x44),void**,0x10c),u16*,0x2e)&255))return;
PlaySoundEffect(0x10019);MenuCopyCursor(arg0);if (MenuIsFixed(arg0) == 0) MenuDescribe(arg0); return;
case 4:
next=GetUnitSpriteLeft(M2C_FIELD(ctx,void**,0x10c));ctx=M2C_FIELD(arg0,void**,0x44);
old=M2C_FIELD(M2C_FIELD(ctx,void**,0x10c),u16*,0x2e)&255;
func_ov003_02200dc8(ctx,M2C_FIELD(next,u16*,0x2e)&255);
if(old==(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void**,0x44),void**,0x10c),u16*,0x2e)&255))return;
PlaySoundEffect(0x10019);MenuCopyCursor(arg0);if (MenuIsFixed(arg0) == 0) MenuDescribe(arg0); return;
case 8:
next=GetUnitSpriteRight(M2C_FIELD(ctx,void**,0x10c));ctx=M2C_FIELD(arg0,void**,0x44);
old=M2C_FIELD(M2C_FIELD(ctx,void**,0x10c),u16*,0x2e)&255;
func_ov003_02200dc8(ctx,M2C_FIELD(next,u16*,0x2e)&255);
if(old==(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0,void**,0x44),void**,0x10c),u16*,0x2e)&255))return;
PlaySoundEffect(0x10019);MenuCopyCursor(arg0);if (MenuIsFixed(arg0) == 0) MenuDescribe(arg0); return;
default:return;
}
}else if((u8)(state==1)){switch(arg1){case 1:
{
    s32 stepOffset = index*24;
    s32 *value = (s32 *)((u8 *)ctx + 12 + stepOffset);
    void *range = (u8 *)ctx + stepOffset;
    *value += M2C_FIELD(range, s32 *, 24);
    if (M2C_FIELD(range, u8 *, 28)) {
        s32 current = *value;
        if (current > M2C_FIELD(range, s32 *, 16)) {
            void *record = (u8 *)ctx + offset;
            do {
                s32 max = M2C_FIELD(record, s32 *, 16);
                s32 min = M2C_FIELD(record, s32 *, 20);
                current = M2C_FIELD(record, s32 *, 12) - (max - min + 1);
                M2C_FIELD(record, s32 *, 12) = current;
            } while (current > M2C_FIELD(record, s32 *, 16));
        }
        current = *value;
        if (current < M2C_FIELD((u8 *)ctx + stepOffset, s32 *, 20)) {
            void *record = (u8 *)ctx + offset;
            do {
                s32 max = M2C_FIELD(record, s32 *, 16);
                s32 min = M2C_FIELD(record, s32 *, 20);
                current = M2C_FIELD(record, s32 *, 12) + (max - min + 1);
                M2C_FIELD(record, s32 *, 12) = current;
            } while (current < M2C_FIELD((u8 *)ctx + offset, s32 *, 20));
        }
    } else {
        s32 max = M2C_FIELD(range, s32 *, 16);
        s32 current = *value;
        if (current > max)
            current = max;
        else {
            s32 min = M2C_FIELD(range, s32 *, 20);
            current = current < min ? min : current;
        }
        *value = current;
    }
}MenuAnimate(M2C_FIELD(M2C_FIELD(arg0,void**,0x40)+index*4,void**,8));
{ u8 k = index + 255; test = (k <= 5) ? (0x23u >> k) & 1 : 0; }
if(test&&!MenuIsFixed(arg0))MenuDescribe(arg0);
if(old==M2C_FIELD(M2C_FIELD(arg0,void**,0x44)+offset,s32*,12))return;
PlaySoundEffect(0x10011);return;
case 8:
test=(u8)((u8)(index+253)<=2);if(test){u8 i=0;do{ctx=M2C_FIELD(arg0,void**,0x44);{
    s32 stepOffset = offset;
    s32 *value = (s32 *)((u8 *)ctx + stepOffset + 12);
    void *range = (u8 *)ctx + stepOffset;
    *value += M2C_FIELD(range, s32 *, 24);
    if (M2C_FIELD(range, u8 *, 28)) {
        s32 current = *value;
        if (current > M2C_FIELD(range, s32 *, 16)) {
            void *record = (u8 *)ctx + offset;
            do {
                s32 max = M2C_FIELD(record, s32 *, 16);
                s32 min = M2C_FIELD(record, s32 *, 20);
                current = M2C_FIELD(record, s32 *, 12) - (max - min + 1);
                M2C_FIELD(record, s32 *, 12) = current;
            } while (current > M2C_FIELD(record, s32 *, 16));
        }
        current = *value;
        if (current < M2C_FIELD((u8 *)ctx + stepOffset, s32 *, 20)) {
            void *record = (u8 *)ctx + offset;
            do {
                s32 max = M2C_FIELD(record, s32 *, 16);
                s32 min = M2C_FIELD(record, s32 *, 20);
                current = M2C_FIELD(record, s32 *, 12) + (max - min + 1);
                M2C_FIELD(record, s32 *, 12) = current;
            } while (current < M2C_FIELD((u8 *)ctx + offset, s32 *, 20));
        }
    } else {
        s32 max = M2C_FIELD(range, s32 *, 16);
        s32 current = *value;
        if (current > max)
            current = max;
        else {
            s32 min = M2C_FIELD(range, s32 *, 20);
            current = current < min ? min : current;
        }
        *value = current;
    }
}i++;}while(i<5);MenuAnimate(M2C_FIELD(M2C_FIELD(arg0,void**,0x40)+index*4,void**,8));}
{ u8 k = index + 255; test = (k <= 5) ? (0x23u >> k) & 1 : 0; }
if(test&&!MenuIsFixed(arg0))MenuDescribe(arg0);
if(old==M2C_FIELD(M2C_FIELD(arg0,void**,0x44)+offset,s32*,12))return;
PlaySoundEffect(0x10011);return;
case 2:
{
    s32 stepOffset = index*24;
    s32 *value = (s32 *)((u8 *)ctx + 12 + stepOffset);
    void *range = (u8 *)ctx + stepOffset;
    *value -= M2C_FIELD(range, s32 *, 24);
    if (M2C_FIELD(range, u8 *, 28)) {
        s32 current = *value;
        if (current > M2C_FIELD(range, s32 *, 16)) {
            void *record = (u8 *)ctx + offset;
            do {
                s32 max = M2C_FIELD(record, s32 *, 16);
                s32 min = M2C_FIELD(record, s32 *, 20);
                current = M2C_FIELD(record, s32 *, 12) - (max - min + 1);
                M2C_FIELD(record, s32 *, 12) = current;
            } while (current > M2C_FIELD(record, s32 *, 16));
        }
        current = *value;
        if (current < M2C_FIELD((u8 *)ctx + stepOffset, s32 *, 20)) {
            void *record = (u8 *)ctx + offset;
            do {
                s32 max = M2C_FIELD(record, s32 *, 16);
                s32 min = M2C_FIELD(record, s32 *, 20);
                current = M2C_FIELD(record, s32 *, 12) + (max - min + 1);
                M2C_FIELD(record, s32 *, 12) = current;
            } while (current < M2C_FIELD((u8 *)ctx + offset, s32 *, 20));
        }
    } else {
        s32 max = M2C_FIELD(range, s32 *, 16);
        s32 current = *value;
        if (current > max)
            current = max;
        else {
            s32 min = M2C_FIELD(range, s32 *, 20);
            current = current < min ? min : current;
        }
        *value = current;
    }
}MenuAnimate(M2C_FIELD(M2C_FIELD(arg0,void**,0x40)+index*4,void**,40));
{ u8 k = index + 255; test = (k <= 5) ? (0x23u >> k) & 1 : 0; }
if(test&&!MenuIsFixed(arg0))MenuDescribe(arg0);
if(old==M2C_FIELD(M2C_FIELD(arg0,void**,0x44)+offset,s32*,12))return;
PlaySoundEffect(0x10011);return;
case 4:
test=(u8)((u8)(index+253)<=2);if(test){u8 i=0;do{ctx=M2C_FIELD(arg0,void**,0x44);{
    s32 stepOffset = offset;
    s32 *value = (s32 *)((u8 *)ctx + stepOffset + 12);
    void *range = (u8 *)ctx + stepOffset;
    *value -= M2C_FIELD(range, s32 *, 24);
    if (M2C_FIELD(range, u8 *, 28)) {
        s32 current = *value;
        if (current > M2C_FIELD(range, s32 *, 16)) {
            void *record = (u8 *)ctx + offset;
            do {
                s32 max = M2C_FIELD(record, s32 *, 16);
                s32 min = M2C_FIELD(record, s32 *, 20);
                current = M2C_FIELD(record, s32 *, 12) - (max - min + 1);
                M2C_FIELD(record, s32 *, 12) = current;
            } while (current > M2C_FIELD(record, s32 *, 16));
        }
        current = *value;
        if (current < M2C_FIELD((u8 *)ctx + stepOffset, s32 *, 20)) {
            void *record = (u8 *)ctx + offset;
            do {
                s32 max = M2C_FIELD(record, s32 *, 16);
                s32 min = M2C_FIELD(record, s32 *, 20);
                current = M2C_FIELD(record, s32 *, 12) + (max - min + 1);
                M2C_FIELD(record, s32 *, 12) = current;
            } while (current < M2C_FIELD((u8 *)ctx + offset, s32 *, 20));
        }
    } else {
        s32 max = M2C_FIELD(range, s32 *, 16);
        s32 current = *value;
        if (current > max)
            current = max;
        else {
            s32 min = M2C_FIELD(range, s32 *, 20);
            current = current < min ? min : current;
        }
        *value = current;
    }
}i++;}while(i<5);MenuAnimate(M2C_FIELD(M2C_FIELD(arg0,void**,0x40)+index*4,void**,40));}
{ u8 k = index + 255; test = (k <= 5) ? (0x23u >> k) & 1 : 0; }
if(test&&!MenuIsFixed(arg0))MenuDescribe(arg0);
if(old==M2C_FIELD(M2C_FIELD(arg0,void**,0x44)+offset,s32*,12))return;
PlaySoundEffect(0x10011);return;
default:return;}}}
#pragma opt_common_subs reset
