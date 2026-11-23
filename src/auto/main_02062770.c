/* 13 functions from 0x02062770 to 0x02063704 (main), found by ds-decomp. */
#include "common.h"
#include "sb_serverlist.h"
extern s32 data_0210019c, sSbFileName;
extern u8 data_021000b4[16];
typedef struct { u8 lo, hi; } PairBytes;
static inline void copy633(void *dst, void *src) { *(PairBytes *)dst=*(PairBytes *)src; *((PairBytes *)dst+1)=*((PairBytes *)src+1); }
static inline void copy633h(void *dst, void *src) { *(PairBytes *)dst=*(PairBytes *)src; }

/* Set up the server list's GameSpy stream cipher for a session: mix the
 * challenge bytes with the list's key string into the 8-byte key at
 * SB_SLIST_CRYPT_KEY, then build the cipher state at SB_SLIST_CRYPT from it. */
void GsCryptSetKey(void *list,s8 *challenge,s32 length) {
s32 StringLength(void *);
void GsCryptInit(void *,void *,s32);
s32 i;
s32 keyLen;
s8 *key;
keyLen=StringLength((u8 *)list+SB_SLIST_GAMEVERSION);
key=(s8 *)list+SB_SLIST_GAMEVERSION;
for(i=0;i<length;i++){
s32 x=key[i%keyLen];
s32 j=(i*x)%8;
s8 value=M2C_FIELD((s8 *)list+i%8,s8 *,SB_SLIST_CRYPT_KEY)^challenge[i];
M2C_FIELD((s8 *)list+j,s8 *,SB_SLIST_CRYPT_KEY)^=value;
}
GsCryptInit((u8 *)list+SB_SLIST_CRYPT,(u8 *)list+SB_SLIST_CRYPT_KEY,8);
}

s32 func_02062810(u8 a) {
s32 n=5;
if(a&2)n+=4;
if(a&8)n+=4;
if(a&16)n+=2;
if(a&32)n+=2;
return n;
}

/* Check that the player record's key/value pairs fit and end with an empty key. */
s32 gpiCheckPlayerKeyValueList(void *data, s32 remaining) {
    s8 *field = data;
    s32 BoundedStringLength(s8 *, s32);

    while (remaining > 0 && *field) {
        s32 fieldBytes = BoundedStringLength(field, remaining);
        if (fieldBytes < 0) {
            return 0;
        }
        remaining -= fieldBytes;
        field += fieldBytes;
        fieldBytes = BoundedStringLength(field, remaining);
        if (fieldBytes < 0) {
            return 0;
        }
        field += fieldBytes;
        remaining -= fieldBytes;
    }
    if (remaining == 0) {
        return 0;
    }
    return *field == 0;
}

/* Walks a list of opcodes, advancing data/n as commands require; returns 1 on success. */
s32 func_020628c0(M2C_UNK context, void *data, s32 n) {
 s32 Vector_GetCount(s32); void *Vector_GetItem(s32,s32); s32 BoundedStringLength(s8*,s32); void AssertFailed(void*,void*,void*,s32);
 s32 count, i, k; u8 *p = data;
 count = Vector_GetCount(M2C_FIELD(context, s32 *, 8));
 for (i = 0; i < count; i++) {
 switch (M2C_FIELD(Vector_GetItem(M2C_FIELD(context, s32 *, 8), i), s32 *, 4)) {
 case 1: p++; n--; break;
 case 2: p += 2; n -= 2; break;
 case 0:
 if (n < 1) return 0;
 k = *p++; n--;
 if (k == 255) {
 k = BoundedStringLength((s8 *) p, n);
 if (k == -1) return 0;
 p += k; n -= k;
 }
 break;
 default: AssertFailed(&data_0210019c, &sSbFileName, data_021000b4, 0x317); return 0;
 }
 if (n < 0) return 0;
 }
 return 1;
}

