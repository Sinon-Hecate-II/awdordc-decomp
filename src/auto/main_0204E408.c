/* 9 functions from 0x0204E408 to 0x0204EEE8 (main), found by ds-decomp. */
#include "common.h"
typedef struct InitPair4E { s32 first, second; } InitPair4E;
typedef struct InitState4E { u8 pad[0x1a4]; InitPair4E pairs[6]; } InitState4E;

#pragma opt_common_subs off
/* Builds a gpi set-status request on the session (status, sesskey, status string
 * and location string) and caches the three values; backslashes in the strings
 * are turned into slashes. Returns 0 on success, 2 on a bad argument or a
 * disconnected connection. */
s32 gpiSetStatusInfo(void **connection, s32 status, s8 *statusString, s8 *locationString) {
    M2C_UNK StringCopyN(s8 *, s8 *, M2C_UNK);
    M2C_UNK gpiSetErrorString(void **, M2C_UNK *);
    s32 StringCompare(s8 *, void *);
    extern M2C_UNK gGpiMsgDisconnected;
    extern s8 gGsKeySessKey;
    extern s8 gGsKeyFinalStatus;
    extern M2C_UNK gGpiMsgInvalidStatusString;
    extern M2C_UNK gGpiMsgInvalidLocationString;
    extern s8 gGsKeyStatus;
    extern s8 gGsKeyStatString;
    extern s8 gGsKeyLocString;
    s8 statusCopy[0x100];
    s8 locationCopy[0x100];
    s8 *c1;
    s8 *c2;
    void *session;

    if (!connection || !(session = *connection)) {
        return 2;
    }
    if (M2C_FIELD(session, s32 *, 0x108) != 0) {
        return 0;
    }
    if (M2C_FIELD(session, s32 *, 0x1D8) == 4) {
        gpiSetErrorString(connection, &gGpiMsgDisconnected);
        return 2;
    }
    if (statusString == NULL) {
        gpiSetErrorString(connection, &gGpiMsgInvalidStatusString);
        return 2;
    }
    if (locationString == NULL) {
        gpiSetErrorString(connection, &gGpiMsgInvalidLocationString);
        return 2;
    }
    StringCopyN(statusCopy, statusString, 0x100);
    if (statusCopy[0] != 0) {
        c1 = statusCopy;
        do {
            if (*c1 == 0x5C) {
                *c1 = 0x2F;
            }
            c1 += 1;
        } while (*c1 != 0);
    }
    StringCopyN(locationCopy, locationString, 0x100);
    if (locationCopy[0] != 0) {
        c2 = locationCopy;
        do {
            if (*c2 == 0x5C) {
                *c2 = 0x2F;
            }
            c2 += 1;
        } while (*c2 != 0);
    }
    if ((status == M2C_FIELD(session, s32 *, 0x214)) && (StringCompare(statusCopy, session + 0x218) == 0) && (StringCompare(locationCopy, session + 0x318) == 0)) {
        return 0;
    }
    M2C_FIELD(session, s32 *, 0x214) = status;
    StringCopyN(session + 0x218, statusCopy, 0x100);
    StringCopyN(session + 0x318, locationCopy, 0x100);
    gpiAppendStringField(connection, session + 0x1F4, &gGsKeyStatus);
    gpiAppendIntField(connection, session + 0x1F4, status);
    gpiAppendStringField(connection, session + 0x1F4, &gGsKeySessKey);
    gpiAppendIntField(connection, session + 0x1F4, M2C_FIELD(session, s32 *, 0x198));
    gpiAppendStringField(connection, session + 0x1F4, &gGsKeyStatString);
    gpiAppendStringField(connection, session + 0x1F4, statusCopy);
    gpiAppendStringField(connection, session + 0x1F4, &gGsKeyLocString);
    gpiAppendStringField(connection, session + 0x1F4, locationCopy);
    gpiAppendStringField(connection, session + 0x1F4, &gGsKeyFinalStatus);
    return 0;
}
#pragma opt_common_subs reset
s32 func_0204e634(void **arg0,s32 arg1,s32 arg2) {
s32 gpiSendMessageToPlayer(void **,s32,s32,s32);
M2C_UNK gpiSetErrorString(void **,M2C_UNK *);
extern M2C_UNK gGpiMsgDisconnected; extern M2C_UNK data_020fdb50;
void *p;
if(arg0==0 || (p=*arg0)==0)return 2;
if(M2C_FIELD(p,s32 *,0x108)!=0)return 0;
if(M2C_FIELD(p,s32 *,0x1d8)==4){gpiSetErrorString(arg0,&gGpiMsgDisconnected);return 2;}
if(arg2==0){gpiSetErrorString(arg0,&data_020fdb50);return 2;}
return gpiSendMessageToPlayer(arg0,arg1,1,arg2);
}

