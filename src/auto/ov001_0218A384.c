/* 39 functions from 0x0218A384 to 0x0218B368 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct { s8 x, y; } TextDirection;
static inline void get_obj_xy(void *base, s32 index, s32 *x, s32 *y) {
*x=(M2C_FIELD(base,u32 *,index*8)&0x1ff0000)>>16;
*y=M2C_FIELD(base,u32 *,index*8)&255;
}
static inline void set_obj_xy(void *base,s32 index,s32 x,s32 y) {
M2C_FIELD(base,u32 *,index*8)=(M2C_FIELD(base,u32 *,index*8)&0xfe00ff00)|(y&255)|((u32)(x<<23)>>7);
}

void Ov001_MoveSpriteLayout(void *arg0,s32 arg1,s32 arg2,s32 arg3) {
void *p=M2C_FIELD(arg0,void **,8);
s32 orig[2],xy[2],i,dx,dy;
if(arg1>=0) {set_obj_xy(p,arg1,arg2,arg3);return;}
get_obj_xy(p,0,&orig[1],&orig[0]);
set_obj_xy(p,0,arg2,arg3);
dx=arg2-orig[1];dy=arg3-orig[0];
for(i=1;i<M2C_FIELD(arg0,u8 *,12);i++) {
get_obj_xy(p,i,&xy[1],&xy[0]);
set_obj_xy(p,i,xy[1]+dx,xy[0]+dy);
}
}

#pragma opt_strength_reduction off
void Ov001_SetSpritePalette(M2C_UNK arg0, s32 arg1, s32 arg2) {
u8 *entries=M2C_FIELD(arg0,u8 **,8);
s32 i;
if(arg1>=0) {
M2C_FIELD(entries+arg1*8,u16 *,4)=(M2C_FIELD(entries+arg1*8,u16 *,4)&~0xc00)|(arg2<<10);
} else {
for(i=0;i<M2C_FIELD(arg0,u8 *,12);i++) {
M2C_FIELD(entries+i*8,u16 *,4)=(M2C_FIELD(entries+i*8,u16 *,4)&~0xc00)|(arg2<<10);
}
}
}
#pragma opt_strength_reduction on
void func_ov001_0218a4d4(void *arg0, s32 arg1, u32 *arg2, s32 *arg3) {
 void *base=M2C_FIELD(arg0,void **,8);
 *arg2=(M2C_FIELD(base,u32 *,arg1*8)&0x01FF0000)>>16;
 *arg3=M2C_FIELD(base,u32 *,arg1*8)&0xFF;
}

void Ov001_LoadCharBank(s32 arg0, M2C_UNK arg1) {
 s32 Ov001_LoadFile(M2C_UNK,M2C_UNK *,M2C_UNK);
 extern M2C_UNK data_ov001_02193e34;
 M2C_UNK sp0;
 (&data_ov001_02193e34)[arg0]=Ov001_LoadFile(arg1,&sp0,4);
}

void func_ov001_0218a534(u8 arg0) {
 void Ov001_FreeFile(s32);
 extern M2C_UNK data_ov001_02193e34;
 Ov001_FreeFile(((s32 *)&data_ov001_02193e34)[arg0]);
 ((s32 *)&data_ov001_02193e34)[arg0] = 0;
}

void Ov001_LoadSpriteObjLayout(s32 arg0, s32 arg1, s32 arg2) {
extern M2C_UNK data_ov001_02193e34;
void CpuFill(u32,void *,s32);
void func_02007e20(const void *,void *,u32);
void func_02007e70(const void *,void *,s32);
u8 *base=(u8 *)((M2C_UNK *)&data_ov001_02193e34)[arg0];
s32 index=arg1<<3;
u16 count=*(u16 *)(base+index);
s32 offset=*(s32 *)(base+index+4);
u8 *src=base+offset;
u8 *dst=(u8 *)arg2;
u8 sp[8]; s32 i;
CpuFill(0,sp,8);
for(i=0;i<(s32)count;i++){
func_02007e20(src,sp,6);func_02007e70(sp,dst,8);src+=6;dst+=8;
}
}

s32 func_ov001_0218a5f0(M2C_UNK arg0, M2C_UNK arg1) {
    void Ov001_LoadSpriteObjLayout(M2C_UNK, M2C_UNK, s32);
    s32 func_ov001_0218c0e4();
    s32 temp_r0;

    temp_r0 = func_ov001_0218c0e4();
    Ov001_LoadSpriteObjLayout(arg0, arg1, temp_r0);
    return temp_r0;
}

M2C_UNK func_ov001_0218a61c(s32 arg0,s32 arg1,s32 arg2) {
extern M2C_UNK data_ov001_02193e34;
M2C_UNK func_ov001_0218a070(s32,s32,s32);
s32 Ov001_GetSpriteObjEntry(s32,s32);
void Ov001_LoadSpriteObjLayout(s32,s32,s32);
void *base=((M2C_UNK **)&data_ov001_02193e34)[arg0];
u16 count=*(u16 *)((u8 *)base+arg1*8);
M2C_UNK t=func_ov001_0218a070(arg0,count,arg2);
Ov001_LoadSpriteObjLayout(arg0,arg1,Ov001_GetSpriteObjEntry(t,0));
return t;
}

void *Ov001_QueueCreate(s32 arg0) {
    void *Ov001_Alloc(s32, M2C_UNK);
    void *temp_r0;

    temp_r0 = Ov001_Alloc(((arg0 + 1) * 4) + 8, 4);
    M2C_FIELD(temp_r0, s16 *, 0) = (s16) (arg0 + 1);
    M2C_FIELD(temp_r0, s8 *, 2) = 0;
    M2C_FIELD(temp_r0, s8 *, 3) = 0;
    return temp_r0;
}

void *Ov001_QueueCreateFromBuffer(s32 arg0, s32 arg1, s32 arg2) {
    void *Ov001_QueueCreate(s32);
    M2C_UNK *base = (M2C_UNK *)Ov001_QueueCreate(arg0);
    s32 i;
    s32 val = arg1;
    for (i = 0; i < arg0; i++) {
        base[i + 1] = (M2C_UNK)val;
        val += arg2;
    }
    ((u8 *)base)[3] = (u8)arg0;
    return base;
}

void func_ov001_0218a6d8(s32 arg0, ...) {
 M2C_UNK func_ov001_0218b71c(M2C_UNK *);
 func_ov001_0218b71c(&arg0);
}

void func_ov001_0218a6f4(void *arg0, s32 arg1) {
    u8 func_020020c4(s32, u16);
    M2C_UNK func_020051c8(s32);
    s32 func_020051f8(M2C_UNK);
    M2C_UNK SystemHalt();
    s32 temp_r6;
    u8 temp_r0;

    temp_r6 = func_020051f8(1);
    temp_r0 = func_020020c4(M2C_FIELD(arg0, u8 *, 3) + 1, M2C_FIELD(arg0, u16 *, 0));
    if (temp_r0 == M2C_FIELD(arg0, u8 *, 2)) {
        SystemHalt();
    }
    M2C_FIELD((arg0 + (M2C_FIELD(arg0, u8 *, 3) * 4)), s32 *, 4) = arg1;
    M2C_FIELD(arg0, u8 *, 3) = temp_r0;
    func_020051c8(temp_r6);
}

s32 func_ov001_0218a74c(void *arg0) {
M2C_UNK func_020051c8(M2C_UNK);s32 func_020051f8(M2C_UNK);u8 func_020020c4(s32,u16);
s32 result=0,saved,value;u8 head,tail,idx;u16 size;

saved=func_020051f8(1);head=M2C_FIELD(arg0,u8 *,3);tail=M2C_FIELD(arg0,u8 *,2);
if(tail!=head){size=M2C_FIELD(arg0,u16 *,0);
value=func_020020c4(head+size-1,size);M2C_FIELD(arg0,u8 *,3)=value;idx=M2C_FIELD(arg0,u8 *,3);
result=M2C_FIELD((u8*)arg0+(idx<<2),s32 *,4);}
func_020051c8(saved);return result;
}

void Ov001_InitFades(void) {
    extern M2C_UNK gOv001FadeStates;
    void *Ov001_Alloc(s32, M2C_UNK);
    void GX_SetBlendControl(M2C_UNK, s32, s32);
    gOv001FadeStates = (M2C_UNK)Ov001_Alloc(0x18, 4);
    GX_SetBlendControl(0x4000050, 0x3f, 0x10);
    GX_SetBlendControl(0x4001050, 0x3f, 0x10);
}

void Ov001_FreeFades(void) {
    M2C_UNK func_ov001_0218b71c(M2C_UNK *);
    extern M2C_UNK gOv001FadeStates;
    func_ov001_0218b71c(&gOv001FadeStates);
}

u8 Ov001_IsFadeActive(s32 arg0) {
    extern M2C_UNK gOv001FadeStates;
    void *p;
    if (arg0 == 1) {
        p = (void *)gOv001FadeStates;
    } else {
        p = (u8 *)gOv001FadeStates + 0xc;
    }
    return ((u8 *)p)[9];
}

s32 Ov001_StartFade(s32 arg0,s32 arg1,s32 arg2,s32 arg3) {
extern u8 gOv001FadeTable[];
extern M2C_UNK gOv001FadeStates;
void GX_SetBlendControl(s32,s32,s32);
void Ov001_UpdateFade(M2C_UNK, void *);
void *func_ov001_0218c884(s32,s32,void *,s32);
s8 buf[4];
void *p;
buf[0]=gOv001FadeTable[8]; buf[1]=gOv001FadeTable[9]; buf[2]=gOv001FadeTable[10]; buf[3]=gOv001FadeTable[11];
if(arg1==1) p=(void *)gOv001FadeStates; else p=(u8 *)gOv001FadeStates+12;
if(M2C_FIELD(p,u8 *,9)) return 0;
if(arg1==1) GX_SetBlendControl(0x4001050,arg2,buf[arg0]); else GX_SetBlendControl(0x4000050,arg2,buf[arg0]);
M2C_FIELD(p,s32 *,0)=(s32)func_ov001_0218c884(1,(s32)Ov001_UpdateFade,p,200);
M2C_FIELD(p,u16 *,4)=0;
M2C_FIELD(p,u8 *,8)=arg0;
M2C_FIELD(p,u16 *,6)=arg3;
M2C_FIELD(p,u8 *,9)=1;
return 1;
}

/* Task callback of one ov001 screen fade: advance its frame counter, map the
 * progress to a BLDY blend value through the fade table and write it to the
 * engine's blend register; when the duration is reached write the mode's end
 * value, clear the fade and post the completion message. */