/* Read the address and port of the server a browser record describes: the 4-byte
 * big-endian address at +1 and, when the record carries its own port (bit 4), the
 * 2-byte port at +5, otherwise the list's default port. */
void gpiReadServerAddress(M2C_UNK list,u8 *record,s32 length,s32 *address,u16 *port) {
u8 flags;
if(length<5)return;
flags=record[0];
*(PairBytes *)address=*(PairBytes *)(record+1);
*((PairBytes *)address+1)=*(PairBytes *)(record+3);
if(flags&GPI_REC_FLAG_SKIP){
if(length-5<2)return;
*(PairBytes *)port=*(PairBytes *)(record+5);
}else *port=M2C_FIELD(list,u16 *,SB_SLIST_DEFAULT_PORT);
}

/* Decodes one gpi player record: stores the flags, the optional id/port/value fields
 * and then the typed field list and raw key/value list into the player. Returns the
 * number of bytes consumed. */
s32 gpiProcessPlayerRecord(M2C_UNK ctx,s32 player,u8 *data,s32 size,s32 readLength) {
void gpiPlayerSetFlags(s32,s32);void gpiPlayerSetAddress(s32,s32,u16);void gpiPlayerSetValue(s32,s32);s32 Vector_GetCount(s32);void *Vector_GetItem(s32,s32);void gpiPlayerSetInt(s32,s32,s32);void gpiPlayerSetString(s32,s32,void *);s32 StringLength(void *);u8 gpiPlayerGetState(s32);void gpiPlayerSetState(s32,u8);
s32 id;u16 rawPort,port; s32 totalSize=size; s32 flags=*data;s32 count,index,length; s32 *field;u8 *key;
data+=5;gpiPlayerSetFlags(player,flags);size-=5;
if(flags&GPI_REC_FLAG_SKIP){data+=2;size-=2;}
if(flags&GPI_REC_FLAG_ID){{PairBytes *dst=(PairBytes *)&id; *dst=*(PairBytes *)data;dst[1]=((PairBytes *)data)[1];}data+=4;size-=4;}else id=0;
if(flags&GPI_REC_FLAG_PORT){{u8 *dst=(u8 *)&port;u8 x=((volatile u8 *)data)[0],y=((volatile u8 *)data)[1];*dst++=x;*dst=y;}data+=2;size-=2;}else port=M2C_FIELD(ctx,u16 *,0x4a8);
gpiPlayerSetAddress(player,id,port);
if(flags&GPI_REC_FLAG_VALUE){{PairBytes *dst=(PairBytes *)&id; *dst=*(PairBytes *)data;dst[1]=((PairBytes *)data)[1];}data+=4;size-=4;gpiPlayerSetValue(player,id);}
if(flags&GPI_REC_FLAG_FIELDS){
count=Vector_GetCount(M2C_FIELD(ctx,s32 *,8));
for(index=0;index<count;index++){
field=Vector_GetItem(M2C_FIELD(ctx,s32 *,8),index);
switch(field[1]){
case GPI_FIELD_BYTE:gpiPlayerSetInt(player,field[0],*data++);size--;break;
case GPI_FIELD_PORT:{u8 *dst=(u8 *)&rawPort;u8 x=((volatile u8 *)data)[0],y=((volatile u8 *)data)[1];*dst++=x;*dst=y;}gpiPlayerSetInt(player,field[0],(u16)(((rawPort>>8)&255)|((rawPort<<8)&0xff00)));data+=2;size-=2;break;
case GPI_FIELD_STRING:
if(readLength){length=*data++;size--;}else length=255;
if(length==255){gpiPlayerSetString(player,field[0],data);length=StringLength(data)+1;data+=length;size-=length;}else gpiPlayerSetString(player,field[0],M2C_FIELD((u8 *)ctx+length*4,void **,0x84));
break;
}
}
gpiPlayerSetState(player,gpiPlayerGetState(player)|GPI_PLAYER_STATE_FIELDS);
}
if(flags&GPI_REC_FLAG_KEYS){
while(*(s8 *)data && size>0){key=data;length=StringLength(data)+1;data+=length;size-=length;gpiPlayerSetString(player,(s32)key,data);length=StringLength(data)+1;data+=length;size-=length;}
size--;gpiPlayerSetState(player,gpiPlayerGetState(player)|GPI_PLAYER_STATE_KEYS);
}
return totalSize-size;
}

