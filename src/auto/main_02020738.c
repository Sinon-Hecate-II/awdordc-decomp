/* 39 functions from 0x02020738 to 0x020216CC (main), found by ds-decomp. */
#include "common.h"
#include "net_socket.h"
#include "ghttp.h"


s32 NetworkPollClosing(void);

s32 SocketQueueSend(void *connection, s32 buffer, s32 byteCount, s32 startPos, u16 tag, s32 fallback, s32 mode) {
    /* Queue a (possibly wrapped) send from connection's circular buffer and remember how much was taken. */
    u16 AllocateLocalPort();
    s32 SocketSendTask(void *);
    s32 SocketAllocTask(void *, s32, s32);
    s32 SocketSubmitSendTask(s32, s32);
    s32 MI_CpuCopy8(s32, s32, s32);
    void *ctx;
    void *entry;
    s32 curBuffer;
    s32 end;
    s32 other;
    s32 size;
    s32 start;
    curBuffer = buffer;
    ctx = M2C_FIELD(connection, void **, 0x68);

    entry = (void *)SocketAllocTask(SocketSendTask, M2C_FIELD(ctx, s32 *, 0x10c), mode);
    if (!entry) return -33;

    if ((mode & 1) && M2C_FIELD(connection, s8 *, 0x73) != 1)
        M2C_FIELD(entry, s8 *, 13) = 3;
    else
        M2C_FIELD(entry, s8 *, 13) = 0;
    start = M2C_FIELD(ctx, s32 *, 0xfc);
    size = M2C_FIELD(ctx, s32 *, 0xf8);
    if (startPos + byteCount < size) {
        M2C_FIELD(entry, s32 *, 16) = start + startPos;
        M2C_FIELD(entry, s32 *, 20) = byteCount;
        M2C_FIELD(entry, s32 *, 24) = 0;
        startPos += byteCount;
        M2C_FIELD(entry, s32 *, 28) = 0;
    } else {
        M2C_FIELD(entry, s32 *, 16) = start + startPos;
        M2C_FIELD(entry, s32 *, 20) = size - startPos;
        M2C_FIELD(entry, s32 *, 24) = start;
        startPos = byteCount - M2C_FIELD(entry, s32 *, 20);
        M2C_FIELD(entry, s32 *, 28) = startPos;
        MI_CpuCopy8(curBuffer + M2C_FIELD(entry, s32 *, 20), M2C_FIELD(entry, s32 *, 24), startPos);
    }
    MI_CpuCopy8(curBuffer, M2C_FIELD(entry, s32 *, 16), M2C_FIELD(entry, s32 *, 20));
    curBuffer = M2C_FIELD(ctx, u16 *, 0x100);
    M2C_FIELD(entry, u16 *, 32) = startPos;
    M2C_FIELD(ctx, u16 *, 0x100) = M2C_FIELD(entry, u16 *, 32);
    if (M2C_FIELD(connection, s8 *, 0x73) == 1) {
        if (!M2C_FIELD(connection, u16 *, 0x74)) {
            M2C_FIELD(connection, u16 *, 0x74) = AllocateLocalPort();
            M2C_FIELD(connection, u16 *, 10) = M2C_FIELD(connection, u16 *, 0x74);
        }
        M2C_FIELD(entry, u16 *, 36) = M2C_FIELD(connection, u16 *, 0x74);
        other = M2C_FIELD(connection, s32 *, 0x78);
        if (!other || fallback) {
            M2C_FIELD(entry, s32 *, 40) = fallback;
            M2C_FIELD(entry, u16 *, 38) = tag;
        } else {
            M2C_FIELD(entry, s32 *, 40) = other;
            M2C_FIELD(entry, u16 *, 38) = M2C_FIELD(connection, u16 *, 0x76);
        }
    } else
        M2C_FIELD(entry, s32 *, 40) = 0;
    if (SocketSubmitSendTask(M2C_FIELD(ctx, s32 *, 0x10c), (s32)entry)) {
        byteCount = 0;
        M2C_FIELD(ctx, u16 *, 0x100) = curBuffer;
    }
    return byteCount;
}

/* Send task for one queued send: while the socket may still write, pull a piece
 * of the queued data out of the send ring (skipping the link/IP/transport header
 * in the outgoing packet buffer) and hand it to the link, repeating until no more
 * is queued or the link rejects it.  The ring's read position is then advanced to
 * where the queueing finished and producers waiting for space are woken. */
