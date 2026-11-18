#include "common.h"
typedef struct {s32 function,argument;} Callback518;
typedef struct {char token[21], hash[33], name[82], buf[512];} Response518;
extern M2C_UNK data_020fe564,data_020fe56c,data_020fe574,data_020fe57c,data_020fe488,data_020fe5ac,data_020fe4bc,data_020fe5b4,data_020fe4c8,data_020fe5e4,data_020fe5ec,gGsKeyUniqueNick,data_020fe5f8,data_020fe434,data_020fe43c,data_020fe44c,data_020fe600,data_020fe608,data_020fe424;


#pragma opt_strength_reduction off
s32 gpiProcessConnect(void **a, void *b, char *text) {
s32 gpiProcessErrorReply(void **,char *,s32);
s32 gpiValueForKey(char *,M2C_UNK *,void *,s32);
s32 ParseInt(char *);
M2C_UNK func_02055bc0(void **,s32);
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
M2C_UNK func_02054484();
Response518 work;
void *q;
void *p=*a;
char *chosen;
s32 *record;
s32 result;
Callback518 callback;
if(gpiProcessErrorReply(a,text,0)){
if(M2C_FIELD(p,s32 *,0x418)==0x106 && M2C_FIELD(p,s32 *,0x1a0)){
func_02055bc0(a,M2C_FIELD(p,s32 *,0x1a0));
M2C_FIELD(p,s32 *,0x19c)=0;M2C_FIELD(p,s32 *,0x1a0)=0;
}else if(M2C_FIELD(p,s32 *,0x418)==0x201){
if(gpiValueForKey(text,&data_020fe564,work.buf,512))M2C_FIELD(p,s32 *,0x1a0)=ParseInt(work.buf);
}
if(StringFind(text,&data_020fe56c)){gpiSetError(a,M2C_FIELD(p,s32 *,0x418),p);gpiCallErrorCallback(a,4,1);return 4;}
else {gpiSetError(a,M2C_FIELD(p,s32 *,0x418),p);gpiCallErrorCallback(a,4,0);return 4;}
}
q=M2C_FIELD(b,void **,4);
switch(M2C_FIELD(b,s32 *,20)){
case 1:
if(StringCompareN(text,&data_020fe574,5)){gpiSetError(a,1,&data_020fe57c);gpiCallErrorCallback(a,3,1);return 3;}
if(!gpiValueForKey(text,&data_020fe488,q,128)){gpiSetError(a,1,&data_020fe57c);gpiCallErrorCallback(a,3,1);return 3;}
if(M2C_FIELD(q,s32 *,0x304)){
result=SendNewUserProfile(a,q);if(result)return result;
M2C_FIELD(b,s32 *,20)=3;
}else{
result=func_020511dc(a,q);if(result)return result;
M2C_FIELD(b,s32 *,20)=2;
}
break;
case 3:
if(StringCompareN(text,&data_020fe5ac,5)){gpiSetError(a,1,&data_020fe57c);gpiCallErrorCallback(a,3,1);return 3;}
if(!gpiValueForKey(text,&data_020fe4bc,work.buf,512)){gpiSetError(a,1,&data_020fe5b4);gpiCallErrorCallback(a,3,1);return 3;}
M2C_FIELD(p,s32 *,0x19c)=ParseInt(work.buf);
if(!gpiValueForKey(text,&data_020fe4c8,work.buf,512)){gpiSetError(a,1,&data_020fe5b4);gpiCallErrorCallback(a,3,1);return 3;}
M2C_FIELD(p,s32 *,0x1a0)=ParseInt(work.buf);
result=func_020511dc(a,q);if(result)return result;
M2C_FIELD(b,s32 *,20)=2;break;
case 2:
if(StringCompareN(text,&data_020fe5e4,5)){gpiSetError(a,1,&data_020fe57c);gpiCallErrorCallback(a,3,1);return 3;}
if(!gpiValueForKey(text,&data_020fe5ec,work.buf,512)){gpiSetError(a,1,&data_020fe5b4);gpiCallErrorCallback(a,3,1);return 3;}
M2C_FIELD(p,s32 *,0x198)=ParseInt(work.buf);
if(!gpiValueForKey(text,&data_020fe4bc,work.buf,512)){gpiSetError(a,1,&data_020fe5b4);gpiCallErrorCallback(a,3,1);return 3;}
M2C_FIELD(p,s32 *,0x19c)=ParseInt(work.buf);
if(!gpiValueForKey(text,&data_020fe4c8,work.buf,512)){gpiSetError(a,1,&data_020fe5b4);gpiCallErrorCallback(a,3,1);return 3;}
M2C_FIELD(p,s32 *,0x1a0)=ParseInt(work.buf);
if(!gpiValueForKey(text,&gGsKeyUniqueNick,work.token,21))work.token[0]=0;
if(!gpiValueForKey(text,&data_020fe5f8,(char *)p+0x474,25))M2C_FIELD(p,s8 *,0x474)=0;
if(M2C_FIELD(q,s8 *,0xc2))chosen=(char *)q+0xc2;
else if(M2C_FIELD(p,s8 *,0x12f))chosen=(char *)p+0x12f;
else {StringFormat(work.name,&data_020fe434,(char *)p+0x110,(char *)p+0x144);chosen=work.name;}
StringFormat(work.buf,&data_020fe43c,(char *)q+161,&data_020fe44c,chosen,q,(char *)q+128,(char *)q+161);
Md5Hex(work.buf,StringLength(work.buf),work.hash);
if(!gpiValueForKey(text,&data_020fe600,work.buf,512)){gpiSetError(a,1,&data_020fe5b4);gpiCallErrorCallback(a,3,1);return 3;}
if(ByteCompareN(work.hash,work.buf,32)){gpiSetError(a,0x108,&data_020fe608);gpiCallErrorCallback(a,3,1);return 3;}
if(M2C_FIELD(p,s32 *,0x100)){record=func_02055aa0(a,M2C_FIELD(p,s32 *,0x1a0));record[0]=M2C_FIELD(p,s32 *,0x1a0);record[1]=M2C_FIELD(p,s32 *,0x19c);}
M2C_FIELD(p,s32 *,0x1d8)=3;
callback=*(Callback518 *)((char *)b+12);
if(callback.function){
q=gpiMalloc(32);
if(!q){gpiSetErrorString((M2C_UNK)a,&data_020fe424);return 1;}
MemSet(q,0,32);
M2C_FIELD(q,s32 *,4)=M2C_FIELD(p,s32 *,0x1a0);M2C_FIELD(q,s32 *,0)=0;
StringCopyN((char *)q+8,work.token,21);
result=gpiAddCallback(a,callback,q,b,0);
if(result)return result;
}
func_02054484(a,b);
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
void gpiDisconnect(void **arg0, s32 arg1) {
    s32 v;
    void *temp_r4;
    s32 temp_r2;
    s32 temp_r0;
    s32 temp_r0_2;
    void *var_r6;
    u32 sp8;

    temp_r4 = *arg0;
    temp_r2 = *(s32 *)((char *)temp_r4 + 0x1D8);
    if (temp_r2 == 4) {
        return;
    }
    if (temp_r2 != 0) {
        if ((arg1 != 0) && (temp_r2 == 3)) {
            gpiAppendStringField(arg0, (char *)temp_r4 + 0x1F4, &data_020fe668);
            gpiAppendIntField(arg0, (char *)temp_r4 + 0x1F4, *(s32 *)((char *)temp_r4 + 0x198));
            gpiAppendStringField(arg0, (char *)temp_r4 + 0x1F4, &gGsKeyFinal);
        }
        gpiSendFromBuffer(arg0, *(s32 *)((char *)temp_r4 + 0x1D4), (char *)temp_r4 + 0x1F4, &sp8, 1, &data_020fe67c);
        temp_r0 = *(s32 *)((char *)temp_r4 + 0x1D4);
        if (temp_r0 != -1) {
            func_020496cc(temp_r0, 2);
            func_020496b8(*(s32 *)((char *)temp_r4 + 0x1D4));
            *(s32 *)((char *)temp_r4 + 0x1D4) = -1;
        }
        temp_r0_2 = *(s32 *)((char *)temp_r4 + 0x204);
        if (temp_r0_2 != -1) {
            func_020496cc(temp_r0_2, 2);
            func_020496b8(*(s32 *)((char *)temp_r4 + 0x204));
            *(s32 *)((char *)temp_r4 + 0x204) = -1;
        }
        *(s32 *)((char *)temp_r4 + 0x1D8) = 4;
        *(s32 *)((char *)temp_r4 + 0x19C) = 0;
        *(s32 *)((char *)temp_r4 + 0x1A0) = 0;
    }
    gpiFree(*(s32 *)((char *)temp_r4 + 0x1DC));
    *(s32 *)((char *)temp_r4 + 0x1DC) = 0;
    gpiFree(*(s32 *)((char *)temp_r4 + 0x1EC));
    *(s32 *)((char *)temp_r4 + 0x1EC) = 0;
    gpiFree(*(s32 *)((char *)temp_r4 + 0x1F4));
    *(s32 *)((char *)temp_r4 + 0x1F4) = 0;
    gpiFree(*(s32 *)((char *)temp_r4 + 0x440));
    *(s32 *)((char *)temp_r4 + 0x440) = 0;
    gpiFree(*(s32 *)((char *)temp_r4 + 0x450));
    *(s32 *)((char *)temp_r4 + 0x450) = 0;
    v = *(s32 *)((char *)temp_r4 + 0x424);
    while (v != 0) {
        func_02054484(arg0);
        v = *(s32 *)((char *)temp_r4 + 0x424);
    }
    *(s32 *)((char *)temp_r4 + 0x424) = 0;
    var_r6 = *(void **)((char *)temp_r4 + 0x434);
    if (var_r6 != NULL) {
        do {
            void *t = var_r6;
            var_r6 = *(void **)((char *)var_r6 + 0x3C);
            func_02054fa8(arg0, t);
        } while (var_r6 != NULL);
    }
    *(s32 *)((char *)temp_r4 + 0x434) = 0;
    while (func_02055cd0(arg0, gpiReleaseBuddyStatusRecord, 0) == 0) {
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

