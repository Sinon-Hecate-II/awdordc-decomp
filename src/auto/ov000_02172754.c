/* 10 functions from 0x02172754 to 0x02173468 (ov000), found by ds-decomp. */
#include "common.h"
extern s32 data_ov000_021b976c, data_ov000_021b9bec, data_ov000_021bb06c, data_ov000_021b9c6c, data_ov000_021b99ec, data_ov000_021bb1ec;
extern void *data_027e00c4;
extern void *gCur3DSpriteEngine;
extern M2C_UNK data_ov000_021c1944, data_ov000_021c13b0, data_ov000_021c11dc, data_ov000_021c1764, data_ov000_021c1b28, data_ov000_021c1d0c;

void func_ov000_02172aa0(void) {
 M2C_UNK func_0207c780(M2C_UNK *,s32); u32 func_ov000_02175074();
 void *saved; s32 base; M2C_UNK *p;
 base=M2C_FIELD(data_027e00c4,s32 *,0x28); saved=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c4;
 switch(func_ov000_02175074()) {
 case 0:p=&data_ov000_021c1944;break;
 case 1:p=&data_ov000_021c13b0;break;
 case 2:p=&data_ov000_021c11dc;break;
 case 3:p=&data_ov000_021c1764;break;
 case 4:p=&data_ov000_021c1b28;break;
 case 5:p=&data_ov000_021c1d0c;break;
 default:p=&data_ov000_021c1944;break;
 }
 func_0207c780(p,base);gCur3DSpriteEngine=saved;
}

void func_ov000_02172d28(void *arg0) {
 M2C_UNK func_020807e4(s32,s32,u16,s32);
 s32 func_ov000_0217244c(); s32 func_ov000_02172468(s32,s32);
 s32 base; void *saved; s32 ctx,value; s32 color;
 saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c4;
 ctx=func_ov000_0217244c();
 base=M2C_FIELD(data_027e00c4,s32 *,0x24);
 color=M2C_FIELD(arg0,s32 *,0)?0x52:1;
 value=func_ov000_02172468(ctx,*M2C_FIELD(arg0,s32 **,0x18));
 if(func_ov000_02172468(ctx,*M2C_FIELD(arg0,s32 **,0x18))) func_020807e4(value,base+0xc4,(u16)color,4);
 gCur3DSpriteEngine=saved;
}

void func_ov000_02172dc0(void *p){
M2C_UNK func_020807e4(s32,s32,u16,s32);
void *ctx,*saved;
if(M2C_FIELD(p,s32*,12)%4==0){
s32 *frames[6]={&data_ov000_021b976c,&data_ov000_021b9bec,&data_ov000_021bb06c,&data_ov000_021b9c6c,&data_ov000_021b99ec,&data_ov000_021bb1ec};
s32 index; u16 color; s32 **table=frames;
saved=gCur3DSpriteEngine;ctx=data_027e00c4;gCur3DSpriteEngine=ctx;
index=M2C_FIELD(p,s32*,12)/4;
color=M2C_FIELD(p,s32*,0)?0x52:1;
func_020807e4((s32)table[index],M2C_FIELD(ctx,s32*,0x24)+0xc4,(u16)color,4);
M2C_FIELD(gCur3DSpriteEngine,u8*,0x46)|=2;
gCur3DSpriteEngine=saved;
}
M2C_FIELD(p,s32*,12)++;
if(M2C_FIELD(p,s32*,12)>=24)M2C_FIELD(p,s32*,12)=0;
}

void func_ov000_02173058(void *arg0) {
 s32 func_ov000_0217244c();
 s32 func_ov000_021724b8(s32,s32);
 s32 func_020e3438(s32);
 void func_02007ef4(s32,s32);
 s32 base; void *saved; s32 index;
 saved=gCur3DSpriteEngine; gCur3DSpriteEngine=data_027e00c4;
 index=func_ov000_021724b8(func_ov000_0217244c(),*M2C_FIELD(arg0,s32 **,0x18));
 base=M2C_FIELD(gCur3DSpriteEngine,s32 *,0x1c);
 if(index!=-1) func_02007ef4(func_020e3438(2)+(s16)index*0x4e0,base+0x2880);
 gCur3DSpriteEngine=saved;
}

void func_ov000_02173290(void *arg0) {
    M2C_UNK func_ov000_02172b4c(void *);
    void func_ov000_02173058();
    func_ov000_02173058();
    if (M2C_FIELD(arg0, u8 *, 0x15) != 0) {
        return;
    }
    func_ov000_02172b4c(arg0);
    M2C_FIELD(arg0, s32 *, 0) = (s32) (1 - M2C_FIELD(arg0, s32 *, 0));
}
