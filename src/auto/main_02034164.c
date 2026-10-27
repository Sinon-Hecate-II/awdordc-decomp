/* 18 functions from 0x02034164 to 0x0203514C (main), found by ds-decomp. */
#include "common.h"
typedef struct Callbacks3506c { void *(*alloc)(void *,int); int b,c; } Callbacks3506c;
extern M2C_UNK data_0213d138, data_020fb7dc, data_020fb7f0;
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
s32 unk1124, unk1128;
s32 unk112c, unk1130;
u16 unk1134;
u8 pad1136[0x896];
s32 unk19cc, unk19d0;
u8 pad19d4[0x24];
s32 buffer[4];
} Unk02034164;

void func_02034480(Unk02034164 *arg0) {
M2C_UNK func_02007f8c(void *,s32,s32);
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
func_02007f8c(arg0,0,0x1c14);
}

s32 func_02034534(Unk02034164 *arg0) {
s32 func_02034870(void *,void *,s32);
extern M2C_UNK data_020fb600;extern M2C_UNK data_020fb654;
M2C_UNK *fmt; s32 a,n; u32 b; void *p=arg0->buffer;
if(arg0->unk1008==0)fmt=&data_020fb600;else fmt=&data_020fb654;
a=func_02068c34(arg0->unk1124);
b=func_02068c34((s32)fmt);
if(func_02034870(arg0,(u8*)arg0 + 0x19f8,a+(s32)((b-4)+(u32)func_02068c34(arg0->unk1128))+0x400)!=1)return 1;
n=func_0200567c(M2C_FIELD(p,s32 *,4),M2C_FIELD(p,s32 *,12),fmt,arg0->unk1128,arg0->unk1124);
M2C_FIELD(p,s32 *,4)=M2C_FIELD(p,s32 *,4)+n;
return 0;
}

s32 func_020345f4(Unk02034164 *obj,int a,int b) {
 void func_020651c4(void *,void *,int); char *func_02068fdc(int,void *); int func_02034908(s32,void *,s32);
 Buffer02034164 *buf=(Buffer02034164 *)obj->buffer;
 int n=func_02068c34(b); unsigned int fmt=func_02068c34((int)&data_020fb674);
 signed char save; char *p; int room;
 n+= (int)((fmt-4)+(unsigned int)func_02068c34(a));
 room=buf->end-buf->current;
 if(n+1>room && func_02034908((int)obj,buf,n-room+1)==0)return 1;
 p=func_02068fdc(buf->start,&data_020fb59c)+2;
 save=*p;
 func_020651c4(p+n,p,func_02068c34((int)p)+1);
 p[func_0200567c(p,n+1,&data_020fb674,a,b)]=save;
 buf->current+=n;return 0;
}

s32 func_020346d0(Unk02034164 *obj, char *name, s32 a, s32 b) {
  extern M2C_UNK data_020fb680, data_020fb684;
  s32 func_02037214(s32, s32, void *, s32);
  s32 func_02068c34(s32);
  int func_02034908(s32, void *, s32);
  s32 ctr = *(s32 *)((u8 *)obj + 0x1000 + 0x9f4);
  char *fmtstr;
  Buffer02034164 *buf = (Buffer02034164 *)((u8 *)obj + 0x1f8 + 0x1800);
  s32 first;
  s32 lenf;
  s32 lenn;
  s32 total;
  s32 room;
  s32 r;

  if (ctr == 0)
    fmtstr = (char *)&data_020fb680;
  else
    fmtstr = (char *)&data_020fb684;

  *(s32 *)((u8 *)obj + 0x1000 + 0x9f4) = ctr + 1;

  first = func_02037214(a, b, (void *)0, 0);

  lenf = func_02068c34((s32)fmtstr);

  lenn = func_02068c34((s32)name);

  total = first + (lenf - 2 + lenn);

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
    s32 func_02068c34(M2C_UNK);
    extern M2C_UNK data_020fb68c;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 var_r1;
    void *temp_r5;

    temp_r5 = arg0 + 0x19F8;
    temp_r0 = func_02068c34(arg1);
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
M2C_UNK func_02007f8c(void *,s32,s32); extern M2C_UNK data_020fb6a4;
s32 v=*arg1;
M2C_UNK (*fn)(M2C_UNK *,s32,s32)=M2C_FIELD(arg0,M2C_UNK (**)(M2C_UNK *,s32,s32),0x1014);
if(v)fn(&data_020fb6a4,v,0);
func_02007f8c(arg1,0,16);
}

s32 func_02034908(s32 a,void *arg,s32 c){extern M2C_UNK data_020fb6b8;extern M2C_UNK data_020fb6a4;void func_02008048(s32,s32,s32);s32 *b=arg;void (*freep)(void *,s32,s32)=M2C_FIELD(a,void (**)(void *,s32,s32),0x1014);s32 (*alloc)(void *,s32)=M2C_FIELD(a,s32 (**)(void *,s32),0x1010);s32 p;if(c<=0)return 0;p=alloc(&data_020fb6b8,b[3]+c);if(!p)return 0;func_02008048(b[0],p,b[3]);freep(&data_020fb6a4,b[0],0);if(!p)return 0;b[1]+=p-b[0];b[3]+=c;b[0]=p;b[2]=p+b[3];return 1;}

