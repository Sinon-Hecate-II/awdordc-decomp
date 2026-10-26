/* 39 functions from 0x020CF69C to 0x020D068C (main), found by ds-decomp. */
#include "common.h"
extern u8 data_0212bd5c[];
extern s8 data_ov000_021b5560[];
extern s8 data_ov000_021b5580[];
extern s8 data_ov000_021b5580[];
extern s32 *data_027e0058;
extern s32 data_02168f08;

void func_020cf69c(s32 arg0, s32 arg1) {
 M2C_UNK func_020cf4f0(s16,s16,s16,s16 *,s16 *);
 extern s32 *data_027e0058;
 s16 sp6; s16 sp4;
 void (*cb)(s16,s16,s32);
 void *p = (void *)*data_027e0058;
 s16 *position=(s16 *)(p+0x52C2);
 s16 x=M2C_FIELD(p,s16 *,0x52C2); s16 y=position[1];
 func_020cf4f0((s16)(x*16), (s16)(y*16), (s16)arg0,&sp6,&sp4);
 cb=M2C_FIELD((void *)data_027e0058[1],void (**)(s16,s16,s32),8);
 if(cb != NULL) cb(sp6,sp4,arg0);
 cb=M2C_FIELD((void *)data_027e0058[1],void (**)(s16,s16,s32),8);
 if(cb == NULL) return;
 cb(sp6,sp4,arg1);
}

void func_020cf754(s32 arg0, s32 arg1) {
 M2C_UNK func_020cf4f0(s16,s16,s16,s16 *,s16 *);
 extern s32 *data_027e0058;
 s16 sp6; s16 sp4;
 void (*cb)(s16,s16,s32);
 void *p = (void *)*data_027e0058;
 s16 *position=(s16 *)(p+0x52C2);
 s16 x=M2C_FIELD(p,s16 *,0x52C2); s16 y=position[1];
 func_020cf4f0((s16)(x*16), (s16)(y*16), (s16)arg0,&sp6,&sp4);
 cb=M2C_FIELD((void *)data_027e0058[1],void (**)(s16,s16,s32),8);
 if(cb != NULL) cb(sp6,sp4,arg0);
 cb=M2C_FIELD((void *)data_027e0058[1],void (**)(s16,s16,s32),8);
 if(cb == NULL) return;
 cb(sp6,sp4,arg1+8);
}

void func_020cf80c(void) {
    M2C_UNK func_020bc454();
    M2C_UNK func_020bcf6c();
    s32 func_020d4dd0();
    if (func_020d4dd0() == 0) {
        return;
    }
    func_020bc454();
    func_020bcf6c();
}

void func_020cf828(M2C_UNK arg0) {
    M2C_UNK func_020bc610(M2C_UNK);
    M2C_UNK func_020bd220(M2C_UNK);
    if (func_020d4dd0() == 0) {
        return;
    }
    func_020bc610(arg0);
    func_020bd220(arg0);
}

void func_020cf850(M2C_UNK arg0) {
    M2C_UNK func_020bc774(M2C_UNK);
    M2C_UNK func_020bd3c0(M2C_UNK);
    if (func_020d4dd0() == 0) {
        return;
    }
    func_020bc774(arg0);
    func_020bd3c0(arg0);
}

u8 func_020cf878(s32 arg0,s32 arg1) {
 s32 func_020a88fc(u16); s32 func_020d048c(u8, s32);
 extern s32 *data_027e0058;
 u8 result; void *p; s32 offset; u8 value;
 p=(void *)*data_027e0058;
 offset=arg0+M2C_FIELD(p+arg1*2,u16 *,0x3758);
 value=M2C_FIELD(p+offset,u8 *,0x1420);
 if(M2C_FIELD(p,u16 *,0x52A4)==0) return 0;
 offset=((u8 *)p)[offset];
 if(offset!=0) return 0;
 if(func_020d048c(value, M2C_FIELD(p,u16 *,0x52A4))==0) return 0;
 if(func_020a88fc(M2C_FIELD((void *)*data_027e0058,u16 *,0x5142))==0) result=1; else result=0;
 return result;
}

