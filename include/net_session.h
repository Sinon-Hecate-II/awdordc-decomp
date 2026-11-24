#ifndef NET_SESSION_H
#define NET_SESSION_H

/* Login fields of the WFC session object pointed to by gNetSession. */
#define NET_SESSION_SOCKET         0x00 /* void * the GameSpy GT2 socket, 0 until OpenGameSpySocket opens it */
#define NET_SESSION_RX_BUFFER      0x14 /* s32 receive buffer size handed to the GT2 socket */
#define NET_SESSION_TX_BUFFER      0x18 /* s32 send buffer size handed to the GT2 socket */
#define NET_SESSION_STATE          0x24 /* s32 current NET_STATE_* */
#define NET_SESSION_PREV_STATE     0x28 /* s32 the state the session was in before the last SetNetState */
#define NET_SESSION_LOCAL_PLAYER_ID 0x2c /* u8 this console's player id in the session */
#define NET_SESSION_ANNOUNCING_CLOSE 0x2d /* u8 set while a deliberate GT2 connection close is announced, so the per-peer disconnect handlers skip their reporting path */
#define NET_SESSION_LOGIN_NAME     0x2e /* u16[26], NUL terminated */
#define NET_SESSION_LAST_PLAYER    0x381 /* u8 index of the last entry of the session's player table (+0x468 sockets, +0x644 ids), i.e. the player count minus one: 0 while only this console is in the session */
#define NET_SESSION_MODE           0x389 /* u8 connection mode: 0/1 the console joined, 2/3 it serves the match (the wider event callback is used) */
#define NET_SESSION_PLAYER_SOCKETS 0x468 /* u32[32] GameSpy profile id of each player, parallel to NET_SESSION_PLAYER_IDS */
#define NET_SESSION_PLAYER_IDS     0x644 /* u8[32] player id of each entry in NET_SESSION_PLAYER_SOCKETS */
#define NET_SESSION_CONNECTED_MASK 0x664 /* u32 bitmask of the player ids present in the session */
#define NET_SESSION_LOCAL_SOCKET   0x64 /* u32 this console's own profile id (second argument of the NAS login result), matched against NET_SESSION_PLAYER_SOCKETS to find its player table entry */
#define NET_SESSION_GAME_NAME      0x68 /* char * service name */
#define NET_SESSION_LOGIN_CALLBACK 0x70 /* void (*)(s32 error, s32 profileId, s32 data) */
#define NET_SESSION_LOGIN_DATA     0x74 /* s32 callback data */
#define NET_SESSION_MATCH_CALLBACK 0x78 /* void (*)(s32 event, s32 data, s32 arg): match-making event callback, invoked once the session state has been restored */
#define NET_SESSION_MATCH_DATA     0x7c /* s32 argument passed to the match callback */
#define NET_SESSION_EVENT_CALLBACK 0x80 /* void (*)(s32 event, s32 arg, s32 data): the app's match event callback installed by the host/join entry points */
#define NET_SESSION_EVENT_DATA     0x84 /* s32 argument handed to that callback */
#define NET_SESSION_EVENT_CALLBACK5 0x88 /* void (*)(s32,s32,s32,s32,s32,s32): wider event callback invoked instead of the +0x80 one while the byte at +0x389 is 2 or 3 */
#define NET_SESSION_EVENT_DATA5    0x8c /* s32 argument handed to the wider callback */

/* The session states whose online subsystem reports an operation's error. */
enum {
    NET_STATE_LOGIN         = 2, /* logging in: errors go to the NAS login callback */
    NET_STATE_MATCHMAKING   = 4, /* matchmaking: errors go through ReportMatchSessionError */
    NET_STATE_SESSION       = 5  /* online session: errors go through ReportConnectionError */
};
#define NET_LOGIN_STATUS_DETAIL_BASE   0xFFFF11B8u
#define NET_SESSION_STATUS_DETAIL_BASE 0xFFFEC398u
#define NET_MATCH_STATUS_DETAIL_BASE    0xFFFEEAA8u

#define NET_LOGIN_NAME_MAX         25
#define NET_LOGIN_NAME_BYTES       52

