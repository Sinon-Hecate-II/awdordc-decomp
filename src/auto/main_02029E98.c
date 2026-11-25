/* 58 functions from 0x02029E98 to 0x0202AE00 (main), found by ds-decomp. */
#include "common.h"
#include "exp_heap.h"
#include "fs.h"
#include "sound.h"
typedef struct HeapRange { u8 *start; u8 *end; } HeapRange;

/* Initialise a heap header: store its signature, region and attribute, start its
 * child list and link the heap into the list of the heap that contains it (the
 * global heap list, initialised on first use, when no heap contains it). */
M2C_UNK InitHeapHead(void *heap, s32 signature, s32 start, M2C_UNK end, s32 attribute) {
    M2C_UNK ListInit(void *, s32);
    M2C_UNK ListAppend(M2C_UNK, void *);
    M2C_UNK GetHeapParentList(void *);
    extern s32 gHeapListInitialized;
    extern u8 gHeapList[];
    struct HeapAttribute { u32 value:8; u32 rest:24; };

    M2C_FIELD(heap, s32 *, 0) = signature;
    M2C_FIELD(heap, s32 *, 0x18) = start;
    M2C_FIELD(heap, s32 *, 0x1C) = end;
    M2C_FIELD(heap, s32 *, 0x20) = 0;
    M2C_FIELD(heap, struct HeapAttribute *, 0x20).value = *(u16 *)&attribute;
    ListInit(heap + 0xC, 4);
    if (gHeapListInitialized == 0) {
        ListInit(gHeapList, 4);
        gHeapListInitialized = 1;
    }
    ListAppend(GetHeapParentList(heap), heap);
}

M2C_UNK func_02029f14(void *arg0) {
    M2C_UNK GetHeapParentList(void *);
    M2C_UNK ListRemove(M2C_UNK, void *);
    ListRemove(GetHeapParentList(arg0), arg0);
}

/* Fill `range` with the payload range of heap block `block`: the payload starts
 * back from the block header by the offset encoded in its attribute word (bits
 * 8..14), and ends after the header plus the block's payload size. */
void GetBlockRange(void *range, void *block) {
    s32 payloadEnd = (s32)(block + HEAP_BLOCK_HEADER_SIZE);
    M2C_FIELD(range, s32 *, 0) = (s32)(block - (u16)(((s32)M2C_FIELD(block, u16 *, 2) >> 8) & 0x7F));
    M2C_FIELD(range, s32 *, 4) = M2C_FIELD(block, s32 *, 4) + payloadEnd;
}

/* Remove `block` from the doubly-linked block list anchored at `list` (head at
 * HEAP_LIST_HEAD, tail at HEAP_LIST_TAIL) and return its previous neighbour,
 * the position where a merged block is put back. */
void *UnlinkBlock(void *list, void *block) {
    void *next;
    void *prev;

    prev = M2C_FIELD(block, void **, HEAP_BLOCK_LINK_PREV);
    next = M2C_FIELD(block, void **, HEAP_BLOCK_LINK_NEXT);
    if (prev != NULL) {
        M2C_FIELD(prev, void **, HEAP_BLOCK_LINK_NEXT) = next;
    } else {
        M2C_FIELD(list, void **, HEAP_LIST_HEAD) = next;
    }
    if (next != NULL) {
        M2C_FIELD(next, void **, HEAP_BLOCK_LINK_PREV) = prev;
    } else {
        M2C_FIELD(list, void **, HEAP_LIST_TAIL) = prev;
    }
    return prev;
}

/* Insert `block` into the free/used block list anchored at `list` (head at
 * HEAP_LIST_HEAD, tail at HEAP_LIST_TAIL), directly after `after`; a NULL
 * `after` inserts at the head. Returns the block. */
void *InsertBlock(void *list, void *block, void *after) {
    void *next;

    M2C_FIELD(block, void **, HEAP_BLOCK_LINK_PREV) = after;
    if (after != NULL) {
        next = M2C_FIELD(after, void **, HEAP_BLOCK_LINK_NEXT);
        M2C_FIELD(after, void **, HEAP_BLOCK_LINK_NEXT) = block;
    } else {
        next = M2C_FIELD(list, void **, HEAP_LIST_HEAD);
        M2C_FIELD(list, void **, HEAP_LIST_HEAD) = block;
    }
    M2C_FIELD(block, void **, HEAP_BLOCK_LINK_NEXT) = next;
    if (next != NULL) {
        M2C_FIELD(next, void **, HEAP_BLOCK_LINK_PREV) = block;
    } else {
        M2C_FIELD(list, void **, HEAP_LIST_TAIL) = block;
    }
    return block;
}

/* Initialise the heap block whose header starts at area->start: set its signature,
 * clear its attribute word and list links, and store the payload size from the end
 * of the header up to area->end.  Returns the block. */
void *InitBlock(void *area, s16 signature) {
    void *block = M2C_FIELD(area, void **, 0);
    M2C_FIELD(block, s16 *, 0) = signature;
    M2C_FIELD(block, s16 *, 2) = 0;
    M2C_FIELD(block, s32 *, 4) = M2C_FIELD(area, s32 *, 4) - (s32)(block + 16);
    M2C_FIELD(block, void **, HEAP_BLOCK_LINK_PREV) = NULL;
    M2C_FIELD(block, void **, HEAP_BLOCK_LINK_NEXT) = NULL;
    return block;
}

