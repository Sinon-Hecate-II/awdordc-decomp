/* 18 functions from 0x02034164 to 0x0203514C (main), found by ds-decomp. */
#include "common.h"
typedef struct Callbacks3506c { void *(*alloc)(void *,int); int b,c; } Callbacks3506c;
extern M2C_UNK gWfcNet, data_020fb7dc, data_020fb7f0;
extern M2C_UNK sHttpHeaderLineFormat, gHttpHeaderEnd, data_020fb680, data_020fb684;
typedef struct Pair02034164 {s32 first, second;} Pair02034164;
typedef struct Buffer02034164 { s32 start, current, end, size; } Buffer02034164;
typedef struct Unk02034164 {
u8 pad[0x1000];
s32 unk1000, unk1004, unk1008, unk100c;
s32 (*alloc)(M2C_UNK *, s32);
M2C_UNK (*free)(M2C_UNK *, s32, s32);
u8 pad1018[12];
char url[256];
s32 host, path;       /* parsed from url */
s32 unk112c, useTls;  /* useTls: 0 = http, 1 = https */
u16 port;             /* default 80 (http) or 443 (https) */
u8 pad1136[0x896];
s32 lowRecvBuf, lowSendBuf;   /* +0x19CC/+0x19D0: low-level receive/send buffers */
u8 pad19d4[0x24];
s32 buffer[4];                /* +0x19F8: request (send) buffer descriptor */
Buffer02034164 recvBuffer;    /* +0x1A08: raw response header text */
u8 pad1a18[0x20];
Pair02034164 headers[32];     /* +0x1A38: parsed response header name/value pairs */
} Unk02034164;

void HttpClientTask(void) { return; }

/* Releases everything HttpClientInit allocated for the client - the parsed
 * response header pairs, the response and request buffers and the low-level
 * receive/send buffers - then clears the whole context. */
void HttpClientCleanup(Unk02034164 *client) {
M2C_UNK MI_CpuFill8(void *,s32,s32);
void HttpBufferFree(void *,s32 *);
void HttpHeaders_Free(void *,void *,s32);
extern u8 gHttpLowRecvBufName[], gHttpLowSendBufName[];
M2C_UNK (*free)(M2C_UNK *,s32,s32)=client->free;
s32 buf;
if(!client)return;
HttpHeaders_Free(client,client->headers,32);
HttpBufferFree(client,(s32*)&client->recvBuffer);
HttpBufferFree(client,client->buffer);
buf=client->lowRecvBuf;
if(buf){free(gHttpLowRecvBufName,buf,0);client->lowRecvBuf=0;}
buf=client->lowSendBuf;
if(buf){free(gHttpLowSendBufName,buf,0);client->lowSendBuf=0;}
MI_CpuFill8(client,0,0x1c14);
}

/* Formats the request line and Host header into the request buffer: chooses the
 * POST or GET format (client->unk1008 is 0 for POST), reserves room for it plus
 * the host and path (with 0x400 bytes of header slack), and writes the formatted
 * text, advancing the buffer's write position.  Returns 1 when the buffer cannot
 * be reserved, else 0. */
s32 HttpBuildRequest(Unk02034164 *client) {
    s32 HttpBufferReserve(void *, void *, s32);
    extern M2C_UNK sHttpPostRequestFormat;
    extern M2C_UNK sHttpGetRequestFormat;
    M2C_UNK *format;
    s32 hostLength;
    s32 written;
    u32 formatLength;
    Buffer02034164 *buffer = (Buffer02034164 *)client->buffer;

    if (client->unk1008 == 0) format = &sHttpPostRequestFormat;
    else format = &sHttpGetRequestFormat;
    hostLength = StringLength(client->host);
    formatLength = StringLength((s32)format);
    if (HttpBufferReserve(client, (void *)client->buffer, hostLength + (s32)((formatLength - 4) + (u32)StringLength(client->path)) + 0x400) != 1) return 1;
    written = StringFormatN(buffer->current, buffer->size, format, client->path, client->host);
    buffer->current = buffer->current + written;
    return 0;
}

