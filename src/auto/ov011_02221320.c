/* 9 functions from 0x02221320 to 0x02222204 (ov011), found by ds-decomp. */
#include "common.h"

void func_ov011_02221320(void *arg0, s32 arg1) {
    extern M2C_UNK data_ov011_02228294;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_ov011_02228294;
    M2C_FIELD(arg0, s32 *, 0x3C) = arg1;
}

void func_ov011_02221334(void) {

}

s32 func_ov011_02221338(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov011_0222134c(void *arg0) {
    M2C_UNK func_020822b8(u16 *);
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern s32 data_027e01d8;
    extern M2C_UNK data_ov011_02227f08;
    typedef struct { u16 a, b, c, d, e, f; } T;
    T first = M2C_FIELD(&data_ov011_02227f08, T *, 0x12);
    T second;
    s32 temp_r4;
    second = M2C_FIELD(&data_ov011_02227f08, T *, 6);
    temp_r4 = data_027e01d8;
    data_027e01d8 = g3DSpriteEngineMain;
    func_020822b8((u16 *)&first);
    data_027e01d8 = g3DSpriteEngineSub;
    func_020822b8((u16 *)&second);
    data_027e01d8 = temp_r4;
}

#pragma opt_common_subs on
#pragma opt_strength_reduction off
void func_ov011_0222140c(void *arg0) {
    M2C_UNK func_02082c84(void);
    M2C_UNK GX_SetBankForBG(s32);
    M2C_UNK func_02003124(s32);
    M2C_UNK func_020031cc(s32);
    M2C_UNK func_02002968(s32);
    M2C_UNK func_02002ab8(s32);
    M2C_UNK func_0200323c(s32);
    M2C_UNK func_020032bc(s32);
    M2C_UNK func_020aca8c(s32);
    M2C_UNK Reset3DSpriteBankState(void);
    M2C_UNK func_01ff9b38(void);
    void func_ov011_0222134c(void *);
    void func_ov011_0222161c(void *);

    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;

    s32 saved;
    s32 i;
    s32 engine;

    func_02082c84();
    GX_SetBankForBG(3);
    func_02003124(4);
    func_020031cc(8);
    func_02002968(0x10);
    func_02002ab8(0x60);
    func_0200323c(0x80);
    func_020032bc(0x100);
    func_ov011_0222134c(arg0);

    saved = gCur3DSpriteEngine;
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            gCur3DSpriteEngine = engine = g3DSpriteEngineMain;
        } else {
            gCur3DSpriteEngine = engine = g3DSpriteEngineSub;
        }
        { u16 * volatile p0=(u16 *)*(s32 *)engine; *p0=*p0 | 0x10; }
        { u16 * volatile p1=(u16 *)*(s32 *)gCur3DSpriteEngine; *p1=*p1 | 0x20; }
        { u16 * volatile p2=(u16 *)*(s32 *)gCur3DSpriteEngine; *p2=*p2 | 0x40; }
        { u16 * volatile p3=(u16 *)*(s32 *)gCur3DSpriteEngine; *p3=*p3 | 0x80; }
        { u16 * volatile p4=(u16 *)*(s32 *)gCur3DSpriteEngine; *p4=*p4 | 0x100; }
        { u16 * volatile p5=(u16 *)*(s32 *)gCur3DSpriteEngine; *p5=*p5 & ~0x200; }
        { u16 * volatile p6=(u16 *)*(s32 *)gCur3DSpriteEngine; *p6=*p6 & ~0x400; }
        { u16 * volatile p7=(u16 *)*(s32 *)gCur3DSpriteEngine; *p7=*p7 & ~0x800; }
        {u16 * volatile p8=(u16 *)(*(s32 *)gCur3DSpriteEngine+0x12);*p8=*p8&~0xC0;}
        ((u8 *)*(s32 *)gCur3DSpriteEngine)[0x51] = 0;
        ((u8 *)*(s32 *)gCur3DSpriteEngine)[0x52] = 0;
        ((u8 *)*(s32 *)gCur3DSpriteEngine)[0x53] = 0;
        *(volatile u16 *)((char *)gCur3DSpriteEngine + 0x44) = 0;
        func_020aca8c(3);
        Reset3DSpriteBankState();
        func_01ff9b38();
    }
    gCur3DSpriteEngine = saved;
    *((u8 *)arg0 + 0x38) = 0;
    func_ov011_0222161c(arg0);
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
void func_ov011_0222161c(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x38) == 0) {
        M2C_FIELD(arg0, s16 *, 0x34) = 0;
        M2C_FIELD(arg0, s8 *, 0x39) = 0;
        M2C_FIELD(arg0, s8 *, 0x36) = 0;
        M2C_FIELD(arg0, s8 *, 0x37) = 0x20;
        M2C_FIELD(arg0, u8 *, 0x38) = 1U;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x34) = 0x20;
    M2C_FIELD(arg0, s8 *, 0x39) = 0;
    M2C_FIELD(arg0, s8 *, 0x36) = 0;
    M2C_FIELD(arg0, s8 *, 0x37) = 0x20;
    M2C_FIELD(arg0, u8 *, 0x38) = 2U;
}

