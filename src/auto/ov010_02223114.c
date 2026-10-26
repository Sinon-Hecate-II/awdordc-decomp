/* 31 functions from 0x02223114 to 0x02224080 (ov010), found by ds-decomp. */
#include "common.h"

s32 func_ov010_02223114(void) {
    s32 func_ov010_02223420(void);
    s32 func_ov010_02223430(s32);
    M2C_UNK func_ov010_022223e8(void *, void *, s32);
    void *func_ov010_02223440(s32);
    M2C_UNK func_ov010_02223478(void *);
    M2C_UNK func_ov010_022235a4(void *, void *);
    M2C_UNK func_ov010_02223624(void *, void *, s32);
    s32 func_ov010_02223764(void *, u8);
    M2C_UNK func_ov010_02224ef8();
    s32 i;
    s32 type;
    s32 count;
    s32 id;
    void *head;
    void *item;
    void *old;
    head = (void *)func_ov010_02223420();
    if (head == NULL) return 0;
    id = M2C_FIELD(head, u8 *, 0x11);
    count = func_ov010_02223430(id);
    i = 0;
    if (count > 0) {
        do {
            item = func_ov010_02223440(id);
            type = M2C_FIELD(item, s32 *, 0xC);
            if (type >= 2) {
                func_ov010_022223e8(M2C_FIELD(item, void **, 0x474), (s8 *)item + 0x1C, M2C_FIELD(item, s32 *, 0x14));
            } else {
                old = M2C_FIELD(item, void **, 0x474);
                if (type == 1) func_ov010_022235a4(old, (s8 *)item + 0x1C);
                else func_ov010_02223624(old, (s8 *)item + 0x1C, M2C_FIELD(item, s32 *, 0x14));
            }
            M2C_FIELD(item, void **, 0x474) = (s8 *)item + 0x1C;
            func_ov010_02223478(item);
            if (func_ov010_02223764(item, M2C_FIELD(item, u8 *, 0x11)) < 0) func_ov010_02224ef8(item);
            i++;
        } while (i < count);
    }
    return count;
}

void func_ov010_022232e0(void) {
    extern s32 data_ov010_0222d878;
    extern s32 data_ov010_0222d880[];
    s32 i;
    i = 0;
    M2C_FIELD(&data_ov010_0222d878, s32 *, 4) = 0;
    data_ov010_0222d878 = 0;
    do {
        data_ov010_0222d880[i] = 0;
        i++;
    } while (i < 3);
}

void func_ov010_02223314(s32 arg0) {
    void *func_ov010_02223440(s32);
    M2C_UNK func_ov010_02223478(void *);
    M2C_UNK func_ov010_02224ef8();
    extern s32 data_ov010_0222d880[];
    void *item;
    item = func_ov010_02223440(arg0);
    if (item != NULL) {
        do {
            func_ov010_02223478(item);
            func_ov010_02224ef8(item);
            item = func_ov010_02223440(arg0);
        } while (item != NULL);
    }
    data_ov010_0222d880[arg0] = 0;
}

void func_ov010_0222335c(void) {
M2C_UNK func_ov010_02224ef8();
extern s32 data_ov010_0222d878;
extern s32 data_ov010_0222d880[];
void *p=(void *)data_ov010_0222d878;
s32 i;
while(p) { void *old=p; p=M2C_FIELD(p,void **,8); func_ov010_02224ef8(old); }
for(i=0;i<3;i++) data_ov010_0222d880[i]=0;
}

s32 func_ov010_022233ac(void *a) {
extern s32 data_ov010_0222d878;
extern s32 data_ov010_0222d880[];
if(data_ov010_0222d878==0) {
data_ov010_0222d878=(s32)a;
M2C_FIELD(a,s32 *,4)=0;
M2C_FIELD((void *)data_ov010_0222d878,s32 *,8)=0;
M2C_FIELD(&data_ov010_0222d878,s32 *,4)=data_ov010_0222d878;
} else {
M2C_FIELD(a,s32 *,4)=M2C_FIELD(&data_ov010_0222d878,s32 *,4);
M2C_FIELD(a,s32 *,8)=0;
M2C_FIELD((void *)M2C_FIELD(&data_ov010_0222d878,s32 *,4),void **,8)=a;
M2C_FIELD(&data_ov010_0222d878,void **,4)=a;
}
data_ov010_0222d880[M2C_FIELD(a,u8 *,0x11)]++;
return data_ov010_0222d880[M2C_FIELD(a,u8 *,0x11)];
}

