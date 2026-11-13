/* 18 functions from 0x0200CD68 to 0x0200DD40 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u16 x,y; } TouchPair;
typedef struct { u8 pad[0x58]; u16 a,b; u8 e,f; u16 c,d; u8 g,h; } TouchInput;
typedef struct { u32 unk0; void (*callback)(s32,s32,s32); u16 sample[4]; u16 index; u16 pad12; void *records; u16 capacity; u8 pad1a[0x1c]; u16 state; u16 flags38, flags3a; } TouchState;
extern HashDescriptor gSha1HashDescriptor;
extern M2C_UNK data_0212fc70;
void Sha1Init(void *);
void Sha1Update(void *, const void *, s32);
void SHA1_Finalize(void *, void *);
void func_0200d2c4(u32,u32,u32);
typedef struct { u32 x:12; u32 y:12; u32 touch:1; u32 valid:2; u32 unused:5; } TouchPacket;
typedef union { TouchPair pair; TouchPacket bits; } TouchSample;
typedef struct { u16 x,y,touch,valid; } TouchResult;

void HmacSha1(u32 a,u32 b,u32 c,u32 d,u32 e) {
void Hmac(u8 *,u8 *,s32,u8 *,s32,HashDescriptor *);
u8 ctx[0x68]; u8 innerDigest[0x14]; HashDescriptor cfg = gSha1HashDescriptor;
cfg.context=ctx; cfg.digest=innerDigest;
cfg.init=Sha1Init; cfg.update=Sha1Update; cfg.final=SHA1_Finalize;
Hmac(a,b,c,d,e,&cfg);
}

#pragma scheduling off
/* Keyed-hash message authentication (HMAC): when the key is longer than one
 * block it is hashed first, then the inner (0x36) and outer (0x5c) padded keys
 * are built and fed through the descriptor's hash callbacks with the message
 * and the inner digest. */
void Hmac(u8 *digest, u8 *msg, s32 msgLen, u8 *key, s32 keyLen, HashDescriptor *hash) {
    u8 keyHash[64];
    u8 innerPad[64];
    u8 outerPad[64];
    s32 i;
    s32 k;
    u8 *p;
    u8 *p2;
    u8 *q;
    u8 *src;
    s32 j;
    u8 b;
    u8 c;

    k = keyLen;
    src = key;
    if ((digest != NULL) && (msg != NULL) && (msgLen != 0) && (src != NULL) && (k != 0) && (hash != NULL)) {
        if (k > (s32)hash->blockSize) {
            hash->init(hash->context);
            hash->update(hash->context, src, k);
            hash->final(hash->context, keyHash);
            k = hash->digestSize;
            src = keyHash;
        }
        i = 0;
        if (k > 0) {
            p = innerPad;
            do {
                b = src[i];
                i += 1;
                *p = b ^ 0x36;
                p += 1;
            } while (i < k);
        }
        if (i < (s32)hash->blockSize) {
            p = &innerPad[i];
            do {
                *p = 0x36;
                p += 1;
                i += 1;
            } while (i < (s32)hash->blockSize);
        }
        hash->init(hash->context);
        hash->update(hash->context, innerPad, hash->blockSize);
        hash->update(hash->context, msg, msgLen);
        hash->final(hash->context, hash->digest);
        j = 0;
        if (k > 0) {
            p2 = outerPad;
            do {
                c = src[j];
                j += 1;
                *p2 = c ^ 0x5C;
                p2 += 1;
            } while (j < k);
        }
        if (j < (s32)hash->blockSize) {
            q = &outerPad[j];
            do {
                *q = 0x5C;
                q += 1;
                j += 1;
            } while (j < (s32)hash->blockSize);
        }
        hash->init(hash->context);
        hash->update(hash->context, outerPad, hash->blockSize);
        hash->update(hash->context, hash->digest, hash->digestSize);
        hash->final(hash->context, digest);
    }
}
#pragma scheduling reset
void func_0200cfc8(u32 *state,const u8 *data,s32 len){
 u32 a,b,c,d,e,W[32],*p,t,x;
 s32 i;
 a=state[0];b=state[1];c=state[2];d=state[3];e=state[4];
 do{
 p=W;
 for(i=0;i<64;i+=4){
 x=*(const u32 *)data;data+=4;
 x=((x&0xff00ff)>>8)|((x&0xff00ff)<<24)|(((x<<8)|(x>>24))&0xff00ff);
 p[16]=x;*p++=x;
 t=0x5a827999+e+((a<<5)|(a>>27))+x+(((c^d)&b)^d);
 e=d;d=c;c=(b>>2)|(b<<30);b=a;a=t;
 }
 p=W;
 for(i=0;i<4;i++){
 x=(p[0]^p[2])^(p[8]^p[13]);x=(x<<1)|(x>>31);
 p[16]=x;*p++=x;
 t=x+e+0x5a827999+((a<<5)|(a>>27))+(((c^d)&b)^d);
 e=d;d=c;c=(b>>2)|(b<<30);b=a;a=t;
 }
 for(i=0;i<20;i++){
 x=(p[0]^p[2])^(p[8]^p[13]);x=(x<<1)|(x>>31);
 p[16]=x;*p++=x;
 t=x+e+0x6ed9eba1+((a<<5)|(a>>27))+(b^c^d);
 e=d;d=c;c=(b>>2)|(b<<30);b=a;a=t;
 if(i==11)p=W;
 }
 for(i=0;i<20;i++){
 x=(p[0]^p[2])^(p[8]^p[13]);x=(x<<1)|(x>>31);
 p[16]=x;*p++=x;
 t=x+e+0x8f1bbcdc+((a<<5)|(a>>27))+(((b|c)&d)|(b&c));
 e=d;d=c;c=(b>>2)|(b<<30);b=a;a=t;
 if(i==7)p=W;
 }
 for(i=0;i<20;i++){
 x=(p[0]^p[2])^(p[8]^p[13]);x=(x<<1)|(x>>31);
 p[16]=x;*p++=x;
 t=x+e+0xca62c1d6+((a<<5)|(a>>27))+(b^c^d);
 e=d;d=c;c=(b>>2)|(b<<30);b=a;a=t;
 if(i==3)p=W;
 }
 state[0]+=a;state[1]+=b;state[2]+=c;state[3]+=d;state[4]+=e;
 len-=64;
 }while(len>0);
}

