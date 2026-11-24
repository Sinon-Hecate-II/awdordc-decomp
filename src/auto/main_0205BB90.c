/* 26 functions from 0x0205BB90 to 0x0205CB68 (main), found by ds-decomp. */
#include "common.h"
#include "gt2.h"
typedef struct { u8 a,b; } Unk05Bytes;
typedef struct { s32 a,b; s16 c,pad; s32 d; } Unk05Record;
/* The first two words of a queued Gt2SentCommand, read as one 8-byte load:
 * a = offset of the command's bytes in the send buffer, b = its byte size. */
typedef union { struct { s32 a,b; }; u64 whole; } Unk05Pair;
Unk05Pair *Vector_GetItem(s32,s32);

/* Handles one received GTI2 message in the small control format (types 0-7):
 * acknowledges the peer's sequence, then dispatches the command when it is the
 * next one expected, drops it when it is stale, or buffers it until its turn. */
s32 gti2HandleSmallMessage(void *session, s32 command, s32 buf, s32 len) {
    s32 Gt2CompareSequence(u16, s32);
    s32 gti2SendClosedAndClose(s32);
    s32 Gt2DispatchCommand(void *, s32, s32, s32);
    s32 Gt2QueuePendingCommand(void *, s32, s32, s32, s32, s32 *);
    s32 Gt2DispatchPendingCommands(void *);
    void Gt2NoteDataReceived(void *);
    s32 queueError;
    s32 sequence;
    s32 ok;
    if (len < 7) {
 if (Gt2CloseConnection(session)) ok=1; else ok=0;
 return ok;
}
    sequence = Gt2ReadShort(buf, 3);
    if (!Gt2AckSentData((s32)session, Gt2ReadShort(buf, 5))) return 0;
    if (sequence == M2C_FIELD(session, u16 *, GT2_RECV_SEQUENCE)) {
        Gt2NoteDataReceived(session);
        if (!Gt2DispatchCommand(session,command,buf+7,len-7)) return 0;
        if (Gt2DispatchPendingCommands(session)) ok=1; else ok=0;
 return ok;
    }
    if (((s32 (*)(s32,s32))Gt2CompareSequence)(sequence,M2C_FIELD(session,u16 *,GT2_RECV_SEQUENCE)) < 0) {
        Gt2NoteDataReceived(session);
        return 1;
    }
    if (!Gt2QueuePendingCommand(session,command,sequence,buf+7,len-7,&queueError)) return 0;
    if (queueError && !gti2SendClosedAndClose((s32)session)) return 0;
    return 1;
}

/* Handle a GT2 acknowledgement control message (type 100): its two-byte payload
 * is the highest sequence number the peer acknowledged, so drop every sent command
 * up to it.  A message of any other length is malformed and closes the connection.
 * Returns 1 when it was handled, 0 when the close failed and the socket is gone. */
s32 gti2HandleAck(M2C_UNK connection, M2C_UNK message, s32 length) {
    s32 Gt2ReadShort(M2C_UNK, M2C_UNK);
    s32 Gt2CloseConnection(M2C_UNK);
    s32 Gt2AckSentData(M2C_UNK, s32);
    s32 ok;

    if (length != 2) {
        if (Gt2CloseConnection(connection) != 0) {
            ok = 1;
        } else {
            ok = 0;
        }
        return ok;
    }
    if (Gt2AckSentData(connection, Gt2ReadShort(message, 0)) != 0) {
        return 1;
    }
    return 0;
}

/* Handle a resend request (GT2 control message 101): the payload holds the first
 * sequence number to resend, and, when it is four bytes long, the last one.
 * Resend every unacknowledged sent command whose sequence lies in that range;
 * close the connection on a malformed length.  Returns 1 on success, 0 when a
 * resend fails. */
