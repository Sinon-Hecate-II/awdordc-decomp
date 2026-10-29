/* 44 functions from 0x02169020 to 0x02169F94 (ov000), found by ds-decomp. */
#include "common.h"

static inline s8 ReadMovementCommand(void *p) {
    return ((s8 *)p + 0x58)[M2C_FIELD(p,u8*,0x40)++];
}

void func_ov000_02169020(void *arg0) {
    s32 func_020c98b4();
    if (func_020c98b4() == 0) {
        M2C_FIELD(arg0, s8 *, 0x41) = 3;
    }
}

void func_ov000_0216903c(void *arg0) {
    s32 func_0207b7c4();
    if (func_0207b7c4() == 0) {
        M2C_FIELD(arg0, s8 *, 0x41) = 2;
    }
}

void func_ov000_02169058(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0x48) = (u16) (M2C_FIELD(arg0, u16 *, 0x48) - 1);
}

void func_ov000_02169068(void) {

}

void func_ov000_0216906c(void) {

}

void func_ov000_02169070(void *p) {
 extern s16 data_ov000_021ae960[];
 u16 t;
 M2C_FIELD(p,u16 *,0x48)+=M2C_FIELD(p,s16 *,0x4a);
 M2C_FIELD(p,s16 *,0x4c)+=M2C_FIELD(p,s16 *,0x4a)*data_ov000_021ae960[M2C_FIELD(p,s8 *,0x44)*2];
 M2C_FIELD(p,s16 *,0x4e)+=M2C_FIELD(p,s16 *,0x4a)*data_ov000_021ae960[M2C_FIELD(p,s8 *,0x44)*2+1];
 t=M2C_FIELD(p,u16 *,0x48);
 t=t;
 if (t<16) return;
 M2C_FIELD(p,u16 *,0x48)=t-16;
 M2C_FIELD(p,s16 *,0x4c)-=M2C_FIELD(p,u16 *,0x48)*data_ov000_021ae960[M2C_FIELD(p,s8 *,0x44)*2];
 M2C_FIELD(p,s16 *,0x4e)-=M2C_FIELD(p,u16 *,0x48)*data_ov000_021ae960[M2C_FIELD(p,s8 *,0x44)*2+1];
 M2C_FIELD(p,u16 *,0x48)=0;
}

#pragma optimization_level 3
void func_ov000_02169138(void *p) {
void func_020c98d8(s32,s32,s32);
s32 func_020d19b4(u32);
void func_02091c20(s32,s32);
void func_ov000_02169740(void *);
void func_ov000_021696f8(void *);
void func_020cfd28(void);
void func_ov000_0216a040(void *);
void func_02091700(s32,s32);
extern s32 *gCurrentMap;
s16 command; u32 idx;
command=ReadMovementCommand(p);
switch(command){
default: break;
case 9:
M2C_FIELD(p,s16*,0x48)=ReadMovementCommand(p);
M2C_FIELD(p,u8*,0x41)=3;break;
case 10:
M2C_FIELD(p,u8*,0x41)=5;
func_020c98d8(M2C_FIELD(p,s16*,0x4c)>>4,M2C_FIELD(p,s16*,0x4e)>>4,0);
if(func_020d19b4(M2C_FIELD((void*)*gCurrentMap,u16*,0x52a4)))func_02091c20(14,1);
break;
case 4:func_ov000_02169740(p);break;
case -1:func_ov000_021696f8(p);func_020cfd28();break;
case 0:case 1:case 2:case 3:
func_ov000_0216a040(p);
if(command!=M2C_FIELD(p,s8*,0x44)){
func_02091700(M2C_FIELD(p,s32*,0x34),command);
func_02091700(M2C_FIELD(p,s32*,0x38),command+4);
M2C_FIELD(p,s8*,0x44)=command;M2C_FIELD(p,u8*,0x41)=2;
}break;
case 5:case 6:case 7:case 8:
command-=5;
if(command!=M2C_FIELD(p,s8*,0x44)){
func_02091700(M2C_FIELD(p,s32*,0x34),command);
func_02091700(M2C_FIELD(p,s32*,0x38),command+4);
M2C_FIELD(p,s8*,0x44)=command;
}break;
}
}
#pragma optimization_level reset
void func_ov000_021692a8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s8 *, 0x41) = 1;
    M2C_FIELD(arg0, s16 *, 0x48) = 0;
}

