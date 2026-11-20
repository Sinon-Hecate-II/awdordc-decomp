/* 4 functions from 0x02050C24 to 0x0205180C (main), found by ds-decomp. */
#include "common.h"

#pragma opt_propagation off
/* gpiStartConnect (gpiConnect.c): open the sockets of a new gpi connection.
 * Without a firewall, a local socket is created, made non-blocking, bound to an
 * ephemeral port and its port kept for NAT negotiation.  Then the server socket
 * is created and made non-blocking, the connection manager host name
 * (gpcm.gs.nintendowifi.net) resolved, and the socket connected to the
 * master's GameSpy port.  A failed socket call stores the connection's network
 * error and reports it as fatal.  On success the connection enters the
 * connecting state and the operation is marked as running. */
s32 gpiStartConnect(void **connectionPtr, void *operation) {
    void *ghiResolveHostname(M2C_UNK *);
    s32 ghiSetNonBlocking(s32, M2C_UNK);
    s32 ghiSocket(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 ghiBind(s32, M2C_UNK *, M2C_UNK);
    s32 ghiConnect(s32, M2C_UNK *, M2C_UNK);
    s32 ghiListen(s32);
    s32 ghiGetSockName(s32, M2C_UNK *, s32 *);
    s32 ghiGetLastSocketError(s32);
    M2C_UNK gpiCallErrorCallback(void **, M2C_UNK, M2C_UNK);
    M2C_UNK gpiSetError(void **, M2C_UNK, M2C_UNK *);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK gGpiMasterHostName;
    extern M2C_UNK gpiConnectSocketError;
    extern M2C_UNK gpiConnectNonBlockingError;
    extern M2C_UNK gpiConnectBindError;
    extern M2C_UNK gpiConnectListenError;
    extern M2C_UNK gpiConnectSockNameError;
    extern M2C_UNK gpiConnectResolveError;
    extern M2C_UNK gpiConnectAddressAssert;
    extern M2C_UNK sGpiConnectSourceFile;
    extern M2C_UNK gpiAssertStartConnect;
    extern M2C_UNK gpiConnectConnectError;
    union {
        u32 words[2];
        struct {
            u8 length;
            u8 family;
            u16 port;
            u32 address;
        } fields;
    } addr;
    s32 addrlen;
    s32 bindResult;
    s32 invalid;
    s32 error;
    s32 localSocket;
    s32 serverSocket;
    s32 hostAddress;
    s32 socketError;
    void *hostEntry;
    void *session;

    session = *connectionPtr;
    if (M2C_FIELD(session, s32 *, GPI_CONN_FIREWALL) == 0) {
        localSocket = ghiSocket(2, 1, 0);
        M2C_FIELD(session, s32 *, GPI_CONN_LOCAL_SOCKET) = localSocket;
        if (localSocket == -1) {
            gpiSetError(connectionPtr, 5, &gpiConnectSocketError);
            gpiCallErrorCallback(connectionPtr, 3, 1);
            return 3;
        }
        if (ghiSetNonBlocking(localSocket, 0) == 0) {
            gpiSetError(connectionPtr, 5, &gpiConnectNonBlockingError);
            gpiCallErrorCallback(connectionPtr, 3, 1);
            return 3;
        }
        {
        u32 *words = addr.words;
        words[0] = 0;
        words[1] = 0;
    }
        addr.fields.family = 2;
        bindResult = ghiBind(M2C_FIELD(session, s32 *, GPI_CONN_LOCAL_SOCKET), (M2C_UNK *)&addr, 8);
        invalid = -1;
        error = 5;
        if (bindResult == invalid) {
            gpiSetError(connectionPtr, error, &gpiConnectBindError);
            gpiCallErrorCallback(connectionPtr, 3, 1);
            return 3;
        }
        if (ghiListen(M2C_FIELD(session, s32 *, GPI_CONN_LOCAL_SOCKET)) == -1) {
            gpiSetError(connectionPtr, 5, &gpiConnectListenError);
            gpiCallErrorCallback(connectionPtr, 3, 1);
            return 3;
        }
        addrlen = 8;
        if (ghiGetSockName(M2C_FIELD(session, s32 *, GPI_CONN_LOCAL_SOCKET), (M2C_UNK *)&addr, &addrlen) == -1) {
            gpiSetError(connectionPtr, 5, &gpiConnectSockNameError);
            gpiCallErrorCallback(connectionPtr, 3, 1);
            return 3;
        }
        M2C_FIELD(session, s32 *, GPI_CONN_LOCAL_PORT) = (s32) addr.fields.port;
        goto block_13;
    }
    M2C_FIELD(session, s32 *, GPI_CONN_LOCAL_SOCKET) = -1;
    M2C_FIELD(session, s32 *, GPI_CONN_LOCAL_PORT) = 0;
block_13:
    serverSocket = ghiSocket(2, 1, 0);
    M2C_FIELD(session, s32 *, GPI_CONN_SOCKET) = serverSocket;
    if (serverSocket == -1) {
        gpiSetError(connectionPtr, 5, &gpiConnectSocketError);
        gpiCallErrorCallback(connectionPtr, 3, 1);
        return 3;
    }
    if (ghiSetNonBlocking(serverSocket, 0) == 0) {
        gpiSetError(connectionPtr, 5, &gpiConnectNonBlockingError);
        gpiCallErrorCallback(connectionPtr, 3, 1);
        return 3;
    }
    hostEntry = ghiResolveHostname(&gGpiMasterHostName);
    if (hostEntry == NULL) {
        gpiSetError(connectionPtr, 5, &gpiConnectResolveError);
        gpiCallErrorCallback(connectionPtr, 3, 1);
        return 3;
    }
    {
        u32 *words = addr.words;
        words[0] = 0;
        words[1] = 0;
    }
    addr.fields.family = 2;
    hostAddress = **M2C_FIELD(hostEntry, s32 ***, 0xC);
    addr.fields.address = hostAddress;
    if (hostAddress == 0) {
        AssertFailed(&gpiConnectAddressAssert, &sGpiConnectSourceFile, &gpiAssertStartConnect, 0x90);
    }
    addr.fields.port = GPI_MASTER_PORT;
    if (ghiConnect(M2C_FIELD(session, s32 *, GPI_CONN_SOCKET), (M2C_UNK *)&addr, 8) == -1) {
        socketError = ghiGetLastSocketError(M2C_FIELD(session, s32 *, GPI_CONN_SOCKET));
        if ((socketError != -6) && (socketError != -0x1A) && (socketError != -0x4C)) {
            gpiSetError(connectionPtr, 5, &gpiConnectConnectError);
            gpiCallErrorCallback(connectionPtr, 3, 1);
            return 3;
        }
    }
    M2C_FIELD(operation, s32 *, 0x14) = 1; /* operation->state: the request is now running */
    M2C_FIELD(session, s32 *, GPI_CONN_STATE) = GPI_STATE_CONNECTING;
    return 0;
}
/* Prepare a GPI connection: store the login profile strings (nick, unique nick,
   email, lowercased, password) and an optional peer name/token/CD key in a new
   connection object, then create its operation and open the sockets. */
s32 gpiStartConnection(void **conn, s8 *nick, s8 *uniqnick, s8 *email, s8 *password, s8 *peerNick, s8 *peerUniqNick, s8 *cdKey, s32 firewall, s32 newUser, s32 completionFlag, s32 callback, s32 callbackParam) {
    void *gpiMalloc(M2C_UNK);
    M2C_UNK StringToLower(void *);
    s32 gpiResetConnection(void **);
    s32 gpiThink(void **, s32);
    s32 gpiStartConnect(void **, void *);
    M2C_UNK gpiDisconnect(void **, M2C_UNK);
    M2C_UNK gpiFinishOperation(void **, void *);
    s32 gpiAddOperation(void **, M2C_UNK, void *, void **, s32, s32, s32);
    M2C_UNK StringCopyN(void *, s8 *, M2C_UNK);
    M2C_UNK gpiSetErrorString(void **, M2C_UNK *);
    M2C_UNK MemSet(void *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_020fe3fc;
    extern M2C_UNK data_020fe410;
    extern M2C_UNK data_020fe424;
    void *newSession;
    s32 result;
    s32 status;
    s32 opResult;
    s32 checkResult;
    void *peer;
    void *session;

    session = *conn;
    if (M2C_FIELD(session, s32 *, 0x1D8) == 4) {
        checkResult = gpiResetConnection(conn);
        if (checkResult != 0) {
            return checkResult;
        }
    }
    if (M2C_FIELD(session, s32 *, 0x1D8) != 0) {
        gpiSetErrorString(conn, &data_020fe3fc);
        return 2;
    }
    switch (firewall) {
    case 1: M2C_FIELD(session, volatile s32 *, 0x10C) = 1; break;
    case 0: M2C_FIELD(session, volatile s32 *, 0x10C) = 0; break;
    default: gpiSetErrorString(conn, &data_020fe410); return 2;
    }
    M2C_FIELD(session, s32 *, 0x10C) = 1;
    StringCopyN(session + 0x110, nick, 0x1F);
    StringCopyN(session + 0x12F, uniqnick, 0x15);
    StringCopyN(session + 0x144, email, 0x33);
    StringCopyN(session + 0x177, password, 0x1F);
    StringToLower(session + 0x144);
    peer = gpiMalloc(0x308);
    if (peer == NULL) {
        gpiSetErrorString(conn, &data_020fe424);
        return 1;
    }
    MemSet(peer, 0, 0x308);
    M2C_FIELD(peer, s32 *, 0x304) = newUser;
    if ((*peerNick != 0) && (*peerUniqNick != 0)) {
        StringCopyN(peer + 0xC2, peerNick, 0x100);
        StringCopyN(peer + 0x1C2, peerUniqNick, 0x100);
    }
    if (cdKey != NULL) {
        StringCopyN(peer + 0x2C2, cdKey, 0x41);
    }
    opResult = gpiAddOperation(conn, 0, peer, &newSession, completionFlag, callback, callbackParam);
    if (opResult != 0) {
        return opResult;
    }
    status = gpiStartConnect(conn, newSession);
    if (status != 0) {
        M2C_FIELD(newSession, s32 *, 0x1C) = status;
        gpiFinishOperation(conn, newSession);
        gpiDisconnect(conn, 0);
        return status;
    }
    if (M2C_FIELD(newSession, s32 *, 8) != 0) {
        result = gpiThink(conn, M2C_FIELD(newSession, s32 *, 0x18));
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
s32 func_020511dc(void *a, void *b) {
    M2C_UNK func_02050bbc(M2C_UNK, M2C_UNK);
    u32 StringLength(void *);
    M2C_UNK Md5Hex(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK StringFormat(M2C_UNK, M2C_UNK, ...);
    M2C_UNK func_02055c68(void **, M2C_UNK, M2C_UNK, M2C_UNK *);
    M2C_UNK gpiAppendStringField(void **, void *, M2C_UNK *);
    M2C_UNK gpiAppendIntField(void **, void *, M2C_UNK);
    extern M2C_UNK data_020fe434, data_020fe43c, data_020fe44c, data_020fe480, data_020fe488, data_020fe494, gGsKeyUniqueNick, data_020fe4b0, data_020fe4b8, data_020fe4bc, data_020fe4c8, data_020fe4d4, data_020fe4e0, data_020fe4ec, gGsKeyProductId, gGsKeyGameName, gGsKeyNamespaceId, gGsKeyId1, gGsKeyFinal, gServiceNameBuffer;
    void **pa = (void **)a;
    void *session = *pa;
    char *r5 = (char *)b;
    register char *r7;
    u32 length;
    void *sp10;
    char digest[0x21];
    char response[0x200];
    char buf1[0x52];
    char *identity;
    func_02050bbc((M2C_UNK)(r5 + 0x80), 0x20);
    r7 = r5[0x1c2] ? r5 + 0x1c2 : (char *)session + 0x177;
    length = StringLength(r7);
    Md5Hex((M2C_UNK)r7, length, (M2C_UNK)(r5 + 0xa1));
    if (r5[0xc2]) {
        identity = r5 + 0xc2;
    } else if (((char *)session)[0x12f]) {
        identity = (char *)session + 0x2f + 0x100;
    } else {
        StringFormat((M2C_UNK)buf1, (M2C_UNK)&data_020fe434, (char *)session + 0x110, (char *)session + 0x144);
        identity = buf1;
    }
    StringFormat((M2C_UNK)response, (M2C_UNK)&data_020fe43c, r5 + 0xa1, &data_020fe44c, identity, r5 + 0x80, r5, r5 + 0xa1);
    length = StringLength(response);
    Md5Hex((M2C_UNK)response, length, (M2C_UNK)digest);
    if (*((M2C_UNK *)((char *)session + 0x100)) != 0) {
        func_02055c68(pa, (M2C_UNK)((char *)session + 0x110), (M2C_UNK)((char *)session + 0x144), (M2C_UNK *)&sp10);
        if (sp10 != 0) {
            M2C_FIELD(session, M2C_UNK *, 0x19c) = M2C_FIELD(sp10, M2C_UNK *, 0x4);
            M2C_FIELD(session, M2C_UNK *, 0x1a0) = M2C_FIELD(sp10, M2C_UNK *, 0x0);
        }
    }
    gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &data_020fe480);
    gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &data_020fe488);
    gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK *)(r5 + 0x80));
    if ((signed char) r5[0xc2] != 0) {
        gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &data_020fe494);
        gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK *)(r5 + 0xc2));
    } else {
        if ((signed char) ((char *)session)[0x100 + 0x2f] != 0) {
            gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &gGsKeyUniqueNick);
            gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK *)((char *)session + 0x12f));
        } else {
            gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &data_020fe4b0);
            gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK *)((char *)session + 0x110));
            gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &data_020fe4b8);
            gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK *)((char *)session + 0x144));
        }
    }
    if (M2C_FIELD(session, M2C_UNK *, 0x19c) != 0) {
        gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &data_020fe4bc);
        gpiAppendIntField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK)M2C_FIELD(session, M2C_UNK *, 0x19c));
    }
    if (M2C_FIELD(session, M2C_UNK *, 0x1a0) != 0) {
        gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &data_020fe4c8);
        gpiAppendIntField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK)M2C_FIELD(session, M2C_UNK *, 0x1a0));
    }
    gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &data_020fe4d4);
    gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK *)digest);
    if (M2C_FIELD(session, M2C_UNK *, 0x10c) == 1) {
        gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &data_020fe4e0);
        gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &data_020fe4ec);
        {
            u16 low = (u16)M2C_FIELD(session, M2C_UNK *, 0x208);
            u16 out = ((low >> 8) & 0xff) | ((low << 8) & 0xff00);
            gpiAppendIntField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK)((s16)out));
        }
    }
    gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &gGsKeyProductId);
    gpiAppendIntField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK)M2C_FIELD(session, M2C_UNK *, 0x46c));
    gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &gGsKeyGameName);
    gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &gServiceNameBuffer);
    gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &gGsKeyNamespaceId);
    gpiAppendIntField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK)M2C_FIELD(session, M2C_UNK *, 0x470));
    gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &gGsKeyId1);
    gpiAppendStringField(pa, (void *)((char *)session + 0x1f4), &gGsKeyFinal);
    return 0;
}
#pragma opt_common_subs reset
#pragma push
#pragma opt_propagation off
/* Builds the GameSpy "newuser" request: encrypts the password and (if given)
   the CD key with the gspy keystream and base64, then appends all profile
   fields (email, nick, ids, game name...) to the outgoing request buffer. */
