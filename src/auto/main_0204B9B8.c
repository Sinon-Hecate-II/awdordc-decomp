/* 11 functions from 0x0204B9B8 to 0x0204C7FC (main), found by ds-decomp. */
#include "common.h"
#include "ghttp.h"
typedef struct { u8 bytes[4]; } BCDCBytes;

s32 func_0204b9b8(void *arg0) {
 M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
 s32 func_02064bcc(s32);
 s32 func_02064ed0(s32,s32,s32);
 void func_02064ffc(s32);
 extern M2C_UNK data_020fd224, sAssertZero, sGhttpPostFile;
 s32 state = *M2C_FIELD(arg0,s32 **,0);
 M2C_FIELD(arg0,s32 *,4)=-1;
 if(state == 0) goto success;
 if(state == 1) {
 if (!M2C_FIELD(arg0,s32 *,8)) return 0;
 if (func_02064ed0(M2C_FIELD(arg0,s32 *,8),0,2)) return 0;
 M2C_FIELD(arg0,s32 *,12)=func_02064bcc(M2C_FIELD(arg0,s32 *,8));
 if (M2C_FIELD(arg0,s32 *,12)==-1) return 0;
 func_02064ffc(M2C_FIELD(arg0,s32 *,8));
 } else if(state != 2) {
 AssertFailed(&sAssertZero,&sGhttpPostFile,&data_020fd224,0x244); return 0;
 }
 success:
 return 1;
}

void func_0204ba68(void *arg0) {
 M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
 void func_02064934(s32);
 extern M2C_UNK data_020fd238, sAssertZero, sGhttpPostFile;
 s32 state = *M2C_FIELD(arg0, s32 **, 0);
 if(state == 0) return;
 if(state == 1) {
 if (M2C_FIELD(arg0,s32 *,8)) func_02064934(M2C_FIELD(arg0,s32 *,8));
 M2C_FIELD(arg0,s32 *,8)=0;
 return;
 }
 if(state == 2) return;
 AssertFailed(&sAssertZero,&sGhttpPostFile,&data_020fd238,0x269); return;
}

s32 func_0204bad4(void *arg0) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    s32 Vector_GetCount(s32);
    void *func_02048558(s32, s32, s32);
    void *Vector_GetItem(s32, s32);
    s32 func_0204b9b8(void *);
    void func_020486f8(void *, void *);
    void func_0204ba68(void *);
    void func_0204861c(s32);
    s32 func_0204b958(void *);
    extern M2C_UNK data_020fd440, sGhttpPostFile, data_020fd1fc, data_020fd454;

    s32 i;
    s32 count;
    s32 zero = 0;
    s32 buf[4];

    if (M2C_FIELD(arg0, void **, 0x13c) == 0) {
        AssertFailed(&data_020fd440, &sGhttpPostFile, &data_020fd1fc, 0x278);
    }
    if (M2C_FIELD(arg0, void **, 0x13c) == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x144) = 0;
    M2C_FIELD(arg0, s32 *, 0x148) = 0;
    M2C_FIELD(arg0, s32 *, 0x14c) = 0;
    M2C_FIELD(arg0, s32 *, 0x150) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x13c), s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x154) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x13c), s32 *, 8);
    count = Vector_GetCount(M2C_FIELD(M2C_FIELD(arg0, void **, 0x13c), s32 *, 0));
    M2C_FIELD(arg0, s32 *, 0x140) = (s32)func_02048558(0x10, count, 0);
    if (M2C_FIELD(arg0, s32 *, 0x140) == 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        s32 v = (s32)Vector_GetItem(M2C_FIELD(M2C_FIELD(arg0, void **, 0x13c), s32 *, 0), i);
        *(volatile s32 *)&buf[0] = 0;
        buf[0] = v;
        buf[1] = zero;
        buf[2] = zero;
        buf[3] = zero;
        if (func_0204b9b8(buf) == 0) {
            i--;
            if (i >= 0) {
                do {
                    void *e = Vector_GetItem(M2C_FIELD(arg0, s32 *, 0x140), i);
                    func_0204ba68(e);
                    i--;
                } while (i >= 0);
            }
            func_0204861c(M2C_FIELD(arg0, s32 *, 0x140));
            M2C_FIELD(arg0, s32 *, 0x140) = 0;
            return 0;
        }
        func_020486f8(M2C_FIELD(arg0, s32 *, 0x140), buf);
    }
    if (Vector_GetCount(M2C_FIELD(M2C_FIELD(arg0, void **, 0x13c), s32 *, 0)) != Vector_GetCount(M2C_FIELD(arg0, s32 *, 0x140))) {
        AssertFailed(&data_020fd454, &sGhttpPostFile, &data_020fd1fc, 0x2b1);
    }
    M2C_FIELD(arg0, s32 *, 0x14c) = func_0204b958(arg0);
    return 1;
}