s32 gti2HandleResendRequest(void *session, void *message, s32 size) {
    s32 Vector_GetCount(s32);
    s32 Gt2CompareSequence(u16, s32);
    s32 gti2ResendPendingCommand(void *, void *);
    s32 first;
    s32 last;
    s32 count;
    s32 i;
    void *command;

    first = Gt2ReadShort((s32)message, 0);
    if (size == 2) {
        last = first;
    } else if (size == 4) {
        last = Gt2ReadShort((s32)message, 2);
    } else {
        return Gt2CloseConnection(session) != 0;
    }
    count = Vector_GetCount(M2C_FIELD(session, s32 *, GT2_CONNECTION_ACK_QUEUE));
    for (i = 0; i < count; i++) {
        command = Vector_GetItem(M2C_FIELD(session, s32 *, GT2_CONNECTION_ACK_QUEUE), i);
        if ((Gt2CompareSequence(M2C_FIELD(command, u16 *, GT2_SENT_COMMAND_SEQUENCE), first) >= 0) &&
            (Gt2CompareSequence(M2C_FIELD(command, u16 *, GT2_SENT_COMMAND_SEQUENCE), last) <= 0) &&
            (gti2ResendPendingCommand(session, command) == 0)) {
            return 0;
        }
    }
    return 1;
}

s32 func_0205be04(s32 a, void *b, s32 c) {
    s32 func_0205cb38(s32, void *, s32);
    return func_0205cb38(a,b,c);
}

/* Handle a GT2 ping control message (type 103): the eight-byte payload is the
 * four-byte "time" magic followed by the sender's 32-bit timestamp.  Compute
 * the round-trip time from that timestamp and hand it to the connection's ping
 * callback.  Malformed or unexpected pings are ignored. */
s32 gti2HandlePing(void *connection, void *message, s32 length) {
    s32 GetSystemTickMilliseconds();
    s32 gti2PingCallback(void *, s32);
    s32 ByteCompareN(void *, M2C_UNK *, s32);
    extern M2C_UNK gti2PingMagic;
    s32 pingTimestamp;
    u8 b0, b1;
    volatile u8 *dst;
    if (!M2C_FIELD(connection, s32 *, GT2_CONNECTION_CALLBACK_PING)) return 1;
    if (length != 8) return 1;
    if (ByteCompareN(message, &gti2PingMagic, 4)) return 1;
    dst = (volatile u8 *)&pingTimestamp;
    b0 = M2C_FIELD(message, volatile u8 *, 4);
    b1 = M2C_FIELD(message, volatile u8 *, 5);
    M2C_FIELD(dst, volatile u8 *, 0) = b0;
    M2C_FIELD(dst, volatile u8 *, 1) = b1;
    b0 = M2C_FIELD(message, volatile u8 *, 6);
    b1 = M2C_FIELD(message, volatile u8 *, 7);
    M2C_FIELD(dst, volatile u8 *, 2) = b0;
    M2C_FIELD(dst, volatile u8 *, 3) = b1;
    return gti2PingCallback(connection, GetSystemTickMilliseconds() - pingTimestamp) != 0;
}

#pragma push
#pragma scheduling off
s32 func_0205bea4(void *arg0) {
    s32 gti2CloseConnection(void *, M2C_UNK, M2C_UNK);
    u32 var_r2;
    u32 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0xC);
    if (temp_r1 == 7) {
        return 1;
    }
    if (temp_r1 == 6) {
        var_r2 = 0;
    } else {
        var_r2 = 1;
    }
    if (gti2CloseConnection(arg0, 2, var_r2) == 0) {
        return 0;
    }
    return 1;
}
#pragma pop
/* Dispatch a GT2 control message to its handler: the type byte (100..104) follows
 * the two-byte magic and the control payload starts after it, so every handler
 * but 102 and 104 gets MESSAGE+3 with the length minus three.  Returns 0 when the
 * handler fails (the connection is then dropped) and 1 otherwise, unknown types
 * included. */
s32 gti2HandleLargeMessage(void *session, s32 messageType, void *message, s32 size) {
    s32 gti2HandleResendRequest(void *, void *, s32);
    s32 len = size - 3;

    if (messageType == 100) {
        if (!gti2HandleAck((s32) session, (s32) ((char *) message + 3), len)) return 0;
    } else if (messageType == 101) {
        if (!gti2HandleResendRequest(session, (char *) message + 3, len)) return 0;
    } else if (messageType == 102) {
        if (!func_0205be04((s32) session, message, size)) return 0;
    } else if (messageType == 103) {
        if (!gti2HandlePing(session, (char *) message + 3, len)) return 0;
    } else if (messageType == 104) {
        if (!func_0205bea4(session)) return 0;
    }
    return 1;
}

