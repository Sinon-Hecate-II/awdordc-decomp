/* 23 functions from 0x02049AB8 to 0x0204AA34 (main), found by ds-decomp. */
#include "common.h"
#include "ghttp.h"

/* Encode len bytes of src as base64 into dst (NUL-terminated), using the alphabet
   selected by mode: 1 = "[]_", 2 = URL-safe "-_", anything else = standard "+/". */
void Base64Encode(u8 *src,s8 *dst,s32 len,s32 mode){
void Base64PackGroup(u8 *,s8 *,s32);
extern const s8 gBase64AlphabetBracket[],gBase64AlphabetUrlSafe[],gBase64AlphabetStandard[];
const s8 *alphabet; s8 *start=dst,*pad; s32 left=len,rem;
switch(mode){case 1:alphabet=gBase64AlphabetBracket;break;case 2:alphabet=gBase64AlphabetUrlSafe;break;default:alphabet=gBase64AlphabetStandard;break;}
while(left>0){Base64PackGroup(src,dst,left<3?left:3);left-=3;dst+=4;src+=3;}
rem=len%3;pad=dst;
if(rem==1)pad=dst-2;else if(rem==2)pad=dst-1;
*dst=0;
while(dst>start){
--dst;
if(dst>=pad)*dst=alphabet[2];
else if(*dst<=25)*dst+=65;
else if(*dst<=51)*dst+=71;
else if(*dst<=61)*dst-=4;
else if(*dst==62)*dst=alphabet[0];
else if(*dst==63)*dst=alphabet[1];
}
}

s32 ghiResizeBuffer(s32 *p,s32 n) {
s32 gpiRealloc(s32,s32);
extern M2C_UNK sAssertBuffer,gGhttpBufferFileName,data_020fce58,sAssertSizeIncrement;
s32 v,total;
if(!p)AssertFailed(&sAssertBuffer,&gGhttpBufferFileName,&data_020fce58,0x20);
if(n<=0)AssertFailed(&sAssertSizeIncrement,&gGhttpBufferFileName,&data_020fce58,0x21);
if(!p)return 0;
if(n<=0)return 0;
total=p[2];total+=n;
v=gpiRealloc(p[1],total);
if(!v)return 0;
p[1]=v;p[2]=total;return 1;
}

/* Initialise a GHIBuffer: record the owning connection and grow step, clear
   the remaining fields, allocate the initial storage and start it empty. */
s32 ghiInitBuffer(void *connection,GHIBuffer *buffer,s32 initialSize,s32 sizeIncrement) {
extern M2C_UNK sAssertConnection,gGhttpBufferFileName,gGhiInitBufferName,sAssertBuffer,sAssertInitialSize,sAssertSizeIncrement;
if(!connection)AssertFailed(&sAssertConnection,&gGhttpBufferFileName,&gGhiInitBufferName,0x43);
if(!buffer)AssertFailed(&sAssertBuffer,&gGhttpBufferFileName,&gGhiInitBufferName,0x44);
if(initialSize<=0)AssertFailed(&sAssertInitialSize,&gGhttpBufferFileName,&gGhiInitBufferName,0x45);
if(sizeIncrement<=0)AssertFailed(&sAssertSizeIncrement,&gGhttpBufferFileName,&gGhiInitBufferName,0x46);
if(!connection)return 0;
if(!buffer)return 0;
if(initialSize<=0)return 0;
if(sizeIncrement<=0)return 0;
buffer->connection=connection;
buffer->data=0;buffer->size=0;buffer->len=0;buffer->pos=0;buffer->sizeIncrement=sizeIncrement;buffer->fixed=0;buffer->dontFree=0;buffer->encrypted=0;
if(!ghiResizeBuffer((s32 *)buffer,initialSize))return 0;
*(u8 *)buffer->data=0;return 1;
}

