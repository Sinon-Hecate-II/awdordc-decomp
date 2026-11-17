/* 18 functions from 0x020543E8 to 0x020553C4 (main), found by ds-decomp. */
#include "common.h"
typedef struct CallbackPair { s32 first, second; } CallbackPair;

void func_020543e8(void **arg0, void *arg1) {
    M2C_UNK func_020496b8(s32);
    M2C_UNK func_020496cc(s32, M2C_UNK);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fe9b0;
    extern M2C_UNK data_020fea00;
    extern M2C_UNK data_020fea4c;
    s32 temp_r0;
    void *temp_r2;
    void *temp_r5;

    temp_r2 = *arg0;
    if (M2C_FIELD(arg1, s32 *, 0) == 3) {
        temp_r5 = M2C_FIELD(arg1, void **, 4);
        temp_r0 = M2C_FIELD(temp_r2, s32 *, 0x210) - 1;
        M2C_FIELD(temp_r2, s32 *, 0x210) = temp_r0;
        if (temp_r0 < 0) {
            AssertFailed(&data_020fea4c, &data_020fea00, &data_020fe9b0, 0xB6);
        }
        func_020496cc(M2C_FIELD(temp_r5, s32 *, 4), 2);
        func_020496b8(M2C_FIELD(temp_r5, s32 *, 4));
        gpiFree(M2C_FIELD(temp_r5, void **, 0x18));
        M2C_FIELD(temp_r5, void **, 0x18) = NULL;
        gpiFree(M2C_FIELD(temp_r5, void **, 8));
        M2C_FIELD(temp_r5, void **, 8) = NULL;
    }
    gpiFree(M2C_FIELD(arg1, void **, 4));
    M2C_FIELD(arg1, void **, 4) = NULL;
    gpiFree(arg1);
}

void func_02054484(void **a,void *b) {
 void *base=*a; void *prev=NULL; void *p=M2C_FIELD(base,void **,0x424);
 while(p) {if(p==b) {if(!prev) M2C_FIELD(base,void **,0x424)=M2C_FIELD(p,void **,32); else M2C_FIELD(prev,void **,32)=M2C_FIELD(b,void **,32); func_020543e8(a,b); return;} prev=p; p=M2C_FIELD(p,void **,32);}
}

s32 func_020544d4(void **arg0, void **arg1, s32 arg2) {
    void *var_r3;

    var_r3 = M2C_FIELD(*arg0, void **, 0x424);
    if (var_r3 != NULL) {
loop_1:
        if (M2C_FIELD(var_r3, s32 *, 0x18) == arg2) {
            if (arg1 != NULL) {
                *arg1 = var_r3;
            }
            return 1;
        }
        var_r3 = M2C_FIELD(var_r3, void **, 0x20);
        if (var_r3 == NULL) {
            goto block_6;
        }
        goto loop_1;
    }
block_6:
    if (arg1 != NULL) {
        *arg1 = NULL;
    }
    return 0;
}

s32 func_02054520(void **a) {
 void *p=M2C_FIELD(*a,void **,0x424);
 while(p) {if(M2C_FIELD(p,s32 *,8)!=0 && M2C_FIELD(p,s32 *,0)!=3) return 1; p=M2C_FIELD(p,void **,32);}
 return 0;
}

void *func_0205455c(void **a,void *b,s32 c) {
 void *func_0205180c(void **,void *,s32);
 void *gpiProcessNewPlayer(void **,void *,s32);
 void *func_02052600(void **,void *,s32);
 void *gpiProcessLoginReply(void **,void *,s32);
 M2C_UNK gpiLogMessage(void **,M2C_UNK *,...);
 extern M2C_UNK data_020fea6c,data_020fea48,data_020fea00,data_020fe9d8;
 void *p=NULL;
 switch(M2C_FIELD(b,u32 *,0)) {
 case 0:p=func_0205180c(a,b,c);break;
 case 1:p=gpiProcessNewPlayer(a,b,c);break;
 case 2:p=func_02052600(a,b,c);break;
 case 4:p=gpiProcessLoginReply(a,b,c);break;
 default:gpiLogMessage(a,&data_020fea6c,M2C_FIELD(b,u32 *,0));AssertFailed(&data_020fea48,&data_020fea00,&data_020fe9d8,326);break;
 }
 if(p) M2C_FIELD(b,void **,28)=p;
 return p;
}

