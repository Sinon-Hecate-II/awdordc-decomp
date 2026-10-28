/* 12 functions from 0x02214E24 to 0x02215DD8 (ov007), found by ds-decomp. */
#include "common.h"
typedef struct { u16 x,y; } Point15A0C;
#pragma opt_common_subs off
#pragma opt_propagation off
static inline volatile Point15A0C *PointZero15A0C(volatile Point15A0C *p) { ((volatile u16 *)p)[0]=0;((volatile u16 *)p)[1]=0;return p; }
#pragma opt_common_subs reset
#pragma opt_propagation reset
typedef struct Map14E24 { u8 pad[0xa10]; u16 cells[(0x3758-0xa10)/2]; u16 rows[32]; u8 pad3798[0x5144-0x3798];u16 width,height; } Map14E24;
extern s32 *gCurrentMap;
extern u8 data_ov007_02221a84[800];

void func_ov007_02214e24(void) {
s32 x,y; s32 *p; u8 *row;
p=gCurrentMap;
y=0;
if(M2C_FIELD(*p,u16 *,0x5146)<=y)return;
row=data_ov007_02221a84;
do {

for(x=0;x<M2C_FIELD(*p,u16 *,0x5144);x++){
row[x]=0;
if(x==0)row[x]=1;
if(y==0)row[x]=1;
if(x==M2C_FIELD(*p,u16 *,0x5144)-1)row[x]=1;
if(y==M2C_FIELD(*p,u16 *,0x5146)-1)row[x]=1;
}
y++; row+=30;
}while(y<M2C_FIELD(*p,u16 *,0x5146));
}

/* Mark each unit standing on a tile of the tactical map (value 2 in the
   30-wide unit grid data_ov007_02221a84) as "moved" (1) and clear value 2
   from its four orthogonal neighbours; returns 1 if any unit was found. */
s32 Map_MarkUnitsMoved(void){
s32 x,y,found=0; s32 *p=gCurrentMap; s8 *row;
y=0;
if(y<M2C_FIELD(*p,u16 *,0x5146)){
row=(s8*)data_ov007_02221a84;
do{
for(x=0;x<M2C_FIELD(*p,u16 *,0x5144);x++){
if(row[x]==2){
if(x-1>=0)row[x-1]=0;
if(y-1>=0)row[x-30]=0;
if(x+1<M2C_FIELD(*p,u16 *,0x5144))row[x+1]=0;
if(y+1<M2C_FIELD(*p,u16 *,0x5146))row[x+30]=0;
found=1;row[x]=1;
}
}
y++;row+=30;
}while(y<M2C_FIELD(*p,u16 *,0x5146));
}return found!=0;
}

s32 func_ov007_02214ff8(s32 x,s32 y,s32 value){
s32 count;
if(((s8*)data_ov007_02221a84+y*30)[x])return 0;
count=0;
if(x-1<0 || value==((Map14E24*)*gCurrentMap)->cells[x-1+((Map14E24*)*gCurrentMap)->rows[y]])count++;
if(y-1<0 || value==((Map14E24*)*gCurrentMap)->cells[x+((Map14E24*)*gCurrentMap)->rows[y-1]])count++;
if(x+1>=M2C_FIELD(*gCurrentMap,u16*,0x5144) || value==((Map14E24*)*gCurrentMap)->cells[x+1+((Map14E24*)*gCurrentMap)->rows[y]])count++;
if(y+1>=M2C_FIELD(*gCurrentMap,u16*,0x5146) || value==((Map14E24*)*gCurrentMap)->cells[x+((Map14E24*)*gCurrentMap)->rows[y+1]])count++;
return count;
}

s32 func_ov007_02215128(s32 value,s32 mode){
s32 RandomIntRange(s32,s32);s32 n;
switch(mode){
case 32:
if(!value)break;
n=RandomIntRange(1,8);
switch(value){case 0:break;case 1:value=2;break;case 2:value=3;break;case 3:value=3;break;case 4:value=5;break;}
if(n<=value)return 1;break;
case 3:
if(!value)break;
n=RandomIntRange(1,6);
switch(value){case 0:break;case 1:value=2;break;case 2:value=4;break;case 3:value=5;break;case 4:value=6;break;}
if(n<=value)return 1;break;
case 34:
n=RandomIntRange(1,4);
switch(value){case 0:value=1;break;case 1:value=3;break;case 2:value=4;break;}
if(n<=value)return 1;break;
}
return 0;
}

