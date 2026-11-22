/* 22 functions from 0x02063704 to 0x02064684 (main), found by ds-decomp. */
#include "common.h"
#include "tcp_socket.h"
#include "sb_serverlist.h"
typedef struct { u8 b[2]; } Bytes2;
typedef struct { u8 b[4]; } Bytes4;
static inline void Copy2(void *d,const void *s) { *(Bytes2 *)d=*(const Bytes2 *)s; }
static inline void Copy4(void *d,const void *s) { *(Bytes4 *)d=*(const Bytes4 *)s; }

typedef struct M2C_S_02063BD0 {
    u32 field_0;
} M2C_S_02063BD0;

/* Add (or update) an entry parsed from the input buffer. */
s32 func_02063704(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 SBServerNew(void *, s32, u16);
    s32 func_02061168();
    M2C_UNK SBServerListAddServer(void *, s32);
    s32 SBServerListFindByAddress(void *, s32, u16);
    s32 SBServerListGetServerAt(void *, s32);
    M2C_UNK gpiReadServerAddress(void *, M2C_UNK, s32, s32 *, u16 *);
    s32 gpiProcessPlayerRecord(void *, s32, M2C_UNK, s32, s32);
    s32 entry;
    u16 kind;
    s32 found;
    s32 count;

    if (arg2 < 5) {
        return 4;
    }
    gpiReadServerAddress(arg0, arg1, arg2, &count, &kind);
    found = SBServerListFindByAddress(arg0, count, kind);
    if (found == -1) {
        entry = SBServerNew(arg0, count, kind);
        if (func_02061168() != 0) {
            return 5;
        }
        goto apply;
    }
    entry = SBServerListGetServerAt(arg0, found);
apply:
    if (gpiProcessPlayerRecord(arg0, entry, arg1, arg2, 0) < 0) {
        return 4;
    }
    if (found == -1) {
        SBServerListAddServer(arg0, entry);
    }
    M2C_FIELD(arg0, M2C_UNK (**)(void *, M2C_UNK, s32, s32), 0x488)(arg0, 1, entry, M2C_FIELD(arg0, s32 *, 0x494));
    return 0;
}

