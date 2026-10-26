/* 19 functions from 0x02012B70 to 0x02013B54 (main), found by ds-decomp. */
#include "common.h"

s32 func_02012b70(s32 arg0, void *arg1) {
void *func_02011440(); s32 func_02011450(void *); s32 func_020112b4(s32,s32); void func_02007e54(s32,void *,s32); void func_02007e70(void *,void *,s32); s32 func_020113d0(void *,s32);
u32 buf[8]; s32 r;
r=func_02011450(func_02011440()); if(r) return r;
func_020112b4(0x23,arg0); func_02007e54(0,buf,0x20);
*(u16 *)buf=0x23; func_02007e70(arg1,&buf[1],0x1c);
r=func_020113d0(buf,0x20); if(!r) r=2; return r;
}

void func_02012be4(s32 arg0, s16 arg1) {
void func_02007e54(s32,void *,s32);
u32 buf[7];
func_02007e54(0,buf,0x1c); buf[0]=3; ((s16 *)buf)[2]=arg1; ((s16 *)buf)[3]=arg1; func_02012b70(arg0,buf);
}

s32 func_02012d64(s32 arg0) {
void *func_02011440(); s32 func_020114b4(s32,s32); s32 func_020067a8(s32,s32); s32 func_020112b4(s32,s32); s32 func_02011324(s32,s32);
void *p; s32 r;
p=func_02011440(); r=((s32 (*)(s32,s32,s32))func_020114b4)(2,9,10); if(r) return r;
func_020067a8(M2C_FIELD(p,void **,4)+12,4);
if(M2C_FIELD(M2C_FIELD(p,void **,4),s32 *,12)==0) return 3;
func_020112b4(16,arg0); r=func_02011324(16,0); if(!r) r=2; return r;
}

s32 func_02012dd4(s32 arg0, void *arg1, u32 arg2) {
void *func_02011440(); s32 func_020114b4(s32,s32); s32 func_020067a8(s32,s32); void func_020067c4(void *,u32); s32 func_020112b4(s32,s32); s32 func_02011324(s32,s32);
void *p; s32 r;
p=func_02011440(); r=func_020114b4(1,8); if(r) return r;
func_020067a8(M2C_FIELD(p,void **,4)+16,4);
if(M2C_FIELD(M2C_FIELD(p,void **,4),s32 *,16)==1) return 3;
if(arg2<16) return 6; if(!arg1) return 6;
func_020067c4(arg1,arg2); func_020112b4(17,arg0); r=((s32 (*)(s32,s32,void *,u32))func_02011324)(17,2,arg1,arg2); if(!r) r=2; return r;
}

s32 func_02012e74(s32 arg0,void *arg1,void *arg2,u32 arg3) {
 void *func_02011440(); s32 func_020114b4(s32,s32); s32 func_020067a8(s32,s32); void func_020067c4(void *,u32); s32 func_020112b4(s32,s32); s32 func_02011324(s32,s32); void func_02008048(void *,void *,u32);
 u32 buf[2]; void *p; s32 r;
 p=func_02011440();r=func_020114b4(1,11);if(r)return r;
 func_020067a8(M2C_FIELD(p,void **,4)+16,4);
 if(M2C_FIELD(M2C_FIELD(p,void **,4),s32 *,16)==0)return 3;
 if(arg3>1508)return 6;
 func_020067c4(arg2,arg3);
 func_020112b4(18,arg0);
 func_02008048(arg1,buf,6);
 r=((s32 (*)(s32,s32,u32,u32,void *,u32))func_02011324)(18,4,buf[0],buf[1],arg2,arg3);
 if(!r)r=2;return r;
}

