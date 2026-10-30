/* 22 functions from 0x0201F89C to 0x02020738 (main), found by ds-decomp. */
#include "common.h"

s32 func_0201f89c(void *arg0, s32 arg1, s32 arg2) {
    s32 func_020214a8();
    void *func_0201f1d0(s32 (*)(void *), void *, s8);
    s32 func_0201f318(void *, void *);
    s32 func_0201f96c(void *);
    s32 a, b;
    s8 v;
    void *p;

    if (func_020214a8() != 0) {
        return -28;
    }
    a = 0;
    if (arg0 != 0) {
        a = (M2C_FIELD(arg0, volatile s16 *, 0x70) & 1) != 0;
    }
    if (a == 0) {
        return -39;
    }
    if (M2C_FIELD(arg0, s16 *, 0x70) & 2) {
        return -28;
    }
    v = M2C_FIELD(arg0, s8 *, 0x73);
    b = 1;
    if (v != 0 && v != 4) {
        b = 0;
    }
    if (b == 0) {
        return -28;
    }
    if (M2C_FIELD(arg0, s8 *, 0x72) != 1) {
        return -6;
    }
    if (M2C_FIELD(arg0, u16 *, 0x74) == 0) {
        return -28;
    }
    p = func_0201f1d0((s32 (*)(void *))func_0201f96c, arg0, (s8)M2C_FIELD(arg0, s8 *, 0x72));
    M2C_FIELD(p, u16 *, 0x10) = M2C_FIELD(arg0, u16 *, 0x74);
    M2C_FIELD(p, s32 *, 0x14) = arg1;
    M2C_FIELD(p, s32 *, 0x18) = arg2;
    M2C_FIELD(arg0, s16 *, 0x70) = (s16)(M2C_FIELD(arg0, s16 *, 0x70) | 2);
    return func_0201f318(arg0, p);
}

s32 func_0201f96c(void *arg0) {
    M2C_UNK func_02006564(s32);
    M2C_UNK func_020065e8(void *);
    M2C_UNK func_0201d190(u16, M2C_UNK, M2C_UNK);
    M2C_UNK func_0201d2b8();
    s32 func_0201d3e4(u16 *, M2C_UNK *);
    M2C_UNK sp4;
    u16 sp0;
    s32 temp_r0;
    void *temp_r4;
    void *temp_r5;

    temp_r4 = M2C_FIELD(arg0, void **, 4);
    temp_r5 = M2C_FIELD(temp_r4, void **, 0x64);
    func_02006564(temp_r5 + 0xE0);
    func_0201d190(M2C_FIELD(arg0, u16 *, 0x10), 0, 0);
    func_0201d2b8();
    M2C_FIELD(temp_r5, s32 *, 0xF8) = 0;
    temp_r0 = func_0201d3e4(&sp0, &sp4);
    *M2C_FIELD(arg0, u16 **, 0x14) = sp0;
    *M2C_FIELD(arg0, s32 **, 0x18) = temp_r0;
    M2C_FIELD(temp_r4, s16 *, 0x70) = (s16) (M2C_FIELD(temp_r4, s16 *, 0x70) | 4);
    func_020065e8(temp_r5 + 0xE0);
    return 0;
}

s32 func_0201f9e4(void *arg0,s32 arg1) {
s32 func_020214a8(); s32 func_0201fb3c(void *);s32 a;
if(func_020214a8()!=0)return -28;
a=0;if(arg0)a=(M2C_FIELD(arg0,volatile s16 *,0x70)&1)!=0;
if(!a)return -39;
if(M2C_FIELD(arg0,s16 *,0x70)&2)return -7;
M2C_FIELD(arg0,s16 *,0x74)=arg1;
if(M2C_FIELD(arg0,s8 *,0x73)!=1)return 0;
return func_0201fb3c(arg0);
}

