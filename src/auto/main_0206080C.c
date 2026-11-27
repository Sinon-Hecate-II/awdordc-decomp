/* 57 functions from 0x0206080C to 0x020617BC (main), found by ds-decomp. */
#include "common.h"
#include "sb_serverlist.h"
typedef struct { u16 count; char buf[128]; } Packet60E;
typedef struct { u8 a,b; } Pair60E;
static inline void CopyPair60E(u8 *d,const u8 *s) { *(Pair60E *)d=*(const Pair60E *)s; }
static inline u16 SwapPair60E(u16 v) { return (u8)(v>>8)|((v<<8)&0xff00); }

/* Give up on the detail queries in the pending list that have waited more than
 * SB_QUERY_TIMEOUT_MS for a reply: flag each server as timed out, store the
 * timeout as its ping, drop the query's flags, report the failed query through
 * the list's query callback and take the server off the pending list. */
void Qr2Query_ExpireTimeouts(void *list) {
    u32 GetSystemTickMilliseconds();
    M2C_UNK QueryQueue_Pop(void *);
    u32 now;
    GpiPlayer *server;

    now = GetSystemTickMilliseconds();
    if (M2C_FIELD(list, GpiPlayer **, SB_LIST_REQUESTS) == NULL) {
        return;
    }
loop_3:
    if (now <= (u32) (M2C_FIELD(list, GpiPlayer **, SB_LIST_REQUESTS)->ping + SB_QUERY_TIMEOUT_MS)) {
        return;
    }
    M2C_FIELD(list, GpiPlayer **, SB_LIST_REQUESTS)->flags = (u8) (M2C_FIELD(list, GpiPlayer **, SB_LIST_REQUESTS)->flags | SB_SERVER_FLAG_TIMED_OUT);
    M2C_FIELD(list, GpiPlayer **, SB_LIST_REQUESTS)->ping = SB_QUERY_TIMEOUT_MS;
    server = M2C_FIELD(list, GpiPlayer **, SB_LIST_REQUESTS);
    server->flags = (u8) (server->flags & SB_SERVER_FLAG_QUERY_MASK);
    M2C_FIELD(list, M2C_UNK (**)(void *, M2C_UNK, void *, s32), SB_LIST_ON_QUERY_DONE)(list, SB_QUERY_STAGE_FAILED, M2C_FIELD(list, GpiPlayer **, SB_LIST_REQUESTS), M2C_FIELD(list, s32 *, SB_LIST_QUERY_DATA));
    QueryQueue_Pop((u8 *)list + SB_LIST_REQUESTS);
    if (M2C_FIELD(list, GpiPlayer **, SB_LIST_REQUESTS) == NULL) {
        return;
    }
    goto loop_3;
}

/* Start waiting detail queries while fewer than SB_LIST_QUERY_LIMIT are in flight,
 * taking each one off the waiting queue and sending it. */
void Qr2Query_SendWaitingQueries(void *list) {
    M2C_UNK QueryQueue_Pop(void *);
    M2C_UNK Qr2Query_SendQuery(void *, void *);

    while ((s32) M2C_FIELD(list, s32 *, SB_LIST_PENDING) < (s32) M2C_FIELD(list, s32 *, SB_LIST_QUERY_LIMIT) && (s32) M2C_FIELD(list, s32 *, SB_LIST_WAITING_COUNT) > 0) {
        Qr2Query_SendQuery(list, QueryQueue_Pop(list + SB_LIST_WAITING));
    }
}

/* One tick of a pending QR2 query list: read whatever replies have arrived, give
 * up on queries that have timed out, start waiting queries while there is room,
 * and once nothing is pending report the query as complete. */
