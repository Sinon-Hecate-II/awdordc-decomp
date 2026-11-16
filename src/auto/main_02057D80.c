/* 28 functions from 0x02057D80 to 0x02058CA4 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 unk_0; s32 unk_4; } Unk02050838Pair;
extern M2C_UNK data_020ff3ec, gGpiInfoState;
extern s32 gGpiInfoSocket;
extern M2C_UNK data_0213dcd0, data_020ff410, data_020ff414, data_020ff3f4;

/* Processes the pending searches queued on the connection: allocates a temporary list of matching search entries, runs each through gpiProcessSingleSearch, and removes finished ones. */
s32 gpiProcessSearches(void **connection) {
    void *gpiMalloc(s32);
    void gpiFree(void *);
    void gpiSetErrorString(s32 *, s32);
    void AssertFailed(void *, void *, void *, s32);
    s32 func_020562d0(void **, void *);
    void func_02054484(void **, void *);
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
                func_02054484(connection, list[i]);
            }
        }
        gpiFree(list);
    }
    return 0;
}

s32 func_02057ed0(s32 a,s32 b,s32 c,s32 d,void *p) {
s32 func_020556e0(s32,s32,s32,s32);s32 func_020501d8(s32,s32,void *);s32 func_0205575c(s32,s32,void *,s32);void StringFormat(void *,void *,s32,s32);
extern M2C_UNK data_020ff228,data_020ff22c;
u8 buf[32];s32 r;
if(!p)p=&data_020ff228;
r=func_020556e0(a,c,201,b);if(r)return r;
StringFormat(buf,&data_020ff22c,1,d);
r=func_020501d8(a,c,buf);if(r)return r;
r=func_0205575c(a,c,p,-1);if(!r)r=0;return r;
}

void func_02057f74(s32 a,s32 b,s32 c,s32 d) {
s32 gpiValueForKey(s32,void *,void *,s32);s32 StringScanf(void *,void *,void *,void *,void *);
extern M2C_UNK data_020ff244,data_020ff24c;
u8 buf[64];s32 z,y,x;
if(!gpiValueForKey(d,&data_020ff244,buf,64))return;
if(StringScanf(buf,&data_020ff24c,&x,&y,&z)!=3)return;
func_02057ed0(a,(s32)&x,b,2,0);
}

/* Handles a server message of type 4 (a player's "login" reply): any "rn" request
   from the server is answered by the caller of func_0205817c, anything else must
   be the player's own "\rn\" reply.  A reply naming a player queues the login
   callback (the player's id is read into the connection at 0x418), otherwise the
   request is simply finished.  Returns 0 or an error code. */
s32 gpiProcessLoginReply(void **a,void *b,s32 c) {
s32 func_0205817c(void **,s32,s32);void gpiSetError(void **,s32,s32);void gpiSetErrorString(s32 *,s32);
s32 StringCompareN(s32,void *,s32);void gpiCallErrorCallback(void *,s32,s32);void *gpiMalloc(s32);s32 gpiAddCallback(void *,Unk02050838Pair,s32 *,void *,s32);void func_02054484(void **,void *);
extern M2C_UNK gGsKeyRoomName,data_020ff260,data_020ff290;
Unk02050838Pair pair;s32 *p;s32 r;
if(func_0205817c(a,c,1))return 4;
if(StringCompareN(c,&gGsKeyRoomName,4)){gpiSetError(a,1,(s32)&data_020ff260);gpiCallErrorCallback(a,3,1);return 3;}
pair=*(Unk02050838Pair *)((u8 *)b+12);
if(pair.unk_0){p=gpiMalloc(4);if(!p){gpiSetErrorString((s32 *)a,(s32)&data_020ff290);return 1;}*p=0;r=gpiAddCallback(a,pair,p,b,0);if(r)return r;}
func_02054484(a,b);return 0;
}

M2C_UNK StringCopyN(s32 a,s32 b,s32 n) {
void AssertFailed(void *,void *,void *,s32);void StringCopyPad(s32,s32,s32);
extern M2C_UNK data_020ff2cc,sGpiUtilitySourceFile,data_020ff2a0,data_020ff2ec;
if(!a)AssertFailed(&data_020ff2cc,&sGpiUtilitySourceFile,&data_020ff2a0,47);
if(!b)AssertFailed(&data_020ff2ec,&sGpiUtilitySourceFile,&data_020ff2a0,48);
StringCopyPad(a,b,n);
M2C_FIELD(a+n,u8 *,-1)=0;
return a+n;
}

