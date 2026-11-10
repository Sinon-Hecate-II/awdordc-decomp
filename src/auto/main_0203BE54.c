/* 10 functions from 0x0203BE54 to 0x0203CB38 (main), found by ds-decomp. */
#include "common.h"

#pragma push
#pragma scheduling off
s8 func_0203be54(s8 arg0, s32 arg1, s32 arg2) {
    s32 func_02037694(M2C_UNK, s32);
    M2C_UNK func_020376d8(M2C_UNK);
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    s8 func_020427b4(void);
    M2C_UNK StringLength(s32);
    M2C_UNK StringCopy(M2C_UNK, s32);
    s32 StringCompare(void);
    M2C_UNK func_0205fdbc(s8, s32);
    extern u8 data_0213d3bc[];
    extern u8 data_0213d3bd[];
    extern u8 data_0213d3be[];
    extern u8 data_0213d3c0[];
    extern u8 data_0213d3c4[];
    s32 var_r6 = arg1;
    s32 var_r5 = arg2;
    s8 var_r7 = arg0;
    s32 temp_r4;
    s32 temp_r0;

    if (var_r6 == 0 || var_r5 == 0) {
        return 0;
    }
    if ((u32) var_r7 >= 0x64U && data_0213d3bc[(var_r7 - 0x64) * 0xC] != 0) {
        s32 off = (var_r7 - 0x64) * 0xC;
        if (*((volatile s32 *)(data_0213d3c0 + off)) != 0 && StringCompare() != 0) {
            return 0;
        }
    } else {
        var_r7 = func_020427b4();
        if ((u32) var_r7 == 0) {
            return 0;
        }
    }
    temp_r4 = (var_r7 - 0x64) * 0xC;
    data_0213d3bc[temp_r4] = var_r7;
    data_0213d3bd[temp_r4] = 0;
    *((u16 *)(data_0213d3be + temp_r4)) = 0;
    if (*((volatile s32 *)(data_0213d3c0 + temp_r4)) != 0) {
        func_020376d8(4);
    }
    temp_r0 = func_02037694(4, StringLength(var_r6) + 1);
    *((volatile s32 *)(data_0213d3c0 + temp_r4)) = temp_r0;
    if (temp_r0 == 0) {
        func_0203dc38(9, 0xFFFEC77F);
        return 0;
    }
    StringCopy(temp_r0, var_r6);
    *((volatile s32 *)(data_0213d3c4 + temp_r4)) = var_r5;
    func_0205fdbc(var_r7, *((volatile s32 *)(data_0213d3c0 + temp_r4)));
    return var_r7;
}
#pragma pop
s8 func_0203bf80(u32 arg0, s32 arg1, s32 arg2) {
    s32 func_02037694(M2C_UNK, s32);
    M2C_UNK func_020376d8(M2C_UNK);
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    s8 func_020427b4(void);
    M2C_UNK StringLength(s32);
    M2C_UNK StringCopy(M2C_UNK, s32);
    s32 StringCompare(void);
    M2C_UNK func_0205fdbc(s8, s32);
    extern u8 data_0213d3bc[];
    extern u8 data_0213d3bd[];
    extern u8 data_0213d3be[];
    extern u8 data_0213d3c0[];
    extern u8 data_0213d3c4[];
    s32 var_r6;
    s32 var_r5;
    u32 var_r7;
    s32 temp_r4;
    u8 *var_r8;
    s32 temp_r0;
    s32 temp_r3;

    var_r6 = arg1;
    var_r5 = arg2;
    var_r7 = arg0;
    if (var_r6 != 0 && var_r5 != 0) {
        if (var_r7 >= 0x64U) {
            temp_r3 = (var_r7 - 0x64) * 0xC;
            if (data_0213d3bc[temp_r3] != 0) {
                if (*((s32 *)(data_0213d3c0 + temp_r3)) != 0 && StringCompare() != 0) {
                    return 0;
                }
                goto block_11;
            }
        }
        var_r7 = (u32) func_020427b4();
        if (var_r7 == 0) {
            return 0;
        }
    block_11:
        temp_r4 = (var_r7 - 0x64) * 0xC;
        data_0213d3bc[temp_r4] = (s8) var_r7;
        data_0213d3bd[temp_r4] = 1;
        *((u16 *)(data_0213d3be + temp_r4)) = 0;
        if (*((s32 *)(data_0213d3c0 + temp_r4)) != 0) {
            func_020376d8(4);
        }
        temp_r0 = func_02037694(4, StringLength(var_r6) + 1);
        var_r8 = data_0213d3c0;
        *((s32 *)(var_r8 + temp_r4)) = temp_r0;
        if (temp_r0 == 0) {
            func_0203dc38(9, 0xFFFEC77F);
            return 0;
        }
        StringCopy(temp_r0, var_r6);
        *((s32 *)(data_0213d3c4 + temp_r4)) = var_r5;
        func_0205fdbc((s8) var_r7, *((s32 *)(var_r8 + temp_r4)));
        return (s8) var_r7;
    }
    return 0;
}

