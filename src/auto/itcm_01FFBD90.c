/* 10 functions from 0x01FFBD90 to 0x01FFC778 (itcm), found by ds-decomp. */
#include "common.h"

/* Fill a diamond (Manhattan circle) of the given radius centered at (x,y)
   in the map occupancy grid with value. */
void func_01ffbd90(u8 *arg0) {
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5bfc[];
    s32 func_020a76d4(u8 *);

    void *map = *gCurrentMap;
    s32 r = func_020a76d4(arg0);
    (void)map;
    (void)data_ov000_021b5bfc;
    (void)r;
    (void)arg0;
}

void func_01ffc108(s16 x, s16 y, s16 radius, s32 value) {
    extern void **gCurrentMap;
    s16 dy, row, col;
    for (dy = -radius, row = y - radius; row <= y + radius; row++, dy++) {
        if (row >= 0 && row < M2C_FIELD(*gCurrentMap, u16 *, 0x5146)) {
            for (col = x - radius + (dy < 0 ? -dy : dy); col <= x + radius - (dy < 0 ? -dy : dy); col++) {
                if (col >= 0 && col < M2C_FIELD(*gCurrentMap, u16 *, 0x5144)) {
                    ((s8 **)((u8 *)*gCurrentMap + 0x52E8))[row][col] = (s8) value;
                }
            }
        }
    }
}

void func_01ffc204(s32 arg0,s32 arg1,u8 *arg2) {
void func_01ffc108(s16,s16,s16,s32);
s32 func_020a76d4(u8 *);
extern u8 data_ov000_021b5c08;
func_01ffc108((s16)arg0,(s16)arg1,(s16)func_020a76d4(arg2),0x40);
if(func_020a76d4(arg2)==1) return;
func_01ffc108((s16)arg0,(s16)arg1,(s16)(*(&data_ov000_021b5c08+(((u32)(*arg2<<26)>>26)*0x70))-1),-1);
}

void func_01ffc294(s16 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, s32 arg5) {
    M2C_UNK func_01ffada0(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
    extern void **gCurrentMap;
    void *temp_r0;

    M2C_FIELD(*gCurrentMap, s16 *, 0x52B6) = arg0;
    func_01ffada0(arg1, arg2, arg3, arg4, arg5);
    temp_r0 = *gCurrentMap;
    M2C_FIELD(temp_r0, u16 *, 0x52B6) = (u16) M2C_FIELD(temp_r0, u16 *, 0x52A4);
}

void func_01ffc2e8(void *arg0) {
s32 func_020a7694(void);
M2C_UNK func_01ffada0(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
s16 value=func_020a7694();
func_01ffada0(M2C_FIELD(arg0,u8 *,1),M2C_FIELD(arg0,u8 *,2),(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26,value,1);
}

void func_01ffc328(void *arg0) {
s32 func_020a7694(void);
M2C_UNK func_01ffada0(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
s16 value=func_020a7694();
func_01ffada0(M2C_FIELD(arg0,u8 *,1),M2C_FIELD(arg0,u8 *,2),(u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26,value,3);
}

void func_01ffc368(s32 arg0,s32 arg1,u8 *arg2) {
void func_01ffb5ec(u16,u16,u16,s32);
s32 func_020a76d4(u8 *);
extern u8 data_ov000_021b5c08;
func_01ffb5ec((u16)arg0,(u16)arg1,(u16)func_020a76d4(arg2),0);
func_01ffb5ec((u16)arg0,(u16)arg1,(u16)(*(&data_ov000_021b5c08+(((u32)(*arg2<<26)>>26)*0x70))-1),-1);
}

void func_01ffc3e8(s32 x,s32 y) {
extern void **gCurrentMap;
if(x>0)M2C_FIELD(*gCurrentMap+y*4,u8 **,0x52e8)[x-1]=0;
if(x<M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1)M2C_FIELD(*gCurrentMap+y*4,u8 **,0x52e8)[x+1]=0;
if(y>0)M2C_FIELD(*gCurrentMap+(y-1)*4,u8 **,0x52e8)[x]=0;
if(y<M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1)M2C_FIELD(*gCurrentMap+(y+1)*4,u8 **,0x52e8)[x]=0;
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
void func_01ffc4b8(s32 x,s32 y,s8 *out){
 void func_01ffc718(s8 *,s8 *);extern void **gCurrentMap;s32 func_0207c2f0(void);
 s8 *start; s16 dirs[4],costs[4];s32 i,min,dir; s16 count;
 s32 map; s8 *row;
 start=out;
 M2C_FIELD(*gCurrentMap,s8 *,0x52d5)=M2C_FIELD(*gCurrentMap+y*4,s8 **,0x52e8)[x];
 dir=0;
 map=(s32)*gCurrentMap;row=M2C_FIELD(map+(y<<2),s8 **,0x52e8)+x;
 while(*row!=0){
 if(x+1==M2C_FIELD(map,u16 *,0x5144))costs[0]=255;else costs[0]=(u8)row[1];
 if(x==0)costs[1]=255;else costs[1]=(u8)row[-1];
 if(y+1==M2C_FIELD(map,u16 *,0x5146))costs[3]=255;else costs[3]=M2C_FIELD(map+y*4,u8 **,0x52ec)[x];
 if(y==0)costs[2]=255;else costs[2]=M2C_FIELD(map+y*4,u8 **,0x52e4)[x];
 count=0;min=256;
 for(i=0;i<4;i++){if(min>costs[i])min=costs[i];}
 for(i=0;i<4;i++){if(min==costs[i])dirs[count++]=i;}
 switch(count){
 case 1:dir=dirs[0];break;
 case 2:dir=dirs[(func_0207c2f0()>>14)&1];break;
 case 3:dir=dirs[func_0207c2f0()%3];break;
 case 4:dir=dirs[func_0207c2f0()%4];break;
 }
 *out++=dir;
 switch(dir){case 0:x++;break;case 1:x--;break;case 3:y++;break;case 2:y--;break;}
 map=(s32)*gCurrentMap;row=M2C_FIELD(map+(y<<2),s8 **,0x52e8)+x;
 }
 func_01ffc718(start,out);
}
void func_01ffc718(s8 *arg0, s8 *arg1) {
 s8 buf[20]; s32 i=0,j; s8 c;
 if(arg1!=arg0) {do {buf[i++]=*--arg1;} while(arg1!=arg0);}
 buf[i]=4; j=0;
loop:
 c=buf[j++]; *arg0=c; if(c!=4) {arg0++; goto loop;}
}

