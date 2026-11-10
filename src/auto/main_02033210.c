/* 14 functions from 0x02033210 to 0x02034164 (main), found by ds-decomp. */
#include "common.h"
typedef struct InitConfig { s32 words[7]; } InitConfig;
typedef struct InitState { u8 pad[0x1000]; u8 flag; u8 pad2[31]; s32 status; } InitState;
extern u8 data_020fb558[], data_020fb570[];

#pragma push
#pragma opt_common_subs on
s32 func_02033210(void){
extern M2C_UNK gNasConnection;extern s32 data_0213e9f4;
extern u8 data_020fb398[],data_020fb3a0[],data_020fb3ac[],data_020fb3b8[],data_020fb3c0[],data_020fb3c8[],data_020fb3d4[],data_020fb3e0[];
void *func_02034ef8(void*,void*);s32 func_02036860(void*);s32 func_0206ad38(s8*);s32 func_02034f50(void*,void*,void*,s32);s32 func_02034fa4(void*,void*,void*,s32);s32 func_0206ac70(void*,void**,s32);s32 StringLength(s32);
void *end; s32 status; void *response;void *p;
p=M2C_FIELD(&gNasConnection,void **,8);status=0;end=(void*)status;
response=M2C_FIELD(p,void **,0x1314);end=func_02034ef8(response,data_020fb398);if(end)func_02036860(end);
p=M2C_FIELD(&gNasConnection,void **,8);end=0;data_0213e9f4=0;status=func_0206ad38(func_02034ef8(M2C_FIELD(p,void **,0x1314),data_020fb3a0));
if(data_0213e9f4==34){M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32*,0x1008)=0x4e85;return 12;}
if(status!=200){M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32*,0x1008)=status+23000;return 18;}
if(func_02034f50(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314),data_020fb3ac,M2C_FIELD(&gNasConnection,void **,8)+0x100c,4)<=0){M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),s32*,0x1008)=0x4e85;return 14;}
status=func_0206ac70(M2C_FIELD(&gNasConnection,void **,8)+0x100c,&end,10);p=M2C_FIELD(&gNasConnection,void **,8);
if(end!=p+0x100c+StringLength((s32)(p+0x100c))){M2C_FIELD(p,s32*,0x1008)=0x4e85;return 12;}
M2C_FIELD(p,s32*,0x1008)=status+20000;
if(status<100){
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),u8*,0x1052)=0;
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),u8*,0x101f)=0;
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),u8*,0x117f)=0;
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),u8*,0x1010)=0;
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),u8*,0x1188)=0;
func_02034f50(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314),data_020fb3b8,M2C_FIELD(&gNasConnection,void **,8)+0x1052,0x12d);
func_02034f50(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314),data_020fb3c0,M2C_FIELD(&gNasConnection,void **,8)+0x101f,0x33);
func_02034f50(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314),data_020fb3c8,M2C_FIELD(&gNasConnection,void **,8)+0x117f,9);
func_02034f50(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314),data_020fb3d4,M2C_FIELD(&gNasConnection,void **,8)+0x1010,15);
func_02034fa4(M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),void **,0x1314),data_020fb3e0,M2C_FIELD(&gNasConnection,void **,8)+0x1188,65);
M2C_FIELD(M2C_FIELD(&gNasConnection,void **,8),u8*,0x11b3)=0;if(status!=40)M2C_FIELD(&gNasConnection,s32*,0)=1;else M2C_FIELD(&gNasConnection,s32*,0)=2;
}return 0;}
#pragma pop
s32 func_020334d8(void *p,void *a,void *b){
extern M2C_UNK gNasConnection,data_0213d120;extern s32 data_0213d13c;
extern u8 data_020fb3ec[],data_020fb3f8[],data_020fb400[],data_020fb408[],data_020fb410[],data_020fb414[],data_020fb41c[];
s32 StringLength(s32);s32 func_020346d0(void *,void *,void *,s32);s32 BuildFriendProfile(s32,void *);s32 func_02033988(void *,void *,s32);s32 func_0206cd90(void *);
u8 buffer[0x94];
s32 v0=M2C_FIELD(&gNasConnection,s32 *,0x10),v1=M2C_FIELD(&gNasConnection,s32 *,0xc);
if(v0==0 && v1==0){
if(func_020346d0(p,data_020fb3f8,data_020fb3ec,StringLength((s32)data_020fb3ec)))return 8;
}else{
if(func_020346d0(p,data_020fb3f8,data_020fb400,StringLength((s32)data_020fb400)))return 8;
}
if(func_020346d0(p,data_020fb408,a,StringLength((s32)a)))return 8;
if(!BuildFriendProfile((s32)buffer,&data_0213d120))return 5;
if(!func_02033988(p,buffer,data_0213d13c))return 8;
if(M2C_FIELD(&gNasConnection,s32 *,4)==1){
if(func_020346d0(p,data_020fb414,data_020fb410,StringLength((s32)data_020fb410)))return 8;
}
{
void *bb=b;
if(func_0206cd90(bb)){
if(func_020346d0(p,data_020fb41c,bb,func_0206cd90(bb)*2))return 8;
}
}
return 0;
}
#pragma opt_common_subs off
void func_0203367c(s32 arg0) {
    M2C_UNK func_02006564(s32);
    M2C_UNK func_020065e8(void *);
    extern M2C_UNK gNasConnection;
    func_02006564(M2C_FIELD(&gNasConnection, void **, 8) + 0x13D8);
    M2C_FIELD(M2C_FIELD(&gNasConnection, void **, 8), s32 *, 0x1004) = arg0;
    func_020065e8(M2C_FIELD(&gNasConnection, void **, 8) + 0x13D8);
}

