/* 42 functions from 0x0205ABB4 to 0x0205BB90 (main), found by ds-decomp. */
#include "common.h"
#include "gt2.h"

/* Advance one GT2 connection: give up on a handshake that timed out, ping a
 * peer we have not sent to for a while, resend commands the peer has not
 * acknowledged, and send the delayed acknowledgement for received data.
 * Returns 0 when a callback freed the connection, 1 to keep thinking it. */
s32 gti2ThinkConnection(void *connection, u32 now) {
    s32 gti2CheckTimeout(void *, u32);
    s32 gti2ResendTimedOutCommands(void *, u32);
    s32 gti2CheckDelayedAck(void *, u32);
    s32 gti2CheckPing(void *, u32);
    if (gti2CheckTimeout(connection, now) == 0) {
        return 0;
    }
    if (gti2CheckPing(connection, now) == 0) {
        return 0;
    }
    if (gti2ResendTimedOutCommands(connection, now) == 0) {
        return 0;
    }
    if (gti2CheckDelayedAck(connection, now) != 0) {
        return 1;
    }
    return 0;
}

/* Close a GT2 connection.  When `localClose` is set the connection is marked
 * closed, the peer is told with a CLOSED notice, the closed callback runs with
 * reason 0 (local) and the connection is dropped from its socket; otherwise the
 * peer closed, so the state becomes PEER_CLOSED and the reliable CLOSED
 * acknowledgement is sent.  A connection that is already closed is left alone. */
M2C_UNK gti2HandleConnectionClose(s32 connection, s32 localClose) {
    void gti2MarkConnectionClosed(void *, ...);
    M2C_UNK gti2SendClosed();
    s32 gti2ClosedCallback(s32, s32);
    void gti2RemoveConnection(s32);
    void gti2SendClosedAck(s32);
    if (localClose) {
        if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) >= GT2_STATE_CLOSED) return;
        gti2MarkConnectionClosed((void *) connection);
        gti2SendClosed(connection);
        gti2ClosedCallback(connection, 0);
        gti2RemoveConnection(connection);
    } else {
        M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) = GT2_STATE_PEER_CLOSED;
        gti2SendClosedAck(connection);
    }
}

/* Mark a GT2 connection closed: leave it alone if it already is, otherwise set
 * its state and move it from its socket's connection hash table to the socket's
 * connection vector. */
void gti2MarkConnectionClosed(void *connection, ...) {
    void TableRemove(s32, void **);
    void Vector_Append(s32, void **);
    if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) == GT2_STATE_CLOSED) return;
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) = GT2_STATE_CLOSED;
    TableRemove(M2C_FIELD(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CONNECTION_TABLE), &connection);
    Vector_Append(M2C_FIELD(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CONNECTIONS), &connection);
}

/* Free a GT2 connection: its queued handshake data, receive and send buffers,
 * send and acknowledgement queues, message-callback and filter vectors, then
 * the connection itself. */
void gti2FreeConnection(void *connection) {
void gpiFree(void *);void Vector_Free(void *);void *p;
p=M2C_FIELD(connection,void **,GT2_CONNECTION_DATA);if(p)gpiFree(p);
p=M2C_FIELD(connection,void **,GT2_CONNECTION_RECV_BUFFER);if(p)gpiFree(p);
p=M2C_FIELD(connection,void **,GT2_CONNECTION_SEND_BUFFER);if(p)gpiFree(p);
p=M2C_FIELD(connection,void **,GT2_CONNECTION_PENDING_QUEUE);if(p)Vector_Free(p);
p=M2C_FIELD(connection,void **,GT2_CONNECTION_ACK_QUEUE);if(p)Vector_Free(p);
p=M2C_FIELD(connection,void **,GT2_CONNECTION_MESSAGE_CALLBACKS);if(p)Vector_Free(p);
p=M2C_FIELD(connection,void **,GT2_CONNECTION_FILTERS);if(p)Vector_Free(p);
gpiFree(connection);
}

