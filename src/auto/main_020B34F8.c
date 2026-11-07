/* 12 functions from 0x020B34F8 to 0x020B4264 (main), found by ds-decomp. */
#include "common.h"
extern void **gCurrentMap;
extern u16 data_0215d9b8[];
extern u8 data_02168f14[];
extern u8 *data_02168f08;
typedef struct { u8 a[33],b;u16 c,d,e; s16 f,g,h,i;u16 j,k;u8 l,m,n,o,p,q,r,s;u8 t[2],u[2];u8 v[322]; } SettingsB3C;
typedef struct {u16 a;u8 b,c;u16 d,e;u32 f,g;} HeaderB3C;
typedef struct {u32 a,b,c,d;u8 e[10];u16 f;u8 g[4];u16 h,i;s8 j;u8 k,l,m,n,o,p,q,r,s,t,u,v,w,z;u8 aa[27],bb[27];u32 cc,dd;u32 ee[4];u32 ff,gg;} PlayerB3C;
typedef struct {u8 a,b,c;u16 d,e,f;u8 g,h;u8 i[2];} UnitB3C;
typedef struct {u8 a,b;u16 c;u8 d,e;s8 f,g;} RecordB3C;
typedef struct {u8 a[33];} Bytes33B3C;
typedef struct {u8 a[322];} Bytes322B3C;
typedef struct {u8 a[27];} Bytes27B3C;
typedef struct {u8 a[2];} Bytes2B3C;
typedef struct {u32 a[4];} Words4B3C;

