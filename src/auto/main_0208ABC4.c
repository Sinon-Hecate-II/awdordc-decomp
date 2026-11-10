/* 24 functions from 0x0208ABC4 to 0x0208B884 (main), found by ds-decomp. */
#include "common.h"
extern void *gCur3DSpriteEngine, *g3DSpriteEngineMain, *g3DSpriteEngineSub;

typedef struct {
    u8 unk_0x00[0x58];
    s32 unk_0x58_0 : 6;
    s32 unk_0x58_6 : 2;
    s32 unk_0x58_8 : 24;
} Unk0208ABC4;

typedef struct { u32 width:9; u32 height:9; u32 rest:14; } WindowSize0208;
typedef struct { u16 low:6; u16 window:2; u16 high:8; } WindowControl0208;
u8 func_0208b5a8(void);

/* Updates the linked left/right objects' orientation fields when the entity is in state 3. */
M2C_UNK func_0208abc4(M2C_UNK arg0) {
    void func_0208ad48(void *);
    void func_0208af20(void *);
    u8 func_0208ae88(Unk0208ABC4 *, s32);
    M2C_UNK PlaySoundEffect(s32);
    void func_020d47d0(void);
    void func_020d47f0(void);
    extern u16 *gKeyState;
    register u32 mode asm("r0");

    if (((u32)(M2C_FIELD(arg0, u8 *, 0x48) << 26) >> 30) != 0) {
        return;
    }
    func_0208ad48(arg0);
    mode = (u8)((u32)(M2C_FIELD(arg0, s32 *, 0x58) << 29) >> 29);
    switch (mode) {
    case 1:
        if ((*(u16 *)gKeyState) & 3) {
            PlaySoundEffect(0x1000d);
            func_0208af20(arg0);
        }
        return;
    case 2:
        if ((*(u16 *)gKeyState) & 3) {
            PlaySoundEffect(0x1000d);
            func_0208af20(arg0);
        }
        return;
    case 3:
        if (((*(u16 *)gKeyState) & 0x20) && func_0208ae88((Unk0208ABC4 *)arg0, 0)) {
            PlaySoundEffect(0x10010);
        }
        if (((*(u16 *)gKeyState) & 0x10) && func_0208ae88((Unk0208ABC4 *)arg0, 1)) {
            PlaySoundEffect(0x10010);
        }
        if ((*(u16 *)gKeyState) & 1) {
            if (((M2C_FIELD(arg0, s32 *, 0x58) << 24) >> 30) == 0) {
                func_020d47d0();
                PlaySoundEffect(0x1000d);
            }
            if (((M2C_FIELD(arg0, s32 *, 0x58) << 24) >> 30) == 1) {
                func_020d47f0();
                PlaySoundEffect(0x1000f);
            }
            func_0208af20(arg0);
            return;
        }
        if ((*(u16 *)gKeyState) & 2) {
            func_020d47f0();
            PlaySoundEffect(0x1000f);
            func_0208af20(arg0);
        }
        return;
    }
    return;
}

