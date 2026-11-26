/* 15 functions from 0x020222D8 to 0x020232B8 (main), found by ds-decomp. */
#include "common.h"
static inline u32 CertificateTag(u8 tag) { return tag & 31; }
typedef struct CertificateTagBits { u8 number:5; u8 constructed:1; u8 category:2; } CertificateTagBits;

/* Verifies the signature carried in the current certificate: hash the handshake
 * messages it covers with the certificate's digest algorithm (MD5 or SHA1),
 * look the issuer's key up by name and check the signature with it.  Returns 0
 * when the chain checks out, otherwise the TLS_CERT_CHECK_* error bits. */
s32 TlsVerifyCertificateSignature(void *ctx) {
    void MD5_Init(void *);
    void MD5_Update(void *, void *, s32);
    void MD5_Final(void *, s32);
    void SHA1_Init(void *);
    void SHA1_Update(void *, void *, s32);
    void SHA1_Final(void *, void *);
    s32 FindNamedRsaKey(void *, void *);
    s32 VerifyRsaSignature(void *, void *);
    s32 errors;
    s32 t0, t1;
    register s32 key asm("r1");
    if (*(u8 *)((u8 *)ctx + TLS_CERT_DATE_VALID) != 0) {
        errors = 0;
    } else {
        errors = TLS_CERT_CHECK_DATE;
    }
    if (*(s32 *)((u8 *)ctx + TLS_CERT_KEY_ALGORITHM) == -1) {
        return errors | TLS_CERT_CHECK_NO_KEY;
    }
    switch (*(s32 *)((u8 *)ctx + TLS_CERT_SIGNATURE_ALGORITHM)) {
    case 3:
        MD5_Init((u8 *)ctx + TLS_MD5_CTX);
        t0 = *(s32 *)((u8 *)ctx + TLS_SIGNED_MESSAGE_START);
        MD5_Update((u8 *)ctx + TLS_MD5_CTX, (void *)t0, *(s32 *)((u8 *)ctx + TLS_SIGNED_MESSAGE_END) - t0);
        MD5_Final((u8 *)ctx + TLS_MD5_CTX, (s32)((u8 *)ctx + TLS_DIGEST));
        *(s32 *)((u8 *)ctx + TLS_DIGEST_LEN) = 0x10;
        break;
    case 4:
        SHA1_Init((u8 *)ctx + TLS_SHA1_CTX);
        t1 = *(s32 *)((u8 *)ctx + TLS_SIGNED_MESSAGE_START);
        SHA1_Update((u8 *)ctx + TLS_SHA1_CTX, (void *)t1, *(s32 *)((u8 *)ctx + TLS_SIGNED_MESSAGE_END) - t1);
        SHA1_Final((u8 *)ctx + TLS_SHA1_CTX, (u8 *)ctx + TLS_DIGEST);
        *(s32 *)((u8 *)ctx + TLS_DIGEST_LEN) = 0x14;
        break;
    default:
        return errors | TLS_CERT_CHECK_UNSUPPORTED;
    }
    key = FindNamedRsaKey(ctx, (u8 *)ctx + TLS_ISSUER_NAME);
    if (key == 0) {
        return errors | TLS_CERT_CHECK_NO_SIGNATURE;
    }
    return errors | VerifyRsaSignature(ctx, (void *)key);
}

/* Length of the name label starting at `p`: the bytes up to the next '.' or the
 * end of the string. */
s32 TlsLabelLength(s8 *p) {
    s8 *start = p;
    s32 c;
    while ((c = *p) != '.' && c != 0) p++;
    return p - start;
}

