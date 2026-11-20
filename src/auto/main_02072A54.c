/* 15 functions from 0x02072A54 to 0x020739F8 (main), found by ds-decomp. */
#include "common.h"
#include "cpp_exception.h"
typedef struct { u8 type:5; } RuntimeType;

/* The exception-lookup context shared by __FindExceptionTable and the landing-pad
 * lookup.  __FindExceptionTable fills the table range; the lookup then records the
 * enclosing function, its language-specific data area (LSDA) and the landing pad,
 * which the unwinder walks from there. */
#define EXC_LOOKUP_FUNC_START  0x00 /* u32 address of the function containing the PC */
#define EXC_LOOKUP_LSDA        0x04 /* void *language-specific data area of that function */
#define EXC_LOOKUP_LANDING_PAD 0x08 /* void *landing pad the PC maps to */
#define EXC_LOOKUP_TABLE_START 0x0C /* u32 *start of the exception table */
#define EXC_LOOKUP_TABLE_END   0x10 /* u32 *end of the exception table */
#define EXC_TABLE_ENTRY_SIZE   12   /* bytes per exception table entry */
#define EXC_ENTRY_INLINE_LSDA  0x01 /* entry word 1 bit 0: the LSDA follows inline at entry+8 */

s32 func_02072a54(void) { return 7; }

s32 func_02072a68(void) {
    return 0x18;
}

s32 func_02072a78(s32 unused,u8 *p,u32 *count) {
s32 func_02072a54(void);
u32 i;
u32 n=*count;
for(i=0;i<n;i++) {
s32 c=func_02072a54();
p[i]=(short)c;
if((u8)c==13 || (u8)c==10) { *count=i+1; break; }
}
return 0;
}

s32 func_02072ac8(s32 unused,u8 *p,u32 *count) {
void func_02072a40(u8 *);
u32 i;
u32 n=*count;
for(i=0;i<n;i++) func_02072a40(p+i);
return 0;
}

s32 func_02072afc(void) {
    return 0;
}

s32 func_02072b04(void *buf) {
    /* save context */
    /* can't express stmia of registers in C directly */
    return 0;
}

#pragma opt_common_subs off
/* Decode one signed compact value of a CodeWarrior exception table: the same
 * encoding as DecodeExceptionValue, but the first byte is signed, so the value
 * is sign-extended and can be negative (it is used for offsets). Returns the
 * cursor just past the value. */
void *DecodeExceptionSignedValue(void *cursor, s32 *out) {
    s8 first;
    u8 second;
    u8 third;
    first = M2C_FIELD(cursor, s8 *, 0);
    if (!(first & CPP_EXCEPTION_VALUE_LONG2)) {
        *out = first >> 1;
        return cursor + 1;
    }
    second = M2C_FIELD(cursor, u8 *, 1);
    if (!(first & CPP_EXCEPTION_VALUE_LONG3)) {
        *out = second | ((first >> 2) << 8);
        return cursor + 2;
    }
    third = M2C_FIELD(cursor, u8 *, 2);
    if (!(first & CPP_EXCEPTION_VALUE_LONG4)) {
        *out = (first >> 3) << 16 | second << 8 | third;
        return cursor + 3;
    }
    *out = (first >> 3) << 24 | second << 16 | third << 8 | M2C_FIELD(cursor, u8 *, 3);
    return cursor + 4;
}
#pragma opt_common_subs off
/* Decode one compact value of a CodeWarrior exception table: bits 0..2 of the
 * first byte say how many bytes follow (none, one, two or three), the first
 * byte's other bits are the value's high bits and the following bytes are
 * little-endian. Returns the cursor just past the value. */
void *DecodeExceptionValue(u8 *cursor,u32 *out) {
    u32 first;
    u8 second;
    u8 third;
    first=*cursor;
    if(!(first&CPP_EXCEPTION_VALUE_LONG2)) { *out=first>>1; return cursor+1; }
    second=cursor[1];
    if(!(first&CPP_EXCEPTION_VALUE_LONG3)) { *out=second|((first>>2)<<8); return cursor+2; }
    third=cursor[2];
    if(!(first&CPP_EXCEPTION_VALUE_LONG4)) { *out=(first>>3)<<16 | second<<8 | third; return cursor+3; }
    *out=(first>>3)<<24 | second<<16 | third<<8 | cursor[3]; return cursor+4;
}
#pragma opt_common_subs reset
void *FindExceptionTableEntry(u32 *p,s32 n,u32 addr) {
s32 mid;
u32 *q;
s32 lo=0;
s32 hi=n-1;
while(lo<=hi) {
mid=(lo+hi)>>1;
q=(u32 *)((u8 *)p+mid*12);
if(addr<q[0]) hi=mid-1;
else if(addr>q[0]+(q[1]&~1U)) lo=mid+1;
else return q;
}
return 0;
}

