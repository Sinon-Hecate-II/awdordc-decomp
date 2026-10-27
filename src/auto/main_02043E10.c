/* 35 functions from 0x02043E10 to 0x02044E04 (main), found by ds-decomp. */
#include "common.h"
void func_02008048(void *,void *,s32);

s32 func_020441e8(s32 arg0) {
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    void *temp_r0;

    if (arg0 != 0) {
        return 1;
    }
    if (M2C_FIELD(func_02044268(), u8 *, 0x15) != 3) {
        temp_r0 = func_02044268();
        M2C_FIELD(temp_r0, u8 *, 0x17D) = (u8) (M2C_FIELD(temp_r0, u8 *, 0x17D) + 1);
    }
    if ((M2C_FIELD(func_02044268(), u8 *, 0x15) == 3) || ((u32) M2C_FIELD(func_02044268(), u8 *, 0x17D) >= 5U)) {
        func_0203dc38(6, 0xFFFEAE6C);
        return 0;
    }
    return 1;
}

void func_02044258(s32 arg0) {
    extern M2C_UNK data_0213d39c;
    M2C_FIELD(&data_0213d39c, s32 *, 4) = arg0;
}

s32 func_02044268(void) {
    extern M2C_UNK data_0213d39c;
    return M2C_FIELD(&data_0213d39c, s32 *, 4);
}

void func_02044278(s32 arg0) {
 extern M2C_UNK data_0213d39c;
 M2C_FIELD(M2C_FIELD(&data_0213d39c, void **, 4), s32 *, 0x1A0) = arg0;
}

void func_0204428c(M2C_UNK arg0) {
    M2C_UNK func_0204429c(M2C_UNK, M2C_UNK);
    func_0204429c(arg0, 1);
}

s32 func_0204429c(M2C_UNK arg0, s32 arg1) {
    s32 func_0203761c();
    s32 func_02038f34(M2C_UNK);
    s32 func_020391b8(M2C_UNK);
    s32 func_020446e8(s32);
    s32 func_02044a08(M2C_UNK);
    s32 temp_r4;

    if ((func_0203761c() != 0) || ((arg1 == 1) && (func_02038f34(arg0) == 0)) || (func_020391b8(arg0) == 0)) {
        return 0;
    }
    if (func_02044a08(arg0) == 1) {
        return 0;
    }
    temp_r4 = func_02044de0(arg0);
    if (temp_r4 >= func_020446e8(arg1)) {
        return 1;
    }
    return 0;
}

s32 func_0204431c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_0204433c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    return func_0204433c(1, arg0, arg1, arg2);
}

s32 func_0204433c(s32 kind,s32 channel,s32 buffer,s32 size) {
extern s32 data_0213db14;
void *func_020449f0(s32);
void func_0204467c(void *,s16,s32);
void func_02044a40(s32,s32,s32,s32);
void *p;
s32 n, total;
u32 header[2];
void (*callback)(s32,s32);
p=func_020449f0(channel);
if(!func_0204429c(channel,kind)) return 0;
M2C_FIELD(p,u8 *,0x1c)=1;
M2C_FIELD(p,s32 *,0)=buffer;
M2C_FIELD(p,s32 *,0xc)=0;
M2C_FIELD(p,s32 *,0x14)=size;
((void (*)(void *,s32,s32))func_0204467c)(header,kind,size);
func_02044a40(channel,(s32)header,8,1);
n=M2C_FIELD(data_0213db14,u16 *,0x610);
if(size<=n)n=size;
if(n>func_02044de0(channel))return 1;
func_02044a40(channel,buffer,n,1);
M2C_FIELD(p,s32 *,0xc)+=n;
total=M2C_FIELD(p,s32 *,0x14);
if(M2C_FIELD(p,s32 *,0xc)==total) {
M2C_FIELD(p,u8 *,0x1c)=0;
M2C_FIELD(p,s32 *,0)=0;
M2C_FIELD(p,s32 *,0xc)=0;
M2C_FIELD(p,s32 *,0x14)=0;
callback=M2C_FIELD(data_0213db14,void (**)(s32,s32),0x600);
if(callback && kind==1) callback(total,channel);
}
return 1;
}

