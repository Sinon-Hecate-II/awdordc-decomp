/* 22 functions from 0x0201F89C to 0x02020738 (main), found by ds-decomp. */
#include "common.h"
#include "net_socket.h"

/* Put the socket into listen on its receive port: the socket's task binds that
 * port to the connection and starts the transport listening, then reports the
 * peer endpoint the connection ends up with through peerPort and peerAddr.
 * Fails with -28 when the network or the socket is gone, uninitialised or busy
 * or has no receive port yet, -39 when the socket is not ready, and -6 when it
 * is not a blocking stream socket. */
s32 SocketListen(void *sock, u16 *peerPort, s32 *peerAddr) {
    s32 func_020214a8();
    void *func_0201f1d0(s32 (*)(void *), void *, s8);
    s32 SocketSubmitRecvTask(void *, void *);
    s32 SocketListenTask(void *);
    s32 ready, usable;
    s8 state;
    void *request;

    if (func_020214a8() != 0) {
        return -28;
    }
    ready = 0;
    if (sock != 0) {
        ready = (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_READY) != 0;
    }
    if (ready == 0) {
        return -39;
    }
    if (M2C_FIELD(sock, s16 *, SOCK_FLAGS) & SOCK_FLAG_BUSY) {
        return -28;
    }
    state = M2C_FIELD(sock, s8 *, SOCK_STATE);
    usable = 1;
    if (state != 0 && state != 4) {
        usable = 0;
    }
    if (usable == 0) {
        return -28;
    }
    if (M2C_FIELD(sock, s8 *, SOCK_BLOCKING) != SOCK_BLOCKING_ON) {
        return -6;
    }
    if (M2C_FIELD(sock, u16 *, SOCK_RECV_PORT) == 0) {
        return -28;
    }
    request = func_0201f1d0((s32 (*)(void *))SocketListenTask, sock, (s8)M2C_FIELD(sock, s8 *, SOCK_BLOCKING));
    M2C_FIELD(request, u16 *, 0x10) = M2C_FIELD(sock, u16 *, SOCK_RECV_PORT);
    M2C_FIELD(request, s32 *, 0x14) = (s32)peerPort;
    M2C_FIELD(request, s32 *, 0x18) = (s32)peerAddr;
    M2C_FIELD(sock, s16 *, SOCK_FLAGS) = (s16)(M2C_FIELD(sock, s16 *, SOCK_FLAGS) | SOCK_FLAG_BUSY);
    return SocketSubmitRecvTask(sock, request);
}

/* Task half of SocketListen: bind the socket's receive port to its raw connection
 * and start the transport listening, drop the connection's pending receive bytes,
 * then report the peer endpoint back through the task's out-pointers and mark the
 * socket's operation done, all under the connection mutex. */
s32 SocketListenTask(void *task) {
    M2C_UNK LockMutex(s32);
    M2C_UNK UnlockMutex(void *);
    M2C_UNK SetConnectionEndpoint(u16, M2C_UNK, M2C_UNK);
    M2C_UNK ListenTransport();
    s32 GetSocketEndpoints(u16 *, M2C_UNK *);
    M2C_UNK peerAddr;
    u16 peerPort;
    s32 result;
    void *socket;
    void *raw;

    socket = M2C_FIELD(task, void **, TASK_SOCKET);
    raw = M2C_FIELD(socket, void **, SOCK_RAW);
    LockMutex(raw + CONN_MUTEX);
    SetConnectionEndpoint(M2C_FIELD(task, u16 *, LISTEN_TASK_LOCAL_PORT), 0, 0);
    ListenTransport();
    M2C_FIELD(raw, s32 *, CONN_RECV_PENDING) = 0;
    result = GetSocketEndpoints(&peerPort, &peerAddr);
    *M2C_FIELD(task, u16 **, LISTEN_TASK_PEER_PORT_PTR) = peerPort;
    *M2C_FIELD(task, s32 **, LISTEN_TASK_PEER_ADDR_PTR) = result;
    M2C_FIELD(socket, s16 *, SOCK_FLAGS) = (s16) (M2C_FIELD(socket, s16 *, SOCK_FLAGS) | SOCK_FLAG_DONE);
    UnlockMutex(raw + CONN_MUTEX);
    return 0;
}

/* Bind a local receive port to the socket and, when the socket is receive-only,
 * start connecting it to its peer.  Fails with SOCK_ERROR when the network or the
 * socket is unavailable, SOCK_NOT_READY when the socket is not initialised, and
 * SOCK_ALREADY when a task is already running on it. */
