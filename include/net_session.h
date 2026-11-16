#ifndef NET_SESSION_H
#define NET_SESSION_H

/* Login fields of the WFC session object pointed to by gNetSession. */
#define NET_SESSION_STATE          0x24 /* s32 current NET_STATE_* */
#define NET_SESSION_LOGIN_NAME     0x2e /* u16[26], NUL terminated */
#define NET_SESSION_GAME_NAME      0x68 /* char * service name */
#define NET_SESSION_LOGIN_CALLBACK 0x70 /* void (*)(s32 error, s32 profileId, s32 data) */
#define NET_SESSION_LOGIN_DATA     0x74 /* s32 callback data */
#define NET_LOGIN_NAME_MAX         25
#define NET_LOGIN_NAME_BYTES       52

enum {
    NET_CONNECTION_CONNECTED = 4,
    NET_LOGIN_ERROR_CONNECTION = -60010
};

#endif
