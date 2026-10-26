/* 17 functions from 0x02076698 to 0x02077624 (main), found by ds-decomp. */
#include "common.h"

void func_02076698(u8 *table,u32 poly){u32 v,i,j;
for(i=0;i<256;i++){v=i;for(j=0;j<8;j++){if(v&128)v=(v<<1)^poly;else v<<=1;}table[i]=v;}
}

s32 func_020766d8(s32 table,u8 *crc,s32 data,s32 size){u32 v,i;u8 *p=(u8*)data;v=*crc;
for(i=0;i<(u32)size;i++)v=((u8*)table)[(u8)(v^*p++)];*crc=v;
}

void func_02076710(u16 *table,u32 poly){u32 v,j,i;
for(i=0;i<256;i++){v=i;for(j=0;j<8;j++){if(v&1)v=(v>>1)^poly;else v>>=1;}table[i]=v;}
}

s32 func_02076754(s32 table,u16 *state,s32 data,s32 size) {
 u32 crc=*state; u32 i; u8 *p=(u8 *)data;
 for(i=0;i<(u32)size;i++) crc=M2C_FIELD(table,u16 *, ((crc ^ *p++) << 24) >> 23) ^ (crc >> 8);
 *state=crc;
}

void func_02076794(u32 *table,u32 poly) {
 u32 crc; u32 i; u32 j; u32 zero;
 i=0; zero=0;
 do { crc=i; j=zero;
 do { if(crc&1) crc=poly^(crc>>1); else crc>>=1; j++; }while(j<8);
 table[i]=crc; i++;
 }while(i<256);
}

s32 func_020767d4(s32 table,s32 *state,s32 data,s32 size) {
 u32 crc=*state; u32 i; u8 *p=(u8 *)data;
 for(i=0;i<(u32)size;i++) crc=((u32 *)table)[(u8)(crc ^ *p++)] ^ (crc >> 8);
 *state=crc;
}

u8 func_02076810(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020766d8(M2C_UNK, u8 *, M2C_UNK, M2C_UNK);
    u8 sp0;

    sp0 = 0;
    func_020766d8(arg0, &sp0, arg1, arg2);
    return sp0;
}

u16 func_02076838(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02076754(M2C_UNK, u16 *, M2C_UNK, M2C_UNK);
    u16 sp0;

    sp0 = 0;
    func_02076754(arg0, &sp0, arg1, arg2);
    return sp0;
}

s32 func_02076860(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_020767d4(M2C_UNK, s32 *, M2C_UNK, M2C_UNK);
    s32 sp0;

    sp0 = -1;
    func_020767d4(arg0, &sp0, arg1, arg2);
    return ~sp0;
}

void func_0207688c(void) {
    M2C_UNK func_02007e98(M2C_UNK, M2C_UNK *, s32);
    extern M2C_UNK data_02141008;
    extern M2C_UNK data_02141788;
    extern M2C_UNK data_02141f08;
    extern M2C_UNK data_02142688;
    extern M2C_UNK data_02142ebc;
    extern M2C_UNK data_02143dbc;
    func_02007e98(0, &data_02142688, 0x834);
    func_02007e98(0, &data_02141f08, 0x900);
    func_02007e98(0, &data_02141788, 0x900);
    func_02007e98(0, &data_02141008, 0x900);
    func_02007e98(0, &data_02142ebc, 0x1200);
    func_02007e98(0, &data_02143dbc, 0x1200);
}

void func_02076910(s32 x,s32 y) {
 extern void *data_027e0058;
 extern M2C_UNK data_02142688;
 void *p; s32 b,a;
 if(x<0 || y<0) return;
 p=(u8 *)M2C_FIELD(data_027e0058,void **,0)+0x5120;
 if(x>=M2C_FIELD(p,u16 *,0x24) || y>=M2C_FIELD(p,u16 *,0x26)) return;
 b=(s32)&data_02142688+(x+1)*42; a=(s32)&data_02142688+x*42;
 M2C_FIELD(y,u8 *,a)=7; M2C_FIELD(y,u8 *,b)=7;
 M2C_FIELD(y+1,u8 *,a)=7; M2C_FIELD(y+1,u8 *,b)=7;
}

void func_02077480(void){extern M2C_UNK data_02140f70;
if(M2C_FIELD(&data_02140f70,s32*,12)==0)M2C_FIELD(&data_02140f70,s32*,12)=1;
}

void func_0207749c(void) {
    extern M2C_UNK data_02140f70;
    M2C_FIELD(&data_02140f70, s32 *, 0xC) = 0;
}

void func_020774b0(void) {
 extern M2C_UNK data_02140f70;
 s32 n=M2C_FIELD(&data_02140f70,s32 *,12);
 if(n<8) M2C_FIELD(&data_02140f70,s32 *,12)=n+1;
}

s32 func_020774cc(void) {
 extern void *data_027e0058;
 extern M2C_UNK data_02140f70;
 if(M2C_FIELD(M2C_FIELD(data_027e0058,void **,4),s32 *,0x60)) return M2C_FIELD(&data_02140f70,s32 *,12)!=0;
 return 0;
}

