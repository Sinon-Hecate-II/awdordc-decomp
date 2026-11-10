/* 23 functions from 0x0203AEB4 to 0x0203BE54 (main), found by ds-decomp. */
#include "common.h"

s32 func_0203aeb4(s32 a) {
 extern M2C_UNK data_0213d38c; s32 GetSessionPlayerId(s32);
 s32 i;
 if(!M2C_FIELD(&data_0213d38c,void **,8)||!a)return -1;
 for(i=0;i<M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0x14);i++) {
 if(a==GetSessionPlayerId(i))return i;
 }return -1;
}

void func_0203af18(void) {
 extern M2C_UNK data_0213d38c; u64 GetSystemTick(void);
 u64 t; void *p=M2C_FIELD(&data_0213d38c,void **,8);
 if(!p)return;
 M2C_FIELD(p,s32 *,8)=0;
 t=GetSystemTick();
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u64 *,0xC)=t;
}

s32 func_0203af50(s32 a,void *b,void *c) {
 extern M2C_UNK data_0213d38c;
 s32 func_0203a660(void); s32 gpiSetStatusInfo(void *,s32,void *,void *);
 if(!M2C_FIELD(&data_0213d38c,void **,8)||!func_0203a660())return 0;
 if(a==-1)a=M2C_FIELD(*M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void ***,4),s32 *,0x214);
 if(!b)b=(u8 *)*M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void ***,4)+0x218;
 if(!c)c=(u8 *)*M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void ***,4)+0x318;
 return gpiSetStatusInfo(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),a,b,c);
}

void func_0203b000(s32 a) {
 extern M2C_UNK data_0213d38c; s32 func_0203a68c(void *,void *);
 u32 out[132]; void *p=M2C_FIELD(&data_0213d38c,void **,8); s32 n;
 if(M2C_FIELD(p,void **,0x44)&&M2C_FIELD(p,s32 *,0)!=1)
 M2C_FIELD(p,void (**)(s32,s32),0x44)(a,M2C_FIELD(p,s32 *,0x48));
 p=M2C_FIELD(&data_0213d38c,void **,8);
 if(!M2C_FIELD(p,void **,0x34))return;
 n=func_0203a68c((u8 *)M2C_FIELD(p,void **,0x18)+a*12,out+66);
 p=M2C_FIELD(&data_0213d38c,void **,8);
 M2C_FIELD(p,void (**)(s32,s32,void *,s32),0x34)(a,n,out+66,M2C_FIELD(p,s32 *,0x38));
}

void func_0203b088(void) {
    extern M2C_UNK data_0213d38c;
    M2C_FIELD(&data_0213d38c, s32 *, 8) = 0;
}

s32 func_0203b09c(void) {
 extern M2C_UNK data_0213d38c; u64 GetSystemTick(void);
 u64 func_02072088(u64,u64);
 s32 func_0204db50(void *);
 s32 r=0; void *p=M2C_FIELD(&data_0213d38c,void **,8);
 if(func_02072088((GetSystemTick()-M2C_FIELD(p,u64 *,0xC))<<6,0x82EA) >=300) {
 M2C_FIELD(p,s32 *,8)++;
 r=func_0204db50(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4));
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u64 *,0xC)=GetSystemTick();
 }
 return r;
}

void func_0203b128(void) {
 extern M2C_UNK data_0213d38c;
 if(!M2C_FIELD(&data_0213d38c,void **,8))return;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0)=0;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1E)=0;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1F)=0;
}

#pragma opt_strength_reduction off
/* Match the session's local player table against the GameSpy buddy list:
 * confirm entries that are already buddies, drop stale buddies, and request
 * a buddy connection for each player whose address is still unknown. Runs as
 * one step of the session update and stops early when a request is pending. */
