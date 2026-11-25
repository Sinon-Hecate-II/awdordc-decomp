/* 53 functions from 0x02048B74 to 0x02049AB8 (main), found by ds-decomp. */
#include "common.h"
#include "md5.h"

typedef struct { u8 bytes[8]; } UnkSocketAddress;

void func_02048b74(M2C_UNK arg0) {
    s32 Vector_GetCount();
    M2C_UNK Vector_RemoveItem(M2C_UNK, s32);
    s32 var_r4;

    var_r4 = Vector_GetCount() - 1;
    if (var_r4 < 0) {
        return;
    }
    do {
        Vector_RemoveItem(arg0, var_r4);
        var_r4 -= 1;
    } while (var_r4 >= 0);
}

/* GameSpy darray ArraySearchLinear: scan the `count` elemSize-byte elements at
 * `base` from the first on, calling compare(item, element) on each; return the
 * address of the first element the comparator accepts (returns 0), or 0 when
 * none does. */
s32 Vector_SearchLinear(s32 item, s32 base, s32 count, s32 elemSize, s32 (*compare)(s32, s32)) {
    s32 i;
    s32 offset;

    i = 0;
    if (count > 0) {
        offset = 0;
        do {
            if (compare(item, base + offset) == 0) {
                return elemSize * i + base;
            }
            i += 1;
            offset += elemSize;
        } while (i < count);
    }
    return 0;
}

/* GameSpy darray ArraySearchSorted: binary-search `item` among the `count`
   elemSize-byte elements at `base` with compare(element, item), set *found when
   an equal element was seen, and return the address where `item` belongs. */
