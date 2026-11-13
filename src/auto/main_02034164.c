/* 18 functions from 0x02034164 to 0x0203514C (main), found by ds-decomp. */
#include "common.h"
typedef struct Callbacks3506c { void *(*alloc)(void *,int); int b,c; } Callbacks3506c;
extern M2C_UNK gWfcNet, data_020fb7dc, data_020fb7f0;
extern M2C_UNK data_020fb674, data_020fb59c, data_020fb680, data_020fb684;
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
s32 unk19cc, unk19d0;
u8 pad19d4[0x24];
s32 buffer[4];
} Unk02034164;

void func_02034164(void) { return; }

void func_02034480(Unk02034164 *arg0) {
M2C_UNK MI_CpuFill8(void *,s32,s32);
void func_020348c8(void *,s32 *);
void func_02034fe4(void *,void *,s32);
extern M2C_UNK data_020fb5d0; extern M2C_UNK data_020fb5e8;
M2C_UNK (*fn)(M2C_UNK *,s32,s32)=M2C_FIELD(arg0,M2C_UNK (**)(M2C_UNK *,s32,s32),0x1014);
s32 v;
if(!arg0)return;
func_02034fe4(arg0,(u8*)arg0 + 0x1a38,32);
func_020348c8(arg0,(s32*)((u8*)arg0 + 0x1a08));
func_020348c8(arg0,(s32*)((u8*)(u8*)arg0 + 0x19f8));
v=arg0->unk19cc;
if(v){fn(&data_020fb5d0,v,0);arg0->unk19cc=0;}
v=arg0->unk19d0;
if(v){fn(&data_020fb5e8,v,0);arg0->unk19d0=0;}
MI_CpuFill8(arg0,0,0x1c14);
}

s32 func_02034534(Unk02034164 *arg0) {
s32 func_02034870(void *,void *,s32);
extern M2C_UNK data_020fb600;extern M2C_UNK data_020fb654;
M2C_UNK *fmt; s32 a,n; u32 b; void *p=arg0->buffer;
if(arg0->unk1008==0)fmt=&data_020fb600;else fmt=&data_020fb654;
a=StringLength(arg0->host);
b=StringLength((s32)fmt);
if(func_02034870(arg0,(u8*)arg0 + 0x19f8,a+(s32)((b-4)+(u32)StringLength(arg0->path))+0x400)!=1)return 1;
n=func_0200567c(M2C_FIELD(p,s32 *,4),M2C_FIELD(p,s32 *,12),fmt,arg0->path,arg0->host);
M2C_FIELD(p,s32 *,4)=M2C_FIELD(p,s32 *,4)+n;
return 0;
}

s32 func_020345f4(Unk02034164 *obj,int a,int b) {
 void MemMove(void *,void *,int); char *StringFind(int,void *); int func_02034908(s32,void *,s32);
 Buffer02034164 *buf=(Buffer02034164 *)obj->buffer;
 int n=StringLength(b); unsigned int fmt=StringLength((int)&data_020fb674);
 signed char save; char *p; int room;
 n+= (int)((fmt-4)+(unsigned int)StringLength(a));
 room=buf->end-buf->current;
 if(n+1>room && func_02034908((int)obj,buf,n-room+1)==0)return 1;
 p=StringFind(buf->start,&data_020fb59c)+2;
 save=*p;
 MemMove(p+n,p,StringLength((int)p)+1);
 p[func_0200567c(p,n+1,&data_020fb674,a,b)]=save;
 buf->current+=n;return 0;
}

s32 func_020346d0(Unk02034164 *obj, char *name, s32 a, s32 b) {
  extern M2C_UNK data_020fb680, data_020fb684;
  s32 func_02037214(s32, s32, void *, s32);
  s32 StringLength(s32);
  int func_02034908(s32, void *, s32);
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
    if (func_02034908((s32)obj, buf, total - room + 1) == 0) return 1;
    room = buf->end - buf->current;
  }

  r = func_0200567c(buf->current, room, fmtstr, name);

  buf->current += r;

  room = buf->end - buf->current;

  r = func_02037214(a, b, (void *)buf->current, room - 1);

  if (r < 0) return 1;

  buf->current += first;

  *(char *)buf->current = 0;

  return 0;
}

s32 func_020347dc(s32 arg0, M2C_UNK arg1) {
    s32 func_0200567c(s32, s32, M2C_UNK *, M2C_UNK);
    s32 func_02034908(s32, void *, s32);
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
        if (func_02034908(arg0, temp_r5, (temp_r0 - var_r1) + 1) == 0) {
            return 1;
        }
        var_r1 = M2C_FIELD(temp_r5, s32 *, 8) - M2C_FIELD(temp_r5, s32 *, 4);
        goto block_4;
    }
