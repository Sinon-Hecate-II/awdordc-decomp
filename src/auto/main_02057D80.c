/* 28 functions from 0x02057D80 to 0x02058CA4 (main), found by ds-decomp. */
#include "common.h"
#include "net_session.h"
typedef struct { s32 unk_0; s32 unk_4; } Unk02050838Pair;

/* Fields a GPI server's error reply leaves on its connection. */
#define GPI_ERROR_CODE    0x418 /* s32: code the last error reply carried */
#define GPI_ERROR_MESSAGE 0x000 /* char[256]: text of the last error reply */

extern M2C_UNK sGpiBucketFindName, gGpiInfoState;
extern s32 gGpiInfoSocket;
extern M2C_UNK data_0213dcd0, sGpiAssertSet, sGpiBucketSourceFile, sGpiBucketNewName;

/* Processes the pending searches queued on the connection: allocates a temporary list of matching search entries, runs each through gpiProcessSingleSearch, and removes finished ones. */
s32 gpiProcessSearches(void **connection) {
    void *gpiMalloc(s32);
    void gpiFree(void *);
    void gpiSetErrorString(s32 *, s32);
    void AssertFailed(void *, void *, void *, s32);
    s32 func_020562d0(void **, void *);
    void gpiRemoveOperation(void **, void *);
    extern M2C_UNK gGpiSearchMsgOutOfMemory, data_020ff208, gGpiSearchSourceFile, data_020fee20;
    void *connectionInfo = *connection;
    void **list;
    void *entry;
    s32 count = 0, i, result;
    if (M2C_FIELD(connectionInfo, s32 *, 0x210) > 0) {
        list = gpiMalloc(M2C_FIELD(connectionInfo, s32 *, 0x210) * 4);
        if (!list) {
            gpiSetErrorString((s32 *)connection, (s32)&gGpiSearchMsgOutOfMemory);
            return 1;
        }
        for (entry = M2C_FIELD(connectionInfo, void **, 0x424); entry; entry = M2C_FIELD(entry, void **, 0x20)) {
            if (M2C_FIELD(entry, s32 *, 0) == 3 &&
                M2C_FIELD(entry, s32 *, 0x14) != 5 &&
                !M2C_FIELD(M2C_FIELD(entry, void **, 4), s32 *, 0x13c)) {
                if (count >= M2C_FIELD(connectionInfo, s32 *, 0x210)) {
                    AssertFailed(&data_020ff208, &gGpiSearchSourceFile, &data_020fee20, 0x563);
                }
                list[count++] = entry;
                M2C_FIELD(M2C_FIELD(entry, void **, 4), s32 *, 0x13c) = 1;
            }
        }
        for (i = 0; i < count; i++) {
            result = func_020562d0(connection, list[i]);
            if (result) {
                M2C_FIELD(list[i], s32 *, 0x1c) = result;
            }
        }
        for (i = 0; i < count; i++) {
            void *search = M2C_FIELD(list[i], void **, 4);
            M2C_FIELD(search, s32 *, 0x13c) = 0;
            if (M2C_FIELD(search, s32 *, 0x140)) {
                gpiRemoveOperation(connection, list[i]);
            }
        }
        gpiFree(list);
    }
    return 0;
}

/* Send the reply to a game-data transfer request: the \m\<type>\xfer\ header
 * carrying the request's three values, then the \version\1\result\<code> body
 * and the message framing around message (an empty one by default).  Returns 0
 * on success or the first send error. */
s32 gpiSendTransferReply(void **gpi, s32 *values, void *peer, s32 result, void *message) {
    s32 gpiPeerStartTransferMessage(void **, void *, s32, s32 *);
    s32 gpiSendString(void **, void *, void *);
    s32 gpiSendFramedMessage(void **, void *, void *, s32);
    void StringFormat(void *, void *, s32, s32);
    extern M2C_UNK gGpiEmptyMessage, gGpiVersionResultFormat;
    u8 buf[32];
    s32 error;
    if (!message) message = &gGpiEmptyMessage;
    error = gpiPeerStartTransferMessage(gpi, peer, GPI_MSG_XFER_REPLY, values);
    if (error) return error;
    StringFormat(buf, &gGpiVersionResultFormat, GPI_PROTOCOL_VERSION, result);
    error = gpiSendString(gpi, peer, buf);
    if (error) return error;
    error = gpiSendFramedMessage(gpi, peer, message, -1);
    if (!error) error = 0;
    return error;
}