u8 func_020b34f8(void *arg0) {
    s32 func_0207c8ec();
    M2C_UNK func_0208fe30(s32);
    s32 active, i, factor, delta;
    s16 old, n;
    u8 step, result;
    s32 limit;

    if (M2C_FIELD(arg0, s16 *, 0x12) != 0) {
        active = 1;
    } else {
        active = 0;
    }
    if (active & 0xFF) {
        return 0U;
    }
    step = M2C_FIELD(arg0, u8 *, 0x5);
    limit = M2C_FIELD(arg0, u8 *, 0x4);
    n = func_0207c8ec(M2C_FIELD(arg0, s16 *, 0xA) + step - 1, step);
    n = (old = M2C_FIELD(arg0, volatile s16 *, 0xC), limit >= n ? n : limit);
    for (i = 0; i < n; i++) {
        if (M2C_FIELD(arg0, s16 *, 0xC) != 0) {
            M2C_FIELD(arg0, s16 *, 0xC) -= 1;
        }
        if (M2C_FIELD(arg0, s16 *, 0x8) - step >= 0) {
            M2C_FIELD(arg0, s16 *, 0x8) -= step;
        }
    }
    if (old != M2C_FIELD(arg0, s16 *, 0xC)) {
        func_0208fe30(0x10019);
    }
    delta = M2C_FIELD(arg0, s16 *, 0xC);
    factor = M2C_FIELD(arg0, u8 *, 0x7);
    delta -= old;
    M2C_FIELD(arg0, s16 *, 0x12) = (s16)(delta * factor);
    if (M2C_FIELD(arg0, s16 *, 0x12) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

#pragma opt_propagation off
void func_020b35d4(void *p) {
s32 func_0207c8ec(s32,s32);
s32 func_0207c928(s32,s32);
u8 func_020b3410(void *);
M2C_UNK func_0208fe30(s32);
extern u16 *data_02101e84;

s32 held,pressed;
s32 cols;
s16 col,row,oldselected;
s16 oldscroll,pages,total;
s32 visible;
s32 n,active,delta,factor;
cols=M2C_FIELD(p,u8 *,5);
total=M2C_FIELD(p,s16 *,10);
visible=M2C_FIELD(p,u8 *,4);
pages=func_0207c8ec(total+cols-1,cols);
if(visible>=pages)visible=pages;
visible=(s16)visible;
col=func_0207c928(M2C_FIELD(p,s16 *,8),cols);
row=func_0207c8ec(M2C_FIELD(p,s16 *,8),cols);
held=data_02101e84[0];pressed=data_02101e84[1];
oldscroll=M2C_FIELD(p,s16 *,12);
oldselected=M2C_FIELD(p,s16 *,8);
if(cols>1){
n=total-row*cols;if(n>cols)n=cols;
if(pressed&32){
if(col>0)M2C_FIELD(p,s16 *,8)--;
else if(pressed==held)M2C_FIELD(p,s16 *,8)+=n-1;
}else if(pressed&16){
if(col<n-1)M2C_FIELD(p,s16 *,8)++;
else if(pressed==held)M2C_FIELD(p,s16 *,8)-=n-1;
}
}else{
if(pressed&32){if(func_020b34f8(p))return;}
else if(pressed&16){if(func_020b3410(p))return;}
}
active=M2C_FIELD(p,s16 *,18)!=0;
if(!(active&255)){
if(pressed&64){
if(row==0){
if(pressed==held){
M2C_FIELD(p,s16 *,8)+=(pages-1)*cols;
n=pages-visible;if(n<=0)n=0;
M2C_FIELD(p,s16 *,12)=n;
n=M2C_FIELD(p,s16 *,8);
if(n>total-1)n=total-1;
M2C_FIELD(p,s16 *,8)=n;
}
}else{
M2C_FIELD(p,s16 *,8)-=cols;
n=M2C_FIELD(p,s16 *,12);
if((s16)func_0207c8ec(M2C_FIELD(p,s16 *,8),cols)-n<=0){
if(n>0)M2C_FIELD(p,s16 *,12)--;
delta=M2C_FIELD(p,s16 *,12);factor=M2C_FIELD(p,u8 *,7);delta-=oldscroll;
M2C_FIELD(p,s16 *,18)=delta*factor;
}
}
}else if(pressed&128){
if(row==pages-1){
if(pressed==held){M2C_FIELD(p,s16 *,8)-=(pages-1)*cols;M2C_FIELD(p,s16 *,12)=0;}
}else{
M2C_FIELD(p,s16 *,8)+=cols;
n=M2C_FIELD(p,s16 *,8);
if(n>total-1)n=total-1;
M2C_FIELD(p,s16 *,8)=n;
row=func_0207c8ec(M2C_FIELD(p,s16 *,8),cols);
n=M2C_FIELD(p,s16 *,12);
if(row-n>=visible-1){
if(n<pages-visible)M2C_FIELD(p,s16 *,12)=n+1;
delta=M2C_FIELD(p,s16 *,12);factor=M2C_FIELD(p,u8 *,7);delta-=oldscroll;
M2C_FIELD(p,s16 *,18)=delta*factor;
}
}
}
}
if(oldscroll!=M2C_FIELD(p,s16 *,12)||oldselected!=M2C_FIELD(p,s16 *,8))func_0208fe30(0x10019);
}
#pragma opt_propagation reset
M2C_UNK func_020b38d0(M2C_UNK arg0) {
    M2C_UNK func_020b3038(M2C_UNK);
    M2C_UNK func_0208fe30(M2C_UNK);
    u8 var_r2;
    u8 var_r0;
    s8 var_r1;
    s16 var_r4;
    s16 var_r5;
    s16 prod;
    s16 newval;

    if (M2C_FIELD(arg0, s16 *, 0x12) != 0)
        return 1;
    var_r2 = M2C_FIELD(arg0, u8 *, 0x5);
    var_r0 = M2C_FIELD(arg0, u8 *, 0x4);
    var_r1 = M2C_FIELD(arg0, s8 *, 0x24);
    var_r4 = M2C_FIELD(arg0, s16 *, 0xc);
    prod = (s16)(var_r0 * var_r2);
    var_r5 = M2C_FIELD(arg0, s16 *, 0x8);
    if (var_r1 < 0)
        return prod;
    if (prod <= var_r1)
        return prod;
    newval = (s16)(var_r2 * var_r4 + var_r1);
    if (newval == var_r5)
        return newval;
    func_020b3038(arg0);
    if (var_r4 == M2C_FIELD(arg0, s16 *, 0xc) && var_r5 == M2C_FIELD(arg0, s16 *, 0x8))
        return M2C_FIELD(arg0, s16 *, 0x8);
    return func_0208fe30(0x10019);
}

/* Returns whether tile column x is currently visible in the camera viewport. */
u8 func_020b3960(void *camera, int x) {
int func_0207c8ec(int,int);
u8 visibleTiles, tileSize; s16 total, scroll, tile; int tileCount;
visibleTiles=M2C_FIELD(camera,u8*,4); tileSize=M2C_FIELD(camera,u8*,5); total=M2C_FIELD(camera,s16*,10);
tileCount=(s16)func_0207c8ec(total+tileSize-1,tileSize);
if(x<0 || total<=x)return 0;
scroll=M2C_FIELD(camera,s16*,12);
tile=func_0207c8ec(x,tileSize);
if(tileCount>visibleTiles)tileCount=visibleTiles;
total=tileCount;
if(M2C_FIELD(camera,s16*,18)>0) {scroll-= (s16)func_0207c8ec(M2C_FIELD(camera,s16*,18)+(M2C_FIELD(camera,u8*,7)-1),M2C_FIELD(camera,u8*,7)); total++;}
else if(M2C_FIELD(camera,s16*,18)<0) {scroll-=(s16)func_0207c8ec(M2C_FIELD(camera,s16*,18),M2C_FIELD(camera,u8*,7)); total++;}
return scroll<=tile && tile<scroll+total;
}

void func_020b3a58(M2C_UNK arg0) {
    M2C_UNK func_02088044(M2C_UNK);
    M2C_UNK func_020b316c();
    M2C_UNK func_020b38d0(M2C_UNK);
    func_020b316c();
    func_02088044(arg0 + 0x18);
    func_020b35d4(arg0);
    func_020b38d0(arg0);
}

void func_020b3a80(void *arg0) {
s32 func_0207c8ec();
s32 func_0207c928(s32,s32);
s16 a,b; s16 x,y,c,old; s16 delta; s32 d,e;
a=M2C_FIELD(arg0,u8 *,6); b=M2C_FIELD(arg0,u8 *,7);
x=func_0207c928(M2C_FIELD(arg0,s16 *,8),M2C_FIELD(arg0,u8 *,5));
c=M2C_FIELD(arg0,s16 *,12);
delta=func_0207c8ec(M2C_FIELD(arg0,s16 *,8),M2C_FIELD(arg0,u8 *,5))-c;
x=(s16)(M2C_FIELD(arg0,s16 *,20)+x*a);
y=(s16)(M2C_FIELD(arg0,s16 *,22)+delta*b);
old=M2C_FIELD(arg0,s16 *,14);
if ((old==-32768 && M2C_FIELD(arg0,s16 *,16)==-32768) || (((d=old-x)<0?-d:d)<=1 && ((e=M2C_FIELD(arg0,s16 *,16)-y)<0?-e:e)<=1)) {
M2C_FIELD(arg0,s16 *,14)=x; M2C_FIELD(arg0,s16 *,16)=y;
} else {
M2C_FIELD(arg0,s16 *,14)=(x+old+1)>>1;
M2C_FIELD(arg0,s16 *,16)=(y+M2C_FIELD(arg0,s16 *,16)+1)>>1;
}
}

void *func_020b3b4c(void *arg0) {
    M2C_UNK func_02082040(void *);
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x2C));
    func_02082040(arg0);
    return arg0;
}

