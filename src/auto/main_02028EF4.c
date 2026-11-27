/* 37 functions from 0x02028EF4 to 0x02029E98 (main), found by ds-decomp. */
#include "common.h"
#include "wfc.h"
#include "exp_heap.h"


extern u8 gWfcSignalSampleCount;
extern u8 gWfcSignalSamples[16];

#pragma push
#pragma optimization_level 3
void func_02028ef4(void *arg0) {
    s32 WFC_StartWireless(M2C_UNK *);
    s32 WFC_SendConnectionData(M2C_UNK *, void *, M2C_UNK, M2C_UNK, s32);
    void WFC_DispatchEvent(M2C_UNK, void *, u32, s32);
    M2C_UNK WFC_SetState(M2C_UNK);
    extern void *gWfcSession;
    extern M2C_UNK WFC_OperationCallback;
    extern M2C_UNK func_0202899c;
    M2C_UNK var_r3;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r2;
    u16 temp_r3;
    u16 temp_r4;
    u32 var_r0;
    u32 temp_r1;
    void *session;
    u8 *flags;

    if (M2C_FIELD(arg0, u16 *, 2) == 0) {
        var_r0 = 0;
        M2C_FIELD(gWfcSession, s8 *, 0x226B) = 0;
        M2C_FIELD(gWfcSession, s16 *, 0x2282) = 0;
        session = gWfcSession;
        temp_r1 = M2C_FIELD(session, u32 *, 0x2260);
        switch (temp_r1) {
        case 5:
        case 6:
            WFC_SetState(3);
            WFC_DispatchEvent(1, NULL, 0U, 0x8F5);
            return;
        case 7:
            WFC_SetState(3);
            WFC_DispatchEvent(0, NULL, 0U, 0x8FB);
            return;
        case 8:
            temp_r4 = M2C_FIELD(session, u16 *, 0x22F8);
            M2C_FIELD(gWfcSession, u16 *, 0x22F8) = 0U;
            if ((temp_r4 == 0x12) && (flags = (u8 *)gWfcSession, flags += 0x2100, temp_r3 = M2C_FIELD(flags, u16 *, 0x70), (temp_r3 & 0x24) != 0x24)) {
                M2C_FIELD(flags, u16 *, 0x70) = (u16) (temp_r3 | 0x24);
                session = gWfcSession;
                temp_r2 = M2C_FIELD(session, s32 *, 0x2264);
                if ((temp_r2 & 0xC0000) == 0xC0000) {
                    var_r0 = 1;
                }
                if ((temp_r2 & 0x30000) != 0x30000) {
                    var_r3 = 1;
                } else {
                    var_r3 = 0;
                }
                temp_r0 = WFC_SendConnectionData(&func_0202899c, (u8 *)session + 0x2140, 0, var_r3, (u16) var_r0);
                switch (temp_r0) {
                case 2:
                    return;
                case 8:
                    WFC_SetState(0xC);
                    WFC_DispatchEvent(1, gWfcSession + 0x2140, temp_r4, 0x91C);
                    return;
                default:
                case 3:
                    WFC_SetState(0xB);
                    WFC_DispatchEvent(7, gWfcSession + 0x2140, temp_r4, 0x925);
                    return;
                }
            } else {
                WFC_SetState(3);
                WFC_DispatchEvent(1, gWfcSession + 0x2140, temp_r4, 0x92D);
                return;
            }
            break;
        case 9:
        case 12:
            WFC_SetState(3);
            WFC_DispatchEvent(0, gWfcSession + 0x2140, 1U, 0x935);
            return;
        case 10:
            WFC_SetState(3);
            WFC_DispatchEvent(0, gWfcSession + 0x2140, 0U, 0x93C);
            return;
        case 13:
            temp_r0_2 = WFC_StartWireless(&WFC_OperationCallback);
            switch (temp_r0_2) {
            case 2:
                return;
            case 8:
                WFC_SetState(0xC);
                WFC_DispatchEvent(1, NULL, 0U, 0x94A);
                return;
            default:
            case 3:
                WFC_SetState(0xB);
                WFC_DispatchEvent(7, NULL, 0U, 0x953);
                return;
            }
            break;
        default:
            WFC_SetState(0xB);
            WFC_DispatchEvent(7, NULL, M2C_FIELD(gWfcSession, u32 *, 0x2260), 0x959);
            return;
        }
    } else {
        WFC_SetState(0xB);
        WFC_DispatchEvent(7, NULL, 0U, 0x960);
    }
}
#pragma pop
/* Zero the WFC session's player-record list buffer (its capacity bytes) with
 * interrupts disabled; does nothing when there is no session or no buffer. */
void WFC_ClearPlayerList(void) {
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); void *GetSession(void); void MI_CpuFill8(void *,s32,s32);
s32 interruptState; void *session; void *block; void *list; s32 capacity;
interruptState=OS_DisableInterrupts(); session=GetSession();
if (!session) { OS_RestoreInterrupts(interruptState); return; }
block=(s8*)session+WFC_SESSION_PLAYER_BLOCK; list=M2C_FIELD(block,void**,WFC_PLAYER_LIST_BLOCK_OFFSET);
if(list) { capacity=M2C_FIELD(block,s32*,WFC_PLAYER_LIST_CAP_OFFSET); if(capacity>0) MI_CpuFill8(list,0,capacity); }
OS_RestoreInterrupts(interruptState);
}

