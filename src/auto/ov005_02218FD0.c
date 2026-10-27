/* 11 functions from 0x02218FD0 to 0x02219FA0 (ov005), found by ds-decomp. */
#include "common.h"

void func_ov005_02219a24(void *p){
extern s32 gCur3DSpriteEngine;
s32 i,v; s32 a,b;
if(M2C_FIELD(p,s32 *,0x60)<=0){func_01ffa730(p);return;}
M2C_FIELD(p,s32 *,0x5c)++;
v=func_0207ca38(0,0,16,M2C_FIELD(p,s32 *,0x5c),M2C_FIELD(p,s32 *,0x60));
a=(u8)(16-v);b=(u8)v;
for(i=0;i<16;i++){
M2C_FIELD(p,u16 **,0x54)[i]=func_020ae354(((u16 *)p)[i+26],(u16)M2C_FIELD(p,s32 *,0x58),a,b);
}
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=16;
if(M2C_FIELD(p,s32 *,0x5c)==M2C_FIELD(p,s32 *,0x60)){
M2C_FIELD(p,s32 *,0x5c)=0;func_01ffa6fc(p);
}
}

void func_ov005_02219aec(void *p){
extern s32 gCur3DSpriteEngine;
s32 i,v; u32 a; u8 b;
if(M2C_FIELD(p,s32 *,0x64)<=0){func_01ffa730(p);return;}
M2C_FIELD(p,s32 *,0x5c)++;
v=func_0207ca38(0,16,0,M2C_FIELD(p,s32 *,0x5c),M2C_FIELD(p,s32 *,0x64));
a=(u8)(16-v);b=(u8)v;
i=0; do {
M2C_FIELD(p,u16 **,0x54)[i]=func_020ae354(((u16 *)p)[i+26],(u16)M2C_FIELD(p,s32 *,0x58),a,b);
i++; }while(i<16);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=16;
if(M2C_FIELD(p,s32 *,0x5c)==M2C_FIELD(p,s32 *,0x64)){
M2C_FIELD(p,s32 *,0x5c)=0;func_01ffa6fc(p);
}
}

void func_ov005_02219bb4(void) {
    void func_ov005_02219a24();
    func_ov005_02219a24();
}

void func_ov005_02219bc0(void) {
    void func_ov005_02219aec();
    func_ov005_02219aec();
}

void func_ov005_02219bcc(void *p) {
extern s32 gCur3DSpriteEngine;
extern u8 data_ov005_022211f0[], data_ov005_022211f8[];
s32 func_020aae10(void *); s32 func_020aae44(void *);
void *q; s16 a,b,y,c,d; s32 t,u,v,w;
M2C_FIELD(p,s32 *,0x3c)++;
M2C_FIELD(p,s32 *,0x40)=func_0207ca38(4,32,0,M2C_FIELD(p,s32 *,0x3c),16);
y=(s16)(M2C_FIELD(p,s32 *,0x40)+160);
q=M2C_FIELD(p,void **,0x34);
func_02088e84(q,224,y,224,y);
if(M2C_FIELD(M2C_FIELD(q,void **,0x64),u8 *,0x12)!=0) t=1; else t=0;
if(t&255){a=M2C_FIELD(q,s16 *,0x52);b=M2C_FIELD(q,s16 *,0x50);u=func_020aae10(q);func_02087d84(M2C_FIELD(q,void **,0x64),1,b,a,(u16)u,(u16)func_020aae44(q));}
M2C_FIELD(q,s16 *,0x34)=224;M2C_FIELD(q,s16 *,0x36)=y;
if(M2C_FIELD(M2C_FIELD(q,void **,0x64),u8 *,0x12)!=0) v=1; else v=0;
if(v&255){c=M2C_FIELD(q,s16 *,0x52);d=M2C_FIELD(q,s16 *,0x50);w=func_020aae10(q);func_02087d84(M2C_FIELD(q,void **,0x64),1,d,c,(u16)w,(u16)func_020aae44(q));}
if(M2C_FIELD(p,s32 *,0x3c)==16){
M2C_FIELD(p,s32 *,0x3c)=0;M2C_FIELD(p,u8 *,0x44)=0;
func_0200bc5c(data_ov005_022211f0);
func_02080cfc(data_ov005_022211f8,M2C_FIELD(gCur3DSpriteEngine,void **,0x2c)+0x540);
func_01ff85b8(M2C_FIELD(gCur3DSpriteEngine,void **,0x2c)+0x540,192,0x9000);
M2C_FIELD(gCur3DSpriteEngine,u8 *,0x46)|=8;
func_01ffaa6c(M2C_FIELD(p,void **,0x38));M2C_FIELD(p,s32 *,0x38)=0;func_01ffa6fc(p);
}
}

