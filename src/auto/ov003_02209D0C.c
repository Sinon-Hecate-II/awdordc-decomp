/* 7 functions from 0x02209D0C to 0x0220ACCC (ov003), found by ds-decomp. */
#include "common.h"


static inline void UpdateA9Slider(void *p, s16 value) {
    s32 Divide(s32, s32);
    void func_020a979c(void *, s16, s16);
    void *object;
    s16 position, current, limit, base;
    M2C_FIELD(p,s16 *,0x12)=value;
    limit=M2C_FIELD(p,s16 *,0x16);
    current=M2C_FIELD(p,s16 *,0x12);
    if(current<=limit) {
        limit=M2C_FIELD(p,s16 *,0x14);
        if(current>=limit)limit=current;
    }
    M2C_FIELD(p,s16 *,0x12)=limit;
    object=M2C_FIELD(p,void **,0x1c);
    base=M2C_FIELD(p,s16 *,8);
    position=base+Divide(M2C_FIELD(p,s16 *,0x12)*(s16)(M2C_FIELD(object,s16 *,0x14)-M2C_FIELD(object,s16 *,0x12)),M2C_FIELD(p,s16 *,0x16)-M2C_FIELD(p,s16 *,0x14));
    func_020a979c(M2C_FIELD(p,void **,0x1c),position,M2C_FIELD(M2C_FIELD(p,void **,0x1c),s16 *,0xa));
}

static inline void UpdateA9Value(void *p,s32 value) {
    s32 current,limit;
    M2C_FIELD(p,s32 *,4)=value;
    if(M2C_FIELD(p,u8 *,0x14)) {
        while(M2C_FIELD(p,s32 *,4)>M2C_FIELD(p,s32 *,8))
            M2C_FIELD(p,s32 *,4)-=M2C_FIELD(p,s32 *,8)-M2C_FIELD(p,s32 *,12)+1;
        while(M2C_FIELD(p,s32 *,4)<M2C_FIELD(p,s32 *,12))
            M2C_FIELD(p,s32 *,4)+=M2C_FIELD(p,s32 *,8)-M2C_FIELD(p,s32 *,12)+1;
    } else {
        limit=M2C_FIELD(p,s32 *,8);
        current=M2C_FIELD(p,s32 *,4);
        if(current<=limit) {
            limit=M2C_FIELD(p,s32 *,12);
            if(current>=limit)limit=current;
        }
        M2C_FIELD(p,s32 *,4)=limit;
    }
}


