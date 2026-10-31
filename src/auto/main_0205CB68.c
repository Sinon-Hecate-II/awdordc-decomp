/* 30 functions from 0x0205CB68 to 0x0205DA30 (main), found by ds-decomp. */
#include "common.h"
struct BytePair_0205 { u8 v[2]; };
struct Packet_0205 { u8 a,b; u16 c; s32 d; };
struct SocketInit_0205 { u16 port; s32 len; s32 addr; struct Packet_0205 pkt; };

s32 func_0205cb68(s32 a, s32 b, s32 c) {
s32 func_0205d228(void *,s32,s32,void *,s32);
extern u8 data_020ff818[];
u8 v[3];
v[0]=data_020ff818[0];
v[2]=0x68;
v[1]=data_020ff818[1];
return func_0205d228((void *)a,b,c,v,3)!=0;
}

s32 func_0205cbb4(void *a, s32 *b) {
    void func_0205b0ec(void *, s32, u16);
    s32 func_0205a9ec(void *, void *, s32);
    func_0205b0ec(M2C_FIELD(a, void **, 0x50), b[0] + 5, M2C_FIELD(a, u16 *, 0x66));
    if (!func_0205a9ec(a, M2C_FIELD(a, u8 **, 0x50) + b[0], b[1])) return 0;
    b[3] = M2C_FIELD(a, s32 *, 0x88);
    if (M2C_FIELD(a, u8 **, 0x50)[b[0] + 2] == 2)
        M2C_FIELD(a, s32 *, 0x8c) = M2C_FIELD(a, s32 *, 0x88);
    return 1;
}

void func_0205cc20(s32 a, s32 b, s32 c, s32 d) {
    M2C_UNK func_0205c620();
    M2C_UNK func_0205c980();
    if (d) { func_0205c620(); return; }
    func_0205c980();
}

s32 func_0205cc3c(void **a, s32 b) {
    void *p = *a;
    s64 func_020722fc(s32, s32);
    return (s32)(func_020722fc(M2C_FIELD(p, s32 *, 0) * (s32)M2C_FIELD(p, u16 *, 4), b) >> 32);
}

s32 func_0205cc5c(void **a,void **b) {
void *p=*a,*q=*b; s32 y=M2C_FIELD(q,s32 *,0),x=M2C_FIELD(p,s32 *,0);
if(x!=y)return x-y;
return (s16)(M2C_FIELD(p,u16 *,4)-M2C_FIELD(q,u16 *,4));
}

void func_0205cc90(s32 *arg0) {
    M2C_UNK func_0205acc8(s32);
    func_0205acc8(*arg0);
}

s32 func_0205cca0(void *p,s32 a,s32 b) {
s32 *func_02048ff8(s32,void *);
s32 data[40];void *ptr;s32 *res;
data[0]=a;M2C_FIELD(data,s16 *,4)=b;ptr=data;
res=func_02048ff8(M2C_FIELD(p,s32 *,12),&ptr);
if(res)return *res;return 0;
}

s32 func_0205ccd8(void **a, char *b, s32 c, s32 d, s32 e) {
void func_0204926c(void);
s32 func_0205d588(char *,s32 *,u16 *);
M2C_UNK func_02037794(s32);
void func_02065210(void *,s32,s32);
s32 func_02048c84(s32,s32,s32,void *,void *,s32);
s32 func_02048558(s32,s32,void (*)(void *));
s32 func_020377c4(void *);
M2C_UNK func_02048dc4(s32);
s32 func_0204861c(s32);
s32 func_020496a4(s32,s32,s32);
s32 func_020496e0(s32,void *,s32);
M2C_UNK func_020496b8(s32);
s32 func_020498b8(s32,void *,s32 *);
s32 addr;
u16 port;
s32 len;
void *p;
s32 swapped;
func_0204926c();
if(d==0)d=0x10000;
if(c==0)c=0x10000;
if(!func_0205d588(b,&addr,&port))return 4;
p=(void *)func_02037794(0x44);
if(!p)return 1;
func_02065210(p,0,0x44);
M2C_FIELD(p,s32 *,0)=-1;
M2C_FIELD(p,s32 *,0x3c)=d;
M2C_FIELD(p,s32 *,0x38)=c;
M2C_FIELD(p,s32 *,0x24)=e;
M2C_FIELD(p,s32 *,0xc)=func_02048c84(4,0x20,2,func_0205cc3c,func_0205cc5c,0);
if(!M2C_FIELD(p,s32 *,0xc)){func_020377c4(p);return 1;}
M2C_FIELD(p,s32 *,0x10)=func_02048558(4,4,(void (*)(void *))func_0205cc90);
if(!M2C_FIELD(p,s32 *,0x10)){func_02048dc4(M2C_FIELD(p,s32 *,0xc));func_020377c4(p);return 1;}
M2C_FIELD(p,s32 *,0)=func_020496a4(2,2,0);
if(M2C_FIELD(p,s32 *,0)==-1){func_02048dc4(M2C_FIELD(p,s32 *,0xc));func_0204861c(M2C_FIELD(p,s32 *,0x10));func_020377c4(p);return 3;}
swapped=((port>>8)&0xff)|((port<<8)&0xff00);
{ struct Packet_0205 pkt={0};
pkt.b=2;
pkt.d=addr;
pkt.c=swapped;
if(func_020496e0(M2C_FIELD(p,s32 *,0),&pkt,8)==-1){
func_020496b8(M2C_FIELD(p,s32 *,0));func_02048dc4(M2C_FIELD(p,s32 *,0xc));func_0204861c(M2C_FIELD(p,s32 *,0x10));func_020377c4(p);return 3;
}
len=8;func_020498b8(M2C_FIELD(p,s32 *,0),&pkt,&len);
M2C_FIELD(p,s32 *,4)=pkt.d;
M2C_FIELD(p,u16 *,8)=((pkt.c>>8)&0xff)|((pkt.c<<8)&0xff00);
*a=p;return 0;
}
}