block_4:
    temp_r0_2 = func_0200567c(M2C_FIELD(temp_r5, s32 *, 4), var_r1, &data_020fb68c, arg1);
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

s32 func_02034870(void *arg0,void *arg1,s32 arg2) {
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

void func_020348c8(void *arg0,s32 *arg1) {
M2C_UNK MI_CpuFill8(void *,s32,s32); extern M2C_UNK data_020fb6a4;
s32 v=*arg1;
M2C_UNK (*fn)(M2C_UNK *,s32,s32)=M2C_FIELD(arg0,M2C_UNK (**)(M2C_UNK *,s32,s32),0x1014);
if(v)fn(&data_020fb6a4,v,0);
MI_CpuFill8(arg1,0,16);
}

s32 func_02034908(s32 a,void *arg,s32 c){extern M2C_UNK data_020fb6b8;extern M2C_UNK data_020fb6a4;void MI_CpuCopy8(s32,s32,s32);s32 *b=arg;void (*freep)(void *,s32,s32)=M2C_FIELD(a,void (**)(void *,s32,s32),0x1014);s32 (*alloc)(void *,s32)=M2C_FIELD(a,s32 (**)(void *,s32),0x1010);s32 p;if(c<=0)return 0;p=alloc(&data_020fb6b8,b[3]+c);if(!p)return 0;MI_CpuCopy8(b[0],p,b[3]);freep(&data_020fb6a4,b[0],0);if(!p)return 0;b[1]+=p-b[0];b[3]+=c;b[0]=p;b[2]=p+b[3];return 1;}

#pragma opt_common_subs off
/* Parse "http[s]://host[:port][/path]" from urlText into the client: copy the
 * URL into client->url, then split out the host, the optional port (default 80
 * for http, 443 for https), the TLS flag and the path. Returns 1 on success. */
s32 HttpParseUrl(Unk02034164 *client,s32 urlText) {
void func_02068d18(s32,s32,s32);char *StringFind(int,void *);s32 ParseInt(char *);
extern M2C_UNK sHttpSchemePrefix,sHttpsSchemePrefix,sPortSeparator,sPathSeparator;
char *portStr=0,*match,*path;u32 len;
if((u32)StringLength(urlText)>=256)return 0;
func_02068d18((s32)client->url,urlText,256);
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
extern M2C_UNK data_020fb75c,data_020fb760,data_020fb76c,data_020fb5cc,data_020fb770,data_020fb774,data_020fb778;
s32 buf[3]; char *base,*end,*p,*colon,*value,*term; s8 save,save2; s32 result; s32 input;
buf[0]=(s32)((u8*)arg0+0x1a38);buf[1]=32;buf[2]=0;
MI_CpuFill8((void*)buf[0],0,256);
input=M2C_FIELD(arg0,s32*,0x1a08);
base=StringFind(input,&data_020fb59c);
if(!base)return 0;
end=base+4+StringLength((s32)(base+4));
colon=StringFind(input,&data_020fb75c);
if(!colon)return 0;
save=colon[4];colon[4]='\0';
result=HttpHeaders_Add(arg0,(Buffer02034164*)buf,(s32)&data_020fb760,(s32)(colon+1));
colon[4]=save;
if(result!=1)return 0;
if(arg1==1 || StringCompareN((s32)(colon+1),&data_020fb76c,3)!=0)return 1;
p=StringFind((s32)(colon+5),&data_020fb5cc);
if(!p)return 0;
p+=2;
while(!(p[0]==13 || p[1]==10)){
colon=StringFind((s32)p,&data_020fb770);if(!colon)break;
save=*colon;*colon=0;value=colon+2;
term=StringFind((s32)value,&data_020fb5cc);
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
if(!term)term=StringFind((s32)value,&data_020fb5cc);
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
#pragma opt_propagation off
s32 ReadHttpHeader(void *a,s32 b,u8 *c,u32 d){
s32 FindHttpHeader(void *,s32);s32 StringLength(s32);s32 func_0203739c(s32,s32,u8 *,u32);
s32 p=FindHttpHeader(a,b),n;
if(!p)return 0;
n=func_0203739c(p,StringLength(p),c,d);
if(n==-1)return n;
if((u32)n>=d)return n;
c[n]=0;return n;
}
#pragma opt_propagation reset
s32 func_02034fa4(void *a,s32 b,void *c,s32 d){s32 FindHttpHeader(void *,s32);s32 StringLength(s32);void StringCopy(void *,s32);s32 p=FindHttpHeader(a,b);if(!p)return 0;if(StringLength(p)>=d)return 0;StringCopy(c,p);return 1;}

void func_02034fe4(void *arg0, void *arg1, s32 arg2) {
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

s32 func_0203506c(Callbacks3506c *cb) {
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

