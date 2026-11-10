/* 11 functions from 0x02040340 to 0x020411DC (main), found by ds-decomp. */
#include "common.h"
void *GetConnection(void);

#pragma opt_strength_reduction off
s32 func_02040340(s32 a, s32 b, s32 c, s32 d, s32 e) {
s32 func_0204e364(s32,s32); s32 func_020428bc(s32); void func_0205ea70(s32); s32 func_02040dc8(s32); void func_0204084c(s32);
extern u8 gConnectionMgr[];
s32 r; void *p;
switch(M2C_FIELD(GetConnection(),u8*,0x15)) {
case 1:
 if(!func_0204e364(M2C_FIELD(GetConnection(),s32*,0),a)){r=255;break;}
 if(!func_020428bc(a)){r=3;break;}
case 0:
 if(d!=M2C_FIELD(GetConnection(),u8*,0x15) || M2C_FIELD(GetConnection(),u8*,0x1a9)!=0 || (p=GetConnection(), M2C_FIELD(p,u8*,0x14)==M2C_FIELD(GetConnection(),u8*,0x16)) || (M2C_FIELD(GetConnection(),u8*,0x17)!=0 && (p=GetConnection(), M2C_FIELD(p,s32*,0x20)==M2C_FIELD(GetConnection(),s32*,0x200)))) {
 r=3;
 if(M2C_FIELD(GetConnection(),u8*,0x15)==0 && M2C_FIELD(M2C_FIELD(GetConnection(),void**,0x10),s32*,0xb4)==0 && M2C_FIELD(GetConnection(),u8*,0x17)!=0 && (p=GetConnection(),M2C_FIELD(p,s32*,0x20)==M2C_FIELD(GetConnection(),s32*,0x200))) func_0205ea70(M2C_FIELD(GetConnection(),s32*,0x10));
 break;
 }
 if(!((M2C_FIELD(GetConnection(),s32*,0x1a0)==3 || M2C_FIELD(GetConnection(),s32*,0x1a0)==4) && (M2C_FIELD(GetConnection(),s32*,0x1c)!=0 || M2C_FIELD(GetConnection(),u16*,0x1a)!=0)) || (b==0 && c==0)){r=4;break;}
 if(M2C_FIELD(GetConnection(),s32*,0x204)!=0) {
 if(a==M2C_FIELD(GetConnection(),s32*,0x204)){
 if(e!=0 || (M2C_FIELD(GetConnection(),s32*,0x200)<a && a!=M2C_FIELD(GetConnection(),s32*,0x208)))r=2;else r=255;
 }else{
 if(e!=0 || (M2C_FIELD(GetConnection(),s32*,0x200)<a && M2C_FIELD(GetConnection(),s32*,0x208)==0)) {
 func_02040dc8(M2C_FIELD(GetConnection(),s32*,0x204));
 if(((s32 (*)())func_0204084c)())return 255;
 r=2;
 }else r=3;
 }
 }else r=2;
 break;
case 2:
 if(!func_0204e364(M2C_FIELD(GetConnection(),s32*,0),a)){r=255;break;}
 if(d!=3 || (p=GetConnection(), M2C_FIELD(p,u8*,0x14)==M2C_FIELD(GetConnection(),u8*,0x16))){r=3;break;}
 if(gConnectionMgr[0x1c]==1 && gConnectionMgr[0x1d]==1){r=19;break;}
 if(!(M2C_FIELD(GetConnection(),s32*,0x1a0)==10 && (M2C_FIELD(GetConnection(),s32*,0x1c)!=0 || M2C_FIELD(GetConnection(),u16*,0x1a)!=0)) || (b==0 && c==0)){r=4;break;}
 r=2;
}
return r;
}