s32 func_0204e6a8(void **a,s32 b,s32 c){void *gpiMalloc(s32);s32 func_020558e8(void **);s32 gpiResetConnection(void **);void func_0204e7f0(void **);void func_02065210(void *,s32,s32);void gpiLogMessage(void **,void *,...);extern u8 data_020fdb70[];InitState4E *p;s32 i,r;*a=0;p=gpiMalloc(0x490);if(!p)return 1;func_02065210(p,0,0x490);M2C_FIELD(p,u8 *,0)=0;M2C_FIELD(p,s32 *,0x418)=0;M2C_FIELD(p,s32 *,0x100)=1;M2C_FIELD(p,s32 *,0x104)=0;M2C_FIELD(p,s32 *,0x108)=0;M2C_FIELD(p,s32 *,0x10c)=0;M2C_FIELD(p,s32 *,0x46c)=b;M2C_FIELD(p,s32 *,0x470)=c;if(!func_020558e8((void **)&p)){gpiFree(p);p=0;return 1;}M2C_FIELD(p,s32 *,0x420)=0;for(i=0;i<6;i++){p->pairs[i].first=0;p->pairs[i].second=0;}M2C_FIELD(p,s32 *,0x460)=0;gpiLogMessage((void **)&p,data_020fdb70);r=gpiResetConnection((void **)&p);if(r){func_0204e7f0((void **)&p);return r;}func_0204926c();GetTickCountMs();SetRandSeed();*a=p;return 0;}

void func_0204e7f0(void **arg0) {
    M2C_UNK gpiFree(void *);
    M2C_UNK func_02048dc4(s32);
    M2C_UNK gpiDisconnect(void **, M2C_UNK);
    void *temp_r4;

    temp_r4 = *arg0;
    gpiDisconnect(arg0, 1);
    gpiFree(M2C_FIELD(temp_r4, void **, 0x460));
    M2C_FIELD(temp_r4, void **, 0x460) = NULL;
    func_02048dc4(M2C_FIELD(temp_r4, s32 *, 0x428));
    gpiFree(temp_r4);
    *arg0 = NULL;
}

s32 func_0204e830(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 8) = 0;
    M2C_FIELD(arg1, s32 *, 0x10) = 0;
    M2C_FIELD(arg1, s32 *, 0x14) = 0;
    M2C_FIELD(arg1, s32 *, 0x18) = 0;
    return 1;
}

s32 gpiResetConnection(void **a){void func_02054484(void **,void *);void func_02055cd0(void **,void *);s32 func_0204e830(void *, void *);void *p=*a;M2C_FIELD(p,s8 *,272)=0;M2C_FIELD(p,s8 *,303)=0;M2C_FIELD(p,s8 *,324)=0;M2C_FIELD(p,s32 *,468)=-1;M2C_FIELD(p,s32 *,472)=0;M2C_FIELD(p,s32 *,484)=0;M2C_FIELD(p,s32 *,488)=0;M2C_FIELD(p,s32 *,480)=0;gpiFree(M2C_FIELD(p,s32 *,476));M2C_FIELD(p,s32 *,476)=0;M2C_FIELD(p,s32 *,496)=0;gpiFree(M2C_FIELD(p,s32 *,492));M2C_FIELD(p,s32 *,492)=0;M2C_FIELD(p,s32 *,508)=0;M2C_FIELD(p,s32 *,512)=0;M2C_FIELD(p,s32 *,504)=0;gpiFree(M2C_FIELD(p,s32 *,500));M2C_FIELD(p,s32 *,500)=0;M2C_FIELD(p,s32 *,1096)=0;M2C_FIELD(p,s32 *,1100)=0;M2C_FIELD(p,s32 *,1092)=0;gpiFree(M2C_FIELD(p,s32 *,1088));M2C_FIELD(p,s32 *,1088)=0;M2C_FIELD(p,s32 *,1112)=0;M2C_FIELD(p,s32 *,1116)=0;M2C_FIELD(p,s32 *,1108)=0;gpiFree(M2C_FIELD(p,s32 *,1104));M2C_FIELD(p,s32 *,1104)=0;M2C_FIELD(p,s32 *,0x204)=-1;M2C_FIELD(p,s32 *,0x20c)=2;while(M2C_FIELD(p,s32 *,0x424))func_02054484(a,M2C_FIELD(p,s32 *,0x424));M2C_FIELD(p,s32 *,0x424)=0;M2C_FIELD(p,s32 *,0x430)=0;func_02055cd0(a,&func_0204e830);M2C_FIELD(p,s32 *,412)=0;M2C_FIELD(p,s32 *,416)=0;M2C_FIELD(p,s32 *,408)=0;M2C_FIELD(p,s32 *,528)=0;M2C_FIELD(p,s32 *,1052)=0;M2C_FIELD(p,s32 *,1076)=0;M2C_FIELD(p,s32 *,0x214)=-1;M2C_FIELD(p,s8 *,0x218)=0;M2C_FIELD(p,s8 *,0x318)=0;return 0;}