s32 func_0201fa54(void *arg0, s16 arg1, s32 arg2) {
    s32 func_020214a8();
    s32 func_0201fb3c(void *);
    extern s32 data_020faf9c;
    s32 a, b, r;
    s8 v;

    if (func_020214a8() != 0 || (M2C_FIELD(arg0, volatile s16 *, 0x70) & 8)) return -28;
    a = 0;
    if (arg0 != 0) {
        a = (M2C_FIELD(arg0, volatile s16 *, 0x70) & 1) != 0;
    }
    if (a == 0) return -39;
    v = M2C_FIELD(arg0, s8 *, 0x73);
    b = 1;
    if (v != 0 && v != 4) {
        b = 0;
    }
    if (b != 0) {
        if (M2C_FIELD(arg0, volatile s16 *, 0x70) & 4) {
            return M2C_FIELD(arg0, s8 *, 0x72) == 1 ? -30 : 0;
        }
        if (M2C_FIELD(arg0, volatile s16 *, 0x70) & 2) {
            return (M2C_FIELD(arg0, volatile s16 *, 0x70) & 0x40) ? M2C_FIELD(arg0, s32 *, 0x6c) : data_020faf9c;
        }
        M2C_FIELD(arg0, s16 *, 0x76) = arg1;
        M2C_FIELD(arg0, s32 *, 0x78) = arg2;
        r = func_0201fb3c(arg0);
        if (M2C_FIELD(arg0, s8 *, 0x72) != 1) r = -26;
        return r;
    }
    M2C_FIELD(arg0, s16 *, 0x76) = arg1;
    M2C_FIELD(arg0, s32 *, 0x78) = arg2;
    return 0;
}

s32 func_0201fb3c(void *arg0) {
s32 func_0201fb94(void *);
void *func_0201f1d0(s32 (*)(void *),void *,s8);
s32 func_0201f318(void *,void *);
void *p=func_0201f1d0(func_0201fb94,arg0,M2C_FIELD(arg0,s8 *,0x72));
if(!p)return -33;
M2C_FIELD(p,u16 *,0x10)=M2C_FIELD(arg0,u16 *,0x74);
M2C_FIELD(p,u16 *,0x12)=M2C_FIELD(arg0,u16 *,0x76);
M2C_FIELD(p,s32 *,0x14)=M2C_FIELD(arg0,s32 *,0x78);
M2C_FIELD(arg0,s16 *,0x70)|=2;
return func_0201f318(arg0,p);
}

s32 func_0201fb94(void *arg0) {
s32 func_0201d3a4(); void *p,*q;s32 v;s8 t;
p=M2C_FIELD(arg0,void **,4);v=0;q=M2C_FIELD(p,void **,0x64);
func_02006564(q+0xe0);
func_0201d190(M2C_FIELD(arg0,u16 *,0x10),M2C_FIELD(arg0,u16 *,0x12),M2C_FIELD(arg0,s32 *,0x14));
M2C_FIELD(q,s32 *,0xf8)=v;t=M2C_FIELD(arg0,s8 *,12);
if(t==0 || t==4)v=func_0201d3a4();
func_020065e8(q+0xe0);
if(v){M2C_FIELD(p,volatile s16 *,0x70)|=0x40;return -76;}
M2C_FIELD(p,volatile s16 *,0x70)|=4;return 0;
}

