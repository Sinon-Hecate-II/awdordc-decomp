/* 28 functions from 0x02059BBC to 0x0205ABB4 (main), found by ds-decomp. */
#include "common.h"
#include "gt2.h"
typedef struct { s32 v[4]; } Unk0205Copy;

/* Build the 32-byte GTI2 challenge response for the challenge in `in_` (and
 * return the same buffer): a valid challenge is mixed with the response key at
 * every position except 0 and 13; an invalid challenge - and those two
 * positions - get random printable characters. */
u8 *gti2ComputeResponse(void *out_, void *in_)
{
  u64 RuntimeIntDivMod(s32, s32);
  s32 StringLength(s32);
  s32 gti2CheckChallenge(s8 *);
  s32 Rand(void);
  s32 Abs(s32);
  extern s8 gGti2ResponseKey[];
  s32 valid;
  s32 keyLength;
  s32 keyStep;
  s32 value;
  s32 i;
  s32 prev;
  u8 *out = out_;
  s8 *in = in_;
  s32 mix;
  s32 keyByte;
  keyLength = StringLength((s32) gGti2ResponseKey);
  valid = gti2CheckChallenge(in);
  i = 0;
  keyStep = 0;
  do
  {
    if (((!valid) || (i == 0)) || (i == 13))
    {
      value = (Rand() % GTI2_CHALLENGE_RANGE) + GTI2_CHALLENGE_BASE;
    }
    else
    {
      if ((i == 1) || (i == 14))
      {
        prev = in[i];
      }
      else
      {
        prev = in[i - 1];
      }
      value = *((u8 *) (((u32) in) + ((u32) i)));
      mix = (s32) (RuntimeIntDivMod(i + value, keyLength) >> 32);
      keyByte = (s32) (RuntimeIntDivMod(prev * keyStep, keyLength) >> 32);
      mix = gGti2ResponseKey[mix];
      keyByte = gGti2ResponseKey[keyByte];
      mix = ((u8 *)in)[(mix + i * value) % GT2_RESPONSE_SIZE];
      mix ^= keyByte;
      value = (Abs(mix) % GTI2_CHALLENGE_RANGE) + GTI2_CHALLENGE_BASE;
    }
    *((u8 *) (((u32) out) + ((u32) i))) = value;
    keyStep += GTI2_RESPONSE_STEP;
    i++;
  }
  while (i < GT2_RESPONSE_SIZE);
  return out;
}

s32 gti2CheckResponse(u8 *a,u8 *b) {s32 i=0;do{if(i!=0&&i!=13&&a[i]!=b[i])return 0;i++;}while(i<32);return 1;}

s32 func_02059cf8(void *arg0, s32 arg1) {
    s32 gpiMalloc(s32);
    s32 temp_r0;

    temp_r0 = gpiMalloc(arg1);
    M2C_FIELD(arg0, s32 *, 0) = temp_r0;
    if (temp_r0 == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    return 1;
}

s32 gti2GetBufferFreeSpace(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4) - M2C_FIELD(arg0, s32 *, 8);
}

/* Append the byte `value` to `buffer`, asserting there is still room for it. */
void gti2BufferWriteByte(Gt2Buffer *buffer,s32 value) {
extern M2C_UNK gAssertExprBufferByteFits,gAssertFileNameBuffer,gAssertNameBufferWriteByte;
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,M2C_UNK);
if(buffer->len>=buffer->size)AssertFailed(&gAssertExprBufferByteFits,&gAssertFileNameBuffer,&gAssertNameBufferWriteByte,35);
buffer->data[buffer->len++]=value;
}

/* Append the 16-bit value `value` to `buffer` as two big-endian bytes,
 * asserting that both fit. */
void gti2BufferWriteUShort(Gt2Buffer *buffer, s32 value) {
extern M2C_UNK gAssertExprBufferShortFits,gAssertFileNameBuffer,gAssertNameBufferWriteUShort;
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,M2C_UNK);
if(M2C_FIELD(buffer,s32 *,8)+2>M2C_FIELD(buffer,s32 *,4))AssertFailed(&gAssertExprBufferShortFits,&gAssertFileNameBuffer,&gAssertNameBufferWriteUShort,46);
M2C_FIELD(buffer,u8 **,0)[M2C_FIELD(buffer,s32 *,8)++]=value>>8;
M2C_FIELD(buffer,u8 **,0)[M2C_FIELD(buffer,s32 *,8)++]=value;
}

