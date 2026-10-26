/* 16 functions from 0x020251B8 to 0x02026164 (main), found by ds-decomp. */
#include "common.h"
void func_020258ac(void *, u32 *, u32);

void func_020251b8(s32 now) {
void func_0200751c(void);void func_02007530(void);void func_02005e5c(void *);
extern M2C_UNK data_02138cc8;extern M2C_UNK data_0212dca4;
void *q; u8 *p; s32 i; void *node;
func_0200751c();
i=0;p=(u8 *)&data_02138cc8;
do{
if(p[0x5a]==0){}else if(now-M2C_FIELD(p,s32 *,0x50)>957)p[0x5a]=0;
i++;p+=0x5c;
}while(i<4);
func_02007530();
node=M2C_FIELD(&data_0212dca4,void **,8);
while(node!=NULL){
q=M2C_FIELD(node,void **,0xa4);
if(q!=NULL && M2C_FIELD(q,void **,0)!=NULL && M2C_FIELD(q,u8 *,9)!=0 && M2C_FIELD(q,u8 *,8)==4 && M2C_FIELD(M2C_FIELD(q,void **,12),u8 *,0x455)<8 && now-M2C_FIELD(q,s32 *,16)>239 && M2C_FIELD(q,s32 *,4)==2){
M2C_FIELD(q,u8 *,8)=0;M2C_FIELD(q,s32 *,4)=0;func_02005e5c(M2C_FIELD(q,void **,0));
}
node=M2C_FIELD(node,void **,0x68);
}
}

