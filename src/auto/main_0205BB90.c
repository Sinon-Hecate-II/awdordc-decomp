/* 26 functions from 0x0205BB90 to 0x0205CB68 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 a,b; s16 c,pad; s32 d; } Unk05Record;
typedef union { struct { s32 a,b; }; u64 whole; } Unk05Pair;
Unk05Pair *func_02048690(s32,s32);

s32 func_0205bb90(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_0205b100(u16, s32);
    s32 func_0205b1b8(s32);
    s32 func_0205b79c(void *, s32, s32, s32);
    s32 func_0205b8b0(void *, s32, s32, s32, s32, s32 *);
    s32 func_0205bae8(void *);
    void func_0205bb68(void *);
    s32 sp8;
    s32 kind;
    s32 result;
    if (arg3 < 7) {
 if (func_0205b1a4(arg0)) result=1; else result=0;
 return result;
}
    kind = func_0205b0cc(arg2, 3);
    if (!func_0205b1e4((s32)arg0, func_0205b0cc(arg2, 5))) return 0;
    if (kind == M2C_FIELD(arg0, u16 *, 0x66)) {
        func_0205bb68(arg0);
        if (!func_0205b79c(arg0,arg1,arg2+7,arg3-7)) return 0;
        if (func_0205bae8(arg0)) result=1; else result=0;
 return result;
    }
    if (((s32 (*)(s32,s32))func_0205b100)(kind,M2C_FIELD(arg0,u16 *,0x66)) < 0) {
        func_0205bb68(arg0);
        return 1;
    }
    if (!func_0205b8b0(arg0,arg1,kind,arg2+7,arg3-7,&sp8)) return 0;
    if (sp8 && !func_0205b1b8((s32)arg0)) return 0;
    return 1;
}

s32 func_0205bcdc(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_0205b0cc(M2C_UNK, M2C_UNK);
    s32 func_0205b1a4();
    s32 func_0205b1e4(M2C_UNK, s32);
    s32 var_r0;

    if (arg2 != 2) {
        if (func_0205b1a4() != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    }
    if (func_0205b1e4(arg0, func_0205b0cc(arg1, 0)) != 0) {
        return 1;
    }
    return 0;
}

s32 func_0205bd28(void *arg0, void *arg1, s32 arg2) {
    s32 func_02048688(s32);
    s32 func_0205b100(u16, s32);
    s32 func_0205cbb4(void *, void *);
    s32 lo;
    s32 hi;
    s32 n;
    s32 i;
    void *p;

    lo = func_0205b0cc((s32)arg1, 0);
    if (arg2 == 2) {
        hi = lo;
    } else if (arg2 == 4) {
        hi = func_0205b0cc((s32)arg1, 2);
    } else {
        return func_0205b1a4(arg0) != 0;
    }
    n = func_02048688(M2C_FIELD(arg0, s32 *, 0x60));
    for (i = 0; i < n; i++) {
        p = func_02048690(M2C_FIELD(arg0, s32 *, 0x60), i);
        if ((func_0205b100(M2C_FIELD(p, u16 *, 8), lo) >= 0) &&
            (func_0205b100(M2C_FIELD(p, u16 *, 8), hi) <= 0) &&
            (func_0205cbb4(arg0, p) == 0)) {
            return 0;
        }
    }
    return 1;
}

s32 func_0205be04(s32 a, void *b, s32 c) {
    s32 func_0205cb38(s32, void *, s32);
    return func_0205cb38(a,b,c);
}

s32 func_0205be10(void *arg0,void *arg1,s32 arg2) { s32 func_02049208(); s32 func_0205a360(void *,s32); s32 func_0206527c(void *,M2C_UNK *,s32); extern M2C_UNK data_020ff810; s32 sp0; u8 a,b; volatile u8 *dst; if(!M2C_FIELD(arg0,s32 *,0x34))return 1;if(arg2!=8)return 1;if(func_0206527c(arg1,&data_020ff810,4))return 1; dst=(volatile u8 *)&sp0; a=M2C_FIELD(arg1,volatile u8 *,4);b=M2C_FIELD(arg1,volatile u8 *,5);M2C_FIELD(dst,volatile u8 *,0)=a;M2C_FIELD(dst,volatile u8 *,1)=b;a=M2C_FIELD(arg1,volatile u8 *,6);b=M2C_FIELD(arg1,volatile u8 *,7);M2C_FIELD(dst,volatile u8 *,2)=a;M2C_FIELD(dst,volatile u8 *,3)=b; return func_0205a360(arg0,func_02049208()-sp0)!=0; }

s32 func_0205bea4(void *arg0) {
    s32 func_0205b110(void *, M2C_UNK, M2C_UNK);
    M2C_UNK var_r2;
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0xC);
    if (temp_r1 == 7) {
        return 1;
    }
    if (temp_r1 == 6) {
        var_r2 = 0;
    } else {
        var_r2 = 1;
    }
    if (func_0205b110(arg0, 2, var_r2) == 0) {
        return 0;
    }
    return 1;
}

s32 func_0205bedc(void *arg0,s32 arg1,void *arg2,s32 arg3) { s32 func_0205bd28(void *,void *,s32); s32 len=arg3-3; if(arg1==100) {if(!func_0205bcdc((s32)arg0,(s32)((char *)arg2+3),len))return 0;} else if(arg1==101) {if(!func_0205bd28(arg0,(char *)arg2+3,len))return 0;} else if(arg1==102) {if(!func_0205be04((s32)arg0,arg2,arg3))return 0;} else if(arg1==103) {if(!func_0205be10(arg0,(char *)arg2+3,len))return 0;} else if(arg1==104) {if(!func_0205bea4(arg0))return 0;} return 1; }

/* Looks up the entry for the given connection/key; validates or refreshes it. */
s32 func_0205c244(void *conn, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_02049208();
    s32 func_0205a614(void *, void *, M2C_UNK, M2C_UNK, s32, s32, s32, s32);
    s32 func_0205b110(void *, M2C_UNK, M2C_UNK);
    void *func_0205cca0();
    void *entry;

    entry = func_0205cca0();
    if ((M2C_FIELD(conn, s32 *, 0x2C) != 0) &&
        (func_0205a614(conn, entry, arg1, arg2, 1, 0, 0, 0) == 0)) {
        return 0;
    }
    if (entry == NULL) {
        return 1;
    }
    if (M2C_FIELD(entry, s32 *, 0xC) == 0) {
        if ((M2C_FIELD(entry, u32 *, 0x20) == 0) ||
            ((u32)(func_02049208() - M2C_FIELD(entry, u32 *, 0x1C)) < M2C_FIELD(entry, u32 *, 0x20))) {
            return 1;
        }
        if (func_0205b110(entry, 6, 1) == 0) {
            return 0;
        }
    } else {
        if (func_0205b110(entry, 2, 1) == 0) {
            return 0;
        }
    }
    return 1;
}