void SyncSessionPlayerConnections(M2C_UNK *arg0,s32 playerCount){
extern M2C_UNK data_0213d38c;
s32 func_0204e184(void *,s32 *);s32 func_0204e1b4(void *,s32,s32);s32 func_0204e3b0(void *,s32);
u32 ReportNetError();s32 GetSessionPlayerId(s32);s32 func_02031e38(void *);void func_020326c4(void *,s32);void func_02031eb8(void *);
s32 func_0203b454(u8 *,s32,s32);s32 func_0204e2f4(void *,s32,s32 *);s32 DropSessionPlayer(s32);
s32 func_02039d98(void);s32 func_02032580(s32,s32);void func_020326f8(s32,void *,void *);
void HandlePeerConnectResult(s32,void *,s32);s32 func_0204dd0c(void *,s32,s32,s32,s32,void *,s32,s32,void (*)(s32,void *,s32),s32);
s32 i,remoteCount,remoteIndex;u32 buddyInfo[132];u32 peerAddress[6];s32 slot,profileId;u8 *a=(u8 *)arg0;
if(!M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1e)){
ReportNetError(func_0204e184(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),&remoteCount));
#pragma opt_loop_invariants off
for(remoteIndex=0;remoteIndex<remoteCount;remoteIndex++){
ReportNetError(func_0204e1b4(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),remoteIndex,(s32)buddyInfo));
for(slot=0;slot<playerCount;slot++){
if((s32)buddyInfo[0]==GetSessionPlayerId(slot)){
if(!func_02031e38(a+slot*12)){
func_020326c4(a+slot*12,buddyInfo[0]);func_02031eb8(a+slot*12);
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1d)=1;
}break;
}}
if(slot==playerCount){
ReportNetError(func_0204e3b0(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),buddyInfo[0]));
remoteCount--;remoteIndex--;
}}
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1e)=1;
}
while(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1c)<playerCount){
profileId=GetSessionPlayerId(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1c));
if(profileId){
if(!func_0203b454(a,M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1c),profileId)){
ReportNetError(func_0204e2f4(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),profileId,&remoteIndex));
if(remoteIndex==-1)DropSessionPlayer(profileId);
}
}else{
if(func_02032580(func_02039d98(),(s32)(a+M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1c)*12))==-1){
func_020326f8(func_02039d98(),a+M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1c)*12,peerAddress);
func_0204dd0c(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),0,0,0,0,peerAddress,0,0,HandlePeerConnectResult,M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1c));
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1e)=2;return;
}}
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1c)++;
}
}
#pragma opt_strength_reduction reset
void func_0203b3c4(void) {
 extern M2C_UNK data_0213d38c;
 void *p=M2C_FIELD(&data_0213d38c,void **,8);
 M2C_FIELD(p,void (**)(s32,u8,s32),0x2C)(0,M2C_FIELD(p,u8 *,0x1D),M2C_FIELD(p,s32 *,0x30));
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0)=2;
}

#pragma opt_propagation off
void func_0203b3fc(u8 *a,u32 b,u32 c){extern M2C_UNK data_0213d38c;void MI_CpuFill8(void*,s32);void *p=M2C_FIELD(&data_0213d38c,void **,8);if(!p)return;MI_CpuFill8(a+b*12,0);p=M2C_FIELD(&data_0213d38c,void **,8);if(M2C_FIELD(p,void (**)(u32,u32,u32),0x3c))M2C_FIELD(p,void (**)(u32,u32,u32),0x3c)(b,c,M2C_FIELD(p,u32*,0x40));}
#pragma opt_propagation reset
s32 func_0203b454(u8 *a,s32 b,s32 c) {
 extern M2C_UNK data_0213d38c; s32 GetSessionPlayerId(s32); s32 func_02031e38(void *);
 s32 i,x;
 for(i=0;i<b;i++) {
 x=GetSessionPlayerId(i);
 if(x&&x==c) {
 if(func_02031e38(a+b*12)&&!func_02031e38(a+i*12))func_0203b3fc(a,i,b);
 else func_0203b3fc(a,b,i);
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1D)=1;return 1;
 }
 }return 0;
}

s32 func_0203b500(u8 *a, s32 b, s32 c) {
    extern M2C_UNK data_0213d38c;
    s32 GetSessionPlayerId(s32);
    s32 func_02031e70(void *);
    s32 func_02031e38(void *);
    void func_020326c4(void *, s32);
    void func_02031eb8(void *);
    void func_0203b3fc(u8 *, u32, u32);

    s32 x, i, y, j;
    s32 result = -1;
    u8 *pj = a;
    u8 *pi = a;

    for (i = 0; i < b; i++, pi += 12, pj = pi) {
        x = GetSessionPlayerId(i);
        if (x == 0) {
            continue;
        }

        if (x == c) {
            result = i;
        }

        for (j = i + 1; j < b; j++) {
            pj = a + j * 12;
            y = GetSessionPlayerId(j);
            if (x != y) {
                continue;
            }

            if (func_02031e70(pi) != 2) {
                continue;
            }

            if (func_02031e70(pj) != 3) {
                continue;
            }

            func_020326c4(pi, x);

            if (func_02031e38(pj) == 0) {
                continue;
            }

            func_02031eb8(pi);
            func_0203b3fc(a, j, i);

            M2C_FIELD(M2C_FIELD(&data_0213d38c, void **, 8), u8 *, 0x1D) = 1;
        }
    }

    return result;
}

