/* 42 functions from 0x0205ABB4 to 0x0205BB90 (main), found by ds-decomp. */
#include "common.h"
#include "gt2.h"
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
void gti2MarkConnectionClosed(void *,...);M2C_UNK gti2SendClosed();s32 gti2ClosedCallback(s32,s32);void func_0205d164(s32);void func_0205c8c8(s32);
if(b){
if(M2C_FIELD(a,s32 *,12)>=7)return;
gti2MarkConnectionClosed((void *)a);gti2SendClosed(a);gti2ClosedCallback(a,0);func_0205d164(a);
}else {M2C_FIELD(a,s32 *,12)=6;func_0205c8c8(a);}
}

void gti2MarkConnectionClosed(void *p,...) {
void func_02048f54(s32,void **);void Vector_AddItem(s32,void **);
if(M2C_FIELD(p,s32 *,12)==7)return;
M2C_FIELD(p,s32 *,12)=7;
func_02048f54(M2C_FIELD(M2C_FIELD(p,void **,8),s32 *,12),&p);
Vector_AddItem(M2C_FIELD(M2C_FIELD(p,void **,8),s32 *,16),&p);
}

void func_0205acc8(void *p) {
void gpiFree(void *);void Vector_Free(void *);void *q;
q=M2C_FIELD(p,void **,56);if(q)gpiFree(q);
q=M2C_FIELD(p,void **,68);if(q)gpiFree(q);
q=M2C_FIELD(p,void **,80);if(q)gpiFree(q);
q=M2C_FIELD(p,void **,92);if(q)Vector_Free(q);
q=M2C_FIELD(p,void **,96);if(q)Vector_Free(q);
q=M2C_FIELD(p,void **,152);if(q)Vector_Free(q);
q=M2C_FIELD(p,void **,156);if(q)Vector_Free(q);
gpiFree(p);
}

void Gt2CreateSocket(s32 a,s32 b,s32 c,s32 d,s32 e) {
void gti2CreateSocket(s32,s32,s32,s32,s32);
gti2CreateSocket(a,b,c,d,e);
}

void func_0205ad60(M2C_UNK arg0) {
    void GT2NotifyConnectionClosed();
    M2C_UNK gti2FreeSocket(M2C_UNK);
    GT2NotifyConnectionClosed();
    gti2FreeSocket(arg0);
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

void Gt2SocketSetConnectAttempt(void) {
    M2C_UNK gti2SocketSetConnectAttempt();
    gti2SocketSetConnectAttempt();
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
void gpiSleep(s32);s32 func_0205a830(s32,void **);s32 func_0205a890(void *,s32,s32,s32);void func_0205d164(s32);s32 gt2StringToAddress(s32,u32 *,u16 *);
void *p;u32 ip;u16 port;s32 result,done;
if(!gt2StringToAddress(c,&ip,&port)||!ip||!port)return 4;
if(((((ip<<24)&0xff000000)|(((ip<<8)&0xff0000)|((u8)(ip>>24)|((ip>>8)&0xff00))))&0xe0000000)==0xe0000000)return 4;
result=func_0205a830(a,&p);if(result)return result;
M2C_FIELD(p,s32 *,32)=f;
result=func_0205a890(p,d,e,g);if(result){func_0205d164((s32)p);return result;}
if(!h){if(b)*b=p;return 0;}
M2C_FIELD(p,s32 *,36)++;
do{func_0205ad78(a);if(M2C_FIELD(p,s32 *,12)>=5)done=1;else done=0;if(!done)gpiSleep(1);}while(!done);
M2C_FIELD(p,s32 *,36)--;
if(M2C_FIELD(p,s32 *,12)==5)*b=p;
return M2C_FIELD(p,s32 *,24);
}

void func_0205af48(void *a,s32 b,s32 c,s32 d) {
s32 Vector_GetCount(s32);
void func_0205d70c(s32 *,s32 *);
void func_0205a424(void *,s32,s32,s32,s32);
void func_0205cc20(void *,s32,s32,s32);
if(M2C_FIELD(a,s32 *,12)!=5)return;
func_0205d70c(&b,&c);
if(Vector_GetCount(M2C_FIELD(a,s32 *,0x98))) {func_0205a424(a,0,b,c,d);return;}
func_0205cc20(a,b,c,d);
}

void GT2FailConnectionAttempt(M2C_UNK arg0) {
    M2C_UNK func_0205ac1c(M2C_UNK, M2C_UNK);
    func_0205ac1c(arg0, 1);
}

void func_0205afdc(s32 *arg0) {
    GT2FailConnectionAttempt(*arg0);
}

void GT2NotifyConnectionClosed(void *a) {
extern s32 data_0213e110;
void Vector_ForEach(s32,void (*)(s32 *),s32);
void func_0205afdc(s32 *);
if(data_0213e110==1)return;
data_0213e110=1;
Vector_ForEach(M2C_FIELD(a,s32 *,12),func_0205afdc,0);
data_0213e110=0;
}

u16 GT2SocketPort(void *arg0) {
    return M2C_FIELD(arg0, u16 *, 8);
}

s32 func_0205b038(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x54) - M2C_FIELD(arg0, s32 *, 0x58);
}

