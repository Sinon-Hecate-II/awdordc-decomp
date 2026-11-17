/* The WFC channel transport (main_02012B70): a channel's state object holds the
 * slots of data sent to and received from the peers, then its control fields at
 * +0x800; the library reports completions through an event record, and the
 * network manager keeps one callback and one object per channel. */
#ifndef WFC_CHANNEL_H
#define WFC_CHANNEL_H

/* One 4-byte entry per channel in the WFC network manager's info block. */
#define WFC_INFO_CHANNEL_CALLBACK 0xcc  /* void *: the channel's event callback */
#define WFC_INFO_CHANNEL_OBJECT   0x10c /* void *: the object the callback receives */

/* Completion event handed to a channel's callback. */
#define WFC_EVENT_RESULT      0x02 /* u16 WFC_EVENT_RESULT_* */
#define WFC_EVENT_COMMAND     0x04 /* u16 command the event belongs to */
#define WFC_EVENT_CHANNEL     0x0a /* u16 channel index */
#define WFC_EVENT_DATA        0x0c /* void *payload of a receive event */
#define WFC_EVENT_LENGTH      0x10 /* u16 payload bytes of a receive event */
#define WFC_EVENT_BIT         0x12 /* u16 peer index a receive event applies to */
#define WFC_EVENT_SEQUENCE    0x1a /* u16 start sequence of a send, in 16-bit words */
#define WFC_EVENT_RECV_OBJECT 0x1c /* void *channel state object of a receive event */
#define WFC_EVENT_SEND_OBJECT 0x20 /* void *channel state object of a send event */

/* WFC_EVENT_RESULT values. */
#define WFC_EVENT_RESULT_DONE    0  /* the transfer went through */
#define WFC_EVENT_RESULT_NO_ROOM 10 /* the receiver had no room: send it again */

/* The state object begins with a ring of WFC_CH_SLOT_COUNT transfer slots of
 * WFC_CH_SLOT_SIZE bytes each, led by two u16 player bit masks and followed by
 * the players' data copies; the control fields below start at +0x800. */
#define WFC_CH_SLOT_SIZE     0x200 /* bytes per transfer slot */
#define WFC_CH_SLOT_COUNT    4     /* slots in the ring */
#define WFC_CH_SLOT_INDEX    0x808 /* u16 the ring's current slot */
#define WFC_CH_PLAYER_MASK   0x80e /* u16 bit per connected player */
#define WFC_CH_PAYLOAD_LEN   0x810 /* u16 bytes of one player's data copy */
#define WFC_CH_PARENT_MODE   0x818 /* u16 1 in the host (parent) channel */

/* Channel state object control fields (the four data slots come before them). */
#define WFC_CH_SENT_SEQUENCE 0x800 /* u16[4]: start sequence of each slot's last transfer */
#define WFC_CH_SEND_INDEX    0x80a /* u16 index of the slot whose transfer completed */
#define WFC_CH_SEND_STATE    0x81c /* u16 one of WFC_CH_STATE_* */

/* WFC_CH_SEND_STATE values. */
enum {
    WFC_CH_STATE_IDLE    = 0, /* nothing queued */
    WFC_CH_STATE_SENDING = 1, /* a transfer is in flight */
    WFC_CH_STATE_RETRY   = 4, /* the receiver had no room; the slot is sent again */
    WFC_CH_STATE_FAILED  = 5  /* the channel failed; its owner reports the error */
};

#endif