/* Per-frame step of a gpi peer that is being connected: open the socket, build
 * the \auth\ request (pid, nick, signature from the buddy record) once TCP is up,
 * read the peer's reply and check it for \aack\/\anack\, then move the peer on to
 * the next state and flush whatever text is waiting in its send buffer. */
s32 gpiPeerProcessConnecting(M2C_UNK a,void *peer) {
 s32 gpiPeerBeginConnect(M2C_UNK,void *);
 s32 gpiCheckConnectionSocket(M2C_UNK,s32,s32 *);
 s32 gpiFindBuddyStatus(M2C_UNK,s32,void **);
 s32 gpiSetErrorString(void **,M2C_UNK *);
 M2C_UNK gpiAppendStringField(M2C_UNK,M2C_UNK,M2C_UNK);
 M2C_UNK gpiAppendIntField(M2C_UNK,M2C_UNK,s32);
 s32 gpiReceiveData(void **,s32,void *,s32 *,s32 *,M2C_UNK *);
 s32 gpiSendFromBuffer(void **,s32,void *,s32 *,s32,M2C_UNK *);
 s32 StringFind(M2C_UNK,M2C_UNK);
 s32 StringCompareN(M2C_UNK,M2C_UNK,s32);
 s32 gpiStartPeerChallenge(M2C_UNK,void *);
 s32 gpiPeerConnectionDone(void *);void gpiFreeBuddyList(M2C_UNK,void *);
 extern M2C_UNK gGpiErrorConnectPeer,gGsKeyAuth,gGsKeyPid,gGsKeyNickAuth,gGsKeySig,gGsKeyFinalAuth,data_020febb0,gGsKeyAuthNack,data_020febbc,gGsKeyAuthAck,data_020febe8,data_020fec08,data_020fec0c,data_020feb48;
 void *session=*(void **)a;
 s32 status,bytes,io,rc,clear;
 void *buddy,*p,*end,*text;
 switch(M2C_FIELD(peer,s32 *,0)) {
 case GPI_PEER_STATE_CHALLENGED:break;
 case GPI_PEER_STATE_PROGRESSING:
 rc=gpiPeerBeginConnect(a,peer);if(rc)return rc;
 break;
 case GPI_PEER_STATE_CONNECTING:
 rc=gpiCheckConnectionSocket(a,M2C_FIELD(peer,s32 *,8),&status);if(rc)return rc;
 if(status==4){gpiSetErrorString((void **)a,&gGpiErrorConnectPeer);return 3;}
 if(status!=3)break;
 clear=1;
 if(!gpiFindBuddyStatus(a,M2C_FIELD(peer,s32 *,12),&buddy)){gpiSetErrorString((void **)a,&gGpiErrorConnectPeer);return 3;}
 gpiAppendStringField(a,(M2C_UNK)(peer+0x28),(M2C_UNK)&gGsKeyAuth);
 gpiAppendStringField(a,(M2C_UNK)(peer+0x28),(M2C_UNK)&gGsKeyPid);
 gpiAppendIntField(a,(M2C_UNK)(peer+0x28),M2C_FIELD(session,s32 *,0x1a0));
 gpiAppendStringField(a,(M2C_UNK)(peer+0x28),(M2C_UNK)&gGsKeyNickAuth);
 gpiAppendStringField(a,(M2C_UNK)(peer+0x28),(M2C_UNK)(session+0x110));
 gpiAppendStringField(a,(M2C_UNK)(peer+0x28),(M2C_UNK)&gGsKeySig);
 gpiAppendStringField(a,(M2C_UNK)(peer+0x28),M2C_FIELD(buddy,s32 *,0x18));
 gpiAppendStringField(a,(M2C_UNK)(peer+0x28),(M2C_UNK)&gGsKeyFinalAuth);
 /* Another peer for the same player that is still connecting shares the buddy's
  * \sig\, so leave the buddy record for it instead of completing it here. */
 for(p=M2C_FIELD(session,void **,0x434);p;p=M2C_FIELD(p,void **,0x3c))
 if(M2C_FIELD(p,s32 *,12)==M2C_FIELD(peer,s32 *,12) && p!=peer && M2C_FIELD(p,s32 *,0)<=103)clear=0;
 if(clear) {
 gpiFree(M2C_FIELD(buddy,void **,0x18));M2C_FIELD(buddy,void **,0x18)=NULL;
 if(gpiPeerConnectionDone(buddy))gpiFreeBuddyList(a,buddy);
 }
 M2C_FIELD(peer,s32 *,0)=GPI_PEER_STATE_WAITING;
 break;
 case GPI_PEER_STATE_WAITING:
 rc=gpiReceiveData((void **)a,M2C_FIELD(peer,s32 *,8),peer+0x18,&bytes,&io,&data_020febb0);if(rc)return rc;
 end=(void *)StringFind(M2C_FIELD(peer,s32 *,0x18),(M2C_UNK)&gGsKeyFinalAuth);
 if(!end)break;
 *(u8 *)end=0;text=M2C_FIELD(peer,void **,0x18);
 if(StringCompareN((M2C_UNK)text,(M2C_UNK)&gGsKeyAuthNack,7)==0) {
 M2C_FIELD(peer,s32 *,0x14)++;
 if(M2C_FIELD(peer,s32 *,0x14)>1){gpiSetErrorString((void **)a,&data_020febbc);return 3;}
 rc=gpiStartPeerChallenge(a,peer);if(rc)return rc;
 } else if(StringCompareN((M2C_UNK)text,(M2C_UNK)&gGsKeyAuthAck,6)!=0) {
 gpiSetErrorString((void **)a,&data_020febe8);return 3;
 }
 M2C_FIELD(peer,s32 *,0)=GPI_PEER_STATE_CONNECTED;M2C_FIELD(peer,s32 *,0x20)=0;
 break;
 default:
 AssertFailed(&data_020fec08,&data_020fec0c,&data_020feb48,0x9f);
 break;
 }
 if(M2C_FIELD(peer,s32 *,0x30)>0) {
 rc=gpiSendFromBuffer((void **)a,M2C_FIELD(peer,s32 *,8),peer+0x28,&io,1,&data_020febb0);
 if(io || rc)M2C_FIELD(peer,s32 *,0)=GPI_PEER_STATE_ERROR;
 }
 return 0;
}

