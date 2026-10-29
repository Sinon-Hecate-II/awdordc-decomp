/* 28 functions from 0x02059BBC to 0x0205ABB4 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 v[4]; } Unk0205Copy;

u8 *func_02059bbc(void *out_,void *in_){
u64 func_020720f0(s32,s32);s32 func_02068c34(s32);s32 func_02059a04(s8 *);s32 func_02067774(void);s32 func_0206409c(s32);extern s8 data_020ff548[];
s8 *in;u8 *out;s32 prev,n,step,v,i,flag,a,b;
in=in_;out=out_;
n=func_02068c34((s32)data_020ff548);flag=func_02059a04(in);i=0;step=0;
do{
if(!flag||i==0||i==13){v=func_02067774()%93+33;}
else{
if(i==1||i==14)prev=in[i];else prev=in[i-1];
v=*(u8 *)((u32)in+(u32)i);a=(s32)(func_020720f0(i+v,n)>>32);b=(s32)(func_020720f0(prev*step,n)>>32);
a=data_020ff548[a];b=data_020ff548[b];v=func_0206409c(b^((u8 *)in)[(a+i*v)%32])%93+33;
}
*(u8 *)((u32)out+(u32)i)=v;step+=0x4647;i++;
}while(i<32);return out;
}

s32 func_02059cc4(u8 *a,u8 *b) {s32 i=0;do{if(i!=0&&i!=13&&a[i]!=b[i])return 0;i++;}while(i<32);return 1;}

s32 func_02059cf8(void *arg0, s32 arg1) {
    s32 func_02037794(s32);
    s32 temp_r0;

    temp_r0 = func_02037794(arg1);
    M2C_FIELD(arg0, s32 *, 0) = temp_r0;
    if (temp_r0 == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 4) = arg1;
    return 1;
}

s32 func_02059d24(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 4) - M2C_FIELD(arg0, s32 *, 8);
}

void func_02059d34(void *p,s32 a) {
extern M2C_UNK data_020ff5d4,data_020ff5f0,data_020ff5a8;
M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,M2C_UNK);
if(M2C_FIELD(p,s32 *,8)>=M2C_FIELD(p,s32 *,4))func_020640a8(&data_020ff5d4,&data_020ff5f0,&data_020ff5a8,35);
M2C_FIELD(p,u8 **,0)[M2C_FIELD(p,s32 *,8)++]=a;
}

void func_02059d84(void *p,s32 a) {
extern M2C_UNK data_020ff5fc,data_020ff5f0,data_020ff5bc;
M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,M2C_UNK);
if(M2C_FIELD(p,s32 *,8)+2>M2C_FIELD(p,s32 *,4))func_020640a8(&data_020ff5fc,&data_020ff5f0,&data_020ff5bc,46);
M2C_FIELD(p,u8 **,0)[M2C_FIELD(p,s32 *,8)++]=a>>8;
M2C_FIELD(p,u8 **,0)[M2C_FIELD(p,s32 *,8)++]=a;
}

void func_02059df0(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    M2C_UNK func_020651a4(s32, s32, s32);
    s32 func_02068c34(s32);
    extern M2C_UNK data_020ff594;
    extern M2C_UNK data_020ff5f0;
    extern M2C_UNK data_020ff620;
    s32 var_r4;

    var_r4 = arg2;
    if ((arg1 != 0) && (var_r4 != 0)) {
        if (var_r4 == -1) {
            var_r4 = func_02068c34(arg1);
        }
        if ((s32) (M2C_FIELD(arg0, s32 *, 8) + var_r4) > (s32) M2C_FIELD(arg0, s32 *, 4)) {
            func_020640a8(&data_020ff620, &data_020ff5f0, &data_020ff594, 0x40);
        }
        func_020651a4(M2C_FIELD(arg0, s32 *, 0) + M2C_FIELD(arg0, s32 *, 8), arg1, var_r4);
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + var_r4);
    }
}

void func_02059e78(void *p,s32 a,s32 b) {
extern M2C_UNK data_020ff644,data_020ff5f0,data_020ff580,data_020ff65c;
void func_020651c4(s32,s32,s32);s32 start;
if(a==-1)a=M2C_FIELD(p,s32 *,8)-b;
if(a>M2C_FIELD(p,s32 *,8))func_020640a8(&data_020ff644,&data_020ff5f0,&data_020ff580,79);
if(b>M2C_FIELD(p,s32 *,8)-a)func_020640a8(&data_020ff65c,&data_020ff5f0,&data_020ff580,80);
start=M2C_FIELD(p,s32 *,0)+a;
func_020651c4(start,start+b,M2C_FIELD(p,s32 *,8)-a-b);
M2C_FIELD(p,s32 *,8)-=b;
}

s32 func_02059f18(void *arg0) {
    M2C_UNK func_0205cef8(void *);
    extern M2C_UNK data_020ff704;
    extern M2C_UNK data_020ff774;
    extern M2C_UNK data_020ff77c;
    if (arg0 == NULL) {
        func_020640a8(&data_020ff774, &data_020ff77c, &data_020ff704, 0x1B);
    }
    if (arg0 == NULL) {
        return 1;
    }
    if (M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x24) == NULL) {
        return 1;
    }
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) + 1);
    M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x24)(arg0);
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) - 1);
    if ((M2C_FIELD(arg0, s32 *, 0x14) != 0) && (M2C_FIELD(arg0, s32 *, 0x1C) == 0)) {
        func_0205cef8(arg0);
        return 0;
    }
    return 1;
}

s32 func_02059fb4(void *p,void *q,s32 a,s32 b,s32 c,s32 d,s32 e){
extern int data_020ff78c,data_020ff77c,data_020ff738;
if(!p||!q)func_020640a8(&data_020ff78c,&data_020ff77c,&data_020ff738,0x3d);
if(!p||!q)return 1;
if(!M2C_FIELD(p,void **,0x20))return 1;
if(!e||!d){d=0;e=0;}
M2C_FIELD(p,s32 *,0x1c)++;
M2C_FIELD(q,s32 *,0x24)++;
((void (*)(void *,void *,s32,s32,s32,s32,s32))M2C_FIELD(p,void **,0x20))(p,q,a,b,c,d,e);
M2C_FIELD(p,s32 *,0x1c)--;M2C_FIELD(q,s32 *,0x24)--;
if(M2C_FIELD(p,s32 *,0x14)&&!M2C_FIELD(p,s32 *,0x1c)){func_0205cef8(p);return 0;}
return 1;
}

s32 func_0205a0d0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_UNK func_0205cef8(void *);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020ff7a4, data_020ff77c, data_020ff6d4;

    if (!arg0) {
        func_020640a8(&data_020ff7a4, &data_020ff77c, &data_020ff6d4, 0x69);
    }
    if (!arg0) {
        return 1;
    }
    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    if (!M2C_FIELD(arg0, void **, 0x28)) {
        return 1;
    }
    M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s32 *, 0x24) + 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x8), s32 *, 0x1C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x8), s32 *, 0x1C) + 1;
    if (arg3 == 0 || arg2 == 0) {
        arg2 = 0;
        arg3 = 0;
    }
    ((void (*)(void *, s32, s32, s32)) M2C_FIELD(arg0, void **, 0x28))(arg0, arg1, arg2, arg3);
    M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg0, s32 *, 0x24) - 1;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x8), s32 *, 0x1C) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x8), s32 *, 0x1C) - 1;
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x8), s32 *, 0x14)) {
        if (!M2C_FIELD(M2C_FIELD(arg0, void **, 0x8), s32 *, 0x1C)) {
            func_0205cef8(M2C_FIELD(arg0, void **, 0x8));
            return 0;
        }
    }
    return 1;
}

s32 func_0205a1b8(void *p,void *a,s32 b,s32 c){
extern int data_020ff7a4,data_020ff77c,data_020ff6bc;
if(!p)func_020640a8(&data_020ff7a4,&data_020ff77c,&data_020ff6bc,0x94);
if(!p)return 1;
if(!M2C_FIELD(p,void **,0x2c))return 1;
if(!b||!a){a=0;b=0;}
M2C_FIELD(p,int *,0x24)++;
M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x1c)++;

((void (*)(void *,void *,s32,s32))M2C_FIELD(p,void **,0x2c))(p,a,b,c);
M2C_FIELD(p,int *,0x24)--;
M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x1c)--;
if(M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x14)&&!M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x1c)){
func_0205cef8(M2C_FIELD(p,void **,8));return 0;
}return 1;}

int func_0205a29c(void *arg0, int arg1) {
    M2C_UNK func_0205cef8(void *);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020ff7a4;
    extern M2C_UNK data_020ff77c;
    extern M2C_UNK data_020ff6a8;
    void *temp;
    void *base;

    if (arg0 == NULL) {
        func_020640a8(&data_020ff7a4, &data_020ff77c, &data_020ff6a8, 0xBA);
    }
    if (arg0 == NULL) {
        return 1;
    }
    if (!*(void **)((char *)arg0 + 0x30)) {
        return 1;
    }
    *(int *)((char *)arg0 + 0x24) = *(int *)((char *)arg0 + 0x24) + 1;
    temp = *(void **)((char *)arg0 + 0x8);
    *(int *)((char *)temp + 0x1C) = *(int *)((char *)temp + 0x1C) + 1;
    ((void (*)(void *, int))*(void **)((char *)arg0 + 0x30))(arg0, arg1);
    *(int *)((char *)arg0 + 0x24) = *(int *)((char *)arg0 + 0x24) - 1;
    base = *(void **)((char *)arg0 + 0x8);
    *(int *)((char *)base + 0x1C) = *(int *)((char *)base + 0x1C) - 1;
    temp = *(void **)((char *)arg0 + 0x8);
    if (*(int *)((char *)temp + 0x14)) {
        if (!*(int *)((char *)temp + 0x1C)) {
            func_0205cef8((void *) temp);
            return 0;
        }
    }
    return 1;
}

s32 func_0205a360(void *arg0, void *arg1) {
    M2C_UNK func_0205cef8(void *);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020ff7a4;
    extern M2C_UNK data_020ff77c;
    extern M2C_UNK data_020ff694;
    if (arg0 == NULL) {
        func_020640a8(&data_020ff7a4, &data_020ff77c, &data_020ff694, 0xD9);
    }
    if (arg0 == NULL) {
        return 1;
    }
    if (!*(void **)((char *)arg0 + 0x34)) {
        return 1;
    }
    *(int *)((char *)arg0 + 0x24) = *(int *)((char *)arg0 + 0x24) + 1;
    *(int *)((char *)*(void **)((char *)arg0 + 0x8) + 0x1C) = *(int *)((char *)*(void **)((char *)arg0 + 0x8) + 0x1C) + 1;
    ((void (*)(void *, void *))*(void **)((char *)arg0 + 0x34))(arg0, arg1);
    *(int *)((char *)arg0 + 0x24) = *(int *)((char *)arg0 + 0x24) - 1;
    *(int *)((char *)*(void **)((char *)arg0 + 0x8) + 0x1C) = *(int *)((char *)*(void **)((char *)arg0 + 0x8) + 0x1C) - 1;
    if (*(int *)((char *)*(void **)((char *)arg0 + 0x8) + 0x14)) {
        if (!*(int *)((char *)*(void **)((char *)arg0 + 0x8) + 0x1C)) {
            func_0205cef8(*(void **)((char *)arg0 + 0x8));
            return 0;
        }
    }
    return 1;
}

/* Invoke the send-filter callback entry, with nesting/refcount bookkeeping and release when idle. */
s32 func_0205a424(void *connection, void *callbackIndex, s32 b, s32 c, s32 d) {
    void *func_02048690(int, int);
    void *callback;
    extern int data_020ff7a4, data_020ff77c, data_020ff6ec;
    if (!connection) func_020640a8(&data_020ff7a4, &data_020ff77c, &data_020ff6ec, 0x101);
    if (!connection) return 1;
    callback = func_02048690(M2C_FIELD(connection, void **, 0x98), callbackIndex);
    if (!callback) return 1;
    if (!c || !b) { b = 0; c = 0; }
    M2C_FIELD(connection, int *, 0x24)++;
    M2C_FIELD(M2C_FIELD(connection, void **, 8), int *, 0x1c)++;
    ((void (*)(void *, void *, s32, s32, s32))M2C_FIELD(callback, void **, 0))(connection, callbackIndex, b, c, d);
    M2C_FIELD(connection, int *, 0x24)--;
    M2C_FIELD(M2C_FIELD(connection, void **, 8), int *, 0x1c)--;
    if (M2C_FIELD(M2C_FIELD(connection, void **, 8), int *, 0x14) && !M2C_FIELD(M2C_FIELD(connection, void **, 8), int *, 0x1c)) {
        func_0205cef8(M2C_FIELD(connection, void **, 8));
        return 0;
    }
    return 1;
}