s32 func_0204445c(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 var_r10;
 s32 var_r6;
 u8 var_r9;
 var_r6 = arg0;
 var_r9 = 0;
 do {
  if (var_r9 != 0) var_r10 = 1 << var_r9;
  else var_r10 = 1;
  if ((var_r6 & var_r10) && (var_r9 != func_02038e94()) && (func_0204431c(var_r9, arg1, arg2) == 0)) var_r6 &= ~var_r10;
  var_r9 += 1;
 } while ((u32)var_r9 < 0x20U);
 return var_r6;
}

s32 func_020444cc(u8 arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 func_0203761c(void);
 s32 func_02038f34(M2C_UNK);
 void func_02044a40(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
 extern s32 data_0213db14;
 void (*callback)(s32, M2C_UNK);
 if (func_0203761c() != 0) return 0;
 if (func_02038f34(arg0) == 0) return 0;
 if (arg2 > M2C_FIELD(data_0213db14, u16 *, 0x610)) return 0;
 func_02044a40(arg0, arg1, arg2, 0);
 callback = M2C_FIELD(data_0213db14, void (**)(s32, M2C_UNK), 0x600);
 if (callback != NULL) callback(arg2, arg0);
 return 1;
}

s32 func_0204455c(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_020444cc(u8, M2C_UNK, M2C_UNK);
    s32 var_r10;
    s32 var_r6;
    u8 var_r9;

    var_r6 = arg0;
    var_r9 = 0;
    do {
        if (var_r9 != 0) {
            var_r10 = 1 << var_r9;
        } else {
            var_r10 = 1;
        }
        if ((var_r6 & var_r10) && (var_r9 != func_02038e94()) && (func_020444cc(var_r9, arg1, arg2) == 0)) {
            var_r6 &= ~var_r10;
        }
        var_r9 += 1;
    } while ((u32) var_r9 < 0x20U);
    return var_r6;
}

s32 func_020445cc(s32 a,s32 b,s32 c){void *func_020449f0();void *p=func_020449f0(a);if(func_02044a24(a)==2)return 0;M2C_FIELD(p,s32 *,4)=b;M2C_FIELD(p,s32 *,8)=c;M2C_FIELD(p,u8 *,0x1d)=1;M2C_FIELD(p,s32 *,0x10)=0;M2C_FIELD(p,s32 *,0x18)=0;return 1;}

s32 func_02044618(s32 a){extern s32 data_0213db14;if(!data_0213db14)return 0;M2C_FIELD(data_0213db14,s32 *,0x600)=a;return 1;}

s32 func_02044638(s32 a){extern s32 data_0213db14;if(!data_0213db14)return 0;M2C_FIELD(data_0213db14,s32 *,0x604)=a;return 1;}

s32 func_02044658(u16 a){extern s32 data_0213db14;if(!data_0213db14)return 0;M2C_FIELD(data_0213db14,u16 *,0x610)=a;return 1;}

void func_0204467c(void *arg0, s16 arg1, s32 arg2) {
    M2C_UNK func_02068d18(s32, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fca34;
    func_02068d18(arg0 + 6, &data_020fca34, 2);
    M2C_FIELD(arg0, s16 *, 4) = arg1;
    M2C_FIELD(arg0, s32 *, 0) = arg2;
}

u16 func_020446ac(void *a){void func_02008048(void *,void *,s32);s32 func_0206527c(void *,void *,s32);extern M2C_UNK data_020fca34;u16 buf[4];func_02008048(a,buf,8);if(func_0206527c(&buf[3],&data_020fca34,2)==0)return buf[2];return 0;}

s32 func_020446e8(s32 a){switch(a){case 2:case 3:case 4:return 12;default:return 8;}}

void func_02044708(s32 a){extern s32 data_0213db14;void func_02007f8c(s32,s32,s32);data_0213db14=a;func_02007f8c(a,0,0x614);M2C_FIELD(data_0213db14,u16 *,0x610)=0x5b9;}

void func_02044744(s32 a,s32 b,s32 c,s32 d){extern s32 data_0213db14;void func_02044a68(s32,s32,s32);void func_02044b5c(s32,s32,s32);if(!data_0213db14)return;if(!b||!c)return;if(d)func_02044a68(a,b,c);else func_02044b5c(a,b,c);}

void func_02044780(s32 a,s32 b){extern s32 data_0213db14;s32 func_020390b4(s32);s32 c;if(!M2C_FIELD(data_0213db14,s32 *,0x60c))return;c=func_020390b4(a);M2C_FIELD(data_0213db14,void (**)(s32,s32),0x60c)(b,c);}

void func_02044954(s32 a){extern s32 data_0213db14;if(!data_0213db14)return;M2C_FIELD(data_0213db14+a*0x30,s32 *,0xc)=0;M2C_FIELD(data_0213db14+a*0x30,s32 *,0x10)=0;M2C_FIELD(data_0213db14+a*0x30,s32 *,0x14)=0;M2C_FIELD(data_0213db14+a*0x30,s32 *,0x18)=0;M2C_FIELD(data_0213db14+a*0x30,u8 *,0x1c)=0;if(((u8 *)(data_0213db14+0x1d))[a*0x30])((u8 *)(data_0213db14+0x1d))[a*0x30]=1;M2C_FIELD(data_0213db14+a*0x30,u16 *,0x22)=0;}

void func_020449dc(void) {
    extern s32 data_0213db14;
    data_0213db14 = 0;
}

void *func_020449f0(s32 a){extern s32 data_0213db14;return (void *)(data_0213db14+0x30*a);}

s32 func_02044a08(s32 a){extern s32 data_0213db14;return M2C_FIELD(data_0213db14+0x30*a,u8 *,0x1c);}

s32 func_02044a24(s32 a){extern s32 data_0213db14;return M2C_FIELD(data_0213db14+0x30*a,u8 *,0x1d);}

void func_02044a40(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
 s32 func_02039050(M2C_UNK);
 void func_0205af48(s32, M2C_UNK, M2C_UNK, M2C_UNK);
 func_0205af48(func_02039050(arg0), arg1, arg2, arg3);
}

/* Handle an inbound transfer request for slot `a`: dispatch by the slot's state. */
void func_02044a68(s32 a, s32 b, s32 c) {
    extern s32 data_0213db14;
    s32 func_020390b4(s32);
    s32 func_02044a24(s32);
    u16 func_020446ac(void *);
    void func_02044da4(M2C_UNK, M2C_UNK);
    void func_02044bf8(s32, s32, s32);
    void func_02044cc0(s32, void *, s32);
    void func_02037638(s32, s32);

    s32 id = func_020390b4(a);
    u32 kind;

    switch (func_02044a24(id)) {
    case 0:
        kind = func_020446ac((void *)b);
        if (kind < 2) return;
        if (kind > 4) return;
        func_02044bf8(id, b, c);
        break;
    case 1:
        func_02044bf8(id, b, c);
        break;
    case 2:
        func_02044cc0(id, (void *)b, c);
        break;
    case 3:
        ((void (*)(s32, s32, s32))func_02044da4)(id, b, c);
        break;
    case 4:
        M2C_FIELD(data_0213db14 + id * 0x30, u8 *, 0x1d) = 1;
        M2C_FIELD(data_0213db14 + id * 0x30, s32 *, 0x10) = 0;
        M2C_FIELD(data_0213db14 + id * 0x30, s32 *, 0x18) = 0;
        break;
    default:
        func_02037638(6, 0xfffe82b6);
        break;
    }
}

void func_02044b5c(s32 a,s32 b,s32 c){extern s32 data_0213db14;s32 func_020390b4(s32);void func_02008048(void *,void *,s32);u64 func_02007004(void);s32 i;void *p;void *q;void (*cb)(s32,void *,s32);i=func_020390b4(a);p=(void *)(data_0213db14+i*0x30);q=M2C_FIELD(p,void **,4);if(!q)return;if(M2C_FIELD(p,s32 *,8)<c)return;func_02008048((void *)b,q,c);cb=M2C_FIELD(data_0213db14,void (**)(s32,void *,s32),0x604);if(cb)cb(i,M2C_FIELD(p,void **,4),c);if(!M2C_FIELD(data_0213db14,s32 *,0x608)||!M2C_FIELD(p,s32 *,0x2c))return;M2C_FIELD(p,u64 *,0x24)=func_02007004();}

void func_02044bf8(s32 a,s32 b,s32 c) {
extern s32 data_0213db14;
u8 buf[8]; void *p; s32 v; p=(void *)data_0213db14; p=(u8 *)p+a*0x30;
M2C_FIELD(p,u8 *,0x1e)=func_02044a24(a);
v=func_020446ac(b);
switch(v){
case 1:
if(c!=8)return;
func_02008048(b,buf,8);
M2C_FIELD(p,s32 *,0x18)=*(s32 *)buf;
M2C_FIELD(p,s32 *,0x10)=0;
if(M2C_FIELD(p,s32 *,4)){
if(M2C_FIELD(p,s32 *,8)>=M2C_FIELD(p,s32 *,0x18)){M2C_FIELD(p,u8 *,0x1d)=2;goto done;}
M2C_FIELD(p,u8 *,0x1d)=4;
break;
}
case 2:case 3:case 4: M2C_FIELD(p,u8 *,0x1d)=3;break;
}
done:
M2C_FIELD(p,u16 *,0x22)=v;
}

void func_02044cc0(s32 a,void *b,s32 c){
extern s32 data_0213db14; s32 func_02044a24(s32); void func_02008048(void *,void *,s32);void func_02037638(s32,s32);u64 func_02007004(void);
void *p;void (*cb)(s32,void *,s32);s32 pos,len;
p=(void *)(data_0213db14+a*0x30);
if(func_02044a24(a)==2){
pos=M2C_FIELD(p,s32 *,0x10);
if(pos+c>M2C_FIELD(p,s32 *,8)){func_02037638(6,0xfffe82ac);return;}
func_02008048(b,M2C_FIELD(p,u8 **,4)+pos,c);
}
M2C_FIELD(p,s32 *,0x10)+=c;
len=M2C_FIELD(p,s32 *,0x18);
if(M2C_FIELD(p,s32 *,0x10)==len){
M2C_FIELD(p,u8 *,0x1d)=1;M2C_FIELD(p,s32 *,0x10)=0;M2C_FIELD(p,s32 *,0x18)=0;
cb=M2C_FIELD(data_0213db14,void (**)(s32,void *,s32),0x604);
if(cb)cb(a,M2C_FIELD(p,void **,4),len);
}
if(!M2C_FIELD(data_0213db14,s32 *,0x608)||!M2C_FIELD(p,s32 *,0x2c))return;
M2C_FIELD(p,u64 *,0x24)=func_02007004();
}

void func_02044da4(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0203dd30(M2C_UNK, u16, M2C_UNK);
    void *func_020449f0();
    u16 temp_r1;
    void *temp_r0;

    temp_r0 = func_020449f0();
    M2C_FIELD(temp_r0, u8 *, 0x1D) = (u8) M2C_FIELD(temp_r0, u8 *, 0x1E);
    temp_r1 = M2C_FIELD(temp_r0, u16 *, 0x22);
    if ((temp_r1 != 2) && (temp_r1 != 3) && (temp_r1 != 4)) {
        return;
    }
    func_0203dd30(arg0, temp_r1, arg1);
}

s32 func_02044de0(void) {
    M2C_UNK func_02039050();
    s32 func_0205b038();
    s32 var_r0;

    func_02039050();
    var_r0 = func_0205b038() + 0xFFFFFDF9;
    if (var_r0 <= 0) {
        var_r0 = 0;
    }
    return var_r0;
}