/* Number of player records in the session's player list, read with interrupts
 * disabled: the list's insert count (its header's first word), or 0 when there
 * is no session or no list buffer big enough to hold a node. */
s32 WFC_GetPlayerListCount(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void *GetSession(void);
    s32 state;
    void *session;
    void *listBase;
    void *list;
    s32 count;

    state = OS_DisableInterrupts();
    session = GetSession();
    count = 0;
    if (session == NULL) {
        OS_RestoreInterrupts(state);
        return count;
    }
    listBase = (void *)((s8 *)session + WFC_SESSION_PLAYER_BLOCK);
    list = M2C_FIELD(listBase, void **, WFC_PLAYER_LIST_BLOCK_OFFSET);
    if (list != NULL) {
        u32 capacity = M2C_FIELD(listBase, u32 *, WFC_PLAYER_LIST_CAP_OFFSET);
        if (capacity > WFC_PLAYER_LIST_HEADER_SIZE) {
            count = M2C_FIELD(list, s32 *, WFC_PLAYER_LIST_COUNT);
        }
    }
    OS_RestoreInterrupts(state);
    return count;
}

#pragma push
#pragma opt_common_subs off
/* Set the WFC session's data lock (WFC_SESSION_DATA_LOCK), which makes incoming
 * player records be discarded, and return whether it was already set; 0 when there
 * is no session. */
s32 WFC_SetDataLock(s32 locked) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void *GetSession(void);
    s32 state;
    void *session;
    u8 wasLocked;
    s32 result;

    state = OS_DisableInterrupts();
    session = GetSession();
    if (session == NULL) {
        OS_RestoreInterrupts(state);
        return 0;
    }
    wasLocked = M2C_FIELD(session, u8 *, WFC_SESSION_DATA_LOCK);
    if (locked != 0) {
        result = wasLocked != 0;
        M2C_FIELD(session, u8 *, WFC_SESSION_DATA_LOCK) = 1;
    } else {
        result = wasLocked != 0;
        M2C_FIELD(session, u8 *, WFC_SESSION_DATA_LOCK) = 0;
    }
    OS_RestoreInterrupts(state);
    return result;
}
#pragma pop
/* Return the connection-data record for a player-list index while interrupts are disabled. */
s32 WFC_GetPlayerRecordByIndex(u16 playerIndex) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void *GetSession(void);
    void *WFC_FindPlayerNodeByIndex(void *);
    s32 interruptState;
    void *session;
    void *node;

    interruptState = OS_DisableInterrupts();
    session = GetSession();
    if (session == NULL) {
        OS_RestoreInterrupts(interruptState);
        return 0;
    }
    if ((node = WFC_FindPlayerNodeByIndex((void *)playerIndex)) == NULL) {
        OS_RestoreInterrupts(interruptState);
        return 0;
    }
    OS_RestoreInterrupts(interruptState);
    return (s32)node + 0x10;
}

/* Store the connection-data record `record` received for WFC player slot `slot`
 * in the session's player list: overwrite the node that already holds the
 * record's player id, else take a free node, else the least recently updated
 * one. The record is copied into the node and the node is moved to the tail so
 * it counts as the most recently updated. Nothing is stored while the session
 * discards player records or the record is already marked as gone. */
void WFC_StorePlayerRecord(void *record, u16 slot) {
    void *GetSession(void);
    void *WFC_FindPlayerById(s32);
    void *WFC_AllocPlayerNode(void);
    s32 WFC_GetOldestPlayerNode(void);
    void WFC_TouchPlayerNode(void *);
    void MI_CpuCopy32(void *, void *, u32);
    void *session;
    void *node;

    session = GetSession();
    if (!session) return;
    if (M2C_FIELD(session, u8 *, WFC_SESSION_DATA_LOCK) || M2C_FIELD(record, u16 *, 0x3c)) return;
    node = WFC_FindPlayerById((s32)record + WFC_PLAYER_RECORD_ID);
    if (!node) node = WFC_AllocPlayerNode();
    if (!node && M2C_FIELD(session, u32 *, 0x2278) == 1) node = (void *)WFC_GetOldestPlayerNode();
    if (!node) return;
    M2C_FIELD(node, u16 *, WFC_PLAYER_NODE_SLOT) = slot;
    MI_CpuCopy32(record, (u8 *)node + WFC_PLAYER_NODE_RECORD, 0xC0);
    WFC_TouchPlayerNode(node);
}

#pragma opt_strength_reduction off
/* Allocate a free node of the session's player-record list: take the first node
 * whose in-use byte is clear, give it the next index, append it at the tail as
 * the newest node and bump the list's insert count.  Returns NULL when the list
 * is missing, its buffer holds no node, or every node has already been used. */