/* GT2 message dispatcher for one received socket message: accept or reject new
   connections, close dead ones, and route the payload to the data handler or to
   the control-message handlers (small type < 8, large type >= 8). */
s32 gti2HandleMessage(void *socket,void *message,s32 len,M2C_UNK address,M2C_UNK port) {
void *func_0205cca0(void *,M2C_UNK,M2C_UNK);
s32 gti2DumpCallback(void *,void *,M2C_UNK,M2C_UNK,s32,s32,s32,s32);
s32 ByteCompareN(void *,M2C_UNK *,s32);
s32 gti2UnrecognizedMessageCallback(void *,M2C_UNK,M2C_UNK,void *,s32,s32 *);
s32 gti2SendClosedOnSocket(s32,s32,u16);
s32 func_0205a860(void *,void **,M2C_UNK,M2C_UNK);
void gti2SendClosed(void *);s32 gti2HandleData(void *,void *,s32);
s32 Gt2CloseConnection(); s32 gti2HandleSmallMessage(void *,s32,s32,s32);s32 gti2HandleLargeMessage(void *,s32,void *,s32);
extern M2C_UNK gGt2Magic;
void *connection,*connection2; s32 handled,isControl,acceptResult,msgType;
u8 *buf=message;
connection=func_0205cca0(socket,address,port);
if(M2C_FIELD(socket,s32*,0x2c)!=0){
if(!gti2DumpCallback(socket,connection,address,port,0,(s32)buf,len,0))return 0;
}
if(len>2 && !ByteCompareN(buf,&gGt2Magic,2))isControl=1;else isControl=0;
if(connection==0){
if(!gti2UnrecognizedMessageCallback(socket,address,port,buf,len,&handled))return 0;
if(handled)return 1;
if(isControl && buf[2]==1)goto incoming;
if(isControl && buf[2]==104)goto accepted1;
if(!((s32 (*)(void *,s32,s32))gti2SendClosedOnSocket)(socket,address,port))return 0;
accepted1:return 1;
incoming:
if(M2C_FIELD(socket,s32*,0x20)==0)return 1;
acceptResult=func_0205a860(socket,&connection,address,port);
if(acceptResult==0)goto connected;
if(acceptResult==5)goto accepted2;
if(!((s32 (*)(void *,s32,s32))gti2SendClosedOnSocket)(socket,address,port))return 0;
accepted2:return 1;
}
connected:
connection2=connection;
if(M2C_FIELD(connection2,s32*,0xc)==7){
if(isControl && buf[2]==104)goto accepted3;
if(!((s32 (*)(void *))gti2SendClosed)(connection2))return 0;
accepted3:return 1;
}
if(isControl && len>=4 && !ByteCompareN(buf+2,&gGt2Magic,2)){buf+=2;len-=2;isControl=0;}
if(!isControl)return gti2HandleData(connection2,buf,len)!=0;
msgType=buf[2];
if(msgType<0)return Gt2CloseConnection(connection2)!=0;
if(msgType<8)return gti2HandleSmallMessage(connection2,msgType,(s32)buf,len)!=0;
return gti2HandleLargeMessage(connection2,msgType,buf,len)!=0;
}

/* Looks up the entry for the given connection/key; validates or refreshes it. */
s32 func_0205c244(void *conn, M2C_UNK arg1, M2C_UNK arg2) {
    s32 GetSystemTickMilliseconds();
    s32 gti2DumpCallback(void *, void *, M2C_UNK, M2C_UNK, s32, s32, s32, s32);
    s32 gti2CloseConnection(void *, M2C_UNK, M2C_UNK);
    void *func_0205cca0();
    void *entry;

    entry = func_0205cca0();
    if ((M2C_FIELD(conn, s32 *, 0x2C) != 0) &&
        (gti2DumpCallback(conn, entry, arg1, arg2, 1, 0, 0, 0) == 0)) {
        return 0;
    }
    if (entry == NULL) {
        return 1;
    }
    if (M2C_FIELD(entry, s32 *, 0xC) == 0) {
        if ((M2C_FIELD(entry, u32 *, 0x20) == 0) ||
            ((u32)(GetSystemTickMilliseconds() - M2C_FIELD(entry, u32 *, 0x1C)) < M2C_FIELD(entry, u32 *, 0x20))) {
            return 1;
        }
        if (gti2CloseConnection(entry, 6, 1) == 0) {
            return 0;
        }
    } else {
        if (gti2CloseConnection(entry, 2, 1) == 0) {
            return 0;
        }
    }
    return 1;
}