/* Creates an expanded heap ('EXPH') over the memory from `heap` up to
 * `endAddress`: initialises the heap header, turns the whole area into one free
 * block and links that block at both ends of the heap's free list. */
void *CreateExpHeap(void *heap, u32 endAddress, s32 attribute) {
    void *InitBlock(void *, s16);
    s32 area[2];
    void *block;

    InitHeapHead(heap, HEAP_SIGNATURE_EXP, (s32)((u8 *)heap + 0x38), endAddress, attribute);
    M2C_FIELD(heap, s16 *, 0x34) = 0;
    M2C_FIELD(heap, u16 *, HEAP_FLAGS) = 0;
    M2C_FIELD(heap, u16 *, HEAP_FLAGS) &= ~1;
    area[0] = M2C_FIELD(heap, s32 *, HEAP_AREA_START);
    area[1] = M2C_FIELD(heap, s32 *, HEAP_AREA_END);
    block = InitBlock(area, HEAP_BLOCK_FREE);
    M2C_FIELD(heap, void **, HEAP_FREE_LIST) = block;
    M2C_FIELD(heap, void **, HEAP_FREE_LIST + 4) = block;
    M2C_FIELD(heap, s32 *, HEAP_USED_LIST) = 0;
    M2C_FIELD(heap, s32 *, HEAP_USED_LIST + 4) = 0;
    return heap;
}

/* Carves an allocation of `size` bytes at `address` out of the free heap block
 * `block`: unlinks the block, turns the free space in front of and behind the
 * allocation back into free blocks (absorbing a remainder too small to hold a
 * header), clears the payload when the heap asks for it, and links the new used
 * block in front of the heap's used-list anchor.  `fromTail` marks the block as
 * tail-allocated.  Returns the payload address. */
s32 AllocFromBlock(void *freeList, void *block, s32 address, s32 size, u16 fromTail) {
    void GetBlockRange(void *, void *);
    void *InitBlock(void *, s16);
    void *UnlinkBlock(void *, void *);
    void *InsertBlock(void *, void *, void *);
    M2C_UNK CpuFill(M2C_UNK, u32, s32);
    HeapRange front;
    HeapRange back;
    HeapRange used;
    void *node;
    void *usedBlock;
    s32 blockEnd;
    s32 blockHeader;
    s32 gap;
    s32 allocStart;
    u16 heapTag;

    GetBlockRange(&front, block);
    blockEnd = (s32)front.end;
    blockHeader = address - 0x10;
    front.end = (u8 *)blockHeader;
    back.end = (u8 *)blockEnd;
    back.start = (u8 *)(size + address);
    node = UnlinkBlock(freeList, block);
    if ((u32)(front.end - front.start) < 0x14U) {
        front.end = front.start;
    } else {
        node = InsertBlock(freeList, InitBlock(&front, HEAP_BLOCK_FREE), node);
    }
    if ((u32)(back.end - back.start) < 0x14U) {
        back.start = back.end;
    } else {
        node = InsertBlock(freeList, InitBlock(&back, HEAP_BLOCK_FREE), node);
    }
    gap = (s32)back.start - (s32)front.end;
    if ((u8)M2C_FIELD(freeList, s32 *, -4) & 1) {
        CpuFill(0, (u32)front.end, gap);
    }
    used.start = (u8 *)blockHeader;
    used.end = back.start;
    usedBlock = InitBlock(&used, HEAP_BLOCK_USED);
    M2C_FIELD(usedBlock, u16 *, 2) = (u16)(M2C_FIELD(usedBlock, u16 *, 2) & ~HEAP_BLOCK_ATTR_FROM_TAIL);
    M2C_FIELD(usedBlock, u16 *, 2) = (u16)(M2C_FIELD(usedBlock, u16 *, 2) | (u16)(fromTail << 15));
    allocStart = (s32)front.end;
    M2C_FIELD(usedBlock, u16 *, 2) = (u16)(M2C_FIELD(usedBlock, u16 *, 2) & ~HEAP_BLOCK_ATTR_OFFSET);
    M2C_FIELD(usedBlock, u16 *, 2) = (u16)(M2C_FIELD(usedBlock, u16 *, 2) | ((((u16)((u32)usedBlock - allocStart)) & 0x7F) << 8));
    heapTag = (u8)M2C_FIELD(freeList, u16 *, 0x10);
    M2C_FIELD(usedBlock, u16 *, 2) = (u16)(M2C_FIELD(usedBlock, u16 *, 2) & ~HEAP_BLOCK_ATTR_TAG);
    M2C_FIELD(usedBlock, u16 *, 2) = (u16)(M2C_FIELD(usedBlock, u16 *, 2) | heapTag);
    InsertBlock((void *)((char *)freeList + 8), usedBlock, M2C_FIELD(freeList, s32 *, 0xC));
    return address;
}

