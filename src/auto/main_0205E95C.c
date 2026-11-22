/* 22 functions from 0x0205E95C to 0x0205F83C (main), found by ds-decomp. */
#include "common.h"
#include "qr2.h"

typedef struct { u8 v[4]; } ByteQuad;
typedef struct { u8 v[2]; } BytePair;
typedef struct { u8 bytes[256]; s32 count; } NetworkFieldList;
extern s32 gLocalIpCount;
extern u8 gLocalIps[5][4];
extern u8 gBroadcastAddressText[16];
extern u8 sQr2ConnectTargetMagic[8];

void func_0205e95c(void *arg0) {
    /* Check connection timeouts and retry/reset state as needed. */
    M2C_UNK Qr2_SendKeepAlive(void *);
    extern M2C_UNK data_020ffa08;
    s32 retryCount;
    u32 lastActivity;
    u32 now;

    now = GetSystemTickMilliseconds();
    if (M2C_FIELD(arg0, s32 *, 0) == -1) {
        return;
    }
    retryCount = M2C_FIELD(arg0, s32 *, 0xB8);
    if ((retryCount > 0) && ((u32) (now - M2C_FIELD(arg0, u32 *, 0xAC)) > 0x2710U)) {
        if (retryCount >= 4) {
            M2C_FIELD(arg0, s32 *, 0xB8) = 0;
            M2C_FIELD(arg0, M2C_UNK (**)(M2C_UNK, M2C_UNK *, s32), 0x9C)(5, &data_020ffa08, M2C_FIELD(arg0, s32 *, 0x10C));
            return;
        }
        Qr2_SendState(arg0, 3);
        M2C_FIELD(arg0, s32 *, 0xB8) = (s32) (M2C_FIELD(arg0, s32 *, 0xB8) + 1);
        goto block_14;
    }
    if ((M2C_FIELD(arg0, s32 *, 0xB4) != 0) && ((u32) (now - M2C_FIELD(arg0, u32 *, 0xAC)) > 0x2710U)) {
        Qr2_SendState(arg0, 1);
    } else {
        lastActivity = M2C_FIELD(arg0, u32 *, 0xAC);
        if (((u32) (now - lastActivity) > 0xEA60U) || (lastActivity == 0) || (now < lastActivity)) {
            Qr2_SendState(arg0, 0);
        }
    }
block_14:
    if ((u32) (now - M2C_FIELD(arg0, s32 *, 0xB0)) <= 0x4E20U) {
        return;
    }
    Qr2_SendKeepAlive(arg0);
}

/* Report to the master that a QR2 connection's state changed: when a state query
 * went out less than ten seconds ago, only mark the state dirty so the next poll
 * sends it, otherwise send the state change now and clear the dirty flag.  A NULL
 * argument means the current global connection. */
void Qr2_StateChanged(void *qr2) {
    s32 GetSystemTickMilliseconds();
    M2C_UNK Qr2_SendState(void *, M2C_UNK);
    extern void *gQr2Connection;

    if (qr2 == NULL) {
        qr2 = gQr2Connection;
    }
    if (M2C_FIELD(qr2, s32 *, QR2_REPORT_TO_MASTER) == 0) {
        return;
    }
    if ((u32) (GetSystemTickMilliseconds() - M2C_FIELD(qr2, s32 *, QR2_LAST_SENT)) < QR2_STATE_MIN_INTERVAL_MS) {
        M2C_FIELD(qr2, s32 *, QR2_STATE_DIRTY) = 1;
        return;
    }
    Qr2_SendState(qr2, QR2_STATE_CHANGED);
    M2C_FIELD(qr2, s32 *, QR2_STATE_DIRTY) = 0;
}

/* Tear down a QR2 connection: report the final state to the master, close its
 * socket and release its receive buffer, then free the record itself - unless
 * it is the static default record, which is never freed.  A NULL record means
 * the current global connection. */
