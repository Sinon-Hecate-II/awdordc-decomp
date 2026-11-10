/* 19 functions from 0x0204D5C0 to 0x0204E408 (main), found by ds-decomp. */
#include "common.h"
void gpiSetErrorString(void **,void *);

void func_0204d5c0(void *arg0) { }

void func_0204da30(void *p){
s32 gpiMalloc(s32);void gpiFree(s32);s32 GetTickCountMs();s32 func_0204a740(void*,s32,s32*);s32 ghiProcessIncomingFileData(void*,s32,s32);
s32 size,buffer,status,n,start;u32 elapsed;
start=GetTickCountMs();elapsed=0;buffer=gpiMalloc(0x2000);
if(!buffer){M2C_FIELD(p,s32*,0xfc)=1;M2C_FIELD(p,s32*,0x38)=1;return;}
while(!M2C_FIELD(p,s32*,0xfc) && elapsed<M2C_FIELD(p,u32*,0x158)){
size=0x2000;status=func_0204a740(p,buffer,&size);
if(status==3 || status==1)break;
if(status==2){
M2C_FIELD(p,s32*,0xfc)=1;n=M2C_FIELD(p,s32*,0x104);
if(n>0 && M2C_FIELD(p,s32*,0x100)<n)M2C_FIELD(p,s32*,0x38)=15;
break;
}
if(!ghiProcessIncomingFileData(p,buffer,size))break;
elapsed=GetTickCountMs()-start;
}
gpiFree(buffer);
}

s32 func_0204db04(s32 arg0,s32 arg1,s32 arg2) {
 extern s32 gDnsQueryState;
 s32 func_0204e6a8(s32,s32,s32);
 if(gDnsQueryState!=1) return 2;
 if(arg0==0) return 2;
 return func_0204e6a8(arg0,arg1,arg2);
}

void func_0204db34(s32 *arg0) {
 void func_0204e7f0(s32 *);
 if (arg0==0 || *arg0==0) return;
 func_0204e7f0(arg0);
}

s32 func_0204db50(void **arg0) {
 s32 gpiThink(void **,s32);
 if(arg0==0 || *arg0==0) return 2;
 if(M2C_FIELD(*arg0,s32 *,0x108)!=0) return 0;
 return gpiThink(arg0,0);
}

s32 func_0204db84(void **arg0,s32 arg1,s32 arg2,s32 arg3) {
 void gpiSetErrorString(void **,void *);
 extern s32 data_020fda24;
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(arg1<0 || arg1>=6) {gpiSetErrorString(arg0,&data_020fda24); return 2;}
 p=(char *)p+arg1*8;
 M2C_FIELD(p,s32 *,0x1a4)=arg2;
 M2C_FIELD(p,s32 *,0x1a8)=arg3;
 return 0;
}

s32 func_0204dbd4(void **p,s8 *a,s8 *b,s32 c,s32 d,void (*cb)(void **,s32 *,s32),s32 e){
 s32 gpiStartConnection(void **,void *,void *,void *,void *,s8 *,s8 *,s32,s32,s32,s32,void (*)(void **,s32 *,s32),s32);
 void gpiSetErrorString(void **,void *);
 extern M2C_UNK data_020fda34,data_020fda44;
 void *q;
 if(!p || !(q=*p))return 2;
 if(!a || !*a)return 2;
 if(!b || !*b)return 2;
 if(!cb){gpiSetErrorString(p,&data_020fda34);return 2;}
 if(M2C_FIELD(q,s32 *,0x108)){
 s32 buf[8]={0};cb(p,buf,e);return 0;
 }
 return gpiStartConnection(p,&data_020fda44,&data_020fda44,&data_020fda44,&data_020fda44,a,b,0,c,0,d,cb,e);
}

void func_0204dcd8(void **arg0) {
    M2C_UNK gpiResetConnection(void **);
    M2C_UNK gpiDisconnect(void **, M2C_UNK);
    void *temp_r1;

    if (arg0 != NULL) {
        temp_r1 = *arg0;
        if (temp_r1 != NULL) {
            if (M2C_FIELD(temp_r1, s32 *, 0x108) != 0) {
                return;
            }
            gpiDisconnect(arg0, 1);
            gpiResetConnection(arg0);
        }
    }
}

