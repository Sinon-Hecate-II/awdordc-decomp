/* 3 functions from 0x022231F8 to 0x02223CB8 (ov011), found by ds-decomp. */
#include "common.h"
typedef struct { s32 words[5]; } ContextTemplate;
extern ContextTemplate data_ov011_02227f28;
extern void *gCur3DSpriteEngine, *data_027e00c8, *data_027e00c4;

M2C_UNK func_ov011_022231f8() { return 0; }

void func_ov011_02223b70(s32 unused,s32 value,u32 mode) {
void func_02082a8c(void*,void*);
ContextTemplate temp=data_ov011_02227f28;
void *saved,*p; s32 i;
if(mode<2)return;
i=0;
if(value==0){saved=gCur3DSpriteEngine;
do {
if(i==0)p=data_027e00c8;else p=data_027e00c4;
gCur3DSpriteEngine=p;
switch(mode){case 2:func_02082a8c(&temp,(u8*)*(void**)p+0x14);break;case 3:func_02082a8c(&temp,(u8*)*(void**)p+0x24);break;}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;return;}
((s16*)&temp)[7]=value;
((s16*)&temp)[6]=((s16*)&temp)[7];
saved=gCur3DSpriteEngine;
do {
if(i==0)p=data_027e00c8;else p=data_027e00c4;
gCur3DSpriteEngine=p;
switch(mode){case 2:func_02082a8c(&temp,(u8*)*(void**)p+0x14);break;case 3:func_02082a8c(&temp,(u8*)*(void**)p+0x24);break;}
i++;
}while(i<2);
gCur3DSpriteEngine=saved;
}
