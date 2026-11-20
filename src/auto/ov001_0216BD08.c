/* 32 functions from 0x0216BD08 to 0x0216CCE0 (ov001), found by ds-decomp. */
#pragma ipa off
#include "common.h"
#include "ov001_room.h"
extern unsigned char data_ov001_0218fd40[];
extern unsigned char data_ov001_0218fdb0[];
typedef struct PacketWork { signed char a; short b,c; unsigned short pad; unsigned char type,zero; short len; int value; } PacketWork;
extern unsigned char gOv001RoomPlayerData[];
extern unsigned char gOv001RoomRecords[];
typedef struct CipherState { unsigned int i, j; unsigned char *s; unsigned int n; } CipherState;
extern unsigned char gRoomState[];
extern signed char data_ov001_02191820[];
extern short gOv001CryptSeed;
extern unsigned char gOv001CryptKeyTail[118];

#pragma thumb on
/* State-1 handler of the multiplayer room protocol: accept only a room-data
 * packet addressed to this player, report the status of a failed request, else
 * unpack the room records and move on to state 2 once a requested group arrived. */
int Ov001_HandleRoomData(int state,unsigned char *packet,int *failures,unsigned char *session) {
 int func_ov001_0216c098(); int Ov001SwapEndian16(unsigned short); int func_ov001_0216cec8(int);
 void Ov001_SetRoomError(int); void Ov001MemClear(); int func_ov001_0216c400();
 unsigned char *header,*chunk;
 if(state!=1) {++*failures;return state;}
 header=packet+OV001_PKT_PREFIX;chunk=packet+OV001_PKT_PREFIX+OV001_PKT_HEADER;
 if(func_ov001_0216c098(session+8,header+OV001_PKT_TOKEN)<0) {++*failures;return state;}
 if(Ov001SwapEndian16(*(unsigned short *)(chunk+OV001_CHUNK_LENGTH))==0) {++*failures;return state;}
 if(*chunk==OV001_CHUNK_ERROR) {
 if(func_ov001_0216cec8(*(int *)(chunk+OV001_CHUNK_STATUS))==-2) Ov001_SetRoomError(20);
 else if(func_ov001_0216cec8(*(int *)(chunk+OV001_CHUNK_STATUS))==-3) Ov001_SetRoomError(21);
 else Ov001_SetRoomError(24);
 return -1;
 }
 Ov001MemClear(gOv001RoomPlayerData,0,OV001_ROOM_PLAYER_DATA_SIZE);
 if(func_ov001_0216c400(0,chunk,Ov001SwapEndian16(*(unsigned short *)(header+OV001_PKT_LENGTH)),gOv001RoomPlayerData,gOv001RoomRecords)<0) {++*failures;return state;}
 if(!(*(int *)(gRoomState+48)&*(int *)(gRoomState+44))) return state;
 *failures=0;return 2;
}

#pragma thumb on
/* State-2 handler of the room protocol: a room-request result must answer this
 * player's request, carry the error chunk kind and a non-zero chunk length; the
 * status then decides the outcome: 0 means the request succeeded (100), -2 and -3
 * map to the room error codes 20 and 21 and any other status to 24, each failing
 * with -1. */
int Ov001_HandleRoomResult(int state,unsigned char *packet,int *failures,unsigned char *session) {
 int func_ov001_0216c098(); int Ov001SwapEndian16(unsigned short); int func_ov001_0216cec8(int); void Ov001_SetRoomError(int);
 unsigned char *header,*chunk;
 if(state!=2) {++*failures;return state;}
 header=packet+OV001_PKT_PREFIX;chunk=packet+OV001_PKT_PREFIX+OV001_PKT_HEADER;
 if(func_ov001_0216c098(session+16,(int)header+OV001_PKT_TOKEN)<0) {++*failures;return state;}
 if(*(unsigned char *)(chunk+OV001_CHUNK_KIND)!=OV001_CHUNK_ERROR) {++*failures;return state;}
 if(Ov001SwapEndian16(*(unsigned short *)(chunk+OV001_CHUNK_LENGTH))==0) {++*failures;return state;}
 if(func_ov001_0216cec8(*(int *)(chunk+OV001_CHUNK_STATUS))==0) return 100;
 if(func_ov001_0216cec8(*(int *)(chunk+OV001_CHUNK_STATUS))==-2) {Ov001_SetRoomError(20);return -1;}
 if(func_ov001_0216cec8(*(int *)(chunk+OV001_CHUNK_STATUS))==-3) {Ov001_SetRoomError(21);return -1;}
 Ov001_SetRoomError(24);return -1;
}

