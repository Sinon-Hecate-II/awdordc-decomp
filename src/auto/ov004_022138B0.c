/* 46 functions from 0x022138B0 to 0x022148A4 (ov004), found by ds-decomp. */
#include "common.h"

s32 func_ov004_022138b0(void) {
    extern void **data_027e0058;
    extern u8 data_ov000_021df7d0;
    u8 value;
    u8 *p;
    u8 *base;
    u8 x, y;
    base = *data_027e0058;
    p = M2C_FIELD(base, u8 **, 0x52D0);
    x = p[1]; y = p[2];
    if (data_ov000_021df7d0 == 3) {
        p = base + (x + M2C_FIELD(base + y * 2, u16 *, 0x3758));
        value = p[0x1420];
        if (((s32)(value & 0xE0) >> 5) == 1 && (u32)((value & 0x1F) - 0x10) <= 1) return 1;
    }
    return 0;
}

u8 func_ov004_0221392c(void) {
    extern void **data_027e0058;
    u8 var_r0;

    if (M2C_FIELD(M2C_FIELD(*data_027e0058, void **, 0x52D0), u8 *, 0xC) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov004_0221395c(void) {
    extern void **data_027e0058;
    extern u8 data_ov000_021df7d0;
    if (data_ov000_021df7d0 == 0x18 && ((u32)(M2C_FIELD(M2C_FIELD(*data_027e0058, u8 **, 0x52D0), u8 *, 0) << 26) >> 26) == 0xD) return 1;
    return 0;
}

s32 func_ov004_022139a8(void) {
    extern void **data_027e0058;
    extern u8 data_ov000_021df7d0;
    u8 value;
    u8 *p;
    u8 *base;
    u8 x, y;
    base = *data_027e0058;
    p = M2C_FIELD(base, u8 **, 0x52D0);
    x = p[1]; y = p[2];
    if (data_ov000_021df7d0 == 24) {
        p = base + (x + M2C_FIELD(base + y * 2, u16 *, 0x3758));
        value = p[0x1420];
        if (((s32)(value & 0xE0) >> 5) == 1 && (value & 0x1F) == 0x14) return 1;
    }
    return 0;
}

s32 func_ov004_02213a1c(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 a=0,b=0; u8 *base=*data_027e0058; s32 i,end; u8 *p; u32 bits;
 if ((s32)M2C_FIELD(base,u16 *,0x52A2)>1) return 0;
 i=data_ov000_021aeef4[1]+1; end=data_ov000_021aeef4[1]+0x33;
 if(i<end) {p=base+0x59A4+i*14;
 do {bits=(u32)(*p<<26)>>26;
 if(bits) {switch(bits) {case 1: if(p[1]>=13U)a++;break; case 4:if(p[1]>=12U)b++;break;}}
 i++; p+=14;
 }while(i<end);}
 if(a==2 && b==1)return 0;
 return 1;
}

s32 func_ov004_02213ad8(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 count; s32 i; u8 *p; s32 end; u8 v;
 count=0; i=data_ov000_021aeef4[2]+1; end=data_ov000_021aeef4[2]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {v=*p; if((u32)(v<<26)>>26) count++; i++; p+=14;}while(i<end);}
 if(count!=0)return 0; return 1;
}

s32 func_ov004_02213b48(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 count; s32 i; u8 *p; s32 end; u8 v;
 count=0; i=data_ov000_021aeef4[2]+1; end=data_ov000_021aeef4[2]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {v=*p; if((u32)(v<<26)>>26) count++; i++; p+=14;}while(i<end);}
 if(count!=0)return 0; return 1;
}

void func_ov004_02213d90(void) {
    M2C_UNK func_02086720(s32);
    s32 func_02086a20(M2C_UNK);
    extern s32 data_ov004_02225f70[];
    func_02086720(data_ov004_02225f70[func_02086a20(0)]);
}

void func_ov004_02213db0(void) {
    M2C_UNK func_02086720(s32);
    s32 func_02086a20(M2C_UNK);
    extern s32 data_ov004_02225fdc[];
    func_02086720(data_ov004_02225fdc[func_02086a20(0)]);
}

void func_ov004_02213dd0(void) {
extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
s32 func_02086a20(M2C_UNK);
s32 i; u8 *p;
if(func_02086a20(0)==0)return;
for(i=data_ov000_021aeef4[M2C_FIELD(*data_027e0058,u16 *,0x52A4)]+1;i<data_ov000_021aeef4[M2C_FIELD(*data_027e0058,u16 *,0x52A4)]+0x33;i++){
p=(u8 *)*data_027e0058+0x59A4+i*14;
if((u32)(p[0]<<26)>>26) {
if(func_02086a20(0)==((u32)(p[0]<<26)>>26)) M2C_FIELD(p,u16 *,4)|=1;
}
}
}

u8 func_ov004_02213e94(void) {
 extern void **data_027e0058;
 s32 n=M2C_FIELD(*data_027e0058,u16 *,0x52A2); u8 r;
 if(n<=0)return 0;
 if(((n+1)&3)==0)r=1;else r=0; return r;
}

