/* 25 functions from 0x02047B84 to 0x02048B74 (main), found by ds-decomp. */
#include "common.h"
#include "ghttp.h"
typedef struct { u8 len, family; u16 port; s32 address; } SockAddr;
extern M2C_UNK sWebGetPath;
extern M2C_UNK gWebRequestState, data_020fca68;
extern M2C_UNK gWebRequestState, data_020fca68;
extern M2C_UNK sWebParamData, sWebHashPlaceholder, sWebParamHash, sWebParamPid, data_020fcba0, sWebEmptySuffix, sWebRequestFormat;
extern u8 data_020fca88[56];
extern M2C_UNK data_020fcd10, data_020fcc5c, data_020fcc84;
extern M2C_UNK data_020fcc4c,sArrayInsertSortedComparator,sArrayInsertSortedName,sArrayRemoveAtName;
extern M2C_UNK sVectorIndexCheck, data_020fcc2c, data_020fccb0, data_020fcbf8, data_020fcbe0, sArrayInsertAtArgCheck, sArrayInsertAtName;
extern M2C_UNK data_0213db90, sServiceReplyPrefix;
extern s32 gDnsQueryState[];
extern M2C_UNK data_020fcc98, sDarrayFileName, data_020fcc04;

/* Builds the Nintendo WFC get.asp request into gWebRequestState: formats the
 * base URL with the player id and a hash placeholder, then base64-encodes the
 * 20-byte header plus the payload. Returns 0 on success, 2 when the buffer
 * cannot be allocated, and 3 when the request builder is not ready. */
s32 BuildWebGetRequest(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    extern M2C_UNK gWebRequestState;
    extern M2C_UNK sWebParamData;
    extern M2C_UNK sWebHashPlaceholder;
    extern M2C_UNK sWebParamHash;
    extern M2C_UNK sWebParamPid;
    extern M2C_UNK sWebGetPath;
    extern M2C_UNK data_020fca68;
    extern M2C_UNK sWebEmptySuffix;
    extern M2C_UNK sWebRequestFormat;
    M2C_UNK StringFormat();
s32 Base64EncodedLength(void *);
void HeapFree(s32,s32,s32);
void *HeapAlloc(s32,s32);
s32 EncodeWfcRequestBody(void *,void *,s32,void *,s32);
s32 StringLength(M2C_UNK);
void *func_0206f8b8(void *,void *,s32);

    s32 r5;
 s32 lengths[5];
    void *ptr;
    u32 arr[5];
    char tmp[16];
    
    s32 len_cb1c;
    s32 len_data0, len_cb88;
    s32 accum;
    s32 len_ptr;
    s32 len_cb1c2, len_cb242;
    s32 res;
    s32 len_cac0b;

    if (M2C_FIELD(&gWebRequestState, s32 *, 0x0c) != 1) {
        return 3;
    }

    if (M2C_FIELD(&gWebRequestState, s32 *, 0x54) != 0) {
        HeapFree(0, M2C_FIELD(&gWebRequestState, s32 *, 0x54), 0);
        M2C_FIELD(&gWebRequestState, s32 *, 0x54) = 0;
    }
    r5 = Base64EncodedLength((u8 *)*(void **)arg4+0x18);
    len_cb1c = StringLength(&sWebParamData);
    lengths[0] = StringLength(&sWebHashPlaceholder);
    lengths[1] = StringLength(&sWebParamHash);
    lengths[2] = StringLength(func_0206f8b8((void *)arg2,tmp,10));
    lengths[3] = StringLength(&sWebParamPid);
    lengths[4] = StringLength(&sWebGetPath);
    len_data0 = StringLength(M2C_FIELD(&gWebRequestState,void **,0));
    len_cb88 = StringLength(&data_020fca68);
    accum = r5 + (len_cb1c + (lengths[0] + (lengths[1] + (lengths[2] + (lengths[3] + (lengths[4] + (len_data0 + len_cb88)))))));
    ptr = HeapAlloc(0, accum + 1);
    M2C_FIELD(&gWebRequestState, void **, 0x54) = ptr;
    if (ptr == 0) {
        return 2;
    }

    StringFormat(ptr, &sWebRequestFormat,
                    M2C_FIELD(&gWebRequestState, s32 *, 0x00),
                    &data_020fca68,
                    &sWebGetPath, arg2, &sWebHashPlaceholder, &sWebEmptySuffix);

    ptr=M2C_FIELD(&gWebRequestState,void **,0x54);
    len_ptr = StringLength(ptr);
    M2C_FIELD(&gWebRequestState, void **, 0x5c) = (void *)((u8 *)ptr + len_ptr);

    len_cb1c2 = StringLength(&sWebParamData);
    len_cb242 = StringLength(&sWebHashPlaceholder);
    M2C_FIELD(&gWebRequestState, s32 *, 0x58) =
        (s32)M2C_FIELD(&gWebRequestState, void **, 0x5c) - len_cb1c2 - len_cb242;

    arr[0] = (u32)arg2;
    arr[1] = (u32)arg3;
    arr[2] = (u32)arg1;
    arr[3] = (u32)arg0;
    arr[4] = (u32)*(u32 *)arg4;
    res = EncodeWfcRequestBody(M2C_FIELD(&gWebRequestState, void **, 0x5c), arr, 0x14, (u8 *)arg4+4, *(s32 *)arg4);
    if (res == 2) {
        HeapFree(0, M2C_FIELD(&gWebRequestState, s32 *, 0x54), 0);
        M2C_FIELD(&gWebRequestState, s32 *, 0x54) = 0;
        return 2;
    } else {
        len_cac0b = StringLength(&sWebParamHash);
        *(u8 *)((u8 *)M2C_FIELD(&gWebRequestState, void **, 0x58) - len_cac0b) = 0;
        M2C_FIELD(&gWebRequestState, s32 *, 0x04) = 4;
        return 0;
    }
}

