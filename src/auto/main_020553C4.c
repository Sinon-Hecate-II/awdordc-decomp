/* 24 functions from 0x020553C4 to 0x020562D0 (main), found by ds-decomp. */
#include "common.h"
static inline s32 *Init55550(s32 *p) {s32 addr=(s32)p;M2C_FIELD(addr,s32 *,16)=0;M2C_FIELD(addr,s32 *,0)=0;M2C_FIELD(addr,s32 *,4)=0;M2C_FIELD(addr,s32 *,8)=0;M2C_FIELD(addr,s32 *,12)=0;M2C_FIELD(addr,s32 *,20)=0;return p;}
typedef struct { s32 unk_0; s32 unk_4; } Unk02050838Pair;
typedef struct Unk020553C4 { u8 pad[0x428]; s32 handle, unk42c, unk430; } Unk020553C4;
typedef struct { u8 bytes[8]; } UnkSocketAddress;
static inline void InitSocketAddress(s32 *p) { s32 addr=(s32)p; M2C_FIELD(addr,s32 *,0)=0; M2C_FIELD(addr,s32 *,4)=0; }

s32 func_020553c4(M2C_UNK arg0, void *arg1) {
    s32 ghiSetNonBlocking(s32, M2C_UNK);
    s32 ghiSocket(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 ghiConnect(s32, UnkSocketAddress *, u8);
    s32 ghiGetLastSocketError(s32);
    void gpiCallErrorCallback(void *, s32, s32);
    M2C_UNK func_02055124(s32);
    void gpiSetError(void **, s32, M2C_UNK);
    s32 gpiSetErrorString(M2C_UNK, M2C_UNK *);
    extern M2C_UNK data_020feb6c;
    extern M2C_UNK data_020fecb0;
    extern M2C_UNK data_020fecd8;
    extern M2C_UNK data_020fed0c;
    s32 addr[2]; s32 node;
    s32 *qp;

    if (func_02055b84(arg0, M2C_FIELD(arg1, s32 *, 0xc), &node) == 0) {
        gpiSetErrorString(arg0, &data_020feb6c);
        return 3;
    }
    M2C_FIELD(arg1, s32 *, 0x8) = ghiSocket(2, 1, 0);
    if (M2C_FIELD(arg1, s32 *, 0x8) == -1) {
        gpiSetError(arg0, 5, &data_020fecb0);
        gpiCallErrorCallback(arg0, 3, 0);
        return 3;
    }
    if (ghiSetNonBlocking(M2C_FIELD(arg1, s32 *, 0x8), 0) == 0) {
        gpiSetError(arg0, 5, &data_020fecd8);
        gpiCallErrorCallback(arg0, 3, 0);
        return 3;
    }
    func_02055124(M2C_FIELD(arg1, s32 *, 0x8));
    InitSocketAddress(addr);
    *((u8 *)addr + 1) = 2;
    qp = (s32 *)node;
    addr[1] = M2C_FIELD(M2C_FIELD(qp,void **,8),s32 *,0x10);
    *((s16 *)addr + 1) = (s16) M2C_FIELD(M2C_FIELD(qp,void **,8),s32 *,0x14);
    if (ghiConnect(M2C_FIELD(arg1, s32 *, 0x8), (UnkSocketAddress *)addr, 8) == -1) {
        s32 r = ghiGetLastSocketError(M2C_FIELD(arg1, s32 *, 0x8));
        if ((r != -6) && (r != -0x1a) && (r != -0x4c)) {
            gpiSetError(arg0, 5, &data_020fed0c);
            gpiCallErrorCallback(arg0, 3, 1);
            return 3;
        }
    }
    M2C_FIELD(arg1, s32 *, 0x0) = 0x67;
    return 0;
}

#pragma opt_dead_code off
s32 func_02055550(s32 ctx,void *p,s32 a,s32 str) {
s32 StringLength(s32 *);s32 gpiAppendStringField();s32 gpiAppendIntField();s32 gpiAppendStringToBufferLen();s32 func_0204fcfc();s32 gpiGetTime(s32);
extern s32 data_020fec7c,data_020fec0c,data_020fead4,data_020fed34,data_020fed44,data_020fed48,data_020fed50;
s32 buf[6];s32 len,r;
if(!p)AssertFailed(&data_020fec7c,&data_020fec0c,&data_020fead4,0x340);
if(!str)AssertFailed(&data_020fed34,&data_020fec0c,&data_020fead4,0x341);
len=StringLength((s32 *)str);
Init55550(buf);buf[4]=a;
r=gpiAppendStringField(ctx,buf,&data_020fed44);if(r)return r;
r=gpiAppendIntField(ctx,buf,a);if(r)return r;
r=gpiAppendStringField(ctx,buf,&data_020fed48);if(r)return r;
r=gpiAppendIntField(ctx,buf,len);if(r)return r;
r=gpiAppendStringField(ctx,buf,&data_020fed50);if(r)return r;
buf[5]=buf[2];
r=gpiAppendStringToBufferLen(ctx,buf,str,len);if(r)return r;
r=func_0204fcfc(ctx,buf,0);if(r)return r;
func_020486f8(M2C_FIELD(p,s32 *,0x38),buf);
M2C_FIELD(p,s32 *,16)=gpiGetTime(0)+300;
return 0;
}
void func_020556e0(s32 arg0,s32 arg1,s32 arg2,s32 *arg3) {
M2C_UNK func_020501d8(s32,s32,void *);
M2C_UNK AssertFailed(void *,void *,void *,s32);
M2C_UNK StringFormat(void *,void *,...);
extern M2C_UNK data_020fed58,data_020fec0c,data_020feae8,data_020fed64;
u8 buf[64];s32 b,a,c;
a=arg3[0];b=arg3[1];c=arg3[2];
if(!arg3)AssertFailed(&data_020fed58,&data_020fec0c,&data_020feae8,0x376);
StringFormat(buf,&data_020fed64,arg2,a,b,c);
func_020501d8(arg0,arg1,buf);
}

s32 func_0205575c(M2C_UNK arg0, void *arg1, M2C_UNK *arg2, s32 arg3) {
s32 gpiGetTime(M2C_UNK);
s32 func_0204fff8(M2C_UNK,void *,M2C_UNK);
s32 gpiSendOrBufferStringLen(M2C_UNK,void *,M2C_UNK *,s32);
s32 func_020501d8(s32,s32,void *);
M2C_UNK AssertFailed(void *,void *,void *,s32);
M2C_UNK StringFormat(void *,void *,...);
s32 StringLength(M2C_UNK *);
extern M2C_UNK data_020feb04,data_020fec0c,data_020fec7c,data_020fed78,data_020fed7c;
M2C_UNK buffer[8];s32 result;
if(!arg1)AssertFailed(&data_020fec7c,&data_020fec0c,&data_020feb04,0x389);
if(!arg2)arg2=&data_020fed78;
if(arg3==-1)arg3=StringLength(arg2);
StringFormat(buffer,&data_020fed7c,arg3);
result=func_020501d8(arg0,arg1,buffer);if(result)return result;
result=gpiSendOrBufferStringLen(arg0,arg1,arg2,arg3);if(result)return result;
result=func_0204fff8(arg0,arg1,0);if(result)return result;
M2C_FIELD(arg1,s32 *,0x10)=gpiGetTime(0)+0x12c;
return 0;
}

s32 func_02055848(s32 *arg0) {
unsigned long long func_020720f0(s32);
return (s32)(func_020720f0(*arg0)>>32);
}

s32 func_0205585c(s32 *arg0, s32 *arg1) {
    return *arg0 - *arg1;
}

void func_0205586c(void *arg0) {
    M2C_UNK gpiFree(void *);
    M2C_UNK func_02053f18(void *);
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 8);
    if (temp_r0 != NULL) {
        gpiFree(M2C_FIELD(temp_r0, void **, 8));
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 8) = NULL;
        gpiFree(M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0xC));
        M2C_FIELD(M2C_FIELD(arg0, void **, 8), void **, 0xC) = NULL;
        gpiFree(M2C_FIELD(arg0, void **, 8));
        M2C_FIELD(arg0, void **, 8) = NULL;
    }
    func_02053f18(arg0);
    gpiFree(M2C_FIELD(arg0, void **, 0x10));
    M2C_FIELD(arg0, void **, 0x10) = NULL;
    gpiFree(M2C_FIELD(arg0, void **, 0x18));
    M2C_FIELD(arg0, void **, 0x18) = NULL;
}

