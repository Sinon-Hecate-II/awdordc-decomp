/* 33 functions from 0x020617BC to 0x02062770 (main), found by ds-decomp. */
#include "common.h"
#include "sb_serverlist.h"
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
extern u8 sSbFileName[];
extern u8 data_02100094[];
extern void *sSbQueryErrorPrefix;
extern s32 sSbNoServer[2];

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

/* Server-list sort callback for a floating-point key: compare the two servers'
 * values of the sort key as doubles and return the sign of their quotient
 * (which stands in for the difference), inverted when the list sorts
 * ascending. */
s32 SBServerListCompareFloat(s32 *serverA, s32 *serverB) {
    double SBServerGetFloatValue(void *, s32, double);
    double func_02070b70(double, double);
    extern void *data_0213e4bc;
    double valueA;
    double valueB;
    double diff;
    s32 server;
    s32 result;

    server = *serverB;
    valueA = SBServerGetFloatValue((void *) *serverA, M2C_FIELD(data_0213e4bc, s32 *, SB_SLIST_SORT_FIELD), 0.0);
    valueB = SBServerGetFloatValue((void *) server, M2C_FIELD(data_0213e4bc, s32 *, SB_SLIST_SORT_FIELD), 0.0);
    diff = func_02070b70(valueA, valueB);
    if (M2C_FIELD(data_0213e4bc, s32 *, SB_SLIST_SORT_DESC) == 0) {
        diff = func_02070b70(0.0, diff);
    }
    if ((float)diff > 0.0f) return 1;
    return -((float)diff < 0.0f);
}

/* Server-list sort callback for a string key: compare the two servers' values of
 * the list's sort key, negated when the list sorts ascending. */
s32 SBServerListCompareString(s32 *serverA, s32 *serverB) {
    s32 SBServerGetStringValue(s32, s32, M2C_UNK *);
    s32 StringCompare(s32, s32);
    extern void *data_0213e4bc;
    extern M2C_UNK sSbEmptyString;
    s32 valueA;
    s32 result;

    valueA = SBServerGetStringValue(*serverA, M2C_FIELD(data_0213e4bc, s32 *, SB_SLIST_SORT_FIELD), &sSbEmptyString);
    result = StringCompare(valueA, SBServerGetStringValue(*serverB, M2C_FIELD(data_0213e4bc, s32 *, SB_SLIST_SORT_FIELD), &sSbEmptyString));
    if (M2C_FIELD(data_0213e4bc, s32 *, SB_SLIST_SORT_DESC) == 0) {
        result = -result;
    }
    return result;
}

s32 func_02061958(s32 *arg0, s32 *arg1) {
    s32 SBServerGetStringValue(s32, s32, M2C_UNK *);
    s32 func_0206f8ac(s32, s32);
    extern void *data_0213e4bc;
    extern M2C_UNK sSbEmptyString;
    s32 temp_r4;
    s32 var_r0;

    temp_r4 = SBServerGetStringValue(*arg0, M2C_FIELD(data_0213e4bc, s32 *, 0x498), &sSbEmptyString);
    var_r0 = func_0206f8ac(temp_r4, SBServerGetStringValue(*arg1, M2C_FIELD(data_0213e4bc, s32 *, 0x498), &sSbEmptyString));
    if (M2C_FIELD(data_0213e4bc, s32 *, 0x49C) == 0) {
        var_r0 = -var_r0;
    }
    return var_r0;
}

void func_020619c0(void *arg0, s32 arg1, s32 arg2, u32 arg3) {
    s32 SBServerListCompareFloat(s32 *, s32 *);
    s32 func_02061958(s32 *, s32 *);
    M2C_UNK func_020489c4(s32, s32 (*)(s32 *, s32 *));
    extern void *data_0213e4bc;
    s32 (*var_r3)(s32 *, s32 *);

    switch (arg3) {
    case 0: var_r3 = func_020617bc; break;
    case 1: var_r3 = SBServerListCompareFloat; break;
    case 2: var_r3 = SBServerListCompareString; break;
    case 3: var_r3 = func_02061958; break;
    default: var_r3 = func_02061958; break;
    }
    M2C_FIELD(arg0, s32 *, 0x498) = arg2;
    M2C_FIELD(arg0, s32 *, 0x49C) = arg1;
    data_0213e4bc = arg0;
    func_020489c4(M2C_FIELD(arg0, s32 *, 4), var_r3);
}

