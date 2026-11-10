/* 1 function from 0x0203F45C to 0x02040340 (main), found by ds-decomp. */
#include "common.h"
u64 func_02072088(u64,u64);
extern u8 *gConnectionMgr;
void *GetConnection(void);u64 func_02007004(void);

int func_0203f45c(int type,int peer,int a,int b,s32 *payload,int count){
int n=0,i,j;u32 packet0;u32 packet[65];u8 raw[8];void *p,*q;s64 ticks;
if(!GetConnection()||!M2C_FIELD(GetConnection(),s32 *,416))return 1;
if(func_02038f6c()==5&&M2C_FIELD(GetConnection(),s32 *,416)==1&&peer==M2C_FIELD(GetConnection(),s32 *,244))func_02042ad0();
switch(type){
case 1:case 11:
if(M2C_FIELD(GetConnection(),u8 *,21)){a=payload[1];b=(u16)payload[2];}
count=ConnectionHandleJoin(peer,a,b,payload[0],type==11);
if(count==2){
M2C_FIELD(GetConnection(),s32 *,476)=0;func_0204063c(peer,a,b);if(func_0204084c())return 0;
if(M2C_FIELD(GetConnection(),u8 *,21)==2&&M2C_FIELD(GetConnection(),s32 *,1132)){p=GetConnection();i=func_0203aeb4(peer);M2C_FIELD(p,void (**)(s32,s32),1132)(i,M2C_FIELD(GetConnection(),s32 *,1136));}
packet[0]=M2C_FIELD(GetConnection(),u8 *,20);
for(n=1;n<=M2C_FIELD(GetConnection(),u8 *,20);n++)packet[n]=M2C_FIELD((u8 *)GetConnection()+((u32)n)*4,s32 *,244);
packet[n++]=M2C_FIELD(GetConnection(),s32 *,28);packet[n++]=M2C_FIELD(GetConnection(),u16 *,26);SetConnectionState(11);
}else if(count==3&&M2C_FIELD(GetConnection(),u8 *,22)){p=GetConnection();if(M2C_FIELD(p,u8 *,20)==M2C_FIELD(GetConnection(),u8 *,22)&&M2C_FIELD(GetConnection(),u8 *,21)==2){packet[0]=16;n=1;}}
if(count!=255){func_0203f058(count,peer,a,b,packet,n);if(func_0204084c())return 0;}
break;
case 2:
if(M2C_FIELD(GetConnection(),s32 *,416)!=4||M2C_FIELD(GetConnection(),s32 *,516)!=peer)break;
M2C_FIELD(GetConnection(),s32 *,520)=0;M2C_FIELD(GetConnection(),u8 *,423)=0;M2C_FIELD(GetConnection(),s32 *,456)=0;M2C_FIELD(GetConnection(),s32 *,444)=0;
M2C_FIELD(GetConnection(),s32 *,36)=M2C_FIELD(payload+payload[0],s32 *,4);M2C_FIELD(GetConnection(),u16 *,164)=M2C_FIELD(payload+payload[0],s32 *,8);M2C_FIELD(GetConnection(),s32 *,440)=M2C_FIELD(payload+payload[0],s32 *,4);M2C_FIELD((u8 *)GetConnection()+256,u16 *,180)=M2C_FIELD(payload+payload[0],s32 *,8);
if(M2C_FIELD(GetConnection(),u8 *,21)==1){
if(func_0204183c(payload+1,payload[0])){if(M2C_FIELD(GetConnection(),u8 *,13))func_020407fc(peer,payload);}
else{func_02040dc8(peer);if(func_0204084c())return 0;TryConnectToPeer(0,0,peer);if(func_0204084c())return 0;break;}}
if(!M2C_FIELD(GetConnection(),u8 *,21)){
if(M2C_FIELD(GetConnection(),u8 *,13)){func_020407fc(peer,payload);func_020410f8();if(func_0204084c())return 0;}
SetConnectionState(6);func_0203ecb0(0,0,func_02061784(M2C_FIELD(GetConnection(),s32 *,228),0));if(func_02043184())return 0;
}else{SetConnectionState(5);if(func_02043008(func_0203ea4c(peer)))return 0;}break;
case 3:
if(M2C_FIELD(GetConnection(),s32 *,416)!=4||M2C_FIELD(GetConnection(),s32 *,516)!=peer)break;
if(count>0&&payload[0]==16){func_0203dc38(13,0);return 0;}
return func_02040cf0(M2C_FIELD(GetConnection(),s32 *,516));
case 4:
if(M2C_FIELD(GetConnection(),s32 *,416)!=4||M2C_FIELD(GetConnection(),s32 *,516)!=peer)break;
p=GetConnection();M2C_FIELD(p,u64 *,460)=func_02007004();
if((M2C_FIELD(GetConnection(),s32 *,520)&&M2C_FIELD(GetConnection(),u8 *,423)<16)||M2C_FIELD(GetConnection(),u8 *,21)==3){
M2C_FIELD(GetConnection(),s32 *,444)=1;p=GetConnection();M2C_FIELD(p,u64 *,448)=func_02007004();
if(M2C_FIELD(GetConnection(),u8 *,21)!=3){p=GetConnection();M2C_FIELD(p,u8 *,423)++;}
}else{M2C_FIELD(GetConnection(),s32 *,520)=0;M2C_FIELD(GetConnection(),u8 *,423)=0;
if(!M2C_FIELD(GetConnection(),u8 *,21)){SetConnectionState(3);M2C_FIELD(GetConnection(),s32 *,232)=1;p=GetConnection();M2C_FIELD(p,u64 *,236)=func_02007004();}
else if(M2C_FIELD(GetConnection(),u8 *,21)==1)TryConnectToPeer(1,0,0);
}break;
case 5:
if(!M2C_FIELD(GetConnection(),u8 *,23)||M2C_FIELD(GetConnection(),s32 *,32)!=peer)break;
if(M2C_FIELD(GetConnection(),u8 *,21)==2&&M2C_FIELD(GetConnection(),u8 *,13)==1&&M2C_FIELD(GetConnection(),s32 *,248)==peer)func_0205afec(M2C_FIELD(M2C_FIELD(GetConnection(),void * *,4),s32 *,0));
if(!func_02040e1c(peer))return 0;break;
case 6:
i=payload[0];j=(u16)payload[1];
if(M2C_FIELD(GetConnection(),s32 *,416)==1)SetConnectionState(6);
else if((M2C_FIELD(GetConnection(),s32 *,416)!=6&&M2C_FIELD(GetConnection(),s32 *,416)!=11)||M2C_FIELD(GetConnection(),s32 *,32)!=peer)break;
M2C_FIELD(GetConnection(),u8 *,972)=255;
p=GetConnection();if(M2C_FIELD((u8 *)p+(M2C_FIELD(GetConnection(),u8 *,13)+1)*4,s32 *,244)!=peer){p=GetConnection();M2C_FIELD((u8 *)p+(M2C_FIELD(GetConnection(),u8 *,13)+1)*4,s32 *,244)=peer;}
M2C_FIELD(raw,u32 *,4)=i;M2C_FIELD(raw,u16 *,2)=((j>>8)&255)|((j<<8)&0xff00);
M2C_FIELD(GetConnection(),u8 *,404)=1;i=func_0205b048(M2C_FIELD(M2C_FIELD(GetConnection(),void * *,4),s32 *,0));p=GetConnection();func_02043e10(0,i,raw,(u8 *)p+404);
p=GetConnection();M2C_FIELD(p,s32 *,396)=0;M2C_FIELD(p,s32 *,400)=0;
break;
case 7:
if(M2C_FIELD(GetConnection(),s32 *,416)!=1||M2C_FIELD(GetConnection(),s32 *,244)!=peer)break;
packet0=payload[0];j=(u8)payload[1];
if(M2C_FIELD(GetConnection(),u8 *,21)==1&&!M2C_FIELD(GetConnection(),u8 *,422)){packet[0]=IsConnectionMember(packet0);func_0203f058(32,peer,a,b,packet,1);if(func_0204084c())return 0;}
p=GetConnection();i=M2C_FIELD(GetConnection(),u8 *,20)+1;M2C_FIELD((u8 *)p+i*4,s32 *,244)=packet0;
p=GetConnection();i=M2C_FIELD(GetConnection(),u8 *,20)+1;M2C_FIELD((u8 *)p+i,u8 *,720)=j;
func_0205ea70(M2C_FIELD(GetConnection(),s32 *,16));
if(M2C_FIELD(GetConnection(),s32 *,1132)){p=GetConnection();i=func_0203aeb4(packet0);M2C_FIELD(p,void (**)(s32,s32),1132)(i,M2C_FIELD(GetConnection(),s32 *,1136));}break;
case 8:
if(M2C_FIELD(GetConnection(),s32 *,416)!=1||M2C_FIELD(GetConnection(),s32 *,244)!=peer)break;
packet0=payload[0];
if(!packet0){
count=payload[1];n=payload[2];M2C_FIELD((void *)(count+(u32)GetConnection()),u8 *,720)=n;
p=GetConnection();M2C_FIELD((u8 *)p+count*4,s32 *,244)=M2C_FIELD(GetConnection(),s32 *,512);func_020411dc(3);
}else{
count=payload[1];n=(u8)payload[2];
if(packet0==M2C_FIELD((u8 *)GetConnection()+count*4,s32 *,244)&&count==M2C_FIELD(GetConnection(),u8 *,13)-1){
p=GetConnection();q=GetConnection();func_0203f058(9,peer,M2C_FIELD(p,s32 *,36),M2C_FIELD(q,u16 *,164),&packet0,1);if(func_0204084c())return 0;
}else{
M2C_FIELD((u8 *)GetConnection()+count*4,s32 *,244)=packet0;
M2C_FIELD((void *)(count+(u32)GetConnection()),u8 *,720)=n;
M2C_FIELD((u8 *)GetConnection()+count*4,s32 *,36)=payload[3];
M2C_FIELD((u8 *)GetConnection()+count*2,u16 *,164)=payload[4];
M2C_FIELD(GetConnection(),s32 *,440)=payload[3];M2C_FIELD((u8 *)GetConnection()+256,u16 *,180)=payload[4];
SetConnectionState(5);if(func_02043008(func_0203ea4c(packet0)))return 0;M2C_FIELD(GetConnection(),s32 *,456)=0;M2C_FIELD(GetConnection(),s32 *,444)=0;
}}
break;
case 9:
if(M2C_FIELD(GetConnection(),s32 *,416)!=13)break;
p=GetConnection();if(payload[0]!=M2C_FIELD((u8 *)p+(M2C_FIELD(GetConnection(),u8 *,420)+1)*4,s32 *,244))break;
p=GetConnection();M2C_FIELD(p,u8 *,420)++;func_020411dc(0);break;
case 10:
if(M2C_FIELD(GetConnection(),s32 *,416)!=1&&M2C_FIELD(GetConnection(),s32 *,416)!=18)break;
if(!M2C_FIELD(GetConnection(),u8 *,21)||func_0204183c(payload+1,payload[0])){M2C_FIELD(GetConnection(),s32 *,520)=payload[1];M2C_FIELD(GetConnection(),u8 *,423)=0;}else M2C_FIELD(GetConnection(),s32 *,520)=0;
if(M2C_FIELD(GetConnection(),u8 *,13))func_0205afec(M2C_FIELD(M2C_FIELD(GetConnection(),void * *,4),s32 *,0));else if(func_02041d14())return 0;
break;
case 12:
if(M2C_FIELD(GetConnection(),s32 *,244)!=peer)break;
if(!M2C_FIELD(GetConnection(),u8 *,21)||M2C_FIELD(GetConnection(),u8 *,21)==1){if(!func_02041038(peer))return 0;}
else if(M2C_FIELD(GetConnection(),u8 *,21)==3){M2C_FIELD(GetConnection(),s32 *,524)=peer;func_02041e44();func_02041be0(0);}
break;
case 13:case 14:case 15:if(!func_02042390(peer,type,payload[0]))return 0;break;
case 16:
if(M2C_FIELD(GetConnection(),s32 *,244)!=peer)return 1;
for(a=0;a<count;a++){i=func_02042a08(payload[a],0);if(i!=255)func_02038de4(i);}break;
case 17:p=gConnectionMgr;
if(p&&M2C_FIELD(p,u8 *,0)){ticks=func_02007004()-M2C_FIELD(p,u64 *,16);if(func_02072088((u64)ticks<<6,0x82ea)>=M2C_FIELD(p,u32 *,4)){packet[0]=1;goto timer_ready;}}
packet[0]=0;
timer_ready:func_0203f058(18,peer,a,b,packet,1);if(func_0204084c())return 0;break;
case 18:
if(M2C_FIELD(GetConnection(),s32 *,416)!=19)break;
i=func_02042a08(peer,0);if(i==255)break;
M2C_FIELD(gConnectionMgr,u32 *,8)|=1<<i;if(payload[0])M2C_FIELD(gConnectionMgr,u32 *,12)|=1<<i;break;
case 19:func_0203dc38(12,0);return 0;
case 32:
if(M2C_FIELD(GetConnection(),u8 *,21)!=1||M2C_FIELD(GetConnection(),u8 *,422))break;
for(n=1;n<=M2C_FIELD(GetConnection(),u8 *,13);n++){
if(M2C_FIELD((u8 *)GetConnection()+((u32)n)*4,s32 *,244)==peer){
if(!payload[0]){
if(M2C_FIELD(GetConnection(),s32 *,416)==11||M2C_FIELD(GetConnection(),s32 *,416)==12){func_02041b0c();if(func_0204084c())return 0;}
if(M2C_FIELD(GetConnection(),s32 *,412)){func_0205df50(M2C_FIELD(GetConnection(),s32 *,412));M2C_FIELD(GetConnection(),s32 *,412)=0;}
func_02041ce0();
}else{p=GetConnection();i=func_02042a08(peer,0);M2C_FIELD(p,u32 *,476)|=1<<i;}
goto done;
}}
break;
case 64:
for(n=1;n<=M2C_FIELD(GetConnection(),u8 *,13);n++){
if(M2C_FIELD((u8 *)GetConnection()+((u32)n)*4,s32 *,244)==peer){n=0;func_0203f058(65,peer,a,b,0,0);if(func_0204084c())return 0;break;}
}break;
case 65:break;
default:break;
}
done:return 1;
}
