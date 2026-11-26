/* 7 functions from 0x0205342C to 0x020543E8 (main), found by ds-decomp. */
#include "common.h"
extern M2C_UNK data_020eacc0;
static inline s32 Upper534(s32 ch) { if(ch < 0 || ch >= 128) return ch; return ((u8 *)&data_020eacc0)[ch]; }
typedef struct TextPair534 { u8 chars[2]; } TextPair534;
static inline void CopyPair534(void *dst, void *src) { *(TextPair534 *)dst = *(TextPair534 *)src; }
typedef struct RequestPair534 { s32 a,b; } RequestPair534;
typedef struct Unk02053e40 { u32 words[60]; } Unk02053e40;

/* The \field\ names gpiSetInfoField appends for each profile-info field. */
#define gGsKeyNick        data_020fe72c
#define gGsKeyUniqueNick  data_020fe734
#define gGsKeyEmail       data_020fe744
#define gGsKeyFirstName   data_020fe74c
#define gGsKeyLastName    data_020fe758
#define gGsKeyIcqUin      data_020fe764
#define gGsKeyHomepage    data_020fe770
#define gGsKeyZipCode     data_020fe77c
#define gGsKeyCountryCode data_020fe788
#define gGsKeySex         data_020fe7bc
#define gGsKeyAim         data_020fe7cc
#define gGsKeyPic         data_020fe7d4
#define gGsKeyOccupation  data_020fe7dc
#define gGsKeyIndustry    data_020fe7e4
#define gGsKeyIncome      data_020fe7ec
#define gGsKeyMarital     data_020fe7f4
#define gGsKeyChildren    data_020fe7fc
#define gGsKeyInterest1   data_020fe804
#define gGsKeyVideoCard1  data_020fe95c
#define gGsKeyVideoCard2  data_020fe970
#define gGsKeyOsString    data_020fe984
#define gGsKeyPassword    data_020fe938
/* \sex\ values: 0 male, 1 female, 2 unspecified. */
#define gGpiSexMaleCode     data_020fe880
#define gGpiSexFemaleCode   data_020fe884
#define gGpiSexUnknownCode  data_020fe888

#pragma opt_propagation off
/* Set one profile-info field of a GPI connection: `field` is 0x700 + the field
 * index (nick, uniquenick, email, password, ...), `value` is its text.  The
 * string is copied into the connection's local profile record and appended to
 * the outgoing profile-update request, with integer fields parsed instead. */
