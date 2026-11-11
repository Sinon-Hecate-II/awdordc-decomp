/* 13 functions from 0x02014B34 to 0x02015AA0 (main), found by ds-decomp. */
#include "common.h"
typedef struct RomHeader_020152c8 { u8 unk_0[0x80]; u32 offset; } RomHeader_020152c8;
static inline u32 FilePosition_020152c8(void *file) { return M2C_FIELD(file,u32 *,0x2c)-M2C_FIELD(file,u32 *,0x24); }


/* Select units by state into priority groups, then dispatch the matching network action. */

u32 func_02015248(void *arg0) {
 s32 FileRead(void *,s32,s32);
 void FileSeek(void *,s32,s32);
 void *p;
 u32 result;
 u32 sp0[24];
 s32 pos;
 p = NULL;
 result = 0;
 if (arg0 != NULL) {
     pos = M2C_FIELD(arg0, s32 *, 0x2c) - M2C_FIELD(arg0, s32 *, 0x24);
     if ((u32)FileRead(arg0, (s32)sp0, 0x60) >= 0x60U) {
         p = sp0;
     }
     FileSeek(arg0, pos, 0);
 } else {
     p = (void *)0x027ffe00;
 }
 if (p != NULL) {
     result = M2C_FIELD(p, s32 *, 0x2c) + 0x268 + M2C_FIELD(p, s32 *, 0x3c);
     if (result < 0x10000U) {
         result = 0x10000;
     }
 }
 return result;
}