#pragma push
#pragma opt_global_reg off
void func_0200d2c4(u32 unused,u32 value,u32 error){
u16 code=(u16)value;u16 command=(u16)((code&0x7f00)>>8);s32 status;
TouchSample sample1,sample2;TouchResult *out; u8 touch,valid;u16 y,x;
if(error){
value=(u32)&data_0212fc70;
error=1<<command;
((TouchState *)(void *)value)->flags38|=error;
if(((TouchState *)(void *)value)->callback)((TouchState *)(void *)value)->callback(command,4,0);return;
}
if(command==16){
value=(u32)&data_0212fc70;
M2C_FIELD((void *)value,u16 *,0x10)++;
if(M2C_FIELD((void *)value,u16 *,0x10)>=M2C_FIELD((void *)value,u16 *,0x18))M2C_FIELD((void *)value,u16 *,0x10)=0;
sample1.pair=*(volatile TouchPair *)0x27fffaa;
x=sample1.bits.x;y=sample1.bits.y;touch=sample1.bits.touch;valid=sample1.bits.valid;
out=M2C_FIELD((void *)value,TouchResult **,0x14)+M2C_FIELD(&data_0212fc70,u16 *,0x10);
out->x=x;out->y=y;out->touch=touch;out->valid=valid;
if(((TouchState *)(void *)value)->callback)((TouchState *)(void *)value)->callback(command,0,(u8)M2C_FIELD((void *)value,u16 *,0x10));return;
}
if(!(value&0x1000000))return;
switch((u8)code){
case 0:
switch(command){case 0:
sample2.pair=*(volatile TouchPair *)0x27fffaa;x=sample2.bits.x;y=sample2.bits.y;touch=sample2.bits.touch;valid=sample2.bits.valid;
M2C_FIELD(&data_0212fc70,u16 *,8)=x;
M2C_FIELD(&data_0212fc70,u16 *,10)=y;
M2C_FIELD(&data_0212fc70,u16 *,12)=touch;
M2C_FIELD(&data_0212fc70,u16 *,14)=valid;
M2C_FIELD(&data_0212fc70,u16 *,0x36)=0;
break;
case 1:M2C_FIELD(&data_0212fc70,u16 *,0x36)=2;break;
case 2:M2C_FIELD(&data_0212fc70,u16 *,0x36)=0;break;
}
((TouchState *)&data_0212fc70)->flags3a&=~(1<<command);
if(((TouchState *)&data_0212fc70)->callback)((TouchState *)&data_0212fc70)->callback(command,0,0);return;
case 4:status=3;goto report;
case 2:status=1;goto report;
case 3:status=2;
report:
((TouchState *)&data_0212fc70)->flags38|=1<<command;
((TouchState *)&data_0212fc70)->flags3a&=~(1<<command);
if(((TouchState *)&data_0212fc70)->callback)((TouchState *)&data_0212fc70)->callback(command,(u8)status,0);
return;
default:SystemHalt();return;
}
}
#pragma pop
void func_0200d544(void) {
void func_02009d34(void); s32 func_02009e8c(s32,s32); void func_02009e40(s32,void *);
if(M2C_FIELD(&data_0212fc70,u16 *,0)) return;
M2C_FIELD(&data_0212fc70,u16 *,0)=1;
func_02009d34();
M2C_FIELD(&data_0212fc70,u16 *,0x10)=0;
M2C_FIELD(&data_0212fc70,u32 *,4)=0;
M2C_FIELD(&data_0212fc70,u32 *,0x14)=0;
M2C_FIELD(&data_0212fc70,u16 *,0x36)=0;
M2C_FIELD(&data_0212fc70,u16 *,0x34)=0;
M2C_FIELD(&data_0212fc70,u16 *,0x3a)=0;
M2C_FIELD(&data_0212fc70,u16 *,0x38)=0;
while(!func_02009e8c(6,1)) {}
func_02009e40(6,&func_0200d2c4);
}