void func_ov007_02215254(s32 arg0, s32 arg1, s16 arg2) {
    s8 func_0207efb4(s16);
    extern s32 *gCurrentMap;
    s32 temp_ip;
    s32 temp_r6;

    temp_ip = *gCurrentMap;
    M2C_FIELD((temp_ip + ((arg0 + M2C_FIELD((temp_ip + (arg1 * 2)), u16 *, 0x3758)) * 2)), s16 *, 0xA10) = arg2;
    temp_r6 = *gCurrentMap;
    M2C_FIELD((temp_r6 + (arg0 + M2C_FIELD((temp_r6 + (arg1 * 2)), u16 *, 0x3758))), s8 *, 0x1420) = func_0207efb4(arg2);
}

s32 func_ov007_022152bc(M2C_UNK arg0, s32 arg1) {
    (void) arg0;
    (void) arg1;
    return 0;
}

s32 func_ov007_022156a4(s32 x,s32 y) {
 s32 func_ov007_0221b754(s32,s32);
 s32 i,j;
 for(j=y-1;j<=y+1;j++)
 for(i=x-1;i<=x+1;i++)
 if(!func_ov007_0221b754(i,j)) return 0;
 return 1;
}

/* Places value 36 at (x,y) if it sits in an open straight corridor
   (left+right or up+down tiles passable with no unit in between). */
s32 func_ov007_02215704(s32 x, s32 y) {
    s32 func_ov007_0221b754(s32, s32);
    if (func_ov007_0221b754(x - 1, y) == 1 && ((s8 *)data_ov007_02221a84 + y * 30)[x - 1] != 2 &&
        func_ov007_0221b754(x + 1, y) == 1 && ((s8 *)data_ov007_02221a84 + y * 30)[x + 1] != 2) {
        func_ov007_02215254(x, y, 36);
        return 1;
    }
    if (func_ov007_0221b754(x, y - 1) == 1 && ((s8 *)data_ov007_02221a84 + (y - 1) * 30)[x] != 2 &&
        func_ov007_0221b754(x, y + 1) == 1 && ((s8 *)data_ov007_02221a84 + (y + 1) * 30)[x] != 2) {
        func_ov007_02215254(x, y, 36);
        return 1;
    }
    return 0;
}

Point15A0C func_ov007_022157fc(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 RandomIntRange(s32, s32);
    Map14E24 *m;
    u16 t;
    s32 rx, ry;
    s32 scale;
    s32 placed, tries;

    scale = arg2 * 5;

    func_ov007_02215254(arg0, arg1, (s16)(scale + 0x1c0));

    placed = 0;
    tries = 0;
    for (placed = 0; placed < arg3; placed++) {
        s32 base;
        base = scale + 0xc1;
        rx = RandomIntRange(arg0 - 2, arg0 + 2);
        ry = RandomIntRange(arg1 - 2, arg1 + 2);
        if (rx < 0) { placed--; continue; }
        m = (Map14E24 *)*gCurrentMap;
        if (rx >= m->width) { placed--; continue; }
        if (ry < 0) { placed--; continue; }
        if (ry >= m->height) { placed--; continue; }
        t = m->cells[rx + m->rows[ry]];
        if (t != 1 || ry < 0 || ry >= m->height || rx < 0 || rx >= m->width) {
            tries++;
            if (tries > 100) { placed--; break; }
            placed--;
            continue;
        }
        func_ov007_02215254(rx, ry, (s16)(base + 0x100));
    }

    placed = 0;
    tries = 0;
    {
        s32 base = scale + 0xc3;
        for (placed = 0; placed < arg4; placed++) {
            rx = RandomIntRange(arg0 - 2, arg0 + 2);
            ry = RandomIntRange(arg1 - 2, arg1 + 2);
            m = (Map14E24 *)*gCurrentMap;
            t = m->cells[rx + m->rows[ry]];
            if (t != 1 || ry < 0 || ry >= m->height || rx < 0 || rx >= m->width) {
                tries++;
                if (tries > 100) { placed--; break; }
                placed--;
                continue;
            }
            func_ov007_02215254(rx, ry, (s16)(base + 0x100));
        }
    }

    {
        Point15A0C result;
        result.x = (u16)arg0;
        result.y = (u16)arg1;
        return result;
    }
}