s32 Vector_SearchSorted(M2C_UNK item, s32 base, s32 count, s32 elemSize, s32 (*compare)(s32, M2C_UNK), s32 *found) {
    s32 low;
    s32 high;
    s32 mid;
    s32 order;

    low = 0;
    *found = 0;
    high = count - 1;
    if (high >= 0) {
        do {
            mid = (s32) (low + high) >> 1;
            order = compare(mid * elemSize + base, item);
            if (order == 0) {
                *found = 1;
            }
            if (order < 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } while (low <= high);
    }
    return low * elemSize + base;
}

void TableNewDefault(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4) {
    M2C_UNK TableNew2(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    TableNew2(arg0, arg1, 4, arg2, arg3, arg4);
}

/* GameSpy hashtable.c TableNew2: allocates a table of nBuckets bucket vectors
   (each an empty vector of elemSize-byte elements) and stores the caller's hash
   and comparison callbacks.  Table layout: +0x00 buckets, +0x04 count,
   +0x08 userData, +0x0C hashFn, +0x10 compFn. */
M2C_UNK TableNew2(M2C_UNK elemSize, M2C_UNK nBuckets, M2C_UNK bucketSize, M2C_UNK hashFn, s32 compFn, M2C_UNK userData) {
    extern M2C_UNK data_020fcd7c, gHashtableFileName, data_020fcd14, data_020fcd90, data_020fcd98, data_020fcda4, sAssertTable, data_020fcdb8;
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    M2C_UNK gpiMalloc(s32);
    M2C_UNK Vector_New(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK table;
    s32 i;
    if (hashFn == 0) AssertFailed(&data_020fcd7c, &gHashtableFileName, &data_020fcd14, 0x38);
    if (compFn == 0) AssertFailed(&data_020fcd90, &gHashtableFileName, &data_020fcd14, 0x39);
    if (elemSize == 0) AssertFailed(&data_020fcd98, &gHashtableFileName, &data_020fcd14, 0x3a);
    if (nBuckets == 0) AssertFailed(&data_020fcda4, &gHashtableFileName, &data_020fcd14, 0x3b);
    table = gpiMalloc(0x14);
    if (table == 0) AssertFailed(&sAssertTable, &gHashtableFileName, &data_020fcd14, 0x3e);
    M2C_FIELD(table, M2C_UNK **, 0) = (M2C_UNK *)gpiMalloc((s32)nBuckets * 4);
    if (M2C_FIELD(table, M2C_UNK **, 0) == 0) AssertFailed(&data_020fcdb8, &gHashtableFileName, &data_020fcd14, 0x41);
    i = 0;
    if ((s32)nBuckets <= 0) goto done;
    do {
        M2C_FIELD(table, M2C_UNK **, 0)[i] = Vector_New(elemSize, bucketSize, userData);
        i++;
    } while (i < (s32)nBuckets);
done:
    M2C_FIELD(table, s32 *, 4) = (s32)nBuckets;
    M2C_FIELD(table, M2C_UNK *, 8) = userData;
    M2C_FIELD(table, M2C_UNK *, 0x10) = compFn;
    M2C_FIELD(table, M2C_UNK *, 0xc) = hashFn;
    return table;
}

/* GameSpy hashtable.c TableFree: releases every bucket vector, then the bucket
 * array and the table itself; a NULL table is an assertion failure. */
void TableFree(HashTable *table) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    M2C_UNK Vector_Free(s32);
    M2C_UNK gpiFree(M2C_UNK);
    extern M2C_UNK sTableFreeName;
    extern M2C_UNK gHashtableFileName;
    extern M2C_UNK sAssertTable;
    s32 i;

    if (table == NULL) {
        AssertFailed(&sAssertTable, &gHashtableFileName, &sTableFreeName, 0x51);
    }
    if (table == NULL) {
        return;
    }
    i = 0;
    if (table->nBuckets > 0) {
        do {
            Vector_Free(table->buckets[i]);
            i += 1;
        } while (i < table->nBuckets);
    }
    gpiFree(table->buckets);
    gpiFree(table);
}

/* GameSpy hashtable.c TableCount: returns how many elements the table holds, the
 * sum of the element counts of its bucket vectors; a NULL table asserts and
 * counts as empty. */
s32 TableCount(HashTable *table) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    s32 Vector_GetCount(s32);
    extern M2C_UNK sAssertTable, gHashtableFileName, sTableCountName;
    s32 i, sum = 0;

    if (!table) AssertFailed(&sAssertTable, &gHashtableFileName, &sTableCountName, 0x61);
    if (!table) return 0;
    for (i = 0; i < table->nBuckets; i++) sum += Vector_GetCount(table->buckets[i]);
    return sum;
}

/* GameSpy hashtable TableEnter: hashes the element with the table's hash
 * function and appends it to that bucket's vector, or replaces the equal
 * element already in the bucket. */
void TableEnter(void *table,s32 data) {
extern M2C_UNK sAssertTable,gHashtableFileName,sTableEnterName;
s32 Vector_Search(s32,s32,s32,s32,s32);
M2C_UNK Vector_Append(s32,s32);
M2C_UNK Vector_ReplaceItem(s32,s32,s32);
s32 bucket,index;
if(!table)AssertFailed(&sAssertTable,&gHashtableFileName,&sTableEnterName,0x71);
if(!table)return;
bucket=M2C_FIELD(table,s32 (**)(s32,s32),12)(data,M2C_FIELD(table,s32 *,4));
index=Vector_Search(M2C_FIELD(table,s32 **,0)[bucket],data,M2C_FIELD(table,s32 *,16),0,0);
if(index==-1)Vector_Append(M2C_FIELD(table,s32 **,0)[bucket],data);
else Vector_ReplaceItem(M2C_FIELD(table,s32 **,0)[bucket],data,index);
}

/* GameSpy hashtable TableRemove: hashes the element into its bucket and
 * removes the equal element found there; returns 0 if the table has none. */
s32 TableRemove(HashTable *table, s32 data) {
    extern M2C_UNK sAssertTable, gHashtableFileName, sTableRemoveName;
    s32 Vector_Search(s32,s32,s32,s32,s32);
    M2C_UNK Vector_RemoveItem(s32,s32);
    s32 bucket, index;

    if (!table) AssertFailed(&sAssertTable, &gHashtableFileName, &sTableRemoveName, 0x82);
    if (!table) return 0;
    bucket = table->hash(data, table->nBuckets);
    index = Vector_Search(table->buckets[bucket], data, (s32)table->compare, 0, 0);
    if (index == -1) return 0;
    Vector_RemoveItem(table->buckets[bucket], index);
    return 1;
}

/* GameSpy hashtable.c TableLookup: hashes the key into its bucket and returns the
 * element equal to it, or 0 when the table holds none. */
s32 TableLookup(HashTable *table,s32 data) {
 extern M2C_UNK sAssertTable,gHashtableFileName,sTableLookupName;
 s32 Vector_GetItem(s32,s32);
 s32 i,n;
 if(!table)AssertFailed(&sAssertTable,&gHashtableFileName,&sTableLookupName,0x94);
 if(!table)return 0;
 i=table->hash(data,table->nBuckets);
 n=Vector_Search(table->buckets[i],data,(s32)table->compare,0,0);
 if(n==-1)return 0;
 return Vector_GetItem(table->buckets[i],n);
}

/* GameSpy hashtable.c TableMapSafe: run callback over every element of every
 * bucket; a NULL callback is an assertion failure. */
void TableMapSafe(HashTable *table, void (*callback)(s32, s32), s32 userData) {
extern M2C_UNK sAssertFn,gHashtableFileName,sTableMapSafeName;
void Vector_MapBackwards(s32 *, void (*)(s32, s32), s32);
s32 i;
if(!callback)AssertFailed(&sAssertFn,&gHashtableFileName,&sTableMapSafeName,0xb6);
for(i=0;i<table->nBuckets;i++)Vector_MapBackwards((s32 *)table->buckets[i],callback,userData);
}

/* GameSpy hashtable.c TableMapSafe2: run `callback` over the elements of every
 * bucket and return the first element it accepts (a nonzero result), or 0 when no
 * element is accepted. */
s32 TableMapSafe2(HashTable *table, s32 (*callback)(s32, s32), s32 userData) {
    extern M2C_UNK sAssertFn, gHashtableFileName, sTableMapSafe2Name;
    s32 Vector_Find(s32 *, s32 (*)(s32, s32), s32);
    s32 i, found;

    if (!callback) AssertFailed(&sAssertFn, &gHashtableFileName, &sTableMapSafe2Name, 0xd3);
    for (i = 0; i < table->nBuckets; i++) {
        found = Vector_Find(table->buckets[i], callback, userData);
        if (found) return found;
    }
    return 0;
}

/* Write the MD5_DIGEST_SIZE-byte `digest` as 32 lowercase hex characters into
 * `hex`. */
void FormatMD5Hex(u8 *digest, char *hex) {
    extern char gMD5HexFormat[];
    unsigned int i = 0;
    int offset = 0;
    do {
        StringFormat(hex + offset, gMD5HexFormat, digest[i]);
        i++;
        offset += 2;
    } while (i < MD5_DIGEST_SIZE);
}

/* Fill `hex` with the hexadecimal MD5 digest of the `length` bytes at `data`. */
void Md5Hex(void *data, u32 length, char *hex) {
    u8 context[88];
    u8 digest[16];
    MD5ContextInit(context);
    MD5ContextUpdate(context, data, length);
    MD5ContextFinal(digest, context);
    FormatMD5Hex(digest, hex);
}

/* Convert the hardware system tick count to milliseconds, asserting that the tick timer is initialized. */
unsigned long long GetSystemTickMilliseconds(void) {
    int IsSystemTickInitialized(void);
    unsigned long long GetSystemTick(void);
    extern char sAssertTickAvailable[];
    extern char sNonportFileName[];
    extern char data_020fcde0[];

    if (IsSystemTickInitialized() != 1) {
        AssertFailed(sAssertTickAvailable, sNonportFileName, data_020fcde0, 0x109);
    }
    return (GetSystemTick() << 6) / TICKS_TO_MS_DIVISOR;
}

void gpiSleep(void) {
    M2C_UNK SleepMilliseconds();
    SleepMilliseconds();
}

void func_0204926c(void) {

}

void func_02049270(void) {

}

s32 gpiStringDup(s32 arg0) {
    s32 gpiMalloc(s32);
    s32 StringLength();
    M2C_UNK StringCopy(s32, s32);
    s32 temp_r0;

    if (arg0 == 0) {
        return 0;
    }
    temp_r0 = gpiMalloc(StringLength() + 1);
    if (temp_r0 != 0) {
        StringCopy(temp_r0, arg0);
    }
    return temp_r0;
}

#pragma push
#pragma optimization_level 2
#pragma opt_if_conversion off

#pragma pop

/* Polls a single fd for readability/priority/error; sets output flags accordingly. */

