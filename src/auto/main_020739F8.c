/* 43 functions from 0x020739F8 to 0x02074920 (main), found by ds-decomp. */
#include "common.h"
#include "cpp_exception.h"
#pragma cplusplus on
extern "C" {
void func_020742f8(void);
M2C_UNK func_020742e0(void);
void *DecodeExceptionValue(void *, s32 *);
void *DecodeExceptionSignedValue(void *, s32 *);
s32 ExceptionTypeMatches(M2C_UNK,void *);
void func_020746a4(void);
void func_0207465c(void *,void *,void *);
void func_02073c78(void);
extern u8 data_021009a4[],data_02100998[],data_021009bc[];
}
#pragma cplusplus off

typedef struct { s32 v[21]; } CtxTail_020739f8;
typedef struct { s32 f0, f1, f2, f3, f4, f5, f6; CtxTail_020739f8 tail; } CtxState_020739f8;
typedef struct { s32 t0, t1, t2, t3, t4, t5; } CtxToken_020739f8;
typedef struct { CtxToken_020739f8 token; CtxState_020739f8 state; } Ctx_020739f8;
typedef struct { s32 a,b,c,d; } CtxOperands_020739f8;

#pragma scheduling off
s32 func_020739f8(void *arg0, void *arg1) {
    u8 func_02072da4(CtxToken_020739f8 *);
    void *DecodeExceptionSignedValue(void *, s32 *);
    s32 func_02072dc0(Ctx_020739f8 *);
    s32 out;
    Ctx_020739f8 ctx;
    CtxState_020739f8 *st;
    s32 *tk;
    u8 *p;

    tk = (s32 *)arg1;
    st = (CtxState_020739f8 *)arg0;
    ctx.token.t0 = tk[0];
    ctx.token.t1 = tk[1];
    ctx.token.t2 = tk[2];
    ctx.token.t3 = tk[3];
    ctx.token.t4 = tk[4];
    ctx.token.t5 = tk[5];
    ctx.state.f0 = st->f0;
    ctx.state.f1 = st->f1;
    ctx.state.f2 = st->f2;
    ctx.state.f3 = st->f3;
    ctx.state.f4 = st->f4;
    ctx.state.f5 = st->f5;
    ctx.state.f6 = st->f6;
    ctx.state.tail = st->tail;

    for (;;) {
        u8 cmd = func_02072da4(&ctx.token);
        switch (cmd) {
        default:
        case 1:
        case 14:
            return 0;
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 15:
        case 16:
        case 17:
        case 18:
            func_02072dc0(&ctx);
            break;
        case 13:
            DecodeExceptionSignedValue((u8 *)ctx.token.t2 + 1, &out);
            p = (u8 *)ctx.state.f6 + out;
            ((s32 *)arg0)[0] = *(s32 *)(p + 4);
            ((s32 *)arg0)[1] = *(s32 *)p;
            ((s32 *)arg0)[2] = 0;
            ((s32 *)arg0)[3] = (s32)p;
            return (s32)p;
        }
    }
}
#pragma scheduling reset
/* True when the catch type pattern in typePattern matches any of the thrown
 * type names listed in the decoded exception context. */
s32 ExceptionTypeMatches(M2C_UNK typePattern, void *exception) {
    s32 func_02074330(M2C_UNK, s32, M2C_UNK *);
    s32 match[2];
    u8 *p;
    u32 i;

    p = M2C_FIELD(exception, u8 **, CPP_EXCEPTION_TYPE_NAMES);
    for (i = 0; i < M2C_FIELD(exception, u32 *, CPP_EXCEPTION_TYPE_COUNT); i++, p += 4) {
        match[1] = p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
        if (func_02074330(typePattern, match[1], match) != 0) return 1;
    }
    return 0;
}

#pragma cplusplus on
#pragma exceptions on
extern "C" void func_02073bd0(void *arg0){
u8 *p=M2C_FIELD(arg0,u8 **,20);s32 values[4];
try{func_020742f8();}catch(...){
void *q=DecodeExceptionValue(p+1,&values[0]);
q=DecodeExceptionValue(q,&values[1]);
values[3]=(s32)DecodeExceptionSignedValue(q,&values[2]);
if(ExceptionTypeMatches(M2C_FIELD(arg0,s32 *,8),values))func_020746a4();
if(ExceptionTypeMatches((s32)data_021009a4,values)){void *exception=data_02100998;func_0207465c(data_021009bc,&exception,(void *)func_02073c78);}
}
func_020742e0();
}
#pragma exceptions off
#pragma cplusplus off