#pragma opt_strength_reduction off
M2C_UNK func_ov003_02209d0c(void *a,s32 b) {
void func_ov003_0220a5fc(void *,s32);void func_ov003_0220a658(void *,s32);
u8 func_ov003_022066c8(u8);void *func_ov003_022066a8(u8);
s16 func_020bfa20(void);s16 func_020bf9e0(void);
void func_ov003_0220accc(void *,u8);void Clear3DSpriteLayer(s32);
s32 GetLanguage(void);s32 GetLocalizedText(void *);s32 func_0209c2a8(s32);
void func_0209b26c(u8,s32,s32,void *,s32,u16);
void func_ov003_0220a864(M2C_UNK);void func_02088f1c(void *);void func_02088ff4(void *);s32 func_02089080(void *);
void func_02087ec0(void *,s16);void func_ov003_02207a8c(void *);M2C_UNK Ov003_RefreshListRowAnimations(void *,s32,s32);
extern M2C_UNK data_0215d9b8;extern u8 data_ov003_02210c80[];extern void *gCur3DSpriteEngine;
void *p;u8 i,total,j,x;s32 tile,k,mode;
M2C_FIELD(a,u8 *,0x38)|=2;
func_ov003_0220a5fc(a,b);
mode=M2C_FIELD(a,u8 *,0x34);
p=M2C_FIELD(a,void **,0x54);
M2C_FIELD(p,s16 *,0xe)=0;M2C_FIELD(p,s16 *,0x10)=16;
M2C_FIELD(p,s16 *,0xc)=mode;
M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);
func_ov003_0220a658(a,b);
M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,0x10)=func_ov003_022066c8(b);
M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)=b;
M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,17)=16;
if((u8)(M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)==8)) {
UpdateA9Slider(M2C_FIELD(a,void **,0x64),func_020bfa20());
UpdateA9Slider(M2C_FIELD(a,void **,0x60),func_020bf9e0());
p=M2C_FIELD(a,void **,0x40);
UpdateA9Value(p,(u32)(M2C_FIELD(&data_0215d9b8,u16 *,6)<<18)>>30);
UpdateA9Value((u8 *)p+24,(u32)(M2C_FIELD(&data_0215d9b8,u16 *,6)<<20)>>30);
UpdateA9Value((u8 *)p+48,(u32)(M2C_FIELD(&data_0215d9b8,u16 *,6)<<17)>>31);
}
M2C_FIELD(a,void **,0x44)=func_ov003_022066a8(b);
for(i=0;i<M2C_FIELD(M2C_FIELD(a,void **,0x44),u8 *,0);i++) {
j=0;
total=j;
for(;j!=(u8)b;j++)total+=M2C_FIELD(func_ov003_022066a8(j),u8 *,0);
M2C_FIELD(M2C_FIELD(a,void **,0x48),void **,i*36)=data_ov003_02210c80+(total+i)*16;
}
if((u8)(((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)==0)) {
func_ov003_0220accc(a,b);
Clear3DSpriteLayer(1);
switch(GetLanguage()) {case 1:case 2:case 3:case 4:case 5:mode=1;break;default:mode=0;break;}
x=0;tile=1;
if(mode) {
void *text;u16 width;
text=M2C_FIELD(M2C_FIELD(M2C_FIELD(a,void **,0x58),void **,12),void **,0);
width=func_0209c2a8(GetLocalizedText(text));
func_0209b26c(x,0,1,text,0x2000,(u16)tile);tile+=width*2;
if(M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8)>1) {
x+=width;
func_0209b26c(x,0,1,(void *)0x4800000f,0x2000,(u16)tile);x++;tile+=2;
text=M2C_FIELD(M2C_FIELD(M2C_FIELD(a,void **,0x58),void **,16),void **,0);
width=func_0209c2a8(GetLocalizedText(text));
func_0209b26c(x,0,1,text,0x2000,(u16)tile);tile+=width*2;
if(M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8)>2) {
{s32 next=x+width;u16 position=tile;
func_0209b26c((u8)next,0,1,(void *)0x4800000f,0x2000,position);}tile+=2;
}}
x=0;
for(k=2;k<M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8);k++) {
text=M2C_FIELD(M2C_FIELD((u8 *)M2C_FIELD(a,void **,0x58)+k*4,void **,12),void **,0);
width=func_0209c2a8(GetLocalizedText(text));
func_0209b26c(x,2,1,text,0x2000,(u16)tile);x+=width;tile+=width*2;
if(k!=M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8)-1) {
func_0209b26c(x,2,1,(void *)0x4800000f,0x2000,(u16)tile);x++;tile+=2;
}
}
} else {
void *text;u16 width;
text=M2C_FIELD(M2C_FIELD(M2C_FIELD(a,void **,0x58),void **,12),void **,0);
width=func_0209c2a8(GetLocalizedText(text));
func_0209b26c(x,0,1,text,0x2000,(u16)tile);tile+=width*2;
if(M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8)>1) {
{s32 next=x+width;u16 position=tile;
func_0209b26c((u8)next,x,1,(void *)0x4800000f,0x2000,position);}tile+=2;
}
for(k=1;k<M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8);k++) {
text=M2C_FIELD(M2C_FIELD((u8 *)M2C_FIELD(a,void **,0x58)+k*4,void **,12),void **,0);
width=func_0209c2a8(GetLocalizedText(text));
func_0209b26c(x,2,1,text,0x2000,(u16)tile);x+=width;tile+=width*2;
if(k!=M2C_FIELD(M2C_FIELD(a,void **,0x58),u8 *,8)-1) {
func_0209b26c(x,2,1,(void *)0x4800000f,0x2000,(u16)tile);x++;tile+=2;
}
}
}
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=2;
}
func_ov003_0220a864((M2C_UNK)a);
if((u8)(M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)==8)) {
func_02088f1c(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,12));
if((u8)(((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)==0))
func_02088f1c(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,20));
} else {
func_02088ff4(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,12));
if((u8)(((u32)(M2C_FIELD(a,u8 *,0x36)<<24)>>28)==0))
func_02088ff4(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,20));
}
if((u8)(M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)==9))
func_02088f1c(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,16));
else func_02088ff4(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,16));
if((u8)(M2C_FIELD(M2C_FIELD(a,void **,0x3c),u8 *,15)==0))
func_02088ff4(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,0));
else if(func_02089080(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,0)))
func_02088f1c(M2C_FIELD(M2C_FIELD(a,void **,0x68),void **,0));
p=M2C_FIELD(a,void **,0x3c);
func_02087ec0(M2C_FIELD(a,void **,0x5c),(s16)((u8)(M2C_FIELD(p,u8 *,M2C_FIELD(p,u8 *,15))+1)+10));
func_ov003_02207a8c(a);
return Ov003_RefreshListRowAnimations(a,10,255);
}
#pragma opt_strength_reduction reset
void func_ov003_0220a5fc(void *arg0, s32 arg1) {
M2C_UNK SetFileDirectory(M2C_UNK *);
M2C_UNK func_0207c780(s32,s32);
s32 func_02080e30(s32,s32);
s32 GetLocalizedFileName(s32);
M2C_UNK HeapFreeBlock(s32);
extern void *g3DSpriteEngineSub;
extern M2C_UNK data_ov003_0220f240, data_ov003_0221118c, data_ov003_0221119c;
s32 temp_r0;
SetFileDirectory(&data_ov003_0221118c);
temp_r0=func_02080e30(GetLocalizedFileName((s32)&data_ov003_0221119c),1);
func_0207c780(temp_r0+M2C_FIELD(&data_ov003_0220f240,s32 *,arg1*16),M2C_FIELD(g3DSpriteEngineSub,s32 *,0x14));
HeapFreeBlock(temp_r0);
}

