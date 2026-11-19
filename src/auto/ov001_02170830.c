/* 28 functions from 0x02170830 to 0x021717FC (ov001), found by ds-decomp. */
#include "common.h"
extern s32 gWhState[];
extern s32 gWhPacketInfo[];
extern u8 data_ov001_0219283c[];
typedef struct { u32 words[58]; } NetworkClearState;
typedef struct { u32 w[8]; } ClearBlk8;
typedef struct { u32 w[2]; } ClearBlk2;
extern u32 gOv001LinkMatchSetup[];
void func_ov001_0216f78c(void);
s32 func_ov001_0216e34c(s32);
s32 func_02005ab0(void);
void TaskCreate(void *,void (*)(void),s32,s32,s32,s32);
void TaskWake(void *);
void func_ov001_021713a8(void);
extern void *gOv001IconRow;
extern const u8 gOv001IconRowCount[];
extern const u8 gOv001IconRowSlot[];
extern const u16 gOv001IconRowX[];
void Ov001_MoveSpriteLayout(void *, s32, s32, void *);

#pragma thumb on
void func_ov001_02171078(u8 *a,volatile u32 *b,u32 n){u32 i;for(i=0;i<n;i+=4){a[i]=*b;a[i+1]=*b>>8;a[i+2]=*b>>16;a[i+3]=*b>>24;b++;}}
#pragma thumb on
void func_ov001_021710a4(u32 *a,u8 *b,u32 n){u32 i;for(i=0;i<n;i+=4){*a++=b[i]|(b[i+1]<<8)|(b[i+2]<<16)|(b[i+3]<<24);}}

#pragma thumb on
void func_ov001_021710d0(u8 *a,u8 *b,u32 n){u32 i;for(i=0;i<n;i++)a[i]=b[i];}
#pragma thumb off

#pragma thumb on
void func_ov001_021710e8(s8 *a,s32 b,u32 n){u32 i;for(i=0;i<n;i++)*a++=(s8)b;}

void func_ov001_02171100(M2C_UNK a,M2C_UNK b,M2C_UNK c){
 M2C_UNK func_ov001_0217073c(M2C_UNK *);M2C_UNK func_ov001_02170764(M2C_UNK *,M2C_UNK,M2C_UNK);M2C_UNK func_ov001_021707dc(M2C_UNK,M2C_UNK *);
 M2C_UNK p[22];func_ov001_0217073c(p);func_ov001_02170764(p,b,c);func_ov001_021707dc(a,p);
}

void WhGetTime(void){u64 GetSystemTick(void);void U64Divide(u64,u64);U64Divide(GetSystemTick()<<6,0x82ea);}

#pragma thumb on
s32 func_ov001_02171178(s8 *a, s32 b) {
    s32 v, ch, i;
    u8 t = (u8)b;
    s8 *p;
    v = (t & 0xF0) >> 4;
    p = a;
    i = 0;
    do {
        if (v <= 9) ch = v + 0x30; else ch = v + 0x37;
        i++;
        *p++ = (s8)ch;
        v = t & 0x0F;
    } while (i < 2);
    *p = 0;
    return (s32)(p - a);
}
s32 func_ov001_021711ac(s8 *arg0,s8 *arg1){
 s8 *sp0=arg0; s8 *p=arg0; s32 i; s8 *q=arg1,*t;s8 v;
 for(i=0;i<6;i++){v=*q++;t=p+func_ov001_02171178(p,v);p=t;if(i<5){p=t+1;*t=0x3a;}}
 *p=0;return p-sp0;
}

