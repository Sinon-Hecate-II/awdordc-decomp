/* 23 functions from 0x020CAB8C to 0x020CBACC (main), found by ds-decomp. */
#include "common.h"
typedef struct UnitCB9 { u8 kind:6; u8 owner:2; u8 x,y,pad; u16 flags; u16 hp; u8 tail[6]; } UnitCB9;
typedef struct UnitHealthCB { u8 pad[6]; u16 health:7; u16 flags:9; } UnitHealthCB;
extern u8 data_0212b1b8[][4];

void func_020cab8c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212b4a4;
    func_01ffa3dc(&data_0212b4a4, 7);
}

#pragma optimization_level 4
s32 func_020caba4(s32 a,s32 b,s32 c){
 extern void **gCurrentMap;
 s32 i=0;void *p;register u8 *q;
 do{
 if(c&data_0212b1b8[i][0]){
 p=*gCurrentMap;q=(u8 *)data_0212b1b8+((u32)i<<2);
 if(a==M2C_FIELD(p,s16 *,0x52dc)+M2C_FIELD(q,s8 *,2) && b==M2C_FIELD(p,s16 *,0x52de)+M2C_FIELD(q,s8 *,3))return i;
 } i++;
 }while(i<4);return -1;
}
s32 func_020cac1c(s32 a,s32 b){do{a=(a+1)&3;}while(!(b&data_0212b1b8[a][0]));return a;}

s32 func_020cac3c(s32 a,s32 b){do{a=(a-1)&3;}while(!(b&data_0212b1b8[a][0]));return a;}

void func_020cac5c(void *arg0) {
 M2C_UNK func_01ffb3d0(M2C_UNK); M2C_UNK func_01ffb554(void *); M2C_UNK func_0207a748(M2C_UNK);
 s32 func_020ba1fc(s16,s16,u8); M2C_UNK func_020cdf30(s16,s16,s32);
 extern void **gCurrentMap;
 s32 n;void *p;
 p=*gCurrentMap;
 n=func_020ba1fc(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de),M2C_FIELD((M2C_FIELD(p,s32 *,0x52d0)+M2C_FIELD(arg0,s16 *,0x70)),u8 *,0xc));
 func_01ffb554((u8 *)*gCurrentMap+0x1e30);func_01ffb3d0(-1);
 p=*gCurrentMap;func_020cdf30(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de),n);func_0207a748(0);
 M2C_FIELD(arg0,s16 *,0x6c)=n;M2C_FIELD(arg0,s16 *,0x6e)=3;
 M2C_FIELD(arg0,s16 *,0x6e)=func_020cac1c(M2C_FIELD(arg0,s16 *,0x6e),n);
}

void func_020cad00(s32 arg0) {
    M2C_UNK func_0208fb0c(M2C_UNK);
    if ((arg0 != 1) && (arg0 != 2)) {
        return;
    }
    func_0208fb0c(0x7C);
}

s32 func_020cad1c(s32 *arg0, s32 arg1) {
    s32 func_020bcbd8(void);
    s32 func_020cac1c(s32, s32);
    s32 func_020cac3c(s32, s32);
    void func_020bda88(s32 *, s32);
    void func_0208fe30(s32);
    void func_020cf5ec(s32);
    s32 func_020bcb94(void);
    s32 func_020bdbf4(s32);
    extern void **gCurrentMap;
    extern s8 data_0212b1ba[];
    extern s8 data_0212b1bb[];
    s32 sp0;
    s32 old;
    s32 result_r6;
    void *map;

    sp0 = *arg0;
    old = *arg0;
    result_r6 = func_020bcbd8();
    if (result_r6 & 8) {
        sp0 = func_020cac1c(sp0, arg1);
    }
    if (result_r6 & 4) {
        sp0 = func_020cac3c(sp0, arg1);
    }
    func_020bda88(&sp0, arg1);
    if (sp0 != old) {
        *arg0 = sp0;
        func_0208fe30(0x1001A);
    }
    map = *gCurrentMap;
    M2C_FIELD(map, s16 *, 0x52C2) = (s16)(M2C_FIELD(map, s16 *, 0x52DC) + data_0212b1ba[sp0 * 4]);
    map = *gCurrentMap;
    M2C_FIELD(map, s16 *, 0x52C4) = (s16)(M2C_FIELD(map, s16 *, 0x52DE) + data_0212b1bb[sp0 * 4]);
    func_020cf5ec(1);
    result_r6 = func_020bcb94();
    result_r6 = result_r6 | func_020bdbf4(arg1);
    if (result_r6 & 0x20) {
        return 0x20;
    }
    if (result_r6 & 0x10) {
        return 0x10;
    }
    return 0;
}

