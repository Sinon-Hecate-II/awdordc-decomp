/* 32 functions from 0x0216BD08 to 0x0216CCE0 (ov001), found by ds-decomp. */
#pragma ipa off
#include "common.h"
#include "ov001_room.h"
extern unsigned char data_ov001_0218fd40[];
extern unsigned char gBuiltinWifiKey[];
typedef struct PacketWork { signed char a; short b,c; unsigned short pad; unsigned char type,zero; short len; int value; } PacketWork;
extern unsigned char gOv001RoomPlayerData[];
extern unsigned char gOv001RoomRecords[];
/* RC4 cipher state: the two state indices (i and j), the 256-byte S-box
 * permutation and the modulus the indices wrap at (the message length). */
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

/* Write the room request's payload into the transfer buffer: when the room's
 * encryption mode is on, encrypt the payload in place behind its big-endian
 * length, record the encryption checksum and flags, and grow the length by the
 * 4-byte prefix; otherwise copy the payload unchanged. */
void Ov001_WriteRoomPayload(int mode, unsigned char *dest, int src, short *length, short *flags, int checksum) {
 int Ov001_EncryptRoomData();
 void Ov001MemCopy();
 short Ov001SwapEndian16Alt(unsigned short);
 extern unsigned char data_ov001_02192560[8];
 if(mode == 1) {
 *flags = 1;
 Ov001_EncryptRoomData(src,dest+4,*length,checksum,dest+2,data_ov001_02192560,8);
 *(short *)dest = Ov001SwapEndian16Alt((unsigned short)*length);
 *length += 4;
 return;
 }
 Ov001MemCopy(dest,src,*length);
}

/* Fill a room-protocol packet header at `header`: the big-endian marker 1 and
 * command, the transfer length, flags, status and kind bytes, and the 8-byte
 * player token the packet answers. */
void Ov001_WriteRoomPacketHeader(u16 *header,int command,int length,int flags,signed char status,signed char kind,void *token) {
 short Ov001SwapEndian16Alt(unsigned short);
 void Ov001MemCopy();
 header[0]=Ov001SwapEndian16Alt(1); header[1]=0; header[2]=0;
 header[3]=Ov001SwapEndian16Alt((unsigned short)command); header[4]=0;
 header[5]=Ov001SwapEndian16Alt((unsigned short)length);
 header[6]=Ov001SwapEndian16Alt((unsigned short)flags);
 ((signed char *)header)[OV001_PKT_STATUS]=status; ((signed char *)header)[OV001_PKT_KIND]=kind;
 Ov001MemCopy(header+8,token,8);
}

/* Sends a room transfer to the room's host: builds the host's 8-byte socket
   address (AF_INET, the fixed room port, and the host's address - or none when the
   player is unset or the host address has not been received) and posts the
   transfer to it. */
void Ov001_SendRoomTransfer(int transfer,int length,int player,int context) {
 void Ov001MemClear();
 void Ov001_SendToAddress();
 int Ov001SwapEndian32(int);
 short Ov001SwapEndian16Alt(unsigned short);
 int addr[2];
 Ov001MemClear(addr,0,8);
 ((char *)addr)[1]=OV001_ADDR_FAMILY_INET;
 ((short *)addr)[1]=Ov001SwapEndian16Alt(OV001_ROOM_PORT);
 addr[1]=Ov001SwapEndian32(M2C_FIELD(gRoomState,int *,OV001_ROOM_HOST_ADDR));
 if(player==255 || data_ov001_02191820[0x1c]==0) addr[1]=-1;
 Ov001_SendToAddress(context,transfer,length,0,addr,8);
}

#pragma thumb on
/* Encrypt one room-protocol payload: store the payload checksum in *checksum,
 * seed the RC4 cipher from a fresh random 16-bit value plus the caller's key
 * tail, then encrypt src into dst.  Returns 0, or -1 when the cipher buffer
 * can't be allocated. */
int Ov001_EncryptRoomData(int src,int dst,int length,signed char *checksum,void *seedOut,void *keyTail,int keyTailLength) {
 int func_ov001_0216ad54(int); void func_ov001_0216ad64(int);
 void Ov001Rc4Init(); void func_ov001_0216cb08();
 int func_ov001_0216cb74(int,int); short Ov001GetRandomSeed(void); void Ov001MemCopy();
 int state; int cipher[4]; short seed;
 *checksum=func_ov001_0216cb74(src,length); state=func_ov001_0216ad54(length); cipher[2]=state;
 if(!state) return -1;
 seed=Ov001GetRandomSeed(); Ov001MemCopy(seedOut,&seed,2);
 Ov001MemCopy(&gOv001CryptSeed,seedOut,2);
 Ov001MemCopy(gOv001CryptKeyTail,keyTail,keyTailLength);
 Ov001Rc4Init(cipher,&gOv001CryptSeed,keyTailLength+2,length);
 func_ov001_0216cb08(cipher,dst,src,length); func_ov001_0216ad64(cipher[2]); return 0;
}

#pragma thumb on
/* RC4-decrypts a room-protocol payload: builds the cipher state from a 2-byte
 * seed plus the caller's key tail, decrypts src into dst and verifies the
 * plaintext checksum.  Returns 0, or -1 after setting a room error. */
