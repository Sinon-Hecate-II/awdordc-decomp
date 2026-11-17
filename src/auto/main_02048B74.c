/* 53 functions from 0x02048B74 to 0x02049AB8 (main), found by ds-decomp. */
#include "common.h"

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

s32 func_02048ba0(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3, s32 (*arg4)(M2C_UNK, s32)) {
    s32 var_r4;
    s32 var_r5;

    var_r4 = 0;
    if (arg2 > 0) {
        var_r5 = 0;
        do {
            if (arg4(arg0, arg1 + var_r5) == 0) {
                return arg3 * var_r4 + arg1;
            }
            var_r4 += 1;
            var_r5 += arg3;
        } while (var_r4 < arg2);
    }
    return 0;
}

s32 func_02048bf8(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3, s32 (*arg4)(s32, M2C_UNK), s32 *arg5) {
    s32 var_r4;
    s32 var_r5;
    s32 temp_r6;
    s32 temp_r0;

    var_r4 = 0;
    *arg5 = 0;
    var_r5 = arg2 - 1;
    if (var_r5 >= 0) {
        do {
            temp_r6 = (s32) (var_r4 + var_r5) >> 1;
            temp_r0 = arg4(temp_r6 * arg3 + arg1, arg0);
            if (temp_r0 == 0) {
                *arg5 = 1;
            }
            if (temp_r0 < 0) {
                var_r4 = temp_r6 + 1;
            } else {
                var_r5 = temp_r6 - 1;
            }
        } while (var_r4 <= var_r5);
    }
    return var_r4 * arg3 + arg1;
}