/* Initialize a fixed-size buffer wrapper with a connection, user storage and capacity. */
s32 ghiInitFixedBuffer(void *connection, s32 *buffer, void *userBuffer, s32 size) {
    extern M2C_UNK sAssertConnection, gGhttpBufferFileName, data_020fce68, sAssertBuffer, data_020fcf0c, data_020fcf18;
    if (!connection) AssertFailed(&sAssertConnection, &gGhttpBufferFileName, &data_020fce68, 0x74);
    if (!buffer) AssertFailed(&sAssertBuffer, &gGhttpBufferFileName, &data_020fce68, 0x75);
    if (!userBuffer) AssertFailed(&data_020fcf0c, &gGhttpBufferFileName, &data_020fce68, 0x76);
    if (size <= 0) AssertFailed(&data_020fcf18, &gGhttpBufferFileName, &data_020fce68, 0x77);
    if (!connection) return 0;
    if (!buffer) return 0;
    if (!userBuffer) return 0;
    if (size <= 0) return 0;
    buffer[0] = (s32)connection;
    buffer[1] = (s32)userBuffer;
    buffer[2] = size;
    buffer[3] = 0;
    buffer[5] = 0;
    buffer[6] = 1;
    buffer[7] = 1;
    buffer[8] = 0;
    *(u8 *)buffer[1] = 0;
    return 1;
}

void ghiFreeBuffer(s32 *p) {
void gpiFree(s32);
extern M2C_UNK sAssertBuffer,gGhttpBufferFileName,data_020fce28;
if(!p)AssertFailed(&sAssertBuffer,&gGhttpBufferFileName,&data_020fce28,0x9b);
if(!p || !p[1])return;
if(!p[7])gpiFree(p[1]);
MemSet(p,0,0x24);
}

/* Append data to a GHIBuffer, growing it if needed; when the buffer is encrypted
   the data is passed through the connection's encryptor first. */
s32 ghiAppendDataToBuffer(s32 arg0, s32 *arg1, s32 dataLen, ...) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    s32 StringLength(s32);
    s32 ghiResizeBuffer(s32 *, s32);
    void MemCopy(void *, void *, s32);
    extern M2C_UNK sAssertBuffer;
    extern M2C_UNK gGhttpBufferFileName;
    extern M2C_UNK data_020fce94;
    extern M2C_UNK data_020fcf24;
    extern M2C_UNK data_020fcf2c;
    extern M2C_UNK data_020fcf3c;
    GHIBuffer *buffer = (GHIBuffer *)arg0;
    const u8 *data = (const u8 *)arg1;
    void *connection = buffer->connection;
    typedef s32 (*Cb)(void *, void *, void *, s32 *, s32, s32 *);

    if (buffer == 0) AssertFailed(&sAssertBuffer, &gGhttpBufferFileName, &data_020fce94, 0xb7);
    if (data == 0) AssertFailed(&data_020fcf24, &gGhttpBufferFileName, &data_020fce94, 0xb8);
    if (dataLen < 0) AssertFailed(&data_020fcf2c, &gGhttpBufferFileName, &data_020fce94, 0xb9);
    if (buffer == 0) return 0;
    if (data == 0) return 0;
    if (dataLen < 0) return 0;

    if (dataLen == 0) {
        dataLen = StringLength((s32)data);
    }

    if (buffer->encrypted == 1) {
        s32 result;
        s32 room;
        if (M2C_FIELD(connection, s32 *, 0x168) == 0) {
            AssertFailed(&data_020fcf3c, &gGhttpBufferFileName, &data_020fce94, 0xce);
        }
        do {
            u8 *dest;
            room = buffer->size - buffer->len;
            dest = buffer->data + buffer->len;
            {
                Cb cb = *(Cb *)((char *)connection + 0x17c);
                result = cb(connection, (char *)connection + 0x164, (void *)data, &dataLen, (s32)dest, &room);
            }
            if (result == 2) {
                if (buffer->fixed != 0) {
                    M2C_FIELD(buffer->connection, s32 *, 0xfc) = 1;
                    M2C_FIELD(buffer->connection, s32 *, 0x38) = 2;
                    return 0;
                }
                if (ghiResizeBuffer((s32 *)buffer, buffer->sizeIncrement) != 0) {
                    M2C_FIELD(buffer->connection, s32 *, 0xfc) = 1;
                    M2C_FIELD(buffer->connection, s32 *, 0x38) = 1;
                    return 0;
                }
                continue;
            }
            buffer->len += room;
        } while (result == 2);
    } else {
        s32 newLen = buffer->len + dataLen;
        while (newLen >= buffer->size) {
            if (buffer->fixed != 0) {
                M2C_FIELD(buffer->connection, s32 *, 0xfc) = 1;
                M2C_FIELD(buffer->connection, s32 *, 0x38) = 2;
                return 0;
            }
            if (ghiResizeBuffer((s32 *)buffer, buffer->sizeIncrement) == 0) {
                M2C_FIELD(buffer->connection, s32 *, 0xfc) = 1;
                M2C_FIELD(buffer->connection, s32 *, 0x38) = 1;
                return 0;
            }
        }
        MemCopy((void *)(buffer->data + buffer->len), (void *)data, dataLen);
        buffer->len = newLen;
        buffer->data[newLen] = 0;
    }
    return 1;
}

