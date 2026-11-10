/* 2 functions from 0x0203538C to 0x020362D4 (main), found by ds-decomp. */
#include "common.h"
extern void *data_0213d138;
extern void *data_020fb7b4,*data_020fb2f8;
extern u8 data_0213d150[],data_0212dca4[],data_020fb8c8[],data_020fb8d4[],data_020fb8f4[],data_020fb8fc[],data_020fb904[],data_020fb82c[];
extern s32 data_0213e9f4;
s32 func_02033ccc(void*,void*);s32 func_02033de8(void*);void func_02034480(void*);void func_02036290(s32);s32 func_02006028(s32);void func_02033e80(void*,s32);void func_02005d60(void*);
s32 func_02034c58(void*,s32);void *func_02034ef8(void*,void*);s32 ParseInt(void*);s32 StringCompare(void*,void*);s32 func_020336c0(void*);s32 func_02033988(void*,void*,s32);
s32 func_020346d0(void*,void*,void*,s32);s32 StringLength(void*);void func_02068d18(void*,void*,s32);void func_02045cbc(void*);
s32 func_020328ac(void*,void*);void func_02032b68(void);s32 func_02032b98(void);void func_02032be4(void*);void func_02032b10(void);
extern u8 data_020fb860[],data_0213d16c[],data_020fb914[],data_020fb91c[],data_020fb810[],data_020fb924[],data_020fb930[],data_020fb934[],data_020fb93c[],data_020fb87c[],data_020fb888[],data_020fb898[],data_020fb8a8[],data_020fb944[],data_020fb950[],data_020fb95c[];
s32 func_02034f50(void*,void*,void*,u32);s32 func_020347dc(void*,void*);void func_02006030(s32);

static inline s32 NetMode(void){return M2C_FIELD(&data_0213d138,s32*,12);}
static inline void *NetHandle(void){return M2C_FIELD(&data_0213d138,void**,0x14);}
static inline void SetNetConfig(void *callback,s32 mode,s32 size,void *alloc,void *free,s32 timeout) {
M2C_FIELD(&data_0213d138,void**,0x18)=callback;M2C_FIELD(&data_0213d138,s32*,0x1c)=mode;M2C_FIELD(&data_0213d138,s32*,0x20)=size;
M2C_FIELD(&data_0213d138,void**,0x24)=alloc;M2C_FIELD(&data_0213d138,void**,0x28)=free;M2C_FIELD(&data_0213d138,s32*,0x30)=timeout;
}
static inline void WaitRequest(void){s32 priority=func_02006028(M2C_FIELD(data_0212dca4,s32*,4))-1;func_02033e80(NetHandle(),priority);if(M2C_FIELD(NetHandle(),s32*,0x1ba4))func_02005d60((u8*)NetHandle()+0x1b38);}


