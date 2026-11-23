/* 9 functions from 0x0204E408 to 0x0204EEE8 (main), found by ds-decomp. */
#include "common.h"
typedef struct InitPair4E { s32 first; /* callback function */ s32 second; /* its parameter */ } InitPair4E;
typedef struct GpiConnection {
    u8  unk00;            /* +0x00 */
    u8  pad01[0xFF];
    s32 unk100;           /* +0x100 */
    s32 unk104;           /* +0x104 */
    s32 unk108;           /* +0x108 */
    s32 unk10c;           /* +0x10C */
    u8  unk110;           /* +0x110 */
    u8  pad111[0x1E];
    u8  unk12f;           /* +0x12F */
    u8  pad130[0x14];
    u8  unk144;           /* +0x144 */
    u8  pad145[0x53];
    s32 unk198;           /* +0x198 */
    s32 unk19c;           /* +0x19C */
    s32 unk1a0;           /* +0x1A0 */
    InitPair4E pairs[6];  /* +0x1A4 the six peer callbacks */
    s32 socket;           /* +0x1D4 peer socket, -1 when not connected */
    s32 state;            /* +0x1D8 connection state (0..4) */
    GPIBuffer recvBuffer; /* +0x1DC messages received from the server */
    void *msgBuffer;      /* +0x1EC parsed message */
    s32 msgCapacity;      /* +0x1F0 its allocated size */
    GPIBuffer sendBuffer; /* +0x1F4 queued outgoing request data */
    s32 unk204;           /* +0x204 */
    s32 pad208;           /* +0x208 */
    s32 unk20c;           /* +0x20C */
    s32 unk210;           /* +0x210 */
    s32 cachedStatus;     /* +0x214 last status sent, -1 when none */
    s8  statusString[0x100];   /* +0x218 */
    s8  locationString[0x100]; /* +0x318 */
    s32 timerSet;         /* +0x418 */
    s32 unk41c;           /* +0x41C */
    s32 unk420;           /* +0x420 */
    s32 unk424;           /* +0x424 pending operation list */
    s32 timerHandle;      /* +0x428 handle of the start-up timer set */
    s32 unk42c;           /* +0x42C */
    s32 unk430;           /* +0x430 */
    s32 unk434;           /* +0x434 */
    u8  pad438[8];
    GPIBuffer unk440;     /* +0x440 */
    GPIBuffer unk450;     /* +0x450 */
    void *unk460;         /* +0x460 owned memory block */
    u8  pad464[8];
    s32 peerCallback;     /* +0x46C callback run when a peer connects */
    s32 peerCallbackData; /* +0x470 its data */
} GpiConnection;
typedef GpiConnection InitState4E;

#pragma opt_common_subs off
/* Builds a gpi set-status request on the session (status, sesskey, status string
 * and location string) and caches the three values; backslashes in the strings
 * are turned into slashes. Returns 0 on success, 2 on a bad argument or a
 * disconnected connection. */