void func_0204bc64(void *arg0) {
 void func_0204861c(s32);
 s32 Vector_GetCount(s32);
 void *Vector_GetItem(s32,s32);
 void func_0204b690(void *);
 s32 i, count;
 void *p;
 if(M2C_FIELD(arg0,s32 *,0x140)) {
 count=Vector_GetCount(M2C_FIELD(arg0,s32 *,0x140));
 for(i=0;i<count;i++) func_0204ba68(Vector_GetItem(M2C_FIELD(arg0,s32 *,0x140),i));
 func_0204861c(M2C_FIELD(arg0,s32 *,0x140));
 M2C_FIELD(arg0,s32 *,0x140)=0;
 }
 p=M2C_FIELD(arg0,void **,0x13c);
 if(p && M2C_FIELD(p,s32 *,0x10)) {
 func_0204b690(p);
 M2C_FIELD(arg0,void **,0x13c)=0;
 }
}

s32 ghiPostStringStateDoPosting(void *p,void *ctx) {
s32 ghiSocketSend(); s8 *StringFindChar(s32,s32);
extern s32 data_020fd4a8,sGhttpPostFile,data_020fd294,data_020fd4b8,data_020fd4e4;
extern s8 data_020fd4f4[],data_020fd340[]; extern BCDCBytes data_020ea97c;
BCDCBytes buf; register BCDCBytes *out; s32 i,ch; s8 *str; s32 hi,n,r;
if(M2C_FIELD(p,s32 *,4)<0)AssertFailed(&data_020fd4a8,&sGhttpPostFile,&data_020fd294,0x2e7);
if(M2C_FIELD(M2C_FIELD(p,void **,0),s32 *,12)==0)return 1;
if(M2C_FIELD(p,s32 *,4)>=M2C_FIELD(M2C_FIELD(p,void **,0),s32 *,12))AssertFailed(&data_020fd4b8,&sGhttpPostFile,&data_020fd294,0x2ee);
if(M2C_FIELD(M2C_FIELD(ctx,void **,0x13c),s32 *,12)==0 && M2C_FIELD(M2C_FIELD(p,void **,0),s32 *,16)!=0){
str=M2C_FIELD(M2C_FIELD(p,void **,0),s8 **,8);
out=&buf; *out=data_020ea97c;
i=0;while((ch=str[i])!=0){
if(StringFindChar((s32)data_020fd340,ch))AppendChar(ctx+0x50,ch);
else if(ch==32)AppendChar(ctx+0x50,43);
else {hi=ch/16;if(hi>=16)AssertFailed(&data_020fd4e4,&sGhttpPostFile,&data_020fd294,0x30d);
out->bytes[1]=data_020fd4f4[hi];out->bytes[2]=data_020fd4f4[ch%16];ghiAppendDataToBuffer(ctx+0x50,out,3);}
i++;
}return 1;
}
n=M2C_FIELD(M2C_FIELD(p,void **,0),s32 *,12)-M2C_FIELD(p,s32 *,4);
r=ghiSocketSend(ctx,M2C_FIELD(M2C_FIELD(p,void **,0),void **,8),n);
if(r==-1)return 0;
M2C_FIELD(p,s32 *,4)+=r;
return r==n?1:2;
}

s32 ghiPostFileDiskStateDoPosting(void *state,void *context){
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
s32 func_02064bcc(s32);
s32 func_02064230(void *,s32,s32,s32);
s32 ghiSendData(void *,void *,s32);
extern M2C_UNK data_020fd4a8,sGhttpPostFile,data_020fd2b0,data_020fd508,data_020fd530;
u8 buf[4096];s32 n,result;
if(M2C_FIELD(state,s32 *,4)<0)AssertFailed(&data_020fd4a8,&sGhttpPostFile,&data_020fd2b0,0x336);
if(M2C_FIELD(state,s32 *,4)>=M2C_FIELD(state,s32 *,12))AssertFailed(&data_020fd508,&sGhttpPostFile,&data_020fd2b0,0x337);
if(M2C_FIELD(state,s32 *,4)!=func_02064bcc(M2C_FIELD(state,s32 *,8)))AssertFailed(&data_020fd530,&sGhttpPostFile,&data_020fd2b0,0x338);
do{
n=func_02064230(buf,1,4096,M2C_FIELD(state,s32 *,8));
if(n<=0){M2C_FIELD(context,s32 *,0xfc)=1;M2C_FIELD(context,s32 *,0x38)=14;return 0;}
M2C_FIELD(state,s32 *,4)+=n;
if(M2C_FIELD(state,s32 *,4)>M2C_FIELD(state,s32 *,12)){M2C_FIELD(context,s32 *,0xfc)=1;M2C_FIELD(context,s32 *,0x38)=14;return 0;}
result=ghiSendData(context,buf,n);
if(result==0)return 0;
if(M2C_FIELD(state,s32 *,4)==M2C_FIELD(state,s32 *,12))return 1;
}while(result==1);
return 2;
}