#pragma opt_strength_reduction off
s32 func_0204063c(s32 arg0, s32 arg1, u16 arg2) {
    s32 func_0203f058(M2C_UNK, M2C_UNK, s32, u16, s32, s32);
    void *GetConnection(void);
    void func_0205ea70(s32);
    u8 func_0204284c(void);
    void ResetConnectionSync(s32);
    s32 loc[2];
    s32 i, r;
    void *p, *q;

    if (M2C_FIELD(GetConnection(), u8 *, 0x17) != 0 && arg0 == M2C_FIELD(GetConnection(), s32 *, 0x20)) return 0;
    M2C_FIELD(GetConnection(), u8 *, 0x17) = 1;
    M2C_FIELD(GetConnection(), s32 *, 0x20) = arg0;
    M2C_FIELD(GetConnection(), s32 *, 0x1bc) = 0;
    M2C_FIELD(GetConnection(), s32 *, 0x1c8) = 0;
    func_0205ea70(M2C_FIELD(GetConnection(), s32 *, 0x10));
    M2C_FIELD(GetConnection(), s32 *, 0x204) = 0;
    p = GetConnection();
    M2C_FIELD((u8 *)p + ((M2C_FIELD(GetConnection(), u8 *, 0x14) + 1) << 2), s32 *, 0xf4) = arg0;
    p = GetConnection();
    M2C_FIELD((u8 *)p + ((M2C_FIELD(GetConnection(), u8 *, 0x14) + 1) << 2), s32 *, 0x24) = arg1;
    p = GetConnection();
    M2C_FIELD((u8 *)p + ((M2C_FIELD(GetConnection(), u8 *, 0x14) + 1) << 1), u16 *, 0xa4) = arg2;
    M2C_FIELD(GetConnection(), s32 *, 0x1b8) = arg1;
    M2C_FIELD((u8 *)GetConnection() + 0x100, u16 *, 0xb4) = arg2;
    p = GetConnection();
    q = GetConnection();
    M2C_FIELD((u8 *)p + (M2C_FIELD(q, u8 *, 0x14) + 1), u8 *, 0x2d0) = func_0204284c();
    loc[0] = arg0;
    p = GetConnection();
    loc[1] = M2C_FIELD((u8 *)p + (M2C_FIELD(GetConnection(), u8 *, 0x14) + 1), u8 *, 0x2d0);
    for (i = loc[1] - loc[1] + 1; i <= (s32)M2C_FIELD(GetConnection(), u8 *, 0x14); i++) {
        p = GetConnection();
        q = GetConnection();
        r = func_0203f058(7, M2C_FIELD((u8 *)p + (i << 2), s32 *, 0xf4), M2C_FIELD((u8 *)q + (i << 2), s32 *, 0x24), M2C_FIELD((u8 *)GetConnection() + (i << 1), u16 *, 0xa4), (s32)loc, 2);
        if (r) return r;
    }
    ResetConnectionSync(1);
    return 0;
}
#pragma opt_strength_reduction reset
void func_020407fc(s32 arg0,s32 *arg1) {
void func_02007e70(void *,void *,u32); void *GetConnection(void);
u32 n=*arg1+2;
if(n>2) func_02007e70(arg1+1,(u8 *)GetConnection()+0x350,(n-2)*4);
M2C_FIELD(GetConnection(),s32 *,0x348)=n-1;
M2C_FIELD(GetConnection(),s32 *,0x34c)=arg0;
}

void func_0204084c(s32 arg0) {
void func_02042f94(s32); void func_02043008(s32); void *GetConnection(void);
if(M2C_FIELD(GetConnection(),u8 *,0x15)==0) { func_02043008(arg0); return; }
func_02042f94(arg0);
}

s32 func_02040878(s32 arg0, s32 arg1) {
    s32 func_0203f058(M2C_UNK, M2C_UNK, s32, u16, s32, s32);
    u64 func_02007004(void);
    void *GetConnection(void);
    s32 func_02061784(s32, M2C_UNK);
    s32 func_02060c44(s32 *);
    s32 func_02060b68(s32, M2C_UNK, s32);
    u16 func_02060c4c(void *);
    extern M2C_UNK data_020fc958;
    s32 loc[3];
    void *p, *q;
    s32 u, slot, begin;

    if (arg1 != 0 || (M2C_FIELD(GetConnection(), s32 *, 0x1c) == 0 && M2C_FIELD(GetConnection(), u16 *, 0x1a) == 0)) {
        M2C_FIELD(GetConnection(), s32 *, 0x1bc) = 1;
        p = GetConnection();
        M2C_FIELD(p, u64 *, 0x1c0) = func_02007004();
        M2C_FIELD(GetConnection(), s32 *, 0xf4) = arg0;
        return 0;
    }
    if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 0) {
        u = func_02061784(M2C_FIELD(GetConnection(), s32 *, 0xe4), 0);
        p = GetConnection();
        M2C_FIELD(p, s32 *, 0xf4) = func_02060b68(u, (s32) &data_020fc958, 0);
        p = GetConnection();
        M2C_FIELD(p, s32 *, 0x24) = func_02060c44((s32 *) u);
        p = GetConnection();
        M2C_FIELD(p, u16 *, 0xa4) = func_02060c4c((void *) u);
        p = GetConnection();
        q = GetConnection();
        slot = 1;
        M2C_FIELD(p, s32 *, 0x204) = M2C_FIELD(q, s32 *, 0xf4);
    } else {
        if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 1) {
            M2C_FIELD(GetConnection(), s32 *, 0xf4) = arg0;
        }
        M2C_FIELD(GetConnection(), s32 *, 0x204) = arg0;
        loc[1] = M2C_FIELD(GetConnection(), s32 *, 0x1c);
        loc[2] = M2C_FIELD(GetConnection(), u16 *, 0x1a);
        slot = 3;
    }
    M2C_FIELD(GetConnection(), s32 *, 0x1c8) = 0x1770;
    p = GetConnection();
    M2C_FIELD(p, u64 *, 0x1cc) = func_02007004();
    M2C_FIELD(GetConnection(), s32 *, 0x1bc) = 0;
    begin = M2C_FIELD(GetConnection(), s32 *, 0x208) != 0 ? 11 : 1;
    loc[0] = M2C_FIELD(GetConnection(), u8 *, 0x15);
    q = GetConnection();
    p = GetConnection();
    return func_0203f058(begin, arg0, M2C_FIELD(q, s32 *, 0x24), M2C_FIELD(p, u16 *, 0xa4), (s32) &loc[0], slot);
}

