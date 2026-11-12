/* 6 functions from 0x02067CB0 to 0x02068C50 (main), found by ds-decomp. */
#include "common.h"
#include "scan_spec.h"
extern const u16 gCharClassTable[];
extern u32 data_021002ec;
static inline s32 ScanOutside67cb0(s32 c) { s32 outside=1; if(c>=0 && c<128)outside=0; return outside; }
static inline s32 ScanSpace67cb0(s32 c) {return ScanOutside67cb0(c)?0:gCharClassTable[c]&0x100;}


char *ParseScanConversion(char *,ScanSpec677b8 *);
u32 func_0206a384(int,int,s32 (*)(void *,s32,s32),void *,s32 *,s32 *,s32 *);
u64 func_0206a76c(int,int,s32 (*)(void *,s32,s32),void *,s32 *,s32 *,s32 *);
f64 func_02069048(int,s32 (*)(void *,s32,s32),void *,s32 *,s32 *);
f64 func_0207191c(f32);
f32 func_0207044c(f64);
int func_02065020(void *,const char *,int);
#pragma opt_peephole off
s32 func_02067cb0(s32 (*get)(void *,s32,s32),void *ctx,s32 arg2,s32 arg3,s32 safe){
char *fmt=(char *)arg2;u32 *args=(u32 *)arg3;void *dst;
s32 base,used,negative,overflow;
s32 value,signedValue,fc;
u64 wide=0,magnitude;
s32 failed=0,nread=0,assigned=0,conversions=0;
f64 real;
ScanSpec677b8 spec;
char ch;u16 wc; u32 size;s32 valid,count,i,state,raw;char *out,*original;u16 *wout;
while((fc=*fmt)!=0){
if(ScanSpace67cb0(fc)){
do{fc=*++fmt;}while(ScanSpace67cb0(fc));
if(failed)continue;
do{nread++;ch=get(ctx,0,0);}while(ScanSpace67cb0(ch));
get(ctx,ch,1);continue;
}
if(fc!='%' && !failed){
ch=get(ctx,0,0);
if((u8)fc!=ch){
get(ctx,ch,1);
if(!safe)break;
failed=1;fmt++;continue;
}
nread++;fmt++;continue;
}
fmt=ParseScanConversion(fmt,&spec);
if(!spec.suppress && spec.conversion!='%')dst=(void *)*(++args-1);else dst=0;
if(spec.conversion!='n' && !failed && get(ctx,0,2)){
if(!safe)break;failed=1;
}
switch(spec.conversion){
case 'd':base=10;goto signed_integer;
case 'i':base=0;
signed_integer:
if(failed){signedValue=0;wide=0;}
else{
if(spec.length==7 || spec.length==4)magnitude=func_0206a76c(base,spec.width,get,ctx,&used,&negative,&overflow);
else value=func_0206a384(base,spec.width,get,ctx,&used,&negative,&overflow);
if(used==0){
if(!safe)goto done;
failed=1;signedValue=0;wide=0;
}else{
nread+=used;
if(spec.length==7 ||spec.length==4){if(negative)wide=-magnitude;else wide=magnitude;}
else {if(negative)signedValue=-value;else signedValue=value;}
}
}
if(dst){
switch(spec.length){
case 0:*(s32 *)dst=signedValue;break;
case 1:*(s8 *)dst=signedValue;break;
case 2:*(s16 *)dst=signedValue;break;
case 3:*(s32 *)dst=signedValue;break;
case 4:*(u64 *)dst=wide;break;
case 5:*(s32 *)dst=signedValue;break;
case 6:*(s32 *)dst=signedValue;break;
case 7:*(u64 *)dst=wide;break;
}
if(!failed)assigned++;conversions++;
}
break;
case 'o':base=8;goto unsigned_integer;
case 'u':base=10;goto unsigned_integer;
case 'x':case 'X':base=16;
unsigned_integer:
if(failed){value=0;magnitude=0;}
else{
if(spec.length==7 ||spec.length==4)magnitude=func_0206a76c(base,spec.width,get,ctx,&used,&negative,&overflow);
else value=func_0206a384(base,spec.width,get,ctx,&used,&negative,&overflow);
if(used==0){
if(!safe)goto done;
failed=1;value=0;magnitude=0;
}else{
nread+=used;
if(negative){if(spec.length!=7)value=-value;else magnitude=-magnitude;}
}
}
if(dst){
switch(spec.length){
case 0:*(u32 *)dst=value;break;
case 1:*(u8 *)dst=value;break;
case 2:*(u16 *)dst=value;break;
case 3:*(u32 *)dst=value;break;
case 4:*(u64 *)dst=magnitude;break;
case 5:*(u32 *)dst=value;break;
case 6:*(u32 *)dst=value;break;
case 7:*(u64 *)dst=magnitude;break;
}
if(!failed)assigned++;conversions++;
}
break;
case 'a':case 'A':case 'e':case 'E':case 'f':case 'F':case 'g':case 'G':
if(failed)real=func_0207191c(*(f32 *)&data_021002ec);
else{
real=func_02069048(spec.width,get,ctx,&used,&overflow);
if(used==0){
if(!safe)goto done;
failed=1;real=func_0207191c(*(f32 *)&data_021002ec);
}else nread+=used;
}
if(dst){
switch(spec.length){case 0:*(f32 *)dst=func_0207044c(real);break;case 8:*(f64 *)dst=real;break;case 9:*(f64 *)dst=real;break;}
if(!failed)assigned++;conversions++;
}
break;

case 'c':
if(!spec.hasWidth)spec.width=1;
if(dst){
if(safe){size=*(++args-1);valid=1;}
used=0;
if(failed){if(size!=0)*(char *)dst=0;break;}
out=dst;original=out;
while(spec.width--!=0 && (!safe || (valid=size>(u32)used)) && (raw=get(ctx,0,0))!=-1){
ch=raw;
if(spec.length!=10)*out++=ch;
else {func_02065020(out,&ch,1);out++;}
used++;
}
ch=raw;
if(used==0 ||(safe && !valid)){
if(!safe)goto done;
failed=1;if(size!=0)*original=0;break;
}
nread+=used;assigned++;
}else{
used=0;
while(spec.width--!=0 && (raw=get(ctx,0,0))!=-1){ch=raw;used++;
}
ch=raw;
if(!used)goto done;
}
conversions++;break;
case '%':
if(failed)break;
ch=get(ctx,0,0);
while(ScanSpace67cb0(ch)){nread++;ch=get(ctx,0,0);}
if(ch!='%'){
get(ctx,ch,1);if(!safe)goto done;failed=1;
}else nread++;
break;
case 's':
if(!failed){
ch=get(ctx,0,0);
while(ScanSpace67cb0(ch)){nread++;ch=get(ctx,0,0);}
get(ctx,ch,1);
}
case '[':
if(dst){
if(safe){size=*(++args-1)-1;valid=1;}
used=0;
if(failed){if(size!=0)*(char *)dst=0;break;}
out=dst;original=out;
while(spec.width--!=0 && (!safe || (valid=size>=(u32)used)) && (raw=get(ctx,0,0))!=-1){
ch=raw;
if(!(spec.set[(u8)ch>>3]&(1<<(ch&7))))break;
if(spec.length!=10)*out++=ch;
else {func_02065020(out,&ch,1);out+=2;}
used++;
}
ch=raw;
if(!used ||(safe&&!valid)){
get(ctx,ch,1);
if(!safe)goto done;
failed=1;if(size!=0)*original=0;break;
}
nread+=used;
if(spec.length==10)*(u16 *)out=0;else *out=0;
assigned++;
}else{
used=0;
while(spec.width--!=0 && (raw=get(ctx,0,0))!=-1){ch=raw;
if(!(spec.set[(u8)ch>>3]&(1<<(ch&7))))break;
used++;
}
ch=raw;
if(!used){get(ctx,ch,1);break;}
nread+=used;
}
if(spec.width>=0)get(ctx,ch,1);
conversions++;break;
case 'n':
if(dst){
switch(spec.length){
case 0:*(s32 *)dst=nread;break;
case 2:*(s16 *)dst=nread;break;
case 3:*(s32 *)dst=nread;break;
case 1:*(s8 *)dst=nread;break;
case 7:((s32 *)dst)[0]=nread;((s32 *)dst)[1]=nread>>31;break;
}
}
break;
case 255:goto done;
default:goto done;
}
}
done:
if(get(ctx,0,2) && !conversions)return -1;
return assigned;
}
#pragma optimize_for_size off
s32 func_02068a04(void *arg0, s32 arg1, s32 arg2) {
    s8 *temp_r1;
    s8 temp_r2;

    switch (arg2) {                                 /* irregular */
    case 0:
        temp_r1 = M2C_FIELD(arg0, s8 **, 0);
        temp_r2 = *temp_r1;
        if (temp_r2 == 0) {
            M2C_FIELD(arg0, s32 *, 4) = 1;
            return -1;
        }
        M2C_FIELD(arg0, s8 **, 0) = (s8 *) (temp_r1 + 1);
        return (s32) (u8) temp_r2;
    case 1:
        if (M2C_FIELD(arg0, s32 *, 4) == 0) {
            --M2C_FIELD(arg0,s8 **,0);
        } else M2C_FIELD(arg0,s32 *,4)=0;
        return arg1;
    case 2:
        return M2C_FIELD(arg0, s32 *, 4);
    default:
        return 0;
    }
}
#pragma optimize_for_size reset
s32 func_02068a88(s8 *arg0, s32 arg1, s32 arg2) {
    s32 func_02068a04(void *, s32, s32);
    s32 func_02067cb0(s32 (*)(void *, s32, s32), void *, s32, s32, s32);
    struct { s8 *ptr; s32 eof; } state;
    state.ptr = arg0;
    if (arg0 == NULL || *arg0 == 0) return -1;
    state.eof = 0;
    return func_02067cb0(func_02068a04, &state, arg1, arg2, 0);
}