void Qr2_DestroyConnection(void *qr2) {
    extern void *gQr2Connection;
    extern M2C_UNK gQr2DefaultConnection;
    void ghiCloseSocket(s32, s32);
    void func_02049270(s32);
    void gpiFree(void *);
    if (!qr2) qr2 = gQr2Connection;
    if (M2C_FIELD(qr2, s32 *, QR2_REPORT_TO_MASTER)) Qr2_SendState(qr2, QR2_STATE_FINAL);
    if (M2C_FIELD(qr2, s32 *, QR2_SOCKET) != -1 && M2C_FIELD(qr2, s32 *, QR2_RECV_BUFFER)) {
        ghiCloseSocket(M2C_FIELD(qr2, s32 *, QR2_SOCKET), M2C_FIELD(qr2, s32 *, QR2_RECV_BUFFER));
    }
    M2C_FIELD(qr2, s32 *, QR2_SOCKET) = -1;
    M2C_FIELD(qr2, s32 *, QR2_LAST_SENT) = 0;
    if (M2C_FIELD(qr2, s32 *, QR2_RECV_BUFFER)) func_02049270(M2C_FIELD(qr2, s32 *, QR2_RECV_BUFFER));
    if (qr2 == &gQr2DefaultConnection) return;
    gpiFree(qr2);
}

#pragma optimization_level 2
#pragma opt_cond_exec off
void Qr2AppendKeyId(u8 *p, s32 a) {
    s32 n = M2C_FIELD(p, s32 *, 0x100);
    if (n >= 254) return;
    if (a < 1 || a > 254) return;
    M2C_FIELD(p, s32 *, 0x100) = n + 1;
    p[n] = (u8)a;
}
#pragma opt_cond_exec reset
#pragma optimization_level reset
void Qr2AppendInt(void *a,M2C_UNK b){void Qr2AppendString(void *,M2C_UNK *);void StringFormat(void *,void *,M2C_UNK,...);extern M2C_UNK data_020ffa40;u8 buf[20];StringFormat(buf,&data_020ffa40,b);Qr2AppendString(a,(M2C_UNK *)buf);}

/* Appends the NUL-terminated `text` to a QR2 query string (its used length kept
   at QR2_QUERY_COUNT): the string is truncated so the query never exceeds
   QR2_QUERY_SIZE bytes, and the buffer stays NUL-terminated. */
void Qr2AppendString(void *query, M2C_UNK *text) {
    s32 StringLength(void *); void MemCopy(void *, void *, s32);
    s32 n = StringLength(text) + 1;
    s32 used = M2C_FIELD(query, s32 *, QR2_QUERY_COUNT);
    if (n > QR2_QUERY_SIZE - used) n = QR2_QUERY_SIZE - used;
    if (!n) return;
    MemCopy((u8 *)query + used, text, n);
    M2C_FIELD(query, s32 *, QR2_QUERY_COUNT) += n;
    ((u8 *)query)[M2C_FIELD(query, s32 *, QR2_QUERY_COUNT) - 1] = 0;
}

#pragma opt_common_subs off
void RefreshLocalIps(void) {
void *GetLocalHostAddresses(void);
void *p=GetLocalHostAddresses();
s32 i;volatile u8 *s;u32 x,y;

if(!p)return;gLocalIpCount=0;
i=0;do{
s=M2C_FIELD(p,u8 ***,12)[i];if(!s)return;
x=s[0];y=s[1];gLocalIps[i][0]=x;gLocalIps[i][1]=y;
x=s[2];y=s[3];gLocalIps[i][2]=x;gLocalIps[i][3]=y;
gLocalIpCount=++i;
}while(i<5);
}
#pragma opt_common_subs reset
/* Fills a socket address (family AF_INET, `port` byte-swapped to network order,
 * IPv4 address) for `hostname`: a NULL name means address 0 (INADDR_ANY), dotted
 * numeric text is parsed by ghiInetAddr, anything else goes through the blocking
 * resolver ghiResolveHostname - except the broadcast address "255.255.255.255",
 * which is kept as-is instead of being resolved.  Optionally hands back the
 * resolver's host record.  Returns 0 when the name does not resolve. */
s32 ResolveHostAddress(s32 hostname,s32 port,void *addr,void **hostEntryOut){s32 ghiInetAddr(s32);s32 StringCompare(s32,void *);void *ghiResolveHostname(s32);u16 hostPort=port;void *hostEntry=0;M2C_FIELD(addr,u8 *,1)=2;M2C_FIELD(addr,u16 *,2)=((u8)(hostPort>>8))|((hostPort<<8)&0xff00);if(!hostname)M2C_FIELD(addr,s32 *,4)=0;else M2C_FIELD(addr,s32 *,4)=ghiInetAddr(hostname);if(M2C_FIELD(addr,s32 *,4)==-1&&StringCompare(hostname,gBroadcastAddressText)){hostEntry=ghiResolveHostname(hostname);if(!hostEntry)return 0;M2C_FIELD(addr,s32 *,4)=**M2C_FIELD(hostEntry,s32 ***,12);}if(hostEntryOut)*hostEntryOut=hostEntry;return 1;}

