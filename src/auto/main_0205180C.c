#include "common.h"
typedef struct {s32 function,argument;} Callback518;
typedef struct {char token[21], hash[33], name[82], buf[512];} Response518;
extern M2C_UNK gGpiConnectPidKey,gGpiConnectFatalKey,gGpiConnectChallengeTag,gGpiConnectMsgBadResponse,gGpiConnectChallengeKey,gGpiConnectNewUserTag,gGpiConnectUserIdKey,gGpiConnectMsgMissingField,gGpiConnectProfileIdKey,gGpiConnectLoginReplyTag,gGpiConnectSessKey,gGsKeyUniqueNick,data_020fe5f8,gGpiConnectIdentityFormat,gGpiConnectProofFormat,gGpiConnectProofSpaces,gGpiConnectProofKey,gGpiConnectMsgBadProof,gGpiConnectMsgOutOfMemory;


#pragma opt_strength_reduction off
/* Handle one server reply of the gpi connect handshake.  A server error reply
 * ends the operation, fatal when it carries a \fatal\ field.  Otherwise the
 * operation state picks the step: 1 is the login challenge, 3 the new-user
 * reply and 2 the login reply.  Each step stores the reply's ids on the
 * connection and sends the next request; the login reply also rebuilds the
 * login proof, verifies the server's copy, marks the connection as logged in
 * and queues the operation's completion callback. */