/* Append `len` bytes from `data` to the GT2 buffer `buffer` (all of `data`'s
 * string when `len` is -1), asserting that they fit.  Nothing is written when
 * `data` or `len` is 0. */
void gti2BufferWriteData(Gt2Buffer *buffer, const void *data, s32 len) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    M2C_UNK MemCopy(s32, s32, s32);
    s32 StringLength(s32);
    extern M2C_UNK gAssertNameBufferWriteData;
    extern M2C_UNK gAssertFileNameBuffer;
    extern M2C_UNK gAssertExprBufferFits;
    s32 size;

    size = len;
    if ((data != 0) && (size != 0)) {
        if (size == -1) {
            size = StringLength((s32)data);
        }
        if ((s32)(buffer->len + size) > buffer->size) {
            AssertFailed(&gAssertExprBufferFits, &gAssertFileNameBuffer, &gAssertNameBufferWriteData, 0x40);
        }
        MemCopy((s32)(buffer->data + buffer->len), (s32)data, size);
        buffer->len = buffer->len + size;
    }
}

/* Remove `shortenBy` bytes from the GT2 buffer starting at `start` (from the
 * buffer's end when `start` is -1), shifting the following bytes down. */
void gti2RemoveFromBuffer(Gt2Buffer *buffer,s32 start,s32 shortenBy) {
extern M2C_UNK gAssertExprStartInBuffer,gAssertFileNameBuffer,gAssertNameBufferShorten,gAssertExprShortenFits;
void MemMove(s32,s32,s32);s32 dst;
if(start==-1)start=buffer->len-shortenBy;
if(start>buffer->len)AssertFailed(&gAssertExprStartInBuffer,&gAssertFileNameBuffer,&gAssertNameBufferShorten,79);
if(shortenBy>buffer->len-start)AssertFailed(&gAssertExprShortenFits,&gAssertFileNameBuffer,&gAssertNameBufferShorten,80);
dst=M2C_FIELD(buffer,s32 *,0)+start;
MemMove(dst,dst+shortenBy,buffer->len-start-shortenBy);
buffer->len-=shortenBy;
}

/* GameSpy GT2's socket error callback: report the error to the callback the
 * socket was created with, held inside the socket's callback count so a socket
 * asked to be freed is only freed once the outermost callback returns. Returns
 * 1, or 0 once the socket has been freed. */
s32 gti2SocketErrorCallback(void *socket) {
    M2C_UNK gti2FreeSocket(void *);
    extern M2C_UNK gAssertExprSocketErrorCallback;
    extern M2C_UNK gAssertNameSocket;
    extern M2C_UNK gAssertFileName;
    if (socket == NULL) {
        AssertFailed(&gAssertNameSocket, &gAssertFileName, &gAssertExprSocketErrorCallback, 0x1B);
    }
    if (socket == NULL) {
        return 1;
    }
    if (M2C_FIELD(socket, M2C_UNK (**)(void *), GT2_SOCKET_ERROR_CALLBACK) == NULL) {
        return 1;
    }
    M2C_FIELD(socket, s32 *, GT2_SOCKET_CALLBACKS) = (s32) (M2C_FIELD(socket, s32 *, GT2_SOCKET_CALLBACKS) + 1);
    M2C_FIELD(socket, M2C_UNK (**)(void *), GT2_SOCKET_ERROR_CALLBACK)(socket);
    M2C_FIELD(socket, s32 *, GT2_SOCKET_CALLBACKS) = (s32) (M2C_FIELD(socket, s32 *, GT2_SOCKET_CALLBACKS) - 1);
    if ((M2C_FIELD(socket, s32 *, GT2_SOCKET_DIRTY) != 0) && (M2C_FIELD(socket, s32 *, GT2_SOCKET_CALLBACKS) == 0)) {
        gti2FreeSocket(socket);
        return 0;
    }
    return 1;
}

/* GameSpy GT2's gti2ConnectAttemptCallback: pass an incoming connect attempt (ip, port,
 * latency, message, length) to the socket's connect-attempt callback, keeping the socket
 * and connection callback counts; when the socket was asked to close and this was its
 * last callback, free it. Returns 1, or 0 once the socket has been freed. */
