/* 21 functions from 0x020B8CCC to 0x020B9C8C (main), found by ds-decomp. */
#include "common.h"
typedef struct { u8 value; u8 flag; } Unk020BChoice;

void func_020b90d8(void) {M2C_UNK func_01ff9ce8(M2C_UNK,s32);void func_020cfd28();void func_020d472c();extern void *gCur3DSpriteEngine;extern void *data_027e00c8;void *old=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;((M2C_UNK (*)())func_01ff9ce8)(1);((M2C_UNK (*)())func_01ff9ce8)(2);M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=2;M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=4;func_020cfd28();func_020d472c();gCur3DSpriteEngine=old;}

void func_020b9140(s32 arg0) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, s32);
    extern M2C_UNK data_021290dc;
    if (arg0 == 0) {
        func_01ffa3dc(&data_021290dc, 7);
        return;
    }
    func_01ffa3dc(&data_021290dc, arg0);
}

void func_020b939c(void *arg0) {
    M2C_UNK func_01ffa574(void *);
    M2C_UNK func_0208fb0c(s32, s16, s16);
    s32 func_020cd674();
    extern void **gCurrentMap;
    void *temp_r1;

    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = 8;
    temp_r1 = *gCurrentMap;
    func_0208fb0c(0x111, M2C_FIELD(temp_r1, s16 *, 0x52C2), M2C_FIELD(temp_r1, s16 *, 0x52C4));
    if (func_020cd674() == 0) {
        return;
    }
    func_01ffa574(arg0);
}

void func_020b93f4(void *a) {s32 func_020d2d38(s32,s32);s32 func_0207ca38(s32,s32,s32,s32,s32);void func_020b916c(s32,s32,s32,s32,s32);M2C_UNK func_0208fe30(s32);void func_01ffa6fc(void *);extern void **gCurrentMap;
s32 n,limit,total,base,delta,v,index;void *g;
v=M2C_FIELD(a,s32 *,92);M2C_FIELD(a,s16 *,108)++;g=*gCurrentMap;n=M2C_FIELD(a,s16 *,108);limit=M2C_FIELD(a,s16 *,110);
index=M2C_FIELD(g,u16 *,0x52a4);total=M2C_FIELD((u8 *)g+index*140,s32 *,0x67a4);
base=func_020d2d38(index,v);delta=total-base;
func_020b916c(0,1,func_0207ca38(0,total,delta,n,limit),-base,delta);
if((n&3)==1)func_0208fe30(0x10023);if(n<limit)return;func_01ffa6fc(a);
}

void func_020b94a4(void *a) {s32 func_020a67fc(s32,s32,s32);void func_ov000_02199f50(s32,u8,s32,s32);void func_ov000_0216aa44(s32,s32);extern void **gCurrentMap;s32 v=M2C_FIELD(a,s32 *,92);s32 result;void *g=*gCurrentMap;
result=func_020a67fc(M2C_FIELD(g,s16 *,0x52c2),M2C_FIELD(g,s16 *,0x52c4),v);
M2C_FIELD(*gCurrentMap,s16 *,0x52dc)=M2C_FIELD(*gCurrentMap,s16 *,0x52c2);
M2C_FIELD(*gCurrentMap,s16 *,0x52de)=M2C_FIELD(*gCurrentMap,s16 *,0x52c4);
func_ov000_02199f50(1,v,0,0);func_ov000_0216aa44(14,result);M2C_FIELD(*gCurrentMap,s16 *,0x52b4)=0;
}

void func_020b953c(s32 arg0, s32 arg1) {
    void *func_01ffa42c(M2C_UNK *);
    extern M2C_UNK data_02129178;
    M2C_FIELD(func_01ffa42c(&data_02129178), s32 *, 0x5C) = arg0;
}

void func_020b9558(u8 a) {s32 func_020d2d38(s32,s32);void func_020b916c(s32,s32,s32,s32,s32);void func_ov000_02174d10(s32,s32);extern void **gCurrentMap;void *g=*gCurrentMap;s32 idx=M2C_FIELD(g,u16 *,0x52a4);s32 total=M2C_FIELD((u8 *)g+idx*140,s32 *,0x67a4);s32 base=func_020d2d38(idx,a);func_020b916c(0,1,total,-base,total-base);func_ov000_02174d10(M2C_FIELD(*gCurrentMap,u16 *,0x52a4),a);}