void func_0208ad48(void *entity) {
    unsigned flagRight;
    unsigned flagLeft;
    void *objLeft;
    void *objRight;

    objLeft = M2C_FIELD(entity, void **, 0x5C);
    objRight = M2C_FIELD(entity, void **, 0x60);
    if ((u8) ((u32) (M2C_FIELD((int)entity, s32 *, 0x58) << 0x1D) >> 0x1D) != 3) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(objLeft, void **, 0x64), s8 *, 0xC) == 1) {
        flagLeft = 1;
    } else {
        flagLeft = 0;
    }
    if (flagLeft & 0xFF) {
        M2C_FIELD(entity, s32 *, 0x58) = (s32) (M2C_FIELD(entity, s32 *, 0x58) & ~0xC0);
    }
    if (M2C_FIELD(M2C_FIELD(objRight, void **, 0x64), s8 *, 0xC) == 1) {
        flagRight = 1;
    } else {
        flagRight = 0;
    }
    if (flagRight & 0xFF) {
        M2C_FIELD(entity, s32 *, 0x58) = (s32) ((M2C_FIELD(entity, s32 *, 0x58) & ~0xC0) | 0x40);
    }
    if (((s32) (M2C_FIELD(entity, s32 *, 0x58) << 0x18) >> 0x1E) == 0) {
        M2C_FIELD(objLeft, s32 *, 0x40) = (s32) ((M2C_FIELD(objLeft, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(objLeft, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(objRight, s32 *, 0x40) = (s32) ((M2C_FIELD(objRight, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) ((u32) (M2C_FIELD(objRight, u8 *, 0x59) << 0x1C) >> 0x1C) << 0x18) >> 6));
    }
    if (((s32) (M2C_FIELD(entity, s32 *, 0x58) << 0x18) >> 0x1E) != 1) {
        return;
    }
    M2C_FIELD(objLeft, s32 *, 0x40) = (s32) ((M2C_FIELD(objLeft, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) ((u32) (M2C_FIELD(objLeft, u8 *, 0x59) << 0x1C) >> 0x1C) << 0x18) >> 6));
    M2C_FIELD(objRight, s32 *, 0x40) = (s32) ((M2C_FIELD(objRight, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(objRight, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
}

u8 func_0208ae88(Unk0208ABC4 *arg0, s32 arg1) {
    s32 var_r3;
    var_r3 = arg0->unk_0x58_6 != arg1;
    arg0->unk_0x58_6 = arg1;
    return var_r3;
}

void func_0208aebc(void *arg0) {
    M2C_UNK func_02088da8();
    M2C_UNK func_0208a6b0(void *);
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) ((M2C_FIELD(arg0, s32 *, 0x58) & ~0x38) | 8);
    M2C_FIELD(arg0, u8 *, 0x48) = (u8) ((M2C_FIELD(arg0, u8 *, 0x48) & ~0x30) | 0x10);
    M2C_FIELD(arg0, s8 *, 0x4B) = 0;
    M2C_FIELD(arg0, s8 *, 0x4A) = 6;
    if (M2C_FIELD(arg0, s32 *, 0x5C) != 0) {
        func_02088da8();
    }
    if (M2C_FIELD(arg0, s32 *, 0x60) != 0) {
        func_02088da8();
    }
    func_0208a6b0(arg0);
}

void func_0208af20(void *arg0) {
    M2C_UNK func_0208a714(void *);
    s32 temp_r1;
    u32 temp_r2;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0x58);
    temp_r2 = (u32) (temp_r1 << 0x1A) >> 0x1D;
    if (temp_r2 == 0) {
        DeleteSpriteObject(arg0, temp_r1, temp_r2);
    } else {
        M2C_FIELD(arg0, s32 *, 0x58) = (s32) ((temp_r1 & ~0x38) | 0x18);
        M2C_FIELD(arg0, u8 *, 0x48) = (u8) ((M2C_FIELD(arg0, u8 *, 0x48) & ~0x30) | 0x20);
        M2C_FIELD(arg0, s8 *, 0x4B) = 0;
        M2C_FIELD(arg0, s8 *, 0x4A) = 8;
        if (M2C_FIELD(arg0, s32 *, 0x5C) != 0) {
            func_02088da8();
        }
        if (M2C_FIELD(arg0, s32 *, 0x60) != 0) {
            func_02088da8();
        }
    }
    func_0208a714(arg0);
}

void func_0208af98(void *p) {
 s32 EaseInterpolate(s32,s32,s32,s32,s32); void func_02088d94(void*);void func_02089c80(void*);s32 func_020890d4();void DrawTileRow(u16,u16,u16,u16,s32);void func_0208e18c(s16,s16,s16,s16,u16,s32);
 s32 bottom,right,tx,ty,j,maxw,i,depth,y,x,height,width; u8 alpha;u32 tile,mode,count;u16 frame;void *old,*engine; WindowControl0208 *volatile control;u8 *widths,*aligns;s32 w; u16 kind;
 frame=(u16)(0x1000|(0x3ff&(0xa0>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0)<<17)>>30))));
 tile=M2C_FIELD(p,u16*,0x3e)<<5;
 width=((WindowSize0208*)((u8*)p+0x40))->width;height=((WindowSize0208*)((u8*)p+0x40))->height;
 x=M2C_FIELD(p,s16*,0x34);y=M2C_FIELD(p,s16*,0x36);depth=M2C_FIELD(p,s8*,0x49);alpha=4;
 mode=(u32)(M2C_FIELD(p,u8*,0x48)<<26)>>30;
 switch(mode){
 case 1:
  M2C_FIELD(p,u8*,0x4b)++;
  if(M2C_FIELD(p,u8*,0x4b)>=M2C_FIELD(p,u8*,0x4a)){
   M2C_FIELD(p,u32*,0x58)=(M2C_FIELD(p,u32*,0x58)&~0x38)|0x10;
   M2C_FIELD(p,u8*,0x48)&=~0x30;
   if(M2C_FIELD(p,void**,0x5c))func_02088d94(M2C_FIELD(p,void**,0x5c));
   if(M2C_FIELD(p,void**,0x60))func_02088d94(M2C_FIELD(p,void**,0x60));
  }
  width=(EaseInterpolate(4,0,width,M2C_FIELD(p,u8*,0x4b),M2C_FIELD(p,u8*,0x4a))+4)&~7;
  x+=((s32)(((WindowSize0208*)((u8*)p+0x40))->width)-width)/2;
  if(!((u32)(M2C_FIELD(p,u32*,0x58)<<18)>>31))alpha=(u8)EaseInterpolate(0,0,4,M2C_FIELD(p,u8*,0x4b),M2C_FIELD(p,u8*,0x4a));
  break;
 case 2:
  M2C_FIELD(p,u8*,0x4b)++;
  if(M2C_FIELD(p,u8*,0x4b)>=M2C_FIELD(p,u8*,0x4a))func_02089c80(p);
  width=(EaseInterpolate(4,width,0,M2C_FIELD(p,u8*,0x4b),M2C_FIELD(p,u8*,0x4a))+4)&~7;
  x+=((s32)(((WindowSize0208*)((u8*)p+0x40))->width)-width)/2;
  alpha=(u8)EaseInterpolate(0,4,0,M2C_FIELD(p,u8*,0x4b),M2C_FIELD(p,u8*,0x4a));
  break;
 }
 right=x+width;bottom=y+height;old=gCur3DSpriteEngine;
 for(i=0;i<2;i++){
  engine=i==0?g3DSpriteEngineMain:g3DSpriteEngineSub;gCur3DSpriteEngine=engine;
  mode=(u32)(M2C_FIELD(p,u8*,0x48)<<28)>>29;
  if((mode!=0||engine==g3DSpriteEngineMain)&&(mode!=1||engine==g3DSpriteEngineSub)&&(mode!=3||engine==old)){
   if((u8)((u32)(M2C_FIELD(p,u32*,0x58)<<21)>>31)){
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x48)=x;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x4a)=y;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x49)=right;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x4b)=bottom;
    control=(WindowControl0208*)((u8*)M2C_FIELD(gCur3DSpriteEngine,void**,0)+0x12);control->window=3;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x51)=0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x52)=0;
    M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u8*,0x53)=alpha;
   }
   if(!func_020890d4(p)){
    maxw=0;count=(u32)(M2C_FIELD(p,u32*,0x58)<<10)>>28;
    if(count){widths=M2C_FIELD(p,u8**,0x68);for(j=0;j<count;j++)if(maxw<*widths++)maxw=M2C_FIELD(p,u8**,0x68)[j];}
    j=0;if(j<count){ty=y+8;tx=x+(width-maxw)/2;
    do {
     w=M2C_FIELD(p,u8**,0x68)[j];
     kind=(u16)(0x2000|(0x3ff&((tile>>5)>>((u32)(M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void**,0),u16*,0)<<17)>>30))));
     switch(M2C_FIELD(p,u8**,0x6c)[j]){
      case 2:DrawTileRow((u16)tx,(u16)ty,(u16)((w+31)&~31),kind,depth);break;
      case 3:DrawTileRow((u16)(tx+maxw-w),(u16)ty,(u16)((w+31)&~31),kind,depth);break;
      default:DrawTileRow((u16)(x+(width-(s32)w)/2),(u16)ty,(u16)((w+31)&~31),kind,depth);break;
     }
     tile+=((((s32)w+7)>>3)+3>>2)<<8;
     ty+=16;j++;
    }while(j<((u32)(M2C_FIELD(p,u32*,0x58)<<10)>>28));
   }}
   if(width>=8&&height>=8)func_0208e18c((s16)x,(s16)y,(s16)width,(s16)height,frame,depth);
  }
 }
 gCur3DSpriteEngine=old;
}

