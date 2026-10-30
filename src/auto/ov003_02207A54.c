/* 13 functions from 0x02207A54 to 0x0220856C (ov003), found by ds-decomp. */
#include "common.h"
static inline void ResetSlot(void *p, u16 value) {
M2C_FIELD(p,s32 *,8)=M2C_FIELD(p,s32 *,4);
M2C_FIELD(p,u16 *,12)=value;
func_020a9218(p);
M2C_FIELD(p,u8 *,14)=value;
M2C_FIELD(p,u8 *,15)=M2C_FIELD(p,u8 *,14);
}

/* Point both animation slots of a sprite at anim, clear its timer and flags. */
static inline void SetSlotAnim(void *p, s32 anim) {
M2C_FIELD(p,s32 *,4)=anim;
M2C_FIELD(p,s32 *,8)=anim;
M2C_FIELD(p,u16 *,12)=0;
func_020a9218(p);
M2C_FIELD(p,u8 *,14)=0;
M2C_FIELD(p,u8 *,15)=M2C_FIELD(p,u8 *,14);
}

extern u8 data_ov003_02210ac4[];
extern u8 data_ov003_02210c44[];

u8 func_ov003_02207a54(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x36) << 0x18) >> 0x1C) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov003_02207a70(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), u8 *, 0xF) == 8) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

/* Reset the 6 child slots of the given structure to their initial state. */
void func_ov003_02207a8c(void *arg0) {
    s32 slotOff;
    u8 i;
    void *cfg;
    void *slot;
    void *slot2;
    void *slot3;

    cfg = M2C_FIELD(arg0, void **, 0x50);
    i = 0;
    M2C_FIELD(cfg, u16 *, 2) = (u16) M2C_FIELD(cfg, u16 *, 4);
    do {
        slotOff = i * 0x24;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 4) = 1;
        i += 1;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s16 *, 6) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s16 *, 8) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0xA) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0xB) = 0;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s16 *, 0xE) = 0xCD;
        slot = M2C_FIELD(arg0, s32 *, 0x48) + slotOff;
        M2C_FIELD(slot, u16 *, 0xC) = (u16) M2C_FIELD(slot, u16 *, 0xE);
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x10) = 8;
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x12) = 0;
        slot2 = M2C_FIELD(arg0, s32 *, 0x48) + slotOff;
        M2C_FIELD(slot2, u8 *, 0x11) = (u8) M2C_FIELD(slot2, u8 *, 0x12);
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x14) = 5;
        slot3 = M2C_FIELD(arg0, s32 *, 0x48) + slotOff;
        M2C_FIELD(slot3, s8 *, 0x13) = (s8) M2C_FIELD(slot3, s8 *, 0x14);
        M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x48) + slotOff), s8 *, 0x15) = 1;
    } while ((u32) i < 6U);
    M2C_FIELD(arg0, u8 *, 0x38) = (u8) (M2C_FIELD(arg0, u8 *, 0x38) | 0x20);
}

#pragma thumb off
void func_ov003_02207b84(void *arg0) {
void func_ov003_02207c7c(void *); void func_ov003_02207e80(void *);
s32 var_ip,var_lr,var_r5,var_r5_2,var_r6,var_r7; void *temp_r8; s32 var_r9,var_r10; void *temp_r1,*temp_r5;
temp_r1=M2C_FIELD(arg0,void **,0x50);var_r9=0;
M2C_FIELD(temp_r1,u16 *,2)=M2C_FIELD(temp_r1,u16 *,4);
if((s32)*M2C_FIELD(arg0,u8 **,0x44)>0){
var_r10=0;
do{
temp_r8=M2C_FIELD(arg0,u8 **,0x48)+var_r10;
temp_r5=*M2C_FIELD(arg0,void ***,0x5c);
if(temp_r5!=NULL)var_r5=M2C_FIELD(temp_r5,u16 *,8);else var_r5=-1U;
if(var_r9==(u8)(var_r5-11)){var_r6=256;var_r7=16;var_ip=1;var_lr=2;var_r5_2=3;}
else{var_r6=205;var_r7=8;var_ip=0;var_lr=5;var_r5_2=1;}
M2C_FIELD(temp_r8,s8 *,0x12)=var_ip;
M2C_FIELD(temp_r8,s8 *,0x14)=var_lr;
M2C_FIELD(temp_r8,s8 *,0x15)=var_r5_2;
M2C_FIELD(temp_r8,s16 *,0xe)=var_r6;
M2C_FIELD(temp_r8,s8 *,0x10)=var_r7;
var_r10+=36;var_r9++;
}while(var_r9<(s32)*M2C_FIELD(arg0,u8 **,0x44));
}
func_ov003_02207e80(arg0);func_ov003_02207c7c(arg0);
}
u8 func_ov003_02207c5c(void *arg0) {
    s32 var_r0;
    void *temp_r0;

    temp_r0 = *M2C_FIELD(arg0, void ***, 0x5C);
    if (temp_r0 != NULL) {
        var_r0 = M2C_FIELD(temp_r0, u16 *, 8);
    } else {
        var_r0 = -1;
    }
    return (u8) (var_r0 - 0xB);
}

