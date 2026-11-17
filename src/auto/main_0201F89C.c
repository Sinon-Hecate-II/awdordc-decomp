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
    s32 func_0201f318(void *, void *);
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
    if (M2C_FIELD(sock, s8 *, SOCK_KIND) != SOCK_KIND_TCP) {
        return -6;
    }
    if (M2C_FIELD(sock, u16 *, SOCK_RECV_PORT) == 0) {
        return -28;
    }
    request = func_0201f1d0((s32 (*)(void *))SocketListenTask, sock, (s8)M2C_FIELD(sock, s8 *, SOCK_KIND));
    M2C_FIELD(request, u16 *, 0x10) = M2C_FIELD(sock, u16 *, SOCK_RECV_PORT);
    M2C_FIELD(request, s32 *, 0x14) = (s32)peerPort;
    M2C_FIELD(request, s32 *, 0x18) = (s32)peerAddr;
    M2C_FIELD(sock, s16 *, SOCK_FLAGS) = (s16)(M2C_FIELD(sock, s16 *, SOCK_FLAGS) | SOCK_FLAG_BUSY);
    return func_0201f318(sock, request);
}

s32 SocketListenTask(void *arg0) {
    M2C_UNK LockMutex(s32);
    M2C_UNK UnlockMutex(void *);
    M2C_UNK func_0201d190(u16, M2C_UNK, M2C_UNK);
    M2C_UNK func_0201d2b8();
    s32 func_0201d3e4(u16 *, M2C_UNK *);
    M2C_UNK sp4;
    u16 sp0;
    s32 temp_r0;
    void *temp_r4;
    void *temp_r5;

    temp_r4 = M2C_FIELD(arg0, void **, 4);
    temp_r5 = M2C_FIELD(temp_r4, void **, 0x64);
    LockMutex(temp_r5 + 0xE0);
    func_0201d190(M2C_FIELD(arg0, u16 *, 0x10), 0, 0);
    func_0201d2b8();
    M2C_FIELD(temp_r5, s32 *, 0xF8) = 0;
    temp_r0 = func_0201d3e4(&sp0, &sp4);
    *M2C_FIELD(arg0, u16 **, 0x14) = sp0;
    *M2C_FIELD(arg0, s32 **, 0x18) = temp_r0;
    M2C_FIELD(temp_r4, s16 *, 0x70) = (s16) (M2C_FIELD(temp_r4, s16 *, 0x70) | 4);
    UnlockMutex(temp_r5 + 0xE0);
    return 0;
}

s32 SocketSetReceivePort(void *arg0,s32 arg1) {
s32 SocketIsUnregistered(); s32 func_0201fb3c(void *);s32 a;
if(SocketIsUnregistered()!=0)return -28;
a=0;if(arg0)a=(M2C_FIELD(arg0,volatile s16 *,0x70)&1)!=0;
if(!a)return -39;
if(M2C_FIELD(arg0,s16 *,0x70)&2)return -7;
M2C_FIELD(arg0,s16 *,0x74)=arg1;
if(M2C_FIELD(arg0,s8 *,0x73)!=1)return 0;
return func_0201fb3c(arg0);
}

/* Give the socket a receive timeout: refuse when the network stack is down, the
 * socket is torn down or busy, or an operation is already running; a finished
 * operation reports its result, a running one asks for its timeout, and an idle
 * socket starts a receive that expires after timeout/token. */
s32 SocketSetReceiveTimeout(void *sock, s16 timeout, s32 token) {
    s32 SocketIsUnregistered();
    s32 func_0201fb3c(void *);
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
            return M2C_FIELD(sock, s8 *, SOCK_KIND) == SOCK_KIND_TCP ? -30 : 0;
        }
        if (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_BUSY) {
            return (M2C_FIELD(sock, volatile s16 *, SOCK_FLAGS) & SOCK_FLAG_TIMEOUT) ? M2C_FIELD(sock, s32 *, SOCK_RECV_TIMEOUT) : gSocketDefaultRecvTimeout;
        }
        M2C_FIELD(sock, s16 *, SOCK_TIMEOUT) = timeout;
        M2C_FIELD(sock, s32 *, SOCK_TIMEOUT_RESULT) = token;
        result = func_0201fb3c(sock);
        if (M2C_FIELD(sock, s8 *, SOCK_KIND) != SOCK_KIND_TCP) result = -26;
        return result;
    }
    M2C_FIELD(sock, s16 *, SOCK_TIMEOUT) = timeout;
    M2C_FIELD(sock, s32 *, SOCK_TIMEOUT_RESULT) = token;
    return 0;
}