s32 DropSessionPlayer(s32 a) {
 extern M2C_UNK data_0213d38c; extern M2C_UNK data_020fc8ec;
 s32 func_0204df00(void *,s32,void *); u32 ReportNetError();
 s32 r=func_0204df00(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),a,&data_020fc8ec);
 ReportNetError(r); return r;
}

s32 func_0203b63c(s32 arg0,s32 arg1) {
extern M2C_UNK data_0213d38c;
s32 func_0203a660(void); s32 func_02039d98(void); s32 func_02032580(s32,s32);
s32 func_0204e2f4(void *,s32,s32 *); s32 func_0204e1b4(void *,s32,s32);
void *p=M2C_FIELD(&data_0213d38c,void **,8);
s32 b=arg1; s32 a=arg0; s32 out=0;
if(!p||!func_0203a660())return 0;
a=func_02032580(func_02039d98(),a);
if(a>0)if(func_0204e2f4(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),a,&out))return 0;
if(a<=0||out==-1)return 0;
return (u32)func_0204e1b4(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),out,b) <= 0;
}

u32 ReportNetError(u32 a,u32 unused,u32 off){void func_0203accc(u32,u32);u32 ret=a;u32 code=ret;if(ret==0)return 0;switch(ret){case 1:code=9;off=code-10;break;case 2:code=9;off=code-11;break;case 3:code=6;off=code-16;break;case 4:code=6;off=code-26;break;}func_0203accc(code,off+0xfffeeaa8);return ret;}

/* Callback for a pending GPI peer connection: matches the returned profile ids
 * to slots in the online-match session's player table, drops peers that are no
 * longer known, and marks the session ready for the next setup step. */
void HandlePeerConnectResult(s32 connection, void *result, s32 index) {
extern M2C_UNK data_0213d38c;
s32 func_02031e70(void *); void func_02031eb8(void *); void func_020326c4(void *,s32);
s32 func_0203b454(u8 *,s32,s32);s32 func_0204e2f4(void *,s32,s32 *);s32 DropSessionPlayer(s32);void func_0203b000(s32);
s32 peerIndex,entryOffset,slotOffset,entryBase;
if(M2C_FIELD(result,s32 *,0)==0 && M2C_FIELD(result,s32 *,4)!=0) {
slotOffset=index*MATCH_SESSION_PLAYER_SIZE;
if(func_02031e70(((u8 *)M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,MATCH_SESSION_PLAYERS)+slotOffset))!=0) {
if(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,MATCH_SESSION_STATUS)!=1)return;
peerIndex=0;if(M2C_FIELD(result,s32 *,4)>0){entryOffset=0;do {
if(func_0203b454(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,MATCH_SESSION_PLAYERS),index,M2C_FIELD((u8 *)M2C_FIELD(result,void **,0xc)+entryOffset,s32 *,0))) {
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,MATCH_SESSION_CURSOR)++;
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,MATCH_SESSION_STATE)=1;
M2C_FIELD(result,s32 *,8)=0x601;
return;
}

peerIndex++;entryOffset+=0xac;
}while(peerIndex<M2C_FIELD(result,s32 *,4));}
entryOffset=0;if(M2C_FIELD(result,s32 *,4)>0){entryBase=entryOffset;do {
s32 profileId;
((u32 (*)(u32))ReportNetError)(func_0204e2f4((void *)connection,M2C_FIELD((u8 *)M2C_FIELD(result,void **,0xc)+entryBase,s32 *,0),&profileId));
if(profileId==-1)DropSessionPlayer(M2C_FIELD((u8 *)M2C_FIELD(result,void **,0xc)+entryBase,s32 *,0));
else {
func_020326c4(((u8 *)M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,MATCH_SESSION_PLAYERS)+slotOffset),M2C_FIELD(M2C_FIELD(result,void **,0xc),s32 *,0));
func_02031eb8(((u8 *)M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,MATCH_SESSION_PLAYERS)+slotOffset));func_0203b000(index);
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,MATCH_SESSION_CURSOR)++;M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,MATCH_SESSION_STATE)=1;
M2C_FIELD(result,s32 *,8)=0x601;M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,MATCH_SESSION_DIRTY)=1;return;
}