void func_020b95cc(u8 *p) {
extern u16 *data_02101e84;
extern s32 data_0215d850;
void func_020b1c60(s32),func_020b2e14(void *),func_020b2e2c(void);
u16 *keys=data_02101e84;
s32 n=*p;
u32 repeat=keys[1];
s32 max;
if(repeat&64) {
if(n==0||n==7) {if(repeat==keys[0]) {n+=6;max=M2C_FIELD(&data_0215d850,s32 *,4)-1;if(n>=max)n=max;}}
else n--;
}
if(repeat&128) {
if(n==6||n==13||n==M2C_FIELD(&data_0215d850,s32 *,4)-1) {if(repeat==keys[0]) {n-=6;if(n<0)n=0;}}
else n++;
}
max=M2C_FIELD(&data_0215d850,s32 *,4);
if(max>7) {
if((repeat&32)&&n>=7)n-=7;
if((repeat&16)&&n<7)n+=7;
max--;if(n>=max)n=max;
}
func_020b1c60(n);
if(data_02101e84[0]&1) {func_020b2e14(p);return;}
if(data_02101e84[0]&2)func_020b2e2c();
}

void func_020b96e0(u8 *a) {
    s32 func_020d2dcc(s32);
    M2C_UNK func_0208fe30(s32);
    void func_02096b6c(u32);
    void *func_01ffa770(M2C_UNK *);
    M2C_UNK func_020b2178();
    M2C_UNK func_01ffa9bc(M2C_UNK *);
    void func_020b953c(s32, s32);
    extern void **gCurrentMap;
    extern u8 data_0215d859[];
    extern u8 data_0215d858[];
    extern M2C_UNK data_021291b0;
    u8 index = *a;
    if (data_0215d859[index * 2] == 1) {
        func_0208fe30(0x1001d);
        return;
    }
    if (!func_020d2dcc(M2C_FIELD(*gCurrentMap, u16 *, 0x52a4))) {
        func_0208fe30(0x1001d);
        func_02096b6c(0xc0000332);
    } else {
        void *result = func_01ffa770(&data_021291b0);
        func_020b953c(data_0215d858[index * 2], (s32)result);
    }
    func_020b2178();
    func_01ffa9bc(&data_021291b0);
}

void func_020b9778(void) {
    M2C_UNK func_01ffa9bc(M2C_UNK *);
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020b2178();
    extern M2C_UNK data_021291b0;
    func_0208fe30(0x10018);
    func_020b2178();
    func_01ffa9bc(&data_021291b0);
}

void func_020b979c(u8 *a) {
    void func_020b9558(u8);
    M2C_UNK func_0208fe30(s32);
    extern u8 data_0215d858[];
    func_020b9558(data_0215d858[*a * 2]);
    func_0208fe30(0x10019);
}

void func_020b97c4(s32 a,s32 b) {void func_020b9874(s8);M2C_UNK func_01ffa3dc(M2C_UNK *,s32);extern void **gCurrentMap;extern M2C_UNK data_0215d850;extern M2C_UNK data_021291b0;u8 *g=*gCurrentMap;u32 type=M2C_FIELD(g+(a+M2C_FIELD(g+b*2,u16 *,0x3758)),u8 *,0x1420)&31;switch(type){case 15:case 16:case 17:data_0215d850=7;break;case 18:data_0215d850=16;break;case 19:data_0215d850=32;break;}
func_020b9874((s8)data_0215d850);func_01ffa3dc(&data_021291b0,7);
}

void func_020b9874(s8 mask) {
    s32 func_020b9e20(s32, s32);
    s32 func_020d2d38(s32, s32);
    extern s8 data_ov000_021aab94[];
    extern u8 data_ov000_021b5bfc[];
    extern u8 data_0215d858[];
    extern M2C_UNK data_0215d850;
    extern void **gCurrentMap;

    u8 *buf = data_0215d858;
    s8 *table = data_ov000_021aab94;
    u8 *attrs = data_ov000_021b5bfc;
    u8 count = 0;
    u8 i = 0;
    if (table[0] != -1) {
        do {
            u8 kind = (u8)table[i];
            if (mask & attrs[kind * 0x70 + 0x13]) {
                void **gp = gCurrentMap;
                void *g = *gp;
                u16 idx = *(u16 *)((u8 *)g + 0x52a4);
                if (func_020b9e20((s32)&((u8 *)g)[0x52a4], kind) != 0) {
                    void *g2 = *gp;
                    s32 base = func_020d2d38(idx, kind);
                    s32 total = *(s32 *)((u8 *)g2 + idx * 0x8c + 0x67a4);
                    u8 flag = (total < base) ? 1 : 0;
                    buf[count * 2 + 1] = flag;
                    buf[count * 2] = kind;
                    count++;
                }
            }
            i++;
        } while (table[i] != -1);
    }
    M2C_FIELD(&data_0215d850, s32 *, 4) = count;
    buf[count * 2] = 0;
}