#pragma push
#pragma optimization_level 2
s32 BuildWebSyncRequest(s32 x, s32 y, s32 a, s32 b) {
    s32 Base64EncodedLength(void *);
    void HeapFree(s32, s32, s32);
    void *HeapAlloc(s32, s32);
    s32 EncodeWfcRequestBody(void *, void *, s32, void *, s32);
    s32 StringLength(M2C_UNK);
    void *func_0206f8b8(void *, void *, s32);
    M2C_UNK StringFormat();

    extern M2C_UNK gWebRequestState, data_020fca68, sWebEmptySuffix, sWebParamData, sWebHashPlaceholder, sWebParamHash, sWebParamPid, data_020fcba0, sWebRequestFormat;

    void *g = &gWebRequestState;
    u32 arr[4];
    char tmp[16];
    s32 r6;
    register s32 len_data0;
    s32 len_cb1c,len_cb24,len_cac0,len_after,len_cb50,len_cba0,len_cb88,accum;
    void *ptr;
    s32 len_ptr, len_cb1c2, len_cb242;
    s32 res, len_cac0b;

    if (M2C_FIELD(&gWebRequestState, s32 *, 0x0c) != 1) {
        return 3;
    }

    if (M2C_FIELD(&gWebRequestState, s32 *, 0x54) != 0) {
        HeapFree(0, M2C_FIELD(&gWebRequestState, s32 *, 0x54), 0);
        M2C_FIELD(&gWebRequestState, s32 *, 0x54) = 0;
    }
    r6 = Base64EncodedLength((void *)0x14);

    len_cb1c = StringLength((M2C_UNK)&sWebParamData);
    len_cb24 = StringLength((M2C_UNK)&sWebHashPlaceholder);
    len_cac0 = StringLength((M2C_UNK)&sWebParamHash);
    len_after = StringLength(func_0206f8b8((void *)a, tmp, 10));
    len_cb50 = StringLength((M2C_UNK)&sWebParamPid);
    len_cba0 = StringLength((M2C_UNK)&data_020fcba0);
    len_data0 = StringLength(M2C_FIELD(&gWebRequestState, M2C_UNK *, 0x00));
    len_cb88 = StringLength((M2C_UNK)&data_020fca68);

    accum = r6 + (len_cb1c + (len_cb24 + (len_cac0 + (len_after + (len_cb50 + (len_cba0 + (len_data0 + len_cb88)))))));

    ptr = HeapAlloc(0, accum + 1);
    M2C_FIELD(&gWebRequestState, void **, 0x54) = ptr;
    if (ptr == 0) {
        return 2;
    }

    StringFormat(ptr, &sWebRequestFormat,
                   M2C_FIELD(&gWebRequestState, s32 *, 0x00),
                   &data_020fca68,
                   &data_020fcba0, a, &sWebHashPlaceholder, &sWebEmptySuffix);

    ptr = M2C_FIELD(&gWebRequestState,void **,0x54);
    len_ptr = StringLength(ptr);
    M2C_FIELD(&gWebRequestState, void **, 0x5c) = (void *)((u8 *)ptr + len_ptr);

    len_cb1c2 = StringLength((M2C_UNK)&sWebParamData);
    len_cb242 = StringLength((M2C_UNK)&sWebHashPlaceholder);
    M2C_FIELD(&gWebRequestState, s32 *, 0x58) =
        (s32)M2C_FIELD(&gWebRequestState, void **, 0x5c) - len_cb1c2 - len_cb242;

    arr[0] = (u32)a;
    arr[1] = (u32)y;
    arr[2] = (u32)x;
    arr[3] = (u32)b;

    res = EncodeWfcRequestBody(M2C_FIELD(&gWebRequestState, void **, 0x5c), arr, 0x10, 0, 0);
    if (res == 2) {
        HeapFree(0, M2C_FIELD(&gWebRequestState, s32 *, 0x54), 0);
        M2C_FIELD(&gWebRequestState, s32 *, 0x54) = 0;
        return 2;
    } else {
        len_cac0b = StringLength((M2C_UNK)&sWebParamHash);
        *(u8 *)((u8 *)M2C_FIELD(&gWebRequestState, void **, 0x58) - len_cac0b) = 0;
        M2C_FIELD(&gWebRequestState, s32 *, 0x04) = 4;
        return 0;
    }
}
#pragma pop
/* Validates the web registration parameters (a's id < 32, b's id == 20, c
 * adjusted by 5 is a multiple of 8, d odd, e has exactly one bit set), copies
 * a (32 bytes) into data_020fca68, copies 10 (x,y) pairs from b into
 * data_020fca88, stores c,d,e,f into the state and marks it active. */
