/* 16 functions from 0x020232B8 to 0x02024260 (main), found by ds-decomp. */
#include "common.h"

M2C_UNK func_020232b8(void *p) {
 M2C_UNK func_0202321c(void *,void *,void *);
 M2C_UNK func_02008048(s32,s32,u32);
 extern M2C_UNK data_020fb048,data_020fb04c,data_020fb050;
 u8 buf[48];
 func_0202321c(buf,&data_020fb048,p);
 func_0202321c(buf+16,&data_020fb04c,p);
 func_0202321c(buf+32,&data_020fb050,p);
 return func_02008048((s32)buf,(s32)p,48);
}

M2C_UNK func_02023318(void *arg0) {
    M2C_UNK func_02025fc0();
    M2C_UNK func_02026014();
    M2C_UNK func_020260cc();
    M2C_UNK func_02025700();
    M2C_UNK func_02025748();
    M2C_UNK func_02025800();
    M2C_UNK func_02026164();
    u8 buf[0x18];
    s32 base;
    s32 w;
    s32 h;
    s32 t;
    s32 i;
    s32 j;
    s32 off;
    s32 bw;
    s32 bt;

    switch (M2C_FIELD(arg0, u16 *, 0x32)) {
    case 4:
        w = 0x10;
        h = 0x10;
        t = 0;
        break;
    case 5:
        w = 0x14;
        h = 0x10;
        t = 0;
        break;
    }
    i = 0;
    if ((w + h + t) * 2 > 0) {
        base = (s32)arg0 + 0x74;
        off = i;
        do {
            func_02025fc0((s32)arg0 + 0x348);
            buf[0] = (u8)(i + 0x41);
            for (j = 0; j < i + 1; j++) {
                func_02026014((s32)arg0 + 0x348, buf, 1);
            }
            func_02026014((s32)arg0 + 0x348, (s32)arg0, 0x30);
            func_02026014((s32)arg0 + 0x348, (s32)arg0 + 0x54, 0x20);
            func_02026014((s32)arg0 + 0x348, (s32)arg0 + 0x34, 0x20);
            func_020260cc((s32)arg0 + 0x348, buf + 1);
            func_02025700((s32)arg0 + 0x3fc);
            func_02025748((s32)arg0 + 0x3fc, (s32)arg0, 0x30);
            func_02025748((s32)arg0 + 0x3fc, buf + 1, 0x14);
            func_02025800((s32)arg0 + 0x3fc, base + off);
            off += 0x10;
            i++;
        } while (off < (w + h + t) * 2);
    }
    if (M2C_FIELD(arg0, u8 *, 0x454) != 0) {
        base = (s32)arg0 + 0x74;
        M2C_FIELD(arg0, s32 *, 0x1d4) = base;
        M2C_FIELD(arg0, s32 *, 0x1d8) = base + 2 * w;
        bw = base + w;
        M2C_FIELD(arg0, s32 *, 0xbc) = bw;
        bt = bw + w;
        M2C_FIELD(arg0, s32 *, 0xc0) = bt + h;
    } else {
        base = (s32)arg0 + 0x74;
        M2C_FIELD(arg0, s32 *, 0xbc) = base;
        M2C_FIELD(arg0, s32 *, 0xc0) = base + 2 * w;
        bw = base + w;
        M2C_FIELD(arg0, s32 *, 0x1d4) = bw;
        bt = bw + w;
        M2C_FIELD(arg0, s32 *, 0x1d8) = bt + h;
    }
    func_02026164((s32)arg0 + 0x1e0, M2C_FIELD(arg0, s32 *, 0x1d8), 0x10);
    func_02026164((s32)arg0 + 0xc8, M2C_FIELD(arg0, s32 *, 0xc0), 0x10);
}

void func_020234e4(void *arg0, M2C_UNK arg1) {
    M2C_UNK func_02021f1c(void *, M2C_UNK, M2C_UNK);
    M2C_UNK func_02022fdc(void *, M2C_UNK, s32);
    M2C_UNK func_020232b8(void *);
    M2C_UNK func_02023318(void *);
    func_02022fdc(arg0, arg1, M2C_FIELD(arg0, s32 *, 0x81C));
    func_020232b8(arg0);
    func_02021f1c(arg0, 0, 0);
    func_02023318(arg0);
    M2C_FIELD(arg0, s8 *, 0x455) = 5;
}

