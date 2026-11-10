/* 11 functions from 0x020362D4 to 0x02037214 (main), found by ds-decomp. */
#include "common.h"
extern void *gWfcMatchSession;
extern s32 data_020fb2f8;
extern s32 data_0213d13c[];
extern s32 data_0212dca4[];
extern u8 sWfcMatchPath[], sWfcProfilePath[], sWfcParamRegion[], sWfcParamEncoding[], sWfcEncodingUtf16[], sWfcParamType[], sWfcTypeQuery[], sWfcParamWords[];

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
    s32 r;

    p = M2C_FIELD(&data_0213d138, void **, 0x10);
    if (p == 0 || M2C_FIELD(p, s32 *, 0x38) == 0) {
        return 4;
    }

    if (M2C_FIELD(p, s32 *, 0x3c) == 0) {
        if (M2C_FIELD(p, u64 *, 0x40) != 0 && M2C_FIELD(p, u64 *, 0x40) < func_02007004()) {
            M2C_FIELD(p, s32 *, 0x3c) = 2;
            M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0x38) = 3;
            func_02021750(M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0), 2);
            func_0202175c(M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0));
        }
    }

    switch (M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0x38)) {
    case 1:
        r = func_02021558(M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0),
                          (char *)M2C_FIELD(&data_0213d138, void **, 0x10) + 4);
        if (r < 0 && r != -26) {
            M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0x3c) = 3;
            M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0x38) = 3;
            func_02021750(M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0), 2);
            func_0202175c(M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0));
            return 0;
        }
        func_0203667c();
        return 0;
    case 2:
        func_02036718();
        return 0;
    case 3:
        r = M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0x3c);
        func_020376d8(0, M2C_FIELD(&data_0213d138, void **, 0x10), 0);
        M2C_FIELD(&data_0213d138, void **, 0x10) = 0;
        return r;
    default:
        M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0x3c) = 3;
        M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0x38) = 3;
        func_02021750(M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0), 2);
        func_0202175c(M2C_FIELD(M2C_FIELD(&data_0213d138, void **, 0x10), s32 *, 0));
        return 0;
    }
}

void func_0203667c(void) {
 s32 func_02021688(s32,M2C_UNK *,s32); M2C_UNK func_02021750(s32,s32); M2C_UNK func_0202175c(s32); s32 StringLength(M2C_UNK *);
 extern M2C_UNK data_020fb968; extern M2C_UNK data_0213d138;
 s32 x;
 x=StringLength(&data_020fb968);
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
s32 func_020215b4(s32,void *,s32);M2C_UNK func_02021750(s32,s32);M2C_UNK func_0202175c(s32);s32 StringCompareN(void *,void *,s32);
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
else if(StringCompareN(p+20+i,&data_020fb99c,3)!=0)M2C_FIELD(p,s32 *,60)=2;
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
s32 StringLength(M2C_UNK *);s32 func_0200f0ac(void *,void *);s64 func_0200f7e0(void *,void *);void StringCopy(void *,const char *);s32 ParseInt();s32 StringCompare(void *,void *);
extern M2C_UNK data_020fba00,data_0213d1b4;extern s32 data_0213e9f4;extern char *data_020fb9d0[];
s32 date[4],time[3];char buf[32];s64 now,t;s32 i,n;
n=StringLength((M2C_UNK *)arg0);
if(n!=StringLength(&data_020fba00)||arg0[7]!=32||arg0[11]!=32||arg0[16]!=32||arg0[19]!=58||arg0[22]!=58||arg0[25]!=32)goto fail;
if(func_0200f0ac(date,time))goto fail;
now=func_0200f7e0(date,time);if(now==-1)goto fail;
StringCopy(buf,arg0);buf[7]=0;buf[11]=0;buf[16]=0;buf[19]=0;buf[22]=0;buf[25]=0;
data_0213e9f4=0;date[0]=ParseInt(buf+12);if(data_0213e9f4==34)goto fail;date[0]-=2000;
date[1]=13;for(i=0;i<12;i++){if(!StringCompare(data_020fb9d0[i],buf+8)){date[1]=i+1;break;}}
if((u32)date[1]>12)goto fail;
data_0213e9f4=0;date[2]=ParseInt(buf+5);if(data_0213e9f4==34)goto fail;
data_0213e9f4=0;time[0]=ParseInt(buf+17);if(data_0213e9f4==34)goto fail;
data_0213e9f4=0;time[1]=ParseInt(buf+20);if(data_0213e9f4==34)goto fail;
data_0213e9f4=0;time[2]=ParseInt(buf+23);if(data_0213e9f4==34)goto fail;
t=func_0200f7e0(date,time);if(t==-1)goto fail;
M2C_FIELD(&data_0213d1b4,s64 *,12)=now-t;M2C_FIELD(&data_0213d1b4,s64 *,4)=now;M2C_FIELD(&data_0213d1b4,s32 *,0)=1;return 1;
fail:return 0;
}