int Ov001_DecryptRoomData(int src,int dst,int length,unsigned int expectedChecksum,void *seed,void *keyTail,int keyTailLength) {
 int func_ov001_0216ad54(int); void func_ov001_0216ad64(int); void Ov001_SetRoomError(int);
 void Ov001Rc4Init(); void func_ov001_0216cb08(); int func_ov001_0216cb74(int,int); void Ov001MemCopy();
 int cipher[4]; int state=func_ov001_0216ad54(length); cipher[2]=state;
 if(!state) {Ov001_SetRoomError(2); return -1;}
 Ov001MemCopy(&gOv001CryptSeed,seed,2);
 Ov001MemCopy(gOv001CryptKeyTail,keyTail,keyTailLength);
 Ov001Rc4Init(cipher,&gOv001CryptSeed,keyTailLength+2,length);
 func_ov001_0216cb08(cipher,dst,src,length);
 if((int *)func_ov001_0216cb74(dst,length)!=(int *)expectedChecksum) {
 Ov001_SetRoomError(0x12); func_ov001_0216ad64(cipher[2]); return -1;
 }
 func_ov001_0216ad64(cipher[2]); return 0;
}
/* RC4 key schedule (the KSA permutation): fill the state's S-box with 0..n-1,
 * then shuffle it with the key bytes, wrapping the key index at `len`. */
void Ov001Rc4Init(CipherState *st, unsigned char *key, unsigned int len, unsigned int n) {
    unsigned char *s = st->s;
    unsigned int index, swapIndex, keyIndex;
    unsigned char t, u;
    st->j = 0;
    st->i = 0;
    st->n = n;
    for (index = 0; index < n; index++) s[index] = index;
    swapIndex = 0;
    keyIndex = 0;
    for (index = 0; index < n; index++) {
        t = s[index];
        swapIndex = (swapIndex + key[keyIndex] + t) % st->n;
        u = s[swapIndex];
        s[swapIndex] = t;
        s[index] = u;
        keyIndex++;
        if (keyIndex >= len) keyIndex = 0;
    }
}

#pragma thumb on
/* RC4 keystream generator (the PRGA step): advance the cipher state's indices,
 * swap the two S-box bytes they point at, and return the next keystream byte. */
unsigned int Ov001Rc4NextByte(CipherState *st) {
    unsigned int n = st->n;
    unsigned char *s = st->s;
    unsigned char i = (st->i + 1) % n;
    unsigned char a = s[i];
    unsigned char j = (a + st->j) % n;
    unsigned char b = s[j];

    st->i = i;
    st->j = j;
    s[j] = a;
    s[i] = b;
    return s[(a + b) % st->n];
}
#pragma thumb off

#pragma thumb on
/* CRC-32 update with the reflected polynomial 0xEDB88320: fold `length` bytes of
 * `data` into the running `crc` one byte at a time, building the 256-entry lookup
 * table on first use (when `tableReady` is zero). */
unsigned int Ov001_Crc32Update(unsigned int crc, unsigned char *data, int length, int tableReady, unsigned int *table) {
    void Ov001_BuildCrc32Table(int, unsigned int *);
    int i;
    if (!tableReady) Ov001_BuildCrc32Table(tableReady, table);
    for (i = 0; i < length; i++) crc = (crc >> 8) ^ table[(unsigned char)(data[i] ^ crc)];
    return crc;
}

/* Obfuscate the `size`-byte buffer `data` in place with a simple keyed two-round
 * cipher (used on the 8-byte room session token): each round lays a half-buffer
 * key mask into the first scratch buffer, XORs it into the second half of `data`
 * and swaps the halves of `data`.  Returns 0, or -1 when an allocation fails. */
int Ov001_ScrambleToken(void *data,int size,void *key,int keyLength) {
 int func_ov001_0216ad54(int);
 void func_ov001_0216ad64(int);
 void Ov001_SwapHalves();
 void Ov001_BuildKeyMask(int,signed char *,int,signed char *,int);
 void Ov001_XorSecondHalf(signed char *,unsigned char *,int);
 int keyMask; int swapBuffer; int round;
 keyMask=func_ov001_0216ad54(size/2);
 if(!keyMask) return -1;
 swapBuffer=func_ov001_0216ad54(size);
 if(!swapBuffer) { func_ov001_0216ad64(keyMask); return -1; }
 for(round=0;round<2;round++) {
 Ov001_BuildKeyMask(round,(signed char *)keyMask,size,key,keyLength);
 Ov001_XorSecondHalf((signed char *)keyMask,data,size);
 Ov001_SwapHalves(data,size,swapBuffer);
 }
 func_ov001_0216ad64(keyMask); func_ov001_0216ad64(swapBuffer); return 0;
}

#pragma thumb on
/* Lay cipher `round`'s key mask into the first half of `mask` (a size/2-byte
 * buffer): byte i is i XORed with the round's key byte, the key repeating from
 * its start and shifted along by the round number. */
void Ov001_BuildKeyMask(int round, signed char *mask, int size, signed char *key, int keyLength) {
    unsigned long long RuntimeIntDivMod(s32, s32);
    int half = size / 2;
    int keyIndex = (s32)(RuntimeIntDivMod(round, keyLength) >> 32);
    int i;
    for (i = 0; i < half; i++) {
        mask[i] = i;
        mask[i] ^= key[keyIndex];
        keyIndex++;
        if (keyIndex >= keyLength) keyIndex = 0;
    }
}
#pragma thumb on
void Ov001_XorSecondHalf(signed char *a,unsigned char *b,int n) {
 int i; int half=n/2;
 for(i=0;i<half;i++) { b[half+i] ^= a[i]; }
}
#pragma thumb off