#pragma optimization_level 3
s32 func_0205c344(void *conn) {
    s32 ghiSocketCanRecv(s32);
    s32 ghiRecvFrom(s32, void *, s32, s32, void *, s32 *);
    s32 ghiGetLastSocketError(s32);
    s32 func_0205c244(void *, M2C_UNK, M2C_UNK);
    void func_0205d49c(void *);
    s32 gti2HandleMessage(void *, void *, s32, M2C_UNK, M2C_UNK);
    u8 buffer[0x5dc];
    struct {
        u16 family;
        u16 port;
        u32 address;
    } peer;
    s32 length;
    s32 received;
    s32 error;

    if (ghiSocketCanRecv(M2C_FIELD(conn, s32 *, 0)) != 0) {
        do {
            length = sizeof(peer);
            received = ghiRecvFrom(M2C_FIELD(conn, s32 *, 0), buffer, sizeof(buffer), 0,
                                   &peer, &length);
            switch (received) {
            case 0:
                error = ghiGetLastSocketError(M2C_FIELD(conn, s32 *, 0));
                if (error == -15) {
                    if (!func_0205c244(conn, peer.address,
                                      (u16)(((peer.port >> 8) & 0xff) | ((peer.port << 8) & 0xff00)))) {
                        return 0;
                    }
                } else if (error != -35) {
                    func_0205d49c(conn);
                    return 0;
                }
                break;
            default:
                if (!gti2HandleMessage(conn, buffer, received, peer.address,
                                       (u16)(((peer.port >> 8) & 0xff) | ((peer.port << 8) & 0xff00)))) {
                    return 0;
                }
            }
        } while (ghiSocketCanRecv(M2C_FIELD(conn, s32 *, 0)) != 0);
    }
    return 1;
}
#pragma optimization_level reset
/* Queue a sent command on the connection's acknowledgement list: record where its
 * bytes start in the send buffer, its length, its sequence number and when it was
 * sent. Returns 1 when the list grew, 0 when the entry was not added. */
s32 gti2QueueSentCommand(void *connection, s16 sequence, s32 size) {
    Gt2SentCommand sent = {0};
    s32 count;

    sent.offset = M2C_FIELD(connection, s32 *, GT2_SEND_BUFFER_LEN);
    sent.size = size;
    sent.sequence = sequence;
    sent.lastSent = GetSystemTickMilliseconds();
    count = Vector_GetCount(M2C_FIELD(connection, s32 *, GT2_CONNECTION_ACK_QUEUE));
    Vector_Append(M2C_FIELD(connection, s32 *, GT2_CONNECTION_ACK_QUEUE), &sent);
    return count + 1 == Vector_GetCount(M2C_FIELD(connection, s32 *, GT2_CONNECTION_ACK_QUEUE));
}

/* Starts the next command in the connection's send buffer: queues the command's
 * acknowledgement record, then writes the GT2 magic, the command type, the
 * command's sequence number and the sequence number being acknowledged.  When
 * the buffer has no room for the command the connection is closed instead, and
 * *status is set to 1; *status is 0 when the command was started.  Returns 1
 * when the caller may go on, 0 when the connection was freed. */