void SBServerListAddServer(void *arg0, s32 arg1) {
    M2C_UNK Vector_AddItem(s32, s32 *);

    Vector_AddItem(M2C_FIELD(arg0, s32 *, 4), &arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(void *, s32, s32, s32), 0x488)(arg0, 0, arg1, M2C_FIELD(arg0, s32 *, 0x494));
}

s32 func_02061a74(void *a,s32 b){s32 Vector_GetCount(s32);s32 *Vector_GetItem();s32 n,i;n=Vector_GetCount(M2C_FIELD(a,s32 *,4));for(i=0;i<n;i++){if(b==*Vector_GetItem(M2C_FIELD(a,s32 *,4),i))return i;}return -1;}

s32 SBServerListFindByAddress(void *a,s32 b,s32 c){s32 Vector_GetCount(s32);s32 *Vector_GetItem();s32 SBServerGetIp(s32);s32 func_02060c70(s32);s32 n,p,i;n=Vector_GetCount(M2C_FIELD(a,s32 *,4));for(i=0;i<n;i++){p=*Vector_GetItem(M2C_FIELD(a,s32 *,4),i);if(b==SBServerGetIp(p)&&c==func_02060c70(p))return i;}return -1;}

void func_02061b38(void *a,s32 b){void func_02060cbc(s32,s32);s32 p=M2C_FIELD(a,s32 *,0x5d0);if(!p)func_02060cbc(b,0);else func_02060cbc(b,p);M2C_FIELD(a,s32 *,0x5d0)=b;}

void func_02061b6c(void *a,s32 b) {
s32 *Vector_GetItem();
void Vector_RemoveItem(s32,s32);
s32 p=*Vector_GetItem(M2C_FIELD(a,s32 *,4),b);
M2C_FIELD(a,M2C_UNK (**)(void *,s32,s32,s32),0x488)(a,2,p,M2C_FIELD(a,s32 *,0x494));
Vector_RemoveItem(M2C_FIELD(a,s32 *,4),b);
func_02061b38(a,p);
}

#pragma scheduling off
/* Number of servers found so far: the length of the list's server vector. */
s32 SBServerListGetServerCount(void *list) {
    s32 Vector_GetCount(s32);
    return Vector_GetCount(M2C_FIELD(list, s32 *, SB_SLIST_SERVERS));
}
#pragma scheduling reset
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
    s32 Vector_New(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_FIELD(arg0, s32 *, 4) = Vector_New(4, 0x64, 0);
    M2C_FIELD(arg0, s32 *, 0x5D0) = 0;
}

