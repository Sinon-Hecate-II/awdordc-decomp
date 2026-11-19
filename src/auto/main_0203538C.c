/* 2 functions from 0x0203538C to 0x020362D4 (main), found by ds-decomp. */
#include "common.h"
extern void *gWfcNet;
extern void *data_020fb7b4,*gNasServer;
extern u8 data_0213d150[],gSocketManager[],data_020fb8c8[],data_020fb8d4[],data_020fb8f4[],data_020fb8fc[],data_020fb904[],data_020fb82c[];
extern s32 gErrno;
s32 HttpClientInit(void*,void*);s32 HttpAppendConnectionHeaders(void*);void HttpClientCleanup(void*);void func_02036290(s32);s32 func_02006028(s32);void HttpClientStartTask(void*,s32);void OS_JoinThread(void*);
s32 ParseHttpResponse(void*,s32);void *FindHttpHeader(void*,void*);s32 ParseInt(void*);s32 StringCompare(void*,void*);s32 func_020336c0(void*);s32 func_02033988(void*,void*,s32);
s32 func_020346d0(void*,void*,void*,s32);s32 StringLength(void*);void StringCopyPad(void*,void*,s32);void GetWfcProfile(void*);
s32 CreateNasConnection(void*,void*);void func_02032b68(void);s32 func_02032b98(void);void Nas_GetResult(void*);void func_02032b10(void);
extern u8 data_020fb860[],data_0213d16c[],data_020fb914[],data_020fb91c[],data_020fb810[],data_020fb924[],data_020fb930[],data_020fb934[],data_020fb93c[],data_020fb87c[],data_020fb888[],data_020fb898[],data_020fb8a8[],data_020fb944[],data_020fb950[],data_020fb95c[];
s32 ReadHttpHeader(void*,void*,void*,u32);s32 HttpBufferAppendString(void*,void*);void SleepMilliseconds(s32);

static inline s32 NetMode(void){return M2C_FIELD(&gWfcNet,s32*,12);}
static inline void *NetHandle(void){return M2C_FIELD(&gWfcNet,void**,0x14);}
static inline void SetNetConfig(void *callback,s32 mode,s32 size,void *alloc,void *free,s32 timeout) {
M2C_FIELD(&gWfcNet,void**,0x18)=callback;M2C_FIELD(&gWfcNet,s32*,0x1c)=mode;M2C_FIELD(&gWfcNet,s32*,0x20)=size;
M2C_FIELD(&gWfcNet,void**,0x24)=alloc;M2C_FIELD(&gWfcNet,void**,0x28)=free;M2C_FIELD(&gWfcNet,s32*,0x30)=timeout;
}
static inline void WaitRequest(void){s32 priority=func_02006028(M2C_FIELD(gSocketManager,s32*,4))-1;HttpClientStartTask(NetHandle(),priority);if(M2C_FIELD(NetHandle(),s32*,0x1ba4))OS_JoinThread((u8*)NetHandle()+0x1b38);}