#pragma optimization_level 2
s32 func_0201fc18(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, s32 arg5) {
    s32 func_02006564();
    s32 func_020065e8();
    s32 func_02006680();
    s32 func_02007580();
    s32 func_0201fd60(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    s32 func_020214a8();
    void *temp_r4;
    s32 var_r5;
    s32 var_r1;
    s32 var_r1_2;
    s8 temp_r0;

    if (func_020214a8() != 0) {
        return -0x1C;
    }
    if (!(arg5 & 4) && M2C_FIELD(arg0, s8 *, 0x72) == 0) {
        if (M2C_FIELD(arg0, s8 *, 0x73) == 4) {
            return -0x1C;
        }
        var_r5 = 0;
    } else {
        if (func_02007580() == 0x12) {
            return -0x1C;
        }
        var_r5 = 1;
    }
    var_r1 = 0;
    if (arg0 != 0) {
        var_r1 = (M2C_FIELD(arg0, volatile s16 *, 0x70) & 1) != 0;
    }
    if (var_r1 == 0) {
        return -0x27;
    }
    temp_r0 = M2C_FIELD(arg0, s8 *, 0x73);
    var_r1_2 = 1;
    if (temp_r0 != 0 && temp_r0 != 4) {
        var_r1_2 = 0;
    }
    if (var_r1_2 != 0 && (!(M2C_FIELD(arg0, volatile s16 *, 0x70) & 4) || (M2C_FIELD(arg0, volatile s16 *, 0x70) & 8))) {
        return -0x38;
    }
    temp_r4 = M2C_FIELD(arg0, void **, 0x64);
    if (!(var_r5 & 1)) {
        if (func_02006680(temp_r4 + 0xE0) == 0) {
            return -6;
        }
    } else {
        func_02006564(temp_r4 + 0xE0);
    }
    var_r5 = func_0201fd60(arg0, arg1, arg2, arg3, arg4, var_r5, arg5);
    func_020065e8(temp_r4 + 0xE0);
    return var_r5;
}
#pragma optimization_level reset
s32 func_0201fd60(void *p,s32 b,s32 c,s32 d,s32 e,s32 f,s32 flags) {
 s32 func_02020220(void *,s32,s32,s32,s32,s32);
 s32 func_0201fdfc(void *,s32,s32,s32,s32,s32);
 s32 func_02020188(void *);
 void *q=M2C_FIELD(p,void **,0x64);
 s32 enabled=(flags&2)!=0 && q!=0;
 s8 old;s32 result;
 if(enabled){old=M2C_FIELD(q,s8 *,0xFE);M2C_FIELD(q,s8 *,0xFE)=1;}
 if(M2C_FIELD(p,s8 *,0x73)==1)result=func_02020220(p,b,c,d,e,f);
 else{result=func_0201fdfc(p,b,c,d,e,f);if(result>=0)func_02020188(p);}
 if(enabled)M2C_FIELD(q,s8 *,0xFE)=old;
 return result;
}

s32 func_0201fdfc(void *p,s32 b,s32 c,s32 d,s32 e,s32 flags) {
 s32 func_0201ffec(void *,s32,s32,s32,s32);
 s32 func_0201fe70(void *,s32,s32,u16 *,s32 *);
 s32 result;
 if(M2C_FIELD(p,s8 *,0x73)==4)return func_0201ffec(p,b,c,d,e);
 result=func_0201fe70(p,b,c,d,e);
 if(result!=-6)return result;
 if(!(flags&1))return result;
 return func_0201ffec(p,b,c,d,e);
}

s32 func_0201fe70(void *arg0, M2C_UNK arg1, s32 arg2, u16 *arg3, s32 *arg4) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    M2C_UNK func_02008048(s32, M2C_UNK, s32);
    s32 func_0201ff78(void *, s32 *, u16 *, u16 *, s32 *);
    s32 spC;
    s32 sp8;
    u16 sp6;
    u16 sp4;
    s32 temp_r0;
    s32 temp_r4;
    s32 var_r2;
    s32 var_r5;
    s32 var_r7;
    s8 temp_r1;
    void *temp_r1_2;

    var_r7 = arg2;
    temp_r4 = func_0200751c();
    temp_r0 = func_0201ff78(arg0, &spC, &sp6, &sp4, &sp8);
    if (temp_r0 != 0) {
        var_r5 = spC;
        if (var_r5 == 0) {
            var_r5 = -6;
        } else {
            temp_r1 = M2C_FIELD(arg0, s8 *, 0x73);
            var_r2 = 1;
            if (var_r7 > var_r5) {
                var_r7 = var_r5;
            }
            if ((temp_r1 != 0) && (temp_r1 != 4)) {
                var_r2 = 0;
            }
            if (var_r2 != 0) {
                var_r5 = var_r7;
            }
            func_02008048(temp_r0, arg1, var_r7);
            temp_r1_2 = M2C_FIELD(arg0, void **, 0x64);
            if (M2C_FIELD(temp_r1_2, s8 *, 0xFE) == 0) {
                M2C_FIELD(temp_r1_2, s32 *, 0xF8) = (s32) (M2C_FIELD(temp_r1_2, s32 *, 0xF8) + var_r5);
            }
        }
    } else {
        if (spC == 0) {
            var_r5 = 0;
        } else {
            var_r5 = -0x1C;
        }
        M2C_FIELD(arg0, s16 *, 0x70) = (s16) (M2C_FIELD(arg0, s16 *, 0x70) & ~6);
    }
    if (var_r5 >= 0) {
        if ((arg3 != NULL) && (arg4 != NULL)) {
            *arg3 = sp4;
            *arg4 = sp8;
        }
        if (M2C_FIELD(arg0, u16 *, 0x74) == 0) {
            M2C_FIELD(arg0, u16 *, 0x74) = sp6;
        }
    }
    func_02007530(temp_r4);
    return var_r5;
}