s32 gpiSetInfoField(s32 *connection, s32 field, s8 *value) {
    M2C_UNK StringToLower(s8 *);
    s32 AppendUpdateProField(s32 *, M2C_UNK *, s8 *);
    s32 AppendUpdateUiField(s32 *, M2C_UNK *, s8 *);
    s32 AppendInfoIntField(s32 *, s32, s32);
    M2C_UNK StringCopyN(s8 *, s8 *, M2C_UNK);
    s32 StringLength(s8 *);
    s32 ParseInt(s8 *);
    extern M2C_UNK gGsKeyNick;
    extern M2C_UNK gGsKeyUniqueNick;
    extern M2C_UNK gGsKeyEmail;
    extern M2C_UNK gGsKeyFirstName;
    extern M2C_UNK gGsKeyLastName;
    extern M2C_UNK gGsKeyIcqUin;
    extern M2C_UNK gGsKeyHomepage;
    extern M2C_UNK gGsKeyZipCode;
    extern M2C_UNK gGsKeyCountryCode;
    extern M2C_UNK gGsKeySex;
    extern M2C_UNK gGsKeyAim;
    extern M2C_UNK gGsKeyPic;
    extern M2C_UNK gGsKeyOccupation;
    extern M2C_UNK gGsKeyIndustry;
    extern M2C_UNK gGsKeyIncome;
    extern M2C_UNK gGsKeyMarital;
    extern M2C_UNK gGsKeyChildren;
    extern M2C_UNK gGsKeyInterest1;
    extern M2C_UNK gGsKeyVideoCard1;
    extern M2C_UNK gGsKeyVideoCard2;
    extern M2C_UNK gGsKeyOsString;
    extern M2C_UNK gGsKeyPassword;
    extern M2C_UNK gGpiSexMaleCode;
    extern M2C_UNK gGpiSexFemaleCode;
    extern M2C_UNK gGpiSexUnknownCode;
    extern M2C_UNK gGpiMsgInvalidInfo;
    extern M2C_UNK gGpiMsgInvalidValue;
    extern M2C_UNK gGpiMsgInvalidCountryCode;
    s8 buffer[0x100]; TextPair534 *sexCode;
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
    s32 info;
    s8 sexLetter;
    s32 var_r1;
    u32 fieldIndex;

    info = *connection;
    if (value == NULL) {
        gpiSetErrorString(connection, &gGpiMsgInvalidValue);
        return 2;
    }
    fieldIndex = field - 0x700;
    switch (fieldIndex) {
    case 0:
        if (*value == 0) {
            gpiSetErrorString(connection, &gGpiMsgInvalidValue);
            return 2;
        }
        StringCopyN(buffer, value, 0x1F);
        StringCopyN(info + 0x110, buffer, 0x1F);
        temp_r0 = AppendUpdateProField(connection, &gGsKeyNick, buffer);
        if (temp_r0 != 0) {
            return temp_r0;
        }
        break;
    case 1:
        if (*value == 0) {
            gpiSetErrorString(connection, &gGpiMsgInvalidValue);
            return 2;
        }
        StringCopyN(buffer, value, 0x15);
        StringCopyN(info + 0x12F, buffer, 0x15);
        temp_r0_2 = AppendUpdateProField(connection, &gGsKeyUniqueNick, buffer);
        if (temp_r0_2 != 0) {
            return temp_r0_2;
        }
        break;
    case 2:
        if (*value == 0) {
            gpiSetErrorString(connection, &gGpiMsgInvalidValue);
            return 2;
        }
        StringCopyN(buffer, value, 0x33);
        StringToLower(buffer);
        StringCopyN(info + 0x144, buffer, 0x33);
        temp_r0_3 = AppendUpdateUiField(connection, &gGsKeyEmail, buffer);
        if (temp_r0_3 != 0) {
            return temp_r0_3;
        }
        break;
    case 3:
        if (*value == 0) {
            gpiSetErrorString(connection, &gGpiMsgInvalidValue);
            return 2;
        }
        StringCopyN(buffer, value, 0x1F);
        StringCopyN(info + 0x177, buffer, 0x1F);
        temp_r0_4 = AppendUpdateUiField(connection, &gGsKeyPassword, buffer);
        if (temp_r0_4 != 0) {
            return temp_r0_4;
        }
        break;
    case 4:
        StringCopyN(buffer, value, 0x1F);
        temp_r0_5 = AppendUpdateProField(connection, &gGsKeyFirstName, buffer);
        if (temp_r0_5 != 0) {
            return temp_r0_5;
        }
        break;
    case 5:
        StringCopyN(buffer, value, 0x1F);
        temp_r0_6 = AppendUpdateProField(connection, &gGsKeyLastName, buffer);
        if (temp_r0_6 != 0) {
            return temp_r0_6;
        }
        break;
    case 7:
        StringCopyN(buffer, value, 0x4C);
        temp_r0_7 = AppendUpdateProField(connection, &gGsKeyHomepage, buffer);
        if (temp_r0_7 != 0) {
            return temp_r0_7;
        }
        break;
    case 8:
        StringCopyN(buffer, value, 0xB);
        temp_r0_8 = AppendUpdateProField(connection, &gGsKeyZipCode, buffer);
        if (temp_r0_8 != 0) {
            return temp_r0_8;
        }
        break;
    case 9:
        if (StringLength(value) != 2) {
            gpiSetErrorString(connection, &gGpiMsgInvalidCountryCode);
            return 2;
        }
        StringCopyN(buffer, value, 3);
        temp_r0_9 = AppendUpdateProField(connection, &gGsKeyCountryCode, buffer);
        if (temp_r0_9 != 0) {
            return temp_r0_9;
        }
        break;
    case 11:
        sexLetter = Upper534(*value); sexCode=(TextPair534*)buffer;
        if (sexLetter == 0x4D) {
            *sexCode = *(TextPair534 *)&gGpiSexMaleCode;
        } else if (sexLetter == 0x46) {
            *sexCode = *(TextPair534 *)&gGpiSexFemaleCode;
        } else {
            *sexCode = *(TextPair534 *)&gGpiSexUnknownCode;
        }
        temp_r0_10 = AppendUpdateProField(connection, &gGsKeySex, buffer);
        if (temp_r0_10 != 0) {
            return temp_r0_10;
        }
        break;
    case 6:
        StringCopyN(buffer, value, 0x100);
        temp_r0_11 = AppendUpdateProField(connection, &gGsKeyIcqUin, buffer);
        if (temp_r0_11 != 0) {
            return temp_r0_11;
        }
        break;
    case 13:
        temp_r0_12 = AppendInfoIntField(connection, 0x70D, ParseInt(value));
        if (temp_r0_12 != 0) {
            return temp_r0_12;
        }
        break;
    case 14:
        temp_r0_13 = AppendInfoIntField(connection, 0x70E, ParseInt(value));
        if (temp_r0_13 != 0) {
            return temp_r0_13;
        }
        break;
    case 15:
        StringCopyN(buffer, value, 0x100);
        temp_r0_14 = AppendUpdateProField(connection, &gGsKeyVideoCard1, buffer);
        if (temp_r0_14 != 0) {
            return temp_r0_14;
        }
        break;
    case 16:
        temp_r0_15 = AppendInfoIntField(connection, 0x710, ParseInt(value));
        if (temp_r0_15 != 0) {
            return temp_r0_15;
        }
        break;
    case 17:
        StringCopyN(buffer, value, 0x100);
        temp_r0_16 = AppendUpdateProField(connection, &gGsKeyVideoCard2, buffer);
        if (temp_r0_16 != 0) {
            return temp_r0_16;
        }
        break;
    case 18:
        temp_r0_17 = AppendInfoIntField(connection, 0x712, ParseInt(value));
        if (temp_r0_17 != 0) {
            return temp_r0_17;
        }
        break;
    case 20:
        temp_r0_18 = AppendInfoIntField(connection, 0x714, ParseInt(value));
        if (temp_r0_18 != 0) {
            return temp_r0_18;
        }
        break;
    case 21:
        temp_r0_19 = AppendInfoIntField(connection, 0x715, ParseInt(value));
        if (temp_r0_19 != 0) {
            return temp_r0_19;
        }
        break;
    case 22:
        StringCopyN(buffer, value, 0x100);
        temp_r0_20 = AppendUpdateProField(connection, &gGsKeyOsString, buffer);
        if (temp_r0_20 != 0) {
            return temp_r0_20;
        }
        break;
    case 23:
        StringCopyN(buffer, value, 0x33);
        temp_r0_21 = AppendUpdateProField(connection, &gGsKeyAim, buffer);
        if (temp_r0_21 != 0) {
            return temp_r0_21;
        }
        break;
    case 24:
        StringCopyN(buffer, value, 0x100);
        temp_r0_22 = AppendUpdateProField(connection, &gGsKeyPic, buffer);
        if (temp_r0_22 != 0) {
            return temp_r0_22;
        }
        break;
    case 25:
        StringCopyN(buffer, value, 0x100);
        temp_r0_23 = AppendUpdateProField(connection, &gGsKeyOccupation, buffer);
        if (temp_r0_23 != 0) {
            return temp_r0_23;
        }
        break;
    case 26:
        StringCopyN(buffer, value, 0x100);
        temp_r0_24 = AppendUpdateProField(connection, &gGsKeyIndustry, buffer);
        if (temp_r0_24 != 0) {
            return temp_r0_24;
        }
        break;
    case 27:
        StringCopyN(buffer, value, 0x100);
        temp_r0_25 = AppendUpdateProField(connection, &gGsKeyIncome, buffer);
        if (temp_r0_25 != 0) {
            return temp_r0_25;
        }
        break;
    case 28:
        StringCopyN(buffer, value, 0x100);
        temp_r0_26 = AppendUpdateProField(connection, &gGsKeyMarital, buffer);
        if (temp_r0_26 != 0) {
            return temp_r0_26;
        }
        break;
    case 29:
        StringCopyN(buffer, value, 0x100);
        temp_r0_27 = AppendUpdateProField(connection, &gGsKeyChildren, buffer);
        if (temp_r0_27 != 0) {
            return temp_r0_27;
        }
        break;
    case 30:
        StringCopyN(buffer, value, 0x100);
        temp_r0_28 = AppendUpdateProField(connection, &gGsKeyInterest1, buffer);
        if (temp_r0_28 != 0) {
            return temp_r0_28;
        }
        break;
    default:
    case 10:
    case 12:
    case 19:
        gpiSetErrorString(connection, &gGpiMsgInvalidInfo);
        return 2;
    }
    return 0;
}
#pragma opt_propagation reset
/* Append the fields of a profile-info ("getprofile") server request to the
 * connection's outgoing command buffer: the session key, the profile id, the
 * operation id and the "\final\" terminator. */
