/* 32 functions from 0x020216CC to 0x020222D8 (main), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_02138bbc, data_02138b34, data_02138b4c, data_02138b54;

void func_020216cc(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, void *arg4) {
    M2C_UNK func_02020478(M2C_UNK, M2C_UNK, M2C_UNK, u16, s32, s32);
    s32 var_r4;
    u16 temp_r4;
    u16 var_r5;
    u32 temp_r6;
    s32 k = 0;

    if (arg4 == NULL) {
        var_r5 = 0;
        var_r4 = 0;
    } else {
        temp_r4 = M2C_FIELD(arg4, u16 *, 2);
        temp_r6 = M2C_FIELD(arg4, u32 *, 4);
        var_r5 = (u8) ((s32) temp_r4 >> 8) | ((temp_r4 << 8) & 0xFF00);
        var_r4 = ((temp_r6 << 0x18) & 0xFF000000) | (((temp_r6 << 8) & 0xFF0000) | ((u8) (temp_r6 >> 0x18) | ((temp_r6 >> 8) & 0xFF00)));
    }
    if (k) { (void)0; }
    func_02020478(arg0, arg1, arg2, var_r5, var_r4, arg3);
}

void func_02021750(void) {
    M2C_UNK func_02020b18();
    func_02020b18();
}

void func_0202175c(void) {
    M2C_UNK func_02020c28();
    func_02020c28();
}

void *func_02021768(void *p) {
u32 func_02021134(void *);
void func_02007f8c(void *,s32,s32);
void func_02019458(void *,void *,s32);
u32 v=func_02021134(p);
if(!v)return 0;
func_02007f8c(&data_02138bbc,0,0x101);
func_02019458(&data_02138bbc,p,0x101);
M2C_FIELD(&data_02138b34,void **,0x20)=&data_02138bbc;
M2C_FIELD(&data_02138b34,u32 *,0x24)=0;
M2C_FIELD(&data_02138b34,u16 *,0x28)=2;
M2C_FIELD(&data_02138b34,u16 *,0x2a)=4;
M2C_FIELD(&data_02138b34,void **,0x2c)=&data_02138b4c;
M2C_FIELD(&data_02138b34,void **,0x18)=&data_02138b4c - 24;
M2C_FIELD(&data_02138b34,u32 *,0x1c)=0;
M2C_FIELD(&data_02138b34,u32 *,0)=((v << 24) & 0xFF000000) | (((v << 8) & 0xFF0000) | ((u8)(v >> 24) | ((v >> 8) & 0xFF00)));
return &data_02138b54;
}

s32 func_02021828(void *p,void *q) {
u32 func_02021264(void *);
u32 v;u32 t;
if(!p)return -39;
v=func_02021264(p);
t=p?M2C_FIELD(p,u16 *,0x74):0;
t=(u16)(v?t:0);
M2C_FIELD(q,u8 *,0)=8;
M2C_FIELD(q,u8 *,1)=2;
M2C_FIELD(q,u16 *,2)=(u8)((s32)t>>8)|((t<<8)&0xff00);
M2C_FIELD(q,u32 *,4)=((v << 24) & 0xFF000000) | (((v << 8) & 0xFF0000) | ((u8)(v >> 24) | ((v >> 8) & 0xFF00)));
return 0;
}

s32 func_020218bc(void) {
    u32 func_02021264();
    u32 temp_r0;

    temp_r0 = func_02021264();
    return ((temp_r0 << 0x18) & 0xFF000000) | (((temp_r0 << 8) & 0xFF0000) | ((u8) (temp_r0 >> 0x18) | ((temp_r0 >> 8) & 0xFF00)));
}

void func_020218f4(u32 *arg0, u32 *arg1) {
    M2C_UNK func_02021230(s32, s32);
    u32 temp_ip;
    u32 temp_r0;

    temp_ip = *arg1;
    temp_r0 = *arg0;
    func_02021230(((temp_r0 << 0x18) & 0xFF000000) | (((temp_r0 << 8) & 0xFF0000) | ((u8) (temp_r0 >> 0x18) | ((temp_r0 >> 8) & 0xFF00))), ((temp_ip << 0x18) & 0xFF000000) | (((temp_ip << 8) & 0xFF0000) | ((u8) (temp_ip >> 0x18) | ((temp_ip >> 8) & 0xFF00))));
}

void func_02021960(void) {
    M2C_UNK func_0201f758();
    func_0201f758();
}

s32 func_0202196c(M2C_UNK a,void *b){
s32 func_0201f7d8(M2C_UNK,u16 *,u32 *);
u32 v;u16 h;
s32 result=func_0201f7d8(a,&h,&v);
if(result<0)return result;
M2C_FIELD(b,u16 *,2)=((h>>8)&255)|((h<<8)&0xff00);
M2C_FIELD(b,u32 *,4)=((v>>24)&255)|((v>>8)&0xff00)|((v<<8)&0xff0000)|((v<<24)&0xff000000);
return result;
}

s32 func_020219e8(void *arg0, s32 arg1, s32 arg2) {
    s32 var_r0;

    if (arg0 == NULL) {
        return -1;
    }
    switch (arg1) {                                 /* irregular */
    case 3:
        if (M2C_FIELD(arg0, s8 *, 0x72) == 1) {
            var_r0 = 0;
        } else {
            var_r0 = 4;
        }
        return var_r0;
    case 4:
        if (arg2 & 4) {
            M2C_FIELD(arg0, s8 *, 0x72) = 0;
        } else {
            M2C_FIELD(arg0, s8 *, 0x72) = 1;
        }
        /* fallthrough */
    default:
        return 0;
    }
}