void func_02073c78(void) {

}

#pragma scheduling on
#pragma peephole off
void func_02073c7c(s32 *arg0, s32 *arg1, void *arg2, s32 arg3) {
 M2C_UNK func_02073148(void *, s32 *, s32);
 M2C_UNK func_0207462c(void *, s32 *, s32);
 void *base; s32 offset; void *entry;
 register s32 value=arg3;
 func_02073148(arg0,arg1,value);
 base=M2C_FIELD(arg0,void **,0x18); offset=M2C_FIELD(arg2,s32 *,8); entry=(u8*)base+offset;
 M2C_FIELD(entry,s32 *,0)=M2C_FIELD(arg0,s32 *,4);
 M2C_FIELD(entry,s32 *,4)=M2C_FIELD(arg0,s32 *,0);
 M2C_FIELD(entry,s32 *,8)=M2C_FIELD(arg0,s32 *,8);
 M2C_FIELD(entry,s32 *,0x14)=value;
 func_0207462c(arg0,arg1,*arg1+M2C_FIELD(arg2,s32 *,4));
}
#pragma peephole reset
#pragma scheduling reset
u8 *func_02073cdc(void *arg0, void *arg1, s32 *arg2) {
    u8 func_02072da4(CtxToken_020739f8 *);
    s32 func_02072dc0(Ctx_020739f8 *);
    void *DecodeExceptionValue(void *, M2C_UNK *);
    void *DecodeExceptionSignedValue(void *, s32 *);
    M2C_UNK func_020742e0(void);
    s32 func_02074330(M2C_UNK, s32, M2C_UNK *);
    s32 ExceptionTypeMatches(M2C_UNK, void *);
    void func_02073c7c(s32 *, s32 *, void *, s32);
    s32 code;
    Ctx_020739f8 ctx;
    s32 values[3];
    CtxOperands_020739f8 operands;

    ctx.token.t0 = ((s32 *)arg1)[0];
    ctx.token.t1 = ((s32 *)arg1)[1];
    ctx.token.t2 = ((s32 *)arg1)[2];
    ctx.token.t3 = ((s32 *)arg1)[3];
    ctx.token.t4 = ((s32 *)arg1)[4];
    ctx.token.t5 = ((s32 *)arg1)[5];
    ctx.state.f0 = ((CtxState_020739f8 *)arg0)->f0;
    ctx.state.f1 = ((CtxState_020739f8 *)arg0)->f1;
    ctx.state.f2 = ((CtxState_020739f8 *)arg0)->f2;
    ctx.state.f3 = ((CtxState_020739f8 *)arg0)->f3;
    ctx.state.f4 = ((CtxState_020739f8 *)arg0)->f4;
    ctx.state.f5 = ((CtxState_020739f8 *)arg0)->f5;
    ctx.state.f6 = ((CtxState_020739f8 *)arg0)->f6;
    ctx.state.tail = ((CtxState_020739f8 *)arg0)->tail;

    code = func_02072da4(&ctx.token);
    for (;;) {
        switch (code) {
        case 12: {
            u8 *node = (u8 *)ctx.token.t2;
            values[0] = node[1] | (node[2] << 8) | (node[3] << 16) | (node[4] << 24);
            {
                u8 *r = (u8 *)DecodeExceptionValue(node + 5, &values[1]);
                DecodeExceptionSignedValue(r, &values[2]);
            }
            if (func_02074330(((CtxState_020739f8 *)arg0)->f0, values[0], arg2) != 0) {
                goto done;
            }
            break;
        }
        case 15: {
            u8 *node = (u8 *)ctx.token.t2;
            u8 *r;
            r = (u8 *)DecodeExceptionValue(node + 1, &operands.a);
            r = (u8 *)DecodeExceptionValue(r, &operands.b);
            r = (u8 *)DecodeExceptionSignedValue(r, &operands.c);
            operands.d = (s32)r;
            if (ExceptionTypeMatches(((CtxState_020739f8 *)arg0)->f0, &operands.a) != 0) {
                    break;
            }
            func_02073c7c((s32 *)arg0, (s32 *)arg1, (void *)&operands.a, (s32)node);
            break;
        }
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 13:
        case 16:
        case 17:
        case 18:
        case 19:
            break;
        case 1:
        case 14:
        default:
            func_020742e0();
            goto done;
        }
        func_02072dc0(&ctx);
        code = func_02072da4(&ctx.token);
    }
done:
    return (u8 *)ctx.token.t2;
}
#pragma opt_common_subs reset
/* Fill the running exception frame record's handler entry, at stack address
 * record[0x18] + stackOffset: copy the record's three saved pointers and store the
 * resume address record[4] + resume.  When the record's type pattern starts with a
 * '*' the entry holds a pointer to the address instead of the address itself. */