s32 SocketBind(void *sock,s32 port) {
s32 SocketIsUnregistered(); s32 SocketSubmitConnectTask(void *);s32 ready;
if(SocketIsUnregistered()!=0)return SOCK_ERROR;
ready=0;if(sock)ready=(M2C_FIELD(sock,volatile s16 *,SOCK_FLAGS)&SOCK_FLAG_READY)!=0;
if(!ready)return SOCK_NOT_READY;
if(M2C_FIELD(sock,s16 *,SOCK_FLAGS)&SOCK_FLAG_BUSY)return SOCK_ALREADY;
M2C_FIELD(sock,u16 *,SOCK_RECV_PORT)=port;
if(M2C_FIELD(sock,s8 *,SOCK_STATE)!=SOCK_STATE_RECV_ONLY)return 0;
return SocketSubmitConnectTask(sock);
}

/* Start a connect to the peer port and IPv4 address: refuse when the network
 * stack is down, the socket is torn down or busy, or an operation is already
 * running.  A finished operation reports its result, a running one its progress,
 * and an idle socket points its raw connection at the peer and queues the
 * connect task. */
s32 SocketConnect(void *sock, s16 peerPort, s32 peerAddr) {
    s32 SocketIsUnregistered();
    s32 SocketSubmitConnectTask(void *);
    extern s32 gSocketDefaultRecvTimeout;
    s32 ready, usable, result;
    s8 state;

    if (SocketIsUnregistered() != 0 || (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_ERROR)) return -28;
    ready = 0;
    if (sock != 0) {
        ready = (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_READY) != 0;
    }
    if (ready == 0) return -39;
    state = M2C_FIELD(sock, s8 *, SOCK_STATE);
    usable = 1;
    if (state != 0 && state != 4) {
        usable = 0;
    }
    if (usable != 0) {
        if (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_DONE) {
            return M2C_FIELD(sock, s8 *, SOCK_BLOCKING) == SOCK_BLOCKING_ON ? -30 : 0;
        }
        if (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_BUSY) {
            return (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_TIMEOUT) ? M2C_FIELD(sock, s32 *, SOCK_STATUS) : gSocketDefaultRecvTimeout;
        }
        M2C_FIELD(sock, s16 *, SOCK_CONNECT_PORT) = peerPort;
        M2C_FIELD(sock, s32 *, SOCK_CONNECT_ADDR) = peerAddr;
        result = SocketSubmitConnectTask(sock);
        if (M2C_FIELD(sock, s8 *, SOCK_BLOCKING) != SOCK_BLOCKING_ON) result = -26;
        return result;
    }
    M2C_FIELD(sock, s16 *, SOCK_CONNECT_PORT) = peerPort;
    M2C_FIELD(sock, s32 *, SOCK_CONNECT_ADDR) = peerAddr;
    return 0;
}

/* Queue a connect task for the socket: its callback gets the local port bound to
 * the connection and the peer port/address the connect goes to, and the socket is
 * marked busy until the task reports. Returns SOCK_NO_MEMORY when no task record
 * could be allocated, else the result of posting the task. */
s32 SocketSubmitConnectTask(void *sock) {
    s32 SocketConnectTask(void *);
    void *SocketAllocTask(s32 (*)(void *), void *, s8);
    s32 SocketSubmitRecvTask(void *, void *);
    void *task = SocketAllocTask(SocketConnectTask, sock, M2C_FIELD(sock, s8 *, SOCK_BLOCKING));

    if (!task) return SOCK_NO_MEMORY;
    M2C_FIELD(task, u16 *, CONNECT_TASK_LOCAL_PORT) = M2C_FIELD(sock, u16 *, SOCK_RECV_PORT);
    M2C_FIELD(task, u16 *, CONNECT_TASK_PEER_PORT) = M2C_FIELD(sock, u16 *, SOCK_CONNECT_PORT);
    M2C_FIELD(task, s32 *, CONNECT_TASK_PEER_ADDR) = M2C_FIELD(sock, s32 *, SOCK_CONNECT_ADDR);
    M2C_FIELD(sock, s16 *, SOCK_FLAGS) |= SOCK_FLAG_BUSY;
    return SocketSubmitRecvTask(sock, task);
}

/* Connect task of a socket: point the raw connection at the peer from the task
 * record and run the transport's connect under the connection mutex.  On failure
 * the socket is flagged and SOCK_CONNECT_FAILED reported; otherwise the operation
 * is marked done. */