s32 gpiSetStatusInfo(void **connection, s32 status, s8 *statusString, s8 *locationString) {
    M2C_UNK StringCopyN(s8 *, s8 *, M2C_UNK);
    M2C_UNK gpiSetErrorString(void **, M2C_UNK *);
    s32 StringCompare(s8 *, void *);
    extern M2C_UNK gGpiMsgDisconnected;
    extern s8 gGsKeySessKey;
    extern s8 gGsKeyFinalStatus;
    extern M2C_UNK gGpiMsgInvalidStatusString;
    extern M2C_UNK gGpiMsgInvalidLocationString;
    extern s8 gGsKeyStatus;
    extern s8 gGsKeyStatString;
    extern s8 gGsKeyLocString;
    s8 statusCopy[0x100];
    s8 locationCopy[0x100];
    s8 *c1;
    s8 *c2;
    void *session;

    if (!connection || !(session = *connection)) {
        return 2;
    }
    if (M2C_FIELD(session, s32 *, 0x108) != 0) {
        return 0;
    }
    if (M2C_FIELD(session, s32 *, 0x1D8) == 4) {
        gpiSetErrorString(connection, &gGpiMsgDisconnected);
        return 2;
    }
    if (statusString == NULL) {
        gpiSetErrorString(connection, &gGpiMsgInvalidStatusString);
        return 2;
    }
    if (locationString == NULL) {
        gpiSetErrorString(connection, &gGpiMsgInvalidLocationString);
        return 2;
    }
    StringCopyN(statusCopy, statusString, 0x100);
    if (statusCopy[0] != 0) {
        c1 = statusCopy;
        do {
            if (*c1 == 0x5C) {
                *c1 = 0x2F;
            }
            c1 += 1;
        } while (*c1 != 0);
    }
    StringCopyN(locationCopy, locationString, 0x100);
    if (locationCopy[0] != 0) {
        c2 = locationCopy;
        do {
            if (*c2 == 0x5C) {
                *c2 = 0x2F;
            }
            c2 += 1;
        } while (*c2 != 0);
    }
    if ((status == M2C_FIELD(session, s32 *, 0x214)) && (StringCompare(statusCopy, session + 0x218) == 0) && (StringCompare(locationCopy, session + 0x318) == 0)) {
        return 0;
    }
    M2C_FIELD(session, s32 *, 0x214) = status;
    StringCopyN(session + 0x218, statusCopy, 0x100);
    StringCopyN(session + 0x318, locationCopy, 0x100);
    gpiAppendStringField(connection, session + 0x1F4, &gGsKeyStatus);
    gpiAppendIntField(connection, session + 0x1F4, status);
    gpiAppendStringField(connection, session + 0x1F4, &gGsKeySessKey);
    gpiAppendIntField(connection, session + 0x1F4, M2C_FIELD(session, s32 *, 0x198));
    gpiAppendStringField(connection, session + 0x1F4, &gGsKeyStatString);
    gpiAppendStringField(connection, session + 0x1F4, statusCopy);
    gpiAppendStringField(connection, session + 0x1F4, &gGsKeyLocString);
    gpiAppendStringField(connection, session + 0x1F4, locationCopy);
    gpiAppendStringField(connection, session + 0x1F4, &gGsKeyFinalStatus);
    return 0;
}
#pragma opt_common_subs reset
/* Queue a text message to a gpi player: report "Invalid message." when there is
 * no text, fail on a disconnected session, and skip the send in simulation mode. */
s32 gpiSendTextToPlayer(void **gpi,s32 playerId,s32 message) {
    s32 gpiSendMessageToPlayer(void **,s32,s32,s32);
    M2C_UNK gpiSetErrorString(void **,M2C_UNK *);
    extern M2C_UNK gGpiMsgDisconnected; extern M2C_UNK gGpiMsgInvalidMessage;
    void *session;
    if(gpi==0 || (session=*gpi)==0)return 2;
    if(M2C_FIELD(session,s32 *,GPI_CONN_SIMULATION)!=0)return 0;
    if(M2C_FIELD(session,s32 *,GPI_CONN_STATE)==GPI_STATE_DISCONNECTED){gpiSetErrorString(gpi,&gGpiMsgDisconnected);return 2;}
    if(message==0){gpiSetErrorString(gpi,&gGpiMsgInvalidMessage);return 2;}
    return gpiSendMessageToPlayer(gpi,playerId,GPI_MSG_PLAYER_INFO,message);
}

/* Creates a GameSpy GPI connection: allocates and clears its state, stores the
 * peer callback, creates the start-up timer set, clears the six peer callbacks
 * and resets the connection. The connection is handed back through out; returns
 * 0 on success, 1 when the allocation fails or a step errors out. */
s32 gpiInitialize(void **out,s32 peerCallback,s32 peerCallbackData){
void *gpiMalloc(s32);s32 gpiCreateBuddyTable(void **);s32 gpiResetConnection(void **);void gpiFreeConnection(void **);void MemSet(void *,s32,s32);void gpiLogMessage(void **,void *,...);extern u8 gGpiLogInitialize[];
GpiConnection *connection;s32 i,result;
*out=0;connection=gpiMalloc(0x490);if(!connection)return 1;MemSet(connection,0,0x490);
connection->unk00=0;connection->timerSet=0;connection->unk100=1;connection->unk104=0;connection->unk108=0;connection->unk10c=0;connection->peerCallback=peerCallback;connection->peerCallbackData=peerCallbackData;
if(!gpiCreateBuddyTable((void **)&connection)){gpiFree(connection);connection=0;return 1;}
connection->unk420=0;for(i=0;i<6;i++){connection->pairs[i].first=0;connection->pairs[i].second=0;}
connection->unk460=0;gpiLogMessage((void **)&connection,gGpiLogInitialize);
result=gpiResetConnection((void **)&connection);if(result){gpiFreeConnection((void **)&connection);return result;}
func_0204926c();GetSystemTickMilliseconds();SetRandSeed();*out=connection;return 0;}

