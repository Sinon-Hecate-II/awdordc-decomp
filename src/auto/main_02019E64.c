/* 29 functions from 0x02019E64 to 0x0201AE0C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 dest[6],src[6];u16 type;u8 pad14,hw;u8 proto,pad17;u16 sizes;u8 pad20,op;u8 sender[6];u16 shi,slo;u8 target[6];u16 thi,tlo; } Packet0201ACA0;

typedef struct {
    u16 tag;
    u8 pad[4];
    u16 extra;
} Func0201A09CBuf;

s32 func_02019e64(void *arg0, s32 *arg1, u8 *arg2, s32 *arg3, M2C_UNK (*arg4)(M2C_UNK, M2C_UNK, s32 *, s32 *)) {
    extern u16 data_020f5574[];

    register void *out asm("r10") = arg0;
    register s32 *outCountPtr asm("r11") = arg1;
    register u8 *in asm("r9") = arg2;
    register M2C_UNK (*cb)(M2C_UNK, M2C_UNK, s32 *, s32 *) asm("r8") = arg4;
    register s32 r6 asm("r6") = 0;
    register s32 r4 asm("r4") = 0;
    register s32 r7 asm("r7");
    register s32 r5 asm("r5");

    s32 limitPtr;
    s32 len;
    s32 flag;
    u16 unit;
    s32 newCursor;
    s32 rc;
    s32 oldOutPos;
    s32 lr;

    limitPtr = (s32)arg3;

    if (in == 0) {
        return 2;
    }

    if (limitPtr != 0) {
        r7 = *(s32 *)limitPtr;
        if (r7 < 0) {
            r7 = 0x7fffffff;
        }
    } else {
        r7 = 0x7fffffff;
    }

    if (out != 0 && outCountPtr != 0) {
        r5 = *outCountPtr;
        if (r5 < 0) {
            r5 = 0x7fffffff;
        }
    } else {
        r5 = 0x7fffffff;
    }

outer:
    {
        u8 b = in[r6];
        u8 *cur = in + r6;
        u8 u = b;

        flag = 0;
        len = 1;

        if (u == 0) {
            return 0;
        }

        if (u <= 0x7e) {
            unit = u;
            len = 1;
            flag = 1;
        } else if (u >= 0xa1 && u <= 0xdf) {
            unit = (u16)(u + 0x3EC0 + 0xC000);
            len = 1;
            flag = 1;
        } else {
            int t = (((int)u & 0xff) ^ 0x20) - 0xa1;
            len = 2;
            if (t >= 0 && t < 0x3c) {
                signed char nb = (signed char)in[r6 + 1];
                if (nb != (signed char)0x7f) {
                    u8 r12 = (u8)(nb - 0x40);
                    if (r12 <= 0xbc) {
                        if (r6 + 2 <= r7) {
                            u8 nxt = in[r6 + 1];
                            s32 thr = ((u >= 0xe0) ? 0x40 : 0x00) + 0x81;
                            s32 cp = (u - thr) * 0xc0 + nxt;
                            unit = data_020f5574[cp - 0x40];
                            if (unit != 0) {
                                flag = 1;
                            }
                        }
                    }
                }
            }
        }

        if (flag == 0) {
            if (cb == 0) {
                return 3;
            }
            len = r7 - r6;
            unit = 0;
            flag = 4;
            rc = cb(&unit, &flag, (void *)(in + r6), &len);
            if (rc != 0) {
                return rc;
            }
            newCursor = r6 + len;
            if (newCursor > r7) {
                return 0;
            }
            oldOutPos = r4;
            r4 = r4 + flag;
            if (r4 > r5) {
                return 0;
            }
            if (out != 0 && flag > 0) {
                lr = 0;
                while (lr < flag) {
                    u16 w = ((u16 *)&unit)[lr];
                    s32 idx = oldOutPos + lr;
                    u8 *dst = (u8 *)out + idx * 2;
                    dst[0] = (u8)(w & 0xff);
                    dst[1] = (u8)((w >> 8) & 0xff);
                    lr += 1;
                }
            }
            r6 = newCursor;
        } else {
            oldOutPos = r4;
            if (out != 0 && flag > 0) {
                lr = 0;
                while (lr < flag) {
                    u16 w = ((u16 *)&unit)[lr];
                    s32 idx = oldOutPos + lr;
                    u8 *dst = (u8 *)out + idx * 2;
                    dst[0] = (u8)(w & 0xff);
                    dst[1] = (u8)((w >> 8) & 0xff);
                    lr += 1;
                }
            }
            r4 = r4 + flag;
            if (r4 > r5) {
                r6 = r6 + len;
                return 0;
            }
            r6 = r6 + len;
        }

        if (!(r4 < r5 && r6 < r7)) {
            return 0;
        }
        goto outer;
    }
}

s32 func_0201a09c(u8 *r0) {
    void func_02008048(void *, void *, s32);
    void func_020067c4(void *, s32);
    Func0201A09CBuf buf;
    if (r0 == NULL) return 0;
    if (*(u16 *)(r0 + 0x3C) == 0) return 0;
    func_02008048(r0 + 0x50, &buf, 8);
    func_020067c4(&buf, 8);
    if (*(s32 *)(r0 + 0x44) == 0) {
        if (*(volatile u16 *)&buf.tag == 0x2348 || *(volatile u16 *)&buf.tag == 0xBD8A) {
            if (buf.extra == 4) return 1;
        }
    }
    return 0;
}

void func_0201a134(s32 arg0) {
    extern M2C_UNK data_02137290;
    extern M2C_UNK data_02137310;
    extern M2C_UNK data_0212dca4;
    extern M2C_UNK data_021375b8;
    void func_02007f8c(void *, s32, s32);
    void func_02005e5c(s32);
    void func_02025298(void);
    s32 old;
    void *node;
    void *sub;
    u8 t;
    void *fld4;
    s32 i;
    u8 *p;
    void (*fp)(u32);
    u32 val;
    old = M2C_FIELD(&data_02137290, s32 *, 0x50);
    M2C_FIELD(&data_02137290, s32 *, 0x0C) = arg0;
    M2C_FIELD(&data_02137290, s32 *, 0x50) = 0;
    M2C_FIELD(&data_02137290, s32 *, 0x1C) = 0;
    M2C_FIELD(&data_02137290, s32 *, 0x2C) = 0;
    M2C_FIELD(&data_02137290, s32 *, 0x60) = 0;
    M2C_FIELD(&data_02137290, s32 *, 0x64) = 0;
    M2C_FIELD(&data_02137290, s32 *, 0x20) = 0;
    if (old == 0) {
        return;
    }
    func_02007f8c(&data_02137310, 0, 0x60);
    node = M2C_FIELD(&data_0212dca4, void **, 0x08);
    while (node != 0) {
        sub = M2C_FIELD(node, void **, 0xA4);
        if (sub != 0) {
            if (M2C_FIELD(sub, void **, 0x00) != 0) {
                t = M2C_FIELD(sub, u8 *, 0x08);
                if (t != 0x0A && t != 0x0B) {
                    M2C_FIELD(sub, u8 *, 0x08) = 0;
                }
                fld4 = M2C_FIELD(sub, void **, 0x04);
                if (fld4 != 0) {
                    M2C_FIELD(sub, void **, 0x04) = 0;
                    func_02005e5c((s32)M2C_FIELD(sub, void **, 0x00));
                }
            }
        }
        node = M2C_FIELD(node, void **, 0x68);
    }
    i = 0;
    p = (u8 *)&data_021375b8;
    for (; i < 8; i++, p += 0x38) {
        if (M2C_FIELD(p, u16 *, 0x04) != 0) {
            fp = (void (*)(u32)) M2C_FIELD(&data_02137290, void **, 0x40);
            val = M2C_FIELD(p, u32 *, 0x34);
            fp(val);
            M2C_FIELD(p, u16 *, 0x04) = 0;
        }
    }
    func_02025298();
}

void func_0201a238(void) {
    extern M2C_UNK data_02137290;
    void func_02005ec8(void);
    void func_02006030(s32);
    s32 f = M2C_FIELD(&data_02137290, s32 *, 0x24);
    if (f == 0) {
        func_02005ec8();
    } else {
        func_02006030(f);
    }
}

void func_0201a260(void) {

}

s32 func_0201a264(void) {
    return 1;
}

void func_0201a26c(void *arg0) {
    void func_02000b9c(s32);
    unsigned long long func_02007004(void);
    void func_02007724(s32);
    void func_02005ac0(void *, void *, s32, void *, s32, s32);
    void func_02005e5c(s32);
    s32 func_0201a264(void);
    void func_0201dd08(void);
    extern s32 data_02137290;
    extern s32 data_02137778;
    extern s32 data_020faf74;
    extern s32 data_021374f8;
    extern s32 data_02138ac0;
    extern s32 data_02137438;
    extern s32 data_021382c0;

    u8 *d = (u8 *)&data_02137290;
    func_02000b9c(0x2000bdc);

    {
        s32 r3 = M2C_FIELD(arg0, s32 *, 0x18);
        s32 r5 = M2C_FIELD(arg0, s32 *, 0x14);
        if (r3 == 0 || r5 == 0) {
            unsigned long long t = func_02007004();
            M2C_FIELD(d, s32 *, 0x68) = (s32)t;
            M2C_FIELD(d, s32 *, 0x6c) = (s32)(t >> 32);
            M2C_FIELD(d, s32 *, 0x70) = 0x6c078965;
            M2C_FIELD(d, s32 *, 0x74) = 0x5d588b65;
            M2C_FIELD(d, s32 *, 0x78) = 0x269ec3;
            M2C_FIELD(d, s32 *, 0x7c) = 0;
        } else {
            M2C_FIELD(d, s32 *, 0x68) = r5;
            M2C_FIELD(d, s32 *, 0x6c) = r3;
            M2C_FIELD(d, s32 *, 0x70) = 0x6c078965;
            M2C_FIELD(d, s32 *, 0x74) = 0x5d588b65;
            M2C_FIELD(d, s32 *, 0x78) = 0x269ec3;
            M2C_FIELD(d, s32 *, 0x7c) = 0;
        }
    }

    {
        s32 v4 = M2C_FIELD(arg0, s32 *, 0x4);
        s32 v8 = M2C_FIELD(arg0, s32 *, 0x8);
        if (v4 != 0 && v8 != 0) {
            M2C_FIELD(d, s32 *, 0x14) = v4;
        } else {
            M2C_FIELD(d, s32 *, 0x14) = 0x5b4;
            M2C_FIELD(d, s32 *, 0x40) = 0x5b4;
        }
    }

    M2C_FIELD(d, s32 *, 0x10) = M2C_FIELD(arg0, s32 *, 0x0);

    {
        s32 f24 = M2C_FIELD(arg0, s32 *, 0x24);
        if (f24 == 0) f24 = 0xf88;
        M2C_FIELD(d, s16 *, 0x2) = (s16)f24;
    }
    M2C_FIELD(d, s32 *, 0x34) = M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(d, s32 *, 0x24) = M2C_FIELD(arg0, s32 *, 0x2c);

    {
        s32 fc = M2C_FIELD(arg0, s32 *, 0xc);
        if (fc == 0) fc = 0x5b4;
        M2C_FIELD(d, s32 *, 0x18) = fc;
    }

    {
        s32 f10 = M2C_FIELD(arg0, s32 *, 0x10);
        if (f10 != 0) {
            M2C_FIELD(d, s32 *, 0x48) = f10;
        } else {
            M2C_FIELD(d, s32 *, 0x48) = (s32)func_0201a264;
        }
    }

    M2C_FIELD(d, s32 *, 0x58) = M2C_FIELD(arg0, s32 *, 0x1c);
    M2C_FIELD(d, s32 *, 0x5c) = M2C_FIELD(arg0, s32 *, 0x20);
    M2C_FIELD(d, s32 *, 0x30) = 0;
    M2C_FIELD(d, s32 *, 0x28) = 0;

    {
        u32 A = M2C_FIELD(d, u32 *, 0x70);
        u32 B = M2C_FIELD(d, u32 *, 0x68);
        u32 C = M2C_FIELD(d, u32 *, 0x6c);
        u32 D = M2C_FIELD(d, u32 *, 0x74);
        u32 E = M2C_FIELD(d, u32 *, 0x78);
        u32 F = M2C_FIELD(d, u32 *, 0x7c);
        u32 r1 = (u32)&data_02137778;
        u32 r0v = 0;
        unsigned long long lowpart = (unsigned long long)A * B;
        unsigned long long mid1 = (unsigned long long)A * C;
        unsigned long long mid2 = (unsigned long long)D * B;
        u32 lowlo = (u32)lowpart;
        u32 lowhi = (u32)(lowpart >> 32);
        u32 hi = lowhi + (u32)mid1 + (u32)mid2;
        u32 carry = (E + lowlo < E) ? 1 : 0;
        u32 r12 = E + lowlo;
        u32 r5 = F + hi + carry;
        u32 r4 = (u32)((unsigned long long)r5 * r1);
        r4 = r4 + r5 * r0v + r0v * r1;
        M2C_FIELD(d, u32 *, 0x68) = r12;
        M2C_FIELD(d, u32 *, 0x6c) = r5;
        M2C_FIELD(d, u16 *, 0x8) = (u16)(r4 + 0x400);
        func_02007724(0);
    }

    M2C_FIELD(d, u8 *, 0x1) = 0;
    {
        func_02005ac0((void *)&data_02137438, (void *)&data_02138ac0, 0, (void *)&data_021382c0, 0x800, M2C_FIELD(data_021374f8, s32 *, 0));
        func_02005ac0((void *)&data_02137438, (void *)&func_0201dd08, 0, (void *)&data_021382c0, 0x800, M2C_FIELD(data_021374f8, s32 *, 0));
    }
    func_02005e5c((s32)&data_02137438);
    func_02005e5c((s32)&data_02137438);
}

#pragma opt_common_subs off
void *func_0201a4a8(void) {
s32 func_0200751c(void);void func_02007530(s32);s32 func_02005d90(s32);void func_02005e5c(s32);
extern M2C_UNK data_02137438;extern M2C_UNK data_02137290;
s32 saved=func_0200751c();
s32 result=func_02005d90((s32)&data_02137438);
if(result==0 && M2C_FIELD(&data_02137290,s32 *,0x44)==0) {
M2C_FIELD(&data_02137290,s32 *,0x44)=1;
func_02005e5c((s32)&data_02137438);
}
func_02007530(saved);return (void *)result;
}
#pragma opt_common_subs on

void func_0201a4f8(s32 arg0) {
    extern M2C_UNK data_02137290;
    M2C_FIELD(&data_02137290, s32 *, 0x3C) = arg0;
}

void func_0201a508(void){void *func_0201a4a8(void);void func_02005d60(void *);void func_02005ccc(void *);void func_0201a134(s32);extern M2C_UNK data_02137438,data_021374f8,data_02137290;func_0201a4a8();func_02005d60(&data_02137438);func_02005ccc(&data_021374f8);M2C_FIELD(&data_02137290,s32 *,84)=0;func_0201a134(0);M2C_FIELD(&data_02137290,s32 *,88)=0;M2C_FIELD(&data_02137290,s32 *,92)=0;}

void func_0201a550(s32 arg0) {
    M2C_UNK func_02005f80(M2C_UNK *, s32);
    extern s32 data_020faf74;
    extern M2C_UNK data_02137438;
    extern M2C_UNK data_021374f8;
    data_020faf74 = arg0;
    func_02005f80(&data_021374f8, arg0);
    func_02005f80(&data_02137438, arg0);
}

u32 func_0201a588(u8 *p,u32 n,u32 sum){u32 v;if((u32)p&1){while(n>1){sum+=(u16)((p[0]<<8)|p[1]);n-=2;p+=2;}}else{v=(u16)sum;sum=(u16)(((s32)v>>8)|(v<<8));while(n>1){sum+=*(u16 *)p;p+=2;n-=2;}v=((sum>>8)&0x00ff00ff)|((sum<<8)&0xff00ff00);sum=(v>>16)|(v<<16);}if(n)sum+=*p<<8;v=(u16)sum+(sum>>16);v+=v>>16;return (u16)v;}

s32 func_0201a63c(s32 arg0) {
    u16 var_r0;

    var_r0 = arg0 ^ 0xFFFF;
    if (var_r0 == 0) {
        var_r0 = 0xFFFF;
    }
    return (s32) var_r0;
}

void func_0201a658(M2C_UNK arg0, M2C_UNK arg1) {
    func_0201a63c((u16)func_0201a588((u8 *)arg0, (u32)arg1, 0));
}

s32 func_0201a674(u8 *a,s32 b,u8 *c,u32 d){u32 r;r=func_0201a588(c+12,8,func_0201a588(a,b,d));r+=b;if(r&0x10000)r=(u16)(r+1);return r!=65535;}

s32 func_0201a6c4(s32 a){extern M2C_UNK data_02137290;s32 r=1;if(a!=-1&&a!=0x7f000001){s32 mask=M2C_FIELD(&data_02137290,s32 *,28);if((a&mask)!=(M2C_FIELD(&data_02137290,s32 *,80)&mask))r=0;}return r;}

s32 func_0201a704(s32 a){s32 func_0201a6c4(s32);extern M2C_UNK data_02137290;if(!func_0201a6c4(a))a=M2C_FIELD(&data_02137290,s32 *,44);return a;}

s32 func_0201a728(s32 a){extern M2C_UNK data_02137290;s32 r=0;if(func_0201a6c4(a)){s32 m=~M2C_FIELD(&data_02137290,s32 *,28);if(m==(m&a))r=1;}return r;}

s32 func_0201a764(s32 arg0) {
    if ((arg0 & 0xF0000000) == 0xE0000000) {
        return 1;
    }
    return 0;
}

s32 func_0201a778(s32 a){extern M2C_UNK data_02137290;s32 r=1,s=1,t=1,u=1; s32 own=M2C_FIELD(&data_02137290,s32 *,80);if(own!=0&&a!=own)u=0;if(!u&&a!=0x7f000001)t=0;if(!t&&!func_0201a728(a))s=0;if(!s&&!func_0201a764(a))r=0;return r;}

s32 func_0201a7f8(u16 *a,u16 *b){s32 i=0;do{if(*a++!=*b++)return 1;i++;}while(i<3);return 0;}

void func_0201a824(u8 *a,s32 b,s32 c,s32 d){void func_02008048(void *,void *,s32);s32 func_02029848(void *,void *,s32,s32,s32);extern M2C_UNK data_020faf80,data_02137290;func_02008048(&data_020faf80,a+6,6);M2C_FIELD(&data_02137290,u8 *,0)=func_02029848(a,a+6,b-6,c,d)<0;}

void func_0201a880(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    extern M2C_UNK data_02137290;
    extern M2C_UNK data_020faf80;
    void func_02008048(void *, void *, s32);
    u32 len;
    u32 n;
    u32 end;
    u32 newOfs;
    u8 *buf;

    buf = M2C_FIELD(&data_02137290, u8 **, 0x58);
    if (buf == NULL || M2C_FIELD(&data_02137290, volatile u32 *, 0x5c) == 0) {
        return;
    }
    len = (u32)a3 + (u32)a5;
    if (len < 8 || len > 0x5e4) {
        return;
    }
    if (((u8 *)a2)[0] != M2C_FIELD(&data_020faf80, u8 *, 0) || ((u8 *)a2)[1] != M2C_FIELD(&data_020faf80, u8 *, 1) ||
        ((u8 *)a2)[2] != M2C_FIELD(&data_020faf80, u8 *, 2) || ((u8 *)a2)[6] != 8) {
        return;
    }
    if (((u8 *)a2)[7] != 0 && ((u8 *)a2)[7] != 6) {
        return;
    }
    n = (u16)((len + 9) & ~1);
    end = M2C_FIELD(&data_02137290, volatile u32 *, 0x28) + n;
    if (M2C_FIELD(&data_02137290, volatile u32 *, 0x28) < M2C_FIELD(&data_02137290, volatile u32 *, 0x30)) {
        if (M2C_FIELD(&data_02137290, volatile u32 *, 0x30) <= end) {
            return;
        }
    }
    if (end == M2C_FIELD(&data_02137290, volatile u32 *, 0x5c)) {
        newOfs = 0;
        if (M2C_FIELD(&data_02137290, volatile u32 *, 0x30) == 0) {
            return;
        }
    } else if (end > M2C_FIELD(&data_02137290, volatile u32 *, 0x5c)) {
        newOfs = n;
        if (M2C_FIELD(&data_02137290, volatile u32 *, 0x30) <= n) {
            return;
        }
    } else {
        newOfs = end;
    }
    if (M2C_FIELD(&data_02137290, volatile u32 *, 0x28) + n > M2C_FIELD(&data_02137290, volatile u32 *, 0x5c)) {
        if (M2C_FIELD(&data_02137290, volatile u32 *, 0x5c) - M2C_FIELD(&data_02137290, volatile u32 *, 0x28) >= 2) {
            *(u16 *)(buf + M2C_FIELD(&data_02137290, volatile u32 *, 0x28)) = 0;
        }
        M2C_FIELD(&data_02137290, volatile u32 *, 0x28) = 0;
    }
    *(u16 *)(M2C_FIELD(&data_02137290, u8 **, 0x58) + M2C_FIELD(&data_02137290, volatile u32 *, 0x28)) = (u16)n;
    func_02008048((void *)a1, M2C_FIELD(&data_02137290, u8 **, 0x58) + M2C_FIELD(&data_02137290, volatile u32 *, 0x28) + 2, 6);
    func_02008048((void *)a0, M2C_FIELD(&data_02137290, u8 **, 0x58) + M2C_FIELD(&data_02137290, volatile u32 *, 0x28) + 8, 6);
    func_02008048((u8 *)a2 + 6, M2C_FIELD(&data_02137290, u8 **, 0x58) + M2C_FIELD(&data_02137290, volatile u32 *, 0x28) + 0xe, a3 - 6);
    if (a4 != 0 && a5 != 0) {
        func_02008048((void *)a4, M2C_FIELD(&data_02137290, u8 **, 0x58) + M2C_FIELD(&data_02137290, volatile u32 *, 0x28) + 8 + a3, a5);
    }
    M2C_FIELD(&data_02137290, volatile u32 *, 0x28) = newOfs;
}

void func_0201aa74(s32 a,s32 b,s32 c,s32 d){void func_0201a880(s32,s32,s32,s32,s32,s32);s32 func_02005d90(s32);void func_02005e5c(s32);extern M2C_UNK data_02137290;func_0201a880(a,b,c,d,0,0);if(!M2C_FIELD(&data_02137290,volatile s32 *,84))return;if(func_02005d90(M2C_FIELD(&data_02137290,volatile s32 *,84)))return;func_02005e5c(M2C_FIELD(&data_02137290,volatile s32 *,84));}

u8 *func_0201aacc(s32 *out){s32 func_0200751c(void);void func_02007530(s32);void func_02005da4(s32);extern M2C_UNK data_02137290,data_0212dca4;s32 key;u32 size;u8 *p;u32 len;key=func_0200751c();while(M2C_FIELD(&data_02137290,u32 *,48)==M2C_FIELD(&data_02137290,u32 *,40)){M2C_FIELD(&data_02137290,s32 *,84)=M2C_FIELD(&data_0212dca4,s32 *,4);func_02005da4(0);M2C_FIELD(&data_02137290,s32 *,84)=0;}func_02007530(key);p=M2C_FIELD(&data_02137290,u8 **,88);do{size=M2C_FIELD(&data_02137290,u32 *,92);if(size-M2C_FIELD(&data_02137290,u32 *,48)<2)M2C_FIELD(&data_02137290,u32 *,48)=0;len=M2C_FIELD(p,u16 *,M2C_FIELD(&data_02137290,u32 *,48));if(!len)M2C_FIELD(&data_02137290,u32 *,48)=0;}while(!len);*out=len-2;return M2C_FIELD(&data_02137290,u8 **,88)+M2C_FIELD(&data_02137290,u32 *,48)+2;}

#pragma opt_strength_reduction off
void func_0201ab8c(void){
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_02137290;
    s32 key;
    u32 old;
    u8 *buf;
    key = func_0200751c();
    old = M2C_FIELD(&data_02137290, volatile u32 *, 0x30);
    buf = (u8 *)M2C_FIELD(&data_02137290, u8 **, 0x58);
    M2C_FIELD(&data_02137290, volatile u32 *, 0x30) = old + M2C_FIELD(buf, u16 *, M2C_FIELD(&data_02137290, volatile u32 *, 0x30));
    if (M2C_FIELD(&data_02137290, volatile u32 *, 0x30) >= M2C_FIELD(&data_02137290, u32 *, 0x5c)) M2C_FIELD(&data_02137290, volatile u32 *, 0x30) = 0;
    func_02007530(key);
}
#pragma opt_strength_reduction reset
s32 func_0201abd0(s32 a){extern M2C_UNK data_02137290,data_02137778,data_020faf78,data_02137310,data_0213731a;s32 func_0200751c(void);void func_02007530(s32);u64 func_02007004(void);s32 irq=func_0200751c();u32 i;void *r=0;u8 *p;if(a==0x7f000001 || a==M2C_FIELD(&data_02137290,s32 *,0x50))r=&data_02137778;else if(func_0201a728(a)||func_0201a764(a))r=&data_020faf78;else{p=(u8 *)&data_02137310;for(i=0;i<8;i++,p+=12){if(a==*(s32 *)p){a=func_02007004()>>16;M2C_FIELD(&data_0213731a,u16 *,i*12)=a;r=(u8 *)&data_02137310+i*12+4;break;}}}func_02007530(irq);return (s32)r;}

/* Build and send a 42-byte ARP-style announcement packet for `nodeId`, swapping byte order in the id fields. */
void func_0201aca0(s32 nodeId) {
    extern M2C_UNK data_02137778;
    extern M2C_UNK data_02137290;
    void func_02007f8c(void *, s32, s32);
    void func_02008048(void *, void *, s32);
    Packet0201ACA0 packet;
    s32 hi;
    s32 lo;
    s32 ahi;
    s32 alo;
    u32 own;
    func_02007f8c(&packet, 0, 42);
    func_02007f8c(packet.dest, 255, 6);
    func_02008048(&data_02137778, packet.src, 6);
    packet.type = 0x608;
    packet.hw = 1;
    packet.proto = 8;
    packet.sizes = 0x406;
    packet.op = 1;
    func_02008048(&data_02137778, packet.sender, 6);
    own = M2C_FIELD(&data_02137290, u32 *, 80);
    hi = (u16)(own >> 16);
    lo = (u16)own;
    ahi = (u16)((u32)nodeId >> 16);
    alo = (u16)nodeId;
    packet.shi = (hi >> 8) | (hi << 8);
    packet.slo = (lo >> 8) | (lo << 8);
    packet.thi = (ahi >> 8) | (ahi << 8);
    packet.tlo = (alo >> 8) | (alo << 8);
    func_0201a824((u8 *)&packet, 42, 0, 0);
}

s32 func_0201ad9c(s32 a){void func_0201aca0(s32);void func_02006030(s32);s32 func_0201abd0(s32);extern M2C_UNK data_02137290;u32 i,j;s32 r;for(i=0;i<8;i++){func_0201aca0(a);for(j=0;j<20;j++){if(!M2C_FIELD(&data_02137290,s32 *,80))return 0;func_02006030(100);r=func_0201abd0(a);if(r)return r;}}return 0;}