void *WFC_AllocPlayerNode(void) {
    void *GetSession(void);
    void *session;
    void *block;
    void *list;
    u32 capacity;
    u32 maxNodes;
    u32 count;
    u32 i;
    u8 *nodes;
    void *node;
    void *oldTail;

    session = GetSession();
    block = (void *)((s8 *)session + WFC_SESSION_PLAYER_BLOCK);
    list = M2C_FIELD(block, void **, WFC_PLAYER_LIST_BLOCK_OFFSET);
    node = 0;
    if (list == 0) return node;
    capacity = M2C_FIELD(block, u32 *, WFC_PLAYER_LIST_CAP_OFFSET);
    if (capacity <= WFC_PLAYER_LIST_HEADER_SIZE) {
        return (void *)0;
    }
    maxNodes = (capacity - WFC_PLAYER_LIST_HEADER_SIZE) / WFC_PLAYER_NODE_SIZE;
    if (maxNodes == 0U) {
        return (void *)0;
    }
    count = M2C_FIELD(list, u32 *, WFC_PLAYER_LIST_COUNT);
    if (maxNodes <= count) {
        return (void *)0;
    }
    i = 0;
    if (i < maxNodes) {
        nodes = (u8 *)list + WFC_PLAYER_LIST_HEADER_SIZE;
        do {
            node = nodes + i * WFC_PLAYER_NODE_SIZE;
            if (M2C_FIELD(node, u8 *, WFC_PLAYER_NODE_IN_USE) == 0U) {
                break;
            }
        } while (++i < maxNodes);
    }
    if (i >= maxNodes) return node;
    M2C_FIELD(node, u8 *, WFC_PLAYER_NODE_IN_USE) = 1;
    count = M2C_FIELD(list, u32 *, WFC_PLAYER_LIST_COUNT);
    M2C_FIELD(node, u32 *, WFC_PLAYER_NODE_INDEX) = count;
    M2C_FIELD(node, void **, WFC_PLAYER_NODE_NEXT) = (void *)0;
    M2C_FIELD(node, void **, WFC_PLAYER_NODE_PREV) = M2C_FIELD(list, void **, WFC_PLAYER_LIST_TAIL);
    M2C_FIELD(list, void **, WFC_PLAYER_LIST_TAIL) = node;
    oldTail = M2C_FIELD(node, void **, WFC_PLAYER_NODE_PREV);
    if (oldTail != (void *)0) {
        M2C_FIELD(oldTail, void **, WFC_PLAYER_NODE_NEXT) = node;
    } else {
        M2C_FIELD(list, void **, WFC_PLAYER_LIST_HEAD) = node;
    }
    count = M2C_FIELD(list, u32 *, WFC_PLAYER_LIST_COUNT);
    count = count + 1;
    M2C_FIELD(list, u32 *, WFC_PLAYER_LIST_COUNT) = count;
    return node;
}
#pragma opt_strength_reduction on
/* Return the session's least recently updated player-list node, the head of the
 * list, which WFC_StorePlayerRecord reuses when the list is full; 0 when the
 * list buffer is missing or too small to hold a node. */
s32 WFC_GetOldestPlayerNode(void) {
    void *GetSession();
    void *session;
    void *list;

    session = GetSession();
    list = M2C_FIELD(session, void **, WFC_SESSION_PLAYER_LIST);
    if ((list != NULL) && ((u32) M2C_FIELD(session, u32 *, WFC_SESSION_PLAYER_LIST_CAP) > WFC_PLAYER_LIST_HEADER_SIZE)) {
        return M2C_FIELD(list, s32 *, WFC_PLAYER_LIST_HEAD);
    }
    return 0;
}

/* Find the session player-list node whose record carries the 6-byte id `playerId`,
 * or NULL when the list is empty or no node matches. */
void *WFC_FindPlayerById(s32 playerId) {
    s32 WFC_PlayerIdEqual(s32, s32);
    void *session;
    void *block;
    void *list;
    void *node;

    session = GetSession();
    block = session + WFC_SESSION_PLAYER_BLOCK;
    node = NULL;
    list = M2C_FIELD(session, void **, WFC_SESSION_PLAYER_LIST);
    if (playerId == 0) {
        return NULL;
    }
    if ((list != NULL) && ((u32) M2C_FIELD(block, u32 *, WFC_PLAYER_LIST_CAP_OFFSET) > WFC_PLAYER_LIST_HEADER_SIZE)) {
        node = M2C_FIELD(list, void **, WFC_PLAYER_LIST_HEAD);
        if (node != NULL) {
loop_5:
            if (WFC_PlayerIdEqual(node + WFC_PLAYER_NODE_RECORD + WFC_PLAYER_RECORD_ID, playerId) == 0) {
                node = M2C_FIELD(node, void **, WFC_PLAYER_NODE_NEXT);
                if (node != NULL) {
                    goto loop_5;
                }
            }
        }
    }
    return node;
}

/* Find the session's player-list node whose node index is `index`, or NULL when
 * the list is empty or no node matches. */
void *WFC_FindPlayerNodeByIndex(void *index) {
    void *session = GetSession();
    void *block = (u8 *)session + WFC_SESSION_PLAYER_BLOCK;
    void *list = M2C_FIELD(block, void **, WFC_PLAYER_LIST_BLOCK_OFFSET);
    void *node = 0;

    if (list != 0 && M2C_FIELD(block, u32 *, WFC_PLAYER_LIST_CAP_OFFSET) > WFC_PLAYER_LIST_HEADER_SIZE) {
        node = M2C_FIELD(list, void **, WFC_PLAYER_LIST_HEAD);
        if (node != 0) {
            do {
                if (M2C_FIELD(node, void **, WFC_PLAYER_NODE_INDEX) == index) break;
                node = M2C_FIELD(node, void **, WFC_PLAYER_NODE_NEXT);
            } while (node != 0);
        }
    }
    return node;
}