void *func_020b3b6c(void *arg0) {
    M2C_UNK func_020e35cc(s32);
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x2C));
    return arg0;
}

void func_020b3b84(void) {
    M2C_UNK func_02086810(u16, M2C_UNK);
    u16 func_020a8aac(u16, s32);
    M2C_UNK func_020bef44();
    s32 func_020befd8();
    s32 func_020bf084(s32);
    M2C_UNK func_020bf0dc(M2C_UNK, s32);
    M2C_UNK func_020bf798();
    s32 func_020cd6d4();
    M2C_UNK func_020e4870();
    extern void **gCurrentMap;
    s32 temp_r0;
    s32 var_r6;
    u16 temp_r0_2;

    temp_r0 = func_020befd8();
    if (temp_r0 != 0) {
        func_020bef44();
        if (func_020bf084(temp_r0) == 0) {
            func_020bf0dc(0, temp_r0);
            func_020e4870();
        }
    }
    if (func_020cd6d4() != 0) {
        var_r6 = 0;
        do {
            temp_r0_2 = func_020a8aac(M2C_FIELD(*gCurrentMap, u16 *, 0x5142), var_r6);
            if (temp_r0_2 != 0) {
                func_02086810(temp_r0_2, 1);
            }
            var_r6 += 1;
        } while (var_r6 < 4);
        func_02086810(M2C_FIELD(*gCurrentMap, u16 *, 0x5142), 1);
    }
    func_020bf798();
}