/* Answer a game-data message (types 200..208): parse the \xfer\ location it
 * carries and reply with the same location and GPI_XFER_RESULT_UNSUPPORTED,
 * because the game's peers relay game data rather than transferring it. */
void gpiRefuseGameDataTransfer(void **gpi, void *peer, s32 messageType, char *command, char *message, s32 length) {
s32 gpiValueForKey(s32,void *,void *,s32);s32 StringScanf(void *,void *,void *,void *,void *);
extern char gGpiXferKey[],gGpiXferLocationFormat[];
u8 buf[64];s32 z,y,x;
if(!gpiValueForKey((s32)command,&gGpiXferKey,buf,64))return;
if(StringScanf(buf,&gGpiXferLocationFormat,&x,&y,&z)!=3)return;
gpiSendTransferReply(gpi,&x,peer,GPI_XFER_RESULT_UNSUPPORTED,NULL);
}

/* Handles a server message of type 4 (a player's "login" reply): any "rn" request
   from the server is answered by the caller of gpiProcessErrorReply, anything else must
   be the player's own "\rn\" reply.  A reply naming a player queues the login
   callback (the player's id is read into the connection at 0x418), otherwise the
   request is simply finished.  Returns 0 or an error code. */
s32 gpiProcessLoginReply(void **a,void *b,s32 c) {
s32 gpiProcessErrorReply(void **,s32,s32);void gpiSetError(void **,s32,s32);void gpiSetErrorString(s32 *,s32);
s32 StringCompareN(s32,void *,s32);void gpiCallErrorCallback(void *,s32,s32);void *gpiMalloc(s32);s32 gpiAddCallback(void *,Unk02050838Pair,s32 *,void *,s32);void gpiRemoveOperation(void **,void *);
extern M2C_UNK gGsKeyRoomName,data_020ff260,data_020ff290;
Unk02050838Pair pair;s32 *p;s32 r;
if(gpiProcessErrorReply(a,c,1))return 4;
if(StringCompareN(c,&gGsKeyRoomName,4)){gpiSetError(a,1,(s32)&data_020ff260);gpiCallErrorCallback(a,3,1);return 3;}
pair=*(Unk02050838Pair *)((u8 *)b+12);
if(pair.unk_0){p=gpiMalloc(4);if(!p){gpiSetErrorString((s32 *)a,(s32)&data_020ff290);return 1;}*p=0;r=gpiAddCallback(a,pair,p,b,0);if(r)return r;}
gpiRemoveOperation(a,b);return 0;
}

/* Copy up to `n` bytes of `src` into `dst`, NUL-terminating at dst[n-1], and
 * return dst + n.  Both pointers are asserted non-null (the GameSpy strzcpy). */
M2C_UNK StringCopyN(s32 dst,s32 src,s32 n) {
void AssertFailed(void *,void *,void *,s32);void StringCopyPad(s32,s32,s32);
extern M2C_UNK sGpiAssertDestNotNull,sGpiUtilitySourceFile,sGpiStrZCpyName,sGpiAssertSrcNotNull;
if(!dst)AssertFailed(&sGpiAssertDestNotNull,&sGpiUtilitySourceFile,&sGpiStrZCpyName,47);
if(!src)AssertFailed(&sGpiAssertSrcNotNull,&sGpiUtilitySourceFile,&sGpiStrZCpyName,48);
StringCopyPad(dst,src,n);
M2C_FIELD(dst+n,u8 *,-1)=0;
return dst+n;
}

void gpiLogMessage(s32 a, ...) {}

/* Handle a server error reply ("\error\<code>\errmsg\<text>"): store the code
   and the message on the connection and, when asked to, report the error to the
   application (an application-level error when the reply says it is fatal).
   Returns 1 for an error reply, 0 for any other message. */
