/* 10 functions from 0x02226D9C to 0x02227D34 (ov010), found by ds-decomp. */
#include "common.h"
typedef struct { u32 magic; u8 kind; u8 channel:4; u8 flags:4; u16 id; u32 size; } Ov010Packet;
typedef struct { u8 bytes[26]; u16 count0, count1, count2; s8 state0, state1, state2; u8 pad[5]; } Ov010Entry;
typedef struct { u8 pad[0x2d4]; Ov010Entry entries[1]; } Ov010State;
extern unsigned char data_ov010_0222f02c[];

extern M2C_UNK data_ov010_0222eee0;

static inline void QueuePop26d9c(void *packet){
void func_ov010_0222959c(void *,u32,u32,u32,void *,u32,u32);void func_ov010_02226908(s32,void *,u32);
u32 saved=*(volatile u16 *)0x4000208;u8 *node;
*(volatile u16 *)0x4000208=0;
node=M2C_FIELD(&data_ov010_0222eee0,void **,0x60);
if(!node){u32 old=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;return;}
{Ov010Packet *h=(Ov010Packet *)(node+4);
func_ov010_0222959c(packet,h->kind,h->channel,h->flags,node+16,M2C_FIELD(node,u32 *,12),M2C_FIELD(node,u16 *,10));}
{void *next=M2C_FIELD(node,void **,0);M2C_FIELD(&data_ov010_0222eee0,void **,0x60)=next;
if(!next)M2C_FIELD(&data_ov010_0222eee0,void **,0x64)=0;}
func_ov010_02226908(0,node,M2C_FIELD(node,u32 *,12)+16);
M2C_FIELD(&data_ov010_0222eee0,u32 *,0x68)--;
{u32 old=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;}
}


static inline u32 PacketSize26d9c(Ov010Packet *p){Ov010Packet h=*p;return h.size;}
static inline u32 PacketChannel26d9c(Ov010Packet *p){Ov010Packet h=*p;return h.channel;}
static inline u32 PacketFlags26d9c(Ov010Packet *p){Ov010Packet h=*p;return h.flags;}
static inline u32 PacketId26d9c(Ov010Packet *p){Ov010Packet h=*p;return h.id;}

static inline u32 QueueCount26d9c(void){
u32 saved=*(volatile u16 *)0x4000208;u32 n;
*(volatile u16 *)0x4000208=0;
if(!M2C_FIELD(&data_ov010_0222eee0,void **,0x60)){u32 old=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;return 0;}
{u32 old=*(volatile u16 *)0x4000208;n=M2C_FIELD(&data_ov010_0222eee0,u32 *,0x68);*(volatile u16 *)0x4000208=saved;}return n;
}
static inline u16 QueueMask26d9c(void){
u32 saved=*(volatile u16 *)0x4000208;void *p;u16 n;
*(volatile u16 *)0x4000208=0;p=M2C_FIELD(&data_ov010_0222eee0,void **,0x60);
if(!p){u32 old=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;return 0;}
n=M2C_FIELD(p,u16 *,10);{u32 old=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;}return n;
}
static inline u32 QueuePayload26d9c(void){
u32 saved=*(volatile u16 *)0x4000208;void *p;u32 n;
*(volatile u16 *)0x4000208=0;p=M2C_FIELD(&data_ov010_0222eee0,void **,0x60);
if(!p){u32 old=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;return 0;}
{u32 old=*(volatile u16 *)0x4000208;n=M2C_FIELD(p,u32 *,12);*(volatile u16 *)0x4000208=saved;}return n;
}
static inline u32 QueueSize26d9c(void){
u32 saved=*(volatile u16 *)0x4000208;u32 n;
*(volatile u16 *)0x4000208=0;
if(!M2C_FIELD(&data_ov010_0222eee0,void **,0x60)){u32 old=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;return 0;}
n=QueuePayload26d9c()+12;{u32 old=*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;}return n;
}