u8 func_020cf908(s32 arg0,s32 arg1,s32 arg2,s32 arg3) {
void func_020d0538(void);
u8 func_020d04d4(s32,s32);
extern u8 data_ov000_021b5c0f[];
void *p=(void *)*data_027e0058;
s32 index=arg0+M2C_FIELD(p+arg1*2,u16*,0x3758);
u8 value=M2C_FIELD(p+index,u8*,0x1420);
s32 offset;
if(arg2!=((s32 (*)(s32))func_020d0538)(value))return 0;
if(func_020d04d4(value,15))return 1;
offset=arg3*0x70;
if(data_ov000_021b5c0f[offset]&7) {if(func_020d04d4(value,17))return 1;}
if(data_ov000_021b5c0f[offset]&16) {if(func_020d04d4(value,18))return 1;}
if(data_ov000_021b5c0f[offset]&32) {if(func_020d04d4(value,19))return 1;}
return 0;
}

u8 func_020cf9f0(s32 arg0,s32 arg1) {
 u8 func_020d04d4(s32,s32);
 extern s32 *data_027e0058;
 void *p=(void *)*data_027e0058;
 s32 index=arg0+M2C_FIELD(p+arg1*2,u16 *,0x3758);
 u8 value=M2C_FIELD(p+index,u8 *,0x1420);
 u8 result;
 if(func_020d04d4(value,1)!=0) return 1;
 if(func_020d04d4(value,9)!=0) result=1; else result=0;
 return result;
}

/* Load the decoded tile-graphics block for id into data_02168f08.  Ids in
   0xE1..0x1A8 come from a fixed 0x6F8-byte tile-set record (byte 4 = width,
   byte 5 = height, then the per-tile ids at +0x54 mapped through func_0207f460);
   any other id is expanded from a resource by the generic loader. */
void func_020cfa58(u32 id) {
s32 func_020e34bc(s32); void *func_020e34f4(s32); s32 func_020c85c4(u32,void *); s32 func_0207f460(s32); M2C_UNK func_020e35cc(s32); void *func_020a8b1c(u32); void func_0200bc5c(void *); void func_02080cfc(void *,s32);
s32 i; u8 *tileSet; u8 *tileIds; void *resource;
data_02168f08=func_020e34bc(0xA12);
if(id>=0xE1 && id<0x1A9){
tileSet=func_020e34f4(0x6F8);
if(func_020c85c4(id,tileSet)){
M2C_FIELD(data_02168f08,u8 *,0)=tileSet[4];
M2C_FIELD(data_02168f08,u8 *,1)=tileSet[5];
tileIds=tileSet+0x54;
for(i=0;i<(s16)tileSet[4]*(s16)tileSet[5];i++){
resource=(void *)data_02168f08;
((u16 *)resource)[i+1]=func_0207f460(tileIds[i]);
}
}
func_020e35cc((s32)tileSet);return;
}
resource=func_020a8b1c(id);if(!resource)return;
func_0200bc5c(data_0212bd5c);func_02080cfc(resource,data_02168f08);
}

void func_020cfb54(void) {
    M2C_UNK func_020e35cc(s32);
    extern s32 data_02168f08;
    func_020e35cc(data_02168f08);
    data_02168f08 = 0;
}

s32 func_020cfb78(void) {
    extern s32 *data_027e0058;
    return *data_027e0058 + 0x5120;
}

u8 func_020cfb94(void) {
 extern s32 *data_027e0058;
 return M2C_FIELD((void *)*data_027e0058,u8 *,0x5141);
}

void func_020cfbb0(u32 arg0) {
    M2C_UNK func_020a8948();
    M2C_UNK func_020c8020();
    if ((arg0 >= 0xE1U) && (arg0 < 0x1A9U)) {
        func_020c8020();
        return;
    }
    func_020a8948();
}

void func_020cfbdc(u32 arg0) {
    M2C_UNK func_02086680();
    M2C_UNK func_020a8888();
    M2C_UNK func_020c7fe4();
    if ((arg0 >= 0xE1U) && (arg0 < 0x1A9U)) {
        func_020c7fe4();
        return;
    }
    func_020a8888();
    func_02086680();
}

u8 func_020cfc0c(s32 arg0) {
 extern s32 *data_027e0058;
 extern s8 data_ov000_021b56c0[];
 s32 mask=arg0 & 0xE0;
 if(mask==0) return 0;
 if(data_ov000_021b56c0[arg0 & 0x1F]==0) return 0;
 return M2C_FIELD((void *)*data_027e0058+(mask>>5)*0x8C,u8 *,0x67C1);
}

