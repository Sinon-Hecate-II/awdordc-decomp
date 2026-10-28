/* 24 functions from 0x0221B56C to 0x0221C534 (ov007), found by ds-decomp. */
#include "common.h"

typedef struct { u8 pad[11]; u8 low : 4; u8 high : 4; } Unk_0221BC18;

s32 func_ov007_0221b6c8();
s32 func_ov007_0221b704(s32,s32);
void func_ov007_0221b688(s32,s32);
s32 func_ov007_0221b56c(s32 a,s32 b,s32 c,s32 d) {
extern s32 *gCurrentMap;
s32 func_ov007_0221acac(s32,s32,s32,s32);
s32 func_020c1a80(s32);
s32 func_ov007_0221b2cc(s32,s32,s32,s32,s32,s32);
s32 e=func_ov007_0221b6c8(a,b),f=func_ov007_0221b704(a,b);
s32 r=func_ov007_0221acac(a,b,c,d); s32 x,y;
if(r!=1)return r;
if(func_020c1a80(c))return 0;
if(func_ov007_0221b2cc(a,b,c,d,e,f)){
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++)
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++)func_ov007_0221b688(x,y);
return 1;
}
return 0;
}

void func_ov007_0221b688(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_ov007_0221ac20(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_ov007_0221ad24(M2C_UNK, M2C_UNK, s32);
    if (func_ov007_0221ad24(arg0, arg1, func_ov007_0221b6c8()) != 0) {
        return;
    }
    func_ov007_0221ac20(arg0, arg1, 8, 3);
}

s32 func_ov007_0221b6c8(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 temp_r2;
    s32 var_r0;

    temp_r2 = *gCurrentMap;
    var_r0 = M2C_FIELD((temp_r2 + (arg0 + M2C_FIELD((temp_r2 + (arg1 * 2)), u16 *, 0x3758))), u8 *, 0x1420) & 0x1F;
    if (var_r0 == 0xE) {
        var_r0 = 0xD;
    }
    return var_r0;
}

s32 func_ov007_0221b704(s32 a,s32 b) {
 extern s32 *gCurrentMap; extern s8 data_ov000_021b56c0[];
 s32 p=*gCurrentMap;
 s32 v=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420);
 if(data_ov000_021b56c0[v&31]) return (v&0xE0)>>5;
 return 0;
}

s32 func_ov007_0221b754(s32 arg0, s32 arg1) {
    extern s32 *gCurrentMap;
    s32 p;
    u16 t;
    if (arg0 < 0 || arg1 < 0) {
        goto ret0;
    }
    p = *gCurrentMap;
    if (arg0 >= M2C_FIELD(p, u16 *, 0x5144) || arg1 >= M2C_FIELD(p, u16 *, 0x5146)) {
        return 1;
    }
    t = M2C_FIELD(p + (arg0 + M2C_FIELD(p + arg1 * 2, u16 *, 0x3758)) * 2, u16 *, 0xA10);
    switch (t) {
        case 0x3:
        case 0x7:
        case 0x22:
        case 0x24:
        case 0x27:
        case 0x146:
        case 0x166:
        case 0x168:
        case 0x199:
        case 0x19A:
        case 0x19B:
        case 0x19C:
        case 0x19D:
        case 0x1C4:
        case 0x1C9:
        case 0x1CE:
        case 0x1D3:
        case 0x1D8:
            return 1;
        default:
            goto ret0;
    }
ret0:
    return 0;
}

s32 func_ov007_0221b8c0(s32 x, s32 y) {
    extern s32 *gCurrentMap;
    s32 p;
    s32 t;
    s32 r;
    if (x < 0 || y < 0) {
        goto fail;
    }
    p = *gCurrentMap;
    if (x < M2C_FIELD(p, u16 *, 0x5144)) {
        if (y < M2C_FIELD(p, u16 *, 0x5146)) {
            goto in_bounds;
        }
    }
    return 0;
in_bounds:
    r = M2C_FIELD(p + y * 2, u16 *, 0x3758);
    t = x + r;
    t = M2C_FIELD(p + t * 2, u16 *, 0xA10);
    t -= 0x79;
    t -= 0x100;
    switch (t) {
        case 0: case 1: case 2: case 3: case 4:
        case 30: case 31: case 32: case 33: case 34:
        case 60: case 61: case 62: case 63: case 64:
        case 68: case 69: case 70: case 71: case 72: case 73: case 74: case 75:
        case 76: case 77: case 78: case 79: case 80: case 81: case 82: case 83:
        case 84: case 85: case 86: case 87: case 88: case 89: case 90: case 91:
        case 92: case 93: case 94: case 95: case 96: case 97: case 98: case 99:
        case 100:
            return 1;
        default:
            goto fail;
    }
fail:
    return 0;
}