s32 AllocFromExpHeapHead(void *arg0, s32 arg1, s32 arg2) {
    s32 AllocFromBlock(void *, void *, s32, s32, u16);
    s32 base, aligned;
    s32 first;
    void *node;
    u32 size, best;
    void *chosen;
    s32 address;
    node = M2C_FIELD(arg0, void **, 0x24);
    chosen = NULL;
    if ((u16)(M2C_FIELD(arg0, u16 *, 0x36) & 1) == 0) first = 1;
    else first = 0;
    best = (u32)chosen - 1;
    address = 0;
    while (node != NULL) {
        base = (s32)(node + 16);
        aligned = ~(arg2 - 1) & (arg2 - 1 + base);
        size = M2C_FIELD(node, u32 *, 4);
        if (size >= (u32)(arg1 + (aligned - base)) && best > size) {
            chosen = node;
            best = size;
            address = aligned;
            if (first || size == arg1) break;
        }
        node = M2C_FIELD(node, void **, 12);
    }
    if (chosen == NULL) return 0;
    return AllocFromBlock(arg0 + 0x24, chosen, address, arg1, 0);
}

s32 AllocFromExpHeapTail(void *arg0, s32 arg1, s32 arg2) {
s32 AllocFromBlock(void *, void *, s32, s32, u16);
s32 base,aligned,first; void *node; u32 size,best; void *chosen; s32 address;
node=M2C_FIELD(arg0,void **,0x28);
if((u16)(M2C_FIELD(arg0,u16 *,0x36)&1)==0) first=1;else first=0;
chosen=NULL; address=0;best=-1U;
while(node!=NULL) {
size=M2C_FIELD(node,u32 *,4);
base=(s32)(node+16);
aligned=~(arg2-1)&(size+base-arg1);
if(aligned-base>=0 && best>size) {
chosen=node;best=size;address=aligned;
if(first || size==arg1)break;
}
node=M2C_FIELD(node,void **,8);
}
if(chosen==NULL)return 0;
return AllocFromBlock(arg0+0x24,chosen,address,arg1,1);
}

/* Frees again a used-block range that was cut out of the heap at `range`
 * (the SDK's free-walk): unlinks the block that starts at range->start,
 * merges the free block in front of it when they are adjacent, and puts the
 * resulting free block back on `freeList`.  Returns 0 when what is left is
 * too small to be a block (16 bytes), 1 when a free block was inserted. */
s32 FreeBlockRange(void *freeList, HeapRange *range)
{
    HeapRange merged;
    void *prev;
    u8 *block;
    u32 size;

    merged = *range;
    prev = 0;
    for (block = M2C_FIELD(freeList, u8 **, 0); block != 0; block = M2C_FIELD(block, u8 **, 12)) {
        if (block < range->start) {
            prev = block;
        } else {
            if (block == range->end) {
                size = M2C_FIELD(block, u32 *, 4);
                merged.end = (u8 *)(size + (u32)(block + 16));
                UnlinkBlock(freeList, block);
            }
            break;
        }
    }
    if (prev != 0 && (u8 *)(M2C_FIELD(prev, u32 *, 4) + (u32)((u8 *)prev + 16)) == range->start) {
        merged.start = prev;
        prev = UnlinkBlock(freeList, prev);
    }
    if ((u32)(merged.end - merged.start) < 16) return 0;
    InsertBlock(freeList, InitBlock(&merged, HEAP_BLOCK_FREE), prev);
    return 1;
}

/* Create an expanded heap on the 4-byte-aligned range of `size` bytes starting
 * at `base`: NULL when the range is empty or smaller than the 0x4C-byte heap
 * header. */
void *CreateExpHeapInRange(u32 base, u32 size, s32 attribute) {
    u32 end = (size + base) & ~3;
    u32 start = (base + 3) & ~3;
    if (start > end || end - start < 0x4C) return NULL;
    return CreateExpHeap((void *)start, end, attribute);
}

void func_0202a45c(void) {
    M2C_UNK func_02029f14();
    func_02029f14();
}

/* Allocate `size` bytes with `alignment` from an expanded heap: round the size up
 * to a 4-byte multiple, then take the block from the front of the heap for a
 * non-negative alignment or from the rear for a negative one. */
s32 AllocFromExpHeap(void *heap, s32 size, s32 alignment) {
    s32 AllocFromExpHeapHead(void *, s32, s32);
    s32 AllocFromExpHeapTail(void *, s32, s32);

    if (size == 0) size = 1;
    size = (size + 3) & ~3;
    if (alignment >= 0) return AllocFromExpHeapHead(heap, size, alignment);
    return AllocFromExpHeapTail(heap, size, -alignment);
}

/* Free the used block `block` of expanded heap `heap`: derive its range, unlink
 * it from the used list and merge the range back into the free list. */
void FreeExpHeapBlock(s32 heap, s32 block) {
    void GetBlockRange(void *, void *);
    void *UnlinkBlock(void *, void *);
    s32 func_0202a334(void *, HeapRange *);
    s32 header;
    HeapRange range;

    header = block - HEAP_BLOCK_HEADER_SIZE;
    GetBlockRange(&range, (void *)header);
    UnlinkBlock((void *)(heap + HEAP_USED_LIST), (void *)header);
    func_0202a334((void *)(heap + HEAP_FREE_LIST), &range);
}

#pragma opt_propagation off
s32 SetHeapFlags(void *arg0,u32 arg1) {
u32 old; u32 bit;
old=M2C_FIELD(arg0,u16 *,0x36);
bit=old&1;
M2C_FIELD(arg0,u16 *,0x36)=old & ~1;
M2C_FIELD(arg0,u16 *,0x36)=M2C_FIELD(arg0,u16 *,0x36)|(arg1&1);
return bit;
}
#pragma opt_propagation reset
/* Initialise a frame heap ('FRMH') over the memory the caller hands in: set up its
 * heap header, then point the frame's head and tail at the start and end of its
 * area and clear its recorded-state list. */