void func_020b9978(void) {
    M2C_UNK func_01ff9ce8(M2C_UNK, s32);
    extern void *gCur3DSpriteEngine;
    func_01ff9ce8(1, M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24));
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_020b99ac(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_0209bfdc(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u16, u16);
    M2C_UNK func_0209c048(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u16, u16);
    M2C_UNK func_0207a61c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, u16, u8, u8);
    M2C_UNK func_020d2d38(M2C_UNK, M2C_UNK);
    extern u8 data_0215d858[];
    extern void *gCur3DSpriteEngine;
    extern void **gCurrentMap;
    extern u8 data_ov000_021b5bfc[];

    u8 *ptr = data_0215d858 + arg2 * 2;
    s16 v0plus3 = (s16)(arg0 + 3);
    u16 v0plus1 = (u16)(arg0 + 1);
    s16 v0plus14 = (s16)(arg0 + 14);
    u16 i;
    u8 kind;
    u8 flag;
    s32 r7;
    u16 r8;
    s32 dataword;
    s16 r9;
    s32 gcur24;
    u16 idx;
    s32 baseval;

    for (i = 0; i < 7; i++) {
        kind = ptr[i * 2];
        if (kind == 0) {
            break;
        }
        flag = ptr[i * 2 + 1];
        if (flag != 0) {
            r7 = 3;
            r8 = 0x100;
        } else {
            r7 = 0;
            r8 = M2C_FIELD(*gCurrentMap, u16 *, 0x52a8);
        }

        dataword = M2C_FIELD(data_ov000_021b5bfc, s32 *, (s32)kind * 0x70);
        r9 = (s16)((arg1 + 1) + i * 2);
        gcur24 = M2C_FIELD(gCur3DSpriteEngine, s32 *, 0x24);

        func_0209bfdc(v0plus3, r9, gcur24, dataword, 0, (u16)r7);

        idx = M2C_FIELD(*gCurrentMap, u16 *, 0x52a4);
        baseval = func_020d2d38(idx, kind);

        func_0209c048(v0plus14, r9, gcur24, baseval, 0, (u16)r7);

        func_0207a61c(gcur24, v0plus1, (u16)r9, kind, r8, 0, 0);
    }

    M2C_FIELD(gCur3DSpriteEngine, u16 *, 0x3a) = 0;
    M2C_FIELD(gCur3DSpriteEngine, u16 *, 0x42) = 0;
    M2C_FIELD(gCur3DSpriteEngine, u16 *, 0x3c) = 0;
    M2C_FIELD(gCur3DSpriteEngine, u16 *, 0x44) = 0;
    M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) = (u8)(M2C_FIELD(gCur3DSpriteEngine, u8 *, 0x46) | 2);
}

void func_020b9b48(s32 a,s32 b,s32 c) {M2C_UNK func_020b22a4(s32,s32,M2C_UNK *,s32);extern u8 data_0215d858[];extern M2C_UNK data_02129150;s32 i;Unk020BChoice *p; a=(a+1)*8;b=(b+1)*8;i=0;p=(Unk020BChoice *)data_0215d858+c;do {if(p[i].value==0)return;func_020b22a4(a,b,&data_02129150,c+i);i++;b=b+16;}while(i<7);}

void func_020b9bac(M2C_UNK a,M2C_UNK b,M2C_UNK c){void func_020b99ac(M2C_UNK,M2C_UNK,M2C_UNK);M2C_UNK func_020c08f8(M2C_UNK,M2C_UNK,M2C_UNK,M2C_UNK,s32);func_020c08f8(a,b,16,16,1);func_020b99ac(a,b,c);}

void func_020b9bec(void){void func_020b9b48(s32,s32,s32);void func_020b1c78(s32);extern M2C_UNK data_0215d850;if(M2C_FIELD(&data_0215d850,s32 *,4)<=7)func_020b9b48(8,4,0);else{func_020b9b48(0,4,0);func_020b9b48(16,4,7);}func_020b1c78(0);}

void func_020b9c40(void){extern M2C_UNK data_0215d850;if(M2C_FIELD(&data_0215d850,s32 *,4)<=7){func_020b9bac(8,4,0);return;}func_020b9bac(0,4,0);func_020b9bac(16,4,7);}