/* Find the exception table entry that covers the program counter `pc` and resolve
   its landing pad: record the enclosing function and its language-specific data
   area in the lookup context, then walk the LSDA's delta-encoded call-site table
   for the site containing the PC and set the landing pad to that site's offset. */
void FindExceptionTableHandler(s32 pc, void *ctx) {
    s32 __FindExceptionTable(void *, s32);
    void *DecodeExceptionValue(u8 *, u32 *);
    void *FindExceptionTableEntry(u32 *, s32, u32);
    s32 SkipExceptionDataHeader(void *);
    u32 siteOffset;
    u32 siteLength;
    u32 landingOffset;
    u32 *tableStart;
    u32 *entry;
    s32 tableEnd;
    u32 pcOffset;
    u32 cursorOffset;
    void *p;
    void *lsda;
    M2C_FIELD(ctx, s32 *, EXC_LOOKUP_LSDA) = 0;
    M2C_FIELD(ctx, s32 *, EXC_LOOKUP_LANDING_PAD) = 0;
    if (__FindExceptionTable(ctx, pc) == 0) {
        return;
    }
    tableStart = M2C_FIELD(ctx, u32 *, EXC_LOOKUP_TABLE_START);
    tableEnd = M2C_FIELD(ctx, s32 *, EXC_LOOKUP_TABLE_END);
    entry = FindExceptionTableEntry(tableStart, (tableEnd - (s32)tableStart) / EXC_TABLE_ENTRY_SIZE, (u32)pc);
    if (entry == NULL) {
        return;
    }
    if (M2C_FIELD(entry, s32 *, 4) & EXC_ENTRY_INLINE_LSDA) {
        lsda = (void *)((u8 *)entry + 8);
    } else {
        lsda = M2C_FIELD(entry, void **, 8);
    }
    M2C_FIELD(ctx, void **, EXC_LOOKUP_LSDA) = lsda;
    M2C_FIELD(ctx, s32 *, EXC_LOOKUP_FUNC_START) = M2C_FIELD(entry, s32 *, 0);
    pcOffset = (u32)(pc - M2C_FIELD(entry, s32 *, 0));
    p = SkipExceptionDataHeader(M2C_FIELD(ctx, void **, EXC_LOOKUP_LSDA));
    cursorOffset = 0;
loop:
    p = DecodeExceptionValue((u8 *)p, &siteOffset);
    if (siteOffset == 0) {
        return;
    }
    p = DecodeExceptionValue((u8 *)p, &siteLength);
    p = DecodeExceptionValue((u8 *)p, &landingOffset);
    {
        u32 siteStart = cursorOffset + siteOffset;
        if (pcOffset < siteStart) {
            return;
        }
        cursorOffset = siteStart + siteLength;
        if (pcOffset > cursorOffset) {
            goto loop;
        }
    }
    M2C_FIELD(ctx, void **, EXC_LOOKUP_LANDING_PAD) = (void *)((u8 *)M2C_FIELD(ctx, void **, EXC_LOOKUP_LSDA) + landingOffset);
    return;
}

u8 func_02072da4(void *arg0) {
u8 *p=M2C_FIELD(arg0,u8 **,8);
s32 result;
if(p) result=*p&31;
else result=0;
return (u8)result;
}

