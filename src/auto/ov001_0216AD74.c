/* 14 functions from 0x0216AD74 to 0x0216BD08 (ov001), found by ds-decomp. */
#include "common.h"
#include "ov001_room.h"

#pragma thumb on
u32 func_ov001_0216b87c(u32 a,u32 b) {u32 t=a&b; b=~b; a=((a&b)+1)|t; if(a>=(b|t)) a=1|t; return a;}

void func_ov001_0216b894(void) {
extern u32 gRoomState[];
void func_ov001_0216ad64(u32);
if(gRoomState[3]) {func_ov001_0216ad64(gRoomState[3]);gRoomState[3]=0;}
if(gRoomState[1]) {func_ov001_0216ad64(gRoomState[1]);gRoomState[1]=0;}
}

#pragma thumb on
/* Builds the room-setup packet at session+0x117 from the decoded player
 * records: four 5-char and four 13-char player names, the two team texts and
 * two single extra records, each block only if its bit is set in
 * gRoomState's request/received mask (+0x2C & +0x30).  On an invalid string
 * the packet is cleared and -1 is returned.
 * Packet layout (0x154 bytes): teamANames[4][6], teamAText[33],
 * teamBNames[4][14], teamBText[33], record5Name[64], record5Text[33],
 * record6Name[64], record6Text[33]. */
s32 BuildRoomSetupPacket(void *session) {
  M2C_UNK Ov001MemCopy(void *,M2C_UNK *,s32);
  M2C_UNK Ov001MemClear(void *,s32,s32);
  s32 Ov001StringLength(M2C_UNK *);
  s32 IsPrintableString(u8 *,s32);
  extern u32 gRoomState[];
  extern Ov001PlayerRecord gRoomTeamA,gRoomTeamB,gRoomRecord5,gRoomRecord6;
  Ov001PlayerRecord *record5=&gRoomRecord5;
  u8 *dst=(u8 *)session+0x117;
  Ov001PlayerRecord *record6;
  Ov001PlayerRecord *teamA=&gRoomTeamA;
  Ov001PlayerRecord *teamB=&gRoomTeamB;
  record6=&gRoomRecord6;
  if(dst==0)return -1;
  M2C_FIELD(session,u16 *,0)=gRoomState[11]&gRoomState[12];
  Ov001MemClear(dst,0,0x154);
 if(M2C_FIELD(session,u16 *,0)&1) {
  Ov001MemCopy(dst+0,(M2C_UNK *)teamA->name[0],teamA->length);
  Ov001MemCopy(dst+6,(M2C_UNK *)teamA->name[1],teamA->length);
  Ov001MemCopy(dst+12,(M2C_UNK *)teamA->name[2],teamA->length);
  Ov001MemCopy(dst+18,(M2C_UNK *)teamA->name[3],teamA->length);
  if(IsPrintableString((u8 *)teamA->text,Ov001StringLength(teamA->text)))goto fail;
  Ov001MemCopy(dst+24,(M2C_UNK *)teamA->text,Ov001StringLength(teamA->text));
 }
 if(M2C_FIELD(session,u16 *,0)&2) {
  Ov001MemCopy(dst+57,(M2C_UNK *)teamB->name[0],teamB->length);
  Ov001MemCopy(dst+71,(M2C_UNK *)teamB->name[1],teamB->length);
  Ov001MemCopy(dst+85,(M2C_UNK *)teamB->name[2],teamB->length);
  Ov001MemCopy(dst+99,(M2C_UNK *)teamB->name[3],teamB->length);
  if(IsPrintableString((u8 *)teamB->text,Ov001StringLength(teamB->text)))goto fail;
  Ov001MemCopy(dst+113,(M2C_UNK *)teamB->text,Ov001StringLength(teamB->text));
 }
 if(M2C_FIELD(session,u16 *,0)&4) {
  if(IsPrintableString((u8 *)record5->name[0],record5->length-1))goto fail;
  Ov001MemCopy(dst+146,(M2C_UNK *)record5->name[0],record5->length);
  if(IsPrintableString((u8 *)record5->text,Ov001StringLength(record5->text)))goto fail;
  Ov001MemCopy(dst+210,(M2C_UNK *)record5->text,Ov001StringLength(record5->text));
 }
 if(M2C_FIELD(session,u16 *,0)&8) {
  if(IsPrintableString((u8 *)record6->name[0],record6->length-1))goto fail;
  Ov001MemCopy(dst+243,(M2C_UNK *)record6->name[0],record6->length);
  if(IsPrintableString((u8 *)record6->text,Ov001StringLength(record6->text)))goto fail;
  Ov001MemCopy(dst+307,(M2C_UNK *)record6->text,Ov001StringLength(record6->text));
 }
 M2C_FIELD(session,u8 *,0x116)=0;return 0;
 fail:Ov001MemClear(dst,0,0x154);return -1;
}
s32 IsPrintableString(u8 *p,s32 n) {s32 i; for(i=0;i<n;i++){u32 c=*p++;if(c<32||c>127)return -1;}return 0;}