/* Validates an encoded data block and, if valid, decodes it. */
s32 func_02062cf8(M2C_UNK context, u8 *data, s32 size) {
    s32 SBServerNew(M2C_UNK, s32, u16);
    s32 func_02061168();
    M2C_UNK SBServerListAddServer(M2C_UNK, s32);
    s32 func_02062810(u8);
    s32 gpiCheckPlayerKeyValueList(void *, s32);
    s32 func_020628c0(M2C_UNK, void *, s32);

    s32 gpiProcessPlayerRecord(M2C_UNK, s32, u8 *, s32, s32);
    s32 ByteCompareN(void *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021001a0;
    s32 sp8;
    u16 sp4;
    s32 headerLen;
    s32 result;
    s32 handle;
    u8 flags;

    if (size < 1) {
        return 0;
    }
    flags = *data;
    headerLen = func_02062810(flags);
    if (size < headerLen) {
        return 0;
    }
    if ((flags & 0x40) && (func_020628c0(context, data + headerLen, size - headerLen) == 0)) {
        return 0;
    }
    if ((flags & 0x80) && (gpiCheckPlayerKeyValueList(data + headerLen, size - headerLen) == 0)) {
        return 0;
    }
    if (ByteCompareN(data + 1, &data_021001a0, 4) == 0) {
        return -1;
    }
    gpiReadServerAddress(context, data, size, &sp8, &sp4);
    handle = SBServerNew(context, sp8, sp4);
    if (func_02061168() != 0) {
        return -2;
    }
    result = gpiProcessPlayerRecord(context, handle, data, size, 1);
    SBServerListAddServer(context, handle);
    return result;
}

void SBServerListSetError(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x4AC) = arg1;
}