void Ov001_UpdateFade(M2C_UNK task, void *fadeArg) {
    s32 func_02002088(s32, u16);
    void GX_SetBlendY(s32, s32);
    void Ov001_PostTaskMessage(s32, s32);
    extern u8 gOv001FadeTable[];
    extern M2C_UNK gOv001FadeStates;

    u8 table[8];
    Ov001Fade *fade;
    s32 ramp;
    u16 duration;
    s32 value;
    u8 mode;
    u8 flags;
    u8 *flagTable;
    s16 elapsed;
    u16 limit;
    u8 endMode;

    fade = fadeArg;

    table[4] = gOv001FadeTable[OV001_FADE_FLAGS + 0];
    table[5] = gOv001FadeTable[OV001_FADE_FLAGS + 1];
    table[6] = gOv001FadeTable[OV001_FADE_FLAGS + 2];
    table[7] = gOv001FadeTable[OV001_FADE_FLAGS + 3];
    table[0] = gOv001FadeTable[OV001_FADE_END_BLEND + 0];
    table[1] = gOv001FadeTable[OV001_FADE_END_BLEND + 1];
    table[2] = gOv001FadeTable[OV001_FADE_END_BLEND + 2];
    table[3] = gOv001FadeTable[OV001_FADE_END_BLEND + 3];

    fade->counter = fade->counter + 1;
    ramp = (s32)fade->counter << 4;
    duration = fade->duration;
    value = func_02002088(ramp, duration);

    mode = fade->mode;
    flagTable = table + OV001_FADE_MODE_COUNT;
    flags = flagTable[mode];
    if (flags & OV001_FADE_INVERT) {
        value = 0x10 - value;
    }
    if (flags & OV001_FADE_NEGATE) {
        value = -value;
    }

    if (fade == (Ov001Fade *)gOv001FadeStates) {
        GX_SetBlendY(GX_BLDCNT_SUB, value);
    } else {
        GX_SetBlendY(GX_BLDCNT_MAIN, value);
    }

    elapsed = fade->counter;
    limit = fade->duration;
    if (elapsed >= (s32)limit) {
        endMode = fade->mode;
        if (fade == (Ov001Fade *)gOv001FadeStates) {
            GX_SetBlendY(GX_BLDCNT_SUB, (s32)(s8)table[endMode]);
        } else {
            GX_SetBlendY(GX_BLDCNT_MAIN, (s32)(s8)table[endMode]);
        }
        fade->active = 0;
        Ov001_PostTaskMessage(1, (s32)task);
    }
}

