/* 16 functions from 0x020251B8 to 0x02026164 (main), found by ds-decomp. */
#include "common.h"
void func_020258ac(void *, u32 *, u32);

void func_020251b8(s32 now) {
void OS_DisableInterrupts(void);void OS_RestoreInterrupts(void);void TaskWake(void *);
extern M2C_UNK data_02138cc8;extern M2C_UNK gSocketManager;
u8 *p; s32 i; void *node; void *q;
OS_DisableInterrupts();
i=0;p=(u8 *)&data_02138cc8;
do{
if(p[0x5a]!=0 && now-M2C_FIELD(p,s32 *,0x50)>957)p[0x5a]=0;
i++;p+=0x5c;
}while(i<4);
OS_RestoreInterrupts();
node=M2C_FIELD(&gSocketManager,void **,8);
while(node!=NULL){
q=M2C_FIELD(node,void **,0xa4);
if(q!=NULL && M2C_FIELD(q,void **,0)!=NULL && M2C_FIELD(q,u8 *,9)!=0 && M2C_FIELD(q,u8 *,8)==4 && M2C_FIELD(M2C_FIELD(q,void **,12),u8 *,0x455)<8 && now-M2C_FIELD(q,s32 *,16)>239 && M2C_FIELD(q,s32 *,4)==2){
M2C_FIELD(q,u8 *,8)=0;M2C_FIELD(q,s32 *,4)=0;TaskWake(M2C_FIELD(q,void **,0));
}
node=M2C_FIELD(node,void **,0x68);
}
}

