/* 18 functions from 0x0218C228 to 0x0218C9B4 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
typedef struct RuntimeRangeNode { struct RuntimeRangeNode *prev, *next; u16 start, size; } RuntimeRangeNode;
typedef struct { u8 pad[0x180]; RuntimeRangeNode head, tail; s32 unk198, heap; } RuntimeRangePool;
typedef struct { s32 a; u8 pad[4]; s32 b; u8 rest[52]; } RuntimePair64;

#pragma scheduling off
RuntimeRangeNode *func_ov001_0218c228(s32 n,s32 size,s32 forward,s32 *out) {
s32 Ov001_QueuePop(s32);
s32 OS_DisableIrqMask(s32);
void OS_EnableIrqMask(s32);
void SystemHalt(void);
void Ov001_ListInsertBefore(void *,void *);
extern s32 gOv001TilePools;
RuntimeRangeNode *node,*p;
s32 old,units;
node=(RuntimeRangeNode *)Ov001_QueuePop(M2C_FIELD(gOv001TilePools+n*0x1a0,s32 *,0x19c));
units=((size+3)&~3)>>2;
node->size=units;
old=OS_DisableIrqMask(1);
if(forward) {
p=&((RuntimeRangePool *)gOv001TilePools)[(u32)n].head;
if (p != &((RuntimeRangePool *)gOv001TilePools)[n].tail) {
do {
RuntimeRangeNode *next=p->next;
s32 pos=p->start+p->size;
if(pos+units<=next->start) {
node->start=pos;
Ov001_ListInsertBefore(next,node);
break;
}
p = next;
} while (p != (RuntimeRangeNode *)(gOv001TilePools+n*0x1a0+0x18c));
}
if(p==(RuntimeRangeNode *)(gOv001TilePools+n*0x1a0+0x18c)) SystemHalt();
} else {
p=&((RuntimeRangePool *)gOv001TilePools)[(u32)n].tail;
if (p != &((RuntimeRangePool *)gOv001TilePools)[n].head) {
do {
RuntimeRangeNode *prev=p->prev;
s32 pos=p->start-units;
if(pos>=prev->start+prev->size) {
node->start=pos;
Ov001_ListInsertBefore(p,node);
break;
}
p = prev;
} while (p != (RuntimeRangeNode *)(gOv001TilePools+n*0x1a0+0x180));
}
if(p==(RuntimeRangeNode *)(gOv001TilePools+n*0x1a0+0x180)) SystemHalt();
}
*out=node->start;
OS_EnableIrqMask(old);
return node;
}
#pragma scheduling reset
/* Return tile-range node `range` to the free-node queue of the screen pool it
 * came from (the second pool when it lies past the first 0x1A0-byte pool),
 * after unlinking it from that pool's in-use list. */
void Ov001_ReturnTileRangeNode(u32 range) {
    M2C_UNK Ov001_QueuePush(s32, u32);
    M2C_UNK Ov001_ListRemove();
    extern s32 gOv001TilePools;
    s32 pool;

    pool = 0;
    Ov001_ListRemove(range);
    if (range >= (u32) (gOv001TilePools + OV001_TILE_POOL_STRIDE)) {
        pool = 1;
    }
    Ov001_QueuePush(M2C_FIELD(((pool * OV001_TILE_POOL_STRIDE) + gOv001TilePools), s32 *, OV001_TILE_POOL_FREE_NODES), range);
}

/* Length of the NUL-terminated string `text` without its terminator, capped at
 * `maxLength` bytes (returns maxLength when the buffer is not terminated). */
s32 StringLengthUpTo(u8 *text, s32 maxLength) {
    s32 length;

    for (length = 0; length < maxLength; length++)
        if (!text[length]) break;
    return length;
}

/* VRAM init pass 1: release the bank grant every VRAM allocator is holding and
 * remember the banks each one gave back in gVramBankGrants, which the second
 * init pass hands to the matching allocator again.  Then assign the main
 * background banks and clear VRAM for the new display setup. */
