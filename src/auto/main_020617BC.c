/* 33 functions from 0x020617BC to 0x02062770 (main), found by ds-decomp. */
#include "common.h"
typedef struct Addr617BC { u8 len, family; u16 port; u32 addr; } Addr617BC;
typedef struct Bytes617BC { u8 b[4]; } Bytes617BC;
typedef struct Pair617BC { u8 b[2]; } Pair617BC;
#pragma push
#pragma opt_propagation off
static inline void CopyHeaderBytes617BC(u8 *dst,u8 *src) {
u8 hi=src[1],lo=src[0];dst[1]=hi;dst[0]=lo;
}
#pragma pop
static inline void CopyPair617BC(u8 *d,u8 *s) { *(Pair617BC *)d=*(Pair617BC *)s; }
static inline void Copy617BC(u8 *d,u8 *s) { *(Bytes617BC *)d=*(Bytes617BC *)s; }
extern u8 data_02100120[];
extern u8 data_0210012c[];
extern u8 data_02100094[];
extern void *data_02100090;
extern s32 data_0213e4b4[2];

s32 func_020617bc(s32 *arg0, s32 *arg1) {
    s32 SBServerGetIntValue(s32, s32, M2C_UNK);
    extern void *data_0213e4bc;
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r0;

    temp_r4 = *arg0;
    temp_r5 = *arg1;
    temp_r4 = SBServerGetIntValue(temp_r4, M2C_FIELD(data_0213e4bc, s32 *, 0x498), 0);
    var_r0 = temp_r4 - SBServerGetIntValue(temp_r5, M2C_FIELD(data_0213e4bc, s32 *, 0x498), 0);
    if (M2C_FIELD(data_0213e4bc, s32 *, 0x49C) == 0) {
        var_r0 = -var_r0;
    }
    return var_r0;
}

s32 func_02061818(s32 *arg0, s32 *arg1) {
    double func_02060c10(void *, s32, double);
    s32 func_0207044c(double);
    double func_02070b70(double, double);
    s32 func_02071438(s32, s32);
    s32 func_02071494(s32, s32);
    extern void *data_0213e4bc;
    double d0;
    double d1;
    double var;
    s32 temp_r5;
    s32 var_r0;

    temp_r5 = *arg1;
    d0 = func_02060c10((void *) *arg0, M2C_FIELD(data_0213e4bc, s32 *, 0x498), 0.0);
    d1 = func_02060c10((void *) temp_r5, M2C_FIELD(data_0213e4bc, s32 *, 0x498), 0.0);
    var = func_02070b70(d0, d1);
    if (M2C_FIELD(data_0213e4bc, s32 *, 0x49C) == 0) {
        var = func_02070b70(0.0, var);
    }
    if ((float)var > 0.0f) return 1;
    return -((float)var < 0.0f);
}

s32 func_020618f0(s32 *arg0, s32 *arg1) {
    s32 func_02060afc(s32, s32, M2C_UNK *);
    s32 StringCompare(s32, s32);
    extern void *data_0213e4bc;
    extern M2C_UNK data_0210011c;
    s32 temp_r4;
    s32 var_r0;

    temp_r4 = func_02060afc(*arg0, M2C_FIELD(data_0213e4bc, s32 *, 0x498), &data_0210011c);
    var_r0 = StringCompare(temp_r4, func_02060afc(*arg1, M2C_FIELD(data_0213e4bc, s32 *, 0x498), &data_0210011c));
    if (M2C_FIELD(data_0213e4bc, s32 *, 0x49C) == 0) {
        var_r0 = -var_r0;
    }
    return var_r0;
}

