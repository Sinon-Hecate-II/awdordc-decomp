/* 17 functions from 0x02169020 to 0x02169E3C (ov001), found by ds-decomp. */
#include "common.h"
extern u8 data_ov001_0218c9e4[4][4][2];
typedef struct { s32 x, y; } FontSize;

void *func_ov001_02169020(void *a,s32 b){u16 n,i;void *p; p=a+M2C_FIELD(a,u16 *,12);n=M2C_FIELD(a,u16 *,14);i=0;for(;i<n;i++){if(M2C_FIELD(p,s32 *,0)==b)return p;p+=M2C_FIELD(p,s32 *,4);}return 0;}

s32 func_ov001_02169068(void *a, u32 b) {
    u16 r = 0xffff;
    switch (M2C_FIELD(a, u16 *, 4)) {
    case 0:
        r = (u16)(M2C_FIELD(a, u16 *, 12) + (b - M2C_FIELD(a, u16 *, 0)));
        break;
    case 1:
        r = M2C_FIELD((u8 *)a + 12 + (b - M2C_FIELD(a, u16 *, 0)) * 2, u16 *, 0);
        break;
    case 2: {
        u8 *lo = (u8 *)a + 14;
        u8 *hi = lo + (M2C_FIELD(a, u16 *, 12) - 1) * 4;
        while (lo <= hi) {
            u8 *mid = lo + (hi - lo) / 4 / 2 * 4;
            u16 k = M2C_FIELD(mid, s16 *, 0);
            if (k < b) {
                lo = mid + 4;
            } else if (b < k) {
                hi = mid - 4;
            } else {
                r = M2C_FIELD(mid, u16 *, 2);
                break;
            }
        }
        break;
    }
    }
    return r;
}

void func_ov001_02169130(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_ov001_0216aab0(M2C_UNK, void *);
    extern M2C_UNK func_ov001_0216ad40;
    func_ov001_0216aab0(arg1, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 4) = &func_ov001_0216ad40;
}

s32 func_ov001_02169154(void **a,u32 b){s32 func_ov001_02169068(void *,u32);void *p=M2C_FIELD(*a,void **,16);while(p){if(M2C_FIELD(p,u16 *,0)<=b && b<=M2C_FIELD(p,u16 *,2))return func_ov001_02169068(p,b);p=M2C_FIELD(p,void **,8);}return 65535;}

void *func_ov001_0216919c(void **a,u32 b){void *p;void *base; base=*a;p=M2C_FIELD(base,void **,12);while(p){u16 lo=M2C_FIELD(p,u16 *,0);if(lo<=b && b<=M2C_FIELD(p,u16 *,2))return p+8+(b-lo)*3;p=M2C_FIELD(p,void **,4);}return base+4;}

s32 func_ov001_021691e8(void *a,s32 b,s32 arg2,s32 *d){s32 c=arg2;s32 width,ch,id;s32 (*f)(s32 *);f=M2C_FIELD(a,s32 (**)(s32 *),4);width=0;ch=f(&c);if(ch){do{if(ch==10)break;id=func_ov001_02169154(a,ch);if(id==65535)id=M2C_FIELD(M2C_FIELD(a,void **,0),u16 *,2);width+=b+M2C_FIELD(func_ov001_0216919c(a,id),s8 *,2);ch=f(&c);}while(ch);}if(d)*d=ch==10?c:0;if(width>0)width-=b;return width;}

s32 func_ov001_02169294(void *a,s32 b,s32 arg2){s32 c=arg2;s32 z[2]={0,0};s32 n,ch;s32 (*f)(s32 *);f=M2C_FIELD(a,s32 (**)(s32 *),4);n=1;ch=f(&c);while(ch){if(ch==10)n++;ch=f(&c);}return n*(b+M2C_FIELD(M2C_FIELD(a,void **,0),s8 *,1))-b;}

void func_ov001_02169308(FontSize *out,void **a,s32 b,s32 c,s32 d){FontSize v={0,0};s32 n=1,w;while(d){w=func_ov001_021691e8(a,b,d,&d);if(w>v.x)v.x=w;n++;}v.y=(n-1)*(c+M2C_FIELD(*a,s8 *,1))-c;*out=v;}