void *InitFrameHeapArea(void *heap, M2C_UNK endAddress, s32 attribute) {
    M2C_UNK InitHeapHead();
    InitHeapHead(heap, HEAP_SIGNATURE_FRM, heap + FRAME_HEAP_DATA, endAddress, attribute);
    M2C_FIELD(heap, s32 *, FRAME_HEAP_HEAD) = (s32) M2C_FIELD(heap, s32 *, HEAP_AREA_START);
    M2C_FIELD(heap, s32 *, FRAME_HEAP_TAIL) = (s32) M2C_FIELD(heap, s32 *, HEAP_AREA_END);
    M2C_FIELD(heap, s32 *, FRAME_HEAP_STATE_LIST) = 0;
    return heap;
}

/* Frame-heap allocation from the front: align the heap's head pointer up to
 * `alignment`, fail when the block would run past the heap's tail (returns NULL),
 * zero-fill the newly claimed bytes when the heap asks for it, and advance the
 * head.  Returns the aligned payload address. */
void *AllocFromFrameHeapHead(void *heap, s32 size, s32 alignment) {
    M2C_UNK CpuFill(M2C_UNK, u32, s32);
    u32 head;
    u32 aligned;
    u32 next;
    u32 diff;

    head = M2C_FIELD(heap, u32 *, 0);
    aligned = (u32)(~(alignment - 1)) & ((u32)(alignment - 1) + head);
    next = (u32)size + aligned;
    if (next > M2C_FIELD(heap, u32 *, 4)) {
        return (void *)0;
    }
    diff = next - head;
    if (((u8)M2C_FIELD(heap, s32 *, -4) & 0x1) != 0) {
        CpuFill(0, head, (s32)diff);
    }
    M2C_FIELD(heap, u32 *, 0) = next;
    return (void *)aligned;
}

/* Frame-heap allocation from the tail: lower the heap's tail by `size`, rounded
 * down to `alignment`; fail when that would cross the heap's head (returns 0),
 * zero-fill the newly claimed bytes when the heap asks for it, and store the new
 * tail.  Returns the aligned payload address. */
u32 AllocFromFrameHeapTail(void *heapPtr, s32 size, s32 alignment) {
    M2C_UNK CpuFill(M2C_UNK, u32, s32);
    FrameHeap *heap = (FrameHeap *)heapPtr;
    u32 tail;
    u32 aligned;
    u32 diff;

    tail = heap->tail;
    aligned = (u32)(~(alignment - 1)) & (tail - size);
    if (aligned < heap->head) {
        return 0U;
    }
    diff = tail - aligned;
    if ((u8)M2C_FIELD(heap, s32 *, FRAME_HEAP_ATTRIBUTE) & FRAME_HEAP_ATTR_ZERO_FILL) {
        CpuFill(0, aligned, diff);
    }
    heap->tail = aligned;
    return aligned;
}

void FreeFrameHeapToHead(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
}

/* Free everything the frame heap allocated from its tail: point the heap's tail
 * at the end of its area and move the saved tail of every recorded state there
 * too. */
void FreeFrameHeapToTail(void *heap) {
    void *state;

    state = M2C_FIELD(heap, void **, FRAME_HEAP_STATE_LIST);
    if (state != NULL) {
        do {
            M2C_FIELD(state, s32 *, FRAME_HEAP_STATE_TAIL) = (s32) M2C_FIELD(heap, s32 *, HEAP_AREA_END);
            state = M2C_FIELD(state, void **, FRAME_HEAP_STATE_NEXT);
        } while (state != NULL);
    }
    M2C_FIELD(heap, s32 *, FRAME_HEAP_TAIL) = (s32) M2C_FIELD(heap, s32 *, HEAP_AREA_END);
}

/* Create a frame heap ('FRMH') in the caller's buffer of `size` bytes that starts
 * at `startAddress`: both ends are aligned to 4 bytes and the buffer must hold the
 * heap header (FRAME_HEAP_DATA bytes).  Returns the heap, or NULL when the buffer
 * is too small. */
void *CreateFrameHeap(u32 startAddress, u32 size, s32 attribute) {
    void *InitFrameHeapArea(void *, M2C_UNK, s32);
    u32 end = (size + startAddress) & ~3;
    u32 start = (startAddress + 3) & ~3;

    if (start > end || end - start < FRAME_HEAP_DATA) return NULL;
    return InitFrameHeapArea((void *)start, (M2C_UNK)end, attribute);
}

void DestroyFrameHeap(void) {
    M2C_UNK func_02029f14();
    func_02029f14();
}

/* Allocate `size` bytes from the frame heap of the sound heap `heap`: round the
 * size up to 4 bytes (a zero size still claims one byte) and allocate with
 * `alignment` from the front, or from the tail when the alignment is negative
 * (the tail allocation takes its absolute value). */
void Sound_HeapAlloc(void *heap, s32 size, s32 alignment) {
    void *AllocFromFrameHeapHead(void *, M2C_UNK, M2C_UNK);
    u32 AllocFromFrameHeapTail(void *, s32, s32);
    if (size == 0) {
        size = 1;
    }
    size = (size + 3) & ~3;
    heap = (s8 *)heap + FRAME_HEAP_HEAD;
    if (alignment >= 0) {
        AllocFromFrameHeapHead(heap, (M2C_UNK)size, (M2C_UNK)alignment);
    } else {
        AllocFromFrameHeapTail(heap, size, -alignment);
    }
}