s32 func_02061958(s32 *arg0, s32 *arg1) {
    s32 func_02060afc(s32, s32, M2C_UNK *);
    s32 func_0206f8ac(s32, s32);
    extern void *data_0213e4bc;
    extern M2C_UNK data_0210011c;
    s32 temp_r4;
    s32 var_r0;

    temp_r4 = func_02060afc(*arg0, M2C_FIELD(data_0213e4bc, s32 *, 0x498), &data_0210011c);
    var_r0 = func_0206f8ac(temp_r4, func_02060afc(*arg1, M2C_FIELD(data_0213e4bc, s32 *, 0x498), &data_0210011c));
    if (M2C_FIELD(data_0213e4bc, s32 *, 0x49C) == 0) {
        var_r0 = -var_r0;
    }
    return var_r0;
}

void func_020619c0(void *arg0, s32 arg1, s32 arg2, u32 arg3) {
    s32 func_02061818(s32 *, s32 *);
    s32 func_02061958(s32 *, s32 *);
    M2C_UNK func_020489c4(s32, s32 (*)(s32 *, s32 *));
    extern void *data_0213e4bc;
    s32 (*var_r3)(s32 *, s32 *);

    switch (arg3) {
    case 0: var_r3 = func_020617bc; break;
    case 1: var_r3 = func_02061818; break;
    case 2: var_r3 = func_020618f0; break;
    case 3: var_r3 = func_02061958; break;
    default: var_r3 = func_02061958; break;
    }
    M2C_FIELD(arg0, s32 *, 0x498) = arg2;
    M2C_FIELD(arg0, s32 *, 0x49C) = arg1;
    data_0213e4bc = arg0;
    func_020489c4(M2C_FIELD(arg0, s32 *, 4), var_r3);
}

void func_02061a38(void *arg0, s32 arg1) {
    M2C_UNK Vector_AddItem(s32, s32 *);

    Vector_AddItem(M2C_FIELD(arg0, s32 *, 4), &arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(void *, s32, s32, s32), 0x488)(arg0, 0, arg1, M2C_FIELD(arg0, s32 *, 0x494));
}

s32 func_02061a74(void *a,s32 b){s32 Vector_GetCount(s32);s32 *Vector_GetItem();s32 n,i;n=Vector_GetCount(M2C_FIELD(a,s32 *,4));for(i=0;i<n;i++){if(b==*Vector_GetItem(M2C_FIELD(a,s32 *,4),i))return i;}return -1;}

s32 SBServerListFindByAddress(void *a,s32 b,s32 c){s32 Vector_GetCount(s32);s32 *Vector_GetItem();s32 SBServerGetIp(s32);s32 func_02060c70(s32);s32 n,p,i;n=Vector_GetCount(M2C_FIELD(a,s32 *,4));for(i=0;i<n;i++){p=*Vector_GetItem(M2C_FIELD(a,s32 *,4),i);if(b==SBServerGetIp(p)&&c==func_02060c70(p))return i;}return -1;}

void func_02061b38(void *a,s32 b){void func_02060cbc(s32,s32);s32 p=M2C_FIELD(a,s32 *,0x5d0);if(!p)func_02060cbc(b,0);else func_02060cbc(b,p);M2C_FIELD(a,s32 *,0x5d0)=b;}

void func_02061b6c(void *a,s32 b) {
s32 *Vector_GetItem();
void func_0204890c(s32,s32);
s32 p=*Vector_GetItem(M2C_FIELD(a,s32 *,4),b);
M2C_FIELD(a,M2C_UNK (**)(void *,s32,s32,s32),0x488)(a,2,p,M2C_FIELD(a,s32 *,0x494));
func_0204890c(M2C_FIELD(a,s32 *,4),b);
func_02061b38(a,p);
}

void func_02061bb8(void *arg0) {
    M2C_UNK Vector_GetCount(s32);
    Vector_GetCount(M2C_FIELD(arg0, s32 *, 4));
}

s32 SBServerListGetServerAt(void *arg0) {
    s32 *Vector_GetItem(s32);
    return *Vector_GetItem(M2C_FIELD(arg0, s32 *, 4));
}