void Qr2Query_Update(void *list) {
    M2C_UNK func_02060678(void *, s32);

    if (M2C_FIELD(list, s32 *, SB_LIST_PENDING) == 0) {
        return;
    }
    func_02060678(list, 0);
    Qr2Query_ExpireTimeouts(list);
    if (M2C_FIELD(list, s32 *, SB_LIST_WAITING_COUNT) > 0) {
        Qr2Query_SendWaitingQueries(list);
    }
    if (M2C_FIELD(list, s32 *, SB_LIST_PENDING) != 0) {
        return;
    }
    M2C_FIELD(list, M2C_UNK (**)(void *, s32, s32, M2C_UNK), SB_LIST_ON_QUERY_DONE)(list, SB_QUERY_STAGE_COMPLETE, 0, M2C_FIELD(list, M2C_UNK *, SB_LIST_QUERY_DATA));
}

/* Remember that the query asks for the field with key id `keyId`: append it to
 * the list's field array, unless SB_LIST_MAX_FIELDS are already recorded. */
void AddServerListField(void *list, u8 keyId) {
    s32 count;

    count = M2C_FIELD(list, s32 *, SB_LIST_FIELD_COUNT);
    if (count >= SB_LIST_MAX_FIELDS) {
        return;
    }
    M2C_FIELD(list, s32 *, SB_LIST_FIELD_COUNT) = (s32) (count + 1);
    M2C_FIELD((list + count), s8 *, SB_LIST_FIELDS) = keyId;
}

/* Take a server record off the browser's query queues: drop it from the
 * in-flight list when a reply was still awaited, otherwise from the list of
 * queries that had not been sent yet. */
void Qr2Query_UnlinkServer(void *list, void *server) {
    M2C_UNK Qr2Query_RemoveRequest(void *, void *);

    if (Qr2Query_RemoveRequest((u8 *)list + SB_LIST_REQUESTS, server) != 0) {
        return;
    }
    Qr2Query_RemoveRequest((u8 *)list + SB_LIST_WAITING, server);
}

void HashInternedString(s8 **arg0, s32 arg1) {
    s32 func_02060fe8(s8 *, s32);

    func_02060fe8(*arg0, arg1);
}

/* String-intern table comparison callback: compare the key strings of two
 * interned entries case-insensitively. */
void CompareInternedStrings(s32 *keyA, s32 *keyB) {
    M2C_UNK StringCompareNoCase(s32, s32);
    StringCompareNoCase(*keyA, *keyB);
}

void FreeInternedString(s32 *arg0) {
    M2C_UNK gpiFree(s32);
    gpiFree(*arg0);
}

/* The QR2 parser's shared string-intern table, built on first use: 100 buckets of
 * 8-byte InternedString elements, keyed by a case-insensitive comparison of their
 * string, whose key string is freed when the element is removed. */
s32 GetStringInternTable(void) {
    extern M2C_UNK gQr2ParseState;
    s32 TableNew2(s32, s32, s32, void *, void *, void *);
    if (M2C_FIELD(&gQr2ParseState, s32 *, SB_QR2_PARSE_INTERN_TABLE) == 0) {
        M2C_FIELD(&gQr2ParseState, s32 *, SB_QR2_PARSE_INTERN_TABLE) = TableNew2(8, 0x64, 2, HashInternedString, CompareInternedStrings, FreeInternedString);
    }
    return M2C_FIELD(&gQr2ParseState, s32 *, SB_QR2_PARSE_INTERN_TABLE);
}

/* Release the QR2 parser's shared string-intern table once no string is interned
 * in it any more. */
void FreeStringInternTableIfEmpty(void) {
    extern M2C_UNK gQr2ParseState;
    s32 TableCount(s32);
    M2C_UNK TableFree(s32);
    if (M2C_FIELD(&gQr2ParseState, s32 *, SB_QR2_PARSE_INTERN_TABLE) == 0) return;
    if (TableCount(M2C_FIELD(&gQr2ParseState, s32 *, SB_QR2_PARSE_INTERN_TABLE)) != 0) return;
    TableFree(M2C_FIELD(&gQr2ParseState, s32 *, SB_QR2_PARSE_INTERN_TABLE));
    M2C_FIELD(&gQr2ParseState, s32 *, SB_QR2_PARSE_INTERN_TABLE) = 0;
}

/* Free the server record that `server` points at: free its key/value table,
 * clear the field and free the record itself. */