void SwapBytes(u8 *arg0, u8 *arg1) {
    u8 temp_r3;

    temp_r3 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_r3;
}

u8 Base64EncodeChar(u32 a){if(a<26)return a+65;if(a<52)return a+71;if(a<62)return a-4;if(a==62)return 43;if(a==63)return 47;return 0;}

/* Base64-encode `count` bytes from `src_void` into `dst_void`, QR2 style:
   every 3-byte group (zero padded when the input runs out) becomes 4 six-bit
   values, each mapped through the standard alphabet by Base64EncodeChar.
   No '=' padding is emitted; the result is NUL-terminated. */
void Base64EncodeRaw(void *src_void, s32 count, void *dst_void) {
    u8 *src = (u8 *) src_void;
    u8 *dst = (u8 *) dst_void;
    u8 buf[3];
    u8 out[4];
    s32 i;
    s32 j;
    i = 0;
    if (count <= 0) goto end;
    for (;;) {
        j = 0;
        /* Fill one 3-byte group, zero-padding past the end of the input. */
        for (;;) {
            if (i < count) {
                buf[j] = *src++;
            } else {
                buf[j] = 0;
            }
            i++;
            j++;
            if (j > 2) break;
        }
        out[0] = (u8) (buf[0] >> 2);
        out[1] = (u8) (((buf[0] & 3) << 4) + (buf[1] >> 4));
        out[2] = (u8) (((buf[1] & 0x0f) << 2) + (buf[2] >> 6));
        out[3] = (u8) (buf[2] & 0x3f);
        j = 0;
        for (;;) {
            *dst++ = Base64EncodeChar(out[j]);
            j++;
            if (j > 3) break;
        }
        if (i >= count) break;
    }
end:
    *dst = 0;
}

/* The GameSpy QR2 stream cipher: build a 256-byte permutation from `keySeed`,
 * then XOR `dataBuffer` with the keystream it generates (the same step encrypts
 * and decrypts).  Used on the state string of a state reply, keyed by the
 * connection's secret key. */
void Qr2CryptStateString(void *keySeed, s32 keyLength, void *dataBuffer, s32 dataLength) {
    unsigned long long RuntimeIntDivMod(s32, s32);
    u8 sbox[256];
    u8 *key;
    u8 *data;
    s32 keyLen;
    s32 dataLen;
    s16 i;
    u8 keyIndex;
    u8 j;
    s16 dataIndex;
    u8 dataJ, dataK;
    u8 streamIndex;
    u8 *sboxPtr;

    key = (u8 *)keySeed;
    data = (u8 *)dataBuffer;
    keyLen = keyLength;
    dataLen = dataLength;

    for (i = 0; i < 256; i++) {
        sbox[i] = (u8)i;
    }

    keyIndex = 0;
    j = 0;
    sboxPtr = sbox;
    for (i = 0; i < 256; i++) {
        j = (u8)((*sboxPtr + key[keyIndex] + j) % 256);
        keyIndex = (u8)(RuntimeIntDivMod(keyIndex + 1, keyLen) >> 32);
        SwapBytes(sboxPtr, sbox + j);
        sboxPtr++;
    }

    dataJ = 0;
    dataK = 0;
    dataIndex = 0;
    if (dataIndex < dataLen) do {
        dataJ = (u8)((dataJ + data[dataIndex] + 1) % 256);
        dataK = (u8)((sbox[dataJ] + dataK) % 256);
        SwapBytes(sbox + dataJ, sbox + dataK);
        streamIndex = (u8)((sbox[dataJ] + sbox[dataK]) % 256);
        data[dataIndex] ^= sbox[streamIndex];
        dataIndex++;
    } while (dataIndex < dataLen);
}

void Qr2InitQuery(u8 *a,s8 b,ByteQuad *c){a[0]=b;*(ByteQuad *)(a+1)=*c;M2C_FIELD(a,s32 *,0x800)=5;}

