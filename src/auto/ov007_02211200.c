/* 41 functions from 0x02211200 to 0x02212200 (ov007), found by ds-decomp. */
#include "common.h"

void func_ov007_02211200(void *arg0) {
 extern void **gCurrentMap;
 extern u8 data_ov007_0221f678[];
 void func_ov007_02211ea4(s32);void func_ov007_02211f10(s32);
 void func_ov007_02211f60(s32);void func_ov007_02211f70(s32);void func_ov007_02211f80(s32);void func_ov007_02211fb0(s32);void func_ov007_02211fc0(s32);
 void func_ov007_022121b0(void);void func_ov007_022121d4(s32);void func_ov007_022121e4(void);
 void func_020cf498(s16,s16);
 void *base;
 s32 value;
 s32 x,y;
 void (*callback)(void);
 func_020ceb48();func_020d8cfc();
 M2C_FIELD(*gCurrentMap,u8*,0x5141)=4;
 func_020bfb74(0);func_0209f5dc();func_020bfa80(0);
 if(!func_020c8020(M2C_FIELD(*gCurrentMap,u16*,0x5142))){
 base=*gCurrentMap;
 value=func_02086680(0xc00002eb);
 func_020675e4((u8*)base+0x5120,data_ov007_0221f678,value,func_020c8018(M2C_FIELD(base,u16*,0x5142))+1);
 }else{
 base=*gCurrentMap;
 value=func_020cfbdc(M2C_FIELD(base,u16*,0x5142));
 func_02068c50((u8*)base+0x5120,value);
 }
 func_020d216c();func_020d1f2c();
 M2C_FIELD(*gCurrentMap,u16*,0x52a4)=0;
 M2C_FIELD(*gCurrentMap,u8*,0x5155)=0;
 M2C_FIELD(*gCurrentMap,u16*,0x52b0)=0;
 func_020ceec8();func_02086608(4);func_020cbdbc();func_020a68d4();func_020a45cc();func_020a23c4();func_020d1c58();func_020d1ce0();
 func_ov007_0221c648(M2C_FIELD(*gCurrentMap,u16*,0x5142));func_020b1ae0();
 callback=M2C_FIELD(gCurrentMap[1],void(**)(void),0x50);
 if(callback)callback();
 func_0207ce28((u8*)*gCurrentMap+0x6ef8);func_020d4b30();
 base=*gCurrentMap;
 x=(u32)M2C_FIELD(base,u16*,0x5144)>>1;
 y=(u32)M2C_FIELD(base,u16*,0x5146)>>1;
 func_020cf498((s16)x,(s16)y);func_0207b754(x,y);
 func_ov007_02211ea4(0);func_ov007_02211f10(0);func_ov007_02211f60(1);func_ov007_02211f70(1);func_ov007_02211f80(0);func_ov007_02211fb0(1);func_ov007_02211fc0(0);
 func_ov007_022121b0();func_ov007_02212da0();func_ov007_02213150();func_ov007_0221ab20();func_ov007_022121d4(0);
 M2C_FIELD(arg0,u8*,0x34)=1;
 func_ov007_022121e4();
}

void func_ov007_0221142c(M2C_UNK arg0) {
    M2C_UNK func_02086740(M2C_UNK, M2C_UNK);
    s32 func_02086a30(M2C_UNK);
    M2C_UNK func_0208999c(void *, M2C_UNK, s32);
    void *func_0208b564(M2C_UNK);
    void *temp_r0;

    if (func_02086a30(0x20) != 0) {
        return;
    }
    func_02086740(0x20, 1);
    temp_r0 = func_0208b564(arg0);
    func_0208999c(temp_r0, 2, 0x46000025);
    M2C_FIELD(temp_r0, s32 *, 0x58) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x58) & ~0x1FC00000) | 0x01000000);
}

void func_ov007_02211480(void) {
    M2C_UNK func_02086658(M2C_UNK);
    M2C_UNK func_0208c748();
    M2C_UNK func_020b2178();
    M2C_UNK func_020bfbc0(M2C_UNK);
    M2C_UNK func_020d4c08();
    M2C_UNK func_ov007_02212db8();
    M2C_UNK func_ov007_0221ab38();
    func_02086658(4);
    func_ov007_02212db8();
    func_020b2178();
    func_ov007_0221ab38();
    func_020d4c08();
    func_0208c748();
    func_020bfbc0(0);
}