void Js_BuildHandlerEntry(void *record, s32 stackOffset, s32 resume) {
    void *entry;
    entry = (u8 *)M2C_FIELD(record, void **, 0x18) + stackOffset;
    M2C_FIELD(entry, s32 *, 0) = M2C_FIELD(record, s32 *, 4);
    M2C_FIELD(entry, s32 *, 4) = M2C_FIELD(record, s32 *, 0);
    M2C_FIELD(entry, s32 *, 8) = M2C_FIELD(record, s32 *, 8);
    if (*M2C_FIELD(record, u8 **, 0) == 0x2A) {
        M2C_FIELD(entry, void **, 0xC) = (u8 *)entry + 0x10;
        M2C_FIELD(entry, s32 *, 0x10) = *M2C_FIELD(record, s32 **, 4) + resume;
    } else {
        M2C_FIELD(entry, s32 *, 0xC) = M2C_FIELD(record, s32 *, 4) + resume;
    }
}

/* Execute the handler of the record whose frame is frame: decode the handlers of the
 * record's data block (JsRecordRef.data) into the handler and the record's data, then
 * run the block's opcodes until one continues or ends execution.  Returns 0 when the
 * block runs to its end (or the record has no handler). */
void Js_RunHandler(void *a){
void FindExceptionTableHandler(s32,void *); M2C_UNK func_020742e0(void); s32 func_020739f8(void *,void *); u8 *func_02073cdc(void *,void *,s32 *); void *DecodeExceptionValue(void *,M2C_UNK *); void *DecodeExceptionSignedValue(void *,s32 *); M2C_UNK func_02073148(); M2C_UNK func_0207462c(void *,s32 *,s32); void Js_DecodeFrameData(void *,void *);
s32 frame[6]; s32 operands[4]; u8 *p; u8 *data;
FindExceptionTableHandler(M2C_FIELD(a,s32 *,16),frame);
if(!frame[1])func_020742e0();
Js_DecodeFrameData(a,frame);
if(M2C_FIELD(a,s32 *,0))M2C_FIELD(a,s32 *,12)=0;
else {M2C_FIELD(a,s32 *,12)=func_020739f8(a,frame);if(!M2C_FIELD(a,s32 *,12))func_020742e0();}
p=func_02073cdc(a,frame,&operands[0]);
operands[1]=p[1]|(p[2]<<8)|(p[3]<<16)|(p[4]<<24);
DecodeExceptionSignedValue(DecodeExceptionValue(p+5,&operands[2]),&operands[3]);
func_02073148(a,frame,p);
Js_BuildHandlerEntry(a,operands[3],operands[0]);
func_0207462c(a,frame,frame[0]+operands[2]);
}

/* Run the deleting destructor of the object described by `record`: when the record
 * holds an object pointer (+0x00) and a destructor (+0x08), call destructor(object, -1)
 * to destroy and free it. */
void DeleteScopedObject(void *record) {
    M2C_UNK (*destructor)(s32, M2C_UNK);
    s32 object;

    object = M2C_FIELD(record, s32 *, 0);
    if (object != 0) {
        destructor = M2C_FIELD(record, M2C_UNK (**)(s32, M2C_UNK), 8);
        if (destructor != NULL) {
            destructor(object, -1);
        }
    }
}

s32 func_02074028(s32 arg0) {
    M2C_UNK MemFree();
    MemFree();
    return arg0;
}

M2C_UNK *func_0207403c(void) {
    extern M2C_UNK data_0210096c;
    return &data_0210096c;
}

/* Run the C++ static constructors the linker collected in the ARM9 program's
 * .ctor table (ARM9_CTOR_START): the table is a null-terminated array of
 * function pointers, called in order. */