void func_ov003_0220a658(void *arg0, s32 arg1) {
    M2C_UNK func_02004b54();
    M2C_UNK func_02004cf0();
    M2C_UNK func_0207c780(s32, s32);
    s32 func_02080e30(s32, s32);
    s32 GetLocalizedFileName(s32);
    M2C_UNK HeapFreeBlock(s32);
    extern M2C_UNK data_ov003_0220f244;
    s32 temp_r4;
    temp_r4 = func_02080e30(GetLocalizedFileName(M2C_FIELD(&data_ov003_0220f244, s32 *, arg1 * 0x10)), 1);
    func_02004b54();
    func_0207c780(temp_r4, 0x06800000);
    func_02004cf0();
    HeapFreeBlock(temp_r4);
}

void Ov003_SetRowAnimation(void *arg0, s8 arg1) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x3C), s8 *, 0x11) = arg1;
    M2C_FIELD(arg0, u8 *, 0x38) = (u8) (M2C_FIELD(arg0, u8 *, 0x38) & ~1);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x50), s8 *, 1) = 1;
}

/* Per-frame update of the ov003 map-select screen while its transition timer
 * (screen+0x34) counts down: at 20 it resets the sliding sprite, at 11 it
 * restores the saved display bits and starts the new sprite object, at 10 it
 * reconfigures the list for the chosen entry, and when the timer expires it
 * redraws the label and window for that entry. */