s32 SocketSendTask(void *request) {
 void OS_WakeupThread(s32);
 M2C_UNK SetConnectionEndpoint(u16,u16,s32);
 s32 SendNetPacket(s32,s32);
 s32 WaitForTlsCloseNotify();
 s32 sent,sendBuffer,isStream,maxChunk,valid,read;void *socket; void *sendConn;u32 total;s32 headerSize;
 s8 state,state2,state3;
 socket=M2C_FIELD(request,void **,4);
 total=0;
 state=M2C_FIELD(socket,s8 *,SOCK_STATE);valid=1;
 sendConn=M2C_FIELD(socket,void **,SOCK_TX_CONN);
 if(state && state!=4)valid=0;
 if(!valid || (M2C_FIELD(socket,s16 *,SOCK_FLAGS)&4)) {
 s32 destAddr=M2C_FIELD(request,s32 *,0x28);
 if(destAddr)SetConnectionEndpoint(M2C_FIELD(request,u16 *,0x24),M2C_FIELD(request,u16 *,0x26),destAddr);
 state2=M2C_FIELD(socket,s8 *,SOCK_STATE);isStream=1;
 sendBuffer=M2C_FIELD(socket,s32 *,SOCK_TX_BUF);
 if(state2 && state2!=4)isStream=0;
 if(isStream)headerSize=SOCK_TX_HDR_STREAM;else headerSize=SOCK_TX_HDR_DGRAM;
 if(state2 && state2!=4)maxChunk=M2C_FIELD(socket,s32 *,SOCK_TX_SIZE)-headerSize;
 else maxChunk=GetMaxSendChunk(M2C_FIELD(socket,s32 *,SOCK_TX_SIZE)-headerSize);
 loop:
 read=ReadSendRequest(sendBuffer+headerSize,maxChunk,request);
 if(read>0) {
 sent=SendNetPacket(sendBuffer+headerSize,read);
 if(sent<=0) {
 state3=M2C_FIELD(socket,s8 *,SOCK_STATE);valid=1;
 if(state3 && state3!=4)valid=0;
 if(valid){
 M2C_FIELD(socket,s16 *,SOCK_FLAGS)&=~14;
 M2C_FIELD(socket,s16 *,SOCK_FLAGS)|=128;
 WaitForTlsCloseNotify();
 }
 total=-76;
 }else{total+=sent;goto loop;}
 }
 }else total=-76;
 M2C_FIELD(sendConn,u16 *,SEND_RING_READ)=M2C_FIELD(request,u16 *,0x20);
 OS_WakeupThread((s32)sendConn+SEND_RING_WAIT);
 return total;
}

/* Clamps a requested send size to a whole number of the connection's send units.
   A unit is twice the smaller of the connection's two send windows (0x2C/0x2E),
   further capped by the network stack's maximum (gNetStackState+0x24); without a
   connection the stack maximum is used.  Returns `size` itself when no unit is
   known or the unit is larger than the request. */
s32 GetMaxSendChunk(s32 size) {
    s32 RuntimeIntDivMod(s32, s32);
    extern M2C_UNK gSocketManager;
    extern M2C_UNK gNetStackState;
    s32 count;
    s32 lock;
    s32 chunkUnit;
    s32 maxUnit;
    s32 sendWindow;
    s32 unit;
    void *socket;
    socket = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), void **, SOCK_OBJECT_RAW);
    lock = OS_DisableInterrupts();
    if (socket != NULL) {
        unit = M2C_FIELD(socket, u16 *, 0x2E);
        if ((unit != 0) && (sendWindow = M2C_FIELD(socket, u16 *, 0x2C), sendWindow != 0)) {
            maxUnit = M2C_FIELD(&gNetStackState, s32 *, 0x24);
            if (unit > sendWindow) unit = sendWindow;
            if (unit > maxUnit) unit = maxUnit;
            chunkUnit = unit * 2;
        } else {
            chunkUnit = M2C_FIELD(&gNetStackState, s32 *, 0x24) * 2;
        }
    } else {
        chunkUnit = M2C_FIELD(&gNetStackState, s32 *, 0x24) * 2;
    }
    OS_RestoreInterrupts(lock);
    if (chunkUnit > 0) {
        count = RuntimeIntDivMod(size, chunkUnit);
        if (count > 0) return chunkUnit * count;
    }
    return size;
}

/* Drain up to maxBytes from a queued send request's two ring pieces into the
 * destination buffer, advancing the request's read pointers, and return how many
 * bytes were copied. */
s32 ReadSendRequest(u8 *dest, s32 maxBytes, SendRequest *req) {
    M2C_UNK MI_CpuCopy8(s32, s32, s32);
    s32 remaining;
    s32 firstLen;
    s32 secondLen;

    firstLen = req->firstLen;
    secondLen = req->secondLen;
    if (firstLen > maxBytes) {
        firstLen = maxBytes;
        secondLen = 0;
    } else {
        remaining = maxBytes - firstLen;
        if (secondLen > remaining) {
            secondLen = remaining;
        }
    }
    if (firstLen > 0) {
        MI_CpuCopy8(req->firstPtr, (s32)dest, firstLen);
        req->firstPtr = (s32) (req->firstPtr + firstLen);
        req->firstLen = (s32) (req->firstLen - firstLen);
    }
    if (secondLen > 0) {
        MI_CpuCopy8(req->secondPtr, (s32)dest + firstLen, secondLen);
        req->secondPtr = (s32) (req->secondPtr + secondLen);
        req->secondLen = (s32) (req->secondLen - secondLen);
    }
    return firstLen + secondLen;
}

