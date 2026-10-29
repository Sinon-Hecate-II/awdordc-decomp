/* 27 functions from 0x021893E4 to 0x0218A384 (ov001), found by ds-decomp. */
#include "common.h"
typedef struct A070Node { struct A070Node *prev; struct A070Node *next; s32 start; u8 size; u8 pad[3]; } A070Node;
typedef struct A070Pool { u8 pad[0x200]; A070Node head; A070Node tail; s32 unk220; s32 handle; } A070Pool;

void func_ov001_021893e4(void) {
    s32 func_ov001_021878c8(void);
    s32 func_ov001_021878dc(s32);
    void func_ov001_02186fa0(M2C_UNK, M2C_UNK);
    s32 func_ov001_021873ec(void);
    void func_ov001_02187454(void);
    void func_ov001_0218754c(void);
    s32 func_ov001_02188394(void);
    s32 func_ov001_02188c28(void);
    extern void *data_ov001_02193e28;

    s32 r0 = func_ov001_021878c8();
    switch (r0) {
    case 1: {
        void *p = data_ov001_02193e28;
        func_ov001_02186fa0((u8 *)p + 0xAB4,
            M2C_FIELD(p, u16 *, 0x64A));
        return;
    }
    case 2: {
        s32 r = func_ov001_021878dc(2);
        if (r != 0) {
            M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 5;
            return;
        }
        r = func_ov001_021878dc(3);
        if (r != 0) {
            M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 6;
            return;
        }
        r = func_ov001_021878dc(4);
        if (r == 0) {
            u8 st = M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90);
            if (st != 5) {
                return;
            }
            r = func_ov001_021878dc(2);
            if (r != 0) {
                return;
            }
            M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 0xd;
            return;
        }
        M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 6;
        return;
    }
    case 3: {
        s32 r = func_ov001_021873ec();
        if (r != 0) {
            func_ov001_02187454();
            return;
        }
        {
            u8 v = M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90);
            if ((u8)(v + 0xfa) > 1) {
                return;
            }
        }
        r = func_ov001_021878dc(3);
        if (r != 0) {
            return;
        }
        M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 0x12;
        return;
    }
    case 5: {
        M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 0x7;
        return;
    }
    case 7: {
        func_ov001_0218754c();
        M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 0x1;
        return;
    }
    case 0: {
        s32 r = func_ov001_02188394();
        if (r == 3) {
            return;
        }
        if (r == 1) {
            func_ov001_02188c28();
            return;
        }
        M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 0x1f;
        return;
    }
    case 4:
    case 6:
    default:
        return;
    }
}

void func_ov001_0218959c(void) {
    M2C_UNK func_ov001_02189828(void);
    void func_ov001_02188a20(s32);
    extern s32 func_ov001_021897ec(s32);
    extern void *data_ov001_02193e28;
    func_ov001_02189828();
    func_ov001_02188a20((s32) &func_ov001_021897ec);
    M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 8;
}

void func_ov001_021895c8(void) {
    s32 func_ov001_02188394(void);
    void func_ov001_021888a8(s32, u16, u16, s32);
    void func_ov001_0218986c(s32, s32, void *);
    void func_ov001_021899d4(void);
    u16 func_ov001_02189ab8(void);
    extern void *data_ov001_02193e28;

    s32 state = func_ov001_02188394();
    switch (state) {
    case 1: {
        u16 w = *(u16 *)((u8 *)data_ov001_02193e28 + 0x648);
        u16 h = *(u16 *)((u8 *)data_ov001_02193e28 + 0x64a);
        func_ov001_021888a8(4, (u16)(w + 1), h, w);
        break;
    }
    case 4:
    case 5:
    case 6: {
        u16 h = *(u16 *)((u8 *)data_ov001_02193e28 + 0x200);
        void *base = *(void **)((u8 *)data_ov001_02193e28 + 0xaa4);
        u32 rem = h % 16;
        void *ptr = (u8 *)base + (rem << 6);
        func_ov001_0218986c(0, h, ptr);
        func_ov001_021899d4();
        if (*(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) == 0x1b) break;
        if (*(u32 *)((u8 *)data_ov001_02193e28 + 0x204) > 0x1e0) {
            *(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) = 0x1b;
            break;
        }
        if (func_ov001_02189ab8() == 0x10 || func_ov001_02189ab8() == 0x20) {
            func_ov001_02189ab8();
            *(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) = 0xa;
        } else if (func_ov001_02189ab8() == 0x40) {
            *(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) = 0xb;
        } else if (func_ov001_02189ab8() == 0xff) {
            *(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) = 0x1b;
        } else if (func_ov001_02189ab8() == 0x50) {
            *(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) = 0x15;
        } else if (func_ov001_02189ab8() == 0x60) {
            *(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) = 0x18;
        } else if (func_ov001_02189ab8() == 0x70) {
            *(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) = 0x1b;
        } else if (func_ov001_02189ab8() == 0x0) {
            *(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) = 0x8;
        } else if (func_ov001_02189ab8() == 0xbd) {
            *(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) = 0x9;
        } else {
            *(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) = 0x1f;
        }
        break;
    }
    default:
        break;
    }
}