s32 SBServerListProcessConnectReply(void *a){
s32 Vector_New(s32,s32,s32);s32 Vector_GetCount(s32);void Vector_Append(s32,s32 *);void GsCryptData(void *,u8 *,s32);s32 BoundedStringLength(s8 *,s32);s32 StringIntern(void *,void *);void AssertFailed(void *,void *,void *,s32);void MemMove(void *,void *,s32);
extern s32 sSbNoServer;extern s32 data_021001a8,data_021000ec;
s32 n;u8 *p;s32 len,off,r,i;u8 *buffer; s32 pair[2];n=M2C_FIELD(a,s32 *,0x80);p=M2C_FIELD(a,u8 **,0x7c);
switch(M2C_FIELD(a,u32 *,0x5c8)){
case 0:
if(n<1)break;off=(p[0]^0xec)+2;if(n<off)break;len=p[off-1]^0xea;r=off+len;if(n<r)break;GsCryptSetKey(a,(s8 *)p+off,len);p+=r;n-=r;M2C_FIELD(a,s32 *,0x5c8)=1;GsCryptData((u8 *)a+0x4bc,p,n);
case 1:
if(n<6)break;
copy633((u8 *)a+0x4a0,p);
M2C_FIELD(a,void (**)(void *,s32,s32,s32),0x488)(a,6,sSbNoServer,M2C_FIELD(a,s32 *,0x494));
copy633h((u8 *)a+0x4a8,p+4);
if(M2C_FIELD(a,u16 *,0x4a8)==0xffff){
if(BoundedStringLength(p+6,n-6)==-1)break;
SBServerListSetError(a,p+6);
M2C_FIELD(a,void (**)(void *,s32,s32,s32),0x488)(a,5,sSbNoServer,M2C_FIELD(a,s32 *,0x494));
if(!M2C_FIELD(a,void **,0x7c))break;
}
p+=6;n-=6;
if((M2C_FIELD(a,s32 *,0x5c4)&2)||M2C_FIELD(a,u16 *,0x4a8)==0xffff){M2C_FIELD(a,s32 *,0x5c8)=5;M2C_FIELD(a,s32 *,0)=2;break;}
M2C_FIELD(a,s32 *,0x5c8)=2;M2C_FIELD(a,s32 *,0x484)=-1;
case 2:
if(M2C_FIELD(a,s32 *,0x484)==-1){if(n<1)break;i=p[0];M2C_FIELD(a,s32 *,0x484)=i;r=Vector_New(8,i,0);M2C_FIELD(a,s32 *,8)=r;if(!r)return 5;p++;n--;}
while(M2C_FIELD(a,s32 *,0x484)>Vector_GetCount(M2C_FIELD(a,s32 *,8))){
if(n<2)break;len=BoundedStringLength(p+1,n-1);if(len==-1)break;pair[1]=p[0];pair[0]=StringIntern(a,p+1);Vector_Append(M2C_FIELD(a,s32 *,8),pair);p+=len+1;n-=len+1;
}
if(M2C_FIELD(a,s32 *,0x484)>Vector_GetCount(M2C_FIELD(a,s32 *,8)))break;
M2C_FIELD(a,s32 *,0x5c8)=3;M2C_FIELD(a,s32 *,0x484)=-1;
case 3:
if(M2C_FIELD(a,s32 *,0x484)==-1){if(n<1)break;M2C_FIELD(a,s32 *,0x484)=*p++;n--;M2C_FIELD(a,s32 *,0x480)=0;}
while(M2C_FIELD(a,s32 *,0x484)>M2C_FIELD(a,s32 *,0x480)){
len=BoundedStringLength(p,n);if(len==-1)break;r=StringIntern(a,p);i=M2C_FIELD(a,s32 *,0x480);p+=len;M2C_FIELD(a,s32 *,0x480)++;M2C_FIELD((u8 *)a+i*4,s32 *,0x84)=r;n-=len;
}
if(M2C_FIELD(a,s32 *,0x484)>M2C_FIELD(a,s32 *,0x480))break;
M2C_FIELD(a,s32 *,0x5c8)=4;
case 4:
if(n<5)break;
do{r=func_02062cf8(a,p,n);if(r==-2)return 5;if(r==-1){M2C_FIELD(a,s32 *,0x5c8)=5;M2C_FIELD(a,s32 *,0)=2;n-=5;p+=5;M2C_FIELD(a,void (**)(void *,s32,s32,s32),0x488)(a,3,sSbNoServer,M2C_FIELD(a,s32 *,0x494));break;}
p+=r;n-=r;if(!M2C_FIELD(a,void **,0x7c))r=0;
}while(r);break;
}
if(n<0)AssertFailed(&data_021001a8,&sSbFileName,&data_021000ec,0x4af);
buffer=M2C_FIELD(a,u8 **,0x7c);if(!buffer)return 0;
if(n)MemMove(buffer,p,n);
M2C_FIELD(a,s32 *,0x80)=n;return 0;
}

/* Decode the key-list message of a server-browser reply: a count byte, then one
 * type byte and a NUL-terminated key name per key.  The names are interned and
 * stored as the list's key schema (SB_SLIST_KEY_LIST), which the records that
 * follow are decoded with.  Returns 0, or 4 on a short reply and 5 when the
 * schema cannot be allocated. */