s32 Gt2InvokeConnectAttempt(void *socket,void *connection,s32 ip,s32 port,s32 latency,s32 message,s32 length){
extern int data_020ff78c,gAssertFileName,data_020ff738;
if(!socket||!connection)AssertFailed(&data_020ff78c,&gAssertFileName,&data_020ff738,0x3d);
if(!socket||!connection)return 1;
if(!M2C_FIELD(socket,void **,0x20))return 1;
if(!length||!message){message=0;length=0;}
M2C_FIELD(socket,s32 *,0x1c)++;
M2C_FIELD(connection,s32 *,0x24)++;
((void (*)(void *,void *,s32,s32,s32,s32,s32))M2C_FIELD(socket,void **,0x20))(socket,connection,ip,port,latency,message,length);
M2C_FIELD(socket,s32 *,0x1c)--;M2C_FIELD(connection,s32 *,0x24)--;
if(M2C_FIELD(socket,s32 *,0x14)&&!M2C_FIELD(socket,s32 *,0x1c)){gti2FreeSocket(socket);return 0;}
return 1;
}

/* Report a connection event: record the event type on the connection and, when
 * the connection has an event callback, call it with the event's data.  The
 * call is nested via the connection and socket counters, so that a socket marked
 * for destruction is freed once the outermost callback has returned.  Returns 0
 * when the socket was freed, 1 otherwise. */
s32 Gt2ConnectionCallCallback(void *connection, s32 type, s32 data, s32 length) {
M2C_UNK gti2FreeSocket(void *);
M2C_UNK AssertFailed(M2C_UNK*,M2C_UNK*,M2C_UNK*,M2C_UNK);
extern M2C_UNK gAssertNameConnection,gAssertFileName,data_020ff6d4;
if(!connection)AssertFailed(&gAssertNameConnection,&gAssertFileName,&data_020ff6d4,0x69);
if(!connection)return 1;
M2C_FIELD(connection,s32*,0x18)=type;
if(!M2C_FIELD(connection,void**,GT2_CONNECTION_CALLBACK))return 1;
if(!length||!data) {data=0;length=0;}
M2C_FIELD(connection,s32*,GT2_CONNECTION_CALLBACKS)++;
M2C_FIELD(M2C_FIELD(connection,void**,GT2_CONNECTION_SOCKET),s32*,GT2_SOCKET_CALLBACKS)++;

((void (*)(void*,s32,s32,s32))M2C_FIELD(connection,void**,GT2_CONNECTION_CALLBACK))(connection,type,data,length);
M2C_FIELD(connection,s32*,GT2_CONNECTION_CALLBACKS)--;
M2C_FIELD(M2C_FIELD(connection,void**,GT2_CONNECTION_SOCKET),s32*,GT2_SOCKET_CALLBACKS)--;
if(M2C_FIELD(M2C_FIELD(connection,void**,GT2_CONNECTION_SOCKET),s32*,GT2_SOCKET_DIRTY)) {
if(!M2C_FIELD(M2C_FIELD(connection,void**,GT2_CONNECTION_SOCKET),s32*,GT2_SOCKET_CALLBACKS)) {
gti2FreeSocket(M2C_FIELD(connection,void**,GT2_CONNECTION_SOCKET));return 0;
}}
return 1;
}

/* Report an incoming message on a connection: when the connection has a message
 * callback, call it with the message, nested via the connection and socket
 * counters so a socket marked for destruction is freed once the outermost
 * callback returns. Returns 0 when the socket was freed, 1 otherwise. */
s32 Gt2ConnectionCallMessageCallback(void *connection,void *messageData,s32 messageLength,s32 unk){
extern int gAssertNameConnection,gAssertFileName,data_020ff6bc;
if(!connection)AssertFailed(&gAssertNameConnection,&gAssertFileName,&data_020ff6bc,0x94);
if(!connection)return 1;
if(!M2C_FIELD(connection,void **,GT2_CONNECTION_CALLBACK_MSG))return 1;
if(!messageLength||!messageData){messageData=0;messageLength=0;}
M2C_FIELD(connection,int *,GT2_CONNECTION_CALLBACKS)++;
M2C_FIELD(M2C_FIELD(connection,void **,GT2_CONNECTION_SOCKET),int *,GT2_SOCKET_CALLBACKS)++;

((void (*)(void *,void *,s32,s32))M2C_FIELD(connection,void **,GT2_CONNECTION_CALLBACK_MSG))(connection,messageData,messageLength,unk);
M2C_FIELD(connection,int *,GT2_CONNECTION_CALLBACKS)--;
M2C_FIELD(M2C_FIELD(connection,void **,GT2_CONNECTION_SOCKET),int *,GT2_SOCKET_CALLBACKS)--;
if(M2C_FIELD(M2C_FIELD(connection,void **,GT2_CONNECTION_SOCKET),int *,GT2_SOCKET_DIRTY)&&!M2C_FIELD(M2C_FIELD(connection,void **,GT2_CONNECTION_SOCKET),int *,GT2_SOCKET_CALLBACKS)){
gti2FreeSocket(M2C_FIELD(connection,void **,GT2_CONNECTION_SOCKET));return 0;
}return 1;}