void RunStaticInitializers(void) {
    extern void (*ARM9_CTOR_START[])(void);
    void (**ctor)(void) = ARM9_CTOR_START;

    while (ctor != NULL && *ctor != NULL) {
        (*ctor)();
        ctor++;
    }
}

/* Run and unlink every function on the C++ exit-function list, handing each its
 * stored argument and -1, until the list is empty. */
void RunExitFunctions(void) {
    extern void *gExitFunctionList;
    void *entry;
    entry = gExitFunctionList;
    if (entry == NULL) return;
    do {
        gExitFunctionList = M2C_FIELD(entry, void **, EXIT_FUNC_NEXT);
        M2C_FIELD(entry, void (**)(s32, s32), EXIT_FUNC_CALLBACK)(M2C_FIELD(entry, s32 *, EXIT_FUNC_ARG), -1);
        entry = gExitFunctionList;
    } while (entry != NULL);
}

#pragma cplusplus on
#pragma exceptions on
extern "C" void DestroyPartialArray(u32 arg0,u32 arg1,s32 arg2,M2C_UNK (*arg3)(u32)) { try { while(arg1>arg0) { arg1-=arg2; arg3(arg1); } } catch (...) { for (;;) {} } }
extern "C" void DestroyPartialArray(u32, u32, s32, M2C_UNK (*)(u32));
/* Construct `count` array elements starting at `first`, `stride` bytes apart, by
 * calling `constructor` on each.  If a constructor throws, destroy the elements
 * already built (in reverse order, through `destructor`) and rethrow. */
extern "C" void ConstructArray(s32 first, s32 count, s32 stride, M2C_UNK (*constructor)(s32), s32 destructor) {
    s32 current;
    if (constructor == 0) return;
    if (destructor != 0) {
        current = first;
        try {
            while (count != 0) { constructor(current); current += stride; --count; }
        } catch (...) {
            DestroyPartialArray(first, current, stride, (M2C_UNK (*)(u32))destructor);
            throw;
        }
    } else {
        while (count != 0) { constructor(first); first += stride; --count; }
    }
}
#pragma cplusplus on
#pragma exceptions on
/* Destroy `count` array elements in reverse, `stride` bytes apart: `first` is the
 * base and the elements end at first + count * stride, so each step subtracts the
 * stride and calls `destructor` on the element.  Does nothing without a
 * destructor. */
extern "C" void DestroyArray(s32 first, s32 count, s32 stride, M2C_UNK (*destructor)(s32)) {
    s32 current;
    if (destructor != 0) {
        current = count * stride + first;
        try {
            while (count != 0) { current -= stride; destructor(current); --count; }
        } catch (s32) {}
    }
}
#pragma exceptions off
#pragma cplusplus off
void func_02074220(void) {

}

/* True when two C++ type_info objects are equal (the comparison dynamic_cast
 * relies on): the same object, or the same mangled type name. */
s32 TypeInfoEquals(TypeInfo *typeInfo, TypeInfo *other) {
    s32 StringCompare(s32, s32);
    if ((typeInfo == other) || (StringCompare((s32) typeInfo->name, (s32) other->name) == 0)) {
        return 1;
    }
    return 0;
}

s32 func_02074254(s32 arg0) {
    func_02074220();
    return arg0;
}

/* CodeWarrior's deleting-destructor helper for an empty class: run the class's
 * (empty) destructor, free the object and leave its address in r0, which is what
 * a delete expression expects back. */
s32 func_02074268(s32 object) {
    func_02074220();
    MemFree(object);
    return object;
}

s32 DestroyEmptyObject(s32 arg0) {
    func_02074220();
    return arg0;
}

s32 func_02074298(s32 arg0) {
    M2C_UNK DestroyEmptyObject();
    DestroyEmptyObject();
    return arg0;
}

/* Deleting destructor of an object whose class has an empty destructor: run the
 * class's destructor (DestroyEmptyObject), free the object and return its
 * address, which is what the caller's delete expression expects back. */
s32 DeleteEmptyObject(s32 object) {
    M2C_UNK DestroyEmptyObject();
    DestroyEmptyObject();
    MemFree(object);
    return object;
}

void func_020742c8(void) {
    M2C_UNK ForceFlushSocketEvents();
    ForceFlushSocketEvents();
}

void func_020742d4(void) {
    M2C_UNK func_020742e0();
    func_020742e0();
}

