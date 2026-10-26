/* 18 functions from 0x020543E8 to 0x020553C4 (main), found by ds-decomp. */
#include "common.h"

void func_020543e8(void **arg0, void *arg1) {
    M2C_UNK func_020496b8(s32);
    M2C_UNK func_020496cc(s32, M2C_UNK);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_020fe9b0;
    extern M2C_UNK data_020fea00;
    extern M2C_UNK data_020fea4c;
    s32 temp_r0;
    void *temp_r2;
    void *temp_r5;

    temp_r2 = *arg0;
    if (M2C_FIELD(arg1, s32 *, 0) == 3) {
        temp_r5 = M2C_FIELD(arg1, void **, 4);
        temp_r0 = M2C_FIELD(temp_r2, s32 *, 0x210) - 1;
        M2C_FIELD(temp_r2, s32 *, 0x210) = temp_r0;
        if (temp_r0 < 0) {
            func_020640a8(&data_020fea4c, &data_020fea00, &data_020fe9b0, 0xB6);
        }
        func_020496cc(M2C_FIELD(temp_r5, s32 *, 4), 2);
        func_020496b8(M2C_FIELD(temp_r5, s32 *, 4));
        func_020377c4(M2C_FIELD(temp_r5, void **, 0x18));
        M2C_FIELD(temp_r5, void **, 0x18) = NULL;
        func_020377c4(M2C_FIELD(temp_r5, void **, 8));
        M2C_FIELD(temp_r5, void **, 8) = NULL;
    }
    func_020377c4(M2C_FIELD(arg1, void **, 4));
    M2C_FIELD(arg1, void **, 4) = NULL;
    func_020377c4(arg1);
}

void func_02054484(void **a,void *b) {
 void *base=*a; void *prev=NULL; void *p=M2C_FIELD(base,void **,0x424);
 while(p) {if(p==b) {if(!prev) M2C_FIELD(base,void **,0x424)=M2C_FIELD(p,void **,32); else M2C_FIELD(prev,void **,32)=M2C_FIELD(b,void **,32); func_020543e8(a,b); return;} prev=p; p=M2C_FIELD(p,void **,32);}
}

s32 func_020544d4(void **arg0, void **arg1, s32 arg2) {
    void *var_r3;

    var_r3 = M2C_FIELD(*arg0, void **, 0x424);
    if (var_r3 != NULL) {
loop_1:
        if (M2C_FIELD(var_r3, s32 *, 0x18) == arg2) {
            if (arg1 != NULL) {
                *arg1 = var_r3;
            }
            return 1;
        }
        var_r3 = M2C_FIELD(var_r3, void **, 0x20);
        if (var_r3 == NULL) {
            goto block_6;
        }
        goto loop_1;
    }
block_6:
    if (arg1 != NULL) {
        *arg1 = NULL;
    }
    return 0;
}

s32 func_02054520(void **a) {
 void *p=M2C_FIELD(*a,void **,0x424);
 while(p) {if(M2C_FIELD(p,s32 *,8)!=0 && M2C_FIELD(p,s32 *,0)!=3) return 1; p=M2C_FIELD(p,void **,32);}
 return 0;
}

void *func_0205455c(void **a,void *b,s32 c) {
 void *func_0205180c(void **,void *,s32);
 void *func_02055940(void **,void *,s32);
 void *func_02052600(void **,void *,s32);
 void *func_02057ff8(void **,void *,s32);
 M2C_UNK func_02058170(void **,M2C_UNK *,...);
 extern M2C_UNK data_020fea6c,data_020fea48,data_020fea00,data_020fe9d8;
 void *p=NULL;
 switch(M2C_FIELD(b,u32 *,0)) {
 case 0:p=func_0205180c(a,b,c);break;
 case 1:p=func_02055940(a,b,c);break;
 case 2:p=func_02052600(a,b,c);break;
 case 4:p=func_02057ff8(a,b,c);break;
 default:func_02058170(a,&data_020fea6c,M2C_FIELD(b,u32 *,0));func_020640a8(&data_020fea48,&data_020fea00,&data_020fe9d8,326);break;
 }
 if(p) M2C_FIELD(b,void **,28)=p;
 return p;
}

