/* 33 functions from 0x02010C14 to 0x02011BB0 (main), found by ds-decomp. */
#include "common.h"

void func_02010c14(void){extern u8 data_0212fde0[],data_02130400[];M2C_UNK *func_02010c84(void);void func_0200fc58();void func_02010e68();u8 *p=data_0212fde0;u8 *q;s32 zero,minus,one;if(M2C_FIELD(p,s32 *,276))return;q=data_02130400;zero=0;minus=zero-1;one=1;M2C_FIELD(p,s32 *,276)=one;M2C_FIELD(p,s32 *,36)=zero;M2C_FIELD(p,s32 *,32)=zero;M2C_FIELD(p,s32 *,28)=zero;M2C_FIELD(p,s32 *,40)=minus;M2C_FIELD(p,s32 *,56)=zero;M2C_FIELD(p,s32 *,60)=zero;M2C_FIELD(q,s32 *,0)=zero;func_0200fc58();M2C_FIELD(data_02130400,s32 *,32)=(s32)func_02010c84();func_02010e68();}

void func_02010c78(void) {
    M2C_UNK func_0200fda0();
    func_0200fda0();
}

M2C_UNK *func_02010c84(void) {
    extern M2C_UNK func_02010938;
    return &func_02010938;
}

void func_02010c90(s32 a,s32 b,s32 c){extern u8 data_0212fde0[];void func_02005e5c(s32);s32 v;if(a!=11)return;if(!c)return;v=M2C_FIELD(data_0212fde0,s32 *,260);M2C_FIELD(data_0212fde0,s32 *,276)&=~32;func_02005e5c(v);}

void func_02010cc4(void){extern u8 data_0212fde0[];s32 func_0200751c();M2C_UNK func_02007530(s32);void func_02005da4(s32);s32 zero=0;u8 *p=data_0212fde0;s32 a;for(;;){a=func_0200751c();while(!(M2C_FIELD(p,s32 *,276)&8))func_02005da4(zero);func_02007530(a);M2C_FIELD(p,void (**)(void *),64)(p);}}

/* Sends a packet over the device, retrying while the device reports "busy/again" (status 4). */
s32 func_02010d14(void *dev, s32 *packet, s32 retries) {
void func_02005da4(s32);
void func_020067e0(s32 *, s32);
void func_020067a8(s32 *, s32);
void func_02006804(void);
void func_0200758c(s32);
s32 func_02009e8c(s32, s32);
s32 func_02009eb0(s32, s32, s32);
s32 func_0200751c(void);
M2C_UNK func_02007530(s32);
s32 count;
s32 *pkt;
s32 status;
s32 savedIrq;
count = retries;
if (!(M2C_FIELD(dev, volatile s32 *, 0x114) & 2)) {
M2C_FIELD(dev, volatile s32 *, 0x114) = M2C_FIELD(dev, volatile s32 *, 0x114) | 2;
if (func_02009e8c(11, 1) == 0) {
do { func_0200758c(100); } while (func_02009e8c(11, 1) == 0);
}
func_02010d14(dev, 0, 1);
}
func_020067e0(M2C_FIELD(dev, s32 **, 0), 96);
func_02006804();
again:
M2C_FIELD(dev, s32 **, 4) = packet;
M2C_FIELD(dev, volatile s32 *, 0x114) = M2C_FIELD(dev, volatile s32 *, 0x114) | 32;
do { } while (func_02009eb0(11, (s32)packet, 1) < 0);
if (!packet) {
pkt = M2C_FIELD(dev, s32 **, 0);
do { } while (func_02009eb0(11, (s32)pkt, 1) < 0);
}
savedIrq = func_0200751c();
while (M2C_FIELD(dev, volatile s32 *, 0x114) & 32) func_02005da4(0);
func_02007530(savedIrq);
func_020067a8(M2C_FIELD(dev, s32 **, 0), 96);
status = *M2C_FIELD(dev, s32 **, 0);
if (status == 4 && --count > 0) goto again;
if (status == 0) return 1;
return 0;
}

void func_02010e68(void) { void func_02009d34(void); void func_02009e40(s32,void (*)(s32,s32)); void func_02010e94(s32,s32); extern M2C_UNK data_02130640; func_02009d34();func_02009e40(14,func_02010e94);M2C_FIELD(&data_02130640,s32 *,4)=0; }

void func_02010e94(s32 a,s32 b) { void func_02010ef8(void); void func_02007958(void); extern M2C_UNK data_02130640; s32 result;
if((b&63)==17) {if(M2C_FIELD(&data_02130640,s32 *,0))return;result=1;M2C_FIELD(&data_02130640,s32 *,0)=result;
if(M2C_FIELD(&data_02130640,s32 (**)(),4))result=M2C_FIELD(&data_02130640,s32 (**)(),4)();
if(!result)return;
func_02010ef8();return;}func_02007958();
}

s32 func_02010ee8(void) {
    extern s32 data_02130640;
    return data_02130640;
}

