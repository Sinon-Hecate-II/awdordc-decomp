/* 14 functions from 0x0201DB20 to 0x0201E944 (main), found by ds-decomp. */
#include "common.h"

u32 func_0201db20(s32 a, s32 b) {
    extern M2C_UNK data_0212dca4;
    M2C_UNK func_020651c4(s32, s32, u32);
    void *p;
    u32 n, used;
    p = M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), void **, 0xA4);
    if (p) {
        n = M2C_FIELD(p, u32 *, 0x60);
        if (n) {
            used = func_0201da4c(M2C_FIELD(p, s32 *, 0x5C), n, a, b);
            n = M2C_FIELD(p, u32 *, 0x60);
            if (used < n) {
                func_020651c4(M2C_FIELD(p, s32 *, 0x5C), M2C_FIELD(p, s32 *, 0x5C) + used, n - used);
                M2C_FIELD(p, u32 *, 0x60) -= used;
                return 0;
            }
            M2C_FIELD(p, u32 *, 0x60) = 0;
            return used - n;
        }
        return func_0201da4c(a, b, 0, 0);
    }
    return 0;
}

s32 func_0201dbb8(void) {
    extern M2C_UNK data_0212dca4;
    s32 func_02024f20(void *);
    void *p;
    s32 n;
    p = M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), void **, 0xA4);
    if (p) {
        if (M2C_FIELD(p, u8 *, 9)) return func_02024f20(p);
        n = M2C_FIELD(p, s32 *, 0x44);
        if (n != 0) goto done;
        {
            u8 c = M2C_FIELD(p, u8 *, 8);
            if (c == 4) goto done;
            if ((u8)(c + 246) > 1) goto fail;
        }
    done:
        return n;
    fail:
        return -1;
    }
    return 0;
}

void func_0201dc28(void) {
    M2C_UNK func_0201da4c(s32, s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0212dca4;
    s32 temp_r1;
    void *temp_r4;

    temp_r4 = M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), void **, 0xA4);
    if (temp_r4 != NULL) {
        temp_r1 = M2C_FIELD(temp_r4, s32 *, 0x60);
        if (temp_r1 != 0) {
            func_0201da4c(M2C_FIELD(temp_r4, s32 *, 0x5C), temp_r1, 0, 0);
            M2C_FIELD(temp_r4, s32 *, 0x60) = 0;
        }
    }
}

void func_0201dc68(void) {
    extern M2C_UNK data_02137290;
    void func_0201aca0(s32);
    void func_02006030(s32);
    u64 func_02007004(void);
    void func_0201a134(s32);
    s32 start;
    M2C_FIELD(&data_02137290, void (**)(void), 0x18)();
    if (!M2C_FIELD(&data_02137290, s32 *, 0x50)) return;
    func_0201aca0(M2C_FIELD(&data_02137290, s32 *, 0x50));
    func_02006030(100);
    func_0201aca0(M2C_FIELD(&data_02137290, s32 *, 0x50));
    start = (u32)(func_02007004() >> 16);
    goto check;
    loop:
    {
        if (M2C_FIELD(&data_02137290, u8 *, 1)) {
            func_0201a134(4);
            return;
        }
        func_02006030(100);
    }
    check:
    if (!M2C_FIELD(&data_02137290, s32 (**)(void), 0x48)()) return;
    if ((s32)((u32)(func_02007004() >> 16) - start) < 23) goto loop;
}