void func_0205cef8(void *arg0) {
M2C_UNK func_020377c4(void *);M2C_UNK func_02048dc4(s32);M2C_UNK func_02049270();M2C_UNK func_020496b8(s32);
if(M2C_FIELD(arg0,s32 *,0x1c)!=0){M2C_FIELD(arg0,s32 *,0x14)=1;return;}
func_020496b8(M2C_FIELD(arg0,s32 *,0));func_02048dc4(M2C_FIELD(arg0,s32 *,0xc));func_0204861c(M2C_FIELD(arg0,s32 *,0x10));func_020377c4(arg0);func_02049270();
}

void func_0205cf3c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
}

void *func_0205cf44(void) {
    M2C_UNK func_02037794(M2C_UNK);
    return (void *)func_02037794(0xA0);
}

s32 func_0205cf54(void *arg0, s32 arg1, s32 arg2, s16 arg3) {
    s32 func_0205cca0(void *, s32, s32);
    void *func_0205cf44(void);
    void func_02065210(void *, s32, s32);
    s32 func_02049208(void);
    s32 func_02059cf8(void *, s32);
    s32 func_02048558(s32, s32, void (*)(void *));
    void func_02048eac(void *, void **);
    s32 func_020377c4(void *);
    s32 func_0204861c(s32);

    void *alloc = 0;
    s32 timestamp;
    s32 result;

    if (((s32 (*)(void *, s32, s16, s32))func_0205cca0)(arg0, arg2, (s16)arg3, 0) != 0) {
        return 5;
    }

    alloc = func_0205cf44();
    if (alloc == 0) {
        goto fail;
    }

    func_02065210(alloc, 0, 0xA0);
    *(s32 *)alloc = arg2;
    *(u16 *)((u8 *)alloc + 4) = (u16)arg3;
    *(void **)((u8 *)alloc + 8) = arg0;
    timestamp = func_02049208();
    *(s32 *)((u8 *)alloc + 0x1C) = timestamp;
    *(s32 *)((u8 *)alloc + 0x88) = *(s32 *)((u8 *)alloc + 0x1C);
    *(u16 *)((u8 *)alloc + 0x64) = 0;
    *(u16 *)((u8 *)alloc + 0x66) = 0;

    if (func_02059cf8((u8 *)alloc + 0x44, *(s32 *)((u8 *)arg0 + 0x3C)) == 0) {
        goto fail;
    }
    if (func_02059cf8((u8 *)alloc + 0x50, *(s32 *)((u8 *)arg0 + 0x38)) == 0) {
        goto fail;
    }

    result = func_02048558(0x10, 0x40, 0);
    *(s32 *)((u8 *)alloc + 0x5C) = result;
    if (*(s32 *)((u8 *)alloc + 0x5C) == 0) {
        goto fail;
    }

    result = func_02048558(0x10, 0x40, 0);
    *(s32 *)((u8 *)alloc + 0x60) = result;
    if (*(s32 *)((u8 *)alloc + 0x60) == 0) {
        goto fail;
    }

    result = func_02048558(0x4, 0x2, 0);
    *(s32 *)((u8 *)alloc + 0x98) = result;
    if (*(s32 *)((u8 *)alloc + 0x98) == 0) {
        goto fail;
    }

    result = func_02048558(0x4, 0x2, 0);
    *(s32 *)((u8 *)alloc + 0x9C) = result;
    if (*(s32 *)((u8 *)alloc + 0x9C) == 0) {
        goto fail;
    }

    func_02048eac(*(void **)((u8 *)arg0 + 0xC), &alloc);
    result = func_0205cca0(arg0, arg2, (s16)arg3);
    *(s32 *)arg1 = result;
    if (result != 0) {
        return 0;
    }

    if (alloc == 0) {
        goto done;
    }

    func_020377c4(*(void **)((u8 *)alloc + 0x44));
    func_020377c4(*(void **)((u8 *)alloc + 0x50));

    result = *(s32 *)((u8 *)alloc + 0x5C);
    if (result != 0) {
        func_0204861c(result);
    }
    result = *(s32 *)((u8 *)alloc + 0x60);
    if (result != 0) {
        func_0204861c(result);
    }
    result = *(s32 *)((u8 *)alloc + 0x98);
    if (result != 0) {
        func_0204861c(result);
    }
    result = *(s32 *)((u8 *)alloc + 0x9C);
    if (result != 0) {
        func_0204861c(result);
    }

    func_020377c4(alloc);

done:
    return 1;

fail:
    return 0;
}