s32 gti2BeginCommand(M2C_UNK p, M2C_UNK mode, M2C_UNK arg2, s32 *status) {
    extern M2C_UNK gGt2Magic;
    s32 gti2GetBufferFreeSpace(void *);
    s32 gti2SendClosedAndClose(M2C_UNK);
    s32 gti2QueueSentCommand(void *, s16, s32);
    void gti2BufferWriteData(void *, M2C_UNK, s32);
    void gti2BufferWriteByte(void *, s32);
    void gti2BufferWriteUShort(void *, s32);
    s32 free;

    free = gti2GetBufferFreeSpace((void *)((char *)p + GT2_CONNECTION_SEND_BUFFER));
    if (free < arg2) {
        s32 r = gti2SendClosedAndClose(p);
        if (r == 0) {
            return 0;
        }
        *status = 1;
        return 1;
    }
    if (!((s32 (*)(void *,u32,s32))gti2QueueSentCommand)((void *)p, M2C_FIELD(p, u16 *, GT2_CONNECTION_SEND_SEQUENCE), arg2)) {
        s32 r = gti2SendClosedAndClose(p);
        if (r == 0) {
            return 0;
        }
        *status = 1;
        return 1;
    }
    gti2BufferWriteData((void *)((char *)p + GT2_CONNECTION_SEND_BUFFER), &gGt2Magic, 2);
    gti2BufferWriteByte((void *)((char *)p + GT2_CONNECTION_SEND_BUFFER), (s32)(mode & 0xff));
    {
        u16 sequence = M2C_FIELD(p, u16 *, GT2_CONNECTION_SEND_SEQUENCE);
        M2C_FIELD(p, u16 *, GT2_CONNECTION_SEND_SEQUENCE) = sequence + 1;
        gti2BufferWriteUShort((void *)((char *)p + GT2_CONNECTION_SEND_BUFFER), sequence);
    }
    gti2BufferWriteUShort((void *)((char *)p + GT2_CONNECTION_SEND_BUFFER), M2C_FIELD(p, u16 *, GT2_RECV_SEQUENCE));
    *status = 0;
    return 1;
}

#pragma scheduling off
/* Send the command most recently queued on the connection's acknowledgement
 * list: gti2BeginCommand queues each reliable command there, and this sends its
 * bytes from the send buffer, which also clears the pending-acknowledgement
 * flag.  Returns 1 when the command was sent, 0 otherwise. */
s32 gti2EndReliableMessage(s32 connection) {
    extern M2C_UNK gAssertExprAckLen, gAssertMessageFileName, gAssertNameEndReliableMessage;
    s32 count = Vector_GetCount(M2C_FIELD(connection, s32 *, GT2_CONNECTION_ACK_QUEUE));
    Unk05Pair *command;
    s32 sent;

    if (count <= 0) AssertFailed(&gAssertExprAckLen, &gAssertMessageFileName, &gAssertNameEndReliableMessage, 0x475);
    command = Vector_GetItem(M2C_FIELD(connection, s32 *, GT2_CONNECTION_ACK_QUEUE), count - 1);
    if (gti2SendRaw(connection, M2C_FIELD(connection, s32 *, GT2_CONNECTION_SEND_BUFFER) + command->a, command->b)) {
        M2C_FIELD(connection, s32 *, GT2_CONNECTION_ACK_PENDING) = 0;
        sent = 1;
    } else {
        sent = 0;
    }
    return sent;
}
#pragma scheduling reset
/* Send an application message as a reliable GT2 data command: start the command
 * with room for its 7-byte header, append the payload to the send buffer and
 * queue it.  A command that could not be started ends the connection and still
 * reports success. */
s32 gti2SendReliableMessage(s32 connection, M2C_UNK message, s32 length) {
    s32 status;

    if (gti2BeginCommand(connection, GTI2_DATA, length + 7, &status) == 0) {
        return 0;
    }
    if (status != 0) {
        return 1;
    }
    gti2BufferWriteData(connection + GT2_CONNECTION_SEND_BUFFER, message, length);
    if (gti2EndReliableMessage(connection) != 0) {
        return 1;
    }
    return 0;
}

/* Client side of the GT2 handshake: send the CONNECT command carrying our 32-byte
 * challenge.  Returns 0 when the connection was freed, 1 otherwise. */
s32 gti2SendConnect(s32 connection, M2C_UNK challenge) {
    M2C_UNK gti2BufferWriteData(s32, M2C_UNK, M2C_UNK);
    s32 status;

    if (gti2BeginCommand(connection, GTI2_CONNECT, GT2_CONNECT_SIZE, &status) == 0) {
        return 0;
    }
    if (status != 0) {
        return 1;
    }
    gti2BufferWriteData(connection + GT2_CONNECTION_SEND_BUFFER, challenge, GT2_RESPONSE_SIZE);
    if (gti2EndReliableMessage(connection) != 0) {
        return 1;
    }
    return 0;
}