s32 func_ov010_02223420(void) {
    extern s32 data_ov010_0222d878;
    return data_ov010_0222d878;
}

s32 func_ov010_02223430(s32 arg0) {
    extern s32 data_ov010_0222d880[];
    return data_ov010_0222d880[arg0];
}

void *func_ov010_02223440(s32 a) {
extern s32 data_ov010_0222d878;
void *p=(void *)data_ov010_0222d878;
while(p) {
if(M2C_FIELD(p,u8 *,0x11)==a) return p;
p=M2C_FIELD(p,void **,8);
}
return NULL;
}

s32 func_ov010_02223478(void *a) {
extern s32 data_ov010_0222d878;
extern s32 data_ov010_0222d880[];
if(M2C_FIELD(a,void **,4)) M2C_FIELD(M2C_FIELD(a,void **,4),void **,8)=M2C_FIELD(a,void **,8);
else { void *p8=M2C_FIELD(a,void **,8);
data_ov010_0222d878=(s32)p8;
if(p8) M2C_FIELD(p8,s32 *,4)=0; }
if(M2C_FIELD(a,void **,8)) M2C_FIELD(M2C_FIELD(a,void **,8),void **,4)=M2C_FIELD(a,void **,4);
else { void *p4=M2C_FIELD(a,void **,4);
M2C_FIELD(&data_ov010_0222d878,s32 *,4)=(s32)p4;
if(p4) M2C_FIELD(p4,s32 *,8)=0; }
data_ov010_0222d880[M2C_FIELD(a,u8 *,0x11)]--;
return data_ov010_0222d880[M2C_FIELD(a,u8 *,0x11)];
}

void func_ov010_022234f8(u8 *out,s16 *in,u32 n) {
extern s32 data_ov010_0222c004[];
u32 i; s32 x,mask,seg; s32 *table;
for(i=0;i<n;i++) {
x=in[i]>>2; table=data_ov010_0222c004;
if(x<0) {mask=0x7f;x=-x;} else mask=0xff;
if(x>0x1fdf) x=0x1fdf;
for(seg=0;seg<8;seg++) if(x+0x21<=*table++) break;
if(seg>=8) out[i]=mask^0x7f;
else out[i]=(((x+0x21)>>(seg+1))&15 | seg<<4)^mask;
}
}

void func_ov010_022235f8(s8 *out,s16 *in,u32 n) {
u32 i; for(i=0;i<n;i++) out[i]=in[i]>>8;
}

void func_ov010_02223654(s32 arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern s32 data_ov010_0222d88c;
    extern s32 data_ov010_0222d890[];
    extern s32 data_ov010_0222d89c[];
    extern s32 data_ov010_0222d8a8[];
    data_ov010_0222d88c = func_0200751c();
    data_ov010_0222d8a8[arg0] = 0;
    data_ov010_0222d89c[arg0] = 0;
    data_ov010_0222d890[arg0] = 0;
    func_02007530(data_ov010_0222d88c);
}

void func_ov010_0222369c(s32 arg0) {
    void *func_ov010_02223878(s32);
    M2C_UNK func_ov010_022238c0(s32);
    M2C_UNK func_ov010_02224ef8(void *);
    extern s32 data_ov010_0222d89c[];
    void *item;
    item = func_ov010_02223878(arg0);
    if (item != NULL) {
        do {
            func_ov010_022238c0(arg0);
            func_ov010_02224ef8(item);
            item = func_ov010_02223878(arg0);
        } while (item != NULL);
    }
    data_ov010_0222d89c[arg0] = 0;
}