s32 func_0201fb3c(void *arg0) {
s32 func_0201fb94(void *);
void *SocketAllocTask(s32 (*)(void *),void *,s8);
s32 func_0201f318(void *,void *);
void *p=SocketAllocTask(func_0201fb94,arg0,M2C_FIELD(arg0,s8 *,0x72));
if(!p)return -33;
M2C_FIELD(p,u16 *,0x10)=M2C_FIELD(arg0,u16 *,0x74);
M2C_FIELD(p,u16 *,0x12)=M2C_FIELD(arg0,u16 *,0x76);
M2C_FIELD(p,s32 *,0x14)=M2C_FIELD(arg0,s32 *,0x78);
M2C_FIELD(arg0,s16 *,0x70)|=2;
return func_0201f318(arg0,p);
}

s32 func_0201fb94(void *arg0) {
s32 func_0201d3a4(); void *p,*q;s32 v;s8 t;
p=M2C_FIELD(arg0,void **,4);v=0;q=M2C_FIELD(p,void **,0x64);
LockMutex(q+0xe0);
func_0201d190(M2C_FIELD(arg0,u16 *,0x10),M2C_FIELD(arg0,u16 *,0x12),M2C_FIELD(arg0,s32 *,0x14));
M2C_FIELD(q,s32 *,0xf8)=v;t=M2C_FIELD(arg0,s8 *,12);
if(t==0 || t==4)v=func_0201d3a4();
UnlockMutex(q+0xe0);
if(v){M2C_FIELD(p,volatile s16 *,0x70)|=0x40;return -76;}
M2C_FIELD(p,volatile s16 *,0x70)|=4;return 0;
}

#pragma optimization_level 2
s32 func_0201fc18(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, s32 arg5) {
    s32 LockMutex();
    s32 UnlockMutex();
    s32 TryLockMutex();
    s32 func_02007580();
    s32 func_0201fd60(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32);
    s32 SocketIsUnregistered();
    void *temp_r4;
    s32 var_r5;
    s32 var_r1;
    s32 var_r1_2;
    s8 temp_r0;

    if (SocketIsUnregistered() != 0) {
        return -0x1C;
    }
    if (!(arg5 & 4) && M2C_FIELD(arg0, s8 *, 0x72) == 0) {
        if (M2C_FIELD(arg0, s8 *, 0x73) == 4) {
            return -0x1C;
        }
        var_r5 = 0;
    } else {
        if (func_02007580() == 0x12) {
            return -0x1C;
        }
        var_r5 = 1;
    }
    var_r1 = 0;
    if (arg0 != 0) {
        var_r1 = (M2C_FIELD(arg0, volatile s16 *, 0x70) & 1) != 0;
    }
    if (var_r1 == 0) {
        return -0x27;
    }
    temp_r0 = M2C_FIELD(arg0, s8 *, 0x73);
    var_r1_2 = 1;
    if (temp_r0 != 0 && temp_r0 != 4) {
        var_r1_2 = 0;
    }
    if (var_r1_2 != 0 && (!(M2C_FIELD(arg0, volatile s16 *, 0x70) & 4) || (M2C_FIELD(arg0, volatile s16 *, 0x70) & 8))) {
        return -0x38;
    }
    temp_r4 = M2C_FIELD(arg0, void **, 0x64);
    if (!(var_r5 & 1)) {
        if (TryLockMutex(temp_r4 + 0xE0) == 0) {
            return -6;
        }
    } else {
        LockMutex(temp_r4 + 0xE0);
    }
    var_r5 = func_0201fd60(arg0, arg1, arg2, arg3, arg4, var_r5, arg5);
    UnlockMutex(temp_r4 + 0xE0);
    return var_r5;
}
#pragma optimization_level reset
s32 func_0201fd60(void *p,s32 b,s32 c,s32 d,s32 e,s32 f,s32 flags) {
 s32 SocketRecv(void *,s32,s32,s32,s32,s32);
 s32 func_0201fdfc(void *,s32,s32,s32,s32,s32);
 s32 func_02020188(void *);
 void *q=M2C_FIELD(p,void **,0x64);
 s32 enabled=(flags&2)!=0 && q!=0;
 s8 old;s32 result;
 if(enabled){old=M2C_FIELD(q,s8 *,0xFE);M2C_FIELD(q,s8 *,0xFE)=1;}
 if(M2C_FIELD(p,s8 *,0x73)==1)result=SocketRecv(p,b,c,d,e,f);
 else{result=func_0201fdfc(p,b,c,d,e,f);if(result>=0)func_02020188(p);}
 if(enabled)M2C_FIELD(q,s8 *,0xFE)=old;
 return result;
}

