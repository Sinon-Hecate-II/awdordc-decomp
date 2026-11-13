/* The sprite animation script engine (main_0208FE7C / main_02090E0C): a sprite
 * object owns a list of 0x30-byte script players.  Each player walks a script of
 * 0x10-byte entries and can spawn child players that share the same script. */
#ifndef SPRITE_SCRIPT_H
#define SPRITE_SCRIPT_H

/* Fields of one script player (allocated 0x30 bytes by the engine). */
#define SPRITE_PLAYER_OWNER        0x00 /* void *sprite object; its +0x38 holds this list */
#define SPRITE_PLAYER_PREV         0x04 /* void *previous player in the list */
#define SPRITE_PLAYER_NEXT         0x08 /* void *next player in the list */
#define SPRITE_PLAYER_SCRIPT       0x0C /* u8 *script data */
#define SPRITE_PLAYER_CURSOR       0x10 /* u8 *current 0x10-byte script entry */
#define SPRITE_PLAYER_FRAME_TABLE  0x14 /* u8 *script plus the header's base offset */
#define SPRITE_PLAYER_FRAME        0x18 /* u8 *frame selected by the current wait entry */
#define SPRITE_PLAYER_DELAY        0x1C /* s32 frames left in the current wait */
#define SPRITE_PLAYER_X            0x20 /* s16 x */
#define SPRITE_PLAYER_Y            0x22 /* s16 y */
#define SPRITE_PLAYER_X_HIGH       0x24 /* u16 high half of x */
#define SPRITE_PLAYER_Y_HIGH       0x26 /* u16 high half of y */
#define SPRITE_PLAYER_TILE         0x28 /* u16 tile/attribute passed to the sprite */
#define SPRITE_PLAYER_PRIORITY     0x2A /* s8 draw priority */
#define SPRITE_PLAYER_PRIORITY_ADD 0x2B /* u8 added to the priority when drawn */
#define SPRITE_PLAYER_SLOT         0x2C /* u8 script slot index */
#define SPRITE_PLAYER_FLAGS        0x2D /* u8 SPRITE_PLAYER_FLAG_* */
#define SPRITE_PLAYER_SIZE         0x30 /* allocation size */

/* Fields of the sprite object that owns a player list. */
#define SPRITE_OWNER_PLAYER_LIST   0x38 /* void *first script player */
#define SPRITE_OWNER_AUX_LIST      0x3C /* void *list of auxiliary sprite objects */

/* Fields of one script entry (0x10 bytes).  Byte 2 is the frame index while the
 * entry is a wait (kind == 0) and the command id while it is a command. */
#define SPRITE_ENTRY_SIZE     0x10 /* size of one script entry */
#define SPRITE_ENTRY_WAIT     0x00 /* u16 frames to wait */
#define SPRITE_ENTRY_COMMAND  0x02 /* u8 command id / frame index */
#define SPRITE_ENTRY_KIND     0x03 /* u8 nonzero for a command entry */
#define SPRITE_ENTRY_OFFSET   0x04 /* s32 relative offset */
#define SPRITE_ENTRY_ARG      0x06 /* s16 command argument */

/* SPRITE_ENTRY_COMMAND values for command entries. */
#define SPRITE_SCRIPT_STOP   0x00 /* stop the player */
#define SPRITE_SCRIPT_JUMP   0x01 /* jump to the entry of the player's script slot */
#define SPRITE_SCRIPT_RETURN 0x02 /* finish the player */
#define SPRITE_SCRIPT_SKIP   0x03 /* no-op, advance past the entry */
#define SPRITE_SCRIPT_SEARCH 0x04 /* scan for the entry whose argument matches */
#define SPRITE_SCRIPT_SPAWN  0x10 /* spawn arg child players */
#define SPRITE_SCRIPT_SET    0x11 /* set SPRITE_PLAYER_PRIORITY_ADD from the argument */
#define SPRITE_SCRIPT_LOOP   0xFF /* loop back to the start / stop the player */

/* SPRITE_PLAYER_FLAGS bits. */
#define SPRITE_PLAYER_FLAG_HIDDEN 0x01 /* skip drawing this player */
#define SPRITE_PLAYER_FLAG_3D     0x02 /* draw with the 3D sprite helper */

#endif