#pragma opt_common_subs off
/* Shut a socket down once its outstanding operation has finished.  A socket the
 * stack does not know, one that never opened, and one that is either still busy
 * or has already failed are refused; otherwise the socket is marked failed and
 * the shutdown task is posted on its send connection, which tears the connection
 * down when the socket is still duplex. */
s32 SocketShutdown(void *socket) {
    s32 SocketShutdownTask(void *);
    s32 SocketAllocTask(void *, s32, s32);
    s32 SocketSubmitSendTask(s32, s32);
    s32 SocketIsUnregistered(void);
    void *sendConn;
    s32 opened;

    if (SocketIsUnregistered() != 0) {
        return -0x1C;
    }
    if (socket == 0) {
        opened = 0;
    } else {
        opened = 0;
        if (M2C_FIELD(socket, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_READY) {
            opened = 1;
        }
    }
    if (opened == 0) {
        return -0x27;
    }
    if (!(M2C_FIELD(socket, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_DONE) || (M2C_FIELD(socket, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_ERROR)) {
        return -0x38;
    }
    M2C_FIELD(socket, volatile s16 *, SOCK_FLAGS) |= SOCK_FLAG_ERROR;
    sendConn = M2C_FIELD(socket, void **, SOCK_TX_CONN);
    if (sendConn != NULL) {
        s32 owner = M2C_FIELD(sendConn, s32 *, SEND_RING_OWNER);
        if (owner != 0) {
            owner = SocketAllocTask(SocketShutdownTask, owner, M2C_FIELD(socket, s8 *, SOCK_BLOCKING));
            if (owner == 0) {
                return -0x21;
            }
            return SocketSubmitSendTask(M2C_FIELD(sendConn, s32 *, SEND_RING_OWNER), owner);
        }
    }
    return 0;
}
#pragma opt_common_subs reset
/* Shutdown task SocketShutdown posts on the socket's send connection: while the
 * socket is still duplex (state 0 or 4), close its transport so both directions
 * are torn down. */
s32 SocketShutdownTask(void *request) {
    M2C_UNK CloseTransport();
    s32 duplex;
    s8 state;

    duplex = 1;
    state = M2C_FIELD(M2C_FIELD(request, void **, TASK_SOCKET), s8 *, SOCK_STATE);
    if ((state != SOCK_STATE_IDLE) && (state != SOCK_STATE_CONNECTED)) {
        duplex = 0;
    }
    if (duplex != 0) {
        CloseTransport();
    }
    return 0;
}

/* True when the socket has left the active list but has not reached the closed
 * list yet: its shutdown is done and it is waiting to be reaped. */
s32 SocketIsDestroyed(s32 socket) {
    s32 SocketIsUnregistered();
    s32 SocketIsClosed(s32);

    if ((socket >= 0) && (SocketIsUnregistered(socket) != 0) && (SocketIsClosed(socket) == 0)) {
        return 1;
    }
    return 0;
}

/* Close a socket: refuse an invalid handle (-28), a socket the stack reports as
 * already closed (-26) and one it no longer knows (0, nothing to do); a socket
 * that never opened gives -39, one whose close already started -26.  Otherwise
 * mark it closing and failed, and while it is still duplex post a stop to its
 * send connection's task queue; then queue the close task that tears both
 * connections down and moves the socket to the closed list. */
s32 SocketClose(s32 socket) {
M2C_UNK SocketQueueTask(s32, M2C_UNK); M2C_UNK SocketSubmitTask();

s32 SocketCloseTask(void *);
void *task;
s32 ready,duplex; s8 state;
if(socket<=0)return -28;
if(SocketIsClosed(socket)!=0)return -26;
if(SocketIsUnregistered(socket)!=0)return 0;
ready=0;
if(socket!=0)ready=(M2C_FIELD(socket,volatile s16*,SOCK_FLAGS)&SOCK_FLAG_READY)!=0;
if(!ready)return -39;
if(M2C_FIELD(socket,s16*,SOCK_FLAGS)&SOCK_FLAG_CLOSING)return -26;
duplex=1;
M2C_FIELD(socket,volatile s16*,SOCK_FLAGS)=M2C_FIELD(socket,volatile s16*,SOCK_FLAGS)|SOCK_FLAG_ERROR|SOCK_FLAG_CLOSING;
state=M2C_FIELD(socket,s8*,SOCK_STATE);
if(state!=0 && state!=4)duplex=0;
if(duplex)SocketQueueTask(M2C_FIELD(socket,s32*,SOCK_TX_CONN),0);
task=(void*)SocketAllocTask(&SocketCloseTask,socket,1);
M2C_FIELD(task,s32*,TASK_NOTIFY)=0;
SocketSubmitTask(socket,task);
return 0;
}

/* Close task of a socket: while the socket is still duplex, shut its send
 * connection down (join the connection's thread, finish the pending TCP send and
 * reset the connection), clear the stack's current raw connection, drop the
 * socket's busy/done flags, post a stop to the connection the socket still uses,
 * then move the socket from the active list to the closed list under the
 * interrupt lock and mark it closed. */
s32 SocketCloseTask(void *request) {
    M2C_UNK CloseTransport();
    M2C_UNK WaitForTlsCloseNotify();
    M2C_UNK CloseRawConnection();
    M2C_UNK ClearCurrentRawConnection();
    M2C_UNK SocketQueueTask(s32, s32);
    void SocketRemoveFromActiveList(M2C_UNK);
    void SocketAddToClosedList(void *);
    s32 irqState;
    s32 connection;
    s32 duplex;
    s8 state;
    void *socket;

    socket = M2C_FIELD(request, void **, TASK_SOCKET);
    duplex = 1;
    state = M2C_FIELD(socket, s8 *, SOCK_STATE);
    if ((state != SOCK_STATE_IDLE) && (state != SOCK_STATE_CONNECTED)) duplex = 0;
    if (duplex != 0) {
        OS_JoinThread(M2C_FIELD(socket, s32 *, SOCK_TX_CONN) + 0x20); /* the send connection's thread */
        CloseTransport();
        WaitForTlsCloseNotify();
        CloseRawConnection();
    }
    ClearCurrentRawConnection();
    M2C_FIELD(socket, s16 *, SOCK_FLAGS) &= ~(SOCK_FLAG_BUSY | SOCK_FLAG_DONE);
    if (M2C_FIELD(socket, s8 *, SOCK_STATE) == SOCK_STATE_SEND_ONLY) connection = M2C_FIELD(socket, s32 *, SOCK_TX_CONN);
    else connection = M2C_FIELD(socket, s32 *, SOCK_RAW);
    SocketQueueTask(connection, 0);
    irqState = OS_DisableInterrupts();
    SocketRemoveFromActiveList((M2C_UNK)socket);
    SocketAddToClosedList(socket);
    OS_RestoreInterrupts(irqState);
    M2C_FIELD(socket, s16 *, SOCK_FLAGS) |= SOCK_FLAG_CLOSED;
    return 0;
}

/* Tear down an object: free its children, detach from queues, then free the object itself. */
M2C_UNK SocketDestroy(s32 obj) {
extern void *gNetAllocator;
void ConnectionAbort(s32);
void SocketRemoveFromActiveList(M2C_UNK);
void SocketRemoveFromClosedList(M2C_UNK);
void OS_WakeupThread(s32);
s32 child,next,lock,active;
s8 state;
if(!obj)return;
M2C_FIELD(obj,s16*,0x70)=0;
state=M2C_FIELD(obj,s8*,0x73);active=1;
if(state!=0 && state!=4)active=0;
if(active){
ConnectionAbort(M2C_FIELD(obj,s32*,0x68));ConnectionAbort(M2C_FIELD(obj,s32*,0x64));
}else if(state==1){
child=M2C_FIELD(M2C_FIELD(obj,s32*,0x64),s32*,0x104);
while(child){next=M2C_FIELD(child,s32*,0); M2C_FIELD(gNetAllocator,void (**)(s32),0x1c)(child);child=next;}
M2C_FIELD(M2C_FIELD(obj,s32*,0x64),s16*,0x108)=0;
M2C_FIELD(M2C_FIELD(obj,s32*,0x64),s32*,0x100)=0;
M2C_FIELD(M2C_FIELD(obj,s32*,0x64),s32*,0x104)=0;
OS_WakeupThread(M2C_FIELD(obj,s32*,0x64)+0x10c);
ConnectionAbort(M2C_FIELD(obj,s32*,0x64));
}else if(state==2)ConnectionAbort(M2C_FIELD(obj,s32*,0x68));
lock=OS_DisableInterrupts();
SocketRemoveFromActiveList(obj);SocketRemoveFromClosedList(obj);
M2C_FIELD(gNetAllocator,void (**)(s32),0x1c)(obj);
OS_RestoreInterrupts(lock);
}

/* Tear a raw connection's task queue down: wait for the connection's worker thread
 * to finish, then take every task still queued on it, tell the caller waiting on
 * the task that it was aborted (SOCK_TASK_ABORTED) and give the task back to the
 * pool. */
void ConnectionAbort(s32 conn) {
    M2C_UNK OS_JoinThread(s32);
    M2C_UNK OS_Reschedule();
    M2C_UNK OS_DisableScheduler();
    M2C_UNK OS_EnableScheduler();
    M2C_UNK OS_SendMessage(s32, M2C_UNK, M2C_UNK);
    s32 OS_ReceiveMessage(s32, void **, M2C_UNK);
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    M2C_UNK SocketFreeTask(void *);
    void *task;
    s32 waiter;
    s32 irq;

    if (conn == 0) {
        return;
    }
    OS_JoinThread(conn + 0x20);
    irq = OS_DisableInterrupts();
    OS_DisableScheduler();
    if (OS_ReceiveMessage(conn, &task, 0) != 0) {
        do {
            if (task != NULL) {
                waiter = M2C_FIELD(task, s32 *, TASK_NOTIFY);
                if (waiter != 0) {
                    OS_SendMessage(waiter, SOCK_TASK_ABORTED, 0);
                }
                SocketFreeTask(task);
            }
        } while (OS_ReceiveMessage(conn, &task, 0) != 0);
    }
    OS_EnableScheduler();
    OS_Reschedule();
    OS_RestoreInterrupts(irq);
}

/* With interrupts disabled, hand every socket on the closed list to SocketDestroy
 * until the list is empty. */
M2C_UNK ReapClosedSockets(void) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    M2C_UNK SocketDestroy(s32);
    extern M2C_UNK gClosedSocketList;
    s32 irq = OS_DisableInterrupts();
    if (gClosedSocketList != 0) {
        do { SocketDestroy(gClosedSocketList); } while (gClosedSocketList != 0);
    }
    OS_RestoreInterrupts(irq);
}

/* Shuts the network stack down: latches its init token, waits while sockets are
   still closing, frees the socket task pool and, when the net allocator has no
   block outstanding, frees the stack's buffer and clears gNetAllocator.  Returns
   the task-pool result (negative on failure). */
s32 NetworkShutdown(void) {
    M2C_UNK SleepMilliseconds(M2C_UNK);
    M2C_UNK func_0201a4f8(s32);
    M2C_UNK NetworkStopWorkers();
    s32 NetworkFreeTaskPool();
    extern void *gNetAllocator;
    extern s32 gLocalIpAddress;
    extern s32 gNetSavedLocalIp;
    extern M2C_UNK gNetStackState;
    s32 result;
    if (gNetSavedLocalIp == 0) { gNetSavedLocalIp = gLocalIpAddress; }
    if (NetworkPollClosing() == SOCK_BUSY) {
        do { SleepMilliseconds(0x64); } while (NetworkPollClosing() == SOCK_BUSY);
    }
    result = NetworkFreeTaskPool();
    if (result >= 0) {
        NetworkStopWorkers();
        func_0201a4f8(0);
        if (M2C_FIELD(gNetAllocator, s32 *, 0x28) == 0) {
            M2C_FIELD(gNetAllocator, void (**)(s32), 0x1C)(M2C_FIELD(&gNetStackState, s32 *, 0x1C));
        }
        gNetAllocator = NULL;
    }
    return result;
}

/* Closes every socket that is still open, one per pass, skipping the socket
 * being shut down (gClosingSocket) and those already closing.  Returns 0 once
 * the open and closed lists are both empty, SOCK_BUSY while any is left. */
s32 SocketCloseAll(void) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    M2C_UNK SocketClose(s32);
    extern M2C_UNK gActiveSocketList, gClosedSocketList;
    extern s32 gClosingSocket;
    s32 socket;
    s32 lock;
retry:
    lock = OS_DisableInterrupts();
    socket = gActiveSocketList;
    while (socket != 0) {
        if (socket != gClosingSocket && !(M2C_FIELD(socket, s16 *, SOCK_FLAGS) & SOCK_FLAG_CLOSING)) { break; }
        socket = M2C_FIELD(socket, s32 *, SOCK_LIST_NEXT);
    }
    OS_RestoreInterrupts(lock);
    if (socket != 0) { SocketClose(socket); goto retry; }
    if ((gActiveSocketList == 0 || (gActiveSocketList == gClosingSocket && M2C_FIELD(gActiveSocketList, s32 *, SOCK_LIST_NEXT) == 0)) && gClosedSocketList == 0) { return 0; }
    return SOCK_BUSY;
}

/* One step of the network shutdown: close the sockets still open, then the one
 * that is being shut down, reap the closed ones, and report SOCK_BUSY until the
 * network task has finished. */
s32 NetworkPollClosing(void) {
    s32 IsNetworkTaskFinished();
    M2C_UNK SocketClose(s32);
    M2C_UNK ReapClosedSockets();
    s32 SocketCloseAll();
    M2C_UNK WFC_SetSendCallback(M2C_UNK);
    extern s32 gClosingSocket;
    s32 result;

    if (gClosingSocket != 0) {
        result = SocketCloseAll();
        if (result == 0) {
            SocketClose(gClosingSocket);
            if (SocketIsDestroyed(gClosingSocket) != 0) {
                gClosingSocket = 0;
            }
            result = SOCK_BUSY;
        }
        ReapClosedSockets();
    } else if (IsNetworkTaskFinished() == 0) {
        result = SOCK_BUSY;
    } else {
        WFC_SetSendCallback(0);
        result = 0;
    }
    return result;
}

/* Resolve a host name to an IPv4 address: hand the network stack a temporary raw
 * connection whose receive and pending-datagram buffers share one allocated block,
 * look the name up, then restore the previous connection and free the block. */
s32 LookupHostAddress(s32 hostname) {
    M2C_UNK MI_CpuFill8(void *, M2C_UNK, M2C_UNK);
    M2C_UNK SetCurrentRawConnection(void *);
    M2C_UNK ClearCurrentRawConnection();
    s32 DnsLookupAddress(s32);
    extern void *gNetAllocator;
    u8 conn[0x64];
    s32 block;
    s32 address;

    if (hostname == 0) { return 0; }
    block = M2C_FIELD(gNetAllocator, s32 (**)(M2C_UNK), NET_ALLOC_ALLOC)(DNS_LOOKUP_BLOCK_BYTES);
    if (block == 0) { return 0; }
    MI_CpuFill8(conn, 0, 0x64);
    M2C_FIELD(conn, u32 *, CONN_RX_BUFFER) = block;
    M2C_FIELD(conn, u32 *, CONN_IN_WINDOW) = DNS_LOOKUP_RX_BYTES;
    M2C_FIELD(conn, u32 *, CONN_RX_PENDING_BUF) = block + DNS_LOOKUP_RX_BYTES;
    M2C_FIELD(conn, u32 *, CONN_RX_MAX) = DNS_LOOKUP_PENDING_BYTES;
    SetCurrentRawConnection(conn);
    address = DnsLookupAddress(hostname);
    ClearCurrentRawConnection();
    M2C_FIELD(gNetAllocator, M2C_UNK (**)(s32), NET_ALLOC_FREE)(block);
    return address;
}

/* Resolve `hostname` with the configured DNS servers cleared, so that only a
 * literal IPv4 address string resolves (a host name would need a DNS query):
 * save the two server addresses under a disabled-interrupt lock, look the name up
 * and put them back. */
s32 DnsLookupAddressWithoutServers(s32 hostname) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 DnsLookupAddress(s32);
    extern M2C_UNK gDnsServerAddresses;
    s32 address;
    s32 lock;
    s32 primary;
    s32 secondary;

    lock = OS_DisableInterrupts();
    primary = M2C_FIELD(&gDnsServerAddresses, s32 *, DNS_SERVER_PRIMARY);
    secondary = M2C_FIELD(&gDnsServerAddresses, s32 *, DNS_SERVER_SECONDARY);
    M2C_FIELD(&gDnsServerAddresses, s32 *, DNS_SERVER_PRIMARY) = 0;
    M2C_FIELD(&gDnsServerAddresses, s32 *, DNS_SERVER_SECONDARY) = 0;
    address = DnsLookupAddress(hostname);
    M2C_FIELD(&gDnsServerAddresses, s32 *, DNS_SERVER_PRIMARY) = primary;
    M2C_FIELD(&gDnsServerAddresses, s32 *, DNS_SERVER_SECONDARY) = secondary;
    OS_RestoreInterrupts(lock);
    return address;
}

