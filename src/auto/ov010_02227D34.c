/* 47 functions from 0x02227D34 to 0x02228D1C (ov010), found by ds-decomp. */
#include "common.h"

void func_ov010_02227d34(s32 arg0, void *arg1, char *arg2, s32 arg3) {
    void func_ov010_0222697c(void *);
    s32 func_02068c34(char *);
    s32 func_0203a9d0(char *, s32, void *, s32);
    void *func_020c4b60(void);
    void func_02007e20(void *, void *, s32);
    extern M2C_UNK data_ov010_0222eee0;
    char buf[0x6c];
    s32 r;
    void *p;
    s32 off;
    char *dst;
    void (*cb)(s32, void *, char *, s32);

    if (arg2 != 0 && *arg2 != 0) {
        func_ov010_0222697c(buf);
        r = func_02068c34(arg2);
        if (func_0203a9d0(arg2, r, buf, 0x6c) == 0x6c) {
            p = func_020c4b60();
            off = arg0 * 0x28;
            func_02007e20(buf, (char *)p + 0x2d4 + off, 0x18);
            dst = (char *)p + off;
            dst[0x2f4] = (signed char)buf[0x24];
            dst[0x2f5] = (signed char)buf[0x25];
            dst[0x2f6] = (signed char)buf[0x26];
        }
    }

    cb = *(void (**)(s32, void *, char *, s32))((char *)&data_ov010_0222eee0 + 4);
    if (cb != 0) {
        cb(arg0, arg1, arg2, arg3);
    }
}

void func_ov010_02227df8(void) {
    void func_ov010_02228298(M2C_UNK);
    s32 func_ov010_022282f8();
    s32 var_r0;

    if (func_ov010_022282f8() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        return;
    }
    func_ov010_02228298(2);
}

void func_ov010_02227e20(s32 arg0, s32 arg1) {
    s32 func_ov010_022282f8(void);
    s32 func_0203a850(void *, s32);
    s32 func_02044618(s32);
    s32 func_02044638(s32);
    s32 func_02038d14(s32, s32);
    s32 func_0203a9a4(s32, s32);
    s32 func_02038790(s32, s32, s32, s32, s32, s32, s32);
    s32 func_02037c90(void);
    void func_ov010_02227934(void);
    void func_ov010_02227954(void);
    void func_ov010_02227bd4(void);
    void func_ov010_02227c3c(void);
    void func_ov010_02227c5c(void);
    void func_ov010_02227df8(void);
    void func_ov010_02227d34(s32, void *, char *, s32);
    extern M2C_UNK data_ov010_0222eee0;
    extern M2C_UNK data_ov010_0222efc0;

    s32 var_r0;
 u32 flags;

    if (func_ov010_022282f8() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        return;
    }

    flags = M2C_FIELD(&data_ov010_0222eee0, u8 *, 0xfa);
 M2C_FIELD(&data_ov010_0222eee0, u8 *, 0xfa) = flags | 1;
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0xfc) = arg1;
    func_0203a850(&data_ov010_0222efc0, 0x6c);

    func_02044618((s32)func_ov010_02227934);
    func_02044638((s32)func_ov010_02227954);
    func_02038d14((s32)func_ov010_02227bd4, 0);
    func_0203a9a4((s32)func_ov010_02227c3c, 0);

    func_02038790(0, (s32)func_ov010_02227df8, 0, (s32)func_ov010_02227d34, 0,
                   (s32)func_ov010_02227c5c, 0);

    if (func_02037c90() != 2) {
        return;
    }

    if (M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x40) == 0) {
        return;
    }

    {
        s32 res = func_02037c90();
        void (*cb)(s32) = M2C_FIELD(&data_ov010_0222eee0, void (**)(s32), 0x40);
        cb(res);
    }
}