s32 func_ov007_0221bad0(s32 a,s32 b) {
 extern s32 *gCurrentMap; s32 p; u16 v;
 if(a<0||b<0)goto fail;
 p=*gCurrentMap;
 if(a>=M2C_FIELD(p,u16 *,0x5144)||b>=M2C_FIELD(p,u16 *,0x5146))goto fail;
 goto valid;
 fail:return 0;
 valid:
 v=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758))*2,u16 *,0xA10);
 switch(v) { case 0x23: case 0x25: return 1; default: return 0; }
}

s32 func_ov007_0221bb44(s32 a,s32 b,s32 c,s32 d,s32 e){
u8 func_ov007_0221bd00(s32,s32,s32);s32 func_ov007_02211ffc(s32);extern s32 *data_027e0058;
s32 p,id;u8 *entry;
if(!func_ov007_0221bd00(a,b,c))return 0;
p=*data_027e0058;id=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0);
if(id){entry=(u8 *)(p+0x59a4)+id*14;
if(((id&0xc0)>>6)+1==d){
if(c==((u32)(entry[0]<<26)>>26)&&((u32)(entry[11]<<28)>>28)==(unsigned)e)return 2;
}else{if(func_ov007_02211ffc(d)>=50)return 0;}
}else{if(func_ov007_02211ffc(d)>=50)return 0;}
return 1;
}

s32 func_ov007_0221bc18(s32 a,s32 b,s32 c,s32 d,s32 e) {
 extern s32 *gCurrentMap;
 s32 func_ov007_0221bb44(s32,s32,s32,s32,s32);
 M2C_UNK func_020a6728(s32);
 void *func_020a660c(s16,s16,s16,s32);
 s32 p,r; u8 id; Unk_0221BC18 *entry;
 r=func_ov007_0221bb44(a,b,c,d,e);
 if(r!=1)return r;
 p=*gCurrentMap;
 id=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0);
 if(id)func_020a6728(id);
 entry=func_020a660c((s16)a,(s16)b,(s16)c,d);
 if(!entry)return 0;
 entry->low=(u8)e;
 return 1;
}

s32 func_ov007_0221bcc0(s32 a,s32 b) {
 extern s32 *gCurrentMap; M2C_UNK func_020a6728(s32);
 s32 p=*gCurrentMap;
 u8 id=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0);
 if(!id)return 0;
 func_020a6728(id); return 1;
}

u8 func_ov007_0221bd00(s32 a,s32 b,s32 c) {
 extern s32 *gCurrentMap;
 extern u8 data_0212616c[];
 extern u8 data_ov000_021b5c0e[];
 s32 p=*gCurrentMap;
 return M2C_FIELD(M2C_FIELD(data_0212616c,s8 **,0x64)+data_ov000_021b5c0e[c*0x70]*32,s8 *,M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420)&31)!=-1;
}

s32 func_ov007_0221bd74(s32 a,s32 b) {
 extern s32 *gCurrentMap;
 s32 p=*gCurrentMap;
 u8 id=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0);
 if(!id)return -1;
 return (u32)(M2C_FIELD(p+id*14,u8 *,0x59A4)<<26)>>26;
}

#pragma push
#pragma optimizewithasm off
#pragma peephole off
s32 func_ov007_0221bdc0(s32 a,s32 b) {
 extern s32 *gCurrentMap;
 s32 p=*gCurrentMap;
 s32 id=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0);
 if(!id)return -1;
 return ((id&0xC0)>>6)+1;
}
#pragma pop
s32 func_ov007_0221be00(s32 a,s32 b) {
 extern s32 *gCurrentMap;
 s32 p=*gCurrentMap;
 u8 id=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0);
 if(!id)return -1;
 return (u32)(M2C_FIELD(p+id*14,u8 *,0x59AF)<<28)>>28;
}

