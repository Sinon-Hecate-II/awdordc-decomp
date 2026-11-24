/* Fields of the TCP socket object used by TcpSendData in main_0201CB4C, and
 * the network-stack callback that says whether the link is up. */
#ifndef TCP_SOCKET_H
#define TCP_SOCKET_H

#define TCP_SOCK_STATE   0x08 /* u8 connection state, 4 = established */
#define TCP_SOCK_SENDPOS 0x28 /* u32 bytes queued into the send buffer */
#define TCP_SOCK_ACKFLAG 0x2C /* u16 set when the peer acknowledges */
#define TCP_SOCK_SENTPOS 0x30 /* u32 bytes handed to the link */
#define TCP_SOCK_RESULT  0x34 /* s32 result of the last operation */

/* Network stack state (gNetStack) callbacks. */
#define NETSTACK_SEND_FAILED 0x00 /* u8: nonzero after the last link send returned an error */
#define NETSTACK_WORKER_WAKE_PENDING 0x44 /* s32: set while the network worker's wakeup is already queued */
#define NETSTACK_POLL   0x48 /* s32 (*poll)(void): nonzero while the link is up */
#define NETSTACK_WAIT_INTERVAL 0x24 /* s32 milliseconds to sleep between idle polls */
#define NETSTACK_SOCKET_RAW_CONNECTION 0xA4 /* void *raw transport connection of the current socket */
#define NETSTACK_TLS_CLOSE_WAIT 39 /* tick count before abandoning a pending TLS close alert */
#define NETSTACK_UPDATE 0x18 /* void (*)(void): stack upkeep callback run once per waiting step */

/* gNetStack single-producer/single-consumer packet ring.  The producer appends
 * a record at NETSTACK_RING_WRITE (a u16 length followed by the packet data) and
 * must stay ahead of the consumer position; the consumer advances through the
 * ring the same way.  A record never wraps: it is only started if it fits. */
#define NETSTACK_RING_WRITE 0x28 /* u32 byte offset where the next record is written */
#define NETSTACK_RING_READ  0x30 /* u32 byte offset of the next record to read */
#define NETSTACK_RING_BUF   0x58 /* u8 *ring buffer */
#define NETSTACK_RING_SIZE  0x5c /* u32 ring buffer size in bytes */
#define NETSTACK_RING_WAITER 0x54 /* void *running thread object while the reader sleeps for a record, else 0 */
#define NETSTACK_MAX_PACKET 0x5e4 /* largest record the ring accepts */

/* The network stack's 64-bit linear-congruential PRNG advanced by NetStackRandom:
 * state = state * NETSTACK_RANDOM_MULT + NETSTACK_RANDOM_ADD, returning the new
 * state's high 32 bits.  seed_network_random sets the state and the constants. */
#define NETSTACK_RANDOM_STATE 0x68 /* u64: current state */
#define NETSTACK_RANDOM_MULT  0x70 /* u64: multiplier, NETSTACK_RANDOM_MULT_VALUE */
#define NETSTACK_RANDOM_ADD   0x78 /* u64: increment, NETSTACK_RANDOM_ADD_VALUE */
#define NETSTACK_RANDOM_MULT_VALUE 0x5D588B656C078965ULL
#define NETSTACK_RANDOM_ADD_VALUE  0x269EC3

/* More gNetStack fields used by the IPv4 sender in main_0201AE0C. */
#define NETSTACK_ALLOC    0x14 /* void *(*)(s32 size) packet buffer allocator */
#define NETSTACK_FREE     0x40 /* void (*)(void *block) packet buffer release */
#define NETSTACK_IP_ID    0x06 /* u16 IPv4 identification counter, bumped per packet */
#define NETSTACK_LOCAL_IP 0x50 /* u32 local IPv4 address, host order */
#define NETSTACK_DHCP_SERVER    0x20 /* u32 DHCP server identifier from the OFFER (option 54) */
#define NETSTACK_REQUESTED_IP   0x34 /* u32 IPv4 address requested from the DHCP server (option 50) */
#define NETSTACK_ARP_RESOLVED 0x01 /* u8 set once an ARP reply announcing the local address arrives */

