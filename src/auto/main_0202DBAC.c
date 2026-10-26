/* 14 functions from 0x0202DBAC to 0x0202E470 (main), found by ds-decomp. */
#include "common.h"
void func_0202de74(void *);
void func_0202dfa8(void *);
void func_0202e12c(M2C_UNK);
void func_0202e02c(M2C_UNK,void *);

void func_0202de1c(void *arg0,s32 arg1) {
void func_0202eed8(void *,s32);
s32 saved=arg1;
s32 flags=M2C_FIELD(arg0,s32 *,0x110);
arg1=(flags<<30)>>31;
if(arg1==0) {func_0202de74(arg0); return;}
if(saved==0) {func_0202de74(arg0); return;}
func_0202eed8((u8 *)arg0+0xe8,0);
M2C_FIELD(arg0,s32 *,0x110)|=8;
M2C_FIELD(arg0,s32 *,0x150)=0;
}

void func_0202de74(void *arg0) {
    M2C_UNK func_02006564(M2C_UNK *);
    M2C_UNK func_020065e8(M2C_UNK *);
    M2C_UNK func_0202b760(void *);
    M2C_UNK func_0202df0c(void *);
    extern M2C_UNK data_0213c290;
    extern M2C_UNK data_0213c908;
    func_02006564(&data_0213c908);
    if (M2C_FIELD(&data_0213c290, s32 *, 4) != 0) {
        func_02006564(M2C_FIELD(&data_0213c290, s32 *, 4) + 0x4C8);
    }
    if (((s32) (M2C_FIELD(arg0, s32 *, 0x110) << 0x1E) >> 0x1F) != 0) {
        func_0202b760(arg0);
    }
    if (((s32) (M2C_FIELD(arg0, s32 *, 0x110) << 0x1F) >> 0x1F) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0x170)(arg0);
    }
    func_0202df0c(arg0);
    func_020065e8(&data_0213c908);
    if (M2C_FIELD(&data_0213c290, s32 *, 4) == 0) {
        return;
    }
    func_020065e8(M2C_FIELD(&data_0213c290, s32 *, 4) + 0x4C8);
}

M2C_UNK func_0202df0c(void *arg0) {
void func_0202e02c(M2C_UNK,void *); void func_0202db80(void *);
extern M2C_UNK data_0213c920; extern M2C_UNK data_0213c290;
if((M2C_FIELD(arg0,s32 *,0x110)<<31)>>31==0) return;
func_0202dfa8(arg0);
M2C_FIELD(arg0,void (**)(void *),0x168)(arg0);
func_0202e02c((M2C_UNK)&data_0213c920,arg0);
if(M2C_FIELD(&data_0213c290,void **,4)) func_0202e02c((M2C_UNK)((u8 *)M2C_FIELD(&data_0213c290,void **,4)+0x4e0),arg0);
func_0202db80(arg0);
}

s32 func_0202df70(void *arg0,s32 arg1,s32 arg2) {
s32 func_0202b4e4(void *,s32,s32);
if(M2C_FIELD(arg0,s32 *,0x120)==0 && func_0202b4e4(arg0,arg1,arg2)==0) return 0;
M2C_FIELD(arg0,s32 *,0x120)++; return 1;
}

void func_0202dfa8(void *arg0) {
    M2C_UNK func_0202b544();
    s32 temp_r1;
    s32 temp_r1_2;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0x120);
    if (temp_r1 == 0) {
        return;
    }
    temp_r1_2 = temp_r1 - 1;
    M2C_FIELD(arg0, s32 *, 0x120) = temp_r1_2;
    if (temp_r1_2 != 0) {
        return;
    }
    func_0202b544();
}