void func_ov007_0221be4c(u8 *a,s32 b) {
 extern s32 *gCurrentMap;
 u8 *d=(u8 *)(*gCurrentMap+0x59A4+((b-1)<<6)*14);
 s32 i=0;
 do {
 u8 *s=a; u8 *t=d; u32 x,y;
 *d=*a; a+=14; d+=14; i++;
 t[1]=s[1];t[2]=s[2];
 M2C_FIELD(t,u16 *,4)=M2C_FIELD(s,u16 *,4);
 M2C_FIELD(t,u16 *,6)=M2C_FIELD(s,u16 *,6);
 M2C_FIELD(t,u16 *,8)=M2C_FIELD(s,u16 *,8);
 t[10]=s[10];t[11]=s[11];x=((volatile u8 *)s)[12];y=((volatile u8 *)s)[13];t[12]=x;t[13]=y;
 }while(i<64);
}

void func_ov007_0221bee4(s32 a,s32 b,s32 c,s32 d){
extern s32 *data_027e0058;
void *func_020e34bc(u32); void func_020e35cc(void *);
u8 *buf; s32 i,off; u8 *t;
if(a==1&&b==2&&c==3&&d==4)return;
buf=func_020e34bc(0xE00);i=0;off=0;t=buf;
do{u8 *s=(u8 *)(*data_027e0058+0x59A4);u8 *p=s+off;u32 x,y;
i++;
t[0]=s[off];t[1]=p[1];t[2]=p[2];
M2C_FIELD(t,u16 *,4)=M2C_FIELD(p,u16 *,4);
M2C_FIELD(t,u16 *,6)=M2C_FIELD(p,u16 *,6);
M2C_FIELD(t,u16 *,8)=M2C_FIELD(p,u16 *,8);
t[10]=p[10];t[11]=p[11];x=((volatile u8 *)p)[12];y=((volatile u8 *)p)[13];t[12]=x;t[13]=y;t+=14;off+=14;
}while(i<256);
if(a!=1)func_ov007_0221be4c(buf+((a-1)<<6)*14,1);
if(b!=2)func_ov007_0221be4c(buf+((b-1)<<6)*14,2);
if(c!=3)func_ov007_0221be4c(buf+((c-1)<<6)*14,3);
if(d!=4)func_ov007_0221be4c(buf+((d-1)<<6)*14,4);
func_020e35cc(buf);
}

#pragma optimization_level 4
#pragma opt_strength_reduction off
void func_ov007_0221c030(s32 a,s32 b,s32 c,s32 d){
extern s32 *gCurrentMap;extern s8 data_ov000_021b56c0[];
s32 func_0207f460(s32);
s32 y,x,p,q,v,k;
for(y=0;y<M2C_FIELD(*gCurrentMap,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(*gCurrentMap,u16 *,0x5144);x++){
p=*gCurrentMap;
q=(p+x)+M2C_FIELD(p+(y<<1),u16 *,0x3758);
v=M2C_FIELD(q,u8 *,0x1420);k=v&31;
if(data_ov000_021b56c0[k]){
if(a==((v&0xe0)>>5))M2C_FIELD(q,u8 *,0x1420)=k|0x20;
if(b==((v&0xe0)>>5)){p=*gCurrentMap;M2C_FIELD(M2C_FIELD(p+(y<<1),u16 *,0x3758)+(p+x),u8 *,0x1420)=k|64;}
if(c==((v&0xe0)>>5)){p=*gCurrentMap;M2C_FIELD(M2C_FIELD(p+(y<<1),u16 *,0x3758)+(p+x),u8 *,0x1420)=k|96;}
if(d==((v&0xe0)>>5)){p=*gCurrentMap;M2C_FIELD(M2C_FIELD(p+(y<<1),u16 *,0x3758)+(p+x),u8 *,0x1420)=k|128;}
p=*gCurrentMap;
M2C_FIELD(p+(x+M2C_FIELD(p+(y<<1),u16 *,0x3758))*2,u16 *,0xa10)=func_0207f460(M2C_FIELD(M2C_FIELD(p+(y<<1),u16 *,0x3758)+(p+x),u8 *,0x1420));
}}}}
void func_ov007_0221c1d4(void) {
    s32 func_020a23b4(s32);
    s32 temp_r4;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;

    var_r5 = 1;
    var_r4 = 0;
    do {
        func_020a231c(var_r4, var_r4);
        var_r4 += 1;
    } while (var_r4 < 5);
    var_r6 = 1;
    do {
        if (func_020a23b4(var_r6) != 0) {
            temp_r4 = func_020a2360(var_r5);
            func_020a231c(var_r5, func_020a2360(var_r6));
            func_020a231c(var_r6, temp_r4);
            var_r5 = (s32) (u8) (var_r5 + 1);
        }
        var_r6 += 1;
    } while (var_r6 < 5);
}