#pragma opt_propagation off
s32 func_0200d5bc(u16 *p) {
    s32 func_0200da04(void *,u16,u16,u16,u16,u16,u16,u16,u16);
    volatile void *base = (volatile void *)0x027ffc80;
    u16 a = M2C_FIELD(base, u16 *, 0x58);
    u16 b = M2C_FIELD(base, u16 *, 0x5a);
    u16 c = M2C_FIELD(base, u16 *, 0x5e);
    u16 d = M2C_FIELD(base, u16 *, 0x60);
    u8 e = M2C_FIELD(base, u8 *, 0x5c);
    u8 f = M2C_FIELD(base, u8 *, 0x5d);
    u8 g = M2C_FIELD(base, u8 *, 0x62);
    u8 h = M2C_FIELD(base, u8 *, 0x63);
    if ((!a && !c && !b && !d) || func_0200da04(p, a, b, e, f, c, d, g, h)) {
        p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0; return 1;
    }
    return 1;
}
#pragma opt_propagation reset
void func_0200d650(s16 *p){
s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);
s32 t,n;
if(!p){M2C_FIELD(&data_0212fc70,u16*,0x34)=0;return;}
t=OS_DisableInterrupts();
if((n=p[2])!=0){
*(volatile u16*)0x4000280=0;
*(volatile u32*)0x4000290=0x10000000;
*(volatile s64*)0x4000298=(u32)n;
M2C_FIELD(&data_0212fc70,s32*,28)=p[0];
M2C_FIELD(&data_0212fc70,s32*,32)=p[2];
while(*(volatile u16*)0x4000280&0x8000){}
M2C_FIELD(&data_0212fc70,s32*,36)=*(volatile s32*)0x40002a0;
}else{M2C_FIELD(&data_0212fc70,s32*,28)=0;M2C_FIELD(&data_0212fc70,s32*,32)=0;M2C_FIELD(&data_0212fc70,s32*,36)=0;}
if((n=p[3])!=0){
*(volatile u16*)0x4000280=0;
*(volatile u32*)0x4000290=0x10000000;
*(volatile s64*)0x4000298=(u32)n;
M2C_FIELD(&data_0212fc70,s32*,40)=p[1];
M2C_FIELD(&data_0212fc70,s32*,44)=p[3];
while(*(volatile u16*)0x4000280&0x8000){}
M2C_FIELD(&data_0212fc70,s32*,48)=*(volatile s32*)0x40002a0;
}else{M2C_FIELD(&data_0212fc70,s32*,40)=0;M2C_FIELD(&data_0212fc70,s32*,44)=0;M2C_FIELD(&data_0212fc70,s32*,48)=0;}
OS_RestoreInterrupts(t);M2C_FIELD(&data_0212fc70,u16*,0x34)=1;}