void func_02010ef8(void) { void func_02007ca4(s32); s32 func_0200e840(void); void func_0200758c(s32); void func_02010fe4(M2C_UNK,M2C_UNK); void func_02007958(void);
s32 ok=1; s32 result;
func_02007ca4(0);func_02007ca4(1);func_02007ca4(2);func_02007ca4(3);
if((*(u16 *)0x027fffa8 & 0x8000)>>15) {
result=func_0200e840();while(result==4){func_0200758c(0xa3a47);result=func_0200e840();}
if(result==0)ok=0;
}
if(ok)func_02010fe4(1,1);
func_02007958();
}

void func_02010f84(s32 arg0) {
s32 func_0200751c(); M2C_UNK func_02007530(s32);
volatile s32 sp0; s32 *p; s32 saved;
if(*(u16 *)0x027FFC10==0)p=(s32 *)0x027FF800;else p=(s32 *)0x027FFC00;
sp0=*p;if(arg0==sp0)return;
saved=func_0200751c();((void (*)(s32,s32,s32))func_02010e94)(14,17,0);func_02007530(saved);
}

void func_02010fe4(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK WaitByLoop(M2C_UNK);
    s32 func_02009eb0(M2C_UNK, M2C_UNK, M2C_UNK);
    if (func_02009eb0(0xE, arg0, 0) == 0) {
        return;
    }
    do {
        WaitByLoop(arg1);
    } while (func_02009eb0(0xE, arg0, 0) != 0);
}

s32 func_02011034(s32 a,s32 b) {
s32 func_02011060(s32,s32,s32);extern M2C_UNK data_02130660;
s32 result=func_02011060(a,b,0xF00);
if(result!=0)return result;
M2C_FIELD(M2C_FIELD(&data_02130660,void **,4),u16 *,0x16)=0;
return result;
}

s32 func_02011244(void) {
s32 func_0200751c();M2C_UNK func_02007530(s32);s32 func_020114b4(s32,...);void func_020118f4(void);extern M2C_UNK data_02130660;
s32 saved=func_0200751c();s32 result;
if(func_02011450()!=0){func_02007530(saved);return 3;}
result=func_020114b4(1,0);if(result!=0)return result;
func_020118f4();func_02009e40(10,0);
M2C_FIELD(&data_02130660,s32 *,4)=0;M2C_FIELD(&data_02130660,u16 *,0)=0;
func_02007530(saved);return 0;
}

void func_020112b4(s32 a,s32 b){extern M2C_UNK data_02130660;M2C_FIELD(M2C_FIELD(&data_02130660,s32 *,4)+a*4,s32 *,24)=b;}

u16 *func_020112cc(void) {
    s32 func_02006390(M2C_UNK *, u16 **, M2C_UNK);
    M2C_UNK func_02006434(M2C_UNK *, u16 *, M2C_UNK);
    extern M2C_UNK data_02130668;
    u16 *sp0;

    if (func_02006390(&data_02130668, &sp0, 0) == 0) {
        return NULL;
    }
    func_020067a8(sp0, 2);
    if (*sp0 & 0x8000) {
        return sp0;
    }
    func_02006434(&data_02130668, sp0, 1);
    return NULL;
}

s32 func_02011324(u16 a,u16 n,...) {
extern M2C_UNK data_02130668;s32 func_02009eb0();s32 func_020062fc();void func_020067c4();
s32 *ap; s32 i,r; s32 count;u16 *p;p=func_020112cc();if(!p)return 8;*p=a;count=n;ap=(s32 *)((u32)&n&~3)+1;for(i=0;i<count;i++){ap++;((s32 *)p)[i+1]=ap[-1];}func_020067c4(p,256);r=func_02009eb0(10,p,0);func_020062fc(&data_02130668,p,1);return r<0?8:2;
}

s32 func_020113d0(void *a,s32 b) {
extern M2C_UNK data_02130668;s32 func_02009eb0();s32 func_020062fc();void func_020067c4();void func_02008048();
u16 *p=func_020112cc();s32 r;if(!p)return 8;func_02008048(a,p,b);func_020067c4(p,b);r=func_02009eb0(10,p,0);func_020062fc(&data_02130668,p,1);return r<0?8:2;
}

s32 func_02011440(void) {
    extern M2C_UNK data_02130660;
    return M2C_FIELD(&data_02130660, s32 *, 4);
}

s32 func_02011450(void) { extern M2C_UNK data_02130660; if(M2C_FIELD(&data_02130660,u16 *,0))return 0;return 3; }

s32 func_0201146c(void) {
extern M2C_UNK data_02130660;s32 r=func_02011450();if(r)return r;
func_020067a8(M2C_FIELD(M2C_FIELD(&data_02130660,void **,4),void **,4),2);
return M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_02130660,void **,4),void **,4),u16 *,0)<=1U?3:0;
}

s32 func_020114b4(s32 count,...) { extern M2C_UNK data_02130660; s32 result=func_02011450();s32 *args;u16 value;
if(result)return result;
func_020067a8(M2C_FIELD(M2C_FIELD(&data_02130660,void **,4),void **,4),2);
value=M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_02130660,void **,4),void **,4),u16 *,0);
args=(s32 *)((u32)&count&~3)+1;result=3;while(count){args++;if(args[-1]==value)result=0;count--;}return result;
}

