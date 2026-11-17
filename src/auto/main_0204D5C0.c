/* 19 functions from 0x0204D5C0 to 0x0204E408 (main), found by ds-decomp. */
#include "common.h"
#include "ghttp.h"
void gpiSetErrorString(void **,void *);
static inline s32 char_space(s32 c) { extern u16 gCharClassTable[]; if(c<0 || c>=128) return 0; return gCharClassTable[c] & 256; }

void func_0204d5c0(void *arg0) {
    s32 gpiMalloc(s32);
    void gpiFree(s32);
    s32 ghiAppendDataToBuffer(void *, void *, s32);
    s8 *StringFind(s32, void *);
    void StringFormat(void *, void *, ...);
    s32 StringLength(s32);
    void MemMove(void *, void *, s32);
    void ResetBuffer(void *);
    void InvokeRequestCallback(void *, s32, s32);
    s32 gpiStringDup(s8 *);
    s32 StringCompareN(void *, void *, s32);
    s32 ParseInt(s8 *);
    s32 ghiGetLastSocketError(s32);
    extern M2C_UNK data_020fd9bc, data_020fd9c4, data_020fd9c8, data_020fd9e4, data_020fd9f4, data_020ea988, data_020fd9d4;
    s32 size;
    s32 rcode;
    s8 *data;
    s32 pos;
    s8 *headerEnd;
    s8 *body;
    s32 bodyLen;
    s32 headerLen;
    s32 statusClass;
    s8 *contentLengthHeader;
    s8 *value;
    s8 *end;
    s32 n;
    s32 length;
    s32 buffer;

    buffer = gpiMalloc(0x1000);
    if (buffer == 0) {
        M2C_FIELD(arg0, s32 *, 0xfc) = 1;
        M2C_FIELD(arg0, s32 *, 0x38) = 1;
        return;
    }
    size = 0x1000;
    rcode = ghiReceiveData(arg0, (void *)buffer, &size);
    if (rcode == 3) goto cleanup;
    if (rcode == 1 && M2C_FIELD(arg0, s32 *, 0x84) == M2C_FIELD(arg0, s32 *, 0x80)) goto cleanup;
    if (rcode == 0) {
        if (!ghiAppendDataToBuffer((u8 *)arg0 + 0x74, (void *)buffer, size)) goto cleanup;
    }
    pos = M2C_FIELD(arg0, s32 *, 0x84);
    data = M2C_FIELD(arg0, s8 **, 0x78);
    M2C_FIELD(arg0, s32 *, 0xf4) = pos;
    headerEnd = StringFind((s32)(data + pos), &data_020fd9bc);
    if (!headerEnd) {
        headerEnd = StringFind((s32)(data + pos), &data_020fd9c4);
    }
    if (headerEnd) {
        headerEnd[2] = 0;
        body = headerEnd + 4;
        bodyLen = M2C_FIELD(arg0, s32 *, 0x80) - (s32)(body - M2C_FIELD(arg0, s8 **, 0x78));
        M2C_FIELD(arg0, s32 *, 0x80) = (s32)(headerEnd + 2) - (s32)M2C_FIELD(arg0, s8 **, 0x78);
        headerLen = (s32)(headerEnd + 2) - (s32)M2C_FIELD(arg0, s8 **, 0x78);
        M2C_FIELD(arg0, s32 *, 0xf8) = headerLen;
        M2C_FIELD(arg0, s32 *, 0x84) = headerLen;
        statusClass = M2C_FIELD(arg0, s32 *, 0xec) / 100;
        if (statusClass == 1) {
            if (bodyLen != 0) {
                MemMove(M2C_FIELD(arg0, s8 **, 0x78), body, bodyLen + 1);
                M2C_FIELD(arg0, s32 *, 0x80) = bodyLen;
                M2C_FIELD(arg0, s32 *, 0x84) = 0;
            } else {
                ResetBuffer((u8 *)arg0 + 0x74);
            }
            M2C_FIELD(arg0, s32 *, 0x10) = 6;
            InvokeRequestCallback(arg0, 0, 0);
            goto cleanup;
        }
        if (statusClass == 3) {
            if (M2C_FIELD(arg0, s32 *, 0x10c) > 10) {
                M2C_FIELD(arg0, s32 *, 0xfc) = 1;
                M2C_FIELD(arg0, s32 *, 0x38) = 0xb;
                goto cleanup;
            }
            value = StringFind((s32)(data + pos), &data_020fd9c8);
            if (value) {
                value += 9;
                while (char_space(*value)) value++;
                end = value;
                while (*end && !char_space(*end)) end++;
                *end = 0;
                if (*value == '/') {
                    n = StringLength((s32)M2C_FIELD(arg0, s8 **, 0x18));
                    length = StringLength((s32)value);
                    M2C_FIELD(arg0, s32 *, 0x108) = gpiMalloc(n + 0xe + length);
                    if (!M2C_FIELD(arg0, s32 *, 0x108)) {
                        M2C_FIELD(arg0, s32 *, 0xfc) = 1;
                        M2C_FIELD(arg0, s32 *, 0x38) = 1;
                    }
                    StringFormat((void *)M2C_FIELD(arg0, s32 *, 0x108), &data_020fd9d4,
                        M2C_FIELD(arg0, s32 *, 0x18), M2C_FIELD(arg0, u16 *, 0x20), value);
                } else {
                    M2C_FIELD(arg0, s32 *, 0x108) = gpiStringDup(value);
                    if (!M2C_FIELD(arg0, s32 *, 0x108)) {
                        M2C_FIELD(arg0, s32 *, 0xfc) = 1;
                        M2C_FIELD(arg0, s32 *, 0x38) = 1;
                    }
                }
                goto cleanup;
            }
        }
        contentLengthHeader = StringFind((s32)(data + pos), &data_020fd9e4);
        if (contentLengthHeader) {
            char maxLength[11] = "2147483647";
            value = contentLengthHeader + 0x10;
            end = value;
            n = StringLength((s32)maxLength);
            while (end && *end && *end != '\n' && *end != '\r' && *end != ' ') end++;
            length = (s32)(end - value);
            if (length > n) {
                M2C_FIELD(arg0, s32 *, 0xfc) = 1;
                M2C_FIELD(arg0, s32 *, 0x38) = 0x10;
                goto cleanup;
            }
            if (n == length && StringCompareN(value, maxLength, length) >= 0) {
                M2C_FIELD(arg0, s32 *, 0xfc) = 1;
                M2C_FIELD(arg0, s32 *, 0x38) = 0x10;
                goto cleanup;
            }
            M2C_FIELD(arg0, s32 *, 0x104) = ParseInt(value);
        }
        M2C_FIELD(arg0, s32 *, 0x110) = StringFind((s32)(data + pos), &data_020fd9f4) != 0;
        if (M2C_FIELD(arg0, s32 *, 0x110)) {
            M2C_FIELD(arg0, u8 *, 0x114) = 0;
            M2C_FIELD(arg0, s32 *, 0x120) = 0;
            M2C_FIELD(arg0, s32 *, 0x124) = 0;
            M2C_FIELD(arg0, s32 *, 0x128) = 0;
        }
        n = M2C_FIELD(arg0, s32 *, 0xc) - 3;
        if ((u32)n <= 1) {
            M2C_FIELD(arg0, s32 *, 0xfc) = 1;
            goto cleanup;
        }
        M2C_FIELD(arg0, s32 *, 0x10) = 8;
        if (contentLengthHeader) {
            if (M2C_FIELD(arg0, s32 *, 0x104) == 0) {
                M2C_FIELD(arg0, s32 *, 0xfc) = 1;
                goto cleanup;
            }
        }
        if (bodyLen > 0) ghiProcessIncomingFileData(arg0, body, bodyLen);
    } else {
        if (rcode == 2) {
            M2C_FIELD(arg0, s32 *, 0xfc) = 1;
            M2C_FIELD(arg0, s32 *, 0x38) = 7;
            M2C_FIELD(arg0, s32 *, 0x4c) = ghiGetLastSocketError(M2C_FIELD(arg0, s32 *, 0x48));
        }
    }
cleanup:
    gpiFree(buffer);
}