/* Reads whatever the server has sent, cuts the receive buffer at each "\final\"
 * terminator and dispatches every message: a message carrying "\id\" runs the
 * operation registered for that id, otherwise it is parsed as key/value data. */
s32 gpiHandleServerData(void *ctx) {
    extern u8 gGpiConnTag[], gGpiMsgRecvError[], gGpiKeyFinal[], gGpiKeyId[], gGpiMsgCmd[],
        gGpiMsgOutOfMemory[], gGpiMsgNoOperation[], gGpiKeyBm[], gGpiKeyKa[], gGpiMsgUnsolicited[],
        gGpiMsgServerClosed[];
    void func_02052e18(void *, void *);
    s32 gpiSendBufferedData(void *, s32, void *, s32 *, s32, void *);
    s32 gpiReceiveData(void *, s32, void *, s32 *, s32 *, void *);
    void gpiSetError(void *, s32, void *);
    void gpiCallErrorCallback(void *, s32, s32);
    u8 *StringFind(void *, void *);
    void gpiLogMessage(void **, void *, ...);
    void *gpiRealloc(void *, s32);
    s32 gpiSetErrorString(void **, s32 *);
    void MemCopy(void *, void *, s32);
    void func_020651c4(void *, void *, s32);
    s32 ParseInt(void *);
    s32 func_020544d4(void **, void **, s32);
    s32 func_0205455c(void *, s32, void *);
    s32 func_0205817c(void *, void *, s32);
    s32 StringCompareN(void *, void *, s32);
    s32 func_0204eee8(void *, void *);
    s32 func_02054520(void *);
    void func_02049260(s32);

    void *operation;
    s32 lineLen, connectionClosed = 0, result, id, again;
    u8 *conn = *(u8 **)ctx, *messageEnd, *scan;
    void *newBuf;

    do {
        func_02052e18(ctx, conn + 0x1f4);
        result = gpiSendBufferedData(ctx, M2C_FIELD(conn, s32 *, 0x1d4), conn + 0x1f4, &connectionClosed, 1, gGpiConnTag);
        if (result) return result;
        result = gpiReceiveData(ctx, M2C_FIELD(conn, s32 *, 0x1d4), conn + 0x1dc, &lineLen, &connectionClosed, gGpiConnTag);
        if (result) {
            if (result != 3) return result;
            gpiSetError(ctx, 5, gGpiMsgRecvError);
            gpiCallErrorCallback(ctx, 3, 1);
            return 3;
        }
        messageEnd = StringFind(M2C_FIELD(conn, void **, 0x1dc), gGpiKeyFinal);
        while (messageEnd) {
            *messageEnd = 0;
            gpiLogMessage(ctx, gGpiMsgCmd, M2C_FIELD(conn, void **, 0x1dc));
            lineLen = messageEnd - M2C_FIELD(conn, u8 **, 0x1dc);
            if (lineLen > M2C_FIELD(conn, s32 *, 0x1f0)) {
                M2C_FIELD(conn, s32 *, 0x1f0) += lineLen < 0x800 ? 0x800 : lineLen;
                newBuf = gpiRealloc(M2C_FIELD(conn, void **, 0x1ec), M2C_FIELD(conn, s32 *, 0x1f0) + 1);
                if (!newBuf) {
                    gpiSetErrorString(ctx, gGpiMsgOutOfMemory);
                    return 1;
                }
                M2C_FIELD(conn, void **, 0x1ec) = newBuf;
            }
            MemCopy(M2C_FIELD(conn, void **, 0x1ec), M2C_FIELD(conn, void **, 0x1dc), lineLen + 1);
            scan = messageEnd + 7;
            M2C_FIELD(conn, s32 *, 0x1e4) -= scan - M2C_FIELD(conn, u8 **, 0x1dc);
            func_020651c4(M2C_FIELD(conn, void **, 0x1dc), scan, M2C_FIELD(conn, s32 *, 0x1e4) + 1);
            scan = M2C_FIELD(conn, u8 **, 0x1ec);
            messageEnd = StringFind(scan, gGpiKeyId);
            if (messageEnd) {
                id = ParseInt(messageEnd + 4);
                if (!func_020544d4(ctx, &operation, id)) {
                    gpiLogMessage(ctx, gGpiMsgNoOperation, id);
                } else {
                    result = func_0205455c(ctx, (s32)operation, M2C_FIELD(conn, void **, 0x1ec));
                    if (result) return result;
                }
            } else {
                if (func_0205817c(ctx, scan, 1)) return 4;
                scan = M2C_FIELD(conn, u8 **, 0x1ec);
                if (!StringCompareN(scan, gGpiKeyBm, 4)) {
                    result = func_0204eee8(ctx, scan);
                    if (result) return result;
                } else if (StringCompareN(scan, gGpiKeyKa, 10)) {
                    gpiLogMessage(ctx, gGpiMsgUnsolicited);
                }
            }
            messageEnd = StringFind(M2C_FIELD(conn, void **, 0x1dc), gGpiKeyFinal);
        }
        if (connectionClosed) {
            gpiSetError(ctx, 7, gGpiMsgServerClosed);
            gpiCallErrorCallback(ctx, 3, 1);
            return 0;
        }
        again = func_02054520(ctx);
        if (again) func_02049260(10);
    } while (again);
    return 0;
}

