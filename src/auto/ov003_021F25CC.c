/* 19 functions from 0x021F25CC to 0x021F35B0 (ov003), found by ds-decomp. */
#include "common.h"

s32 func_ov003_021f25cc(void) {
 s32 func_020d886c();
 switch(func_020d886c()) {
 case 6: case 8: case 12: case 14: case 15: case 16: case 17: case 22: case 23: case 24: return 1;
 case 0: case 1: case 2: case 3: case 4: case 5: case 7: case 9: case 10: case 11: case 13: case 18: case 19: case 20: case 21: default: return 0;
 }
}

s32 func_ov003_021f2654(void) {
 s32 func_020d886c();
 switch(func_020d886c()) {
 case 6: case 12: case 22: case 23: return 1;
 default: return 0;
 }
}

u8 func_ov003_021f269c(s32 unused,u16 *array,s32 value) {
 u8 i=0;
 do { if(value==array[i]) return i; ++i;}while(i<5);
 return 255;
}

void func_ov003_021f26c8(s32 arg0,s32 arg1,M2C_UNK value) {
 u8 func_ov003_021f27b8();
 M2C_UNK func_0208fe30(s32);
 s32 func_ov003_021f27d4(s32,s32);
 s32 i; s32 other;
 i=func_ov003_021f269c(arg0,(u16 *)arg1,value);
 if(i!=255) {
 func_0208fe30(0x1000f); ((u16 *)arg1)[i]=65535; return;
 }
 if(func_ov003_021f27b8(arg0,arg1)) {func_0208fe30(0x1001d);return;}
 other=arg0+4; if(arg1==other) other=arg0+14;
 if(func_ov003_021f269c(arg0,(u16 *)other,value)!=255) {func_0208fe30(0x1001d);return;}
 i=func_ov003_021f27d4(arg0,arg1);
 func_0208fe30(0x1000d);
 ((u16 *)arg1)[i]=value;
}

s32 func_ov003_021f2780(s32 unused,u16 *array) {
    u8 count=0,i=0;
    do { if(array[i]!=0xffff) ++count; ++i; } while(i<5);
    return count;
}

u8 func_ov003_021f27b8(s32 arg0, s32 arg1) {
    s32 func_ov003_021f2780();
    u8 var_r0;

    if (func_ov003_021f2780() == 5) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov003_021f27d4(s32 unused,s32 array) {
    u8 i=0;
    do { if(((u16 *)array)[i]==0xffff) return i; ++i; } while(i<5);
    return 255;
}

void func_ov003_021f2808(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_0208fe30(s32);
    s32 func_020c7eb8(M2C_UNK);
    void func_ov003_021f26c8(s32, s32, M2C_UNK);
    if (func_020c7eb8(arg1) == 0) {
        func_0208fe30(0x1001D);
        return;
    }
    func_ov003_021f26c8(arg0, arg0 + 4, arg1);
}

void func_ov003_021f2848(s32 arg0) {
    M2C_UNK func_ov003_021f24ac(s32, s32);
    func_ov003_021f24ac(arg0 + 4, arg0 + 0xE);
}

void func_ov003_021f2860(s32 arg0) {
    M2C_UNK func_ov003_021f24ec(s32, s32);
    func_ov003_021f24ec(arg0 + 4, arg0 + 0xE);
}

/* Attempt to start a contextual action (overlay-dependent); returns 1 if one was started. */
s32 func_ov003_021f2a9c(s32 entry) {
    s32 func_020846a4(void);
    s32 func_0208b5a8(void);
    s32 func_02084644(void);
    s32 func_ov009_022241b4(void);
    void func_ov009_02225fb4(s32, s32, s32, void *);
    s32 func_ov010_02228314(s32 *, s32 *);
    void func_ov010_0222a808(s32, s32, s32, s32, s32, void *);
    void func_ov010_02228320(void);
    void func_ov010_022282d4(s32);
    s32 result, spare;

    if (!func_020846a4()) {
        return 0;
    }
    if (!M2C_FIELD(entry, u8 *, 0x45)) {
        return 0;
    }
    if (func_0208b5a8()) {
        return 0;
    }
    switch (func_02084644()) {
    case 1:
        func_ov009_02225fb4(0, 0x6e0, func_ov009_022241b4(), (void *)entry);
        break;
    case 2:
        func_ov010_0222a808(0, 0x6e0, func_ov010_02228314(&result, &spare), result, spare, (void *)entry);
        func_ov010_02228320();
        switch (spare) {
        case 0:
        case 1:
        case 2:
            func_ov010_022282d4(6);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        }
        break;
    }
    return 1;
}

s32 func_ov003_021f2b88(s32 a) {
    s32 func_020846a4(void);
    s32 func_0208b5a8(void);
    s32 func_0208b564(s32);
    void func_020899cc(s32,s32,s32,u32);
    if(!func_020846a4()) return 0;
    if(M2C_FIELD(a,u8 *,0x45)) return 0;
    if(!M2C_FIELD(a,u8 *,0x46)) return 0;
    if(func_0208b5a8()) return 0;
    func_020899cc(func_0208b564(a),2,0xdc00,0x44000001);
    return 1;
}

void func_ov003_021f34d8(void) {
    M2C_UNK func_ov003_021f2bf0();
    func_ov003_021f2bf0();
}

void func_ov003_021f34e4(void *a) {
    s32 func_020846a4(void);
    void func_020bfbc0(s32);
    void func_020d47d0(void);
    void func_020d47f0(void);
    s32 func_ov003_021f1bfc(void);
    void func_ov006_02217214(void *);
    u8 mode=M2C_FIELD(M2C_FIELD(a,void **,0x40),u8 *,4);
    s32 test;
    switch(mode) {
    case 1: case 3: case 5: test=1; break;
    default: test=0; break;
    }
    if(test) func_020bfbc0(0);
    if(func_ov003_021f1bfc()==1) {
        func_020d47d0();
        if(!func_020846a4()) return;
        mode=M2C_FIELD(M2C_FIELD(a,void **,0x40),u8 *,4);
        if(mode!=1 && mode!=5) return;
        func_ov006_02217214(a);
    } else func_020d47f0();
}

void func_ov003_021f3564(M2C_UNK arg0) {
    M2C_UNK func_01ffa8c4(M2C_UNK, M2C_UNK);
    M2C_UNK func_ov003_021f17e0();
    M2C_UNK func_ov003_021f2878();
    s32 func_ov003_021f2a9c(M2C_UNK);
    s32 func_ov003_021f2b88(M2C_UNK);
    func_ov003_021f2878();
    if ((func_ov003_021f2a9c(arg0) == 0) && (func_ov003_021f2b88(arg0) == 0)) {
        return;
    }
    func_ov003_021f17e0();
    func_01ffa8c4(arg0, 5);
}

void func_ov003_021f35a4(void) {
    M2C_UNK func_ov003_021f2e98();
    func_ov003_021f2e98();
}