/* Insert a "name: value\r\n" header line at the end of the request's header
 * block, just before its terminating blank line, growing the buffer when it
 * does not fit.  Returns 0, or 1 when the buffer cannot be grown. */
s32 HttpAppendHeader(Unk02034164 *client, char *name, char *value) {
    void MemMove(void *, void *, int);
    char *StringFind(int, void *);
    int HttpBufferGrow(s32, void *, s32);
    Buffer02034164 *buf = (Buffer02034164 *)client->buffer;
    int len = StringLength(value);
    unsigned int fmtLen = StringLength((int)&sHttpHeaderLineFormat);
    signed char saved;
    char *pos;
    int room;

    len += (int)((fmtLen - 4) + (unsigned int)StringLength(name));
    room = buf->end - buf->current;
    if (len + 1 > room && HttpBufferGrow((int)client, buf, len - room + 1) == 0) {
        return 1;
    }
    pos = StringFind(buf->start, &gHttpHeaderEnd) + 2;
    saved = *pos;
    MemMove(pos + len, pos, StringLength((int)pos) + 1);
    pos[StringFormatN(pos, len + 1, &sHttpHeaderLineFormat, name, value)] = saved;
    buf->current += len;
    return 0;
}

s32 func_020346d0(Unk02034164 *obj, char *name, s32 a, s32 b) {
  extern M2C_UNK data_020fb680, data_020fb684;
  s32 func_02037214(s32, s32, void *, s32);
  s32 StringLength(s32);
  int HttpBufferGrow(s32, void *, s32);
  s32 ctr = *(s32 *)((u8 *)obj + 0x19f4);
  Buffer02034164 *buf = (Buffer02034164 *)obj->buffer;
  char *fmtstr;
  s32 first;
  s32 lenf;
  s32 lenn;
  s32 total;
  s32 room;
  s32 r;

  if (ctr == 0) fmtstr = (char *)&data_020fb680;
  else fmtstr = (char *)&data_020fb684;

  *(s32 *)((u8 *)obj + 0x19f4) = ctr + 1;

  first = func_02037214(a, b, (void *)0, 0);

  lenf = StringLength((s32)fmtstr);

  lenn = StringLength((s32)name);

  total = first + ((lenf - 2) + lenn);

  room = buf->end - buf->current;

  if (total > room) {
    if (HttpBufferGrow((s32)obj, buf, total - room + 1) == 0) return 1;
    room = buf->end - buf->current;
  }

  r = StringFormatN(buf->current, room, fmtstr, name);

  buf->current += r;

  room = buf->end - buf->current;

  r = func_02037214(a, b, (void *)buf->current, room - 1);

  if (r < 0) return 1;

  buf->current += first;

  *(char *)buf->current = 0;

  return 0;
}

s32 func_020347dc(s32 arg0, M2C_UNK arg1) {
    s32 StringFormatN(s32, s32, M2C_UNK *, M2C_UNK);
    s32 HttpBufferGrow(s32, void *, s32);
    s32 StringLength(M2C_UNK);
    extern M2C_UNK data_020fb68c;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 var_r1;
    void *temp_r5;

    temp_r5 = arg0 + 0x19F8;
    temp_r0 = StringLength(arg1);
    var_r1 = M2C_FIELD(temp_r5, s32 *, 8) - M2C_FIELD(temp_r5, s32 *, 4);
    if (temp_r0 > var_r1) {
        if (HttpBufferGrow(arg0, temp_r5, (temp_r0 - var_r1) + 1) == 0) {
            return 1;
        }
        var_r1 = M2C_FIELD(temp_r5, s32 *, 8) - M2C_FIELD(temp_r5, s32 *, 4);
        goto block_4;
    }
block_4:
    temp_r0_2 = StringFormatN(M2C_FIELD(temp_r5, s32 *, 4), var_r1, &data_020fb68c, arg1);
    if (temp_r0_2 != temp_r0) {
        return 1;
    }
    M2C_FIELD(temp_r5, s32 *, 4) = (s32) (M2C_FIELD(temp_r5, s32 *, 4) + temp_r0_2);
    return 0;
}

