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
extern short data_ov001_02192568;
extern unsigned char data_ov001_0219256a[118];

#pragma thumb on
/* State-1 handler of the multiplayer room protocol: accept only a room-data
 * packet addressed to this player, report the status of a failed request, else
 * unpack the room records and move on to state 2 once a requested group arrived. */

#pragma thumb on

#pragma opt_lifetimes off

#pragma opt_lifetimes reset

#pragma thumb on
/* Walks the chunk list of one player's room data and copies its strings into
 * the per-player record: the message string (chunk 0x15/0x25, up to 33 bytes
 * with the last byte NUL) to +0x08, and four slots to +0x30/+0x70/+0xB0/+0xF0
 * holding either a 5-byte (chunk 0x10-0x13) or a 13-byte (0x20-0x23) string;
 * the slot length is stored at +0x04. Chunks chain through a big-endian offset
 * at +0x04 of each chunk until it is zero. */

#pragma thumb on

#pragma thumb on

void func_ov001_0216c88c(int mode, unsigned char *p, int a, short *n, short *out, int b) {
 int func_ov001_0216c9a0();
 void Ov001MemCopy();
 short func_ov001_0216ceb0(unsigned short);
 extern unsigned char data_ov001_02192560[8];
 if(mode == 1) {
 *out = 1;
 func_ov001_0216c9a0(a,p+4,*n,b,p+2,data_ov001_02192560,8);
 *(short *)p = func_ov001_0216ceb0((unsigned short)*n);
 *n += 4;
 return;
 }
 Ov001MemCopy(p,a,*n);
}

void func_ov001_0216c8e0(unsigned short *p,int a,int b,int c,signed char d,signed char e,void *f) {
 short func_ov001_0216ceb0(unsigned short);
 void Ov001MemCopy();
 p[0]=func_ov001_0216ceb0(1); p[1]=0; p[2]=0;
 p[3]=func_ov001_0216ceb0((unsigned short)a); p[4]=0;
 p[5]=func_ov001_0216ceb0((unsigned short)b);
 p[6]=func_ov001_0216ceb0((unsigned short)c);
 ((signed char *)p)[14]=d; ((signed char *)p)[15]=e;
 Ov001MemCopy(p+8,f,8);
}

void func_ov001_0216c938(int a,int b,int c,int d) {
 void Ov001MemClear();
 void func_ov001_0216ce58();
 int Ov001SwapEndian32(int);
 short func_ov001_0216ceb0(unsigned short);
 int packet[2];
 Ov001MemClear(packet,0,8);
 ((char *)packet)[1]=2;
 ((short *)packet)[1]=func_ov001_0216ceb0(0x5790);
 packet[1]=Ov001SwapEndian32(*(int *)(gRoomState+0x34));
 if(c==255 || data_ov001_02191820[0x1c]==0) packet[1]=-1;
 func_ov001_0216ce58(d,a,b,0,packet,8);
}

#pragma thumb on
int func_ov001_0216c9a0(int a,int b,int c,signed char *d,void *e,void *f,int g) {
 int func_ov001_0216ad54(int); void func_ov001_0216ad64(int);
 void func_ov001_0216caa4(); void func_ov001_0216cb08();
 int func_ov001_0216cb74(int,int); short func_ov001_0216cf1c(void); void Ov001MemCopy();
 int handle; int packet[4]; short seed;
 *d=func_ov001_0216cb74(a,c); handle=func_ov001_0216ad54(c); packet[2]=handle;
 if(!handle) return -1;
 seed=func_ov001_0216cf1c(); Ov001MemCopy(e,&seed,2);
 Ov001MemCopy(&data_ov001_02192568,e,2);
 Ov001MemCopy(data_ov001_0219256a,f,g);
 func_ov001_0216caa4(packet,&data_ov001_02192568,g+2,c);
 func_ov001_0216cb08(packet,b,a,c); func_ov001_0216ad64(packet[2]); return 0;
}