/* Move a player-record node to the tail (most recently updated end) of the
 * session's player list: unlink it if it is already in the list, then re-link
 * it at the tail. A node that was not in the list is new, so it also gets the
 * next node index and bumps the list's insert count. */
void WFC_TouchPlayerNode(void *node) {
    void *session;
    void *oldPrev;
    void *listBase;
    void *prev;
    void *next;
    void *oldNext;
    void *tail;
    void *cursor;
    register void *list;

    session = GetSession();
    listBase = session + 0x2000;
    list = M2C_FIELD(session, void **, WFC_SESSION_PLAYER_LIST);
    if ((node != NULL) && (list != NULL)) {
        if ((u32) M2C_FIELD(listBase, u32 *, 0x274) <= 0xCU) { /* buffer too small for any node */
            return;
        }
        cursor = M2C_FIELD(list, void **, WFC_PLAYER_LIST_HEAD);
        if (cursor != NULL) {
loop_7:
            if (cursor == node) {
                /* already listed: unlink it */
                oldPrev = M2C_FIELD(cursor, void **, WFC_PLAYER_NODE_PREV);
                oldNext = M2C_FIELD(cursor, void **, WFC_PLAYER_NODE_NEXT);
                if (oldPrev != NULL) {
                    M2C_FIELD(oldPrev, void **, WFC_PLAYER_NODE_NEXT) = oldNext;
                } else {
                    M2C_FIELD(list, void **, WFC_PLAYER_LIST_HEAD) = oldNext;
                }
                next = M2C_FIELD(cursor, void **, WFC_PLAYER_NODE_NEXT);
                prev = M2C_FIELD(cursor, void **, WFC_PLAYER_NODE_PREV);
                if (next != NULL) {
                    M2C_FIELD(next, void **, WFC_PLAYER_NODE_PREV) = prev;
                } else {
                    M2C_FIELD(list, void **, WFC_PLAYER_LIST_TAIL) = prev;
                }
            } else {
                cursor = M2C_FIELD(cursor, void **, WFC_PLAYER_NODE_NEXT);
                if (cursor != NULL) {
                    goto loop_7;
                }
            }
        }
        /* link the node at the tail */
        M2C_FIELD(node, s32 *, WFC_PLAYER_NODE_NEXT) = 0;
        M2C_FIELD(node, void **, WFC_PLAYER_NODE_PREV) = (void *) M2C_FIELD(list, void **, WFC_PLAYER_LIST_TAIL);
        M2C_FIELD(list, void **, WFC_PLAYER_LIST_TAIL) = node;
        tail = M2C_FIELD(node, void **, WFC_PLAYER_NODE_PREV);
        if (tail != NULL) {
            M2C_FIELD(tail, void **, WFC_PLAYER_NODE_NEXT) = node;
        } else {
            M2C_FIELD(list, void **, WFC_PLAYER_LIST_HEAD) = node;
        }
        if (cursor != NULL) { /* was already in the list: keep its index */
            return;
        }
        M2C_FIELD(node, s32 *, WFC_PLAYER_NODE_INDEX) = (s32) M2C_FIELD(list, s32 *, WFC_PLAYER_LIST_COUNT);
        M2C_FIELD(list, s32 *, WFC_PLAYER_LIST_COUNT) = (s32) (M2C_FIELD(list, s32 *, WFC_PLAYER_LIST_COUNT) + 1);
    }
}

/* Set up the asynchronous WFC send path once: mark it initialized, clear the
 * state left by the last send and create the mutex that serialises sends. */
void WFC_InitSendState(void) {
    void InitMutex(void *);
    extern M2C_UNK gWfcSendState;
    extern M2C_UNK gWfcSendLock;

    if (((WfcSendState *)&gWfcSendState)->initialized != 0) {
        return;
    }
    ((WfcSendState *)&gWfcSendState)->initialized = 1;
    ((WfcSendState *)&gWfcSendState)->result = WFC_SEND_OK;
    ((WfcSendState *)&gWfcSendState)->flags = 0;
    ((WfcSendState *)&gWfcSendState)->request = 0;
    InitMutex(&gWfcSendLock);
}

/* Hand a received WFC link data block to the IP stack: if a send callback is
 * installed, queue the block's frame (with its link addresses) for the network
 * sender. */
void WFC_QueueReceivedFrame(void *block) {
    extern M2C_UNK gWfcSendState;
    if (((WfcSendState *)&gWfcSendState)->callback == NULL) {
        return;
    }
    ((WfcSendState *)&gWfcSendState)->callback((u8 *)block + WFC_RECV_SRC_LINK, (u8 *)block + WFC_RECV_DST_LINK, (u8 *)block + WFC_RECV_FRAME, M2C_FIELD(block, u16 *, WFC_RECV_FRAME_LEN));
}

#pragma opt_common_subs off
/* State-timer tick while the session is linking: send the local player's
 * connection data to the peer through the send lock. A send already in flight
 * leaves the lock to its completion callback. */
