/* 14 functions from 0x0201DB20 to 0x0201E944 (main), found by ds-decomp. */
#include "common.h"
static inline u32 NextPacketRandom(void) {
 extern M2C_UNK data_02137290;
 M2C_FIELD(&data_02137290,u64*,0x68)=M2C_FIELD(&data_02137290,u64*,0x70)*M2C_FIELD(&data_02137290,u64*,0x68)+M2C_FIELD(&data_02137290,u64*,0x78);
 return M2C_FIELD(&data_02137290,u64*,0x68)>>32;
}
static inline u16 PacketSwap(u16 x) { return (x>>8)|(x<<8); }
static inline void PacketPut32(u8 *p,u32 x) { *(u16*)p=PacketSwap(x>>16); *(u16*)(p+2)=PacketSwap(x); }
static inline void PacketAddress(u8 *p) { extern M2C_UNK data_02137778; void func_02008048(s32,u8*,s32); func_02008048((s32)&data_02137778,p,6); }

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

#pragma opt_common_subs off
u8 *func_0201e078(u8 *p,s32 kind,s32 out) {
extern M2C_UNK data_02137290; extern M2C_UNK data_02137778; extern M2C_UNK data_020faf8c;
M2C_UNK func_02007f8c(s32,M2C_UNK,s32); void func_02008048(s32,u8*,s32);
u32 value; u16 hi,lo;
func_02007f8c((s32)p,0,236); *(u16*)p=0x101;p[2]=6;
value=NextPacketRandom();if(out)*(u32*)out=value;
*(u16*)(p+4)=PacketSwap(value>>16);*(u16*)(p+6)=PacketSwap(value);
*(u16*)(p+12)=PacketSwap(M2C_FIELD(&data_02137290,u32*,0x50)>>16);
*(u16*)(p+14)=PacketSwap(M2C_FIELD(&data_02137290,u32*,0x50));
func_02008048((s32)&data_02137778,p+0x1c,6);
*(u16*)(p+0xec)=0x8263;*(u16*)(p+0xee)=0x6353;*(u16*)(p+0xf0)=0x135;
p[0xf2]=kind;p[0xf3]=0x3d;p[0xf4]=7;p[0xf5]=1;
func_02008048((s32)&data_02137778,p+0xf6,6);
p[0xfc]=12;p[0xfd]=10;func_02008048((s32)&data_020faf8c,p+0xfe,10);
p[0x108]=0x37;p[0x109]=3;p[0x10a]=1;p[0x10b]=3;p[0x10c]=6;return p+0x10d;
}
#pragma opt_common_subs reset
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
u8 *p;u16 hi,lo;s32 result;s32 base=(s32)data_021377e6;
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
*p++=255;
p=(u8 *)func_0201e204(0,300,(s32)p,(s32)p-base);
func_0201db20(base,(s32)p-base);return result;
}

s32 func_0201e404(s32 arg0, s32 arg1) {
    u64 func_02007004(void);
    s32 func_0201dbb8(void);
    void func_0201a238(void);
    s32 func_0201d618(s32 *);
    s32 func_0201a7f8(u16 *, u16 *);
    void func_0201d70c(s32);
    extern M2C_UNK data_02137290;
    extern M2C_UNK data_02137778;

    s32 slots[2];
    u32 timer;
    s32 result;
    u32 limit;
    s32 *lenp;
    s32 len;
    u8 *q;
    u8 *cur;
    u8 *endb;
    u8 tag;
    u32 combo;
    u32 now;
    u8 flen;
    u16 t0, t1;

    slots[0] = arg0;
    lenp = &slots[1];
    limit = (arg1 + 1) * 15;
    timer = (u32)(func_02007004() >> 16);
    result = 0;
    goto timer_check;

top_loop:
    if (func_0201dbb8() == 0) {
        func_0201a238();
    } else {
        q = (u8 *)func_0201d618(lenp);
        len = slots[1];
        if (q == 0) goto fail;
        if ((u32)len <= 0xF0) goto fail;
        if (q[0] != 2) goto fail;
        t0 = *(u16 *)(q + 4);
        t1 = *(u16 *)(q + 6);
        if (((((u32)PacketSwap(t0)) << 16) | (u32)PacketSwap(t1)) != (u32)slots[0]) goto fail;
        if (func_0201a7f8((u16 *)&data_02137778, (u16 *)(q + 0x1C)) != 0) goto fail;
        if (q[0xEC] != 0x63 || q[0xED] != 0x82 || q[0xEE] != 0x53 || q[0xEF] != 0x63) goto fail;

        combo = ((u32)q[0x10] << 24) | ((u32)q[0x11] << 16) | ((u32)q[0x12] << 8) | (u32)q[0x13];
        result = 3;
        cur = q + 0xF0;
        endb = q + len;

        if (cur >= endb) goto fail;
        tag = *cur++;

        while (1) {
            switch (tag) {
            case 0x01:
                M2C_FIELD(&data_02137290, u32 *, 0x1C) =
                    ((u32)cur[1] << 24) | ((u32)cur[2] << 16) | ((u32)cur[3] << 8) | (u32)cur[4];
                break;
            case 0x03:
                M2C_FIELD(&data_02137290, u32 *, 0x2C) =
                    ((u32)cur[1] << 24) | ((u32)cur[2] << 16) | ((u32)cur[3] << 8) | (u32)cur[4];
                break;
            case 0x06:
                if (cur[0] < 8) {
                    M2C_FIELD(&data_02137290, u32 *, 0x64) = 0;
                } else {
                    M2C_FIELD(&data_02137290, u32 *, 0x64) =
                        ((u32)cur[5] << 24) | ((u32)cur[6] << 16) | ((u32)cur[7] << 8) | (u32)cur[8];
                }
                M2C_FIELD(&data_02137290, u32 *, 0x60) =
                    ((u32)cur[1] << 24) | ((u32)cur[2] << 16) | ((u32)cur[3] << 8) | (u32)cur[4];
                break;
            case 0x33:
                if (cur[0] == 0x02) {
                    result = 1;
                    M2C_FIELD(&data_02137290, u32 *, 0x34) = combo;
                } else if (cur[0] == 0x05) {
                    result = 2;
                    M2C_FIELD(&data_02137290, u32 *, 0x50) = combo;
                }
                break;
            case 0x35:
                M2C_FIELD(&data_02137290, u32 *, 0x20) =
                    ((u32)cur[1] << 24) | ((u32)cur[2] << 16) | ((u32)cur[3] << 8) | (u32)cur[4];
                break;
            default:
                break;
            }

            flen = cur[0];
            cur += flen + 1;
            if (cur >= endb) goto fail;
            tag = *cur++;

            if (tag == 0xFF) {
                func_0201d70c(slots[1]);
                if (M2C_FIELD(&data_02137290, s32 (**)(void), 0x48)() == 0) goto final;
                if (result != 0) goto final;
                goto timer_check;
            }
        }
    }

fail:
    result = 0;

timer_check:
    now = (u32)(func_02007004() >> 16);
    if ((u32)(now - timer) < limit) goto top_loop;

final:
    return result;
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

