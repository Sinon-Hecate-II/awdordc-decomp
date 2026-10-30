/* 61 functions from 0x02005F80 to 0x02006F14 (main), found by ds-decomp. */
#include "common.h"

typedef struct QueueFields {
    u32 wait[4];
    void **buffer;
    s32 capacity;
    s32 first;
    s32 count;
} QueueFields;

s32 func_02005f80(void *arg0,s32 arg1) {
M2C_UNK func_020057f8(void *); M2C_UNK func_020058a0(); s32 func_0200751c(); void func_02007530(s32); extern M2C_UNK data_0212dc80; extern M2C_UNK data_0212dcb4;
void *cur; void *prev; s32 state;
cur=M2C_FIELD(&data_0212dc80,void **,0x2c);prev=0;state=func_0200751c();
while(cur!=0 && cur!=arg0){prev=cur;cur=M2C_FIELD(cur,void **,0x68);}
if(cur==0 || cur==&data_0212dcb4){func_02007530(state);return 0;}
if(M2C_FIELD(cur,s32 *,0x70)!=arg1){
if(prev==0){M2C_FIELD(&data_0212dc80,void **,0x2c)=M2C_FIELD(arg0,void **,0x68);}else{M2C_FIELD(prev,void **,0x68)=M2C_FIELD(arg0,void **,0x68);}
M2C_FIELD(arg0,s32 *,0x70)=arg1;func_020057f8(arg0);func_020058a0();}
func_02007530(state);return 1;
}

s32 func_02006028(void *arg0) {
    return M2C_FIELD(arg0, s32 *, 0x70);
}

void func_02006030(s32 arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_02007190(void *);
    void func_020072cc(void *, u64, void (*)(void **), void **);
    M2C_UNK func_02005da4(void *);
    extern M2C_UNK data_0212dc80;
    extern void func_020060d8(void **);
    register s32 argSaved = arg0;
    s32 buf[11];
    void *node;
    s32 state;
    u64 delay;

    func_02007190(buf);
    node = M2C_FIELD(M2C_FIELD(&data_0212dc80, void **, 8), void **, 0);
    state = func_0200751c();
    delay = ((u64)(u32)argSaved * 0x82EAULL) >> 6;
    M2C_FIELD(node, void **, 0xB0) = buf;
    func_020072cc(buf, delay, func_020060d8, &node);
    while (node != NULL) {
        func_02005da4(NULL);
    }
    func_02007530(state);
}

void func_020060d8(void **arg0) {
    M2C_UNK func_02005e5c(void *);
    void *temp_r2;

    temp_r2 = *arg0;
    *arg0 = NULL;
    M2C_FIELD(temp_r2, s32 *, 0xB0) = 0;
    func_02005e5c(temp_r2);
}

s32 func_020060f8(s32 arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_0212dc80;
    s32 state;
    s32 temp;

    state = func_0200751c();
    temp = M2C_FIELD(&data_0212dc80, s32 *, 0x30);
    M2C_FIELD(&data_0212dc80, s32 *, 0x30) = arg0;
    func_02007530(state);
    return temp;
}

void func_02006120(void)
{
  s32 func_02007508(void);
  M2C_UNK func_02007968(void);
  func_02007508();
  for (;;)
  {
    func_02007968();
  }

}

s32 func_02006130(void) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_0212dc80;
    s32 state;
    s32 r;
    s32 v;
    s32 limit = -1;

    state = func_0200751c();
    v = M2C_FIELD(&data_0212dc80, s32 *, 4);
    if ((u32)v < (u32)limit) {
        r = v;
        M2C_FIELD(&data_0212dc80, s32 *, 4) = v + 1;
    }
    func_02007530(state);
    return r;
}

s32 func_02006164(void) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_0212dc80;
    s32 state;
    s32 r;
    s32 v;

    state = func_0200751c();
    r = 0;
    v = M2C_FIELD(&data_0212dc80, s32 *, 4);
    if (v != 0) {
        r = v;
        M2C_FIELD(&data_0212dc80, s32 *, 4) = v - 1;
    }
    func_02007530(state);
    return r;
}