void SBServerFree(GpiPlayer **server) {
    M2C_UNK TableFree(s32);
    GpiPlayer *record;

    record = *server;
    TableFree(record->keyValues);
    record->keyValues = 0;
    gpiFree(record);
}

/* Store an interned key/value string pair in a gpi player record's key/value
 * table (GpiPlayer.keyValues at +0x18). */
void gpiPlayerSetString(GpiPlayer *player, const char *key, const char *value) {
    s32 StringIntern(s32, const char *);
    void TableEnter(s32, s32 *);
    s32 values[2];
    values[0] = StringIntern(0, key);
    values[1] = StringIntern(0, value);
    TableEnter(player->keyValues, values);
}

/* Format an integer as decimal text and store it as the string value of `key`
 * in a gpi player record's key/value table. */
void gpiPlayerSetInt(GpiPlayer *player, const char *key, s32 value) {
    s32 StringFormat(void *, void *, ...);
    extern M2C_UNK gGpiIntFormat;
    char buf[20];

    StringFormat(buf, &gGpiIntFormat, value);
    gpiPlayerSetString(player, key, buf);
}

/* GameSpy SBServerGetStringValue: look up the interned key `key` in the server's
 * key/value table and return its value, or `def` when the key is absent (0 when
 * the server itself is NULL). */
s32 SBServerGetStringValue(GpiPlayer *server, s32 key, s32 def) {
    void *TableLookup(s32, s32 *);
    M2C_UNK AssertFailed(void *, void *, void *, s32);
    extern M2C_UNK sSbServerAssertServer, sSbServerSourceFile, sSbServerGetStringValueAName;
    s32 keyBuf[2];
    void *entry;

    if (!server) AssertFailed(&sSbServerAssertServer, &sSbServerSourceFile, &sSbServerGetStringValueAName, 0x97);
    if (!server) return 0;
    keyBuf[0] = key;
    entry = TableLookup(server->keyValues, keyBuf);
    if (entry) def = M2C_FIELD(entry, s32 *, 4);
    return def;
}

s32 SBServerGetIntValue(GpiPlayer *server, s32 key, s32 defaultVal) {
    /* Return the numeric value of the named server key, or defaultVal when the
     * server has no such value or its string isn't a number.  The "ping" key
     * is handled directly from the record's ping field.  (GameSpy sb_sbGetInt.) */
    s32 StringCompare(s32, void *);
    s32 ParseInt(void *);
    extern M2C_UNK sPingKey; extern u16 gCharClassTable[];
    s8 *p, *q; u8 c; s32 isDigit;
    if (!server) return defaultVal;
    if (!StringCompare(key, &sPingKey)) return SBServerGetPing(server);
    p = (s8 *) SBServerGetStringValue(server, key, 0);
    if (!p) return defaultVal;
    if (*p != '-') q = p; else q = p + 1;
    c = *(u8 *) q;
    if ((s32) c < 0 || (s32) c >= 128) isDigit = 0;
    else isDigit = gCharClassTable[c] & 8;
    if (!isDigit) return defaultVal;
    return ParseInt(p);
}

/* GameSpy sb_sbGetFloat: look up the server key `key`, parse its string value as a
 * floating-point number and return it, or `def` when the key is absent. */
double SBServerGetFloatValue(GpiPlayer *server, s32 key, double def) {
    double atof(s32);
    s32 text = SBServerGetStringValue(server, key, 0);
    if (text) def = atof(text);
    return def;
}

s32 SBServerGetIp(s32 *arg0) {
    return *arg0;
}

/* GameSpy SBServerGetPort: the server's query port in host byte order (the
 * GpiPlayer record keeps its ports in network order). */
u16 SBServerGetPort(GpiPlayer *server) {
    return SwapPair60E(server->port);
}

u16 SBServerGetPortNBO(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 4);
}

/* GameSpy SBServerHasPrivateAddress: true when the server record carries its own
 * (private) address and query port, from the QR2 reply's optional id field. */
s32 SBServerHasPrivateAddress(GpiPlayer *server) {
    if ((server->flags & GPI_REC_FLAG_ID) == GPI_REC_FLAG_ID) {
        return 1;
    }
    return 0;
}