/* Free what has been allocated from the frame heap `heap`: from the frame's head,
 * from its tail, or both, by the FRAME_HEAP_FREE_TO_* bits of `mode`. */
void FreeToFrameHeap(void *heap, s32 mode) {
    void FreeFrameHeapToHead(void *);
    void FreeFrameHeapToTail(void *);

    if (mode & FRAME_HEAP_FREE_TO_HEAD) {
        FreeFrameHeapToHead(heap);
    }
    if (mode & FRAME_HEAP_FREE_TO_TAIL) {
        FreeFrameHeapToTail(heap);
    }
}

#pragma opt_propagation off
/* Largest block a frame heap can still allocate with the given alignment: round
 * the frame head up to the alignment and return the bytes left before the tail,
 * or 0 when the tail is already below it. */
s32 GetAllocatableSizeForFrameHeap(void *heap, M2C_UNK alignment) {
    s32 Abs(M2C_UNK);
    s32 t;
    u32 head, tail, start;
    t = Abs(alignment) - 1;
    head = M2C_FIELD(heap, u32 *, FRAME_HEAP_HEAD);
    start = ~t;
    t += head;
    tail = M2C_FIELD(heap, u32 *, FRAME_HEAP_TAIL);
    start &= t;
    if (start > tail) return 0;
    return tail - start;
}
#pragma opt_propagation reset
/* Records a frame-heap state tagged `tag`: allocates a state node from the heap,
 * saves the heap's current head and tail in it, pushes it on the heap's state
 * list and returns 1, or 0 when the node cannot be allocated. */
s32 RecordFrameHeapState(void *heap, s32 tag) {
    void *AllocFromFrameHeapHead(void *, M2C_UNK, M2C_UNK);
    s32 head;
    void *state;

    head = M2C_FIELD(heap, s32 *, 0x24);
    state = AllocFromFrameHeapHead(heap + 0x24, FRAME_HEAP_STATE_SIZE, 4);
    if (state == NULL) {
        return 0;
    }
    M2C_FIELD(state, s32 *, FRAME_HEAP_STATE_TAG) = tag;
    M2C_FIELD(state, s32 *, FRAME_HEAP_STATE_HEAD) = head;
    M2C_FIELD(state, s32 *, FRAME_HEAP_STATE_TAIL) = (s32) M2C_FIELD(heap, s32 *, 0x28);
    M2C_FIELD(state, void **, FRAME_HEAP_STATE_NEXT) = (void *) M2C_FIELD(heap, void **, 0x2C);
    M2C_FIELD(heap, void **, FRAME_HEAP_STATE_LIST) = state;
    return 1;
}

/* Restore the frame heap to a recorded state: find the saved-state node whose tag
 * is `tag` (the newest node when tag is 0) and put back the frame head and tail
 * it recorded, dropping that node and every newer one.  Returns 0 when no node
 * matches. */
s32 UnrecordFrameHeapState(void *heap, s32 tag) {
    void *state;

    state = M2C_FIELD(heap, void **, FRAME_HEAP_STATE_LIST);
    if ((tag != 0) && (state != NULL)) {
loop_4:
        if (M2C_FIELD(state, s32 *, FRAME_HEAP_STATE_TAG) != tag) {
            state = M2C_FIELD(state, void **, FRAME_HEAP_STATE_NEXT);
            if (state != NULL) {
                goto loop_4;
            }
        }
    }
    if (state == NULL) {
        return 0;
    }
    M2C_FIELD(heap, s32 *, FRAME_HEAP_HEAD) = (s32) M2C_FIELD(state, s32 *, FRAME_HEAP_STATE_HEAD);
    M2C_FIELD(heap, s32 *, FRAME_HEAP_TAIL) = (s32) M2C_FIELD(state, s32 *, FRAME_HEAP_STATE_TAIL);
    M2C_FIELD(heap, void **, FRAME_HEAP_STATE_LIST) = (void *) M2C_FIELD(state, void **, FRAME_HEAP_STATE_NEXT);
    return 1;
}

/* True when `header` starts with a NARC archive header: the "NARC" magic, the
 * little-endian byte-order mark and version 0x0100. */
s32 IsValidNarcHeader(void *header) {
    if (M2C_FIELD(header, s32 *, 0) != NARC_MAGIC) {
        return 0;
    }
    if (M2C_FIELD(header, u16 *, 4) != NARC_BYTE_ORDER) {
        return 0;
    }
    if (M2C_FIELD(header, u16 *, 6) == NARC_VERSION) {
        return 1;
    }
    return 0;
}

/* Initialise a NARC archive handle from its loaded image: check the NARC
 * header, find the file-allocation (BTAF), file-name (BTNF) and image (GMIF)
 * blocks, register the handle under `name` and give it the block layout the
 * file lookups use. Returns 0 on a bad archive or a failed registration. */