/* State-8 handler of a ghttp request: drain the response body into the read
 * buffer until it is complete, there is nothing more to read or the transfer
 * timeout runs out.  A close before Content-Length bytes arrived fails the
 * request with GHTTP_RESULT_DOWNLOAD_INCOMPLETE. */
void ghiReceiveFile(GHIConnection *conn){
s32 gpiMalloc(s32);void gpiFree(s32);s32 GetTickCountMs();s32 ghiReceiveData(void*,s32,s32*);s32 ghiProcessIncomingFileData(void*,s32,s32);
s32 readSize,readBuf,status,contentLength,startTime;u32 elapsed;
startTime=GetTickCountMs();elapsed=0;readBuf=gpiMalloc(0x2000);
if(!readBuf){conn->completed=1;conn->result=GHTTP_RESULT_OUT_OF_MEMORY;return;}
while(!conn->completed && elapsed<conn->timeout){
readSize=0x2000;status=ghiReceiveData(conn,readBuf,&readSize);
if(status==GHI_RECV_ERROR || status==GHI_RECV_NO_DATA)break;
if(status==GHI_RECV_CLOSED){
conn->completed=1;contentLength=conn->contentLength;
if(contentLength>0 && conn->bytesReceived<contentLength)conn->result=GHTTP_RESULT_DOWNLOAD_INCOMPLETE;
break;
}
if(!ghiProcessIncomingFileData(conn,readBuf,readSize))break;
elapsed=GetTickCountMs()-startTime;
}
gpiFree(readBuf);
}