#pragma optimization_level 4
s32 TlsMatchWildcardName(s8 *p,s8 *q) {
s32 a,b,c,d;
again:
while((d=*p++)==(c=*q++)) { if(d==0)return 0; }
if(c!=0x2a)return 1;
p--;a=TlsLabelLength(p);b=TlsLabelLength(q);
if(b>a)return 1;
p+=a-b;
goto again;
}
#pragma optimization_level reset
void TlsProcessCertificate(void *a, u8 *b) {
s32 func_020222d8(void *,u8 **,s32,s32,s32);
void GetRtcDate(s32 *);
s32 VerifyRsaSignature(void *,void *);
s32 date[4]; u8 low; s32 result; u32 remaining; s32 i; u8 *next; u32 n;
n=b[0]; remaining=b[1]; remaining=b[2]+(((n<<8)+remaining)<<8);b+=3;
M2C_FIELD(a,s32 *,0x45c)=-1;
GetRtcDate(date);
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
result=TlsVerifyCertificateSignature(a);
if(i==0 && M2C_FIELD(a,s8 **,0x800)!=0 && TlsMatchWildcardName(M2C_FIELD(a,s8 **,0x800),(s8 *)a+0x7b0))result|=0x4000;
low=(u8)result;
if(low==1 && remaining){
next=b+3;M2C_FIELD(a,u8 *,0x5ad)=0;
if(func_020222d8(a,&next,0,0,2)){M2C_FIELD(a,u8 *,0x455)=9;return;}
result=(result&~255)|VerifyRsaSignature(a,(u8 *)a+0x480);
}
if(M2C_FIELD(a,s32 (**)(s32,void *,s32),0x810))result=M2C_FIELD(a,s32 (**)(s32,void *,s32),0x810)(result,a,i);
i++;
}while(low && result==0 && remaining && (low=1));
if(result==0)M2C_FIELD(a,u8 *,0x455)=3;else M2C_FIELD(a,u8 *,0x455)=9;
}

#pragma opt_propagation off
/* Handle a ServerHello body: keep the server's random, resume the cached session when the
 * server echoed its id (otherwise cache the new id, dropping the old entry), and take the
 * server's hash algorithm from the cipher suite that follows the session id. */
void TlsProcessServerHello(s32 channel, u8 *body) {
    void TlsSessionCacheDiscard(s32);
    s32 hadCachedSession, sessionIdLen;

    MI_CpuCopy8(body + 2, channel + TLS_RANDOM_B, 0x20);
    hadCachedSession = M2C_FIELD(channel, u8 *, TLS_SESSION_CACHED);
    sessionIdLen = body[0x22];
    body += 0x23;
    if (hadCachedSession && sessionIdLen == 0x20 && !ByteCompareN(channel + TLS_SESSION_ID, body, 0x20)) M2C_FIELD(channel, u8 *, TLS_SESSION_RESUMED) = 1;
    else {
        if (hadCachedSession) TlsSessionCacheDiscard(channel);
        if (!sessionIdLen) M2C_FIELD(channel, u8 *, TLS_SESSION_CACHED) = 0;
        else {MI_CpuCopy8(body, channel + TLS_SESSION_ID, 0x20);M2C_FIELD(channel, u8 *, TLS_SESSION_CACHED) = 1;}
        M2C_FIELD(channel, u8 *, TLS_SESSION_RESUMED) = 0;
    }
    M2C_FIELD(channel, u16 *, TLS_HASH_ALGORITHM) = (body[sessionIdLen] << 8) + (body + sessionIdLen)[1];
    M2C_FIELD(channel, u8 *, TLS_STATE) = 2;
}
#pragma opt_propagation reset
/* Returns 1 when the cipher suite list the peer offered (`count` entries of
 * `entrySize` bytes holding big-endian suite ids) contains `suite`; SSLv2 lists
 * use 3-byte entries, later versions 2. */
s32 TlsListContainsSuite(u8 *list, s32 count, s32 entrySize, s32 suite) {
    s32 i, value;
    for (i = 0; i < count; i++, list += entrySize) {
        value = list[0];
        value = (value << 8) + list[1];
        if (entrySize == 3) value = list[2] + (value << 8);
        if (value == suite) return 1;
    }
    return 0;
}

/* Picks the first cipher suite this build prefers (gTlsCipherSuites) that the
 * peer's offered list, `count` entries of `stride` bytes each, also contains;
 * returns the chosen suite (which the handshake then records as its hash
 * algorithm) or 0 when none of the preferred suites is offered. */
s32 TlsPickCipherSuite(u8 *list,s32 count,s32 stride) {
extern u16 gTlsCipherSuites[];
u32 i=0;
do {
if(TlsListContainsSuite(list,count,stride,gTlsCipherSuites[i]))return gTlsCipherSuites[i];
i++;
}while(i<2);
return 0;
}