#pragma scheduling reset
s32 SBServerListProcessData(void *arg0) {
    s32 ghiSend(s32, void *, s32, s32);
    M2C_UNK SBServerListCheckQueryError(void *);
    s32 SBServerListParseKeyList(void *, u8 *, s32);
    s32 GpiHandleRecordList(void *, u8 *, s32);
    s32 GpiHandleServerInfoResponse(void *, u8 *, s32);
    s32 func_02063678(M2C_UNK, u8 *, s32);
    void AssertFailed(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    void MemMove(void *, void *, s32);
    extern u8 data_021001b4[], sSbFileName[], data_021000d8[];
    s32 result = 0;
    s32 zero = 0;
    u16 size;
    u8 *hdr;
    u8 *buf;

    hdr = (u8 *) &size;
    while (M2C_FIELD(arg0, s32 *, 0x80) >= 3) {
        Copy2(hdr, M2C_FIELD(arg0, void **, 0x7C));
        size = (u8) (size >> 8) | ((size << 8) & 0xff00);
        if (size > 0x1000) {
            result = 4;
            break;
        }
        if (M2C_FIELD(arg0, s32 *, 0x80) < size) {
            return 0;
        }
        buf = M2C_FIELD(arg0, u8 **, 0x7C);
        switch (((s8 *) buf)[2]) {
        case 1:
            result = SBServerListParseKeyList(arg0, buf + 3, size - 3);
            break;
        case 2:
            result = func_02063704(arg0, buf + 3, size - 3);
            break;
        case 3:
            if (ghiSend(M2C_FIELD(arg0, s32 *, 0x4B0), buf, size, zero) <= 0) {
                return 3;
            }
            break;
        case 4:
            result = func_02063678(arg0, buf + 3, size - 3);
            break;
        case 5:
            result = GpiHandleServerInfoResponse(arg0, buf + 3, size - 3);
            break;
        case 6:
            result = GpiHandleRecordList(arg0, buf + 3, size - 3);
            break;
        }
        if ((M2C_FIELD(arg0, s32 *, 0x80) -= size) < 0) {
            AssertFailed((M2C_UNK) data_021001b4, (M2C_UNK) sSbFileName, (M2C_UNK) data_021000d8, 0x5B4);
        }
        if (M2C_FIELD(arg0, s32 *, 0x80) != 0 && M2C_FIELD(arg0, u8 **, 0x7C) != NULL) {
            MemMove(M2C_FIELD(arg0, u8 **, 0x7C), M2C_FIELD(arg0, u8 **, 0x7C) + size,
                          M2C_FIELD(arg0, s32 *, 0x80));
        }
        if (result != 0) {
            break;
        }
    }
    if (result != 0) {
        SBServerListCheckQueryError(arg0);
    }
    return result;
}
#pragma scheduling off
/* Read whatever the master socket has received into the list's reply buffer,
 * decrypt it, and hand it to the connect-reply or reply-message parser for the
 * list's state.  Returns 0 when there is nothing (more) to do, 3 when the
 * receive failed, or a parser's error code. */
s32 SBServerListCheckForData(void *list) {
    s32 ghiSocketCanRecv(s32);
    s32 ghiRecv(s32, s32, s32, M2C_UNK);
    M2C_UNK GsCryptData(void *, s32, s32);
    M2C_UNK SBServerListCheckQueryError(void *);
    s32 SBServerListProcessConnectReply(void *);
    s32 SBServerListProcessData(void *);
    s32 received;
    s32 result;
    s32 oldLength;

    if (ghiSocketCanRecv(M2C_FIELD(list, s32 *, SB_SLIST_SOCKET)) == 0) {
        return 0;
    }
    oldLength = M2C_FIELD(list, s32 *, SB_SLIST_RECV_LENGTH);
    received = ghiRecv(M2C_FIELD(list, s32 *, SB_SLIST_SOCKET), M2C_FIELD(list, s32 *, SB_SLIST_RECV_BUFFER) + oldLength, SB_SLIST_RECV_BUFFER_SIZE - oldLength, 0);
    if ((u32) (received + 1) <= 1U) {
        SBServerListCheckQueryError(list);
        return 3;
    }
    result = 0;
    M2C_FIELD(list, s32 *, SB_SLIST_RECV_LENGTH) = M2C_FIELD(list, s32 *, SB_SLIST_RECV_LENGTH) + received;
    if (M2C_FIELD(list, s32 *, SB_SLIST_STATE) == SB_SLIST_STATE_CONNECTED || M2C_FIELD(list, s32 *, SB_SLIST_CRYPT_STAGE) > 0) {
        GsCryptData((u8 *)list + SB_SLIST_CRYPT, M2C_FIELD(list, s32 *, SB_SLIST_RECV_BUFFER) + oldLength, M2C_FIELD(list, s32 *, SB_SLIST_RECV_LENGTH) - oldLength);
    }
    if (M2C_FIELD(list, s32 *, SB_SLIST_STATE) == SB_SLIST_STATE_QUERYING) {
        result = SBServerListProcessConnectReply(list);
    }
    if (result != 0) {
        return result;
    }
    if (M2C_FIELD(list, s32 *, SB_SLIST_STATE) == SB_SLIST_STATE_CONNECTED && M2C_FIELD(list, s32 *, SB_SLIST_RECV_LENGTH) > 0) {
        return SBServerListProcessData(list);
    }
    return 0;
}
#pragma push
#pragma opt_alias_analysis off
s32 func_02063aa8(void *arg0,u32 arg1,u32 arg2,void *arg3,s32 arg4) {
s32 func_02049810(s32,void *,s32,s32);s32 func_02062324(void *,void *,s32);s32 func_020623bc(void *,s32,s32,s32,s32);
u8 packet[16]; u16 size; u16 temp; s32 result; u8 *d; u8 *s;
if(M2C_FIELD(arg0,s32 *,0)==1) {
func_020623bc(arg0,0,0,2,0);
}
if(M2C_FIELD(arg0,s32 *,0)==1)return 3;
temp=arg4+9;size=(u8)(temp>>8)|((temp<<8)&0xff00);
d=packet;s=(u8 *)&size;Copy2(d,s);
d=packet+3;s=(u8 *)&arg1;Copy4(d,s);
d=packet+7;s=(u8 *)&arg2;Copy2(d,s);
packet[2]=2;
result=func_02062324(arg0,packet,9);if(result)return result;
return func_02049810(M2C_FIELD(arg0,s32 *,0x4b0),arg3,arg4,0)<0?3:0;
}
#pragma pop
void func_02063bd0(void *context, u32 arg1, u32 arg2, u32 code) {
    s32 func_02063aa8(void *, u32, u32, void *, s32);
    u8 packet[10];
    u8 *bytes;
    packet[0] = 0xfd;
    code = ((code << 24) & 0xff000000) | (((code << 8) & 0xff0000) | ((u8)(code >> 24) | ((code >> 8) & 0xff00)));
    packet[1] = 0xfc;
    packet[2] = 0x1e;
    packet[3] = 0x66;
    packet[4] = 0x6a;
    packet[5] = 0xb2;
    bytes = (u8 *)&code;
    {
        u8 *out = packet + 6;
        u8 b0 = bytes[0], b1 = bytes[1], b2 = bytes[2], b3 = bytes[3];
        out[0] = b0;
        out[1] = b1;
        out[2] = b2;
        out[3] = b3;
    }
    func_02063aa8(context, arg1, arg2, packet, sizeof(packet));
}
#pragma scheduling reset
extern s32 sSbNoServer[];
/* Server-list state 0: collect the servers that announce themselves on the query
   socket.  The sender of each announcement becomes a new list entry (flagged 0x11,
   which notifies the callback); once the 2-second collection window is over the
   socket is closed, the list goes idle and the callback is told the query finished. */
s32 SBServerListProcessAdHocServers(void *list) {
    s32 ghiSocketCanRecv(s32);
    s32 ghiRecvFrom(s32, void *, s32, s32, void *, s32 *);
    s32 SBServerListFindByAddress(void *, s32, u16);
    s32 SBServerNew(void *, s32, u16);
    s32 func_02061168(void);
    void gpiPlayerSetFlags(s32, s32);
    s32 SBServerListAddServer(void *, s32);
    u32 GetTickCountMs(void);
    void ghiCloseSocket(s32);
    u8 packet[0x5dc];
    u16 fromAddr[4];
    s32 addrLen = 8;
    s32 server;

    while (ghiSocketCanRecv(M2C_FIELD(list, s32 *, SB_SLIST_SOCKET))) {
        if (ghiRecvFrom(M2C_FIELD(list, s32 *, SB_SLIST_SOCKET), packet, 0x5db, 0,
                          fromAddr, &addrLen) != -1 &&
            SBServerListFindByAddress(list, *(s32 *)(fromAddr + 2), fromAddr[1]) == -1) {
            server = SBServerNew(list, *(s32 *)(fromAddr + 2), fromAddr[1]);
            if (func_02061168()) return 5;
            gpiPlayerSetFlags(server, 0x11);
            SBServerListAddServer(list, server);
        }
    }
    if (GetTickCountMs() - M2C_FIELD(list, u32 *, SB_SLIST_START_TICK) > 2000) {
        ghiCloseSocket(M2C_FIELD(list, s32 *, SB_SLIST_SOCKET));
        M2C_FIELD(list, s32 *, SB_SLIST_SOCKET) = -1;
        M2C_FIELD(list, s32 *, SB_SLIST_STATE) = SB_SLIST_STATE_IDLE;
        M2C_FIELD(list, void (**)(void *, s32, s32, s32), SB_SLIST_CALLBACK)(list, SB_LIST_EVENT_QUERY_COMPLETE, sSbNoServer[0], M2C_FIELD(list, s32 *, SB_SLIST_INSTANCE));
    }
    return 0;
}

s32 func_02063dac(void *arg0) {
    void SBServerListFreeRemovedServers(void *);
    s32 SBServerListCheckForData(void *);
    s32 SBServerListProcessAdHocServers(void *);
    s32 temp_r0;

    SBServerListFreeRemovedServers(arg0);
    temp_r0 = M2C_FIELD(arg0, s32 *, 0);
    switch (temp_r0) {
    case 2:
    case 3:
        return SBServerListCheckForData(arg0);
    case 0:
        return SBServerListProcessAdHocServers(arg0);
    case 1:
    default:
        return 0;
    }
}

M2C_UNK func_02063df8(void) {
    M2C_UNK InvokeSocketCallback(M2C_UNK);
    void func_02063e1c(M2C_UNK);
    extern M2C_UNK gSocketEventState;
    InvokeSocketCallback(1);
    M2C_FIELD(&gSocketEventState, s32 *, 0xC) = 1;
    func_02063e1c(1);
}

void func_02063e1c(M2C_UNK arg0) {
    M2C_UNK FlushSocketCallbacks(M2C_UNK);
    M2C_UNK func_02074074();
    extern M2C_UNK gSocketEventState;
    if (M2C_FIELD(&gSocketEventState, s32 *, 0xC) == 0) {
        func_02074074();
        if (M2C_FIELD(&gSocketEventState, M2C_UNK (**)(), 4) != NULL) {
            M2C_FIELD(&gSocketEventState, M2C_UNK (**)(), 4)();
            M2C_FIELD(&gSocketEventState, M2C_UNK (**)(), 4) = NULL;
        }
    }
    FlushSocketCallbacks(arg0);
}

#pragma opt_common_subs off
/* Run the deferred socket callbacks (last queued first) and then finish network-stack teardown. */
M2C_UNK FlushSocketCallbacks(M2C_UNK arg0) {
    s32 TryLockMutex(void *);
    M2C_UNK LockMutex();
    M2C_UNK UnlockMutex();
    M2C_UNK FlushFileStream(s32);
    M2C_UNK func_020746f0(void);
    extern u8 gStreamMutexes[];
    extern M2C_UNK gSocketManager, gSocketEventState, gSocketEventCallbacks;
    extern s32 gStreamLockOwner[], gStreamLockDepth[];
    s32 n;
    M2C_UNK (*cb)(void);
    void *thread;
    s32 owner;

    if (!TryLockMutex(gStreamMutexes)) {
        gStreamLockOwner[0] = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), s32 *, 0x6C);
        gStreamLockDepth[0] = 1;
    } else if ((thread = M2C_FIELD(&gSocketManager, void **, 4),
                owner = gStreamLockOwner[0],
                owner == M2C_FIELD(thread, s32 *, 0x6C))) {
        gStreamLockDepth[0]++;
    } else {
        LockMutex(gStreamMutexes);
        gStreamLockOwner[0] = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), s32 *, 0x6C);
        gStreamLockDepth[0] = 1;
    }
    while (M2C_FIELD(&gSocketEventState, s32 *, SOCK_EVENT_COUNT) > 0) {
        n = M2C_FIELD(&gSocketEventState, s32 *, SOCK_EVENT_COUNT) - 1;
        cb = ((M2C_UNK (**)(void)) &gSocketEventCallbacks)[n];
        M2C_FIELD(&gSocketEventState, s32 *, SOCK_EVENT_COUNT) = n;
        cb();
    }
    if (--gStreamLockDepth[0] == 0) {
        UnlockMutex(gStreamMutexes);
    }
    if (M2C_FIELD(&gSocketEventState, M2C_UNK (**)(void), SOCK_EVENT_FLUSH_CB)) {
        M2C_FIELD(&gSocketEventState, M2C_UNK (**)(void), SOCK_EVENT_FLUSH_CB)();
        M2C_FIELD(&gSocketEventState, M2C_UNK (**)(void), SOCK_EVENT_FLUSH_CB) = 0;
    }
    FlushFileStream(0);
    func_020746f0();
}
#pragma opt_common_subs reset
void func_02063f90(void) {
    M2C_UNK _f2d(s32);
    extern s32 gFloatNanBits;
    _f2d(gFloatNanBits);
}