/* ARP packet layout (RFC 826), as handled by HandleArpPacket in main_0201AE0C.
 * The 16-bit fields are in network byte order in the buffer. */
#define ARP_HTYPE     0x00 /* u16 hardware type, 1 = Ethernet */
#define ARP_PTYPE     0x02 /* u16 protocol type, 0x0800 = IPv4 */
#define ARP_HLEN      0x04 /* u8 hardware address length, 6, followed by plen 4 */
#define ARP_OPCODE    0x06 /* u16 1 = request, 2 = reply */
#define ARP_SENDER_MAC 0x08 /* u8[6] sender hardware address */
#define ARP_SENDER_IP  0x0E /* u32 sender protocol address */
#define ARP_TARGET_MAC 0x12 /* u8[6] target hardware address */
#define ARP_TARGET_IP  0x18 /* u32 target protocol address */
#define ARP_ADDR_PAIR_SIZE 0x0A /* bytes of one hardware+protocol address pair (MAC + IPv4) */
#define ARP_PACKET_SIZE 0x1C /* smallest ARP packet the handler accepts */
#define ARP_OPCODE_REQUEST 1
#define ARP_OPCODE_REPLY   2

/* Gratuitous-ARP announcement of the stack's own address: the packet is sent
 * ARP_RETRY_MS apart while the link is polled, for NETSTACK_ARP_TIMEOUT ticks. */
#define ARP_RETRY_MS         100 /* milliseconds between the announcement packets */
#define NETSTACK_ARP_TIMEOUT 23  /* (GetSystemTick >> 16) ticks the announcement waits before giving up */
#define ARP_RESOLVE_ATTEMPTS 8   /* times ResolveArpMacAddress re-announces itself before giving up */
#define ARP_RESOLVE_WAITS    20  /* ARP_RETRY_MS waits for a reply after each announcement */

/* The IPv4 ARP cache (gArpCache): ARP_CACHE_COUNT entries mapping an address to
 * the hardware address learned for it, with the tick it was last refreshed. */
#define ARP_CACHE_COUNT   8
#define ARP_CACHE_STRIDE  0x0C
#define ARP_CACHE_ADDR    0x00 /* u32 IPv4 address, host order */
#define ARP_CACHE_MAC     0x04 /* u8[6] hardware address */
#define ARP_CACHE_AGE     0x0A /* u16 tick the entry was last refreshed (GetSystemTick >> 16) */

/* IPv4 fragmentation: at most 1480 payload bytes per fragment, the fragment
 * offset counts 8-byte units, and the more-fragments flag is 0x2000. */
#define IP_HEADER_SIZE          20
#define LINK_HEADER_SIZE        8  /* link-layer header the stack prepends to a frame */
#define IP_LOOPBACK             0x7F000001u /* 127.0.0.1 in host order */
#define IP_MAX_FRAGMENT_PAYLOAD 1480
#define IP_FRAGMENT_UNIT        8
#define IP_FLAG_MOREFRAGMENTS   0x2000
#define ETH_TYPE_IPV4           0x0800 /* Ethernet type of an IPv4 frame */
#define ETH_TYPE_ARP            0x0806 /* Ethernet type of an ARP frame */

/* Ethernet II header the stack builds in front of the IPv4 packet: destination
 * MAC, source MAC, then the type.  Its offsets are from the header start, which
 * sits ETH_HEADER_SIZE bytes before the IPv4 header. */
#define ETH_HEADER_SIZE  14
#define ETH_DEST_MAC     0x00 /* u8[6] destination hardware address */
#define ETH_SRC_MAC      0x06 /* u8[6] source hardware address */
#define ETH_TYPE         0x0C /* u16 Ethernet type, network byte order */
#define ETH_MULTICAST_MAC_PREFIX 0x01 /* first byte: 01:00:5e:xx:xx:xx */
#define ETH_MULTICAST_MAC_SECOND 0x00
#define ETH_MULTICAST_MAC_THIRD  0x5E