s32 func_0203c0b0(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_0203761c();
    void *GetConnection();
    s32 func_02060b68(s32, M2C_UNK, s32);
    s32 func_02061784(s32, M2C_UNK);
    s32 temp_r0;
    s32 var_r4;

    var_r4 = arg2;
    if ((GetConnection() == NULL) || (func_0203761c() != 0)) {
        return var_r4;
    }
    temp_r0 = func_02061784(M2C_FIELD(GetConnection(), s32 *, 0xE4), arg0);
    if (temp_r0 != 0) {
        var_r4 = func_02060b68(temp_r0, arg1, var_r4);
    }
    return var_r4;
}

void func_0203c110(s32 arg0,s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g) {
void *GetConnection(void);s32 SetConnectionState(s32);
void func_02044258(s32);void func_020427f4(void);void func_0203e570(s32);
void func_02007f8c(void *,s32,s32);
extern M2C_UNK gConnectionMgr;
void *p;
func_02044258(arg0);
M2C_FIELD(GetConnection(),s32 *,0)=a;
M2C_FIELD(GetConnection(),s32 *,4)=b;
M2C_FIELD(GetConnection(),s32 *,8)=c;
M2C_FIELD(GetConnection(),s32 *,16)=0;
M2C_FIELD(GetConnection(),s32 *,28)=0;
M2C_FIELD(GetConnection(),u16 *,26)=0;
M2C_FIELD(GetConnection(),s32 *,228)=0;
SetConnectionState(0);
M2C_FIELD(GetConnection(),u8 *,15)=0;
M2C_FIELD(GetConnection(),u8 *,25)=0;
M2C_FIELD(GetConnection(),u8 *,431)=0;
M2C_FIELD(GetConnection(),u16 *,438)=0;
M2C_FIELD(GetConnection(),s32 *,476)=0;
M2C_FIELD(GetConnection(),s32 *,512)=0;
M2C_FIELD(GetConnection(),s32 *,756)=d;
M2C_FIELD(GetConnection(),s32 *,760)=e;
M2C_FIELD(GetConnection(),s32 *,764)=f;
M2C_FIELD(GetConnection(),s32 *,768)=g;
func_02007f8c((u8 *)GetConnection()+0x304,0,64);
M2C_FIELD(GetConnection(),s32 *,836)=0;
M2C_FIELD(GetConnection(),s32 *,1124)=0;
M2C_FIELD(GetConnection(),s32 *,1128)=0;
M2C_FIELD(GetConnection(),s32 *,1140)=0;
M2C_FIELD(GetConnection(),s32 *,1144)=0;
M2C_FIELD(GetConnection(),s32 *,1148)=0;
M2C_FIELD(GetConnection(),s32 *,1152)=0;
p=GetConnection();
M2C_FIELD(p,s32 *,0x174)=0;M2C_FIELD(p,s32 *,0x178)=0;
func_020427f4();
M2C_FIELD(&gConnectionMgr,u8 *,0x1c)=0;
M2C_FIELD(&gConnectionMgr,u8 *,0x1d)=0;
M2C_FIELD(&gConnectionMgr,u16 *,0x1e)=0;
func_0203e570(0);
}