s32 InitNarcArchive(void *archive, M2C_UNK name, void *data) {
    s32 RegisterArchiveName(void *, M2C_UNK, s32);
    M2C_UNK InitArchive(void *);
    s32 ConfigureArchiveLayout(void *, void *, s32, s32, s32, s32, s32, s32);
    s32 StringLength(M2C_UNK);
    void *fat;
    void *fnt;
    void *image;
    void *imageData;
    s32 blockIndex;
    void *block;
    u16 blockCount;
    s32 tag;

    fat = NULL;
    fnt = NULL;
    image = NULL;
    if (IsValidNarcHeader(data) == 0) {
        return 0;
    }
    blockCount = M2C_FIELD(data, u16 *, 0xE);
    blockIndex = 0;
    block = data + M2C_FIELD(data, u16 *, 0xC);
    if ((s32) blockCount > 0) {
        do {
            tag = M2C_FIELD(block, s32 *, 0);
            switch (tag) {
            case NARC_BLOCK_FNT:
                fnt = block;
                break;
            case NARC_BLOCK_FAT:
                fat = block;
                break;
            case NARC_BLOCK_IMAGE:
                image = block;
                break;
            }
            blockIndex += 1;
            block += M2C_FIELD(block, s32 *, 4);
        } while (blockIndex < (s32) blockCount);
    }
    InitArchive(archive);
    M2C_FIELD(archive, void **, 0x5C) = data;
    M2C_FIELD(archive, void **, 0x60) = fat;
    imageData = image + 8;
    M2C_FIELD(archive, void **, 0x64) = imageData;
    if (RegisterArchiveName(archive, name, StringLength(name)) == 0) {
        return 0;
    }
    if (ConfigureArchiveLayout(archive, imageData, (fat + 0xC) - imageData, M2C_FIELD(fat, s32 *, 4) - 0xC, (fnt + 8) - imageData, M2C_FIELD(fnt, s32 *, 4) - 8, 0, 0) != 0) {
        return 1;
    }
    ReleaseArchiveName(archive);
    return 0;
}

/* Close the archive handle `archive`: shut the archive's file down and, when
 * that succeeded, release the archive's registered name.  Returns 0 when the
 * archive's file could not be closed. */
s32 CloseArchive(FSArchive *archive) {
    s32 CloseArchiveFile(FSArchive *);
    if (CloseArchiveFile(archive) == 0) {
        return 0;
    }
    ReleaseArchiveName(archive);
    return 1;
}

/* Sets the sound driver up once: shorts out if it is already up, initializes the
 * sound command queue, installs the handlers that reset the driver's channels,
 * then starts the voice allocator and the streamed sound state.  The driver's id
 * (-1 = none) and state are left at their start values. */
void InitSoundDriver(void) {
    M2C_UNK InitSoundCommandSystem(M2C_UNK);
    M2C_UNK PM_AddPreSleepCallback(M2C_UNK);
    M2C_UNK PM_AddPostSleepCallback(M2C_UNK);
    void func_0202ab60(void);
    M2C_UNK func_0202ba8c(void);
    M2C_UNK Sound_InitVoices(void);
    void Sound_StopAllChannels(void);
    void func_0202aa58(void);
    extern M2C_UNK gSoundInitState;
    extern M2C_UNK data_02138eb0;
    extern M2C_UNK data_02138ebc;
    if (M2C_FIELD(&gSoundInitState, s32 *, SOUND_INIT_DONE) != 0) {
        return;
    }
    M2C_FIELD(&gSoundInitState, s32 *, SOUND_INIT_DONE) = 1;
    InitSoundCommandSystem((M2C_UNK)&gSoundInitState);
    M2C_FIELD(&gSoundInitState, void **, SOUND_INIT_STOP) = (void *)Sound_StopAllChannels;
    M2C_FIELD(&gSoundInitState, s32 *, 0x14) = 0;
    M2C_FIELD(&gSoundInitState, void **, SOUND_INIT_SILENCE) = (void *)func_0202aa58;
    M2C_FIELD(&gSoundInitState, s32 *, 0x20) = 0;
    PM_AddPreSleepCallback((M2C_UNK)&data_02138eb0);
    PM_AddPostSleepCallback((M2C_UNK)&data_02138ebc);
    func_0202ab60();
    func_0202ba8c();
    Sound_InitVoices();
    M2C_FIELD(&gSoundInitState, s8 *, 0) = -1;
    M2C_FIELD(&gSoundInitState, s32 *, 4) = 1;
}

/* One frame of the sound driver, run by the main loop: apply every command the
 * ARM7 has finished, start and update the voices, streamed voice volumes and
 * player channels, then flush the commands queued here to the ARM7. */
void Sound_UpdateDriver(void) {
    s32 Sound_DequeueCommand(M2C_UNK);
    M2C_UNK Sound_FlushCommands(M2C_UNK);
    M2C_UNK Sound_UpdateVoices();
    M2C_UNK UpdateStreamVoiceVolume();
    M2C_UNK Sound_UpdatePlayerChannels();
    do {
        /* Drop the commands the ARM7 already applied. */
    } while (Sound_DequeueCommand(0) != 0);
    Sound_UpdateVoices();
    UpdateStreamVoiceVolume();
    Sound_UpdatePlayerChannels();
    Sound_FlushCommands(0);
}

