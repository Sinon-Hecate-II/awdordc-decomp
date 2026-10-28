/* 31 functions from 0x020CC9C8 to 0x020CD8A8 (main), found by ds-decomp. */
#include "common.h"

void func_020cc9c8(void *obj) {
 extern s32 *gCurrentMap;s32 func_0207cfb8(s32);s32 func_0207cee0(s32);s32 func_0207cf48(s32);void func_0208fe30(s32);
 s32 oldH,oldW,newH,newW,x,y,width,height,map,dx,dy;
 if(func_0207cfb8(*gCurrentMap+0x6ef8)==0) {M2C_FIELD(obj,s32 *,0x5c)=0;M2C_FIELD(obj,s32 *,0x60)=128;func_0208fe30(0x1001e);}
 else {M2C_FIELD(obj,s32 *,0x5c)=128;M2C_FIELD(obj,s32 *,0x60)=0;func_0208fe30(0x1001f);}
 oldH=func_0207cee0(M2C_FIELD(obj,s32 *,0x5c));oldW=func_0207cf48(M2C_FIELD(obj,s32 *,0x5c));
 newH=func_0207cee0(M2C_FIELD(obj,s32 *,0x60));newW=func_0207cf48(M2C_FIELD(obj,s32 *,0x60));
 map=*gCurrentMap;x=M2C_FIELD(map,s16 *,0x5148);y=M2C_FIELD(map,s16 *,0x514a);
 dx=M2C_FIELD(map,s16 *,0x52c2)-(x>>4);dy=M2C_FIELD(map,s16 *,0x52c4)-(y>>4);
 M2C_FIELD(obj,s16 *,0x6c)=M2C_FIELD(*gCurrentMap,s16 *,0x5148);
 M2C_FIELD(obj,s16 *,0x6e)=M2C_FIELD(*gCurrentMap,s16 *,0x5148);
 M2C_FIELD(obj,s16 *,0x70)=M2C_FIELD(*gCurrentMap,s16 *,0x514a);
 M2C_FIELD(obj,s16 *,0x72)=M2C_FIELD(*gCurrentMap,s16 *,0x514a);
 if(dx>=newW-2) {
 map=*gCurrentMap;width=M2C_FIELD(map,u16 *,0x5144);
 x=M2C_FIELD(map,s16 *,0x52c2);if(x<width-3)width=x+3;
 M2C_FIELD(obj,s16 *,0x6e)=(width-newW)<<4;
 }
 if(dy>=newH-2) {
 map=*gCurrentMap;height=M2C_FIELD(map,u16 *,0x5146);
 y=M2C_FIELD(map,s16 *,0x52c4);if(y<height-3)height=y+3;
 M2C_FIELD(obj,s16 *,0x72)=(height-newH)<<4;
 }
 if(oldW<newW) {
 width=M2C_FIELD(*gCurrentMap,u16 *,0x5144);
 if(width<newW+(M2C_FIELD(obj,s16 *,0x6e)>>4))M2C_FIELD(obj,s16 *,0x6e)=(width-newW)<<4;
 }
 if(oldH<newH) {
 height=M2C_FIELD(*gCurrentMap,u16 *,0x5146);
 if(height<newH+(M2C_FIELD(obj,s16 *,0x72)>>4))M2C_FIELD(obj,s16 *,0x72)=(height-newH)<<4;
 }
 M2C_FIELD(obj,s32 *,0x64)=0;M2C_FIELD(obj,s32 *,0x68)=15;
}

void func_020ccbc0(void *arg0) {
extern s32 *gCurrentMap;
s32 func_0207ca38(s32,s32,s32,s32,s32);
void func_0207cec0(s32,s32);
void func_01ffa6fc(void *);
s32 base;
M2C_FIELD(arg0,s32 *,0x64)++;
func_0207cec0(*gCurrentMap+0x6ef8,func_0207ca38(4,M2C_FIELD(arg0,s32 *,0x5c),M2C_FIELD(arg0,s32 *,0x60),M2C_FIELD(arg0,s32 *,0x64),M2C_FIELD(arg0,s32 *,0x68)));
base=*gCurrentMap+0x5120;
M2C_FIELD(base,s16 *,0x28)=func_0207ca38(4,M2C_FIELD(arg0,s16 *,0x6c),M2C_FIELD(arg0,s16 *,0x6e),M2C_FIELD(arg0,s32 *,0x64),M2C_FIELD(arg0,s32 *,0x68));
base=*gCurrentMap+0x5120;
M2C_FIELD(base,s16 *,0x2a)=func_0207ca38(4,M2C_FIELD(arg0,s16 *,0x70),M2C_FIELD(arg0,s16 *,0x72),M2C_FIELD(arg0,s32 *,0x64),M2C_FIELD(arg0,s32 *,0x68));
if(M2C_FIELD(arg0,s32 *,0x64)==M2C_FIELD(arg0,s32 *,0x68))func_01ffa6fc(arg0);
}