#pragma opt_common_subs on
Point15A0C func_ov007_02215a0c(s32 a,s32 b,s32 c) {
s32 RandomIntRange(s32,s32);Point15A0C func_ov007_022157fc(s32,s32,s32,s32,s32);
s32 tries=0,i,j;s32 *map;s32 x,y,yy,xx;Point15A0C result;
retry:
if(++tries>100){volatile Point15A0C empty;volatile u16 *p=(volatile u16 *)&empty;*p++=0;*p=0;return empty;}
x=RandomIntRange(0,M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1);
y=RandomIntRange(0,M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1);
for(j=y-1;j<=y+1;j++){
if(j<0)goto retry;map=gCurrentMap;if(j>=((Map14E24 *)*map)->height)goto retry;
for(i=x-1;i<=x+1;i++){
if(i<0||i>=((Map14E24 *)*map)->width)goto retry;
if(M2C_FIELD((u8 *)*map+((Map14E24 *)*map)->rows[j]+i,u8 *,0x1420)&0xe0)goto retry;
}}
for(yy=y-1;yy<=y+1;yy++)for(xx=x-1;xx<=x+1;xx++)func_ov007_02215254(xx,yy,1);
return func_ov007_022157fc(x,y,a,b,c);
}
#pragma opt_common_subs reset
s32 func_ov007_02215bc4(s32 *x,s32 *y,s32 value) {
 s32 RandomIntRange(s32,s32);
 extern s32 *gCurrentMap;
 s32 n=0;
 s32 a=0,b=0;
 do {
 if(++n>100) return 0;
 *x=RandomIntRange(a,M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1);
 *y=RandomIntRange(b,M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1);
 } while(value!=M2C_FIELD((*gCurrentMap+((*x+M2C_FIELD((*gCurrentMap+(*y*2)),u16 *,0x3758))*2)),u16 *,0xA10));
 return 1;
}

/* Pick a random non-border tile whose 3x3 neighbourhood all equals tileValue, at least Map_MinDistanceThreshold(50) Manhattan distance from avoidPoint when given; retry up to 100 times. Returns 1 on success, 0 otherwise. */
s32 Map_PickRandomInteriorTile(s32 *outX, s32 *outY, s32 tileValue, s16 *avoidPoint) {
    s32 RandomIntRange(s32, s32);
    s32 ManhattanDistance(s16, s16, s16, s16);
    s32 Map_MinDistanceThreshold(s32);
    s32 tries = 0, x, y, dist;
retry:
    if (++tries > 100) return 0;
    *outX = RandomIntRange(0, M2C_FIELD(*gCurrentMap, u16 *, 0x5144) - 1);
    *outY = RandomIntRange(0, M2C_FIELD(*gCurrentMap, u16 *, 0x5146) - 1);
    if (*outX == 0 || *outX == M2C_FIELD(*gCurrentMap, u16 *, 0x5144) - 1 ||
        *outY == 0 || *outY == M2C_FIELD(*gCurrentMap, u16 *, 0x5146) - 1) goto retry;
    if (avoidPoint) {
        dist = ManhattanDistance(avoidPoint[0], avoidPoint[1], (s16)*outX, (s16)*outY);
        if (dist < Map_MinDistanceThreshold(50)) goto retry;
    }
    for (y = *outY - 1; y <= *outY + 1; y++)
        for (x = *outX - 1; x <= *outX + 1; x++)
            if (tileValue != ((Map14E24 *)*gCurrentMap)->cells[x + ((Map14E24 *)*gCurrentMap)->rows[y]]) goto retry;
    return 1;
}

