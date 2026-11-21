/* GameSpy NAT-negotiation client (natneg). Every remote peer that needs a
 * hole punched for it has a NatNegPeer record; all of them are held in the
 * peer vector of the global manager gNatNegManager. */
#ifndef NATNEG_H
#define NATNEG_H

#define NATNEG_MAGIC_LEN 6 /* gNatNegMagic bytes at the start of every packet */
#define NATNEG_PROTOCOL_VERSION 2 /* version byte every packet carries */

/* Bytes of the packet header that follow the magic. */
#define NATNEG_PKT_VERSION 0x06 /* u8 NATNEG_PROTOCOL_VERSION */
#define NATNEG_PKT_KIND    0x07 /* u8 packet kind, NATNEG_KIND_* */

/* The receive address ghiRecvFrom fills (8 bytes) is also what the connect
 * packets send back: the sender's port and address, host byte order. */
#define NATNEG_ADDR_PORT 0x02 /* u16 source port */
#define NATNEG_ADDR_IP   0x04 /* u32 source address */

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

/* NatNeg packet kinds (the byte at packet+7). */
#define NATNEG_KIND_INIT         0x00 /* peer asks its partner to start negotiating */
#define NATNEG_KIND_INIT_ACK     0x01 /* one of the three responses to NN_INIT */
#define NATNEG_KIND_ERT_TEST     0x02 /* round-trip test request */
#define NATNEG_KIND_ERT_ACK      0x03 /* round-trip test response */
#define NATNEG_KIND_STATE_UPDATE 0x04 /* negotiation state update */
#define NATNEG_KIND_CONNECT_PING 0x05 /* connect request to the peer behind its NAT */
#define NATNEG_KIND_CONNECT_ACK  0x06 /* connect request acknowledged */
#define NATNEG_KIND_CONNECT_PONG 0x07 /* reply to a connect ping */

/* NatNegPeer state machine steps (NATNEG_PEER_STATE). */
enum {
    NATNEG_STATE_START   = 0, /* send the initial requests */
    NATNEG_STATE_ACKED   = 1, /* all responses to the initial requests arrived */
    NATNEG_STATE_CONNECT = 2, /* the peer's connect response arrived */
    NATNEG_STATE_REPORT  = 3, /* the peer's address report arrived */
    NATNEG_STATE_DONE    = 4  /* negotiation finished and the peer is released */
};

/* Fields the connect-ping/pong packets share (the layout NatNeg_SendConnectPong
 * builds): the sending peer's own address, its remote address and port and the
 * NAT state it reports. */
#define NATNEG_PKT_PEER_ADDR 0x08 /* u32 the sending peer's address, byte-swapped */
#define NATNEG_PKT_PEER_IP   0x0C /* s32 the sending peer's remote address */
#define NATNEG_PKT_PEER_PORT 0x10 /* u16 the sending peer's remote port, byte-swapped */
#define NATNEG_PKT_FLAG      0x12 /* u8 the sender's NATNEG_PEER_FLAG32 */
#define NATNEG_PKT_MODE      0x13 /* u8 nonzero when the sender was not in its connect step */

/* The connect ack (kind NATNEG_KIND_CONNECT_ACK) is 21 bytes: the header, the
 * peer's address as its cookie and the low byte of its echoed value; the port
 * it answers is handed to the send helper separately. */
#define NATNEG_PKT_ACK_VALUE 0x0D /* u8 low byte of the peer's NATNEG_PEER_VALUE */
#define NATNEG_PKT_ACK_LEN   0x15 /* bytes of a connect ack */

/* The BSD-style host record GetLocalAddressList hands back for the console's own
 * interfaces.  h_addr_list is a NULL-terminated array of pointers to 4-byte IPv4
 * addresses held in network byte order. */
typedef struct GsHostent {
    void  *h_name;      /* +0x00 official host name */
    void **h_aliases;   /* +0x04 alias list */
    u16    h_addrtype;  /* +0x08 AF_INET = 2 */
    u16    h_length;    /* +0x0A address length in bytes, 4 */
    void **h_addr_list; /* +0x0C interface addresses, NULL-terminated */
} GsHostent;

/* 127.0.0.1 as its four network-order bytes read as a little-endian ARM9 word
 * (0x7F000001 in host order). */
#define IP_LOOPBACK_NET 0x0100007Fu

#endif
