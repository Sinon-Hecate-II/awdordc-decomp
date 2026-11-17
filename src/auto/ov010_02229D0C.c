/* 47 functions from 0x02229D0C to 0x0222A9DC (ov010), found by ds-decomp. */
#include "common.h"
#include "string_storage.h"
typedef struct { u8 value; } UnkA750Flag;
typedef struct { u32 flag:1; u32 rest:31; } UnkA750Bits;
static inline void *GetTextA320(void *s) { if (!((UnkA750Bits *)s)->flag) return (u8 *)s+1; return M2C_FIELD(s,void **,8); }

void func_ov010_02229d0c(s32 arg0) {
extern M2C_UNK gOv010OnlineSession;
M2C_FIELD(&gOv010OnlineSession, void **, 0x18) = NULL;
}

void func_ov010_02229d20(void *arg0) {
    M2C_UNK func_ov010_02229c0c(void *, s32);
    func_ov010_02229c0c(arg0 + 0x38, M2C_FIELD(arg0, s32 *, 0x34));
}

void func_ov010_02229d34(s32 arg0) {
    M2C_UNK func_ov010_02229c74(s32);
    func_ov010_02229c74(arg0 + 0x38);
}

void func_ov010_02229d44(s32 arg0) {
    void func_ov010_02229d0c(s32);
    func_ov010_02229d0c(arg0 + 0x38);
}

M2C_UNK **func_ov010_02229d54(s32 arg0, M2C_UNK arg1) {
M2C_UNK **CreateSpriteObject(M2C_UNK *, M2C_UNK);
s32 IsOnlineSessionFlagSet(M2C_UNK);
extern M2C_UNK data_ov010_0222c250;
extern M2C_UNK data_ov010_0222c394;
M2C_UNK **temp_r0;
if (IsOnlineSessionFlagSet(3) == 0) return NULL;
temp_r0 = CreateSpriteObject(&data_ov010_0222c250, arg1);
if (temp_r0 != NULL) {
*temp_r0 = &data_ov010_0222c394;
M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
}
return temp_r0;
}

M2C_UNK func_ov010_02229d9c(s32 arg0) {
    s32 GetOnlineTransportPlayerId();
    s8 func_ov010_02229a94();
    extern M2C_UNK gOv010OnlineSession;
    if (IsOnlineSessionFlagSet(3) == 0) return;
    M2C_FIELD(arg0, u16 *, 2) = 1 << GetOnlineTransportPlayerId();
    M2C_FIELD(arg0, u8 *, 0) = func_ov010_02229a94();
    M2C_FIELD(&gOv010OnlineSession, s32 *, 0x24) = arg0;
}

s32 func_ov010_02229ddc(s32 arg0){s32 GetOnlinePeerMask();s32 GetNetErrorCode();extern M2C_UNK gOv010OnlineSession;s32 v,b,t;
if(M2C_FIELD(&gOv010OnlineSession,void * volatile *,0x24)){v=GetOnlinePeerMask();t=GetOnlinePeerMask();if(v!=(M2C_FIELD(M2C_FIELD(&gOv010OnlineSession,void **,0x24),u16 *,2)&t)){v=1;goto ready;}}v=0;ready:;
if(!M2C_FIELD(M2C_FIELD(&gOv010OnlineSession,void **,0x24),u8 *,0))v=0;
if(!IsOnlineSessionFlagSet(3))v=0;
if(GetNetErrorCode())b=1;else b=0;if(b)v=0;if(!v)func_ov010_02229bdc();return v;}

void func_ov010_02229e70(s32 arg0) {
extern M2C_UNK gOv010OnlineSession;
M2C_FIELD(&gOv010OnlineSession, void **, 0x24) = NULL;
}

void func_ov010_02229e84(s32 arg0) {
    M2C_UNK func_ov010_02229d9c(s32);
    func_ov010_02229d9c(arg0 + 0x34);
}

void func_ov010_02229e94(s32 arg0) {
    M2C_UNK func_ov010_02229ddc(s32);
    func_ov010_02229ddc(arg0 + 0x34);
}

void func_ov010_02229ea4(s32 arg0) {
    void func_ov010_02229e70(s32);
    func_ov010_02229e70(arg0 + 0x34);
}