void Sound_StopAllChannels(void) {
    M2C_UNK Sound_StopChannels(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Sound_WaitForCommand(s32);
    s32 Sound_GetQueueMark();
    M2C_UNK StopStreamChannels();
    s32 commandMark;

    /* Stop streamed playback and all remaining channels, then wait for the ARM7 to apply the stop. */
    StopStreamChannels();
    Sound_StopChannels(0, 0, 0, 0);
    commandMark = Sound_GetQueueMark();
    Sound_FlushCommands(1);
    Sound_WaitForCommand(commandMark);
}

void func_0202aa58(void) {
    M2C_UNK func_0202bc7c();
    func_0202bc7c();
}

/* Reserve the hardware channels in `channelMask` for the game: succeed trivially
 * when none are asked for, fail when any is already reserved, otherwise tell the
 * sound driver (its ARM7 side) to reserve them and record the mask as reserved. */
s32 Sound_ReserveChannels(s32 channelMask) {
 M2C_UNK Sound_Arm7ReserveChannels(M2C_UNK, M2C_UNK);
 extern M2C_UNK gSoundChannelMasks;
 if (!channelMask) return 1;
 if (channelMask & M2C_FIELD(&gSoundChannelMasks, s32 *, SOUND_CHANNEL_MASK_RESERVED)) return 0;
 Sound_Arm7ReserveChannels(channelMask, 0);
 { s32 v = M2C_FIELD(&gSoundChannelMasks, s32 *, SOUND_CHANNEL_MASK_RESERVED); channelMask = v | (u32)channelMask;
 M2C_FIELD(&gSoundChannelMasks, s32 *, SOUND_CHANNEL_MASK_RESERVED) = channelMask; }
 return 1;
}

/* Release the hardware channels in `channelMask` (and, on ARM7, tell the sound
 * driver to stop holding them), then clear them from the reserved mask. */
void Sound_ReleaseChannels(s32 channelMask) {
    M2C_UNK Sound_Arm7ReleaseChannels(M2C_UNK, M2C_UNK);
    extern M2C_UNK gSoundChannelMasks;
    M2C_UNK *masks;
    if (channelMask == 0) {
        return;
    }
    Sound_Arm7ReleaseChannels(channelMask, 0);
    masks = &gSoundChannelMasks;
    masks[SOUND_CHANNEL_MASK_RESERVED / 4] = masks[SOUND_CHANNEL_MASK_RESERVED / 4] & ~channelMask;
}

void func_0202aadc(s32 arg0) {
    extern s32 gSoundChannelMasks;
    gSoundChannelMasks &= ~arg0;
}

#pragma push
#pragma opt_common_subs off
/* Hand out the first free hardware channel (the lowest clear bit of the
 * allocated-channel mask), mark it allocated and return its index, or -1 when
 * none of the eight channels is free. */
s32 Sound_AllocChannel(void) {
    extern M2C_UNK gSoundChannelMasks;
    s32 mask = 1;
    s32 channel;
    for (channel = 0; channel < 8; channel++, mask <<= 1) {
        if (!(M2C_FIELD(&gSoundChannelMasks, u32 *, SOUND_CHANNEL_MASK_ALLOC) & mask)) {
            s32 inUse = M2C_FIELD(&gSoundChannelMasks, u32 *, SOUND_CHANNEL_MASK_ALLOC);
            mask = inUse | (u32)mask;
            M2C_FIELD(&gSoundChannelMasks, u32 *, SOUND_CHANNEL_MASK_ALLOC) = mask;
            return channel;
        }
    }
    return -1;
}
#pragma pop
void Sound_FreeChannel(s32 arg0) {
    extern M2C_UNK gSoundChannelMasks;
    M2C_UNK *g = &gSoundChannelMasks;
    M2C_UNK m = 1;
    g[1] = g[1] & ~(m << arg0);
}

void func_0202ab60(void) {
    extern M2C_UNK gSoundChannelMasks;
    M2C_FIELD(&gSoundChannelMasks, u32 *, 8) = 0;
    M2C_FIELD(&gSoundChannelMasks, u32 *, 0) = 0;
    M2C_FIELD(&gSoundChannelMasks, u32 *, 4) = 0;
}

void Sound_SetChannelMixVolume(s32 arg0, s8 arg1) {
    extern u8 data_0213b724[];
    data_0213b724[arg0 * 0x24] = (u8)arg1;
}

void func_0202ab94(s32 arg0, s32 arg1) {
    extern u8 data_0213b71c[];
    *(s32 *)(data_0213b71c + arg0 * 0x24) = (s32)(u16)arg1;
}

void func_0202abb4(s32 arg0, s32 arg1) {
    extern u8 data_0213b720[];
    *(s32 *)(data_0213b720 + arg0 * 0x24) = arg1;
}

/* Allocates one of a channel's preallocated sequence-player heaps: a sound data
 * block of heapSize usable bytes plus its node header, holding a heap that the
 * channel's sequence players claim through Sound_LinkVoiceChannel.  The node
 * waits on the channel's sequence list until a player takes it.  Returns 0 when
 * the block or the heap inside it cannot be created. */
s32 Sound_CreateChannelHeap(s32 channel, void *soundPlayer, s32 heapSize) {
    s32 ListAppend(s32, void *);
    s32 Sound_CreateHeap(void *, s32);
    void *Sound_AllocDataBlock(s32 *, s32, s32, s32, s32);
    extern M2C_UNK gSoundChannels;
    void Sound_FreeChannelHeap(void *, s32, s32, s32);
    void *node;
    s32 heap;

    node = Sound_AllocDataBlock((s32 *)soundPlayer, heapSize + SOUND_CHANNEL_HEAP_RESERVED, (s32)&Sound_FreeChannelHeap, 0, 0);
    if (node == 0) {
        return 0;
    }
    M2C_FIELD(node, s32 *, SOUND_CHANNEL_HEAP_OWNER) = 0;
    M2C_FIELD(node, s32 *, SOUND_CHANNEL_HEAP_CHANNEL) = channel;
    M2C_FIELD(node, s32 *, SOUND_CHANNEL_HEAP_HEAP) = 0;
    heap = Sound_CreateHeap((void *)((char *)node + SOUND_CHANNEL_HEAP_RESERVED), heapSize);
    if (heap == 0) {
        return 0;
    }
    M2C_FIELD(node, s32 *, SOUND_CHANNEL_HEAP_HEAP) = heap;
    ListAppend((s32)&gSoundChannels + channel * SOUND_CHANNEL_SIZE + SOUND_CHANNEL_SEQ_LIST, node);
    return 1;
}

void func_0202ac60(s32 *arg0) {
    M2C_UNK Sound_FadeOutVoice(s32);
    Sound_FadeOutVoice(*arg0);
}

/* Fade every active driver voice out over `fadeLength` frames; 0 releases the
 * voices at once. */
void Sound_FadeOutAllVoices(s32 fadeLength) {
    extern M2C_UNK gVoicePool;
    s32 i;
    u8 *voice;

    voice = (u8 *)&gVoicePool;
    i = 0;
    do {
        if (M2C_FIELD(voice, u8 *, SOUND_VOICE_STATE) != 0) {
            Sound_FadeOutVoice(voice, fadeLength);
        }
        i += 1;
        voice += SOUND_VOICE_SIZE;
    } while (SOUND_VOICE_COUNT > i);
}

void func_0202acb0(s32 *arg0) {
    *arg0 = 0;
}

void func_0202acbc(s32 * volatile *arg0) {
if(*arg0==NULL)return;
**arg0=0;
*arg0=NULL;
}

void func_0202acdc(void **arg0, s8 arg1) {
if (*(void * volatile *)arg0 != NULL) {
M2C_FIELD(*(void * volatile *)arg0,s8 *,0x41)=arg1;
}
}

void Sound_SetVoiceVolume(void **arg0, s8 arg1) {
    if (*(void * volatile *)arg0 != NULL) {
        M2C_FIELD(*(void * volatile *)arg0, s8 *, 0x40) = arg1;
    }
}

#pragma push
#pragma optimizewithasm off
#pragma peephole off
/* Fade the volume of the sound held by the `player` handle to `volume` (0..0x7F)
 * over `frames` frames.  A detached handle, or a voice that is already fading
 * out, is left alone; the fade envelope works in Q8.8, so the volume is scaled
 * up by 8 bits before it is handed over. */
void Sound_StartPlayerVolumeFade(void * volatile *player, s32 volume, s32 frames) {
 M2C_UNK Sound_StartFade(void *, s32, s32);
 void *voice;
 if (*player != 0) { voice=*player; if (M2C_FIELD(voice,u8 *,SOUND_VOICE_STATE)!=SOUND_VOICE_PLAYING) Sound_StartFade((u8 *)voice+SOUND_VOICE_ENVELOPE,volume<<8,frames); }
}
#pragma pop
void Sound_SetChannelPan(void * volatile *arg0, s32 arg1) {
M2C_UNK func_02008c50(u8,s32);
if(*arg0==NULL)return;
func_02008c50(M2C_FIELD(*arg0,u8 *,0x3c),arg1);
}

void func_0202ad50(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02008d94(u8, s32, s32);
    if (M2C_FIELD(arg0, s32 *, 0) == 0) return;
    func_02008d94(M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0x3C), arg1, arg2);
}