s32 func_0203c28c(s32 arg0){
void *GetConnection(void);
s32 func_0205b030(s32);s32 func_0205b048(s32);
s32 func_0205e670(void*,s32,s32,s32,s32,s32,s32,void*,void*,void*,void*,void*,void*,s32);
extern s32 func_02043a24,func_02043b6c,func_02043b70,func_02043b74,func_02043c18,func_02043c20,func_02043c2c,func_02043c4c,func_02043d00;
s32 i,result,a,b;void *p,*q;
if(M2C_FIELD(GetConnection(),s32*,16))return 0;
M2C_FIELD(GetConnection(),s32*,512)=arg0;
for(i=0;i<5;i++){
p=GetConnection();
a=func_0205b048(*M2C_FIELD(GetConnection(),s32**,4));
b=func_0205b030(*M2C_FIELD(GetConnection(),s32**,4));
q=GetConnection();
result=func_0205e670((u8*)p+16,a,b,M2C_FIELD(q,s32*,0x2f4),M2C_FIELD(GetConnection(),s32*,0x2f8),1,1,&func_02043a24,&func_02043b6c,&func_02043b70,&func_02043b74,&func_02043c18,&func_02043c20,0);
if(!result)break;
func_0205eacc(M2C_FIELD(GetConnection(),s32*,16));
M2C_FIELD(GetConnection(),s32*,16)=0;
if(result!=3 || i==4){func_0204309c(result);return result;}
}
M2C_FIELD(GetConnection(),s32*,28)=0;
M2C_FIELD(GetConnection(),s16*,26)=0;
func_0205e864(M2C_FIELD(GetConnection(),s32*,16),&func_02043c2c);
func_0205e834(M2C_FIELD(GetConnection(),s32*,16),&func_02043c4c);
func_0205e84c(M2C_FIELD(GetConnection(),s32*,16),&func_02043d00);
func_0205ea70(M2C_FIELD(GetConnection(),s32*,16));
return result;
}

void func_0203c428(s32 arg0,s32 arg1,s32 arg2,s32 arg3,s32 arg4,s32 arg5){
void *GetConnection(void);s32 SetConnectionState(s32);
s32 func_0203e908(s32,s32,M2C_UNK,M2C_UNK);
s32 func_0203ec48(void*,s32,s32,s32);
s32 StringLength(s32);s32 func_02037694(s32,s32);
s32 func_020613dc(s32,s32,s32,s32,s32,s32,s32,M2C_UNK*,s32);
s32 func_02043008(s32);
extern M2C_UNK gConnectionMgr,data_020fc8fc,data_020fc904,func_020432d4;
u8 text[256]; s32 len;void *p,*q,*r,*t; s32 value; void *state=&gConnectionMgr;
value=M2C_FIELD(state,s32*,8);
if(value){func_020376d8(4,value,0);M2C_FIELD(&gConnectionMgr,s32*,8)=0;}
if(arg1){
len=func_0203ec48(text,-1,32,3);
len=256-len-StringLength((s32)&data_020fc8fc);
value=func_02037694(4,len);
M2C_FIELD(&gConnectionMgr,s32*,8)=value;
if(!value){func_0203dc38(9,0xfffec77f);return;}
MI_CpuCopy8(arg1,value,len);
((u8*)M2C_FIELD(&gConnectionMgr,void**,8)+len)[-1]=0;
}
func_0203e908(0,arg0,arg2,arg3);
M2C_FIELD(GetConnection(),s32*,0x474)=arg4;
M2C_FIELD(GetConnection(),s32*,0x478)=arg5;
SetConnectionState(2);
if(!M2C_FIELD(GetConnection(),s32*,0xe4)){
t=GetConnection();q=GetConnection();r=GetConnection();
M2C_FIELD(t,s32*,0xe4)=func_020613dc(M2C_FIELD(q,s32*,0x2f4),M2C_FIELD(r,s32*,0x2f4),M2C_FIELD(GetConnection(),s32*,0x2f8),0,20,1,0,&func_020432d4,0);
}
if(!M2C_FIELD(GetConnection(),s32*,0xe4)&&func_02043008(5))return;
func_0203af50(3,&data_020fc904,0);
if(func_02043008(func_0203ea4c(M2C_FIELD(GetConnection(),s32*,0x200))))return;
if(!M2C_FIELD(GetConnection(),s32*,16))func_0203c28c(M2C_FIELD(GetConnection(),s32*,512));
ResetConnectionSync(0);
}

#pragma push
#pragma scheduling off
/* Begin joining an online match: store the connection mode and player list, create the
   peer connection, register the match keys (player id/format/version) and connect. */
