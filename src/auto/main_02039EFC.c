/* 24 functions from 0x02039EFC to 0x0203AEB4 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
typedef struct { u32 words[3]; } Record3A;
typedef struct { u32 words[8]; } Record39;

void NasConnectionResultCallback(M2C_UNK a,Record39 *b){
extern M2C_UNK gNasLogin,data_020fc8a8,NasLoginInfoCallback;
s32 SetGpiStatus(s32,s32,void *);s32 ReportNasError(void);s32 func_02038f88(void);s32 StartQr2Reporting(s32);
void func_02039db4(s32,s32);M2C_UNK gpiGetInfo(M2C_UNK,s32,M2C_UNK,M2C_UNK,M2C_UNK *,s32);
void *p;
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),s32 *,48)=0;
if(b->words[0]==0){
p=M2C_FIELD(&gNasLogin,void **,4);
M2C_FIELD(p,Record39 *,0x260)=*b;
if(M2C_FIELD(p,s32 *,4)==2){
if(M2C_FIELD(M2C_FIELD(p,void **,28),u32 *,28)==b->words[1]){
M2C_FIELD(p,s32 *,4)=5;
SetGpiStatus(1,(s32)&data_020fc8a8,0);
if(ReportNasError())return;
p=M2C_FIELD(&gNasLogin,void **,4);
M2C_FIELD(p,void (**)(s32,u32,s32),20)(0,b->words[1],M2C_FIELD(p,s32 *,24));
if(func_02038f88())return;
if(StartQr2Reporting(b->words[1]))return;
}else func_02039db4(6,-60000);
}else if(M2C_FIELD(p,s32 *,4)==3){
gpiGetInfo(a,b->words[1],0,0,&NasLoginInfoCallback,0);
if(ReportNasError())return;
}
}else ReportNasError();
}

void NasLoginRequestCallback(M2C_UNK arg0, M2C_UNK arg1) {
    void func_0203a04c(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK);
    void NasConnectionResultCallback(M2C_UNK, Record39 *);
    func_0203a04c(arg0, arg1, (M2C_UNK *)&NasConnectionResultCallback, 2);
}

void func_0203a04c(M2C_UNK a,M2C_UNK b,M2C_UNK *c,M2C_UNK d) {
extern M2C_UNK gNasLogin;
void StringCopy(void *,M2C_UNK);
u64 GetSystemTick(void);
void func_0204dbd4(s32,void *,void *,s32,s32,M2C_UNK *,s32);
s32 ReportNasError(void);
void *p;
StringCopy((u8 *)M2C_FIELD(&gNasLogin,void **,4)+0x48,a);
StringCopy((u8 *)M2C_FIELD(&gNasLogin,void **,4)+0x148,b);
p=M2C_FIELD(&gNasLogin,void **,4);
M2C_FIELD(p,u64 *,0x34)=GetSystemTick();
M2C_FIELD(p,s32 *,0x30)=1;
p=M2C_FIELD(&gNasLogin,void **,4);
func_0204dbd4(M2C_FIELD(p,s32 *,0),(u8 *)p+0x48,(u8 *)p+0x148,1,0,c,0);
if(ReportNasError()) return; M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),s32 *,4)=d;
}

/* Starts an online/NAS request for source `b`, remembering the completion callback `a`.
 * Builds the 72-byte request descriptor (the request name, the payload name at +0x34 and
 * the alloc/free callbacks at +0x40/+0x44), allocates the NAS connection block and hands
 * the descriptor to func_020328ac. */