s32 AppendHttpHeader(M2C_UNK arg0, M2C_UNK *arg1, M2C_UNK *arg2) {
    s32 ghiAppendDataToBuffer(M2C_UNK, M2C_UNK *, M2C_UNK,...);
    extern M2C_UNK data_020fcf78;
    extern M2C_UNK data_020fcf7c;
    if (ghiAppendDataToBuffer(arg0, arg1, 0) == 0) {
        return 0;
    }
    if (ghiAppendDataToBuffer(arg0, &data_020fcf78, 2) == 0) {
        return 0;
    }
    if (ghiAppendDataToBuffer(arg0, arg2, 0) == 0) {
        return 0;
    }
    if (ghiAppendDataToBuffer(arg0, &data_020fcf7c, 2) != 0) {
        return 1;
    }
    return 0;
}

s32 AppendChar(s32 p,s32 c) {
s32 ghiAppendDataToBuffer(s32,s32 *,s32,...);
extern M2C_UNK sAssertBuffer,gGhttpBufferFileName,data_020fce7c;
u8 v=c;
if(!p)AssertFailed(&sAssertBuffer,&gGhttpBufferFileName,&data_020fce7c,0x131);
if(!p)return 0;
return ghiAppendDataToBuffer(p,(s32 *)&v,1);
}

void AppendInt(s32 a,s32 b) {
void StringFormat(void *,void *,s32);
s32 ghiAppendDataToBuffer(s32,s32 *,s32,...);
extern M2C_UNK data_020fcf80;
s32 buf[4];
StringFormat(buf,&data_020fcf80,b);
ghiAppendDataToBuffer(a,buf,0);
}

void ResetBuffer(void *arg0) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fce48;
    extern M2C_UNK sAssertBuffer;
    extern M2C_UNK gGhttpBufferFileName;
    if (arg0 == NULL) {
        AssertFailed(&sAssertBuffer, &gGhttpBufferFileName, &data_020fce48, 0x16C);
    }
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    *M2C_FIELD(arg0, s8 **, 4) = 0;
}

/* Send the rest of a connection's request buffer: poll the socket until it is
 * writable, write the bytes from the buffer's read position to its end and
 * advance that position; a poll or send failure is saved as a socket error. */