s32 gpiAppendInfoRequest(void **connection, s32 profileId, s32 operationId) {
    M2C_UNK gpiAppendStringField(void **, void *, M2C_UNK *);
    M2C_UNK gpiAppendIntField(void **, void *, s32);
    extern M2C_UNK gGpiProfileIdField;
    extern M2C_UNK gGpiUpdateFinal;
    extern M2C_UNK gGpiGetProfileHeader;
    extern M2C_UNK gGpiIdField;
    void *session;

    session = *connection;
    gpiAppendStringField(connection, session + GPI_CONN_OUTPUT_BUFFER, &gGpiGetProfileHeader);
    gpiAppendIntField(connection, session + GPI_CONN_OUTPUT_BUFFER, M2C_FIELD(session, s32 *, GPI_CONN_SESSION_KEY));
    gpiAppendStringField(connection, session + GPI_CONN_OUTPUT_BUFFER, &gGpiProfileIdField);
    gpiAppendIntField(connection, session + GPI_CONN_OUTPUT_BUFFER, profileId);
    gpiAppendStringField(connection, session + GPI_CONN_OUTPUT_BUFFER, &gGpiIdField);
    gpiAppendIntField(connection, session + GPI_CONN_OUTPUT_BUFFER, operationId);
    gpiAppendStringField(connection, session + GPI_CONN_OUTPUT_BUFFER, &gGpiUpdateFinal);
    return 0;
}