s32 *func_02021a38(s32 a){
extern M2C_UNK data_02138b34;
s32 *p; s32 size=a+4;
p=M2C_FIELD(&data_02138b34,s32 *(**)(M2C_UNK,s32),12)(0,size);
if(p){*p=size;p++;}
return p;
}

void func_02021a64(void *arg0) {
    extern M2C_UNK data_02138b34;
    if (arg0 == NULL) {
        return;
    }
    M2C_FIELD(&data_02138b34, M2C_UNK (**)(M2C_UNK, s32, s32), 4)(0, arg0 - 4, M2C_FIELD(arg0, s32 *, -4));
}

/* Copy a (possibly network) configuration record into the shared context and
   initialise its allocator/free callbacks plus the byte-swapped endpoint fields. */
void func_02021a90(void *cfg) {
extern M2C_UNK data_02138b74;
s32 *func_02021a38(s32);
void func_02021a64(void *);
void func_0201ee58(void *);
u32 v;
M2C_FIELD(&data_02138b34,u32 *,0x40)=M2C_FIELD(cfg,u32 *,12)==1;
v=M2C_FIELD(cfg,u32 *,16);M2C_FIELD(&data_02138b34,u32 *,68)=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
v=M2C_FIELD(cfg,u32 *,20);M2C_FIELD(&data_02138b34,u32 *,72)=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
v=M2C_FIELD(cfg,u32 *,24);M2C_FIELD(&data_02138b34,u32 *,76)=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
v=M2C_FIELD(cfg,u32 *,28);M2C_FIELD(&data_02138b34,u32 *,80)=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
v=M2C_FIELD(cfg,u32 *,32);M2C_FIELD(&data_02138b34,u32 *,84)=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
M2C_FIELD(&data_02138b34,s32 *(**)(s32),0x58)=func_02021a38;
M2C_FIELD(&data_02138b34,void (**)(void *),0x5c)=func_02021a64;
M2C_FIELD(&data_02138b34,u32 *,12)=M2C_FIELD(cfg,u32 *,4);
M2C_FIELD(&data_02138b34,u32 *,4)=M2C_FIELD(cfg,u32 *,8);
M2C_FIELD(&data_02138b34,u32 *,0x60)=0x40;
M2C_FIELD(&data_02138b34,u32 *,0x70)=M2C_FIELD(cfg,u32 *,0x2c);
M2C_FIELD(&data_02138b34,u32 *,0x74)=M2C_FIELD(cfg,u32 *,0x30);
func_0201ee58(&data_02138b74);
}

void func_02021c04(void) {
    M2C_UNK func_02020f6c();
    func_02020f6c();
}

M2C_UNK *func_02021c10(s32 a,...){
M2C_UNK func_02021c90(M2C_UNK,void *,void *,M2C_UNK);
extern M2C_UNK data_02138bac;
func_02021c90(2,&a,&data_02138bac,16);
return &data_02138bac;
}