s32 func_0204800c(u8 *a, u8 *b, s32 c, u32 d, u32 e, s32 f) {
    s32 StringLength();
    s32 MemCopy();
    s32 i, n;
    u32 k;
    u8 *p;
    M2C_FIELD(&gWebRequestState, s32 *, 12) = 0;
    if ((u32)StringLength(a) >= 32) return 0;
    if (StringLength(b) != 20) return 0;
    if ((c - 5) & 7) return 0;
    if (!(d & 1)) return 0;
    n = 0;
    for (i = 0; i < 32; i++)
        if (((e >> i) & 1) == 1)
            n++;
    if (n != 1) return 0;
    MemCopy(&data_020fca68, a, 32);
    k = 10;
    p = data_020fca88;
    do {
        u8 x = b[0];
        u8 y = b[1];
        b += 2;
        p[0] = x;
        p[1] = y;
        p += 2;
    } while (--k != 0);
    M2C_FIELD(&gWebRequestState, s32 *, 68) = c;
    M2C_FIELD(&gWebRequestState, u32 *, 72) = d;
    M2C_FIELD(&gWebRequestState, u32 *, 76) = e;
    M2C_FIELD(&gWebRequestState, s32 *, 80) = f;
    M2C_FIELD(&gWebRequestState, s32 *, 12) = 1;
    return 1;
}