s32 func_020558e8(void **arg0) {
s32 func_02048c5c();
Unk020553C4 *p=*arg0;
p->unk430=0;p->unk42c=0;
p->handle=func_02048c5c(28,4,func_02055848,func_0205585c,func_0205586c);
return p->handle!=0;
}

s32 func_02055940(void **a,void *b,s32 c) {
s32 func_0205817c(void **,s32,s32);void gpiSetError(void **,s32,s32);s32 gpiSetErrorString(s32,s32 *);
s32 StringCompareN(s32,void *,s32);void gpiCallErrorCallback(void *,s32,s32);void *gpiMalloc(s32);s32 gpiAddCallback(void *,Unk02050838Pair,s32 *,void *,s32);void func_02054484(void **,void *);
s32 GetStringField(s32,void *,void *,s32);s32 ParseInt(void *);
extern M2C_UNK data_020feda0,data_020feda8,data_020fedd8,data_020fede4;
char buffer[16];Unk02050838Pair pair;s32 *p;s32 r;s32 value;
if(func_0205817c(a,c,1))return 4;
if(StringCompareN(c,&data_020feda0,5)){gpiSetError(a,1,(s32)&data_020feda8);gpiCallErrorCallback(a,3,1);return 3;}
if(!GetStringField(c,&data_020fedd8,buffer,16)){gpiSetError(a,1,(s32)&data_020feda8);gpiCallErrorCallback(a,3,1);return 3;}
value=ParseInt(buffer);
pair=*(Unk02050838Pair *)((u8 *)b+12);
if(pair.unk_0){p=gpiMalloc(8);if(!p){gpiSetErrorString((s32)a,(s32 *)&data_020fede4);return 1;}p[1]=value;p[0]=0;r=gpiAddCallback(a,pair,p,b,0);if(r)return r;}
func_02054484(a,b);return 0;
}

