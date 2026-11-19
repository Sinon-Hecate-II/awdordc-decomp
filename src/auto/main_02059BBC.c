/* 28 functions from 0x02059BBC to 0x0205ABB4 (main), found by ds-decomp. */
#include "common.h"
#include "gt2.h"
typedef struct { s32 v[4]; } Unk0205Copy;

u8 *gti2ComputeResponse(void *out_, void *in_)
{
  u64 func_020720f0(s32, s32);
  s32 StringLength(s32);
  s32 func_02059a04(s8 *);
  s32 Rand(void);
  s32 Abs(s32);
  extern s8 data_020ff548[];
  s8 *in = in_;
  u8 *out = out_;
  s32 prev;
  s32 n;
  s32 step;
  int new_var;
  s32 v;
  s32 i;
  s32 flag;
  s32 a;
  s32 b;
  n = StringLength((s32) data_020ff548);
  flag = func_02059a04(in);
  i = 0;
  step = 0;
  new_var = i == 14;
  do
  {
    if (((!flag) || (i == 0)) || (i == 13))
    {
      v = (Rand() % 93) + 33;
    }
    else
    {
      if ((i == 1) || new_var)
      {
        prev = in[i];
      }
      else
      {
        prev = in[i - 1];
      }
      v = *((u8 *) (((u32) in) + ((u32) i)));
      a = (s32) (func_020720f0(i + v, n) >> 32);
      b = (s32) (func_020720f0(prev * step, n) >> 32);
      a = data_020ff548[a];
      b = data_020ff548[b];
      v = (Abs(b ^ ((u8 *) in)[(a + (i * v)) % 32]) % 93) + 33;
    }
    *((u8 *) (((u32) out) + ((u32) i))) = v;
    step += 0x4647;
    i++;
  }
  while (i < 32);
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

void gti2AddByteToBuffer(void *p,s32 a) {
extern M2C_UNK data_020ff5d4,gAssertFileNameBuffer,data_020ff5a8;
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,M2C_UNK);
if(M2C_FIELD(p,s32 *,8)>=M2C_FIELD(p,s32 *,4))AssertFailed(&data_020ff5d4,&gAssertFileNameBuffer,&data_020ff5a8,35);
M2C_FIELD(p,u8 **,0)[M2C_FIELD(p,s32 *,8)++]=a;
}

void gti2AddShortToBuffer(void *p,s32 a) {
extern M2C_UNK data_020ff5fc,gAssertFileNameBuffer,data_020ff5bc;
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,M2C_UNK);
if(M2C_FIELD(p,s32 *,8)+2>M2C_FIELD(p,s32 *,4))AssertFailed(&data_020ff5fc,&gAssertFileNameBuffer,&data_020ff5bc,46);
M2C_FIELD(p,u8 **,0)[M2C_FIELD(p,s32 *,8)++]=a>>8;
M2C_FIELD(p,u8 **,0)[M2C_FIELD(p,s32 *,8)++]=a;
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
s32 func_0205a424(void *connection, void *callbackIndex, s32 b, s32 c, s32 d) {
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
s32 func_0205d70c(s32 *,s32 *);void gti2GetChallenge(void *);u8 *gti2ComputeResponse(void *,void *);void gti2SendConnect(void *,void *);
s32 challenge[8];s32 messageCopy;
func_0205d70c(&message,&messageLen);
if(messageLen>0){messageCopy=gpiMalloc(messageLen);M2C_FIELD(connection,s32 *,GT2_CONNECTION_DATA)=messageCopy;if(!messageCopy)return 1;MemCopy(messageCopy,message,messageLen);M2C_FIELD(connection,s32 *,GT2_CONNECTION_DATA_LEN)=messageLen;}
if(callbacks)M2C_FIELD(connection,GT2ConnectionCallbacks *,GT2_CONNECTION_CALLBACK)=*callbacks;
gti2GetChallenge(challenge);gti2ComputeResponse((u8 *)connection+GT2_CONNECTION_RESPONSE,challenge);gti2SendConnect(connection,challenge);M2C_FIELD(connection,s32 *,GT2_CONNECTION_STATE)=GT2_STATE_AWAIT_CONNECT_ACCEPT;return 0;
}

s32 func_0205a938(void *p,Unk0205Copy *q) {
void func_0205c7f8(void *);
if(M2C_FIELD(p,s32 *,20)){M2C_FIELD(p,s32 *,20)=0;return 0;}
M2C_FIELD(p,s32 *,20)=0;if(M2C_FIELD(p,s32 *,12)!=4)return 0;
func_0205c7f8(p);M2C_FIELD(p,s32 *,12)=5;if(q)M2C_FIELD(p,Unk0205Copy *,0x28)=*q;return 1;
}

void func_0205a994(void *p,s32 a,s32 b,...) {
M2C_UNK func_0205d70c(s32 *,s32 *);M2C_UNK func_0205c854(void *,s32,s32);
M2C_FIELD(p,s32 *,20)=0;if(M2C_FIELD(p,s32 *,12)!=4)return;
func_0205d70c(&a,&b);func_0205c854(p,a,b);M2C_FIELD(p,s32 *,12)=6;
}

s32 gti2SendRaw(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 GetTickCountMs();
    s32 func_0205d228(s32, s32, u16, M2C_UNK, s32);
    if (func_0205d228(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, u16 *, 4), arg1, arg2) == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x88) = GetTickCountMs();
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

s32 func_0205aad8(void *p,u32 t) {
s32 Vector_GetCount(s32);void *Vector_GetItem(s32,s32);s32 gti2ResendPendingCommand(void *,void *);
s32 i,n;n=Vector_GetCount(M2C_FIELD(p,s32 *,96));
for(i=0;i<n;i++){void *q=Vector_GetItem(M2C_FIELD(p,s32 *,96),i);if(t-M2C_FIELD(q,u32 *,12)>1000){if(!gti2ResendPendingCommand(p,q))return 0;}}return 1;
}

s32 func_0205ab44(void *p,u32 t) {s32 func_0205ca48(void *,u32);if(!M2C_FIELD(p,s32 *,0x90))return 1;if(t-M2C_FIELD(p,u32 *,0x94)>100){if(!func_0205ca48(p,t-M2C_FIELD(p,u32 *,0x94)))return 0;}return 1;}

s32 func_0205ab80(void *p,u32 t) {s32 func_0205c924(void *,u32);if(t-M2C_FIELD(p,u32 *,0x88)>30000){if(!func_0205c924(p,t-M2C_FIELD(p,u32 *,0x88)))return 0;}return 1;}