#pragma push
#pragma opt_common_subs off
s32 func_02072dc0(void *arg0) {


    void FindExceptionTableHandler(s32, void *);
    s32 func_020744e0(void *, void *);
    M2C_UNK Js_DecodeFrameData(void *, void *);
    s32 operands[40];
    s32 temp_r0;
    s32 temp_r0_2;
    u32 temp_r0_4;
    u8 *temp_r0_5;
    u8 *temp_r2;
    u8 *var_r2;
    u8 temp_r0_3;

loop_1:
    temp_r2 = M2C_FIELD(arg0, u8 **, 8);
    if ((temp_r2 == NULL) || (temp_r0_3 = *temp_r2, ((temp_r0_3 & 0x80) != 0))) {
        FindExceptionTableHandler(func_020744e0(arg0 + 0x18, arg0), arg0);
        if (M2C_FIELD(arg0, s32 *, 4) == 0) {
            return 0xFF;
        }
        Js_DecodeFrameData(arg0 + 0x18, arg0);
        if (M2C_FIELD(arg0, u8 **, 8) != NULL) {
            goto block_48;
        }
        goto loop_1;
    }
    temp_r0_4 = temp_r0_3 & 0x1F;
    switch (temp_r0_4) {
    case 2:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionSignedValue(temp_r2 + 1, &operands[39]) + 4);
        break;
    case 3:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionSignedValue(DecodeExceptionSignedValue(temp_r2 + 1, &operands[37]), &operands[38]) + 4);
        break;
    case 4:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionSignedValue(temp_r2 + 1, &operands[36]) + 4);
        break;
    case 5:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionValue(DecodeExceptionValue(DecodeExceptionSignedValue(temp_r2 + 1, &operands[33]), &operands[34]), &operands[35]) + 4);
        break;
    case 6:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionSignedValue(DecodeExceptionSignedValue(temp_r2 + 1, &operands[31]), &operands[32]) + 4);
        break;
    case 7:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionSignedValue(DecodeExceptionSignedValue(temp_r2 + 1, &operands[29]), &operands[30]) + 4);
        break;
    case 8:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionSignedValue(DecodeExceptionSignedValue(DecodeExceptionSignedValue(temp_r2 + 1, &operands[26]), &operands[27]), &operands[28]) + 4);
        break;
    case 9:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionValue(DecodeExceptionValue(DecodeExceptionSignedValue(DecodeExceptionSignedValue(temp_r2 + 1, &operands[22]), &operands[23]), &operands[24]), &operands[25]) + 4);
        break;
    case 10:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionSignedValue(temp_r2 + 1, &operands[21]) + 4);
        break;
    case 11:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionSignedValue(DecodeExceptionSignedValue(temp_r2 + 1, &operands[19]), &operands[20]) + 4);
        break;
    case 12:
        M2C_FIELD(arg0, u8 **, 8) = DecodeExceptionSignedValue(DecodeExceptionValue(temp_r2 + 5, &operands[17]), &operands[18]);
        break;
    case 13:
        M2C_FIELD(arg0, u8 **, 8) = DecodeExceptionSignedValue(temp_r2 + 1, &operands[16]);
        break;
    case 15:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionSignedValue(DecodeExceptionValue(DecodeExceptionValue(temp_r2 + 1, &operands[13]), &operands[14]), &operands[15]) + (operands[13] * 4));
        break;
    case 16:
        temp_r0_5 = DecodeExceptionSignedValue(DecodeExceptionSignedValue(temp_r2 + 1, &operands[9]), &operands[10]);
        temp_r0_5 += 4;
        operands[12] = (u32)temp_r0_5[-4] |
                       ((u32)temp_r0_5[-3] << 8) |
                       ((u32)temp_r0_5[-2] << 16) |
                       ((u32)temp_r0_5[-1] << 24);
        M2C_FIELD(arg0, u8 **, 8) = (u8 *)DecodeExceptionSignedValue(temp_r0_5, &operands[11]) + 4;
        break;
    case 17:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionSignedValue(DecodeExceptionSignedValue(DecodeExceptionSignedValue(DecodeExceptionSignedValue(temp_r2 + 1, &operands[5]), &operands[7]) + 1, &operands[6]), &operands[8]) + 4);
        break;
    case 18:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionValue(DecodeExceptionSignedValue(DecodeExceptionSignedValue(temp_r2 + 1, &operands[2]) + 1, &operands[3]), &operands[4]) + 4);
        break;
    case 19:
        M2C_FIELD(arg0, u8 **, 8) = DecodeExceptionSignedValue(temp_r2 + 1, &operands[1]);
        break;
    default:
        return 0xFF;
    }