void func_ov010_02227f14(void) {
 s32 func_02038eb0(u8 **); s32 func_ov010_02229a08(void); void func_020445cc(u32,void *,s32); extern M2C_UNK data_ov010_0222eee0;
 u8 *list; s32 n=func_02038eb0(&list); s32 i; u32 id; u32 index;
 for(i=0;i<n;i++){id=list[i];if(id!=func_ov010_02229a08()){if(id<(u32)func_ov010_02229a08())index=id;else index=id-1;func_020445cc(id,M2C_FIELD(&data_ov010_0222eee0,u8 **,0x3c)+index*0x5a0,0x5a0);}}
}

void func_ov010_02227f88(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_02008048(M2C_UNK, s32);
    extern M2C_UNK data_ov010_0222f02c;
    func_02008048(arg1, (arg0 * 0x6C) + (s32) &data_ov010_0222f02c);
}

void func_ov010_02227fac(s32 arg0,s32 arg1,s32 arg2) {
s32 func_ov010_022282f8(void); void func_ov010_02228298(s32); M2C_UNK func_ov010_022282d4(M2C_UNK); s32 func_ov010_02229a08(void); s32 func_0203a850(void *,s32); void func_ov010_02227f14(void); s32 func_ov010_02229a94(void); extern M2C_UNK data_ov010_0222eee0; extern M2C_UNK data_ov010_0222efc0;
s32 t; void (*cb)(s32,s32,s32);
t=func_ov010_022282f8();t=(t!=0);
if(t==0) {if(arg1==0) {func_ov010_02228298(3);M2C_FIELD(&data_ov010_0222eee0,u8 *,0xfb)=func_ov010_02229a08();func_0203a850(&data_ov010_0222efc0,0x6c);func_ov010_02227f14();func_ov010_02229a94();}else{func_ov010_02228298(4);}}else{func_ov010_02228298(4);func_ov010_022282d4(3);}
cb=M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,s32,s32),12);if(cb==0)return;cb(arg0,arg1,arg2);
}

s32 func_ov010_02228050(s32 a,s32 b) { extern M2C_UNK data_ov010_0222eee0; s32 result=1; s32 (*fp)(s32,s32)=M2C_FIELD(&data_ov010_0222eee0,s32 (**)(s32,s32),0x20); if(fp) result+=fp(a,b); return result; }

void func_ov010_0222807c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_ov010_022282f8(void);
    void func_ov010_02228298(s32);
    M2C_UNK func_ov010_022282d4(M2C_UNK);
    s32 func_ov010_02229a08(void);
    s32 func_0203a850(void *, s32);
    void func_ov010_02227f14(void);
    s32 func_ov010_02229a94(void);
    extern M2C_UNK data_ov010_0222eee0;
    extern M2C_UNK data_ov010_0222efc0;

    s32 t;

    t = func_ov010_022282f8();
    t = (t != 0);

    if (t == 0) {
        if (arg1 == 0) {
            func_ov010_02228298(3);
            M2C_FIELD(&data_ov010_0222eee0, u8 *, 0xfb) =
                (u8)func_ov010_02229a08();
            func_0203a850(&data_ov010_0222efc0, 0x6c);
            func_ov010_02227f14();
            func_ov010_02229a94();
            goto callback_call;
        }

        if (arg2 == 0 && arg3 == 0) {
            goto callback_call;
        }

        func_ov010_02228298(4);
        func_ov010_022282d4(3);
        goto callback_call;
    }

    func_ov010_02228298(4);
    func_ov010_022282d4(3);

callback_call:
    if (M2C_FIELD(
            &data_ov010_0222eee0,
            void (* volatile *)(s32, s32, s32, s32, s32, s32),
            0x8
        ) == 0) {
        return;
    }

    M2C_FIELD(
        &data_ov010_0222eee0,
        void (* volatile *)(s32, s32, s32, s32, s32, s32),
        0x8
    )(arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_ov010_0222815c(s32 a,s32 b) {
 extern M2C_UNK data_ov010_0222eee0;
 void (*cb)(s32,s32)=M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,s32),0x44);
 if(!cb)return; cb(a,b);
}

void func_ov010_0222817c(void) {

}

