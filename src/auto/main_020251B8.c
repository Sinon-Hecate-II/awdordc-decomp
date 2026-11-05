/* 16 functions from 0x020251B8 to 0x02026164 (main), found by ds-decomp. */
#include "common.h"
void func_020258ac(void *, u32 *, u32);

void func_020251b8(s32 now) {
void func_0200751c(void);void func_02007530(void);void func_02005e5c(void *);
extern M2C_UNK data_02138cc8;extern M2C_UNK data_0212dca4;
void *q; u8 *p; s32 i; void *node;
func_0200751c();
i=0;p=(u8 *)&data_02138cc8;
do{
if(p[0x5a]!=0 &&(now-M2C_FIELD(p,s32 *,0x50)>957))p[0x5a]=0;
p+=0x5c;i++;
}while(i<4);
func_02007530();
node=M2C_FIELD(&data_0212dca4,void **,8);
while(node!=NULL){
q=M2C_FIELD(node,void **,0xa4);
if(q!=NULL && M2C_FIELD(q,void **,0)!=NULL && M2C_FIELD(q,u8 *,9)!=0 && M2C_FIELD(q,u8 *,8)==4 && M2C_FIELD(M2C_FIELD(q,void **,12),u8 *,0x455)<8 && now-M2C_FIELD(q,s32 *,16)>239 && M2C_FIELD(q,s32 *,4)==2){
M2C_FIELD(q,u8 *,8)=0;M2C_FIELD(q,s32 *,4)=0;func_02005e5c(M2C_FIELD(q,void **,0));
}
node=M2C_FIELD(node,void **,0x68);
}
}