void StartNasRequest(void *a,s32 b){
extern M2C_UNK gNasLogin;
u64 GetSystemTick(void); s32 func_02032370(void *); s32 func_02032358(void *); s32 func_020322ec(void *); void func_02032228(void *); void FormatNasId(void *,s32,void *); void func_02031dfc(void *,u32); s32 Utf16StringLength(s32); void MI_CpuCopy8(s32,void *,s32);void StringCopy(void *,M2C_UNK); s32 func_020376a4(s32,s32,s32); void HeapAlloc(void);void HeapFree(M2C_UNK,M2C_UNK,M2C_UNK);void func_020328ac(void *,s32);void MI_CpuFill8(void *,s32,s32);
u8 buf[72];void *p; s32 n;
MI_CpuFill8(buf,0,72);M2C_FIELD(&gNasLogin,void **,8)=a;M2C_FIELD(&gNasLogin,s32 *,0)=b;
if(func_02032370(M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),void **,28))){
p=M2C_FIELD(&gNasLogin,void **,4);FormatNasId(M2C_FIELD(p,u8 **,28)+16,M2C_FIELD(M2C_FIELD(p,void **,28),s32 *,36),(u8 *)p+0x248);
}else{
if(!func_02032358((u8 *)M2C_FIELD(&gNasLogin,void **,4)+0x3c)){
if(func_020322ec(M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),u8 **,28)+4)){
p=M2C_FIELD(&gNasLogin,void **,4);M2C_FIELD(p,Record3A *,0x3c)=M2C_FIELD(M2C_FIELD(p,void **,28),Record3A *,4);
}else func_02032228((u8 *)M2C_FIELD(&gNasLogin,void **,4)+0x3c);
}else{
u64 t=GetSystemTick();func_02031dfc((u8 *)M2C_FIELD(&gNasLogin,void **,4)+0x3c,(u32)((t*0x5d588b656c078965ULL+0x269ec3)>>32));
}
p=M2C_FIELD(&gNasLogin,void **,4);FormatNasId((u8 *)p+0x3c,M2C_FIELD(p,s32 *,12),(u8 *)p+0x248);
}
n=Utf16StringLength(M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),s32 *,16));
MI_CpuCopy8(M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),s32 *,16),buf,n*2+2);
StringCopy(buf+0x34,(s32)((u8 *)M2C_FIELD(&gNasLogin,void **,4)+0x251));
M2C_FIELD(buf,u32 *,64)=(u32)HeapAlloc;M2C_FIELD(buf,u32 *,68)=(u32)HeapFree;n=func_020376a4(0,0x1c14,4);
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),s32 *,36)=n;
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,4),u64 *,40)=GetSystemTick();
func_020328ac(buf,n);
}

#pragma opt_strength_reduction off
void func_0203a2b4(void) {
    extern M2C_UNK gNasLogin;
    s32 func_02032b98(void);
    void func_02032be4(void *);
    void func_02032b10(void);
    u64 GetSystemTick(void);
    u64 func_02072088(u64, u64);
    void StringCopy(void *, M2C_UNK);
    void HeapFree(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02032370(void *);
    void func_0203a04c(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK);
    void MI_CpuFill8(void *, s32, s32);
    s32 Utf16StringLength(s32);
    void MI_CpuCopy8(s32, void *, s32);
    void func_020328ac(void *, M2C_UNK);
    void func_02039db4(s32, s32);
    void HeapAlloc(void);
    void NasConnectionResultCallback(M2C_UNK, Record39 *);

    u8 buf[0x3D0];
    s32 n, r;
    void *context;
    u64 now, stored, diff, q;

    r = func_02032b98();
    if (r == 0x15) {
        func_02032be4(buf + 0x20C);
        StringCopy((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x48, (M2C_UNK)(buf + 0x200 + 0x56));
        StringCopy((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x148, (M2C_UNK)(buf + 0x300 + 0x83));
        func_02032b10();
        HeapFree(0, M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), M2C_UNK *, 0x24), 0);
        M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), M2C_UNK *, 0x24) = 0;
        if (func_02032370(M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), void **, 0x1C))) {
            M2C_FIELD(&gNasLogin, void (**)(void *, void *, s32), 8)(
                (void *)((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x48),
                (void *)((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x148),
                M2C_FIELD(&gNasLogin,s32 *,0));
        } else {
            func_0203a04c(
                (M2C_UNK)((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x48),
                (M2C_UNK)((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x148),
                (M2C_UNK *)NasConnectionResultCallback,
                3);
        }
    } else {
        r = func_02032b98();
        if (r == 0) {
            return;
        }
        now = GetSystemTick();
        stored = M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), u64 *, 0x28);
        diff = now - stored;
        q = func_02072088(diff << 6, 0x82EAULL);
        if (q > 0x2710ULL) {
            func_02032be4(buf + 0x48);
            func_02032b10();
            HeapFree(0, M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), M2C_UNK *, 0x24), 0);
            M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), M2C_UNK *, 0x24) = 0;
            func_02039db4(2, *(s32 *)(buf + 0x48));
        } else {
            func_02032b10();
            MI_CpuFill8(buf, 0, 0x48);
            n = Utf16StringLength(M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), s32 *, 0x10));
            MI_CpuCopy8(M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), s32 *, 0x10), buf, n * 2 + 2);
            StringCopy(buf + 0x34, (M2C_UNK)((u8 *)M2C_FIELD(&gNasLogin, void **, 4) + 0x251));
            *(M2C_UNK *)(buf + 0x40) = (M2C_UNK)HeapAlloc;
            context = M2C_FIELD(&gNasLogin,void **,4);
            *(M2C_UNK *)(buf + 0x44) = (M2C_UNK)HeapFree;
            func_020328ac(buf, M2C_FIELD(context, M2C_UNK *, 0x24));
        }
    }
}
#pragma opt_strength_reduction reset
/* Completion callback for the gpi profile fetch of the NAS login.  In state 3
 * it stores the login id in the profile's last-name field and fetches the
 * profile again; in state 4 it verifies the fetched id, records the login key
 * in the session profile and continues the login (state 2).  An id that is
 * already set belongs to an earlier login, so the connection is dropped and
 * the NAS request restarted. */