void func_ov007_022114ac(M2C_UNK arg0) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f5c0;
    func_01ffa3dc(&data_ov007_0221f5c0, arg0);
}

void func_ov007_022114c4(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_ov007_02211f30();
    s32 func_ov007_02211f40();
    s32 func_ov007_02211f50();
    s32 func_ov007_0221bc18(s32, s32, s32, s32, s32);
    M2C_UNK func_020cfe2c();
    void func_ov007_022121b0(void);
    void func_ov007_022121d4(s32);
    M2C_UNK func_0208fb54(s32, s32, s32, s32);
    M2C_UNK func_0208fe30(s32);
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r5;
    temp_r5 = func_ov007_02211f30();
    temp_r4 = func_ov007_02211f40();
    temp_r0 = func_ov007_0221bc18(arg1, arg2, temp_r5, temp_r4, func_ov007_02211f50());
    switch (temp_r0) {
    case 1:
        func_020cfe2c();
        func_ov007_022121b0();
        func_ov007_022121d4(1);
        func_ov007_022114ac(arg0);
        func_0208fb54(0x119, arg1, arg2, 1);
        return;
    case 0:
        if (arg3 == 0) return;
        func_0208fe30(0x1001D);
        return;
    }
}

void func_ov007_02211560(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_ov007_0221bd74(s32, s32);
    s32 func_ov007_0221bdc0(s32, s32);
    s32 func_ov007_0221be00(s32, s32);
    void func_ov007_02211f60(s32);
    void func_ov007_02211f70(s32);
    void func_ov007_02211f80(s32);
    void func_ov007_022121b0(void);
    M2C_UNK func_ov007_0221ab4c();
    M2C_UNK func_0208fb54(s32, s32, s32, s32);
    M2C_UNK func_0208fe30(s32);
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    temp_r6 = func_ov007_0221bd74(arg1, arg2);
    temp_r5 = func_ov007_0221bdc0(arg1, arg2);
    temp_r4 = func_ov007_0221be00(arg1, arg2);
    if (temp_r6 >= 0) {
        func_ov007_02211f60(temp_r6);
        func_ov007_02211f70(temp_r5);
        func_ov007_02211f80(temp_r4);
        func_ov007_022121b0();
        func_ov007_0221ab4c();
        func_0208fb54(0x11B, arg1, arg2, 1);
        return;
    }
    if (arg3 == 0) return;
    func_0208fe30(0x1001D);
}

void func_ov007_022115fc(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_ov007_0221bcc0(s32, s32);
    M2C_UNK func_020cfe2c();
    void func_ov007_022121b0(void);
    void func_ov007_022121d4(s32);
    M2C_UNK func_020b5134(M2C_UNK *, s32, s32, s32, s32, s32, M2C_UNK);
    M2C_UNK func_0208fb54(s32, s32, s32, s32);
    M2C_UNK func_0208fe30(s32);
    extern M2C_UNK data_ov007_0221f680;
    if (func_ov007_0221bcc0(arg1, arg2) != 0) {
        func_020cfe2c();
        func_ov007_022121b0();
        func_ov007_022121d4(1);
        func_ov007_022114ac(arg0);
        func_020b5134(&data_ov007_0221f680, arg1, arg2, 0x50, 0, 0, arg0);
        func_0208fb54(0x8A, arg1, arg2, 1);
        return;
    }
    if (arg3 == 0) return;
    func_0208fe30(0x1001D);
}

void func_ov007_022116a0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_0208fe30(s32);
    s32 func_ov007_02214718(M2C_UNK, M2C_UNK);
    if (func_ov007_02214718(arg1, arg2) != 0) {
        return;
    }
    if (arg3 == 0) {
        return;
    }
    func_0208fe30(0x1001D);
}

void func_ov007_022116d4(M2C_UNK a,s32 x,s32 y,s32 sound){
u8 func_ov007_02211f90();u8 func_ov007_02211fa0();s32 func_ov007_0221b0a4(s32,s32,s32,s32,s32);
M2C_UNK func_020cfe2c();void func_ov007_022121b0(void);void func_ov007_022121d4(s32);M2C_UNK func_0208fb54(s32,s32,s32,s32);M2C_UNK func_0208fe30(s32);
s32 kind=func_ov007_02211f90();s32 other=func_ov007_02211fa0();
switch(func_ov007_0221b0a4(x,y,kind,other,1)){
case 1:func_020cfe2c();func_ov007_022121b0();func_ov007_022121d4(1);func_ov007_022114ac(a);
switch(kind){case 7:case 8:case 9:case 10:case 11:case 12:func_0208fb54(0x11a,x,y,1);break;
default:func_0208fb54(0x119,x,y,1);break;}break;
case 0:if(sound==0)return;func_0208fe30(0x1001d);break;
}
}