void func_ov007_0221c250(void) {
    M2C_UNK func_020a231c(s32, s32);
    M2C_UNK func_020d1f2c();
    M2C_UNK func_020d216c();
    s32 var_r4;

    var_r4 = 0;
    do {
        func_020a231c(var_r4, var_r4);
        var_r4 += 1;
    } while (var_r4 < 5);
    func_020d216c();
    func_020d1f2c();
}

s32 func_ov007_0221c27c(s32 arg0) {
    s32 func_020a2360(s32);
    s32 var_r4;

    var_r4 = 0;
loop_1:
    if (arg0 == func_020a2360(var_r4)) {
        return var_r4;
    }
    var_r4 += 1;
    if (var_r4 >= 5) {
        return 0;
    }
    goto loop_1;
}

void func_ov007_0221c2b0(void *a) {
 extern s32 *gCurrentMap;
 s32 func_020c8054(s32); s32 func_ov007_0221216c(s32); void func_02086720(u32);
 if(func_020c8054(M2C_FIELD(*gCurrentMap,u16 *,0x5142)))func_02086720(0x4600000C);
 else if(func_ov007_0221216c(-1))func_02086720(0x46000008);
 else func_02086720(0x46000009);
 M2C_FIELD(a,s32 *,0x5C)=M2C_FIELD(*gCurrentMap,u16 *,0x5142);
 M2C_FIELD(a,u16 *,0x6C)=0;
}

void func_ov007_0221c33c(void *p) {
extern s32 *gCurrentMap;
s32 func_020be1a8(void); s32 func_020a2360(s32); s32 func_ov007_0221c27c(s32);
void func_ov007_0221c030(s32,s32,s32,s32);
void func_020c8d50(s32); void func_ov007_0221c250(void); void func_ov007_0221205c(void); void func_ov007_022121d4(s32); void func_01ffa6fc(void *);
s32 a,b,c,d;
if(func_020be1a8())return;
func_ov007_0221c1d4();
a=func_020a2360(1);b=func_020a2360(2);c=func_020a2360(3);d=func_020a2360(4);
func_ov007_0221bee4(a,b,c,d);
a=func_020a2360(1);b=func_020a2360(2);c=func_020a2360(3);d=func_020a2360(4);
func_ov007_0221c030(a,b,c,d);
if(M2C_FIELD(p,s16 *,0x6c)){s32 v=M2C_FIELD(p,s32 *,0x5c);M2C_FIELD(p,s32 *,0x5c)=v+1;func_020c8d50(v+0xe1);}else func_020c8d50(M2C_FIELD(*gCurrentMap,u16 *,0x5142));
a=func_ov007_0221c27c(1);b=func_ov007_0221c27c(2);c=func_ov007_0221c27c(3);d=func_ov007_0221c27c(4);
func_ov007_0221bee4(a,b,c,d);
a=func_ov007_0221c27c(1);b=func_ov007_0221c27c(2);c=func_ov007_0221c27c(3);d=func_ov007_0221c27c(4);
func_ov007_0221c030(a,b,c,d);
func_ov007_0221c250();func_ov007_0221205c();func_ov007_022121d4(0);
if(M2C_FIELD(p,s16 *,0x6c)){if(M2C_FIELD(p,s32 *,0x5c)<50)return;func_01ffa6fc(p);return;}func_01ffa6fc(p);
}

void func_ov007_0221c4d4(void) {
 extern s32 *gCurrentMap;
 s32 func_020c7ea8(s32); s32 func_020be4c0(s32); void func_02086720(u32);
 if(func_020be4c0(func_020c7ea8(M2C_FIELD(*gCurrentMap,u16 *,0x5142)))==0){func_02086720(0xC000034C);return;}
 func_02086720(0);
}

#pragma push
#pragma optimization_level 3
void func_ov007_0221c51c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_022201d8;
    func_01ffa3dc(&data_ov007_022201d8, 7);
}