void WFC_SendConnDataRequest(void) {
    s32 GetSession(void);
    s32 WFC_TryLockSend(void *);
    s32 WFC_SubmitRequest(s32, void *, void *, u32);
    void WFC_OnSendRequestComplete(void);
    s32 WFC_UnlockSend(M2C_UNK *);
    extern M2C_UNK gWfcSendLock;
    void *session;
    s32 result;

    session = (void *)GetSession();
    if (session == 0) return;
    if (M2C_FIELD((s8 *)session + WFC_SESSION_PLAYER_BLOCK, s32 *, WFC_SESSION_BLOCK_STATE) != WFC_SESSION_STATE_LINKING) return;
    if (M2C_FIELD((s8 *)session + WFC_SESSION_PLAYER_BLOCK, u8 *, WFC_SESSION_BLOCK_ABORT) == 1) return;
    if (WFC_TryLockSend(&gWfcSendLock) == 0) return;
    result = WFC_SubmitRequest((s32)WFC_OnSendRequestComplete, (s8 *)session + WFC_SESSION_CONN_DATA + WFC_PLAYER_RECORD_ID, (s8 *)session + WFC_SESSION_SEND_BUFFER, 0);
    if (result == WFC_CMD_OK) return;
    WFC_UnlockSend(&gWfcSendLock);
}
#pragma opt_common_subs reset
/* Pointer to the local connection record's alternate code inside the session
 * (WFC_RECORD_CODE_ALT), usable only while the session is linking and has not
 * failed; NULL otherwise. */
void *WFC_GetConnectionAltCode(void) {
    s32 GetSession(void);
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    void *session;
    void *code;
    s32 state;

    code = NULL;
    session = (void *)GetSession();
    state = OS_DisableInterrupts();
    if ((session != NULL) && (M2C_FIELD(session, s32 *, WFC_SESSION_STATE) == WFC_SESSION_STATE_LINKING) && (M2C_FIELD(session, u8 *, WFC_SESSION_ABORT) == 0)) {
        code = (void *)((char *)session + WFC_SESSION_CONN_DATA + WFC_RECORD_CODE_ALT);
    }
    OS_RestoreInterrupts(state);
    return code;
}

/* When the session is linking a friend and has not aborted, return the friend
 * code (WFC_RECORD_CODE) of the connection record and store its length in
 * *codeLength; otherwise return NULL and a length of 0. */
void *Wfc_GetConnectionCode(u16 *codeLength) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 GetSession(void);

    s32 session;
    void *code;
    u16 length;
    s32 state;

    code = (void *)0;
    length = 0;
    session = GetSession();
    state = OS_DisableInterrupts();
    if (session != 0) {
        if (M2C_FIELD(session, s32 *, WFC_SESSION_STATE) == WFC_SESSION_STATE_LINKING) {
            if (M2C_FIELD(session, u8 *, WFC_SESSION_ABORT) == 0) {
                length = (u16)M2C_FIELD(session, u16 *, WFC_SESSION_CONN_DATA + WFC_RECORD_CODE_LEN);
                code = (void *)((char *)session + WFC_SESSION_CONN_DATA + WFC_RECORD_CODE);
            }
        }
    }
    OS_RestoreInterrupts(state);
    if (codeLength != (u16 *)0) {
        *codeLength = length;
    }
    return code;
}

/* Install the callback the WFC send path calls to queue a received link block
 * (NULL clears it), with interrupts disabled. */
void WFC_SetSendCallback(s32 callback) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    extern M2C_UNK gWfcSendState;
    s32 state = OS_DisableInterrupts();
    ((WfcSendState *)&gWfcSendState)->callback = (void (*)(void *, void *, void *, u16))callback;
    OS_RestoreInterrupts(state);
}

#pragma opt_if-conversion off
/* Sends a packet through the WFC layer: copies the first data block and the
 * optional second block into the session's send buffer, starts the transfer and
 * sleeps until the completion callback reports the result. Returns the packet
 * length, or a negative error code. */
s32 WFC_SendPacket(void *destAddr, void *data, s32 dataLen, s32 extra, s32 extraLen) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 GetSession(void);
    void LockMutex(void *);
    void UnlockMutex(void *);
    void MI_CpuCopy8(void *, void *, s32);
    s32 WFC_SubmitRequest(s32, void *, void *, u32);
    void OS_SleepThread(void *);
    void WFC_OnSendComplete(void *);
    extern M2C_UNK gWfcSendLock;
    extern M2C_UNK gWfcSendThread;
    extern M2C_UNK gWfcSendState;

    s32 irqState;
    s32 work;
    s32 session;
    s32 result;
    s32 status;

    work = extra;
    irqState = OS_DisableInterrupts();
    if (GetSession() == 0) {
        OS_RestoreInterrupts(irqState);
        return -1;
    }
    LockMutex(&gWfcSendLock);
    session = GetSession();
    if (session == 0) {
        UnlockMutex(&gWfcSendLock);
        OS_RestoreInterrupts(irqState);
        return -1;
    }
    if (M2C_FIELD((void *)session, s32 *, WFC_SESSION_STATE) != 9 ||
        M2C_FIELD((void *)session, u8 *, WFC_SESSION_ABORT) == 1) {
        UnlockMutex(&gWfcSendLock);
        OS_RestoreInterrupts(irqState);
        return -4;
    }
    MI_CpuCopy8(data, (void *)(session + WFC_SESSION_SEND_BUFFER), dataLen);
    if (extraLen > 0) {
        MI_CpuCopy8(work, (void *)(session + WFC_SESSION_SEND_BUFFER + dataLen), extraLen);
    }
    work = dataLen + extraLen;
    result = WFC_SubmitRequest((s32)WFC_OnSendComplete, destAddr, (void *)(session + WFC_SESSION_SEND_BUFFER), (u32)(u16)work);
    switch (result) {
        case 2:
            break;
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            UnlockMutex(&gWfcSendLock);
            OS_RestoreInterrupts(irqState);
            return -5;
    }
    OS_SleepThread(&gWfcSendThread);
    status = ((WfcSendState *)&gWfcSendState)->result;
    switch (status) {
    case WFC_SEND_OK: break;
    case 1:
    default:
        UnlockMutex(&gWfcSendLock);
        OS_RestoreInterrupts(irqState);
        return -5;
    }
    UnlockMutex(&gWfcSendLock);
    OS_RestoreInterrupts(irqState);
    return work;
}
#pragma opt_if-conversion reset
/* Completion callback of a WFC send: store the transfer's result in the send
 * state, rearm the state timer on success and wake the thread waiting for the
 * send.  Records of any other command are ignored. */
