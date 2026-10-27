/* 19 functions from 0x021A58C8 to 0x021A686C (ov000), found by ds-decomp. */
#include "common.h"
typedef struct { u8 x,y; u8 unk[10]; } UnkA66Entry;

void func_ov000_021a5b28(void) {
    void func_01ffb3d0(s32);
    void func_01ffb554(void *);
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_021a58c8(u8);
    extern void **gCurrentMap;
    u16 saved;
    s32 i;
    void *base;
    base = *gCurrentMap;
    saved = M2C_FIELD(base, u16 *, 0x52B6);
    func_01ffb554(base + 0x2338);
    func_01ffb3d0(0x7F);
    func_01ffb554(*gCurrentMap + 0x1E30);
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 && func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) == 0)
            func_ov000_021a58c8(i);
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = saved;
}

void func_ov000_021a5f50(void) {
    void func_01ffb3d0(s32);
    void func_01ffb554(void *);
    s32 func_020d1938(s32);
    s32 func_020d273c(u16, s32);
    void func_ov000_021a5bd4(u8);
    extern void **gCurrentMap;
    u16 saved;
    s32 i;
    void *base;
    base = *gCurrentMap;
    saved = M2C_FIELD(base, u16 *, 0x52B6);
    func_01ffb554(base + 0x2338);
    func_01ffb3d0(0x7F);
    func_01ffb554(*gCurrentMap + 0x1E30);
    for (i = 1; i < 5; i++) {
        if (func_020d1938(i) != 0 && func_020d273c(M2C_FIELD(*gCurrentMap, u16 *, 0x52A4), i) == 0)
            func_ov000_021a5bd4(i);
    }
    M2C_FIELD(*gCurrentMap, u16 *, 0x52B6) = saved;
}

s32 func_ov000_021a5ffc(s32 arg0) {
extern u8 *data_ov000_021df578;
extern M2C_UNK data_ov000_021e00ac;
u8 *p;
s32 i;
p = (u8 *)&data_ov000_021e00ac;
for (i=0; i<*data_ov000_021df578; i++,p+=12) {
if ((u32)p[3]<0xFCU && (arg0==4 || p[2]==arg0)) return i;
}
return -1;
}

s32 func_ov000_021a605c(s32 arg0) {
extern u8 *data_ov000_021df578;
extern M2C_UNK data_ov000_021e00ac;
u8 *p;
s32 i;
s32 best;
s32 result;
u8 value;
best=0;
result=-1;
p=(u8 *)&data_ov000_021e00ac;
for(i=0;i<*data_ov000_021df578;i++,p+=12) {
if ((u32)p[3]<0xFCU && (arg0==4 || p[2]==arg0)) {
value=p[6];
if(best < (s32)value) {best=value;result=i;}
}
}
return result;
}

s32 func_ov000_021a60d4(s32 arg0) {
extern u8 *data_ov000_021df578;
extern M2C_UNK data_ov000_021e00ac;
u8 *p;
s32 i;
s32 best;
s32 result;
u8 value;
best=0x7FFF;
result=-1;
p=(u8 *)&data_ov000_021e00ac;
for(i=0;i<*data_ov000_021df578;i++,p+=12) {
if ((u32)p[3]<0xFCU && (arg0==4 || p[2]==arg0)) {
value=p[8];
if(best > (s32)value) {best=value;result=i;}
}
}
return result;
}

s32 func_ov000_021a6150(s32 arg0) { extern u8 *data_ov000_021df578; extern M2C_UNK data_ov000_021e00ac; 
u8 *p; s32 i; s32 best; s32 result; u8 value;
best=0x7fff; result=-1; p=(u8 *)&data_ov000_021e00ac;
for(i=0;i<*data_ov000_021df578;i++,p+=12) { if((u32)p[3]<0xFCU && (arg0==4 || p[2]==arg0)) { value=p[9]; if(best > (s32)value) {best=value;result=i;} } } return result; }