#pragma opt_strength_reduction off
s32 func_02063fa8(void){
s32 FlushFileStream(s32);extern u8 gStdinStream[];
u8 *p; s32 result; s32 i; u8 *base; s32 zero; s32 off;
p=gStdinStream;result=0;i=1;zero=result;base=gStdinStream;
do{u32 a; u32 v=M2C_FIELD(p,u32*,4);a=(u32)(v<<22)>>29;
if(a && (((u32)(v<<25)>>30)&1)){u32 b=(u32)(M2C_FIELD(p,s32*,8)<<29)>>29;if(b==1 && ((s32 (*)(void*,u32,u32))FlushFileStream)(p,b,a))result=-1;}
if(i<3){off=i*76;i++;p=base+off;}else p=0;
}while(p);
return result;}
#pragma opt_strength_reduction reset

#pragma opt_strength_reduction off
#pragma peephole off
/* Flush each open standard stream (stdin, stdout and stderr, STD_STREAM_STRIDE
 * bytes apart at gStdinStream) and return -1 when any of the flushes fails. */
s32 CloseStandardStreams(void) {
    s32 FlushFileStream(s32);
    extern u8 gStdinStream[];
    void *stream;
    s32 result;
    s32 index;
    s32 offset;

    stream = gStdinStream;
    result = 0;
    index = 1;
    do {
        if (FILE_STREAM_KIND(M2C_FIELD(stream, u32 *, FILE_STREAM_MODE)) != 0 && FlushFileStream((s32)stream)) {
            result = -1;
        }
        if (index < STD_STREAM_COUNT) {
            offset = index * STD_STREAM_STRIDE;
            index++;
            stream = gStdinStream + offset;
        } else {
            stream = NULL;
        }
    } while (stream);
    return result;
}
#pragma peephole reset
#pragma opt_strength_reduction reset

