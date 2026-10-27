/* 19 functions from 0x020BBBBC to 0x020BCB94 (main), found by ds-decomp. */
#include "common.h"
static inline s16 BC454Direction(s16 *p,s32 dir) { return p[dir*2]; }

void func_020bbbbc(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    M2C_UNK func_02091c20(M2C_UNK, M2C_UNK);
    void *func_01ffa444(M2C_UNK *, M2C_UNK);
    s32 func_020d19b4(u16);
    extern s32 *gCurrentMap;
    extern M2C_UNK data_0212b00c;
    void *temp_r0;

    if (func_020d19b4(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) != 0) {
        func_02091c20(0xD, 1);
    }
    temp_r0 = func_01ffa444(&data_0212b00c, arg4);
    M2C_FIELD(temp_r0, s16 *, 0x6C) = arg0;
    M2C_FIELD(temp_r0, s16 *, 0x6E) = arg1;
    M2C_FIELD(temp_r0, s32 *, 0x34) = arg2;
    M2C_FIELD(temp_r0, s32 *, 0x38) = arg3;
    M2C_FIELD(temp_r0, s16 *, 0x52) = 0x1E;
}

void func_020bbc2c(M2C_UNK arg0) {
    M2C_UNK func_02091c20(M2C_UNK, M2C_UNK);
    M2C_UNK func_020a348c(M2C_UNK);
    M2C_UNK func_020cfd28();
    s32 func_020d19b4(u16);
    extern s32 *gCurrentMap;

    if (func_020d19b4(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4)) != 0) {
        func_02091c20(6, 1);
    }
    func_020a348c(arg0);
    func_020cfd28();
}

void func_020bbc74(void *arg0) {
    M2C_UNK func_020a8240(M2C_UNK *, s32, s32, M2C_UNK *);
    M2C_UNK func_020a8050(M2C_UNK *, s16 *, s16 *, M2C_UNK *);
    M2C_UNK func_020a83e4(M2C_UNK *, M2C_UNK *);
    M2C_UNK func_ov000_0216939c(M2C_UNK *);
    M2C_UNK func_ov000_02169518(M2C_UNK *);
    s16 arr1[2];
    s16 arr0[2];
    M2C_UNK buf[5];
    M2C_UNK *temp_r4;

    temp_r4 = M2C_FIELD(arg0, M2C_UNK **, 0x54);
    func_020a8240(temp_r4, M2C_FIELD(arg0, s32 *, 0x34), M2C_FIELD(arg0, s32 *, 0x38), buf);
    func_ov000_0216939c(temp_r4);
    func_ov000_02169518(buf);
    arr1[0] = M2C_FIELD(temp_r4, u8 *, 1);
    arr1[1] = M2C_FIELD(temp_r4, u8 *, 2);
    func_020a83e4(temp_r4, buf);
    arr0[0] = M2C_FIELD(temp_r4, u8 *, 1);
    arr0[1] = M2C_FIELD(temp_r4, u8 *, 2);
    func_020a8050(temp_r4, arr1, arr0, buf);
}

void func_020bbcec(s32 a) {
 void *func_01ffa3dc(M2C_UNK *,s32);
 extern s32 *gCurrentMap;
 extern s16 data_0212924c[];
 extern M2C_UNK data_0212929c;
 s32 base=*gCurrentMap;
 s32 x=data_0212924c[a*2];
 s32 y=data_0212924c[a*2+1];
 s32 xx=M2C_FIELD(base,s16 *,0x52dc)+x;
 s32 yy=M2C_FIELD(base,s16 *,0x52de)+y;
 s32 row=M2C_FIELD(base+yy*2,u16 *,0x3758);
 u8 id=M2C_FIELD(base+(xx+row),u8 *,0x508);
 void *p=(void *)(base+0x59a4+(s16)id*(s16)14);
 void *q;
 if(!p)return;
 q=func_01ffa3dc(&data_0212929c,7);
 M2C_FIELD(q,s32 *,0x34)=x*2;
 M2C_FIELD(q,s32 *,0x38)=y*2;
 M2C_FIELD(q,void **,0x54)=p;
}

void func_020bbd8c(void) {
    M2C_UNK func_020cab8c();
    func_020cab8c();
}

void func_020bbd98(void) {
 extern s32 *gCurrentMap;
 void *p;u16 v,n;
 func_020c79c4();
 p=M2C_FIELD(*gCurrentMap,void **,0x52d0);
 v=M2C_FIELD(p,u16 *,6);
 n=(u16)(((u32)(v<<21)>>28)+65535);
 M2C_FIELD(p,u16 *,6)=(v&~0x780)|((n&15)<<7);
 if(func_020d19b4(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)))func_02091c20(36,1);
}