s32 func_0201fdfc(void *p,s32 b,s32 c,s32 d,s32 e,s32 flags) {
 s32 func_0201ffec(void *,s32,s32,s32,s32);
 s32 func_0201fe70(void *,s32,s32,u16 *,s32 *);
 s32 result;
 if(M2C_FIELD(p,s8 *,0x73)==4)return func_0201ffec(p,b,c,d,e);
 result=func_0201fe70(p,b,c,d,e);
 if(result!=-6)return result;
 if(!(flags&1))return result;
 return func_0201ffec(p,b,c,d,e);
}

s32 func_0201fe70(void *arg0, M2C_UNK arg1, s32 arg2, u16 *arg3, s32 *arg4) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    M2C_UNK MI_CpuCopy8(s32, M2C_UNK, s32);
    s32 func_0201ff78(void *, s32 *, u16 *, u16 *, s32 *);
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
    temp_r0 = func_0201ff78(arg0, &spC, &sp6, &sp4, &sp8);
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

s32 func_0201ff78(void *p,s32 *remaining,u16 *a,u16 *b,s32 *c) {
 void *q=M2C_FIELD(p,void **,0x64);
 void *entry=M2C_FIELD(q,void **,0xC4);
 s32 offset=M2C_FIELD(q,s32 *,0xF8);
 s32 n=M2C_FIELD(entry,s32 *,0x44)-offset;
 if(n>=0){
 *a=M2C_FIELD(entry,u16 *,0xA);*b=M2C_FIELD(entry,u16 *,0x18);
 *c=M2C_FIELD(entry,s32 *,0x1C);*remaining=n;
 if(n==0 && M2C_FIELD(entry,u8 *,8)!=4)return 0;
 }else{*remaining=-1;return 0;}
 return M2C_FIELD(entry,s32 *,0x40)+offset;
}

s32 func_0201ffec(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
s32 func_02020038(void *);
void *p=SocketAllocTask(func_02020038,arg0,1);
M2C_FIELD(p,s32 *,0x10)=arg1;
M2C_FIELD(p,s32 *,0x14)=arg2;
M2C_FIELD(p,s32 *,0x18)=arg3;
M2C_FIELD(p,s32 *,0x1c)=arg4;
func_0201f318(arg0,p);
}

s32 func_02020038(void *arg0) {
    void *func_0201d618(u32 *);
    M2C_UNK SleepMilliseconds(s32);
    M2C_UNK MI_CpuCopy8(s32, s32, s32);
    s32 func_0201fe70(void *, M2C_UNK, s32, u16 *, s32 *);
    void func_0201d70c(s32);
    s32 func_020201e4(s32);
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
    var_r0 = func_0201d618(&sp10);
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
        func_0201d70c((s32) var_r10);
        return (s32) var_r10;
    }
    if (var_r0 == 0) {
        var_r4 = 0;
    } else {
        var_r4 = func_0201fe70(temp_r7, spC, var_r10, sp8, sp4);
    }
    if (var_r4 <= 0) {
        return var_r4;
    }
    if ((s32) M2C_FIELD(temp_r8, s32 *, (int)0xF8) >= (s32) M2C_FIELD(temp_r8, u16 *, 0xFC)) {
        func_020201e4(temp_r7);
    }
    return var_r4;
}

s32 func_02020188(void *arg0) {
void func_020201d4(void *);
void *q=M2C_FIELD(arg0,void **,0x64),*p;
if(M2C_FIELD(q,s32 *,0xf8)<M2C_FIELD(q,u16 *,0xfc))return 0;
p=SocketAllocTask((s32 (*)(void *))func_020201d4,arg0,0);
if(!p)return -33;
return func_0201f318(arg0,p);
}

void func_020201d4(void *arg0) {
    M2C_UNK func_020201e4(s32);
    func_020201e4(M2C_FIELD(arg0, s32 *, 4));
}

