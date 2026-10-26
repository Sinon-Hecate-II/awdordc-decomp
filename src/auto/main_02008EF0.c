/* 44 functions from 0x02008EF0 to 0x02009EB0 (main), found by ds-decomp. */
#include "common.h"
typedef struct Shared09d40 { u8 pad[0x388]; u32 value; } Shared09d40;
extern u16 data_0212fb64;
extern s32 data_0212fb68[32];
void func_02009f38(void);
void func_0200902c(void);
void func_0200962c(void);
void *func_02009210(int);
void func_020092d0(int);
void func_02009854(void *);
typedef struct Link09a0c { void *owner; struct Link09a0c *next; } Link09a0c;

void func_0200973c(void);
typedef struct QueueNode09298 { struct QueueNode09298 *next; } QueueNode09298;
typedef struct Queue09298 { s32 unk0, unk4; QueueNode09298 *head, *tail; } Queue09298;

void func_02008ef0(M2C_UNK arg0) {
    M2C_UNK func_02008f88(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02008f88(0x17, arg0, 0, 0, 0);
}

void func_02008f10(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    func_02008f88(0x19, arg0, arg1, arg2, arg3);
}

void func_02008f38(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    func_02008f88(6, arg0, arg1, arg2, arg3);
}

void func_02008f60(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4) {
    func_02008f88(7, arg0 | (arg4 << 0x18), arg1, arg2, arg3);
}

s32 func_02008f88(int a,int b,int c,int d,int e){void *func_02009210(int);void *p=func_02009210(1);if(!p)return (s32)p;M2C_FIELD(p,s32 *,4)=a;M2C_FIELD(p,s32 *,8)=b;M2C_FIELD(p,s32 *,12)=c;M2C_FIELD(p,s32 *,16)=d;M2C_FIELD(p,s32 *,20)=e;return func_02009298(p);}

void func_02008fcc(void){extern s32 data_0212e000;extern M2C_UNK data_0212e004;if(data_0212e000)return;data_0212e000=1;func_0200654c(&data_0212e004);func_0200902c();func_0200973c();}

void func_02009004(void) {
    M2C_UNK func_02006564(M2C_UNK *);
    extern M2C_UNK data_0212e004;
    func_02006564(&data_0212e004);
}

void func_02009018(void){M2C_UNK func_020065e8(M2C_UNK *);extern M2C_UNK data_0212e004;func_020065e8(&data_0212e004);}

#pragma opt_strength_reduction off
#pragma peephole off
void func_0200902c(void){
extern u8 data_0212e300[];
extern M2C_UNK data_0212e020,data_0212f020,data_0212fae8,data_0212e080;
extern s32 *data_0212fb60;
int i;void *p;
func_0200962c();
M2C_FIELD(&data_0212e020,void **,0)=&data_0212e300;
for(i=0;i<255;i++)M2C_FIELD(&data_0212e300,void **,i*24)=(char *)&data_0212e300+(i+1)*24;
M2C_FIELD(&data_0212f020,int *,0xac8)=0;
M2C_FIELD(&data_0212e020,void **,16)=&data_0212fae8;
M2C_FIELD(&data_0212e020,int *,8)=0;
M2C_FIELD(&data_0212e020,int *,12)=0;
M2C_FIELD(&data_0212e020,int *,28)=0;
M2C_FIELD(&data_0212e020,int *,20)=0;
M2C_FIELD(&data_0212e020,int *,24)=0;
M2C_FIELD(&data_0212e020,int *,32)=1;
M2C_FIELD(&data_0212e020,int *,4)=0;
data_0212fb60=(s32 *)&data_0212e080;
func_02009854((void *)data_0212fb60);
p=func_02009210(1);
if(!p)return;
M2C_FIELD(p,int *,4)=29;
M2C_FIELD(p,s32 **,8)=data_0212fb60;
func_02009298(p);func_020092d0(1);
}
#pragma peephole reset
#pragma opt_strength_reduction reset
void *func_02009210(int flags){
void func_0200968c(void);
void func_020092d0(int);
s32 func_020096fc(void);
void *func_020096b4(void);
s32 func_02009100(int);
void *p;
if(!func_020096fc())return 0;
p=func_020096b4();
if(p)return p;
if(!(flags&1))return 0;
if(func_020095ec()>0){
while(func_02009100(0)!=0){
}
p=func_020096b4();
if(p)return p;
}
else{
func_020092d0(1);
}
func_0200968c();
do{
func_02009100(1);
p=func_020096b4();
}
while(!p);
return p;
}


s32 func_02009298(QueueNode09298 *arg0) {
s32 func_0200751c(void);extern M2C_UNK data_0212e020;
s32 s=func_0200751c(); Queue09298 *p=(Queue09298 *)&data_0212e020;
QueueNode09298 *tail=p->tail;
if(!tail){p->head=arg0;p->tail=arg0;}else {tail->next=arg0;p->tail=arg0;}
arg0->next=0;return func_02007530(s);
}

void func_0200948c(int a) {
void func_0200968c(void);
if(func_02009524(a))return;
while(func_02009100(0)){}
if(func_02009524(a))return;
func_0200968c();
if(func_02009524(a))return;
do {func_02009100(1);}while(!func_02009524(a));
}

s32 func_020094f8(void) {
s32 func_0200751c(void);extern M2C_UNK data_0212e020;
s32 s=func_0200751c();s32 r;
if(M2C_FIELD(&data_0212e020,s32 *,8)==0)r=M2C_FIELD(&data_0212e020,s32 *,4);else r=M2C_FIELD(&data_0212e020,s32 *,32);
func_02007530(s);return r;
}

s32 func_02009524(u32 a){s32 func_0200751c(void);s32 func_02007530(s32);extern M2C_UNK data_0212e020;s32 state=func_0200751c();s32 r;u32 v=M2C_FIELD(&data_0212e020,u32 *,4);if(a>v){if(a-v<0x80000000U)r=0;else r=1;}else{if(v-a<0x80000000U)r=1;else r=0;}func_02007530(state);return r;}

s32 func_02009574(void){s32 func_0200751c(void);s32 func_02007530(s32);extern M2C_UNK data_0212e020;s32 state=func_0200751c();s32 count=0;void *p=M2C_FIELD(&data_0212e020,void **,0);if(p){do{p=*(void **)p;count++;}while(p);}func_02007530(state);return count;}

s32 func_020095b0(void){s32 func_0200751c(void);s32 func_02007530(s32);extern M2C_UNK data_0212e020;s32 state=func_0200751c();s32 count=0;void *p=M2C_FIELD(&data_0212e020,void **,8);if(p){do{p=*(void **)p;count++;}while(p);}func_02007530(state);return count;}

s32 func_020095ec(void) {
    s32 func_02009574();
    s32 func_020095b0();
    s32 temp_r4;

    temp_r4 = func_02009574();
    return (0x100 - temp_r4) - func_020095b0();
}

void func_02009608(int unused,int arg1) {
s32 func_0200751c(void);s32 s=func_0200751c();func_020097bc(arg1);func_02007530(s);
}

void func_0200962c(void){M2C_UNK func_0200758c(M2C_UNK);s32 func_020096fc();M2C_UNK func_02009e40(M2C_UNK,M2C_UNK *);s32 func_02009e8c(M2C_UNK,M2C_UNK);extern void func_02009608(int,int);func_02009e40(7,(M2C_UNK *)&func_02009608);if(!func_020096fc())return;if(func_02009e8c(7,1))return;do{func_0200758c(100);}while(!func_02009e8c(7,1));}

void func_0200968c(void) {
    s32 func_02009eb0(M2C_UNK, M2C_UNK, M2C_UNK);
    do {

    } while (func_02009eb0(7, 0, 0) < 0);
}

void *func_020096b4(void){s32 func_0200751c(void);s32 func_02007530(s32);extern M2C_UNK data_0212e020;s32 state=func_0200751c();void *p=M2C_FIELD(&data_0212e020,void **,0);void *next;if(!p){func_02007530(state);return 0;}next=*(void **)p;M2C_FIELD(&data_0212e020,void **,0)=next;if(!next)M2C_FIELD(&data_0212e020,s32 *,16)=0;func_02007530(state);return p;}

s32 func_020096fc(void){s32 func_020062b4(void);s32 func_0200751c(void);s32 func_02007530(s32);s32 state,v,result;if(!func_020062b4())return 1;state=func_0200751c();*(volatile s32 *)0x04fff200=16;v=*(volatile s32 *)0x04fff200;func_02007530(state);if(v)result=1;else result=0;return result;}

void func_0200973c(void){extern M2C_UNK data_0212fb00;int i=0;u8 *p=(u8 *)&data_0212fb00;int zero=i;do{*(s32 *)p=zero;*(s32 *)(p+4)=zero;i++;p[8]=zero;p+=12;}while(i<8);}

void func_0200976c(s32 arg0) {
    extern M2C_UNK data_0212fb00;
    s32 temp_r1;

    temp_r1 = (arg0 * 0xC) + (s32) &data_0212fb00;
    M2C_FIELD(temp_r1, u8 *, 8) = (u8) (M2C_FIELD(temp_r1, u8 *, 8) + 1);
}

u8 func_0200978c(int a,int b,int c){extern M2C_UNK data_0212fb00;void *p=(char *)&data_0212fb00+a*12;M2C_FIELD(p,int *,0)=b;M2C_FIELD(p,int *,4)=c;return ++M2C_FIELD(p,u8 *,8);}

s32 func_020097bc(s32 a){
extern M2C_UNK data_0212fb00;void *p=(char *)&data_0212fb00+(a&255)*12;
u8 generation=a>>8;
if(M2C_FIELD(p,u8 *,8)!=generation)return;
if(M2C_FIELD(p,void (**)(int),0))M2C_FIELD(p,void (**)(int),0)(M2C_FIELD(p,int *,4));
}

s32 func_02009800(void){M2C_UNK func_020067a8(s32 *,M2C_UNK);extern s32 *data_0212fb60;func_020067a8(data_0212fb60+1,4);return data_0212fb60[1];}

s32 func_0200982c(void) {
    M2C_UNK func_020067a8(s32 *, M2C_UNK);
    extern s32 *data_0212fb60;
    func_020067a8(data_0212fb60, 4);
    return *data_0212fb60;
}

void func_02009854(void *a){
int i,j;void *p=a;
M2C_FIELD(a,int *,4)=0;M2C_FIELD(a,s16 *,8)=0;M2C_FIELD(a,s16 *,10)=0;M2C_FIELD(a,int *,0)=0;
for(i=0;i<16;i++,p=(char *)p+36){M2C_FIELD(p,int *,64)=0;for(j=0;j<16;j++)((s16 *)p+j)[16]=-1;}
for(j=0;j<16;j++)((s16 *)a+j)[304]=-1;
func_020067e0(a,640);
}

u16 func_020098d0(s32 a){
extern u8 data_020ea3a0[];int n;u8 v;
if(a < -723)a=-723;else if(a>0)a=0;
v=data_020ea3a0[a+723];
if(a < -240)n=3;else if(a < -120)n=2;else if(a < -60)n=1;else n=0;
return v|(n<<8);
}

void func_02009940(void *a,int i,void *b){
Link09a0c *entry,*p,*next;void *owner;
func_02009004();
owner=((Link09a0c *)a+i)[3].owner;
if(owner){
if(b==owner){func_02009018();return;}
entry=(Link09a0c *)((char *)a+24)+i;
p=M2C_FIELD(owner,Link09a0c **,24);
if(entry==p){M2C_FIELD(owner,Link09a0c **,24)=((Link09a0c *)a+i)[3].next;func_020067c4(((Link09a0c *)a+i)[3].owner,60);}
else{
if(p){do{next=p->next;if(entry==next)break;p=next;}while(next);}
p->next=((Link09a0c *)a+i)[3].next;func_020067c4(p,8);
}
}
p=M2C_FIELD(b,Link09a0c **,24);
M2C_FIELD(b,Link09a0c **,24)=(Link09a0c *)((char *)a+24)+i;
((Link09a0c *)a+i)[3].next=p;
((Link09a0c *)a+i)[3].owner=b;
func_02009018();func_020067c4(a,60);func_020067c4(b,60);
}

void func_02009a0c(void *a){
int i;Link09a0c *entry,*p,*next;void *owner;
func_02009004();
entry=(Link09a0c *)((char *)a+24);
for(i=0;i<4;i++,entry++){
owner=((Link09a0c *)a+i)[3].owner;
if(owner){
p=M2C_FIELD(owner,Link09a0c **,24);
if(entry==p){M2C_FIELD(owner,Link09a0c **,24)=((Link09a0c *)a+i)[3].next;func_020067c4(owner,60);}
else {
if(p){do {next=p->next;if(entry==next)break;p=next;}while(next);}
p->next=((Link09a0c *)a+i)[3].next;func_020067c4(p,8);
}
}
}
func_02009018();
}

void func_02009aa4(void *arg0) {
    void *temp_r6;
    void *var_r0;

    func_02009004();
    var_r0 = M2C_FIELD(arg0, void **, 0x18);
    if (var_r0 != NULL) {
        do {
            temp_r6 = M2C_FIELD(var_r0, void **, 4);
            M2C_FIELD(var_r0, s32 *, 0) = 0;
            M2C_FIELD(var_r0, void **, 4) = NULL;
            func_020067c4(var_r0, 8);
            var_r0 = temp_r6;
        } while (temp_r6 != NULL);
    }
    func_02009018();
}

void func_02009aec(u32 *a){volatile u32 zero[2];a[0]=0;zero[0]=0;zero[1]=0;a[1]=0;}

s32 func_02009cbc(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x38);
}