s32 func_0204db04(s32 arg0,s32 arg1,s32 arg2) {
 extern s32 gDnsQueryState;
 s32 gpiInitialize(s32,s32,s32);
 if(gDnsQueryState!=1) return 2;
 if(arg0==0) return 2;
 return gpiInitialize(arg0,arg1,arg2);
}

void func_0204db34(s32 *arg0) {
 void gpiFreeConnection(s32 *);
 if (arg0==0 || *arg0==0) return;
 gpiFreeConnection(arg0);
}

s32 func_0204db50(void **arg0) {
 s32 gpiThink(void **,s32);
 if(arg0==0 || *arg0==0) return 2;
 if(M2C_FIELD(*arg0,s32 *,0x108)!=0) return 0;
 return gpiThink(arg0,0);
}

s32 func_0204db84(void **arg0,s32 arg1,s32 arg2,s32 arg3) {
 void gpiSetErrorString(void **,void *);
 extern s32 data_020fda24;
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(arg1<0 || arg1>=6) {gpiSetErrorString(arg0,&data_020fda24); return 2;}
 p=(char *)p+arg1*8;
 M2C_FIELD(p,s32 *,0x1a4)=arg2;
 M2C_FIELD(p,s32 *,0x1a8)=arg3;
 return 0;
}

/* Opens a GameSpy connection with a raw profile: nickname, unique nickname and a
   completion callback (no e-mail, password or CD key).  Fails with "No callback."
   when no callback is given.  A connection that already has a user id just calls
   the callback straight away. */