#pragma dont_inline on
s32 func_020201e4(s32 p) {
 s32 OS_DisableInterrupts(void);s32 OS_RestoreInterrupts(s32);void func_0201d70c(s32);
 void *q=M2C_FIELD(p,void **,0x64);
 s32 irq=OS_DisableInterrupts();s32 value=M2C_FIELD(q,s32 *,0xF8);
 if(value){M2C_FIELD(q,s32 *,0xF8)=0;func_0201d70c(value);}
 OS_RestoreInterrupts(irq);return value;
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

s32 func_02020478(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 SocketIsUnregistered();
    s32 TryLockMutex(s32);
    s32 func_0202058c(void *, s32, s32, s32, s32, s32);
    s32 temp_r4;
    s32 temp_r5;
    s32 var_ip;
    s32 var_r1;
    s32 var_r1_2;
    s8 temp_r0;

    if (SocketIsUnregistered() != 0) {
        return -28;
    }
    var_r1 = 0;
    if (arg0 != NULL && (M2C_FIELD(arg0, volatile s16 *, 0x70) & 1)) {
        var_r1 = 1;
    }
    if (var_r1 == 0) {
        return -39;
    }
    temp_r0 = M2C_FIELD(arg0, s8 *, 0x73);
    var_r1_2 = 1;
    if (temp_r0 != 0 && temp_r0 != 4) {
        var_r1_2 = 0;
    }
    if (var_r1_2 != 0) {
        if (!(M2C_FIELD(arg0, s16 *, 0x70) & 4) || (M2C_FIELD(arg0, s16 *, 0x70) & 8)) {
            return -56;
        }
    }
    temp_r4 = (s32) M2C_FIELD(arg0, void **, 0x68);
    if (!(arg5 & 4) && M2C_FIELD(arg0, s8 *, 0x72) == 0) {
        if (TryLockMutex(temp_r4 + 0xE0) == 0) {
            return -6;
        }
        var_ip = 0;
    } else {
        LockMutex(temp_r4 + 0xE0);
        var_ip = 1;
    }
    temp_r5 = func_0202058c(arg0, arg1, arg2, arg3, arg4, var_ip);
    UnlockMutex(temp_r4 + 0xE0);
    return temp_r5;
}

s32 func_0202058c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_02020690(void *, s32, s32, s32 *, s32);
    s32 func_02020738(void *, s32, s32, s32, s32, s32, s32);
    s32 sp14;
    s32 sp10;
    s32 spC = arg3;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 var_r5 = 0;
    s32 var_r8 = arg2;
    s32 var_r9 = arg1;
    s32 var_r11;

    temp_r0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), void **, 0x10C), s32 *, 0x48);
    if (M2C_FIELD(arg0, s8 *, 0x73) == 1) {
        if (var_r8 > temp_r0 - 0x2A) {
            return -0x23;
        }
        sp10 = var_r8;
    } else {
        temp_r0_2 = temp_r0 - 0x36;
        sp10 = temp_r0_2;
        if (var_r8 <= temp_r0_2) {
            sp10 = var_r8;
        }
    }
    if (var_r8 > 0) {
        var_r11 = arg5 & 1;
        do {
            temp_r0_3 = func_02020690(arg0, var_r8, sp10, &sp14, arg5);
            if (temp_r0_3 > 0) {
                if (func_02020738(arg0, var_r9, temp_r0_3, sp14, spC, arg4, arg5) <= 0) {
                    return -6;
                }
                var_r9 += temp_r0_3;
                var_r8 -= temp_r0_3;
                var_r5 += temp_r0_3;
            }
            if (var_r11 == 0) {
                if (temp_r0_3 <= 0) {
                    return -6;
                }
            }
        } while (var_r8 > 0);
    }
    return var_r5;
}

#pragma dont_inline reset

s32 func_02020690(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4) {
    M2C_UNK OS_SleepThread(void *);
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    s32 func_02020714(void *);
    s32 temp_r11;
    void *temp_r4;
    s32 var_r8;
    s32 var_r5;

    var_r8 = arg2;
    temp_r4 = M2C_FIELD(arg0, void **, 0x68);
    if (var_r8 > arg1) {
        var_r8 = arg1;
    }
    temp_r11 = OS_DisableInterrupts();
loop_3:
    var_r5 = func_02020714(arg0);
    if (var_r5 >= var_r8) {
        if (var_r5 >= arg1) {
            var_r5 = arg1;
        }
        *arg3 = (s32) M2C_FIELD(temp_r4, u16 *, 0x100);
    } else if (!(arg4 & 1)) {
        var_r5 = 0;
    } else {
        OS_SleepThread(temp_r4 + 0x104);
        goto loop_3;
    }
    OS_RestoreInterrupts(temp_r11);
    return var_r5;
}

s32 func_02020714(void *arg0) {
    volatile u16 *q = M2C_FIELD(arg0, void **, 0x68) + 0x100;
    s32 c = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s32 *, 0xf8);
    s32 a = q[0];
    s32 b = q[1];
    b = b - a - 1;
    if (b < 0) b += c;
    return b;
}