s32 func_0201ff78(void *p,s32 *remaining,u16 *a,u16 *b,s32 *c) {
 void *q=M2C_FIELD(p,void **,0x64);
 void *entry=M2C_FIELD(q,void **,0xC4);
 s32 offset=M2C_FIELD(q,s32 *,0xF8);
 s32 n=M2C_FIELD(entry,s32 *,0x44)-offset;
 if(n>=0){
 *a=M2C_FIELD(entry,u16 *,0xA);*b=M2C_FIELD(entry,u16 *,0x18);
 *c=M2C_FIELD(entry,s32 *,0x1C);*remaining=n;
 if(n==0 && M2C_FIELD(entry,u8 *,8)!=4)return 0;
 }else{*remaining=-1;return 0;}
 return M2C_FIELD(entry,s32 *,0x40)+offset;
}

s32 func_0201ffec(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
s32 func_02020038(void *);
void *p=func_0201f1d0(func_02020038,arg0,1);
M2C_FIELD(p,s32 *,0x10)=arg1;
M2C_FIELD(p,s32 *,0x14)=arg2;
M2C_FIELD(p,s32 *,0x18)=arg3;
M2C_FIELD(p,s32 *,0x1c)=arg4;
func_0201f318(arg0,p);
}

s32 func_02020038(void *arg0) {
    s32 func_0201d618(u32 *);
    M2C_UNK func_02006030(s32);
    M2C_UNK func_02008048(s32, s32, s32);
    s32 func_0201fe70(void *, M2C_UNK, s32, u16 *, s32 *);
    void func_0201d70c(s32);
    s32 func_020201e4(s32);
    u32 sp10;
    s32 spC;
    u16 *sp8;
    s32 *sp4;
    s32 temp_r9;
    s32 var_r0;
    s32 var_r1;
    s32 var_r4;
    s8 temp_r0;
    u32 var_r10;
    void *temp_r7;
    void *temp_r8;

    temp_r7 = M2C_FIELD(arg0, void **, 4);
    temp_r8 = M2C_FIELD(temp_r7, void **, 0x64);
    spC = M2C_FIELD(arg0, s32 *, 0x10);
    var_r10 = M2C_FIELD(arg0, u32 *, 0x14);
    temp_r9 = M2C_FIELD(temp_r8, s32 *, 0xF8);
    sp8 = M2C_FIELD(arg0, u16 **, 0x18);
    sp4 = M2C_FIELD(arg0, s32 **, 0x1C);
loop_1:
    var_r0 = func_0201d618(&sp10);
    if ((var_r0 != 0) && ((s32) (sp10 - temp_r9) <= 0)) {
        temp_r0 = M2C_FIELD(temp_r7, s8 *, 0x73);
        var_r1 = 1;
        if ((temp_r0 != 0) && (temp_r0 != 4)) {
            var_r1 = 0;
        }
        if ((var_r1 != 0) && (M2C_FIELD((u32)temp_r7, u8 *, 8) != 4)) {
            var_r0 = 0;
        } else {
            func_02006030(0xA);
            goto loop_1;
        }
    }
    if (M2C_FIELD(temp_r7, s16 *, 0x70) & 0x80) {
        return -0xF;
    }
    if (M2C_FIELD(temp_r7, s8 *, 0x73) == 4) {
        if (var_r0 == 0) {
            return 0;
        }
        if (var_r10 > sp10) {
            var_r10 = sp10;
        }
        func_02008048(var_r0, spC, (s32) var_r10);
        func_0201d70c((s32) var_r10);
        return (s32) var_r10;
    }
    if (var_r0 == 0) {
        var_r4 = 0;
    } else {
        var_r4 = func_0201fe70(temp_r7, spC, var_r10, sp8, sp4);
    }
    if (var_r4 <= 0) {
        return var_r4;
    }
    if ((s32) M2C_FIELD(temp_r8, s32 *, (int)0xF8) >= (s32) M2C_FIELD(temp_r8, u16 *, 0xFC)) {
        func_020201e4(temp_r7);
    }
    return var_r4;
}