M2C_UNK func_ov005_02219d98(void *arg0) {
    M2C_UNK func_01ffaacc(M2C_UNK, M2C_UNK, u16, M2C_UNK *, s32);
    extern s32 gCur3DSpriteEngine;
    extern s32 data_027e00b4;
    u8 temp_r1;
    s32 val;
    u16 r7;
    s32 i;
    u32 r10;
    u16 t;
    u8 bits;
    u16 tile;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x44);
    if (temp_r1 == 0) {
        return 0;
    }
    val = M2C_FIELD(arg0, s32 *, 0x40);
    r7 = (u16) ((val & 0xFF00) | ((val + 0xA0) & 0xFF));
    for (i = 0; i < 4; i++) {
        r10 = i * 0x40;
        t = (u16) M2C_FIELD(M2C_FIELD((void *) gCur3DSpriteEngine, s32 *, 0), u16 *, 0);
        bits = (u8) (((u32) t << 17) >> 30);
        tile = (u16) ((0x3FF & (0x1B8 >> bits)) | 0xEC00);
        func_01ffaacc(r10 & 0x1FF, r7, tile, &data_027e00b4, 0);
    }
    return 0;
}

void func_ov005_02219e40(void) {
    void func_ov005_02219bcc();
    func_ov005_02219bcc();
}

void func_ov005_02219e4c(void) {
    M2C_UNK func_ov005_02219d98();
    func_ov005_02219d98();
}

void func_ov005_02219e58(void *arg0) {
    M2C_UNK func_02090810(s32, s16, s16);
    extern s32 data_027e00c4, data_027e00c8, gCur3DSpriteEngine;
    s32 temp_r7;
    s32 var_r8;
    void *temp_ptr;
    s32 temp_r0;
    s32 var_r1;
    s32 var_r2;

    temp_r7 = gCur3DSpriteEngine;
    var_r8 = 0;
    do {
        if (var_r8 == 0) gCur3DSpriteEngine = data_027e00c8;
        else gCur3DSpriteEngine = data_027e00c4;
        temp_ptr = (void *)M2C_FIELD(arg0 + var_r8 * 4, void **, 0x34);
        var_r1 = (s32)M2C_FIELD(arg0, s32 *, 0x3C);
        var_r2 = (s32)M2C_FIELD(arg0, s32 *, 0x40);
        var_r1 = (s32)((s32)var_r1 << 16);
        temp_r0 = (s32)M2C_FIELD(temp_ptr, s32 *, 0x38);
        if (var_r8 == 0) var_r2 -= 0xC0;
        var_r1 = (s32)((s32)var_r1 >> 16);
        if (temp_r0 != 0) {
            func_02090810(temp_r0, (s16)var_r1, (s16)var_r2);
        }
        var_r8++;
    } while (var_r8 < 2);
    gCur3DSpriteEngine = temp_r7;
}

void func_ov005_02219ee0(void *arg0) {
    M2C_UNK func_01ffa574(void *);
    void func_ov005_02219e58(void *);
    extern s32 data_027e15bc;
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x44);
    switch (temp_r0) {                              /* irregular */
    case 1:
        if (data_027e15bc & 1) {
            M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) + 1);
        }
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) (M2C_FIELD(arg0, s32 *, 0x40) - 1);
        break;
    case 3:
        M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) + 1);
        if (data_027e15bc & 1) {
            M2C_FIELD(arg0, s32 *, 0x40) = (s32) (M2C_FIELD(arg0, s32 *, 0x40) - 1);
        }
        break;
    default:
        M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) + 1);
        M2C_FIELD(arg0, s32 *, 0x40) = (s32) (M2C_FIELD(arg0, s32 *, 0x40) - 1);
        break;
    }
    func_ov005_02219e58(arg0);
    if (((s32) M2C_FIELD(arg0, s32 *, 0x3C) < 0x108) && ((s32) M2C_FIELD(arg0, s32 *, 0x40) >= -8)) {
        return;
    }
    func_01ffa574(arg0);
}

