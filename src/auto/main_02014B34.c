/* 13 functions from 0x02014B34 to 0x02015AA0 (main), found by ds-decomp. */
#include "common.h"

s32 func_02014b34(u16 arg0) {
 s32 func_020189a4(s8 *,void *);s32 func_02015f10(s32,u16,s32);
 extern u8 data_020f5544;extern void *data_02136c4c;
 M2C_UNK func_02007f8c(M2C_UNK,M2C_UNK,M2C_UNK);M2C_UNK func_02008048(M2C_UNK,M2C_UNK,M2C_UNK);
 void *base;u8 packet[6];u8 counts[16];s32 ptr;s8 selected=-1;u16 idx,idx2,mask=0;u8 tries,candidate;s8 owner;
 func_02007f8c((s32)counts,0,16);base=data_02136c4c;
 for(idx=1;idx<=15;idx++){
 if(M2C_FIELD(base+idx*4,s32 *,0x14e4)==5){
 owner=M2C_FIELD(base+idx,s8 *,0x1525);counts[owner]++;
 }}
 candidate=data_020f5544;
 for(tries=0;tries<16;tries++){
 candidate=(candidate+1)%16;
 if(M2C_FIELD(base+candidate*0x5d4,u8 *,0x1d52)&&counts[candidate]){
 selected=candidate;break;
 }}
 if(selected==-1)return 21;
 data_020f5544=selected;
 for(idx2=1;idx2<=15;idx2++){
 if(M2C_FIELD(base+idx2*4,s32 *,0x14e4)==5 && selected==M2C_FIELD(base+idx2,s8 *,0x1525))mask|=1<<idx2;
 }
 packet[0]=3;*(s16 *)(packet+2)=selected;
 ptr=func_020189a4((s8 *)packet,base);
 if(ptr)func_02008048((s32)(data_02136c4c+0x1788+selected*0x5d4),ptr,0xe4);
 return func_02015f10(0xea,mask,(s32)data_02136c4c);
}

void func_02014ccc(void *arg0) {
 s32 func_0200b144(void *,s32);
 void func_0200b774(void *);
 s32 func_0200b99c(void *,s32,s32,s32,s32);
 void func_0200ba9c(void *);
 s32 func_0200bbe0(void *,s32,s32);
 u32 sp4[18];
 s32 val;
 void *a,*b;
 b=M2C_FIELD(arg0,void **,0x14); a=M2C_FIELD(arg0,void **,0x10);
 func_0200b774(sp4);
 val=M2C_FIELD(a,s32 *,0);
 if(func_0200b99c(sp4,func_0200b144(b+16,M2C_FIELD(b,s32 *,0x14)),val,val+M2C_FIELD(a,s32 *,4),-1)!=0){
 if(M2C_FIELD(a,s32 *,4)==func_0200bbe0(sp4,M2C_FIELD(a,s32 *,8),M2C_FIELD(a,s32 *,4))) M2C_FIELD(a,s32 *,12)=2;
 func_0200ba9c(sp4);
 }
 if(M2C_FIELD(a,s32 *,12)==2)return;
 M2C_FIELD(a,s32 *,0)=0; M2C_FIELD(a,s32 *,12)=2;
}