void func_02025298(void) {
    M2C_UNK func_02007f8c(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_02138cc8;
    func_02007f8c(&data_02138cc8, 0, 0x170);
}

void func_020252b4(M2C_UNK *arg0, void *arg1, u32 arg2) {
    void func_02008048(s32, void *, u32);
    func_02008048(arg1, arg0, arg2);
}

void func_020252cc(M2C_UNK *arg0, void *arg1, u32 arg2) {
    void func_02008048(s32, void *, u32);
    func_02008048(arg1, arg0, arg2);
}

void func_020252e4(void *state,s32 block){
extern u8 data_020fb064;extern u32 data_020fb0e4;
u32 a,b,c,d,buf[16];s32 n,i;u32 t;
a=M2C_FIELD(state,u32*,0);b=M2C_FIELD(state,u32*,4);c=M2C_FIELD(state,u32*,8);d=M2C_FIELD(state,u32*,12);
func_020252cc(buf,block,64);n=0;
for(i=0;i<4;i++){
t=a + (((u32*)&data_020fb0e4)[n+0]+((d ^ (b & (c ^ d)))+buf[((u8*)&data_020fb064)[n+0]]));
a=b+((t<<7)|(t>>25));
t=d + (((u32*)&data_020fb0e4)[n+1]+((c ^ (a & (b ^ c)))+buf[((u8*)&data_020fb064)[n+1]]));
d=a+((t<<12)|(t>>20));
t=c + (((u32*)&data_020fb0e4)[n+2]+((b ^ (d & (a ^ b)))+buf[((u8*)&data_020fb064)[n+2]]));
c=d+((t<<17)|(t>>15));
t=b + (((u32*)&data_020fb0e4)[n+3]+((a ^ (c & (d ^ a)))+buf[((u8*)&data_020fb064)[n+3]]));
b=c+((t<<22)|(t>>10));
n+=4;
}
for(i=0;i<4;i++){
t=a + (((u32*)&data_020fb0e4)[n+0]+((c ^ (d & (b ^ c)))+buf[((u8*)&data_020fb064)[n+0]]));
a=b+((t<<5)|(t>>27));
t=d + (((u32*)&data_020fb0e4)[n+1]+((b ^ (c & (a ^ b)))+buf[((u8*)&data_020fb064)[n+1]]));
d=a+((t<<9)|(t>>23));
t=c + (((u32*)&data_020fb0e4)[n+2]+((a ^ (b & (d ^ a)))+buf[((u8*)&data_020fb064)[n+2]]));
c=d+((t<<14)|(t>>18));
t=b + (((u32*)&data_020fb0e4)[n+3]+((d ^ (a & (c ^ d)))+buf[((u8*)&data_020fb064)[n+3]]));
b=c+((t<<20)|(t>>12));
n+=4;
}
for(i=0;i<4;i++){
t=a + (((u32*)&data_020fb0e4)[n+0]+((d ^ (b ^ c))+buf[((u8*)&data_020fb064)[n+0]]));
a=b+((t<<4)|(t>>28));
t=d + (((u32*)&data_020fb0e4)[n+1]+((c ^ (a ^ b))+buf[((u8*)&data_020fb064)[n+1]]));
d=a+((t<<11)|(t>>21));
t=c + (((u32*)&data_020fb0e4)[n+2]+((b ^ (d ^ a))+buf[((u8*)&data_020fb064)[n+2]]));
c=d+((t<<16)|(t>>16));
t=b + (((u32*)&data_020fb0e4)[n+3]+((a ^ (c ^ d))+buf[((u8*)&data_020fb064)[n+3]]));
b=c+((t<<23)|(t>>9));
n+=4;
}
for(i=0;i<4;i++){
t=a + (((u32*)&data_020fb0e4)[n+0]+((c ^ (b | ~d))+buf[((u8*)&data_020fb064)[n+0]]));
a=b+((t<<6)|(t>>26));
t=d + (((u32*)&data_020fb0e4)[n+1]+((b ^ (a | ~c))+buf[((u8*)&data_020fb064)[n+1]]));
d=a+((t<<10)|(t>>22));
t=c + (((u32*)&data_020fb0e4)[n+2]+((a ^ (d | ~b))+buf[((u8*)&data_020fb064)[n+2]]));
c=d+((t<<15)|(t>>17));
t=b + (((u32*)&data_020fb0e4)[n+3]+((d ^ (c | ~a))+buf[((u8*)&data_020fb064)[n+3]]));
b=c+((t<<21)|(t>>11));
n+=4;
}
M2C_FIELD(state,u32*,0)+=a;M2C_FIELD(state,u32*,4)+=b;M2C_FIELD(state,u32*,8)+=c;M2C_FIELD(state,u32*,12)+=d;
}

void func_02025700(void *arg0) {
    func_02007f8c(arg0, 0, 0x58);
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
}

void func_02025748(void *arg0, s32 arg1, u32 arg2) {
void func_02008048(s32,void *,u32); void func_020252e4(void *,s32);
u32 index,low,old,count;
old=M2C_FIELD(arg0,u32 *,0x10);
low=old+(arg2<<3); M2C_FIELD(arg0,u32 *,0x10)=low;
if(low<(arg2<<3))M2C_FIELD(arg0,u32 *,0x14)++;
arg2=arg2; old >>= 3; index=old&63; count=64-index;
M2C_FIELD(arg0,u32 *,0x14)+=arg2>>29;
if(arg2>=count){func_02008048(arg1,(u8 *)arg0+24+index,count);index=0;func_020252e4(arg0,(s32)arg0+24);
while(count+63<arg2){func_020252e4(arg0,arg1+(s32)count);count+=64;}
}else count=0;
func_02008048(arg1+count,(u8 *)arg0+24+index,arg2-count);
}


void func_02025800(void *arg0, M2C_UNK *arg1) {
    void func_020252b4(M2C_UNK *, void *, u32);
    void func_02025748(void *, s32, u32);
    extern M2C_UNK data_020fb0a4;
    s32 temp_r0;
    s32 var_r2;

    func_020252b4(arg1, arg0 + 0x10, 8);
    temp_r0 = ((u32) M2C_FIELD(arg0, u32 *, 0x10) >> 3) & 0x3F;
    if (temp_r0 < 0x38) {
        var_r2 = 0x38 - temp_r0;
    } else {
        var_r2 = 0x78 - temp_r0;
    }
    func_02025748(arg0, &data_020fb0a4, var_r2);
    func_02025748(arg0, arg1, 8);
    func_020252b4(arg1, arg0, 0x10);
}

s32 func_02025868(s32 arg0, u32 *arg1) {
    u32 value;
    u32 result;
    value = arg1[arg0] ^ (arg1[(arg0 + 2) & 15] ^ (arg1[(arg0 + 13) & 15] ^ arg1[arg0 ^ 8]));
    result = (value << 1) | (value >> 31);
    arg1[arg0] = result;
    return result;
}

void func_020258ac(void *arg0, u32 *arg1, u32 arg2) {
    u8 *out = arg0;
    
    u32 i = 0;
    u32 value;
    arg2 >>= 2;
    if (arg2 == 0) return;
    do {
        value = *arg1++;
        i++;
        out[0] = value >> 24;
        out[1] = value >> 16;
        out[2] = value >> 8;
        out[3] = value;
        out += 4;
    } while (i < arg2);
}

#pragma opt_peephole off
void func_020258f0(u32 *arg0,u8 *arg1,u32 arg2) {
u32 i=0,value; u8 *p; u8 last;
if(i>=arg2)return;
do {
p=arg1+i;
last=p[3];
value=(p[1]<<16)|(arg1[i]<<24)|(p[2]<<8);
i+=4;
*arg0++=last|value;
}while(i<arg2);
}
#pragma opt_peephole reset
void func_02025938(void *state,s32 block){
u32 a,b,c,d,e; s32 n,i;u32 w[16];
a=((u32 *)state)[0];b=((u32 *)state)[1];c=((u32 *)state)[2];d=((u32 *)state)[3];e=((u32 *)state)[4];
func_020258f0(w,(u8 *)block,64);n=0;
for(i=0;i<3;i++){
e += ((((a << 5) | (a >> 27)) + (d ^ (b & (c ^ d)))) + w[n+0]) + 0x5a827999;
b = (b << 30) | (b >> 2);
d += ((((e << 5) | (e >> 27)) + (c ^ (a & (b ^ c)))) + w[n+1]) + 0x5a827999;
a = (a << 30) | (a >> 2);
c += ((((d << 5) | (d >> 27)) + (b ^ (e & (a ^ b)))) + w[n+2]) + 0x5a827999;
e = (e << 30) | (e >> 2);
b += ((((c << 5) | (c >> 27)) + (a ^ (d & (e ^ a)))) + w[n+3]) + 0x5a827999;
d = (d << 30) | (d >> 2);
a += ((((b << 5) | (b >> 27)) + (e ^ (c & (d ^ e)))) + w[n+4]) + 0x5a827999;
c = (c << 30) | (c >> 2);
n+=5;
}
e += ((((a << 5) | (a >> 27)) + (d ^ (b & (c ^ d)))) + w[15]) + 0x5a827999;
b = (b << 30) | (b >> 2);
d += ((((e << 5) | (e >> 27)) + (c ^ (a & (b ^ c)))) + func_02025868(0,w)) + 0x5a827999;
a = (a << 30) | (a >> 2);
c += ((((d << 5) | (d >> 27)) + (b ^ (e & (a ^ b)))) + func_02025868(1,w)) + 0x5a827999;
e = (e << 30) | (e >> 2);
b += ((((c << 5) | (c >> 27)) + (a ^ (d & (e ^ a)))) + func_02025868(2,w)) + 0x5a827999;
d = (d << 30) | (d >> 2);
a += ((((b << 5) | (b >> 27)) + (e ^ (c & (d ^ e)))) + func_02025868(3,w)) + 0x5a827999;
c = (c << 30) | (c >> 2);
n=4;
for(i=0;i<4;i++){
e += ((((a << 5) | (a >> 27)) + (d ^ (b ^ c))) + func_02025868(n,w)) + 0x6ed9eba1;
b = (b << 30) | (b >> 2);
d += ((((e << 5) | (e >> 27)) + (c ^ (a ^ b))) + func_02025868(n+1,w)) + 0x6ed9eba1;
a = (a << 30) | (a >> 2);
n=(n+2)&15;
c += ((((d << 5) | (d >> 27)) + (b ^ (e ^ a))) + func_02025868(n,w)) + 0x6ed9eba1;
e = (e << 30) | (e >> 2);
b += ((((c << 5) | (c >> 27)) + (a ^ (d ^ e))) + func_02025868(n+1,w)) + 0x6ed9eba1;
d = (d << 30) | (d >> 2);
a += ((((b << 5) | (b >> 27)) + (e ^ (c ^ d))) + func_02025868(n+2,w)) + 0x6ed9eba1;
c = (c << 30) | (c >> 2);
n+=3;
}
for(i=0;i<4;i++){
e += ((((a << 5) | (a >> 27)) + ((b & (c | d)) | (c & d))) + func_02025868(n,w)) + 0x8f1bbcdc;
b = (b << 30) | (b >> 2);
d += ((((e << 5) | (e >> 27)) + ((a & (b | c)) | (b & c))) + func_02025868(n+1,w)) + 0x8f1bbcdc;
a = (a << 30) | (a >> 2);
c += ((((d << 5) | (d >> 27)) + ((e & (a | b)) | (a & b))) + func_02025868(n+2,w)) + 0x8f1bbcdc;
e = (e << 30) | (e >> 2);
n=(n+3)&15;
b += ((((c << 5) | (c >> 27)) + ((d & (e | a)) | (e & a))) + func_02025868(n,w)) + 0x8f1bbcdc;
d = (d << 30) | (d >> 2);
a += ((((b << 5) | (b >> 27)) + ((c & (d | e)) | (d & e))) + func_02025868(n+1,w)) + 0x8f1bbcdc;
c = (c << 30) | (c >> 2);
n+=2;
}
for(i=0;i<4;i++){
e += ((((a << 5) | (a >> 27)) + (d ^ (b ^ c))) + func_02025868(n,w)) + 0xca62c1d6;
b = (b << 30) | (b >> 2);
d += ((((e << 5) | (e >> 27)) + (c ^ (a ^ b))) + func_02025868(n+1,w)) + 0xca62c1d6;
a = (a << 30) | (a >> 2);
c += ((((d << 5) | (d >> 27)) + (b ^ (e ^ a))) + func_02025868(n+2,w)) + 0xca62c1d6;
e = (e << 30) | (e >> 2);
b += ((((c << 5) | (c >> 27)) + (a ^ (d ^ e))) + func_02025868(n+3,w)) + 0xca62c1d6;
d = (d << 30) | (d >> 2);
n=(n+4)&15;
a += ((((b << 5) | (b >> 27)) + (e ^ (c ^ d))) + func_02025868(n,w)) + 0xca62c1d6;
c = (c << 30) | (c >> 2);
n+=1;
}
((u32 *)state)[0]+=a;((u32 *)state)[1]+=b;((u32 *)state)[2]+=c;((u32 *)state)[3]+=d;((u32 *)state)[4]+=e;
}

void func_02025fc0(void *arg0) {
    func_02007f8c(arg0, 0, 0x5C);
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
    M2C_FIELD(arg0, s32 *, 0x10) = 0xC3D2E1F0;
}

#pragma opt_strength_reduction off
M2C_UNK func_02026014(void *arg0,s32 arg1,u32 arg2) {
void func_02008048(s32,void *,u32); void func_02025938(void *,s32);
s32 index; u32 low,old,count;
old=M2C_FIELD(arg0,u32 *,0x18);
index=(old>>3)&63;
low=old+arg2*8;M2C_FIELD(arg0,u32 *,0x18)=low;
if(low<arg2*8)M2C_FIELD(arg0,u32 *,0x14)++;
count=64-index;
M2C_FIELD(arg0,u32 *,0x14)+=arg2>>29;
if(arg2>=count) {
func_02008048(arg1,(u8 *)arg0+0x1c+index,count);
index=0;func_02025938(arg0,(s32)arg0+0x1c);
while(count+63<arg2){func_02025938(arg0,arg1+count);count+=64;}
}else count=0;
func_02008048(arg1+count,(u8 *)arg0+0x1c+index,arg2-count);
}
#pragma opt_strength_reduction reset
void func_020260cc(void *arg0, M2C_UNK *arg1) {
    extern M2C_UNK data_020fb1e4;
    s32 temp_r0;
    s32 var_r2;

    func_020258ac(arg1, arg0 + 0x14, 8);
    temp_r0 = ((u32) M2C_FIELD(arg0, u32 *, 0x18) >> 3) & 0x3F;
    if (temp_r0 < 0x38) {
        var_r2 = 0x38 - temp_r0;
    } else {
        var_r2 = 0x78 - temp_r0;
    }
    func_02026014(arg0, &data_020fb1e4, var_r2);
    func_02026014(arg0, arg1, 8);
    func_020258ac(arg1, arg0, 0x14);
}

void func_02026134(M2C_UNK arg0, M2C_UNK arg1) {
    void func_020258ac(void *, u32 *, u32);
    M2C_UNK func_02026014();
    extern M2C_UNK data_020fb1e5;
    func_02026014(arg0, &data_020fb1e5, 0x2C);
    func_020258ac(arg1, arg0, 0x14);
}