M2C_UNK **func_ov010_02229eb4(M2C_UNK arg0) {
    M2C_UNK **CreateSpriteObject(M2C_UNK *, M2C_UNK);
    s32 IsOnlineSessionFlagSet(M2C_UNK);
    extern M2C_UNK data_ov010_0222c288;
    extern M2C_UNK data_ov010_0222c380;
    M2C_UNK **temp_r0;

    if (IsOnlineSessionFlagSet(3) == 0) {
        return NULL;
    }
    temp_r0 = CreateSpriteObject(&data_ov010_0222c288, arg0);
    if (temp_r0 != NULL) {
        *temp_r0 = &data_ov010_0222c380;
    }
    return temp_r0;
}

s32 func_ov010_02229ef4(s32 a,s32 b,s32 c,s32 d,s32 e){s32 func_02036ec0(s32,s32,s32,s32,s32,s32,s32);if(!IsOnlineSessionFlagSet(1))return 0;MI_CpuFill8(d,0,b);M2C_FIELD(e,s32 *,0)=0;return func_02036ec0(a,b,0,c,d,e,255);}

s32 func_ov010_02229f64(void) {
    u32 func_02036f14();
    s32 var_r4;
    u32 temp_r0;

    var_r4 = 0;
    temp_r0 = func_02036f14();
    switch (temp_r0) {
    case 0:
    case 2:
    case 3:
        break;
    default:
        break;
    case 1:
        var_r4 = 1;
        break;
    }
    return var_r4;
}

void func_ov010_02229f98(void *arg0) {
    M2C_UNK func_ov010_02229ef4(s32, s32, s32, s32, s32);
    func_ov010_02229ef4(M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), M2C_FIELD(arg0, s32 *, 0x3C), M2C_FIELD(arg0, s32 *, 0x40), M2C_FIELD(arg0, s32 *, 0x44));
}

void func_ov010_02229fc0(void) {
    M2C_UNK func_ov010_02229f64();
    func_ov010_02229f64();
}

void func_ov010_02229fcc(void) {

}

void *func_ov010_02229fd0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    extern M2C_UNK data_ov010_0222c2c0;
    extern M2C_UNK data_ov010_0222c3e4;
    void *temp_r0;

    if (IsOnlineSessionFlagSet(1) == 0) {
        return NULL;
    }
    temp_r0 = CreateSpriteObject(&data_ov010_0222c2c0, arg5);
    if (temp_r0 == NULL) {
        return temp_r0;
    }
    M2C_FIELD(temp_r0, M2C_UNK **, 0) = &data_ov010_0222c3e4;
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x3C) = arg2;
    M2C_FIELD(temp_r0, s32 *, 0x40) = arg3;
    M2C_FIELD(temp_r0, s32 *, 0x44) = arg4;
    return temp_r0;
}

void func_ov010_0222a038(void) {

}

s32 func_ov010_0222a03c(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void *func_ov010_0222a050(void *arg0) {
    M2C_UNK func_ov010_02229580();
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        func_ov010_02229580();
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
    }
    return arg0;
}

void *func_ov010_0222a078(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        func_ov010_02229580();
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
    }
    MemFree(arg0);
    return arg0;
}