s32 SocketConnectTask(void *task) {
s32 ConnectTransport(); void *socket,*raw;s32 result;s8 socketState;
socket=M2C_FIELD(task,void **,TASK_SOCKET);result=0;raw=M2C_FIELD(socket,void **,SOCK_RAW);
LockMutex(raw+CONN_MUTEX);
SetConnectionEndpoint(M2C_FIELD(task,u16 *,CONNECT_TASK_LOCAL_PORT),M2C_FIELD(task,u16 *,CONNECT_TASK_PEER_PORT),M2C_FIELD(task,s32 *,CONNECT_TASK_PEER_ADDR));
M2C_FIELD(raw,s32 *,CONN_RECV_PENDING)=result;socketState=M2C_FIELD(task,s8 *,12);
if(socketState==0 || socketState==4)result=ConnectTransport();
UnlockMutex(raw+CONN_MUTEX);
if(result){M2C_FIELD(socket,volatile s16 *,SOCK_FLAGS)|=SOCK_FLAG_TIMEOUT;return SOCK_CONNECT_FAILED;}
M2C_FIELD(socket,volatile s16 *,SOCK_FLAGS)|=SOCK_FLAG_DONE;return 0;
}

#pragma optimization_level 2
/* Receive up to len bytes from sock into buf, taking the receive connection's
 * mutex around the call and reporting the sender through peerPort/peerAddr.
 * A non-blocking call (SOCK_RECV_NONBLOCK, or a socket whose blocking mode was
 * cleared) only try-locks the connection and fails with SOCK_WOULD_BLOCK when no
 * data can be read, and a blocking call is refused inside an IRQ handler.
 * Returns the received byte count, or SOCK_ERROR / SOCK_NOT_READY / SOCK_ABORTED
 * when the network, the socket or its state is not usable. */
s32 SocketRecvFrom(void *sock, s32 buf, s32 len, s32 peerPort, s32 peerAddr, s32 flags) {
    s32 LockMutex();
    s32 UnlockMutex();
    s32 TryLockMutex();
    s32 GetProcessorMode();
    s32 SocketRecvLocked(void *, s32, s32, s32, s32, s32, s32);
    s32 SocketIsUnregistered();
    void *raw;
    s32 wait;
    s32 ready;
    s32 usable;
    s8 state;

    if (SocketIsUnregistered(sock) != 0) {
        return SOCK_ERROR;
    }
    if ((flags & SOCK_RECV_NONBLOCK) || M2C_FIELD(sock, s8 *, SOCK_BLOCKING) == 0) {
        if (M2C_FIELD(sock, s8 *, SOCK_STATE) == SOCK_STATE_CONNECTED) {
            return SOCK_ERROR;
        }
        wait = 0;
    } else {
        if (GetProcessorMode() == CPSR_MODE_IRQ) {
            return SOCK_ERROR;
        }
        wait = 1;
    }
    ready = 0;
    if (sock != 0) {
        ready = (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_READY) != 0;
    }
    if (ready == 0) {
        return SOCK_NOT_READY;
    }
    state = M2C_FIELD(sock, s8 *, SOCK_STATE);
    usable = 1;
    if (state != SOCK_STATE_IDLE && state != SOCK_STATE_CONNECTED) {
        usable = 0;
    }
    if (usable != 0 && (!(M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_DONE) || (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_ERROR))) {
        return SOCK_ABORTED;
    }
    raw = M2C_FIELD(sock, void **, SOCK_RAW);
    if (!(wait & 1)) {
        if (TryLockMutex(raw + CONN_MUTEX) == 0) {
            return SOCK_WOULD_BLOCK;
        }
    } else {
        LockMutex(raw + CONN_MUTEX);
    }
    wait = SocketRecvLocked(sock, buf, len, peerPort, peerAddr, wait, flags);
    UnlockMutex(raw + CONN_MUTEX);
    return wait;
}
#pragma optimization_level reset
/* Receive up to len bytes from sock into buf with the socket's mutex already
 * held, through the path its state selects: a receive-only socket takes the
 * next queued record, while a duplex socket reads the connection's receive
 * window and releases it once the read finished.  With the peek bit (2) set in
 * flags the raw connection is told to keep the record for the duration of the
 * call; wait is passed on as the receive flags (bit 0: wait for data). */
s32 SocketRecvLocked(void *sock, s32 buf, s32 len, s32 peerPort, s32 peerAddr, s32 wait, s32 flags) {
 s32 SocketRecv(void *,s32,s32,s32,s32,s32);
 s32 SocketRecvData(void *,s32,s32,s32,s32,s32);
 s32 SocketReleaseRecvWindow(void *);
 void *raw=M2C_FIELD(sock,void **,SOCK_RAW);
 s32 peek=(flags&2)!=0 && raw!=0;
 s8 old;s32 result;
 if(peek){old=M2C_FIELD(raw,s8 *,CONN_RECV_HOLD);M2C_FIELD(raw,s8 *,CONN_RECV_HOLD)=1;}
 if(M2C_FIELD(sock,s8 *,SOCK_STATE)==SOCK_STATE_RECV_ONLY)result=SocketRecv(sock,buf,len,peerPort,peerAddr,wait);
 else{result=SocketRecvData(sock,buf,len,peerPort,peerAddr,wait);if(result>=0)SocketReleaseRecvWindow(sock);}
 if(peek)M2C_FIELD(raw,s8 *,CONN_RECV_HOLD)=old;
 return result;
}

