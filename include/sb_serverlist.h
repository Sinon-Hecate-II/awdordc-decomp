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

/* SB_LIST_QUERY (the QR2 query record) starts with the SBServerList state word. */
#define SB_LIST_STATE_IDLE     SB_SLIST_STATE_IDLE
#define SB_LIST_STATE_QUERYING SB_SLIST_STATE_QUERYING

#define SB_LIST_MAX_FIELDS 20 /* key ids SB_LIST_FIELDS can hold */

/* Fields of the SBServerList object itself (the SBServerList* API's `list`,
 * which the game keeps at SB_LIST_QUERY of its server-browser object). */
#define SB_SLIST_STATE       0x00  /* s32: SB_SLIST_STATE_* */
#define SB_SLIST_SERVERS     0x04  /* Vector *servers found so far */
#define SB_SLIST_GAMENAME    0x0c  /* char[] game name reported to the master */
#define SB_SLIST_SECRETKEY   0x30  /* char[] secret key sent in the connect packet */
#define SB_SLIST_GAMEVERSION 0x54  /* char[] game version reported to the master */
#define SB_SLIST_SOCKET      0x4b0 /* s32 master-server socket, -1 when none */
#define SB_SLIST_QUERY_PORT  0x4b8 /* s32 port the master is queried on */
#define SB_SLIST_CALLBACK    0x488 /* void (*)(list, event, server, instance) */
#define SB_SLIST_INSTANCE    0x494 /* void *instance passed to SB_SLIST_CALLBACK */
#define SB_SLIST_SORT_FIELD  0x498 /* char[] key the server list is sorted on */
#define SB_SLIST_SORT_DESC   0x49c /* s32 nonzero to sort descending */

/* SB_SLIST_STATE values. */
#define SB_SLIST_STATE_IDLE     1 /* disconnected, ready for a new query */
#define SB_SLIST_STATE_QUERYING 3 /* a query is in flight */

#endif
