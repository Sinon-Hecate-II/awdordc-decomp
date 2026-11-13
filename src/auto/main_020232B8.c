/* 16 functions from 0x020232B8 to 0x02024260 (main), found by ds-decomp. */
#include "common.h"

M2C_UNK func_020232b8(void *p) {
 M2C_UNK func_0202321c(void *,void *,void *);
 M2C_UNK MI_CpuCopy8(s32,s32,u32);
 extern M2C_UNK data_020fb048,data_020fb04c,data_020fb050;
 u8 buf[48];
 func_0202321c(buf,&data_020fb048,p);
 func_0202321c(buf+16,&data_020fb04c,p);
 func_0202321c(buf+32,&data_020fb050,p);
 return MI_CpuCopy8((s32)buf,(s32)p,48);
}

/* Derives the TLS record-layer keys: for each direction it runs the master secret
 * through the key-block PRF (SHA1 or MD5 per the negotiated hash) once per block and
 * writes the per-direction MAC secrets and RC4 keys into TLS_KEY_BLOCK, then points
 * the in/out MAC key fields at them and initialises both RC4 states. */
M2C_UNK TlsInitRecordKeys(void *arg0) {
    M2C_UNK SHA1_Init();
    M2C_UNK SHA1_Update();
    M2C_UNK SHA1_Final();
    M2C_UNK MD5_Init();
    M2C_UNK MD5_Update();
    M2C_UNK MD5_Final();
    M2C_UNK RC4_Init();
    u8 buf[0x18];
    s32 base;
    s32 w;
    s32 h;
    s32 t;
    s32 i;
    s32 j;
    s32 off;
    s32 bw;
    s32 bt;

    switch (M2C_FIELD(arg0, u16 *, TLS_HASH_ALGORITHM)) {
    case TLS_HASH_MD5:
        w = 0x10;
        h = 0x10;
        t = 0;
        break;
    case TLS_HASH_SHA1:
        w = 0x14;
        h = 0x10;
        t = 0;
        break;
    }
    i = 0;
    if ((w + h + t) * 2 > 0) {
        base = (s32)arg0 + TLS_KEY_BLOCK;
        off = i;
        do {
            SHA1_Init((s32)arg0 + TLS_SHA1_CTX);
            buf[0] = (u8)(i + 0x41);
            for (j = 0; j < i + 1; j++) {
                SHA1_Update((s32)arg0 + TLS_SHA1_CTX, buf, 1);
            }
            SHA1_Update((s32)arg0 + TLS_SHA1_CTX, (s32)arg0 + TLS_MASTER_SECRET, 0x30);
            SHA1_Update((s32)arg0 + TLS_SHA1_CTX, (s32)arg0 + TLS_RANDOM_B, 0x20);
            SHA1_Update((s32)arg0 + TLS_SHA1_CTX, (s32)arg0 + TLS_RANDOM_A, 0x20);
            SHA1_Final((s32)arg0 + TLS_SHA1_CTX, buf + 1);
            MD5_Init((s32)arg0 + TLS_MD5_CTX);
            MD5_Update((s32)arg0 + TLS_MD5_CTX, (s32)arg0 + TLS_MASTER_SECRET, 0x30);
            MD5_Update((s32)arg0 + TLS_MD5_CTX, buf + 1, 0x14);
            MD5_Final((s32)arg0 + TLS_MD5_CTX, base + off);
            off += 0x10;
            i++;
        } while (off < (w + h + t) * 2);
    }
    if (M2C_FIELD(arg0, u8 *, TLS_SERVER_SIDE) != 0) {
        base = (s32)arg0 + TLS_KEY_BLOCK;
        M2C_FIELD(arg0, s32 *, TLS_MAC_KEY_IN) = base;
        M2C_FIELD(arg0, s32 *, TLS_RC4_KEY_IN) = base + 2 * w;
        bw = base + w;
        M2C_FIELD(arg0, s32 *, TLS_MAC_KEY_OUT) = bw;
        bt = bw + w;
        M2C_FIELD(arg0, s32 *, TLS_RC4_KEY_OUT) = bt + h;
    } else {
        base = (s32)arg0 + TLS_KEY_BLOCK;
        M2C_FIELD(arg0, s32 *, TLS_MAC_KEY_OUT) = base;
        M2C_FIELD(arg0, s32 *, TLS_RC4_KEY_OUT) = base + 2 * w;
        bw = base + w;
        M2C_FIELD(arg0, s32 *, TLS_MAC_KEY_IN) = bw;
        bt = bw + w;
        M2C_FIELD(arg0, s32 *, TLS_RC4_KEY_IN) = bt + h;
    }
    RC4_Init((s32)arg0 + TLS_RC4_IN, M2C_FIELD(arg0, s32 *, TLS_RC4_KEY_IN), 0x10);
    RC4_Init((s32)arg0 + TLS_RC4_OUT, M2C_FIELD(arg0, s32 *, TLS_RC4_KEY_OUT), 0x10);
}