void func_ov001_021897a4(void) {
    extern void *data_ov001_02193e28;
    M2C_FIELD(data_ov001_02193e28, s8 *, 0xA90) = 0xC;
}

s32 func_ov001_021897bc(void) {
    M2C_UNK func_ov001_02188394(void);
    M2C_UNK func_ov001_02188c28(void);
    extern void *data_ov001_02193e28;
    if (func_ov001_02188394() != 1) {
        return 0;
    }
    func_ov001_02188c28();
    M2C_FIELD(data_ov001_02193e28, u8 *, 0xA90) = 1;
    return 1;
}

s32 func_ov001_021897ec(s32 arg0) {
    s32 func_ov001_02187a30(s32);
    s32 func_ov001_021879fc(s32);
    extern void *data_ov001_02193e28;
    s32 temp_r0;

    temp_r0 = func_ov001_02187a30(arg0 + 0xA);
    if (temp_r0 == 0) {
        return 0;
    }
    M2C_FIELD((u8 *) data_ov001_02193e28 + (temp_r0 - 1) * 4, s32 *, 0xAA0) = func_ov001_021879fc(temp_r0);
    return 1;
}

M2C_UNK func_ov001_02189828(void) {
 extern void *data_ov001_02193e28; void func_02007f8c(void*,s32,s32); void *p;
 func_02007f8c((u8*)data_ov001_02193e28+0x100,0,0x100);
 func_02007f8c(data_ov001_02193e28,0,0x100);
 p=data_ov001_02193e28;
 M2C_FIELD(p,void**,0xAB0)=p;
 return (s32)p;
}

void func_ov001_0218986c(s32 arg0, s32 arg1, void *arg2) {
    M2C_UNK func_ov001_02188394(void);
    M2C_UNK func_ov001_02188a5c(void *);
    M2C_UNK func_ov001_02188380(void);
    M2C_UNK func_ov001_02188a34(s32);
    M2C_UNK func_02008048(M2C_UNK, M2C_UNK, M2C_UNK);
    extern void *data_ov001_02193e28;
    u16 i;
    u8 *p;

    if (*(u8 *)((u8 *)data_ov001_02193e28 + 0xa93) == 1) {
        p = *(u8 **)((u8 *)data_ov001_02193e28 + 0xab0);
        *(u16 *)p = (u16)arg0;
        *(((u16 *)p) + 1) = (u16)arg1;
        func_02008048(arg2, p + 4, 0x40);
        return;
    }

    *(u32 *)((u8 *)data_ov001_02193e28 + 0x204) += 1;
    p = *(u8 **)((u8 *)data_ov001_02193e28 + 0xab0);
    *(u16 *)p = 0xbc;
    p[4] = *(u8 *)((u8 *)data_ov001_02193e28 + 0xa92);

    if (func_ov001_02188394() != 5) {
        return;
    }
    if (func_ov001_02188a5c(data_ov001_02193e28) == 0) {
        *(u32 *)((u8 *)data_ov001_02193e28 + 0x204) += 4;
        return;
    }
    if (*(u8 *)((u8 *)data_ov001_02193e28 + 0xa93) == 0) {
        *(u32 *)((u8 *)data_ov001_02193e28 + 0x204) += 1;
    } else {
        *(u32 *)((u8 *)data_ov001_02193e28 + 0x204) = 0;
        if (func_ov001_02188380() != 3) {
            *(u8 *)((u8 *)data_ov001_02193e28 + 0xa90) = 0x1b;
            return;
        }
    }

    for (i = 0; i < 2; i = (u16)(i + 1)) {
        void *src = func_ov001_02188a34(i);
        if (src == 0) {
            *(s32 *)((u8 *)data_ov001_02193e28 + 0x208 + i * 4) = 0;
        } else {
            func_02008048(src, (u8 *)data_ov001_02193e28 + 0x100 + i * 0x44, 0x44);
            *(s32 *)((u8 *)data_ov001_02193e28 + 0x208 + i * 4) = 1;
        }
    }
}

