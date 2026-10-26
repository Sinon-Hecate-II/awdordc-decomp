/* 30 functions from 0x0205CB68 to 0x0205DA30 (main), found by ds-decomp. */
#include "common.h"
struct BytePair_0205 { u8 v[2]; };
struct Packet_0205 { u8 a,b; u16 c; s32 d; };

s32 func_0205cb68(s32 a, s32 b, s32 c) {
    s32 func_0205d228(s32,s32,s32,void *,s32);
    extern u8 data_020ff818[];
    u8 v[3];
    v[2]=0x68;
    v[0]=data_020ff818[0];
    v[1]=data_020ff818[1];
    return func_0205d228(a,b,c,v,3)!=0;
}

s32 func_0205cbb4(void *a, s32 *b) {
    void func_0205b0ec(void *,s32,u16);
    s32 func_0205a9ec(void *,void *,s32);
    func_0205b0ec(M2C_FIELD(a,void **,0x50),b[0]+5,M2C_FIELD(a,u16 *,0x66));
    if (!func_0205a9ec(a,M2C_FIELD(a,u8 **,0x50)+b[0],b[1])) return 0;
    b[3]=M2C_FIELD(a,s32 *,0x88);
    if (M2C_FIELD(a,u8 **,0x50)[b[0]+2]==2)
        M2C_FIELD(a,s32 *,0x8c)=M2C_FIELD(a,s32 *,0x88);
    return 1;
}

void func_0205cc20(s32 a, s32 b, s32 c, s32 d) {
    M2C_UNK func_0205c620();
    M2C_UNK func_0205c980();
    if (d) { func_0205c620(); return; }
    func_0205c980();
}

s32 func_0205cc3c(void **a,s32 b) {
    void *p=*a;
    return (M2C_FIELD(p,s32 *,0)*M2C_FIELD(p,u16 *,4))%b;
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

s32 func_0205cca0(void *p,s32 a,s16 b) {
s32 *func_02048ff8(s32,void *);
s32 data[40]; void *ptr; s32 *res;
data[0]=a; M2C_FIELD(data,s16 *,4)=b; ptr=data;
res=func_02048ff8(M2C_FIELD(p,s32 *,12),&ptr);
if(res)return *res;return 0;
}

void func_0205cef8(void *arg0) {
    M2C_UNK func_020377c4(void *);
    M2C_UNK func_02048dc4(s32);
    M2C_UNK func_02049270();
    M2C_UNK func_020496b8(s32);
    if (M2C_FIELD(arg0, s32 *, 0x1C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x14) = 1;
        return;
    }
    func_020496b8(M2C_FIELD(arg0, s32 *, 0));
    func_02048dc4(M2C_FIELD(arg0, s32 *, 0xC));
    func_0204861c(M2C_FIELD(arg0, s32 *, 0x10));
    func_020377c4(arg0);
    func_02049270();
}

void func_0205cf3c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
}

void func_0205cf44(void) {
    M2C_UNK func_02037794(M2C_UNK);
    func_02037794(0xA0);
}

s32 func_0205d164(s32 arg) {
    s32 func_02048688(s32);
    s32 *func_02048690(s32, s32);
    void func_0204890c(s32, s32);
    void func_02048f54(s32, void *);
    void *p = (void *)arg;
    if (M2C_FIELD(p, s32 *, 0x14) != 0 || M2C_FIELD(p, s32 *, 0x24) != 0) {
        return 0;
    }
    if (M2C_FIELD(p, s32 *, 0x0c) != 7) {
        func_02048f54(M2C_FIELD((void *)M2C_FIELD(p, s32 *, 0x08), s32 *, 0x0c), &p);
        return 0;
    }
    {
        s32 base = M2C_FIELD((void *)M2C_FIELD(p, s32 *, 0x08), s32 *, 0x10);
        s32 n = func_02048688(base);
        s32 i;
        if (n <= 0) return 0;
        for (i = 0; i < n; i++) {
            s32 *item = func_02048690(base, i);
            if (arg == (s32)item[0]) {
                func_0204890c(base, i);
                return 0;
            }
        }
    }
    return 0;
}

s32 func_0205d3d0(void **a,void **b) {
void *p=*a; void *q=*b;
if(M2C_FIELD(p,s32 *,12)!=7) {
if(!func_0205abb4(p,q))return 0;
}
if(M2C_FIELD(p,s32 *,12)==7 && M2C_FIELD(p,s32 *,20)==0 && M2C_FIELD(p,s32 *,36)==0)func_0205d164(p);
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
if (M2C_FIELD(a,s32 *,0x18)) return;
M2C_FIELD(a,s32 *,0x18)=1;
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
p.d=b; c=((c>>8)&255)|((c<<8)&0xff00); p.b=2; p.c=c;
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