s32 SBServerListParseKeyList(void *list, u8 *data, s32 size) {
    s32 Vector_New(s32, s32, s32);
    void Vector_Append(s32, s32 *);
    s32 StringIntern(void *, void *);
    s32 BoundedStringLength(s8 *, s32);
    void SBServerListFreeKeyList(void *);
    SBServerListKey entry;
    s32 i, count, len;

    size--;
    count = *data++;
    if (M2C_FIELD(list, s32 *, SB_SLIST_KEY_LIST)) {
        SBServerListFreeKeyList(list);
    }
    M2C_FIELD(list, s32 *, SB_SLIST_KEY_LIST) = Vector_New(8, count, 0);
    if (!M2C_FIELD(list, s32 *, SB_SLIST_KEY_LIST)) {
        return 5;
    }
    for (i = 0; i < count; i++) {
        if (size < 2) {
            return 4;
        }
        len = BoundedStringLength((s8 *)data + 1, size - 1);
        if (len == -1) {
            return 4;
        }
        entry.type = *data;
        entry.name = (char *)StringIntern(list, data + 1);
        Vector_Append(M2C_FIELD(list, s32 *, SB_SLIST_KEY_LIST), (s32 *)&entry);
        data += len + 1;
        size -= len + 1;
    }
    return 0;
}

/* Handle an incoming GameSpy GPI record-list message (response type 6): reads a
 * count and a flag, then for each record reads a key string, its fixed
 * id/port/value field block and a trailing string, and dispatches it through the
 * connection's record callback (at +0x490).  When the flag is set one final empty
 * record is delivered. */
s32 GpiHandleRecordList(void *gpi, u8 *data, s32 size) {
    s32 BoundedStringLength(s8 *, s32);
    s32 flag;
    void *keyStart;
    s32 count;
    u16 port;
    u32 id;
    u32 value;
    u8 *hx; u8 *h0; u8 *h1;
    u8 *p;
    u8 *key;
    s32 i;
    s32 remaining;
    s32 len;
    void (*callback)(void *, void *, u32, u16, u32, void *, s32);

    remaining=size;
    if (remaining < 2) {
        return 4;
    }
    p = data;
    count = p[1];
    flag = p[0];
    p += 2;
    remaining -= 2;
    i = 0;
    while (i < count) {
        h0=(u8 *)&id; hx=(u8 *)&value; h1=(u8 *)&port;
        keyStart = p;
        len = BoundedStringLength((s8 *)p, remaining);
        if (len == -1) {
            return 4;
        }
        remaining -= len;
        key = p + len;
        if (remaining < 0xb) {
            return 4;
        }
        p = key + 0xa;
        remaining -= 0xa;
        *(volatile PairBytes *)h0=*(PairBytes *)key;
        { u8 lo=key[2]; u8 hi=key[3]; h0[3]=hi; h0[2]=lo; }
        *(volatile PairBytes *)h1=*(PairBytes *)(key+4);
        *(volatile PairBytes *)hx=*(PairBytes *)(key+6);
        *((volatile PairBytes *)hx+1)=*(PairBytes *)(key+8);
        { u32 a=(value<<24)&0xff000000u; u32 b=(value<<8)&0xff0000u; u32 c=(value>>24)&255; u32 d=(value>>8)&0xff00u; value=a|(b|(c|d)); }
        len = BoundedStringLength((s8 *)p, remaining);
        if (len == -1) {
            return 4;
        }
        callback = *(void (**)(void *, void *, u32, u16, u32, void *, s32))((u8 *)gpi + 0x490);
        callback(gpi, keyStart, id, port, value, p, *(s32 *)((u8 *)gpi + 0x494));
        i++;
        p += len;
        remaining -= len;
    }
    if (flag != 0) {
        callback = *(void (**)(void *, void *, u32, u16, u32, void *, s32))((u8 *)gpi + 0x490);
        callback(gpi, 0, 0, 0, 0, 0, *(s32 *)((u8 *)gpi + 0x494));
    }
    return 0;
}

