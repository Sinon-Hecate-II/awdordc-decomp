/* The ov001 multiplayer room protocol's packets (handled in ov001_0216BD08.c): a
 * transfer carries a 12-byte prefix, the packet header and then its payload. */
#ifndef OV001_ROOM_H
#define OV001_ROOM_H

/* Packet header, counted from the end of the transfer prefix. */
#define OV001_PKT_COMMAND 0x06 /* u16 big-endian command: 0x1010, 0x2010 or 0x3010 */
#define OV001_PKT_LENGTH  0x0a /* u16 big-endian bytes of the payload */
#define OV001_PKT_KIND    0x0f /* u8 kind; 17 marks a room-protocol packet */
#define OV001_PKT_TOKEN   0x10 /* 8-byte player token the packet answers */

/* Bytes of a transfer before its packet header, and of the packet header before
 * its payload. */
#define OV001_PKT_PREFIX  0x0c
#define OV001_PKT_HEADER  0x18

/* The payload's chunk record: kind, big-endian payload bytes, status. */
#define OV001_CHUNK_KIND   0x00 /* u8 kind */
#define OV001_CHUNK_LENGTH 0x02 /* u16 big-endian bytes that follow the 4-byte header */
#define OV001_CHUNK_STATUS 0x04 /* s32 big-endian result, set on a failed request */
#define OV001_CHUNK_DATA   0x06 /* chunk contents */

/* Chunk kind reporting that the request failed; OV001_CHUNK_STATUS says why. */
#define OV001_CHUNK_ERROR 7

/* Bytes of the decoded record data of one room (four player entries). */
#define OV001_ROOM_PLAYER_DATA_SIZE 0x6a0

#endif