s32 func_02060c90(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 8);
}

/* Return the query port of server record `server` (GpiPlayer.queryPort, kept in
 * network byte order) in host byte order. */
u16 SBServerGetQueryPort(GpiPlayer *server) {
    u16 port;

    port = server->queryPort;
    return (u16) ((u8) ((s32) port >> 8) | ((port << 8) & 0xFF00));
}

void SBServerSetNext(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
}

s32 SBServerGetNext(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x20);
}

/* True when a key from a QR2 reply is an ordinary server field: the reply's
 * meta keys ("queryid" and "final", gQr2MetaFields) are not stored in the
 * server record. */
s32 Qr2_IsServerField(M2C_UNK *key) {
    s32 StringCompare(s32, void *);
    extern char *gQr2MetaFields[2];
    char *metaKeys[2]; char **meta = metaKeys; u32 i;
    metaKeys[0] = gQr2MetaFields[0]; metaKeys[1] = gQr2MetaFields[1];
    for (i = 0; i < 2; i++) { if (!StringCompare((s32) key, meta[i])) return 0; }
    return 1;
}

/* QR2 reply field tokenizer: `input`, when nonzero, restarts the shared parse
 * cursor at that text. Scans to `delimiter`, replacing it with a NUL and moving
 * the cursor past it. Returns the field's text, NULL for an empty field and NULL
 * at the end of the text. */
M2C_UNK *Qr2_NextField(s32 input, s32 delimiter) {
    extern M2C_UNK gQr2ParseState;
    s8 *field = (s8 *)input;
    s32 c;
    s8 *p;
    if (field) M2C_FIELD(&gQr2ParseState, s8 **, SB_QR2_PARSE_CURSOR) = field;
    field = M2C_FIELD(&gQr2ParseState, s8 **, SB_QR2_PARSE_CURSOR);
    p = field;
    while ((c = *p) != 0 && c != delimiter) {
        p++;
        M2C_FIELD(&gQr2ParseState, s8 **, SB_QR2_PARSE_CURSOR) = p;
    }
    if (p == field) field = 0;
    if (c == 0) return field;
    {
        s8 *next = M2C_FIELD(&gQr2ParseState, s8 **, SB_QR2_PARSE_CURSOR);
        *p = 0;
        M2C_FIELD(&gQr2ParseState, s8 **, SB_QR2_PARSE_CURSOR) = next + 1;
    }
    return field;
}

/* Splits a QR2 reply's text into backslash-separated key/value pairs and stores
 * every ordinary server field in the server record; a key without a value gets
 * the empty string.  The 'queryid' and 'final' meta fields are skipped. */
void Qr2Query_ParseTextFields(M2C_UNK server, s32 reply) {
    s32 Qr2_IsServerField(M2C_UNK *);
    M2C_UNK *Qr2_NextField(s32, M2C_UNK);
    extern M2C_UNK sQr2EmptyString;
    M2C_UNK *key;
    M2C_UNK *value;

    key = Qr2_NextField(reply + 1, 0x5C);
    if (key == NULL) {
        return;
    }
    do {
        value = Qr2_NextField(0, 0x5C);
        if (value == NULL) {
            value = &sQr2EmptyString;
        }
        if (Qr2_IsServerField(key) != 0) {
            gpiPlayerSetString(server, key, value);
        }
        key = Qr2_NextField(0, 0x5C);
    } while (key != NULL);
}