s32 func_02040a28(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_02032580(void *, void *);
    s32 func_0204e2f4(void **, s32, s32 *);
    s32 func_0204e1b4(void **, s32, void *);
    s32 func_02037df0(s8 *, s8 *, s8 *, s32);
    s32 func_0206abd8(void *, s32, s32);
    s32 func_02039d98(void);
    s32 func_02032398(void *);
    u64 func_02007004(void);
    s32 func_02040878(s32, s32);
    extern M2C_UNK data_020fc90c;
    extern M2C_UNK data_020fc918;
    extern M2C_UNK data_020fc91c;

    s32 info[4];
    s32 tmp[4];
    u8 payload[0x208];
    s32 rec;
    s32 found;
    s32 next;
    s32 first;
    s32 i;
    s32 a;
    s32 b;
    s32 ver;
    s32 fme;
    s32 mdf;

    if (arg1 != 0) {
        next = M2C_FIELD(GetConnection(), u8 *, 0x1a5);
    } else {
        if (M2C_FIELD(GetConnection(), u8 *, 0x1a5) >= M2C_FIELD(GetConnection(), s32 *, 0x344) - 1) {
            next = 0;
        } else {
            next = M2C_FIELD(GetConnection(), u8 *, 0x1a5) + 1;
        }
    }
    found = 0;
    first = arg1 == 0;
    for (;;) {
        if (first || found) {
            M2C_FIELD(GetConnection(), u8 *, 0x1a5)++;
            if (M2C_FIELD(GetConnection(), u8 *, 0x1a5) >= M2C_FIELD(GetConnection(), s32 *, 0x344)) {
                M2C_FIELD(GetConnection(), u8 *, 0x1a5) = 0;
            }
        }
        if (found && next == M2C_FIELD(GetConnection(), u8 *, 0x1a5)) {
            M2C_FIELD(GetConnection(), s32 *, 0x1c8) = 3000;
            M2C_FIELD(GetConnection(), u64 *, 0x1cc) = func_02007004();
            M2C_FIELD(GetConnection(), s32 *, 0x1bc) = 0;
            return 0;
        }
        found = 1;
        rec = func_02032580(func_02039d98(),
            M2C_FIELD(GetConnection(), s32 *, 0x2fc) +
            12 * M2C_FIELD((u8 *)GetConnection() + M2C_FIELD(GetConnection(), u8 *, 0x1a5), u8 *, 0x304));
        if (rec == 0 || rec == -1) {
            continue;
        }
        if (((s32 (*)(void *))func_02032398)(
                M2C_FIELD(GetConnection(), s32 *, 0x2fc) +
                12 * M2C_FIELD((u8 *)GetConnection() + M2C_FIELD(GetConnection(), u8 *, 0x1a5), u8 *, 0x304)) == 0) {
            continue;
        }
        for (i = 1; i <= (s32)M2C_FIELD(GetConnection(), u8 *, 0xd); i++) {
            if (rec == M2C_FIELD((u8 *)GetConnection() + (i << 2), s32 *, 0xf4)) {
                break;
            }
        }
        if (i <= (s32)M2C_FIELD(GetConnection(), u8 *, 0xd)) {
            continue;
        }
        a = func_0204e2f4((void **)M2C_FIELD(GetConnection(), void **, 0), rec, &tmp[1]);
        b = func_0204e1b4((void **)M2C_FIELD(GetConnection(), void **, 0), tmp[1], &info[2]);
        if ((a | b) != 0 || info[3] != 4) {
            continue;
        }
        ver = func_02037df0((s8 *)&data_020fc91c, (s8 *)&tmp[3], (s8 *)payload, 0x2f);
        fme = func_02037df0((s8 *)&data_020fc90c, (s8 *)&tmp[2], (s8 *)payload, 0x2f);
        mdf = func_02037df0((s8 *)&data_020fc918, (s8 *)&tmp[0], (s8 *)payload, 0x2f);
        if (!(ver > 0 && fme > 0 && mdf > 0)) {
            continue;
        }
        if (func_0206abd8(&tmp[3], 0, 10) != 3) {
            continue;
        }
        if (func_0206abd8(&tmp[2], 0, 10) != M2C_FIELD(GetConnection(), u8 *, 0x16)) {
            continue;
        }
        if (rec == arg2) {
            arg0 = 1;
        }
        return func_02040878(rec, arg0);
    }
}