s32 func_0205c344(void *conn) {
    s32 func_02049534(void *);
    s32 func_020497e0(void *, void *, s32, s32, void *, s32 *);
    s32 func_02049900(void);
    s32 func_0205c244(void *, M2C_UNK, M2C_UNK);
    void func_0205d49c(void *);
    s32 func_0205bf94(void *, void *, s32, M2C_UNK, M2C_UNK);

    s32 cnt;
    s32 val_c;
    M2C_UNK val_10;
    u8 buffer[0x5dc];
    s32 read;
    s32 x;

    if (func_02049534((void *)M2C_FIELD(conn, s32 *, 0)) == 0) {
        return 0;
    }

    cnt = 8;

    for (;;) {
        read = func_020497e0((void *)M2C_FIELD(conn, s32 *, 0), buffer, 0x5dc, 0,
                              (u8 *)&val_c, &cnt);
        if (read != -1) {
            u16 hv = *(u16 *)((char *)&val_c + 2);
            u16 bsw = (u16)(((hv >> 8) & 0xff) | ((hv << 8) & 0xff00));
            if (func_0205bf94(conn, buffer, read, val_10, bsw) == 0) {
                return 0;
            }
            if (func_02049534((void *)M2C_FIELD(conn, s32 *, 0)) == 0) {
                return 1;
            }
        } else {
            x = func_02049900();
            if (x == -15) {
                u16 hv = *(u16 *)((char *)&val_c + 2);
                u16 bsw = (u16)(((hv >> 8) & 0xff) | ((hv << 8) & 0xff00));
                func_0205c244(conn, val_10, bsw);
                return 0;
            }
            if (x != -35) {
                func_0205d49c(conn);
            }
            return 0;
        }
    }
}

s32 func_0205c474(void *p,s16 a,s32 b){Unk05Record s={0};s32 n;s.a=M2C_FIELD(p,s32 *,0x58);s.b=b;s.c=a;s.d=func_02049208();n=func_02048688(M2C_FIELD(p,s32 *,0x60));func_020486f8(M2C_FIELD(p,s32 *,0x60),&s);return n+1==func_02048688(M2C_FIELD(p,s32 *,0x60));}