void gpiFreeConnection(void **arg0) {
    M2C_UNK gpiFree(void *);
    M2C_UNK TableFree(s32);
    M2C_UNK gpiDisconnect(void **, M2C_UNK);
    void *temp_r4;

    temp_r4 = *arg0;
    gpiDisconnect(arg0, 1);
    gpiFree(M2C_FIELD(temp_r4, void **, 0x460));
    M2C_FIELD(temp_r4, void **, 0x460) = NULL;
    TableFree(M2C_FIELD(temp_r4, s32 *, 0x428));
    gpiFree(temp_r4);
    *arg0 = NULL;
}

s32 func_0204e830(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 8) = 0;
    M2C_FIELD(arg1, s32 *, 0x10) = 0;
    M2C_FIELD(arg1, s32 *, 0x14) = 0;
    M2C_FIELD(arg1, s32 *, 0x18) = 0;
    return 1;
}

/* Reset a gpi connection to its initial state: free its receive, message, send
 * and two queue buffers, drop the pending operations and clear the cached status
 * and location strings. */
s32 gpiResetConnection(void **a){void gpiRemoveOperation(void **,void *);void gpiWalkBuddyTable(void **,void *);s32 func_0204e830(void *, void *);GpiConnection *p=*a;
p->unk110=0;p->unk12f=0;p->unk144=0;
p->socket=-1;p->state=0;
p->recvBuffer.len=0;p->recvBuffer.pos=0;p->recvBuffer.size=0;
gpiFree(p->recvBuffer.data);p->recvBuffer.data=0;
p->msgCapacity=0;
gpiFree(p->msgBuffer);p->msgBuffer=0;
p->sendBuffer.len=0;p->sendBuffer.pos=0;p->sendBuffer.size=0;
gpiFree(p->sendBuffer.data);p->sendBuffer.data=0;
p->unk440.len=0;p->unk440.pos=0;p->unk440.size=0;
gpiFree(p->unk440.data);p->unk440.data=0;
p->unk450.len=0;p->unk450.pos=0;p->unk450.size=0;
gpiFree(p->unk450.data);p->unk450.data=0;
p->unk204=-1;p->unk20c=2;
while(p->unk424)gpiRemoveOperation(a,p->unk424);
p->unk424=0;p->unk430=0;
gpiWalkBuddyTable(a,&func_0204e830);
p->unk19c=0;p->unk1a0=0;p->unk198=0;p->unk210=0;p->unk41c=0;p->unk434=0;
p->cachedStatus=-1;p->statusString[0]=0;p->locationString[0]=0;
return 0;}

/* Reads whatever the server has sent, cuts the receive buffer at each "\final\"
 * terminator and dispatches every message: a message carrying "\id\" runs the
 * operation registered for that id, otherwise it is parsed as key/value data. */