/* Invoke receive-filter callback entry 0 (or a), with nesting/refcount bookkeeping; release the filter table when idle. */
s32 gti2ReceiveFilterCallback(void *p,void *a,s32 b,s32 c,s32 d){
void *func_02048690(int,int);void *entry;
extern int data_020ff7a4,data_020ff77c,data_020ff71c;
if(!p)func_020640a8(&data_020ff7a4,&data_020ff77c,&data_020ff71c,0x12d);
if(!p)return 1;
entry=func_02048690(M2C_FIELD(p,void **,0x9c),a);if(!entry)return 1;
if(!c||!b){b=0;c=0;}
M2C_FIELD(p,int *,0x24)++;
M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x1c)++;

((void (*)(void *,void *,s32,s32,s32))M2C_FIELD(entry,void **,0))(p,a,b,c,d);
M2C_FIELD(p,int *,0x24)--;
M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x1c)--;
if(M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x14)&&!M2C_FIELD(M2C_FIELD(p,void **,8),int *,0x1c)){
func_0205cef8(M2C_FIELD(p,void **,8));return 0;
}return 1;}

s32 func_0205a614(void *p,void *q,s32 a,s32 b,s32 c,s32 d,s32 e,s32 f){
extern int data_020ff774,data_020ff77c,data_020ff680;
void (*cb)(void *,void *,s32,s32,s32,s32,s32);
if(!p)func_020640a8(&data_020ff774,&data_020ff77c,&data_020ff680,0x160);
if(!p)return 1;
if(f)cb=M2C_FIELD(p,void (**)(void *,void *,s32,s32,s32,s32,s32),0x28);
else cb=M2C_FIELD(p,void (**)(void *,void *,s32,s32,s32,s32,s32),0x2c);
if(!cb)return 1;
if(!e||!d){e=0;d=0;}
M2C_FIELD(p,s32 *,0x1c)++;
if(q)M2C_FIELD(q,s32 *,0x24)++;
cb(p,q,a,b,c,d,e);
M2C_FIELD(p,s32 *,0x1c)--;
if(q)M2C_FIELD(q,s32 *,0x24)--;
if(M2C_FIELD(p,s32 *,0x14)&&!M2C_FIELD(p,s32 *,0x1c)){func_0205cef8(p);return 0;}
return 1;}

