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

s32 func_ov003_021f2878(s32 entry) {
    s32 func_020846a4(void);
    s32 func_0208471c(void);
    s32 func_02084644(void);
    void func_ov009_022244ec(M2C_UNK);
    s32 func_ov009_02224508(M2C_UNK);
    s32 func_ov010_022282b4(M2C_UNK);
    void func_ov010_02228298(M2C_UNK);
    M2C_UNK func_ov010_02228314(M2C_UNK *, M2C_UNK *);
    s32 func_02084a6c(void);
    s32 func_02084a0c(void);
    s32 func_ov003_021f17fc(void);
    M2C_UNK func_ov003_021f14c8(void);
    s32 var_sp4;
    s32 var_sp0;

    if (M2C_FIELD(entry, u8 *, 0x47) != 0) {
        goto tail;
    }
    if (func_020846a4() == 0) {
        return 0;
    }
    if (M2C_FIELD(entry, u8 *, 0x34) != 2) {
        return 0;
    }
    {
        void *p = *(void **)(entry + 0x40);
        s8 idx = *(s8 *)((u8 *)p + 5);
        u8 *arr = *(u8 **)((u8 *)p + 8);
        s32 t = arr[idx] - 8;
        switch (t) {
        case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            return 1;
        default:
            break;
        }
    }
    {
        s32 t = func_ov003_021f17fc();
        if (t != 0) {
            return t;
        }
    }
    {
        u8 r0 = M2C_FIELD(entry, u8 *, 0x45);
        if (r0 == 0) {
            r0 = M2C_FIELD(entry, u8 *, 0x46);
        }
        if (r0 != 0) {
            return r0;
        }
    }
    if (func_0208471c() != 0) {
        s32 sw = func_02084644();
        if (sw == 1) {
            if (func_ov009_02224508(1) == 0) {
                func_ov009_022244ec(1);
                M2C_FIELD(entry, u8 *, 0x45) = 1;
            }
        } else if (sw == 2) {
            if (func_ov010_022282b4(6) == 0) {
                func_ov010_02228298(6);
                func_ov010_02228314(&var_sp4, &var_sp0);
                switch (var_sp0) {
                case 1: case 2: case 3: case 4: case 5: case 6: case 7:
                    func_ov010_02228298(6);
                    M2C_FIELD(entry, u8 *, 0x45) = 1;
                    break;
                default:
                    break;
                }
            }
        }
    }

tail:
    for (;;) {
        if (M2C_FIELD(entry, u8 *, 0x47) != 0) {
            M2C_FIELD(entry, u8 *, 0x47) = 0;
            return 0;
        }
        if (func_02084a6c() == 0) {
            break;
        }
    }
    {
        s32 a = func_02084a0c();
        if (a > 1) {
            return a;
        }
    }
    {
        s32 r = func_ov003_021f14c8();
        if (r != 0) {
            M2C_FIELD(entry, u8 *, 0x46) = 1;
        } else {
            void *p = *(void **)(entry + 0x40);
            s8 idx = *(s8 *)((u8 *)p + 5);
            u8 *arr = *(u8 **)((u8 *)p + 8);
            s32 terrain = arr[idx];
            s32 flag = 0;
            if (terrain == 6) {
                flag = 1;
            } else if (terrain > 6) {
                s32 d = terrain - 18;
                if (d >= 0 && d <= 3) {
                    flag = 1;
                }
            }
            if (flag == 0) {
                M2C_FIELD(entry, u8 *, 0x46) = 1;
            }
        }
    }
    return 1;
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

M2C_UNK func_ov003_021f2bf0(M2C_UNK arg0) {
    M2C_UNK func_01ff9e00(void);
    void func_02082c84(void);
    void func_02082cb4(void);
    void func_02003560(void);
    void func_02002bb8(s32);
    void func_020035bc(void);
    void func_02002ab8(s32);
    void func_ov003_021f1ab8(s32);
    void func_ov003_021f1af8(s32);
    s32 func_020d4810(void);
    void func_ov003_021f1bd4(void);
    void func_ov003_021f1be8(void);
    void func_ov003_021f192c(void *);
    void func_ov003_021f18b4(void *);
    void func_02084a40(void);
    s32 func_020846a4(void);
    void func_020852a8(void);
    void func_ov003_021f1884(s32);
    M2C_UNK func_ov003_021f2e98(M2C_UNK);
    extern void *gCur3DSpriteEngine, *data_027e00c4, *data_027e00c8;
    extern M2C_UNK data_ov003_0220fcb4;
    extern M2C_UNK data_ov003_0220fca8;

    s32 var_r9;
    u16 **temp_r11;
    u16 **var_r0;
    u16 *sp18, *sp14, *sp10, *spC, *sp8, *sp4;
    u16 *temp_r0, *temp_r0_2, *temp_r0_3, *temp_r0_4, *temp_r0_5, *temp_r0_6;
    void *saved;
    void *obj;

    func_01ff9e00();
    func_02082c84();
    func_02082cb4();
    func_02003560();
    func_02002bb8(0x40);
    func_020035bc();
    func_02002ab8(0x20);
    func_ov003_021f1ab8((s32)&data_ov003_0220fcb4);
    func_ov003_021f1af8((s32)&data_ov003_0220fca8);

    var_r9 = 0;
    temp_r11 = (u16 **)gCur3DSpriteEngine;
    do {
        if (var_r9 == 0) {
            var_r0 = (u16 **)data_027e00c8;
        } else {
            var_r0 = (u16 **)data_027e00c4;
        }
        gCur3DSpriteEngine = (void *)var_r0;
        temp_r0 = *var_r0;
        sp18 = temp_r0;
        *temp_r0 = *sp18 | 0x10;
        temp_r0_2 = *(u16 **)gCur3DSpriteEngine;
        sp14 = temp_r0_2;
        *temp_r0_2 = *sp14 | 0x20;
        temp_r0_3 = *(u16 **)gCur3DSpriteEngine;
        sp10 = temp_r0_3;
        *temp_r0_3 = *sp10 | 0x40;
        temp_r0_4 = *(u16 **)gCur3DSpriteEngine;
        spC = temp_r0_4;
        *temp_r0_4 = *spC | 0x80;
        temp_r0_5 = *(u16 **)gCur3DSpriteEngine;
        sp8 = temp_r0_5;
        *temp_r0_5 = *sp8 | 0x100;
        temp_r0_6 = *(u16 **)gCur3DSpriteEngine;
        sp4 = temp_r0_6 + 0x12;
        M2C_FIELD(temp_r0_6, s16 *, 0x12) = (s16)(*sp4 & ~0xC0);
        M2C_FIELD(*(u16 **)gCur3DSpriteEngine, s8 *, 0x51) = (s8)var_r9;
        M2C_FIELD(*(u16 **)gCur3DSpriteEngine, s8 *, 0x52) = (s8)var_r9;
        M2C_FIELD(*(u16 **)gCur3DSpriteEngine, s8 *, 0x53) = (s8)var_r9;
        var_r9 += 1;
    } while (var_r9 < 2);
    gCur3DSpriteEngine = temp_r11;

    if (func_020d4810() != 0) {
        func_ov003_021f1bd4();
    } else {
        func_ov003_021f1be8();
    }

    obj = *(void **)((u8 *)arg0 + 0x3C);
    *(u8 *)((u8 *)obj + 1) = 1;
    {
        u8 idx = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x40) + 4);
        if (idx == 10 || idx == 11 || idx == 12) {
            *(u8 *)((u8 *)obj + 1) = 0;
            *(s32 *)((u8 *)obj + 4) = 0x780;
            *(u8 *)((u8 *)obj + 8) = 0x1F;
            func_ov003_021f192c(obj);
        }
    }
    {
        void *p2 = *(void **)((u8 *)arg0 + 0x38);
        *(u8 *)((u8 *)p2 + 0) = 1;
        *(u8 *)((u8 *)p2 + 1) = 2;
        *(u8 *)((u8 *)p2 + 2) = 0x0F;
        *(u8 *)((u8 *)p2 + 3) = 1;
        *(u8 *)((u8 *)p2 + 4) = 2;
        *(u8 *)((u8 *)p2 + 5) = 0x0F;
        func_ov003_021f18b4(p2);
    }
    func_02084a40();
    if (func_020846a4() != 0) {
        func_020852a8();
    }
    func_ov003_021f1884(0x6E0);
    func_ov003_021f2e98(arg0);
    *(u8 *)((u8 *)arg0 + 0x34) = 3;
    return 0;
}

s32 func_ov003_021f2e98(s32 arg0) { (void)arg0; return 0; }

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