void func_ov011_0222166c(void *arg0) {
    M2C_UNK func_01ffa8c4(void *, s32);
    s32 temp_r1;
    if (M2C_FIELD(arg0, u8 *, 0x39) == 0) {
        temp_r1 = M2C_FIELD(arg0, s32 *, 0x3C);
        if (temp_r1 == 1) {
            M2C_FIELD(arg0, u8 *, 0x38) = 2;
            M2C_FIELD(arg0, s16 *, 0x34) = 0x10;
            func_01ffa8c4(arg0, 2);
            return;
        }
        if (temp_r1 != 2) {
            M2C_FIELD(arg0, u8 *, 0x38) = 1;
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x38) = 3;
        func_01ffa8c4(arg0, 6);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 2) return;
    func_01ffa8c4(arg0, 4);
}

void func_ov011_022216d8(void *arg0, void *arg1, s32 arg2, s32 arg3) {
M2C_UNK func_0200bc5c(M2C_UNK *); M2C_UNK func_020814e4(M2C_UNK *); M2C_UNK func_02081590(M2C_UNK *,s32); M2C_UNK func_020815fc(M2C_UNK *,s32,s32); M2C_UNK func_0208161c(M2C_UNK *,s32,s32,s32); M2C_UNK func_02081644(M2C_UNK *,s32,s32,s32); M2C_UNK func_02081528(void); s32 func_020e31e0(void); M2C_UNK *func_020e3218(M2C_UNK *);
extern s32 gCur3DSpriteEngine, g3DSpriteEngineSub, g3DSpriteEngineMain;
extern M2C_UNK data_ov011_022282a0, data_ov011_022282ac, data_ov011_022282bc, data_ov011_022282c8, data_ov011_022282d4, data_ov011_022282e0, data_ov011_022282f4, data_ov011_02228308, data_ov011_0222831c, data_ov011_02228330, data_ov011_02228344, data_ov011_02228358, data_ov011_0222836c, data_ov011_02228380, data_ov011_02228398, data_ov011_022283ac, data_ov011_022283c0, data_ov011_022283d4, data_ov011_022283e4, data_ov011_022283f0, data_ov011_022283fc, data_ov011_0222840c, data_ov011_02228418, data_ov011_02228424, data_ov011_02228438, data_ov011_0222844c, data_ov011_02228460, data_ov011_02228474, data_ov011_02228488, data_ov011_0222849c, data_ov011_022284b0, data_ov011_022284c4, data_ov011_022284dc, data_ov011_022284f0, data_ov011_02228504, data_ov011_02228518, data_ov011_0222852c, data_ov011_02228540, data_ov011_02228554, data_ov011_02228568, data_ov011_02228580, data_ov011_02228594, data_ov011_022285a8, data_ov011_022285bc, data_ov011_022285d0, data_ov011_022285e4, data_ov011_022285f8, data_ov011_0222860c, data_ov011_02228624, data_ov011_02228638, data_ov011_0222864c, data_ov011_02228660, data_ov011_02228674, data_ov011_02228688, data_ov011_0222869c, data_ov011_022286b0, data_ov011_022286c8, data_ov011_022286dc, data_ov011_022286f0, data_ov011_02228704, data_ov011_02228718, data_ov011_0222872c, data_ov011_02228740, data_ov011_02228754, data_ov011_0222876c, data_ov011_02228780, data_ov011_02228794, data_ov011_022287a8, data_ov011_022287bc, data_ov011_022287d0, data_ov011_022287e4, data_ov011_022287f8, data_ov011_02228804, data_ov011_0222880c, data_ov011_02228814, data_ov011_0222881c, data_ov011_02228838, data_ov011_02228850, data_ov011_02228868, data_ov011_02228880, data_ov011_02228898, data_ov011_022288b0, data_ov011_022288c8, data_ov011_022288e0, data_ov011_022288ec, data_ov011_022288f4, data_ov011_022288fc, data_ov011_02228904, data_ov011_02228910, data_ov011_0222891c, data_ov011_02228928;
s32 saved,i,engine,lang;
func_0200bc5c(&data_ov011_022282a0); saved=gCur3DSpriteEngine; i=0;
do { if(i==0) engine=g3DSpriteEngineMain; else engine=g3DSpriteEngineSub;
gCur3DSpriteEngine=engine;
if(arg2==0 && engine!=g3DSpriteEngineMain) goto inc;
if(arg2==1 && engine!=g3DSpriteEngineSub) goto inc;
if(arg2==3 && engine!=saved) goto inc;
switch((u32)arg1) {
case 0:
func_020814e4(&data_ov011_022282ac);
func_02081590(&data_ov011_022282bc,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_022282c8,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_020815fc(&data_ov011_022282d4,0,32);func_02081528(); break;

case 1:
func_020814e4(&data_ov011_022282e0);
func_02081590(&data_ov011_022282f4,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_02228308,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_020815fc(&data_ov011_0222831c,0,32);func_02081528(); break;

case 3:
func_020814e4(&data_ov011_02228330);
func_02081590(&data_ov011_02228344,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_02228358,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_0222836c,arg3,0,512);func_02081528(); break;

case 4:
func_020814e4(&data_ov011_02228380);
func_02081590(&data_ov011_02228398,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_022283ac,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_022283c0,arg3,0,512);func_02081528(); break;

case 5:
func_020814e4(&data_ov011_022283d4);
func_02081590(&data_ov011_022283e4,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_0208161c(&data_ov011_022283f0,arg3,0,512);func_02081528(); break;

case 6:
func_020814e4(&data_ov011_022283fc);
func_02081590(&data_ov011_0222840c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_0208161c(&data_ov011_02228418,arg3,0,512);func_02081528(); break;

case 11:
func_020814e4(&data_ov011_02228424);
func_02081590(&data_ov011_02228438,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_0222844c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_02228460,arg3,0,512);func_02081528(); break;

case 12:
func_020814e4(&data_ov011_02228474);
func_02081590(&data_ov011_02228488,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_0222849c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_022284b0,arg3,0,512);func_02081528(); break;

case 7:
func_020814e4(&data_ov011_022284c4);
func_02081590(&data_ov011_022284dc,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_022284f0,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_02228504,arg3,0,512);func_02081528(); break;

case 8:
func_020814e4(&data_ov011_02228518);
func_02081590(&data_ov011_0222852c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_02228540,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_02228554,arg3,0,512);func_02081528(); break;

case 9:
func_020814e4(&data_ov011_02228568);
func_02081590(&data_ov011_02228580,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_02228594,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_022285a8,arg3,0,512);func_02081528(); break;

case 10:
func_020814e4(&data_ov011_022285bc);
func_02081590(&data_ov011_022285d0,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_022285e4,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_022285f8,arg3,0,512);func_02081528(); break;

case 13:
func_020814e4(&data_ov011_0222860c);
func_02081590(&data_ov011_02228624,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_02228638,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_0222864c,arg3,0,512);func_02081528(); break;

case 14:
func_020814e4(&data_ov011_02228660);
func_02081590(&data_ov011_02228674,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_02228688,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_0222869c,arg3,0,512);func_02081528(); break;

case 15:
func_020814e4(&data_ov011_022286b0);
func_02081590(&data_ov011_022286c8,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_022286dc,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_02081644(&data_ov011_022286f0,arg3,0,512);func_02081528(); break;

case 16:
func_020814e4(&data_ov011_02228704);
func_02081590(&data_ov011_02228718,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_0222872c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_02081644(&data_ov011_02228740,arg3,0,512);func_02081528(); break;

case 17:
func_020814e4(&data_ov011_02228754);
func_02081590(&data_ov011_0222876c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_02228780,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_02228794,arg3,0,512);func_02081528(); break;

case 18:
func_020814e4(&data_ov011_022287a8);
func_02081590(&data_ov011_022287bc,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_022287d0,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_0208161c(&data_ov011_022287e4,arg3,0,512);func_02081528(); break;

case 19:
func_020814e4(&data_ov011_022287f8);
func_02081590(&data_ov011_02228804,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_0222880c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_020815fc(&data_ov011_02228814,0,32);func_02081528(); break;

case 20:
func_020814e4(&data_ov011_0222881c);
func_02081590(&data_ov011_02228838,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_02228850,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_02081644(&data_ov011_02228868,arg3,0,512);func_02081528(); break;

case 21:
func_020814e4(&data_ov011_02228880);
func_02081590(&data_ov011_02228898,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_022288b0,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_02081644(&data_ov011_022288c8,arg3,0,512);func_02081528(); break;

case 22:
lang=func_020e31e0(); if(lang==1||lang==2||lang==5) {
func_020814e4(func_020e3218(&data_ov011_022288e0));
func_02081590(func_020e3218(&data_ov011_022288ec), M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(func_020e3218(&data_ov011_022288f4), M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_020815fc(func_020e3218(&data_ov011_022288fc),0,32); func_02081528(); break; }
func_020814e4(&data_ov011_02228904);
func_02081590(&data_ov011_02228910,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,12));
func_02081590(&data_ov011_0222891c,M2C_FIELD(gCur3DSpriteEngine+arg3*4,s32 *,32));
func_020815fc(&data_ov011_02228928,0,32);func_02081528(); break;
} M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46) |= 1<<arg3;
inc: i++; }while(i<2); gCur3DSpriteEngine=saved;
}

void func_ov011_02222010(s32 unused, u32 arg0, s32 arg1) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02080cfc(M2C_UNK *, s32);
    M2C_UNK func_0208116c(M2C_UNK *, M2C_UNK, M2C_UNK);
    M2C_UNK func_020812a4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK *func_020e3218(M2C_UNK *);
    extern s32 gCur3DSpriteEngine;
    extern s32 g3DSpriteEngineSub;
    extern s32 g3DSpriteEngineMain;
    extern M2C_UNK data_ov011_02228934;
    extern M2C_UNK data_ov011_02228940;
    extern M2C_UNK data_ov011_02228950;
    extern M2C_UNK data_ov011_02228960;
    extern M2C_UNK data_ov011_02228970;
    extern M2C_UNK data_ov011_02228980;
    extern M2C_UNK data_ov011_02228994;
    extern M2C_UNK data_ov011_022289a4;
    extern M2C_UNK data_ov011_022289b8;
    extern M2C_UNK data_ov011_022289c8;
    extern M2C_UNK data_ov011_022289dc;
    extern M2C_UNK data_ov011_022289ec;
    extern M2C_UNK data_ov011_02228a00;
    extern M2C_UNK data_ov011_02228a10;
    extern M2C_UNK data_ov011_02228a20;

    s32 saved_r5;
    s32 var_r6;
    s32 var_r7;

    func_0200bc5c(&data_ov011_02228934);

    saved_r5 = gCur3DSpriteEngine;

    var_r6 = 0;
    do {
        if (var_r6 == 0) {
            var_r7 = g3DSpriteEngineMain;
        } else {
            var_r7 = g3DSpriteEngineSub;
        }

        gCur3DSpriteEngine = var_r7;

        if (arg1 == 0 && var_r7 != g3DSpriteEngineMain) goto inc;
        if (arg1 == 1 && var_r7 != g3DSpriteEngineSub) goto inc;
        if (arg1 == 3 && var_r7 != saved_r5) goto inc;

        switch (arg0) {
            case 0:
                func_02080cfc(func_020e3218(&data_ov011_02228940), M2C_FIELD(var_r7, s32 *, 0x1C));
                func_0208116c(&data_ov011_02228950, 0x200, 0x20);
                break;
            case 1:
                func_02080cfc(&data_ov011_02228960, M2C_FIELD(var_r7, s32 *, 0x1C) + 0x800);
                func_0208116c(&data_ov011_02228970, 0x2C0, 0x20);
                break;
            case 3:
                func_02080cfc(func_020e3218(&data_ov011_02228980), M2C_FIELD(var_r7, s32 *, 0x1C));
                func_0208116c(&data_ov011_02228994, 0x200, 0x20);
                break;
            case 4:
                func_02080cfc(func_020e3218(&data_ov011_022289a4), M2C_FIELD(var_r7, s32 *, 0x1C));
                func_0208116c(&data_ov011_022289b8, 0x200, 0x20);
                break;
            case 5:
                func_02080cfc(func_020e3218(&data_ov011_022289c8), M2C_FIELD(var_r7, s32 *, 0x1C));
                func_0208116c(&data_ov011_022289dc, 0x200, 0x20);
                break;
            case 6:
                func_02080cfc(func_020e3218(&data_ov011_022289ec), M2C_FIELD(var_r7, s32 *, 0x1C));
                func_0208116c(&data_ov011_02228a00, 0x200, 0x20);
                break;
            case 7:
                func_02080cfc(&data_ov011_02228a10, M2C_FIELD(var_r7, s32 *, 0x1C));
                func_020812a4(&data_ov011_02228a20, 0, 0, 0x200);
                break;
            default:
                break;
        }

inc:
        var_r6 += 1;
    } while (var_r6 < 2);

    gCur3DSpriteEngine = saved_r5;
}

