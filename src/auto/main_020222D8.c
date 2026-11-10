/* 15 functions from 0x020222D8 to 0x020232B8 (main), found by ds-decomp. */
#include "common.h"
static inline u32 CertificateTag(u8 tag) { return tag & 31; }
typedef struct CertificateTagBits { u8 number:5; u8 constructed:1; u8 category:2; } CertificateTagBits;

s32 func_02022970(void *arg0) {
    void MD5_Init(void *);
    void MD5_Update(void *, void *, s32);
    void MD5_Final(void *, s32);
    void SHA1_Init(void *);
    void SHA1_Update(void *, void *, s32);
    void SHA1_Final(void *, void *);
    s32 func_02022150(void *, void *);
    s32 func_020227c8(void *, void *);
    s32 var_r4;
    s32 t0, t1;
    register s32 p asm("r1");
    if (*(u8 *)((u8 *)arg0 + 0x5af) != 0) {
        var_r4 = 0;
    } else {
        var_r4 = 0x8000;
    }
    if (*(s32 *)((u8 *)arg0 + 0x45c) == -1) {
        return var_r4 | 4;
    }
    switch (*(s32 *)((u8 *)arg0 + 0x458)) {
    case 3:
        MD5_Init((u8 *)arg0 + 0x3fc);
        t0 = *(s32 *)((u8 *)arg0 + 0x460);
        MD5_Update((u8 *)arg0 + 0x3fc, (void *)t0, *(s32 *)((u8 *)arg0 + 0x464) - t0);
        MD5_Final((u8 *)arg0 + 0x3fc, (s32)((u8 *)arg0 + 0x468));
        *(s32 *)((u8 *)arg0 + 0x47c) = 0x10;
        break;
    case 4:
        SHA1_Init((u8 *)arg0 + 0x348);
        t1 = *(s32 *)((u8 *)arg0 + 0x460);
        SHA1_Update((u8 *)arg0 + 0x348, (void *)t1, *(s32 *)((u8 *)arg0 + 0x464) - t1);
        SHA1_Final((u8 *)arg0 + 0x348, (u8 *)arg0 + 0x468);
        *(s32 *)((u8 *)arg0 + 0x47c) = 0x14;
        break;
    default:
        return var_r4 | 3;
    }
    p = func_02022150(arg0, (u8 *)arg0 + 0x5b0);
    if (p == 0) {
        return var_r4 | 1;
    }
    return var_r4 | func_020227c8(arg0, (void *)p);
}

s32 func_02022a54(s8 *p) {
s8 *start=p;
s32 c;
while((c=*p)!=0x2e && c!=0)p++;
return p-start;
}

s32 func_02022a78(s8 *p, s8 *q) {
    s32 a, b, c, d;
    do {
        while ((d = *p++) == (c = *q++)) {
            if (d == 0) return 0;
        }
        if (c != 0x2a) return 1;
        p--;
        a = func_02022a54(p);
        b = func_02022a54(q);
        if (b > a) return 1;
        p += a - b;
    } while (1);
}

