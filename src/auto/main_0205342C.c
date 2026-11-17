/* 7 functions from 0x0205342C to 0x020543E8 (main), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_020eacc0;
static inline s32 Upper534(s32 ch) { if(ch < 0 || ch >= 128) return ch; return ((u8 *)&data_020eacc0)[ch]; }
typedef struct TextPair534 { u8 chars[2]; } TextPair534;
static inline void CopyPair534(void *dst, void *src) { *(TextPair534 *)dst = *(TextPair534 *)src; }
typedef struct RequestPair534 { s32 a,b; } RequestPair534;
typedef struct Unk02053e40 { u32 words[60]; } Unk02053e40;

#pragma opt_propagation off
s32 func_0205342c(s32 *arg0, s32 arg1, s8 *arg2) {
    M2C_UNK StringToLower(s8 *);
    s32 AppendUpdateProField(s32 *, M2C_UNK *, s8 *);
    s32 AppendUpdateUiField(s32 *, M2C_UNK *, s8 *);
    s32 AppendInfoIntField(s32 *, s32, s32);
    M2C_UNK StringCopyN(s8 *, s8 *, M2C_UNK);
    s32 StringLength(s8 *);
    s32 ParseInt(s8 *);
    extern M2C_UNK data_020fe72c;
    extern M2C_UNK data_020fe734;
    extern M2C_UNK data_020fe744;
    extern M2C_UNK data_020fe74c;
    extern M2C_UNK data_020fe758;
    extern M2C_UNK data_020fe764;
    extern M2C_UNK data_020fe770;
    extern M2C_UNK data_020fe77c;
    extern M2C_UNK data_020fe788;
    extern M2C_UNK data_020fe7bc;
    extern M2C_UNK data_020fe7cc;
    extern M2C_UNK data_020fe7d4;
    extern M2C_UNK data_020fe7dc;
    extern M2C_UNK data_020fe7e4;
    extern M2C_UNK data_020fe7ec;
    extern M2C_UNK data_020fe7f4;
    extern M2C_UNK data_020fe7fc;
    extern M2C_UNK data_020fe804;
    extern M2C_UNK data_020fe880;
    extern M2C_UNK data_020fe884;
    extern M2C_UNK data_020fe888;
    extern M2C_UNK data_020fe918;
    extern M2C_UNK data_020fe928;
    extern M2C_UNK data_020fe938;
    extern M2C_UNK data_020fe944;
    extern M2C_UNK data_020fe95c;
    extern M2C_UNK data_020fe970;
    extern M2C_UNK data_020fe984;
    s8 sp0[0x100]; TextPair534 *dest;
    s32 temp_r0;
    s32 temp_r0_10;
    s32 temp_r0_11;
    s32 temp_r0_12;
    s32 temp_r0_13;
    s32 temp_r0_14;
    s32 temp_r0_15;
    s32 temp_r0_16;
    s32 temp_r0_17;
    s32 temp_r0_18;
    s32 temp_r0_19;
    s32 temp_r0_20;
    s32 temp_r0_21;
    s32 temp_r0_22;
    s32 temp_r0_23;
    s32 temp_r0_24;
    s32 temp_r0_25;
    s32 temp_r0_26;
    s32 temp_r0_27;
    s32 temp_r0_28;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r0_7;
    s32 temp_r0_8;
    s32 temp_r0_9;
    s32 temp_r4;
    s8 temp_r0_29;
    s32 var_r1;
    u32 temp_r1;

    temp_r4 = *arg0;
    if (arg2 == NULL) {
        gpiSetErrorString(arg0, &data_020fe928);
        return 2;
    }
    temp_r1 = arg1 - 0x700;
    switch (temp_r1) {
    case 0:
        if (*arg2 == 0) {
            gpiSetErrorString(arg0, &data_020fe928);
            return 2;
        }
        StringCopyN(sp0, arg2, 0x1F);
        StringCopyN(temp_r4 + 0x110, sp0, 0x1F);
        temp_r0 = AppendUpdateProField(arg0, &data_020fe72c, sp0);
        if (temp_r0 != 0) {
            return temp_r0;
        }
        break;
    case 1:
        if (*arg2 == 0) {
            gpiSetErrorString(arg0, &data_020fe928);
            return 2;
        }
        StringCopyN(sp0, arg2, 0x15);
        StringCopyN(temp_r4 + 0x12F, sp0, 0x15);
        temp_r0_2 = AppendUpdateProField(arg0, &data_020fe734, sp0);
        if (temp_r0_2 != 0) {
            return temp_r0_2;
        }
        break;
    case 2:
        if (*arg2 == 0) {
            gpiSetErrorString(arg0, &data_020fe928);
            return 2;
        }
        StringCopyN(sp0, arg2, 0x33);
        StringToLower(sp0);
        StringCopyN(temp_r4 + 0x144, sp0, 0x33);
        temp_r0_3 = AppendUpdateUiField(arg0, &data_020fe744, sp0);
        if (temp_r0_3 != 0) {
            return temp_r0_3;
        }
        break;
    case 3:
        if (*arg2 == 0) {
            gpiSetErrorString(arg0, &data_020fe928);
            return 2;
        }
        StringCopyN(sp0, arg2, 0x1F);
        StringCopyN(temp_r4 + 0x177, sp0, 0x1F);
        temp_r0_4 = AppendUpdateUiField(arg0, &data_020fe938, sp0);
        if (temp_r0_4 != 0) {
            return temp_r0_4;
        }
        break;
    case 4:
        StringCopyN(sp0, arg2, 0x1F);
        temp_r0_5 = AppendUpdateProField(arg0, &data_020fe74c, sp0);
        if (temp_r0_5 != 0) {
            return temp_r0_5;
        }
        break;
    case 5:
        StringCopyN(sp0, arg2, 0x1F);
        temp_r0_6 = AppendUpdateProField(arg0, &data_020fe758, sp0);
        if (temp_r0_6 != 0) {
            return temp_r0_6;
        }
        break;
    case 7:
        StringCopyN(sp0, arg2, 0x4C);
        temp_r0_7 = AppendUpdateProField(arg0, &data_020fe770, sp0);
        if (temp_r0_7 != 0) {
            return temp_r0_7;
        }
        break;
    case 8:
        StringCopyN(sp0, arg2, 0xB);
        temp_r0_8 = AppendUpdateProField(arg0, &data_020fe77c, sp0);
        if (temp_r0_8 != 0) {
            return temp_r0_8;
        }
        break;
    case 9:
        if (StringLength(arg2) != 2) {
            gpiSetErrorString(arg0, &data_020fe944);
            return 2;
        }
        StringCopyN(sp0, arg2, 3);
        temp_r0_9 = AppendUpdateProField(arg0, &data_020fe788, sp0);
        if (temp_r0_9 != 0) {
            return temp_r0_9;
        }
        break;
    case 11:
        temp_r0_29 = Upper534(*arg2); dest=(TextPair534*)sp0;
        if (temp_r0_29 == 0x4D) {
            *dest = *(TextPair534 *)&data_020fe880;
        } else if (temp_r0_29 == 0x46) {
            *dest = *(TextPair534 *)&data_020fe884;
        } else {
            *dest = *(TextPair534 *)&data_020fe888;
        }
        temp_r0_10 = AppendUpdateProField(arg0, &data_020fe7bc, sp0);
        if (temp_r0_10 != 0) {
            return temp_r0_10;
        }
        break;
    case 6:
        StringCopyN(sp0, arg2, 0x100);
        temp_r0_11 = AppendUpdateProField(arg0, &data_020fe764, sp0);
        if (temp_r0_11 != 0) {
            return temp_r0_11;
        }
        break;
    case 13:
        temp_r0_12 = AppendInfoIntField(arg0, 0x70D, ParseInt(arg2));
        if (temp_r0_12 != 0) {
            return temp_r0_12;
        }
        break;
    case 14:
        temp_r0_13 = AppendInfoIntField(arg0, 0x70E, ParseInt(arg2));
        if (temp_r0_13 != 0) {
            return temp_r0_13;
        }
        break;
    case 15:
        StringCopyN(sp0, arg2, 0x100);
        temp_r0_14 = AppendUpdateProField(arg0, &data_020fe95c, sp0);
        if (temp_r0_14 != 0) {
            return temp_r0_14;
        }
        break;
    case 16:
        temp_r0_15 = AppendInfoIntField(arg0, 0x710, ParseInt(arg2));
        if (temp_r0_15 != 0) {
            return temp_r0_15;
        }
        break;
    case 17:
        StringCopyN(sp0, arg2, 0x100);
        temp_r0_16 = AppendUpdateProField(arg0, &data_020fe970, sp0);
        if (temp_r0_16 != 0) {
            return temp_r0_16;
        }
        break;
    case 18:
        temp_r0_17 = AppendInfoIntField(arg0, 0x712, ParseInt(arg2));
        if (temp_r0_17 != 0) {
            return temp_r0_17;
        }
        break;
    case 20:
        temp_r0_18 = AppendInfoIntField(arg0, 0x714, ParseInt(arg2));
        if (temp_r0_18 != 0) {
            return temp_r0_18;
        }
        break;
    case 21:
        temp_r0_19 = AppendInfoIntField(arg0, 0x715, ParseInt(arg2));
        if (temp_r0_19 != 0) {
            return temp_r0_19;
        }
        break;
    case 22:
        StringCopyN(sp0, arg2, 0x100);
        temp_r0_20 = AppendUpdateProField(arg0, &data_020fe984, sp0);
        if (temp_r0_20 != 0) {
            return temp_r0_20;
        }
        break;
    case 23:
        StringCopyN(sp0, arg2, 0x33);
        temp_r0_21 = AppendUpdateProField(arg0, &data_020fe7cc, sp0);
        if (temp_r0_21 != 0) {
            return temp_r0_21;
        }
        break;
    case 24:
        StringCopyN(sp0, arg2, 0x100);
        temp_r0_22 = AppendUpdateProField(arg0, &data_020fe7d4, sp0);
        if (temp_r0_22 != 0) {
            return temp_r0_22;
        }
        break;
    case 25:
        StringCopyN(sp0, arg2, 0x100);
        temp_r0_23 = AppendUpdateProField(arg0, &data_020fe7dc, sp0);
        if (temp_r0_23 != 0) {
            return temp_r0_23;
        }
        break;
    case 26:
        StringCopyN(sp0, arg2, 0x100);
        temp_r0_24 = AppendUpdateProField(arg0, &data_020fe7e4, sp0);
        if (temp_r0_24 != 0) {
            return temp_r0_24;
        }
        break;
    case 27:
        StringCopyN(sp0, arg2, 0x100);
        temp_r0_25 = AppendUpdateProField(arg0, &data_020fe7ec, sp0);
        if (temp_r0_25 != 0) {
            return temp_r0_25;
        }
        break;
    case 28:
        StringCopyN(sp0, arg2, 0x100);
        temp_r0_26 = AppendUpdateProField(arg0, &data_020fe7f4, sp0);
        if (temp_r0_26 != 0) {
            return temp_r0_26;
        }
        break;
    case 29:
        StringCopyN(sp0, arg2, 0x100);
        temp_r0_27 = AppendUpdateProField(arg0, &data_020fe7fc, sp0);
        if (temp_r0_27 != 0) {
            return temp_r0_27;
        }
        break;
    case 30:
        StringCopyN(sp0, arg2, 0x100);
        temp_r0_28 = AppendUpdateProField(arg0, &data_020fe804, sp0);
        if (temp_r0_28 != 0) {
            return temp_r0_28;
        }
        break;
    default:
    case 10:
    case 12:
    case 19:
        gpiSetErrorString(arg0, &data_020fe918);
        return 2;
    }
    return 0;
}
#pragma opt_propagation reset
s32 func_02053c04(void **arg0, s32 arg1, s32 arg2) {
    M2C_UNK gpiAppendStringField(void **, void *, M2C_UNK *);
    M2C_UNK gpiAppendIntField(void **, void *, s32);
    extern M2C_UNK data_020fe710;
    extern M2C_UNK gGpiUpdateFinal;
    extern M2C_UNK data_020fe990;
    extern M2C_UNK data_020fe9a8;
    void *temp_r4;

    temp_r4 = *arg0;
    gpiAppendStringField(arg0, temp_r4 + 0x1F4, &data_020fe990);
    gpiAppendIntField(arg0, temp_r4 + 0x1F4, M2C_FIELD(temp_r4, s32 *, 0x198));
    gpiAppendStringField(arg0, temp_r4 + 0x1F4, &data_020fe710);
    gpiAppendIntField(arg0, temp_r4 + 0x1F4, arg1);
    gpiAppendStringField(arg0, temp_r4 + 0x1F4, &data_020fe9a8);
    gpiAppendIntField(arg0, temp_r4 + 0x1F4, arg2);
    gpiAppendStringField(arg0, temp_r4 + 0x1F4, &gGpiUpdateFinal);
    return 0;
}

/* Send a type-2 (set) operation for profile profileId. When useLocal is set
 * and the profile is cached, update the cached record first; callback and
 * callbackArg are delivered on completion, and doFinish waits for the result. */