void WFC_OnSendComplete(void *event) {
    void WFC_RearmStateTimer(void);
    void OS_WakeupThread(void *);
    extern M2C_UNK gWfcSendState;
    extern M2C_UNK gWfcSendThread;

    if (M2C_FIELD(event, u16 *, WFC_COMPLETE_COMMAND) != WFC_SEND_COMMAND) return;
    M2C_FIELD(&gWfcSendState, u32 *, 0x24) = M2C_FIELD(event, u16 *, WFC_COMPLETE_RESULT);
    if (M2C_FIELD(event, u16 *, WFC_COMPLETE_RESULT) == 0) WFC_RearmStateTimer();
    OS_WakeupThread(&gWfcSendThread);
}

void WFC_OnSendRequestComplete(void) {
    M2C_UNK WFC_UnlockSend(M2C_UNK *);
    extern M2C_UNK gWfcSendLock;
    WFC_UnlockSend(&gWfcSendLock);
}

/* Non-blocking recursive lock of the WFC send mutex: take it when free, count a
 * nested lock when the same fixed holder already owns it, and report failure
 * when someone else holds it. */
s32 WFC_TryLockSend(void *lock) {
    extern M2C_UNK func_01ff8000;
    void *owner;

    owner = M2C_FIELD(lock, void **, OSMUTEX_OWNER);
    if (owner == NULL) {
        M2C_FIELD(lock, void **, OSMUTEX_OWNER) = &func_01ff8000;
        M2C_FIELD(lock, s32 *, OSMUTEX_COUNT) = (s32) (M2C_FIELD(lock, s32 *, OSMUTEX_COUNT) + 1);
        return 1;
    }
    if (owner != &func_01ff8000) {
        return 0;
    }
    M2C_FIELD(lock, s32 *, OSMUTEX_COUNT) = (s32) (M2C_FIELD(lock, s32 *, OSMUTEX_COUNT) + 1);
    return 1;
}

/* Release the recursive WFC send lock: only its fixed holder may unlock it, and
 * the last nested unlock clears the owner and wakes the threads queued on it. */
s32 WFC_UnlockSend(M2C_UNK *lock) {
    void OS_WakeupThread(void *);
    extern M2C_UNK func_01ff8000;

    if (M2C_FIELD(lock, void **, OSMUTEX_OWNER) != (void *)&func_01ff8000) {
        return;
    }
    M2C_FIELD(lock, s32 *, OSMUTEX_COUNT) -= 1;
    if (M2C_FIELD(lock, s32 *, OSMUTEX_COUNT) != 0) {
        return;
    }
    M2C_FIELD(lock, void **, OSMUTEX_OWNER) = NULL;
    OS_WakeupThread(lock);
    return;
}

/* Whether two WFC player ids (the consoles' 6-byte MAC addresses) are equal. */
s32 WFC_PlayerIdEqual(s32 a, s32 b) {
    u8 *id0 = (u8 *)a;
    u8 *id1 = (u8 *)b;
    s32 i = 0;
    do {
        if (id0[i] != id1[i]) {
            return 0;
        }
        i++;
    } while (i < WFC_PLAYER_ID_SIZE);
    return 1;
}

/* The link's signal grade (0..3) while the session is establishing its link, or 0
 * otherwise: read with interrupts disabled and only reported in
 * WFC_SESSION_STATE_LINKING. */
s32 WFC_GetLinkSignalLevel(void) {
    s32 OS_DisableInterrupts(void);
    void OS_RestoreInterrupts(s32);
    s32 GetSession(void);
    s32 WFC_GetSignalGrade(void);
    s32 interruptState;
    s32 grade;
    s32 session;

    interruptState = OS_DisableInterrupts();
    session = GetSession();
    grade = 0;
    if (session != 0) {
        if (M2C_FIELD(session, s32 *, WFC_SESSION_STATE) == WFC_SESSION_STATE_LINKING) {
            grade = WFC_GetSignalGrade();
        }
    }
    OS_RestoreInterrupts(interruptState);
    return grade;
}

/* Average the signal samples taken so far: 0 before the first sample, the
 * mean of the whole ring once it has wrapped. */
