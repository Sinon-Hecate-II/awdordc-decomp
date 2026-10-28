/* 25 functions from 0x02047B84 to 0x02048B74 (main), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_020fcb8c;
extern M2C_UNK data_020fca58, data_020fca68;
extern M2C_UNK data_020fca58, data_020fca68;
extern M2C_UNK data_020fcb1c, data_020fcb24, data_020fcac0, data_020fcb50, data_020fcba0, data_020fcb88, data_020fcb6c;
extern u8 data_020fca88[56];
extern M2C_UNK data_020fcd10, data_020fcc5c, data_020fcc84;
extern M2C_UNK data_020fcc4c,data_020fcd04,data_020fcc70,data_020fcc1c;
extern M2C_UNK data_020fccc4, data_020fcc2c, data_020fccb0, data_020fcbf8, data_020fcbe0, data_020fcce4, data_020fcc3c;
extern M2C_UNK data_0213db90, data_020fcbdc;
extern s32 gDnsQueryState[];
extern M2C_UNK data_020fcc98, data_020fcca4, data_020fcc04;

// Validates dialog box parameters (a's id < 32, b's id == 20, c adjusted by 5 multiple of 8,
// d odd, e has exactly one bit set), copies a (32 bytes) into data_020fca68, copies 10 (x,y) pairs
// from b into data_020fca88, stores c,d,e,f into the state and marks it active.
s32 func_02047b84(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    s32 func_02047370(void *);
    void func_020376d8(s32, s32, s32);
    void *func_02037694(s32, s32);
    s32 func_0204760c(void *, void *, s32, void *, s32);
    s32 func_02068c34(M2C_UNK);
    void *func_0206f8b8(void *, void *, s32);

    s32 r5 = 0;
    void *g = &data_020fca58;
    void *ptr;
    M2C_UNK tmp;
    s32 len_cb1c, len_cb24, len_cac0, len_after;
    s32 len_cb50, len_cb8c, len_data0, len_cb88;
    s32 accum;
    s32 len_ptr;
    s32 len_cb1c2, len_cb242;
    u32 arr[5];
    s32 res;
    s32 len_cac0b;

    if (M2C_FIELD(g, s32 *, 0x0c) != 1) {
        return 3;
    }

    if (M2C_FIELD(g, s32 *, 0x54) != 0) {
        func_020376d8(0, M2C_FIELD(g, s32 *, 0x54), 0);
        M2C_FIELD(g, s32 *, 0x54) = 0;
        r5 = func_02047370((void *)((s32 *)arg4)[0] + 0x18);
    }

    len_cb1c = func_02068c34(data_020fcb1c);
    len_cb24 = func_02068c34(data_020fcb24);
    len_cac0 = func_02068c34(data_020fcac0);

    len_after = func_02068c34(func_0206f8b8((void *)arg2, &tmp, 10));

    len_cb50 = func_02068c34(data_020fcb50);
    len_cb8c = func_02068c34(data_020fcb8c);
    len_data0 = func_02068c34(M2C_FIELD(g, M2C_UNK *, 0x00));
    len_cb88 = func_02068c34(data_020fcb88);

    accum = len_data0 + len_cb88;
    accum = len_cb8c + accum;
    accum = len_cb50 + accum;
    accum = len_after + accum;
    accum = len_cac0 + accum;
    accum = len_cb24 + accum;
    accum = len_cb1c + accum;
    accum = r5 + accum;

    ptr = func_02037694(0, accum + 1);
    M2C_FIELD(g, void **, 0x54) = ptr;
    if (ptr == 0) {
        return 2;
    }

    func_020675e4(ptr, data_020fcb6c,
                    M2C_FIELD(g, s32 *, 0x00),
                    data_020fca68,
                    data_020fcb8c, arg2, data_020fcb24, data_020fcb88);

    len_ptr = func_02068c34(ptr);
    M2C_FIELD(g, void **, 0x5c) = (void *)((u8 *)ptr + len_ptr);

    len_cb1c2 = func_02068c34(data_020fcb1c);
    len_cb242 = func_02068c34(data_020fcb24);
    M2C_FIELD(g, s32 *, 0x58) =
        (s32)M2C_FIELD(g, void **, 0x5c) - len_cb1c2 - len_cb242;

    arr[0] = (u32)arg2;
    arr[1] = (u32)arg3;
    arr[2] = (u32)arg1;
    arr[3] = (u32)arg0;
    arr[4] = (u32)*(u32 *)arg4;

    res = func_0204760c(M2C_FIELD(g, void **, 0x5c), arr, 0x14, (void *)((u8 *)arg4 + 4), *(s32 *)arg4);
    if (res == 2) {
        func_020376d8(0, M2C_FIELD(g, s32 *, 0x54), 0);
        M2C_FIELD(g, s32 *, 0x54) = 0;
        return 2;
    } else {
        len_cac0b = func_02068c34(data_020fcac0);
        *(u8 *)((u8 *)M2C_FIELD(g, void **, 0x58) - len_cac0b) = 0;
        M2C_FIELD(g, s32 *, 0x04) = 4;
        return 0;
    }
}

s32 func_0204800c(u8 *a, u8 *b, s32 c, u32 d, u32 e, s32 f) {
    s32 func_02068c34();
    s32 func_020651a4();
    s32 i, n;
    u32 k;
    u8 *p;
    M2C_FIELD(&data_020fca58, s32 *, 12) = 0;
    if ((u32)func_02068c34(a) >= 32) return 0;
    if (func_02068c34(b) != 20) return 0;
    if ((c - 5) & 7) return 0;
    if (!(d & 1)) return 0;
    n = 0;
    for (i = 0; i < 32; i++)
        if (((e >> i) & 1) == 1)
            n++;
    if (n != 1) return 0;
    func_020651a4(&data_020fca68, a, 32);
    k = 10;
    p = data_020fca88;
    do {
        u8 x = b[0];
        u8 y = b[1];
        b += 2;
        p[0] = x;
        p[1] = y;
        p += 2;
    } while (--k != 0);
    M2C_FIELD(&data_020fca58, s32 *, 68) = c;
    M2C_FIELD(&data_020fca58, u32 *, 72) = d;
    M2C_FIELD(&data_020fca58, u32 *, 76) = e;
    M2C_FIELD(&data_020fca58, s32 *, 80) = f;
    M2C_FIELD(&data_020fca58, s32 *, 12) = 1;
    return 1;
}

s32 func_02048108(s32 a,s32 b,void *c) {
s32 func_020498e4(s32); void *func_02021768(s32);
u16 v=b; void *p;
M2C_FIELD(c,u8 *,1)=2;
M2C_FIELD(c,u16 *,2)=((u8)((s32)v>>8))|((v<<8)&0xff00);
M2C_FIELD(c,s32 *,4)=func_020498e4(a);
if(M2C_FIELD(c,s32 *,4)==-1) {
p=func_02021768(a);if(!p)return 0;
M2C_FIELD(c,s32 *,4)=**M2C_FIELD(p,s32 ***,12);
}
return 1;
}

void func_0204817c(void) {
    s32 func_02049208();
    M2C_UNK func_02049824(s32, M2C_UNK *, s32, M2C_UNK, M2C_UNK *, s32);
    extern s32 gDnsQueryState[];
    extern M2C_UNK gDnsPacketHeader;
    extern M2C_UNK data_0213db94;
    func_02049824(M2C_FIELD(&gDnsQueryState, s32 *, 4), &data_0213db94, M2C_FIELD(&gDnsQueryState, s32 *, 0x50), 0, &gDnsPacketHeader, 8);
    M2C_FIELD(&gDnsQueryState, s32 *, 0x54) = func_02049208();
}

/* Sets up a DNS query for service availability for the given service name. */
void InitServiceAvailabilityQuery(s8 *serviceName) {
    s32 func_02068c50(); s32 func_0204926c(); s32 func_020675e4(); s32 func_020496a4(); s32 func_02068c34(); s32 func_020651a4();
    extern M2C_UNK gServiceNameBuffer, gOverrideDnsName, gServiceAvailabilityFormat, gDnsPacketHeader, gDnsQueryNameBuffer;
    s8 hostNameBuffer[64]; s32 hasOverride, dnsNameLength;
    func_02068c50(&gServiceNameBuffer, serviceName);
    M2C_FIELD(&gDnsQueryState, s32 *, 4) = -1;
    func_0204926c(&gDnsQueryState);
    hasOverride = M2C_FIELD(&gOverrideDnsName, s8 *, 0);
    if (!hasOverride) func_020675e4(hostNameBuffer, &gServiceAvailabilityFormat, serviceName);
    if (!func_02048108(hasOverride ? (s8 *)&gOverrideDnsName : hostNameBuffer, 0x6cfc, &gDnsPacketHeader)) return;
    M2C_FIELD(&gDnsQueryState, s32 *, 4) = func_020496a4(2, 2, 0);
    if (M2C_FIELD(&gDnsQueryState, s32 *, 4) == -1) return;
    M2C_FIELD(&gDnsQueryState, s8 *, 0x10) = 9;
    dnsNameLength = func_02068c34(serviceName);
    func_020651a4(&gDnsQueryNameBuffer, serviceName, dnsNameLength + 1);
    M2C_FIELD(&gDnsQueryState, s32 *, 0x50) = dnsNameLength + 6;
    func_0204817c();
    M2C_FIELD(&gDnsQueryState, s32 *, 0x58) = 0;
}