void func_ov003_02207c7c(void *arg0) {
void func_02087d84(void *,u16,s32,s16,u16,s32);
s32 func_020a8ce4(s32,s32);
s32 func_020a8e28(s32,s32);
s32 func_ov003_02206690(s32,s32,s32);
void *inner,*inner2;
u16 selected;
s32 x;
s32 xpre,value,width,i,minus=-1,constant=0xcd;
s32 cond,cond2,cond3;
u8 kind,idx;
void *p;
inner=*M2C_FIELD(arg0,void ***,0x5c);
selected=inner?M2C_FIELD(inner,u16 *,8):minus;
xpre=func_020a8e28(M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,1),constant)+16;
i=11;
if(M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,0)+11<=11)return;
x=(s16)xpre;
do {
width=M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,1);
value=func_020a8ce4(width,constant);
if(i==selected){
inner2=*M2C_FIELD(arg0,void ***,0x5c);
cond=0;
idx=(u8)((inner2?M2C_FIELD(inner2,u16 *,8):minus)-11);
kind=M2C_FIELD(M2C_FIELD(arg0,void **,0x3c),u8 *,15);
if(kind==8){if(idx<=1)cond=1;}
if(!(cond&255)){
idx=(u8)((inner2?M2C_FIELD(inner2,u16 *,8):minus)-11);
if(kind==8)cond2=1;else cond2=0;
cond3=(cond2&255) && func_ov003_02206690(idx,2,4)!=0;
if(cond3&255)goto half;
}else {half: width>>=1;}
p=M2C_FIELD(arg0,void **,0x44);
func_02087d84(M2C_FIELD(arg0,void **,0x5c),(u16)i,16,(s16)(M2C_FIELD(p,u8 *,4)*(i-11)+2),(u16)width,M2C_FIELD(p,u8 *,2));
}else{
p=M2C_FIELD(arg0,void **,0x44);
func_02087d84(M2C_FIELD(arg0,void **,0x5c),(u16)i,x,(s16)(M2C_FIELD(p,u8 *,4)*(i-11)+2),(u16)value,M2C_FIELD(p,u8 *,2));
}
i++;
}while(i<M2C_FIELD(M2C_FIELD(arg0,void **,0x44),u8 *,0)+11);
}

