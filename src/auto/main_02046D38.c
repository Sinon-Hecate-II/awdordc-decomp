/* 18 functions from 0x02046D38 to 0x02047B84 (main), found by ds-decomp. */
#include "common.h"

typedef struct { char bytes[17]; } HexDigits;
typedef struct { char bytes[20]; } HashPrefix;
typedef struct { u32 lo, hi; } Unk046Pair;
typedef struct { Unk046Pair a, b; s32 flag; } Unk046State;
void GetWfcProfile(void *);
s32 func_02045d94(void *, s32);
s32 func_02046ebc(void *);

/* Encode a WFC profile code: pack the 16-bit seed, the 24-bit MAC address and
   the flag bits together, then obfuscate the bytes with a fixed XOR, a nibble
   substitution and a byte permutation. */
u64 EncodeWfcProfileCode(u32 seed,u32 mac,u32 flag,u32 type){
void MI_CpuCopy8(u8 *,u8 *,u32);extern u8 sWfcCodeByteOrder[];extern u8 sWfcCodeNibbleMap[];
union { u64 value; u8 bytes[8]; } code;u8 scrambled[8];s32 i;u8 *p;u8 *q;u8 *order;
code.value=((u64)type&3) | (((u64)flag&1)<<2) | (((u64)mac&0xffffff)<<3) | (((u64)seed&0xffff)<<27);
p=code.bytes;
for(i=0;i<6;i++){*p^=0xd6;p++;}
p=code.bytes;
for(i=0;i<5;i++){u8 x=*p;*p++=(sWfcCodeNibbleMap[(x>>4)&15]<<4)|sWfcCodeNibbleMap[x&15];}
MI_CpuCopy8(code.bytes,scrambled,8);
q=scrambled;order=sWfcCodeByteOrder;
for(i=0;i<5;i++)code.bytes[*order++]=*q++;
code.bytes[5]&=7;code.bytes[7]=0;code.bytes[6]=0;
code.value<<=1;
code.bytes[0]|=(code.bytes[5]>>3)&1;
p=code.bytes;for(i=0;i<6;i++){*p^=0x67;p++;}
code.bytes[7]=0;code.bytes[6]=0;code.bytes[5]&=7;
return code.value;
}

#pragma opt_common_subs on
s32 func_02046ebc(void *arg0) {
void GetWfcProfile(void *);void func_0200ee70(void);s32 func_0200ef4c(void *);s32 func_0200eff8(void *);long long MakeTime(void *,void *);u16 func_02006f8c(void);void GetMacAddress(void *);u64 GetSystemTick(void);
u8 *p=arg0;u8 sp[0x24];long long diff;long long seed;u32 state;u8 flag;u32 mac;
GetWfcProfile(p);func_0200ee70();
if(func_0200ef4c(sp+0x14))return 0;
if(func_0200eff8(sp+8))return 0;
diff=MakeTime(sp+0x14,sp+8);if(diff<0)return 0;
seed=diff;
if(func_02006f8c()!=0)seed+=(u32)GetSystemTick;
GetMacAddress(sp);
state=(u32)seed*0x5d588b65+0x269ec3;
flag=(((sp[0]<<16)|(sp[1]<<8)|sp[2])!=0x9bf);
mac=(sp[3]<<16)|(sp[4]<<8)|sp[5];
*(u16 *)(p+0x10)=((state>>16)*1000)>>16;
*(u64 *)p=0;
if(*(u16 *)(p+0x12)==0){
*(u64 *)(p+8)=0;
while(*(u64 *)(p+8)==0){
state=state*0x5d588b65+0x269ec3;while(state==0)state=state*0x5d588b65+0x269ec3;
*(u16 *)(p+0x12)=state;
*(u64 *)(p+8)=EncodeWfcProfileCode(*(u16 *)(p+0x12),mac,flag,0);
}
}else {
*(u64 *)(p+8)=0;
while(*(u64 *)(p+8)==0){
*(u16 *)(p+0x12)+=1;
*(u64 *)(p+8)=EncodeWfcProfileCode(*(u16 *)(p+0x12),mac,flag,0);
}
}
return 1;
}
s32 func_02047098(s32 arg0) { Unk046State s; if (func_02046ebc(&s)==0) return 0; if(func_02045d94(&s,arg0)!=0) return 1; return 0; }

