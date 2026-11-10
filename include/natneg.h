/* GameSpy NAT-negotiation client (natneg). Every remote peer that needs a
 * hole punched for it has a NatNegPeer record; all of them are held in the
 * peer vector of the global manager gNatNegManager. */
#ifndef NATNEG_H
#define NATNEG_H

#define NATNEG_MAGIC_LEN 6 /* gNatNegMagic bytes at the start of every packet */

/* gNatNegManager fields. */
#define NATNEG_HOST2  0x00 /* char[] natneg2 server host name */
#define NATNEG_HOST1  0x04 /* char[] natneg1 server host name */
#define NATNEG_IP2    0x08 /* s32 resolved address of natneg2 */
#define NATNEG_IP1    0x0C /* s32 resolved address of natneg1 */
#define NATNEG_PEERS  0x10 /* vector handle of NatNegPeer records */

/* NatNegPeer fields. */
#define NATNEG_PEER_SOCKET      0x00 /* s32 UDP socket */
#define NATNEG_PEER_SOCKET2     0x04 /* s32 second socket, -1 until opened */
#define NATNEG_PEER_ADDRESS     0x08 /* u32 peer address, the lookup key */
#define NATNEG_PEER_VALUE       0x0C /* s32 value echoed in the packets */
#define NATNEG_PEER_STATE       0x10 /* s32 one of NATNEG_STATE_* */
#define NATNEG_PEER_GOT0        0x14 /* s32 response 0 received */
#define NATNEG_PEER_GOT1        0x18 /* s32 response 1 received */
#define NATNEG_PEER_GOT2        0x1C /* s32 response 2 received */
#define NATNEG_PEER_RETRIES     0x20 /* s32 retries of the current step */
#define NATNEG_PEER_MAX_RETRIES 0x24 /* s32 retries before giving up */
#define NATNEG_PEER_DEADLINE    0x28 /* u32 tick to retry at */
#define NATNEG_PEER_REMOTE_IP   0x2C /* s32 remote address */
#define NATNEG_PEER_REMOTE_PORT 0x30 /* u16 remote port, host order */
#define NATNEG_PEER_FLAG32      0x32 /* u8 */
#define NATNEG_PEER_FLAG33      0x33 /* u8 */
#define NATNEG_PEER_EVENT       0x34 /* void (*event)(s32 event, s32 data) */
#define NATNEG_PEER_SEND        0x38 /* void (*send)(s32 kind, s32 socket, void *packet, s32 data) */
#define NATNEG_PEER_SEND_DATA   0x3C /* s32 data passed to both callbacks */

/* NatNegPeer state machine steps (NATNEG_PEER_STATE). */
enum {
    NATNEG_STATE_START   = 0, /* send the initial requests */
    NATNEG_STATE_ACKED   = 1, /* all responses to the initial requests arrived */
    NATNEG_STATE_CONNECT = 2, /* the peer's connect response arrived */
    NATNEG_STATE_REPORT  = 3, /* the peer's address report arrived */
    NATNEG_STATE_DONE    = 4  /* negotiation finished and the peer is released */
};

#endif