#pragma opt_common_subs off
s32 func_020349b0(Unk02034164 *p,s32 text) {
void func_02068d18(s32,s32,s32);char *func_02068fdc(int,void *);s32 func_0206ad38(char *);
extern M2C_UNK data_020fb6c8,data_020fb6d0,data_020fb6dc,data_020fb6e0;
char *port=0,*q,*path;u32 n;
if((u32)func_02068c34(text)>=256)return 0;
func_02068d18((s32)p->url,text,256);
n=func_02068c34(text);
if(n!=func_02068c34((s32)p->url))return 0;
q=func_02068fdc((s32)p->url,&data_020fb6c8);
if(q){
p->unk1124=(s32)(p->url+7);
p->unk1130=0;p->unk1134=80;
}else{
q=func_02068fdc((s32)p->url,&data_020fb6d0);
if(!q)return 0;
p->unk1124=(s32)(q+8);
p->unk1130=1;p->unk1134=443;
}
q=func_02068fdc(p->unk1124,&data_020fb6dc);
if(q){*q=0;port=q+1;}
q=func_02068fdc(p->unk1124,&data_020fb6e0);
if(!q)p->unk1128=0;else{*q=0;p->unk1128=(s32)(q+1);}
if(port)p->unk1134=func_0206ad38(port);
return 1;
}
#pragma opt_common_subs reset
s32 func_02034b04(Unk02034164 *obj,Buffer02034164 *buf,s32 a,s32 b) {
void func_02068c50(void *,s32);
extern M2C_UNK data_020fb6e4,data_020fb704,data_020fb724,data_020fb740;
s32 (*alloc)(M2C_UNK *,s32)=obj->alloc;
M2C_UNK (*free)(M2C_UNK *,s32,s32)=obj->free;
if(buf->end>buf->current)return 0;
((Pair02034164 *)buf->start)[buf->end].first=alloc(&data_020fb6e4,func_02068c34(a)+1);
if(((Pair02034164 *)buf->start)[buf->end].first){
((Pair02034164 *)buf->start)[buf->end].second=alloc(&data_020fb704,func_02068c34(b)+1);
if(((Pair02034164 *)buf->start)[buf->end].second){
func_02068c50((void *)((Pair02034164 *)buf->start)[buf->end].first,a);
func_02068c50((void *)((Pair02034164 *)buf->start)[buf->end].second,b);
buf->end++;return 1;}}
if(((Pair02034164 *)buf->start)[buf->end].first){free(&data_020fb724,((Pair02034164 *)buf->start)[buf->end].first,0);((Pair02034164 *)buf->start)[buf->end].first=0;}
if(((Pair02034164 *)buf->start)[buf->end].second){free(&data_020fb740,((Pair02034164 *)buf->start)[buf->end].second,0);((Pair02034164 *)buf->start)[buf->end].second=0;}
return 0;
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
s32 func_02034ef8(void *a,s32 b){s32 func_02068d98(s32,s32);s32 i=0;loop:if(M2C_FIELD(((s32)a+i*8),s32 *,0x1a38)!=0){if(func_02068d98(b,M2C_FIELD(((s32)a+i*8),s32 *,0x1a38))==0)return M2C_FIELD(((s32)a+i*8),s32 *,0x1a3c);i++;if(i<32)goto loop;}return 0;}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
s32 func_02034f50(void *a,s32 b,u8 *c,u32 d){s32 func_02034ef8(void *,s32);s32 func_02068c34(s32);s32 func_0203739c(s32,s32,u8 *,u32);s32 p=func_02034ef8(a,b);s32 n;if(!p)return 0;n=func_0203739c(p,func_02068c34(p),c,d);if(n==-1)return n;if((u32)n<d){c[n]=0;return n;}return n;}
#pragma optimize_ifs reset
s32 func_02034fa4(void *a,s32 b,void *c,s32 d){s32 func_02034ef8(void *,s32);s32 func_02068c34(s32);void func_02068c50(void *,s32);s32 p=func_02034ef8(a,b);if(!p)return 0;if(func_02068c34(p)>=d)return 0;func_02068c50(c,p);return 1;}

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
 M2C_UNK func_0200654c(void *); M2C_UNK func_02007f8c(void *,M2C_UNK,s32); M2C_UNK func_02035304();
 void *(*alloc)(void *,int)=cb->alloc; void *p;
 if(M2C_FIELD(&data_0213d138,void **,0))return 4;
 p=alloc(&data_020fb7dc,0x11f4); M2C_FIELD(&data_0213d138,void **,0)=p;
 if(!p)return 4;
 func_02007f8c(p,0,0x11f4);
 M2C_FIELD(M2C_FIELD(&data_0213d138,void **,0),int *,0x1004)=0xfffe7961;
 *(Callbacks3506c *)((u8 *)M2C_FIELD(&data_0213d138,void **,0)+0x1108)=*cb;
 if(M2C_FIELD(&data_0213d138,void **,20))return 4;
 p=alloc(&data_020fb7f0,0x1c14);M2C_FIELD(&data_0213d138,void **,20)=p;
 if(!p)return 4;
 M2C_FIELD(&data_0213d138,int *,4)=0;
 func_0200654c((u8 *)M2C_FIELD(&data_0213d138,void **,0)+0x11dc);
 func_02035304();return 0;
}