s32 func_02040cf0(M2C_UNK arg0) {
 void *GetConnection(); unsigned long long func_02007004(); s32 func_0203ea4c(); s32 func_02040a28(); M2C_UNK SetConnectionState(M2C_UNK); M2C_UNK func_0203dc38(M2C_UNK,s32);
 void func_02043008(s32); void *p;
 M2C_FIELD(GetConnection(),s32*,0x208)=0;
 M2C_FIELD(GetConnection(),s32*,0x204)=0;
 M2C_FIELD(GetConnection(),u8*,0x1a7)=0;
 p=GetConnection();
 M2C_FIELD(p,unsigned long long*,0x1cc)=func_02007004();
 if(M2C_FIELD(GetConnection(),u8*,0x15)==0) {
 SetConnectionState(3); func_0203ea4c(0); if(((s32 (*)())func_02043008)())return 0;
 } else if(M2C_FIELD(GetConnection(),u8*,0x15)==1) {
 func_02040a28(0,0,arg0); if(((s32 (*)())func_0204084c)())return 0;
 } else if(M2C_FIELD(GetConnection(),u8*,0x15)==3) {
 func_0203dc38(6,0xfffec5e6);return 0;
 }
 return 1;
}

s32 func_02040dc8(M2C_UNK arg0) {
    s32 func_0203f058(M2C_UNK, M2C_UNK, s32, u16, s32, s32);
    void *GetConnection();
    s32 temp_r4;
    void *temp_r4_2;

    temp_r4_2 = GetConnection();
    temp_r4 = func_0203f058(5, arg0, M2C_FIELD(temp_r4_2, s32 *, 0x24), M2C_FIELD(GetConnection(), u16 *, 0xA4), 0, 0);
    M2C_FIELD(GetConnection(), s32 *, 0x204) = 0;
    return temp_r4;
}

#pragma opt_strength_reduction off
s32 func_02040e1c(M2C_UNK arg0) {
    u64 func_02007004(void);
    M2C_UNK func_02040a28(M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_02041be0(M2C_UNK);
    M2C_UNK func_02041ce0(void);
    M2C_UNK func_02041dd4(M2C_UNK);
    s32 func_02042310(s32, M2C_UNK);
    void func_0205ea70(s32);
    M2C_UNK func_0205df50(s32);
    M2C_UNK SetConnectionState(M2C_UNK);
    void *GetConnection(void);
    s32 var_r4;
    s32 var_r5;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r6;

    if ((M2C_FIELD(GetConnection(), u8 *, 0x17) != 0) && (temp_r4 = GetConnection(), (M2C_FIELD(temp_r4, s32 *, 0x20) == M2C_FIELD(GetConnection(), s32 *, 0x200)))) {
        var_r4 = 0;
    } else {
        var_r4 = 1;
    }
    if (var_r4 != 0) {
        M2C_FIELD(GetConnection(), u8 *, 0x17) = 0;
        M2C_FIELD(GetConnection(), s32 *, 0x20) = 0;
        func_0205ea70(M2C_FIELD(GetConnection(), s32 *, 0x10));
        if ((u32) M2C_FIELD(GetConnection(), u8 *, 0xD) < 0x1FU) {
            temp_r6 = GetConnection();
            M2C_FIELD((temp_r6 + ((M2C_FIELD(GetConnection(), u8 *, 0xD) + 1) << 2)), s32 *, 0xF4) = 0;
        }
        M2C_FIELD(GetConnection(), u8 *, 0x3CC) = 0xFF;
        if (M2C_FIELD(GetConnection(), s32 *, 0x19C) != 0) {
            func_0205df50(M2C_FIELD(GetConnection(), s32 *, 0x19C));
            M2C_FIELD(GetConnection(), s32 *, 0x19C) = 0;
        }
        temp_r6 = GetConnection();
        M2C_FIELD(temp_r6, u8 *, 0x14) = (u8) M2C_FIELD(GetConnection(), u8 *, 0xD);
        M2C_FIELD(GetConnection(), s32 *, 0x204) = 0;
    }
    if (var_r4 == 0) {
        if (M2C_FIELD(GetConnection(), u8 *, 0x15) != 3) {
            func_02041ce0();
        }
        goto done;
    }
    if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 0) {
        SetConnectionState(3);
        M2C_FIELD(GetConnection(), s32 *, 0xE8) = 2;
        temp_r4_2 = GetConnection();
        M2C_FIELD(temp_r4_2, u64 *, 0xEC) = func_02007004();
        goto done;
    }
    if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 1) {
        SetConnectionState(4);
        func_02040a28(1, 0, 0);
        goto done;
    }
    if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 2) {
        SetConnectionState(0xE);
        M2C_FIELD(GetConnection(), s32 *, 0x1D8) = 0;
        M2C_FIELD(GetConnection(), s16 *, 0x1B2) = 0;
        func_02041dd4(arg0);
        var_r5 = 1;
        var_r4 = 0xD;
        if ((s32) M2C_FIELD(GetConnection(), u8 *, 0xD) >= 1) {
            for (;;) {
                if (func_02042310(M2C_FIELD((GetConnection() + (var_r5 << 2)), s32 *, 0xF4), var_r4) == 0) {
                    return 0;
                }
                var_r5 += 1;
                if (var_r5 > (s32) M2C_FIELD(GetConnection(), u8 *, 0xD)) {
                    break;
                }
            }
        }
        if (M2C_FIELD(GetConnection(), u8 *, 0xD) == 0) {
            func_02041be0(2);
        }
        goto done;
    }