/* Posts pending bytes from state->data into context, up to 0x8000 at a time; returns 0 on write error, 1 when fully posted, 2 when no progress. */
s32 ghiPostFileMemoryStateDoPosting(void *state, M2C_UNK context) {
    s32 ghiSocketSend(M2C_UNK, s32, s32);
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_020fd2f0;
    extern M2C_UNK sGhttpPostFile;
    extern M2C_UNK data_020fd4a8;
    extern M2C_UNK data_020fd568;
    s32 written;
    s32 total;
    s32 avail;
    s32 pos;
    s32 chunk;
    void *info;

    if ((s32) M2C_FIELD(state, s32 *, 4) < 0) {
        AssertFailed(&data_020fd4a8, &sGhttpPostFile, &data_020fd2f0, 0x36E);
    }
    total = M2C_FIELD(M2C_FIELD(state, void **, 0), s32 *, 0xC);
    if (total == 0) {
        return 1;
    }
    if ((s32) M2C_FIELD(state, s32 *, 4) >= total) {
        AssertFailed(&data_020fd568, &sGhttpPostFile, &data_020fd2f0, 0x375);
    }
loop_7:
    info = M2C_FIELD(state, void **, 0);
    pos = M2C_FIELD(state, s32 *, 4);
    chunk = M2C_FIELD(info, s32 *, 0xC) - pos;
    if (chunk >= 0x8000) {
        chunk = 0x8000;
    }
    written = ghiSocketSend(context, M2C_FIELD(info, s32 *, 8) + pos, chunk);
    if (written == -1) {
        return 0;
    }
    avail = M2C_FIELD(state, s32 *, 4) + written;
    M2C_FIELD(state, s32 *, 4) = avail;
    if (M2C_FIELD(M2C_FIELD(state, void **, 0), s32 *, 0xC) == avail) {
        return 1;
    }
    if (written == 0) {
        return 2;
    }
    goto loop_7;
}

/* Posts one part of a multipart/form-data request: on the first call it writes
 * the part header (or the "name=" query parameter for a GET) and sends it, then
 * hands the body to the string, disk-file or in-memory-file state handler. */