/* Creates a Nintendo WFC match: allocates and configures the session, loads the
 * profile, then uploads the region, type and tab-separated player-name
 * parameters. Returns 1 on success, 0 on failure. */
M2C_UNK CreateWfcMatch(s32 names,s32 count,s32 typeValue,s32 timeout,s32 flagsOut,s32 countOut,s8 *region) {
 s32 func_0206cd90();void func_0206cdac();void func_02007f8c();M2C_UNK func_02037694();M2C_UNK func_020376d8();void func_02068d18();void *StringFind();void MI_CpuCopy8();s32 func_02033ccc();s32 func_020336c0();s32 func_02033988();s32 func_020346d0();s32 func_020347dc();s32 func_02033de8();s32 func_02006028();void func_02033e80();M2C_UNK func_02034480(void *);void func_020371f4();void func_02037204();
 s32 options[7];u8 work[0x94];s32 totalLen,i,pos,n;u16 *namesBuf=0;void *p;
 if(!names||count<=0||count>50||!flagsOut||!countOut)return 0;
 totalLen=0;for(i=0;i<count;i++)totalLen+=func_0206cd90(((s32 *)names)[i])+1;
 if(totalLen-1<=0||totalLen-1>500)return 0;
 if(gWfcMatchSession)return 0;
 func_02007f8c(flagsOut,0,count);
 gWfcMatchSession=(void *)func_02037694(0,0x1d28);
 if(!gWfcMatchSession)goto fail;
 func_02007f8c(gWfcMatchSession,0,0x1d28);
 M2C_FIELD(gWfcMatchSession,s32 *,0x1c14)=0;
 func_02007f8c(work,0,0x94);
 M2C_FIELD(gWfcMatchSession,s32 *,0x1d1c)=flagsOut;
 M2C_FIELD(gWfcMatchSession,s32 *,0x1d20)=countOut;
 M2C_FIELD(gWfcMatchSession,s32 *,0x1d24)=count;
 func_02068d18(gWfcMatchSession+0x1c18,data_020fb2f8,256);
 M2C_FIELD(gWfcMatchSession,u8 *,0x1d18)=0;
 p=StringFind(gWfcMatchSession+0x1c18,sWfcMatchPath);
 if(!p)goto fail;
 MI_CpuCopy8(sWfcProfilePath,p,4);
 p=gWfcMatchSession+0x1c18;
 options[0]=(s32)p;options[1]=0;options[2]=0x400;options[3]=(s32)func_020371f4;options[4]=(s32)func_02037204;options[5]=0;if(timeout<=0)options[6]=10000;else options[6]=timeout;
 if(func_02033ccc(gWfcMatchSession,options)!=0)goto fail;
 M2C_FIELD(gWfcMatchSession,s32 *,0x1c14)=1;
 if(!func_020336c0(work))goto fail;
 if(!func_02033988(gWfcMatchSession,work,data_0213d13c[0]))goto fail;
 if(func_020346d0(gWfcMatchSession,sWfcParamRegion,region,1))goto fail;
 if(func_020346d0(gWfcMatchSession,sWfcParamEncoding,sWfcEncodingUtf16,8))goto fail;
 if(typeValue&&func_020346d0(gWfcMatchSession,sWfcParamType,typeValue,4))goto fail;
 if(func_020347dc(gWfcMatchSession,sWfcTypeQuery))goto fail;
 namesBuf=(u16 *)func_02037694(0,totalLen*2);
 if(!namesBuf)goto fail;
 pos=0;for(i=0;i<count;i++){func_0206cdac(namesBuf+pos,((s32 *)names)[i]);n=pos+func_0206cd90(((s32 *)names)[i]);if(n>=totalLen-1)break;namesBuf[n]=9;pos=n+1;}
 if(func_020346d0(gWfcMatchSession,sWfcParamWords,namesBuf,(totalLen-1)*2))goto fail;
 func_020376d8(0,namesBuf,0);namesBuf=0;
 if(func_02033de8(gWfcMatchSession))goto fail;
 n=func_02006028(data_0212dca4[1]);
 func_02033e80(gWfcMatchSession,n-1);
 if(M2C_FIELD(gWfcMatchSession,s32 *,0x1ba4))return 1;
fail:
 if(namesBuf)func_020376d8(0,namesBuf,0);
 if(gWfcMatchSession){if(M2C_FIELD(gWfcMatchSession,s32 *,0x1c14)==1)func_02034480(gWfcMatchSession);func_020376d8(0,gWfcMatchSession,0);gWfcMatchSession=0;}
 return 0;
}