void func_02006198(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xB4) = arg1;
}

void func_020061a0(void *arg0, s32 arg1, s32 arg2) {
arg1+=4;
M2C_FIELD(arg0,s32 *,0x40)=arg1;
M2C_FIELD(arg0,s32 *,0x44)=arg2;
arg2-=0x40;
if(arg2&4)arg2-=4;
M2C_FIELD(arg0,s32 *,0x38)=arg2;
arg1 &= 1;
if(arg1) arg1=0x3f;
else arg1=0x1f;
M2C_FIELD(arg0,s32 *,0)=arg1;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
}

s32 func_020062b4(void) {
    return 0;
}

s32 func_020062bc(void) {
    extern s32 data_020f5218;
    s32 v = 0x82000001;
    data_020f5218 = v;
    return v;
}

void func_020062d4(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = arg1;
    M2C_FIELD(arg0, s32 *, 0x14) = arg2;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
}

s32 func_020062fc(void *arg0, s32 arg1, s32 arg2) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    M2C_UNK func_02005df4(void *);
    unsigned long long func_020720f0(s32, s32);
    s32 state;

    state = func_0200751c();
    while (M2C_FIELD(arg0, s32 *, 0x14) <= M2C_FIELD(arg0, s32 *, 0x1C)) {
        if (!(arg2 & 1)) {
            func_02007530(state);
            return 0;
        }
        func_02005da4(arg0);
    }
    ((s32 *)M2C_FIELD(arg0, void **, 0x10))[(s32)(func_020720f0(M2C_FIELD(arg0, s32 *, 0x18) + M2C_FIELD(arg0, s32 *, 0x1C), M2C_FIELD(arg0, s32 *, 0x14)) >> 32)] = arg1;
    M2C_FIELD(arg0, s32 *, 0x1C) = M2C_FIELD(arg0, s32 *, 0x1C) + 1;
    func_02005df4((u8 *)arg0 + 8);
    func_02007530(state);
    return 1;
}

s32 func_02006390(void *arg0, s32 *arg1, s32 arg2) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    M2C_UNK func_02005df4(void *);
    unsigned long long func_020720f0(s32, s32);
    s32 state;

    state = func_0200751c();
    while (M2C_FIELD(arg0, s32 *, 0x1C) == 0) {
        if (!(arg2 & 1)) {
            func_02007530(state);
            return 0;
        }
        func_02005da4((u8 *)arg0 + 8);
    }
    if (arg1 != NULL) {
        *arg1 = ((s32 *)M2C_FIELD(arg0, void **, 0x10))[M2C_FIELD(arg0, s32 *, 0x18)];
    }
    M2C_FIELD(arg0, s32 *, 0x18) = (s32)(func_020720f0(M2C_FIELD(arg0, s32 *, 0x18) + 1, M2C_FIELD(arg0, s32 *, 0x14)) >> 32);
    M2C_FIELD(arg0, s32 *, 0x1C) = M2C_FIELD(arg0, s32 *, 0x1C) - 1;
    func_02005df4(arg0);
    func_02007530(state);
    return 1;
}

s32 func_02006434(void *arg0, s32 arg1, s32 arg2) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    M2C_UNK func_02005df4(void *);
    unsigned long long func_020720f0(s32, s32);
    s32 state;

    state = func_0200751c();
    while (M2C_FIELD(arg0, s32 *, 0x14) <= M2C_FIELD(arg0, s32 *, 0x1C)) {
        if (!(arg2 & 1)) {
            func_02007530(state);
            return 0;
        }
        func_02005da4(arg0);
    }
    ((s32 *)M2C_FIELD(arg0, void **, 0x10))[M2C_FIELD(arg0,s32 *,0x18) = (s32)(func_020720f0(M2C_FIELD(arg0,s32 *,0x18)+M2C_FIELD(arg0,s32 *,0x14)-1,M2C_FIELD(arg0,s32 *,0x14))>>32)] = arg1;
    M2C_FIELD(arg0, s32 *, 0x1C) = M2C_FIELD(arg0, s32 *, 0x1C) + 1;
    func_02005df4((u8 *)arg0 + 8);
    func_02007530(state);
    return 1;
}

