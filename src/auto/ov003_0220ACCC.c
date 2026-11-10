/* 13 functions from 0x0220ACCC to 0x0220BCAC (ov003), found by ds-decomp. */
#include "common.h"

/* Configures the path entries for the selected table index, using the simple path for 0/1 entries. */
void func_ov003_0220accc(void *obj, s32 index) {
    extern u8 data_ov003_0220f238[];
    extern u8 data_ov003_02210a4c[];

    void *table = data_ov003_0220f238 + index * 16;
    void *state;
    u8 count;
    u8 i;
    s32 active;

    M2C_FIELD(M2C_FIELD(obj, void **, 0x58), u8 *, 8) = M2C_FIELD(table, u8 *, 2);
    state = M2C_FIELD(obj, void **, 0x58);
    count = M2C_FIELD(state, u8 *, 8);

    if (count <= 1U) {
        goto simple;
    }

    if (M2C_FIELD(M2C_FIELD(obj, void **, 0x3C), u8 *, 15) == 8) {
        active = 1;
    } else {
        active = 0;
    }

    if (active & 255) {
    simple:
        M2C_FIELD(state, u8 *, 0) = 0;
        M2C_FIELD(M2C_FIELD(obj, void **, 0x58), u8 *, 8) = 1;
        M2C_FIELD(M2C_FIELD(obj, void **, 0x58), s16 *, 4) = 0xC0;
        M2C_FIELD(M2C_FIELD(obj, void **, 0x58), s16 *, 6) = 6;
        return;
    }

    for (i = 0; i < count; i++) {
        M2C_FIELD(state + i * 4, void **, 12) = data_ov003_02210a4c + M2C_FIELD(table + i, u8 *, 3) * 8;
        state = M2C_FIELD(obj, void **, 0x58);
        count = M2C_FIELD(state, u8 *, 8);
    }

    M2C_FIELD(state, u8 *, 1) = 0;
    M2C_FIELD(M2C_FIELD(obj, void **, 0x58), u8 *, 0) = 1;
    M2C_FIELD(M2C_FIELD(obj, void **, 0x58), s16 *, 4) = 0xA0;
    M2C_FIELD(M2C_FIELD(obj, void **, 0x58), s16 *, 6) = -4;
}

void func_ov003_0220adb4(void *a) {
#pragma opt_common_subs off
extern void *gKeyState,*gTouchState;
u8 func_ov003_02207c5c(void *);
s16 func_ov003_0220b7b8(void *);
void func_ov003_0220b7c0(void *);
u8 func_ov003_0220b7fc(void *,s32);
u8 func_ov003_0220b8ac(void *,s32);
u8 func_ov003_0220bb40(void *,s32);
void func_ov003_0220b830(void *,s32);
void func_ov003_0220b8e0(void *,s32);
void func_ov003_0220b9a0(void *,s32);
void func_ov003_0220ba70(void *,s32);
void func_ov003_0220bb88(void *);
void func_ov003_0220bbcc(void *);
s32 i,left,right,active,pos,old;u16 held,press;
if(!((u32)(M2C_FIELD(a,u8 *,0x38)<<31)>>31))return;
i=func_ov003_02207c5c(a);
left=func_ov003_0220b7b8(M2C_FIELD(a,void **,0x60));
right=func_ov003_0220b7b8(M2C_FIELD(a,void **,0x64));
active=1;
func_ov003_0220b7c0(M2C_FIELD(a,void **,0x68));
held=M2C_FIELD(gKeyState,u16 *,2);press=M2C_FIELD(gKeyState,u16 *,0);
if((((held&64)&&i!=0)||(press&64))&&!M2C_FIELD(gTouchState,u8 *,0x12)) {
if(i==0){if(press&64)i=M2C_FIELD(M2C_FIELD(a,void **,0x44),u8 *,0)-1;else i=func_ov003_02207c5c(a);}else i--;
}else if((((held&128)&&i!=M2C_FIELD(M2C_FIELD(a,void **,0x44),u8 *,0)-1)||(press&128))&&!M2C_FIELD(gTouchState,u8 *,0x12)){
if(i==M2C_FIELD(M2C_FIELD(a,void **,0x44),u8 *,0)-1){if(press&128)i=0;else i=func_ov003_02207c5c(a);}else i++;
}
held=M2C_FIELD(gKeyState,u16 *,2);
if((held&32)&&!M2C_FIELD(gTouchState,u8 *,0x12)){
if(func_ov003_0220b7fc(a,(u8)i))func_ov003_0220b830(M2C_FIELD(a,void **,0x60),-8);
if(func_ov003_0220b8ac(a,(u8)i))func_ov003_0220b830(M2C_FIELD(a,void **,0x64),-8);
if(func_ov003_02207e38(a,(u8)i)){func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,4));if(func_ov003_02209274(a,(u8)i))func_ov003_0220b8e0(M2C_FIELD(a,void **,0x40),-1);if(func_ov003_022092a8(a,(u8)i))func_ov003_0220b9a0(M2C_FIELD(a,void **,0x40),-1);if(func_ov003_022092dc(a,(u8)i))func_ov003_0220ba70(M2C_FIELD(a,void **,0x40),-1);}
if(func_ov003_0220bb40(a,(u8)i))PlaySoundEffect(0x10011);
func_ov003_0220bb88(a);
}
else if((held&16)&&!M2C_FIELD(gTouchState,u8 *,0x12)){
if(func_ov003_0220b7fc(a,(u8)i))func_ov003_0220b830(M2C_FIELD(a,void **,0x60),8);
if(func_ov003_0220b8ac(a,(u8)i))func_ov003_0220b830(M2C_FIELD(a,void **,0x64),8);
if(func_ov003_02207e38(a,(u8)i)){func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,8));if(func_ov003_02209274(a,(u8)i))func_ov003_0220b8e0(M2C_FIELD(a,void **,0x40),1);if(func_ov003_022092a8(a,(u8)i))func_ov003_0220b9a0(M2C_FIELD(a,void **,0x40),1);if(func_ov003_022092dc(a,(u8)i))func_ov003_0220ba70(M2C_FIELD(a,void **,0x40),1);}
if(func_ov003_0220bb40(a,(u8)i))PlaySoundEffect(0x10011);
func_ov003_0220bb88(a);
}