s32 func_0204dd0c(void **p,s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g,void (*cb)(void **,s32 *,s32),s32 h){
 s32 gpiSearchProfiles(void **,s32,s32,s32,s32,s32,s32,s32,s32,void (*)(void **,s32 *,s32),s32);
 void gpiSetErrorString(void **,void *);extern M2C_UNK data_020fda34;
 s32 buf[4];s32 *result;void *q;
 if(!p || !(q=*p))return 2;
 if(!cb){gpiSetErrorString(p,&data_020fda34);return 2;}
 if(M2C_FIELD(q,s32 *,0x108)){
 result=(s32 *)buf;
 *(volatile s32 *)(result+2)=0;
 result[0]=0;
 result[1]=0;
 result[3]=0;
 buf[2]=0x601;
 cb(p,result,h);
 return 0;
 }
 return gpiSearchProfiles(p,a,b,c,d,e,f,0,g,cb,h);
}

s32 func_0204ddd4(void **p,s32 a,s32 b,s32 c,void (*cb)(void **,s32 *,s32),s32 d){
s32 func_02053c9c(void **,s32,s32,s32,void (*)(void **,s32 *,s32),s32);
extern M2C_UNK data_020fda34;extern s32 gGpiMsgDisconnected;
void *q;
if(!p || !(q=*p) || !a)return 2;
if(!cb){gpiSetErrorString(p,&data_020fda34);return 2;}
if(M2C_FIELD(q,s32 *,0x108)){s32 buf[129]={0};cb(p,buf,d);return 0;}
if(M2C_FIELD(q,s32 *,0x1d8)==4){gpiSetErrorString(p,&gGpiMsgDisconnected);return 2;}
return func_02053c9c(p,a,b,c,cb,d);
}

s32 func_0204deb0(void **arg0,s32 arg1,s32 arg2) {
 s32 func_0205342c(void **,s32,s32);
 extern s32 gGpiMsgDisconnected;
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) return 0;
 if(M2C_FIELD(p,s32 *,0x1d8)==4) {gpiSetErrorString(arg0,&gGpiMsgDisconnected);return 2;}
 return func_0205342c(arg0,arg1,arg2);
}

s32 func_0204df00(void **connection, s32 newProfileId, s8 *reason) {
    /* Build an add-buddy request in the connection's send buffer from the session key, new profile id and reason string. */
    void gpiAppendStringField(void **, void *, s8 *);
    void gpiAppendIntField(void **, void *, s32);
    void StringCopyN(void *, s8 *, s32);
    extern s32 gGpiMsgDisconnected, data_020fda78;
    extern s8 data_020fda88, gGsKeySessKey, data_020fdaa0, data_020fdab0, gGsKeyFinalStatus;
    s8 buf[0x401];
    s8 *c;
    void *session;
    if (!connection || !(session = *connection)) return 2;
    if (M2C_FIELD(session, s32 *, 0x108)) return 0;
    if (M2C_FIELD(session, s32 *, 0x1d8) == 4) {
        gpiSetErrorString(connection, &gGpiMsgDisconnected);
        return 2;
    }
    if (!reason) {
        gpiSetErrorString(connection, &data_020fda78);
        return 2;
    }
    StringCopyN(buf, reason, 0x401);
    if (*buf) {
        c = buf;
        do {
            if (*c == 92) *c = 47;
            c++;
        } while (*c);
    }
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, &data_020fda88);
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, &gGsKeySessKey);
    gpiAppendIntField(connection, (u8 *)session + 0x1f4, M2C_FIELD(session, s32 *, 0x198));
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, &data_020fdaa0);
    gpiAppendIntField(connection, (u8 *)session + 0x1f4, newProfileId);
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, &data_020fdab0);
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, buf);
    gpiAppendStringField(connection, (u8 *)session + 0x1f4, &gGsKeyFinalStatus);
    return 0;
}

s32 func_0204e074(void **arg0,s32 arg1) {
 s32 func_0204fa60(void **,s32);
 extern s32 gGpiMsgDisconnected;
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) return 0;
 if(M2C_FIELD(p,s32 *,0x1d8)==4) {gpiSetErrorString(arg0,&gGpiMsgDisconnected);return 2;}
 return func_0204fa60(arg0,arg1);
}

