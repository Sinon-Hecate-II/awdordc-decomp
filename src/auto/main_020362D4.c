/* 11 functions from 0x020362D4 to 0x02037214 (main), found by ds-decomp. */
#include "common.h"

s32 func_020362d4(s32 arg0){
M2C_UNK func_02037694();void func_02007f8c(void *,s32,s32);s32 func_02021500(s32,s32,s32);s32 func_020219e8(s32,s32,s32);s32 func_02021558(s32,void *);s32 func_02021750(s32,s32);s32 func_0202175c(s32);M2C_UNK func_020376d8();u64 func_02007004(void);extern M2C_UNK data_0213d138;
s32 r;u32 ip;
if(M2C_FIELD(&data_0213d138,void **,16)||!M2C_FIELD(&data_0213d138,u32 *,8))return 0;
M2C_FIELD(&data_0213d138,void **,16)=func_02037694(0,72);
if(!M2C_FIELD(&data_0213d138,void **,16))return 0;
func_02007f8c(M2C_FIELD(&data_0213d138,void **,16),0,72);
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0)=-1;
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0)=func_02021500(2,1,0);
if(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0)<0){func_020376d8(0,M2C_FIELD(&data_0213d138,void **,16),0);M2C_FIELD(&data_0213d138,void **,16)=0;return 0;}
r=func_020219e8(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0),3,0);
func_020219e8(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0),4,r|4);
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),u8 *,4)=8;
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),u8 *,5)=2;
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),u16 *,6)=0x5000;
ip=M2C_FIELD(&data_0213d138,u32 *,8);
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),u32 *,8)=((ip>>24)&255)|((ip>>8)&0xff00)|((ip<<8)&0xff0000)|((ip<<24)&0xff000000);
r=func_02021558(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0),M2C_FIELD(&data_0213d138,void **,16)+4);
if(r<0&&r!=-26){
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,60)=3;
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,56)=3;
func_02021750(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0),2);func_0202175c(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0));return 1;}
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,56)=1;
if(arg0>0)M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),u64 *,64)=func_02007004()+((u64)((s64)arg0*0x82ea)>>6);
else M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),u64 *,64)=func_02007004()+0x17f898;
return 1;}

s32 func_020364f4(void) {
    u64 func_02007004(void);
    s32 func_02021558(M2C_UNK, void *);
    M2C_UNK func_02021750(s32, s32);
    M2C_UNK func_0202175c(s32);
    void func_0203667c(void);
    void func_02036718(void);
    M2C_UNK func_020376d8(s32, M2C_UNK *, s32);
    extern M2C_UNK data_0213d138;

    void *p;

    p = M2C_FIELD(&data_0213d138, void **, 0x10);
    if (p == 0 || M2C_FIELD(p, s32 *, 0x38) == 0) {
        return 4;
    }

    if (M2C_FIELD(p, s32 *, 0x3c) == 0) {
        if (M2C_FIELD(p, u32 *, 0x44) != 0 || M2C_FIELD(p, u32 *, 0x40) != 0) {
            u64 now;
            u32 hi;
            u32 lo;
            u32 nowHi;
            u32 nowLo;
            now = func_02007004();
            hi = M2C_FIELD(p, u32 *, 0x44);
            lo = M2C_FIELD(p, u32 *, 0x40);
            nowHi = (u32)(now >> 32);
            nowLo = (u32)now;
            if (hi < nowHi || (hi == nowHi && lo < nowLo)) {
                M2C_FIELD(p, s32 *, 0x3c) = 2;
                M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0x38) = 3;
                func_02021750(M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0), 2);
                func_0202175c(M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0));
            }
        }
    }

sw: {
        void *pp;
        s32 st;
        pp = M2C_FIELD(&data_0213d138, void **, 0x10);
        st = M2C_FIELD(pp, s32 *, 0x38);
        if (st == 1) goto case1;
        if (st == 2) goto case2;
        if (st == 3) goto case3;
        goto def;
    }

case1: {
        void *pp;
        s32 r;
        pp = M2C_FIELD(&data_0213d138, void **, 0x10);
        r = func_02021558(M2C_FIELD(pp, s32 *, 0), (void *)((char *)pp + 4));
        if (r < 0) {
            if (r != -26) goto err;
        }
        goto ok;
    }

err: {
        void *pp;
        pp = M2C_FIELD(&data_0213d138, void **, 0x10);
        M2C_FIELD(pp, s32 *, 0x3c) = 3;
        M2C_FIELD(pp, s32 *, 0x38) = 3;
        func_02021750(M2C_FIELD(pp, s32 *, 0), 2);
        func_0202175c(M2C_FIELD(pp, s32 *, 0));
        return 0;
    }