void func_ov007_022117e0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_0208fb54(s32, M2C_UNK, M2C_UNK, s32);
    void func_ov007_02211fb0(s32);
    void func_ov007_02211fc0(s32);
    void func_ov007_022121b0(void);
    M2C_UNK func_ov007_0221ab4c();
    s32 func_ov007_0221b6c8(M2C_UNK, M2C_UNK);
    s32 func_ov007_0221b704(M2C_UNK, M2C_UNK);
    s32 temp_r4;
    s32 temp_r5;
    temp_r5 = func_ov007_0221b6c8(arg1, arg2);
    temp_r4 = func_ov007_0221b704(arg1, arg2);
    func_ov007_02211fb0(temp_r5);
    func_ov007_02211fc0(temp_r4);
    func_ov007_022121b0();
    func_ov007_0221ab4c();
    func_0208fb54(0x11B, arg1, arg2, 1);
}

void func_ov007_02211840(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
s32 func_ov007_0221b754(s32,s32);
s32 func_ov007_0221b0a4(s32,s32,s32,s32,s32);
M2C_UNK func_020cfe2c();
void func_ov007_022121b0(void);
void func_ov007_022121d4(s32);
M2C_UNK func_020b5134(M2C_UNK*,s32,s32,s32,s32,s32,M2C_UNK);
M2C_UNK func_0208fb54(s32,s32,s32,s32);
M2C_UNK func_0208fe30(s32);
extern M2C_UNK data_ov007_0221f690;
s32 n=1;
if(func_ov007_0221b754(arg1,arg2))n=8;
if(func_ov007_0221b0a4(arg1,arg2,n,0,1)==1) {
func_020cfe2c();func_ov007_022121b0();func_ov007_022121d4(1);
func_ov007_022114ac(arg0);
func_020b5134(&data_ov007_0221f690,arg1,arg2,0x50,0,0,arg0);
func_0208fb54(0x8a,arg1,arg2,1);
return;
}
if(arg3==0)return;
func_0208fe30(0x1001d);
}

void func_ov007_0221190c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_0208fb54(s32, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020cfd28();
    u8 func_ov007_02211f90(void);
    u8 func_ov007_02211fa0(void);
    void func_ov007_022121b0(void);
    void func_ov007_022121d4(s32);
    M2C_UNK func_ov007_0221ab4c();
    s32 func_ov007_0221b56c(M2C_UNK, M2C_UNK, s32, s32);
    s32 temp_r0;
    s32 temp_r4;
    temp_r4 = func_ov007_02211f90();
    temp_r0 = func_ov007_0221b56c(arg1, arg2, temp_r4, func_ov007_02211fa0());
    switch (temp_r0) {
    case 1:
        func_020cfd28();
        func_ov007_022121b0();
        func_ov007_0221ab4c();
        func_ov007_022121d4(1);
        func_0208fb54(0x11C, arg1, arg2, 1);
        return;
    case 0:
        if (arg3 == 0) return;
        func_0208fe30(0x1001D);
        return;
    }
}

/* Returns 0 if cell (x,y) is usable for the current action, else a nonzero status code (4/5). */
s32 func_ov007_02211990(s32 x, s32 y) {
    extern void **gCurrentMap;
    u8 func_ov007_02211f00(void); u8 func_ov007_02211f20(void);
    s32 func_ov007_02211f30(void); s32 func_ov007_02211f40(void); s32 func_ov007_02211f50(void);
    u8 func_ov007_02211f90(void); u8 func_ov007_02211fa0(void);
    s32 func_ov007_0221bb44(s32, s32, s32, s32, s32);
    s32 func_ov007_0221acac(s32, s32, s32, s32); s32 func_020c1a80(s32);
    s32 a, b; void *p;
    switch (func_ov007_02211f00()) {
    case 1:
        switch (func_ov007_02211f20()) {
        case 0:
            a = func_ov007_02211f30();
            b = func_ov007_02211f40();
            if (!func_ov007_0221bb44(x, y, a, b, func_ov007_02211f50()))
                return 5;
            break;
        case 2:
            return 4;
        case 1:
        case 3:
            p = *gCurrentMap;
            if (!M2C_FIELD(p, u8 *, x + M2C_FIELD((u8 *)p + y * 2, u16 *, 0x3758)))
                return 5;
            break;
        }
        break;
    case 0:
        switch (func_ov007_02211f20()) {
        case 0:
        case 1:
            a = func_ov007_02211f90();
            if (!func_ov007_0221acac(x, y, a, func_ov007_02211fa0()))
                return 5;
            break;
        case 2:
            return 4;
        case 3:
            a = func_ov007_02211f90();
            if (!func_ov007_0221acac(x, y, a, func_ov007_02211fa0()))
                return 5;
            if (func_020c1a80(func_ov007_02211f90()))
                return 5;
            break;
        }
        break;
    }
    return 0;
}