void func_020cfc5c(void) {
 extern s32 *data_027e0058;
 if(M2C_FIELD((void *)*data_027e0058,s16 *,0x52C2)<0)
 M2C_FIELD((void *)*data_027e0058,s16 *,0x52C2)=0;
 if(M2C_FIELD((void *)*data_027e0058,s16 *,0x52C2)>=M2C_FIELD((void *)*data_027e0058,u16 *,0x5144))
 M2C_FIELD((void *)*data_027e0058,s16 *,0x52C2)=M2C_FIELD((void *)*data_027e0058,u16 *,0x5144)-1;
 if(M2C_FIELD((void *)*data_027e0058,s16 *,0x52C4)<0)
 M2C_FIELD((void *)*data_027e0058,s16 *,0x52C4)=0;
 if(M2C_FIELD((void *)*data_027e0058,s16 *,0x52C4)>=M2C_FIELD((void *)*data_027e0058,u16 *,0x5146))
 M2C_FIELD((void *)*data_027e0058,s16 *,0x52C4)=M2C_FIELD((void *)*data_027e0058,u16 *,0x5146)-1;
}

void func_020cfd14(void) {
    M2C_UNK func_020cf2c8();
    M2C_UNK func_ov000_0219a9b0();
    M2C_UNK func_020d2470();
    func_020cf2c8();
    func_020d2470();
    func_ov000_0219a9b0();
}

void func_020cfd28(void) {
    M2C_UNK func_020cfd38();
    M2C_UNK func_020d0270();
    func_020d0270();
    func_020cfd38();
}

M2C_UNK func_020cfd38(void) {
void (*cb)(void);
void func_0207a668(void); void func_02076980(s32,s32,s32,s32); void func_0207843c(s32,s32,s32,s32);
M2C_FIELD((void *)*data_027e0058,s16 *,0x5150)=M2C_FIELD((void *)*data_027e0058,s16 *,0x5148)/16;
M2C_FIELD((void *)*data_027e0058,s16 *,0x5152)=M2C_FIELD((void *)*data_027e0058,s16 *,0x514A)/16;
M2C_FIELD((void *)*data_027e0058,s16 *,0x514C)=M2C_FIELD((void *)*data_027e0058,s16 *,0x5148);
M2C_FIELD((void *)*data_027e0058,s16 *,0x514E)=M2C_FIELD((void *)*data_027e0058,s16 *,0x514A);
cb=M2C_FIELD((void *)data_027e0058[1],void (**)(void),0x1C); if(cb)cb();
cb=M2C_FIELD((void *)data_027e0058[1],void (**)(void),0); if(cb)cb();
cb=M2C_FIELD((void *)data_027e0058[1],void (**)(void),4); if(cb)cb();
func_0207a668();func_02076980(0,0,48,40);func_0207843c(0,0,48,40);
}

void func_020d0164(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02007f8c(M2C_UNK, M2C_UNK, s32);
    func_02007f8c(arg0, arg1, 0x508);
}

M2C_UNK func_020d0178(void) {
void func_020d0288(void *,s32,s32,s32,s32,s32); void func_020d0428(s32,s32,s32,s32); s32 func_020d03c4(s32);
s32 func_020d1938(s32); void *func_020a32f4(s32); s32 func_020a7d20(void); s32 func_020d2cf0(s32); s32 func_020a334c(s32); s32 func_020d02b4(void *); void func_02078068(void);
s32 i; s32 temp[8]; void *p; s32 n;
for(i=1;i<5;i++){
if(!func_020d1938(i))continue;
func_020d0164(func_020d03c4(i),0);
p=func_020a32f4(i); if(!p)continue;
if(func_020a7d20() && !(M2C_FIELD(p,u16 *,4)&4))continue;
n=func_020d2cf0(i); if(func_020a334c(i))n=6;
func_020d0288(temp,n,M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),M2C_FIELD((void *)*data_027e0058,u16 *,0x5144),M2C_FIELD((void *)*data_027e0058,u16 *,0x5146));
for(;;){if(!func_020d02b4(temp))break;func_020d0428(i,temp[4],temp[5],1);}
}
func_02078068();
}