void NasLoginInfoCallback(s32 conn,void *info) {
extern M2C_UNK gNasLogin;
void FormatNasId(void *,s32,void *); M2C_UNK gpiGetInfo(M2C_UNK,s32,M2C_UNK,M2C_UNK,M2C_UNK *,s32); void gpiSetInfoString(s32,s32,void *); s32 ReportNasError(void); void gpiCloseConnection(s32); void StartNasRequest(void *,s32); s32 StringCompare(s32,M2C_UNK *); void SetNasProfileKey(void *,void *,s32);
u8 nasId[21],expectedId[21],keyText[21]; void *ctx;
if(M2C_FIELD(info,s32 *,0))return;
ctx=M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT);
if(M2C_FIELD(ctx,s32 *,NAS_LOGIN_STATE)==NAS_STATE_GET_PROFILE){
if(M2C_FIELD(info,s8 *,GPI_INFO_LASTNAME)==0){
FormatNasId(M2C_FIELD(ctx,u8 **,NAS_LOGIN_SESSION)+4,M2C_FIELD(ctx,s32 *,NAS_LOGIN_KEY_TYPE),nasId);
gpiSetInfoString(conn,GPI_INFO_FIELD_LASTNAME,nasId);if(ReportNasError())return;
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT),s32 *,NAS_LOGIN_STATE)=NAS_STATE_VERIFY_PROFILE;
gpiGetInfo(conn,M2C_FIELD(info,s32 *,GPI_INFO_PROFILE_ID),0,0,(M2C_UNK *)NasLoginInfoCallback,0);if(ReportNasError())return;
}else{
gpiCloseConnection(conn);StartNasRequest((void *)NasLoginRequestCallback,0);
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT),s32 *,NAS_LOGIN_STATE)=NAS_STATE_REQUESTING;
}
}else if(M2C_FIELD(ctx,s32 *,NAS_LOGIN_STATE)==NAS_STATE_VERIFY_PROFILE){
FormatNasId(M2C_FIELD(ctx,u8 **,NAS_LOGIN_SESSION)+4,M2C_FIELD(ctx,s32 *,NAS_LOGIN_KEY_TYPE),expectedId);
if(StringCompare((s32)((u8 *)info+GPI_INFO_LASTNAME),(M2C_UNK *)expectedId)==0){
ctx=M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT);FormatNasId((u8 *)ctx+NAS_LOGIN_KEY,M2C_FIELD(ctx,s32 *,NAS_LOGIN_KEY_TYPE),keyText);
ctx=M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT);SetNasProfileKey(M2C_FIELD(ctx,void **,NAS_LOGIN_SESSION),(u8 *)ctx+NAS_LOGIN_KEY,M2C_FIELD(info,s32 *,GPI_INFO_PROFILE_ID));
M2C_FIELD(M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT),s32 *,NAS_LOGIN_STATE)=NAS_STATE_CONNECTED;
((void (*)(s32,Record39 *,s32))NasConnectionResultCallback)(conn,(Record39 *)((u8 *)M2C_FIELD(&gNasLogin,void **,NAS_LOGIN_CONTEXT)+NAS_LOGIN_CONNECT_RESULT),0);
}else{gpiGetInfo(conn,M2C_FIELD(info,s32 *,GPI_INFO_PROFILE_ID),0,0,(M2C_UNK *)NasLoginInfoCallback,0);if(ReportNasError())return;}
}
}

