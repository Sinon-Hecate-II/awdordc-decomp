/* 37 functions from 0x020E34BC to 0x020E4490 (main), found by ds-decomp. */
#include "common.h"
#include "ghttp.h"

/* A list node in the online player screen: its type table, the player record
 * array, its count-out slot and the entries collected so far.  Each player record
 * is 0x310 bytes (id, name, ... data size at +0x30C). */
#define LIST_VTABLE    0x00 /* s32 *type table */
#define LIST_FIRST     0x34 /* void *first player record */
#define LIST_COUNT     0x38 /* s32 number of players collected */
#define LIST_LIMIT     0x3C /* s32 most players the list may hold */
#define LIST_CAPACITY  0x40 /* s32 *count-out: the answering request writes its count here */
#define LIST_IDS       0x44 /* s32 *player id array, LIST_CAPACITY entries */
#define LIST_UNK48     0x48
#define LIST_ID_SLOTS  0x40 /* id array size the ids are padded to */
#define PLAYER_REC_SIZE 0x310 /* one player record */
#define PLAYER_ID      0x04 /* s32 player id, -1 when free */
#define PLAYER_DATA_LEN 0x30C /* s32 bytes of name data at +0x10 */


static inline void irq_save(s32 *state) {
    *state = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
}

static inline void irq_restore(s32 *state) {
    (void)*(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = *state;
}

typedef struct {
    s32 ime;
} IntrState;

static inline BOOL check_val(void *arg0, s32 *sp) {
    s32 *arr;
    s32 val;
    s32 j;
    s32 count;

    count = M2C_FIELD(arg0, s32 *, 0x38);
    val = sp[1];
    for (j = 0; (u32)j < (u32)count; j++) {
        arr = M2C_FIELD(arg0, s32 **, 0x44);
        if (arr[j] == val) {
            return TRUE;
        }
    }
    return FALSE;
}


s32 func_020e352c(s32, s32);
#pragma opt_common_subs off
s32 HeapAllocBlock(s32 arg0) {
 u32 s;
 volatile u32 saved;
 u16 old;
 s32 result;
 old = *(volatile u16 *)0x04000208;
 *(volatile u16 *)0x04000208 = 0;
 saved = old;
 result = func_020e352c(arg0, 8);
 s = saved;
 (void)*(volatile u16 *)0x04000208;
 *(volatile u16 *)0x04000208 = s;
 return result;
}
#pragma opt_common_subs reset
s32 func_020e3580(s32, s32);
#pragma push
#pragma opt_global_reg off
s32 func_020e34f4(s32 arg0) {
 s32 func_020e3580(s32,s32);
 s32 s;
 volatile u32 saved;
 u32 old;
 s32 result;
 old=*(volatile u16*)0x04000208;
 *(volatile u16*)0x04000208=0;
 saved=old;
 result=func_020e3580(arg0,8);
 s=saved;
 (void)*(volatile u16*)0x04000208;
 *(volatile u16*)0x04000208=s;
 return result;
}
#pragma pop
s32 func_020e352c(s32 arg0, s32 arg1) {
    M2C_UNK func_0202a468(s32, s32, s32);
    extern s32 data_02168fe4;
    volatile u32 saved;
    u32 temp;
    void *p;
    temp = *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 0;
    p = (void *)data_02168fe4;
    saved = temp;
    func_0202a468((s32)p, arg0, arg1);
    {
        u32 s = saved;
        (void)*(volatile u16 *)0x04000208;
        *(volatile u16 *)0x04000208 = s;
    }
}

s32 func_020e3580(s32 arg0,s32 arg1) {
#pragma push
#pragma opt_global_reg on
extern s32 data_02168fe4;
s32 result;
volatile u32 saved;
u32 temp=*(volatile u16*)0x04000208;
*(volatile u16*)0x04000208=0;
saved=temp;
{
    s32 direction = -arg1;
    s32 block = data_02168fe4;
    result = func_0202a468(block, arg0, direction);
}
{
    volatile u16 *ime = (volatile u16 *)0x04000208;
    u16 restored = saved;
    *ime = ((void)*ime, restored);
}
return result;
#pragma pop
}
#pragma push
#pragma opt_propagation off
void HeapFreeBlock(s32 arg0) {
void func_0202a498(s32,s32);
extern s32 data_02168fe4;
volatile u32 saved;
u32 temp;
temp=*(volatile u16*)0x04000208;
*(volatile u16*)0x04000208=0;
saved=temp;
func_0202a498(data_02168fe4,arg0);
temp=saved; arg0=temp;
(void)*(volatile u16*)0x04000208;
*(volatile u16*)0x04000208=arg0;
}
#pragma pop
void func_020e3610(M2C_UNK arg0) {
    M2C_UNK Sprite_ResumeAnimation(M2C_UNK);
    s32 IsSessionInError();
    s32 func_0208477c();
    s32 func_ov010_02226364();
    if ((IsSessionInError() != 0) || (func_0208477c() != 0)) {
        Sprite_ResumeAnimation(arg0);
        return;
    }
    if (func_ov010_02226364() == 0) {
        return;
    }
    Sprite_ResumeAnimation(arg0);
}

void func_020e3654(M2C_UNK arg0) {
    s32 func_ov010_02226560();
    if ((IsSessionInError() != 0) || (func_0208477c() != 0)) {
        Sprite_ResumeAnimation(arg0);
        return;
    }
    if (func_ov010_02226560() == 0) {
        return;
    }
    Sprite_ResumeAnimation(arg0);
}

void func_020e3698(M2C_UNK arg0) {
    s32 func_ov010_022266ec();
    if ((IsSessionInError() != 0) || (func_0208477c() != 0)) {
        Sprite_ResumeAnimation(arg0);
        return;
    }
    if (func_ov010_022266ec() == 0) {
        return;
    }
    Sprite_ResumeAnimation(arg0);
}

void func_020e36dc(void) {
   void func_020e4304();
   s32 SubmitWebRegisterRequest(void);
   if (SubmitWebRegisterRequest() == 0) return;
   func_020e4304();
}

void func_020e36f4(void) {
   s32 func_ov010_02226888(void);
   void func_020e4304();
   if (func_ov010_02226888() == 0) return;
   func_020e4304();
}

void func_020e370c(void *arg0) {
   M2C_UNK SetSpriteAnimation(void *, s32);
   s32 func_ov010_02226738(void);
   if (func_ov010_02226738() == 5) {
     *M2C_FIELD(arg0, s32 **, 0x40) = 1;
   } else {
     SetSpriteAnimation(arg0, 1);
   }
}

void func_020e3738(void *arg0) {
    M2C_UNK SetSpriteAnimation(void *, M2C_UNK);
    s32 func_ov010_02226334(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, void *);
    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    if (func_ov010_02226334(0, 2, 0, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), arg0) != 0) {
        return;
    }
    SetSpriteAnimation(arg0, 1);
}