s32 func_ov010_02228180(void) {
    M2C_UNK func_ov010_022282b4(M2C_UNK);
    M2C_UNK func_ov010_022268f4(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov010_02226908(M2C_UNK, s32, s32);
    s32 func_02031d00(M2C_UNK);
    void func_02037680(s32, s32);
    M2C_UNK func_020067a8(M2C_UNK, s32);
    M2C_UNK func_ov010_02226a88();
    s32 func_02044658(u16);
    M2C_UNK func_ov010_02229a50();
    void func_ov010_02228280(M2C_UNK);
    extern M2C_UNK data_ov010_0222eee0;
    M2C_UNK p;
    M2C_UNK q;
    s32 s;

    if (func_ov010_022282b4(0) != 0) {
        return 0;
    }
    p = func_ov010_022268f4(0, 0x700, 0x20);
    s = func_02031d00(p);
    func_ov010_02226908(0, p, 0x700);
    if (s != 3) {
        func_02037680((s32)func_ov010_022268f4, (s32)func_ov010_02226908);
        q = func_ov010_022268f4(0, 0x10e0, 0x20);
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x3c) = q;
        func_020067a8(q, 0x10e0);
        func_ov010_02226a88();
        func_02044658(0x5b9);
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x40) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x38) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x4c) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x2c) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x34) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x10) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x14) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x4) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x20) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0xc) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x8) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x44) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x58) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x1c) = 0;
        M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x50) = 0;
        func_ov010_02229a50();
        func_ov010_02228280(0);
    }
    return s;
}

void func_ov010_0222826c(void) {
    extern M2C_UNK data_ov010_0222eee0;
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x54) = 0;
}

void func_ov010_02228280(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x54) = 1 << arg0;
}

void func_ov010_02228298(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    M2C_FIELD(&data_ov010_0222eee0, s32 *, (unsigned)0x54) =
        (M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x54) | (1 << arg0));
}

s32 func_ov010_022282b4(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    s32 var_r2 = 1;
    if (!(M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x54) & (1 << arg0))) {
        var_r2 = 0;
    }
    return var_r2;
}

M2C_UNK func_ov010_022282d4(M2C_UNK arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    s32 v;
    v = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x54);
    v = v & (-1 ^ (1 << arg0));
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x54) = v;
    return v;
}

s32 func_ov010_022282f8(void) {
    void func_ov010_02228314();
    s32 out[2];
    func_ov010_02228314(&out[1], &out[0]);
}

void func_ov010_02228314(void) {
    M2C_UNK func_02037508();
    func_02037508();
}

void func_ov010_02228320(void) {
    M2C_UNK func_020375fc();
    func_020375fc();
}