u8 func_ov004_02213ed0(void) {
 extern void **data_027e0058;
 s32 n=M2C_FIELD(*data_027e0058,u16 *,0x52A2); u8 r;
 if(n<=0)return 0;
 if((n&3)==0)r=1;else r=0; return r;
}

s32 func_ov004_02213f08(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 count; s32 i; u8 *p; s32 end; u8 v;
 count=0; i=data_ov000_021aeef4[2]+1; end=data_ov000_021aeef4[2]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {v=*p; if((u32)(v<<26)>>26) count++; i++; p+=14;}while(i<end);}
 if(count!=0)return 0; return 1;
}

u8 func_ov004_02213f78(void) {
 void *func_020a32f4(u16); extern void **data_027e0058;
 u8 r; if(func_020a32f4(M2C_FIELD(*data_027e0058,u16 *,0x52A4)))r=1;else r=0;return r;
}

void func_ov004_02213fac(void) {
 void *func_020a32f4(u16); extern void **data_027e0058;
 void *p=func_020a32f4(M2C_FIELD(*data_027e0058,u16 *,0x52A4));
 if(p)M2C_FIELD(p,u16 *,4)|=1;
}

s32 func_ov004_02213fe0(void) {
 extern void **data_027e0058;
 void *p=*data_027e0058;
 s16 a=M2C_FIELD(p,s16 *,0x52DC), b=M2C_FIELD(p,s16 *,0x52DE);
 return a==0 && b==4;
}