if((M2C_FIELD(gKeyState,u16 *,0)&0x800)&&!M2C_FIELD(gTouchState,u8 *,0x12)){
if(func_ov003_02207a70(a)&&func_ov003_02207a54(a))func_ov003_0220bbcc(a);active=0;
}
if(active&&(M2C_FIELD(gKeyState,u16 *,0)&4)&&!M2C_FIELD(gTouchState,u8 *,0x12)){
if(func_ov003_02207a70(a)){func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,12));func_ov003_0220bcac(a);PlaySoundEffect(0x1000d);func_ov003_0220bb88(a);}
if(func_ov003_02209258(a)){
if(func_020e4b28(i)){RequestMenuMode(a,2);func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,16));func_020b4df4(i,a);PlaySoundEffect(0x1000d);}
else PlaySoundEffect(0x1001d);
} active=0;
}
if(i!=func_ov003_02207c5c(a)){func_02087ec0(M2C_FIELD(a,void **,0x5c),(s16)(i+11));PlaySoundEffect(0x10010);}
func_020a98c4(M2C_FIELD(a,void **,0x60));
if(!func_ov003_02209cc8(M2C_FIELD(a,void **,0x60)))func_020a98c4(M2C_FIELD(a,void **,0x64));
if(func_ov003_02209cc8(M2C_FIELD(a,void **,0x60))&&!func_ov003_0220b7fc(a,func_ov003_02207c5c(a)))func_02087ec0(M2C_FIELD(a,void **,0x5c),11);
if(func_ov003_02209cc8(M2C_FIELD(a,void **,0x64))&&!func_ov003_0220b8ac(a,func_ov003_02207c5c(a)))func_02087ec0(M2C_FIELD(a,void **,0x5c),12);
if(!func_ov003_02209cc8(M2C_FIELD(a,void **,0x60))&&!func_ov003_02209cc8(M2C_FIELD(a,void **,0x64)))func_02088044(M2C_FIELD(a,void **,0x5c));
old=func_ov003_02207c5c(a);pos=func_ov003_0220bf68(M2C_FIELD(a,void **,0x5c));
if((active&&(M2C_FIELD(gKeyState,u16 *,0)&9)&&!M2C_FIELD(gTouchState,u8 *,0x12))||old==pos-11){func_ov003_0220c190(a,(u16)old);active=0;}
else if((active&&(M2C_FIELD(gKeyState,u16 *,0)&2)&&!M2C_FIELD(gTouchState,u8 *,0x12))||func_ov003_021e88a4(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,0))){
func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,0));func_ov003_0220c328(a,(u16)old);PlaySoundEffect(0x1000f);active=0;
}else if(active&&func_ov003_02207a54(a)&&func_ov003_021e88a4(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,20))){
if(func_ov003_02207a70(a))func_ov003_0220bbcc(a);active=0;
}else if(active&&func_ov003_021e88a4(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,12))){
if(func_ov003_02207a70(a)){func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,12));func_ov003_0220bcac(a);PlaySoundEffect(0x1000d);func_ov003_0220bb88(a);}active=0;
}
if(func_ov003_02209258(a)){if(func_020e4b28(old))func_ov003_021ebc54(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,16));else func_ov003_021ebc00(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,16));}
if(active&&func_ov003_021ebbcc(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,16))&&func_ov003_021e88a4(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,16))){
if(func_ov003_02209258(a)){RequestMenuMode(a,2);func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,16));func_020b4df4(old,a);PlaySoundEffect(0x1000d);}active=0;
}
if(active&&pos>=3&&pos<=M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8)+2){
func_ov003_0220a698(a,M2C_FIELD(M2C_FIELD(M2C_FIELD(a,void **,0x58)+(pos-3)*4,void **,12),u8 *,4));
M2C_FIELD(a,u8 *,0x34)=30;func_ov003_0220828c(a,5,255);func_ov003_0220bf70(a);PlaySoundEffect(0x1000f);active=0;
}
if(active&&func_ov003_021e88a4(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,4))){
func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,4));
if(func_ov003_02209274(a,(u8)old))func_ov003_0220b8e0(M2C_FIELD(a,void **,0x40),-1);if(func_ov003_022092a8(a,(u8)old))func_ov003_0220b9a0(M2C_FIELD(a,void **,0x40),-1);if(func_ov003_022092dc(a,(u8)old))func_ov003_0220ba70(M2C_FIELD(a,void **,0x40),-1);if(func_ov003_0220bb40(a,(u8)old))PlaySoundEffect(0x10011);func_ov003_0220bb88(a);}
if(active&&func_ov003_021e88a4(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,8))){
func_ov003_021ebb88(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,8));
if(func_ov003_02209274(a,(u8)old))func_ov003_0220b8e0(M2C_FIELD(a,void **,0x40),1);if(func_ov003_022092a8(a,(u8)old))func_ov003_0220b9a0(M2C_FIELD(a,void **,0x40),1);if(func_ov003_022092dc(a,(u8)old))func_ov003_0220ba70(M2C_FIELD(a,void **,0x40),1);if(func_ov003_0220bb40(a,(u8)old))PlaySoundEffect(0x10011);func_ov003_0220bb88(a);}