/* Invoke the "unrecognized message" callback with refcount tracking, releasing the owning handler when idle. */
s32 gti2UnrecognizedMessageCallback(void *p,s32 a,s32 b,s32 c,s32 d,s32 *out){
extern int data_020ff774,data_020ff77c,data_020ff754;
*out=0;
if(!p)func_020640a8(&data_020ff774,&data_020ff77c,&data_020ff754,0x197);
if(!p)return 1;
if(!M2C_FIELD(p,void **,0x30))return 1;
if(!d||!c){c=0;d=0;}
M2C_FIELD(p,int *,0x1c)++;
*out=((s32 (*)(void *,s32,s32,s32,s32))M2C_FIELD(p,void **,0x30))(p,a,b,c,d);
M2C_FIELD(p,int *,0x1c)--;
if(M2C_FIELD(p,int *,0x14)&&!M2C_FIELD(p,int *,0x1c)){func_0205cef8(p);return 0;}
return 1;
}

s32 func_0205a830(s32 a,void **p) {s32 func_0205cf54(s32);s32 r=func_0205cf54(a);if(r)return r;M2C_FIELD(*p,s32 *,12)=0;M2C_FIELD(*p,s32 *,16)=1;return 0;}

s32 func_0205a860(s32 a,void **p) {s32 func_0205cf54(s32);s32 r=func_0205cf54(a);if(r)return r;M2C_FIELD(*p,s32 *,12)=2;M2C_FIELD(*p,s32 *,16)=0;return 0;}