s32 gpiThink(void **arg0, s32 arg1) {
    void func_02049260(s32); s32 gpiHandleServerData(void *); s32 func_02050ad4(void **,s32);
    s32 func_02051ed0(void **); void gpiFinishOperation(void **); void func_02054484(void **,void *);
    s32 func_020544d4(void **,void **,s32); s32 func_0205519c(void **);
    s32 gpiProcessSearches(void **); s32 gpiDisconnect(void **,s32);
    void AssertFailed(void *,void *,void *,s32);
    extern M2C_UNK data_020fdb64,data_020fdc80,data_020fdd78,data_020fdd80;
    void *sp0;
    void *state;
    s32 result;
    u32 flag;
    void *node;
    s32 ret;
    state=*arg0; result=0;
    if(M2C_FIELD(state,u32 *,0x1d8)>4)AssertFailed(&data_020fdc80,&data_020fdd78,&data_020fdb64,0x1b6);
    if(M2C_FIELD(state,u32 *,0x1d8)==1) {
        do {
            result=func_02051ed0(arg0);
            if(result==0 && arg1 && M2C_FIELD(state,u32 *,0x1d8)==1)flag=1;else flag=0;
            if(flag)func_02049260(10);
        }while(flag);
        if(result) {
            if(func_020544d4(arg0,&sp0,1))M2C_FIELD(sp0,s32 *,0x1c)=4;
            else AssertFailed(&data_020fdd80,&data_020fdd78,&data_020fdb64,0x1dc);
        }
    }
    if((u32)(M2C_FIELD(state,u32 *,0x1d8)-2)<=1){
        if(!result)result=gpiHandleServerData(arg0);
        if(!result)result=func_0205519c(arg0);
    }
    if(!result)result=gpiProcessSearches(arg0);
    node=M2C_FIELD(state,void **,0x424);sp0=node;
    if(node)do {
        if(M2C_FIELD(node,s32 *,0x1c)==0)sp0=M2C_FIELD(node,void **,0x20);
        else {gpiFinishOperation(arg0);node=sp0;sp0=M2C_FIELD(node,void **,0x20);func_02054484(arg0,node);}
        node=sp0;
    }while(node);
    ret=func_02050ad4(arg0,arg1);
    if(ret)return ret;
    if(M2C_FIELD(state,s32 *,0x41c))gpiDisconnect(arg0,0);
    return result;
}

s32 func_0204ee40(void **arg0, void *arg1) {
    M2C_UNK gpiAppendStringField(void **, void *, M2C_UNK *);
    M2C_UNK gpiAppendIntField(void **, void *, s32);
    extern M2C_UNK data_020fdd94;
    extern M2C_UNK data_020fdda0;
    extern M2C_UNK data_020fddac;
    extern M2C_UNK data_020fddbc;
    extern M2C_UNK data_020fddc4;
    void *temp_r4;

    temp_r4 = *arg0;
    gpiAppendStringField(arg0, temp_r4 + 0x1F4, &data_020fdd94);
    gpiAppendStringField(arg0, temp_r4 + 0x1F4, &data_020fdda0);
    gpiAppendIntField(arg0, temp_r4 + 0x1F4, M2C_FIELD(temp_r4, s32 *, 0x198));
    gpiAppendStringField(arg0, temp_r4 + 0x1F4, &data_020fddac);
    gpiAppendIntField(arg0, temp_r4 + 0x1F4, M2C_FIELD(arg1, s32 *, 0));
    gpiAppendStringField(arg0, temp_r4 + 0x1F4, &data_020fddbc);
    gpiAppendStringField(arg0, temp_r4 + 0x1F4, M2C_FIELD(arg1, M2C_UNK **, 0x10));
    gpiAppendStringField(arg0, temp_r4 + 0x1F4, &data_020fddc4);
    return 0;
}