void func_020cae2c(void *p){
extern void **gCurrentMap; extern s32 data_0215be0c;
M2C_UNK func_020d472c();M2C_UNK func_020c75cc();void func_01ffa574(void *);void func_01ffa6fc(void *);void func_020c93fc(u8,u8);
s32 mask=M2C_FIELD(p,s16 *,0x6c); s32 a=M2C_FIELD(p,s16 *,0x6e),flags; s32 selector; s32 index;u8 *units;void *map;u8 *unit;
flags=func_020cad1c(&a,mask);
M2C_FIELD(p,s16 *,0x6e)=a;
if(flags&32){
func_020d472c();func_020c75cc();
map=*gCurrentMap;M2C_FIELD(map,s16 *,0x52c2)=M2C_FIELD(map,s16 *,0x52d8);
map=*gCurrentMap;M2C_FIELD(map,s16 *,0x52c4)=M2C_FIELD(map,s16 *,0x52da);
func_01ffa574(p);return;
}
if(!(flags&16))return;
data_0215be0c=M2C_FIELD(p,s16 *,0x6e);
map=*gCurrentMap;selector=M2C_FIELD(p,s16 *,0x70);
unit=(u8*)M2C_FIELD(map,void **,0x52d0)+selector;
units=(u8*)map+0x59a4;
index=(s16)unit[12]*14;
func_020c93fc((u8)M2C_FIELD(p,s16 *,0x70),(u8)(M2C_FIELD(p,s16 *,0x6e)+1));
map=*gCurrentMap;
((void(*)(s32,s32,s32))func_020cad00)(((u32)(units[index]<<26)>>26),M2C_FIELD(map,s16 *,0x52dc),M2C_FIELD(map,s16 *,0x52de));
func_01ffa6fc(p);
}

void func_020caf3c(void *arg0) {
    M2C_UNK func_020d472c();
    s32 func_020c6384();
    s32 func_020c6414();
    M2C_UNK func_020c75cc();
    M2C_UNK func_020c9580(u8);
    M2C_UNK func_020d468c();
    M2C_UNK func_020a15e4();
    u8 func_020c9440(s16, s16, s32);
    M2C_UNK func_ov000_02199f50(s32, u8, u8, u8);
    extern void **gCurrentMap;
    void *base;
    s32 a, b;

    func_020d472c();
    if ((func_020c6384() == 0) || (func_020c6414() == 0)) {
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C2) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DC);
        M2C_FIELD(*gCurrentMap, s16 *, 0x52C4) = M2C_FIELD(*gCurrentMap, s16 *, 0x52DE);
        func_020c9580((u8) M2C_FIELD(arg0, s16 *, 0x70));
        func_020c75cc();
        return;
    }
    func_020d468c();
    func_020a15e4();
    base = *gCurrentMap;
    a = func_020c9440(M2C_FIELD(base, s16 *, 0x52DC), M2C_FIELD(base, s16 *, 0x52DE), 0);
    b = func_020c9440(M2C_FIELD(base, s16 *, 0x52DC), M2C_FIELD(base, s16 *, 0x52DE), 1);
    func_ov000_02199f50(8, M2C_FIELD(*gCurrentMap, u8 *, 0x52D4), (u8) a, (u8) b);
}

void func_020cb00c(void) {
    M2C_UNK func_0207a768();
    func_0207a768();
}

void func_020cb018(s16 arg0) {
    extern M2C_UNK data_0212b374;
    M2C_FIELD(func_01ffa3dc(&data_0212b374, 7), s16 *, 0x70) = arg0;
}