/* GameSpy GT2's gti2ClosedCallback: report a connection close to the
 * connection's closed callback, nested via the connection and socket callback
 * counters so that a socket marked for destruction is freed once the outermost
 * callback returns.  Returns 0 when the socket was freed, 1 otherwise. */
int gti2ClosedCallback(void *connection, int reason) {
    M2C_UNK gti2FreeSocket(void *);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK gAssertNameConnection;
    extern M2C_UNK gAssertFileName;
    extern M2C_UNK gAssertExprClosedCallback;
    void *socket;

    if (connection == NULL) {
        AssertFailed(&gAssertNameConnection, &gAssertFileName, &gAssertExprClosedCallback, 0xBA);
    }
    if (connection == NULL) {
        return 1;
    }
    if (!M2C_FIELD(connection, void **, GT2_CONNECTION_CALLBACK_CLOSED)) {
        return 1;
    }
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_CALLBACKS) = M2C_FIELD(connection, s32 *, GT2_CONNECTION_CALLBACKS) + 1;
    socket = M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET);
    M2C_FIELD(socket, s32 *, GT2_SOCKET_CALLBACKS) = M2C_FIELD(socket, s32 *, GT2_SOCKET_CALLBACKS) + 1;
    ((void (*)(void *, int))M2C_FIELD(connection, void **, GT2_CONNECTION_CALLBACK_CLOSED))(connection, reason);
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_CALLBACKS) = M2C_FIELD(connection, s32 *, GT2_CONNECTION_CALLBACKS) - 1;
    socket = M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET);
    M2C_FIELD(socket, s32 *, GT2_SOCKET_CALLBACKS) = M2C_FIELD(socket, s32 *, GT2_SOCKET_CALLBACKS) - 1;
    socket = M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET);
    if (M2C_FIELD(socket, s32 *, GT2_SOCKET_DIRTY)) {
        if (!M2C_FIELD(socket, s32 *, GT2_SOCKET_CALLBACKS)) {
            gti2FreeSocket((void *) socket);
            return 0;
        }
    }
    return 1;
}

/* GameSpy GT2's gti2PingCallback: report a ping reply's round-trip time to the
 * connection's ping callback.  The call is nested via the connection and the
 * socket callback counters, so that a socket marked for destruction is freed
 * once the outermost callback has returned.  Returns 1, or 0 once the socket
 * has been freed. */
s32 gti2PingCallback(void *connection, s32 pingTime) {
    M2C_UNK gti2FreeSocket(void *);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK gAssertNameConnection;
    extern M2C_UNK gAssertFileName;
    extern M2C_UNK gAssertExprPingCallback;
    if (connection == NULL) {
        AssertFailed(&gAssertNameConnection, &gAssertFileName, &gAssertExprPingCallback, 0xD9);
    }
    if (connection == NULL) {
        return 1;
    }
    if (!M2C_FIELD(connection, void **, GT2_CONNECTION_CALLBACK_PING)) {
        return 1;
    }
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_CALLBACKS) = M2C_FIELD(connection, s32 *, GT2_CONNECTION_CALLBACKS) + 1;
    M2C_FIELD(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CALLBACKS) = M2C_FIELD(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CALLBACKS) + 1;
    ((void (*)(void *, s32))M2C_FIELD(connection, void **, GT2_CONNECTION_CALLBACK_PING))(connection, pingTime);
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_CALLBACKS) = M2C_FIELD(connection, s32 *, GT2_CONNECTION_CALLBACKS) - 1;
    M2C_FIELD(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CALLBACKS) = M2C_FIELD(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CALLBACKS) - 1;
    if (M2C_FIELD(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_DIRTY)) {
        if (!M2C_FIELD(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CALLBACKS)) {
            gti2FreeSocket(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET));
            return 0;
        }
    }
    return 1;
}