/* Store the two IPv4 DNS servers, in lookup order.  They can only be set once the
 * stack has a local address (the DNS query needs one to originate from); before
 * that the call fails with -39. */
s32 SetDnsServerAddresses(s32 primary, s32 secondary) {
    s32 GetLocalIpAddress();
    extern M2C_UNK gDnsServerAddresses;
    if (GetLocalIpAddress() == 0) {
        return -0x27;
    }
    M2C_FIELD(&gDnsServerAddresses, s32 *, DNS_SERVER_PRIMARY) = primary;
    M2C_FIELD(&gDnsServerAddresses, s32 *, DNS_SERVER_SECONDARY) = secondary;
    return 0;
}

/* Return the local IPv4 address the network stack was configured with.  While it
 * is not known yet, wait briefly for the WFC init callback as long as
 * initialisation is still pending (gNetInitStatus == 1) and we are not running in
 * IRQ mode; once the address is known, latch a copy the first time. */
s32 GetLocalIpAddress(void) {
    M2C_UNK SleepMilliseconds(M2C_UNK);
    s32 GetProcessorMode();
    extern s32 gLocalIpAddress;
    extern s32 gNetSavedLocalIp;
    extern s32 gNetInitStatus;
    if (gLocalIpAddress == 0) {
        if (((gNetInitStatus & 3) == 1) && (GetProcessorMode() != 0x12)) {
            SleepMilliseconds(0xA);
        }
    } else if (gNetSavedLocalIp == 0) {
        gNetSavedLocalIp = gLocalIpAddress;
    }
    return gLocalIpAddress;
}