s32 gpiProcessErrorReply(void **connection, s32 text, s32 report) {
s32 StringCompareN(s32,void *,s32);s32 gpiValueForKey(s32,void *,void *,s32);s32 ParseInt(void *);void *StringFind(s32,void *);void gpiCallErrorCallback(void *,s32,s32);
extern M2C_UNK gGsKeyError,gGsKeyErr,gGsKeyErrMsg,gGsKeyFatal;
u8 buf[16];void *info=*connection;
if(StringCompareN(text,&gGsKeyError,7)==0){
if(gpiValueForKey(text,&gGsKeyErr,buf,16))M2C_FIELD(info,s32 *,GPI_ERROR_CODE)=ParseInt(buf);
if(!gpiValueForKey(text,&gGsKeyErrMsg,info,256))M2C_FIELD(info,u8 *,GPI_ERROR_MESSAGE)=0;
if(report){s32 fatal=StringFind(text,&gGsKeyFatal)!=0;gpiCallErrorCallback(connection,4,fatal!=0);}
return 1;}return 0;
}

/* Copies the value of key from a GameSpy command string ("\key\value") into
 * value, NUL-terminated and at most len bytes; returns 0 when the key is absent. */
s32 gpiValueForKey(s32 command,void *key,void *value,s32 len){
void AssertFailed(void *,void *,void *,s32);void *StringFind(s32,void *);s32 StringLength(void *);
extern M2C_UNK sGpiAssertCommandNotNull,sGpiUtilitySourceFile,sGpiValueForKeyName,sGpiAssertKeyNotNull,sGpiAssertValueNotNull,sGpiAssertLenPositive;
s8 *field;s32 separator,ch;s32 i;
if(!command)AssertFailed(&sGpiAssertCommandNotNull,&sGpiUtilitySourceFile,&sGpiValueForKeyName,269);
if(!key)AssertFailed(&sGpiAssertKeyNotNull,&sGpiUtilitySourceFile,&sGpiValueForKeyName,270);
if(!value)AssertFailed(&sGpiAssertValueNotNull,&sGpiUtilitySourceFile,&sGpiValueForKeyName,271);
if(len<=0)AssertFailed(&sGpiAssertLenPositive,&sGpiUtilitySourceFile,&sGpiValueForKeyName,272);
separator=*(s8 *)key;field=StringFind(command,key);if(!field)return 0;
field+=StringLength(key);
for(i=0;i<len-1 && (ch=field[i])!=0 && ch!=separator;i++)*(s8 *)((u32)value+(u32)i)=ch;
((s8 *)value)[i]=0;return 1;
}

/* Checks the connection's socket for activity: a poll error reports error 5 and
 * returns 3; a rejected connection sets *state to 4 and an accepted connection to
 * 3 (both succeed); no activity sets *state to 0. */
s32 gpiCheckConnectionSocket(s32 conn, s32 socket, s32 *state){
s32 PollOneFd(s32,s32,s32*,s32*);void gpiLogMessage(s32,...);void gpiSetError(void**,s32,s32);void gpiCallErrorCallback(void*,s32,s32);
extern M2C_UNK gpiLogErrorConnecting, gpiErrorCheckingCompletedConnection, gpiLogConnectionRejected, gpiLogConnectionAccepted;
s32 accepted=0,rejected=0; s32 r=PollOneFd(socket,0,&accepted,&rejected);
if(r==-1){gpiLogMessage(conn,&gpiLogErrorConnecting);gpiSetError((void**)conn,5,(s32)&gpiErrorCheckingCompletedConnection);gpiCallErrorCallback((void*)conn,3,1);return 3;}
if(r>0){if(rejected){gpiLogMessage(conn,&gpiLogConnectionRejected);*state=4;return 0;}if(accepted){gpiLogMessage(conn,&gpiLogConnectionAccepted);*state=3;return 0;}}
*state=0;return 0;
}