s32 func_02054f0c(M2C_UNK a,void *b) {
 s32 func_02054600(M2C_UNK,void *);
 s32 func_0205495c(M2C_UNK,void *);
 s32 func_02054c8c(M2C_UNK,void *);
 extern M2C_UNK data_020fec54,data_020fec0c,data_020feac4;
 s32 v=0;
 if(M2C_FIELD(b,s32 *,0)==100) func_020640a8(&data_020fec54,&data_020fec0c,&data_020feac4,473);
 if(M2C_FIELD(b,s32 *,0)!=105) {
 if(M2C_FIELD(b,s32 *,4)) v=func_02054600(a,b);else v=func_0205495c(a,b);
 }
 if(!v && M2C_FIELD(b,s32 *,0)==105) v=func_02054c8c(a,b);
 return v;
}

M2C_UNK func_02054fa8(void **a,void *b) {
 M2C_UNK func_0204861c(s32);
 func_020496cc(M2C_FIELD(b,s32 *,8),2);
 func_020496b8(M2C_FIELD(b,s32 *,8));
 func_020377c4(M2C_FIELD(b,void **,24));M2C_FIELD(b,void **,24)=NULL;
 func_020377c4(M2C_FIELD(b,void **,40));M2C_FIELD(b,void **,40)=NULL;
 if(M2C_FIELD(b,s32 *,56)) {func_0204861c(M2C_FIELD(b,s32 *,56));M2C_FIELD(b,s32 *,56)=0;}
 func_020377c4(b);
}

/* Unlinks an entry from a manager's 0x434 singly-linked list and releases its children. */
void func_02055008(void **manager, void *entry) {
    s32 func_02048688(s32);
    void *func_02048690(s32, M2C_UNK);
    M2C_UNK func_0204890c(s32, M2C_UNK);
    M2C_UNK func_0204f89c(void **, s32, s32, s32);
    M2C_UNK func_02054fa8(void **, void *);
    M2C_UNK func_02058170(void **, M2C_UNK *, ...);
    extern M2C_UNK data_020feab4;
    extern M2C_UNK data_020fec08;
    extern M2C_UNK data_020fec0c;
    extern M2C_UNK data_020fec7c;
    extern M2C_UNK data_020fec8c;
    s32 count;
    void *item;
    void *base;
    void *cursor;
    void *previous;

    base = *manager;
    if (entry == NULL) {
        func_020640a8(&data_020fec7c, &data_020fec0c, &data_020feab4, 0x213);
    }
    previous = M2C_FIELD(base, void **, 0x434);
    if (previous == entry) {
        M2C_FIELD(base, void **, 0x434) = (void *) M2C_FIELD(entry, void **, 0x3C);
        goto block_9;
    }
    cursor = M2C_FIELD(previous, void **, 0x3C);
    if (cursor != entry) {
loop_5:
        if (cursor == NULL) {
            func_020640a8(&data_020fec08, &data_020fec0c, &data_020feab4, 0x225);
            func_02058170(manager, &data_020fec8c);
            return;
        }
        previous = cursor;
        cursor = M2C_FIELD(cursor, void **, 0x3C);
        if (cursor == entry) {
            goto block_8;
        }
        goto loop_5;
    }
block_8:
    M2C_FIELD(previous, void **, 0x3C) = (void *) M2C_FIELD(entry, void **, 0x3C);
block_9:
    if (func_02048688(M2C_FIELD(entry, s32 *, 0x38)) != 0) {
        do {
            item = func_02048690(M2C_FIELD(entry, s32 *, 0x38), 0);
            count = M2C_FIELD(item, s32 *, 0x10);
            if (count < 0x64) {
                func_0204f89c(manager, M2C_FIELD(entry, s32 *, 0xC), count, M2C_FIELD(item, s32 *, 0) + M2C_FIELD(item, s32 *, 0x14));
            }
            func_0204890c(M2C_FIELD(entry, s32 *, 0x38), 0);
        } while (func_02048688(M2C_FIELD(entry, s32 *, 0x38)) != 0);
    }
    func_02054fa8(manager, entry);
}

void func_02055124(M2C_UNK arg0) {
    M2C_UNK func_0204932c(M2C_UNK, M2C_UNK);
    M2C_UNK func_02049370(M2C_UNK, M2C_UNK);
    M2C_UNK func_020493b0(M2C_UNK);
    M2C_UNK func_020493f8(M2C_UNK);
    func_0204932c(arg0, 0x4000);
    func_0204932c(arg0, 0x8000);
    func_0204932c(arg0, 0x10000);
    func_0204932c(arg0, 0x20000);
    func_0204932c(arg0, 0x40000);
    func_02049370(arg0, 0x4000);
    func_02049370(arg0, 0x8000);
    func_02049370(arg0, 0x10000);
    func_020493b0(arg0);
    func_020493f8(arg0);
}

