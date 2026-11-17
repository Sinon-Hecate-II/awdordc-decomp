#ifndef NET_SESSION_H
#define NET_SESSION_H

/* Login fields of the WFC session object pointed to by gNetSession. */
#define NET_SESSION_SOCKET         0x00 /* void * the GameSpy GT2 socket, 0 until OpenGameSpySocket opens it */
#define NET_SESSION_RX_BUFFER      0x14 /* s32 receive buffer size handed to the GT2 socket */
#define NET_SESSION_TX_BUFFER      0x18 /* s32 send buffer size handed to the GT2 socket */
#define NET_SESSION_STATE          0x24 /* s32 current NET_STATE_* */
#define NET_SESSION_LOGIN_NAME     0x2e /* u16[26], NUL terminated */
#define NET_SESSION_GAME_NAME      0x68 /* char * service name */
#define NET_SESSION_LOGIN_CALLBACK 0x70 /* void (*)(s32 error, s32 profileId, s32 data) */
#define NET_SESSION_LOGIN_DATA     0x74 /* s32 callback data */

/* The session states whose online subsystem reports an operation's error. */
enum {
    NET_STATE_LOGIN         = 2, /* logging in: errors go to the NAS login callback */
    NET_STATE_MATCHMAKING   = 4, /* matchmaking: errors go through func_0203accc */
    NET_STATE_SESSION       = 5  /* online session: errors go through func_0203dc38 */
};
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

/* A GameSpy info string is a run of \key\value\ fields; the gpi info reader
 * (gpiGetInfoField) extracts one value into gGpiProfileScratch. */
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