#pragma opt_propagation off
s32 func_02058450(void **arg0, s8 *arg1, s32 *arg2, void *arg3, void *arg4) {
    void AssertFailed(void *, void *, void *, s32);
    void gpiSetError(void **, s32, M2C_UNK);
    void gpiCallErrorCallback(void *, s32, s32);
    extern M2C_UNK data_020ff3cc, sGpiUtilitySourceFile, data_020ff2b8, sGpiAssertKeyNotNull, sGpiAssertValueNotNull, data_020ff3dc;
    s32 idx;
    s8 *p;
    s8 *dstA;
    s32 cnt;
    s8 ch;
    s8 *dstB;
    s32 cnt2;
    s8 ch2;

    dstA = (s8 *)arg3;
    dstB = (s8 *)arg4;
    if (!arg1) {
        AssertFailed(&data_020ff3cc, &sGpiUtilitySourceFile, &data_020ff2b8, 0x199);
    }
    if (!dstA) {
        AssertFailed(&sGpiAssertKeyNotNull, &sGpiUtilitySourceFile, &data_020ff2b8, 0x19a);
    }
    if (!dstB) {
        AssertFailed(&sGpiAssertValueNotNull, &sGpiUtilitySourceFile, &data_020ff2b8, 0x19b);
    }
    idx = *arg2;
    if (arg1[idx] != 0x5c) {
        gpiSetError(arg0, 1, (s32)&data_020ff3dc);
        gpiCallErrorCallback(arg0, 3, 1);
        return 3;
    }
    p = arg1 + idx;
    ch = p[1];
    arg1 = p + 2;
    cnt = 0;
    while (ch != 0x5c) {
        if (ch == 0) {
            gpiSetError(arg0, 1, (s32)&data_020ff3dc);
            gpiCallErrorCallback(arg0, 3, 1);
            return 3;
        }
        if (cnt == 0x1ff) {
                gpiSetError(arg0, 1, (s32)&data_020ff3dc);
                gpiCallErrorCallback(arg0, 3, 1);
                return 3;
            }
        *dstA++ = ch;
        ch = *arg1++;
        cnt++;
    }
    *dstA = 0;
    cnt2 = 0;
    while ((ch2 = *arg1++) != 0x5c && ch2 != 0) {
        if (cnt2 == 0x1ff) {
            gpiSetError(arg0, 1, (s32)&data_020ff3dc);
            gpiCallErrorCallback(arg0, 3, 1);
            return 3;
        }
        *dstB++ = ch2;
        cnt2++;
    }
    *dstB = 0;
    *arg2 += arg1 - p - 1;
    return 0;
}
#pragma opt_propagation reset
void gpiSetError(void **arg0, s32 arg1, M2C_UNK arg2) {
    void *temp_r4;

    temp_r4 = *arg0;
    StringCopyN(temp_r4, arg2, 0x100);
    M2C_FIELD(temp_r4, s32 *, 0x418) = arg1;
}

void gpiSetErrorString(s32 *arg0, M2C_UNK arg1) {
    M2C_UNK StringCopyN(s32, M2C_UNK, M2C_UNK);
    StringCopyN(*arg0, arg1, 0x100);
}

/* gbucket.c BucketNew: add a key/value entry to a bucket store (the module's
 * default store when store is null): duplicate the key, start the entry with one
 * sample and no value yet, set the value, insert the entry into the store's hash
 * table and return the value it now holds. */
void *BucketNew(void *store,s32 key,s32 type,void *value){
void *BucketValue(void *);void AssertFailed(void *,void *,void *,s32);s32 gpiStringDup(s32);
s32 BucketSetValue(void *,void *);void TableEnter(s32,void *);void *BucketFind(void *,s32);
s32 entry[5];
if(!store)store=M2C_FIELD(&data_0213dcd0,void **,4);
if(!store)AssertFailed(&sGpiAssertSet,&sGpiBucketSourceFile,&sGpiBucketNewName,120);
M2C_FIELD(entry,s32 *,GPI_BUCKET_KEY)=gpiStringDup(key);
M2C_FIELD(entry,s32 *,GPI_BUCKET_TYPE)=type;
M2C_FIELD(entry,s32 *,GPI_BUCKET_VALUE)=0;
M2C_FIELD(entry,s32 *,GPI_BUCKET_COUNT)=1;
BucketSetValue(entry,value);TableEnter(M2C_FIELD(store,s32 *,0),entry);
return BucketValue(BucketFind(store,key));
}

s32 func_020586f4(void *a,s32 b,void *c){
void *BucketFind(void *,s32);s32 BucketSetValue(void *,void *);
void *p=BucketFind(a,b);if(!p)return 0;
M2C_FIELD(p,s32 *,8)=0;return BucketSetValue(p,c);
}

/* gbucket.c BucketAdd: add `value` to the entry for `key` in bucket `store` and
 * store the sum, integer or double by the entry's type; a string entry gets the
 * text appended instead.  Returns the entry's new value, or 0 when the key is
 * absent. */