void func_0208b4e4(void) {
    M2C_UNK func_0208a750();
    func_0208a750();
}

void func_0208b4f0(void) {
    M2C_UNK func_0208ab78();
    func_0208ab78();
}

void func_0208b4fc(void) {
    M2C_UNK func_02089cb8();
    func_02089cb8();
}

void func_0208b508(void) {
    M2C_UNK func_02089d30();
    func_02089d30();
}

void func_0208b514(void) {
    M2C_UNK func_0208abc4();
    func_0208abc4();
}

void func_0208b520(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    void *func_020898d0(void);
    extern M2C_UNK data_021027f0;
    s32 temp_r4;
    void *var_r0;
    temp_r4 = func_0208b5a8();
    var_r0 = func_01ffa3dc(&data_021027f0, arg0);
    if (var_r0 != 0) var_r0 = func_020898d0();
    M2C_FIELD(var_r0, s32 *, 0x58) = (M2C_FIELD(var_r0, s32 *, 0x58) & ~0x2000) | ((u32)(temp_r4 << 31) >> 18);
}

void func_0208b564(s32 arg0) {
    void *func_01ffa444(M2C_UNK *, M2C_UNK);
    void *func_020898d0(void);
    extern M2C_UNK data_021027f0;
    s32 temp_r4;
    void *var_r0;
    temp_r4 = func_0208b5a8();
    var_r0 = func_01ffa444(&data_021027f0, arg0);
    if (var_r0 != 0) var_r0 = func_020898d0();
    M2C_FIELD(var_r0, s32 *, 0x58) = (M2C_FIELD(var_r0, s32 *, 0x58) & ~0x2000) | ((u32)(temp_r4 << 31) >> 18);
}