void GxReleaseAllBankGrants(void) {
M2C_UNK GX_ReleaseBankGrantForBG(void);
M2C_UNK GX_ReleaseBankGrantForOBJ(void);
M2C_UNK GX_ReleaseBankGrantForBGExtPalette(void);
M2C_UNK GX_ReleaseBankGrantForObjExtPalette(void);
M2C_UNK GX_ReleaseBankGrantForTex(void);
M2C_UNK GX_ReleaseBankGrantForOBJExtPltt(void);
M2C_UNK GX_ReleaseBankGrantForTexExtPltt(void);
M2C_UNK GX_ReleaseBankGrantForSubBG(void);
M2C_UNK GX_ReleaseBankGrantForSubOBJ(void);
M2C_UNK GX_ReleaseBankGrantForBGExtPlttSub(void);
M2C_UNK GX_ReleaseBankGrantForOBJExtPlttSub(void);
M2C_UNK GX_ReleaseBankGrantForObjCD(void);
M2C_UNK GX_ReleaseBankGrantForAll(void);
void GX_SetBankForObjCD(s32);
void GxClearDisplayMemory();
extern s32 gVramBankGrants[];
gVramBankGrants[0]=GX_ReleaseBankGrantForBG();
gVramBankGrants[1]=GX_ReleaseBankGrantForOBJ();
gVramBankGrants[2]=GX_ReleaseBankGrantForBGExtPalette();
gVramBankGrants[3]=GX_ReleaseBankGrantForObjExtPalette();
gVramBankGrants[4]=GX_ReleaseBankGrantForTex();
gVramBankGrants[5]=GX_ReleaseBankGrantForOBJExtPltt();
gVramBankGrants[6]=GX_ReleaseBankGrantForTexExtPltt();
gVramBankGrants[7]=GX_ReleaseBankGrantForSubBG();
gVramBankGrants[8]=GX_ReleaseBankGrantForSubOBJ();
gVramBankGrants[9]=GX_ReleaseBankGrantForBGExtPlttSub();
gVramBankGrants[10]=GX_ReleaseBankGrantForOBJExtPlttSub();
gVramBankGrants[11]=GX_ReleaseBankGrantForObjCD();
gVramBankGrants[12]=GX_ReleaseBankGrantForAll();
GX_SetBankForObjCD(gVramBankGrants[11]);
GxClearDisplayMemory();
return;
}

/* System init pass 2: invoke NitroSDK startup hooks from gVramBankGrants,
   plus a timing/sync hook, then clear VCOUNT/IRQ mask regs before enabling
   something via SetLcdEnabled(1). */
#pragma opt_global_reg_alloc off
void func_ov001_0218c4c0(void) {
    extern s32 gVramBankGrants[];
    s32 GX_ReleaseBankGrantForBG(void);
    s32 GX_ReleaseBankGrantForOBJ(void);
    s32 GX_ReleaseBankGrantForSubBG(void);
    s32 GX_ReleaseBankGrantForSubOBJ(void);
    void GxClearDisplayMemory(void);
    void SetLcdEnabled(s32);
    void GX_SetBankForBG(s32);
    void GX_SetBankForOBJ(s32);
    void GX_SetBankForBGExtPalette(s32);
    void GX_SetBankForObjExtPalette(s32);
    void GX_SetBankForTex(s32);
    void GX_SetBankForOBJExtPltt(s32);
    void GX_SetBankForTexExtPltt(s32);
    void GX_SetBankForSubBG(s32);
    void GX_SetBankForSubOBJ(s32);
    void GX_SetBankForBGExtPlttSub(s32);
    void GX_SetBankForOBJExtPlttSub(s32);
    s32 func_02003104(s32);

    GX_ReleaseBankGrantForBG();
    GX_ReleaseBankGrantForOBJ();
    GX_ReleaseBankGrantForSubBG();
    GX_ReleaseBankGrantForSubOBJ();
    GxClearDisplayMemory();
    GX_SetBankForBG(gVramBankGrants[0]);
    GX_SetBankForOBJ(gVramBankGrants[1]);
    GX_SetBankForBGExtPalette(gVramBankGrants[2]);
    GX_SetBankForObjExtPalette(gVramBankGrants[3]);
    GX_SetBankForTex(gVramBankGrants[4]);
    GX_SetBankForOBJExtPltt(gVramBankGrants[5]);
    GX_SetBankForTexExtPltt(gVramBankGrants[6]);
    GX_SetBankForSubBG(gVramBankGrants[7]);
    GX_SetBankForSubOBJ(gVramBankGrants[8]);
    GX_SetBankForBGExtPlttSub(gVramBankGrants[9]);
    GX_SetBankForOBJExtPlttSub(gVramBankGrants[10]);
    func_02003104(gVramBankGrants[12]);
    *(volatile u16 *)0x4000050 = 0;
    *(volatile u16 *)0x4001050 = 0;
    *(volatile u32 *)0x4000010 = 0;
    *(volatile u32 *)0x4000014 = 0;
    *(volatile u32 *)0x4000018 = 0;
    *(volatile u32 *)0x400001c = 0;
    *(volatile u32 *)0x4001010 = 0;
    *(volatile u32 *)0x4001014 = 0;
    *(volatile u32 *)0x4001018 = 0;
    *(volatile u32 *)0x400101c = 0;
    SetLcdEnabled(1);
}
#pragma opt_global_reg_alloc reset
/* Clear the display memory: release the background, extended-palette and OAM
 * VRAM banks, clear the main-engine background character/map VRAM and its
 * extended palettes, fill both engines' OAM areas with disabled entries and both
 * palettes with zero, then hand the released banks back to the allocator. */