#pragma optimization_level 3
void Wfc_NetCheckTask(void) {
u8 *state=(u8*)&gWfcNet;
u32 code;
void *(*alloc)(void*,s32)=M2C_FIELD(gWfcNet,void*(**)(void*,s32),0x1108);
void (*freefn)(void*,void*,s32)=M2C_FIELD(gWfcNet,void(**)(void*,void*,s32),0x110c);
u8 *first=0,*second=0,*result=0;void *text,*urlcopy,*callback;u8 auth[452],response[148];u8 clock[20];
s32 retry=0,status,n1,n2,n3,delay,length;char statusText[4];
for(;;){
SetNetConfig(data_020fb7b4,1,4096,(void*)alloc,(void*)freefn,20000);M2C_FIELD(gWfcNet,s32*,0x1004)=-2;
if(HttpClientInit(NetHandle(),data_0213d150)){HttpClientCleanup(NetHandle());func_02036290(1);goto done;}
if(HttpAppendConnectionHeaders(NetHandle())){HttpClientCleanup(NetHandle());func_02036290(1);goto done;}
WaitRequest();
switch(M2C_FIELD(NetHandle(),s32*,0x1020)){
case 2:M2C_FIELD(gWfcNet,s32*,0x1004)=-1;
default:HttpClientCleanup(NetHandle());func_02036290(3);goto done;
case 8:break;
}
if(ParseHttpResponse(NetHandle(),0)!=1){HttpClientCleanup(NetHandle());func_02036290(2);goto done;}
text=FindHttpHeader(NetHandle(),data_020fb8c8);code=ParseInt(text);
if(gErrno==34){func_02036290(2);goto done;}
switch(code){
case 200:M2C_FIELD(state,s32*,8)=M2C_FIELD(NetHandle(),s32*,0x112c);break;
case 302:
M2C_FIELD(state,s32*,4)=1;
if(M2C_FIELD(gWfcNet,void**,0x1118)){
M2C_FIELD(gWfcNet,s32*,0x1004)=-6;HttpClientCleanup(NetHandle());
callback=gNasServer;SetNetConfig(callback,0,512,(void*)alloc,(void*)freefn,20000);
if(StringCompare(callback,data_020fb8d4))M2C_FIELD(&gWfcNet,s32*,0x2c)=1;
if(HttpClientInit(NetHandle(),data_0213d150)){HttpClientCleanup(NetHandle());func_02036290(1);goto done;}
if(!func_020336c0(response)||!func_02033988(NetHandle(),response,1)){HttpClientCleanup(NetHandle());func_02036290(8);goto done;}
if(func_020346d0(NetHandle(),data_020fb8f4,data_020fb8fc,7)||(text=M2C_FIELD(gWfcNet,void**,0x1118),length=StringLength(text),func_020346d0(NetHandle(),data_020fb904,text,length))){HttpClientCleanup(NetHandle());func_02036290(8);goto done;}
freefn(data_020fb82c,M2C_FIELD(gWfcNet,void**,0x1118),0);M2C_FIELD(gWfcNet,void**,0x1118)=0;
if(HttpAppendConnectionHeaders(NetHandle())){HttpClientCleanup(NetHandle());func_02036290(1);goto done;}
WaitRequest();
switch(M2C_FIELD(NetHandle(),s32*,0x1020)){
case 2:M2C_FIELD(gWfcNet,s32*,0x1004)=-1;
default:HttpClientCleanup(NetHandle());func_02036290(3);goto done;
case 8:HttpClientCleanup(NetHandle());func_02036290(7);goto done;
}
}
text=M2C_FIELD(NetHandle(),void**,0x1a08);if(!text){HttpClientCleanup(NetHandle());func_02036290(2);goto done;}
length=StringLength(text)+1;M2C_FIELD(gWfcNet,void**,0x1114)=alloc(data_020fb860,length);
urlcopy=M2C_FIELD(gWfcNet,void**,0x1114);if(!urlcopy){HttpClientCleanup(NetHandle());func_02036290(4);goto done;}
StringCopyPad(urlcopy,text,StringLength(text));break;
default:HttpClientCleanup(NetHandle());func_02036290(10);goto done;
}
HttpClientCleanup(NetHandle());GetWfcProfile(&clock);
if(M2C_FIELD(clock,u64*,0)==0){
M2C_FIELD(gWfcNet,s32*,0x1004)=-3;M2C_FIELD(state,u16*,0x34)=0;state[0x68]=0;
text=gWfcNet;M2C_FIELD(state,void**,0x74)=M2C_FIELD(text,void**,0x1108);M2C_FIELD(state,void**,0x78)=M2C_FIELD(text,void**,0x110c);
if(CreateNasConnection(data_0213d16c,NetHandle())){func_02036290(5);goto done;}
func_02032b68();
if(func_02032b98()!=21){
if(func_02032b98()==9){M2C_FIELD(gWfcNet,s32*,0x1004)=-1;goto nasError;}else{
Nas_GetResult(auth);
if(NetMode()==1&&(M2C_FIELD(auth,s32*,0)==(s32)0xffffa4fa||func_02032b98()==11)){
M2C_FIELD(gWfcNet,s32*,0x1004)=0;func_02032b10();func_02036290(11);goto done;
}
M2C_FIELD(gWfcNet,s32*,0x1004)=M2C_FIELD(auth,s32*,0);
nasError:func_02032b10();func_02036290(6);goto done;
}}
func_02032b10();
}
if(code==200){M2C_FIELD(gWfcNet,s32*,0x1004)=0;func_02036290(11);goto done;}
M2C_FIELD(gWfcNet,s32*,0x1004)=-4;
callback=gNasServer;SetNetConfig(callback,0,4096,(void*)alloc,(void*)freefn,40000);
if(StringCompare(callback,data_020fb8d4))M2C_FIELD(state,s32*,0x2c)=1;
if(HttpClientInit(NetHandle(),data_0213d150)){HttpClientCleanup(NetHandle());func_02036290(1);goto done;}
if(!func_020336c0(response)||!func_02033988(NetHandle(),response,1)){HttpClientCleanup(NetHandle());func_02036290(8);goto done;}
if(func_020346d0(NetHandle(),data_020fb8f4,data_020fb914,5)||(text=M2C_FIELD(gWfcNet,void**,0x1114),length=StringLength(text),func_020346d0(NetHandle(),data_020fb91c,text,length))){HttpClientCleanup(NetHandle());func_02036290(8);goto done;}
freefn(data_020fb810,M2C_FIELD(gWfcNet,void**,0x1114),0);M2C_FIELD(gWfcNet,void**,0x1114)=0;
if(HttpAppendConnectionHeaders(NetHandle())){HttpClientCleanup(NetHandle());func_02036290(1);goto done;}
WaitRequest();
switch(M2C_FIELD(NetHandle(),s32*,0x1020)){
case 3:HttpClientCleanup(NetHandle());if(NetMode()==1){M2C_FIELD(gWfcNet,s32*,0x1004)=0;func_02036290(11);goto done;}func_02036290(3);goto done;
case 2:M2C_FIELD(gWfcNet,s32*,0x1004)=-1;
default:HttpClientCleanup(NetHandle());func_02036290(3);goto done;
case 8:break;
}
if(ParseHttpResponse(NetHandle(),0)!=1){HttpClientCleanup(NetHandle());func_02036290(2);goto done;}
code=ParseInt(FindHttpHeader(NetHandle(),data_020fb8c8));
if(gErrno==34){HttpClientCleanup(NetHandle());func_02036290(2);goto done;}
if(code!=200){HttpClientCleanup(NetHandle());if(NetMode()==1&&code==302){M2C_FIELD(gWfcNet,s32*,0x1004)=0;func_02036290(11);goto done;}func_02036290(2);goto done;}
if(ReadHttpHeader(NetHandle(),data_020fb924,statusText,4)<=0){HttpClientCleanup(NetHandle());func_02036290(9);goto done;}
status=ParseInt(statusText);if(gErrno==34){HttpClientCleanup(NetHandle());func_02036290(9);goto done;}
if(NetMode()==1&&status==114){M2C_FIELD(gWfcNet,s32*,0x1004)=0;func_02036290(11);goto done;}
if(status>=100){HttpClientCleanup(NetHandle());func_02036290(6);goto done;}
n1=ReadHttpHeader(NetHandle(),data_020fb930,0,0);if(n1<=0){HttpClientCleanup(NetHandle());func_02036290(9);goto done;}
n2=ReadHttpHeader(NetHandle(),data_020fb934,0,0);if(n2<=0){HttpClientCleanup(NetHandle());func_02036290(9);goto done;}
n3=ReadHttpHeader(NetHandle(),data_020fb93c,0,0);
first=alloc(data_020fb87c,n1+1);if(!first){HttpClientCleanup(NetHandle());func_02036290(4);goto done;}
second=alloc(data_020fb888,n2+1);if(!second){HttpClientCleanup(NetHandle());func_02036290(4);goto done;}
if(n3>0){result=alloc(data_020fb898,n3+1);if(!result){HttpClientCleanup(NetHandle());func_02036290(4);goto done;}}
status=ReadHttpHeader(NetHandle(),data_020fb930,first,n1+1);if(status<0){HttpClientCleanup(NetHandle());func_02036290(9);goto done;}first[status]=0;
status=ReadHttpHeader(NetHandle(),data_020fb934,second,n2+1);if(status<0){HttpClientCleanup(NetHandle());func_02036290(9);goto done;}second[status]=0;
delay=0;
if(n3>0){
status=ReadHttpHeader(NetHandle(),data_020fb93c,result,n3+1);if(status<0){HttpClientCleanup(NetHandle());func_02036290(9);goto done;}result[status]=0;
status=ParseInt(result);if(gErrno==34){HttpClientCleanup(NetHandle());func_02036290(9);goto done;}
delay=status*1000;if(delay>180000)delay=180000;
}
HttpClientCleanup(NetHandle());M2C_FIELD(gWfcNet,s32*,0x1004)=-5;
SetNetConfig(first,0,4096,(void*)alloc,(void*)freefn,120000);
if(HttpClientInit(NetHandle(),data_0213d150)){HttpClientCleanup(NetHandle());func_02036290(1);goto done;}
if(HttpBufferAppendString(NetHandle(),second)){HttpClientCleanup(NetHandle());func_02036290(8);goto done;}
if(HttpAppendConnectionHeaders(NetHandle())){HttpClientCleanup(NetHandle());func_02036290(1);goto done;}
WaitRequest();
switch(M2C_FIELD(NetHandle(),s32*,0x1020)){
case 2:M2C_FIELD(gWfcNet,s32*,0x1004)=-1;
default:HttpClientCleanup(NetHandle());func_02036290(3);goto done;
case 8:break;
}
if(ParseHttpResponse(NetHandle(),1)!=1){HttpClientCleanup(NetHandle());func_02036290(2);goto done;}
text=M2C_FIELD(NetHandle(),void**,0x1a08);if(!text){HttpClientCleanup(NetHandle());func_02036290(2);goto done;}
M2C_FIELD(gWfcNet,void**,0x1118)=alloc(data_020fb8a8,StringLength(text)+1);
urlcopy=M2C_FIELD(gWfcNet,void**,0x1118);if(!urlcopy){HttpClientCleanup(NetHandle());func_02036290(4);goto done;}
StringCopyPad(urlcopy,text,StringLength(text));HttpClientCleanup(NetHandle());SleepMilliseconds(delay);
}
done:
if(first)freefn(data_020fb944,first,0);if(second)freefn(data_020fb950,second,0);if(result)freefn(data_020fb95c,result,0);
}
#pragma optimization_level reset
void func_02036290(s32 arg0) {
    M2C_UNK LockMutex(void *);
    M2C_UNK UnlockMutex(void *);
    extern void *gWfcNet;
    LockMutex(gWfcNet + 0x11DC);
    M2C_FIELD(gWfcNet, s32 *, 0x1000) = arg0;
    UnlockMutex(gWfcNet + 0x11DC);
}
