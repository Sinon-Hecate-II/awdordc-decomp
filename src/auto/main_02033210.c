/* 14 functions from 0x02033210 to 0x02034164 (main), found by ds-decomp. */
#include "common.h"
typedef struct InitConfig { s32 words[7]; } InitConfig;
typedef struct InitState { u8 pad[0x1000]; u8 flag; u8 pad2[31]; s32 status; } InitState;
extern u8 data_020fb558[], data_020fb570[];

#pragma opt_common_subs off
s32 func_02033210(void) {
    return 0;
}

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

s32 func_020336e8(s32 arg0, void *arg1) {
    M2C_UNK func_0200567c();
    void func_02007f8c(void *, s32, s32);
    void func_0200563c(void *, void *, ...);
    void func_02007724(void *);
    void func_02007740(void *);
    M2C_UNK func_02008048(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_0200f0ac(s32, s32);
    void func_02007958(void);
    void *func_02029784(void);
    void *func_020297c8(void *);
    void func_020067a8(void *, s32);
    u8 func_0202f248(void);
    void func_020317ac(void *, void *);
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern u8 data_020fb428[], data_020fb430[], data_020fb438[], data_020fb440[], data_020fb44c[], data_020fb468[];
    s32 var_r6;
    void *var_r7;
    void *var_r5;
    u8 sp_16[6];
    u8 sp_38[0x54];
    u16 sp_14;
    u32 sp_vals[6];
    s32 i;

    func_02007f8c((void *)arg0, 0, 0x94);
    {
        u32 *p = (u32 *)arg1;
        u32 low0 = p[0], high0 = p[1];
        u32 low1 = p[2], high1 = p[3];
        if (low0 == 0 && high0 == 0) {
            func_0200567c((void *)arg0, 0xe, data_020fb428, low1, high1);
        } else {
            func_0200567c((void *)arg0, 0xe, data_020fb428, low0, high0);
        }
    }
    {
        u16 v = *((u16 *)((u8 *)arg1 + 0x10));
        func_0200567c((void *)((u8 *)arg0 + 0xe), 7, data_020fb430, v);
    }
    if (*(u8 *)0x027FFE0C == 0) {
        func_02007958();
    }
    func_02008048((void *)0x027FFE0C, (void *)((u8 *)arg0 + 0x15), 4);
    if (*(u8 *)0x027FFE10 == 0) {
        func_02007958();
    }
    func_02008048((void *)0x027FFE10, (void *)((u8 *)arg0 + 0x1a), 2);
    *((u8 *)arg0 + 0x1d) = 0x30;
    func_02007724(sp_16);
    for (i = 0; i < 6; i++) {
        func_0200563c((void *)((u8 *)arg0 + 0x1f + i * 2), data_020fb438, sp_16[i]);
    }
    func_02007740(sp_38);
    if (sp_38[0] >= 8) {
        sp_38[0] = 1;
    }
    func_0200567c((void *)((u8 *)arg0 + 0x2c), 3, data_020fb438, sp_38[0]);
    func_02008048(sp_38 + 4, (void *)((u8 *)arg0 + 0x7e), 0x14);
    func_0200567c((void *)((u8 *)arg0 + 0x2f), 5, data_020fb440, sp_38[2], sp_38[3]);
    if (func_0200f0ac((s32)(sp_vals + 3), (s32)(sp_vals + 0)) != 0) {
        return 0;
    }
    func_0200567c((void *)((u8 *)arg0 + 0x34), 0xd, data_020fb44c,
        sp_vals[3], sp_vals[4], sp_vals[5], sp_vals[0], sp_vals[1], sp_vals[2]);
    var_r6 = func_0200751c();
    var_r7 = func_02029784();
    if (var_r7 == NULL) {
        func_02007530(var_r6);
        return 0;
    }
    func_020067a8(var_r7, 6);
    for (i = 0; i < 6; i++) {
        func_0200563c((void *)((u8 *)arg0 + 0x41 + i * 2), data_020fb438, ((u8 *)var_r7)[i]);
    }
    {
        u8 b = func_0202f248();
        func_0200567c((void *)((u8 *)arg0 + 0x6f), 0xe, data_020fb468, b);
    }
    var_r5 = func_020297c8(&sp_14);
    func_020067a8(var_r5, 0x20);
    if (var_r5 == NULL) {
        func_02007530(var_r6);
        return 0;
    }
    func_020317ac(var_r5, (void *)((u8 *)arg0 + 0x72));
    func_02008048(var_r5, (void *)((u8 *)arg0 + 0x4e), 0x20);
    func_02007530(var_r6);
    return 1;
}

s32 func_02033988(void *arg0, void *arg1, s32 arg2) {
    s32 func_0200567c(void *, s32, void *, s32, s32);
    s32 func_020345f4(void *, void *, void *);
    s32 func_020346d0(void *, void *, void *, s32);
    s32 func_02068c34(s32);
    s32 func_0206cd90(void *);
    extern u8 data_020fb478[], data_020fb484[], data_020fb48c[], data_020fb494[], data_020fb49c[];
    extern u8 data_020fb4a4[], data_020fb4ac[], data_020fb4b4[], data_020fb4bc[], data_020fb4c4[];
    extern u8 data_020fb4cc[], data_020fb4d4[], data_020fb4dc[], data_020fb4e4[], data_020fb4ec[];
    extern u8 data_020fb4f4[], data_020fb50c[], data_020fb518[];
    u8 sp4[0x24];

    func_0200567c(sp4, 0x21, data_020fb478, 2, 2);
    if (func_020346d0(arg0, data_020fb484, sp4, func_02068c34((s32)sp4)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb48c, arg1, func_02068c34((s32)arg1)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb494, (u8 *)arg1 + 0xe, func_02068c34((s32)arg1 + 0xe)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb49c, (u8 *)arg1 + 0x41, func_02068c34((s32)arg1 + 0x41)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4a4, (u8 *)arg1 + 0x6f, func_02068c34((s32)arg1 + 0x6f)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4ac, (u8 *)arg1 + 0x15, func_02068c34((s32)arg1 + 0x15)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4b4, (u8 *)arg1 + 0x1a, func_02068c34((s32)arg1 + 0x1a)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4bc, (u8 *)arg1 + 0x1d, func_02068c34((s32)arg1 + 0x1d)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4c4, (u8 *)arg1 + 0x1f, func_02068c34((s32)arg1 + 0x1f)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4cc, (u8 *)arg1 + 0x2c, func_02068c34((s32)arg1 + 0x2c)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4d4, (u8 *)arg1 + 0x2f, func_02068c34((s32)arg1 + 0x2f)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4dc, (u8 *)arg1 + 0x34, func_02068c34((s32)arg1 + 0x34)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4e4, (u8 *)arg1 + 0x7e, func_0206cd90((u8 *)arg1 + 0x7e) * 2) != 0) return 0;
    if (arg2 == 1) {
        if (func_020346d0(arg0, data_020fb4ec, (u8 *)arg1 + 0x4e, func_02068c34((s32)arg1 + 0x4e)) != 0) return 0;
    }
    func_0200567c(sp4, 0x21, data_020fb4f4, 2, 2);
    if (func_020345f4(arg0, data_020fb50c, sp4) != 0) return 0;
    return func_020345f4(arg0, data_020fb518, (u8 *)arg1 + 0x15) == 0;
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
    M2C_UNK func_0200567c();
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