s32 func_ov001_0218aa24(s32 arg0) {
    void *func_ov001_0218c884(s32, M2C_UNK, void *, s32);
    void func_ov001_0218aa7c(M2C_UNK, void *);
    extern M2C_UNK gOv001FadeStates;
    s32 a = arg0;
    void *r4 = (void *)gOv001FadeStates;
    if (*((u8 *)r4 + 9) != 0) {
        return 0;
    }
    *(void **)r4 = func_ov001_0218c884(1, (M2C_UNK)func_ov001_0218aa7c, r4, 0xc8);
    *(u16 *)((u8 *)r4 + 4) = 0;
    *(u16 *)((u8 *)r4 + 6) = (u16)a;
    *((u8 *)r4 + 9) = 1;
    return 1;
}

void func_ov001_0218aa7c(M2C_UNK arg0, void *arg1) {
    void Ov001_PostTaskMessage(M2C_UNK, M2C_UNK);
    M2C_FIELD(arg1, s16 *, 4) = (s16) (M2C_FIELD(arg1, s16 *, 4) + 1);
    if ((s32) M2C_FIELD(arg1, s16 *, 4) < (s32) M2C_FIELD(arg1, u16 *, 6)) {
        return;
    }
    M2C_FIELD(arg1, s8 *, 9) = 0;
    Ov001_PostTaskMessage(1, arg0);
}

