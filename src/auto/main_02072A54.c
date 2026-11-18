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
void *func_02072b20(void *arg0, s32 *arg1) {
    s8 temp_r2;
    u8 temp_r4;
    u8 temp_lr;
    temp_r2 = M2C_FIELD(arg0, s8 *, 0);
    if (!(temp_r2 & 1)) {
        *arg1 = temp_r2 >> 1;
        return arg0 + 1;
    }
    temp_r4 = M2C_FIELD(arg0, u8 *, 1);
    if (!(temp_r2 & 2)) {
        *arg1 = temp_r4 | ((temp_r2 >> 2) << 8);
        return arg0 + 2;
    }
    temp_lr = M2C_FIELD(arg0, u8 *, 2);
    if (!(temp_r2 & 4)) {
        *arg1 = (temp_r2 >> 3) << 16 | temp_r4 << 8 | temp_lr;
        return arg0 + 3;
    }
    *arg1 = (temp_r2 >> 3) << 24 | temp_r4 << 16 | temp_lr << 8 | M2C_FIELD(arg0, u8 *, 3);
    return arg0 + 4;
}
#pragma opt_common_subs off
void *DecodeExceptionValue(u8 *p,u32 *out) {
    u32 a;
    u8 temp_r4;
    u8 temp_lr;
    a=*(u8 *)p;
    if(!(a&1)) { *out=a>>1; return p+1; }
    temp_r4=p[1];
    if(!(a&2)) { *out=temp_r4|((a>>2)<<8); return p+2; }
    temp_lr=p[2];
    if(!(a&4)) { *out=(a>>3)<<16 | temp_r4<<8 | temp_lr; return p+3; }
    *out=(a>>3)<<24 | temp_r4<<16 | temp_lr<<8 | p[3]; return p+4;
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

s32 func_02072dc0(void *arg0) {
    void *func_02072b20(void *, s32 *);
    void *DecodeExceptionValue(u8 *, u32 *);
    void FindExceptionTableHandler(s32, void *);
    s32 func_020744e0(void *, void *);
    M2C_UNK Js_DecodeFrameData(void *, void *);
    s32 sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 sp4;
    s32 sp0;
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
    default:
    case 0:
    case 1:
    case 14:
        return 0xFF;
    case 2:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(temp_r2 + 1, &sp9C) + 4);
block_48:
        var_r2 = M2C_FIELD(arg0, u8 **, 8);
        temp_r0_2 = *var_r2 & 0x1F;
        if (temp_r0_2 != 1) {
            return temp_r0_2;
        }
        do {
            func_02072b20(var_r2 + 1, &sp0);
            var_r2 = &M2C_FIELD(arg0, u8 **, 8)[sp0];
            M2C_FIELD(arg0, u8 **, 8) = var_r2;
            temp_r0 = *var_r2 & 0x1F;
        } while (temp_r0 == 1);
        return temp_r0;
    case 3:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(temp_r2 + 1, &sp94), &sp98) + 4);
        goto block_48;
    case 4:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(temp_r2 + 1, &sp90) + 4);
        goto block_48;
    case 5:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionValue(DecodeExceptionValue(func_02072b20(temp_r2 + 1, &sp84), &sp88), &sp8C) + 4);
        goto block_48;
    case 6:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(temp_r2 + 1, &sp7C), &sp80) + 4);
        goto block_48;
    case 7:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(temp_r2 + 1, &sp74), &sp78) + 4);
        goto block_48;
    case 8:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(func_02072b20(temp_r2 + 1, &sp68), &sp6C), &sp70) + 4);
        goto block_48;
    case 9:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionValue(DecodeExceptionValue(func_02072b20(func_02072b20(temp_r2 + 1, &sp58), &sp5C), &sp60), &sp64) + 4);
        goto block_48;
    case 10:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(temp_r2 + 1, &sp54) + 4);
        goto block_48;
    case 11:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(temp_r2 + 1, &sp4C), &sp50) + 4);
        goto block_48;
    case 12:
        M2C_FIELD(arg0, u8 **, 8) = func_02072b20(DecodeExceptionValue(temp_r2 + 5, &sp44), &sp48);
        goto block_48;
    case 13:
        M2C_FIELD(arg0, u8 **, 8) = func_02072b20(temp_r2 + 1, &sp40);
        goto block_48;
    case 15:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(DecodeExceptionValue(DecodeExceptionValue(temp_r2 + 1, &sp34), &sp38), &sp3C) + (sp34 * 4));
        goto block_48;
    case 16:
        temp_r0_5 = func_02072b20(func_02072b20(temp_r2 + 1, &sp24), &sp28);
        sp30 = M2C_FIELD(temp_r0_5, u8 *, 0) | (M2C_FIELD(temp_r0_5, u8 *, 1) << 8) | (M2C_FIELD(temp_r0_5, u8 *, 2) << 0x10) | (M2C_FIELD(temp_r0_5, u8 *, 3) << 0x18);
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(temp_r0_5 + 4, &sp2C) + 4);
        goto block_48;
    case 17:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (func_02072b20(func_02072b20(func_02072b20(func_02072b20(temp_r2 + 1, &sp14), &sp1C) + 1, &sp18), &sp20) + 4);
        goto block_48;
    case 18:
        M2C_FIELD(arg0, u8 **, 8) = (u8 *) (DecodeExceptionValue(func_02072b20(func_02072b20(temp_r2 + 1, &sp8) + 1, &spC), &sp10) + 4);
        goto block_48;
    case 19:
        M2C_FIELD(arg0, u8 **, 8) = func_02072b20(temp_r2 + 1, &sp4);
        goto block_48;
    }
}

