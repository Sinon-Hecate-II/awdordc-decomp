/* 17 functions from 0x02013B54 to 0x02014B34 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 low:4; u8 high:4; } Packet14564;

s32 func_02013b54(M2C_UNK a,u32 b,s32 c){ M2C_UNK func_020067c4(s32,M2C_UNK); s32 r=func_0201146c(); if(r)return r;if(b>3)return 6;if(b){if(!c)return 6;func_020067c4(c,80);}func_020112b4(20,a);r=func_02011324(20,2,b,c);if(!r)r=2;return r;}

s32 func_02013bc8(M2C_UNK a,u32 b,s32 c,s32 d){ s32 r=func_0201146c();if(r)return r;if(b>3)return 6;if(b){if(!d)return 6;func_020067c4(d,80);}func_020112b4(39,a);r=func_02011324(39,3,b,d,c);if(!r)r=2;return r;}

s32 func_02013c44(M2C_UNK a,s32 b,u32 c,s32 d,u16 e,u8 f){ M2C_UNK func_02007e20(s32,M2C_UNK *,u32);extern M2C_UNK data_02131100;s32 r=func_020114b4(2,7,9);if(r)return r;if(!b)return 6;if(c>112)return 6;func_02007e20(b,&data_02131100,c);func_020067c4(&data_02131100,c);func_020112b4(24,a);r=func_02011324(24,5,&data_02131100,c,d,(s32)e,(s32)f);if(!r)r=2;return r;}

s32 func_02013cfc(M2C_UNK arg0, s32 arg1) {
    s32 func_0201146c();
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_0201146c();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if ((arg1 != 0) && (arg1 != 1)) {
        return 6;
    }
    func_020112b4(0x19, arg0);
    var_r0 = func_02011324(0x19, 1, arg1);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02013d4c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, u16 arg4) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_0201146c();
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(0x1D, arg0);
    var_r0 = func_02011324(0x1D, 4, arg1, arg2, arg3, (s32) arg4);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

s32 func_02013dac(s32 arg0,s16 arg1,s16 arg2,s16 arg3,u16 arg4) {
 s32 func_020113d0(s16 *,s32);
 void func_02011440();
 s16 packet[5]; s32 result;
 func_02011440();
 result=func_020114b4(1,2);
 if(result) return result;
 func_020112b4(0x1e,arg0);
 packet[0]=0x1e; packet[1]=arg1; packet[2]=arg2; packet[3]=arg3; packet[4]=arg4;
 result=func_020113d0(packet,10);
 if(!result) result=2;
 return result;
}

s32 func_02013e24(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_020112b4(M2C_UNK, M2C_UNK);
    s32 func_02011324(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_020114b4(M2C_UNK, M2C_UNK, M2C_UNK);
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_020114b4(2, 7, 9);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_020112b4(0x21, arg0);
    var_r0 = func_02011324(0x21, 1, arg1);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}

void func_02013e70(s32 arg0) { s32 OS_DisableInterrupts(); void OS_RestoreInterrupts(s32); extern s32 data_02136c4c; s32 state=OS_DisableInterrupts(); M2C_FIELD(data_02136c4c,s32 *,0x14e4)=arg0; OS_RestoreInterrupts(state); }

#pragma opt_strength_reduction off
void *func_02013e98(s32 arg0) {
s32 OS_DisableInterrupts(void); void OS_RestoreInterrupts(s32); s32 func_02015214(); void MI_CpuCopy8(void *,void *); extern s32 data_02136c4c;
s32 state=OS_DisableInterrupts();
if(data_02136c4c && func_02015214(arg0)){
MI_CpuCopy8((void *)(data_02136c4c+0x1340+(arg0-1)*22),(void *)(data_02136c4c+0x1772));
OS_RestoreInterrupts(state); return (void *)(data_02136c4c+0x1772);
}
OS_RestoreInterrupts(state); return 0;
}
#pragma opt_strength_reduction reset
s32 func_02013f1c(s32 arg0) {
 extern s32 data_02136c4c;
 s32 func_02015214();
 if(data_02136c4c && func_02015214(arg0)) {
 if(M2C_FIELD(data_02136c4c+(arg0-1)*4,s32 *,0x14e8)==7) return 1;
 }
 return 0;
}

s32 func_02013f70(s32 arg0, u32 arg1) {
s32 OS_DisableInterrupts(void);void OS_RestoreInterrupts(s32);s32 func_02015214(s32);extern s32 data_02136c4c;
u32 val; s32 expected; s32 state;
state=OS_DisableInterrupts();
switch(arg1){case 0:expected=10;val=4;break;case 1:expected=10;val=3;break;case 2:expected=14;val=2;break;case 3:expected=7;val=5;break;default:OS_RestoreInterrupts(state);return 0;}
if(data_02136c4c && func_02015214(arg0)){
s32 idx=arg0-1;u8 *base=(u8 *)data_02136c4c;
if(expected==*(s32 *)(base+idx*4+0x14e8)){
*(u16 *)(base+idx*2+0x1754)=val;OS_RestoreInterrupts(state);return 1;
}}
OS_RestoreInterrupts(state);return 0;
}

void func_02014050(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 func_02015214();
    extern s32 data_02136c4c;
    M2C_UNK func_0201409c(s32, s32, M2C_UNK);
    if (func_02015214() != 0) {
        M2C_FIELD((data_02136c4c + ((arg0 - 1) * 4)), s32 *, 0x14E8) = arg1;
    }
    func_0201409c(arg0, arg1, arg2);
}

M2C_UNK func_0201409c(s32 arg0,s32 arg1,M2C_UNK arg2) {
 extern s32 data_02136c4c;
 void (*callback)(s32,s32,M2C_UNK)=M2C_FIELD(data_02136c4c,void (**)(s32,s32,M2C_UNK),0x14e4);
 if(!callback) return;
 callback(arg0,arg1,arg2);
}

#pragma opt_scheduling off
#pragma opt_common_subs off
void func_020140c4(s32 a, void *b) {
extern s32 data_02136c4c;
void func_02014a48(s32); void func_02007f8c(); void func_02018960(); void func_02015008(); void func_02016124(); s32 func_02018390(); s32 func_020183a4(); s32 func_020183b8(); void func_02016250(); void func_02015230(); void func_02007e98();
s32 id, idx, off, group; u8 i; s32 x,y,z;
switch(a) {
case 17: break;
case 21: func_02014050(0,1,(s32)b); break;
case 0: if(*(u16*)((u8*)b+16)!=0 && *(u16*)((u8*)b+16)<16) func_02014050(*(u16*)((u8*)b+16),2,(s32)b); break;
case 1:
if(*(u16*)((u8*)b+16)==0 || *(u16*)((u8*)b+16)>=16) break;
M2C_FIELD(data_02136c4c+(*(u16*)((u8*)b+16)-1)*2,u16*,0x148a)=0;
func_02007f8c(data_02136c4c+0x14a8+(*(u16*)((u8*)b+16)-1)*4,0,4);
func_02007f8c(data_02136c4c+0x1340+(*(u16*)((u8*)b+16)-1)*22,0,22);
func_02018960(*(u16*)((u8*)b+16));
M2C_FIELD(data_02136c4c+(*(u16*)((u8*)b+16)-1)*2,u16*,0x1754)=0;
id=*(u16*)((u8*)b+16); idx=id-1;
group=M2C_FIELD(data_02136c4c+idx,s8*,0x1526);
if(group!=-1) {
off=(u8)group*0x5d4;
M2C_FIELD(data_02136c4c+off,u16*,0x1d4e)&=~(1<<id);
M2C_FIELD(data_02136c4c+off,u16*,0x1d50)|=1<<id;
M2C_FIELD(data_02136c4c+idx,s8*,0x1526)=-1;
M2C_FIELD(data_02136c4c+off,u16*,0x1d4c)&=~(1<<id);
}
if(M2C_FIELD(data_02136c4c,u16*,0x1536)&(1<<*(u16*)((u8*)b+16))) {
M2C_FIELD(data_02136c4c,u8*,0x1535)--;
M2C_FIELD(data_02136c4c,u16*,0x1536)&=~(1<<*(u16*)((u8*)b+16));
}
if(M2C_FIELD(data_02136c4c+(*(u16*)((u8*)b+16)-1)*4,s32*,0x14e8)==8) func_02014050(*(u16*)((u8*)b+16),9,0);
func_02014050(*(u16*)((u8*)b+16),3,(s32)b);
M2C_FIELD(data_02136c4c+(*(u16*)((u8*)b+16)-1)*4,s32*,0x14e8)=0;
break;
case 3: func_02014a48((s32)b); break;
case 25: func_02015008(); break;
case 28:
for(i=0;i<16;i++){
off=i*0x5d4;
if(M2C_FIELD(data_02136c4c+off,u8*,0x1d52) && M2C_FIELD(data_02136c4c+off,u16*,0x1d50)){
func_02016124(data_02136c4c+0x186c+off,data_02136c4c+0x1340,M2C_FIELD(data_02136c4c+off,u16*,0x1d4e),M2C_FIELD(data_02136c4c+off,u16*,0x1d50));
M2C_FIELD(data_02136c4c+off,u16*,0x1d50)=0;
}}
x=func_02018390(); y=func_020183a4(); z=func_020183b8(); func_02016250(x,y,z); break;
case 255:
switch(*(u16*)((u8*)b+2)){case 1:case 4:case 5:case 6:case 8:case 9:func_02015230(0,9);break;case 0:case 2:case 3:case 7:case 10:case 11:case 12:case 13:case 14:case 15:default:func_02015230(0,8);break;} break;
case 256:
switch(*(u16*)b){case 0:case 7:case 8:case 13:case 14:case 15:case 17:case 18:case 21:case 25:case 29:func_02015230(0,9);break;case 1:case 2:case 3:case 4:case 5:case 6:case 9:case 10:case 11:case 12:case 16:case 19:case 20:case 22:case 23:case 24:case 26:case 27:case 28:default:func_02015230(0,8);break;} break;
}
if(a==17){void (*cb)(s32,s32,s32)=M2C_FIELD(data_02136c4c,void (**)(s32,s32,s32),0x14e4);func_02007e98(0,data_02136c4c,0x7d00);data_02136c4c=0;if(cb)cb(0,12,0);}
}
#pragma opt_scheduling on
#pragma opt_common_subs on
void func_02014564(void *arg0,u16 n) {
void *func_02018a28(); void MI_CpuCopy8(); u16 func_02015204(); extern s32 data_02136c4c; extern s32 data_02131180;
s32 state; u8 *p; u32 group; u8 count,i; u8 header[20]; u8 packet[32];
if(!n)return; if(n>15)return;
p=func_02018a28((u8 *)arg0+10,header,n);
state=M2C_FIELD(data_02136c4c+((u32)n-1)*4,s32 *,0x14e8);
switch(header[0]){
case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 11: break;
case 7:
if(state==2){
if(!p)return;
MI_CpuCopy8(p,packet,29);
M2C_FIELD(data_02136c4c+(n-1)*4,u32 *,0x14a8)=*(u32 *)packet;
M2C_FIELD(data_02136c4c+(n-1)*2,u16 *,0x148a)=*(u16 *)(packet+26);
MI_CpuCopy8(packet+4,(void *)(data_02136c4c+0x1340+(n-1)*22),22);
((Packet14564 *)(data_02136c4c+0x1340+((u32)n-1)*22))->high=(u8)n;
func_02014050(n,10,(M2C_UNK)(packet+4));
}
if(state!=10)return;
group=p[28]; count=0;
if(group>=16 || !M2C_FIELD(data_02136c4c+group*0x5d4,u8 *,0x1d52) || M2C_FIELD(data_02136c4c+(n-1)*4,u32 *,0x14a8)!=M2C_FIELD(M2C_FIELD(data_02136c4c+group*0x5d4,u32 *,0x1d40),u32 *,20)){
M2C_FIELD(data_02136c4c+(n-1)*2,u16 *,0x1754)=4;
}else{
for(i=0;i<16;i++)if(M2C_FIELD(data_02136c4c+group*0x5d4,u16 *,0x1d4e)&(1<<i))count++;
if(count>=M2C_FIELD(M2C_FIELD(data_02136c4c+group*0x5d4,u32 *,0x1d40),u8 *,24)){
M2C_FIELD(data_02136c4c+(n-1)*2,u16 *,0x1754)=0;func_02014050(n,11,0);return;}
}
switch(M2C_FIELD(data_02136c4c+(n-1)*2,u16 *,0x1754)){
case 3:
if(M2C_FIELD(data_02136c4c,u16 *,0x1536)&(1<<n))return;
M2C_FIELD(data_02136c4c,u8 *,0x1535)++;
M2C_FIELD(data_02136c4c,u16 *,0x1536)|=1<<n;
M2C_FIELD(data_02136c4c+n-1,u8 *,0x1526)=group;
M2C_FIELD(data_02136c4c+group*0x5d4,u16 *,0x1d4e)|=1<<n;
M2C_FIELD(data_02136c4c+group*0x5d4,u16 *,0x1d50)|=1<<n;
M2C_FIELD(data_02136c4c+(n-1)*2,u16 *,0x1754)=0;func_02014050(n,5,0);return;
case 4:M2C_FIELD(data_02136c4c+(n-1)*2,u16 *,0x1754)=0;func_02014050(n,4,0);return;
}break;
case 8:
if(state==5){func_02014050(n,14,0);return;}
if(state!=14)return;
if(M2C_FIELD(data_02136c4c+(n-1)*2,u16 *,0x1754)!=2)return;
group=M2C_FIELD(data_02136c4c+n-1,u8 *,0x1526);
M2C_FIELD(data_02136c4c+group*0x5d4,u16 *,0x1d4c)|=1<<n;
M2C_FIELD(data_02136c4c+group*0x5d4,u16 *,0x1d48)=0;
M2C_FIELD(data_02136c4c+(n-1)*2,u16 *,0x1754)=0;func_02014050(n,6,0);break;
case 9:
if(state!=6)return;
group=M2C_FIELD(data_02136c4c+n-1,u8 *,0x1526);if(group==255)return;
M2C_FIELD(data_02136c4c+group*0x5d4,u16 *,0x1d4a)=func_02015204(M2C_FIELD(data_02136c4c+group*0x5d4,u16 *,0x1d4a),*(u16 *)(header+2));
data_02131180|=1<<group;break;
case 10:
if(state==6){group=M2C_FIELD(data_02136c4c+n-1,u8 *,0x1526);if(group==255)return;M2C_FIELD(data_02136c4c+group*0x5d4,u16 *,0x1d4c)&=~(1<<n);func_02014050(n,7,0);return;}
if(state!=7)return;
if(M2C_FIELD(data_02136c4c+(n-1)*2,u16 *,0x1754)!=5)return;
M2C_FIELD(data_02136c4c+(n-1)*2,u16 *,0x1754)=0;func_02014050(n,8,0);break;
}
}
#pragma opt_strength_reduction reset
void func_02014a48(s32 arg0) {
 extern s32 data_02136c4c; extern s32 data_02131180;
 void *func_02011c74(s32,u16); void func_02014564(void *,u16);
 u16 i; void *p;
 for(i=0;i<16;i++) {
 p=(void *)(data_02136c4c+i*0x5d4);
 if(M2C_FIELD(p,u8 *,0x1d52)) M2C_FIELD(p,u16 *,0x1d4a)=0;
 }
 data_02131180=0;
 for(i=1;i<=15;i++) {
 p=func_02011c74(arg0,i);
 if(p && M2C_FIELD(p,u16 *,0)!=0xffff && M2C_FIELD(p,u16 *,0)!=0) func_02014564(p,i);
 }
}

void func_02014af4(u8 arg0,s32 arg1) {
 void func_020189a4(u8 *,s32); void func_02015f10(s32,s32,s32);
 extern s32 data_02136c4c;
 u8 packet[8];
 packet[0]=arg0;
 func_020189a4(packet,data_02136c4c);
 func_02015f10(6,arg1,data_02136c4c);
}