void func_ov001_0218aab4(void) {
    void *Ov001_Alloc(s32, M2C_UNK);
    void *Ov001_QueueCreateFromBuffer(s32, s32, s32);
    s32 Ov001_GetLanguage(void);
    s32 Ov001_LoadFile(M2C_UNK, M2C_UNK *, M2C_UNK);
    void func_ov001_02169130(void *, M2C_UNK);
    extern M2C_UNK data_ov001_02193e40;
    extern M2C_UNK data_ov001_021917c0;
    extern M2C_UNK data_ov001_021917c8;
    M2C_UNK p;

    p = (M2C_UNK)Ov001_Alloc(0x680, 4);
    data_ov001_02193e40 = p;
    M2C_FIELD((void *)data_ov001_02193e40, void **, 0x670) = Ov001_QueueCreateFromBuffer(0x20, (s32)p + 0x10, 0x30);

    if (Ov001_GetLanguage() == 6) {
        s32 i;
        s32 acc = 0;
        M2C_UNK *arr = (M2C_UNK *)(&data_ov001_021917c0);
        for (i = 0; i < 2; i++) {
            M2C_FIELD((void *)data_ov001_02193e40 + i * 4, M2C_UNK *, 0x674) =
                (M2C_UNK)Ov001_LoadFile(arr[i], 0, 4);
            func_ov001_02169130((void *)data_ov001_02193e40 + acc,
                M2C_FIELD((void *)data_ov001_02193e40 + i * 4, M2C_UNK *, 0x674));
            acc += 8;
        }
    } else {
        s32 acc = 0;
        s32 i;
        M2C_UNK *arr = (M2C_UNK *)(&data_ov001_021917c8);
        for (i = 0; i < 2; i++) {
            M2C_FIELD((void *)data_ov001_02193e40 + i * 4, M2C_UNK *, 0x674) =
                (M2C_UNK)Ov001_LoadFile(arr[i], 0, 4);
            func_ov001_02169130((void *)data_ov001_02193e40 + acc,
                M2C_FIELD((void *)data_ov001_02193e40 + i * 4, M2C_UNK *, 0x674));
            acc += 8;
        }
    }
}

void func_ov001_0218abb8(void) {
 void Ov001_FreeFile(s32);
 void func_ov001_0218a6d8(s32,...);
 M2C_UNK func_ov001_0218b71c(M2C_UNK *);
 extern M2C_UNK data_ov001_02193e40;
 extern M2C_UNK data_ov001_02193e44;
 M2C_UNK *p=&data_ov001_02193e40;
 s32 i;
 for(i=0;i<2;i++)Ov001_FreeFile(*((s32 *)((u8 *)(*p)+0x674)+i));
 func_ov001_0218a6d8(*((s32 *)((u8 *)data_ov001_02193e40+0x670)));
 func_ov001_0218b71c(&data_ov001_02193e44-1);
}