s32 func_020cb038(void *arg0,s32 arg1){
s32 func_0207c8ec(s32,s32); M2C_UNK func_020d2b10(s32,u16);
extern void **gCurrentMap; extern u16 data_ov000_021b5c02[];extern M2C_UNK data_ov000_021b5bfc;
u8 *tab;s32 sum=0;u16 cost;u32 n=(u32)(M2C_FIELD(arg0,u16 *,6)<<25);u16 h,idx;void *map;
if(arg1){n >>=25;cost=*(u16 *)((u8 *)data_ov000_021b5c02+((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*112)*(n?func_0207c8ec(n-1,10)+1:sum);
}else {n >>=25;cost=n?func_0207c8ec(n-1,10)+1:sum;}
tab=(u8 *)&data_ov000_021b5bfc;
loop:
if(((u32)(M2C_FIELD(arg0,u16 *,6)<<21)>>28)!=tab[((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)*112+9]){
if(arg1){map=*gCurrentMap;idx=M2C_FIELD(map,u16 *,0x52a4);if(M2C_FIELD((u8*)map+idx*140,s32 *,0x67a4)>=(s32)cost){func_020d2b10(idx,cost);goto update;}}
else{update:h=M2C_FIELD(arg0,u16 *,6);sum+=cost;M2C_FIELD(arg0,u16 *,6)=(h&~0x780)|((u32)((u16)(((u32)(h<<21)>>28)+1)<<28)>>21);goto loop;}}
return sum;}

s32 func_020cb170(void *arg0, s32 arg1) {
    s32 func_0207c8ec(s32, M2C_UNK);
    M2C_UNK func_020d2b10(s32, u16);
    extern void **gCurrentMap;
    extern M2C_UNK data_ov000_021b5bfc;
    u8 *tab;
    s32 var_r7;
    u32 temp_r0;
    u16 temp_r8;
    u16 temp_r0_2;
    u8 temp_r1_2;
    void *temp_r1;

    var_r7 = 0;
    temp_r0 = (u32) (M2C_FIELD(arg0, u16 *, 6) << 0x19) >> 0x19;
    temp_r8 = temp_r0 ? (func_0207c8ec(temp_r0 - 1, 0xA) + 1) : var_r7;
    tab = (u8 *) &data_ov000_021b5bfc;
loop_4:
    if (((u32) (M2C_FIELD(arg0, u8 *, 0xA) << 0x19) >> 0x19) != tab[((u32) (M2C_FIELD(arg0, u8 *, 0) << 0x1A) >> 0x1A) * 0x70 + 0xE]) {
        if (arg1 != 0) {
            temp_r1 = *gCurrentMap;
            temp_r0_2 = M2C_FIELD(temp_r1, u16 *, 0x52A4);
            if ((s32) M2C_FIELD(((temp_r0_2 * 0x8C) + (s32) temp_r1), s32 *, 0x67A4) >= (s32) temp_r8) {
                func_020d2b10(temp_r0_2, temp_r8);
                goto block_8;
            }
        } else {
block_8:
            temp_r1_2 = M2C_FIELD(arg0, u8 *, 0xA);
            var_r7 += temp_r8;
            M2C_FIELD(arg0, u8 *, 0xA) = (u8) ((temp_r1_2 & ~0x7F) | ((u8) (((u32) (temp_r1_2 << 0x19) >> 0x19) + 1) & 0x7F));
            goto loop_4;
        }
    }
    return var_r7;
}

#pragma opt_common_subs on
s32 func_020cb254(void *p,s32 count,s32 pay){
s32 func_020a7310(void);
s32 func_020d2d18(s32,u32);
s32 func_0207c8ec(s32,s32);
M2C_UNK func_020d2b10(s32,u16);
extern void **gCurrentMap;
s32 owner,total,health,level,offset;u16 cost,v;
owner=func_020a7310();total=0;
cost=func_020d2d18(owner,(u32)(M2C_FIELD(p,u8*,0)<<26)>>26);
if(count){offset=owner*140;
do{
health=((UnitHealthCB*)p)->health;
if(!health)level=0;else level=func_0207c8ec(health-1,10)+1;
if(level==10)break;
if(pay){
if(M2C_FIELD(offset+(s32)*gCurrentMap,s32*,0x67a4)<(s32)cost)break;
func_020d2b10(owner,cost);total+=cost;
}
v=M2C_FIELD(p,u16*,6);
M2C_FIELD(p,u16*,6)=(v&~127)|((u16)(((u32)(v<<25)>>25)+10)&127);
if(((UnitHealthCB*)p)->health>100)((UnitHealthCB*)p)->health=100;
}while(--count);
}
health=((UnitHealthCB*)p)->health;
if(!health)level=0;else level=func_0207c8ec(health-1,10)+1;
((UnitHealthCB*)p)->health=(u16)(level*10);
return total;
}
s32 func_020cb3a4(s32 a,s32 b){extern void **gCurrentMap;s32 func_020a7e08(void *);u8 *base=*gCurrentMap;u8 *start=base+0x59a4;u8 *p=start+(s16)base[a+((u16 *)(base+0x3758))[b]]*14;s32 index=p?(p-start)/14:0;if(M2C_FIELD(base,u16 *,0x52a8)==(index&0xc0) && func_020a7e08(p))return 1;return 0;}

s32 func_020cb430(u8 *p) {
extern u8 data_ov000_021b5c66[];
extern void **gCurrentMap;
if (!data_ov000_021b5c66[((u32)(p[0]<<26)>>26)*112]) return 0;
if(p[1] && func_020cb3a4((s16)(p[1]-1),p[2]))return 1;
if(p[2] && func_020cb3a4(p[1],(s16)(p[2]-1)))return 1;
if(p[1]<M2C_FIELD(*gCurrentMap,u16 *,0x5144)-1 && func_020cb3a4((s16)(p[1]+1),p[2]))return 1;
if(p[2]<M2C_FIELD(*gCurrentMap,u16 *,0x5146)-1 && func_020cb3a4(p[1],(s16)(p[2]+1)))return 1;
return 0;
}

#pragma opt_propagation off
s32 func_020cb550(u8 *p){
u8 func_020c98d8(u8,u8,s32);s32 func_020a7558(void *);s32 func_020cb254(void *,s32,s32);
extern void **gCurrentMap;extern M2C_UNK data_ov000_021b5bfc;extern u8 data_ov000_021b5c5c[];
u8 j;u8 *base;u8 i;u8 *q;u8 n;s32 sum; s32 other;sum=0;other=0;i=0;
if((u32)i<(u32)data_ov000_021b5c5c[((u32)(p[0]<<26)>>26)*112]){
do{q=p+i;n=q[12];if(n){
sum+=func_020cb038((u8 *)*gCurrentMap+0x59a4+n*14,0);
sum+=func_020cb170((u8 *)*gCurrentMap+0x59a4+q[12]*14,0);
if(((u32)(p[0]<<26)>>26)==21){j=q[12];base=(u8 *)*gCurrentMap+0x59a4;other+=func_020cb254(base+j*14,func_020a7558(p),1);}
}i++;}while(i<((u8 *)&data_ov000_021b5bfc)[((u32)(p[0]<<26)>>26)*112+0x60]);}
if(other)return func_020c98d8(p[1],p[2],1);
if(!sum)return 0;
return func_020c98d8(p[1],p[2],2);
}
#pragma opt_propagation reset
u8 func_020cb6a4(void *arg0) {
s32 func_020a8604(u32);
u8 func_020c98d8(u8,u8,s32);
s32 func_020cb038(void *,s32);
s32 func_020cb170(void *,s32);
s32 n=0;
if(func_020a8604((u32)(M2C_FIELD(arg0,u8 *,0)<<26)>>26)==0) n+=func_020cb038(arg0,0);
n+=func_020cb170(arg0,0);
if(n==0) return n;
return func_020c98d8(M2C_FIELD(arg0,u8 *,1),M2C_FIELD(arg0,u8 *,2),2);
}

void func_020cb704(void *a){s32 func_020ba510(s32,s32);extern s32 data_0215be0c;extern void **data_027e0058;u16 i=0;data_0215be0c=0;do{void *p=*data_027e0058;s32 n=func_020ba510(M2C_FIELD(p,s16 *,0x52dc)+(s8)data_0212b1b8[i][2],M2C_FIELD(p,s16 *,0x52de)+(s8)data_0212b1b8[i][3]);data_0215be0c |= data_0212b1b8[i][0]*n;i++;}while(i<4);M2C_FIELD(a,s16 *,0x34)=0;}

void func_020cb78c(void *arg0){
void func_01ffa574(void *);void func_020bac24(void);s32 func_020c98b4(void);M2C_UNK func_020d468c();M2C_UNK func_ov000_02199f50(s32,u8,u8,u8);
extern s32 data_0215be0c;extern void **gCurrentMap;
s32 i;u8 *m;u8 *q;s32 x;void *p;
if(func_020c98b4())return;
loop:
i=M2C_FIELD(arg0,s16 *,0x34);
if(i>=4){
if(!M2C_FIELD(arg0,s16 *,0x36)){
p=*gCurrentMap;M2C_FIELD(p,s16 *,0x52c2)=M2C_FIELD(p,s16 *,0x52dc);
p=*gCurrentMap;M2C_FIELD(p,s16 *,0x52c4)=M2C_FIELD(p,s16 *,0x52de);}
func_01ffa574(arg0);func_020bac24();
if(!M2C_FIELD(arg0,s16 *,0x36))func_ov000_02199f50(6,M2C_FIELD(*gCurrentMap,u8 *,0x52d4),0,0);
func_020d468c();
return;
}
if(data_0215be0c&((u8 *)data_0212b1b8)[(u32)i<<2]){
m=*gCurrentMap;q=(u8 *)data_0212b1b8+i*4;
x=(s32)(m+M2C_FIELD(m,s16 *,0x52dc));func_020cb6a4(M2C_FIELD((M2C_FIELD(m+2*(M2C_FIELD(m,s16 *,0x52de)+M2C_FIELD(q,s8 *,3)),u16 *,0x3758)+(M2C_FIELD(q,s8 *,2)+x)),u8 *,0x508)*14+(m+0x59a4));
M2C_FIELD(arg0,s16 *,0x34)++;
}else{M2C_FIELD(arg0,s16 *,0x34)++;}goto loop;
}

void func_020cb8cc(s32 a) {
extern M2C_UNK data_0212b3ac;
void *p=func_01ffa3dc(&data_0212b3ac,7);
if(a) M2C_FIELD(p,s16 *,0x36)=0;
else M2C_FIELD(p,s16 *,0x36)=1;
}

void func_020cb8f8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x50) = 1;
}

void func_020cb904(void *state){
extern void **gCurrentMap;extern M2C_UNK data_ov000_021b5bfc;
u16 i; s32 a,b; UnitCB9 *unit; s32 n;u8 *map;
if(func_020c98b4(state))return;
for(i=M2C_FIELD(state,u16 *,0x50);i<51;i++){
map=*gCurrentMap;
unit=(UnitCB9 *)(map+0x59a4+(M2C_FIELD(map,u16 *,0x52a8)+i)*14);
if(!unit->kind || (unit->flags&8))continue;
a=0;b=0;
if(func_020d280c(M2C_FIELD(map,u16 *,0x52a4),unit->x,unit->y)){
s32 kind=unit->kind; s32 x; s32 y; s32 terrain; s8 *table;
map=*gCurrentMap; x=unit->x;y=unit->y;
terrain=M2C_FIELD(map+x+M2C_FIELD(map+y*2,u16 *,0x3758),u8 *,0x1420)&31;
table=M2C_FIELD((u8 *)&data_ov000_021b5bfc+kind*112,s8 **,0x58);
if(table[terrain]){
if(!func_020a8604(kind)){
a+=func_020cb038(unit,0);
}
a+=func_020cb170(unit,0);
b+=func_020cb254(unit,func_020a7558(unit),1);
}
}
n=func_020a2668(unit,unit->x,unit->y);
if(n)b+=func_020cb254(unit,n,1);
if(a||b){
if(b)func_020c98d8(unit->x,unit->y,1);
else func_020c98d8(unit->x,unit->y,2);
M2C_FIELD(state,u16 *,0x50)=i+1;
break;
}
}
if(i==51)func_01ffa6fc(state);
}