s32 gpiStartConnectionRaw(void **p,s8 *a,s8 *b,s32 c,s32 d,void (*cb)(void **,s32 *,s32),s32 e){
 s32 gpiStartConnection(void **,void *,void *,void *,void *,s8 *,s8 *,s32,s32,s32,s32,void (*)(void **,s32 *,s32),s32);
 void gpiSetErrorString(void **,void *);
 extern M2C_UNK gpiErrorNoCallback,data_020fda44;
 void *q;
 if(!p || !(q=*p))return 2;
 if(!a || !*a)return 2;
 if(!b || !*b)return 2;
 if(!cb){gpiSetErrorString(p,&gpiErrorNoCallback);return 2;}
 if(M2C_FIELD(q,s32 *,0x108)){
 s32 buf[8]={0};cb(p,buf,e);return 0;
 }
 return gpiStartConnection(p,&data_020fda44,&data_020fda44,&data_020fda44,&data_020fda44,a,b,0,c,0,d,cb,e);
}

void gpiCloseConnection(void **arg0) {
    M2C_UNK gpiResetConnection(void **);
    M2C_UNK gpiDisconnect(void **, M2C_UNK);
    void *temp_r1;

    if (arg0 != NULL) {
        temp_r1 = *arg0;
        if (temp_r1 != NULL) {
            if (M2C_FIELD(temp_r1, s32 *, 0x108) != 0) {
                return;
            }
            gpiDisconnect(arg0, 1);
            gpiResetConnection(arg0);
        }
    }
}

/* Validate a gpi profile-search request and, in simulation mode, deliver an
   empty result list to the callback; otherwise start the real search (with a
   default country code).  Fails with "No callback." when no callback is given. */
s32 gpiProfileSearch(void **gpi, s8 *nick, s8 *uniquenick, s8 *email,
                     s8 *firstname, s8 *lastname, s32 icq, s32 flags,
                     void (*callback)(void **, s32 *, s32), s32 callbackArg) {
    s32 gpiSearchProfiles(void **, s8 *, s8 *, s8 *, s8 *, s8 *, s32, s32, s32, void (*)(void **, s32 *, s32), s32);
    void gpiSetErrorString(void **, void *);
    extern M2C_UNK gpiErrorNoCallback;
    s32 result[GPI_SEARCH_RESULT_WORDS];
    s32 *response;
    void *connection;
    if (!gpi || !(connection = *gpi)) return 2;
    if (!callback) {
        gpiSetErrorString(gpi, &gpiErrorNoCallback);
        return 2;
    }
    if (M2C_FIELD(connection, s32 *, GPI_CONN_SIMULATION)) {
        response = (s32 *)result;
        *(volatile s32 *)(response + 2) = 0;
        response[0] = 0;
        response[1] = 0;
        response[3] = 0;
        result[2] = GPI_SEARCH_MORE;
        callback(gpi, response, callbackArg);
        return 0;
    }
    return gpiSearchProfiles(gpi, nick, uniquenick, email, firstname, lastname, icq, 0, flags, callback, callbackArg);
}

/* Validate a profile-info request, delivering an empty result in simulation mode. */
s32 gpiGetInfo(void **gpi, s32 profileId, s32 useCache, s32 blocking,
               void (*callback)(void **, s32 *, s32), s32 callbackArg) {
    s32 gpiGetInfoInternal(void **, s32, s32, s32, void (*)(void **, s32 *, s32), s32);
    extern M2C_UNK gpiErrorNoCallback;
    extern s32 gGpiMsgDisconnected;
    void *connection;
    if (!gpi || !(connection = *gpi) || !profileId) return 2;
    if (!callback) {
        gpiSetErrorString(gpi, &gpiErrorNoCallback);
        return 2;
    }
    if (M2C_FIELD(connection, s32 *, GPI_CONN_SIMULATION)) {
        s32 result[GPI_INFO_RESULT_WORDS] = {0};
        callback(gpi, result, callbackArg);
        return 0;
    }
    if (M2C_FIELD(connection, s32 *, GPI_CONN_STATE) == GPI_STATE_DISCONNECTED) {
        gpiSetErrorString(gpi, &gGpiMsgDisconnected);
        return 2;
    }
    return gpiGetInfoInternal(gpi, profileId, useCache, blocking, callback, callbackArg);
}