done:
    return 1;
}
#pragma opt_strength_reduction reset
s32 func_02041038(void) {
    M2C_UNK func_0203dc38(M2C_UNK, s32);
    s32 func_02040cf0(M2C_UNK);
    M2C_UNK func_02041ce0();
    M2C_UNK func_02041e44();
    M2C_UNK SetConnectionState(M2C_UNK);
    M2C_UNK func_0205df50(s32);
    s32 var_r4;
    void *temp_r5;

    var_r4 = 1;
    if (M2C_FIELD(GetConnection(), u8 *, 0x15) == 3) {
        if (M2C_FIELD(GetConnection(), u8 *, 0xD) != 0) {
            func_02041e44();
        }
        func_0203dc38(6, 0xFFFEC5D2);
        return 0;
    }
    temp_r5 = GetConnection();
    M2C_FIELD(temp_r5, u8 *, 0x14) = (u8) M2C_FIELD(GetConnection(), u8 *, 0xD);
    M2C_FIELD(GetConnection(), s32 *, 0x208) = 0;
    if (M2C_FIELD(GetConnection(), s32 *, 0x19C) != 0) {
        func_0205df50(M2C_FIELD(GetConnection(), s32 *, 0x19C));
        M2C_FIELD(GetConnection(), s32 *, 0x19C) = 0;
    }
    if (M2C_FIELD(GetConnection(), u8 *, 0xD) != 0) {
        func_02041ce0();
    } else {
        SetConnectionState(4);
        var_r4 = func_02040cf0(0);
    }
    return var_r4;
}

#pragma opt_strength_reduction off
s32 func_020410f8(void) {
 s32 i,r; void *a,*b,*c,*d;
 s32 func_0203f058(M2C_UNK,M2C_UNK,s32,u16,s32,s32); void func_0205afec(s32); 
 for(i=1;i<=M2C_FIELD(GetConnection(),u8*,0xd);i++){
 a=GetConnection();b=GetConnection();c=GetConnection();d=GetConnection();
 r=func_0203f058(10,M2C_FIELD((u8*)a+(i<<2),s32*,0xf4),M2C_FIELD((u8*)b+(int)i*4,s32*,0x24),M2C_FIELD((u8*)c+(i<<1),u16*,0xa4),(s32)((u8*)d+0x348),M2C_FIELD(GetConnection(),s32*,0x348)+1);
 if(r)return r;
 }
 M2C_FIELD(GetConnection(),u8*,0x17)=0;
 M2C_FIELD(GetConnection(),s32*,0x20)=0;
 M2C_FIELD(GetConnection(),u8*,0x1a8)=1;
 func_0205afec(*M2C_FIELD(GetConnection(),s32**,4));
 M2C_FIELD(GetConnection(),u8*,0x1a8)=0;
 return 0;
}
#pragma opt_strength_reduction reset