/* Invoke the send-filter callback entry, with nesting/refcount bookkeeping and release when idle. */
s32 gti2SendFilterCallback(void *connection, void *callbackIndex, s32 b, s32 c, s32 d) {
    void *Vector_GetItem(int, int);
    void *callback;
    extern int gAssertNameConnection, gAssertFileName, data_020ff6ec;
    if (!connection) AssertFailed(&gAssertNameConnection, &gAssertFileName, &data_020ff6ec, 0x101);
    if (!connection) return 1;
    callback = Vector_GetItem(M2C_FIELD(connection, void **, 0x98), callbackIndex);
    if (!callback) return 1;
    if (!c || !b) { b = 0; c = 0; }
    M2C_FIELD(connection, int *, 0x24)++;
    M2C_FIELD(M2C_FIELD(connection, void **, 8), int *, 0x1c)++;
    ((void (*)(void *, void *, s32, s32, s32))M2C_FIELD(callback, void **, 0))(connection, callbackIndex, b, c, d);
    M2C_FIELD(connection, int *, 0x24)--;
    M2C_FIELD(M2C_FIELD(connection, void **, 8), int *, 0x1c)--;
    if (M2C_FIELD(M2C_FIELD(connection, void **, 8), int *, 0x14) && !M2C_FIELD(M2C_FIELD(connection, void **, 8), int *, 0x1c)) {
        gti2FreeSocket(M2C_FIELD(connection, void **, 8));
        return 0;
    }
    return 1;
}

/* Invoke receive-filter callback entry 0 (or a), with nesting/refcount bookkeeping; release the filter table when idle. */
s32 gti2ReceiveFilterCallback(void *p,void *a,s32 b,s32 c,s32 d){
void *Vector_GetItem(int,int);void *entry;
extern int gAssertNameConnection,gAssertFileName,data_020ff71c;
if(!p)AssertFailed(&gAssertNameConnection,&gAssertFileName,&data_020ff71c,0x12d);
if(!p)return 1;
entry=Vector_GetItem(M2C_FIELD(p,void **,0x9c),a);if(!entry)return 1;
if(!c||!b){b=0;c=0;}
M2C_FIELD(p,int *,0x24)++;
M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x1c)++;

((void (*)(void *,void *,s32,s32,s32))M2C_FIELD(entry,void **,0))(p,a,b,c,d);
M2C_FIELD(p,int *,0x24)--;
M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x1c)--;
if(M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x14)&&!M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x1c)){
gti2FreeSocket(M2C_FIELD(p,void **,8));return 0;
}return 1;}

/* Invoke the GT2 socket's dump handler for a message being sent (send != 0) or
 * received, keep the socket's and connection's callback refcounts, and free the
 * socket when it was closed and the last callback has returned. */
s32 gti2DumpCallback(void *socket, void *connection, s32 address, s32 port, s32 flags, s32 message, s32 length, s32 send) {
    extern int gAssertNameSocket, gAssertFileName, data_020ff680;
    void (*dumpHandler)(void *, void *, s32, s32, s32, s32, s32);
    if (!socket) AssertFailed(&gAssertNameSocket, &gAssertFileName, &data_020ff680, 0x160);
    if (!socket) return 1;
    if (send) dumpHandler = M2C_FIELD(socket, void (**)(void *, void *, s32, s32, s32, s32, s32), 0x28);
    else dumpHandler = M2C_FIELD(socket, void (**)(void *, void *, s32, s32, s32, s32, s32), 0x2c);
    if (!dumpHandler) return 1;
    if (!length || !message) { length = 0; message = 0; }
    M2C_FIELD(socket, s32 *, 0x1c)++;
    if (connection) M2C_FIELD(connection, s32 *, 0x24)++;
    dumpHandler(socket, connection, address, port, flags, message, length);
    M2C_FIELD(socket, s32 *, 0x1c)--;
    if (connection) M2C_FIELD(connection, s32 *, 0x24)--;
    if (M2C_FIELD(socket, s32 *, 0x14) && !M2C_FIELD(socket, s32 *, 0x1c)) { gti2FreeSocket(socket); return 0; }
    return 1;
}