s32 func_020482c4(s8 *a,s32 b,void *c,u32 *d) {
s32 func_0206527c(void *,void *,s32);
if(b<7)return 1;
if(func_0206527c((u8 *)c+4,&data_0213db90,4))return 1;
if(M2C_FIELD(c,u16 *,2)!=M2C_FIELD(&gDnsQueryState,u16 *,10))return 1;
if(func_0206527c(a,&data_020fcbdc,3))return 1;
{u32 x=(a[3]<<24)&0xff000000; u32 y=(a[4]<<16)&0xff0000; u32 z=(a[5]<<8)&0xff00; u32 w=(u8)a[6]; x|=y; x|=z; *d=x|w;}
return 0;
}

s32 func_0204837c(void) {
s32 func_02049534(void);
s32 func_020497e0(s32,void *,s32,s32,void *,s32 *);
s32 func_020496b8(s32);
s32 func_02049208(void);
s8 buffer[64];
u8 address[8];
s32 len;
u32 flags;
len=8;
if(-1==gDnsQueryState[1]){
gDnsQueryState[0]=1;
return 1;
}
if(func_02049534() && func_020482c4(buffer,func_020497e0(gDnsQueryState[1],buffer,64,0,address,&len),address,&flags)==0){
func_020496b8(gDnsQueryState[1]);
if(flags&1)gDnsQueryState[0]=2;
else if(flags&2)gDnsQueryState[0]=3;
else gDnsQueryState[0]=1;
return gDnsQueryState[0];
}
if((u32)func_02049208()>M2C_FIELD(&gDnsQueryState,u32 *,0x54)+2000){
if(gDnsQueryState[22]==1){
func_020496b8(gDnsQueryState[1]);
gDnsQueryState[0]=1;
return 1;
}
func_0204817c();
{s32 n=gDnsQueryState[22]+1;
gDnsQueryState[22]=n;}
}
return 0;
}