s32 Abs(s32 arg0) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 < 0) {
        var_r0 = 0 - var_r0;
    }
    return var_r0;
}

void AssertFailed(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    M2C_UNK func_02063df8();
    M2C_UNK StdoutPrintf(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    extern M2C_UNK data_021002b0;
    StdoutPrintf(&data_021002b0, arg0, arg1, arg2, arg3);
    func_02063df8();
}

void func_020640e4(M2C_UNK a, M2C_UNK *b) {
}

void func_020640e8(M2C_UNK, M2C_UNK *) {

}

void StreamResetBuffer(void *arg0) {
    s32 temp_r3;

    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
    temp_r3 = M2C_FIELD(arg0, s32 *, 0x20);
    M2C_FIELD(arg0, s32 *, 0x28) = temp_r3;
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (temp_r3 - (M2C_FIELD(arg0, s32 *, 0x18) & M2C_FIELD(arg0, s32 *, 0x2C)));
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
}

/* Fills the stream's read buffer through its read callback (the function at
 * +0x3C): resets the buffer cursor, runs the callback with the buffer and its
 * byte count, advances the stream's total byte count and returns the callback's
 * result (0 = success). `wholeBuffer` 1 asks for the whole buffer, which the
 * unbuffered read path uses to read straight into the caller's own buffer. */
s32 StreamFillBuffer(void *stream, M2C_UNK *filled, M2C_UNK wholeBuffer) {
    M2C_UNK result;

    StreamResetBuffer(stream);
    if (wholeBuffer == 1) {
        M2C_FIELD(stream, s32 *, 0x28) = M2C_FIELD(stream, s32 *, 0x20);
    }
    result = M2C_FIELD(stream, M2C_UNK (**)(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK), 0x3C)(M2C_FIELD(stream, s32 *, 0), M2C_FIELD(stream, s32 *, 0x1C), &M2C_FIELD(stream, s32 *, 0x28), M2C_FIELD(stream, s32 *, 0x48));
    if (result == 2) {
        M2C_FIELD(stream, s32 *, 0x28) = 0;
    }
    if (filled != NULL) {
        *filled = M2C_FIELD(stream, s32 *, 0x28);
    }
    if (result != 0) {
        return result;
    }
    M2C_FIELD(stream, s32 *, 0x18) += M2C_FIELD(stream, s32 *, 0x28);
    if (((u32) M2C_FIELD(stream, s32 *, 4) << 0x13) >> 0x1F == 0) {
        func_020640e8(M2C_FIELD(stream, s32 *, 0x1C), &M2C_FIELD(stream, s32 *, 0x28));
    }
    return 0;
}

#pragma scheduling off
s32 StreamFlush(void *arg0,M2C_UNK *arg1){
void func_020640e4(M2C_UNK,M2C_UNK*);void StreamResetBuffer(void*);
s32 n=M2C_FIELD(arg0,s32*,0x24)-M2C_FIELD(arg0,s32*,0x1c);s32 result;
if(n){
M2C_FIELD(arg0,s32*,0x28)=n;
if((((u32)M2C_FIELD(arg0,s32*,4)<<19)>>31)==0)func_020640e4(M2C_FIELD(arg0,M2C_UNK*,0x1c),&M2C_FIELD(arg0,s32*,0x28));
result=M2C_FIELD(arg0,M2C_UNK (**)(M2C_UNK,M2C_UNK,M2C_UNK*,M2C_UNK),0x40)(M2C_FIELD(arg0,s32*,0),M2C_FIELD(arg0,s32*,0x1c),&M2C_FIELD(arg0,s32*,0x28),M2C_FIELD(arg0,s32*,0x48));
if(arg1)*arg1=M2C_FIELD(arg0,s32*,0x28);
if(result)return result;
M2C_FIELD(arg0,s32*,0x18)+=*(volatile s32 *)((u8 *)arg0+0x28);
StreamResetBuffer(arg0);
}return 0;
}
#pragma scheduling reset
/* Reads count elements of elemSize bytes from stream into buffer, under the
 * stream's reentrant lock: the running thread's id is kept in gStreamLockOwner,
 * its nesting in gStreamLockDepth, and the mutex is released when the outermost
 * read returns.  Streams other than stdin share the last lock. */
s32 ReadFileData(void *buffer, s32 elemSize, s32 count, void *stream) {
    s32 TryLockMutex(void *);
    M2C_UNK LockMutex();
    M2C_UNK UnlockMutex();
    s32 StreamRead(u16 *, s32, s32, void *);
    extern u8 gStdinStream[];
    extern u8 gStreamMutexes[]; /* GsiMutex array, sizeof(GsiMutex) per stream class */
    extern M2C_UNK gSocketManager;
    extern s32 gStreamLockOwner[];
    extern s32 gStreamLockDepth[];

    s32 lockIndex;
    s32 bytesRead;
    void *thread;
    s32 owner;

    if (stream == (void *)gStdinStream) {
        lockIndex = STREAM_LOCK_STDIN;
    } else {
        lockIndex = STREAM_LOCK_FILE;
    }

    if (TryLockMutex(gStreamMutexes + lockIndex * sizeof(GsiMutex)) == 0) {
        gStreamLockOwner[lockIndex] = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), s32 *, STREAM_THREAD_ID);
        gStreamLockDepth[lockIndex] = 1;
    } else if ((thread = M2C_FIELD(&gSocketManager, void **, 4),
               owner = gStreamLockOwner[lockIndex],
               owner == M2C_FIELD(thread, s32 *, STREAM_THREAD_ID))) {
        gStreamLockDepth[lockIndex]++;
    } else {
        LockMutex(gStreamMutexes + lockIndex * sizeof(GsiMutex));
        gStreamLockOwner[lockIndex] = M2C_FIELD(M2C_FIELD(&gSocketManager, void **, 4), s32 *, STREAM_THREAD_ID);
        gStreamLockDepth[lockIndex] = 1;
    }

    bytesRead = StreamRead(buffer, elemSize, count, stream);

    if (--gStreamLockDepth[lockIndex] == 0) {
        UnlockMutex(gStreamMutexes + lockIndex * sizeof(GsiMutex));
    }

    return bytesRead;
}