void Gt2CreateSocket(s32 a,s32 b,s32 c,s32 d,s32 e) {
void gti2CreateSocket(s32,s32,s32,s32,s32);
gti2CreateSocket(a,b,c,d,e);
}

void func_0205ad60(M2C_UNK arg0) {
    void GT2NotifyConnectionClosed();
    M2C_UNK gti2FreeSocket(M2C_UNK);
    GT2NotifyConnectionClosed();
    gti2FreeSocket(arg0);
}

void func_0205ad78(M2C_UNK arg0) {
    s32 func_0205c344();
    s32 gti2ThinkSocketConnections(M2C_UNK);
    M2C_UNK gti2RemoveClosedConnections(M2C_UNK);
    if (func_0205c344() == 0) {
        return;
    }
    if (gti2ThinkSocketConnections(arg0) == 0) {
        return;
    }
    gti2RemoveClosedConnections(arg0);
}

void Gt2SocketSetConnectAttempt(void) {
    M2C_UNK gti2SocketSetConnectAttempt();
    gti2SocketSetConnectAttempt();
}

void func_0205adb4(void) {
    M2C_UNK gti2AcceptConnection();
    gti2AcceptConnection();
}

void func_0205adc0(void) {
    M2C_UNK gti2RejectConnection();
    gti2RejectConnection();
}

#pragma scheduling off
s32 func_0205adcc(s32 a,void **b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h){
void func_02049260(s32);s32 func_0205a830(s32,void **);s32 func_0205a890(void *,s32,s32,s32);void func_0205d164(s32);s32 func_0205d588(s32,u32 *,u16 *);
void *p;u32 ip;u16 port;s32 result,done;
if(!func_0205d588(c,&ip,&port)||!ip||!port)return 4;
if(((((ip<<24)&0xff000000)|(((ip<<8)&0xff0000)|((u8)(ip>>24)|((ip>>8)&0xff00))))&0xe0000000)==0xe0000000)return 4;
result=func_0205a830(a,&p);if(result)return result;
M2C_FIELD(p,s32 *,32)=f;
result=func_0205a890(p,d,e,g);if(result){func_0205d164((s32)p);return result;}
if(!h){if(b)*b=p;return 0;}
M2C_FIELD(p,s32 *,36)++;
do{func_0205ad78(a);if(M2C_FIELD(p,s32 *,12)>=5)done=1;else done=0;if(!done)func_02049260(1);}while(!done);
M2C_FIELD(p,s32 *,36)--;
if(M2C_FIELD(p,s32 *,12)==5)*b=p;
return M2C_FIELD(p,s32 *,24);
}
#pragma scheduling reset
/* Send a message on a connected GT2 peer, starting with the first send filter when present. */
void gt2Send(void *connection, const u8 *message, s32 length, s32 reliable) {
    s32 Vector_GetCount(s32 *);
    void gti2NormalizeMessage(const u8 **, s32 *);
    s32 gti2SendFilterCallback(void *, s32, const u8 *, s32, s32);
    void gti2Send(void *, const u8 *, s32, s32);

    if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) != GT2_STATE_CONNECTED) {
        return;
    }
    gti2NormalizeMessage(&message, &length);
    if (Vector_GetCount(M2C_FIELD(connection, s32 **, GT2_CONNECTION_SEND_FILTERS))) {
        gti2SendFilterCallback(connection, 0, message, length, reliable);
        return;
    }
    gti2Send(connection, message, length, reliable);
}

void GT2FailConnectionAttempt(M2C_UNK arg0) {
    M2C_UNK gti2HandleConnectionClose(M2C_UNK, M2C_UNK);
    gti2HandleConnectionClose(arg0, 1);
}

void gti2FailTableConnection(s32 *arg0) {
    GT2FailConnectionAttempt(*arg0);
}

/* Fail every connection a GT2 socket owns (the socket is closing), run from a
 * reentry guard so a closed callback cannot start this pass again. */