void func_020484b8(void *a,s32 b) {
s32 func_02048690(void *,s32);
if(!M2C_FIELD(a,void (**)(),16))return;
M2C_FIELD(a,void (**)(s32),16)(func_02048690(a,b));
}

void func_020484dc(void *a) {
s32 func_020377a8(s32,s32);
M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
M2C_FIELD(a,s32 *,4)+=M2C_FIELD(a,s32 *,12);
M2C_FIELD(a,s32 *,20)=func_020377a8(M2C_FIELD(a,s32 *,20),M2C_FIELD(a,s32 *,4)*M2C_FIELD(a,s32 *,8));
if(!M2C_FIELD(a,s32 *,20))func_020640a8(&data_020fcc98,&data_020fcca4,&data_020fcc04,65);
}

void func_02048534(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020651a4(s32, M2C_UNK, s32);
    func_020651a4(func_02048690(arg0, arg2), arg1, M2C_FIELD(arg0, s32 *, 8));
}

s32 *func_02048558(s32 a,s32 b,s32 c) {
s32 *func_02037794(s32); s32 func_020640a8();
extern M2C_UNK data_020fcbec,data_020fccb8;
s32 *p=func_02037794(24);
if(!p)func_020640a8(&data_020fccb0,&data_020fcca4,&data_020fcbec,0x52);
if(!a)func_020640a8(&data_020fccb8,&data_020fcca4,&data_020fcbec,0x53);
if(!b)b=8;
p[0]=0;p[1]=b;p[2]=a;p[3]=b;p[4]=c;
if(p[1]) {
p[5]=(s32)func_02037794(p[1]*p[2]);
if(!p[5])func_020640a8(&data_020fcc98,&data_020fcca4,&data_020fcbec,0x5e);
} else p[5]=0;
return p;
}

void func_0204861c(s32 *a) {
s32 func_020640a8();s32 func_020377c4();s32 i;
if(!a)func_020640a8(&data_020fccb0,&data_020fcca4,&data_020fcbf8,0x69);
for(i=0;i<a[0];i++)func_020484b8(a,i);
func_020377c4(a[5]);func_020377c4(a);
}

s32 func_02048688(s32 *arg0) {
    return *arg0;
}