void func_02022ae4(void *a, u8 *b) {
s32 func_020222d8(void *,u8 **,s32,s32,s32);
void func_0200ef4c(s32 *);
s32 func_020227c8(void *,void *);
s32 date[4]; u8 low; s32 result; u32 remaining; s32 i; u8 *next; u32 n;
n=b[0]; remaining=b[1]; remaining=b[2]+(((n<<8)+remaining)<<8);b+=3;
M2C_FIELD(a,s32 *,0x45c)=-1;
func_0200ef4c(date);
M2C_FIELD(a,s32 *,0x80c)=date[2]+((date[0]+2000<<16)+(date[1]<<8));
low=0;M2C_FIELD(a,u8 *,0x6b0)=low;
M2C_FIELD(a,s32 *,0x5a0)=low;M2C_FIELD(a,s32 *,0x594)=low;i=low;
do {
n=b[0];n=(n<<8)+b[1];n=(n<<8)+b[2];b+=3;
M2C_FIELD(a,s32 *,0x458)=-1;
M2C_FIELD(a,u8 *,0x5ad)=0;M2C_FIELD(a,u8 *,0x5ac)=0;M2C_FIELD(a,u8 *,0x5af)=0;M2C_FIELD(a,u8 *,0x6b0)=0;M2C_FIELD(a,u8 *,0x5b0)=0;M2C_FIELD(a,u8 *,0x7b0)=0;
M2C_FIELD(a,u8 **,0x804)=b;M2C_FIELD(a,u32 *,0x808)=n;
remaining-=n+3;
if(((s32 (*)(void *,u8 **,s32,s32,u8))func_020222d8)(a,&b,0,0,low)!=0 || M2C_FIELD(a,u32 *,0x594)<51 || M2C_FIELD(a,s32 *,0x5a0)==0){M2C_FIELD(a,u8 *,0x455)=9;return;}
result=func_02022970(a);
if(i==0 && M2C_FIELD(a,s8 **,0x800)!=0 && func_02022a78(M2C_FIELD(a,s8 **,0x800),(s8 *)a+0x7b0))result|=0x4000;
low=(u8)result;
if(low==1 && remaining){
next=b+3;M2C_FIELD(a,u8 *,0x5ad)=0;
if(func_020222d8(a,&next,0,0,2)){M2C_FIELD(a,u8 *,0x455)=9;return;}
result=(result&~255)|func_020227c8(a,(u8 *)a+0x480);
}
if(M2C_FIELD(a,s32 (**)(s32,void *,s32),0x810))result=M2C_FIELD(a,s32 (**)(s32,void *,s32),0x810)(result,a,i);
i++;
}while(low && result==0 && remaining && (low=1));
if(result==0)M2C_FIELD(a,u8 *,0x455)=3;else M2C_FIELD(a,u8 *,0x455)=9;
}

#pragma opt_propagation off
void func_02022d08(s32 p,u8 *s) {
s32 old,n;
MI_CpuCopy8(s+2,p+0x54,0x20);
old=M2C_FIELD(p,u8 *,0x30);n=s[0x22];s+=0x23;
if(old && n==0x20 && !func_0206527c(p+0x74,s,0x20))M2C_FIELD(p,u8 *,0x31)=1;
else {
if(old)func_02022008(p);
if(!n) M2C_FIELD(p,u8 *,0x30)=0;
else {MI_CpuCopy8(s,p+0x74,0x20);M2C_FIELD(p,u8 *,0x30)=1;}
M2C_FIELD(p,u8 *,0x31)=0;
}
M2C_FIELD(p,u16 *,0x32)=(s[n]<<8)+(s+n)[1];
M2C_FIELD(p,u8 *,0x455)=2;
}
#pragma opt_propagation reset
s32 func_02022dbc(u8 *p,s32 n,s32 stride,s32 target) {
s32 i,v;
for(i=0;i<n;i++,p+=stride) {
v=p[0]; v=(v<<8)+p[1];
if(stride==3)v=p[2]+(v<<8);
if(v==target)return 1;
}
return 0;
}

s32 func_02022e08(u8 *arg0,s32 arg1,s32 arg2) {
extern u16 data_020faffc[];
u32 i=0;
do {
if(func_02022dbc(arg0,arg1,arg2,data_020faffc[i]))return data_020faffc[i];
i++;
}while(i<2);
return 0;
}

s32 func_02022e68(s32 arg0, s32 arg1) {
    if (arg0 == 3) {
        return 1;
    }
    return 0;
}

#pragma opt_propagation off
void func_02022e78(u8 *p,u8 *q){
s32 MI_CpuCopy8(); void MI_CpuFill8();
s32 size,offset,n;u16 value;
if(!func_02022e68(q[0],q[1]))return;
size=(q[2]<<8)+q[3];
value=func_02022e08(q+8,size/3,3);
if(!value)return;
M2C_FIELD(p,u16*,0x32)=value;
offset=(q[4]<<8)+q[5];n=(q[6]<<8)+q[7];
p[0x30]=0;
offset=(size+8)+offset;
if(n>=32)MI_CpuCopy8(q+offset,p+0x34,32);
else {MI_CpuFill8(p+0x34,0,32-n);MI_CpuCopy8(q+offset,p+0x54-n,n);}
p[0x455]=1;
}
#pragma opt_propagation reset
void func_02022f40(void *arg0,u8 *arg1) {
s32 MI_CpuCopy8(); void func_02021de8(void *);
u32 n; u8 *p; u16 value;
if(func_02022e68(arg1[0],arg1[1])==0)return;
MI_CpuCopy8(arg1+2,(u8 *)arg0+0x34,32);
n=arg1[0x22];p=arg1+0x23;
if(n!=32)M2C_FIELD(arg0,u8 *,0x30)=0;
else {MI_CpuCopy8(p,(u8 *)arg0+0x74,32);func_02021de8(arg0);}
p+=n;
value=func_02022e08(p+2,((p[0]<<8)+p[1])/2,2);
M2C_FIELD(arg0,u16 *,0x32)=value;
if(value)M2C_FIELD(arg0,u8 *,0x455)=1;
}

