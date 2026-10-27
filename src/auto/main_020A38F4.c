/* 28 functions from 0x020A38F4 to 0x020A48EC (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 x,y; u16 width:3; u16 height:3; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020ADimEntryTop;
typedef struct { u16 first; u16 low:6; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020AEntry;

void func_020a38f4(s32 a) {
 extern s32 *gCurrentMap;
 void *p;u32 index;
 switch(a){case 1:case 2:case 3:
 p=(void *)*gCurrentMap;
 index=(u32)M2C_FIELD(p,u16 *,0x52a4)-1;
 M2C_FIELD(p+index,u8 *,0x515c)=1;
 break;
 }
}

#pragma scheduling off
void func_020a3934(s32 a,s32 b) {
 extern s32 *gCurrentMap;
 s32 func_020d1938(s32);
 u32 value;s32 i;
 switch(a){case 1:case 2:case 3:
 i=1;value=b&0xff;
 do{
 if(func_020d1938(i))M2C_FIELD(*gCurrentMap+i,u8 *,0x515b)=value;
 i++;
 }while(i<5);
 break;
 }
}
#pragma scheduling reset
void func_020a398c(s32 a) {
 extern s32 *gCurrentMap;
 if(a==0)return;
 if(a==M2C_FIELD(*gCurrentMap,u8 *,0x5158))return;
 func_020a38f4(a);
}

void func_020a39c0(M2C_UNK arg0) {
    s16 func_020a3790(M2C_UNK);
    void func_020a3934();
    extern M2C_UNK data_021204f4;
    void *temp_r4;

    func_020a3934();
    temp_r4 = func_01ffa3dc(&data_021204f4, 7);
    M2C_FIELD(temp_r4, s16 *, 0x36) = func_020a3790(arg0);
    M2C_FIELD(temp_r4, s16 *, 0x38) = 0;
}

void func_020a3b58(void) {
extern s32 *gCurrentMap;extern M2C_UNK data_021204f4;
void *p;
func_020a398c(M2C_FIELD(*gCurrentMap,u8 *,0x515a));
if(M2C_FIELD(*gCurrentMap,u8 *,0x5158)==M2C_FIELD(*gCurrentMap,u8 *,0x515a))return;
p=func_01ffa3dc(&data_021204f4,7);
M2C_FIELD(p,u16 *,0x36)=M2C_FIELD(*gCurrentMap,u8 *,0x515a);
M2C_FIELD(p,u16 *,0x38)=1;
}

void func_020a40c0(u32 a) {
void func_020a3bcc(void);void func_020a3d10(void);void func_020a3e48(void);void func_020a3f88(void);
switch(a){case 0:func_020a3bcc();return;case 1:func_020a3d10();return;case 2:func_020a3e48();return;case 3:func_020a3f88();return;default:return;}
}

void func_020a4100(s32 a) {
extern s32 *gCurrentMap;u8 b=a;
M2C_FIELD(*gCurrentMap,u8 *,0x515b)=b;
M2C_FIELD(*gCurrentMap,u8 *,0x5158)=b;
M2C_FIELD(*gCurrentMap,u8 *,0x515a)=b;
M2C_FIELD(*gCurrentMap,u8 *,0x5159)=0;
}

#pragma scheduling off
void func_020a4154(void) {
    void func_01ff90e4(u8, u8, s32, void *);
    extern u8 data_021204a4[];
    extern s32 *gCurrentMap;
    extern s32 data_027e15c0;
    s16 i;
    s32 offset;
    void *p;
    void *q;
    s32 drawOffset;
    s32 end;
    u32 j;
    s16 next;
    i = 0;
    offset = 0;
    do {
        p = M2C_FIELD(gCurrentMap, void **, 0xC);
        i++;
        M2C_FIELD(p, u16 *, offset) += M2C_FIELD((u8 *)p + offset, u16 *, 4);
        q = (u8 *)M2C_FIELD(gCurrentMap, void **, 0xC) + offset;
        offset += 12;
        M2C_FIELD(q, u16 *, 2) += M2C_FIELD(q, u16 *, 6);
    } while (i < 32);
    j = (u32)(data_027e15c0 << 31) >> 27;
    end = j + 16;
    if (end <= (s32)j) return;
    drawOffset = (s16)j * 12;
    do {
        p = (u8 *)M2C_FIELD(gCurrentMap, void **, 0xC) + drawOffset;
        q = M2C_FIELD(gCurrentMap, void **, 0);
        func_01ff90e4((u8)((M2C_FIELD(p, u16 *, 0) >> 8) - M2C_FIELD(q, s16 *, 0x5148)),
                     (u8)((M2C_FIELD(p, u16 *, 2) >> 8) - M2C_FIELD(q, s16 *, 0x514A)), 0,
                     data_021204a4 + M2C_FIELD(p, u16 *, 8) * 8);
        next = j + 1;
        drawOffset += 12;
        j = next;
    } while (end > (s32)j);
}

void func_020a434c(void) {
    void func_01ff90e4(u8, u8, s32, void *);
    extern u8 data_0212049c[];
    extern s32 *gCurrentMap;
    extern s32 data_027e15c0;
    s16 i;
    s32 offset;
    void *p;
    void *q;
    s32 drawOffset;
    s32 end;
    u32 j;
    s16 next;
    i = 0;
    offset = 0;
    do {
        p = M2C_FIELD(gCurrentMap, void **, 0xC);
        i++;
        M2C_FIELD(p, u16 *, offset) += M2C_FIELD((u8 *)p + offset, u16 *, 4);
        q = (u8 *)M2C_FIELD(gCurrentMap, void **, 0xC) + offset;
        offset += 12;
        M2C_FIELD(q, u16 *, 2) += M2C_FIELD(q, u16 *, 6);
    } while (i < 32);
    j = (u32)(data_027e15c0 << 31) >> 27;
    end = j + 16;
    if (end <= (s32)j) return;
    drawOffset = (s16)j * 12;
    do {
        p = (u8 *)M2C_FIELD(gCurrentMap, void **, 0xC) + drawOffset;
        q = M2C_FIELD(gCurrentMap, void **, 0);
        func_01ff90e4((u8)((M2C_FIELD(p, u16 *, 0) >> 8) - M2C_FIELD(q, s16 *, 0x5100)),
                     (u8)((M2C_FIELD(p, u16 *, 2) >> 8) - M2C_FIELD(q, s16 *, 0x5102)), 0,
                     data_0212049c + M2C_FIELD(p, u16 *, 8) * 12);
        next = j + 1;
        drawOffset += 12;
        j = next;
    } while (end > (s32)j);
}

void func_020a445c(void) {
extern s32 gCur3DSpriteEngine,data_027e00c8;extern s32 *gCurrentMap;
void func_020a4250(void);void func_020a434c(void);
s32 old=gCur3DSpriteEngine;
gCur3DSpriteEngine=data_027e00c8;
switch(M2C_FIELD(*gCurrentMap,u8 *,0x5158)){case 0:break;case 1:func_020a4154();break;case 2:func_020a4250();break;case 3:func_020a434c();break;}
gCur3DSpriteEngine=old;
}

#pragma scheduling reset
void func_020a44d0(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_021204d4;
    func_01ffa3dc(&data_021204d4, 1);
}

void func_020a44e8(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    extern M2C_UNK data_021204d4;
    func_01ffa9e4(&data_021204d4);
}

void func_020a44fc(M2C_UNK arg0, s32 arg1) {
    M2C_UNK func_02008048(M2C_UNK, s32, M2C_UNK);
    extern s32 *gCurrentMap;
    func_02008048(arg0, *gCurrentMap + 0x58A4 + (arg1 * 8), 8);
}

void func_020a4528(void) {
extern s32 *gCurrentMap;Unk020ADimEntryTop *p=(Unk020ADimEntryTop *)(*gCurrentMap+0x58a4);s32 i=0;
do{p->height=0;p->width=p->height;
M2C_FIELD(p,u8 *,0)=M2C_FIELD(p,u8 *,1)=p->width;
p->type=0;p->value=0;p->mode=0;p->kind=0;p->extra=0;p->last=0;p++;i++;}while(i<32);
}

void func_020a45cc(void) {
 void func_020a4528(void);
 extern s32 *gCurrentMap;
 M2C_FIELD(*gCurrentMap,u16 *,0x58a6)&=~0x3c0;
 func_020a4528();
}

void *func_020a45f8(s32 a,s32 b) {
extern s32 *gCurrentMap;Unk020ADimEntryTop *p=(Unk020ADimEntryTop *)(*gCurrentMap+0x58a4);
while(p->type){s32 x=M2C_FIELD(p,u8 *,0);s32 endx=x+p->width; s32 y=M2C_FIELD(p,u8 *,1);s32 endy=y+p->height;
if(a>=x&&b>=y&&a<endx&&b<endy)return p;p++;}return 0;
}

void *func_020a4678(s32 a,s32 b,s32 c) {
extern s32 *gCurrentMap;Unk020ADimEntryTop *p=(Unk020ADimEntryTop *)(*gCurrentMap+0x58a4);u32 t;
while(t=p->type){s32 x=M2C_FIELD(p,u8 *,0);s32 endx=x+p->width; s32 y=M2C_FIELD(p,u8 *,1);s32 endy=y+p->height;
if(a>=x&&b>=y&&a<endx&&b<endy){if(t==c)return p;}p++;}return 0;
}

u8 func_020a4700(s32 a,s32 b) {
extern s32 *gCurrentMap;
s16 pos[2];s32 p;void *q=func_020a45f8(a,b);
if(!q)return 0;
if(!func_020a488c(q,pos))return 0;
p=*gCurrentMap;
return M2C_FIELD(p+(pos[0]+M2C_FIELD(p+pos[1]*2,u16 *,0x3758)),s8 *,0x1e30)>=0;
}

s32 func_020a4770(s32 a,s32 b) {
s16 pos[2];void *p=func_020a45f8(a,b);
if(!p)return 0;
if(!func_020a488c(p,pos))return 0;
if(pos[0]!=a||pos[1]!=b)return 0;
if(!M2C_FIELD(p,u8 *,4))p=0;
return (s32)p;
}

s32 func_020a47e0(s32 a,s32 b) {
extern s32 *gCurrentMap;s32 func_020a4770(s32,s32);s32 p=*gCurrentMap;
if((M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x1420)&31)!=29)return 0;return func_020a4770(a,b);
}

#pragma scheduling off
s32 func_020a4828(s32 a,s32 b) {
extern s32 *gCurrentMap;
s32 q=func_020a4770(a,b);s32 p=*gCurrentMap; s32 result=0;u32 value;

value=M2C_FIELD(p+(a+M2C_FIELD(p+b*2,u16 *,0x3758)),u8 *,0x539c)&127;
if(q)result=(u32)(M2C_FIELD(q,u16 *,2)<<22)>>28;
if(value)result=1;
return result;
}
#pragma scheduling reset
s32 func_020a488c(void *arg0, void *arg1) {
    u32 temp_r2;

    temp_r2 = (u32) (M2C_FIELD(arg0, u16 *, 2) << 0x16) >> 0x1C;
    switch (temp_r2) {                              /* irregular */
    case 6:
    case 7:
        M2C_FIELD(arg1, s16 *, 0) = (s16) M2C_FIELD(arg0, u8 *, 0);
        M2C_FIELD(arg1, s16 *, 2) = (s16) M2C_FIELD(arg0, u8 *, 1);
        return 1;
    case 4:
        M2C_FIELD(arg1, s16 *, 0) = (s16) (M2C_FIELD(arg0, u8 *, 0) + 1);
        M2C_FIELD(arg1, s16 *, 2) = (s16) (M2C_FIELD(arg0, u8 *, 1) + 2);
        return 1;
    default:
        return 0;
    }
}
typedef struct { u8 x,y; u16 width:3; u16 height:3; u16 type:4; u16 kind:4; u16 top:2; u8 value; u8 flags:4; u8 mode:4; u8 extra; u8 last; } Unk020ADimEntry;