u8 func_ov003_02207e38(void *arg0, s32 arg1) {
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

void func_ov003_02207e80(void *arg0) {
extern u16 **gCur3DSpriteEngine;
extern u16 **data_027e00c4;
M2C_UNK func_01ff9ce8(s32);
void *func_020bf25c(s32,u8);
s32 func_02086680(s32);
void func_02068c50(void *,void *);
s32 func_020675e4(void *,void *,...);
void func_0209b2b4(s32,s32,s32,void *,u16,u16);
extern char data_ov003_02211188[];
u16 **saved=gCur3DSpriteEngine;
char buf[256];
s32 scale;
void *inner,*kindptr;
u8 flag,kind,idx,old,byte38;
u32 bit;
gCur3DSpriteEngine=data_027e00c4;
func_01ff9ce8(1);
flag=M2C_FIELD(arg0,u8 *,0x34)!=0;
if(!flag){
inner=*M2C_FIELD(arg0,void ***,0x5c);
byte38=M2C_FIELD(arg0,u8 *,0x38);
kindptr=M2C_FIELD(arg0,void **,0x3c);
idx=(u8)((inner?M2C_FIELD(inner,u16 *,8):-1)-11);
bit=((u32)byte38<<29)>>31;
kind=M2C_FIELD(kindptr,u8 *,15);
scale=(bit<<8)-bit+1;
switch(kind){
case 9:func_02068c50(buf,func_020bf25c(0,idx));break;
case 11:func_02068c50(buf,func_020bf25c(5,idx));break;
case 10:func_02068c50(buf,func_020bf25c(1,idx));break;
default:
idx=(u8)((inner?M2C_FIELD(inner,u16 *,8):-1)-11);
func_020675e4(buf,data_ov003_02211188,func_02086680(M2C_FIELD(*(void **)((char *)M2C_FIELD(arg0,void **,0x48)+(s16)idx*(s16)36),s32 *,12)));
break;
}
func_0209b2b4(0,0,1,buf,0x3000,(u16)scale);
}
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
bit=((u32)M2C_FIELD(arg0,volatile u8 *,0x38)<<29)>>31;
old=M2C_FIELD(arg0,u8 *,0x38);
flag=!bit;
M2C_FIELD(arg0,u8 *,0x38)=(old&~4)|(((u32)flag<<31)>>29);
gCur3DSpriteEngine=saved;
}

u8 func_ov003_0220801c(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, u8 *, 0x34) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_02208034(void *arg0) {
    M2C_UNK func_02082a8c(s32 *, u16 *);
    s32 func_020a8ff4(s32);
    extern u16 **data_027e00c4;
    extern u16 **gCur3DSpriteEngine;
    s32 block[5];
    u16 * sp4;
    u16 * sp0;
    s32 var_r0;
    s32 var_r0_3;
    u16 **temp_r4;
    u16 *temp_r1;
    u16 *temp_r1_2;
    u16 *var_r1;
    u16 temp_r0;
    u16 temp_r5;
    s32 var_r0_2;
    s32 var_r0_4;
    u16 var_r2;

    temp_r4 = gCur3DSpriteEngine;
    gCur3DSpriteEngine = data_027e00c4;
    if (M2C_FIELD(arg0, u8 *, 0x34) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (!(var_r0 & 0xFF)) {
        var_r0_2 = 0x100;
    } else {
        var_r0_2 = func_020a8ff4(*M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 **, 0x18));
    }
    temp_r5 = var_r0_2;
    if (M2C_FIELD(arg0, u8 *, 0x34) != 0) {
        var_r0_3 = 1;
    } else {
        var_r0_3 = 0;
    }
    if (!(var_r0_3 & 0xFF)) {
        var_r0_4 = 0x100;
    } else {
        var_r0_4 = func_020a8ff4(*M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), s32 **, 0x1C));
    }
    temp_r0 = var_r0_4;
    if(temp_r5==0 || temp_r0==0){sp4=*gCur3DSpriteEngine;*(*(u16 * volatile *)&sp4) = *(*(u16 * volatile *)&sp4) & ~0x80;}else{sp0=*gCur3DSpriteEngine;*(*(u16 * volatile *)&sp0) = *(*(u16 * volatile *)&sp0) | 0x80;}
    M2C_FIELD(block,u16 *,14) = temp_r0;
    M2C_FIELD(block,s32 *,0) = 0x80;
    M2C_FIELD(block,s32 *,4) = 0x88;
    M2C_FIELD(block,u16 *,12) = temp_r5;
    M2C_FIELD(block,s16 *,16) = 0;
    M2C_FIELD(block,s16 *,8) = 0x80;
    M2C_FIELD(block,s16 *,10) = 0x88;
    func_02082a8c(block, (u16 *)((u8 *)*gCur3DSpriteEngine + 0x24));
    gCur3DSpriteEngine = temp_r4;
}