#pragma optimization_level 2
void func_ov001_021899d4(void) {
extern void *data_ov001_02193e28;s32 i;u8 *p;
i=0;do {
if(M2C_FIELD((u8 *)data_ov001_02193e28+i*4,s32*,0x208)){
p=(u8 *)data_ov001_02193e28+0x100+i*0x44;
if(i==1){
if(M2C_FIELD(data_ov001_02193e28,u8*,0xa93)==1){
if(*(u16 *)p!=0x10)return;
M2C_FIELD(data_ov001_02193e28,s32*,0xa94)++;
if(!(M2C_FIELD(data_ov001_02193e28,s32*,0xa94)&1)){
M2C_FIELD(data_ov001_02193e28,u16*,0x200)++;
if(M2C_FIELD(data_ov001_02193e28,u16*,0x200)>=0x24)M2C_FIELD(data_ov001_02193e28,u16*,0x200)=0;
}
}else{
M2C_FIELD(data_ov001_02193e28,u16*,0x202)=0xbc;
if(*(u16 *)p==0xbd){
M2C_FIELD(data_ov001_02193e28,u8*,0xa93)=1;
M2C_FIELD(data_ov001_02193e28,u16*,0x200)=0;
M2C_FIELD(data_ov001_02193e28,s32*,0xa94)=0;
}
}
}
}
i++;
}while(i<16);
}
#pragma optimization_level 4
u16 func_ov001_02189ab8(void) {
    extern void *data_ov001_02193e28;
    void *ptr = data_ov001_02193e28;
    return M2C_FIELD((u8 *)ptr + 0x100, u16 *, 0x44);
}

void func_ov001_02189ad0(void) {
    s32 func_ov001_0218b6f8(s32, s32);
    void func_0200b774(void *);
    s32 func_0200ba54(void *, void *);
    void func_02007958(void);
    s32 func_0200558c(void);
    void func_0200bbe0(void *, void *, s32);
    void func_0200ba9c(void *);
    void func_0200b118(void *);
    s32 func_0200b184(void *, void *, s32);
    void func_0200b6a8(void *, s32, s32);
    s32 func_0200b2bc(void *, s32, s32, s32, s32, s32, void *, void *);
    s32 func_0200b3ec(void *, s32, s32);
    s32 func_ov001_0218a698(s32, s32, s32);
    void func_0200563c(void *, void *, ...);
    void func_0200bc5c(void *);
    extern void *data_ov001_02193e2c;
    extern void *data_ov001_02191794;
    extern void *data_ov001_0218fd04;
    extern void *data_ov001_021917ac;
    s32 func_ov001_02189d0c(s32, s32);
    s32 func_ov001_02189d70();
    s32 func_ov001_02189dc0(void);

    struct { u8 pad[0x10]; u32 sp10, sp14, sp18, sp1c; u8 name[0x80]; u8 file[0x48]; } fr;
    s32 r4;
    void *buf;
    s32 size;

    data_ov001_02193e2c = (void *)func_ov001_0218b6f8(0xE8, 4);
    func_0200b774(fr.file);
    if (!func_0200ba54(fr.file, data_ov001_02191794)) {
        func_02007958();
        M2C_FIELD(data_ov001_02193e2c, u16 *, 0xE4) = (u16)func_0200558c();
    }
    r4 = *(s32 *)(fr.file + 0x24);
    func_0200bbe0(fr.file, &fr.sp18, 8);
    func_0200bbe0(fr.file, &fr.sp10, 8);
    func_0200ba9c(fr.file);
    func_0200b118((u8 *)data_ov001_02193e2c + 0x88);
    if (!func_0200b184((u8 *)data_ov001_02193e2c + 0x88, data_ov001_0218fd04, 3)) {
        func_02007958();
    }
    func_0200b6a8((u8 *)data_ov001_02193e2c + 0x88, (s32)func_ov001_02189d0c, 0x602);
    if (!func_0200b2bc((u8 *)data_ov001_02193e2c + 0x88, r4, fr.sp10, fr.sp14, fr.sp18, fr.sp1c, (void *)func_ov001_02189d70, (void *)func_ov001_02189dc0)) {
        func_02007958();
    }
    size = func_0200b3ec((u8 *)data_ov001_02193e2c + 0x88, 0, 0);
    buf = (void *)func_ov001_0218b6f8(size, 4);
    *(void **)data_ov001_02193e2c = buf;
    func_0200b3ec((u8 *)data_ov001_02193e2c + 0x88, (s32)buf, size);
    M2C_FIELD(data_ov001_02193e2c, s32 *, 0x84) = (s32)func_ov001_0218a698(0x20, (s32)((u8 *)data_ov001_021917ac + 4), 4);
    func_0200563c(fr.name, data_ov001_021917ac, data_ov001_0218fd04);
    func_0200bc5c(fr.name);
}