s32 SendNewUserProfile(void **conn, void *params) {
    M2C_UNK SeedRandom(s32);
    s8 RandomRange(M2C_UNK, M2C_UNK);
    M2C_UNK gpiAppendStringField(void **, void *, M2C_UNK *);
    M2C_UNK Base64Encode(s8 *, M2C_UNK *, u32, M2C_UNK);
    M2C_UNK gpiAppendIntField(void **, void *, s32);
    u32 StringLength(void *);

    extern M2C_UNK gGsKeyUniqueNick;
    extern M2C_UNK gGsKeyProductId;
    extern M2C_UNK gGsKeyGameName;
    extern M2C_UNK gGsKeyNamespaceId;
    extern M2C_UNK gGsKeyId1;
    extern M2C_UNK gGsKeyFinal;
    extern M2C_UNK gGsKeyNewUser;
    extern M2C_UNK gGsKeyEmail;
    extern M2C_UNK gGsKeyNick;
    extern M2C_UNK gGsKeyPasswordEnc;
    extern M2C_UNK gGsKeyCdKeyEnc;
    extern M2C_UNK gServiceNameBuffer;

    s8 passwordBytes[0x1F];
    s8 passwordEnc[0x2D];
    s8 cdkeyBytes[0x42];
    s8 cdkeyEnc[0x5A];

    void *session;
    register void *src2;
    u32 i;
    u32 cdkeyLen;
    s8 *q;
    u32 passwordLen;
    s8 *p;
    u32 j;
    s8 *src;
    s8 randByte;

    session = *conn;
    passwordLen = StringLength(session + 0x177);
    SeedRandom(0x79707367);
    i = 0;
    if (passwordLen > i) {
        p = passwordBytes;
        do {
            randByte = (s8)((s32 (*)(s32,s32))RandomRange)(0,0xFF);
            src = (s8 *)(session + i + 0x100);
            i += 1;
            *p = (s8)((s8)M2C_FIELD(src, s8 *, 0x77) ^ randByte);
            p += 1;
        } while (i < passwordLen);
    }
    passwordBytes[i] = 0;
    Base64Encode(passwordBytes, passwordEnc, passwordLen, 1);
    gpiAppendStringField(conn, session + 0x1F4, &gGsKeyNewUser);
    gpiAppendStringField(conn, session + 0x1F4, &gGsKeyEmail);
    gpiAppendStringField(conn, session + 0x1F4, session + 0x144);
    gpiAppendStringField(conn, session + 0x1F4, &gGsKeyNick);
    gpiAppendStringField(conn, session + 0x1F4, session + 0x110);
    gpiAppendStringField(conn, session + 0x1F4, &gGsKeyPasswordEnc);
    gpiAppendStringField(conn, session + 0x1F4, (M2C_UNK *)passwordEnc);
    gpiAppendStringField(conn, session + 0x1F4, &gGsKeyProductId);
    gpiAppendIntField(conn, session + 0x1F4, M2C_FIELD(session, s32 *, 0x46C));
    gpiAppendStringField(conn, session + 0x1F4, &gGsKeyGameName);
    gpiAppendStringField(conn, session + 0x1F4, &gServiceNameBuffer);
    gpiAppendStringField(conn, session + 0x1F4, &gGsKeyNamespaceId);
    gpiAppendIntField(conn, session + 0x1F4, M2C_FIELD(session, s32 *, 0x470));
    gpiAppendStringField(conn, session + 0x1F4, &gGsKeyUniqueNick);
    gpiAppendStringField(conn, session + 0x1F4, session + 0x12F);
    if (M2C_FIELD(params, s8 *, 0x2C2) != 0) {
        cdkeyLen = StringLength(params + 0x2C2);
        SeedRandom(0x79707367);
        j = 0;
        if (cdkeyLen > j) {
            q = cdkeyBytes;
            do {
                randByte = (s8)((s32 (*)(s32,s32))RandomRange)(0,0xFF);
                src2 = params + j + 0x200;
                j += 1;
                *q = (s8)((s8)M2C_FIELD(src2, s8 *, 0xC2) ^ randByte);
                q += 1;
            } while (j < cdkeyLen);
        }
        cdkeyBytes[j] = 0;
        Base64Encode(cdkeyBytes, (s8 *)cdkeyEnc, cdkeyLen, 1);
        gpiAppendStringField(conn, session + 0x1F4, &gGsKeyCdKeyEnc);
        gpiAppendStringField(conn, session + 0x1F4, (M2C_UNK *)cdkeyEnc);
    }
    gpiAppendStringField(conn, session + 0x1F4, &gGsKeyId1);
    gpiAppendStringField(conn, session + 0x1F4, &gGsKeyFinal);
    return 0;
}
#pragma pop