s32 func_ov010_0222a0a8(s32 arg0) {
    M2C_UNK func_020741c4(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK func_ov010_02228a48;
    func_020741c4(arg0 + 0x34, 4, 8, &func_ov010_02228a48);
    return arg0;
}

s32 func_ov010_0222a0d0(s32 arg0) {
    M2C_UNK func_020741c4(s32, M2C_UNK, M2C_UNK, M2C_UNK *);
    extern M2C_UNK func_ov010_02228a48;
    func_020741c4(arg0 + 0x34, 4, 8, &func_ov010_02228a48);
    MemFree(arg0);
    return arg0;
}

void func_ov010_0222a100(void) {

}

s32 func_ov010_0222a104(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov010_0222a118(void) {

}

s32 func_ov010_0222a11c(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov010_0222a130(void) {

}

s32 func_ov010_0222a134(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

void func_ov010_0222a148(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
}

/* Per-frame network error check: while an error is pending, report it once — mark
   the session's error flag and hand the error code, detail and category to the
   owner's error callback, if it has one. */
void ReportNetErrorToCallback(void *self) {
    s32 GetNetErrorCode();
    s32 func_ov010_02228314(s32 *, u32 *);
    s32 errorDetail;
    u32 errorType;
    void (*callback)(s32, s32, u32, s32);
    s32 errorCode, reported;
    if (GetNetErrorCode()) reported = 1; else reported = 0;
    if (!reported) return;
    errorCode = func_ov010_02228314(&errorDetail, &errorType);
    if (IsOnlineSessionFlagSet(OV010_FLAG_ERROR)) return;
    switch (errorType) {
    case 0:
        break;
    case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        SetOnlineSessionFlag(OV010_FLAG_ERROR);
        callback = M2C_FIELD(self, void (**)(s32, s32, u32, s32), 0x34);
        if (!callback) return;
        callback(errorCode, errorDetail, errorType, M2C_FIELD(self, s32 *, 0x18));
        break;
    default:
        break;
    }
}

void func_ov010_0222a20c(s32 arg0) {
    void *func_01ffa3dc(void *);
    extern M2C_UNK data_ov010_0222c544, data_ov010_0222c900;
    void *temp_r0;
    temp_r0 = func_01ffa3dc(&data_ov010_0222c544);
    if (temp_r0 != NULL) {
        M2C_FIELD(temp_r0, void **, 0) = &data_ov010_0222c900;
        M2C_FIELD(temp_r0, s32 *, 0x34) = arg0;
    }
}

void func_ov010_0222a238(void) {
    M2C_UNK func_01ffaa5c();
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_ov010_0222c544;
    if (FindObjectByClass(&data_ov010_0222c544) == 0) {
        return;
    }
    func_01ffaa5c();
}

void func_ov010_0222a258(void) {
    M2C_UNK func_01ffaa6c();
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_ov010_0222c544;
    if (FindObjectByClass(&data_ov010_0222c544) == 0) {
        return;
    }
    func_01ffaa6c();
}

void func_ov010_0222a278(void) {
    M2C_UNK DeleteSpriteObject();
    s32 FindObjectByClass(M2C_UNK *);
    extern M2C_UNK data_ov010_0222c544;
    if (FindObjectByClass(&data_ov010_0222c544) == 0) {
        return;
    }
    DeleteSpriteObject();
}

u8 func_ov010_0222a298(void) {
    s32 IsScreenFadeActive();
    u8 var_r0;

    if (IsScreenFadeActive() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov010_0222a2b4(void *arg0) {
    s32 GetScreenFlag(M2C_UNK);
    M2C_UNK func_020ad348(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if ((M2C_FIELD(arg0, u8 *, 0x34) & 1) && (GetScreenFlag(0) == 0)) {
        func_020ad348(2, 8, 0, arg0);
    }
    if (!(M2C_FIELD(arg0, u8 *, 0x34) & 2)) {
        return;
    }
    if (GetScreenFlag(1) != 0) {
        return;
    }
    func_020ad348(2, 8, 1, arg0);
}

#pragma opt_common_subs off
#pragma scheduling on
void func_ov010_0222a320(void *a){
extern u8 data_ov010_0222c8f4[];extern s32 gCur3DSpriteEngine,g3DSpriteEngineSub,g3DSpriteEngineMain;
void *func_ov010_0222832c(void *,void *);void *GetLocalizedText(void *);void func_ov010_0222bc54(void *,void *);void func_0206f8b8(s32,void *,s32);void StringStorageConcat(void *,void *,void *);void func_ov010_0222bbe8(void *,void *);void func_0206fa14(void *);s32 FindTextLayer(void);void func_0208af20(void);void *CreateTextLayer(void *);void RenderTextLayer(void *,s32,s32,void *);void func_ov010_0222a238(void);void func_ov010_0222a278(void);
u8 sp[0x44];s32 v;
func_ov010_0222bc54((u8 *)a+0x44,GetLocalizedText(func_ov010_0222832c(M2C_FIELD(a,void **,0x3c),M2C_FIELD(a,void **,0x40))));
v=M2C_FIELD(a,s32 *,0x3c);if(v<0)v=-v;func_0206f8b8(v,sp+0x24,10);
StringStorageConcat(sp+0x18,(u8 *)a+0x44,data_ov010_0222c8f4);
StringStorageConcat(sp+0xc,sp+0x18,GetLocalizedText((void *)0x42000000));
StringStorageConcat(sp,sp+0xc,sp+0x24);
func_ov010_0222bbe8((u8 *)a+0x44,sp);func_0206fa14(sp);func_0206fa14(sp+0xc);func_0206fa14(sp+0x18);
if(!M2C_FIELD(a,s32 *,0x38))return;
switch(M2C_FIELD(a,s32 *,0x40)){
case 0:case 1:func_ov010_0222a238();return;
case 2:{
s32 old;void *text;s32 i;u32 current;s8 mode;void *p;
if(FindTextLayer())func_0208af20();
if(((UnkA750Bits *)((u8 *)a+0x44))->flag)text=M2C_FIELD(a,void **,0x4c);else text=(u8 *)a+0x45;
old=gCur3DSpriteEngine;i=0;do{
if(i==0)current=g3DSpriteEngineMain;else current=g3DSpriteEngineSub;
gCur3DSpriteEngine=current;mode=M2C_FIELD(a,s8 *,0x35);
if(mode==0&&current!=g3DSpriteEngineMain)continue;
if(mode==1&&current!=g3DSpriteEngineSub)continue;
if(mode==3&&current!=old)continue;
p=CreateTextLayer(a);RenderTextLayer(p,2,M2C_FIELD(a,u16 *,0x36)<<5,text);M2C_FIELD(p,u32 *,0x58)|=0x1400;
}while(++i<2);
gCur3DSpriteEngine=old;func_ov010_0222a238();return;
}
case 3:case 4:case 5:case 6:{
s32 old;void *text;s32 i;u32 current;s8 mode;void *p;
if(FindTextLayer())func_0208af20();
if(((UnkA750Bits *)((u8 *)a+0x44))->flag)text=M2C_FIELD(a,void **,0x4c);else text=(u8 *)a+0x45;
old=gCur3DSpriteEngine;i=0;do{
if(i==0)current=g3DSpriteEngineMain;else current=g3DSpriteEngineSub;
gCur3DSpriteEngine=current;mode=M2C_FIELD(a,s8 *,0x35);
if(mode==0&&current!=g3DSpriteEngineMain)continue;
if(mode==1&&current!=g3DSpriteEngineSub)continue;
if(mode==3&&current!=old)continue;
p=CreateTextLayer(a);RenderTextLayer(p,2,M2C_FIELD(a,u16 *,0x36)<<5,text);M2C_FIELD(p,u32 *,0x58)|=0x1400;
}while(++i<2);
gCur3DSpriteEngine=old;func_ov010_0222a278();return;
}
case 7:{
s32 old;void *text;s32 i;u32 current;s8 mode;void *p;
if(FindTextLayer())func_0208af20();
if(((UnkA750Bits *)((u8 *)a+0x44))->flag)text=M2C_FIELD(a,void **,0x4c);else text=(u8 *)a+0x45;
old=gCur3DSpriteEngine;i=0;do{
if(i==0)current=g3DSpriteEngineMain;else current=g3DSpriteEngineSub;
gCur3DSpriteEngine=current;mode=M2C_FIELD(a,s8 *,0x35);
if(mode==0&&current!=g3DSpriteEngineMain)continue;
if(mode==1&&current!=g3DSpriteEngineSub)continue;
if(mode==3&&current!=old)continue;
p=CreateTextLayer(a);RenderTextLayer(p,0,M2C_FIELD(a,u16 *,0x36)<<5,text);M2C_FIELD(p,u32 *,0x58)|=0x1c00;
}while(++i<2);
gCur3DSpriteEngine=old;func_ov010_0222a278();return;
}
default:func_ov010_0222a238();return;}}
#pragma opt_common_subs reset
#pragma scheduling reset
void func_ov010_0222a694(void *arg0){u32 v;if(!M2C_FIELD(arg0,s32 *,0x38))return;v=M2C_FIELD(arg0,u32 *,0x40);switch(v){case 0:case 1:case 2:func_ov010_0222a258();return;default:func_ov010_0222a258();return;case 3:case 4:case 5:case 6:case 7:return;}}

void func_ov010_0222a6e4(void *arg0) {
    M2C_UNK func_020ad2a0(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if (GetScreenFlag(0) == 1) {
        func_020ad2a0(2, 8, 0, arg0);
        M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 1);
    }
    if (GetScreenFlag(1) != 1) {
        return;
    }
    func_020ad2a0(2, 8, 1, arg0);
    M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 2);
}

/* Builds the text string `out` as `first` (a stored text string, inline or on the
 * heap) followed by the plain string `last`: clears `out`, reserves room for both,
 * then inserts `first` at position 0 and `last` right after it. */
void StringStorageConcat(void *out, void *first, void *last) {
    s32 StringLength(void *);
    void *StringStorageReplace(void *, s32, s32, void *, void *, UnkA750Flag);
    u32 i, firstLen;
    void *firstData;
    s32 lastLen;
    UnkA750Flag flags[2];
    void *r;

    for (i = 0; i < 3; i++) ((u32 *)out)[i] = 0;
    lastLen = StringLength(last);
    if (((StringStorage *)first)->large.flag) {
        firstData = ((StringStorage *)first)->large.data;
        firstLen = ((StringStorage *)first)->large.length;
    } else {
        firstData = ((StringStorage *)first)->small.data;
        firstLen = ((StringStorage *)first)->small.length;
    }
    StringStorageReserve(out, firstLen + lastLen);
    r = StringStorageReplace(out, 0, 0, firstData, firstData + firstLen, flags[1]);
    StringStorageReplace(r, firstLen, 0, last, last + lastLen, flags[0]);
}

void func_ov010_0222a808(s8 a,u16 b,s32 c,s32 d,u32 e,void *f){extern M2C_UNK data_ov010_0222c58c,data_ov010_0222c914;void *func_01ffa444(void *,void *);void *p;u32 i;u32 *out;if(!c)return;p=func_01ffa444(&data_ov010_0222c58c,f);if(!p)return;M2C_FIELD(p,void **,0)=&data_ov010_0222c914;M2C_FIELD(p,u8 *,0x34)=0;M2C_FIELD(p,s8 *,0x35)=a;M2C_FIELD(p,u16 *,0x36)=b;M2C_FIELD(p,s32 *,0x38)=c;M2C_FIELD(p,s32 *,0x3c)=d;M2C_FIELD(p,u32 *,0x40)=e;out=p+0x44;for(i=0;i<3;i++)out[i]=0;}

void func_ov010_0222a880(void *arg0) {
    s32 GetScreenFlag(M2C_UNK);
    M2C_UNK func_020ad348(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if ((M2C_FIELD(arg0, u8 *, 0x34) & 1) && (GetScreenFlag(0) == 0)) {
        func_020ad348(2, 8, 0, arg0);
    }
    if (!(M2C_FIELD(arg0, u8 *, 0x34) & 2)) {
        return;
    }
    if (GetScreenFlag(1) != 0) {
        return;
    }
    func_020ad348(2, 8, 1, arg0);
}

void func_ov010_0222a8ec(void *a){M2C_UNK func_ov010_0222ba94(s32,u16,void *);if(!M2C_FIELD(a,volatile s32 *,0x38))return;func_ov010_0222a808(M2C_FIELD(a,s8 *,0x35),M2C_FIELD(a,u16 *,0x36),M2C_FIELD(a,s32 *,0x38),M2C_FIELD(a,s32 *,0x3c),M2C_FIELD(a,u32 *,0x40),a);
switch(M2C_FIELD(a,u32 *,0x40)){case 0:case 1:case 2:break;case 3:case 4:case 5:case 6:case 7:func_ov010_0222ba94(-1,M2C_FIELD(a,u16 *,0x36),a);break;default:break;}}

void func_ov010_0222a96c(void) {

}

void func_ov010_0222a970(void *arg0) {
    M2C_UNK func_020ad2a0(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if (GetScreenFlag(0) == 1) {
        func_020ad2a0(2, 8, 0, arg0);
        M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 1);
    }
    if (GetScreenFlag(1) != 1) {
        return;
    }
    func_020ad2a0(2, 8, 1, arg0);
    M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 2);
}

