/* 6 functions from 0x021A7610 to 0x021A860C (ov000), found by ds-decomp. */
#include "common.h"
#pragma optimization_level 0
static inline s32 AiWeightedCount(s32 value,s32 kind) { extern u16 data_ov000_021e14aa[]; return data_ov000_021e14aa[kind]*value; }
#pragma optimization_level reset
#pragma optimization_level 0
static inline s32 AiProduct(s32 factor, s32 value) { return factor * value; }
#pragma optimization_level reset
#pragma optimization_level 0
static inline s32 AiScale(s32 value,s32 kind) {
 extern u16 data_ov000_021e14aa[];
 s32 func_ov000_021a6f24(s32,s32,s32);
 value=AiProduct(data_ov000_021e14aa[kind],value);
 return func_ov000_021a6f24(value,kind,0);
}
#pragma optimization_level reset
typedef struct { s32 money; s32 unk4; s32 income; u8 pad[128]; } AiPlayer;

void func_ov000_021a7d08(void) {
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    extern void **gCurrentMap;
    extern u16 data_ov000_021e1474[];
    extern u16 data_ov000_021e14aa[];
    extern u16 data_ov000_021aeef4[];
    void func_ov000_021a7610(void);

    register s32 r5 asm("r5");

    for (r5 = 0; r5 < 0x1B; r5++) {
        data_ov000_021e1474[r5] = 0;
        data_ov000_021e14aa[r5] = data_ov000_021e1474[r5];
    }

    for (r5 = 1; r5 < 5; r5++) {
        u16 field;
        s32 start;
        register s32 limit;
        register s32 inner;
        u8 *p;
        void *map;

        if (!func_020d1938(r5)) {
            continue;
        }
        map = *gCurrentMap;
        field = *(u16 *)((u8 *)*gCurrentMap + 0x52A4);
        if (func_020d273c(field, r5) == 1) {
            start = data_ov000_021aeef4[r5] + 1;
            limit = data_ov000_021aeef4[r5] + 0x33;
            for (inner = start; inner < limit; inner++) {
                u32 kind, value;
                p = (u8 *)*gCurrentMap + 0x59A4 + inner * 0xE;
                kind = (u32)p[0] << 26;
kind >>= 26;
                if (kind == 0) {
                    continue;
                }
                if ((((unsigned int)p[0x0B]) << 24) >> 31) {
                    continue;
                }
                value = (u32)*(u16 *)(p + 6) << 25;
data_ov000_021e14aa[kind] += value >> 25;
            }
        } else {
            start = data_ov000_021aeef4[r5] + 1;
            limit = data_ov000_021aeef4[r5] + 0x33;
            for (inner = start; inner < limit; inner++) {
                u32 kind, value;
                p = (u8 *)*gCurrentMap + 0x59A4 + inner * 0xE;
                kind = (u32)p[0] << 26;
kind >>= 26;
                if (kind == 0) {
                    continue;
                }
                value = (u32)*(u16 *)(p + 6) << 25;
data_ov000_021e1474[kind] += value >> 25;
            }
        }
    }
    func_ov000_021a7610();
}

s32 func_ov000_021a7e98(s32 arg0) {
    s32 func_020d2d18(u16, M2C_UNK);
    s32 func_ov000_021a6c8c();
    s32 func_ov000_021a72c0(M2C_UNK);
    s32 func_ov000_021a8784(M2C_UNK);
    extern void **gCurrentMap;
    register void *temp_r4;
    u16 temp_r5;

    if (arg0) {
        temp_r4 = *gCurrentMap;
        temp_r5 = M2C_FIELD(temp_r4, u16 *, 0x52A4);
        if ((s32) (func_020d2d18(temp_r5, 0x15) * 0xA) > M2C_FIELD(((temp_r5 * 0x8C) + temp_r4), s32 *, 0x67A4)) {
            return -1;
        }
    }
    if (func_ov000_021a72c0(0x15) == 0) {
        return -1;
    }
    if (func_ov000_021a8784(0x15) != 0) {
        return -1;
    }
    return func_ov000_021a6c8c();
}