void func_020e3788(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
 void *CreateSpriteForOwner(void *, s32);
 extern s32 data_0212d950;
 extern s32 gOnlinePlayerListVtable;
 void *temp_r0;
 temp_r0 = CreateSpriteForOwner(&data_0212d950, arg3);
 if (temp_r0 == NULL) return;
 M2C_FIELD(temp_r0, s32 **, 0) = &gOnlinePlayerListVtable;
 M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
 M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
 M2C_FIELD(temp_r0, s32 *, 0x3c) = 0;
 M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
 M2C_FIELD(temp_r0, s32 *, 0x44) = 0;
 M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
}

/* Update step of the online-player list: once the web request has completed
 * (WEB_TXN_COMPLETE), copy the first player entry of the answer - its id fields,
 * name length and name data - into the list's first record and report one record
 * filled to the owner's count; otherwise start the list's waiting animation. */
void FillOnlinePlayerListFirstEntry(void *list) {
    s32 func_ov010_02226738(void);
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 Ov010_GetWebPlayerEntry(s32, s32 *);
    void MI_CpuCopy8(s32, void *, s32);
    s32 entry[7];
    u8 *record;

    if (func_ov010_02226738() != WEB_TXN_COMPLETE) {
        SetSpriteAnimation(list, 1);
        return;
    }

    record = M2C_FIELD(list, u8 **, LIST_FIRST);
    if (Ov010_GetWebPlayerEntry(0, entry) == 0) {
        return;
    }

    M2C_FIELD(record, s32 *, 0) = entry[0];
    M2C_FIELD(record, s32 *, 0x4) = entry[1];
    M2C_FIELD(record, s32 *, 0x8) = entry[2];
    M2C_FIELD(record, s32 *, 0xc) = entry[3];
    M2C_FIELD(record, s32 *, 0x30c) = entry[5];

    MI_CpuCopy8(entry[6], record + 0x10, entry[5]);

    *M2C_FIELD(list, s32 **, LIST_CAPACITY) = 1;
}

/* Submit the player list's stored ids to the server (web request kind 3): the
   payload is {byte length 0x10C, flag 1, count + 1, 0} followed by the list's
   64-slot id array; clear the count-out slot for the answer and start the list's
   waiting animation when the request cannot be queued. */