void func_0202dfcc(void *arg0, s32 arg1) {
    M2C_UNK func_02005ac0(void *, M2C_UNK *, void *, s32, s32, s32);
    M2C_UNK func_02005e5c(void *);
    M2C_UNK func_0200654c(void *);
    M2C_UNK func_02029c30(void *, M2C_UNK);
    extern M2C_UNK func_0202ee30;
    func_02005ac0(arg0, &func_0202ee30, arg0, arg0 + 0x4C0, 0x400, arg1);
    func_02029c30(arg0 + 0x4E0, 0);
    func_0200654c(arg0 + 0x4C8);
    M2C_FIELD(arg0, s32 *, 0x4C4) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C0) = 0;
    func_02005e5c(arg0);
}

void func_0202e02c(M2C_UNK arg0,void *arg1) {
s32 func_0200751c(void); M2C_UNK func_02007530(s32);
void *func_02029ddc(M2C_UNK,M2C_UNK); M2C_UNK func_02029d7c(M2C_UNK,void *);
s32 saved; void *node,*next;
saved=func_0200751c();
node=func_02029ddc(arg0,0);
while(node) {
next=func_02029ddc(arg0,(M2C_UNK)node);
if(M2C_FIELD(node,void **,8)==arg1) {func_02029d7c(arg0,node);func_0202e12c((M2C_UNK)node);}
node=next;
}
func_02007530(saved);
}

void *func_0202e09c(M2C_UNK arg0) {
    M2C_UNK func_02029d7c(M2C_UNK, void *);
    void *func_02029ddc(M2C_UNK, M2C_UNK);
    s32 temp_r4;
    void *temp_r0;
    void *temp_r1;

    temp_r4 = func_0200751c();
    temp_r0 = func_02029ddc(arg0, 0);
    if (temp_r0 != NULL) {
        func_02029d7c(arg0, temp_r0);
        temp_r1 = M2C_FIELD(temp_r0, void **, 8);
        M2C_FIELD(temp_r1, s32 *, 0x11C) = (s32) (M2C_FIELD(temp_r1, s32 *, 0x11C) - 1);
    }
    func_02007530(temp_r4);
    return temp_r0;
}

M2C_UNK func_0202e0ec(void) {
extern M2C_UNK data_0213c29c;
s32 saved; M2C_UNK node;
saved=func_0200751c();
node=(M2C_UNK)func_02029ddc((M2C_UNK)&data_0213c29c,0);
if(node!=0) func_02029d7c((M2C_UNK)&data_0213c29c,(void *)node);
func_02007530(saved);
return node;
}

void func_0202e12c(M2C_UNK arg0) {
    s32 func_0200751c();
    M2C_UNK func_02007530(s32);
    M2C_UNK func_02029c74(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0213c29c;
    s32 temp_r4;

    temp_r4 = func_0200751c();
    func_02029c74(&data_0213c29c, arg0);
    func_02007530(temp_r4);
}

void func_0202e158(s32 arg0,s32 arg1,void *arg2) {
M2C_UNK func_02006564(M2C_UNK *); M2C_UNK func_020065e8(M2C_UNK *); M2C_UNK func_0202b544();
extern M2C_UNK data_0213c290; extern M2C_UNK data_0213c908;
if(arg0!=M2C_FIELD(arg2,s32 *,0x12c)) return;
func_02006564(&data_0213c908);
if(M2C_FIELD(&data_0213c290,s32 *,4)) func_02006564(M2C_FIELD(&data_0213c290,s32 *,4)+0x4c8);
func_0202de74(arg2);
M2C_FIELD(arg2,s32 *,0x12c)=0; M2C_FIELD(arg2,s32 *,0x130)=0; M2C_FIELD(arg2,u8 *,0x124)=0;
if(M2C_FIELD(arg2,s32 *,0x120)>0) {
func_0202b544(arg2); M2C_FIELD(arg2,s32 *,0x120)=0;
}
func_020065e8(&data_0213c908);
if(!M2C_FIELD(&data_0213c290,s32 *,4)) return;
func_020065e8(M2C_FIELD(&data_0213c290,s32 *,4)+0x4c8);
}

