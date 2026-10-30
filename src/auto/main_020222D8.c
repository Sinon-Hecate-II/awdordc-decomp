/* 15 functions from 0x020222D8 to 0x020232B8 (main), found by ds-decomp. */
#include "common.h"

s32 func_02022970(void *arg0) {
    void func_02025700(void *);
    void func_02025748(void *, void *, s32);
    void func_02025800(void *, s32);
    void func_02025fc0(void *);
    void func_02026014(void *, void *, s32);
    void func_020260cc(void *, void *);
    s32 func_02022150(void *, void *);
    s32 func_020227c8(void *, void *);
    s32 var_r4;
    s32 t0, t1;
    register s32 p asm("r1");
    if (*(u8 *)((u8 *)arg0 + 0x5af) != 0) {
        var_r4 = 0;
    } else {
        var_r4 = 0x8000;
    }
    if (*(s32 *)((u8 *)arg0 + 0x45c) == -1) {
        return var_r4 | 4;
    }
    switch (*(s32 *)((u8 *)arg0 + 0x458)) {
    case 3:
        func_02025700((u8 *)arg0 + 0x3fc);
        t0 = *(s32 *)((u8 *)arg0 + 0x460);
        func_02025748((u8 *)arg0 + 0x3fc, (void *)t0, *(s32 *)((u8 *)arg0 + 0x464) - t0);
        func_02025800((u8 *)arg0 + 0x3fc, (s32)((u8 *)arg0 + 0x468));
        *(s32 *)((u8 *)arg0 + 0x47c) = 0x10;
        break;
    case 4:
        func_02025fc0((u8 *)arg0 + 0x348);
        t1 = *(s32 *)((u8 *)arg0 + 0x460);
        func_02026014((u8 *)arg0 + 0x348, (void *)t1, *(s32 *)((u8 *)arg0 + 0x464) - t1);
        func_020260cc((u8 *)arg0 + 0x348, (u8 *)arg0 + 0x468);
        *(s32 *)((u8 *)arg0 + 0x47c) = 0x14;
        break;
    default:
        return var_r4 | 3;
    }
    p = func_02022150(arg0, (u8 *)arg0 + 0x5b0);
    if (p == 0) {
        return var_r4 | 1;
    }
    return var_r4 | func_020227c8(arg0, (void *)p);
}

s32 func_02022a54(s8 *p) {
s8 *start=p;
s32 c;
while((c=*p)!=0x2e && c!=0)p++;
return p-start;
}

s32 func_02022a78(s8 *p,s8 *q) {
s32 a,b,c,d;
do {
while((d=*p++)==(c=*q++)) { if(d==0)return 0; }
if(c!=0x2a)return 1;
p--;a=func_02022a54(p);b=func_02022a54(q);
if(b>a)return 1;
p+=a-b;
} while(1);
}