void RequestOnlinePlayerListIds(void *list) {
    void MIi_CpuCopy32(s32, void *, s32);
    s32 SubmitWebGetRequest(s32, s32, s32, void *, void *);
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 request[68];
    s32 count;

    *M2C_FIELD(list, s32 **, LIST_CAPACITY) = 0;
    count = M2C_FIELD(list, s32 *, LIST_COUNT) + 1;
    request[0] = 0x10C;
    request[2] = count;
    request[3] = 0;
    request[1] = 1;
    MIi_CpuCopy32(M2C_FIELD(list, s32 *, LIST_IDS), &request[4], 0x100);
    if (SubmitWebGetRequest(3, 0, 0xFF, request, list) != 0) {
        return;
    }
    SetSpriteAnimation(list, 1);
}

/* Build a list node for `capacity` online players: install its type table, keep
 * the record array and the id slot, take an id array of LIST_ID_SLOTS entries
 * from the heap, store the local player's id in it (the rest zero), and clear
 * every player record in the array.  Returns the node, or NULL on failure. */
void *CreateOnlinePlayerListNode(void *records, s32 unk34, s32 capacity) {
    void *CreateSpriteForOwner(void *, s32);
    s32 func_020e34f4(s32);
    s32 GetOnlineLocalPlayerId(void);
    void MIi_CpuCopy32(s32, void *, s32);
    void CpuFill(s32, s32, s32);
    extern s32 data_0212d870;
    extern s32 gOnlinePlayerListVtable;
    u32 end = (u32)records;
    void *node;
    s32 playerId;
    s32 count;
    u8 *rec;

    node = CreateSpriteForOwner(&data_0212d870, capacity);
    if (node != NULL) {
        M2C_FIELD(node, s32 **, LIST_VTABLE) = &gOnlinePlayerListVtable;
        M2C_FIELD(node, s32 *, LIST_FIRST) = (s32)records;
        M2C_FIELD(node, s32 *, LIST_COUNT) = 1;
        M2C_FIELD(node, s32 *, LIST_LIMIT) = 0;
        M2C_FIELD(node, s32 *, LIST_CAPACITY) = unk34;
        M2C_FIELD(node, s32 *, LIST_IDS) = func_020e34f4(0x100);
        M2C_FIELD(node, s32 *, LIST_UNK48) = 0;
        playerId = GetOnlineLocalPlayerId();
        MIi_CpuCopy32((s32)&playerId, (void *)M2C_FIELD(node, s32 *, LIST_IDS), M2C_FIELD(node, s32 *, LIST_COUNT) * 4);
        count = M2C_FIELD(node, s32 *, LIST_COUNT);
        CpuFill(0, M2C_FIELD(node, s32 *, LIST_IDS) + count * 4, (LIST_ID_SLOTS - count) * 4);
        for (rec = (u8 *)records; (u32)rec < end + M2C_FIELD(node, s32 *, LIST_COUNT) * PLAYER_REC_SIZE; rec += PLAYER_REC_SIZE) {
            M2C_FIELD(rec, s32 *, PLAYER_ID) = -1;
            M2C_FIELD(rec, s32 *, 0x8) = 0;
            M2C_FIELD(rec, s32 *, PLAYER_DATA_LEN) = 0;
        }
    }
    return node;
}

/* Populates the list's node array from the ov010 source (mode 5 only), skipping entries whose id matches a sentinel value. */
void func_020e39d8(void *list) {
    s32 func_ov010_02226738(void);
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 GetOnlinePlayerCount(void);
    s32 GetOnlinePlayerTotal(void);
    s32 Ov010_GetWebPlayerEntry(s32, s32 *);
    s32 GetOnlineLocalPlayerId(void);
    void MI_CpuCopy8(s32, void *, s32);
    extern s32 gOnlinePlayerCount;
    s32 entry[7];
    s32 total;
    s32 count;
    s32 i;
    u8 *node;

    if (func_ov010_02226738() != 5) {
        SetSpriteAnimation(list, 1);
        return;
    }

    gOnlinePlayerCount = GetOnlinePlayerCount();
    total = GetOnlinePlayerTotal();
    count = 0;
    i = 0;
    node = M2C_FIELD(list, u8 **, 0x34);

    for (; i < total; i++) {
        if (Ov010_GetWebPlayerEntry(i, entry) != 0 && entry[1] != GetOnlineLocalPlayerId()) {
            M2C_FIELD(node, s32 *, 0) = entry[0];
            M2C_FIELD(node, s32 *, 0x4) = entry[1];
            M2C_FIELD(node, s32 *, 0x8) = entry[2];
            M2C_FIELD(node, s32 *, 0xc) = entry[3];
            M2C_FIELD(node, s32 *, 0x30c) = entry[5];

            MI_CpuCopy8(entry[6], node + 0x10, entry[5]);
            node += 0x310;
            count++;
        }
    }

    *M2C_FIELD(list, s32 **, 0x40) = count;
}