s32 func_0205c4e8(M2C_UNK p, M2C_UNK mode, M2C_UNK arg2, s32 *status) {
    extern M2C_UNK data_020ff818;
    s32 func_02059d24(void *);
    s32 func_0205b1b8(M2C_UNK);
    s32 func_0205c474(void *, s16, s32);
    void func_02059df0(void *, M2C_UNK, s32);
    void func_02059d34(void *, s32);
    void func_02059d84(void *, s32);
    s32 free;

    free = func_02059d24((void *)((char *)p + 0x50));
    if (free < arg2) {
        s32 r = func_0205b1b8(p);
        if (r == 0) {
            return 0;
        }
        *status = 1;
        return 1;
    }
    if (!func_0205c474((void *)p, M2C_FIELD(p, u16 *, 0x64), arg2)) {
        s32 r = func_0205b1b8(p);
        if (r == 0) {
            return 0;
        }
        *status = 1;
        return 1;
    }
    func_02059df0((void *)((char *)p + 0x50), &data_020ff818, 2);
    func_02059d34((void *)((char *)p + 0x50), (s32)(mode & 0xff));
    {
        u16 old64 = M2C_FIELD(p, u16 *, 0x64);
        M2C_FIELD(p, u16 *, 0x64) = old64 + 1;
        func_02059d84((void *)((char *)p + 0x50), old64);
    }
    func_02059d84((void *)((char *)p + 0x50), M2C_FIELD(p, u16 *, 0x66));
    *status = 0;
    return 1;
}

s32 func_0205c5ac(s32 p){extern M2C_UNK data_020ff81c,data_020ff824,data_020ff7f8;s32 n=func_02048688(M2C_FIELD(p,s32 *,0x60));u64 pair; s32 lo,hi;s32 v;if(n<=0)func_020640a8(&data_020ff81c,&data_020ff824,&data_020ff7f8,0x475);pair=*(u64 *)func_02048690(M2C_FIELD(p,s32 *,0x60),n-1);lo=(u32)pair;hi=pair>>32;if(func_0205a9ec(p,lo+M2C_FIELD(p,s32 *,0x50),hi)){M2C_FIELD(p,s32 *,0x90)=0;v=1;}else v=0;return v;}

s32 func_0205c620(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 sp0;

    if (func_0205c4e8(arg0, 0, arg2 + 7, &sp0) == 0) {
        return 0;
    }
    if (sp0 != 0) {
        return 1;
    }
    func_02059df0(arg0 + 0x50, arg1, arg2);
    if (func_0205c5ac(arg0) != 0) {
        return 1;
    }
    return 0;
}

s32 func_0205c694(s32 arg0, M2C_UNK arg1) {
    M2C_UNK func_02059df0(s32, M2C_UNK, M2C_UNK);
    s32 sp0;

    if (func_0205c4e8(arg0, 1, 0x27, &sp0) == 0) {
        return 0;
    }
    if (sp0 != 0) {
        return 1;
    }
    func_02059df0(arg0 + 0x50, arg1, 0x20);
    if (func_0205c5ac(arg0) != 0) {
        return 1;
    }
    return 0;
}

s32 func_0205c6f4(s32 p,s32 a,s32 b){s32 s; s32 v;if(!func_0205c4e8(p,2,0x47,&s))return 0;if(s)return 1;func_02059df0(p+0x50,a,0x20);func_02059df0(p+0x50,b,0x20);if(func_0205c5ac(p)==0)v=0;else{M2C_FIELD(p,s32 *,0x8c)=M2C_FIELD(p,s32 *,0x88);v=1;}return v;}

s32 func_0205c780(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    s32 sp0;

    if (func_0205c4e8(arg0, 3, arg3 + 0x27, &sp0) == 0) {
        return 0;
    }
    if (sp0 != 0) {
        return 1;
    }
    func_02059df0(arg0 + 0x50, arg1, 0x20);
    func_02059df0(arg0 + 0x50, arg2, arg3);
    if (func_0205c5ac(arg0) != 0) {
        return 1;
    }
    return 0;
}

s32 func_0205c7f8(M2C_UNK arg0) {
    s32 func_0205c4e8(M2C_UNK, M2C_UNK, M2C_UNK, s32 *);
    s32 func_0205c5ac(M2C_UNK);
    s32 sp0;

    if (func_0205c4e8(arg0, 4, 7, &sp0) == 0) {
        return 0;
    }
    if (sp0 != 0) {
        return 1;
    }
    if (func_0205c5ac(arg0) != 0) {
        return 1;
    }
    return 0;
}