/* Server side of the GT2 handshake: send the CONNECT_ACCEPT command carrying
 * our response to the client's challenge followed by our own 32-byte challenge,
 * then start the connection's clock from the tick the command was sent at. */
s32 gti2SendConnectAccept(s32 connection, s32 response, s32 challenge) {
    s32 status;
    s32 sent;
    if (!gti2BeginCommand(connection, 2, 0x47, &status)) return 0;
    if (status) return 1;
    gti2BufferWriteData(connection + GT2_CONNECTION_SEND_BUFFER, response, GT2_RESPONSE_SIZE);
    gti2BufferWriteData(connection + GT2_CONNECTION_SEND_BUFFER, challenge, GT2_RESPONSE_SIZE);
    if (gti2EndReliableMessage(connection) == 0) sent = 0;
    else {
        M2C_FIELD(connection, s32 *, GT2_CONNECTION_START_TIME) = M2C_FIELD(connection, s32 *, GT2_CONNECTION_LAST_SENT);
        sent = 1;
    }
    return sent;
}

/* Client side of the GT2 handshake: send the CLIENT_RESPONSE command carrying
 * our 32-byte response to the server's challenge followed by the caller's
 * connection data.  Returns 0 when the connection was freed, 1 otherwise. */
s32 gti2SendClientResponse(s32 connection, s32 response, s32 data, s32 len) {
    s32 status;

    if (gti2BeginCommand(connection, GTI2_CLIENT_RESPONSE, len + 7 + GT2_RESPONSE_SIZE, &status) == 0) {
        return 0;
    }
    if (status != 0) {
        return 1;
    }
    gti2BufferWriteData(connection + GT2_CONNECTION_SEND_BUFFER, response, GT2_RESPONSE_SIZE);
    gti2BufferWriteData(connection + GT2_CONNECTION_SEND_BUFFER, data, len);
    if (gti2EndReliableMessage(connection) != 0) {
        return 1;
    }
    return 0;
}

/* Accept the connection: send the payload-less GTI2_ACCEPT command (its command
 * header only).  Returns 0 when the connection was freed, 1 otherwise. */
s32 gti2SendAccept(M2C_UNK connection) {
    s32 gti2BeginCommand(M2C_UNK, M2C_UNK, M2C_UNK, s32 *);
    s32 gti2EndReliableMessage(M2C_UNK);
    s32 status;

    if (gti2BeginCommand(connection, GTI2_ACCEPT, GT2_COMMAND_HEADER_SIZE, &status) == 0) {
        return 0;
    }
    if (status != 0) {
        return 1;
    }
    if (gti2EndReliableMessage(connection) != 0) {
        return 1;
    }
    return 0;
}

/* Send the CLOSE command carrying the reason string `reason` of `length` bytes:
 * start a GTI2_CLOSE command with room for the seven-byte command header plus
 * the reason, write the reason after the header and queue it for sending.
 * Returns 0 when the connection was freed, 1 otherwise (a command with no room
 * in the send buffer is dropped and *status stays 0). */
s32 gti2SendClose(s32 connection, M2C_UNK reason, s32 length) {
    s32 status;

    if (gti2BeginCommand(connection, GTI2_CLOSE, length + 7, &status) == 0) {
        return 0;
    }
    if (status != 0) {
        return 1;
    }
    gti2BufferWriteData(connection + GT2_CONNECTION_SEND_BUFFER, reason, length);
    if (gti2EndReliableMessage(connection) != 0) {
        return 1;
    }
    return 0;
}

/* Acknowledge the peer's close with a payload-less GTI2_CLOSED command (its
 * command header only).  Returns 0 when the connection was freed, 1 otherwise. */
s32 gti2SendClosedAck(M2C_UNK connection) {
    s32 status;

    if (gti2BeginCommand(connection, GTI2_CLOSED, GT2_COMMAND_HEADER_SIZE, &status) == 0) {
        return 0;
    }
    if (status != 0) {
        return 1;
    }
    if (gti2EndReliableMessage(connection) != 0) {
        return 1;
    }
    return 0;
}

