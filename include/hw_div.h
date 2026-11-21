#ifndef HW_DIV_H
#define HW_DIV_H

/* NDS hardware divider (ARM9).  Writing the numerator and denominator starts a
 * signed 32-bit division; the busy flag in DIVCNT clears when the quotient is
 * ready in DIV_RESULT.  The 64-bit denominator register is written whole so the
 * high word is cleared too. */
#define REG_DIVCNT      (*(volatile u16 *)0x04000280)
#define REG_DIV_NUMER   (*(volatile s32 *)0x04000290)
#define REG_DIV_DENOM   (*(volatile s64 *)0x04000298)
#define REG_DIV_RESULT  (*(volatile s32 *)0x040002A0)
#define REG_DIVREM_RESULT (*(volatile s32 *)0x040002A8)
#define DIVCNT_BUSY     0x8000

#endif