void func_02022ae4(void *a, u8 *b) {
s32 func_020222d8(void *,u8 **,s32,s32,s32);
void func_0200ef4c(s32 *);
s32 func_020227c8(void *,void *);
s32 date[4]; s32 low,result; u32 n,remaining; s32 i; u8 *next;
n=b[0]; remaining=b[1]; remaining=b[2]+(((n<<8)+remaining)<<8);b+=3;
M2C_FIELD(a,s32 *,0x45c)=-1;
func_0200ef4c(date);
M2C_FIELD(a,s32 *,0x80c)=date[2]+((date[0]+2000<<16)+(date[1]<<8));
low=0;M2C_FIELD(a,u8 *,0x6b0)=low;
M2C_FIELD(a,s32 *,0x5a0)=low;M2C_FIELD(a,s32 *,0x594)=low;i=low;
do {
{u32 x=b[0],y=b[1],z=b[2];n=z+(((x<<8)+y)<<8);}b+=3;
M2C_FIELD(a,s32 *,0x458)=-1;
M2C_FIELD(a,u8 *,0x5ad)=0;M2C_FIELD(a,u8 *,0x5ac)=0;M2C_FIELD(a,u8 *,0x5af)=0;M2C_FIELD(a,u8 *,0x6b0)=0;M2C_FIELD(a,u8 *,0x5b0)=0;M2C_FIELD(a,u8 *,0x7b0)=0;
M2C_FIELD(a,u8 **,0x804)=b;M2C_FIELD(a,u32 *,0x808)=n;
remaining-=n+3;
if(func_020222d8(a,&b,0,0,low)!=0 || M2C_FIELD(a,u32 *,0x594)<51 || M2C_FIELD(a,s32 *,0x5a0)==0){M2C_FIELD(a,u8 *,0x455)=9;return;}
result=func_02022970(a);
if(i==0 && M2C_FIELD(a,s8 **,0x800)!=0 && func_02022a78(M2C_FIELD(a,s8 **,0x800),(s8 *)a+0x7b0))result|=0x4000;
low=(u8)result;
if(low==1 && remaining){
next=b+3;M2C_FIELD(a,u8 *,0x5ad)=0;
if(func_020222d8(a,&next,0,0,2)){M2C_FIELD(a,u8 *,0x455)=9;return;}
result=(result&~255)|func_020227c8(a,(u8 *)a+0x480);
}
if(M2C_FIELD(a,s32 (**)(s32,void *,s32),0x810))result=M2C_FIELD(a,s32 (**)(s32,void *,s32),0x810)(result,a,i);
i++;
}while(low && result==0 && remaining && (low=1));
if(result==0)M2C_FIELD(a,u8 *,0x455)=3;else M2C_FIELD(a,u8 *,0x455)=9;
}

#pragma opt_propagation off
void func_02022d08(s32 p,u8 *s) {
s32 old,n;
func_02008048(s+2,p+0x54,0x20);
old=M2C_FIELD(p,u8 *,0x30);n=s[0x22];s+=0x23;
if(old && n==0x20 && !func_0206527c(p+0x74,s,0x20))M2C_FIELD(p,u8 *,0x31)=1;
else {
if(old)func_02022008(p);
if(!n) M2C_FIELD(p,u8 *,0x30)=0;
else {func_02008048(s,p+0x74,0x20);M2C_FIELD(p,u8 *,0x30)=1;}
M2C_FIELD(p,u8 *,0x31)=0;
}
M2C_FIELD(p,u16 *,0x32)=(s[n]<<8)+(s+n)[1];
M2C_FIELD(p,u8 *,0x455)=2;
}
#pragma opt_propagation reset
s32 func_02022dbc(u8 *p,s32 n,s32 stride,s32 target) {
s32 i,v;
for(i=0;i<n;i++,p+=stride) {
v=p[0]; v=(v<<8)+p[1];
if(stride==3)v=p[2]+(v<<8);
if(v==target)return 1;
}
return 0;
}

s32 func_02022e08(u8 *arg0,s32 arg1,s32 arg2) {
extern u16 data_020faffc[];
u32 i=0;
do {
if(func_02022dbc(arg0,arg1,arg2,data_020faffc[i]))return data_020faffc[i];
i++;
}while(i<2);
return 0;
}

s32 func_02022e68(s32 arg0, s32 arg1) {
    if (arg0 == 3) {
        return 1;
    }
    return 0;
}

