/* 29 functions from 0x02019E64 to 0x0201AE0C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 dest[6],src[6];u16 type;u8 pad14,hw;u8 proto,pad17;u16 sizes;u8 pad20,op;u8 sender[6];u16 shi,slo;u8 target[6];u16 thi,tlo; } Packet0201ACA0;

typedef struct {
    u16 tag;
    u8 pad[4];
    u16 extra;
} Func0201A09CBuf;

s32 func_0201a09c(u8 *r0) {
    void func_02008048(void *, void *, s32);
    void func_020067c4(void *, s32);
    Func0201A09CBuf buf;
    if (r0 == NULL) return 0;
    if (*(u16 *)(r0 + 0x3C) == 0) return 0;
    func_02008048(r0 + 0x50, &buf, 8);
    func_020067c4(&buf, 8);
    if (*(s32 *)(r0 + 0x44) == 0) {
        if (*(volatile u16 *)&buf.tag == 0x2348 || *(volatile u16 *)&buf.tag == 0xBD8A) {
            if (buf.extra == 4) return 1;
        }
    }
    return 0;
}

void func_0201a238(void) {
    extern M2C_UNK data_02137290;
    void func_02005ec8(void);
    void func_02006030(s32);
    s32 f = M2C_FIELD(&data_02137290, s32 *, 0x24);
    if (f) {
        func_02006030(f);
    } else {
        func_02005ec8();
    }
}

void func_0201a260(void) {

}

s32 func_0201a264(void) {
    return 1;
}

void func_0201a4f8(s32 arg0) {
    extern M2C_UNK data_02137290;
    M2C_FIELD(&data_02137290, s32 *, 0x3C) = arg0;
}

void func_0201a508(void){void *func_0201a4a8(void);void func_02005d60(void *);void func_02005ccc(void *);void func_0201a134(s32);extern M2C_UNK data_02137438,data_021374f8,data_02137290;func_0201a4a8();func_02005d60(&data_02137438);func_02005ccc(&data_021374f8);M2C_FIELD(&data_02137290,s32 *,84)=0;func_0201a134(0);M2C_FIELD(&data_02137290,s32 *,88)=0;M2C_FIELD(&data_02137290,s32 *,92)=0;}

void func_0201a550(s32 arg0) {
    M2C_UNK func_02005f80(M2C_UNK *, s32);
    extern s32 data_020faf74;
    extern M2C_UNK data_02137438;
    extern M2C_UNK data_021374f8;
    data_020faf74 = arg0;
    func_02005f80(&data_021374f8, arg0);
    func_02005f80(&data_02137438, arg0);
}

u32 func_0201a588(u8 *p,u32 n,u32 sum){u32 v;if((u32)p&1){while(n>1){sum+=(u16)((p[0]<<8)|p[1]);n-=2;p+=2;}}else{v=(u16)sum;sum=(u16)(((s32)v>>8)|(v<<8));while(n>1){sum+=*(u16 *)p;p+=2;n-=2;}v=((sum>>8)&0x00ff00ff)|((sum<<8)&0xff00ff00);sum=(v>>16)|(v<<16);}if(n)sum+=*p<<8;v=(u16)sum+(sum>>16);v+=v>>16;return (u16)v;}

s32 func_0201a63c(s32 arg0) {
    u16 var_r0;

    var_r0 = arg0 ^ 0xFFFF;
    if (var_r0 == 0) {
        var_r0 = 0xFFFF;
    }
    return (s32) var_r0;
}

void func_0201a658(M2C_UNK arg0, M2C_UNK arg1) {
    func_0201a63c((u16)func_0201a588((u8 *)arg0, (u32)arg1, 0));
}

s32 func_0201a674(u8 *a,s32 b,u8 *c,u32 d){u32 r;r=func_0201a588(c+12,8,func_0201a588(a,b,d));r+=b;if(r&0x10000)r=(u16)(r+1);return r!=65535;}

s32 func_0201a6c4(s32 a){extern M2C_UNK data_02137290;s32 r=1;if(a!=-1&&a!=0x7f000001){s32 mask=M2C_FIELD(&data_02137290,s32 *,28);if((a&mask)!=(M2C_FIELD(&data_02137290,s32 *,80)&mask))r=0;}return r;}

s32 func_0201a704(s32 a){s32 func_0201a6c4(s32);extern M2C_UNK data_02137290;if(!func_0201a6c4(a))a=M2C_FIELD(&data_02137290,s32 *,44);return a;}

s32 func_0201a728(s32 a){extern M2C_UNK data_02137290;s32 r=0;if(func_0201a6c4(a)){s32 m=~M2C_FIELD(&data_02137290,s32 *,28);if(m==(m&a))r=1;}return r;}

s32 func_0201a764(s32 arg0) {
    if ((arg0 & 0xF0000000) == 0xE0000000) {
        return 1;
    }
    return 0;
}

s32 func_0201a778(s32 a){extern M2C_UNK data_02137290;s32 r=1,s=1,t=1,u=1; s32 own=M2C_FIELD(&data_02137290,s32 *,80);if(own!=0&&a!=own)u=0;if(!u&&a!=0x7f000001)t=0;if(!t&&!func_0201a728(a))s=0;if(!s&&!func_0201a764(a))r=0;return r;}

s32 func_0201a7f8(u16 *a,u16 *b){s32 i=0;do{if(*a++!=*b++)return 1;i++;}while(i<3);return 0;}

void func_0201a824(u8 *a,s32 b,s32 c,s32 d){void func_02008048(void *,void *,s32);s32 func_02029848(void *,void *,s32,s32,s32);extern M2C_UNK data_020faf80,data_02137290;func_02008048(&data_020faf80,a+6,6);M2C_FIELD(&data_02137290,u8 *,0)=func_02029848(a,a+6,b-6,c,d)<0;}

void func_0201aa74(s32 a,s32 b,s32 c,s32 d){void func_0201a880(s32,s32,s32,s32,s32,s32);s32 func_02005d90(s32);void func_02005e5c(s32);extern M2C_UNK data_02137290;func_0201a880(a,b,c,d,0,0);if(!M2C_FIELD(&data_02137290,volatile s32 *,84))return;if(func_02005d90(M2C_FIELD(&data_02137290,volatile s32 *,84)))return;func_02005e5c(M2C_FIELD(&data_02137290,volatile s32 *,84));}

u8 *func_0201aacc(s32 *out){s32 func_0200751c(void);void func_02007530(s32);void func_02005da4(s32);extern M2C_UNK data_02137290,data_0212dca4;s32 key;u32 size;u8 *p;u32 len;key=func_0200751c();while(M2C_FIELD(&data_02137290,u32 *,48)==M2C_FIELD(&data_02137290,u32 *,40)){M2C_FIELD(&data_02137290,s32 *,84)=M2C_FIELD(&data_0212dca4,s32 *,4);func_02005da4(0);M2C_FIELD(&data_02137290,s32 *,84)=0;}func_02007530(key);p=M2C_FIELD(&data_02137290,u8 **,88);do{size=M2C_FIELD(&data_02137290,u32 *,92);if(size-M2C_FIELD(&data_02137290,u32 *,48)<2)M2C_FIELD(&data_02137290,u32 *,48)=0;len=M2C_FIELD(p,u16 *,M2C_FIELD(&data_02137290,u32 *,48));if(!len)M2C_FIELD(&data_02137290,u32 *,48)=0;}while(!len);*out=len-2;return M2C_FIELD(&data_02137290,u8 **,88)+M2C_FIELD(&data_02137290,u32 *,48)+2;}

void func_0201ab8c(void){s32 func_0200751c(void);void func_02007530(s32);extern M2C_UNK data_02137290;s32 key;register u32 n;register u8 *p;register void *q;key=func_0200751c();q=&data_02137290;n=M2C_FIELD(q,volatile u32 *,48);p=M2C_FIELD(q,u8 **,88);n+=M2C_FIELD(p,u16 *,M2C_FIELD(q,volatile u32 *,48));M2C_FIELD(q,volatile u32 *,48)=n;if(M2C_FIELD(q,volatile u32 *,48)>=M2C_FIELD(q,u32 *,92))M2C_FIELD(q,volatile u32 *,48)=0;func_02007530(key);}

s32 func_0201abd0(s32 a){extern M2C_UNK data_02137290,data_02137778,data_020faf78,data_02137310,data_0213731a;s32 func_0200751c(void);void func_02007530(s32);u64 func_02007004(void);s32 irq=func_0200751c();u32 i;void *r=0;u8 *p;if(a==0x7f000001 || a==M2C_FIELD(&data_02137290,s32 *,0x50))r=&data_02137778;else if(func_0201a728(a)||func_0201a764(a))r=&data_020faf78;else{p=(u8 *)&data_02137310;for(i=0;i<8;i++,p+=12){if(a==*(s32 *)p){a=func_02007004()>>16;M2C_FIELD(&data_0213731a,u16 *,i*12)=a;r=(u8 *)&data_02137310+i*12+4;break;}}}func_02007530(irq);return (s32)r;}

void func_0201aca0(s32 a){extern M2C_UNK data_02137778,data_02137290;void func_02007f8c(void *,s32,s32);void func_02008048(void *,void *,s32);Packet0201ACA0 packet;s32 hi,lo,ahi,alo;u32 own;func_02007f8c(&packet,0,42);func_02007f8c(packet.dest,255,6);func_02008048(&data_02137778,packet.src,6);packet.type=0x608;packet.hw=1;packet.proto=8;packet.sizes=0x406;packet.op=1;func_02008048(&data_02137778,packet.sender,6);own=M2C_FIELD(&data_02137290,u32 *,80);hi=(u16)(own>>16);lo=(u16)own;ahi=(u16)((u32)a>>16);alo=(u16)a;packet.shi=(hi>>8)|(hi<<8);packet.slo=(lo>>8)|(lo<<8);packet.thi=(ahi>>8)|(ahi<<8);packet.tlo=(alo>>8)|(alo<<8);func_0201a824((u8 *)&packet,42,0,0);}

s32 func_0201ad9c(s32 a){void func_0201aca0(s32);void func_02006030(s32);s32 func_0201abd0(s32);extern M2C_UNK data_02137290;u32 i,j;s32 r;for(i=0;i<8;i++){func_0201aca0(a);for(j=0;j<20;j++){if(!M2C_FIELD(&data_02137290,s32 *,80))return 0;func_02006030(100);r=func_0201abd0(a);if(r)return r;}}return 0;}