void func_02048c5c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4) {
    M2C_UNK TableNew2(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    TableNew2(arg0, arg1, 4, arg2, arg3, arg4);
}

/* GameSpy hashtable.c TableNew2: allocates a table of nBuckets bucket vectors
   (each an empty vector of elemSize-byte elements) and stores the caller's hash
   and comparison callbacks.  Table layout: +0x00 buckets, +0x04 count,
   +0x08 userData, +0x0C hashFn, +0x10 compFn. */
M2C_UNK TableNew2(M2C_UNK elemSize, M2C_UNK nBuckets, M2C_UNK bucketSize, M2C_UNK hashFn, s32 compFn, M2C_UNK userData) {
    extern M2C_UNK data_020fcd7c, data_020fcd84, data_020fcd14, data_020fcd90, data_020fcd98, data_020fcda4, data_020fcdb0, data_020fcdb8;
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    M2C_UNK gpiMalloc(s32);
    M2C_UNK Vector_New(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK table;
    s32 i;
    if (hashFn == 0) AssertFailed(&data_020fcd7c, &data_020fcd84, &data_020fcd14, 0x38);
    if (compFn == 0) AssertFailed(&data_020fcd90, &data_020fcd84, &data_020fcd14, 0x39);
    if (elemSize == 0) AssertFailed(&data_020fcd98, &data_020fcd84, &data_020fcd14, 0x3a);
    if (nBuckets == 0) AssertFailed(&data_020fcda4, &data_020fcd84, &data_020fcd14, 0x3b);
    table = gpiMalloc(0x14);
    if (table == 0) AssertFailed(&data_020fcdb0, &data_020fcd84, &data_020fcd14, 0x3e);
    M2C_FIELD(table, M2C_UNK **, 0) = (M2C_UNK *)gpiMalloc((s32)nBuckets * 4);
    if (M2C_FIELD(table, M2C_UNK **, 0) == 0) AssertFailed(&data_020fcdb8, &data_020fcd84, &data_020fcd14, 0x41);
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

void func_02048dc4(s32 **arg0) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    M2C_UNK Vector_Free(s32);
    M2C_UNK gpiFree(M2C_UNK);
    extern M2C_UNK data_020fcd20;
    extern M2C_UNK data_020fcd84;
    extern M2C_UNK data_020fcdb0;
    s32 var_r4;

    if (arg0 == NULL) {
        AssertFailed(&data_020fcdb0, &data_020fcd84, &data_020fcd20, 0x51);
    }
    if (arg0 == NULL) {
        return;
    }
    var_r4 = 0;
    if (M2C_FIELD(arg0, s32 *, 4) > 0) {
        do {
            Vector_Free(M2C_FIELD(arg0, s32 **, 0)[var_r4]);
            var_r4 += 1;
        } while (var_r4 < M2C_FIELD(arg0, s32 *, 4));
    }
    gpiFree(M2C_FIELD(arg0, s32 **, 0));
    gpiFree(arg0);
}

s32 func_02048e38(void *p) {
extern M2C_UNK data_020fcdb0,data_020fcd84,data_020fcd38;
s32 Vector_GetCount(s32);
s32 i, sum=0;
if(!p)AssertFailed(&data_020fcdb0,&data_020fcd84,&data_020fcd38,0x61);
if(!p)return 0;
for(i=0;i<M2C_FIELD(p,s32 *,4);i++)sum+=Vector_GetCount(M2C_FIELD(p,s32 **,0)[i]);
return sum;
}

void func_02048eac(void *p,s32 a) {
extern M2C_UNK data_020fcdb0,data_020fcd84,data_020fcd2c;
s32 Vector_Search(s32,s32,s32,s32,s32);
M2C_UNK Vector_AddItem(s32,s32);
M2C_UNK func_02048964(s32,s32,s32);
s32 i,n;
if(!p)AssertFailed(&data_020fcdb0,&data_020fcd84,&data_020fcd2c,0x71);
if(!p)return;
i=M2C_FIELD(p,s32 (**)(s32,s32),12)(a,M2C_FIELD(p,s32 *,4));
n=Vector_Search(M2C_FIELD(p,s32 **,0)[i],a,M2C_FIELD(p,s32 *,16),0,0);
if(n==-1)Vector_AddItem(M2C_FIELD(p,s32 **,0)[i],a);
else func_02048964(M2C_FIELD(p,s32 **,0)[i],a,n);
}

s32 func_02048f54(void *p,s32 a) {
extern M2C_UNK data_020fcdb0,data_020fcd84,data_020fcd44;
s32 Vector_Search(s32,s32,s32,s32,s32);
s32 i,n;
if(!p)AssertFailed(&data_020fcdb0,&data_020fcd84,&data_020fcd44,0x82);
if(!p)return 0;
i=M2C_FIELD(p,s32 (**)(s32,s32),12)(a,M2C_FIELD(p,s32 *,4));
n=Vector_Search(M2C_FIELD(p,s32 **,0)[i],a,M2C_FIELD(p,s32 *,16),0,0);
if(n==-1)return 0;
Vector_RemoveItem(M2C_FIELD(p,s32 **,0)[i],n);
return 1;
}

s32 func_02048ff8(void *p,s32 a) {
extern M2C_UNK data_020fcdb0,data_020fcd84,data_020fcd50;
s32 Vector_GetItem(s32,s32);
s32 i,n;
if(!p)AssertFailed(&data_020fcdb0,&data_020fcd84,&data_020fcd50,0x94);
if(!p)return 0;
i=M2C_FIELD(p,s32 (**)(s32,s32),12)(a,M2C_FIELD(p,s32 *,4));
n=Vector_Search(M2C_FIELD(p,s32 **,0)[i],a,M2C_FIELD(p,s32 *,16),0,0);
if(n==-1)return 0;
return Vector_GetItem(M2C_FIELD(p,s32 **,0)[i],n);
}

void Vector_ForEach(void *p,s32 a,s32 b) {
extern M2C_UNK data_020fcdc8,data_020fcd84,data_020fcd5c;
void func_02048a9c(s32,s32,s32);
s32 i;
if(!a)AssertFailed(&data_020fcdc8,&data_020fcd84,&data_020fcd5c,0xb6);
for(i=0;i<M2C_FIELD(p,s32 *,4);i++)func_02048a9c(M2C_FIELD(p,s32 **,0)[i],a,b);
}

s32 func_02049104(void *p,s32 a,s32 b) {
extern M2C_UNK data_020fcdc8,data_020fcd84,data_020fcd6c;
s32 func_02048afc(s32,s32,s32);
s32 i,n;
if(!a)AssertFailed(&data_020fcdc8,&data_020fcd84,&data_020fcd6c,0xd3);
for(i=0;i<M2C_FIELD(p,s32 *,4);i++){n=func_02048afc(M2C_FIELD(p,s32 **,0)[i],a,b);if(n)return n;}
return 0;
}

void func_0204917c(u8 *a,char *b){extern char data_020fcdcc[];unsigned int i=0;int off=0;do {StringFormat(b+off,data_020fcdcc,a[i]);i++;off+=2;}while(i<16);}

void Md5Hex(int a,int b,char *c){u8 ctx[88];u8 digest[16];func_02027090(ctx);func_0202709c(ctx,a,b);func_020270a8(digest,ctx);func_0204917c(digest,c);}

unsigned long long GetTickCountMs(void){int func_02006f8c(void);unsigned long long GetSystemTick(void);extern char data_020fcdf0[],data_020fce10[],data_020fcde0[];if(func_02006f8c()!=1)AssertFailed(data_020fcdf0,data_020fce10,data_020fcde0,0x109);return (GetSystemTick()<<6)/0x82ea;}

void gpiSleep(void) {
    M2C_UNK func_02006030();
    func_02006030();
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

