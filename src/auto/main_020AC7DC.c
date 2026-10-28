/* 37 functions from 0x020AC7DC to 0x020AD78C (main), found by ds-decomp. */
#include "common.h"

s32 *func_020ad570(s32);

void func_020ac7dc(void *arg0) {
extern s32 gCur3DSpriteEngine,data_027e00c4,data_027e00c8;
s32 func_0207ca38(s32,s32,s32,s32,s32);
s32 v; s8 pos,neg;s32 saved,bank,i;u8 mode;
M2C_FIELD(arg0,u16 *,0x38)++;
v=func_0207ca38(0,0,16,M2C_FIELD(arg0,u16 *,0x38),M2C_FIELD(arg0,u16 *,0x3a));
pos=v;neg=-v;
saved=gCur3DSpriteEngine;
for(i=0;i<2;i++) {
if(i==0)bank=data_027e00c8;else bank=data_027e00c4;
gCur3DSpriteEngine=bank;
mode=M2C_FIELD(arg0,u8 *,0x3c);
if(mode==0 && bank!=data_027e00c8)goto next;
if(mode==1 && bank!=data_027e00c4)goto next;
if(mode==3 && bank!=saved)goto next;
switch(M2C_FIELD(arg0,s32 *,0x34)){
case 0:M2C_FIELD(M2C_FIELD(bank,void **,0),s8 *,0x50)=neg;break;
case 1:M2C_FIELD(M2C_FIELD(bank,void **,0),s8 *,0x50)=pos;break;
case 2:func_020abfcc(M2C_FIELD(arg0,u16 *,0x3a)-M2C_FIELD(arg0,u16 *,0x38));break;
}
if(M2C_FIELD(arg0,u16 *,0x38)>=M2C_FIELD(arg0,u16 *,0x3a)){
func_020aca8c((u8)M2C_FIELD(arg0,s32 *,0x34));
func_01ffa6fc(arg0);
}
next:;
}
gCur3DSpriteEngine=saved;
if(M2C_FIELD(arg0,s32 *,0x18)==1)func_020ac598(M2C_FIELD(arg0,u8 *,0x3c));
}

s32 func_020ac924(M2C_UNK arg0, s32 arg1) {
 s32 func_01ffa860(M2C_UNK *, M2C_UNK);
 extern M2C_UNK data_02127360, data_02127390;
 switch(arg1) {
 case 0: return func_01ffa860(&data_02127360,arg0);
 case 1: return func_01ffa860(&data_02127390,arg0);
 default: return 0;
 }
}

void func_020ac970(M2C_UNK arg0) {
    M2C_UNK func_01ffa574();
    M2C_UNK func_020ac924(M2C_UNK, M2C_UNK);
    func_020ac924(arg0, 0);
    func_01ffa574();
    func_020ac924(arg0, 1);
    func_01ffa574();
}

void func_020ac998(s32 mode) {
s32 func_020abf3c(u8); void func_020ac144(u8,s32,s32);
extern s32 gCur3DSpriteEngine,data_027e00c8;
u8 currentIsPrimary, screen; u16 *volatile p; u16 *volatile q;
if(gCur3DSpriteEngine==data_027e00c8)currentIsPrimary=1;else currentIsPrimary=0;
if(currentIsPrimary!=1)screen=1;else screen=0;
if(mode==3)mode=func_020abf3c(screen);
func_020ac970(screen);func_020ac144(screen,0,mode);
switch(mode){
case 0: case 1: M2C_FIELD(*(void **)gCur3DSpriteEngine,u8 *,0x50)=0;break;
case 2:
p=*(u16 **)gCur3DSpriteEngine;*p = *p & ~0x200;
q=*(u16 **)gCur3DSpriteEngine;*q = *q & ~0x400;
break;
}
/* Configure the active display for the requested mode. */
}