/* Fills the service-availability DNS query's socket address: family AF_INET,
 * the port byte-swapped into network order, and the IPv4 address of `hostname`
 * (parsed numerically first, else resolved through ghiResolveHostname, whose
 * hostent gives h_addr_list[0]). Returns 0 when the name does not resolve. */
s32 ResolveServiceHostAddress(char *hostname, s32 port, void *addrPtr) {
    s32 ghiInetAddr(char *);
    GhiHostEntry *ghiResolveHostname(char *);
    GhiSocketAddress *addr = addrPtr;
    u16 hostPort = port;
    GhiHostEntry *hostEntry;

    addr->family = 2;
    M2C_FIELD(addr, u16 *, 2) = ((u8)((s32)hostPort >> 8)) | ((hostPort << 8) & 0xff00);
    addr->addr = ghiInetAddr(hostname);
    if (addr->addr == -1) {
        hostEntry = ghiResolveHostname(hostname);
        if (!hostEntry) return 0;
        addr->addr = *(s32 *)*hostEntry->hostent;
    }
    return 1;
}

void func_0204817c(void) {
    s32 GetTickCountMs();
    M2C_UNK ghiSendTo(s32, M2C_UNK *, s32, M2C_UNK, M2C_UNK *, s32);
    extern s32 gDnsQueryState[];
    extern M2C_UNK gDnsPacketHeader;
    extern M2C_UNK data_0213db94;
    ghiSendTo(M2C_FIELD(&gDnsQueryState, s32 *, 4), &data_0213db94, M2C_FIELD(&gDnsQueryState, s32 *, 0x50), 0, &gDnsPacketHeader, 8);
    M2C_FIELD(&gDnsQueryState, s32 *, 0x54) = GetTickCountMs();
}

/* Sets up a DNS query for service availability for the given service name. */
void InitServiceAvailabilityQuery(s8 *serviceName) {
    s32 StringCopy(); s32 func_0204926c(); s32 StringFormat(); s32 ghiSocket(); s32 StringLength(); s32 MemCopy();
    extern M2C_UNK gServiceNameBuffer, gOverrideDnsName, gServiceAvailabilityFormat, gDnsPacketHeader, gDnsQueryNameBuffer;
    s8 hostNameBuffer[64]; s32 hasOverride, dnsNameLength;
    StringCopy(&gServiceNameBuffer, serviceName);
    M2C_FIELD(&gDnsQueryState, s32 *, 4) = -1;
    func_0204926c(&gDnsQueryState);
    hasOverride = M2C_FIELD(&gOverrideDnsName, s8 *, 0);
    if (!hasOverride) StringFormat(hostNameBuffer, &gServiceAvailabilityFormat, serviceName);
    if (!ResolveServiceHostAddress(hasOverride ? (s8 *)&gOverrideDnsName : hostNameBuffer, 0x6cfc, &gDnsPacketHeader)) return;
    M2C_FIELD(&gDnsQueryState, s32 *, 4) = ghiSocket(2, 2, 0);
    if (M2C_FIELD(&gDnsQueryState, s32 *, 4) == -1) return;
    M2C_FIELD(&gDnsQueryState, s8 *, 0x10) = 9;
    dnsNameLength = StringLength(serviceName);
    MemCopy(&gDnsQueryNameBuffer, serviceName, dnsNameLength + 1);
    M2C_FIELD(&gDnsQueryState, s32 *, 0x50) = dnsNameLength + 6;
    func_0204817c();
    M2C_FIELD(&gDnsQueryState, s32 *, 0x58) = 0;
}