s32 func_ov000_021a61cc(s32 arg0) { extern u8 *data_ov000_021df578; extern M2C_UNK data_ov000_021e00ac; extern M2C_UNK data_ov000_021dfd94;
u8 *p; s32 i; s32 best; s32 result; u8 value;
best=0x7fff; result=-1; p=(u8 *)&data_ov000_021e00ac;
for(i=0;i<*data_ov000_021df578;i++,p+=12) { if((u32)p[3]<0xFCU && ((u8 *)&data_ov000_021dfd94)[(s8)p[4]*8+2] && (arg0==4 || p[2]==arg0)) { value=p[9]; if(best > (s32)value) {best=value;result=i;} } } return result; }

s32 func_ov000_021a6264(s32 arg0) {
extern u8 *data_ov000_021df578; extern M2C_UNK data_ov000_021e00ac;
u8 *p; s32 i,best,result,flag; s32 a; u8 b; s32 n;
best=0x7fff;flag=0;n=*data_ov000_021df578;i=0;result=-1;p=(u8 *)&data_ov000_021e00ac;
if(n>0) { for(;i<*data_ov000_021df578;i++,p+=12) { if((u32)p[3]<0xfcU && (arg0==4 || p[2]==arg0)) {
a=p[9]; if(best>=a) { b=p[10]; if(!(best==b && flag==1)) {best=b;result=i;if((u32)b>=(u32)a) flag=1;else flag=0;} }
} } }return result; }

s32 func_ov000_021a6310(s32 a) {
extern u8 *data_ov000_021df578;
extern M2C_UNK data_ov000_021e00ac,data_ov000_021dfd94;
u8 *p; s32 i,best,result,value;
best=0x7fff;result=-1;p=(u8 *)&data_ov000_021e00ac;
for(i=0;i<*data_ov000_021df578;i++,p+=12){
if((u32)p[3]<0xfcU && (a==4 || p[2]==a)){
value=p[7];
if(p[2]==1 && (((u32)((u8 *)&data_ov000_021dfd94)[(s8)p[4]*8+3]<<29)>>31))value+=255;
if(best>value){best=value;result=i;}
}
}
return result;
}

s32 func_ov000_021a63b8(s32 a,s32 b) {
extern u8 *data_ov000_021df578;extern M2C_UNK data_ov000_021e00ac;
u8 *p; s32 i,best,result;u8 value;
best=0x7fff;result=-1;p=(u8 *)&data_ov000_021e00ac;
for(i=0;i<*data_ov000_021df578;i++,p+=12){
if((u32)p[3]<0xfcU && (a==4 || p[2]==a) && (s8)p[4]==b){
value=p[7];if(best>value){best=value;result=i;}
}}
return result;
}

s32 func_ov000_021a6440(s32 a,s32 b) {
extern u8 *data_ov000_021df578;extern M2C_UNK data_ov000_021e00ac;
u8 *p; s32 i,best,result;u8 value;
best=0;result=-1;p=(u8 *)&data_ov000_021e00ac;
for(i=0;i<*data_ov000_021df578;i++,p+=12){
if((u32)p[3]<0xfcU && (a==4 || p[2]==a) && (s8)p[4]==b){
value=p[6];if(best<value){best=value;result=i;}
}}
return result;
}

s32 func_ov000_021a64c4(void) { extern u8 *data_ov000_021df578; extern M2C_UNK data_ov000_021e00ac; 
u8 *p; s32 i; s32 best; s32 result; s8 value;
best=0; result=-1; p=(u8 *)&data_ov000_021e00ac;
for(i=0;i<*data_ov000_021df578;i++,p+=12) { if((u32)p[3]<0xFCU ) { value=(s8)p[5]; if(best < (s32)value) {best=value;result=i;} } } return result; }

s32 func_ov000_021a6528(s32 arg0) {
    void func_ov000_021a01c0(void);
    s32 func_ov000_021a6440(s32, s32);
    extern u8 *data_ov000_021df578;
    extern M2C_UNK data_ov000_021dfd94;
    u8 *p;
    u8 **storage;
    s32 best;
    s32 ff;
    s32 neg;
    s32 init;
    u8 *base;
    s32 result;
    s32 i;
    s32 r;

    p = (u8 *)&data_ov000_021dfd94;
    best = 0;
    func_ov000_021a01c0();
    storage = &data_ov000_021df578;
    ff = 0xff;
    neg = -1;
    init = best;

    for (;;) {
        base = *storage;
        result = neg;
        i = init;
        while (i < (s32)base[1]) {
            if (p[1] != 0xff) {
                if (best < (s32)p[0]) {
                    best = (s32)p[0];
                    result = i;
                }
            }
            i++;
            p += 8;
        }
        if (result == neg) {
            return -1;
        }
        r = func_ov000_021a6440(arg0, result);
        if (r != neg) {
            return r;
        }
        p[1] = ff;
    }
}