/* Asks ov010 for a batch of the online players that are not collected yet,
 * bounded by the list's limit: the limit is clamped to the players that exist, the
 * batch starts at the list's count (clamped to the limit) and spans a random
 * number of the players left.  +0x40 of the list holds the count the answering
 * request fills in. */
void RequestOnlinePlayersUpToLimit(void *list) {
    s32 RandomIntRange(s32, s32);
    s32 SubmitWebGetRequest(s32, s32, s32, void *, void *);
    M2C_UNK SetSpriteAnimation(void *, s32);
    extern s32 gOnlinePlayerCount;
    s32 request[68];
    u32 limit;
    u32 start;
    s32 count;

    *M2C_FIELD(list, s32 **, 0x40) = 0;
    limit = M2C_FIELD(list, u32 *, LIST_LIMIT);
    start = M2C_FIELD(list, u32 *, LIST_COUNT);
    if (limit >= (u32)gOnlinePlayerCount) {
        limit = gOnlinePlayerCount;
    }
    if (limit < start) {
        start = limit;
    }
    count = RandomIntRange(0, limit - start) + 1;
    request[0] = 0x10; /* payload length in bytes */
    request[1] = 1;
    request[2] = start;
    request[3] = 0;
    request[4] = count;
    if (SubmitWebGetRequest(6, 0, 0xFF, request, list) != 0) {
        return;
    }
    SetSpriteAnimation(list, 1);
}

/* Creates an online-player list node over a caller-owned array of player
 * records: the list starts with *countPtr entries and may hold at most `limit`
 * of them.  The list keeps no id array, and every record it covers is marked
 * free (id -1) with no name data. */
void CreateOnlinePlayerListUpToLimitNode(void *records, s32 limit, s32 *countPtr, s32 owner) {
    void *CreateSpriteForOwner(void *, s32);
    extern s32 gOnlinePlayerListUpToLimitClass;
    extern s32 gOnlinePlayerListVtable;
    u32 base = (u32)records;
    void *node;
    u8 *rec;

    node = CreateSpriteForOwner(&gOnlinePlayerListUpToLimitClass, owner);
    if (node == NULL) {
        return;
    }
    M2C_FIELD(node, s32 **, LIST_VTABLE) = &gOnlinePlayerListVtable;
    M2C_FIELD(node, s32 *, LIST_FIRST) = (s32)records;
    M2C_FIELD(node, s32 *, LIST_COUNT) = *countPtr;
    M2C_FIELD(node, s32 *, LIST_LIMIT) = limit;
    M2C_FIELD(node, s32 *, LIST_CAPACITY) = (s32)countPtr;
    M2C_FIELD(node, s32 *, LIST_IDS) = 0;
    M2C_FIELD(node, s32 *, LIST_UNK48) = 0;

    for (rec = (u8 *)records; (u32)rec < base + M2C_FIELD(node, s32 *, LIST_COUNT) * PLAYER_REC_SIZE; rec += PLAYER_REC_SIZE) {
        M2C_FIELD(rec, s32 *, PLAYER_ID) = -1;
        M2C_FIELD(rec, s32 *, 0x8) = 0;
        M2C_FIELD(rec, s32 *, PLAYER_DATA_LEN) = 0;
    }
}

/* Builds the filtered list of entries from the overlay's state, skipping the excluded one. */
void func_020e3bf0(void *list) {
    s32 func_ov010_02226738(void);
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 GetOnlinePlayerCount(void);
    s32 GetOnlinePlayerTotal(void);
    s32 Ov010_GetWebPlayerEntry(s32, s32 *);
    s32 GetOnlineLocalPlayerId(void);
    void MI_CpuCopy8(s32, void *, s32);
    extern s32 gOnlinePlayerCount;
    s32 entry[7];
    s32 total;
    s32 count;
    s32 i;
    u8 *node;

    if (func_ov010_02226738() != 5) {
        SetSpriteAnimation(list, 1);
        return;
    }

    gOnlinePlayerCount = GetOnlinePlayerCount();
    total = GetOnlinePlayerTotal();
    count = 0;
    i = 0;
    node = M2C_FIELD(list, u8 **, 0x34);

    for (; i < total; i++) {
        if (Ov010_GetWebPlayerEntry(i, entry) != 0 && entry[1] != GetOnlineLocalPlayerId()) {
            M2C_FIELD(node, s32 *, 0) = entry[0];
            M2C_FIELD(node, s32 *, 0x4) = entry[1];
            M2C_FIELD(node, s32 *, 0x8) = entry[2];
            M2C_FIELD(node, s32 *, 0xc) = entry[3];
            M2C_FIELD(node, s32 *, 0x30c) = entry[5];

            MI_CpuCopy8(entry[6], node + 0x10, entry[5]);
            node += 0x310;
            count++;
        }
    }

    *M2C_FIELD(list, s32 **, 0x40) = count;
}