void func_0201dd08(void) {
    extern M2C_UNK data_02137290;
    extern M2C_UNK data_0212dca4;
    extern M2C_UNK data_02137370;
    extern M2C_UNK data_021375b8;
    extern M2C_UNK data_0213793c;
    extern M2C_UNK data_021377bc;
    M2C_UNK func_02007f8c(s32, M2C_UNK, s32);
    u64 func_02007004(void);
    void func_02006030(s32);
    void func_0201dc68(void);
    s32 func_0201e754(void);
    s32 func_0201e7ac(u32 *, s32);
    void func_0201a134(s32);
    void func_0201d138(s32);
    void func_0201d14c(void);

    s32 r4;
    s32 r10;
    s32 r11;
    u32 sp0;
    u32 tick;
    s32 i;

    r4 = 0;
    r10 = 1;
    r11 = 1;
    sp0 = 1;

    M2C_FIELD(&data_02137290, u32 *, 0x44) = 0;
    func_02007f8c((s32)&data_02137370, 0, 0x64);
    func_0201d138((s32)&data_02137370);
    M2C_FIELD(&data_02137290, s32 *, 0x11c) = 0x180;
    M2C_FIELD(&data_02137290, void **, 0x120) = &data_0213793c;
    M2C_FIELD(&data_02137290, s32 *, 0x128) = 0x180;
    M2C_FIELD(&data_02137290, void **, 0x12c) = &data_021377bc;
    M2C_FIELD(&data_02137290, s32 *, 0xc) = 1;
    func_02006030(0x3e8);

mainloop:
    if (M2C_FIELD(&data_02137290, u32 *, 0x44) != 0) goto epilogue;
    tick = (u32)(func_02007004() >> 16);
    if (M2C_FIELD(&data_02137290, s32 (**)(void), 0x48)() != 0) {
        sp0--;
        if (sp0 == 0) {
            if (M2C_FIELD(&data_02137290, u32 *, 0x10) & 1) {
                if (r4 == 0) { func_0201dc68(); r4 = 1; }
            } else {
                switch (r4) {
                case 0:
                    if (r11) {
                        M2C_FIELD(&data_02137290, s32 *, 0xc) = 2;
                        r11 = 0;
                    }
                    if (func_0201e754()) {
                        if (func_0201e7ac(&sp0, 0)) r4 = 1;
                        else { func_0201dc68(); r4 = 3; }
                    } else {
                        if (func_0201e7ac(&sp0, 1)) {
                        } else if (sp0 < 0x3c) {
                            r4 = 2;
                        }
                    }
                    break;
                case 1:
                case 2:
                case 3:
                    break;
                }
            }
        }
    }
    goto mainloop;

epilogue:
    func_0201d14c();
}

u8 *func_0201e078(u8 *arg0, s32 arg1, s32 arg2) {
    extern M2C_UNK data_02137290;
    extern M2C_UNK data_02137778;
    M2C_UNK func_02007f8c(s32, M2C_UNK, s32);
    void func_02008048(s32, u8 *, s32);
    u32 temp;
    u64 val;
    u8 *p = arg0;

    func_02007f8c((s32)arg0, 0, 236);
    *(u16 *)arg0 = 0x101;
    arg0[2] = 6;
    val = *(u64 *)((char *)&data_02137290 + 0x68);
    *(u16 *)(arg0 + 4) = (u16)(val >> 8);
    *(u16 *)(arg0 + 6) = (u16)(val >> 8);
    return arg0;
}

s32 func_0201e204(M2C_UNK arg0, u32 arg1, s32 arg2, u32 arg3) {
    M2C_UNK func_02007f8c(s32, M2C_UNK, s32);
    s32 temp_r4;
    s32 var_r5;

    var_r5 = arg2;
    if (arg3 < arg1) {
        temp_r4 = arg1 - arg3;
        func_02007f8c(var_r5, arg0, temp_r4);
        var_r5 += temp_r4;
    }
    return var_r5;
}

s32 func_0201e238(void) {
extern M2C_UNK data_02137290; extern u8 data_021377e6[];
u8 *func_0201e078(u8 *,s32,s32);
volatile u8 *p; u16 hi,lo; s32 result; s32 base=(s32)data_021377e6;
p=func_0201e078((u8 *)base,1,(s32)&result);
if(M2C_FIELD(&data_02137290,u32 *,0x34)) {
p[0]=0x32; p[1]=4;
hi=M2C_FIELD(&data_02137290,u32 *,0x34)>>16; p[2]=hi>>8;
p[3]=M2C_FIELD(&data_02137290,u32 *,0x34)>>16;
p[4]=(u16)M2C_FIELD(&data_02137290,u32 *,0x34)>>8;
p[5]=M2C_FIELD(&data_02137290,u32 *,0x34);
p+=6;
}
*p++=255;
p=(u8 *)func_0201e204(0,300,(s32)p,(s32)p-base);
func_0201db20(base,(s32)p-base);
return result;
}