void *func_ov001_0218ac04(s32 a,s32 b,s32 c,s32 d,s32 *out,s32 e){
extern M2C_UNK data_ov001_02193e40;
s32 func_ov001_0218c228(s32,s32,s32,s32 *);s32 func_ov001_0216a33c(s32,s32);void func_ov001_0216a1a8(void *,s32,s32,s32,s32);
u8 *p;s32 n; s32 base; s32 index;
p=(u8 *)func_ov001_0218a74c((void *)M2C_FIELD(data_ov001_02193e40,s32 *,0x670));
p[46]=b;p[47]=c;
M2C_FIELD(p,s32 *,40)=func_ov001_0218c228(a,b*c,d,&n);
M2C_FIELD(p,u16 *,44)=n;
*out=func_ov001_0216a33c(b,c);
index=n; if(a==1) base=0x6600000; else base=0x6400000;
func_ov001_0216a1a8(p,base+(index<<7),b,c,4);
((void (*)(void *,s32))M2C_FIELD(M2C_FIELD(p,void **,20),void **,4))(p,0);
index=data_ov001_02193e40+e*8;
M2C_FIELD(p,void **,24)=p;
M2C_FIELD(p,s32 *,28)=index;
M2C_FIELD(p,s32 *,32)=1;M2C_FIELD(p,s32 *,36)=1;
return p;
}

void func_ov001_0218ace0(M2C_UNK arg0) {
    M2C_UNK func_ov001_0218c3a0(M2C_UNK);
    void func_ov001_0218a6f4(void *, s32);
    extern M2C_UNK data_ov001_02193e40;
    func_ov001_0218c3a0(M2C_FIELD((void *)arg0, M2C_UNK *, 0x28));
    func_ov001_0218a6f4((void *)M2C_FIELD((void *)data_ov001_02193e40, M2C_UNK *, 0x670), arg0);
}

#pragma opt_propagation off
void *CreateTextPanel(s32 arg0,s32 arg1) {
void *Ov001_Alloc(s32,s32); void func_ov001_0216a17c(void*,void*,s32,s32,s32);
s32 func_020036b8(void); s32 func_02003684(void);
void func_ov001_0216a230(s32,s32,s32,s32,s32,s32,s32,u32);
void func_ov001_0218b1ec(void*,s32); void *func_ov001_0218c884(s32,M2C_UNK,void*,s32); void func_ov001_0218ae84(M2C_UNK,void*);
extern M2C_UNK data_ov001_02193e40; extern u8 data_ov001_0218fd18[],data_ov001_0218fd1a[],data_ov001_0218fd14[];
void *base;
void *p=(u8*)(void*)data_ov001_02193e40+0x610+arg0*0x30;
u32 a=*(u16*)(data_ov001_0218fd1a+arg0*4);
u32 b=*(u16*)(data_ov001_0218fd18+arg0*4); s32 v; u16 c; s32 zero;
*(void**)((u8*)p+0x28)=Ov001_Alloc((b*a)<<5,32);
if(arg0==1) { *(volatile u16*)0x4001008 &= ~0x40; *(volatile u16*)0x4001008=(*(volatile u16*)0x4001008&0x43)|0xc00; }
else { *(volatile u16*)0x4000008 &= ~0x40; *(volatile u16*)0x4000008=(*(volatile u16*)0x4000008&0x43)|0xc00; }
func_ov001_0216a17c(p,*(void**)((u8*)p+0x28),b,a,4);
base=(void*)data_ov001_02193e40;
*(void**)((u8*)p+0x18)=p;
*(void**)((u8*)p+0x1c)=(u8*)base+arg1*8;
*(s32*)((u8*)p+0x20)=1; *(s32*)((u8*)p+0x24)=1;
if(arg0==1) v=func_020036b8(); else v=func_02003684();
zero=0;
c=*(volatile u16*)(data_ov001_0218fd14+arg0*2);
func_ov001_0216a230(v,b,a,zero,zero,32,c,15);
func_ov001_0218b1ec(p,0);
*(void**)((u8*)p+0x2c)=func_ov001_0218c884(1,(M2C_UNK)func_ov001_0218ae84,(u8*)(void*)data_ov001_02193e40+0x67c+arg0,200);
return p;
}
#pragma opt_propagation reset
void func_ov001_0218ae84(M2C_UNK arg0, void *arg1) {
    void DC_FlushRange(M2C_UNK, s32);
    void func_0200454c(M2C_UNK, s32, u32);
    void func_020045ac(M2C_UNK, s32, u32);
    extern M2C_UNK data_ov001_02193e40;
    if (!*(u8 *)arg1) {
        return;
    }
    if (arg1 == (void *)((u8 *)data_ov001_02193e40 + 0x67C)) {
        DC_FlushRange(M2C_FIELD((void *)data_ov001_02193e40, M2C_UNK *, 0x638), 0x6000);
        func_0200454c(M2C_FIELD((void *)data_ov001_02193e40, M2C_UNK *, 0x638), 0, 0x6000);
    } else {
        DC_FlushRange(M2C_FIELD((void *)data_ov001_02193e40, M2C_UNK *, 0x668), 0x3000);
        func_020045ac(M2C_FIELD((void *)data_ov001_02193e40, M2C_UNK *, 0x668), 0x3000, 0x3000);
    }
    *(u8 *)arg1 = 0;
}