s32 TlsIsSsl3Version(s32 arg0, s32 arg1) {
    if (arg0 == 3) {
        return 1;
    }
    return 0;
}

#pragma opt_propagation off
void TlsProcessClientHelloSslV2(u8 *p,u8 *q){
s32 MI_CpuCopy8(); void MI_CpuFill8();
s32 size,offset,n;u16 value;
if(!TlsIsSsl3Version(q[0],q[1]))return;
size=(q[2]<<8)+q[3];
value=TlsPickCipherSuite(q+8,size/3,3);
if(!value)return;
M2C_FIELD(p,u16*,0x32)=value;
offset=(q[4]<<8)+q[5];n=(q[6]<<8)+q[7];
p[0x30]=0;
offset=(size+8)-(-offset);
if(n>=32)MI_CpuCopy8(q+offset,p+0x34,32);
else {MI_CpuFill8(p+0x34,0,32-n);MI_CpuCopy8(q+offset,p+0x54-n,n);}
p[0x455]=1;
}
#pragma opt_propagation reset
/* Handle a ClientHello body: accept only an SSL 3.x record version, keep the
 * client's random, take its session id (restoring the matching cached session
 * when the id is the full 32 bytes, otherwise clearing the cache marker), then
 * pick one of the cipher suites the body offers and record it as the handshake's
 * hash algorithm; a picked suite moves the handshake to the ClientHello state. */