void GT2NotifyConnectionClosed(void *socket) {
extern s32 gGt2ClosingConnections;
void TableMapSafe(s32,void (*)(s32 *),s32);
void gti2FailTableConnection(s32 *);
if(gGt2ClosingConnections==1)return;
gGt2ClosingConnections=1;
TableMapSafe(M2C_FIELD(socket,s32 *,GT2_SOCKET_CONNECTION_TABLE),gti2FailTableConnection,0);
gGt2ClosingConnections=0;
}

u16 GT2SocketPort(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 8);
}

s32 func_0205b038(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x54) - M2C_FIELD(arg0, s32 *, 0x58);
}

s32 GT2SocketHandle(s32 *arg0) {
    return *arg0;
}

void Gt2SocketSetUnrecognizedCallback(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x30) = arg1;
}

/* GameSpy GT2: attach the caller's data word to a connection (the connection
   must not be NULL). */
void gt2SetConnectionData(void *connection, s32 data) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK sGt2AssertConnection, gGt2MainFileName, sGt2SetConnectionDataName;
    if (!connection) AssertFailed(&sGt2AssertConnection, &gGt2MainFileName, &sGt2SetConnectionDataName, 0x1a3);
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_USER_DATA) = data;
}

/* Return the caller's user data attached to GT2 `connection` (the network layer
 * keeps its peer record there); a NULL connection is a bug. */
s32 gt2GetConnectionData(void *connection) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK sGt2GetConnectionDataName;
    extern M2C_UNK gGt2MainFileName;
    extern M2C_UNK sGt2AssertConnection;

    if (connection == NULL) {
        AssertFailed(&sGt2AssertConnection, &gGt2MainFileName, &sGt2GetConnectionDataName, 0x1AA);
    }
    return M2C_FIELD(connection, s32 *, GT2_CONNECTION_USER_DATA);
}

s32 Gt2ReadShort(u8 *a,s32 b) {u16 n=(a[b]<<8)&0xff00;return (u16)n|a[b+1];}

void func_0205b0ec(u8 *a,s32 b,s32 c){a[b]=c>>8;a[b+1]=c;}

s16 Gt2CompareSequence(s32 arg0, s32 arg1) {
    return (s16) (arg0 - arg1);
}

/* Shared teardown path of a GT2 connection.  A connection that is still
 * handshaking reports the failure through its connected callback with
 * `connectEvent` when this side opened it; one accepted from the peer is only
 * marked closed (and noted so that a late accept is refused).  A live connection
 * reports `closeReason` through its closed callback.  A connection that is
 * already closed is left alone.  Returns 0 when a callback freed the connection,
 * so the caller must not touch it any more. */
s32 gti2CloseConnection(M2C_UNK connection, M2C_UNK connectEvent, M2C_UNK closeReason) {
    s32 Gt2ConnectionCallCallback(s32, s32, s32, s32);
    s32 gti2ClosedCallback(s32, s32);
    s32 state = M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE);

    if (state < GT2_STATE_CONNECTED) {
        if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_INITIATOR)) {
            gti2MarkConnectionClosed((void *)connection);
            if (!Gt2ConnectionCallCallback(connection, connectEvent, 0, 0)) return 0;
        } else {
            if (state == GT2_STATE_AWAIT_ACCEPT) M2C_FIELD(connection, s32 *, GT2_CONNECTION_CLOSE_PENDING) = 1;
            gti2MarkConnectionClosed((void *)connection);
        }
    } else if (state != GT2_STATE_CLOSED) {
        gti2MarkConnectionClosed((void *)connection);
        if (!gti2ClosedCallback(connection, closeReason)) return 0;
    }
    return 1;
}

s32 Gt2CloseConnection(M2C_UNK arg0) {
    M2C_UNK gti2CloseConnection(M2C_UNK, M2C_UNK, M2C_UNK);
    return gti2CloseConnection(arg0, 7, 2);
}

s32 gti2SendClosedAndClose(M2C_UNK arg0) {
    s32 gti2SendClosed();
    if (gti2SendClosed() == 0) {
        return 0;
    }
    return gti2CloseConnection(arg0, 1, 4);
}

