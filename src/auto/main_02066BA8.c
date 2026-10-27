/* 11 functions from 0x02066BA8 to 0x020677B8 (main), found by ds-decomp. */
#include "common.h"
static inline void heapSwap(s8 *a,s8 *b,u32 n) { s8 t; if(n) do { t=*a; *a++=*b; *b++=t; } while(--n); }

s32 func_020673cc(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 func_02064684(M2C_UNK, M2C_UNK, s32, s32);
    s32 var_r5;

    var_r5 = arg0;
    if (arg2 != func_02064684(arg1, 1, arg2, var_r5)) {
        var_r5 = 0;
    }
    return var_r5;
}

s32 func_020673f8(void *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_020651a4(s32, M2C_UNK, s32);
    s32 temp_r3;
    s32 var_r5;
    u32 temp_r2;

    temp_r3 = M2C_FIELD(arg0, s32 *, 8);
    var_r5 = arg2;
    temp_r2 = M2C_FIELD(arg0, u32 *, 4);
    if ((u32) (temp_r3 + var_r5) > temp_r2) {
        var_r5 = temp_r2 - temp_r3;
    }
    func_020651a4(M2C_FIELD(arg0, s32 *, 0) + temp_r3, arg1, var_r5);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + var_r5);
    return 1;
}

s32 func_0206743c(s32 format, ...) {
extern u8 data_02100218[],data_0213e664[],data_0213e5d4[],data_0213e5f8[],data_0212dca4[];
s32 func_0206ad4c(void *,s32);s32 func_02006680(void *);u32 func_02066ba8();
s32 result;char *args;
if(func_0206ad4c(data_02100218,-1)>=0)return -1;
if(!func_02006680(data_0213e664)){
M2C_FIELD(data_0213e5d4,s32 *,12)=M2C_FIELD(M2C_FIELD(data_0212dca4,void **,4),s32 *,0x6c);
M2C_FIELD(data_0213e5f8,s32 *,12)=1;
}else if(M2C_FIELD(data_0213e5d4,s32 *,12)==M2C_FIELD(M2C_FIELD(data_0212dca4,void **,4),s32 *,0x6c)){
M2C_FIELD(data_0213e5f8,s32 *,12)++;
}else{
func_02006564(data_0213e664);
M2C_FIELD(data_0213e5d4,s32 *,12)=M2C_FIELD(M2C_FIELD(data_0212dca4,void **,4),s32 *,0x6c);
M2C_FIELD(data_0213e5f8,s32 *,12)=1;
}
args=(char *)(((u32)&format&~3U)+4);
result=func_02066ba8(func_020673cc,data_02100218,format,args);
if(--M2C_FIELD(data_0213e5f8,s32 *,12)==0)func_020065e8(data_0213e664);
return result;
}

u32 func_02067554(char *arg0, u32 arg1, s32 arg2, void *arg3) {
    u32 func_02066ba8();
    struct { char *buffer; u32 size; u32 position; } state;
    u32 result;
    state.buffer = arg0;
    state.size = arg1;
    state.position = 0;
    result = func_02066ba8(func_020673f8, &state, arg2, arg3);
    if (arg0 == 0) return result;
    if (result < arg1) {
        arg0[result] = 0;
        return result;
    }
    if (arg1 != 0) (arg0 + arg1)[-1] = 0;
    return result;
}

void func_020675bc(s32 arg0, s32 arg1, s32 arg2, ...) {
    char *args;
    args = (char *)(((u32)&arg2 & ~3U) + 4);
    func_02067554(arg0, arg1, arg2, args);

}

void func_020675e4(s32 arg0, s32 arg1, ...) {
    char *args;
    args = (char *)(((u32)&arg1 & ~3U) + 4);
    func_02067554((char *)arg0, -1, arg1, args);
}

void func_02067610(s8 *base,u32 count,u32 size,s32 (*compare)(const void*,const void*)) {
u32 root,child,k; s8 *start,*end,*parent,*q,*p; s8 byte; u32 offset,neg;
if(count<2)return;
root=(count>>1)+1;
start=base+size*(root-1);end=base+size*(count-1);offset=root*size;neg=size*-1;
for(;;){
if(root>1){--root;offset-=size;start-=size;}
else {
heapSwap(start,end,size);
if(--count==1)return;
end-=size;
}
child=root;p=base+(offset+neg);
while(count>=child*2){
child*=2;parent=p;p=base+size*(child-1);
if(count>child && compare(p,p+size)<0){child++;p+=size;}
if(compare(parent,p)>=0)break;
heapSwap(parent,p,size);
}
}
}

s32 func_02067774(void) {
    extern s32 data_02100554;
    u32 value;
    value = (data_02100554 * 0x41C64E6D) + 0x3039;
    data_02100554 = value;
    return 0x7FFF & (value >> 16);
}

void func_020677a8(s32 arg0) {
    extern s32 data_02100554;
    data_02100554 = arg0;
}