#pragma thumb on
int func_ov001_0216ca1c(int a,int b,int c,unsigned int d,void *e,void *f,int g) {
 int func_ov001_0216ad54(int); void func_ov001_0216ad64(int); void func_ov001_0216b918(int);
 void func_ov001_0216caa4(); void func_ov001_0216cb08(); int func_ov001_0216cb74(int,int); void Ov001MemCopy();
 int packet[4]; int h=func_ov001_0216ad54(c); packet[2]=h;
 if(!h) {func_ov001_0216b918(2); return -1;}
 Ov001MemCopy(&data_ov001_02192568,e,2);
 Ov001MemCopy(data_ov001_0219256a,f,g);
 func_ov001_0216caa4(packet,&data_ov001_02192568,g+2,c);
 func_ov001_0216cb08(packet,b,a,c);
 if((int *)func_ov001_0216cb74(b,c)!=(int *)d) {
 func_ov001_0216b918(0x12); func_ov001_0216ad64(packet[2]); return -1;
 }
 func_ov001_0216ad64(packet[2]); return 0;
}
void func_ov001_0216caa4(CipherState *st,unsigned char *key,unsigned int len,unsigned int n) {
 unsigned char *s=st->s; unsigned int i,j,k; unsigned char t,u;
 st->j=0; st->i=0; st->n=n;
 for(i=0;i<n;i++) s[i]=i;
 j=0;k=0;
 for(i=0;i<n;i++) {
 t=s[i]; j=(j+key[k]+t)%st->n;
 u=s[j]; s[j]=t; s[i]=u;
 k++; if(k>=len) k=0;
 }
}

#pragma thumb on
unsigned int func_ov001_0216cb34(CipherState *st) {
 unsigned int n=st->n; unsigned char *s=st->s;
 unsigned char i=(st->i+1)%n;
 unsigned char a=s[i];
 unsigned char j=(a+st->j)%n;
 unsigned char b=s[j];
 st->i=i; st->j=j; s[j]=a; s[i]=b;
 return s[(a+b)%st->n];
}
#pragma thumb off

#pragma thumb on
unsigned int func_ov001_0216cb9c(unsigned int crc,unsigned char *p,int n,int ready,unsigned int *table) {
 void func_ov001_0216cbd4(int,unsigned int *);
 int i;
 if(!ready) func_ov001_0216cbd4(ready,table);
 for(i=0;i<n;i++) crc=(crc>>8)^table[(unsigned char)(p[i]^crc)];
 return crc;
}

int func_ov001_0216cc0c(void *p,int n,void *key,int len) {
 int func_ov001_0216ad54(int);
 void func_ov001_0216ad64(int);
 void func_ov001_0216cce0();
 void func_ov001_0216cc88(int,signed char *,int,signed char *,int);
 void func_ov001_0216ccbc(signed char *,unsigned char *,int);
 int a; int b; int i;
 a=func_ov001_0216ad54(n/2);
 if(!a) return -1;
 b=func_ov001_0216ad54(n);
 if(!b) { func_ov001_0216ad64(a); return -1; }
 for(i=0;i<2;i++) {
 func_ov001_0216cc88(i,(signed char *)a,n,key,len);
 func_ov001_0216ccbc((signed char *)a,p,n);
 func_ov001_0216cce0(p,n,b);
 }
 func_ov001_0216ad64(a); func_ov001_0216ad64(b); return 0;
}

#pragma thumb on
void func_ov001_0216cc88(int a,signed char *out,int n,signed char *key,int len) {
 int half=n/2; int j=a%len; int i;
 for(i=0;i<half;i++) {
 out[i]=i; out[i]^=key[j]; j++;
 if(j>=len) j=0;
 }
}
#pragma thumb on
void func_ov001_0216ccbc(signed char *a,unsigned char *b,int n) {
 int i; int half=n/2;
 for(i=0;i<half;i++) { b[half+i] ^= a[i]; }
}
#pragma thumb off
