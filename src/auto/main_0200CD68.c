/* 18 functions from 0x0200CD68 to 0x0200DD40 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u16 x,y; } TouchPair;
typedef struct { u8 pad[0x58]; u16 a,b; u8 e,f; u16 c,d; u8 g,h; } TouchInput;
typedef struct { u32 v[7]; } InputConfig;
typedef struct { u32 unk0; void (*callback)(s32,s32,s32); u8 pad[0x30]; u16 flags38, flags3a; } TouchState;
extern InputConfig data_020ea6d8;
extern M2C_UNK data_0212fc70;
extern M2C_UNK func_0200c9c8, func_0200ca18, func_0200cb6c;
void func_0200d2c4(u32,u32,u32);
typedef struct { u32 x:12; u32 y:12; u32 touch:1; u32 valid:2; u32 unused:5; } TouchPacket;
typedef union { TouchPair pair; TouchPacket bits; } TouchSample;
typedef struct { u16 x,y,touch,valid; } TouchResult;

void func_0200cd68(u32 a,u32 b,u32 c,u32 d,u32 e) {
void func_0200cdfc(u8 *,u8 *,s32,u8 *,s32,void *);
u8 buf[0x68]; u8 small[0x14]; InputConfig cfg = data_020ea6d8;
cfg.v[2]=(u32)buf; cfg.v[3]=(u32)small;
cfg.v[4]=(u32)&func_0200c9c8; cfg.v[5]=(u32)&func_0200ca18; cfg.v[6]=(u32)&func_0200cb6c;
func_0200cdfc(a,b,c,d,e,&cfg);
}

#pragma scheduling off
void func_0200cdfc(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3, s32 arg4, void *arg5) {
    u8 sp80[64];
    u8 sp40[64];
    u8 sp0[64];
    s32 var_r2;
    s32 var_r3;
    s32 var_r5;
    u8 *var_r6;
    u8 temp_r0;

    var_r5 = arg4;
    var_r6 = arg3;
    if ((arg0 != NULL) && (arg1 != NULL) && (arg2 != 0) && (var_r6 != NULL) && (var_r5 != 0) && (arg5 != NULL)) {
        if (var_r5 > (s32) M2C_FIELD(arg5, s32 *, 4)) {
            M2C_FIELD(arg5, M2C_UNK (**)(s32), 0x10)(M2C_FIELD(arg5, s32 *, 8));
            M2C_FIELD(arg5, M2C_UNK (**)(s32, u8 *, s32), 0x14)(M2C_FIELD(arg5, s32 *, 8), var_r6, var_r5);
            M2C_FIELD(arg5, M2C_UNK (**)(s32, u8 *), 0x18)(M2C_FIELD(arg5, s32 *, 8), &sp80[0]);
            var_r5 = M2C_FIELD(arg5, s32 *, 0);
            var_r6 = &sp80[0];
        }
        var_r2 = 0;
        if (var_r5 > 0) {
            do {
                sp40[var_r2] = var_r6[var_r2] ^ 0x36;
                var_r2 += 1;
            } while (var_r2 < var_r5);
        }
        if (var_r2 < (s32) M2C_FIELD(arg5, s32 *, 4)) {
            do {
                sp40[var_r2] = 0x36;
                var_r2 += 1;
            } while (var_r2 < (s32) M2C_FIELD(arg5, s32 *, 4));
        }
        M2C_FIELD(arg5, M2C_UNK (**)(s32), 0x10)(M2C_FIELD(arg5, s32 *, 8));
        M2C_FIELD(arg5, M2C_UNK (**)(s32, u8 *, s32), 0x14)(M2C_FIELD(arg5, s32 *, 8), &sp40[0], M2C_FIELD(arg5, s32 *, 4));
        M2C_FIELD(arg5, M2C_UNK (**)(s32, u8 *, s32), 0x14)(M2C_FIELD(arg5, s32 *, 8), arg1, arg2);
        M2C_FIELD(arg5, M2C_UNK (**)(s32, u8 *), 0x18)(M2C_FIELD(arg5, s32 *, 8), M2C_FIELD(arg5, u8 **, 0xC));
        var_r3 = 0;
        if (var_r5 > 0) {
            do {
                sp0[var_r3] = var_r6[var_r3] ^ 0x5C;
                var_r3 += 1;
            } while (var_r3 < var_r5);
        }
        if (var_r3 < (s32) M2C_FIELD(arg5, s32 *, 4)) {
            do {
                sp0[var_r3] = 0x5C;
                var_r3 += 1;
            } while (var_r3 < (s32) M2C_FIELD(arg5, s32 *, 4));
        }
        M2C_FIELD(arg5, M2C_UNK (**)(s32), 0x10)(M2C_FIELD(arg5, s32 *, 8));
        M2C_FIELD(arg5, M2C_UNK (**)(s32, u8 *, s32), 0x14)(M2C_FIELD(arg5, s32 *, 8), &sp0[0], M2C_FIELD(arg5, s32 *, 4));
        M2C_FIELD(arg5, M2C_UNK (**)(s32, u8 *, s32), 0x14)(M2C_FIELD(arg5, s32 *, 8), M2C_FIELD(arg5, u8 **, 0xC), M2C_FIELD(arg5, s32 *, 0));
        M2C_FIELD(arg5, M2C_UNK (**)(s32, u8 *), 0x18)(M2C_FIELD(arg5, s32 *, 8), arg0);
    }
}
#pragma scheduling reset
void func_0200cfc8(u32 *state, const u8 *data, s32 len) {
    u32 a, b, c, d, e;
    u32 W[80];
    s32 i;
    while (len > 0) {
        for (i = 0; i < 16; i++) {
            u32 x = ((const u32 *)data)[i];
            x = ((x >> 24) & 0xFF) | ((x >> 8) & 0xFF00) | ((x << 8) & 0xFF0000) | (x << 24);
            W[i] = x;
        }
        data += 64;
        a = state[0]; b = state[1]; c = state[2]; d = state[3]; e = state[4];
        for (i = 0; i < 80; i++) {
            u32 f, k, temp;
            if (i < 20) { f = (b & c) | (~b & d); k = 0x5A827999; }
            else if (i < 40) { f = b ^ c ^ d; k = 0x6ED9EBA1; }
            else if (i < 60) { f = (b & c) | (b & d) | (c & d); k = 0x8F1BBCDC; }
            else { f = b ^ c ^ d; k = 0xCA62C1D6; }
            if (i >= 16) {
                u32 t = W[i-3] ^ W[i-8] ^ W[i-14] ^ W[i-16];
                W[i] = (t << 1) | (t >> 31);
            }
            temp = ((a << 5) | (a >> 27)) + f + e + k + W[i];
            e = d; d = c; c = ((b << 30) | (b >> 2)); b = a; a = temp;
        }
        state[0] += a; state[1] += b; state[2] += c; state[3] += d; state[4] += e;
        len -= 64;
    }
}

void func_0200d2c4(u32 unused,u32 value,u32 error){
u16 code=(u16)value;u16 command=(u16)((code&0x7f00)>>8);s32 status;
TouchSample sample1,sample2;TouchResult *out; u8 touch,valid;u16 y,x;
if(error){
M2C_FIELD(&data_0212fc70,u16 *,0x38)|=1<<command;
if(M2C_FIELD(&data_0212fc70,void (**)(s32,s32,s32),4))M2C_FIELD(&data_0212fc70,void (**)(s32,s32,s32),4)(command,4,0);return;
}
if(command==16){
M2C_FIELD(&data_0212fc70,u16 *,0x10)++;
if(M2C_FIELD(&data_0212fc70,u16 *,0x10)>=M2C_FIELD(&data_0212fc70,u16 *,0x18))M2C_FIELD(&data_0212fc70,u16 *,0x10)=0;
sample1.pair=*(volatile TouchPair *)0x27fffaa;
x=sample1.bits.x;y=sample1.bits.y;touch=sample1.bits.touch;valid=sample1.bits.valid;
out=M2C_FIELD(&data_0212fc70,TouchResult **,0x14)+M2C_FIELD(&data_0212fc70,u16 *,0x10);
out->x=x;out->y=y;out->touch=touch;out->valid=valid;
if(M2C_FIELD(&data_0212fc70,void (**)(s32,s32,s32),4))M2C_FIELD(&data_0212fc70,void (**)(s32,s32,s32),4)(command,0,(u8)M2C_FIELD(&data_0212fc70,u16 *,0x10));return;
}
if(!(value&0x1000000))return;
switch((u8)code){
case 0:
switch(command){case 0:
sample2.pair=*(volatile TouchPair *)0x27fffaa;x=sample2.bits.x;y=sample2.bits.y;touch=sample2.bits.touch;valid=sample2.bits.valid;
M2C_FIELD(&data_0212fc70,u16 *,8)=x;
M2C_FIELD(&data_0212fc70,u16 *,10)=y;
M2C_FIELD(&data_0212fc70,u16 *,12)=touch;
M2C_FIELD(&data_0212fc70,u16 *,14)=valid;
M2C_FIELD(&data_0212fc70,u16 *,0x36)=0;
break;
case 1:M2C_FIELD(&data_0212fc70,u16 *,0x36)=2;break;
case 2:M2C_FIELD(&data_0212fc70,u16 *,0x36)=0;break;
}
M2C_FIELD(&data_0212fc70,u16 *,0x3a)&=~(1<<command);
if(M2C_FIELD(&data_0212fc70,void (**)(s32,s32,s32),4))M2C_FIELD(&data_0212fc70,void (**)(s32,s32,s32),4)(command,0,0);return;
case 4:status=3;goto report;
case 2:status=1;goto report;
case 3:status=2;
report:
M2C_FIELD(&data_0212fc70,u16 *,0x38)|=1<<command;
M2C_FIELD(&data_0212fc70,u16 *,0x3a)&=~(1<<command);
if(M2C_FIELD(&data_0212fc70,void (**)(s32,s32,s32),4))M2C_FIELD(&data_0212fc70,void (**)(s32,s32,s32),4)(command,(u8)status,0);
return;
default:func_02007958();return;
}
}

void func_0200d544(void) {
void func_02009d34(void); s32 func_02009e8c(s32,s32); void func_02009e40(s32,void *);
if(M2C_FIELD(&data_0212fc70,u16 *,0)) return;
M2C_FIELD(&data_0212fc70,u16 *,0)=1;
func_02009d34();
M2C_FIELD(&data_0212fc70,u16 *,0x10)=0;
M2C_FIELD(&data_0212fc70,u32 *,4)=0;
M2C_FIELD(&data_0212fc70,u32 *,0x14)=0;
M2C_FIELD(&data_0212fc70,u16 *,0x36)=0;
M2C_FIELD(&data_0212fc70,u16 *,0x34)=0;
M2C_FIELD(&data_0212fc70,u16 *,0x3a)=0;
M2C_FIELD(&data_0212fc70,u16 *,0x38)=0;
while(!func_02009e8c(6,1)) {}
func_02009e40(6,&func_0200d2c4);
}

#pragma opt_lifetimes off
s32 func_0200d5bc(u16 *p) {
s32 func_0200da04(void *,u16,u16,u8,s32,s32,s32,s32,s32);
u16 a=M2C_FIELD((void *)0x027ffc80,u16 *,0x58);
u16 b=M2C_FIELD((void *)0x027ffc80,u16 *,0x5a);
u16 c=M2C_FIELD((void *)0x027ffc80,u16 *,0x5e);
u16 d=M2C_FIELD((void *)0x027ffc80,u16 *,0x60);
u8 e=M2C_FIELD((void *)0x027ffc80,u8 *,0x5c);
u8 f=M2C_FIELD((void *)0x027ffc80,u8 *,0x5d);
u8 g=M2C_FIELD((void *)0x027ffc80,u8 *,0x62);
u8 h=M2C_FIELD((void *)0x027ffc80,u8 *,0x63);
if((!a&&!c&&!b&&!d)||func_0200da04(p,a,b,e,f,c,d,g,h)) {p[0]=0;p[1]=0;p[2]=0;p[3]=0; return 1;} return 1;
}
#pragma opt_lifetimes reset
void func_0200d650(s16 *p){
s32 func_0200751c(void);void func_02007530(s32);
s32 t,n;
if(!p){M2C_FIELD(&data_0212fc70,u16*,0x34)=0;return;}
t=func_0200751c();
if((n=p[2])!=0){
*(volatile u16*)0x4000280=0;
*(volatile u32*)0x4000290=0x10000000;
*(volatile s64*)0x4000298=(u32)n;
M2C_FIELD(&data_0212fc70,s32*,28)=p[0];
M2C_FIELD(&data_0212fc70,s32*,32)=p[2];
while(*(volatile u16*)0x4000280&0x8000){}
M2C_FIELD(&data_0212fc70,s32*,36)=*(volatile s32*)0x40002a0;
}else{M2C_FIELD(&data_0212fc70,s32*,28)=0;M2C_FIELD(&data_0212fc70,s32*,32)=0;M2C_FIELD(&data_0212fc70,s32*,36)=0;}
if((n=p[3])!=0){
*(volatile u16*)0x4000280=0;
*(volatile u32*)0x4000290=0x10000000;
*(volatile s64*)0x4000298=(u32)n;
M2C_FIELD(&data_0212fc70,s32*,40)=p[1];
M2C_FIELD(&data_0212fc70,s32*,44)=p[3];
while(*(volatile u16*)0x4000280&0x8000){}
M2C_FIELD(&data_0212fc70,s32*,48)=*(volatile s32*)0x40002a0;
}else{M2C_FIELD(&data_0212fc70,s32*,40)=0;M2C_FIELD(&data_0212fc70,s32*,44)=0;M2C_FIELD(&data_0212fc70,s32*,48)=0;}
func_02007530(t);M2C_FIELD(&data_0212fc70,u16*,0x34)=1;}

#pragma opt_propagation off
void func_0200d778(void){
s32 func_0200751c(void);void func_02007530(s32);s32 func_02009eb0(s32,u32,s32);
void (*callback)(s32,s32,s32);s32 t=func_0200751c();s32 ok=(func_02009eb0(6,0x3000000,0)>=0);
if(!ok){TouchState *p;func_02007530(t);p=(TouchState*)&data_0212fc70;p->flags38 = 1 | (u32)p->flags38;callback=p->callback;if(callback)callback(0,4,0);}
else{TouchState *p=(TouchState*)&data_0212fc70;p->flags3a = 1 | (u32)p->flags3a;p->flags38 = ~1 & (u32)p->flags38;func_02007530(t);}
}
#pragma opt_propagation on
s32 func_0200d80c(u16 *a) {
void func_0200dd14(u32);
func_0200dd14(1);if(M2C_FIELD(&data_0212fc70,u16 *,0x38)&1)return 1;
((TouchPair *)a)[0]=M2C_FIELD(&data_0212fc70,TouchPair *,8);
((TouchPair *)a)[1]=M2C_FIELD(&data_0212fc70,TouchPair *,12);return 0;
}

void func_0200d85c(s32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    s32 func_02009eb0(s32, u32, s32);
    u32 i;
    s32 t;
    u8 ok;

    M2C_FIELD(&data_0212fc70, s32 *, 0x14) = arg2;
    M2C_FIELD(&data_0212fc70, u16 *, 0x10) = 0;
    M2C_FIELD(&data_0212fc70, u16 *, 0x12) = arg1;
    M2C_FIELD(&data_0212fc70, u16 *, 0x18) = arg3;
    for (i = 0; i < arg3; i++) {
        ((u16 *)M2C_FIELD(&data_0212fc70, s32 *, 0x14))[i * 4 + 2] = (u16)i;
    }
    t = func_0200751c();
    ok = (func_02009eb0(6, (arg1 & 0xff) | 0x100 | 0x2000000, 0) >= 0
          && func_02009eb0(6, arg0 | 0x10000 | 0x1000000, 0) >= 0);
    if (!ok) {
        func_02007530(t);
        M2C_FIELD(&data_0212fc70, u16 *, 0x38) |= 2;
        if (M2C_FIELD(&data_0212fc70, void (**)(s32, s32, s32), 4)) {
            M2C_FIELD(&data_0212fc70, void (**)(s32, s32, s32), 4)(1, 4, 0);
        }
    } else {
        M2C_FIELD(&data_0212fc70, u16 *, 0x3a) |= 2;
        M2C_FIELD(&data_0212fc70, u16 *, 0x38) &= ~2;
        func_02007530(t);
    }
}

void func_0200d95c(void) {
s32 func_0200751c(void); void func_02007530(s32); s32 func_02009eb0(s32,u32,s32);
s32 t=func_0200751c();u32 v; void *p; s32 ok=(func_02009eb0(6,0x3000200,0)>=0);
if(!ok) {func_02007530(t);p=&data_0212fc70;v=M2C_FIELD(p,u16 *,0x38); v|=4; M2C_FIELD(p,u16 *,0x38)=v;
if(M2C_FIELD(p,void (**)(s32,s32,s32),4))M2C_FIELD(p,void (**)(s32,s32,s32),4)(2,4,0);
} else { p=&data_0212fc70; v=M2C_FIELD(p,u16 *,0x3a); v|=4; M2C_FIELD(p,u16 *,0x3a)=v;M2C_FIELD(p,u16 *,0x38)&=~4;func_02007530(t);}
}

u16 func_0200d9f4(void) {
    extern M2C_UNK data_0212fc70;
    return M2C_FIELD(&data_0212fc70, u16 *, 0x10);
}

s32 func_0200da04(void *arg0, u16 arg1, u16 arg2, u8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    s32 saved;

    if (arg1 >= 0x1000U || arg2 >= 0x1000U || arg5 >= 0x1000 || arg6 >= 0x1000) {
        return 1;
    }
    if (arg3 >= 0x100U || arg7 >= 0x100 || arg4 >= 0xC0 || arg8 >= 0xC0) {
        return 1;
    }
    if (!(arg3 != arg7 && arg4 != arg8 && arg1 != arg5 && arg2 != arg6)) {
        return 1;
    }

    saved = func_0200751c();
    *(volatile u16 *)0x04000280 = 0;
    *(volatile s32 *)0x04000290 = (s32)((arg1 - arg5) << 8);
    *(volatile s32 *)0x04000298 = (s32)(arg3 - arg7);
    *(volatile s32 *)0x0400029C = 0;
    while (*(volatile u16 *)0x04000280 & 0x8000) {
    }
    {
        s32 vert = (s32)((arg2 - arg6) << 8);
        s32 old = *(volatile s32 *)0x040002A0;
        *(volatile u16 *)0x04000280 = 0;
        *(volatile s32 *)0x04000290 = vert;
        *(volatile s32 *)0x04000298 = (s32)(arg4 - arg8);
        *(volatile s32 *)0x0400029C = 0;
        if (old >= 0x8000 || old < -0x8000) {
            func_02007530(saved);
            return 1;
        }
        *(volatile s16 *)((u8 *)arg0 + 4) = (s16)old;
        {
            s32 reload = *(volatile s16 *)((u8 *)arg0 + 4);
            s32 comp = (s32)((arg1 + arg5) << 8) - reload * (arg3 + arg7);
            comp = (comp << 9) >> 16;
            if (comp >= 0x8000 || comp < -0x8000) {
                func_02007530(saved);
                return 1;
            }
            *(volatile s16 *)((u8 *)arg0 + 0) = (s16)comp;
        }
    }
    while (*(volatile u16 *)0x04000280 & 0x8000) {
    }
    {
        s32 old2 = *(volatile s32 *)0x040002A0;
        func_02007530(saved);
        if (old2 >= 0x8000 || old2 < -0x8000) {
            return 1;
        }
        *(s16 *)((u8 *)arg0 + 6) = (s16)old2;
        {
            s32 reload = *(s16 *)((u8 *)arg0 + 6);
            s32 comp2 = (s32)((arg2 + arg6) << 8) - reload * (arg4 + arg8);
            comp2 = (comp2 << 9) >> 16;
            if (comp2 >= 0x8000 || comp2 < -0x8000) {
                return 1;
            }
            *(s16 *)((u8 *)arg0 + 2) = (s16)comp2;
        }
    }
    return 0;
}

extern s32 data_0212fc8c[];
extern s32 p[];
void func_0200dbf0(u16 *a,u16 *b) {
s32 *p;
if(!M2C_FIELD(&data_0212fc70,u16 *,0x34)) { ((TouchPair *)a)[0]=((TouchPair *)b)[0]; ((TouchPair *)a)[1]=((TouchPair *)b)[1]; return; }
p=data_0212fc8c;
a[2]=b[2]; a[3]=b[3];
if(!b[2]) {a[0]=0;a[1]=0;return;}
a[0]=(((long long)(b[0]<<2)-p[0])*p[2])>>22;
if((s16)a[0]<0)a[0]=0;else if((s16)a[0]>255)a[0]=255;
a[1]=(((long long)(b[1]<<2)-p[3])*p[5])>>22;
if((s16)a[1]<0)a[1]=0;else if((s16)a[1]>191)a[1]=191;
}

void func_0200dd14(u32 a) {while(M2C_FIELD(&data_0212fc70,volatile u16 *,0x3a)&a) {}}

u32 func_0200dd2c(u32 arg0) { return M2C_FIELD(&data_0212fc70, u16 *, 0x38) & arg0; }