void func_020118f4(void) {
    u16 temp_r0;

    temp_r0 = *(u16 *)0x027FFF96;
    if (temp_r0 & 1) {
        *(u16 *)0x027FFF96 = temp_r0 & ~1;
    }
}

s32 func_02011910(void) {
extern M2C_UNK data_02130660;
if(func_02011450()!=0)return 0;
return M2C_FIELD(M2C_FIELD(&data_02130660,void **,4),s32 *,4);
}

s32 func_02011934(void) {
extern M2C_UNK data_02130660;s32 s=func_0200751c();s32 r;void *p=M2C_FIELD(&data_02130660,void **,4);if(p)r=M2C_FIELD(p,u16 *,0x150);else r=0;func_02007530(s);return r;
}

u16 func_02011964(void) { s32 func_0200751c(void); M2C_UNK func_02007530(s32); extern M2C_UNK data_02130660;s32 s=func_0200751c();s32 r;void *p=M2C_FIELD(&data_02130660,void **,4);if(p)r=M2C_FIELD(p,s32 *,0x14c);else r=0;func_02007530(s);return r;}

s32 func_02011994(void) {s32 func_0200751c(void); M2C_UNK func_02007530(s32);M2C_UNK func_020067a8();extern M2C_UNK data_02130660;s32 r;void *p;s32 s;s=func_0200751c();p=M2C_FIELD(&data_02130660,void **,4);if(!p)r=0;else {p=M2C_FIELD(p,void **,4);func_020067a8(p+0x86,2);r=M2C_FIELD(p,u16 *,0x86);}func_02007530(s);return r;}

s32 func_020119dc(s32 arg0) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    s32 func_02011450();
    s32 temp_r0;
    s32 temp_r5;

    temp_r5 = func_0200751c();
    temp_r0 = func_02011450();
    if (temp_r0 != 0) {
        func_02007530(temp_r5);
        return temp_r0;
    }
    M2C_FIELD(func_02011440(), s32 *, 0xC8) = arg0;
    func_02007530(temp_r5);
    return 0;
}

/* Registers a callback and passes it some data under critical section. */
s32 func_02011a20(s32 arg0, void (*callback)(void *), s32 arg2) {
    u8 buf[0x44];
    s32 result;
    s32 irq;
    void *p;

    if (callback) {
        func_02007f8c(buf, 0, 0x44);
        M2C_FIELD(buf, u16 *, 0) = 0x82;
        M2C_FIELD(buf, u16 *, 2) = 0;
        M2C_FIELD(buf, u16 *, 4) = 0x19;
        M2C_FIELD(buf, u16 *, 6) = arg0;
        M2C_FIELD(buf, u32 *, 8) = 0;
        M2C_FIELD(buf, u32 *, 12) = 0;
        M2C_FIELD(buf, u16 *, 16) = 0;
        M2C_FIELD(buf, u16 *, 26) = 0xffff;
        M2C_FIELD(buf, u32 *, 28) = arg2;
        M2C_FIELD(buf, u16 *, 18) = 0;
        func_02007724(buf + 20);
    }
    irq = func_0200751c();
    result = func_02011450();
    if (result) {
        func_02007530(irq);
        return result;
    }
    p = (u8 *)func_02011440() + arg0 * 4;
    M2C_FIELD(p, void (**)(void *), 0xcc) = callback;
    M2C_FIELD(p, s32 *, 0x10c) = arg2;
    if (callback) {
        M2C_FIELD(buf, u16 *, 34) = (void *)func_02011964();
        M2C_FIELD(buf, u16 *, 32) = (void *)func_02011934();
        callback(buf);
    }
    func_02007530(irq);
    return 0;
}

s32 func_02011af8(s32 arg0) {
    M2C_UNK func_020067a8(s32, M2C_UNK);
    M2C_UNK func_02007ef4(s32, s32, M2C_UNK);
    s32 temp_r0;
    void *temp_r4;

    temp_r4 = func_02011440();
    temp_r0 = func_02011450();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if (arg0 == 0) {
        return 6;
    }
    func_020067a8(M2C_FIELD(temp_r4, s32 *, 4), 0x7D0);
    func_02007ef4(M2C_FIELD(temp_r4, s32 *, 4), arg0, 0x7D0);
    return 0;
}

s32 func_02011b44(void) {
    s32 func_020114b4(s32,...);
    void *temp_r1;
    void *temp_r4;

    temp_r4 = func_02011440();
    if (func_020114b4(2, 7, 8) != 0) {
        return 0;
    }
    func_020067a8(M2C_FIELD(temp_r4, void **, 4) + 0xC, 4);
    temp_r1 = M2C_FIELD(temp_r4, void **, 4);
    if (M2C_FIELD(temp_r1, s32 *, 0xC) == 1) {
        return 0;
    }
    func_020067a8(temp_r1 + 0x3C, 4);
    return (M2C_FIELD(M2C_FIELD(temp_r4, void **, 4), u16 *, 0x3C) + 0x1F) & ~0x1F;
}