void func_020b3c2c(M2C_UNK arg0) {
    M2C_UNK func_01ffa42c(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021286ac;
    func_01ffa42c(&data_021286ac, arg0);
}

void func_020b3c44(void) {

}

#pragma opt_strength_reduction off
void func_020b3c48(void *p) {
void func_020cfa58(s32);void func_020cfb54(void);void func_020a1720(void *);
u8 *map,*src;void *dst; s32 n,x,y,i,j,unitStart,saveStart,off;u16 tile,old;
src=(u8 *)*gCurrentMap+0x52c2;
M2C_FIELD(p,s16*,0x18)=M2C_FIELD(src,s16*,0);
M2C_FIELD(p,s16*,0x1a)=M2C_FIELD(src,s16*,2);
M2C_FIELD(p,u16*,0x16)=M2C_FIELD(*gCurrentMap,u16*,0x52a2);
M2C_FIELD(p,u16*,0x14)=M2C_FIELD(*gCurrentMap,u16*,0x52a4);
M2C_FIELD(p,u8*,0x125b)=((u32)data_0215d9b8[3]<<22)>>29;
src=(u8 *)*gCurrentMap+0x5120;dst=(u8 *)p+0x2c;
M2C_FIELD(dst,Bytes33B3C*,0)=M2C_FIELD(src,Bytes33B3C*,0);
M2C_FIELD(dst,u8*,33)=M2C_FIELD(src,u8*,33);
M2C_FIELD(dst,u16*,34)=M2C_FIELD(src,u16*,34);
M2C_FIELD(dst,u16*,36)=M2C_FIELD(src,u16*,36);
M2C_FIELD(dst,u16*,38)=M2C_FIELD(src,u16*,38);
M2C_FIELD(dst,s16*,40)=M2C_FIELD(src,s16*,40);
M2C_FIELD(dst,s16*,42)=M2C_FIELD(src,s16*,42);
M2C_FIELD(dst,s16*,44)=M2C_FIELD(src,s16*,44);
M2C_FIELD(dst,s16*,46)=M2C_FIELD(src,s16*,46);
M2C_FIELD(dst,u16*,48)=M2C_FIELD(src,u16*,48);
M2C_FIELD(dst,u16*,50)=M2C_FIELD(src,u16*,50);
M2C_FIELD(dst,u8*,52)=M2C_FIELD(src,u8*,52);
M2C_FIELD(dst,u8*,53)=M2C_FIELD(src,u8*,53);
M2C_FIELD(dst,u8*,54)=M2C_FIELD(src,u8*,54);
M2C_FIELD(dst,u8*,55)=M2C_FIELD(src,u8*,55);
M2C_FIELD(dst,u8*,56)=M2C_FIELD(src,u8*,56);
M2C_FIELD(dst,u8*,57)=M2C_FIELD(src,u8*,57);
M2C_FIELD(dst,u8*,58)=M2C_FIELD(src,u8*,58);
M2C_FIELD(dst,u8*,59)=M2C_FIELD(src,u8*,59);
M2C_FIELD(dst,Bytes2B3C*,60)=M2C_FIELD(src,Bytes2B3C*,60);
M2C_FIELD(dst,Bytes2B3C*,62)=M2C_FIELD(src,Bytes2B3C*,62);
M2C_FIELD(dst,Bytes322B3C*,64)=M2C_FIELD(src,Bytes322B3C*,64);

src=data_02168f14;dst=(u8 *)p+0x1c;
M2C_FIELD(dst,u16*,0)=M2C_FIELD(src,u16*,0);
M2C_FIELD(dst,u8*,2)=M2C_FIELD(src,u8*,2);
M2C_FIELD(dst,u8*,3)=M2C_FIELD(src,u8*,3);
M2C_FIELD(dst,u16*,4)=M2C_FIELD(src,u16*,4);
M2C_FIELD(dst,u16*,6)=M2C_FIELD(src,u16*,6);
M2C_FIELD(dst,u32*,8)=M2C_FIELD(src,u32*,8);
M2C_FIELD(dst,u32*,12)=M2C_FIELD(src,u32*,12);

func_020cfa58(M2C_FIELD(*gCurrentMap,u16*,0x5142));
n=0;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16*,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16*,0x5144);x++){
map=*gCurrentMap;
i=x+M2C_FIELD(map+y*2,u16*,0x3758);
tile=M2C_FIELD(map+i*2,u16*,0xa10);
old=M2C_FIELD(data_02168f08+i*2,u16*,2);
if(tile!=old && (M2C_FIELD(map+old,u8*,0x6a60)&31)!=27){
M2C_FIELD((u8 *)p+n*4,u16*,0xf0a)=tile;
M2C_FIELD((u8 *)p+n*4,u8*,0xf08)=x;
M2C_FIELD((u8 *)p+n*4,u8*,0xf09)=y;n++;
}
}
}
if(n<99)M2C_FIELD((u8 *)p+n*4,u16*,0xf0a)=0xffff;
func_020cfb54();
dst=p;
for(i=0;i<4;i++){
src=(u8 *)*gCurrentMap+0x67a4+(i+1)*140;
M2C_FIELD(dst,u32*,432)=M2C_FIELD(src,u32*,0);
M2C_FIELD(dst,u32*,436)=M2C_FIELD(src,u32*,4);
M2C_FIELD(dst,u32*,440)=M2C_FIELD(src,u32*,8);
M2C_FIELD(dst,u32*,444)=M2C_FIELD(src,u32*,12);
M2C_FIELD(dst,u8*,448)=M2C_FIELD(src,u8*,16);
M2C_FIELD(dst,u8*,449)=M2C_FIELD(src,u8*,17);
M2C_FIELD(dst,u8*,450)=M2C_FIELD(src,u8*,18);
M2C_FIELD(dst,u8*,451)=M2C_FIELD(src,u8*,19);
M2C_FIELD(dst,u8*,452)=M2C_FIELD(src,u8*,20);
M2C_FIELD(dst,u8*,453)=M2C_FIELD(src,u8*,21);
M2C_FIELD(dst,u8*,454)=M2C_FIELD(src,u8*,22);
M2C_FIELD(dst,u8*,455)=M2C_FIELD(src,u8*,23);
M2C_FIELD(dst,u8*,456)=M2C_FIELD(src,u8*,24);
M2C_FIELD(dst,u8*,457)=M2C_FIELD(src,u8*,25);
M2C_FIELD(dst,u16*,458)=M2C_FIELD(src,u16*,26);
M2C_FIELD(dst,u8*,460)=M2C_FIELD(src,u8*,28);
M2C_FIELD(dst,u8*,461)=M2C_FIELD(src,u8*,29);
M2C_FIELD(dst,u8*,462)=M2C_FIELD(src,u8*,30);
M2C_FIELD(dst,u8*,463)=M2C_FIELD(src,u8*,31);
M2C_FIELD(dst,u16*,464)=M2C_FIELD(src,u16*,32);
M2C_FIELD(dst,u16*,466)=M2C_FIELD(src,u16*,34);
M2C_FIELD(dst,s8*,468)=M2C_FIELD(src,s8*,36);
M2C_FIELD(dst,u8*,469)=M2C_FIELD(src,u8*,37);
M2C_FIELD(dst,u8*,470)=M2C_FIELD(src,u8*,38);
M2C_FIELD(dst,u8*,471)=M2C_FIELD(src,u8*,39);
M2C_FIELD(dst,u8*,472)=M2C_FIELD(src,u8*,40);
M2C_FIELD(dst,u8*,473)=M2C_FIELD(src,u8*,41);
M2C_FIELD(dst,u8*,474)=M2C_FIELD(src,u8*,42);
M2C_FIELD(dst,u8*,475)=M2C_FIELD(src,u8*,43);
M2C_FIELD(dst,u8*,476)=M2C_FIELD(src,u8*,44);
M2C_FIELD(dst,u8*,477)=M2C_FIELD(src,u8*,45);
M2C_FIELD(dst,u8*,478)=M2C_FIELD(src,u8*,46);
M2C_FIELD(dst,u8*,479)=M2C_FIELD(src,u8*,47);
M2C_FIELD(dst,u8*,480)=M2C_FIELD(src,u8*,48);
M2C_FIELD(dst,u8*,481)=M2C_FIELD(src,u8*,49);
M2C_FIELD(dst,u8*,482)=M2C_FIELD(src,u8*,50);
M2C_FIELD(dst,Bytes27B3C*,483)=M2C_FIELD(src,Bytes27B3C*,51);
M2C_FIELD(dst,Bytes27B3C*,510)=M2C_FIELD(src,Bytes27B3C*,78);
{u32 a=M2C_FIELD(src,u32*,108),b=M2C_FIELD(src,u32*,112);M2C_FIELD(dst,u32*,540)=a;M2C_FIELD(dst,u32*,544)=b;}
M2C_FIELD(dst,Words4B3C*,548)=M2C_FIELD(src,Words4B3C*,116);
M2C_FIELD(dst,u32*,564)=M2C_FIELD(src,u32*,132);
M2C_FIELD(dst,u32*,568)=M2C_FIELD(src,u32*,136);
dst+=140;

}
saveStart=unitStart=0;
for(i=0;i<4;i++){
dst=(u8 *)p+saveStart*14;
for(j=0;j<51;j++){
src=(u8 *)*gCurrentMap+0x59a4+(j+unitStart)*14;
M2C_FIELD(dst,u8*,992)=M2C_FIELD(src,u8*,0);
M2C_FIELD(dst,u8*,993)=M2C_FIELD(src,u8*,1);
M2C_FIELD(dst,u8*,994)=M2C_FIELD(src,u8*,2);
M2C_FIELD(dst,u16*,996)=M2C_FIELD(src,u16*,4);
M2C_FIELD(dst,u16*,998)=M2C_FIELD(src,u16*,6);
M2C_FIELD(dst,u16*,1000)=M2C_FIELD(src,u16*,8);
M2C_FIELD(dst,u8*,1002)=M2C_FIELD(src,u8*,10);
M2C_FIELD(dst,u8*,1003)=M2C_FIELD(src,u8*,11);
M2C_FIELD(dst,Bytes2B3C*,1004)=M2C_FIELD(src,Bytes2B3C*,12);
dst+=14;
}
unitStart+=64;saveStart+=51;
}
i=0;
for(off=0;i<32;i++){
src=(u8 *)*gCurrentMap+0x58a4+off;dst=(u8 *)p+i*8;
M2C_FIELD(dst,u8*,4244)=M2C_FIELD(src,u8*,0);
M2C_FIELD(dst,u8*,4245)=M2C_FIELD(src,u8*,1);
M2C_FIELD(dst,u16*,4246)=M2C_FIELD(src,u16*,2);
M2C_FIELD(dst,u8*,4248)=M2C_FIELD(src,u8*,4);
M2C_FIELD(dst,u8*,4249)=M2C_FIELD(src,u8*,5);
M2C_FIELD(dst,s8*,4250)=M2C_FIELD(src,s8*,6);
M2C_FIELD(dst,s8*,4251)=M2C_FIELD(src,s8*,7);
off+=8;
}
func_020a1720((u8 *)p+0x1194);
}