/* Polls a socket and returns a readiness bitmask: bit 0 readable (data queued),
 * bit 3 writable (send space free), bit 5 the last receive timed out, bit 6 idle
 * (no operation pending) and bit 7 the socket is no longer registered.  A finished
 * operation that has not been read yet has its busy/done flags cleared. */
s32 SocketPoll(void *sock) {
    s32 SocketGetSendRingFreeBytes(void *);
    s32 SocketReadableBytes(void *);
    s32 lock, pending, status = 0;
    s8 state;

    if (SocketIsUnregistered() != 0) status |= 0x80;
    else {
        if (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_TIMEOUT) status |= 0x20;
        if (M2C_FIELD(sock, s8 *, SOCK_STATE) == 1 || (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_DONE)) {
            lock = OS_DisableInterrupts();
            if (SocketReadableBytes(sock) > 0) status |= 1;
            if (SocketGetSendRingFreeBytes(sock) > 0) status |= 8;
            OS_RestoreInterrupts(lock);
        }
        state = M2C_FIELD(sock, s8 *, SOCK_STATE);
        pending = 1;
        if (state != 0 && state != 4) pending = 0;
        if (pending) {
            if ((M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_DONE) && M2C_FIELD(sock, u8 *, 8) != 4) {
                if (!(status & 1)) M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) &= ~6;
            }
            if (!(M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_BUSY) && !(M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_DONE)) status |= 0x40;
        }
    }
    return status;
}

