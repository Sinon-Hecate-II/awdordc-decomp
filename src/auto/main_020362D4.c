/* 11 functions from 0x020362D4 to 0x02037214 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
extern void *gWfcMatchSession;
extern s32 gNasServer;
extern s32 data_0213d13c[];
extern s32 gSocketManager[];
extern u8 sWfcMatchPath[], sWfcProfilePath[], sWfcParamRegion[], sWfcParamEncoding[], sWfcEncodingUtf16[], sWfcParamType[], sWfcTypeQuery[], sWfcParamWords[];

/* Open the HTTP connection to the WFC server whose address is at gWfcNet+8:
 * allocate and clear the connection object, create a non-blocking TCP socket,
 * fill in the server address and port, and start the connect. arg0 is the
 * give-up timeout in ms (0 or less uses the default). Returns 0 if the socket
 * could not be set up, 1 once the connection attempt is under way. */
s32 OpenWfcHttpConnection(s32 timeout){
M2C_UNK HeapAlloc();void MI_CpuFill8(void *,s32,s32);s32 func_02021500(s32,s32,s32);s32 func_020219e8(s32,s32,s32);s32 func_02021558(s32,void *);s32 func_02021750(s32,s32);s32 func_0202175c(s32);M2C_UNK HeapFree();u64 GetSystemTick(void);extern M2C_UNK gWfcNet;
s32 r;u32 ip;
if(M2C_FIELD(&gWfcNet,void **,16)||!M2C_FIELD(&gWfcNet,u32 *,8))return 0;
M2C_FIELD(&gWfcNet,void **,16)=HeapAlloc(0,72);
if(!M2C_FIELD(&gWfcNet,void **,16))return 0;
MI_CpuFill8(M2C_FIELD(&gWfcNet,void **,16),0,72);
((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->socket=-1;
((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->socket=func_02021500(2,1,0);
if(((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->socket<0){HeapFree(0,M2C_FIELD(&gWfcNet,void **,16),0);M2C_FIELD(&gWfcNet,void **,16)=0;return 0;}
r=func_020219e8(((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->socket,3,0);
func_020219e8(((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->socket,4,r|4);
((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->addrLen=8;
((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->addrFamily=2;
((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->port=0x5000;
ip=M2C_FIELD(&gWfcNet,u32 *,8);
((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->addr=((ip>>24)&255)|((ip>>8)&0xff00)|((ip<<8)&0xff0000)|((ip<<24)&0xff000000);
r=func_02021558(((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->socket,M2C_FIELD(&gWfcNet,void **,16)+4);
if(r<0&&r!=-26){
((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->result=3;
((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->state=3;
func_02021750(((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->socket,2);func_0202175c(((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->socket);return 1;}
((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->state=1;
if(timeout>0)((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->deadline=GetSystemTick()+((u64)((s64)timeout*0x82ea)>>6);
else ((WfcHttpConnection *)M2C_FIELD(&gWfcNet,void **,16))->deadline=GetSystemTick()+0x17f898;
return 1;}

/* Advance the WFC HTTP connection test: time out a stalled attempt, poll the
   connect, send the request or read the status line, and free the connection
   when it is done. Returns 0 while running, the connection's result when it is
   freed, or 4 when there is no connection to update. */
s32 UpdateWfcHttpConnection(void) {
    u64 GetSystemTick(void);
    s32 func_02021558(M2C_UNK, void *);
    M2C_UNK func_02021750(s32, s32);
    M2C_UNK func_0202175c(s32);
    void SendWfcHttpRequest(void);
    void ReceiveWfcHttpResponse(void);
    M2C_UNK HeapFree(s32, M2C_UNK *, s32);
    extern M2C_UNK gWfcNet;

    WfcHttpConnection *p;
    s32 r;

    p = M2C_FIELD(&gWfcNet, WfcHttpConnection **, 0x10);
    if (p == 0 || p->state == WFC_HTTP_IDLE) {
        return 4;
    }

    if (p->result == 0) {
        if (p->deadline != 0 && p->deadline < GetSystemTick()) {
            p->result = 2;
            ((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->state = WFC_HTTP_DONE;
            func_02021750(((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->socket, 2);
            func_0202175c(((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->socket);
        }
    }

    switch (((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->state) {
    case WFC_HTTP_CONNECTING:
        r = func_02021558(((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->socket,
                          (char *)M2C_FIELD(&gWfcNet, void **, 0x10) + 4);
        if (r < 0 && r != -26) {
            ((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->result = 3;
            ((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->state = WFC_HTTP_DONE;
            func_02021750(((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->socket, 2);
            func_0202175c(((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->socket);
            return 0;
        }
        SendWfcHttpRequest();
        return 0;
    case WFC_HTTP_RECEIVING:
        ReceiveWfcHttpResponse();
        return 0;
    case WFC_HTTP_DONE:
        r = ((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->result;
        HeapFree(0, M2C_FIELD(&gWfcNet, void **, 0x10), 0);
        M2C_FIELD(&gWfcNet, void **, 0x10) = 0;
        return r;
    default:
        ((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->result = 3;
        ((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->state = WFC_HTTP_DONE;
        func_02021750(((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->socket, 2);
        func_0202175c(((WfcHttpConnection *)M2C_FIELD(&gWfcNet, void **, 0x10))->socket);
        return 0;
    }
}

void SendWfcHttpRequest(void) {
 s32 func_02021688(s32,M2C_UNK *,s32); M2C_UNK func_02021750(s32,s32); M2C_UNK func_0202175c(s32); s32 StringLength(M2C_UNK *);
 extern M2C_UNK sWfcConnTestRequest; extern M2C_UNK gWfcNet;
 s32 x;
 x=StringLength(&sWfcConnTestRequest);
 x=func_02021688(M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,0),&sWfcConnTestRequest,x);
 if(x==-56) return;
 if(x<=0) {
 M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,60)=2;
 M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,56)=3;
 func_02021750(M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,0),2);
 func_0202175c(M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,0)); return;
 }
 M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,56)=2;
 M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,52)=0;
}

void ReceiveWfcHttpResponse(void) {
s32 func_020215b4(s32,void *,s32);M2C_UNK func_02021750(s32,s32);M2C_UNK func_0202175c(s32);s32 StringCompareN(void *,void *,s32);
extern M2C_UNK gWfcNet,sWfcHttpOkStatus;
s32 r,i;void *p; s8 *scan;
p=M2C_FIELD(&gWfcNet,void **,16);
r=func_020215b4(M2C_FIELD(p,s32 *,0),p+20+M2C_FIELD(p,s32 *,52),32-M2C_FIELD(p,s32 *,52));
if(r==-6)return;
if(r>=0) {
M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,52)+=r;
if(r==0||M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,52)>=32){
p=M2C_FIELD(&gWfcNet,void **,16);
for(i=0,scan=p;scan[20]!=32&&i<32;scan++,i++);
i++;
if(i>=32)M2C_FIELD(p,s32 *,60)=2;
else if(StringCompareN(p+20+i,&sWfcHttpOkStatus,3)!=0)M2C_FIELD(p,s32 *,60)=2;
else M2C_FIELD(p,s32 *,60)=1;
M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,56)=3;
func_02021750(M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,0),2);
func_0202175c(M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,0));
}
}else{
M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,60)=2;
M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,56)=3;
func_02021750(M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,0),2);
func_0202175c(M2C_FIELD(M2C_FIELD(&gWfcNet,void **,16),s32 *,0));
}
}

/* Parses the server's RFC-1123 Date header and records the local clock, the
 * server time and their difference in the server-time sync record. */
s32 ParseHttpDate(const char *text){
s32 StringLength(M2C_UNK *);s32 GetLocalTime(void *,void *);s64 MakeTime(void *,void *);void StringCopy(void *,const char *);s32 ParseInt();s32 StringCompare(void *,void *);
extern M2C_UNK gHttpDateTemplate,gServerTimeSync;extern s32 gErrno;extern char *gMonthNames[];
s32 date[4],time[3];char buf[32];s64 now,serverTime;s32 i,n;
n=StringLength((M2C_UNK *)text);
if(n!=StringLength(&gHttpDateTemplate)||text[HTTP_DATE_DAY_SPACE]!=32||text[HTTP_DATE_MONTH_SPACE]!=32||text[HTTP_DATE_YEAR_SPACE]!=32||text[HTTP_DATE_HOUR_COLON]!=58||text[HTTP_DATE_MIN_COLON]!=58||text[HTTP_DATE_TZ_SPACE]!=32)goto fail;
if(GetLocalTime(date,time))goto fail;
now=MakeTime(date,time);if(now==-1)goto fail;
StringCopy(buf,text);buf[7]=0;buf[11]=0;buf[16]=0;buf[19]=0;buf[22]=0;buf[25]=0;
gErrno=0;date[0]=ParseInt(buf+12);if(gErrno==34)goto fail;date[0]-=2000;
date[1]=13;for(i=0;i<12;i++){if(!StringCompare(gMonthNames[i],buf+8)){date[1]=i+1;break;}}
if((u32)date[1]>12)goto fail;
gErrno=0;date[2]=ParseInt(buf+5);if(gErrno==34)goto fail;
gErrno=0;time[0]=ParseInt(buf+17);if(gErrno==34)goto fail;
gErrno=0;time[1]=ParseInt(buf+20);if(gErrno==34)goto fail;
gErrno=0;time[2]=ParseInt(buf+23);if(gErrno==34)goto fail;
serverTime=MakeTime(date,time);if(serverTime==-1)goto fail;
M2C_FIELD(&gServerTimeSync,s64 *,SERVER_TIME_OFFSET)=now-serverTime;M2C_FIELD(&gServerTimeSync,s64 *,SERVER_TIME_NOW)=now;M2C_FIELD(&gServerTimeSync,s32 *,SERVER_TIME_VALID)=1;return 1;
fail:return 0;
}

/* Creates a Nintendo WFC match: allocates and configures the session, loads the
 * profile, then uploads the region, type and tab-separated player-name
 * parameters. Returns 1 on success, 0 on failure. */
M2C_UNK CreateWfcMatch(s32 names,s32 count,s32 typeValue,s32 timeout,s32 flagsOut,s32 countOut,s8 *region) {
 s32 func_0206cd90();void func_0206cdac();void MI_CpuFill8();M2C_UNK HeapAlloc();M2C_UNK HeapFree();void func_02068d18();void *StringFind();void MI_CpuCopy8();s32 func_02033ccc();s32 func_020336c0();s32 func_02033988();s32 func_020346d0();s32 func_020347dc();s32 func_02033de8();s32 func_02006028();void func_02033e80();M2C_UNK func_02034480(void *);void func_020371f4();void func_02037204();
 s32 options[7];u8 work[0x94];s32 totalLen,i,pos,n;u16 *namesBuf=0;void *p;
 if(!names||count<=0||count>50||!flagsOut||!countOut)return 0;
 totalLen=0;for(i=0;i<count;i++)totalLen+=func_0206cd90(((s32 *)names)[i])+1;
 if(totalLen-1<=0||totalLen-1>500)return 0;
 if(gWfcMatchSession)return 0;
 MI_CpuFill8(flagsOut,0,count);
 gWfcMatchSession=(void *)HeapAlloc(0,0x1d28);
 if(!gWfcMatchSession)goto fail;
 MI_CpuFill8(gWfcMatchSession,0,0x1d28);
 M2C_FIELD(gWfcMatchSession,s32 *,0x1c14)=0;
 MI_CpuFill8(work,0,0x94);
 M2C_FIELD(gWfcMatchSession,s32 *,0x1d1c)=flagsOut;
 M2C_FIELD(gWfcMatchSession,s32 *,0x1d20)=countOut;
 M2C_FIELD(gWfcMatchSession,s32 *,0x1d24)=count;
 func_02068d18(gWfcMatchSession+0x1c18,gNasServer,256);
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
 namesBuf=(u16 *)HeapAlloc(0,totalLen*2);
 if(!namesBuf)goto fail;
 pos=0;for(i=0;i<count;i++){func_0206cdac(namesBuf+pos,((s32 *)names)[i]);n=pos+func_0206cd90(((s32 *)names)[i]);if(n>=totalLen-1)break;namesBuf[n]=9;pos=n+1;}
 if(func_020346d0(gWfcMatchSession,sWfcParamWords,namesBuf,(totalLen-1)*2))goto fail;
 HeapFree(0,namesBuf,0);namesBuf=0;
 if(func_02033de8(gWfcMatchSession))goto fail;
 n=func_02006028(gSocketManager[1]);
 func_02033e80(gWfcMatchSession,n-1);
 if(M2C_FIELD(gWfcMatchSession,s32 *,0x1ba4))return 1;
fail:
 if(namesBuf)HeapFree(0,namesBuf,0);
 if(gWfcMatchSession){if(M2C_FIELD(gWfcMatchSession,s32 *,0x1c14)==1)func_02034480(gWfcMatchSession);HeapFree(0,gWfcMatchSession,0);gWfcMatchSession=0;}
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
    s32 ProcessWfcMatchResponse();
    M2C_UNK SetNetError(M2C_UNK, s32);
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
        if (ProcessWfcMatchResponse() == 0) {
            var_r4 = 3;
        } else {
            var_r4 = 2;
        }
        break;
    case 2:
        SetNetError(8, 0xFFFF347C - var_r2);
        var_r4 = 3;
        break;
    case 3:
    case 4:
    case 6:
        SetNetError(0x13, 0xFFFF7F0E);
        var_r4 = 3;
        break;
    default:
    case 0:
    case 1:
    case 5:
    case 7:
        SetNetError(0x13, 0xFFFF7EFA);
        var_r4 = 3;
        break;
    }
    func_02034480(gWfcMatchSession);
    HeapFree(0, gWfcMatchSession, 0);
    gWfcMatchSession = 0;
    return var_r4;
}

/* Processes the match server's HTTP response: parses the Date header, checks the
 * "httpresult" code, then reads the "prwords" player-word string and turns every
 * '0'/'1' into a per-player flag, counting the set ones.  Returns 1 on success, or
 * 0 after SetNetError when the response is bad. */
s32 ProcessWfcMatchResponse(void) {
s32 ParseHttpResponse(void *,s32); s32 FindHttpHeader(void *,void *); s32 ParseHttpDate(); s32 ParseInt(); s32 ReadHttpHeader(void *,void *,void *,s32); s32 SetNetError(s32,s32);
extern void *gWfcMatchSession; extern s32 gErrno;
extern u8 sWfcHeaderDate[],sWfcHeaderHttpResult[],sWfcHeaderReturnCode[],sWfcHeaderPlayerWords[];
s32 value; s8 buf[51]; void *p=gWfcMatchSession; s32 r,i;
if(ParseHttpResponse(p,0)) {
if(FindHttpHeader(p,sWfcHeaderDate))ParseHttpDate();
if(FindHttpHeader(p,sWfcHeaderHttpResult)){
r=ParseInt();
if(gErrno!=34 && r==200 && ReadHttpHeader(p,sWfcHeaderReturnCode,&value,4)>0){
r=ParseInt(&value);
if(gErrno!=34){
if(r==1)goto error;
if(r<100)goto readbuf;
if(r==100)goto readbuf;
error:
SetNetError(18,-33000-r);return 0;
readbuf:
ReadHttpHeader(p,sWfcHeaderPlayerWords,buf,51);
process:
*M2C_FIELD(gWfcMatchSession,s32 **,WFC_MATCH_FLAG_COUNT)=0;
for(i=0;i<M2C_FIELD(gWfcMatchSession,s32 *,WFC_MATCH_PLAYER_COUNT);i++){
if(buf[i]=='0')M2C_FIELD(gWfcMatchSession,u8 **,WFC_MATCH_FLAGS)[i]=0;
else {M2C_FIELD(gWfcMatchSession,u8 **,WFC_MATCH_FLAGS)[i]=1; ++*M2C_FIELD(gWfcMatchSession,s32 **,WFC_MATCH_FLAG_COUNT);}
}return 1;
}
}
}
}
SetNetError(18,-33020);return 0;
}

void func_020371f4(void) {
    M2C_UNK HeapAlloc(M2C_UNK);
    HeapAlloc(0);
}

void func_02037204(void) {
    M2C_UNK HeapFree(M2C_UNK);
    HeapFree(0);
}