#pragma push
#pragma opt_common_subs off
/* Handles a peer waiting for its connection answer: reads the \auth\ reply from
 * the peer, checks its \sig\ signature against the MD5 of the session text, sends
 * \aack\ or \anack\, then marks the peer connected with the reply's player id. */
s32 gpiProcessPeerAcceptingConnection(M2C_UNK a, void *b) {
    void *gpiMalloc(M2C_UNK);
    s32 Md5Hex(M2C_UNK, s32, M2C_UNK);
    s32 gpiStringDup(s32);
    s32 gpiGetTime(M2C_UNK);
    M2C_UNK gpiAppendStringField(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 gpiReceiveData(void **, s32, void *, s32 *, s32 *, M2C_UNK *);
    s32 gpiValueForKey(M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    M2C_UNK StringFormat(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 StringLength(M2C_UNK);
    M2C_UNK StringCompare(M2C_UNK, M2C_UNK);
    s32 StringCompareN(M2C_UNK, M2C_UNK, s32);
    M2C_UNK ParseInt(M2C_UNK);
    M2C_UNK StringFind(M2C_UNK, M2C_UNK);

    extern M2C_UNK data_020fec18, data_020fec0c, data_020feb24, data_020febb0, gGsKeyFinalAuth;
    extern M2C_UNK gGsKeyAuth, gGsKeyPid, gGsKeyNickAuth, gGsKeySig, gGsAuthSigFormat;
    extern M2C_UNK gGsKeyAuthNack, gGsKeyAuthAck;

    void **gpi = (void **)a;
    void *session = *gpi;
    s32 bytesRead;
    s32 ioStatus;
    char authText[0x100];
    char pidText[0x10];
    char nickText[0x1f];
    char peerSig[0x21];
    char localSig[0x21];
    void *text;
    void *tagEnd;
    s32 playerId;
    s32 textLen;
    s32 ioResult;

    if (M2C_FIELD(b, s32 *, 0) != GPI_PEER_STATE_WAITING) {
        AssertFailed(&data_020fec18, &data_020fec0c, &data_020feb24, 0xc1);
    }

    ioResult = gpiReceiveData(gpi, M2C_FIELD(b, s32 *, 8), (void *)((char *)b + 0x18), &bytesRead, &ioStatus, &data_020febb0);
    if (ioResult != 0) {
        return ioResult;
    }
    if (ioStatus != 0) {
        M2C_FIELD(b, s32 *, 0) = GPI_PEER_STATE_ERROR;
        return 0;
    }

    text = M2C_FIELD(b, void **, 0x18);
    tagEnd = (void *)StringFind((M2C_UNK)text, (M2C_UNK)&gGsKeyFinalAuth);
    if (tagEnd == NULL) goto end;

    *((char *)tagEnd) = 0;
    text = M2C_FIELD(b, void **, 0x18);

    if (StringCompareN((M2C_UNK)text, (M2C_UNK)&gGsKeyAuth, 6) != 0) goto fail_end_0x794;

    if (gpiValueForKey((M2C_UNK)text, (M2C_UNK)&gGsKeyPid, (M2C_UNK)pidText, 0x10) == 0) {
        M2C_FIELD(b, s32 *, 0) = GPI_PEER_STATE_ERROR;
        return 0;
    }

    playerId = (s32)ParseInt((M2C_UNK)pidText);

    if (gpiValueForKey((M2C_UNK)M2C_FIELD(b, void **, 0x18), (M2C_UNK)&gGsKeyNickAuth, (M2C_UNK)nickText, 0x1f) == 0) {
        M2C_FIELD(b, s32 *, 0) = GPI_PEER_STATE_ERROR;
        return 0;
    }

    if (gpiValueForKey((M2C_UNK)M2C_FIELD(b, void **, 0x18), (M2C_UNK)&gGsKeySig, (M2C_UNK)peerSig, 0x21) == 0) {
        M2C_FIELD(b, s32 *, 0) = GPI_PEER_STATE_ERROR;
        return 0;
    }

    StringFormat((M2C_UNK)authText, (M2C_UNK)&gGsAuthSigFormat, (M2C_UNK)((char *)session + 0x177), (M2C_UNK)M2C_FIELD(session, s32 *, 0x1a0), (M2C_UNK)playerId);

    textLen = StringLength((M2C_UNK)authText);
    Md5Hex((M2C_UNK)authText, textLen, (M2C_UNK)localSig);

    if (StringCompare((M2C_UNK)peerSig, (M2C_UNK)localSig) != 0) {
        gpiAppendStringField((M2C_UNK)gpi, (M2C_UNK)((char *)b + 0x28), (M2C_UNK)&gGsKeyAuthNack);
        gpiAppendStringField((M2C_UNK)gpi, (M2C_UNK)((char *)b + 0x28), (M2C_UNK)&gGsKeyFinalAuth);
        M2C_FIELD(b, s32 *, 0) = GPI_PEER_STATE_ERROR;
        return 0;
    }
    gpiAppendStringField((M2C_UNK)gpi, (M2C_UNK)((char *)b + 0x28), (M2C_UNK)&gGsKeyAuthAck);
    gpiAppendStringField((M2C_UNK)gpi, (M2C_UNK)((char *)b + 0x28), (M2C_UNK)&gGsKeyFinalAuth);
    M2C_FIELD(b, s32 *, 0) = GPI_PEER_STATE_CONNECTED;
    M2C_FIELD(b, s32 *, 12) = playerId;
    goto finish;
fail_end_0x794:
    M2C_FIELD(b, s32 *, 0) = GPI_PEER_STATE_ERROR;
    return 0;
finish:
    M2C_FIELD(b, s32 *, 0x20) = 0;
end:
    return 0;
}
#pragma pop
/* Send the send buffers queued on a gpi peer: hand each GPISendBuffer at the
 * front of the peer's queue to the socket and drop it once it has gone out
 * completely, stopping at the first one only partly sent.  A write error or a
 * blocked send puts the peer in the error state.  Nothing is sent while the
 * peer still has queued text of its own (+0x30). */
s32 gpiSendQueuedMessages(void **gpi, void *peer) {
    s32 Vector_GetCount(s32);
    void *Vector_GetItem(s32, s32);
    M2C_UNK Vector_RemoveItem(s32, s32);
    s32 gpiSendFromBuffer(void **, s32, void *, s32 *, s32, M2C_UNK *);
    extern M2C_UNK data_020febb0;
    s32 wouldBlock;
    GPISendBuffer *queued;
    s32 result;

    if (M2C_FIELD(peer, s32 *, 0x30)) return 0;
    while (Vector_GetCount(M2C_FIELD(peer, s32 *, 0x38))) {
        queued = Vector_GetItem(M2C_FIELD(peer, s32 *, 0x38), 0);
        result = gpiSendFromBuffer(gpi, M2C_FIELD(peer, s32 *, 8), queued, &wouldBlock, 0, &data_020febb0);
        if (wouldBlock || result) {
            M2C_FIELD(peer, s32 *, 0) = GPI_PEER_STATE_ERROR;
            return 0;
        }
        if (queued->pos != queued->len) break;
        Vector_RemoveItem(M2C_FIELD(peer, s32 *, 0x38), 0);
    }
    return 0;
}

/* Advance one connected gpi peer: flush its queued output, read the peer
 * socket, then parse each incoming message and queue the player events it
 * carries (player announcement, challenge reply, game data). */
s32 gpiProcessPeer(void **gpi, void *peer) {
    void *gpiMalloc(M2C_UNK);
    s32 gpiStringDup(s32);
    s32 gpiGetTime(M2C_UNK);
    M2C_UNK gpiSendMessageToPlayer(void **, s32, M2C_UNK, M2C_UNK *);
    s32 gpiReceiveData(void **, s32, void *, s32 *, s32 *, M2C_UNK *);
    s32 gpiSendFromBuffer(void **, s32, void *, s32 *, s32, M2C_UNK *);
    s32 gpiReadMessageFromPeer(void **, void *, s32 *, s32 *, s32 *);
    M2C_UNK gpiConsumeReadBuffer(void **, void *);
    s32 gpiAddCallback(void **, CallbackPair, void *, s32, s32);
    s32 gpiSendQueuedMessages(void **, void *);
    M2C_UNK func_02057f74(void **, void *, s32, s32, s32, s32);
    M2C_UNK gpiSetErrorString(void **, M2C_UNK *);
    extern M2C_UNK data_020febb0;
    extern M2C_UNK gpiErrorOutOfMemory;
    extern M2C_UNK gpiChallengeReply;
    s32 bytesRead;
    s32 ioStatus;
    CallbackPair playerCallback;
    s32 message;
    s32 messageType;
    s32 messageLength;
    s32 callbackResult;
    s32 readResult;
    s32 sendQueuedResult;
    s32 sendResult;
    s32 callbackFn;
    void *eventData;
    void *conn;

    conn = *gpi;
    if (M2C_FIELD(peer, s32 *, 0x30) != 0) {
        sendResult = gpiSendFromBuffer(gpi, M2C_FIELD(peer, s32 *, 8), peer + 0x28, &ioStatus, 1, &data_020febb0);
        if ((ioStatus == 0) && (sendResult == 0)) {
            goto block_5;
        }
        M2C_FIELD(peer, s32 *, 0) = GPI_PEER_STATE_ERROR;
        return 0;
    }
block_5:
    if (M2C_FIELD(peer, s32 *, 0x30) == 0) {
        sendQueuedResult = gpiSendQueuedMessages(gpi, peer);
        if (sendQueuedResult != 0) {
            return sendQueuedResult;
        }
        if (M2C_FIELD(peer, s32 *, 0) == GPI_PEER_STATE_ERROR) {
            return 0;
        }
        goto block_10;
    }
block_10:
    if (gpiReceiveData(gpi, M2C_FIELD(peer, s32 *, 8), peer + 0x18, &bytesRead, &ioStatus, &data_020febb0) != 0) {
        M2C_FIELD(peer, s32 *, 0) = GPI_PEER_STATE_ERROR;
        return 0;
    }
    if (bytesRead > 0) {
        M2C_FIELD(peer, s32 *, 0x10) = (s32) (gpiGetTime(0) + 0x12C);
    }
loop_15:
    readResult = gpiReadMessageFromPeer(gpi, peer + 0x18, &message, &messageType, &messageLength);
    if (readResult != 0) {
        return readResult;
    }
    if (message != 0) {
        switch (messageType) {
        case GPI_MSG_PLAYER_INFO:
                callbackFn = M2C_FIELD(conn, s32 *, 0x1BC);
                playerCallback.first = callbackFn;
                playerCallback.second = M2C_FIELD(conn, s32 *, 0x1C0);
                if (callbackFn != 0) {
                    eventData = gpiMalloc(0xC);
                    if (eventData == NULL) {
                        gpiSetErrorString(gpi, &gpiErrorOutOfMemory);
                        return 1;
                    }
                    M2C_FIELD(eventData, s32 *, 0) = (s32) M2C_FIELD(peer, s32 *, 0xC);
                    M2C_FIELD(eventData, s32 *, 8) = gpiStringDup(message);
                    M2C_FIELD(eventData, s32 *, 4) = gpiGetTime(0);
                    callbackResult = gpiAddCallback(gpi, playerCallback, eventData, 0, 2);
                    if (callbackResult != 0) {
                        return callbackResult;
                    }
                    }

            break;
        case GPI_MSG_CHALLENGE:
            gpiSendMessageToPlayer(gpi, M2C_FIELD(peer,s32 *,0xc),GPI_MSG_CHALLENGE_REPLY,&gpiChallengeReply);
            break;
        case 200: case 201: case 202: case 203: case 204: case 205: case 206: case 207: case 208:
            func_02057f74(gpi,peer,messageType,M2C_FIELD(peer,s32 *,0x18),message,messageLength);
            break;
        default: break;
        }
block_41:
        gpiConsumeReadBuffer(gpi, peer + 0x18);
        goto block_42;
    }
block_42:
    if (message == 0) {
        if (ioStatus != 0) {
            M2C_FIELD(peer, s32 *, 0) = GPI_PEER_STATE_ERROR;
        }
        return 0;
    }
    goto loop_15;
}

s32 func_02054f0c(M2C_UNK a,void *b) {
 s32 gpiPeerProcessConnecting(M2C_UNK,void *);
 s32 gpiProcessPeerAcceptingConnection(M2C_UNK,void *);
 s32 gpiProcessPeer(void **,void *);
 extern M2C_UNK data_020fec54,data_020fec0c,data_020feac4;
 s32 v=0;
 if(M2C_FIELD(b,s32 *,0)==100) AssertFailed(&data_020fec54,&data_020fec0c,&data_020feac4,473);
 if(M2C_FIELD(b,s32 *,0)!=105) {
 if(M2C_FIELD(b,s32 *,4)) v=gpiPeerProcessConnecting(a,b);else v=gpiProcessPeerAcceptingConnection(a,b);
 }
 if(!v && M2C_FIELD(b,s32 *,0)==105) v=gpiProcessPeer(a,b);
 return v;
}

M2C_UNK func_02054fa8(void **a,void *b) {
 M2C_UNK Vector_Free(s32);
 func_020496cc(M2C_FIELD(b,s32 *,8),2);
 func_020496b8(M2C_FIELD(b,s32 *,8));
 gpiFree(M2C_FIELD(b,void **,24));M2C_FIELD(b,void **,24)=NULL;
 gpiFree(M2C_FIELD(b,void **,40));M2C_FIELD(b,void **,40)=NULL;
 if(M2C_FIELD(b,s32 *,56)) {Vector_Free(M2C_FIELD(b,s32 *,56));M2C_FIELD(b,s32 *,56)=0;}
 gpiFree(b);
}

/* Unlinks an entry from a manager's 0x434 singly-linked list and releases its children. */
void func_02055008(void **manager, void *entry) {
    s32 Vector_GetCount(s32);
    void *Vector_GetItem(s32, M2C_UNK);
    M2C_UNK Vector_RemoveItem(s32, M2C_UNK);
    M2C_UNK gpiSendMessageToServer(void **, s32, s32, s32);
    M2C_UNK func_02054fa8(void **, void *);
    M2C_UNK gpiLogMessage(void **, M2C_UNK *, ...);
    extern M2C_UNK data_020feab4;
    extern M2C_UNK data_020fec08;
    extern M2C_UNK data_020fec0c;
    extern M2C_UNK data_020fec7c;
    extern M2C_UNK data_020fec8c;
    s32 count;
    void *item;
    void *base;
    void *cursor;
    void *previous;

    base = *manager;
    if (entry == NULL) {
        AssertFailed(&data_020fec7c, &data_020fec0c, &data_020feab4, 0x213);
    }
    previous = M2C_FIELD(base, void **, 0x434);
    if (previous == entry) {
        M2C_FIELD(base, void **, 0x434) = (void *) M2C_FIELD(entry, void **, 0x3C);
        goto block_9;
    }
    cursor = M2C_FIELD(previous, void **, 0x3C);
    if (cursor != entry) {
loop_5:
        if (cursor == NULL) {
            AssertFailed(&data_020fec08, &data_020fec0c, &data_020feab4, 0x225);
            gpiLogMessage(manager, &data_020fec8c);
            return;
        }
        previous = cursor;
        cursor = M2C_FIELD(cursor, void **, 0x3C);
        if (cursor == entry) {
            goto block_8;
        }
        goto loop_5;
    }
block_8:
    M2C_FIELD(previous, void **, 0x3C) = (void *) M2C_FIELD(entry, void **, 0x3C);
block_9:
    if (Vector_GetCount(M2C_FIELD(entry, s32 *, 0x38)) != 0) {
        do {
            item = Vector_GetItem(M2C_FIELD(entry, s32 *, 0x38), 0);
            count = M2C_FIELD(item, s32 *, 0x10);
            if (count < 0x64) {
                gpiSendMessageToServer(manager, M2C_FIELD(entry, s32 *, 0xC), count, M2C_FIELD(item, s32 *, 0) + M2C_FIELD(item, s32 *, 0x14));
            }
            Vector_RemoveItem(M2C_FIELD(entry, s32 *, 0x38), 0);
        } while (Vector_GetCount(M2C_FIELD(entry, s32 *, 0x38)) != 0);
    }
    func_02054fa8(manager, entry);
}

void func_02055124(M2C_UNK arg0) {
    M2C_UNK ghiSetRecvBufferSize(M2C_UNK, M2C_UNK);
    M2C_UNK func_02049370(M2C_UNK, M2C_UNK);
    M2C_UNK func_020493b0(M2C_UNK);
    M2C_UNK func_020493f8(M2C_UNK);
    ghiSetRecvBufferSize(arg0, 0x4000);
    ghiSetRecvBufferSize(arg0, 0x8000);
    ghiSetRecvBufferSize(arg0, 0x10000);
    ghiSetRecvBufferSize(arg0, 0x20000);
    ghiSetRecvBufferSize(arg0, 0x40000);
    func_02049370(arg0, 0x4000);
    func_02049370(arg0, 0x8000);
    func_02049370(arg0, 0x10000);
    func_020493b0(arg0);
    func_020493f8(arg0);
}

/* Ticks the gpi session manager: accepts a pending incoming connection (the
 * socket in the manager's -1 peer slot, queued as a new GPI_STATE_ACCEPTING
 * peer and set non-blocking), then steps every peer on the manager's peer list
 * (0x434) and drops the peers that errored out or went quiet past their
 * deadline.  Returns 0. */
s32 func_0205519c(void **manager) {
    M2C_UNK ghiSetNonBlocking(M2C_UNK, s32);
    s32 ghiSocketCanRecv(s32);
    s32 func_020497a0(s32, M2C_UNK, M2C_UNK);
    s32 gpiGetTime(M2C_UNK);
    M2C_UNK func_020496b8(s32);
    s32 func_02054f0c(M2C_UNK, void *);
    void func_02055008(void **, void *);
    void *gpiCreatePeer(void **, s32, s32);
    void func_02055124(M2C_UNK);
    s32 socket;
    s32 peerResult;
    void *peer;
    void *nextPeer;
    void *session;

    session = *manager;
    if ( -1 != M2C_FIELD(session, s32 *, 0x204) && (ghiSocketCanRecv(M2C_FIELD(session, s32 *, 0x204)) != 0)) {
        socket = func_020497a0(M2C_FIELD(session, s32 *, 0x204), 0, 0);
        if (socket != -1) {
            peer = gpiCreatePeer(manager, -1, 0);
            if (peer != NULL) {
                M2C_FIELD(peer, s32 *, 0) = 0x68;
                M2C_FIELD(peer, s32 *, 8) = socket;
                ghiSetNonBlocking(socket, 0);
                func_02055124(M2C_FIELD(peer, s32 *, 8));
            } else {
                func_020496b8(socket);
            }
        }
    }
    peer = M2C_FIELD(session, void **, 0x434);
    if (peer != NULL) {
        do {
            nextPeer = M2C_FIELD(peer, void **, 0x3C);
            peerResult = func_02054f0c(manager, peer);
            if ((M2C_FIELD(peer, s32 *, 0) == 0x6A) || (peerResult != 0) || (gpiGetTime(0) > (s32) M2C_FIELD(peer, s32 *, 0x10))) {
                func_02055008(manager, peer);
            }
            peer = nextPeer;
        } while (nextPeer != NULL);
    }
    return 0;
}

void *gpiFindConnectedPeer(void **a,s32 b) {
 void *p=M2C_FIELD(*a,void **,0x434);
 while(p) {if(M2C_FIELD(p,s32 *,12)==b && M2C_FIELD(p,s32 *,0)==105) return p; p=M2C_FIELD(p,void **,60);}
 return NULL;
}

void func_020552c4(s32 *arg0) {
    M2C_UNK gpiFree(s32);
    gpiFree(*arg0);
    *arg0 = 0;
}

void *gpiCreatePeer(void **a,s32 b,s32 c) {
 void *gpiMalloc(s32);
 s32 gpiGetTime(s32);
 s32 Vector_New(s32,s32,void *);
 void *base=*a;
 void *p=gpiMalloc(64);
 if(!p)return NULL;
 MemSet(p,0,64);
 M2C_FIELD(p,s32 *,0)=100;
 M2C_FIELD(p,s32 *,4)=c;
 M2C_FIELD(p,s32 *,8)=-1;
 M2C_FIELD(p,s32 *,12)=b;
 M2C_FIELD(p,s32 *,16)=gpiGetTime(0)+300;
 M2C_FIELD(p,void **,60)=M2C_FIELD(base,void **,0x434);
 M2C_FIELD(p,s32 *,56)=Vector_New(24,0,func_020552c4);
 M2C_FIELD(base,void **,0x434)=p;
 return p;
}

s32 gpiStartPeerChallenge(M2C_UNK arg0, void *arg1) {
    s32 func_02053c04(M2C_UNK, s32, s32);
    s32 gpiAddOperation(M2C_UNK, M2C_UNK, M2C_UNK, void **, s32, s32, s32);
    void *spC;
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = gpiAddOperation(arg0, 2, 0, &spC, 0, 0, 0);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    var_r0 = func_02053c04(arg0, M2C_FIELD(arg1, s32 *, 0xC), M2C_FIELD(spC, s32 *, 0x18));
    if (var_r0 == 0) {
        M2C_FIELD(arg1, s32 *, 0) = 0x65;
        var_r0 = 0;
    }
    return var_r0;
}

