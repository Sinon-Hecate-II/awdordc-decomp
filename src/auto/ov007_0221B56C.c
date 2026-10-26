/* 24 functions from 0x0221B56C to 0x0221C534 (ov007), found by ds-decomp. */
#include "common.h"

typedef struct { u8 pad[11]; u8 low : 4; u8 high : 4; } Unk_0221BC18;

void func_ov007_0221b688(M2C_UNK arg0, M2C_UNK arg1) {
    M2C_UNK func_ov007_0221ac20(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 func_ov007_0221ad24(M2C_UNK, M2C_UNK, s32);
    if (func_ov007_0221ad24(arg0, arg1, func_ov007_0221b6c8()) != 0) {
        return;
    }
    func_ov007_0221ac20(arg0, arg1, 8, 3);
}

s32 func_ov007_0221b6c8(s32 arg0, s32 arg1) {
    extern s32 *data_027e0058;
    s32 temp_r2;
    s32 var_r0;

    temp_r2 = *data_027e0058;
    var_r0 = M2C_FIELD((temp_r2 + (arg0 + M2C_FIELD((temp_r2 + (arg1 * 2)), u16 *, 0x3758))), u8 *, 0x1420) & 0x1F;
    if (var_r0 == 0xE) {
        var_r0 = 0xD;
    }
    return var_r0;
}

s32 func_ov007_0221b704(s32 a,s32 b) {
 extern s32 *data_027e0058; extern s8 data_ov000_021b56c0[];
 s32 p=*data_027e0058;
 s32 v=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420);
 if(data_ov000_021b56c0[v&31]) return (v&0xE0)>>5;
 return 0;
}

s32 func_ov007_0221bad0(s32 a,s32 b) {
 extern s32 *data_027e0058; s32 p; u16 v;
 if(a<0||b<0)goto fail;
 p=*data_027e0058;
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
if(c==((u32)(entry[0]<<26)>>26)&&((u32)(entry[11]<<28)>>28)==e)return 2;
}else{if(func_ov007_02211ffc(d)>=50)return 0;}
}else{if(func_ov007_02211ffc(d)>=50)return 0;}
return 1;
}

s32 func_ov007_0221bc18(s32 a,s32 b,s32 c,s32 d,s32 e) {
 extern s32 *data_027e0058;
 s32 func_ov007_0221bb44(s32,s32,s32,s32,s32);
 M2C_UNK func_020a6728(s32);
 void *func_020a660c(s16,s16,s16,s32);
 s32 p,r; u8 id; Unk_0221BC18 *entry;
 r=func_ov007_0221bb44(a,b,c,d,e);
 if(r!=1)return r;
 p=*data_027e0058;
 id=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0);
 if(id)func_020a6728(id);
 entry=func_020a660c((s16)a,(s16)b,(s16)c,d);
 if(!entry)return 0;
 entry->low=(u8)e;
 return 1;
}

s32 func_ov007_0221bcc0(s32 a,s32 b) {
 extern s32 *data_027e0058; M2C_UNK func_020a6728(s32);
 s32 p=*data_027e0058;
 u8 id=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0);
 if(!id)return 0;
 func_020a6728(id); return 1;
}

u8 func_ov007_0221bd00(s32 a,s32 b,s32 c) {
 extern s32 *data_027e0058;
 extern u8 data_0212616c[];
 extern u8 data_ov000_021b5c0e[];
 s32 p=*data_027e0058;
 return M2C_FIELD(M2C_FIELD(data_0212616c,s8 **,0x64)+data_ov000_021b5c0e[c*0x70]*32,s8 *,M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420)&31)!=-1;
}

s32 func_ov007_0221bd74(s32 a,s32 b) {
 extern s32 *data_027e0058;
 s32 p=*data_027e0058;
 u8 id=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0);
 if(!id)return -1;
 return (u32)(M2C_FIELD(p+id*14,u8 *,0x59A4)<<26)>>26;
}

s32 func_ov007_0221bdc0(s32 a,s32 b) {
 extern s32 *data_027e0058;
 s32 p=*data_027e0058;
 s32 id=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0);
 if(!id)return -1;
 return ((id&0xC0)>>6)+1;
}

s32 func_ov007_0221be00(s32 a,s32 b) {
 extern s32 *data_027e0058;
 s32 p=*data_027e0058;
 u8 id=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0);
 if(!id)return -1;
 return (u32)(M2C_FIELD(p+id*14,u8 *,0x59AF)<<28)>>28;
}

void func_ov007_0221be4c(u8 *a,s32 b) {
 extern s32 *data_027e0058;
 u8 *d=(u8 *)(*data_027e0058+0x59A4+((b-1)<<6)*14);
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
 extern s32 *data_027e0058;
 s32 func_020c8054(s32); s32 func_ov007_0221216c(s32); void func_02086720(u32);
 if(func_020c8054(M2C_FIELD(*data_027e0058,u16 *,0x5142)))func_02086720(0x4600000C);
 else if(func_ov007_0221216c(-1))func_02086720(0x46000008);
 else func_02086720(0x46000009);
 M2C_FIELD(a,s32 *,0x5C)=M2C_FIELD(*data_027e0058,u16 *,0x5142);
 M2C_FIELD(a,u16 *,0x6C)=0;
}

void func_ov007_0221c4d4(void) {
 extern s32 *data_027e0058;
 s32 func_020c7ea8(s32); s32 func_020be4c0(s32); void func_02086720(u32);
 if(func_020be4c0(func_020c7ea8(M2C_FIELD(*data_027e0058,u16 *,0x5142)))==0){func_02086720(0xC000034C);return;}
 func_02086720(0);
}

void func_ov007_0221c51c(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_ov007_022201d8;
    func_01ffa3dc(&data_ov007_022201d8, 7);
}