void func_ov001_02189c80(void) {
extern void *data_ov001_021917b4[2];
extern void *data_ov001_02193e2c;
void func_0200bc5c(void *);
void func_0200b510(void *);
void func_0200b32c(void *);
void func_0200b238(void *);
void func_020055f4(u16);
void func_ov001_0218b71c(void *);
func_0200bc5c(data_ov001_021917b4);
func_0200b510((u8 *)data_ov001_02193e2c+0x88);
func_0200b32c((u8 *)data_ov001_02193e2c+0x88);
func_0200b238((u8 *)data_ov001_02193e2c+0x88);
func_020055f4(M2C_FIELD(data_ov001_02193e2c,u16 *,0xe4));
M2C_FIELD(data_ov001_02193e2c,u16 *,0xe4)=0;
func_ov001_0218b71c(data_ov001_02193e2c);
M2C_FIELD(data_ov001_02193e2c,u32 *,0)=0;
func_ov001_0218b71c((void *)0x02193e2c);
}

s32 func_ov001_02189d0c(s32 arg0, s32 arg1) {
    M2C_UNK func_0200fe24(u16);
    M2C_UNK func_0200fe40(u16);
    extern void *data_ov001_02193e2c;
    
    switch (arg1) {
    case 9:
        func_0200fe24(M2C_FIELD(data_ov001_02193e2c, u16 *, 0xE4));
        return 0;
    case 10:
        func_0200fe40(M2C_FIELD(data_ov001_02193e2c, u16 *, 0xE4));
        return 0;
    case 1:
        return 4;
    default:
        return 8;
    }
}

void func_ov001_02189db0(M2C_UNK arg0);

s32 func_ov001_02189d70(void *arg0,s32 arg1,s32 arg2,s32 arg3) {
 void func_02010b1c(s32,s32,s32,s32,s32,void*,s32);
 func_02010b1c(-1,arg2+M2C_FIELD(arg0,s32*,0x28),arg1,arg3,(s32)func_ov001_02189db0,arg0,1);
 return 6;
}

void func_ov001_02189db0(M2C_UNK arg0) {
    M2C_UNK func_0200b6c8(M2C_UNK, M2C_UNK);
    func_0200b6c8(arg0, 0);
}

s32 func_ov001_02189dc0(void) {
    return 1;
}

void *func_ov001_02189dc8(void *arg0,u32 *arg1,s32 arg2){
s32 func_ov001_0218a74c(s32);void func_0200b774(void *);s32 func_0200ba54(void *,void *);void func_02007958(void);void func_0200bbe0(void *,void *,s32);void func_0200ba9c(void *);void func_020081d0(void *,void *);void func_ov001_0218b71c(void *);s32 func_ov001_0218b6f8(s32,s32);
extern void *data_ov001_02193e2c;extern s32 data_ov001_021917bc;
void *buf;u32 work[18];u32 size;s32 align;void *out;
func_ov001_0218a74c(M2C_FIELD(data_ov001_02193e2c,s32*,0x84));
func_0200b774(work);if(!func_0200ba54(work,arg0))func_02007958();
size=work[10]-work[9];if(arg1)*arg1=size;
if(func_ov001_02189ef0(arg0,(s32)&data_ov001_021917bc,2))align=-4;else align=arg2;
buf=(void *)func_ov001_0218b6f8(size,align);
func_0200bbe0(work,buf,size);func_0200ba9c(work);
if(align>0)return buf;
size=*(u32 *)buf>>8;if(arg1)*arg1=size;
out=(void *)func_ov001_0218b6f8(size,arg2);func_020081d0(buf,out);func_ov001_0218b71c(&buf);return out;
}

