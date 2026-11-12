/* BOOTP/DHCP packet layout and constants, for the packet builder in
 * main_0201DB20.c.  All multi-byte wire fields are big-endian. */
#ifndef DHCP_H
#define DHCP_H

/* Fixed-header field offsets. */
#define DHCP_OFF_OP      0x00 /* u8: 1 = request, 2 = reply */
#define DHCP_OFF_HTYPE   0x01 /* u8: 1 = Ethernet */
#define DHCP_OFF_HLEN    0x02 /* u8: hardware address length, 6 */
#define DHCP_OFF_XID     0x04 /* u32 transaction id */
#define DHCP_OFF_CIADDR  0x0C /* u32 client IP address */
#define DHCP_OFF_CHADDR  0x1C /* u8[16]: client hardware address, then padding */
#define DHCP_OFF_OPTIONS 0xEC /* options start after the 64-byte sname and 128-byte file */

/* The four bytes 63 82 53 63 that open the option area. */
#define DHCP_MAGIC_W0 0x8263 /* as two little-endian u16 words */
#define DHCP_MAGIC_W1 0x6353

/* DHCP option codes. */
#define DHCP_OPT_HOSTNAME   12   /* host name */
#define DHCP_OPT_MSG_TYPE   53   /* DHCP message type, one byte */
#define DHCP_OPT_PARAM_REQ  55   /* parameter request list */
#define DHCP_OPT_CLIENT_ID  61   /* client identifier: hardware type + hardware address */
#define DHCP_OPT_SUBNET     1    /* parameter request: subnet mask */
#define DHCP_OPT_ROUTER     3    /* parameter request: router */
#define DHCP_OPT_DNS        6    /* parameter request: DNS servers */
#define DHCP_OPTION_END     255  /* end-of-options marker */

/* DHCP message types. */
#define DHCP_MSG_DISCOVER 1
#define DHCP_MSG_REQUEST  3
#define DHCP_MSG_RELEASE  7

#define DHCP_PACKET_MIN 300 /* smallest BOOTP/DHCP packet size */
#define DHCP_HWADDR_LEN 6

#endif