M2C_UNK func_020742e0(void) {
    extern M2C_UNK data_02100a80;
    return M2C_FIELD(&data_02100a80, M2C_UNK (**)(), 0)();
}

void func_020742f8(void) {
    extern M2C_UNK data_02100a80;
    M2C_FIELD(&data_02100a80, M2C_UNK (**)(), 4)();
}

/* Push an exit-function record (a node for __cxa_atexit) onto gExitFunctionList:
 * it stores the callback and its argument, then becomes the new list head. */
void RegisterExitFunction(s32 argument, s32 callback, void *node) {
    extern void *gExitFunctionList;
    M2C_FIELD(node, void **, EXIT_FUNC_NEXT) = (void *) gExitFunctionList;
    M2C_FIELD(node, s32 *, EXIT_FUNC_CALLBACK) = callback;
    M2C_FIELD(node, s32 *, EXIT_FUNC_ARG) = argument;
    gExitFunctionList = node;
}

#pragma opt_common_subs off
s32 func_02074330(M2C_UNK arg0,s32 arg1,M2C_UNK *arg2){
u8 *p=(u8 *)arg0;u8 *q;s32 num;u8 t,u;
q=(u8 *)arg1;
*(s32 *)arg2=0;
if(!arg1)return 1;
if(*(u8 *)arg1=='P'){
if(*++q=='V')q++;
if(*q=='K')q++;
if(*q=='v' && (*p=='P'||*p=='*'))return 1;
}
q=(u8 *)arg1;
t=*p;
if(t=='!'||*p=='*'){
if(*p++!=*q++)return 0;
compare:
t=*p;
if(t==*q++){
p++;
if(t!='!')goto compare;
num=0;
if(*p!='!')do{num=num*10+*p-'0';p++;}while(*p!='!');
*(s32 *)arg2=num;return 1;
}
while(*p++!='!'){}
while(*p++!='!'){}
if(!*p)return 0;
q=(u8 *)arg1+1;goto compare;
}
goto check;
prefix:
u=*++q;p++;
if(u=='K'){
q++;if(*p=='K')p++;
t=*p;if(t=='K')return 0;
}
if(*q=='V'){
if(t=='V')p++;
q++;if(*p=='V')return 0;
}
check:
t=*p;
if(t=='P'||t=='R'){if(t==*q)goto prefix;}
while(t==*q){
if(t==0)return 1;
t=*++p;++q;
}
return 0;
}
#pragma opt_common_subs reset
/* Restore one frame's saved registers while unwinding: pop the registers the
 * block marked in JS_FRAME_SAVE_MASK from below JS_FRAME_TOP + JS_FRAME_SAVE_SIZE
 * (16 bytes higher when the block is ID4) into the frame, point JS_FRAME_PREV at
 * the previous frame, and return the restored link register (JS_FRAME_SAVED_LR)
 * the caller looks the exception handler up for. */
s32 Js_RestoreFrameRegisters(void *frame) {
    s32 saveSize;
    s32 *stack;
    s32 reg;

    saveSize = M2C_FIELD(frame, s32 *, JS_FRAME_SAVE_SIZE);
    stack = (s32 *)(M2C_FIELD(frame, s32 *, JS_FRAME_TOP) + saveSize -
                (M2C_FIELD(frame, u8 *, JS_FRAME_ID4) != 0 ? 0x10 : 0));
    for (reg = 15; reg >= 0; reg--) {
        if (M2C_FIELD(frame, u16 *, JS_FRAME_SAVE_MASK) & (1 << reg)) {
            stack--;
            ((s32 *)frame)[reg + 7] = *stack;
        }
    }
    M2C_FIELD(frame, s32 *, JS_FRAME_PREV) = M2C_FIELD(frame, s32 *, JS_FRAME_TOP) + saveSize;
    return M2C_FIELD(frame, s32 *, JS_FRAME_SAVED_LR);
}

/* Decode a handler's data block (state->data) into the unwinder's frame record:
 * copy which JS_KIND_* bits the block's header sets into the record, take the
 * block's register count into the record's save mask, decode the block's two
 * values, then pick the frame pointer the handler's operands are read from. */