void func_ov000_021692c0(void *p) {
 void func_ov000_02169138(void *);
 s32 func_ov000_02169ae4(void *);
 void func_ov000_02169a28(void *);
 extern void (*data_ov000_021ae970[])(void *);
 u32 n=M2C_FIELD(p,u8 *,0x41);
 if(n!=0) {
 if((u8)(n+0xFE)<=1 && M2C_FIELD(p,u16 *,0x48)==0) {
 func_ov000_02169138(p);
 if(M2C_FIELD(p,s32 *,4)==0)return;
 }
 data_ov000_021ae970[M2C_FIELD(p,u8 *,0x41)](p);
 }
 if(func_ov000_02169ae4(p))func_ov000_02169a28(p);
}

void func_ov000_02169334(void *p) {
 extern s32 *gCurrentMap;
 M2C_UNK func_ov000_02169f94();
 void func_ov000_02169cd4(void *);
 func_ov000_02169f94(p);
 func_ov000_02169cd4(p);
 M2C_FIELD(gCurrentMap,u8 **,8)[M2C_FIELD(p,s8 *,0x45)]=0;
}

extern int *gCurrentMap;
void func_ov000_02169368(void)
{
    unsigned short i = 0;

    do {
        unsigned char *ptr =
            *(unsigned char **)((unsigned char *)gCurrentMap + 8);

        ptr[i] = 0;
        i++;
    } while (i < 3);
}

void *func_ov000_021694b0(s32,s32,s32,s32);
void *func_ov000_0216939c(u8 *p) {
 extern s32 *gCurrentMap;
 s32 n; void *q;
 M2C_FIELD(p,u16 *,4)|=6;
 if(!p)n=0;
 else n=((s32)p-(s32)((u8 *)*gCurrentMap+0x59A4))/14;
 q=func_ov000_021694b0(p[1],p[2],(n>>6)+1,(u32)(p[0]<<26)>>26);
 if(!q)return 0;
 M2C_FIELD(q,void **,0x3C)=p;
 return q;
}

void *func_ov000_0216941c(s32 a,s32 b,s32 c,s32 d,s32 e) {
 s32 func_ov000_0216975c(void);
 void *func_01ffa3dc(M2C_UNK *,s32);
 s32 func_ov000_02169f08(void *);
 void func_ov000_02169bc4(void *);
 extern M2C_UNK data_ov000_021ae988;
 void *p;
 s32 slot=func_ov000_0216975c();
 if(slot==-1)return 0;
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,8),u8 *,slot)=1;
 p=func_01ffa3dc(&data_ov000_021ae988,9);
 M2C_FIELD(p,u8 *,0x45)=slot;
 M2C_FIELD(p,u16 *,0x4C)=a<<4;
 M2C_FIELD(p,u16 *,0x4E)=b<<4;
 M2C_FIELD(p,u8 *,0x42)=d;
 M2C_FIELD(p,u8 *,0x43)=c;
 M2C_FIELD(p,u8 *,0x44)=e;
 M2C_FIELD(p,u16 *,0x4A)=func_ov000_02169f08(p);
 func_ov000_02169bc4(p);
 return p;
}

void *func_ov000_021694b0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    void *func_ov000_0216941c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    return func_ov000_0216941c(arg0, arg1, arg2, arg3, func_ov000_021694e8(arg2));
}

s32 func_ov000_021694e8(s32 arg0) {
    extern s32 *gCurrentMap;
    if (M2C_FIELD(((arg0 * 0x8C) + *gCurrentMap), u8 *, 0x67CC) != 0) {
        return 1;
    }
    return 0;
}