#pragma peephole off
void func_02060e10(M2C_UNK a,s8 *p,s32 n){
s32 BoundedStringLength(s8 *,s32);
s32 StringFormat(void *,void *,...);
s32 StringLength(const char *);
extern M2C_UNK data_02100084;
volatile Packet60E packet;s8 *start; s32 pass,len,fields,row,col; s8 *key,*value;
while(*p){len=BoundedStringLength(p,n);if(len<0)return;key=p;n-=len;p+=len;
len=BoundedStringLength(p,n);if(len<0)return;value=p;p+=len;n-=len;gpiPlayerSetString(a,key,value);}
p++;n--;
for(pass=0;pass<2;pass++){
if(n<2)return;
{ volatile u8 *dst=(volatile u8 *)&packet.count;
const u8 *src=(const u8 *)p;
u8 first=src[0],second=src[1];
p+=2;dst[0]=first;dst[1]=second; }
start=p;n-=2;
packet.count=(u8)(packet.count>>8)|((packet.count<<8)&0xff00);
fields=0;while(*p){len=BoundedStringLength(p,n);if(len<0)return;if(len>100)return;p+=len;fields++;n-=len;}
p++;n--;
for(row=0;row<packet.count;row++){key=start;for(col=0;col<fields;col++){
len=BoundedStringLength(p,n);if(len<0)return;
StringFormat(packet.buf,&data_02100084,key,row);gpiPlayerSetString(a,(M2C_UNK *)packet.buf,p);
p+=len;n-=len;key+=StringLength(key)+1;
}}
}
}
#pragma peephole on
s32 func_02060fe8(s8 *arg0,s32 arg1) {
extern u8 data_020eac40[];s64 U32DivideRem(s32,s32);
s32 hash=0; s32 c=*arg0;
if(c){do{if(c>=0 && c<128){c=(u32)data_020eac40[c];}else{c=(s32)c;}hash=hash*0x9CCF9319+c;c=*++arg0;}while(c);}
return U32DivideRem(hash,arg1)>>32;
}
/* Free one key/value entry of a server record's table (the TableNew2 free
 * callback): release its interned key and value strings. */
void FreeServerKeyValue(s32 *pair) {
    M2C_UNK StringInternRelease(M2C_UNK, s32);
    StringInternRelease(0, pair[0]);
    StringInternRelease(0, pair[1]);
}

void HashServerKey(s8 **arg0, s32 arg1) {
    s32 func_02060fe8(s8 *, s32);

    func_02060fe8(*arg0, arg1);
}

/* Key/value table comparison callback: compare the key strings of two server
 * key/value entries case-insensitively. */
void CompareServerKeys(s32 *keyA, s32 *keyB) {
    M2C_UNK StringCompareNoCase(s32, s32);

    StringCompareNoCase(*keyA, *keyB);
}

s32 SBServerGetPing(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x1C);
}

/* Allocates a server record for the address the browser saw it at, with an empty
   key/value table and all its state, address, value and ping cleared. */
void *SBServerNew(s32 unused,s32 ip,s32 port){
 void *gpiMalloc(s32);M2C_UNK gpiFree(s32);
 s32 TableNew2(s32,s32,s32,void *,void *,void *);
 GpiPlayer *server=(GpiPlayer *)gpiMalloc(sizeof(GpiPlayer));
 if(!server)return 0;
 server->keyValues=TableNew2(8,8,4,HashServerKey,CompareServerKeys,FreeServerKeyValue);
 if(!server->keyValues){gpiFree((s32)server);return 0;}
 server->state=0;server->flags=0;
 server->next=0;server->ping=0;
 server->value=0;server->ip=ip;
 server->port=port;server->address=0;
 server->queryPort=0;return server;
}

void gpiPlayerSetFlags(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x15) = arg1;
}

void gpiPlayerSetAddress(void *arg0, s32 arg1, s16 arg2) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, s16 *, 0xC) = arg2;
}

void gpiPlayerSetValue(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
}

void gpiPlayerSetState(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x14) = arg1;
}

u8 gpiPlayerGetState(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x14);
}

/* Whether `server` is the server pointer the QR2 reply parser keeps at offset 4
 * of its shared state. */
s32 func_02061168(s32 server) {
    extern M2C_UNK gQr2ParseState;
    if (server == M2C_FIELD(&gQr2ParseState, s32 *, 4)) {
        return 1;
    }
    return 0;
}

/* QR2 server-list event callback: receives the Qr2 engine's per-server events
 * (0..6) and forwards the matching notification to the application's server-list
 * callback at self+0x630.  For a newly found server (event 0) it also starts the
 * detail query; once a pending server finishes it clears the pending query. */