/* Invoke the "unrecognized message" callback with refcount tracking, releasing the owning handler when idle. */
s32 gti2UnrecognizedMessageCallback(void *p,s32 a,s32 b,s32 c,s32 d,s32 *out){
extern int gAssertNameSocket,gAssertFileName,data_020ff754;
*out=0;
if(!p)AssertFailed(&gAssertNameSocket,&gAssertFileName,&data_020ff754,0x197);
if(!p)return 1;
if(!M2C_FIELD(p,void **,0x30))return 1;
if(!d||!c){c=0;d=0;}
M2C_FIELD(p,int *,0x1c)++;
*out=((s32 (*)(void *,s32,s32,s32,s32))M2C_FIELD(p,void **,0x30))(p,a,b,c,d);
M2C_FIELD(p,int *,0x1c)--;
if(M2C_FIELD(p,int *,0x14)&&!M2C_FIELD(p,int *,0x1c)){gti2FreeSocket(p);return 0;}
return 1;
}

s32 func_0205a830(s32 a,void **p) {s32 gti2CreateConnection(s32);s32 r=gti2CreateConnection(a);if(r)return r;M2C_FIELD(*p,s32 *,12)=0;M2C_FIELD(*p,s32 *,16)=1;return 0;}

s32 func_0205a860(s32 a,void **p) {s32 gti2CreateConnection(s32);s32 r=gti2CreateConnection(a);if(r)return r;M2C_FIELD(*p,s32 *,12)=2;M2C_FIELD(*p,s32 *,16)=0;return 0;}

/* Start a client-side GT2 connection attempt: store the connect message and the
 * callbacks on the connection, generate our challenge, compute the response the
 * peer must echo, send the CONNECT command carrying the challenge and wait for
 * the peer's CONNECT_ACCEPT.  Returns 0 on success, 1 if the message could not
 * be copied. */
s32 gti2StartConnectionAttempt(void *connection,s32 message,s32 messageLen,GT2ConnectionCallbacks *callbacks,...) {
s32 gti2NormalizeMessage(s32 *,s32 *);void gti2GetChallenge(void *);u8 *gti2ComputeResponse(void *,void *);void gti2SendConnect(void *,void *);
s32 challenge[8];s32 messageCopy;
gti2NormalizeMessage(&message,&messageLen);
if(messageLen>0){messageCopy=gpiMalloc(messageLen);M2C_FIELD(connection,s32 *,GT2_CONNECTION_DATA)=messageCopy;if(!messageCopy)return 1;MemCopy(messageCopy,message,messageLen);M2C_FIELD(connection,s32 *,GT2_CONNECTION_DATA_LEN)=messageLen;}
if(callbacks)M2C_FIELD(connection,GT2ConnectionCallbacks *,GT2_CONNECTION_CALLBACK)=*callbacks;
gti2GetChallenge(challenge);gti2ComputeResponse((u8 *)connection+GT2_CONNECTION_RESPONSE,challenge);gti2SendConnect(connection,challenge);M2C_FIELD(connection,s32 *,GT2_CONNECTION_STATE)=GT2_STATE_AWAIT_CONNECT_ACCEPT;return 0;
}

/* Server side of the GT2 handshake: drop a connection that closed while it was
 * still pending and, once the peer's response is in, send ACCEPT, mark the
 * connection established and store the callbacks it reports events through. */
s32 gti2AcceptConnection(void *connection,GT2ConnectionCallbacks *callbacks) {
void gti2SendAccept(void *);
if(M2C_FIELD(connection,s32 *,GT2_CONNECTION_CLOSE_PENDING)){M2C_FIELD(connection,s32 *,GT2_CONNECTION_CLOSE_PENDING)=0;return 0;}
M2C_FIELD(connection,s32 *,GT2_CONNECTION_CLOSE_PENDING)=0;
if(M2C_FIELD(connection,s32 *,GT2_CONNECTION_STATE)!=GT2_STATE_AWAIT_ACCEPT)return 0;
gti2SendAccept(connection);M2C_FIELD(connection,s32 *,GT2_CONNECTION_STATE)=GT2_STATE_CONNECTED;
if(callbacks)M2C_FIELD(connection,GT2ConnectionCallbacks *,GT2_CONNECTION_CALLBACK)=*callbacks;
return 1;
}

/* GameSpy GT2's gti2RejectConnection: refuse a connection that is still awaiting
 * the server's accept by sending a CLOSE carrying the reason message, then move
 * it to the peer-closed state; a connection in any other state is left alone. */