static inline u32 RxQueueSize26d9c(u8 **entry){
extern u8 data_ov010_0222ef58[];
u32 oldIme,tempIme,result;
oldIme=*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=0;

if(!*entry){(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=oldIme;return 0;}
tempIme=*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=0;
if(!*entry){(void)*(volatile u16 *)0x4000208;result=0;*(volatile u16 *)0x4000208=tempIme;}
else{result=*(volatile u16 *)0x4000208;result=((Ov010Packet *)((u8 *)*entry+4))->size;*(volatile u16 *)0x4000208=tempIme;}
result+=12;
(void)*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=oldIme;
return result;
}

static inline void RxQueuePop26d9c(u8 *entry,void *buf){
extern u8 data_ov010_0222ef58[];
void func_ov010_02226908(s32,void *,u32);
void func_ov010_0222959c(void *,u32,u32,u32,void *,u32,u32);
Ov010Packet *h;
void *node;
u32 saved;
saved=*(volatile u16 *)0x4000208;

*(volatile u16 *)0x4000208=0;
node=M2C_FIELD(entry,void **,0);
if(!node){(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;return;}
h=(Ov010Packet *)((u8 *)node+4);
func_ov010_0222959c(buf,h->kind,h->channel,h->flags,(u8 *)node+0x10,h->size,h->id);
{void *next=M2C_FIELD(node,void **,0);
M2C_FIELD(entry,void **,0)=next;
if(!next)M2C_FIELD(entry,void **,4)=0;}
func_ov010_02226908(0,node,h->size+0x10);
M2C_FIELD(entry,s32 *,8)--;
(void)*(volatile u16 *)0x4000208;
*(volatile u16 *)0x4000208=saved;
}

static inline void RxQueuePush26d9c(Ov010Packet *h,u32 channel,u8 *queues) {
void *func_ov010_022268f4(s32,u32,u32);void MI_CpuFill8(void *,s32,u32);
void func_ov010_0222959c(void *,u32,u32,u32,void *,u32,u32);
volatile u32 saved=*(volatile u16 *)0x4000208;void *node;u8 *entry;void *head;
*(volatile u16 *)0x4000208=0;
node=func_ov010_022268f4(0,h->size+16,32);
if(!node){(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;return;}
MI_CpuFill8(node,0,16);
func_ov010_0222959c((u8 *)node+4,h->kind,h->channel,h->flags,(u8 *)h+12,h->size,h->id);
entry=queues+channel*12;head=M2C_FIELD(entry,void **,0);
if(!head){M2C_FIELD(entry,void **,4)=node;M2C_FIELD(entry,void **,0)=node;}
else{M2C_FIELD(node,void **,0)=head;M2C_FIELD(queues+channel*12,void **,0)=node;}
M2C_FIELD(entry,u32 *,8)++;
(void)*(volatile u16 *)0x4000208;*(volatile u16 *)0x4000208=saved;
}

#pragma opt_common_subs off
void func_ov010_02226d9c(void *a){
s32 func_ov010_022282b4(s32);s32 func_ov010_02229a08();s32 func_ov010_02229a24();s32 func_0204428c(u8); void *func_ov010_02229568(u32);M2C_UNK func_ov010_02229580(s32);void func_ov010_0222959c(void *,u32,u32,u32,void *,u32,u32);void func_ov010_02226908(s32,void *,u32);
void func_ov010_02227934(s32,s32);void func_ov010_02227954(s32,void *,s32);M2C_UNK func_01ffa6fc(void *);
extern M2C_UNK data_ov010_0222eee0;
u32 n; s32 i,self; register u32 one; Ov010Packet *p;
if(!func_ov010_022282b4(3))return;
self=func_ov010_02229a08();
if(!M2C_FIELD(a,void **,0x38)){
if(!QueueCount26d9c())return;
}
if(M2C_FIELD(a,void **,0x38)){
M2C_FIELD(a,u16 *,0x44)=M2C_FIELD(M2C_FIELD(a,void **,0x38),u16 *,6);
M2C_FIELD(a,u16 *,0x44)&=func_ov010_02229a24();
for(i=0;i<4;i++)if(self!=i && (M2C_FIELD(a,u16 *,0x44)&(1<<i))){if(!func_0204428c((u8)i))return;}
if(M2C_FIELD(a,u32 *,0x34)!=((Ov010Packet *)M2C_FIELD(a,void **,0x38))->size){
{Ov010Packet header=*(Ov010Packet *)M2C_FIELD(a,void **,0x38); n=header.size;}
n=n-M2C_FIELD(a,u32 *,0x34);if(n>0x594)n=0x594;
p=func_ov010_02229568(n+12);
{Ov010Packet *h=M2C_FIELD(a,void **,0x38);
func_ov010_0222959c(p,5,h->channel,h->flags,(u8 *)M2C_FIELD(a,void **,0x38)+12+M2C_FIELD(a,u32 *,0x34),n,h->id); }
M2C_FIELD(a,u32 *,0x34)+=n;M2C_FIELD(a,void **,0x3c)=p;M2C_FIELD(a,u32 *,0x40)=p->size+12;
}else{
p=func_ov010_02229568(12);
{Ov010Packet *h=M2C_FIELD(a,void **,0x38);
func_ov010_0222959c(p,6,h->channel,h->flags,0,0,h->id); }
M2C_FIELD(a,void **,0x3c)=p;M2C_FIELD(a,u32 *,0x40)=p->size+12;M2C_FIELD(a,u32 *,0x34)=0;
if(M2C_FIELD(a,void **,0x38)){func_ov010_02229580(M2C_FIELD(a,void **,0x38));M2C_FIELD(a,void **,0x38)=0;}
}
}else{
M2C_FIELD(a,u16 *,0x44)=QueueMask26d9c();
M2C_FIELD(a,u16 *,0x44)&=func_ov010_02229a24();
for(i=0;i<4;i++)if(self!=i && (M2C_FIELD(a,u16 *,0x44)&(1<<i))){if(!func_0204428c((u8)i))return;}
M2C_FIELD(a,u32 *,0x40)=QueueSize26d9c();
p=func_ov010_02229568(M2C_FIELD(a,u32 *,0x40));M2C_FIELD(a,void **,0x3c)=p;
QueuePop26d9c(p);
if(M2C_FIELD(a,u32 *,0x40)>0x5a0){
M2C_FIELD(a,u32 *,0x34)=0;M2C_FIELD(a,void **,0x38)=M2C_FIELD(a,void **,0x3c);
p=func_ov010_02229568(24);
{Ov010Packet *h=M2C_FIELD(a,void **,0x38);
func_ov010_0222959c(p,4,h->channel,h->flags,M2C_FIELD(a,void **,0x38),12,h->id); }
M2C_FIELD(a,void **,0x3c)=p;M2C_FIELD(a,u32 *,0x40)=p->size+12;
}
}
{void (*cb)(u16,void *)=M2C_FIELD(&data_ov010_0222eee0,void (**)(u16,void *),0x58);if(cb)cb(M2C_FIELD(a,u16 *,0x44),M2C_FIELD(a,void **,0x3c));}
one=1;
if(M2C_FIELD(a,u16 *,0x44)&(one<<self)){
func_ov010_02227934(M2C_FIELD(a,s32 *,0x40),(u8)self);
func_ov010_02227954((u8)self,M2C_FIELD(a,void **,0x3c),M2C_FIELD(a,s32 *,0x40));
M2C_FIELD(a,u16 *,0x44)&=~0U ^ (one<<self);
}
if(M2C_FIELD(a,u16 *,0x44)){
switch(((Ov010Packet *)M2C_FIELD(a,void **,0x3c))->flags){
case 0:func_0204445c(M2C_FIELD(a,u16 *,0x44),M2C_FIELD(a,void **,0x3c),M2C_FIELD(a,s32 *,0x40));func_01ffa6fc(a);return;
case 1:func_0204455c(M2C_FIELD(a,u16 *,0x44),M2C_FIELD(a,void **,0x3c),M2C_FIELD(a,s32 *,0x40));func_ov010_02229580(M2C_FIELD(a,void **,0x3c));M2C_FIELD(a,void **,0x3c)=0;M2C_FIELD(a,u32 *,0x40)=0;return;
default:return;
}}
func_ov010_02229580(M2C_FIELD(a,void **,0x3c));M2C_FIELD(a,void **,0x3c)=0;M2C_FIELD(a,u32 *,0x40)=0;
}
#pragma opt_common_subs reset
void func_ov010_02227264(void *arg0) {
M2C_UNK func_01ffa6fc(void *);
s32 func_0204428c(u8);
M2C_UNK func_ov010_02229580(s32);
s32 func_ov010_02229a24();
s32 i;
u16 mask;
mask = func_ov010_02229a24() & M2C_FIELD(arg0,u16 *,0x44);
for (i=0;i<4;i++) {
if ((1 << i) & mask) { if (!func_0204428c((u8)i)) return; }
}
func_ov010_02229580(M2C_FIELD(arg0,s32 *,0x3c));
M2C_FIELD(arg0,s32 *,0x3c)=0;
M2C_FIELD(arg0,s32 *,0x40)=0;
func_01ffa6fc(arg0);
}

#pragma opt_common_subs off
void func_ov010_022272cc(void *arg0) {
s32 func_ov010_022282b4(s32);
s32 func_ov010_02229a08();
s32 func_ov010_02229bdc();
s32 func_ov010_02229b48(s32);
unsigned int func_ov010_022298a0(unsigned int);
s32 func_ov010_02229920(s32,void *);
void *func_ov010_02229568(u32);
M2C_UNK func_ov010_02229580(s32);
void func_ov010_0222959c(void *,u32,u32,u32,void *,u32,u32);
void *func_ov010_022268f4(s32,u32,u32);
void func_ov010_02226908(s32,void *,u32);
s32 func_ov010_02229608(u8,void *,s32,u16);
void func_ov010_02227f88(s32,void *);
M2C_UNK func_ov010_02228cbc();
void MI_CpuCopy8(void *,void *,u32);
void MI_CpuFill8(void *,s32,u32);
extern M2C_UNK data_ov010_0222eee0;
extern u8 data_ov010_0222ef58[],data_ov010_0222ef88[];
register s32 i;
s32 j;
u8 *state;
u32 size,chan;
void *p,*node,*s,*b;
Ov010Packet *hp,*hb;
s32 keep;
Ov010Packet hdr;
u8 *entry;
if(!func_ov010_022282b4(3))return;
state=(u8 *)&data_ov010_0222eee0;
for(i=0;i<4;i++){
entry=data_ov010_0222ef58+(u8)i*12;
size=RxQueueSize26d9c((u8 **)entry);
if(!size)continue;
keep=1;
p=func_ov010_02229568(size);
RxQueuePop26d9c(entry,p);
hp=(Ov010Packet *)p;
chan=hp->channel;
switch(hp->kind){
case 2:
if(func_ov010_02229bdc()){
s=M2C_FIELD(state,void **,0x18);
if(s&&M2C_FIELD(s,s32 *,0)==M2C_FIELD(p,s32 *,0xc))func_ov010_02229608(2,s,8,(u16)(1<<chan));
}else{
s=M2C_FIELD(state,void **,0x18);
if(s&&M2C_FIELD(s,s32 *,0)==M2C_FIELD(p,s32 *,0xc)){
func_ov010_02229608(3,s,8,(u16)(1<<chan));
}else{
func_ov010_02229608(2,(u8 *)p+0xc,8,(u16)(1<<chan));
}
}
break;
case 3:
if(func_ov010_02229bdc()){
s=M2C_FIELD(state,void **,0x18);
if(s&&M2C_FIELD(s,s32 *,0)==M2C_FIELD(p,s32 *,0xc))M2C_FIELD(s,u16 *,4)|=1<<chan;
}else{
s=M2C_FIELD(state,void **,0x18);
if(s&&M2C_FIELD(s,s32 *,0)==M2C_FIELD(p,s32 *,0xc)){
M2C_FIELD(s,u16 *,4)=0xffff;
}
}
break;
case 4:
MI_CpuCopy8((u8 *)p+0xc,&hdr,12);
node=func_ov010_02229568(hdr.size+12);
func_ov010_0222959c(node,hdr.kind,hdr.channel,hdr.flags,0,hdr.size,hdr.id);
M2C_FIELD((u8 *)arg0+chan*8,u32 *,0x34)=0;
M2C_FIELD((u8 *)arg0+chan*8,void **,0x38)=node;
break;
case 5:
size=hp->size;
MI_CpuCopy8((u8 *)p+0xc,(u8 *)M2C_FIELD((u8 *)arg0+chan*8,void **,0x38)+12+M2C_FIELD((u8 *)arg0+chan*8,u32 *,0x34),size);
M2C_FIELD((u8 *)arg0+chan*8,u32 *,0x34)+=size;
break;
case 6:
b=M2C_FIELD((u8 *)arg0+chan*8,void **,0x38);
hb=(Ov010Packet *)b;
if(hb->kind<10)RxQueuePush26d9c(hb,chan,data_ov010_0222ef58);
else RxQueuePush26d9c(hb,chan,data_ov010_0222ef88);
M2C_FIELD((u8 *)arg0+chan*8,u32 *,0x34)=0;
node=M2C_FIELD((u8 *)arg0+chan*8,void **,0x38);
if(node){
func_ov010_02229580((s32)node);
M2C_FIELD((u8 *)arg0+chan*8,void **,0x38)=0;
}
break;
case 7:
func_ov010_02227f88((u8)chan,(u8 *)p+0xc);
func_ov010_02229608(8,(void *)func_ov010_02229b48(func_ov010_02229a08()),0x6c,(u16)(1<<chan));
break;
case 8:
func_ov010_02227f88((u8)chan,(u8 *)p+0xc);
s=M2C_FIELD(state,void **,0x24);
if(s)M2C_FIELD(s,u16 *,2)|=1<<chan;
break;
case 9:
func_ov010_02228cbc((u8)chan);
break;
}
{s32 (*cb)(u8,void *)=M2C_FIELD(state,s32 (**)(u8,void *),0x1c);
if(cb)keep=cb((u8)chan,p);}
if(!keep)continue;
func_ov010_02229580(p);
}
state=(u8 *)&data_ov010_0222eee0;
if(!M2C_FIELD(state,void **,0x50))return;
{
void *p2;
u32 size2,chan2;
s32 keep2;
for(j=0;j<4;j++){
size2=func_ov010_022298a0((u8)j);
if(!size2)continue;
keep2=1;
p2=func_ov010_02229568(size2);
func_ov010_02229920((u8)j,p2);
chan2=((Ov010Packet *)p2)->channel;
{s32 (*cb)(u8,void *)=M2C_FIELD(state,s32 (**)(u8,void *),0x50);
if(cb)keep2=cb((u8)chan2,p2);}
if(!keep2)continue;
func_ov010_02229580(p2);
}
}
}
#pragma opt_common_subs reset
s32 func_ov010_0222791c(s32 arg0) {
    extern M2C_UNK data_ov010_0222eee0;
    s32 temp_r2;

    temp_r2 = M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x40);
    M2C_FIELD(&data_ov010_0222eee0, s32 *, 0x40) = arg0;
    return temp_r2;
}

void func_ov010_02227934(s32 a, s32 b) {
extern M2C_UNK data_ov010_0222eee0;
void (*cb)(s32,s32) = M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,s32),0x38);
if (!cb) return;
cb(a,b);
}