void func_02061bdc(void *arg0) {
    M2C_UNK func_02060a60(s32 *);
    s32 func_02060cc4(s32);
    s32 sp0;
    s32 var_r5;

    var_r5 = M2C_FIELD(arg0, s32 *, 0x5D0);
    if (var_r5 == 0) {
        return;
    }
    sp0 = var_r5;
    if (var_r5 != 0) {
        do {
            var_r5 = func_02060cc4(var_r5);
            func_02060a60(&sp0);
            sp0 = var_r5;
        } while (var_r5 != 0);
    }
    M2C_FIELD(arg0, s32 *, 0x5D0) = 0;
}

s32 func_02061c34(void *a) {
s32 Vector_GetCount(s32);s32 *Vector_GetItem();void func_02048b74(s32);
s32 i,n;
n=Vector_GetCount(M2C_FIELD(a,s32 *,4));
for(i=0;i<n;i++)func_02061b38(a,*Vector_GetItem(M2C_FIELD(a,s32 *,4),i));
func_02048b74(M2C_FIELD(a,s32 *,4));
func_02061bdc(a);
}

void func_02061c8c(void *arg0) {
    s32 func_02048558(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_FIELD(arg0, s32 *, 4) = func_02048558(4, 0x64, 0);
    M2C_FIELD(arg0, s32 *, 0x5D0) = 0;
}

s32 func_02061cb4(s32 a,s32 b) {
s32 func_020609bc(s32);
s32 *func_02048ff8(s32,s32 *);
s32 gpiStringDup(s32);
void func_02048eac(s32,s32 *);
s32 pair[2]; s32 *p;
pair[0]=b;
p=func_02048ff8(func_020609bc(a),pair);
if(p){p[1]++;return p[0];}
pair[0]=gpiStringDup(b);pair[1]=1;
func_02048eac(func_020609bc(a),pair);
return pair[0];
}

void func_02061d24(void *a,s32 b) {s32 func_020609bc(s32);s32 *func_02048ff8(s32,s32 *);void func_02048f54(s32,s32 *);void AssertFailed(void *,void *,void *,s32);s32 pair[2];s32 *p;pair[0]=b;p=func_02048ff8(func_020609bc((s32)a),pair);if(!p)AssertFailed(data_02100120,data_0210012c,data_02100094,0xf4);if(!p)return;if(--p[1])return;func_02048f54(func_020609bc((s32)a),pair);}

s32 BoundedStringLength(s8 *a,s32 b){s32 i;for(i=0;i<b;i++){if(!a[i])return i+1;}return -1;}

void func_02061dd0(void *p,void *a,void *b,void *c,s32 d,s32 force,s32 cb,s32 userdata){
extern u8 data_0210013c[],data_021000c4[],data_0210014c[];extern s32 gDnsQueryState[];extern M2C_UNK data_0210011c;
void AssertFailed(void*,void*,void*,s32);s32 func_020609bc(s32);void StringCopy(void*,void*);void func_02062e28(void*,void*);s32 GetTickCountMs(void);void SetRandSeed(s32);void func_0204926c(void);
if(!p)AssertFailed(data_0210013c,data_0210012c,data_021000c4,0x11c);
if(!force && gDnsQueryState[0]!=1)return;
M2C_FIELD(p,s32*,0)=1;func_02061c8c(p);func_020609bc((s32)p);
StringCopy((u8*)p+0xc,a);StringCopy((u8*)p+0x30,b);StringCopy((u8*)p+0x54,c);
M2C_FIELD(p,s32*,0x488)=cb;M2C_FIELD(p,s32*,0x48c)=0;
if(!cb)AssertFailed(data_0210014c,data_0210012c,data_021000c4,0x132);
M2C_FIELD(p,s32*,0x494)=userdata;M2C_FIELD(p,void**,0x498)=&data_0210011c;
M2C_FIELD(p,s32*,0x4a0)=0;M2C_FIELD(p,s32*,0x4b0)=-1;
M2C_FIELD(p,s32*,0x7c)=0;M2C_FIELD(p,s32*,0x80)=0;M2C_FIELD(p,s32*,8)=0;
M2C_FIELD(p,s32*,0x484)=-1;M2C_FIELD(p,s32*,0x480)=0;
M2C_FIELD(p,s32*,0x4a4)=0;M2C_FIELD(p,s32*,0x4b8)=d;
func_02062e28(p,&data_0210011c);M2C_FIELD(p,s32*,0x5cc)=0;
SetRandSeed(GetTickCountMs());func_0204926c();
}

s32 func_02061efc(void *a) {s32 StringLength(M2C_UNK *);s32 StringCompareN(void *,void *,u32);void func_02062e28(void *,void *);void SBServerListDisconnect(void *);s32 n;void *p,*q,*s;n=M2C_FIELD(a,s32 *,0x80);if(n>0){s=data_02100090;if((u32)n>(u32)StringLength(s)){p=M2C_FIELD(a,void **,0x7c);q=data_02100090;if(!StringCompareN(p,q,StringLength(q))){func_02062e28(a,(u8 *)p+StringLength(s));M2C_FIELD(a,M2C_UNK (**)(void *,s32,s32,s32),0x488)(a,5,data_0213e4b4[0],M2C_FIELD(a,s32 *,0x494));}}}M2C_FIELD(a,M2C_UNK (**)(void *,s32,s32,s32),0x488)(a,4,data_0213e4b4[0],M2C_FIELD(a,s32 *,0x494));SBServerListDisconnect(a);}

s32 func_02061fb8(void *arg0, s32 arg1) {
    extern volatile u8 data_020eac40[128];
    s64 func_020722fc(s32, s32);
    s8 *p = (s8 *)arg0;
    s8 c;
    s32 h = 0;
    while ((c = *p) != 0) {
        h = 0x9CCF9319 * h + (c >= 0 && c < 0x80 ? data_020eac40[c] : c);
        p++;
    }
    return (s32)((func_020722fc(h, arg1)) >> 32);
}

s32 SBServerListOpenConnection(void *p){
s32 func_02061fb8(void*,s32);void StringCopy(void*,void*);void StringFormat(void*,void*,...);s32 func_020498e4(void*);void *ghiResolveHostname(void*);s32 ghiSocket(s32,s32,s32);s32 ghiConnect(s32,void*,s32);s32 func_020496b8(s32);
extern void *data_0213e4bc;extern u8 data_02100160[];
u8 buf[128];Addr617BC addr;s32 n,fd;void *host;
n=func_02061fb8((u8*)p+12,20);
if(M2C_FIELD(&data_0213e4bc,void**,4))StringCopy(buf,M2C_FIELD(&data_0213e4bc,void**,4));
else StringFormat(buf,data_02100160,(u8*)p+12,n);
addr.family=2;addr.port=0xee70;addr.addr=func_020498e4(buf);
if(addr.addr==-1){host=ghiResolveHostname(buf);if(!host)return 2;Copy617BC((u8*)&addr.addr,*M2C_FIELD(host,u8***,12));}
fd=M2C_FIELD(p,s32*,0x4b0);
if(fd==-1){fd=ghiSocket(2,1,0);M2C_FIELD(p,s32*,0x4b0)=fd;if(fd==-1)return 1;}
if(ghiConnect(fd,&addr,8)==0)return 0;
func_020496b8(M2C_FIELD(p,s32*,0x4b0));M2C_FIELD(p,s32*,0x4b0)=-1;return 3;
}

void AppendString(s32 *arg0, M2C_UNK *arg1, s32 *arg2) {
    M2C_UNK MemCopy(s32, M2C_UNK *, s32);
    s32 StringLength(M2C_UNK *);
    extern M2C_UNK data_0210011c;
    M2C_UNK *var_r7;
    s32 temp_r5;

    var_r7 = arg1;
    if (var_r7 == NULL) {
        var_r7 = &data_0210011c;
    }
    temp_r5 = StringLength(var_r7) + 1;
    MemCopy(*arg0, var_r7, temp_r5);
    *arg2 += temp_r5;
    *arg0 += temp_r5;
}

void AppendByte(s8 **arg0, s8 arg1, s32 *arg2) {
    **arg0 = arg1;
    *arg2 += 1;
    *arg0 += 1;
}

void AppendInt32BE(u8 **a,s32 b,s32 *c,...){u8 *p=*a;u8 *q=(u8 *)&b;u8 x,y;x=q[1];y=q[0];p[0]=y;p[1]=x;x=q[3];y=q[2];p[2]=y;p[3]=x;*c+=4;*a+=4;}

void AppendBytes(s32 *a,M2C_UNK *b,s32 c,s32 *d) {
M2C_UNK MemCopy(s32,M2C_UNK *,s32);
MemCopy(*a,b,c);*d+=c;*a+=c;
}

void GenerateSessionKey(void *arg0) {
 s32 Rand(void);
 s32 i, parity; s8 *p; s32 a,b;
 *(s8 *)((u8 *)arg0+0x74)=Rand()%93+33;
 parity=0;
 i=1; do {
 p=(s8 *)((u32)arg0+i);
 a=p[0x73]; b=*((s8 *)arg0+0x74);
 { s32 x,y; if(a<b)x=1;else x=0; if(b<79)y=1;else y=0; parity=(b&1)^(parity^((i^a)&1)); parity^=y; parity^=x; }
 p[0x74]=Rand()%93+33;
 if ((parity && !(p[0x74]&1)) || (!parity && (p[0x74]&1)==1)) p[0x74]++;
 i++; }while(i<8);
}

s32 func_02062324(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_02049810(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02061efc(void *);
    s32 SBServerListConnectAndQuery(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 temp_r0;
    s32 temp_r0_2;
    s32 var_r7;

    var_r7 = 1;
loop_1:
    var_r7 -= 1;
    temp_r0_2 = func_02049810(M2C_FIELD(arg0, s32 *, 0x4B0), arg1, arg2, 0);
    if ((temp_r0_2 <= 0) && (var_r7 >= 0)) {
        SBServerListDisconnect(arg0);
        temp_r0 = SBServerListConnectAndQuery(arg0, 0, 0, 2, 0);
        if (temp_r0 != 0) {
            func_02061efc(arg0);
            return temp_r0;
        }
        if (var_r7 < 0) {
            goto block_6;
        }
        goto loop_1;
    }
block_6:
    if (temp_r0_2 <= 0) {
        return 3;
    }
    return 0;
}

#pragma push
#pragma opt_propagation off
/* Connect a server list to the QR2 master server and send the initial query packet:
   protocol header, game id, host names, session key, requested fields, filter, query
   flags and (for flag 0x80) the maximum server count; allocate the receive buffer. */
s32 SBServerListConnectAndQuery(void *slist, M2C_UNK filter, M2C_UNK fields, M2C_UNK queryFlags, s32 maxServers) {
extern u8 data_0210017c[],data_02100100[];extern M2C_UNK data_0210011c;
void AssertFailed(void*,void*,void*,s32);s32 StringLength(M2C_UNK*);s32 func_02049810(s32,s32,s32,s32);s32 gpiMalloc(s32);
u8 packet[768];s32 length;u8 *out;u16 beLength;u8 *lenBytes,*packetBytes;s32 err;
if(M2C_FIELD(slist,s32*,0)!=1)AssertFailed(data_0210017c,data_0210012c,data_02100100,0x20a);
if(!filter)filter=(s32)&data_0210011c;if(!fields)fields=(s32)&data_0210011c;
if((u32)StringLength((M2C_UNK*)filter)>256)return 6;if((u32)StringLength((M2C_UNK*)fields)>256)return 6;
err=SBServerListOpenConnection(slist);if(err)return err;
M2C_FIELD(slist,s32*,0x5c4)=queryFlags;GenerateSessionKey(slist);
length=2;out=packet+2;
AppendByte((s8**)&out,0,&length);AppendByte((s8**)&out,1,&length);AppendByte((s8**)&out,3,&length);
AppendInt32BE(&out,M2C_FIELD(slist,s32*,0x4b8),&length);
AppendString((s32*)&out,(M2C_UNK*)((u8*)slist+12),&length);AppendString((s32*)&out,(M2C_UNK*)((u8*)slist+48),&length);
AppendBytes((s32*)&out,(M2C_UNK*)((u8*)slist+0x74),8,&length);
AppendString((s32*)&out,(M2C_UNK*)fields,&length);AppendString((s32*)&out,(M2C_UNK*)filter,&length);
AppendInt32BE(&out,((u32)queryFlags<<24&0xff000000)|(((u32)queryFlags<<8&0xff0000)|(((u32)queryFlags>>24&255)|((u32)queryFlags>>8&0xff00))),&length);
if(M2C_FIELD(slist,s32*,0x5c4)&8)AppendInt32BE(&out,M2C_FIELD(slist,s32*,0x4a4),&length);
if(M2C_FIELD(slist,s32*,0x5c4)&128)AppendInt32BE(&out,maxServers,&length);
lenBytes=(u8 *)&beLength;
beLength=(((u16)length>>8)&255)|(((u16)length<<8)&0xff00);
packetBytes=packet;*((Pair617BC *)packetBytes)=*((Pair617BC *)lenBytes);
if(func_02049810(M2C_FIELD(slist,s32*,0x4b0),(s32)packetBytes,length,0)<=0){SBServerListDisconnect(slist);return 3;}
M2C_FIELD(slist,s32*,0)=3;M2C_FIELD(slist,s32*,0x5c8)=0;
if(!M2C_FIELD(slist,s32*,0x7c)){M2C_FIELD(slist,s32*,0x7c)=gpiMalloc(4096);if(!M2C_FIELD(slist,s32*,0x7c))return 5;M2C_FIELD(slist,s32*,0x80)=0;}
return 0;
}
#pragma pop
void func_0206262c(void *a) {void func_02061d24(void *,s32);s32 i;for(i=0;i<M2C_FIELD(a,s32 *,0x480);i++)func_02061d24(a,((s32 *)a)[i+33]);M2C_FIELD(a,s32 *,0x480)=0;}

void func_02062670(void *a) {
s32 Vector_GetCount(s32);s32 *Vector_GetItem();void func_02061d24(void *,s32);s32 func_0204861c();
s32 i; s32 p=M2C_FIELD(a,s32 *,8);
if(!p)return;
for(i=0;i<Vector_GetCount(M2C_FIELD(a,s32 *,8));i++)func_02061d24(a,*Vector_GetItem(M2C_FIELD(a,s32 *,8),i));
func_0204861c(M2C_FIELD(a,s32 *,8));M2C_FIELD(a,s32 *,8)=0;
}

s32 SBServerListDisconnect(void *a) {
s32 gpiFree();s32 func_020496b8();
if(M2C_FIELD(a,s32 *,0x7c))gpiFree(M2C_FIELD(a,s32 *,0x7c));
M2C_FIELD(a,s32 *,0x7c)=0;M2C_FIELD(a,s32 *,0x80)=0;
if(M2C_FIELD(a,s32 *,0x4b0)!=-1)func_020496b8(M2C_FIELD(a,s32 *,0x4b0));
M2C_FIELD(a,s32 *,0x4b0)=-1;M2C_FIELD(a,s32 *,0)=1;
func_02062670(a);M2C_FIELD(a,s32 *,0x484)=-1;func_0206262c(a);
}

void func_02062738(void *arg0) {
    M2C_UNK func_0204861c();
    M2C_UNK func_02060a20(void *);
    M2C_UNK func_02061c34(void *);
    M2C_UNK SBServerListDisconnect();
    SBServerListDisconnect();
    func_02061c34(arg0);
    func_02060a20(arg0);
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        func_0204861c();
    }
    M2C_FIELD(arg0, s32 *, 4) = 0;
}