void func_02025298(void) {
    M2C_UNK MI_CpuFill8(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_02138cc8;
    MI_CpuFill8(&data_02138cc8, 0, 0x170);
}

void func_020252b4(M2C_UNK *arg0, void *arg1, u32 arg2) {
    void MI_CpuCopy8(s32, void *, u32);
    MI_CpuCopy8(arg1, arg0, arg2);
}

void func_020252cc(M2C_UNK *arg0, void *arg1, u32 arg2) {
    void MI_CpuCopy8(s32, void *, u32);
    MI_CpuCopy8(arg1, arg0, arg2);
}

/* MD5 compression function: mixes one 64-byte block into the 16-byte state
 * (a,b,c,d) using the MD5 K table and the per-step message-word permutation. */
void MD5_Transform(void *state,s32 block){
extern u8 gMd5MessageIndex;extern u32 gMd5Constants;
u32 a,b,c,d,words[16];s32 offset,i;u32 tmp;
a=M2C_FIELD(state,u32*,0);b=M2C_FIELD(state,u32*,4);c=M2C_FIELD(state,u32*,8);d=M2C_FIELD(state,u32*,12);
func_020252cc(words,block,64);offset=0;
for(i=0;i<4;i++){
tmp=a + (((u32*)&gMd5Constants)[offset+0]+((d ^ (b & (c ^ d)))+words[((u8*)&gMd5MessageIndex)[offset+0]]));
a=b+((tmp<<7)|(tmp>>25));
tmp=d + (((u32*)&gMd5Constants)[offset+1]+((c ^ (a & (b ^ c)))+words[((u8*)&gMd5MessageIndex)[offset+1]]));
d=a+((tmp<<12)|(tmp>>20));
tmp=c + (((u32*)&gMd5Constants)[offset+2]+((b ^ (d & (a ^ b)))+words[((u8*)&gMd5MessageIndex)[offset+2]]));
c=d+((tmp<<17)|(tmp>>15));
tmp=b + (((u32*)&gMd5Constants)[offset+3]+((a ^ (c & (d ^ a)))+words[((u8*)&gMd5MessageIndex)[offset+3]]));
b=c+((tmp<<22)|(tmp>>10));
offset+=4;
}
for(i=0;i<4;i++){
tmp=a + (((u32*)&gMd5Constants)[offset+0]+((c ^ (d & (b ^ c)))+words[((u8*)&gMd5MessageIndex)[offset+0]]));
a=b+((tmp<<5)|(tmp>>27));
tmp=d + (((u32*)&gMd5Constants)[offset+1]+((b ^ (c & (a ^ b)))+words[((u8*)&gMd5MessageIndex)[offset+1]]));
d=a+((tmp<<9)|(tmp>>23));
tmp=c + (((u32*)&gMd5Constants)[offset+2]+((a ^ (b & (d ^ a)))+words[((u8*)&gMd5MessageIndex)[offset+2]]));
c=d+((tmp<<14)|(tmp>>18));
tmp=b + (((u32*)&gMd5Constants)[offset+3]+((d ^ (a & (c ^ d)))+words[((u8*)&gMd5MessageIndex)[offset+3]]));
b=c+((tmp<<20)|(tmp>>12));
offset+=4;
}
for(i=0;i<4;i++){
tmp=a + (((u32*)&gMd5Constants)[offset+0]+((d ^ (b ^ c))+words[((u8*)&gMd5MessageIndex)[offset+0]]));
a=b+((tmp<<4)|(tmp>>28));
tmp=d + (((u32*)&gMd5Constants)[offset+1]+((c ^ (a ^ b))+words[((u8*)&gMd5MessageIndex)[offset+1]]));
d=a+((tmp<<11)|(tmp>>21));
tmp=c + (((u32*)&gMd5Constants)[offset+2]+((b ^ (d ^ a))+words[((u8*)&gMd5MessageIndex)[offset+2]]));
c=d+((tmp<<16)|(tmp>>16));
tmp=b + (((u32*)&gMd5Constants)[offset+3]+((a ^ (c ^ d))+words[((u8*)&gMd5MessageIndex)[offset+3]]));
b=c+((tmp<<23)|(tmp>>9));
offset+=4;
}
for(i=0;i<4;i++){
tmp=a + (((u32*)&gMd5Constants)[offset+0]+((c ^ (b | ~d))+words[((u8*)&gMd5MessageIndex)[offset+0]]));
a=b+((tmp<<6)|(tmp>>26));
tmp=d + (((u32*)&gMd5Constants)[offset+1]+((b ^ (a | ~c))+words[((u8*)&gMd5MessageIndex)[offset+1]]));
d=a+((tmp<<10)|(tmp>>22));
tmp=c + (((u32*)&gMd5Constants)[offset+2]+((a ^ (d | ~b))+words[((u8*)&gMd5MessageIndex)[offset+2]]));
c=d+((tmp<<15)|(tmp>>17));
tmp=b + (((u32*)&gMd5Constants)[offset+3]+((d ^ (c | ~a))+words[((u8*)&gMd5MessageIndex)[offset+3]]));
b=c+((tmp<<21)|(tmp>>11));
offset+=4;
}
M2C_FIELD(state,u32*,0)+=a;M2C_FIELD(state,u32*,4)+=b;M2C_FIELD(state,u32*,8)+=c;M2C_FIELD(state,u32*,12)+=d;
}

void MD5_Init(void *arg0) {
    MI_CpuFill8(arg0, 0, 0x58);
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
}

void MD5_Update(void *arg0, s32 arg1, u32 arg2) {
void MI_CpuCopy8(s32,void *,u32); void MD5_Transform(void *,s32);
u32 index,low,old,count;
old=M2C_FIELD(arg0,u32 *,0x10);
index=(old>>3)&63;
low=old+(arg2<<3); M2C_FIELD(arg0,u32 *,0x10)=low;
if(low<(arg2<<3))M2C_FIELD(arg0,u32 *,0x14)++;
count=64-index;
M2C_FIELD(arg0,u32 *,0x14)+=arg2>>29;
if(arg2>=count){MI_CpuCopy8(arg1,(u8 *)arg0+24+index,count);index=0;MD5_Transform(arg0,(s32)arg0+24);
while(count+63<arg2){MD5_Transform(arg0,arg1+(s32)count);count+=64;}
}else count=0;
MI_CpuCopy8(arg1+count,(u8 *)arg0+24+index,arg2-count);
}


void MD5_Final(void *arg0, M2C_UNK *arg1) {
    void func_020252b4(M2C_UNK *, void *, u32);
    void MD5_Update(void *, s32, u32);
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
    MD5_Update(arg0, &data_020fb0a4, var_r2);
    MD5_Update(arg0, arg1, 8);
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
u32 i=0,value;
if(i>=arg2)return;
do {
value=(arg1[i+1]<<16)|(arg1[i]<<24)|(arg1[i+2]<<8)|arg1[i+3];
i+=4;
*arg0++=value;
}while(i<arg2);
}
#pragma opt_peephole reset
void SHA1_Transform(void *state,s32 block){
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

void SHA1_Init(void *arg0) {
    MI_CpuFill8(arg0, 0, 0x5C);
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
    M2C_FIELD(arg0, s32 *, 0x10) = 0xC3D2E1F0;
}

#pragma opt_strength_reduction off
M2C_UNK SHA1_Update(void *arg0,s32 arg1,u32 arg2) {
void MI_CpuCopy8(s32,void *,u32); void SHA1_Transform(void *,s32);
s32 index; u32 low,old,count;
old=M2C_FIELD(arg0,u32 *,0x18);
index=(old>>3)&63;
low=old+arg2*8;M2C_FIELD(arg0,u32 *,0x18)=low;
if(low<arg2*8)M2C_FIELD(arg0,u32 *,0x14)++;
count=64-index;
M2C_FIELD(arg0,u32 *,0x14)+=arg2>>29;
if(arg2>=count) {
MI_CpuCopy8(arg1,(u8 *)arg0+0x1c+index,count);
index=0;SHA1_Transform(arg0,(s32)arg0+0x1c);
while(count+63<arg2){SHA1_Transform(arg0,arg1+count);count+=64;}
}else count=0;
MI_CpuCopy8(arg1+count,(u8 *)arg0+0x1c+index,arg2-count);
}
#pragma opt_strength_reduction reset
void SHA1_Final(void *arg0, M2C_UNK *arg1) {
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
    SHA1_Update(arg0, &data_020fb1e4, var_r2);
    SHA1_Update(arg0, arg1, 8);
    func_020258ac(arg1, arg0, 0x14);
}

void func_02026134(M2C_UNK arg0, M2C_UNK arg1) {
    void func_020258ac(void *, u32 *, u32);
    M2C_UNK SHA1_Update();
    extern M2C_UNK data_020fb1e5;
    SHA1_Update(arg0, &data_020fb1e5, 0x2C);
    func_020258ac(arg1, arg0, 0x14);
}