s32 func_02055aa0(void **arg0, s32 arg1) {
    M2C_UNK func_02048eac(s32,s32 *);
    M2C_UNK AssertFailed();
    extern M2C_UNK data_020fed8c;
    extern M2C_UNK data_020fedf4;
    extern M2C_UNK data_020fedfc;
    s32 key[7];
    s32 sp0;
    void *temp_r4;

    temp_r4 = *arg0;
    if (arg1 <= 0) {
        AssertFailed(&data_020fedf4, &data_020fedfc, &data_020fed8c, 0x2B5);
    }
    if (arg1 <= 0) {
        return 0;
    }
    if (func_02055b84(arg0, arg1, &sp0) != 0) {
        return sp0;
    }
    M2C_FIELD((s32)key, s32 *, 0) = 0;
    M2C_FIELD((s32)key, s32 *, 4) = 0;
    M2C_FIELD((s32)key, s32 *, 0xC) = 0;
    M2C_FIELD((s32)key, s32 *, 0x10) = 0;
    M2C_FIELD((s32)key, s32 *, 0x14) = 0;
    M2C_FIELD((s32)key, s32 *, 0x18) = 0;
    key[0] = arg1;
    M2C_FIELD((s32)key, s32 *, 8) = 0;
    key[1] = 0;
    key[3] = 0;
    key[4] = 0;
    key[6] = 0;
    key[5] = 0;
    func_02048eac(M2C_FIELD(temp_r4, s32 *, 0x428),key);
    M2C_FIELD(temp_r4, s32 *, 0x42C) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x42C) + 1);
    if (func_02055b84(arg0, arg1, &sp0) != 0) {
        return sp0;
    }
    return 0;
}