void gti2RejectConnection(void *connection, s32 message, s32 length, ...) {
    M2C_UNK gti2NormalizeMessage(s32 *, s32 *);
    M2C_UNK gti2SendClose(void *, s32, s32);

    M2C_FIELD(connection, s32 *, GT2_CONNECTION_CLOSE_PENDING) = 0;
    if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) != GT2_STATE_AWAIT_ACCEPT) return;
    gti2NormalizeMessage(&message, &length);
    gti2SendClose(connection, message, length);
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) = GT2_STATE_PEER_CLOSED;
}

/* Send `length` bytes of `data` to the connection's peer in one raw socket
 * send and remember when they went out.  Returns 1 on success, 0 when the send
 * failed. */
s32 gti2SendRaw(void *connection, void *data, s32 length) {
    s32 GetSystemTickMilliseconds();
    s32 gti2SocketSend(void *, s32, u16, void *, s32);
    if (gti2SocketSend(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), M2C_FIELD(connection, s32 *, GT2_CONNECTION_IP), M2C_FIELD(connection, u16 *, GT2_CONNECTION_PORT), data, length) == 0) {
        return 0;
    }
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_LAST_SENT) = GetSystemTickMilliseconds();
    return 1;
}

/* Check one GT2 connection for a handshake timeout.  While the handshake is
 * still in progress, a connection this side opened is dropped when it has been
 * silent longer than its own timeout, and a connection accepted from a peer
 * when it has been silent longer than GT2_CONNECT_TIMEOUT.  A timed-out
 * connection sends its CLOSED command, is marked closed, and reports event 6
 * (the timeout) to the connection's callback.  Returns 1 to keep the
 * connection, or 0 once a callback freed the socket. */
s32 gti2CheckTimeout(void *connection, u32 now) {
    s32 Gt2ConnectionCallCallback(void *, s32, s32, s32);
    void gti2SendClosed(void *);
    void gti2MarkConnectionClosed(void *);
    s32 state = M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE), timedOut;

    if (state < GT2_STATE_CONNECTED) {
        timedOut = 0;
        if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_INITIATOR)) {
            u32 timeout = M2C_FIELD(connection, u32 *, GT2_CONNECTION_TIMEOUT);
            if (timeout) {
                if (now - M2C_FIELD(connection, u32 *, GT2_CONNECTION_LAST_RECEIVE) > timeout) timedOut = 1;
            }
        } else if (state < GT2_STATE_AWAIT_ACCEPT) {
            if (now - M2C_FIELD(connection, u32 *, GT2_CONNECTION_LAST_RECEIVE) > GT2_CONNECT_TIMEOUT) timedOut = 1;
        }
        if (timedOut) {
            gti2SendClosed(connection);
            gti2MarkConnectionClosed(connection);
            if (!Gt2ConnectionCallCallback(connection, 6, 0, 0)) return 0;
        }
    }
    return 1;
}

/* Walk the connection's acknowledgement queue and resend every sent command the
 * peer has left unacknowledged for longer than GT2_RESEND_TIMEOUT.  Returns 0
 * once a resend fails (the socket may have been freed), 1 otherwise. */
s32 gti2ResendTimedOutCommands(void *connection,u32 now) {
s32 Vector_GetCount(s32);void *Vector_GetItem(s32,s32);s32 gti2ResendPendingCommand(void *,void *);
s32 i,count;void *command;
count=Vector_GetCount(M2C_FIELD(connection,s32 *,GT2_CONNECTION_ACK_QUEUE));
for(i=0;i<count;i++){
command=Vector_GetItem(M2C_FIELD(connection,s32 *,GT2_CONNECTION_ACK_QUEUE),i);
if(now-M2C_FIELD(command,u32 *,GT2_SENT_COMMAND_LAST_SENT)>GT2_RESEND_TIMEOUT){
if(!gti2ResendPendingCommand(connection,command))return 0;
}
}
return 1;
}

s32 gti2CheckDelayedAck(void *p,u32 t) {s32 func_0205ca48(void *,u32);if(!M2C_FIELD(p,s32 *,0x90))return 1;if(t-M2C_FIELD(p,u32 *,0x94)>100){if(!func_0205ca48(p,t-M2C_FIELD(p,u32 *,0x94)))return 0;}return 1;}

s32 gti2CheckPing(void *p,u32 t) {s32 gti2SendPing(void *,u32);if(t-M2C_FIELD(p,u32 *,0x88)>30000){if(!gti2SendPing(p,t-M2C_FIELD(p,u32 *,0x88)))return 0;}return 1;}