void TlsProcessClientKeyExchange(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_02021f1c(void *, M2C_UNK, M2C_UNK);
    M2C_UNK RsaCrtDecrypt(void *, M2C_UNK, s32);
    M2C_UNK func_020232b8(void *);
    M2C_UNK TlsInitRecordKeys(void *);
    RsaCrtDecrypt(arg0, arg1, M2C_FIELD(arg0, s32 *, 0x81C));
    func_020232b8(arg0);
    func_02021f1c(arg0, 0, 0);
    TlsInitRecordKeys(arg0);
    M2C_FIELD(arg0, s8 *, 0x455) = 5;
}

M2C_UNK TlsComputeFinishedMd5(void *arg0, void *arg1, s32 arg2) {
    M2C_UNK MD5_Init();
    M2C_UNK MD5_Update();
    M2C_UNK MD5_Final();
    M2C_UNK MI_CpuFill8();
    extern u8 data_020fb054[], data_020fb05c[];
    u8 sp0[0x30];
    if ((M2C_FIELD(arg0, u8 *, 0x454) ^ arg2) != 0)
        MD5_Update(arg0 + 0x3A4, data_020fb054, 4);
    else
        MD5_Update(arg0 + 0x3A4, data_020fb05c, 4);
    MD5_Update(arg0 + 0x3A4, arg0, 0x30);
    MI_CpuFill8(sp0, 0x36, 0x30);
    MD5_Update(arg0 + 0x3A4, sp0, 0x30);
    MD5_Final(arg0 + 0x3A4, arg1);
    MD5_Init(arg0 + 0x3A4);
    MD5_Update(arg0 + 0x3A4, arg0, 0x30);
    MI_CpuFill8(sp0, 0x5C, 0x30);
    MD5_Update(arg0 + 0x3A4, sp0, 0x30);
    MD5_Update(arg0 + 0x3A4, arg1, 0x10);
    MD5_Final(arg0 + 0x3A4, arg1);
}

M2C_UNK TlsComputeFinishedSha1(void *arg0, void *arg1, s32 arg2) {
M2C_UNK SHA1_Update(); M2C_UNK MI_CpuFill8(void *,s32,s32); M2C_UNK SHA1_Final(void *,void *); M2C_UNK SHA1_Init(void *);
extern u8 data_020fb054[],data_020fb05c[];
u8 sp0[40];
if((M2C_FIELD(arg0,u8 *,0x454)^arg2)!=0) SHA1_Update(arg0+0x2ec,data_020fb054,4);
else SHA1_Update(arg0+0x2ec,data_020fb05c,4);
SHA1_Update(arg0+0x2ec,arg0,0x30);
MI_CpuFill8(sp0,0x36,0x28);
SHA1_Update(arg0+0x2ec,sp0,0x28);
SHA1_Final(arg0+0x2ec,arg1);
SHA1_Init(arg0+0x2ec);
SHA1_Update(arg0+0x2ec,arg0,0x30);
MI_CpuFill8(sp0,0x5c,0x28);
SHA1_Update(arg0+0x2ec,sp0,0x28);
SHA1_Update(arg0+0x2ec,arg1,0x14);
SHA1_Final(arg0+0x2ec,arg1);
}