/* Checks one datagram received on the service-availability query socket: it must
 * be at least 7 bytes long, come from the address kept in data_0213db90 and from
 * the query's port, and start with sServiceReplyPrefix. The reply's status word
 * follows those 3 prefix bytes, big-endian; it goes to *status. Returns 0 when the
 * datagram is that reply, nonzero when it is something else. */
s32 ParseServiceAvailabilityReply(s8 *packet, s32 length, void *source, u32 *status) {
    s32 ByteCompareN(void *, void *, s32);

    if (length < 7) return 1;
    if (ByteCompareN((u8 *)source + 4, &data_0213db90, 4)) return 1;
    if (((SockAddr *)source)->port != M2C_FIELD(&gDnsQueryState, u16 *, 10)) return 1;
    if (ByteCompareN(packet, &sServiceReplyPrefix, 3)) return 1;
    {
        u32 b3 = (packet[3] << 24) & 0xff000000;
        u32 b4 = (packet[4] << 16) & 0xff0000;
        u32 b5 = (packet[5] << 8) & 0xff00;
        u32 b6 = (u8)packet[6];
        b3 |= b4;
        b3 |= b5;
        *status = b3 | b6;
    }
    return 0;
}

s32 func_0204837c(void) {
s32 ghiSocketCanRecv(void);
s32 ghiRecvFrom(s32,void *,s32,s32,void *,s32 *);
s32 ghiCloseSocket(s32);
s32 GetTickCountMs(void);
s8 buffer[64];
u8 address[8];
s32 len;
u32 flags;
len=8;
if(gDnsQueryState[1]==-1){
gDnsQueryState[0]=1;
return 1;
}
if(ghiSocketCanRecv() && ParseServiceAvailabilityReply(buffer,ghiRecvFrom(gDnsQueryState[1],buffer,64,0,address,&len),address,&flags)==0){
ghiCloseSocket(gDnsQueryState[1]);
if(flags&1)gDnsQueryState[0]=2;
else if(flags&2)gDnsQueryState[0]=3;
else gDnsQueryState[0]=1;
return gDnsQueryState[0];
}
if((u32)GetTickCountMs()>M2C_FIELD(&gDnsQueryState,u32 *,0x54)+2000){
if(gDnsQueryState[22]==1){
ghiCloseSocket(gDnsQueryState[1]);
gDnsQueryState[0]=1;
return 1;
}
func_0204817c();
{s32 n=gDnsQueryState[22]+1;
gDnsQueryState[22]=n;}
}
return 0;
}

void func_020484b8(void *a,s32 b) {
s32 Vector_GetItem(void *,s32);
if(!M2C_FIELD(a,void (**)(),16))return;
M2C_FIELD(a,void (**)(s32),16)(Vector_GetItem(a,b));
}

void Vector_GrowCapacity(void *a) {
s32 gpiRealloc(s32,s32);
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
M2C_FIELD(a,s32 *,4)+=M2C_FIELD(a,s32 *,12);
M2C_FIELD(a,s32 *,20)=gpiRealloc(M2C_FIELD(a,s32 *,20),M2C_FIELD(a,s32 *,4)*M2C_FIELD(a,s32 *,8));
if(!M2C_FIELD(a,s32 *,20))AssertFailed(&data_020fcc98,&sDarrayFileName,&data_020fcc04,65);
}

void Vector_SetItem(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK MemCopy(s32, M2C_UNK, s32);
    MemCopy(Vector_GetItem(arg0, arg2), arg1, M2C_FIELD(arg0, s32 *, 8));
}

/* GameSpy gpi ArrayNew: allocates an array of `capacity` items of `elemSize` bytes
 * each. Layout: +0x00 count, +0x04 capacity, +0x08 item size, +0x0C capacity added
 * when it grows, +0x10 user data (the per-item release callback), +0x14 items. */