s32 func_02021c40(s32 a,u32 *b){
u32 func_020211e4(s32);u32 v=func_020211e4(a);
if(!v)return 0;
*b=((v<<24)&0xff000000)|(((v<<8)&0xff0000)|((u8)(v>>24)|((v>>8)&0xff00)));
return 1;
}

M2C_UNK func_02021c90(s32 a,void *b,void *c,s32 d){
void func_02008048(void *,void *,u32);void func_02021d14(u32,void *);
void func_0200567c(void *,s32,void *,...);
extern M2C_UNK data_020fafe8;
u32 value;u8 bytes[4];
if(a!=2)return 0;if((u32)d<16)return 0;
func_02008048(b,&value,4);func_02021d14(value,bytes);
func_0200567c(c,16,&data_020fafe8,bytes[3],bytes[2],bytes[1],bytes[0]);return (M2C_UNK)c;
}

void func_02021d14(u32 arg0, void *arg1) {
M2C_FIELD(arg1,u8 *,0)=arg0>>24;
M2C_FIELD(arg1,u8 *,1)=arg0>>16;
M2C_FIELD(arg1,u8 *,2)=arg0>>8;
M2C_FIELD(arg1,u8 *,3)=arg0;
}

s32 func_02021d34(void *a,u32 n,s64 timeout){
s32 func_020212cc(s32);void func_02006030(s32);
s32 limited=timeout!=-1;
void *p;u32 i;s32 count;
for(;;){
count=0;p=a;i=0;
if(n>i) do {
s32 mask=M2C_FIELD(p,s16 *,4)|0xe0;
s32 v=mask&func_020212cc(M2C_FIELD(p,s32 *,0));
M2C_FIELD(p,s16 *,6)=v;if(v)count++;p+=8;i++;
}while(n>i);
if(count>0)break;
if(limited && 0LL>=timeout)break;
func_02006030(1);timeout-=0x20b;
}return count;
}

void func_02021de8(void *p) {
s32 func_0200751c(void); void func_02007530(s32); 
void func_02008048(void *,void *,u32);s32 func_0206527c(void *,void *,s32);
extern M2C_UNK data_02138cc8;
s32 i; s32 old;void *q;old=func_0200751c();i=0;q=&data_02138cc8;
M2C_FIELD(p,u8 *,0x30)=0;
do{
if(M2C_FIELD(q,u8 *,0x5a)&&!M2C_FIELD(q,u32 *,0x54)&&!M2C_FIELD(q,u16 *,0x58)&&!func_0206527c(q,p+0x74,32)){
func_02008048(q+32,p,48);M2C_FIELD(p,u8 *,0x30)=1;break;
}
i++;q+=92;
}while(i<4);
func_02007530(old);
}

void func_02021e7c(void *p,s32 a,s32 b) {
s32 func_0200751c(void); void func_02007530(s32); 
void func_02008048(void *,void *,u32);u64 func_02007004(void);
extern M2C_UNK data_02138cc8;
s32 old=func_0200751c();s32 i=0;void *q=&data_02138cc8;
M2C_FIELD(p,u8 *,0x30)=0;
do{
if(M2C_FIELD(q,u8 *,0x5a)&&M2C_FIELD(q,s32 *,0x54)==a&&M2C_FIELD(q,u16 *,0x58)==b){
func_02008048(q,p+0x74,32);func_02008048(q+32,p,48);
M2C_FIELD(q,u32 *,0x50)=func_02007004()>>16;
M2C_FIELD(p,u8 *,0x30)=1;break;
}
i++;q+=92;
}while(i<4);
func_02007530(old);
}

void func_02021f1c(u8 *arg0, s32 arg1, u16 arg2) {
u64 func_02007004(void); s32 func_0200751c(void); void func_02007530(s32); void func_02008048(void *,void *,u32);
extern M2C_UNK data_02138cc8;
s32 state; u32 now; u8 *best; u32 maxage; s32 i; u8 *p; u32 age; u64 ticks; u8 valid;
state=func_0200751c(); ticks=func_02007004();
best=(u8 *)&data_02138cc8; maxage=0; now=(u32)(ticks>>16);
for(i=0,p=(u8 *)&data_02138cc8;i<4;i++,p+=0x5C){
valid=p[0x5A];
if(valid && arg1 && arg1==M2C_FIELD(p,s32 *,0x54) && arg2 && arg2==M2C_FIELD(p,u16 *,0x58)){best=p;break;}
if(maxage!=~0U){
if(!valid){maxage=~0U;best=p;}
else {age=now-M2C_FIELD(p,u32 *,0x50);if(age>maxage){maxage=age;best=p;}}
}
}
func_02008048(arg0+0x74,best,0x20);
func_02008048(arg0,best+0x20,0x30);
M2C_FIELD(best,u32 *,0x50)=now; best[0x5A]=1; M2C_FIELD(best,s32 *,0x54)=arg1;M2C_FIELD(best,u16 *,0x58)=arg2;
func_02007530(state);
}

