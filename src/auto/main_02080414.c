/* 34 functions from 0x02080414 to 0x02081400 (main), found by ds-decomp. */
#include "common.h"

void func_02080414(void *arg0) {
 M2C_UNK func_01ffa6fc(void *); s8 func_0207ca38(s32,s32,s32,s32,s32);
 extern void *gCur3DSpriteEngine;
 if(M2C_FIELD(arg0,s16 *,0x6C)==0) {func_01ffa6fc(arg0);return;}
 M2C_FIELD(arg0,s32 *,0x5C)++;
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),s8 *,0x50)=func_0207ca38(0,0,16,M2C_FIELD(arg0,s32 *,0x5C),M2C_FIELD(arg0,s16 *,0x6C));
 if(M2C_FIELD(arg0,s32 *,0x5C)!=M2C_FIELD(arg0,s16 *,0x6C)) return;
 func_01ffa6fc(arg0);
}

void func_02080498(void *arg0) {
 M2C_UNK func_01ffa6fc(void *);
 s32 temp_r2;
 if(M2C_FIELD(arg0,s16 *,0x6E)==0) {func_01ffa6fc(arg0);return;}
 temp_r2=M2C_FIELD(arg0,s32 *,0x60)+1;
 M2C_FIELD(arg0,s32 *,0x60)=temp_r2;
 if(temp_r2!=M2C_FIELD(arg0,s16 *,0x6E)) return;
 func_01ffa6fc(arg0);
}

void func_020804d0(void *arg0) {
 M2C_UNK func_01ffa6fc(void *); s8 func_0207ca38(s32,s32,s32,s32,s32);
 extern void *gCur3DSpriteEngine;
 if(M2C_FIELD(arg0,s16 *,0x70)==0) {func_01ffa6fc(arg0);return;}
 M2C_FIELD(arg0,s32 *,0x64)++;
 M2C_FIELD(M2C_FIELD(gCur3DSpriteEngine,void **,0),s8 *,0x50)=func_0207ca38(0,16,0,M2C_FIELD(arg0,s32 *,0x64),M2C_FIELD(arg0,s16 *,0x70));
 if(M2C_FIELD(arg0,s32 *,0x64)!=M2C_FIELD(arg0,s16 *,0x70)) return;
 func_01ffa6fc(arg0);
}

void func_0208066c(void *arg0) {
    M2C_UNK func_02080554(s16, u16, M2C_UNK, M2C_UNK);
    func_02080554(M2C_FIELD(arg0, s16 *, 0x50), M2C_FIELD(arg0, u16 *, 0x52), 0, 0);
}

void func_0208068c(void *arg0) {
    func_02080554(M2C_FIELD(arg0, s16 *, 0x50), M2C_FIELD(arg0, u16 *, 0x52), 0, 0);
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
}

void func_020806b8(void *a) {
 M2C_UNK func_01ffa6fc(void *);
 s16 (*p)[2]=M2C_FIELD(a,s16 (**)[2],0x54);
 if(p[M2C_FIELD(a,s32 *,0x5c)][0]==0x7fff) {
 M2C_FIELD(a,s32 *,0x5c)=0;
 if(M2C_FIELD(a,s16 *,0x4c)==-1){func_01ffa6fc(a);return;}
 }
 func_02080554(M2C_FIELD(a,s16 *,0x50),M2C_FIELD(a,u16 *,0x52),p[M2C_FIELD(a,s32 *,0x5c)][0],p[M2C_FIELD(a,s32 *,0x5c)][1]);
 M2C_FIELD(a,s32 *,0x5c)++;
 M2C_FIELD(a,s32 *,0x60)++;
 if(M2C_FIELD(a,s32 *,0x60)!=M2C_FIELD(a,s16 *,0x4c))return;
 func_01ffa6fc(a);
}