void func_ov000_02169518(s32 arg0) {
 void func_ov000_02169540(void *,s32);
 extern M2C_UNK data_ov000_021ae988;
 void *p=(void *)func_01ffa770(&data_ov000_021ae988);
 if(!p)return;
 func_ov000_02169540(p,arg0);
}

void func_ov000_02169540(void *p, s32 arg1){
s32 func_020a7d38(void *);s32 func_020a7d68(void *);s32 func_020946d0(void);void func_0207b764(s32,s32);s32 func_020d19b4(u32);void func_020d4790(void);
extern u8 data_02168f0c[];
s32 func_ov000_021697a0(volatile s8 *);s32 func_ov000_02169940(s8 *);int func_ov000_02169854(int,int,const signed char *);void func_ov000_02169804(void *,void *);void func_ov000_02169f88(void);
s8 *path=(s8*)arg1;
s32 x=M2C_FIELD(p,s16 *,0x4c)/16,y=M2C_FIELD(p,s16 *,0x4e)/16;u8 ok;
if(func_ov000_021697a0(path)==0 && func_ov000_02169940(path)==0)return;
M2C_FIELD(p,u8 *,0x40)=0;M2C_FIELD(p,u8 *,0x41)=4;M2C_FIELD(p,u8 *,0x46)=1;
if(data_02168f0c[0]){
if(data_02168f0c[0]){if(M2C_FIELD((void*)*gCurrentMap,u16 *,0x52b0)!=19)ok=1;else ok=0;}else ok=0;
if(!(ok&255))M2C_FIELD(p,u8 *,0x46)=0;
}
if(!func_ov000_02169854(x,y,path))M2C_FIELD(p,u8 *,0x46)=0;
if(M2C_FIELD(p,void **,0x3c) && func_020a7d38(M2C_FIELD(p,void **,0x3c)) && !func_020a7d68(M2C_FIELD(p,void **,0x3c)))M2C_FIELD(p,u8 *,0x46)=0;
if(func_020946d0())M2C_FIELD(p,u8 *,0x46)=0;
if(M2C_FIELD(p,u8 *,0x46))func_0207b764(x,y);
if(func_020d19b4(M2C_FIELD((void*)*gCurrentMap,u16 *,0x52a4)))func_02091c20(15,func_ov000_021697a0(path));
func_ov000_02169804(path,(u8*)p+0x58);
func_020d4790();
((void(*)(void*))func_ov000_02169f88)(p);
}

void *func_ov000_021696b0(s32 a,s32 b,s32 c,s32 d,s32 e) {
 void func_ov000_02169540(void *,s32);
 void *p=func_ov000_021694b0(a,b,c,d);
 if(!p)return 0;
 func_ov000_02169540(p,e);
 return p;
}

void func_ov000_021696d4(void) {
 s32 func_01ffa770(M2C_UNK *);
 void func_ov000_021696f8(void *);
 extern M2C_UNK data_ov000_021ae988;
 void *p=(void *)func_01ffa770(&data_ov000_021ae988);
 if(!p)return;
 func_ov000_021696f8(p);
 func_ov000_021696d4();
}

void func_ov000_021696f8(void *arg0) {
 void func_01ffa574(void *);
 M2C_UNK func_020d47b0();
 void *p=M2C_FIELD(arg0,void **,0x3C);
 if(p) M2C_FIELD(p,u16 *,4)&=~6;
 func_01ffa574(arg0);
 func_020d47b0();
}

