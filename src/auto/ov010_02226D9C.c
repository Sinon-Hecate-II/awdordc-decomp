/* 10 functions from 0x02226D9C to 0x02227D34 (ov010), found by ds-decomp. */
#include "common.h"
typedef struct { u32 magic; u8 kind; u8 channel:4; u8 flags:4; u16 id; u32 size; } Ov010Packet;
typedef struct { u8 bytes[26]; u16 count0, count1, count2; s8 state0, state1, state2; u8 pad[5]; } Ov010Entry;
typedef struct { u8 pad[0x2d4]; Ov010Entry entries[1]; } Ov010State;
extern unsigned char data_ov010_0222f02c[];

M2C_UNK func_ov010_02226d9c(void *a) {
    (void)a;
    return 0;
}

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

void func_ov010_022272cc(void *arg0) { (void)arg0; }

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

void func_ov010_02227954(s32 a,void *b,s32 c) {
void func_02008048(void *,void *,u32);
void *func_01ffa770(void *);
void *func_ov010_022268f4(s32,u32,u32);
void func_02007f8c(void *,s32,u32);
void func_ov010_0222959c(void *,u32,u32,u32,void *,u32,u32);
extern u8 data_ov010_0222c160[], data_ov010_0222ef58[],data_ov010_0222ef88[];
extern M2C_UNK data_ov010_0222eee0;
Ov010Packet header; volatile Ov010Packet *h; u32 kind; void *state;
void (*cb)(s32,void *,s32);
func_02008048(b,&header,12);
h=&header;
if(header.magic==0x5f57464d) {
u8 channel=h->channel;
state=func_01ffa770(data_ov010_0222c160);
if(state) M2C_FIELD((u8 *)state+channel*4,u32 *,0x38)=0;
kind=h->kind;
if(kind!=0 && kind!=1) {if(kind<10) {
u8 channel=h->channel;
u8 flags;
u32 size=h->size;
register u32 id=h->id;
volatile u32 irq=*(volatile u16 *)0x4000208;
void *payload=size ? (u8 *)b+12 : 0;
u8 *queue=data_ov010_0222ef58+channel*12;
u8 *node;
*(volatile u16 *)0x4000208=0;
flags=h->flags;
node=func_ov010_022268f4(0,size+16,32);
if(!node) { u32 unused=*(volatile u16 *)0x4000208; *(volatile u16 *)0x4000208=irq; goto callbacks; }
{
func_02007f8c(node,0,16);
func_ov010_0222959c(node+4,kind,channel,flags,payload,size,id);
if(!M2C_FIELD(queue,void **,4)) { M2C_FIELD(queue,void **,4)=node; M2C_FIELD(queue,void **,0)=node; }
else { M2C_FIELD(M2C_FIELD(queue,void **,4),void **,0)=node; M2C_FIELD(queue,void **,4)=node; }
M2C_FIELD(queue,u32 *,8)++;
}
{u32 unused=*(volatile u16 *)0x4000208; *(volatile u16 *)0x4000208=irq;}
} else {
u8 channel=h->channel;
u8 flags;
u32 size=h->size;
register u32 id=h->id;
volatile u32 irq=*(volatile u16 *)0x4000208;
void *payload=size ? (u8 *)b+12 : 0;
u8 *queue=data_ov010_0222ef88+channel*12;
u8 *node;
*(volatile u16 *)0x4000208=0;
flags=h->flags;
node=func_ov010_022268f4(0,size+16,32);
if(!node) { u32 unused=*(volatile u16 *)0x4000208; *(volatile u16 *)0x4000208=irq; goto callbacks; }
{
func_02007f8c(node,0,16);
func_ov010_0222959c(node+4,kind,channel,flags,payload,size,id);
if(!M2C_FIELD(queue,void **,4)) { M2C_FIELD(queue,void **,4)=node; M2C_FIELD(queue,void **,0)=node; }
else { M2C_FIELD(M2C_FIELD(queue,void **,4),void **,0)=node; M2C_FIELD(queue,void **,4)=node; }
M2C_FIELD(queue,u32 *,8)++;
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

void func_ov010_02227c5c(s32 arg0, s32 arg1, s32 arg2) {
void *func_020c4b60(void);
void func_02007df8(s32,void *,s32);
extern M2C_UNK data_ov010_0222eee0;
Ov010State *base;
s32 offset;
void (*cb)(s32,s32,s32);
base=func_020c4b60();
offset=arg0*40;
M2C_FIELD((u8 *)base+0x2ee,u16 *,arg1*40)+=((Ov010State *)((u8 *)base+offset))->entries[0].count0;
M2C_FIELD((u8 *)base+0x2f0,u16 *,arg1*40)+=((Ov010State *)((u8 *)base+offset))->entries[0].count1;
M2C_FIELD((u8 *)base+0x2f2,u16 *,arg1*40)+=((Ov010State *)((u8 *)base+offset))->entries[0].count2;
func_02007df8(0,base->entries[arg0].bytes,26);
base->entries[arg0].count0=0;
base->entries[arg0].count1=0;
base->entries[arg0].count2=0;
base->entries[arg0].state0=-1;
base->entries[arg0].state1=-2;
base->entries[arg0].state2=-2;
cb=M2C_FIELD(&data_ov010_0222eee0,void (**)(s32,s32,s32),20);
if(cb)cb(arg0,arg1,arg2);
}