s32 gpiProcessConnect(void **connectionRef, void *operation, char *message) {
s32 gpiProcessErrorReply(void **,char *,s32);
s32 gpiValueForKey(char *,M2C_UNK *,void *,s32);
s32 ParseInt(char *);
M2C_UNK gpiRemoveBuddyStatus(void **,s32);
s32 StringFind(char *,M2C_UNK *);
M2C_UNK gpiSetError(void **,s32,M2C_UNK *);
M2C_UNK gpiCallErrorCallback(void **,s32,s32);
s32 StringCompareN(char *,M2C_UNK *,s32);
s32 SendNewUserProfile(void **,void *);
s32 func_020511dc(void **,void *);
s32 StringFormat(char *,M2C_UNK *,...);
s32 StringLength(char *);
M2C_UNK Md5Hex(char *,s32,char *);
s32 ByteCompareN(void *,void *,s32);
s32 *func_02055aa0(void **,s32);
void *gpiMalloc(s32);
void MemSet(void *,s32,s32);
void StringCopyN(void *,void *,s32);
s32 gpiAddCallback(void **,Callback518,void *,void *,s32);
M2C_UNK gpiSetErrorString(M2C_UNK,M2C_UNK *);
M2C_UNK gpiRemoveOperation();
Response518 scratch;
void *payload;
void *connection=*connectionRef;
char *identity;
s32 *buddyRecord;
s32 result;
Callback518 callback;
if(gpiProcessErrorReply(connectionRef,message,0)){
if(M2C_FIELD(connection,s32 *,GPI_CONN_ERROR_CODE)==0x106 && M2C_FIELD(connection,s32 *,GPI_CONN_PROFILE_ID)){
gpiRemoveBuddyStatus(connectionRef,M2C_FIELD(connection,s32 *,GPI_CONN_PROFILE_ID));
M2C_FIELD(connection,s32 *,GPI_CONN_USER_ID)=0;M2C_FIELD(connection,s32 *,GPI_CONN_PROFILE_ID)=0;
}else if(M2C_FIELD(connection,s32 *,GPI_CONN_ERROR_CODE)==0x201){
if(gpiValueForKey(message,&gGpiConnectPidKey,scratch.buf,512))M2C_FIELD(connection,s32 *,GPI_CONN_PROFILE_ID)=ParseInt(scratch.buf);
}
if(StringFind(message,&gGpiConnectFatalKey)){gpiSetError(connectionRef,M2C_FIELD(connection,s32 *,GPI_CONN_ERROR_CODE),connection);gpiCallErrorCallback(connectionRef,4,1);return 4;}
else {gpiSetError(connectionRef,M2C_FIELD(connection,s32 *,GPI_CONN_ERROR_CODE),connection);gpiCallErrorCallback(connectionRef,4,0);return 4;}
}
payload=M2C_FIELD(operation,void **,4);
switch(M2C_FIELD(operation,s32 *,20)){
case 1:
if(StringCompareN(message,&gGpiConnectChallengeTag,5)){gpiSetError(connectionRef,1,&gGpiConnectMsgBadResponse);gpiCallErrorCallback(connectionRef,3,1);return 3;}
if(!gpiValueForKey(message,&gGpiConnectChallengeKey,payload,128)){gpiSetError(connectionRef,1,&gGpiConnectMsgBadResponse);gpiCallErrorCallback(connectionRef,3,1);return 3;}
if(M2C_FIELD(payload,s32 *,0x304)){
result=SendNewUserProfile(connectionRef,payload);if(result)return result;
M2C_FIELD(operation,s32 *,20)=3;
}else{
result=func_020511dc(connectionRef,payload);if(result)return result;
M2C_FIELD(operation,s32 *,20)=2;
}
break;
case 3:
if(StringCompareN(message,&gGpiConnectNewUserTag,5)){gpiSetError(connectionRef,1,&gGpiConnectMsgBadResponse);gpiCallErrorCallback(connectionRef,3,1);return 3;}
if(!gpiValueForKey(message,&gGpiConnectUserIdKey,scratch.buf,512)){gpiSetError(connectionRef,1,&gGpiConnectMsgMissingField);gpiCallErrorCallback(connectionRef,3,1);return 3;}
M2C_FIELD(connection,s32 *,GPI_CONN_USER_ID)=ParseInt(scratch.buf);
if(!gpiValueForKey(message,&gGpiConnectProfileIdKey,scratch.buf,512)){gpiSetError(connectionRef,1,&gGpiConnectMsgMissingField);gpiCallErrorCallback(connectionRef,3,1);return 3;}
M2C_FIELD(connection,s32 *,GPI_CONN_PROFILE_ID)=ParseInt(scratch.buf);
result=func_020511dc(connectionRef,payload);if(result)return result;
M2C_FIELD(operation,s32 *,20)=2;break;
case 2:
if(StringCompareN(message,&gGpiConnectLoginReplyTag,5)){gpiSetError(connectionRef,1,&gGpiConnectMsgBadResponse);gpiCallErrorCallback(connectionRef,3,1);return 3;}
if(!gpiValueForKey(message,&gGpiConnectSessKey,scratch.buf,512)){gpiSetError(connectionRef,1,&gGpiConnectMsgMissingField);gpiCallErrorCallback(connectionRef,3,1);return 3;}
M2C_FIELD(connection,s32 *,GPI_CONN_SESSION_KEY)=ParseInt(scratch.buf);
if(!gpiValueForKey(message,&gGpiConnectUserIdKey,scratch.buf,512)){gpiSetError(connectionRef,1,&gGpiConnectMsgMissingField);gpiCallErrorCallback(connectionRef,3,1);return 3;}
M2C_FIELD(connection,s32 *,GPI_CONN_USER_ID)=ParseInt(scratch.buf);
if(!gpiValueForKey(message,&gGpiConnectProfileIdKey,scratch.buf,512)){gpiSetError(connectionRef,1,&gGpiConnectMsgMissingField);gpiCallErrorCallback(connectionRef,3,1);return 3;}
M2C_FIELD(connection,s32 *,GPI_CONN_PROFILE_ID)=ParseInt(scratch.buf);
if(!gpiValueForKey(message,&gGsKeyUniqueNick,scratch.token,21))scratch.token[0]=0;
if(!gpiValueForKey(message,&data_020fe5f8,(char *)connection+0x474,25))M2C_FIELD(connection,s8 *,0x474)=0;
if(M2C_FIELD(payload,s8 *,0xc2))identity=(char *)payload+0xc2;
else if(M2C_FIELD(connection,s8 *,0x12f))identity=(char *)connection+0x12f;
else {StringFormat(scratch.name,&gGpiConnectIdentityFormat,(char *)connection+0x110,(char *)connection+0x144);identity=scratch.name;}
StringFormat(scratch.buf,&gGpiConnectProofFormat,(char *)payload+161,&gGpiConnectProofSpaces,identity,payload,(char *)payload+128,(char *)payload+161);
Md5Hex(scratch.buf,StringLength(scratch.buf),scratch.hash);
if(!gpiValueForKey(message,&gGpiConnectProofKey,scratch.buf,512)){gpiSetError(connectionRef,1,&gGpiConnectMsgMissingField);gpiCallErrorCallback(connectionRef,3,1);return 3;}
if(ByteCompareN(scratch.hash,scratch.buf,32)){gpiSetError(connectionRef,0x108,&gGpiConnectMsgBadProof);gpiCallErrorCallback(connectionRef,3,1);return 3;}
if(M2C_FIELD(connection,s32 *,0x100)){buddyRecord=func_02055aa0(connectionRef,M2C_FIELD(connection,s32 *,GPI_CONN_PROFILE_ID));buddyRecord[0]=M2C_FIELD(connection,s32 *,GPI_CONN_PROFILE_ID);buddyRecord[1]=M2C_FIELD(connection,s32 *,GPI_CONN_USER_ID);}
M2C_FIELD(connection,s32 *,GPI_CONN_STATE)=GPI_STATE_LOGGED_IN;
callback=*(Callback518 *)((char *)operation+12);
if(callback.function){
payload=gpiMalloc(32);
if(!payload){gpiSetErrorString((M2C_UNK)connectionRef,&gGpiConnectMsgOutOfMemory);return 1;}
MemSet(payload,0,32);
M2C_FIELD(payload,s32 *,4)=M2C_FIELD(connection,s32 *,GPI_CONN_PROFILE_ID);M2C_FIELD(payload,s32 *,0)=0;
StringCopyN((char *)payload+8,scratch.token,21);
result=gpiAddCallback(connectionRef,callback,payload,operation,0);
if(result)return result;
}
gpiRemoveOperation(connectionRef,operation);
break;
}
return 0;
}
#pragma opt_strength_reduction on
/* gpiCheckConnect (gpiConnect.c): one step of the gpi connection handshake.  Poll
 * the connection's socket and, when the server has accepted it, move the
 * connection into the connected state; a refused socket raises the connection
 * error and reports it, and no activity leaves the connection alone.  Returns a
 * nonzero error code to stop the caller. */