s32 func_0205a890(void *p,s32 a,s32 b,Unk0205Copy *q,...) {
s32 func_0205d70c(s32 *,s32 *);void func_02059aa0(void *);u8 *func_02059bbc(void *,void *);void func_0205c694(void *,void *);
s32 local[8];s32 r;
func_0205d70c(&a,&b);
if(b>0){r=func_02037794(b);M2C_FIELD(p,s32 *,0x38)=r;if(!r)return 1;func_020651a4(r,a,b);M2C_FIELD(p,s32 *,0x3c)=b;}
if(q)M2C_FIELD(p,Unk0205Copy *,0x28)=*q;
func_02059aa0(local);func_02059bbc((u8 *)p+0x68,local);func_0205c694(p,local);M2C_FIELD(p,s32 *,12)=0;return 0;
}

s32 func_0205a938(void *p,Unk0205Copy *q) {
void func_0205c7f8(void *);
if(M2C_FIELD(p,s32 *,20)){M2C_FIELD(p,s32 *,20)=0;return 0;}
M2C_FIELD(p,s32 *,20)=0;if(M2C_FIELD(p,s32 *,12)!=4)return 0;
func_0205c7f8(p);M2C_FIELD(p,s32 *,12)=5;if(q)M2C_FIELD(p,Unk0205Copy *,0x28)=*q;return 1;
}