#pragma opt_common_subs off



#pragma opt_common_subs off
void func_ov010_02227954(s32 a,void *b,s32 c) {
void MI_CpuCopy8(void *,void *,u32);
void *FindObjectByClass(void *);
void *func_ov010_022268f4(s32,u32,u32);
void MI_CpuFill8(void *,s32,u32);
void func_ov010_0222959c(void *,u32,u32,u32,void *,u32,u32);
extern u8 data_ov010_0222c160[], data_ov010_0222ef58[],data_ov010_0222ef88[];
extern M2C_UNK data_ov010_0222eee0;
Ov010Packet header; volatile Ov010Packet *h; u32 kind; void *state;
void (*cb)(s32,void *,s32);
MI_CpuCopy8(b,&header,12);
h=&header;
if(header.magic==0x5f57464d) {
u8 channel=h->channel;
state=FindObjectByClass(data_ov010_0222c160);
if(state) M2C_FIELD((u8 *)state+channel*4,u32 *,0x38)=0;
kind=h->kind;
if(kind!=0 && kind!=1) {if(kind<10) {
u8 channel=h->channel;
u8 flags;
u32 size=h->size;
s32 id=h->id;
volatile u32 irq=*(volatile u16 *)0x4000208;
void *payload=size ? (u8 *)b+12 : 0;
u8 *queue;
u8 *node;
*(volatile u16 *)0x4000208=0;
flags=h->flags;
queue=data_ov010_0222ef58+channel*12;
node=func_ov010_022268f4(0,size+16,32);
if(!node) { u32 unused=*(volatile u16 *)0x4000208; *(volatile u16 *)0x4000208=irq; goto callbacks; }
{
MI_CpuFill8(node,0,16);
func_ov010_0222959c(node+4,kind,channel,flags,payload,size,id);
if(!M2C_FIELD(queue,void **,4)) { M2C_FIELD(queue,void **,4)=node; M2C_FIELD(queue,void **,0)=node; }
else { M2C_FIELD(M2C_FIELD(queue,void **,4),void **,0)=node; M2C_FIELD(queue,void **,4)=node; }
M2C_FIELD(queue,u32 *,8)=M2C_FIELD(queue,u32 *,8)+1;
}
{u32 unused=*(volatile u16 *)0x4000208; *(volatile u16 *)0x4000208=irq;}
} else {
u8 channel=h->channel;
u8 flags;
u32 size=h->size;
s32 id=h->id;
volatile u32 irq=*(volatile u16 *)0x4000208;
void *payload=size ? (u8 *)b+12 : 0;
u8 *queue;
u8 *node;
*(volatile u16 *)0x4000208=0;
flags=h->flags;
queue=data_ov010_0222ef88+channel*12;
node=func_ov010_022268f4(0,size+16,32);
if(!node) { u32 unused=*(volatile u16 *)0x4000208; *(volatile u16 *)0x4000208=irq; goto callbacks; }
{
MI_CpuFill8(node,0,16);
func_ov010_0222959c(node+4,kind,channel,flags,payload,size,id);
if(!M2C_FIELD(queue,void **,4)) { M2C_FIELD(queue,void **,4)=node; M2C_FIELD(queue,void **,0)=node; }
else { M2C_FIELD(M2C_FIELD(queue,void **,4),void **,0)=node; M2C_FIELD(queue,void **,4)=node; }
M2C_FIELD(queue,u32 *,8)=M2C_FIELD(queue,u32 *,8)+1;
}
{u32 unused=*(volatile u16 *)0x4000208; *(volatile u16 *)0x4000208=irq;}
}}
}
callbacks:
cb=M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,void *,s32),0x2c); if(cb)cb(a,b,c);
cb=M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,void *,s32),0x4c); if(cb)cb(a,b,c);
}
#pragma opt_common_subs reset
void func_ov010_02227bc8(void) {
    M2C_UNK func_ov010_02228cbc();
    func_ov010_02228cbc();
}