s32 gpiCheckConnect(void **connection) {
M2C_UNK gpiCallErrorCallback(void **,s32,s32);
s32 gpiCheckConnectionSocket(void **,s32,s32 *);
M2C_UNK gpiSetError(void **,s32,M2C_UNK *);
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
extern M2C_UNK sGpiConnectCheckName,sGpiConnectSourceFile,gGpiMsgConnectionRefused,sGpiAssertStateConnected;
s32 state,result;void *session=*connection;
result=gpiCheckConnectionSocket(connection,M2C_FIELD(session,s32 *,0x1d4),&state);
if(result)return result;
if(state==GPI_SOCKET_REFUSED){
gpiSetError(connection,0x107,&gGpiMsgConnectionRefused);
gpiCallErrorCallback(connection,4,1);return 4;
}
if(state==GPI_SOCKET_NONE)return 0;
if(state!=GPI_SOCKET_ACCEPTED)AssertFailed(&sGpiAssertStateConnected,&sGpiConnectSourceFile,&sGpiConnectCheckName,0x2ef);
M2C_FIELD(session,s32 *,GPI_CONN_STATE)=GPI_STATE_CONNECTED;
return 0;
}

/* Release one record of the connection's buddy-status table: free its presence
 * details (unless the connection keeps them), its signature and its extra
 * string, and remove the record when no operation holds it and no profile info
 * is cached for it.  Returns 0 when the record was removed, so the table scan
 * restarts, and 1 when it stays. */
s32 gpiReleaseBuddyStatusRecord(void **connection, void *record) {
    M2C_UNK gpiFree(void *);
    M2C_UNK gpiFreeBuddyList(void **, void *);
    void *details = M2C_FIELD(record, void **, GPI_BUDDY_DETAILS);
    void *session = *connection;

    if (details && M2C_FIELD(session, s32 *, GPI_CONN_KEEP_BUDDY_DETAILS) == 0) {
        gpiFree(M2C_FIELD(M2C_FIELD(record, void **, GPI_BUDDY_DETAILS), void **, GPI_BUDDY_STATUS_STRING));
        M2C_FIELD(M2C_FIELD(record, void **, GPI_BUDDY_DETAILS), void **, GPI_BUDDY_STATUS_STRING) = 0;
        gpiFree(M2C_FIELD(M2C_FIELD(record, void **, GPI_BUDDY_DETAILS), void **, GPI_BUDDY_LOCATION_STRING));
        M2C_FIELD(M2C_FIELD(record, void **, GPI_BUDDY_DETAILS), void **, GPI_BUDDY_LOCATION_STRING) = 0;
        gpiFree(M2C_FIELD(record, void **, GPI_BUDDY_DETAILS));
        M2C_FIELD(record, void **, GPI_BUDDY_DETAILS) = 0;
    }
    gpiFree(M2C_FIELD(record, void **, GPI_BUDDY_SIGNATURE));
    M2C_FIELD(record, void **, GPI_BUDDY_SIGNATURE) = 0;
    gpiFree(M2C_FIELD(record, void **, GPI_BUDDY_UNK18));
    M2C_FIELD(record, void **, GPI_BUDDY_UNK18) = 0;
    M2C_FIELD(record, s32 *, GPI_BUDDY_USE_COUNT) = 0;
    if (!M2C_FIELD(record, s32 *, GPI_BUDDY_CACHED_INFO) || (M2C_FIELD(session, s32 *, GPI_CONN_KEEP_BUDDY_DETAILS) == 1 && !M2C_FIELD(record, void **, GPI_BUDDY_DETAILS))) {
        gpiFreeBuddyList(connection, record);
        return 0;
    }
    return 1;
}

