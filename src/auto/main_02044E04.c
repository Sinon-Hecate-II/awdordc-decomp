/* 24 functions from 0x02044E04 to 0x02045D94 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 words[4]; } CallbackRecord;

s32 func_02044e04(void) {
    M2C_UNK func_0204b378();
    extern M2C_UNK data_0213db18;
    func_0204b378();
    M2C_FIELD(&data_0213db18, s32 *, 4) = (s32) (M2C_FIELD(&data_0213db18, s32 *, 4) + 1);
    return 1;
}

s32 func_02044e28(void){extern M2C_UNK data_0213db18;void func_0204b3cc(void);void func_02045374(void);s32 n;if(M2C_FIELD(&data_0213db18,s32 *,4)<=0)return 1;func_0204b3cc();n=M2C_FIELD(&data_0213db18,s32 *,4)-1;M2C_FIELD(&data_0213db18,s32 *,4)=n;if(n==0)func_02045374();return 1;}

s32 func_02044e68(void) {
    s32 func_0203761c();
    M2C_UNK func_0204b674();
    if (func_0203761c() != 0) {
        return 0;
    }
    func_0204b674();
    return 1;
}

s32 func_02044e88(s32 unused,s32 a,s32 b,s32 c,void *arg){void func_020376d8(s32,s32,s32);s32 func_02045138(s32);void func_020452f0(void *);s32 flag;void (*cb)(s32,s32,s32,s32);void *p=arg;s32 x;cb=M2C_FIELD(p,void (**)(s32,s32,s32,s32),4);flag=M2C_FIELD(p,s32 *,12);if(cb){if(a==0)cb(b,c,a,M2C_FIELD(p,s32 *,0));else{func_02045138(a);cb(0,0,a,M2C_FIELD(p,s32 *,0));}}if(a!=0||flag==1){x=M2C_FIELD(p,s32 *,16);if(x==0)flag=1;else func_020376d8(4,x,0);}func_020452f0(p);return flag!=0;}

void func_02044f24(s32 unused,s32 a,s32 b,s32 c,s32 d,s32 e,void *p){
void (*cb)(s32,s32,s32,s32,s32,s32)=M2C_FIELD(p,void (**)(s32,s32,s32,s32,s32,s32),8);
if(!cb)return;cb(a,b,c,d,e,M2C_FIELD(p,s32 *,0));
}

s32 func_02044f6c(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    s32 func_0203761c(void);
    void *func_02037694(s32, s32);
    void func_020376d8(s32, s32, s32);
    s32 func_02045138(s32);
    void *func_02045294(CallbackRecord *);
    void func_020452f0(void *);
    s32 func_0204b428(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

    CallbackRecord rec;
    void *buf;
    void *node;
    s32 result;
    s32 old;

    buf = 0;
    if (func_0203761c() != 0) {
        return -8;
    }

    rec.words[0] = (u32)a6;
    rec.words[1] = (u32)a5;
    rec.words[2] = (u32)a4;
    rec.words[3] = (u32)a2;

    node = func_02045294(&rec);
    if (node == 0) {
        func_02045138(-5);
        ((void (*)(s32, s32, s32, s32))a5)((s32)buf, (s32)buf, -5, a6);
        return -5;
    }

    if (a1 > 0) {
        buf = func_02037694(4, a1);
        if (buf == 0) {
            func_02045138(-5);
            ((void (*)(s32, s32, s32, s32))a5)(0, 0, -5, a6);
            func_020452f0(node);
            return -5;
        }
        *(s32 *)((char *)node + 0x10) = (s32)buf;
    }

    if (a3 != 0) {
        result = func_0204b428(a0, 0, (s32)buf, a1,
                                *(s32 *)a3, 0, 0,
                                (s32)func_02044f24,
                                (s32)func_02044e88,
                                (s32)node);
    } else {
        result = func_0204b428(a0, 0, (s32)buf, a1,
                                0, 0, 0,
                                (s32)func_02044f24,
                                (s32)func_02044e88,
                                (s32)node);
    }

    if (result < 0) {
        func_02045138(result);
        ((void (*)(s32, s32, s32, s32))a5)(0, 0, result, a6);
        old = *(s32 *)((char *)node + 0x10);
        if (old != 0) {
            func_020376d8(4, old, 0);
        }
        func_020452f0(node);
    }

    *(s32 *)((char *)node + 0x14) = result;
    return result;
}

void func_02045110(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5) {
    M2C_UNK func_02044f6c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    func_02044f6c(arg0, arg1, arg2, 0, arg3, arg4, arg5);
}

s32 func_02045138(s32 arg0) {
M2C_UNK func_02037638(M2C_UNK,s32);
s32 a=7,b=0xfffe8130;
if(!arg0)return 0;
switch((u32)(arg0+7)){
case 0:b-=0x320;break;
case 1:b+=(u32)0xfffffcd6;break;
case 2:b-=0x348;break;
case 3:case 4:case 5:b-=0x334;break;
case 6:b+=(u32)0xfffffcc2;break;
case 8:case 26:b-=1;a=9;break;
case 9:b-=0x348;break;
case 10:b+=(u32)0xfffffcae;break;
case 11:b-=0x1e;break;
case 12:b-=0x32;break;
case 13:case 18:case 19:b-=0x14;break;
case 14:b-=0x35c;break;
case 15:case 16:case 17:b+=(u32)0xfffffc9a;break;
case 20:case 21:b-=0x370;break;
case 22:b+=(u32)0xfffffc86;break;
case 23:b-=0x384;break;
case 24:b+=(u32)0xfffffc72;break;
}
func_02037638(a,b);return arg0;
}

void *func_02045294(CallbackRecord *src){void *func_02037694(s32,s32);extern M2C_UNK data_0213db18;void *p=func_02037694(4,28);if(!p)return 0;*(CallbackRecord *)p=*src;M2C_FIELD(p,s32 *,24)=0;M2C_FIELD(p,s32 *,16)=0;if(!M2C_FIELD(&data_0213db18,void **,0)){M2C_FIELD(&data_0213db18,void **,0)=p;return p;}else{M2C_FIELD(p,void **,24)=M2C_FIELD(&data_0213db18,void **,0);M2C_FIELD(&data_0213db18,void **,0)=p;}return p;}

void func_020452f0(void *a) {
 extern M2C_UNK data_0213db18; void func_020376d8(s32,s32,s32);
 void *p=M2C_FIELD(&data_0213db18,void **,0),*q,*n;
 if(!p)return;
 if(p==a){n=M2C_FIELD(p,void **,24);func_020376d8(4,(s32)p,0);M2C_FIELD(&data_0213db18,void **,0)=n;return;}
 q=M2C_FIELD(p,void **,24);
 while(q) {
 if(q!=a)p=q;
 else {n=M2C_FIELD(p,void **,24);M2C_FIELD(p,void **,24)=M2C_FIELD(n,void **,24);func_020376d8(4,(s32)n,0);return;}
 q=M2C_FIELD(q,void **,24);
 }
}

void func_02045374(void) {
 extern M2C_UNK data_0213db18;void func_020376d8(s32,s32,s32);
 void *p=M2C_FIELD(&data_0213db18,void **,0),*q;
 while(p){q=p;p=M2C_FIELD(p,void **,24);if(M2C_FIELD(q,s32 *,16))func_020376d8(4,M2C_FIELD(q,s32 *,16),0);func_020376d8(4,(s32)q,0);}
 M2C_FIELD(&data_0213db18,void **,0)=0;
}

s32 func_020453e4(s32 *a) {
 s32 func_0203761c();s32 *func_02047928(s32 *);extern s32 data_0213db20;
 s32 x; s32 *p;
 if(func_0203761c())return 1;
 if(data_0213db20!=5)return 16;
 p=func_02047928(&x);if(!x)return 17;
 a[0]=x;a[1]=*p++;a[2]=(s32)p;return 0;
}

s32 func_02045458(s32 a, s32 b) {
    s32 func_0203761c(void);
    s32 func_020323b0(void *);
    s32 func_020323f4(void *);
    u32 func_02068c34(void *);
    void *func_02068d18(void *, void *, s32);
    s32 func_0206abd8(void *, s32, s32);
    s32 func_0204800c(void *, void *, s32, s32, s32, s32);
    s32 func_02068d98(void *, void *);
    void func_02047750(s32);
    extern M2C_UNK data_0213db20;
    extern void *data_020fb2f8;
    extern M2C_UNK data_020fca38;

    u8 text[0x15];
    u8 buf[9] = {0};
    s32 r8, r7, r6, parsed4;

    if (func_0203761c() != 0) {
        return 1;
    }
    if (M2C_FIELD(&data_0213db20, s32 *, 0) != 0) {
        return 3;
    }
    if (func_020323b0((void *)b) == 0 || func_020323f4((void *)b) == 0) {
        return 6;
    }
    if (func_02068c34((void *)a) >= 0x54u) {
        return 4;
    }
    func_02068d18(text, (void *)a, 0x14);
    text[0x14] = 0;
    r8 = func_0206abd8(func_02068d18(buf, (void *)(a + 0x14), 8), 0, 0x10);
    r7 = func_0206abd8(func_02068d18(buf, (void *)(a + 0x1c), 8), 0, 0x10);
    r6 = func_0206abd8(func_02068d18(buf, (void *)(a + 0x24), 8), 0, 0x10);
    parsed4 = func_0206abd8(func_02068d18(buf, (void *)(a + 0x2c), 8), 0, 0x10);
    if (func_0204800c((void *)(a + 0x34), text, r8, r7, r6, parsed4) == 0) {
        return 5;
    }
    M2C_FIELD(&data_0213db20, s32 *, 4) = M2C_FIELD((void *)b, s32 *, 0x1c);
    if (func_02068d98(data_020fb2f8, (void *)&data_020fca38) == 0) {
        func_02047750(1);
    } else {
        func_02047750(0);
    }
    M2C_FIELD(&data_0213db20, s32 *, 0) = 1;
    return 0;
}

s32 func_02045620(void){void func_020478b8(void);extern s32 data_0213db20;func_020478b8();return data_0213db20=0;}

s32 func_0204563c(u32 arg0, s32 arg1, s32 arg2, s32 arg3, u32 arg4) {
    s32 func_0203761c();
    s32 func_02047940(s32, s32, s32, s32, s32, s32);
    extern s32 data_0213db20;
    s32 r;
    if (func_0203761c() != 0) {
        return 1;
    }
    if (data_0213db20 != 1 && data_0213db20 != 5) {
        return 7;
    }
    if (arg0 > 0x3e8u || arg4 > 0x2fcu) {
        return 2;
    }
    if (arg3 == 0 && arg4 != 0) {
        return 2;
    }
    r = func_02047940((s32)arg0, M2C_FIELD(&data_0213db20, s32 *, 4), arg1, arg2, arg3, (s32)arg4);
    if (r == 2) goto L8;
    if (r != 3) goto Ldata;
    goto L9;
L8:
    return 8;
L9:
    return 9;
Ldata:
    data_0213db20 = 2;
    return 0;
}

s32 func_0204571c(s32 a,u32 b,s32 c,void *d){
s32 func_0203761c(void);s32 func_02047b84(s32,u32,s32,s32,void *);extern M2C_UNK data_0213db20;s32 r;
if(func_0203761c())return 1;
if(M2C_FIELD(&data_0213db20,s32 *,0)!=1&&M2C_FIELD(&data_0213db20,s32 *,0)!=5)return 10;
if(b>1000||!d)return 2;
switch(a){
case 0:if(M2C_FIELD(d,s32 *,0)!=8)return 2;if(M2C_FIELD(d,s32 *,4)!=0&&M2C_FIELD(d,s32 *,4)!=1)return 2;break;
case 1:if(M2C_FIELD(d,s32 *,0)!=12)return 2;if(M2C_FIELD(d,s32 *,4)!=0&&M2C_FIELD(d,s32 *,4)!=1)return 2;if(M2C_FIELD(d,u32 *,8)>30||M2C_FIELD(d,u32 *,8)<=0)return 2;break;
case 2:case 4:case 5:if(M2C_FIELD(d,s32 *,0)!=12)return 2;if(M2C_FIELD(d,s32 *,4)!=0&&M2C_FIELD(d,s32 *,4)!=1)return 2;if(M2C_FIELD(d,u32 *,8)>30||M2C_FIELD(d,u32 *,8)<=1)return 2;break;
case 3:if(M2C_FIELD(d,s32 *,0)!=268)return 2;if(M2C_FIELD(d,s32 *,4)!=0&&M2C_FIELD(d,s32 *,4)!=1)return 2;if(M2C_FIELD(d,u32 *,8)>65||M2C_FIELD(d,u32 *,8)<=1)return 2;break;
case 6:if(M2C_FIELD(d,s32 *,0)!=16)return 2;if(M2C_FIELD(d,s32 *,4)!=0&&M2C_FIELD(d,s32 *,4)!=1)return 2;if(M2C_FIELD(d,u32 *,8)>30||M2C_FIELD(d,u32 *,8)<=0)return 2;if(M2C_FIELD(d,u32 *,16)>0x7fffffff||M2C_FIELD(d,u32 *,16)==0)return 2;break;
}r=func_02047b84(a,b,M2C_FIELD(&data_0213db20,s32 *,4),c,d);switch(r){case 3:return 11;case 2:return 12;default:M2C_FIELD(&data_0213db20,s32 *,0)=3;return 0;}}

s32 func_02045934(s32 a, s32 b, u32 c, s32 d) {
    s32 func_0203761c();
    s32 func_02047dd4(s32, u32, s32, s32);
    extern s32 data_0213db20;
    if (func_0203761c() != 0) return 1;
    if (data_0213db20 != 1 && data_0213db20 != 5) return 10;
    if (c > 1000) return 2;
    if (a < 0 || a >= 9) return 2;
    if (b < 0) return 2;
    {
        s32 r = func_02047dd4(a, c, b, d);
        switch (r) {
            case 3:
                return 11;
            case 2:
                return 12;
            default:
                data_0213db20 = 4;
                return 0;
        }
    }
}

s32 func_020459ec(void) {
    s32 func_0203761c();
    s32 func_020477ac();
    extern s32 data_0213db20;
    if (func_0203761c()) return 1;
    if (data_0213db20 != 2 && data_0213db20 != 3 && data_0213db20 != 4) return 14;
    switch (func_020477ac()) {
        case 1:
            data_0213db20 = 6;
            break;
        case 0:
            data_0213db20 = 6;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
        case 8:
            data_0213db20 = 5;
            break;
    }
    return 0;
}

s32 func_02045a88(void) {
    extern s32 data_0213db20;
    return data_0213db20;
}

s32 func_0203761c(void);
s32 func_02045a98(s32 a, s32 b) {
    s32 buf[3];
    s32 *pVar1;
    s32 iVar2;
    s32 *pVar3;
    s32 uVar4;
    s32 *pVar5;
    
    if (func_0203761c() != 0) {
        return 1;
    }
    if (func_020453e4(buf) != 0) {
        return 1;
    }
    iVar2 = buf[1];
    if ((u32)iVar2 < 8) {
        switch (iVar2) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            return 15;
        case 1:
            break;
        }
    }
    if (a == 0) {
        return 2;
    }
    pVar3 = (s32 *)buf[2];
    if (pVar3 == NULL || a >= *pVar3) {
        return 2;
    }
    pVar5 = pVar3 + 2;
    if (b != 0) {
        do {
            uVar4 = pVar5[5];
            pVar5 = (s32 *)((char *)(pVar5 + 6) + uVar4);
            b--;
        } while (b != 0);
    }
    uVar4 = pVar5[5];
    pVar1 = (s32 *)((char *)(pVar5 + 6) + uVar4);
    pVar5 = (s32 *)buf[0];
    if ((char *)pVar1 - (char *)pVar5 > *(s32 *)((char *)pVar3 + (int)pVar5)) {
        return 2;
    }
    pVar1 = (s32 *)buf[5]; // placeholder to match remaining stores
    return 0;
}

s32 func_02045ba0(s32 *a) {
    s32 func_0203761c();
    s32 func_020453e4(s32 *);
    s32 x[3], r;
    if (func_0203761c()) return 1;
    r = func_020453e4(x); if (r) return r;
    if (!a) return 2;
    switch (x[1]) {
        case 0:
            return 15;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        default:
            *a = *(s32 *)x[2];
            return 0;
    }
}

s32 func_02045c34(s32 *a) {
 s32 func_0203761c(); s32 func_020453e4(s32 *);
 s32 x[3],r;
 if(func_0203761c())return 1;
 r=func_020453e4(x);if(r)return r;
 if(!a)return 2;
 *a=M2C_FIELD(x[2],s32 *,4);return 0;
}

s32 func_02045c90(M2C_UNK arg0) {
    s32 func_020465c4(s32, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0213db28;
    if (func_020465c4(M2C_FIELD(&data_0213db28, s32 *, 8), 0x300, arg0) != 0) {
        return 1;
    }
    return 0;
}

void func_02045cbc(void *arg0) {
    void func_02008048(void *, void *, u32);
    extern M2C_UNK data_0213db34;
    extern M2C_UNK data_0213db39;
    extern M2C_UNK data_0213db3e;
    extern M2C_UNK data_0213db40;
    u32 *p = (u32 *)arg0;
    u32 a, b;
    s32 h;
    u32 m;

    func_02008048(&data_0213db34, arg0, 6);
    a = p[0];
    b = p[1];
    p[0] = a & (0x7FF - 0x800);
    p[1] = b & 0x7FF;

    func_02008048(&data_0213db39, arg0 + 8, 6);
    a = p[2];
    b = p[3];
    p[2] = (a >> 3) | (b << 29);
    p[3] = b >> 3;
    a = p[2];
    b = p[3];
    p[2] = a & (0x7FF - 0x800);
    p[3] = b & 0x7FF;

    func_02008048(&data_0213db3e, arg0 + 0x10, 2);
    h = (s32)*(u16 *)(arg0 + 0x10);
    h = h >> 6;
    *(u16 *)(arg0 + 0x10) = (u16)h;
    h = (s32)*(u16 *)(arg0 + 0x10);
    h = h & 0x3FF;
    *(u16 *)(arg0 + 0x10) = (u16)h;

    func_02008048(&data_0213db40, arg0 + 0x12, 2);
}