s32 func_0205d164(s32 arg) {
    s32 func_02048688(s32);
    s32 *func_02048690(s32, s32);
    void func_0204890c(s32, s32);
    void func_02048f54(s32, void *);
    void *p = (void *)arg;
    s32 v = M2C_FIELD(p, s32 *, 0x14);
    if (v == 0) v = M2C_FIELD(p, s32 *, 0x24);
    if (v != 0u) return v;
    if (M2C_FIELD(p, s32 *, 0x0C) == 7) {
        s32 *field8 = (s32 *)M2C_FIELD(p, s32 *, 0x08);
        s32 base = M2C_FIELD(field8, s32 *, 0x10);
        s32 n = func_02048688(base);
        s32 i;
        if (n <= 0) return 0;
        for (i = 0; i < n; i++) {
            s32 *item = func_02048690(base, i);
            if (item[0] == arg) {
                func_0204890c(base, i);
                return 0;
            }
        }
        return 0;
    }
    {
        s32 *field8 = (s32 *)M2C_FIELD(p, s32 *, 0x08);
        func_02048f54(M2C_FIELD(field8, s32 *, 0x0C), (void *)&arg);
        return 0;
    }
}

s32 func_0205d228(void *p, s32 arg1, s32 arg2, void *arg3, s32 arg4) {
    void func_0205d70c(M2C_UNK **, s32 *);
    s32 func_0204955c(s32);
    s32 func_02049824(s32, s32, s32, s32, void *, s32);
    s32 func_02049900(s32);
    s32 func_0205c244(void *, s32, s32);
    void func_0205d49c(void *);
    s32 func_0205cca0(void *, s32, s32);
    s32 func_0205a614(void *, void *, s32, s32, s32, s32, s32, s32);


    struct Packet_0205 *pp;
    s32 res;
    s32 combined;

    func_0205d70c((M2C_UNK **)&arg3, &arg4);

    if (func_0204955c(*(s32 *)p) == 0) {
        return 1;
    }

    {
    struct Packet_0205 pkt={0};
    pp = &pkt;
    combined = ((arg2 >> 8) & 0xff) | ((arg2 << 8) & 0xff00);


    pp->c = (u16)combined;
    pp->b = 2;
    pp->d = arg1;

    res = func_02049824(*(s32 *)p, (s32)arg3, arg4, 0, pp, 8);
    if (res == -1) {
        s32 r = func_02049900(*(s32 *)p);
        if (r == -15) {
            s32 c = func_0205c244(p, arg1, arg2);
            if (c != 0) {
                goto success;
            }
            return 0;
        }
        if (r == -42 || r == -6) {
            return 1;
        }
        if (r == -35) {
            goto success;
        }
        func_0205d49c(p);
        return 0;
    }

    if (*(s32 *)((u8 *)p + 0x28) == 0) {
        goto success;
    }

    {
        void *cca = (void *)func_0205cca0(p, arg1, arg2);
        s32 t = func_0205a614(p, cca, arg1, arg2, 0, (s32)arg3, arg4, 1);
        if (t == 0) {
            return 0;
        }
    }

success:
    return 1;
    }
}

