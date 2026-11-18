/* 37 functions from 0x020E34BC to 0x020E4490 (main), found by ds-decomp. */
#include "common.h"

/* A list node in the online player screen: its type table, the capacity of the
 * player array and the entries collected so far.  Each player record is 0x310
 * bytes (id, name, ... data size at +0x30C). */
#define LIST_VTABLE    0x00 /* s32 *type table */
#define LIST_FIRST     0x34 /* void *first player record */
#define LIST_COUNT     0x38 /* s32 number of players collected */
#define LIST_LIMIT     0x3C /* s32 most players the list may hold */
#define LIST_CAPACITY  0x40 /* s32 capacity the list was created with */
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
extern s32 data_02168fe4;
register s32 result;
volatile u32 saved;
u32 temp=*(volatile u16*)0x04000208;
*(volatile u16*)0x04000208=0;
saved=temp;
result=func_0202a468(data_02168fe4,arg0,-arg1);
temp=saved;
(void)*(volatile u16*)0x04000208;
*(volatile u16*)0x04000208=temp;
return result;
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
    s32 func_0208471c();
    s32 func_0208477c();
    s32 func_ov010_02226364();
    if ((func_0208471c() != 0) || (func_0208477c() != 0)) {
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
    if ((func_0208471c() != 0) || (func_0208477c() != 0)) {
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
    if ((func_0208471c() != 0) || (func_0208477c() != 0)) {
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
 extern s32 data_0212da10;
 void *temp_r0;
 temp_r0 = CreateSpriteForOwner(&data_0212d950, arg3);
 if (temp_r0 == NULL) return;
 M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
 M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
 M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
 M2C_FIELD(temp_r0, s32 *, 0x3c) = 0;
 M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
 M2C_FIELD(temp_r0, s32 *, 0x44) = 0;
 M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
}

void func_020e37dc(void *arg0) {
    s32 func_ov010_02226738(void);
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 func_ov010_022267b0(s32, s32 *);
    void MI_CpuCopy8(s32, void *, s32);
    s32 sp[7];
    void *temp_r4;

    if (func_ov010_02226738() != 5) {
        SetSpriteAnimation(arg0, 1);
        return;
    }

    temp_r4 = M2C_FIELD(arg0, void **, 0x34);
    if (func_ov010_022267b0(0, sp) == 0) {
        return;
    }

    M2C_FIELD(temp_r4, s32 *, 0) = sp[0];
    M2C_FIELD(temp_r4, s32 *, 0x4) = sp[1];
    M2C_FIELD(temp_r4, s32 *, 0x8) = sp[2];
    M2C_FIELD(temp_r4, s32 *, 0xc) = sp[3];
    M2C_FIELD(temp_r4, s32 *, 0x30c) = sp[5];

    MI_CpuCopy8(sp[6], (u8 *)temp_r4 + 0x10, sp[5]);

    *M2C_FIELD(arg0, s32 **, 0x40) = 1;
}

void func_020e3870(void *arg0) {
    void func_02007e70(s32, void *, s32);
    s32 func_ov010_02226538(s32, s32, s32, void *, void *);
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 sp[68];
    s32 val;

    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    val = M2C_FIELD(arg0, s32 *, 0x38) + 1;
    sp[0] = 0x10C;
    sp[2] = val;
    sp[3] = 0;
    sp[1] = 1;
    func_02007e70(M2C_FIELD(arg0, s32 *, 0x44), &sp[4], 0x100);
    if (func_ov010_02226538(3, 0, 0xFF, sp, arg0) != 0) {
        return;
    }
    SetSpriteAnimation(arg0, 1);
}

/* Build a list node for `capacity` online players: install its type table, keep
 * the record array and the id slot, take an id array of LIST_ID_SLOTS entries
 * from the heap, store the local player's id in it (the rest zero), and clear
 * every player record in the array.  Returns the node, or NULL on failure. */
void *CreateOnlinePlayerListNode(void *records, s32 unk34, s32 capacity) {
    void *CreateSpriteForOwner(void *, s32);
    s32 func_020e34f4(s32);
    s32 GetOnlineLocalPlayerId(void);
    void func_02007e70(s32, void *, s32);
    void CpuFill(s32, s32, s32);
    extern s32 data_0212d870;
    extern s32 data_0212da10;
    u32 end = (u32)records;
    void *node;
    s32 playerId;
    s32 count;
    u8 *rec;

    node = CreateSpriteForOwner(&data_0212d870, capacity);
    if (node != NULL) {
        M2C_FIELD(node, s32 **, LIST_VTABLE) = &data_0212da10;
        M2C_FIELD(node, s32 *, LIST_FIRST) = (s32)records;
        M2C_FIELD(node, s32 *, LIST_COUNT) = 1;
        M2C_FIELD(node, s32 *, LIST_LIMIT) = 0;
        M2C_FIELD(node, s32 *, LIST_CAPACITY) = unk34;
        M2C_FIELD(node, s32 *, LIST_IDS) = func_020e34f4(0x100);
        M2C_FIELD(node, s32 *, LIST_UNK48) = 0;
        playerId = GetOnlineLocalPlayerId();
        func_02007e70((s32)&playerId, (void *)M2C_FIELD(node, s32 *, LIST_IDS), M2C_FIELD(node, s32 *, LIST_COUNT) * 4);
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
    s32 func_ov010_0222681c(void);
    s32 func_ov010_02226744(void);
    s32 func_ov010_022267b0(s32, s32 *);
    s32 GetOnlineLocalPlayerId(void);
    void MI_CpuCopy8(s32, void *, s32);
    extern s32 data_0212d744;
    s32 entry[7];
    s32 total;
    s32 count;
    s32 i;
    u8 *node;

    if (func_ov010_02226738() != 5) {
        SetSpriteAnimation(list, 1);
        return;
    }

    data_0212d744 = func_ov010_0222681c();
    total = func_ov010_02226744();
    count = 0;
    i = 0;
    node = M2C_FIELD(list, u8 **, 0x34);

    for (; i < total; i++) {
        if (func_ov010_022267b0(i, entry) != 0 && entry[1] != GetOnlineLocalPlayerId()) {
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

void func_020e3ab4(void *arg0) {
    s32 RandomIntRange(s32, s32);
    s32 func_ov010_02226538(s32, s32, s32, void *, void *);
    M2C_UNK SetSpriteAnimation(void *, s32);
    extern s32 data_0212d744;
    s32 sp[68];
    u32 r1;
    u32 r5;
    s32 temp;

    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    r1 = M2C_FIELD(arg0, u32 *, 0x3C);
    r5 = M2C_FIELD(arg0, u32 *, 0x38);
    if (r1 >= (u32)data_0212d744) {
        r1 = data_0212d744;
    }
    if (r1 < r5) {
        r5 = r1;
    }
    temp = RandomIntRange(0, r1 - r5) + 1;
    sp[0] = 0x10;
    sp[1] = 1;
    sp[2] = r5;
    sp[3] = 0;
    sp[4] = temp;
    if (func_ov010_02226538(6, 0, 0xFF, sp, arg0) != 0) {
        return;
    }
    SetSpriteAnimation(arg0, 1);
}

void func_020e3b54(void *arg0, s32 arg1, s32 *arg2, s32 arg3) {
    void *CreateSpriteForOwner(void *, s32);
    extern s32 data_0212d988;
    extern s32 data_0212da10;
    u32 base = (u32)arg0;
    void *temp_r0;
    u8 *ptr;

    temp_r0 = CreateSpriteForOwner(&data_0212d988, arg3);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
    M2C_FIELD(temp_r0, s32 *, 0x34) = (s32)arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = *arg2;
    M2C_FIELD(temp_r0, s32 *, 0x3c) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x40) = (s32)arg2;
    M2C_FIELD(temp_r0, s32 *, 0x44) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;

    for (ptr = (u8 *)arg0; (u32)ptr < base + M2C_FIELD(temp_r0, s32 *, 0x38) * 0x310; ptr += 0x310) {
        M2C_FIELD(ptr, s32 *, 0x4) = -1;
        M2C_FIELD(ptr, s32 *, 0x8) = 0;
        M2C_FIELD(ptr, s32 *, 0x30c) = 0;
    }
}

/* Builds the filtered list of entries from the overlay's state, skipping the excluded one. */
void func_020e3bf0(void *list) {
    s32 func_ov010_02226738(void);
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 func_ov010_0222681c(void);
    s32 func_ov010_02226744(void);
    s32 func_ov010_022267b0(s32, s32 *);
    s32 GetOnlineLocalPlayerId(void);
    void MI_CpuCopy8(s32, void *, s32);
    extern s32 data_0212d744;
    s32 entry[7];
    s32 total;
    s32 count;
    s32 i;
    u8 *node;

    if (func_ov010_02226738() != 5) {
        SetSpriteAnimation(list, 1);
        return;
    }

    data_0212d744 = func_ov010_0222681c();
    total = func_ov010_02226744();
    count = 0;
    i = 0;
    node = M2C_FIELD(list, u8 **, 0x34);

    for (; i < total; i++) {
        if (func_ov010_022267b0(i, entry) != 0 && entry[1] != GetOnlineLocalPlayerId()) {
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

void func_020e3ccc(void *arg0) {
    s32 NextRandomValue(void);
    s32 RandomIntRange(s32, s32);
    s32 func_ov010_02226538(s32, s32, s32, void *, void *);
    M2C_UNK SetSpriteAnimation(void *, s32);
    extern s32 data_0212d744;
    s32 sp[68];
    s32 temp5;
    u32 r6;

    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    r6 = M2C_FIELD(arg0, u32 *, 0x38);
    if ((u32)data_0212d744 < r6) {
        r6 = data_0212d744;
    }
    temp5 = RandomIntRange(0, data_0212d744 - r6) + 1;
    sp[0] = 0x10;
    sp[1] = (NextRandomValue() & 1) == 0;
    sp[2] = r6;
    sp[3] = 0;
    sp[4] = temp5;
    if (func_ov010_02226538(6, 0, 0xFF, sp, arg0) != 0) {
        return;
    }
    SetSpriteAnimation(arg0, 1);
}

void func_020e3d6c(void *arg0, s32 *arg1, s32 arg2) {
void *CreateSpriteForOwner(void *,s32);
extern s32 data_0212d9c8;extern s32 data_0212da10;
u32 base=(u32)arg0;
void *p;u8 *ptr;
p=CreateSpriteForOwner(&data_0212d9c8,arg2);
if(!p)return;
M2C_FIELD(p,s32 **,0)=&data_0212da10;
M2C_FIELD(p,s32 *,0x34)=(s32)arg0;
M2C_FIELD(p,s32 *,0x38)=*arg1;
M2C_FIELD(p,s32 *,0x3c)=0;
M2C_FIELD(p,s32 *,0x40)=(s32)arg1;
M2C_FIELD(p,s32 *,0x44)=0;
M2C_FIELD(p,s32 *,0x48)=0;
for(ptr=arg0;(u32)ptr<base+M2C_FIELD(p,s32 *,0x38)*0x310;ptr+=0x310){
M2C_FIELD(ptr,s32 *,4)=-1;
M2C_FIELD(ptr,s32 *,8)=0;
M2C_FIELD(ptr,s32 *,0x30c)=0;
}
}

void func_020e3e04(void *arg0) {
    s32 func_ov010_02226738(void);
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 func_ov010_02226744(void);
    s32 func_ov010_022267b0(s32, s32 *);
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

    total = func_ov010_02226744();
    count = 0;
    node_ptr = M2C_FIELD(arg0, u8 **, 0x34);

    for (i = 0; i < total; i++) {
        if (func_ov010_022267b0(i, sp) != 0 && check_val(arg0, sp)) {
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

void func_020e3f08(void *arg0) {
    void func_02007e70(s32, void *, s32);
    s32 func_ov010_02226538(s32, s32, s32, void *, void *);
    M2C_UNK SetSpriteAnimation(void *, s32);
    s32 sp[68];
    s32 val;

    *M2C_FIELD(arg0, s32 **, 0x40) = 0;
    val = M2C_FIELD(arg0, s32 *, 0x38) + 1;
    sp[0] = 0x10C;
    sp[2] = val;
    sp[3] = 0;
    sp[1] = 1;
    func_02007e70(M2C_FIELD(arg0, s32 *, 0x44), &sp[4], 0x100);
    if (func_ov010_02226538(3, 0, 0xFF, sp, arg0) != 0) {
        return;
    }
    SetSpriteAnimation(arg0, 1);
}

void *func_020e3f88(s32 arg0, void *arg1, s32 *arg2, s32 arg3) {
    void *CreateSpriteForOwner(void *, s32);
    s32 func_020e34f4(s32);
    void func_02007e70(s32, void *, s32);
    void CpuFill(s32, s32, s32);
    extern s32 data_0212d838;
    extern s32 data_0212da10;
    void *temp_r0;
    s32 temp_r2;
    register u8 *ptr;

    temp_r0 = CreateSpriteForOwner(&data_0212d838, arg3);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
        M2C_FIELD(temp_r0, s32 *, 0x34) = (s32)arg1;
        M2C_FIELD(temp_r0, s32 *, 0x38) = *arg2;
        M2C_FIELD(temp_r0, s32 *, 0x3c) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x40) = (s32)arg2;
        M2C_FIELD(temp_r0, s32 *, 0x44) = func_020e34f4(0x100);
        M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
        func_02007e70(arg0, (void *)M2C_FIELD(temp_r0, s32 *, 0x44), M2C_FIELD(temp_r0, s32 *, 0x38) * 4);
        temp_r2 = M2C_FIELD(temp_r0, s32 *, 0x38);
        CpuFill(0, M2C_FIELD(temp_r0, s32 *, 0x44) + temp_r2 * 4, (0x40 - temp_r2) * 4);
        for (ptr = (u8 *)arg1; (u32)ptr < (u32)arg1 + M2C_FIELD(temp_r0, s32 *, 0x38) * 0x310; ptr += 0x310) {
            M2C_FIELD(ptr, s32 *, 0x4) = -1;
            M2C_FIELD(ptr, s32 *, 0x8) = 0;
            M2C_FIELD(ptr, s32 *, 0x30c) = 0;
        }
    }
    return temp_r0;
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

void *func_020e40e0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *CreateSpriteForOwner(void *, s32);
    s32 func_020e34f4(s32);
    void func_02007e70(s32, void *, s32);
    void CpuFill(s32, s32, s32);
    extern s32 data_0212d8a8;
    extern s32 data_0212da10;
    void *temp_r0;
    s32 sp0;
    s32 temp_r2;

    temp_r0 = CreateSpriteForOwner(&data_0212d8a8, arg3);
    if (temp_r0 != NULL) {
        sp0 = arg0;
        M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
        M2C_FIELD(temp_r0, s32 *, 0x34) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x38) = 1;
        M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
        M2C_FIELD(temp_r0, s32 *, 0x44) = func_020e34f4(0x100);
        M2C_FIELD(temp_r0, s32 *, 0x48) = arg1;
        func_02007e70((s32)&sp0, (void *)M2C_FIELD(temp_r0, s32 *, 0x44), M2C_FIELD(temp_r0, s32 *, 0x38) * 4);
        temp_r2 = M2C_FIELD(temp_r0, s32 *, 0x38);
        CpuFill(0, M2C_FIELD(temp_r0, s32 *, 0x44) + temp_r2 * 4, (0x40 - temp_r2) * 4);
    }
    return temp_r0;
}

void *func_020e4174(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *CreateSpriteForOwner(void *, s32);
    s32 func_020e34f4(s32);
    void func_02007e70(s32, void *, s32);
    void CpuFill(s32, s32, s32);
    extern s32 data_0212d7d8;
    extern s32 data_0212da10;
    void *temp_r0;
    s32 sp0;
    s32 temp_r2;

    temp_r0 = CreateSpriteForOwner(&data_0212d7d8, arg3);
    if (temp_r0 != NULL) {
        sp0 = arg0;
        M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
        M2C_FIELD(temp_r0, s32 *, 0x34) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x38) = 1;
        M2C_FIELD(temp_r0, s32 *, 0x40) = arg2;
        M2C_FIELD(temp_r0, s32 *, 0x44) = func_020e34f4(0x100);
        M2C_FIELD(temp_r0, s32 *, 0x48) = arg1;
        func_02007e70((s32)&sp0, (void *)M2C_FIELD(temp_r0, s32 *, 0x44), M2C_FIELD(temp_r0, s32 *, 0x38) * 4);
        temp_r2 = M2C_FIELD(temp_r0, s32 *, 0x38);
        CpuFill(0, M2C_FIELD(temp_r0, s32 *, 0x44) + temp_r2 * 4, (0x40 - temp_r2) * 4);
    }
    return temp_r0;
}

void func_020e4208(void *arg0) {
    s32 func_ov010_02226738(void);
    s32 func_ov010_0222681c(void);
    M2C_UNK SetSpriteAnimation(void *, s32);
    extern s32 data_0212d744;

    if (func_ov010_02226738() != 5) {
        SetSpriteAnimation(arg0, 1);
        return;
    }
    data_0212d744 = func_ov010_0222681c();
}

void func_020e4240(void *arg0) {
    s32 func_ov010_02226538(s32, s32, s32, void *, void *);
    M2C_UNK SetSpriteAnimation(void *, s32);
    extern s32 data_0212d744;
    s32 sp[68];

    if (data_0212d744 >= 0) {
        SetSpriteAnimation(arg0, 1);
        return;
    }

    sp[0] = 0xC;
    sp[1] = 1;
    sp[2] = 1;
    sp[3] = 0;

    if (func_ov010_02226538(1, 0, 0xFF, sp, arg0) != 0) {
        return;
    }

    SetSpriteAnimation(arg0, 1);
}

void func_020e42bc(s32 arg0) {
    void *CreateSpriteForOwner(void *, s32);
    extern s32 data_0212d748;
    extern s32 data_0212da10;
    void *temp_r0;

    temp_r0 = CreateSpriteForOwner(&data_0212d748, arg0);
    if (temp_r0 == NULL) {
        return;
    }
    M2C_FIELD(temp_r0, s32 **, 0) = &data_0212da10;
    M2C_FIELD(temp_r0, s32 *, 0x34) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x3c) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x40) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x44) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x48) = 0;
}

void func_020e4304(void) {
    extern s32 data_0212d744;
    data_0212d744 = -1;
}

void *func_020e4318(void *arg0) {
    void MemFree(void *);
    extern M2C_UNK data_0212da10;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_0212da10;
    if (M2C_FIELD(arg0, s32 *, 0x44) != 0) {
        HeapFreeBlock(M2C_FIELD(arg0, s32 *, 0x44));
    }
    MemFree(arg0);
    return arg0;
}

void *func_020e434c(void *arg0) {
    void HeapFreeBlock();
    extern M2C_UNK data_0212da10;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_0212da10;
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
    M2C_UNK func_02006f14();
    M2C_UNK func_02007140();
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, M2C_UNK);
    M2C_UNK Arm7CommandInit();
    extern s32 data_020f5204;
    u16 *p;
    u16 *q;
    func_02006c58();
    func_02006858();
    func_02006f14();
    func_02007140();
    func_020022d8();
    data_020f5204 = -1;
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
    M2C_UNK OS_SetFifoReceiveHandlers(M2C_UNK, M2C_UNK *);
    M2C_UNK OS_EnableIrqMask(M2C_UNK);
    extern M2C_UNK func_020e4688;
    u16 temp_r1;

    OS_SetFifoReceiveHandlers(1, &func_020e4688);
    OS_EnableIrqMask(1);
    temp_r1 = *(u16 *)0x04000208;
    *(u16 *)0x04000208 = 1;
    GX_SetVBlankIrq(1, temp_r1);
}