M2C_UNK func_020aca8c(M2C_UNK arg0) {
    s32 func_020abf3c(u8);
    void func_020ac970(M2C_UNK);
    void func_020ac144(u8, s32, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c8;
    u8 currentIsPrimary;
    u8 screen;
    s32 mode;

    if (gCur3DSpriteEngine == data_027e00c8) {
        currentIsPrimary = 1;
    } else {
        currentIsPrimary = 0;
    }
    if (currentIsPrimary != 1) {
        screen = 1;
    } else {
        screen = 0;
    }
    if (arg0 == 3) {
        mode = func_020abf3c(screen);
        func_020ac970(screen);
        func_020ac144(screen, 1, mode);
        switch (mode) {
        case 0:
            *(s8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x50) = -16;
            break;
        case 1:
            *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x50) = 0x10;
            break;
        case 2:
            break;
        }
    } else {
        u16 *volatile sp44;
        u16 *volatile sp40;
        u16 *volatile sp3c;
        u16 *volatile sp38;
        u16 *volatile sp34;
        u16 *volatile sp30;
        u16 *volatile sp2c;
        u16 *volatile sp28;
        u16 *volatile sp24;
        u16 *volatile sp20;
        u16 *volatile sp1c;
        u16 *volatile sp18;
        u16 *volatile sp14;
        u16 *volatile sp10;
        u16 *volatile spC;
        u16 *volatile sp8;
        u16 *volatile sp4;
        u16 *volatile sp0;

        sp44 = (u16 *)*(u8 **)gCur3DSpriteEngine;
        *sp44 = *sp44 | 0x200;

        sp40 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp40 = *sp40 & ~1;

        sp3c = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp3c = *sp3c & ~2;

        sp38 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp38 = *sp38 & ~4;

        sp34 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp34 = *sp34 & ~8;

        sp30 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp30 = *sp30 & ~0x10;

        sp2c = (u16 *)*(u8 **)gCur3DSpriteEngine;
        *sp2c = *sp2c | 0x400;

        sp28 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp28 = *sp28 & ~0x100;

        sp24 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp24 = *sp24 & ~0x200;

        sp20 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp20 = *sp20 & ~0x400;

        sp1c = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp1c = *sp1c & ~0x800;

        sp18 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x0e);
        *sp18 = *sp18 & ~0x1000;

        sp14 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *sp14 = (*sp14 & ~1) | 1;

        sp10 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *sp10 = *sp10 | 0x2;

        spC = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *spC = *spC | 0x4;

        sp8 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *sp8 = *sp8 | 0x8;

        sp4 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *sp4 = *sp4 | 0x10;

        sp0 = (u16 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x10);
        *sp0 = *sp0 | 0x20;

        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x48) = 0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4a) = 0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x49) = 0xff;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4b) = 0xc0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4c) = 1;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4e) = 0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4d) = 0;
        *(u8 *)((u8 *)*(u8 **)gCur3DSpriteEngine + 0x4f) = 0xc0;
    }
}

void func_020ace54(void) {
    s32 func_020abe90(u8);
    M2C_UNK func_020aca8c(M2C_UNK);
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    u8 var_r0;
    u8 var_r0_2;

    if (gCur3DSpriteEngine == data_027e00c8) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 1) {
        var_r0_2 = 1;
    } else {
        var_r0_2 = 0;
    }
    if (func_020abe90(var_r0_2) != 1) {
        return;
    }
    func_020aca8c(3);
}

void func_020acea8(s32 arg0, s16 arg1, s32 arg2) {
 void *func_01ffa3dc(M2C_UNK *, s32);
 s32 func_020abe90(u8);
 void func_020ac998(M2C_UNK);
 extern M2C_UNK data_02127360;
 extern s32 data_027e00c8, gCur3DSpriteEngine;
 s32 var_r4;
 u8 var_r0;
 u8 var_r0_2;
 void *temp_r0;
 if(gCur3DSpriteEngine == data_027e00c8) var_r0=1; else var_r0=0;
 if(var_r0 != 1) var_r0_2=1; else var_r0_2=0;
 var_r4=arg2;
 if(var_r4==0) var_r4=7;
 if(arg1==0) {
 func_020ac970(var_r0_2);
 func_020ac998(arg0);
 return;
 }
 if(func_020abe90(var_r0_2)==0) return;
 func_020ac970(var_r0_2);
 temp_r0=func_01ffa3dc(&data_02127360,var_r4);
 M2C_FIELD(temp_r0,s16 *,0x2e)=var_r0_2;
 M2C_FIELD(temp_r0,u8 *,0x3c)=var_r0_2;
 M2C_FIELD(temp_r0,s16 *,0x3a)=arg1;
 M2C_FIELD(temp_r0,s32 *,0x34)=arg0;
 M2C_FIELD(temp_r0,s32 *,0x40)=0;
}

