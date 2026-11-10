/* 4 functions from 0x02050C24 to 0x0205180C (main), found by ds-decomp. */
#include "common.h"

s32 func_02050c24(void **arg0, void *arg1) {
    void *ghiResolveHostname(M2C_UNK *);
    s32 ghiSetNonBlocking(s32, M2C_UNK);
    s32 ghiSocket(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020496e0(s32, M2C_UNK *, M2C_UNK);
    s32 ghiConnect(s32, M2C_UNK *, M2C_UNK);
    s32 func_0204978c(s32);
    s32 func_020498b8(s32, M2C_UNK *, s32 *);
    s32 ghiGetLastSocketError(s32);
    M2C_UNK gpiCallErrorCallback(void **, M2C_UNK, M2C_UNK);
    M2C_UNK gpiSetError(void **, M2C_UNK, M2C_UNK *);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fe1f0;
    extern M2C_UNK data_020fe210;
    extern M2C_UNK data_020fe290;
    extern M2C_UNK data_020fe2b8;
    extern M2C_UNK data_020fe2ec;
    extern M2C_UNK data_020fe314;
    extern M2C_UNK data_020fe340;
    extern M2C_UNK data_020fe370;
    extern M2C_UNK data_020fe3a4;
    extern M2C_UNK data_020fe3c4;
    extern M2C_UNK data_020fe3d4;
    s32 sp8;
    u16 sp6;
    s8 sp5;
    M2C_UNK sp4;
    s32 sp0;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_4;
    s32 temp_r0_5;
    void *temp_r0_3;
    void *temp_r4;

    temp_r4 = *arg0;
    if (M2C_FIELD(temp_r4, s32 *, 0x10C) == 0) {
        temp_r0 = ghiSocket(2, 1, 0);
        M2C_FIELD(temp_r4, s32 *, 0x204) = temp_r0;
        if (temp_r0 == -1) {
            gpiSetError(arg0, 5, &data_020fe290);
            gpiCallErrorCallback(arg0, 3, 1);
            return 3;
        }
        if (ghiSetNonBlocking(temp_r0, 0) == 0) {
            gpiSetError(arg0, 5, &data_020fe2b8);
            gpiCallErrorCallback(arg0, 3, 1);
            return 3;
        }
        M2C_FIELD(&sp4, s32 *, 0) = 0;
        M2C_FIELD(&sp4, s32 *, 4) = 0;
        sp5 = 2;
        if (func_020496e0(M2C_FIELD(temp_r4, s32 *, 0x204), &sp4, 8) == -1) {
            gpiSetError(arg0, 5, &data_020fe2ec);
            gpiCallErrorCallback(arg0, 3, 1);
            return 3;
        }
        if (func_0204978c(M2C_FIELD(temp_r4, s32 *, 0x204)) == -1) {
            gpiSetError(arg0, 5, &data_020fe314);
            gpiCallErrorCallback(arg0, 3, 1);
            return 3;
        }
        sp0 = 8;
        if (func_020498b8(M2C_FIELD(temp_r4, s32 *, 0x204), &sp4, &sp0) == -1) {
            gpiSetError(arg0, 5, &data_020fe340);
            gpiCallErrorCallback(arg0, 3, 1);
            return 3;
        }
        M2C_FIELD(temp_r4, s32 *, 0x208) = (s32) sp6;
        goto block_13;
    }
    M2C_FIELD(temp_r4, s32 *, 0x204) = -1;
    M2C_FIELD(temp_r4, s32 *, 0x208) = 0;
block_13:
    temp_r0_2 = ghiSocket(2, 1, 0);
    M2C_FIELD(temp_r4, s32 *, 0x1D4) = temp_r0_2;
    if (temp_r0_2 == -1) {
        gpiSetError(arg0, 5, &data_020fe290);
        gpiCallErrorCallback(arg0, 3, 1);
        return 3;
    }
    if (ghiSetNonBlocking(temp_r0_2, 0) == 0) {
        gpiSetError(arg0, 5, &data_020fe2b8);
        gpiCallErrorCallback(arg0, 3, 1);
        return 3;
    }
    temp_r0_3 = ghiResolveHostname(&data_020fe210);
    if (temp_r0_3 == NULL) {
        gpiSetError(arg0, 5, &data_020fe370);
        gpiCallErrorCallback(arg0, 3, 1);
        return 3;
    }
    M2C_FIELD(&sp4, s32 *, 0) = 0;
    M2C_FIELD(&sp4, s32 *, 4) = 0;
    sp5 = 2;
    temp_r0_4 = **M2C_FIELD(temp_r0_3, s32 ***, 0xC);
    sp8 = temp_r0_4;
    if (temp_r0_4 == 0) {
        AssertFailed(&data_020fe3a4, &data_020fe3c4, &data_020fe1f0, 0x90);
    }
    sp6 = 0xCC74;
    if (ghiConnect(M2C_FIELD(temp_r4, s32 *, 0x1D4), &sp4, 8) == -1) {
        temp_r0_5 = ghiGetLastSocketError(M2C_FIELD(temp_r4, s32 *, 0x1D4));
        if ((temp_r0_5 != -6) && (temp_r0_5 != -0x1A) && (temp_r0_5 != -0x4C)) {
            gpiSetError(arg0, 5, &data_020fe3d4);
            gpiCallErrorCallback(arg0, 3, 1);
            return 3;
        }
        M2C_FIELD(arg1, s32 *, 0x14) = 1;
        M2C_FIELD(temp_r4, s32 *, 0x1D8) = 1;
        return 0;
    }
    M2C_FIELD(arg1, s32 *, 0x14) = 1;
    M2C_FIELD(temp_r4, s32 *, 0x1D8) = 1;
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
    s32 func_02050c24(void **, void *);
    M2C_UNK gpiDisconnect(void **, M2C_UNK);
    M2C_UNK gpiFinishOperation(void **, void *);
    s32 gpiAddOperation(void **, M2C_UNK, void *, void **, s32, s32, s32);
    M2C_UNK StringCopyN(void *, s8 *, M2C_UNK);
    M2C_UNK gpiSetErrorString(void **, M2C_UNK *);
    M2C_UNK func_02065210(void *, M2C_UNK, M2C_UNK);
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
    func_02065210(peer, 0, 0x308);
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
    status = func_02050c24(conn, newSession);
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

void func_020511dc(void *a, void *b) {
    M2C_UNK func_02050bbc(M2C_UNK, M2C_UNK);
    M2C_UNK Md5Hex(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK StringFormat(M2C_UNK, M2C_UNK, ...);
    M2C_UNK func_02055c68(void **, M2C_UNK, M2C_UNK, M2C_UNK *);
    M2C_UNK gpiAppendStringField(void **, void *, M2C_UNK *);
    M2C_UNK gpiAppendIntField(void **, void *, M2C_UNK);
    extern M2C_UNK data_020fe434, data_020fe43c, data_020fe44c, data_020fe480, data_020fe488, data_020fe494, gGsKeyUniqueNick, data_020fe4b0, data_020fe4b8, data_020fe4bc, data_020fe4c8, data_020fe4d4, data_020fe4e0, data_020fe4ec, gGsKeyProductId, gGsKeyGameName, gGsKeyNamespaceId, gGsKeyId1, gGsKeyFinal, gServiceNameBuffer;
    void **pa = (void **)a;
    void *session = *pa;
    char *r5 = (char *)b;
    char *r7;
    int nameByte;
    int otherByte;
    char buf1[0x52];
    char digest[64];
    void *sp10 = 0;
    int slen;
    func_02050bbc((M2C_UNK)(r5 + 0x80), 0x20);
    nameByte = (signed char) r5[0x100 + 0xc2];
    if (nameByte != 0) {
        r7 = r5 + 0xc2;
    } else {
        otherByte = (signed char) ((char *)session)[0x100 + 0x2f];
        if (otherByte != 0) {
            r7 = (char *)session + 0x2f + 0x100;
        } else {
            StringFormat((M2C_UNK)buf1, (M2C_UNK)&data_020fe434, (M2C_UNK)((char *)session + 0x110), (M2C_UNK)((char *)session + 0x144));
            r7 = buf1;
        }
    }
    r7 = r7 + 0x100;
    slen = 0; while (r7[slen] != 0) slen++;
    Md5Hex((M2C_UNK)r7, slen, (M2C_UNK)digest);
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
            unsigned int low = (unsigned int)M2C_FIELD(session, M2C_UNK *, 0x208) & 0xffffu;
            unsigned int out = ((low >> 8) & 0xff) | ((low << 8) & 0xff00);
            gpiAppendIntField(pa, (void *)((char *)session + 0x1f4), (M2C_UNK)((signed short)(out << 16 >> 16)));
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
}

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