void TlsProcessFinished(void *p,void *q) {
 M2C_UNK MI_CpuCopy8(s32,s32,u32);
 M2C_UNK TlsComputeFinishedMd5(void *,void *,s32);
 M2C_UNK TlsComputeFinishedSha1(void *,void *,s32);
 s32 ByteCompareN(void *,void *,s32);
 u8 buf[20];
 MI_CpuCopy8((s32)p+0x3A4,(s32)p+0x3FC,0x58);
 TlsComputeFinishedMd5(p,buf,1);
 MI_CpuCopy8((s32)p+0x3FC,(s32)p+0x3A4,0x58);
 if(ByteCompareN(q,buf,16)) { M2C_FIELD(p,s8 *,0x455)=9;return;}
 MI_CpuCopy8((s32)p+0x2EC,(s32)p+0x348,0x5C);
 TlsComputeFinishedSha1(p,buf,1);
 MI_CpuCopy8((s32)p+0x348,(s32)p+0x2EC,0x5C);
 if(ByteCompareN(q+16,buf,20)) M2C_FIELD(p,s8 *,0x455)=9;
 else M2C_FIELD(p,s8 *,0x455)=6;
}

void IncrementBe64(u8 *arg0) {
    s32 var_r2;
    u8 *var_r0;
    u8 temp_r1;

    var_r0 = arg0;
    var_r2 = 8;
loop_1:
    var_r0 -= 1;
    temp_r1 = *var_r0 + 1;
    *var_r0 = temp_r1;
    if (temp_r1 != 0) {
        return;
    }
    var_r2 -= 1;
    if (var_r2 == 0) {
        return;
    }
    goto loop_1;
}

s32 func_020237bc(s32 x,s32 unused,s32 value) {
 M2C_UNK RC4_Crypt(s32);
 RC4_Crypt(x+0x1E0);return value;
}

/* Verifies the digest of a message received on a comm channel: the payload is already RC4-decrypted by func_020237bc, then the channel's MD5 (type 4, ctx +0x3FC) or SHA1 (type 5, ctx +0x348) is run twice - key+pad, then key+pad+counter+message - and the result compared with the digest stored at the end of the payload. On mismatch the channel state (+0x455) becomes 9; the channel counter (+0x2EC) is bumped and the message length without the digest is returned. */
s32 TlsVerifyRecordMac(void *channel, u8 *msg) {
    M2C_UNK MI_CpuFill8();
    M2C_UNK MD5_Init();
    M2C_UNK MD5_Update();
    M2C_UNK MD5_Final();
    M2C_UNK SHA1_Init();
    M2C_UNK SHA1_Update();
    M2C_UNK SHA1_Final();
    M2C_UNK RC4_Crypt();
    u8 digest[20];
    u8 pad[0x30];
    s32 dataLen;
    s32 digestSize;
    u16 temp_r0;

    dataLen = func_020237bc((s32)channel,(s32)(msg+5),(msg[3] << 8) + msg[4]);
    switch (*(u16 *)((u8 *)channel + 0x32)) {
    case 4:
        dataLen -= 16;
        msg[3]=dataLen>>8;msg[4]=dataLen;
        MD5_Init(channel + 0x3FC);
        MD5_Update(channel + 0x3FC, *(void **)((u8 *)channel + 0x1D4), 0x10);
        MI_CpuFill8(pad, 0x36, 0x30);
        MD5_Update(channel + 0x3FC, pad, 0x30);
        MD5_Update(channel + 0x3FC, channel + 0x2E4, 8);
        MD5_Update(channel + 0x3FC, msg, 1);
        MD5_Update(channel + 0x3FC, msg + 3, dataLen + 2);
        MD5_Final(channel + 0x3FC, digest);
        MD5_Init(channel + 0x3FC);
        MD5_Update(channel + 0x3FC, *(void **)((u8 *)channel + 0x1D4), 0x10);
        MI_CpuFill8(pad, 0x5C, 0x30);
        MD5_Update(channel + 0x3FC, pad, 0x30);
        MD5_Update(channel + 0x3FC, digest, 0x10);
        MD5_Final(channel + 0x3FC, digest);
        digestSize=16;
        break;
    case 5:
        dataLen -= 20;
        msg[3]=dataLen>>8;msg[4]=dataLen;
        SHA1_Init(channel + 0x348);
        SHA1_Update(channel + 0x348, *(void **)((u8 *)channel + 0x1D4), 0x14);
        MI_CpuFill8(pad, 0x36, 0x28);
        SHA1_Update(channel + 0x348, pad, 0x28);
        SHA1_Update(channel + 0x348, channel + 0x2E4, 8);
        SHA1_Update(channel + 0x348, msg, 1);
        SHA1_Update(channel + 0x348, msg + 3, dataLen + 2);
        SHA1_Final(channel + 0x348, digest);
        SHA1_Init(channel + 0x348);
        SHA1_Update(channel + 0x348, *(void **)((u8 *)channel + 0x1D4), 0x14);
        MI_CpuFill8(pad, 0x5C, 0x28);
        SHA1_Update(channel + 0x348, pad, 0x28);
        SHA1_Update(channel + 0x348, digest, 0x14);
        SHA1_Final(channel + 0x348, digest);
        digestSize=20;
        break;
    }
    if(ByteCompareN(msg+5+dataLen,digest,digestSize))M2C_FIELD(channel,u8*,0x455)=9;
    IncrementBe64(channel+0x2EC);
    return dataLen+5;
}

