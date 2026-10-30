/* 42 functions from 0x0205ABB4 to 0x0205BB90 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 offset,size,command;u16 sequence; } Command5B8B0;

s32 func_0205abb4(M2C_UNK arg0, M2C_UNK arg1) {
    s32 func_0205aa34();
    s32 func_0205aad8(M2C_UNK, M2C_UNK);
    s32 func_0205ab44(M2C_UNK, M2C_UNK);
    s32 func_0205ab80(M2C_UNK, M2C_UNK);
    if (func_0205aa34() == 0) {
        return 0;
    }
    if (func_0205ab80(arg0, arg1) == 0) {
        return 0;
    }
    if (func_0205aad8(arg0, arg1) == 0) {
        return 0;
    }
    if (func_0205ab44(arg0, arg1) != 0) {
        return 1;
    }
    return 0;
}

M2C_UNK func_0205ac1c(s32 a,s32 b) {
void func_0205ac6c(void *,...);M2C_UNK func_0205cb4c();s32 func_0205a29c(s32,s32);void func_0205d164(s32);void func_0205c8c8(s32);
if(b){
if(M2C_FIELD(a,s32 *,12)>=7)return;
func_0205ac6c((void *)a);func_0205cb4c(a);func_0205a29c(a,0);func_0205d164(a);
}else {M2C_FIELD(a,s32 *,12)=6;func_0205c8c8(a);}
}

void func_0205ac6c(void *p,...) {
void func_02048f54(s32,void **);void func_020486f8(s32,void **);
if(M2C_FIELD(p,s32 *,12)==7)return;
M2C_FIELD(p,s32 *,12)=7;
func_02048f54(M2C_FIELD(M2C_FIELD(p,void **,8),s32 *,12),&p);
func_020486f8(M2C_FIELD(M2C_FIELD(p,void **,8),s32 *,16),&p);
}

void func_0205acc8(void *p) {
void func_020377c4(void *);void func_0204861c(void *);void *q;
q=M2C_FIELD(p,void **,56);if(q)func_020377c4(q);
q=M2C_FIELD(p,void **,68);if(q)func_020377c4(q);
q=M2C_FIELD(p,void **,80);if(q)func_020377c4(q);
q=M2C_FIELD(p,void **,92);if(q)func_0204861c(q);
q=M2C_FIELD(p,void **,96);if(q)func_0204861c(q);
q=M2C_FIELD(p,void **,152);if(q)func_0204861c(q);
q=M2C_FIELD(p,void **,156);if(q)func_0204861c(q);
func_020377c4(p);
}

void func_0205ad4c(s32 a,s32 b,s32 c,s32 d,s32 e) {
void func_0205ccd8(s32,s32,s32,s32,s32);
func_0205ccd8(a,b,c,d,e);
}

void func_0205ad60(M2C_UNK arg0) {
    void func_0205afec();
    M2C_UNK func_0205cef8(M2C_UNK);
    func_0205afec();
    func_0205cef8(arg0);
}

void func_0205ad78(M2C_UNK arg0) {
    s32 func_0205c344();
    s32 func_0205d428(M2C_UNK);
    M2C_UNK func_0205d464(M2C_UNK);
    if (func_0205c344() == 0) {
        return;
    }
    if (func_0205d428(arg0) == 0) {
        return;
    }
    func_0205d464(arg0);
}

void func_0205ada8(void) {
    M2C_UNK func_0205cf3c();
    func_0205cf3c();
}

void func_0205adb4(void) {
    M2C_UNK func_0205a938();
    func_0205a938();
}

void func_0205adc0(void) {
    M2C_UNK func_0205a994();
    func_0205a994();
}

s32 func_0205adcc(s32 a,void **b,s32 c,s32 d,s32 e,s32 f,s32 g,s32 h){
void func_02049260(s32);s32 func_0205a830(s32,void **);s32 func_0205a890(void *,s32,s32,s32);void func_0205d164(s32);s32 func_0205d588(s32,u32 *,u16 *);
void *p;u32 ip;u16 port;s32 result,done;
if(!func_0205d588(c,&ip,&port)||!ip||!port)return 4;
if(((((ip<<24)&0xff000000)|(((ip<<8)&0xff0000)|((u8)(ip>>24)|((ip>>8)&0xff00))))&0xe0000000)==0xe0000000)return 4;
result=func_0205a830(a,&p);if(result)return result;
M2C_FIELD(p,s32 *,32)=f;
result=func_0205a890(p,d,e,g);if(result){func_0205d164((s32)p);return result;}
if(!h){if(b)*b=p;return 0;}
M2C_FIELD(p,s32 *,36)++;
do{func_0205ad78(a);if(M2C_FIELD(p,s32 *,12)>=5)done=1;else done=0;if(!done)func_02049260(1);}while(!done);
M2C_FIELD(p,s32 *,36)--;
if(M2C_FIELD(p,s32 *,12)==5)*b=p;
return M2C_FIELD(p,s32 *,24);
}

void func_0205af48(void *a,s32 b,s32 c,s32 d) {
s32 func_02048688(s32);
void func_0205d70c(s32 *,s32 *);
void func_0205a424(void *,s32,s32,s32,s32);
void func_0205cc20(void *,s32,s32,s32);
if(M2C_FIELD(a,s32 *,12)!=5)return;
func_0205d70c(&b,&c);
if(func_02048688(M2C_FIELD(a,s32 *,0x98))) {func_0205a424(a,0,b,c,d);return;}
func_0205cc20(a,b,c,d);
}

void func_0205afcc(M2C_UNK arg0) {
    M2C_UNK func_0205ac1c(M2C_UNK, M2C_UNK);
    func_0205ac1c(arg0, 1);
}

void func_0205afdc(s32 *arg0) {
    func_0205afcc(*arg0);
}

void func_0205afec(void *a) {
extern s32 data_0213e110;
void func_02049098(s32,void (*)(s32 *),s32);
void func_0205afdc(s32 *);
if(data_0213e110==1)return;
data_0213e110=1;
func_02049098(M2C_FIELD(a,s32 *,12),func_0205afdc,0);
data_0213e110=0;
}

u16 func_0205b030(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 8);
}

s32 func_0205b038(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x54) - M2C_FIELD(arg0, s32 *, 0x58);
}

s32 func_0205b048(s32 *arg0) {
    return *arg0;
}

void func_0205b050(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x30) = arg1;
}

void func_0205b058(void *a,s32 b) {
M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
extern M2C_UNK data_020ff7ec,data_020ff7e0,data_020ff7b0;
if(!a)func_020640a8(&data_020ff7ec,&data_020ff7e0,&data_020ff7b0,0x1a3);
M2C_FIELD(a,s32 *,0x40)=b;
}

s32 func_0205b094(void *arg0) {
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_020ff7c8;
    extern M2C_UNK data_020ff7e0;
    extern M2C_UNK data_020ff7ec;
    if (arg0 == NULL) {
        func_020640a8(&data_020ff7ec, &data_020ff7e0, &data_020ff7c8, 0x1AA);
    }
    return M2C_FIELD(arg0, s32 *, 0x40);
}

s32 func_0205b0cc(u8 *a,s32 b) {u16 n=(a[b]<<8)&0xff00;return (u16)n|a[b+1];}

void func_0205b0ec(u8 *a,s32 b,s32 c){a[b]=c>>8;a[b+1]=c;}

s16 func_0205b100(s32 arg0, s32 arg1) {
    return (s16) (arg0 - arg1);
}

s32 func_0205b110(M2C_UNK a,M2C_UNK b,M2C_UNK c) {
s32 func_0205a0d0(s32,s32,s32,s32);s32 func_0205a29c(s32,s32);
s32 n=M2C_FIELD(a,s32 *,12);
if(n<5){
if(M2C_FIELD(a,s32 *,16)){func_0205ac6c((void *)a);if(!func_0205a0d0(a,b,0,0))return 0;}
else {if(n==4)M2C_FIELD(a,s32 *,20)=1;func_0205ac6c((void *)a);}
}else if(n!=7){func_0205ac6c((void *)a);if(!func_0205a29c(a,c))return 0;}
return 1;
}

s32 func_0205b1a4(M2C_UNK arg0) {
    M2C_UNK func_0205b110(M2C_UNK, M2C_UNK, M2C_UNK);
    return func_0205b110(arg0, 7, 2);
}

s32 func_0205b1b8(M2C_UNK arg0) {
    s32 func_0205cb4c();
    if (func_0205cb4c() == 0) {
        return 0;
    }
    return func_0205b110(arg0, 1, 4);
}

/* Drop the leading entries of the sorted list a->list whose key is below b,
   then rebase every remaining entry's index by the first entry's value and
   delete that many leading items from the object's backing store at a+0x50. */