void func_ov001_02189ebc(s32 arg0, ...) {
 M2C_UNK func_ov001_0218a6f4(s32,void*); void func_ov001_0218b71c(void*); extern void *data_ov001_02193e2c;
 func_ov001_0218b71c(&arg0);
 func_ov001_0218a6f4(M2C_FIELD(data_ov001_02193e2c,s32*,0x84),(void*)arg0);
}

s32 func_ov001_02189ef0(void *arg0, s32 arg1, s32 arg2) {
    s32 func_02068c34(void *);
    s32 func_0206527c(void *, void *, s32);
    s32 temp_r4;
    s32 temp_r0;
    
    temp_r4 = func_02068c34(arg0);
    temp_r0 = func_02068c34(arg1);
    if (temp_r4 < arg2 || temp_r0 < arg2) {
        return 0;
    }
    if (func_0206527c(arg0 + (temp_r4 - arg2), arg1 + (temp_r0 - arg2), arg2) == 0) {
        return 1;
    }
    return 0;
}

void func_ov001_02189f48(void) {
s32 func_ov001_0218a698(s32,s32,s32);s32 func_ov001_0218b6f8(s32,s32);s32 func_ov001_0218bf04();M2C_UNK func_ov001_0218bfb4(s32,void *);M2C_UNK func_ov001_0218bfc4(s32,void *);s32 func_ov001_0218c150(s32,s32);
extern s32 data_ov001_02193e30;
s32 i;void *p;
data_ov001_02193e30=func_ov001_0218b6f8(0x450,4);
for(i=0;i<2;i++){
M2C_FIELD(data_ov001_02193e30+i*0x228,s32*,0x224)=func_ov001_0218a698(0x20,data_ov001_02193e30+i*0x228,0x10);
M2C_FIELD(data_ov001_02193e30+i*0x228,s32*,0x220)=func_ov001_0218bf04();
M2C_FIELD(data_ov001_02193e30+i*0x228,s32*,0x208)=func_ov001_0218c150(i,0x40);
M2C_FIELD(data_ov001_02193e30+i*0x228,s32*,0x218)=func_ov001_0218c150(i,0x7f)+8;
p=(void *)(data_ov001_02193e30+i*0x228);func_ov001_0218bfc4(M2C_FIELD(p,s32*,0x220),p+0x200);
p=(void *)(data_ov001_02193e30+i*0x228);func_ov001_0218bfb4(M2C_FIELD(p,s32*,0x220),p+0x210);
}
}

#pragma push
#pragma merge_constants off
#pragma opt_common_subs off
void func_ov001_0218a01c(void) {
    void func_ov001_0218a6d8(s32);
    void func_ov001_0218b71c(void *);
    void func_ov001_0218bf30(s32);
    extern s32 data_ov001_02193e30;
    s32 i, offset;
    i=0; offset=0;
    do {
        func_ov001_0218bf30(M2C_FIELD(data_ov001_02193e30+offset,s32*,0x220));
        func_ov001_0218a6d8(M2C_FIELD(data_ov001_02193e30+offset,s32*,0x224));
        i++;
        offset+=0x228;
    }while(i<2);
    (void)data_ov001_02193e30;
    func_ov001_0218b71c(&data_ov001_02193e30);
}
#pragma pop
void *func_ov001_0218a070(s32 in_idx, s32 in_arg1, s32 in_arg2) {
    s32 func_ov001_0218a74c(s32);
    s32 func_020051f8(s32);
    void func_020051c8(s32);
    void func_02007958(void);
    void func_ov001_0218bf84(void *, void *);
    extern s32 data_ov001_02193e30;
    s32 idx = in_idx;
    s32 arg1 = in_arg1;
    s32 off = idx * 0x228;
    A070Node *node;
    s32 state;
    s32 arg2 = in_arg2;
    A070Node *cur;
    A070Node *next;
    A070Node *prev;
    A070Node *bound;
    A070Node *headBound;
    s32 curEnd;
    s32 need;

    node = (A070Node *)func_ov001_0218a74c(*((s32 *)(data_ov001_02193e30 + off + 0x224)));
    state = func_020051f8(1);
    if (arg2 != 0) {
        bound = (A070Node *)(data_ov001_02193e30 + off + 0x210);
        cur = (A070Node *)(data_ov001_02193e30 + off + 0x200);
        if (cur != bound) {
            do {
                next = cur->next;
                curEnd = cur->start + cur->size * 8;
                need = curEnd + arg1 * 8;
                if ((u32)need <= (u32)next->start) {
                    node->start = curEnd;
                    func_ov001_0218bf84(next, node);
                    break;
                }
                cur = next;
            } while (next != bound);
        }
        if (cur == bound) {
            func_02007958();
        }
    } else {
        bound = (A070Node *)(data_ov001_02193e30 + off + 0x210);
        headBound = (A070Node *)(data_ov001_02193e30 + off + 0x200);
        cur = bound;
        if (cur != headBound) {
            do {
                prev = cur->prev;
                curEnd = cur->start - arg1 * 8;
                need = prev->start + prev->size * 8;
                if ((u32)curEnd >= (u32)need) {
                    node->start = curEnd;
                    func_ov001_0218bf84(cur, node);
                    break;
                }
                cur = prev;
            } while (prev != headBound);
        }
        if (cur == headBound) {
            func_02007958();
        }
    }
    func_020051c8(state);
    node->size = (u8)arg1;
    return node;
}