s32 func_02048690(void *a,s32 b) {
s32 func_020640a8();
if(b<0||b>=M2C_FIELD(a,s32 *,0))func_020640a8(&data_020fccc4,&data_020fcca4,&data_020fcbe0,0x94);
if(b<0||b>=M2C_FIELD(a,s32 *,0))return 0;
return M2C_FIELD(a,s32 *,20)+M2C_FIELD(a,s32 *,8)*b;
}

void func_020486f8(s32 *arg0, M2C_UNK arg1) {
    M2C_UNK func_02048744(s32 *, M2C_UNK, s32);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fcc10;
    extern M2C_UNK data_020fcca4;
    extern M2C_UNK data_020fccb0;
    if (arg0 == NULL) {
        func_020640a8(&data_020fccb0, &data_020fcca4, &data_020fcc10, 0xA0);
    }
    if (arg0 == NULL) {
        return;
    }
    func_02048744(arg0, arg1, *arg0);
}

s32 func_02048744(s32 *a,s32 b,s32 c) {
s32 func_020640a8();s32 func_020651c4();s32 n,p,t;
if(c<0||c>a[0])func_020640a8(&data_020fcce4,&data_020fcca4,&data_020fcc3c,0xa7);
if(a[0]==a[1])func_020484dc(a);
t=a[0]+1;n=t-1;a[0]=t;
if(c<n){p=func_02048690(a,c+1);func_020651c4(p,func_02048690(a,c),a[2]*(n-c));}
func_02048534(a,b,c);
}

void func_020487fc(s32 *a,s32 b,s32 c){s32 func_020640a8();s32 func_02048bf8(s32,s32,s32,s32,s32,s32 *);s32 func_020720f0(s32,s32);s32 x,r;if(!c)func_020640a8(&data_020fcd04,&data_020fcca4,&data_020fcc70,0xb7);r=func_02048bf8(b,a[5],a[0],a[2],c,&x);func_02048744(a,b,func_020720f0(r-a[5],a[2]));}

s32 func_0204887c(s32 *a,s32 b){s32 func_020640a8();s32 func_020651c4(s32,s32,s32);s32 n,p,q;if(b<0||b>=a[0])func_020640a8(&data_020fccc4,&data_020fcca4,&data_020fcc1c,0xc0);n=a[0]-1;if(b<n){p=func_02048690(a,b);q=func_02048690(a,b+1);func_020651c4(p,q,a[2]*(n-b));}return --a[0];}

void func_0204890c(s32 *a,s32 b) {
s32 func_0204887c();s32 func_020640a8();
if(b<0||b>=a[0])func_020640a8(&data_020fccc4,&data_020fcca4,&data_020fcc2c,0xca);
func_020484b8(a,b);func_0204887c(a,b);
}

void func_02048964(s32 *a,s32 b,s32 c){s32 func_020640a8();if(c<0||c>=a[0])func_020640a8(&data_020fccc4,&data_020fcca4,&data_020fcc4c,0xd3);func_020484b8(a,c);func_02048534(a,b,c);}

void func_020489c4(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_02067610(s32, s32, s32, M2C_UNK);
    func_02067610(M2C_FIELD(arg0, s32 *, 0x14), M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 8), arg1);
}

s32 func_020489e4(void *a,s32 b,s32 c,s32 d,s32 e){s32 func_02048bf8(s32,s32,s32,s32,s32,s32 *);s32 func_02048ba0(s32,s32,s32,s32,s32);s32 func_020720f0(s32,s32);s32 x=1,n,r;if(!a||!(n=M2C_FIELD(a,s32 *,0)))return -1;if(e)r=func_02048bf8(b,func_02048690(a,d),n-d,M2C_FIELD(a,s32 *,8),c,&x);else r=func_02048ba0(b,func_02048690(a,d),n-d,M2C_FIELD(a,s32 *,8),c);if(!r||!x)return -1;return func_020720f0(r-M2C_FIELD(a,s32 *,20),M2C_FIELD(a,s32 *,8));}

void func_02048a9c(s32 *a,void (*b)(s32,s32),s32 c) {
s32 func_020640a8();s32 i;
if(!b)func_020640a8(&data_020fcd10,&data_020fcca4,&data_020fcc5c,0x104);
for(i=a[0]-1;i>=0;i--)b(func_02048690(a,i),c);
}

s32 func_02048afc(s32 *a,s32 (*b)(s32,s32),s32 c) {
s32 func_020640a8();s32 i,p;
if(!b)func_020640a8(&data_020fcd10,&data_020fcca4,&data_020fcc84,0x121);
for(i=a[0]-1;i>=0;i--){p=func_02048690(a,i);if(!b(p,c))return p;}
return 0;
}