u8 WFC_GetAverageSignal(void) {
    s32 RuntimeIntDivMod(s32, s32);
    extern u8 gWfcSignalSampleCount;
    extern u8 gWfcSignalSamples[16];
    u8 count = gWfcSignalSampleCount;
    s32 sum = 0;
    s32 i;
    s32 average;

    if (count > WFC_SIGNAL_RING_FULL) {
        i = 0;
        do {
            sum += gWfcSignalSamples[i];
            i++;
        } while (i < WFC_SIGNAL_SAMPLE_COUNT);
        average = sum / WFC_SIGNAL_SAMPLE_COUNT;
    } else if (count != 0) {
        i = 0;
        while (i < count) {
            sum += gWfcSignalSamples[i];
            i++;
        }
        average = RuntimeIntDivMod(sum, count);
    } else {
        average = 0;
    }
    return (u8)average;
}

/* Bucket the averaged link signal into a 0..3 connection grade: 0 below
 * WFC_SIGNAL_GRADE_1_MIN, one level per threshold passed. */
s32 WFC_GetSignalGrade(void) {
    u8 WFC_GetAverageSignal();
    s32 grade;
    u32 average;

    average = WFC_GetAverageSignal();
    grade = 0;
    if (average >= WFC_SIGNAL_GRADE_3_MIN) {
        grade = 3;
    } else if (average >= WFC_SIGNAL_GRADE_2_MIN) {
        grade = 2;
    } else if (average >= WFC_SIGNAL_GRADE_1_MIN) {
        grade = 1;
    }
    return grade;
}

#pragma opt_propagation off
void func_02029bd0(s32 arg0) {
extern u8 gWfcSignalSampleCount;
extern u8 gWfcSignalSamples[16];
register u8 value;
s32 shifted=arg0>>2;
if(!(arg0&2)) shifted+=25;
value=(u8)shifted;
gWfcSignalSamples[gWfcSignalSampleCount%16]=value;
if(gWfcSignalSampleCount<16) gWfcSignalSampleCount++;
else gWfcSignalSampleCount=(gWfcSignalSampleCount+1)%16+16;
}
#pragma opt_propagation reset
/* Initialise an empty doubly-linked list whose nodes keep their link pair at
 * byte offset `nodeOffset` inside the node. */
void ListInit(void *list, s16 nodeOffset) {
    M2C_FIELD(list, s32 *, DLIST_HEAD) = 0;
    M2C_FIELD(list, s32 *, DLIST_TAIL) = 0;
    M2C_FIELD(list, u16 *, DLIST_COUNT) = 0;
    M2C_FIELD(list, u16 *, DLIST_NODE_OFFSET) = nodeOffset;
}

/* Make `node` the only node of the doubly-linked list `list`: clear its link
 * pair, point the list's head and tail at it and count it.  The DLIST_* macros
 * name the header and link fields. */
void ListAddFirst(void *list, void *node) {
    u16 nodeOffset = M2C_FIELD(list, u16 *, DLIST_NODE_OFFSET);
    void *link = (void *)((s8 *)node + nodeOffset);

    M2C_FIELD(link, s32 *, DLIST_LINK_NEXT) = 0;
    M2C_FIELD(link, s32 *, DLIST_LINK_PREV) = 0;
    M2C_FIELD(list, void **, DLIST_HEAD) = node;
    M2C_FIELD(list, void **, DLIST_TAIL) = node;
    M2C_FIELD(list, u16 *, DLIST_COUNT) += 1;
}

/* Append `node` at the tail of the doubly-linked list `list`: an empty list goes
   through ListAddFirst, otherwise the node is linked after the current tail and
   becomes the new tail.  The DLIST_* macros name the header and link fields. */
void ListAppend(void *list, void *node) {
    void ListAddFirst(void *, void *);
    u16 nodeOffset;

    if (M2C_FIELD(list, void **, DLIST_HEAD) == (void *)0) {
        ListAddFirst(list, node);
        return;
    }
    nodeOffset = M2C_FIELD(list, u16 *, DLIST_NODE_OFFSET);
    M2C_FIELD(node, s32 *, nodeOffset) = M2C_FIELD(list, s32 *, DLIST_TAIL);
    M2C_FIELD((void *)((char *)node + nodeOffset), s32 *, DLIST_LINK_NEXT) = 0;
    M2C_FIELD((void *)(M2C_FIELD(list, void **, DLIST_TAIL) + M2C_FIELD(list, u16 *, DLIST_NODE_OFFSET)), s32 *, DLIST_LINK_NEXT) = (s32)node;
    M2C_FIELD(list, void **, DLIST_TAIL) = node;
    M2C_FIELD(list, u16 *, DLIST_COUNT) = (u16)(M2C_FIELD(list, u16 *, DLIST_COUNT) + 1);
}

/* Prepend `node` at the head of the doubly-linked list `list`: an empty list goes
   through ListAddFirst, otherwise the node's previous link is cleared and it is
   chained in front of the current head.  The DLIST_* macros name the header and
   link fields. */