u8 func_0208b5a8(void) {
    u8 var_r0;
    if (func_0208b5ec() != 0) var_r0 = 1;
    else var_r0 = 0;
    return var_r0;
}

s32 func_0208b5c4(void) {
    s32 func_020890d4(void);
    if ((func_0208b5ec() != 0) && (func_020890d4() != 0)) return 1;
    return 0;
}

s32 func_0208b5ec(void) {
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_021027f0;
    return FindObjectByClass(&data_021027f0);
}

void func_0208b600(void *arg0) {
    M2C_UNK func_0208b884(s32);
    func_0208b884(M2C_FIELD(arg0, s32 *, 0x34));
}

void *func_0208b610(s32 arg0) {
    void *func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021026d8;
    void *p = func_01ffa3dc(&data_021026d8, 1);
    M2C_FIELD(p, s32 *, 0x34) = arg0;
    return p;
}

void *func_0208b630(void *arg0) {
    M2C_UNK func_02088e84(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_02089108();
    extern M2C_UNK data_021025e8;
    func_02089108();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_021025e8;
    M2C_FIELD(arg0, s16 *, 0x58) = 0;
    M2C_FIELD(arg0, s16 *, 0x5A) = 0;
    M2C_FIELD(arg0, s8 *, 0x5C) = 0;
    M2C_FIELD(arg0, s8 *, 0x5D) = 0x3C;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s16 *, 0x3C) = 0;
    M2C_FIELD(arg0, s16 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x36) = 0xC0;
    func_02088e84(arg0, 0, 0xA0, 0, 0xC0);
    return arg0;
}

