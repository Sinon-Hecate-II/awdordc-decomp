/* 58 functions from 0x02029E98 to 0x0202AE00 (main), found by ds-decomp. */
#include "common.h"
#include "exp_heap.h"
#include "sound.h"
typedef struct HeapRange { u8 *start; u8 *end; } HeapRange;

/* Initialise a heap header: store its signature, region and attribute, start its
 * child list and link the heap into the list of the heap that contains it (the
 * global heap list, initialised on first use, when no heap contains it). */
M2C_UNK InitHeapHead(void *heap, s32 signature, s32 start, M2C_UNK end, s32 attribute) {
    M2C_UNK ListInit(void *, s32);
    M2C_UNK ListAppend(M2C_UNK, void *);
    M2C_UNK GetHeapListForAddress(void *);
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
    ListAppend(GetHeapListForAddress(heap), heap);
}

M2C_UNK func_02029f14(void *arg0) {
    M2C_UNK GetHeapListForAddress(void *);
    M2C_UNK ListRemove(M2C_UNK, void *);
    ListRemove(GetHeapListForAddress(arg0), arg0);
}

void GetBlockRange(void *arg0, void *arg1) {
    s32 temp_r3 = (s32)(arg1 + 0x10);
    M2C_FIELD(arg0, s32 *, 0) = (s32) (arg1 - (u16) (((s32) M2C_FIELD(arg1, u16 *, 2) >> 8) & 0x7F));
    M2C_FIELD(arg0, s32 *, 4) = M2C_FIELD(arg1, s32 *, 4) + temp_r3;
}

void *UnlinkBlock(void *arg0, void *arg1) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg1, void **, 8);
    temp_r1 = M2C_FIELD(arg1, void **, 0xC);
    if (temp_r2 != NULL) {
        M2C_FIELD(temp_r2, void **, 0xC) = temp_r1;
    } else {
        M2C_FIELD(arg0, void **, 0) = temp_r1;
    }
    if (temp_r1 != NULL) {
        M2C_FIELD(temp_r1, void **, 8) = temp_r2;
    } else {
        M2C_FIELD(arg0, void **, 4) = temp_r2;
    }
    return temp_r2;
}

void *InsertBlock(void *arg0, void *arg1, void *arg2) {
    void *var_r3;

    M2C_FIELD(arg1, void **, 8) = arg2;
    if (arg2 != NULL) {
        var_r3 = M2C_FIELD(arg2, void **, 0xC);
        M2C_FIELD(arg2, void **, 0xC) = arg1;
    } else {
        var_r3 = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(arg0, void **, 0) = arg1;
    }
    M2C_FIELD(arg1, void **, 0xC) = var_r3;
    if (var_r3 != NULL) {
        M2C_FIELD(var_r3, void **, 8) = arg1;
    } else {
        M2C_FIELD(arg0, void **, 4) = arg1;
    }
    return arg1;
}

