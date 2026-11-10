/* 5 functions from 0x02052600 to 0x0205342C (main), found by ds-decomp. */
#include "common.h"
typedef struct {
 s8 buf14[51],buf47[31],buf66[31],buf85[51],bufB8[21],bufCD[31],bufEC[64],buf12C[76];
} Buffers526;
typedef struct {
 s8 *p0,*p4,*p8,*pC,*p10,*p14;
 s32 n18; s8 b1C[11],b27[3],pad2A[2]; s32 n2C,n30; s8 b34[128];
 s32 nB4,nB8,nBC,nC0,nC4; s8 *pC8;
 s32 nCC,nD0,nD4,nD8,nDC,nE0,nE4,nE8,nEC;
} Response526;
typedef struct {s32 a,b;} Callback526;
static inline Response526 MakeResponse526(void) { Response526 r={0}; return r; }
typedef struct {s32 a,b,c,d;} ZeroBlock526;
static inline void ClearResponse526(Response526 *r) {
ZeroBlock526 z={0}; ZeroBlock526 *p=(ZeroBlock526*)r; s32 i=7;
do { *p++=z; *p++=z; } while(--i); *p=z;
}

#pragma push
#pragma opt_common_subs off
s32 func_02052600(void **arg0, void *arg1, char *arg2) {
    void *func_02037794(M2C_UNK);
    M2C_UNK func_020377c4(s32);
    s32 func_02049274(s8 *);
    M2C_UNK func_02050744(void **, M2C_UNK, M2C_UNK);
    s32 func_02050838(void **, Callback526, void *, void *, s32);
    s32 func_02052360(void **, s32, s32 *, s32 *, s32 *);
    M2C_UNK func_02052408(s8 **, void *);
    M2C_UNK func_02053e40(void **, void *, s8 **);
    M2C_UNK func_02054484(void **, void *);
    void *func_02055aa0(void **, s32);
    M2C_UNK func_02055b84(void **, s32, void **);
    s32 func_0205817c(void **, char *, s32);
    s32 func_02058254(char *, M2C_UNK *, void *, s32);
    M2C_UNK func_02058620(void **, M2C_UNK, M2C_UNK *);
    M2C_UNK func_02058644(void **, M2C_UNK *);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    s32 func_02068eac(M2C_UNK, M2C_UNK *, M2C_UNK);
    M2C_UNK func_0206a374(s8 *);
    s32 func_0206ad38(s8 *);
    s32 func_0207044c();
    extern M2C_UNK data_020fe690;
    extern M2C_UNK data_020fe6a4;
    extern M2C_UNK data_020fe6d8;
    extern M2C_UNK data_020fe6e0;
    extern M2C_UNK data_020fe710;
    extern M2C_UNK data_020fe71c;
    extern M2C_UNK data_020fe72c;
    extern M2C_UNK data_020fe734;
    extern M2C_UNK data_020fe744;
    extern M2C_UNK data_020fe74c;
    extern M2C_UNK data_020fe758;
    extern M2C_UNK data_020fe764;
    extern M2C_UNK data_020fe770;
    extern M2C_UNK data_020fe77c;
    extern M2C_UNK data_020fe788;
    extern M2C_UNK data_020fe798;
    extern M2C_UNK data_020fe7a0;
    extern M2C_UNK data_020fe7a8;
    extern M2C_UNK data_020fe7b0;
    extern M2C_UNK data_020fe7bc;
    extern M2C_UNK data_020fe7c4;
    extern M2C_UNK data_020fe7cc;
    extern M2C_UNK data_020fe7d4;
    extern M2C_UNK data_020fe7dc;
    extern M2C_UNK data_020fe7e4;
    extern M2C_UNK data_020fe7ec;
    extern M2C_UNK data_020fe7f4;
    extern M2C_UNK data_020fe7fc;
    extern M2C_UNK data_020fe804;
    extern M2C_UNK data_020fe80c;
    extern M2C_UNK data_020fe814;
    extern M2C_UNK data_020fe81c;
    extern M2C_UNK data_020fe824;
    void *sp10;
    Callback526 callback;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r1;
    s32 var_r5;
    s32 var_r8;
    s8 **var_r7;
    void *temp_r0_4;
    void *temp_r6;
    void *temp_r7;
    void *var_r7_2;

    {s8 parse[64];
    temp_r6 = *arg0;
    if (func_0205817c(arg0, arg2, 1) != 0) {
        return 4;
    }
    if (func_02068eac(arg2, &data_020fe6d8, 4) != 0) {
        func_02058620(arg0, 1, &data_020fe6e0);
        func_02050744(arg0, 3, 1);
        return 3;
    }
    if (func_02058254(arg2, &data_020fe710, parse, 0x40) == 0) {
        func_02058620(arg0, 1, &data_020fe6e0);
        func_02050744(arg0, 3, 1);
        return 3;
    }
    temp_r0_3 = func_0206ad38(parse);
    if (temp_r0_3 <= 0) {
        func_020640a8(&data_020fe71c, &data_020fe6a4, &data_020fe690, 0x15A);
    }
    func_02055b84(arg0, temp_r0_3, &sp10);
    }
    {Response526 response = {0};
    Buffers526 buffers;
    response.p4 = &buffers.bufB8[0];
    response.pC = &buffers.buf66[0];
    response.p8 = &buffers.buf85[0];
    response.p10 = &buffers.buf47[0];
    response.p14 = &buffers.buf12C[0];
    response.p0 = &buffers.bufCD[0];
    response.pC8 = &buffers.buf14[0];
    if (func_02058254(arg2, &data_020fe72c, &buffers.bufCD[0], 0x1F) == 0) {
        *response.p0 = 0;
    }
    if (func_02058254(arg2, &data_020fe734, response.p4, 0x15) == 0) {
        *response.p4 = 0;
    }
    if (func_02058254(arg2, &data_020fe744, response.p8, 0x33) == 0) {
        *response.p8 = 0;
    }
    if (func_02058254(arg2, &data_020fe74c, response.pC, 0x1F) == 0) {
        *response.pC = 0;
    }
    if (func_02058254(arg2, &data_020fe758, response.p10, 0x1F) == 0) {
        *response.p10 = 0;
    }
    if (func_02058254(arg2, &data_020fe764, &buffers.bufEC[0], 0x40) == 0) {
        response.n18 = -1;
    } else {
        response.n18 = func_0206ad38(&buffers.bufEC[0]);
    }
    if (func_02058254(arg2, &data_020fe770, response.p14, 0x4C) == 0) {
        *response.p14 = 0;
    }
    if (func_02058254(arg2, &data_020fe77c, &response.b1C[0], 0xB) == 0) {
        response.b1C[0] = 0;
    }
    if (func_02058254(arg2, &data_020fe788, response.b27, 3) == 0) {
        response.b27[0] = 0;
    }
    if (func_02058254(arg2, &data_020fe798, &buffers.bufEC[0], 0x40) == 0) {
        response.n2C = 0;
    } else {
        func_0206a374(&buffers.bufEC[0]);
        response.n2C = func_0207044c();
    }
    if (func_02058254(arg2, &data_020fe7a0, &buffers.bufEC[0], 0x40) == 0) {
        response.n30 = 0;
    } else {
        func_0206a374(&buffers.bufEC[0]);
        response.n30 = func_0207044c();
    }
    if (func_02058254(arg2, &data_020fe7a8, &response.b34[0], 0x80) == 0) {
        response.b34[0] = 0;
    }
    if (func_02058254(arg2, &data_020fe7b0, &buffers.bufEC[0], 0x40) == 0) {
        response.nB4 = 0;
        response.nB8 = 0;
        response.nBC = 0;
        goto block_41;
    }
    temp_r0_2 = func_02052360(arg0, func_0206ad38(&buffers.bufEC[0]), &response.nB4, &response.nB8, &response.nBC);
    if (temp_r0_2 != 0) {
        return temp_r0_2;
    }
block_41:
    if (func_02058254(arg2, &data_020fe7bc, &buffers.bufEC[0], 0x40) == 0) {
        response.nC0 = 0x502;
    } else if (buffers.bufEC[0] == 0x30) {
        response.nC0 = 0x500;
    } else if (buffers.bufEC[0] == 0x31) {
        response.nC0 = 0x501;
    } else {
        response.nC0 = 0x502;
    }
    if (func_02058254(arg2, &data_020fe7c4, &buffers.bufEC[0], 0x40) == 0) {
        response.nC4 = -1;
    } else {
        response.nC4 = func_0206ad38(&buffers.bufEC[0]);
    }
    if (func_02058254(arg2, &data_020fe7cc, response.pC8, 0x33) == 0) {
        *response.pC8 = 0;
    }
    if (func_02058254(arg2, &data_020fe7d4, &buffers.bufEC[0], 0x40) == 0) {
        response.nCC = 0;
    } else {
        response.nCC = func_0206ad38(&buffers.bufEC[0]);
    }
    if (func_02058254(arg2, &data_020fe7dc, &buffers.bufEC[0], 0x40) == 0) {
        response.nD0 = 0;
    } else {
        response.nD0 = func_0206ad38(&buffers.bufEC[0]);
    }
    if (func_02058254(arg2, &data_020fe7e4, &buffers.bufEC[0], 0x40) == 0) {
        response.nD4 = 0;
    } else {
        response.nD4 = func_0206ad38(&buffers.bufEC[0]);
    }
    if (func_02058254(arg2, &data_020fe7ec, &buffers.bufEC[0], 0x40) == 0) {
        response.nD8 = 0;
    } else {
        response.nD8 = func_0206ad38(&buffers.bufEC[0]);
    }
    if (func_02058254(arg2, &data_020fe7f4, &buffers.bufEC[0], 0x40) == 0) {
        response.nDC = 0;
    } else {
        response.nDC = func_0206ad38(&buffers.bufEC[0]);
    }
    if (func_02058254(arg2, &data_020fe7fc, &buffers.bufEC[0], 0x40) == 0) {
        response.nE0 = 0;
    } else {
        response.nE0 = func_0206ad38(&buffers.bufEC[0]);
    }
    if (func_02058254(arg2, &data_020fe804, &buffers.bufEC[0], 0x40) == 0) {
        response.nE4 = 0;
    } else {
        response.nE4 = func_0206ad38(&buffers.bufEC[0]);
    }
    if (func_02058254(arg2, &data_020fe80c, &buffers.bufEC[0], 0x40) == 0) {
        response.nE8 = 0;
    } else {
        response.nE8 = func_0206ad38(&buffers.bufEC[0]);
    }
    if (func_02058254(arg2, &data_020fe814, &buffers.bufEC[0], 0x40) == 0) {
        response.nEC = 0;
    } else {
        response.nEC = func_0206ad38(&buffers.bufEC[0]);
    }
    if (func_02058254(arg2, &data_020fe81c, &buffers.bufEC[0], 0x40) == 0) {
        func_02058620(arg0, 1, &data_020fe6e0);
        func_02050744(arg0, 3, 1);
        return 3;
    }
    var_r7_2 = M2C_FIELD(temp_r6, void **, 0x434);
    var_r8 = M2C_FIELD(temp_r6, s32 *, 0x100);
    if (var_r7_2 != NULL) {
        do {
            if ((M2C_FIELD(var_r7_2, s32 *, 0xC) == temp_r0_3) && (M2C_FIELD(var_r7_2, s32 *, 0) == 0x65)) {
                if (sp10 == NULL) {
                    sp10 = func_02055aa0(arg0, temp_r0_3);
                }
                var_r8 = 1;
                M2C_FIELD(var_r7_2, s32 *, 0) = 0x66;
            }
            var_r7_2 = M2C_FIELD(var_r7_2, void **, 0x3C);
        } while (var_r7_2 != NULL);
    }
    if ((sp10 == NULL) && (M2C_FIELD(temp_r6, s32 *, 0x100) != 0)) {
        sp10 = func_02055aa0(arg0, temp_r0_3);
    }
    if (var_r8 != 0) {
        func_020377c4(M2C_FIELD(sp10, s32 *, 0x18));
        M2C_FIELD(sp10, s32 *, 0x18) = 0;
        M2C_FIELD(sp10, s32 *, 0x18) = func_02049274(&buffers.bufEC[0]);
    }
    if (M2C_FIELD(temp_r6, s32 *, 0x100) != 0) {
        func_02053e40(arg0, sp10, &response.p0);
    }
    callback=*(Callback526*)((u8*)arg1+12);
    temp_r1=callback.a;
    if (temp_r1 != 0) {
        temp_r0_4 = func_02037794(0x204);
        if (temp_r0_4 == NULL) {
            func_02058644(arg0, &data_020fe824);
            return 1;
        }
        func_02052408(&response.p0, temp_r0_4);
        M2C_FIELD(temp_r0_4, s32 *, 0) = 0;
        M2C_FIELD(temp_r0_4, s32 *, 4) = temp_r0_3;
        temp_r0 = func_02050838(arg0, callback, temp_r0_4, arg1, 0);
        if (temp_r0 != 0) {
            return temp_r0;
        }
    }
    func_02054484(arg0, arg1);
    return 0;
}
}
#pragma pop
s32 func_02052e18(void **arg0, M2C_UNK arg1) {
    M2C_UNK func_0204fed0(void **, M2C_UNK, s32);
    extern M2C_UNK data_020fe834;
    extern M2C_UNK data_020fe84c;
    extern M2C_UNK data_020fe854;
    void *temp_r4;

    temp_r4 = *arg0;
    if ((s32) M2C_FIELD(temp_r4, s32 *, 0x448) > 0) {
        func_0204fea0(arg0, arg1, &data_020fe834);
        func_0204fed0(arg0, arg1, M2C_FIELD(temp_r4, s32 *, 0x198));
        func_0204fea0(arg0, arg1, M2C_FIELD(temp_r4, M2C_UNK **, 0x440));
        func_0204fea0(arg0, arg1, &data_020fe84c);
        M2C_FIELD(temp_r4, s32 *, 0x448) = 0;
    }
    if ((s32) M2C_FIELD(temp_r4, s32 *, 0x458) > 0) {
        func_0204fea0(arg0, arg1, &data_020fe854);
        func_0204fed0(arg0, arg1, M2C_FIELD(temp_r4, s32 *, 0x198));
        func_0204fea0(arg0, arg1, M2C_FIELD(temp_r4, M2C_UNK **, 0x450));
        func_0204fea0(arg0, arg1, &data_020fe84c);
        M2C_FIELD(temp_r4, s32 *, 0x458) = 0;
    }
    return 0;
}