if(left!=func_ov003_0220b7b8(M2C_FIELD(a,void **,0x60))){PlaySoundEffect(0x10011);func_ov003_0220bb88(a);}
if(right!=func_ov003_0220b7b8(M2C_FIELD(a,void **,0x64))){PlaySoundEffect(0x10011);func_ov003_0220bb88(a);}
M2C_FIELD(a,u8 *,0x37)=(M2C_FIELD(a,u8 *,0x37)&~0xf0)|((u32)((u8)old<<28)>>24);
if(!((u32)(M2C_FIELD(a,u8 *,0x38)<<26)>>31)){
if(((u32)(M2C_FIELD(a,u8 *,0x37)<<28)>>28)==((u32)(M2C_FIELD(a,u8 *,0x37)<<24)>>28))return;
}
func_ov003_02207b84(a);
M2C_FIELD(a,u8 *,0x37)=(M2C_FIELD(a,u8 *,0x37)&~15)|(((u32)(M2C_FIELD(a,u8 *,0x37)<<24)>>28)&15);
if(!func_ov003_0220801c(a)&&M2C_FIELD(gTouchState,u8 *,0x12))PlaySoundEffect(0x10010);
M2C_FIELD(a,u8 *,0x38)&=~32;
}
#pragma opt_common_subs reset
s16 func_ov003_0220b7b8(void *arg0) {
    return M2C_FIELD(arg0, s16 *, 0x12);
}

void func_ov003_0220b7c0(void *arg0) {
    M2C_UNK MenuSpriteUpdate(s32);
    MenuSpriteUpdate(M2C_FIELD(arg0, s32 *, 0));
    MenuSpriteUpdate(M2C_FIELD(arg0, s32 *, 4));
    MenuSpriteUpdate(M2C_FIELD(arg0, s32 *, 8));
    MenuSpriteUpdate(M2C_FIELD(arg0, s32 *, 0xC));
    MenuSpriteUpdate(M2C_FIELD(arg0, s32 *, 0x10));
    MenuSpriteUpdate(M2C_FIELD(arg0, s32 *, 0x14));
}