s32 gpiGetInfoInternal(void **connection,s32 profileId,s32 useLocal,s32 doFinish,s32 callback,s32 callbackArg) {
s32 gpiFindBuddyStatus(void **,s32,void **);void *gpiMalloc(s32);M2C_UNK gpiSetErrorString(void **,M2C_UNK *);void gpiCopyInfo(void *,void *);
s32 gpiAddCallback(void **,RequestPair534,void *,void *,s32);void func_02054484(void **,void *);s32 gpiThink(void **,s32);
extern M2C_UNK data_020fe824;
register void *buffer; register s32 operationId; register s32 finish=doFinish; register s32 value=profileId;
void *cachedInfo,*operation; void *session=*connection; s32 useCache,rc;RequestPair534 pair;
operation=0;useCache=0;if(useLocal==1)useCache=1;
if(M2C_FIELD(session,s32 *,256)==0)useCache=0;
if(callback && useCache && gpiFindBuddyStatus(connection,profileId,&cachedInfo) && M2C_FIELD(cachedInfo,void **,12)) {
buffer=gpiMalloc(516);
if(!buffer){gpiSetErrorString(connection,&data_020fe824);return 1;}
gpiCopyInfo(M2C_FIELD(cachedInfo,void **,12),buffer);
M2C_FIELD(buffer,s32 *,0)=0;M2C_FIELD(buffer,s32 *,4)=profileId;
pair.a=callback;pair.b=callbackArg;
rc=gpiAddOperation(connection,2,0,&operation,1,callback,callbackArg);if(rc)return rc;
operationId=M2C_FIELD(operation,s32 *,24);
rc=gpiAddCallback(connection,pair,buffer,operation,0);if(rc)return rc;
func_02054484(connection,operation);
}else{
rc=gpiAddOperation(connection,2,0,&operation,doFinish,callback,callbackArg);if(rc)return rc;
operationId=M2C_FIELD(operation,s32 *,24);rc=func_02053c04(connection,profileId,operationId);if(rc)return rc;
}
if(doFinish){rc=gpiThink(connection,operationId);if(rc)return rc;}
return 0;
}

