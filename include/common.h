/* Basic types for this decompilation (CodeWarrior for DS conventions). Agents add structs and prototypes here or
 * in new headers next to it. */
#ifndef COMMON_H
#define COMMON_H

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
#define TRUE 1
#define FALSE 0
#ifndef NULL
#define NULL ((void*)0)
#endif

/* The compression types of a DS compressed block: the high nibble of its first
 * byte, which InitDecompress keeps in the decoder's type byte. */
enum {
    COMP_TYPE_LZ77    = 0x10,
    COMP_TYPE_HUFFMAN = 0x20,
    COMP_TYPE_RLE     = 0x30
};

/* The first word of a DS compressed block: bits 4..7 hold the compression type
 * (COMP_TYPE_* >> 4) and bits 8..31 the decompressed size in bytes. */
#define COMP_BLOCK_WORD        0x00 /* u32 header word */
#define COMP_BLOCK_TYPE_MASK   0xF0 /* COMP_TYPE_* nibble within COMP_BLOCK_WORD */
#define COMP_BLOCK_TYPE_SHIFT  4    /* shift of the type nibble within COMP_BLOCK_WORD */
#define COMP_BLOCK_SIZE_SHIFT  8    /* shift of the decompressed size within COMP_BLOCK_WORD */
#define COMP_BLOCK_HEADER_BYTES 4   /* bytes of the header before the payload */
#define COMP_BLOCK_RAM_END     0x04000000 /* destinations below this address are main RAM, not VRAM/IO */

/* The game's global pseudo-random generator (Rand / SetRandSeed in main_02066BA8)
 * is the classic 32-bit linear-congruential generator: the state advances to
 * state * RAND_MULTIPLIER + RAND_INCREMENT and Rand returns the top 15 bits. */
#define RAND_MULTIPLIER 0x41C64E6D
#define RAND_INCREMENT  0x3039
#define RAND_SHIFT      16
#define RAND_MASK       0x7FFF

/* State of the chunked decompressor: InitDecompress (main_0207C2F0) sets the
 * two bytes below, then the compression type's Init*Decompress (main_02007EF4)
 * fills in the decoder state at +0x04 that DecompressChunk runs. */
typedef struct DecompressState {
    u8 compType;  /* +0x00 COMP_TYPE_* from the block header's high nibble */
    u8 vramFlag;  /* +0x01 1 when the output address is outside main RAM (VRAM) */
} DecompressState;

/* The Huffman decoder state (DecompressState +0x04) that InitHuffmanDecompress
 * sets up and HuffmanDecompress runs: the output pointer and remaining count, the
 * bit and output-word accumulators, and the node/tree buffer the node pointer
 * walks while decoding symbols. */
#define HUFFMAN_OUTPUT     0x00 /* u32 *: next output word */
#define HUFFMAN_REMAINING  0x04 /* s32: output bytes still to produce */
#define HUFFMAN_NODE       0x08 /* u8 *: current tree node within the buffer at +0x1C */
#define HUFFMAN_BITS       0x0C /* u32: bit accumulator */
#define HUFFMAN_OUT_WORD   0x10 /* u32: output word being assembled */
#define HUFFMAN_NODE_COUNT 0x14 /* s16: nodes still to read for the current symbol */
#define HUFFMAN_BIT_COUNT  0x16 /* u8: bits held in the accumulator */
#define HUFFMAN_WORD_BITS  0x17 /* u8: bits assembled into the output word */
#define HUFFMAN_WORD_SHIFT 0x18 /* u8: header low nibble, bits per output pixel */
#define HUFFMAN_BUFFER     0x1C /* u8[]: symbol/tree buffer the node pointer walks */

/* The shared state of the RLE and LZ77 decoders (DecompressState +0x04): the
 * output pointer and remaining count, the 16-bit output accumulator and the bit
 * position it has reached, and the flag byte with the number of its bits still
 * to use.  LZ77 adds the pending back-reference byte. */
#define DECOMP_OUT       0x00 /* u8 * / u16 *: next output byte or word */
#define DECOMP_REMAINING 0x04 /* s32: output bytes still to produce */
#define DECOMP_ACC       0x08 /* u16: output word being assembled (16-bit output) */
#define DECOMP_POS       0x0a /* u8: bits held in DECOMP_ACC (0, 8 or 16) */
#define DECOMP_HDR       0x0b /* u8: current flag byte */
#define DECOMP_CNT       0x0c /* u8 (LZ77) / u16 (RLE): flag bits left in DECOMP_HDR */
#define DECOMP_PREV      0x0d /* u8: LZ77 back-reference length/high-distance byte */
#define DECOMP_HAVE      0x0e /* u8: LZ77 DECOMP_PREV holds an unused byte */

/* Word-at-a-time C string helpers (StringCompare, StringCopy): a little-endian word
 * holds a NUL byte when (word + STRING_ZERO_BIAS) & ~word & STRING_ZERO_MASK is set. */
#define STRING_ZERO_BIAS 0xfefefeffu /* the word minus 0x01010101 */
#define STRING_ZERO_MASK 0x80808080u /* the top bit of every byte */

/* State of the bounded string writer of the game's formatter (StringFormatBounded
 * and WriteFormatBuffer in main_02066BA8.c): the output buffer, its capacity and
 * how much of it has been written. */
typedef struct FormatBuffer {
    char *buffer;  /* +0x00 output buffer */
    u32   size;    /* +0x04 capacity in bytes */
    u32   position;/* +0x08 bytes written so far */
} FormatBuffer;

/* The same writer state for the wide (UTF-16) formatter (StringFormatWideToBuffer
 * and its writer callback): the output buffer, its capacity and how many
 * characters of it have been written. */
typedef struct WideFormatBuffer {
    u16 *buffer;   /* +0x00 output UTF-16 buffer */
    u32  size;     /* +0x04 capacity in characters */
    s32  count;    /* +0x08 characters written so far */
} WideFormatBuffer;

/* The game's block allocator (HeapAlloc/HeapFree and the WFC library's callbacks):
 * every block carries a 0x20-byte header with a magic word and its user-data size. */
#define HEAP_BLOCK_HEADER 0x20   /* bytes in front of the user data */
#define HEAP_BLOCK_MAGIC  0x4457434D /* u32 at +0x00: block tag "MCWD" */
#define HEAP_BLOCK_SIZE   0x04   /* s32 at +0x04: bytes of user data */
#define HEAP_ALIGN_DEFAULT 0x20  /* alignment HeapAlloc asks for */

typedef struct HeapCallbacks {
    void (*freeBlock)(s32 heap, void *blockHeader, s32 size); /* +0x00 */
    void *(*allocate)(s32 heap, s32 size, s32 align);         /* +0x04 */
} HeapCallbacks; /* 8 bytes */


/* What machine drafts (m2c) use for what they can't tell yet: autopilot tries them as they are. */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;

typedef struct OSLockWord {
    volatile u32 lockFlag;
    u16 ownerId;   /* +0x04 lock id owning the word, 0 when the word is free */
    u16 extension;
} OSLockWord;

/* OS_GetLockID hands out ids 64..127, so bit 6 of a nonzero ownerId is always
 * set: testing it tells whether some lock id owns the word. */
#define OS_LOCK_WORD_OWNED 0x40

/* The OS lock word the OSi_*Word lock helpers (OSi_TryLockWord and friends) share:
 * it lives in the ARM9's DTCM. */
#define OS_LOCK_WORD_ADDR 0x027FFFE8

/* The lock word the card ROM/archive lock helpers use, next to the OS lock word
 * (CARD_LockRom/CARD_UnlockRom guard the ROM access with it). */
#define CARD_LOCK_WORD_ADDR 0x027FFFE0

enum { OS_UNLOCK_NOT_OWNER = -2 };
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
typedef struct { s32 fd; s16 events; s16 revents; } PollFd;

/* PollFd event bits: what the caller asks for in events and SocketPoll reports
 * in revents. */
#define POLL_FD_READ     0x01 /* data can be read */
#define POLL_FD_PRIORITY 0x08 /* out-of-band (priority) data */
#define POLL_FD_ERROR    0x20 /* the socket failed or timed out */
#define POLL_FD_WRITE    0x40 /* data can be written */
#define POLL_FD_INVALID  0x80 /* the socket is not registered */
#define POLL_FD_ALWAYS   0xE0 /* error, writable and invalid are reported even when not asked for */

/* A GameSpy (gsi) recursive mutex, 24 bytes. The mutex remembers the thread
 * object that holds it and how many times that thread took it. */
typedef struct GsiMutex {
    u32 unused00;       /* +0x00 */
    u32 unused04;       /* +0x04 */
    void *owner;        /* +0x08: thread object holding the mutex, NULL when free */
    s32 count;          /* +0x0C: nesting depth for the owner */
    u32 unused10;       /* +0x10 */
    s32 waiters;        /* +0x14 */
} GsiMutex;             /* 0x18 */

/* A GameSpy hashtable (hashtable.c, built by TableNew in main_02048B74): an
 * array of nBuckets vectors whose elements are all elemSize bytes; an element
 * lives in the vector its hash callback returns. */
typedef struct HashTable {
    void **buckets;                    /* +0x00 the nBuckets vectors */
    s32 nBuckets;                      /* +0x04 */
    void *userData;                    /* +0x08 handed to the vectors' callbacks */
    s32 (*hash)(const void *, s32);    /* +0x0C element, nBuckets -> bucket */
    s32 (*compare)(const void *, const void *); /* +0x10 a, b -> 0 when equal */
} HashTable;

/* One record of a string-intern table (the 8-byte element of the HashTable built
 * by GetStringInternTable): the canonical copy of an interned string and how many
 * references have been handed out.  StringIntern/StringInternRelease update the
 * count; the entry is removed, freeing the string, when it reaches zero. */
typedef struct InternedString {
    char *string;   /* +0x00 the interned duplicate */
    s32   refCount; /* +0x04 live references */
} InternedString;

/* GameSpy gpi darray (darray.c; the Vector_* functions in main_02047B84): an
 * array of count items of elemSize bytes that holds capacity slots and grows by
 * growCapacity slots when full.  userData is the per-item release callback that
 * Vector_Free and Vector_RemoveItem call. */
#define VECTOR_COUNT     0x00 /* s32 items in use */
#define VECTOR_CAPACITY  0x04 /* s32 slots allocated */
#define VECTOR_ELEM_SIZE 0x08 /* s32 bytes per item */
#define VECTOR_GROW      0x0C /* s32 slots added when the array is full */
#define VECTOR_USER_DATA 0x10 /* s32 per-item release callback, 0 when none */
#define VECTOR_ITEMS     0x14 /* void *the item slots */

typedef struct Vector {
    s32 count;     /* +0x00 items in use */
    s32 capacity;  /* +0x04 slots allocated */
    s32 elemSize;  /* +0x08 bytes per item */
    s32 grow;      /* +0x0C slots added when the array is full */
    s32 userData;  /* +0x10 per-item release callback, 0 when none */
    void *items;   /* +0x14 the item slots */
} Vector;

/* A 16-bit pixel rectangle (position and size) handed to the sprite widget code. */
typedef struct WidgetRect {
    u16 x, y, w, h;
} WidgetRect;

/* TCP segment header on the wire (all multi-byte fields big-endian). */
typedef struct TcpSegment {
    u16 srcPort;    /* +0x00 */
    u16 dstPort;    /* +0x02 */
    u32 seq;        /* +0x04 */
    u32 ack;        /* +0x08 */
    u8 dataOffset;  /* +0x0C: header length in 32-bit words in the high nibble */
    u8 flags;       /* +0x0D: TCP_FLAG_* */
    u16 window;     /* +0x0E */
    u16 checksum;   /* +0x10 */
    u16 urgent;     /* +0x12 */
} TcpSegment;

/* UDP datagram header on the wire (all multi-byte fields big-endian). */
typedef struct UdpDatagram {
    u16 srcPort;    /* +0x00 */
    u16 dstPort;    /* +0x02 */
    u16 length;     /* +0x04 */
    u16 checksum;   /* +0x06 */
} UdpDatagram;

/* IP header fields used by the transport layer (two u16 each, big-endian). */
#define IP_HEADER_SRC_ADDR 0x0C /* source address */
#define IP_HEADER_DST_ADDR 0x10 /* destination address */

/* Socket control block, the object at a socket-list node's +0xA4. */
#define SOCKET_OWNER      0x00 /* s32 nonzero while the socket is in use */
#define SOCKET_TASK_STATE 0x04 /* s32 state of the task waiting on the socket */
#define SOCKET_STATE      0x08 /* u8 socket state, TCP_STATE_* or SOCKET_STATE_* */
#define SOCKET_STATE_TICK 0x10 /* u32 tick (GetSystemTick >> 16) the current state was entered */
#define SOCKET_LOCAL_PORT 0x0A /* u16 local port, host order */
#define SOCKET_LOCAL_ADDR 0x14 /* u32 local address */
#define SOCKET_PEER_PORT  0x18 /* u16 peer port, 0 until a peer is bound */
#define SOCKET_PEER_ADDR  0x1C /* u32 peer address, 0 or -1 until a peer is bound */
#define SOCKET_NEXT_PEER_PORT 0x1A /* u16 peer port staged before it is committed to SOCKET_PEER_PORT */
#define SOCKET_NEXT_PEER_ADDR 0x20 /* u32 peer address staged before it is committed to SOCKET_PEER_ADDR */
#define SOCKET_DATA_CB    0x38 /* s32 (*)(void *, u32, void *) receive callback */
#define SOCKET_RX_CAP     0x3C /* u32 receive buffer capacity */
#define SOCKET_RX_BUFFER  0x40 /* void *receive buffer */
#define SOCKET_RX_LENGTH  0x44 /* u32 bytes currently in the receive buffer */
#define SOCKET_TX_CAP     0x48 /* u32 transmit buffer capacity */
#define SOCKET_TX_BUFFER  0x4C /* void *transmit buffer */

/* Socket states that are not TCP states (SOCKET_STATE). */
enum {
    SOCKET_STATE_UDP_LISTEN = 10,   /* unbound UDP socket waiting for a peer */
    SOCKET_STATE_UDP_CONNECTED = 11 /* UDP socket with its peer address set */
};

#define IP_PROTO_TCP 6 /* IPv4 protocol number of a TCP segment */

/* TCP control flags (TcpSegment.flags, also used as the event kind). */
enum {
    TCP_FLAG_FIN = 0x01,
    TCP_FLAG_SYN = 0x02,
    TCP_FLAG_RST = 0x04,
    TCP_FLAG_PSH = 0x08,
    TCP_FLAG_ACK = 0x10,
    TCP_FLAG_URG = 0x20
};

/* State of a TCP connection (byte at +0x08 of the connection). */
enum TcpState {
    TCP_STATE_CLOSED = 0,
    TCP_STATE_SYN_SENT = 2,
    TCP_STATE_SYN_RCVD = 3,
    TCP_STATE_ESTABLISHED = 4,
    TCP_STATE_LAST_ACK = 6,
    TCP_STATE_FIN_WAIT1 = 7,
    TCP_STATE_FIN_WAIT2 = 8,
    TCP_STATE_TIME_WAIT = 9
};

/* Fields of the connection/socket object TcpSendSegment builds a segment from
 * (and TcpSendReset assembles a reset in).  The ports and destination address
 * are stored in host order; the sequence and acknowledgement numbers are the
 * raw 32-bit values that go on the wire. */
#define TCP_CONN_ACK_NUM  0x24 /* u32 acknowledgement number to send */
#define TCP_CONN_SEND_SEQ 0x28 /* u32 next send sequence number */
#define TCP_CONN_PEER_MSS 0x2E /* u16 peer maximum segment size in bytes */

#define TCP_DATA_OFFSET_MASK 0xF0
#define TCP_DEFAULT_MSS 536
enum {
    TCP_OPTION_END = 0,
    TCP_OPTION_NOP = 1,
    TCP_OPTION_MSS = 2
};

/* Description of a hash used by Hmac for keyed hashing (HMAC): the digest and
 * block sizes, the hash state it works on and its three entry points.  The
 * game's SHA1 one is gSha1HashDescriptor. */
typedef struct HashDescriptor {
    u32 digestSize;                            /* +0x00 digest bytes written by final() */
    u32 blockSize;                             /* +0x04 HMAC block size in bytes */
    void *context;                             /* +0x08 hash state passed to the callbacks */
    u8 *digest;                                /* +0x0C scratch for the inner digest */
    void (*init)(void *);                      /* +0x10 */
    void (*update)(void *, const void *, s32); /* +0x14 */
    void (*final)(void *, void *);             /* +0x18 */
} HashDescriptor;

#define SHA1_DIGEST_SIZE 20 /* bytes of a SHA1 digest */

/* The four SHA-1 round constants, one per 20 steps of a block compression. */
#define SHA1_K_STEPS_0_19  0x5A827999
#define SHA1_K_STEPS_20_39 0x6ED9EBA1
#define SHA1_K_STEPS_40_59 0x8F1BBCDC
#define SHA1_K_STEPS_60_79 0xCA62C1D6

/* A fixed HMAC key: the key bytes and their length.  gHmacSha1Key is the 64-byte
 * archive-signing key HmacSha1Verify uses. */
typedef struct HmacKey {
    const u8 *data; /* +0x00 key bytes */
    u32 length;     /* +0x04 key length in bytes */
} HmacKey;

/* SHA1 state worked on by Sha1Init, Sha1Update and SHA1_Finalize (main_0200BDA4). */
typedef struct Sha1Context {
    u32 state[5];      /* +0x00 A, B, C, D, E */
    u32 bitCountLo;    /* +0x14 low word of the processed bit count */
    u32 bitCountHi;    /* +0x18 high word of the processed bit count */
    u32 bufferBytes;   /* +0x1C bytes waiting in block */
    u8  block[0x40];   /* +0x20 message block being filled */
} Sha1Context; /* 0x60 bytes */

/* Compact SHA1 context of the reference implementation in main_020251B8
 * (SHA1_Init, SHA1_Update, SHA1_Final) that the TLS code hashes with. Unlike
 * Sha1Context above it stores no buffered-byte count: the offset in the block
 * is the low word of the bit count modulo 64. */
typedef struct TlsSha1Context {
    u32 state[5];    /* +0x00 A, B, C, D, E */
    u32 bitCountHi;  /* +0x14 high word of the processed bit count */
    u32 bitCountLo;  /* +0x18 low word of the processed bit count */
    u8 block[0x40];  /* +0x1C message block being filled */
} TlsSha1Context; /* 0x5C bytes */

/* A fixed-point decimal number used by the software-float and BigNum layer (the
 * calculator, damage and gauge code): a sign, a binary exponent, the number of
 * digits in use and the digits themselves, each a byte 0..9, most significant
 * first.  Several source files declared their own copy of this layout
 * (DecimalBD, Decimal38) before it lived here. */
typedef struct DecimalNumber {
    s8  sign;       /* +0x00 0 = positive, nonzero = negative */
    u8  pad;        /* +0x01 */
    s16 exponent;   /* +0x02 */
    u8  length;     /* +0x04 number of digits in use (0..32) */
    u8  digits[33]; /* +0x05 the digits, most significant first */
} DecimalNumber;    /* 0x26 bytes */

/* Largest limb product BigNumSquare doubles in one carry.  BigNumAddCarryAt
 * adds a 32-bit carry to a u16 limb; a carry above 0xFFFF0000 would overflow
 * that addition, so multiplying a product by two is only safe up to this value
 * (half of 0xFFFF0000).  A bigger product is added twice instead. */
#define BIGNUM_DOUBLE_PRODUCT_MAX 0x7fff8000U

/* The high bit of a big number's most significant limb: a big number is negative
 * (two's complement) when that bit is set. */
#define BIGNUM_SIGN_BIT 0x8000

/* Values ClassifyDouble returns for the class of a double. */
enum {
    DOUBLE_CLASS_NAN       = 1,
    DOUBLE_CLASS_INFINITE  = 2,
    DOUBLE_CLASS_ZERO      = 3,
    DOUBLE_CLASS_NORMAL    = 4,
    DOUBLE_CLASS_SUBNORMAL = 5
};

/* Fields of a double's high word (the second u32 of the 8 bytes). */
#define DOUBLE_SIGN_HI     0x80000000 /* sign bit */
#define DOUBLE_EXP_HI      0x7ff00000 /* exponent field */
#define DOUBLE_MANTISSA_HI 0x000fffff /* mantissa bits of the high word */

/* TLS connection (the channel object the TLS record code passes around).  The
 * hash and RC4 states are embedded; the key fields point into the channel's key
 * block, and each direction's sequence number is an 8-byte big-endian counter. */
enum {
    TLS_HASH_MD5  = 4, /* TLS_HASH_ALGORITHM: 16-byte MAC */
    TLS_HASH_SHA1 = 5  /* TLS_HASH_ALGORITHM: 20-byte MAC */
};

#define TLS_HASH_ALGORITHM 0x32  /* u16, TLS_HASH_MD5 or TLS_HASH_SHA1 */
#define TLS_MAC_KEY_OUT    0xbc  /* void * key of the outgoing record MAC */
#define TLS_RC4_KEY_OUT    0xc0  /* void * key of the outgoing RC4 state */
#define TLS_RC4_OUT        0xc8  /* RC4 state of outgoing records */
#define TLS_SEQ_OUT        0x1cc /* u8[8] outgoing sequence number, hashed in the MAC */
#define TLS_MAC_KEY_IN     0x1d4 /* void * key of the incoming record MAC */
#define TLS_RC4_KEY_IN     0x1d8 /* void * key of the incoming RC4 state */
#define TLS_RC4_IN         0x1e0 /* RC4 state of incoming records */

/* RC4 keystream state: the two S-box indices and the 256-byte permutation. */
#define RC4_INDEX_I 0x00 /* u8 i, advanced by one for every byte */
#define RC4_INDEX_J 0x01 /* u8 j, advanced by the S-box entry i names */
#define RC4_SBOX    0x02 /* u8[256] the permutation */

typedef struct RC4State {
    u8 i;            /* +0x00 RC4_INDEX_I */
    u8 j;            /* +0x01 RC4_INDEX_J */
    u8 sbox[256];    /* +0x02 RC4_SBOX */
} RC4State;          /* 0x102 bytes */
#define TLS_SEQ_IN         0x2e4 /* u8[8] incoming sequence number, hashed in the MAC */
#define TLS_SHA1_CTX       0x348 /* SHA1 context of the record being handled */
#define TLS_MD5_CTX        0x3fc /* MD5 context of the record being handled */
#define TLS_STATE          0x455 /* u8 TLS record/handshake state */
#define TLS_HMAC_IPAD      0x36  /* inner HMAC pad byte */
#define TLS_HMAC_OPAD      0x5c  /* outer HMAC pad byte */
#define TLS_MD5_PAD_SIZE   0x30  /* bytes of inner/outer pad the MD5 Finished digest hashes */
#define TLS_SHA1_PAD_SIZE  0x28  /* bytes of inner/outer pad the SHA1 Finished digest hashes */
#define TLS_MASTER_SECRET  0x00  /* u8[48] the session's master secret */
#define TLS_MASTER_SECRET_SIZE 0x30 /* bytes of the master secret the PRF hashes */
#define TLS_RANDOM_SIZE    0x20  /* bytes of one handshake random */
#define TLS_RANDOM_A       0x34  /* u8[32] one handshake random */
#define TLS_RANDOM_B       0x54  /* u8[32] the other handshake random */
#define TLS_KEY_BLOCK      0x74  /* per-direction MAC secrets and RC4 keys derived by TlsInitRecordKeys */
#define TLS_SESSION_CACHED 0x30  /* u8 nonzero when a cached session was restored for the peer */
#define TLS_SESSION_RESUMED 0x31 /* u8 nonzero when the server resumed the cached session */
#define TLS_SESSION_ID     0x74  /* u8[32] session id echoed in a ClientHello; the key block reuses it later */
#define TLS_SERVER_SIDE    0x454 /* u8 nonzero when this endpoint uses the server-side role */
#define TLS_CLIENT_CERT_REQUESTED 0x5ac /* u8 set once a CertificateRequest was received */
#define TLS_PENDING_RECORD 0x824 /* void * record buffer being reassembled */
#define TLS_PENDING_SIZE   0x828 /* u32 total size of that record */
#define TLS_PENDING_READ   0x82c /* s32 bytes of it read so far */
#define TLS_PENDING_KEEP   0x456 /* u8 keep the reassembled record for the caller */
#define TLS_STATE_CLIENT_HELLO 1  /* TLS_STATE value: the peer's ClientHello was accepted */
#define TLS_STATE_CLIENT_KEY_EXCHANGE 5 /* TLS_STATE value: the peer's ClientKeyExchange was accepted */
#define TLS_STATE_SERVER_HELLO_DONE 4 /* TLS_STATE value: the peer sent ServerHelloDone */
#define TLS_STATE_FINISHED  6     /* TLS_STATE value: the peer's Finished digest verified */
#define TLS_STATE_CHANGE_CIPHER_SPEC 7 /* TLS_STATE value: the peer's ChangeCipherSpec was received */
#define TLS_MD5_CTX_SIZE    0x58  /* bytes of a saved MD5 transcript context */
#define TLS_SHA1_CTX_SIZE   0x5C  /* bytes of a saved SHA1 transcript context */
#define TLS_MD5_FINISHED_SIZE  16 /* bytes of a Finished MD5 digest */
#define TLS_SHA1_FINISHED_SIZE 20 /* bytes of a Finished SHA1 digest */
#define TLS_STATE_DONE     8     /* TLS_STATE value meaning the handshake completed */
#define TLS_STATE_ERROR    9     /* TLS_STATE value meaning the handshake failed */
#define TLS_RECORD_HEADER  5     /* bytes of a TLS record header */
#define TLS_MAX_RECORD     0x4800 /* largest accepted record body */

  /* The TLS client's session-resumption cache: TLS_CACHE_ENTRIES entries in
 * gTlsSessionCache, each holding one peer's session id and master secret, keyed
 * by its address and port and stamped with the tick (GetSystemTick()>>16) it was
 * stored at.  TlsStoreSession, TlsRestoreSession and TlsSessionCacheDiscard
 * access it with interrupts disabled. */
#define TLS_CACHE_ENTRIES    4
#define TLS_CACHE_ENTRY_SIZE 0x5C
#define TLS_CACHE_SIZE       0x170 /* TLS_CACHE_ENTRIES * TLS_CACHE_ENTRY_SIZE */
#define TLS_CACHE_SESSION_ID 0x00  /* u8[32] session id echoed in a later ClientHello */
#define TLS_CACHE_SECRET     0x20  /* u8[48] the session's master secret */
#define TLS_CACHE_TICK       0x50  /* u32 tick the session was stored at */
#define TLS_CACHE_ADDRESS    0x54  /* s32 peer address the session was stored for */
#define TLS_CACHE_PORT       0x58  /* u16 peer port */
#define TLS_CACHE_VALID      0x5A  /* u8 nonzero once the entry holds a session */

/* The preferred TLS cipher suites (gTlsCipherSuites): the TLS_CIPHER_SUITE_COUNT
 * suites this build offers, which TlsPickCipherSuite matches against the peer's
 * list.  The word at TLS_BOOST_PRIORITY, right after them, is the run priority
 * the RSA/TLS work raises the running thread to: Wfc_CreateConnection sets it and
 * BoostThreadPriority applies it, and 32 or more (its boot value) means unset. */
#define TLS_CIPHER_SUITE_COUNT 2     /* suites in gTlsCipherSuites */
#define TLS_BOOST_PRIORITY     0x04  /* u32 gTlsCipherSuites + this: the boost run priority */
#define THREAD_PRIORITY_MAX    32    /* run priorities are 0..THREAD_PRIORITY_MAX-1 */

/* ASN.1 time values as they appear in a certificate's validity dates: a tag
 * followed by ASCII digits.  UTCTime carries a two-digit year, GeneralizedTime
 * a four-digit one; ParseAsn1Time turns either into year<<16 | month<<8 | day. */
#define ASN1_TIME_UTC         0x17 /* UTCTime */
#define ASN1_TIME_GENERALIZED 0x18 /* GeneralizedTime */
#define ASN1_DIGITS_ZERO      0x210 /* '0' * 10 + '0', so d0*10 + d1 - this is the pair's value */

/* ASN.1 DER lengths: the first byte is the length itself when its high bit is
 * clear, otherwise its low 7 bits are the number of following bytes of a
 * big-endian length.  ParseAsn1Length decodes either form. */
#define ASN1_LENGTH_LONG_FORM  0x80 /* first length byte: a multi-byte length follows */
#define ASN1_LENGTH_VALUE_MASK 0x7F /* the number of following length bytes */

/* TLS record content types (the first byte of a record). */
enum {
    TLS_CONTENT_ALERT              = 21,
    TLS_CONTENT_CHANGE_CIPHER_SPEC = 20,
    TLS_CONTENT_HANDSHAKE          = 22,
    TLS_CONTENT_APPLICATION_DATA   = 23
};

/* Fields of the close alert a TLS endpoint sends when it closes a channel: a
 * two-byte alert message carrying a warning-level close_notify. */
#define TLS_ALERT_LENGTH            2
#define TLS_ALERT_LEVEL_WARNING     1
#define TLS_ALERT_DESC_CLOSE_NOTIFY 0

/* Application data is split across records no larger than this; each record
 * needs TLS_APP_RECORD_OVERHEAD extra bytes for its header and SHA1 MAC. */
#define TLS_APP_CHUNK_MAX       0xB4F
#define TLS_APP_RECORD_OVERHEAD 0x19

/* TLS handshake message type of the Finished message. */
#define TLS_HANDSHAKE_FINISHED 20

/* Contexts of the handshake transcript (the running MD5/SHA1 hash of the
 * handshake messages). TLS_MD5_CTX/TLS_SHA1_CTX above are the separate scratch
 * contexts a record MAC is computed in. */
#define TLS_TRANSCRIPT_MD5  0x3a4
#define TLS_TRANSCRIPT_SHA1 0x2ec

/* ov003 map-list menu entity: the mode nibble selects the map screen, and the
 * selected map id is read either from the paged list or from MAP_ID below. */
#define MENU_ENTITY_MODE      0x3b /* u8 low nibble: menu kind */
#define MENU_ENTITY_MAP_ID    0x3c /* u16 selected map id for non-list menus */
#define MENU_ENTITY_MAP_LIST  0x44 /* paged table of u16 map ids */
#define MENU_ENTITY_CURSOR    0x4c /* list cursor object, +0x14 selected row */
#define MENU_ENTITY_PAGER     0x5c /* paging object, +4 page index */
#define MENU_ENTITY_TWEEN_TOP 0x58 /* SpriteTween *: first row's slide tween */
#define MENU_MAP_PAGE_SIZE    0x200 /* bytes per map-list page */
#define MENU_MAP_ENTRY_OFFSET 0x2e /* u16 map id per row within a page */
#define MENU_MAP_LIST_DRAWN   0x186C /* u8[13]: one bit per row, set while the row is drawn */
#define MENU_MAP_LIST_DRAWN_SIZE 0x0D /* bytes of drawn-row markers (104 rows) */

/* ov003 map-list menu kinds (MENU_ENTITY_MODE low nibble) that open an ov006
 * map sub-panel: the campaign map list (6) and the two map-pick lists (7, 8). */
#define MENU_KIND_CAMPAIGN   6
#define MENU_KIND_MAP_PICK_7 7
#define MENU_KIND_MAP_PICK_8 8

/* ov003 map-select screen: six preview rows of three animations each. */
typedef struct MapSelectRow {
    u8 pad[0x18];
    void *anim0;   /* +0x18 */
    void *anim1;   /* +0x1C */
    void *anim2;   /* +0x20 */
} MapSelectRow;    /* 0x24 bytes */

typedef struct MapSelectScreen {
    void *vtable;          /* +0x00 */
    u8 pad04[0x30];
    u8 unk34;              /* +0x34 */
    u8 unk35;              /* +0x35 */
    u8 flags36;            /* +0x36: high nibble selects the palette variant */
    u8 unk37;              /* +0x37 */
    u8 flags38;            /* +0x38 */
    u8 colorIndex;         /* +0x39 */
    u8 colorValue;         /* +0x3A */
    u8 pad3B;              /* +0x3B */
    void *palette;         /* +0x3C */
    void *bounds;          /* +0x40 */
    void *handle;          /* +0x44 */
    MapSelectRow *rows;    /* +0x48: 6 rows */
    void *animPair;        /* +0x4C: object with two animations at +0x18/+0x1C */
    void *sprite50;        /* +0x50 */
    void *sprite54;        /* +0x54 */
    void *obj58;           /* +0x58 */
    void *obj5C;           /* +0x5C: owns a buffer at +0x14 */
    void *obj60;           /* +0x60: polymorphic, vtable[1] is its destructor */
    void *obj64;           /* +0x64: polymorphic, vtable[1] is its destructor */
    void **buffers68;      /* +0x68: 6 buffers */
} MapSelectScreen;

/* A battle-scene player label: a row of unit sprites with the player's username
 * and a class vtable (destroy, then destroy-and-free) in its first word.  A small
 * heap block of extra state sits at +0x68 and is freed with the label. */
#define PLAYER_LABEL_VTABLE 0x00 /* void * the label's vtable: destroy, then destroy-and-free */
#define PLAYER_LABEL_BUFFER 0x68 /* void * heap block freed by the deleting destructor */

/* Label state of the ov003 map-select screen (DrawMapSelectLabel). */
#define MAP_SELECT_KIND         0x0F /* byte in the descriptor at +0x3C that picks the label kind */
#define MAP_SELECT_ENTRY_ID     0x08 /* u16 entry id in the pager's current page object */
#define MAP_SELECT_ROW_ID_BASE  11   /* entry ids start this far above the row index */
#define MAP_SELECT_ROW_STRIDE   0x24 /* bytes per preview row in the +0x48 array */
#define MAP_SELECT_ROW_TEXT_KEY 0x0C /* s32 localized-text key in the object a row points at */
#define MAP_SELECT_BLINK        0x04 /* flags38 bit toggled on every label redraw */

/* The ov003 map-grid menu (the 0x3C-byte polymorphic object the map-select
 * handler holds at +0x48): eleven button sprites -- ids 0..4 in the top row,
 * 5..9 in the bottom row and 10 the wide button -- plus the entry ids its
 * per-frame update latches.  Ov003_UpdateMapGridButtons animates the buttons
 * every frame and records the button that reports a click (MAPGRID_CLICKED) and
 * the one showing its pressed frame (MAPGRID_PRESSED); the handler then moves
 * the map preview onto the pressed button.  func_ov003_021e1530 sets up the
 * selected entry: MAPGRID_CURSOR is its sprite object, MAPGRID_ID the entry id,
 * MAPGRID_COLUMN/ROW its grid position. */
#define MAPGRID_CLICKED   0x04 /* s8: button clicked this frame, -1 = none */
#define MAPGRID_PRESSED   0x05 /* s8: button showing its pressed frame, -1 = none */
#define MAPGRID_ID        0x06 /* u8: selected entry id (0..10) */
#define MAPGRID_COLUMN    0x07 /* u8: id % 5 */
#define MAPGRID_ROW       0x08 /* u8: id / 5 */
#define MAPGRID_COUNT     0x0B /* u8: number of visible map buttons */
#define MAPGRID_BUTTONS   0x0C /* void *[11]: the button sprites */
#define MAPGRID_BUTTON_STRIDE 4
#define MAPGRID_CURSOR    0x38 /* void *: sprite object of the selected entry */

/* The ov003 waypoint/segment list (the object the panel holds at +0x6C): 26 slot
 * sprites, each with its own owner.  Ov003_UpdateWaypointSlotButtons animates
 * every slot each frame and latches the slot that reports a click
 * (WAYPOINT_LIST_CLICKED) and the one showing its pressed frame
 * (WAYPOINT_LIST_PRESSED). */
#define WAYPOINT_LIST_COUNT   0x04 /* u8: number of slots in use */
#define WAYPOINT_LIST_CLICKED 0x05 /* s8: slot clicked this frame, -1 = none */
#define WAYPOINT_LIST_PRESSED 0x06 /* s8: slot showing its pressed frame, -1 = none */
#define WAYPOINT_LIST_SELECTED 0x07 /* u8: currently selected slot */
#define WAYPOINT_LIST_OPTION  0x08 /* u8: the selected slot's option, what the list shows and plays with */
#define WAYPOINT_LIST_PENDING_OPTION 0x09 /* u8: option the player-option menu is editing; RestoreWaypointOption puts it back */
#define WAYPOINT_LIST_SLOT_OPTIONS 0x0A /* u8[4]: per-slot option, one byte per slot */
#define WAYPOINT_LIST_SLOT_VARIANTS 0x0E /* u8[4]: per-slot two-state variant toggled by clicking the slot's option cell; 2 draws the alternate option-cell tile */
#define WAYPOINT_LIST_OPTION_COUNTERS 0x14 /* OptionCounter[4]: per-slot option counters */
#define WAYPOINT_LIST_IDS     0x74 /* u8[4]: player id of each slot, 0xFF = no player yet */
#define WAYPOINT_NO_PLAYER    0xFF /* WAYPOINT_LIST_IDS: the slot has no player yet */
#define WAYPOINT_LIST_SLOTS   0x78 /* void *[26]: the slot sprites */
#define WAYPOINT_LIST_SLOT_COUNT 26
#define WAYPOINT_LIST_UNIT    0xE0 /* void *: unit sprite of the selected slot */

/* The 26 list slots fall into five consecutive groups; the group table gives
 * each group's first slot and its slot count: 0-3, 4-7, 8-20, 21-24 and 25. */
typedef struct WaypointSlotGroup {
    u8 firstSlot; /* first slot index of the group */
    u8 count;     /* number of slots in the group */
} WaypointSlotGroup;

/* The waypoint panel object's own children: the four player-select sprite
 * objects, the sprite group (12 slot sprites at +0x14 with a player label each at
 * +0x44, a trailing label at +0x74, the main sprite at +0x78 and one ready flag
 * per slot at +0x7C) and the WAYPOINT_LIST_* waypoint list above. */
#define WAYPOINT_PANEL_SELECT_SPRITES 0x64 /* void *[4]: player-select sprite objects */
/* The player-select sprite set at WAYPOINT_PANEL_SELECT_SPRITES (0x48 bytes): two
 * slide sprites and a sprite per player column in each of four rows.  The whole
 * set is animated each frame by UpdateWaypointSelectSprites. */
#define WAYPOINT_SELECT_SLIDE     0x00 /* s32 slide sprite */
#define WAYPOINT_SELECT_SLIDE_ALT 0x04 /* s32 alternate slide sprite */
#define WAYPOINT_SELECT_TILE      0x08 /* void *[4]: first row of per-player-column sprites */
#define WAYPOINT_SELECT_TILE_ALT  0x18 /* void *[4]: second row */
#define WAYPOINT_SELECT_ROW_2     0x28 /* void *[4]: third row */
#define WAYPOINT_SELECT_ROW_3     0x38 /* void *[4]: fourth row */
#define WAYPOINT_PANEL_GROUP          0x68 /* the sprite group */
#define WAYPOINT_PANEL_LIST           0x6C /* the waypoint list */
#define WAYPOINT_PANEL_ICON_RECORD    0x40 /* CO panel record the icon refresh updates */
#define WAYPOINT_GROUP_READY          0x7C /* u8[4]: that slot's player record has arrived */

/* The waypoint panel's 0x24-byte link packet (36 bytes, copied into peers'
 * records): the two s32 words the panel toggles tell the peers when this player
 * opened or closed the panel. */
#define WAYPOINT_PACKET_OPENED 0x00 /* s32: set by SendWaypointPanelOpened */
#define WAYPOINT_PACKET_CLOSED 0x04 /* s32: set by SendWaypointPanelClosed */

/* The ov003 setup menu (the object the setup screen holds at +0x44): nine entry
 * sprites -- the eight option rows plus a ninth button -- each with its own
 * owner, plus the entry widget the selection currently points at.  The per-frame
 * update animates every slot and latches the entry that reports a click
 * (SETUP_MENU_CLICKED) and the one showing its pressed frame (SETUP_MENU_PRESSED);
 * +6 is the selected entry, also read from SETUP_MENU_CURRENT's sprite id. */
#define SETUP_MENU_CLICKED    0x04 /* s8: entry clicked this frame, -1 = none */
#define SETUP_MENU_PRESSED    0x05 /* s8: entry showing its pressed frame, -1 = none */
#define SETUP_MENU_SELECTED   0x06 /* u8: currently selected entry (0..7) */
#define SETUP_MENU_CELLS      0xC8 /* void *[8]: the option-row widgets */
#define SETUP_MENU_SLOTS      0xE8 /* void *[9]: the entry sprites */
#define SETUP_MENU_SLOT_COUNT 9
#define SETUP_MENU_CURRENT    0x10C /* void *: sprite of the selected entry */
/* The setup menu's 0x24-byte network state packet at SETUP_MENU_PACKET: the first
 * word is the start/confirm flag (set to 1 before a send), the second word a
 * second request flag, then the packed setup values. */
#define SETUP_MENU_PACKET      0x110 /* u8[0x24]: setup state packet sent to the other players */
#define SETUP_MENU_PACKET_SIZE 0x24

/* The scene object that owns the setup menu above: it holds the menu at
 * SETUP_PANEL_MENU and its SETUP_PANEL_STATE byte says whether the panel is open
 * on the selected entry; SETUP_PANEL_HIGHLIGHT is the cursor-frame sprite the
 * panel's highlight sits on. */
#define SETUP_PANEL_STATE     0x39 /* u8: SETUP_PANEL_CLOSED or SETUP_PANEL_OPEN */
#define SETUP_PANEL_CLOSED    0
#define SETUP_PANEL_OPEN      1
#define SETUP_PANEL_MENU      0x44 /* void *: the setup menu object */
#define SETUP_PANEL_HIGHLIGHT 0x4C /* void *: cursor-frame sprite of the panel highlight */
/* The panel's sprite set at SETUP_PANEL_SPRITES: two slide sprites at +0x00/+0x04,
 * then four rows of four slot sprites.  The rows are contiguous, so walking +0x08
 * and +0x28 by eight pointers covers the first two rows and the last two.  The
 * per-frame update animates every sprite in the set; the panel hide routine
 * (Ov003_HideSetupPanelSprites) hides them all. */
#define SETUP_PANEL_SPRITES   0x40 /* void *: the panel's sprite set */
/* Offsets inside the sprite set at SETUP_PANEL_SPRITES. */
#define SETUP_SPRITES_SLIDE_0    0x00 /* void *: first slide sprite */
#define SETUP_SPRITES_SLIDE_1    0x04 /* void *: second slide sprite */
#define SETUP_SPRITES_ROW_TOP    0x08 /* void *[8]: first two rows of four slot sprites */
#define SETUP_SPRITES_ROW_BOTTOM 0x28 /* void *[8]: last two rows of four slot sprites */
#define SETUP_SPRITES_ROW_COUNT  8    /* slot sprites walked from each row pointer */

/* Per-row animation targets of a MapSelectRow (the tween fields in front of its
 * three animation pointers). Ov003_ApplyRowSelectionAnimations stores the first
 * value on the selected row and the second on every other row; the matching
 * current fields follow the target as the tween runs. */
#define MAP_SELECT_ROW_ANIM_VALUE   0x0E /* u16 main tween target (0x100 selected, 0xCD idle) */
#define MAP_SELECT_ROW_ANIM_AUX     0x10 /* u8 auxiliary animation value (16 selected, 8 idle) */
#define MAP_SELECT_ROW_ANIM_STEP    0x12 /* s8 step tween target (1 selected, 0 idle) */
#define MAP_SELECT_ROW_ANIM_LEVEL   0x14 /* s8 level tween target (2 selected, 5 idle) */
#define MAP_SELECT_ROW_ANIM_MODE    0x15 /* s8 row animation mode (3 selected, 1 idle) */

/* ov003 map-info screen: the per-owner property count grid filled by
 * CountMapProperties (5 player bands of 12 property columns, the grid starting at
 * +4 of the block) and the text sprite that prints one column's total. */
#define OV003_UNIT_COUNT_GRID 0x68 /* u8 *: 5x12 per-owner property counts, grid at +4 */
#define OV003_UNIT_COUNT_TEXT 0x50 /* void *: text sprite for a column's total */

/* ov003 map-preview panel: the unit-category count block (its grid starts at
 * +0x1C and holds one 12-byte record per player band) and the text sprite that
 * prints one category's total. */
#define OV003_PREVIEW_UNIT_GRID 0x5C /* u8 *: per-category unit counts, grid at +0x1C */
#define OV003_PREVIEW_UNIT_TEXT 0x54 /* void *: text sprite for a category's count */

/* ov001 map-select list screen: the object pointed at by gMapSelectState+4.
 * It holds two rows of label sprites and a table of 42-byte map entries. */
#define MAPSELECT_ENTRIES       0x00 /* void *: map entry table */
#define MAPSELECT_OBJ_LIST_BG   0x04 /* void *: loaded map-list background tile set (the map preview draws over it) */
#define MAPSELECT_OBJ_STEP31_BG 0x08 /* void *: loaded step-31 background tile set the OBJ tiles are cut from */
#define MAPSELECT_ENTRY_SIZE    42   /* bytes per map entry */
#define MAPSELECT_ENTRY_NAME_ID 0x26 /* u16 per entry: index of the map's name tile */
#define MAPSELECT_ENTRY_FLAG    0x28 /* u8 per entry: selects the preview path */
#define MAPSELECT_LABEL_TILES   0x42 /* u16[]: tile of a row label sprite, indexed by the entry's MAPSELECT_ENTRY_FLAG */
#define MAPSELECT_NAME_TILES    0x48 /* u16[]: tile of a row name sprite, indexed by the entry's MAPSELECT_ENTRY_NAME_ID */
#define MAPSELECT_ROW_OBJS_A    0x10 /* void *[MAPSELECT_ROWS] row labels */
#define MAPSELECT_ROW_OBJS_B    0x24 /* void *[MAPSELECT_ROWS] map names */
#define MAPSELECT_ROW_TILE      0x04 /* u16 of a row sprite object: tile id in the low ten bits */
#define MAPSELECT_ROWS          5    /* rows shown at once */
#define MAPSELECT_ROW_OBJS_A_INDEX  (MAPSELECT_ROW_OBJS_A / 4) /* void* index of the row label objects */
#define MAPSELECT_ROW_OBJS_B_INDEX  (MAPSELECT_ROW_OBJS_B / 4) /* void* index of the map-name objects */
#define MAPSELECT_LABEL_TILES_INDEX (MAPSELECT_LABEL_TILES / 2) /* u16 index of the label tile table */
#define MAPSELECT_NAME_TILES_INDEX  (MAPSELECT_NAME_TILES / 2)  /* u16 index of the name tile table */
#define MAPSELECT_LABEL_TILES_COUNT 3    /* label tile variants */
#define MAPSELECT_NAME_TILES_COUNT  4    /* map-name tile variants */
#define MAPSELECT_ROW_LABEL_SPRITE  0x2e /* sprite layout of a row's label */
#define MAPSELECT_ROW_NAME_SPRITE   0x18 /* sprite layout of a row's map name */
#define MAPSELECT_ROW_UNITS     0x1c /* scroll units of one list row */
#define MAPSELECT_COUNT         0x51 /* u8 number of maps in the list */
#define MAPSELECT_INDEX         0x52 /* u8 selected row */
#define MAPSELECT_CHOSEN        0x54 /* u8 a map has been chosen */
#define MAPSELECT_TEXT_PANEL    0x0C /* void *: panel the row names are drawn into */
#define MAPSELECT_SCROLL_ANIM   0x38 /* s32 token of the running list-scroll animation */
#define MAPSELECT_TASK          0x3C /* s32 handle of the row-scroll task */
#define MAPSELECT_MAX_SCROLL    0x40 /* u16 scroll position of the last row */
#define MAPSELECT_LAST_ROW      0x53 /* u8 the bar's handle travel in pixels (MAPSELECT_HANDLE_TRAVEL_*) */
#define MAPSELECT_BUMP_LATCH    0x59 /* u8 set once the no-move sound played for a held key */
#define MAPSELECT_SCROLL_DIRTY  0x56 /* u8 set when the list moved: refresh the BG scroll registers */
#define MAPSELECT_ROW_BASE_Y    0x36 /* y of the first visible row with the list at scroll 0 */
#define MAPSELECT_ROW_LABEL_X   0xB3 /* x of a row's label sprite */
#define MAPSELECT_ROW_NAME_X    0xD2 /* x of a row's map-name sprite */

/* The map-select list's scroll bar: the handle size (index into the bar's sprite
 * table, so the longer it is the fewer maps fit), the travel of each handle and
 * the bar's track on the screen. A list of MAPSELECT_NO_SCROLL_MAX maps or fewer
 * does not scroll and gets no bar. */
#define MAPSELECT_NO_SCROLL_MAX    4  /* maps that fit without scrolling */
#define MAPSELECT_SHORT_HANDLE_MAX 8  /* up to this many maps the bar uses the short handle */
#define MAPSELECT_HANDLE_NONE      0  /* no bar at all */
#define MAPSELECT_HANDLE_SHORT     1
#define MAPSELECT_HANDLE_LONG      2
#define MAPSELECT_HANDLE_TRAVEL_SHORT 0x1F /* MAPSELECT_LAST_ROW value of the short handle */
#define MAPSELECT_HANDLE_TRAVEL_LONG  0x37 /* MAPSELECT_LAST_ROW value of the long handle */
#define MAPSELECT_SCROLLBAR_TRACK  0x55 /* track length in pixels */
#define MAPSELECT_SCROLLBAR_X      0xEC /* x of the bar on the list screen */
#define MAPSELECT_SCROLLBAR_Y      0x3F /* y of the bar */

/* The fields of gMapSelectState in front of that object. */
#define MAPSELECT_STATE_CURSOR  0x00 /* u8 highlighted row (0..4) */
#define MAPSELECT_STATE_SCROLL  0x02 /* u16 list scroll position, 0x1c units per row */
#define MAPSELECT_STATE_OBJ     0x04 /* void *: the map-list object (MAPSELECT_*) */

/* The ov001 two-option Wi-Fi menu (gOv001WifiMenuSelection): the option the player
 * has selected and the explanation text loaded for the screen. Its options open
 * the access-point list or the options menu. */
#define OV001_WIFI_MENU_CHOICE      0x00 /* u8 selected option (OV001_WIFI_MENU_*) */
#define OV001_WIFI_MENU_TEXT        0x04 /* s32 loaded explanation text file */
#define OV001_WIFI_MENU_ACCESS_POINT 0   /* open the access-point list */
#define OV001_WIFI_MENU_OPTIONS      1   /* open the options menu */

/* The in-memory game settings block. The word at +0x128 is stamped with this
 * magic once the defaults have been filled in; code that reads the settings
 * re-initialises them when the magic is missing. */
#define GAME_SETTINGS_MAGIC 0x20070810

/* The saved option halfword (inside data_0215d990, stored as the save file's
 * settingsHalfword): a 3-bit map-view zoom field (GAME_OPTION_ZOOM_MASK), 0 while
 * the view is zoomed in and GAME_OPTION_ZOOM_OUT while zoomed out, among the other
 * option bits InitDefaultGameSettings clears. */
#define GAME_OPTIONS_WORD     0x2E
#define GAME_OPTION_ZOOM_MASK 0x0380
#define GAME_OPTION_ZOOM_OUT  0x0080

/* The in-memory option bits (gOptionBits, beside the settings block above): the
 * option flags packed into the halfword at +6.  Bits 10-11 are the battle
 * animation speed; its four codes count 1 and 2 as fast, with 0 the default and
 * 3 the slowest. */
#define GAME_OPTIONS_HALFWORD      0x06 /* u16 packed option bits */
#define GAME_OPTION_ANIMATION_MASK 0x0C00 /* bits 10-11: battle animation speed */
#define GAME_OPTION_ANIMATION_FAST 1
#define GAME_OPTION_ANIMATION_FASTEST 2
/* Bit 14 is the battlefield grid overlay switch: while it is clear the grid is
 * drawn over the terrain (see IsMapGridEnabled). */
#define GAME_OPTION_GRID_MASK 0x4000

/* Total play time in frames: it is the first record value (gRecordValues[0]),
 * which also lies at gOptionBits + 0x74, and the records screen shows it as a
 * clock (IncrementPlayTime ticks it once per frame). */
#define GAME_SETTINGS_PLAY_TIME 0x74

/* NitroSDK NARC archive header and block tags. A block holds its tag at +0 and
 * its byte size at +4; the header's u16 at +0x0C is the offset of the block
 * list and the u16 at +0x0E is the block count. */
#define NARC_MAGIC       0x4352414E /* "NARC" at +0x00 */
#define NARC_BYTE_ORDER  0xFFFE     /* u16 at +0x04 */
#define NARC_VERSION     0x0100     /* u16 at +0x06 */
#define NARC_BLOCK_FAT   0x46415442 /* "BTAF": file allocation table */
#define NARC_BLOCK_FNT   0x464E5442 /* "BTNF": file name table */
#define NARC_BLOCK_IMAGE 0x46494D47 /* "GMIF": file image data */

/* ov005 record/history menu: one scrolling list per tab (global gHistoryMenu). */
typedef struct HistoryMenuTab {
    s16 animPos;    /* +0x00: current scroll offset */
    s16 cursor;     /* +0x02: first visible row */
    s16 animating;  /* +0x04: scroll animation in progress */
    s16 selectable; /* +0x06: number of selectable rows */
    s16 count;      /* +0x08: number of rows */
} HistoryMenuTab;   /* 0xA bytes */

/* Rows of one history-menu page: the row-slot helper creates at most this many
 * row slots, and the list is scrolled seven rows at a time. */
#define HISTORY_MENU_PAGE_ROWS 7

typedef struct HistoryMenu {
    u8 unk00;           /* +0x00 */
    s8 tab;             /* +0x01: active tab (0..2) */
    u8 selected;        /* +0x02: selected row */
    u8 pad03[0xD];
    HistoryMenuTab tabs[3]; /* +0x10 */
    u16 recordTierEarned; /* +0x2E: sum of the record tiers the player has reached */
    u16 recordTierTotal;  /* +0x30: highest tier sum obtainable, 3 per listed record */
    u8 rankIcon;          /* +0x32: rank icon index for the player's earned tiers */
    u8 pad33[0x01];
    s32 favouriteGroupTextId;  /* +0x34: localized text id of the favourite record group */
    s32 favouriteRecordTextId; /* +0x38: localized text id of the player's best record */
    s32 rankTextId;       /* +0x3C: localized text id of the rank the earned tiers reach */
    u8 medals[8];        /* +0x40: medals earned, one flag each (drawn on the records screen) */
    void *sprite48;     /* +0x48 */
    void *sprite4C;     /* +0x4C */
    void *sprite50;     /* +0x50 */
    void *sprite54;     /* +0x54 */
    void *sprite58;     /* +0x58: list-up arrow */
    void *sprite5C;     /* +0x5C: list-down arrow */
    void *sprite60;     /* +0x60 */
} HistoryMenu;          /* 0x64 bytes */

/* ov005 records/achievements screen: the object at gRecordsMenuState+8.
 * Three tabs (tab) each list one record group; the list scrolls six rows at a
 * time and a row is only selectable when its enabled[] flag is set. */
/* Run-time exception frames used by the C++ code in src/auto/main_020739F8.c.
 * The handler's data block is self-describing: 1-byte opcodes (low 5 bits) with
 * an operand flag; FindExceptionEntryTarget walks the block to find where the
 * handler for the frame that faulted starts. */
#define JS_KIND_BIGENDIAN 0x80 /* data block: integers are big-endian and the opcodes are 5 bits wide */
#define JS_KIND_IMMEDIATE 0x40 /* operand flag tested by some handlers: take the value at the frame instead of memory */
#define JS_KIND_ID4       0x20 /* operand flag: something with function ids (bit checked by handlers 4, 6..11) */
#define JS_OP_MASK        0x1F /* opcode bits of a data byte */

/* Fields of the unwinder's frame record that a handler's data block fills: the
 * block's header byte (JS_KIND_*) says how its values are encoded, and from
 * JS_FRAME_SAVE_SIZE on the block describes the frame's saved registers. */
#define JS_FRAME_PREV       0x14 /* void *frame pointer used when the data block is not immediate */
#define JS_FRAME_TOP        0x18 /* void *base of the frame the handler's operands are read from */
#define JS_FRAME_ALT_FP     0x38 /* void *frame pointer picked when the data block is immediate */
#define JS_FRAME_ALT_IP     0x48 /* void *second frame pointer picked when the data block is immediate */
#define JS_FRAME_SAVE_SIZE  0x60 /* s32 bytes of saved registers the frame holds */
#define JS_FRAME_SAVE_VALUE 0x64 /* s32 second value decoded from the data block (immediate case) */
#define JS_FRAME_SAVE_MASK  0x68 /* u16 which registers the frame saved */
#define JS_FRAME_ID4        0x6A /* u8 copy of the data block's JS_KIND_ID4 bit */
#define JS_FRAME_IMMEDIATE  0x6B /* u8 copy of the data block's JS_KIND_IMMEDIATE bit */
#define JS_FRAME_BIGENDIAN  0x6C /* u8 copy of the data block's JS_KIND_BIGENDIAN bit */
#define JS_FRAME_SAVED_LR   0x54 /* s32 slot of the restored link register (r14, always saved): the handler's PC */

/* Frame context: the first 7 words are a copy of the faulted frame's sticky
 * fields, tail[0..20] the spilled registers r4..r11 too. */
typedef struct JsFrameContext {
    s32 f0, f1, f2, f3, f4, f5, f6;
    s32 tail[21];
} JsFrameContext;

typedef struct JsRecord {           /* a frame's record: copy of the context plus the handler location */
    s32 f0, f1, f2, f3, f4, f5, f6;
    s32 tail[21];
    u8 *entry;
} JsRecord;

typedef struct JsRecordRef {
    s32 result;                     /* +0x00 nonzero while the record is in use */
    s32 handler;                    /* +0x04 handler of the record */
    void *unused;                   /* +0x08 */
    u8 *data;                       /* +0x0C the record's data block */
} JsRecordRef;

typedef struct JsResume {
    u8 *data;                       /* +0x00 the record's data block */
    s32 opcode;                     /* +0x04 opcode that resumes the handler */
} JsResume;

/* One entry of the unit kind table (gUnitKindTable, 0x70 = UNIT_KIND_STATS_SIZE
 * bytes per kind): the kind's build cost (unit kind stats +0x00, see
 * UNIT_KIND_STATS_COST) and its movement and combat numbers.  The not-yet-named
 * fields are kept as raw bytes. */
#define UNIT_KIND_STATS_NAME     0x00 /* u16: the kind's build cost (misnamed, kept for old code) */
#define UNIT_KIND_STATS_POWER    0x04 /* u16 attack power the AI's damage estimates multiply */
#define UNIT_KIND_STATS_FUEL_COST 0x56 /* s8 *: per-terrain fuel cost table, 0x20 terrain entries */
#define UNIT_KIND_STATS_LOSE_FUEL 0x5C /* u8 per kind: terrain (MAP_TERRAIN_PLAIN-based) kinds the unit loses fuel on */
#define UNIT_KIND_STATS_LOSE_FUEL2 0x5D /* u8 per kind: a second kind the unit loses fuel on */

/* The unit kinds the menus list, in display order (gUnitKindMenuList): the unit
 * list and the CO-zone panel walk it and stop at the trailing 0 entry. */
#define UNIT_KIND_DISPLAY_COUNT 27 /* entries in gUnitKindMenuList, sentinel included */
typedef struct DisplayUnitKindList {
    u8 values[UNIT_KIND_DISPLAY_COUNT]; /* +0x00: unit kinds in display order, 0 ends the list */
} DisplayUnitKindList;

typedef struct RecordsScreen {
    u16 flags;           /* +0x00 */
    s16 fadeCursor;      /* +0x02: position in fadeList, -1 before the first step */
    s16 fadeCount;       /* +0x04: number of entries in fadeList */
    s16 fadeList[1];     /* +0x06: record order walked by RecordsMenu_AdvanceFadeRecord */
    u8  pad08[0x7E];     /* +0x08 */
    s16 fadeTop;         /* +0x86: fade-out timer of the main screen */
    s16 fadeBottom;      /* +0x88: fade-out timer of the sub screen */
    s8  actionMode;      /* +0x8A: mode argument of the pending action */
    u8  pad8B;
    s16 lastHighlight;   /* +0x8C: highlighted record the cursor last moved from */
    s16 highlighted;     /* +0x8E: highlighted record, -1 when none */
    s16 pending;         /* +0x90: record a pending action applies to, -1 when none */
    s16 tab;             /* +0x92: record group shown (0..2) */
    s16 cursorRow;       /* +0x94: cursor row inside the visible window */
    s16 scrollGoal;      /* +0x96: scroll position the list is animating to */
    s16 scroll;          /* +0x98: top visible row */
    s16 count;           /* +0x9A: number of records */
    s16 selectable;      /* +0x9C: number of enabled records */
    s16 stepAnim;        /* +0x9E: one scroll step is being animated */
    s16 actionTimer;     /* +0xA0: countdown before a pending action runs */
    u8  enabled[0x40];   /* +0xA2: per-record enabled flag */
    s16 listCursor;      /* +0xE2: cursor into the shuffled enabled list */
    s16 listCount;       /* +0xE4: number of entries in that list */
    s16 list[1];         /* +0xE6: shuffled record indices */
} RecordsScreen;

/* The records screen's global state wrapper (gRecordsMenuState): its state word
 * at +0 and the heap-allocated RecordsScreen the menu works on at +8. */
#define RECORDS_MENU_FLAGS  0x00 /* u16 menu state bits, bit 0 = the screen is open */
#define RECORDS_MENU_SCREEN 0x08 /* RecordsScreen * freed when the screen closes */

/* One entry of the records screen's music list (gRecordTracks, RECORD_TRACK_SIZE
 * bytes per entry): the track to play, the colour of its list row and how long
 * it lasts.  A zeroed entry terminates the table. */
typedef struct RecordTrack {
    s32 trackId;    /* +0x00: packed track id: low 16 bits the sound, 0x10000 an archive sound */
    u32 color;      /* +0x04: colour of the record's list row */
    s32 length;     /* +0x08: length of the track in frames */
} RecordTrack;

#define RECORD_TRACK_SIZE 0x0C /* bytes per RecordTrack */
/* Frames a selected record's pending action waits on top of the record's own
 * length (RecordsScreen::actionTimer). */
#define RECORDS_ACTION_DELAY 0x258

/* Special values RecordsMenu_PlayTrack accepts besides a gRecordTracks index. */
#define RECORD_TRACK_STOP 100 /* stop the music: fade it out over the default 30 frames */
#define RECORD_TRACK_WAIT 101 /* create a sprite that waits for the music to finish fading */

/* One entry of the records/achievements table (gRecordTable): 3 groups of 39
 * entries of 0x30 bytes.  The entry names the thing a record counts and the
 * value thresholds for its three tiers. */
typedef struct RecordDefinition {
    u32 present;        /* +0x00 nonzero while the entry is in use */
    u16 id;             /* +0x04 id of the unit/event the record counts */
    u16 group;          /* +0x06 group (0..2) the record's counts add up in */
    u32 bronze;         /* +0x08 tier 1 threshold */
    u32 silver;         /* +0x0C tier 2 threshold */
    u32 gold;           /* +0x10 tier 3 threshold */
    u32 value;          /* +0x14 id describing what the record's value holds */
    u8 weight;          /* +0x18 how much one count weighs when picking a favourite */
    u8 pad19[3];
    u32 tierText[3];    /* +0x1C text ids of the three tiers' descriptions */
    u8 pad28[8];
} RecordDefinition;     /* 0x30 bytes */

#define RECORD_DEFINITION_SIZE 0x30 /* bytes per RecordDefinition */
#define RECORD_GROUP_STRIDE    0x750 /* bytes per group of the table (39 entries) */
#define RECORD_GROUP_COUNT     3    /* groups in gRecordTable */

/* One entry of the record-rank table (gRecordRankTable): the text id naming the
 * rank and the earned record tiers (GetEarnedRecordTierTotal) needed to reach it.
 * The entries run from the best rank down to the worst. */
typedef struct RecordRankEntry {
    u32 textId;    /* +0x00 text id naming the rank */
    u32 threshold; /* +0x04 earned record tiers needed for the rank */
} RecordRankEntry;
#define RECORD_RANK_COUNT 20 /* entries in gRecordRanks: ranks 0 (best) to 19 */

/* Text ids of the record screen's empty rows: shown when the player has no
 * favourite record group or record yet. */
#define FAVOURITE_GROUP_TEXT_NONE  0xc0000021 /* GetFavouriteGroupTextId's text id when no group is set */
#define FAVOURITE_RECORD_TEXT_NONE 0xc0000025 /* GetFavouriteRecordTextId's text id when no record is set */

/* Counter blocks of gRecordValues, one per record group: a record of group N
 * counts at gRecordValues[record->id + RECORD_VALUE_GROUP_N_BASE]. */
#define RECORD_VALUE_GROUP0_BASE 0x00
#define RECORD_VALUE_GROUP1_BASE 0x28
#define RECORD_VALUE_GROUP2_BASE 0x43 /* the per-unit-kind counters, RECORD_UNIT_KIND_BASE */

/* Base of the per-unit-kind counters in gRecordValues: the count for a unit kind
 * is at gRecordValues[RECORD_UNIT_KIND_BASE + kind]. */
#define RECORD_UNIT_KIND_BASE 0x43

/* Number of counters in gRecordValues (94 words, the SaveWords376 record the
 * settings save copies whole). */
#define RECORD_VALUE_COUNT 94

/* Saturation caps of the gRecordValues counters: ordinary record values are
 * shown with six digits, the (larger) record-funds pool with eight. */
#define RECORD_VALUE_MAX 999999u   /* AddRecordValue's cap, the six-digit display maximum */
#define RECORD_FUNDS_MAX 99999999u /* AddRecordFunds' cap, the eight-digit maximum */

/* Cap of the play- and turn-time counters (IncrementCounter): 999:59:59 at the
 * 60 Hz tick the counters advance on. */
#define TIME_COUNTER_MAX 0x0CDFE5C4u

/* 3D sprite layer the ov000 map info window's own sprite is created in. */
#define OV000_INFO_SPRITE_LAYER 8

/* Panels of the ov000 map info window (the box that follows the map cursor). */
enum {
    OV000_INFO_IDLE = 1,        /* no panel shown */
    OV000_INFO_TERRAIN = 2,     /* terrain / unit info panel */
    OV000_INFO_NO_TERRAIN = 3,  /* info panel with nothing selected */
    OV000_INFO_UNIT_STATS = 4   /* detailed unit statistics panel */
};

/* State of the ov000 map info window, one instance in ov000. */
typedef struct Ov000InfoMenu {
    void *statsWindow;   /* +0x00: unit statistics panel object */
    void *panel;         /* +0x04: terrain / unit info panel controller */
    s32 state;           /* +0x08: panel currently shown, OV000_INFO_* */
    s32 pendingState;    /* +0x0C: panel requested this frame */
    u8 refresh;          /* +0x10: panel content must be rebuilt */
    u8 trigger;          /* +0x11: re-read the cell under the cursor */
    u8 pressed;          /* +0x12: confirm button state last frame */
    u8 hasUnit;          /* +0x13: cursor cell holds a unit */
    s8 prevMode;         /* +0x14: map interaction mode last frame */
    s16 cursorX;         /* +0x16: cell under the cursor */
    s16 cursorY;         /* +0x18 */
    s8 animFrame;        /* +0x1A: cursor blink timer, -1 = not blinking */
    s32 language;        /* +0x1C: LANGUAGE_* the window was created with; picks its frame graphics */
} Ov000InfoMenu;

/* The ov000 unit-statistics window, allocated by Ov000_StatsWindow_Create and
 * drawn on the sub engine; it owns the unit panel descriptor at +0x10. */
typedef struct Ov000StatsWindow {
    s32 toggle;      /* +0x00 alternates each redraw, copied to the info panel */
    s32 drawMode;    /* +0x04 0 idle, 1/2 a full redraw was requested */
    s32 blinkFrame;  /* +0x08 blink counter, 0..79 */
    u8  hasUnit;     /* +0x0C set while a unit is shown (Ov000_InfoWindow_SetUnitFlags) */
    u8  pad0D[3];
    void *panel;     /* +0x10 0x104-byte unit panel descriptor */
} Ov000StatsWindow; /* 0x14 bytes */

/* The ov000 map info window's terrain/unit info panel controller (0x1C bytes,
 * created by Ov000_InfoPanel_Create; it owns the 0x11C-byte record block at
 * +0x18). Ov000_InfoWindow_Update sets NO_TERRAIN for the terrain panel and
 * clears it for the unit panel. */
#define OV000_INFO_PANEL_DRAW_MODE   0x04 /* s32 0 idle, 1/2 a redraw was requested */
#define OV000_INFO_PANEL_COUNTER     0x08 /* s32 per-frame draw counter, wraps at 90 */
#define OV000_INFO_PANEL_HAS_UNIT    0x14 /* u8 set while a unit's info is shown */
#define OV000_INFO_PANEL_NO_TERRAIN  0x15 /* u8 set when the panel has nothing selected */
#define OV000_INFO_PANEL_RECORDS     0x18 /* void * 0x11C-byte record block (four 0x38-byte unit records at +0x3C) */
#endif

/* Current key input state; the global gKeyState points at one of these. */
typedef struct KeyState {
    u16 pressed;     /* +0x00: keys newly pressed this frame */
    u16 repeat;      /* +0x02: keys auto-repeating while held */
    u16 repeat2;     /* +0x04: second auto-repeat tier */
    u16 held;        /* +0x06: keys held now */
    u16 prevHeld;    /* +0x08: keys held on the previous frame */
    u16 prevHeld2;   /* +0x0A: keys held two frames ago (release detection) */
    u8 repeatDelay;  /* +0x0C: auto-repeat delay counter */
    u8 repeatRate;   /* +0x0D: auto-repeat rate counter */
} KeyState;

/* Input lock/suspend state (gInputBlockState): countdowns during which key and
 * touch input are ignored, plus the flags that suspend input while the display
 * is off and that block injected key presses. */
typedef struct InputBlockState {
    s8 inputLockFrames;   /* +0x00 frames input stays ignored (>0 locks it) */
    u8 inputDisabled;     /* +0x01 nonzero: input disabled while the display is off */
    u8 suspendRequested;  /* +0x02 nonzero: a screen-off was requested */
    u8 keyInjectBlocked;  /* +0x03 nonzero: injected key presses are ignored */
    s8 inputLockFrames2;  /* +0x04 second input lock countdown */
} InputBlockState;

/* A scalar tween evaluated by GetSpriteAnimValue and advanced by
 * UpdateSpriteAnimation (the anim script runner fills it in). */
typedef struct SpriteTween {
    u8  mode;       /* +0x00: interpolation curve, SPRITE_TWEEN_* */
    u8  done;       /* +0x01 nonzero: stop advancing */
    u16 current;    /* +0x02 frames elapsed */
    u16 start;      /* +0x04 value current is reset to */
    u16 step;       /* +0x06 frames added per update */
    s16 base;       /* +0x08 constant offset added to the curve */
    s16 amplitude;  /* +0x0A curve amplitude */
    s16 duration;   /* +0x0C frames of the fade */
    s16 from;       /* +0x0E start value */
    s16 to;         /* +0x10 end value */
} SpriteTween;

enum {
    SPRITE_TWEEN_SINE = 0,     /* base + amplitude * sin(current) */
    SPRITE_TWEEN_LINEAR = 1,   /* from -> to, linear */
    SPRITE_TWEEN_CONSTANT = 2, /* from * amplitude, current ignored */
    SPRITE_TWEEN_EASE_IN = 3,  /* from -> to, quadratic ease-in */
    SPRITE_TWEEN_EASE_OUT = 4  /* from -> to, quadratic ease-out */
};

/* The three SpriteTweens an animated menu object steps together each frame
 * (StepSpriteTweenGroup), and the object's cached copy of the first tween's
 * value (0x2A): while the two still agree the third tween runs ease-out. */
#define SPRITE_TWEEN_FIRST  0x30 /* first SpriteTween */
#define SPRITE_TWEEN_SECOND 0x42 /* second SpriteTween */
#define SPRITE_TWEEN_THIRD  0x54 /* third SpriteTween */
#define SPRITE_TWEEN_CACHED 0x2A /* s16 cached value of the first tween */

/* One entry of a SpriteAnimPlayer's frame table (12 bytes): the segment runs
 * until the player's frame counter reaches endFrame, the tween moving towards
 * value on the given curve.  mode -1 marks the table's end. */
typedef struct SpriteAnimFrame {
    s16 endFrame; /* +0x00 frame counter at which this segment ends */
    s32 mode;     /* +0x04 SPRITE_TWEEN_* curve, -1 ends the table */
    s16 value;    /* +0x08 value the tween reaches at endFrame */
} SpriteAnimFrame;

/* An animation player stepped by StepAnimationFrames: it owns a SpriteTween that
 * the frame entries drive, the frame table it walks and the entry playing now. */
typedef struct SpriteAnimPlayer {
    SpriteTween *tween;      /* +0x00 tween the frame entries drive */
    SpriteAnimFrame *frames; /* +0x04 start of the frame table */
    SpriteAnimFrame *frame;  /* +0x08 frame entry playing now */
    u16 index;               /* +0x0C frame counter, absolute across the table */
    u8  done;                /* +0x0E nonzero: stop stepping */
    u8  ended;               /* +0x0F the table's end marker was reached */
} SpriteAnimPlayer;

/* Streaming voice state (the ov010 gStreamVoiceState object).  The voice reads from
 * two sample buffers that the stream callback refills. */
#define STREAM_VOICE_DATA_READY      0x00 /* s32 set when the segment callback received a voice packet (IsVoiceDataReady) */
#define STREAM_VOICE_ACTIVE          0x04 /* s32 voice started */
#define STREAM_VOICE_FLIP            0x08 /* s32 which buffer is being filled */
#define STREAM_VOICE_BUFFER1         0x0C /* first sample buffer */
#define STREAM_VOICE_BUFFER2         0x1C /* second sample buffer */
#define STREAM_VOICE_BUFFER2_SIZE    0x14 /* bytes allocated for the second buffer */
#define STREAM_VOICE_BUFFER1_SIZE    0x18 /* bytes allocated for the first buffer */
#define STREAM_VOICE_PAUSED          0x10 /* s32 voice paused */

/* Touch-screen tracking state, reached through *(gKeyState + 4). */
#define TOUCH_CUR_X        0x00 /* u16 current touch x */
#define TOUCH_CUR_Y        0x02 /* u16 current touch y */
#define TOUCH_START_X      0x04 /* u16 x where the touch began */
#define TOUCH_START_Y      0x06 /* u16 y where the touch began */
#define TOUCH_MIN_X        0x08 /* u16 leftmost x reached */
#define TOUCH_MIN_Y        0x0A /* u16 topmost y reached */
#define TOUCH_MAX_X        0x0C /* u16 rightmost x reached */
#define TOUCH_MAX_Y        0x0E /* u16 bottommost y reached */
#define TOUCH_HOLD_FRAMES  0x10 /* u8 frames the touch has been held, capped at 0xff */
#define TOUCH_REPEAT_TIMER 0x11 /* u8 frames left before the next repeat */
#define TOUCH_ACTIVE       0x12 /* u8 touch currently down */
#define TOUCH_PRESSED      0x13 /* u8 press or repeat delivered this frame */
#define TOUCH_STARTED      0x14 /* u8 touch began this frame */
#define TOUCH_TAP          0x15 /* u8 touch was a short tap */
#define TOUCH_RELEASED     0x16 /* u8 touch ended this frame */
#define TOUCH_DRAG_FRAMES  20   /* TOUCH_HOLD_FRAMES value at which a hold becomes a drag */

/* Press state of a sprite-button slot (GetSpriteSlotState/SetSpriteSlotState). */
enum {
    SPRITE_SLOT_IDLE    = 0, /* not touched */
    SPRITE_SLOT_PRESSED = 1, /* touch down inside the slot, waiting for release */
    SPRITE_SLOT_DRAGGED = 2  /* held past TOUCH_DRAG_FRAMES */
};

/* The CO "occupation" cut-in effect object used by main_020C1F58.  It shares
 * the battle-effect header layout (vtable at +0, timers at +0x34) but its
 * pointers at +0x40/+0x4C hold CO data and a palette instead. */
typedef struct OccupationEffect {
    u8   pad00[0x34];
    u8   frame;      /* +0x34: animation frame counter */
    u8   active;     /* +0x35: cut-in is running */
    u8   variant;    /* +0x36: portrait variant */
    u8   startFrame; /* +0x37: frame at which the portrait starts */
    u8   endFrame;   /* +0x38: frame at which the cut-in ends */
    u8   progress;   /* +0x39: portrait rows revealed / voices played */
    u8   pad3A[2];
    void *sprite;    /* +0x3C: panel sprite object */
    u8   *co;        /* +0x40: capture parameters, the battle-effect block: [0] player, [1] terrain kind (asset),
                      * [2] owning/property army id, [3] capturing unit's army id, [5] capture points (rows) */
    u16  *spriteA;   /* +0x44: sprite effect object (special variant) */
    u16  *spriteB;   /* +0x48: sprite effect object (normal) */
    void *palette;   /* +0x4C: palette object */
    u8   flags;      /* +0x50: bit0/bit1 toggles, bits 2..7 selected state */
} OccupationEffect;

/* The battle-start "break" cut-in effect state (built by the main_020C3D34
 * create function): the diagonal-line banner with the CO's name and face.  The two band offsets are the left and right halves' positions, the
 * window fields the bank split that the banner slides through, and rows the cell
 * rows each half draws. */
typedef struct BreakCutIn {
    s32 frame;         /* +0x00 frames the cut-in has run; its step phases are keyed on it */
    s32 holdTimer;     /* +0x04 timer of the hold step; the cut-in ends at 64 */
    s16 co;            /* +0x08 army/CO id whose face, palette and name are shown */
    s16 offsetX;       /* +0x0A band x offset, wraps at 256 (bank corner x) */
    s16 offsetY;       /* +0x0C band y offset, wraps at 256 (bank corner y) */
    u8  filler_0E[2];
    s32 scale;         /* +0x10 fixed-point zoom of the band's tile grid */
    s16 windowRight;   /* +0x14 split window 0 right bound (bank window0H[0]) */
    s16 windowBottom;  /* +0x16 split window 0 bottom bound (bank window0V[0]) */
    s16 windowLeft;    /* +0x18 split window 0 left bound (bank window0H[1]) */
    s16 windowTop;     /* +0x1A split window 0 top bound (bank window0V[1]) */
    s16 bandLeftX;     /* +0x1C x of the left half's first sprite */
    s16 bandLeftY;     /* +0x1E y of the left half's first sprite */
    s16 bandRightX;    /* +0x20 x of the right half's first sprite */
    s16 bandRightY;    /* +0x22 y of the right half's first sprite */
    s16 rows;          /* +0x24 cell rows each half draws (bank rowsAbove/rowsBelow) */
} BreakCutIn;

/* The 20-byte battle-command packet at gBattleCommand (sent by
 * SendBattleCommandPacket and SendTurnEndPacket): the random seed the battle uses
 * is captured in the s32 at +8. */
#define BATTLE_COMMAND_SEED 0x08

/* The link command queues (gLinkCommandQueues): one FIFO of incoming command
 * messages per command source, 12 bytes of queue head each. */
#define LINK_COMMAND_QUEUE_COUNT  4
#define LINK_COMMAND_QUEUE_STRIDE 12
#define LINK_MSG_COMMAND_BASE     0x81
#define LINK_COMMAND_HEADER_SIZE  2 /* type byte and a fixed flag byte before a queued command's payload */

typedef struct LinkReceivedMessage {
    u8 unk_00[4];
    u8 type;
    u8 unk_05[3];
    s32 payloadSize;
    u8 payload[1];
} LinkReceivedMessage;

typedef struct LinkCommandEntry {
    u8 payload[32];
    u16 payloadSize;
    s16 unk_22;
    struct LinkCommandEntry *next;
} LinkCommandEntry;

typedef struct LinkCommandQueue {
    LinkCommandEntry *head;
    LinkCommandEntry *tail;
    u32 unk_08;
} LinkCommandQueue;

/* DS key bits, as stored in the KeyState masks. */
enum {
    KEY_A = 0x0001, KEY_B = 0x0002, KEY_SELECT = 0x0004, KEY_START = 0x0008,
    KEY_RIGHT = 0x0010, KEY_LEFT = 0x0020, KEY_UP = 0x0040, KEY_DOWN = 0x0080,
    KEY_R = 0x0100, KEY_L = 0x0200, KEY_X = 0x0400, KEY_Y = 0x0800
};

/* L+R+START+SELECT: held together it soft-resets the console. */
#define KEY_RESET_COMBO (KEY_L | KEY_R | KEY_START | KEY_SELECT)

/* The keys that count as a player's response while a screen waits for input. */
#define KEY_INPUT_RESPONSE (KEY_A | KEY_B | KEY_START | KEY_X | KEY_Y)

/* Entries of the KeyState masks (gKeyState). */
#define KEY_HELD    0 /* u16 keys held this frame */
#define KEY_PRESSED 1 /* u16 keys newly pressed this frame */

/* The unit-production menu's state object (gProductionMenuState): the mask of unit-kind
 * capability flags the selected base may build, the number of entries listed, then the
 * entries themselves as 2-byte {kind, unaffordable} pairs (gProductionMenuState+0x08). */
typedef struct ProductionMenuState {
    s32 kindMask;    /* +0x00 mask of buildable unit-kind capability flags */
    s32 count;       /* +0x04 number of entries in the buffer */
    u8  entries[1];  /* +0x08 first of the {u8 kind; u8 unaffordable;} entries */
} ProductionMenuState;

#define PRODUCTION_MENU_KIND_MASK 0x00 /* s32 ProductionMenuState.kindMask */
#define PRODUCTION_MENU_COUNT     0x04 /* s32 ProductionMenuState.count */

/* Build masks stored in ProductionMenuState.kindMask: a unit kind is listed when
 * its capability flags (UNIT_KIND_STATS_FLAGS) share a bit with the mask. */
#define PRODUCTION_BUILD_GROUND 0x07 /* ground kinds, built at the ground facilities */
#define PRODUCTION_BUILD_AIR    0x10 /* air kinds, built at an airport */
#define PRODUCTION_BUILD_NAVAL  0x20 /* naval kinds, built at a port */

/* The production menu's list of buildable entries (gProductionChoices): up
 * to PRODUCTION_MENU_PAGE_ENTRIES {kind, unaffordable} byte pairs, terminated
 * by a zero kind. */
#define PRODUCTION_MENU_PAGE_ENTRIES    7 /* entries drawn on one page of the menu */
#define PRODUCTION_MENU_CHOICE_KIND     0 /* u8: unit kind, 0 ends the list */
#define PRODUCTION_MENU_UNAFFORDABLE    1 /* u8: 1 when the player cannot pay for that kind yet */

/* The per-kind row object the production menu creates (CreateProductionMenuRow):
 * the unit kind it will build, and the frame counter of the funds line's count-up. */
#define PRODUCTION_ROW_KIND     0x5C /* s32 unit kind the row is about */
#define PRODUCTION_ROW_FRAME    0x6C /* s16 frames elapsed */
#define PRODUCTION_ROW_DURATION 0x6E /* s16 frames the count-up takes */

/* ov000 unit-list menu object (singleton returned by GetScrollList). */
typedef struct ScrollList {
    u8 pad00[0x34];
    s16 tab;          /* +0x34: selected tab (0..3) */
    s16 reverse;      /* +0x36: reverse sort order toggle (0/1) */
    s16 animPos;      /* +0x38: animated scroll offset (eased toward scrollPos*2) */
    s16 scrollPos;    /* +0x3A: first visible row */
    s16 count;        /* +0x3C: number of rows */
    s16 animating;    /* +0x3E: scroll animation in progress */
    s16 selectedId;   /* +0x40: unit id shown by the info panel */
    void *spriteUp;   /* +0x44: list-up arrow sprite */
    void *spriteDown; /* +0x48: list-down arrow sprite */
} ScrollList;

/* The unit-list menu's row list (gUnitListRows): the list's pixel scroll value
 * followed by the buffer of unit slots to show, which ScrollListRebuild sorts. */
#define UNIT_LIST_ROW_CAPACITY 64 /* slots in the row list buffer (bytes) */
#define UNIT_LIST_SCROLL_VALUE 0 /* s32 the list's pixel scroll value */
#define UNIT_LIST_ROWS_PTR     4 /* u8 *sorted row-slot buffer, UNIT_LIST_ROW_CAPACITY bytes */

/* Geometry of the unit list's clickable buttons: one highlight sprite per visible
 * row, 16 px apart and starting at y 39, 4 px in from the left; the four tab buttons
 * sit across the top and carry the slot ids 251 (tab 0) down to 248 (tab 3). */
#define SCROLL_LIST_VISIBLE_ROWS 6
#define SCROLL_LIST_ROW_X        4
#define SCROLL_LIST_ROW_Y        39
#define SCROLL_LIST_ROW_STEP     16
#define SCROLL_LIST_TAB_ID(tab)  (251 - (tab))

/* Flags byte of a gpi player record (player + 0x15): which optional parts follow. */
enum {
    GPI_REC_FLAG_ID     = 0x02, /* a 4-byte id follows */
    GPI_REC_FLAG_VALUE  = 0x08, /* a 4-byte value follows */
    GPI_REC_FLAG_SKIP   = 0x10, /* a big-endian 2-byte server port follows; it is read as the server's port and then skipped by the player parser */
    GPI_REC_FLAG_PORT   = 0x20, /* a big-endian 2-byte port follows (else the context default) */
    GPI_REC_FLAG_FIELDS = 0x40, /* typed key/value fields follow, per the context schema */
    GPI_REC_FLAG_KEYS   = 0x80  /* raw zero-terminated key/value pairs follow */
};

/* Length of a gpi record's header before the variable sections its flags name:
 * the flags byte itself and the server's 4-byte address, which head every
 * record (gpiRecordHeaderLength adds the optional parts to it). */
#define GPI_RECORD_HEADER_BASE 5

/* Type of a field in a gpi record schema (entry[1]). */
enum {
    GPI_FIELD_STRING = 0, /* zero-terminated string */
    GPI_FIELD_BYTE   = 1,
    GPI_FIELD_PORT   = 2  /* big-endian 16-bit */
};

/* Bits of a gpi player's state byte (player + 0x14): what sections of a reply
 * have been applied, which query the record was sent for, and whether the reply
 * is complete. */
enum {
    GPI_PLAYER_STATE_FIELDS = 1, /* a fields section has been applied */
    GPI_PLAYER_STATE_KEYS   = 2, /* a key/value section has been applied */
    GPI_PLAYER_QUERY_MASK   = 0x0C, /* bits 2..3: one-hot kind of query the record was sent for */
    GPI_PLAYER_QUERY_KEYS   = 0x04, /* the query asked for the record's named keys only */
    GPI_PLAYER_QUERY_INFO   = 0x08, /* the query asked for the record's whole info */
    GPI_PLAYER_QUERY_CLEAR  = 0xF3, /* a state byte with GPI_PLAYER_QUERY_MASK cleared */
    GPI_PLAYER_STATE_COMPLETE = 0x40 /* the reply arrived in full, the query is done */
};

/* Fields of a gpi peer record (64 bytes, gpiCreatePeer). */
#define GPI_PEER_STATE      0x00 /* s32 one of GPI_PEER_STATE_* */
#define GPI_PEER_INITIATOR  0x04 /* s32 1 when this side opened the connection, 0 when it accepts one */
#define GPI_PEER_SOCKET     0x08 /* s32 socket handle, -1 until opened */
#define GPI_PEER_PLAYER_ID  0x0C /* s32 player id this peer speaks for */
#define GPI_PEER_DEADLINE   0x10 /* s32 gpiGetTime() value after which the handshake times out */
#define GPI_PEER_RX_BUFFER  0x18 /* GPIBuffer of peer messages read so far */
#define GPI_PEER_TX_BUFFER  0x28 /* GPISendBuffer of bytes queued for the peer */
#define GPI_PEER_PENDING    0x30 /* s32 bytes of the send buffer still to go out */
#define GPI_PEER_CALLBACKS  0x38 /* s32 Vector of the peer's queued callbacks */
#define GPI_PEER_NEXT       0x3C /* void *next peer in the manager's list */

/* State of a gpi peer connection (peer->state at +0x00). */
enum {
    GPI_PEER_STATE_CREATED     = 100, /* allocated, no challenge answered yet */
    GPI_PEER_STATE_CHALLENGED  = 101, /* challenge sent, awaiting the answer */
    GPI_PEER_STATE_PROGRESSING = 102, /* authentication reply built, socket being opened */
    GPI_PEER_STATE_CONNECTING  = 103, /* socket opened, awaiting the TCP connect */
    GPI_PEER_STATE_WAITING     = 104, /* waiting for the peer's \auth\ reply */
    GPI_PEER_STATE_CONNECTED   = 105, /* ready: relay game data messages */
    GPI_PEER_STATE_ERROR       = 106  /* failed; the peer is torn down */
};

/* Message kinds carried in a gpi message's \m\ field. */
enum {
    GPI_MSG_PLAYER_INFO     = 1,   /* player id/name announcement */
    GPI_MSG_CHALLENGE       = 102, /* challenge request */
    GPI_MSG_CHALLENGE_REPLY = 103, /* answer to a challenge request */
    GPI_MSG_GAME_DATA_FIRST = 200,
    GPI_MSG_XFER_REPLY      = 201, /* answer to a \xfer\ game-data transfer */
    GPI_MSG_GAME_DATA_LAST  = 208
};

/* The player-info message record a gpi GPI_MSG_PLAYER_INFO callback receives
 * (built in main_020543E8): the sender's id, its arrival time and its text. */
#define GPI_PLAYER_INFO_ID   0x00 /* s32 the sender's player id */
#define GPI_PLAYER_INFO_TIME 0x04 /* s32 gpiGetTime() when the message arrived */
#define GPI_PLAYER_INFO_TEXT 0x08 /* char *the message's text */

/* The \version\ value the game's gpi messages carry in their body. */
#define GPI_PROTOCOL_VERSION 1

/* A game-data message's \xfer\ field: three numbers (key gGpiXferKey, format
 * gGpiXferLocationFormat) locating the data a transfer asks for.  The peers only
 * relay game data, so the reply echoes the location with this result code. */
#define GPI_XFER_RESULT_UNSUPPORTED 2

/* GameSpy gpi receive buffer (the connection field at +0x1DC, and a peer's
 * message buffer at peer + 0x18): storage, the allocated size, the number of
 * bytes currently held and, for a peer buffer, the read position of the next
 * message. */
/* Appending strings grows storage by at least this many bytes, plus a terminator. */
#define GPI_BUFFER_GROWTH 0x800

typedef struct GPIBuffer {
    void *data; /* +0x00 storage */
    s32   size; /* +0x04 allocated bytes */
    s32   len;  /* +0x08 bytes used */
    s32   pos;  /* +0x0C read position of the next message (peer buffers only) */
} GPIBuffer;

/* GameSpy gpi send buffer (the peer field at +0x28): storage, its allocated
 * size, the number of bytes queued and the offset of the first byte that has
 * not been sent yet. */
typedef struct GPISendBuffer {
    void *data; /* +0x00 storage */
    s32   size; /* +0x04 allocated bytes */
    s32   len;  /* +0x08 bytes queued */
    s32   pos;  /* +0x0C offset of the first unsent byte */
} GPISendBuffer;

/* One key/value entry of a GameSpy gpi bucket (gbucket.c, the store behind the
 * gpiValue* helpers).  A numeric entry keeps its value inline at +0x0C; a string
 * entry owns a pointer there. */
#define GPI_BUCKET_KEY    0x00 /* char *: the entry's key (owned copy) */
#define GPI_BUCKET_TYPE   0x04 /* s32: GPI_BUCKET_* value type */
#define GPI_BUCKET_COUNT  0x08 /* s32: samples folded in by gpiValueAverage */
#define GPI_BUCKET_VALUE  0x0C /* s32, double or owned char * depending on the type */
enum {
    GPI_BUCKET_INT    = 0, /* bt_int */
    GPI_BUCKET_DOUBLE = 1, /* bt_double */
    GPI_BUCKET_STRING = 2  /* bt_string */
};

/* The gbucket.c module's scratch state (gGpiBucketScratchState): BucketIntValue
 * and BucketDoubleValue assemble a temporary value here for BucketSetValue, and
 * the bucket store used when a caller passes NULL is kept at +4.  The temporary
 * double (gGpiBucketTmpDouble) is the second half of the same block. */
#define GPI_BUCKET_SCRATCH_INT    0x00 /* s32: temporary integer value */
#define GPI_BUCKET_SCRATCH_STORE  0x04 /* void *: default bucket store */
#define GPI_BUCKET_SCRATCH_DOUBLE 0x08 /* double: temporary double value */

/* A queued GameSpy gpi callback (gpiCallback.c).  gpiCallCallback invokes
 * callback.callback(connection, arg, callback.param) and then frees arg
 * according to type. */
typedef struct GPICallbackData {
    struct {
        void (*callback)(void *connection, void *arg, void *param); /* +0x00 */
        void *param;                                                 /* +0x04 */
    } callback;
    void *arg;                    /* +0x08 typed data handed to the callback */
    s32   type;                   /* +0x0C GPI_CALLBACK_* */
    s32   operationId;            /* +0x10 id of the operation that queued it */
    struct GPICallbackData *next; /* +0x14 next queued callback */
} GPICallbackData;

/* GPICallbackData.type: the layout of its arg and what gpiCallCallback frees
 * after the callback has run. */
enum {
    GPI_CALLBACK_ERROR         = 1, /* arg is one block; run whatever the operation */
    GPI_CALLBACK_PLAYER_INFO   = 2, /* arg->name at +0x08 is an owned string */
    GPI_CALLBACK_INFO_LISTS    = 3, /* arg owns the two string lists at +0x3C/+0x40 */
    GPI_CALLBACK_INFO_RECORDS  = 4, /* arg owns the record array at +0x0C */
    GPI_CALLBACK_OWNED_POINTER = 7, /* arg owns the pointer at +0x10 */
    GPI_CALLBACK_RECORD_LIST   = 8, /* arg owns the record array at +0x08 */
    GPI_CALLBACK_STRING_LIST   = 9  /* arg owns the array of strings at +0x08 */
};

/* Callback data with an owned string at +0x08 (GPI_CALLBACK_PLAYER_INFO). */
typedef struct GpiPlayerInfoData {
    s32   id;    /* +0x00 */
    s32   time;  /* +0x04 */
    char *name;  /* +0x08 released after the callback */
} GpiPlayerInfoData;

/* Callback data with two owned string lists (GPI_CALLBACK_INFO_LISTS). */
typedef struct GpiInfoListsData {
    u8     pad00[0x38];
    s32    count;   /* +0x38 entries in each list */
    char **names;   /* +0x3C owned list of allocated names */
    char **values;  /* +0x40 owned list of allocated values */
} GpiInfoListsData;

/* Callback data owning one record array at +0x0C (GPI_CALLBACK_INFO_RECORDS). */
typedef struct GpiInfoRecordsData {
    u8   pad00[0x0C];
    void *records; /* +0x0C owned record array */
} GpiInfoRecordsData;

/* Callback data owning the pointer at +0x10 (GPI_CALLBACK_OWNED_POINTER). */
typedef struct GpiOwnedPointerData {
    u8   pad00[0x10];
    void *pointer; /* +0x10 released after the callback when set */
} GpiOwnedPointerData;

/* Callback data owning one record array at +0x08 (GPI_CALLBACK_RECORD_LIST). */
typedef struct GpiRecordListData {
    s32  unknown00; /* +0x00 */
    s32  count;     /* +0x04 number of records */
    void *records;  /* +0x08 owned record array */
} GpiRecordListData;

/* Callback data owning an array of strings (GPI_CALLBACK_STRING_LIST). */
typedef struct GpiStringListData {
    s32    unknown00; /* +0x00 */
    s32    count;     /* +0x04 number of strings */
    char **strings;   /* +0x08 owned array of allocated strings */
} GpiStringListData;

/* Public gpi operations return empty success results in simulation mode. */
#define GPI_CONN_SIMULATION 0x108 /* s32 nonzero bypasses network operations */
#define GPI_CONN_STATE 0x1D8 /* s32 connection state */
#define GPI_STATE_IDLE         0 /* no connection */
#define GPI_STATE_CONNECTING   1 /* the socket is opened and the handshake runs */
#define GPI_STATE_CONNECTED    2 /* the server accepted the socket */
#define GPI_STATE_LOGGED_IN    3 /* the login reply was handled; commands may flow */
#define GPI_STATE_DISCONNECTED 4

/* A gpi call returns 0 on success and this code when it refused to act: a bad
 * argument, an invalid index/status, or an unusable connection. */
#define GPI_ERROR_REFUSED 2

/* A gpi connection's sockets.  The server socket carries the GameSpy
 * connection to the connection manager; the local socket is bound to an
 * ephemeral port for NAT negotiation and only exists when the connection runs
 * without a firewall (GPI_CONN_FIREWALL 0). */
#define GPI_CONN_FIREWALL     0x10C /* s32 firewall mode: 0 no firewall (a local socket is bound), 1 normal */
#define GPI_CONN_SOCKET       0x1D4 /* s32 server socket, -1 until it is created */
#define GPI_CONN_LOCAL_SOCKET 0x204 /* s32 local socket, -1 when unused */
#define GPI_CONN_LOCAL_PORT   0x208 /* u16 port the local socket was bound to, 0 when unused */

/* Socket option level and names the ghi socket helpers hand to the get/set
 * option wrapper. */
#define GHI_SOL_SOCKET 0xFFFF /* level: generic socket options */
#define GHI_SO_SNDBUF  0x1001 /* get/set the send buffer size */
#define GHI_SO_RCVBUF  0x1002 /* get/set the receive buffer size */

/* Port of the GameSpy connection manager, in network byte order (29900). */
#define GPI_MASTER_PORT 0xCC74

/* State gpiCheckConnectionSocket leaves in its argument for a connection's
 * socket: no activity this poll, the connection accepted, or refused. */
#define GPI_SOCKET_NONE     0
#define GPI_SOCKET_ACCEPTED 3 /* the caller's assert names this GPI_CONNECTED */
#define GPI_SOCKET_REFUSED  4
#define GPI_INFO_RESULT_WORDS 129 /* 0x204-byte profile-info callback record */
#define GPI_SEARCH_RESULT_WORDS 4 /* s32 words in a search callback record */
#define GPI_SEARCH_MORE 0x601 /* search status: more result pages follow (0x600 when complete) */

/* Server-message fields in the GameSpy gpi connection. */
#define GPI_CONN_SESSION_KEY 0x198 /* s32 server-issued session key */
#define GPI_CONN_OUTPUT_BUFFER 0x1F4 /* server command send buffer */
#define GPI_MESSAGE_COPY_SIZE 0xDAD /* bounded message copy, including terminator */
#define GPI_MESSAGE_STACK_SIZE 0xDB0 /* aligned temporary message storage */

/* Pending profile updates: AppendUpdateProField/AppendUpdateUiField accumulate
 * fields here and gpiFlushUpdateBuffers moves them to the outgoing buffer. */
#define GPI_CONN_UPDATE_PRO_BUFFER 0x440 /* GPIBuffer: accumulated "updatepro" fields */
#define GPI_CONN_UPDATE_PRO_LEN    0x448 /* s32: bytes pending in it (the buffer's len) */
#define GPI_CONN_UPDATE_UI_BUFFER  0x450 /* GPIBuffer: accumulated "updateui" fields */
#define GPI_CONN_UPDATE_UI_LEN     0x458 /* s32: bytes pending in it (the buffer's len) */

/* The rest of a gpi connection's login identity and message buffers: the user id
 * and profile id from the login reply are the keys its buddy-status records are
 * looked up by (the "\userid\" and "\profileid\" fields). */
#define GPI_CONN_USER_ID     0x19C /* s32 user id from the login reply */
#define GPI_CONN_PROFILE_ID  0x1A0 /* s32 profile id from the login reply */
#define GPI_CONN_RECV_BUFFER 0x1DC /* GPIBuffer: raw data received from the server */
#define GPI_CONN_MSG_BUFFER  0x1EC /* void *parsed message copied out of the receive buffer */

/* A gpi connection's error state and callback queue.  The six 8-byte entries at
 * GPI_CONN_ERROR_CALLBACK are {handler, parameter} pairs that gpiSetPeerCallback
 * fills by index; entry 0 is the error callback gpiCallErrorCallback queues. */
#define GPI_CONN_ERROR_CALLBACK 0x1A4 /* s32 registered error callback function (entry 0's handler) */
#define GPI_CONN_ERROR_DATA     0x1A8 /* s32 parameter passed to it (entry 0's parameter) */
#define GPI_CONN_CALLBACK_COUNT  6    /* entries in the connection's callback table */
#define GPI_CONN_CALLBACK_STRIDE 8    /* bytes per callback entry */
#define GPI_CONN_ERROR_CODE     0x418 /* s32 code last stored by gpiSetError */
#define GPI_CONN_ERROR_FATAL    0x41C /* s32 nonzero once a fatal error was reported */
#define GPI_CONN_CACHED_STATUS  0x214 /* s32 status last handed to gpiSetStatusInfo, -1 when none yet */
#define GPI_CONN_STATUS_STRING  0x218 /* s8[0x100] cached status string */
#define GPI_CONN_LOCATION_STRING 0x318 /* s8[0x100] cached location string */
#define GPI_CONN_CALLBACK_HEAD  0x438 /* GPICallbackData *first queued callback */
#define GPI_CONN_CALLBACK_TAIL  0x43C /* GPICallbackData *last queued callback */
#define GPI_CONN_OPERATIONS     0x424 /* GPIOperation *first pending operation */
#define GPI_CONN_PEER_HEAD      0x434 /* void *first peer of the connection's peer list (linked through GPI_PEER_NEXT) */
#define GPI_CONN_BUDDY_COUNT    0x430 /* s32 buddies in the connection's list, the index bound of gpGetBuddyStatus */
#define GPI_CONN_NEXT_OPERATION_ID 0x20C /* s32 next operation id handed out (starts at 2) */
#define GPI_CONN_SEARCH_COUNT      0x210 /* s32 search operations still pending on the connection */

/* A queued gpi operation (0x24 bytes), a node of the connection's pending
 * operation list.  gpiAddOperation allocates one and prepends it; the stepping
 * code walks the list, stores the result and turns it into a callback. */
typedef struct GPIOperation {
    s32 type;          /* +0x00 operation kind */
    void *data;        /* +0x04 profile, peer or search the operation works on */
    s32 blocking;      /* +0x08 nonzero when the operation must finish before returning */
    s32 callback;      /* +0x0C completion callback */
    s32 callbackParam; /* +0x10 the callback's parameter */
    s32 state;         /* +0x14 operation state */
    s32 id;            /* +0x18 id of the operation */
    s32 result;        /* +0x1C result stored when it completes */
    struct GPIOperation *next; /* +0x20 next pending operation */
} GPIOperation; /* 0x24 bytes */

/* GPIOperation.type: which request the operation carries.  Values follow the
 * GameSpy gpi operation order and are what gpiAddOperation receives. */
enum {
    GPI_OP_CONNECT    = 0, /* open a connection (data: the peer record) */
    GPI_OP_NEW_PLAYER = 1, /* new player notification */
    GPI_OP_GET_INFO   = 2, /* profile info request */
    GPI_OP_SEARCH     = 3, /* profile search */
    GPI_OP_LOGIN      = 4  /* login reply */
};

/* Fatal flag passed to gpiCallErrorCallback. */
enum {
    GP_NON_FATAL = 0, /* the connection stays usable */
    GP_FATAL     = 1  /* the connection is finished */
};

/* GameSpy Presence operation result codes. */
#define GP_NO_ERROR         0
#define GP_MEMORY_ERROR     1
#define GP_PARAMETER_ERROR  2
#define GP_NETWORK_ERROR    3
#define GP_SERVER_ERROR     4

/* Connection session states (the state at GetConnection()->0x1A0) used while
 * the peers agree on their player slots and synchronise. */
enum {
    CONN_STATE_SYNC_PREPARE  = 8,  /* preparing the session with a peer */
    CONN_STATE_WAIT_SLOT     = 9,  /* own player slot is being accepted */
    CONN_STATE_MATCH         = 10, /* the session's match has started; match traffic is live */
    CONN_STATE_SYNC_MEASURE  = 14, /* peers report in; the round trip is being measured */
    CONN_STATE_SYNC_DONE     = 15, /* every connected peer has acknowledged the sync */
    CONN_STATE_WAIT_SYNC_ACK = 16, /* waiting for every peer to acknowledge the sync */
    CONN_STATE_WAIT_SYNC_RTT = 17  /* waiting out the measured latency before completing */
};

/* Peer synchronization notices carried in a connection packet's type field. */
enum {
    PEER_SYNC_PREPARE = 13, /* peer asks us to prepare the session */
    PEER_SYNC_ACK     = 14, /* peer is ready; measure the round trip */
    PEER_SYNC_DONE    = 15  /* the peer's synchronization is complete */
};

/* Connection session fields (in the context returned by GetConnection()) used
 * by the synchronization handshake. */
#define CONN_SESSION_STATE        0x1A0 /* s32 state, one of CONN_STATE_* */
#define CONN_SESSION_SLOT         0x14  /* u8 peer slots in use: the slot arrays are indexed 1..this */
#define CONN_SESSION_PLAYER_COUNT 0x0D  /* u8  number of connected peers */
#define CONN_SESSION_ACTIVE_MAX   0x0E  /* u8  number of set bits in CONN_SESSION_PLAYER_MASK minus 1, 0 when none */
#define CONN_SESSION_PEER_IDS     0xF4  /* s32 peer ids, 4 bytes per slot */
#define CONN_SESSION_READY_MASK   0x1D4 /* u32 bitmask of peers that sent the ready packet (connection packet type 3) */
#define CONN_SESSION_SYNC_ACKS    0x1D8 /* u32 bitmask of peers that answered */
#define CONN_SESSION_SYNC_SENT    0x1E8 /* u64 time the last sync notice was sent */
#define CONN_SESSION_SYNC_EXCESS  0x1B2 /* u16 worst overrun of the sync deadline */
#define CONN_SESSION_SYNC_RETRY   0x1AC /* u8 retry counter for the sync-measure notices */
#define CONN_SESSION_SLOT_RETRY      0x1AD /* u8 times our player slot has been requested from the peer */
#define CONN_SESSION_SLOT_RETRY_TICK 0x1F8 /* u64 time that slot request was last sent */
#define CONN_SESSION_PEER_SLOTS   0x2D0 /* u8 slot id per connected peer, indexed from 1 */
#define CONN_SESSION_NO_PEER_SLOT 0xFF /* FindPeerSlot result when no connected peer has the wanted id */
#define CONN_SESSION_PEER_DATA    0x24  /* s32 per slot: peer player id exchanged in connection packets */
#define CONN_SESSION_PEER_DATA_PORT 0xA4 /* u16 per slot: peer port exchanged in connection packets */
#define CONN_SESSION_PEER_IPS     0x210 /* s32 per slot: peer IPv4 address */
#define CONN_SESSION_PEER_PORTS   0x290 /* u16 per slot: peer port */
#define CONN_SESSION_PLAYER_MASK  0x2F0 /* u32 bitmask of player slots that are present */
#define CONN_SESSION_PLAYER_RECORDS 0x2FC /* s32 * base of the match's 12-byte player records (MATCH_SESSION_PLAYERS) */
#define CONN_SESSION_PLAYER_LIST  0x304 /* u8[64]: indices into CONN_SESSION_PLAYER_RECORDS, one per match player */
#define CONN_SESSION_PLAYER_LIST_COUNT 0x344 /* s32 number of valid entries in CONN_SESSION_PLAYER_LIST */
#define CONN_SESSION_STORED_COMMAND      0x348 /* s32[0x21]: last received command kept for resending: word count, sender peer, payload words */
#define CONN_SESSION_STORED_COMMAND_PEER 0x34C /* s32: peer id the stored command came from */
#define CONN_SESSION_STORED_COMMAND_DATA 0x350 /* s32[]: the stored command's payload words */
#define CONN_SESSION_MODE         0x15  /* u8 connection mode (0/1 joining, 2/3 serving) */
#define CONN_SESSION_JOIN_SLOT    0x1A4 /* u8 highest peer slot whose join has been set up; the join chain fills slots 1..PLAYER_COUNT-1 */
#define CONN_SESSION_JOIN_FLAG    0x1A6 /* u8 flag StartJoinMatch was opened with: sends command 6 on the binary path and lets the peer-list membership checks pass while the join settles */
#define CONN_SESSION_JOIN_ACK_MASK 0x1DC /* u32 bitmask of peers that acknowledged the join (command 32) */
#define CONN_SESSION_BUSY         0x1A9 /* u8 nonzero while a connection change is in progress */
#define CONN_SESSION_TEARDOWN     0x1A8 /* u8 nonzero while peers are being removed or the session torn down */
#define CONN_TEARDOWN_IN_PROGRESS 2    /* CONN_SESSION_TEARDOWN value while the peer list is being changed */
#define CONN_SESSION_NATNEG       0x19C /* s32 NAT negotiation session to free on teardown, 0 when none */
#define CONN_SESSION_JOIN_PEER    0x204 /* s32 player id a join request is outstanding to, 0 when none */
#define CONN_SESSION_TARGET_ID    0x20C /* s32 player id of the matchmaking target, 0 when none */
#define CONN_SESSION_MATCH_ADDRESS 0x20 /* s32 address reported for the match (usually our QR2 parameter at 0x200) */
#define CONN_SESSION_ADDRESS_VALID 0x17 /* u8 nonzero once MATCH_ADDRESS may be announced to the peer */
#define CONN_SESSION_SERVER_BROWSER 0xE4 /* s32 GameSpy server-browser/QR2 object built by func_020613dc */
#define CONN_SESSION_EVENT_CALLBACK     0x464 /* s32 match event callback: (status, closed, targetCleared, serving, slot, data) */
#define CONN_SESSION_EVENT_DATA         0x468 /* s32 data passed to EVENT_CALLBACK */
#define CONN_SESSION_PEER_CALLBACK      0x46C /* s32 callback (slot, data) run when a peer joins while serving */
#define CONN_SESSION_PEER_CALLBACK_DATA 0x470 /* s32 data passed to PEER_CALLBACK */
#define CONN_SESSION_SCORE_CALLBACK     0x474 /* s32 callback (index, data) scoring browsed sessions */
#define CONN_SESSION_SCORE_CALLBACK_DATA 0x478 /* s32 data passed to SCORE_CALLBACK */
#define CONN_SESSION_CONNECT_ATTEMPTS 0x17D /* u8 failed peer-connect attempts */
#define CONN_PEER_CONNECT_LIMIT 5U
#define CONN_MODE_SERVE          2 /* serving a match */
#define CONN_MODE_SERVE_NO_RETRY 3 /* serving mode that reports the failure immediately */
#define CONN_ERROR_MATCH_FAILED 6
#define CONN_DETAIL_JOIN_FAILED   ((s32)0xFFFEC5D2) /* join retries exhausted */
#define CONN_DETAIL_BROWSE_FAILED ((s32)0xFFFEB3EE) /* server browse deadline passed */
#define CONN_DETAIL_PEER_CONNECT_FAILED ((s32)0xFFFEAE6C)
#define CONN_SESSION_TARGET_NOTICES  0x17C /* u8 QR2 state notices seen from the connect target */
#define CONN_SESSION_CONNECT_TARGET  0x180 /* s32 peer id the outstanding connect targets */
#define CONN_SESSION_JOIN_TICK       0x184 /* u64 time the outstanding join was opened */
#define CONN_SESSION_CONNECT_TICK    0x18C /* u64 time the outgoing socket connect was started */
#define CONN_SESSION_SELF_ID         0x208 /* s32 own player id, 0 before the master answered */
#define CONN_SESSION_ATTEMPT_TICK    0x1CC /* u64 tick the current connect attempt started */
#define CONN_SESSION_ATTEMPT_LIMIT   0x1C8 /* s32 time limit of the attempt, 0 when it has none */
#define CONN_SESSION_CAPACITY        0x16  /* u8 session capacity (SCM) minus 1, fixed when the match starts */
#define CONN_SESSION_MATCH_START_PENDING  0x1AE /* u8 nonzero while a match start waits for CONN_STATE_MATCH */
#define CONN_SESSION_MATCH_START_CALLBACK 0x47C /* s32 callback (data) run when the deferred match start happens */
#define CONN_SESSION_MATCH_START_DATA     0x480 /* s32 data passed to it */
#define CONN_SESSION_LAST_COMMAND        0x3CC /* u8 connection command last handled, CONN_SESSION_NO_COMMAND when none */
#define CONN_SESSION_LAST_COMMAND_TRIES  0x3CD /* u8 times the last command has been repeated */
#define CONN_SESSION_NO_COMMAND          0xFF  /* CONN_SESSION_LAST_COMMAND value when no command is remembered */
#define CONN_SESSION_CLOSED              0x18  /* u8 set once the session has been torn down, cleared when it is reset */
#define CONN_SESSION_JOIN_RETRIES         0x1AA /* u8 join attempts made */
#define CONN_SESSION_JOIN_PENDING         0x1BC /* s32 1 while a join request waits for its timeout */
#define CONN_SESSION_JOIN_REQUEST_TICK    0x1C0 /* u64 time the join request was sent */
#define CONN_SESSION_MATCHMAKING_TICK     0x1F0 /* u64 time the state-18 matchmaking wait started */
#define CONN_SESSION_COMMAND_PORT          0x3CE /* u16 port of the last command sent */
#define CONN_SESSION_COMMAND_ADDRESS       0x3D0 /* s32 address of the last command sent */
#define CONN_SESSION_COMMAND_DATA          0x3D4 /* s32[] payload of the last command sent */
#define CONN_SESSION_COMMAND_PEER          0x454 /* s32 peer of the last command sent */
#define CONN_SESSION_COMMAND_COUNT         0x458 /* s32 payload words of the last command sent */
#define CONN_SESSION_COMMAND_TICK          0x45C /* u64 time the last command was sent */

/* Matchmaking states taken by CONN_SESSION_STATE before the synchronization
 * handshake (CONN_STATE_SYNC_* above): a host is set up by StartHostMatch, a
 * client walks searching -> joining -> joined. */
enum {
    CONN_STATE_HOST_WAITING = 2, /* a host is up and waiting for the other players */
    CONN_STATE_SEARCHING    = 3, /* a client is browsing the matchmaking server list */
    CONN_STATE_JOINING      = 4, /* a client has sent its join request */
    CONN_STATE_JOINED       = 5, /* the join was accepted and the parameters are exchanged */
    CONN_STATE_CONNECTING   = 6  /* a client is connecting to the chosen host */
};

/* Matchmaking browse bookkeeping.  A browse that does not complete within
 * CONN_BROWSE_TIMEOUT_TICKS fails with connection error 6; the retry mode is 1
 * to rescan after 1 s and 2 after 3 s. */
#define CONN_SESSION_BROWSE_DEADLINE   0x174 /* u64: GetSystemTick deadline of the running browse, 0 when none */
#define CONN_SESSION_BROWSE_RETRY      0x0E8 /* s32: 0 none, 1 retry after 1 s, 2 retry after 3 s */
#define CONN_SESSION_BROWSE_RETRY_TICK 0x0EC /* u64: GetSystemTick the retry mode was armed at */
#define CONN_SESSION_TARGET_PORT       0x1B4 /* u16 port of the peer a join is being made to */
#define CONN_SESSION_TARGET_ADDRESS    0x1B8 /* s32 IPv4 address of that peer */
#define CONN_BROWSE_TIMEOUT_TICKS      0xEFB5F7 /* 30 s in GetSystemTick units */

/* Flags of the connection manager (gConnectionMgr).  Its +0x18 counter is the
 * depth of the server-browser callbacks running; a teardown while it is nonzero
 * cannot free the browser, so it asks the think loop to (BROWSER_FREE). */
#define CONN_MGR_BROWSER_FREE  0x14 /* s32 nonzero to have the think loop free the server browser */
#define CONN_MGR_BROWSER_DEPTH 0x18 /* s32 server-browser callback nesting depth */
#define CONN_MGR_NATNEG_SHUTDOWN 0x0C /* s32 nonzero requests NAT negotiation be shut down once Think returns */
#define CONN_MGR_NATNEG_THINKING 0x10 /* s32 nonzero while NatNeg_Think runs */
#define CONN_MGR_PLAYER_LIST   0x00 /* void *heap copy of the player list of the match being joined */
#define CONN_MGR_MATCH_MESSAGE 0x08 /* void *heap copy of the matchmaking message a host sends */
#define CONN_MGR_MATCH_STARTED 0x1C /* u8 nonzero once a match session has been started */
#define CONN_MGR_MATCH_FINISHED 0x1D /* u8 nonzero once that match session has finished */

/* Header of the match player-list object CONN_MGR_PLAYER_LIST points at while a
 * match is being synchronized.  ResetConnectionSync clears the round masks and
 * retry counter and stamps the timers, UpdateConnectionSync (main_020420A0) and
 * the command-18/19 handler (main_0203F45C) read and set them. */
#define CONN_SYNC_ACTIVE       0x00 /* u8 nonzero while the object is in use */
#define CONN_SYNC_PLAYER_COUNT 0x01 /* u8 number of players expected in the match */
#define CONN_SYNC_RETRIES      0x02 /* u8 sync packets sent in the current round */
#define CONN_SYNC_INTERVAL     0x04 /* u32 sync round timeout, in milliseconds */
#define CONN_SYNC_ANSWERED     0x08 /* u32 bitmask of peers that answered the round */
#define CONN_SYNC_READY        0x0C /* u32 bitmask of peers that answered ready */
#define CONN_SYNC_START_TICK   0x10 /* u64 GetSystemTick time the sync phase started */
#define CONN_SYNC_SENT_TICK    0x18 /* u64 GetSystemTick time the last sync packet was sent */

/* The in-flight peer-connect record at GetConnection()+0x194 (0xC bytes): what
 * the socket connect is for and how often it has been retried.  Its last word
 * overlaps CONN_SESSION_NATNEG. */
typedef struct ConnAttempt {
    u8  isJoin;  /* +0x00 nonzero when the attempt is a join */
    u8  retries; /* +0x01 connect retries so far */
    u16 port;    /* +0x02 peer port */
    s32 address; /* +0x04 peer IPv4 address */
    s32 natNeg;  /* +0x08 NAT negotiation session reused by the connect, 0 when none */
} ConnAttempt;

/* A peer address handed to a connect: the IPv4 address at +4 and the port at +2. */
typedef struct PeerAddress {
    u16 unk00;   /* +0x00 */
    u16 port;    /* +0x02 */
    s32 address; /* +0x04 */
} PeerAddress;

/* Connection session fields used while GameSpy QR2 server reporting runs. */
#define CONN_SESSION_GT2_SOCKET   0x04  /* GameSpy GT2 socket wrapper (handle at +0, local port at +8) */
/* GameSpy GTI2 transport session field used by the message handler. */
#define GT2_RECV_SEQUENCE         0x66  /* u16 sequence number the next incoming command must carry */
#define CONN_SESSION_QR2_RECORD   0x10  /* void *GameSpy QR2 connection record (see qr2.h) */
#define CONN_SESSION_PUBLIC_PORT  0x1A  /* u16 port the master reported for this client */
#define CONN_SESSION_PUBLIC_IP    0x1C  /* s32 IPv4 address the master reported for this client */
#define CONN_SESSION_QR2_PARAM    0x200 /* s32 matchmaking parameter reported to the master */
#define CONN_SESSION_GAME_NAME    0x2F4 /* s32 game name string given to QR2 */
#define CONN_SESSION_PLAYER_NAME  0x2F8 /* s32 player name string given to QR2 */

/* The live online-match session context (the MATCH_SESSION_* block), held by
 * gMatchSessionMgr; NULL when no session is running. */
#define MATCH_SESSION_MGR_SESSION  0x08 /* void * current match session, or NULL */

/* Fields of the online-match session context (the pointer held at
 * gMatchSessionMgr + 8). */
#define MATCH_SESSION_STATUS       0x00 /* s32 0 idle, 1 running, 2 finished */
#define MATCH_SESSION_STATUS_RUNNING 1  /* MATCH_SESSION_STATUS: the match is running */
#define MATCH_SESSION_STATUS_FINISHED 2 /* MATCH_SESSION_STATUS: setup complete, the app has been notified */
#define MATCH_SESSION_CONNECTION   0x04 /* void *GameSpy gpi connection handle of the match session */
#define MATCH_SESSION_THINK_COUNT  0x08 /* s32 paced think passes run on the session's connection */
#define MATCH_SESSION_THINK_TICK   0x0C /* u64 system tick of the last paced think pass */
#define MATCH_SESSION_PLAYER_COUNT 0x14 /* s32 number of players */
#define MATCH_SESSION_PLAYERS      0x18 /* array of 12-byte player records */
#define MATCH_SESSION_PLAYER_SIZE  12

/* Fields of one 12-byte player record (MATCH_SESSION_PLAYERS, and the record at
 * the head of a saved battle's slot): the first word holds the record kind in
 * bits 11..12 (GetPlayerRecordKind reads word0 >> 11 & 3) together with the
 * high 11 bits of a player code at bits 0..10; the two words after it are the
 * player's profile id, or for a PLAYER_RECORD_CODE record a 64-bit player code
 * whose low word is that id and whose high word is a 7-bit checksum of the id
 * and the local user id. */
#define PLAYER_RECORD_TYPE       0x00 /* u32 bits 11..12: a PLAYER_RECORD_KIND_* value, bit 13: PLAYER_RECORD_JOINED, bits 0..10: player-code high bits */
#define PLAYER_RECORD_JOINED     0x4 /* bit 2 of a record's type word (PLAYER_RECORD_TYPE >> 11): a profile record whose player joined the match */
#define PLAYER_RECORD_CODE       0x04 /* u64 player code of a PLAYER_RECORD_KIND_CODE record */
#define PLAYER_RECORD_ID         0x04 /* s32 GameSpy profile id of a PLAYER_RECORD_KIND_PROFILE record */
#define PLAYER_CODE_HIGH_MASK    0x7FF /* low bits of a record's type word (PLAYER_RECORD_TYPE) holding the high 11 bits of a 43-bit player code */

/* PLAYER_RECORD_TYPE values. */
#define PLAYER_RECORD_KIND_EMPTY      0 /* no player */
#define PLAYER_RECORD_KIND_UNRESOLVED 1 /* its profile has not been looked up yet (GetPlayerRecordId gives -1) */
#define PLAYER_RECORD_KIND_CODE       2 /* a player code, resolved against the local profile */
#define PLAYER_RECORD_KIND_PROFILE    3 /* a profile id, marked joined once the player is in the match */
#define PLAYER_RECORD_KIND_MASK       0x3 /* low bits of a record's type word (GetPlayerRecordTypeWord) that hold its PLAYER_RECORD_KIND_* */
#define MATCH_SESSION_CURSOR       0x1C /* u8 player being processed */
#define MATCH_SESSION_DIRTY        0x1D /* u8 player list changed */
#define MATCH_SESSION_STATE        0x1E /* u8 match-setup step */
#define MATCH_SESSION_STEP         0x1F /* u8 pass counter: the session finishes when it reaches 2 */
#define MATCH_SESSION_EVENT_CB     0x2C /* void (*)(s32 error, u8 dirty, s32 data): session finished or failed */
#define MATCH_SESSION_EVENT_DATA   0x30 /* s32 data passed to EVENT_CB */
#define MATCH_SESSION_INFO_CB      0x34 /* void (*)(s32 slot, s32 value, void *out, s32 data): asks for a player's info */
#define MATCH_SESSION_INFO_DATA    0x38 /* s32 data passed to INFO_CB */
#define MATCH_SESSION_STATS_CB     0x3C /* void (*)(s32 slot, s32 otherSlot, s32 data): folds one player's battle stats into another */
#define MATCH_SESSION_STATS_DATA   0x40 /* s32 data passed to STATS_CB */
#define MATCH_SESSION_SLOT_CB      0x44 /* void (*)(s32 slot, s32 data): invoked when a player slot changed */
#define MATCH_SESSION_SLOT_DATA    0x48 /* s32 data passed to SLOT_CB */

/* The multiboot boot-handshake channel: the ARM9 posts its boot control
 * messages (Mb_SendControlMessage) on FIFO tag 0xD, where the ARM7's replies
 * (boot-ready, boot-complete) arrive and are handled by Mb_BootHandshakeHandler
 * and Mb_BootCompleteHandler. */
#define MB_FIFO_TAG 0xD

/* An ARM7 boot message's status: the low six bits of the message the FIFO
 * handlers receive say which boot stage the ARM7 reports. */
#define MB_STATUS_MASK          0x3F /* bits of a boot message that hold MB_STATUS_* */
#define MB_STATUS_BOOT_READY    1    /* the ARM7 is ready for the boot parameters (Mb_BootHandshakeHandler) */
#define MB_STATUS_BOOT_COMPLETE 17   /* the ARM7 finished booting (Mb_BootCompleteHandler) */

/* Multiboot (DS Download Play) boot state (gMbBootState, 0x20 bytes). */
typedef struct MbBootState {
    s32 paramsSent;  /* +0x00 nonzero once Mb_SendBootParams has run */
    s32 remoteReady; /* +0x04 cleared when the ARM7 reports that it is ready */
    s32 initialised; /* +0x08 nonzero once Mb_BootInit has run */
    s32 complete;    /* +0x0C nonzero once the ARM7's boot-complete message was handled */
    s32 unk10;       /* +0x10 */
    s32 unk14;       /* +0x14 */
    s32 (*onComplete)(void); /* +0x18 optional callback run by Mb_BootCompleteHandler */
    s32 unk1C;       /* +0x1C */
} MbBootState;

/* The multiboot match profile the parent broadcasts with command 10: the match
 * id, the player slot currently being announced, and the small info block the
 * profile packet carries after them. */
typedef struct MbMatchProfile {
    s32 matchId;    /* +0x00 the match id both sides compare */
    u16 playerSlot; /* +0x04 slot (1..16) whose profile is being announced */
    u16 infoWord;   /* +0x06 first info word of the profile packet */
    u8  info[6];    /* +0x08 six info bytes of the profile packet */
} MbMatchProfile;

/* The multiboot state object gMbState: a u16 flag, the top of its task stack and
 * the two pointers every multiboot routine reaches through. */
#define MB_STATE_CTX   0x08 /* void *the multiboot context (the front of the work area below) */
#define MB_STATE_WORK  0x0C /* void *the multiboot match work area (MB_WORK_*) */

/* The multiboot match work area (gMbWork = gMbState.work, 0x7D00 bytes): the
 * buffer commands are serialized into, the per-player slot states and the 16
 * records of players grouped together for one battle. */
#define MB_WORK_SIZE        0x7D00 /* bytes cleared when the match state is torn down */
#define MB_CMD_BUFFER       0x0000 /* outgoing command record, written by SerializeCommand */

/* A multiboot control command (MB_CMD_BUFFER): its type byte and the two 16-bit
 * arguments that follow.  SerializeCommand writes it big-endian for sending. */
typedef struct MbCommand {
    u8  type; /* +0x00 command id */
    u16 arg0; /* +0x02 first argument */
    u16 arg1; /* +0x04 second argument */
} MbCommand;

/* State of a held cartridge-access lock: the shared OS lock word's owner-id
 * busy flag seen when the lock was taken (+0x00) and the caller's interrupt
 * mask to restore (+0x04). */
typedef struct MbLockState {
    s32 busy;       /* +0x00 */
    s32 interrupts; /* +0x04 */
} MbLockState;
#define MB_EVENT_CALLBACK   0x14E4 /* void (*)(s32 player, s32 event, void *packet): the match's event callback, set by Mb_SetMatchEventCallback */
#define MB_PLAYER_STATE     0x14E4 /* s32 per-player state: player p's state is at MB_PLAYER_STATE + p*4 */
#define MB_PLAYER_STATE_FIRST 0x14E8 /* player 1's state: player p's state is at MB_PLAYER_STATE + p*4 (player 0's slot is MB_EVENT_CALLBACK) */
#define MB_PLAYER_STATE_GROUPED 5 /* the player has joined a group; the group's battle can start */
#define MB_PLAYER_STATE_READY   7 /* the player's setup is complete; the link's ready check and the phase-3 acknowledge look for this */
#define MB_PLAYER_GROUP     0x1525 /* s8 per-player group id, 1 byte each, indexed from 1 */
#define MB_GROUP_STARTED    0x1524 /* u8 nonzero once the players have been grouped */
#define MB_GROUPS           0x1788 /* 16 group records, MB_GROUP_STRIDE bytes each */
#define MB_GROUP_STRIDE     0x5D4
#define MB_GROUP_UNIT_DATA  0x0000 /* 0xE4-byte unit roster sent when the group's battle starts */
#define MB_GROUP_UNIT_COUNT 0x5C4  /* u16 players/units in the group */
#define MB_GROUP_ACTIVE     0x5CA  /* u8 nonzero while the group record is in use */
#define MB_GROUP_PENDING    0x5AA  /* u16 record-relative: per-player pending bitmask */
#define MB_GROUP_ACKED      0x5AC  /* u16 record-relative: per-player done bitmask */
#define MB_GROUP_CHUNK_CURSOR 0x5C0 /* u16 record-relative: chunk transfer the group is sending */
#define MB_GROUP_CHUNK_GOAL   0x5C2 /* u16 record-relative: newest chunk a member asked for; the cursor advances to it */
#define MB_PLAYER_FORFEIT   0x1526 /* s8 per-player 1-byte flag, -1 = gave up, indexed from 1 */
#define MB_PLAYER_MAX       15   /* multiboot player numbers run 1..MB_PLAYER_MAX; 0 is the local console */
#define MB_PLAYER_INFO       0x1340 /* per-player info block, 22 bytes each, indexed from 1 (the block PlayerData packets carry) */
#define MB_PLAYER_INFO_SIZE  0x16   /* bytes in one player's info block */
#define MB_PLAYER_INFO_OUT   0x1772 /* scratch info block MultiBoot_GetPlayerInfo copies a player's block into */
#define MB_BLOCK_SIZE       0x1318 /* u32 bytes carried by one transfer block, at this work-area offset */

/* The multiboot worker thread (gMbJobTask): a TaskCreate thread object whose
 * MB_TASK_JOB word points at the job to run and whose MB_TASK_JOB_BLOCK record is
 * the job it always owns.  A job's first callback runs it and returns its result,
 * the second callback runs afterwards; the job record is 0x24 bytes. */
#define MB_TASK_JOB         0xC0 /* void *job the worker is running, 0 while it sleeps */
#define MB_TASK_JOB_BLOCK   0xC4 /* the worker's own MB_JOB_SIZE-byte job record */
#define MB_JOB_SIZE         0x24 /* bytes of one job record */
#define MB_JOB_FIRST        0x00 /* s32 (*)(void *job): runs the job, its return is the result */
#define MB_JOB_SECOND       0x04 /* void (*)(void *job): runs after the job's first callback */
#define MB_JOB_RESULT       0x08 /* s32 result the first callback returned */
#define MB_JOB_REST         0x0C /* s32[6] */

/* Priority codes a queued multiboot job may use besides 0..MB_TASK_PRIORITY_MIN:
 * an absolute value, or one relative to the worker thread's current priority. */
#define MB_TASK_PRIORITY_MIN     31 /* lowest priority value a request may use */
#define MB_TASK_PRIORITY_HIGHER  32 /* one step above the worker's current priority */
#define MB_TASK_PRIORITY_LOWER   33 /* one step below the worker's current priority */
#define MB_TASK_PRIORITY_SAME    34 /* the worker's current priority */

/* The game group id a download-play parent advertises in its beacon: a value
 * from MB_GROUP_ID_COUNT ids starting at MB_GROUP_ID_FIRST, picked from the
 * console's MAC address and the shared frame counter. */
#define MB_GROUP_ID_FIRST   0xC8 /* 200 */
#define MB_GROUP_ID_COUNT   20   /* ids a console chooses from */

/* Link session fields of the multiboot context (gMbState.ctx, the front of the
 * same work area the offsets above index). */
/* Four u16 send-status words the context keeps; the send-flag builder packs
 * whether each is nonzero into the flag byte of a download send (bit 0 = the
 * word at +0x0E, bit 1 = +0x12, bit 2 = +0x14, bit 3 = +0x16).  +0x16 is 1
 * from startup, and the download sender always adds bits 0 and 1 itself. */
#define MB_CTX_STATUS0      0x0E /* u16 */
#define MB_CTX_STATUS1      0x12 /* u16 */
#define MB_CTX_STATUS2      0x14 /* u16 */
#define MB_CTX_STATUS3      0x16 /* u16 */
/* Packet payload limits and buffer overhead for the multiboot parent's MP link. */
#define MB_PARENT_PAYLOAD_MIN        0xE4U
#define MB_PARENT_PAYLOAD_MAX        0x1FEU
#define MB_CHILD_PAYLOAD_MIN         8U
#define MB_CHILD_PAYLOAD_MAX         16U
#define MB_PARENT_PACKET_OVERHEAD    0x26
#define MB_CHILD_PACKET_OVERHEAD     0x20
#define MB_PARENT_BUFFER_OVERHEAD    0x14A
#define MB_PER_CHILD_BUFFER_OVERHEAD 0x70
#define MB_LINK_BUFFER_LIMIT         0x15E0

#define MB_LINK_STARTED     0x50D /* u8 1 once the link has started (IsMultiBootLinkStarted) */
#define MB_LINK_SEND_PENDING 0x50C /* u8 nonzero while a link send is queued and not yet done */
#define MB_LINK_CLOSING     0x526 /* u16 nonzero once the link shutdown has begun */
#define MB_LINK_EXCHANGE    0x528 /* u16 1 while the group match-data exchange is under way */
#define MB_LINK_PLAYERS     0x52A /* u16 bit per player slot still in the link, 0 when none */
#define MB_LINK_ALIVE       0x5E4 /* s32 1 while the link keeps running; cleared when it closes */
#define MB_LINK_ROTATE_PLAYERS 0x5E8 /* s32 1 on the console that cycles the player slot the match profile announces */
#define MB_MATCH_RECORD_INDEX  0x5EC /* s32 record the last received match packet filled */
/* Link task fields of the multiboot context. */
#define MB_CTX_CHANNEL      0x520 /* s32 WFC channel index of the link */
#define MB_CTX_DATA         0x504 /* void *data buffer handed to the link task */
#define MB_CTX_DATA_SIZE    0x51A /* u16 bytes of that buffer */
#define MB_CTX_EXTRA_BUFFER 0x040 /* the extra buffer the link task fills */
#define MB_CTX_EXTRA_SIZE   0x518 /* u16 bytes of that buffer */
#define MB_CTX_FLAG         0x52C /* u16 flag carried by a link task request */
#define MB_CTX_RECV_BUFFER  0x440 /* 0xC0-byte buffer the received match data is assembled into */
/* The match records at the end of the context: one block per player's match data,
 * its six-byte id at +0xCA, the value a receive updates at +0xF6 and the 128-byte
 * payload at +0xF8. */
#define MB_MATCH_RECORDS       0x600
#define MB_MATCH_RECORD_SIZE   0x180
#define MB_MATCH_RECORD_SLOTS  16
#define MB_MATCH_RECORD_COUNT  0x5E0 /* u16 records in use */
#define MB_MATCH_RECV_VALUE    0x5E2 /* u16 value carried by the last match packet */
#define MB_MATCH_RECORD_ID     0xCA  /* u8[6] id matched against a received record */
#define MB_MATCH_RECORD_VALUE  0xF6  /* u16 value a receive updates */
#define MB_MATCH_RECORD_BLOCK  0xF8  /* 128-byte payload a receive updates */
/* The game's link command callback (gMbState+8, the multiboot context): the
 * dispatcher func_020140c4 runs it with a command/event code and its packet. */
#define MB_CTX_CALLBACK     0x51C /* s32 (*)(s32 event, void *packet) */
#define MB_LINK_EVENT_CANCEL 17 /* the link cancel has finished; the game tears the match state down */
/* gMbState+0xC, the download work block: nonzero once the block has been set up
 * for a download-play session (MultiBoot_StartParent), cleared when it ends. */
#define MB_DOWNLOAD_SET_UP  0x1316 /* u16 */
#define MB_WORK_STARTED     0x1320 /* s32 nonzero once the multiboot library was started (MultiBoot_Start); a link cannot be closed before that */

/* The DS Download Play send queue the WFC download channel drains
 * (gDownloadSendState, main_02015AA0): the files waiting to be sent, the file being
 * sent and the packet buffer transmitted.  The packet symbol gDownloadPacket is
 * the state's DL_PACKET field. */
#define DL_QUEUE      0x18 /* DownloadFile *files waiting to be sent */
#define DL_CURRENT    0x1C /* DownloadFile *file currently being sent */
#define DL_STATE      0x24 /* u8 send state machine step (0 = idle, 2 = sending a file) */
#define DL_PROGRESS   0x25 /* u8 progress byte of the current file, reset with the counters below */
#define DL_FILE_INDEX 0x26 /* u8 the current file's step counter, copied from DL_FILE_STEP */
#define DL_CHUNK_INDEX 0x27 /* u8 index of the next chunk packet in the current batch */
#define DL_SEQUENCE   0x29 /* u8 sequence number stamped into every packet submitted */
#define DL_SEND_PHASE 0x10 /* s32 which of a file's roster packets runs DL_CALLBACK (0 = before it is submitted, 1 = after) */
#define DL_CALLBACK   0x14 /* void (*)(u32 fileId) progress callback, run with the current file's id */
#define DL_PACKET     0x40 /* 0x70-byte packet WFC_SubmitDownloadData sends (gDownloadPacket) */
/* Fields of a DownloadFile (one queued 0x4C0-byte file record). */
#define DL_FILE_PLAYER_COUNT 0x358 /* u8 players in the roster the file is sent to */
#define DL_FILE_PLAYER_MASK  0x35A /* u16 bit per player (bit 0 is the sender) the file goes to */
#define DL_FILE_READY_MASK   0x35C /* u16 per-player mask carried by the file's roster packets */
#define DL_FILE_PLAYER_INFO  0x35E /* 15 player info blocks, MB_PLAYER_INFO_SIZE bytes each */
#define DL_FILE_PLAYER_SLOTS 15    /* player info blocks a file record holds */
#define DL_FILE_STEP  0x4B4 /* u8 per-file counter copied into DL_FILE_INDEX */
#define DL_FILE_ROSTER_SENT 0x4B0 /* u16 bit per player whose roster packets this file has sent (bit 0 = the sender), compared against DL_FILE_PLAYER_MASK */
#define DL_FILE_NEXT  0x4BC /* DownloadFile *next queued file */
#define DL_FILE_HAS_RESOURCES 0x4B2 /* u8 nonzero once the file's resource region was loaded */
#define DL_FILE_RESOURCES     0x220 /* start of the loaded resource region inside a file record */
#define DL_CHUNK_SOURCE       0x20 /* u8 * source of the next 0x62-byte chunk packet batch */
#define DL_CHUNK_COUNT        0x28 /* u8 chunk packets the current batch sends */
/* DL_STATE values of the download sender. */
#define DL_STATE_IDLE         0 /* no file has been started yet */
#define DL_STATE_START        1 /* a queued file may be started */
#define DL_STATE_BEGIN_PACKET 2 /* choose the file region the next packets carry */
#define DL_STATE_SEND_CHUNK   3 /* send the file's 0x62-byte chunk packets */
#define DL_STATE_FILE_DONE    4 /* file data complete, move on to its roster packets */
#define DL_STATE_SEND_ROSTER  5 /* send the file's roster/unit packets */
#define DL_STATE_WAIT         6 /* nothing to send, keep polling */

/* Events a multiboot command callback receives.  The callback pointer lives in
 * MB_EVENT_CALLBACK (set by Mb_SetMatchEventCallback) and is run by Mb_DispatchPlayerEvent as
 * (player, event, packet): func_020140c4 maps the link state machine's commands
 * onto the events, func_02015230 reports a status. */
#define MB_EVENT_JOIN         2  /* a player's join request arrived (packet = its record) */
#define MB_EVENT_LEAVE        3  /* a player was removed from the link */
#define MB_EVENT_GROUP_REJECT 4  /* the player could not join a group */
#define MB_EVENT_GROUP_JOIN   5  /* the player joined a group */
#define MB_EVENT_GROUP_DATA   6  /* the group's data exchange finished */
#define MB_EVENT_CHUNK_ACK    7  /* the player acknowledged a downloaded chunk */
#define MB_EVENT_CHUNK_SENT   8  /* the player's chunk transfer finished */
#define MB_EVENT_KICK         9  /* the player was dropped mid-group */
#define MB_EVENT_PLAYER_DATA  10 /* the player's info block arrived (packet = it) */
#define MB_EVENT_ROSTER_DONE  11 /* the group's roster is complete */
#define MB_EVENT_TEARDOWN     12 /* the match state is being cleared */
#define MB_EVENT_STATUS       13 /* a status code arrived (packet = the s16 code) */
#define MB_EVENT_GROUP_LEAVE  14 /* a group-leave request was received */

/* Address windows a download chunk may occupy, chosen by the chunk kind kept in
 * sMbChunkKinds (2 = the fixed header window, 0 = main RAM below 0x022C0000,
 * 1 = the rest of main RAM or the 0x037F8000 window). Kinds 0 and 1 may not
 * reach the last 0x1800 bytes of main RAM. */
#define MB_WINDOW_HEADER_START 0x027FFE00 /* header chunk window, MB_WINDOW_HEADER_SIZE bytes */
#define MB_WINDOW_HEADER_SIZE  0x160
#define MB_WINDOW_HEADER_END   0x027FFF60 /* one past the header chunk window */
#define MB_WINDOW_RAM_START    0x02000000 /* start of main RAM */
#define MB_WINDOW_RAM_LOW_END  0x022C0000 /* end of the first main RAM window */
#define MB_WINDOW_RAM_END      0x02300000 /* end of the main RAM the low window may be extended into */
#define MB_WINDOW_RAM_HIGH_END 0x023FE800 /* end of the main RAM a tail block may reach */
#define MB_WINDOW_EXT_START    0x037F8000 /* start of the second address window */
#define MB_WINDOW_EXT_END      0x0380F000 /* one past the second address window */

/* The first 0x8000 bytes of a DS game card hold the header and the secure
 * area; the normal card read command cannot fetch them, so a card load that
 * starts in that range skips the unreadable part. */
#define CARD_SECURE_AREA_END   0x8000

/* What a card read drives: the byte-wide command registers (byte 0 the control
 * byte, then the 0xB7 "read card" opcode and the four address bytes), the ROM
 * control register that starts a command and reports its progress, and the 32-bit
 * data port the command streams a page through.  The boot header's card control
 * word supplies the transfer clock the commands are built from. */
#define CARD_REG_COMMAND    0x040001A1 /* u8[8]: command registers */
#define CARD_REG_ROMCTRL    0x040001A4 /* u32: bit 31 busy, bit 23 a data word is ready */
#define CARD_REG_DATA       0x04100010 /* u32: data port the read command fills */
#define CARD_HEADER_CONTROL 0x027FFE60 /* u32: card control word kept in the header window */
#define CARD_READ_OPCODE    0xB7 /* u8 command byte that starts a read */
#define CARD_COMMAND_MODE   0xC0 /* command register byte 0: raw-command transfer mode */
#define CARD_PAGE_SIZE      0x200 /* bytes one read command fetches */

/* One chunk of a multiboot program image as the sender describes it: where the
 * bytes go in the member's memory, the source address (or download-image offset
 * when flags bit 0 is set) and the byte count. */
typedef struct MbMemoryDescriptor {
    u32 dest;   /* +0x00 destination address in the member's memory */
    u32 source; /* +0x04 source address or image offset */
    u32 size;   /* +0x08 bytes in the chunk */
    u32 flags;  /* +0x0C bit 0: source is an image offset copied from the loader's pool */
} MbMemoryDescriptor;

/* One multiboot member's chunk transfer: the next block to send, where it goes in
 * the member's memory and which program chunk it belongs to. */
typedef struct MbChunkTransfer {
    u32 dest;   /* +0x00 destination address in the member's memory */
    u32 size;   /* +0x04 bytes to send from that block on */
    u32 source; /* +0x08 offset of the block in the download image */
    u8  chunk;  /* +0x0C chunk index (low byte of the word the sender reads) */
} MbChunkTransfer;

/* One cached block of the multiboot download image a group reads from its
 * archive: where the block sits in the image, how big it is, the buffer it is
 * read into and copied from, and how far its read has got.  The group's load
 * queue keeps MB_LOAD_BLOCK_COUNT of them and serves copy requests from them. */
typedef struct MbLoadBlock {
    u32 offset; /* +0x00 byte offset of the block in the download image */
    u32 size;   /* +0x04 bytes in the block */
    u8 *data;   /* +0x08 buffer the block is read into and copied from */
    s32 state;  /* +0x0C MB_LOAD_STATE_* */
} MbLoadBlock;   /* 0x10 bytes */

#define MB_LOAD_BLOCK_COUNT    4 /* block cache slots in one load queue */
#define MB_LOAD_STATE_READING  1 /* the block's read from the archive is queued or running */
#define MB_LOAD_STATE_RESIDENT 2 /* the block holds image bytes that can be copied */
#define MB_LOAD_STATE_FIXED    3 /* the block is always present in memory and is never re-read */

/* The 0x70-byte load queue a group's download chunks go through: the name of the
 * archive the image is read from and the block cache the loader serves copy
 * requests from (see Mb_LoadProgramImage and the load-block task). */
typedef struct MbLoadQueue {
    u32 pending;         /* +0x00 reads queued; 0 = idle */
    u8 pad04[0x0C];      /* +0x04 */
    u8 name[4];          /* +0x10 name of the archive the image comes from */
    s32 nameLength;      /* +0x14 its length in bytes */
    u8 pad18[0x18];      /* +0x18 */
    MbLoadBlock blocks[MB_LOAD_BLOCK_COUNT]; /* +0x30 cached image blocks */
} MbLoadQueue;           /* 0x70 bytes */

/* Assembly of the per-player info records received during multiboot match setup:
 * each 30-byte record (player id, info block, group) is sent in command-7 packets
 * carrying numbered fragments, and reassembled into one slot per player. */
#define MB_RECORD_SIZE      0x1E  /* bytes in a finished player record */
#define MB_RECORD_SLOT      0x20  /* bytes per player slot in the assembly buffer */
#define MB_RECORD_MASK      0x1E0 /* byte offset of the per-player received-fragment bitmasks */
#define MB_RECORD_BUFFER_SIZE 0x21C /* whole buffer: 15 player slots plus their 15 fragment masks */
typedef struct MbRecordRx {
    u32 unk00;         /* +0x00 never read */
    u8 *buffer;        /* +0x04 player slots, MB_RECORD_SLOT bytes each */
    s32 fragmentSize;  /* +0x08 payload bytes carried by one fragment */
    s32 fragmentCount; /* +0x0C fragments that make up a full record */
    s32 recordSize;    /* +0x10 bytes per record */
} MbRecordRx;
/* State of the ov001 front end (the title and menu screens), kept in
 * gOv001ScreenState and set up by the screen-mode initialiser before the main
 * loop runs.  Functions declare it `extern u8 gOv001ScreenState;` locally. */
#define OV001_SCREEN_LANGUAGE   0x00 /* u8 console language the front end was started with */
#define OV001_SCREEN_EXIT       0x01 /* u8 nonzero asks the main loop to stop */
#define OV001_SCREEN_WORK       0x04 /* void *work buffer the overlay was loaded on */
#define OV001_SCREEN_OPTIONS    0x08 /* u32 screen options: low nibble = screen layout, bit 4+n = option n */
#define OV001_SCREEN_STEP       0x0c /* void (*)(void) called once per frame by the main loop */
#define OV001_SCREEN_NEXT_MODE  0x10 /* s32 next screen mode (see Ov001_SetNextScreenMode) */
#define OV001_SCREEN_NEXT_ARG   0x14 /* s32 argument of the next screen mode */
#define OV001_SCREEN_ENTRY_MODE 0x18 /* s32 name-entry mode (see Ov001_SetNameEntryMode) */
#define OV001_SCREEN_ENTRY_ARG  0x1c /* s32 argument of the name-entry mode */

/* Bytes of the expansion heap created in the ov001 work buffer; every ov001
 * allocation comes from it. */
#define OV001_HEAP_SIZE 0x40000

/* Initial layouts stored in the low nibble of OV001_SCREEN_OPTIONS. */
enum {
    OV001_LAYOUT_WIFI_MENU = 0,
    OV001_LAYOUT_ACCESS_POINT_MENU = 1
};
#define OV001_SCREEN_CREATE_ICON_ROW 1 /* next-screen argument that enables icon row creation */

/* Asset path templates handed to Ov001_GetLocalizedFileName carry the language
 * character at index OV001_PATH_LANGUAGE_CHAR.  A OV001_PATH_LANG_ALL template
 * is used unchanged by every language; a OV001_PATH_LANG_NONJP template is used
 * unchanged except in Japanese, which needs its own 'j' file; any other
 * template is the Japanese name, and the character is replaced with the current
 * language's code from gOv001LanguageCode. */
#define OV001_PATH_LANGUAGE_CHAR 5
#define OV001_PATH_LANG_ALL      'x'
#define OV001_PATH_LANG_NONJP    'y'

/* Positions compared by ConvergeSyncedPositions are Q12 fixed-point pixels
 * (0x1000 is one pixel).  Each call moves a position by at most one map cell
 * (24 pixels, the size of a cell in the zoomed-in map view), by a saturating
 * curve of the gap between the two positions whose scale is 400 pixels. */
#define POS_FX_ONE          0x1000  /* 1.0 in Q12 */
#define POS_FX_HALF         0x800   /* 0.5 in Q12 */
#define POS_CONVERGE_CELL   0x18000 /* 24 pixels in Q12: most a position moves per call */
#define POS_CONVERGE_SCALE  0x190000 /* 400 pixels in Q12: the curve's scale */

/* The receive state itself is declared `extern M2C_UNK gMbRecordRx;` locally by
 * each user; access its fields through this. */
#define MB_RECORD_RX ((MbRecordRx *)&gMbRecordRx)

/* A GPI player-info result (the buffer handed to a gpiGetInfo callback). */
#define GPI_INFO_STATUS    0x00 /* s32 0 = ok, nonzero = error/status */
#define GPI_INFO_PLAYER_ID 0x04 /* s32 player/profile id */
#define GPI_INFO_NAS_ID    0x8E /* char[] NAS id as text */

/* States of the WFC match-making session (gNetSession + 0x24). */
enum {
    NET_STATE_OFFLINE  = 0, /* session has not logged in */
    NET_STATE_CHECKING_SERVICE = 1, /* checking service availability before login */
    NET_STATE_READY    = 3, /* idle in the lobby: a match can be started */
    NET_STATE_STARTING = 5, /* a match is being set up */
    NET_STATE_MATCH    = 6  /* the match is running */
};

/* Global network error record (gNetError): the error code and its parameter.
 * Code 9 is fatal: it is never overwritten nor cleared. */
typedef struct NetError {
    s32 code;   /* +0x00 0 = no error */
    s32 detail; /* +0x04 error parameter */
} NetError;

#define NET_ERROR_NONE  0 /* no error is recorded */
#define NET_ERROR_FATAL 9 /* fatal: never overwritten nor cleared */
/* The record itself is declared `extern M2C_UNK gNetError;` locally by each user. */
#define NET_ERROR ((NetError *)&gNetError)

/* The error fields of the network panel record and of the net-error sprite
 * CreateNetErrorSprite builds from it. Classes 3..7 also get the online
 * match's name label; classes 0..2 are shown only as the error text. */
#define NET_ERROR_CODE  0x38 /* s32: error code, 0 = no error */
#define NET_ERROR_PARAM 0x3C /* s32: the error's parameter */
#define NET_ERROR_CLASS 0x40 /* u32: error class 0..7 */

/* Step flags of the ov010 online session (gOv010OnlineSession+0x54): their bit
 * index is what SetOnlineSessionFlag/IsOnlineSessionFlagSet take. */
#define OV010_FLAG_STARTED 0 /* the session's work block is allocated */
#define OV010_FLAG_CONNECTED 1 /* the WFC connection is up (cleared while connecting) */
#define OV010_FLAG_MATCHMAKING 2 /* matchmaking has started (set by its start callback) */
#define OV010_FLAG_RUNNING 3 /* the online session is running (cleared when it stops or its start fails) */
#define OV010_FLAG_FAILED  4 /* the session start failed or the session stopped */
#define OV010_FLAG_REGISTERING 5 /* the NAS player registration request is in flight */
#define OV010_FLAG_ERROR   6 /* a network error has been handed to the UI, so it is not reported again */

/* The ov010 online session's transfer-start callback (gOv010OnlineSession+0x38):
 * called with the size of the transfer that starts and the id of the player it
 * goes to; 0 when none is installed. */
#define OV010_SESSION_TRANSFER_START_CALLBACK 0x38

/* The online lobby's local-player name label: the player's name and the screen
 * position it is shown at, created when the online lobby opens. */
#define ONLINE_LABEL_X     0x35 /* s8 x position */
#define ONLINE_LABEL_Y     0x36 /* s16 y position */
#define ONLINE_LABEL_NAME  0x38 /* void *: the local player's name record (GetLocalPlayerName), the single name a WFC match query looks up */
#define ONLINE_LABEL_MATCHED 0x3C /* u8: nonzero once the query matched the local player's name */
#define ONLINE_LABEL_MATCH_COUNT 0x40 /* s32: number of matches the query returned (0..7) */
#define ONLINE_LABEL_ANIM_SESSION_END 0x12 /* GotoSpriteAnimationLabel target once the WFC session has ended */

/* An ov010 online player record, 0x6c bytes each: a 0x1a-byte name area, the
 * connected flag and player id, a status word, the GameSpy skill rating, five
 * per-slot state bytes, then the 0x40-byte network panel record (NET_PLAYER_*). */
#define ONLINE_PLAYER_RECORD_SIZE 0x6C
#define ONLINE_PLAYER_FLAGS 0x1a /* u8: ONLINE_PLAYER_FLAG_* bits */
#define ONLINE_PLAYER_FLAG_CONNECTED 0x01 /* the record holds a connected peer */
#define ONLINE_PLAYER_FLAG_VOICE 0x04 /* u8: bit 2 set while the peer has voice chat available */
#define ONLINE_PLAYER_ID    0x1b /* s8: the player id the peer plays as, -1 when unset */
#define ONLINE_PLAYER_RATING 0x20 /* s32: GameSpy skill rating (RATING_DEFAULT for a new player) */
#define ONLINE_PLAYER_NAME_SIZE 0x1a /* bytes of the name area that precedes the flags */
#define ONLINE_PLAYER_STATUS    0x1c /* s32 status word, -1 when unset */
#define ONLINE_PLAYER_SLOT_STATE 0x24 /* s8[5]: per-slot state bytes, -1/-2 when unset */
#define ONLINE_PLAYER_SLOT_RANK       0x24 /* s8: rank index used to load the player's rank icon, -1 when unset */
#define ONLINE_PLAYER_SLOT_FAV_GROUP  0x25 /* s8: favourite CO/group index, -2 when unset */
#define ONLINE_PLAYER_SLOT_FAV_RECORD 0x26 /* s8: favourite CO record index, -2 when unset */
#define ONLINE_PLAYER_SLOT_HOST       0x27 /* s8: 0 when this console hosted the match through matchmaking, 1 when it served or joined one */
#define ONLINE_PLAYER_PANEL     0x2c /* network panel record that follows the slot states */
#define ONLINE_PLAYER_PANEL_SIZE 0x40 /* bytes of the network panel record (NET_PLAYER_*) */

/* A connected player's network record, the block GetNetworkPlayerRecord returns
 * (0x20 bytes into an ov009 link player slot, 0x2C into an ov010 online player
 * record): the CO choices the player made in the waypoint panel. */
#define NET_PLAYER_PANEL_OPEN   0x08 /* u8: 1 while the player has the waypoint panel open */
#define NET_PLAYER_CO_ICON      0x0D /* u8: CO icon index of the player's own waypoint slot */
#define NET_PLAYER_SLOT_OPTIONS 0x0E /* u8[4]: CO option chosen for each waypoint slot */
#define NET_PLAYER_SLOT_ICONS   0x12 /* u8[4]: CO icon index chosen for each waypoint slot */
#define NET_PLAYER_DATA         0x18 /* s32: nonzero once the player's panel record has been filled in */

/* Fields of the ov010 online session the match event handlers touch. */
#define OV010_SESSION_CHANGED_PLAYERS 0x00 /* u16: one bit per player whose connection changed (set when its record's connected flag is cleared) */
#define OV010_SESSION_PEER_CALLBACK 0x34 /* void (*)(s32 error, s32 wasConnected, s32 pending, s32 playerId, s32 playerSlot, s32 arg): peer connection event forwarded by the net layer */
#define OV010_SESSION_START_RECORD 0x18 /* void *: record of the match being started (see OV010_START_RECORD_*) */
#define OV010_START_RECORD_ID      0x00 /* s32 match id both sides compare */
#define OV010_START_RECORD_ACKS    0x04 /* u16 one bit per player that acknowledged the start request */
#define OV010_SESSION_CALLBACK 0x0c /* void (*)(s32 error, s32 aborted, s32 data): the running match's event callback */
#define OV010_SESSION_SLOT_CALLBACK 0x10 /* void (*)(s32 slot, s32 data): the app's callback for a changed player slot */
#define OV010_SESSION_PEER_JOINED_CALLBACK 0x44 /* void (*)(s32 slot, s32 data): the app's callback for a peer joining while serving (Ov010Online_OnPeerJoined) */
#define OV010_SESSION_VOICE_CALLBACK 0x2c /* void (*)(s32 peerId, void *packet, s32 length): receives each packet for the voice chat, 0 when voice chat is off */
#define OV010_SESSION_PLAYER   0x24 /* void *: the local player's join record (OV010_PLAYER_*) */
#define OV010_PLAYER_JOINED    0x00 /* u8 nonzero once the local player joined the session */
#define OV010_PLAYER_MASK      0x02 /* u16 this console's player bit */
#define OV010_SESSION_PEER_RX_BUFFERS 0x3c /* u8 *: receive buffers indexed by peer, skipping the local player */
#define OV010_PEER_RX_BUFFER_SIZE 0x5a0
#define OV010_SESSION_LOCAL_ID 0xfb /* u8 this console's transport player id, stored when the match starts */

/* The ov010 online connection object (gOv010ConnectionClass): a stream of data
 * being chunked out to the peers and the packet currently on the wire.  The send
 * step advances the stream offset, builds each packet and records it at PACKET
 * with its size and the peers it is addressed to; the finish step releases the
 * packet once every addressed peer can accept a transfer again. */
#define OV010_CONNECTION_STREAM_OFFSET 0x34 /* u32: bytes of the stream already sent */
#define OV010_CONNECTION_STREAM 0x38 /* Ov010Packet *: the stream being chunked, 0 when idle */
#define OV010_CONNECTION_PACKET 0x3c /* Ov010Packet *: packet currently being sent */
#define OV010_CONNECTION_PACKET_SIZE 0x40 /* u32: its total byte count */
#define OV010_CONNECTION_RECIPIENTS 0x44 /* u16: one bit per peer the packet is addressed to */

/* The ov010 packet-assembly object (gOv010PacketAssemblyClass): at +0x34 it keeps
 * one receive-assembly slot per online peer (OV010_ASSEMBLY_*), each filled from
 * that peer's incoming packet fragments and drained by FreePacketAssemblySlot. */
#define OV010_ASSEMBLY_SLOTS       0x34 /* first of 4 per-peer assembly slots */
#define OV010_ASSEMBLY_SLOT_COUNT  4    /* assembly slots (one per online peer) */
#define OV010_ASSEMBLY_SLOT_STRIDE 0x08 /* bytes per peer slot */
#define OV010_ASSEMBLY_SLOT_OFFSET 0x00 /* s32 bytes of the packet assembled so far */
#define OV010_ASSEMBLY_SLOT_PACKET 0x04 /* void *packet being assembled, 0 when idle */

/* A match-request node (a 3D sprite Link_CreateMatchRequest has the active link
 * overlay create): the arguments of the search it runs, read back when the node
 * is stepped (OnlineMatchRequest_StartQuery).  The online runner hands slots TYPE/TIMEOUT
 * and TIMEOUT/FLAGS to Ov010_RequestWfcMatch as its timeout and flags-out. */
#define MATCH_REQUEST_NAMES      0x34 /* s32: player-name text the query looks up */
#define MATCH_REQUEST_NAME_COUNT 0x38 /* s32: number of names in the table */
#define MATCH_REQUEST_TYPE       0x3C /* s32: game type the query asks for */
#define MATCH_REQUEST_TIMEOUT    0x40 /* s32: query timeout */
#define MATCH_REQUEST_FLAGS      0x44 /* s32: caller's search result/flags buffer */

/* A match player's info record (0x210 bytes), filled by gpGetBuddyStatus from
 * the GameSpy buddy list (gp.c's GPBuddyStatus). The key/value string holds the
 * player's fields, e.g. "SCM=1/SCN=2/". */
typedef struct MatchPlayerInfo {
    s32 profileId;     /* +0x00 the buddy's GameSpy profile id */
    s32 status;        /* +0x04 6 = a valid player record */
    u8  fields[0x100]; /* +0x08 key/value status string */
    u8  name[0x100];   /* +0x108 location/display name */
    u32 ipAddr;        /* +0x208 advertised IPv4 address */
    s32 port;          /* +0x20C advertised port */
} MatchPlayerInfo;     /* 0x210 bytes */

/* A GameSpy buddy-list record (keyed by profile id) and its details: the
 * buddy's position in the list, presence status, two owned strings and the
 * advertised address. Built by gpiBuddy.c, read by gpGetBuddyStatus. */
typedef struct GpiBuddyStatusDetails {
    s32  index;          /* +0x00 position in the buddy list */
    s32  status;         /* +0x04 presence status */
    s8  *statusString;   /* +0x08 owned key/value status string */
    s8  *locationString; /* +0x0C owned location string */
    u32  ipAddr;         /* +0x10 advertised IPv4 address */
    s32  port;           /* +0x14 advertised port */
} GpiBuddyStatusDetails;

typedef struct GpiBuddyStatus {
    s32 profileId;                  /* +0x00 the buddy's profile id (the table key) */
    s32 unk04;                      /* +0x04 */
    GpiBuddyStatusDetails *details; /* +0x08 presence and address, NULL once released */
    void *cachedInfo;               /* +0x0C cached profile info (GPI_INFO_RESULT_WORDS words) */
    s8  *signature;                 /* +0x10 owned status signature */
    s32  useCount;                  /* +0x14 operations still holding the record */
    s8  *unk18;                     /* +0x18 owned string */
} GpiBuddyStatus;

/* GpiBuddyStatus field offsets, for the code that reaches the record through a
 * raw pointer. */
#define GPI_BUDDY_DETAILS     0x08
#define GPI_BUDDY_CACHED_INFO 0x0C
#define GPI_BUDDY_SIGNATURE   0x10
#define GPI_BUDDY_USE_COUNT   0x14
#define GPI_BUDDY_UNK18       0x18

/* GpiBuddyStatusDetails field offsets (the two owned strings). */
#define GPI_BUDDY_STATUS_STRING   0x08
#define GPI_BUDDY_LOCATION_STRING 0x0C

/* While set, a released buddy-status record keeps its presence details instead
 * of dropping them, so the details alone can keep the record in the table. */
#define GPI_CONN_KEEP_BUDDY_DETAILS 0x104

/* The voice-chat ("VCHT") option menu entity (main_020E0194): the option row
 * that starts selected and the widget sprites the setup creates. */
#define VCHT_MENU_SELECTED_ROW 0x3C /* s32 id of the row the toggle starts on */
#define VCHT_MENU_FLAGS        0x48 /* u16: VCHT_FLAG_* */
#define VCHT_MENU_TOGGLE0      0x50 /* void *first toggle-option widget */
#define VCHT_MENU_TOGGLE1      0x58 /* void *second toggle-option widget */
#define VCHT_MENU_LABEL        0x64 /* void *the option's label text */
#define VCHT_MENU_ANIM         0x68 /* void *the option's animation widget */

/* VCHT_MENU_FLAGS bits. */
#define VCHT_FLAG_CONFIRMED 0x0008 /* the option was confirmed; the update waits on it */
#define VCHT_FLAG_BUILDING  0x0020 /* the menu was just built; the next update clears it */
#define VCHT_FLAG_OVERLAY   0x1000 /* the link overlay event the shared update records */

/* The match id a link/online start request carries ('VCHT'): the start record
 * both consoles compare (LINK_START_RECORD_ID), so only a request for the same
 * session type is accepted.  Link_CreateStartRequest tags its request object
 * with it (the object's +0x34 field). */
#define MATCH_ID_VCHT 0x56434854

/* The local player's link status (GetLocalPlayerStatus): its option bits and
 * the player id the online session assigned to this console. */
#define LOCAL_STATUS_OPTIONS    0x1A /* u8 option bits the link menus edit */
#define LOCAL_STATUS_PLAYER_ID  0x1C /* s32 id of this console's player in the online match */
#define LOCAL_OPTION_ONLINE     0x02 /* an online/link session is running (the wait callbacks check it) */
#define LOCAL_OPTION_VOICE_CHAT 0x04 /* voice chat is on */

/* GameSpy skill ratings are fixed point with twelve fraction bits: a rating of
 * 1500 (the default for a new player) is 0x5DC000.  A joining peer's rating is
 * accepted once it is within a tolerance of the local player's, which widens
 * by 20 points an update up to RATING_TOLERANCE_MAX; the closer the two
 * ratings, the higher the match quality (up to MATCH_QUALITY_MAX). */
#define RATING_ONE              0x1000
#define RATING_DEFAULT          0x5DC000
#define RATING_TOLERANCE_START  10
#define RATING_TOLERANCE_STEP   20
#define RATING_TOLERANCE_MAX    50000
#define MATCH_QUALITY_MAX       0x7FFFFF

/* Per-slot peer record (gPlayerPeers[slot], 8 bytes): the connection slot the
 * player came in on and the peer id assigned to it in the match. */
typedef struct PlayerPeer {
    u8  slot;   /* +0x00 connection slot */
    u8  peerId; /* +0x01 peer id within the match */
    u16 unk02;  /* +0x02 */
    s32 unk04;  /* +0x04 */
} PlayerPeer;   /* 8 bytes */

/* Sprite state of the ov001 menu screen's region selector: one object plus two
 * rows of three item sprites. column remembers which column the selection came
 * from so the wide bar (region 3) can return to it. */
typedef struct Ov001MenuSprites {
    void *obj;        /* +0x00 */
    void *top[3];     /* +0x04 top-row item sprites */
    void *middle[3];  /* +0x10 middle-row item sprites */
    u8   column;      /* +0x1C last column of the two rows */
    u8   mode;        /* +0x1D OV001_MENU_MODE_* */
} Ov001MenuSprites;

/* Ov001MenuSprites::mode: what the player's icon-row choice did. */
#define OV001_MENU_MODE_CHOSEN 1 /* an item was chosen, so open it */
#define OV001_MENU_MODE_CANCEL 2 /* the choice was cancelled, so close the menu */

/* The ov001 menu screen's selection state (gOv001MenuRegion): the selected
 * region (0..6, the touch rectangles are at data_ov001_0218fa02) and its
 * sprite state. */
typedef struct Ov001MenuRegion {
    u8 index;             /* +0x00 selected region */
    u8 pad01[3];
    Ov001MenuSprites *sprites; /* +0x04 */
} Ov001MenuRegion;

/* Directions passed to Ov001_MoveMenuRegion. */
enum {
    OV001_DIR_LEFT  = 0,
    OV001_DIR_UP    = 1,
    OV001_DIR_RIGHT = 2,
    OV001_DIR_DOWN  = 3
};

/* The ov001 icon menu's selection state: the highlighted entry, the entry to
 * return to when a move is cancelled, whether the choice was confirmed rather
 * than cancelled, and the loaded menu graphics file. */
typedef struct Ov001IconMenuState {
    s8   savedSelection; /* +0x00 selection restored when a move is cancelled */
    s8   selection;      /* +0x01 highlighted entry */
    u8   confirmed;      /* +0x02 nonzero once the player confirmed the choice */
    u8   pad03;
    void *file;          /* +0x04 loaded menu graphics file */
} Ov001IconMenuState;

/* The ov001 save data (gSaveData, 0x6f8 bytes): four 0x100-byte save slots from
 * +0 and the working copy of the current slot at +0x400.  Name data lives at the
 * same slot-relative offsets the StorePlayerName helper uses on the working slot. */
 #define SAVE_PLAYER_NAMES   0x480 /* four 16-byte player-name fields in the working slot */
 #define SAVE_NAME_SIZE      0x10  /* bytes per stored name */
 #define SAVE_NAME_TEXT_MAX  0x20  /* longest name text accepted (hex or raw) */
 #define SAVE_NAME_FLAGS     0x4e6 /* u8: low 2 bits name-length class, high bits flags */
 #define SAVE_NAME_MODE_MASK 0x03  /* name-length class (0, 5, 13 or 16 bytes) */
 #define SAVE_NAME_RAW       0x04  /* name was copied raw instead of hex-decoded */
 #define SAVE_NAME_FLAGS_MASK 0xfc /* remaining flag bits */

 /* The rest of the working save slot (gSaveData + SAVE_WORK_SLOT).  The slot's
  * own fields are at these offsets; +0x4f0..+0x4ff exist only in the working
  * copy, the card slot stores a bit count of the code there instead. */
 #define SAVE_WORK_SLOT      0x400 /* the 0x100-byte working copy of the current slot */
 #define SAVE_MAP_NAME       0x440 /* u8[32]: the saved match's map name text */
#define SAVE_MAP_NAME_SIZE  0x20  /* bytes of map-name text stored */
 #define SAVE_PLAYER_CODES   0x4c0 /* four 4-byte dotted values, one per player */
 #define SAVE_CODE_BITS      0x4d0 /* u8: set-bit count of the slot's code */
 #define SAVE_CO_NAMES       0x4d1 /* four 5-byte CO-name fields */
 #define SAVE_SLOT_STATUS    0x4e7 /* u8: slot status (1/2 written, 0xFF erased) */
 #define SAVE_CODE           0x4f0 /* 4-byte dotted map/verification code (working copy only) */
 #define SAVE_SLOT_INDEX     0x4f4 /* u8: physical slot the working copy belongs to */
 #define SAVE_EXTRA_EMPTY_A  0x4f5 /* u8: the +0xc0/+0xc4 codes are absent (cleared on commit) */
 #define SAVE_EXTRA_EMPTY_B  0x4f6 /* u8: the +0xc8/+0xcc codes are absent (cleared on commit) */
#define SAVE_SLOT_SIZE         0x100 /* bytes per physical save slot image */
#define SAVE_SLOT_IMAGE_SIZE   0xF0  /* slot bytes copied to/from the working copy; above this is working-copy only */
#define SAVE_SLOT_STATUS_REL   0xE7  /* slot-relative SAVE_SLOT_STATUS: 1/2 written, 0xFF erased */
#define SAVE_SLOT_PROFILE_CODE_SIZE 14 /* bytes of the local Wi-Fi profile code stored at SAVE_SLOT_CODE */
#define SAVE_SLOT_MAP_NAME     0x40 /* offset within one slot image of SAVE_MAP_NAME */
#define SAVE_SLOT_PLAYER_CODES 0xC0 /* offset within one 0x100-byte slot image of the player-code fields */
#define SAVE_SLOT_CODE_BITS    0xD0 /* offset within one slot image of the SAVE_CODE_BITS byte */
#define SAVE_SLOT_CODE         0xF0 /* offset within one slot image of the SAVE_CODE word (working copy only) */
#define SAVE_SLOT_INDEX_REL    0xF4 /* offset within one slot image of SAVE_SLOT_INDEX */
#define SAVE_SLOT_EMPTY_A      0xF5 /* offset within one slot image of SAVE_EXTRA_EMPTY_A */
#define SAVE_SLOT_EMPTY_B      0xF6 /* offset within one slot image of SAVE_EXTRA_EMPTY_B */
#define SAVE_SLOT_FLAGS        0xEF /* u8: bitmap of written slots (bit n = slot n), mirrored in the first two slot images */
#define SAVE_SLOT_CLEAR_SIZE   0xEF /* bytes of a slot image cleared when the slot is erased: everything before its flags byte */
#define SAVE_SLOT_CRC          0xFE /* offset within one slot image of its trailing 2-byte CRC16 */
#define SAVE_SLOT_CRC_SIZE     0xFE /* bytes of a slot image covered by that CRC16 (everything before it) */
#define SAVE_SLOT_STATUS_ERASED 0xFF /* SAVE_SLOT_STATUS value of an erased slot */
#define SAVE_CRC_TABLE         0x4F8 /* u16[256]: CRC16 lookup table (built by BuildCrc16Table) */
#define SAVE_DATA_SIZE         0x6F8 /* bytes of the ov001 save data block (four slots, working copy, CRC table) */

/* Reflected (bit-reversed) CRC polynomials BuildCrc16Table/BuildCrc32Table are
 * called with. */
#define CRC16_POLYNOMIAL 0xA001
#define CRC32_POLYNOMIAL 0xEDB88320

 /* The link-match setup sent before a saved battle (the 0xE8-byte state that
  * Ov001_CopyLinkMatchSetup copies out of the receive buffer): the map name, the
  * name-length class shared by the four player names, and the name texts. */
 #define MATCH_SETUP_MAP_NAME   0x00 /* u8[32]: map name text */
 #define MATCH_SETUP_NAME_CLASS 0x20 /* s32: 1 = 5, 2 = 13, 3 = 16 bytes per name */
 #define MATCH_SETUP_NAMES      0x28 /* u8[4][32]: player name texts */

/* The card battle-save block (SAVE_BLOCK_SIZE bytes): a magic word, then 60
 * 12-byte slot summaries and 60 40-byte slot records.  The save manager scans
 * SAVE_RECORD_STRIDE-byte directory records to find the newest one of a type. */
#define SAVE_BLOCK_MAGIC        0x07090600 /* first word of an initialised save block */
#define SAVE_BLOCK_SIZE         0xC34      /* bytes of a complete battle save */

/* A block of the card save archive (SaveManager_ScanArchive walks 256 of them
 * in 0x400-byte steps): a magic word, the block's byte length, its type and
 * version, then the links to the previous and next block of the chain.  Type 1
 * is the save-list head, whose two link words hold its timestamp instead. */
#define SAVE_ARCHIVE_MAGIC      0x32777364 /* "dws2" first word of an archive block */
#define SAVE_ARCHIVE_CHECKSUM   0x04 /* u32 sum of the block's bytes from SAVE_ARCHIVE_SUMMARY */
#define SAVE_ARCHIVE_SUMMARY    0x08 /* the block's 12-byte directory record, where its checksum starts */
#define SAVE_ARCHIVE_LENGTH     0x0C /* u16 bytes the block occupies, at most SAVE_ARCHIVE_MAX_SIZE */
#define SAVE_ARCHIVE_TYPE       0x0E /* u8 SAVE_ARCHIVE_TYPE_* or 9 + campaign map index */
#define SAVE_ARCHIVE_VERSION    0x0F /* u8 block format version, 1 */
#define SAVE_ARCHIVE_PREV       0x10 /* u16 previous block, SAVE_ARCHIVE_LINK_NONE; the head's low timestamp word */
#define SAVE_ARCHIVE_NEXT       0x12 /* u16 next block, SAVE_ARCHIVE_LINK_NONE; the head's high timestamp word */
#define SAVE_ARCHIVE_MAX_SIZE   0x400 /* largest block the archive holds */
#define SAVE_ARCHIVE_TYPE_LIMIT 0x3B /* block types below this are known */
#define SAVE_ARCHIVE_TYPE_HEAD  1    /* the block holding the save list itself */
#define SAVE_ARCHIVE_LINK_MAX   0x100 /* highest block link that is not SAVE_ARCHIVE_LINK_NONE */
#define SAVE_ARCHIVE_LINK_NONE  0xFFFF /* no previous/next block */

/* The local player's profile save block (the object main_020C3D34's
 * GetProfileSaveBlock returns): the save magic, a 0x40-byte profile-id block and then
 * the profile's own fields. */
#define PROFILE_ID_BLOCK      0x04 /* 0x40-byte profile-id block (InitProfileIdBlock) */
#define PROFILE_ID_BLOCK_SIZE 0x40
#define PROFILE_ID_BLOCK_LOGIN_KEY 0x04 /* 12-byte NAS login key recorded by InitNasLoginKey */
#define PROFILE_ID_BLOCK_KEY     0x10 /* 12-byte NAS player key record (player code + its check word) */
#define PROFILE_ID_BLOCK_ID      0x1C /* s32 GameSpy profile id the key was resolved to */
#define PROFILE_ID_BLOCK_KEY_SET 0x20 /* u32 bit 0: a key has been stored in the block */
#define PROFILE_ID_BLOCK_GAME_ID 0x24 /* u32 game id (0x5957324A, "YW2J"): salt of player codes and key type in their text form */
#define PROFILE_GAME_ID_CODE 0x5957324A /* u32 game id ("YW2J") stored in the profile-id block */
#define PROFILE_ID_BLOCK_CRC     0x3C /* u32 CRC32 of the block's first 0x3C bytes */
#define SAVE_SLOT_COUNT         60         /* slot summaries/records in a block */
#define SAVE_SLOT_SUMMARY_SIZE  12         /* bytes per slot summary */
#define SAVE_SLOT_RECORD_SIZE   0x28       /* bytes per slot record */
#define SAVE_SUMMARIES_OFFSET   4          /* first slot summary */
#define SAVE_RECORDS_OFFSET     0x2d4      /* first slot record */
#define SAVE_RECORD_STRIDE      0x28       /* bytes per save-directory / battle-save record */
#define SAVE_RECORD_ZERO_PREFIX 0x1A       /* initial bytes cleared in each battle-save record */
#define SAVE_RECORD_INIT_WORD0  0x1A       /* s16 initialized to 0 */
#define SAVE_RECORD_INIT_WORD1  0x1C       /* s16 initialized to 0 */
#define SAVE_RECORD_INIT_WORD2  0x1E       /* s16 initialized to 0 */
#define SAVE_RECORD_INIT_BYTE0  0x20       /* s8 initialized to -1 */
#define SAVE_RECORD_INIT_BYTE1  0x21       /* s8 initialized to -2 */
#define SAVE_RECORD_INIT_BYTE2  0x22       /* s8 initialized to -2 */
#define SAVE_RECORD_ID          0          /* u16 slot id inside a directory record */
#define SAVE_RECORD_TYPE        2          /* u8 save type inside a directory record */
#define SAVE_RECORD_TIME        4          /* u32 timestamp inside a directory record */
#define SAVE_TYPE_PLAYER        2          /* player/profile save */
#define SAVE_TYPE_BATTLE        3          /* battle save */
#define SAVE_TYPE_SETTINGS      4          /* the shared game-settings snapshot (gGameSettingsSaveBuffer) */
#define SAVE_SETTINGS_RECORD_SIZE 0x5CC    /* bytes of the shared game-settings snapshot */
#define SAVE_TYPE_CAMPAIGN_MAP  9          /* campaign map index 0; record type = 9 + map index */
/* The save block a save/load screen sprite reads or writes, at its +0x34.  The
 * main save/load screen holds both: the profile block at +0x34 and the battle
 * save block at +0x38 (CreateSaveLoadScreen). */
#define SAVE_SPRITE_BLOCK       0x34       /* void *: profile or battle save block */
#define SAVE_SPRITE_BATTLE_BLOCK 0x38      /* void *: battle save block */
/* The save-progress indicator sprite (gSaveIndicatorClass) keeps the save block
 * it was handed at +0x54 and frees it once the save is done. */
#define SAVE_INDICATOR_BLOCK     0x54       /* void *: save block the indicator owns */

/* Battle-save record types GetCurrentSaveType returns and SaveTypeHasNoSlot
 * tests: a campaign battle uses SAVE_RECORD_TYPE_CAMPAIGN + its save slot
 * (0..2), a versus battle the single SAVE_RECORD_TYPE_VERSUS record, which has
 * no save slot of its own. */
#define SAVE_RECORD_TYPE_CAMPAIGN 5 /* first campaign battle record (SAVE_RECORD_TYPE_CAMPAIGN + slot) */
#define SAVE_RECORD_TYPE_VERSUS   8 /* the versus battle's single record */

/* The campaign progress records (gCampaignSaveRecords): one 0x118-byte record
 * per campaign save slot.  Each starts with the 8-byte save summary
 * StoreSaveSlotProgress writes (slot and day count, then the map and its turn),
 * followed by the per-map progress and CO/rank tables. */
#define CAMPAIGN_RECORD_SIZE    0x118 /* bytes per campaign progress record */
#define CAMPAIGN_RECORD_COUNT   3     /* records in gCampaignSaveRecords */
#define CAMPAIGN_RECORD_SUMMARY 0x00  /* u32[2]: the record's 8-byte save summary */

/* A battle save record: eight bytes kept per save slot (slots 5..8, see
 * GetBattleSaveRecord) describing the last battle fought there. */
#define BATTLE_RECORD_SIZE  0x08 /* bytes per battle save record */
#define BATTLE_RECORD_MAP   0x00 /* u16: map id the battle was fought on, 0 when the slot is empty */
#define BATTLE_RECORD_DAYS  0x02 /* u16: days the battle lasted (gCurrentMap +0x52a2, capped at 999) */
#define BATTLE_RECORD_DATE  0x04 /* u32: local date/time, year:8 month:6 day:6 hour:6 minute:6 */

/* Save-chip configuration the save manager asks the device for before it reads
 * the archive: the chip kind in the low byte and the size/variant bit index in
 * bits 8..15 (0x1202 = kind 2, bit 18).  The device must report state 2 after. */
#define SAVE_DEVICE_CONFIG      0x1202
#define SAVE_DEVICE_STATE_READY 2      /* SaveDevice_GetState result once configured */

/* The save-chip device state (gSaveDeviceState): the card lock the CARD_* calls
 * take, the backup transfer the device runs a chunk at a time, the device task
 * with the thread queue transfers sleep on, and the transfer flags.  Offsets
 * 0x18..0x4C hold the lock kind and then the chip configuration and the
 * per-transfer parameters (callback, retries, unit size). */
#define SAVE_DEVICE_RESPONSE      0x00 /* s32 *: reply block from the ARM7; word 0 is the transfer status */
#define SAVE_DEVICE_STATE         0x04 /* s32: device state, SAVE_DEVICE_STATE_READY once configured */
#define SAVE_DEVICE_ADDRESS       0x1C /* u32: source (backup-chip) address of the transfer */
#define SAVE_DEVICE_DEST          0x20 /* u32: destination RAM address of the transfer */
#define SAVE_DEVICE_LENGTH        0x24 /* u32: bytes of the transfer still to move */
#define SAVE_DEVICE_DMA_CHANNEL   0x28 /* s32: DMA channel the transfer runs on */
#define SAVE_DEVICE_CALLBACK      0x38 /* void (*)(s32): called once the transfer ends */
#define SAVE_DEVICE_CALLBACK_ARG  0x3C /* s32: argument of that callback */
#define SAVE_DEVICE_TASK          0x44 /* task the transfer runs in when it is asynchronous */
#define SAVE_DEVICE_TASK_ROUTINE  0x40 /* void (*)(void *): routine the worker thread runs when a transfer wakes it */
#define SAVE_DEVICE_REQUEST_TASK  0x104 /* void *: task the pending transfer/command request runs in, woken once the ARM7 replies */
#define SAVE_DEVICE_THREAD_QUEUE  0x10C /* OSThreadQueue: threads asleep on the running transfer */
#define SAVE_DEVICE_FLAGS         0x114 /* u32: SAVE_DEVICE_FLAG_* of the transfer */
#define SAVE_DEVICE_PRIORITY      0x108 /* s32: run priority of the transfer task */

/* Flags of the save-chip device state (SAVE_DEVICE_FLAGS). */
#define SAVE_DEVICE_FLAG_BUSY         0x04 /* a transfer is running */
#define SAVE_DEVICE_FLAG_ASYNC        0x08 /* the transfer runs in SAVE_DEVICE_TASK */
#define SAVE_DEVICE_FLAG_TASK_WAITING 0x10 /* a task sleeps until the transfer ends */
#define SAVE_DEVICE_FLAG_COMMAND      0x20 /* a command is queued to the ARM7 */
#define SAVE_DEVICE_FLAG_CHUNK        0x40 /* the transfer moves through the bounce buffer */

/* Lock class passed to SaveDevice_Lock/SaveDevice_Unlock: which card access the
 * lock guards (the ROM/archive or the backup/save chip). */
#define SAVE_DEVICE_LOCK_ROM     1 /* the card ROM / archive */
#define SAVE_DEVICE_LOCK_BACKUP  2 /* the backup (save) chip */

/* The save manager / queued save list object (gSaveManager): byte 0x2050 is
 * nonzero once the archive was initialised, 0x2052 becomes 1 once it failed. */
#define SAVE_MANAGER_ACTIVE 0x2050 /* u8: the archive was initialised */
#define SAVE_MANAGER_STATE  0x2052 /* u8: 1 = the archive is unusable */
#define SAVE_MANAGER_DIRTY  0x2053 /* u8: set when the directory was repaired/changed and needs writing back */
#define SAVE_MANAGER_QUEUE       0x2054 /* the request queue: SAVE_REQUEST_STRIDE-byte entries */
#define SAVE_MANAGER_QUEUE_COUNT 0x2554 /* u32 number of requests queued */

/* One queued save-list request.  Its kind byte selects the fields SaveList_Flush
 * reads: an update carries two records and a value type, a delete a record id. */
#define SAVE_REQUEST_STRIDE 0x14 /* bytes per queued request */
#define SAVE_REQUEST_RECORD 0x0C /* u16 record id of a delete request */
#define SAVE_REQUEST_KIND   0x0F /* u8 SAVE_REQUEST_* */
enum {
    SAVE_REQUEST_UPDATE = 1, /* write a record back (SaveList_EnqueueUpdate) */
    SAVE_REQUEST_DELETE = 2  /* drop a record (a delete request) */
};

/* One 12-byte entry of the save manager's block index table (gSaveManager +
 * index * SAVE_BLOCK_ENTRY_STRIDE): SaveManager_ScanArchive copies it from the
 * block header's +8, so it mirrors the header's length, type, version and links. */
typedef struct SaveBlockEntry {
    u32 time;    /* +0x00 block timestamp */
    u16 length;  /* +0x04 bytes the block occupies */
    u8  type;    /* +0x06 SAVE_ARCHIVE_TYPE_* */
    u8  version; /* +0x07 block format version */
    u16 prev;    /* +0x08 previous block, SAVE_ARCHIVE_LINK_NONE for a chain root */
    u16 next;    /* +0x0A next block, SAVE_ARCHIVE_LINK_NONE at the end */
} SaveBlockEntry; /* 12 bytes */

#define SAVE_BLOCK_ENTRY_STRIDE 12   /* bytes per index-table entry */
#define SAVE_BLOCK_ENTRY_TIME    0x00 /* u32 block timestamp */
#define SAVE_BLOCK_ENTRY_LENGTH  0x04 /* u16 bytes the block occupies */
#define SAVE_BLOCK_ENTRY_TYPE    0x06 /* u8 SAVE_ARCHIVE_TYPE_* */
#define SAVE_BLOCK_ENTRY_VERSION 0x07 /* u8 block format version */
#define SAVE_BLOCK_ENTRY_PREV    0x08 /* u16 previous block, SAVE_ARCHIVE_LINK_NONE for a chain root */
#define SAVE_BLOCK_ENTRY_NEXT    0x0A /* u16 next block, SAVE_ARCHIVE_LINK_NONE at the end */
#define SAVE_ARCHIVE_HEADER_SIZE 0x14 /* bytes before a continuation block's payload */
#define SAVE_ARCHIVE_ROOT_SIZE   0x38 /* bytes before a chain-root block's payload */

/* Kinds of 4-byte connection notice sent by SendConnectionPacket(kind, slot). */
enum {
    CONN_NOTICE_PLAYER_SLOT = 2, /* claim a player slot (last-player flag, slot, id) */
    CONN_NOTICE_SYNC_STATUS = 3, /* report own slot and measured latency */
    CONN_NOTICE_SYNC_DONE   = 4  /* the sync is finished */
};

/* Frame table of one map info window icon: the animation the icon plays. */
typedef struct MapInfoIconFrames {
    s8 first;        /* +0x00 first tile */
    u8 unk01;        /* +0x01 */
    u16 start;       /* +0x02 */
    u16 end;         /* +0x04 */
    s16 unk06;       /* +0x06 */
    s16 unk08;       /* +0x08 */
    s16 unk0A;       /* +0x0A */
    s16 unk0C;       /* +0x0C */
    s16 unk0E;       /* +0x0E */
    s16 unk10;       /* +0x10 */
} MapInfoIconFrames; /* 0x12 bytes */

/* One icon of the map info window (an icon animation object). */
typedef struct MapInfoIcon {
    MapInfoIconFrames *frames; /* +0x00 */
    void *anim;                /* +0x04 animation descriptor */
    void *vtable;              /* +0x08 */
    s16 frame;                 /* +0x0C current frame */
    u8 unk0E;                  /* +0x0E */
    u8 unk0F;                  /* +0x0F */
} MapInfoIcon;                 /* 0x10 bytes */

/* ov000 map info window: a UI node describing the army of the player whose
 * turn it is, with a unit-stat panel and seven icon animations. */
typedef struct MapInfoWindow {
    void *vtable;          /* +0x00 */
    u8 pad04[0x30];
    s16 timer;             /* +0x34 frame timer */
    u8 visible;            /* +0x36 */
    u8 pad37;              /* +0x37 */
    s16 scroll;            /* +0x38 scroll position (see func_ov000_0216b898) */
    u8 player;             /* +0x3A player the window describes */
    u8 armyState;          /* +0x3B that player's army state */
    s8 colorIndex;         /* +0x3C armour colour index, 0-based */
    u8 detailed;           /* +0x3D draw the detailed layout */
    s16 animTime;          /* +0x3E */
    void *panel;           /* +0x40 unit-stat panel */
    MapInfoIcon *icons[7]; /* +0x44..+0x5C icon animations */
} MapInfoWindow;

/* ov010 wireless-link voice channel state: three 0x94-byte records, one per
 * channel, in the ov010 link channel table. A channel pulls packets from a
 * queue and plays them back against a smoothed clock. */
typedef struct LinkChannelState {
    u32 clock;        /* +0x00 smoothed playback clock */
    u8 pad04[4];
    s32 backlog;      /* +0x08 packets left when a pull found nothing */
    u8 pad0c[8];
    s32 skipped;      /* +0x14 packets skipped over a sequence gap */
    u8 pad18[8];
    s32 played;       /* +0x20 packets played while catching up */
    u8 pad24[4];
    u32 lastTime;     /* +0x28 time the last packet was pulled */
    u32 smoothTime;   /* +0x2C smoothed time */
    u8 pad30[4];
    s32 index;        /* +0x34 queue index of this channel */
    s32 id;           /* +0x38 channel id this state belongs to */
    void *current;    /* +0x3C packet currently being played */
    u8 pad40[0x18];
    u32 lastSeq;      /* +0x58 sequence number of the last packet */
    u8 pad5c[0x14];
    s32 hold;         /* +0x70 packets still to hold back */
} LinkChannelState;   /* 0x94 bytes */

#define LINK_CHANNEL_STRIDE 0x94
#define LINK_CHANNEL_COUNT  3

/* Fields of a link packet buffer while it sits in a channel's packet queue (the
 * Link_* queue helpers): the doubly-linked list links and the ordering key. */
#define LINK_PACKET_PREV 0x04 /* void *previous packet in the queue */
#define LINK_PACKET_NEXT 0x08 /* void *next packet in the queue */
#define LINK_PACKET_KEY  0x18 /* u32 ordering key the queue is kept sorted by */
#define LINK_PACKET_CHANNEL 0x11 /* u8 link channel the packet is sent on (LINK_CHANNEL_COUNT of them) */

/* ov007 map editor text entry. The widget keeps a glyph layout table of three
 * blocks of MAPEDIT_GLYPH_COUNT entries: the base glyphs, then their voiced
 * (dakuten) and semi-voiced (handakuten) forms. The line being edited is
 * MAPEDIT_LINE_LENGTH glyph slots long. */
#define MAPEDIT_TEXT_LAYOUT       0x34  /* u32 **glyph layout: 3 blocks of 75 */
#define MAPEDIT_TEXT_CELLS        0x38  /* s32 *sprite cell list of the text line */
#define MAPEDIT_TEXT_INDEX        0x3c  /* s8 cursor into the current line */
#define MAPEDIT_LINE_LENGTH       17    /* u32 glyphs in gMapEditObjectList */
#define MAPEDIT_GLYPH_COUNT       75    /* entries per layout block */
#define MAPEDIT_DAKUTEN_VARIANTS  0x12c /* byte offset of the voiced block */
#define MAPEDIT_HANDAKUTEN_VARIANTS 0x258 /* byte offset of the semi-voiced block */

/* One cell template of the map editor's glyph keyboard: the offset and size a
 * cell gets plus the fields copied into its sprite slot, and the handlers run
 * for it.  The glyph layout uses one template per key. */
typedef struct EditorCellDesc {
    s16 offsetX;     /* +0x00 added to the cell's x */
    s16 offsetY;     /* +0x02 added to the cell's y */
    s16 width;       /* +0x04 sprite width, also the per-column x step */
    s16 height;      /* +0x06 sprite height, also the per-row y step */
    s16 unk08;       /* +0x08 */
    s16 unk0A;       /* +0x0A */
    s16 unk0C;       /* +0x0C */
    s16 unk0E;       /* +0x0E */
    void *handler10; /* +0x10 */
    void *handler14; /* +0x14 */
    void *handler18; /* +0x18 */
    void *handler1C; /* +0x1C */
    void *handler20; /* +0x20 */
    void *handler24; /* +0x24 */
} EditorCellDesc;    /* 0x28 bytes */

/* One field of an RSA key: a big-endian byte string and its length. */
typedef struct RsaKeyPart {
    s32 length;    /* +0x00 number of bytes in bytes[] */
    u8 *bytes;     /* +0x04 big-endian value */
} RsaKeyPart;

/* RSA key in CRT form, used by the TLS handshake code. The fields are the modulus n, the primes
 * p and q, the private exponents dP = d mod (p-1) and dQ = d mod (q-1), and qInv = q^-1 mod p. */
typedef struct RsaCrtKey {
    RsaKeyPart modulus; /* +0x00 n */
    RsaKeyPart p;       /* +0x08 */
    RsaKeyPart q;       /* +0x10 */
    RsaKeyPart dP;      /* +0x18 */
    RsaKeyPart dQ;      /* +0x20 */
    RsaKeyPart qInv;    /* +0x28 */
} RsaCrtKey;

/* Length of the decrypted RSA block (the TLS premaster secret). */
#define RSA_PREMASTER_LEN 0x30

/* Named RSA public key from the TLS handshake's key list (see SetTlsKeyList): the peer's
 * ServerKeyExchange carries the name that selects one, and a signature is verified by
 * exponentiating it with exponent modulo modulus. */
typedef struct NamedRsaKey {
    char *name;         /* +0x00 name sent with the handshake */
    s32 modulusLength;  /* +0x04 bytes in modulus[] */
    u8 *modulus;        /* +0x08 n, big-endian */
    s32 exponentLength; /* +0x0c bytes in exponent[] */
    u8 *exponent;       /* +0x10 e, big-endian */
} NamedRsaKey;

/* The TLS context's list of known public keys (filled by SetTlsKeyList): an
 * array of NamedRsaKey pointers and the number of entries. */
#define TLS_KEY_LIST  0x814 /* NamedRsaKey ** */
#define TLS_KEY_COUNT 0x818 /* s32 */
#define TLS_RSA_KEY   0x81C /* RsaCrtKey *: private key TlsProcessClientKeyExchange decrypts the premaster secret with */

/* TLS handshake fields used by the signature verification. */
#define TLS_DIGEST        0x468 /* u8[] hash of the handshake message that was signed */
#define TLS_DIGEST_LEN    0x47c /* s32 bytes written to TLS_DIGEST */
#define TLS_SIGNATURE     0x5a4 /* u8 * signature bytes of the handshake message */
#define TLS_SIGNATURE_LEN 0x5a8 /* s32 bytes in TLS_SIGNATURE */
#define TLS_CERT_SIGNATURE_ALGORITHM 0x458 /* s32 OID index of the certificate's signature algorithm: 3 md5WithRSA, 4 sha1WithRSA */
#define TLS_CERT_KEY_ALGORITHM 0x45c /* s32 OID index of the certificate's public key algorithm, -1 when none was parsed */
#define TLS_SIGNED_MESSAGE_START 0x460 /* u8 * first handshake message the certificate's signature covers */
#define TLS_SIGNED_MESSAGE_END 0x464 /* u8 * end of those handshake messages */
#define TLS_ISSUER_NAME    0x5b0 /* char[] name of the key that signed the certificate */
#define TLS_CERT_DATE_VALID 0x5af /* u8 nonzero while the certificate's date range contains the console's date */

/* What the certificate check reports (the low bits; 0 = the chain checks out). */
#define TLS_CERT_CHECK_DATE        0x8000 /* the certificate is not valid at the console's date */
#define TLS_CERT_CHECK_NO_SIGNATURE 1     /* the issuer's key is unknown */
#define TLS_CERT_CHECK_BAD_SIGNATURE 2    /* the signature does not verify */
#define TLS_CERT_CHECK_UNSUPPORTED  3     /* the digest algorithm is not supported */
#define TLS_CERT_CHECK_NO_KEY       4     /* the certificate carries no RSA key algorithm */

/* On-screen keyboard of the ov001 name-entry screen; gOv001MenuState points at one.  The 47
 * character keys of a page are followed by two page toggles, space, delete and the two actions. */
typedef struct Ov001KeyboardState {
    void *rowPanels[3][4]; /* +0x00 text panel of each key row, [page][row] */
    void *charKeys[47];    /* +0x30 the 47 character-key sprites of the page */
    void *auxKeys[4];      /* +0xEC sprites of the two page keys, space and delete */
    void *actionKeys[2];   /* +0xFC sprites of the case and symbols keys */
    void *textSprites[4];  /* +0x104 drawn text of each key row */
    void *cursor;          /* +0x114 sprite marking the selected key */
    s32 slideTask;         /* +0x118 slide-in animation task, 0 when none */
    u8 key;          /* +0x11C character/action produced by the last press, 0xFF = none */
    u8 page;         /* +0x11D layout shown: 0 lowercase, 1 symbols, 2 uppercase */
    s8 touchKey;     /* +0x11E key under the stylus, -1 = none */
    s8 highlightedKey; /* +0x11F key whose touch highlight is shown, -1 = none */
    s8 prevKey;      /* +0x120 key the cursor came from */
    s8 selectedKey;  /* +0x121 highlighted key, 0..52 */
    u8 deleteRepeat; /* +0x122 auto-repeat counter of the delete key */
    u8 canDelete;    /* +0x123 delete key enabled (text not empty) */
    u8 canAdd;       /* +0x124 character keys enabled (text not full) */
    u8 deleteBuzzed; /* +0x125 invalid-delete buzz already played while B is held */
} Ov001KeyboardState;

/* The on-screen keyboard slides in from the right one key row at a time; the rows
 * are staggered 22 pixels apart, and a row waits just off the screen (x = 192)
 * until the row above it has arrived. */
#define KBD_ROW_HIDDEN_X 0xC0 /* where a key row waits off the right edge */
#define KBD_ROW_REST_X0  0x51 /* resting x of the first (number) row */
#define KBD_ROW_REST_X1  0x67 /* resting x of the second row */
#define KBD_ROW_REST_X2  0x7D /* resting x of the third row */
#define KBD_ROW_REST_X3  0x93 /* resting x of the fourth row */
#define KBD_ROW_REST_X4  0xAA /* resting x of the bottom action row */

/* The two-bar icon row shared by the ov001 screens (gOv001IconRow): each page
 * id picks the pair of wide bar sprites that slide in; tapping a bar selects it
 * for a moment before the row restores itself. */
#define OV001_ICON_ROW_NOT_READY (-2) /* selected: the row has not slid in yet and takes no input */
#define OV001_ICON_ROW_WIFI_MENU   0 /* the two-bar back/confirm row of the Wi-Fi menu */
#define OV001_ICON_ROW_WFC_CONNECT 6 /* the two-bar back/confirm row of the WFC connect screen */
typedef struct Ov001IconRow {
    void *bars[2];    /* +0x00 the two option bar sprites */
    void *backdrop;   /* +0x08 wide background bar sprite */
    s32 introTimer;   /* +0x0C timer staging the slide-in */
    s32 selectTimer;  /* +0x10 timer that ends a touch selection */
    u16 introDelay;   /* +0x14 frames of the intro still to run */
    s8 selected;      /* +0x16 selected bar, -1 none, -2 not ready */
    u8 page;          /* +0x17 page id, indexes the icon-row tables */
    u8 inputLocked;   /* +0x18 nonzero: the row is moving, touch is ignored */
    u8 active;        /* +0x19 nonzero once the row is in use */
} Ov001IconRow;

/* Wi-Fi connection indicator of an ov001 screen (gOv001WfcIcon): a single
 * sprite that shows one of the four status layouts of its style and is
 * relaid out each frame from the WFC connection state. */
typedef struct Ov001WfcIcon {
    void *sprite; /* +0x00 sprite object showing the icon */
    s32 task;     /* +0x04 update task, 0 when none */
    s8 style;     /* +0x08 icon style, indexes gOv001WfcIconLayouts */
} Ov001WfcIcon;   /* 0x0C bytes */

/* Blend control registers the ov001 screen fades write: the main engine's and
 * the sub engine's BLDCNT, with BLDALPHA and BLDY at +2 and +4. */
#define GX_BLDCNT_MAIN 0x04000050
#define GX_BLDCNT_SUB  0x04001050
#define GX_BLDALPHA_MAIN 0x04000052 /* u16: EVA (bits 0-4) and EVB (bits 8-12) coefficients */
/* Bits 6-7 of BLDCNT (the effect field): how BLDY is applied.  0x40 is plain
 * alpha blending; the level's sign picks between brightening and darkening. */
#define GX_BLDCNT_EFFECT_MASK     0x00C0
#define GX_BLDCNT_EFFECT_ALPHA    0x0040
#define GX_BLDCNT_EFFECT_BRIGHTEN 0x0080 /* BLDY lightens the screen */
#define GX_BLDCNT_EFFECT_DARKEN   0x00C0 /* BLDY darkens the screen */
#define GX_VCOUNT        0x04000006 /* u16: current scanline, read by per-scanline effects */

/* Window range registers of the main engine; the sub engine's sit at +0x1000.
 * WIN0 and WIN1 each have a horizontal and a vertical range, packed as high
 * byte = first edge, low byte = second edge. */
#define GX_WIN0H_MAIN 0x04000040
#define GX_WIN0V_MAIN 0x04000042
#define GX_WIN1H_MAIN 0x04000044
#define GX_WIN1V_MAIN 0x04000046
#define GX_WIN0H_SUB  0x04001040
#define GX_WIN0V_SUB  0x04001042
#define GX_WIN1H_SUB  0x04001044
#define GX_WIN1V_SUB  0x04001046

/* The ov001 screen-fade system (gOv001FadeStates points at two Ov001Fade, the
 * sub engine's then the main engine's). A fade task maps frames 0..duration to a
 * BLDY blend value; gOv001FadeTable holds the four fade modes as three parallel
 * arrays. A negative blend value makes GX_SetBlendY fade through the backdrop. */
#define OV001_FADE_MODE_COUNT  4
#define OV001_FADE_END_BLEND   0x0 /* s8[end] BLDY value once the fade completes */
#define OV001_FADE_FLAGS       0x4 /* u8[end] OV001_FADE_* direction flags */
#define OV001_FADE_START_BLEND 0x8 /* s8[end] BLDY value the fade starts from */

/* Engine selectors and blend targets passed to Ov001_StartFade. */
enum {
    OV001_FADE_MAIN = 0,
    OV001_FADE_SUB = 1
};
/* The four gOv001FadeTable modes: where the BLDY ramp starts and ends. */
#define OV001_FADE_FROM_BLACK 0 /* -16 to 0: fade in from black */
#define OV001_FADE_TO_BLACK   1 /* 0 to -16: fade out through the backdrop */
#define OV001_FADE_FROM_WHITE 2 /* 16 to 0: fade in from white */
#define OV001_FADE_TO_WHITE   3 /* 0 to 16: fade out to white */
#define OV001_BLEND_BG0 0x01
#define OV001_BLEND_BG1 0x02
#define OV001_BLEND_BG2 0x04
#define OV001_BLEND_BG3 0x08
#define OV001_BLEND_OBJ 0x10
#define OV001_BLEND_BACKDROP 0x20
#define OV001_BLEND_ALL 0x3F /* every background plane, the OBJ layer and the backdrop */

/* A fade mode's flags (gOv001FadeTable + OV001_FADE_FLAGS + mode). */
enum {
    OV001_FADE_INVERT = 0x01, /* value = 16 - ramp, so 16 fades down to 0 */
    OV001_FADE_NEGATE = 0x10  /* value = -value, fading through the backdrop */
};

/* gOv001WfcScreenState: outcome of the Wi-Fi connection screen, picked by
 * Ov001_HandleConnectionStatus and read by its fade-out and closing steps. */
enum {
    OV001_WFC_SCREEN_NONE        = 0, /* no status reported yet */
    OV001_WFC_SCREEN_CONNECTED   = 1, /* every player is online */
    OV001_WFC_SCREEN_DISCONNECTED = 2, /* the connection was lost */
    OV001_WFC_SCREEN_NO_PLAYERS  = 3  /* no player joined the connection */
};

/* One running screen fade (Ov001FadeStates::sub / ::main). */
typedef struct Ov001Fade {
    s32 task;      /* +0x00 task created for the fade, 0 when idle */
    s16 counter;   /* +0x04 frames elapsed */
    u16 duration;  /* +0x06 frames the fade runs */
    u8  mode;      /* +0x08 index into gOv001FadeTable, 0..3 */
    u8  active;    /* +0x09 nonzero while the fade runs */
    u8  pad0A[2];  /* +0x0A */
} Ov001Fade;       /* 0x0C bytes */

typedef struct Ov001FadeStates {
    Ov001Fade sub;  /* +0x00 fades the sub engine (GX_BLDCNT_SUB) */
    Ov001Fade main; /* +0x0C fades the main engine (GX_BLDCNT_MAIN) */
} Ov001FadeStates; /* 0x18 bytes */

/* State of the ov001 name-entry screen (gNameEntryState): its entered text and
 * the position word of its cursor sprite. */
#define NAME_ENTRY_PANEL   0x00 /* text panel that draws the entered text */
#define NAME_ENTRY_CURSOR  0x04 /* s32 * cursor sprite's position/attribute word */
#define NAME_ENTRY_TEXT    0x08 /* u8[33] entered text, NUL-terminated */
#define NAME_ENTRY_MAX_LENGTH 32 /* u8 characters that fit in NAME_ENTRY_TEXT (plus its NUL) */
#define NAME_ENTRY_LENGTH  0x29 /* u8 number of characters entered */
#define NAME_ENTRY_RESULT  0x2a /* u8 result: 0 cancelled, 1 accepted, 2 rejected */
#define NAME_ENTRY_CURSOR_MASK 0xC1FFFCFF /* cursor attribute bits a cancelled entry clears */
#define NAME_ENTRY_CURSOR_POS_MASK 0xFE00FF00 /* cursor attribute bits the x/y position update replaces */

/* The name-entry screen's configuration (gOv001NameEntryConfig), one entry per
 * entry mode: the message panel shown while typing, the message shown once the
 * name is accepted, and the handler that stores it. */
#define NAME_ENTRY_CONFIG_MESSAGE_PANEL 0x00 /* u8[2] message panel id per mode */
#define NAME_ENTRY_CONFIG_RESULT_MESSAGE 0x08 /* s32[2] message id shown on acceptance, per mode */
#define NAME_ENTRY_CONFIG_ACCEPT        0x10 /* void (*[2])(u8 *text) stores the accepted name */

/* State of the ov001 friend-code entry screen (gOv001FriendCodeState): the four
 * 3-digit groups of the code being entered, the group being edited and the
 * result of the region menu that asks which saved code the entry replaces. */
#define CODE_ENTRY_PANEL       0x00 /* text panel that draws the code */
#define CODE_ENTRY_CURSOR      0x04 /* s32 * cursor sprite's position/attribute word */
#define CODE_ENTRY_TEXT        0x08 /* u8[12] four 3-character groups of the code */
#define CODE_ENTRY_GROUPS      4    /* groups in CODE_ENTRY_TEXT */
#define CODE_ENTRY_GROUP_SIZE  3    /* characters per group */
#define CODE_ENTRY_GROUP       0x14 /* u8 group being edited, 0..3 */
#define CODE_ENTRY_RESULT      0x15 /* u8 result: 0 cancelled, 1 accepted, 2 rejected */
#define CODE_ENTRY_LAST_GROUP_MIN 26 /* value the last group must reach to count as complete */

/* Cursor sprite attribute bits a cancelled code entry clears. */
#define CODE_ENTRY_CURSOR_MASK 0xC1FFFCFF



/* Attribute bits of a sprite object's entry word (the first u32 of each 8-byte entry):
 * bits 8-9 choose how the entry is drawn and bits 25-29 hold the index of the
 * rotation-scaling matrix it reads.  A normal entry is hidden with SPRITE_ENTRY_HIDDEN;
 * an affine one is drawn at double size with SPRITE_ENTRY_AFFINE|SPRITE_ENTRY_HIDDEN. */
#define SPRITE_ENTRY_ATTR_MASK     0xC1FFFCFF /* bits 8-9 and 25-29: draw mode and matrix index */
#define SPRITE_ENTRY_AFFINE        0x100 /* bit 8: the entry uses a rotation-scaling matrix */
#define SPRITE_ENTRY_HIDDEN        0x200 /* bit 9: normal entry hidden, affine entry double size */
#define SPRITE_ENTRY_AFFINE_DOUBLE 0x300 /* bits 8-9: affine entry drawn at double size */
#define SPRITE_ENTRY_MATRIX_SHIFT  25    /* bits 25-29: rotation-scaling matrix index */
/* The same entry also carries its OAM mode in bits 10-11 of the first u32 and
 * its 16-colour palette bank in bits 12-15 of the u16 at entry +4. */
#define SPRITE_ENTRY_OBJ_MODE_MASK  0x00000C00 /* bits 10-11 of the u32 at +0 */
#define SPRITE_ENTRY_OBJ_MODE_SHIFT 10
#define SPRITE_ENTRY_PALETTE_MASK   0xF000     /* bits 12-15 of the u16 at +4 */
#define SPRITE_ENTRY_PALETTE_SHIFT  12
/* The same u16 carries a 2-bit palette variant (0..3) in bits 10-11. */
#define SPRITE_ENTRY_PALETTE_VARIANT_MASK  0x0C00
#define SPRITE_ENTRY_PALETTE_VARIANT_SHIFT 10

/* Packed position word of an ov001 sprite object (the object's first word): x in
 * the low byte, y in bits 16..24. */
#define OV001_SPRITE_POS_X_MASK  0x000000FF
#define OV001_SPRITE_POS_Y_MASK  0x01FF0000
#define OV001_SPRITE_POS_Y_SHIFT 16

/* The ov001 character-bank files, loaded one per screen (gOv001CharBanks:
 * index 1 the top screen's, 0 the bottom screen's).  Each file is an array of
 * sprite layouts followed by their OAM source entries. */
#define OV001_CHAR_BANK_COUNT 2
#define OV001_CHAR_BANK_TOP    1 /* the top screen's bank */
#define OV001_CHAR_BANK_BOTTOM 0 /* the bottom screen's bank */

/* One sprite layout in a char-bank file: how many 6-byte OAM source entries it
 * has (+0x00) and where they start in the file (+0x04). */
typedef struct Ov001SpriteLayout {
    u16 count;  /* +0x00 OAM source entries in the layout */
    u16 pad02;  /* +0x02 */
    s32 offset; /* +0x04 offset of the source entries from the file's start */
} Ov001SpriteLayout;

/* The DS screen is 256x192 pixels: sprite layouts are clipped to its height. */
#define SCREEN_WIDTH  256
#define SCREEN_HEIGHT 192

/* Non-printing characters the on-screen keyboard produces. */
enum {
    KBD_KEY_NONE   = 0xFF, /* no key produced by the last press */
    KBD_KEY_DELETE = 0x80,
    KBD_KEY_CANCEL = 0x82,
    KBD_KEY_OK     = 0x83,
    KBD_KEY_SPACE  = 0xE01D /* glyph id the space key produces */
};

/* On-screen keyboard key layout: 47 character keys, then space and delete,
 * then the two bottom action keys. */
#define KBD_CHAR_KEY_COUNT 0x2F /* character keys on a page */
#define KBD_DELETE_INDEX   0x32 /* index of the delete key */
#define KBD_ACTION_KEY_BASE 0x33 /* index of the first bottom action key */
#define KBD_ROW_FIRST_LETTERS       1  /* first letter row, below the number keys */
#define KBD_FIRST_LETTER_KEY        12 /* first key in that row */
#define KBD_ROW_SECOND_LETTERS      2  /* second letter row */
#define KBD_ROW_THIRD_LETTERS       3  /* third letter row */
#define KBD_SECOND_LETTER_ROW_KEY   24 /* first key of the second letter row */
#define KBD_THIRD_LETTER_ROW_KEY    36 /* first key of the third letter row */
#define KBD_ROW_CLOSE_STEP_PIXELS   12 /* rightward movement per close frame */
#define KBD_ROW_ACTION      4    /* layout row of the two bottom action keys */

/* Delete-key auto-repeat: repeat after this many frames, dropping the counter
 * by this much per repeat. */
#define KBD_DELETE_REPEAT_DELAY 0x28
#define KBD_DELETE_REPEAT_STEP  7

/* A menu sprite object, as animated by MenuSpriteUpdate.  The current frame is
 * held in bits 18..25 of the word at +0x40, the base frame in the low nibble at
 * +0x59 and +0x5a is the press timer (negative while the press animation is
 * done). +0x64 points at the sprite-cell list the sprite draws its cells from. */
#define MENU_SPRITE_FRAME 0x40 /* u32 frame bits */
#define MENU_SPRITE_RESUME_LABEL 0x40 /* u8 low byte of MENU_SPRITE_FRAME: animation label to jump back to */
#define MENU_SPRITE_FRAME_MASK 0x03FC0000 /* bits 18..25 of MENU_SPRITE_FRAME: the current frame */
#define MENU_SPRITE_BASE  0x59 /* u8 low nibble: base frame; bit 4 enables the alternate (pressed) frame */
#define MENU_SPRITE_TIMER 0x5a /* s8 press timer, -1 = idle */
#define MENU_SPRITE_OWNER 0x64 /* SpriteCellList *the sprite's cell list */

/* A menu object is such a sprite plus the state word and child sprites of its
 * options; a menu entry points at it through +0x10 (the entry's +0x00 is the
 * value the entry shows). */
#define MENU_PRESS_SPRITE 0x5c /* void *sprite pressed when its option is taken */
#define MENU_STATE        0x48 /* u16: MENU_STATE_* */
#define MENU_STATE_OPTION 0x01 /* set: the second of the menu's two options was taken */
#define MENU_STATE_CHOSEN 0x02 /* a choice has been made, the menu is playing it out */
#define MENU_STATE_ACCEPTED 0x20 /* the menu accepted the choice and is animating away */
#define MENU_STATE_OPTION0_PRESSED 0x04 /* the menu's first option child registered its press */
#define MENU_STATE_OPTION1_PRESSED 0x08 /* the menu's second option child registered its press */

/* The battle-map menu entity (the object whose driver func_020da7e8 dispatches by
 * +0x34, with its sub-state at +0x38).  +0x40 holds the animation label the menu
 * resumes on, +0x44 the screen flag handed to GetScreenFlag, and +0x48 its state
 * flags; its child sprite objects start at +0x50. */
#define MAP_MENU_ANIM_STEP 0x40 /* u8 animation label the menu resumes at (GotoSpriteAnimationLabel) */

/* Position and slide-animation fields of the 3D sprite actor animated by
 * UpdateSpriteSlide: a current position, a slide origin and target, and a state
 * byte that also holds the visible bit and the fade mode. */
#define SPRITE_ACTOR_X           0x34 /* s16 current x */
#define SPRITE_ACTOR_Y           0x36 /* s16 current y */
#define SPRITE_ACTOR_STATE       0x48 /* u8: bit 0 visible, bits 1-3 screen, bits 4-5 fade mode, bits 6-7 slide mode */
#define SPRITE_ACTOR_SCREEN_MASK 0x0e /* bits 1-3 of SPRITE_ACTOR_STATE: DS3D_TARGET_* engine(s) to draw on */
#define SPRITE_ACTOR_SLIDE_MODE_MASK 0xc0 /* bits 6-7 of SPRITE_ACTOR_STATE */
#define SPRITE_ACTOR_SLIDE_TIMER 0x4c /* u8 frames since the slide started */
#define SPRITE_ACTOR_SLIDE_DELAY 0x4d /* u8 delay before the slide starts */
#define SPRITE_ACTOR_SLIDE_DELAY 0x4d /* u8 frames still to wait before sliding */
#define SPRITE_ACTOR_SLIDE_LEN   0x4e /* u8 slide length in frames */
#define SPRITE_ACTOR_SLIDE_BACK_LEN 0x4f /* u8 length of the reverse slide */
#define SPRITE_ACTOR_TARGET_X    0x50 /* s16 slide destination x */
#define SPRITE_ACTOR_TARGET_Y    0x52 /* s16 slide destination y */
#define SPRITE_ACTOR_START_X     0x54 /* s16 slide origin x */
#define SPRITE_ACTOR_START_Y     0x56 /* s16 slide origin y */
#define SPRITE_ACTOR_SPLIT       0x40 /* u32 bits 26..31: row where the cell grid is split in halves (16 = whole sprite) */
#define SPRITE_ACTOR_PALETTE     0x40 /* u32 bits 18..25: OBJ palette row of the actor's tiles */
#define SPRITE_ACTOR_PALETTE_MASK 0x03FC0000 /* bits 18..25 of SPRITE_ACTOR_PALETTE */
#define SPRITE_ACTOR_PRIORITY    0x49 /* u8 OBJ priority passed to AddSprite */
#define SPRITE_ACTOR_TILE_ROW    0x3e /* u16 texture row the actor draws */
#define SPRITE_ACTOR_TILE        0x3c /* u16 first tile index of the actor's graphics */
#define SPRITE_ACTOR_TEXT_WIDTH  0x58 /* s16 width in pixels of the text the actor drew */

/* Fade fields of the same 3D sprite actor, started by Show3DSpriteFade /
 * Hide3DSpriteFade and stepped by UpdateSpriteFade: bits 4-5 of
 * SPRITE_ACTOR_STATE select the direction, +0x4a is the length in frames and
 * +0x4b the frame counter; the fade writes its alpha into bits 26..31 of
 * SPRITE_ACTOR_SPLIT. */
#define SPRITE_ACTOR_FADE_LEN     0x4a /* u8 fade length in frames */
#define SPRITE_ACTOR_FADE_TIMER   0x4b /* u8 frames since the fade started */
#define SPRITE_ACTOR_FADE_MASK    0x30 /* bits 4-5 of SPRITE_ACTOR_STATE */
#define SPRITE_ACTOR_ALPHA_MASK   0xFC000000 /* bits 26..31 of SPRITE_ACTOR_SPLIT */
#define SPRITE_ACTOR_ALPHA_MAX    16 /* fully opaque value of SPRITE_ACTOR_ALPHA_MASK */
/* Fade mode (SPRITE_ACTOR_STATE bits 4-5). */
enum {
    SPRITE_FADE_NONE = 0,
    SPRITE_FADE_IN   = 1, /* fade in, showing the sprite when it starts */
    SPRITE_FADE_OUT  = 2  /* fade out, hiding the sprite when it ends */
};

/* A frame-border sprite actor (CreateFrameBorderSprite in main_02088FF4.c; its
 * draw callback outlines the rectangle below with DrawFrameBorder, or with
 * DrawFrameBorderPulse while the highlight pulses): the rectangle it outlines,
 * whether it uses the highlight tiles, and the position left for the next draw
 * to sync. */
#define FRAME_ACTOR_HIGHLIGHT 0x58 /* u8 nonzero: draw the highlight tile row */
#define FRAME_ACTOR_PULSE     0x59 /* u8 nonzero with HIGHLIGHT: animate the pulsing highlight */
#define FRAME_ACTOR_SYNC      0x5A /* u8 nonzero: copy the target position and size before drawing */
#define FRAME_ACTOR_COLOR     0x5C /* s16 colour the highlight pattern was loaded with */
#define FRAME_ACTOR_X         0x5E /* s16 left edge, synced from SPRITE_ACTOR_X */
#define FRAME_ACTOR_Y         0x60 /* s16 top edge, synced from SPRITE_ACTOR_Y */
#define FRAME_ACTOR_WIDTH     0x62 /* s16 width, synced from bits 0..8 of SPRITE_ACTOR_SPLIT */
#define FRAME_ACTOR_HEIGHT    0x64 /* s16 height, synced from bits 9..17 of SPRITE_ACTOR_SPLIT */

/* A scrolling text sprite: a sprite actor whose string is rendered by
 * SetSpriteText and drawn as a horizontal strip by func_0208b884, scrolling one
 * pixel per SPRITE_TEXT_SCROLL_PERIOD frames while the text is wider than the
 * sprite (the initialiser is next to the other text-sprite helpers). */
#define SPRITE_TEXT_SCROLL        0x5A /* s16 horizontal scroll offset in pixels */
#define SPRITE_TEXT_SCROLL_TIMER  0x5C /* u8 frames since the last scroll step */
#define SPRITE_TEXT_SCROLL_PERIOD 0x5D /* u8 frames between scroll steps */
#define SPRITE_TEXT_HANDLE        0x60 /* void *handle sprite that draws the banner */

/* A number-display sprite: a sprite actor that draws a 64-bit decimal value as a
 * row of digit sprites and lets the d-pad select a digit and change it.  Its own
 * fields come after the sprite actor's (SPRITE_ACTOR_X/Y are the position). */
#define NUMBER_DISPLAY_DIGIT     0x58 /* s32 digit the cursor starts on */
#define NUMBER_DISPLAY_DIGITS    0x5C /* s32 number of digits drawn */
#define NUMBER_DISPLAY_VALUE     0x60 /* s64 value drawn and edited */
#define NUMBER_DISPLAY_HIGH      0x64 /* s32 sign extension of the value's low word */
#define NUMBER_DISPLAY_SOURCE    0x68 /* s64 *value written back when the sprite is destroyed */

/* A countdown-timer display sprite: a sprite actor with the same layout as a
 * number display, except that its +0x58 field is the time left. DrawTimerDigits
 * renders it as minutes:centiseconds, one unit per 1/60 s frame. */
#define TIMER_DISPLAY_TICKS      0x58 /* s32 time left, in 1/60 s units */

/* A scene panel: a 3D sprite actor whose two halves (the sprite sources at
 * +0x60 and +0x64) show a pair of CO faces.  The face sprites themselves are its
 * two children (reached through Get3DSpriteChild). */
#define SCENE_PANEL_FLIP       0x58 /* u8 nonzero: swap the two face children */
#define SCENE_PANEL_FACE_STATE 0x59 /* u8 face display state (0 none, 5..10 the pose layouts) */
#define SCENE_PANEL_LAYOUT     0x5a /* u8 face layout index */
#define SCENE_PANEL_LAYOUT_TALK 1 /* SCENE_PANEL_LAYOUT: plain talk window, drawn with window_talk.cg */
#define SCENE_PANEL_LAYOUT_BODY 2 /* SCENE_PANEL_LAYOUT: body window with the two face sprites, drawn with window_body.cg */
#define SCENE_PANEL_MOTION     0x5b /* u8 motion variant: 1 offsets x, 2 offsets y, 0 draws no cursor */
#define SCENE_PANEL_MOTION_HIDDEN 0 /* the panel shows no cursor (HideMenuCursor) */
#define SCENE_PANEL_MOTION_X   0x5c /* s16 x the motion offset applies to */
#define SCENE_PANEL_MOTION_Y   0x5e /* s16 y the motion offset applies to */
#define SCENE_PANEL_HALF0      0x60 /* void *sprite source of the first half */
#define SCENE_PANEL_HALF1      0x64 /* void *sprite source of the second half */
#define SCENE_PANEL_FACE0      0x68 /* void *first face child sprite */
#define SCENE_PANEL_FACE1      0x6C /* void *second face child sprite */

/* The scene panel's shared graphics: gScenePanelGraphics, a compressed block that
 * LoadScenePanelGraphics decompresses into the current engine's texture VRAM, and
 * gScenePanelPalette, the panel's 16-colour palette uploaded to OBJ palette slot
 * DS3D_OBJ_PALETTE_BASE (byte offset in the engine's OBJ palette shadow). */
#define SCENE_PANEL_PALETTE_SLOT   (DS3D_OBJ_PALETTE_BASE << DS3D_PALETTE_SHIFT) /* 0x200 */
#define SCENE_PANEL_PALETTE_COLORS DS3D_PALETTE_BYTES /* 0x20 bytes of panel palette */

/* Slide mode (SPRITE_ACTOR_STATE bits 6-7). */
enum {
    SPRITE_SLIDE_NONE    = 0,
    SPRITE_SLIDE_FORWARD = 1, /* slide from the origin to the target */
    SPRITE_SLIDE_SHOW    = 2, /* the same, showing the sprite when it starts */
    SPRITE_SLIDE_REVERSE = 3  /* slide back to the origin, hiding the sprite when it arrives */
};

/* Work area of the movement flood fill (gMoveSearchState).  It starts with a
 * 32-entry terrain cost table, then the search limits, then two ping-pong
 * queues of 4-byte nodes (x, y, direction, accumulated cost). */
typedef struct MoveSearchNode {
    u8 x;      /* +0x00 */
    u8 y;      /* +0x01 */
    u8 dir;    /* +0x02 direction taken to reach the tile, 1 = start */
    u8 cost;   /* +0x03 accumulated movement cost */
} MoveSearchNode; /* 4 bytes */

/* MoveSearchNode::dir: the move that reached the tile. Expansion skips the
 * reverse of the direction it arrived by; the seed expands all four. */
enum {
    MOVE_SEARCH_DIR_START = 1,
    MOVE_SEARCH_DIR_UP    = 2,
    MOVE_SEARCH_DIR_DOWN  = 3,
    MOVE_SEARCH_DIR_LEFT  = 4,
    MOVE_SEARCH_DIR_RIGHT = 5
};

/* The low bits of MOVE_SEARCH_MOVE_RANGE double as this flood fill's behaviour
 * flags, read by func_01ffb114 (which units and terrains may be passed). */
#define MOVE_SEARCH_BLOCK_ALL_UNITS 0x1 /* a unit in a cell stops the search, own team's included */
#define MOVE_SEARCH_TEAM_VISION    0x2 /* consult MAP_CELL_BITMAP_TEAM_A before a unit blocks */

#define MOVE_SEARCH_FLAG_ANY_OWNER 0x01 /* cells held by other players do not block the fill */
#define MOVE_SEARCH_FLAG_ANY_VISIBILITY 0x02 /* units outside the current team's view do not block the fill */

#define MOVE_SEARCH_TERRAIN_COST 0x00 /* s8[32] movement cost per terrain kind */
#define MOVE_SEARCH_COST_LIMIT   0x20 /* s16 accumulated-cost limit */
#define MOVE_SEARCH_MOVE_RANGE   0x22 /* s16 unit move range (movement points) */
#define MOVE_SEARCH_WIDTH        0x24 /* u8 map width, filled by SelectMapLayer */
#define MOVE_SEARCH_HEIGHT       0x25 /* u8 map height, filled by SelectMapLayer */
#define MOVE_SEARCH_MOVEMENT_TYPE 0x26 /* u8 movement type the search is for */
#define MOVE_SEARCH_QUEUE_A      0x28 /* MoveSearchNode[349] */
#define MOVE_SEARCH_QUEUE_B      0x5A0 /* MoveSearchNode[349] */
#define MOVE_SEARCH_QUEUE_MAX    349

/* The pending move path of the unit under the cursor (gUnitMovePath): up to 12
 * steps on the cell grid, step 0 being the unit's own tile.  An s8 length of 0
 * means the path is empty; the entries are indexed together. */
#define UNIT_PATH_CURSOR_X  0x34 /* s8 cell x the path was last drawn from */
#define UNIT_PATH_CURSOR_Y  0x35 /* s8 cell y */
#define UNIT_PATH_X         0x36 /* s8[12] tile x of each step */
#define UNIT_PATH_Y         0x42 /* s8[12] tile y of each step */
#define UNIT_PATH_STEP_COST 0x4e /* s8[12] movement cost left at each step */
#define UNIT_PATH_START_COST 0x5a /* s8 movement cost at the unit's tile */
#define UNIT_PATH_LENGTH    0x5b /* s8 index of the last step, 0 = empty */
#define UNIT_PATH_MAX_STEPS 12

/* The side of a move-path step the path leaves through or enters through, used to
 * index gPathArrowTiles as (outgoing, incoming): UnitPath_GetOutgoingDir returns
 * the side the path leaves through, UnitPath_GetIncomingDir the side it enters
 * through.  PATH_EDGE_NONE means the step has no neighbour on the path. */
#define PATH_EDGE_NONE   0
#define PATH_EDGE_RIGHT  1
#define PATH_EDGE_BOTTOM 2
#define PATH_EDGE_LEFT   3
#define PATH_EDGE_TOP    4

/* Direction codes of a movement path (gUnitMovePath / MAP_CURSOR_PATH), one byte per
 * grid step.  MOVE_DIR_STOP and MOVE_DIR_NONE end the list; MOVE_DIR_ATTACK replaces
 * the step that would enter an enemy unit. */
#define MOVE_DIR_LEFT   0
#define MOVE_DIR_RIGHT  1
#define MOVE_DIR_DOWN   2
#define MOVE_DIR_UP     3
#define MOVE_DIR_STOP   4
#define MOVE_DIR_ATTACK 10
#define MOVE_DIR_NONE   (-1)
/* The compact command path (gCommandPath) packs two 4-bit MOVE_DIR codes per
 * byte; a 4-bit 0xF nibble is a missing step, unpacked as MOVE_DIR_NONE. */
#define COMMAND_PATH_NONE 0xF

/* Flag byte at +0x20 of the friend-code entry's sub-panels. */
typedef struct FriendCodeFlags {
    u8 active:1;
    u8 mode:4;
    u8 kind:3;
} FriendCodeFlags;

/* One of the two 0x2C-byte sub-panels of the friend-code entry screen. It is a
 * bare heap object whose only method is the MemFree destructor of
 * gHeapObjectVTable; the fields are the ones its drawing code reads. */
typedef struct FriendCodeSubPanel {
    void *vtable;        /* +0x00 gHeapObjectVTable */
    u8 unk04;            /* +0x04 */
    u8 pad05[0x0D];
    s16 unk12;           /* +0x12 */
    u8 unk14;            /* +0x14 */
    u8 unk15;            /* +0x15 */
    u8 unk16;            /* +0x16 */
    u8 unk17;            /* +0x17 */
    u8 unk18;            /* +0x18 */
    u8 pad19[7];
    FriendCodeFlags flags; /* +0x20 */
    u8 unk21;            /* +0x21 */
    u8 pad22[2];
    s32 unk24;           /* +0x24 */
    u8 unk28;            /* +0x28 */
    u8 unk29;            /* +0x29 */
    u8 pad2A[2];
} FriendCodeSubPanel;    /* 0x2C bytes */

/* The friend-code entry screen node built by FriendCodeEntry_Create: a scene
 * node with six sprite objects, two sub-panels, a 0x12-byte animation frame
 * table (laid out like MapInfoIconFrames) and a sprite-grid widget. */
typedef struct FriendCodeEntry {
    void *vtable;        /* +0x00 gFriendCodeEntryVTable */
    u8 pad04[0x30];
    u8 unk34;            /* +0x34 */
    u8 pad35[7];
    void *sprites;       /* +0x3C block of six sprite objects */
    void *panelTop;      /* +0x40 FriendCodeSubPanel */
    void *panelBottom;   /* +0x44 FriendCodeSubPanel */
    void *anim;          /* +0x48 animation frame table (0x12 bytes) */
    void *grid;          /* +0x4C sprite-grid widget */
} FriendCodeEntry;

/* Key ids of the friend-code entry keypad. The ten digit keys are ids 0-9,
 * laid out three per row (7 8 9 / 4 5 6 / 1 2 3 / 0); the remaining keys
 * follow. */
#define FRIEND_CODE_KEYPAD_COLUMNS 3
#define FRIEND_CODE_KEYPAD_CLEAR   10 /* 'C': erase the whole code */
#define FRIEND_CODE_KEYPAD_DELETE  11 /* 'B': erase the last entered digit */
#define FRIEND_CODE_KEYPAD_CANCEL  12 /* 'N': leave the code unchanged */
#define FRIEND_CODE_KEYPAD_CONFIRM 13 /* 'Y': submit the code */

/* A friend code has this many digits; gFriendCodeInput holds them plus a NUL. */
#define FRIEND_CODE_LENGTH 12
/* Digit cursor (0..FRIEND_CODE_LENGTH) of the friend-code entry state, the object
 * the keypad handlers reach through the keypad event's +0x10 pointer. */
#define FRIEND_CODE_CURSOR 0x38

/* The friend-code keypad event each per-key handler receives: the focused key
 * id and the entry state object the key acts on. */
#define FRIEND_CODE_KEY_ID    0x00 /* u8 focused key id (FRIEND_CODE_KEYPAD_*) */
#define FRIEND_CODE_KEY_STATE 0x10 /* void *friend-code entry state object */

/* The digit characters of the keypad's ten digit keys, keyed by key id 0-9:
 * one 6-byte record per key whose first byte is the digit character. */
#define FRIEND_CODE_KEY_RECORD 6

/* ov007 map generator's 30-column scratch marker grid (gMapMarkerGrid). */
#define MAP_MARKER_STRIDE 30
#define MAP_MARKER_RESERVED 1 /* cell reserved by the map border or a structure */
#define MAP_MARKER_PATH 2     /* cell covered by a generated path */
#define MAP_POINT_NONE 0xFF   /* MapPoint x value meaning the point is unset */

/* Styles for DrawFrameBorder. */
enum {
    FRAME_BORDER_INSIDE = 1,  /* frame drawn on the rectangle's own edge */
    FRAME_BORDER_OUTSIDE = 2  /* frame drawn one pixel outside the rectangle */
};

/* The animated highlight frame (DrawFrameBorderPulse): over each half period of
 * FRAME_BORDER_PULSE_STEPS eased steps, one step every other frame, the border
 * grows outward by FRAME_BORDER_PULSE_RANGE pixels and returns. */
#define FRAME_BORDER_PULSE_RANGE 2
#define FRAME_BORDER_PULSE_STEPS 8
#define FRAME_BORDER_PULSE_MASK  0x0F /* steps in a full period, both halves */

/* Window-frame tile ids stamped into a 32-column tile map by the frame-tile
 * drawer (the tiles of the frame tileset loaded for the window). A tile cell holds the
 * tile id in the low 10 bits plus the flip bits and the palette in bits 12-15. */
#define FRAME_TILE_CORNER     1    /* outer corner; the other three are mirrored */
#define FRAME_TILE_EDGE_H     2    /* horizontal (top/bottom) edge */
#define FRAME_TILE_EDGE_V     3    /* vertical (left/right) edge */
#define FRAME_TILE_STRIPE     4    /* striped style: shaded interior row */
#define FRAME_TILE_FILL       5    /* interior fill */
#define FRAME_TILE_EDGE_H_ALT 6    /* striped style: shaded top edge */
#define FRAME_TILE_FLIP_H     0x400 /* mirror the tile horizontally */
#define FRAME_TILE_FLIP_V     0x800 /* mirror the tile vertically */

/* The UI bar gradient (DrawUiGradient): the gradient strip at this offset of the
 * engine's texture area, with its end colours written to this OBJ palette slot. */
#define UI_GRADIENT_TILE    0x1400
#define UI_GRADIENT_PALETTE 1

/* UI colour ids (GetUiColor) of the two ends of that gradient: the resting bar
 * runs from the start colour to the end colour. */
#define UI_GRADIENT_COLOR_START 0xD
#define UI_GRADIENT_COLOR_END   0xE

/* UI colour id (GetUiColor) of the frame-border sprite's tint. */
#define UI_COLOR_FRAME_BORDER 9

/* UI colour id (GetUiColor) of the tint of a frame-rectangle sprite's border
 * pattern (SetFrameRectPattern). */
#define UI_COLOR_FRAME_RECT 11

/* The four grey shades DrawUiGradient writes after the two caller colours into the
 * gradient's OBJ palette (RGB555). */
#define UI_GRADIENT_SHADE_1 0x5AD6
#define UI_GRADIENT_SHADE_2 0x35AD
#define UI_GRADIENT_SHADE_3 0x4E73
#define UI_GRADIENT_SHADE_4 0x6F7B

/* DrawUiGradientPulse walks the far end of that gradient from one UI colour to
 * another and back over UI_GRADIENT_PULSE_FRAMES frames, half per direction. */
#define UI_GRADIENT_PULSE_FRAMES 0x20
#define UI_GRADIENT_PULSE_HALF   0x10

/* Display mode of a 3D sprite engine: bits 2..3 of its first halfword. */
#define SPRITE_ENGINE_MODE(engine) (((u32)(*(u16 *)M2C_FIELD((engine), void **, 0)) << 17) >> 30)

/* A frame-rectangle sprite (SetFrameRect creates one, DrawFrameRectSprite draws
 * its border every frame): the rectangle's top-left corner, its frame tile and
 * palette, and the screen it is drawn on. */
#define FRAME_RECT_X      0x38 /* s32 left edge in screen pixels */
#define FRAME_RECT_Y      0x3c /* s32 top edge in screen pixels */
#define FRAME_RECT_TILE   0x5c /* s32 frame tile id (packed with the palette by DrawFrameRectBorder) */
#define FRAME_RECT_PAL    0x60 /* s32 OBJ palette slot of the frame */
#define FRAME_RECT_SCREEN 0x64 /* s32 screen: 0 main only, 1 sub only, 3 only the engine active when it is drawn; any other value draws on both */

/* Parsed GameSpy GPI profile-info reply, built by gpiProcessGetInfo (gpiInfo.c)
 * from the \nick\, \email\, \firstname\ ... fields of the server response. */
typedef struct GpiInfoResponse {
    char *nick;           /* +0x00: \nick\ */
    char *uniqueNick;     /* +0x04: \uniquenick\ */
    char *email;          /* +0x08: \email\ */
    char *firstName;      /* +0x0C: \firstname\ */
    char *lastName;       /* +0x10: \lastname\ */
    char *homepage;       /* +0x14: \homepage\ */
    s32   icqUin;         /* +0x18: \icquin\ */
    char  zipCode[11];    /* +0x1C: \zipcode\ */
    char  countryCode[3]; /* +0x27: \countrycode\ */
    u8    pad2A[2];
    s32   longitude;      /* +0x2C: \lon\ */
    s32   latitude;       /* +0x30: \lat\ */
    char  location[128];  /* +0x34: \loc\ */
    s32   birthYear;      /* +0xB4: \birthday\ */
    s32   birthMonth;     /* +0xB8 */
    s32   birthDay;       /* +0xBC */
    s32   sex;            /* +0xC0: \sex\ */
    s32   pmask;          /* +0xC4: \pmask\ */
    char *aim;            /* +0xC8: \aim\ */
    s32   pic;            /* +0xCC: \pic\ */
    s32   occupation;     /* +0xD0: \occ\ */
    s32   industry;       /* +0xD4: \ind\ */
    s32   income;         /* +0xD8: \inc\ */
    s32   marital;        /* +0xDC: \mar\ */
    s32   children;       /* +0xE0: \chc\ */
    s32   i1;             /* +0xE4: \i1\ */
    s32   o1;             /* +0xE8: \o1\ */
    s32   conn;           /* +0xEC: \conn\ */
} GpiInfoResponse;

/* Flat info record handed to the game's gpiInfo callback (gpiInfo.c).  The
 * first two words are the result code and profile id, filled in by the caller. */
typedef struct GpiInfoRecord {
    s32  result;          /* +0x000 set by the caller */
    s32  profileId;       /* +0x004 */
    char nick[31];        /* +0x008 */
    char uniqueNick[21];  /* +0x027 */
    char email[51];       /* +0x03C */
    char firstName[31];   /* +0x06F */
    char lastName[31];    /* +0x08E */
    char homepage[76];    /* +0x0AD */
    u8   padF9[3];
    s32  icqUin;          /* +0x0FC */
    char zipCode[11];     /* +0x100 */
    char countryCode[3];  /* +0x10B */
    u8   pad10E[2];
    s32  longitude;       /* +0x110 */
    s32  latitude;        /* +0x114 */
    char location[128];   /* +0x118 */
    s32  birthYear;       /* +0x198 */
    s32  birthMonth;      /* +0x19C */
    s32  birthDay;        /* +0x1A0 */
    s32  sex;             /* +0x1A4 */
    s32  pmask;           /* +0x1A8 */
    char aim[51];         /* +0x1AC */
    u8   pad1DF;
    s32  pic;             /* +0x1E0 */
    s32  occupation;      /* +0x1E4 */
    s32  industry;        /* +0x1E8 */
    s32  income;          /* +0x1EC */
    s32  marital;         /* +0x1F0 */
    s32  children;        /* +0x1F4 */
    s32  i1;              /* +0x1F8 */
    s32  o1;              /* +0x1FC */
    s32  conn;            /* +0x200 */
} GpiInfoRecord;          /* 0x204 bytes */

/* A GameSpy gpi profile search request (gpiSearch.c): the criteria the search
 * entry point copies out of its arguments plus the socket and buffers set up. */
typedef struct GpiSearchRequest {
    s32    type;           /* +0x00: search type */
    s32    socket;         /* +0x04: SOCKET, -1 until created */
    void  *recvBuffer;     /* +0x08: received-data buffer */
    s32    recvBufferSize; /* +0x0C: its size (0x1000) */
    u8     pad10[0x08];
    void  *buffer;         /* +0x18: 0x1001-byte working buffer */
    s32    bufferSize;     /* +0x1C: its size (0x1000) */
    u8     pad20[0x08];
    char   nick[31];       /* +0x28 */
    char   uniquenick[21]; /* +0x47 */
    char   email[51];      /* +0x5C */
    char   firstname[31];  /* +0x8F */
    char   lastname[31];   /* +0xAE */
    u8     padCD[0x63];
    s32    icq;            /* +0x130 */
    s32    countrycode;    /* +0x134 */
    s32    pad138;
    s32    pad13C;         /* +0x13C */
    s32    pad140;         /* +0x140 */
} GpiSearchRequest;        /* 0x144 bytes */

/* One decoded multiplayer room-setup record in ov001 (gRoomTeamA/B and
 * gRoomRecord5/6), filled by the packet decoders in ov001_0216BD08.c. */
typedef struct Ov001PlayerRecord {
    u32  unk00;       /* +0x00 */
    s32  length;      /* +0x04: bytes used by each name/text */
    char text[40];    /* +0x08: team name or extra text */
    char name[4][64]; /* +0x30: up to four player names */
} Ov001PlayerRecord;  /* 0x130 bytes */

/* ov001 cooperative task system (gOv001Tasks): OV001_TASK_GROUP_COUNT groups,
 * each with a node pool, a message queue and a priority-ordered list of
 * pending callbacks bookended by two sentinel nodes. */
#define OV001_TASK_GROUP_COUNT 2

typedef struct Ov001ListNode {
    struct Ov001ListNode *prev; /* +0x00 */
    struct Ov001ListNode *next; /* +0x04 */
} Ov001ListNode;                /* 0x08 bytes: a list anchor */

typedef struct Ov001TaskList {
    Ov001ListNode head;         /* +0x00: head.next is the first node */
    Ov001ListNode tail;         /* +0x08: tail.prev is the last node */
} Ov001TaskList;                /* 0x10 bytes */

/* One scheduled callback; also the type of the sentinel nodes embedded in
 * every Ov001Task. */
typedef struct Ov001TaskNode {
    struct Ov001TaskNode *prev;     /* +0x00 */
    struct Ov001TaskNode *next;     /* +0x04 */
    void (*callback)(void *, s32);  /* +0x08 */
    s32  arg;                       /* +0x0C */
    u8   priority;                  /* +0x10: lower runs first */
    u8   ownsArg;                   /* +0x11: arg is an owned buffer, freed with the node */
    u8   pad12[2];
} Ov001TaskNode;                    /* 0x14 bytes */

/* One task group: nodes are recycled through freeNodes, queued messages wait
 * in pendingNodes, and pending callbacks sit in list in priority order. */
typedef struct Ov001Task {
    s32            freeNodes;    /* +0x00: queue of unused nodes */
    s32            pendingNodes; /* +0x04: queue of nodes waiting to run */
    Ov001TaskList *list;         /* +0x08: pending callbacks, head/tail sentinels below */
    Ov001TaskNode  head;         /* +0x0C: sentinel, priority 0 */
    Ov001TaskNode  tail;         /* +0x20: sentinel, priority 0xFF */
    s32            nodeCount;    /* +0x34: nodes in the pool */
    u8             enabled;      /* +0x38: nonzero while the group dispatches */
    u8             pad39[3];
    Ov001TaskNode *pool;         /* +0x3C: nodeCount nodes of this size */
} Ov001Task;                     /* 0x40 bytes */

/* Multiplayer data-transfer manager (the pointer at gTransferManager): one
 * 0x30-byte slot per player connection, each used to trickle one outgoing
 * buffer and gather one incoming buffer over several frames. */
typedef struct TransferSlot {
    s32  outData;       /* +0x00: outgoing buffer being sent */
    void *inData;       /* +0x04: incoming buffer */
    s32  inSize;        /* +0x08: capacity of inData */
    s32  outSent;       /* +0x0C: bytes of outData already sent */
    s32  inReceived;    /* +0x10: bytes of inData already received */
    s32  outSize;       /* +0x14: size of outData */
    s32  inExpected;    /* +0x18: total bytes expected to arrive */
    u8   sending;       /* +0x1C: an outgoing transfer is in progress */
    u8   state;         /* +0x1D: transfer state */
    u8   prevState;     /* +0x1E: state restored when the transfer ends */
    u8   pad1F[3];
    u16  kind;          /* +0x22: transfer kind (1..4) */
    u64  lastTick;      /* +0x24: GetSystemTick() of the last send */
    u32  timeoutMs;     /* +0x2C: idle timeout in milliseconds */
} TransferSlot;         /* 0x30 bytes */

#define TRANSFER_SLOT_COUNT    32    /* identity bits, one slot each */
/* The 8-byte header that opens every multiplayer transfer (SendTransfer /
 * BuildTransferHeader): the payload size, the transfer kind and the magic tag. */
#define TRANSFER_HEADER_SIZE   0x00 /* s32 payload bytes that follow the header */
#define TRANSFER_HEADER_KIND   0x04 /* s16 transfer kind (1..4) */
#define TRANSFER_HEADER_MAGIC  0x06 /* u16 must equal gTransferMagic */
#define TRANSFER_DEFAULT_CHUNK 0x5B9 /* default bytes sent per frame */
/* Free GT2 send-buffer space kept spare when checking for room for a transfer
 * chunk (GetSendSpace): the space is reported as the buffer's free bytes less
 * this margin, so a chunk queued right after the check still fits. */
#define TRANSFER_SEND_MARGIN (-0x207)
#define TICKS_TO_MS_DIVISOR    0x82EA /* ((GetSystemTick delta) << 6) / this = ms */
#define TICKS_TO_SECONDS_DIVISOR 0x1FF6210ULL /* ((GetSystemTick delta) << 6) / this = seconds */

typedef struct TransferManager {
    TransferSlot slots[TRANSFER_SLOT_COUNT];          /* +0x000 */
    void (*onSent)(s32 size, s32 id);                 /* +0x600: outgoing transfer done */
    void (*onReceived)(s32 id, void *buf, s32 size);  /* +0x604: incoming buffer complete */
    void (*onTimeout)(s32 id);                        /* +0x608: idle timeout elapsed */
    void (*onError)(s32 error, s32 id);               /* +0x60C: called with the error code and the connection's player id */
    u16  chunkSize;                                   /* +0x610: bytes sent per frame */
    u8   pad612[2];
} TransferManager;      /* 0x614 bytes */

/* ov010 voice-chat link protocol: one context per peer exchange plus the
 * handshake state of the exchange currently being served. */
#define VOICE_LINK_CONTEXT_MAX 8 /* exchange contexts a voice-chat link keeps */

/* The link's packet allocator (VoiceLink_InitPacketPool and friends): a free list of
 * fixed-size packet buffers carved out of the caller's VoiceLinkConfig.packetPool. */
#define LINK_PACKET_SIZE     0x478 /* bytes in one link packet buffer */
#define LINK_PACKET_POOL_MIN 4     /* fewest packets the pool may hold */
#define LINK_PACKET_POOL_MAX 0x48  /* most packets the pool may hold */

typedef struct LinkPacketPool {
    s32   intrState; /* +0x00: saved interrupt state around a list change */
    void *freeList;  /* +0x04: head of the free list */
    void *base;      /* +0x08: start of the pool's buffer */
} LinkPacketPool;

typedef struct VoiceLinkContext {
    s32 valid;                       /* +0x00: nonzero while the context is in use */
    u8  peerId;                      /* +0x04: player id of the peer */
    u8  packetPeerId;                /* +0x05: peer id of the packet being answered */
    u8  pad06[2];
    u32 peerMask;                    /* +0x08: peers this exchange covers */
    s32 step;                        /* +0x0C: row of the protocol sequence table */
    u32 pad10;                       /* +0x10 */
    struct VoiceLinkContext *next;   /* +0x14: free/active list link */
} VoiceLinkContext;                  /* 0x18 bytes */

/* What starts a voice-chat link (VoiceLink_Init): the caller's context and
 * packet pools plus the connection kind and the link layer's callback. */
typedef struct VoiceLinkConfig {
    VoiceLinkContext *contextPool; /* +0x00: VOICE_LINK_CONTEXT_MAX contexts, 0x18 bytes each */
    u32 contextCount;              /* +0x04: contexts in the pool (1..VOICE_LINK_CONTEXT_MAX) */
    s32 kind;                      /* +0x08: connection kind (1..3) */
    u8  localId;                   /* +0x0C: local player id (below 0x20) */
    u8  pad0D[3];
    void *packetPool;              /* +0x10: packet buffers, 0x478 bytes each */
    u32 packetPoolSize;            /* +0x14: size of the packet pool in bytes */
    void *callback;                /* +0x18: link layer's packet callback */
    void *callbackArg;             /* +0x1C: argument for that callback */
} VoiceLinkConfig;                 /* 0x20 bytes */

/* The ov010 voice-chat link object (gVoiceChatLink): the streamed-voice work
 * buffer whose refill callback serves the link, the exchange context currently
 * attached to it, and the link's own configuration. */
typedef struct VoiceChatLink {
    u8 *streamBuffer;              /* +0x00: streamed-voice work buffer */
    VoiceLinkContext *context;     /* +0x04: exchange context in use, or NULL */
    VoiceLinkConfig config;        /* +0x08: link configuration (also data_ov010_0222ee78) */
} VoiceChatLink;                   /* 0x28 bytes */
#define VOICE_CHAT_LINK_CONTEXT 0x04 /* the VoiceChatLink.context field */

typedef struct VoiceLinkState {
    s32 unk00;                       /* +0x00 */
    u32 peerMask;                    /* +0x04: connected peers, one bit each */
    u64 lastActivity;                /* +0x08: GetSystemTick() of the last exchange */
    VoiceLinkContext *freeList;      /* +0x10: idle contexts */
    VoiceLinkContext *activeList;    /* +0x14: contexts in use */
    u64 (*getTick)(void);            /* +0x18 */
    u32 randMul;                     /* +0x1C */
    u32 randAdd;                     /* +0x20 */
    u8  pad24[0x18];
    s32 sessionState;                /* +0x3C: 0 idle, 2 exchange active */
    u8  peerId;                      /* +0x40: peer being served */
    u8  peerFlag;                    /* +0x41 */
    u8  pad42[2];
    u32 peerMask2;                   /* +0x44 */
    s32 substate;                    /* +0x48 */
} VoiceLinkState;

/* The link layer's shared configuration block, gLinkConfig, which the voice-chat
 * code reads beside its own state.  In mode 2 the link talks through the single
 * shared gVoiceLinkContext: VoiceLink_FindContext returns it for every peer and
 * no per-peer context is allocated. */
#define LINK_CONFIG_LOCAL_ID  0x00 /* u8 local player id */
#define LINK_CONFIG_PEER_ID   0x01 /* u8 player id of the peer the link talks to */
#define LINK_CONFIG_NOTIFY    0x04 /* void (*)(u8 peer, s32 event, s32 *context, s32 arg) */
#define LINK_CONFIG_NOTIFY_ARG 0x08 /* s32 argument handed to the notify callback */
#define LINK_CONFIG_CONTROL   0x0C /* s32 nonzero: 0xFF control packets go to the control handler, else the peer handler */
#define LINK_CONFIG_MODE      0x10 /* s32 link mode; 2 = single shared context */

/* LINK_CONFIG_NOTIFY event codes. */
#define LINK_NOTIFY_TIMEOUT 9 /* the active exchange was idle for too long and was dropped */

typedef struct LinkConfig {
    u8  localId;    /* +0x00 */
    u8  peerId;     /* +0x01 */
    u8  pad02[2];
    void (*notify)(u8 peer, s32 event, s32 *context, s32 arg); /* +0x04 */
    s32 notifyArg;  /* +0x08 */
    s32 control;    /* +0x0C */
    s32 mode;       /* +0x10 */
    s32 pad14;      /* +0x14 */
} LinkConfig;       /* 0x18 bytes */

/* Audio data packets use a 12-byte header. The codec size table contains
 * one pair per mode, with a byte for the number of 68-byte units and a byte for the remainder. */
#define VOICE_AUDIO_HEADER_BYTES      12
#define VOICE_CODEC_SIZE_ENTRY_BYTES  2
#define VOICE_CODEC_PAYLOAD_UNIT_BYTES 68

enum {
    VOICE_CODEC_PCM8,
    VOICE_CODEC_MULAW,
    VOICE_CODEC_ADPCM2,
    VOICE_CODEC_ADPCM3,
    VOICE_CODEC_ADPCM4,
    VOICE_CODEC_MODE_COUNT
};

/* Fields of gVoiceChatState. The encoder state starts at gLinkCodecState. */
#define VOICE_CHAT_WIRE_PACKET_BYTES 0x0C /* s32 bytes including the audio header */
#define VOICE_CHAT_ADPCM_PREDICTOR   0x10 /* s16 predicted sample */
#define VOICE_CHAT_ADPCM_STEP_INDEX  0x12 /* u8 index into gAdpcmStepTable */
#define VOICE_CHAT_CODEC_MODE        0x1C /* s32 VOICE_CODEC_* */
#define VOICE_CHAT_STREAM_TICK       0x00 /* u16 stream tick taken when the stream starts */
#define VOICE_CHAT_CONTEXT_MASK      0x04 /* u32 mask of the attached contexts' peers */
#define VOICE_CHAT_ACTIVE            0x14 /* s32 nonzero once the voice stream runs */
#define VOICE_CHAT_CONTEXT_COUNT     0x20 /* s32 voice-exchange contexts attached (0..VOICE_CHAT_CONTEXT_MAX) */
#define VOICE_CHAT_CONTEXT_MAX       3    /* contexts the chat tracks at once, one per link channel */
#define VOICE_CHAT_STREAM_STATS      0xF00 /* s32[6] stream statistics cleared when the stream starts */

/* The ov010 voice-chat service state (gVoiceChatSession): the session the voice
 * stream runs in, apart from the codec state above and the link's own state. */
#define VOICE_CHAT_SESSION_TICK        0x00 /* u32 frames since the service started */
#define VOICE_CHAT_SESSION_ACTIVE      0x08 /* s32 1 while a voice-chat session runs */
#define VOICE_CHAT_SESSION_LOCAL_ID    0x0C /* u8 this console's player id */
#define VOICE_CHAT_SESSION_STREAM_CB   0x10 /* void (*)(u8 peer, s32 left, s32 right, s32 arg): decoded audio */
#define VOICE_CHAT_SESSION_STREAM_ARG  0x14 /* s32 argument handed to that callback */
#define VOICE_CHAT_SESSION_PAD18       0x18 /* s32 cleared when the session starts */
#define VOICE_CHAT_SESSION_KIND        0x1C /* s32 connection kind (1..3), 0 once the session ends */

/* The ov010 voice-activity detector's state (gVoiceActivityState, 16 bytes),
 * which marks the start and end of the local player's voice bursts so the chat
 * can send speech instead of silence: a payload whose root energy is at least
 * twice the running average starts a burst, and a burst ends after too many
 * payloads stay under the burst's threshold. */
#define VOICE_ACTIVITY_SPEAKING      0x00 /* s32 nonzero while a voice burst is under way */
#define VOICE_ACTIVITY_LEVEL         0x04 /* s32 last payload's root energy >> 8 */
#define VOICE_ACTIVITY_SILENCE_LIMIT 0x08 /* s32 silent payloads after which a burst ends */
#define VOICE_ACTIVITY_WINDOW_BYTES  0x0C /* s32 SILENCE_LIMIT * VOICE_CODEC_PAYLOAD_UNIT_BYTES */
#define VOICE_ACTIVITY_SILENCE_UNITS 15   /* silent payloads tolerated in a burst: a packet's 16 units less one */
#define VOICE_ACTIVITY_STATE_SIZE    0x10 /* bytes of gVoiceActivityState, the size a state snapshot copies */

/* The 4-byte ADPCM codec header at the start of a voice audio packet, which is
 * also the codec's state: the predictor, the step-table index and a zero byte. */
#define VOICE_ADPCM_PREDICTOR   0x00 /* s16 predicted sample */
#define VOICE_ADPCM_STEP_INDEX  0x02 /* u8 index into gAdpcmStepTable */
#define VOICE_ADPCM_RESERVED    0x03 /* u8 always 0 */

/* Header of a voice-chat link packet (magic 0x5F564354). */
#define VOICE_LINK_PACKET_SIZE 0x10 /* bytes in every voice-link packet and in its header */
#define VOICE_LINK_PACKET_MAGIC 0x5F564354 /* first field of every voice-link packet header */
typedef struct VoiceLinkPacket {
    u32 magic;      /* +0x00: VOICE_LINK_PACKET_MAGIC */
    u8  kind;       /* +0x04: packet kind, 0/0xFF are control packets */
    u8  headerSize; /* +0x05: 16 */
    u8  subtype;    /* +0x06: handshake step within the kind */
    u8  pad07;
    u8  sender;     /* +0x08: player id that sent the packet */
    u8  target;     /* +0x09: player id it is for */
    u8  flag;       /* +0x0A */
    u8  peerId;     /* +0x0B */
    u32 sequence;   /* +0x0C */
} VoiceLinkPacket;  /* 0x10 bytes */

/* Result of serving one voice-chat link packet: the reply type to send back
 * (0 = no reply) and the context the reply belongs to. */
typedef struct VoiceLinkReply {
    s32 type;                  /* +0x00 reply packet type, 0 = no reply */
    VoiceLinkContext *context; /* +0x04 exchange the reply belongs to */
} VoiceLinkReply;

/* ov001 bitmap-font text subsystem (ov001_02169020.c / ov001_02169E3C.c).
 * Ov001TextState is what the text-drawing entry points take; Ov001Font wraps a
 * parsed NFTR resource; Ov001FontResource is the data Ov001Font.resource points
 * at, with the metrics and the section lists the glyph lookups walk. */
#define OV001_TEXT_ALIGN_CENTER 0x400 /* DrawTextMultiline: centre each line in the block width */
#define OV001_TEXT_ALIGN_RIGHT  0x800 /* DrawTextMultiline: right-align each line in the block width */

/* Text control codes a text-panel string carries: a line ends at 13, or at 10
 * when the line has no 13 (FindTextControlCode steps over every code below 32). */
#define TEXT_CODE_LINE_END     13
#define TEXT_CODE_LINE_END_ALT 10
#define TEXT_CODE_LINE_BREAK   4 /* line break, optionally followed by a CR or LF (Text_FindLineBreakEnd) */
#define TEXT_CODE_MSG_SPRITE_COUNT 0x15 /* 3D sprite count the message asks for: operand 0x80/0x81/0x82 selects 0/1/2 (Text_GetScreenCount) */
#define TEXT_CODE_LINE_ALIGN   0x1D /* 2-byte code whose operand's low seven bits hold the line's alignment (Text_GetLineAlignment) */
#define TEXT_CODE_CHOICE_WIDGET     5 /* embeds an interactive two-state choice widget in the text; a plain message box rejects such a text */
#define TEXT_CODE_CHOICE_WIDGET_ALT 6 /* the same widget, its initial selection on the other half */

/* Bytes IsPrintableString accepts in a player name or room text: 0x20 ' ' up to
 * 0x7F; anything below or above is rejected. */
#define TEXT_PRINTABLE_MIN 32
#define TEXT_PRINTABLE_MAX 127

/* Alignment codes carried by a TEXT_CODE_LINE_ALIGN operand; a text panel's
 * per-line kind (Text_GetLineAlignment) picks how each line is drawn. */
#define TEXT_LINE_ALIGN_CENTER 0 /* draw the line centred in the block */
#define TEXT_LINE_ALIGN_LEFT   2 /* draw the line flush left */
#define TEXT_LINE_ALIGN_RIGHT  3 /* draw the line flush right */

/* A measured text line or text block, in pixels. */
typedef struct Ov001TextSize {
    s32 width;  /* +0x00 widest line */
    s32 height; /* +0x04 block height across all lines */
} Ov001TextSize;

/* Anchor flags of the ov001 text-block placement: the horizontal flags move the
 * block along the text direction, the vertical ones across it. */
#define OV001_TEXT_ANCHOR_VCENTER 0x02 /* centre the block across the text direction */
#define OV001_TEXT_ANCHOR_VBOTTOM 0x04 /* put the block's bottom edge at the anchor */
#define OV001_TEXT_ANCHOR_HCENTER 0x10 /* centre the block along the text direction */
#define OV001_TEXT_ANCHOR_HORIZ_BLOCK 0x80  /* unknown anchor flag used by the textured-text draw path */
#define OV001_TEXT_VALIGN_BOTTOM 0x100      /* DrawVerticallyAnchoredText: put the block's end at the anchor */
#define OV001_TEXT_ANCHOR_HRIGHT  0x20 /* put the block's trailing edge at the anchor */

/* A NitroSDK NFTR font file's header and its binary block table.  The header
 * ends with the offset and entry count of the table; each entry carries a
 * four-character block tag and the block's size, which is also the stride to the
 * next entry (FindFontBlock, RelocateFontPointers). */
typedef struct NftrFileHeader {
    u32 signature;  /* +0x00 'RTFN' (0x4E465452) */
    u16 byteOrder;  /* +0x04 */
    u16 version;    /* +0x06 */
    u32 fileSize;   /* +0x08 */
    u16 headerSize; /* +0x0C offset of the block table */
    u16 blockCount; /* +0x0E number of block table entries */
} NftrFileHeader;

typedef struct NftrBlockHeader {
    u32 kind; /* +0x00 block tag: 'FINF', 'CWDH', 'CMAP' or 'CGLP' */
    u32 size; /* +0x04 block size, the stride to the next table entry */
    /* +0x08 block data */
} NftrBlockHeader;

typedef struct Ov001FontResource {
    u8   unk00;         /* +0x00 */
    s8   lineHeight;    /* +0x01: pixels a line advances */
    u16  defaultChar;   /* +0x02: glyph index used for characters not in the font */
    u8   pad04[4];
    u8  *glyphRunTable; /* +0x08: per-glyph rotation/run records */
    void *cwdhList;     /* +0x0C: first CWDH width record (GetFontGlyphMetric) */
    void *cmapList;     /* +0x10: first CMAP record (GetFontGlyphIndex) */
} Ov001FontResource;

typedef struct Ov001Font {
    Ov001FontResource *resource;    /* +0x00 */
    s32 (*decodeChar)(s32 *cursor); /* +0x04: decode the next character of a text stream */
} Ov001Font;

/* One glyph's width record (a CWDH entry, returned by GetFontGlyphMetric). */
typedef struct Ov001GlyphMetric {
    s8  left;    /* +0x00 pixels the glyph starts left of the pen */
    u8  width;   /* +0x01 pixels the glyph covers */
    s8  advance; /* +0x02 pixels the pen advances */
} Ov001GlyphMetric;

/* One CWDH range record of a font resource: the character codes it covers, the
 * next record of the list, and one Ov001GlyphMetric per code of the range.  A
 * glyph no record covers uses the resource's zero metric just past its header. */
typedef struct Ov001CwdhRecord {
    u16 first; /* +0x00 first character code the record covers */
    u16 last;  /* +0x02 last character code the record covers */
    void *next;/* +0x04 next range record, NULL at the end of the list */
    /* +0x08 first of (last - first + 1) 3-byte Ov001GlyphMetric entries */
} Ov001CwdhRecord;

/* One CMAP record of a font resource: the character range it maps, the mapping
 * method and the next record of the list.  The method selects the table that
 * follows at +12: 0 a base glyph index, 1 a u16 glyph table indexed from
 * `first`, 2 sorted (u16 code, u16 glyph) pairs. */
typedef struct Ov001CmapRecord {
    u16 first;  /* +0x00 first character code the record maps */
    u16 last;   /* +0x02 last character code the record maps */
    u16 method; /* +0x04 lookup method (0, 1 or 2) */
    u16 pad06;
    void *next; /* +0x08 next record of the list, NULL at the end */
} Ov001CmapRecord;

/* Returned by the glyph lookups for a character the font does not map. */
#define OV001_GLYPH_NONE 0xffff

/* The pair a glyph draw hands to the panel's ops: the glyph's width record and
 * its bitmap data inside the font's glyph run table. */
typedef struct Ov001Glyph {
    Ov001GlyphMetric *metric; /* +0x00 */
    u8 *bitmap;               /* +0x04 */
} Ov001Glyph;

/* The drawing operations a text panel points at with Ov001TextPanel::ops.  Two
 * tables of them exist: the fixed full-screen panels use gTextOpsLinear (their
 * tile map is a plain row stride), the queued panels gTextOpsPooled (their tile
 * map wraps the surface's tiles). */
typedef struct Ov001TextOps {
    s32 (*drawGlyph)(void *panel, Ov001Font *font, s32 x, s32 y, s32 color, Ov001Glyph *glyph); /* +0x00 */
    void (*clear)(void *panel, s32 arg); /* +0x04 clear the text (TextPanel_ClearText) */
    void (*fillRect)(void *panel, s32 color, s32 x, s32 y, s32 width, s32 height); /* +0x08 fill a rectangle of the surface */
} Ov001TextOps;

/* A text panel: the bitmap surface (CreateTextPanel) text is drawn into.
 * CreatePooledTextPanel hands out 0x30-byte panels from the context's queue and
 * fills in the size and tile fields; the fixed full-screen panels reuse +0x2C
 * as their refresh task handle and keep their surface size in surfaceWidth and
 * surfaceHeight instead. */
typedef struct Ov001TextPanel {
    void *tileBase;    /* +0x00 tile buffer the drawing ops write into */
    s32 surfaceWidth;  /* +0x04 width of the bitmap surface in tiles */
    s32 surfaceHeight; /* +0x08 height of the bitmap surface in tiles */
    u8  depth;         /* +0x0C bits per pixel (4 or 8) */
    u8  pad0D[3];
    s32 tileMap;       /* +0x10 tile map of the surface: tiles per row (linear ops) or the packed x/y wrap shifts (pooled ops) */
    Ov001TextOps *ops; /* +0x14 drawing operations */
    void *self;        /* +0x18 the panel object itself, target of text drawing */
    Ov001Font *font;   /* +0x1C font/glyph set decoding the panel's text */
    s32 unk20;         /* +0x20 */
    s32 unk24;         /* +0x24 */
    void *tiles;       /* +0x28 allocated tile range (queued panels) or heap tile buffer (fixed panels) */
    u16 tileCount;     /* +0x2C tiles allocated in the range (queued panels) */
    u8  width;         /* +0x2E panel width in tiles */
    u8  height;        /* +0x2F panel height in tiles */
} Ov001TextPanel;      /* queued panels are 0x30 bytes */

/* The map action popup object (the repair/refill/level-up sprite created by
 * func_020c98d8): it briefly zooms from double size down to normal while drawing
 * its 3D sprite, then waits out a timer (or a button press) and deletes itself. */
#define MAP_ACTION_X       0x34 /* s32 pixel x of the popup */
#define MAP_ACTION_Y       0x38 /* s32 pixel y of the popup */
#define MAP_ACTION_TILE_X  0x3c /* s32 tile x the action happens on */
#define MAP_ACTION_TILE_Y  0x40 /* s32 tile y the action happens on */
#define MAP_ACTION_MODE    0x44 /* s32 PlayMapActionSound mode (0..2, sounds 0x81/0xE4) */
#define MAP_ACTION_FRAME   0x48 /* s32 sprite animation frame */
#define MAP_ACTION_TIMER   0x4c /* s32 frames left before the popup may end, -1 while zooming */
#define MAP_ACTION_SCALE   0x50 /* s32 zoom in 8.8 fixed point, eases from 0x200 to 0x100 */
#define MAP_ACTION_SPRITE  0x54 /* void *3D sprite the popup draws */
#define MAP_ACTION_HOLD    0x1e /* frames the popup stays at normal size before it may end */

/* The ov001 text/sprite context (gOv001TextContext, a 0x680-byte allocation). */
#define OV001_CTX_FONTS              0x00  /* Ov001Font[2]: the parsed font sets */
#define OV001_CTX_PANEL0_TILE_BUFFER 0x638 /* panel 0's cached tile image */
#define OV001_CTX_PANEL1_TILE_BUFFER 0x668 /* panel 1's cached tile image */
#define OV001_CTX_PANEL_UPLOAD_FLAGS 0x67C /* one pending-upload byte per panel */
#define OV001_CTX_PANEL_QUEUE        0x670 /* ring queue of the 32 text-panel objects CreatePooledTextPanel hands out */
/* A fixed-entry ring queue (Ov001_QueueCreate, Ov001_QueuePush/Pop):
 * u16 capacity, then the read and write indices, then the entries. */
#define OV001_QUEUE_CAPACITY 0x00 /* u16 number of entries the ring holds */
#define OV001_QUEUE_READ     0x02 /* u8 index of the entry QueuePop takes next */
#define OV001_QUEUE_WRITE    0x03 /* u8 index of the entry QueuePush writes next */
#define OV001_QUEUE_ENTRIES  0x04 /* s32[] entries, OV001_QUEUE_CAPACITY of them */
#define OV001_CTX_SIZE               0x680 /* bytes of the text context allocation */
#define OV001_CTX_PANEL_BUFFER       0x010 /* first of the 32 pooled text panels */
#define OV001_CTX_SCREEN_PANELS      0x610 /* Ov001TextPanel[2]: the fixed full-screen panels (index 0 main, 1 sub), 0x30 bytes each, whose tile buffers live in the context */
#define OV001_PANEL_REFRESH_TASK     0x2C  /* fixed panels: s32 tile-refresh task handle (a queued panel stores its u16 tileCount there instead) */
#define OV001_PANEL0_VRAM_BYTES      0x6000 /* character VRAM bytes cleared for screen 0's panel */
#define OV001_PANEL1_VRAM_BYTES      0x3000 /* character VRAM bytes cleared for screen 1's panel */
#define OV001_TEXT_PANEL_COUNT       32    /* pooled panels CreatePooledTextPanel may hand out */
#define OV001_TEXT_PANEL_SIZE        0x30  /* bytes per pooled text panel */
#define OV001_CTX_FONT_FILES         0x674 /* s32[2]: file handles of the two loaded font sets */

typedef struct Ov001TextState {
    void       *panel;         /* +0x00: text panel whose ops blit one glyph */
    Ov001Font  *font;          /* +0x04 */
    s32         letterSpacing; /* +0x08: extra pixels added after each glyph */
    s32         lineSpacing;   /* +0x0C: extra pixels between lines */
} Ov001TextState;              /* 0x10 bytes */

typedef struct Ov001RangeNode {
    struct Ov001RangeNode *prev; /* +0x00 */
    struct Ov001RangeNode *next; /* +0x04 */
    u16 start;                   /* +0x08 first word of the range */
    u16 size;                    /* +0x0A length in words */
} Ov001RangeNode;

typedef struct Ov001TilePool {
    u8 nodes[0x180];     /* +0x000 storage of the 32 range nodes the queue hands out */
    Ov001RangeNode head; /* +0x180 sentinel before the first used range */
    Ov001RangeNode tail; /* +0x18C sentinel after the last used range */
    s32 usedList;        /* +0x198 list of the ranges in use (head and tail are its sentinels) */
    s32 freeNodes;       /* +0x19C queue of the unused range nodes */
} Ov001TilePool;         /* 0x1A0 bytes */

#define OV001_TILE_POOL_COUNT      2
#define OV001_TILE_POOL_STRIDE     0x1A0 /* bytes per pool */
#define OV001_TILE_POOL_NODE_COUNT 32 /* range nodes available per pool (0x180 bytes / 12) */
#define OV001_TILE_POOL_HEAD       0x180 /* Ov001RangeNode: sentinel before the first used range */
#define OV001_TILE_POOL_TAIL       0x18C /* Ov001RangeNode: sentinel after the last used range */
#define OV001_TILE_POOL_HEAD_START 0x188 /* u16 head.start: first range word in use */
#define OV001_TILE_POOL_TAIL_START 0x194 /* u16 tail.start: one past the last free range word */
#define OV001_TILE_POOL_USED_LIST  0x198 /* s32 list of the ranges in use */
#define OV001_TILE_POOL_FREE_NODES 0x19C /* s32 queue of the free range nodes */
#define OV001_TILE_POOL_FREE_START 0x300 /* first free range word of a fresh pool */
#define OV001_TILE_POOL_FREE_END   0x400 /* one past its last free range word */

/* The ov001 sprite-object arena (gOv001SpriteArena): 0x400 bytes of 8-byte OAM
 * entries per screen, then the free-object queues that hand out 0x40 of those
 * entries per screen, then the id of the task that copies the arena to the
 * hardware OAM of both screens. */
#define OV001_SPRITE_OBJ_ARENA_SIZE   0x80c /* bytes Ov001_Alloc gives the arena */
#define OV001_SPRITE_OBJ_BUFFER       0x800 /* bytes of the two screens' OAM entries */
#define OV001_SPRITE_OBJS_PER_SCREEN  0x400 /* bytes from one screen's entries to the next */
#define OV001_SPRITE_OBJ_COUNT        0x40  /* free 8-byte entries per screen */
#define OV001_SPRITE_OBJ_STRIDE       0x08  /* bytes per OAM entry */
#define OV001_SPRITE_OBJ_FREE_QUEUES  0x800 /* s32[2]: free-object queues, one per screen */
#define OV001_SPRITE_OBJ_TASK         0x808 /* s32: id of the OAM flush task */
#define OV001_SPRITE_OBJ_TASK_PERIOD  200   /* flush task period (Ov001_AddTask) */

/* The Nintendo WFC web request state (gWebRequestState), used by the put.asp and
 * get.asp request builders in main_02046D38/main_02047B84.  The request text is
 * formatted into a heap buffer at WEB_REQ_BUFFER and its body is base64-encoded
 * in place by EncodeWfcRequestBody. */
#define WEB_REQ_PHASE        0x04 /* s32 request state-machine step */
#define WEB_REQ_RESULT       0x08 /* s32 ghttp result of the last request */
#define WEB_REQ_READY        0x0C /* s32 nonzero once the request API may be used */
#define WEB_REQ_PRNG_MUL     0x44 /* s32 LCG multiplier for the body obfuscation */
#define WEB_REQ_PRNG_ADD     0x48 /* s32 LCG increment */
#define WEB_REQ_PRNG_MOD     0x4C /* s32 LCG modulus */
#define WEB_REQ_CHECK_KEY    0x50 /* u32 key XORed into the body's byte-sum checksum */
#define WEB_REQ_BUFFER       0x54 /* char * formatted request buffer */
#define WEB_REQ_HASH_POS     0x58 /* char * position of the hash in the buffer */
#define WEB_REQ_DATA_POS     0x5C /* char * position where the base64 body starts */
#define WEB_REQ_PAYLOAD      0x60 /* void * payload of the last request */
#define WEB_REQ_PAYLOAD_SIZE 0x64 /* s32 its size in bytes */

/* Base64: every BASE64_GROUP_BYTES input bytes become BASE64_GROUP_CHARS
 * characters, and a final partial group is padded to a whole one. */
#define BASE64_GROUP_BYTES 3
#define BASE64_GROUP_CHARS 4

/* Phases of the WFC web request state machine (gWebRequestState's WEB_REQ_PHASE,
 * stepped by AdvanceWebRequest): build the put.asp request, send it and wait for
 * its reply, send the follow-up get.asp request carrying that reply's hash, wait
 * for that reply, then the exchange is done. */
enum {
    WEB_REQ_FAILED     = 1, /* the exchange failed; the transaction reports failure */
    WEB_REQ_IDLE       = 2, /* reset, no exchange in flight */
    WEB_REQ_REGISTERED = 3, /* request registered, the put.asp body is being built */
    WEB_REQ_PUT_SEND   = 4, /* the put.asp request is ready to send */
    WEB_REQ_PUT_WAIT   = 5, /* put.asp sent, waiting for its reply */
    WEB_REQ_GET_SEND   = 6, /* the follow-up get.asp request is ready to send */
    WEB_REQ_GET_WAIT   = 7, /* follow-up sent, waiting for its reply */
    WEB_REQ_DONE       = 8  /* the exchange completed */
};

/* GetWebResponseHeader (src/auto/main_02044E04.c) reports the received response
 * as three words: these are their indices. */
#define WEB_RESPONSE_SIZE    0 /* body size in bytes */
#define WEB_RESPONSE_STATUS  1 /* server result code, 1 = player records follow */
#define WEB_RESPONSE_RECORDS 2 /* body+4: first word is the record count, the records start at +8 */
/* Words of the record array WEB_RESPONSE_RECORDS points at (the records themselves
 * start after both of them). */
#define WEB_RESPONSE_COUNT   0 /* number of player records in the reply */
#define WEB_RESPONSE_ONLINE  1 /* players online on the whole server */

/* Status the get.asp accessors return when the reply carries no player data. */
#define WEB_STATUS_NO_DATA   15

/* ov007 CO-power panel object (returned by GetPanelObject).  The panel keeps a
 * flag per graphic variant and three values that the opening/closing animation
 * eases between 0 and 256; the rest of the object is a set of sprite handles. */
#define OV007_PANEL_VARIANT_A 0x34 /* u8: first panel variant in use */
#define OV007_PANEL_VARIANT_B 0x35 /* u8: second panel variant in use */
#define OV007_PANEL_ANIM0     0x3c /* u16: first eased value, 0..256 */
#define OV007_PANEL_ANIM1     0x3e /* u16: second eased value, 0..256 */
#define OV007_PANEL_ANIM2     0x40 /* u16: split-region eased value, 0..256 */
#define OV007_PANEL_ANIM_FRAME 0x54 /* s16: frame counter of a panel animation driver object */
#define OV007_PANEL_ANIM_VALUE 0x5c /* s32: value a panel animation step applies (the colour the panel cursor picked) */
#define OV007_PANEL_ROW0      0x44 /* void *first of the panel's three row sprite actors */
#define OV007_PANEL_ROW1      0x48 /* void *second row sprite actor */
#define OV007_PANEL_ROW2      0x4c /* void *third row sprite actor */
#define OV007_PANEL_SPRITE_A  0x50 /* void *one of the panel's two sprites */
#define OV007_PANEL_SPRITE_B  0x54 /* void *the panel's other sprite */

/* A number/text sprite. DrawTextSprite (main_020A94FC) draws it as a row of glyph
 * sprites and SetTextSpriteValue (main_020A86F8) fills in its numeric form. */
#define TEXT_SPRITE_TYPE    0x04 /* u8: 0 = number sprite, 1 = text sprite */
#define TEXT_SPRITE_ANCHOR_X 0x06 /* s16: x the glyph run is aligned on; the +0x20 layout bits pick left/centre/right */
#define TEXT_SPRITE_Y       0x08 /* s16: screen y of the glyph run */
#define TEXT_SPRITE_PALETTE 0x21 /* u8: OBJ palette row of the glyphs, low nibble */
#define TEXT_SPRITE_COUNT   0x0A /* u8: number of digit glyphs to draw */
#define TEXT_SPRITE_DIGITS  0x0B /* u8[6]: digit glyph indices, least significant first */
#define TEXT_SPRITE_W       0x14 /* u8: glyph cell width in pixels */
#define TEXT_SPRITE_H       0x15 /* u8: glyph cell height in pixels */
#define TEXT_SPRITE_TILE_STEP 0x16 /* u8: tiles one glyph advances the tile index */
#define TEXT_SPRITE_ADVANCE 0x17 /* u8: pixels the pen advances per glyph */
#define TEXT_SPRITE_GLYPH_H 0x18 /* u8: glyph height in pixels */
#define TEXT_SPRITE_VALUE   0x1C /* s32: numeric value, clamped to +/-999999 */
#define TEXT_SPRITE_DESC    0x24 /* void *sprite descriptor used for each glyph */

/* A text layer sprite (CreateTextLayer, CreateTextLayerChild and the
 * RenderTextLayer family in main_02088FF4): a 3D-sprite object that owns the
 * text it draws plus two small render buffers. */
#define TEXT_LAYER_PANEL_STATE        0x58 /* u32 packed panel state */
#define TEXT_LAYER_LEFT_ICON          0x5C /* void * child sprite */
#define TEXT_LAYER_RIGHT_ICON         0x60 /* void * child sprite */
#define TEXT_LAYER_STRING    0x64 /* char *owned accumulated text */
#define TEXT_LAYER_BUFFER_A  0x68 /* void *8-byte render buffer */
#define TEXT_LAYER_BUFFER_B  0x6C /* void *8-byte render buffer */
#define TEXT_LAYER_TEXT_DATA 0x70 /* void *text the sprite currently draws */

/* A text-layer panel proxy (class gTextLayerPanelProxyClass, created by
 * CreateTextLayerPanelProxy): a stand-in sprite that redraws the text panel it
 * stands for whenever the proxy itself is drawn. */
#define TEXT_LAYER_PANEL_PROXY_PANEL 0x34 /* s32 the text panel the proxy redraws */

#define TEXT_LAYER_PANEL_KIND_MASK      0x00000007u /* panel kind in bits 0..2 */
#define TEXT_LAYER_PANEL_KIND_TEXT      1 /* text panel that any A/B press dismisses (2 is the same) */
#define TEXT_LAYER_PANEL_SAVED_MODE_SHIFT 29 /* saved mode is restored from bits 29..31 */
#define TEXT_LAYER_PANEL_ANIMATION_MASK 0x00000038u
#define TEXT_LAYER_PANEL_CHOICE_MASK    0x000000C0u
#define TEXT_LAYER_PANEL_POSITION_MASK  0x00000300u /* center, top or bottom */
#define TEXT_LAYER_PANEL_WINDOW_MASK    0x00000400u /* configure the screen window */
#define TEXT_LAYER_PANEL_HIDDEN         0x00000800u /* the panel is drawn but not shown */
#define TEXT_LAYER_PANEL_NESTED         0x00002000u /* another text layer already existed */
#define TEXT_LAYER_PANEL_ICON_COUNT     0x00038000u
#define TEXT_LAYER_PANEL_LINE_COUNT     0x003C0000u
#define TEXT_LAYER_PANEL_REFRESH_TIMER  0x1FC00000u
#define TEXT_LAYER_PANEL_SAVED_MODE     0xE0000000u
#define TEXT_LAYER_PANEL_LINK_SOUND     0x00004000u /* the panel queued its link-session sound on slot 0 */

/* The window open/close animation the panel sprites play (the open and close
 * starters in main_0208ABC4): the mode byte at +0x48 holds the direction in
 * bits 4..5, +0x4A the frames it runs and +0x4B its frame counter. */
#define TEXT_LAYER_PANEL_MODE       0x48 /* u8 open/close mode and display bits */
#define TEXT_LAYER_PANEL_MODE_MASK  0x30
#define TEXT_LAYER_PANEL_MODE_OPEN  0x10
#define TEXT_LAYER_PANEL_MODE_CLOSE 0x20
#define TEXT_LAYER_PANEL_FRAMES     0x4A /* s8 frames the animation runs */
#define TEXT_LAYER_PANEL_FRAME      0x4B /* s8 frame counter */
#define TEXT_LAYER_PANEL_ANIM_OPEN  0x08 /* TEXT_LAYER_PANEL_STATE animation mode */
#define TEXT_LAYER_PANEL_ANIM_CLOSE 0x18

/* TEXT_LAYER_PANEL_STATE bits 0..2 are the panel kind the layer was rendered as
 * (1/2 is a text panel that any A/B press dismisses, 3 a two-option panel); bits
 * 6..7 are its selected choice (0 = left/accept, 1 = right/cancel). */

/* The ov011 opening-sequence state object, advanced by the ov011_02223CB8 code. */
#define INTRO_TIMER     0x34 /* u16 frames spent in the current state */
#define INTRO_SUBSTATE  0x36 /* u8 sub-state flag */
#define INTRO_ANIM      0x37 /* u8 sprite animation currently playing */
#define INTRO_STATE     0x38 /* u8 1 = opening, 2 = title, 3 = stage sequence */
#define INTRO_STAGE     0x39 /* u8 index into gIntroStateDurations */
#define INTRO_MODE      0x3C /* s32 presentation mode; 2 selects the alternate path */

/* ARM7/ARM9 IPC FIFO: the message word and the status register the game's FIFO
 * code (main_02008EF0, main_02009EB0) polls.  A word carries the index of the
 * handler that receives it, a payload, and a request/reply bit. */
#define REG_IPC_FIFO_CR   0x04000184 /* u16 control/status */
#define REG_IPC_FIFO_SEND 0x04000188 /* u32 write the next outgoing message */
#define REG_IPC_FIFO_RECV 0x04100000 /* u32 read the next incoming message */
#define IPC_FIFO_SEND_FULL  0x0002 /* send FIFO full, no message can be posted */
#define IPC_FIFO_RECV_EMPTY 0x0100 /* no message waiting in the receive FIFO */
#define IPC_FIFO_ERROR      0x4000 /* FIFO error; write IPC_FIFO_CLEAR to recover */
#define IPC_FIFO_CLEAR      0xc000 /* clear the error and re-enable the FIFO */

/* TIMER0, the free-running hardware counter the system tick is built on, and the
 * interrupt register that reports its overflow (main_02006F14).  TIMER1 is the
 * OS timer's hardware countdown: its countdown register arms the next timer and
 * its interrupt runs the queue. */
#define REG_TM0D     0x04000100 /* u16 TIMER0 counter, counted up by the timer hardware */
#define REG_TM0CNT   0x04000102 /* u16 TIMER0 control; 0xC1 = enabled with an overflow interrupt */
#define REG_TM1D     0x04000104 /* u16 TIMER1 countdown, armed by ArmTimerCountdown */
#define REG_TM1CNT   0x04000106 /* u16 TIMER1 control; 0xC1 = enabled with an overflow interrupt */
/* ARM9 external memory control: which processor arbitrates cartridge ROM/SPI,
 * main RAM and VRAM accesses.  The multiboot cartridge reader saves and restores
 * the RAM and VRAM fields around its cartridge-header reads. */
#define REG_EXMEMCNT          0x04000204 /* u16 */
#define EXMEMCNT_RAM_MASK     0x000C     /* bits 2-3: ARM7/ARM9 main-RAM priority and access */
#define EXMEMCNT_VRAM_PRIORITY 0x0010    /* bit 4: ARM7/ARM9 VRAM priority */
#define REG_IE       0x04000210 /* u32 interrupt enable mask */
#define REG_IF       0x04000214 /* u32 interrupt flags */
#define IRQ_VBLANK   0x0001     /* REG_IE/REG_IF bit 0: VBlank */
#define IRQ_HBLANK   0x0002     /* REG_IE/REG_IF bit 1: HBlank */
#define IRQ_TIMER0   0x0008     /* REG_IF bit set when TIMER0 overflows */
#define IRQ_TIMER1   0x0010     /* REG_IF bit set when TIMER1 overflows (the OS timer) */
#define IRQ_VCOUNT   0x0004     /* REG_IE/REG_IF bit 2: VCount (scanline) match */
#define TIMER0_HALF  0x8000     /* top bit of the 16-bit counter */

/* The ARM9 square-root hardware (ARM946E-S coprocessor): writing the operand
 * starts the operation and the result is ready once the control register's busy
 * bit clears.  The game uses it for the map-view distance scaling. */
#define REG_SQRTCNT      0x040002B0 /* u16 control; bit 15 is set while a root is computed */
#define REG_SQRT_RESULT  0x040002B4 /* s32 result, valid once the busy bit is clear */
#define REG_SQRT_PARAM   0x040002B8 /* s32 operand the root is taken of */
#define SQRTCNT_BUSY     0x8000     /* REG_SQRTCNT bit 15: the square root is still running */

/* The ARM9 IRQ handler table: one handler per IRQ bit (the timers are IRQ 3-6,
 * the DMA channels 8-11, IPC receive 18).  The table is the first words of the
 * OS work area (gOsArea) and its entries are called with no argument by the
 * dispatcher func_01ff8000.  The four timers and the four DMA channels share one
 * IRQ line each, so they have an IrqHandler entry per channel instead; those
 * entries follow each other in hardware order: DMA0-3, then TIMER0-3
 * (OS_SetIrqHandler, OS_GetIrqHandler, OS_SetDmaHandler in main_02004FF8). */
#define IRQ_COUNT          22 /* the dispatcher handles IRQ bits 0..21 */
#define IRQ_NUMBER_TIMER0  3
#define IRQ_NUMBER_TIMER3  6
#define IRQ_NUMBER_DMA0    8
#define IRQ_NUMBER_DMA3    11
#define IRQ_HANDLER_DMA_COUNT 4 /* DMA entries before the timer entries */

typedef struct IrqHandler {
    s32 handler; /* +0x00 function the IRQ dispatcher calls with arg */
    s32 ieMask;  /* +0x04 IE bit the channel was set up with; 1 when the handler manages its own IRQ */
    s32 arg;     /* +0x08 argument the handler is called with */
} IrqHandler;    /* 0x0C */

/* Event word near the end of the OS work area: one bit per IRQ line that an
 * interrupt handler signals and a thread waits on.  Bit 0 is the VBlank event:
 * the VBlank handler sets it and the main loop's frame wait consumes it; bit 4
 * is TIMER1, set by the OS timer interrupt. */
#define OS_AREA_EVENT_FLAGS 0x3FF8 /* u32 */
#define OS_EVENT_VBLANK     0x0001 /* IRQ 0 */
#define OS_EVENT_TIMER1     0x0010 /* IRQ 4, the OS timer */

/* The game's event flags (SetEventFlag/IsEventFlagSet, main_02086208) are three
 * separate bit blocks picked by the flag id: ids 0..0x1F in the low block,
 * 0x20..0x5F in the mid block and 0x60..0x9F in the high block; other ids are
 * ignored. */
#define EVENT_FLAG_LOW_BASE   0x00 /* ..0x1F: gEventFlagsLow */
#define EVENT_FLAG_LOW_BYTES  4    /* bytes in gEventFlagsLow (32 flags) */
#define EVENT_FLAG_MID_BASE   0x20 /* ..0x5F: gEventFlagsMid */
#define EVENT_FLAG_HIGH_BASE  0x60 /* ..0x9F: gEventFlagsHigh */
#define EVENT_FLAG_COUNT      0xA0 /* total flag ids (0..0x9F) */

/* The system tick state: TIMER0's 16-bit counter extended to 64 bits by counting
 * the overflows at SYSTEM_TICK_OVERFLOW.  Addressed by offset (its symbol is
 * declared as a u16 by its users). */
typedef struct SystemTickState {
    u16 initialized; /* +0x00 nonzero once TIMER0 has been started */
    u8  pad02[2];    /* +0x02 */
    s32 reload;      /* +0x04 nonzero when TIMER0 has to be reloaded */
    u64 overflows;   /* +0x08 TIMER0 overflows counted so far */
} SystemTickState; /* 0x10 bytes */

#define SYSTEM_TICK_INITIALIZED 0x00 /* u16 nonzero once the timer has been set up */
#define SYSTEM_TICK_RELOAD      0x04 /* s32 nonzero when TIMER0 must be reloaded */
#define SYSTEM_TICK_OVERFLOW    0x08 /* u64 TIMER0 overflows counted so far */

/* The VCount (scanline match) interrupt module's state block, cleared once
 * during its one-time initialisation.  Only the module's initialisation is
 * linked into this build, so the four words after the flag are never read back
 * here. */
typedef struct VCountIrqState {
    u16 initialized;  /* +0x00 nonzero once the module has been set up */
    u8  pad02[2];     /* +0x02 */
    s32 unknown04;    /* +0x04 */
    s32 unknown08;    /* +0x08 */
    s32 unknown0C;    /* +0x0C */
    s32 unknown10;    /* +0x10 */
} VCountIrqState;     /* 0x14 bytes */

/* The DS firmware's user settings ("Personal Data") at 0x027FFC80: version, the
 * favourite colour and birthday, the nickname and personal message with their
 * lengths, and a flags word at the end whose low three bits are the language. */
typedef struct FirmwareUserSettings {
    u16 version;       /* +0x00 */
    u8  favoriteColor; /* +0x02 0..15 */
    u8  birthMonth;    /* +0x03 1..12 */
    u8  birthDay;      /* +0x04 1..31 */
    u8  pad05;         /* +0x05 */
    u16 name[10];      /* +0x06 nickname, UTF-16 */
    u8  nameLength;    /* +0x1a number of nickname characters */
    u8  pad1b;         /* +0x1b */
    u16 message[26];   /* +0x1c personal message, UTF-16 */
    u8  messageLength; /* +0x50 number of message characters */
    u8  pad51[0x13];   /* +0x51..0x63 */
    u16 flags;         /* +0x64 low 3 bits = system language */
} FirmwareUserSettings; /* 0x66 bytes */

/* The game's copy of the firmware user settings, filled by GetSystemUserProfile
 * and read as the local player's profile: language, favourite colour and
 * birthday, then the nickname and personal message with their lengths. */
typedef struct UserProfile {
    u8  language;      /* +0x00 0..7 */
    u8  favoriteColor; /* +0x01 0..15 */
    u8  birthMonth;    /* +0x02 */
    u8  birthDay;      /* +0x03 */
    u16 name[10];      /* +0x04 nickname, UTF-16 */
    u16 pad18;         /* +0x18 cleared */
    u16 nameLength;    /* +0x1a nickname length in characters */
    u16 message[26];   /* +0x1c personal message, UTF-16 */
    u16 pad50;         /* +0x50 cleared */
    u16 messageLength; /* +0x52 personal message length in characters */
} UserProfile; /* 0x54 bytes */

/* The OS timer queue (gTimerQueue): timer nodes sorted by their u64 deadline,
 * the earliest at TIMER_QUEUE_HEAD and the latest at TIMER_QUEUE_TAIL.  A node
 * links toward the head at TIMER_NODE_PREV and toward the tail at
 * TIMER_NODE_NEXT.  A node whose TIMER_NODE_PERIOD is set repeats, counting from
 * the tick it last fired at; the timer interrupt calls its TIMER_NODE_CALLBACK
 * with TIMER_NODE_ARG. */
#define TIMER_QUEUE_READY   0x00 /* u16 nonzero once the queue is set up */
#define TIMER_QUEUE_HEAD    0x04 /* void * node with the earliest deadline */
#define TIMER_QUEUE_TAIL    0x08 /* void * node with the latest deadline */
#define TIMER_NODE_CALLBACK 0x00 /* s32 function the timer interrupt calls, 0 while the node is idle */
#define TIMER_NODE_ARG      0x04 /* s32 argument the callback gets */
#define TIMER_NODE_DEADLINE 0x0c /* u64 system tick the timer is due */
#define TIMER_NODE_PREV     0x14 /* void * node nearer the head */
#define TIMER_NODE_NEXT     0x18 /* void * node nearer the tail */
#define TIMER_NODE_PERIOD   0x1c /* u64 repeat period in ticks, 0 for a one-shot timer */
#define TIMER_NODE_LAST     0x24 /* u64 system tick the timer last fired at */

/* The OS timer queue (gTimerQueue) keeps its armed timers sorted by deadline,
 * the earliest at TIMER_QUEUE_HEAD and the latest at TIMER_QUEUE_TAIL; the
 * TIMER_* offsets describe one timer object. */
#define TIMER_QUEUE_HEAD    0x04 /* void *: timer due first */
#define TIMER_QUEUE_TAIL    0x08 /* void *: timer due last */
#define TIMER_CALLBACK      0x00 /* void (*)(s32): run when the timer is due, 0 once cancelled */
#define TIMER_ARG           0x04 /* s32 argument handed to the callback */
#define TIMER_DEADLINE      0x0C /* u64 GetSystemTick() value the timer is due at */
#define TIMER_PREV          0x14 /* the timer due before this one */
#define TIMER_NEXT          0x18 /* the timer due after this one */
#define TIMER_PERIOD        0x1C /* u64 repeat period, 0 for a one-shot timer */
#define TIMER_LAST_DEADLINE 0x24 /* u64 deadline a periodic timer was last queued at */

typedef struct FifoMessage {
    u32 tag:5;      /* bit 0: handler index, 0 when there is no message */
    u32 reply:1;    /* bit 5: 0 = request, 1 = reply */
    u32 payload:26; /* bits 6..31: message data */
} FifoMessage;

/* The ARM7 system FIFO (tag 14) carries the power driver's messages.  The only
 * one the game handles is the shutdown request, whose payload's low 6 bits are
 * SYSTEM_CMD_SHUTDOWN.  gSystemShutdownState records that shutdown has begun and
 * holds an optional callback consulted before the console is halted (returning
 * 0 vetoes the shutdown, anything else proceeds with it). */
#define SYSTEM_FIFO_TAG        0xE /* IPC FIFO tag of the ARM7 system/power service */
#define SYSTEM_CMD_SHUTDOWN    17  /* payload low 6 bits of the ARM7's shutdown request */
#define SYSTEM_SHUTDOWN_STARTED  0x00 /* s32: nonzero once the shutdown request was handled */
#define SYSTEM_SHUTDOWN_CALLBACK 0x04 /* s32 (*)(void): optional pre-shutdown callback */

/* An ARM7 transfer request is posted on the IPC FIFO as seven words: first the
 * transfer flags (with the fixed bits 0x02004100), then the source,
 * destination and byte size, each as a high and a low 16-bit half.  A word
 * carries its command index at bits 16..22, and the last word also sets bit 24. */
#define ARM7_XFER_FIFO_TAG 9   /* IPC FIFO handler tag of the ARM7 transfer service */
#define ARM7_XFER_WORD(n)  ((u32)(n) << 16) /* command index of a request word */
#define ARM7_XFER_LAST_WORD 0x01000000      /* set on the last word of a request */
#define ARM7_XFER_STOP_WORD 0x03004200      /* the one-word stop request: command index 48, the last-word bit */

/* The ARM7 transfer service's state object (gArm7TransferState).  One request is
 * in flight at a time; Arm7TransferStart keeps the descriptor's user words and the
 * completion callback here, Arm7TransferEnd reuses the busy flag, callback and
 * user for its transfer-end command. */
#define ARM7_XFER_STATE_READY    0x00 /* u16 nonzero once the FIFO handler is installed */
#define ARM7_XFER_STATE_BUSY     0x04 /* s32 1 while a transfer is being started or completed */
#define ARM7_XFER_STATE_CALLBACK 0x08 /* void (*)(s32 result, s32 user) run on completion */
#define ARM7_XFER_STATE_USER     0x0C /* s32 second argument handed to the callback */
#define ARM7_XFER_STATE_RESULT   0x10 /* s32 result of the last completed transfer */
#define ARM7_XFER_STATE_USER1    0x14 /* u32 first user word of the descriptor */
#define ARM7_XFER_STATE_USER2    0x18 /* u32 second user word of the descriptor */
#define ARM7_XFER_STATE_PROGRESS 0x1C /* u16 * where the ARM7's progress word is stored */

/* The ARM9's side of the ARM7 boot handshake (gArm7BootSync, main_02006F14).
 * InitArm7BootSync installs Arm7BootAckHandler on FIFO channel 12 and the
 * ARM7's boot-ready reply (payload 0x10) sets ARM7_BOOT_SYNC_READY; the
 * console-reboot path sends that request and the card-image loader waits for
 * the ready flag before it loads. */
#define ARM7_BOOT_SYNC_FIFO_TAG    0xC /* IPC FIFO tag of the ARM7 boot-sync service */
#define ARM7_BOOT_SYNC_READY       0x00 /* s16 set to 1 by the ARM7's channel-12 boot-ready message */
#define ARM7_BOOT_SYNC_INITIALISED 0x02 /* u16 nonzero once the channel-12 handler was installed */
#define ARM7_BOOT_SYNC_REPLY       0x10 /* command of the ARM7's channel-12 boot-ready message (bits 8..14 of its word) */

/* The ARM7 command service's state object (gArm7CommandState, at 0x0212FCCC).
 * The service talks to the ARM7 power/sound driver through the FIFO and
 * remembers when the LCD was last switched off, so that an immediate re-enable
 * (a bouncing lid or power button) can be debounced. */
#define POWER_SERVICE_LAST_OFF 0x10 /* u32: shared frame counter at the last LCD power-off */
#define ARM7_CMD_FIFO_TAG  8    /* IPC FIFO handler tag of the ARM7 command service */
#define ARM7_CMD_INIT      0x00 /* u16: nonzero once the command service is initialised */
#define ARM7_CMD_BUSY      0x18 /* s32: nonzero while a command is outstanding */
#define ARM7_CMD_CALLBACK  0x1C /* void (*)(s32, s32): called with a command's reply */
#define ARM7_CMD_USER      0x20 /* s32: second argument handed to ARM7_CMD_CALLBACK */
#define ARM7_CMD_VALUE_PTR 0x24 /* s32 *: where the reply to command 0x67 is stored */
#define ARM7_CMD_DONE_NOTIFY 0x04 /* s32: nonzero once the ARM7 answered command 0x60 */
#define ARM7_CMD_DONE_SLEEP  0x08 /* s32: nonzero once the ARM7 answered command 0x62 */
#define ARM7_CMD_SET_POWER   0x63 /* Arm7SetPowerState: switch the ARM7 power state */
#define ARM7_CMD_SET_AMP     0x64 /* command 0x64: set a sound-amplifier parameter */
#define ARM7_CMD_SET_VALUE   0x66 /* command 0x66: set the ARM7's system value (its argument byte) */
#define ARM7_CMD_GET_VALUE   0x67 /* command 0x67: read the ARM7's system value, answered through ARM7_CMD_VALUE_PTR */
#define ARM7_SYSTEM_VALUE_FRONTEND 0xF /* system value overlay 001 keeps the ARM7 at while a front-end screen runs */

/* An ARM7 command is sent as one or two FIFO words: the command word names the
 * command byte and carries an extra argument byte, a command with a 16-bit
 * value sends that as a following argument word. */
#define ARM7_CMD_WORD(cmd, arg) ((u32)0x02000000 | ((u32)(cmd) << 8) | (u8)(arg))
#define ARM7_CMD_ARG_WORD(value) ((u32)0x01010000 | (u16)(value))

#define ARM7_POWER_INVALID   0xFFFF /* Arm7SetBacklight/SendPowerCommand: no matching power state */

/* The FIFO block-transfer state (gFifoBlockTransfer) of the save/profile upload in
 * main_02045D94: the reply to the last FIFO command, whether it arrived, and the
 * ARM7 address the current block is copied to.  Blocks are 0x100 bytes. */
#define FIFO_BLOCK_TAG    4    /* IPC FIFO handler index of the block-transfer service */
#define FIFO_XFER_REPLY   0x00 /* u16 reply value, nonzero = the command failed */
#define FIFO_XFER_DONE    0x04 /* s32 1 once the reply arrived */
#define FIFO_XFER_ADDRESS 0x08 /* s32 ARM7 destination address of the first block */
#define FIFO_BLOCK_SIZE   0x100 /* bytes in one transferred block */
#define FIFO_BLOCK_COUNT  4     /* blocks one transfer holds */
#define FIFO_XFER_FAILED  0xFF  /* reply stored when the ARM7 bounced the command back unhandled */

/* One of the command service's five reply slots (gArm7CommandReplies, 8 bytes
 * each): when reply command 0x70..0x74 arrives its value is stored through
 * dest and written is then set.  gArm7CommandReplySlots holds the five; the
 * dest field of each starts four bytes in (the old data_0212fd10 symbol). */
typedef struct Arm7CommandReplySlot {
    u16 written; /* +0x00 nonzero once the reply value has been stored */
    u16 *dest;   /* +0x04 where to store it, or NULL */
} Arm7CommandReplySlot;

#define ARM7_CMD_REPLY_COUNT 5
#define ARM7_CMD_REPLY_SIZE  8

/* The mic test screen's state object (class descriptor at 0x0212DA88, vtable
 * at 0x0212DBA0, built by the screen's constructor): it measures the
 * microphone's peak level over the last ten windows, averages them into a bar
 * count and animates its sprites accordingly. */
typedef struct MicTestScreen {
    void *vtable;          /* +0x00 the screen's vtable (at 0x0212DBA0) */
    u8 filler_04[0x30];
    void *levelSprite;     /* +0x34 sprite driven by the measured level */
    void *menuSprite;      /* +0x38 mic illustration, updated as a menu sprite */
    u8 flags;              /* +0x3C bit 0: measurement requested, bit 1: measuring */
    u8 pad_3d;
    s16 timer;             /* +0x3E frames left before the next measurement (180) */
    u8 levelIndex;         /* +0x40 slot the next level is written to */
    u8 levels[10];         /* +0x41 last ten peak levels, 0..4 */
} MicTestScreen;           /* 0x4B bytes */

/* The mic test screen's IPC block (at 0x02168FF4): the 32-byte ARM7 microphone
 * sample buffer at +0 and, four bytes in, the ARM7 transfer descriptor that
 * fills it (+4 is the old gMicTestTransferDesc symbol). */
#define MIC_TEST_SAMPLES      0x00 /* u8 *: microphone sample buffer */
#define MIC_TEST_TRANSFER     0x04 /* ARM7 transfer descriptor */
#define MIC_TEST_SAMPLE_COUNT 0x20 /* bytes of samples per transfer */
#define MIC_TEST_LEVEL_COUNT  10   /* levels averaged into the bar count */
#define MIC_TEST_LEVEL_HISTORY 0x41 /* MicTestScreen offset of levels[] */
#define MIC_TEST_FLAG_START   0x01 /* flags bit 0 */
#define MIC_TEST_FLAG_RUNNING 0x02 /* flags bit 1 */
#define MIC_TEST_MAX_BARS     3    /* bars the average level can fill */

/* POWCNT1, whose bit 0 enables the LCD. */
#define REG_POWCNT1        0x04000304 /* u16 */
#define POWCNT1_LCD_ENABLE 0x0001

/* Delay, in CPU cycles, between attempts to bring the LCD back up: the power
 * service refuses to re-enable it within seven frames of switching it off. */
#define LCD_WAKE_DELAY_CYCLES 0x996A00
/* Delay between display-wake attempts while the shell closes the lid. */
#define DISPLAY_WAKE_RETRY_CYCLES 0xA3A47

/* The ARM7/ARM9 shared work area (the shared header and everything the two CPUs
 * share); SHARED_FIFO_TAG_WORD is the s32 index into it whose bit `tag` is set
 * while a handler for that IPC FIFO message tag is registered
 * (SetFifoMessageHandler). */
#define SHARED_WORK_BASE     0x027FFC00
#define SHARED_FIFO_TAG_WORD 226 /* s32 index: bit per handled FIFO tag */
/* The console's six-byte MAC address, copied from the firmware header into the
 * shared work area at boot (GetMacAddress reads it). */
#define SHARED_MAC_ADDRESS   0x027FFCF4
/* Reset parameter kept across a soft reset: the boot code reads it back, so the
 * reboot path bounces a value through it. */
#define SHARED_RESET_PARAMETER 0x027FFC20 /* s32 */

/* Word of the ARM7/ARM9 shared work area that the ARM7 keeps up to date; its
 * top bit is set while the lid is closed. */
#define SHARED_LID_WORD   0x027FFFA8 /* volatile u16 */
#define SHARED_LID_CLOSED 0x8000

/* Frame counter the engine keeps in the shared work area (incremented once per
 * frame, used for parity and short timeouts). */
#define SHARED_FRAME_COUNTER 0x027FFC3C /* volatile u32 */

/* The ROM header is copied to 0x027FFE00 at boot; its game code's last byte
 * (header +0x0F) is the cartridge's region letter, which the WFC match query
 * sends to the server. */
#define ROM_HEADER_GAME_CODE_REGION 0x027FFE0F /* s8: region letter, e.g. 'E' or 'J' */

/* A touch rectangle as the touch API's hit tests take it: the box's two
 * corners, left/top first, each as u16 at these offsets. */
#define RECT_LEFT   0x0 /* u16 x of the left edge */
#define RECT_TOP    0x2 /* u16 y of the top edge */
#define RECT_RIGHT  0x4 /* u16 x of the right edge */
#define RECT_BOTTOM 0x6 /* u16 y of the bottom edge */

/* The ov001 map-list screen's state (gMapListState): the list's pixel scroll
 * position and a pointer to the screen's 0x48-byte object.  That object holds
 * the loaded background tilemaps, the text panel the info rows are drawn in,
 * the seven row/selection sprite slots at +0x18 and, after them, the scroll
 * bar, task handles and button flags. */
#define OV001_MAP_LIST_SCROLL     0x04 /* u16: scroll position in pixels */
#define OV001_MAP_LIST_STATE      0x00 /* u8: screen state index: the list row's screen, or a sub-screen */
#define OV001_MAP_LIST_ROW        0x02 /* u8: selected row within the visible rows */
#define OV001_MAP_LIST_OBJECT     0x08 /* void *: the screen's 0x48-byte object */
#define OV001_MAP_LIST_ROW_HIGHLIGHT 0x04 /* object: u8[4] custom-map highlight countdown, one per visible row */
#define OV001_MAP_LIST_ROW_HEIGHT 29   /* pixels of one list row; five are visible */

/* The ov001 map-preview buffer: gOv001MapPreview is itself a 12-byte block
 * holding the pointer to the allocated preview object, then the source and
 * destination VRAM addresses of the OBJ-tile copy a task is asked to make.  The
 * object holds the 32x24 BG2 tilemap the map preview is drawn into; a task
 * flushes it to BG2 whenever its dirty flag is set. */
typedef struct Ov001MapPreview {
    s32 task;          /* +0x00 id of the task that flushes the tilemap */
    u16 tiles[0x300];  /* +0x04 the 32x24 BG2 tilemap, 0x600 bytes */
    u8  dirty;         /* +0x604 nonzero: the tilemap must be flushed */
} Ov001MapPreview;     /* 0x608 bytes */
#define OV001_MAP_PREVIEW_POINTER     0x00 /* s32 pointer to the allocated Ov001MapPreview object */
#define OV001_MAP_PREVIEW_COPY_SOURCE 0x04 /* s32 VRAM address the staged OBJ-tile copy reads from */
#define OV001_MAP_PREVIEW_COPY_DEST   0x08 /* s32 VRAM address that copy writes to */
#define OV001_MAP_PREVIEW_COPY_WORDS  32   /* 16-bit words the staged OBJ-tile copy moves */
#define OV001_MAP_LIST_BG_TILEMAP 0x08 /* object: s32 loaded list-background tilemap */
#define OV001_MAP_LIST_PALETTE    0x0C /* object: s32 loaded map-list background palette (the step-2 palette file) */
#define OV001_MAP_LIST_TEXT_PANEL 0x14 /* object: s32 text panel for the info rows */
#define OV001_MAP_LIST_OBJ_TILEMAP 0x10 /* object: s32 OBJ tilemap of the row/selection icon tiles */
#define OV001_MAP_LIST_TASK       0x38 /* object: s32 id of the running scroll task, 0 while idle */
#define OV001_MAP_LIST_BG_DIRTY   0x44 /* object: u8 set when the background scroll needs refreshing */
#define OV001_MAP_LIST_BG_DIRTY   0x44 /* object: u8 set when the list background must be scrolled */
#define OV001_MAP_LIST_BG_DIRTY   0x44 /* object: u8 nonzero when the list moved and the background scroll must follow */
#define OV001_MAP_LIST_EMPTY_B    0x43 /* object: u8 cached copy of the record's SAVE_SLOT_EMPTY_B flag */
#define OV001_MAP_LIST_SCROLL_STEP 6   /* pixels the scroll animation moves per step */
#define OV001_MAP_LIST_SCROLL_MAX  145 /* scroll range in pixels */
#define OV001_MAP_LIST_HANDLE_TRAVEL 55 /* pixels the scroll-bar handle travels over the range */
#define OV001_MAP_LIST_NO_TOUCH 14 /* GetMapListTouchedEntry result when no row entry was touched */
#define OV001_MAP_LIST_SAVE_SCREEN_FIRST 11 /* first OV001_MAP_LIST_STATE of the save-slot sub-screens */
#define OV001_MAP_LIST_SAVE_SCREEN_LAST  13 /* last one; their icon tile is gMapListSaveScreenIconTile[state - 11] */

/* The ov001 friend-roster screen's vertical scroll bar (gOv001Scrollbar, a
 * 0x20-byte object built by Ov001_CreateScrollBar): a sprite whose touch
 * rectangles are hit-tested for dragging (handle), paging (track) and the two
 * arrow caps. */
#define OV001_SCROLLBAR_SPRITE     0x00 /* M2C_UNK layout handle of the bar sprite */
#define OV001_SCROLLBAR_TASK       0x0c /* s32 id of the task driving the bar */
#define OV001_SCROLLBAR_X          0x10 /* u16 x of the track */
#define OV001_SCROLLBAR_Y          0x12 /* u16 y of the track */
#define OV001_SCROLLBAR_W          0x14 /* u16 width of the bar, 12 */
#define OV001_SCROLLBAR_H          0x16 /* u16 y the track starts at for touch input */
#define OV001_SCROLLBAR_DRAG_OFFSET 0x18 /* u8 handle offset when the drag started */
#define OV001_SCROLLBAR_TRACK      0x19 /* u8 track length in pixels */
#define OV001_SCROLLBAR_HANDLE_POS 0x1a /* u8 current handle offset in pixels */
#define OV001_SCROLLBAR_KIND       0x1b /* u8 sprite kind: index of the handle length */
#define OV001_SCROLLBAR_STATE      0x1c /* u8 0 idle, 1 dragging, 2/3 bar scroll */
#define OV001_SCROLLBAR_EVENT      0x1d /* u8 event code the update task reports */
#define OV001_SCROLLBAR_BLOCKED    0x1e /* u8 nonzero while the task must leave it alone */

/* Parts of the scroll bar a touch rectangle can describe, in hit-test order. */
enum {
    OV001_SCROLLBAR_PART_HANDLE = 1, /* the draggable handle */
    OV001_SCROLLBAR_PART_UP     = 2, /* the cap just above the track */
    OV001_SCROLLBAR_PART_DOWN   = 3, /* the cap just below the track */
    OV001_SCROLLBAR_PART_TRACK  = 4  /* the track itself, page by a touch */
};

/* The event code the scroll bar's task reports each frame in
 * OV001_SCROLLBAR_EVENT (0 when nothing happened).  GetMenuState returns it and
 * the owning list's state machine switches on it: 4/6 start a cap scroll, 5/7
 * are their releases. */
enum {
    OV001_SCROLLBAR_EVENT_NONE           = 0,
    OV001_SCROLLBAR_EVENT_HANDLE_DOWN    = 1, /* the handle was grabbed */
    OV001_SCROLLBAR_EVENT_HANDLE_DRAG    = 2, /* the handle is being dragged */
    OV001_SCROLLBAR_EVENT_HANDLE_UP      = 3, /* the handle was released */
    OV001_SCROLLBAR_EVENT_UP_PRESS       = 4, /* the up cap was pressed */
    OV001_SCROLLBAR_EVENT_UP_RELEASE     = 5, /* ... and released */
    OV001_SCROLLBAR_EVENT_DOWN_PRESS     = 6, /* the down cap was pressed */
    OV001_SCROLLBAR_EVENT_DOWN_RELEASE   = 7  /* ... and released */
};

/* The generic scroll bar (ScrollBar_*, main_020A94FC): the touchable track, the
 * scroll value with its range, and the draggable thumb object it owns at +0x1C. */
#define SCROLLBAR_FLAGS    0x05 /* u8 nonzero while the bar accepts touch */
#define SCROLLBAR_DRAGGING 0x06 /* u8 nonzero while the thumb is grabbed */
#define SCROLLBAR_X        0x08 /* s16 x of the track the thumb slides along */
#define SCROLLBAR_Y        0x0A /* s16 y of the track */
#define SCROLLBAR_TOUCH_W  0x0C /* u8 width of the track's touch rectangle */
#define SCROLLBAR_TOUCH_H  0x0D /* u8 height of the track's touch rectangle */
#define SCROLLBAR_VALUE    0x12 /* s16 current scroll value */
#define SCROLLBAR_MIN      0x14 /* s16 lowest scroll value */
#define SCROLLBAR_MAX      0x16 /* s16 highest scroll value */
#define SCROLLBAR_THUMB    0x1C /* void * the draggable thumb (SCROLLTHUMB_*) */

/* The thumb of a scroll bar (ScrollBar_PlaceThumb): its clamped position, the
 * offsets from the track start, its touch box and the bounds it clamps to. */
#define SCROLLTHUMB_X       0x08 /* s16 thumb x, clamped into [MIN_X,MAX_X] */
#define SCROLLTHUMB_Y       0x0A /* s16 thumb y, clamped into [MIN_Y,MAX_Y] */
#define SCROLLTHUMB_DX      0x0C /* s16 thumb x minus the track start (MIN_X) */
#define SCROLLTHUMB_DY      0x0E /* s16 thumb y minus the track start (MIN_Y) */
#define SCROLLTHUMB_TOUCH_W 0x10 /* u8 touch box width */
#define SCROLLTHUMB_TOUCH_H 0x11 /* u8 touch box height */
#define SCROLLTHUMB_MIN_X   0x12 /* s16 leftmost thumb x */
#define SCROLLTHUMB_MAX_X   0x14 /* s16 rightmost thumb x */
#define SCROLLTHUMB_MIN_Y   0x16 /* s16 topmost thumb y */
#define SCROLLTHUMB_MAX_Y   0x18 /* s16 bottommost thumb y */

/* Fields used when closing an MSL file stream. */
#define FILE_STREAM_HANDLE      0x00 /* s32 handle passed to the close callback */
#define FILE_STREAM_MODE        0x04 /* s32 packed modes, including the file kind */
#define FILE_STREAM_STATE       0x08 /* s32 state word */
#define FILE_STREAM_CLOSE_CB    0x44 /* s32 (*)(s32 handle) */

#define FILE_STREAM_KIND_MASK   0x380 /* zero for a closed stream */
#define FILE_STREAM_KIND(mode)  ((u32)((mode) << 22) >> 29)
#define FILE_STREAM_CLOSE_ERROR(state) ((u32)((state) << 28) >> 31) /* bit 3 forces a close error */

/* The C runtime's multibyte locale (gMultibyteLocale): the character-class
 * table, the longest multibyte character in bytes (MB_CUR_MAX) and the table of
 * conversion functions the wide-character helpers dispatch through, so another
 * locale can swap them. */
typedef struct MultibyteFunctions {
    s32 (*mbtowc)(s16 *wideChar, u8 *multibyte, s32 remainingBytes); /* +0x00 */
    s32 (*wctomb)(s8 *multibyte, u16 wideChar);                       /* +0x04 */
} MultibyteFunctions;
#define LOCALE_CLASS_TABLE 0x00 /* void *: character-class table */
#define LOCALE_MB_CUR_MAX  0x04 /* u32: longest multibyte character in bytes */
#define LOCALE_FUNCTIONS   0x08 /* MultibyteFunctions *: the conversions */

/* The buffered part of a stream object, shared by the read and write paths
 * (StreamResetBuffer, StreamFillBuffer, StreamFlush).  position is the file
 * offset just past the bytes read from the file, mask keeps the buffer start on
 * its block boundary, and the stream's current file offset is
 * STREAM_BUFFER_POS + (STREAM_CURSOR - STREAM_BUFFER). */
#define STREAM_POSITION     0x18 /* s32 file offset just past the bytes read */
#define STREAM_BUFFER       0x1C /* u8 *start of the stream's buffer */
#define STREAM_BUFFER_SIZE  0x20 /* s32 capacity of the buffer in bytes */
#define STREAM_CURSOR       0x24 /* u8 *current read/write cursor in the buffer */
#define STREAM_PENDING      0x28 /* s32 bytes in the buffer not consumed yet */
#define STREAM_BUFFER_MASK  0x2C /* s32 keeps the buffer start on its block boundary */
#define STREAM_BUFFER_POS   0x34 /* s32 file offset the buffer starts at */

/* Stream locking shared by the stdio file helpers and the stdout printf.
 * gStreamMutexes holds one GsiMutex per stream class (its symbol
 * covers the first three; gStreamMutexStdout holds the stdout one); the running
 * thread object (gSocketManager+0x04) carries its id at +0x6C, which
 * gStreamLockOwner records while it holds the mutex and gStreamLockDepth counts
 * its reentrant nesting. */
#define STREAM_LOCK_STDIN  2    /* gStreamMutexes index for stdin */
#define STREAM_LOCK_STDOUT 3    /* ... for stdout */
#define STREAM_LOCK_STDERR 4    /* ... for stderr */
#define STREAM_LOCK_FILE   5    /* ... for every other stream */
#define STREAM_THREAD_ID   0x6C /* s32 thread id inside the running thread object */
#define STD_STREAM_COUNT   3    /* standard streams: stdin, stdout, stderr */
#define STD_STREAM_STRIDE  0x4C /* bytes between the standard stream objects at gStdinStream */

/* The console's menu language (gLanguage, read by GetLanguage).  The localized
 * file name built by GetLocalizedFileName takes the matching gFileNameFormat*
 * prefix; 0 means no language is set yet and the plain name is used. */
enum {
    LANGUAGE_UNSET   = 0,
    LANGUAGE_ENGLISH = 1, /* e_ prefix */
    LANGUAGE_FRENCH  = 2, /* f_ prefix */
    LANGUAGE_GERMAN  = 3, /* d_ prefix */
    LANGUAGE_ITALIAN = 4, /* i_ prefix */
    LANGUAGE_SPANISH = 5, /* s_ prefix */
    LANGUAGE_KOREAN  = 6  /* kor.bmg archive, kc_ font */
};

/* A localized text bank, an entry of gTextBankTable: the first text id the
 * bank holds and the localized file it is loaded from.  The table ends with an
 * entry whose file name is null.  gUiGraphicsBanks holds the loaded bank for
 * each entry, and a text id's low 24 bits index the bank's offset table
 * (LoadUiGraphicsBank loads a bank, GetLocalizedText looks a string up). */
typedef struct LocalizedTextBank {
    u32 firstTextId;  /* +0x00 lowest text id the bank holds */
    const char *file; /* +0x04 localized file name of the bank, 0 at the end of the table */
} LocalizedTextBank;
#define TEXT_BANK_INDEX_MASK 0xFFFFFF /* low bits of a text id: index in the bank's offset table */
#define TEXT_BANK_COUNT 0x28 /* slots in gTextBankTable / loaded banks in gUiGraphicsBanks */

/* Refcounted cache of the decompressed username font ("/link/username_font"),
 * whose 128-byte glyphs DrawGlyphString copies into the name sprites. */
typedef struct UsernameFontCache {
    u8 refCount;  /* +0x00 live acquires of the font */
    u8 pad01[3];
    void *glyphs; /* +0x04 decompressed glyph data */
} UsernameFontCache;

/* UI message text ids passed to SetUiMessageText. */
#define TEXT_ID_NO_SAVE_DATA 0xC000034C /* the save data the current menu needs is missing */
#define TEXT_ID_SAVE_LOAD_FAILED 0xC000034D /* the save data could not be loaded */
#define TEXT_ID_BATTLE_RULES 0xC0000328 /* the battle map's rules message, free battle */
#define TEXT_ID_BATTLE_RULES_CAMPAIGN 0xC000032F /* the battle map's rules message, campaign battle */

/* The generated text-label slot table (gTextLabelSlotState): 13 slots, each a
 * used flag (one byte at the table base) plus two 12-byte rows, one row per slot
 * at base + slot*TEXT_LABEL_ROW_BYTES. */
#define TEXT_LABEL_SLOT_COUNT 13
#define TEXT_LABEL_ROW_BYTES  12
#define TEXT_LABEL_ROW_A      0x0D /* per-slot first 12-byte row */
#define TEXT_LABEL_ROW_B      0xA9 /* per-slot second 12-byte row */

/* One thread of the cooperative scheduler.  gThreadManager (a void * with
 * gSocketManager straight after it) holds the running thread at
 * THREAD_MANAGER_CURRENT and the ready list, kept in priority order and chained
 * through Thread::next, at THREAD_MANAGER_READY. */
 #define THREAD_MANAGER_LOCK    0x04 /* s32 scheduler disable count: OS_DisableScheduler/OS_EnableScheduler step it and the scheduler runs only while it is 0 */
#define THREAD_MANAGER_CURRENT 0x28 /* Thread *: the thread that is running */
#define THREAD_MANAGER_SWITCH_CALLBACK 0x30 /* ThreadSwitchCallback: run with (from, to) just before every switch, 0 when none */
 #define THREAD_MANAGER_READY   0x2c /* Thread *: first thread of the ready list */
#define THREAD_MANAGER_UNK_30  0x30 /* s32: cleared once during scheduler init; no other reader or writer */
 /* Thread **: points at the slot holding the running thread (the same Thread * as
  * THREAD_MANAGER_CURRENT); the scheduler reads the current thread through it. */
 #define THREAD_MANAGER_RUNNING 0x08

/* Thread::state values. */
enum {
    THREAD_STATE_WAITING  = 0, /* asleep on a queue */
    THREAD_STATE_READY    = 1, /* runnable, on the ready list */
    THREAD_STATE_FINISHED = 2  /* finished; the scheduler skips it */
};

typedef struct Thread {
    u8 pad00[0x64];
    s32 state;           /* +0x64 0 waiting, 1 ready to run, 2 finished */
    struct Thread *next; /* +0x68 next thread of the ready list */
    u32 id;              /* +0x6c creation id */
    s32 priority;        /* +0x70 run priority; equal priorities round-robin */
    u8 pad74[4];
    void *waitQueue;          /* +0x78 OSThreadQueue *the thread is waiting on, 0 when running */
    struct Thread *queuePrev; /* +0x7c previous thread in that queue */
    struct Thread *queueNext; /* +0x80 next thread in that queue */
} Thread;

/* The callback the scheduler runs with the thread it leaves and the one it
 * switches to, just before the context switch; 0 when the game has none. */
typedef void (*ThreadSwitchCallback)(Thread *from, Thread *to);

/* The callback TaskExitThread runs once with the thread's exit status when the
 * thread ends; cleared before it runs.  0 when none is registered. */
#define THREAD_EXIT_CALLBACK 0xB4

/* The timer object scheduled to wake a thread that is sleeping in
 * SleepMilliseconds; 0 when the thread is not sleeping on a timer. */
#define THREAD_WAKE_TIMER 0xB0

/* The thread queue holding the threads asleep in OS_JoinThread on this thread;
 * TerminateThread wakes them all once the thread is finished. */
#define THREAD_JOIN_QUEUE 0x9C

/* An OS mutex (the OSMutex a sound or network task locks): the waiting-thread
 * queue the scheduler keeps at +0x00, the owning thread, and the owner's
 * reentrant lock count.  A mutex the thread has locked is chained on the thread's
 * own list through the mutex link. */
#define OSMUTEX_OWNER     0x08 /* Thread *: the thread holding the mutex, 0 when free */
#define OSMUTEX_COUNT     0x0c /* u32 nesting level of the owner's locks */
#define OSMUTEX_LINK_NEXT 0x10 /* OSMutex * next mutex on the owner thread's list */
#define OSMUTEX_LINK_PREV 0x14 /* OSMutex * previous mutex on that list */
#define THREAD_WAIT_MUTEX      0x84 /* OSMutex * mutex the thread is blocked on */
#define THREAD_MUTEX_LIST_HEAD 0x88 /* OSMutex * first mutex the thread has locked */
#define THREAD_MUTEX_LIST_TAIL 0x8c /* OSMutex * last of that list */

/* The exit-function list (gExitFunctionList) the C++ runtime registers with
 * __cxa_atexit: a singly-linked list of nodes, each a function and the argument
 * it is run with.  Unloading a module takes out the nodes that belong to it. */
#define EXIT_FUNC_NEXT     0x00 /* node *: next registered function, 0 at the end */
#define EXIT_FUNC_CALLBACK 0x04 /* the function to run */
#define EXIT_FUNC_ARG      0x08 /* u32 argument handed to it */

/* The CO state (gCoState): the last battle's three ratings with their grade and
 * the CO the menus show, then the bitset of unlocked COs.  The battle-results
 * screen counts the ratings up from zero to these values. */
#define CO_STATE_SPEED     0x00 /* u8 speed rating counted up by the results screen */
#define CO_STATE_POWER     0x01 /* u8 power rating */
#define CO_STATE_TECHNIQUE 0x02 /* u8 technique rating */
#define CO_STATE_RANK      0x03 /* u8 grade 1..4 of the total rating */
#define CO_STATE_CURRENT_SLOT 0x04 /* u8 index into gCoPlayerSlots of the CO the menus show */
#define CO_STATE_UNLOCKED 0x08
#define CO_COUNT 15 /* COs in the roster: CO_STATE_UNLOCKED has one bit each */

/* The CO roster (gCoPlayerSlots): 12-byte records, one per CO. */
#define CO_SLOT_STRIDE 12 /* bytes per record */
#define CO_SLOT_ID     0x00 /* u16 id of the CO in the slot, 0 when the slot is empty */

/* A Q12 fixed-point 4x3 matrix as the matrix library (main_02001068) stores it:
 * three rows of three rotation/scale coefficients, row-major, then the
 * translation row.  NitroSDK calls this type MtxFx43. */
#define MTX43_ROT     0  /* s32[9] rotation/scale coefficients */
#define MTX43_TRANS   9  /* s32[3] translation */
#define MTX44_TRANS   12 /* s32[4] translation column of a 4x4 matrix (MtxFx44) */
#define MTX_FX_SHIFT  12 /* fractional bits of a matrix coefficient */

/* NitroSDK thread and message queues (os_thread.c, os_message.c).  An
 * OSMessageQueue is a fixed ring of 32-bit messages, usually pointers, that
 * threads hand to each other; a thread queue lists the threads asleep on it. */
typedef struct OSThreadQueue {
    void *head; /* +0x00 first thread waiting on the queue, NULL when empty */
    void *tail; /* +0x04 last thread waiting on the queue */
} OSThreadQueue; /* 8 bytes */

typedef struct OSMessageQueue {
    OSThreadQueue sendQueue;    /* +0x00 threads asleep because the queue is full */
    OSThreadQueue receiveQueue; /* +0x08 threads asleep because the queue is empty */
    s32 *msgArray;              /* +0x10 message slots */
    s32 msgCount;               /* +0x14 number of slots */
    s32 firstIndex;             /* +0x18 slot holding the oldest message */
    s32 usedCount;              /* +0x1C messages queued */
} OSMessageQueue; /* 0x20 bytes */

/* Flags of OS_SendMessage, OS_JamMessage, OS_ReceiveMessage and OS_ReadMessage:
 * bit 0 set makes the call sleep until the queue can take or give a message. */
enum {
    OS_MESSAGE_NOBLOCK = 0,
    OS_MESSAGE_BLOCK   = 1
};

/* ARM processor mode: the low five bits of CPSR (read by the CPSR reader in
 * main_02006F14).  Code that would sleep or take a blocking mutex refuses to
 * run in IRQ mode. */
#define CPSR_MODE_IRQ 0x12

/* The DS real-time clock counts seconds since 2000/01/01 and only distinguishes the
 * years of one century: RtcSecondsToDateTime clamps a count to that range. */
#define RTC_SECONDS_PER_MINUTE 60
#define RTC_SECONDS_PER_HOUR   3600
#define RTC_SECONDS_PER_DAY    86400

typedef struct RtcTime {
    s32 hour;
    s32 minute;
    s32 second;
} RtcTime;

/* The DS real-time clock's date record, as filled by GetRtcDate and read by
 * RtcDateToDays. */
typedef struct RtcDate {
    u32 year;    /* +0x00 year since 2000, 0..99 */
    u32 month;   /* +0x04 month, 1..12 */
    u32 day;     /* +0x08 day of the month, 1..31 */
    s32 weekday; /* +0x0C day of the week, 0 = Sunday */
} RtcDate;

/* A saved date/time stamp (the profile's sync time and the Get request's server
 * time) is an RtcDate record followed by an RtcTime record; the time starts
 * this far into it. */
#define DATE_TIME_TIME 0x10

#define RTC_EPOCH_OFFSET 946684800 /* seconds from 1970/01/01 to the RTC's 2000/01/01 */

#define WM_TGID_UNINITIALIZED 0x10000u
#define RTC_SECONDS_SPAN       3155760000LL /* one RTC century, 100 * 365.25 days */
#define RTC_SECONDS_LAST       3155759999LL /* last second the RTC can name */

/* The RTC request state (gRtcState): one request is in flight at a time, and the
 * FIFO reply handler (func_0200f0e4) fills the out records and calls the
 * callback when the operation completes.  A request kind repeats 0 for a date
 * read, 1 for a time read and 2 for a read of both. */
#define RTC_STATE_READY        0x00 /* u16 nonzero once the FIFO handler is installed */
#define RTC_STATE_BUSY         0x04 /* s32 1 while the request is being started or completed */
#define RTC_STATE_CALLBACK     0x08 /* void (*)(s32 result, s32 callbackArg) run on completion */
#define RTC_STATE_OUT0         0x0C /* s32 * first result record (the date) */
#define RTC_STATE_OUT1         0x10 /* s32 * second result record (the time) */
#define RTC_STATE_CALLBACK_ARG 0x14 /* s32 second argument passed to the callback */
#define RTC_STATE_KIND         0x18 /* s32 operation the reply is decoded as */
#define RTC_STATE_STEP         0x1C /* s32 step/retry flag of a multi-frame operation */
#define RTC_STATE_HANDLER      0x20 /* void (*)(void) handler for a command-0x30 reply */
#define RTC_STATE_RESULT       0x24 /* s32 result of the last completed request */

/* IPC FIFO tag and the ARM7 processor id of the RTC command channel. */
#define RTC_FIFO_TAG 5

/* An RTC command word carries its command index in bits 8..14 of the FIFO word. */
#define RTC_COMMAND_SHIFT 8
#define RTC_COMMAND_MASK  0x7F00

/* Values of RTC_STATE_KIND. */
#define RTC_KIND_DATE      0 /* read the date into RTC_STATE_OUT0 */
#define RTC_KIND_TIME      1 /* read the time into RTC_STATE_OUT0 */
#define RTC_KIND_DATE_TIME 2 /* read the date into OUT0 and the time into OUT1 */

/* One record of gDialogSequences, the eight dialog scripts the game can run at
 * once.  While script is set the record is active: its command pointer walks a
 * script of 16-byte commands (run through the dispatch table) and wait, when
 * set, is called every frame until it clears the slot. */
typedef struct DialogSequence {
    void *script;   /* +0x00: script being run, 0 when the slot is free */
    u8   *command;  /* +0x04: next 16-byte command of the script */
    s32 (*wait)(struct DialogSequence *); /* +0x08: per-frame wait callback, 0 = none */
    u16  delay;     /* +0x0C: frames the current command still waits */
    u8   pad0E[2];
    u8   pad10[8];
} DialogSequence;
#define DIALOG_SEQUENCE_COUNT 8
#define DIALOG_SEQUENCE_STRIDE 0x18 /* one DialogSequence record */

/* The ARM7 sound command channel: InitSoundCommandLink installs the channel's
 * handler under this IPC FIFO tag and waits for the ARM7 firmware to report it
 * ready, polling every SND_CMD_LINK_POLL_DELAY cycles. */
#define SND_CMD_FIFO_TAG       7
#define SND_CMD_LINK_POLL_DELAY 100 /* WaitCycles between link-ready polls */
/* The sound command channel's status register, probed by
 * Sound_IsCommandChannelReady: writing SND_CMD_CHANNEL_PROBE and reading it back
 * gives a nonzero value once the channel can carry commands. */
#define SND_CMD_CHANNEL_STATUS_REG 0x04FFF200
#define SND_CMD_CHANNEL_PROBE      0x10

/* The ARM7 sound driver's shared command-argument buffer (gSoundCommandBuffer,
 * 640 bytes): two handshake words the ARM9 polls (the number of command batches
 * the ARM7 has taken and the mask of channels it is playing), then 16 argument
 * entries — each a 16-value s16 parameter array and a value word — and a final
 * 16-value parameter array.  InitSoundCommandBuffer resets it. */
#define SND_CMD_BUFFER_SIZE         640
#define SND_CMD_BUFFER_PROCESSED    0x000 /* s32 command batches the ARM7 has taken */
#define SND_CMD_BUFFER_CHANNELS     0x004 /* u32 channels the ARM7 sound driver is playing */
#define SND_CMD_BUFFER_UNK08        0x008 /* s16 */
#define SND_CMD_BUFFER_UNK0A        0x00A /* s16 */
#define SND_CMD_BUFFER_ENTRY_COUNT  16   /* argument entries */
#define SND_CMD_BUFFER_ENTRY_STRIDE 0x024 /* bytes per entry */
#define SND_CMD_BUFFER_ENTRY_PARAMS 0x020 /* s16 parameter array of an entry (16 values) */
#define SND_CMD_BUFFER_ENTRY_VALUE  0x040 /* s32 value word of an entry */
#define SND_CMD_BUFFER_PARAM_COUNT  16   /* s16 parameters per array */
#define SND_CMD_BUFFER_TAIL_PARAMS  0x260 /* final s16 parameter array (16 values) */

/* One ARM7 sound command node (SOUND_CMD_NODE_SIZE bytes) from the
 * gSoundCommandNodes pool: the queue's next link at +0x00, the command id at
 * +0x04 and up to four s32 arguments at +0x08..+0x14.  SendArm7Message fills one
 * and EnqueueSoundCommand queues it. */
#define SOUND_CMD_NODE_NEXT 0x00 /* next node link used by the queue */
#define SOUND_CMD_NODE_ID   0x04 /* s32 command id */
#define SOUND_CMD_NODE_ARG0 0x08 /* s32 first command argument */
#define SOUND_CMD_NODE_ARG1 0x0C /* s32 second command argument */
#define SOUND_CMD_NODE_ARG2 0x10 /* s32 third command argument */
#define SOUND_CMD_NODE_ARG3 0x14 /* s32 fourth command argument */
#define SOUND_CMD_NODE_SIZE 0x18
#define SOUND_CMD_NODE_COUNT 0x100 /* nodes in the gSoundCommandNodes pool */

/* The ARM9-side ARM7 sound command queue state (gSoundCommandQueueState,
 * 36 bytes), always read and written with interrupts locked: the free command
 * nodes are chained on the free list, and the commands waiting to be sent to
 * the ARM7 on the send list.  Each batch of queued commands is sent as the head
 * of its node chain and remembered in gSoundCommandSentBatches (nine slots in
 * use), so that once the ARM7 reports taking a batch the queue can free its
 * nodes again (Sound_DequeueCommand) and raise SOUND_CMD_QUEUE_COMPLETED.  A
 * command mark (Sound_GetCommandMark) is a batch number compared against that
 * completed count by Sound_IsCommandReached. */
#define SOUND_CMD_QUEUE_FREE_HEAD     0x00 /* SOUND_CMD_NODE *first free command node */
#define SOUND_CMD_QUEUE_COMPLETED     0x04 /* s32 command batches the ARM7 has taken */
#define SOUND_CMD_QUEUE_SEND_HEAD     0x08 /* SOUND_CMD_NODE *first command waiting to be sent */
#define SOUND_CMD_QUEUE_SEND_TAIL     0x0C /* SOUND_CMD_NODE *last command waiting to be sent */
#define SOUND_CMD_QUEUE_FREE_TAIL     0x10 /* SOUND_CMD_NODE *last free command node */
#define SOUND_CMD_QUEUE_RECLAIM_INDEX 0x14 /* s32 ring slot the next taken batch is freed from */
#define SOUND_CMD_QUEUE_SEND_INDEX    0x18 /* s32 ring slot the next sent batch is remembered in */
#define SOUND_CMD_QUEUE_PENDING       0x1C /* s32 batches sent and not taken yet */
#define SOUND_CMD_QUEUE_NEXT_MARK     0x20 /* s32 mark the next sent batch takes */
#define SOUND_CMD_SEND_RING_SLOTS     9    /* gSoundCommandSentBatches slots the queue uses */

/* Intrusive doubly-linked list header shared by the List* helpers (ListInit,
 * ListAddFirst, ListAppend/Prepend, ListInsertBefore, ListRemove, ListNext/Prev
 * in main_02028EF4) and their callers: the head and tail node pointers, the node
 * count and the byte offset of each node's {prev, next} link pair inside the
 * node.  A null link pair word means there is no link that way. */
#define DLIST_HEAD        0x00 /* void *first node */
#define DLIST_TAIL        0x04 /* void *last node */
#define DLIST_COUNT       0x08 /* u16 nodes in the list */
#define DLIST_NODE_OFFSET 0x0A /* u16 offset of a node's link pair from the node's start */
#define DLIST_LINK_PREV   0x00 /* void *previous node in a node's link pair */
#define DLIST_LINK_NEXT   0x04 /* void *next node in a node's link pair */

/* One record of gShogunNameFiles, the CO face id -> name-graphic file table read
 * by GetNameFileForFace: the face id at +0x00 and, at +0x04, the .cg file name
 * of that CO's name graphic (0 when the face has no name graphic). */
typedef struct FaceNameFile {
    s16  faceId;    /* +0x00: CO face id */
    char *nameFile; /* +0x04: name graphic file name, 0 when none */
} FaceNameFile;
#define FACE_NAME_FILE_COUNT 15 /* records in gShogunNameFiles */

/* Name/character graphics loaded into gNameGraphicFiles, in file order: the two
 * standalone .cg files "ter_moji.cg" (terrain glyphs) and "unit_moji.cg" (unit
 * glyphs), then the terrain, unit and weapon name tables of cg_name.narc. */
#define NAME_GRAPHIC_FILE_COUNT 5

/* The ov004 battle-start window state (the task object func_ov004_022120c0 sets
 * up and Ov004_UpdateBattleStartWindow steps every frame): the opening animation's frame
 * counters, the day number the window shows, its phase, the gap between its two
 * frame bars and the palette fades it starts. */
#define OV004_START_WINDOW_OPEN_FRAME   0x34 /* u16 frame of the opening ease, 0..OV004_START_WINDOW_EASE_FRAMES */
#define OV004_START_WINDOW_FRAME        0x36 /* u16 frames the window has been open */
#define OV004_START_WINDOW_DAY          0x3a /* u8 day number drawn in the window */
#define OV004_START_WINDOW_PHASE        0x3b /* u8 opening phase, 0..4 */
#define OV004_START_WINDOW_SLIT         0x3c /* u8 half the gap between the two frame bars */
#define OV004_START_WINDOW_FADE_DELAY   0x3d /* u8 frames left before the next palette fade */
#define OV004_START_WINDOW_FADE_MAIN    0x40 /* void *main-screen palette fade */
#define OV004_START_WINDOW_FADE_SUB     0x44 /* void *sub-screen palette fade */
#define OV004_START_WINDOW_EASE_FRAMES  16   /* frames the opening ease and each fade hold last */
#define OV004_START_WINDOW_ROWS         16   /* cell grid rows on each side of the split */
#define OV004_START_WINDOW_SLIT_MAX     20   /* gap half-width once the window is fully open */
#define OV004_START_WINDOW_PALETTE_FRAMES 32 /* frames each palette fade lasts */

#endif

