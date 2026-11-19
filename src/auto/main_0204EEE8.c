/* 9 functions from 0x0204EEE8 to 0x0204FED0 (main), found by ds-decomp. */
#include "common.h"

typedef struct { s32 function; s32 parameter; } GpiCallbackPair;
static inline u32 gpiParseAddress(char *buffer, void *key, char *small) {
 s32 gpiValueForKey(void *,void *,void *,s32);
 s32 ParseInt(void *);
 u32 a,b,c,d;
 if(!gpiValueForKey(buffer,key,small,16))return 0;
 a=ParseInt(small);b=ParseInt(small);
 c=ParseInt(small);d=ParseInt(small);
 return ((c>>24)&255)|((d>>8)&0xff00)|((b<<8)&0xff0000)|((a<<24)&0xff000000);
}

#pragma opt_instruction_scheduling off
s32 func_0204eee8(void *arg0, void *arg1) {
extern M2C_UNK gpiKeyBm,gpiErrorUnexpectedData,gpiKeyFrom,gpiKeyDate,gpiErrorOutOfMemoryText,gpiKeyMsg,gpiSepSigned,gpiSepS,gpiSepSs,gpiSepLs,gpiSepIp,gpiSepP,gpiSepL,gpiChallengeAccept;
s32 gpiValueForKey(void *,void *,void *,s32);
s32 ParseInt(void *);
s32 gpiGetTime(s32);
void *gpiMalloc(s32);
s32 StringLength(M2C_UNK);
void StringCopy(void *,void *);
s32 gpiAddCallback(void *,GpiCallbackPair,void *,s32,s32);
void *func_02055aa0(void *,s32);
char *StringFind(void *,void *);
s32 gpiStringDup(char *);
s32 gpiSendMessageToPlayer(void **,s32,s32,void *);
u32 w,x,v,y,value; register s32 id; s32 kind,time,r,err; s32 *q,*b,*f; char *c; u16 port; GpiCallbackPair cb,cb4,cb3,cb2; void *p=*(void **)arg0; char buf[4096],text[256],small[16];
if(!gpiValueForKey(arg1,&gpiKeyBm,buf,4096)) {gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
kind=ParseInt(buf);
if(!gpiValueForKey(arg1,&gpiKeyFrom,buf,4096)) {gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
id=ParseInt(buf);
if(gpiValueForKey(arg1,&gpiKeyDate,buf,4096)) time=ParseInt(buf); else time=gpiGetTime(0);
switch(kind) {
case 1:
cb= M2C_FIELD(p,GpiCallbackPair *,0x1bc);
if(!cb.function)break;
q=gpiMalloc(12);if(!q){gpiSetErrorString(arg0,&gpiErrorOutOfMemoryText);return 1;}
if(!gpiValueForKey(arg1,&gpiKeyMsg,buf,4096)){gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
q[2]=(s32)gpiMalloc(StringLength((s32)buf)+1);
if(!q[2]){gpiSetErrorString(arg0,&gpiErrorOutOfMemoryText);return 1;}
StringCopy((void *)q[2],buf);
q[0]=id;q[1]=time;r=gpiAddCallback(arg0,cb,q,0,2);if(r)return r;break;
case 2:
b=func_02055aa0(arg0,id);if(!b){gpiSetErrorString(arg0,&gpiErrorOutOfMemoryText);return 1;}
if(!gpiValueForKey(arg1,&gpiKeyMsg,buf,4096)){gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
c=StringFind(buf,&gpiSepSigned);if(!c){gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
*c=0;if(StringLength((s32)(c+8))!=32){gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
gpiFree(b[4]);b[4]=0;b[4]=gpiStringDup(c+8);b[5]++;
cb2=M2C_FIELD(p,GpiCallbackPair *,0x1ac);if(!cb2.function)break;
q=gpiMalloc(0x40c);if(!q){gpiSetErrorString(arg0,&gpiErrorOutOfMemoryText);return 1;}
StringCopyN(q+2,buf,0x401);q[0]=id;q[1]=time;
r=gpiAddCallback(arg0,cb2,q,0,6);if(r)return r;break;
case 100:
b=func_02055aa0(arg0,id);if(!b){gpiSetErrorString(arg0,&gpiErrorOutOfMemoryText);return 1;}
if(!b[2]){
b[2]=(s32)gpiMalloc(24);if(!b[2]){gpiSetErrorString(arg0,&gpiErrorOutOfMemoryText);return 1;}
c=(char *)b[2];v=6;do {c[0]=0;c[1]=0;c[2]=0;c[3]=0;c+=4;}while(--v);
v=M2C_FIELD(p,s32 *,0x430);M2C_FIELD(p,s32 *,0x430)=v+1;*(s32 *)b[2]=v;
}
f=(s32 *)b[2];
if(!gpiValueForKey(arg1,&gpiKeyMsg,buf,4096)){gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
if(!gpiValueForKey(buf,&gpiSepS,small,16)){gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
f[1]=ParseInt(small);
gpiFree(f[2]);f[2]=0;
if(!gpiValueForKey(buf,&gpiSepSs,text,256))text[0]=0;
f[2]=gpiStringDup(text);if(!f[2]){gpiSetErrorString(arg0,&gpiErrorOutOfMemoryText);return 1;}
gpiFree(f[3]);f[3]=0;
if(!gpiValueForKey(buf,&gpiSepLs,text,256))text[0]=0;
f[3]=gpiStringDup(text);if(!f[3]){gpiSetErrorString(arg0,&gpiErrorOutOfMemoryText);return 1;}
if(!gpiValueForKey(buf,&gpiSepIp,small,16))f[4]=0;
else {v=ParseInt(small);w=ParseInt(small);x=ParseInt(small);y=ParseInt(small);
f[4]=((w>>24)&255)|((y>>8)&0xff00)|((x<<8)&0xff0000)|((v<<24)&0xff000000);}

if(!gpiValueForKey(buf,&gpiSepP,small,16))v=0;
else {port=ParseInt(small);v=(u16)(((port>>8)&255)|((port<<8)&0xff00));}
f[5]=v;
cb3=M2C_FIELD(p,GpiCallbackPair *,0x1b4);if(!cb3.function)break;
q=gpiMalloc(12);if(!q){gpiSetErrorString(arg0,&gpiErrorOutOfMemoryText);return 1;}
q[0]=id;q[2]=f[0];q[1]=time;
r=gpiAddCallback(arg0,cb3,q,0,5);if(r)return r;break;
case 101:
if(!gpiValueForKey(arg1,&gpiKeyMsg,buf,4096)){gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
c=StringFind(buf,&gpiSepP);if(!c){gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
if(!c[3]){gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
err=ParseInt(c+3);c=StringFind(buf,&gpiSepL);
if(!c)text[0]=0;else StringCopyN(text,c+3,256);
cb4=M2C_FIELD(p,GpiCallbackPair *,0x1c4);if(!cb4.function)break;
q=gpiMalloc(0x108);if(!q){gpiSetErrorString(arg0,&gpiErrorOutOfMemoryText);return 1;}
q[0]=id;q[1]=err;StringCopy(q+2,text);
r=gpiAddCallback(arg0,cb4,q,0,0);if(r)return r;break;
case 102:
if(!gpiValueForKey(arg1,&gpiKeyMsg,buf,4096)){gpiSetError(arg0,1,&gpiErrorUnexpectedData);gpiCallErrorCallback(arg0,3,1);return 3;}
gpiSendMessageToPlayer(arg0,id,103,&gpiChallengeAccept);break;

}
return 0;
}
#pragma opt_instruction_scheduling reset
/* Queue a buddy message for server delivery with session key and recipient fields. */
s32 gpiSendMessageToServer(void **gpi, s32 playerId, s32 messageType, void *message) {
    void gpiAppendStringField(M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK gpiKeyBm;
    extern M2C_UNK gpiKeySessionKey;
    extern M2C_UNK gpiKeyTarget;
    extern M2C_UNK gpiKeyMsg;
    extern M2C_UNK gpiKeyFinal;
    u8 messageCopy[GPI_MESSAGE_STACK_SIZE];
    void *connection;
    connection = *gpi;
    StringCopyN(messageCopy, message, GPI_MESSAGE_COPY_SIZE);
    gpiAppendStringField(gpi, connection + GPI_CONN_OUTPUT_BUFFER, &gpiKeyBm);
    gpiAppendIntField(gpi, connection + GPI_CONN_OUTPUT_BUFFER, messageType);
    gpiAppendStringField(gpi, connection + GPI_CONN_OUTPUT_BUFFER, &gpiKeySessionKey);
    gpiAppendIntField(gpi, connection + GPI_CONN_OUTPUT_BUFFER, M2C_FIELD(connection, s32 *, GPI_CONN_SESSION_KEY));
    gpiAppendStringField(gpi, connection + GPI_CONN_OUTPUT_BUFFER, &gpiKeyTarget);
    gpiAppendIntField(gpi, connection + GPI_CONN_OUTPUT_BUFFER, playerId);
    gpiAppendStringField(gpi, connection + GPI_CONN_OUTPUT_BUFFER, &gpiKeyMsg);
    gpiAppendStringField(gpi, connection + GPI_CONN_OUTPUT_BUFFER, (s32)messageCopy);
    gpiAppendStringField(gpi, connection + GPI_CONN_OUTPUT_BUFFER, &gpiKeyFinal);
    return 0;
}

/* Queues an outgoing gpi message for a player: a peer that is already connected
 * takes it directly, otherwise the player's buddy record is used to create a
 * peer and start its challenge or connect, and when there is no usable record
 * the message goes to the server instead. */
s32 gpiSendMessageToPlayer(void **gpi,s32 playerId,s32 messageType,void *message) {
s32 gpiFindConnectedPeer(void **,s32);
s32 gpiFindBuddyStatus(void **,s32,void **);
s32 gpiCreatePeer(void **,s32,s32);
s32 gpiStartPeerChallenge(void **,s32);
s32 gpiPeerBeginConnect(void **,s32);
s32 gpiPeerAddMessage(void **,s32,s32,void *);
void *buddy; s32 peer,r;
peer=gpiFindConnectedPeer(gpi,playerId);
if(!peer) {
if(!gpiFindBuddyStatus(gpi,playerId,&buddy) || !M2C_FIELD(buddy,void **,8) || !M2C_FIELD(M2C_FIELD(buddy,void **,8),s32 *,0x14)) return gpiSendMessageToServer(gpi,playerId,messageType,message);
peer=gpiCreatePeer(gpi,playerId,1);
if(!peer) return 1;
if(!M2C_FIELD(buddy,s32 *,0x18)) {r=gpiStartPeerChallenge(gpi,peer);if(r)return r;}
else {r=gpiPeerBeginConnect(gpi,peer);if(r)return r;}
}
r=gpiPeerAddMessage(gpi,peer,messageType,message);if(!r)return 0;return r;
}

/* Sends the \authadd\ message that adds the profile `profileId` to the buddy
 * list, then releases the temporary profile record: its use count is decremented
 * and, once it reaches zero, its signature string and the record are freed. */
s32 gpiAuthAddProfile(void **connection, M2C_UNK profileId) {
    M2C_UNK gpiFree(s32);
    s32 gpiAppendAuthAddCommand(void **, void *);
    s32 gpiFindBuddyStatus(void **, M2C_UNK, void **);
    M2C_UNK gpiFreeBuddyList(void **, void *);
    s32 gpiPeerConnectionDone(void *);
    M2C_UNK gpiSetErrorString(void **, M2C_UNK *);
    extern M2C_UNK gGpiMsgInvalidProfile;
    void *profile;
    s32 result;
    void *gpi;

    gpi = *connection;
    if (gpiFindBuddyStatus(connection, profileId, &profile) == 0) {
        gpiSetErrorString(connection, &gGpiMsgInvalidProfile);
        return 2;
    }
    if (M2C_FIELD(profile, s32 *, 0x10) == 0) {
        gpiSetErrorString(connection, &gGpiMsgInvalidProfile);
        return 2;
    }
    result = gpiAppendAuthAddCommand(connection,profile);
    if (result != 0) {
        return result;
    }
    M2C_FIELD(profile, s32 *, 0x14) = (s32) (M2C_FIELD(profile, s32 *, 0x14) - 1);
    if ((M2C_FIELD(gpi, s32 *, 0x100) == 0) && ((s32) M2C_FIELD(profile, s32 *, 0x14) <= 0)) {
        gpiFree(M2C_FIELD(profile, s32 *, 0x10));
        M2C_FIELD(profile, s32 *, 0x10) = 0;
        if (gpiPeerConnectionDone(profile) != 0) {
            gpiFreeBuddyList(connection, profile);
        }
    }
    return 0;
}

s32 func_0204fb2c(void *unused,void *arg1,s32 arg2) {
s32 *p=M2C_FIELD(arg1,s32 **,8);
if(p) { s32 n=*p; if(n>arg2) *p=n-1; }
return 1;
}

/* Removes operation `opId` from the session: appends the removal fields to the
   outgoing message, frees the operation's shared buffers, unlinks it from the
   callback table and decrements the session's operation counter. */
s32 func_0204fb50(void **connection,s32 opId) {
void gpiAppendStringField(M2C_UNK,M2C_UNK,M2C_UNK);
s32 func_0204fb2c(void *,void *,s32);
s32 gpiFindBuddyStatus(void **,s32,void **);
s32 gpiPeerConnectionDone(void *);
M2C_UNK gpiFreeBuddyList(void **,void *);
M2C_UNK gpiSetErrorString(void **,M2C_UNK *);
M2C_UNK gpiFree(s32);
void AssertFailed(void *,void *,void *,s32);
extern M2C_UNK gGpiMsgInvalidProfile,data_020fde74,gpiKeySessionKey,data_020fde80,gpiKeyFinal,data_020fde90,data_020fde9c,data_020fdd84,data_020fdea8;
void *session=*connection,*op; s32 refCount;
if(!gpiFindBuddyStatus(connection,opId,&op)){gpiSetErrorString(connection,&gGpiMsgInvalidProfile);return 2;}
gpiAppendStringField(connection,session+0x1f4,&data_020fde74);
gpiAppendStringField(connection,session+0x1f4,&gpiKeySessionKey);
gpiAppendIntField(connection,session+0x1f4,M2C_FIELD(session,s32 *,0x198));
gpiAppendStringField(connection,session+0x1f4,&data_020fde80);
gpiAppendIntField(connection,session+0x1f4,M2C_FIELD(op,s32 *,0));
gpiAppendStringField(connection,session+0x1f4,&gpiKeyFinal);
if(M2C_FIELD(op,void **,8)){
refCount=M2C_FIELD(M2C_FIELD(op,void **,8),s32 *,0);
if(refCount<0)AssertFailed(&data_020fde90,&data_020fde9c,&data_020fdd84,0x1fd);
gpiFree(M2C_FIELD(M2C_FIELD(op,void **,8),s32 *,8));
M2C_FIELD(M2C_FIELD(op,void **,8),s32 *,8)=0;
gpiFree(M2C_FIELD(M2C_FIELD(op,void **,8),s32 *,12));
M2C_FIELD(M2C_FIELD(op,void **,8),s32 *,12)=0;
gpiFree(M2C_FIELD(op,s32 *,8));M2C_FIELD(op,s32 *,8)=0;
if(gpiPeerConnectionDone(op))gpiFreeBuddyList(connection,op);
if(--M2C_FIELD(session,s32 *,0x430)<0)AssertFailed(&data_020fdea8,&data_020fde9c,&data_020fdd84,0x204);
func_02055cd0(connection,func_0204fb2c,refCount);
}
return 0;
}

/* Appends one character to a gpi text buffer, growing its storage by
 * GPI_BUFFER_GROWTH bytes when it is full; sets the session's error and returns
 * 1 when that reallocation fails. */
s32 gpiAppendChar(void **gpi, GPIBuffer *buffer, s32 c) {
    extern char sAssertOutputBufferNotNull[], gGpiBufferFileName[], data_020fdf0c[];
    extern M2C_UNK gGpiRecvOutOfMemory;
    void AssertFailed(void *, void *, void *, s32);
    void *gpiRealloc(void *, s32);
    M2C_UNK gpiSetErrorString(void **, M2C_UNK *);
    s32 len, capacity;
    u8 *data;

    if (!buffer) AssertFailed(sAssertOutputBufferNotNull, gGpiBufferFileName, data_020fdf0c, 0x25);
    len = buffer->len;
    data = buffer->data;
    capacity = buffer->size;
    if (capacity == len) {
        capacity += GPI_BUFFER_GROWTH;
        data = gpiRealloc(data, capacity + 1);
        if (!data) {
            gpiSetErrorString(gpi, &gGpiRecvOutOfMemory);
            return 1;
        }
    }
    data[len] = c;
    data[len + 1] = 0;
    buffer->len++;
    buffer->size = capacity;
    buffer->data = data;
    return 0;
}

/* Append stringLen bytes, growing the buffer as needed and retaining a trailing NUL. */
s32 gpiAppendStringToBufferLen(void **connection, void *outputBuffer, void *string, s32 stringLen) {
    extern char sAssertGpiStringNotNull[], gGpiBufferFileName[], sGpiAppendStringToBufferLenName[];
    extern char sAssertGpiStringLengthNonnegative[], sAssertOutputBufferNotNull[];
    extern M2C_UNK gGpiRecvOutOfMemory;
    void AssertFailed(void *, void *, void *, s32);
    void *gpiRealloc(void *, s32);
    M2C_UNK gpiSetErrorString(void **, M2C_UNK *);
    s32 length, capacity;
    u8 *data;

    if (!string)
        AssertFailed(sAssertGpiStringNotNull, gGpiBufferFileName, sGpiAppendStringToBufferLenName, 0x51);
    if (stringLen < 0)
        AssertFailed(sAssertGpiStringLengthNonnegative, gGpiBufferFileName, sGpiAppendStringToBufferLenName, 0x52);
    if (!outputBuffer)
        AssertFailed(sAssertOutputBufferNotNull, gGpiBufferFileName, sGpiAppendStringToBufferLenName, 0x53);
    if (!string) return 0;
    length = ((GPIBuffer *)outputBuffer)->len;
    capacity = ((GPIBuffer *)outputBuffer)->size;
    data = ((GPIBuffer *)outputBuffer)->data;
    if (capacity - length < stringLen) {
        capacity += stringLen < GPI_BUFFER_GROWTH ? GPI_BUFFER_GROWTH : stringLen;
        data = gpiRealloc(data, capacity + 1);
        if (!data) {
            gpiSetErrorString(connection, &gGpiRecvOutOfMemory);
            return 1;
        }
    }
    MemCopy(data + length, string, stringLen);
    data[length + stringLen] = 0;
    ((GPIBuffer *)outputBuffer)->len += stringLen;
    ((GPIBuffer *)outputBuffer)->size = capacity;
    ((GPIBuffer *)outputBuffer)->data = data;
    return 0;
}

void gpiAppendStringField(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 gpiAppendStringToBufferLen(void **, void *, void *, s32);
    s32 StringLength(M2C_UNK);
    gpiAppendStringToBufferLen(arg0, arg1, arg2, StringLength(arg2));
}