u8 func_ov003_0220b7fc(void *arg0, s32 arg1) { s32 active; s32 result; if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active=1; else active=0; if ((active & 255) && arg1 == 0) result=1; else result=0; return result; }

void func_ov003_0220b830(void *arg0, s32 arg1) {
 s32 Divide(s32,s32); M2C_UNK func_020a979c(void *,s16,s16);
 s32 current,limit; s32 x; s16 base; void *p;
 M2C_FIELD(arg0,s16 *,0x12) += arg1;
 limit=M2C_FIELD(arg0,s16 *,0x16); current=M2C_FIELD(arg0,s16 *,0x12);
 if(current<=limit){limit=M2C_FIELD(arg0,s16 *,0x14); if(current>=limit)limit=current;}
 M2C_FIELD(arg0,s16 *,0x12)=limit;
 p=M2C_FIELD(arg0,void **,0x1c);
 base=M2C_FIELD(arg0,s16 *,8); x=base+Divide(M2C_FIELD(arg0,s16 *,0x12)*(s16)(M2C_FIELD(p,s16 *,0x14)-M2C_FIELD(p,s16 *,0x12)),M2C_FIELD(arg0,s16 *,0x16)-M2C_FIELD(arg0,s16 *,0x14));
 p=M2C_FIELD(arg0,void **,0x1c); func_020a979c(p,(s16)x,M2C_FIELD(p,s16 *,0xa));
}

u8 func_ov003_0220b8ac(void *arg0, s32 arg1) { s32 active; s32 result; if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) active=1; else active=0; if ((active & 255) && arg1 == 1) result=1; else result=0; return result; }

void func_ov003_0220b8e0(void *arg0,s32 arg1){
 s32 func_ov003_02206690(s32,s32,s32); s32 value,limit;
 value=arg1+M2C_FIELD(arg0,s32 *,4);
 func_ov003_02206690((s16)value,(s16)M2C_FIELD(arg0,s32 *,12),(s16)M2C_FIELD(arg0,s32 *,8));
 M2C_FIELD(arg0,s32 *,4)=value;
 if(M2C_FIELD(arg0,u8 *,20)){
 while(M2C_FIELD(arg0,s32 *,4)>M2C_FIELD(arg0,s32 *,8)) M2C_FIELD(arg0,s32 *,4)-=M2C_FIELD(arg0,s32 *,8)-M2C_FIELD(arg0,s32 *,12)+1;
 while(M2C_FIELD(arg0,s32 *,4)<M2C_FIELD(arg0,s32 *,12)) M2C_FIELD(arg0,s32 *,4)+=M2C_FIELD(arg0,s32 *,8)-M2C_FIELD(arg0,s32 *,12)+1;
 }else{value=M2C_FIELD(arg0,s32 *,4);limit=M2C_FIELD(arg0,s32 *,8);if(value<=limit){limit=M2C_FIELD(arg0,s32 *,12);if(value>=limit)limit=value;}M2C_FIELD(arg0,s32 *,4)=limit;}
}

void func_ov003_0220b9a0(void *arg0,s32 arg1){
 s32 func_ov003_02206690(s32,s32,s32); s32 value,limit;
 value=arg1+M2C_FIELD(arg0,s32 *,0x1c);
 func_ov003_02206690((s16)value,(s16)M2C_FIELD(arg0,s32 *,0x24),(s16)M2C_FIELD(arg0,s32 *,0x20));
 M2C_FIELD(arg0,s32 *,0x1c)=value;
 if(M2C_FIELD(arg0,u8 *,0x2c)){
 while(M2C_FIELD(arg0,s32 *,0x1c)>M2C_FIELD(arg0,s32 *,0x20)) M2C_FIELD(arg0,s32 *,0x1c)-=M2C_FIELD(arg0,s32 *,0x20)-M2C_FIELD(arg0,s32 *,0x24)+1;
 while(M2C_FIELD(arg0,s32 *,0x1c)<M2C_FIELD(arg0,s32 *,0x24)) M2C_FIELD(arg0,s32 *,0x1c)+=M2C_FIELD(arg0,s32 *,0x20)-M2C_FIELD(arg0,s32 *,0x24)+1;
 }else{limit=M2C_FIELD(arg0,s32 *,0x20);value=M2C_FIELD(arg0,s32 *,0x1c);if(value<=limit){limit=M2C_FIELD(arg0,s32 *,0x24);if(value>=limit)limit=value;}M2C_FIELD(arg0,s32 *,0x1c)=limit;}
}