void func_ov010_022236e4(void) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    M2C_UNK func_ov010_02224ef8(void *);
    extern s32 data_ov010_0222d88c;
    extern s32 data_ov010_0222d890[];
    extern s32 data_ov010_0222d89c[];
    s32 i;
    void *node;
    void *next;
    node = (void *)func_0200751c();
    i = 0;
    data_ov010_0222d88c = (s32)node;
    for (; i < 3; i++) {
        node = (void *)data_ov010_0222d890[i];
        while (node != NULL) {
            next = M2C_FIELD(node, void **, 8);
            data_ov010_0222d890[i] = (s32)next;
            if (next != NULL) {
                M2C_FIELD(next, s32 *, 4) = 0;
            }
            func_ov010_02224ef8(node);
            node = (void *)data_ov010_0222d890[i];
        }
        data_ov010_0222d89c[i] = 0;
    }
    func_02007530(data_ov010_0222d88c);
}

void *func_ov010_02223878(s32 arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern s32 data_ov010_0222d88c;
    extern s32 data_ov010_0222d890[];
    data_ov010_0222d88c = func_0200751c();
    if (data_ov010_0222d890[arg0] != 0) {
        func_02007530(data_ov010_0222d88c);
        return (void *)data_ov010_0222d890[arg0];
    }
    func_02007530(data_ov010_0222d88c);
    return NULL;
}

s32 func_ov010_022238c0(s32 arg0) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern s32 data_ov010_0222d88c;
    extern s32 data_ov010_0222d890[];
    extern s32 data_ov010_0222d89c[];
    void *temp;
    data_ov010_0222d88c = func_0200751c();
    temp = (void *)data_ov010_0222d890[arg0];
    if (temp != NULL) {
        void *next = M2C_FIELD(temp, void **, 8);
        data_ov010_0222d890[arg0] = (s32)next;
        data_ov010_0222d89c[arg0] = data_ov010_0222d89c[arg0] - 1;
        if (next != NULL) {
            M2C_FIELD(next, s32 *, 4) = 0;
        }
    }
    func_02007530(data_ov010_0222d88c);
    return data_ov010_0222d89c[arg0];
}

s32 func_ov010_0222392c(s32 arg0) {
    extern s32 data_ov010_0222d89c[];
    return data_ov010_0222d89c[arg0];
}

void func_ov010_0222393c(void *arg0, s32 arg1, s32 arg2) {
    M2C_UNK func_02007f8c(void *, M2C_UNK, M2C_UNK);
    func_02007f8c(arg0, 0, 0x28);
    M2C_FIELD(arg0, s32 *, 4) = 0x134DF;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = arg1;
    M2C_FIELD(arg0, s32 *, 0x38) = arg2;
    M2C_FIELD(arg0, s32 *, 0x7C) = 0;
    M2C_FIELD(arg0, s32 *, 0x80) = 0;
    M2C_FIELD(arg0, s32 *, 0x84) = 0;
    M2C_FIELD(arg0, s32 *, 0x88) = 0;
    M2C_FIELD(arg0, s32 *, 0x8C) = 0x134DF;
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
    M2C_FIELD(arg0, s32 *, 0x4C) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    M2C_FIELD(arg0, s32 *, 0x50) = 0;
    M2C_FIELD(arg0, s32 *, 0x54) = 0;
    M2C_FIELD(arg0, s32 *, 0x58) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 1;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
}

void func_ov010_022239c8(void *arg0) {
    M2C_UNK func_ov010_02224ef8();
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        func_ov010_02224ef8();
        M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    }
    M2C_FIELD(arg0, s32 *, 0x38) = -1;
}

void func_ov010_022239f4(void *arg0, s32 arg1) {
    M2C_UNK func_ov010_022238c0(s32);
    if (M2C_FIELD(arg0, s32 *, 0x3C) != 0) {
        func_ov010_02224ef8();
    }
    M2C_FIELD(arg0, s32 *, 0x3C) = arg1;
    func_ov010_022238c0(M2C_FIELD(arg0, s32 *, 0x34));
}