void AutoloadCallback(void);
#pragma opt_strength_reduction off
#pragma opt_common_subs off
s32 func_020152c8(void *arg0,void *arg1,s32 arg2){
 s32 FileRead(void *,s32,s32);void FileSeek(void *,s32,s32);void InitFileRequest();s32 func_0200b144();void func_0200b99c();M2C_UNK MI_CpuCopy8(s32,s32,s32);void func_02018470();void func_02018484();void func_0200ba9c();void func_02015724(void *,u32,u32,s32);void DC_FlushRange();
 extern u8 data_020f554c[];extern u32 *data_020f5548;
 u8 file[0x48];u32 info[4];s32 result,owned;u32 size;u32 left;void *p,*header,*table;u32 base,readBase,origin,n; s32 i;u32 *ranges;
 size=arg2;result=0;
 if(size>=0x164){
 left=size;p=arg1;owned=0;header=0;table=0;p+=0x160;left-=0x160;
 if(arg0){
 origin=M2C_FIELD(arg0,u32 *,0x2c)-M2C_FIELD(arg0,u32 *,0x24);
 if(FileRead(arg0,(s32)arg1,0x160)<0x160)left=0;
 base=M2C_FIELD(arg1,u32 *,0x80);if(!base)base=0x1000000;
 }else{
 base=((RomHeader_020152c8 *)0x027ffe00)->offset;if(!base)base=0x1000000;owned=1;
 InitFileRequest(file);
 n=func_0200b144(data_020f554c,3);
 func_0200b99c(file,n,0,base+0x88,-1);
 arg0=file;origin=M2C_FIELD(arg0,u32 *,0x2c)-M2C_FIELD(arg0,u32 *,0x24);
 MI_CpuCopy8(0x027ffe00,(s32)arg1,0x160);
 M2C_FIELD(arg1,u32 *,0x60)|=0x406000;
 }
 if(left<0x88)left=0;
 else{FileSeek(arg0,origin+base,0);FileRead(arg0,(s32)p,0x88);p+=0x88;left-=0x88;}
 if(left>=0x70){
 header=p;func_02018470(p);
 p+=0x70;left-=0x70;func_02018484(header,0,0x160,arg1,3);
 n=M2C_FIELD(arg0,u32 *,8);
 for(i=0;i<3&&M2C_FIELD(n,s8 *,i)!=0;i++);
 MI_CpuCopy8(n,(s32)header+0x10,i);M2C_FIELD(header,u32 *,0x14)=i;
 }else left=0;
 if(left<0x10)left=0;
 else{
 M2C_FIELD(p,u32 *,0)=0;
 M2C_FIELD(p,u32 *,4)=M2C_FIELD(arg1,u32 *,0x20)+(origin+M2C_FIELD(arg0,u32 *,0x24));
 M2C_FIELD(p,u32 *,8)=M2C_FIELD(arg1,u32 *,0x30)+(origin+M2C_FIELD(arg0,u32 *,0x24));
 table=p;p+=0x10;left-=0x10;
 }
 if(left>=M2C_FIELD(arg1,u32 *,0x2c)+M2C_FIELD(arg1,u32 *,0x3c)){
 readBase=M2C_FIELD(arg0,u32 *,0x24);
 FileSeek(arg0,M2C_FIELD(table,u32 *,4)-readBase,0);
 FileRead(arg0,(s32)p,M2C_FIELD(arg1,u32 *,0x2c));
 func_02018484(header,M2C_FIELD(table,u32 *,4),M2C_FIELD(arg1,u32 *,0x2c),p,3);
 left=M2C_FIELD(arg1,u32 *,0x2c);
 FileSeek(arg0,M2C_FIELD(table,u32 *,8)-readBase,0);
 FileRead(arg0,(s32)p+left,M2C_FIELD(arg1,u32 *,0x3c));
 func_02018484(header,M2C_FIELD(table,u32 *,8),M2C_FIELD(arg1,u32 *,0x3c),p+left,3);
 result=1;
 }else if(left>=0xcc00){
 left=M2C_FIELD(arg0,u32 *,0x24);base=M2C_FIELD(table,u32 *,4);
 FileSeek(arg0,base-left,0);FileRead(arg0,(s32)p,0x4400);
 func_02018484(header,base,0x4400,p,3);
 FileSeek(arg0,base+0x4400-left,0);FileRead(arg0,(s32)p+0x4400,0x4400);
 func_02018484(header,base+0x4400,0x4400,p+0x4400,2);
 FileSeek(arg0,base+0x8800-left,0);FileRead(arg0,(s32)p+0x8800,0x4400);
 func_02018484(header,base+0x8800,0x4400,p+0x8800,2);result=1;
 }
 FileSeek(arg0,origin,0);
 if(owned){
 func_0200ba9c(file);
 if(result){
 info[0]=M2C_FIELD(arg1,u32 *,0x20);info[1]=M2C_FIELD(arg1,u32 *,0x28)-M2C_FIELD(arg1,u32 *,0x20);info[2]=M2C_FIELD(header,u32 *,0x48)-M2C_FIELD(arg1,u32 *,0x20);info[3]=size;
 ranges=data_020f5548;
 func_02015724(info,0x4000,0x8000,1);
 while(ranges[1]){func_02015724(info,ranges[0],ranges[0]+ranges[1],0);ranges+=2;}
 n=(u32)AutoloadCallback-M2C_FIELD(arg1,u32 *,0x28);M2C_FIELD(M2C_FIELD(header,void **,0x48),u32 *,n)=0xe12fff1e;
 }
 }
 if(result)DC_FlushRange(arg1,size);
 }
 return result;
}
void func_02015724(void *arg0, u32 arg1, u32 arg2, s32 arg3) {
    M2C_UNK MI_CpuFill8(s32, M2C_UNK, s32);
    M2C_UNK MI_CpuCopy8(s32, s32, s32);
    u32 temp_ip;
    u32 temp_r1;
    u32 var_lr;
    u32 var_r2;

    var_r2 = arg2;
    var_lr = arg1;
    temp_ip = M2C_FIELD(arg0, u32 *, 0);
    if (var_lr < 0x4000U) {
        var_lr = 0x4000;
    }
    if (var_r2 > 0x8000U) {
        var_r2 = 0x8000;
    }
    temp_r1 = temp_ip + M2C_FIELD(arg0, s32 *, 0xC);
    if (var_lr < temp_ip) {
        var_lr = temp_ip;
    }
    if (var_r2 > temp_r1) {
        var_r2 = temp_r1;
    }
    if (var_lr >= var_r2) {
        return;
    }
    if (arg3 != 0) {
        MI_CpuFill8(M2C_FIELD(arg0, s32 *, 8) + var_lr, 0, var_r2 - var_lr);
        return;
    }
    MI_CpuCopy8(M2C_FIELD(arg0, s32 *, 4) + var_lr, M2C_FIELD(arg0, s32 *, 8) + var_lr, var_r2 - var_lr);
}