void func_020ccc94(void) {
    M2C_UNK func_020d8804();
    func_020d8804();
}

void func_020ccca0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b424;
    func_01ffa3dc(&data_0212b424, 7);
}

u8 func_020cccb8(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_0212b424;
    u8 var_r0;

    if (func_01ffa770(&data_0212b424) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

#pragma opt_strength_reduction off
s32 func_020cccdc(void) {
extern s32 *gCurrentMap;
s32 func_020c1a80(s32);
s32 n=0,x,y,base=*gCurrentMap;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
if(func_020c1a80(M2C_FIELD(M2C_FIELD(base+(y<<1),u16 *,0x3758)+(base+x),u8 *,0x1420)&31) || M2C_FIELD(M2C_FIELD(*gCurrentMap+(y<<1),u16 *,0x3758)+(*gCurrentMap+x),u8 *,0x539c))n++;
base=*gCurrentMap;
}
}
if(n>=99)return 0;return 1;
}
#pragma opt_strength_reduction reset
void func_020ccdc0(M2C_UNK arg0) {
    M2C_UNK func_02084ea0(s32, M2C_UNK);
    func_02084ea0(0x474D4544, arg0);
}

void func_020ccdd8(s32 arg0) {
    void func_01ffa42c(void *, s32);
    extern u8 data_02168f0c;
    extern M2C_UNK data_0212b7ec;
    if (data_02168f0c == 0) return;
    func_01ffa42c(&data_0212b7ec, arg0);
}

void func_020cce04(s32 arg0) {
    void func_020a196c(void);
    void func_0209c8d4(void);
    void func_01ffa8c4(s32, s32);
    u8 func_020cd6d4(void);
    u8 func_020cd28c(void);
    func_020a196c();
    func_0209c8d4();
    if (func_020cd6d4() && func_020cd28c()) {
        func_01ffa8c4(arg0, 1);
    } else {
        func_01ffa8c4(arg0, 0);
    }
}

void func_020cce4c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b894;
    func_01ffa3dc(&data_0212b894, 7);
}

s32 func_020cce64(s32 arg0) {
    extern s32 *gCurrentMap;
    extern u8 data_02168f0c;
    s32 func_020d1980(s32);
    s32 func_020d19b4(s32);
    s32 func_020d1938(s32);
    s32 func_02084614(void);
    s32 func_02084aa0(s32);

    s32 base = *gCurrentMap;
    u8 field7 = M2C_FIELD(arg0 * 0x8C + base, u8 *, 0x67CA);

    if (!func_020d1980(arg0)) return 0;

    if (((u8 *)&data_02168f0c)[0]) {
        s32 r8 = 1;
        s32 i;
        for (i = 1; i < 5; i++) if (func_020d19b4(i)) r8 = i;
        if (func_02084614() == 1) {
            if (((u8 *)&data_02168f0c)[1]) return 3;
            if (((u8 *)&data_02168f0c)[2]) return 3;
        }
        if (func_02084614() == 2) {
            if (r8 == arg0) {
                if (((u8 *)&data_02168f0c)[1]) return 2;
                if (((u8 *)&data_02168f0c)[2] && ((u8 *)&data_02168f0c)[3] == 0) return 2;
            }
            if (((u8 *)&data_02168f0c)[1]) {
                u8 other = M2C_FIELD(r8 * 0x8C + base, u8 *, 0x67CA);
                if (field7 != other) return 1;
                return 2;
            }
            if (((u8 *)&data_02168f0c)[2]) {
                if (((u8 *)&data_02168f0c)[3] == 0) {
                    u8 other = M2C_FIELD(r8 * 0x8C + base, u8 *, 0x67CA);
                    if (field7 != other) return 1;
                    return 2;
                }
                if (func_02084aa0(arg0 - 1)) return 2;
                for (i = 1; i < 5; i++) {
                    if (func_020d1980(i) && func_020d1938(i)) {
                        u8 other = M2C_FIELD(i * 0x8C + base, u8 *, 0x67CA);
                        if (field7 == other) return 1;
                    }
                }
                return 2;
            }
        }
    }

    {
        s32 r4 = 0, r5 = 0, r6 = 0;
        s32 i;
        for (i = 1; i < 5; i++) {
            if (func_020d1980(i)) {
                r4++;
                if (func_020d1938(i)) r5++; else r6++;
            }
        }
        if (r5 == r4) return 3;
        if (r6 == r4) return 3;
        for (i = 1; i < 5; i++) {
            if (func_020d1980(i) && func_020d1938(i)) {
                u8 other = M2C_FIELD(i * 0x8C + base, u8 *, 0x67CA);
                if (field7 == other) return 1;
            }
        }
        return 2;
    }
}