/* Drop the leading entries of the sorted list a->list whose key is below b,
   then rebase every remaining entry's index by the first entry's value and
   delete that many leading items from the object's backing store at a+0x50. */
#pragma opt_strength_reduction off
s32 Gt2AckSentData(void *a,s32 b){
void *Vector_GetItem(s32,s32);
s32 n,i,removed; s32 *p;
    u32 index;
n=Vector_GetCount(M2C_FIELD(a,s32 *,0x60));if(!n)return 1;
for(i=0;i<n;i++){if(Gt2CompareSequence(M2C_FIELD(Vector_GetItem(M2C_FIELD(a,s32 *,0x60),i),u16 *,8),b)>=0)break;}
if(!i)return 1;
index = i;
    while (index--) {
        Vector_RemoveItem(M2C_FIELD(a, s32 *, 0x60), index);
    }
n=Vector_GetCount(M2C_FIELD(a,s32 *,0x60));if(!n){M2C_FIELD(a,s32 *,0x58)=0;return 1;}
removed=*(s32 *)Vector_GetItem(M2C_FIELD(a,s32 *,0x60),0);
for(i=0;i<n;i++){p=Vector_GetItem(M2C_FIELD(a,s32 *,0x60),i);*p-=removed;}
gti2RemoveFromBuffer((u8 *)a+0x50,0,removed);return 1;}
/* Delivers application data that arrived on a GT2 connection to its receive
 * filters, or to the message callback when it has none.  Returns 1 when the data
 * was handled (or the connection is not receiving) and 0 when the callback freed
 * the socket. */
s32 gti2HandleData(void *connection, void *message, s32 length) {
    s32 Vector_GetCount(s32);
    s32 Gt2ConnectionCallMessageCallback(void *, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 gti2ReceiveFilterCallback(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 state;
    s32 result;

    state = M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE);
    if ((state != GT2_STATE_CONNECTED) && (state != GT2_STATE_PEER_CLOSED)) {
        return 1;
    }
    if (Vector_GetCount(M2C_FIELD(connection, s32 *, GT2_CONNECTION_FILTERS)) != 0) {
        if (gti2ReceiveFilterCallback(connection, 0, message, length, 0) != 0) {
            result = 1;
        } else {
            result = 0;
        }
        return result;
    }
    if (Gt2ConnectionCallMessageCallback(connection, message, length, 0) != 0) {
        return 1;
    }
    return 0;
}

/* Handle command 0 (application data) received on a GT2 control channel: hand the
   payload to the connection's receive filters, or to its message callback when it
   has no filters, flagged as coming from the control channel. A connection that is
   neither connected nor closing is closed instead of receiving the data. */
s32 gti2HandleDataCommand(void *connection,s32 message,s32 length) {
s32 Vector_GetCount(s32);
s32 Gt2ConnectionCallMessageCallback(void *,s32,s32,s32);
s32 gti2ReceiveFilterCallback(void *,s32,s32,s32,s32);
s32 state=M2C_FIELD(connection,s32 *,GT2_CONNECTION_STATE),r;
if(state!=GT2_STATE_CONNECTED&&state!=GT2_STATE_PEER_CLOSED){if(!Gt2CloseConnection((s32)connection))return 0;}
else {
if(Vector_GetCount(M2C_FIELD(connection,s32 *,GT2_CONNECTION_FILTERS))){if(gti2ReceiveFilterCallback(connection,0,message,length,1))r=1;else r=0;return r;}
if(!Gt2ConnectionCallMessageCallback(connection,message,length,1))return 0;
}
return 1;
}

/* Server side of the GT2 handshake: answer a client's CONNECT with a
 * CONNECT_ACCEPT carrying the response to its challenge and our own challenge,
 * remember the response we expect back, then await the client's RESPONSE. */
s32 gti2HandleConnect(void *connection, void *message, s32 length) {
    void gti2ComputeResponse(void *, void *);
    void gti2GetChallenge(void *);
    s32 gti2SendConnectAccept(void *, void *, void *);
    u8 response[32], challenge[32];

    if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) != GT2_STATE_AWAIT_CLIENT_CONNECT) return Gt2CloseConnection((s32)connection) != 0;
    if (length < GT2_RESPONSE_SIZE) return Gt2CloseConnection((s32)connection) != 0;
    gti2ComputeResponse(response, message);
    gti2GetChallenge(challenge);
    gti2ComputeResponse((u8 *)connection + GT2_CONNECTION_RESPONSE, challenge);
    if (!gti2SendConnectAccept(connection, response, challenge)) return 0;
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) = GT2_STATE_AWAIT_CLIENT_RESPONSE;
    return 1;
}

