/* 9 functions from 0x0204E408 to 0x0204EEE8 (main), found by ds-decomp. */
#include "common.h"
typedef struct InitPair4E { s32 first, second; } InitPair4E;
typedef struct InitState4E { u8 pad[0x1a4]; InitPair4E pairs[6]; } InitState4E;

s32 func_0204e408(void **arg0, s32 arg1, s8 *arg2, s8 *arg3) {
    M2C_UNK func_020580fc(s8 *, s8 *, M2C_UNK);
    M2C_UNK func_02058644(void **, M2C_UNK *);
    s32 func_02068d98(s8 *, void *);
    extern M2C_UNK data_020fda48;
    extern s8 data_020fda94;
    extern s8 data_020fdabc;
    extern M2C_UNK data_020fdaf8;
    extern M2C_UNK data_020fdb10;
    extern s8 data_020fdb28;
    extern s8 data_020fdb34;
    extern s8 data_020fdb44;
    s8 sp100[0x100];
    s8 sp0[0x100];
    s8 *var_r2;
    s8 *var_r2_2;
    void *temp_r4;

    if (arg0 != NULL) {
        temp_r4 = *arg0;
        if (temp_r4 != NULL) {
            if (M2C_FIELD(temp_r4, s32 *, 0x108) != 0) {
                return 0;
            }
            if (M2C_FIELD(temp_r4, s32 *, 0x1D8) == 4) {
                func_02058644(arg0, &data_020fda48);
                return 2;
            }
            if (arg2 == NULL) {
                func_02058644(arg0, &data_020fdaf8);
                return 2;
            }
            if (arg3 == NULL) {
                func_02058644(arg0, &data_020fdb10);
                return 2;
            }
            func_020580fc(sp100, arg2, 0x100);
            if (sp100[0] != 0) {
                var_r2 = sp100;
                do {
                    if (*var_r2 == 0x5C) {
                        *var_r2 = 0x2F;
                    }
                    var_r2 += 1;
                } while (*var_r2 != 0);
            }
            func_020580fc(sp0, arg3, 0x100);
            if (sp0[0] != 0) {
                var_r2_2 = sp0;
                do {
                    if (*var_r2_2 == 0x5C) {
                        *var_r2_2 = 0x2F;
                    }
                    var_r2_2 += 1;
                } while (*var_r2_2 != 0);
            }
            if ((arg1 == M2C_FIELD(temp_r4, s32 *, 0x214)) && (func_02068d98(sp100, temp_r4 + 0x218) == 0) && (func_02068d98(sp0, temp_r4 + 0x318) == 0)) {
                return 0;
            }
            M2C_FIELD(temp_r4, s32 *, 0x214) = arg1;
            func_020580fc(temp_r4 + 0x218, sp100, 0x100);
            func_020580fc(temp_r4 + 0x318, sp0, 0x100);
            func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fdb28);
            func_0204fed0(arg0, temp_r4 + 0x1F4, arg1);
            func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fda94);
            func_0204fed0(arg0, temp_r4 + 0x1F4, M2C_FIELD(temp_r4, s32 *, 0x198));
            func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fdb34);
            func_0204fea0(arg0, temp_r4 + 0x1F4, sp100);
            func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fdb44);
            func_0204fea0(arg0, temp_r4 + 0x1F4, sp0);
            func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fdabc);
            return 0;
        }
    }
    return 2;
}

s32 func_0204e6a8(void **a,s32 b,s32 c){void *func_02037794(s32);s32 func_020558e8(void **);s32 func_0204e84c(void **);void func_0204e7f0(void **);void func_02065210(void *,s32,s32);void func_02058170(void **,void *);extern u8 data_020fdb70[];InitState4E *p;s32 i,r;*a=0;p=func_02037794(0x490);if(!p)return 1;func_02065210(p,0,0x490);M2C_FIELD(p,u8 *,0)=0;M2C_FIELD(p,s32 *,0x418)=0;M2C_FIELD(p,s32 *,0x100)=1;M2C_FIELD(p,s32 *,0x104)=0;M2C_FIELD(p,s32 *,0x108)=0;M2C_FIELD(p,s32 *,0x10c)=0;M2C_FIELD(p,s32 *,0x46c)=b;M2C_FIELD(p,s32 *,0x470)=c;if(!func_020558e8((void **)&p)){func_020377c4(p);p=0;return 1;}M2C_FIELD(p,s32 *,0x420)=0;for(i=0;i<6;i++){p->pairs[i].first=0;p->pairs[i].second=0;}M2C_FIELD(p,s32 *,0x460)=0;func_02058170((void **)&p,data_020fdb70);r=func_0204e84c((void **)&p);if(r){func_0204e7f0((void **)&p);return r;}func_0204926c();func_02049208();func_020677a8();*a=p;return 0;}

