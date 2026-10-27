/* 7 functions from 0x0205342C to 0x020543E8 (main), found by ds-decomp. */
#include "common.h"
typedef struct RequestPair534 { s32 a,b; } RequestPair534;
typedef struct Unk02053e40 { u32 words[60]; } Unk02053e40;

s32 func_02053c04(void **arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_0204fea0(void **, void *, M2C_UNK *);
    M2C_UNK func_0204fed0(void **, void *, s32);
    extern M2C_UNK data_020fe710;
    extern M2C_UNK data_020fe84c;
    extern M2C_UNK data_020fe990;
    extern M2C_UNK data_020fe9a8;
    void *temp_r4;

    temp_r4 = *arg0;
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fe990);
    func_0204fed0(arg0, temp_r4 + 0x1F4, M2C_FIELD(temp_r4, s32 *, 0x198));
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fe710);
    func_0204fed0(arg0, temp_r4 + 0x1F4, arg1);
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fe9a8);
    func_0204fed0(arg0, temp_r4 + 0x1F4, arg2);
    func_0204fea0(arg0, temp_r4 + 0x1F4, &data_020fe84c);
    return 0;
}

s32 func_02053c9c(void **a,s32 b,s32 c,s32 d,s32 e,s32 f) {
s32 func_02055b84(void **,s32,void **);void *func_02037794(s32);M2C_UNK func_02058644(void **,M2C_UNK *);void func_02052408(void *,void *);
s32 func_02050838(void **,RequestPair534,void *,void *,s32);void func_02054484(void **,void *);s32 func_0204ec8c(void **,s32);
extern M2C_UNK data_020fe824;
register void *buffer; register s32 id; register s32 finish=d; register s32 value=b;
void *found,*req; void *base=*a; s32 enabled,result;RequestPair534 pair;
req=0;enabled=0;if(c==1)enabled=1;
if(M2C_FIELD(base,s32 *,256)==0)enabled=0;
if(e && enabled && func_02055b84(a,b,&found) && M2C_FIELD(found,void **,12)) {
buffer=func_02037794(516);
if(!buffer){func_02058644(a,&data_020fe824);return 1;}
func_02052408(M2C_FIELD(found,void **,12),buffer);
M2C_FIELD(buffer,s32 *,0)=0;M2C_FIELD(buffer,s32 *,4)=b;
pair.a=e;pair.b=f;
result=func_02054330(a,2,0,&req,1,e,f);if(result)return result;
id=M2C_FIELD(req,s32 *,24);
result=func_02050838(a,pair,buffer,req,0);if(result)return result;
func_02054484(a,req);
}else{
result=func_02054330(a,2,0,&req,d,e,f);if(result)return result;
id=M2C_FIELD(req,s32 *,24);result=func_02053c04(a,b,id);if(result)return result;
}
if(d){result=func_0204ec8c(a,id);if(result)return result;}
return 0;
}

/* Allocates and initializes an object structure. */
s32 func_02053e40(void **arg0, void *arg1, Unk02053e40 *arg2) {
    void func_02053f18(void *);
    void *func_02037794(s32);
    u32 func_02049274(u32);
    Unk02053e40 *p;

    if (!M2C_FIELD(*arg0, s32 *, 0x100)) {
        return 1;
    }
    func_02053f18(arg1);
    p = M2C_FIELD(arg1, Unk02053e40 **, 12) = func_02037794(0xf0);
    if (p) {
        *p = *arg2;
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 0) = func_02049274(M2C_FIELD(arg2, u32 *, 0));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 4) = func_02049274(M2C_FIELD(arg2, u32 *, 4));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 8) = func_02049274(M2C_FIELD(arg2, u32 *, 8));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 12) = func_02049274(M2C_FIELD(arg2, u32 *, 12));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 16) = func_02049274(M2C_FIELD(arg2, u32 *, 16));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 20) = func_02049274(M2C_FIELD(arg2, u32 *, 20));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 200) = func_02049274(M2C_FIELD(arg2, u32 *, 200));
    }
    return M2C_FIELD(arg1, void **, 12) != 0;
}

void func_02053f18(void *arg0) {
    M2C_UNK func_020377c4(void *);
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 0xC);
    if (temp_r0 == NULL) {
        return;
    }
    func_020377c4(M2C_FIELD(temp_r0, void **, 0));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 4));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 4) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 8));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 8) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0xC));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0xC) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0x10));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0x10) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0x14));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0x14) = NULL;
    func_020377c4(M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0xC8));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0xC8) = NULL;
    func_020377c4(M2C_FIELD(arg0, void **, 0xC));
    M2C_FIELD(arg0, void **, 0xC) = NULL;
}

s32 func_02054330(void **arg0, s32 arg1, s32 arg2, void **arg3, s32 arg4, s32 arg5, s32 arg6) {
    void *func_02037794(M2C_UNK);
    M2C_UNK func_02058644(void **, M2C_UNK *);
    extern M2C_UNK data_020fea38;
    s32 temp_r2;
    void *temp_r0;
    void *temp_r4;

    temp_r4 = *arg0;
    temp_r0 = func_02037794(0x24);
    if (temp_r0 == NULL) {
        func_02058644(arg0, &data_020fea38);
        return 1;
    }
    M2C_FIELD(temp_r0, s32 *, 0) = arg1;
    M2C_FIELD(temp_r0, s32 *, 4) = arg2;
    M2C_FIELD(temp_r0, s32 *, 8) = arg4;
    M2C_FIELD(temp_r0, s32 *, 0x14) = 0;
    if (arg1 == 0) {
        M2C_FIELD(temp_r0, s32 *, 0x18) = 1;
    } else {
        temp_r2 = M2C_FIELD(temp_r4, s32 *, 0x20C);
        M2C_FIELD(temp_r4, s32 *, 0x20C) = (s32) (temp_r2 + 1);
        M2C_FIELD(temp_r0, s32 *, 0x18) = temp_r2;
        if ((s32) M2C_FIELD(temp_r4, s32 *, 0x20C) < 2) {
            M2C_FIELD(temp_r4, s32 *, 0x20C) = 2;
        }
    }
    M2C_FIELD(temp_r0, s32 *, 0x1C) = 0;
    M2C_FIELD(temp_r0, s32 *, 0xC) = arg5;
    M2C_FIELD(temp_r0, s32 *, 0x10) = arg6;
    M2C_FIELD(temp_r0, void **, 0x20) = (void *) M2C_FIELD(temp_r4, void **, 0x424);
    M2C_FIELD(temp_r4, void **, 0x424) = temp_r0;
    *arg3 = temp_r0;
    return 0;
}