void func_020bbe10(void){
void func_020c98d8(u8,u8,s32); void func_020a3184(u16,void *); s32 func_020d2d50(u16,u32); void func_020d2b10(u16,s32); M2C_UNK func_02091c20(M2C_UNK,M2C_UNK);
extern s32 *gCurrentMap;
void *p;
p=M2C_FIELD(*gCurrentMap,void **,0x52d0);
func_020c98d8(M2C_FIELD(p,u8 *,1),M2C_FIELD(p,u8 *,2),3);
func_020a3184(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),M2C_FIELD(*gCurrentMap,void **,0x52d0));
func_020d2b10(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),func_020d2d50(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),(u32)(M2C_FIELD(M2C_FIELD(*gCurrentMap,void **,0x52d0),u8 *,0)<<26)>>26));
if(func_020d19b4(M2C_FIELD(*gCurrentMap,u16 *,0x52a4)))func_02091c20(27,1);
}

#pragma push
#pragma opt_strength_reduction off
void func_020bc454(void) {
s32 func_0207d0b8(void); s32 func_0207d0d4(void); void func_020cfc5c(void);
extern s32 *gCurrentMap; extern void *data_02101e84; extern s16 data_021292dc; extern s16 data_021292de;
u32 dir=(M2C_FIELD(data_02101e84,u16 *,6)>>4)&15;
s32 w,h,n; w=func_0207d0b8(); h=func_0207d0d4();
if(M2C_FIELD(*gCurrentMap,u16 *,0x5144)<w)w=M2C_FIELD(*gCurrentMap,u16 *,0x5144);
if(M2C_FIELD(*gCurrentMap,u16 *,0x5146)<h)h=M2C_FIELD(*gCurrentMap,u16 *,0x5146);
if(BC454Direction(&data_021292dc,dir)<0)M2C_FIELD(*gCurrentMap,s16 *,0x52c2)=(M2C_FIELD(*gCurrentMap,s16 *,0x5148)>>4)+1;
if(BC454Direction(&data_021292dc,dir)>0)M2C_FIELD(*gCurrentMap,s16 *,0x52c2)=(w-2)+(M2C_FIELD(*gCurrentMap,s16 *,0x5148)>>4);
if(BC454Direction(&data_021292de,dir)<0)M2C_FIELD(*gCurrentMap,s16 *,0x52c4)=(M2C_FIELD(*gCurrentMap,s16 *,0x514a)>>4)+1;
if(BC454Direction(&data_021292de,dir)>0)M2C_FIELD(*gCurrentMap,s16 *,0x52c4)=(h-2)+(M2C_FIELD(*gCurrentMap,s16 *,0x514a)>>4);
func_020cfc5c();
n=M2C_FIELD(*gCurrentMap,s16 *,0x52c2)+BC454Direction(&data_021292dc,dir);
if(n>=0 && n<M2C_FIELD(*gCurrentMap,u16 *,0x5144))M2C_FIELD(*gCurrentMap,s16 *,0x52c2)=n;
n=M2C_FIELD(*gCurrentMap,s16 *,0x52c4)+BC454Direction(&data_021292de,dir);
if(n>=0 && n<M2C_FIELD(*gCurrentMap,u16 *,0x5146))M2C_FIELD(*gCurrentMap,s16 *,0x52c4)=n;
}
#pragma pop
void func_020bc610(void *arg0){
void func_0208fe30(void *);
extern void *data_02101e84; extern s32 *gCurrentMap; extern s16 data_021292dc; extern s16 data_021292de;
s32 dir; void *p; s32 n;
dir=(M2C_FIELD(data_02101e84,u16 *,4)>>4)&15;
p=(void *)*gCurrentMap;
n=M2C_FIELD(p,s16 *,0x52c2)+*(&data_021292dc+dir*2);
if(n>=0 && n<M2C_FIELD(p,u16 *,0x5144)){
M2C_FIELD(p,s16 *,0x52c2)=n;
if(*(&data_021292dc+dir*2)!=0)func_0208fe30(arg0);
}
p=(void *)*gCurrentMap;
n=M2C_FIELD(p,s16 *,0x52c4)+*(&data_021292de+dir*2);
if(n>=0 && n<M2C_FIELD(p,u16 *,0x5146)){
M2C_FIELD(p,s16 *,0x52c4)=n;
if(*(&data_021292de+dir*2)!=0)func_0208fe30(arg0);
}
}

s32 func_020bc6ec(s32 a,s32 b) {
 extern s32 *gCurrentMap;
 s32 p=*gCurrentMap;
 s32 v=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),s8 *,0x1e30);
 if(v>=0 && v<=110)return 1;
 return 0;
}