/* Bytes a socket has ready to read: on a receive-only socket the payload length of
 * the next queued record, on a duplex socket the unread bytes of its receive
 * window.  Zero when the socket has no connection or only sends. */
s32 SocketReadableBytes(void *sock) {
    s8 state;
    void *raw;
    void *record;
    s32 readable;

    raw = M2C_FIELD(sock, void **, SOCK_RAW);
    readable = 0;
    if (raw != NULL) {
        state = M2C_FIELD(sock, s8 *, SOCK_STATE);
        if (state == SOCK_STATE_RECV_ONLY) {
            record = M2C_FIELD(raw, void **, CONN_RECV_HEAD);
            if (record != NULL) { readable = M2C_FIELD(record, u16 *, REC_LEN); }
        } else if (state == SOCK_STATE_IDLE || state == SOCK_STATE_CONNECTED) {
            readable = M2C_FIELD(sock, s32 *, CONN_RX_POS) - M2C_FIELD(raw, s32 *, CONN_RECV_PENDING);
        }
    }
    return readable;
}

s32 AlignSize4(s32 arg0) {
    return (arg0 + 3) & ~3;
}

/* Put a socket object on the socket layer's list of active sockets (a singly
 * linked list through the socket's SOCK_LIST_NEXT field). */
void RegisterActiveSocket(void *socket) {
    void SocketListPrepend(void **, void *);
    extern M2C_UNK gActiveSocketList;
    SocketListPrepend((void **)&gActiveSocketList, socket);
}