#pragma opt_common_subs off
s32 StreamRead(u16 *arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 func_02063fa8();
    s32 StreamFillBuffer(void *, M2C_UNK *, M2C_UNK);
    M2C_UNK MemCopy(void *, s32, u32);
    s32 func_0206ad4c(void *, M2C_UNK);
    s32 U32DivideRem(s32, s32);
    u32 sp0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_5;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 temp_r1_3;
    u32 var_r4;
    s32 var_r5;
    s32 var_r6;
    u16 *temp_r6;
    u8 *var_r9;
    s32 temp_r0_4;
    u32 temp_r10;

    u32 size = arg1;
    
    var_r9 = (u8 *)arg0;
    if (func_0206ad4c(arg3, 0) == 0) {
        func_0206ad4c(arg3, -1);
    }
    var_r4 = size * arg2;
    if ((var_r4 == 0) || (M2C_FIELD(arg3, u8 *, 0xD) != 0) || (temp_r1 = M2C_FIELD(arg3, s32 *, 4), (((u32) (temp_r1 << 0x16) >> 0x1D) == 0))) {
        return 0;
    }
    var_r6 = 1;
    if (((u32)(temp_r1 << 19) >> 31) != 0 &&
        ((u32)(temp_r1 << 25) >> 30) != 2) var_r6 = 0;
    temp_r1_2 = M2C_FIELD(arg3, s32 *, 8);
    if ((((u32) (temp_r1_2 << 0x1D) >> 0x1D) == 0) && (((u32) (M2C_FIELD(arg3, s32 *, 4) << 0x1B) >> 0x1D) & 1)) {
        M2C_FIELD(arg3, s32 *, 8) = (s32) ((temp_r1_2 & ~7) | 2);
        M2C_FIELD(arg3, u32 *, 0x28) = 0U;
    }
    if ((u32) ((u32) (M2C_FIELD(arg3, s32 *, 8) << 0x1D) >> 0x1D) < 2U) {
        M2C_FIELD(arg3, u8 *, 0xD) = 1U;
        M2C_FIELD(arg3, u32 *, 0x28) = 0U;
        return 0;
    }
    if ((((u32) (M2C_FIELD(arg3, s32 *, 4) << 0x19) >> 0x1E) & 1) && (func_02063fa8() != 0)) {
        M2C_FIELD(arg3, u8 *, 0xD) = 1U;
        M2C_FIELD(arg3, u32 *, 0x28) = 0U;
        return 0;
    }
    var_r5 = 0;
    if ((var_r4 != 0) && ((u32) ((u32) (M2C_FIELD(arg3, s32 *, 8) << 0x1D) >> 0x1D) >= 3U)) {
loop_21:
        temp_r0_2 = func_0206ad4c(arg3, 0);
        if (temp_r0_2 == 1) {
            u16 value = M2C_FIELD((arg3 + ((M2C_FIELD(arg3, u32 *, 8) << 29) >> 28)), u16 *, 0xE);
            var_r5 += 2;
            var_r4 -= 2;
            *(u16 *) var_r9 = value;
            var_r9 += 2;
        } else {
            u32 slot = M2C_FIELD(arg3, u32 *, 8);
            u32 slotOffset = (slot << 29) >> 28;
            u8 value = ((u8 *)arg3 + (slotOffset >> 1))[0xF];
            var_r5 += 1;
            var_r4 -= 1;
            *var_r9 = value;
            var_r9 += 1;
        }
        temp_r1_3 = M2C_FIELD(arg3, s32 *, 8);
        M2C_FIELD(arg3, s32 *, 8) = (s32) ((temp_r1_3 & ~7) | ((((u32) (temp_r1_3 << 0x1D) >> 0x1D) - 1) & 7));
        if ((var_r4 != 0) && ((u32) ((u32) (M2C_FIELD(arg3, s32 *, 8) << 0x1D) >> 0x1D) >= 3U)) {
            goto loop_21;
        }
        if (((u32) (M2C_FIELD(arg3, s32 *, 8) << 0x1D) >> 0x1D) == 2) {
            M2C_FIELD(arg3, u32 *, 0x28) = (u32) M2C_FIELD(arg3, u32 *, 0x30);
        }
    }
    if (var_r4 != 0) {
        if ((M2C_FIELD(arg3, u32 *, 0x28) == 0) && (var_r6 == 0)) {

        } else {
loop_33:
            if ((M2C_FIELD(arg3, u32 *, 0x28) == 0) && (temp_r0_3 = StreamFillBuffer(arg3, NULL, 0), (temp_r0_3 != 0))) {
                if (temp_r0_3 == 1) {
                    M2C_FIELD(arg3, u8 *, 0xD) = 1U;
                } else {
                    M2C_FIELD(arg3, s32 *, 8) = (s32) (M2C_FIELD(arg3, s32 *, 8) & ~7);
                    M2C_FIELD(arg3, s8 *, 0xC) = 1;
                }
                temp_r0_3 = 0;
                M2C_FIELD(arg3, u32 *, 0x28) = temp_r0_3;
                var_r4 = 0;
                goto buffer_done;
            } else {
                temp_r0_4 = M2C_FIELD(arg3, u32 *, 0x28);
                sp0 = temp_r0_4;
                if (temp_r0_4 > var_r4) {
                    sp0 = var_r4;
                }
                MemCopy(var_r9, M2C_FIELD(arg3, s32 *, 0x24), sp0);
                temp_r0_4 = sp0;
                var_r4 -= temp_r0_4;
                M2C_FIELD(arg3, s32 *, 0x24) += temp_r0_4;
                var_r9 += temp_r0_4;
                {
                    u32 pending = M2C_FIELD(arg3, u32 *, 0x28);
                    pending -= sp0;
                    M2C_FIELD(arg3, u32 *, 0x28) = pending;
                    var_r5 += temp_r0_4;
                }
                if ((var_r4 != 0) && (var_r6 != 0)) {
                    goto loop_33;
                }
            }
        }
    }
buffer_done:
    if ((var_r4 != 0) && (var_r6 == 0)) {
        temp_r6 = M2C_FIELD(arg3, u16 **, 0x1C);
        temp_r10 = M2C_FIELD(arg3, u32 *, 0x20);
        M2C_FIELD(arg3, u16 **, 0x1C) = (u16 *) var_r9;
        M2C_FIELD(arg3, u32 *, 0x20) = var_r4;
        temp_r0_5 = StreamFillBuffer(arg3, &sp0, 1);
        if (temp_r0_5 != 0) {
            if (temp_r0_5 == 1) {
                M2C_FIELD(arg3, u8 *, 0xD) = 1U;
                M2C_FIELD(arg3, u32 *, 0x28) = 0U;
            } else {
                M2C_FIELD(arg3, s32 *, 8) = (s32) (M2C_FIELD(arg3, s32 *, 8) & ~7);
                M2C_FIELD(arg3, s8 *, 0xC) = 1;
                M2C_FIELD(arg3, u32 *, 0x28) = 0U;
            }
        }
        temp_r0_4 = sp0;
        M2C_FIELD(arg3, u16 **, 0x1C) = temp_r6;
        M2C_FIELD(arg3, u32 *, 0x20) = temp_r10;
        var_r5 += temp_r0_4;
        StreamResetBuffer(arg3);
        M2C_FIELD(arg3, u32 *, 0x28) = 0U;
    }
    return U32DivideRem(var_r5, size);
}
#pragma opt_common_subs reset
