/* The ov001 multiplayer room protocol's packets (handled in ov001_0216BD08.c): a
 * transfer carries a 12-byte prefix, the packet header and then its payload. */
#ifndef OV001_ROOM_H
#define OV001_ROOM_H

/* Packet header, counted from the end of the transfer prefix. */
#define OV001_PKT_MARKER  0x00 /* u16 big-endian: a packet with 0 here is ignored (1 in every packet this build writes) */
#define OV001_PKT_COMMAND 0x06 /* u16 big-endian command: 0x1010, 0x2010 or 0x3010 */
#define OV001_PKT_LENGTH  0x0a /* u16 big-endian bytes of the payload */
#define OV001_PKT_FLAGS   0x0c /* u16 big-endian transfer flags */
#define OV001_PKT_STATUS  0x0e /* u8 status byte carried with the flags */
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

/* Chunk kind whose payload is one player's user data, carried as a wrapped
 * packet of type OV001_USER_DATA_PACKET (see Ov001_UnpackUserDataPacket). */
#define OV001_CHUNK_USER_DATA 0x0a
#define OV001_USER_DATA_PACKET 0x70 /* low byte of the packet's big-endian type word */

/* The wrapped packet a room chunk's payload can carry: the 6-byte header the
 * WH packets use, a big-endian type word and payload length, then the bytes. */
#define OV001_PACKET_TYPE   0x00 /* u16 big-endian packet type */
#define OV001_PACKET_LENGTH 0x02 /* u16 big-endian bytes of payload */
#define OV001_PACKET_DATA   0x06 /* packet payload */

/* Bytes of the decoded record data of one room (four player entries). */
#define OV001_ROOM_PLAYER_DATA_SIZE 0x6a0

/* One player's 0x70-byte record (Ov001UnpackPlayerRecord fills it from that
 * player's chunk list): a 33-byte message and a 64-byte profile block. */
#define OV001_RECORD_DATA_LENGTH 0x04 /* u32: bytes of the profile block */
#define OV001_RECORD_TEXT        0x08 /* char[33]: the player's message */
#define OV001_RECORD_DATA        0x30 /* char[64]: the player's profile block */
#define OV001_RECORD_TEXT_MAX    0x21 /* bytes one message chunk may carry */
#define OV001_RECORD_DATA_MAX    0x40 /* bytes one profile chunk may carry */

/* Chunk kinds carrying those fields; the 0x40 and 0x45 kinds are the same chunk
 * in the second of the two parallel chunk sets (kinds x0..x5 and x0+0x10..). */
#define OV001_CHUNK_PROFILE      0x30
#define OV001_CHUNK_TEXT         0x35

/* gRoomState fields of the room session used by the request builders. */
#define OV001_TRANSFER_BUFFER 0x14 /* u8 *room transfer buffer, cleared before each request */
#define OV001_REQUEST_MASK    0x2c /* u32 room groups this client asks for */
#define OV001_ROOM_HOST_ADDR  0x34 /* s32 host-order IPv4 address of the room's host */
#define OV001_ROOM_PORT       0x5790 /* u16 UDP port the room protocol sends to */

/* Family byte of the socket address the room transfers are sent to. */
#define OV001_ADDR_FAMILY_INET 2

/* gRoomState's random-value sequence: seeded once from the real-time clock,
 * then one linear congruential step per random value the protocol needs. */
#define OV001_ROOM_RANDOM_READY 0x08 /* s32: nonzero once the sequence is seeded */
#define OV001_ROOM_RANDOM_STATE 0x18 /* u32: last value of the sequence */
#define OV001_ROOM_RANDOM_MUL   0x1c /* u32: sequence multiplier */
#define OV001_ROOM_RANDOM_ADD   0x20 /* u32: sequence increment */
#define OV001_ROOM_RANDOM_MULTIPLIER 0x5D588B65
#define OV001_ROOM_RANDOM_INCREMENT  0x269EC3

/* Bytes cleared in the transfer buffer before a request is written. */
#define OV001_TRANSFER_BYTES 0x5dc

/* Transfer command of the room-data request. */
#define OV001_CMD_ROOM_REQUEST 0x2000
/* Kind byte marking a room-protocol packet (value of OV001_PKT_KIND). */
#define OV001_PKT_KIND_ROOM 0x11

/* The built-in access-point profile InitBuiltinWifiAp fills from the hard-coded
 * SSID (gBuiltinWifiSsid) and WEP key (gBuiltinWifiKey). */
#define WIFI_AP_SSID_LENGTH 0x00 /* u32: bytes of the SSID text */
#define WIFI_AP_SSID        0x04 /* char[0x20]: network name */
#define WIFI_AP_SECURITY    0x24 /* u32: 1 = WEP security */
#define WIFI_AP_KEY_LENGTH  0x28 /* u32: bytes of the key text */
#define WIFI_AP_KEY         0x2c /* char[]: WEP key text, at most WIFI_AP_KEY_MAX bytes */
#define WIFI_AP_KEY_MAX     13   /* longest key accepted (104-bit WEP in ASCII) */

/* The request record the ov001 request builders fill in before the transfer is
 * written into the buffer: a status byte, a flag word and the transfer length
 * so far, followed by the record itself (a type byte, a zero byte, a
 * big-endian record length and a 32-bit value, the room group mask). */
typedef struct Ov001RequestWork {
    s8 status;      /* +0x00 */
    s16 flags;      /* +0x02 set once the record got a length prefix */
    s16 length;     /* +0x04 bytes written to the transfer buffer so far */
    u16 pad;        /* +0x06 */
    u8 type;        /* +0x08 record type */
    u8 zero;        /* +0x09 */
    s16 recordLen;  /* +0x0a record length, big-endian */
    s32 value;      /* +0x0c record value */
} Ov001RequestWork; /* 0x10 bytes */

#endif