s32 func_02055b84(void **arg0,s32 arg1,s32 *arg2) {
s32 func_02048ff8(s32,void *);
s32 key[7];s32 v;void *p=*arg0;
key[0]=arg1;
v=func_02048ff8(M2C_FIELD(p,s32 *,0x428),key);
if(arg2)*arg2=v;
return v!=0;
}

void func_02055bc0(void **arg0, M2C_UNK arg1) {
    s32 func_02055b84(void **, M2C_UNK, s32 *);
    s32 sp0;
    void *temp_r4;

    temp_r4 = *arg0;
    if (func_02055b84(arg0, arg1, &sp0) == 0) {
        return;
    }
    func_02048f54(M2C_FIELD(temp_r4, s32 *, 0x428), sp0);
}

void func_02055bf4(void **arg0) {
    M2C_UNK func_02048f54(s32);
    func_02048f54(M2C_FIELD(*arg0, s32 *, 0x428));
}

s32 func_02055c08(s32 arg0,void *arg1,void *arg2) {
s32 StringCompare(s32,s32);
void *p=M2C_FIELD(arg1,void **,12);
if(p && StringCompare(M2C_FIELD(arg2,s32 *,0),M2C_FIELD(p,s32 *,0))==0 && StringCompare(M2C_FIELD(arg2,s32 *,4),M2C_FIELD(p,s32 *,8))==0){
*M2C_FIELD(arg2,void ***,8)=arg1;M2C_FIELD(arg2,s32 *,12)=1;return 0;
}
return 1;
}

s32 func_02055c68(void **arg0,s32 arg1,s32 arg2,s32 *arg3) {
s32 func_02055cd0(void **,s32 (*)(s32,void *,void *),void *);
s32 data[4];
data[0]=arg1;data[1]=arg2;data[3]=0;data[2]=(s32)arg3;
func_02055cd0(arg0,func_02055c08,data);
if(!data[3])*arg3=0;
return 0;
}

void func_02055cb4(M2C_UNK arg0, void *arg1) {
    M2C_FIELD(arg1, M2C_UNK (**)(s32, M2C_UNK, s32), 4)(M2C_FIELD(arg1, s32 *, 0), arg0, M2C_FIELD(arg1, s32 *, 8));
}

s32 func_02055cd0(void **arg0,s32 (*arg1)(s32,void *,void *),void *arg2) {
s32 func_02049104(s32,void (*)(s32,void *),void *);
s32 data[3];void *p=*arg0;
data[1]=(s32)arg1;data[2]=(s32)arg2;data[0]=(s32)arg0;
return func_02049104(M2C_FIELD(p,s32 *,0x428),func_02055cb4,data)==0;
}

s32 func_02055d10(s32 arg0,void *arg1,void *arg2) {
s32 *p=M2C_FIELD(arg1,s32 **,8);
if(p && M2C_FIELD(arg2,s32 *,0)==*p){M2C_FIELD(arg2,void **,4)=arg1;return 0;}
return 1;
}

s32 func_02055d3c(void **arg0, s32 arg1) {
s32 data[2]; data[0]=arg1;data[1]=0;
func_02055cd0(arg0,func_02055d10,data);return data[1];
}

s32 func_02055d6c(void *arg0) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, s32 *, 0xC) == 0) && (M2C_FIELD(arg0, s32 *, 8) == 0) && (M2C_FIELD(arg0, s32 *, 0x18) == 0) && (M2C_FIELD(arg0, s32 *, 0x10) == 0)) {
        return 1;
    }
    return 0;
}

/* Connects to the GameSpy profile search manager: allocates the search's
 * receive buffer, opens a TCP socket, resolves gpsp.gs.nintendowifi.net and
 * starts a non-blocking connect to it on port 0x74CD (0xcd74 in network byte
 * order). */