s32 func_0205519c(void **arg0) {
    M2C_UNK func_020492ec(M2C_UNK, s32);
    s32 func_02049534();
    s32 func_020497a0(s32, M2C_UNK, M2C_UNK);
    s32 func_02049910(M2C_UNK);
    M2C_UNK func_020496b8(s32);
    s32 func_02054f0c(M2C_UNK, void *);
    void func_02055008(void **, void *);
    void *func_020552e0(void **, s32, s32);
    void func_02055124(M2C_UNK);
    s32 temp_r0;
    s32 temp_r0_3;
    void *temp_r0_2;
    void *temp_r6;
    void *temp_r7;
    void *var_r7;

    temp_r7 = *arg0;
    if ( -1 != M2C_FIELD(temp_r7, s32 *, 0x204) && (func_02049534() != 0)) {
        temp_r0 = func_020497a0(M2C_FIELD(temp_r7, s32 *, 0x204), 0, 0);
        if (temp_r0 != -1) {
            temp_r0_2 = func_020552e0(arg0, -1, 0);
            if (temp_r0_2 != NULL) {
                M2C_FIELD(temp_r0_2, s32 *, 0) = 0x68;
                M2C_FIELD(temp_r0_2, s32 *, 8) = temp_r0;
                func_020492ec(temp_r0, 0);
                func_02055124(M2C_FIELD(temp_r0_2, s32 *, 8));
            } else {
                func_020496b8(temp_r0);
            }
        }
    }
    var_r7 = M2C_FIELD(temp_r7, void **, 0x434);
    if (var_r7 != NULL) {
        do {
            temp_r6 = M2C_FIELD(var_r7, void **, 0x3C);
            temp_r0_3 = func_02054f0c(arg0, var_r7);
            if ((M2C_FIELD(var_r7, s32 *, 0) == 0x6A) || (temp_r0_3 != 0) || (func_02049910(0) > (s32) M2C_FIELD(var_r7, s32 *, 0x10))) {
                func_02055008(arg0, var_r7);
            }
            var_r7 = temp_r6;
        } while (temp_r6 != NULL);
    }
    return 0;
}

void *func_0205528c(void **a,s32 b) {
 void *p=M2C_FIELD(*a,void **,0x434);
 while(p) {if(M2C_FIELD(p,s32 *,12)==b && M2C_FIELD(p,s32 *,0)==105) return p; p=M2C_FIELD(p,void **,60);}
 return NULL;
}

void func_020552c4(s32 *arg0) {
    M2C_UNK func_020377c4(s32);
    func_020377c4(*arg0);
    *arg0 = 0;
}

void *func_020552e0(void **a,s32 b,s32 c) {
 void *func_02037794(s32);
 s32 func_02049910(s32);
 s32 func_02048558(s32,s32,void *);
 void *base=*a;
 void *p=func_02037794(64);
 if(!p)return NULL;
 func_02065210(p,0,64);
 M2C_FIELD(p,s32 *,0)=100;
 M2C_FIELD(p,s32 *,4)=c;
 M2C_FIELD(p,s32 *,8)=-1;
 M2C_FIELD(p,s32 *,12)=b;
 M2C_FIELD(p,s32 *,16)=func_02049910(0)+300;
 M2C_FIELD(p,void **,60)=M2C_FIELD(base,void **,0x434);
 M2C_FIELD(p,s32 *,56)=func_02048558(24,0,func_020552c4);
 M2C_FIELD(base,void **,0x434)=p;
 return p;
}

s32 func_02055360(M2C_UNK arg0, void *arg1) {
    s32 func_02053c04(M2C_UNK, s32, s32);
    s32 func_02054330(M2C_UNK, M2C_UNK, M2C_UNK, void **, s32, s32, s32);
    void *spC;
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_02054330(arg0, 2, 0, &spC, 0, 0, 0);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    var_r0 = func_02053c04(arg0, M2C_FIELD(arg1, s32 *, 0xC), M2C_FIELD(spC, s32 *, 0x18));
    if (var_r0 == 0) {
        M2C_FIELD(arg1, s32 *, 0) = 0x65;
        var_r0 = 0;
    }
    return var_r0;
}