/* Appends the HMAC of a TLS record to its payload: runs the keyed MD5 (hash
 * algorithm 4) or SHA1 (5) over the record and writes the digest after the
 * current payload, then updates the record length, RC4-encrypts the record and
 * bumps the outgoing sequence number. Returns the record length. */
s32 TlsAppendRecordMac(void *channel, u8 *msg) {
    M2C_UNK MI_CpuFill8();
    M2C_UNK MD5_Init();
    M2C_UNK MD5_Update();
    M2C_UNK MD5_Final();
    M2C_UNK SHA1_Init();
    M2C_UNK SHA1_Update();
    M2C_UNK SHA1_Final();
    M2C_UNK RC4_Crypt();
    u8 pad[0x30];
    void *payload;
    s32 length;
    u16 hashAlgorithm;

    hashAlgorithm = *(u16 *)((u8 *)channel + TLS_HASH_ALGORITHM);
    payload = msg + 5;
    length = (msg[3] << 8) + msg[4];
    switch (hashAlgorithm) {
    case TLS_HASH_MD5:
        MD5_Init(channel + TLS_MD5_CTX);
        MD5_Update(channel + TLS_MD5_CTX, *(void **)((u8 *)channel + TLS_MAC_KEY_OUT), 0x10);
        MI_CpuFill8(pad, TLS_HMAC_IPAD, 0x30);
        MD5_Update(channel + TLS_MD5_CTX, pad, 0x30);
        MD5_Update(channel + TLS_MD5_CTX, channel + TLS_SEQ_OUT, 8);
        MD5_Update(channel + TLS_MD5_CTX, msg, 1);
        MD5_Update(channel + TLS_MD5_CTX, msg + 3, length + 2);
        MD5_Final(channel + TLS_MD5_CTX, (u8 *)payload + length);
        MD5_Init(channel + TLS_MD5_CTX);
        MD5_Update(channel + TLS_MD5_CTX, *(void **)((u8 *)channel + TLS_MAC_KEY_OUT), 0x10);
        MI_CpuFill8(pad, TLS_HMAC_OPAD, 0x30);
        MD5_Update(channel + TLS_MD5_CTX, pad, 0x30);
        MD5_Update(channel + TLS_MD5_CTX, (u8 *)payload + length, 0x10);
        MD5_Final(channel + TLS_MD5_CTX, (u8 *)payload + length);
        length += 0x10;
        break;
    case TLS_HASH_SHA1:
        SHA1_Init(channel + TLS_SHA1_CTX);
        SHA1_Update(channel + TLS_SHA1_CTX, *(void **)((u8 *)channel + TLS_MAC_KEY_OUT), 0x14);
        MI_CpuFill8(pad, TLS_HMAC_IPAD, 0x28);
        SHA1_Update(channel + TLS_SHA1_CTX, pad, 0x28);
        SHA1_Update(channel + TLS_SHA1_CTX, channel + TLS_SEQ_OUT, 8);
        SHA1_Update(channel + TLS_SHA1_CTX, msg, 1);
        SHA1_Update(channel + TLS_SHA1_CTX, msg + 3, length + 2);
        SHA1_Final(channel + TLS_SHA1_CTX, (u8 *)payload + length);
        SHA1_Init(channel + TLS_SHA1_CTX);
        SHA1_Update(channel + TLS_SHA1_CTX, *(void **)((u8 *)channel + TLS_MAC_KEY_OUT), 0x14);
        MI_CpuFill8(pad, TLS_HMAC_OPAD, 0x28);
        SHA1_Update(channel + TLS_SHA1_CTX, pad, 0x28);
        SHA1_Update(channel + TLS_SHA1_CTX, (u8 *)payload + length, 0x14);
        SHA1_Final(channel + TLS_SHA1_CTX, (u8 *)payload + length);
        length += 0x14;
        break;
    }
    msg[3] = (u8)(length >> 8);
    msg[4] = (u8)length;
    RC4_Crypt(channel + TLS_RC4_OUT, msg + 5, length);
    IncrementBe64(channel + TLS_SEQ_OUT + 8);
    return length + 5;
}