/* Receive up to len bytes from a duplex socket into buf.  A connected socket
 * always runs the receive through a task; a socket that is still handshaking
 * reads the transport's receive window first, and only when nothing is queued
 * (SOCK_WOULD_BLOCK) and the caller asked to wait does it start the receive
 * task, which sleeps until data arrives. */
s32 SocketRecvData(void *sock, s32 buf, s32 len, s32 peerPort, s32 peerAddr, s32 flags) {
    s32 SocketStartRecvTask(void *, s32, s32, s32, s32);
    s32 SocketRecvFromWindow(void *, s32, s32, u16 *, s32 *);
    s32 result;

    if (M2C_FIELD(sock, s8 *, SOCK_STATE) == SOCK_STATE_CONNECTED) return SocketStartRecvTask(sock, buf, len, peerPort, peerAddr);
    result = SocketRecvFromWindow(sock, buf, len, peerPort, peerAddr);
    if (result != SOCK_WOULD_BLOCK) return result;
    if (!(flags & 1)) return result;
    return SocketStartRecvTask(sock, buf, len, peerPort, peerAddr);
}

#pragma optimize_for_speed off
s32 SocketRecvFromWindow(void *arg0, M2C_UNK arg1, s32 arg2, u16 *arg3, s32 *arg4) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    M2C_UNK MI_CpuCopy8(s32, M2C_UNK, s32);
    s32 GetRecvWindowData(void *, s32 *, u16 *, u16 *, s32 *);
    s32 spC;
    s32 sp8;
    u16 sp6;
    u16 sp4;
    s32 temp_r0;
    s32 temp_r4;
    s8 temp_r1;
    s32 var_r2;
    s32 var_r5;
    s32 var_r7;
    void *temp_r1_2;

    var_r7 = arg2;
    temp_r4 = OS_DisableInterrupts();
    temp_r0 = GetRecvWindowData(arg0, &spC, &sp6, &sp4, &sp8);
    if (temp_r0 != 0) {
        var_r5 = spC;
        if (var_r5 == 0) {
            var_r5 = -6;
        } else {
            temp_r1 = M2C_FIELD(arg0, s8 *, 0x73);
            var_r2 = 1;
            if (var_r7 > var_r5) {
                var_r7 = var_r5;
            }
            if (temp_r1 != 0 && temp_r1 != 4) {
                var_r2 = 0;
            }
            if (var_r2 != 0) {
                var_r5 = var_r7;
            }
            MI_CpuCopy8(temp_r0, arg1, var_r7);
            temp_r1_2 = M2C_FIELD(arg0, void **, 0x64);
            if (M2C_FIELD(temp_r1_2, s8 *, 0xFE) == 0) {
                *(s32 *)((char *)temp_r1_2 + 0xF8) = *(s32 *)((char *)temp_r1_2 + 0xF8) + var_r5;
            }
        }
    } else {
        if (spC == 0) {
            var_r5 = 0;
        } else {
            var_r5 = -0x1C;
        }
        M2C_FIELD(arg0, s16 *, 0x70) = (s16)(M2C_FIELD(arg0, s16 *, 0x70) & ~6);
    }
    if (var_r5 >= 0) {
        if (arg3 != 0 && arg4 != 0) {
            *arg3 = sp4;
            *arg4 = sp8;
        }
        if (M2C_FIELD(arg0, u16 *, 0x74) == 0) {
            M2C_FIELD(arg0, u16 *, 0x74) = sp6;
        }
    }
    OS_RestoreInterrupts(temp_r4);
    return var_r5;
}
#pragma optimize_for_speed reset
/* Report the next unread bytes of a duplex socket's transport connection: return
 * the connection's receive buffer advanced by the bytes already consumed (the raw
 * connection's pending count), set *remaining to the bytes left (-1 when the
 * pending count ran past it) and fill in the connection's local and remote
 * endpoint.  When exactly caught up on a connection that is not established there
 * is nothing to read and 0 is returned. */
s32 GetRecvWindowData(void *sock,s32 *remaining,u16 *localPort,u16 *remotePort,s32 *remoteIp) {
 void *raw=M2C_FIELD(sock,void **,SOCK_RAW);
 void *conn=M2C_FIELD(raw,void **,0xC4); /* transport connection of the raw connection */
 s32 pending=M2C_FIELD(raw,s32 *,CONN_RECV_PENDING);
 s32 avail=M2C_FIELD(conn,s32 *,CONN_RX_POS)-pending;
 if(avail>=0){
 *localPort=M2C_FIELD(conn,u16 *,CONN_LOCAL_PORT);*remotePort=M2C_FIELD(conn,u16 *,CONN_REMOTE_PORT);
 *remoteIp=M2C_FIELD(conn,s32 *,CONN_REMOTE_IP);*remaining=avail;
 if(avail==0 && M2C_FIELD(conn,u8 *,CONN_STATE)!=CONN_STATE_ESTABLISHED)return 0;
 }else{*remaining=-1;return 0;}
 return M2C_FIELD(conn,s32 *,CONN_RX_BUFFER)+pending;
}

