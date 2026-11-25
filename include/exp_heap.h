/* Block header of the ExpHeap allocator in main_02029E98.c.  A block is a
 * 0x10-byte header followed by its payload: the signature at +0x00, the
 * attribute word at +0x02, the payload size at +0x04, and the free/used list
 * links at +0x08 and +0x0C. */
#ifndef EXP_HEAP_H
#define EXP_HEAP_H

/* Block signatures (u16 at block+0x00). */
#define HEAP_BLOCK_FREE 0x4652 /* 'FR': block sits on a free list */
#define HEAP_BLOCK_USED 0x5544 /* 'UD': allocated block */

/* HEAP_BLOCK_ATTR bits (u16 at block+0x02). */
#define HEAP_BLOCK_ATTR_TAG       0x00ff /* low byte: heap tag copied from the heap */
#define HEAP_BLOCK_ATTR_OFFSET    0x7f00 /* bits 8..14: alignment bytes absorbed in front of the block */
#define HEAP_BLOCK_ATTR_FROM_TAIL 0x8000 /* bit 15: block was allocated from the tail */

#define HEAP_BLOCK_HEADER_SIZE 0x10 /* bytes of header in front of a block's payload */

/* Heap signature (u32 at heap+0x00). */
#define HEAP_SIGNATURE_EXP 0x45585048 /* 'EXPH' */
#define HEAP_SIGNATURE_FRM 0x46524D48 /* 'FRMH': frame heap, see InitFrameHeapArea */

/* Heap-containment links of an expanded heap's header.  InitHeapHead starts the
 * heap's child list at +0x0C and links the heap into the list of the heap that
 * contains it through +0x04 (next) and +0x08 (previous); the link offset those
 * lists use is 4, so the list nodes are the heaps themselves. */
#define HEAP_LINK_NEXT  0x04 /* void *next heap in the list that contains this one */
#define HEAP_LINK_PREV  0x08 /* void *previous heap */
#define HEAP_CHILD_LIST 0x0c /* list header of the heaps contained in this one */

/* Field offsets of an expanded heap's header (the object CreateExpHeap sets up). */
#define HEAP_AREA_START 0x18 /* s32 first byte of the heap's memory area */
#define HEAP_AREA_END   0x1c /* s32 last byte of the area */
#define HEAP_FREE_LIST  0x24 /* void *head of the free-block list; +0x04 is its tail */
#define HEAP_USED_LIST  0x2c /* void *head of the used-block list; +0x04 is its tail */
#define HEAP_FLAGS      0x36 /* u16; bit 0: search the whole free list for the smallest block that fits */

/* Allocator state of a frame heap (the 'FRMH' heap CreateFrameHeap sets up),
 * reached through the pointer stored at heap+0x24.  Head allocations grow the
 * frame upward from `head`; tail allocations move `tail` down to meet them.  The
 * heap's attribute byte lives 4 bytes before this struct, at heap+0x20. */
typedef struct FrameHeap {
    u32 head; /* +0x00 first free byte of the frame; a front allocation advances it */
    u32 tail; /* +0x04 last free byte of the frame; a tail allocation moves it down */
} FrameHeap;

#define FRAME_HEAP_HEAD 0x24 /* u32 first free byte of the frame (FrameHeap::head) */
#define FRAME_HEAP_TAIL 0x28 /* u32 last free byte of the frame (FrameHeap::tail) */
#define FRAME_HEAP_DATA 0x30 /* first byte of the frame heap's allocatable area (the header ends here) */
#define FRAME_HEAP_ATTRIBUTE     (-4)  /* heap+0x20: the heap attribute byte (see InitHeapHead) */
#define FRAME_HEAP_ATTR_ZERO_FILL 0x01 /* attribute bit 0: clear freshly allocated bytes */

/* A recorded frame-heap state: RecordFrameHeapState allocates one of these from
 * the heap itself, tags it with the caller's tag and pushes it on the heap's
 * state list at heap+0x2C; the matching unrecord call finds a node by tag and
 * restores the head and tail it saved. */
#define FRAME_HEAP_STATE_LIST 0x2c /* void *head of the recorded-state list */
#define FRAME_HEAP_STATE_SIZE 0x10 /* bytes of one recorded-state node */
#define FRAME_HEAP_STATE_TAG  0x00 /* u32 tag the state was recorded under */
#define FRAME_HEAP_STATE_HEAD 0x04 /* u32 saved frame-heap head */
#define FRAME_HEAP_STATE_TAIL 0x08 /* u32 saved frame-heap tail */
#define FRAME_HEAP_STATE_NEXT 0x0c /* void *next recorded-state node */

#endif
