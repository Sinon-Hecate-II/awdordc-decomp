/* 18 functions from 0x02046D38 to 0x02047B84 (main), found by ds-decomp. */
#include "common.h"

typedef struct { u32 lo, hi; } Unk046Pair;
typedef struct { Unk046Pair a, b; s32 flag; } Unk046State;
void func_02045cbc(void *);
s32 func_02045d94(void *, s32);
s32 func_02046ebc(void *);

s32 func_02047098(s32 arg0) { Unk046State s; if (func_02046ebc(&s)==0) return 0; if(func_02045d94(&s,arg0)!=0) return 1; return 0; }

s32 func_020470dc(Unk046State *p, s32 x) { Unk046State s; func_02045cbc(&s); *(u64 *)&p->a=*(u64 *)&p->b; *(u64 *)&p->b=*(u64 *)&s.b; if(func_02045d94(p,x)!=0) return 1; return 0; }

void func_020472cc(Unk046State *p) { Unk046State s; func_02045cbc(&s); *(u64 *)&p->a=*(u64 *)&s.a; *(u64 *)&p->b=*(u64 *)&s.b; p->flag=*(u64 *)&s.a != 0; }

s32 func_02047320(void) { Unk046State s; func_02045cbc(&s); if(*(u64 *)&s.b==0 && *(u64 *)&s.a==0)return 1;return 0; }

u32 func_02047370(u32 n) { return ((n % 3 != 0) + n / 3) * 4; }

void func_020473a8(void) {

}

void func_020475b8(s32 arg0) {
    extern s32 data_0213db80;
    data_0213db80 = arg0 | (arg0 << 0x10);
}

s32 func_020475cc(void) { extern M2C_UNK data_020fca58; extern s32 data_0213db80; data_0213db80=(M2C_FIELD(&data_020fca58,s32 *,0x44)*data_0213db80+M2C_FIELD(&data_020fca58,s32 *,0x48))%M2C_FIELD(&data_020fca58,s32 *,0x4c); return (data_0213db80>>16)&255; }

void func_02047750(s32 arg0) { register M2C_UNK *p; extern M2C_UNK data_020fca58,data_020fcad0,data_020fcaf8; M2C_FIELD(&data_020fca58,s32 *,8)=-1; M2C_FIELD(&data_020fca58,s32 *,0x54)=0; M2C_FIELD(&data_020fca58,s32 *,0x58)=0; if(arg0) p=&data_020fcad0; else p=&data_020fcaf8; M2C_FIELD(&data_020fca58,s32 *,0x5c)=0; M2C_FIELD(&data_020fca58,s32 *,0x60)=0; M2C_FIELD(&data_020fca58,s32 *,0x64)=0; M2C_FIELD(&data_020fca58,M2C_UNK **,0)=p; func_02044e04(0); M2C_FIELD(&data_020fca58,s32 *,4)=3; }

void func_020478b8(void) { extern M2C_UNK data_020fca58; M2C_UNK func_020376d8(s32,s32,s32); s32 p; p=M2C_FIELD(&data_020fca58,s32 *,0x54);if(p) {func_020376d8(0,p,0);M2C_FIELD(&data_020fca58,s32 *,0x54)=0;} p=M2C_FIELD(&data_020fca58,s32 *,0x60);if(p) {func_020376d8(0,p,0);M2C_FIELD(&data_020fca58,s32 *,0x64)=0;M2C_FIELD(&data_020fca58,s32 *,0x60)=0;} func_02044e28(); M2C_FIELD(&data_020fca58,s32 *,4)=2; }

s32 func_02047928(s32 *arg0) {
    extern M2C_UNK data_020fca58;
    *arg0 = M2C_FIELD(&data_020fca58, s32 *, 0x64);
    return M2C_FIELD(&data_020fca58, s32 *, 0x60);
}