/* Allocates and initializes an object structure. */
s32 func_02053e40(void **arg0, void *arg1, Unk02053e40 *arg2) {
    void gpiFreeInfo(void *);
    void *gpiMalloc(s32);
    u32 gpiStringDup(u32);
    Unk02053e40 *p;

    if (!M2C_FIELD(*arg0, s32 *, 0x100)) {
        return 1;
    }
    gpiFreeInfo(arg1);
    p = M2C_FIELD(arg1, Unk02053e40 **, 12) = gpiMalloc(0xf0);
    if (p) {
        *p = *arg2;
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 0) = gpiStringDup(M2C_FIELD(arg2, u32 *, 0));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 4) = gpiStringDup(M2C_FIELD(arg2, u32 *, 4));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 8) = gpiStringDup(M2C_FIELD(arg2, u32 *, 8));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 12) = gpiStringDup(M2C_FIELD(arg2, u32 *, 12));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 16) = gpiStringDup(M2C_FIELD(arg2, u32 *, 16));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 20) = gpiStringDup(M2C_FIELD(arg2, u32 *, 20));
        M2C_FIELD(M2C_FIELD(arg1, void **, 12), u32 *, 200) = gpiStringDup(M2C_FIELD(arg2, u32 *, 200));
    }
    return M2C_FIELD(arg1, void **, 12) != 0;
}