s32 func_02020188(void *arg0) {
void func_020201d4(void *);
void *q=M2C_FIELD(arg0,void **,0x64),*p;
if(M2C_FIELD(q,s32 *,0xf8)<M2C_FIELD(q,u16 *,0xfc))return 0;
p=func_0201f1d0((s32 (*)(void *))func_020201d4,arg0,0);
if(!p)return -33;
return func_0201f318(arg0,p);
}

void func_020201d4(void *arg0) {
    M2C_UNK func_020201e4(s32);
    func_020201e4(M2C_FIELD(arg0, s32 *, 4));
}

#pragma dont_inline on
s32 func_020201e4(s32 p) {
 s32 func_0200751c(void);s32 func_02007530(s32);void func_0201d70c(s32);
 void *q=M2C_FIELD(p,void **,0x64);
 s32 irq=func_0200751c();s32 value=M2C_FIELD(q,s32 *,0xF8);
 if(value){M2C_FIELD(q,s32 *,0xF8)=0;func_0201d70c(value);}
 func_02007530(irq);return value;
}

s32 func_02020220(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_0200751c(void);
    M2C_UNK func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    s32 func_020214a8();
    M2C_UNK func_02008048(M2C_UNK, M2C_UNK, s32);
    extern s32 data_020faf98;

    void *r6 = M2C_FIELD(arg0, void **, 0x64);
    s32 sp0 = arg1;
    s32 sp4 = arg2;
    void *out_arg3 = (void *)arg3;
    s32 irqs = func_0200751c();
    void *node = M2C_FIELD(r6, void **, 0x104);
    s32 r8 = 0;
    s32 r9;
    s32 r5 = 0;

    if (node == NULL) {
        r9 = arg5 & 1;
        if (r9 == 0) {
            r8 = -6;
        } else {
            func_02005da4((char *)r6 + 0x10c);
            if (func_020214a8(arg0) != 0) {
                node = M2C_FIELD(r6, void **, 0x104);
                if (node == NULL) {
                    node = M2C_FIELD(r6, void **, 0x104);
                }
            } else {
                s32 ok = 0;
                if (arg0 != NULL) {
                    ok = (M2C_FIELD(arg0, s16 *, 0x70) & 1) != 0;
                }
                if (!ok) {
                    r8 = -0x38;
                    goto done;
                }
            }
        }
    }

    node = M2C_FIELD(r6, void **, 0x104);
    if (node != NULL) {
        s32 lim = M2C_FIELD(node, u16 *, 0x4);
        if (sp4 > lim) {
            sp4 = lim;
        }
        func_02008048((char *)node + 0xC, (void *)sp0, sp4);
        if (out_arg3 != NULL) {
            M2C_FIELD(out_arg3, u16 *, 0) = M2C_FIELD(node, u16 *, 0x6);
        }
        if (arg4 != 0) {
            M2C_FIELD(arg4, s32 *, 0) = M2C_FIELD(node, s32 *, 0x8);
        }
        r8 = M2C_FIELD(node, u16 *, 0x4);
        if (M2C_FIELD(r6, s8 *, 0xfe) == 0) {
            void *nxt = M2C_FIELD(node, void **, 0x0);
            M2C_FIELD(r6, void **, 0x104) = nxt;
            if (nxt == NULL) {
                M2C_FIELD(r6, void **, 0x100) = NULL;
            }
            {
                void **alloc = (void **)data_020faf98;
                void (*freefn)(void *) = (void (*)(void *))alloc[7];
                freefn(node);
            }
            {
                u16 *pcnt = (u16 *)((char *)r6 + 0x108);
                *pcnt = (u16)(*pcnt - r8);
            }
        }
    }

done:
    func_02007530(irqs);
    return r8;
}

