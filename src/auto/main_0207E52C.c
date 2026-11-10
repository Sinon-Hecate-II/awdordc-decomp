/* 3 functions from 0x0207E52C to 0x0207F460 (main), found by ds-decomp. */
#include "common.h"
typedef struct { s32 values[4]; } TerrainVariants7E52;
typedef struct { s16 x,y,z; } TerrainOffset7E52;
typedef struct { TerrainOffset7E52 values[4]; } TerrainNeighbors7E52;

#pragma opt_lifetimes off
#pragma opt_instruction_scheduling off
s32 func_0207e52c(s32 x,s32 y) {
s32 func_0207e150(s32,s32);s32 func_0207dc0c(s32,s32);s32 GetTerrainEdgeVariant(s32,s32);s32 func_0207e338(s32,s32);s32 func_0207e39c(s32,s32);s32 func_0207e400(s32,s32);s32 func_0207e464(s32,s32);s32 func_0207e4c8(s32,s32);
extern TerrainVariants7E52 data_020ebe04,data_020ebe14,data_020ebe24;
extern TerrainNeighbors7E52 gTerrainNeighborOffsets;
extern void **gCurrentMap;
extern void *gTerrainTileset;
extern M2C_UNK gTerrainClassFlags;
u16 *lookup;
TerrainVariants7E52 variantsA,variantsB,variantsC;
TerrainNeighbors7E52 adjacent0,adjacent1,adjacent2,adjacent3,adjacent4,adjacent5;
s32 i,nx,ny,index,type,row;
u16 tile;
u32 bits=0;
u8 *map;
variantsA=data_020ebe04;variantsB=data_020ebe14;variantsC=data_020ebe24;
map=*gCurrentMap;
lookup=M2C_FIELD(&gTerrainTileset,u16 **,4);
row=M2C_FIELD(map+y*2,u16 *,0x3758);
index=row+x;
tile=lookup[M2C_FIELD(map+index*2,u16 *,0xa10)];
switch(tile){
case 1:return func_0207e338(x,y);
case 7:return func_0207e39c(x,y);
case 53:return func_0207e400(x,y);
case 220:return func_0207e464(x,y);
case 224:return func_0207e4c8(x,y);
case 56:
adjacent0=gTerrainNeighborOffsets;
for(i=0;i<4;i++){
nx=x+adjacent0.values[i].x;ny=y+adjacent0.values[i].y;
if(nx<0||ny<0)continue;
map=*gCurrentMap;
if(nx>=M2C_FIELD(map,u16 *,0x5144)||ny>=M2C_FIELD(map,u16 *,0x5146))continue;
index=M2C_FIELD(map+ny*2,u16 *,0x3758)+nx;
type=lookup[M2C_FIELD(map+index*2,u16 *,0xa10)];
if(M2C_FIELD(&gTerrainClassFlags,u32 *,type*8)&3145728)bits=(u8)(bits|(1<<i));
}
switch(bits){
case 1:
if(x>=0&&(ny=y+(1))>=0&&x<M2C_FIELD(*gCurrentMap,u16 *,0x5144)&&ny<M2C_FIELD(*gCurrentMap,u16 *,0x5146))break;
bits=(u8)(bits|8);break;
case 2:
if((nx=x+(1))>=0&&y>=0&&nx<M2C_FIELD(*gCurrentMap,u16 *,0x5144)&&y<M2C_FIELD(*gCurrentMap,u16 *,0x5146))break;
bits=(u8)(bits|4);break;
case 4:
if((nx=x+(-1))>=0&&y>=0&&nx<M2C_FIELD(*gCurrentMap,u16 *,0x5144)&&y<M2C_FIELD(*gCurrentMap,u16 *,0x5146))break;
bits=(u8)(bits|2);break;
case 8:
if(x>=0&&(ny=y+(-1))>=0&&x<M2C_FIELD(*gCurrentMap,u16 *,0x5144)&&ny<M2C_FIELD(*gCurrentMap,u16 *,0x5146))break;
bits=(u8)(bits|1);break;
}
return (u16)(tile+bits);
case 104:
adjacent1=gTerrainNeighborOffsets;
for(i=0;i<4;i++){
nx=x+adjacent1.values[i].x;ny=y+adjacent1.values[i].y;
if(nx<0||ny<0)continue;
map=*gCurrentMap;
if(nx>=M2C_FIELD(map,u16 *,0x5144)||ny>=M2C_FIELD(map,u16 *,0x5146))continue;
index=M2C_FIELD(map+ny*2,u16 *,0x3758)+nx;
type=lookup[M2C_FIELD(map+index*2,u16 *,0xa10)];
if(M2C_FIELD(&gTerrainClassFlags,u32 *,type*8)&3211264)bits=(u8)(bits|(1<<i));
}
return (u16)(tile+bits);
case 120:
adjacent2=gTerrainNeighborOffsets;
for(i=0;i<4;i++){
nx=x+adjacent2.values[i].x;ny=y+adjacent2.values[i].y;
if(nx<0||ny<0)continue;
map=*gCurrentMap;
if(nx>=M2C_FIELD(map,u16 *,0x5144)||ny>=M2C_FIELD(map,u16 *,0x5146))continue;
index=M2C_FIELD(map+ny*2,u16 *,0x3758)+nx;
type=lookup[M2C_FIELD(map+index*2,u16 *,0xa10)];
if(M2C_FIELD(&gTerrainClassFlags,u32 *,type*8)&3211264)bits=(u8)(bits|(1<<i));
}
return (u16)(tile+bits);
case 88:
case 152:
{u8 specialBits=0;
adjacent3=gTerrainNeighborOffsets;
for(i=0;i<4;i++){
nx=x+adjacent3.values[i].x;ny=y+adjacent3.values[i].y;
if(nx<0||ny<0)continue;
map=*gCurrentMap;
if(nx>=M2C_FIELD(map,u16 *,0x5144)||ny>=M2C_FIELD(map,u16 *,0x5146))continue;
index=M2C_FIELD(map+ny*2,u16 *,0x3758)+nx;
type=lookup[M2C_FIELD(map+index*2,u16 *,0xa10)];
if(M2C_FIELD(&gTerrainClassFlags,u32 *,type*8)&8388608)specialBits=(u8)(specialBits|(1<<i));
}
return (u16)(tile+specialBits);
}
case 72:
case 136:
{u8 specialBits=0;
adjacent4=gTerrainNeighborOffsets;
for(i=0;i<4;i++){
nx=x+adjacent4.values[i].x;ny=y+adjacent4.values[i].y;
if(nx<0||ny<0)continue;
map=*gCurrentMap;
if(nx>=M2C_FIELD(map,u16 *,0x5144)||ny>=M2C_FIELD(map,u16 *,0x5146))continue;
index=M2C_FIELD(map+ny*2,u16 *,0x3758)+nx;
type=lookup[M2C_FIELD(map+index*2,u16 *,0xa10)];
if(M2C_FIELD(&gTerrainClassFlags,u32 *,type*8)&12582912)specialBits=(u8)(specialBits|(1<<i));
}
switch(specialBits){
case 1:
if(x>=0&&(ny=y+(1))>=0&&x<M2C_FIELD(*gCurrentMap,u16 *,0x5144)&&ny<M2C_FIELD(*gCurrentMap,u16 *,0x5146))break;
specialBits=(u8)(specialBits|8);break;
case 2:
if((nx=x+(1))>=0&&y>=0&&nx<M2C_FIELD(*gCurrentMap,u16 *,0x5144)&&y<M2C_FIELD(*gCurrentMap,u16 *,0x5146))break;
specialBits=(u8)(specialBits|4);break;
case 4:
if((nx=x+(-1))>=0&&y>=0&&nx<M2C_FIELD(*gCurrentMap,u16 *,0x5144)&&y<M2C_FIELD(*gCurrentMap,u16 *,0x5146))break;
specialBits=(u8)(specialBits|2);break;
case 8:
if(x>=0&&(ny=y+(-1))>=0&&x<M2C_FIELD(*gCurrentMap,u16 *,0x5144)&&ny<M2C_FIELD(*gCurrentMap,u16 *,0x5146))break;
specialBits=(u8)(specialBits|1);break;
}
return (u16)(tile+specialBits);
}
case 14:
adjacent5=gTerrainNeighborOffsets;
for(i=0;i<4;i++){
nx=x+adjacent5.values[i].x;ny=y+adjacent5.values[i].y;
if(nx<0||ny<0)continue;
map=*gCurrentMap;
if(nx>=M2C_FIELD(map,u16 *,0x5144)||ny>=M2C_FIELD(map,u16 *,0x5146))continue;
index=M2C_FIELD(map+ny*2,u16 *,0x3758)+nx;
type=lookup[M2C_FIELD(map+index*2,u16 *,0xa10)];
if(M2C_FIELD(&gTerrainClassFlags,u32 *,type*8)&0x1000000)bits=(u8)(bits|(1<<i));
}
return (u16)(tile+bits);

case 227:return func_0207e150(x,y);
case 173:return func_0207dc0c(x,y);
case 265:return GetTerrainEdgeVariant(x,y);
case 44:case 48:case 168:
nx=x+1;
if(nx>=0&&y>=0){
map=*gCurrentMap;
if(nx<M2C_FIELD(map,u16 *,0x5144)&&y<M2C_FIELD(map,u16 *,0x5146)){
index=row+nx;
if(tile==lookup[M2C_FIELD(map+index*2,u16 *,0xa10)])bits++;
}}
nx=x-1;
if(nx>=0&&y>=0){
map=*gCurrentMap;
if(nx<M2C_FIELD(map,u16 *,0x5144)&&y<M2C_FIELD(map,u16 *,0x5146)){
index=row+nx;
if(tile==lookup[M2C_FIELD(map+index*2,u16 *,0xa10)])bits+=2;
}}
if(tile==44)tile=variantsA.values[bits];
if(tile==48)tile=variantsB.values[bits];
if(tile==168)tile=variantsC.values[bits];
return tile;
default:return tile;
}
}
#pragma opt_instruction_scheduling reset
#pragma opt_lifetimes reset
s32 func_0207ef5c(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_0207dc0c(s32, s32);
    s32 GetTerrainEdgeVariant(s32, s32);
    s32 func_0207e338(s32, s32);
    extern M2C_UNK gTerrainClassFlags;
    u16 flags;
    flags = (u16)M2C_FIELD(&gTerrainClassFlags, u32 *, arg2 * 8);
    if (arg2 == 0x34) return 5;
    if (flags & 1) return func_0207e338(arg0, arg1);
    if (flags & 2) return func_0207dc0c(arg0, arg1);
    if (!(flags & 4)) return 0;
    return GetTerrainEdgeVariant(arg0, arg1);
}