/* Client side of the GT2 handshake: handle the server's CONNECT_ACCEPT (the
 * response to our challenge plus the server's own challenge) and answer it with
 * our challenge response and the data queued for this connection. */
s32 gti2HandleConnectAccept(void *connection,void *message,s32 length) {
void gti2ComputeResponse(void *,void *);s32 gti2CheckResponse(void *,void *);s32 gti2SendClientResponse(void *,void *,s32,s32);
u8 response[32];
if(M2C_FIELD(connection,s32 *,GT2_CONNECTION_STATE)!=GT2_STATE_AWAIT_CONNECT_ACCEPT)return Gt2CloseConnection((s32)connection)!=0;
if(length<GT2_CONNECT_ACCEPT_SIZE)return Gt2CloseConnection((s32)connection)!=0;
if(!gti2CheckResponse(message,(u8 *)connection+GT2_CONNECTION_RESPONSE))return Gt2CloseConnection((s32)connection)!=0;
gti2ComputeResponse(response,(u8 *)message+GT2_RESPONSE_SIZE);
if(!gti2SendClientResponse(connection,response,M2C_FIELD(connection,s32 *,GT2_CONNECTION_DATA),M2C_FIELD(connection,s32 *,GT2_CONNECTION_DATA_LEN)))return 0;
if(M2C_FIELD(connection,void **,GT2_CONNECTION_DATA)){gpiFree(M2C_FIELD(connection,void **,GT2_CONNECTION_DATA));M2C_FIELD(connection,void **,GT2_CONNECTION_DATA)=0;}
M2C_FIELD(connection,s32 *,GT2_CONNECTION_STATE)=GT2_STATE_AWAIT_SERVER_ACCEPT;return 1;
}

/* Validate an incoming client's response and pass its payload to the connection-attempt callback. */
s32 gti2HandleClientResponse(void *connection, s32 message, s32 length) {
    s32 gti2CheckResponse(void *, void *); s32 gti2SendClosed(void *); s32 GetSystemTickMilliseconds(void); s32 Gt2InvokeConnectAttempt(void *, void *, s32, u16, s32, s32, s32);
    if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) != GT2_STATE_AWAIT_CLIENT_RESPONSE) return Gt2CloseConnection((s32)connection) != 0;
    if (length < GT2_RESPONSE_SIZE) return Gt2CloseConnection((s32)connection) != 0;
    if (!gti2CheckResponse((void *)message, connection + GT2_CONNECTION_RESPONSE)) return Gt2CloseConnection((s32)connection) != 0;
    if (!M2C_FIELD(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CONNECT_ATTEMPT)) {
        if (!gti2SendClosed(connection)) return 0;
        gti2MarkConnectionClosed(connection); return 1;
    }
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) = GT2_STATE_AWAIT_ACCEPT;
    return Gt2InvokeConnectAttempt(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), connection, M2C_FIELD(connection, s32 *, GT2_CONNECTION_IP), M2C_FIELD(connection, u16 *, GT2_CONNECTION_PORT), GetSystemTickMilliseconds() - M2C_FIELD(connection, s32 *, GT2_CONNECTION_START_TIME), message + GT2_RESPONSE_SIZE, length - GT2_RESPONSE_SIZE) != 0;
}

/* Client side of the GT2 handshake: handle the server's ACCEPT.  A connection
 * still waiting for it becomes connected and reports the connect event through
 * its callback; any other state is closed.  Returns 0 when a callback freed the
 * connection. */