/* Start an asynchronous receive of up to len bytes into buf: allocate a receive
 * task record, fill in its buffer, length and the two peer-endpoint out-pointers,
 * and post it to the socket. */
s32 SocketStartRecvTask(void *sock, s32 buf, s32 len, s32 peerPort, s32 peerAddr) {
    s32 SocketRecvFromTask(void *);
    void *task = SocketAllocTask(SocketRecvFromTask, sock, 1);
    M2C_FIELD(task, s32 *, RECV_TASK_BUF) = buf;
    M2C_FIELD(task, s32 *, RECV_TASK_LEN) = len;
    M2C_FIELD(task, s32 *, RECV_TASK_PEER_PORT) = peerPort;
    M2C_FIELD(task, s32 *, RECV_TASK_PEER_ADDR) = peerAddr;
    SocketSubmitRecvTask(sock, task);
}

s32 SocketRecvFromTask(void *arg0) {
    void *PeekSocketReceivedData(u32 *);
    M2C_UNK SleepMilliseconds(s32);
    M2C_UNK MI_CpuCopy8(s32, s32, s32);
    s32 SocketRecvFromWindow(void *, M2C_UNK, s32, u16 *, s32 *);
    void ConsumeConnectionReceivedData(s32);
    s32 ConsumeSocketReceivedBytes(s32);
    u32 sp10;
    s32 spC;
    u16 *sp8;
    s32 *sp4;
    s32 temp_r9;
    void *var_r0;
    s32 var_r1;
    s32 var_r4;
    s8 temp_r0;
    u32 var_r10;
    void *temp_r7;
    void *temp_r8;

    temp_r7 = M2C_FIELD(arg0, void **, 4);
    temp_r8 = M2C_FIELD(temp_r7, void **, 0x64);
    spC = M2C_FIELD(arg0, s32 *, 0x10);
    var_r10 = M2C_FIELD(arg0, u32 *, 0x14);
    temp_r9 = M2C_FIELD(temp_r8, s32 *, 0xF8);
    sp8 = M2C_FIELD(arg0, u16 **, 0x18);
    sp4 = M2C_FIELD(arg0, s32 **, 0x1C);
loop_1:
    var_r0 = PeekSocketReceivedData(&sp10);
    if ((var_r0 != 0) && ((s32) (sp10 - temp_r9) <= 0)) {
        temp_r0 = M2C_FIELD(temp_r7, s8 *, 0x73);
        var_r1 = 1;
        if ((temp_r0 != 0) && (temp_r0 != 4)) {
            var_r1 = 0;
        }
        if ((var_r1 != 0) && (M2C_FIELD((u32)temp_r7, u8 *, 8) != 4)) {
            var_r0 = 0;
        } else {
            SleepMilliseconds(0xA);
            goto loop_1;
        }
    }
    if (M2C_FIELD(temp_r7, s16 *, 0x70) & 0x80) {
        return -0xF;
    }
    if (M2C_FIELD(temp_r7, s8 *, 0x73) == 4) {
        if (var_r0 == 0) {
            return 0;
        }
        if (var_r10 > sp10) {
            var_r10 = sp10;
        }
        MI_CpuCopy8(var_r0, spC, (s32) var_r10);
        ConsumeConnectionReceivedData((s32) var_r10);
        return (s32) var_r10;
    }
    if (var_r0 == 0) {
        var_r4 = 0;
    } else {
        var_r4 = SocketRecvFromWindow(temp_r7, spC, var_r10, sp8, sp4);
    }
    if (var_r4 <= 0) {
        return var_r4;
    }
    if ((s32) M2C_FIELD(temp_r8, s32 *, (int)0xF8) >= (s32) M2C_FIELD(temp_r8, u16 *, 0xFC)) {
        ConsumeSocketReceivedBytes(temp_r7);
    }
    return var_r4;
}

/* Queue the task that consumes the connection's pending receive data once enough
 * of it has arrived: nothing happens while the pending byte count is below the
 * connection's receive-window release threshold. */
s32 SocketReleaseRecvWindow(void *sock) {
    void SocketReleaseRecvWindowTask(void *);
    void *raw = M2C_FIELD(sock, void **, SOCK_RAW), *task;
    if (M2C_FIELD(raw, s32 *, CONN_RECV_PENDING) < M2C_FIELD(raw, u16 *, CONN_RECV_RELEASE_AT)) return 0;
    task = SocketAllocTask((s32 (*)(void *))SocketReleaseRecvWindowTask, sock, 0);
    if (!task) return SOCK_NO_MEMORY;
    return SocketSubmitRecvTask(sock, task);
}