s32 func_02034864(s32 arg0) {
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 & 0x8000) {
        var_r0 &= ~0x8000;
    }
    return var_r0;
}

s32 HttpBufferReserve(void *arg0,void *arg1,s32 arg2) {
extern M2C_UNK data_020fb690;
s32 (*fn)(M2C_UNK *,s32)=M2C_FIELD(arg0,s32 (**)(M2C_UNK *,s32),0x1010);
s32 v;
if(!arg2)return 0;
v=fn(&data_020fb690,arg2);
M2C_FIELD(arg1,s32 *,0)=v;
if(!v)return 0;
M2C_FIELD(arg1,s32 *,4)=v;
M2C_FIELD(arg1,s32 *,12)=arg2;
v=M2C_FIELD(arg1,s32 *,0)+arg2;
M2C_FIELD(arg1,s32 *,8)=v;
return (v!=0);
}

void HttpBufferFree(void *arg0,s32 *arg1) {
M2C_UNK MI_CpuFill8(void *,s32,s32); extern M2C_UNK sHttpFreeBufBufferName;
s32 v=*arg1;
M2C_UNK (*fn)(M2C_UNK *,s32,s32)=M2C_FIELD(arg0,M2C_UNK (**)(M2C_UNK *,s32,s32),0x1014);
if(v)fn(&sHttpFreeBufBufferName,v,0);
MI_CpuFill8(arg1,0,16);
}

s32 HttpBufferGrow(s32 a,void *arg,s32 c){extern M2C_UNK sHttpAllocNewptrName;extern M2C_UNK sHttpFreeBufBufferName;void MI_CpuCopy8(s32,s32,s32);s32 *b=arg;void (*freep)(void *,s32,s32)=M2C_FIELD(a,void (**)(void *,s32,s32),0x1014);s32 (*alloc)(void *,s32)=M2C_FIELD(a,s32 (**)(void *,s32),0x1010);s32 p;if(c<=0)return 0;p=alloc(&sHttpAllocNewptrName,b[3]+c);if(!p)return 0;MI_CpuCopy8(b[0],p,b[3]);freep(&sHttpFreeBufBufferName,b[0],0);if(!p)return 0;b[1]+=p-b[0];b[3]+=c;b[0]=p;b[2]=p+b[3];return 1;}

#pragma opt_common_subs off
/* Parse "http[s]://host[:port][/path]" from urlText into the client: copy the
 * URL into client->url, then split out the host, the optional port (default 80
 * for http, 443 for https), the TLS flag and the path. Returns 1 on success. */
s32 HttpParseUrl(Unk02034164 *client,s32 urlText) {
void StringCopyPad(s32,s32,s32);char *StringFind(int,void *);s32 ParseInt(char *);
extern M2C_UNK sHttpSchemePrefix,sHttpsSchemePrefix,sPortSeparator,sPathSeparator;
char *portStr=0,*match,*path;u32 len;
if((u32)StringLength(urlText)>=256)return 0;
StringCopyPad((s32)client->url,urlText,256);
len=StringLength(urlText);
if(len!=StringLength((s32)client->url))return 0;
match=StringFind((s32)client->url,&sHttpSchemePrefix);
if(match){
client->host=(s32)(client->url+7);
client->useTls=0;client->port=80;
}else{
match=StringFind((s32)client->url,&sHttpsSchemePrefix);
if(!match)return 0;
client->host=(s32)(match+8);
client->useTls=1;client->port=443;
}
match=StringFind(client->host,&sPortSeparator);
if(match){*match=0;portStr=match+1;}
match=StringFind(client->host,&sPathSeparator);
if(!match)client->path=0;else{*match=0;client->path=(s32)(match+1);}
if(portStr)client->port=ParseInt(portStr);
return 1;
}
#pragma opt_common_subs reset
/* Appends one name/value string pair to the HTTP header table: allocates and
 * copies both strings into the next free slot, freeing whatever was allocated if
 * either fails. Returns 1 when the pair was stored, 0 when the table is full or
 * an allocation failed. */