s32 func_020cd164(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 base;
    if (!func_020d1980(arg0)) return 0;
    if (!func_020d1980(arg1)) return 0;
    if (arg0 == arg1) return 0;
    base = *gCurrentMap + 0x67A4;
    if (M2C_FIELD(arg0 * 0x8C + base, u8 *, 0x26) == M2C_FIELD(arg1 * 0x8C + base, u8 *, 0x26)) return 0;
    return func_020cce64(arg0);
}

s32 func_020cd1e4(void) {
    s32 func_020d19b4(s32);
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r4_3;

    var_r4 = 1;
loop_1:
    if ((func_020d19b4(var_r4) != 0) && (func_020cce64(var_r4) == 1)) {
        return 1;
    }
    var_r4 += 1;
    if (var_r4 >= 5) {
        var_r4_2 = 1;
loop_6:
        if ((func_020d19b4(var_r4_2) != 0) && (func_020cce64(var_r4_2) == 2)) {
            return 0;
        }
        var_r4_2 += 1;
        if (var_r4_2 >= 5) {
            var_r4_3 = 1;
loop_11:
            if ((func_020d1980(var_r4_3) != 0) && (func_020cce64(var_r4_3) == 1)) {
                return 1;
            }
            var_r4_3 += 1;
            if (var_r4_3 >= 5) {
                return 0;
            }
            goto loop_11;
        }
        goto loop_6;
    }
    goto loop_1;
}

u8 func_020cd28c(void) {
    s32 func_020cd2b8();
    s32 func_020cd1e4();
    u8 var_r0;

    if (func_020cd2b8() != 0) {
        return 0U;
    }
    if (func_020cd1e4() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_020cd2b8(void) {
    s32 func_020cce64(s32);
    s32 func_020d1980(s32);
    s32 var_r4;

    var_r4 = 1;
loop_1:
    if ((func_020d1980(var_r4) != 0) && (func_020cce64(var_r4) == 3)) {
        return 1;
    }
    var_r4 += 1;
    if (var_r4 >= 5) {
        return 0;
    }
    goto loop_1;
}

s32 func_020cd2f8(void){
extern u8 data_02168f0c;extern s32 *gCurrentMap;s32 i;
if(!data_02168f0c && func_020cce64(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))==1)return M2C_FIELD(*gCurrentMap,u16 *,0x52a4);
for(i=1;i<5;i++)if(func_020d19b4(i) && func_020cce64(i)==1)return i;
for(i=1;i<5;i++)if(func_020d1980(i) && func_020cce64(i)==1)return i;
return 0;
}

s32 func_020cd3bc(void){
extern u8 data_02168f0c;extern s32 *gCurrentMap;s32 i;
if(!data_02168f0c && func_020cce64(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))==2)return M2C_FIELD(*gCurrentMap,u16 *,0x52a4);
for(i=1;i<5;i++)if(func_020d19b4(i) && func_020cce64(i)==2)return i;
for(i=1;i<5;i++)if(func_020d1980(i) && func_020cce64(i)==2)return i;
return 0;
}

void func_020cd544(s32);
void func_020cd480(s32 a){
extern u16 data_02168f14;extern s32 *gCurrentMap;extern M2C_UNK data_0212b804;extern u32 data_0215d8a0[];u32 v;
func_02088634();if(func_020e4b28(a)){func_020cd544(a);return;}
func_020e49ec();data_0215d8a0[0]=(data_0215d8a0[0]&~15)|(a&15);
v=data_0215d8a0[0]&~240;*(volatile u32 *)data_0215d8a0=v;
data_02168f14 &= ~7;
v&=~0xff0000;
v&=~0xff00;
data_0215d8a0[1]=(u16)(data_0215d8a0[1]&0xffff0000);
data_0215d8a0[0]=v&~0xff000000;
M2C_FIELD(*gCurrentMap,u16 *,0x5142)=161;func_02086810(161,1);func_01ffa3dc(&data_0212b804,7);
}