/* Appends another player's state string to a state reply: the string must be 1 to
   65 bytes with a terminating NUL, so it is copied out and ciphered with the QR2
   state-string cipher keyed by the connection's secret key, then base64-encoded
   into the reply buffer and the reply length moved past it. */
void Qr2_AppendStateString(void *qr2, void *reply, s8 *state, s32 length) {
    void StringCopy(void *, void *);
    s32 StringLength(void *);
    void Qr2CryptStateString(void *, s32, void *, s32);
    void Base64EncodeRaw(void *, s32, void *);
    s8 buf[QR2_STATE_STRING_MAX];

    if (length < 1) return;
    if (length > QR2_STATE_STRING_MAX) return;
    if (state[length - 1]) return;
    StringCopy(buf, state);
    Qr2CryptStateString((u8 *)qr2 + QR2_SECRET_KEY, StringLength((u8 *)qr2 + QR2_SECRET_KEY), buf, length - 1);
    Base64EncodeRaw(buf, length - 1, (u8 *)reply + M2C_FIELD(reply, s32 *, QR2_QUERY_COUNT));
    M2C_FIELD(reply, s32 *, QR2_QUERY_COUNT) += StringLength((u8 *)reply + M2C_FIELD(reply, s32 *, QR2_QUERY_COUNT)) + 1;
}

/* GameSpy QR2: parse the master's public-address reply, which packs the address
   in network byte order and the port as hex ("%08X%04X"), convert the address
   to host order and, when it differs from the cached one, store it and tell the
   application through its public-address callback. */
void Qr2_ParsePublicAddress(void *qr2, M2C_UNK text) {
    M2C_UNK StringScanf(M2C_UNK, M2C_UNK *, u32 *, s32 *);
    extern M2C_UNK sQr2PublicAddressFormat;
    u32 wireAddress; s32 portValue; u16 port; u32 address;
    StringScanf(text, &sQr2PublicAddressFormat, &wireAddress, &portValue);
    port = portValue;
    address = ((wireAddress << 24) & 0xff000000) | (((wireAddress << 8) & 0xff0000) | ((u8)(wireAddress >> 24) | ((wireAddress >> 8) & 0xff00)));
    wireAddress = address;
    if (address && port) {
        if (M2C_FIELD(qr2, u32 *, QR2_PUBLIC_IP) == address && M2C_FIELD(qr2, u16 *, QR2_PUBLIC_PORT) == port) return;
        M2C_FIELD(qr2, u32 *, QR2_PUBLIC_IP) = address;
        M2C_FIELD(qr2, u16 *, QR2_PUBLIC_PORT) = port;
        M2C_FIELD(qr2, M2C_UNK (**)(u32, u16, s32), QR2_CB_PUBLIC_ADDRESS)(wireAddress, port, M2C_FIELD(qr2, s32 *, QR2_CTX));
    }
}