s32 ghiPostStateDoPosting(void *state, void *context, s32 isFirstPart) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    M2C_UNK StringFormat(void *, void *, ...);
    s32 StringLength(const char *);
    s32 ghiSendData(void *, void *, s32);
    s32 ghiPostStringStateDoPosting(void *, void *);
    s32 ghiPostFileDiskStateDoPosting(void *, void *);
    s32 ghiPostFileMemoryStateDoPosting(void *, M2C_UNK);
    extern M2C_UNK sAssertDataIsString, sGhttpPostFile, sGhiPostStateDoPosting, sQueryParamFirstFormat, sQueryParamNextFormat, sMultipartBoundary, sMultipartBoundaryNext, sMultipartValueFormat, sMultipartFileFormat, sAssertZero, sAssertDataIsFileMemory;

    u8 buf[0x800];

    if (((GHIPostState *)state)->pos == -1) {
        ((GHIPostState *)state)->pos = 0;
        if (M2C_FIELD(M2C_FIELD(context, void **, 0x13c), s32 *, 0xc) == 0) {
            if (((GHIPostState *)state)->data->type != GHIString) {
                AssertFailed(&sAssertDataIsString, &sGhttpPostFile, &sGhiPostStateDoPosting, 0x3a9);
            }
            if (isFirstPart) StringFormat(buf, &sQueryParamFirstFormat, ((GHIPostState *)state)->data->name);
            else StringFormat(buf, &sQueryParamNextFormat, ((GHIPostState *)state)->data->name);
        } else {
            GHIPostData *data = ((GHIPostState *)state)->data;
            s32 type = data->type;
            if (type == GHIString) {
                StringFormat(buf, &sMultipartValueFormat,
                              isFirstPart ? &sMultipartBoundary : &sMultipartBoundaryNext,
                              data->name);
            } else if (type == GHIFile || type == GHIFileMemory) {
                s32 filename, contentType;
                if (type == GHIFile) {
                    filename = (s32)data->u.diskFile.filename;
                    contentType = (s32)data->u.diskFile.contentType;
                } else {
                    filename = (s32)data->u.memoryFile.filename;
                    contentType = (s32)data->u.memoryFile.contentType;
                }
                StringFormat(buf, &sMultipartFileFormat,
                              isFirstPart ? &sMultipartBoundary : &sMultipartBoundaryNext,
                              data->name, filename, contentType);
            } else {
                AssertFailed(&sAssertZero, &sGhttpPostFile, &sGhiPostStateDoPosting, 0x3dc);
            }
        }
        {
            s32 len = StringLength((const char *)buf);
            s32 res = ghiSendData(context, buf, len);
            if (res == 0) return 0;
            if (res == 2) return 2;
        }
    }

    {
        GHIPostData *data = ((GHIPostState *)state)->data;
        s32 type = data->type;
        if (type == GHIString) return ghiPostStringStateDoPosting(state, context);
        if (type == GHIFile) return ghiPostFileDiskStateDoPosting(state, context);
        if (type != GHIFileMemory) {
            AssertFailed(&sAssertDataIsFileMemory, &sGhttpPostFile, &sGhiPostStateDoPosting, 0x3f5);
        }
        return ghiPostFileMemoryStateDoPosting(state, context);
    }
}

/* Uploads the prepared POST body of the connection through its item list:
 * flushes any buffered bytes first, writes each item with the state machine's
 * do-posting routine (the first item marks the start of the body), then sends
 * the closing multipart boundary. Returns 0 on error, 1 when done, 2 when the
 * caller has to come back for more. */
s32 ghiPostDoPosting(void *connection){
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);s32 Vector_GetCount(s32);void *Vector_GetItem(s32,s32);s32 SendBufferedData(void *);void ResetBuffer(void *);s32 ghiSendData(void *,void *,s32);s32 StringLength(const char *);
extern M2C_UNK data_020fd6c0,sGhttpPostFile,data_020fd210,data_020fd440,data_020fd6cc,data_020fd454,data_020fd6ec,data_020fd710,data_020fd760,data_020fd76c,sMultipartBoundaryEnd;
void *item;s32 result,total;
if(!connection)AssertFailed(&data_020fd6c0,&sGhttpPostFile,&data_020fd210,0x404);
if(!M2C_FIELD(connection,s32 *,GHI_POST_DATA))AssertFailed(&data_020fd440,&sGhttpPostFile,&data_020fd210,0x405);
if(!M2C_FIELD(connection,s32 *,GHI_POST_ITEMS))AssertFailed(&data_020fd6cc,&sGhttpPostFile,&data_020fd210,0x406);
if(Vector_GetCount(M2C_FIELD(M2C_FIELD(connection,void **,GHI_POST_DATA),s32 *,0))!=Vector_GetCount(M2C_FIELD(connection,s32 *,GHI_POST_ITEMS)))AssertFailed(&data_020fd454,&sGhttpPostFile,&data_020fd210,0x407);
if(M2C_FIELD(connection,s32 *,GHI_POST_INDEX)<0)AssertFailed(&data_020fd6ec,&sGhttpPostFile,&data_020fd210,0x408);
if(M2C_FIELD(connection,s32 *,GHI_POST_INDEX)>Vector_GetCount(M2C_FIELD(connection,s32 *,GHI_POST_ITEMS)))AssertFailed(&data_020fd710,&sGhttpPostFile,&data_020fd210,0x409);
total=Vector_GetCount(M2C_FIELD(connection,s32 *,GHI_POST_ITEMS));
if(M2C_FIELD(connection,s32 *,GHI_BUFFER_LEN)){if(!SendBufferedData(connection))return 0;if(M2C_FIELD(connection,s32 *,GHI_BUFFER_POS)<M2C_FIELD(connection,s32 *,GHI_BUFFER_LEN))return 2;ResetBuffer(connection+0x50);
if(M2C_FIELD(connection,volatile s32 *,GHI_POST_INDEX)==total)return 1;}
while(M2C_FIELD(connection,s32 *,GHI_POST_INDEX)<total){
item=Vector_GetItem(M2C_FIELD(connection,s32 *,GHI_POST_ITEMS),M2C_FIELD(connection,s32 *,GHI_POST_INDEX));
if(!item)AssertFailed(&data_020fd760,&sGhttpPostFile,&data_020fd210,0x42f);
result=ghiPostStateDoPosting(item,connection,M2C_FIELD(connection,s32 *,GHI_POST_INDEX)==0);
if(!result){if(!M2C_FIELD(connection,s32 *,GHI_COMPLETED)||!M2C_FIELD(connection,s32 *,GHI_RESULT))AssertFailed(&data_020fd76c,&sGhttpPostFile,&data_020fd210,0x43b);return 0;}
if(result==2)return 2;
M2C_FIELD(connection,s32 *,GHI_POST_INDEX)++;
}
if(M2C_FIELD(M2C_FIELD(connection,void **,GHI_POST_DATA),s32 *,12)){if(!ghiSendData(connection,&sMultipartBoundaryEnd,StringLength(&sMultipartBoundaryEnd)))return 0;}
return M2C_FIELD(connection,s32 *,GHI_BUFFER_LEN)?2:1;
}