void Js_DecodeFrameData(void *frame, void *state) {
    void *DecodeExceptionValue(void *, M2C_UNK *);
    void *lsda;
    void *cursor;
    u8 kind;
    s32 immediate;
    s32 bigEndian;
    s8 immediateFlag;
    s8 id4Flag;
    s8 bigEndianFlag;

    lsda = M2C_FIELD(state, void **, 4);
    kind = M2C_FIELD(lsda, u8 *, 0);
    immediate = kind & JS_KIND_IMMEDIATE;
    if (immediate != 0) {
        immediateFlag = 1;
    } else {
        immediateFlag = 0;
    }
    M2C_FIELD(frame, u8 *, JS_FRAME_IMMEDIATE) = immediateFlag;
    if (kind & JS_KIND_ID4) {
        id4Flag = 1;
    } else {
        id4Flag = 0;
    }
    bigEndian = kind & JS_KIND_BIGENDIAN;
    M2C_FIELD(frame, u8 *, JS_FRAME_ID4) = id4Flag;
    if (bigEndian != 0) {
        bigEndianFlag = 1;
    } else {
        bigEndianFlag = 0;
    }
    M2C_FIELD(frame, u8 *, JS_FRAME_BIGENDIAN) = bigEndianFlag;
    M2C_FIELD(frame, u16 *, JS_FRAME_SAVE_MASK) = (u16) (M2C_FIELD(lsda, u8 *, 1) << 4);
    M2C_FIELD(frame, u16 *, JS_FRAME_SAVE_MASK) = (u16) (M2C_FIELD(frame, u16 *, JS_FRAME_SAVE_MASK) | 0x4000);
    cursor = DecodeExceptionValue((u8 *)lsda + 2, (M2C_UNK *)((u8 *)frame + JS_FRAME_SAVE_SIZE));
    if (immediate != 0) {
        DecodeExceptionValue(cursor, (M2C_UNK *)((u8 *)frame + JS_FRAME_SAVE_VALUE));
    }
    if (immediate != 0) {
        if (bigEndian != 0) {
            M2C_FIELD(frame, s32 *, JS_FRAME_TOP) = M2C_FIELD(frame, s32 *, JS_FRAME_ALT_FP);
        } else {
            M2C_FIELD(frame, s32 *, JS_FRAME_TOP) = M2C_FIELD(frame, s32 *, JS_FRAME_ALT_IP);
        }
    } else {
        M2C_FIELD(frame, s32 *, JS_FRAME_TOP) = M2C_FIELD(frame, s32 *, JS_FRAME_PREV);
    }
}

/* The default exception-table lookup: point the lookup context at the game's
 * whole C++ exception table and report that the table covers every address. */
s32 __FindExceptionTable(void *arg0) {
    CppExceptionState *state = (CppExceptionState *)arg0;
    state->tableStart = (u32 *)&__exception_table_start__;
    state->tableEnd = (u32 *)&__exception_table_end__;
    return 1;
}

/* Skip the header of a CodeWarrior exception data block: decode the first value
 * at +2 (the register mask) and, when the block's flags mark an immediate
 * operand (JS_KIND_IMMEDIATE), the value that operand takes from the frame.
 * Returns the cursor just past the header. */
u8 *SkipExceptionDataHeader(u8 *data) {
    void *DecodeExceptionValue(void *, M2C_UNK *);
    M2C_UNK value;
    u8 flags;
    u8 *cursor;

    flags = *data;
    cursor = (u8 *)DecodeExceptionValue(data + 2, &value);
    if (!(flags & JS_KIND_IMMEDIATE)) {
        return cursor;
    }
    return (u8 *)DecodeExceptionValue(cursor, &value);
}

void func_020746f0(void) {
    M2C_UNK func_02072a68();
    func_02072a68();
}

/* Checksum of an archive block: the sum of its bytes from SAVE_ARCHIVE_SUMMARY
 * up to its SAVE_ARCHIVE_LENGTH, stored at SAVE_ARCHIVE_CHECKSUM.  A block that
 * claims to be longer than SAVE_ARCHIVE_MAX_SIZE has no valid checksum (0). */
s32 SaveArchive_ComputeChecksum(s32 unused,u8 *block) {
u32 length=M2C_FIELD(block,u16 *,SAVE_ARCHIVE_LENGTH);
s32 sum=0,i;
if(length>SAVE_ARCHIVE_MAX_SIZE)return 0;
block+=SAVE_ARCHIVE_SUMMARY;
for(i=SAVE_ARCHIVE_SUMMARY;i<(s32)length;i++)sum+=*block++;
return sum;
}