s32 func_ov001_0216c0e4(M2C_UNK arg0, M2C_UNK arg1) {
    void Ov001MemClear();
    int Ov001SwapEndian16(u16);
    void Ov001MemCopy();
    int func_ov001_0216c1a0();
    int func_ov001_0216cec8();
    extern unsigned char gRoomState[];

    M2C_UNK r4;
    M2C_UNK r5;
    M2C_UNK r6;
    M2C_UNK r7;
    s32 r2;
    u8 t;
    u16 f;
    s32 v;

    r5 = arg1;
    r6 = arg0;
    Ov001MemClear(r5, 0, 0x104);
    r7 = r5 + 0x80;
    r4 = r6;
    for (;;) {
    r2 = Ov001SwapEndian16(*(u16 *)((u8 *)r4 + 2));
    if (r2 <= 0) {
        return -1;
    }
        t = *(u8 *)r4;
        switch (t) {
        case 0:
            Ov001MemCopy(r5, (M2C_UNK)((u8 *)r4 + 6));
            break;
        case 1:
            Ov001MemCopy(r7, (M2C_UNK)((u8 *)r4 + 6));
            break;
        case 2:
            Ov001MemCopy(r5 + 0x100, (M2C_UNK)((u8 *)r4 + 6));
            break;
        case 3:
            if (Ov001SwapEndian16(*(u8 *)((u8 *)r4 + 6)) <= 0) {
                return -2;
            }
            break;
        case 4:
            v = func_ov001_0216c1a0((M2C_UNK)((u8 *)r4 + 6), r2);
            v = func_ov001_0216cec8(v);
            *(s32 *)(gRoomState + 0x34) = v;
            break;
        case 5:
            v = func_ov001_0216c1a0((M2C_UNK)((u8 *)r4 + 6), r2);
            v = func_ov001_0216cec8(v);
            *(s32 *)(gRoomState + 0x38) = v;
            break;
        case 6:
        default:
            return -1;
        }
        f = *(u16 *)((u8 *)r4 + 4);
        if (f == 0) {
            return 0;
        }
        r4 = (M2C_UNK)((u8 *)r6 + Ov001SwapEndian16(f));
    }
}

#pragma opt_lifetimes off
s32 func_ov001_0216c1a0(s32 arg0, s32 arg1) {
    s32 var_r3;
    s32 var_r4;
    u8 *var_r5;
    u8 temp_r0;

    var_r3 = 0;
    var_r5 = arg0 + (arg1 - 1);
    var_r4 = 0;
    if (arg1 > 0) {
        do {
            temp_r0 = *var_r5;
            var_r4 += 1;
            var_r5 -= 1;
            var_r3 = temp_r0 + (var_r3 << 8);
        } while (var_r4 < arg1);
    }
    return var_r3;
}
#pragma opt_lifetimes reset

#pragma thumb on
/* Walks the chunk list of one player's room data and copies its strings into
 * the per-player record: the message string (chunk 0x15/0x25, up to 33 bytes
 * with the last byte NUL) to +0x08, and four slots to +0x30/+0x70/+0xB0/+0xF0
 * holding either a 5-byte (chunk 0x10-0x13) or a 13-byte (0x20-0x23) string;
 * the slot length is stored at +0x04. Chunks chain through a big-endian offset
 * at +0x04 of each chunk until it is zero. */
s32 Ov001UnpackPlayerStrings(void *arg0,s32 arg1) {
s32 Ov001SwapEndian16(u16);
void Ov001MemCopy();
u8 *p=(u8 *)arg0+6;
u8 *out=(u8 *)arg1;
u8 *base,*text,*slot3,*slot2,*slot1,*slot0;
u32 n;
text=out;text=out+8;slot3=out;slot3=out+240;slot2=out;slot2=out+176;slot1=out;slot1=out+112;slot0=out+48;base=p;
do {
n=Ov001SwapEndian16(*(u16 *)(p+2));
switch(*p){
case 0x10:case 0x11:case 0x12:case 0x13:if(n>5)return -1;break;
case 0x20:case 0x21:case 0x22:case 0x23:if(n>13)return -1;break;
case 0x15:case 0x25:if(n>33)return -1;break;
}
switch(*p){
case 0x10:case 0x20:Ov001MemCopy(slot0,p+6,n);*(u32 *)(out+4)=n;break;
case 0x11:case 0x21:Ov001MemCopy(slot1,p+6,n);*(u32 *)(out+4)=n;break;
case 0x12:case 0x22:Ov001MemCopy(slot2,p+6,n);*(u32 *)(out+4)=n;break;
case 0x13:case 0x23:Ov001MemCopy(slot3,p+6,n);*(u32 *)(out+4)=n;break;
case 0x15:case 0x25:if(n && p[n+5])return -1;Ov001MemCopy(text,p+6,n);break;
default:return -1;
}
if(*(u16 *)(p+4)==0)break;
p=base+Ov001SwapEndian16(*(u16 *)(p+4));
}while(1);
return 0;
}