s32 func_0203a660(void) {
    extern M2C_UNK gNasLogin;
    if ((M2C_FIELD(&gNasLogin, void **, 4) != NULL) && (M2C_FIELD(M2C_FIELD(&gNasLogin, void **, 4), s32 *, 4) == 5)) {
        return 1;
    }
    return 0;
}

void func_0203a68c(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0203a6a4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    func_0203a6a4(arg0, 0, 0, arg1);
}

s32 func_0203a6a4(M2C_UNK a,M2C_UNK b,M2C_UNK c,M2C_UNK d) {
extern u8 data_020fc8ac[],data_020fc8b0[];
s32 func_0203b63c(M2C_UNK,void *);
s32 ExtractKeyValue(void *,void *,void *,s32);
s32 func_0206abd8(void *,void *,s32);
void StringCopy(void *,M2C_UNK);
u32 buf[132];u32 temp;
if(func_0203b63c(a,buf)){
if(buf[1]==6){
if(b){if(ExtractKeyValue(data_020fc8ac,&temp,buf+2,47)<=0)*(u8 *)b=0;else *(u8 *)b=func_0206abd8(&temp,0,10);}
if(c){if(ExtractKeyValue(data_020fc8b0,&temp,buf+2,47)<=0)*(u8 *)c=0;else *(u8 *)c=func_0206abd8(&temp,0,10);}
}else{if(b)*(u8 *)b=0;if(c)*(u8 *)c=0;}
if(d)StringCopy((void *)d,(M2C_UNK)(buf+66));
return (u8)buf[1];
}
if(b)*(u8 *)b=0;if(c)*(u8 *)c=0;return 0;
}

s32 func_0203a7c0(M2C_UNK a,M2C_UNK b,M2C_UNK c,s32 d,s32 *e) {
s32 func_0203a6a4(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK);
s32 StringLength(void *);
s32 func_0203739c(void *,s32,s32,s32);
u8 buf[256];s32 n,v;
n=func_0203a6a4(a,b,c,(s32)buf);
if(!n){*e=-1;return n;}
*e=func_0203739c(buf,StringLength(buf),0,0);
if(!d || (v=*e)==-1)return n;func_0203739c(buf,StringLength(buf),d,v);
return n;
}

s32 func_0203a850(s32 a,s32 b) {
extern M2C_UNK gMatchSessionMgr;
s32 func_02037214(s32,s32,void *,s32);
s32 SetGpiStatus(s32,s32,void *);
u8 buf[256];s32 n;
if(!M2C_FIELD(&gMatchSessionMgr,void **,8)||!func_0203a660())return 0;
n=func_02037214(a,b,buf,255);
if(n==-1)return 0;
buf[n]=0;
return SetGpiStatus(-1,0,buf)==0;
}

s32 func_0203a8dc(void) {
extern M2C_UNK gMatchSessionMgr;
void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(p && (u8)(M2C_FIELD(p,u8 *,0x1e)+255)<=1)return 0;
return 1;
}