void func_ov003_0220ba70(void *arg0,s32 arg1){
 s32 func_ov003_02206690(s32,s32,s32); s32 value,limit;
 value=arg1+M2C_FIELD(arg0,s32 *,0x34);
 func_ov003_02206690((s16)value,(s16)M2C_FIELD(arg0,s32 *,0x3c),(s16)M2C_FIELD(arg0,s32 *,0x38));
 M2C_FIELD(arg0,s32 *,0x34)=value;
 if(M2C_FIELD(arg0,u8 *,0x44)){
 while(M2C_FIELD(arg0,s32 *,0x34)>M2C_FIELD(arg0,s32 *,0x38)) M2C_FIELD(arg0,s32 *,0x34)-=M2C_FIELD(arg0,s32 *,0x38)-M2C_FIELD(arg0,s32 *,0x3c)+1;
 while(M2C_FIELD(arg0,s32 *,0x34)<M2C_FIELD(arg0,s32 *,0x3c)) M2C_FIELD(arg0,s32 *,0x34)+=M2C_FIELD(arg0,s32 *,0x38)-M2C_FIELD(arg0,s32 *,0x3c)+1;
 }else{limit=M2C_FIELD(arg0,s32 *,0x38);value=M2C_FIELD(arg0,s32 *,0x34);if(value<=limit){limit=M2C_FIELD(arg0,s32 *,0x3c);if(value>=limit)limit=value;}M2C_FIELD(arg0,s32 *,0x34)=limit;}
}

u8 func_ov003_0220bb40(void *arg0, s32 arg1) {
    s32 func_ov003_02206690(s32, s32, s32);
    s32 var_r0;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if ((var_r0 & 0xFF) && (func_ov003_02206690(arg1, 2, 4) != 0)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return (u8) var_r0;
}

void func_ov003_0220bb88(void *arg0) {
    s32 var_r1;
    s32 var_r1_2;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x36) << 0x18) >> 0x1C) == 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    if (!(var_r1 & 0xFF)) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) {
        var_r1_2 = 1;
    } else {
        var_r1_2 = 0;
    }
    if (var_r1_2 & 0xFF) {
        M2C_FIELD(arg0, u8 *, 0x38) = (u8) (M2C_FIELD(arg0, u8 *, 0x38) | 0x80);
    }
}

/* Updates the entity's linked object orientation and commits derived state to globals. */
void func_ov003_0220bbcc(void *entity) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK PlaySoundEffect(s32);
    M2C_UNK func_020d47d0();
    M2C_UNK func_020d885c(M2C_UNK);
    extern M2C_UNK data_0215d9b8;
    void *subObject;
    void *linkedObject;

    subObject = M2C_FIELD(M2C_FIELD(entity, void **, 0x68), void **, 0x14);
    if ((s32) M2C_FIELD(subObject, s8 *, 0x5A) >= 0) {
        M2C_FIELD(subObject, s32 *, 0x40) = (s32) ((M2C_FIELD(subObject, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(subObject, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(subObject, s8 *, 0x5A) = 0xC;
    }
    func_020d47d0();
    func_020d885c(0x12);
    func_01ffa6fc(entity);
    PlaySoundEffect(0x1000E);
    linkedObject = M2C_FIELD(entity, void **, 0x40);
    M2C_FIELD(&data_0215d9b8, u16 *, 6) = (u16) ((M2C_FIELD(&data_0215d9b8, u16 *, 6) & ~0x3000) | ((u32) ((u16) M2C_FIELD(linkedObject, s32 *, 4) << 0x1E) >> 0x12));
    M2C_FIELD(&data_0215d9b8, u16 *, 6) = (u16) ((M2C_FIELD(&data_0215d9b8, u16 *, 6) & ~0xC00) | ((u32) ((u16) M2C_FIELD(linkedObject, s32 *, 0x1C) << 0x1E) >> 0x14));
    M2C_FIELD(&data_0215d9b8, u16 *, 6) = (u16) ((M2C_FIELD(&data_0215d9b8, u16 *, 6) & ~0x4000) | ((u32) ((u16) M2C_FIELD(linkedObject, s32 *, 0x34) << 0x1F) >> 0x11));
}