void func_ov003_02208168(void *a){s32 off,i;void *p;i=0;
if((s32)*M2C_FIELD(a,u8 **,0x44)>0){do{off=i*36;
ResetSlot(M2C_FIELD(M2C_FIELD(a,u8 **,0x48)+off,void **,24),0);
ResetSlot(M2C_FIELD(M2C_FIELD(a,u8 **,0x48)+off,void **,28),0);
ResetSlot(M2C_FIELD(M2C_FIELD(a,u8 **,0x48)+off,void **,32),0);
i++;
}while(i<(s32)*M2C_FIELD(a,u8 **,0x44));}
ResetSlot(M2C_FIELD(M2C_FIELD(a,void **,0x4c),void **,24),0);
ResetSlot(M2C_FIELD(M2C_FIELD(a,void **,0x4c),void **,28),0);
}

void func_ov003_0220828c(void *arg0, s32 arg1, s32 arg2) {
    s32 a, b, c, d;
    s32 i;
    s32 off;
    void *base;
    void *slot;

    func_ov003_02208168(arg0);
    switch (arg1) {
    case 0:
    case 5:
        a = 12;
        c = 0;
        d = 6;
        b = 17;
        break;
    case 10:
        a = 22;
        b = 27;
        c = a;
        d = b;
        break;
    }
    for (i = 0; i < (s32)*M2C_FIELD(arg0, u8 **, 0x44); i++) {
        off = i * 0x24;
        base = M2C_FIELD(arg0, s32 *, 0x48) + off;
        if (i == arg2) {
            SetSlotAnim(M2C_FIELD(base, void **, 0x18), (void *)(data_ov003_02210ac4 + c * 12));
            SetSlotAnim(M2C_FIELD(base, void **, 0x1C), (void *)(data_ov003_02210ac4 + d * 12));
            SetSlotAnim(M2C_FIELD(base, void **, 0x20), (void *)data_ov003_02210c44);
            if (M2C_FIELD(base, u8 *, 0x11) == 0) {
                M2C_FIELD(base, u8 *, 0x13) = 0;
                M2C_FIELD(base, u8 *, 0x11) = 1;
            }
            M2C_FIELD(base, u16 *, 0xC) = 0x100;
        } else {
            SetSlotAnim(M2C_FIELD(base, void **, 0x18), (void *)(data_ov003_02210ac4 + a * 12));
            SetSlotAnim(M2C_FIELD(base, void **, 0x1C), (void *)(data_ov003_02210ac4 + b * 12));
            M2C_FIELD(M2C_FIELD(base, void **, 0x20), u8 *, 0xE) = 1;
        }
    }
    slot = M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), void **, 0x18);
    SetSlotAnim(slot, (void *)(data_ov003_02210ac4 + a * 12));
    slot = M2C_FIELD(M2C_FIELD(arg0, void **, 0x4C), void **, 0x1C);
    SetSlotAnim(slot, (void *)(data_ov003_02210ac4 + b * 12));
}

void func_ov003_022084f0(void *arg0) {
    M2C_UNK func_020a91a8(s32);
    void func_ov003_02208034(void *);
    void *temp_r6;
    void *var_r5;
    s32 var_r4;
    s32 var_r7;

    var_r4 = 0;
    var_r5 = arg0;
    if ((s32) *M2C_FIELD(var_r5, u8 **, 0x44) > 0) {
        var_r7 = 0;
        do {
            temp_r6 = M2C_FIELD(var_r5, s32 *, 0x48) + var_r7;
            func_020a91a8(M2C_FIELD(temp_r6, s32 *, 0x18));
            func_020a91a8(M2C_FIELD(temp_r6, s32 *, 0x1C));
            func_020a91a8(M2C_FIELD(temp_r6, s32 *, 0x20));
            ++var_r4;
            var_r7 += 0x24;
        } while (var_r4 < (s32) *M2C_FIELD(var_r5, u8 **, 0x44));
    }
    func_020a91a8(M2C_FIELD(M2C_FIELD(var_r5, void **, 0x4C), s32 *, 0x18));
    func_020a91a8(M2C_FIELD(M2C_FIELD(var_r5, void **, 0x4C), s32 *, 0x1C));
    func_ov003_02208034(var_r5);
}