void *memset(void *,s32,u32);
#pragma optimize_for_size off
s32 func_ov001_021711e0(s32 a,s32 b,s32 c,s32 (*d)(s32),s32 e,s32 f){
s32 r;u32 i;u32 *p;
if(gWhState[14]>=1 && gWhState[14]<=5)return -10;
gWhPacketInfo[4]=b;gWhState[14]=7;gWhState[31]=c;((s32 (**)(s32))gWhState)[1]=d;gWhState[3]=e;gWhPacketInfo[2]=f;
r=func_ov001_0216e34c(b);gWhState[29]=1;if(r<0){gWhState[30]=r;return r;}
r=((s32 (**)(s32))gWhState)[1](gWhPacketInfo[2]);gWhState[12]=r;if(!r){gWhState[30]=-1;return -1;}if(func_02005ab0()!=1){gWhState[30]=-9;return -9;}
TaskCreate(data_ov001_0219283c,func_ov001_0216f78c,0,gWhState[12]+(gWhPacketInfo[2]&~7),gWhPacketInfo[2],a);gWhState[14]=1;gWhPacketInfo[3]=((s32 (*)(void))WhGetTime)()+60000;gWhState[4]=0;
p=gOv001LinkMatchSetup;i=58;do{*p++=0;}while(--i);
func_ov001_021713a8();TaskWake(data_ov001_0219283c);gWhState[25]=1;return 1;
}
#pragma optimize_for_size reset
void Ov001_AnimSpriteTask(void);
#pragma thumb off
void Ov001_CreateAnimSprite(s8 arg0) {
s32 *Ov001_CreateSpriteFromLayout(s32,s32); void *Ov001_Alloc(s32,s32); s32 Ov001_AddTask(s32,void (*)(void),s32,s32);
extern M2C_UNK gOv001AnimSpritePalette; extern void *gOv001AnimSprite;
s32 *p,*q,*r; void *a; s8 v;
a=Ov001_Alloc(12,4);gOv001AnimSprite=a;M2C_FIELD(a,s8 *,8)=arg0;
M2C_FIELD(gOv001AnimSprite,s32 **,4)=Ov001_CreateSpriteFromLayout(0,0x47);
v=((u8 *)&gOv001AnimSpritePalette)[arg0];
p=M2C_FIELD(gOv001AnimSprite,s32 **,4);
M2C_FIELD(p,u16 *,4)=(M2C_FIELD(p,u16 *,4)&~0xc00)|0x400;
q=M2C_FIELD(gOv001AnimSprite,s32 **,4);*q&=~0xc00;
M2C_FIELD(q,u16 *,4)=(M2C_FIELD(q,u16 *,4)&~0xf000)|((u8)v<<12);
r=M2C_FIELD(gOv001AnimSprite,s32 **,4);*r=(*r&0xfe00ff00)|0xe6008b;
M2C_FIELD(gOv001AnimSprite,s32 *,0)=Ov001_AddTask(1,Ov001_AnimSpriteTask,0,120);
}
#pragma merge_constants off
void Ov001_FreeOptionSprites(void) {
    M2C_UNK Ov001_FreeAlloc(void **);
    M2C_UNK Ov001_ReleaseSprite(s32);
    M2C_UNK func_ov001_0218c94c(M2C_UNK, s32);
    extern void *gOv001AnimSprite;
    extern void *gOv001IconRow;
    func_ov001_0218c94c(1, M2C_FIELD(gOv001AnimSprite, s32 *, 0));
    Ov001_ReleaseSprite(M2C_FIELD(gOv001AnimSprite, s32 *, 4));
    Ov001_FreeAlloc(&gOv001IconRow - 1);
}
#pragma merge_constants reset
/* Per-frame task of the animated icon sprite: step the frame tick (wrapping at
 * 40), point the sprite's obj layout at the animation frame the tick selects,
 * then apply the attribute and palette bits of the sprite's kind. */
void Ov001_AnimSpriteTask(void) {
    s32 HardwareDivide(u8, M2C_UNK);
    u8 HardwareDivideRemainder(s32, M2C_UNK);
    M2C_UNK Ov001_LoadSpriteObjLayout(M2C_UNK, s32, s32 *);
    extern M2C_UNK gOv001AnimSpritePalette;
    extern void *gOv001AnimSprite;
    s32 frame;
    u8 palette;
    s32 *entry;
    s32 *obj;
    s32 *obj2;

    M2C_FIELD(gOv001AnimSprite, u8 *, 9) = HardwareDivideRemainder(M2C_FIELD(gOv001AnimSprite, u8 *, 9) + 1, (M2C_UNK)0x28);
    frame = HardwareDivide(M2C_FIELD(gOv001AnimSprite, u8 *, 9), 5);
    Ov001_LoadSpriteObjLayout(0, frame + 0x47, M2C_FIELD(gOv001AnimSprite, s32 **, 4));
    obj = M2C_FIELD(gOv001AnimSprite, s32 **, 4);
    M2C_FIELD(obj, u16 *, 4) = (u16) ((M2C_FIELD(obj, u16 *, 4) & ~0xC00) | 0x400);
    palette = ((u8 *)&gOv001AnimSpritePalette)[M2C_FIELD(gOv001AnimSprite, u8 *, 8)];
    obj2 = M2C_FIELD(gOv001AnimSprite, s32 **, 4);
    M2C_FIELD(obj2, s32 *, 0) &= ~0xC00;
    M2C_FIELD(obj2, u16 *, 4) = (u16) ((M2C_FIELD(obj2, u16 *, 4) & ~0xF000) | (palette << 0xC));
    entry = M2C_FIELD(gOv001AnimSprite, s32 **, 4);
    *entry = (*entry & 0xFE00FF00) | 0xE6008B;
}

