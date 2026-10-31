/* 11 functions from 0x0204B9B8 to 0x0204C7FC (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 bytes[4]; } BCDCBytes;

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

s32 func_0204bad4(void *arg0) {
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    s32 func_02048688(s32);
    void *func_02048558(s32, s32, s32);
    void *func_02048690(s32, s32);
    s32 func_0204b9b8(void *);
    void func_020486f8(void *, void *);
    void func_0204ba68(void *);
    void func_0204861c(s32);
    s32 func_0204b958(void *);
    extern M2C_UNK data_020fd440, data_020fd334, data_020fd1fc, data_020fd454;

    s32 i;
    s32 count;
    s32 buf[4];
    s32 zero = 0;

    if (M2C_FIELD(arg0, void **, 0x13c) == 0) {
        func_020640a8(&data_020fd440, &data_020fd334, &data_020fd1fc, 0x278);
    }
    if (M2C_FIELD(arg0, void **, 0x13c) == 0) {
        return 0;
    }
    M2C_FIELD(arg0, s32 *, 0x144) = 0;
    M2C_FIELD(arg0, s32 *, 0x148) = 0;
    M2C_FIELD(arg0, s32 *, 0x14c) = 0;
    M2C_FIELD(arg0, s32 *, 0x150) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x13c), s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x154) = M2C_FIELD(M2C_FIELD(arg0, void **, 0x13c), s32 *, 8);
    count = func_02048688(M2C_FIELD(M2C_FIELD(arg0, void **, 0x13c), s32 *, 0));
    M2C_FIELD(arg0, s32 *, 0x140) = (s32)func_02048558(0x10, count, 0);
    if (M2C_FIELD(arg0, s32 *, 0x140) == 0) {
        return 0;
    }
    if (count > 0) {
        i = 0;
        do {
            buf[0] = (s32)func_02048690(M2C_FIELD(M2C_FIELD(arg0, void **, 0x13c), s32 *, 0), i);
            buf[1] = zero;
            buf[2] = zero;
            buf[3] = zero;
            if (func_0204b9b8(buf) == 0) {
                i--;
                if (i >= 0) {
                    do {
                        void *e = func_02048690(M2C_FIELD(arg0, s32 *, 0x140), i);
                        func_0204ba68(e);
                        i--;
                    } while (i >= 0);
                }
                func_0204861c(M2C_FIELD(arg0, s32 *, 0x140));
                M2C_FIELD(arg0, s32 *, 0x140) = 0;
                return 0;
            }
            func_020486f8(M2C_FIELD(arg0, s32 *, 0x140), buf);
            i++;
        } while (i < count);
    }
    if (func_02048688(M2C_FIELD(M2C_FIELD(arg0, void **, 0x13c), s32 *, 0)) != func_02048688(M2C_FIELD(arg0, s32 *, 0x140))) {
        func_020640a8(&data_020fd454, &data_020fd334, &data_020fd1fc, 0x2b1);
    }
    M2C_FIELD(arg0, s32 *, 0x14c) = func_0204b958(arg0);
    return 1;
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

s32 func_0204bcdc(void *p,void *ctx) {
s32 func_0204a954(); s8 *func_02068ee0(s32,s32);
extern s32 data_020fd4a8,data_020fd334,data_020fd294,data_020fd4b8,data_020fd4e4;
extern s8 data_020fd4f4[],data_020fd340[]; extern BCDCBytes data_020ea97c;
BCDCBytes buf; register BCDCBytes *out; s32 i,ch; s8 *str; s32 hi,n,r;
if(M2C_FIELD(p,s32 *,4)<0)func_020640a8(&data_020fd4a8,&data_020fd334,&data_020fd294,0x2e7);
if(M2C_FIELD(M2C_FIELD(p,void **,0),s32 *,12)==0)return 1;
if(M2C_FIELD(p,s32 *,4)>=M2C_FIELD(M2C_FIELD(p,void **,0),s32 *,12))func_020640a8(&data_020fd4b8,&data_020fd334,&data_020fd294,0x2ee);
if(M2C_FIELD(M2C_FIELD(ctx,void **,0x13c),s32 *,12)==0 && M2C_FIELD(M2C_FIELD(p,void **,0),s32 *,16)!=0){
str=M2C_FIELD(M2C_FIELD(p,void **,0),s8 **,8);
out=&buf; *out=data_020ea97c;
i=0;while((ch=str[i])!=0){
if(func_02068ee0((s32)data_020fd340,ch))func_0204a230(ctx+0x50,ch);
else if(ch==32)func_0204a230(ctx+0x50,43);
else {hi=ch/16;if(hi>=16)func_020640a8(&data_020fd4e4,&data_020fd334,&data_020fd294,0x30d);
out->bytes[1]=data_020fd4f4[hi];out->bytes[2]=data_020fd4f4[ch%16];func_02049ef4(ctx+0x50,out,3);}
i++;
}return 1;
}
n=M2C_FIELD(M2C_FIELD(p,void **,0),s32 *,12)-M2C_FIELD(p,s32 *,4);
r=func_0204a954(ctx,M2C_FIELD(M2C_FIELD(p,void **,0),void **,8),n);
if(r==-1)return 0;
M2C_FIELD(p,s32 *,4)+=r;
return r==n?1:2;
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

s32 func_0204c0fc(void *state, void *context, s32 flag) {
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    M2C_UNK func_020675e4(void *, void *, ...);
    s32 func_02068c34(const char *);
    s32 func_0204a9d0(void *, void *, s32);
    s32 func_0204bcdc(void *, void *);
    s32 func_0204bec0(void *, void *);
    s32 func_0204c01c(void *, M2C_UNK);
    extern M2C_UNK data_020fd598, data_020fd334, data_020fd24c, data_020fd5b8, data_020fd5bc, data_020fd5c4, data_020fd5ec, data_020fd618, data_020fd648, data_020fd330, data_020fd69c;

    u8 buf[0x800];

    if (M2C_FIELD(state, s32 *, 4) == -1) {
        M2C_FIELD(state, s32 *, 4) = 0;
        if (M2C_FIELD(M2C_FIELD(context, void **, 0x13c), s32 *, 0xc) == 0) {
            if (M2C_FIELD(M2C_FIELD(state, void **, 0), s32 *, 0) != 0) {
                func_020640a8(&data_020fd598, &data_020fd334, &data_020fd24c, 0x3a9);
            }
            func_020675e4(buf, flag ? &data_020fd5b8 : &data_020fd5bc,
                          M2C_FIELD(M2C_FIELD(state, void **, 0), s32 *, 4));
        } else {
            void *d = M2C_FIELD(state, void **, 0);
            s32 type = M2C_FIELD(d, s32 *, 0);
            if (type == 0) {
                func_020675e4(buf, &data_020fd618,
                              flag ? &data_020fd5c4 : &data_020fd5ec,
                              M2C_FIELD(d, s32 *, 4));
            } else if (type == 1 || type == 2) {
                s32 a0, a1;
                if (type == 1) {
                    a0 = M2C_FIELD(d, s32 *, 0xc);
                    a1 = M2C_FIELD(d, s32 *, 0x10);
                } else {
                    a0 = M2C_FIELD(d, s32 *, 0x10);
                    a1 = M2C_FIELD(d, s32 *, 0x14);
                }
                func_020675e4(buf, &data_020fd648,
                              flag ? &data_020fd5c4 : &data_020fd5ec,
                              M2C_FIELD(d, s32 *, 4), a0, a1);
            } else {
                func_020640a8(&data_020fd330, &data_020fd334, &data_020fd24c, 0x3dc);
            }
        }
        {
            s32 len = func_02068c34((const char *)buf);
            s32 res = func_0204a9d0(context, buf, len);
            if (res == 0) return 0;
            if (res == 2) return 2;
        }
    }

    {
        void *d = M2C_FIELD(state, void **, 0);
        s32 type = M2C_FIELD(d, s32 *, 0);
        if (type == 0) return func_0204bcdc(state, context);
        if (type == 1) return func_0204bec0(state, context);
        if (type != 2) {
            func_020640a8(&data_020fd69c, &data_020fd334, &data_020fd24c, 0x3f5);
        }
        return func_0204c01c(state, context);
    }
}

s32 func_0204c300(void *arg0){
M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);s32 func_02048688(s32);void *func_02048690(s32,s32);s32 func_0204a30c(void *);void func_0204a2c8(void *);s32 func_0204a9d0(void *,void *,s32);s32 func_02068c34(const char *);
extern M2C_UNK data_020fd6c0,data_020fd334,data_020fd210,data_020fd440,data_020fd6cc,data_020fd454,data_020fd6ec,data_020fd710,data_020fd760,data_020fd76c,data_020fd798;
void *p;s32 r,n;
if(!arg0)func_020640a8(&data_020fd6c0,&data_020fd334,&data_020fd210,0x404);
if(!M2C_FIELD(arg0,s32 *,0x13c))func_020640a8(&data_020fd440,&data_020fd334,&data_020fd210,0x405);
if(!M2C_FIELD(arg0,s32 *,0x140))func_020640a8(&data_020fd6cc,&data_020fd334,&data_020fd210,0x406);
if(func_02048688(M2C_FIELD(M2C_FIELD(arg0,void **,0x13c),s32 *,0))!=func_02048688(M2C_FIELD(arg0,s32 *,0x140)))func_020640a8(&data_020fd454,&data_020fd334,&data_020fd210,0x407);
if(M2C_FIELD(arg0,s32 *,0x144)<0)func_020640a8(&data_020fd6ec,&data_020fd334,&data_020fd210,0x408);
if(M2C_FIELD(arg0,s32 *,0x144)>func_02048688(M2C_FIELD(arg0,s32 *,0x140)))func_020640a8(&data_020fd710,&data_020fd334,&data_020fd210,0x409);
n=func_02048688(M2C_FIELD(arg0,s32 *,0x140));
if(M2C_FIELD(arg0,s32 *,0x5c)){if(!func_0204a30c(arg0))return 0;if(M2C_FIELD(arg0,s32 *,0x60)<M2C_FIELD(arg0,s32 *,0x5c))return 2;func_0204a2c8(arg0+0x50);
if(M2C_FIELD(arg0,volatile s32 *,0x144)==n)return 1;}
while(M2C_FIELD(arg0,s32 *,0x144)<n){
p=func_02048690(M2C_FIELD(arg0,s32 *,0x140),M2C_FIELD(arg0,s32 *,0x144));
if(!p)func_020640a8(&data_020fd760,&data_020fd334,&data_020fd210,0x42f);
r=func_0204c0fc(p,arg0,M2C_FIELD(arg0,s32 *,0x144)==0);
if(!r){if(!M2C_FIELD(arg0,s32 *,0xfc)||!M2C_FIELD(arg0,s32 *,0x38))func_020640a8(&data_020fd76c,&data_020fd334,&data_020fd210,0x43b);return 0;}
if(r==2)return 2;
M2C_FIELD(arg0,s32 *,0x144)++;
}
if(M2C_FIELD(M2C_FIELD(arg0,void **,0x13c),s32 *,12)){if(!func_0204a9d0(arg0,&data_020fd798,func_02068c34(&data_020fd798)))return 0;}
return M2C_FIELD(arg0,s32 *,0x5c)?2:1;
}

s32 func_0204c580(void *a) {
s32 func_02049274(s8 *); s32 func_02068eac(s8 *,void *,s32); s8 *func_02068ee0(s32,s32); s32 func_02068f1c(s8 *,void *); s32 func_0206ad38(s8 *);
extern u8 data_020fd858[],data_020fd864[],data_020fd7c4[],data_020fd874[],data_020fd884[],data_020fd88c[],data_020fd898[];extern s8 data_020fd89c[];
s8 *p,*q; s32 n,v; s8 ch; s32 secure;
if(!a)func_020640a8(data_020fd858,data_020fd864,data_020fd7c4,37);
if(!a)return 0;
if(!M2C_FIELD(a,s32 *,20))func_020640a8(data_020fd874,data_020fd864,data_020fd7c4,43);
p=M2C_FIELD(a,s8 **,20);if(!p)return 0;
if(!func_02068eac(p,data_020fd884,7)){p+=7;secure=0;}
else if(!func_02068eac(p,data_020fd88c,8)){p+=8;secure=1;}
else return 0;
n=func_02068f1c(p,data_020fd898);ch=p[n];p[n]=0;
M2C_FIELD(a,s32 *,24)=func_02049274(p);
if(!M2C_FIELD(a,s32 *,24))return 0;
p[n]=ch;p+=n;
if(*p==58){p++;M2C_FIELD(a,u16 *,32)=func_0206ad38(p);if(!M2C_FIELD(a,u16 *,32))return 0;
do {s8 c=*++p; if(c==0)break; if(c==47)break;}while(1);
}else{if(secure)M2C_FIELD(a,u16 *,32)=443;else M2C_FIELD(a,u16 *,32)=80;}
done: if(!*p)p=data_020fd89c;
M2C_FIELD(a,s32 *,36)=func_02049274(p);
v=M2C_FIELD(a,s32 *,36);
q=func_02068ee0(v,32);
if(q){do{*q=43;v=M2C_FIELD(a,s32 *,36);q=func_02068ee0(v,32);}while(q);}
if(v==0)return 0;return 1;
}

void func_0204c738(void *p) {
void func_0204a518(void *,s32,s32); void func_0204926c(void); s32 func_0204c580(void *);s32 func_020498e4(s32);void *func_02021768(s32);extern s32 data_0213dca8;
s32 id,v;void *q;
func_0204a518(p,0,0);func_0204926c();
if(!func_0204c580(p)){M2C_FIELD(p,s32 *,0xfc)=1;M2C_FIELD(p,s32 *,0x38)=3;return;}
id=M2C_FIELD(p,s32 *,0x15c);
if(id==0) { id=data_0213dca8 ? data_0213dca8 : M2C_FIELD(p,s32 *,0x18); }
v=func_020498e4(id);M2C_FIELD(p,s32 *,0x1c)=v;
if(v==-1){
q=func_02021768(id);
if(!q){M2C_FIELD(p,s32 *,0xfc)=1;M2C_FIELD(p,s32 *,0x38)=4;return;}
M2C_FIELD(p,s32 *,0x1c)=**M2C_FIELD(q,s32 ***,12);
}
M2C_FIELD(p,s32 *,0x10)=1;func_0204a518(p,0,0);
}

