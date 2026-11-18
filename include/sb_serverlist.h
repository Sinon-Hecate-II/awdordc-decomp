/* The game's GameSpy server-browser object (the "SBServerList" of
 * sb_serverbrowsing), used by the SBServerList* helpers in main_0206080C and
 * main_020617BC.  The game keeps its own bookkeeping first; the QR2 query record
 * the API operates on begins at SB_LIST_QUERY, and the helpers are handed a
 * pointer straight to it. */
#ifndef SB_SERVERLIST_H
#define SB_SERVERLIST_H

#define SB_LIST_PENDING     0x10  /* s32 nonzero while query replies are still awaited */
#define SB_LIST_FIELDS      0x2C  /* u8[SB_LIST_MAX_FIELDS]: key ids asked of the master */
#define SB_LIST_FIELD_COUNT 0x40  /* s32 number of used entries in SB_LIST_FIELDS */
#define SB_LIST_QUERY       0x4C  /* QR2 query record the SBServerList* API works on */
#define SB_LIST_DISCONNECT  0x620 /* s32 disconnect the list once a running query ends */
#define SB_LIST_QUERY_SERVER_IP   0x628 /* s32 address of the server a single-server query is outstanding for, 0 when none */
#define SB_LIST_QUERY_SERVER_PORT 0x62C /* u16 port of that server */
#define SB_LIST_NOTIFY      0x630 /* the application's SBServerListCallback: (list, event, server, instance) */
#define SB_LIST_NOTIFY_DATA 0x634 /* the instance passed as SB_LIST_NOTIFY's last argument */

/* SB_LIST_QUERY (the QR2 query record) starts with the SBServerList state word. */
#define SB_LIST_STATE_IDLE     SB_SLIST_STATE_IDLE
#define SB_LIST_STATE_QUERYING SB_SLIST_STATE_QUERYING

#define SB_LIST_MAX_FIELDS 20 /* key ids SB_LIST_FIELDS can hold */

/* Fields of the SBServerList object itself (the SBServerList* API's `list`,
 * which the game keeps at SB_LIST_QUERY of its server-browser object). */
#define SB_SLIST_STATE       0x00  /* s32: SB_SLIST_STATE_* */
#define SB_SLIST_SERVERS     0x04  /* Vector *servers found so far */
#define SB_SLIST_KEY_LIST    0x08  /* Vector *of SBServerListKey: the announced key schema */
#define SB_SLIST_GAMENAME    0x0c  /* char[] game name reported to the master */
#define SB_SLIST_SECRETKEY   0x30  /* char[] secret key sent in the connect packet */
#define SB_SLIST_GAMEVERSION 0x54  /* char[] game version reported to the master */
#define SB_SLIST_SOCKET      0x4b0 /* s32 master-server socket, -1 when none */
#define SB_SLIST_CRYPT       0x4bc /* GsCryptState of the session's GameSpy stream cipher (qr2.h) */
#define SB_SLIST_QUERY_PORT  0x4b8 /* s32 port the master is queried on */
#define SB_SLIST_CALLBACK    0x488 /* void (*)(list, event, server, instance) */
#define SB_SLIST_INSTANCE    0x494 /* void *instance passed to SB_SLIST_CALLBACK */
#define SB_SLIST_SORT_FIELD  0x498 /* char[] key the server list is sorted on */
#define SB_SLIST_SORT_DESC   0x49c /* s32 nonzero to sort descending */
#define SB_SLIST_START_TICK  0x4b4 /* u32 GetTickCountMs() the 2 s collection window starts at */
#define SB_SLIST_CRYPT_KEY  0x74  /* u8[8] GameSpy cipher key derived from the session challenge */
#define SB_SLIST_RECV_BUFFER 0x7c  /* char *reply buffer (SBServerListConnectAndQuery allocates it) */
#define SB_SLIST_RECV_LENGTH 0x80  /* s32 bytes held in SB_SLIST_RECV_BUFFER */
#define SB_SLIST_ERROR      0x4ac /* char *error message, NULL while none (SBServerListSetErrorString) */

/* One entry of the list's key schema (SB_SLIST_KEY_LIST): a key the master or
 * game server announces, interned, together with the type of the values
 * recorded for it.  Record parsing walks the schema in order and decodes each
 * field's value according to the entry's type. */
#define SB_SLIST_KEY_SIZE 8 /* bytes per key-schema entry */
typedef struct SBServerListKey {
    char *name; /* +0x00 interned key name (StringIntern) */
    s32   type; /* +0x04 GPI_FIELD_* (common.h): how the value is encoded */
} SBServerListKey;

/* One server found by the browser: a gpi player record (0x24 bytes), allocated
 * and filled by SBServerNew, read through the SBServerGet* and gpiPlayer*
 * accessors.  The gpi layer keeps the key/value table at +0x18; the browser
 * keeps the ping and its list of removed servers in the words after it. */
typedef struct GpiPlayer {
    u32 ip;         /* +0x00 address the record was received from */
    u16 port;       /* +0x04 its port, network order */
    u16 pad06;
    u32 address;    /* +0x08 address the server reports for queries */
    u16 queryPort;  /* +0x0C its port, network order */
    u16 pad0E;
    s32 value;      /* +0x10 the record's optional value field */
    u8  state;      /* +0x14 gpi state bits (GPI_PLAYER_STATE_*) and browser state */
    u8  flags;      /* +0x15 gpi record flags (GPI_REC_FLAG_*) */
    u16 pad16;
    s32 keyValues;  /* +0x18 table of the record's interned key/value strings */
    s32 ping;       /* +0x1C last measured round-trip time in ms */
    s32 next;       /* +0x20 next removed server on the browser's free list */
} GpiPlayer; /* 0x24 bytes */

/* Events the list reports through SB_SLIST_CALLBACK:
 * (list, event, server, SB_SLIST_INSTANCE). */
#define SB_LIST_EVENT_SERVER_ADDED   0 /* a server was added to the list */
#define SB_LIST_EVENT_QUERY_COMPLETE 3 /* the running query finished */
#define SB_LIST_EVENT_DISCONNECTED   4 /* the list is being disconnected from the master */
#define SB_LIST_EVENT_QUERY_ERROR    5 /* the master reported an error, see SB_SLIST_ERROR */

/* SB_SLIST_STATE values. */
#define SB_SLIST_STATE_IDLE     1 /* disconnected, ready for a new query */
#define SB_SLIST_STATE_QUERYING 3 /* a query is in flight */

#endif