s32 func_0207efb4(s32 arg0) {
    switch (arg0) {
    case 0x17c: return 1;
    case 2: return 1;
    case 3: return 5;
    case 4: return 8;
    case 7: return 2;
    case 0x20: return 4;
    case 0x21: return 3;
    case 0x22: return 9;
    case 0x23: return 7;
    case 0x24: return 13;
    case 0x25: return 14;
    case 0x27: return 10;
    case 0x142: return 0x1b;
    case 0x146: return 0x3b;
    case 0x162: return 0x1c;
    case 0x166: return 0x3c;
    case 0x168: return 0xc;
    case 0x179: return 0x14;
    case 0x17a: return 0x34;
    case 0x17b: return 0x54;
    case 0x17d: return 0x74;
    case 0x17e: return 0x94;
    case 0x181: return 0x18;
    case 0x182: return 6;
    case 0x19b: return 0x15;
    case 0x19c: return 0x35;
    case 0x19d: return 0x55;
    case 0x19e: return 0x75;
    case 0x19f: return 0x95;
    case 0x1a3: return 0x1a;
    case 0x1bb: return 0x16;
    case 0x1bc: return 0x36;
    case 0x1bd: return 0x56;
    case 0x1be: return 0x76;
    case 0x1bf: return 0x96;
    case 0x1c0: return 0xf;
    case 0x1c1: return 0x11;
    case 0x1c2: return 0x10;
    case 0x1c3: return 0x12;
    case 0x1c4: return 0x13;
    case 0x1c5: return 0x2f;
    case 0x1c6: return 0x31;
    case 0x1c7: return 0x30;
    case 0x1c8: return 0x32;
    case 0x1c9: return 0x33;
    case 0x1ca: return 0x4f;
    case 0x1cb: return 0x51;
    case 0x1cc: return 0x50;
    case 0x1cd: return 0x52;
    case 0x1ce: return 0x53;
    case 0x1cf: return 0x6f;
    case 0x1d0: return 0x71;
    case 0x1d1: return 0x70;
    case 0x1d2: return 0x72;
    case 0x1d3: return 0x73;
    case 0x1d4: return 0x8f;
    case 0x1d5: return 0x91;
    case 0x1d6: return 0x90;
    case 0x1d7: return 0x92;
    case 0x1d8: return 0x93;
    case 0x1d9: return 0x17;
    case 0x1da: return 0x37;
    case 0x1db: return 0x57;
    case 0x1dc: return 0x77;
    case 0x1dd: return 0x97;
    default: return 1;
    }
}

