/* 3 functions from 0x0221CAA0 to 0x0221D818 (ov005), found by ds-decomp. */
#include "common.h"
static inline s32 boxWidth(void *p) { return p ? M2C_FIELD(p,u16*,4):0; }
static inline s32 boxHeight(void *p) { return p ? M2C_FIELD(p,u16*,6):0; }
static inline s32 boxX(void *p) { return p ? M2C_FIELD(p,s16*,0):0; }
static inline s32 boxY(void *p) { return p ? M2C_FIELD(p,s16*,2):0; }
static inline void boxPosition(void *p,s32 x,s32 y) { M2C_FIELD(p,s16*,0x34)=x; M2C_FIELD(p,s16*,0x36)=y; }
typedef struct { u32 width:9,height:9,other:14; } BoxSizeBits;
static inline void boxSize(void *p,u32 w,u32 h) { M2C_FIELD(p,u32*,0x40)=((M2C_FIELD(p,u32*,0x40)&~511)|(w&(-512U>>23)))&0xfffc01ff | ((h<<23)>>14); }

static inline void boxBounds(s32 x,s32 y,u32 w,u32 h,void *p) { boxPosition(p,x,y); boxSize(p,w,h); }
void func_ov005_0221cff8(void *arg0) {
void *func_01ffa770(void*);void *func_020896f0(void*);s32 func_020cfb94();s32 func_020ae22c();
extern u8 data_ov005_02220d50[];
s32 i,y;void *sprite,*p;s32 width,height;
func_020aad18(M2C_FIELD(func_01ffa770(data_ov005_02220d50),s32*,0x38));
func_020aad18(M2C_FIELD(func_01ffa770(data_ov005_02220d50),s32*,0x3c));
func_020aad18(M2C_FIELD(func_01ffa770(data_ov005_02220d50),s32*,0x40));
i=0;
if(func_020cfb94()>0){y=79;do{
func_02087d18(M2C_FIELD(arg0,void**,0x34),(s16)y,170,16,16,(u16)(i+3),12);
i++;y+=20;
}while(i<func_020cfb94());}
func_02087f00(M2C_FIELD(arg0,void**,0x34),3);
M2C_FIELD(arg0,void**,0x38)=func_020896f0(arg0);
func_020893a8(M2C_FIELD(arg0,void**,0x38),4096,1,func_020ae22c(9));
sprite=M2C_FIELD(arg0,void**,0x38);p=*(void**)M2C_FIELD(arg0,void**,0x34);
boxBounds(boxX(p)-1,boxY(p)-1,boxWidth(p)+2,boxHeight(p)+2,sprite);
func_02089438(M2C_FIELD(arg0,void**,0x38));
}