void func_ov007_02211ae8(M2C_UNK arg0) {
    extern void *data_02101e84;
    extern void *data_02101e88;
    extern void **gCurrentMap;
    s32 func_020d46e8(void);
    s32 func_020ab240(void);
    void func_020cf828(s32);
    void func_0207a7a4(s32, s32);
    s32 func_ov007_02211990(s32, s32);
    void func_020cf5ec(s32);
    void func_020ccca0(void);
    void func_ov007_02219418(void);
    void func_ov007_022144ec(void);
    void func_ov007_0221330c(void);
    u8 func_ov007_02211f00(void);
    u8 func_ov007_02211f20(void);
    void func_ov007_022114c4(M2C_UNK, s32, s32, s32);
    void func_ov007_022116d4(M2C_UNK, s32, s32, s32);
    void func_ov007_02211560(M2C_UNK, s32, s32, s32);
    void func_ov007_022117e0(M2C_UNK, s32, s32);
    void func_ov007_022115fc(M2C_UNK, s32, s32, s32);
    void func_ov007_02211840(M2C_UNK, s32, s32, s32);
    void func_ov007_022116a0(M2C_UNK, s32, s32, s32);
    void func_ov007_0221190c(M2C_UNK, s32, s32, s32);
    s32 r4;
    s32 r5;
    void *q;
    s32 r6;
    s32 r7;
    s16 val;
    s32 t;
    u8 f;
    r4 = *(u16 *)data_02101e84;
    r5 = *(u16 *)((u8 *)data_02101e84 + 6);
    if (func_020d46e8()) {
        ((u8 *)arg0)[0x34] = 1;
        return;
    }
    q = data_02101e88;
    if (((u8 *)q)[0x12]) r5 |= 1;
    if (((u8 *)q)[0x14]) r4 |= 1;
    if (((u8 *)arg0)[0x34]) {
        r5 = r4;
        if (r4) ((u8 *)arg0)[0x34] = 0;
    }
    if (!func_020ab240()) {
        func_020cf828(0x1001b);
        func_0207a7a4(1, 4);
        r6 = *(s16 *)((u8 *)*gCurrentMap + 0x52c2);
        r7 = *(s16 *)((u8 *)*gCurrentMap + 0x52c4);
        val = func_ov007_02211990(r6, r7);
        func_020cf5ec(val);
    }
    if (r4 & 0x100) { func_020ccca0(); return; }
    if (r4 & 0x200) { func_ov007_02219418(); return; }
    if (r4 & 0x8) { func_ov007_022144ec(); return; }
    if (r4 & 0x4) { func_ov007_0221330c(); return; }
    if (!((u8 *)data_02101e88)[0x12]) goto L_b4c;
    if (func_020ab240()) return;
    t = func_ov007_02211f20();
    switch (t) {
    case 0:
        if (!(r5 & 1)) return;
        f = func_ov007_02211f00();
        if (f == 0) goto L_c0;
        if (f != 1) return;
        func_ov007_022114c4(arg0, r6, r7, r4 & 1);
        return;
    L_c0:
        func_ov007_022116d4(arg0, r6, r7, r4 & 1);
        return;
    case 1:
        if (!(r4 & 1)) return;
        r4 &= 1;
        f = func_ov007_02211f00();
        if (f == 0) goto L_c1;
        if (f != 1) return;
        func_ov007_02211560(arg0, r6, r7, r4);
        return;
    L_c1:
        func_ov007_022117e0(arg0, r6, r7);
        return;
    case 2:
        if (!(r5 & 1)) return;
        f = func_ov007_02211f00();
        if (f == 0) goto L_c2;
        if (f != 1) return;
        func_ov007_022115fc(arg0, r6, r7, r4 & 1);
        return;
    L_c2:
        func_ov007_02211840(arg0, r6, r7, r4 & 1);
        return;
    case 3:
        if (!(r4 & 1)) return;
        r4 &= 1;
        f = func_ov007_02211f00();
        if (f == 0) goto L_c3;
        if (f != 1) return;
        func_ov007_022116a0(arg0, r6, r7, r4);
        return;
    L_c3:
        func_ov007_0221190c(arg0, r6, r7, r4);
        return;
    }
    return;
L_b4c:
    f = func_ov007_02211f00();
    if (f == 0) goto L_be4;
    if (f != 1) return;
    if (r5 & 1) { func_ov007_022114c4(arg0, r6, r7, r4 & 1); return; }
    if (r4 & 2) { func_ov007_02211560(arg0, r6, r7, r4 & 2); return; }
    if (*(u16 *)((u8 *)data_02101e84 + 6) & 0x400) { func_ov007_022115fc(arg0, r6, r7, r4 & 0x400); return; }
    if (r4 & 0x800) { func_ov007_022116a0(arg0, r6, r7, r4 & 0x800); return; }
    return;
L_be4:
    if (r5 & 1) { func_ov007_022116d4(arg0, r6, r7, r4 & 1); return; }
    if (r4 & 2) { func_ov007_022117e0(arg0, r6, r7); return; }
    if (r5 & 0x400) { func_ov007_02211840(arg0, r6, r7, r4 & 0x400); return; }
    if (r4 & 0x800) { func_ov007_0221190c(arg0, r6, r7, r4 & 0x800); return; }
}