void func_02073148(s32 arg0, void *arg1, s32 arg2) {
u32 func_020722fc(s32,u32);
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
q=func_02072b20(p+1,&spa0);
M2C_FIELD(arg1,u8 **,8)+=spa0;break;
case 2:
q=func_02072b20(p+1,&sp9c);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(void *,s32))f)(M2C_FIELD(arg0,u8 **,0x18)+sp9c,-1);M2C_FIELD(arg1,u8 **,8)=end;break;
case 3:
flag=op&64;
q=func_02072b20(p+1,&sp94);
q=func_02072b20(q,&sp98);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
if((flag?(u8)M2C_FIELD(arg0+sp94*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),u8 *,sp94))) ((void (*)(void *,s32))f)(M2C_FIELD(arg0,u8 **,0x18)+sp98,-1);M2C_FIELD(arg1,u8 **,8)=end;break;
case 4:
flag=op&32;
q=func_02072b20(p+1,&sp90);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(s32,s32))f)((flag?(s32)M2C_FIELD(arg0+sp90*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp90)),-1);M2C_FIELD(arg1,u8 **,8)=end;break;
case 5:
q=func_02072b20(p+1,&sp84);
q=DecodeExceptionValue(q,&sp88);
q=DecodeExceptionValue(q,&sp8c);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
v=(s32)(M2C_FIELD(arg0,u8 **,0x18)+sp84)+sp88*sp8c;n=sp88;while(n){v-=sp8c;((void (*)(s32,s32))f)(v,-1);--n;}M2C_FIELD(arg1,u8 **,8)=end;break;
case 6:
flag=op&32;
q=func_02072b20(p+1,&sp7c);
q=func_02072b20(q,&sp80);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(s32,s32))f)((flag?(s32)M2C_FIELD(arg0+sp7c*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp7c))+sp80,0);M2C_FIELD(arg1,u8 **,8)=end;break;
case 7:
flag=op&32;
q=func_02072b20(p+1,&sp74);
q=func_02072b20(q,&sp78);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(s32,s32))f)((flag?(s32)M2C_FIELD(arg0+sp74*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp74))+sp78,-1);M2C_FIELD(arg1,u8 **,8)=end;break;
case 8:
flag=op&32;
q=func_02072b20(p+1,&sp68);
q=func_02072b20(q,&sp6c);
q=func_02072b20(q,&sp70);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
if(((op&64)?(s16)M2C_FIELD(arg0+sp68*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s16 *,sp68))) ((void (*)(s32,s32))f)((flag?(s32)M2C_FIELD(arg0+sp6c*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp6c))+sp70,-1);M2C_FIELD(arg1,u8 **,8)=end;break;
case 9:
flag=op&32;
q=func_02072b20(p+1,&sp58);
q=func_02072b20(q,&sp5c);
q=DecodeExceptionValue(q,&sp60);
q=DecodeExceptionValue(q,&sp64);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
v=(flag?(s32)M2C_FIELD(arg0+sp58*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp58))+sp5c;n=sp60;v+=n*sp64;while(n){v-=sp64;((void (*)(s32,s32))f)(v,-1);--n;}M2C_FIELD(arg1,u8 **,8)=end;break;
case 10:
flag=op&32;
q=func_02072b20(p+1,&sp54);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(s32))f)((flag?(s32)M2C_FIELD(arg0+sp54*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp54)));M2C_FIELD(arg1,u8 **,8)=end;break;
case 11:
flag=op&32;
q=func_02072b20(p+1,&sp4c);
q=func_02072b20(q,&sp50);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
if(((op&64)?(u8)M2C_FIELD(arg0+sp4c*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),u8 *,sp4c))) ((void (*)(s32))f)((flag?(s32)M2C_FIELD(arg0+sp50*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp50)));M2C_FIELD(arg1,u8 **,8)=end;break;
case 12:
if((s32)p==arg2) return;
q=DecodeExceptionValue(p+5,&sp44);q=func_02072b20(q,&sp48);M2C_FIELD(arg1,u8 **,8)=q;break;
case 13:
q=func_02072b20(p+1,&sp40);
v=(s32)(M2C_FIELD(arg0,u8 **,0x18)+sp40); f=M2C_FIELD(v,u32 *,8); if(f) { w=M2C_FIELD(v,s32 *,0); if(M2C_FIELD(arg0,s32 *,4)==w) M2C_FIELD(arg0,u32 *,8)=f; else ((void (*)(s32,s32))f)(w,-1); } M2C_FIELD(arg1,u8 **,8)=q; break;
case 14:
goto bad;
case 15:
if((s32)p==arg2) return;
q=DecodeExceptionValue(p+1,&sp34);
q=DecodeExceptionValue(q,&sp38);
q=func_02072b20(q,&sp3c);
M2C_FIELD(arg1,u8 **,8)=q+sp34*4;break;
case 16:
flag=op&32;
q=func_02072b20(p+1,&sp24);
q=func_02072b20(q,&sp28);
sp30=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;q=func_02072b20(q+4,&sp2c);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
((void (*)(s32,s32))f)((flag?(s32)M2C_FIELD(arg0+sp24*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp24))+sp28,sp30+sp2c);M2C_FIELD(arg1,u8 **,8)=end;break;
case 17:
flag=op&32;
q=func_02072b20(p+1,&sp14);
q=func_02072b20(q,&sp1c);
flag2=*q++ &32;q=func_02072b20(q,&sp18);q=func_02072b20(q,&sp20);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
v=(flag?(s32)M2C_FIELD(arg0+sp14*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp14));w=flag2?M2C_FIELD(arg0+sp18*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp18);((void (*)(s32,s32))f)(v+sp1c,w+sp20);M2C_FIELD(arg1,u8 **,8)=end;break;
case 18:
flag=op&32;
q=func_02072b20(p+1,&sp8);
flag2=*q++ &32;q=func_02072b20(q,&spc);q=DecodeExceptionValue(q,(u32 *)&sp10);
f=(u32)q[0]|(u32)q[1]<<8|(u32)q[2]<<16|(u32)q[3]<<24;end=q+4;
v=(flag?(s32)M2C_FIELD(arg0+sp8*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,sp8));w=flag2?M2C_FIELD(arg0+spc*4,s32 *,0x1c):M2C_FIELD(M2C_FIELD(arg0,u8 **,0x18),s32 *,spc);v+=w;n=func_020722fc(v,sp10);while(n){v-=sp10;((void (*)(s32,s32))f)(v,-1);--n;}M2C_FIELD(arg1,u8 **,8)=end;break;
case 19:
q=func_02072b20(p+1,&sp4);
M2C_FIELD(arg1,u8 **,8)=q;break;
default: bad: func_020742e0();break;
} if(op&128) M2C_FIELD(arg1,u8 **,8)=0;goto loop;
}

