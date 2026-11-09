/* 4 functions from 0x0220DE5C to 0x0220ED80 (ov003), found by ds-decomp. */
#include "common.h"
typedef void (*VFn)(void *);
static inline void RestoreByte(void *p,u8 v) { M2C_FIELD(p,u8 *,15)=v; }
static inline void RestoreBits12(u16 x) { extern u8 data_0215d9b8[8]; M2C_FIELD(data_0215d9b8,u16 *,6)=(M2C_FIELD(data_0215d9b8,u16 *,6)&~0x3000)|((x&3)<<12); }
static inline void RestoreBits10(u16 x) { extern u8 data_0215d9b8[8]; M2C_FIELD(data_0215d9b8,u16 *,6)=(M2C_FIELD(data_0215d9b8,u16 *,6)&~0xc00)|((x&3)<<10); }
static inline void RestoreBit14(u16 x) { extern u8 data_0215d9b8[8]; M2C_FIELD(data_0215d9b8,u16 *,6)=(M2C_FIELD(data_0215d9b8,u16 *,6)&~0x4000)|((x&1)<<14); }
typedef struct { u8 low:4, high:4; } Unk0220C6C8Nibbles;
typedef struct { u8 b0:1,b1:1,b2:1,b3:1,b4:1,b5:1,b6:1,b7:1; } Unk0220C6C8Bits;
typedef struct { u8 kind, unk1; u16 unk2, unk4, unk6, unk8, unkA, unkC, unkE, unk10; } Unk0220C6C8Sprite;
typedef struct { Unk0220C6C8Sprite *sprite; u32 *start, *current; u16 index; u8 unkE, unkF; } Unk0220C6C8Anim;
extern u8 data_ov003_02210ac4[], data_ov003_02210b0c[], data_ov003_02210c44[];
extern u8 data_ov003_02210a4c[], data_ov003_02211018[], data_ov003_0220fb28[];
extern u8 data_0215d9b8[];
typedef struct { void *vtable; u8 unk4,unk5,unk6,unk7; s16 unk8,unkA; u8 unkC,unkD; s16 unkE,unk10,unk12,unk14,unk16; u8 unk18,pad[3]; void *child; } Unk0220C6C8Slider;
static inline void Unk0220C6C8Reset(Unk0220C6C8Anim *p) { p->unkE=0; p->unkF=0; }



void *func_01ffa42c(void *, void *);
int func_ov003_022066a8(int);
void *func_02082028(int);
extern u8 data_ov003_022109ec[];
extern u8 data_ov003_02211060[];
extern u32 data_02101fd8;
void *func_02082034(int);
void *func_020e34bc(int);
void func_02007f8c(void *, int, int);
void func_020a9218(void *);
void func_020a9188(void *, int);
void func_020a9a1c(void *, int, int);
void func_020a979c(void *, int, int);
int func_020bf9e0(void);
int func_020bfa20(void);
int func_0207c8ec(int, int);
extern int data_ov003_02211028;
static inline u8 *Unk0220DE5CCreateSlider(int y,int childY) { u8 *q,*t; q=func_02082028(0x20);
if(q) {
M2C_FIELD(q,void **,0)=&data_ov003_02211028;
q[6]=0;q[5]=0;q[4]=0;q[13]=0;q[12]=0;
M2C_FIELD(q,s16 *,10)=0; M2C_FIELD(q,s16 *,8)=0;
q[24]=0; M2C_FIELD(q,s16 *,22)=0; M2C_FIELD(q,s16 *,20)=0; M2C_FIELD(q,s16 *,18)=0; M2C_FIELD(q,s16 *,16)=0; M2C_FIELD(q,s16 *,14)=0;
func_020a9a1c(q,0,127);
q[12]=70;q[13]=24;M2C_FIELD(q,s16 *,8)=145;M2C_FIELD(q,s16 *,10)=y;
t=func_02082028(0x1c);
if(t) {
M2C_FIELD(t,void **,0)=data_ov003_02211018;
t[6]=0;t[5]=0;t[4]=0;t[17]=0;t[16]=0;
M2C_FIELD(t,s16 *,14)=0;M2C_FIELD(t,s16 *,12)=0;M2C_FIELD(t,s16 *,10)=0;M2C_FIELD(t,s16 *,8)=0;
M2C_FIELD(t,s16 *,24)=0;M2C_FIELD(t,s16 *,22)=0;M2C_FIELD(t,s16 *,20)=0;
M2C_FIELD(t,s16 *,18)=145;M2C_FIELD(t,s16 *,20)=215;M2C_FIELD(t,s16 *,22)=childY;M2C_FIELD(t,s16 *,24)=childY;
t[16]=16;t[17]=32;func_020a979c(t,180,childY);
}
M2C_FIELD(q,u8 **,28)=t;
}
 return q; }