s32 gpiStartProfileSearch(void **connection, void *search) {
    void *gpiMalloc(s32);
    s32 ghiSocket(s32, s32, s32);
    s32 ghiSetNonBlocking(s32, s32);
    void *ghiResolveHostname(void *);
    s32 ghiConnect(s32, UnkSocketAddress *, u8);
    s32 ghiGetLastSocketError(s32);
    s32 gpiSetErrorString(M2C_UNK, M2C_UNK *);
    void gpiSetError(void **, s32, M2C_UNK);
    void gpiCallErrorCallback(void *, s32, s32);
    M2C_UNK AssertFailed(void *, void *, void *, s32);
    extern M2C_UNK gGpiSearchMsgOutOfMemory, gGpiSearchMsgCreateSocket, gGpiSearchMsgSetNonBlocking, gGpiSearchManagerHostname, gGpiSearchMsgResolveManager, gGpiSearchAssertSinAddr, gGpiSearchSourceFile, gGpiStartProfileSearchName, gGpiSearchMsgConnect;
    void *searchData = M2C_FIELD(search, void **, 4), *resolved;
    s32 addr[2];
    s32 error;
    M2C_FIELD(searchData, s32 *, 12) = 4096;
    M2C_FIELD(searchData, void **, 8) = gpiMalloc(4097);
    if (!M2C_FIELD(searchData, void **, 8)) { gpiSetErrorString(connection, &gGpiSearchMsgOutOfMemory); return 1; }
    M2C_FIELD(searchData, s32 *, 4) = ghiSocket(2, 1, 0);
    if (M2C_FIELD(searchData, s32 *, 4) == -1) { gpiSetError(connection, 5, &gGpiSearchMsgCreateSocket); gpiCallErrorCallback(connection, 3, 1); return 3; }
    if (!ghiSetNonBlocking(M2C_FIELD(searchData, s32 *, 4), 0)) { gpiSetError(connection, 5, &gGpiSearchMsgSetNonBlocking); gpiCallErrorCallback(connection, 3, 1); return 3; }
    resolved = ghiResolveHostname(&gGpiSearchManagerHostname);
    if (!resolved) { gpiSetError(connection, 5, &gGpiSearchMsgResolveManager); gpiCallErrorCallback(connection, 3, 1); return 3; }
    InitSocketAddress(addr);
    ((u8 *)addr)[1] = 2;
    addr[1] = **M2C_FIELD(resolved, s32 ***, 12);
    if (!addr[1]) AssertFailed(&gGpiSearchAssertSinAddr, &gGpiSearchSourceFile, &gGpiStartProfileSearchName, 89);
    ((u16 *)addr)[1] = 0xcd74;
    if (ghiConnect(M2C_FIELD(searchData, s32 *, 4), (UnkSocketAddress *)addr, 8) == -1) {
        error = ghiGetLastSocketError(M2C_FIELD(searchData, s32 *, 4));
        if (error != -6 && error != -26 && error != -76) { gpiSetError(connection, 5, &gGpiSearchMsgConnect); gpiCallErrorCallback(connection, 3, 1); return 3; }
    }
    M2C_FIELD(search, s32 *, 20) = 1;
    return 0;
}