void *InitBlock(void *arg0, s16 arg1) {
    void *p = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(p, s16 *, 0) = arg1;
    M2C_FIELD(p, s16 *, 2) = 0;
    M2C_FIELD(p, s32 *, 4) = M2C_FIELD(arg0, s32 *, 4) - (s32)(p + 16);
    M2C_FIELD(p, s32 *, 8) = 0;
    M2C_FIELD(p, s32 *, 12) = 0;
    return p;
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

s32 func_0202a1d0(void *arg0, s32 arg1, s32 arg2) {
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

s32 func_0202a284(void *arg0, s32 arg1, s32 arg2) {
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
s32 func_0202a334(void *freeList, HeapRange *range)
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

void *func_0202a424(u32 arg0, u32 arg1, s32 arg2) {
    u32 end = (arg1 + arg0) & ~3;
    u32 start = (arg0 + 3) & ~3;
    if (start > end || end - start < 0x4C) return NULL;
    return CreateExpHeap((void *)start, end, arg2);
}

void func_0202a45c(void) {
    M2C_UNK func_02029f14();
    func_02029f14();
}

s32 func_0202a468(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0) arg1 = 1;
    arg1 = (arg1 + 3) & ~3;
    if (arg2 >= 0) return func_0202a1d0(arg0, arg1, arg2);
    return func_0202a284(arg0, arg1, -arg2);
}

void func_0202a498(s32 arg0, s32 arg1) {
    void GetBlockRange(void *, void *);
    void *UnlinkBlock(void *, void *);
    s32 func_0202a334(void *, HeapRange *);
    s32 temp_r4;
    s32 sp0[2];

    temp_r4 = arg1 - 0x10;
    GetBlockRange(sp0, (void *)temp_r4);
    UnlinkBlock((void *)(arg0 + 0x2C), (void *)temp_r4);
    func_0202a334((void *)(arg0 + 0x24), (HeapRange *)sp0);
}

#pragma opt_propagation off
s32 func_0202a4d4(void *arg0,u32 arg1) {
u32 old; u32 bit;
old=M2C_FIELD(arg0,u16 *,0x36);
bit=old&1;
M2C_FIELD(arg0,u16 *,0x36)=old & ~1;
M2C_FIELD(arg0,u16 *,0x36)=M2C_FIELD(arg0,u16 *,0x36)|(arg1&1);
return bit;
}
#pragma opt_propagation reset
void *func_0202a4fc(void *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK InitHeapHead();
    InitHeapHead(arg0, 0x46524D48, arg0 + 0x30, arg1, arg2);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    return arg0;
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

u32 AllocFromFrameHeapTail(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK CpuFill(M2C_UNK, u32, s32);
    u32 temp_r3;
    u32 temp_r5;
    u32 diff;

    temp_r3 = M2C_FIELD(arg0, u32 *, 4);
    temp_r5 = (u32)(~(arg2 - 1)) & (temp_r3 - arg1);
    if (temp_r5 < (u32)M2C_FIELD(arg0, u32 *, 0)) {
        return 0U;
    }
    diff = temp_r3 - temp_r5;
    if ((u8)M2C_FIELD(arg0, s32 *, -4) & 1) {
        CpuFill(0, temp_r5, diff);
    }
    M2C_FIELD(arg0, u32 *, 4) = temp_r5;
    return temp_r5;
}

void func_0202a5f8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
}

void func_0202a60c(void *arg0) {
    void *var_r2;

    var_r2 = M2C_FIELD(arg0, void **, 0x2C);
    if (var_r2 != NULL) {
        do {
            M2C_FIELD(var_r2, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
            var_r2 = M2C_FIELD(var_r2, void **, 0xC);
        } while (var_r2 != NULL);
    }
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x1C);
}

void *CreateFrameHeap(u32 arg0, u32 arg1, s32 arg2) {
    void *func_0202a4fc(void *, M2C_UNK, s32);
    u32 end = (arg1 + arg0) & ~3;
    u32 start = (arg0 + 3) & ~3;
    if (start > end || end - start < 0x30) return NULL;
    return func_0202a4fc((void *)start, (M2C_UNK)end, arg2);
}

void DestroyFrameHeap(void) {
    M2C_UNK func_02029f14();
    func_02029f14();
}

void Sound_HeapAlloc(void *arg0, s32 arg1, s32 arg2) {
    void *AllocFromFrameHeapHead(void *, M2C_UNK, M2C_UNK);
    u32 AllocFromFrameHeapTail(void *, s32, s32);
    if (arg1 == 0) {
        arg1 = 1;
    }
    arg1 = (arg1 + 3) & ~3;
    arg0 = (s8 *)arg0 + 0x24;
    if (arg2 >= 0) {
        AllocFromFrameHeapHead(arg0, (M2C_UNK)arg1, (M2C_UNK)arg2);
    } else {
        AllocFromFrameHeapTail(arg0, arg1, -arg2);
    }
}

void func_0202a6b0(void *arg0, s32 arg1) {
    void func_0202a5f8(void *);
    void func_0202a60c(void *);
    if (arg1 & 1) {
        func_0202a5f8(arg0);
    }
    if (arg1 & 2) {
        func_0202a60c(arg0);
    }
}

#pragma opt_propagation off
s32 func_0202a6dc(void *arg0, M2C_UNK arg1) {
 s32 Abs(M2C_UNK);
 s32 t; u32 value,end,mask;
 t=Abs(arg1)-1;
 value=M2C_FIELD(arg0,u32 *,0x24);
 mask=~t;
 t+=value;
 end=M2C_FIELD(arg0,u32 *,0x28);
 mask &=t;
 if(mask>end)return 0;
 return end-mask;
}
#pragma opt_propagation reset
s32 func_0202a714(void *arg0, s32 arg1) {
    void *AllocFromFrameHeapHead(void *, M2C_UNK, M2C_UNK);
    s32 temp_r4;
    void *temp_r0;

    temp_r4 = M2C_FIELD(arg0, s32 *, 0x24);
    temp_r0 = AllocFromFrameHeapHead(arg0 + 0x24, 0x10, 4);
    if (temp_r0 == NULL) {
        return 0;
    }
    M2C_FIELD(temp_r0, s32 *, 0) = arg1;
    M2C_FIELD(temp_r0, s32 *, 4) = temp_r4;
    M2C_FIELD(temp_r0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(temp_r0, void **, 0xC) = (void *) M2C_FIELD(arg0, void **, 0x2C);
    M2C_FIELD(arg0, void **, 0x2C) = temp_r0;
    return 1;
}

s32 func_0202a764(void *arg0, s32 arg1) {
    void *var_r3;

    var_r3 = M2C_FIELD(arg0, void **, 0x2C);
    if ((arg1 != 0) && (var_r3 != NULL)) {
loop_4:
        if (M2C_FIELD(var_r3, s32 *, 0) != arg1) {
            var_r3 = M2C_FIELD(var_r3, void **, 0xC);
            if (var_r3 != NULL) {
                goto loop_4;
            }
        }
    }
    if (var_r3 == NULL) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) M2C_FIELD(var_r3, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(var_r3, s32 *, 8);
    M2C_FIELD(arg0, void **, 0x2C) = (void *) M2C_FIELD(var_r3, void **, 0xC);
    return 1;
}

s32 func_0202a7b4(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0) != 0x4352414E) {
        return 0;
    }
    if (M2C_FIELD(arg0, u16 *, 4) != 0xFFFE) {
        return 0;
    }
    if (M2C_FIELD(arg0, u16 *, 6) == 0x100) {
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
    if (func_0202a7b4(data) == 0) {
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

s32 func_0202a940(M2C_UNK arg0) {
    M2C_UNK ReleaseArchiveName(M2C_UNK);
    s32 func_0200b32c();
    if (func_0200b32c() == 0) {
        return 0;
    }
    ReleaseArchiveName(arg0);
    return 1;
}

/* Sets the sound driver up once: shorts out if it is already up, initializes the
 * sound command queue, installs the handlers that reset the driver's channels,
 * then starts the voice allocator and the streamed sound state.  The driver's id
 * (-1 = none) and state are left at their start values. */
void InitSoundDriver(void) {
    M2C_UNK func_02008fcc(M2C_UNK);
    M2C_UNK func_0200ee10(M2C_UNK);
    M2C_UNK func_0200ee28(M2C_UNK);
    void func_0202ab60(void);
    M2C_UNK func_0202ba8c(void);
    M2C_UNK Sound_InitVoices(void);
    void func_0202aa20(void);
    void func_0202aa58(void);
    extern M2C_UNK gSoundInitState;
    extern M2C_UNK data_02138eb0;
    extern M2C_UNK data_02138ebc;
    if (M2C_FIELD(&gSoundInitState, s32 *, SOUND_INIT_DONE) != 0) {
        return;
    }
    M2C_FIELD(&gSoundInitState, s32 *, SOUND_INIT_DONE) = 1;
    func_02008fcc((M2C_UNK)&gSoundInitState);
    M2C_FIELD(&gSoundInitState, void **, SOUND_INIT_STOP) = (void *)func_0202aa20;
    M2C_FIELD(&gSoundInitState, s32 *, 0x14) = 0;
    M2C_FIELD(&gSoundInitState, void **, SOUND_INIT_SILENCE) = (void *)func_0202aa58;
    M2C_FIELD(&gSoundInitState, s32 *, 0x20) = 0;
    func_0200ee10((M2C_UNK)&data_02138eb0);
    func_0200ee28((M2C_UNK)&data_02138ebc);
    func_0202ab60();
    func_0202ba8c();
    Sound_InitVoices();
    M2C_FIELD(&gSoundInitState, s8 *, 0) = -1;
    M2C_FIELD(&gSoundInitState, s32 *, 4) = 1;
}

void func_0202a9f0(void) {
    s32 Sound_DequeueCommand(M2C_UNK);
    M2C_UNK Sound_FlushCommands(M2C_UNK);
    M2C_UNK Sound_UpdateVoices();
    M2C_UNK UpdateStreamVoiceVolume();
    M2C_UNK func_0202d9e4();
    do {

    } while (Sound_DequeueCommand(0) != 0);
    Sound_UpdateVoices();
    UpdateStreamVoiceVolume();
    func_0202d9e4();
    Sound_FlushCommands(0);
}

void func_0202aa20(void) {
    M2C_UNK Sound_StopChannels(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK Sound_WaitForCommand(s32);
    s32 Sound_GetCommandCounter();
    M2C_UNK StopStreamChannels();
    s32 temp_r4;

    StopStreamChannels();
    Sound_StopChannels(0, 0, 0, 0);
    temp_r4 = Sound_GetCommandCounter();
    Sound_FlushCommands(1);
    Sound_WaitForCommand(temp_r4);
}

void func_0202aa58(void) {
    M2C_UNK func_0202bc7c();
    func_0202bc7c();
}

s32 Sound_ReserveChannels(s32 arg0) {
 M2C_UNK func_02008dbc(M2C_UNK, M2C_UNK);
 extern M2C_UNK data_0213b2a0;
 if (!arg0) return 1;
 if (arg0 & M2C_FIELD(&data_0213b2a0, s32 *, 8)) return 0;
 func_02008dbc(arg0, 0);
 { s32 v = M2C_FIELD(&data_0213b2a0, s32 *, 8); arg0 = v | (u32)arg0;
 M2C_FIELD(&data_0213b2a0, s32 *, 8) = arg0; }
 return 1;
}

void func_0202aaac(s32 arg0) {
    M2C_UNK func_02008ddc(M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0213b2a0;
    M2C_UNK *g;
    if (arg0 == 0) {
        return;
    }
    func_02008ddc(arg0, 0);
    g = &data_0213b2a0;
    g[2] = g[2] & ~arg0;
}

void func_0202aadc(s32 arg0) {
    extern s32 data_0213b2a0;
    data_0213b2a0 &= ~arg0;
}

#pragma push
#pragma opt_common_subs off
s32 Sound_AllocChannel(void) {
 extern M2C_UNK data_0213b2a0;
 s32 mask = 1;
 s32 i;
 for (i=0; i<8; i++, mask <<= 1) {
  if (!(M2C_FIELD(&data_0213b2a0, u32 *, 4) & mask)) {
   s32 v = M2C_FIELD(&data_0213b2a0, u32 *, 4);
   mask = v | (u32)mask;
   M2C_FIELD(&data_0213b2a0, u32 *, 4) = mask;
   return i;
  }
 }
 return -1;
}
#pragma pop
void func_0202ab40(s32 arg0) {
    extern M2C_UNK data_0213b2a0;
    M2C_UNK *g = &data_0213b2a0;
    M2C_UNK m = 1;
    g[1] = g[1] & ~(m << arg0);
}

void func_0202ab60(void) {
    extern M2C_UNK data_0213b2a0;
    M2C_FIELD(&data_0213b2a0, u32 *, 8) = 0;
    M2C_FIELD(&data_0213b2a0, u32 *, 0) = 0;
    M2C_FIELD(&data_0213b2a0, u32 *, 4) = 0;
}

void func_0202ab7c(s32 arg0, s8 arg1) {
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
    M2C_UNK func_0202b10c(s32);
    func_0202b10c(*arg0);
}

void func_0202ac70(M2C_UNK arg0) {
    extern M2C_UNK gVoicePool;
    s32 var_r4;
    u8 *var_r5;

    var_r5 = (u8 *)&gVoicePool;
    var_r4 = 0;
    do {
        if (M2C_FIELD(var_r5, u8 *, 0x2C) != 0) {
            func_0202b10c(var_r5, arg0);
        }
        var_r4 += 1;
        var_r5 += 0x44;
    } while (0x10 > var_r4);
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
void Sound_StartPlayerVolumeFade(void * volatile *arg0, s32 arg1, s32 arg2) {
 M2C_UNK func_0202eed8(void *, s32, s32);
 void *p;
 if (*arg0 != 0) { p=*arg0; if (M2C_FIELD(p,u8 *,0x2C)!=2) func_0202eed8((u8 *)p+0x1C,arg1<<8,arg2); }
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

void func_0202ad90(void *arg0, s32 arg1, s32 arg2) {
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
void Sound_SetSoundSource(void **arg0, s16 arg1, s16 arg2) {
    if (*(void * volatile *)arg0 == NULL) {
        return;
    }
    M2C_FIELD(*(void * volatile *)arg0, s16 *, 0x34) = 2;
    M2C_FIELD(*(void * volatile *)arg0, s16 *, 0x38) = arg1;
    M2C_FIELD(*(void * volatile *)arg0, s16 *, 0x3A) = arg2;
}