/* Asks ov010 for a random page of online players: from the entries already
 * collected on, a random number of the ones left, with the request's flag word
 * randomly chosen; the node moves on once the request is queued.  +0x40 of the
 * list holds the count the answering request fills in. */
void RequestRandomOnlinePlayers(void *list) {
    s32 NextRandomValue(void);
    s32 RandomIntRange(s32, s32);
    s32 SubmitWebGetRequest(s32, s32, s32, void *, void *);
    M2C_UNK SetSpriteAnimation(void *, s32);
    extern s32 gOnlinePlayerCount;
    s32 request[68];
    s32 count;
    u32 start;

    *M2C_FIELD(list, s32 **, 0x40) = 0;
    start = M2C_FIELD(list, u32 *, LIST_COUNT);
    if ((u32) gOnlinePlayerCount < start) {
        start = gOnlinePlayerCount;
    }
    count = RandomIntRange(0, gOnlinePlayerCount - start) + 1;
    request[0] = 0x10; /* payload length in bytes */
    request[1] = (NextRandomValue() & 1) == 0;
    request[2] = start;
    request[3] = 0;
    request[4] = count;
    if (SubmitWebGetRequest(6, 0, 0xFF, request, list) != 0) {
        return;
    }
    SetSpriteAnimation(list, 1);
}

/* Creates an online-player list node over a caller-owned array of player
 * records: the list starts with *countPtr entries and imposes no limit on them.
 * The list keeps no id array, and every record it covers is marked free (id -1)
 * with no name data. */
void CreateOnlinePlayerListNoLimitNode(void *records, s32 *countPtr, s32 owner) {
    void *CreateSpriteForOwner(void *, s32);
    extern s32 gOnlinePlayerListNoLimitClass;
    extern s32 gOnlinePlayerListVtable;
    u32 base = (u32)records;
    void *node;
    u8 *rec;

    node = CreateSpriteForOwner(&gOnlinePlayerListNoLimitClass, owner);
    if (node == NULL) {
        return;
    }
    M2C_FIELD(node, s32 **, LIST_VTABLE) = &gOnlinePlayerListVtable;
    M2C_FIELD(node, s32 *, LIST_FIRST) = (s32)records;
    M2C_FIELD(node, s32 *, LIST_COUNT) = *countPtr;
    M2C_FIELD(node, s32 *, LIST_LIMIT) = 0;
    M2C_FIELD(node, s32 *, LIST_CAPACITY) = (s32)countPtr;
    M2C_FIELD(node, s32 *, LIST_IDS) = 0;
    M2C_FIELD(node, s32 *, LIST_UNK48) = 0;

    for (rec = (u8 *)records; (u32)rec < base + M2C_FIELD(node, s32 *, LIST_COUNT) * PLAYER_REC_SIZE; rec += PLAYER_REC_SIZE) {
        M2C_FIELD(rec, s32 *, PLAYER_ID) = -1;
        M2C_FIELD(rec, s32 *, 0x8) = 0;
        M2C_FIELD(rec, s32 *, PLAYER_DATA_LEN) = 0;
    }
}

void func_020e3e04(void *arg0) {
    s32 func_ov010_02226738(void);
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 GetOnlinePlayerTotal(void);
    s32 Ov010_GetWebPlayerEntry(s32, s32 *);
    void MI_CpuCopy8(s32, void *, s32);
    s32 sp[7];
    s32 total;
    s32 count;
    s32 i;
    u8 *node_ptr;

    if (func_ov010_02226738() != 5) {
        SetSpriteAnimation(arg0, 1);
        return;
    }

    total = GetOnlinePlayerTotal();
    count = 0;
    node_ptr = M2C_FIELD(arg0, u8 **, 0x34);

    for (i = 0; i < total; i++) {
        if (Ov010_GetWebPlayerEntry(i, sp) != 0 && check_val(sp, arg0)) {
            M2C_FIELD(node_ptr, s32 *, 0) = sp[0];
            M2C_FIELD(node_ptr, s32 *, 0x4) = sp[1];
            M2C_FIELD(node_ptr, s32 *, 0x8) = sp[2];
            M2C_FIELD(node_ptr, s32 *, 0xc) = sp[3];
            M2C_FIELD(node_ptr, s32 *, 0x30c) = sp[5];

            MI_CpuCopy8(sp[6], node_ptr + 0x10, sp[5]);
            node_ptr += 0x310;
            count++;
        }
    }

    *M2C_FIELD(arg0, s32 **, 0x40) = count;
}