s32 gti2HandleAccept(void *connection) {
    s32 Gt2ConnectionCallCallback();
    s32 closed;

    if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) != GT2_STATE_AWAIT_SERVER_ACCEPT) {
        if (Gt2CloseConnection(connection)) closed = 1;
        else closed = 0;
        return closed;
    }
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) = GT2_STATE_CONNECTED;
    if (Gt2ConnectionCallCallback(connection, GT2_EVENT_CONNECTED, 0, 0)) return 1;
    return 0;
}

/* GT2 command 5 handler (GTI2_CLOSE): the peer asked to close. A connection
 * still waiting for the server's ACCEPT is torn down normally; otherwise it is
 * marked closed, the peer's CLOSED is sent back, and the closure is reported to
 * the connection callback with the reason the peer gave. Returns 0 when the
 * callback freed the connection. */
s32 gti2HandleClose(void *connection, s32 reason, s32 length) {
s32 Gt2ConnectionCallCallback();
s32 gti2SendClosed();
s32 closed;
if (M2C_FIELD(connection,s32 *,GT2_CONNECTION_STATE)!=GT2_STATE_AWAIT_SERVER_ACCEPT) {
if (Gt2CloseConnection(connection)) closed=1; else closed=0;
return closed;
}
gti2MarkConnectionClosed(connection);
if (!gti2SendClosed(connection)) return 0;
if (Gt2ConnectionCallCallback(connection,2,reason,length)) return 1;
return 0;
}

#pragma push
#pragma opt_propagation off
s32 func_0205b758(void *arg0) {
    if (gti2SendClosed() == 0) {
        return 0;
    }
    if (gti2CloseConnection(arg0, 2, M2C_FIELD(arg0, s32 *, 0xC) != 6 ? 1 : 0) == 0) {
        return 0;
    }
    return 1;
}
#pragma pop
/* Increment the object's command counter and dispatch one of its commands (0-6). */
s32 Gt2DispatchCommand(void *object, s32 command, s32 param_a, s32 param_b) {
    s32 gti2HandleClientResponse(void *, s32, s32);
    M2C_FIELD(object, u16 *, 0x66)++;
    if (command == 0) { if (!gti2HandleDataCommand(object, param_a, param_b)) return 0; }
    else if (command == 1) { if (!gti2HandleConnect(object, (void *)param_a, param_b)) return 0; }
    else if (command == 2) { if (!gti2HandleConnectAccept(object, (void *)param_a, param_b)) return 0; }
    else if (command == 3) { if (!gti2HandleClientResponse(object, param_a, param_b)) return 0; }
    else if (command == 4) { if (!gti2HandleAccept(object)) return 0; }
    else if (command == 5) { if (!gti2HandleClose(object, param_a, param_b)) return 0; }
    else if (command == 6) { if (!func_0205b758(object)) return 0; }
    return 1;
}

void func_0205b89c(void *arg0, void *arg1) {
    Gt2CompareSequence(M2C_FIELD(arg0, u16 *, 0xC), M2C_FIELD(arg1, u16 *, 0xC));
}

/* Enqueue an outgoing command: insert a header record (offset/size/command/
   sequence) for command/sequence into the send queue kept sorted by sequence,
   copy the payload into the session's ring buffer, and acknowledge any numbered
   sequence gap that was filled. Returns 0 to retry, 1 when finished; *error is
   set when the sequence already exists or the queue rejected the record. */