void GxClearDisplayMemory(void) {
    M2C_UNK func_02003104(s32);
    M2C_UNK GX_ReleaseBankGrantForAll();
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, M2C_UNK);
    func_02003104(VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G | VRAM_BANK_H | VRAM_BANK_I);
    MI_CpuFill32(0, GX_MAIN_BG_VRAM_BASE, GX_MAIN_BG_VRAM_SIZE);
    MI_CpuFill32(0, GX_MAIN_BG_EXTPLTT_VRAM_BASE, GX_MAIN_BG_EXTPLTT_VRAM_SIZE);
    GX_ReleaseBankGrantForAll();
    MI_CpuFill32(GX_OAM_DISABLED, GX_MAIN_OBJ_OAM_BASE, GX_OAM_SIZE);
    MI_CpuFill32(0, GX_MAIN_PALETTE_BASE, GX_PALETTE_SIZE);
    MI_CpuFill32(GX_OAM_DISABLED, GX_SUB_OBJ_OAM_BASE, GX_OAM_SIZE);
    MI_CpuFill32(0, GX_SUB_PALETTE_BASE, GX_PALETTE_SIZE);
}

/* Front-end per-frame: read the ARM7's system value and, when the read succeeds and
 * the value is not already the front-end's, put the ARM7 back into front-end mode. */
void Ov001_UpdateArm7Value(void) {
    s32 Arm7ReadValueWait(s32 *);
    s32 value;

    if (Arm7ReadValueWait(&value) != 0) {
        return;
    }
    if (value == ARM7_SYSTEM_VALUE_FRONTEND) {
        return;
    }
    Arm7SetValueWait(ARM7_SYSTEM_VALUE_FRONTEND);
}

/* Put the ARM7's system value back to its default (1) while overlay 001 shuts
 * down, undoing the front-end value Ov001_UpdateArm7Value keeps it at. */
void Ov001_RestoreArm7SystemValue(void) {
    Arm7SetValueWait(ARM7_SYSTEM_VALUE_DEFAULT);
}

/* Task-group array behind the untyped gOv001Tasks slot; each access reloads
 * the global, as the helpers may replace it. */
#define OV001_TASKS ((Ov001Task *)gOv001Tasks)

void Ov001_InitTasks(void) {
    M2C_UNK Ov001_Alloc(s32, s32);
    M2C_UNK Ov001_QueueCreateFromRange(s32, s32, s32);
    M2C_UNK Ov001_QueueCreate(s32);
    Ov001TaskList *Ov001_ListCreate(void);
    void Ov001_ListPushFront(Ov001TaskList *, Ov001TaskNode *);
    void Ov001_ListPushBack(Ov001TaskList *, Ov001TaskNode *);
    extern s32 gOv001Tasks;
    extern u8 data_ov001_0218fd28[];
    u8 *src;
    s32 i;

    /* One 0x40-byte group per entry of the node-count table. */
    gOv001Tasks = Ov001_Alloc(sizeof(Ov001Task) * OV001_TASK_GROUP_COUNT, 4);
    src = data_ov001_0218fd28;
    i = 0;
    for (; i < OV001_TASK_GROUP_COUNT; i++) {
        OV001_TASKS[i].nodeCount = *src;
        OV001_TASKS[i].pool = (Ov001TaskNode *)Ov001_Alloc((u32)*src * sizeof(Ov001TaskNode), 4);
        OV001_TASKS[i].freeNodes = Ov001_QueueCreateFromRange(*src, (s32)OV001_TASKS[i].pool, sizeof(Ov001TaskNode));
        OV001_TASKS[i].pendingNodes = Ov001_QueueCreate(*src++);
        OV001_TASKS[i].list = Ov001_ListCreate();
        OV001_TASKS[i].head.priority = 0;
        OV001_TASKS[i].tail.priority = 0xFF;
        Ov001_ListPushFront(OV001_TASKS[i].list, &OV001_TASKS[i].head);
        Ov001_ListPushBack(OV001_TASKS[i].list, &OV001_TASKS[i].tail);
        OV001_TASKS[i].enabled = 1;
    }
}

/* Tear down the cooperative task system: free every task group's pending-callback
 * list and free-node queue, then the group array itself. */