void func_02025298(void) {
    M2C_UNK func_02007f8c(M2C_UNK *, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_02138cc8;
    func_02007f8c(&data_02138cc8, 0, 0x170);
}

void func_020252b4(M2C_UNK *arg0, void *arg1, u32 arg2) {
    void func_02008048(s32, void *, u32);
    func_02008048(arg1, arg0, arg2);
}

void func_020252cc(M2C_UNK *arg0, void *arg1, u32 arg2) {
    void func_02008048(s32, void *, u32);
    func_02008048(arg1, arg0, arg2);
}

void func_02025700(void *arg0) {
    func_02007f8c(arg0, 0, 0x58);
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
}

void func_02025748(void *arg0, s32 arg1, u32 arg2) {
    void func_02008048(s32, void *, u32);
    void func_020252e4(void *, s32);
    s32 index;
    u32 low;
    u32 old;
    u32 count;
    old = M2C_FIELD(arg0, u32 *, 0x10);
    low = old + arg2 * 8;
    M2C_FIELD(arg0, u32 *, 0x10) = low;
    if (low < arg2 * 8) M2C_FIELD(arg0, u32 *, 0x14) += 1;
    index = (old >> 3) & 0x3F;
    count = 0x40 - index;
    M2C_FIELD(arg0, u32 *, 0x14) += arg2 >> 29;
    if (arg2 >= count) {
        func_02008048(arg1, (u8 *)arg0 + 0x18 + index, count);
        index = 0;
        func_020252e4(arg0, (s32)arg0 + 0x18);
        if (count + 0x3F < arg2) {
            do {
                func_020252e4(arg0, arg1 + count);
                count += 0x40;
            } while (count + 0x3F < arg2);
        }
    } else count = 0;
    func_02008048((u8 *)arg1 + count, (u8 *)arg0 + 0x18 + index, arg2 - count);
}


void func_02025800(void *arg0, M2C_UNK *arg1) {
    void func_020252b4(M2C_UNK *, void *, u32);
    void func_02025748(void *, s32, u32);
    extern M2C_UNK data_020fb0a4;
    s32 temp_r0;
    s32 var_r2;

    func_020252b4(arg1, arg0 + 0x10, 8);
    temp_r0 = ((u32) M2C_FIELD(arg0, u32 *, 0x10) >> 3) & 0x3F;
    if (temp_r0 < 0x38) {
        var_r2 = 0x38 - temp_r0;
    } else {
        var_r2 = 0x78 - temp_r0;
    }
    func_02025748(arg0, &data_020fb0a4, var_r2);
    func_02025748(arg0, arg1, 8);
    func_020252b4(arg1, arg0, 0x10);
}

s32 func_02025868(s32 arg0, u32 *arg1) {
    u32 value;
    u32 result;
    value = arg1[arg0] ^ (arg1[(arg0 + 2) & 15] ^ (arg1[(arg0 + 13) & 15] ^ arg1[arg0 ^ 8]));
    result = (value << 1) | (value >> 31);
    arg1[arg0] = result;
    return result;
}

void func_020258ac(void *arg0, u32 *arg1, u32 arg2) {
    u8 *out = arg0;
    
    u32 i = 0;
    u32 value;
    arg2 >>= 2;
    if (arg2 == 0) return;
    do {
        value = *arg1++;
        i++;
        out[0] = value >> 24;
        out[1] = value >> 16;
        out[2] = value >> 8;
        out[3] = value;
        out += 4;
    } while (i < arg2);
}

void func_020258f0(u32 *arg0,u8 *arg1,u32 arg2) {
u32 i=0,value; u8 *p; u8 last;
if(i>=arg2)return;
do {
p=arg1+i;
last=p[3];
value=(p[1]<<16)|(arg1[i]<<24)|(p[2]<<8);
i+=4;
*arg0++=last|value;
}while(i<arg2);
}

void func_02025fc0(void *arg0) {
    func_02007f8c(arg0, 0, 0x5C);
    M2C_FIELD(arg0, s32 *, 0) = 0x67452301;
    M2C_FIELD(arg0, s32 *, 4) = 0xEFCDAB89;
    M2C_FIELD(arg0, s32 *, 8) = 0x98BADCFE;
    M2C_FIELD(arg0, s32 *, 0xC) = 0x10325476;
    M2C_FIELD(arg0, s32 *, 0x10) = 0xC3D2E1F0;
}

M2C_UNK func_02026014(void *arg0, s32 arg1, u32 arg2) {
void func_02008048(s32,void *,u32);
void func_02025938(void *,s32);
s32 index;
u32 low,old,count;
old=M2C_FIELD(arg0,u32 *,0x18);
low=old+arg2*8;
M2C_FIELD(arg0,u32 *,0x18)=low;
if(low<arg2*8) M2C_FIELD(arg0,u32 *,0x14)+=1;
index=(old>>3)&0x3f;
count=0x40-index;
M2C_FIELD(arg0,u32 *,0x14)+=arg2>>29;
if(arg2>=count) {
func_02008048(arg1,(u8 *)arg0+0x1c+index,count);
index=0;
func_02025938(arg0,(s32)arg0+0x1c);
if(count+0x3f<arg2) do {
func_02025938(arg0,arg1+count);
count+=0x40;
}while(count+0x3f<arg2);
}else count=0;
func_02008048(arg1+count,(u8 *)arg0+0x1c+index,arg2-count);
}

void func_020260cc(void *arg0, M2C_UNK *arg1) {
    extern M2C_UNK data_020fb1e4;
    s32 temp_r0;
    s32 var_r2;

    func_020258ac(arg1, arg0 + 0x14, 8);
    temp_r0 = ((u32) M2C_FIELD(arg0, u32 *, 0x18) >> 3) & 0x3F;
    if (temp_r0 < 0x38) {
        var_r2 = 0x38 - temp_r0;
    } else {
        var_r2 = 0x78 - temp_r0;
    }
    func_02026014(arg0, &data_020fb1e4, var_r2);
    func_02026014(arg0, arg1, 8);
    func_020258ac(arg1, arg0, 0x14);
}

void func_02026134(M2C_UNK arg0, M2C_UNK arg1) {
    void func_020258ac(void *, u32 *, u32);
    M2C_UNK func_02026014();
    extern M2C_UNK data_020fb1e5;
    func_02026014(arg0, &data_020fb1e5, 0x2C);
    func_020258ac(arg1, arg0, 0x14);
}

