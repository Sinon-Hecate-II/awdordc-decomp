/* 32 functions from 0x0216BD08 to 0x0216CCE0 (ov001), found by ds-decomp. */
#pragma ipa off
#include "common.h"
#include "ov001_room.h"
extern unsigned char data_ov001_0218fd40[];
extern unsigned char data_ov001_0218fdb0[];
extern unsigned char gOv001RoomPlayerData[];
extern unsigned char gOv001RoomRecords[];
typedef struct CipherState { unsigned int i, j; unsigned char *s; unsigned int n; } CipherState;
extern unsigned char gRoomState[];
extern signed char data_ov001_02191820[];
extern short gOv001CryptSeed;
extern unsigned char gOv001CryptKeyTail[118];

#pragma thumb on
/* State-1 handler of the multiplayer room protocol: accept only a room-data
 * packet addressed to this player, report the status of a failed request, else
 * unpack the room records and move on to state 2 once a requested group arrived. */

#pragma thumb on

#pragma opt_lifetimes off

#pragma opt_lifetimes reset

#pragma thumb on
/* Walks the chunk list of one player's room data and copies its strings into
 * the per-player record: the message string (chunk 0x15/0x25, up to 33 bytes
 * with the last byte NUL) to +0x08, and four slots to +0x30/+0x70/+0xB0/+0xF0
 * holding either a 5-byte (chunk 0x10-0x13) or a 13-byte (0x20-0x23) string;
 * the slot length is stored at +0x04. Chunks chain through a big-endian offset
 * at +0x04 of each chunk until it is zero. */

#pragma thumb on

#pragma thumb on

#pragma thumb on
/* Build and send the room-data request for this player: fill the room request
 * record (type 2, the room group mask from gRoomState) into the room transfer
 * buffer, append this player's 8-byte session token, then post the transfer. */
int Ov001_SendRoomRequest(int state, int session, int context) {
    void Ov001_SetRoomError(int);
    void func_ov001_0216c88c(int, unsigned char *, int, short *, short *, int);
    void func_ov001_0216c8e0(unsigned short *, int, int, int, signed char, signed char, void *);
    void func_ov001_0216c938(int, int, int, int);
    int func_ov001_0216cc0c(void *, int, void *, int);
    int Ov001SwapEndian32(int);
    short func_ov001_0216ceb0(u16);
    void Ov001MemClear();
    void Ov001MemCopy();
    struct {
        Ov001RequestWork work;
        u8 token[8];
    } packet;
    u8 *buffer;

    packet.work.status = 0;
    packet.work.length = 0;
    packet.work.flags = 0;
    buffer = M2C_FIELD(gRoomState, u8 **, OV001_TRANSFER_BUFFER);
    Ov001MemClear(&packet.work.type, 0, 8);
    Ov001MemClear(buffer, 0, OV001_TRANSFER_BYTES);
    packet.work.type = 2;
    packet.work.zero = 0;
    packet.work.recordLen = func_ov001_0216ceb0(4);
    packet.work.value = M2C_FIELD(gRoomState, int *, OV001_REQUEST_MASK);
    packet.work.value = Ov001SwapEndian32(packet.work.value);
    packet.work.length = 8;
    func_ov001_0216c88c(M2C_FIELD(gRoomState, int *, 0), buffer + OV001_PKT_HEADER,
                       (int)&packet.work.type, &packet.work.length, &packet.work.flags, (int)&packet.work);
    Ov001MemCopy(packet.token, (void *)(session + 8), 8);
    if (func_ov001_0216cc0c(packet.token, 8, data_ov001_0218fdb0, 6)) {
        Ov001_SetRoomError(2);
        return -1;
    }
    func_ov001_0216c8e0((unsigned short *)buffer, OV001_CMD_ROOM_REQUEST, packet.work.length, packet.work.flags, packet.work.status, OV001_PKT_KIND_ROOM, packet.token);
    packet.work.length += OV001_PKT_HEADER;
    func_ov001_0216c938((int)buffer, packet.work.length, 0, context);
    return 0;
}