void Ov001_FreeTasks(void) {
    void Ov001_ListDestroy(s32);
    void Ov001_QueueDestroy(s32);
    void Ov001_FreeAlloc(void *);
    extern s32 gOv001Tasks;
    extern s32 gVramBankGrants[];
    s32 i;

    for (i = 0; i < OV001_TASK_GROUP_COUNT; i++) {
        Ov001_ListDestroy((s32)OV001_TASKS[i].list);
        Ov001_QueueDestroy(OV001_TASKS[i].freeNodes);
    }
    /* The group array (the word right after gVramBankGrants); spelled through the
     * neighbouring symbol so the pool keeps the original's two literal words. */
    Ov001_FreeAlloc(gVramBankGrants + 13);
}

void Ov001_UpdateTaskGroup(s32 n) {
s32 Ov001_QueuePop(s32);
M2C_UNK Ov001_ReturnTaskNode();
extern s32 gOv001Tasks;
void *node;
s32 i; s32 offset;
if(!M2C_FIELD(gOv001Tasks+(n<<6),u8 *,0x38)) return;
node=M2C_FIELD(gOv001Tasks+(n<<6),void **,0x10);
while(node!=(void *)(gOv001Tasks+(n<<6)+0x20)) {
M2C_FIELD(node,void (**)(void *,s32),8)(node,M2C_FIELD(node,s32 *,12));
node=M2C_FIELD(node,void **,4);
}
offset=(s32)((u32)n*64);
for(i=0;i<M2C_FIELD((s32)((u8 *)gOv001Tasks+offset),s32 *,0x34);i++) {
s32 p=Ov001_QueuePop(M2C_FIELD((s32)((u8 *)gOv001Tasks+offset),s32 *,4));
if(!p) return;
Ov001_ReturnTaskNode(n,p);
}
}

/* Schedule `callback(arg)` as a task in `group` at `priority`, without an owned
 * argument buffer (see Ov001_AddTaskNode). */
void Ov001_AddTask(s32 group, s32 callback, s32 arg, s32 priority) {
    void *Ov001_AddTaskNode(s32, s32, s32, s32, u8);
    Ov001_AddTaskNode(group, callback, arg, priority, 0);
}

/* Take a free node from task group `group`, fill in the callback, its argument,
 * priority and ownership flag, and link it into the group's pending-callback
 * list just before the first node with a lower priority (lower runs first).
 * Interrupts are masked only while the list is walked and relinked. */
void *Ov001_AddTaskNode(s32 group, s32 callback, s32 arg, s32 priority, u8 ownsArg) {
    s32 Ov001_QueuePop(s32);
    s32 OS_DisableIrqMask(s32);
    void OS_EnableIrqMask(s32);
    void Ov001_ListInsertBefore(void *, void *);
    extern s32 gOv001Tasks;
    Ov001TaskNode *node;
    Ov001TaskNode *cur;
    s32 saved;

    node = (Ov001TaskNode *)Ov001_QueuePop(OV001_TASKS[group].freeNodes);
    node->callback = (void (*)(void *, s32))callback;
    node->arg = arg;
    node->priority = priority;
    node->ownsArg = ownsArg;
    saved = OS_DisableIrqMask(1);
    cur = OV001_TASKS[group].head.next;
    for (;;) {
        if ((u32)priority < cur->priority) {
            Ov001_ListInsertBefore(cur, node);
            break;
        }
        cur = cur->next;
    }
    OS_EnableIrqMask(saved);
    return node;
}

void Ov001_SetSlideStep(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
}

/* Queue `message` in task group `group`'s pending-message queue, for the group's
 * next update (see Ov001_UpdateTaskGroup). */
void Ov001_PostTaskMessage(s32 group, u32 message) {
    M2C_UNK Ov001_QueuePush(s32, u32);
    extern s32 gOv001Tasks;
    Ov001_QueuePush(OV001_TASKS[group].pendingNodes, message);
}

void Ov001_ReturnTaskNodeVeneer(void) {
    M2C_UNK Ov001_ReturnTaskNode();
    Ov001_ReturnTaskNode();
}

/* Recycle task node `node` of task group `group`: free the argument buffer it
 * owns, unlink it from the pending-callback list and push it back onto the
 * group's free-node queue. */
M2C_UNK Ov001_ReturnTaskNode(s32 group, Ov001TaskNode *node) {
    void Ov001_FreeAlloc(void *);
    M2C_UNK Ov001_ListRemove();
    M2C_UNK Ov001_QueuePush(s32, u32);
    extern s32 gOv001Tasks;
    if (node->ownsArg) Ov001_FreeAlloc((u8 *)node + 12);
    Ov001_ListRemove(node);
    Ov001_QueuePush(OV001_TASKS[group].freeNodes, (u32)node);
}

/* Enable (nonzero) or disable (0) the dispatch of task group `group`. */
void Ov001_SetTaskGroupEnabled(s32 group, s8 enabled) {
    extern s32 gOv001Tasks;
    OV001_TASKS[group].enabled = enabled;
}