s32 gpiHandleServerData(void *ctx) {
    extern u8 gGpiConnTag[], gGpiMsgRecvError[], gGpiKeyFinal[], gGpiKeyId[], gGpiMsgCmd[],
        gGpiMsgOutOfMemory[], gGpiMsgNoOperation[], gGpiKeyBm[], gGpiKeyKa[], gGpiMsgUnsolicited[],
        gGpiMsgServerClosed[];
    void gpiFlushUpdateBuffers(void *, void *);
    s32 gpiSendFromBuffer(void *, s32, void *, s32 *, s32, void *);
    s32 gpiReceiveData(void *, s32, void *, s32 *, s32 *, void *);
    void gpiSetError(void *, s32, void *);
    void gpiCallErrorCallback(void *, s32, s32);
    u8 *StringFind(void *, void *);
    void gpiLogMessage(void **, void *, ...);
    void *gpiRealloc(void *, s32);
    s32 gpiSetErrorString(void **, s32 *);
    void MemCopy(void *, void *, s32);
    void MemMove(void *, void *, s32);
    s32 ParseInt(void *);
    s32 gpiFindOperationById(void **, void **, s32);
    s32 gpiProcessOperation(void *, s32, void *);
    s32 gpiProcessErrorReply(void *, void *, s32);
    s32 StringCompareN(void *, void *, s32);
    s32 func_0204eee8(void *, void *);
    s32 func_02054520(void *);
    void gpiSleep(s32);

    void *operation;
    s32 lineLen, connectionClosed = 0, result, id, again;
    u8 *conn = *(u8 **)ctx, *messageEnd, *scan;
    void *newBuf;

    do {
        gpiFlushUpdateBuffers(ctx, conn + 0x1f4);
        result = gpiSendFromBuffer(ctx, M2C_FIELD(conn, s32 *, 0x1d4), conn + 0x1f4, &connectionClosed, 1, gGpiConnTag);
        if (result) return result;
        result = gpiReceiveData(ctx, M2C_FIELD(conn, s32 *, 0x1d4), conn + 0x1dc, &lineLen, &connectionClosed, gGpiConnTag);
        if (result) {
            if (result != 3) return result;
            gpiSetError(ctx, 5, gGpiMsgRecvError);
            gpiCallErrorCallback(ctx, 3, 1);
            return 3;
        }
        messageEnd = StringFind(M2C_FIELD(conn, void **, 0x1dc), gGpiKeyFinal);
        while (messageEnd) {
            *messageEnd = 0;
            gpiLogMessage(ctx, gGpiMsgCmd, M2C_FIELD(conn, void **, 0x1dc));
            lineLen = messageEnd - M2C_FIELD(conn, u8 **, 0x1dc);
            if (lineLen > M2C_FIELD(conn, s32 *, 0x1f0)) {
                M2C_FIELD(conn, s32 *, 0x1f0) += lineLen < 0x800 ? 0x800 : lineLen;
                newBuf = gpiRealloc(M2C_FIELD(conn, void **, 0x1ec), M2C_FIELD(conn, s32 *, 0x1f0) + 1);
                if (!newBuf) {
                    gpiSetErrorString(ctx, gGpiMsgOutOfMemory);
                    return 1;
                }
                M2C_FIELD(conn, void **, 0x1ec) = newBuf;
            }
            MemCopy(M2C_FIELD(conn, void **, 0x1ec), M2C_FIELD(conn, void **, 0x1dc), lineLen + 1);
            scan = messageEnd + 7;
            M2C_FIELD(conn, s32 *, 0x1e4) -= scan - M2C_FIELD(conn, u8 **, 0x1dc);
            MemMove(M2C_FIELD(conn, void **, 0x1dc), scan, M2C_FIELD(conn, s32 *, 0x1e4) + 1);
            scan = M2C_FIELD(conn, u8 **, 0x1ec);
            messageEnd = StringFind(scan, gGpiKeyId);
            if (messageEnd) {
                id = ParseInt(messageEnd + 4);
                if (!gpiFindOperationById(ctx, &operation, id)) {
                    gpiLogMessage(ctx, gGpiMsgNoOperation, id);
                } else {
                    result = gpiProcessOperation(ctx, (s32)operation, M2C_FIELD(conn, void **, 0x1ec));
                    if (result) return result;
                }
            } else {
                if (gpiProcessErrorReply(ctx, scan, 1)) return 4;
                scan = M2C_FIELD(conn, u8 **, 0x1ec);
                if (!StringCompareN(scan, gGpiKeyBm, 4)) {
                    result = func_0204eee8(ctx, scan);
                    if (result) return result;
                } else if (StringCompareN(scan, gGpiKeyKa, 10)) {
                    gpiLogMessage(ctx, gGpiMsgUnsolicited);
                }
            }
            messageEnd = StringFind(M2C_FIELD(conn, void **, 0x1dc), gGpiKeyFinal);
        }
        if (connectionClosed) {
            gpiSetError(ctx, 7, gGpiMsgServerClosed);
            gpiCallErrorCallback(ctx, 3, 1);
            return 0;
        }
        again = func_02054520(ctx);
        if (again) gpiSleep(10);
    } while (again);
    return 0;
}

/* One tick of the GP connection: while connecting it pumps the handshake (waitId
   enables the blocking poll), then reads and dispatches server data, advances the
   search and pending-operation queues, and flushes finished callbacks; a nonzero
   error code is returned to stop. */