s32 gpiSetInfoString(void **arg0,s32 arg1,s32 arg2) {
 s32 func_0205342c(void **,s32,s32);
 extern s32 gGpiMsgDisconnected;
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) return 0;
 if(M2C_FIELD(p,s32 *,0x1d8)==4) {gpiSetErrorString(arg0,&gGpiMsgDisconnected);return 2;}
 return func_0205342c(arg0,arg1,arg2);
}

s32 func_0204df00(void **connection, s32 newProfileId, s8 *reason) {
    /* Build an add-buddy request in the connection's send buffer from the session key, new profile id and reason string. */
    void gpiAppendStringField(void **, void *, s8 *);
    void gpiAppendIntField(void **, void *, s32);
    void StringCopyN(void *, s8 *, s32);
    extern s32 gGpiMsgDisconnected, data_020fda78;
    extern s8 data_020fda88, gGsKeySessKey, data_020fdaa0, data_020fdab0, gGsKeyFinalStatus;
    s8 buf[0x401];
    s8 *c;
    void *session;
    if (!connection || !(session = *connection)) return 2;
    if (M2C_FIELD(session, s32 *, 0x108)) return 0;
    if (M2C_FIELD(session, s32 *, 0x1d8) == 4) {
        gpiSetErrorString(connection, &gGpiMsgDisconnected);
        return 2;
    }
    if (!reason) {
        gpiSetErrorString(connection, &data_020fda78);
        return 2;
    }
    StringCopyN(buf, reason, 0x401);
    if (*buf) {
        c = buf;
        do {
            if (*c == 92) *c = 47;
            c++;
        } while (*c);
    }
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, &data_020fda88);
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, &gGsKeySessKey);
    gpiAppendIntField(connection, (u8 *)session + 0x1f4, M2C_FIELD(session, s32 *, 0x198));
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, &data_020fdaa0);
    gpiAppendIntField(connection, (u8 *)session + 0x1f4, newProfileId);
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, &data_020fdab0);
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, buf);
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, &gGsKeyFinalStatus);
    return 0;
}

s32 func_0204e074(void **arg0,s32 arg1) {
 s32 gpiAuthAddProfile(void **,s32);
 extern s32 gGpiMsgDisconnected;
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) return 0;
 if(M2C_FIELD(p,s32 *,0x1d8)==4) {gpiSetErrorString(arg0,&gGpiMsgDisconnected);return 2;}
 return gpiAuthAddProfile(arg0,arg1);
}

/* Release a profile record: drop one reference to it and, once the session no
 * longer keeps buddy details and the last reference is gone, free its signature
 * string and the record itself. Returns 2 when no connection is available. */
s32 gpiReleaseProfile(void **connection, s32 profileId) {
    void gpiFree(s32);
    s32 gpiFindBuddyStatus(void **, s32, void **);
    void gpiFreeBuddyList(void **, void *);
    s32 gpiPeerConnectionDone(void *);
    extern s32 gGpiMsgDisconnected;
    void *profile;
    void *gpi;
    if (connection == 0 || (gpi = *connection) == 0) return 2;
    if (M2C_FIELD(gpi, s32 *, GPI_CONN_SIMULATION) != 0) return 0;
    if (M2C_FIELD(gpi, s32 *, GPI_CONN_STATE) == GPI_STATE_DISCONNECTED) {
        gpiSetErrorString(connection, &gGpiMsgDisconnected);
        return 2;
    }
    if (gpiFindBuddyStatus(connection, profileId, &profile) == 0) return 0;
    M2C_FIELD(profile, s32 *, GPI_BUDDY_USE_COUNT)--;
    if (M2C_FIELD(gpi, s32 *, 0x100) == 0 && M2C_FIELD(profile, s32 *, GPI_BUDDY_USE_COUNT) <= 0) {
        gpiFree(M2C_FIELD(profile, s32 *, GPI_BUDDY_SIGNATURE));
        M2C_FIELD(profile, s32 *, GPI_BUDDY_SIGNATURE) = 0;
        if (gpiPeerConnectionDone(profile) != 0) gpiFreeBuddyList(connection, profile);
    }
    return 0;
}