#pragma push
#pragma opt_common_subs off
void Qr2AppendPlayerFieldGroup(M2C_UNK a0,M2C_UNK a1,M2C_UNK a2,s32 count,s32 listPtr) {
void Qr2AppendString(void *,M2C_UNK *);
extern M2C_UNK sQr2UnknownKey,sQr2EmptyValue;
extern M2C_UNK *gQr2KeyNames[];
NetworkFieldList fields; u16 wire; s32 port; u8 *wireBytes; u8 lo,hi; u8 *out; s32 n=0; s32 reps,j,before,i,k; u8 *p=(u8 *)listPtr; M2C_UNK *name;
fields.count=0;
if(!count)return;
if((u32)(a2-1)<=1) {
if((u32)(2048-M2C_FIELD(a1,s32 *,2048))<2)return;
reps=M2C_FIELD(a0,s32 (**)(s32,s32),0x98)(a2,M2C_FIELD(a0,s32 *,0x10c));
port=(u16)reps; wire=((port>>8)&255)|((port<<8)&0xff00);
wireBytes=(u8 *)&wire;
hi=wireBytes[1];
n=M2C_FIELD(a1,s32 *,2048);
lo=wireBytes[0];
out=(u8 *)a1+n;
out[0]=lo;out[1]=hi;
M2C_FIELD(a1,s32 *,2048)+=2;
} else reps=1;
if(count==255) {
M2C_FIELD(a0,void (**)(s32,u8 *,s32),0x94)(a2,fields.bytes,M2C_FIELD(a0,s32 *,0x10c));
i=0;
if(fields.count>0) {
p=fields.bytes;
do {
name=gQr2KeyNames[*p]; if(!name)name=&sQr2UnknownKey;
Qr2AppendString((void *)a1,name);
if(a2==0) {
before=M2C_FIELD(a1,s32 *,2048);
M2C_FIELD(a0,void (**)(s32,s32,s32),0x88)(*p,a1,M2C_FIELD(a0,s32 *,0x10c));
if(before==M2C_FIELD(a1,s32 *,2048))Qr2AppendString((void *)a1,&sQr2EmptyValue);
}
i++;p++;
}while(i<fields.count);
}
n=M2C_FIELD(a1,s32 *,2048);
if(2048-n<1)return;
M2C_FIELD(a1,s32 *,2048)=n+1;
((u8 *)a1)[n]=0;
count=fields.count;
p=fields.bytes;
if(a2==0)return;
}
for(j=0;j<reps;j++) {
for(k=0;k<count;k++) {
before=M2C_FIELD(a1,s32 *,2048);
if(a2==0) M2C_FIELD(a0,void (**)(s32,s32,s32),0x88)(p[k],a1,M2C_FIELD(a0,s32 *,0x10c));
else if(a2==1) M2C_FIELD(a0,void (**)(s32,s32,s32,s32),0x8c)(p[k],j,a1,M2C_FIELD(a0,s32 *,0x10c));
else if(a2==2) M2C_FIELD(a0,void (**)(s32,s32,s32,s32),0x90)(p[k],j,a1,M2C_FIELD(a0,s32 *,0x10c));
if(before==M2C_FIELD(a1,s32 *,2048))Qr2AppendString((void *)a1,&sQr2EmptyValue);
}
}
}
#pragma pop
/* Append a player record's three field groups to a QR2 query string: the plain
 * "key\value" pairs, then the two indexed key groups (see Qr2AppendPlayerRecord). */