s32 ReceiveExactBytes(s32 arg0, u32 arg1, M2C_UNK arg2) {
    M2C_UNK MI_CpuCopy8(s32, s32, u32);
    s32 PeekReceivedData(u32 *, M2C_UNK);
    M2C_UNK ConsumeReceivedData(u32, M2C_UNK);
    u32 sp0;
    s32 temp_r0;
    s32 var_r7;
    u32 var_r6;

    var_r7 = arg0;
    var_r6 = arg1;
loop_1:
    temp_r0 = PeekReceivedData(&sp0, arg2);
    if (sp0 == 0) {
        return -1;
    }
    if (sp0 > var_r6) {
        sp0 = var_r6;
    }
    MI_CpuCopy8(temp_r0, var_r7, sp0);
    ConsumeReceivedData(sp0, arg2);
    var_r6 -= sp0;
    var_r7 += sp0;
    if ((s32) var_r6 <= 0) {
        return 0;
    }
    goto loop_1;
}

void TlsUpdateHandshakeHash(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK MD5_Update(s32, M2C_UNK, M2C_UNK);
    M2C_UNK SHA1_Update();
    SHA1_Update(arg0 + 0x2EC);
    MD5_Update(arg0 + 0x3A4, arg1, arg2);
}

/* Dispatches one record buffer received on a TLS connection: decrypts it if the
 * handshake already switched ciphers, then handles change-cipher-spec, alert,
 * handshake and application-data records.  The buffer is freed unless it is an
 * application-data record kept for the caller. */
