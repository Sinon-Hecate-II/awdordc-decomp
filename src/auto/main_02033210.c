/* 14 functions from 0x02033210 to 0x02034164 (main), found by ds-decomp. */
#include "common.h"
typedef struct InitConfig { s32 words[7]; } InitConfig;
typedef struct InitState { u8 pad[0x1000]; u8 flag; u8 pad2[31]; s32 status; } InitState;
extern u8 data_020fb558[], data_020fb570[];

#pragma opt_common_subs off
s32 func_020334d8(void *p,void *a,void *b){
extern M2C_UNK data_0213d114,data_0213d120;extern s32 data_0213d13c;
extern u8 data_020fb3ec[],data_020fb3f8[],data_020fb400[],data_020fb408[],data_020fb410[],data_020fb414[],data_020fb41c[];
s32 func_02068c34(s32);s32 func_020346d0(void *,void *,void *,s32);s32 func_020336e8(s32,void *);s32 func_02033988(void *,void *,s32);s32 func_0206cd90(void *);
u8 buffer[0x94];
s32 v0=M2C_FIELD(&data_0213d114,s32 *,0x10),v1=M2C_FIELD(&data_0213d114,s32 *,0xc);
if(v0==0 && v1==0){
if(func_020346d0(p,data_020fb3f8,data_020fb3ec,func_02068c34((s32)data_020fb3ec)))return 8;
}else{
if(func_020346d0(p,data_020fb3f8,data_020fb400,func_02068c34((s32)data_020fb400)))return 8;
}
if(func_020346d0(p,data_020fb408,a,func_02068c34((s32)a)))return 8;
if(!func_020336e8((s32)buffer,&data_0213d120))return 5;
if(!func_02033988(p,buffer,data_0213d13c))return 8;
if(M2C_FIELD(&data_0213d114,s32 *,4)==1){
if(func_020346d0(p,data_020fb414,data_020fb410,func_02068c34((s32)data_020fb410)))return 8;
}
if(func_0206cd90(b)){
if(func_020346d0(p,data_020fb41c,b,func_0206cd90(b)*2))return 8;
}
return 0;
}
void func_0203367c(s32 arg0) {
    M2C_UNK func_02006564(s32);
    M2C_UNK func_020065e8(void *);
    extern M2C_UNK data_0213d114;
    func_02006564(M2C_FIELD(&data_0213d114, void **, 8) + 0x13D8);
    M2C_FIELD(M2C_FIELD(&data_0213d114, void **, 8), s32 *, 0x1004) = arg0;
    func_020065e8(M2C_FIELD(&data_0213d114, void **, 8) + 0x13D8);
}

void func_020336c0(s32 arg0) {
    s32 func_020336e8(s32, void *);
    void func_02045cbc(void *);
    u8 sp0[20];
    func_02045cbc(sp0);
    func_020336e8(arg0, sp0);
}

s32 func_02033ccc(void *p, InitConfig *cfg) {
s32 func_02034534(void *); s32 func_02034870(void *,void *,s32); s32 func_020349b0(void *,s32);
s32 (*alloc)(void *,s32)=(s32 (*)(void *,s32))cfg->words[3];
func_02007f8c(p,0,0x1c14);
M2C_FIELD(p,s32 *,0x1a30)=-1;M2C_FIELD(p,s32 *,0x1a34)=-1;
*(InitConfig *)(p+0x1004)=*cfg;
M2C_FIELD(p,s32 *,0x19cc)=alloc(data_020fb558,0xb68);
if(!M2C_FIELD(p,s32 *,0x19cc)){((InitState*)p)->status=1;return 1;}
M2C_FIELD(p,s32 *,0x19d0)=alloc(data_020fb570,0x5ea);
if(!M2C_FIELD(p,s32 *,0x19d0)){((InitState*)p)->status=1;return 1;}
if(!func_02034870(p,p+0x1a08,M2C_FIELD(p,s32 *,0x100c))){((InitState*)p)->status=1;return 1;}
if(!func_020349b0(p,cfg->words[0])){((InitState*)p)->status=1;return 1;}
((InitState*)p)->status=func_02034534(p);
if(!((InitState*)p)->status)((InitState*)p)->flag=255;
return ((InitState*)p)->status;
}

s32 func_02033de8(void *arg0) {
    void func_0200567c(void *, s32, void *, s32);
    s32 func_020345f4(void *, void *, void *);
    s32 func_02068c34(s32);
    s32 func_02068fdc(s32, void *);
    extern u8 data_020fb588[], data_020fb594[], data_020fb59c[], data_020fb5a4[], data_020fb5a8[];
    u8 sp0[8];
    s32 temp;
    if (func_020345f4(arg0, data_020fb588, data_020fb594)) return 1;
    temp = func_02068c34(func_02068fdc(M2C_FIELD(arg0,s32 *,0x19f8),data_020fb59c)+4);
    if (temp) {
        func_0200567c(sp0,7,data_020fb5a4,temp);
        if (func_020345f4(arg0,data_020fb5a8,sp0)) return 1;
    }
    return 0;
}