s32 SendBufferedData(void *connection) {
    s32 PollOneFd(s32, M2C_UNK, s32 *, s32 *);
    s32 writable;
    s32 error;
    s32 sent;
    s32 pos;
    s32 newPos;

loop_1:
    if ((PollOneFd(M2C_FIELD(connection, s32 *, 0x48), 0, &writable, &error) == -1) || (error != 0)) {
        M2C_FIELD(connection, s32 *, GHI_COMPLETED) = 1;
        M2C_FIELD(connection, s32 *, GHI_RESULT) = GHTTP_RESULT_SOCKET_FAILED;
        M2C_FIELD(connection, s32 *, 0x4C) = ghiGetLastSocketError(M2C_FIELD(connection, s32 *, 0x48));
        return 0;
    }
    if (writable == 0) {
        return 1;
    }
    pos = M2C_FIELD(connection, s32 *, GHI_BUFFER_POS);
    sent = ghiSocketSend(connection, M2C_FIELD(connection, s32 *, GHI_BUFFER_DATA) + pos, M2C_FIELD(connection, s32 *, GHI_BUFFER_LEN) - pos);
    if (sent == -1) {
        return 0;
    }
    newPos = M2C_FIELD(connection, s32 *, GHI_BUFFER_POS) + sent;
    M2C_FIELD(connection, s32 *, GHI_BUFFER_POS) = newPos;
    if (newPos >= (s32) M2C_FIELD(connection, s32 *, GHI_BUFFER_LEN)) {
        return 1;
    }
    goto loop_1;
}

/* ghttp ghiReadBuffer: copy up to *bufferLen unread bytes out of a GHIBuffer
 * (as a NUL-terminated string), store the count actually copied back in
 * *bufferLen and advance the buffer's read position. Returns 1 when bytes were
 * copied, 0 when nothing was requested or nothing is left. */
s32 ghiReadBuffer(s32 *bufferIn, u8 *bufferOut, s32 *bufferLen) {
    extern M2C_UNK sAssertBufferInNotNull, gGhttpBufferFileName, sGhttpBufferFuncName, sAssertLenNotNull;
    s32 bytes, bytesLeft;
    if (!bufferIn) AssertFailed(&sAssertBufferInNotNull, &gGhttpBufferFileName, &sGhttpBufferFuncName, 0x1b7);
    if (!bufferLen) AssertFailed(&sAssertLenNotNull, &gGhttpBufferFileName, &sGhttpBufferFuncName, 0x1b8);
    bytes = *bufferLen;
    if (!bytes) return 0;
    bytesLeft = bufferIn[3] - bufferIn[4]; /* len - pos */
    if (bytesLeft <= 0) return 0;
    if (bytes >= bytesLeft) bytes = bytesLeft;
    MemCopy(bufferOut, (void *)(bufferIn[1] + bufferIn[4]), bytes); /* data + pos */
    bufferOut[bytes] = 0; *bufferLen = bytes; bufferIn[4] += bytes; return 1;
}

void func_0204a498(void *p) {
extern M2C_UNK data_020fcfec,data_020fcff8,data_020fcfd0;
s32 a,b,r;
if(!p)AssertFailed(&data_020fcfec,&data_020fcff8,&data_020fcfd0,0x1b);
if(!M2C_FIELD(p,s32 (**)(s32,s32,s32,s32,s32),0x40))return;
if(M2C_FIELD(p,s32 *,12)){a=0;b=0;}else{a=M2C_FIELD(p,s32 *,0xc0);b=M2C_FIELD(p,s32 *,0x100);}
r=M2C_FIELD(p,s32 (**)(s32,s32,s32,s32,s32),0x40)(M2C_FIELD(p,s32 *,4),M2C_FIELD(p,s32 *,0x38),a,b,M2C_FIELD(p,s32 *,0x44));
if(a && !r)M2C_FIELD(p,s32 *,0xd8)=1;
}