#pragma opt_common_subs off
void func_ov010_02227bd4(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f) {
    extern M2C_UNK data_ov010_0222eee0;
    extern u8 data_ov010_0222f02c[];
    void (*cb)(s32,s32,s32,s32,s32,s32);
    u8 *p;
    u8 byte;
    u16 flags;
    u16 newFlags;
    p = &data_ov010_0222f02c[d*0x6c];
    byte = M2C_FIELD(p,u8 *,0x1a);
    flags = M2C_FIELD(&data_ov010_0222eee0,u16 *,0);
    byte = byte & ~1;
    newFlags = (u16)(flags | (1 << d));
    M2C_FIELD(p,u8 *,0x1a) = byte;
    M2C_FIELD(&data_ov010_0222eee0,u16 *,0) = newFlags;
    cb = M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,s32,s32,s32,s32,s32),0x34);
    if (!cb) return;
    cb(a,b,c,d,e,f);
}
#pragma opt_common_subs reset
void func_ov010_02227c3c(s32 a,s32 b) {
extern M2C_UNK data_ov010_0222eee0;
void (*cb)(s32,s32)=M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,s32),0x10);
if (!cb) return;
cb(a,b);
}

#pragma opt_common_subs on
void func_ov010_02227c5c(s32 arg0, s32 arg1, s32 arg2) {
void *func_020c4b60(void);
void FillU16(s32,void *,s32);
extern M2C_UNK data_ov010_0222eee0;
Ov010State *base;
u32 offset;
void (*cb)(s32,s32,s32);
base=func_020c4b60();
offset=arg0*40;
M2C_FIELD((u8 *)base+0x2ee,u16 *,arg1*40)=M2C_FIELD((u8 *)base+offset+0x200,u16 *,0xee)+M2C_FIELD((u8 *)base+0x2ee,u16 *,arg1*40);
M2C_FIELD((u8 *)base+0x2f0,u16 *,arg1*40)=M2C_FIELD((u8 *)base+offset+0x200,u16 *,0xf0)+M2C_FIELD((u8 *)base+0x2f0,u16 *,arg1*40);
M2C_FIELD((u8 *)base+0x2f2,u16 *,arg1*40)+=M2C_FIELD((u8 *)base+offset+0x200,u16 *,0xf2);
FillU16(0,base->entries[arg0].bytes,26);
base->entries[arg0].count0=0;
base->entries[arg0].count1=0;
base->entries[arg0].count2=0;
base->entries[arg0].state0=-1;
base->entries[arg0].state1=-2;
base->entries[arg0].state2=-2;
cb=M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,s32,s32),20);
if(cb)cb(arg0,arg1,arg2);
}
