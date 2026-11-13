/* 1 function from 0x020562D0 to 0x02057D80 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 function; s32 argument; } ProtocolCallback;
extern s32 data_020fef90;
extern char data_020fef94[];
extern char data_020fefc0[];
extern char data_020fefcc[];
extern char data_020fefd8[];
extern char data_020fefe4[];
extern char data_020feff4[];
extern char data_020feffc[];
extern char data_020ff00c[];
extern char data_020ff014[];
extern char data_020ff020[];
extern char data_020ff02c[];
extern char data_020ff038[];
extern char data_020ff040[];
extern char data_020ff048[];
extern char data_020ff050[];
extern char data_020ff058[];
extern char data_020ff064[];
extern char data_020ff070[];
extern char data_020ff078[];
extern char data_020ff084[];
extern char data_020ff090[];
extern char data_020ff098[];
extern char data_020ff0a4[];
extern char data_020ff0b4[];
extern char data_020ff0c4[];
extern char gGpiSearchSourceFile[];
extern char data_020fee0c[];
extern char data_020ff0c8[];
extern char gServiceNameBuffer[];
extern char data_020ff0d4[];
extern char data_020ff0dc[];
extern char data_020ff108[];
extern char data_020ff110[];
extern char data_020ff118[];
extern char gGpiSearchMsgOutOfMemory[];
extern char data_020ff11c[];
extern char data_020ff124[];
extern char data_020ff130[];
extern char data_020ff13c[];
extern char data_020ff148[];
extern char data_020ff150[];
extern char data_020ff178[];
extern char data_020ff17c[];
extern char data_020ff180[];
extern char data_020ff188[];
extern char data_020ff190[];
extern char data_020ff194[];
extern char data_020ff19c[];
extern char data_020ff1a8[];
extern char data_020ff1ac[];
extern char data_020ff1b4[];
extern char data_020ff1b8[];
extern char data_020ff1c0[];
extern char data_020ff1c8[];
extern char data_020ff1cc[];
extern char data_020ff1d4[];
extern char data_020ff1dc[];
extern char data_020ff1e0[];
extern char data_020ff1e8[];

#pragma push
#pragma opt_lifetimes off
s32 func_020562d0(void *a,void *b) {
s32 gpiSendFromBuffer(void*,s32,void*,void*,s32,void*);
s32 func_0205835c(void*,s32,s32*);
void gpiAppendStringField(void*,void*,void*);
void gpiAppendIntField(void*,void*,s32);
s32 gpiReceiveData(void*,s32,void*,s32*,s32*,void*);
s32 func_02058450(void*,s32,s32*,char*,char*);
s32 StringCompare(void*,void*);
void *gpiRealloc(void*,s32);
void *gpiMalloc(s32);
s32 gpiAddCallback(void*,ProtocolCallback,void*,void*,s32);
s32 gpiSearchProfiles(void*,void*,void*,void*,void*,void*,s32,s32,s32,s32,s32);
s32 result,status,token,loop,done,inner,previous,kind,i;
void *ctx=M2C_FIELD(a,void**,0),*request=M2C_FIELD(b,void**,4);
ProtocolCallback callback1,callback2,callback3,callback4,callback5,callback6,callback7,callback8;
char name[512],value[512];s32 response[4];void *entry,*item,*array;u32 count; s32 code,extra;
loop=M2C_FIELD(b,s32*,8)!=0;
again:
result=gpiSendFromBuffer(a,M2C_FIELD(request,s32*,4),request+24,&status,1,&data_020fef90);
if(result)return result;
if(M2C_FIELD(b,s32*,20)==1){
result=func_0205835c(a,M2C_FIELD(request,s32*,4),&kind);if(result)return result;
if(kind==4){gpiSetError(a,0xd01,data_020fef94);gpiCallErrorCallback(a,4,0);return 4;}
if(kind==3){
i=M2C_FIELD(request,s32*,0);
if(i==1){
gpiAppendStringField(a,request+24,data_020fefc0);
gpiAppendStringField(a,request+24,data_020fefcc);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,408));
gpiAppendStringField(a,request+24,data_020fefd8);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,416));
gpiAppendStringField(a,request+24,data_020fefe4);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,1136));
if(M2C_FIELD(request,s8*,40)){gpiAppendStringField(a,request+24,data_020feff4);
gpiAppendStringField(a,request+24,request+40);
}
if(M2C_FIELD(request,s8*,71)){gpiAppendStringField(a,request+24,data_020feffc);
gpiAppendStringField(a,request+24,request+71);
}
if(M2C_FIELD(request,s8*,92)){gpiAppendStringField(a,request+24,data_020ff00c);
gpiAppendStringField(a,request+24,request+92);
}
if(M2C_FIELD(request,s8*,143)){gpiAppendStringField(a,request+24,data_020ff014);
gpiAppendStringField(a,request+24,request+143);
}
if(M2C_FIELD(request,s8*,174)){gpiAppendStringField(a,request+24,data_020ff020);
gpiAppendStringField(a,request+24,request+174);
}
if(M2C_FIELD(request,s32*,304)!=0){gpiAppendStringField(a,request+24,data_020ff02c);
gpiAppendIntField(a,request+24,M2C_FIELD(request,s32*,304));}
if(M2C_FIELD(request,s32*,308)>0){gpiAppendStringField(a,request+24,data_020ff038);
gpiAppendIntField(a,request+24,M2C_FIELD(request,s32*,308));}
}else if(i==2){gpiAppendStringField(a,request+24,data_020ff040);
gpiAppendStringField(a,request+24,data_020ff00c);
gpiAppendStringField(a,request+24,request+92);
}else if(i==3){gpiAppendStringField(a,request+24,data_020ff048);
gpiAppendStringField(a,request+24,data_020ff00c);
gpiAppendStringField(a,request+24,request+92);
gpiAppendStringField(a,request+24,data_020ff050);
gpiAppendStringField(a,request+24,request+205);
gpiAppendStringField(a,request+24,data_020fefe4);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,1136));
}else if(i==4){gpiAppendStringField(a,request+24,data_020ff058);
gpiAppendStringField(a,request+24,data_020fefcc);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,408));
gpiAppendStringField(a,request+24,data_020fefd8);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,416));
gpiAppendStringField(a,request+24,data_020ff064);
gpiAppendIntField(a,request+24,M2C_FIELD(request,s32*,0x138));
}else if(i==5){gpiAppendStringField(a,request+24,data_020ff070);
gpiAppendStringField(a,request+24,data_020feff4);
gpiAppendStringField(a,request+24,request+40);
gpiAppendStringField(a,request+24,data_020ff00c);
gpiAppendStringField(a,request+24,request+92);
gpiAppendStringField(a,request+24,data_020ff050);
gpiAppendStringField(a,request+24,request+205);
}else if(i==6){
gpiAppendStringField(a,request+24,data_020ff078);
gpiAppendStringField(a,request+24,data_020feff4);
gpiAppendStringField(a,request+24,request+40);
gpiAppendStringField(a,request+24,data_020ff00c);
gpiAppendStringField(a,request+24,request+92);
gpiAppendStringField(a,request+24,data_020ff050);
gpiAppendStringField(a,request+24,request+205);
gpiAppendStringField(a,request+24,data_020ff084);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,1132));
gpiAppendStringField(a,request+24,data_020fefe4);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,1136));
gpiAppendStringField(a,request+24,data_020feffc);
gpiAppendStringField(a,request+24,request+71);
if(M2C_FIELD(request,s8*,0xec)){gpiAppendStringField(a,request+24,data_020ff090);
gpiAppendStringField(a,request+24,request+236);
}}else if(i==7){gpiAppendStringField(a,request+24,data_020ff098);
gpiAppendStringField(a,request+24,data_020fefcc);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,408));
gpiAppendStringField(a,request+24,data_020fefd8);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,416));
gpiAppendStringField(a,request+24,data_020fefe4);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,1136));
}else if(i==8){gpiAppendStringField(a,request+24,data_020ff0a4);
gpiAppendStringField(a,request+24,data_020ff0b4);
gpiAppendStringField(a,request+24,request+71);
gpiAppendStringField(a,request+24,data_020fefe4);
gpiAppendIntField(a,request+24,M2C_FIELD(ctx,s32*,1136));
}else{AssertFailed(data_020ff0c4,gGpiSearchSourceFile,data_020fee0c,0x275);}
gpiAppendStringField(a,request+24,data_020ff0c8);
gpiAppendStringField(a,request+24,gServiceNameBuffer);
gpiAppendStringField(a,request+24,data_020ff0d4);
M2C_FIELD(b,s32*,20)=4;
}
}else if(M2C_FIELD(b,s32*,20)==4){
result=gpiReceiveData(a,M2C_FIELD(request,s32*,4),request+8,&token,&status,&data_020fef90);
if(result){if(result!=3)return result;gpiSetError(a,0xd01,data_020ff0dc);gpiCallErrorCallback(a,3,0);return 3;}
if(StringFind(M2C_FIELD(request,void**,8),data_020ff0d4)!=0){
previous=0;M2C_FIELD(b,s32*,20)=5;
if(func_0205817c(a,M2C_FIELD(request,s32*,8),1)){M2C_FIELD(request,s32*,0x140)=1;return 4;}
if(M2C_FIELD(request,s32*,0)==1){
done=0;response[0]=0;response[1]=0;response[2]=0x601;response[3]=0;
do{
result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;
if(!StringCompare(name,data_020ff108)){
result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;
if(!StringCompare(name,data_020ff110)){
if(StringCompare(value,data_020ff0c4))response[2]=0x600;done=1;
}
}else if(!StringCompare(name,data_020ff118)){
response[1]++;
response[3]=(s32)gpiRealloc((void*)response[3],response[1]*172);
if(!response[3]){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
entry=(void*)(response[3]+(response[1]-1)*172);
MemSet(entry,0,172);M2C_FIELD(entry,s32*,0)=ParseInt(value);
inner=0;token=previous;
do{
result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;
if(!StringCompare(name,data_020ff11c)){StringCopyN(entry+4,value,31);}
else if(!StringCompare(name,data_020ff124)){StringCopyN(entry+35,value,21);}
else if(!StringCompare(name,data_020ff130)){StringCopyN(entry+56,value,31);}
else if(!StringCompare(name,data_020ff13c)){StringCopyN(entry+87,value,31);}
else if(!StringCompare(name,data_020ff148)){StringCopyN(entry+118,value,51);}
else if(!StringCompare(name,data_020ff118)||!StringCompare(name,data_020ff108)){previous=token;inner=1;}
}while(!inner);
}else{gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}
}while(!done);
code=response[2];
if(M2C_FIELD(b,void**,12))((void(*)(void*,s32*,s32))M2C_FIELD(b,void**,12))(a,response,M2C_FIELD(b,s32*,16));
if(code==0x600 && response[2]==0x600){result=gpiSearchProfiles(a,request+0x28,request+0x47,request+0x5c,request+0x8f,request+0xae,M2C_FIELD(request,s32*,0x130),response[1]+M2C_FIELD(request,s32*,0x134),M2C_FIELD(b,s32*,8),M2C_FIELD(b,s32*,12),M2C_FIELD(b,s32*,16));if(result)return result;gpiFree(response[3]);response[3]=0;}
}else if(M2C_FIELD(request,s32*,0)==2){
callback2.function=M2C_FIELD(b,s32*,12);callback2.argument=M2C_FIELD(b,s32*,16);
if(callback2.function){
result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;
if(StringCompare(name,data_020ff178)){gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}
entry=gpiMalloc(60);if(!entry){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
M2C_FIELD(entry,s32*,0)=0;StringCopyN(entry+4,request+0x5c,51);
M2C_FIELD(entry,s32*,56)=value[0]=='0'?0:1;
result=gpiAddCallback(a,callback2,entry,b,0);if(result)return result;
}
}else if(M2C_FIELD(request,s32*,0)==3){
callback3.function=M2C_FIELD(b,s32*,12);callback3.argument=M2C_FIELD(b,s32*,16);
if(callback3.function){
entry=gpiMalloc(68);if(!entry){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
M2C_FIELD(entry,s32*,0)=0;StringCopy(entry+4,request+0x5c);
M2C_FIELD(entry,s32*,56)=0;M2C_FIELD(entry,s32*,60)=0;M2C_FIELD(entry,s32*,64)=0;
result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;
if(StringCompare(name,data_020ff17c)){gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}
done=0;
do{
result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;
if(!StringCompare(name,data_020ff11c)){
void *array=gpiRealloc(M2C_FIELD(entry,void**,60),(M2C_FIELD(entry,s32*,56)+1)*4);if(!array){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
M2C_FIELD(entry,void**,60)=array;
array=gpiMalloc(31);if(!array){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
((void**)M2C_FIELD(entry,void**,60))[M2C_FIELD(entry,s32*,56)]=array;
StringCopyN(array,value,31);M2C_FIELD(entry,s32*,56)++;
}else if(!StringCompare(name,data_020ff124)){
if(M2C_FIELD(entry,s32*,56)>0){
void *array=gpiRealloc(M2C_FIELD(entry,void**,64),M2C_FIELD(entry,s32*,56)*4);if(!array){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
M2C_FIELD(entry,void**,64)=array;
array=gpiMalloc(21);if(!array){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
((void**)M2C_FIELD(entry,void**,64))[M2C_FIELD(entry,s32*,56)-1]=array;
StringCopyN(array,value,21);
}
}else if(!StringCompare(name,data_020ff180))done=1;
else {gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}
}while(!done);
result=gpiAddCallback(a,callback3,entry,b,3);if(result)return result;
}
}
else if(M2C_FIELD(request,s32*,0)==4){
callback4.function=M2C_FIELD(b,s32*,12);callback4.argument=M2C_FIELD(b,s32*,16);
if(callback4.function){
entry=gpiMalloc(16);if(!entry){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
M2C_FIELD(entry,s32*,0)=0;M2C_FIELD(entry,s32*,4)=M2C_FIELD(request,s32*,0x138);M2C_FIELD(entry,s32*,8)=0;M2C_FIELD(entry,s32*,12)=0;
done=0;do{result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;

if(!StringCompare(name,data_020ff188))done=1;
else if(!StringCompare(name,data_020ff190)){
count=M2C_FIELD(entry,s32*,8)+1;M2C_FIELD(entry,s32*,8)=count;
array=gpiRealloc(M2C_FIELD(entry,void**,12),count*296);if(!array){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
M2C_FIELD(entry,void**,12)=array;item=array+(count-1)*296;MemSet(item,0,296);M2C_FIELD(item,s32*,36)=1;M2C_FIELD(item,s32*,0)=ParseInt(value);
inner=0;token=previous;do{result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;

if(!StringCompare(name,data_020ff194))StringCopyN(item+40,value,256);
else if(!StringCompare(name,data_020ff11c))StringCopyN(item+4,value,31);
if(!StringCompare(name,data_020ff19c))M2C_FIELD(item,s32*,36)=ParseInt(value);
else if(!StringCompare(name,data_020ff190)||!StringCompare(name,data_020ff188)){previous=token;inner=1;}
}while(!inner);
}else {gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}
}while(!done);result=gpiAddCallback(a,callback4,entry,b,4);if(result)return result;

}}
else if(M2C_FIELD(request,s32*,0)==5){
callback5.function=M2C_FIELD(b,s32*,12);callback5.argument=M2C_FIELD(b,s32*,16);
if(callback5.function){
result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;

if(StringCompare(name,data_020ff1a8)){gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}
code=ParseInt(value);
if(code)M2C_FIELD(ctx,s32*,0x418)=code;
extra=0;
if(!code){
if(!GetStringField(M2C_FIELD(request,s32*,8),data_020ff1ac,value,512)){if(!code){gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}}
else extra=ParseInt(value);
}
entry=gpiMalloc(8);if(!entry){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}M2C_FIELD(entry,s32*,0)=code;M2C_FIELD(entry,s32*,4)=extra;
result=gpiAddCallback(a,callback5,entry,b,0);if(result)return result;

}}
else if(M2C_FIELD(request,s32*,0)==6){
callback6.function=M2C_FIELD(b,s32*,12);callback6.argument=M2C_FIELD(b,s32*,16);
if(callback6.function){
result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;

if(StringCompare(name,data_020ff1b4)){gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}
code=ParseInt(value);
if(code)M2C_FIELD(ctx,s32*,0x418)=code;
extra=0;
if(1){
if(!GetStringField(M2C_FIELD(request,s32*,8),data_020ff1ac,value,512)){if(!code){gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}}
else extra=ParseInt(value);
}
entry=gpiMalloc(8);if(!entry){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}M2C_FIELD(entry,s32*,0)=code;M2C_FIELD(entry,s32*,4)=extra;
result=gpiAddCallback(a,callback6,entry,b,0);if(result)return result;

}}
else if(M2C_FIELD(request,s32*,0)==7){
callback7.function=M2C_FIELD(b,s32*,12);callback7.argument=M2C_FIELD(b,s32*,16);
if(callback7.function){
entry=gpiMalloc(12);if(!entry){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
M2C_FIELD(entry,s32*,0)=0;M2C_FIELD(entry,s32*,4)=0;M2C_FIELD(entry,s32*,8)=0;
result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;

if(StringCompare(name,data_020ff1b8)){gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}
done=0;do{result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;

if(!StringCompare(name,data_020ff1c0))done=1;
else if(!StringCompare(name,data_020ff1c8)){
count=M2C_FIELD(entry,s32*,4);
array=gpiRealloc(M2C_FIELD(entry,void**,8),(count+1)*172);if(!array){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
M2C_FIELD(entry,void**,8)=array;item=array+count*172;MemSet(item,0,172);M2C_FIELD(entry,s32*,4)=count+1;M2C_FIELD(item,s32*,0)=ParseInt(value);
inner=0;token=previous;do{result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;

if(!StringCompare(name,data_020ff11c))StringCopyN(item+4,value,31);
else if(!StringCompare(name,data_020ff124))StringCopyN(item+35,value,21);
else if(!StringCompare(name,data_020ff1cc))StringCopyN(item+56,value,31);
else if(!StringCompare(name,data_020ff1d4))StringCopyN(item+87,value,31);
else if(!StringCompare(name,data_020ff148))StringCopyN(item+118,value,51);
else if(!StringCompare(name,data_020ff1c8)||!StringCompare(name,data_020ff1c0)){previous=token;inner=1;}
}while(!inner);
}else {gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}
}while(!done);result=gpiAddCallback(a,callback7,entry,b,8);if(result)return result;

}}
else if(M2C_FIELD(request,s32*,0)==8){
callback8.function=M2C_FIELD(b,s32*,12);callback8.argument=M2C_FIELD(b,s32*,16);
if(callback8.function){
count=0;entry=gpiMalloc(12);if(!entry){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
M2C_FIELD(entry,s32*,0)=0;M2C_FIELD(entry,s32*,4)=0;M2C_FIELD(entry,s32*,8)=0;
result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;

if(StringCompare(name,data_020ff1dc)){gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}
M2C_FIELD(entry,s32*,4)=ParseInt(value);
array=gpiMalloc(M2C_FIELD(entry,s32*,4)*4);M2C_FIELD(entry,void**,8)=array;if(!array){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}
done=0;do{result=func_02058450(a,M2C_FIELD(request,s32*,8),&previous,name,value);if(result)return result;

if(!StringCompare(name,data_020ff11c)){
item=gpiMalloc(21);((void**)M2C_FIELD(entry,void**,8))[count]=item;if(!item){gpiSetErrorString(a,gGpiSearchMsgOutOfMemory);return 1;}StringCopyN(item,value,21);count++;
}else if(!StringCompare(name,data_020ff1e0)){
if(count!=M2C_FIELD(entry,s32*,4))AssertFailed(data_020ff1e8,gGpiSearchSourceFile,data_020fee0c,0x515);
M2C_FIELD(entry,s32*,4)=count;done=1;
}else {gpiSetError(a,1,data_020ff150);gpiCallErrorCallback(a,3,1);return 3;}
}while(!done);result=gpiAddCallback(a,callback8,entry,b,9);if(result)return result;

}}
else AssertFailed(data_020ff0c4,gGpiSearchSourceFile,data_020fee0c,0x52a);

M2C_FIELD(request,s32*,0x140)=1;loop=0;
}
}
if(loop){gpiSleep(10);goto again;}return 0;
}
#pragma pop
