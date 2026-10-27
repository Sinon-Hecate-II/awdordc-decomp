/* 35 functions from 0x0200AE9C to 0x0200BDA4 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 words[3]; } Unk032Record;
typedef struct FileLink { struct FileLink *prev,*next; } FileLink;
static inline void UnlinkFileRequest(FileLink *a) {
FileLink *p=a->prev,*n=a->next;
if(p)p->next=n;if(n)n->prev=p;
}
static inline void MoveFileRequest(FileLink *a, FileLink *head) {
FileLink *n; FileLink *p; p=a->prev;n=a->next;
if(p)p->next=n;if(n)n->prev=p;
{ FileLink *next=head->next;while(next){head=next;next=next->next;} }
head->next=a;a->prev=head;a->next=0;
}
static inline void AppendFileRequest(FileLink *head,FileLink *a) {
FileLink *next=head->next;
while(next){head=next;next=next->next;}
head->next=a;a->prev=head;a->next=0;
}
typedef struct { u32 words[2]; } Unk02BDFileRange;

static inline s32 TestRequestFlag(void *a,s32 mask) { return (M2C_FIELD(a,volatile s32 *,12)&mask)?1:0; }
static inline s32 TestFileFlag(void *a, s32 mask) {
 s32 result;
 if(M2C_FIELD(a,volatile s32 *,0x1c)&mask) result=1;
 else result=0;
 return result;
}

M2C_UNK func_0200ae9c(void *a){s32 func_0200751c(void);M2C_UNK func_02007530(s32);void func_02005df4(void *);s32 func_0200a0ac(void *,s32);s32 func_0200ac88(s32);s32 b=M2C_FIELD(a,s32 *,8),key;if(!a)return;do{key=func_0200751c();M2C_FIELD(a,volatile s32 *,12)|=64;if((M2C_FIELD(a,volatile s32 *,12)&4)?1:0){func_02005df4(a+24);func_02007530(key);return;}M2C_FIELD(a,volatile s32 *,12)|=8;func_02007530(key);if(func_0200a0ac(a,M2C_FIELD(a,s32 *,16))==6)return;a=(void *)func_0200ac88(b);}while(a);}

s32 func_0200af30(void *arg0) {
    M2C_UNK func_0200a050(void *, s32);
    s32 func_0200a0ac(void *, s32);
    s32 func_0200ac88(s32);
    M2C_UNK func_0200ae9c();
    func_0200a050(arg0, func_0200a0ac(arg0, M2C_FIELD(arg0, s32 *, 0x10)));
    if (func_0200ac88(M2C_FIELD(arg0, s32 *, 8)) != 0) {
        func_0200ae9c();
    }
    if (M2C_FIELD(arg0, s32 *, 0x14) == 0) {
        return 1;
    }
    return 0;
}

s32 func_0200af74(void *a,s32 cmd) {
s32 func_0200751c(void); M2C_UNK func_02007530(s32);M2C_UNK func_0200a050(void *,s32);void func_02005da4(void *);
register void *file; register s32 key; register void *request=a; register u32 mask; void *prev,*next,*tail;
file=M2C_FIELD(a,void **,8);mask=1<<cmd;
M2C_FIELD(a,s32 *,16)=cmd;M2C_FIELD(a,s32 *,20)=2;M2C_FIELD(a,volatile s32 *,12)|=1;
key=func_0200751c();
if(M2C_FIELD(file,s32 *,28)&128){func_0200a050(a,3);func_02007530(key);return 0;}
if(mask&0x1fc)M2C_FIELD(a,volatile s32 *,12)|=4;
MoveFileRequest(a,(FileLink *)((u8 *)file+32));
if(!TestFileFlag(file,8)&&!TestFileFlag(file,16)){
M2C_FIELD(file,s32 *,28)|=16;func_02007530(key);
if(M2C_FIELD(file,s32 *,88)&512) M2C_FIELD(file,void (**)(void *,s32),84)(a,9);
{ s32 key2=func_0200751c();M2C_FIELD(a,volatile s32 *,12)|=64;
if(!TestRequestFlag(a,4)){func_02007530(key2);func_0200ae9c(a);return 1;}
func_02007530(key2);}
}else{
if(!TestRequestFlag(a,4)){func_02007530(key);return 1;}
do{func_02005da4((u8 *)a+24);}while(!(M2C_FIELD(a,volatile s32 *,12)&64));
func_02007530(key);
}
return func_0200af30(a);
}

void func_0200b118(void *arg0) {
    M2C_UNK func_02007f8c(void *, M2C_UNK, M2C_UNK);
    func_02007f8c(arg0, 0, 0x5C);
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
}

s32 func_0200b144(s32 a,s32 b){s32 func_0200abdc(s32,s32);s32 func_0200751c(void);M2C_UNK func_02007530(s32);extern M2C_UNK data_0212fbe8;s32 id=func_0200abdc(a,b),key;void *p;key=func_0200751c();p=M2C_FIELD(&data_0212fbe8,void **,0);while(p&&M2C_FIELD(p,s32 *,0)!=id)p=M2C_FIELD(p,void **,4);func_02007530(key);return (s32)p;}

s32 func_0200b184(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    s32 func_0200abdc(M2C_UNK, M2C_UNK);
    s32 func_0200b144(M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0212fbe8;
    s32 temp_r4;
    s32 var_r8;
    void *var_r0;
    void *var_r1;

    var_r8 = 0;
    temp_r4 = func_0200751c();
    if (func_0200b144(arg1, arg2) == 0) {
        var_r1 = M2C_FIELD(&data_0212fbe8, void **, 0);
        if (var_r1 == NULL) {
            M2C_FIELD(&data_0212fbe8, void **, 0) = arg0;
            M2C_FIELD(&data_0212fbe8, void **, 4) = arg0;
            M2C_FIELD(&data_0212fbe8, s32 *, 0xC) = 0;
            M2C_FIELD(&data_0212fbe8, s16 *, 0xA) = 0;
            M2C_FIELD(&data_0212fbe8, s16 *, 8) = 0;
        } else {
            var_r0 = M2C_FIELD(var_r1, void **, 4);
            if (var_r0 != NULL) {
                do {
                    var_r1 = var_r0;
                    var_r0 = M2C_FIELD(var_r0, void **, 4);
                } while (var_r0 != NULL);
            }
            M2C_FIELD(var_r1, void **, 4) = arg0;
            M2C_FIELD(arg0, void **, 8) = var_r1;
        }
        M2C_FIELD(arg0, s32 *, 0) = func_0200abdc(arg1, arg2);
        var_r8 = 1;
        M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) | 1);
    }
    func_02007530(temp_r4);
    return var_r8;
}

void func_0200b238(void *a){s32 func_0200751c(void);M2C_UNK func_02007530(s32);extern M2C_UNK data_0212fbe8;s32 key;void *p;if(!M2C_FIELD(a,s32 *,0))return;key=func_0200751c();p=M2C_FIELD(a,void **,4);if(p)M2C_FIELD(p,void **,8)=M2C_FIELD(a,void **,8);p=M2C_FIELD(a,void **,8);if(p)M2C_FIELD(p,void **,4)=M2C_FIELD(a,void **,4);M2C_FIELD(a,s32 *,0)=0;M2C_FIELD(a,s32 *,8)=0;M2C_FIELD(a,s32 *,4)=0;M2C_FIELD(a,s32 *,28)&=~1;if(M2C_FIELD(&data_0212fbe8,void **,4)==a){M2C_FIELD(&data_0212fbe8,void **,4)=M2C_FIELD(&data_0212fbe8,void **,0);M2C_FIELD(&data_0212fbe8,s32 *,12)=0;M2C_FIELD(&data_0212fbe8,u16 *,10)=0;M2C_FIELD(&data_0212fbe8,u16 *,8)=0;}func_02007530(key);}

s32 func_0200b2bc(void *a,s32 b,s32 c,s32 d,s32 e,s32 f,void *g,void *h) {
 extern M2C_UNK func_0200ac34,func_0200ac50;
 void *x,*y;
 M2C_FIELD(a,s32 *,0x28)=b;
 M2C_FIELD(a,s32 *,0x30)=d;
 M2C_FIELD(a,s32 *,0x2c)=M2C_FIELD(a,s32 *,0x3c)=c;
 M2C_FIELD(a,s32 *,0x38)=f;
 M2C_FIELD(a,s32 *,0x34)=M2C_FIELD(a,s32 *,0x40)=e;
 x=g;if(!x)x=&func_0200ac34;
 M2C_FIELD(a,void **,0x48)=x;
 y=h;if(!y)y=&func_0200ac50;
 M2C_FIELD(a,void **,0x4c)=y;
 M2C_FIELD(a,void **,0x50)=M2C_FIELD(a,void **,0x48);
 M2C_FIELD(a,s32 *,0x44)=0;
 M2C_FIELD(a,s32 *,0x1c)|=2;
 return 1;
}

s32 func_0200b32c(void *a) {
 s32 func_0200751c(void);
 s32 func_02007530(s32);
 s32 func_0200b59c(void *);
 M2C_UNK func_0200b638(void *);
 s32 func_0200a050(void *,s32);
 s32 irq;void *p; s32 flag;void *next; s32 r;
 irq=func_0200751c();
 if(M2C_FIELD(a,s32 *,0x1c)&2)flag=1;else flag=0;
 if(flag!=0){
 r=func_0200b59c(a);
 M2C_FIELD(a,s32 *,0x1c)|=128;
 p=M2C_FIELD(a,void **,0x24);
 while(p){next=M2C_FIELD(p,void **,4);func_0200a050(p,3);p=next;}
 M2C_FIELD(a,void **,0x24)=0;
 if(r)func_0200b638(a);
 M2C_FIELD(a,s32 *,0x28)=0;M2C_FIELD(a,s32 *,0x2c)=0;
 M2C_FIELD(a,s32 *,0x30)=0;M2C_FIELD(a,s32 *,0x34)=0;
 M2C_FIELD(a,s32 *,0x38)=0;M2C_FIELD(a,s32 *,0x40)=0;M2C_FIELD(a,s32 *,0x3c)=0;
 M2C_FIELD(a,s32 *,0x1c)&=~0xa2;
 }
 func_02007530(irq);return 1;
}

u32 func_0200b3ec(void *a,u32 memory,u32 size){
extern M2C_UNK func_0200ac70;
void func_0200b774(void *);
s32 func_0200b99c(void *,s32,s32,s32,s32);
s32 func_0200bbe0(s32,s32,s32);
s32 func_0200ba9c(void *);
M2C_UNK func_02007f8c(void *,M2C_UNK,M2C_UNK);
u8 file[0x48];u32 required,p;
required=(M2C_FIELD(a,u32 *,0x30)+M2C_FIELD(a,u32 *,0x38)+63)&~31;
if(required<=size){
p=(memory+31)&~31;
func_0200b774(file);
if(func_0200b99c(file,(s32)a,M2C_FIELD(a,s32 *,0x2c),M2C_FIELD(a,s32 *,0x2c)+M2C_FIELD(a,s32 *,0x30),-1)){
if(func_0200bbe0((s32)file,p,M2C_FIELD(a,s32 *,0x30))<0)func_02007f8c((void*)p,0,M2C_FIELD(a,s32 *,0x30));
func_0200ba9c(file);
}
M2C_FIELD(a,u32 *,0x2c)=p;
p+=M2C_FIELD(a,u32 *,0x30);
if(func_0200b99c(file,(s32)a,M2C_FIELD(a,s32 *,0x34),M2C_FIELD(a,s32 *,0x34)+M2C_FIELD(a,s32 *,0x38),-1)){
if(func_0200bbe0((s32)file,p,M2C_FIELD(a,s32 *,0x38))<0)func_02007f8c((void*)p,0,M2C_FIELD(a,s32 *,0x38));
func_0200ba9c(file);
}
M2C_FIELD(a,u32 *,0x34)=p;
M2C_FIELD(a,u32 *,0x44)=memory;
M2C_FIELD(a,void **,0x50)=&func_0200ac70;
M2C_FIELD(a,u32 *,0x1c)|=4;
}
return required;
}

s32 func_0200b510(void *a) {
 s32 func_0200b59c();
 s32 func_0200b638(void *);
 s32 r,flag,out=0;
 flag=TestFileFlag(a,2);
 if(flag!=0){
 r=func_0200b59c(a);
 flag=TestFileFlag(a,4);
 if(flag!=0){
 M2C_FIELD(a,s32 *,0x1c)&=~4;
 out=M2C_FIELD(a,s32 *,0x44);M2C_FIELD(a,s32 *,0x44)=0;
 M2C_FIELD(a,s32 *,0x2c)=M2C_FIELD(a,s32 *,0x3c);
 M2C_FIELD(a,s32 *,0x34)=M2C_FIELD(a,s32 *,0x40);
 M2C_FIELD(a,s32 *,0x50)=M2C_FIELD(a,s32 *,0x48);
 }
 if(r)func_0200b638(a);
 }
 return out;
}

s32 func_0200b59c(void *a){void func_02005da4(void *);s32 func_0200751c(void);M2C_UNK func_02007530(s32);s32 t,v,key=func_0200751c();s32 r=((M2C_FIELD(a,volatile s32 *,28)&8)?1:0)==0;if(r){t=(M2C_FIELD(a,volatile s32 *,28)&16)?1:0;v=M2C_FIELD(a,volatile s32 *,28);if(t){M2C_FIELD(a,volatile s32 *,28)=v|64;do{func_02005da4(a+20);}while((M2C_FIELD(a,volatile s32 *,28)&64)?1:0);}else M2C_FIELD(a,volatile s32 *,28)=v|8;}func_02007530(key);return r;}

s32 func_0200b638(void *a){s32 func_0200751c(void);M2C_UNK func_02007530(s32);s32 p=0,key,r;key=func_0200751c();r=((M2C_FIELD(a,s32 *,28)&8)?1:0)==0;if(!r){M2C_FIELD(a,s32 *,28)&=~8;p=func_0200ac88((s32)a);}func_02007530(key);if(p)func_0200ae9c((void *)p);return r;}

void func_0200b6a8(void *arg0, s32 arg1, s32 arg2) {
    s32 var_r1;
    s32 var_r2;

    var_r1 = arg1;
    var_r2 = arg2;
    if (var_r2 == 0) {
        var_r1 = 0;
    } else if (var_r1 == 0) {
        var_r2 = 0;
    }
    M2C_FIELD(arg0, s32 *, 0x54) = var_r1;
    M2C_FIELD(arg0, s32 *, 0x58) = var_r2;
}

M2C_UNK func_0200b6c8(M2C_UNK a,M2C_UNK b){M2C_UNK func_0200a050(void *,s32);s32 func_0200751c(void);M2C_UNK func_02007530(s32);void func_02005df4(void *);s32 key,p;if((M2C_FIELD(a,volatile s32 *,28)&256)?1:0){key=M2C_FIELD(a,volatile s32 *,28);p=M2C_FIELD(a,s32 *,36);M2C_FIELD(a,volatile s32 *,28)=key&~256;func_0200a050((void *)p,b);p=func_0200ac88(a);if(p)func_0200ae9c((void *)p);return;}p=M2C_FIELD(a,s32 *,36);key=func_0200751c();M2C_FIELD(p,s32 *,20)=b;M2C_FIELD(a,volatile s32 *,28)&=~512;func_02005df4((void *)(a+12));func_02007530(key);}

void func_0200b74c(s32 a){void func_0200bda4(s32);extern s32 data_0212fbf8;if(data_0212fbf8)return;data_0212fbf8=1;func_0200bda4(a);}

void func_0200b774(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0xE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
}

s32 func_0200b79c(void *a,s32 b,s32 c,s32 d) {
extern Unk032Record data_0212fbec;
s32 func_0200af74(void *,s32);
u8 *path=(u8 *)b;Unk032Record rec; s32 i,flag;void *p;
if(*path==47||*path==92){
M2C_FIELD(&rec,u16 *,4)=0;
rec.words[0]=data_0212fbec.words[0];rec.words[2]=0;M2C_FIELD(&rec,u16 *,6)=0;path++;
}else{
rec=data_0212fbec;
for(i=0;i<=3;i++){
u8 ch=path[i];
if(ch==0||ch==47||ch==92)break;
if(ch==58){
p=(void *)func_0200b144((s32)path,i);if(!p)return 0;
flag=TestFileFlag(p,2);if(flag==0)return 0;
rec.words[0]=(u32)p;rec.words[2]=0;M2C_FIELD(&rec,u16 *,6)=0;M2C_FIELD(&rec,u16 *,4)=0;
path+=i+1;if(*path==47||*path==92)path++;break;
}
}
}
M2C_FIELD(a,u32 *,8)=rec.words[0];M2C_FIELD(a,u8 **,0x3c)=path;
M2C_FIELD(a,Unk032Record *,0x30)=rec;
if(d!=0){M2C_FIELD(a,s32 *,0x40)=1;M2C_FIELD(a,s32 *,0x44)=d;}
else{M2C_FIELD(a,s32 *,0x40)=0;M2C_FIELD(a,s32 *,0x44)=c;}
return func_0200af74(a,4);
}

M2C_UNK func_0200b8e0(M2C_UNK a,M2C_UNK b,M2C_UNK c,M2C_UNK d){s32 func_0200bad8(void *);s32 old=M2C_FIELD(a,s32 *,44),n=c,limit=M2C_FIELD(a,s32 *,40)-old;M2C_FIELD(a,s32 *,48)=b;if(n>limit)n=limit;if(n<0)n=0;M2C_FIELD(a,s32 *,52)=c;M2C_FIELD(a,s32 *,56)=n;if(!d)M2C_FIELD(a,s32 *,12)|=4;func_0200af74((void *)a,0);if(!d){if(func_0200bad8((void *)a))n=M2C_FIELD(a,s32 *,44)-old;else n=-1;}return n;}

s32 func_0200b95c(s32 a,s32 b) {
 s32 func_0200b79c(void *,s32,s32,s32);
 u8 v[0x48];
 func_0200b774(v);
 return func_0200b79c(v,b,a,0)!=0;
}

s32 func_0200b99c(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_FIELD(arg0, s32 *, 8) = arg1;
    M2C_FIELD(arg0, s32 *, 0x38) = arg4;
    M2C_FIELD(arg0, s32 *, 0x30) = arg2;
    M2C_FIELD(arg0, s32 *, 0x34) = arg3;
    if (func_0200af74(arg0, 7) == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) ((M2C_FIELD(arg0, s32 *, 0xC) | 0x10) & ~0x20);
    return 1;
}

s32 func_0200b9e4(s32 a,Unk02BDFileRange b){if(!b.words[0])return 0;M2C_FIELD(a,u32 *,8)=b.words[0];M2C_FIELD(a,u32 *,48)=b.words[0];M2C_FIELD(a,u32 *,52)=M2C_FIELD(&b,volatile u32 *,4);if(!func_0200af74((void *)a,6))return 0;M2C_FIELD(a,s32 *,12)=(M2C_FIELD(a,s32 *,12)|16)&~32;return 1;}

s32 func_0200ba54(s32 a){s32 func_0200b9e4(s32,Unk02BDFileRange);Unk02BDFileRange v;if(((s32 (*)(void *))func_0200b95c)(&v)&&func_0200b9e4(a,v))return 1;return 0;}

s32 func_0200ba9c(void *arg0) {
    s32 func_0200af74(void *, M2C_UNK);
    if (func_0200af74(arg0, 8) == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0xE;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (M2C_FIELD(arg0, s32 *, 0xC) & ~0x30);
    return 1;
}

s32 func_0200bad8(void *a){void func_02005da4(void *);s32 r=0,key=func_0200751c();if((M2C_FIELD(a,volatile s32 *,12)&1)?1:0){r=!(M2C_FIELD(a,volatile s32 *,12)&0x44);if(r){M2C_FIELD(a,volatile s32 *,12)|=4;do{func_02005da4(a+24);}while(!(M2C_FIELD(a,volatile s32 *,12)&64));}else{do{func_02005da4(a+24);}while((M2C_FIELD(a,volatile s32 *,12)&1)?1:0);}}func_02007530(key);if(r)return func_0200af30(a);return M2C_FIELD(a,s32 *,20)==0;}

void func_0200bb98(void *a){s32 key=func_0200751c();void *p;if((M2C_FIELD(a,volatile s32 *,12)&1)?1:0){M2C_FIELD(a,volatile s32 *,12)|=2;p=M2C_FIELD(a,void **,8);M2C_FIELD(p,s32 *,28)|=32;}func_02007530(key);}

s32 func_0200bbe0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_0200b8e0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    return func_0200b8e0(arg0, arg1, arg2, 0);
}

s32 func_0200bbf0(void *a,s32 b,s32 c){s32 v;switch(c){case 0:b+=M2C_FIELD(a,volatile s32 *,36);break;case 1:b+=M2C_FIELD(a,volatile s32 *,44);break;case 2:b+=M2C_FIELD(a,volatile s32 *,40);break;default:return 0;}v=M2C_FIELD(a,volatile s32 *,36);if(b<v)b=v;v=M2C_FIELD(a,volatile s32 *,40);if(b>v)b=v;M2C_FIELD(a,s32 *,44)=b;return 1;}

s32 func_0200bc5c(s32 a){u8 buf[72];Unk032Record v;extern Unk032Record data_0212fbec;func_0200b774(buf);if(!func_0200b79c(buf,a,0,(s32)&v))return 0;data_0212fbec=v;return 1;}

void func_0200bcb4(M2C_UNK arg0) {
    M2C_UNK func_0200b6c8(M2C_UNK, M2C_UNK);
    s32 func_02010ee8();
    M2C_UNK var_r1;

    if (func_02010ee8() != 0) {
        var_r1 = 5;
    } else {
        var_r1 = 0;
    }
    func_0200b6c8(arg0, var_r1);
}

s32 func_0200bcd8(s32 a,s32 b,s32 c,s32 d){void func_02010b1c(s32,s32,s32,s32,s32,void *,s32);extern M2C_UNK data_0212fbfc;func_02010b1c(M2C_FIELD(&data_0212fbfc,s32 *,4),c,b,d,(s32)func_0200bcb4,(void *)a,1);return 6;}

s32 func_0200bd20(void) {
    return 1;
}

s32 func_0200bd28(s32 a,s32 b){void func_0200fe24(u16);void func_0200fe40(u16);extern s32 data_0212fbfc;switch(b){case 9:func_0200fe24((u16)data_0212fbfc);return 0;case 10:func_0200fe40((u16)data_0212fbfc);return 0;case 1:return 4;default:return 8;}}

s32 func_0200bd94(void) {
    return 1;
}

s32 func_0200bd9c(void) {
    return 4;
}