extern u32 gGsKeyFinal;
extern u32 data_020fe668;
extern u32 data_020fe67c;
extern s32 gpiReleaseBuddyStatusRecord(void **, void *);
/* Tear down a gpi connection: when asked to and still logged in, send the logout
 * command, close the server and local sockets, then free every buffer, pending
 * operation and peer and drop all the connection's buddy-status records. */
void gpiDisconnect(void **arg0, s32 sendLogout) {
    void *operation;
    void *connection;
    s32 state;
    s32 socket;
    s32 localSocket;
    void *peer;
    u32 closed;

    connection = *arg0;
    state = *(s32 *)((char *)connection + GPI_CONN_STATE);
    if (state == GPI_STATE_DISCONNECTED) {
        return;
    }
    if (state != GPI_STATE_IDLE) {
        if ((sendLogout != 0) && (state == GPI_STATE_LOGGED_IN)) {
            gpiAppendStringField(arg0, (char *)connection + GPI_CONN_OUTPUT_BUFFER, &data_020fe668);
            gpiAppendIntField(arg0, (char *)connection + GPI_CONN_OUTPUT_BUFFER, *(s32 *)((char *)connection + GPI_CONN_SESSION_KEY));
            gpiAppendStringField(arg0, (char *)connection + GPI_CONN_OUTPUT_BUFFER, &gGsKeyFinal);
        }
        gpiSendFromBuffer(arg0, *(s32 *)((char *)connection + GPI_CONN_SOCKET), (char *)connection + GPI_CONN_OUTPUT_BUFFER, &closed, 1, &data_020fe67c);
        socket = *(s32 *)((char *)connection + GPI_CONN_SOCKET);
        if (socket != -1) {
            func_020496cc(socket, 2);
            ghiCloseSocket(*(s32 *)((char *)connection + GPI_CONN_SOCKET));
            *(s32 *)((char *)connection + GPI_CONN_SOCKET) = -1;
        }
        localSocket = *(s32 *)((char *)connection + GPI_CONN_LOCAL_SOCKET);
        if (localSocket != -1) {
            func_020496cc(localSocket, 2);
            ghiCloseSocket(*(s32 *)((char *)connection + GPI_CONN_LOCAL_SOCKET));
            *(s32 *)((char *)connection + GPI_CONN_LOCAL_SOCKET) = -1;
        }
        *(s32 *)((char *)connection + GPI_CONN_STATE) = GPI_STATE_DISCONNECTED;
        *(s32 *)((char *)connection + GPI_CONN_USER_ID) = 0;
        *(s32 *)((char *)connection + GPI_CONN_PROFILE_ID) = 0;
    }
    gpiFree(*(s32 *)((char *)connection + GPI_CONN_RECV_BUFFER));
    *(s32 *)((char *)connection + GPI_CONN_RECV_BUFFER) = 0;
    gpiFree(*(s32 *)((char *)connection + GPI_CONN_MSG_BUFFER));
    *(s32 *)((char *)connection + GPI_CONN_MSG_BUFFER) = 0;
    gpiFree(*(s32 *)((char *)connection + GPI_CONN_OUTPUT_BUFFER));
    *(s32 *)((char *)connection + GPI_CONN_OUTPUT_BUFFER) = 0;
    gpiFree(*(s32 *)((char *)connection + GPI_CONN_UPDATE_PRO_BUFFER));
    *(s32 *)((char *)connection + GPI_CONN_UPDATE_PRO_BUFFER) = 0;
    gpiFree(*(s32 *)((char *)connection + GPI_CONN_UPDATE_UI_BUFFER));
    *(s32 *)((char *)connection + GPI_CONN_UPDATE_UI_BUFFER) = 0;
    operation = M2C_FIELD(connection, void **, GPI_CONN_OPERATIONS);
    while (operation != NULL) {
        gpiRemoveOperation(arg0, operation);
        operation = M2C_FIELD(connection, void **, GPI_CONN_OPERATIONS);
    }
    *(s32 *)((char *)connection + GPI_CONN_OPERATIONS) = 0;
    peer = *(void **)((char *)connection + GPI_CONN_PEER_HEAD);
    if (peer != NULL) {
        do {
            void *t = peer;
            peer = *(void **)((char *)peer + GPI_PEER_NEXT);
            gpiFreePeer(arg0, t);
        } while (peer != NULL);
    }
    *(s32 *)((char *)connection + GPI_CONN_PEER_HEAD) = 0;
    while (gpiWalkBuddyTable(arg0, gpiReleaseBuddyStatusRecord, 0) == 0) {
    }
}