#pragma scheduling off
s32 func_ov001_0216bb4c(u32 *arg0) {
s32 func_ov001_0216cdb4(void *,M2C_UNK *,s32);
s32 func_ov001_0216cf08(M2C_UNK *);
extern M2C_UNK gBuiltinWifiSsid;
s32 result; u32 n;
s32 matches;
s32 i;
u8 *p; u8 *text;
p=(u8 *)arg0; n=*(u32 *)p; result=0; matches=result;
if(n==0)return 5;
if(n>64)n=64;
i=0;
if((s32)n>0) {
text=p+8;
do {
if((M2C_FIELD(p,u32 *,0x54)&1) && M2C_FIELD(p,s32 *,4)==func_ov001_0216cf08(&gBuiltinWifiSsid) && !func_ov001_0216cdb4(text,&gBuiltinWifiSsid,func_ov001_0216cf08(&gBuiltinWifiSsid)))matches++;
p+=0x54;text+=0x54;i++;
}while(i<(s32)n);
}
if(matches>1)result=4;
if(matches==0)result=5;
return result;
}
#pragma scheduling reset
/* Fill `ap` with the built-in access point: the SSID gBuiltinWifiSsid and its WEP
 * key gBuiltinWifiKey, failing when the key is longer than WIFI_AP_KEY_MAX bytes. */
s32 InitBuiltinWifiAp(void *ap) {
extern M2C_UNK gBuiltinWifiSsid;
extern M2C_UNK gBuiltinWifiKey;
s32 Ov001StringLength(M2C_UNK *);
M2C_UNK Ov001MemCopy(void *,M2C_UNK *,s32);
u32 keyLength;
M2C_FIELD(ap,u32 *,WIFI_AP_SSID_LENGTH)=Ov001StringLength(&gBuiltinWifiSsid);
Ov001MemCopy((u8 *)ap+WIFI_AP_SSID,&gBuiltinWifiSsid,M2C_FIELD(ap,u32 *,WIFI_AP_SSID_LENGTH));
M2C_FIELD(ap,u32 *,WIFI_AP_SECURITY)=1;
keyLength=M2C_FIELD(ap,u32 *,WIFI_AP_KEY_LENGTH)=Ov001StringLength(&gBuiltinWifiKey);
if(keyLength>WIFI_AP_KEY_MAX)return -1;
Ov001MemCopy((u8 *)ap+WIFI_AP_KEY,&gBuiltinWifiKey,keyLength);
return 0;
}
void func_ov001_0216bc0c(s32 n,void *p,M2C_UNK *src) {
M2C_UNK Ov001MemCopy(void *,M2C_UNK *,s32);
u16 Ov001SwapEndian16Alt(u16);
u16 Ov001GetRandomSeed(void);
s32 i;
for(i=0;i<n;i++,p=(u8 *)p+8) {
Ov001MemCopy(p,src,6);
M2C_FIELD(p,u16 *,6)=Ov001GetRandomSeed();
M2C_FIELD(p,u16 *,6)=Ov001SwapEndian16Alt(M2C_FIELD(p,u16 *,6));
}
}

/* Top-level dispatcher of the ov001 room protocol's packets: a packet must carry a
 * non-zero header marker, be a room-protocol packet (kind 17) and pass the room
 * request check; its command then picks the handler for the session's state
 * (0x1010 the room setup, 0x2010 the room data, 0x3010 a room request's result).
 * A rejected packet counts as a failure and the state is left alone. */
s32 Ov001_DispatchRoomPacket(s32 state,void *packet,s32 *failures,s32 session) {
s32 Ov001_HandleRoomSetup(s32,void *,s32 *,s32);
s32 Ov001_HandleRoomData(s32,void *,s32 *,s32);
s32 Ov001_HandleRoomResult(s32,void *,s32 *,s32);
s32 Ov001_HandleRoomRequest(void *);
u32 Ov001SwapEndian16(u16);
void *header=(u8 *)packet+OV001_PKT_PREFIX;
if(Ov001SwapEndian16(M2C_FIELD(packet,u16 *,OV001_PKT_PREFIX))<1U){++*failures;return state;}
if(M2C_FIELD(header,u8 *,OV001_PKT_KIND)!=OV001_PKT_KIND_ROOM){++*failures;return state;}
if(Ov001_HandleRoomRequest((u8 *)packet+OV001_PKT_PREFIX)>0){++*failures;return state;}
switch(Ov001SwapEndian16(M2C_FIELD(header,u16 *,OV001_PKT_COMMAND))) {
case 0x1010:state=Ov001_HandleRoomSetup(state,packet,failures,session);break;
case 0x2010:state=Ov001_HandleRoomData(state,packet,failures,session);break;
case 0x3010:state=Ov001_HandleRoomResult(state,packet,failures,session);break;
}
return state;
}
#pragma thumb off

#pragma thumb off