s32 func_0205b1e4(void *a,s32 b){
void *func_02048690(s32,s32);
s32 n,i,removed; s32 *p;
n=func_02048688(M2C_FIELD(a,s32 *,0x60));if(!n)return 1;
for(i=0;i<n;i++){if(func_0205b100(M2C_FIELD(func_02048690(M2C_FIELD(a,s32 *,0x60),i),u16 *,8),b)>=0)break;}
if(!i)return 1;
while(i--){func_0204890c(M2C_FIELD(a,s32 *,0x60),i);}
n=func_02048688(M2C_FIELD(a,s32 *,0x60));if(!n){M2C_FIELD(a,s32 *,0x58)=0;return 1;}
removed=*(s32 *)func_02048690(M2C_FIELD(a,s32 *,0x60),0);
for(i=0;i<n;i++){p=func_02048690(M2C_FIELD(a,s32 *,0x60),i);*p-=removed;}
func_02059e78((u8 *)a+0x50,0,removed);return 1;}

s32 func_0205b2e0(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_02048688(s32);
    s32 func_0205a1b8(void *, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 gti2ReceiveFilterCallback(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0xC);
    if ((temp_r0 != 5) && (temp_r0 != 6)) {
        return 1;
    }
    if (func_02048688(M2C_FIELD(arg0, s32 *, 0x9C)) != 0) {
        if (gti2ReceiveFilterCallback(arg0, 0, arg1, arg2, 0) != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    }
    if (func_0205a1b8(arg0, arg1, arg2, 0) != 0) {
        return 1;
    }
    return 0;
}

s32 func_0205b370(void *a,s32 b,s32 c) {
s32 func_02048688(s32);
s32 func_0205a1b8(void *,s32,s32,s32);
s32 gti2ReceiveFilterCallback(void *,s32,s32,s32,s32);
s32 n=M2C_FIELD(a,s32 *,12),r;
if(n!=5&&n!=6){if(!func_0205b1a4((s32)a))return 0;}
else {
if(func_02048688(M2C_FIELD(a,s32 *,0x9c))){if(gti2ReceiveFilterCallback(a,0,b,c,1))r=1;else r=0;return r;}
if(!func_0205a1b8(a,b,c,1))return 0;
}
return 1;
}

s32 func_0205b41c(void *a,void *b,s32 c) {
void func_02059bbc(void *,void *);void func_02059aa0(void *);
s32 func_0205c6f4(void *,void *,void *);
u8 x[32],y[32];
if(M2C_FIELD(a,s32 *,12)!=2)return func_0205b1a4((s32)a)!=0;
if(c<32)return func_0205b1a4((s32)a)!=0;
func_02059bbc(x,b);func_02059aa0(y);func_02059bbc((u8 *)a+0x68,y);
if(!func_0205c6f4(a,x,y))return 0;
M2C_FIELD(a,s32 *,12)=3;return 1;
}

s32 func_0205b4b4(void *a,void *b,s32 c) {
void func_02059bbc(void *,void *);s32 func_02059cc4(void *,void *);s32 func_0205c780(void *,void *,s32,s32);
u8 x[32];
if(M2C_FIELD(a,s32 *,12)!=0)return func_0205b1a4((s32)a)!=0;
if(c<64)return func_0205b1a4((s32)a)!=0;
if(!func_02059cc4(b,(u8 *)a+0x68))return func_0205b1a4((s32)a)!=0;
func_02059bbc(x,(u8 *)b+32);
if(!func_0205c780(a,x,M2C_FIELD(a,s32 *,0x38),M2C_FIELD(a,s32 *,0x3c)))return 0;
if(M2C_FIELD(a,void **,0x38)){func_020377c4(M2C_FIELD(a,void **,0x38));M2C_FIELD(a,void **,0x38)=0;}
M2C_FIELD(a,s32 *,12)=1;return 1;
}

s32 func_0205b590(void *a,s32 b,s32 c){
s32 func_02059cc4(void *,void *);s32 func_0205cb4c(void *);s32 func_02049208(void);s32 func_02059fb4(void *,void *,s32,u16,s32,s32,s32);
if(M2C_FIELD(a,s32 *,12)!=3)return func_0205b1a4((s32)a)!=0;
if(c<32)return func_0205b1a4((s32)a)!=0;
if(!func_02059cc4((void *)b,a+0x68))return func_0205b1a4((s32)a)!=0;
if(!M2C_FIELD(M2C_FIELD(a,void **,8),s32 *,32)){
if(!func_0205cb4c(a))return 0;
func_0205ac6c(a);return 1;
}
M2C_FIELD(a,s32 *,12)=4;
return func_02059fb4(M2C_FIELD(a,void **,8),a,M2C_FIELD(a,s32 *,0),M2C_FIELD(a,u16 *,4),func_02049208()-M2C_FIELD(a,s32 *,0x8c),b+32,c-32)!=0;
}

s32 func_0205b6a0(void *a) {s32 func_0205a0d0();s32 v;if(M2C_FIELD(a,s32 *,12)!=1){if(func_0205b1a4(a))v=1;else v=0;return v;} M2C_FIELD(a,s32 *,12)=5;if(func_0205a0d0(a,0,0,0))return 1;return 0;}

s32 func_0205b6ec(void *a,s32 b,s32 c) {s32 func_0205a0d0();s32 func_0205cb4c();s32 v;if(M2C_FIELD(a,s32 *,12)!=1){if(func_0205b1a4(a))v=1;else v=0;return v;}func_0205ac6c(a);if(!func_0205cb4c(a))return 0;if(func_0205a0d0(a,2,b,c))return 1;return 0;}

s32 func_0205b758(void *arg0) {
    M2C_UNK var_r2;

    if (func_0205cb4c() == 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0xC) == 6) {
        var_r2 = 0;
    } else {
        var_r2 = 1;
    }
    if (func_0205b110(arg0, 2, var_r2) == 0) {
        return 0;
    }
    return 1;
}

/* Increment the object's command counter and dispatch one of its commands (0-6). */
s32 func_0205b79c(void *object, s32 command, s32 param_a, s32 param_b) {
    s32 func_0205b590(void *, s32, s32);
    M2C_FIELD(object, u16 *, 0x66)++;
    if (command == 0) { if (!func_0205b370(object, param_a, param_b)) return 0; }
    else if (command == 1) { if (!func_0205b41c(object, (void *)param_a, param_b)) return 0; }
    else if (command == 2) { if (!func_0205b4b4(object, (void *)param_a, param_b)) return 0; }
    else if (command == 3) { if (!func_0205b590(object, param_a, param_b)) return 0; }
    else if (command == 4) { if (!func_0205b6a0(object)) return 0; }
    else if (command == 5) { if (!func_0205b6ec(object, param_a, param_b)) return 0; }
    else if (command == 6) { if (!func_0205b758(object)) return 0; }
    return 1;
}

void func_0205b89c(void *arg0, void *arg1) {
    func_0205b100(M2C_FIELD(arg0, u16 *, 0xC), M2C_FIELD(arg1, u16 *, 0xC));
}

s32 func_0205b8b0(void *a,s32 command,u16 sequence,void *data,s32 size,s32 *error){
s32 func_02048688(s32);void *func_02048690(s32,s32);s32 func_02059d24(void *);void func_020487fc(s32,void *,void *);void func_02059df0(void *,void *,s32);s32 func_0205caac(void *,u16,u16);
s32 count=func_02048688(M2C_FIELD(a,s32 *,0x5c));s32 i;Command5B8B0 record;void *prev;s32 seq2;
for(i=0;i<count;i++){u16 seq=M2C_FIELD(func_02048690(M2C_FIELD(a,s32 *,0x5c),i),u16 *,12);if(seq==sequence){*error=0;return 1;}if(func_0205b100(seq,sequence)>0)break;}
if(func_02059d24(a+0x44)<size){*error=1;return 1;}
record.offset=M2C_FIELD(a,s32 *,0x4c);record.size=size;record.command=command;record.sequence=sequence;
func_020487fc(M2C_FIELD(a,s32 *,0x5c),&record,func_0205b89c);
if(count+1!=func_02048688(M2C_FIELD(a,s32 *,0x5c))){*error=1;return 1;}
func_02059df0(a+0x44,data,size);
if(count==0){if(!func_0205caac(a,M2C_FIELD(a,u16 *,0x66),(u16)(sequence-1)))return 0;}
else {seq2=M2C_FIELD(func_02048690(M2C_FIELD(a,s32 *,0x5c),count),u16 *,12);if(seq2==sequence){
prev=func_02048690(M2C_FIELD(a,s32 *,0x5c),count-1);
if((u16)func_0205b100(sequence,M2C_FIELD(prev,u16 *,12))>1){
if(!func_0205caac(a,(u16)(M2C_FIELD(prev,u16 *,12)+1),(u16)(sequence-1)))return 0;
}}}
*error=0;return 1;
}

void func_0205ba64(void *a,void *b,s32 c) {void *func_02048690(s32,s32);s32 x,y,n,i,max;void *p;s32 v;x=M2C_FIELD(b,s32 *,0);y=M2C_FIELD(b,s32 *,4);max=0;func_0204890c(M2C_FIELD(a,s32 *,92),c);n=func_02048688(M2C_FIELD(a,s32 *,92));i=0;if(n>0)do{p=func_02048690(M2C_FIELD(a,s32 *,92),i);if(M2C_FIELD(p,s32 *,0)>x){M2C_FIELD(p,s32 *,0)-=y;v=M2C_FIELD(p,s32 *,0)+M2C_FIELD(p,s32 *,4);if(max<=v)max=v;}i++;}while(i<n);func_02059e78((char*)a+68,x,y);}

s32 func_0205bae8(void *a){s32 func_02048688(s32);void *func_02048690(s32,s32);s32 func_0205b79c(void *,s32,s32,s32);s32 i;void *p;restart:for(i=func_02048688(M2C_FIELD(a,s32 *,92))-1;i>=0;i--){p=func_02048690(M2C_FIELD(a,s32 *,92),i);if(M2C_FIELD(p,u16 *,12)==M2C_FIELD(a,u16 *,102)){if(func_0205b79c(a,M2C_FIELD(p,s32 *,8),M2C_FIELD(a,s32 *,68)+M2C_FIELD(p,s32 *,0),M2C_FIELD(p,s32 *,4))==0)return 0;func_0205ba64(a,p,i);goto restart;}}return 1;}

void func_0205bb68(void *arg0) {
    s32 func_02049208();
    if (M2C_FIELD(arg0, s32 *, 0x90) != 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x90) = 1;
    M2C_FIELD(arg0, s32 *, 0x94) = func_02049208();
}