block_48:
    var_r2 = M2C_FIELD(arg0, u8 **, 8);
    temp_r0 = *var_r2 & 0x1F;
    if (temp_r0 == 1) {
        s32 *offset = &operands[0];
        do {
            DecodeExceptionSignedValue(var_r2 + 1, offset);
            var_r2 = (M2C_FIELD(arg0, u8 **, 8) += operands[0]);
            temp_r0 = *var_r2 & 0x1F;
        } while (temp_r0 == 1);
    }
    return temp_r0;
}
#pragma pop
void func_02073148(s32 arg0, void *arg1, s32 arg2) {
u32 U32DivideRem(s32,u32);
s32 func_020744e0(void *,void *);
void func_020742e0(void);
s32 Js_DecodeFrameData(void *,void *);
s32 spa0;
s32 sp9c;
s32 sp98;
s32 sp94;
s32 sp90;
s32 sp8c;
s32 sp88;
s32 sp84;
s32 sp80;
s32 sp7c;
s32 sp78;
s32 sp74;
s32 sp70;
s32 sp6c;
s32 sp68;
s32 sp64;
s32 sp60;
s32 sp5c;
s32 sp58;
s32 sp54;
s32 sp50;
s32 sp4c;
s32 sp48;
s32 sp44;
s32 sp40;
s32 sp3c;
s32 sp38;
s32 sp34;
s32 sp30;
s32 sp2c;
s32 sp28;
s32 sp24;
s32 sp20;
s32 sp1c;
s32 sp18;
s32 sp14;
s32 sp10;
s32 spc;
s32 sp8;
s32 sp4;
u8 *p,*q,*end; u32 f,g,flag,flag2; s32 v,w,n; u8 op;
loop:
p=M2C_FIELD(arg1,u8 **,8);
if(!p) {
FindExceptionTableHandler(func_020744e0(arg0,arg1),arg1);
if(!M2C_FIELD(arg1,s32 *,4)) func_020742e0();
Js_DecodeFrameData(arg0,arg1);
p=M2C_FIELD(arg1,u8 **,8);
if(!p) goto loop;
}
op=*p;
switch(op&31) {
case 1:
q=DecodeExceptionSignedValue(p+1,&spa0);
M2C_FIELD(arg1,u8 **,8)+=spa0;break;
case 2:
q=DecodeExceptionSignedValue(p+1,&sp9c);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(void *,s32))f)(M2C_FIELD(arg0,u8 **,0x18)+sp9c,-1);M2C_FIELD(arg1,u8 **,8)=end;break;
case 3:
flag=op&64;
q=DecodeExceptionSignedValue(p+1,&sp94);
q=DecodeExceptionSignedValue(q,&sp98);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
if((flag?(u8)M2C_FIELD(arg0+sp94*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),u8 *,sp94))) ((void (*)(void *,s32))f)(M2C_FIELD(arg0,u8 **,0x18)+sp98,-1);M2C_FIELD(arg1,u8 **,8)=end;break;
case 4:
flag=op&32;
q=DecodeExceptionSignedValue(p+1,&sp90);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(s32,s32))f)((flag?(s32)M2C_FIELD(arg0+sp90*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp90)),-1);M2C_FIELD(arg1,u8 **,8)=end;break;
case 5:
q=DecodeExceptionSignedValue(p+1,&sp84);
q=DecodeExceptionValue(q,&sp88);
q=DecodeExceptionValue(q,&sp8c);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
v=(s32)(M2C_FIELD(arg0,u8 **,0x18)+sp84)+sp88*sp8c;n=sp88;while(n){v-=sp8c;((void (*)(s32,s32))f)(v,-1);--n;}M2C_FIELD(arg1,u8 **,8)=end;break;
case 6:
flag=op&32;
q=DecodeExceptionSignedValue(p+1,&sp7c);
q=DecodeExceptionSignedValue(q,&sp80);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(s32,s32))f)((flag?(s32)M2C_FIELD(arg0+sp7c*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp7c))+sp80,0);M2C_FIELD(arg1,u8 **,8)=end;break;
case 7:
flag=op&32;
q=DecodeExceptionSignedValue(p+1,&sp74);
q=DecodeExceptionSignedValue(q,&sp78);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(s32,s32))f)((flag?(s32)M2C_FIELD(arg0+sp74*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp74))+sp78,-1);M2C_FIELD(arg1,u8 **,8)=end;break;
case 8:
flag=op&32;
q=DecodeExceptionSignedValue(p+1,&sp68);
q=DecodeExceptionSignedValue(q,&sp6c);
q=DecodeExceptionSignedValue(q,&sp70);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
if(((op&64)?(s16)M2C_FIELD(arg0+sp68*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s16 *,sp68))) ((void (*)(s32,s32))f)((flag?(s32)M2C_FIELD(arg0+sp6c*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp6c))+sp70,-1);M2C_FIELD(arg1,u8 **,8)=end;break;
case 9:
flag=op&32;
q=DecodeExceptionSignedValue(p+1,&sp58);
q=DecodeExceptionSignedValue(q,&sp5c);
q=DecodeExceptionValue(q,&sp60);
q=DecodeExceptionValue(q,&sp64);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
v=(flag?(s32)M2C_FIELD(arg0+sp58*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp58))+sp5c;n=sp60;v+=n*sp64;while(n){v-=sp64;((void (*)(s32,s32))f)(v,-1);--n;}M2C_FIELD(arg1,u8 **,8)=end;break;
case 10:
flag=op&32;
q=DecodeExceptionSignedValue(p+1,&sp54);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(s32))f)((flag?(s32)M2C_FIELD(arg0+sp54*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp54)));M2C_FIELD(arg1,u8 **,8)=end;break;
case 11:
flag=op&32;
q=DecodeExceptionSignedValue(p+1,&sp4c);
q=DecodeExceptionSignedValue(q,&sp50);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
if(((op&64)?(u8)M2C_FIELD(arg0+sp4c*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),u8 *,sp4c))) ((void (*)(s32))f)((flag?(s32)M2C_FIELD(arg0+sp50*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp50)));M2C_FIELD(arg1,u8 **,8)=end;break;
case 12:
if((s32)p==arg2) return;
q=DecodeExceptionValue(p+5,&sp44);q=DecodeExceptionSignedValue(q,&sp48);M2C_FIELD(arg1,u8 **,8)=q;break;
case 13:
q=DecodeExceptionSignedValue(p+1,&sp40);
v=(s32)(M2C_FIELD(arg0,u8 **,0x18)+sp40); f=M2C_FIELD(v,u32 *,8); if(f) { w=M2C_FIELD(v,s32 *,0); if(M2C_FIELD(arg0,s32 *,4)==w) M2C_FIELD(arg0,u32 *,8)=f; else ((void (*)(s32,s32))f)(w,-1); } M2C_FIELD(arg1,u8 **,8)=q; break;
case 14:
goto bad;
case 15:
if((s32)p==arg2) return;
q=DecodeExceptionValue(p+1,&sp34);
q=DecodeExceptionValue(q,&sp38);
q=DecodeExceptionSignedValue(q,&sp3c);
M2C_FIELD(arg1,u8 **,8)=q+sp34*4;break;
case 16:
flag=op&32;
q=DecodeExceptionSignedValue(p+1,&sp24);
q=DecodeExceptionSignedValue(q,&sp28);
sp30=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;q=DecodeExceptionSignedValue(q+4,&sp2c);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(s32,s32))f)((flag?(s32)M2C_FIELD(arg0+sp24*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp24))+sp28,sp30+sp2c);M2C_FIELD(arg1,u8 **,8)=end;break;
case 17:
flag=op&32;
q=DecodeExceptionSignedValue(p+1,&sp14);
q=DecodeExceptionSignedValue(q,&sp1c);
flag2=*q++ &32;q=DecodeExceptionSignedValue(q,&sp18);q=DecodeExceptionSignedValue(q,&sp20);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
v=(flag?(s32)M2C_FIELD(arg0+sp14*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp14));w=flag2?M2C_FIELD(arg0+sp18*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp18);((void (*)(s32,s32))f)(v+sp1c,w+sp20);M2C_FIELD(arg1,u8 **,8)=end;break;
case 18:
flag=op&32;
q=DecodeExceptionSignedValue(p+1,&sp8);
flag2=*q++ &32;q=DecodeExceptionSignedValue(q,&spc);q=DecodeExceptionValue(q,(u32 *)&sp10);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
v=(flag?(s32)M2C_FIELD(arg0+sp8*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp8));w=flag2?M2C_FIELD(arg0+spc*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,spc);v+=w;n=U32DivideRem(v,sp10);while(n){v-=sp10;((void (*)(s32,s32))f)(v,-1);--n;}M2C_FIELD(arg1,u8 **,8)=end;break;
case 19:
q=DecodeExceptionSignedValue(p+1,&sp4);
M2C_FIELD(arg1,u8 **,8)=q;break;
default: bad: func_020742e0();break;
} if(op&128) M2C_FIELD(arg1,u8 **,8)=0;goto loop;
}

