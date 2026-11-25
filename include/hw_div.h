#ifndef HW_DIV_H
#define HW_DIV_H

/* NDS hardware divider (ARM9).  Writing the numerator and denominator starts a
 * signed 32-bit division; the busy flag in DIVCNT clears when the quotient is
 * ready in DIV_RESULT.  The 64-bit denominator register is written whole so the
 * high word is cleared too. */
#define REG_DIVCNT      (*(volatile u16 *)0x04000280)
#define REG_DIV_NUMER   (*(volatile s32 *)0x04000290)
#define REG_DIV_NUMER64 (*(volatile s64 *)0x04000290) /* 64-bit numerator: writing a 32-bit value clears the high word, so the divide is unsigned */
#define REG_DIV_DENOM   (*(volatile s64 *)0x04000298)
#define REG_DIV_RESULT  (*(volatile s32 *)0x040002A0)
#define REG_DIVREM_RESULT (*(volatile s32 *)0x040002A8)
/* The 32-bit quotient and remainder read together as one 64-bit value (the
 * matrix code does this when it scales a quotient before splitting it). */
#define REG_DIV_RESULT64 (*(volatile u64 *)0x040002A0)
#define DIVCNT_BUSY     0x8000

/* The divider register block's base and the offsets the matrix code writes
 * through one base register to start a 64-by-32 divide (numeratorHigh << 32 over
 * the denominator).  DIVCNT's low bit selects the 64-bit numerator mode; the
 * denominator's second word is unused there and is cleared. */
#define DIV_REG_BASE     0x04000280 /* DIVCNT, the block's first register */
#define DIV_CNT_64BIT    1          /* DIVCNT: bit 0, 64-bit numerator mode */
#define DIV_NUMER_LOW    0x10       /* s32 low word of the 64-bit numerator */
#define DIV_NUMER_HIGH   0x14       /* s32 high word of the 64-bit numerator */
#define DIV_DENOM_LOW    0x18       /* s32 the 32-bit denominator */
#define DIV_DENOM_HIGH   0x1C       /* s32 second denominator word, unused in 64-by-32 mode */

#endif