s32 func_020064d0(void *arg0, s32 *arg1, s32 arg2) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    s32 state;

    state = func_0200751c();
    while (M2C_FIELD(arg0, s32 *, 0x1C) == 0) {
        if (!(arg2 & 1)) {
            func_02007530(state);
            return 0;
        }
        func_02005da4((u8 *)arg0 + 8);
    }
    if (arg1 != NULL) {
        u32 idx = M2C_FIELD(arg0, u32 *, 0x18);
        s32 *base = M2C_FIELD(arg0,s32 **,0x10);
        *arg1 = base[idx];
    }
    func_02007530(state);
    return 1;
}

void func_0200654c(void *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = 0;
}

void func_02006564(void *arg0) {
    s32 func_0200751c();
    void func_02007530(s32);
    M2C_UNK func_02005da4(void *);
    void func_020066f4(void *, void *);
    extern M2C_UNK data_0212dca4;
    s32 state;
    void *head;
    u32 c;

    state = func_0200751c();
    head = M2C_FIELD(&data_0212dca4, void **, 0x4);
    while (1) {
        void *cur = M2C_FIELD(arg0, void **, 0x8);
        if (cur == NULL) {
            M2C_FIELD(arg0, void **, 0x8) = head;
            c = M2C_FIELD(arg0, u32 *, 0xC) + 1;
            M2C_FIELD(arg0, u32 *, 0xC) = c;
            func_020066f4(head, arg0);
            break;
        }
        if (cur == head) {
            c = M2C_FIELD(arg0, u32 *, 0xC) + 1;
            M2C_FIELD(arg0, u32 *, 0xC) = c;
            break;
        }
        M2C_FIELD(head, void **, 0x84) = arg0;
        func_02005da4(arg0);
        M2C_FIELD(head, void **, 0x84) = NULL;
    }
    func_02007530(state);
}

void func_020065e8(void *arg0) {
    s32 func_0200751c();
    void func_02007530(s32);
    M2C_UNK func_02005df4(void *);
    void func_02006718(void *, void *);
    extern M2C_UNK data_0212dca4;
    s32 state;
    void *head;
    u32 c;

    state = func_0200751c();
    head = M2C_FIELD(&data_0212dca4, void **, 0x4);
    if (M2C_FIELD(arg0, void **, 0x8) == head) {
        c = M2C_FIELD(arg0, u32 *, 0xC);
        c = c - 1;
        M2C_FIELD(arg0, u32 *, 0xC) = c;
        if (c == 0) {
            func_02006718(head, arg0);
            M2C_FIELD(arg0, void **, 0x8) = NULL;
            func_02005df4(arg0);
        }
    }
    func_02007530(state);
}

void func_02006644(void *arg0) {
    void *func_020057c8(void *);
    M2C_UNK func_02005df4();
    void *temp_r0;

    if (M2C_FIELD(arg0, s32 *, 0x88) == 0) {
        return;
    }
    do {
        temp_r0 = func_020057c8(arg0 + 0x88);
        M2C_FIELD(temp_r0, s32 *, 0xC) = 0;
        M2C_FIELD(temp_r0, s32 *, 8) = 0;
        func_02005df4();
    } while (M2C_FIELD(arg0, s32 *, 0x88) != 0);
}

s32 func_02006680(void *arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    void func_020066f4(void *, void *);
    extern M2C_UNK data_0212dca4;
    void *head;
    void *cur;
    s32 state;
    s32 r6;

    state = func_0200751c();
    head = M2C_FIELD(&data_0212dca4, void **, 0x4);
    cur = M2C_FIELD(arg0, void **, 0x8);
    if (cur == NULL) {
        u32 tmp;
        M2C_FIELD(arg0, void **, 0x8) = head;
        tmp = M2C_FIELD(arg0, u32 *, 0xC) + 1;
        M2C_FIELD(arg0, u32 *, 0xC) = tmp;
        func_020066f4(head, arg0);
        r6 = 1;
    } else if (cur == head) {
        M2C_FIELD(arg0, u32 *, 0xC) = M2C_FIELD(arg0, u32 *, 0xC) + 1;
        r6 = 1;
    } else {
        r6 = 0;
    }
    func_02007530(state);
    return r6;
}