#pragma optimization_level 3
void func_0203538c(void) {
u8 *state=(u8*)&data_0213d138;
u32 code;s32 n2;
void *(*alloc)(void*,s32)=M2C_FIELD(data_0213d138,void*(**)(void*,s32),0x1108);
void (*freefn)(void*,void*,s32)=M2C_FIELD(data_0213d138,void(**)(void*,void*,s32),0x110c);
u8 *first=0,*second=0,*result=0;void *text,*urlcopy,*callback;u8 auth[452],response[148];u8 clock[20];
s32 retry=0,status,n1,n3,delay,length;char statusText[4];
for(;;){
SetNetConfig(data_020fb7b4,1,4096,(void*)alloc,(void*)freefn,20000);M2C_FIELD(data_0213d138,s32*,0x1004)=-2;
if(func_02033ccc(NetHandle(),data_0213d150)){func_02034480(NetHandle());func_02036290(1);goto done;}
if(func_02033de8(NetHandle())){func_02034480(NetHandle());func_02036290(1);goto done;}
WaitRequest();
switch(M2C_FIELD(NetHandle(),s32*,0x1020)){
case 2:M2C_FIELD(data_0213d138,s32*,0x1004)=-1;
default:func_02034480(NetHandle());func_02036290(3);goto done;
case 8:break;
}
if(func_02034c58(NetHandle(),0)!=1){func_02034480(NetHandle());func_02036290(2);goto done;}
text=func_02034ef8(NetHandle(),data_020fb8c8);code=ParseInt(text);
if(data_0213e9f4==34){func_02036290(2);goto done;}
switch(code){
case 200:M2C_FIELD(state,s32*,8)=M2C_FIELD(NetHandle(),s32*,0x112c);break;
case 302:
M2C_FIELD(state,s32*,4)=1;
if(M2C_FIELD(data_0213d138,void**,0x1118)){
M2C_FIELD(data_0213d138,s32*,0x1004)=-6;func_02034480(NetHandle());
callback=data_020fb2f8;SetNetConfig(callback,0,512,(void*)alloc,(void*)freefn,10000);
if(StringCompare(callback,data_020fb8d4))M2C_FIELD(state,s32*,0x2c)=1;
if(func_02033ccc(NetHandle(),data_0213d150)){func_02034480(NetHandle());func_02036290(1);goto done;}
if(!func_020336c0(response)||!func_02033988(NetHandle(),response,1)){func_02034480(NetHandle());func_02036290(8);goto done;}
if(func_020346d0(NetHandle(),data_020fb8f4,data_020fb8fc,7)||(text=M2C_FIELD(data_0213d138,void**,0x1118),length=StringLength(text),func_020346d0(NetHandle(),data_020fb904,text,length))){func_02034480(NetHandle());func_02036290(8);goto done;}
freefn(data_020fb82c,M2C_FIELD(data_0213d138,void**,0x1118),0);M2C_FIELD(data_0213d138,void**,0x1118)=0;
if(func_02033de8(NetHandle())){func_02034480(NetHandle());func_02036290(1);goto done;}
WaitRequest();
switch(M2C_FIELD(NetHandle(),s32*,0x1020)){
case 2:M2C_FIELD(data_0213d138,s32*,0x1004)=-1;
default:func_02034480(NetHandle());func_02036290(3);goto done;
case 8:func_02034480(NetHandle());func_02036290(7);goto done;
}
}
text=M2C_FIELD(NetHandle(),void**,0x1a08);if(!text){func_02034480(NetHandle());func_02036290(2);goto done;}
M2C_FIELD(data_0213d138,void**,0x1114)=alloc(data_020fb860,StringLength(text)+1);
urlcopy=M2C_FIELD(data_0213d138,void**,0x1114);if(!urlcopy){func_02034480(NetHandle());func_02036290(4);goto done;}
func_02068d18(urlcopy,text,StringLength(text));break;
default:func_02034480(NetHandle());func_02036290(10);goto done;
}
func_02034480(NetHandle());func_02045cbc(&clock);
if(M2C_FIELD(clock,u64*,0)==0){
M2C_FIELD(data_0213d138,s32*,0x1004)=-3;M2C_FIELD(state,u16*,0x34)=0;state[0x68]=0;
M2C_FIELD(state,void**,0x74)=M2C_FIELD(data_0213d138,void**,0x1108);M2C_FIELD(state,void**,0x78)=M2C_FIELD(data_0213d138,void**,0x110c);
if(func_020328ac(data_0213d16c,NetHandle())){func_02036290(5);goto done;}
func_02032b68();
if(func_02032b98()!=21){
if(func_02032b98()==9){M2C_FIELD(data_0213d138,s32*,0x1004)=-1;}else{
func_02032be4(auth);
if(NetMode()==1&&(M2C_FIELD(auth,s32*,0)==(s32)0xffffa4fa||func_02032b98()==11)){
M2C_FIELD(data_0213d138,s32*,0x1004)=0;func_02032b10();func_02036290(11);goto done;
}
M2C_FIELD(data_0213d138,s32*,0x1004)=M2C_FIELD(auth,s32*,0);func_02032b10();func_02036290(6);goto done;
}}
func_02032b10();
}
if(code==200){M2C_FIELD(data_0213d138,s32*,0x1004)=0;func_02036290(11);goto done;}
M2C_FIELD(data_0213d138,s32*,0x1004)=-4;
callback=data_020fb2f8;SetNetConfig(callback,0,4096,(void*)alloc,(void*)freefn,40000);
if(StringCompare(callback,data_020fb8d4))M2C_FIELD(state,s32*,0x2c)=1;
if(func_02033ccc(NetHandle(),data_0213d150)){func_02034480(NetHandle());func_02036290(1);goto done;}
if(!func_020336c0(response)||!func_02033988(NetHandle(),response,1)){func_02034480(NetHandle());func_02036290(8);goto done;}
if(func_020346d0(NetHandle(),data_020fb8f4,data_020fb914,5)||(text=M2C_FIELD(data_0213d138,void**,0x1114),length=StringLength(text),func_020346d0(NetHandle(),data_020fb91c,text,length))){func_02034480(NetHandle());func_02036290(8);goto done;}
freefn(data_020fb810,M2C_FIELD(data_0213d138,void**,0x1114),0);M2C_FIELD(data_0213d138,void**,0x1114)=0;
if(func_02033de8(NetHandle())){func_02034480(NetHandle());func_02036290(1);goto done;}
WaitRequest();
switch(M2C_FIELD(NetHandle(),s32*,0x1020)){
case 3:func_02034480(NetHandle());if(NetMode()==1){M2C_FIELD(data_0213d138,s32*,0x1004)=0;func_02036290(11);goto done;}func_02036290(3);goto done;
case 2:M2C_FIELD(data_0213d138,s32*,0x1004)=-1;
default:func_02034480(NetHandle());func_02036290(3);goto done;
case 8:break;
}
if(func_02034c58(NetHandle(),0)!=1){func_02034480(NetHandle());func_02036290(2);goto done;}
code=ParseInt(func_02034ef8(NetHandle(),data_020fb8c8));
if(data_0213e9f4==34){func_02034480(NetHandle());func_02036290(2);goto done;}
if(code!=200){func_02034480(NetHandle());if(NetMode()==1&&code==302){M2C_FIELD(data_0213d138,s32*,0x1004)=0;func_02036290(11);goto done;}func_02036290(2);goto done;}
if(func_02034f50(NetHandle(),data_020fb924,statusText,4)<=0){func_02034480(NetHandle());func_02036290(9);goto done;}
status=ParseInt(statusText);if(data_0213e9f4==34){func_02034480(NetHandle());func_02036290(9);goto done;}
if(NetMode()==1&&status==114){M2C_FIELD(data_0213d138,s32*,0x1004)=0;func_02036290(11);goto done;}
if(status>=100){func_02034480(NetHandle());func_02036290(6);goto done;}
n1=func_02034f50(NetHandle(),data_020fb930,0,0);if(n1<=0){func_02034480(NetHandle());func_02036290(9);goto done;}
n2=func_02034f50(NetHandle(),data_020fb934,0,0);if(n2<=0){func_02034480(NetHandle());func_02036290(9);goto done;}
n3=func_02034f50(NetHandle(),data_020fb93c,0,0);
first=alloc(data_020fb87c,n1+1);if(!first){func_02034480(NetHandle());func_02036290(4);goto done;}
second=alloc(data_020fb888,n2+1);if(!second){func_02034480(NetHandle());func_02036290(4);goto done;}
if(n3>0){result=alloc(data_020fb898,n3+1);if(!result){func_02034480(NetHandle());func_02036290(4);goto done;}}
status=func_02034f50(NetHandle(),data_020fb930,first,n1+1);if(status<0){func_02034480(NetHandle());func_02036290(9);goto done;}first[status]=0;
status=func_02034f50(NetHandle(),data_020fb934,second,n2+1);if(status<0){func_02034480(NetHandle());func_02036290(9);goto done;}second[status]=0;
delay=0;
if(n3>0){
status=func_02034f50(NetHandle(),data_020fb93c,result,n3+1);if(status<0){func_02034480(NetHandle());func_02036290(9);goto done;}result[status]=0;
status=ParseInt(result);if(data_0213e9f4==34){func_02034480(NetHandle());func_02036290(9);goto done;}
delay=status*1000;if(delay>180000)delay=180000;
}
func_02034480(NetHandle());M2C_FIELD(data_0213d138,s32*,0x1004)=-5;
SetNetConfig(first,0,4096,(void*)alloc,(void*)freefn,120000);
if(func_02033ccc(NetHandle(),data_0213d150)){func_02034480(NetHandle());func_02036290(1);goto done;}
if(func_020347dc(NetHandle(),second)){func_02034480(NetHandle());func_02036290(8);goto done;}
if(func_02033de8(NetHandle())){func_02034480(NetHandle());func_02036290(1);goto done;}
WaitRequest();
switch(M2C_FIELD(NetHandle(),s32*,0x1020)){
case 2:M2C_FIELD(data_0213d138,s32*,0x1004)=-1;
default:func_02034480(NetHandle());func_02036290(3);goto done;
case 8:break;
}
if(func_02034c58(NetHandle(),1)!=1){func_02034480(NetHandle());func_02036290(2);goto done;}
text=M2C_FIELD(NetHandle(),void**,0x1a08);if(!text){func_02034480(NetHandle());func_02036290(2);goto done;}
M2C_FIELD(data_0213d138,void**,0x1118)=alloc(data_020fb8a8,StringLength(text)+1);
urlcopy=M2C_FIELD(data_0213d138,void**,0x1118);if(!urlcopy){func_02034480(NetHandle());func_02036290(4);goto done;}
func_02068d18(urlcopy,text,StringLength(text));func_02034480(NetHandle());func_02006030(delay);
}
done:
if(first)freefn(data_020fb944,first,0);if(second)freefn(data_020fb950,second,0);if(result)freefn(data_020fb95c,result,0);
}
#pragma optimization_level reset
void func_02036290(s32 arg0) {
    M2C_UNK func_02006564(void *);
    M2C_UNK func_020065e8(void *);
    extern void *data_0213d138;
    func_02006564(data_0213d138 + 0x11DC);
    M2C_FIELD(data_0213d138, s32 *, 0x1000) = arg0;
    func_020065e8(data_0213d138 + 0x11DC);
}
