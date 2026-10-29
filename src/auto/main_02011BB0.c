/* 28 functions from 0x02011BB0 to 0x02012B70 (main), found by ds-decomp. */
#include "common.h"
typedef struct {u8 kind,length; u16 pad; u8 *data;} ParsedItem;
typedef struct {u8 count; u8 pad[3]; ParsedItem items[16];} ParsedItems;
typedef struct { u32 flags; u16 a,b,c,d; u8 e,f,g,h; } PacketParams_02012a64;

s32 func_02011bb0(void) {
    void *func_02011440();
    void func_020067a8(void *, s32);
    void *p;
    void *q;
    s32 flag;
    u16 v;
    u16 w;
    p = func_02011440();
    if (func_020114b4(2, 7, 8) != 0) {
        return 0;
    }
    func_020067a8(M2C_FIELD(p, void **, 4) + 0xC, 4);
    q = M2C_FIELD(p, void **, 4);
    if (M2C_FIELD(q, s32 *, 0xC) == 1) {
        return 0;
    }
    func_020067a8((u8 *)q + 0x188, 2);
    q = M2C_FIELD(p, void **, 4);
    if (M2C_FIELD(q, u16 *, 0x188) == 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    func_020067a8((u8 *)q + 0x3E, 2);
    q = M2C_FIELD(p, void **, 4);
    v = M2C_FIELD(q, u16 *, 0x3E);
    if (flag == 1) {
        func_020067a8((u8 *)q + 0xF8, 2);
        q = M2C_FIELD(p, void **, 4);
        w = M2C_FIELD(q, u16 *, 0xF8);
        return (((v + 0xC) * w + 0x29) & ~0x1F) << 1;
    } else {
        return ((v + 0x51) & ~0x1F) << 1;
    }
}

void *func_02011c74(void *arg0,u32 arg1){
void *func_02011440(void);s32 func_02011450(void);void func_020067a8(void *,s32);
s32 entries[15];void *p=func_02011440();s32 i;
if(func_02011450())return 0;
if(arg1<1||arg1>15)return 0;
func_020067a8((u8 *)M2C_FIELD(p,void **,4)+0x182,2);
if(!(M2C_FIELD(M2C_FIELD(p,void **,4),u16 *,0x182)&(1<<arg1)))return 0;
if(!M2C_FIELD(arg0,volatile u16 *,4))return 0;
entries[0]=(s32)arg0+10;i=0;
do{
if(arg1==M2C_FIELD(entries[i],u16 *,4))return (void *)entries[i];
i++;
entries[i]=entries[i-1]+M2C_FIELD(arg0,u16 *,6);
}while(i<M2C_FIELD(arg0,volatile u16 *,4));
return 0;
}

u16 func_02011d58(void) {
    s32 func_02011450();
    if (func_02011450() != 0) {
        return 0x8000U;
    }
    return *(u16 *)0x027FFCFA;
}

u16 func_02011d78(void){void *func_02011440();s32 func_02011450();void func_020067a8(void *,s32);void *p=func_02011440();void *q;u16 n;if(func_02011450())return 0;func_020067a8(M2C_FIELD(p,void **,4),2);q=M2C_FIELD(p,void **,4);n=M2C_FIELD(q,u16 *,0);switch(n){case 9:func_020067a8((u8 *)q+0x182,2);q=M2C_FIELD(p,void **,4);if(!M2C_FIELD(q,u16 *,0x182))return 0;case 10:case 11:func_020067a8((u8 *)q+0xbc,2);return M2C_FIELD(M2C_FIELD(p,void **,4),u16 *,0xbc);default:return 0;}}

u16 func_02011e08(void){void func_02007724(u8 *);u8 buf[6];u16 sum;s32 i;u8 *p;u16 v;func_02007724(buf);i=0;p=buf;sum=0;do{sum+=*p++;i++;}while(i<6);v=sum+*(s32 *)0x027ffc3c;v=v*7;return (s32)v%20+200;}

u16 func_02011e98(void){void func_02007724(u8 *);u8 buf[6];s32 i;u16 sum;u8 *p;u16 v;func_02007724(buf);i=0;p=buf;sum=0;do{sum+=*p++;i++;}while(i<6);v=sum+*(s32 *)0x027ffc3c;v=v*13;return (s32)v%10+30;}

/* Parse the item list embedded in the input buffer into *out (at most 16 items). */
void func_02011f2c(ParsedItems *out, void *in) {
    ParsedItems result;
    u8 *p;
    s32 i;
    u8 used, limit, size;

    if (M2C_FIELD(in, u16 *, 60)) {
        result.count = 0;
        *out = result;
        return;
    }
    result.count = M2C_FIELD(in, u16 *, 62);
    if (result.count == 0) {
        *out = result;
        return;
    }
    if (result.count > 16)
        result.count = 16;
    used = 0;
    p = (u8 *)in + 64;
    limit = M2C_FIELD(in, u16 *, 0) * 2 - 64;
    for (i = 0; i < result.count; i++) {
        result.items[i].kind = p[0];
        result.items[i].length = p[1];
        result.items[i].data = p + 2;
        size = result.items[i].length + 2;
        used += size;
        if (used > limit) {
            result.count = 0;
            *out = result;
            return;
        }
        p += size;
    }
    *out = result;
}

u16 func_02012084(void){
extern u32 data_020f5540;void func_0200ee70(void);s32 func_0200eff8(void *);
s32 a[3];
if(data_020f5540==0x10000){func_0200ee70();if(func_0200eff8(a)==0)data_020f5540=(u16)(a[2]+(a[1]<<8));}
data_020f5540=(u16)(data_020f5540+1);return (u16)data_020f5540;
}

s32 func_020120f8(M2C_UNK a){
s32 func_020114b4(s32,s32); void *func_02011440();s32 r;void *p;
r=func_020114b4(1,0);if(r)return r;func_020112b4(3,a);p=func_02011440();r=func_02011324(3,3,M2C_FIELD(p,s32 *,0),M2C_FIELD(p,s32 *,4),M2C_FIELD(p,s32 *,16));if(!r)r=2;return r;
}

s32 func_02012158(M2C_UNK arg0) {
    s32 func_020114b4(M2C_UNK, M2C_UNK);
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_020114b4(1, 1);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(4, arg0);
    var_r0 = func_02011324(4, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02012198(M2C_UNK arg0) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_020114b4(1, 1);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(5, arg0);
    var_r0 = func_02011324(5, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_020121d8(M2C_UNK arg0) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_020114b4(1, 2);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(6, arg0);
    var_r0 = func_02011324(6, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02012218(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_02011034(M2C_UNK, M2C_UNK);
    void *func_02011440();
    s32 temp_r0;
    s32 var_r0;
    void *temp_r0_2;

    temp_r0 = func_02011034(arg0, arg2);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(0, arg1);
    temp_r0_2 = func_02011440();
    var_r0 = func_02011324(0, 3, M2C_FIELD(temp_r0_2, s32 *, 0), M2C_FIELD(temp_r0_2, s32 *, 4), M2C_FIELD(temp_r0_2, s32 *, 0x10));
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02012274(M2C_UNK arg0) {
    M2C_UNK func_020112b4(M2C_UNK, M2C_UNK);
    s32 func_02011324();
    s32 func_0201146c();
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_0201146c();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(1, arg0);
    var_r0 = func_02011324(1, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_020122ac(M2C_UNK arg0) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_020114b4(1, 2);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(2, arg0);
    var_r0 = func_02011324(2, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_020122ec(s32 arg0,void *arg1){
s32 func_020114b4(s32,s32);s32 func_020123c8(void *);void func_020067c4(void *,s32);
s32 result=func_020114b4(1,2);s32 extra;
if(result)return result;
if(!arg1)return 6;
if(M2C_FIELD(arg1,u16 *,4)&&!M2C_FIELD(arg1,void **,0))return 6;
if(M2C_FIELD(arg1,u16 *,0x34)+(M2C_FIELD(arg1,u16 *,0x14)?42:0)>512 ||
M2C_FIELD(arg1,u16 *,0x36)+(M2C_FIELD(arg1,u16 *,0x14)?6:0)>512)return 6;
func_020123c8(arg1);func_020112b4(7,arg0);
func_020067c4(arg1,64);
if(M2C_FIELD(arg1,u16 *,4))func_020067c4(M2C_FIELD(arg1,void **,0),M2C_FIELD(arg1,u16 *,4));
result=func_02011324(7,1,arg1);
if(!result)result=2;return result;
}

s32 func_020123c8(void *arg0) {
    u16 temp_r0;
    u16 temp_r1;

    if ((u32) M2C_FIELD(arg0, u16 *, 4) > 0x70U) {
        return 0;
    }
    temp_r1 = M2C_FIELD(arg0, u16 *, 0x18);
    if (((u32) temp_r1 < 0xAU) || ((u32) temp_r1 > 0x3E8U)) {
        return 0;
    }
    temp_r0 = M2C_FIELD(arg0, u16 *, 0x32);
    if (((u32) temp_r0 < 1U) || ((u32) temp_r0 > 0xEU)) {
        return 0;
    }
    return 1;
}

s32 func_02012418(M2C_UNK a,M2C_UNK b){void *func_02011440();s32 r=func_020114b4(1,2);void *p;if(r)return r;p=func_02011440();M2C_FIELD(p,u16 *,0x150)=0;M2C_FIELD(p,s32 *,0x14c)=0;func_020112b4(8,a);r=func_02011324(8,1,b);if(!r)r=2;return r;}

void func_02012474(M2C_UNK arg0) {
    M2C_UNK func_02012418(M2C_UNK, M2C_UNK);
    func_02012418(arg0, 1);
}

s32 func_02012484(M2C_UNK arg0) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_020114b4(1, 7);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(9, arg0);
    var_r0 = func_02011324(9, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_020124c4(s32 a,void *b){s32 func_020114b4();s32 func_020113d0(void *,s32);u32 packet[4];s32 r;u16 n;r=func_020114b4(3,2,3,5);if(r)return r;if(!b)return 6;if(!M2C_FIELD(b,u32 *,0))return 6;n=M2C_FIELD(b,u16 *,4);if(n<1U||n>14U)return 6;func_020112b4(10,a);M2C_FIELD(packet,u16 *,0)=10;M2C_FIELD(packet,u16 *,2)=M2C_FIELD(b,u16 *,4);M2C_FIELD(packet,u32 *,4)=M2C_FIELD(b,u32 *,0);M2C_FIELD(packet,u16 *,8)=M2C_FIELD(b,u16 *,6);M2C_FIELD(packet,u8 *,10)=M2C_FIELD(b,u8 *,8);M2C_FIELD(packet,u8 *,11)=M2C_FIELD(b,u8 *,9);M2C_FIELD(packet,u8 *,12)=M2C_FIELD(b,u8 *,10);M2C_FIELD(packet,u8 *,13)=M2C_FIELD(b,u8 *,11);M2C_FIELD(packet,u8 *,14)=M2C_FIELD(b,u8 *,12);M2C_FIELD(packet,u8 *,15)=M2C_FIELD(b,u8 *,13);r=func_020113d0(packet,16);if(!r)r=2;return r;}

/* Wraps params into a packet and dispatches it to the host. */
s32 func_020125b0(s32 sendCode, void *params) {
s32 func_020114b4();
s32 func_020113d0(void *, s32);
void func_02008048(void *, void *, s32);
u16 packet[30];
s32 r;
u16 type;

r = func_020114b4(3, 2, 3, 5);
if (r) return r;
if (!params) return 6;
if (!M2C_FIELD(params, u32 *, 0)) return 6;
if (M2C_FIELD(params, u16 *, 4) > 0x400U) return 6;
if (M2C_FIELD(params, u16 *, 18) > 32U) return 6;
type = M2C_FIELD(params, u16 *, 16);
if (type != 0 && type != 1 && type != 2 && type != 3) return 6;
if ((u16)(type + 0xfffe) <= 1U && M2C_FIELD(params, u16 *, 52) > 32U) return 6;
func_020112b4(38, sendCode);
M2C_FIELD(packet, u16 *, 0) = 38;
M2C_FIELD(packet, u16 *, 2) = M2C_FIELD(params, u16 *, 6);
M2C_FIELD(packet, u32 *, 4) = M2C_FIELD(params, u32 *, 0);
M2C_FIELD(packet, u16 *, 8) = M2C_FIELD(params, u16 *, 4);
M2C_FIELD(packet, u16 *, 10) = M2C_FIELD(params, u16 *, 8);
func_02008048((u8 *)params + 10, &packet[6], 6);
M2C_FIELD(packet, u16 *, 18) = M2C_FIELD(params, u16 *, 16);
M2C_FIELD(packet, u16 *, 54) = M2C_FIELD(params, u16 *, 52);
M2C_FIELD(packet, u16 *, 20) = M2C_FIELD(params, u16 *, 18);
func_02008048((u8 *)params + 20, &packet[11], 32);
r = func_020113d0(packet, 60);
if (!r) r = 2;
return r;
}

s32 func_02012700(M2C_UNK arg0) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_020114b4(1, 5);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(0xB, arg0);
    var_r0 = func_02011324(0xB, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02012740(s32 a,u16 *b,void *c,s32 d,u16 e){
void *func_02011440(void);
void func_020067c4(void *,s32);void func_02008048(void *,void *,s32);void func_02007f8c(void *,s32,s32);s32 func_020113d0(void *,s32);
u32 packet[10];s32 r;void *p;
r=func_020114b4(1,2);if(r)return r;if(!b)return 6;
func_020067c4(b,*b*2);p=func_02011440();M2C_FIELD(p,u16 *,0x150)=0;M2C_FIELD(p,s32 *,0x14c)=0;func_020112b4(12,a);
M2C_FIELD(packet,u16 *,0)=12;M2C_FIELD(packet,u16 **,4)=b;
if(c)func_02008048(c,&packet[2],24);else func_02007f8c(&packet[2],0,24);
M2C_FIELD(packet,s32 *,32)=d;M2C_FIELD(packet,u16 *,38)=e;
r=func_020113d0(packet,40);if(!r)r=2;return r;
}

s32 func_0201280c(s32 a,u32 b){s32 func_020114b4();void *func_02011440();void func_020067a8(void *,s32);void *p=func_02011440();void *q;s32 r=func_020114b4(5,7,9,8,10,11);if(r)return r;q=M2C_FIELD(p,void **,4);if(M2C_FIELD(q,u16 *,0)==7 || M2C_FIELD(q,u16 *,0)==9){if(b<1 || b>15)return 6;func_020067a8((u8 *)q+0x182,2);if(!(M2C_FIELD(M2C_FIELD(p,void **,4),u16 *,0x182)&(1<<b)))return 7;}else if(b)return 6;func_020112b4(13,a);r=func_02011324(13,1,1<<b);if(!r)r=2;return r;}

s32 func_020128f4(s32 index, s32 peer, s32 payloadSize, s32 param, u16 tag, void *data) {
    /* Register a pending uplink packet: validates camera/module state, builds packet header in a 64-byte buffer, returns status. */
    s32 func_020114b4();
    void *func_02011440();
    void func_020067a8(void *, s32);
    void func_02007e54(s32, void *, s32);
    void func_02007e70(void *, void *, s32);
    s32 func_020113d0(void *, s32);
    s32 func_02011b44();
    u32 packet[16];
    s32 rc;
    void *ctx;
    ctx = M2C_FIELD(func_02011440(), void **, 4);
    rc = func_020114b4(2, 7, 8);
    if (rc) return rc;
    func_020067a8(ctx + 0x188, 2);
    func_020067a8(ctx + 0xC6, 2);
    if (M2C_FIELD(ctx, u16 *, 0x188) && M2C_FIELD(ctx, u16 *, 0xC6) != 1) return 3;
    func_020067a8(ctx + 12, 4);
    if (M2C_FIELD(ctx, s32 *, 12) == 1) return 3;
    if (payloadSize & 63) return 6;
    if (tag & 31) return 6;
    func_020067a8(ctx + 0x9C, 2);
    if (!M2C_FIELD(ctx, u16 *, 0x9C)) {
        if (payloadSize < func_02011bb0()) return 6;
        if ((s32)tag < func_02011b44()) return 6;
    }
    func_020112b4(14, index);
    func_02007e54(0, packet, 64);
    M2C_FIELD(packet, u16 *, 0) = 14;
    packet[1] = peer;
    packet[2] = (u32)payloadSize >> 1;
    packet[3] = param;
    packet[4] = tag;
    func_02007e54(0, &packet[5], 28);
    func_02007e70(data, &packet[12], 16);
    rc = func_020113d0(packet, 64);
    if (!rc) rc = 2;
    return rc;
}

void func_02012a64(M2C_UNK a,M2C_UNK b,M2C_UNK c,M2C_UNK d,u16 e,u16 f,u16 g,s32 h,s32 i,s32 j,s32 k){
    void func_02007e54();
    PacketParams_02012a64 x;
    func_02007e54(0,&x,16);
    x.g=(u8)k;x.d=g;x.e=(u8)h;x.f=(u8)i;x.flags=0x1e03;
    if(j&f){x.flags|=4;x.c=f;}
    x.a=f;x.b=f;
    func_020128f4(a,b,c,d,e,&x);
}

void func_02012b08(M2C_UNK a,M2C_UNK b,M2C_UNK c,M2C_UNK d,u16 e,u16 f){
void func_02007e54();s32 func_020128f4(s32,s32,s32,s32,u16,void *);u32 x[4];
func_02007e54(0,x,16);x[0]=3;M2C_FIELD(x,u16 *,4)=f;M2C_FIELD(x,u16 *,6)=f;func_020128f4(a,b,c,d,e,x);
}
typedef struct { u32 flags; u16 a,b,c,d; u8 e,f,g,h; } Packet_02012a64;