void func_0208b698(M2C_UNK arg0, M2C_UNK arg1) {
extern void *g3DSpriteEngineSub;extern void *g3DSpriteEngineMain;extern void *gCur3DSpriteEngine;
s16 func_0209b91c(M2C_UNK,M2C_UNK);
void *old; s32 i; void *p; u32 mode;
old=gCur3DSpriteEngine;i=0;
do {
if(i==0)p=g3DSpriteEngineMain;else p=g3DSpriteEngineSub;
gCur3DSpriteEngine=p;
mode=(u32)(M2C_FIELD(arg0,u8 *,0x48)<<28)>>29;
if(((mode!=0)||(p==g3DSpriteEngineMain))&&((mode!=1)||(p==g3DSpriteEngineSub))&&((mode!=3)||(p==old))){
M2C_FIELD(arg0,s16 *,0x58)=func_0209b91c((u8 *)M2C_FIELD(p,void **,0x1c)+((M2C_FIELD(arg0,u16 *,0x3e)<<5)+0x400),arg1);
M2C_FIELD(arg0,s16 *,0x5a)=0;M2C_FIELD(arg0,u8 *,0x5c)=0;
}i++;
}while(i<2);
gCur3DSpriteEngine=old;
}

void func_0208b758(M2C_UNK arg0, M2C_UNK arg1) {
    s32 GetLocalizedText(M2C_UNK);
    func_0208b698(arg0, GetLocalizedText(arg1));
}

/* Refresh the display banks selected by the entity's mode, then allocate and link a handle for it. */
void func_0208b778(void *entity) {
    extern void *gCur3DSpriteEngine, *g3DSpriteEngineSub, *g3DSpriteEngineMain;
    extern u8 data_0211e1ec[], data_0211e12c[];
    void *savedBank;
    void *bank;
    u32 mode;
    s32 i;

    savedBank = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) {
            bank = g3DSpriteEngineMain;
        } else {
            bank = g3DSpriteEngineSub;
        }
        gCur3DSpriteEngine = bank;
        mode = (u32)(M2C_FIELD(entity, u8 *, 0x48) << 28) >> 29;
        if ((mode != 0 || bank == g3DSpriteEngineMain) &&
            (mode != 1 || bank == g3DSpriteEngineSub) &&
            (mode != 3 || bank == savedBank)) {
            func_0207c780(data_0211e1ec, M2C_FIELD(bank, u8 **, 0x1C) + (M2C_FIELD(entity, u16 *, 0x3E) << 5));
            func_01ff9e44(data_0211e12c, ((u16)((u32)(M2C_FIELD(entity, u32 *, 0x40) << 6) >> 24) + 16) << 5, 32);
            func_02091d4c(18);
        }
        i++;
    } while (i < 2);
    gCur3DSpriteEngine = savedBank;
    M2C_FIELD(entity, void **, 0x60) = func_0208b610((s32)entity);
}

void func_0208b868(void *arg0) {
    M2C_UNK DeleteSpriteObject(s32);
    DeleteSpriteObject(M2C_FIELD(arg0, s32 *, 0x60));
}

void func_0208b878(void) {
    M2C_UNK func_02088c78();
    func_02088c78();
}