s32 BucketAdd(void *store, s32 key, void *value) {
    void *BucketValue(void *);
    M2C_UNK *BucketIntValue(s32);
    M2C_UNK *BucketDoubleValue(s32, s32);
    void *BucketFind(void *, s32);
    s32 BucketSetValue(void *, void *);
    s32 BucketConcat(void *, s32, void *);
    s64 func_02070134(s64, s64); /* the C runtime's double addition */
    void *entry = BucketFind(store, key);
    void *old;
    s64 sum;

    if (!entry) return 0;
    if (M2C_FIELD(entry, s32 *, GPI_BUCKET_TYPE) == GPI_BUCKET_INT) {
        old = BucketValue(entry);
        return BucketSetValue(entry, BucketIntValue(M2C_FIELD(value, s32 *, 0) + M2C_FIELD(old, s32 *, 0)));
    } else if (M2C_FIELD(entry, s32 *, GPI_BUCKET_TYPE) == GPI_BUCKET_DOUBLE) {
        old = BucketValue(entry);
        sum = func_02070134(*(s64 *)value, *(s64 *)old);
        return BucketSetValue(entry, BucketDoubleValue((s32)sum, (s32)(sum >> 32)));
    } else return BucketConcat(store, key, value);
}

/* gbucket.c BucketSubtract: subtract `value` from the entry for `key` in bucket
 * `store`, integer or double by the entry's type; other types are left alone.
 * Returns the entry's new value, or 0 when the key is absent. */
s32 BucketSubtract(void *store,s32 key,void *value) {
void *BucketFind(void *,s32);M2C_UNK *BucketIntValue(s32);s32 BucketSetValue(void *,void *);
void *BucketValue(void *);M2C_UNK *BucketDoubleValue(s32,s32);
s64 func_02070b70(s64,s64); /* the C runtime's double subtraction */
void *entry=BucketFind(store,key);void *old;s64 difference;
if(!entry)return 0;
if(M2C_FIELD(entry,s32 *,GPI_BUCKET_TYPE)==GPI_BUCKET_INT){old=BucketValue(entry);return BucketSetValue(entry,BucketIntValue(M2C_FIELD(old,s32 *,0) - M2C_FIELD(value,s32 *,0)));}
if(M2C_FIELD(entry,s32 *,GPI_BUCKET_TYPE)==GPI_BUCKET_DOUBLE){old=BucketValue(entry);difference=func_02070b70(*(s64 *)old,*(s64 *)value);return BucketSetValue(entry,BucketDoubleValue((s32)difference,(s32)(difference>>32)));}
return (s32)BucketValue(entry);
}

/* gbucket.c BucketMultiply: multiply the entry for `key` in bucket `store` by
 * `value`, integer or double by the entry's type; other types are left alone.
 * Returns the entry's new value, or 0 when the key is absent. */
s32 BucketMultiply(void *store,s32 key,void *value) {
void *BucketFind(void *,s32);M2C_UNK *BucketIntValue(s32);s32 BucketSetValue(void *,void *);
void *BucketValue(void *);M2C_UNK *BucketDoubleValue(s32,s32);
s64 func_02070658(s64,s64); /* the C runtime's double multiplication */
void *entry=BucketFind(store,key);void *old;s64 product;
if(!entry)return 0;
if(M2C_FIELD(entry,s32 *,GPI_BUCKET_TYPE)==GPI_BUCKET_INT){old=BucketValue(entry);return BucketSetValue(entry,BucketIntValue(M2C_FIELD(value,s32 *,0) * M2C_FIELD(old,s32 *,0)));}
if(M2C_FIELD(entry,s32 *,GPI_BUCKET_TYPE)==GPI_BUCKET_DOUBLE){old=BucketValue(entry);product=func_02070658(*(s64 *)value,*(s64 *)old);return BucketSetValue(entry,BucketDoubleValue((s32)product,(s32)(product>>32)));}
return (s32)BucketValue(entry);
}

/* gbucket.c BucketDivide: divide the entry for `key` in bucket `store` by
 * `value`, integer or double by the entry's type; other types are left alone.
 * Returns the entry's new value, or 0 when the key is absent. */