s32 GT2SocketHandle(s32 *arg0) {
    return *arg0;
}

void Gt2SocketSetUnrecognizedCallback(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x30) = arg1;
}

void func_0205b058(void *a,s32 b) {
M2C_UNK AssertFailed(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
extern M2C_UNK data_020ff7ec,data_020ff7e0,data_020ff7b0;
if(!a)AssertFailed(&data_020ff7ec,&data_020ff7e0,&data_020ff7b0,0x1a3);
M2C_FIELD(a,s32 *,0x40)=b;
}

s32 func_0205b094(void *arg0) {
    M2C_UNK AssertFailed(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_020ff7c8;
    extern M2C_UNK data_020ff7e0;
    extern M2C_UNK data_020ff7ec;
    if (arg0 == NULL) {
        AssertFailed(&data_020ff7ec, &data_020ff7e0, &data_020ff7c8, 0x1AA);
    }
    return M2C_FIELD(arg0, s32 *, 0x40);
}

s32 Gt2ReadShort(u8 *a,s32 b) {u16 n=(a[b]<<8)&0xff00;return (u16)n|a[b+1];}

void func_0205b0ec(u8 *a,s32 b,s32 c){a[b]=c>>8;a[b+1]=c;}

s16 Gt2CompareSequence(s32 arg0, s32 arg1) {
    return (s16) (arg0 - arg1);
}

s32 func_0205b110(M2C_UNK a,M2C_UNK b,M2C_UNK c) {
s32 Gt2ConnectionCallCallback(s32,s32,s32,s32);s32 gti2ClosedCallback(s32,s32);
s32 n=M2C_FIELD(a,s32 *,12);
if(n<5){
if(M2C_FIELD(a,s32 *,16)){gti2MarkConnectionClosed((void *)a);if(!Gt2ConnectionCallCallback(a,b,0,0))return 0;}
else {if(n==4)M2C_FIELD(a,s32 *,20)=1;gti2MarkConnectionClosed((void *)a);}
}else if(n!=7){gti2MarkConnectionClosed((void *)a);if(!gti2ClosedCallback(a,c))return 0;}
return 1;
}

s32 Gt2CloseConnection(M2C_UNK arg0) {
    M2C_UNK func_0205b110(M2C_UNK, M2C_UNK, M2C_UNK);
    return func_0205b110(arg0, 7, 2);
}

s32 gti2SendClosedAndClose(M2C_UNK arg0) {
    s32 gti2SendClosed();
    if (gti2SendClosed() == 0) {
        return 0;
    }
    return func_0205b110(arg0, 1, 4);
}

/* Drop the leading entries of the sorted list a->list whose key is below b,
   then rebase every remaining entry's index by the first entry's value and
   delete that many leading items from the object's backing store at a+0x50. */
s32 Gt2AckSentData(void *a,s32 b){
void *Vector_GetItem(s32,s32);
s32 n,i,removed; s32 *p;
n=Vector_GetCount(M2C_FIELD(a,s32 *,0x60));if(!n)return 1;
for(i=0;i<n;i++){if(Gt2CompareSequence(M2C_FIELD(Vector_GetItem(M2C_FIELD(a,s32 *,0x60),i),u16 *,8),b)>=0)break;}
if(!i)return 1;
while(i--){Vector_RemoveItem(M2C_FIELD(a,s32 *,0x60),i);}
n=Vector_GetCount(M2C_FIELD(a,s32 *,0x60));if(!n){M2C_FIELD(a,s32 *,0x58)=0;return 1;}
removed=*(s32 *)Vector_GetItem(M2C_FIELD(a,s32 *,0x60),0);
for(i=0;i<n;i++){p=Vector_GetItem(M2C_FIELD(a,s32 *,0x60),i);*p-=removed;}
gti2RemoveFromBuffer((u8 *)a+0x50,0,removed);return 1;}

s32 func_0205b2e0(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 Vector_GetCount(s32);
    s32 Gt2ConnectionCallMessageCallback(void *, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 gti2ReceiveFilterCallback(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0xC);
    if ((temp_r0 != 5) && (temp_r0 != 6)) {
        return 1;
    }
    if (Vector_GetCount(M2C_FIELD(arg0, s32 *, 0x9C)) != 0) {
        if (gti2ReceiveFilterCallback(arg0, 0, arg1, arg2, 0) != 0) {
            var_r0 = 1;
        } else {
            var_r0 = 0;
        }
        return var_r0;
    }
    if (Gt2ConnectionCallMessageCallback(arg0, arg1, arg2, 0) != 0) {
        return 1;
    }
    return 0;
}

/* Handle command 0 (application data) received on a GT2 control channel: hand the
   payload to the connection's receive filters, or to its message callback when it
   has no filters, flagged as coming from the control channel. A connection that is
   neither connected nor closing is closed instead of receiving the data. */
s32 gti2HandleDataCommand(void *connection,s32 message,s32 length) {
s32 Vector_GetCount(s32);
s32 Gt2ConnectionCallMessageCallback(void *,s32,s32,s32);
s32 gti2ReceiveFilterCallback(void *,s32,s32,s32,s32);
s32 state=M2C_FIELD(connection,s32 *,GT2_CONNECTION_STATE),r;
if(state!=GT2_STATE_CONNECTED&&state!=GT2_STATE_PEER_CLOSED){if(!Gt2CloseConnection((s32)connection))return 0;}
else {
if(Vector_GetCount(M2C_FIELD(connection,s32 *,GT2_CONNECTION_FILTERS))){if(gti2ReceiveFilterCallback(connection,0,message,length,1))r=1;else r=0;return r;}
if(!Gt2ConnectionCallMessageCallback(connection,message,length,1))return 0;
}
return 1;
}

s32 func_0205b41c(void *a,void *b,s32 c) {
void gti2ComputeResponse(void *,void *);void gti2GetChallenge(void *);
s32 func_0205c6f4(void *,void *,void *);
u8 x[32],y[32];
if(M2C_FIELD(a,s32 *,12)!=2)return Gt2CloseConnection((s32)a)!=0;
if(c<32)return Gt2CloseConnection((s32)a)!=0;
gti2ComputeResponse(x,b);gti2GetChallenge(y);gti2ComputeResponse((u8 *)a+0x68,y);
if(!func_0205c6f4(a,x,y))return 0;
M2C_FIELD(a,s32 *,12)=3;return 1;
}

/* Client side of the GT2 handshake: handle the server's CONNECT_ACCEPT (the
 * response to our challenge plus the server's own challenge) and answer it with
 * our challenge response and the data queued for this connection. */
s32 gti2HandleConnectAccept(void *connection,void *message,s32 length) {
void gti2ComputeResponse(void *,void *);s32 gti2CheckResponse(void *,void *);s32 gti2SendClientResponse(void *,void *,s32,s32);
u8 response[32];
if(M2C_FIELD(connection,s32 *,GT2_CONNECTION_STATE)!=GT2_STATE_AWAIT_CONNECT_ACCEPT)return Gt2CloseConnection((s32)connection)!=0;
if(length<GT2_CONNECT_ACCEPT_SIZE)return Gt2CloseConnection((s32)connection)!=0;
if(!gti2CheckResponse(message,(u8 *)connection+GT2_CONNECTION_RESPONSE))return Gt2CloseConnection((s32)connection)!=0;
gti2ComputeResponse(response,(u8 *)message+GT2_RESPONSE_SIZE);
if(!gti2SendClientResponse(connection,response,M2C_FIELD(connection,s32 *,GT2_CONNECTION_DATA),M2C_FIELD(connection,s32 *,GT2_CONNECTION_DATA_LEN)))return 0;
if(M2C_FIELD(connection,void **,GT2_CONNECTION_DATA)){gpiFree(M2C_FIELD(connection,void **,GT2_CONNECTION_DATA));M2C_FIELD(connection,void **,GT2_CONNECTION_DATA)=0;}
M2C_FIELD(connection,s32 *,GT2_CONNECTION_STATE)=GT2_STATE_AWAIT_SERVER_ACCEPT;return 1;
}

/* Validate an incoming client's response and pass its payload to the connection-attempt callback. */
s32 gti2HandleClientResponse(void *connection, s32 message, s32 length) {
    s32 gti2CheckResponse(void *, void *); s32 gti2SendClosed(void *); s32 GetTickCountMs(void); s32 Gt2InvokeConnectAttempt(void *, void *, s32, u16, s32, s32, s32);
    if (M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) != GT2_STATE_AWAIT_CLIENT_RESPONSE) return Gt2CloseConnection((s32)connection) != 0;
    if (length < GT2_RESPONSE_SIZE) return Gt2CloseConnection((s32)connection) != 0;
    if (!gti2CheckResponse((void *)message, connection + GT2_CONNECTION_RESPONSE)) return Gt2CloseConnection((s32)connection) != 0;
    if (!M2C_FIELD(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), s32 *, GT2_SOCKET_CONNECT_ATTEMPT)) {
        if (!gti2SendClosed(connection)) return 0;
        gti2MarkConnectionClosed(connection); return 1;
    }
    M2C_FIELD(connection, s32 *, GT2_CONNECTION_STATE) = GT2_STATE_AWAIT_ACCEPT;
    return Gt2InvokeConnectAttempt(M2C_FIELD(connection, void **, GT2_CONNECTION_SOCKET), connection, M2C_FIELD(connection, s32 *, GT2_CONNECTION_IP), M2C_FIELD(connection, u16 *, GT2_CONNECTION_PORT), GetTickCountMs() - M2C_FIELD(connection, s32 *, GT2_CONNECTION_START_TIME), message + GT2_RESPONSE_SIZE, length - GT2_RESPONSE_SIZE) != 0;
}

s32 func_0205b6a0(void *a) {s32 Gt2ConnectionCallCallback();s32 v;if(M2C_FIELD(a,s32 *,12)!=1){if(Gt2CloseConnection(a))v=1;else v=0;return v;} M2C_FIELD(a,s32 *,12)=5;if(Gt2ConnectionCallCallback(a,0,0,0))return 1;return 0;}

s32 func_0205b6ec(void *a,s32 b,s32 c) {s32 Gt2ConnectionCallCallback();s32 gti2SendClosed();s32 v;if(M2C_FIELD(a,s32 *,12)!=1){if(Gt2CloseConnection(a))v=1;else v=0;return v;}gti2MarkConnectionClosed(a);if(!gti2SendClosed(a))return 0;if(Gt2ConnectionCallCallback(a,2,b,c))return 1;return 0;}

#pragma push
#pragma opt_propagation off
s32 func_0205b758(void *arg0) {
    if (gti2SendClosed() == 0) {
        return 0;
    }
    if (func_0205b110(arg0, 2, M2C_FIELD(arg0, s32 *, 0xC) != 6 ? 1 : 0) == 0) {
        return 0;
    }
    return 1;
}
#pragma pop
/* Increment the object's command counter and dispatch one of its commands (0-6). */
s32 Gt2DispatchCommand(void *object, s32 command, s32 param_a, s32 param_b) {
    s32 gti2HandleClientResponse(void *, s32, s32);
    M2C_FIELD(object, u16 *, 0x66)++;
    if (command == 0) { if (!gti2HandleDataCommand(object, param_a, param_b)) return 0; }
    else if (command == 1) { if (!func_0205b41c(object, (void *)param_a, param_b)) return 0; }
    else if (command == 2) { if (!gti2HandleConnectAccept(object, (void *)param_a, param_b)) return 0; }
    else if (command == 3) { if (!gti2HandleClientResponse(object, param_a, param_b)) return 0; }
    else if (command == 4) { if (!func_0205b6a0(object)) return 0; }
    else if (command == 5) { if (!func_0205b6ec(object, param_a, param_b)) return 0; }
    else if (command == 6) { if (!func_0205b758(object)) return 0; }
    return 1;
}

void func_0205b89c(void *arg0, void *arg1) {
    Gt2CompareSequence(M2C_FIELD(arg0, u16 *, 0xC), M2C_FIELD(arg1, u16 *, 0xC));
}

/* Enqueue an outgoing command: insert a header record (offset/size/command/
   sequence) for command/sequence into the send queue kept sorted by sequence,
   copy the payload into the session's ring buffer, and acknowledge any numbered
   sequence gap that was filled. Returns 0 to retry, 1 when finished; *error is
   set when the sequence already exists or the queue rejected the record. */
s32 Gt2QueuePendingCommand(void *session,s32 command,u16 sequence,void *data,s32 size,s32 *error){
s32 Vector_GetCount(s32);void *Vector_GetItem(s32,s32);s32 gti2GetBufferFreeSpace(void *);void func_020487fc(s32,void *,void *);void gti2AddToBuffer(void *,void *,s32);s32 func_0205caac(void *,u16,u16);
s32 count=Vector_GetCount(M2C_FIELD(session,s32 *,0x5c));s32 i;Command5B8B0 record;void *prev;s32 nextSequence;
for(i=0;i<count;i++){u16 queued=M2C_FIELD(Vector_GetItem(M2C_FIELD(session,s32 *,0x5c),i),u16 *,12);if(queued==sequence){*error=0;return 1;}if(Gt2CompareSequence(queued,sequence)>0)break;}
if(gti2GetBufferFreeSpace(session+0x44)<size){*error=1;return 1;}
record.offset=M2C_FIELD(session,s32 *,0x4c);record.size=size;record.command=command;record.sequence=sequence;
func_020487fc(M2C_FIELD(session,s32 *,0x5c),&record,func_0205b89c);
if(count+1!=Vector_GetCount(M2C_FIELD(session,s32 *,0x5c))){*error=1;return 1;}
gti2AddToBuffer(session+0x44,data,size);
if(count==0){if(!func_0205caac(session,M2C_FIELD(session,u16 *,0x66),(u16)(sequence-1)))return 0;}
else {nextSequence=M2C_FIELD(Vector_GetItem(M2C_FIELD(session,s32 *,0x5c),count),u16 *,12);if(nextSequence==sequence){
prev=Vector_GetItem(M2C_FIELD(session,s32 *,0x5c),count-1);
if((u16)Gt2CompareSequence(sequence,M2C_FIELD(prev,u16 *,12))>1){
if(!func_0205caac(session,(u16)(M2C_FIELD(prev,u16 *,12)+1),(u16)(sequence-1)))return 0;
}}}
*error=0;return 1;
}

void func_0205ba64(void *a,void *b,s32 c) {void *Vector_GetItem(s32,s32);s32 x,y,n,i,max;void *p;s32 v;x=M2C_FIELD(b,s32 *,0);y=M2C_FIELD(b,s32 *,4);max=0;Vector_RemoveItem(M2C_FIELD(a,s32 *,92),c);n=Vector_GetCount(M2C_FIELD(a,s32 *,92));i=0;if(n>0)do{p=Vector_GetItem(M2C_FIELD(a,s32 *,92),i);if(M2C_FIELD(p,s32 *,0)>x){M2C_FIELD(p,s32 *,0)-=y;v=M2C_FIELD(p,s32 *,0)+M2C_FIELD(p,s32 *,4);if(max<=v)max=v;}i++;}while(i<n);gti2RemoveFromBuffer((char*)a+68,x,y);}

s32 Gt2DispatchPendingCommands(void *a){s32 Vector_GetCount(s32);void *Vector_GetItem(s32,s32);s32 Gt2DispatchCommand(void *,s32,s32,s32);s32 i;void *p;restart:for(i=Vector_GetCount(M2C_FIELD(a,s32 *,92))-1;i>=0;i--){p=Vector_GetItem(M2C_FIELD(a,s32 *,92),i);if(M2C_FIELD(p,u16 *,12)==M2C_FIELD(a,u16 *,102)){if(Gt2DispatchCommand(a,M2C_FIELD(p,s32 *,8),M2C_FIELD(a,s32 *,68)+M2C_FIELD(p,s32 *,0),M2C_FIELD(p,s32 *,4))==0)return 0;func_0205ba64(a,p,i);goto restart;}}return 1;}

void Gt2NoteDataReceived(void *arg0) {
    s32 GetTickCountMs();
    if (M2C_FIELD(arg0, s32 *, 0x90) != 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x90) = 1;
    M2C_FIELD(arg0, s32 *, 0x94) = GetTickCountMs();
}