s32 func_0205d3d0(void **a,void **b) {
void *p=*a;void *q=*b;
if(M2C_FIELD(p,s32 *,12)!=7) {if(!func_0205abb4(p,q))return 0;}
if(M2C_FIELD(p,s32 *,12)==7 && M2C_FIELD(p,s32 *,20)==0 && M2C_FIELD(p,s32 *,36)==0)func_0205d164((s32)p);
return 1;
}

s32 func_0205d428(void *arg0) {
    s32 func_02049104(s32, s32 (*)(void **,void **), s32 *);
    s32 func_02049208();
    s32 func_0205d3d0(void **,void **);
    s32 sp0;

    sp0 = func_02049208();
    if (func_02049104(M2C_FIELD(arg0, s32 *, 0xC), &func_0205d3d0, &sp0) == 0) {
        return 1;
    }
    return 0;
}

void func_0205d464(void *arg0) {
    s32 func_02048688(s32);
    s32 *func_02048690(s32, s32);
    M2C_UNK func_0205d164(s32);
    s32 var_r4;

    var_r4 = func_02048688(M2C_FIELD(arg0, s32 *, 0x10)) - 1;
    if (var_r4 < 0) {
        return;
    }
    do {
        func_0205d164(*func_02048690(M2C_FIELD(arg0, s32 *, 0x10), var_r4));
        var_r4 -= 1;
    } while (var_r4 >= 0);
}

void func_0205d49c(void *a) {
    void func_0205afec(void *);
    s32 func_02059f18(void *);
    if (M2C_FIELD(a, s32 *, 0x18)) return;
    M2C_FIELD(a, s32 *, 0x18) = 1;
    func_0205afec(a);
    if (!func_02059f18(a)) return;
    func_0205cef8(a);
}

char *func_0205d4d8(s32 a,s32 b,char *p) {
s32 func_02021c10(s32);
s32 func_020675e4(char *,const char *,...);
extern s32 data_0213e114;
extern char data_0213e118[],data_020ff848[],data_020ff850[],data_020ff854[];
volatile s32 saved;
if (!p) { data_0213e114^=1; p=data_0213e118+data_0213e114*22; }
if(a) {
saved=a;
if(b) func_020675e4(p,data_020ff848,func_02021c10(a),b);
else func_020675e4(p,data_020ff850,func_02021c10(a));
} else {
if(!b) *p=0;
else func_020675e4(p,data_020ff854,b);
}
return p;
}