void gpiLogMessage(s32 a, ...) {}

s32 func_0205817c(void **a,s32 b,s32 c) {
s32 StringCompareN(s32,void *,s32);s32 gpiValueForKey(s32,void *,void *,s32);s32 ParseInt(void *);void *StringFind(s32,void *);void gpiCallErrorCallback(void *,s32,s32);
extern M2C_UNK data_020ff2f8,data_020ff300,data_020ff308,data_020ff314;
u8 buf[16];void *p=*a;
if(StringCompareN(b,&data_020ff2f8,7)==0){
if(gpiValueForKey(b,&data_020ff300,buf,16))M2C_FIELD(p,s32 *,0x418)=ParseInt(buf);
if(!gpiValueForKey(b,&data_020ff308,p,256))M2C_FIELD(p,u8 *,0)=0;
if(c){s32 x=StringFind(b,&data_020ff314)!=0;gpiCallErrorCallback(a,4,x!=0);}
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

s32 func_02058450(void **arg0, s32 arg1, s32 *arg2, void *arg3, void *arg4) {
    void AssertFailed(void *, void *, void *, s32);
    void gpiSetError(void **, s32, M2C_UNK);
    void gpiCallErrorCallback(void *, s32, s32);
    extern M2C_UNK data_020ff3cc, sGpiUtilitySourceFile, data_020ff2b8, sGpiAssertKeyNotNull, sGpiAssertValueNotNull, data_020ff3dc;
    s32 idx;
    s8 *p;
    s8 *dstA;
    s8 *cursor;
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
    p = (s8 *)arg1 + idx;
    if (*p != 0x5c) {
        gpiSetError(arg0, 1, (s32)&data_020ff3dc);
        gpiCallErrorCallback(arg0, 3, 1);
        return 3;
    }
    cursor = p + 2;
    cnt = 0;
    ch = p[1];
    if (ch != 0x5c) {
        if (ch == 0) {
            gpiSetError(arg0, 1, (s32)&data_020ff3dc);
            gpiCallErrorCallback(arg0, 3, 1);
            return 3;
        }
        do {
            if (cnt == 0x1ff) {
                gpiSetError(arg0, 1, (s32)&data_020ff3dc);
                gpiCallErrorCallback(arg0, 3, 1);
                return 3;
            }
            *dstA++ = ch;
            ch = *cursor++;
            cnt++;
        } while (ch != 0x5c);
    }
    *dstA = 0;
    cnt2 = 0;
    ch2 = *cursor++;
    do {
        if (cnt2 == 0x1ff) {
            gpiSetError(arg0, 1, (s32)&data_020ff3dc);
            gpiCallErrorCallback(arg0, 3, 1);
            return 3;
        }
        *dstB++ = ch2;
        cnt2++;
        ch2 = *cursor++;
    } while (ch2 != 0x5c && ch2 != 0);
    *dstB = 0;
    *arg2 = idx + (s32)(cursor - p - 1);
    return 0;
}

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

void *func_02058658(void *a,s32 b,s32 c,void *d){
void *func_02058b94(void *);void AssertFailed(void *,void *,void *,s32);s32 gpiStringDup(s32);
s32 func_02058b18(void *,void *);void func_02048eac(s32,void *);void *func_02058bb4(void *,s32);
s32 buf[5];
if(!a)a=M2C_FIELD(&data_0213dcd0,void **,4);
if(!a)AssertFailed(&data_020ff410,&data_020ff414,&data_020ff3f4,120);
buf[0]=gpiStringDup(b);buf[1]=c;buf[3]=0;buf[2]=1;
func_02058b18(buf,d);func_02048eac(M2C_FIELD(a,s32 *,0),buf);
return func_02058b94(func_02058bb4(a,b));
}

s32 func_020586f4(void *a,s32 b,void *c){
void *func_02058bb4(void *,s32);s32 func_02058b18(void *,void *);
void *p=func_02058bb4(a,b);if(!p)return 0;
M2C_FIELD(p,s32 *,8)=0;return func_02058b18(p,c);
}

s32 func_02058720(void *a,s32 b,void *c){
void *func_02058b94(void *);M2C_UNK *func_02058ab4(s32);M2C_UNK *func_02058acc(s32,s32);
void *func_02058bb4(void *,s32);s32 func_02058b18(void *,void *);s32 func_0205893c(void *,s32,void *);
s64 func_02070134(s64,s64);
void *p=func_02058bb4(a,b);void *q;s64 v;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)==0){q=func_02058b94(p);return func_02058b18(p,func_02058ab4(M2C_FIELD(c,s32 *,0)+M2C_FIELD(q,s32 *,0)));}
else if(M2C_FIELD(p,s32 *,4)==1){q=func_02058b94(p);v=func_02070134(*(s64 *)c,*(s64 *)q);return func_02058b18(p,func_02058acc((s32)v,(s32)(v>>32)));}
else return func_0205893c(a,b,c);
}