M2C_UNK func_02023520(void *arg0, void *arg1, s32 arg2) {
    M2C_UNK func_02025700();
    M2C_UNK func_02025748();
    M2C_UNK func_02025800();
    M2C_UNK func_02007f8c();
    extern u8 data_020fb054[], data_020fb05c[];
    u8 sp0[0x30];
    if ((M2C_FIELD(arg0, u8 *, 0x454) ^ arg2) != 0)
        func_02025748(arg0 + 0x3A4, data_020fb054, 4);
    else
        func_02025748(arg0 + 0x3A4, data_020fb05c, 4);
    func_02025748(arg0 + 0x3A4, arg0, 0x30);
    func_02007f8c(sp0, 0x36, 0x30);
    func_02025748(arg0 + 0x3A4, sp0, 0x30);
    func_02025800(arg0 + 0x3A4, arg1);
    func_02025700(arg0 + 0x3A4);
    func_02025748(arg0 + 0x3A4, arg0, 0x30);
    func_02007f8c(sp0, 0x5C, 0x30);
    func_02025748(arg0 + 0x3A4, sp0, 0x30);
    func_02025748(arg0 + 0x3A4, arg1, 0x10);
    func_02025800(arg0 + 0x3A4, arg1);
}

M2C_UNK func_020235fc(void *arg0, void *arg1, s32 arg2) {
M2C_UNK func_02026014(); M2C_UNK func_02007f8c(void *,s32,s32); M2C_UNK func_020260cc(void *,void *); M2C_UNK func_02025fc0(void *);
extern u8 data_020fb054[],data_020fb05c[];
u8 sp0[40];
if((M2C_FIELD(arg0,u8 *,0x454)^arg2)!=0) func_02026014(arg0+0x2ec,data_020fb054,4);
else func_02026014(arg0+0x2ec,data_020fb05c,4);
func_02026014(arg0+0x2ec,arg0,0x30);
func_02007f8c(sp0,0x36,0x28);
func_02026014(arg0+0x2ec,sp0,0x28);
func_020260cc(arg0+0x2ec,arg1);
func_02025fc0(arg0+0x2ec);
func_02026014(arg0+0x2ec,arg0,0x30);
func_02007f8c(sp0,0x5c,0x28);
func_02026014(arg0+0x2ec,sp0,0x28);
func_02026014(arg0+0x2ec,arg1,0x14);
func_020260cc(arg0+0x2ec,arg1);
}

void func_020236d8(void *p,void *q) {
 M2C_UNK func_02008048(s32,s32,u32);
 M2C_UNK func_02023520(void *,void *,s32);
 M2C_UNK func_020235fc(void *,void *,s32);
 s32 func_0206527c(void *,void *,s32);
 u8 buf[20];
 func_02008048((s32)p+0x3A4,(s32)p+0x3FC,0x58);
 func_02023520(p,buf,1);
 func_02008048((s32)p+0x3FC,(s32)p+0x3A4,0x58);
 if(func_0206527c(q,buf,16)) { M2C_FIELD(p,s8 *,0x455)=9;return;}
 func_02008048((s32)p+0x2EC,(s32)p+0x348,0x5C);
 func_020235fc(p,buf,1);
 func_02008048((s32)p+0x348,(s32)p+0x2EC,0x5C);
 if(func_0206527c(q+16,buf,20)) M2C_FIELD(p,s8 *,0x455)=9;
 else M2C_FIELD(p,s8 *,0x455)=6;
}

void func_02023798(u8 *arg0) {
    s32 var_r2;
    u8 *var_r0;
    u8 temp_r1;

    var_r0 = arg0;
    var_r2 = 8;
loop_1:
    var_r0 -= 1;
    temp_r1 = *var_r0 + 1;
    *var_r0 = temp_r1;
    if (temp_r1 != 0) {
        return;
    }
    var_r2 -= 1;
    if (var_r2 == 0) {
        return;
    }
    goto loop_1;
}

s32 func_020237bc(s32 x,s32 unused,s32 value) {
 M2C_UNK func_020261d8(s32);
 func_020261d8(x+0x1E0);return value;
}

s32 func_02023c08(s32 arg0, u32 arg1, M2C_UNK arg2) {
    M2C_UNK func_02008048(s32, s32, u32);
    s32 func_0201d59c(u32 *, M2C_UNK);
    M2C_UNK func_0201d67c(u32, M2C_UNK);
    u32 sp0;
    s32 temp_r0;
    s32 var_r7;
    u32 var_r6;

    var_r7 = arg0;
    var_r6 = arg1;
loop_1:
    temp_r0 = func_0201d59c(&sp0, arg2);
    if (sp0 == 0) {
        return -1;
    }
    if (sp0 > var_r6) {
        sp0 = var_r6;
    }
    func_02008048(temp_r0, var_r7, sp0);
    func_0201d67c(sp0, arg2);
    var_r6 -= sp0;
    var_r7 += sp0;
    if ((s32) var_r6 <= 0) {
        return 0;
    }
    goto loop_1;
}