void SocketListPrepend(void **arg0, void *arg1) {
    M2C_FIELD(arg1, void **, 0x7C) = (void *) *arg0;
    *arg0 = arg1;
}

/* Add a socket object to the socket layer's list of closed sockets (a
 * singly linked list through the socket's SOCK_LIST_NEXT field). */
void SocketAddToClosedList(void *socket) {
    extern M2C_UNK gClosedSocketList;
    SocketListPrepend((void **)&gClosedSocketList, socket);
}

/* Remove a socket object from the socket layer's list of active sockets. */
void SocketRemoveFromActiveList(s32 socket) {
    s32 SocketUnlinkFromList(s32 *, s32);
    extern M2C_UNK gActiveSocketList;
    SocketUnlinkFromList((s32 *)&gActiveSocketList, socket);
}

/* Unlink a socket object from one of the socket layer's lists: find the list
 * pointer that refers to the socket and make it skip the socket. */
s32 SocketUnlinkFromList(s32 *list, s32 socket) {
    void *SocketFindLink(void *, s32);
    void *link = SocketFindLink(list, socket);
    if (link) M2C_FIELD(link, s32 *, 0) = M2C_FIELD(socket, s32 *, SOCK_LIST_NEXT);
}

void *SocketFindLink(void *arg0, s32 arg1);
/* Find a socket in one of the socket layer's lists and return the address of the
 * pointer that refers to it -- the list head, or the previous socket's
 * SOCK_LIST_NEXT field -- so the caller can unlink it; NULL when the socket is
 * not in the list.  The handle is the socket object's own address. */
void *SocketFindLink(void *link, s32 socket) {
    void *p = M2C_FIELD(link, void **, 0);

    while (p) {
        if ((s32)p == socket) return link;
        link = (u8 *)p + SOCK_LIST_NEXT;
        p = M2C_FIELD(p, void **, SOCK_LIST_NEXT);
    }
    return NULL;
}

/* Remove a socket object from the socket layer's list of closed sockets. */
void SocketRemoveFromClosedList(s32 socket) {
    s32 SocketUnlinkFromList(s32 *, s32);
    extern M2C_UNK gClosedSocketList;
    SocketUnlinkFromList((s32 *)&gClosedSocketList, socket);
}