ok:
    func_0203667c();
    return 0;

case2:
    func_0203667c();
    return 0;

case3:
    func_02036718();
    return 0;

def: {
        void *pp;
        s32 saved;
        pp = M2C_FIELD(&data_0213d138, void **, 0x10);
        saved = M2C_FIELD(pp, s32 *, 0x3c);
        func_020376d8(0, pp, 0);
        M2C_FIELD(&data_0213d138, void **, 0x10) = 0;
        return saved;
    }
}

void func_0203667c(void) {
 s32 func_02021688(s32,M2C_UNK *,s32); M2C_UNK func_02021750(s32,s32); M2C_UNK func_0202175c(s32); s32 func_02068c34(M2C_UNK *);
 extern M2C_UNK data_020fb968; extern M2C_UNK data_0213d138;
 s32 x;
 x=func_02068c34(&data_020fb968);
 x=func_02021688(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0),&data_020fb968,x);
 if(x==-56) return;
 if(x<=0) {
 M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,60)=2;
 M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,56)=3;
 func_02021750(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0),2);
 func_0202175c(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0)); return;
 }
 M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,56)=2;
 M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,52)=0;
}

void func_02036718(void) {
s32 func_020215b4(s32,void *,s32);M2C_UNK func_02021750(s32,s32);M2C_UNK func_0202175c(s32);s32 func_02068eac(void *,void *,s32);
extern M2C_UNK data_0213d138,data_020fb99c;
s32 r,i;void *p; s8 *scan;
p=M2C_FIELD(&data_0213d138,void **,16);
r=func_020215b4(M2C_FIELD(p,s32 *,0),p+20+M2C_FIELD(p,s32 *,52),32-M2C_FIELD(p,s32 *,52));
if(r==-6)return;
if(r>=0) {
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,52)+=r;
if(r==0||M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,52)>=32){
p=M2C_FIELD(&data_0213d138,void **,16);
for(i=0,scan=p;scan[20]!=32&&i<32;scan++,i++);
i++;
if(i>=32)M2C_FIELD(p,s32 *,60)=2;
else if(func_02068eac(p+20+i,&data_020fb99c,3)!=0)M2C_FIELD(p,s32 *,60)=2;
else M2C_FIELD(p,s32 *,60)=1;
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,56)=3;
func_02021750(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0),2);
func_0202175c(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0));
}
}else{
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,60)=2;
M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,56)=3;
func_02021750(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0),2);
func_0202175c(M2C_FIELD(M2C_FIELD(&data_0213d138,void **,16),s32 *,0));
}
}

s32 func_02036860(const char *arg0){
s32 func_02068c34(M2C_UNK *);s32 func_0200f0ac(void *,void *);s64 func_0200f7e0(void *,void *);void func_02068c50(void *,const char *);s32 func_0206ad38();s32 func_02068d98(void *,void *);
extern M2C_UNK data_020fba00,data_0213d1b4;extern s32 data_0213e9f4;extern char *data_020fb9d0[];
s32 date[4],time[3];char buf[32];s64 now,t;s32 i,n;
n=func_02068c34((M2C_UNK *)arg0);
if(n!=func_02068c34(&data_020fba00)||arg0[7]!=32||arg0[11]!=32||arg0[16]!=32||arg0[19]!=58||arg0[22]!=58||arg0[25]!=32)goto fail;
if(func_0200f0ac(date,time))goto fail;
now=func_0200f7e0(date,time);if(now==-1)goto fail;
func_02068c50(buf,arg0);buf[7]=0;buf[11]=0;buf[16]=0;buf[19]=0;buf[22]=0;buf[25]=0;
data_0213e9f4=0;date[0]=func_0206ad38(buf+12);if(data_0213e9f4==34)goto fail;date[0]-=2000;
date[1]=13;for(i=0;i<12;i++){if(!func_02068d98(data_020fb9d0[i],buf+8)){date[1]=i+1;break;}}
if((u32)date[1]>12)goto fail;
data_0213e9f4=0;date[2]=func_0206ad38(buf+5);if(data_0213e9f4==34)goto fail;
data_0213e9f4=0;time[0]=func_0206ad38(buf+17);if(data_0213e9f4==34)goto fail;
data_0213e9f4=0;time[1]=func_0206ad38(buf+20);if(data_0213e9f4==34)goto fail;
data_0213e9f4=0;time[2]=func_0206ad38(buf+23);if(data_0213e9f4==34)goto fail;
t=func_0200f7e0(date,time);if(t==-1)goto fail;
M2C_FIELD(&data_0213d1b4,s64 *,12)=now-t;M2C_FIELD(&data_0213d1b4,s64 *,4)=now;M2C_FIELD(&data_0213d1b4,s32 *,0)=1;return 1;
fail:return 0;
}