void func_020066f4(void *arg0, void *arg1) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0x8C);
    if (temp_r2 == NULL) {
        M2C_FIELD(arg0, void **, 0x88) = arg1;
    } else {
        M2C_FIELD(temp_r2, void **, 0x10) = arg1;
    }
    M2C_FIELD(arg1, void **, 0x14) = temp_r2;
    M2C_FIELD(arg1, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, void **, 0x8C) = arg1;
}

void func_02006718(void *arg0, void *arg1) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg1, void **, 0x10);
    temp_r1 = M2C_FIELD(arg1, void **, 0x14);
    if (temp_r2 == NULL) {
        M2C_FIELD(arg0, void **, 0x8C) = temp_r1;
    } else {
        M2C_FIELD(temp_r2, void **, 0x14) = temp_r1;
    }
    if (temp_r1 == NULL) {
        M2C_FIELD(arg0, void **, 0x88) = temp_r2;
        return;
    }
    M2C_FIELD(temp_r1, void **, 0x10) = temp_r2;
}

#pragma opt_propagation off
void func_02006838(void) { u32 saved; u32 *io; io=(u32 *)0x04000000; saved=io[0x82]; io[0x82]=(u32)io; do {} while(*(volatile u16 *)((u8 *)io+6)); io[0x82]=saved; }
#pragma opt_propagation reset
void func_02006858(void) {
    M2C_UNK func_02004fe0();
    M2C_UNK func_02005254();
    M2C_UNK func_02005288();
    M2C_UNK func_02005968();
    void func_02006838(void);
void func_020068a0(void);
    M2C_UNK func_02006ce4();
    M2C_UNK func_020074c0();
    M2C_UNK func_020075b4();
    M2C_UNK func_020077cc();
    M2C_UNK func_02008bb8();
    M2C_UNK func_02009d34();
    M2C_UNK func_0200e2f8();
    M2C_UNK func_02010c14();
    M2C_UNK func_02018f3c();
    func_020068a0();
    func_02009d34();
    func_02005288();
    func_020069a4();
    func_02004fe0();
    func_02005254();
    func_02006ce4();
    func_02008bb8();
    func_020074c0();
    func_020077cc();
    func_02005968();
    func_020075b4();
    func_02018f3c();
    func_02010c14();
    func_0200e2f8();
    func_02006838();
}

void func_020068a0(void) {
    s32 func_02006a38(s32);
    void func_02006bc4(s32, s32);
    s32 func_02006b1c(s32);
    void func_02006bd8(s32, s32);
    extern M2C_UNK data_0212defc;

    if (M2C_FIELD(&data_0212defc, s32 *, 0) != 0) {
        return;
    }
    M2C_FIELD(&data_0212defc, s32 *, 0) = 1;
    func_02006bc4(0, func_02006a38(0));
    func_02006bd8(0, func_02006b1c(0));
    func_02006bd8(2, 0);
    func_02006bc4(2, 0);
    func_02006bc4(3, func_02006a38(3));
    func_02006bd8(3, func_02006b1c(3));
    func_02006bc4(4, func_02006a38(4));
    func_02006bd8(4, func_02006b1c(4));
    func_02006bc4(5, func_02006a38(5));
    func_02006bd8(5, func_02006b1c(5));
    func_02006bc4(6, func_02006a38(6));
    func_02006bd8(6, func_02006b1c(6));
}

s32 func_02006a10(s32 arg0) {
    u32 a = arg0 * 4;
    a = a + 0x02700000;
    a = a + 0x000FF000;
    return M2C_FIELD(a, s32 *, 0xDC4);
}