s32 func_0204c580(void *a) {
s32 gpiStringDup(s8 *); s32 StringCompareN(s8 *,void *,s32); s8 *StringFindChar(s32,s32); s32 func_02068f1c(s8 *,void *); s32 ParseInt(s8 *);
extern u8 gGhttpAssertConnection[],gGhttpProcessFileName[],data_020fd7c4[],data_020fd874[],data_020fd884[],data_020fd88c[],data_020fd898[];extern s8 data_020fd89c[];
s8 *p,*q; s32 n,v; s8 ch; s32 secure;
if(!a)AssertFailed(gGhttpAssertConnection,gGhttpProcessFileName,data_020fd7c4,37);
if(!a)return 0;
if(!M2C_FIELD(a,s32 *,20))AssertFailed(data_020fd874,gGhttpProcessFileName,data_020fd7c4,43);
p=M2C_FIELD(a,s8 **,20);if(!p)return 0;
if(!StringCompareN(p,data_020fd884,7)){p+=7;secure=0;}
else if(!StringCompareN(p,data_020fd88c,8)){p+=8;secure=1;}
else return 0;
n=func_02068f1c(p,data_020fd898);ch=p[n];p[n]=0;
M2C_FIELD(a,s32 *,24)=gpiStringDup(p);
if(!M2C_FIELD(a,s32 *,24))return 0;
p[n]=ch;p+=n;
if(*p==58){p++;M2C_FIELD(a,u16 *,32)=ParseInt(p);if(!M2C_FIELD(a,u16 *,32))return 0;
do {s8 c=*++p; if(c==0)break; if(c==47)break;}while(1);
}else{if(secure)M2C_FIELD(a,u16 *,32)=443;else M2C_FIELD(a,u16 *,32)=80;}
done: if(!*p)p=data_020fd89c;
M2C_FIELD(a,s32 *,36)=gpiStringDup(p);
v=M2C_FIELD(a,s32 *,36);
q=StringFindChar(v,32);
if(q){do{*q=43;v=M2C_FIELD(a,s32 *,36);q=StringFindChar(v,32);}while(q);}
if(v==0)return 0;return 1;
}

void func_0204c738(void *p) {
void InvokeRequestCallback(void *,s32,s32); void func_0204926c(void); s32 func_0204c580(void *);s32 func_020498e4(s32);void *ghiResolveHostname(s32);extern s32 gHttpServerOverride;
s32 id,v;void *q;
InvokeRequestCallback(p,0,0);func_0204926c();
if(!func_0204c580(p)){M2C_FIELD(p,s32 *,0xfc)=1;M2C_FIELD(p,s32 *,0x38)=3;return;}
id=M2C_FIELD(p,s32 *,0x15c);
if(id==0) { id=gHttpServerOverride ? gHttpServerOverride : M2C_FIELD(p,s32 *,0x18); }
v=func_020498e4(id);M2C_FIELD(p,s32 *,0x1c)=v;
if(v==-1){
q=ghiResolveHostname(id);
if(!q){M2C_FIELD(p,s32 *,0xfc)=1;M2C_FIELD(p,s32 *,0x38)=4;return;}
M2C_FIELD(p,s32 *,0x1c)=**M2C_FIELD(q,s32 ***,12);
}
M2C_FIELD(p,s32 *,0x10)=1;InvokeRequestCallback(p,0,0);
}