/* Free the owned copy of a gpi profile-info response cached at record+0xC: its
 * seven owned strings and then the response itself. */
void gpiFreeInfo(void *record) {
    M2C_UNK gpiFree(void *);
    GpiInfoResponse *info;

    info = M2C_FIELD(record, void **, 0xC);
    if (info == NULL) {
        return;
    }
    gpiFree(info->nick);
    ((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->nick = NULL;
    gpiFree(((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->uniqueNick);
    ((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->uniqueNick = NULL;
    gpiFree(((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->email);
    ((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->email = NULL;
    gpiFree(((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->firstName);
    ((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->firstName = NULL;
    gpiFree(((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->lastName);
    ((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->lastName = NULL;
    gpiFree(((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->homepage);
    ((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->homepage = NULL;
    gpiFree(((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->aim);
    ((GpiInfoResponse *)M2C_FIELD(record, void **, 0xC))->aim = NULL;
    gpiFree(M2C_FIELD(record, void **, 0xC));
    M2C_FIELD(record, void **, 0xC) = NULL;
}

s32 gpiFinishOperation(void **arg0, void *arg1) {
    void *gpiMalloc(s32);
    void MemSet(void *, s32, s32);
    M2C_UNK gpiSetErrorString(void **, M2C_UNK *);
    M2C_UNK AssertFailed(M2C_UNK, M2C_UNK *, M2C_UNK *, s32);
    s32 gpiAddCallback(void **, RequestPair534, void *, void *, s32);
    extern M2C_UNK data_020fe9ec;
    extern M2C_UNK data_020fe9c4;
    extern M2C_UNK data_020fea00;
    extern M2C_UNK data_020fea10;
    extern M2C_UNK data_020fea24;
    extern M2C_UNK data_020fea38;
    extern M2C_UNK data_020fea48;

    void *base = *arg0;
    void *operation = arg1;
    RequestPair534 pair;
    s32 result;
    void *buffer;

    if (arg0 == NULL) {
        AssertFailed((M2C_UNK)&data_020fe9ec, (M2C_UNK)&data_020fea00, (M2C_UNK)&data_020fe9c4, 0x22);
    }
    if (*arg0 == NULL) {
        AssertFailed((M2C_UNK)&data_020fea10, (M2C_UNK)&data_020fea00, (M2C_UNK)&data_020fe9c4, 0x23);
    }
    if (operation == NULL) {
        AssertFailed((M2C_UNK)&data_020fea24, (M2C_UNK)&data_020fea00, (M2C_UNK)&data_020fe9c4, 0x24);
    }

    pair.a = M2C_FIELD(operation, s32 *, 0xC);
    pair.b = M2C_FIELD(operation, s32 *, 0x10);
    if (pair.a != 0) {
        switch (M2C_FIELD(operation, s32 *, 0x00)) {
            case 0:
                buffer = gpiMalloc(0x20);
                if (buffer == NULL) {
                    gpiSetErrorString(arg0, &data_020fea38);
                    return 1;
                }
                MemSet(buffer, 0, 0x20);
                M2C_FIELD(buffer, s32 *, 0x00) = M2C_FIELD(operation, s32 *, 0x1C);
                if (M2C_FIELD(base, s32 *, 0x418) == 0x201) {
                    M2C_FIELD(buffer, s32 *, 0x04) = M2C_FIELD(base, s32 *, 0x1A0);
                    M2C_FIELD(base, s32 *, 0x1A0) = 0;
                }
                result = gpiAddCallback(arg0, pair, buffer, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 1:
                buffer = gpiMalloc(8);
                if (buffer == NULL) {
                    gpiSetErrorString(arg0, &data_020fea38);
                    return 1;
                }
                {
                    u8 *p = buffer;
                    p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0;
                    p[4] = 0; p[5] = 0; p[6] = 0; p[7] = 0;
                }
                M2C_FIELD(buffer, s32 *, 0x00) = M2C_FIELD(operation, s32 *, 0x1C);
                result = gpiAddCallback(arg0, pair, buffer, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 2:
                buffer = gpiMalloc(0x204);
                if (buffer == NULL) {
                    gpiSetErrorString(arg0, &data_020fea38);
                    return 1;
                }
                MemSet(buffer, 0, 0x204);
                M2C_FIELD(buffer, s32 *, 0x00) = M2C_FIELD(operation, s32 *, 0x1C);
                result = gpiAddCallback(arg0, pair, buffer, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 3:
                buffer = gpiMalloc(0x10);
                if (buffer == NULL) {
                    gpiSetErrorString(arg0, &data_020fea38);
                    return 1;
                }
                {
                    s32 zero = 0;
                    unsigned long count = 4;
                    u8 *ptr = buffer;
                    do {
                        ptr[0] = zero;
                        ptr[1] = zero;
                        ptr[2] = zero;
                        ptr[3] = zero;
                        ptr += 4;
                    } while (--count != 0);
                }
                M2C_FIELD(buffer, s32 *, 0x00) = M2C_FIELD(operation, s32 *, 0x1C);
                M2C_FIELD(buffer, s32 *, 0x0C) = 0;
                result = gpiAddCallback(arg0, pair, buffer, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            case 4:
                buffer = gpiMalloc(4);
                if (buffer == NULL) {
                    gpiSetErrorString(arg0, &data_020fea38);
                    return 1;
                }
                {
                    u8 *p = buffer;
                    p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0;
                }
                M2C_FIELD(buffer, s32 *, 0x00) = M2C_FIELD(operation, s32 *, 0x1C);
                result = gpiAddCallback(arg0, pair, buffer, operation, 0);
                if (result != 0) {
                    return result;
                }
                break;
            default:
                AssertFailed((M2C_UNK)&data_020fea48, (M2C_UNK)&data_020fea00, (M2C_UNK)&data_020fe9c4, 0x6B);
                break;
        }
    }
    return 0;
}

/* Creates a gpi operation of `type` working on `data`, prepends it to the
 * connection's pending operation list and returns it through `operationOut`.
 * A type-0 operation gets id 1; every other type gets the next connection-wide
 * id.  Returns 0, or 1 when the operation could not be allocated. */
s32 gpiAddOperation(void **connection, s32 type, s32 data, void **operationOut, s32 blocking, s32 callback, s32 callbackParam) {
    void *gpiMalloc(M2C_UNK);
    M2C_UNK gpiSetErrorString(void **, M2C_UNK *);
    extern M2C_UNK data_020fea38;
    s32 id;
    GPIOperation *op;
    void *conn;

    conn = *connection;
    op = gpiMalloc(0x24);
    if (op == NULL) {
        gpiSetErrorString(connection, &data_020fea38);
        return 1;
    }
    op->type = type;
    op->data = (void *)data;
    op->blocking = blocking;
    op->state = 0;
    if (type == 0) {
        op->id = 1;
    } else {
        id = M2C_FIELD(conn, s32 *, GPI_CONN_NEXT_OPERATION_ID);
        M2C_FIELD(conn, s32 *, GPI_CONN_NEXT_OPERATION_ID) = (s32) (id + 1);
        op->id = id;
        if ((s32) M2C_FIELD(conn, s32 *, GPI_CONN_NEXT_OPERATION_ID) < 2) {
            M2C_FIELD(conn, s32 *, GPI_CONN_NEXT_OPERATION_ID) = 2;
        }
    }
    op->result = 0;
    op->callback = callback;
    op->callbackParam = callbackParam;
    op->next = (GPIOperation *) M2C_FIELD(conn, void **, GPI_CONN_OPERATIONS);
    M2C_FIELD(conn, void **, GPI_CONN_OPERATIONS) = op;
    *operationOut = op;
    return 0;
}

