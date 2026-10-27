/* 20 functions from 0x02097C50 to 0x02098BD4 (main), found by ds-decomp. */
#include "common.h"

void func_02097c50(u32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 func_0209e9dc(u16); M2C_UNK func_0209e25c(s32,M2C_UNK,M2C_UNK,M2C_UNK);
 s32 t=func_0209e9dc((u16)arg0); if(!t)return; func_0209e25c(t,2,arg1,arg2);
}

void func_02097c84(u32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
 s32 func_0209e9dc(u16); M2C_UNK func_0209e25c(s32,M2C_UNK,M2C_UNK,M2C_UNK);
 s32 t=func_0209e9dc((u16)arg0); if(!t)return; func_0209e25c(t,1,arg1,arg2);
}

void func_02097cb8(u32 arg0) { s32 func_0209e9dc(u16); M2C_UNK func_0209e25c(s32,M2C_UNK,M2C_UNK,M2C_UNK); s32 t=func_0209e9dc((u16)arg0); if(!t)return; func_0209e25c(t,0,0,0); }

s32 func_02098278(s32 a){extern M2C_UNK data_021031e8,data_021031f0,data_021031fc,data_02103208,data_02103214,data_02103220,data_0210322c,data_02103238,data_02103244,data_02103250,data_0210325c,data_02103268;switch(a){case 0:return (s32)&data_021031e8;case 1:return (s32)&data_021031f0;case 2:return (s32)&data_021031fc;case 3:return (s32)&data_02103208;case 4:return (s32)&data_02103214;case 5:return (s32)&data_02103220;case 6:return (s32)&data_0210322c;case 7:return (s32)&data_02103238;case 8:return (s32)&data_02103244;case 9:return (s32)&data_02103250;case 10:return (s32)&data_0210325c;case 11:return (s32)&data_02103268;default:return 0;}}

/* Returns a filename string from one of the face/skin filename tables based on a transformed index and type. */
s32 func_0209834c(s32 index, s32 type) {
    s32 func_020bf8cc(s32);
    extern s32 data_02102ffc[], data_0210300c[], data_0210301c[];
    if (index == 15) {
        index = 4;
    }
    index = func_020bf8cc(index);
    switch (type) {
    case 0: return data_02102ffc[index];
    case 1: return data_02102ffc[index];
    case 2: return data_02102ffc[index];
    case 3: return data_02102ffc[index];
    case 4: return data_02102ffc[index];
    case 5: return data_0210300c[index];
    case 6: return data_0210300c[index];
    case 7: return data_0210300c[index];
    case 8: return data_02102ffc[index];
    case 9: return data_02102ffc[index];
    case 10: return data_02102ffc[index];
    case 11: return data_0210301c[index];
    default: return 0;
    }
}

s32 func_02098440(s32 arg0) {
 switch((u32)arg0) {
case 0: return 48;
case 1: return 56;
case 2: return 72;
case 3: return 72;
case 4: return 72;
case 5: return 48;
case 6: return 48;
case 7: return 48;
case 8: return 160;
case 9: return 160;
case 10: return 160;
case 11: return 256;
 default:return 0;
 }
}

s32 func_020984e4(s32 a){switch((u32)a){case 0:return 16;case 1:return 56;case 2:return 64;case 3:return 64;case 4:return 64;case 5:return 48;case 6:return 48;case 7:return 48;case 8:return 192;case 9:return 192;case 10:return 192;case 11:return 64;default:return 0;}}

s32 func_02098588(s32 arg0) {
    s32 func_02098440();
    s32 func_020984e4(s32);
    s32 temp_r4;
    s32 var_r0;

    temp_r4 = func_02098440(arg0);
    var_r0 = temp_r4 * func_020984e4(arg0);
    if (arg0 == 1) {
        var_r0 += temp_r4;
    }
    return var_r0;
}

void func_020985b0(s32 unused,s32 a,s32 b){s32 func_02098034(void);s32 func_02098278(s32);M2C_UNK func_0200bc5c(s32);void func_02080cfc(s32,s32);s32 x,y;x=func_02098034();y=func_02098278(a);if(!x)return;func_0200bc5c(x);func_02080cfc(y,b);}