/* Task half of SocketReleaseRecvWindow: hand the bytes the socket's raw
 * connection has queued to the connection's receive-data consumer. */
void SocketReleaseRecvWindowTask(void *task) {
    M2C_UNK ConsumeSocketReceivedBytes(s32);
    ConsumeSocketReceivedBytes(M2C_FIELD(task, s32 *, TASK_SOCKET));
}

#pragma dont_inline on
/* Take the bytes queued on a socket's raw connection: under an interrupt lock
 * read the pending received count (CONN_RECV_PENDING), clear it and hand it to the
 * active connection's receive-data consumer.  Returns the bytes that were
 * waiting, 0 when none were. */
s32 ConsumeSocketReceivedBytes(s32 sock) {
    s32 OS_DisableInterrupts(void);
    s32 OS_RestoreInterrupts(s32);
    void ConsumeConnectionReceivedData(s32);
    void *raw = M2C_FIELD(sock, void **, SOCK_RAW);
    s32 irq = OS_DisableInterrupts();
    s32 pending = M2C_FIELD(raw, s32 *, CONN_RECV_PENDING);
    if (pending) {
        M2C_FIELD(raw, s32 *, CONN_RECV_PENDING) = 0;
        ConsumeConnectionReceivedData(pending);
    }
    OS_RestoreInterrupts(irq);
    return pending;
}

/* Receive up to len bytes from a stream socket's queued receive records into
 * buf, reporting the record's peer port and address when asked.  With the wait
 * bit set in flags it sleeps until a record arrives; otherwise it fails with
 * SOCK_WOULD_BLOCK.  The record is dequeued and freed unless the socket is
 * being peeked at. */
s32 SocketRecv(void *sock, s32 buf, s32 len, s32 peerPort, s32 peerAddr, s32 flags) {
s32 OS_DisableInterrupts(); M2C_UNK OS_RestoreInterrupts(s32); M2C_UNK OS_SleepThread(void *); s32 SocketIsUnregistered(); M2C_UNK MI_CpuCopy8(M2C_UNK,M2C_UNK,s32); extern s32 gNetAllocator;
void *raw=M2C_FIELD(sock,void **,SOCK_RAW);
s32 irq=OS_DisableInterrupts(M2C_FIELD(raw,void **,CONN_RECV_HEAD));
void *rec=M2C_FIELD(raw,void **,CONN_RECV_HEAD);
s32 result;
if(rec==0) {
s32 wait=flags&1;
do {
if(!wait) {result=SOCK_WOULD_BLOCK; break;}

OS_SleepThread((char *)raw+CONN_RECV_THREAD);
if(SocketIsUnregistered(sock) == 0) {
s32 ready=0;
if(sock) ready=(M2C_FIELD(sock,s16 *,SOCK_FLAGS)&SOCK_FLAG_READY)!=0;
if(ready) goto next;
}
result=SOCK_ABORTED; break;
next:
rec=M2C_FIELD(raw,void **,CONN_RECV_HEAD);
} while(!rec);
}
if(rec) {
if(len>M2C_FIELD(rec,u16 *,REC_LEN)) len=M2C_FIELD(rec,u16 *,REC_LEN);
MI_CpuCopy8((char *)rec+REC_DATA,buf,len);
if(peerPort) M2C_FIELD(peerPort,u16 *,0)=M2C_FIELD(rec,u16 *,REC_PORT);
if(peerAddr) M2C_FIELD(peerAddr,s32 *,0)=M2C_FIELD(rec,s32 *,REC_ADDR);
result=M2C_FIELD(rec,u16 *,REC_LEN);
if(M2C_FIELD(raw,s8 *,CONN_RECV_HOLD)==0) {
M2C_FIELD(raw,void **,CONN_RECV_HEAD)=M2C_FIELD(rec,void **,REC_NEXT);
if(!M2C_FIELD(rec,void **,REC_NEXT)) M2C_FIELD(raw,void **,CONN_RECV_TAIL)=0;
((void (*)(void *))M2C_FIELD(gNetAllocator,void **,NET_ALLOC_FREE))(rec);
M2C_FIELD(raw,u16 *,CONN_RECV_COUNT)-=result;
}
}
OS_RestoreInterrupts(irq);return result;
}

/* Data-arrival callback for a stream socket: wrap the received payload in a
 * record (header REC_LEN/REC_PORT/REC_ADDR, then the data), append it to the
 * raw connection's receive queue unless it is full or the allocation fails,
 * update the socket's peer and local port, then wake the reader. */