void Qr2ServerEventCallback(void *serverList,u32 event,void *server,void *self){
void Qr2Query_StartServerQuery(void *,void *,s32,s32);
void func_0206040c(void *,s32);
s32 Vector_GetCount(s32);
M2C_UNK SBServerListDisconnect(void *);
s32 queryFlag;
switch(event){
case 0:
M2C_FIELD(self,void (**)(void *,s32,void *,s32),0x630)(self,0,server,M2C_FIELD(self,s32 *,0x634));
if((!(M2C_FIELD(server,u8 *,0x14)&3)||!(M2C_FIELD(server,u8 *,0x14)&0x40))&&!(M2C_FIELD(server,u8 *,0x14)&0x2c)&&!M2C_FIELD(self,s32 *,0x624)){
if(M2C_FIELD(server,u8 *,0x15)&1)queryFlag=!(M2C_FIELD(self,s32 *,0x4c)&&M2C_FIELD(self,s32 *,0x40));else queryFlag=2;
Qr2Query_StartServerQuery(self,server,0,queryFlag);
}break;
case 1:
if(!(M2C_FIELD(server,u8 *,0x14)&0x43))
M2C_FIELD(self,void (**)(void *,s32,void *,s32),0x630)(self,2,server,M2C_FIELD(self,s32 *,0x634));
else M2C_FIELD(self,void (**)(void *,s32,void *,s32),0x630)(self,1,server,M2C_FIELD(self,s32 *,0x634));
break;
case 2:
if(M2C_FIELD(server,u8 *,0x14)&0x2c)Qr2Query_UnlinkServer(self,server);
M2C_FIELD(self,void (**)(void *,s32,void *,s32),0x630)(self,3,server,M2C_FIELD(self,s32 *,0x634));break;
case 3:
if(M2C_FIELD(self,s32 *,0x620))SBServerListDisconnect(serverList);
if(!Vector_GetCount(M2C_FIELD(serverList,s32 *,4))||!M2C_FIELD(self,s32 *,0x10))
M2C_FIELD(self,void (**)(void *,s32,void *,s32),0x630)(self,4,0,M2C_FIELD(self,s32 *,0x634));break;
case 5:
M2C_FIELD(self,void (**)(void *,s32,void *,s32),0x630)(self,5,0,M2C_FIELD(self,s32 *,0x634));break;
case 6:func_0206040c(self,M2C_FIELD(self,s32 *,0x4ec));break;
}
if(!server)return;
if(M2C_FIELD(server,s32 *,0)!=M2C_FIELD(self,s32 *,0x628))return;
if(M2C_FIELD(server,u16 *,4)==M2C_FIELD(self,u16 *,0x62c))M2C_FIELD(self,s32 *,0x628)=0;
}

/* Callback the QR2 query engine calls for the single server a detail query is
 * outstanding for: forwards each query stage to the application's server-list
 * callback (1 = updated, 2 = update failed, 4 = query complete) and, once that
 * server reports, clears the outstanding-query address. */
void Qr2ServerQueryCallback(s32 unused,s32 stage,void *server,void *self){
 switch(stage){
 case 1:M2C_FIELD(self,M2C_UNK (**)(void *,s32,void *,s32),SB_LIST_NOTIFY)(self,2,server,M2C_FIELD(self,s32 *,SB_LIST_NOTIFY_DATA));break;
 case 0:M2C_FIELD(self,M2C_UNK (**)(void *,s32,void *,s32),SB_LIST_NOTIFY)(self,1,server,M2C_FIELD(self,s32 *,SB_LIST_NOTIFY_DATA));break;
 case 2:M2C_FIELD(self,M2C_UNK (**)(void *,s32,void *,s32),SB_LIST_NOTIFY)(self,4,server,M2C_FIELD(self,s32 *,SB_LIST_NOTIFY_DATA));break;
 }
 if(!server)return;
 if(M2C_FIELD(server,s32 *,0)!=M2C_FIELD(self,s32 *,SB_LIST_QUERY_SERVER_IP))return;
 if(M2C_FIELD(server,u16 *,4)==M2C_FIELD(self,u16 *,SB_LIST_QUERY_SERVER_PORT))M2C_FIELD(self,s32 *,SB_LIST_QUERY_SERVER_IP)=0;
}