s32 func_ov000_021a8438(s32 index) {
 extern u8 data_ov000_021e00ac[],data_ov000_021b5c6c[],data_ov000_021b5be0[],data_ov000_021b5bfc[],data_ov000_021df7d0[];
 extern u8 *data_ov000_021df580; extern u32 data_ov000_021df8ac[];extern void **gCurrentMap;
 s32 func_ov000_021a98e4(u8);s32 func_020d2d18(u16,s32);s32 func_ov000_021a4e08(u32,u32,s32);
 u8 *entry=data_ov000_021e00ac+index*12;
 u32 score; s32 retry=0; s32 best,i;u8 *attr;u8 *map;AiPlayer *player;s32 price;u32 flag;s32 cost,money,offset;
 if(entry[2]==3 && (((u32)(*(u16 *)(data_ov000_021df580+10)<<29)>>29)&2))return -1;
 for(;;) {
 best=0;score=0;
 for(i=1,attr=data_ov000_021b5c6c;i<27;i++,attr+=112) {
 if(score<data_ov000_021df8ac[i]) {
 if(func_ov000_021a98e4((u8)i)==1 && (attr[19]&7))continue;
 score=data_ov000_021df8ac[i];best=i;
 }}
 if(best==0)return -1;
 if(entry[2]!=data_ov000_021b5be0[best])goto reject;
 cost=func_020d2d18(*(u16 *)((u8 *)*gCurrentMap+0x52a4),best)*10;
 price=(u16)cost;map=*gCurrentMap;player=(AiPlayer *)(map+0x67a4)+*(u16 *)(map+0x52a4);
 money=player->money;
 if(money<price)goto reject;
 if(!retry || (flag=data_ov000_021b5bfc[best*112+19]&16)!=0) {
 if(func_ov000_021a4e08(entry[0],entry[1],best)<70)goto accept;
 if(data_ov000_021b5bfc[best*112+19]&16)goto reject;
 if(best==22)goto reject;
 retry=1;continue;
 } else {
 if(flag!=0)goto reject;
 if(price>(player->income>>1) && price>(money>>1))goto reject;
 }
 accept:data_ov000_021df7d0[6]=best;return index;
 reject:data_ov000_021df8ac[best]=0;
 }
}
void func_ov000_021a7610(void) {
u8 func_ov000_021a7348(void); s32 func_ov000_021a6e5c(u8); s32 func_ov000_021a72c0(s32);
s32 func_ov000_021a96f4(s32,s32,s32); s32 func_ov000_021a96a8(s32,s32,s32);
s32 func_ov000_021a6f24(s32,s32,s32); s32 func_0207c8ec(s32,s32);
s32 func_ov000_021a7084(u8,u8); s32 func_ov000_021a881c(s32,s32); s32 func_020d2d18(u16,s32);
extern u8 *data_ov000_021df578; extern u32 data_ov000_021df8ac[27];
extern u16 data_ov000_021e1474[27],data_ov000_021e14aa[27]; extern u8 *data_ov000_021df580;
extern u8 data_ov000_021df598[]; extern u8 data_ov000_021b5bfc[]; extern void **gCurrentMap;
s32 values[9]; s32 minimum;
s32 b,a,i,j,k,t,v;
s32 kind;
data_ov000_021df578[6]=func_ov000_021a7348();
for(a=0;a<27;a++)data_ov000_021df8ac[a]=0;
for(b=0;b<9;b++)values[b]=0;
for(i=1;i<27;i++){j=func_ov000_021a6e5c((u8)i);if(j!=10)values[j]+=data_ov000_021e1474[i];}
t=(u32)(M2C_FIELD(data_ov000_021df580,u16*,10)<<29)>>29;
if((t&4) && !(t&2))values[7]*=2;
for(kind=1;kind<27;kind++){
if(!func_ov000_021a72c0((u8)kind))continue;
for(j=0;j<9;j++){
if(values[j]==0)continue;
if(data_ov000_021df598[j]==22)v=func_ov000_021a96f4(kind,data_ov000_021df598[j],0);
else v=func_ov000_021a96a8(kind,data_ov000_021df598[j],0);
v=func_ov000_021a6f24(AiProduct(v,data_ov000_021e14aa[kind]),kind,0);
if(data_ov000_021b5bfc[data_ov000_021df598[j]*112+19]&16){
if(kind==6 && (data_ov000_021df578[6]==2 || data_ov000_021df578[6]==4))v>>=1;
if(kind==23 && (data_ov000_021df578[6]==1 || data_ov000_021df578[6]==3))v>>=1;
}
values[j]-=func_0207c8ec(v,100);
}
}
for(j=0;j<9;j++)if(values[j]>0)goto positive;
goto nonpositive;
positive: {
for(i=1;i<27;i++){
if(!func_ov000_021a72c0((u8)i))continue;
if(i==6 && !(((u32)(M2C_FIELD(data_ov000_021df580,u16*,10)<<29)>>29)&10))continue;
for(j=0;j<9;j++)if(values[j]>0)data_ov000_021df8ac[i]+=AiProduct(func_ov000_021a7084((u8)i,data_ov000_021df598[j]),values[j]);
for(k=0;k<func_ov000_021a881c(i,5);k++)data_ov000_021df8ac[i]-=(u32)data_ov000_021df8ac[i]>>3;
}
return;
}
nonpositive:
minimum=0;for(j=0;j<9;j++)if(minimum>values[j])minimum=values[j];
if(minimum!=0){
for(i=1;i<27;i++){
if(!func_ov000_021a72c0((u8)i))continue;
if(i==6 && !(((u32)(M2C_FIELD(data_ov000_021df580,u16*,10)<<29)>>29)&10))continue;
for(j=0;j<9;j++)if(values[j]!=0)data_ov000_021df8ac[i]+=AiProduct(func_ov000_021a7084((u8)i,data_ov000_021df598[j]),(values[j]-(minimum-1)));
for(k=0;k<func_ov000_021a881c(i,5);k++)data_ov000_021df8ac[i]-=(u32)data_ov000_021df8ac[i]>>2;
}
return;
}
for(i=1;i<27;i++){
if(!func_ov000_021a72c0((u8)i))continue;
if(i==6 && !(((u32)(M2C_FIELD(data_ov000_021df580,u16*,10)<<29)>>29)&10))continue;
if(!func_ov000_021a96a8(i,1,0))continue;
data_ov000_021df8ac[i]=func_020d2d18(M2C_FIELD(*gCurrentMap,u16*,0x52a4),i);
for(k=0;k<func_ov000_021a881c(i,5);k++)data_ov000_021df8ac[i]-=(u32)data_ov000_021df8ac[i]>>2;
}
}