s32 SocketQueueReceivedData(void *data, s16 len, void *sock) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    M2C_UNK MI_CpuCopy8(M2C_UNK, M2C_UNK, s32);
    void OS_WakeupThread(void *);
    extern s32 gNetAllocator;
    extern M2C_UNK gSocketRecvStats;
    void *raw;
    void *rec;
    s32 irq;

    raw = M2C_FIELD(sock, void **, SOCK_RAW);
    irq = OS_DisableInterrupts();
    if (M2C_FIELD(raw, u16 *, CONN_RECV_LIMIT) >= (u32) (M2C_FIELD(raw, u16 *, CONN_RECV_COUNT) + len)) {
        rec = M2C_FIELD(gNetAllocator, void *(**)(s32), NET_ALLOC_ALLOC)(len + REC_DATA);
        if (rec != NULL) {
            M2C_FIELD(raw, u16 *, CONN_RECV_COUNT) = (u16) (M2C_FIELD(raw, u16 *, CONN_RECV_COUNT) + len);
            M2C_FIELD(rec, M2C_UNK **, REC_NEXT) = NULL;
            M2C_FIELD(rec, s16 *, REC_LEN) = len;
            M2C_FIELD(rec, u16 *, REC_PORT) = M2C_FIELD(sock, u16 *, SOCK_PEER_PORT);
            M2C_FIELD(rec, s32 *, REC_ADDR) = M2C_FIELD(sock, s32 *, SOCK_PEER_ADDR);
            MI_CpuCopy8(data, (char *) rec + REC_DATA, len);
            if (M2C_FIELD(raw, void *volatile *, CONN_RECV_TAIL) != NULL) {
                *(M2C_UNK **) M2C_FIELD(raw, void *volatile *, CONN_RECV_TAIL) = rec;
            }
            M2C_FIELD(raw, void **, CONN_RECV_TAIL) = rec;
            if (M2C_FIELD(raw, void **, CONN_RECV_HEAD) == NULL) {
                M2C_FIELD(raw, void **, CONN_RECV_HEAD) = rec;
            }
        } else {
            M2C_FIELD(&gSocketRecvStats, s32 *, RECV_STAT_NO_MEMORY) = (s32) (M2C_FIELD(&gSocketRecvStats, s32 *, RECV_STAT_NO_MEMORY) + 1);
        }
    } else {
        M2C_FIELD(&gSocketRecvStats, s32 *, RECV_STAT_QUEUE_FULL) = (s32) (M2C_FIELD(&gSocketRecvStats, s32 *, RECV_STAT_QUEUE_FULL) + 1);
    }
    if (M2C_FIELD(sock, u16 *, SOCK_RECV_PORT) == 0) {
        M2C_FIELD(sock, u16 *, SOCK_RECV_PORT) = (u16) M2C_FIELD(sock, u16 *, SOCK_LINK_PORT);
    }
    M2C_FIELD(sock, u16 *, SOCK_PEER_PORT) = (u16) M2C_FIELD(sock, u16 *, SOCK_NEXT_PEER_PORT);
    M2C_FIELD(sock, s32 *, SOCK_PEER_ADDR) = M2C_FIELD(sock, s32 *, SOCK_NEXT_PEER_ADDR);
    OS_WakeupThread((char *) raw + CONN_RECV_THREAD);
    OS_RestoreInterrupts(irq);
    return 1;
}

/* Send up to len bytes from buf to peerPort/peerAddr — or to the socket's own
 * peer when both are 0 — taking the send connection's mutex around the call.
 * A non-blocking call (SOCK_RECV_NONBLOCK, or a socket whose blocking mode was
 * cleared) only try-locks the connection and fails with SOCK_WOULD_BLOCK when it
 * is busy.  Returns the bytes sent, or SOCK_ERROR / SOCK_NOT_READY /
 * SOCK_ABORTED when the network, the socket or its state is not usable. */
s32 SocketSendTo(void *sock, s32 buf, s32 len, s32 peerPort, s32 peerAddr, s32 flags) {
    s32 LockMutex();
    s32 UnlockMutex();
    s32 TryLockMutex();
    s32 SocketIsUnregistered();
    s32 SocketSendLocked(void *, s32, s32, s32, s32, s32);
    void *sendConn;
    s32 sent;
    s32 wait;
    s32 ready;
    s32 usable;
    s8 state;

    if (SocketIsUnregistered(sock) != 0) {
        return SOCK_ERROR;
    }
    ready = 0;
    if (sock != NULL) {
        ready = (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_READY) != 0;
    }
    if (ready == 0) {
        return SOCK_NOT_READY;
    }
    state = M2C_FIELD(sock, s8 *, SOCK_STATE);
    usable = 1;
    if (state != SOCK_STATE_IDLE && state != SOCK_STATE_CONNECTED) {
        usable = 0;
    }
    if (usable != 0) {
        if (!(M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_DONE) || (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_ERROR)) {
            return SOCK_ABORTED;
        }
    }
    sendConn = M2C_FIELD(sock, void **, SOCK_TX_CONN);
    if (flags & SOCK_RECV_NONBLOCK) {
        goto nonblocking;
    }
    if (M2C_FIELD(sock, s8 *, SOCK_BLOCKING) == 0) {
nonblocking:
        if (TryLockMutex(sendConn + CONN_MUTEX) == 0) {
            return SOCK_WOULD_BLOCK;
        }
        wait = 0;
    } else {
        LockMutex(sendConn + CONN_MUTEX);
        wait = 1;
    }
    sent = SocketSendLocked(sock, buf, len, peerPort, peerAddr, wait);
    UnlockMutex(sendConn + CONN_MUTEX);
    return sent;
}