void func_020336c0(s32 arg0) {
    s32 BuildFriendProfile(s32, void *);
    void func_02045cbc(void *);
    u8 sp0[20];
    func_02045cbc(sp0);
    BuildFriendProfile(arg0, sp0);
}

#pragma push
#pragma opt_strength_reduction off
/* Builds the ~0x94-byte Wi-Fi friend/profile record: friend code, DS MAC and
 * firmware ids, region, date and session code, then the connection-data block. */
s32 BuildFriendProfile(s32 arg0, void *arg1) {
    M2C_UNK func_0200567c();
    void func_02007f8c(void *, s32, s32);
    void func_0200563c(void *, void *, ...);
    void func_02007724(void *);
    void func_02007740(void *);
    M2C_UNK MI_CpuCopy8(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_0200f0ac(s32, s32);
    void func_02007958(void);
    void *func_02029784(void);
    void *func_020297c8(void *);
    void func_020067a8(void *, s32);
    u8 func_0202f248(void);
    void func_020317ac(void *, void *);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern u8 gFmtFriendCode[], gFmtU03[], gFmtHex02[], gFmtHex02Pair[], gFmtDate6[], gFmtSessionCode[];
    s32 intrState;
    void *connInfo;
    void *connData;
    u8 macBytes[6];
    u8 userSettings[0x54];
    u16 connType;
    u32 dateVals[7];
    s32 i;u8 *src,*dst;

    func_02007f8c((void *)arg0, 0, 0x94);
    {
        u32 *raw = (u32 *)arg1;
        u32 low = raw[0], high = raw[1];
        if (high != 0 || low != 0) {
            func_0200567c((void *)arg0, 0xe, gFmtFriendCode, low, high);
        } else {
            u64 id=*((u64*)arg1+1);low=id;high=id>>32;
            func_0200567c((void *)arg0, 0xe, gFmtFriendCode, low, high);
        }
    }
    {
        u16 region = *((u16 *)((u8 *)arg1 + 0x10));
        func_0200567c((void *)((u8 *)arg0 + 0xe), 7, gFmtU03, region);
    }
    if (*(u8 *)0x027FFE0C == 0) {
        func_02007958();
    }
    MI_CpuCopy8((void *)0x027FFE0C, (void *)((u8 *)arg0 + 0x15), 4);
    if (*(u8 *)0x027FFE10 == 0) {
        func_02007958();
    }
    MI_CpuCopy8((void *)0x027FFE10, (void *)((u8 *)arg0 + 0x1a), 2);
    *((u8 *)arg0 + 0x1d) = 0x30;
    func_02007724(macBytes);
    dst=(u8*)arg0+0x1f;src=macBytes;
    for(i=0;i<6;i++,dst+=2,src++) func_0200563c(dst,gFmtHex02,*src);
    func_02007740(userSettings);
    if (userSettings[0] >= 8) {
        userSettings[0] = 1;
    }
    func_0200567c((void *)((u8 *)arg0 + 0x2c), 3, gFmtHex02, userSettings[0]);
    MI_CpuCopy8(userSettings + 4, (void *)((u8 *)arg0 + 0x7e), 0x14);
    func_0200567c((void *)((u8 *)arg0 + 0x2f), 5, gFmtHex02Pair, userSettings[2], userSettings[3]);
    if (func_0200f0ac((s32)(dateVals + 3), (s32)(dateVals + 0)) != 0) {
        return 0;
    }
    func_0200567c((void *)((u8 *)arg0 + 0x34), 0xd, gFmtDate6,
        dateVals[3], dateVals[4], dateVals[5], dateVals[0], dateVals[1], dateVals[2]);
    intrState = OS_DisableInterrupts();
    connInfo = func_02029784();
    func_020067a8(connInfo, 6);
    if (connInfo == NULL) {
        OS_RestoreInterrupts(intrState);
        return 0;
    }
    dst=(u8*)arg0+0x41;
    for(i=0;i<6;i++,dst+=2) func_0200563c(dst,gFmtHex02,((u8*)connInfo)[i]);
    {
        u8 language = func_0202f248();
        func_0200567c((void *)((u8 *)arg0 + 0x6f), 0xe, gFmtSessionCode, language);
    }
    connData = func_020297c8(&connType);
    func_020067a8(connData, 0x20);
    if (connData == NULL) {
        OS_RestoreInterrupts(intrState);
        return 0;
    }
    func_020317ac(connData, (void *)((u8 *)arg0 + 0x72));
    MI_CpuCopy8(connData, (void *)((u8 *)arg0 + 0x4e), 0x20);
    OS_RestoreInterrupts(intrState);
    return 1;
}
#pragma pop
s32 func_02033988(void *arg0, void *arg1, s32 arg2) {
    s32 func_0200567c(void *, s32, void *, s32, s32);
    s32 func_020345f4(void *, void *, void *);
    s32 func_020346d0(void *, void *, void *, s32);
    s32 StringLength(s32);
    s32 func_0206cd90(void *);
    extern u8 data_020fb478[], data_020fb484[], data_020fb48c[], data_020fb494[], data_020fb49c[];
    extern u8 data_020fb4a4[], data_020fb4ac[], data_020fb4b4[], data_020fb4bc[], data_020fb4c4[];
    extern u8 data_020fb4cc[], data_020fb4d4[], data_020fb4dc[], data_020fb4e4[], data_020fb4ec[];
    extern u8 data_020fb4f4[], data_020fb50c[], data_020fb518[];
    u8 sp4[0x24];

    func_0200567c(sp4, 0x21, data_020fb478, 2, 2);
    if (func_020346d0(arg0, data_020fb484, sp4, StringLength((s32)sp4)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb48c, arg1, StringLength((s32)arg1)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb494, (u8 *)arg1 + 0xe, StringLength((s32)arg1 + 0xe)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb49c, (u8 *)arg1 + 0x41, StringLength((s32)arg1 + 0x41)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4a4, (u8 *)arg1 + 0x6f, StringLength((s32)arg1 + 0x6f)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4ac, (u8 *)arg1 + 0x15, StringLength((s32)arg1 + 0x15)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4b4, (u8 *)arg1 + 0x1a, StringLength((s32)arg1 + 0x1a)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4bc, (u8 *)arg1 + 0x1d, StringLength((s32)arg1 + 0x1d)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4c4, (u8 *)arg1 + 0x1f, StringLength((s32)arg1 + 0x1f)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4cc, (u8 *)arg1 + 0x2c, StringLength((s32)arg1 + 0x2c)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4d4, (u8 *)arg1 + 0x2f, StringLength((s32)arg1 + 0x2f)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4dc, (u8 *)arg1 + 0x34, StringLength((s32)arg1 + 0x34)) != 0) return 0;
    if (func_020346d0(arg0, data_020fb4e4, (u8 *)arg1 + 0x7e, func_0206cd90((u8 *)arg1 + 0x7e) * 2) != 0) return 0;
    if (arg2 == 1) {
        if (func_020346d0(arg0, data_020fb4ec, (u8 *)arg1 + 0x4e, StringLength((s32)arg1 + 0x4e)) != 0) return 0;
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
    s32 StringLength(s32);
    s32 func_02068fdc(s32, void *);
    extern u8 data_020fb588[], data_020fb594[], data_020fb59c[], data_020fb5a4[], data_020fb5a8[];
    u8 sp0[8];
    s32 temp;
    if (func_020345f4(arg0, data_020fb588, data_020fb594)) return 1;
    temp = StringLength(func_02068fdc(M2C_FIELD(arg0,s32 *,0x19f8),data_020fb59c)+4);
    if (temp) {
        func_0200567c(sp0,7,data_020fb5a4,temp);
        if (func_020345f4(arg0,data_020fb5a8,sp0)) return 1;
    }
    return 0;
}

void func_02033e80(void *arg0, s32 arg1) {
    void func_02005ac0(void *, void *, void *, void *, s32, s32);
    s32 func_02005d90(void *);
    void TaskWake(void *);
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
    TaskWake(arg0+0x1b38);
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
s32 StringLength(s32);s32 func_02068fdc(s32,void *);s32 func_0206ad38(s8 *);
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
len=StringLength(&data_020fb5b8);
end=(s8 *)func_02068fdc((s32)(q+len),&data_020fb5cc);
ch=*end;*end=0;
func_02006564(a+0x1a18);
M2C_FIELD(a,s32 *,0x1a30)=func_0206ad38(q+len);
func_020065e8(a+0x1a18);
*end=ch;return 1;
}