M2C_UNK func_ov001_0218af0c(s32 arg0) {
    extern M2C_UNK data_ov001_02193e40;
    M2C_UNK temp_r0;
    func_ov001_0218c94c(1, M2C_FIELD((void *)arg0, M2C_UNK *, 0x2C));
    if (arg0 == (M2C_UNK)data_ov001_02193e40 + 0x610) {
        temp_r0 = FillU16(0, func_02003834(), 0x6000);
    } else {
        temp_r0 = FillU16(0, func_02003834(), 0x3000);
    }
    return func_ov001_0218b71c((u8 *)arg0 + 0x28);
}

void func_ov001_0218af70(s32 arg0) {
    M2C_UNK func_ov001_0218af0c(s32);
    extern s32 data_ov001_02193e40;
    func_ov001_0218af0c((0x30 * arg0) + (data_ov001_02193e40 + 0x610));
}

void func_ov001_0218af94(void *arg0,s32 x,s32 y,s32 b,s32 arg4,s32 arg5) {
M2C_UNK DrawAnchoredText(void *,s32,s32,s32,s32,s32,TextDirection);
void **p=M2C_FIELD(arg0,void ***,0x1c);
TextDirection dir={0,0};
u8 type=M2C_FIELD(M2C_FIELD(*p,void **,8),u8 *,7);
switch(type){
case 0: case 7:dir.x=1;break;
case 1: case 2:dir.y=1;break;
case 3: case 4:dir.x=-1;break;
case 5: case 6:dir.y=-1;break;
default:break;
}
DrawAnchoredText(arg0+0x18,x,y,b,arg4,arg5,dir);
}