s32 gpiCreateSearchData(M2C_UNK arg0, void **arg1, s32 arg2) {
void *gpiMalloc(M2C_UNK); M2C_UNK gpiSetErrorString(M2C_UNK,M2C_UNK *); M2C_UNK func_02065210(void *,M2C_UNK,M2C_UNK); extern M2C_UNK gGpiSearchMsgOutOfMemory;
void *p,*buf; s32 n;
p=gpiMalloc(0x144);
if(!p){gpiSetErrorString(arg0,&gGpiSearchMsgOutOfMemory);return 1;}
func_02065210(p,0,0x144);
M2C_FIELD(p,s32 *,0)=arg2;
M2C_FIELD(p,s32 *,4)=-1;
M2C_FIELD(p,s32 *,8)=0;
M2C_FIELD(p,s32 *,0x10)=0;
M2C_FIELD(p,s32 *,0x14)=0;
M2C_FIELD(p,s32 *,0xc)=0;
M2C_FIELD(p,s32 *,0x20)=0;
M2C_FIELD(p,volatile s32 *,0x24)=0;
n=0x1000;
M2C_FIELD(p,s32 *,0x1c)=n;
buf=gpiMalloc(n+1);
M2C_FIELD(p,void **,0x18)=buf;
if(!buf){gpiSetErrorString(arg0,&gGpiSearchMsgOutOfMemory);return 1;}
M2C_FIELD(p,s32 *,0x13c)=0; M2C_FIELD(p,s32 *,0x140)=0; *arg1=p; return 0;
}

s32 gpiStartSearch(void **arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 gpiThink(void **, s32);
    s32 gpiAddOperation(void **, M2C_UNK, M2C_UNK, void **, s32, s32, s32);
    s32 gpiStartProfileSearch(void **, void *);
    void *spC;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    void *temp_r4;

    temp_r4 = *arg0;
    M2C_FIELD(temp_r4, s32 *, 0x210) = (s32) (M2C_FIELD(temp_r4, s32 *, 0x210) + 1);
    temp_r0_3 = gpiAddOperation(arg0, 3, arg1, &spC, arg2, arg3, arg4);
    if (temp_r0_3 != 0) {
        return temp_r0_3;
    }
    temp_r0_2 = gpiStartProfileSearch(arg0, spC);
    if (temp_r0_2 != 0) {
        return temp_r0_2;
    }
    if (M2C_FIELD(spC, s32 *, 8) != 0) {
        temp_r0 = gpiThink(arg0, M2C_FIELD(spC, s32 *, 0x18));
        if (temp_r0 != 0) {
            return temp_r0;
        }
    }
    return 0;
}

s32 gpiSearchProfiles(void **connection,s8 *nick,s8 *uniquenick,s8 *email,s8 *firstname,s8 *lastname,s32 icq,s32 countrycode,s32 flags,s32 callback,s32 callbackParam) {
M2C_UNK StringToLower(void *);s32 gpiCreateSearchData(M2C_UNK,void **,M2C_UNK);M2C_UNK StringCopyN(void *,s8 *,M2C_UNK);M2C_UNK gpiSetErrorString(M2C_UNK,M2C_UNK *);
extern M2C_UNK gGpiSearchMsgNoCriteria;
GpiSearchRequest *searchData;s32 r;
/* Start a gpi profile search with the given criteria (at least one of nick,
   unique nick, email, first name, last name or icq must be supplied). */
if(nick && *nick)goto ready;
if(email && *email)goto ready;
if(firstname && *firstname)goto ready;
if(lastname && *lastname)goto ready;
if(icq==0){if(uniquenick && *uniquenick)goto ready;gpiSetErrorString(connection,&gGpiSearchMsgNoCriteria);return 2;}
ready:
r=gpiCreateSearchData(connection,(void **)&searchData,1);if(r)return r;
if(!nick)searchData->nick[0]=0;else StringCopyN(searchData->nick,nick,31);
if(!uniquenick)searchData->uniquenick[0]=0;else StringCopyN(searchData->uniquenick,uniquenick,21);
if(!email)searchData->email[0]=0;else StringCopyN(searchData->email,email,51);
StringToLower(searchData->email);
if(!firstname)searchData->firstname[0]=0;else StringCopyN(searchData->firstname,firstname,31);
if(!lastname)searchData->lastname[0]=0;else StringCopyN(searchData->lastname,lastname,31);
searchData->icq=icq;
if(countrycode<0)countrycode=0;
searchData->countrycode=countrycode;
r=gpiStartSearch(connection,searchData,flags,callback,callbackParam);if(r==0)r=0;return r;
}