void func_0205a994(void *p,s32 a,s32 b,...) {
M2C_UNK func_0205d70c(s32 *,s32 *);M2C_UNK func_0205c854(void *,s32,s32);
M2C_FIELD(p,s32 *,20)=0;if(M2C_FIELD(p,s32 *,12)!=4)return;
func_0205d70c(&a,&b);func_0205c854(p,a,b);M2C_FIELD(p,s32 *,12)=6;
}

s32 func_0205a9ec(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_02049208();
    s32 func_0205d228(s32, s32, u16, M2C_UNK, s32);
    if (func_0205d228(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, u16 *, 4), arg1, arg2) == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x88) = func_02049208();
    return 1;
}

s32 func_0205aa34(void *p,u32 t) {
s32 func_0205a0d0(void *,s32,s32,s32);void func_0205cb4c(void *);void func_0205ac6c(void *);
s32 state=M2C_FIELD(p,s32 *,12),flag;
if(state<5){flag=0;
if(M2C_FIELD(p,s32 *,16)){u32 limit=M2C_FIELD(p,u32 *,32);if(limit){if(t-M2C_FIELD(p,u32 *,28)>limit)flag=1;}}
else if(state<4){if(t-M2C_FIELD(p,u32 *,28)>60000)flag=1;}
if(flag){func_0205cb4c(p);func_0205ac6c(p);if(!func_0205a0d0(p,6,0,0))return 0;}}
return 1;
}

s32 func_0205aad8(void *p,u32 t) {
s32 func_02048688(s32);void *func_02048690(s32,s32);s32 func_0205cbb4(void *,void *);
s32 i,n;n=func_02048688(M2C_FIELD(p,s32 *,96));
for(i=0;i<n;i++){void *q=func_02048690(M2C_FIELD(p,s32 *,96),i);if(t-M2C_FIELD(q,u32 *,12)>1000){if(!func_0205cbb4(p,q))return 0;}}return 1;
}

s32 func_0205ab44(void *p,u32 t) {s32 func_0205ca48(void *,u32);if(!M2C_FIELD(p,s32 *,0x90))return 1;if(t-M2C_FIELD(p,u32 *,0x94)>100){if(!func_0205ca48(p,t-M2C_FIELD(p,u32 *,0x94)))return 0;}return 1;}

s32 func_0205ab80(void *p,u32 t) {s32 func_0205c924(void *,u32);if(t-M2C_FIELD(p,u32 *,0x88)>30000){if(!func_0205c924(p,t-M2C_FIELD(p,u32 *,0x88)))return 0;}return 1;}