/* Submit the online-player list's collected ids to the server (web request kind 3):
 * the payload is {byte length 0x10C, flag 1, count + 1, 0} followed by the list's
 * 64-slot id array; the count-out slot is cleared for the answer, and a request that
 * could not be queued starts the list's waiting animation. */
void RequestOnlinePlayersByIds(void *list) {
    void MIi_CpuCopy32(s32, void *, s32);
    s32 SubmitWebGetRequest(s32, s32, s32, void *, void *);
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 request[68];
    s32 count;

    *M2C_FIELD(list, s32 **, LIST_CAPACITY) = 0;
    count = M2C_FIELD(list, s32 *, LIST_COUNT) + 1;
    request[0] = 0x10C;
    request[2] = count;
    request[3] = 0;
    request[1] = 1;
    MIi_CpuCopy32(M2C_FIELD(list, s32 *, LIST_IDS), &request[4], 0x100);
    if (SubmitWebGetRequest(3, 0, 0xFF, request, list) != 0) {
        return;
    }
    SetSpriteAnimation(list, 1);
}

/* Builds an online-player list node over a caller-owned array of `*countPtr`
 * player records: installs its type table, keeps the record array and the count
 * pointer, copies the caller's ids into a fresh 64-entry id array (unused entries
 * zero) and marks every record free (id -1) with no name data.  Returns the node,
 * or NULL when the sprite cannot be created. */
void *CreateOnlinePlayerListWithIdsNode(s32 ids, void *records, s32 *countPtr, s32 owner) {
    void *CreateSpriteForOwner(void *, s32);
    s32 func_020e34f4(s32);
    void MIi_CpuCopy32(s32, void *, s32);
    void CpuFill(s32, s32, s32);
    extern s32 gOnlinePlayerListWithIdsClass;
    extern s32 gOnlinePlayerListVtable;
    void *node;
    s32 count;
    u32 base = (u32)records;
    u8 *rec;

    node = CreateSpriteForOwner(&gOnlinePlayerListWithIdsClass, owner);
    if (node != NULL) {
        M2C_FIELD(node, s32 **, LIST_VTABLE) = &gOnlinePlayerListVtable;
        M2C_FIELD(node, s32 *, LIST_FIRST) = (s32)records;
        M2C_FIELD(node, s32 *, LIST_COUNT) = *countPtr;
        M2C_FIELD(node, s32 *, LIST_LIMIT) = 0;
        M2C_FIELD(node, s32 *, LIST_CAPACITY) = (s32)countPtr;
        M2C_FIELD(node, s32 *, LIST_IDS) = func_020e34f4(0x100);
        M2C_FIELD(node, s32 *, LIST_UNK48) = 0;
        MIi_CpuCopy32(ids, (void *)M2C_FIELD(node, s32 *, LIST_IDS), M2C_FIELD(node, s32 *, LIST_COUNT) * 4);
        count = M2C_FIELD(node, s32 *, LIST_COUNT);
        CpuFill(0, M2C_FIELD(node, s32 *, LIST_IDS) + count * 4, (LIST_ID_SLOTS - count) * 4);
        for (rec = (u8 *)records; (u32)rec < base + M2C_FIELD(node, s32 *, LIST_COUNT) * PLAYER_REC_SIZE; rec += PLAYER_REC_SIZE) {
            M2C_FIELD(rec, s32 *, PLAYER_ID) = -1;
            M2C_FIELD(rec, s32 *, 0x8) = 0;
            M2C_FIELD(rec, s32 *, PLAYER_DATA_LEN) = 0;
        }
    }
    return node;
}

void func_020e4064(void *arg0) {
 M2C_UNK SetSpriteAnimation(void *, s32);
 s32 func_ov010_02226738(void);
 if (func_ov010_02226738() == 5) {
  *M2C_FIELD(arg0, s32 **, 0x40) = 1;
 } else {
  SetSpriteAnimation(arg0, 1);
 }
}

