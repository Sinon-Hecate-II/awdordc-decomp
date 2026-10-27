/* 35 functions from 0x02174F68 to 0x02175F60 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { u8 kind; u8 pad; u16 size; char text[256]; } MenuRecord;
extern struct { u8 state; u8 pad[3]; void *ptr; } data_ov001_02193d24;

typedef struct { s32 x; u32 y; } Position;

void func_ov001_02175600(int arg0) {
extern void *data_ov001_02193d20;
int i; unsigned int *ptr;
func_ov001_0218c92c(0,arg0);
for(i=0;i<4;i++){ptr=(unsigned int *)data_ov001_02193d20;func_ov001_0218a1cc(((void **)ptr)[i+0x12]);ptr=(unsigned int *)data_ov001_02193d20;func_ov001_0218ace0(((void **)ptr)[i]);}
for(i=0;i<2;i++){ptr=(unsigned int *)data_ov001_02193d20;func_ov001_0218a1cc(((void **)ptr)[i+0x10]);}
for(i=0;i<2;i++){ptr=(unsigned int *)data_ov001_02193d20;func_ov001_0218c104(((void **)ptr)[i+0xe]);}
for(i=0;i<10;i++){ptr=(unsigned int *)data_ov001_02193d20;func_ov001_0218c104(((void **)ptr)[i+4]);}
func_ov001_0218b71c((void *)0x02193D20);
}

void func_ov001_021756c0(void){
void *func_ov001_0218b6f8(s32,s32);
extern char data_ov001_0218f6e8[];
void func_ov001_02175880(void); void func_ov001_02175890(void);
MenuRecord rec;
data_ov001_02193d24.ptr=func_ov001_0218b6f8(0x26c,4);
data_ov001_02193d24.state=0;
func_02007df8(0,&rec,0x104);
rec.kind=0x50; rec.size=12;
func_02008048(data_ov001_0218f6e8,rec.text);
M2C_FIELD(data_ov001_02193d24.ptr,s16 *,0)=3;
M2C_FIELD(data_ov001_02193d24.ptr,MenuRecord *,2)=rec;
M2C_FIELD(data_ov001_02193d24.ptr,s16 *,0x106)=1;
M2C_FIELD(data_ov001_02193d24.ptr,s16 *,0x108)=-1;
M2C_FIELD(data_ov001_02193d24.ptr,s16 *,0x10a)=1;
M2C_FIELD(data_ov001_02193d24.ptr,s16 *,0x10c)=-1;
M2C_FIELD(data_ov001_02193d24.ptr,s16 *,0x10e)=-1;
func_02007724((char *)data_ov001_02193d24.ptr+0x110);
if(func_ov001_0216d088(func_ov001_02175880,func_ov001_02175890))func_02007958();
}