s32 StringIntern(s32 a,s32 b) {
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

void StringInternRelease(void *a,s32 b) {s32 func_020609bc(s32);s32 *func_02048ff8(s32,s32 *);void func_02048f54(s32,s32 *);void AssertFailed(void *,void *,void *,s32);s32 pair[2];s32 *p;pair[0]=b;p=func_02048ff8(func_020609bc((s32)a),pair);if(!p)AssertFailed(data_02100120,sSbFileName,data_02100094,0xf4);if(!p)return;if(--p[1])return;func_02048f54(func_020609bc((s32)a),pair);}

s32 BoundedStringLength(s8 *a,s32 b){s32 i;for(i=0;i<b;i++){if(!a[i])return i+1;}return -1;}

/* GameSpy SBServerListInit: initialise a server-list object with its game name,
   secret key and version strings plus the callback and instance, and clear the
   query state.  Does nothing when `force` is clear and the DNS/network layer is
   not ready, so a list is only created while networking is up. */
void SBServerListInit(void *list,void *gameName,void *secretKey,void *gameVersion,s32 queryPort,s32 force,s32 callback,s32 instance){
extern u8 sSbAssertSlistNotNull[],sSbServerListInitName[],sSbAssertCallbackNotNull[];extern s32 gDnsQueryState[];extern M2C_UNK sSbEmptyString;
void AssertFailed(void*,void*,void*,s32);s32 func_020609bc(s32);void StringCopy(void*,void*);void SBServerListSetError(void*,void*);s32 GetTickCountMs(void);void SetRandSeed(s32);void func_0204926c(void);
if(!list)AssertFailed(sSbAssertSlistNotNull,sSbFileName,sSbServerListInitName,0x11c);
if(!force && gDnsQueryState[0]!=1)return;
M2C_FIELD(list,s32*,SB_SLIST_STATE)=SB_SLIST_STATE_IDLE;func_02061c8c(list);func_020609bc((s32)list);
StringCopy((u8*)list+SB_SLIST_GAMENAME,gameName);StringCopy((u8*)list+SB_SLIST_SECRETKEY,secretKey);StringCopy((u8*)list+SB_SLIST_GAMEVERSION,gameVersion);
M2C_FIELD(list,s32*,SB_SLIST_CALLBACK)=callback;M2C_FIELD(list,s32*,0x48c)=0;
if(!callback)AssertFailed(sSbAssertCallbackNotNull,sSbFileName,sSbServerListInitName,0x132);
M2C_FIELD(list,s32*,SB_SLIST_INSTANCE)=instance;M2C_FIELD(list,void**,SB_SLIST_SORT_FIELD)=&sSbEmptyString;
M2C_FIELD(list,s32*,0x4a0)=0;M2C_FIELD(list,s32*,SB_SLIST_SOCKET)=-1;
M2C_FIELD(list,s32*,0x7c)=0;M2C_FIELD(list,s32*,0x80)=0;M2C_FIELD(list,s32*,8)=0;
M2C_FIELD(list,s32*,0x484)=-1;M2C_FIELD(list,s32*,0x480)=0;
M2C_FIELD(list,s32*,0x4a4)=0;M2C_FIELD(list,s32*,SB_SLIST_QUERY_PORT)=queryPort;
SBServerListSetError(list,&sSbEmptyString);M2C_FIELD(list,s32*,0x5cc)=0;
SetRandSeed(GetTickCountMs());func_0204926c();
}

/* Check the master server's reply sitting in the list's receive buffer: when it
 * starts with "Query Error: " the text after the prefix becomes the list's error
 * message and the query-error event is reported.  Either way the disconnect event
 * follows and the list is disconnected. */
s32 SBServerListCheckQueryError(void *list) {
    s32 StringLength(M2C_UNK *);
    s32 StringCompareN(void *, void *, u32);
    void SBServerListSetError(void *, void *);
    s32 SBServerListDisconnect(void *);
    s32 length;
    void *prefix;
    void *buffer;
    void *start;

    length = M2C_FIELD(list, s32 *, SB_SLIST_RECV_LENGTH);
    if (length > 0) {
        prefix = sSbQueryErrorPrefix;
        if ((u32)length > (u32)StringLength(prefix)) {
            buffer = M2C_FIELD(list, void **, SB_SLIST_RECV_BUFFER);
            start = sSbQueryErrorPrefix;
            if (!StringCompareN(buffer, start, StringLength(start))) {
                SBServerListSetError(list, (u8 *)buffer + StringLength(prefix));
                M2C_FIELD(list, M2C_UNK (**)(void *, s32, s32, s32), SB_SLIST_CALLBACK)(list, SB_LIST_EVENT_QUERY_ERROR, sSbNoServer[0], M2C_FIELD(list, s32 *, SB_SLIST_INSTANCE));
            }
        }
    }
    M2C_FIELD(list, M2C_UNK (**)(void *, s32, s32, s32), SB_SLIST_CALLBACK)(list, SB_LIST_EVENT_DISCONNECTED, sSbNoServer[0], M2C_FIELD(list, s32 *, SB_SLIST_INSTANCE));
    SBServerListDisconnect(list);
}

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
    extern M2C_UNK sSbEmptyString;
    M2C_UNK *var_r7;
    s32 temp_r5;

    var_r7 = arg1;
    if (var_r7 == NULL) {
        var_r7 = &sSbEmptyString;
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

void AppendInt32BE(u8 **a,s32 b,s32 *c,...) {u8 *p=*a;const u8 *q=(u8 *)&b;s32 x,y;x=q[0];y=q[1];p[0]=x;p[1]=y;x=q[2];y=q[3];p[2]=x;p[3]=y;*c+=4;*a+=4;}

void AppendBytes(s32 *a,M2C_UNK *b,s32 c,s32 *d) {
M2C_UNK MemCopy(s32,M2C_UNK *,s32);
MemCopy(*a,b,c);*d+=c;*a+=c;
}

/* Fill the 8-byte QR2 session key at +0x74 of the server list with printable
 * random characters, each shifted by one when its parity does not fit the running
 * parity of what was generated so far (the master server checks it). */
void GenerateSessionKey(void *arg0) {
 s32 Rand(void);
 s32 i, parity; s8 *p; s32 prev,cur;
 *(s8 *)((u8 *)arg0+0x74)=Rand()%93+33;   /* '!'..'}' */
 parity=0;
 i=1; do {
 p=(s8 *)((u32)arg0+i);
 prev=p[0x73]; cur=*((s8 *)arg0+0x74);
 { s32 below,over; if(prev<cur)below=1;else below=0; if(cur<79)over=1;else over=0; parity=(cur&1)^(parity^((i^prev)&1)); parity^=over; parity^=below; }
 p[0x74]=Rand()%93+33;
 if ((parity && !(p[0x74]&1)) || (!parity && (p[0x74]&1)==1)) p[0x74]++;
 i++; }while(i<8);
}

s32 func_02062324(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_02049810(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK SBServerListCheckQueryError(void *);
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
            SBServerListCheckQueryError(arg0);
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
extern u8 data_0210017c[],data_02100100[];extern M2C_UNK sSbEmptyString;
void AssertFailed(void*,void*,void*,s32);s32 StringLength(M2C_UNK*);s32 func_02049810(s32,s32,s32,s32);s32 gpiMalloc(s32);
u8 packet[768];s32 length;u8 *out;u16 beLength;u8 *lenBytes,*packetBytes;s32 err;
if(M2C_FIELD(slist,s32*,0)!=1)AssertFailed(data_0210017c,sSbFileName,data_02100100,0x20a);
if(!filter)filter=(s32)&sSbEmptyString;if(!fields)fields=(s32)&sSbEmptyString;
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
void func_0206262c(void *a) {void StringInternRelease(void *,s32);s32 i;for(i=0;i<M2C_FIELD(a,s32 *,0x480);i++)StringInternRelease(a,((s32 *)a)[i+33]);M2C_FIELD(a,s32 *,0x480)=0;}

void SBServerListFreeKeyList(void *a) {
s32 Vector_GetCount(s32);s32 *Vector_GetItem();void StringInternRelease(void *,s32);s32 Vector_Free();
s32 i; s32 p=M2C_FIELD(a,s32 *,8);
if(!p)return;
for(i=0;i<Vector_GetCount(M2C_FIELD(a,s32 *,8));i++)StringInternRelease(a,*Vector_GetItem(M2C_FIELD(a,s32 *,8),i));
Vector_Free(M2C_FIELD(a,s32 *,8));M2C_FIELD(a,s32 *,8)=0;
}

s32 SBServerListDisconnect(void *a) {
s32 gpiFree();s32 func_020496b8();
if(M2C_FIELD(a,s32 *,0x7c))gpiFree(M2C_FIELD(a,s32 *,0x7c));
M2C_FIELD(a,s32 *,0x7c)=0;M2C_FIELD(a,s32 *,0x80)=0;
if(M2C_FIELD(a,s32 *,0x4b0)!=-1)func_020496b8(M2C_FIELD(a,s32 *,0x4b0));
M2C_FIELD(a,s32 *,0x4b0)=-1;M2C_FIELD(a,s32 *,0)=1;
SBServerListFreeKeyList(a);M2C_FIELD(a,s32 *,0x484)=-1;func_0206262c(a);
}

void func_02062738(void *arg0) {
    M2C_UNK Vector_Free();
    M2C_UNK func_02060a20(void *);
    M2C_UNK func_02061c34(void *);
    M2C_UNK SBServerListDisconnect();
    SBServerListDisconnect();
    func_02061c34(arg0);
    func_02060a20(arg0);
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        Vector_Free();
    }
    M2C_FIELD(arg0, s32 *, 4) = 0;
}