void func_020e4090(void *arg0) {
    s32 func_ov010_022266c4(M2C_UNK, s32, M2C_UNK, s32, void *);
    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    if (func_ov010_022266c4(8, *M2C_FIELD(arg0, s32 **, 0x44), 0, M2C_FIELD(arg0, s32 *, 0x48), arg0) != 0) {
        return;
    }
    SetSpriteAnimation(arg0, 1);
}

/* Twin of CreateOnlinePlayerIdListNode over the other id-list sprite bank (the one
 * whose nodes also carry the extra slot handlers): allocate the sprite node,
 * install the player-list vtable, keep one id (a copy of `id`) in a fresh
 * 0x100-byte id array whose rest is cleared, keep `flags` at +0x48 and the
 * caller's result slot at +0x40, and leave the list with no player records.
 * The caller uses it for the last id it requests.  Returns the node, or NULL when
 * the sprite cannot be created. */
void *func_020e40e0(s32 id, s32 flags, s32 result, s32 owner) {
    void *CreateSpriteForOwner(void *, s32);
    s32 func_020e34f4(s32);
    void MIi_CpuCopy32(s32, void *, s32);
    void CpuFill(s32, s32, s32);
    extern s32 data_0212d8a8;
    extern s32 gOnlinePlayerListVtable;
    void *node;
    s32 idCopy;
    s32 count;

    node = CreateSpriteForOwner(&data_0212d8a8, owner);
    if (node != NULL) {
        idCopy = id;
        M2C_FIELD(node, s32 **, LIST_VTABLE) = &gOnlinePlayerListVtable;
        M2C_FIELD(node, s32 *, LIST_FIRST) = 0;
        M2C_FIELD(node, s32 *, LIST_COUNT) = 1;
        M2C_FIELD(node, s32 *, 0x40) = result;
        M2C_FIELD(node, s32 *, LIST_IDS) = func_020e34f4(0x100);
        M2C_FIELD(node, s32 *, LIST_UNK48) = flags;
        MIi_CpuCopy32((s32) &idCopy, (void *) M2C_FIELD(node, s32 *, LIST_IDS), M2C_FIELD(node, s32 *, LIST_COUNT) * 4);
        count = M2C_FIELD(node, s32 *, LIST_COUNT);
        CpuFill(0, M2C_FIELD(node, s32 *, LIST_IDS) + count * 4, (0x40 - count) * 4);
    }
    return node;
}

/* Create an online-player id-list node: allocate the sprite node, install the
 * player-list vtable, keep one id (a copy of `id`) in a fresh 0x100-byte id array
 * whose rest is cleared, keep `flags` at +0x48 and the caller's result slot at
 * +0x40, and leave the list with no player records.  Returns the node, or NULL
 * when the sprite cannot be created. */
void *CreateOnlinePlayerIdListNode(s32 id, s32 flags, s32 result, s32 owner) {
    void *CreateSpriteForOwner(void *, s32);
    s32 func_020e34f4(s32);
    void MIi_CpuCopy32(s32, void *, s32);
    void CpuFill(s32, s32, s32);
    extern s32 data_0212d7d8;
    extern s32 gOnlinePlayerListVtable;
    void *node;
    s32 idCopy;
    s32 count;

    node = CreateSpriteForOwner(&data_0212d7d8, owner);
    if (node != NULL) {
        idCopy = id;
        M2C_FIELD(node, s32 **, LIST_VTABLE) = &gOnlinePlayerListVtable;
        M2C_FIELD(node, s32 *, LIST_FIRST) = 0;
        M2C_FIELD(node, s32 *, LIST_COUNT) = 1;
        M2C_FIELD(node, s32 *, 0x40) = result;
        M2C_FIELD(node, s32 *, LIST_IDS) = func_020e34f4(0x100);
        M2C_FIELD(node, s32 *, LIST_UNK48) = flags;
        MIi_CpuCopy32((s32) &idCopy, (void *) M2C_FIELD(node, s32 *, LIST_IDS), M2C_FIELD(node, s32 *, LIST_COUNT) * 4);
        count = M2C_FIELD(node, s32 *, LIST_COUNT);
        CpuFill(0, M2C_FIELD(node, s32 *, LIST_IDS) + count * 4, (0x40 - count) * 4);
    }
    return node;
}

void func_020e4208(void *arg0) {
    s32 func_ov010_02226738(void);
    s32 GetOnlinePlayerCount(void);
    M2C_UNK SetSpriteAnimation(void *, s32);
    extern s32 gOnlinePlayerCount;

    if (func_ov010_02226738() != 5) {
        SetSpriteAnimation(arg0, 1);
        return;
    }
    gOnlinePlayerCount = GetOnlinePlayerCount();
}