#pragma opt_propagation off
void func_0200d778(void) {
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); s32 func_02009eb0(s32,u32,s32);
s32 t=OS_DisableInterrupts(); s32 ok=(func_02009eb0(6,0x3000000,0)>=0); u32 base;
if(!ok) {OS_RestoreInterrupts(t);base=(u32)&data_0212fc70;
((TouchState *)base)->flags38 = 1 | ((TouchState *)base)->flags38;
if(((TouchState *)base)->callback)((TouchState *)base)->callback(0,4,0);
} else {base=(u32)&data_0212fc70;((TouchState *)base)->flags3a = 1 | ((TouchState *)base)->flags3a;((TouchState *)base)->flags38&=~1;OS_RestoreInterrupts(t);}
}
#pragma opt_propagation reset
s32 func_0200d80c(u16 *a) {
void func_0200dd14(u32);
func_0200dd14(1);if(M2C_FIELD(&data_0212fc70,u16 *,0x38)&1)return 1;
((TouchPair *)a)[0]=M2C_FIELD(&data_0212fc70,TouchPair *,8);
((TouchPair *)a)[1]=M2C_FIELD(&data_0212fc70,TouchPair *,12);return 0;
}

#pragma opt_instruction_scheduling off
void func_0200d85c(s32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 func_02009eb0(s32, u32, s32);
    u32 i;
    s32 t;
    u8 ok;

    M2C_FIELD(&data_0212fc70, s32 *, 0x14) = arg2;
    M2C_FIELD(&data_0212fc70, u16 *, 0x10) = 0;
    M2C_FIELD(&data_0212fc70, u16 *, 0x12) = arg1;
    M2C_FIELD(&data_0212fc70, u16 *, 0x18) = arg3;
    i = 0;
    while (i < arg3) {
        u32 v = i;
        i++;
        ((u16 *)M2C_FIELD(&data_0212fc70, s32 *, 0x14))[v * 4 + 2] = (u16)v;
    }
    t = OS_DisableInterrupts();
    if (func_02009eb0(6, (arg1 & 0xff) | 0x100 | 0x2000000, 0) < 0) {
        goto fail;
    }
    ok = (func_02009eb0(6, arg0 | 0x10000 | 0x1000000, 0) >= 0);
    if (ok) {
        goto okpath;
    }
fail:
    OS_RestoreInterrupts(t);
    M2C_FIELD(&data_0212fc70, u16 *, 0x38) |= 2;
    if (M2C_FIELD(&data_0212fc70, void (**)(s32, s32, s32), 4)) {
        M2C_FIELD(&data_0212fc70, void (**)(s32, s32, s32), 4)(1, 4, 0);
    }
    return;
okpath:
    M2C_FIELD(&data_0212fc70, u16 *, 0x3a) |= 2;
    M2C_FIELD(&data_0212fc70, u16 *, 0x38) &= ~2;
    OS_RestoreInterrupts(t);
    return;
}
#pragma opt_instruction_scheduling reset
void func_0200d95c(void) {
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); s32 func_02009eb0(s32,u32,s32);
s32 t=OS_DisableInterrupts();s32 ok=(func_02009eb0(6,0x3000200,0)>=0);
if(ok==0) {OS_RestoreInterrupts(t);M2C_FIELD(&data_0212fc70,u16 *,0x38)=4|M2C_FIELD(&data_0212fc70,u16 *,0x38);
if(M2C_FIELD(&data_0212fc70,void (**)(s32,s32,s32),4))M2C_FIELD(&data_0212fc70,void (**)(s32,s32,s32),4)(2,4,0);
} else { M2C_FIELD(&data_0212fc70,u16 *,0x3a)=4|M2C_FIELD(&data_0212fc70,u16 *,0x3a);M2C_FIELD(&data_0212fc70,u16 *,0x38)=~4&M2C_FIELD(&data_0212fc70,u16 *,0x38);OS_RestoreInterrupts(t);}
}
#pragma opt_instruction_scheduling reset
u16 func_0200d9f4(void) {
    extern M2C_UNK data_0212fc70;
    return M2C_FIELD(&data_0212fc70, u16 *, 0x10);
}