void func_ov007_02211e6c(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f5f8;
    func_01ffa42c(&data_ov007_0221f5f8, arg0);
}

void func_ov007_02211e84(void) {
    M2C_UNK func_01ffa6fc();
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov007_0221f5f8;
    if (func_01ffa770(&data_ov007_0221f5f8) == 0) {
        return;
    }
    func_01ffa6fc();
}

void func_ov007_02211ea4(s32 arg0) {
    extern u8 data_ov007_02221a00;
    extern void **gCurrentMap;
    data_ov007_02221a00 = arg0;
    switch (arg0) {
    case 0:
        M2C_FIELD(*gCurrentMap, s16 *, 0x52B4) = 0xA;
        return;
    case 1:
        M2C_FIELD(*gCurrentMap, s16 *, 0x52B4) = 0;
        return;
    }
}

u8 func_ov007_02211f00(void) {
    extern u8 data_ov007_02221a00;
    return data_ov007_02221a00;
}

void func_ov007_02211f10(s32 arg0) {
    extern u8 data_ov007_02221a00;
    M2C_FIELD(&data_ov007_02221a00, u8 *, 9) = arg0;
}

u8 func_ov007_02211f20(void) {
    extern u8 data_ov007_02221a00;
    return M2C_FIELD(&data_ov007_02221a00, u8 *, 9);
}

s32 func_ov007_02211f30(void) {
    extern u8 data_ov007_02221a00;
    return M2C_FIELD(&data_ov007_02221a00, u8 *, 8);
}

s32 func_ov007_02211f40(void) {
    extern u8 data_ov007_02221a00;
    return M2C_FIELD(&data_ov007_02221a00, u8 *, 7);
}

s32 func_ov007_02211f50(void) {
    extern u8 data_ov007_02221a00;
    return M2C_FIELD(&data_ov007_02221a00, u8 *, 6);
}

void func_ov007_02211f60(s32 arg0) {
    extern u8 data_ov007_02221a00;
    M2C_FIELD(&data_ov007_02221a00, u8 *, 8) = arg0;
}

void func_ov007_02211f70(s32 arg0) {
    extern u8 data_ov007_02221a00;
    M2C_FIELD(&data_ov007_02221a00, u8 *, 7) = arg0;
}

void func_ov007_02211f80(s32 arg0) {
    extern u8 data_ov007_02221a00;
    M2C_FIELD(&data_ov007_02221a00, u8 *, 6) = arg0;
}

u8 func_ov007_02211f90(void) {
    extern u8 data_ov007_02221a00;
    return M2C_FIELD(&data_ov007_02221a00, u8 *, 3);
}