void func_020acf54(s32 arg0, s16 arg1, s32 arg2) {
 void *func_01ffa3dc(M2C_UNK *, s32);
 s32 func_020abe90(u8);
 M2C_UNK func_020aca8c(M2C_UNK);
 extern M2C_UNK data_02127390;
 extern s32 data_027e00c8, gCur3DSpriteEngine;
 s32 var_r4;
 u8 var_r0;
 u8 var_r0_2;
 void *temp_r0;
 if(gCur3DSpriteEngine == data_027e00c8) var_r0=1; else var_r0=0;
 if(var_r0 != 1) var_r0_2=1; else var_r0_2=0;
 var_r4=arg2;
 if(var_r4==0) var_r4=7;
 if(arg1==0) {
 func_020ac970(var_r0_2);
 func_020aca8c(arg0);
 return;
 }
 if(func_020abe90(var_r0_2)==1) return;
 func_020ac970(var_r0_2);
 temp_r0=func_01ffa3dc(&data_02127390,var_r4);
 M2C_FIELD(temp_r0,s16 *,0x2e)=var_r0_2;
 M2C_FIELD(temp_r0,u8 *,0x3c)=var_r0_2;
 M2C_FIELD(temp_r0,s16 *,0x3a)=arg1;
 M2C_FIELD(temp_r0,s32 *,0x34)=arg0;
 M2C_FIELD(temp_r0,s32 *,0x40)=0;
}

void func_020ad000(s32 arg0, s16 arg1, s32 arg2) {
void *func_01ffa3dc(M2C_UNK *, s32);
s32 func_020abe90(u8);
void func_020ac998(M2C_UNK);
M2C_UNK func_01ffaa5c(s32);
extern M2C_UNK data_02127360;
extern s32 data_027e00c8, gCur3DSpriteEngine;
u8 var_r0, var_r0_2;
void *temp_r0;
if(gCur3DSpriteEngine == data_027e00c8) var_r0=1; else var_r0=0;
if(var_r0 != 1) var_r0_2=1; else var_r0_2=0;
if(arg1==0) {
func_020ac970(var_r0_2);
func_020ac998(arg0);
return;
}
if(func_020abe90(var_r0_2)==0) return;
func_020ac970(var_r0_2);
temp_r0=func_01ffa3dc(&data_02127360,1);
M2C_FIELD(temp_r0,s16 *,0x2e)=var_r0_2;
M2C_FIELD(temp_r0,u8 *,0x3c)=var_r0_2;
M2C_FIELD(temp_r0,s16 *,0x3a)=arg1;
M2C_FIELD(temp_r0,s32 *,0x34)=arg0;
M2C_FIELD(temp_r0,s32 *,0x40)=arg2;
func_01ffaa5c(arg2);
}

void func_020ad0a8(s32 arg0, s16 arg1, s32 arg2) {
void *func_01ffa3dc(M2C_UNK *, s32);
s32 func_020abe90(u8);
M2C_UNK func_020aca8c(M2C_UNK);
M2C_UNK func_01ffaa5c(s32);
extern M2C_UNK data_02127390;
extern s32 data_027e00c8, gCur3DSpriteEngine;
u8 var_r0, var_r0_2;
void *temp_r0;
if(gCur3DSpriteEngine == data_027e00c8) var_r0=1; else var_r0=0;
if(var_r0 != 1) var_r0_2=1; else var_r0_2=0;
if(arg1==0) {
func_020ac970(var_r0_2);
func_020aca8c(arg0);
return;
}
if(func_020abe90(var_r0_2)==1) return;
func_020ac970(var_r0_2);
temp_r0=func_01ffa3dc(&data_02127390,1);
M2C_FIELD(temp_r0,s16 *,0x2e)=var_r0_2;
M2C_FIELD(temp_r0,u8 *,0x3c)=var_r0_2;
M2C_FIELD(temp_r0,s16 *,0x3a)=arg1;
M2C_FIELD(temp_r0,s32 *,0x34)=arg0;
M2C_FIELD(temp_r0,s32 *,0x40)=arg2;
func_01ffaa5c(arg2);
}