typedef struct { void *vtable; s32 value, max, min, step; u8 wrap; u8 pad[3]; } Unk0220DE5CBound;
static inline void Unk0220DE5CSet(Unk0220DE5CBound *p, int value) {
p->value=value;
if(p->wrap) { while(p->value>p->max) p->value-=p->max-p->min+1; while(p->value<p->min) p->value+=p->max-p->min+1; }
else if(p->value<=p->max) p->value=p->value<p->min?p->min:p->value;
}



void func_ov003_0220de5c(void *a) {
u8 *t, *q;
Unk0220C6C8Anim *anim;
Unk0220C6C8Sprite *sprite, *resetSprite;
int i, base;
u8 *p = func_01ffa42c(data_ov003_022109ec, a);
if (p) {
*(void **)p = data_ov003_02211060;
p[0x34]=0; p[0x35]=0;
((Unk0220C6C8Nibbles *)(p+0x36))->low=4;
((Unk0220C6C8Nibbles *)(p+0x36))->high=0;
((Unk0220C6C8Nibbles *)(p+0x37))->low=0;
((Unk0220C6C8Nibbles *)(p+0x37))->high=0;
((Unk0220C6C8Bits *)(p+0x38))->b0=1;
((Unk0220C6C8Bits *)(p+0x38))->b1=1;
((Unk0220C6C8Bits *)(p+0x38))->b2=0;
((Unk0220C6C8Bits *)(p+0x38))->b3=0;
((Unk0220C6C8Bits *)(p+0x38))->b4=0;
((Unk0220C6C8Bits *)(p+0x38))->b5=0;
((Unk0220C6C8Bits *)(p+0x38))->b6=0;
((Unk0220C6C8Bits *)(p+0x38))->b7=0;
*(u32 *)(p+0x3c)=data_02101fd8;
*(u32 *)(p+0x40)=0;
*(u32 *)(p+0x44)=func_ov003_022066a8(0);
*(u32 *)(p+0x68)=0;
*(void **)(p+0x4c)=func_02082028(0x24);anim=func_02082028(0x10);
if (anim) {
anim->start=(u32 *)data_ov003_02210ac4; anim->current=(u32 *)data_ov003_02210ac4; anim->index=0; anim->unkE=0; anim->unkF=0;
sprite = func_02082028(0x12);
if (sprite) {
sprite->kind = anim->current[1]; sprite->unk1=0; sprite->unk2=0; sprite->unk4=0;
sprite->unk6=1; sprite->unk8=0; sprite->unkA=1; sprite->unkC=1; sprite->unkE=0; sprite->unk10=0;
sprite->unk2=sprite->unk4;
}

anim->sprite=sprite; anim->current=anim->start; anim->index=0;
func_020a9218(anim); anim->unkE=0; anim->unkF=0;
}
M2C_FIELD(M2C_FIELD(p, u8 **, 0x4c), Unk0220C6C8Anim **, 0x18)=anim;
anim=func_02082028(0x10);
if (anim) {
anim->start=(u32 *)data_ov003_02210b0c; anim->current=(u32 *)data_ov003_02210b0c; anim->index=0; anim->unkE=0; anim->unkF=0;
sprite = func_02082028(0x12);
if (sprite) {
sprite->kind = anim->current[1]; sprite->unk1=0; sprite->unk2=0; sprite->unk4=0;
sprite->unk6=1; sprite->unk8=0; sprite->unkA=1; sprite->unkC=1; sprite->unkE=0; sprite->unk10=0;
sprite->unk2=sprite->unk4;
}

anim->sprite=sprite; anim->current=anim->start; anim->index=0;
func_020a9218(anim); anim->unkE=0; anim->unkF=0;
}
M2C_FIELD(M2C_FIELD(p, u8 **, 0x4c), Unk0220C6C8Anim **, 0x1c)=anim;
M2C_FIELD(p, void **, 0x48)=func_02082034(0xd8);
for (i=0;i<6;i++) {anim=func_02082028(0x10);
if (anim) {
anim->start=(u32 *)data_ov003_02210ac4; anim->current=(u32 *)data_ov003_02210ac4; anim->index=0; anim->unkE=0; anim->unkF=0;
sprite = func_02082028(0x12);
if (sprite) {
sprite->kind = anim->current[1]; sprite->unk1=0; sprite->unk2=0; sprite->unk4=0;
sprite->unk6=1; sprite->unk8=0; sprite->unkA=1; sprite->unkC=1; sprite->unkE=0; sprite->unk10=0;
sprite->unk2=sprite->unk4;
}

anim->sprite=sprite; anim->current=anim->start; anim->index=0;
func_020a9218(anim); anim->unkE=0; anim->unkF=0;
}
M2C_FIELD(M2C_FIELD(p,u8 **,0x48)+i*0x24,Unk0220C6C8Anim **,24)=anim;
anim=func_02082028(0x10);
if (anim) {
anim->start=(u32 *)data_ov003_02210b0c; anim->current=(u32 *)data_ov003_02210b0c; anim->index=0; anim->unkE=0; anim->unkF=0;
sprite = func_02082028(0x12);
if (sprite) {
sprite->kind = anim->current[1]; sprite->unk1=0; sprite->unk2=0; sprite->unk4=0;
sprite->unk6=1; sprite->unk8=0; sprite->unkA=1; sprite->unkC=1; sprite->unkE=0; sprite->unk10=0;
sprite->unk2=sprite->unk4;
}

anim->sprite=sprite; anim->current=anim->start; anim->index=0;
func_020a9218(anim); anim->unkE=0; anim->unkF=0;
}
M2C_FIELD(M2C_FIELD(p,u8 **,0x48)+i*0x24,Unk0220C6C8Anim **,28)=anim;
anim=func_02082028(0x10);
if (anim) {
anim->start=(u32 *)data_ov003_02210c44; anim->current=(u32 *)data_ov003_02210c44; anim->index=0; anim->unkE=0; anim->unkF=0;
sprite = func_02082028(0x12);
if (sprite) {
sprite->kind = anim->current[1]; sprite->unk1=0; sprite->unk2=0; sprite->unk4=0;
sprite->unk6=1; sprite->unk8=0; sprite->unkA=1; sprite->unkC=1; sprite->unkE=0; sprite->unk10=0;
sprite->unk2=sprite->unk4;
}

anim->sprite=sprite; anim->current=anim->start; anim->index=0;
func_020a9218(anim); anim->unkE=0; anim->unkF=0;
}
M2C_FIELD(M2C_FIELD(p,u8 **,0x48)+i*0x24,Unk0220C6C8Anim **,32)=anim;
}
sprite = func_02082028(0x12);
if (sprite) {
sprite->kind = 0; sprite->unk1=0; sprite->unk2=0; sprite->unk4=0;
sprite->unk6=1; sprite->unk8=0; sprite->unkA=1; sprite->unkC=1; sprite->unkE=0; sprite->unk10=0;
sprite->unk2=sprite->unk4;
}
M2C_FIELD(p,Unk0220C6C8Sprite **,0x50)=sprite;
func_020a9188(sprite,0x78);
M2C_FIELD(p,Unk0220C6C8Sprite **,0x50)->unk4=0xc000;
M2C_FIELD(p,Unk0220C6C8Sprite **,0x50)->unk8=7;
M2C_FIELD(p,Unk0220C6C8Sprite **,0x50)->unkA=7;
sprite = func_02082028(0x12);
if (sprite) {
sprite->kind = 1; sprite->unk1=0; sprite->unk2=0; sprite->unk4=0;
sprite->unk6=1; sprite->unk8=0; sprite->unkA=1; sprite->unkC=1; sprite->unkE=0; sprite->unk10=0;
sprite->unk2=sprite->unk4;
}
M2C_FIELD(p,Unk0220C6C8Sprite **,0x54)=sprite;
resetSprite=M2C_FIELD(p,Unk0220C6C8Sprite **,0x54);
resetSprite->unkE=0; resetSprite->unk10=0; resetSprite->unkC=0; resetSprite->unk2=resetSprite->unk4;
M2C_FIELD(p,u8 **,0x58)=func_02082028(0x1c);
M2C_FIELD(M2C_FIELD(p,u8 **,0x58),void **,0xc)=data_ov003_02210a4c;
M2C_FIELD(p,u8 **,0x58)[8]=1; M2C_FIELD(p,u8 **,0x58)[0]=0;
M2C_FIELD(M2C_FIELD(p,u8 **,0x58),s16 *,4)=0xc0;
M2C_FIELD(M2C_FIELD(p,u8 **,0x58),s16 *,2)=M2C_FIELD(M2C_FIELD(p,u8 **,0x58),s16 *,4);
M2C_FIELD(M2C_FIELD(p,u8 **,0x58),s16 *,6)=-4;
q=func_02082028(0x24);
if(q) {
M2C_FIELD(q,u16 *,0x10)=30; q[0x12]=0;
M2C_FIELD(q,u32 *,0)=0; M2C_FIELD(q,u32 *,4)=0;
M2C_FIELD(q,s8 *,8)=-1;M2C_FIELD(q,s8 *,9)=-1;M2C_FIELD(q,s8 *,10)=-1;M2C_FIELD(q,s8 *,11)=-1;q[13]=255;M2C_FIELD(q,s8 *,12)=-1;q[14]=0;q[15]=255;
M2C_FIELD(q,void **,0x14)=func_020e34bc(0x168);
func_02007f8c(M2C_FIELD(q,void **,0x14),0,0x168);
}
M2C_FIELD(p,u8 **,0x5c)=q;
q=func_02082028(0x20);
if(q) {
M2C_FIELD(q,void **,0)=&data_ov003_02211028;
q[6]=0;q[5]=0;q[4]=0;q[13]=0;q[12]=0;
M2C_FIELD(q,s16 *,10)=0; M2C_FIELD(q,s16 *,8)=0;
q[24]=0; M2C_FIELD(q,s16 *,22)=0; M2C_FIELD(q,s16 *,20)=0; M2C_FIELD(q,s16 *,18)=0; M2C_FIELD(q,s16 *,16)=0; M2C_FIELD(q,s16 *,14)=0;
func_020a9a1c(q,0,127);
q[12]=70;q[13]=24;M2C_FIELD(q,s16 *,8)=145;M2C_FIELD(q,s16 *,10)=6;
t=func_02082028(0x1c);
if(t) {
M2C_FIELD(t,void **,0)=data_ov003_02211018;
t[6]=0;t[5]=0;t[4]=0;t[17]=0;t[16]=0;
M2C_FIELD(t,s16 *,14)=0;M2C_FIELD(t,s16 *,12)=0;M2C_FIELD(t,s16 *,10)=0;M2C_FIELD(t,s16 *,8)=0;
M2C_FIELD(t,s16 *,24)=0;M2C_FIELD(t,s16 *,22)=0;M2C_FIELD(t,s16 *,20)=0;
M2C_FIELD(t,s16 *,18)=145;M2C_FIELD(t,s16 *,20)=215;M2C_FIELD(t,s16 *,22)=18;M2C_FIELD(t,s16 *,24)=18;
t[16]=16;t[17]=32;func_020a979c(t,180,18);
}
M2C_FIELD(q,u8 **,28)=t;
}
M2C_FIELD(p,u8 **,96)=q;
i=func_020bf9e0(); q=M2C_FIELD(p,u8 **,96); M2C_FIELD(q,s16 *,18)=i;
if(M2C_FIELD(q,s16 *,22)>=M2C_FIELD(q,s16 *,18)) M2C_FIELD(q,s16 *,18)=M2C_FIELD(q,s16 *,20)>M2C_FIELD(q,s16 *,18)?M2C_FIELD(q,s16 *,20):M2C_FIELD(q,s16 *,18);
base=M2C_FIELD(q,s16 *,8);
i=base+func_0207c8ec(M2C_FIELD(q,s16 *,18)*(s16)(M2C_FIELD(M2C_FIELD(q,u8 **,28),s16 *,20)-M2C_FIELD(M2C_FIELD(q,u8 **,28),s16 *,18)),M2C_FIELD(q,s16 *,22)-M2C_FIELD(q,s16 *,20));
func_020a979c(M2C_FIELD(q,u8 **,28),(s16)i,M2C_FIELD(M2C_FIELD(q,u8 **,28),s16 *,10));
q=func_02082028(0x20);
if(q) {
M2C_FIELD(q,void **,0)=&data_ov003_02211028;
q[6]=0;q[5]=0;q[4]=0;q[13]=0;q[12]=0;
M2C_FIELD(q,s16 *,10)=0; M2C_FIELD(q,s16 *,8)=0;
q[24]=0; M2C_FIELD(q,s16 *,22)=0; M2C_FIELD(q,s16 *,20)=0; M2C_FIELD(q,s16 *,18)=0; M2C_FIELD(q,s16 *,16)=0; M2C_FIELD(q,s16 *,14)=0;
func_020a9a1c(q,0,127);
q[12]=70;q[13]=24;M2C_FIELD(q,s16 *,8)=145;M2C_FIELD(q,s16 *,10)=36;
t=func_02082028(0x1c);
if(t) {
M2C_FIELD(t,void **,0)=data_ov003_02211018;
t[6]=0;t[5]=0;t[4]=0;t[17]=0;t[16]=0;
M2C_FIELD(t,s16 *,14)=0;M2C_FIELD(t,s16 *,12)=0;M2C_FIELD(t,s16 *,10)=0;M2C_FIELD(t,s16 *,8)=0;
M2C_FIELD(t,s16 *,24)=0;M2C_FIELD(t,s16 *,22)=0;M2C_FIELD(t,s16 *,20)=0;
M2C_FIELD(t,s16 *,18)=145;M2C_FIELD(t,s16 *,20)=215;M2C_FIELD(t,s16 *,22)=48;M2C_FIELD(t,s16 *,24)=48;
t[16]=16;t[17]=32;func_020a979c(t,180,48);
}
M2C_FIELD(q,u8 **,28)=t;
}
M2C_FIELD(p,u8 **,100)=q;
i=func_020bfa20(); q=M2C_FIELD(p,u8 **,100); M2C_FIELD(q,s16 *,18)=i;
if(M2C_FIELD(q,s16 *,22)>=M2C_FIELD(q,s16 *,18)) M2C_FIELD(q,s16 *,18)=M2C_FIELD(q,s16 *,20)>M2C_FIELD(q,s16 *,18)?M2C_FIELD(q,s16 *,20):M2C_FIELD(q,s16 *,18);
base=M2C_FIELD(q,s16 *,8);
i=base+func_0207c8ec(M2C_FIELD(q,s16 *,18)*(s16)(M2C_FIELD(M2C_FIELD(q,u8 **,28),s16 *,20)-M2C_FIELD(M2C_FIELD(q,u8 **,28),s16 *,18)),M2C_FIELD(q,s16 *,22)-M2C_FIELD(q,s16 *,20));
func_020a979c(M2C_FIELD(q,u8 **,28),(s16)i,M2C_FIELD(M2C_FIELD(q,u8 **,28),s16 *,10));
q=func_02082028(24);
if(q) { M2C_FIELD(q,u32 *,0)=0;M2C_FIELD(q,u32 *,4)=0;M2C_FIELD(q,u32 *,8)=0;M2C_FIELD(q,u32 *,12)=0;M2C_FIELD(q,u32 *,16)=0;M2C_FIELD(q,u32 *,20)=0; }
M2C_FIELD(p,u8 **,0x68)=q;
q=func_02082028(72);
if(q) {M2C_FIELD(q,void **,0)=data_ov003_0220fb28;M2C_FIELD(q,s32 *,4)=0;M2C_FIELD(q,s32 *,8)=2;M2C_FIELD(q,s32 *,12)=0;M2C_FIELD(q,s32 *,16)=1;q[20]=1;
M2C_FIELD(q,void **,24)=data_ov003_0220fb28;M2C_FIELD(q,s32 *,28)=0;M2C_FIELD(q,s32 *,32)=2;M2C_FIELD(q,s32 *,36)=0;M2C_FIELD(q,s32 *,40)=1;q[44]=1;
M2C_FIELD(q,void **,48)=data_ov003_0220fb28;M2C_FIELD(q,s32 *,52)=0;M2C_FIELD(q,s32 *,56)=1;M2C_FIELD(q,s32 *,60)=0;M2C_FIELD(q,s32 *,64)=1;q[68]=1;
M2C_FIELD(q,s32 *,4)=((u32)M2C_FIELD(data_0215d9b8,u16 *,6)<<18)>>30;
if(q[20]) { while(M2C_FIELD(q,s32 *,4)>M2C_FIELD(q,s32 *,8)) M2C_FIELD(q,s32 *,4)-=M2C_FIELD(q,s32 *,8)-M2C_FIELD(q,s32 *,12)+1; while(M2C_FIELD(q,s32 *,4)<M2C_FIELD(q,s32 *,12)) M2C_FIELD(q,s32 *,4)+=M2C_FIELD(q,s32 *,8)-M2C_FIELD(q,s32 *,12)+1; }
else { if(M2C_FIELD(q,s32 *,8)>=M2C_FIELD(q,s32 *,4)) M2C_FIELD(q,s32 *,4)=M2C_FIELD(q,s32 *,12)>M2C_FIELD(q,s32 *,4)?M2C_FIELD(q,s32 *,12):M2C_FIELD(q,s32 *,4); }
M2C_FIELD(q,s32 *,28)=((u32)M2C_FIELD(data_0215d9b8,u16 *,6)<<20)>>30;
if(q[44]) { while(M2C_FIELD(q,s32 *,28)>M2C_FIELD(q,s32 *,32)) M2C_FIELD(q,s32 *,28)-=M2C_FIELD(q,s32 *,32)-M2C_FIELD(q,s32 *,36)+1; while(M2C_FIELD(q,s32 *,28)<M2C_FIELD(q,s32 *,36)) M2C_FIELD(q,s32 *,28)+=M2C_FIELD(q,s32 *,32)-M2C_FIELD(q,s32 *,36)+1; }
else { if(M2C_FIELD(q,s32 *,32)>=M2C_FIELD(q,s32 *,28)) M2C_FIELD(q,s32 *,28)=M2C_FIELD(q,s32 *,36)>M2C_FIELD(q,s32 *,28)?M2C_FIELD(q,s32 *,36):M2C_FIELD(q,s32 *,28); }
M2C_FIELD(q,s32 *,52)=((u32)M2C_FIELD(data_0215d9b8,u16 *,6)<<17)>>31;
if(q[68]) { while(M2C_FIELD(q,s32 *,52)>M2C_FIELD(q,s32 *,56)) M2C_FIELD(q,s32 *,52)-=M2C_FIELD(q,s32 *,56)-M2C_FIELD(q,s32 *,60)+1; while(M2C_FIELD(q,s32 *,52)<M2C_FIELD(q,s32 *,60)) M2C_FIELD(q,s32 *,52)+=M2C_FIELD(q,s32 *,56)-M2C_FIELD(q,s32 *,60)+1; }
else { if(M2C_FIELD(q,s32 *,56)>=M2C_FIELD(q,s32 *,52)) M2C_FIELD(q,s32 *,52)=M2C_FIELD(q,s32 *,60)>M2C_FIELD(q,s32 *,52)?M2C_FIELD(q,s32 *,60):M2C_FIELD(q,s32 *,52); }
}
M2C_FIELD(p,u8 **,0x40)=q;
((Unk0220C6C8Nibbles *)(p+0x36))->high=2;
}
}