/* Decrypt one RSA block (the TLS premaster secret) with the CRT private key: exponentiate the
 * input modulo each prime, combine the two results with the Chinese Remainder Theorem and write
 * the 48-byte plaintext to out. */
void RsaCrtDecrypt(s32 out, s32 in, void *arg2) {
    s32 BoostThreadPriority(void);
    void RestoreThreadPriority(s32);
    s32 BigNumSign(u16 *, s32);
    void BigNumAdd(u16 *, u16 *, u16 *, s32);
    void BigNumNeg(u16 *, s32);
    void BigNumSub(u16 *, u16 *, u16 *, s32);
    void BigNumMul(u16 *, u16 *, u16 *, s32);
    void BigNumDivMod(u16 *, u16 *, u16 *, u16 *, s32, u16 *);
    void BigNumModPow(void *, void *, void *, s32, void *);
    void BigNumFromBytes(void *, void *, void *, s32);
    void BigNumToBytes(void *, void *, s32, s32);
    extern u32 gAlloc[];
    extern u32 gFree[];

    s32 limbs;
    u16 *base, *exp, *q, *m1, *m2, *mod, *result, *work;
    RsaCrtKey *key;
    s32 savedPriority, n, twiceN;

    if (arg2 == 0) return;
    key = (RsaCrtKey *)arg2;
    if (key->modulus.length == 0) return;
    n = key->modulus.length;
    twiceN = n * 2;
    {
        u32 ut;
        s32 sum;
        ut = (u32)twiceN;
        sum = twiceN + (s32)(ut >> 31);
        limbs = (sum >> 1) + 1;
    }
    base = (u16 *)((void *(*)(u32))gAlloc[0])((u32)(limbs * 0x14));
    if (base == 0) return;
    exp = base + limbs;
    q = exp + limbs;
    m1 = q + limbs;
    m2 = m1 + limbs;
    mod = m2 + limbs;
    result = mod + limbs;
    work = result + limbs;
    BigNumFromBytes(base, (void *)in, (void *)(s32)key->modulus.length, limbs);
    BigNumFromBytes(exp, (void *)key->dP.bytes, (void *)key->dP.length, limbs);
    BigNumFromBytes(mod, (void *)key->p.bytes, (void *)key->p.length, limbs);
    savedPriority = BoostThreadPriority();
    BigNumModPow(m1, base, exp, limbs, mod);
    BigNumFromBytes(exp, (void *)key->dQ.bytes, (void *)key->dQ.length, limbs);
    BigNumFromBytes(mod, (void *)key->q.bytes, (void *)key->q.length, limbs);
    BigNumModPow(m2, base, exp, limbs, mod);
    RestoreThreadPriority(savedPriority);
    BigNumSub(base, m1, m2, limbs);
    BigNumFromBytes(exp, (void *)key->qInv.bytes, (void *)key->qInv.length, limbs);
    BigNumMul(q, base, exp, limbs);
    BigNumFromBytes(exp, (void *)key->q.bytes, (void *)key->q.length, limbs);
    BigNumMul(base, q, exp, limbs);
    BigNumAdd(q, base, m2, limbs);
    BigNumFromBytes(exp, (void *)key->modulus.bytes, (void *)key->modulus.length, limbs);
    if (BigNumSign(q, limbs) < 0) {
        BigNumNeg(q, limbs);
        BigNumDivMod((u16 *)0, q, exp, result, limbs, work);
        BigNumSub(result, exp, result, limbs);
    } else {
        BigNumDivMod((u16 *)0, q, exp, result, limbs, work);
    }
    BigNumToBytes((void *)out, result, 0x30, limbs);
    ((void (*)(void *))gFree[0])((void *)base);
}