M2C_UNK func_02036a7c(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s8 *g) { return 0; }

void func_02036ec0(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g) {
 M2C_UNK func_02036a7c(s32,s32,s32,s32,s32,s32,s8 *);
 s8 x[1];
 switch(g) {case 255: x[0]=65; break; default: x[0]=*(s8 *)0x027ffe0f; break;}
 func_02036a7c(a,b,c,d,e,f,x);
}

s32 func_02036f14(void) {
    s32 func_02005d90(void *);
    u32 func_0202f248();
    M2C_UNK func_02034480(void *);
    s32 func_0203703c();
    M2C_UNK func_02037638(M2C_UNK, s32);
    extern void *data_0213d1c8;
    s32 tmp;
    s32 var_r4;
    u32 temp_r0;
    u32 var_r2;

    if (data_0213d1c8 != 0) {
        tmp = M2C_FIELD(data_0213d1c8, s32 *, 0x1BA4);
    }
    if (tmp == 0) return 0;
    if (func_02005d90(data_0213d1c8 + 0x1B38) != 1) return 1;
    var_r2 = func_0202f248();
    if (var_r2 > 0x63U) {
        var_r2 = 0x63;
    }
    temp_r0 = M2C_FIELD(data_0213d1c8, u32 *, 0x1020);
    switch (temp_r0) {
    case 8:
        if (func_0203703c() == 0) {
            var_r4 = 3;
        } else {
            var_r4 = 2;
        }
        break;
    case 2:
        func_02037638(8, 0xFFFF347C - var_r2);
        var_r4 = 3;
        break;
    case 3:
    case 4:
    case 6:
        func_02037638(0x13, 0xFFFF7F0E);
        var_r4 = 3;
        break;
    default:
    case 0:
    case 1:
    case 5:
    case 7:
        func_02037638(0x13, 0xFFFF7EFA);
        var_r4 = 3;
        break;
    }
    func_02034480(data_0213d1c8);
    func_020376d8(0, data_0213d1c8, 0);
    data_0213d1c8 = 0;
    return var_r4;
}

s32 func_0203703c(void) {
s32 func_02034c58(void *,s32); s32 func_02034ef8(void *,void *); s32 func_02036860(); s32 func_0206ad38(); s32 func_02034f50(void *,void *,void *,s32); s32 func_02037638(s32,s32);
extern void *data_0213d1c8; extern s32 data_0213e9f4;
extern u8 data_020fba60[],data_020fba68[],data_020fba74[],data_020fba80[];
s32 value; s8 buf[51]; void *p=data_0213d1c8; s32 r,i;
if(func_02034c58(p,0)) {
if(func_02034ef8(p,data_020fba60))func_02036860();
if(func_02034ef8(p,data_020fba68)){
r=func_0206ad38();
if(data_0213e9f4!=34 && r==200 && func_02034f50(p,data_020fba74,&value,4)>0){
r=func_0206ad38(&value);
if(data_0213e9f4!=34){
if(r==1)goto error;
if(r<100)goto readbuf;
if(r==100)goto readbuf;
error:
func_02037638(18,-33000-r);return 0;
readbuf:
func_02034f50(p,data_020fba80,buf,51);
process:
*M2C_FIELD(data_0213d1c8,s32 **,0x1d20)=0;
for(i=0;i<M2C_FIELD(data_0213d1c8,s32 *,0x1d24);i++){
if(buf[i]=='0')M2C_FIELD(data_0213d1c8,u8 **,0x1d1c)[i]=0;
else {M2C_FIELD(data_0213d1c8,u8 **,0x1d1c)[i]=1; ++*M2C_FIELD(data_0213d1c8,s32 **,0x1d20);}
}return 1;
}
}
}
}
func_02037638(18,-33020);return 0;
}

void func_020371f4(void) {
    M2C_UNK func_02037694(M2C_UNK);
    func_02037694(0);
}

void func_02037204(void) {
    M2C_UNK func_020376d8(M2C_UNK);
    func_020376d8(0);
}