s32 func_ov000_021a65c4(s32 arg0, s32 arg1) {
    extern u8 *data_ov000_021df578;
    extern M2C_UNK data_ov000_021e00ac;
    u8 *p;
    s32 i;
    s32 best;
    s32 result;
    u8 value;
    best = 0x7fff;
    result = -1;
    p = (u8 *)&data_ov000_021e00ac;
    for (i = 0; i < *data_ov000_021df578; i++, p += 12) {
        if ((u32)p[3] < 0xFCU && (arg0 == 4 || p[2] == arg0) && (s8)p[4] == arg1) {
            value = p[8];
            if (best > (s32)value) {
                best = value;
                result = i;
            }
        }
    }
    return result;
}

s32 func_ov000_021a664c(void) {
    void func_ov000_021a01c0(void);
    s32 func_ov000_021a65c4(s32, s32);
    extern u8 *data_ov000_021df578;
    extern M2C_UNK data_ov000_021dfd94;
    u8 *p;
    u8 **storage;
    s32 one;
    s32 ff;
    s32 neg;
    s32 init;
    u8 *base;
    s32 result;
    s32 i;
    s32 r;

    p = (u8 *)&data_ov000_021dfd94;
    func_ov000_021a01c0();
    storage = &data_ov000_021df578;
    one = 1;
    ff = 0xFF;
    neg = -1;
    init = 0;

    for (;;) {
        base = *storage;
        result = neg;
        i = init;
        while (i < (s32)base[1]) {
            if (p[1] != 0xFF) {
                if (!(p[3] & 0x01)) {
                    result = i;
                    break;
                }
            }
            i++;
            p += 8;
        }
        if (result == neg) {
            return -1;
        }
        r = func_ov000_021a65c4(one, result);
        if (r != neg) {
            return r;
        }
        p[1] = ff;
    }
}

#pragma optimization_level 3
s32 func_ov000_021a66e8(void) {
void func_ov000_021a01c0(void);
extern M2C_UNK data_ov000_021dfd94,data_ov000_021e00ac;extern u8 *data_ov000_021df578;extern void **gCurrentMap;
u8 *p=(u8 *)&data_ov000_021dfd94; s32 found,i,r;u8 *entry;void *map;void *cell;u32 x,y;
func_ov000_021a01c0();
for(;;){
found=-1;
for(i=0;i<data_ov000_021df578[1];i++,p+=8){
if(p[1]!=255 && ((u32)(p[3]<<30)>>31)){found=i;break;}
}
if(found==-1)return -1;
r=func_ov000_021a6440(1,found);
if(r!=-1)r=func_ov000_021a63b8(1,found);
if(r==-1)break;
entry=(u8 *)&data_ov000_021e00ac+r*12;map=*gCurrentMap;
y=entry[1];x=entry[0];cell=(map+x)+M2C_FIELD(map+y*2,u16 *,0x3758)+0x2000;
if(M2C_FIELD(cell,u8 *,0x840)<50 && M2C_FIELD(cell,u8 *,0xd48)<50)return r;
p[1]=255;
}
return r;
}
#pragma optimization_level 4
s32 func_ov000_021a67f0(s32 a) {
extern u8 *data_ov000_021df578;
s32 func_ov000_021a6528(s32);s32 func_ov000_021a6310(s32);
s32 r=-1;
if(data_ov000_021df578[1]>=2)r=func_ov000_021a6528(a);
if(r==-1)r=func_ov000_021a605c(a);
if(r==-1)r=func_ov000_021a6310(a);
if(r==-1)r=func_ov000_021a5ffc(a);
return r;
}