/* IPv4 header fields (RFC 791) the transport layer reads; the 16-bit fields are
 * in network byte order in the packet. */
#define IPH_VERSION_IHL 0x00 /* u8 version in the high nibble, header length in words in the low one */
#define IPH_TOTAL_LENGTH 0x02 /* u16 total packet length, network byte order */
#define IPH_PROTOCOL  0x09 /* u8 protocol of the payload */
#define IPH_SRC_IP    0x0C /* u32 source IPv4 address */
#define IPH_SRC_IP_HI 0x0C /* u16 high half of the source address */
#define IPH_SRC_IP_LO 0x0E /* u16 low half of the source address */
#define IPH_DST_IP    0x10 /* u32 destination IPv4 address */
#define IPH_DST_IP_HI 0x10 /* u16 high half of the destination address */
#define IPH_DST_IP_LO 0x12 /* u16 low half of the destination address */

/* ICMP message fields and the types the ICMP handler dispatches on. */
#define ICMP_TYPE      0x00 /* u8 message type */
#define ICMP_CHECKSUM  0x02 /* u16 message checksum */
#define ICMP_TYPE_ECHO_REPLY   0
#define ICMP_TYPE_ECHO_REQUEST 8
/* The 16-bit one's-complement internet checksum (RFC 1071) the network stack
 * builds: ChecksumAccumulate adds the words of a buffer to a running sum and
 * folds its carries (words are summed big-endian, so a buffer at an odd address
 * is summed byte by byte and an even one has its host-order words byte-swapped
 * around the sum), and ChecksumFinalize complements the result, mapping 0 to
 * 0xFFFF so that a message summed with its own checksum field gives
 * CHECKSUM_VALID when the checksum is right. */
#define CHECKSUM_VALID 0xFFFF /* sum over a message, checksum field included, when it is valid */

/* TCP header fields (RFC 793), network byte order in the packet. */
#define TCPH_SRC_PORT 0x00 /* u16 sender port */
#define TCPH_DST_PORT 0x02 /* u16 receiver port */

/* IPv4 protocol numbers used by the transport senders. */
#define IP_PROTO_ICMP 1
#define IP_PROTO_TCP  6
#define IP_PROTO_UDP  17
#define IP_PSEUDO_HEADER_SIZE 12 /* source/dest address, zero+protocol, transport length */
#define UDP_HEADER_SIZE 8

/* Fields of the datagram/stream socket object (gSocketManager->...+0xA4) the
 * transport senders share. */
#define SOCK_TRANSPORT   0x08 /* u8 transport: SOCK_KIND_UDP (10), SOCK_KIND_ICMP (11), else a TCP stream */
#define SOCK_TLS_ACTIVE  0x09 /* u8 nonzero once the socket's payload is wrapped in TLS records */
#define SOCK_LOCAL_PORT  0x0A /* u16 local (source) port */
#define SOCK_REMOTE_PORT 0x18 /* u16 remote (destination) port */
#define SOCK_REMOTE_IP   0x1C /* u32 remote IPv4 address, host order */
#define SOCK_SEND_BUFFER 0x4C /* void *send buffer; its +0x22 is where the transport header starts */

/* Deferred socket callback machinery (gSocketEventState / gSocketEventCallbacks,
 * formerly data_0213e4c4 / data_0213e4d4).  Network-stack code that must not run
 * reentrantly registers a callback here; FlushSocketCallbacks runs the queue
 * (count entries, last-to-first) once the network stack is idle and armed. */
#define SOCK_EVENT_FLUSH_CB  0x00 /* void (*)(void) one-shot, run after the queued callbacks */
#define SOCK_EVENT_IDLE_CB   0x04 /* void (*)(void) one-shot, run when the link comes back from idle */
#define SOCK_EVENT_COUNT     0x08 /* s32 number of callbacks queued in gSocketEventCallbacks */
#define SOCK_EVENT_ARMED     0x0C /* s32 nonzero once the network link is up (events may then flush) */
#define SOCK_EVENT_QUEUE_LEN 64 /* callbacks gSocketEventCallbacks can hold */

#endif