#pragma opt_propagation off
void func_02022e78(u8 *p,u8 *q){
s32 func_02008048(); void func_02007f8c();
s32 size,offset,n;u16 value;
if(!func_02022e68(q[0],q[1]))return;
size=(q[2]<<8)+q[3];
value=func_02022e08(q+8,size/3,3);
if(!value)return;
M2C_FIELD(p,u16*,0x32)=value;
offset=(q[4]<<8)+q[5];n=(q[6]<<8)+q[7];
p[0x30]=0;
offset=(size+8)+offset;
if(n>=32)func_02008048(q+offset,p+0x34,32);
else {func_02007f8c(p+0x34,0,32-n);func_02008048(q+offset,p+0x54-n,n);}
p[0x455]=1;
}
#pragma opt_propagation reset
void func_02022f40(void *arg0,u8 *arg1) {
s32 func_02008048(); void func_02021de8(void *);
u32 n; u8 *p; u16 value;
if(func_02022e68(arg1[0],arg1[1])==0)return;
func_02008048(arg1+2,(u8 *)arg0+0x34,32);
n=arg1[0x22];p=arg1+0x23;
if(n!=32)M2C_FIELD(arg0,u8 *,0x30)=0;
else {func_02008048(p,(u8 *)arg0+0x74,32);func_02021de8(arg0);}
p+=n;
value=func_02022e08(p+2,((p[0]<<8)+p[1])/2,2);
M2C_FIELD(arg0,u16 *,0x32)=value;
if(value)M2C_FIELD(arg0,u8 *,0x455)=1;
}

void func_02022fdc(s32 arg0, s32 arg1, void *arg2) {
    s32 func_020220b8(void);
    void func_02022104(s32);
    s32 func_0202626c(u16 *, s32);
    void func_0202629c(u16 *, u16 *, u16 *, s32);
    void func_0202639c(u16 *, s32);
    void func_020263dc(u16 *, u16 *, u16 *, s32);
    void func_02026558(u16 *, u16 *, u16 *, s32);
    void func_020267fc(u16 *, u16 *, u16 *, u16 *, s32, u16 *);
    void func_02026de4(void *, void *, void *, s32, void *);
    void func_02026ff0(void *, void *, void *, s32);
    void func_0202704c(void *, void *, s32, s32);
    extern u32 data_021372a4[];
    extern u32 data_021372d0[];

    s32 r4;
    u16 *r5, *r6, *r7, *sp10, *spC, *r8, *r9, *r11;
    s32 *ip;
    s32 tmp, n, t;

    if (arg2 == 0) return;
    ip = (s32 *)arg2;
    if (ip[0] == 0) return;
    n = ip[0];
    t = n * 2;
    {
        u32 ut;
        s32 sum;
        ut = (u32)t;
        sum = t + (s32)(ut >> 31);
        r4 = (sum >> 1) + 1;
    }
    r5 = (u16 *)((void *(*)(u32))data_021372a4[0])((u32)(r4 * 0x14));
    if (r5 == 0) return;
    r6 = r5 + r4;
    r7 = r6 + r4;
    sp10 = r7 + r4;
    spC = sp10 + r4;
    r8 = spC + r4;
    r9 = r8 + r4;
    r11 = r9 + r4;
    func_02026ff0(r5, (void *)arg1, (void *)(s32)ip[0], r4);
    func_02026ff0(r6, (void *)ip[7], (void *)ip[6], r4);
    func_02026ff0(r8, (void *)ip[3], (void *)ip[2], r4);
    tmp = func_020220b8();
    func_02026de4(sp10, r5, r6, r4, r8);
    func_02026ff0(r6, (void *)ip[9], (void *)ip[8], r4);
    func_02026ff0(r8, (void *)ip[5], (void *)ip[4], r4);
    func_02026de4(spC, r5, r6, r4, r8);
    func_02022104(tmp);
    func_020263dc(r5, sp10, spC, r4);
    func_02026ff0(r6, (void *)ip[11], (void *)ip[10], r4);
    func_02026558(r7, r5, r6, r4);
    func_02026ff0(r6, (void *)ip[5], (void *)ip[4], r4);
    func_02026558(r5, r7, r6, r4);
    func_0202629c(r7, r5, spC, r4);
    func_02026ff0(r6, (void *)ip[1], (void *)ip[0], r4);
    if (func_0202626c(r7, r4) < 0) {
        func_0202639c(r7, r4);
        func_020267fc((u16 *)0, r7, r6, r9, r4, r11);
        func_020263dc(r9, r6, r9, r4);
    } else {
        func_020267fc((u16 *)0, r7, r6, r9, r4, r11);
    }
    func_0202704c((void *)arg0, r9, 0x30, r4);
    ((void (*)(void *))data_021372d0[0])((void *)r5);
}