/* Send a type-2 (set) operation for profile profileId. When useLocal is set
 * and the profile is cached, update the cached record first; callback and
 * callbackArg are delivered on completion, and doFinish waits for the result. */
s32 gpiGetInfoInternal(void **connection,s32 profileId,s32 useLocal,s32 doFinish,s32 callback,s32 callbackArg) {
s32 gpiFindBuddyStatus(void **,s32,void **);void *gpiMalloc(s32);M2C_UNK gpiSetErrorString(void **,M2C_UNK *);void gpiCopyInfo(void *,void *);
s32 gpiAddCallback(void **,RequestPair534,void *,void *,s32);void gpiRemoveOperation(void **,void *);s32 gpiThink(void **,s32);
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
gpiRemoveOperation(connection,operation);
}else{
rc=gpiAddOperation(connection,2,0,&operation,doFinish,callback,callbackArg);if(rc)return rc;
operationId=M2C_FIELD(operation,s32 *,24);rc=gpiAppendInfoRequest(connection,profileId,operationId);if(rc)return rc;
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
    extern M2C_UNK sGpiOperationSourceFile;
    extern M2C_UNK data_020fea10;
    extern M2C_UNK data_020fea24;
    extern M2C_UNK data_020fea38;
    extern M2C_UNK sGpiAssertZero;

    void *base = *arg0;
    void *operation = arg1;
    RequestPair534 pair;
    s32 result;
    void *buffer;

    if (arg0 == NULL) {
        AssertFailed((M2C_UNK)&data_020fe9ec, (M2C_UNK)&sGpiOperationSourceFile, (M2C_UNK)&data_020fe9c4, 0x22);
    }
    if (*arg0 == NULL) {
        AssertFailed((M2C_UNK)&data_020fea10, (M2C_UNK)&sGpiOperationSourceFile, (M2C_UNK)&data_020fe9c4, 0x23);
    }
    if (operation == NULL) {
        AssertFailed((M2C_UNK)&data_020fea24, (M2C_UNK)&sGpiOperationSourceFile, (M2C_UNK)&data_020fe9c4, 0x24);
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
                AssertFailed((M2C_UNK)&sGpiAssertZero, (M2C_UNK)&sGpiOperationSourceFile, (M2C_UNK)&data_020fe9c4, 0x6B);
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