#pragma intrinsic on
u32 func_ov001_0216939c(u32 x,u32 y,s32 w,s32 h,s32 sx,s32 sy){
u32 n=0,a,b; s32 ix,iy;
for(;;){
a=h&(~0u<<sy);b=w&(~0u<<sx);
if(a<=y){
n+=w*a;
if(b<=x){h-=a;n+=b*h;x-=b;y-=a;w-=b;}
else {w=b;y-=a;h-=a;}
}else {
if(b<=x){n+=b*a;h=a;x-=b;w-=b;}
else {
n+=b*(y&(~0u<<sy));
n+=(x&(~0u<<sx))<<sy;
n+=(y&~(~0u<<sy))<<sx;
return n+(x&~(~0u<<sx));
}
}
ix=w>=8?3:31-__CLZ(w);
iy=h>=8?3:31-__CLZ(h);
sx=data_ov001_0218c9e4[iy][ix][0];sy=data_ov001_0218c9e4[iy][ix][1];
}
}
s32 func_ov001_02169494(u8 *a){extern s32 data_ov001_0218ca04[4][4];return data_ov001_0218ca04[a[1]][a[0]];}

void func_ov001_021694b0(u32 *dst, s32 shift, s32 start, s32 w, s32 h, u32 color, s32 bpp) {
    M2C_UNK func_02007e98(s32, s32, s32);
    u64 mask;
    u32 lo, hi, v0, v1, n0, n1;
    u32 *p;
    u32 *end;

    if (w == 8 && h == 8) {
        func_02007e98((s32) color, (s32) dst, bpp * 8);
        return;
    }
    if (bpp == 4) {
        mask = (~0ull >> (64 - (shift * 4 + w * 4))) << (shift * 4);
        lo = (u32) mask;
        v0 = color & lo;
        n0 = ~lo;
        p = dst + start;
        end = p + h;
        if (p >= end) {
            return;
        }
        do {
            *p = (*p & n0) | v0;
            p++;
        } while (p < end);
        return;
    }
    mask = (~0ull >> (64 - (shift * 8 + w * 8))) << (shift * 8);
    lo = (u32) mask;
    hi = (u32) (mask >> 32);
    v0 = color & lo;
    v1 = color & hi;
    n0 = ~lo;
    n1 = ~hi;
    p = dst + start * 2;
    end = p + h * 2;
    if (p >= end) {
        return;
    }
    do {
        p[0] = (p[0] & n0) | v0;
        p[1] = (p[1] & n1) | v1;
        p += 2;
    } while (p < end);
}

void func_ov001_02169bd0(void *a,s32 b){M2C_UNK func_02007e98(s32,s32,s32);s32 bits=M2C_FIELD(a,u8 *,12);u32 v; if(bits==4) {u32 t=b|b<<4;v=t|t<<8;}else{v=(u32)b|((u32)b<<8);}func_02007e98(v|v<<16,M2C_FIELD(a,s32 *,0),(M2C_FIELD(a,s32 *,4)*M2C_FIELD(a,s32 *,8))*((bits*64)/8));}

void func_ov001_02169c20(void *arg0,s32 arg1){M2C_UNK func_02007e98(s32,s32,s32);register s32 width;register s32 stride;register s32 p;register s32 i;register void *a;register s32 v;s32 bits,t,size;a=arg0;v=arg1;bits=M2C_FIELD(a,u8 *,12);p=M2C_FIELD(a,s32 *,0);if(bits==4){t=v|(v<<4);t|=t<<8;}else t=v|(v<<8);v=t|(t<<16);size=(bits<<6)/8;stride=size*M2C_FIELD(a,s32 *,16);width=size*M2C_FIELD(a,s32 *,4);i=0;if(M2C_FIELD(a,s32 *,8)<=0)return;do{func_02007e98(v,p,width);i++;p+=stride;}while(i<M2C_FIELD(a,s32 *,8));}