u8 func_ov007_02211fa0(void) {
    extern u8 data_ov007_02221a00;
    return M2C_FIELD(&data_ov007_02221a00, u8 *, 1);
}

void func_ov007_02211fb0(s32 arg0) {
    extern u8 data_ov007_02221a00;
    M2C_FIELD(&data_ov007_02221a00, u8 *, 3) = arg0;
}

void func_ov007_02211fc0(s32 arg0) {
    extern u8 data_ov007_02221a00;
    M2C_FIELD(&data_ov007_02221a00, u8 *, 1) = arg0;
}

void func_ov007_02211fd0(void) {
    s8 func_020d2ff0(s32);
    extern M2C_UNK data_ov007_02221a48;
    s32 var_r4;
    s8 *var_r5;
    s8 temp_r0;

    var_r5 = (s8 *)&data_ov007_02221a48;
    var_r4 = 0;
    do {
        temp_r0 = func_020d2ff0(var_r4);
        var_r4 += 1;
        *var_r5 = temp_r0;
        var_r5 += 1;
    } while (var_r4 < 5);
}

s32 func_ov007_02211ffc(s32 arg0) {
    extern M2C_UNK data_ov007_02221a48;
    return M2C_FIELD(&data_ov007_02221a48, u8 *, arg0);
}

void func_ov007_0221200c(void) {
    s8 func_020c1878(M2C_UNK *);
    extern M2C_UNK data_ov007_02221a0a;
    extern u8 data_ov007_02221a00;
    M2C_FIELD(&data_ov007_02221a00, u8 *, 4) = func_020c1878(&data_ov007_02221a0a);
}

s32 func_ov007_0221202c(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_020c1980(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov007_02221a0a;
    return func_020c1980(&data_ov007_02221a0a, arg0, arg1);
}

u8 func_ov007_0221204c(void) {
    extern u8 data_ov007_02221a00;
    return M2C_FIELD(&data_ov007_02221a00, u8 *, 4);
}

void func_ov007_0221205c(void){
void func_020a23a4(s32,s32);void func_020a231c(s32,s32);s32 func_020a23b4(s32);s32 func_ov007_02211ffc(s32);s32 func_ov007_0221202c(s32,s32);
extern u8 data_ov007_02221a00;
s32 i;
for(i=0;i<5;i++){func_020a23a4(i,0);func_020a231c(i,i);}
for(i=1;i<5;i++){
if(func_ov007_02211ffc(i)>0)func_020a23a4(i,1);
if(func_ov007_0221202c(2,i)>0)func_020a23a4(i,1);
if(func_ov007_0221202c(3,i)>0)func_020a23a4(i,1);
if(func_ov007_0221202c(4,i)>0)func_020a23a4(i,1);
}
M2C_FIELD(&data_ov007_02221a00,u8 *,2)=0;
for(i=0;i<5;i++){if(func_020a23b4(i)==1)M2C_FIELD(&data_ov007_02221a00,u8 *,2)++;}
}

u8 func_ov007_0221216c(s32 arg0) {
    s32 func_020a23b4();
    extern u8 data_ov007_02221a00;
    u8 var_r0;
    u8 var_r0_2;
    if (arg0 < 0) {
        if ((u32) M2C_FIELD(&data_ov007_02221a00, u8 *, 2) >= 2U) {
            var_r0_2 = 1;
        } else {
            var_r0_2 = 0;
        }
        return var_r0_2;
    }
    if (func_020a23b4(arg0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov007_022121b0(void) {
    void func_ov007_02211fd0(void);
    void func_ov007_0221205c(void);
    void func_ov007_0221200c(void);
    func_ov007_02211fd0();
    func_ov007_0221200c();
    func_ov007_0221205c();
}

u8 func_ov007_022121c4(void) {
    extern u8 data_ov007_02221a00;
    return M2C_FIELD(&data_ov007_02221a00, u8 *, 5);
}

void func_ov007_022121d4(s32 arg0) {
    extern u8 data_ov007_02221a00;
    M2C_FIELD(&data_ov007_02221a00, u8 *, 5) = arg0;
}

void func_ov007_022121e4(void) {
    M2C_UNK func_020b51dc();
    M2C_UNK func_020b5200(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_0221f6a0;
    func_020b51dc();
    func_020b5200(&data_ov007_0221f6a0, 0);
}