/* Online player list refresh handler: when the server already told us how many
 * players are online (gOnlinePlayerCount >= 0) there is nothing to ask for, so the
 * list just keeps animating; otherwise ask the server for that total (web request
 * kind 1, payload {byte length 12, flag 1, count 1, 0}) and animate the list when
 * the request cannot be queued.  A queued request leaves the list waiting. */
void RequestOnlinePlayerCount(void *list) {
    s32 SubmitWebGetRequest(s32, s32, s32, void *, void *);
    M2C_UNK SetSpriteAnimation(void *, s32);
    extern s32 gOnlinePlayerCount;
    s32 request[68];

    if (gOnlinePlayerCount >= 0) {
        SetSpriteAnimation(list, 1);
        return;
    }

    request[0] = 0xC; /* payload length in bytes */
    request[1] = 1;
    request[2] = 1;
    request[3] = 0;

    if (SubmitWebGetRequest(1, 0, 0xFF, request, list) != 0) {
        return;
    }

    SetSpriteAnimation(list, 1);
}

void func_020e42bc(s32 arg0) {
    void *CreateSpriteForOwner(void *, s32);
    extern s32 data_0212d748;
    extern s32 gOnlinePlayerListVtable;
    void *temp_r0;

    temp_r0 = CreateSpriteForOwner(&data_0212d748, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, s32 **, 0) = &gOnlinePlayerListVtable;
    M2C_FIELD(temp_r0, s32 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x3c) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x44) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
}

void func_020e4304(void) {
    extern s32 gOnlinePlayerCount;
    gOnlinePlayerCount = -1;
}

void *func_020e4318(void *arg0) {
    void MemFree(void *);
    extern M2C_UNK gOnlinePlayerListVtable;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &gOnlinePlayerListVtable;
    if (M2C_FIELD(arg0, s32 *, 0x44) != 0) {
        HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x44));
    }
    MemFree(arg0);
    return arg0;
}

void *func_020e434c(void *arg0) {
    void HeapFreeBlock();
    extern M2C_UNK gOnlinePlayerListVtable;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &gOnlinePlayerListVtable;
    if (M2C_FIELD(arg0, s32 *, 0x44) != 0) {
        HeapFreeBlock();
    }
    return arg0;
}

/* Initialize graphics: clear VRAM, OAM and palettes, then enable the caches. */
#pragma opt_propagation off
void func_020e4378(void) {
    M2C_UNK func_020022d8();
    M2C_UNK GX_InitDisplay();
    M2C_UNK func_02002490();
    M2C_UNK func_02003104(s32);
    M2C_UNK func_020035f8();
    M2C_UNK func_02006858();
    M2C_UNK func_02006c58();
    M2C_UNK func_02006c6c();
    M2C_UNK func_02006c7c();
    M2C_UNK InitSystemTick();
    M2C_UNK func_02007140();
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, M2C_UNK);
    M2C_UNK Arm7CommandInit();
    extern s32 gGxDmaChannel;
    u16 *p;
    u16 *q;
    func_02006c58();
    func_02006858();
    InitSystemTick();
    func_02007140();
    func_020022d8();
    gGxDmaChannel = -1;
    GX_InitDisplay();
    func_02002490();
    *(s32 *)0x04001000 &= ~0x10000;
    Arm7CommandInit();
    func_02003104(0x1FF);
    MI_CpuFill32(0, 0x6800000, 0xA4000);
    func_020035f8();
    MI_CpuFill32(0xC0, 0x7000000, 0x400);
    MI_CpuFill32(0, 0x5000000, 0x400);
    MI_CpuFill32(0xC0, 0x7000400, 0x400);
    MI_CpuFill32(0, 0x5000400, 0x400);
    p = (u16 *)0x04000204;
    q = p + 0x80;
    p[0] |= 0x8000;
    q[0] &= ~0x8000;
    func_02006c6c();
    func_02006c7c();
}
#pragma opt_propagation reset
void func_020e4458(void) {
    M2C_UNK GX_SetVBlankIrq(M2C_UNK, u16);
    M2C_UNK OS_SetIrqHandler(M2C_UNK, M2C_UNK *);
    M2C_UNK OS_EnableIrqMask(M2C_UNK);
    extern M2C_UNK VBlankHandler;
    u16 temp_r1;

    OS_SetIrqHandler(1, &VBlankHandler);
    OS_EnableIrqMask(1);
    temp_r1 = *(u16 *)0x04000208;
    *(u16 *)0x04000208 = 1;
    GX_SetVBlankIrq(1, temp_r1);
}