void InvokeRequestCallback(void *p,s32 a,s32 b) {
extern M2C_UNK data_020fcfec,data_020fcff8,data_020fcfb8;
if(!p)AssertFailed(&data_020fcfec,&data_020fcff8,&data_020fcfb8,0x45);
if(!M2C_FIELD(p,s32 (**)(s32,s32,s32,s32,s32,s32,s32),0x3c))return;
M2C_FIELD(p,s32 (**)(s32,s32,s32,s32,s32,s32,s32),0x3c)(M2C_FIELD(p,s32 *,4),M2C_FIELD(p,s32 *,0x10),a,b,M2C_FIELD(p,s32 *,0x100),M2C_FIELD(p,s32 *,0x104),M2C_FIELD(p,s32 *,0x44));
}

void ghiCallPostCallback(void *arg0) {
    s32 Vector_GetCount(s32);
    extern M2C_UNK data_020fcfa4;
    extern M2C_UNK data_020fcfec;
    extern M2C_UNK data_020fcff8;
    if (arg0 == NULL) {
        AssertFailed(&data_020fcfec, &data_020fcff8, &data_020fcfa4, 0x5E);
    }
    if (M2C_FIELD(arg0, M2C_UNK (**)(s32, s32, s32, s32, s32, s32), 0x150) == NULL) {
        return;
    }
    M2C_FIELD(arg0, M2C_UNK (**)(s32, s32, s32, s32, s32, s32), 0x150)(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x14C), M2C_FIELD(arg0, s32 *, 0x144), Vector_GetCount(M2C_FIELD(arg0, s32 *, 0x140)), M2C_FIELD(arg0, s32 *, 0x44));
}

void func_0204a608(void) {

}

void func_0204a60c(void) {

}

void ghiLockMutex(void) {

}

void ghiUnlockMutex(void) {

}

/* Run the connection's decryptor over the ciphertext left unread in the decrypt
 * buffer, appending the plaintext to the read buffer.  When the decryptor fills
 * the read buffer it is grown and the decrypt is retried; once most of the
 * decrypt buffer has been consumed it is compacted.  Returns 0 on failure. */