s32 func_02006a24(s32 arg0) {
    u32 a = arg0 * 4;
    a = a + 0x02700000;
    a = a + 0x000FF000;
    return M2C_FIELD(a, s32 *, 0xDA0);
}

s32 func_02006a38(s32 arg0) {
s32 func_020062bc(void); extern M2C_UNK data_0212defc,data_027e0000; extern char data_00000000[],data_00000800[];
switch(arg0) {
case 0:return 0x23e0000;
case 2: if(M2C_FIELD(&data_0212defc,s32 *,4)!=0) {if((func_020062bc()&3)==1)return 0;else goto mainram;} else return 0x2700000;
case 3:mainram:return 0x2000000;
case 4:{s32 b; u32 c,e; s32 a; a=(s32)&data_027e0000; b=(s32)data_00000000; c=(s32)data_00000800; e=a+0x3f80; c=e-c;
if((void *)b==0){if((u32)a<0x27e15e0U)a=0x27e15e0;return a;} if(b<0)return 0x27e15e0-b;return c-b;}
case 5:return 0x27ff680;case 6:return 0x37f8000;default:return 0;
}}

s32 func_02006b1c(s32 arg0) {
    s32 func_020062bc(void);
    extern M2C_UNK data_0212defc;

    switch (arg0) {
    case 0:
        return 0x0223c840;
    case 2:
        if (M2C_FIELD(&data_0212defc, s32 *, 4) == 0) {
            goto Lzero;
        }
        if ((func_020062bc() & 0x3) != 1) {
            goto Lone;
        }
        return 0;
    case 3:
        return 0x027e15e0;
    case 4:
        return 0x027ff000;
    case 5:
        return 0x037f8000;
    case 6:
    case 1:
    default:
        return 0;
    }
Lzero:
    return 0x023e0000;
Lone:
    return 0x01ffc780;
}

void func_02006bc4(s32 arg0, s32 arg1) {
    M2C_FIELD((((u32)arg0 * 4) + (s32)0x027FF000), s32 *, 0xDC4) = arg1;
}

void func_02006bd8(s32 arg0, s32 arg1) {
    M2C_FIELD(((arg0 * 4) + (unsigned)0x027FF000), s32 *, 0xDA0) = arg1;
}

s32 func_02006bec(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 temp_r2;
    s32 temp_r4;
    s32 temp;
    u32 temp_r5;

    temp_r0 = func_02006a24(arg0);
    if (temp_r0 == 0) {
        return 0;
    }
    temp_r2 = ~(arg2 - 1);
    temp_r4 = temp_r2 & ((temp_r0 + arg2) - 1);
    temp = temp_r4 + arg1;
    temp_r5 = temp_r2 & ((temp + arg2) - 1);
    if (temp_r5 > (u32)func_02006a10(arg0)) {
        return 0;
    }
    func_02006bd8(arg0, temp_r5);
    return temp_r4;
}

void func_02006c58(void) {
    extern M2C_UNK data_0212defc;
    M2C_FIELD(&data_0212defc, s32 *, 4) = 0;
}

M2C_UNK func_02006ce4(void) {
    extern u32 data_027ffd9c;
    extern u32 data_0212df04[3];
    void func_02006d54(void);
    u32 v;
    u32 *base;
    v = data_027ffd9c;
    if (v >= 0x2600000u) {
        if (v < 0x2800000u) {
            data_0212df04[0] = v;
        } else {
            data_0212df04[0] = 0;
        }
    }
    if (data_0212df04[0] == 0) {
        data_027ffd9c = (u32)func_02006d54;
        base = (u32 *)0x27e3000;
        base[0x3f7] = (u32)func_02006d54;
        data_0212df04[2] = 0;
    }
}

#pragma optimization_level 4
void func_02006dd8(void) {void func_02006dec(void);void func_02006e7c(void);func_02006dec();func_02006e7c();}
void func_02006ef8(s32 arg0) {
    extern u16 data_0212dfb0;
    u16 v = data_0212dfb0;
    data_0212dfb0 = v | (1u << arg0);
}