s32 func_0204e184(void **arg0,volatile s32 *arg1) {
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) {*arg1=0; return 0;}
 *arg1=M2C_FIELD(p,s32 *,0x430);
 return 0;
}

/* Copies the GameSpy buddy at `index` into `status`: the buddy's profile id,
 * presence status, its status and location strings and advertised address.
 * Returns 0 on success, 2 on a bad argument or a disconnected connection. */
s32 gpGetBuddyStatus(void **connection,s32 index,MatchPlayerInfo *status){
 void *gpiGetBuddyStatusByIndex(void **,s32);
 void StringCopyN(void *,s8 *,s32);
 void gpiSetErrorString(void **,void *);
 void AssertFailed(void *,void *,void *,s32);
 void MemSet(void *,s32,s32);
 extern M2C_UNK gGpiGetBuddyStatusName,gGpiMsgInvalidStatus,gGpiMsgInvalidIndex,gGpiAssertBuddyStatus,gGpiGpFileName;
 void *session; GpiBuddyStatus *buddy; GpiBuddyStatusDetails *details; s8 *string; s32 count;
 if(!connection || !(session=*connection))return 2;
 if(M2C_FIELD(session,s32 *,0x108)){MemSet(status,0,0x210);return 0;}
 if(!status){gpiSetErrorString(connection,&gGpiMsgInvalidStatus);return 2;}
 count=M2C_FIELD(session,s32 *,0x430);
 if(index<0 || index>=count){gpiSetErrorString(connection,&gGpiMsgInvalidIndex);return 2;}
 buddy=gpiGetBuddyStatusByIndex(connection,index);
 if(!buddy){gpiSetErrorString(connection,&gGpiMsgInvalidIndex);return 2;}
 details=buddy->details;
 if(!details)AssertFailed(&gGpiAssertBuddyStatus,&gGpiGpFileName,&gGpiGetBuddyStatusName,0x5cf);
 status->profileId=buddy->profileId;
 status->status=details->status;
 string=details->statusString;
 if(!string)*string=0;else StringCopyN(status->fields,string,256);
 string=details->locationString;
 if(!string)*string=0;else StringCopyN(status->name,string,256);
 status->ipAddr=details->ipAddr;
 status->port=details->port;
 return 0;
}

s32 func_0204e2f4(void **arg0,s32 arg1,s32 *arg2) {
 s32 gpiFindBuddyStatus(void **,s32,void **);
 void *sp0; s32 *q;
 if(arg0==0 || *arg0==0) return 2;
 if(M2C_FIELD(*arg0,s32 *,0x108)!=0) {*arg2=0; return 0;}
 if(gpiFindBuddyStatus(arg0,arg1,&sp0)!=0 && (q=M2C_FIELD(sp0,s32 **,8))!=0) *arg2=*q;
 else *arg2=-1;
 return 0;
}

s32 func_0204e364(void **arg0,s32 arg1) {
 s32 gpiFindBuddyStatus(void **,s32,void **);
 void *sp0;
 if(arg0==0 || *arg0==0) return 0;
 if(M2C_FIELD(*arg0,s32 *,0x108)!=0) return 0;
 if(gpiFindBuddyStatus(arg0,arg1,&sp0)!=0 && M2C_FIELD(sp0,s32 *,8)!=0) return 1;
 return 0;
}

s32 func_0204e3b0(void **arg0,s32 arg1) {
 s32 func_0204fb50(void **,s32);
 extern s32 gGpiMsgDisconnected;
 void *p; s32 result;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) return 0;
 if(M2C_FIELD(p,s32 *,0x1d8)==4) {gpiSetErrorString(arg0,&gGpiMsgDisconnected);return 2;}
 result=func_0204fb50(arg0,arg1);
 if(result==0) return 0;
 return result;
}