void StringScanf(s32 arg0, s32 arg1, ...) {
 char *args;
 args=(char *)(((u32)&arg1 & ~3U)+4);
 func_02068a88((s8 *)arg0,arg1,(s32)args);
}

s32 func_02068b04(s32 arg0) {
M2C_UNK LockMutex(M2C_UNK *);
M2C_UNK UnlockMutex(M2C_UNK *);
s32 func_02006680(M2C_UNK *);
M2C_UNK func_02063e1c(M2C_UNK);
extern M2C_UNK gSocketManager;
extern M2C_UNK data_0213e5d4;
extern s32 data_0213e5f8[9];
extern M2C_UNK data_0213e6c4;
extern M2C_UNK data_0213e9f8;
M2C_UNK (*cb)(s32);
s32 n;
if(arg0<1 || arg0>7) return -1;
if(func_02006680(&data_0213e6c4)==0) {
M2C_FIELD(&data_0213e5d4,s32 *,0x1c)=M2C_FIELD(M2C_FIELD(&gSocketManager,void **,4),s32 *,0x6c);
data_0213e5f8[7]=1;
} else if(M2C_FIELD(&data_0213e5d4,s32 *,0x1c)==M2C_FIELD(M2C_FIELD(&gSocketManager,void **,4),s32 *,0x6c)) {
n=data_0213e5f8[7]+1;
data_0213e5f8[7]=n;
} else {
LockMutex(&data_0213e6c4);
M2C_FIELD(&data_0213e5d4,s32 *,0x1c)=M2C_FIELD(M2C_FIELD(&gSocketManager,void **,4),s32 *,0x6c);
data_0213e5f8[7]=1;
}
n=arg0-1;
cb=((M2C_UNK (**)(s32))&data_0213e9f8)[n];
if(cb!=(M2C_UNK (*)(s32))1) ((M2C_UNK (**)(s32))&data_0213e9f8)[n]=0;
n=data_0213e5f8[7]-1;
data_0213e5f8[7]=n;
if(n==0) UnlockMutex(&data_0213e6c4);
if(cb==(M2C_UNK (*)(s32))1 || (cb==0 && arg0==1)) return 0;
if(cb==0) func_02063e1c(0);
cb(arg0);
return 0;
}

s32 StringLength(s8 *arg0) {
    s32 var_r2;
    s8 *var_r0;
    s8 temp_r1;

    var_r0 = arg0;
    var_r2 = -1;
    do {
        temp_r1 = *var_r0;
        var_r0 += 1;
        var_r2 += 1;
    } while (temp_r1 != 0);
    return var_r2;
}