#pragma optimize_ifs off
s32 func_ov010_0222832c(s32 arg0, s32 arg1) {
    s32 var_r0;
    s32 var_r1;

    var_r0 = arg0;
    switch(arg1) { case 0: case 1: case 2: var_r1=0; break; default: var_r1=1; break; }
    if (var_r0 < 0) {
        var_r0 = 0 - var_r0;
    }
    if ((var_r0 == 0x4E85) || ((var_r0 >= 0x59D8) && (var_r0 <= 0x5DBF))) {
        return 0x42000007;
    }
    if (var_r0 == 0x4E8C) {
        return 0x42000008;
    }
    if (var_r0 == 0x4E8E) {
        return 0x42000009;
    }
    if ((var_r0 >= 0xC800) && (var_r0 <= 0xC863)) {
        return 0x4200000A;
    }
    if ((var_r0 >= 0xC350) && (var_r0 <= 0xC3B3)) {
        return 0x4200000B;
    }
    if (var_r0 == 0xC79F) {
        return 0x4200000D;
    }
    if (((var_r0 >= 0xC738) && (var_r0 <= 0xC79B)) || ((var_r0 >= 0xC79C) && (var_r0 <= 0xC7FF)) || ((var_r0 >= 0xC864) && (var_r0 <= 0xC8C7))) {
        return 0x4200000C;
    }
    if (((var_r0 >= 0xCB20) && (var_r0 <= 0xCB23)) || ((var_r0 >= 0xCB84) && (var_r0 <= 0xCB87)) || ((var_r0 >= 0xCBE8) && (var_r0 <= 0xCBEB))) {
        return 0x4200000E;
    }
    if (var_r0 == 0x13A2E) {
        return 0x4200000F;
    }
    if (((var_r0 >= 0x4E20) && (var_r0 <= 0x5207)) || ((var_r0 >= 0xCB20) && (var_r0 <= 0xCB83)) || ((var_r0 >= 0xCB84) && (var_r0 <= 0xCBE7)) || ((var_r0 >= 0xCBE8) && (var_r0 <= 0xCC4B)) || ((var_r0 >= 0xCC4C) && (var_r0 <= 0xCCAF)) || ((var_r0 >= 0xCF08) && (var_r0 <= 0xCF6B)) || ((var_r0 >= 0xCF6C) && (var_r0 <= 0xCFCF)) || ((var_r0 >= 0xCFD0) && (var_r0 <= 0xD033))) {
        return 0x42000006;
    }
    if ((var_r1 == 0) && (var_r0 >= 0x7918) && (var_r0 <= 0x7CFF)) {
        return 0x42000011;
    }
    if (var_r1 != 0) {
        return 0x42000010;
    }
    return 0x42000012;
}
#pragma optimize_ifs reset
void func_ov010_02228614(void) {
    M2C_UNK func_0203783c(M2C_UNK *);
    M2C_UNK func_02037854(M2C_UNK);
    M2C_UNK func_020378a4();
    M2C_UNK func_ov010_02226a88();
    extern M2C_UNK data_ov010_0222ef4c;
    func_ov010_022282d4(1);
    func_ov010_02226a88();
    func_0203783c(&data_ov010_0222ef4c);
    func_02037854(2);
    func_020378a4();
}

s32 func_ov010_02228640(void) {
    s32 func_02037954();
    M2C_UNK func_02037994();
    if (func_02037954() != 0) {
        func_ov010_02228298(1);
        return 0;
    }
    func_02037994();
    return 1;
}

M2C_UNK func_ov010_0222866c(M2C_UNK arg0) {
    M2C_UNK func_02037c10(M2C_UNK);
    return func_02037c10(arg0);
}

s32 func_ov010_02228678(M2C_UNK *arg0) {
    M2C_UNK func_02037c1c(void);
    s32 var_r4;
    u32 temp_r0;
    var_r4 = 1;
    temp_r0 = func_02037c1c();
    switch (temp_r0) {
    case 0:
        var_r4 = 0;
        break;
    case 1:
        break;
    case 2:
        M2C_FIELD(arg0, s32 *, 0) = 1;
        var_r4 = 0;
        break;
    case 3:
        M2C_FIELD(arg0, s32 *, 0) = 0;
        var_r4 = 0;
        break;
    default:
        break;
    }
    return var_r4;
}

void func_ov010_022286cc(void *arg0) {
    M2C_UNK func_ov010_0222866c(M2C_UNK);
    M2C_UNK func_01ffa574(void *);
    if (func_ov010_0222866c(M2C_FIELD(arg0, s32 *, 0x34)) != 0) {
        return;
    }
    func_01ffa574(arg0);
}