#pragma push
#pragma opt_common_subs off
s32 func_02014d6c(void) {
    extern void *data_02136c4c;
    void func_02015188(s32);
    s32 func_02015ce4(void *,void *,u16,void *);
    s32 func_020189a4(s8 *,void *);
    s32 func_020184ec(void *,u32,s32,u32);
    s32 func_0201874c(void *);
    void func_02007958(void);
    void func_02018764(void *,void (*)(void *),s32,s32);
    s32 func_02015f10(s32,u16,s32);
    u8 packet[8];
    u32 output[4];
    u8 tries,candidate;
    s32 i;
    s32 offset;
    void *buffer;
    void *task;
    u32 *best;
    void *base;
    void *entry;
    void *loopEntry;
    u32 (*records)[4];
    s32 j;
    s32 command;
    u32 size;
    u32 bank;
    s32 *table;
    void *interior;
    u32 position;
    u32 previous;
    if (!M2C_FIELD(data_02136c4c,u8 *,0x1524)) return 21;
    for (tries=0;tries<16;tries++) {
        M2C_FIELD(data_02136c4c,u8 *,0x1525)=(M2C_FIELD(data_02136c4c,u8 *,0x1525)+1)%16;
        base=data_02136c4c;
        candidate=M2C_FIELD(base,u8 *,0x1525);
        loopEntry=base+candidate*0x5d4;
        if (M2C_FIELD(loopEntry,u8 *,0x1d52) && M2C_FIELD(loopEntry,u16 *,0x1d4c)) break;
    }
    if (tries==16) return 21;
    func_02015188(candidate);
    base=data_02136c4c;
    i=M2C_FIELD(base,u8 *,0x1525);
    if (!func_02015ce4(output,base+0x1d2c+i*0x5d4,M2C_FIELD(base+i*0x5d4,u16 *,0x1d48),base+0x1788+i*0x5d4)) return 21;
    base=data_02136c4c;
    packet[0]=4;
    *(u16 *)(packet+2)=M2C_FIELD(base,u8 *,0x1525);
    *(u16 *)(packet+4)=M2C_FIELD(base+M2C_FIELD(base,u8 *,0x1525)*0x5d4,u16 *,0x1d48);
    command=func_020189a4((s8 *)packet,base);
    base=data_02136c4c;
    entry=base+M2C_FIELD(base,u8 *,0x1525)*0x5d4;
    bank=((u8 *)output)[12];
    position=output[2];
    interior=entry+0x1000;
    table=M2C_FIELD(interior,s32 **,0xd58);
    previous=M2C_FIELD(entry+bank*4,u32 *,0x1d2c);
    offset=table[bank]+(position-previous);
    buffer=M2C_FIELD(interior,void **,0xd54);
    size=output[1];
    if (!func_020184ec(buffer,offset,command,size)) {
        task=data_02136c4c+0x7ce0;
        if (!func_0201874c(task)) {
            if (M2C_FIELD(buffer,u32 *,0)) M2C_FIELD(buffer,u32 *,0)--;
            else {
                records=(u32 (*)[4])(buffer+0x30);
                best=0;
                for(j=0;j<4;j++) {
                    if (records[j][3]==2) {
                        if (!best || M2C_FIELD(best,u32 *,0)>records[j][0]) best=records[j];
                    }
                }
                if (!best) func_02007958();
                M2C_FIELD(buffer,u32 *,0)=2;
                M2C_FIELD(best,s32 *,12)=1;
                M2C_FIELD(best,u32 *,0)=offset&~31;
                M2C_FIELD(task,void **,16)=best;
                M2C_FIELD(task,void **,20)=buffer;
                func_02018764(task,func_02014ccc,0,4);
            }
        }
        return 21;
    }
    base=data_02136c4c;
    return func_02015f10(output[1]+6,M2C_FIELD(base+M2C_FIELD(base,u8 *,0x1525)*0x5d4,u16 *,0x1d4c),(s32)base);
}
#pragma pop
/* Select units by state into priority groups, then dispatch the matching network action. */
void func_02015008(void) {
extern void *data_02136c4c;
void func_02007df8(s32,void *,s32); s32 func_02014af4(s32,u16); s32 func_02014b34(u16); s32 func_02014d6c(void);
u16 masks[5];u16 i; s32 result;
func_02007df8(0,masks,10);
for(i=1;i<=15;i++){
switch(M2C_FIELD((u8 *)data_02136c4c+4*i,s32 *,0x14e4)){
case 2:masks[0]|=1<<i;break;
case 5:masks[1]|=1<<i;break;
case 4:masks[2]|=1<<i;break;
case 8:masks[3]|=1<<i;break;
case 11:masks[4]|=1<<i;break;
}
}
if(masks[3])result=func_02014af4(5,masks[3]);
else if(masks[0])result=func_02014af4(1,masks[0]);
else if(masks[4])result=func_02014af4(6,masks[4]);
else if(masks[2])result=func_02014af4(2,masks[2]);
else if(masks[1])result=func_02014b34(masks[1]);
else result=func_02014d6c();
if(result==21)func_02014af4(0,0xffff);
}

void func_02015188(s32 arg0) {
 extern s32 data_02131180;
    extern void *data_02136c4c;
 u16 a,b; void *base;
 if(!(data_02131180 & (1<<arg0)))return;
 base=(void *)(arg0*0x5d4+data_02136c4c);
 if(M2C_FIELD(base,u8 *,0x1d52)!=0 && M2C_FIELD(base,u16 *,0x1d4c)!=0){
 a=M2C_FIELD(base+0x1d00,u16 *,0x48); b=M2C_FIELD(base,u16 *,0x1d4a);
 if((u32)b<=(u32)a && (s32)a<=b+2){M2C_FIELD(base+0x1d00,u16 *,0x48)=a+1;return;}
 M2C_FIELD(base+0x1d00,u16 *,0x48)=b;
 }
}

u32 func_02015204(u32 arg0, u32 arg1) {
    u32 var_r1;

    var_r1 = arg1;
    if (var_r1 <= arg0) {
        var_r1 = arg0;
    }
    return var_r1;
}

s32 func_02015214(u32 arg0) {
    if ((arg0 >= 1U) && (arg0 <= 0xFU)) {
        return 1;
    }
    return 0;
}

void func_02015230(M2C_UNK arg0, s16 arg1) {
    M2C_UNK func_0201409c(M2C_UNK, M2C_UNK, s16 *);
    s16 sp0;

    sp0 = arg1;
    func_0201409c(arg0, 0xD, &sp0);
}