void TlsProcessRecord(void *channel, void *msg) {
 M2C_UNK MI_CpuFill8(void *,s32,s32);
 M2C_UNK TlsProcessCertificate(void *,void *);
 M2C_UNK TlsProcessServerHello(void *,void *);
 M2C_UNK TlsProcessClientHello(void *,void *);
 
 extern void (*gFree[])(void *);
 u8 *payload; u32 remaining; s32 length; u8 state,contentType;
 state=M2C_FIELD(channel,u8 *,TLS_STATE);
 if(state==TLS_STATE_ERROR){gFree[0](msg);return;}
 remaining=(M2C_FIELD(msg,u8 *,3)<<8)+M2C_FIELD(msg,u8 *,4)+TLS_RECORD_HEADER;
 contentType=M2C_FIELD(msg,u8 *,0);
 if(((u8)(state+249)<=1 && contentType!=21)||(contentType==21 && remaining>7)){
 remaining=TlsVerifyRecordMac(channel,msg); state=M2C_FIELD(channel,u8 *,TLS_STATE);
 if(state==TLS_STATE_ERROR){gFree[0](msg);return;}
 }
 payload=(u8 *)msg+TLS_RECORD_HEADER;remaining-=TLS_RECORD_HEADER;
 switch(contentType){
 case 20:
 if(M2C_FIELD(channel,s32 *,TLS_MAC_KEY_IN)==0) M2C_FIELD(channel,u8 *,TLS_STATE)=TLS_STATE_ERROR;
 else {MI_CpuFill8(channel+TLS_SEQ_IN,0,8);M2C_FIELD(channel,u8 *,TLS_STATE)=7;}
 break;
 case 21: if(payload[0]==2)M2C_FIELD(channel,u8 *,TLS_STATE)=TLS_STATE_ERROR;break;
 case 22:
 do{
 s32 handshakeType=payload[0];
 length=((payload[1]<<16)+(payload[2]<<8))+payload[3];payload+=4;
 switch(handshakeType){
 case 1: if(M2C_FIELD(channel,u8 *,TLS_SERVER_SIDE)!=0 && state==0)TlsProcessClientHello(channel,payload);break;
 case 16:TlsProcessClientKeyExchange(channel,(M2C_UNK)payload);break;
 case 2:TlsProcessServerHello(channel,payload);break;
 case 11:TlsProcessCertificate(channel,payload);M2C_FIELD(channel,u8 *,TLS_CLIENT_CERT_REQUESTED)=0;break;
 case 13:M2C_FIELD(channel,u8 *,TLS_CLIENT_CERT_REQUESTED)=1;break;
 case 14:M2C_FIELD(channel,u8 *,TLS_STATE)=4;break;
 case 20:TlsProcessFinished(channel,(M2C_UNK)payload);break;
 default:M2C_FIELD(channel,u8 *,TLS_STATE)=TLS_STATE_ERROR;break;
 }
 TlsUpdateHandshakeHash(channel,payload-4,length+4);payload+=length;remaining-=length+4;
 if(remaining==0)break;
 state=M2C_FIELD(channel,u8 *,TLS_STATE);
 }while(state!=TLS_STATE_ERROR);
 break;
 case 23:
 M2C_FIELD(channel,void **,TLS_PENDING_RECORD)=msg;
 M2C_FIELD(channel,s32 *,TLS_PENDING_READ)=TLS_RECORD_HEADER;
 M2C_FIELD(channel,u32 *,TLS_PENDING_SIZE)=remaining+TLS_RECORD_HEADER;
 M2C_FIELD(channel,u8 *,TLS_PENDING_KEEP)=1;return;
 default:M2C_FIELD(channel,u8 *,TLS_STATE)=TLS_STATE_ERROR;break;
 }
 gFree[0](msg);
}

/* Reads one record from a connection's transport and processes it: an
 * SSLv2-format client hello at handshake start fills the client random, any
 * other record is read in full and dispatched by content type.  Returns the
 * resulting TLS state. */
s32 TlsReadRecord(void *transport) {
    M2C_UNK PeekReceivedData(u32 *, M2C_UNK);
    M2C_UNK ConsumeReceivedData(u32, M2C_UNK);
    void TlsProcessClientHelloSslV2(u8 *, u8 *);
    void TlsProcessRecord(void *, void *);
    extern void *(*gAlloc)(s32);
    extern void (*gFree[])(void *);
    void *channel;
    u8 *chunk;
    u8 *record;
    u32 size;

    channel = M2C_FIELD(transport, void **, 0xC);
    for (;;) {
        chunk = (u8 *)PeekReceivedData(&size, transport);
        if (size == 0) {
            M2C_FIELD(channel, u8 *, TLS_STATE) = TLS_STATE_ERROR;
            return TLS_STATE_ERROR;
        }
        if (size >= TLS_RECORD_HEADER) {
            break;
        }
    }
    if (chunk[0] == 0x80) {
        if (M2C_FIELD(channel, u8 *, TLS_SERVER_SIDE) != 0 && M2C_FIELD(channel, u8 *, TLS_STATE) == 0) {
            size = chunk[1];
            ConsumeReceivedData(2, transport);
            record = (u8 *)gAlloc(size);
            if (record == 0) {
                M2C_FIELD(channel, u8 *, TLS_STATE) = TLS_STATE_ERROR;
                return TLS_STATE_ERROR;
            }
            if (ReceiveExactBytes((s32)record, size, transport) != 0 || record[0] != 1) {
                M2C_FIELD(channel, u8 *, TLS_STATE) = TLS_STATE_ERROR;
            } else {
                TlsProcessClientHelloSslV2(channel, record + 1);
            }
            TlsUpdateHandshakeHash(channel, record, size);
            gFree[0](record);
        } else {
            M2C_FIELD(channel, u8 *, TLS_STATE) = TLS_STATE_ERROR;
        }
    } else {
        size = (chunk[3] << 8) + chunk[4] + TLS_RECORD_HEADER;
        if (size > TLS_MAX_RECORD + TLS_RECORD_HEADER) {
            M2C_FIELD(channel, u8 *, TLS_STATE) = TLS_STATE_ERROR;
            return TLS_STATE_ERROR;
        }
        record = (u8 *)gAlloc(size);
        if (record == 0) {
            M2C_FIELD(channel, u8 *, TLS_STATE) = TLS_STATE_ERROR;
            return TLS_STATE_ERROR;
        }
        if (ReceiveExactBytes((s32)record, size, transport) != 0) {
            gFree[0](record);
            M2C_FIELD(channel, u8 *, TLS_STATE) = TLS_STATE_ERROR;
            return TLS_STATE_ERROR;
        }
        TlsProcessRecord(channel, record);
    }
    return M2C_FIELD(channel, u8 *, TLS_STATE);
}