void func_02023c74(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK func_02025748(s32, M2C_UNK, M2C_UNK);
    M2C_UNK func_02026014();
    func_02026014(arg0 + 0x2EC);
    func_02025748(arg0 + 0x3A4, arg1, arg2);
}

s32 func_02023f20(void *arg0) {
    M2C_UNK func_0201d59c(u32 *, M2C_UNK);
    M2C_UNK func_0201d67c(u32, M2C_UNK);
    void func_02022e78(u8 *, u8 *);
    void func_02023ca0(void *, void *);
    extern void *(*data_021372a4)(s32);
    extern void (*data_021372d0[])(void *);
    void *channel;
    u8 *temp;
    u8 *buf;
    u32 size;

    channel = M2C_FIELD(arg0, void **, 0xC);
    for (;;) {
        temp = (u8 *)func_0201d59c(&size, arg0);
        if (size == 0) {
            M2C_FIELD(channel, u8 *, 0x455) = 9;
            return 9;
        }
        if (size >= 5) {
            break;
        }
    }
    if (temp[0] == 0x80) {
        if (M2C_FIELD(channel, u8 *, 0x454) != 0 && M2C_FIELD(channel, u8 *, 0x455) == 0) {
            size = temp[1];
            func_0201d67c(2, arg0);
            buf = (u8 *)data_021372a4(size);
            if (buf == 0) {
                M2C_FIELD(channel, u8 *, 0x455) = 9;
                return 9;
            }
            if (func_02023c08((s32)buf, size, arg0) != 0 || buf[0] != 1) {
                M2C_FIELD(channel, u8 *, 0x455) = 9;
            } else {
                func_02022e78(channel, buf + 1);
            }
            func_02023c74(channel, buf, size);
            data_021372d0[0](buf);
        } else {
            M2C_FIELD(channel, u8 *, 0x455) = 9;
        }
    } else {
        size = (temp[3] << 8) + temp[4] + 5;
        if (size > 0x4805) {
            M2C_FIELD(channel, u8 *, 0x455) = 9;
            return 9;
        }
        buf = (u8 *)data_021372a4(size);
        if (buf == 0) {
            M2C_FIELD(channel, u8 *, 0x455) = 9;
            return 9;
        }
        if (func_02023c08((s32)buf, size, arg0) != 0) {
            data_021372d0[0](buf);
            M2C_FIELD(channel, u8 *, 0x455) = 9;
            return 9;
        }
        func_02023ca0(channel, buf);
    }
    return M2C_FIELD(channel, u8 *, 0x455);
}

void func_020240c0(u8 *dst,s32 len){
M2C_UNK func_02025fc0(void*);s32 func_0200751c(void);M2C_UNK func_02007530(s32);M2C_UNK func_02026014();void func_02026134(void*,void*);void func_020241f0(M2C_UNK*,s32);
extern s8 data_02138cc0;extern u64 data_021372f8[3];extern M2C_UNK data_02138e38;extern u8 data_02138e4b;
u8 ctx[92],hash[20];u32 seed; s32 out,index,state,j;u32 carry,total;u8 *p,*q;
if(!*(u8*)&data_02138cc0){data_021372f8[0]=data_021372f8[1]*data_021372f8[0]+data_021372f8[2];seed=data_021372f8[0]>>32;func_020241f0((M2C_UNK*)&seed,4);}
out=0;index=20;
while(out<len){
if(index==20){
func_02025fc0(ctx);state=func_0200751c();func_02026014(ctx,&data_02138e38,20);func_02026134(ctx,hash);
carry=1;j=19;p=&data_02138e4b;q=hash+19;
for(;j>=0;j--){total=carry+(*p+*q--);*p--=total;carry=total>>8;}
seed=total;func_02007530(state);index=0;
}
{u8 c=hash[index++];if(c)dst[out++]=c;}
}
}

void func_020241f0(M2C_UNK *p,s32 n) {
 s32 func_0200751c(void);
 M2C_UNK func_02007530(s32);
 M2C_UNK func_02025fc0(void *);
 M2C_UNK func_02026014();
 M2C_UNK func_020260cc(void *,void *);
 extern s8 data_02138cc0;
 extern M2C_UNK data_02138e38;
 u8 buf[0x5C];
 s32 state;
 func_02025fc0(buf);
 state=func_0200751c();
 func_02026014(buf,&data_02138e38,20);
 func_02026014(buf,p,n);
 func_020260cc(buf,&data_02138e38);
 func_02007530(state);
 data_02138cc0=1;
}