#pragma thumb on
/* Unpacks one player's chunk list into its 0x70-byte room record: the 33-byte
 * message chunk goes to the record's text, a 64-byte profile chunk to its
 * profile block (and its length to the record's length word).  Chunks chain
 * through the big-endian offset at +0x04 of each chunk until it is zero; any
 * other kind, or a length over the field's size, fails the unpack. */
int Ov001UnpackPlayerRecord(void *packet,int record) {
 int Ov001SwapEndian16(unsigned short); void Ov001MemCopy();
 unsigned char *base,*cur=(unsigned char *)packet+6,*message=(unsigned char *)record+OV001_RECORD_TEXT,*profile=(unsigned char *)record+OV001_RECORD_DATA; unsigned int n; int kind;
 base=cur;
 for (;;) {
  n=Ov001SwapEndian16(*(unsigned short *)(cur+2)); kind=*cur;
  switch(kind) { case OV001_CHUNK_PROFILE: case OV001_CHUNK_PROFILE+0x10: if(n>OV001_RECORD_DATA_MAX) return -1; break; case OV001_CHUNK_TEXT: case OV001_CHUNK_TEXT+0x10: if(n>OV001_RECORD_TEXT_MAX) return -1; break; }
  switch(kind) {
   case OV001_CHUNK_PROFILE: case OV001_CHUNK_PROFILE+0x10: Ov001MemCopy(profile,cur+6,n); *(int *)(record+4)=n; break;
   case OV001_CHUNK_TEXT: case OV001_CHUNK_TEXT+0x10: if(n && cur[n+5]) return -1; Ov001MemCopy(message,cur+6,n); break;
   default: return -1;
  }
  if (!*(unsigned short *)(cur+4)) break;
  cur=base+Ov001SwapEndian16(*(unsigned short *)(cur+4));
 }
 return 0;
}
int func_ov001_0216c3d0(unsigned char *p, void *out) {
 int Ov001SwapEndian16(unsigned short);
 void Ov001MemCopy();
 unsigned char *q = p + 6;
 int n = Ov001SwapEndian16(*(unsigned short *)(q+2));
 if (n <= 0) return -1;
 if (*q != 0x70) return -1;
 Ov001MemCopy(out,q+6,n);
 return 0;
}

#pragma thumb on
s32 func_ov001_0216c400(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
s32 Ov001UnpackPlayerStrings(void *,s32);
s32 Ov001UnpackPlayerRecord(void *,s32);
s32 Ov001SwapEndian16(u16);
s32 func_ov001_0216c3d0(u8 *,void *);
s32 sp0=arg0;
u8 *p=arg1;
s32 rem=arg2;
s32 sp4=arg3;
s32 flags=0;
u8 *q;
s32 remaining,base,result,len;
s32 sp8,spC,sp10;
if(rem<=0)return -2;
search:
q=p;
if(q[0]!=data_ov001_0218fd40[sp0]){
len=Ov001SwapEndian16(*(u16 *)(p+2))+4;
rem=rem-len;
p=p+len;
if(rem<=0)return -4;
goto search;
}
remaining=Ov001SwapEndian16(*(u16 *)(q+2));
base=sp4+0x350*sp0;
sp8=arg4;
spC=(sp0+3)<<7;
sp10=base;
sp10=sp10+8;
do {
switch(q[0]){
case 3:result=Ov001UnpackPlayerStrings(q,sp10);flags|=1;break;
case 4:result=Ov001UnpackPlayerStrings(q,base+0x138);flags|=2;break;
case 5:result=Ov001UnpackPlayerRecord(q,base+0x268);flags|=4;break;
case 6:result=Ov001UnpackPlayerRecord(q,base+0x2d8);flags|=8;break;
case 10:result=func_ov001_0216c3d0(q,(void *)(sp8+spC));break;
default:result=-3;break;
}
if(result!=0)return result;
len=Ov001SwapEndian16(*(u16 *)(q+2))+4;remaining=remaining-len;q=q+len;
}while(remaining>0);
*(s32 *)(gRoomState+0x30)|=flags;
return 0;
}
unsigned int func_ov001_0216c510(unsigned int x) { unsigned int result = 0; if (x & 0x10) result = 1; return result; }

int func_ov001_0216c520(int mode, int a, int b, int c) {
 void func_ov001_0216bc3c(int);
 int func_ov001_0216c574(int,int,int);
 int Ov001_SendRoomRequest(int,int,int);
 int func_ov001_0216c794(int,int,int);
 switch(mode) {
 case 0: func_ov001_0216bc3c(2); return func_ov001_0216c574(a,b,c);
 case 1: func_ov001_0216bc3c(3); return Ov001_SendRoomRequest(a,b,c);
 case 2: func_ov001_0216bc3c(5); return func_ov001_0216c794(a,b,c);
 default: return -1;
 }
}