s32 func_020587b4(void *a,s32 b,void *c) {
void *func_02058bb4(void *,s32);M2C_UNK *func_02058ab4(s32);s32 func_02058b18(void *,void *);
void *func_02058b94(void *);M2C_UNK *func_02058acc(s32,s32);
s64 func_02070b70(s64,s64);
void *p=func_02058bb4(a,b);void *q;s64 v;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)==0){q=func_02058b94(p);return func_02058b18(p,func_02058ab4(M2C_FIELD(q,s32 *,0) - M2C_FIELD(c,s32 *,0)));}
if(M2C_FIELD(p,s32 *,4)==1){q=func_02058b94(p);v=func_02070b70(*(s64 *)q,*(s64 *)c);return func_02058b18(p,func_02058acc((s32)v,(s32)(v>>32)));}
return (s32)func_02058b94(p);
}

s32 func_02058838(void *a,s32 b,void *c) {
void *func_02058bb4(void *,s32);M2C_UNK *func_02058ab4(s32);s32 func_02058b18(void *,void *);
void *func_02058b94(void *);M2C_UNK *func_02058acc(s32,s32);
s64 func_02070658(s64,s64);
void *p=func_02058bb4(a,b);void *q;s64 v;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)==0){q=func_02058b94(p);return func_02058b18(p,func_02058ab4(M2C_FIELD(c,s32 *,0) * M2C_FIELD(q,s32 *,0)));}
if(M2C_FIELD(p,s32 *,4)==1){q=func_02058b94(p);v=func_02070658(*(s64 *)c,*(s64 *)q);return func_02058b18(p,func_02058acc((s32)v,(s32)(v>>32)));}
return (s32)func_02058b94(p);
}

s32 func_020588b8(void *a,s32 b,void *c) {
void *func_02058bb4(void *,s32);M2C_UNK *func_02058ab4(s32);s32 func_02058b18(void *,void *);
void *func_02058b94(void *);M2C_UNK *func_02058acc(s32,s32);
s64 func_020724f8(s64,s64);s32 func_020720f0(s32,s32);
void *p=func_02058bb4(a,b);void *q;s64 v;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)==0){q=func_02058b94(p);return func_02058b18(p,func_02058ab4(func_020720f0(M2C_FIELD(q,s32 *,0),M2C_FIELD(c,s32 *,0))));}
if(M2C_FIELD(p,s32 *,4)==1){q=func_02058b94(p);v=func_020724f8(*(s64 *)q,*(s64 *)c);return func_02058b18(p,func_02058acc((s32)v,(s32)(v>>32)));}
return (s32)func_02058b94(p);
}

s32 func_0205893c(void *a,s32 b,void *c) {
void *func_02058bb4(void *,s32);void *func_02058b94(void *);void AssertFailed(void *,void *,void *,s32);s32 StringLength(void *);void *gpiMalloc(s32);void StringCopy(void *,void *);void StringAppend(void *,void *);void gpiFree(void *);s32 func_02058b18(void *,void *);
extern M2C_UNK data_020ff420,data_020ff414,data_020ff400;
void *p=func_02058bb4(a,b);void *q;void *r;s32 n;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)!=2)AssertFailed(&data_020ff420,&data_020ff414,&data_020ff400,209);
q=func_02058b94(p);n=StringLength(q);n+=StringLength(c);
r=gpiMalloc(n+1);StringCopy(r,q);StringAppend(r,c);func_02058b18(p,r);gpiFree(r);return (s32)func_02058b94(p);
}