s32 HttpHeaders_Add(Unk02034164 *net,Buffer02034164 *table,s32 name,s32 value) {
void StringCopy(void *,s32);
extern M2C_UNK data_020fb6e4,data_020fb704,data_020fb724,data_020fb740;
s32 (*alloc)(M2C_UNK *,s32)=net->alloc;
M2C_UNK (*free)(M2C_UNK *,s32,s32)=net->free;
if(table->end>table->current)return 0;
((Pair02034164 *)table->start)[table->end].first=alloc(&data_020fb6e4,StringLength(name)+1);
if(((Pair02034164 *)table->start)[table->end].first){
((Pair02034164 *)table->start)[table->end].second=alloc(&data_020fb704,StringLength(value)+1);
if(((Pair02034164 *)table->start)[table->end].second){
StringCopy((void *)((Pair02034164 *)table->start)[table->end].first,name);
StringCopy((void *)((Pair02034164 *)table->start)[table->end].second,value);
table->end++;return 1;}}
if(((Pair02034164 *)table->start)[table->end].first){free(&data_020fb724,((Pair02034164 *)table->start)[table->end].first,0);((Pair02034164 *)table->start)[table->end].first=0;}
if(((Pair02034164 *)table->start)[table->end].second){free(&data_020fb740,((Pair02034164 *)table->start)[table->end].second,0);((Pair02034164 *)table->start)[table->end].second=0;}
return 0;
}

s32 ParseHttpResponse(Unk02034164 *arg0,s32 arg1) {
char *StringFind(s32,void*); s32 StringCompareN(s32,void*,s32); s32 StringLength(s32); M2C_UNK MI_CpuFill8(void*,s32,s32);
extern M2C_UNK data_020fb75c,data_020fb760,data_020fb76c,gHttpHeaderLineEnd,data_020fb770,data_020fb774,data_020fb778;
s32 buf[3]; char *base,*end,*p,*colon,*value,*term; s8 save,save2; s32 result; s32 input;
buf[0]=(s32)((u8*)arg0+0x1a38);buf[1]=32;buf[2]=0;
MI_CpuFill8((void*)buf[0],0,256);
input=M2C_FIELD(arg0,s32*,0x1a08);
base=StringFind(input,&gHttpHeaderEnd);
if(!base)return 0;
end=base+4+StringLength((s32)(base+4));
colon=StringFind(input,&data_020fb75c);
if(!colon)return 0;
save=colon[4];colon[4]='\0';
result=HttpHeaders_Add(arg0,(Buffer02034164*)buf,(s32)&data_020fb760,(s32)(colon+1));
colon[4]=save;
if(result!=1)return 0;
if(arg1==1 || StringCompareN((s32)(colon+1),&data_020fb76c,3)!=0)return 1;
p=StringFind((s32)(colon+5),&gHttpHeaderLineEnd);
if(!p)return 0;
p+=2;
while(!(p[0]==13 || p[1]==10)){
colon=StringFind((s32)p,&data_020fb770);if(!colon)break;
save=*colon;*colon=0;value=colon+2;
term=StringFind((s32)value,&gHttpHeaderLineEnd);
if(!term){*colon=save;break;}
save2=*term;*term=0;
if(HttpHeaders_Add(arg0,(Buffer02034164*)buf,(s32)p,(s32)value)!=1){*colon=save;*term=save2;return 0;}
result=StringLength((s32)value);
*colon=save;*term=save2;p=value+result+2;
}
p=base+4;
while(p<end){
colon=StringFind((s32)p,&data_020fb774);if(!colon)break;
save=*colon;*colon=0;value=colon+1;
term=StringFind((s32)value,&data_020fb778);
if(!term)term=StringFind((s32)value,&gHttpHeaderLineEnd);
if(term){save2=*term;*term=0;}
if(HttpHeaders_Add(arg0,(Buffer02034164*)buf,(s32)p,(s32)value)!=1){*colon=save;if(term)*term=save2;return 0;}
result=StringLength((s32)value);*colon=save;p=value+result+1;if(term)*term=save2;
}
return 1;
}