void func_020cd544(s32 arg0) {
    extern u16 data_02168f14;
    extern M2C_UNK data_0212b844;
    s32 func_020bf054(s32, s32);
    s32 func_020bee64(s32);
    u8 value;
    func_02088634();
    value = func_020bf054(0, arg0);
    data_02168f14 &= ~7;
    func_020e4a18(arg0);
    if (func_020bee64(value)) {
        func_020d4ac8(value);
    } else {
        func_01ffa3dc(&data_0212b844, 7);
    }
}

void func_020cd5ac(void) {
    extern M2C_UNK data_0212b844;
    extern u16 data_02168f14;
    data_02168f14 &= ~7;
    func_01ffa3dc(&data_0212b844, 7);
}

s32 func_020cd5d8(void) {
    extern M2C_UNK data_0215d9b8;
    switch ((u32)(M2C_FIELD(&data_0215d9b8, u16 *, 6) << 20) >> 30) {
    case 0: return 1;
    case 1: return 1;
    default: return 0;
    }
}

s32 func_020cd614(void) {
    extern M2C_UNK data_0215d9b8;
    extern s32 *gCurrentMap;
    s32 func_020d19b4(s32);
    switch ((u32)(M2C_FIELD(&data_0215d9b8, u16 *, 6) << 18) >> 30) {
    case 0: return 1;
    case 1:
        if (func_020d19b4(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4))) return 1;
    }
    return 0;
}

s32 func_020cd674(void) {
    extern M2C_UNK data_0215d9b8;
    switch ((u32)(M2C_FIELD(&data_0215d9b8, u16 *, 6) << 20) >> 30) {
    case 2: return 1;
    case 1: return 1;
    }
    return 0;
}

u8 func_020cd6b0(void) {
    extern M2C_UNK data_0215d9b8;
    u8 var_r0;

    if (((u32) (M2C_FIELD(&data_0215d9b8, u16 *, 6) << 0x11) >> 0x1F) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020cd6d4(void) {
    extern M2C_UNK data_02168f08;
    u8 var_r0;

    if (!(((u32) (M2C_FIELD(&data_02168f08, u16 *, 0xC) << 0x1D) >> 0x1D) & 0xFF)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020cd6fc(void) {
    extern M2C_UNK data_02168f08;
    u8 value;
    if ((u8)((u32)(M2C_FIELD(&data_02168f08, u16 *, 0xC) << 29) >> 29) == 1) value = 1;
    else value = 0;
    return value;
}

u8 func_020cd728(void) {
    extern M2C_UNK data_02168f08;
    u8 value;
    if ((u8)((u32)(M2C_FIELD(&data_02168f08, u16 *, 12) << 29) >> 29) == 2) value = 1;
    else value = 0;
    return value;
}

void func_020cd754(s32 arg0) {
extern s32 *gCurrentMap;
void func_02007f8c(s32, s32);
s32 base = *gCurrentMap;
if (M2C_FIELD(base,u8 *,0x5156)==0 && M2C_FIELD(base,u8 *,0x5158)!=2)
func_02007f8c((base+0x5160) + arg0*(u32)0xA1,255);
else func_02007f8c((base+0x5160) + arg0*(u32)0xA1,0);
}

void func_020cd7bc(s32 arg0,s32 arg1) {
extern s32 *gCurrentMap;
void func_02008048(s32,s32);
s32 base=*gCurrentMap+0x5160;
func_02008048(base+arg0*(u32)0xA1,base+arg1*(u32)0xA1);
}

s32 func_020cd7ec(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 temp_r0;

    if (func_020d1980(arg1) == 0) {
        return 0;
    }
    temp_r0 = *gCurrentMap + 0x67A4;
    if (M2C_FIELD(((arg0 * 0x8C) + temp_r0), u8 *, 0x26) != M2C_FIELD(((arg1 * 0x8C) + temp_r0), u8 *, 0x26)) {
        return 1;
    }
    return 2;
}

s32 func_020cd848(s32 arg0) {
 s32 i, v, n;
 n = arg0 + 1;
 i = 1;
 do {
 v = n;
 if (n >= 5) v = n - 4;
 if (func_020cd7ec(arg0, (u16)v) == 2 && func_020d19b4(v) != 0) return 1;
 i++;
 n++;
 } while(i < 4);
 return 0;
}