void func_02009cc4(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_020067c4(s32, M2C_UNK);
    func_02009004();
    M2C_FIELD((arg0 + (arg1 * 4)), s32 *, 0x3C) = arg2;
    func_020067c4(arg0 + 0x3C + (arg1 * 4), 4);
    func_02009018();
}

void *func_02009cf8(char *a,s32 b){
void *v;func_02009004();v=M2C_FIELD(a+b*4,void **,60);
if(v){if((u32)v<0x2000000U)v=a+(u32)v;}else v=0;
func_02009018();return v;
}

void func_02009d34(void) {
    M2C_UNK func_02009d40();
    func_02009d40();
}

s32 func_02009d40(void){
s32 func_0200751c(void);s32 state=func_0200751c();int i,stable;
if(!data_0212fb64){
data_0212fb64=1;
*(volatile u32 *)0x027fff88=0;
for(i=0;i<32;i++)data_0212fb68[i]=0;
*(volatile u16 *)0x04000184=0xc408;
func_02005228(0x40000);func_02004ff8(0x40000,func_02009f38);func_020051c8(0x40000);
stable=0;
for(;;){int value=*(volatile u16 *)0x04000180&15;int timeout;
*(volatile u16 *)0x04000180=value<<8;
if(!value&&stable>4)break;
timeout=1000;
while((*(volatile u16 *)0x04000180&15)==value){
if(timeout<=0){stable=0;break;}timeout--;
}
stable++;
}
}
return func_02007530(state);
}

s32 func_02009e40(s32 a,M2C_UNK *b){
s32 func_0200751c(void);extern s32 data_0212fb68[];
s32 s=func_0200751c();s32 *base=(s32 *)0x027ffc00;
data_0212fb68[a]=(s32)b;
if(b)base[226]|=1<<a;
else base[226]&=~(1<<a);
return func_02007530(s);
}

s32 func_02009e8c(s32 a,s32 b){u32 *base=(u32 *)0x027ffc00;s32 r=1;if(!(base[b+0xe2]&(1<<a)))r=0;return r;}