void TlsProcessClientHello(void *channel,u8 *body) {
s32 MI_CpuCopy8(); void TlsRestoreSessionById(void *);
u32 sessionIdLen; u8 *cursor; u16 cipherSuite;
if(TlsIsSsl3Version(body[0],body[1])==0)return;
MI_CpuCopy8(body+2,(u8 *)channel+TLS_RANDOM_A,TLS_RANDOM_SIZE);
sessionIdLen=body[0x22];cursor=body+0x23;
if(sessionIdLen!=TLS_RANDOM_SIZE)M2C_FIELD(channel,u8 *,TLS_SESSION_CACHED)=0;
else {MI_CpuCopy8(cursor,(u8 *)channel+TLS_SESSION_ID,TLS_RANDOM_SIZE);TlsRestoreSessionById(channel);}
cursor+=sessionIdLen;
cipherSuite=TlsPickCipherSuite(cursor+2,((cursor[0]<<8)+cursor[1])/2,2);
M2C_FIELD(channel,u16 *,TLS_HASH_ALGORITHM)=cipherSuite;
if(cipherSuite)M2C_FIELD(channel,u8 *,TLS_STATE)=TLS_STATE_CLIENT_HELLO;
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

/* One 16-byte chunk of the SSLv3 master-secret PRF: hash the chunk label, the
 * master secret and both handshake randoms with SHA1, then hash the master
 * secret and that digest with MD5 into `out`. */
void TlsComputeMasterSecretChunk(s32 out,u8 *label,u8 *session) {
void MD5_Init(void *); void MD5_Update(void *,void *,s32); void MD5_Final(void *,s32);
void SHA1_Init(void *); void SHA1_Update(void *,void *,s32);void SHA1_Final(void *,void *);
s32 StringLength(void *);
u8 sha1[20];
SHA1_Init(session+TLS_SHA1_CTX);
SHA1_Update(session+TLS_SHA1_CTX,label,StringLength(label));
SHA1_Update(session+TLS_SHA1_CTX,session,TLS_MASTER_SECRET_SIZE);
SHA1_Update(session+TLS_SHA1_CTX,session+TLS_RANDOM_A,TLS_RANDOM_SIZE*2);
SHA1_Final(session+TLS_SHA1_CTX,sha1);
MD5_Init(session+TLS_MD5_CTX);
MD5_Update(session+TLS_MD5_CTX,session,TLS_MASTER_SECRET_SIZE);
MD5_Update(session+TLS_MD5_CTX,sha1,20);
MD5_Final(session+TLS_MD5_CTX,out);
}
#pragma scheduling off
s32 func_020222d8(void *ctx,u8 **input,s32 depth,s32 index,s32 mode) {
s32 MI_CpuCopy8(); s32 ParseAsn1Length(u8**); void AppendCommaSeparatedName(void*,u8*,s32);
u32 ParseAsn1Time(u8*); s32 ByteCompareN(void*,void*,s32); s32 StringLength(void*);
extern char *data_020fb004[6];
u8 *start=*input; u8 *p=start+1; u8 tag=*start; s32 len=ParseAsn1Length(&p); s32 i; u8 *end; u32 date; u32 sw;
if (!(len >= 0 && len <= 2000)) return 1;
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
if(ByteCompareN(oid,name,StringLength(name))==0){
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
AppendCommaSeparatedName((u8*)ctx+0x6b0,p,len);
if(M2C_FIELD(ctx,u8*,0x5ae)==5 && len<=79){MI_CpuCopy8(p,(u8*)ctx+0x7b0,len);M2C_FIELD((u8*)ctx+len,u8*,0x7b0)=0;}
}else AppendCommaSeparatedName((u8*)ctx+0x5b0,p,len);
}
M2C_FIELD(ctx,u8*,0x5ae)=0;p+=len;break;
case 23:case 24:
if(mode!=2){
date=ParseAsn1Time(p);
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
/* Verify the RSA signature carried in the current TLS handshake message: exponentiate it with
 * the named public key, then check the recovered PKCS#1 v1.5 block (00 01 ff..ff 00 30 ...)
 * ends in the handshake digest. Returns 0 when it verifies, 2 when the key or signature is
 * missing or does not check out. */
s32 VerifyRsaSignature(void *arg0, void *arg1) {
    extern u32 gAlloc[];
    extern u32 gFree[];
    void BigNumFromBytes(void *, void *, void *, s32);
    s32 BoostThreadPriority(void);
    void func_020269dc(void *, void *, s32, s32, void *);
    void RestoreThreadPriority(s32);
    void BigNumToBytes(void *, void *, s32, s32);
    s32 ByteCompareN(void *, void *, s32);
    NamedRsaKey *key;
    u8 *work;
    s32 limbs;
    u8 *sig;
    u8 *exp;
    u8 *mod;
    s32 savedPriority;
    s32 keyLen;
    s32 i;
    s32 length;
    key = (NamedRsaKey *)arg1;
    if (!*(u32 *)((u8 *)arg0 + TLS_SIGNATURE) || !*(u32 *)((u8 *)arg0 + TLS_SIGNATURE_LEN) ||
        !key->exponent || !key->exponentLength ||
        !key->modulus || !(length = key->modulusLength)) {
        return 2;
    }
    limbs = (length * 2) / 2;
    {
        void *(*alloc)(u32) = (void *(*)(u32))gAlloc[0];
        work = (u8 *)alloc((u32)(limbs * 8));
    }
    if (work == 0) {
        return 2;
    }
    sig = work + limbs * 2;
    exp = sig + limbs * 2;
    mod = exp + limbs * 2;
    BigNumFromBytes(sig, *(void **)((u8 *)arg0 + TLS_SIGNATURE), *(void **)((u8 *)arg0 + TLS_SIGNATURE_LEN), limbs);
    BigNumFromBytes(exp, key->exponent, (void *)key->exponentLength, limbs);
    BigNumFromBytes(mod, key->modulus, (void *)key->modulusLength, limbs);
    savedPriority = BoostThreadPriority();
    func_020269dc(work, sig, (s32)exp, limbs, mod);
    RestoreThreadPriority(savedPriority);
    BigNumToBytes(sig, work, key->modulusLength, limbs);
    savedPriority = work[limbs * 2];
    limbs = 0;
    if (savedPriority != 0 || sig[1] != 1) {
        limbs = 2;
        goto done;
    }
    keyLen = key->modulusLength;
    i = 2;
    while (i < keyLen) {
        if (sig[i] != 0xff) break;
        i++;
    }
    if (i + 1 >= keyLen) goto bad;
    if (sig[i] != 0 || sig[i + 1] != 0x30) goto bad;
    {
        s32 digestLen = *(s32 *)((u8 *)arg0 + TLS_DIGEST_LEN);
        if (!ByteCompareN((u8 *)arg0 + TLS_DIGEST, sig + keyLen - digestLen, digestLen)) goto done;
    }
bad:
    limbs = 2;
done:
    {
        void (*freefn)(void *) = (void (*)(void *))gFree[0];
        freefn(work);
    }
    return limbs;
}
