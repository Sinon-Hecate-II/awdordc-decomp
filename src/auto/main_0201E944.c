/* 35 functions from 0x0201E944 to 0x0201F89C (main), found by ds-decomp. */
#include "common.h"

s32 func_0201ebec(u8 *arg0, u8 **arg1) {
    s32 var_ip;
    u8 *var_r0;
    u8 temp_r3;

    var_r0 = arg0;
    *arg1 = var_r0;
    var_ip = 0;
loop_1:
    temp_r3 = *var_r0 - 0x30;
    if ((u32) temp_r3 <= 9U) {
        var_ip = (0xA * var_ip) + temp_r3;
        var_r0 += 1;
        *arg1 = var_r0;
        goto loop_1;
    }
    return var_ip;
}

s32 func_0201ec20(u8 *arg0, s32 *arg1) {
    u8 *end;
    s32 value = 0;
    s32 i = 0;
    u32 part;
    for (; i < 4; i++) {
        part = func_0201ebec(arg0, &end);
        if (arg0 == end) return 0;
        arg0 = end;
        if (part > 255 || (i != 3 && *arg0++ != '.') || (i == 3 && *arg0 != 0)) return 0;
        value = part | (value << 8);
    }
    *arg1 = value;
    return 1;
}

s32 func_0201ecbc(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    M2C_UNK func_0201d164();
    M2C_UNK func_0201d190(M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_0201d1f0();
    M2C_UNK func_0201d224();
    s32 func_0201e944(M2C_UNK, s32, M2C_UNK, s32, s32);
    s32 result;
    if (arg1 == 0) return -1;
    func_0201d1f0();
    func_0201d164();
    func_0201d190(0, 0x35, arg1);
    result = func_0201e944(arg0, 1, arg2, 0, 0);
    func_0201d224();
    return result;
}

s32 func_0201ee58(s32 arg0) {
    M2C_UNK func_02000b9c(s32);
    s32 func_0201ee94();
    M2C_UNK func_0201eed4();
    extern s32 data_020faf98;
    func_02000b9c(0x02000BF4);
    if (data_020faf98 != 0) {
        return 0;
    }
    data_020faf98 = arg0;
    func_0201eed4();
    return func_0201ee94();
}

s32 func_0201ee94(void) {
    s32 func_0201f0cc(s32);
    s32 func_0201f400();
    extern s32 data_020faf98;
    extern M2C_UNK data_020fafd0;
    extern M2C_UNK data_02138ac0;
    s32 result;
    result = func_0201f0cc(M2C_FIELD(data_020faf98, s32 *, 0x20));
    if (result >= 0) {
        M2C_FIELD(&data_02138ac0, s32 *, 0xC) = func_0201f400(&data_020fafd0);
    }
    return result;
}

void func_0201f030(void) {
    extern s32 data_020faf98;
    extern s32 data_021372e0, data_021372ac, data_021372bc;
    extern M2C_UNK data_021372f0, data_02138ac0;
    data_021372e0 = M2C_FIELD(data_020faf98, s32 *, 4);
    data_021372ac = M2C_FIELD(data_020faf98, s32 *, 8);
    data_021372bc = M2C_FIELD(data_020faf98, s32 *, 0xC);
    M2C_FIELD(&data_021372f0, s32 *, 0) = M2C_FIELD(data_020faf98, s32 *, 0x10);
    M2C_FIELD(&data_021372f0, s32 *, 4) = M2C_FIELD(data_020faf98, s32 *, 0x14);
    M2C_FIELD(&data_02138ac0, s32 *, 8) |= 2;
}

void func_0201f09c(void) {
    extern M2C_UNK data_02138ac0;
    M2C_FIELD(&data_02138ac0, s32 *, 8) = (s32) (M2C_FIELD(&data_02138ac0, s32 *, 8) | 2);
}

s32 func_0201f0b4(void) {
    s32 func_02029784();
    if (func_02029784() != 0) {
        return 1;
    }
    return 0;
}

s32 func_0201f0cc(s32 arg0) {
    void func_0201f210(s32);
    M2C_UNK func_020062d4(s32, s32, s32);
    extern s32 data_020faf98;
    extern M2C_UNK data_02138b00, data_02138b04;
    s32 temp_r5;
    s32 temp_r0;
    s32 var_r4;
    s32 var_r5;
    s32 size;
    var_r4 = arg0;
    temp_r5 = ((var_r4 * 4) + 3) & ~3;
    size = ((var_r4 * 0x2C) + 3) & ~3;
    temp_r0 = M2C_FIELD(data_020faf98, s32 (**)(s32), 0x18)(size + temp_r5);
    if (temp_r0 == 0) return -1;
    func_020062d4((s32)&data_02138b04, temp_r0, var_r4);
    var_r5 = temp_r0 + temp_r5;
    if (var_r4 > 0) {
        do {
            func_0201f210(var_r5);
            var_r4 -= 1;
            var_r5 += 0x2C;
        } while (var_r4 > 0);
    }
    M2C_FIELD(&data_02138b00, s32 *, 0) = temp_r0;
    return 0;
}

s32 func_0201f160(void) {
    extern s32 data_020faf98;
    extern M2C_UNK data_02138b00;
    if (M2C_FIELD(&data_02138b00, s32 *, 0x20) < M2C_FIELD(&data_02138b00, s32 *, 0x18)) return -1;
    M2C_FIELD(data_020faf98, void (**)(s32), 0x1C)(M2C_FIELD(&data_02138b00, s32 *, 0));
    M2C_FIELD(&data_02138b00, s32 *, 0) = 0;
    return 0;
}

s32 func_0201f1a8(s32 arg0) {
    s32 func_02006390(M2C_UNK *, s32 *, s32);
    extern M2C_UNK data_02138b04;
    s32 result;
    if (func_02006390(&data_02138b04, &result, arg0) != 0) return result;
    return 0;
}

s32 func_0201f1d0(M2C_UNK *arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_r0 = func_0201f1a8(arg2);
    if (temp_r0 == 0) return temp_r0;
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = arg0;
    M2C_FIELD(temp_r0, s32 *, 4) = arg1;
    M2C_FIELD(temp_r0, s32 *, 8) = 0;
    M2C_FIELD(temp_r0, s8 *, 0xC) = M2C_FIELD(arg1, s8 *, 0x73);
    M2C_FIELD(temp_r0, s8 *, 0xD) = arg2;
    return temp_r0;
}

void func_0201f210(s32 arg0) {
    M2C_UNK func_020062fc(M2C_UNK *, s32, M2C_UNK);
    extern M2C_UNK data_02138b04;
    if (arg0 == 0) {
        return;
    }
    func_020062fc(&data_02138b04, arg0, 0);
}

s32 func_0201f230(void *arg0) {
    s32 var_r1;

    var_r1 = M2C_FIELD(arg0, s32 *, 0x64);
    if (var_r1 == 0) {
        var_r1 = M2C_FIELD(arg0, s32 *, 0x68);
    }
    return var_r1;
}

s32 func_0201f244(M2C_UNK arg0, void *arg1) {
    M2C_UNK var_r2;
    s32 temp_r0;

    if ((arg1 == NULL) || (M2C_FIELD(arg1, s8 *, 0xD) & 1)) {
        var_r2 = 1;
    } else {
        var_r2 = 0;
    }
    temp_r0 = func_020062fc(arg0, arg1, var_r2);
    if (temp_r0 == 0) {
        func_0201f210(arg1);
    }
    if (temp_r0 != 0) {
        return 0;
    }
    return -0x2A;
}

s32 func_0201f290(void *arg0, void *arg1) {
    return func_0201f244(func_0201f230(arg0), arg1);
}

s32 func_0201f2a8(arg0, arg1)
s32 arg0;
void *arg1;
{
    M2C_UNK func_020062d4(s32, s32, s32);
    s32 func_02006390(M2C_UNK *, s32 *, s32);
    u8 queue[0x20];
    s32 result;
    s32 message;
    if (M2C_FIELD(arg1, s8 *, 0xD) == 1) {
        func_020062d4((s32)queue, (s32)&message, 1);
        M2C_FIELD(arg1, void **, 8) = queue;
        func_0201f244(arg0, arg1);
        func_02006390((M2C_UNK *)queue, &result, 1);
    } else {
        M2C_FIELD(arg1, void **, 8) = NULL;
        result = func_0201f244(arg0, arg1);
    }
    return result;
}

void func_0201f318(void *arg0) {
    M2C_UNK func_0201f2a8();
    func_0201f2a8(M2C_FIELD(arg0, s32 *, 0x64));
}

void func_0201f328(void *arg0) {
    func_0201f2a8(M2C_FIELD(arg0, s32 *, 0x68));
}

s32 func_0201f338(s32 arg0, s32 arg1) {
    s32 func_0201f2a8();
    return func_0201f2a8(func_0201f230(arg0), arg1);
}

void func_0201f350(s32 arg0) {
s32 p,old,v;
loop:
func_020064d0(arg0,&p,1);
if(p) {
v=M2C_FIELD(p,s32 (**)(s32),0)(p);
old=func_0200751c();
func_02006130();
func_02006390(arg0,0,0);
if(M2C_FIELD(p,s32*,4))M2C_FIELD(M2C_FIELD(p,s32*,4),s32*,0x6c)=v;
if(M2C_FIELD(p,s32*,8))func_020062fc(M2C_FIELD(p,s32*,8),v,0);
func_0201f210(p);func_02006164();func_02007530(old);
goto loop;
}
}

s32 func_0201f400(void) {
    s32 func_0201f1d0(M2C_UNK *, s32, M2C_UNK);
    M2C_UNK func_0201f338(s32, s32);
    s32 func_0201f4b0();
    extern M2C_UNK func_0201f43c;
    s32 temp_r0;

    temp_r0 = func_0201f4b0();
    if (temp_r0 == 0) {
        return -0x31;
    }
    func_0201f338(temp_r0, func_0201f1d0(&func_0201f43c, temp_r0, 1));
    return temp_r0;
}

s32 func_0201f43c(void *arg0) {
M2C_UNK func_0201d138(void *);
M2C_UNK func_0201d164();
M2C_UNK func_0201d1f0();
M2C_UNK func_0201d244(s32);
M2C_UNK func_0201d29c(M2C_UNK *);
extern M2C_UNK func_02020364;
void *p=M2C_FIELD(arg0,void**,4);
s32 v;
func_0201d138(p);
v=M2C_FIELD(p,s32*,0x68);
switch(M2C_FIELD(p,s8*,0x73)){
case 0:case 4:func_0201d244(v+0x20);func_0201d1f0();break;
case 1:func_0201d1f0();func_0201d164();func_0201d29c(&func_02020364);break;
case 2:func_0201d164();break;
}
M2C_FIELD(p,s16*,0x70)=1;return 0;
}

s32 func_0201f4b0(arg0)
void *arg0;
{
extern s32 data_020faf98;
s32 p,old,size;
size=func_0201f518(arg0);
old=func_0200751c();
p=M2C_FIELD(data_020faf98,s32 (**)(s32),0x18)(size);
if(p){func_02007f8c(p,0,size);func_0201f5c0(p,arg0);func_020213f0(p);}
func_02007530(old);return p;
}

s32 func_0201f518(void *arg0) {
s32 n=0x80; u32 v;
v=M2C_FIELD(arg0,u16*,2);
if(v){n+=0x114;n+=func_020213e4(v);n+=func_020213e4(M2C_FIELD(arg0,u16*,8));n+=func_0201f598(arg0+0x10);}
v=M2C_FIELD(arg0,u16*,6);
if(v){n+=0x110;n+=func_020213e4(v);n+=func_020213e4(M2C_FIELD(arg0,u16*,0xa));n+=func_020213e4(M2C_FIELD(arg0,u16*,0xc));n+=func_0201f598(arg0+0x14);}
return n;
}

s32 func_0201f598(void *arg0) {
    s32 temp_r4;

    temp_r4 = func_020213e4(M2C_FIELD(arg0, u8 *, 3) * 4);
    return temp_r4 + func_020213e4(M2C_FIELD(arg0, u16 *, 0));
}

/* Duplicate the sprite/frame data referenced by `src` into `dst`, advancing the cursor. */
s32 func_0201f5c0(void *dst, void *src) {
    extern void *data_02138acc;
    void *p;
    void *q;
    void *r0;
    void *cur;

    cur = dst + 0x80;
    M2C_FIELD(dst, s8 *, 0x73) = M2C_FIELD(src, s8 *, 0);
    M2C_FIELD(dst, s8 *, 0x72) = M2C_FIELD(src, s8 *, 1);

    if (M2C_FIELD(src, u16 *, 2) != 0) {
        M2C_FIELD(dst, void **, 0x64) = cur;
        M2C_FIELD(cur, u16 *, 0xFC) = M2C_FIELD(src, u16 *, 4);
        p = cur;
        r0 = (void *)func_0201f6bc(func_0201f6bc(func_0201f6e4((s32)(cur + 0x114), (s32)cur, src + 0x10), dst + 0x3C, M2C_FIELD(src, u16 *, 2)), dst + 0x50, M2C_FIELD(src, u16 *, 8));
        cur = r0;
        M2C_FIELD(p + 0x100, u16 *, 0x0A) = M2C_FIELD(src, u16 *, 0x0E);
        M2C_FIELD(p, s32 *, 0x110) = 0;
        M2C_FIELD(p, s32 *, 0x10C) = 0;
    }

    if (M2C_FIELD(src, u16 *, 6) != 0) {
        M2C_FIELD(dst, void **, 0x68) = cur;
        q = cur;
        M2C_FIELD(cur, void **, 0x10C) = dst;
        r0 = (void *)func_0201f6bc(func_0201f6bc(func_0201f6bc(func_0201f6e4((s32)(cur + 0x110), (s32)cur, src + 0x14), dst + 0x48, M2C_FIELD(src, u16 *, 6)), dst + 0x58, M2C_FIELD(src, u16 *, 0x0A)), cur + 0xF8, M2C_FIELD(src, u16 *, 0x0C));
        cur = r0;
        M2C_FIELD(q, s32 *, 0x108) = 0;
        M2C_FIELD(q, s32 *, 0x104) = 0;
    } else {
        M2C_FIELD(dst, void **, 0x68) = M2C_FIELD(data_02138acc, void **, 0x68);
    }

    return (s32)cur;
}

s32 func_0201f6bc(s32 arg0, void *arg1, s32 arg2) {
    s32 temp_r4;
    s32 var_r0;

    var_r0 = arg0;
    temp_r4 = var_r0;
    if (arg2 == 0) {
        var_r0 = 0;
    }
    M2C_FIELD(arg1, s32 *, 4) = var_r0;
    M2C_FIELD(arg1, s32 *, 0) = arg2;
    return temp_r4 + func_020213e4(arg2);
}

s32 func_0201f6e4(s32 arg0, s32 arg1, void *arg2) {
    M2C_UNK func_02005ac0(s32, M2C_UNK *, s32, s32, s32, s32);
    M2C_UNK func_02005e5c(s32);
    M2C_UNK func_020062d4(s32, s32, s32);
    M2C_UNK func_0200654c(s32);
    s32 func_0201f598(void *);
    void func_0201f350();
    s32 temp_r4;

    temp_r4 = func_0201f598(arg2);
    func_020062d4(arg1, arg0, M2C_FIELD(arg2, u8 *, 3));
    func_0200654c(arg1 + 0xE0);
    func_02005ac0(arg1 + 0x20, (M2C_UNK *)&func_0201f350, arg1, arg0 + temp_r4, (s32) M2C_FIELD(arg2, u16 *, 0), (s32) M2C_FIELD(arg2, u8 *, 2));
    func_02005e5c(arg1 + 0x20);
    return arg0 + temp_r4;
}

s32 func_0201f758(void *arg0) {
s32 func_020214a8();
s32 a,b; s8 v;
if(func_020214a8()!=0)return -28;
a=0;
if(arg0!=0) a=(M2C_FIELD(arg0,volatile s16*,0x70)&1)!=0;
if(!a)return -39;
if(M2C_FIELD(arg0,s16*,0x70)&2)return -28;
v=M2C_FIELD(arg0,s8*,0x73);b=1;
if(v!=0 && v!=4)b=0;
if(!b)return -28;
return M2C_FIELD(arg0,s8*,0x72)==1?0:-6;
}

s32 func_0201f7d8(void *arg0, s32 arg1, s32 arg2) {
s32 func_020214a8(); s32 func_0201f400(); s32 func_0201f9e4(); s32 func_0201f89c();
extern M2C_UNK data_020fafb8;
s32 a,b,r,h; s8 v;
if(func_020214a8()!=0)return -28;
a=0;
if(arg0!=0)a=(M2C_FIELD(arg0,volatile s16*,0x70)&1)!=0;
if(!a)return -39;
if(M2C_FIELD(arg0,s16*,0x70)&2)return -28;
v=M2C_FIELD(arg0,s8*,0x73);b=1;
if(v!=0 && v!=4)b=0;
if(!b)return -28;
if(M2C_FIELD(arg0,s8*,0x72)!=1)return -6;
h=func_0201f400(&data_020fafb8);
if(h<0)return h;
r=func_0201f9e4(h,M2C_FIELD(arg0,u16*,0x74));
if(r<0)return r;
r=func_0201f89c(h,arg1,arg2);
if(r<0)return r;
return h;
}