void func_0204e7f0(void **arg0) {
    M2C_UNK func_020377c4(void *);
    M2C_UNK func_02048dc4(s32);
    M2C_UNK func_02052038(void **, M2C_UNK);
    void *temp_r4;

    temp_r4 = *arg0;
    func_02052038(arg0, 1);
    func_020377c4(M2C_FIELD(temp_r4, void **, 0x460));
    M2C_FIELD(temp_r4, void **, 0x460) = NULL;
    func_02048dc4(M2C_FIELD(temp_r4, s32 *, 0x428));
    func_020377c4(temp_r4);
    *arg0 = NULL;
}

s32 func_0204e830(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 8) = 0;
    M2C_FIELD(arg1, s32 *, 0x10) = 0;
    M2C_FIELD(arg1, s32 *, 0x14) = 0;
    M2C_FIELD(arg1, s32 *, 0x18) = 0;
    return 1;
}

s32 func_0204e84c(void **a){void func_02054484(void **,void *);void func_02055cd0(void **,void *);s32 func_0204e830(void *, void *);void *p=*a;M2C_FIELD(p,s8 *,272)=0;M2C_FIELD(p,s8 *,303)=0;M2C_FIELD(p,s8 *,324)=0;M2C_FIELD(p,s32 *,468)=-1;M2C_FIELD(p,s32 *,472)=0;M2C_FIELD(p,s32 *,484)=0;M2C_FIELD(p,s32 *,488)=0;M2C_FIELD(p,s32 *,480)=0;func_020377c4(M2C_FIELD(p,s32 *,476));M2C_FIELD(p,s32 *,476)=0;M2C_FIELD(p,s32 *,496)=0;func_020377c4(M2C_FIELD(p,s32 *,492));M2C_FIELD(p,s32 *,492)=0;M2C_FIELD(p,s32 *,508)=0;M2C_FIELD(p,s32 *,512)=0;M2C_FIELD(p,s32 *,504)=0;func_020377c4(M2C_FIELD(p,s32 *,500));M2C_FIELD(p,s32 *,500)=0;M2C_FIELD(p,s32 *,1096)=0;M2C_FIELD(p,s32 *,1100)=0;M2C_FIELD(p,s32 *,1092)=0;func_020377c4(M2C_FIELD(p,s32 *,1088));M2C_FIELD(p,s32 *,1088)=0;M2C_FIELD(p,s32 *,1112)=0;M2C_FIELD(p,s32 *,1116)=0;M2C_FIELD(p,s32 *,1108)=0;func_020377c4(M2C_FIELD(p,s32 *,1104));M2C_FIELD(p,s32 *,1104)=0;M2C_FIELD(p,s32 *,0x204)=-1;M2C_FIELD(p,s32 *,0x20c)=2;while(M2C_FIELD(p,s32 *,0x424))func_02054484(a,M2C_FIELD(p,s32 *,0x424));M2C_FIELD(p,s32 *,0x424)=0;M2C_FIELD(p,s32 *,0x430)=0;func_02055cd0(a,&func_0204e830);M2C_FIELD(p,s32 *,412)=0;M2C_FIELD(p,s32 *,416)=0;M2C_FIELD(p,s32 *,408)=0;M2C_FIELD(p,s32 *,528)=0;M2C_FIELD(p,s32 *,1052)=0;M2C_FIELD(p,s32 *,1076)=0;M2C_FIELD(p,s32 *,0x214)=-1;M2C_FIELD(p,s8 *,0x218)=0;M2C_FIELD(p,s8 *,0x318)=0;return 0;}

void func_0204e974(void *arg0) {
    return;
}

s32 func_0204ee40(void **arg0, void *arg1) {
    M2C_UNK func_0204fea0(void **, void *, M2C_UNK *);
    M2C_UNK func_0204fed0(void **, void *, s32);
    extern M2C_UNK data_020fdd94;
    extern M2C_UNK data_020fdda0;
    extern M2C_UNK data_020fddac;
    extern M2C_UNK data_020fddbc;
    extern M2C_UNK data_020fddc4;
    void *temp_r4;

    temp_r4 = *arg0;
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fdd94);
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fdda0);
    func_0204fed0(arg0, temp_r4 + 0x1F4, M2C_FIELD(temp_r4, s32 *, 0x198));
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fddac);
    func_0204fed0(arg0, temp_r4 + 0x1F4, M2C_FIELD(arg1, s32 *, 0));
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fddbc);
    func_0204fea0(arg0, temp_r4 + 0x1F4, M2C_FIELD(arg1, M2C_UNK **, 0x10));
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fddc4);
    return 0;
}