u8 func_020bc734(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 temp_r2;
    u8 var_r0;

    temp_r2 = *gCurrentMap;
    if ((s32) M2C_FIELD((temp_r2 + (arg0 + M2C_FIELD((temp_r2 + (arg1 * 2)), u16 *, 0x3758))), s8 *, 0x1E30) > 0x6E) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

#pragma opt_strength_reduction off
void func_020bc774(void *arg0){
void func_0208fe30(void *);extern void *data_02101e84;extern s32 *gCurrentMap;extern s16 data_021292dc,data_021292de;
s32 dir;u16 keys;s16 x,y;void *p;s32 n;
dir=(M2C_FIELD(data_02101e84,u16 *,4)>>4)&15;keys=M2C_FIELD(data_02101e84,u16 *,0);
p=(void *)*gCurrentMap;
x=M2C_FIELD(p,s16 *,0x52c2)+((s16 (*)[2])&data_021292dc)[dir][0];y=M2C_FIELD(p,s16 *,0x52c4)+((s16 (*)[2])&data_021292de)[dir][0];
if(!keys){
if(func_020bc6ec(M2C_FIELD(p,s16 *,0x52c2),M2C_FIELD(p,s16 *,0x52c4))&&!func_020bc6ec(x,y)){if(!func_020bc734(x,y))return;}
p=(void *)*gCurrentMap;
if(func_020bc734(M2C_FIELD(p,s16 *,0x52c2),M2C_FIELD(p,s16 *,0x52c4))){if(!func_020bc734(x,y))return;}
}
p=(void *)*gCurrentMap;n=M2C_FIELD(p,s16 *,0x52c2)+((s16 (*)[2])&data_021292dc)[dir][0];
if(n>=0&&n<M2C_FIELD(p,u16 *,0x5144)){M2C_FIELD(p,s16 *,0x52c2)=n;if(((s16 (*)[2])&data_021292dc)[dir][0])func_0208fe30(arg0);}
p=(void *)*gCurrentMap;n=M2C_FIELD(p,s16 *,0x52c4)+((s16 (*)[2])&data_021292de)[dir][0];
if(n>=0&&n<M2C_FIELD(p,u16 *,0x5146)){M2C_FIELD(p,s16 *,0x52c4)=n;if(((s16 (*)[2])&data_021292de)[dir][0])func_0208fe30(arg0);}
}
#pragma opt_strength_reduction reset
s32 func_020bc910(void) {
    void func_020d549c(void *);
    void func_020c752c(void);
    void func_020ccca0(void);
    void func_020d8fa0(void);
    void *func_020d2e3c(u16);
    void func_0208fe30(void *);
    s32 func_0207b764(u8, u8);
    s32 func_020d5aa0(s32, s32, s32, s32, s32);
    void func_020d58c4(s32, s32);

    extern s32 *gCurrentMap;
    extern void *data_02101e84;

    void *mapbase = *(void **)gCurrentMap;
    s16 x = *(s16 *)((char *)mapbase + 0x52C2);
    s16 y = *(s16 *)((char *)mapbase + 0x52C4);
    u16 flags = *(u16 *)data_02101e84;

    if (flags & 0x8) {
        func_020d549c((char *)mapbase + 0x5200);
        return 1;
    }
    if (flags & 0x4) {
        func_020c752c();
        return 1;
    }
    if (flags & 0x100) {
        func_020ccca0();
        return 1;
    }
    if (flags & 0x400) {
        func_020d8fa0();
        return 0;
    }
    if (flags & 0x200) {
        u16 w = *(u16 *)((char *)mapbase + 0x52A4);
        void *r6 = func_020d2e3c(w);
        if (r6 != 0) {
            func_0208fe30((void *)0x1001A);
            return func_0207b764(*(u8 *)((char *)r6 + 1), *(u8 *)((char *)r6 + 2));
        }
    }

    {
        u16 infoFlags = *(u16 *)data_02101e84;
        if (infoFlags & 0x1) {
            s32 res = func_020d5aa0(x, y, 1, 1, 0);
            if (res != 0) {
                return 1;
            }
        }
        if (!(infoFlags & 0x2)) {
            return 0;
        }
    }
    {
        void *mapbase2 = *(void **)gCurrentMap;
        s16 xx = *(s16 *)((char *)mapbase2 + 0x52C2);
        s16 yy = *(s16 *)((char *)mapbase2 + 0x52C4);
        func_020d58c4(xx, yy);
    }
    return 1;
}

s32 func_020bca68(void) {
 extern void *data_02101e84;
 extern u8 data_02164d5d;
 u16 v=M2C_FIELD(data_02101e84,u16 *,0);
 if(v&1){data_02164d5d=0;return 16;}
 if(v&2)return 32;
 if(v&256)return 256;
 if(v&1024)return 64;
 return 0;
}

s32 func_020bcac0(void) {
    extern void *data_02101e84;
    if (M2C_FIELD(data_02101e84, u16 *, 0) & 2) {
        return 0x20;
    }
    if (M2C_FIELD(data_02101e84, u16 *, 6) & 2) {
        return 0;
    }
    return 0x20;
}

s32 func_020bcaf0(void) {
    extern void *data_02101e84;
    u16 temp_r0;

    temp_r0 = M2C_FIELD(data_02101e84, u16 *, 0);
    if (temp_r0 & 1) {
        return 0x10;
    }
    if (temp_r0 & 2) {
        return 0x20;
    }
    if (temp_r0 & 0x100) {
        return 0x100;
    }
    if (temp_r0 & 0x400) {
        return 0x40;
    }
    return 0;
}

void func_020bcb34(s32 *arg0,s32 arg1) {
extern void *data_02101e84;
if(M2C_FIELD(data_02101e84,u16 *,2)&0x90) {
(*arg0)++;
if(*arg0==arg1) *arg0=0;
}
if(M2C_FIELD(data_02101e84,u16 *,2)&0x60) {
if(*arg0<=0) *arg0=arg1;
(*arg0)--;
}
}