void func_ov010_022286f0(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    s32 func_ov010_02228678(M2C_UNK *);
    if (func_ov010_02228678(M2C_FIELD(arg0, s32 *, 0x38)) != 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_ov010_02228714(void) {
    M2C_UNK func_02037b1c();
    func_02037b1c();
}

s32 func_ov010_02228720(void) {
    s32 temp_r0;

    temp_r0 = func_02037b1c();
    if (temp_r0 != 0) {
        func_ov010_022282d4(1);
    }
    if (temp_r0 == 0) {
        return 1;
    }
    return 0;
}

void func_ov010_02228748(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov010_0222c1b8;
    func_01ffa42c(&data_ov010_0222c1b8, arg0);
}

M2C_UNK func_ov010_02228760(M2C_UNK a, M2C_UNK b, M2C_UNK c, M2C_UNK d) {
    extern M2C_UNK data_ov010_0222c3fc;
    extern M2C_UNK data_ov010_0222f1dc;
    extern M2C_UNK data_ov010_0222c3f0;
    extern M2C_UNK data_ov010_0222eee0;
    extern M2C_UNK data_ov010_0222efc0;
    extern M2C_UNK data_ov010_0222efec;
    extern M2C_UNK data_ov010_0222c128;
    extern M2C_UNK data_ov010_0222f02c;
    extern M2C_UNK data_ov010_0222c160;
    extern M2C_UNK data_ov010_0222c3bc;
    extern M2C_UNK data_ov010_0222c330;
    extern M2C_UNK data_ov010_0222c3a8;
    M2C_UNK func_ov010_022282d4(M2C_UNK);
    void func_ov010_0222791c(M2C_UNK);
    M2C_UNK func_ov010_02226a88(void);
    void *func_020c4acc(void);
    void *func_020c4b60(void);
    M2C_UNK func_ov010_02228b20(M2C_UNK);
    M2C_UNK func_ov010_02228b38(M2C_UNK);
    M2C_UNK func_ov010_02228b68(M2C_UNK);
    M2C_UNK func_ov010_02228b80(M2C_UNK);
    M2C_UNK func_ov010_02228b98(M2C_UNK);
    M2C_UNK func_ov010_02228bb0(M2C_UNK);
    void func_ov010_02229498(M2C_UNK);
    void func_ov010_022294b0(M2C_UNK);
    void func_ov010_022294c8(M2C_UNK);
    M2C_UNK func_ov010_02229a50(void);
    void func_ov000_0216a470(void);
    void func_ov000_0216a564(void);
    void func_ov000_0216a76c(void);
    void func_ov000_0216a7c4(void);
    M2C_UNK func_01ffa3dc(M2C_UNK, M2C_UNK);
    M2C_UNK func_02007f8c(M2C_UNK, M2C_UNK);
    M2C_UNK func_0203804c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02038688(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02074114(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

    M2C_UNK r4 = a;
    func_ov010_022282d4(2);
    func_ov010_0222791c(r4);
    func_ov010_02226a88();
    r4 = (M2C_UNK)func_020c4acc();
    func_020c4b60();
    func_ov010_02229a50();
    func_ov000_0216a470();
    func_ov000_0216a564();
    func_ov000_0216a76c();
    func_ov000_0216a7c4();
    return 0;
}

void func_ov010_02228a38(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
}

void *func_ov010_02228a48(void *arg0) {
    M2C_UNK func_ov010_02229580();
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        func_ov010_02229580();
        M2C_FIELD(arg0, s32 *, 4) = 0;
    }
    return arg0;
}

void func_ov010_02228a70(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK);
    void func_020382d0(void);
    void func_ov010_0222791c(M2C_UNK);
    s32 func_ov010_02228b20(M2C_UNK);
    s32 func_ov010_02228b38(M2C_UNK);
    s32 func_ov010_02228b50(M2C_UNK);
    s32 func_ov010_02228b68(M2C_UNK);
    s32 func_ov010_02228b80(M2C_UNK);
    s32 func_ov010_02228b98(M2C_UNK);
    s32 func_ov010_02228bb0(M2C_UNK);
    void func_ov010_02229438(M2C_UNK);
    void func_ov010_02229450(M2C_UNK);
    void func_ov010_02229468(M2C_UNK);
    void func_ov010_02229480(M2C_UNK);
    void func_ov010_02229498(M2C_UNK);
    void func_ov010_022294b0(M2C_UNK);
    void func_ov010_022294c8(M2C_UNK);
    M2C_UNK func_ov010_022282d4(M2C_UNK);
    extern M2C_UNK data_ov010_0222c160;
    extern M2C_UNK data_ov010_0222c330;
    extern M2C_UNK data_ov010_0222c2f8;
    func_01ffa9e4(&data_ov010_0222c160);
    func_01ffa9e4(&data_ov010_0222c330);
    func_01ffa9e4(&data_ov010_0222c2f8);
    func_020382d0();
    func_ov010_0222791c(0);
    func_ov010_02228b20(0);
    func_ov010_02228b38(0);
    func_ov010_02228b50(0);
    func_ov010_02228b68(0);
    func_ov010_02228b80(0);
    func_ov010_02228b98(0);
    func_ov010_02228bb0(0);
    func_ov010_02229438(0);
    func_ov010_02229450(0);
    func_ov010_02229468(0);
    func_ov010_02229480(0);
    func_ov010_02229498(0);
    func_ov010_022294b0(0);
    func_ov010_022294c8(0);
    func_ov010_022282d4(2);
}

s32 func_ov010_02228b20(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x38);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x38) = arg0;
    return temp_r2;
}