void func_ov001_0218a1cc(void *arg0) {
    M2C_UNK func_ov001_0218a6f4(s32, void *);
    M2C_UNK func_ov001_0218bf4c(void *);
    extern s32 data_ov001_02193e30;
    u8 *var_r2;
    s32 var_r3;
    s32 var_r4;

    var_r4 = 0;
    var_r3 = 0;
    var_r2 = M2C_FIELD(arg0, u8 **, 8);
    if ((s32) M2C_FIELD(arg0, u8 *, 0xC) > 0) {
        do {
            var_r3 += 1;
            M2C_FIELD(var_r2, s32 *, 0) = (M2C_FIELD(var_r2, s32 *, 0) & 0xC1FFFCFF) | 0x200;
            var_r2 += 8;
        } while (var_r3 < (s32) M2C_FIELD(arg0, u8 *, 0xC));
    }
    func_ov001_0218bf4c(arg0);
    if ((u32) arg0 >= (u32) (data_ov001_02193e30 + 0x228)) {
        var_r4 = 1;
    }
    func_ov001_0218a6f4(M2C_FIELD(((var_r4 * 0x228) + data_ov001_02193e30), s32 *, 0x224), arg0);
}

s32 func_ov001_0218a24c(void *arg0, s32 arg1) {
    return M2C_FIELD(arg0, s32 *, 8) + (arg1 * 8);
}

u8 func_ov001_0218a258(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0xC);
}

void func_ov001_0218a260(void *arg0,s32 arg1,s32 arg2,s32 arg3){
u32 (*array)[2]=*(u32 (**)[2])((u8 *)arg0+8);
u32 val; s32 i;
if(arg1>=0){
if(arg2!=0x100 && arg2!=0x300){val=array[arg1][0]&0xc1fffcff;val|=arg2;array[arg1][0]=val;}
else{val=array[arg1][0]&0xc1fffcff;val|=arg2;val|=arg3<<25;array[arg1][0]=val;}
}else{
for(arg1=0;arg1<M2C_FIELD(arg0,u8 *,12);arg1++){
if(arg2!=0x100 && arg2!=0x300){val=array[arg1][0]&0xc1fffcff;val|=arg2;}
else {val=array[arg1][0]&0xc1fffcff;val|=arg2;val|=arg3<<25;}
array[arg1][0]=val;
}
}
}

#pragma push
#pragma opt_strength_reduction off
void func_ov001_0218a304(void *obj, s32 index, u32 a, u32 b) {
 u8 *entries=M2C_FIELD(obj,u8**,8);
 s32 i;
 if(index>=0) {
  M2C_FIELD(entries+index*8,u32*,0)=(M2C_FIELD(entries+index*8,u32*,0)&~0xc00U)|(a<<10);
  M2C_FIELD(entries+index*8,u16*,4)=(M2C_FIELD(entries+index*8,u16*,4)&~0xf000U)|(b<<12);
 } else {
  for(i=0;i<M2C_FIELD(obj,u8*,12);i++) {
   M2C_FIELD(entries+i*8,u32*,0)=(M2C_FIELD(entries+i*8,u32*,0)&~0xc00U)|(a<<10);
   M2C_FIELD(entries+i*8,u16*,4)=(M2C_FIELD(entries+i*8,u16*,4)&~0xf000U)|(b<<12);
  }
 }
}
#pragma pop