void Qr2AppendPlayerFields(M2C_UNK qr2Record, M2C_UNK query, s32 plainLength, s32 plainFields, s32 indexedLength, s32 indexedFields, s32 indexed2Length, s32 indexed2Fields) {
    void Qr2AppendPlayerFieldGroup(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    Qr2AppendPlayerFieldGroup(qr2Record, query, QR2_KEY_MODE_PLAIN, plainLength, plainFields);
    Qr2AppendPlayerFieldGroup(qr2Record, query, QR2_KEY_MODE_INDEXED1, indexedLength, indexedFields);
    Qr2AppendPlayerFieldGroup(qr2Record, query, QR2_KEY_MODE_INDEXED2, indexed2Length, indexed2Fields);
}

/* Appends one player record to a QR2 query string.  A record is three
 * length-prefixed field lists: the plain "key\value" fields, then the two
 * indexed field groups.  A length of 0 means the group is empty and
 * QR2_FIELDS_ALL means "every key of the group", in which case no list
 * follows in the record. */
void Qr2AppendPlayerRecord(M2C_UNK qr2Record, void *query, u8 *record, s32 length) {
    s32 plainLength, indexedLength, indexed2Length;
    s32 plainFields = 0, indexedFields = 0, indexed2Fields = 0;

    if (length < 3) return;
    plainLength = *record++;
    length--;
    if (plainLength != 0 && plainLength != QR2_FIELDS_ALL) {
        plainFields = (s32)record;
        length -= plainLength;
        record += plainLength;
    }
    if (length < 2) return;
    indexedLength = *record++;
    length--;
    if (indexedLength != 0 && indexedLength != QR2_FIELDS_ALL) {
        indexedFields = (s32)record;
        length -= indexedLength;
        record += indexedLength;
    }
    if (length < 1) return;
    indexed2Length = *record;
    length--;
    if (indexed2Length != 0 && indexed2Length != QR2_FIELDS_ALL) {
        length -= indexed2Length;
        indexed2Fields = (s32)(record + 1);
    }
    if (length < 0) return;
    Qr2AppendPlayerFields(qr2Record, query, plainLength, plainFields, indexedLength, indexedFields, indexed2Length, indexed2Fields);
}

/* Appends every key of one mode to a QR2 query string. mode 0 writes plain
 * "key\value" pairs, modes 1 and 2 write each indexed key "name%d" repeated by
 * the record's repeat count; the record's callbacks do the actual formatting. */
void Qr2AppendKeys(M2C_UNK qr2Record, void *query, M2C_UNK mode) {
    void StringFormat(void *, void *, M2C_UNK, ...);
    extern M2C_UNK *gQr2KeyNames[];
    extern M2C_UNK sQr2UnknownKey, sQr2EmptyValue, sQr2IndexedKeyFormat;
    u8 valueText[128];
    NetworkFieldList keyList;
    s32 i;
    s32 j, lengthBefore;
    u8 *keyId;
    M2C_UNK *keyName;
    s32 repeatCount;
    void *record = (void *)qr2Record;
    u8 *queryBuf = query;

    keyList.count = 0;
    if ((u32)(mode - 1) <= 1) {
        repeatCount = M2C_FIELD(record, s32 (**)(s32, s32), QR2_CB_REPEAT_COUNT)(mode, M2C_FIELD(record, s32 *, QR2_CTX));
    } else {
        repeatCount = 1;
    }
    M2C_FIELD(record, void (**)(s32, void *, s32), QR2_CB_COLLECT_KEYS)(mode, keyList.bytes, M2C_FIELD(record, s32 *, QR2_CTX));
    i = 0;
    if (keyList.count <= 0) return;
    do {
        keyId = keyList.bytes + i;
        keyName = gQr2KeyNames[*keyId];
        if (!keyName) keyName = &sQr2UnknownKey;
        if (!mode) {
            Qr2AppendString(queryBuf, keyName);
            queryBuf[M2C_FIELD(queryBuf, s32 *, QR2_QUERY_COUNT) - 1] = '\\';
            lengthBefore = M2C_FIELD(queryBuf, s32 *, QR2_QUERY_COUNT);
            M2C_FIELD(record, void (**)(s32, void *, s32), QR2_CB_APPEND_KEY)(*keyId, queryBuf, M2C_FIELD(record, s32 *, QR2_CTX));
            if (lengthBefore == M2C_FIELD(queryBuf, s32 *, QR2_QUERY_COUNT)) Qr2AppendString(queryBuf, &sQr2EmptyValue);
            queryBuf[M2C_FIELD(queryBuf, s32 *, QR2_QUERY_COUNT) - 1] = '\\';
        } else {
            for (j = 0; j < repeatCount; j++) {
                StringFormat(valueText, &sQr2IndexedKeyFormat, (s32)keyName, j);
                Qr2AppendString(queryBuf, (M2C_UNK *)valueText);
                queryBuf[M2C_FIELD(queryBuf, s32 *, QR2_QUERY_COUNT) - 1] = '\\';
                lengthBefore = M2C_FIELD(queryBuf, s32 *, QR2_QUERY_COUNT);
                if (mode == 1) {
                    M2C_FIELD(record, void (**)(s32, s32, void *, s32), QR2_CB_APPEND_IDX1)(*keyId, j, queryBuf, M2C_FIELD(record, s32 *, QR2_CTX));
                } else if (mode == 2) {
                    M2C_FIELD(record, void (**)(s32, s32, void *, s32), QR2_CB_APPEND_IDX2)(*keyId, j, queryBuf, M2C_FIELD(record, s32 *, QR2_CTX));
                }
                if (lengthBefore == M2C_FIELD(queryBuf, s32 *, QR2_QUERY_COUNT)) Qr2AppendString(queryBuf, &sQr2EmptyValue);
                queryBuf[M2C_FIELD(queryBuf, s32 *, QR2_QUERY_COUNT) - 1] = '\\';
            }
        }
        i++;
    } while (i < keyList.count);
}

/* Build the final query for the master: start the buffer at a bare '\', append the
 * three key groups, then the sQr2FinalQueryTrailer marker.  The stored length at
 * QR2_QUERY_COUNT is left excluding the terminating NUL. */
void Qr2_AppendFinalQuery(M2C_UNK qr2, void *query) {
    void Qr2AppendString(void *, M2C_UNK *);
    void Qr2AppendKeys(M2C_UNK, void *, M2C_UNK);
    extern M2C_UNK sQr2FinalQueryTrailer;
    M2C_FIELD(query, s32 *, QR2_QUERY_COUNT) = 1;
    M2C_FIELD(query, s8 *, 0) = '\\';
    Qr2AppendKeys(qr2, query, QR2_KEY_MODE_PLAIN);
    Qr2AppendKeys(qr2, query, QR2_KEY_MODE_INDEXED1);
    Qr2AppendKeys(qr2, query, QR2_KEY_MODE_INDEXED2);
    Qr2AppendString(query, &sQr2FinalQueryTrailer);
    M2C_FIELD(query, s32 *, QR2_QUERY_COUNT) = (s32) (M2C_FIELD(query, s32 *, QR2_QUERY_COUNT) - 1);
}

#pragma opt_strength_reduction off
/* Handle the body of a peer-relayed QR2 message (a QR2_TYPE_PEER packet after
 * its 4-byte id): when it starts with the 6-byte connect-target magic followed by
 * a network-order IPv4 address, deliver that address (converted to host order)
 * to the state-changed callback; any other body goes to the receive-state
 * callback. */
void Qr2_HandlePeerPacket(void *qr2, void *packet, s32 bytes) {
    u8 targetMagic[6] = {0xfd, 0xfc, 0x1e, 0x66, 0x6a, 0xb2};
    u32 wireAddress;
    
    s32 i;
    s32 isConnectTarget;
    u8 *magicByte=targetMagic;
    u32 targetAddress;
    u32 wireValue;
    M2C_UNK (*cbTarget)(M2C_UNK, M2C_UNK);
    M2C_UNK (*cbReceive)(M2C_UNK, M2C_UNK, M2C_UNK);


    isConnectTarget = 1;
    if (bytes >= 10) {
        for (i = 0; i < 6; i++,magicByte++) {
            if (*magicByte != ((u8 *)packet)[i]) {
                isConnectTarget = 0;
                break;
            }
        }
    } else { isConnectTarget=0; }

    if (!isConnectTarget) goto not_connect_target;

    { u8 *wireBytes=(u8 *)&wireAddress; u8 a=((u8 *)packet)[6], b=((u8 *)packet)[7]; wireBytes[0]=a; wireBytes[1]=b; a=((u8 *)packet)[8]; b=((u8 *)packet)[9]; wireBytes[3]=b; wireBytes[2]=a; }

    cbTarget = M2C_FIELD(qr2, M2C_UNK (**)(M2C_UNK, M2C_UNK), QR2_CB_STATE_CHANGED);
    if (cbTarget == NULL) return;
    {
    wireValue = wireAddress;
    targetAddress = ((wireValue >> 24) & 0xFFU) |
          ((wireValue >> 8) & 0xFF00U) |
          ((wireValue << 8) & 0xFF0000U) |
          ((wireValue << 24) & 0xFF000000U);

        cbTarget(targetAddress, M2C_FIELD(qr2, M2C_UNK *, QR2_CTX));
    }
    return;

not_connect_target:
    cbReceive = M2C_FIELD(qr2, M2C_UNK (**)(M2C_UNK, M2C_UNK, M2C_UNK), QR2_CB_RECEIVE_STATE);
    if (cbReceive != NULL) {
        cbReceive(packet, bytes, M2C_FIELD(qr2, M2C_UNK *, QR2_CTX));
    }
}
#pragma opt_strength_reduction reset
/* Remembers the request id of a just-received QR2 message: 1 when one of the
 * last QR2_RECENT_ID_COUNT ids is already `id` (a duplicate the caller drops),
 * 0 when the id was added to the ring at the next slot instead. */
s32 Qr2_RememberRequest(void *qr2,s32 id) {
 s32 i=0;
loop:
 if(M2C_FIELD((u8 *)qr2+((u32)i<<2),s32 *,QR2_RECENT_IDS)==id)return 1;
 i++;
 if(i<QR2_RECENT_ID_COUNT)goto loop;
 M2C_FIELD(qr2,s32 *,QR2_RECENT_INDEX)=(M2C_FIELD(qr2,s32 *,QR2_RECENT_INDEX)+1)%QR2_RECENT_ID_COUNT;
 i=M2C_FIELD(qr2,s32 *,QR2_RECENT_INDEX);
 M2C_FIELD(qr2,s32 *,QR2_RECENT_INDEX)=i;
 M2C_FIELD((u8 *)qr2+((u32)i<<2),s32 *,QR2_RECENT_IDS)=id;
 return 0;
}