void func_02033e80(void *arg0, s32 arg1) {
    void func_02005ac0(void *, void *, void *, void *, s32, s32);
    s32 func_02005d90(void *);
    void func_02005e5c(void *);
    void func_0200654c(void *);
    extern s32 data_0213d134;
    extern u8 func_02034164[];
    s32 var_r1;
    M2C_FIELD(arg0,s32 *,0x1c10)=0;
    func_0200654c(arg0+0x1bf8);
    func_0200654c(arg0+0x1a18);
    if(M2C_FIELD(arg0,s32 *,0x1018)==1) data_0213d134=1; else data_0213d134=0;
    if(M2C_FIELD(arg0,s32 *,0x1ba4)!=0 && func_02005d90(arg0+0x1b38)==0) return;
    func_02005ac0(arg0+0x1b38,func_02034164,arg0,arg0+0x1000,0x1000,arg1);
    func_02005e5c(arg0+0x1b38);
}

void func_02033f3c(void *arg0) {
    M2C_UNK func_02005d60(void *);
    if (M2C_FIELD(arg0, u8 *, 0x1000) != 0xFF) {
        return;
    }
    func_02006564(arg0 + 0x1BF8);
    M2C_FIELD(arg0, s32 *, 0x1C10) = 1;
    func_020065e8(arg0 + 0x1BF8);
    if (M2C_FIELD(arg0, s32 *, 0x1BA4) == 0) {
        return;
    }
    func_02005d60(arg0 + 0x1B38);
}

s32 func_02033f98(void *arg0) {
    void func_02006030(s32);
    void func_02007888(void *);
    void func_020241f0(void *,s32);
    if(M2C_FIELD(arg0,s32 *,0x1130)==1) {
        func_02007888(arg0+0x19d4);
        func_020241f0(arg0+0x19d4,0x20);
    }
    func_02006564(arg0+0x1bf8);
    if(M2C_FIELD(arg0,s32 *,0x1c10)==1) {
        func_020065e8(arg0+0x1bf8); return 0;
    }
    func_020065e8(arg0+0x1bf8);
    func_02006030(10);
    return 1;
}

void func_02034010(void *arg0) {
    M2C_UNK func_02007f8c(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_0201d138(void *);
    func_02007f8c(arg0 + 0x1138, 0, 0x64);
    M2C_FIELD(arg0, s32 *, 0x1174) = 0xB68;
    M2C_FIELD(arg0, s32 *, 0x1178) = (s32) M2C_FIELD(arg0, s32 *, 0x19CC);
    M2C_FIELD(arg0, s32 *, 0x1180) = 0x5EA;
    M2C_FIELD(arg0, s32 *, 0x1184) = (s32) M2C_FIELD(arg0, s32 *, 0x19D0);
    func_0201d138(arg0 + 0x1138);
}

void func_02034068(void *arg0) {
    M2C_UNK func_0201ed20(s32);
    func_0201ed20(M2C_FIELD(arg0, s32 *, 0x1124));
}

s32 func_0203407c(void *a){
s32 func_02068c34(s32);s32 func_02068fdc(s32,void *);s32 func_0206ad38(s8 *);
extern u8 data_020fb59c[];extern M2C_UNK data_020fb5b8,data_020fb5cc;
s8 ch;void *hdr; s8 *p,*end; s32 len; s8 *q;
p=M2C_FIELD(a,s8 **,0x1a08);hdr=(u8 *)a+0x1a08;
if(func_02068fdc((s32)p,data_020fb59c)==0)return 0;
p=(s8 *)(func_02068fdc((s32)p,data_020fb59c)+4);
func_02006564(a+0x1a18);
M2C_FIELD(a,s32 *,0x1a34)=M2C_FIELD(hdr,s8 **,4)-p;
func_020065e8(a+0x1a18);
q=(s8 *)func_02068fdc(M2C_FIELD(hdr,s32 *,0),&data_020fb5b8);
if(q==NULL)return 1;
len=func_02068c34(&data_020fb5b8);
end=(s8 *)func_02068fdc((s32)(q+len),&data_020fb5cc);
ch=*end;*end=0;
func_02006564(a+0x1a18);
M2C_FIELD(a,s32 *,0x1a30)=func_0206ad38(q+len);
func_020065e8(a+0x1a18);
*end=ch;return 1;
}

