/* 32 functions from 0x0216BD08 to 0x0216CCE0 (ov001), found by ds-decomp. */
#pragma ipa off
#include "common.h"
#include "ov001_room.h"
extern unsigned char data_ov001_0218fd40[];
extern unsigned char data_ov001_0218fdb0[];
typedef struct PacketWork { signed char a; short b,c; unsigned short pad; unsigned char type,zero; short len; int value; } PacketWork;
extern unsigned char gOv001RoomPlayerData[];
extern unsigned char gOv001RoomRecords[];
typedef struct CipherState { unsigned int i, j; unsigned char *s; unsigned int n; } CipherState;
extern unsigned char gRoomState[];
extern signed char data_ov001_02191820[];
extern short data_ov001_02192568;
extern unsigned char data_ov001_0219256a[118];

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
int func_ov001_0216c6b8(int state, int session, int context) {
    void func_ov001_0216b918(int);
    void func_ov001_0216c88c(int, unsigned char *, int, short *, short *, int);
    void func_ov001_0216c8e0(unsigned short *, int, int, int, signed char, signed char, void *);
    void func_ov001_0216c938(int, int, int, int);
    int func_ov001_0216cc0c(void *, int, void *, int);
    int func_ov001_0216ce88(int);
    short func_ov001_0216ceb0(u16);
    void Ov001MemClear();
    void Ov001MemCopy();
    struct {
        PacketWork work;
        u8 token[8];
    } packet;
    u8 *buffer;

    packet.work.a = 0;
    packet.work.c = 0;
    packet.work.b = 0;
    buffer = M2C_FIELD(gRoomState, u8 **, 0x14);
    Ov001MemClear(&packet.work.type, 0, 8);
    Ov001MemClear(buffer, 0, 0x5dc);
    packet.work.type = 2;
    packet.work.zero = 0;
    packet.work.len = func_ov001_0216ceb0(4);
    packet.work.value = M2C_FIELD(gRoomState, int *, 0x2c);
    packet.work.value = func_ov001_0216ce88(packet.work.value);
    packet.work.c = 8;
    func_ov001_0216c88c(M2C_FIELD(gRoomState, int *, 0), buffer + 0x18,
                       (int)&packet.work.type, &packet.work.c, &packet.work.b, (int)&packet.work);
    Ov001MemCopy(packet.token, (void *)(session + 8), 8);
    if (func_ov001_0216cc0c(packet.token, 8, data_ov001_0218fdb0, 6)) {
        func_ov001_0216b918(2);
        return -1;
    }
    func_ov001_0216c8e0((unsigned short *)buffer, 0x2000, packet.work.c, packet.work.b, packet.work.a, 0x11, packet.token);
    packet.work.c += 0x18;
    func_ov001_0216c938((int)buffer, packet.work.c, 0, context);
    return 0;
}