/* Build the state for a render effect indexed by id: allocate the 28-byte
   control block, load its sprite list from gOv001IconRowLayout, and set up
   animation timer (120 units). */
void func_ov001_0217159c(s32 id) {
    extern const u8 gOv001IconRowLayout[];
    void Ov001_IconRow_Layout(void *);
    void *Ov001_Alloc(s32, s32);
    void *Ov001_CreateSprite(s32, s32, s32);
    void Ov001_SetSpritePalette(void *, s32, s32);
    void Ov001_IconRow_SlideOut(void);
    s32 Ov001_AddTask(s32, void (*)(void), s32, s32);
    s32 n, i;
    const u8 *p;
    n = gOv001IconRowCount[id];
    gOv001IconRow = Ov001_Alloc(28, 4);
    M2C_FIELD(gOv001IconRow, s8 *, 22) = -2;
    M2C_FIELD(gOv001IconRow, u8 *, 23) = id;
    i = 0;
    if (n > 0) {
        p = gOv001IconRowLayout + id * 2;
        do {
            ((void **)gOv001IconRow)[i] = Ov001_CreateSprite(0, *p++, 1);
            Ov001_SetSpritePalette(((void **)gOv001IconRow)[i], -1, 1);
            i++;
        } while (i < n);
    }
    M2C_FIELD(gOv001IconRow, void **, 8) = Ov001_CreateSprite(0, 1, 1);
    Ov001_SetSpritePalette(M2C_FIELD(gOv001IconRow, void **, 8), -1, 1);
    Ov001_IconRow_Layout((void *)192);
    M2C_FIELD(gOv001IconRow, s32 *, 12) = Ov001_AddTask(0, Ov001_IconRow_SlideOut, 0, 120);
}

void func_ov001_02171694(void){
 extern void *gOv001IconRow;void Ov001_SetSlideStep(s32,void (*)(void));void func_ov001_02171a44(void);
 M2C_FIELD(gOv001IconRow,u8 *,0x19)=1;
 Ov001_SetSlideStep(M2C_FIELD(gOv001IconRow,s32 *,12),func_ov001_02171a44);
}

#pragma thumb off

#pragma thumb off

s8 Ov001_GetIconRowSelection(void) {
    extern void *gOv001IconRow;
    return M2C_FIELD(gOv001IconRow, s8 *, 0x16);
}

void Ov001_LatchIconRowSelection(s8 a){if(M2C_FIELD(gOv001IconRow,s8 *,0x16)==-1)M2C_FIELD(gOv001IconRow,s8 *,0x16)=a;}

void Ov001_SetIconRowSelection(s8 a){extern void *gOv001IconRow;M2C_FIELD(gOv001IconRow,s8 *,0x16)=a;}

s32 Ov001_IsIconRowIdle(void){if(gOv001IconRow==NULL)return 1;if(M2C_FIELD(gOv001IconRow,u8 *,0x19)==0)return 1;return 0;}

#pragma thumb off
void Ov001_UnlockIconRow(void){extern void *gOv001IconRow;M2C_FIELD(gOv001IconRow,u8 *,0x18)=0;}

void Ov001_LockIconRow(void){M2C_FIELD(gOv001IconRow,u8 *,0x18)=1;}

/* Places the icon row's sprites at height `y` (the row's y coordinate, passed on
 * as the layout helper's pointer-sized y): the wide backdrop bar at `y` and each
 * bar of the current page at the X its slot table gives, 4 pixels below the
 * backdrop. */
void Ov001_IconRow_Layout(void *y) {
    s32 n, i;

    n = gOv001IconRowCount[((Ov001IconRow *)gOv001IconRow)->page];
    Ov001_MoveSpriteLayout(((Ov001IconRow *)gOv001IconRow)->backdrop, -1, 0, y);
    for (i = 0; i < n; i++)
        Ov001_MoveSpriteLayout(((Ov001IconRow *)gOv001IconRow)->bars[i], -1,
            gOv001IconRowX[((const u8 (*)[2])gOv001IconRowSlot)[((Ov001IconRow *)gOv001IconRow)->page][i] * 2],
            (u8 *)y + 4);
}