s32 func_020589e0(void *a,s32 b,void *c) {
s64 func_020705dc(s32);s64 func_02070658(s64,s64);s64 func_02070134(s64,s64);s64 func_020724f8(s64,s64);s32 func_020720f0(s32,s32);void *func_02058bb4(void *,s32);void *func_02058b94(void *);s32 func_02058b18(void *,void *);M2C_UNK *func_02058ab4(s32);M2C_UNK *func_02058acc(s32,s32);
void *p=func_02058bb4(a,b);void *q;s32 n;s64 v;
if(!p)return 0;
if(M2C_FIELD(p,s32 *,4)==0){q=func_02058b94(p);n=++M2C_FIELD(p,s32 *,8);return func_02058b18(p,func_02058ab4(func_020720f0(n*M2C_FIELD(q,s32 *,0)+M2C_FIELD(c,s32 *,0),n)));}
if(M2C_FIELD(p,s32 *,4)==1){q=func_02058b94(p);n=++M2C_FIELD(p,s32 *,8);v=func_02070134(*(s64 *)c,func_02070658(func_020705dc(n),*(s64 *)q));v=func_020724f8(v,func_020705dc(n));return func_02058b18(p,func_02058acc((s32)v,(s32)(v>>32)));}
return (s32)func_02058b94(p);
}

M2C_UNK *func_02058ab4(s32 a) {
    *(s32 *)&data_0213dcd0 = a;
    return (M2C_UNK *)&data_0213dcd0;
}

M2C_UNK *func_02058acc(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0213dcd0;
    extern M2C_UNK data_0213dcd8;
    M2C_FIELD(&data_0213dcd0, s32 *, 8) = arg0;
    M2C_FIELD(&data_0213dcd0, s32 *, 0xC) = arg1;
    return &data_0213dcd8;
}

s8 *func_02058ae8(s8 *p) {
s8 *q=p;s32 c=*p;
if(c){do{if(c==92)*p=47;c=*++p;}while(c);}
return q;
}

s32 func_02058b18(void *p,void *q) {
void gpiFree(void *);s32 gpiStringDup(s32);s8 *func_02058ae8(s8 *);void *func_02058b94(void *);
s32 t=M2C_FIELD(p,s32 *,4);void *r;
if(t==0)M2C_FIELD(p,s32 *,12)=M2C_FIELD(q,s32 *,0);
else if(t==1){M2C_FIELD(p,double *,12)=M2C_FIELD(q,double *,0);}
else if(t==2){
r=M2C_FIELD(p,void **,12);if(r)gpiFree(r);
if(!q)r=0;else r=func_02058ae8((s8 *)gpiStringDup((s32)q));
M2C_FIELD(p,void **,12)=r;
}
return (s32)func_02058b94(p);
}

void *func_02058b94(void *arg0) {
    if (arg0 == NULL) {
        return NULL;
    }
    if (M2C_FIELD(arg0, s32 *, 4) == 2) {
        return M2C_FIELD(arg0, void **, 0xC);
    }
    return arg0 + 0xC;
}

void *func_02058bb4(void *a,s32 b){
void AssertFailed(void *,void *,void *,s32);void *func_02048ff8(s32,void *);
s32 buf[5];
if(!a)a=M2C_FIELD(&data_0213dcd0,void **,4);
if(!a)AssertFailed(&data_020ff410,&data_020ff414,&data_020ff3ec,0x153);
buf[0]=b;return func_02048ff8(M2C_FIELD(a,s32 *,0),buf);
}

void gpiInfoCloseSocket(void){
void func_020496cc(s32,s32);void func_020496b8(s32);void func_0205954c(void);void gpiFree(void *);
if(gGpiInfoSocket!=-1){func_020496cc(gGpiInfoSocket,2);func_020496b8(gGpiInfoSocket);}
gGpiInfoSocket=-1;
func_0205954c();
if(M2C_FIELD(&gGpiInfoState,void **,12)){gpiFree(M2C_FIELD(&gGpiInfoState,void **,12));M2C_FIELD(&gGpiInfoState,s32 *,12)=0;M2C_FIELD(&gGpiInfoState,s32 *,44)=0;M2C_FIELD(&gGpiInfoState,s32 *,0)=0;}
}

s32 func_02058c84(void) {
    extern s32 gGpiInfoSocket;
    if (gGpiInfoSocket != -1) {
        return 1;
    }
    return 0;
}