/* Handle an incoming GPI server-info reply (message type 5): find the server it
   refers to by address and port, read the 32-bit value and the list of
   NUL-terminated strings that follow, then hand them to the server-info callback
   (at +0x48c).  Returns 4 on a malformed message, 0 otherwise. */
s32 GpiHandleServerInfoResponse(void *gpi, u8 *data, s32 size) {
    s32 SBServerListFindByAddress(M2C_UNK, s32, u16);
    s32 SBServerListGetServerAt(void *,s32);
    s32 BoundedStringLength(s8 *, s32);

    u8 *ipBytes,*valueBytes; register u8 *portBytes;
    u32 value;
    u16 port;
    s32 ip;
    void *strings[16];
    s32 index;
    s32 server;

    s32 declaredCount;
    s32 actualCount;

    s32 userdata;
    void (*callback)(void *, s32, u32, s32, void *, s32);

    if (size < 0xb) {
        return 4;
    }

    ipBytes=(u8 *)&ip; portBytes=(u8 *)&port;
    *(volatile PairBytes *)ipBytes=*(PairBytes *)data;
    { u8 lo=data[2],hi=data[3]; ipBytes[3]=hi; ipBytes[2]=lo; }
    { u8 hi=data[5],lo=data[4]; portBytes[1]=hi; portBytes[0]=lo; }

    index = SBServerListFindByAddress(gpi, (s32)ip, (s32)port);
    if (index == -1) {
        return 0;
    }

    server = SBServerListGetServerAt(gpi,index);

    valueBytes=(u8 *)&value;
    *(volatile PairBytes *)valueBytes=*(PairBytes *)(data+6);
    *((volatile PairBytes *)valueBytes+1)=*(PairBytes *)(data+8);
    { u32 a=(value<<24)&0xff000000u; u32 b=(value<<8)&0xff0000u; u32 c=(value>>24)&255; u32 d=(value>>8)&0xff00u; value=a|(b|(c|d)); }

    declaredCount = data[10];
    data += 0xb;
    size -= 0xb;
    actualCount = 0;

    while(actualCount < declaredCount && actualCount < 16) {
        s32 k;
        if(size < 1) break;
        k=BoundedStringLength((s8 *)data,size);
        if(k == -1)return 4;
        strings[actualCount]=data;
        data+=k; size-=k; actualCount++;
    }

    callback = *(void (**)(void *, s32, u32, s32, void *, s32))((u8 *)gpi + 0x48c);
    if (callback == 0) {
        return 0;
    }
    userdata = *(s32 *)((u8 *)gpi + 0x494);
    callback(gpi, server, value, actualCount, strings, userdata);
    return 0;
}

#pragma scheduling off
s32 func_02063678(M2C_UNK arg0, u8 *arg1, s32 arg2) {
    s32 SBServerListFindByAddress(M2C_UNK, s32, u16);
    M2C_UNK SBServerListRemoveServerAt(M2C_UNK);
    s32 sp4;
    u16 sp0;

    if (arg2 < 6) {
        return 4;
    }
    {
        u8 a0 = ((volatile u8 *)arg1)[0];
        u8 a1 = ((volatile u8 *)arg1)[1];
        u8 *lr = (u8 *)&sp4;
        u8 *rc = (u8 *)&sp0;
        lr[0] = a0;
        lr[1] = a1;
        {
            u8 a2 = ((volatile u8 *)arg1)[2];
            u8 a3 = ((volatile u8 *)arg1)[3];
            lr[2] = a2;
            lr[3] = a3;
        }
        {
            u8 a4 = ((volatile u8 *)arg1)[4];
            u8 a5 = ((volatile u8 *)arg1)[5];
            s32 saved = sp4;
            rc[0] = a4;
            rc[1] = a5;
            if (SBServerListFindByAddress(arg0, saved, sp0) == -1) {
                return 0;
            }
        }
    }
    SBServerListRemoveServerAt(arg0);
    return 0;
}
#pragma scheduling reset