void *func_020613dc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    void *gpiMalloc(s32);
    M2C_UNK func_02060398(void *, s32, s32, s32, M2C_UNK *, void *);
    M2C_UNK SBServerListInit(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, M2C_UNK *, void *);
    extern s32 gDnsQueryState;
    void Qr2ServerEventCallback(void *,u32,void *,void *);
    void Qr2ServerQueryCallback(s32, s32, void *, void *);
    void *obj;

    if ((arg6 == 0) && (gDnsQueryState != 1)) {
        return NULL;
    }
    obj = gpiMalloc(0x638);
    if (obj == NULL) {
        return NULL;
    }
    M2C_FIELD(obj, s32 *, 0x630) = arg7;
    M2C_FIELD(obj, s32 *, 0x634) = arg8;
    M2C_FIELD(obj, s32 *, 0x624) = 0;
    SBServerListInit(obj + 0x4C, arg0, arg1, arg2, arg3, arg6, (M2C_UNK *)&Qr2ServerEventCallback, obj);
    func_02060398(obj, arg4, arg5, arg6, (M2C_UNK *)&Qr2ServerQueryCallback, obj);
    return obj;
}

void DestroyServerBrowser(void *browser) {
    M2C_UNK Qr2Query_CloseSocket(void *);
    M2C_UNK SBServerListClear(void *);
    SBServerListClear((u8 *)browser + SB_LIST_QUERY);
    Qr2Query_CloseSocket(browser);
    gpiFree(browser);
}

/* Start a QR2 server-list query: build the filter string from the given key ids
 * (each key's name prefixed by a backslash), remember which fields were asked for,
 * then connect and send the query.  Unless `async` is set, wait out the query by
 * sleeping and stepping the list until it finishes or fails. */
s32 SBServerListQuery(s32 serverList,s32 async,s32 disconnect,s32 fieldIds,s32 fieldCount,s32 fields,s32 queryFlags,s32 maxServers){
 extern char *gQr2KeyNames[]; extern char sQr2FilterFormat[];
 s32 StringLength(const char *); s32 StringFormat(void *,void *,...);
 s32 SBServerListConnectAndQuery(s32,char *,s32,s32,s32); void gpiSleep(s32);
 char filter[256]={0}; s32 filterLen=0,keyIndex; char *keyName; s32 result;
 M2C_FIELD(serverList,s32 *,SB_LIST_DISCONNECT)=disconnect;
 M2C_FIELD(serverList,s32 *,SB_LIST_FIELD_COUNT)=0;
 for(keyIndex=0;keyIndex<fieldCount;keyIndex++){
 keyName=gQr2KeyNames[*(u8 *)(fieldIds+(u32)keyIndex)];
 if(filterLen+StringLength(keyName)+1>=256)break;
 filterLen+=StringFormat(filter+filterLen,sQr2FilterFormat,keyName);
 AddServerListField((void *)serverList,*(u8 *)(fieldIds+(u32)keyIndex));
 }
 result=SBServerListConnectAndQuery(serverList+0x4c,filter,fields,queryFlags,maxServers);
 if(result)return result;
 if(!async){
 goto check;
 loop:
 gpiSleep(10);
 result=SBServerListThink(serverList);
 check:
 if(M2C_FIELD(serverList,s32 *,SB_LIST_QUERY)==SB_LIST_STATE_QUERYING)goto loop;
 if(M2C_FIELD(serverList,s32 *,SB_LIST_PENDING)<=0)return result;
 if(result==0)goto loop;
 }
 return result;
}

/* Start a QR2 server-list query through SBServerListQuery with the max-servers
 * limit flag set, so the query packet carries `maxServers`. */
void SendToPlayerList(s32 serverList, s32 async, s32 disconnect, s32 fieldIds, s32 fieldCount, s32 fields, s32 maxServers) {
    SBServerListQuery(serverList, async, disconnect, fieldIds, fieldCount, fields, SB_QUERY_FLAG_MAX_SERVERS, maxServers);
}