/* Whether a socket handle is not registered: 1 for a non-positive handle or one
 * absent from the list of active sockets, 0 when it is registered. */
s32 SocketIsUnregistered(s32 socket) {
    extern M2C_UNK gActiveSocketList;
    if (socket <= 0 || SocketFindLink(&gActiveSocketList, socket) == NULL) return 1;
    return 0;
}

/* Whether socket handle `socket` is in the socket layer's list of closed sockets. */
s32 SocketIsClosed(s32 socket) {
    extern M2C_UNK gClosedSocketList;
    return SocketFindLink(&gClosedSocketList, socket) != NULL;
}

/* Create a socket from the default template: a stream (TCP) one when `type` is
 * SOCK_TYPE_STREAM, a datagram (UDP) one otherwise.  The address family and the
 * protocol are ignored; returns the socket, negative when none could be made. */
s32 SocketCreate(s32 domain, s32 type, s32 protocol) {
    s32 SocketCreateFromConfig(M2C_UNK *);
    extern M2C_UNK gUdpSocketConfig;
    extern M2C_UNK gTcpSocketConfig;
    if (type == SOCK_TYPE_STREAM) { return SocketCreateFromConfig(&gTcpSocketConfig); }
    return SocketCreateFromConfig(&gUdpSocketConfig);
}

/* Bind a socket to the port of a GhiSocketAddress, converting it from network
 * byte order to host order. */
void SocketBindAddress(s32 socket, GhiSocketAddress *address) {
    M2C_UNK SocketBind(M2C_UNK, u16);
    u16 netPort;

    netPort = address->port;
    SocketBind(socket, (u16) ((u8) ((s32) netPort >> 8) | ((netPort << 8) & 0xFF00)));
}

/* Convert the socket address's network-order port and IPv4 address to host
 * order and hand them to SocketConnect. */
s32 SocketConnectAddress(s32 socket, GhiSocketAddress *address) {
    s32 SocketConnect(s32, u16, s32);
    u16 netPort;
    u32 netAddr;

    netPort = address->port;
    netAddr = address->addr;
    return SocketConnect(socket, (u16) ((u8) ((s32) netPort >> 8) | ((netPort << 8) & 0xFF00)), ((netAddr << 0x18) & 0xFF000000) | (((netAddr << 8) & 0xFF0000) | ((u8) (netAddr >> 0x18) | ((netAddr >> 8) & 0xFF00))));
}

/* Receive up to `len` bytes from `socket` into `buf` with no flags and no sender
 * report; the plain wrapper over SocketRecvFrom, the recv counterpart of SocketSend. */
s32 SocketReceive(M2C_UNK socket, M2C_UNK buf, M2C_UNK len) {
    M2C_UNK SocketRecvFrom(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    return SocketRecvFrom(socket, buf, len, 0, 0, 0);
}

/* Receive up to len bytes from socket into buf with flags (SOCK_RECV_NONBLOCK
 * makes it a try); the sender is not reported, so the peer outputs are NULL. */
s32 SocketRecvFlags(M2C_UNK socket, M2C_UNK buf, M2C_UNK len, s32 flags) {
    M2C_UNK SocketRecvFrom(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    return SocketRecvFrom(socket, buf, len, 0, 0, flags);
}

/* Receive up to len bytes on a socket and report the sender in peer as a socket
 * address: the port and the IPv4 address are written in network byte order. */
s32 SocketRecvFromAddress(M2C_UNK sock, M2C_UNK buf, M2C_UNK len, s32 flags, void *peer) {
    u32 peerAddr; u16 peerPort;
    s32 result = SocketRecvFrom(sock, buf, len, &peerPort, &peerAddr, flags);
    if (result < 0) return result;
    if (peer == NULL) return result;
    ((GhiSocketAddress *)peer)->port = ((peerPort >> 8)&255)|((peerPort << 8)&0xff00);
    ((GhiSocketAddress *)peer)->addr = ((peerAddr >> 24)&255)|((peerAddr >> 8)&0xff00)|((peerAddr << 8)&0xff0000)|((peerAddr << 24)&0xff000000);
    return result;
}

/* Send data on a socket without specifying a destination address. */
void SocketSend(M2C_UNK socket, M2C_UNK buffer, M2C_UNK length) {
    M2C_UNK SocketSendTo(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    SocketSendTo(socket, buffer, length, 0, 0, 0);
}

/* Send up to len bytes from buf on socket with flags; the send counterpart of
 * SocketRecvFlags, no fixed peer is given, so the peer port and address are NULL. */
void SocketSendFlags(M2C_UNK socket, M2C_UNK buf, M2C_UNK len, s32 flags) {
    M2C_UNK SocketSendTo(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    SocketSendTo(socket, buf, len, 0, 0, flags);
}