void func_0203a910(void *a) {
extern M2C_UNK gMatchSessionMgr;
s32 GetLocalPlayerInfo(void);s32 GetPlayerRecordId(s32,void *);
s32 func_0204e364(s32,s32);void func_0204e3b0(s32,s32);void MI_CpuFill8(void *,s32,s32);
s32 n;
if(!M2C_FIELD(&gMatchSessionMgr,void **,8)||!func_0203a660()||!GetLocalPlayerInfo())goto clear;
n=GetPlayerRecordId(GetLocalPlayerInfo(),a);
if(!n || n==-1)goto clear;
if(func_0204e364(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,4),n))
func_0204e3b0(M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,4),n);
clear: MI_CpuFill8(a,0,12);
}

s32 func_0203a9a4(s32 a,s32 b) {
extern M2C_UNK gMatchSessionMgr;
if(!M2C_FIELD(&gMatchSessionMgr,void **,8))return 0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,0x44)=a;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,0x48)=b;
return 1;
}

void func_0203a9d0(void) {
    M2C_UNK func_0203739c();
    func_0203739c();
}

void func_0203a9dc(void *a,s32 b,s32 c,s32 d,s32 e) {
 extern M2C_UNK gMatchSessionMgr;
 void *p;
 M2C_FIELD(&gMatchSessionMgr,void**,8)=a;
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,0)=0;
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,4)=b;
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,8)=0;
 p=M2C_FIELD(&gMatchSessionMgr,void**,8);
 M2C_FIELD(p,s32*,12)=0;M2C_FIELD(p,s32*,16)=0;M2C_FIELD(p,s32*,20)=e;
 M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,24)=d;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),u8*,28)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),u8*,29)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),u8*,30)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),u8*,31)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,32)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,36)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,40)=c;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,44)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,48)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,52)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,56)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,60)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,64)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,68)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,72)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,76)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,80)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,84)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void**,8),s32*,88)=0;
}

/* Advance the registered communication session by one step. */
void func_0203aabc(void) {
extern M2C_UNK gMatchSessionMgr;
s32 HasNetError(void *); s32 func_0203b09c(void); s32 func_0203bcf8(s32); s32 func_02058c84(void);
void gpiInfoReadSocket(void); void gpiInfoCloseSocket(void); void SyncSessionPlayerConnections(s32,s32); void func_0203b3c4(void);
void *ctx,*child; u32 status;
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(!ctx)return;
if(HasNetError(ctx))return;
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(!M2C_FIELD(ctx,s32 *,0x18)){
child=M2C_FIELD(ctx,void **,4);
if(child && M2C_FIELD(child,s32 *,0))func_0203b09c();
return;
}
if(func_0203bcf8(M2C_FIELD(ctx,s32 *,0x18)) || func_02058c84()){
M2C_FIELD(&gMatchSessionMgr,s32 *,0)=1;
M2C_FIELD(&gMatchSessionMgr,s32 *,12)=0;
gpiInfoReadSocket();
M2C_FIELD(&gMatchSessionMgr,s32 *,0)=0;
if(M2C_FIELD(&gMatchSessionMgr,s32 *,12)==1){
M2C_FIELD(&gMatchSessionMgr,s32 *,12)=0;gpiInfoCloseSocket();
}}
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
child=M2C_FIELD(ctx,void **,4);
if(child && M2C_FIELD(child,s32 *,0)){
if(func_0203b09c())return;
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(!M2C_FIELD(ctx,s32 *,0))return;
if(M2C_FIELD(ctx,s32 *,0x18) && (status=M2C_FIELD(ctx,u8 *,0x1e))!=3){
if(M2C_FIELD(ctx,u32 *,8)>7){
if(status<=1)SyncSessionPlayerConnections(M2C_FIELD(ctx,s32 *,0x18),M2C_FIELD(ctx,s32 *,0x14));
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(M2C_FIELD(ctx,u8 *,0x1c)>=M2C_FIELD(ctx,s32 *,0x14)){
M2C_FIELD(ctx,u8 *,0x1e)=3;
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
M2C_FIELD(ctx,u8 *,0x1f)++;
}
}}}
ctx=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(M2C_FIELD(ctx,u8 *,0x1f)<2)return;
M2C_FIELD(ctx,u8 *,0x1f)=0;
func_0203b3c4();
}