void func_ov000_021a7ac0(s32 index) {
extern u16 data_ov000_021e1474[],data_ov000_021e14aa[];
extern u8 *data_ov000_021df57c;
extern u8 data_ov000_021e00ac[],data_ov000_021e00ad[],data_ov000_021b5bfc[];
extern void **gCurrentMap;
void func_01ffada0(s32,s32,s32,s32,s32); s32 func_020d27c0(s32); void func_ov000_021a7610(void);
s32 minx,maxy,r,cx,cy; s32 maxx,y,x,i,off,miny; u8 *unit,*map,*entry;
for(i=0;i<27;i++) {data_ov000_021e1474[i]=0;data_ov000_021e14aa[i]=data_ov000_021e1474[i];}
off=index*12;
func_01ffada0(data_ov000_021e00ac[off],data_ov000_021e00ad[off],7,data_ov000_021df57c[16],0);
cy=data_ov000_021e00ad[off]; r=data_ov000_021df57c[16]; cx=data_ov000_021e00ac[off];
minx=cx-r; if(minx<0)minx=0;
miny=cy-r; if(miny<0)miny=0;
map=*gCurrentMap;
maxx=r+cx; if(maxx>*(u16 *)(map+0x5144)-1)maxx=*(u16 *)(map+0x5144)-1;
maxy=r+cy; if(maxy>*(u16 *)(map+0x5146)-1)maxy=*(u16 *)(map+0x5146)-1;
entry=data_ov000_021e00ac+off;
for(y=miny;y<=maxy;y++)for(x=minx;x<=maxx;x++){
s32 dx=entry[0]-x,dy=entry[1]-y,d;
if(dx<=0)dx=x-entry[0];if(dy<=0)dy=y-entry[1];d=0+dx+dy;
if(d<0||d>data_ov000_021df57c[16])continue;
map=*gCurrentMap;
i=map[*(u16 *)(map+0x3758+y*2)+x]; if(!i)continue;
unit=map+0x59a4+i*14;
if((data_ov000_021b5bfc[(((u32)(unit[0]<<26)>>26))*112+19]&7)&&((s8 **)(map+0x52e8))[y][x]<0)continue;
if(func_020d27c0(i)==1)data_ov000_021e14aa[((u32)(unit[0]<<26)>>26)]+=((u32)(*(u16 *)(unit+6)<<25)>>25);
else data_ov000_021e1474[((u32)(unit[0]<<26)>>26)]+=((u32)(*(u16 *)(unit+6)<<25)>>25);
}
func_ov000_021a7610();
}