void func_0202321c(s32 arg0,u8 *arg1,u8 *arg2) {
void MD5_Init(void *); void MD5_Update(void *,void *,s32); void MD5_Final(void *,s32);
void SHA1_Init(void *); void SHA1_Update(void *,void *,s32);void SHA1_Final(void *,void *);
s32 StringLength(void *);
u8 sp0[20];
SHA1_Init(arg2+0x348);
SHA1_Update(arg2+0x348,arg1,StringLength(arg1));
SHA1_Update(arg2+0x348,arg2,0x30);
SHA1_Update(arg2+0x348,arg2+0x34,0x40);
SHA1_Final(arg2+0x348,sp0);
MD5_Init(arg2+0x3fc);
MD5_Update(arg2+0x3fc,arg2,0x30);
MD5_Update(arg2+0x3fc,sp0,20);
MD5_Final(arg2+0x3fc,arg0);
}
#pragma opt_strength_reduction off
s32 func_020222d8(void *ctx,u8 **input,s32 depth,s32 index,s32 mode) {
s32 MI_CpuCopy8(); s32 func_0202219c(u8**); void func_020221ec(void*,u8*,s32);
u32 func_02022258(u8*); s32 func_0206527c(void*,void*,s32); s32 StringLength(void*);
extern char *data_020fb004[6];
u8 *start=*input; u8 *p=start+1; u8 tag=*start; s32 len=func_0202219c(&p); s32 i; u8 *end; u32 date; u32 sw;
if(len<0 || len>2000)return 1;
sw=tag&31;
switch(sw){
case 2:
if(M2C_FIELD(ctx,u8*,0x5ad)){
if(index==0){
while(*p==0){p++;len--;}
switch(mode){
case 0:if(len<=256){MI_CpuCopy8(p,(u8*)ctx+0x494,len);M2C_FIELD(ctx,s32*,0x594)=len;}break;
case 2:M2C_FIELD(ctx,s32*,0x484)=len;M2C_FIELD(ctx,u8**,0x488)=p;break;
}
}else if(index==1){
while(*p==0){p++;len--;}
switch(mode){
case 0:if(len<=8){MI_CpuCopy8(p,(u8*)ctx+0x598,len);M2C_FIELD(ctx,s32*,0x5a0)=len;}break;
case 2:M2C_FIELD(ctx,s32*,0x48c)=len;M2C_FIELD(ctx,u8**,0x490)=p;break;
}
}
}
p+=len;break;
case 3:
if(depth==1 && mode!=2){M2C_FIELD(ctx,u8**,0x5a4)=p+1;M2C_FIELD(ctx,s32*,0x5a8)=len-1;}
if(M2C_FIELD(ctx,u8*,0x5ad)){
p++;if(func_020222d8(ctx,&p,depth,0,mode))return 1;M2C_FIELD(ctx,u8*,0x5ad)=0;
}else p+=len;
break;
case 6: {
u8 *oid=p; char *name;
for(i=0;i<6;i++){
name=data_020fb004[i];
if(func_0206527c(oid,name,StringLength(name))==0){
switch(i){
case 1:case 2:if(mode==0)M2C_FIELD(ctx,s32*,0x45c)=i;M2C_FIELD(ctx,u8*,0x5ad)=i;break;
case 3:case 4:if(mode!=2)M2C_FIELD(ctx,s32*,0x458)=i;break;
case 5:if(mode!=2)M2C_FIELD(ctx,u8*,0x5ae)=i;break;
}
break;
}}
p+=len;break;
}
case 12:case 19:case 20:case 22:
if(mode!=2){
if(M2C_FIELD(ctx,u8*,0x5ac)){
func_020221ec((u8*)ctx+0x6b0,p,len);
if(M2C_FIELD(ctx,u8*,0x5ae)==5 && len<=79){MI_CpuCopy8(p,(u8*)ctx+0x7b0,len);M2C_FIELD((u8*)ctx+len,u8*,0x7b0)=0;}
}else func_020221ec((u8*)ctx+0x5b0,p,len);
}
M2C_FIELD(ctx,u8*,0x5ae)=0;p+=len;break;
case 23:case 24:
if(mode!=2){
date=func_02022258(p);
if(index==0){if(M2C_FIELD(ctx,u32*,0x80c)>=date)M2C_FIELD(ctx,u8*,0x5af)=1;}
else if(M2C_FIELD(ctx,u32*,0x80c)>date)M2C_FIELD(ctx,u8*,0x5af)=0;
}
p+=len;M2C_FIELD(ctx,u8*,0x5ac)=1;break;
case 16:
if(depth==0 && index==0 && mode!=2)M2C_FIELD(ctx,u8**,0x460)=p;
end=p+len;i=0;
while(p<end){s32 result=func_020222d8(ctx,&p,depth+1,i,mode);i++;if(result)return 1;}
if(depth==1 && index==0 && mode!=2)M2C_FIELD(ctx,u8**,0x464)=p;
break;
case 17:
end=p+len;
while(p<end)if(func_020222d8(ctx,&p,depth+1,0,mode))return 1;
break;
default:
if(tag==160){end=p+len;while(p<end)if(func_020222d8(ctx,&p,depth+1,0,mode))return 1;}
else p+=len;
break;
}
*input=p;return 0;
}
#pragma opt_strength_reduction reset
s32 func_020227c8(void *arg0, void *arg1) {
    extern u32 gAlloc[];
    extern u32 gFree[];
    void BigNumFromBytes(void *, void *, void *, s32);
    s32 BoostThreadPriority(void);
    void func_020269dc(void *, void *, s32, s32, void *);
    void RestoreThreadPriority(s32);
    void BigNumToBytes(void *, void *, s32, s32);
    s32 func_0206527c(void *, void *, s32);
    u8 *base;
    s32 cnt;
    u8 *r6;
    u8 *r9;
    u8 *r10;
    s32 t;
    s32 r3count;
    s32 r2;
    s32 length;
    if (!*(u32 *)((u8 *)arg0 + 0x5a4) || !*(u32 *)((u8 *)arg0 + 0x5a8) ||
        !*(u32 *)((u8 *)arg1 + 0x10) || !*(u32 *)((u8 *)arg1 + 0xc) ||
        !*(u32 *)((u8 *)arg1 + 0x8) || !(length=*(s32 *)((u8 *)arg1 + 0x4))) {
        return 2;
    }
    cnt = (length * 2) / 2;
    {
        void *(*alloc)(u32) = (void *(*)(u32))gAlloc[0];
        base = (u8 *)alloc((u32)(cnt * 8));
    }
    if (base == 0) {
        return 2;
    }
    r6 = base + cnt * 2;
    r9 = r6 + cnt * 2;
    r10 = r9 + cnt * 2;
    BigNumFromBytes(r6, *(void **)((u8 *)arg0 + 0x5a4), *(void **)((u8 *)arg0 + 0x5a8), cnt);
    BigNumFromBytes(r9, *(void **)((u8 *)arg1 + 0x10), *(void **)((u8 *)arg1 + 0xc), cnt);
    BigNumFromBytes(r10, *(void **)((u8 *)arg1 + 0x8), *(void **)((u8 *)arg1 + 0x4), cnt);
    t = BoostThreadPriority();
    func_020269dc(base, r6, (s32)r9, cnt, r10);
    RestoreThreadPriority(t);
    BigNumToBytes(r6, base, *(s32 *)((u8 *)arg1 + 0x4), cnt);
    t = base[cnt * 2];
    cnt = 0;
    if (t != 0 || r6[1] != 1) {
        cnt = 2;
        goto done;
    }
    r3count = *(s32 *)((u8 *)arg1 + 4);
    r2 = 2;
    while (r2 < r3count) {
        if (r6[r2] != 0xff) break;
        r2++;
    }
    if (r2 + 1 >= r3count) goto bad;
    if (r6[r2] != 0 || r6[r2 + 1] != 0x30) goto bad;
    {
        s32 field = *(s32 *)((u8 *)arg0 + 0x47c);
        if (!func_0206527c((u8 *)arg0 + 0x468, r6 + r3count - field, field)) goto done;
    }
bad:
    cnt = 2;
done:
    {
        void (*freefn)(void *) = (void (*)(void *))gFree[0];
        freefn(base);
    }
    return cnt;
}