#pragma push
#pragma scheduling off
s32 func_0201579c(s32 arg0, s32 arg1) {
    s32 OS_DisableInterrupts();
    M2C_UNK OS_RestoreInterrupts(s32);
    void func_02015a2c(void *, void *);
    s32 func_02015c18(void *, void *);
    M2C_UNK func_02015f94(void *, s32, void *);
    M2C_UNK func_020161bc(void *);
    s32 func_02018418();
    M2C_UNK func_0201869c(void *, M2C_UNK);
    s32 func_0201871c();
    M2C_UNK func_02018738(void *);
    extern u8 data_02131184;
    extern void *data_02136c4c;
    u8 var_r4;
    u8 var_r6;
    s32 temp_r2;
    s32 temp_r5;
    s32 temp_r6;
    void *temp_r9; s32 sequence;

    var_r4 = 0xFF;
    temp_r5 = OS_DisableInterrupts();
    if (func_02018418() == 0) {
        OS_RestoreInterrupts(temp_r5);
        return 0;
    }
    if ((s32) (M2C_FIELD(data_02136c4c, u8 *, 0x1524) + 1) > 0x10) {
        OS_RestoreInterrupts(temp_r5);
        return 0;
    }
    var_r6 = 0;
loop_5:
    temp_r2 = (var_r6 * 0x5D4) + (s32) data_02136c4c;
    if (M2C_FIELD(temp_r2, s32 *, 0x1D40) == arg0) {
        OS_RestoreInterrupts(temp_r5);
        return 0;
    }
    if (M2C_FIELD(temp_r2, u8 *, 0x1D52) == 0) {
        var_r4 = var_r6;
        goto block_10;
    }
    var_r6 += 1;
    if ((u32) var_r6 >= 0x10U) {
block_10:
        if (var_r6 == 0x10) {
            OS_RestoreInterrupts(temp_r5);
            return 0;
        }
        temp_r6 = var_r4 * 0x5D4;
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D40) = arg0;
        temp_r9 = data_02136c4c + 0x1788 + temp_r6;
        func_02015a2c(temp_r9, arg1);
        MI_CpuCopy8(arg0 + 0x1C, temp_r9 + 0xC4, 0x20);
        if (func_02015c18(data_02136c4c + 0x1D2C + temp_r6, temp_r9) == 0) {
            OS_RestoreInterrupts(temp_r5);
            return 0;
        }
        func_02015f94(data_02136c4c + 0x186C + temp_r6, arg0, data_02136c4c + 0x1300);
        M2C_FIELD((data_02136c4c + temp_r6), u8 *, 0x1D21) = var_r4;
        func_020161bc(data_02136c4c + 0x186C + temp_r6);
        sequence=data_02131184;
        M2C_FIELD((data_02136c4c + temp_r6), u8 *, 0x1D1F) = sequence;
        M2C_FIELD((data_02136c4c + temp_r6), s16 *, 0x1D4E) = 1;
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D44) = arg1;
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D54) = (s32) (arg1 + 0x1E8);
        M2C_FIELD((data_02136c4c + temp_r6), s32 *, 0x1D58) = (s32) (arg1 + 0x258);
        data_02131184 = sequence+1;
        if ((M2C_FIELD(M2C_FIELD((data_02136c4c + temp_r6), void **, 0x1D54), s32 *, 0x6C) != 0) && (func_0201871c() == 0)) {
            func_02018738(data_02136c4c + 0x7CE0);
            func_0201869c(data_02136c4c + 0x74E0, 0x800);
        }
        M2C_FIELD((data_02136c4c + temp_r6), s8 *, 0x1D52) = 1;
        M2C_FIELD(data_02136c4c, u8 *, 0x1524) = (u8) (M2C_FIELD(data_02136c4c, u8 *, 0x1524) + 1);
        OS_RestoreInterrupts(temp_r5);
        return 1;
    }
    goto loop_5;
}
#pragma pop
void func_02015a2c(void *arg0, void *arg1) {
 M2C_UNK MI_CpuCopy8(s32,s32,s32);
 void func_02015aa0(void *, void *, void *, s32 *);
 extern u8 data_020ea72c[];
 s32 sp0;
 u8 *p;
 void *out;
 s32 i;
 sp0=0x022C0000;
 p=data_020ea72c;
 M2C_FIELD(arg0,s32 *,0)=M2C_FIELD(arg1,s32 *,0x24);
 out=arg0+12;
 M2C_FIELD(arg0,s32 *,4)=M2C_FIELD(arg1,s32 *,0x34);
 i=0;
 do {func_02015aa0(arg1,p,out,&sp0); i++; out+=16; p+=4;} while(i<3);
 MI_CpuCopy8((s32)arg1+0x160,(s32)arg0+0x3c,0x88);
}
