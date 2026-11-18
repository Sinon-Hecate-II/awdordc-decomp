/* The ov001 single-card (Download Play) link work block (gOv001LinkWork): a
 * seven-u16 header of per-player bitmaps (bit n = player n) that the link state
 * machine moves each player through, then the per-player records and the
 * multiboot buffers. */
#ifndef OV001_LINK_H
#define OV001_LINK_H

/* Header words. Each holds one bit per player index; a player changes from one
 * group to the next as the match setup and the leave handshake progress. */
#define OV001_LINK_STATUS        0x00 /* u16: Ov001_SetLinkStatus value */
#define OV001_LINK_JOINED        0x02 /* players in the link */
#define OV001_LINK_KICKED        0x04 /* players kicked out of it */
#define OV001_LINK_KICK_PENDING  0x06 /* players whose kick awaits their acknowledge */
#define OV001_LINK_KICK_ANSWERED 0x08 /* players that acknowledged the kick */
#define OV001_LINK_READY         0x0a /* players ready to start */
#define OV001_LINK_JOINED_COPY   0x0c /* second joined map, must equal +2 when the link ends */

/* Per-player records that follow the header, OV001_LINK_RECORD_SIZE bytes each,
 * player 1 first. */
#define OV001_LINK_RECORDS          0x0e /* work-block offset of the first record */
#define OV001_LINK_RECORD_SIZE      0x1e
#define OV001_LINK_RECORD_INFO      0x00 /* 0x16-byte block copied from the multiboot record */
#define OV001_LINK_RECORD_INFO_SIZE 0x16
#define OV001_LINK_RECORD_ADDRESS   0x16 /* six-byte peer link address from the join request */
#define OV001_LINK_RECORD_ID        0x1c /* u16 one-based player id, 0 while the slot is unused */

/* Multiboot buffers inside the work block. */
#define OV001_LINK_TRANSFER      0x1b140 /* void *: buffer handed to MultiBoot_StartParent */
#define OV001_LINK_PROGRAM       0x1b144 /* void *: program image loaded at work +0x2c */

#endif