entryOffset++;entryBase+=0xac;
}while(entryOffset<M2C_FIELD(result,s32 *,4));}
if(M2C_FIELD(result,s32 *,8)!=0x600) {M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,MATCH_SESSION_CURSOR)++;M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,MATCH_SESSION_STATE)=1;}
return;
}
}
if(M2C_FIELD(result,s32 *,0)!=0) {
if(((u32 (*)(u32))ReportNetError)(M2C_FIELD(result,s32 *,0)))return;
return;
}
if(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,MATCH_SESSION_STATUS)==1 || !func_02031e70((u8 *)M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,MATCH_SESSION_PLAYERS)+index*MATCH_SESSION_PLAYER_SIZE)){
M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,MATCH_SESSION_CURSOR)++;M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,MATCH_SESSION_STATE)=1;
}
}

#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_propagation off
void func_0203b9a8(void **conn, void *buf, s32 unused) {
    extern M2C_UNK data_0213d38c;
    extern M2C_UNK data_020fc8f0;
    s32 func_02031e70(void *);
    s32 func_02039d98(void);
    void func_020326f8(s32, void *, void *);
    s32 StringCompare(void *, void *);
    s32 func_0204e074(void **, s32);
    void func_020326c4(void *, s32);
    s32 func_02032580(s32, s32);
    s32 func_0200567c(void *, s32, void *, ...);
    s32 func_0206527c(void *, void *, s32);
    s32 DropSessionPlayer(s32);
    s32 func_0204e0c4(void **, s32);

    u8 local[0x1c];
    void *data;
    void *p;
    s32 i;
    s32 found;
    s32 offset;
    s32 t2;
    s32 t;
    u32 v;

    found = 0;
    if (M2C_FIELD(buf, s32 *, 0) != 0) {
        return;
    }
    data = &data_0213d38c;
    i = 0;
    p = M2C_FIELD(data, void **, 8);
    if (M2C_FIELD(p, s32 *, 0x14) <= 0) {
        goto after_loop;
    }
    offset = 0;

    do {
        if (func_02031e70((u8 *)M2C_FIELD(p, void **, 0x18) + offset) == 1) {
            t = func_02039d98();
            func_020326f8(t, (u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset, local + 5);
            if (StringCompare(local + 5, (u8 *)buf + 0x8e) == 0) {
                func_0204e074(conn, M2C_FIELD(buf, s32 *, 4));
                func_020326c4((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset, M2C_FIELD(buf, s32 *, 4));
                found = 1;
            }
        } else {
            if (func_02031e70((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset) == 3 ||
                func_02031e70((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset) == 2) {
                t = func_02039d98();
                v = M2C_FIELD(t, u32 *, 0x24);
                func_0200567c(local, 5, &data_020fc8f0,
                              (v >> 24) & 0xff,
                              (v >> 16) & 0xff,
                              (v >> 8) & 0xff,
                              v & 0xff);
                t2 = M2C_FIELD(buf, s32 *, 4);
                t = func_02039d98();
                if (t2 == func_02032580(t, (s32)((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset))) {
                    if (func_0206527c(local, (u8 *)buf + 0x97, 4) == 0) {
                        func_0204e074(conn, t2);
                        found = 1;
                    }
                }
            }
        }
        p = M2C_FIELD(data, void **, 8);
        offset += 0xc;
        i++;
    } while (i < M2C_FIELD(p, s32 *, 0x14));

after_loop:
    if (found) {
        DropSessionPlayer(M2C_FIELD(buf, s32 *, 4));
    } else {
        func_0204e0c4(conn, M2C_FIELD(buf, s32 *, 4));
    }
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
#pragma opt_propagation reset

void func_0203bb58(s32 unused, void *r10) {
    extern M2C_UNK data_0213d38c;
    s32 func_02031e70(void *);
    s32 func_02039d98(void);
    void func_020326f8(s32, void *, void *);
    s32 StringCompare(void *, void *);
    void func_020326c4(void *, s32);
    void func_02031eb8(void *);
    s32 func_02032580(s32, s32);
    s32 func_02031e38(void *);
    s32 func_0203b500(u8 *, s32, s32);
    void func_0203b000(s32);

    u8 bufstore[0x18];
    void *data;
    void *buf;
    s32 i;
    s32 moved;
    s32 other;
    s32 offset;
    s32 one;
    s32 t, res;

    moved = 0;
    other = 0;
    if (M2C_FIELD(r10, s32 *, 0) != 0) {
        return;
    }
    data = &data_0213d38c;
    i = 0;
    if (M2C_FIELD(M2C_FIELD(data, void **, 8), s32 *, 0x14) <= 0) {
        goto after_loop;
    }
    offset = 0;
    one = 1;

    do {
        buf = bufstore;
        t = func_02031e70((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset);
        if (t == 1) {
            t = func_02039d98();
            func_020326f8(t, (u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset, buf);
            if (StringCompare(buf, (u8 *)r10 + 0x8e) == 0) {
                func_020326c4((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset, M2C_FIELD(r10, s32 *, 4));
                func_02031eb8((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset);
                moved = one;
            }
        } else {
            if (func_02031e70((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset) == 3 ||
                func_02031e70((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset) == 2) {
                t = func_02039d98();
                res = func_02032580(t, (s32)((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset));
                if (M2C_FIELD(r10, s32 *, 4) == res) {
                    if (func_02031e38((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset) == 1) {
                        other = 1;
                    } else {
                        func_020326c4((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset, M2C_FIELD(r10, s32 *, 4));
                        func_02031eb8((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18) + offset);
                        moved = 1;
                    }
                }
            }
        }
        i++;
        offset += 0xc;
    } while (i < M2C_FIELD(M2C_FIELD(data, void **, 8), s32 *, 0x14));

after_loop:
    if (moved == 0) {
        return;
    }

    res = func_0203b500((u8 *)M2C_FIELD(M2C_FIELD(data, void **, 8), void **, 0x18),
                        M2C_FIELD(M2C_FIELD(data, void **, 8), s32 *, 0x14),
                        M2C_FIELD(r10, s32 *, 4));
    if (other == 0) {
        func_0203b000(res);
    }
    M2C_FIELD(M2C_FIELD(&data_0213d38c, void **, 8), u8 *, 0x1d) = 1;
}

s32 func_0203bcf8(void) {
 extern M2C_UNK data_0213d38c;
 return M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0x20);
}

void func_0203bd0c(void) {
    M2C_UNK func_0205d8f4();
    extern M2C_UNK gConnectionMgr;
    if (M2C_FIELD(&gConnectionMgr, s32 *, 0x10) != 0) {
        M2C_FIELD(&gConnectionMgr, s32 *, 0xC) = 1;
        return;
    }
    func_0205d8f4();
}

s32 func_0203bd34(void) {
    s32 func_0203bd54();
    M2C_UNK func_020418c4();
    if (func_0203bd54() == 0) {
        return 0;
    }
    func_020418c4();
    return 1;
}

s32 func_0203bd54(void) {
    s32 HasNetError();
    s32 func_02038f6c();
    void *GetConnection();
    if (HasNetError() != 0) {
        return 0;
    }
    if ((GetConnection() == NULL) || (func_02038f6c() != 5) || (M2C_FIELD(GetConnection(), u8 *, 0x1A9) != 0)) {
        return 0;
    }
    return 1;
}

s32 func_0203bda0(void (*callback)(s32),s32 arg) {
s32 HasNetError(void);void *GetConnection(void);s32 func_02038f6c(void);void func_0203e410(void);
void *p;
if(HasNetError()!=0||!GetConnection()||M2C_FIELD(GetConnection(),u8 *,0x15)!=2||(func_02038f6c()!=5&&func_02038f6c()!=6))return 0;
if(M2C_FIELD(GetConnection(),s32 *,0x1a0)==10){
p=GetConnection();M2C_FIELD(p,u8 *,0x16)=M2C_FIELD(GetConnection(),u8 *,0xd);
func_0203e410();if(callback)callback(arg);
}else{
M2C_FIELD(GetConnection(),void (**)(s32),0x47c)=callback;
M2C_FIELD(GetConnection(),s32 *,0x480)=arg;
M2C_FIELD(GetConnection(),u8 *,0x1ae)=1;
}return 1;
}