/* Returns 1 if (day, month, year) is a valid calendar date (years 1900..2079, leap rules), 0 otherwise; treats 0/0/0 as valid sentinel. */
s32 gpiIsValidDate(s32 day,s32 month,s32 year){
 if(day==0 && month==0 && year==0)return 1;
 if(day<0 || month<0 || year<0)return 0;
 switch(month){
 case 0: if(day!=0)return 0;break;
 case 1:case 3:case 5:case 7:case 8:case 10:case 12:if(day>31)return 0;break;
 case 4:case 6:case 9:case 11:if(day>30)return 0;break;
 case 2:
 if((year%4==0 && year%100!=0)||year%400==0){if(day>29)return 0;}
 else if(day>28)return 0;
 break;
 default:return 0;
 }
 if(year<1900)return 0;
 if(year>2079)return 0;
 if(year==2079){
 if(month>6)return 0;
 if(month==6 && day>6)return 0;
 }
 return 1;
}

/* Split a GameSpy packed date (day in the top byte, month in the next, year in
 * the low 16 bits) into day, month and year.  An invalid date asserts and then
 * reports "Invalid date." through the connection's error string, returning 2. */
s32 gpiIntToDate(M2C_UNK connection,s32 date,s32 *day,s32 *month,s32 *year){
s32 gpiIsValidDate(s32,s32,s32);
M2C_UNK gpiSetErrorString(M2C_UNK,M2C_UNK *);
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
extern M2C_UNK sGpiIntToDateName,gGpiInfoFileName,sGpiInvalidDateError,sGpiIsValidDateArgCheck;
s32 d=(u8)(date>>24),m=(u8)(date>>16);
s32 y=(u16)date;
if(!gpiIsValidDate(d,m,y))AssertFailed(&sGpiIsValidDateArgCheck,&gGpiInfoFileName,&sGpiIntToDateName,0xb7);
if(!gpiIsValidDate(d,m,y)){gpiSetErrorString(connection,&sGpiInvalidDateError);return 2;}
*day=d;*month=m;*year=y;
return 0;
}

/* Copies a parsed profile-info reply into the flat GpiInfoRecord delivered to
 * the game's info callback; a missing string becomes an empty one. */
void gpiCopyInfo(GpiInfoResponse *src, GpiInfoRecord *dst){
void StringCopyN(void *,void *,s32);
void *p;
p=src->nick;if(!p)dst->nick[0]=0;else StringCopyN(dst->nick,p,31);
p=src->uniqueNick;if(!p)dst->uniqueNick[0]=0;else StringCopyN(dst->uniqueNick,p,21);
p=src->email;if(!p)dst->email[0]=0;else StringCopyN(dst->email,p,51);
p=src->firstName;if(!p)dst->firstName[0]=0;else StringCopyN(dst->firstName,p,31);
p=src->lastName;if(!p)dst->lastName[0]=0;else StringCopyN(dst->lastName,p,31);
p=src->homepage;if(!p)dst->homepage[0]=0;else StringCopyN(dst->homepage,p,76);
dst->icqUin=src->icqUin;
StringCopyN(dst->zipCode,src->zipCode,11);
StringCopyN(dst->countryCode,src->countryCode,3);
p=src->location;
dst->longitude=src->longitude;
dst->latitude=src->latitude;
if(!p)dst->location[0]=0;else StringCopyN(dst->location,p,128);
dst->birthYear=src->birthYear;
dst->birthMonth=src->birthMonth;
dst->birthDay=src->birthDay;
dst->sex=src->sex;
dst->pmask=src->pmask;
p=src->aim;if(!p)dst->aim[0]=0;else StringCopyN(dst->aim,p,51);
dst->icqUin=src->icqUin;
dst->longitude=src->longitude;
dst->latitude=src->latitude;
dst->birthYear=src->birthYear;
dst->birthMonth=src->birthMonth;
dst->birthDay=src->birthDay;
dst->sex=src->sex;
dst->pmask=src->pmask;
dst->pic=src->pic;
dst->occupation=src->occupation;
dst->industry=src->industry;
dst->income=src->income;
dst->marital=src->marital;
dst->children=src->children;
dst->i1=src->i1;
dst->o1=src->o1;
dst->conn=src->conn;
}