s32 AppendUpdateProField(s32 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_0204fea0(s32 *, s32, M2C_UNK);
    s32 temp_r0;
    s32 temp_r4;
    s32 var_r0;

    temp_r4 = *arg0;
    temp_r0 = func_0204fea0(arg0, temp_r4 + 0x440, arg1);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    var_r0 = func_0204fea0(arg0, temp_r4 + 0x440, arg2);
    if (var_r0 == 0) {
        var_r0 = 0;
    }
    return var_r0;
}

s32 AppendUpdateUiField(s32 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 func_0204fea0(s32 *, s32, M2C_UNK);
    s32 temp_r0;
    s32 temp_r4;
    s32 var_r0;

    temp_r4 = *arg0;
    temp_r0 = func_0204fea0(arg0, temp_r4 + 0x450, arg1);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    var_r0 = func_0204fea0(arg0, temp_r4 + 0x450, arg2);
    if (var_r0 == 0) {
        var_r0 = 0;
    }
    return var_r0;
}

/* Writes one numeric profile field to the connection's outgoing GameSpy
 * messages: the field id picks the protocol key and whether it belongs in the
 * profile ("updatepro") or UI ("updateui") buffer. */
s32 AppendInfoIntField(s32 *connection,s32 fieldId,s32 value) {
s32 func_02058644(void **,M2C_UNK *);
s32 func_020675e4(s8 *,M2C_UNK *,...);
extern M2C_UNK data_020fe868;
extern M2C_UNK data_020fe87c;
extern M2C_UNK data_020fe77c;
extern M2C_UNK data_020fe7bc;
extern M2C_UNK data_020fe880;
extern M2C_UNK data_020fe884;
extern M2C_UNK data_020fe888;
extern M2C_UNK data_020fe88c;
extern M2C_UNK data_020fe764;
extern M2C_UNK data_020fe89c;
extern M2C_UNK data_020fe8ac;
extern M2C_UNK data_020fe8b8;
extern M2C_UNK data_020fe8c4;
extern M2C_UNK data_020fe8d4;
extern M2C_UNK data_020fe8e4;
extern M2C_UNK data_020fe8f4;
extern M2C_UNK data_020fe908;
extern M2C_UNK data_020fe7d4;
extern M2C_UNK data_020fe7dc;
extern M2C_UNK data_020fe7e4;
extern M2C_UNK data_020fe7ec;
extern M2C_UNK data_020fe7f4;
extern M2C_UNK data_020fe7fc;
extern M2C_UNK data_020fe804;
extern M2C_UNK data_020fe918;
s8 text[16];
s32 err;
switch(fieldId) {
case 0x708:
if(value<0){func_02058644((void **)connection,&data_020fe868);return 2;}
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateProField(connection,(s32)&data_020fe77c,(s32)text);
if(err!=0)return err;
break;
case 0x70b:
switch(value){
case 0x500:
err=AppendUpdateProField(connection,(s32)&data_020fe7bc,(s32)&data_020fe880);
if(err!=0)return err;
break;
case 0x501:
err=AppendUpdateProField(connection,(s32)&data_020fe7bc,(s32)&data_020fe884);
if(err!=0)return err;
break;
case 0x502:
err=AppendUpdateProField(connection,(s32)&data_020fe7bc,(s32)&data_020fe888);
if(err!=0)return err;
break;
default:func_02058644((void **)connection,&data_020fe88c);return 2;
}
break;
case 0x706:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateProField(connection,(s32)&data_020fe764,(s32)text);
if(err!=0)return err;
break;
case 0x70c:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateUiField(connection,(s32)&data_020fe89c,(s32)text);
if(err!=0)return err;
break;
case 0x70d:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateUiField(connection,(s32)&data_020fe8ac,(s32)text);
if(err!=0)return err;
break;
case 0x70e:
func_020675e4(text,&data_020fe87c,value/16);
err=AppendUpdateUiField(connection,(s32)&data_020fe8b8,(s32)text);
if(err!=0)return err;
break;
case 0x710:
func_020675e4(text,&data_020fe87c,value/4);
err=AppendUpdateUiField(connection,(s32)&data_020fe8c4,(s32)text);
if(err!=0)return err;
break;
case 0x712:
func_020675e4(text,&data_020fe87c,value/4);
err=AppendUpdateUiField(connection,(s32)&data_020fe8d4,(s32)text);
if(err!=0)return err;
break;
case 0x713:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateUiField(connection,(s32)&data_020fe8e4,(s32)text);
if(err!=0)return err;
break;
case 0x714:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateUiField(connection,(s32)&data_020fe8f4,(s32)text);
if(err!=0)return err;
break;
case 0x715:
if(value!=0)value=1;
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateUiField(connection,(s32)&data_020fe908,(s32)text);
if(err!=0)return err;
break;
case 0x718:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateProField(connection,(s32)&data_020fe7d4,(s32)text);
if(err!=0)return err;
break;
case 0x719:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateProField(connection,(s32)&data_020fe7dc,(s32)text);
if(err!=0)return err;
break;
case 0x71a:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateProField(connection,(s32)&data_020fe7e4,(s32)text);
if(err!=0)return err;
break;
case 0x71b:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateProField(connection,(s32)&data_020fe7ec,(s32)text);
if(err!=0)return err;
break;
case 0x71c:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateProField(connection,(s32)&data_020fe7f4,(s32)text);
if(err!=0)return err;
break;
case 0x71d:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateProField(connection,(s32)&data_020fe7fc,(s32)text);
if(err!=0)return err;
break;
case 0x71e:
func_020675e4(text,&data_020fe87c,value);
err=AppendUpdateProField(connection,(s32)&data_020fe804,(s32)text);
if(err!=0)return err;
break;
default:func_02058644((void **)connection,&data_020fe918);return 2;
}
return 0;
}