void func_02080750(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK func_02080774(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02080774(4, arg0, arg1, 0x64, arg2);
}

M2C_UNK func_02080774(M2C_UNK a,M2C_UNK b,M2C_UNK c,M2C_UNK d,s32 e) {
 void *func_01ffa3dc(M2C_UNK *,M2C_UNK);void *func_01ffa42c(M2C_UNK *,s32);
 extern M2C_UNK data_02101cf8;extern void *data_02101cc4[];
 void *p;
 if(e)p=func_01ffa42c(&data_02101cf8,e);else p=func_01ffa3dc(&data_02101cf8,6);
 M2C_FIELD(p,void **,0x54)=data_02101cc4[b];
 M2C_FIELD(p,s16 *,0x4c)=c;
 M2C_FIELD(p,s16 *,0x50)=a;
 M2C_FIELD(p,s16 *,0x52)=d;
}

void func_020807d0(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_02101cf8;
    func_01ffa9e4(&data_02101cf8);
}

void func_020807e4(u8 *a,u16 *b,s32 c,s32 d) {
 u16 v=(c&0x3ff)|((d&15)<<12);
 s32 h=a[1];
 s32 w=a[0];
 u16 *p=(u16 *)(a+2);
 s32 x,y;
 for(y=0;y<h;y++)for(x=0;x<w;x++)b[y*32+x]=*p+++v;
}

void func_02080860(u16 *p,s32 w,s32 h,u32 tile,u16 pal) {
 s32 x,y; u16 v=(tile&0x3ff)|((pal&15)<<12);
 for(y=0;y<h;y++)for(x=0;x<w;x++)p[y*32+x]=v++;
}

void func_020808dc(u16 *p,s32 w,s32 h,u32 pal) {
 s32 x,y;
 for(y=0;y<h;y++)for(x=0;x<w;x++)p[y*32+x]=(p[y*32+x]&0xfff)|((pal&15)<<12);
}

void func_02080944(u16 *p,s32 w,s32 h,u32 pal) {
 s32 x,y;u16 v;u32 low;
 for(y=0;y<h;y++)for(x=0;x<w;x++){
 v=p[y*32+x];low=v&0xfff;v^=low;v+=(pal&15)<<12;p[y*32+x]=low|v;
 }
}

void func_020809c0(u16 *p,s32 w,s32 h){
 s32 x,y;
 for(y=0;y<h;y++)for(x=0;x<w;x++)p[y*32+x]=0;
}

void func_02080a14(u16 *p,s32 w,s32 h,u16 *q){
 s32 x,y;
 for(y=0;y<h;y++)for(x=0;x<w;x++)p[y*32+x]=q[y*32+x];
}

void func_02080a6c(u16 *p, s32 totalW, s32 totalH, s32 chunkW, u16 bandH, u16 lowArg, u16 palArg) {
    u16 cur = (u16)((lowArg & 0x3ff) | ((palArg & 0xf) << 12));
    s32 r5 = 0;
    s32 stack = 0;
    if (totalH <= 0) return;
    if (totalW <= 0) return;
    while (r5 < totalH) {
        stack = 0;
        do {
            s32 r7 = 0;
            if (bandH > 0) {
                do {
                    u16 *rowBase = p + stack + (r5 + r7) * 32;
                    s32 r6 = 0;
                    if (chunkW > 0) {
                        do {
                            rowBase[r6] = cur++;
                            r6++;
                        } while (r6 < chunkW);
                    }
                    r7++;
                } while (r7 < bandH);
            }
            stack += chunkW;
        } while (stack < totalW);
        r5 += bandH;
    }
}

void func_02080b38(u16 *p,u32 w,s32 h){
 s32 y,x;u16 *a,*b;u32 tmp;
 for(y=0;y<h;y++){
 for(x=0;x<(s32)(w>>1);x++){a=p+x;b=p+(w-1-x);tmp=a[y*32];a[y*32]=b[y*32];b[y*32]=tmp;}
 for(x=0;x<(s32)w;x++)p[y*32+x]^=0x400;
 }
}

void func_02080bd4(void) {
    M2C_UNK func_0200b74c(M2C_UNK);
    s32 func_0200beec(s32, s32);
    s32 func_020e34bc();
    s32 temp_r4;

    func_0200b74c(-1);
    temp_r4 = func_0200beec(0, 0);
    func_0200beec(func_020e34bc(), temp_r4);
}

s32 func_02080c00(void *a) {
 void func_0200b774(void *);s32 func_0200ba54(void *,void *);void func_0200ba9c(void *);
 s32 buf[18];s32 n;
 func_0200b774(buf);
 if(!func_0200ba54(buf,a))return 0;
 n=buf[10]-buf[9];func_0200ba9c(buf);return n;
}

int func_02080c50(int arg0, int arg1) {
    void *sp0[18];
    int var_7;
    int var_8;
    int var_9;

    func_0200b774(sp0);
    if (func_0200ba54(sp0, arg0) == 0) {
        func_02007958();
        return 0;
    }
    var_8 = (int)sp0[10] - (int)sp0[9];
    var_7 = 0;
    if (var_8 != 0) {
        do {
            var_9 = var_8 - var_7;
            if (!(var_9 < 0x2800)) {
                var_9 = 0x2800;
            }
            if (func_0200bbe0(sp0, arg1 + var_7, var_9) != var_9) {
                func_02007958();
                return 0;
            }
            var_7 += var_9;
        } while (var_8 - var_7 != 0);
    }
    func_0200ba9c(sp0);
    return var_8;
}

void *func_02080e30(void *arg0, int arg1) {
    void *sp0[18];
    int off;
    int total;
    void *buf;
    int chunk;
    int a;
    int b;

    func_0200b774(sp0);
    if (func_0200ba54(sp0, arg0) == 0) {
        func_02007958();
        return 0;
    }
    b = (int)sp0[10];
    a = (int)sp0[9];
    total = b - a;
    if (arg1 != 0) {
        buf = (void *)func_020e34bc(total);
    } else {
        buf = (void *)func_020e34f4(total);
    }
    off = 0;
    if (total != 0) {
        do {
            chunk = total - off;
            if ((unsigned int)chunk >= 0x2800) {
                chunk = 0x2800;
            }
            if (func_0200bbe0(sp0, (void *)((char *)buf + off), chunk) != chunk) {
                func_02007958();
                return 0;
            }
            off += chunk;
        } while (total - off != 0);
    }
    func_0200ba9c(sp0);
    return buf;
}

void func_02081070(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_02080efc(M2C_UNK, M2C_UNK, M2C_UNK);
    func_02080efc(arg0, arg1, 0);
}

int func_02081080(int arg0, int arg1, int arg2, int arg3) {
    void *sp0[18];

    func_0200b774(sp0);
    if (func_0200ba54(sp0, arg0) == 0) {
        func_02007958();
        return 0;
    }
    if (func_0200bbf0(sp0, arg2, 0) == 0) {
        func_02007958();
        return 0;
    }
    if (func_0200bbe0(sp0, arg1, arg3) != arg3) {
        func_02007958();
        return 0;
    }
    func_0200ba9c(sp0);
    return 1;
}

s32 func_02081128(M2C_UNK a,M2C_UNK b) {
 s32 func_02081080(M2C_UNK,s32,M2C_UNK,M2C_UNK);s32 func_020e34f4(M2C_UNK);
 s32 p=func_020e34f4(b);
 if(func_02081080(a,p,0,b))return p;
 func_020e35cc(p);return 0;
}

s32 func_0208116c(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    s32 func_02081080(M2C_UNK, s32, M2C_UNK, M2C_UNK);
    extern void *gCur3DSpriteEngine;
    if (func_02081080(arg0, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x30) + arg1, 0, arg2) == 0) {
        return 0;
    }
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8) (M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 0x10);
    return 1;
}