s32 *Vector_New(s32 elemSize, s32 capacity, s32 userData) {
s32 gpiMalloc(s32); s32 AssertFailed();
extern M2C_UNK data_020fcbec,data_020fccb8;
s32 *p=gpiMalloc(24);
if(!p)AssertFailed(&data_020fccb0,&sDarrayFileName,&data_020fcbec,0x52);
if(!elemSize)AssertFailed(&data_020fccb8,&sDarrayFileName,&data_020fcbec,0x53);
if(!capacity)capacity=8;
p[0]=0;p[1]=capacity;p[2]=elemSize;p[3]=capacity;p[4]=userData;
if(p[1]) {
p[5]=(s32)gpiMalloc(p[1]*p[2]);
if(!p[5])AssertFailed(&data_020fcc98,&sDarrayFileName,&data_020fcbec,0x5e);
} else p[5]=0;
return p;
}

void Vector_Free(s32 *a) {
s32 AssertFailed();s32 gpiFree();s32 i;
if(!a)AssertFailed(&data_020fccb0,&sDarrayFileName,&data_020fcbf8,0x69);
for(i=0;i<a[0];i++)func_020484b8(a,i);
gpiFree(a[5]);gpiFree(a);
}

s32 Vector_GetCount(s32 *arg0) {
    return *arg0;
}

s32 Vector_GetItem(void *a,s32 b) {
s32 AssertFailed();
if(b<0||b>=M2C_FIELD(a,s32 *,0))AssertFailed(&sVectorIndexCheck,&sDarrayFileName,&data_020fcbe0,0x94);
if(b<0||b>=M2C_FIELD(a,s32 *,0))return 0;
return M2C_FIELD(a,s32 *,20)+M2C_FIELD(a,s32 *,8)*b;
}

void Vector_AddItem(s32 *arg0, M2C_UNK arg1) {
    M2C_UNK Vector_InsertAt(s32 *, M2C_UNK, s32);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fcc10;
    extern M2C_UNK sDarrayFileName;
    extern M2C_UNK data_020fccb0;
    if (arg0 == NULL) {
        AssertFailed(&data_020fccb0, &sDarrayFileName, &data_020fcc10, 0xA0);
    }
    if (arg0 == NULL) {
        return;
    }
    Vector_InsertAt(arg0, arg1, *arg0);
}

/* GameSpy darray.c ArrayInsertAt: inserts `item` at `index`, growing the array
 * when it is full and shifting the items after `index` up by one slot. */
s32 Vector_InsertAt(s32 *array, s32 item, s32 index) {
    s32 AssertFailed();
    s32 MemMove();
    s32 count, dst, newCount;
    if (index < 0 || index > array[0]) AssertFailed(&sArrayInsertAtArgCheck, &sDarrayFileName, &sArrayInsertAtName, 0xa7);
    if (array[0] == array[1]) Vector_GrowCapacity(array);
    newCount = array[0] + 1;
    count = newCount - 1;
    array[0] = newCount;
    if (index < count) {
        dst = Vector_GetItem(array, index + 1);
        MemMove(dst, Vector_GetItem(array, index), array[2] * (count - index));
    }
    Vector_SetItem(array, item, index);
}

/* GameSpy darray ArrayInsertSorted: find the item's place with a binary search
 * using the comparison function, then insert it there. */
void Vector_InsertSorted(s32 *array, s32 item, s32 compare) {
s32 AssertFailed();s32 Vector_SearchSorted(s32,s32,s32,s32,s32,s32 *);s32 RuntimeIntDivMod(s32,s32);
s32 found, pos;
if(!compare)AssertFailed(&sArrayInsertSortedComparator,&sDarrayFileName,&sArrayInsertSortedName,0xb7);
pos=Vector_SearchSorted(item,array[5],array[0],array[2],compare,&found);
Vector_InsertAt(array,item,RuntimeIntDivMod(pos-array[5],array[2]));
}

/* GameSpy darray ArrayRemoveAt: drop the item at `index` by moving the items
 * after it down one slot, then return the array's new count. */