/* Generates len bytes of cryptographically mixed random data: the 20-byte SHA1
 * entropy pool is re-hashed (with interrupts disabled) whenever the current
 * digest runs out, the new digest is folded back into the pool with a
 * big-endian carry add, and zero bytes are skipped so the stream never stalls.
 * On first use the pool is seeded from a 64-bit multiply-add state. */
void GenerateRandomBytes(u8 *dst,s32 len){
M2C_UNK SHA1_Init(void*);s32 OS_DisableInterrupts(void);M2C_UNK OS_RestoreInterrupts(s32);M2C_UNK SHA1_Update();void func_02026134(void*,void*);void Random_AddEntropy(M2C_UNK*,s32);
extern s8 gTlsRandomState;extern u64 gRandomSeedState[3];extern M2C_UNK gRandomEntropyPool;extern u8 gRandomEntropyPoolEnd;
u8 sha1Ctx[92],digest[20];u32 seed; s32 written,index,irq,j;u32 carry,total;u8 *poolPtr,*digestPtr;
if(!*(u8*)&gTlsRandomState){gRandomSeedState[0]=gRandomSeedState[1]*gRandomSeedState[0]+gRandomSeedState[2];seed=gRandomSeedState[0]>>32;Random_AddEntropy((M2C_UNK*)&seed,4);}
written=0;index=20;
while(written<len){
if(index==20){
SHA1_Init(sha1Ctx);irq=OS_DisableInterrupts();SHA1_Update(sha1Ctx,&gRandomEntropyPool,20);func_02026134(sha1Ctx,digest);
carry=1;j=19;poolPtr=&gRandomEntropyPoolEnd;digestPtr=digest+19;
for(;j>=0;j--){total=carry+(*poolPtr+*digestPtr--);*poolPtr--=total;carry=total>>8;}
seed=total;OS_RestoreInterrupts(irq);index=0;
}
{u8 c=digest[index++];if(c)dst[written++]=c;}
}
}

void Random_AddEntropy(M2C_UNK *p,s32 n) {
 s32 OS_DisableInterrupts(void);
 M2C_UNK OS_RestoreInterrupts(s32);
 M2C_UNK SHA1_Init(void *);
 M2C_UNK SHA1_Update();
 M2C_UNK SHA1_Final(void *,void *);
 extern s8 gTlsRandomState;
 extern M2C_UNK gRandomEntropyPool;
 u8 buf[0x5C];
 s32 state;
 SHA1_Init(buf);
 state=OS_DisableInterrupts();
 SHA1_Update(buf,&gRandomEntropyPool,20);
 SHA1_Update(buf,p,n);
 SHA1_Final(buf,&gRandomEntropyPool);
 OS_RestoreInterrupts(state);
 gTlsRandomState=1;
}