s32 func_020811b8(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
 M2C_UNK func_0200478c(void); M2C_UNK func_0200482c(s32,s32,s32); M2C_UNK func_0200489c(void);
 M2C_UNK func_020049dc(void); M2C_UNK func_020049f4(s32,s32,s32); M2C_UNK func_02004a58(void);
 extern void *gCur3DSpriteEngine; extern void *data_027e00c8;
 s32 temp_r0; s32 var_r0;
 temp_r0=func_02081128(arg0,arg3);
 if(temp_r0==0) return 0;
 func_020067e0(temp_r0,arg3);
 if(gCur3DSpriteEngine==data_027e00c8) var_r0=1; else var_r0=0;
 if(var_r0 & 0xFF) {func_0200478c();func_0200482c(temp_r0,arg2+(arg1<<13),arg3);func_0200489c();}
 else {func_020049dc();func_020049f4(temp_r0,arg2+(arg1<<13),arg3);func_02004a58();}
 func_020e35cc(temp_r0); return 1;
}

s32 func_02081254(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_UNK func_0207c650(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    s32 func_02081128(M2C_UNK, M2C_UNK);
    s32 temp_r0;

    temp_r0 = func_02081128(arg0, arg3);
    if (temp_r0 == 0) {
        return 0;
    }
    func_0207c650(temp_r0, arg1, arg2, arg3, 1);
    return 1;
}

s32 func_020812a4(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3) {
 M2C_UNK func_020048e4(void); M2C_UNK func_0200492c(s32,s32,s32); M2C_UNK func_02004998(void);
 M2C_UNK func_02004a98(void); M2C_UNK func_02004ab0(s32,s32,s32); M2C_UNK func_02004b14(void);
 extern void *gCur3DSpriteEngine; extern void *data_027e00c8;
 s32 temp_r0; s32 var_r0;
 temp_r0=func_02081128(arg0,arg3);
 if(temp_r0==0) return 0;
 func_020067e0(temp_r0,arg3);
 if(gCur3DSpriteEngine==data_027e00c8) var_r0=1; else var_r0=0;
 if(var_r0 & 0xFF) {func_020048e4();func_0200492c(temp_r0,arg2+(arg1<<13),arg3);func_02004998();}
 else {func_02004a98();func_02004ab0(temp_r0,arg2+(arg1<<13),arg3);func_02004b14();}
 func_020e35cc(temp_r0); return 1;
}

s32 func_02081340(M2C_UNK a,s32 b,M2C_UNK c,M2C_UNK d) {
 extern void *gCur3DSpriteEngine;
 if(!func_02081080(a,M2C_FIELD(gCur3DSpriteEngine,s32 *,0x30)+b,c,d))return 0;
 M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=0x10;
 return 1;
}

s32 func_02081384(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_0207da34(s32, M2C_UNK, s32);
    M2C_UNK func_020e35cc(s32);
    s32 sp0;
    s32 temp_r0;

    temp_r0 = func_02080efc(arg0, 0, &sp0);
    func_020067e0(temp_r0, sp0);
    func_0207da34(temp_r0, arg1, sp0);
    func_020e35cc(temp_r0);
    return sp0;
}

s32 func_020813c4(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_020067e0(s32, s32);
    M2C_UNK func_0207c464(s32, M2C_UNK, s32, M2C_UNK);
    s32 sp0;
    s32 temp_r0;

    temp_r0 = func_02080efc(arg0, 0, &sp0);
    func_020067e0(temp_r0, sp0);
    func_0207c464(temp_r0, arg1, sp0, 1);
    return sp0;
}