s32 func_020470dc(Unk046State *p, s32 x) { Unk046State s; GetWfcProfile(&s); *(u64 *)&p->a=*(u64 *)&p->b; *(u64 *)&p->b=*(u64 *)&s.b; if(func_02045d94(p,x)!=0) return 1; return 0; }

#pragma opt_propagation off
#pragma opt_common_subs off
s32 func_0204712c(void *arg0) {
    void GetWfcProfile(void *);
    void func_0200ee70(void);
    s32 func_0200ef4c(void *);
    s32 func_0200eff8(void *);
    long long MakeTime(void *, void *);
    u16 func_02006f8c(void);
    void GetMacAddress(void *);
    u64 GetSystemTick(void);
    u64 EncodeWfcProfileCode(u32, u32, u32, u32);

    u8 *p;
    u8 sp[0x24];
    long long diff;
    u32 seed;
    register u32 mult, inc;
register u32 tmp4, tmp3;
    u32 spval;
    register u32 r9;
    register u8 flag;
    register u32 r8;
    u16 f10;
    u16 cand;
    u64 res;

    p = arg0;
    { u8 *q=sp; q[0]=0;q[1]=0;q[2]=0;q[3]=0;q[4]=0;q[5]=0; }

    GetWfcProfile(p);
    func_0200ee70();
    if (func_0200ef4c(&sp[0x14]) != 0) return 0;
    if (func_0200eff8(&sp[0x8]) != 0) return 0;

    diff = MakeTime(&sp[0x14], &sp[0x8]);
    if (diff < 0) return 0;
    if (func_02006f8c() != 0) diff += (u32)GetSystemTick;

    seed = (u32)diff;
    GetMacAddress(sp);
    mult=0x5d588b65;inc=0x269ec3;
    r9 = seed * mult + inc;
    spval = (sp[0] << 16) | (sp[1] << 8) | sp[2];
    flag = (spval != 0x9bf) ? 1 : 0;
    r8 = (sp[3] << 16) | (sp[4] << 8) | sp[5];
    f10 = (u16)(((r9 >> 16) * 1000u) >> 16);
    *(u16 *)((u8 *)p + 0x10) = f10;
    *(u64 *)(p+8) = 0;


    while (*(u64 *)(p + 8) == 0) {
        r9 = r9 * mult + inc;
        while (r9 == 0 || *(u16 *)(p + 0x12) == (u16)r9)
            r9 = r9 * mult + inc;
        *(u16 *)(p + 0x12) = (u16)r9;
        *(u64 *)(p + 8) = EncodeWfcProfileCode(*(u16 *)(p + 0x12), r8, flag, 0);
    }
    return 1;
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
void func_020472cc(Unk046State *p) { Unk046State s; GetWfcProfile(&s); *(u64 *)&p->a=*(u64 *)&s.a; *(u64 *)&p->b=*(u64 *)&s.b; p->flag=*(u64 *)&s.a != 0; }

s32 func_02047320(void) { Unk046State s; GetWfcProfile(&s); if(*(u64 *)&s.b==0 && *(u64 *)&s.a==0)return 1;return 0; }

u32 func_02047370(u32 n) { return ((n % 3 != 0) + n / 3) * 4; }

void func_020473a8(void) {

}

#pragma push
#pragma opt_propagation on
void func_020473ac(void *arg0, u32 arg1, s32 arg2) {
    void MemCopy(void *, const void *, s32);
    void func_02076658(u8 *, u8 *, s32);
    s32 StringLength(const void *);
    s32 StringCompareN(void *, void *, s32);
    void HeapFree(s32, s32, s32);
    extern M2C_UNK gWebRequestState;
    extern u8 data_020ea95c[];
    extern u8 data_020fca88[];
    extern u8 sWebParamHash[];
    extern u8 data_020fcac8[];

    char input[32];
    HashPrefix prefix;
    HexDigits digits;
    s32 state;
    s32 i;
    u8 *target;
    u8 *base;
    s32 len;

    M2C_FIELD(&gWebRequestState, s32 *, 0x8) = -1;
    state = M2C_FIELD(&gWebRequestState, s32 *, 0x4);
    if (state == 1) return;
    if(arg2) goto error;
    switch(state) { case 5:
        if (arg1 == 0x20) {
            target=M2C_FIELD(&gWebRequestState,u8 **,0x58)+20;
            digits=*(HexDigits *)data_020ea95c;
            prefix=*(HashPrefix *)data_020fca88;
            MemCopy(input, arg0, 0x20);
            func_02076658(target, prefix.bytes, 0x34);
            for (i = 0; i < 20; i++) {
                M2C_FIELD(&gWebRequestState,u8 **,0x58)[i*2] = digits.bytes[target[i] >>4];
                M2C_FIELD(&gWebRequestState,u8 **,0x58)[i*2+1] = digits.bytes[target[i]&15];
            }
            len = StringLength(sWebParamHash);
            *(M2C_FIELD(&gWebRequestState,u8 **,0x58)-len) = 0x26;
            M2C_FIELD(&gWebRequestState, s32 *, 0x4) = 6;
            goto free_input;
        } else {
            M2C_FIELD(&gWebRequestState, s32 *, 0x4) = 1;
          free_input:
            HeapFree(0, (s32)arg0, 0);
            return;
        }
    break;
    case 7:
        len = StringLength(data_020fcac8);
        if (StringCompareN(arg0, data_020fcac8, len) == 0) {
            HeapFree(0, (s32)arg0, 0);
            M2C_FIELD(&gWebRequestState, s32 *, 0x4) = 1;
            return;
        } else {
            if (M2C_FIELD(&gWebRequestState, s32 *, 0x60) != 0) {
                HeapFree(0, (s32)M2C_FIELD(&gWebRequestState, s32 *, 0x60), 0);
            }
            M2C_FIELD(&gWebRequestState, s32 **, 0x60) = (s32 *)arg0;
            M2C_FIELD(&gWebRequestState, s32 *, 0x64) = (s32)arg1;
            M2C_FIELD(&gWebRequestState, s32 *, 0x4) = 8;
            return;
        }
    break;
    }
    return;
error:
    M2C_FIELD(&gWebRequestState,s32 *,4)=1;
}
#pragma pop
void func_020475b8(s32 arg0) {
    extern s32 data_0213db80;
    data_0213db80 = arg0 | (arg0 << 0x10);
}

s32 func_020475cc(void) { extern M2C_UNK gWebRequestState; extern s32 data_0213db80; data_0213db80=(M2C_FIELD(&gWebRequestState,s32 *,0x44)*data_0213db80+M2C_FIELD(&gWebRequestState,s32 *,0x48))%M2C_FIELD(&gWebRequestState,s32 *,0x4c); return (data_0213db80>>16)&255; }

s32 func_0204760c(u8 *arg0, u8 *arg1, u32 arg2, u8 *arg3, u32 arg4) {
    extern M2C_UNK gWebRequestState;
    u8 *p;
    u32 sum;
    u32 n;
    s32 i, k, l;
    u8 *HeapAlloc(s32, s32);
    void func_020475b8(s32);
    s32 func_020475cc(void);
    void Base64Encode(u8 *, u8 *, s32, s32);

    n = arg4 + arg2;
    sum = 0;
    p = HeapAlloc(0, n + 4);
    if (p == 0) return 2;
    for (i = 0; i < arg2; i++) p[i + 4] = arg1[i];
    for (i = 0; i < arg4; i++) p[arg2 + i + 4] = arg3[i];
    for (k = 0; k < n; k++) sum += p[k + 4];
    func_020475b8(sum);
    for (l = 0; l < n; l++) {
        p[l + 4] ^= func_020475cc();
    }
    sum ^= M2C_FIELD(&gWebRequestState, u32 *, 0x50);
    p[0] = sum >> 24;
    p[1] = sum >> 16;
    p[2] = sum >> 8;
    p[3] = sum;
    Base64Encode(p, arg0, n + 4, 2);
    HeapFree(0, (s32)p, 0);
    arg0[func_02047370(n + 4)] = 0;
    return 0;
}

#pragma scheduling off
void func_02047750(s32 arg0) { M2C_UNK *p; extern M2C_UNK gWebRequestState,data_020fcad0,data_020fcaf8; M2C_FIELD(&gWebRequestState,s32 *,8)=-1; M2C_FIELD(&gWebRequestState,s32 *,0x54)=0; M2C_FIELD(&gWebRequestState,s32 *,0x58)=0; p=arg0?&data_020fcad0:&data_020fcaf8; M2C_FIELD(&gWebRequestState,s32 *,0x5c)=0; M2C_FIELD(&gWebRequestState,s32 *,0x60)=0; M2C_FIELD(&gWebRequestState,s32 *,0x64)=0; M2C_FIELD(&gWebRequestState,M2C_UNK **,0)=p; func_02044e04(0); M2C_FIELD(&gWebRequestState,s32 *,4)=3; }
#pragma scheduling reset
s32 func_020477ac(void) {
    extern M2C_UNK gWebRequestState;
    void func_020473a8(void);
    void func_020473ac(void *, u32, s32);
    M2C_UNK HttpGetStart(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02044e68(void);

    switch (M2C_FIELD(&gWebRequestState, s32 *, 4)) {
    case 5:
        {
            M2C_UNK r = HttpGetStart(M2C_FIELD(&gWebRequestState, M2C_UNK *, 0x54), (M2C_UNK)0, (M2C_UNK)0,
                          (M2C_UNK)func_020473a8, (M2C_UNK)func_020473ac, (M2C_UNK)0);
            M2C_FIELD(&gWebRequestState, M2C_UNK *, 8) = r;
            if ((s32)r >= 0) {
                M2C_FIELD(&gWebRequestState, s32 *, 4) = 5;
            } else {
                M2C_FIELD(&gWebRequestState, s32 *, 4) = 1;
            }
        }
        break;
    case 6:
        if (func_02044e68() == 0) {
            M2C_FIELD(&gWebRequestState, s32 *, 4) = 1;
        }
        break;
    case 7:
        {
            M2C_UNK r = HttpGetStart(M2C_FIELD(&gWebRequestState, M2C_UNK *, 0x54), (M2C_UNK)0, (M2C_UNK)0,
                          (M2C_UNK)func_020473a8, (M2C_UNK)func_020473ac, (M2C_UNK)0);
            M2C_FIELD(&gWebRequestState, M2C_UNK *, 8) = r;
            if ((s32)r >= 0) {
                M2C_FIELD(&gWebRequestState, s32 *, 4) = 7;
            } else {
                M2C_FIELD(&gWebRequestState, s32 *, 4) = 1;
            }
        }
        break;
    case 8:
        if (func_02044e68() == 0) {
            M2C_FIELD(&gWebRequestState, s32 *, 4) = 1;
        }
        break;
    default:
        break;
    }
    return M2C_FIELD(&gWebRequestState, s32 *, 4);
}

s32 func_020477ac(void);

void func_020478b8(void) { extern M2C_UNK gWebRequestState; M2C_UNK HeapFree(s32,s32,s32); s32 p; p=M2C_FIELD(&gWebRequestState,s32 *,0x54);if(p) {HeapFree(0,p,0);M2C_FIELD(&gWebRequestState,s32 *,0x54)=0;} p=M2C_FIELD(&gWebRequestState,s32 *,0x60);if(p) {HeapFree(0,p,0);M2C_FIELD(&gWebRequestState,s32 *,0x64)=0;M2C_FIELD(&gWebRequestState,s32 *,0x60)=0;} func_02044e28(); M2C_FIELD(&gWebRequestState,s32 *,4)=2; }

s32 func_02047928(s32 *arg0) {
    extern M2C_UNK gWebRequestState;
    *arg0 = M2C_FIELD(&gWebRequestState, s32 *, 0x64);
    return M2C_FIELD(&gWebRequestState, s32 *, 0x60);
}

/* Builds the Nintendo WFC put.asp request into gWebRequestState: formats the
 * base URL with the player id and a hash placeholder, then base64-encodes the
 * 20-byte header plus the payload after "&data=". Returns 0 on success, 2 when
 * the buffer cannot be allocated, and 3 when the request builder is not ready. */
s32 BuildWebPutRequest(s32 playerId, s32 sourceId, s32 field2, s32 field3, s32 payload, void *payloadSize) {
    extern M2C_UNK gWebRequestState;
    extern M2C_UNK sWebParamData;
    extern M2C_UNK sWebHashPlaceholder;
    extern unsigned char sWebParamHash[];
    extern M2C_UNK sWebParamPid;
    extern M2C_UNK sWebPutPath;
    extern M2C_UNK data_020fca68;
    extern M2C_UNK sWebEmptySuffix;
    extern M2C_UNK sWebRequestFormat;
    M2C_UNK StringFormat(M2C_UNK, M2C_UNK, ...);

    s32 dataBase64Len;
    void *buffer;
    u32 header[5];
    char pidText[16];
    s32 lenDataParam, lenHashPlaceholder, lenHashParam, lenPidText;
    s32 lenPidParam, lenPath, lenBase, lenSuffix;
    s32 totalLen;
    s32 formattedLen;
    s32 lenDataParam2, lenHashPlaceholder2;
    s32 encodeResult;
    s32 lenHashParam2;

    if (M2C_FIELD(&gWebRequestState, s32 *, 0x0c) != 1) {
        return 3;
    }

    if (M2C_FIELD(&gWebRequestState, s32 *, 0x54) != 0) {
        HeapFree(0, M2C_FIELD(&gWebRequestState, s32 *, 0x54), 0);
        M2C_FIELD(&gWebRequestState, s32 *, 0x54) = 0;
    }
    dataBase64Len = func_02047370((u8 *)payloadSize+0x18);
    lenDataParam = StringLength(&sWebParamData);
    lenHashPlaceholder = StringLength(&sWebHashPlaceholder);
    lenHashParam = StringLength(sWebParamHash);
    lenPidText = StringLength(func_0206f8b8((void *)sourceId,pidText,10));
    lenPidParam = StringLength(&sWebParamPid);
    lenPath = StringLength(&sWebPutPath);
    lenBase = StringLength(M2C_FIELD(&gWebRequestState,void **,0));
    lenSuffix = StringLength(&data_020fca68);
    totalLen = dataBase64Len + (lenDataParam + (lenHashPlaceholder + (lenHashParam + (lenPidText + (lenPidParam + (lenPath + (lenBase + lenSuffix)))))));
    buffer = HeapAlloc(0, totalLen + 1);
    M2C_FIELD(&gWebRequestState, void **, 0x54) = buffer;
    if (buffer == 0) {
        return 2;
    }

    StringFormat(buffer, &sWebRequestFormat,
                    M2C_FIELD(&gWebRequestState, s32 *, 0x00),
                    &data_020fca68,
                    &sWebPutPath, sourceId, &sWebHashPlaceholder, &sWebEmptySuffix);

    buffer=M2C_FIELD(&gWebRequestState,void **,0x54);
    formattedLen = StringLength(buffer);
    M2C_FIELD(&gWebRequestState, void **, 0x5c) = (void *)((u8 *)buffer + formattedLen);

    lenDataParam2 = StringLength(&sWebParamData);
    lenHashPlaceholder2 = StringLength(&sWebHashPlaceholder);
    M2C_FIELD(&gWebRequestState, s32 *, 0x58) =
        (s32)M2C_FIELD(&gWebRequestState, void **, 0x5c) - lenDataParam2 - lenHashPlaceholder2;

    header[0] = (u32)sourceId;
    header[1] = (u32)field2;
    header[2] = (u32)playerId;
    header[3] = (u32)field3;
    header[4] = (u32)payloadSize;

    encodeResult = func_0204760c(M2C_FIELD(&gWebRequestState, void **, 0x5c), header, 0x14, (void *)payload, (s32)payloadSize);
    if (encodeResult == 2) {
        HeapFree(0, M2C_FIELD(&gWebRequestState, s32 *, 0x54), 0);
        M2C_FIELD(&gWebRequestState, s32 *, 0x54) = 0;
        return 2;
    } else {
        lenHashParam2 = StringLength(sWebParamHash);
        *(u8 *)((u8 *)M2C_FIELD(&gWebRequestState, void **, 0x58) - lenHashParam2) = 0;
        M2C_FIELD(&gWebRequestState, s32 *, 0x04) = 4;
        return 0;
    }
}