void func_02036ec0(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g) {
 M2C_UNK CreateWfcMatch(s32,s32,s32,s32,s32,s32,s8 *);
 s8 x[1];
 switch(g) {case 255: x[0]=65; break; default: x[0]=*(s8 *)0x027ffe0f; break;}
 CreateWfcMatch(a,b,c,d,e,f,x);
}

s32 func_02036f14(void) {
    s32 func_02005d90(void *);
    u32 func_0202f248();
    M2C_UNK func_02034480(void *);
    s32 func_0203703c();
    M2C_UNK func_02037638(M2C_UNK, s32);
    extern void *gWfcMatchSession;
    s32 tmp;
    s32 var_r4;
    u32 temp_r0;
    u32 var_r2;

    if (gWfcMatchSession != 0) {
        tmp = M2C_FIELD(gWfcMatchSession, s32 *, 0x1BA4);
    }
    if (tmp == 0) return 0;
    if (func_02005d90(gWfcMatchSession + 0x1B38) != 1) return 1;
    var_r2 = func_0202f248();
    if (var_r2 > 0x63U) {
        var_r2 = 0x63;
    }
    temp_r0 = M2C_FIELD(gWfcMatchSession, u32 *, 0x1020);
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
    func_02034480(gWfcMatchSession);
    func_020376d8(0, gWfcMatchSession, 0);
    gWfcMatchSession = 0;
    return var_r4;
}

s32 func_0203703c(void) {
s32 func_02034c58(void *,s32); s32 func_02034ef8(void *,void *); s32 func_02036860(); s32 ParseInt(); s32 func_02034f50(void *,void *,void *,s32); s32 func_02037638(s32,s32);
extern void *gWfcMatchSession; extern s32 data_0213e9f4;
extern u8 data_020fba60[],data_020fba68[],data_020fba74[],data_020fba80[];
s32 value; s8 buf[51]; void *p=gWfcMatchSession; s32 r,i;
if(func_02034c58(p,0)) {
if(func_02034ef8(p,data_020fba60))func_02036860();
if(func_02034ef8(p,data_020fba68)){
r=ParseInt();
if(data_0213e9f4!=34 && r==200 && func_02034f50(p,data_020fba74,&value,4)>0){
r=ParseInt(&value);
if(data_0213e9f4!=34){
if(r==1)goto error;
if(r<100)goto readbuf;
if(r==100)goto readbuf;
error:
func_02037638(18,-33000-r);return 0;
readbuf:
func_02034f50(p,data_020fba80,buf,51);
process:
*M2C_FIELD(gWfcMatchSession,s32 **,0x1d20)=0;
for(i=0;i<M2C_FIELD(gWfcMatchSession,s32 *,0x1d24);i++){
if(buf[i]=='0')M2C_FIELD(gWfcMatchSession,u8 **,0x1d1c)[i]=0;
else {M2C_FIELD(gWfcMatchSession,u8 **,0x1d1c)[i]=1; ++*M2C_FIELD(gWfcMatchSession,s32 **,0x1d20);}
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