void func_0202321c(s32 arg0,u8 *arg1,u8 *arg2) {
void func_02025700(void *); void func_02025748(void *,void *,s32); void func_02025800(void *,s32);
void func_02025fc0(void *); void func_02026014(void *,void *,s32);void func_020260cc(void *,void *);
s32 func_02068c34(void *);
u8 sp0[20];
func_02025fc0(arg2+0x348);
func_02026014(arg2+0x348,arg1,func_02068c34(arg1));
func_02026014(arg2+0x348,arg2,0x30);
func_02026014(arg2+0x348,arg2+0x34,0x40);
func_020260cc(arg2+0x348,sp0);
func_02025700(arg2+0x3fc);
func_02025748(arg2+0x3fc,arg2,0x30);
func_02025748(arg2+0x3fc,sp0,20);
func_02025800(arg2+0x3fc,arg0);
}
s32 func_020227c8(void *arg0, void *arg1) {
    extern u32 data_021372a4[];
    extern u32 data_021372d0[];
    void func_02026ff0(void *, void *, void *, s32);
    s32 func_020220b8(void);
    void func_020269dc(void *, void *, s32, s32, void *);
    void func_02022104(s32);
    void func_0202704c(void *, void *, s32, s32);
    s32 func_0206527c(void *, void *, s32);
    u8 *base;
    s32 cnt;
    u8 *r6;
    u8 *r9;
    u8 *r10;
    s32 t;
    s32 r3count;
    s32 r2;
    s32 length;
    if (!*(u32 *)((u8 *)arg0 + 0x5a4) || !*(u32 *)((u8 *)arg0 + 0x5a8) ||
        !*(u32 *)((u8 *)arg1 + 0x10) || !*(u32 *)((u8 *)arg1 + 0xc) ||
        !*(u32 *)((u8 *)arg1 + 0x8) || !(length=*(s32 *)((u8 *)arg1 + 0x4))) {
        return 2;
    }
    cnt = (length * 2) / 2;
    {
        void *(*alloc)(u32) = (void *(*)(u32))data_021372a4[0];
        base = (u8 *)alloc((u32)(cnt * 8));
    }
    if (base == 0) {
        return 2;
    }
    r6 = base + cnt * 2;
    r9 = r6 + cnt * 2;
    r10 = r9 + cnt * 2;
    func_02026ff0(r6, *(void **)((u8 *)arg0 + 0x5a4), *(void **)((u8 *)arg0 + 0x5a8), cnt);
    func_02026ff0(r9, *(void **)((u8 *)arg1 + 0x10), *(void **)((u8 *)arg1 + 0xc), cnt);
    func_02026ff0(r10, *(void **)((u8 *)arg1 + 0x8), *(void **)((u8 *)arg1 + 0x4), cnt);
    t = func_020220b8();
    func_020269dc(base, r6, (s32)r9, cnt, r10);
    func_02022104(t);
    func_0202704c(r6, base, *(s32 *)((u8 *)arg1 + 0x4), cnt);
    t = base[cnt * 2];
    cnt = 0;
    if (t != 0 || r6[1] != 1) {
        cnt = 2;
        goto done;
    }
    r3count = *(s32 *)((u8 *)arg1 + 4);
    r2 = 2;
    while (r2 < r3count) {
        if (r6[r2] != 0xff) break;
        r2++;
    }
    if (r2 + 1 >= r3count) goto bad;
    if (r6[r2] != 0 || r6[r2 + 1] != 0x30) goto bad;
    {
        s32 field = *(s32 *)((u8 *)arg0 + 0x47c);
        if (!func_0206527c((u8 *)arg0 + 0x468, r6 + r3count - field, field)) goto done;
    }
bad:
    cnt = 2;
done:
    {
        void (*freefn)(void *) = (void (*)(void *))data_021372d0[0];
        freefn(base);
    }
    return cnt;
}
