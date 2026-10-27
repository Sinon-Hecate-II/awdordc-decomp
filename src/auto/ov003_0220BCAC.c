/* 13 functions from 0x0220BCAC to 0x0220C6C8 (ov003), found by ds-decomp. */
#include "common.h"

s8 func_ov003_0220bf68(void *arg0) {
    return M2C_FIELD(arg0, s8 *, 0xB);
}

void func_ov003_0220bf70(void) {
    M2C_UNK func_01ff9d88(M2C_UNK);
    extern void *data_027e00c4;
    func_01ff9d88(1);
    M2C_FIELD(data_027e00c4, u8 *, 0x46) = (u8) (M2C_FIELD(data_027e00c4, u8 *, 0x46) | 2);
}

void func_ov003_0220bf98(void *a) {
M2C_UNK func_020a8f8c(s32);M2C_UNK func_ov003_022084f0(void *);
s32 i,offset,flag;
func_020a8f8c(M2C_FIELD(a,s32 *,0x54));
flag=M2C_FIELD(a,u8 *,0x34)!=0;
if((u8)flag){func_ov003_022084f0(a);return;}
func_020a8f8c(M2C_FIELD(a,s32 *,0x50));
i=0;if((s32)*M2C_FIELD(a,u8 **,0x44)<=0)return;
offset=0;do {
void *p=(u8 *)M2C_FIELD(a,void **,0x48)+offset;
s32 value,limit,delta,v;u32 x,y;
x=M2C_FIELD(p,u8 *,0x11);y=M2C_FIELD(p,u8 *,0x12);
value=M2C_FIELD(p,s8 *,0x13);delta=M2C_FIELD(p,s8 *,0x15);
if(x==y){
limit=M2C_FIELD(p,s8 *,0x14);v=value+delta;
if(v<=limit){if(v<0)v=0;limit=v;}
M2C_FIELD(p,s8 *,0x13)=limit;
}else{
limit=M2C_FIELD(p,s8 *,0x14);v=value-delta;
if(v<=limit){if(v<0)v=0;limit=v;}
M2C_FIELD(p,s8 *,0x13)=limit;
}
y=M2C_FIELD(p,u8 *,0x12);
if(M2C_FIELD(p,u8 *,0x11)!=y&&M2C_FIELD(p,s8 *,0x13)==0)M2C_FIELD(p,u8 *,0x11)=y;
limit=M2C_FIELD(p,u16 *,14);x=M2C_FIELD(p,u16 *,12);delta=M2C_FIELD(p,u8 *,16);
if(x<(u32)limit){
v=x+delta;if(v<=limit){if(v<205)v=205;limit=v;}
M2C_FIELD(p,u16 *,12)=limit;
}else{
v=x-delta;if(v>256)limit=256;else if(v>=limit)limit=v;
M2C_FIELD(p,u16 *,12)=limit;
}
i++;offset+=36;
}while(i<(s32)*M2C_FIELD(a,u8 **,0x44));
}

void func_ov003_0220c0e8(void *arg0) {
    M2C_UNK func_020bf9f0(s16);
    M2C_UNK func_020bfa30(s16);
    func_020bf9f0(M2C_FIELD(M2C_FIELD(arg0, void **, 0x60), s16 *, 0x12));
    func_020bfa30(M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), s16 *, 0x12));
}

void func_ov003_0220c328(void *arg0, int arg1) {
 extern void *data_027e00c4;
 u8 *p=arg0; u8 *q; int v; u8 a,b;
 p[0x38]&=~2;
 q=*(u8 **)(p+0x3c); v=q[0x10];
 func_0208fe30(0x1000f);
 if((u8)((((unsigned int)p[0x36]<<24)>>28)==1) || (u8)((((unsigned int)p[0x36]<<24)>>28)==2)){p[0x35]=1;func_020d47f0();func_01ffa6fc(p);}
 p[0x38]&=~8;
 q=*(u8 **)(p+0x3c);q[q[0xf]]=arg1;
 if(v!=16){p[0x34]=30;func_ov003_0220a698(p,v);func_ov003_0220828c(p,5,255);func_01ff9d88(1);M2C_FIELD(data_027e00c4,u8 *,0x46)|=2;}
 else {func_020d47f0();func_01ffa6fc(p);}
}

void func_ov003_0220c6a4(void) {
    M2C_UNK func_ov003_022066d8();
    func_ov003_022066d8();
}

void func_ov003_0220c6b0(void) {
    M2C_UNK func_ov003_02209310();
    func_ov003_02209310();
}

void func_ov003_0220c6bc(void) {
    M2C_UNK func_ov003_02209cdc();
    func_ov003_02209cdc();
}