void *func_ov003_0220ea28(void *arg0) {
    void *r6 = arg0;
    u32 h;
    u8 cond;
    s32 i;
    void *p;

    M2C_FIELD(r6, M2C_UNK **, 0) = (M2C_UNK *)&data_ov003_02211060;

    h = (((u32)M2C_FIELD(r6, u8 *, 0x36) << 24) >> 28);
    cond = (h == 1);
    if (cond) {
        void *s = M2C_FIELD(r6, void **, 0x40);
RestoreBits12(M2C_FIELD(s,u32 *,4)); RestoreBits10(M2C_FIELD(s,u32 *,0x1c)); RestoreBit14(M2C_FIELD(s,u32 *,0x34));
    }

    h = (((u32)M2C_FIELD(r6, u8 *, 0x36) << 24) >> 28);
    cond = (h == 1);
    if (cond || (u8)(h == 2)) {
            void *s = M2C_FIELD(r6, void **, 0x3C);
            u8 v;
            M2C_FIELD(M2C_FIELD(r6,void **,0x3c),u8 *,15)=M2C_FIELD(r6,u8 *,0x39);
            s = M2C_FIELD(r6, void **, 0x3C);
            v = M2C_FIELD(s, u8 *, 0xF);
            M2C_FIELD(s, u8 *, v) = M2C_FIELD(r6, u8 *, 0x3A);
    }

{void *q=M2C_FIELD(M2C_FIELD(r6,void **,0x4c),void **,0x18); if(q) { if(M2C_FIELD(q,void **,0)) func_02082040(M2C_FIELD(q,void **,0)); func_02082040(q); } }
{void *q=M2C_FIELD(M2C_FIELD(r6,void **,0x4c),void **,0x1c); if(q) { if(M2C_FIELD(q,void **,0)) func_02082040(M2C_FIELD(q,void **,0)); func_02082040(q); } }
p=M2C_FIELD(r6,void **,0x4c); if(p) func_02082040(p);
for(i=0;i<6;i++) {
{void *q=M2C_FIELD((u8 *)M2C_FIELD(r6,void **,0x48)+i*0x24,void **,24); if(q) { if(M2C_FIELD(q,void **,0)) func_02082040(M2C_FIELD(q,void **,0)); func_02082040(q); } }
{void *q=M2C_FIELD((u8 *)M2C_FIELD(r6,void **,0x48)+i*0x24,void **,28); if(q) { if(M2C_FIELD(q,void **,0)) func_02082040(M2C_FIELD(q,void **,0)); func_02082040(q); } }
{void *q=M2C_FIELD((u8 *)M2C_FIELD(r6,void **,0x48)+i*0x24,void **,32); if(q) { if(M2C_FIELD(q,void **,0)) func_02082040(M2C_FIELD(q,void **,0)); func_02082040(q); } }
} func_0208204c(M2C_FIELD(r6,void **,0x48));
    p = M2C_FIELD(r6, void **, 0x50);
    if (p != NULL) func_02082040(p);

    p = M2C_FIELD(r6, void **, 0x54);
    if (p != NULL) func_02082040(p);

    p = M2C_FIELD(r6, void **, 0x58);
    if (p != NULL) func_02082040(p);

    p = M2C_FIELD(r6, void **, 0x5C);
    if (p != NULL) {
        void *q = M2C_FIELD(p, void **, 0x14);
        func_020e35cc(q);
        func_02082040(p);
    }

    p = M2C_FIELD(r6, void **, 0x60);
    if (p != NULL) {
        VFn *vt = M2C_FIELD(p, VFn **, 0);
        vt[1](p);
    }

    p = M2C_FIELD(r6, void **, 0x64);
    if (p != NULL) {
        VFn *vt = M2C_FIELD(p, VFn **, 0);
        vt[1](p);
    }

    p = M2C_FIELD(r6, void **, 0x68);
    if (p != NULL) {
{void *q=M2C_FIELD(p,void **,0);if(q)func_01ffa574(q);}
{void *q=M2C_FIELD(p,void **,4);if(q)func_01ffa574(q);}
{void *q=M2C_FIELD(p,void **,8);if(q)func_01ffa574(q);}
{void *q=M2C_FIELD(p,void **,12);if(q)func_01ffa574(q);}
{void *q=M2C_FIELD(p,void **,16);if(q)func_01ffa574(q);}
{void *q=M2C_FIELD(p,void **,20);if(q)func_01ffa574(q);}
        func_02082040(p);
    }

    p = M2C_FIELD(r6, void **, 0x40);
    if (p != NULL) func_02082040(p);

    func_020af71c();
    func_02082040(r6);
    return r6;
}

void *func_ov003_0220ed30(void *arg0) {
    extern M2C_UNK data_ov003_02211028;
    M2C_UNK func_02082040();
    void **temp_r0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov003_02211028;
    temp_r0 = M2C_FIELD(arg0, void ***, 0x1C);
    if (temp_r0 != NULL) {
        M2C_FIELD(*temp_r0, void (**)(void *), 4)(temp_r0);
    }
    func_02082040(arg0);
    return arg0;
}

s32 func_ov003_0220ed6c(s32 arg0) {
    M2C_UNK func_02082040();
    func_02082040();
    return arg0;
}
