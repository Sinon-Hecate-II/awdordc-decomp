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

/* Heap signature (u32 at heap+0x00). */
#define HEAP_SIGNATURE_EXP 0x45585048 /* 'EXPH' */

#endif