u8 func_ov000_0216971c(void) {
    s32 func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov000_021ae988;
    u8 var_r0;

    if (func_01ffa770(&data_ov000_021ae988) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov000_02169740(void *arg0) {
    M2C_UNK func_020d47b0();
    M2C_UNK func_ov000_02169f94();
    func_ov000_02169f94();
    M2C_FIELD(arg0, s8 *, 0x41) = 1;
    func_020d47b0();
}

s32 func_ov000_0216975c(void) {
 u16 i=0;
 u8 *p=M2C_FIELD(gCurrentMap,u8 **,8);
 do {if(p[i]==0)return (s16)i; i++;}while(i<3);
 return -1;
}

s32 func_ov000_021697a0(volatile s8 *p) {
    s32 count = 0;
loop:
    switch (*p++) {
    case 9:
        p++;
        break;
    case -1:
    case 4:
    case 10:
        return count;
    case 0:
    case 1:
    case 2:
    case 3:
        count++;
        break;
    }
    goto loop;
    return count;
}

void func_ov000_02169800(void) {

}

void func_ov000_02169804(void *arg0,void *arg1) {
 s8 *src=arg0,*dst=arg1; s8 token;
loop:
 token=*src;
 if (token==-1 || token==4) goto end;
 if (token!=9) goto normal;
 dst[0]=token;
 { s8 next=src[1]; src+=2; dst[1]=next; dst+=2; }
 goto loop;
end:
 *dst=*(volatile s8 *)src;
normal:
 src++;
 *dst++=token;
 goto loop;
}

void func_ov000_02169850(void) {

}

extern u32* D_027E0058;
int func_ov000_02169854(int x,int y,const signed char *cmd) {
u8 *map=(u8 *)*gCurrentMap;
u32 pos;
if(*(u8 *)(map+*(u16 *)(map+0x52a4)*140+0x67c3)&2)return 1;
for(;;){
pos=x+*(u16 *)(map+y*2+0x3758);
if((u8)(map[(pos>>3)+0x5201] & (1<<(pos&7))))return 1;
switch(*cmd++){
case 9:cmd++;break;
case -1: case 4:return 0;
case 10:return 1;
case 0:x--;break;
case 1:x++;break;
case 2:y++;break;
case 3:y--;break;
}
}
}

s32 func_ov000_02169940(s8 *p) {
 loop: switch(*p++) {
 case 9: p++; goto loop;
 case -1: case 4: return 0;
 case 10: return 1;
 default: goto loop;
 }
}

void func_ov000_02169998(u8 *p,s8 *q) {
  for (;;) {
    switch (*q++) {
    case 9: q++; break;
    case -1:
    case 4:
      return;
    case 0:
      p[1]--;
      break;
    case 1:
      p[1]++;
      break;
    case 2:
      p[2]++;
      break;
    case 3:
      p[2]--;
      break;
    default:
      break;
    }
  }
}

void func_ov000_02169a24(void) {

}

void func_ov000_02169a28(void *p) {
 s32 func_0207cfb8(void *);
 void func_02091248(s32);
 void func_020910d0(void *,s32 *,s32,s32);
 s32 v[3]; void *q; s32 n;
 u8 mode=func_0207cfb8((void *)(*gCurrentMap+0x6EF8))<=0?0x10:0x18;
 if(mode==0x10){q=M2C_FIELD(p,void **,0x34);n=0x30000;}
 else{q=M2C_FIELD(p,void **,0x38);n=0x20000;}
 if(M2C_FIELD(p,u8 *,0x47)!=mode){M2C_FIELD(q,u8 *,0x22)|=1;M2C_FIELD(p,u8 *,0x47)=mode;}
 v[0]=(M2C_FIELD(p,s16 *,0x4C)+8)*48;
 v[1]=(M2C_FIELD(p,s16 *,0x4E)+16)*48;
 v[2]=0x871;
 func_02091248(31);
 func_020910d0(q,v,n,0);
}

s32 func_ov000_02169ae4(void *p) {
    s32 func_020a5d8c(s32, s32, s32);
    void func_ov000_02169d74(s32, s32);
    s32 cx;
    s32 cy;
    u8 *base;
    u8 flags;
    u32 a;
    u32 idx;
    u8 hit;
    s32 r;

    cx = (M2C_FIELD(p, s16 *, 0x4C) + 8) / 16;
    cy = (M2C_FIELD(p, s16 *, 0x4E) + 8) / 16;
    base = (u8 *)*gCurrentMap;
    flags = M2C_FIELD(base + M2C_FIELD(base + 0x5200, u16 *, 0xA4) * 0x8C, u8 *, 0x67C3);
    a = M2C_FIELD(p, u32 *, 0x3C);
    r = 1;
    if (!(flags & 2)) {
        idx = cx + M2C_FIELD(base + cy * 2 + 0x3700, u16 *, 0x58);
        hit = M2C_FIELD(base + (idx >> 3) + 0x5000, u8 *, 0x201) & (1 << (idx & 7));
        if (!hit || func_020a5d8c(a, (s16)cx, (s16)cy) == 0) {
            r = 0;
        }
    }
    if (M2C_FIELD(p, u8 *, 0x41) == 2 && M2C_FIELD(p, u8 *, 0x46) != 0) {
        func_ov000_02169d74(M2C_FIELD(p, s16 *, 0x4C), M2C_FIELD(p, s16 *, 0x4E));
    }
    return r;
}

void func_ov000_02169bc4(void *p){
s32 func_02091270(s32,s32,s32);void func_02091700(s32,s32);void func_0207c55c(void *,s32,s32,s32);
extern u8 data_02120a20[];
void *player;s32 a;
M2C_FIELD(p,s32 *,0x50)=func_ov000_02169d00((s32)p);
M2C_FIELD(p,s32 *,0x54)=func_ov000_02169d28(p);
M2C_FIELD(p,s32 *,0x34)=func_02091270(M2C_FIELD(p,s32 *,0x54),15,14);
M2C_FIELD(p,s32 *,0x38)=func_02091270(M2C_FIELD(p,s32 *,0x54),15,14);
M2C_FIELD(p,u8 *,0x47)=0;
func_02091700(M2C_FIELD(p,s32 *,0x34),M2C_FIELD(p,s8 *,0x44));
M2C_FIELD(M2C_FIELD(p,void **,0x34),s32 *,0x30)=M2C_FIELD(p,s32 *,0x50);
M2C_FIELD(M2C_FIELD(p,void **,0x34),s32 *,0x28)=func_ov000_02169d50(p);
M2C_FIELD(M2C_FIELD(p,void **,0x34),s32 *,0x2c)=func_ov000_02169d64(p);
func_02091700(M2C_FIELD(p,s32 *,0x38),M2C_FIELD(p,s8 *,0x44)+4);
M2C_FIELD(M2C_FIELD(p,void **,0x38),s32 *,0x30)=M2C_FIELD(p,s32 *,0x50);
M2C_FIELD(M2C_FIELD(p,void **,0x38),s32 *,0x28)=func_ov000_02169d50(p);
M2C_FIELD(M2C_FIELD(p,void **,0x38),s32 *,0x2c)=func_ov000_02169d64(p);
player=(u8*)M2C_FIELD(gCurrentMap,void **,0)+0x67a4+M2C_FIELD(p,u8 *,0x43)*140;
a=func_ov000_02169d64(p);
func_0207c55c(data_02120a20+(M2C_FIELD(player,u8 *,0x1d)-1)*32,a,32,0);
}

void func_ov000_02169cd4(void *arg0) {
    void func_020912a4(s32 *);
    M2C_UNK func_020e35cc(s32);
    func_020912a4(M2C_FIELD(arg0, s32 *, 0x34));
    func_020912a4(M2C_FIELD(arg0, s32 *, 0x38));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x54));
    func_020e35cc(M2C_FIELD(arg0, s32 *, 0x50));
}