s32 BucketDivide(void *store, s32 key, void *value) {
    void *BucketFind(void *, s32);
    M2C_UNK *BucketIntValue(s32);
    s32 BucketSetValue(void *, void *);
    void *BucketValue(void *);
    M2C_UNK *BucketDoubleValue(s32, s32);
    s64 RuntimeDoubleDivide(s64, s64);
    s32 RuntimeIntDivMod(s32, s32);
    void *entry = BucketFind(store, key);
    void *old;
    s64 quotient;

    if (!entry) return 0;
    if (M2C_FIELD(entry, s32 *, GPI_BUCKET_TYPE) == GPI_BUCKET_INT) {
        old = BucketValue(entry);
        return BucketSetValue(entry, BucketIntValue(RuntimeIntDivMod(M2C_FIELD(old, s32 *, 0), M2C_FIELD(value, s32 *, 0))));
    }
    if (M2C_FIELD(entry, s32 *, GPI_BUCKET_TYPE) == GPI_BUCKET_DOUBLE) {
        old = BucketValue(entry);
        quotient = RuntimeDoubleDivide(*(s64 *)old, *(s64 *)value);
        return BucketSetValue(entry, BucketDoubleValue((s32)quotient, (s32)(quotient >> 32)));
    }
    return (s32)BucketValue(entry);
}

/* BucketConcat (gbucket.c): append the string `text` to the string value of key
 * `key` in bucket `store`, replacing the entry's value with the concatenation.
 * Asserts that the entry is a string entry; returns the entry's new value, or 0
 * when the key is absent. */
s32 BucketConcat(void *store,s32 key,void *text) {
void *BucketFind(void *,s32);void *BucketValue(void *);void AssertFailed(void *,void *,void *,s32);s32 StringLength(void *);void *gpiMalloc(s32);void StringCopy(void *,void *);void StringAppend(void *,void *);void gpiFree(void *);s32 BucketSetValue(void *,void *);
extern M2C_UNK sGpiAssertBucketTypeString,sGpiBucketSourceFile,sGpiBucketConcatName;
void *entry=BucketFind(store,key);void *value;void *concat;s32 length;
if(!entry)return 0;
if(M2C_FIELD(entry,s32 *,GPI_BUCKET_TYPE)!=GPI_BUCKET_STRING)AssertFailed(&sGpiAssertBucketTypeString,&sGpiBucketSourceFile,&sGpiBucketConcatName,209);
value=BucketValue(entry);length=StringLength(value);length+=StringLength(text);
concat=gpiMalloc(length+1);StringCopy(concat,value);StringAppend(concat,text);BucketSetValue(entry,concat);gpiFree(concat);return (s32)BucketValue(entry);
}

/* Fold a new sample into a gpi key/value entry and store the entry's running
 * average, then return the value.  The entry keeps its value type at +0x04 (0
 * int, 1 double, 2 string), its sample count at +0x08 and the value at +0x0C;
 * both numeric types average (count * old + new) / count, a string entry is
 * left alone. */
s32 gpiValueAverage(void *store, s32 key, void *value) {
    s64 func_020705dc(s32);
    s64 func_02070658(s64, s64);
    s64 func_02070134(s64, s64);
    s64 RuntimeDoubleDivide(s64, s64);
    s32 RuntimeIntDivMod(s32, s32);
    void *BucketFind(void *, s32);
    void *BucketValue(void *);
    s32 BucketSetValue(void *, void *);
    M2C_UNK *BucketIntValue(s32);
    M2C_UNK *BucketDoubleValue(s32, s32);
    void *entry = BucketFind(store, key);
    void *old;
    s32 count;
    s64 average;

    if (!entry) return 0;
    if (M2C_FIELD(entry, s32 *, 4) == 0) {
        old = BucketValue(entry);
        count = ++M2C_FIELD(entry, s32 *, 8);
        return BucketSetValue(entry, BucketIntValue(RuntimeIntDivMod(count * M2C_FIELD(old, s32 *, 0) + M2C_FIELD(value, s32 *, 0), count)));
    }
    if (M2C_FIELD(entry, s32 *, 4) == 1) {
        old = BucketValue(entry);
        count = ++M2C_FIELD(entry, s32 *, 8);
        average = func_02070134(*(s64 *)value, func_02070658(func_020705dc(count), *(s64 *)old));
        average = RuntimeDoubleDivide(average, func_020705dc(count));
        return BucketSetValue(entry, BucketDoubleValue((s32)average, (s32)(average >> 32)));
    }
    return (s32)BucketValue(entry);
}