void func_02022008(void *p) {
s32 func_0200751c(void);void func_02007530(s32);s32 func_0206527c(void *,void *,s32);
extern M2C_UNK data_02138cc8;
s32 i; s32 old;void *q;old=func_0200751c();q=&data_02138cc8;i=0;
do{
if(M2C_FIELD(q,u8 *,0x5a)&&!func_0206527c(q,p+0x74,32)){M2C_FIELD(q,u8 *,0x5a)=0;break;}
i++;q+=92;
}while(i<4);
func_02007530(old);
}

s32 func_02022070(void){
void func_0200ef4c(void *);void func_0200eff8(void *);s32 func_0200f7e0(void *,void *);
s32 a[4],b[3];
func_0200ef4c(a);func_0200eff8(b);return func_0200f7e0(a,b)+0x386d4380;
}

void func_020220a8(s32 arg0) {
    extern M2C_UNK data_020faffc;
    M2C_FIELD(&data_020faffc, s32 *, 4) = arg0;
}

s32 func_020220b8(void) {
s32 func_02006028(void *); void func_02005f80(s32,u32);
extern M2C_UNK data_020faffc, data_0212dca4;
void *p; s32 x;
if(M2C_FIELD(&data_020faffc,u32 *,4)>=32)return -1;
p=M2C_FIELD(&data_0212dca4,void **,4);
x=func_02006028(p);
func_02005f80((s32)p,M2C_FIELD(&data_020faffc,u32 *,4));
return x;
}

void func_02022104(u32 a){
void func_02005f80(s32,u32);
extern M2C_UNK data_0212dca4;
if(a>=32)return;
func_02005f80(M2C_FIELD(&data_0212dca4,s32 *,4),a);
}

void func_02022128(s32 arg0, s32 arg1) {
    extern M2C_UNK data_0212dca4;
    void *temp_r2;
    void *temp_r2_2;

    temp_r2 = M2C_FIELD(M2C_FIELD(&data_0212dca4, void **, 4), void **, 0xA4);
    if (temp_r2 != NULL) {
        temp_r2_2 = M2C_FIELD(temp_r2, void **, 0xC);
        if (temp_r2_2 != NULL) {
            M2C_FIELD(temp_r2_2, s32 *, 0x814) = arg0;
            M2C_FIELD(temp_r2_2, s32 *, 0x818) = arg1;
        }
    }
}

void *func_02022150(void *p,void *key){
s32 func_02068d98(void *,void *);
s32 i;void **a;s32 n;void *v;
n=M2C_FIELD(p,s32 *,0x818);
i=0;
if(n>0){a=M2C_FIELD(p,void ***,0x814);do{v=a[i];if(!func_02068d98(M2C_FIELD(v,void **,0),key))return v;i++;}while(i<n);}return 0;
}

u32 func_0202219c(u8 **p){
u8 *q=*p;u32 v=*q++;s32 n;
if(v&0x80){n=v&0x7f;v=0;while(n--){if(v&0xff000000)return -1;v=*q+++(v<<8);}}
*p=q;return v;
}

void func_020221ec(s8 *p,s8 *q,s32 n){
s8 *start=p;
if(*p){while(*++p){}if(p-start>=255)return;p[0]=',';p[1]=' ';p+=2;}
while(n-- && p-start<255)*p++=*q++;
*p=0;
}

s32 func_02022258(u8 *p,s32 type){
s32 year;u32 first;u8 b;
b=p[1];first=p[0]*10+b-0x210;p+=2;
if(type==0x17){if(first<50)year=first+2000;else year=first+1900;}
else{b=p[1];year=first*100+(p[0]*10+b-0x210);p+=2;}
return ((p[0]*10+p[1]-0x210)<<8)+(year<<16)+(p[2]*10+p[3]-0x210);
}