s32 Vector_RemoveAt(s32 *array, s32 index) {
    s32 AssertFailed();
    s32 MemMove(s32, s32, s32);
    s32 last, dst, src;
    if (index < 0 || index >= M2C_FIELD(array, s32 *, VECTOR_COUNT)) AssertFailed(&sVectorIndexCheck, &sDarrayFileName, &sArrayRemoveAtName, 0xc0);
    last = M2C_FIELD(array, s32 *, VECTOR_COUNT) - 1;
    if (index < last) {
        dst = Vector_GetItem(array, index);
        src = Vector_GetItem(array, index + 1);
        MemMove(dst, src, M2C_FIELD(array, s32 *, VECTOR_ELEM_SIZE) * (last - index));
    }
    return --M2C_FIELD(array, s32 *, VECTOR_COUNT);
}

void Vector_RemoveItem(s32 *a,s32 b) {
s32 Vector_RemoveAt();s32 AssertFailed();
if(b<0||b>=a[0])AssertFailed(&sVectorIndexCheck,&sDarrayFileName,&data_020fcc2c,0xca);
func_020484b8(a,b);Vector_RemoveAt(a,b);
}

void Vector_ReplaceItem(s32 *a,s32 b,s32 c){s32 AssertFailed();if(c<0||c>=a[0])AssertFailed(&sVectorIndexCheck,&sDarrayFileName,&data_020fcc4c,0xd3);func_020484b8(a,c);Vector_SetItem(a,b,c);}

void Vector_Sort(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_02067610(s32, s32, s32, M2C_UNK);
    func_02067610(M2C_FIELD(arg0, s32 *, 0x14), M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 8), arg1);
}

/* GameSpy darray ArraySearch: returns the index of `item` in `array`, searching
 * from item `startIndex` on - a binary search when `isSorted` is set (then only an
 * exact hit counts), a linear scan otherwise - or -1 when it is not there. */
s32 Vector_Search(void *array, s32 item, s32 compare, s32 startIndex, s32 isSorted) {
    s32 Vector_SearchSorted(s32, s32, s32, s32, s32, s32 *);
    s32 Vector_SearchLinear(s32, s32, s32, s32, s32);
    s32 RuntimeIntDivMod(s32, s32);
    s32 found = 1;
    s32 count, offset;

    if (!array || !(count = M2C_FIELD(array, s32 *, 0))) return -1;
    if (isSorted)
        offset = Vector_SearchSorted(item, Vector_GetItem(array, startIndex), count - startIndex,
                                     M2C_FIELD(array, s32 *, 8), compare, &found);
    else
        offset = Vector_SearchLinear(item, Vector_GetItem(array, startIndex), count - startIndex,
                                     M2C_FIELD(array, s32 *, 8), compare);
    if (!offset || !found) return -1;
    return RuntimeIntDivMod(offset - M2C_FIELD(array, s32 *, 20), M2C_FIELD(array, s32 *, 8));
}

void func_02048a9c(s32 *a,void (*b)(s32,s32),s32 c) {
s32 AssertFailed();s32 i;
if(!b)AssertFailed(&data_020fcd10,&sDarrayFileName,&data_020fcc5c,0x104);
for(i=a[0]-1;i>=0;i--)b(Vector_GetItem(a,i),c);
}

/* GameSpy darray ArrayFind: walk the items from the last one down, returning
 * the first item for which the test callback returns 0, or 0 when none does. */
s32 Vector_Find(s32 *array,s32 (*test)(s32,s32),s32 context) {
s32 AssertFailed();s32 i,item;
if(!test)AssertFailed(&data_020fcd10,&sDarrayFileName,&data_020fcc84,0x121);
for(i=M2C_FIELD(array,s32 *,VECTOR_COUNT)-1;i>=0;i--){item=Vector_GetItem(array,i);if(!test(item,context))return item;}
return 0;
}