M2C_UNK func_020d0270(void) {
 M2C_UNK func_020ce9a0(); M2C_UNK func_020cfe2c(); M2C_UNK func_020d0178(); M2C_UNK func_ov000_02174ce8();
 func_020ce9a0(); func_020cfe2c(); func_020d0178(); func_ov000_02174ce8();
}

void func_020d0288(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    M2C_FIELD(arg0, s32 *, 0) = arg4;
    M2C_FIELD(arg0, s32 *, 4) = arg5;
    M2C_FIELD(arg0, s32 *, 8) = arg2;
    M2C_FIELD(arg0, s32 *, 0xC) = arg3;
    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
}

s32 func_020d03c4(s32 arg0) {
    extern s32 *data_027e0058;
    s32 temp = *data_027e0058;
    temp = temp + 0x3F8;
    temp = temp + 0x3400;
    return arg0 * 0x508 + temp;
}

s32 func_020d03ec(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 *data_027e0058;
    s32 temp = *data_027e0058;
    s32 off = M2C_FIELD(temp + arg2 * 2, u16 *, 0x3758);
    s32 acc = arg1 + off;
    s32 base = temp + arg0 * 0x508;
    return M2C_FIELD(acc + base, u8 *, 0x37F8);
}

void func_020d0428(s32 a,s32 b,s32 c,s32 d){extern s32 *data_027e0058;s32 p=*data_027e0058;s32 off=M2C_FIELD(p+c*2,u16 *,0x3758);s32 row=p+a*0x508;M2C_FIELD(row+(b+off),u8 *,0x37f8)=d;}

s32 func_020d0468(M2C_UNK arg0) {
    s32 func_020d03ec();
    s32 func_020d2c18(M2C_UNK);
    if (func_020d03ec() == 0) {
        return -1;
    }
    return func_020d2c18(arg0);
}

s32 func_020d048c(u8 a,s32 b){void func_020d0538(void);extern s8 data_ov000_021b5580[];u8 n=a&31;s32 v=b;if(v!=((s32 (*)(void))func_020d0538)())return 0;if(n!=16){if(data_ov000_021b5580[n&31])return 1;}return 0;}

u8 func_020d04d4(s32 arg0, s32 arg1) {
    u8 var_r0;

    if ((arg0 & 0x1F) == arg1) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020d04ec(s32 arg0,s32 arg1,s32 arg2) {
 void *p=(void *)*data_027e0058;
 return func_020d04d4(M2C_FIELD(p+(arg0+M2C_FIELD(p+arg1*2,u16 *,0x3758)),u8 *,0x1420),arg2);
}

s32 func_020d0528(s32 arg0) {
    return arg0 >> 5;
}

s32 func_020d0530(s32 arg0) {
    return arg0 & 0xE0;
}

void func_020d0538(void) {
    M2C_UNK func_020d0528();
    M2C_UNK func_020d0530();
    func_020d0530();
    func_020d0528();
}

s32 func_020d0548(s32 arg0,s32 arg1) {
 void func_02079c6c(s32,s32,void *);
 s32 temp[3];
 func_02079c6c(arg0,arg1,temp);
 if(arg0<0 || arg1<0 || arg0>256 || arg1>192) return 0;
 return 1;
}

u8 func_020d0590(s32 arg0) {
 s32 func_020d19b4(s32);
 u8 result;
 if(func_020d19b4(arg0)!=0) return 1;
 if(M2C_FIELD(&data_02168f08,u8 *,4)!=0) return 0;
 if(M2C_FIELD((void *)*data_027e0058+arg0*0x8C,u8 *,0x67C3)&2) result=1; else result=0;
 return result;
}

s32 func_020d05f4(s32 a,s32 b,s32 c){
s32 func_020a857c(s32);
s32 n;
if(func_020a857c(b))return 0;
n=(s16)data_ov000_021b5560[c]*(s16)10+M2C_FIELD((void *)*data_027e0058+a*0x8C,s8 *,0x67C8);
if(n<0)n=0;
return n;
}

s32 func_020d0654(s32 arg0,s32 arg1,s32 arg2) {
 s32 func_020a857c(s32);
 s32 value;
 if(func_020a857c(arg1)!=0) return 0;
 value=data_ov000_021b5560[arg2]*10;
 if(value<0) value=0;
 return value;
}