s32 func_ov000_02169d00(M2C_UNK arg0) {
    M2C_UNK func_0200bc5c(M2C_UNK *);
    M2C_UNK func_02081070(s32, M2C_UNK);
    s32 func_ov000_02169ec0(M2C_UNK);
    extern M2C_UNK data_ov000_021aeee0;
    func_0200bc5c(&data_ov000_021aeee0);
    func_02081070(func_ov000_02169ec0(arg0), 1);
}

s32 func_ov000_02169d28(void *arg0) {
    M2C_UNK func_02080e30(s32, M2C_UNK);
    s32 func_ov000_02169f64(u8);
    extern M2C_UNK data_ov000_021aeee4;
    func_0200bc5c(&data_ov000_021aeee4);
    func_02080e30(func_ov000_02169f64(M2C_FIELD(arg0, u8 *, 0x42)), 1);
}

s32 func_ov000_02169d50(void *arg0) {
    return (M2C_FIELD(arg0, s8 *, 0x45) << 0xB) + 0x30D20;
}

s32 func_ov000_02169d64(void *arg0) {
    return (M2C_FIELD(arg0, s8 *, 0x45) << 5) + 0x14C0;
}

#pragma push
#pragma opt_common_subs off
void func_ov000_02169d74(s32 x,s32 y){
s32 func_0207d0b8(void);s32 func_0207d0d4(void);
s32 w=func_0207d0b8(),h=func_0207d0d4();
s16 nx=10000,ny=10000;
void *map=M2C_FIELD(gCurrentMap,void **,0);s16 ox=M2C_FIELD(map,s16 *,0x5148),oy; s32 dx=x-ox,dy;void (*cb)(void);
if(dx<16)nx=x-16;
if(dx>((w-2)<<4))nx=x-((w-2)<<4);
oy=M2C_FIELD(map,s16 *,0x514a);dy=y-oy;
if(dy<16)ny=y-16;
if(dy>((h-2)<<4))ny=y-((h-2)<<4);
if(nx==10000 && ny==10000)return;
if(nx==10000)nx=ox;
else if(nx<0)nx=0;
else if(nx>((M2C_FIELD(map,u16 *,0x5144)-w)<<4))nx=(M2C_FIELD(map,u16 *,0x5144)-w)<<4;
if(ny==10000)ny=oy;
else if(ny<0)ny=0;
else if(ny>((M2C_FIELD(map,u16 *,0x5146)-h)<<4))ny=(M2C_FIELD(map,u16 *,0x5146)-h)<<4;
M2C_FIELD(map,s16 *,0x5148)=nx;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,0x514a)=ny;
cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),void (**)(void),0x1c);
if(cb)cb();
}
#pragma pop
s32 func_ov000_02169ec0(M2C_UNK p) {
 s32 func_020a7298(s32,s32);
 extern s32 data_ov000_021aec88[];
 return M2C_FIELD(data_ov000_021aec88,s32 *,func_020a7298(M2C_FIELD(p,u8 *,0x42),M2C_FIELD(*gCurrentMap+M2C_FIELD(p,u8 *,0x43)*0x8C,u8 *,0x67CD))*20);
}

s32 func_ov000_02169f08(void *p) {
 s32 func_020a7298(s32,s32);
 s32 func_020cd674(void);
 extern M2C_UNK data_ov000_021aec90;
 s32 value;
 void *base=M2C_FIELD(gCurrentMap,void **,0);
 s32 index=func_020a7298(M2C_FIELD(p,u8 *,0x42),M2C_FIELD(base+M2C_FIELD(p,u8 *,0x43)*0x8C,u8 *,0x67CD));
 value=M2C_FIELD(&data_ov000_021aec90,u8 *,index*20);
 if(func_020cd674()!=0)value<<=1;
 return (s16)value;
}

s32 func_ov000_02169f64(u8 arg0) {
 s32 func_020a7298(s32,s32);
 extern M2C_UNK data_ov000_021aec8c;
 return M2C_FIELD(&data_ov000_021aec8c,s32 *,func_020a7298(arg0,1)*20);
}

void func_ov000_02169f88(void) {
    M2C_UNK func_ov000_0216a1ac();
    func_ov000_0216a1ac();
}