#pragma opt_instruction_scheduling off
s32 func_0200da04(void *arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5, u16 arg6, u16 arg7, u16 arg8) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    volatile s16 *p = (volatile s16 *)arg0;
    s32 saved;
    s32 c;
    s32 r;
    s32 sy;
    s32 dy;

    if (arg1 >= 0x1000 || arg2 >= 0x1000 || arg5 >= 0x1000 || arg6 >= 0x1000) return 1;
    if (arg3 >= 0x100 || arg7 >= 0x100 || arg4 >= 0xC0 || arg8 >= 0xC0) return 1;
    if (arg3 == arg7 || arg4 == arg8 || arg1 == arg5 || arg2 == arg6) return 1;

    saved = OS_DisableInterrupts();
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = (s32)((arg1 - arg5) << 8);
    *(volatile s64 *)0x04000298 = (u32)(arg3 - arg7);
    dy = (s32)(arg2 - arg6);
    sy = (s32)(arg4 - arg8);
    while (*(volatile u16 *)0x04000280 & 0x8000) {
    }
    r = *(volatile s32 *)0x040002A0;
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = dy << 8;
    *(volatile s64 *)0x04000298 = (u32)sy;
    if (r >= 0x8000 || r < -0x8000) {
        OS_RestoreInterrupts(saved);
        return 1;
    }
    p[2] = (s16)r;
    c = (s32)((arg1 + arg5) << 8) - p[2] * (s32)(arg3 + arg7);
    c = (c << 9) >> 16;
    if (c >= 0x8000 || c < -0x8000) {
        OS_RestoreInterrupts(saved);
        return 1;
    }
    p[0] = (s16)c;
    while (*(volatile u16 *)0x04000280 & 0x8000) {
    }
    r = *(volatile s32 *)0x040002A0;
    OS_RestoreInterrupts(saved);
    if (r >= 0x8000 || r < -0x8000) {
        return 1;
    }
    p[3] = (s16)r;
    c = (s32)((arg2 + arg6) << 8) - p[3] * (s32)(arg4 + arg8);
    c = (c << 9) >> 16;
    if (c >= 0x8000 || c < -0x8000) {
        return 1;
    }
    p[1] = (s16)c;
    return 0;
}
#pragma opt_instruction_scheduling reset
extern s32 data_0212fc8c[];
extern s32 p[];
void func_0200dbf0(u16 *a,u16 *b) {
s32 *p;
if(!M2C_FIELD(&data_0212fc70,u16 *,0x34)) { ((TouchPair *)a)[0]=((TouchPair *)b)[0]; ((TouchPair *)a)[1]=((TouchPair *)b)[1]; return; }
p=data_0212fc8c;
a[2]=b[2]; a[3]=b[3];
if(!b[2]) {a[0]=0;a[1]=0;return;}
a[0]=(((long long)(b[0]<<2)-p[0])*p[2])>>22;
if((s16)a[0]<0)a[0]=0;else if((s16)a[0]>255)a[0]=255;
a[1]=(((long long)(b[1]<<2)-p[3])*p[5])>>22;
if((s16)a[1]<0)a[1]=0;else if((s16)a[1]>191)a[1]=191;
}

void func_0200dd14(u32 a) {while(M2C_FIELD(&data_0212fc70,volatile u16 *,0x3a)&a) {}}

u32 func_0200dd2c(u32 arg0) { return M2C_FIELD(&data_0212fc70, u16 *, 0x38) & arg0; }

