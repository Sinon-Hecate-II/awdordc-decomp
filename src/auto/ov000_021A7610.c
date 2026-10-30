/* 6 functions from 0x021A7610 to 0x021A860C (ov000), found by ds-decomp. */
#include "common.h"
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
        s32 limit;
        register s32 inner asm("r2");
        u8 *p;
        void *map;

        if (!func_020d1938(r5)) {
            continue;
        }
        map = *gCurrentMap;
        field = *(u16 *)((u8 *)map + 0x52A4);
        if (func_020d273c(field, r5) == 1) {
            start = data_ov000_021aeef4[r5] + 1;
            limit = data_ov000_021aeef4[r5] + 0x33;
            for (inner = start; inner < limit; inner++) {
                u8 kind;
                p = *(u8 **)map + 0x59A4 + inner * 0xE;
                kind = (u8)(((unsigned int)p[0] << 26) >> 26);
                if (kind == 0) {
                    continue;
                }
                if ((((unsigned int)p[0x0B]) << 24) >> 31) {
                    continue;
                }
                data_ov000_021e14aa[kind] += (u16)(((unsigned int)*(u16 *)(p + 6) << 19) >> 19);
            }
        } else {
            start = data_ov000_021aeef4[r5] + 1;
            limit = data_ov000_021aeef4[r5] + 0x33;
            for (inner = start; inner < limit; inner++) {
                u8 kind;
                p = *(u8 **)map + 0x59A4 + inner * 0xE;
                kind = (u8)(((unsigned int)p[0] << 26) >> 26);
                if (kind == 0) {
                    continue;
                }
                data_ov000_021e1474[kind] += (u16)(((unsigned int)*(u16 *)(p + 6) << 19) >> 19);
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