s32 func_02020364(void *arg0, s16 arg1, void *arg2) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    M2C_UNK func_02008048(M2C_UNK, M2C_UNK, s32);
    void func_02005df4(void *);
    extern s32 data_020faf98;
    extern M2C_UNK data_02138b24;
    void *temp_r4;
    void *temp_r0;
    s32 temp_r6;

    temp_r4 = M2C_FIELD(arg2, void **, 0x64);
    temp_r6 = func_0200751c();
    if (M2C_FIELD(temp_r4, u16 *, 0x10A) >= (u32) (M2C_FIELD(temp_r4, u16 *, 0x108) + arg1)) {
        temp_r0 = M2C_FIELD(data_020faf98, void *(**)(s32), 0x18)(arg1 + 0xC);
        if (temp_r0 != NULL) {
            M2C_FIELD(temp_r4, u16 *, 0x108) = (u16) (M2C_FIELD(temp_r4, u16 *, 0x108) + arg1);
            M2C_FIELD(temp_r0, M2C_UNK **, 0) = NULL;
            M2C_FIELD(temp_r0, s16 *, 4) = arg1;
            M2C_FIELD(temp_r0, u16 *, 6) = M2C_FIELD(arg2, u16 *, 0x18);
            M2C_FIELD(temp_r0, s32 *, 8) = M2C_FIELD(arg2, s32 *, 0x1C);
            func_02008048(arg0, (char *) temp_r0 + 0xC, arg1);
            if (M2C_FIELD(temp_r4, void *volatile *, 0x100) != NULL) {
                *(M2C_UNK **) M2C_FIELD(temp_r4, void *volatile *, 0x100) = temp_r0;
            }
            M2C_FIELD(temp_r4, void **, 0x100) = temp_r0;
            if (M2C_FIELD(temp_r4, void **, 0x104) == NULL) {
                M2C_FIELD(temp_r4, void **, 0x104) = temp_r0;
            }
        } else {
            M2C_FIELD(&data_02138b24, s32 *, 0) = (s32) (M2C_FIELD(&data_02138b24, s32 *, 0) + 1);
        }
    } else {
        M2C_FIELD(&data_02138b24, s32 *, 4) = (s32) (M2C_FIELD(&data_02138b24, s32 *, 4) + 1);
    }
    if (M2C_FIELD(arg2, u16 *, 0x74) == 0) {
        M2C_FIELD(arg2, u16 *, 0x74) = (u16) M2C_FIELD(arg2, u16 *, 0xA);
    }
    M2C_FIELD(arg2, u16 *, 0x18) = (u16) M2C_FIELD(arg2, u16 *, 0x1A);
    M2C_FIELD(arg2, s32 *, 0x1C) = M2C_FIELD(arg2, s32 *, 0x20);
    func_02005df4((char *) temp_r4 + 0x10C);
    func_02007530(temp_r6);
    return 1;
}

