/* 14 functions from 0x0204FED0 to 0x02050C24 (main), found by ds-decomp. */
#include "common.h"

typedef struct { s32 unk_0; s32 unk_4; } Unk02050838Pair;

/* Format an integer as decimal text and append it to a gpi connection's output
 * buffer as a field. */
void gpiAppendIntField(M2C_UNK connection, M2C_UNK buffer, s32 value) {
    s32 StringFormat(void *, void *, ...);
    void gpiAppendStringField(M2C_UNK, M2C_UNK, void *);
    extern M2C_UNK gGpiFieldIntFormat;
    u8 buf[16];

    StringFormat(buf, &gGpiFieldIntFormat, value);
    gpiAppendStringField(connection, buffer, buf);
}

s32 gpiSendOrBufferChar(M2C_UNK arg0,s32 arg1,s8 *arg2,M2C_UNK arg3,M2C_UNK *arg4,s32 *arg5,M2C_UNK *arg6) {
s32 ghiSend(M2C_UNK,s8 *,M2C_UNK,M2C_UNK);
s32 ghiGetLastSocketError(M2C_UNK);
void gpiCallErrorCallback(void **,s32,s32);
M2C_UNK gpiLogMessage(M2C_UNK,M2C_UNK *,M2C_UNK *);
M2C_UNK gpiSetError(M2C_UNK,M2C_UNK,M2C_UNK *);
extern M2C_UNK data_020fdfb4;
extern M2C_UNK data_020fdfdc;
s8 *buf; s32 r; s32 e;
buf=(s8 *)arg6;
r=ghiSend(arg1,arg2,arg3,0);
if(r==-1) {
e=ghiGetLastSocketError(arg1);
if(e!=-6 && e!=-26 && e!=-76) {
if(buf[0]==80 && buf[1]==82) return 3;
gpiSetError(arg0,5,&data_020fdfb4);
gpiCallErrorCallback(arg0,3,0);
return 3;
}
*arg5=0; *arg4=0;
} else {
if(r!=0) { *arg5=r; *arg4=0; }
if(r!=0) goto done;
gpiLogMessage(arg0,&data_020fdfdc,(M2C_UNK *)buf);
*arg5=0; *arg4=1;
}
done:
return 0;
}

/* Send one character to the peer's socket; when nothing is queued in the peer's
 * send buffer and the socket would block, append it to that buffer instead.
 * Returns a gpi error code (0 on success). */
s32 gpiSendOrBufferSingleChar(M2C_UNK connection, void *peer, s8 ch, M2C_UNK unused) {
    s32 Vector_GetCount(s32);
    s32 gpiAppendChar(M2C_UNK, void *, s8);
    s32 gpiSendOrBufferChar(M2C_UNK, s32, s8 *, M2C_UNK, M2C_UNK *, s32 *, M2C_UNK *);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fdef8;
    extern M2C_UNK gGpiBufferFileName;
    extern M2C_UNK gGpiAssertOutputBuffer;
    extern M2C_UNK data_020fe024;
    M2C_UNK wouldBlock;
    s32 sent;

    if (M2C_FIELD(peer, s32 *, 0x28) == 0) {
        AssertFailed(&gGpiAssertOutputBuffer, &gGpiBufferFileName, &data_020fdef8, 0xde);
    }
    /* Only talk to the socket while the peer's send buffer is empty. */
    if (((M2C_FIELD(peer, s32 *, 0x30) - M2C_FIELD(peer, s32 *, 0x34)) == 0) &&
        (Vector_GetCount(M2C_FIELD(peer, s32 *, 0x38)) == 0)) {
        s32 result = gpiSendOrBufferChar(connection, M2C_FIELD(peer, s32 *, 8), &ch, 1, &wouldBlock, &sent, &data_020fe024);
        if (result != 0) {
            return result;
        }
        if (sent != 0) {
            return 0;
        }
    }
    return gpiAppendChar(connection, peer + 0x28, ch);
}