/* Send an empty GTI2_PING command (its command header only); the peer answers it
 * with a sequence acknowledgement.  Returns 0 when the connection was freed, 1
 * otherwise. */
s32 gti2SendPing(M2C_UNK connection) {
    s32 status;

    if (gti2BeginCommand(connection, GTI2_PING, GT2_COMMAND_HEADER_SIZE, &status) == 0) {
        return 0;
    }
    if (status != 0) {
        return 1;
    }
    if (gti2EndReliableMessage(connection) != 0) {
        return 1;
    }
    return 0;
}

/* Send an application message the unreliable way, as a single datagram with no
 * acknowledgement: a message that does not begin with the GT2 magic is sent
 * exactly as given, while one that does is escaped with an extra magic first (so
 * the peer does not take it for a control message) by copying it into the
 * connection's send buffer, sending it from there and removing it again. */
s32 gti2SendUnreliable(void *connection, M2C_UNK *message, s32 len) {
    s32 gti2GetBufferFreeSpace(void *);
    s32 ByteCompareN(void *, M2C_UNK *, s32);
    s32 gti2SendRaw(s32, void *, s32);
    M2C_UNK gti2BufferWriteData(M2C_UNK, M2C_UNK, M2C_UNK);
    void gti2RemoveFromBuffer(void *, M2C_UNK, s32);
    extern M2C_UNK gGt2Magic;
    s32 sendPos;
    s32 sendBase;
    s32 escapedLen;

    if ((len < 2) || (ByteCompareN(message, &gGt2Magic, 2) != 0)) {
        if (gti2SendRaw((s32)connection, message, len) == 0) {
            return 0;
        }
        return 1;
    }
    escapedLen = len + 2;
    if (gti2GetBufferFreeSpace((Gt2Buffer *)((char *)connection + GT2_CONNECTION_SEND_BUFFER)) < escapedLen) {
        return 1;
    }
    sendBase = M2C_FIELD(connection, s32 *, 0x50);
    sendPos = M2C_FIELD(connection, s32 *, 0x58);
    gti2BufferWriteData((M2C_UNK)((char *)connection + GT2_CONNECTION_SEND_BUFFER), (M2C_UNK)&gGt2Magic, 2);
    gti2BufferWriteData((M2C_UNK)((char *)connection + GT2_CONNECTION_SEND_BUFFER), (M2C_UNK)message, len);
    if (gti2SendRaw((s32)connection, (void *)(sendBase + sendPos), escapedLen) == 0) {
        return 0;
    }
    gti2RemoveFromBuffer((Gt2Buffer *)((char *)connection + GT2_CONNECTION_SEND_BUFFER), -1, escapedLen);
    return 1;
}

s32 func_0205ca48(void *p){
    extern M2C_UNK gGt2Magic;
    void *q=p;
    u8 *g=(u8*)&gGt2Magic;
    u8 a=g[0], b=g[1];
    u8 buf[5];
    buf[2]=0x64; buf[0]=a; buf[1]=b;
    func_0205b0ec(buf,3,M2C_FIELD(q,u16 *,0x66));
    if(gti2SendRaw(q,buf,5)){M2C_FIELD(q,s32 *,0x90)=0;return 1;}
    return 0;
}

s32 func_0205caac(void *p, s32 arg1, s32 arg2) {
extern M2C_UNK gGt2Magic;
u8 buf[8]; u32 n=0; u8 *q=buf;
*(Unk05Bytes *)buf=*(Unk05Bytes *)&gGt2Magic;
buf[2]=0x65;
func_0205b0ec(buf, n+3, arg1); n+=5;
if((u32)arg2!=(u32)arg1){func_0205b0ec(buf,n,arg2); n+=2;}
if(gti2SendRaw(p,buf,n)==0)return 0; return 1;
}

s32 func_0205cb38(s32 a,void *b,s32 c) { s32 gti2SendRaw(s32,void *,s32); M2C_FIELD(b,u8 *,2)=103; return gti2SendRaw(a,b,c); }

void gti2SendClosed(void *arg0) {
    M2C_UNK gti2SendClosedOnSocket(s32, s32, u16);
    gti2SendClosedOnSocket(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, u16 *, 4));
}