s32 func_02020478(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_020214a8();
    s32 func_02006680(s32);
    s32 func_0202058c(void *, s32, s32, s32, s32, s32);
    s32 temp_r4;
    s32 temp_r5;
    s32 var_ip;
    s32 var_r1;
    s32 var_r1_2;
    s8 temp_r0;

    if (func_020214a8() != 0) {
        return -28;
    }
    var_r1 = 0;
    if (arg0 != NULL && (M2C_FIELD(arg0, volatile s16 *, 0x70) & 1)) {
        var_r1 = 1;
    }
    if (var_r1 == 0) {
        return -39;
    }
    temp_r0 = M2C_FIELD(arg0, s8 *, 0x73);
    var_r1_2 = 1;
    if (temp_r0 != 0 && temp_r0 != 4) {
        var_r1_2 = 0;
    }
    if (var_r1_2 != 0) {
        if (!(M2C_FIELD(arg0, s16 *, 0x70) & 4) || (M2C_FIELD(arg0, s16 *, 0x70) & 8)) {
            return -56;
        }
    }
    temp_r4 = (s32) M2C_FIELD(arg0, void **, 0x68);
    if (!(arg5 & 4) && M2C_FIELD(arg0, s8 *, 0x72) == 0) {
        if (func_02006680(temp_r4 + 0xE0) == 0) {
            return -6;
        }
        var_ip = 0;
    } else {
        func_02006564(temp_r4 + 0xE0);
        var_ip = 1;
    }
    temp_r5 = func_0202058c(arg0, arg1, arg2, arg3, arg4, var_ip);
    func_020065e8(temp_r4 + 0xE0);
    return temp_r5;
}

s32 func_0202058c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_02020690(void *, s32, s32, s32 *, s32);
    s32 func_02020738(void *, s32, s32, s32, s32, s32, s32);
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 var_r5;
    s32 var_r8;
    s32 var_r9;
    s32 var_r11;

    spC = arg3;
    var_r9 = arg1;
    var_r8 = arg2;
    temp_r0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0x10C), s32 *, 0x48);
    var_r5 = 0;
    if (M2C_FIELD(arg0, s8 *, 0x73) == 1) {
        if (var_r8 > temp_r0 - 0x2A) {
            return -0x23;
        }
        sp10 = var_r8;
    } else {
        temp_r0_2 = temp_r0 - 0x36;
        sp10 = temp_r0_2;
        if (var_r8 <= temp_r0_2) {
            sp10 = var_r8;
        }
    }
    if (var_r8 > 0) {
        var_r11 = arg5 & 1;
        do {
            temp_r0_3 = func_02020690(arg0, var_r8, sp10, &sp14, arg5);
            if (temp_r0_3 > 0) {
                if (func_02020738(arg0, var_r9, temp_r0_3, sp14, spC, arg4, arg5) <= 0) {
                    return -6;
                }
                var_r9 += temp_r0_3;
                var_r8 -= temp_r0_3;
                var_r5 += temp_r0_3;
            }
            if (var_r11 == 0 && temp_r0_3 <= 0) {
                return -6;
            }
        } while (var_r8 > 0);
    }
    return var_r5;
}

#pragma dont_inline reset

s32 func_02020690(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4) {
    M2C_UNK func_02005da4(void *);
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    s32 func_02020714(void *);
    s32 temp_r11;
    void *temp_r4;
    s32 var_r8;
    s32 var_r5;

    var_r8 = arg2;
    temp_r4 = M2C_FIELD(arg0, void **, 0x68);
    if (var_r8 > arg1) {
        var_r8 = arg1;
    }
    temp_r11 = func_0200751c();
loop_3:
    var_r5 = func_02020714(arg0);
    if (var_r5 >= var_r8) {
        if (var_r5 >= arg1) {
            var_r5 = arg1;
        }
        *arg3 = (s32) M2C_FIELD(temp_r4, u16 *, 0x100);
    } else if (!(arg4 & 1)) {
        var_r5 = 0;
    } else {
        func_02005da4(temp_r4 + 0x104);
        goto loop_3;
    }
    func_02007530(temp_r11);
    return var_r5;
}

s32 func_02020714(void *arg0) {
    volatile u16 *q = M2C_FIELD(arg0, void **, 0x68) + 0x100;
    s32 c = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0xf8);
    s32 a = q[0];
    s32 b = q[1];
    b = b - a - 1;
    if (b < 0) b += c;
    return b;
}