u8 func_ov004_02214010(void) {
    s32 func_02086b40(M2C_UNK);
    u8 var_r0;

    if (func_02086b40(0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_02214030(void) {
    s32 func_020a3518(M2C_UNK);
    u8 var_r0;

    if (func_020a3518(1) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_02214050(void) {
    s32 func_020a3594(M2C_UNK, M2C_UNK);
    s32 temp_r4;
    u8 var_r0;

    temp_r4 = func_020a3594(1, 2);
    if ((temp_r4 - func_020a3518(1)) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

s32 func_ov004_02214080(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 count; s32 i; u8 *p; s32 end; u8 v;
 count=0; i=data_ov000_021aeef4[2]+1; end=data_ov000_021aeef4[2]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {v=*p; if((u32)(v<<26)>>26) count++; i++; p+=14;}while(i<end);}
 if(count!=0)return 0; return 1;
}

u8 func_ov004_022140f0(void) {
extern void **data_027e0058;
u8 *base=*data_027e0058; s32 y,x; u8 *p; s32 t; u8 v;
for(y=0;y<M2C_FIELD(base,u16 *,0x5146);y++){
for(x=0;x<M2C_FIELD(base,u16 *,0x5144);x++){
if((((base+M2C_FIELD(base+(y<<1),u16 *,0x3758))[x+0x1420]&0xE0)>>5)==1){
p=base+M2C_FIELD(base+y*2,u16 *,0x3758)+x;
t=p[0x1420]&0x1F;
if(t==15||t==17){v=p[0x508];if(v!=0 && (v>>6)==0)return 1;}
}
}
}
return 0;
}

s32 func_ov004_022141bc(void) {
    s32 temp_r4;

    temp_r4 = func_020a3594(1, 2);
    if ((temp_r4 == func_020a3518(1)) && (func_020a3518(1) > 0)) {
        return 1;
    }
    return 0;
}

u8 func_ov004_022141fc(void) {
    s32 func_020a4ce8(M2C_UNK);
    u8 var_r0;

    if (func_020a4ce8(4) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_0221421c(void) {
    u8 var_r0;

    if (func_02086b40(0) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov004_0221423c(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 i; u16 start=data_ov000_021aeef4[M2C_FIELD(*data_027e0058,u16 *,0x52A4)];
 for(i=start+1;i<data_ov000_021aeef4[M2C_FIELD(*data_027e0058,u16 *,0x52A4)]+0x33;i++){
 u8 *p=(u8 *)*data_027e0058+0x59A4+i*14;
 if((u32)(*p<<26)>>26) M2C_FIELD(p,u16 *,4)|=1;
 }
}

s32 func_ov004_022142d4(void) {
 extern void **data_027e0058;
 void *p; s16 a,b;
 if((s32)M2C_FIELD(*data_027e0058,u16 *,0x52A2)<2)return 0;
 if(func_02086b40(0))return 0;
 if(!func_020a7cfc(M2C_FIELD(*data_027e0058,s32 *,0x52D0)))return 0;
 p=*data_027e0058; a=M2C_FIELD(p,s16 *,0x52DC); b=M2C_FIELD(p,s16 *,0x52DE);
 return a==4 && b==12;
}

s32 func_ov004_0221435c(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 count; s32 i; u8 *p; s32 end; u8 v;
 count=0; i=data_ov000_021aeef4[2]+1; end=data_ov000_021aeef4[2]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {v=*p; if((u32)(v<<26)>>26) count++; i++; p+=14;}while(i<end);}
 if(count!=0)return 0; return 1;
}

s32 func_ov004_022143cc(void) {
 extern void **data_027e0058;extern u16 data_ov000_021aeef4[];
 s32 count,i,end;u8 *p,v;
 count=0;
 if(func_020d32a0(2))return 1;
 i=data_ov000_021aeef4[2]+1;end=data_ov000_021aeef4[2]+0x33;
 if(i<end){p=(u8 *)*data_027e0058+0x59A4+i*14;
 do{v=*p;if((u32)(v<<26)>>26)count++;i++;p+=14;}while(i<end);}
 if(count!=0)return 0;return 1;
}

s32 func_ov004_02214454(void) {
    return 1;
}

void func_ov004_0221445c(s32 arg0) {
    M2C_UNK func_020c78e8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_020c78e8(9, 6, 3, 0x32, arg0);
}

u8 func_ov004_0221447c(void) {
 extern void **data_027e0058;
 s32 n=M2C_FIELD(*data_027e0058,u16 *,0x52A2);u8 r;
 if(n<3)return 0;
 if(n<=5)r=1;else r=0;return r;
}

void func_ov004_022144b4(s32 arg0) {
 s32 func_ov000_021aab20(s16 *,s32,s32,s32,s32,s32);
 s16 pos[2];
 if(!func_ov000_021aab20(pos,2,0,6,3,50))return;
 func_020c78e8(pos[0],pos[1],3,50,arg0);
}

s32 func_ov004_02214510(void) {
 extern void **data_027e0058; extern u16 data_ov000_021aeef4[];
 s32 count; s32 i; u8 *p; s32 end; u8 v;
 count=0; i=data_ov000_021aeef4[2]+1; end=data_ov000_021aeef4[2]+0x33;
 if(i<end) {p=(u8 *)*data_027e0058+0x59A4+i*14;
 do {v=*p; if((u32)(v<<26)>>26) count++; i++; p+=14;}while(i<end);}
 if(count!=0)return 0; return 1;
}

s32 func_ov004_02214580(void) {
 extern void **data_027e0058;extern u16 data_ov000_021aeef4[];
 s32 count,i,end;u8 *p,v;
 count=0;
 i=data_ov000_021aeef4[2]+1;end=data_ov000_021aeef4[2]+0x33;
 if(i<end){p=(u8 *)*data_027e0058+0x59A4+i*14;
 do{v=*p;if((u32)(v<<26)>>26)count++;i++;p+=14;}while(i<end);}
 if(count>3)return 0;return 1;
}

s32 func_ov004_022145f0(s8 *a) {
extern void **data_027e0058;
s32 func_0207c928(s32,s32);
s32 n=0;
while(a[n]>=0)n++;
return a[func_0207c928(M2C_FIELD(*data_027e0058,u16 *,0x52a2)-1,n)];
}

void func_ov004_02214640(void) {
extern s8 data_ov004_02233d24[];extern void **data_027e0058;
s32 n=func_ov004_022145f0(data_ov004_02233d24);void *p=*data_027e0058;
s32 i=M2C_FIELD(p,u16 *,0x3768)+10;
if(M2C_FIELD((u8 *)p+i,u8 *,0x508))return;
if(!n)return;
func_020a66e0(10,8,n,2);
}

void func_ov004_0221469c(void) {
extern s8 data_ov004_02233d1c[];extern void **data_027e0058;
s32 n=func_ov004_022145f0(data_ov004_02233d1c);void *p=*data_027e0058;
s32 i=M2C_FIELD(p,u16 *,0x3768)+14;
if(M2C_FIELD((u8 *)p+i,u8 *,0x508))return;
if(!n)return;
func_020a66e0(14,8,n,2);
}

void func_ov004_022146f8(void) {
    M2C_UNK func_02080774(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
    func_02080774(4, 2, 0, 0x32, 0);
}

u8 func_ov004_02214718(void) {
    M2C_UNK func_020a45f8(M2C_UNK, M2C_UNK);
    s32 func_020a4c7c();
    u8 var_r0;

    func_020a45f8(6, 6);
    if (func_020a4c7c() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_02214740(void) {
    u8 var_r0;

    func_020a45f8(0xB, 5);
    if (func_020a4c7c() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_02214768(void) {
    u8 var_r0;

    func_020a45f8(0xC, 5);
    if (func_020a4c7c() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_02214790(void) {
    u8 var_r0;

    func_020a45f8(0xD, 5);
    if (func_020a4c7c() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_022147b8(void) {
    u8 var_r0;

    func_020a45f8(0x12, 6);
    if (func_020a4c7c() == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_ov004_022147e0(void) {
    u8 var_r0;

    if (func_020a4ce8(6) != 0) {
        return 0U;
    }
    if (func_020a4ce8(7) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov004_02214814(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    M2C_UNK func_02087c6c(s32, s32, s32, s32, s32, s32);
    func_02087c6c(arg0, arg1, arg2 + 1, arg1, arg4, arg5);
    func_02087c6c(arg2, arg1, arg2, arg3 + 1, arg4, arg5);
    func_02087c6c(arg2 + 1, arg3, arg0, arg3, arg4, arg5);
    func_02087c6c(arg0, arg3 + 1, arg0, arg1, arg4, arg5);
}