void func_ov001_0218b044(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4, s32 arg5) {
    M2C_UNK DrawTextGlyph(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    extern M2C_UNK data_ov001_02193e40;
    M2C_UNK base = data_ov001_02193e40;
    DrawTextGlyph((M2C_UNK)arg0, (M2C_UNK)((u8 *)base + arg5 * 8), arg1, arg2, (M2C_UNK)arg3, (M2C_UNK)arg4);
}

void DrawTextRun(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 *arg5, s32 arg6) {
    s32 GetFontGlyphIndex(void **a, u32 b);
    void *GetFontGlyphMetric(void **a, u32 b);
    void func_ov001_0218b044(void *, s32, s32, s32, u16, s32);
    extern M2C_UNK data_ov001_02193e40;
    void **entry;
    s32 id;
    void *p;
    if (*arg5 == 0) return;
    do {
        entry = (void **)((u8 *)data_ov001_02193e40 + arg6 * 8);
        id = GetFontGlyphIndex(entry, *arg5);
        if (id == 0xffff) id = M2C_FIELD(*entry, u16 *, 2);
        p = GetFontGlyphMetric(entry, id);
        func_ov001_0218b044(arg0, arg1 + ((arg4 - M2C_FIELD(p, s8 *, 2)) >> 1), arg2, arg3, *arg5, arg6);
        arg5++;
        arg1 += arg4;
    } while (*arg5);
}

void DrawPanelText(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    M2C_UNK func_ov001_0216a9d0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    u8 spC;
    u8 spD;
    u8 temp_ip;

    M2C_FIELD(&spC, u8 *, 0) = 0;
    M2C_FIELD(&spD, u8 *, 0) = 0;
    temp_ip = M2C_FIELD(M2C_FIELD(*M2C_FIELD(arg0, void ***, 0x1C), void **, 8), u8 *, 7);
    switch (temp_ip) {
    default:
        break;
    case 0:
    case 7:
        M2C_FIELD(&spC, u8 *, 0) = 1;
        break;
    case 1:
    case 2:
        M2C_FIELD(&spD, u8 *, 0) = 1;
        break;
    case 3:
    case 4:
        M2C_FIELD(&spC, u8 *, 0) = (u8)-1;
        break;
    case 5:
    case 6:
        M2C_FIELD(&spD, u8 *, 0) = (u8)-1;
        break;
    }
    func_ov001_0216a9d0((s32)(arg0 + 0x18), arg1, arg2, arg3, arg4, arg5, arg6, arg7, spC, spD);
}

void func_ov001_0218b1ec(void *arg0, s32 arg1) {
M2C_FIELD(M2C_FIELD(arg0,void **,0x14),void (**)(void *,s32),4)(arg0,arg1);
}

void func_ov001_0218b200(void *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK func_ov001_0216a398(s32, u8, u8, M2C_UNK, s32, s32, s32, s32);
          s32 Ov001_GetSpriteObjEntry(s32, s32);
    M2C_UNK func_ov001_0218a260(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    M2C_UNK func_ov001_0218a304(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
    void Ov001_SetSpritePalette(M2C_UNK, M2C_UNK, s32);
    s32 temp_r5;

    temp_r5 = Ov001_GetSpriteObjEntry(arg3, 0);
    func_ov001_0218a260(arg3, -1, 0, 0);
    func_ov001_0218a304(arg3, -1, 0, 0xF);
    Ov001_SetSpritePalette(arg3, -1, arg4);
    func_ov001_0216a398(temp_r5, M2C_FIELD(arg0, u8 *, 0x2E), M2C_FIELD(arg0, u8 *, 0x2F), arg1, arg2, 0, (s32) M2C_FIELD(arg0, u16 *, 0x2C), 2);
}

void CloseTextPanel(s32 arg0) {
    extern M2C_UNK data_ov001_02193e40;
    void *p = M2C_FIELD(&data_ov001_02193e40, void **, 0);
    if (arg0 == (s32)p + 0x610) {
        M2C_FIELD(p, u8 *, 0x67c) = 1;
    } else {
        M2C_FIELD(p, u8 *, 0x67d) = 1;
    }
}

void func_ov001_0218b2bc(s16 arg0, s16 arg1, void *arg2) {
    M2C_FIELD(arg2, s16 *, 0) = arg0;
    M2C_FIELD(arg2, s16 *, 2) = arg1;
}

void SetRect16(s16 arg0, s16 arg1, s16 arg2, s16 arg3, void *arg4) {
    M2C_FIELD(arg4, s16 *, 0) = arg0;
    M2C_FIELD(arg4, s16 *, 2) = arg1;
    M2C_FIELD(arg4, s16 *, 4) = arg2;
    M2C_FIELD(arg4, s16 *, 6) = arg3;
}

void BuildTouchRect(void *arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg2, u16 *, 0) = (u16) M2C_FIELD(arg0, u16 *, 0);
    M2C_FIELD(arg2, u16 *, 2) = (u16) M2C_FIELD(arg0, u16 *, 2);
    M2C_FIELD(arg2, s16 *, 4) = (s16) (M2C_FIELD(arg0, u16 *, 0) + M2C_FIELD(arg1, u16 *, 0));
    M2C_FIELD(arg2, s16 *, 6) = (s16) (M2C_FIELD(arg0, u16 *, 2) + M2C_FIELD(arg1, u16 *, 2));
}

void func_ov001_0218b314(s32 arg0, s32 arg1) {
    if (arg0 == 1) {
        volatile u32 *p1 = (volatile u32 *)0x04001000;
        u32 t1 = *p1 & 0x1F00;
        *p1 = (*p1 & ~0x1F00) | ((arg1 | (t1 >> 8)) << 8);
        return;
    }
    {
        volatile u32 *p2 = (volatile u32 *)0x04000000;
        u32 t2 = *p2 & 0x1F00;
        *p2 = (*p2 & ~0x1F00) | ((arg1 | (t2 >> 8)) << 8);
    }
}