/* Resolve `host` to a numeric address and send `length` bytes of `packet` to that
 * host and `port` through the server browser's transport, swapping the port to
 * network byte order first.  Returns the transport's result. */
s32 SBServerListSendToAddress(s32 browser, char *host, s32 port, void *packet, s32 length) {
    M2C_UNK func_02063aa8(s32, s32, u16, M2C_UNK, s32);
    return func_02063aa8(browser + SB_LIST_QUERY, ghiInetAddr(host), (u16) ((u8) (port >> 8) | ((port << 8) & 0xFF00)), packet, length);
}

/* Send the NAT-negotiation request carrying `cookie` to `host` and `port` through
 * the server browser's QR2 query socket, the port in network byte order. */
void SBServerListSendNATNegotiation(s32 browser, char *host, s32 port, s32 cookie) {
    s32 ghiInetAddr(char *);
    s32 func_02063bd0(s32, s32, u16, s32);
    func_02063bd0(browser + SB_LIST_QUERY, ghiInetAddr(host), (u16) ((u8) (port >> 8) | ((port << 8) & 0xFF00)), cookie);
}

/* Remove a server from a server-browser list: find it in the QR2 query's server
 * vector and drop it there, which reports the removal to the application. */
void SBServerListRemoveServer(s32 list, s32 server) {
    s32 SBServerListFindByServer(s32, s32);
    M2C_UNK SBServerListRemoveServerAt(s32, s32);
    s32 index = SBServerListFindByServer(list + SB_LIST_QUERY, server);
    if (index == -1) return;
    SBServerListRemoveServerAt(list + SB_LIST_QUERY, index);
}

/* One per-frame step of the server browser: tick the QR2 detail-query list, then
 * run the server-list state machine. */
s32 SBServerListThink(s32 browser) {
    s32 SBServerListProcessState(s32);

    Qr2Query_Update((void *) browser);
    return SBServerListProcessState(browser + SB_LIST_QUERY);
}

/* Reset a server-browser object: disconnect the QR2 session it holds at
 * SB_LIST_QUERY and drop the queries still queued in its query queues. */
M2C_UNK SBServerListReset(void *browser) {
    M2C_UNK SBServerListDisconnect(void *);
    M2C_UNK Qr2Query_ResetQueues(void *);

    SBServerListDisconnect((u8 *)browser + SB_LIST_QUERY);
    Qr2Query_ResetQueues(browser);
}

/* Reset the connection's server browser: reset the SBServerList state and drop the
 * servers the application already removed. */
void ResetServerBrowser(s32 browser) {
    M2C_UNK SBServerListReset();
    M2C_UNK SBServerListClearRemovedServers(s32);
    SBServerListReset(browser);
    SBServerListClearRemovedServers(browser + SB_LIST_QUERY);
}

/* The server browser's activity code, from its count of pending detail queries and
 * the list state machine's state at SB_LIST_QUERY. */
s32 SBServerListGetStatus(void *browser) {
    s32 state;

    if (M2C_FIELD(browser, s32 *, SB_LIST_PENDING) > 0) return SB_BROWSER_STATUS_QUERIES;
    state = M2C_FIELD(browser, s32 *, SB_LIST_QUERY);
    if (state == SB_SLIST_STATE_QUERYING || state == SB_SLIST_STATE_AD_HOC) return SB_BROWSER_STATUS_SEARCHING;
    if (state == SB_SLIST_STATE_IDLE) return SB_BROWSER_STATUS_IDLE;
    return SB_BROWSER_STATUS_CONNECTED;
}

void SBServerListGetServer(s32 arg0) {
    M2C_UNK SBServerListGetServerAt(s32);
    SBServerListGetServerAt(arg0 + 0x4C);
}

void SBServerListGetCount(s32 arg0) {
    M2C_UNK SBServerListGetServerCount(s32);
    SBServerListGetServerCount(arg0 + 0x4C);
}

void SBServerListSort(s32 arg0) {
    M2C_UNK SBServerListSortServers(s32);
    SBServerListSortServers(arg0 + 0x4C);
}

s32 func_020617b4(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x4EC);
}