s32 SocketSendLocked(void *sock, s32 buf, s32 len, s32 peerPort, s32 peerAddr, s32 wait) {
    s32 SocketGetSendRingSpace(void *, s32, s32, s32 *, s32);
    s32 SocketQueueSend(void *, s32, s32, s32, s32, s32, s32);
    s32 writePos;
    s32 chunk;
    s32 packetPort;
    s32 packetBytes;
    s32 streamBytes;
    s32 available;
    s32 sent;
    s32 remaining;
    s32 cursor;
    s32 blocking;

    packetPort = peerPort;
    cursor = buf;
    remaining = len;
    packetBytes = M2C_FIELD(M2C_FIELD(M2C_FIELD(sock, void **, SOCK_TX_CONN), void **, SEND_RING_OWNER), s32 *, SOCK_TX_SIZE);
    sent = 0;
    if (M2C_FIELD(sock, s8 *, SOCK_STATE) == SOCK_STATE_RECV_ONLY) {
        if (remaining > packetBytes - SOCK_TX_HDR_DGRAM) {
            return SOCK_MESSAGE_TOO_LONG;
        }
        chunk = remaining;
    } else {
        streamBytes = packetBytes - SOCK_TX_HDR_STREAM;
        chunk = streamBytes;
        if (remaining <= streamBytes) {
            chunk = remaining;
        }
    }
    if (remaining > 0) {
        blocking = wait & 1;
        do {
            available = SocketGetSendRingSpace(sock, remaining, chunk, &writePos, wait);
            if (available > 0) {
                if (SocketQueueSend(sock, cursor, available, writePos, packetPort, peerAddr, wait) <= 0) {
                    return SOCK_WOULD_BLOCK;
                }
                cursor += available;
                remaining -= available;
                sent += available;
            }
            if (blocking == 0 && available <= 0) {
                return SOCK_WOULD_BLOCK;
            }
        } while (remaining > 0);
    }
    return sent;
}

#pragma dont_inline reset

/* Get a writable span's starting index and size, sleeping until enough room opens if requested. */
s32 SocketGetSendRingSpace(void *socket, s32 requestedBytes, s32 minimumBytes, s32 *writePosition, s32 flags) {
    M2C_UNK OS_SleepThread(void *);
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 SocketGetSendRingFreeBytes(void *);
    s32 interruptState;
    void *sendConnection;
    s32 threshold;
    s32 writableBytes;

    threshold = minimumBytes;
    sendConnection = M2C_FIELD(socket, void **, SOCK_TX_CONN);
    if (threshold > requestedBytes) {
        threshold = requestedBytes;
    }
    interruptState = OS_DisableInterrupts();
checkSpace:
    writableBytes = SocketGetSendRingFreeBytes(socket);
    if (writableBytes >= threshold) {
        if (writableBytes >= requestedBytes) {
            writableBytes = requestedBytes;
        }
        *writePosition = (s32) M2C_FIELD(sendConnection, u16 *, SEND_RING_WRITE);
    } else if (!(flags & SOCK_SEND_WAIT_FOR_SPACE)) {
        writableBytes = 0;
    } else {
        OS_SleepThread(sendConnection + SEND_RING_WAIT);
        goto checkSpace;
    }
    OS_RestoreInterrupts(interruptState);
    return writableBytes;
}

/* Bytes free in the socket's send ring: the gap between the read and write
 * positions, minus the one slot that tells a full ring from an empty one. */
s32 SocketGetSendRingFreeBytes(void *sock) {
    void *connection = M2C_FIELD(sock, void **, SOCK_TX_CONN);
    volatile u16 *positions = connection + SEND_RING_WRITE;
    s32 capacity = M2C_FIELD(connection, s32 *, SEND_RING_SIZE);
    s32 writePos = positions[0];
    s32 readPos = positions[1];
    readPos = readPos - writePos - 1;
    if (readPos < 0) readPos += capacity;
    return readPos;
}