s32 gpiSendOrBufferStringLen(M2C_UNK connection, M2C_UNK peer, M2C_UNK string, s32 stringLen) {
    s32 Vector_GetCount(s32);
    M2C_UNK gpiAppendStringToBufferLen(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 gpiSendOrBufferChar(M2C_UNK, s32, s8 *, M2C_UNK, M2C_UNK *, s32 *, M2C_UNK *);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fdf24;
    extern M2C_UNK gGpiBufferFileName;
    extern M2C_UNK data_020fe000;
    extern M2C_UNK data_020fe024;
    M2C_UNK unusedStatus;
    s32 bytesSent;
    s32 offset;
    s32 result;

    /* Send string to peer, buffering the bytes that cannot be sent immediately. */
    if (M2C_FIELD(peer, s32 *, 0x28) == 0) {
        AssertFailed(&data_020fe000, &gGpiBufferFileName, &data_020fdf24, 0xfb);
    }
    offset = 0;
    if (stringLen == 0) {
        return offset;
    }
    if (((M2C_FIELD(peer, s32 *, 0x30) - M2C_FIELD(peer, s32 *, 0x34)) == 0) &&
        (Vector_GetCount(M2C_FIELD(peer, s32 *, 0x38)) == 0)) {
        do {
            result = gpiSendOrBufferChar(connection, M2C_FIELD(peer, s32 *, 8), (s8 *)(string + offset), stringLen, &unusedStatus, &bytesSent, &data_020fe024);
            if (result != 0) {
                return result;
            }
            if (bytesSent != 0) {
                stringLen -= bytesSent;
                offset += bytesSent;
            }
        } while (bytesSent != 0 && stringLen != 0);
    }
    if (stringLen != 0) {
        result = gpiAppendStringToBufferLen(connection, peer + 0x28, string + offset, stringLen);
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

/* Send `string` to `peer` over `connection`, buffering the bytes the socket
 * cannot take yet; the string's length is measured here. */
void gpiSendString(M2C_UNK connection, M2C_UNK peer, M2C_UNK string) {
    M2C_UNK gpiSendOrBufferStringLen(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 StringLength(M2C_UNK);

    gpiSendOrBufferStringLen(connection, peer, string, StringLength(string));
}

/* Receive from the connection's socket into its gpi receive buffer: grow the
   buffer by 0x800 bytes when nearly full and keep reading until 0x20000 bytes
   have arrived, the peer closes, or a fatal socket error occurs; report the
   bytes read and whether the connection closed. */
s32 gpiReceiveData(M2C_UNK connection, s32 sock, void *inputBuffer, s32 *bytesRead, s32 *connClosed, M2C_UNK tag) {
    void *gpiRealloc(void *, s32);
    s32 ghiRecv(s32, void *, s32, s32);
    s32 ghiGetLastSocketError(s32);
    M2C_UNK gpiSetErrorString(M2C_UNK, M2C_UNK *);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK gGpiBufferFileName;
    extern M2C_UNK gGpiRecvToBufferName;
    extern M2C_UNK gGpiAssertSockValid;
    extern M2C_UNK gGpiAssertInputBuffer;
    extern M2C_UNK gGpiAssertBytesRead;
    extern M2C_UNK gGpiAssertConnClosed;
    extern M2C_UNK gGpiRecvOutOfMemory;
    extern M2C_UNK gGpiRecvError;
    extern M2C_UNK gGpiMsgRecvClosed;
    extern M2C_UNK gGpiMsgRecvTotal;
    GPIBuffer *buf;
    void *data;
    s32 used;
    s32 capacity;
    s32 received;
    s32 totalRead;
    s32 connectionClosed;
    s32 socketError;

    buf = (GPIBuffer *)inputBuffer;

    if (sock == -1) {
        AssertFailed(&gGpiAssertSockValid, &gGpiBufferFileName, &gGpiRecvToBufferName, 0x150);
    }
    if (inputBuffer == 0) {
        AssertFailed(&gGpiAssertInputBuffer, &gGpiBufferFileName, &gGpiRecvToBufferName, 0x151);
    }
    if (bytesRead == 0) {
        AssertFailed(&gGpiAssertBytesRead, &gGpiBufferFileName, &gGpiRecvToBufferName, 0x152);
    }
    if (connClosed == 0) {
        AssertFailed(&gGpiAssertConnClosed, &gGpiBufferFileName, &gGpiRecvToBufferName, 0x153);
    }

    used = buf->len;
    data = buf->data;
    capacity = buf->size;
    totalRead = 0;
    connectionClosed = totalRead;

    for (;;) {
        if (used + 0x800 > capacity) {
            capacity = used + 0x800;
            data = gpiRealloc(data, capacity + 1);
            if (data == 0) {
                gpiSetErrorString(connection, &gGpiRecvOutOfMemory);
                return 1;
            }
        }
        received = ghiRecv(sock, (char *)data + used, capacity - used, 0);
        if (received == -1) {
            socketError = ghiGetLastSocketError(sock);
            if (socketError != -6 && socketError != -0x1A && socketError != -0x4C) {
                gpiSetErrorString(connection, &gGpiRecvError);
                return 3;
            }
        } else if (received == 0) {
            connectionClosed = 1;
            gpiLogMessage(connection, &gGpiMsgRecvClosed, (M2C_UNK *)tag);
        } else {
            used += received;
            totalRead += received;
        }

        *((char *)data + used) = 0;

        if (received == -1) {
            break;
        }
        if (connectionClosed != 0) {
            break;
        }
        if (totalRead < 0x20000) {
            continue;
        }
        break;
    }

    if (totalRead != 0) {
        ((M2C_UNK (*)(M2C_UNK, M2C_UNK *, M2C_UNK, s32))gpiLogMessage)(connection, &gGpiMsgRecvTotal, (M2C_UNK *)tag, totalRead);
    }

    buf->data = data;
    buf->len = used;
    buf->size = capacity;
    *bytesRead = totalRead;
    *connClosed = connectionClosed;
    return 0;
}

/* GameSpy gpi send: flush as much of the peer's queued send buffer as the socket
   accepts, then either compact the buffer or advance its position past the sent
   bytes, and record the new [pos, len) range.  *outBuffered is set when the
   socket would block.  Returns 0, or a socket error code. */
s32 gpiSendFromBuffer(s32 connection,s32 sock,void *buffer,s32 *outBuffered,s32 compact,s32 tag) {
 s32 AssertFailed(s32 *,s32 *,s32 *,s32);
 s32 MemMove(s32,s32,s32);
 extern s32 sAssertOutputBufferNotNull,sGpiSendFromBufferName,gGpiBufferFileName,sAssertLenNonNeg,sAssertPosNonNeg,sAssertPosLeLen;
 s32 wouldBlock,sentNow;
 s32 done;
 GPISendBuffer *buf;
 s32 result;
 s32 remaining;
 s32 len;
 s32 *out;
 s32 data;
 s32 pos;
 buf=buffer;out=outBuffered;
 if(!buffer)AssertFailed(&sAssertOutputBufferNotNull,&gGpiBufferFileName,&sGpiSendFromBufferName,0x1b9);
 done=0;
 len=buf->len;
 pos=buf->pos;
 data=(s32)buf->data;
 remaining=len-pos;
 if(!remaining)return 0;
 do {
 result=gpiSendOrBufferChar(connection,sock,(s8 *)(data+(pos+done)),remaining,&wouldBlock,&sentNow,(s32 *)tag);
 if(result)return result;
 if(sentNow){remaining-=sentNow;done+=sentNow;}
 }while(sentNow && remaining);
 if(compact) {
 if(done>0){MemMove(data,data+done,remaining+1);len-=done;}
 }else pos+=done;
 if(len<0)AssertFailed(&sAssertLenNonNeg,&gGpiBufferFileName,&sGpiSendFromBufferName,0x1de);
 if(pos<0)AssertFailed(&sAssertPosNonNeg,&gGpiBufferFileName,&sGpiSendFromBufferName,0x1df);
 if(pos>len)AssertFailed(&sAssertPosLeLen,&gGpiBufferFileName,&sGpiSendFromBufferName,0x1e0);
 buf->len=len;
 buf->pos=pos;
 if(out)*out=wouldBlock;
 return 0;
}

/* Read one complete gpi message out of a peer's receive buffer: locate the
 * "\msg\" end-of-header marker, parse the \m\ (message type) and \len\
 * (message length) fields, and return the message body and length, advancing
 * the buffer's read position. Returns 0 when no complete message is ready (and
 * sets *messageOut to NULL), or 3 for a malformed message. */
s32 gpiReadMessageFromPeer(M2C_UNK connection, GPIBuffer *buf, s8 **messageOut, s32 *messageType, s32 *messageLength) {
    s8 *StringFindChar(M2C_UNK, M2C_UNK);
    s32 StringCompareN(s32, M2C_UNK *, s32);
    s32 gpiValueForKey(M2C_UNK, M2C_UNK *, M2C_UNK *, s32);
    s32 ParseInt(M2C_UNK *);
    extern M2C_UNK gGpiKeyMsg;
    extern M2C_UNK gGpiKeyM;
    extern M2C_UNK gGpiKeyLen;
    M2C_UNK field[4];
    s8 *lineEnd;
    s32 bodyLen;
    s32 *lengthOut;

    (void)connection;
    *messageOut = NULL;
    lengthOut = messageLength;
    if (buf->len < 5) {
        return 0;
    }
    lineEnd = StringFindChar((M2C_UNK)buf->data, 0xA);
    if (lineEnd == NULL) {
        goto done;
    }
    if (StringCompareN((s32)(lineEnd - 5), &gGpiKeyMsg, 5) != 0) {
        return 3;
    }
    *lineEnd = 0;
    if (gpiValueForKey((M2C_UNK)buf->data, &gGpiKeyM, field, 0x10) == 0) {
        return 3;
    }
    *messageType = ParseInt(field);
    if (gpiValueForKey((M2C_UNK)buf->data, &gGpiKeyLen, field, 0x10) == 0) {
        return 3;
    }
    bodyLen = ParseInt(field);
    if (buf->len > (bodyLen + 1 + (lineEnd - (s8 *)buf->data))) {
        if (lineEnd[bodyLen + 1] != 0) {
            return 3;
        }
        *messageOut = lineEnd + 1;
        *lengthOut = bodyLen;
        buf->pos = (bodyLen + 1) + (lineEnd - (s8 *)buf->data) + 1;
    } else {
        *lineEnd = 0xA;
    }
done:
    return 0;
}

/* Drop the bytes a peer's receive buffer has already read: compact the unread
 * remainder (len - pos) to the front of the storage, NUL-terminate it and reset
 * the read position.  The gpi connection argument is unused. */
s32 gpiConsumeReadBuffer(M2C_UNK gpi, GPIBuffer *buf) {
    s32 remaining;

    (void)gpi;
    if (!buf || !buf->data || !buf->pos) return 0;
    remaining = buf->len - buf->pos;
    buf->len = remaining;
    if (remaining) MemMove(buf->data, (u8 *)buf->data + buf->pos, remaining);
    ((u8 *)buf->data)[buf->len] = 0;
    buf->pos = 0;
    return 0;
}

/* Queues the connection's registered error callback with the result and the
 * fatal flag; a fatal error also latches the connection's fatal state.  Nothing
 * is queued when no error callback is registered. */
void gpiCallErrorCallback(void **connectionRef, s32 result, s32 fatal) {
    void *gpiMalloc(s32);
    s32 gpiAddCallback(void *, volatile Unk02050838Pair, s32, s32, u32);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK gGpiCallErrorCallbackName;
    extern M2C_UNK gGpiAssertConnection;
    extern M2C_UNK gGpiCallbackFileName;
    extern M2C_UNK gGpiAssertResult;
    extern M2C_UNK gGpiAssertFatal;

    void *conn = *connectionRef;

    if (conn == NULL) {
        AssertFailed(&gGpiAssertConnection, &gGpiCallbackFileName, &gGpiCallErrorCallbackName, 0x23);
    }
    if (result == GP_NO_ERROR) {
        AssertFailed(&gGpiAssertResult, &gGpiCallbackFileName, &gGpiCallErrorCallbackName, 0x24);
    }
    if (fatal != GP_FATAL && fatal != GP_NON_FATAL) {
        AssertFailed(&gGpiAssertFatal, &gGpiCallbackFileName, &gGpiCallErrorCallbackName, 0x25);
    }
    if (fatal == GP_FATAL) {
        M2C_FIELD(conn, s32 *, GPI_CONN_ERROR_FATAL) = 1;
    }
    {
        s32 callback = M2C_FIELD(conn, s32 *, GPI_CONN_ERROR_CALLBACK);
        volatile Unk02050838Pair pair;
        void *data;
        pair.unk_0 = callback;
        pair.unk_4 = M2C_FIELD(conn, s32 *, GPI_CONN_ERROR_DATA);
        if (callback == 0) {
            return;
        }
        data = gpiMalloc(0x10);
        if (data != NULL) {
            M2C_FIELD(data, s32 *, 0) = result;
            M2C_FIELD(data, s32 *, 0xC) = fatal;
            M2C_FIELD(data, s32 *, 4) = M2C_FIELD(conn, s32 *, GPI_CONN_ERROR_CODE);
            M2C_FIELD(data, void **, 8) = conn;
        }
        gpiAddCallback(connectionRef, pair, (s32)data, 0, 1);
    }
}

s32 gpiAddCallback(void *arg0,volatile Unk02050838Pair pair,s32 c,s32 arg4,u32 arg5) {
void *gpiMalloc(s32);extern M2C_UNK data_020fe1ac;
void *base=M2C_FIELD(arg0,void **,0);void *p=gpiMalloc(24);void *q;s32 tmp;
if(!p){gpiSetErrorString(arg0,&data_020fe1ac);return 1;}
M2C_FIELD(p,s32 *,0)=pair.unk_0;M2C_FIELD(p,s32 *,4)=pair.unk_4;M2C_FIELD(p,s32 *,8)=c;
tmp=arg4?M2C_FIELD(arg4,s32 *,24):0;
M2C_FIELD(p,s32 *,12)=arg5;
M2C_FIELD(p,s32 *,16)=tmp;
M2C_FIELD(p,s32 *,20)=0;
if(!M2C_FIELD(base,void **,0x438))M2C_FIELD(base,void **,0x438)=p;
q=M2C_FIELD(base,void **,0x43c);if(q)M2C_FIELD(q,void **,20)=p;
M2C_FIELD(base,void **,0x43c)=p;return 0;
}

void gpiCallCallback(void *connection, GPICallbackData *data) {
    void gpiFree(void *);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK gGpiAssertCallback, gGpiCallbackFileName, gGpiCallCallbackName, gGpiAssertArg;
    s32 code;

    /* Run a queued gpi callback, then release the typed data it was given. */
    if (!data->callback.callback) {
        AssertFailed(&gGpiAssertCallback, &gGpiCallbackFileName, &gGpiCallCallbackName, 0x6e);
    }
    if (!data->arg) {
        AssertFailed(&gGpiAssertArg, &gGpiCallbackFileName, &gGpiCallCallbackName, 0x6f);
    }
    data->callback.callback(connection, data->arg, data->callback.param);

    code = data->type;
    if (code == GPI_CALLBACK_PLAYER_INFO) {
        gpiFree(((GpiPlayerInfoData *)data->arg)->name);
        ((GpiPlayerInfoData *)data->arg)->name = 0;
    } else if (code == GPI_CALLBACK_INFO_LISTS) {
        s32 i;
        GpiInfoListsData *lists;
        lists = data->arg;
        for (i = 0; i < lists->count; i++) {
            gpiFree(lists->names[i]);
            lists->names[i] = 0;
            gpiFree(lists->values[i]);
            lists->values[i] = 0;
        }
        gpiFree(lists->names);
        lists->names = 0;
        gpiFree(lists->values);
        lists->values = 0;
    } else if (code == GPI_CALLBACK_INFO_RECORDS) {
        GpiInfoRecordsData *info = data->arg;
        gpiFree(info->records);
        info->records = 0;
    } else if (code == GPI_CALLBACK_OWNED_POINTER) {
        GpiOwnedPointerData *info = data->arg;
        if (info->pointer) {
            gpiFree(info->pointer);
            info->pointer = 0;
        }
    } else if (code == GPI_CALLBACK_RECORD_LIST) {
        GpiRecordListData *list = data->arg;
        if (list->records) {
            gpiFree(list->records);
            list->records = 0;
        }
    } else if (code == GPI_CALLBACK_STRING_LIST) {
        s32 i;
        GpiStringListData *list;
        list = data->arg;
        for (i = 0; i < list->count; i++) {
            gpiFree(list->strings[i]);
            list->strings[i] = 0;
        }
        gpiFree(list->strings);
        list->strings = 0;
    }

    gpiFree(data->arg);
    data->arg = 0;
    gpiFree(data);
}

/* Take queued gpi callbacks off the connection's queue and run them.  With an
 * operation id, only that operation's callbacks and the queued error callbacks
 * go, the rest stay queued in order; with 0, everything queued goes. */
s32 gpiRemoveCallbacks(void **connectionRef, s32 operationId) {
    void *conn;
    void *head;
    void *tail;
    void *prev;
    void *data;
    void *next;
    void *cur;

    conn = *connectionRef;

    if (operationId != 0) {
        head = M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_HEAD);
        tail = M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_TAIL);
        prev = (void *)0;
        M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_HEAD) = (void *)0;
        cur = head;
        M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_TAIL) = (void *)0;
        if (head != (void *)0) {
            do {
                next = M2C_FIELD(cur, void **, 0x14);
                if ((M2C_FIELD(cur, s32 *, 0x10) == operationId) ||
                    (M2C_FIELD(cur, s32 *, 0xC) == GPI_CALLBACK_ERROR)) {
                    if (prev != (void *)0) {
                        M2C_FIELD(prev, void **, 0x14) = next;
                    } else {
                        head = next;
                    }
                    if (tail == cur) {
                        tail = prev;
                    }
                    gpiCallCallback(connectionRef, cur);
                } else {
                    prev = cur;
                }
                cur = next;
            } while (next != (void *)0);
        }
        if (M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_HEAD) != (void *)0) {
            M2C_FIELD(M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_TAIL), void **, 0x14) = head;
        } else {
            M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_HEAD) = head;
        }
        M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_TAIL) = tail;
        return 0;
    }

    cur = M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_HEAD);
    if (cur != (void *)0) {
        do {
            head = (void *)0;
            M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_HEAD) = (void *)0;
            M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_TAIL) = (void *)0;
            if (cur != (void *)0) {
                do {
                    data = M2C_FIELD(cur, void **, 0x14);
                    gpiCallCallback(connectionRef, cur);
                    cur = data;
                } while (data != (void *)0);
            }
            cur = M2C_FIELD(conn, void **, GPI_CONN_CALLBACK_HEAD);
        } while (cur != (void *)0);
    }
    return 0;
}

/* Fill `dst` with `length` random characters from the base62 alphabet
 * ("A-Za-z0-9") and NUL-terminate it. */
void GenerateRandomString(s8 *dst, s32 length) {
    u32 Rand(void);
    extern s8 gBase62Alphabet[];
    s32 i = 0;
    for (; i < length; i++) dst[i] = gBase62Alphabet[Rand() % 62U];
    dst[i] = 0;
}