void ListPrepend(void *list, void *node) {
    void ListAddFirst(void *, void *);
    u16 nodeOffset;

    if (M2C_FIELD(list, void **, DLIST_HEAD) == (void *)0) {
        ListAddFirst(list, node);
        return;
    }
    nodeOffset = M2C_FIELD(list, u16 *, DLIST_NODE_OFFSET);
    M2C_FIELD(node, s32 *, nodeOffset) = 0;
    M2C_FIELD((void *)((char *)node + nodeOffset), s32 *, DLIST_LINK_NEXT) = M2C_FIELD(list, s32 *, DLIST_HEAD);
    M2C_FIELD(M2C_FIELD(list, void **, DLIST_HEAD), s32 *, M2C_FIELD(list, u16 *, DLIST_NODE_OFFSET)) = (s32)node;
    M2C_FIELD(list, void **, DLIST_HEAD) = node;
    M2C_FIELD(list, u16 *, DLIST_COUNT) = (u16)(M2C_FIELD(list, u16 *, DLIST_COUNT) + 1);
}

/* Inserts `node` into the doubly-linked list `list` before the node `before`: a
 * NULL `before` appends at the tail and the current head prepends.  The list keeps
 * its head at +0, its tail at +4, its node count at +8 and the byte offset of each
 * node's links at +0xA (first word the previous node, second the next). */
void ListInsertBefore(void *list, void *before, void *node) {
void ListAppend(void *,void *); void ListPrepend(void *,void *);
void *link; void *oldPrev; u16 off;
if(!before) {ListAppend(list,node);return;}
if(before==M2C_FIELD(list,void **,0)) {ListPrepend(list,node);return;}
off=M2C_FIELD(list,u16 *,10);
link=(char *)node+off;
oldPrev=M2C_FIELD(before,void**,off);
M2C_FIELD(link,void **,0)=oldPrev;
M2C_FIELD(link,void **,4)=before;
M2C_FIELD((char *)oldPrev+off,void **,4)=node;
M2C_FIELD(before,s32*,M2C_FIELD(list,u16*,10))=(s32)node;
M2C_FIELD(list,u16 *,8)++;
}

/* Unlink an entry from the doubly-linked list: fix the head (DLIST_HEAD) or the
 * previous entry's next link, then the tail (DLIST_TAIL) or the next entry's
 * previous link, clear the entry's own link pair and decrement DLIST_COUNT. */
void ListRemove(void *list, void *entry) {
    u16 off;
    u32 *link;
    u32 *prev;
    u32 next;

    off = *(u16 *)((u8 *)list + DLIST_NODE_OFFSET);
    link = (u32 *)((u8 *)entry + off);
    if (*link == 0) {
        *(u32 *)((u8 *)list + DLIST_HEAD) = link[1];
    } else {
        prev = (u32 *)((u8 *)(*link) + off);
        prev[1] = link[1];
    }
    next = link[1];
    if (next == 0) {
        *(u32 *)((u8 *)list + DLIST_TAIL) = link[0];
    } else {
        *(u32 *)((u8 *)next + *(u16 *)((u8 *)list + DLIST_NODE_OFFSET)) = link[0];
    }
    link[0] = 0;
    link[1] = 0;
    off = *(u16 *)((u8 *)list + DLIST_COUNT);
    off = off - 1;
    *(u16 *)((u8 *)list + DLIST_COUNT) = off;
}

/* Return the node after `node` in `list`, or the list's head when `node` is NULL. */
s32 ListNext(void *list, s32 node) {
    if (node == 0) {
        return M2C_FIELD(list, s32 *, DLIST_HEAD);
    }
    return M2C_FIELD((node + M2C_FIELD(list, u16 *, DLIST_NODE_OFFSET)), s32 *, DLIST_LINK_NEXT);
}

s32 ListPrev(void *arg0, s32 arg1) {
    if (arg1 == 0) {
        return M2C_FIELD(arg0, s32 *, 4);
    }
    return M2C_FIELD((arg1 + M2C_FIELD(arg0, u16 *, 0xA)), s32 *, 0);
}

/* Find the heap whose memory area covers `address`, walking the heap list `list`
 * and descending into the child list (HEAP_CHILD_LIST) of any heap that covers
 * the address.  Returns the containing heap header, or NULL when none covers it. */
M2C_UNK FindHeapForAddress(M2C_UNK *list, M2C_UNK address) {
    s32 ListNext(void *, s32);
    M2C_UNK listStart = (M2C_UNK)list;
    M2C_UNK key = address;
    M2C_UNK node;
    M2C_UNK found;

    node = ListNext((void *)list, 0);
    while (node != 0) {
        if (M2C_FIELD((void *)node, u32 *, HEAP_AREA_START) > (u32)key) {
            goto advance;
        }
        if ((u32)key >= M2C_FIELD((void *)node, u32 *, HEAP_AREA_END)) {
            goto advance;
        }
        found = FindHeapForAddress((M2C_UNK *)((s8 *)(void *)node + HEAP_CHILD_LIST), key);
        if (found != 0) {
            return found;
        }
        return node;
    advance:
        node = ListNext((void *)listStart, node);
    }
    return 0;
}

/* Return the list a heap at `address` belongs in: the child-list header
 * (HEAP_CHILD_LIST) of the heap whose memory area contains the address, or the
 * global heap list when no heap contains it. */
M2C_UNK *GetHeapParentList(M2C_UNK address) {
    s32 FindHeapForAddress(M2C_UNK *, M2C_UNK);
    extern M2C_UNK gHeapList;
    M2C_UNK *parentList;
    s32 heap;

    parentList = &gHeapList;
    heap = FindHeapForAddress(&gHeapList, address);
    if (heap != 0) {
        parentList = (M2C_UNK *)(heap + HEAP_CHILD_LIST);
    }
    return parentList;
}