void func_0202ad70(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02008c68(u8, s32, s32);
    if (M2C_FIELD(arg0, s32 *, 0) == 0) return;
    func_02008c68(M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0x3C), arg1, arg2);
}

void Sound_SetPlayerPan(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02008c84(u8, s32, s32);
    if (M2C_FIELD(arg0, s32 *, 0) == 0) return;
    func_02008c84(M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0x3C), arg1, arg2);
}

#pragma opt_common_subs off
void Sound_SetSequenceSource(void **arg0, s32 arg1) {
    if (*(void * volatile *)arg0 == NULL) {
        return;
    }
    M2C_FIELD(*(void * volatile *)arg0, s16 *, 0x34) = 1;
    M2C_FIELD(*(void * volatile *)arg0, s16 *, 0x38) = arg1;
}
#pragma opt_common_subs reset
/* Record on the player that it plays sound entry `entryIndex` of sound archive
 * `archiveId`, so the player's restart callback can find the sound again.  A
 * detached player (a NULL handle) is left alone. */
void Sound_SetSoundSource(void **owner, s16 archiveId, s16 entryIndex) {
    if (*(void * volatile *)owner == NULL) {
        return;
    }
    M2C_FIELD(*(void * volatile *)owner, s16 *, SOUND_HANDLE_SOURCE_TYPE) = 2;
    M2C_FIELD(*(void * volatile *)owner, s16 *, SOUND_HANDLE_SOURCE_ARCHIVE) = archiveId;
    M2C_FIELD(*(void * volatile *)owner, s16 *, SOUND_HANDLE_SOURCE_ENTRY) = entryIndex;
}