#pragma opt_strength_reduction off
void func_020985f0(s32 src,s32 dst,u32 w,u32 h,u8 half){
void func_02007ef4(s32,s32,u32);
s32 y0,col0,tile0,row0,width0,height0,x0;
s32 tile1,width1,height1,y1,x1,row1;
if(w<=1){func_02007ef4(src,dst,(half?32:64)*(w*h));return;}
if(half){
height0=(u16)(h*8);
y0=0;if(height0<=0)return;
width0=(u16)(w*4);row0=0;
do{
x0=0;if(width0>0){tile0=(y0>>3)*w;col0=0;do{
*(u32 *)(dst+x0+row0)=*(u32 *)(src+((col0+tile0)<<5)+(x0&3)+((y0&7)<<2));
col0++;x0+=4;}while(x0<width0);}
y0++;row0+=width0;
}while(y0<height0);
}else{
height1=(u16)(h*8);
y1=0;if(height1<=0)return;
width1=(u16)(w*8);row1=0;
do{
x1=0;if(width1>0){tile1=(y1>>3)*w;do{
*(u32 *)(dst+x1+row1)=*(u32 *)(src+((tile1+(x1>>3))<<6)+(x1&7)+((y1&7)<<3));
x1+=4;}while(x1<width1);}
y1++;row1+=width1;
}while(y1<height1);
}
}
s32 func_0209871c(s32 unused,s32 type,s32 dst){
s32 func_02098034(void);s32 func_02098588(s32);void func_02080cfc(s32,s32);M2C_UNK func_0200bc5c(s32);
void func_020985f0(s32,s32,u32,u32,u8);
s32 func_020e34bc(void);M2C_UNK func_020e35cc(s32);
s32 size,x,y,buf,i0,off0,n0,off1,n1,i1;
x=func_02098034();y=func_02098278(type);size=0;
if(x){
size=func_02098588(type);buf=func_020e34bc();func_0200bc5c(x);func_02080cfc(y,buf);
switch(type){
case 0:
i0=0;n0=size>>8;
if(n0>0){off0=0;do{func_020985f0(buf+(off0<<6),dst+(off0<<6),2,2,0);i0++;off0+=4;}while(i0<n0);}break;
case 2:case 3:case 4:
i1=0;n1=size>>8;
if(n1>0){off1=0;do{func_020985f0(buf+(off1<<6),dst+(off1<<6),1,4,0);i1++;off1+=4;}while(i1<n1);}break;
}
func_020e35cc(buf);
}return size;
}
/* Fills a tile-map rectangle for the given layout index, optionally mirroring it. */
void func_02098844(u32 layout, s32 col, s32 row, s32 vramBase, u16 startTile, u16 palette, u8 mirror) {
    s32 widthPx;
    M2C_UNK func_02080b38(s32, u16, u16);
    s32 heightPx;
    M2C_UNK func_02080a6c(s32, u16, u16, u16, s32, s32, s32);
    unsigned int offset;
    s32 tileWidth;
    register s32 tileHeight;
    s32 cols;
    s32 rows;

    widthPx = func_02098440(layout);
    tileWidth = (s32) (widthPx + ((u32) (widthPx >> 2) >> 0x1D)) >> 3;
    heightPx = func_020984e4(layout);
    tileHeight = (s32) (heightPx + ((u32) (heightPx >> 2) >> 0x1D)) >> 3;
    cols = tileWidth;
    rows = tileHeight;
    switch (layout) {
    default:
        break;
    case 1:
        cols = 1;
        rows = 4;
        break;
    case 0:
    case 5:
    case 6:
    case 7:
        cols = 2;
        rows = 2;
        break;
    case 2:
    case 3:
    case 4:
        cols = 1;
        rows = 4;
        break;
    case 8:
    case 9:
    case 10:
        cols = 4;
        rows = 8;
        break;
    case 11:
        cols = 8;
        rows = 8;
        break;
    }
    offset = vramBase + (col * 2) + (row << 6);
    func_02080a6c(offset, (u16) tileWidth, (u16) tileHeight, (u16) cols, (s32) (u16) rows, (s32) startTile, (s32) palette);
    if (!mirror) {
        return;
    }
    func_02080b38(offset, (u16) tileWidth, (u16) tileHeight);
}

void func_02098970(M2C_UNK arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_020ae548(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    M2C_UNK func_020ae67c(M2C_UNK, s32);
    M2C_UNK func_020ae728(M2C_UNK, s32);
    if (arg1 & 1) {
        func_020ae548(arg0, 0, 0xA, 6, arg2);
    }
    if (arg1 & 8) {
        func_020ae548(arg0, 0, 8, 8, arg2);
    }
    if (arg1 & 0x10) {
        func_020ae548(arg0, 0, 4, 0xC, arg2);
    }
    if (arg1 & 0x20) {
        func_020ae548(arg0, 0, 0, 0x10, arg2);
    }
    if (arg1 & 2) {
        func_020ae67c(arg0, arg2);
    }
    if (!(arg1 & 4)) {
        return;
    }
    func_020ae728(arg0, arg2);
}

void func_02098a34(s32 a,s32 b,s32 c,s32 d,u8 e){s32 func_02098034(void);s32 func_0209834c(s32,s32);M2C_UNK func_0200bc5c(s32);s32 func_02081128(s32,s32);void func_0207c650(s32,s32,u16,s32,s32);s32 p,q;u16 off;p=func_02098034();q=func_0209834c(a,b);off=d<<9;if(!p)return;func_0200bc5c(p);q=func_02081128(q,512);func_02098970(q,e,512);func_0207c650(q,c,off,512,1);}

void func_02098ac0(s32 a,s32 b,s32 c,s32 d){s32 func_02098034(void);s32 func_0209834c(s32,s32);M2C_UNK func_0200bc5c(s32);s32 func_02081128(s32,s32);void func_0207c728(s32,s32,u16,s32,s32);s32 p,q;u16 off;p=func_02098034();q=func_0209834c(a,b);off=c<<9;if(!p)return;func_0200bc5c(p);q=func_02081128(q,512);func_02098970(q,d,512);func_0207c728(q,0,off,512,1);}

void func_02098b4c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_0200bc5c(s32);
    M2C_UNK func_02080c50(s32, M2C_UNK);
    s32 func_02098034();
    s32 func_0209834c(M2C_UNK, M2C_UNK);
    s32 temp_r4;
    s32 temp_r5;

    temp_r5 = func_02098034();
    temp_r4 = func_0209834c(arg0, arg1);
    if (temp_r5 == 0) {
        return;
    }
    func_0200bc5c(temp_r5);
    func_02080c50(temp_r4, arg2);
}

void func_02098b94(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    void func_020985b0(M2C_UNK, M2C_UNK, s32);
    void func_02098ac0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    func_020985b0(arg0, arg1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x1C) + arg2);
    func_02098ac0(arg0, arg1, arg3, 0);
}