enum {
    NET_CONNECTION_CONNECTED = 4,
    NET_LOGIN_ERROR_CONNECTION = -60010
};

/* The GP info object behind gGpiInfoState: the list of profile records
 * (gGpiInfoProfiles) that the server reports on, the receive buffer, and the
 * logged-in session. */
#define GPI_INFO_PROFILES      0x04 /* Vector * of GpiProfile records */
#define GPI_INFO_SCRATCH_BANK  0x24 /* s32 alternating index of the gGpiProfileScratch bank in use */
#define GPI_INFO_SESSION       0x28 /* void * logged-in session, NULL until login */
/* The logged-in session's bucket store (gbucket) holds the gpi key/value
 * entries keyed by name; the gpiGetOrCreate* helpers look a key up there and
 * add it with the requested type when it is missing. */
#define GPI_SESSION_STORE      0x0C /* void * the session's bucket store */
#define GPI_INFO_USED          0x00 /* s32 bytes used in the receive buffer */
#define GPI_INFO_RECV_BUFFER   0x0C /* u8 * receive buffer, grown as data arrives */
#define GPI_INFO_RECV_CAPACITY 0x2C /* s32 allocated size of the receive buffer */

/* The gpi info connection object (gGpiInfoSocket): the GHI socket the info
 * protocol runs on and the cursor into the XOR key string its messages are
 * encrypted with.  gpiXorInfoMessage walks that cursor from byte to byte and
 * wraps it back to the key's first byte at the NUL that ends the string. */
#define GPI_SOCKET_HANDLE  0x00 /* s32 GHI socket, -1 when the connection is closed */
#define GPI_SOCKET_XOR_KEY 0x08 /* const s8 * next byte of the message XOR key */

/* A GameSpy info string is a run of \key\value\ fields; the gpi info reader
 * (gpiGetInfoField) extracts one value into gGpiProfileScratch.  The gpi reply
 * keys are the gGpiKey* strings in main_02058CA4's data: \lid\, \pid\,
 * \mod\ (modified), \length\, \data\, and the \getpdr\/\setpdr\ result echoes.
 * gGpiEmptyValue is the empty string a missing field yields. */
#define GPI_FIELD_DELIMITER 0x5C /* the backslash between a field's key and value */

/* Fields of a GpiProfile record: a server profile's id and name. */
#define GPI_PROFILE_TYPE        0x00 /* s32 kind of the info request (GPI_PROFILE_, picks the update callback's argument list) */
#define GPI_PROFILE_ID          0x04 /* s32 profile id reported by the server */
#define GPI_PROFILE_PID         0x08 /* s32 the server's profile number (the "lid"/"pid" field) */
#define GPI_PROFILE_NAME        0x0C /* char * profile name, or pad when the record has none */
#define GPI_PROFILE_NAME_PAD    0x10
#define GPI_PROFILE_ONLINE      0x14 /* s32 nonzero when the profile's owner is online */
#define GPI_PROFILE_CALLBACK    0x18 /* void (*)(...) called when the server updates the profile */

/* GPI_PROFILE_TYPE kinds: the update callback's fixed arguments differ. */
enum {
    GPI_PROFILE_STATUS = 0, /* (id, status, online, text, ...) */
    GPI_PROFILE_AUTH,       /* (id, status, lid, pid, online, secret, flags, text, ...) */
    GPI_PROFILE_INFO,       /* (id, status, lid, pid, online, flags, text, ...) */
    GPI_PROFILE_BUDDY       /* (id, status, online, ...) */
};

/* gGpiProfileScratch is two banks of scratch strings holding the field values
 * gpiGetInfoField last returned; GPI_INFO_SCRATCH_BANK alternates 0/1 so the two
 * results stay valid at once.  gGpiEmptyField is the image of an empty field
 * buffer: a delimiter followed by zeros. */
#define GPI_SCRATCH_BANK_BYTES 0x100
#define GPI_SCRATCH_BUFFER(bank) ((u8 *)gGpiProfileScratch + (bank) * GPI_SCRATCH_BANK_BYTES)

#endif