void func_ov010_02223a20(void *arg0, s16 arg1) {
    M2C_FIELD(arg0, s16 *, 0x68) = arg1;
    M2C_FIELD(arg0, s32 *, 0x64) = 0x10001;
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
}

s32 func_ov010_02223ec8(s32 a) {
s32 func_ov010_022243b0(s32);
extern s32 data_ov010_0222edc0;
s32 state=M2C_FIELD(&data_ov010_0222edc0,s32 *,0x10);
if(state==0 || state==2) return 0;
return func_ov010_022243b0(a);
}

s32 func_ov010_02223ef0(void *arg0) {
    extern M2C_UNK data_ov010_0222d8b4;
    extern M2C_UNK data_ov010_0222d8f0;
    extern M2C_UNK data_ov010_0222edc0;
    void *var_ip;
    void *var_lr;

    var_ip = NULL;
    var_lr = M2C_FIELD(&data_ov010_0222d8b4, void **, 0x14);
    if (arg0 == NULL) {
        return 0;
    }
    if (M2C_FIELD(&data_ov010_0222edc0, s32 *, 0x10) == 2) {
        if (arg0 == &data_ov010_0222d8f0) {
            M2C_FIELD(&data_ov010_0222d8b4, s32 *, 0x3C) = 0;
        }
        return 1;
    }
    while (var_lr != NULL) {
        if (var_lr == arg0) {
            void *temp_r2;
            M2C_FIELD(arg0, s32 *, 0) = 0;
            if (var_ip != NULL) {
                M2C_FIELD(var_ip, void **, 0x14) = M2C_FIELD(arg0, void **, 0x14);
            } else {
                temp_r2 = M2C_FIELD(var_lr, void **, 0x14);
                if (temp_r2 != NULL) {
                    M2C_FIELD(&data_ov010_0222d8b4, void **, 0x14) = temp_r2;
                } else {
                    M2C_FIELD(&data_ov010_0222d8b4, void **, 0x14) = NULL;
                }
            }
            M2C_FIELD(arg0, void **, 0x14) = M2C_FIELD(&data_ov010_0222d8b4, void **, 0x10);
            M2C_FIELD(&data_ov010_0222d8b4, void **, 0x10) = arg0;
            return 1;
        }
        var_ip = var_lr;
        var_lr = M2C_FIELD(var_lr, void **, 0x14);
    }
    return 0;
}

s32 func_ov010_02223fac(void *arg0, s32 arg1, void *arg2, u32 arg3) {
    M2C_UNK func_ov010_02224700(void *, void *, u8);
    s32 func_ov010_02224820(void *);
    s32 func_ov010_0222486c(void *, void *);
    extern M2C_UNK data_ov010_0222edc0;

    if (arg0 == NULL) {
        return -1;
    }
    if (arg3 < 0x10) {
        return -1;
    }
    if (M2C_FIELD(&data_ov010_0222edc0, s32 *, 0xC) == 1) {
        return -3;
    }
    if ((arg1 < 0) || (arg1 >= 5)) {
        return -3;
    }
    M2C_FIELD(arg2, u8 *, 4) = 0xFF;
    func_ov010_02224700(arg0, arg2, (u8) arg1);
    if (func_ov010_0222486c(arg0, arg2) == 0) {
        return -3;
    }
    if ((M2C_FIELD(&data_ov010_0222edc0, s32 *, 0x10) == 1) && (arg1 == 0)) {
        if (func_ov010_02224820(arg0) == 0) {
            return -3;
        }
    }
    return 0;
}

s32 func_ov010_0222405c(s32 arg0, s32 arg1) {
    s32 func_ov010_0222441c(s32, s32);
    extern M2C_UNK data_ov010_0222edc0;
    if (M2C_FIELD(&data_ov010_0222edc0, s32 *, 0x10) == 2) return -3;
    return func_ov010_0222441c(arg0, arg1);
}