#pragma opt_propagation on
#pragma opt_strength_reduction off
#pragma opt_common_subs off
s32 FindHttpHeader(void *a,s32 b){s32 StringCompare(s32,s32);s32 i=0;loop:if(M2C_FIELD(((s32)a+i*8),s32 *,0x1a38)!=0){if(StringCompare(b,M2C_FIELD(((s32)a+i*8),s32 *,0x1a38))==0)return M2C_FIELD(((s32)a+i*8),s32 *,0x1a3c);i++;if(i<32)goto loop;}return 0;}
#pragma optimize_ifs off
#pragma scheduling off
s32 ReadHttpHeader(void *a,s32 b,u8 *c,u32 d){
s32 FindHttpHeader(void *,s32);s32 StringLength(s32);s32 func_0203739c(s32,s32,u8 *,u32);
s32 p=FindHttpHeader(a,b);u32 n;
if(!p)return 0;
n=func_0203739c(p,StringLength(p),c,d);
if(n==-1)return n;
if((u32)n>=d)return n;
c[n]=0;return n;
}
#pragma scheduling reset
#pragma optimize_ifs reset
s32 func_02034fa4(void *a,s32 b,void *c,s32 d){s32 FindHttpHeader(void *,s32);s32 StringLength(s32);void StringCopy(void *,s32);s32 p=FindHttpHeader(a,b);if(!p)return 0;if(StringLength(p)>=d)return 0;StringCopy(c,p);return 1;}

void HttpHeaders_Free(void *arg0, void *arg1, s32 arg2) {
extern M2C_UNK data_020fb77c; extern M2C_UNK data_020fb798;
M2C_UNK (*fn)(M2C_UNK *,s32,s32)=M2C_FIELD(arg0,M2C_UNK (**)(M2C_UNK *,s32,s32),0x1014);
Pair02034164 *p=arg1;
M2C_UNK *name1,*name2;
s32 i=0;
if(arg2<=0)return;
name1=&data_020fb77c;name2=&data_020fb798;
do {
if(p[i].first){fn(name1,p[i].first,0);p[i].first=0;}
if(p[i].second){fn(name2,p[i].second,0);p[i].second=0;}
i++;}while(i<arg2);
return;
}

/* Initialise the WFC networking library: allocate the net-check context (0x11F4
 * bytes) and the HTTP client context (0x1C14 bytes) from the caller's allocator,
 * clear them, store the client handlers at context+0x1108, set the client's
 * socket timeout and create the mutex the client state is locked with. Returns
 * 4 if any of that fails or the library is already initialised, 0 on success. */
s32 Dwc_HttpStartup(Callbacks3506c *cb) {
 M2C_UNK InitMutex(void *); M2C_UNK MI_CpuFill8(void *,M2C_UNK,s32); M2C_UNK func_02035304();
 void *(*alloc)(void *,int)=cb->alloc; void *p;
 if(M2C_FIELD(&gWfcNet,void **,0))return 4;
 p=alloc(&data_020fb7dc,0x11f4); M2C_FIELD(&gWfcNet,void **,0)=p;
 if(!p)return 4;
 MI_CpuFill8(p,0,0x11f4);
 M2C_FIELD(M2C_FIELD(&gWfcNet,void **,0),int *,0x1004)=0xfffe7961;
 *(Callbacks3506c *)((u8 *)M2C_FIELD(&gWfcNet,void **,0)+0x1108)=*cb;
 if(M2C_FIELD(&gWfcNet,void **,20))return 4;
 p=alloc(&data_020fb7f0,0x1c14);M2C_FIELD(&gWfcNet,void **,20)=p;
 if(!p)return 4;
 M2C_FIELD(&gWfcNet,int *,4)=0;
 InitMutex((u8 *)M2C_FIELD(&gWfcNet,void **,0)+0x11dc);
 func_02035304();return 0;
}