M2C_UNK *BucketIntValue(s32 a) {
    *(s32 *)&data_0213dcd0 = a;
    return (M2C_UNK *)&data_0213dcd0;
}

M2C_UNK *BucketDoubleValue(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0213dcd0;
    extern M2C_UNK data_0213dcd8;
    M2C_FIELD(&data_0213dcd0, s32 *, 8) = arg0;
    M2C_FIELD(&data_0213dcd0, s32 *, 0xC) = arg1;
    return &data_0213dcd8;
}

s8 *ConvertBackslashesToSlashes(s8 *p) {
s8 *q=p;s32 c=*p;
if(c){do{if(c==92)*p=47;c=*++p;}while(c);}
return q;
}

/* gbucket.c BucketSetValue: store `value` in bucket entry `entry`, by the
 * entry's value type (integer, double, or owned string copy that has its
 * backslashes turned into slashes); returns the entry's value. */
s32 BucketSetValue(void *entry, void *value) {
    void gpiFree(void *);
    s32 gpiStringDup(s32);
    s8 *ConvertBackslashesToSlashes(s8 *);
    void *BucketValue(void *);
    s32 type = M2C_FIELD(entry, s32 *, GPI_BUCKET_TYPE);
    void *stored;

    if (type == GPI_BUCKET_INT) {
        M2C_FIELD(entry, s32 *, GPI_BUCKET_VALUE) = M2C_FIELD(value, s32 *, 0);
    } else if (type == GPI_BUCKET_DOUBLE) {
        M2C_FIELD(entry, double *, GPI_BUCKET_VALUE) = M2C_FIELD(value, double *, 0);
    } else if (type == GPI_BUCKET_STRING) {
        stored = M2C_FIELD(entry, void **, GPI_BUCKET_VALUE);
        if (stored) gpiFree(stored);
        if (!value) stored = 0;
        else stored = ConvertBackslashesToSlashes((s8 *)gpiStringDup((s32)value));
        M2C_FIELD(entry, void **, GPI_BUCKET_VALUE) = stored;
    }
    return (s32)BucketValue(entry);
}

void *BucketValue(void *arg0) {
    if (arg0 == NULL) {
        return NULL;
    }
    if (M2C_FIELD(arg0, s32 *, 4) == 2) {
        return M2C_FIELD(arg0, void **, 0xC);
    }
    return arg0 + 0xC;
}

/* gbucket.c BucketFind: look up the entry for `key` in bucket `store` (or the
   module's default store, kept at data_0213dcd0+4, when store is null) and
   return its value, or 0 when there is no such entry. */
void *BucketFind(void *store, s32 key) {
    void AssertFailed(void *, void *, void *, s32);
    void *TableLookup(s32, void *);
    s32 keyBuf[5];
    if (!store) store = M2C_FIELD(&data_0213dcd0, void **, 4);
    if (!store) AssertFailed(&sGpiAssertSet, &sGpiBucketSourceFile, &sGpiBucketFindName, 0x153);
    keyBuf[0] = key;
    return TableLookup(M2C_FIELD(store, s32 *, 0), keyBuf);
}

/* Closes the GPI info module's connection: shuts the socket down and closes it,
 * then frees the module's profile list and receive buffer. */
void gpiInfoCloseSocket(void){
void func_020496cc(s32,s32);void ghiCloseSocket(s32);void gpiInfoFreeProfiles(void);void gpiFree(void *);
if(gGpiInfoSocket!=-1){func_020496cc(gGpiInfoSocket,2);ghiCloseSocket(gGpiInfoSocket);}
gGpiInfoSocket=-1;
gpiInfoFreeProfiles();
if(M2C_FIELD(&gGpiInfoState,void **,GPI_INFO_RECV_BUFFER)){gpiFree(M2C_FIELD(&gGpiInfoState,void **,GPI_INFO_RECV_BUFFER));M2C_FIELD(&gGpiInfoState,s32 *,GPI_INFO_RECV_BUFFER)=0;M2C_FIELD(&gGpiInfoState,s32 *,GPI_INFO_RECV_CAPACITY)=0;M2C_FIELD(&gGpiInfoState,s32 *,GPI_INFO_USED)=0;}
}

s32 func_02058c84(void) {
    extern s32 gGpiInfoSocket;
    if (gGpiInfoSocket != -1) {
        return 1;
    }
    return 0;
}