s32 func_0205c854(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 sp0;

    if (func_0205c4e8(arg0, 5, arg2 + 7, &sp0) == 0) {
        return 0;
    }
    if (sp0 != 0) {
        return 1;
    }
    func_02059df0(arg0 + 0x50, arg1, arg2);
    if (func_0205c5ac(arg0) != 0) {
        return 1;
    }
    return 0;
}

s32 func_0205c8c8(M2C_UNK arg0) {
    s32 sp0;

    if (func_0205c4e8(arg0, 6, 7, &sp0) == 0) {
        return 0;
    }
    if (sp0 != 0) {
        return 1;
    }
    if (func_0205c5ac(arg0) != 0) {
        return 1;
    }
    return 0;
}

s32 func_0205c924(M2C_UNK arg0) {
    s32 sp0;

    if (func_0205c4e8(arg0, 7, 7, &sp0) == 0) {
        return 0;
    }
    if (sp0 != 0) {
        return 1;
    }
    if (func_0205c5ac(arg0) != 0) {
        return 1;
    }
    return 0;
}

s32 func_0205c980(void *arg0, M2C_UNK *arg1, s32 arg2) {
    s32 func_02059d24(void *);
    s32 func_0206527c(void *, M2C_UNK *, s32);
    s32 func_0205a9ec(s32, void *, s32);
    M2C_UNK func_02059df0(M2C_UNK, M2C_UNK, M2C_UNK);
    void func_02059e78(void *, M2C_UNK, s32);
    extern M2C_UNK data_020ff818;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;

    if ((arg2 < 2) || (func_0206527c(arg1, &data_020ff818, 2) != 0)) {
        if (func_0205a9ec((s32)arg0, arg1, arg2) == 0) {
            return 0;
        }
        return 1;
    }
    temp_r6 = arg2 + 2;
    if (func_02059d24((void *)((char *)arg0 + 0x50)) < temp_r6) {
        return 1;
    }
    temp_r5 = M2C_FIELD(arg0, s32 *, 0x50);
    temp_r4 = M2C_FIELD(arg0, s32 *, 0x58);
    func_02059df0((M2C_UNK)((char *)arg0 + 0x50), (M2C_UNK)&data_020ff818, 2);
    func_02059df0((M2C_UNK)((char *)arg0 + 0x50), (M2C_UNK)arg1, arg2);
    if (func_0205a9ec((s32)arg0, (void *)(temp_r5 + temp_r4), temp_r6) == 0) {
        return 0;
    }
    func_02059e78((void *)((char *)arg0 + 0x50), -1, temp_r6);
    return 1;
}

s32 func_0205ca48(void *p){extern M2C_UNK data_020ff818;u8 buf[5];u8 a=M2C_FIELD(&data_020ff818,u8 *,0),b=M2C_FIELD(&data_020ff818,u8 *,1);s32 v;buf[2]=100;M2C_FIELD(buf,volatile u8 *,0)=a;M2C_FIELD(buf,volatile u8 *,1)=b;func_0205b0ec(buf,3,M2C_FIELD(p,u16 *,0x66));if(func_0205a9ec(p,buf,5)){M2C_FIELD(p,s32 *,0x90)=0;v=1;}else v=0;return v;}

s32 func_0205caac(void *p, s32 arg1, s32 arg2) {
    extern M2C_UNK data_020ff818;
    u8 buf[8];
    u8 a, b;
    s32 r6;
    buf[2] = 0x65;
    a = M2C_FIELD(&data_020ff818, u8 *, 0);
    b = M2C_FIELD(&data_020ff818, u8 *, 1);
    M2C_FIELD(buf, u8 *, 0) = a;
    M2C_FIELD(buf, u8 *, 1) = b;
    func_0205b0ec(buf, 3, arg1);
    r6 = 5;
    if (arg1 != arg2) {
        func_0205b0ec(buf, r6, arg2);
        r6 += 2;
    }
    if (func_0205a9ec(p, buf, r6) == 0) {
        return 0;
    }
    return 1;
}

s32 func_0205cb38(s32 a,void *b,s32 c) { s32 func_0205a9ec(s32,void *,s32); M2C_FIELD(b,u8 *,2)=103; return func_0205a9ec(a,b,c); }

void func_0205cb4c(void *arg0) {
    M2C_UNK func_0205cb68(s32, s32, u16);
    func_0205cb68(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, u16 *, 4));
}