s32 ghiDecryptBuffer(GHIConnection *conn) {
M2C_UNK MemMove(s32,s32,s32);
s32 inBytes; s32 outBytes; s32 decryptPos,readLen,result,used,remaining,data,inPtr,outPtr;
inBytes=0; outBytes=0;
loop:
decryptPos=conn->decryptBuffer.pos;
inPtr=(s32)conn->decryptBuffer.data;
inBytes=conn->decryptBuffer.len-decryptPos;
readLen=conn->readBuffer.len;
outPtr=(s32)conn->readBuffer.data;
outBytes=conn->readBuffer.size-readLen;
result=conn->decryptor(conn,conn->encryptorState,inPtr+decryptPos,&inBytes,outPtr+readLen,&outBytes);
if(result==GHI_DECRYPT_OUTPUT && !ghiResizeBuffer((s32 *)&conn->readBuffer,conn->readBuffer.sizeIncrement))return 0;
if(result==GHI_DECRYPT_OUTPUT && outBytes==0)goto loop;
conn->decryptBuffer.pos+=inBytes;
conn->readBuffer.len+=outBytes;
used=conn->decryptBuffer.pos;
if(used>255){
remaining=conn->decryptBuffer.len-used;
if(!remaining)ResetBuffer(&conn->decryptBuffer);
else {
data=(s32)conn->decryptBuffer.data;
MemMove(data,data+used,remaining);
conn->decryptBuffer.pos=0;
conn->decryptBuffer.len=remaining;
}
}
if(result!=GHI_DECRYPT_ERROR)return 1;
conn->completed=1;
conn->result=17;
return 0;
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
s32 ghiReceiveData(void *p,u8 *dst,s32 *len) {
u32 GetTickCountMs(void);
s32 ghiAppendDataToBuffer(s32,s32 *,s32,...);
s32 ghiRecv(s32,u8 *,s32,s32);

extern s32 gGhiRecvTimeoutMs[];
s32 r; s32 err; s32 n; u32 now; register s32 got; register s32 out;
n=*len-1;
if(M2C_FIELD(p,s32 *,0x134)){
now=GetTickCountMs();
if(now<M2C_FIELD(p,u32 *,0x138)+gGhiRecvTimeoutMs[0])return 1;
M2C_FIELD(p,u32 *,0x138)=now;
if(n>=gGhiRecvTimeoutMs[1])n=gGhiRecvTimeoutMs[1];
}
if(M2C_FIELD(p,s32 *,0x84)<M2C_FIELD(p,s32 *,0x80)){
ghiReadBuffer(p+0x74,dst,len);
if(M2C_FIELD(p,s32 *,0x84)==M2C_FIELD(p,s32 *,0x80)){
M2C_FIELD(p,s32 *,0x80)=M2C_FIELD(p,s32 *,0xf8);
M2C_FIELD(p,s32 *,0x84)=M2C_FIELD(p,s32 *,0xf8);
}return 0;
}
got=ghiRecv(M2C_FIELD(p,s32 *,0x48),dst,n,0);
r=got;
if((u32)got==0xffffffffU){
err=ghiGetLastSocketError(M2C_FIELD(p,s32 *,0x48));
if(err==-6||err==-26||err==-76)return 1;
M2C_FIELD(p,s32 *,0xfc)=1;M2C_FIELD(p,s32 *,0x38)=5;
M2C_FIELD(p,s32 *,0x4c)=err;M2C_FIELD(p,s32 *,0x130)=1;return 3;
}
if(got==0){M2C_FIELD(p,s32 *,0x130)=1;return 2;}
if(M2C_FIELD(p,s32 *,0x168)){
if(!((s32 (*)(void *,u8 *))ghiAppendDataToBuffer)(p+0x98,dst))return 3;
if(!ghiDecryptBuffer(p)){M2C_FIELD(p,s32 *,0xfc)=1;M2C_FIELD(p,s32 *,0x38)=17;return 3;}
if(M2C_FIELD(p,s32 *,0x80)-M2C_FIELD(p,s32 *,0x84)<=0){*dst=0;*len=0;return 1;}
r=*len-1;
if(!ghiReadBuffer(p+0x74,dst,&r))return 3;
if(M2C_FIELD(p,s32 *,0x84)==M2C_FIELD(p,s32 *,0x80)){
M2C_FIELD(p,s32 *,0x80)=M2C_FIELD(p,s32 *,0xf8);
M2C_FIELD(p,s32 *,0x84)=M2C_FIELD(p,s32 *,0xf8);
}
got=r;if(got<=0)return 1;
}
out=0;dst[got]=0;*len=r;if(r<=0)out=1;return out;
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
#pragma opt_propagation reset
s32 ghiSocketSend(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 ghiSend(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 ghiGetLastSocketError(s32);
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = ghiSend(M2C_FIELD(arg0, s32 *, 0x48), arg1, arg2, 0);
    if (temp_r0 == -1) {
        temp_r0_2 = ghiGetLastSocketError(M2C_FIELD(arg0, s32 *, 0x48));
        if ((temp_r0_2 != -6) && (temp_r0_2 != -0x1A) && (temp_r0_2 != -0x4C)) {
            M2C_FIELD(arg0, s32 *, 0xFC) = 1;
            M2C_FIELD(arg0, s32 *, 0x38) = 5;
            M2C_FIELD(arg0, s32 *, 0x4C) = temp_r0_2;
            return -1;
        }
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x10) == 4) {
        M2C_FIELD(arg0, s32 *, 0x148) = (s32) (M2C_FIELD(arg0, s32 *, 0x148) + temp_r0);
    }
    return temp_r0;
}

s32 ghiSendData(void *p,s32 a,s32 b) {
s32 n=0;
if(M2C_FIELD(p,s32 *,0x5c)==0){
n=ghiSocketSend(p,a,b);
if(n==-1)return 0;
if(n==b)return 1;
}
if(!ghiAppendDataToBuffer((s32)p+0x50,(s32 *)(a+n),b-n))return 0;
return 2;
}