void StartJoinMatch(s32 playerList, s32 listLength, u8 matchType, s32 flag, s32 eventCallback, s32 eventData, s32 resultCallback, s32 resultData) {
    void *GetConnection(void);
    s32 SetConnectionState(s32);
    s32 func_0203e908(s32, s32, M2C_UNK, M2C_UNK);
    s32 MI_CpuCopy8(M2C_UNK, void *, s32);
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    s32 func_02043008(s32);
    s32 func_020613dc(s32, s32, s32, s32, s32, s32, s32, M2C_UNK *, s32);
    M2C_UNK func_0200567c(void *, s32, void *, s32);
    M2C_UNK func_02037d78(void *, void *, void *, s32);
    M2C_UNK func_02037db0(void *, void *, void *, s32);
    M2C_UNK func_0203af50(M2C_UNK, M2C_UNK *, M2C_UNK);
    s32 func_02042f94(void);
    M2C_UNK func_0203c28c(s32);
    M2C_UNK TryConnectToPeer(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_0204084c(void);
    M2C_UNK ResetConnectionSync(M2C_UNK);
    s32 func_0203e410(void);
    extern M2C_UNK gConnectionMgr, data_020fc908, gKeyFME, data_020fc910, data_020fc914, gKeyMDF, gKeyVER, func_020432d4;
    u8 sp34[12];
    s32 sp14[8];
    void *p, *q;

    func_0203e908(1, matchType, eventCallback, eventData);
    *((u8 *)((p = GetConnection())) + 0x1A6) = (u8)(flag ? 1 : 0);
    q = GetConnection();
    M2C_FIELD(q, s32 *, 0x474) = resultCallback;
    q = GetConnection();
    M2C_FIELD(q, s32 *, 0x478) = resultData;
    p = GetConnection();
    MI_CpuCopy8(playerList, (u8 *)p + 0x304, listLength);
    p = GetConnection();
    M2C_FIELD(p, s32 *, 0x344) = listLength;

    if (listLength == 0) goto error;
    {
        if (listLength < (s32)matchType && flag == 0) {
            s32 *gp = M2C_FIELD(&gConnectionMgr, s32 *, 0);
            if (gp == 0 || *(u8 *)gp == 0) goto error;
            {
                if (listLength < (s32)(((u8 *)gp)[1]) - 1) {
error:
                    func_0203dc38(10, 0);
                    goto done;
                }
            }
        }
        SetConnectionState(4);
        p = GetConnection();
        if (M2C_FIELD(p, s32 *, 0xE4) == 0) {
            void *p1 = GetConnection();
            void *p2 = GetConnection();
            void *p3 = GetConnection();
            void *p4 = GetConnection();
            s32 res;
            res = func_020613dc(M2C_FIELD(p2, s32 *, 0x2F4), M2C_FIELD(p3, s32 *, 0x2F4), M2C_FIELD(p4, s32 *, 0x2F8), 0,
                                 0x14, 1, 0, &func_020432d4, 0);
            M2C_FIELD(p1, s32 *, 0xE4) = res;
        }
            p = GetConnection();
            if (M2C_FIELD(p, s32 *, 0xE4) == 0) {
                if (func_02043008(5) != 0) {
                    goto done;
                }
            }
                func_0200567c(sp34, 12, &data_020fc908, matchType);
                func_02037d78(&gKeyFME, sp34, sp14, 0x2F);
                func_02037db0(&gKeyMDF, (flag != 0) ? &data_020fc910 : &data_020fc914, sp14, 0x2F);
                func_0200567c(sp34, 12, &data_020fc908, 3);
                func_02037db0(&gKeyVER, sp34, sp14, 0x2F);
                func_0203af50(4, sp14, 0);
                if (func_02042f94() != 0) {
                    goto done;
                }
    }

    p = GetConnection();
    if (M2C_FIELD(p, s32 *, 0x10) != 0) {
        goto tail;
    }
    p = GetConnection();
    if (func_0203c28c(M2C_FIELD(p, s32 *, 0x200)) != 0) {
        goto done;
    }
tail:
    TryConnectToPeer(0, 1, 0);
    if (func_0204084c() != 0) {
        goto done;
    }
    ResetConnectionSync(0);
done:
    ;
}
#pragma pop
void func_0203c878(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4) {
    M2C_UNK func_0203c28c(s32);
    M2C_UNK func_0203e410();
    M2C_UNK func_0203e908(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_02042f94();
    M2C_UNK SetConnectionState(M2C_UNK);
    extern M2C_UNK gConnectionMgr;
    void *temp_r4;

    func_0203e908(2, arg0, arg1, arg2);
    M2C_FIELD(GetConnection(), s32 *, 0x46C) = arg3;
    M2C_FIELD(GetConnection(), s32 *, 0x470) = arg4;
    temp_r4 = GetConnection();
    M2C_FIELD(temp_r4, s32 *, 0xF4) = (s32) M2C_FIELD(GetConnection(), s32 *, 0x200);
    M2C_FIELD(GetConnection(), s32 *, 0x2F0) = 1;
    M2C_FIELD(GetConnection(), s8 *, 0xE) = 0;
    M2C_FIELD(&gConnectionMgr, s8 *, 0x1D) = 0;
    SetConnectionState(0xA);
    func_0203e410();
    if (func_02042f94() != 0) {
        return;
    }
    if (M2C_FIELD(GetConnection(), s32 *, 0x10) != 0) {
        return;
    }
    func_0203c28c(M2C_FIELD(GetConnection(), s32 *, 0x200));
}

void func_0203c920(s32 arg0,M2C_UNK arg1,M2C_UNK arg2,s32 arg3,s32 arg4) {
s32 GetConnection(void);
s32 SetConnectionState(s32);
s32 func_0203e908(s32,s32,M2C_UNK,M2C_UNK);
M2C_UNK func_0203af50(M2C_UNK,M2C_UNK *,M2C_UNK);
M2C_UNK func_0204084c(void);
M2C_UNK func_02040878(s32,M2C_UNK);
s32 func_02043008(M2C_UNK);
s32 func_02042f94(void);
s32 func_0203c28c(s32);
s32 func_020613dc(s32,s32,s32,s32,s32,s32,s32,M2C_UNK *,s32);
extern M2C_UNK data_020fc904,func_020432d4;
void *p,*q,*r,*t;
func_0203e908(3,0,arg1,arg2);
M2C_FIELD(GetConnection(),s32 *,0x46c)=arg3;
M2C_FIELD(GetConnection(),s32 *,0x470)=arg4;
M2C_FIELD(GetConnection(),u8 *,0x17)=1;
p=GetConnection();
M2C_FIELD(p,s32 *,0x20)=M2C_FIELD(GetConnection(),s32 *,0x200);
M2C_FIELD(GetConnection(),s32 *,0xf4)=arg0;
SetConnectionState(4);
if(!M2C_FIELD(GetConnection(),s32 *,0xe4)){
t=GetConnection();q=GetConnection();r=GetConnection();
M2C_FIELD(t,s32 *,0xe4)=func_020613dc(M2C_FIELD(q,s32 *,0x2f4),M2C_FIELD(r,s32 *,0x2f4),M2C_FIELD(GetConnection(),s32 *,0x2f8),0,20,1,0,&func_020432d4,0);
}
if(!M2C_FIELD(GetConnection(),s32 *,0xe4)&&func_02043008(5))return;
func_0203af50(5,&data_020fc904,0);
if(func_02042f94())return;
if(!M2C_FIELD(GetConnection(),s32 *,0x10)&&func_0203c28c(M2C_FIELD(GetConnection(),s32 *,0x200)))return;
func_02040878(M2C_FIELD(GetConnection(),s32 *,0xf4),0);
if(func_0204084c())return;
}

void func_0203ca88(void *arg0) {
    M2C_UNK func_0205e87c();
    M2C_UNK func_0205ea70(s32);
    u32 temp_r0_2;
    u8 temp_r0;

    if (arg0 == NULL) {
        return;
    }
    func_0205e87c();
    if (M2C_FIELD(arg0, s32 *, 0xB4) != 0) {
        return;
    }
    temp_r0 = M2C_FIELD(GetConnection(), u8 *, 0x15);
    switch (temp_r0) {
    case 0:
    case 1:
        temp_r0_2 = M2C_FIELD(GetConnection(), u32 *, 0x1A0);
        switch (temp_r0_2) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
        case 11:
            func_0205ea70(M2C_FIELD(GetConnection(), s32 *, 0x10));
            break;
        default:
            break;
        }
        break;
    case 2:
        if (M2C_FIELD(GetConnection(), u32 *, 0x1A0) == 0xB) {
            func_0205ea70(M2C_FIELD(GetConnection(), s32 *, 0x10));
        }
        break;
    }
}