/* True when `header` is a plausible block header of the card save archive: the
 * block magic, a length within the block, a known block type, version 1, and
 * (except for the save-list head, whose two words are a timestamp) two block
 * links that are within range or empty.  The first argument is unused. */
s32 IsSaveArchiveBlockValid(s32 unused,void *header) {
u16 previous,next; u8 type;
if(M2C_FIELD(header,s32 *,0)!=SAVE_ARCHIVE_MAGIC)return 0;
if(M2C_FIELD(header,u16 *,SAVE_ARCHIVE_LENGTH)>SAVE_ARCHIVE_MAX_SIZE)return 0;
type=M2C_FIELD(header,u8 *,SAVE_ARCHIVE_TYPE);
if(type>=SAVE_ARCHIVE_TYPE_LIMIT)return 0;
if(M2C_FIELD(header,u8 *,SAVE_ARCHIVE_VERSION)!=1)return 0;
if(type!=SAVE_ARCHIVE_TYPE_HEAD) {
previous=M2C_FIELD(header,u16 *,SAVE_ARCHIVE_PREV);
if(previous>SAVE_ARCHIVE_LINK_MAX && previous!=SAVE_ARCHIVE_LINK_NONE)return 0;
next=M2C_FIELD(header,u16 *,SAVE_ARCHIVE_NEXT);
if(next>SAVE_ARCHIVE_LINK_MAX && next!=SAVE_ARCHIVE_LINK_NONE)return 0;
}
return 1;
}

/* True when a save-archive block's stored checksum matches the checksum computed
 * over its contents. The first argument is the save context, unused here. */
u8 SaveArchive_IsChecksumValid(s32 unused, u8 *block) {
    u8 valid;
    if (M2C_FIELD(block, s32 *, SAVE_ARCHIVE_CHECKSUM) == SaveArchive_ComputeChecksum(unused, block)) {
        valid = 1;
    } else {
        valid = 0;
    }
    return valid;
}

/* Check that a save-list record's link chain is consistent: walk its forward (+0x08)
 * and backward (+0x0A) links, and at each step require the linked record to point back
 * at the record it came from, be in use (rank 3), and share the record's kind (+0x06).
 * Returns 1 when the whole chain is consistent, 0 on a cycle or a bad link. */
s32 IsNodeChainValid(s32 table, s32 index) {
    s32 start;
    s32 cur;
    s32 fwd;
    s32 fwdOff;
    s32 fwdIndex;
    s32 bwdOff;
    s32 bwdIndex;
    u16 fwdLink;
    u16 bwdLink;

    cur = (index * 0xC) + table;
    fwd = cur;
loop_1:
    fwdLink = M2C_FIELD(fwd, u16 *, 8);
    if (fwdLink != 0xFFFF) {
        if (fwdLink == index) {
            return 0;
        }
        if ((((s32) M2C_FIELD((table + ((s32) fwdLink >> 2)), u8 *, 0xC0C) >> ((u32) (fwdLink << 0x1E) >> 0x1D)) & 3) != 3) {
            return 0;
        }
        fwdOff = fwd - table;
        fwdIndex = fwdOff / 12;
        fwd = (fwdLink * 0xC) + table;
        if (M2C_FIELD(fwd, u16 *, 0xA) != (u16) fwdIndex) {
            return 0;
        }
        if (M2C_FIELD(fwd, u8 *, 6) != M2C_FIELD(cur, u8 *, 6)) {
            return 0;
        }
        goto loop_1;
    }
    start = cur;
loop_11:
    bwdLink = M2C_FIELD(cur, u16 *, 0xA);
    if (bwdLink != 0xFFFF) {
        if (bwdLink == index) {
            return 0;
        }
        if ((((s32) M2C_FIELD((table + ((s32) bwdLink >> 2)), u8 *, 0xC0C) >> ((u32) (bwdLink << 0x1E) >> 0x1D)) & 3) != 3) {
            return 0;
        }
        bwdOff = cur - table;
        bwdIndex = bwdOff / 12;
        cur = (bwdLink * 0xC) + table;
        if (M2C_FIELD(cur, u16 *, 8) != (u16) bwdIndex) {
            return 0;
        }
        if (M2C_FIELD(cur, u8 *, 6) != M2C_FIELD(start, u8 *, 6)) {
            return 0;
        }
        goto loop_11;
    }
    return 1;
}