#pragma opt_common_subs off
s32 func_0205d588(char *a, s32 *b, u16 *c) {
    char *func_02068ee0(char *, s32);
    M2C_UNK func_020640a8(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void func_020651a4(void *, const void *, s32);
    s32 func_0206ad38(char *);
    s32 func_020498e4(void *);
    void *func_02021768(void *);
    extern u16 data_020ead40[];
    extern char data_020ff858[];
    extern char data_020ff878[];
    extern char data_020ff834[];
    char buf[0x104];
    char *r8;
    s32 *r7;
    u16 *r6;
    s32 r5;
    s32 r4;

    r8 = a;
    r7 = b;
    r6 = c;
    if (r8 == 0 || *r8 == 0) { r4 = 0; r5 = r4; } else {
        char *colon = func_02068ee0(r8, ':');
        r5 = (s32)colon;
        if (colon == 0) { r5 = 0; } else {
            if (colon == r8) { r8 = 0; r4 = 0; } else {
                s32 r9 = (s32)colon - (s32)r8;
                if (r9 >= 0x100) {
                    func_020640a8((M2C_UNK)data_020ff858, (M2C_UNK)data_020ff878, (M2C_UNK)data_020ff834, 0x81);
                }
                    func_020651a4(buf, r8, r9);
                    r8 = buf;
                    buf[r9] = 0;
            }
                {
                    char *r3 = colon + 1;
                    signed char ch = *r3;
                    while (ch != 0) {
                        s32 v = (ch < 0 || ch >= 0x80) ? 0 : data_020ead40[ch] & 8;
                        if (v == 0) return 0;
                        r3++;
                        ch = *r3;
                    }
                }
            {
                s32 rr = func_0206ad38((char *)(r5 + 1));
                if (rr < 0 || rr > 0xffff) {
                    return 0;
                }
                r5 = (u16)rr;
            }
        }
        if (r8 != 0) {
            r4 = func_020498e4(r8);
            if (r4 == -1) {
                void *t = func_02021768(r8);
                if (t == 0) {
                    return 0;
                }
                {
                    void *q = *(void **)((char *)t + 0xc);
                    void *rrr = *(void **)((char *)q + 0);
                    r4 = *(s32 *)((char *)rrr + 0);
                }
            }
        }
    }
    if (r7 != 0) {
        *r7 = r4;
    }
    if (r6 != 0) {
        *r6 = (u16)r5;
    }
    return 1;
}
#pragma opt_common_subs reset
void func_0205d70c(M2C_UNK **arg0, s32 *arg1) {
    s32 func_02068c34(M2C_UNK *);
    extern M2C_UNK data_020ff888;
    M2C_UNK *temp_r2;

    temp_r2 = *arg0;
    if (temp_r2 == NULL) {
        *arg0 = &data_020ff888;
        *arg1 = 0;
        return;
    }
    if (*arg1 != -1) {
        return;
    }
    *arg1 = func_02068c34(temp_r2) + 1;
}

void *func_0205d75c(s32 a) {
s32 func_02048688(s32);
s32 *func_02048690(s32,s32);
extern M2C_UNK data_0213e144;
s32 i; s32 *p;
if (!M2C_FIELD(&data_0213e144,s32 *,0x10)) return 0;
for(i=0;i<func_02048688(M2C_FIELD(&data_0213e144,s32 *,0x10));i++) {
p=func_02048690(M2C_FIELD(&data_0213e144,s32 *,0x10),i);
if (p[2]==a) return p;
}
return 0;
}

void func_0205d7c4(void *p) {
s32 func_020496b8(s32);
if(M2C_FIELD(p,s32 *,0)!=-1)func_020496b8(M2C_FIELD(p,s32 *,0));
M2C_FIELD(p,s32 *,0)=-1; M2C_FIELD(p,s32 *,16)=4;
}

s32 *func_0205d7f4(void) {
extern M2C_UNK data_0213e144;
s32 func_02048558(s32,s32,void (*)(void *));
s32 func_02048688(s32); s32 *func_02048690(s32,s32);
s32 handle=M2C_FIELD(&data_0213e144,s32 *,16); s32 data[16]={0};
if(!handle)M2C_FIELD(&data_0213e144,s32 *,16)=func_02048558(64,4,func_0205d7c4);
func_020486f8(M2C_FIELD(&data_0213e144,s32 *,16),data);
return func_02048690(M2C_FIELD(&data_0213e144,s32 *,16),func_02048688(M2C_FIELD(&data_0213e144,s32 *,16))-1);
}

void func_0205d88c(s32 *p) {
extern M2C_UNK data_0213e144;
s32 func_02048688(s32); s32 *func_02048690(s32,s32);
s32 i=0;
for(;i<func_02048688(M2C_FIELD(&data_0213e144,s32 *,16));i++) {
if(p==func_02048690(M2C_FIELD(&data_0213e144,s32 *,16),i)) {
func_0204887c(M2C_FIELD(&data_0213e144,s32 *,16),i);return;
}
}
}

void func_0205d8f4(void) {
    M2C_UNK func_0204861c();
    extern M2C_UNK data_0213e144;
    if (M2C_FIELD(&data_0213e144, s32 *, 0x10) == 0) {
        return;
    }
    func_0204861c();
    M2C_FIELD(&data_0213e144, s32 *, 0x10) = 0;
}

s32 func_0205d920(M2C_UNK arg0) {
    s32 func_0206527c(M2C_UNK, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020ff88c;
    if (func_0206527c(arg0, &data_020ff88c, 6) == 0) {
        return 1;
    }
    return 0;
}

void func_0205d944(s32 a,s32 b,s32 c,s32 d,s32 e) {
s32 func_02049824(s32,s32,s32,s32,void *,s32);
struct Packet_0205 p;
p.c=((c>>8)&255)|((c<<8)&0xff00);
p.d=b;
p.b=2;
func_02049824(a,d,e,0,&p,8);
}

s32 func_0205d998(s32 a) {
void *func_02049584(s32);
s32 i;void *q;void *p;s32 result=0;p=func_02049584(a);
if(!p)return result;
for(i=0;;i++) {
q=M2C_FIELD(p,void ***,12)[i];
if(!q)break;
if(M2C_FIELD((s32)q,s32 *,0)!=0x100007f) {
result=M2C_FIELD(q,s32 *,0);
if(func_02049610(q))return result;
}
}
return result;
}

s32 func_0205d9fc(s32 a) {
s32 func_020498b8(s32,void *,s32 *);
u16 v[4]; s32 size=8;
if (func_020498b8(a,v,&size)==-1) return 0;
return v[1];
}

