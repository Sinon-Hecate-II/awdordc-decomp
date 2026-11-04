/* 17 functions from 0x02094D8C to 0x02095C90 (main), found by ds-decomp. */
#include "common.h"

void func_02094d8c(M2C_UNK arg0) {
    s32 func_0209600c();
    M2C_UNK func_02097a2c(M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_02097a2c(arg0);
}

void func_02094dac(void) {
    s32 func_02091db4();
    M2C_UNK func_020979a4(M2C_UNK);
    s32 temp_r0;

    if (func_0209600c() != 0) {
        return;
    }
    temp_r0 = func_02091db4();
    switch (temp_r0) {                              /* irregular */
    case 0:
    case 1:
        func_020979a4(-1);
        return;
    case 2:
        func_02097a2c(-1);
        return;
    }
}

void func_02095250(s32 arg0) {
extern M2C_UNK data_02102aa8;
if(func_0209600c())return;
switch(arg0) {
case 100:func_0208f890();return;
case 101:func_01ffa3dc(&data_02102aa8,7);return;
default:func_0208f780(func_020ad584(arg0));return;
}
}

u8 func_020952a4(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02102aa8;
    u8 var_r0;

    if (func_01ffa770(&data_02102aa8) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020952c8(M2C_UNK arg0) {
    M2C_UNK func_0208fe30();
    M2C_UNK func_020ad560(M2C_UNK);
    if (func_0209600c() != 0) {
        return;
    }
    func_020ad560(arg0);
    func_0208fe30();
}

void func_020952ec(s32 arg0,s32 arg1,s32 arg2) {
u32 value=(u8)func_02091e44();
if(func_0209600c())arg2=0;
switch(arg0) {
case 0:func_020ad150((u8)arg1,(u16)arg2,value,7);return;
case 1:func_020ad1f8((u8)arg1,(u16)arg2,value,7);return;
}
}

void func_0209535c(s32 arg0) {
extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine;
s32 saved,i,v;
if(func_020ad3f0()) {
if(!func_02096064())return;
saved=gCur3DSpriteEngine;
i=0;
do {
if(i==0)v=data_027e00c8;else v=data_027e00c4;
gCur3DSpriteEngine=v;
func_020ace54();
i++;
}while(i<2);
gCur3DSpriteEngine=saved;
}
func_01ffa6fc(arg0);
}

void func_020953d0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102ac8;
    func_01ffa3dc(&data_02102ac8, 7);
}

u8 func_020953e8(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02102ac8;
    u8 var_r0;

    if (func_01ffa770(&data_02102ac8) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_0209540c(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    s32 func_02096064();
    s16 temp_r1;

    if (func_02096064() != 0) {
        func_01ffa6fc(arg0);
        return;
    }
    temp_r1 = M2C_FIELD(arg0, s16 *, 0x6C);
    M2C_FIELD(arg0, s16 *, 0x6C) = (s16) (temp_r1 - 1);
    if (temp_r1 != 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_0209544c(s16 arg0) {
    extern M2C_UNK data_02102a88;
    M2C_FIELD(func_01ffa3dc(&data_02102a88, 7), s16 *, 0x6C) = arg0;
}

u8 func_0209546c(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_02102a88;
    u8 var_r0;

    if (func_01ffa770(&data_02102a88) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_02095490(void *arg0) {
    u8 func_02091dc4(s32);
    s32 func_02091ddc(s32);
    extern s32 data_027e00c4, data_027e00c8, gCur3DSpriteEngine;
    s32 saved;
    s32 engine;
    u8 mode;
    u8 type;
    s32 i;
    u16 *volatile sp4C;
    u16 *volatile sp48;
    u16 *volatile sp44;
    u16 *volatile sp40;
    u16 *volatile sp3C;
    u16 *volatile sp38;
    u16 *volatile sp34;
    u16 *volatile sp30;
    u16 *volatile sp2C;
    u16 *volatile sp28;
    u16 *volatile sp24;
    u16 *volatile sp20;
    u16 *volatile sp1C;
    u16 *volatile sp18;
    u16 *volatile sp14;
    u16 *volatile sp10;
    u16 *volatile spC;
    u16 *volatile sp8;
    u16 *volatile sp4;
    u16 *volatile sp0;

    mode = func_02091dc4(M2C_FIELD(arg0, s32 *, 0x5C));
    type = (u8)func_02091ddc(M2C_FIELD(arg0, s32 *, 0x5C));
    saved = gCur3DSpriteEngine;
    i = 0;
    do {
        if (i == 0) engine = data_027e00c8; else engine = data_027e00c4;
        gCur3DSpriteEngine = engine;
        {
            s32 screen = M2C_FIELD(arg0, s32 *, 0x5C);
            if (screen == 0 && engine != data_027e00c8) goto end;
            if (screen == 1 && engine != data_027e00c4) goto end;
            if (screen == 3 && engine != saved) goto end;
        }
        switch (mode) {
        case 0:
            sp4C = *(u16 **)(engine);
            *sp4C = (u16)(*sp4C | 0x10);
            break;
        case 1:
            sp48 = *(u16 **)(engine);
            *sp48 = (u16)(*sp48 | 0x20);
            break;
        case 2:
            sp44 = *(u16 **)(engine);
            *sp44 = (u16)(*sp44 | 0x40);
            break;
        case 3:
            sp40 = *(u16 **)(engine);
            *sp40 = (u16)(*sp40 | 0x80);
            break;
        case 4:
            sp3C = *(u16 **)(engine);
            *sp3C = (u16)(*sp3C | 0x100);
            break;
        }
        switch (type) {
        case 0:
            sp38 = *(u16 **)gCur3DSpriteEngine;
            *sp38 = (u16)(*sp38 | 0x10);
            break;
        case 1:
            sp34 = *(u16 **)gCur3DSpriteEngine;
            *sp34 = (u16)(*sp34 | 0x20);
            break;
        case 2:
            sp30 = *(u16 **)gCur3DSpriteEngine;
            *sp30 = (u16)(*sp30 | 0x40);
            break;
        case 3:
            sp2C = *(u16 **)gCur3DSpriteEngine;
            *sp2C = (u16)(*sp2C | 0x80);
            break;
        case 4:
            sp28 = *(u16 **)gCur3DSpriteEngine;
            *sp28 = (u16)(*sp28 | 0x100);
            break;
        }
        sp24 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp24 = (u16)(*sp24 & ~1);
        sp20 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp20 = (u16)(*sp20 & ~2);
        sp1C = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp1C = (u16)(*sp1C | 4);
        sp18 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp18 = (u16)(*sp18 & ~8);
        sp14 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp14 = (u16)(*sp14 & ~0x10);
        sp10 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp10 = (u16)(*sp10 & ~0x100);
        spC = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *spC = (u16)(*spC & ~0x200);
        sp8 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp8 = (u16)(*sp8 & ~0x400);
        sp4 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp4 = (u16)(*sp4 | 0x800);
        sp0 = (u16 *)(*(s32 *)gCur3DSpriteEngine + 0x12);
        *sp0 = (u16)(*sp0 & ~0x1000);
        i++;
    } while (i < 2);

end:
    gCur3DSpriteEngine = saved;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
}

void func_02095ad0(u8 *p){
u8 func_02091dc4(s32);
s32 func_02091ddc(s32);
s32 func_0207ca38(s32,s32,s32,s32,s32);
void func_01ffa574(void *);
extern s32 gCur3DSpriteEngine,data_027e00c4,data_027e00c8;
u16 *volatile a;
u16 *volatile b;
s32 mode,screen;
u32 first;
u8 second;
s32 saved,engine;
s32 i;
mode=func_02091dc4(*(s32 *)(p+92));
func_02091ddc(*(s32 *)(p+92));
(*(s32 *)(p+100))++;
second=func_0207ca38(0,0,16,*(s32 *)(p+100),*(s32 *)(p+96));
saved=gCur3DSpriteEngine;
first=16-second;
i=0;
do{
if(i==0)engine=data_027e00c8;else engine=data_027e00c4;
gCur3DSpriteEngine=engine;
screen=*(s32 *)(p+92);
if(screen==0 && engine!=data_027e00c8)goto next;
if(screen==1 && engine!=data_027e00c4)goto next;
if(screen==3 && engine!=saved)goto next;
switch(mode){
case 2:
a=(u16 *)(*(u8 **)engine+18);*a=(*a&~0xc0)|0x40;
(*(u8 **)gCur3DSpriteEngine)[81]=first;
(*(u8 **)gCur3DSpriteEngine)[82]=second;
break;
case 3:
b=(u16 *)(*(u8 **)engine+18);*b=(*b&~0xc0)|0x40;
(*(u8 **)gCur3DSpriteEngine)[81]=second;
(*(u8 **)gCur3DSpriteEngine)[82]=first;
break;
}
next:i++;
}while(i<2);
gCur3DSpriteEngine=saved;
if(*(s32 *)(p+100)<*(s32 *)(p+96))return;
func_01ffa574(p);
}

void func_02095c58(s32 arg0, s32 arg1, M2C_UNK arg2) {
    void *func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_02102ae8;
    void *temp_r0;

    if (func_0209600c() != 0) {
        return;
    }
    temp_r0 = func_01ffa42c(&data_02102ae8, arg2);
    M2C_FIELD(temp_r0, s32 *, 0x5C) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x60) = arg1;
}