s32 func_02012f40(M2C_UNK arg0) {
    M2C_UNK func_020067a8(s32, M2C_UNK);
    M2C_UNK func_020112b4(M2C_UNK, M2C_UNK);
    s32 func_02011324(M2C_UNK, M2C_UNK);
    void *func_02011440();
    s32 func_020114b4(M2C_UNK, M2C_UNK);
    s32 temp_r0;
    s32 var_r0;
    void *temp_r4;

    temp_r4 = func_02011440();
    temp_r0 = func_020114b4(1, 0xB);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020067a8(M2C_FIELD(temp_r4, void **, 4) + 0x10, 4);
    if (M2C_FIELD(M2C_FIELD(temp_r4, void **, 4), s32 *, 0x10) == 0) {
        return 3;
    }
    func_020112b4(0x13, arg0);
    var_r0 = func_02011324(0x13, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02013200(void *arg0) {
    M2C_UNK func_02011a20(u16, M2C_UNK, M2C_UNK);
    if (arg0 == NULL) {
        return 6;
    }
    if (M2C_FIELD(arg0, u16 *, 0x80E) == 0) {
        return 3;
    }
    func_02011a20(M2C_FIELD(arg0, u16 *, 0x816), 0, 0);
    M2C_FIELD(arg0, u16 *, 0x80E) = 0U;
    M2C_FIELD(arg0, s16 *, 0x81C) = 0;
    return 0;
}

void func_02013590(void *p) {
 void *func_02011440(void); s32 func_02011934(void); void func_02013668(void);void func_02013794(void *);
 void *ctx=func_02011440(); void *obj; void *cb; s32 r;
 ctx=(u8 *)ctx+M2C_FIELD(p,u16 *,10)*4;
 cb=M2C_FIELD(ctx,void **,0xcc);
 obj=M2C_FIELD(ctx,void **,0x10c);
 if(cb!=(void *)func_02013668 && cb!=(void *)func_02013794)return;
 if(!obj)return;
 if(obj!=M2C_FIELD(p,void **,32))return;
 r=func_02011934();
 if(M2C_FIELD(p,u16 *,2)==0) {
 if(r)return;
 ((u16 *)((u8 *)obj+0x800))[M2C_FIELD(obj,u16 *,0x80a)]=M2C_FIELD(p,u16 *,0x1a)>>1;
 M2C_FIELD(obj,u16 *,0x80a)=(M2C_FIELD(obj,u16 *,0x80a)+1)&3;
 return;
 }
 if(M2C_FIELD(p,u16 *,2)==10) {
 if(r)M2C_FIELD(obj,u16 *,0x80a)=(M2C_FIELD(obj,u16 *,0x80a)+3)&3;
 M2C_FIELD(obj,u16 *,0x81c)=4;
 } else M2C_FIELD(obj,u16 *,0x81c)=5;
}

void func_02013794(void *p) {
void func_02007e20(void *,void *,u32);s32 func_02011934(void);
void *q=M2C_FIELD(p,void **,0x1C);u16 *data;u32 len;u16 mask;s32 bit;
if(!q)return;
if(M2C_FIELD(p,u16 *,2)==0) {
switch((s32)M2C_FIELD(p,u16 *,4)) {
case 7:case 8:case 9:break;
case 25:case 26:break;
case 21:
data=M2C_FIELD(p,u16 **,0xC);len=M2C_FIELD(p,u16 *,0x10);mask=*data;bit=func_02011934();
if(len!=M2C_FIELD(q,u16 *,0x814)){if(len>0x200)len=0x200;}
if(len<4)return;
if(!(mask&(1<<bit)))return;
func_02007e20(data,q+(M2C_FIELD(q,u16 *,0x808)<<9),len);
M2C_FIELD(q+M2C_FIELD(q,u16 *,0x808)*2,u16 *,0x800)=(s32)M2C_FIELD(p,u16 *,0x1A)>>1;
M2C_FIELD(q,u16 *,0x808)=(M2C_FIELD(q,u16 *,0x808)+1)&3;
break;
}
}else M2C_FIELD(q,u16 *,0x81C)=5;
}

void func_02013888(void *p,u32 index,void *src) {
 void func_02007e20(void *,void *,u32);void func_02007df8(s32,void *,u32);s32 func_0200751c(void);void func_02007530(s32);
 u16 mask=1<<index; u16 slot; void *dst; s32 irq;
 if(!(M2C_FIELD(p,u16 *,0x80e)&mask))return;
 slot=M2C_FIELD(p,u16 *,0x808);
 if(!(((u16 (*)[256])p)[slot][0]&mask)) {
 if(M2C_FIELD(p,u16 *,0x818)!=1)return;
 slot=(slot+1)&3;
 if(!(M2C_FIELD(p,u16 *,slot<<9)&mask))return;
 }
 dst=(void *)func_02013afc(p,M2C_FIELD(p,u16 *,0x80e),(s32)&((u16 (*)[256])p)[slot][2],index);
 if(src)func_02007e20(src,dst,M2C_FIELD(p,u16 *,0x810));
 else func_02007df8(0,dst,M2C_FIELD(p,u16 *,0x810));
 irq=func_0200751c();
 M2C_FIELD(p,u16 *,slot<<9)&=~mask;
 ((u16 (*)[256])((u8 *)p+2))[slot][0]|=mask;
 func_02007530(irq);
}

s32 func_02013aa8(void *arg0, void *arg1, register u32 arg2) {
u16 a=M2C_FIELD(arg1,u16 *,0); u16 b=M2C_FIELD(arg1,u16 *,2);
register s32 mask=1;
if(!arg0) return 0; if(!arg1) return 0;
if(!(a & (mask<<arg2))) return 0;
if(!(b & (1<<arg2))) return 0;
return func_02013afc(arg0,a,(s32)arg1+4,arg2);
}

s32 func_02013afc(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_02076614(s32);
    return (M2C_FIELD(arg0, u16 *, 0x810) * func_02076614(arg1 & ((1 << arg3) - 1))) + arg2;
}

void func_02013b2c(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02012fac(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02012fac(arg0, arg1, 0xFFFF, 2, 1);
}

void func_02013b48(void) {
    M2C_UNK func_02013200();
    func_02013200();
}