void func_0203ac20(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h) {
extern M2C_UNK gMatchSessionMgr;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,44)=c;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,48)=d;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,52)=e;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,56)=f;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,60)=g;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,64)=h;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,29)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,30)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,31)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),u8 *,28)=0;
M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),s32 *,0)=1;
{void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);if(!M2C_FIELD(p,s32 *,24))M2C_FIELD(p,u8 *,31)++;}
{void *p=M2C_FIELD(&gMatchSessionMgr,void **,8);M2C_FIELD(p,u8 *,31)++;}
}

void func_0203accc(s32 a,s32 b) {
extern M2C_UNK gMatchSessionMgr;void SetNetError(s32,s32);void func_0203b128(void);
void *p;
if(!M2C_FIELD(&gMatchSessionMgr,void **,8)||!a)return;
SetNetError(a,b);
p=M2C_FIELD(&gMatchSessionMgr,void **,8);
if(M2C_FIELD(p,s32 *,0)!=0 && M2C_FIELD(p,s32 *,0)!=2) M2C_FIELD(p,void (**)(s32,u8,s32),44)(a,M2C_FIELD(p,u8 *,29),M2C_FIELD(p,s32 *,48));
func_0203b128();
}

void func_0203ad24(M2C_UNK a,void *b) {
extern M2C_UNK gMatchSessionMgr;
extern M2C_UNK func_0203b9a8;
M2C_UNK gpiGetInfo(M2C_UNK,s32,M2C_UNK,M2C_UNK,M2C_UNK *,s32);
if(!M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,0x18))return;
gpiGetInfo(a,M2C_FIELD(b,s32 *,0),0,0,&func_0203b9a8,0);
}

s32 func_0203ad70(M2C_UNK arg0, void *arg1) {
    M2C_UNK gpiGetInfo(M2C_UNK, s32, M2C_UNK, M2C_UNK, M2C_UNK *, s32);
    s32 StringCompare(s32, M2C_UNK *);
    extern M2C_UNK data_020fc8b4;
    extern M2C_UNK HandleGpiPlayerInfo;
    if (StringCompare(M2C_FIELD(arg1, s32 *, 8), &data_020fc8b4) != 0) {
        return 0;
    }
    gpiGetInfo(arg0, M2C_FIELD(arg1, s32 *, 0), 0, 0, &HandleGpiPlayerInfo, 0);
    return 1;
}

void func_0203adcc(s32 a,void *b) {
extern M2C_UNK gMatchSessionMgr;
s32 func_0203aeb4(s32);
void func_0204e1b4(s32,s32,void *);
u32 out[66]; u32 buf[66];s32 n;void *p;
if(!M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,0x34))return;
n=func_0203aeb4(M2C_FIELD(b,s32 *,0));
if(n==-1)return;
func_0204e1b4(a,M2C_FIELD(b,s32 *,8),buf);
p=M2C_FIELD(&gMatchSessionMgr,void **,8);
M2C_FIELD(p,void (**)(s32,u32,void *,s32),0x34)(n,buf[1]&255,out,M2C_FIELD(p,s32 *,0x38));
}

s32 func_0203ae50(void) {
    extern M2C_UNK gMatchSessionMgr;
    if (M2C_FIELD(&gMatchSessionMgr, void **, 8) != NULL) {
        return M2C_FIELD(M2C_FIELD(&gMatchSessionMgr, void **, 8), s32 *, 0x14);
    }
    return 0;
}

s32 GetSessionPlayerId(s32 a) {
extern M2C_UNK gMatchSessionMgr;
s32 GetLocalPlayerInfo(void);
s32 GetPlayerRecordId(s32,void *);
void *p,*v;
p=M2C_FIELD(M2C_FIELD(&gMatchSessionMgr,void **,8),void **,0x18);
if(!p)return 0;
v=(void *)GetPlayerRecordId(GetLocalPlayerInfo(),(u8 *)p+a*12);
if(v==0||v==(void *)-1)return 0;
return (s32)v;
}

