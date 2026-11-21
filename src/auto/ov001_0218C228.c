/* 18 functions from 0x0218C228 to 0x0218C9B4 (ov001), found by ds-decomp. */
#include "common.h"
#include "gx.h"
typedef struct RuntimeRangeNode { struct RuntimeRangeNode *prev, *next; u16 start, size; } RuntimeRangeNode;
typedef struct { u8 pad[0x180]; RuntimeRangeNode head, tail; s32 unk198, heap; } RuntimeRangePool;
typedef struct { s32 a; u8 pad[4]; s32 b; u8 rest[52]; } RuntimePair64;

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
if(p!=&((RuntimeRangePool *)gOv001TilePools)[n].tail) do {
RuntimeRangeNode *next=p->next;
s32 pos=p->start+p->size;
if(pos+units<=next->start) {
node->start=pos;
Ov001_ListInsertBefore(next,node);
break;
}
p=next;
} while(p!=(RuntimeRangeNode *)(gOv001TilePools+n*0x1a0+0x18c));
if(p==(RuntimeRangeNode *)(gOv001TilePools+n*0x1a0+0x18c)) SystemHalt();
} else {
p=&((RuntimeRangePool *)gOv001TilePools)[(u32)n].tail;
if(p!=&((RuntimeRangePool *)gOv001TilePools)[n].head) do {
RuntimeRangeNode *prev=p->prev;
s32 pos=p->start-units;
if(pos>=prev->start+prev->size) {
node->start=pos;
Ov001_ListInsertBefore(p,node);
break;
}
p=prev;
} while(p!=(RuntimeRangeNode *)(gOv001TilePools+n*0x1a0+0x180));
if(p==(RuntimeRangeNode *)(gOv001TilePools+n*0x1a0+0x180)) SystemHalt();
}
*out=node->start;
OS_EnableIrqMask(old);
return node;
}

void func_ov001_0218c3a0(u32 arg0) {
    M2C_UNK Ov001_QueuePush(s32, u32);
    M2C_UNK Ov001_ListRemove();
    extern s32 gOv001TilePools;
    s32 var_r4;

    var_r4 = 0;
    Ov001_ListRemove();
    if (arg0 >= (u32) (gOv001TilePools + 0x1A0)) {
        var_r4 = 1;
    }
    Ov001_QueuePush(M2C_FIELD(((var_r4 * 0x1A0) + gOv001TilePools), s32 *, 0x19C), arg0);
}

s32 StringLengthUpTo(u8 *p,s32 n) {
s32 i;
for(i=0;i<n;i++) if(!p[i]) break;
return i;
}

/* VRAM init pass 1: release the bank grant every VRAM allocator is holding and
 * remember the banks each one gave back in gVramBankGrants, which the second
 * init pass hands to the matching allocator again.  Then assign the main
 * background banks and clear VRAM for the new display setup. */
void GxReleaseAllBankGrants(void) {
M2C_UNK func_02003538(void);
M2C_UNK func_0200354c(void);
M2C_UNK func_02003560(void);
M2C_UNK func_02003584(void);
M2C_UNK func_020035a8(void);
M2C_UNK func_020035bc(void);
M2C_UNK func_020035d0(void);
M2C_UNK func_0200360c(void);
M2C_UNK func_02003620(void);
M2C_UNK func_02003634(void);
M2C_UNK func_0200365c(void);
M2C_UNK func_020035e4(void);
M2C_UNK func_020035f8(void);
void GX_SetBankForObjCD(s32);
void GxClearDisplayMemory();
extern s32 gVramBankGrants[];
gVramBankGrants[0]=func_02003538();
gVramBankGrants[1]=func_0200354c();
gVramBankGrants[2]=func_02003560();
gVramBankGrants[3]=func_02003584();
gVramBankGrants[4]=func_020035a8();
gVramBankGrants[5]=func_020035bc();
gVramBankGrants[6]=func_020035d0();
gVramBankGrants[7]=func_0200360c();
gVramBankGrants[8]=func_02003620();
gVramBankGrants[9]=func_02003634();
gVramBankGrants[10]=func_0200365c();
gVramBankGrants[11]=func_020035e4();
gVramBankGrants[12]=func_020035f8();
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
    s32 func_02003538(void);
    s32 func_0200354c(void);
    s32 func_0200360c(void);
    s32 func_02003620(void);
    void GxClearDisplayMemory(void);
    void SetLcdEnabled(s32);
    void GX_SetBankForBG(s32);
    void GX_SetBankForOBJ(s32);
    void func_02002ab8(s32);
    void GX_SetBankForObjExtPalette(s32);
    void GX_SetBankForTex(s32);
    void GX_SetBankForOBJExtPltt(s32);
    void GX_SetBankForTexExtPltt(s32);
    void func_02003124(s32);
    void GX_SetBankForSubOBJ(s32);
    void GX_SetBankForBGExtPlttSub(s32);
    void GX_SetBankForOBJExtPlttSub(s32);
    s32 func_02003104(s32);

    func_02003538();
    func_0200354c();
    func_0200360c();
    func_02003620();
    GxClearDisplayMemory();
    GX_SetBankForBG(gVramBankGrants[0]);
    GX_SetBankForOBJ(gVramBankGrants[1]);
    func_02002ab8(gVramBankGrants[2]);
    GX_SetBankForObjExtPalette(gVramBankGrants[3]);
    GX_SetBankForTex(gVramBankGrants[4]);
    GX_SetBankForOBJExtPltt(gVramBankGrants[5]);
    GX_SetBankForTexExtPltt(gVramBankGrants[6]);
    func_02003124(gVramBankGrants[7]);
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
    M2C_UNK func_020035f8();
    M2C_UNK MI_CpuFill32(M2C_UNK, s32, M2C_UNK);
    func_02003104(VRAM_BANK_A | VRAM_BANK_B | VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G | VRAM_BANK_H | VRAM_BANK_I);
    MI_CpuFill32(0, GX_MAIN_BG_VRAM_BASE, GX_MAIN_BG_VRAM_SIZE);
    MI_CpuFill32(0, GX_MAIN_BG_EXTPLTT_VRAM_BASE, GX_MAIN_BG_EXTPLTT_VRAM_SIZE);
    func_020035f8();
    MI_CpuFill32(GX_OAM_DISABLED, GX_MAIN_OBJ_OAM_BASE, GX_OAM_SIZE);
    MI_CpuFill32(0, GX_MAIN_PALETTE_BASE, GX_PALETTE_SIZE);
    MI_CpuFill32(GX_OAM_DISABLED, GX_SUB_OBJ_OAM_BASE, GX_OAM_SIZE);
    MI_CpuFill32(0, GX_SUB_PALETTE_BASE, GX_PALETTE_SIZE);
}

