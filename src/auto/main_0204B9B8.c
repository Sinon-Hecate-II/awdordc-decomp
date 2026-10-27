/* 11 functions from 0x0204B9B8 to 0x0204C7FC (main), found by ds-decomp. */
#include "common.h"

s32 func_0204b9b8(void *arg0) {
 M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
 s32 func_02064bcc(s32);
 s32 func_02064ed0(s32,s32,s32);
 void func_02064ffc(s32);
 extern M2C_UNK data_020fd224, data_020fd330, data_020fd334;
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
 func_020640a8(&data_020fd330,&data_020fd334,&data_020fd224,0x244); return 0;
 }
 success:
 return 1;
}

void func_0204ba68(void *arg0) {
 M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
 void func_02064934(s32);
 extern M2C_UNK data_020fd238, data_020fd330, data_020fd334;
 s32 state = *M2C_FIELD(arg0, s32 **, 0);
 if(state == 0) return;
 if(state == 1) {
 if (M2C_FIELD(arg0,s32 *,8)) func_02064934(M2C_FIELD(arg0,s32 *,8));
 M2C_FIELD(arg0,s32 *,8)=0;
 return;
 }
 if(state == 2) return;
 func_020640a8(&data_020fd330,&data_020fd334,&data_020fd238,0x269); return;
}

void func_0204bc64(void *arg0) {
 void func_0204861c(s32);
 s32 func_02048688(s32);
 void *func_02048690(s32,s32);
 void func_0204b690(void *);
 s32 i, count;
 void *p;
 if(M2C_FIELD(arg0,s32 *,0x140)) {
 count=func_02048688(M2C_FIELD(arg0,s32 *,0x140));
 for(i=0;i<count;i++) func_0204ba68(func_02048690(M2C_FIELD(arg0,s32 *,0x140),i));
 func_0204861c(M2C_FIELD(arg0,s32 *,0x140));
 M2C_FIELD(arg0,s32 *,0x140)=0;
 }
 p=M2C_FIELD(arg0,void **,0x13c);
 if(p && M2C_FIELD(p,s32 *,0x10)) {
 func_0204b690(p);
 M2C_FIELD(arg0,void **,0x13c)=0;
 }
}

s32 func_0204bec0(void *state,void *context){
M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
s32 func_02064bcc(s32);
s32 func_02064230(void *,s32,s32,s32);
s32 func_0204a9d0(void *,void *,s32);
extern M2C_UNK data_020fd4a8,data_020fd334,data_020fd2b0,data_020fd508,data_020fd530;
u8 buf[4096];s32 n,result;
if(M2C_FIELD(state,s32 *,4)<0)func_020640a8(&data_020fd4a8,&data_020fd334,&data_020fd2b0,0x336);
if(M2C_FIELD(state,s32 *,4)>=M2C_FIELD(state,s32 *,12))func_020640a8(&data_020fd508,&data_020fd334,&data_020fd2b0,0x337);
if(M2C_FIELD(state,s32 *,4)!=func_02064bcc(M2C_FIELD(state,s32 *,8)))func_020640a8(&data_020fd530,&data_020fd334,&data_020fd2b0,0x338);
do{
n=func_02064230(buf,1,4096,M2C_FIELD(state,s32 *,8));
if(n<=0){M2C_FIELD(context,s32 *,0xfc)=1;M2C_FIELD(context,s32 *,0x38)=14;return 0;}
M2C_FIELD(state,s32 *,4)+=n;
if(M2C_FIELD(state,s32 *,4)>M2C_FIELD(state,s32 *,12)){M2C_FIELD(context,s32 *,0xfc)=1;M2C_FIELD(context,s32 *,0x38)=14;return 0;}
result=func_0204a9d0(context,buf,n);
if(result==0)return 0;
if(M2C_FIELD(state,s32 *,4)==M2C_FIELD(state,s32 *,12))return 1;
}while(result==1);
return 2;
}

/* Posts pending bytes from state->data into context, up to 0x8000 at a time; returns 0 on write error, 1 when fully posted, 2 when no progress. */
s32 func_0204c01c(void *state, M2C_UNK context) {
    s32 func_0204a954(M2C_UNK, s32, s32);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_020fd2f0;
    extern M2C_UNK data_020fd334;
    extern M2C_UNK data_020fd4a8;
    extern M2C_UNK data_020fd568;
    s32 written;
    s32 total;
    s32 avail;
    s32 pos;
    s32 chunk;
    void *info;

    if ((s32) M2C_FIELD(state, s32 *, 4) < 0) {
        func_020640a8(&data_020fd4a8, &data_020fd334, &data_020fd2f0, 0x36E);
    }
    total = M2C_FIELD(M2C_FIELD(state, void **, 0), s32 *, 0xC);
    if (total == 0) {
        return 1;
    }
    if ((s32) M2C_FIELD(state, s32 *, 4) >= total) {
        func_020640a8(&data_020fd568, &data_020fd334, &data_020fd2f0, 0x375);
    }
loop_7:
    info = M2C_FIELD(state, void **, 0);
    pos = M2C_FIELD(state, s32 *, 4);
    chunk = M2C_FIELD(info, s32 *, 0xC) - pos;
    if (chunk >= 0x8000) {
        chunk = 0x8000;
    }
    written = func_0204a954(context, M2C_FIELD(info, s32 *, 8) + pos, chunk);
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

void func_0204c738(void *p) {
 void func_0204a518(void *,s32,s32); void func_0204926c(void); s32 func_0204c580(void *);s32 func_020498e4(s32);void *func_02021768(s32);extern s32 data_0213dca8;
 s32 id,v;void *q;
 func_0204a518(p,0,0);func_0204926c();
 if(!func_0204c580(p)){M2C_FIELD(p,s32 *,0xfc)=1;M2C_FIELD(p,s32 *,0x38)=3;return;}
 id=M2C_FIELD(p,s32 *,0x15c);
 if(!id){id=data_0213dca8;if(!id)id=M2C_FIELD(p,s32 *,0x18);}
 v=func_020498e4(id);M2C_FIELD(p,s32 *,0x1c)=v;
 if(v==-1){
 q=func_02021768(id);
 if(!q){M2C_FIELD(p,s32 *,0xfc)=1;M2C_FIELD(p,s32 *,0x38)=4;return;}
 M2C_FIELD(p,s32 *,0x1c)=**M2C_FIELD(q,s32 ***,12);
 }
 M2C_FIELD(p,s32 *,0x10)=1;func_0204a518(p,0,0);
}