s32 func_0204e0c4(void **arg0,s32 arg1) {
 void gpiFree(s32);
 s32 func_02055b84(void **,s32,void **);
 void func_02055bf4(void **,void *);
 s32 func_02055d6c(void *);
 extern s32 gGpiMsgDisconnected;
 void *sp0;
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) return 0;
 if(M2C_FIELD(p,s32 *,0x1d8)==4) {gpiSetErrorString(arg0,&gGpiMsgDisconnected);return 2;}
 if(func_02055b84(arg0,arg1,&sp0)==0) return 0;
 M2C_FIELD(sp0,s32 *,0x14)--;
 if(M2C_FIELD(p,s32 *,0x100)==0 && M2C_FIELD(sp0,s32 *,0x14)<=0) {
 gpiFree(M2C_FIELD(sp0,s32 *,0x10));
 M2C_FIELD(sp0,s32 *,0x10)=0;
 if(func_02055d6c(sp0)!=0) func_02055bf4(arg0,sp0);
 }
 return 0;
}

s32 func_0204e184(void **arg0,volatile s32 *arg1) {
 void *p;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) {*arg1=0; return 0;}
 *arg1=M2C_FIELD(p,s32 *,0x430);
 return 0;
}

s32 func_0204e1b4(void **p,s32 index,void *out){
 void *func_02055d3c(void **,s32);
 void StringCopyN(void *,s8 *,s32);
 void gpiSetErrorString(void **,void *);
 void AssertFailed(void *,void *,void *,s32);
 void func_02065210(void *,s32,s32);
 extern M2C_UNK data_020fda10,data_020fdac4,data_020fdad4,data_020fdae4,data_020fdaf0;
 void *q,*entry,*details; s8 *text; s32 count;
 if(!p || !(q=*p))return 2;
 if(M2C_FIELD(q,s32 *,0x108)){func_02065210(out,0,0x210);return 0;}
 if(!out){gpiSetErrorString(p,&data_020fdac4);return 2;}
 count=M2C_FIELD(q,s32 *,0x430);
 if(index<0 || index>=count){gpiSetErrorString(p,&data_020fdad4);return 2;}
 entry=func_02055d3c(p,index);
 if(!entry){gpiSetErrorString(p,&data_020fdad4);return 2;}
 details=M2C_FIELD(entry,void **,8);
 if(!details)AssertFailed(&data_020fdae4,&data_020fdaf0,&data_020fda10,0x5cf);
 M2C_FIELD(out,s32 *,0)=M2C_FIELD(entry,s32 *,0);
 M2C_FIELD(out,s32 *,4)=M2C_FIELD(details,s32 *,4);
 text=M2C_FIELD(details,s8 **,8);
 if(!text)*text=0;else StringCopyN((u8 *)out+8,text,256);
 text=M2C_FIELD(details,s8 **,12);
 if(!text)*text=0;else StringCopyN((u8 *)out+0x108,text,256);
 M2C_FIELD(out,s32 *,0x208)=M2C_FIELD(details,s32 *,0x10);
 M2C_FIELD(out,s32 *,0x20c)=M2C_FIELD(details,s32 *,0x14);
 return 0;
}

s32 func_0204e2f4(void **arg0,s32 arg1,s32 *arg2) {
 s32 func_02055b84(void **,s32,void **);
 void *sp0; s32 *q;
 if(arg0==0 || *arg0==0) return 2;
 if(M2C_FIELD(*arg0,s32 *,0x108)!=0) {*arg2=0; return 0;}
 if(func_02055b84(arg0,arg1,&sp0)!=0 && (q=M2C_FIELD(sp0,s32 **,8))!=0) *arg2=*q;
 else *arg2=-1;
 return 0;
}

s32 func_0204e364(void **arg0,s32 arg1) {
 s32 func_02055b84(void **,s32,void **);
 void *sp0;
 if(arg0==0 || *arg0==0) return 0;
 if(M2C_FIELD(*arg0,s32 *,0x108)!=0) return 0;
 if(func_02055b84(arg0,arg1,&sp0)!=0 && M2C_FIELD(sp0,s32 *,8)!=0) return 1;
 return 0;
}

s32 func_0204e3b0(void **arg0,s32 arg1) {
 s32 func_0204fb50(void **,s32);
 extern s32 gGpiMsgDisconnected;
 void *p; s32 result;
 if(arg0==0 || (p=*arg0)==0) return 2;
 if(M2C_FIELD(p,s32 *,0x108)!=0) return 0;
 if(M2C_FIELD(p,s32 *,0x1d8)==4) {gpiSetErrorString(arg0,&gGpiMsgDisconnected);return 2;}
 result=func_0204fb50(arg0,arg1);
 if(result==0) return 0;
 return result;
}

