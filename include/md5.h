/* The context of the MD5 message digest the game runs over its TLS handshake
 * transcript (MD5_Init/MD5_Update/MD5_Final in main_020251B8; 0x58 bytes, the
 * TLS_MD5_CTX_SIZE the channel records reserve for it). */
#ifndef MD5_H
#define MD5_H

#include "common.h"

#define MD5_BLOCK_SIZE  64 /* bytes of message per digest block */
#define MD5_DIGEST_SIZE 16 /* bytes of a finished digest */

typedef struct MD5Context {
    u32 state[4];   /* +0x00 chaining words a, b, c and d */
    u32 count[2];   /* +0x10 message length in bits, low word then high word */
    u8  buffer[64]; /* +0x18 bytes of the block being filled */
} MD5Context;

#endif