u32 func_ov003_0220a6bc(void *screen) {
M2C_UNK func_020c01ec(void *);M2C_UNK DrawMapSelectLabel(void *);u32 UpdateMapSelectLabelTransform(void *);M2C_UNK RequestMenuMode(void *,M2C_UNK);
extern M2C_UNK data_0215d9b8;
u8 timer;u32 active,isPending; s32 modeIsZero,kindIs8,remaining;void *p;
timer=M2C_FIELD(screen,u8 *,0x34);active=timer!=0?1:0;if(!(active&255))return active;
isPending=(u32)(M2C_FIELD(screen,u8 *,0x38)<<27)>>31;if(isPending)return isPending;
if(timer==20){p=M2C_FIELD(screen,void **,0x54);M2C_FIELD(p,s16 *,14)=16;M2C_FIELD(p,s16 *,16)=0;M2C_FIELD(p,s16 *,12)=10;M2C_FIELD(p,u16 *,2)=M2C_FIELD(p,u16 *,4);}
if(M2C_FIELD(screen,u8 *,0x34)==11) {
modeIsZero=((u32)(M2C_FIELD(screen,u8 *,0x36)<<24)>>28)==0?1:0;
if(modeIsZero&255){
kindIs8=M2C_FIELD(M2C_FIELD(screen,void **,0x3c),u8 *,15)==8?1:0;
if((kindIs8&255)&&((u32)(M2C_FIELD(screen,u8 *,0x38)<<24)>>31)){
p=M2C_FIELD(screen,void **,0x40);
M2C_FIELD(&data_0215d9b8,u16 *,6)=(M2C_FIELD(&data_0215d9b8,u16 *,6)&~0x3000)|((u32)((u16)M2C_FIELD(p,s32 *,4)<<30)>>18);
M2C_FIELD(&data_0215d9b8,u16 *,6)=(M2C_FIELD(&data_0215d9b8,u16 *,6)&~0xc00)|((u32)((u16)M2C_FIELD(p,s32 *,28)<<30)>>20);
M2C_FIELD(&data_0215d9b8,u16 *,6)=(M2C_FIELD(&data_0215d9b8,u16 *,6)&~0x4000)|((u32)((u16)M2C_FIELD(p,s32 *,52)<<31)>>17);
RequestMenuMode(screen,0);func_020c01ec(screen);M2C_FIELD(screen,u8 *,0x38)&=~128;
}}}
if(M2C_FIELD(screen,u8 *,0x34)==10){M2C_FIELD(screen,u8 *,0x38)=(M2C_FIELD(screen,u8 *,0x38)&~1)|1;func_ov003_02209d0c(screen,M2C_FIELD(M2C_FIELD(screen,void **,0x3c),u8 *,17));M2C_FIELD(M2C_FIELD(screen,void **,0x50),u8 *,1)=0;}
remaining=M2C_FIELD(screen,u8 *,0x34)-1;M2C_FIELD(screen,u8 *,0x34)=remaining;active=(remaining&255)?1:0;if(active&255)return active;
DrawMapSelectLabel(screen);return UpdateMapSelectLabelTransform(screen);
}

void func_ov003_0220a864(M2C_UNK arg0) { (void)arg0; }

void func_ov003_0220ac58(void *arg0) {
void *p=M2C_FIELD(arg0,void **,0x58);
s16 current=M2C_FIELD(p,s16 *,2);
s16 step;
s16 target;
if(current==M2C_FIELD(p,s16 *,4)) return;
M2C_FIELD(p,s16 *,2)=current+M2C_FIELD(p,s16 *,6);
p=M2C_FIELD(arg0,void **,0x58);
step=M2C_FIELD(p,s16 *,6);
if((step==6 && (target=M2C_FIELD(p,s16 *,4),M2C_FIELD(p,s16 *,2)>target)) || (step==-4 && (target=M2C_FIELD(p,s16 *,4),M2C_FIELD(p,s16 *,2)<target))) M2C_FIELD(p,s16 *,2)=target;
p=M2C_FIELD(arg0,void **,0x58);
M2C_FIELD(p,u8 *,1)+=1;
}