void func_ov001_0218c63c(void) {
    s32 func_0200ed18(s32 *);
    s32 sp0;

    if (func_0200ed18(&sp0) != 0) {
        return;
    }
    if (sp0 == 0xF) {
        return;
    }
    func_0200eca8(0xF);
}

void func_ov001_0218c668(void) {
    func_0200eca8(1);
}

/* Task-group array behind the untyped gOv001Tasks slot; each access reloads
 * the global, as the helpers may replace it. */
#define OV001_TASKS ((Ov001Task *)gOv001Tasks)

void Ov001_InitTasks(void) {
    M2C_UNK Ov001_Alloc(s32, s32);
    M2C_UNK Ov001_QueueCreateFromBuffer(s32, s32, s32);
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
        OV001_TASKS[i].freeNodes = Ov001_QueueCreateFromBuffer(*src, (s32)OV001_TASKS[i].pool, sizeof(Ov001TaskNode));
        OV001_TASKS[i].pendingNodes = Ov001_QueueCreate(*src++);
        OV001_TASKS[i].list = Ov001_ListCreate();
        OV001_TASKS[i].head.priority = 0;
        OV001_TASKS[i].tail.priority = 0xFF;
        Ov001_ListPushFront(OV001_TASKS[i].list, &OV001_TASKS[i].head);
        Ov001_ListPushBack(OV001_TASKS[i].list, &OV001_TASKS[i].tail);
        OV001_TASKS[i].enabled = 1;
    }
}

void func_ov001_0218c78c(void) {
void func_ov001_0218bf30(s32); void func_ov001_0218a6d8(s32); void Ov001_FreeAlloc(void *); extern s32 gOv001Tasks; extern s32 gVramBankGrants[]; s32 i; for(i=0;i<2;i++){ func_ov001_0218bf30(((RuntimePair64 *)gOv001Tasks)[i].b);func_ov001_0218a6d8(((RuntimePair64 *)gOv001Tasks)[i].a); } Ov001_FreeAlloc(gVramBankGrants+13); }

void func_ov001_0218c7d4(s32 n) {
s32 Ov001_QueuePop(s32);
M2C_UNK func_ov001_0218c958();
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
func_ov001_0218c958(n,p);
}
}

void Ov001_AddTask(s32 a,s32 b,s32 c,s32 d) {
void *Ov001_AddTaskNode(s32,s32,s32,s32,u8);
Ov001_AddTaskNode(a,b,c,d,0);
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

void Ov001_PostTaskMessage(s32 n,u32 arg) {
M2C_UNK Ov001_QueuePush(s32,u32);
extern s32 gOv001Tasks;
Ov001_QueuePush(M2C_FIELD(gOv001Tasks+(n<<6),s32 *,4),arg);
}

void func_ov001_0218c94c(void) {
    M2C_UNK func_ov001_0218c958();
    func_ov001_0218c958();
}

M2C_UNK func_ov001_0218c958(s32 n,void *p) {
void Ov001_FreeAlloc(void *);
M2C_UNK Ov001_ListRemove();
M2C_UNK Ov001_QueuePush(s32,u32);
extern s32 gOv001Tasks;
if(M2C_FIELD(p,u8 *,17)) Ov001_FreeAlloc((u8 *)p+12);
Ov001_ListRemove(p);
Ov001_QueuePush(M2C_FIELD(gOv001Tasks+(n<<6),s32 *,0),(u32)p);
}

void Ov001_SetTaskGroupEnabled(s32 arg0, s8 arg1) {
    extern s32 gOv001Tasks;
    M2C_FIELD((gOv001Tasks + (arg0 << 6)), s8 *, 0x38) = arg1;
}