s32 Gt2QueuePendingCommand(void *session,s32 command,u16 sequence,void *data,s32 size,s32 *error){
s32 Vector_GetCount(s32);void *Vector_GetItem(s32,s32);s32 gti2GetBufferFreeSpace(void *);void Vector_InsertSorted(s32,void *,void *);void gti2BufferWriteData(void *,void *,s32);s32 func_0205caac(void *,u16,u16);
s32 count=Vector_GetCount(M2C_FIELD(session,s32 *,0x5c));s32 i;Gt2PendingCommand record;void *prev;s32 nextSequence;
for(i=0;i<count;i++){u16 queued=M2C_FIELD(Vector_GetItem(M2C_FIELD(session,s32 *,0x5c),i),u16 *,12);if(queued==sequence){*error=0;return 1;}if(Gt2CompareSequence(queued,sequence)>0)break;}
if(gti2GetBufferFreeSpace(session+0x44)<size){*error=1;return 1;}
record.offset=M2C_FIELD(session,s32 *,0x4c);record.size=size;record.kind=command;record.sequence=sequence;
Vector_InsertSorted(M2C_FIELD(session,s32 *,0x5c),&record,func_0205b89c);
if(count+1!=Vector_GetCount(M2C_FIELD(session,s32 *,0x5c))){*error=1;return 1;}
gti2BufferWriteData(session+0x44,data,size);
if(count==0){if(!func_0205caac(session,M2C_FIELD(session,u16 *,0x66),(u16)(sequence-1)))return 0;}
else {nextSequence=M2C_FIELD(Vector_GetItem(M2C_FIELD(session,s32 *,0x5c),count),u16 *,12);if(nextSequence==sequence){
prev=Vector_GetItem(M2C_FIELD(session,s32 *,0x5c),count-1);
if((u16)Gt2CompareSequence(sequence,M2C_FIELD(prev,u16 *,12))>1){
if(!func_0205caac(session,(u16)(M2C_FIELD(prev,u16 *,12)+1),(u16)(sequence-1)))return 0;
}}}
*error=0;return 1;
}

/* Drop a command the dispatch loop has finished with: remove it from the
 * connection's pending-command queue, slide the queued commands that sit after it
 * in the buffer back over its bytes, then drop those bytes from the buffer. */
void Gt2RemovePendingCommand(void *connection, Gt2PendingCommand *command, s32 index) {
 void *Vector_GetItem(s32,s32);
 s32 offset,size,count,i,maxEnd;Gt2PendingCommand *entry;s32 end;
 offset=command->offset;size=command->size;maxEnd=0;Vector_RemoveItem(M2C_FIELD(connection,s32 *,GT2_CONNECTION_PENDING_QUEUE),index);count=Vector_GetCount(M2C_FIELD(connection,s32 *,GT2_CONNECTION_PENDING_QUEUE));i=0;if(count>0)do{entry=Vector_GetItem(M2C_FIELD(connection,s32 *,GT2_CONNECTION_PENDING_QUEUE),i);if(entry->offset>offset){entry->offset-=size;end=entry->offset+entry->size;if(maxEnd<=end)maxEnd=end;}i++;}while(i<count);gti2RemoveFromBuffer((char*)connection+GT2_CONNECTION_RECV_BUFFER,offset,size);
}

/* Dispatches, newest entry first, every queued incoming command whose sequence
 * is next due; a command whose dispatch fails stops the connection. */
s32 Gt2DispatchPendingCommands(void *connection) {
    s32 Vector_GetCount();
    void *Vector_GetItem();
    s32 Gt2DispatchCommand(void *, s32, s32, s32);
    s32 i;
    Gt2PendingCommand *command;

restart:
    for (i = Vector_GetCount(M2C_FIELD(connection, s32 *, GT2_CONNECTION_PENDING_QUEUE)) - 1; i >= 0; i--) {
        command = Vector_GetItem(M2C_FIELD(connection, s32 *, GT2_CONNECTION_PENDING_QUEUE), i);
        if (command->sequence == M2C_FIELD(connection, u16 *, GT2_RECV_SEQUENCE)) {
            if (Gt2DispatchCommand(connection, command->kind, M2C_FIELD(connection, s32 *, GT2_CONNECTION_RECV_BUFFER) + command->offset, command->size) == 0) return 0;
            Gt2RemovePendingCommand(connection, command, i);
            goto restart;
        }
    }
    return 1;
}

void Gt2NoteDataReceived(void *arg0) {
    s32 GetSystemTickMilliseconds();
    if (M2C_FIELD(arg0, s32 *, 0x90) != 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x90) = 1;
    M2C_FIELD(arg0, s32 *, 0x94) = GetSystemTickMilliseconds();
}