void func_020ad150(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    s32 temp_r5;
    s32 var_r1;
    s32 var_r6;

    temp_r5 = gCur3DSpriteEngine;
    var_r6 = 0;
    do {
        if (var_r6 == 0) {
            var_r1 = data_027e00c8;
        } else {
            var_r1 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r1;
        if (((arg2 != 0) || (var_r1 == data_027e00c8)) &&
            ((arg2 != 1) || (var_r1 == data_027e00c4)) &&
            ((arg2 != 3) || (var_r1 == temp_r5))) {
            func_020acea8(arg0, arg1, arg3);
        }
        var_r6 += 1;
    } while (var_r6 < 2);
    gCur3DSpriteEngine = temp_r5;
}

void func_020ad1f8(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    s32 temp_r5;
    s32 var_r1;
    s32 var_r6;

    temp_r5 = gCur3DSpriteEngine;
    var_r6 = 0;
    do {
        if (var_r6 == 0) {
            var_r1 = data_027e00c8;
        } else {
            var_r1 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r1;
        if (((arg2 != 0) || (var_r1 == data_027e00c8)) &&
            ((arg2 != 1) || (var_r1 == data_027e00c4)) &&
            ((arg2 != 3) || (var_r1 == temp_r5))) {
            func_020acf54(arg0, arg1, arg3);
        }
        var_r6 += 1;
    } while (var_r6 < 2);
    gCur3DSpriteEngine = temp_r5;
}

void func_020ad2a0(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    s32 temp_r5;
    s32 var_r1;
    s32 var_r6;

    temp_r5 = gCur3DSpriteEngine;
    var_r6 = 0;
    do {
        if (var_r6 == 0) {
            var_r1 = data_027e00c8;
        } else {
            var_r1 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r1;
        if (((arg2 != 0) || (var_r1 == data_027e00c8)) &&
            ((arg2 != 1) || (var_r1 == data_027e00c4)) &&
            ((arg2 != 3) || (var_r1 == temp_r5))) {
            func_020ad000(arg0, arg1, arg3);
        }
        var_r6 += 1;
    } while (var_r6 < 2);
    gCur3DSpriteEngine = temp_r5;
}

void func_020ad348(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    s32 temp_r5;
    s32 var_r1;
    s32 var_r6;

    temp_r5 = gCur3DSpriteEngine;
    var_r6 = 0;
    do {
        if (var_r6 == 0) {
            var_r1 = data_027e00c8;
        } else {
            var_r1 = data_027e00c4;
        }
        gCur3DSpriteEngine = var_r1;
        if (((arg2 != 0) || (var_r1 == data_027e00c8)) &&
            ((arg2 != 1) || (var_r1 == data_027e00c4)) &&
            ((arg2 != 3) || (var_r1 == temp_r5))) {
            func_020ad0a8(arg0, arg1, arg3);
        }
        var_r6 += 1;
    } while (var_r6 < 2);
    gCur3DSpriteEngine = temp_r5;
}

u8 func_020ad3f0(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02127360;
    extern M2C_UNK data_02127390;
    u8 var_r0;

    if (func_01ffa770(&data_02127360) != 0) {
        return 1U;
    }
    if (func_01ffa770(&data_02127390) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

M2C_UNK func_020ad42c(s32 arg0, M2C_UNK *arg1) {
    u8 func_020e31e0(void);
    M2C_UNK *func_020e3218(s32);

    if ((arg0 != 0x2E) && (arg0 != 0x2F)) {
        goto done;
    }
    if (func_020e31e0() != 2) {
        goto done;
    }
    return (M2C_UNK) func_020e3218((s32) arg1);
done:
    return (M2C_UNK) arg1;
}

void func_020ad460(s32 arg0) {
 M2C_UNK func_02068c50(M2C_UNK *, s32);
 M2C_UNK func_02068d68(M2C_UNK *, M2C_UNK *);
 M2C_UNK func_020ad42c(s32, M2C_UNK *);
 extern s32 data_021278a4[];
 extern M2C_UNK data_021279d8, data_0215c3c8;
 func_02068c50(&data_0215c3c8, data_021278a4[arg0]);
 func_02068d68(&data_0215c3c8, &data_021279d8);
 func_020ad42c(arg0, &data_0215c3c8);
}

void func_020ad4a0(s32 arg0) {
 M2C_UNK func_02068c50(M2C_UNK *, s32);
 M2C_UNK func_02068d68(M2C_UNK *, M2C_UNK *);
 M2C_UNK func_020ad42c(s32, M2C_UNK *);
 extern s32 data_021278a4[];
 extern M2C_UNK data_021279e0, data_0215c3e8;
 func_02068c50(&data_0215c3e8, data_021278a4[arg0]);
 func_02068d68(&data_0215c3e8, &data_021279e0);
 func_020ad42c(arg0, &data_0215c3e8);
}

void func_020ad4e0(s32 arg0) {
 M2C_UNK func_02068c50(M2C_UNK *, s32);
 M2C_UNK func_02068d68(M2C_UNK *, M2C_UNK *);
 M2C_UNK func_020ad42c(s32, M2C_UNK *);
 extern s32 data_021278a4[];
 extern M2C_UNK data_021279e4, data_0215c408;
 func_02068c50(&data_0215c408, data_021278a4[arg0]);
 func_02068d68(&data_0215c408, &data_021279e4);
 func_020ad42c(arg0, &data_0215c408);
}

void func_020ad520(s32 arg0) {
 M2C_UNK func_02068c50(M2C_UNK *, s32);
 M2C_UNK func_02068d68(M2C_UNK *, M2C_UNK *);
 M2C_UNK func_020ad42c(s32, M2C_UNK *);
 extern s32 data_021278a4[];
 extern M2C_UNK data_021279e8, data_0215c3a8;
 func_02068c50(&data_0215c3a8, data_021278a4[arg0]);
 func_02068d68(&data_0215c3a8, &data_021279e8);
 func_020ad42c(arg0, &data_0215c3a8);
}

s32 func_020ad560(s32 arg0) {
    extern s32 data_02127884[];
    return data_02127884[arg0];
}

s32 *func_020ad570(s32 arg0) {
    extern M2C_UNK data_020f4ab8;
    return (s32 *) ((0xC * arg0) + (s32) &data_020f4ab8);
}

s32 func_020ad584(void) {
    s32 *func_020ad570();
    return *func_020ad570();
}

s32 func_020ad594(s32 arg0) {
    s32 func_020ad5dc();
    s32 *func_020ad570(s32);
    s32 temp;
    s32 var_r4;
    s32 temp_r0;

    temp_r0 = func_020ad5dc();
    for (var_r4 = 0; var_r4 < temp_r0; var_r4++) {
        temp = M2C_FIELD(func_020ad570(var_r4), s32 *, 0);
        if (temp == arg0) {
            return var_r4;
        }
    }
    return -1;
}

s32 func_020ad5dc(void) {
    s32 var_r4;

    var_r4 = 0;
loop_1:
    if (M2C_FIELD(func_020ad570(var_r4), s32 *, 8) != 0) {
        var_r4 += 1;
        goto loop_1;
    }
    return var_r4;
}

void func_020ad604(s32 arg0) {
    M2C_UNK func_02086774(s32, M2C_UNK);
    if (arg0 < 0) {
        return;
    }
    func_02086774(arg0, 1);
}

s32 func_020ad61c(s32 arg0) {
    s32 func_020869c0();
    if ((arg0 >= 0) && (func_020869c0() != 0)) {
        return 1;
    }
    return 0;
}

void func_020ad640(s32 arg0) {
    M2C_UNK func_020867a8(s32, M2C_UNK);
    if (arg0 < 0) {
        return;
    }
    func_020867a8(arg0, 1);
}

s32 func_020ad658(s32 arg0) {
    s32 func_020869e0();
    if ((arg0 >= 0) && (func_020869e0() != 0)) {
        return 1;
    }
    return 0;
}

void func_020ad67c(void) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    extern M2C_UNK data_02127d78;
    func_0200bc5c(&data_02127d78);
}

s32 func_020ad690(void) {
extern s16 *data_0215c428;
return data_0215c428[2] != 0;
}

s32 func_020ad6b0(void) {
    s32 func_020ad690();
    extern s32 data_027e00c4;
    return M2C_FIELD((data_027e00c4 + (func_020ad690() * 4)), s32 *, 0xC);
}

s32 func_020ad6d0(void) {
 s32 func_020ad690();
 extern s32 data_027e00c4;
 return M2C_FIELD(data_027e00c4 + func_020ad690()*4, s32 *, 0x20);
}

void func_020ad6f0(void) {
    extern s16 *data_0215c428;
    *data_0215c428 |= 1;
}

void func_020ad70c(void) {
extern s16 *data_0215c428;
*data_0215c428 &= ~1;
}

u8 func_020ad728(void) {
 extern s16 *data_0215c428;
 u8 result;
 if (data_0215c428[0] & 1) result=1; else result=0;
 return result;
}

void func_020ad74c(void) {
 extern s16 *data_0215c428;
 s32 func_020ad690();
 void func_01ff9ce8(u8);
 void func_020ad78c(void);
 data_0215c428[2]=1-data_0215c428[2];
 func_01ff9ce8((u8)func_020ad690());
 func_020ad78c();
 data_0215c428[3]=0;
}