s32 func_ov010_02228b38(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x4C);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x4C) = arg0;
    return temp_r2;
}

s32 func_ov010_02228b50(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    s32 old = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x2c);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x2c) = arg0;
    return old;
}

s32 func_ov010_02228b68(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x34);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x34) = arg0;
    return temp_r2;
}

s32 func_ov010_02228b80(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x10);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x10) = arg0;
    return temp_r2;
}

s32 func_ov010_02228b98(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x14);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x14) = arg0;
    return temp_r2;
}

s32 func_ov010_02228bb0(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    s32 temp_r2;
    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x4);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x4) = arg0;
    return temp_r2;
}

void func_ov010_02228bc8(void) {
    M2C_UNK func_02038d40();
    M2C_UNK func_ov010_022282d4(M2C_UNK);
    func_02038d40();
    func_ov010_022282d4(3);
}

void func_ov010_02228bdc(M2C_UNK arg0) {
    s32 func_0204428c(u8);
    s32 func_ov010_022282b4(M2C_UNK);
    s32 func_ov010_022282f8();
    s32 func_ov010_02229850();
    s32 func_ov010_02229a08();
    s32 func_ov010_02229a24();
    s32 temp_r5;
    s32 var_r0;
    u16 temp_r7;
    s32 var_r6;
    s32 c;

    if (func_ov010_022282b4(3) == 0) goto end;
    if (func_ov010_022282f8() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 0) goto end;
    if (func_ov010_022282b4(6) != 0) goto end;
    if (func_ov010_02229850() == 0) {
        return;
    }
    temp_r5 = func_ov010_02229a24();
    c = 1;
    temp_r7 = (u16)(temp_r5 & ((c - 2) ^ (c << func_ov010_02229a08())));
    if (temp_r7 == 0) goto end;
    var_r6 = 0;
    c = 1;
loop:
    if ((temp_r7 & (c << var_r6)) && (func_0204428c((u8)var_r6) == 0)) {
        return;
    }
    var_r6 = var_r6 + 1;
    if (var_r6 < 4) goto loop;
end:
    func_01ffa6fc(arg0);
}

void func_ov010_02228c88(M2C_UNK arg0) {
    M2C_UNK func_ov010_02229608(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_ov010_0222c140;
    func_ov010_02229608(9, 0, 0, 0xFFFF);
    func_01ffa42c(&data_ov010_0222c140, arg0);
}

void func_ov010_02228cbc(void) {
    M2C_UNK func_02038de4();
    func_02038de4();
}

void func_ov010_02228cc8(void) {
    M2C_UNK func_02037bb8();
    func_02037bb8();
}

void func_ov010_02228cd4(void) {
      void func_ov010_02228a70();
  func_ov010_02228320();
    func_ov010_02228a70();
}

void func_ov010_02228ce4(void) {
    M2C_UNK func_ov010_02226a88();
    M2C_UNK func_ov010_02226908(M2C_UNK, s32, s32);
    void func_ov010_0222826c(void);
    extern M2C_UNK data_ov010_0222eee0;
    func_ov010_02226a88();
    func_ov010_02226908(0, M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x3c), 0x10e0);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x3c) = 0;
    func_ov010_0222826c();
}