s32 func_0201e2fc(s32 a){
extern M2C_UNK data_02137290;extern u8 data_021377e6[];
u8 *func_0201e078(u8 *,s32,s32);
u8 *p;u16 hi,lo;u8 *next;s32 result;s32 base=(s32)data_021377e6;
p=func_0201e078((u8 *)base,3,(s32)&result);
if(a==0){
p[0]=0x32;p[1]=4;
hi=M2C_FIELD(&data_02137290,u32 *,0x34)>>16;p[2]=hi>>8;
p[3]=M2C_FIELD(&data_02137290,u32 *,0x34)>>16;
p[4]=(u16)M2C_FIELD(&data_02137290,u32 *,0x34)>>8;
p[5]=M2C_FIELD(&data_02137290,u32 *,0x34);
p[6]=0x36;p[7]=4;
hi=M2C_FIELD(&data_02137290,u32 *,0x20)>>16;p[8]=hi>>8;
p[9]=M2C_FIELD(&data_02137290,u32 *,0x20)>>16;
p[10]=(u16)M2C_FIELD(&data_02137290,u32 *,0x20)>>8;
p[11]=M2C_FIELD(&data_02137290,u32 *,0x20);
p+=12;
}
next=p+1;*p=255;p=next;
p=(u8 *)func_0201e204(0,300,(s32)p,(s32)p-base);
func_0201db20(base,(s32)p-base);return result;
}

s32 func_0201e404(s32 arg0, s32 arg1) {
    (void)arg0; (void)arg1;
    return 0;
}

s32 func_0201e754(void) {
    M2C_UNK func_0201d164();
    M2C_UNK func_0201d190(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_0201d1f0();
    M2C_UNK func_0201d224();
    s32 func_0201e238();
    s32 func_0201e404(s32, s32);
    s32 temp_r0;
    s32 var_r5;

    func_0201d1f0();
    func_0201d164();
    func_0201d190(0x44, 0x43, -1);
    var_r5 = 0;
loop_1:
    temp_r0 = func_0201e404(func_0201e238(), var_r5);
    if (temp_r0 != 1) {
        var_r5 += 1;
        if (var_r5 < 4) {
            goto loop_1;
        }
    }
    func_0201d224();
    if (temp_r0 == 1) {
        return 1;
    }
    return 0;
}

/* Attempt up to four times to exchange a data packet with a peer.
 * On a peer-data match (result 2) record the peer's size info and return
 * success; otherwise halve the stored timeout and apply a mode-specific floor. */
s32 func_0201e7ac(u32 *out_size, s32 mode) {
    s32 func_0201e2fc(s32);
    extern M2C_UNK data_02137290;
    s32 result;
    s32 attempt;
    u32 timeout;

    func_0201d1f0();
    func_0201d164();
    if (mode == 1) {
        func_0201d190(0x44, 0x43, M2C_FIELD(&data_02137290, s32 *, 0x20));
    } else {
        func_0201d190(0x44, 0x43, -1);
    }
    attempt = 0;
loop_4:
    result = func_0201e404(func_0201e2fc(mode), attempt);
    if (result == 0) {
        attempt += 1;
        if (attempt < 4) {
            goto loop_4;
        }
    }
    func_0201d224();
    if (result == 2) {
        *out_size = (u32) M2C_FIELD(&data_02137290, u32 *, 0x4C) >> 1;
        M2C_FIELD(&data_02137290, u32 *, 0x38) = (u32) ((u32) (M2C_FIELD(&data_02137290, u32 *, 0x4C) * 3) >> 3);
        return 1;
    }
    timeout = (u32) M2C_FIELD(&data_02137290, u32 *, 0x38) >> 1;
    M2C_FIELD(&data_02137290, u32 *, 0x38) = timeout;
    *out_size = timeout;
    switch (mode) {                                 /* irregular */
    case 1:
        if (timeout < 0x3CU) {
            *out_size = 1;
            M2C_FIELD(&data_02137290, u32 *, 0x38) = (u32) ((u32) M2C_FIELD(&data_02137290, u32 *, 0x4C) >> 3);
        }
        break;
    case 2:
        if (timeout < 0x3CU) {
            *out_size = 1;
        }
        break;
    }
    return 0;
}

void func_0201e8a8(void) {
 extern M2C_UNK data_02137290;
 extern u8 data_021377e6[];
 u8 *func_0201e078(u8 *,s32,s32);
 s32 p; s32 base;
 func_0201d1f0();
 func_0201d164();
 func_0201d190(0x44,0x43,M2C_FIELD(&data_02137290,s32 *,0x20));
 base=(s32)data_021377e6;
 p=(s32)func_0201e078((u8 *)base,7,0);
 M2C_FIELD(p,u8 *,0)=0xff; p++;
 p=func_0201e204(0,300,(s32)p,p-base);
 func_0201db20((s32)base,p-base);
 func_0201d224();
}

u8 *func_0201e914(u8 *p) {
    u32 c = *p++;
    while (c) {
        if ((c & 0xC0) == 0xC0) return p + 1;
        p += c;
        c = *p++;
    }
    return p;
}