s32 gpiThink(void **connection, s32 waitId) {
    void gpiSleep(s32); s32 gpiHandleServerData(void *); s32 gpiRemoveCallbacks(void **,s32);
    s32 gpiCheckConnect(void **); void gpiFinishOperation(void **); void gpiRemoveOperation(void **,void *);
    s32 gpiFindOperationById(void **,void **,s32); s32 func_0205519c(void **);
    s32 gpiProcessSearches(void **); s32 gpiDisconnect(void **,s32);
    void AssertFailed(void *,void *,void *,s32);
    extern M2C_UNK data_020fdb64,data_020fdc80,data_020fdd78,data_020fdd80;
    void *next;
    void *session;
    s32 result;
    u32 keepPolling;
    void *pending;
    s32 code;
    session=*connection; result=0;
    if(M2C_FIELD(session,u32 *,0x1d8)>4)AssertFailed(&data_020fdc80,&data_020fdd78,&data_020fdb64,0x1b6);
    if(M2C_FIELD(session,u32 *,0x1d8)==1) {
        do {
            result=gpiCheckConnect(connection);
            if(result==0 && waitId && M2C_FIELD(session,u32 *,0x1d8)==1)keepPolling=1;else keepPolling=0;
            if(keepPolling)gpiSleep(10);
        }while(keepPolling);
        if(result) {
            if(gpiFindOperationById(connection,&next,1))M2C_FIELD(next,s32 *,0x1c)=4;
            else AssertFailed(&data_020fdd80,&data_020fdd78,&data_020fdb64,0x1dc);
        }
    }
    if((u32)(M2C_FIELD(session,u32 *,0x1d8)-2)<=1){
        if(!result)result=gpiHandleServerData(connection);
        if(!result)result=func_0205519c(connection);
    }
    if(!result)result=gpiProcessSearches(connection);
    pending=M2C_FIELD(session,void **,0x424);next=pending;
    if(pending)do {
        if(M2C_FIELD(pending,s32 *,0x1c)==0)next=M2C_FIELD(pending,void **,0x20);
        else {gpiFinishOperation(connection);pending=next;next=M2C_FIELD(pending,void **,0x20);gpiRemoveOperation(connection,pending);}
        pending=next;
    }while(pending);
    code=gpiRemoveCallbacks(connection,waitId);
    if(code)return code;
    if(M2C_FIELD(session,s32 *,0x41c))gpiDisconnect(connection,0);
    return result;
}

/* Builds the authadd request on the connection's send buffer: the command name,
 * the session key, the profile the friend add comes from, that profile's
 * signature and the final marker. Always reports success. */
s32 gpiAppendAuthAddCommand(void **connection, void *profile) {
    M2C_UNK gpiAppendStringField(void **, void *, M2C_UNK *);
    M2C_UNK gpiAppendIntField(void **, void *, s32);
    extern M2C_UNK gpiKeyAuthAdd;
    extern M2C_UNK gpiKeySessionKey;
    extern M2C_UNK gpiKeyFromProfileID;
    extern M2C_UNK gpiKeySig;
    extern M2C_UNK gpiKeyFinal;
    void *conn;

    conn = *connection;
    gpiAppendStringField(connection, (u8 *)conn + GPI_CONN_OUTPUT_BUFFER, &gpiKeyAuthAdd);
    gpiAppendStringField(connection, (u8 *)conn + GPI_CONN_OUTPUT_BUFFER, &gpiKeySessionKey);
    gpiAppendIntField(connection, (u8 *)conn + GPI_CONN_OUTPUT_BUFFER, M2C_FIELD(conn, s32 *, GPI_CONN_SESSION_KEY));
    gpiAppendStringField(connection, (u8 *)conn + GPI_CONN_OUTPUT_BUFFER, &gpiKeyFromProfileID);
    gpiAppendIntField(connection, (u8 *)conn + GPI_CONN_OUTPUT_BUFFER, M2C_FIELD(profile, s32 *, 0));
    gpiAppendStringField(connection, (u8 *)conn + GPI_CONN_OUTPUT_BUFFER, &gpiKeySig);
    gpiAppendStringField(connection, (u8 *)conn + GPI_CONN_OUTPUT_BUFFER, M2C_FIELD(profile, M2C_UNK **, 0x10));
    gpiAppendStringField(connection, (u8 *)conn + GPI_CONN_OUTPUT_BUFFER, &gpiKeyFinal);
    return 0;
}

