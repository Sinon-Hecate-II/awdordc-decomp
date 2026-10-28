/* 11 functions from 0x0204C7FC to 0x0204D5C0 (main), found by ds-decomp. */
#include "common.h"
static inline s32 char_outside(s32 c) { s32 bad=1; if(c>=0) { if(c<128)bad=0; } return bad; }
static inline s32 char_space(s32 c) { extern u16 data_020ead40[]; return char_outside(c) ? 0 : (data_020ead40[c] & 256); }

void func_0204c7fc(void *arg0) {
    s32 func_020492ec(s32, s32);
    M2C_UNK func_0204932c(s32, s32);
    s32 func_020496a4(s32, s32, s32);
    s32 func_02049740(s32, void *, s32);
    s32 func_02049900(s32);
    s32 PollOneFd(s32, s32 *, s32, s32);
    M2C_UNK func_0204a518(void *, s32, s32);
    extern s32 data_020fd010;
    extern s32 data_0213dca8;
    extern u16 data_0213dca4;
    u8 sp8[8];
    s32 sp4;
    s32 sp0;
    s32 temp_r0;
    s32 var_r1;
    u16 t2, t3;

    if (M2C_FIELD(arg0, s32 *, 0x48) == -1) {
        temp_r0 = func_020496a4(2, 1, 0);
        M2C_FIELD(arg0, s32 *, 0x48) = temp_r0;
        if (temp_r0 == -1) {
            M2C_FIELD(arg0, s32 *, 0xFC) = 1;
            M2C_FIELD(arg0, s32 *, 0x38) = 5;
            M2C_FIELD(arg0, s32 *, 0x4C) = func_02049900(M2C_FIELD(arg0, s32 *, 0x48));
            return;
        }
        if (func_020492ec(temp_r0, 0) == 0) {
            M2C_FIELD(arg0, s32 *, 0xFC) = 1;
            M2C_FIELD(arg0, s32 *, 0x38) = 5;
            M2C_FIELD(arg0, s32 *, 0x4C) = func_02049900(M2C_FIELD(arg0, s32 *, 0x48));
            return;
        }
        if (M2C_FIELD(arg0, s32 *, 0x134) != 0) {
            func_0204932c(M2C_FIELD(arg0, s32 *, 0x48), data_020fd010);
        }
        M2C_FIELD(sp8, s32 *, 0) = 0;
        M2C_FIELD(sp8, s32 *, 4) = 0;
        sp8[1] = 2;
        if (M2C_FIELD(arg0, s32 *, 0x15C) != 0) {
            t2 = M2C_FIELD(arg0, u16 *, 0x160);
            M2C_FIELD(sp8, u16 *, 2) = (u8)((s32)t2 >> 8) | ((t2 << 8) & 0xFF00);
        } else if (data_0213dca8 != 0) {
            M2C_FIELD(sp8, u16 *, 2) = (u8)((s32)data_0213dca4 >> 8) | ((data_0213dca4 << 8) & 0xFF00);
        } else {
            t3 = M2C_FIELD(arg0, u16 *, 0x20);
            M2C_FIELD(sp8, u16 *, 2) = (u8)((s32)t3 >> 8) | ((t3 << 8) & 0xFF00);
        }
        M2C_FIELD(sp8, s32 *, 4) = M2C_FIELD(arg0, s32 *, 0x1C);
        if (func_02049740(M2C_FIELD(arg0, s32 *, 0x48), sp8, 8) == -1) {
            temp_r0 = func_02049900(M2C_FIELD(arg0, s32 *, 0x48));
            if (temp_r0 != -6 && temp_r0 != -26 && temp_r0 != -76) {
                M2C_FIELD(arg0, s32 *, 0xFC) = 1;
                M2C_FIELD(arg0, s32 *, 0x38) = 6;
                M2C_FIELD(arg0, s32 *, 0x4C) = temp_r0;
                return;
            }
        }
    }
    var_r1 = (PollOneFd(M2C_FIELD(arg0, s32 *, 0x48), (s32 *)0, &sp4, &sp0) > 0) ? 1 : 0;
    if (var_r1 == -1 || sp0 != 0) {
        M2C_FIELD(arg0, s32 *, 0xFC) = 1;
        M2C_FIELD(arg0, s32 *, 0x38) = 6;
        if (var_r1 != 0) {
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x4C) = func_02049900(M2C_FIELD(arg0, s32 *, 0x48));
        return;
    }
    if (sp4 == 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = 2;
    func_0204a518(arg0, 0, 0);
}

void func_0204ca4c(void *a){
s32 func_02068eac(void *,void *,s32);M2C_UNK func_0204a518(void *,s32,s32);s32 func_0204a30c(void *);void func_0204a2c8(void *);M2C_UNK func_0204a740(void *,void *,s32 *);
M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
extern M2C_UNK data_020fd88c,data_020fd8a0,data_020fd864,data_020fd804;
u8 buf[1024];s32 size;
if(!M2C_FIELD(a,s32 *,0x168)){
if(!func_02068eac(M2C_FIELD(a,void **,0x14),&data_020fd88c,8)){
M2C_FIELD(a,s32 *,0xfc)=1;M2C_FIELD(a,s32 *,0x38)=17;return;
}
M2C_FIELD(a,s32 *,0x10)=3;func_0204a518(a,0,0);return;
}
if(M2C_FIELD(a,s32 *,0x170)){M2C_FIELD(a,s32 *,0x10)=3;func_0204a518(a,0,0);return;}
if(!M2C_FIELD(a,s32 *,0x16c)&& M2C_FIELD(a,s32 (**)(void *,void *),0x174)(a,(u8 *)a+0x164)==3){
func_020640a8(&data_020fd8a0,&data_020fd864,&data_020fd804,0x146);return;
}
if(M2C_FIELD(a,s32 *,0x60)>=M2C_FIELD(a,s32 *,0x5c))goto done;
if(!func_0204a30c(a))return;
if(M2C_FIELD(a,s32 *,0x60)<M2C_FIELD(a,s32 *,0x5c))return;
func_0204a2c8((u8 *)a+0x50);
done:size=1024;func_0204a740(a,buf,&size);
}

void func_0204cbac(void *arg0) {
  s32 func_02049ef4(void *, void *, s32);
  s32 func_0204a1b0(M2C_UNK, M2C_UNK *, M2C_UNK *);
  M2C_UNK func_0204a230(s32, s32);
  void func_0204a290(s32, s32);
  s32 func_0204a30c(void *);
  void func_0204a2c8(void *);
  M2C_UNK *func_0204b6ac(void *);
  M2C_UNK func_0204a518(void *, s32, s32);
  u8 *func_02068fdc(s32, M2C_UNK *);
  M2C_UNK func_020675e4(void *, void *, s32);
  extern M2C_UNK data_020fd8a4, data_020fd8ac, data_020fd8b4, data_020fd8bc;
  extern M2C_UNK data_020fd8c8, data_020fd8d0, data_020fd8dc, data_020fd8d8;
  extern M2C_UNK data_020fd8e8, data_020fd8f8, data_020fd904, data_020fd910;
  extern M2C_UNK data_020fd918, data_020fd91c, data_020fd92c;
  extern s32 data_0213dca8;
  u8 *buf;
  u8 tmp[16];
  s32 temp_r0;
  if (M2C_FIELD(arg0, s32 *, 0x5c) == 0) {
    buf = (u8 *)arg0 + 0x50;
    func_02049ef4(buf,
      M2C_FIELD(arg0, s32 *, 0x13c) ? (void *)&data_020fd8a4 :
        (M2C_FIELD(arg0, s32 *, 0xc) == 3 ? (void *)&data_020fd8ac : (void *)&data_020fd8b4), 0);
    if (M2C_FIELD(arg0, s32 *, 0x15c) || data_0213dca8)
      func_02049ef4(buf, (void *)M2C_FIELD(arg0, s32 *, 0x14), 0);
    else
      func_02049ef4(buf, (void *)M2C_FIELD(arg0, s32 *, 0x24), 0);
    func_02049ef4(buf, &data_020fd8bc, 0);
    if (M2C_FIELD(arg0, u16 *, 0x20) == 0x50)
      func_0204a1b0((M2C_UNK)buf, &data_020fd8c8, (M2C_UNK *)M2C_FIELD(arg0, s32 *, 0x18));
    else {
      func_02049ef4(buf, &data_020fd8d0, 0);
      func_02049ef4(buf, (void *)M2C_FIELD(arg0, s32 *, 0x18), 0);
    }
    func_0204a230((s32)buf, 0x3a);
    func_0204a290((s32)buf, M2C_FIELD(arg0, u16 *, 0x20));
    func_02049ef4(buf, &data_020fd8d8, 2);
    if (!M2C_FIELD(arg0, s32 *, 0x28) ||
        !func_02068fdc(M2C_FIELD(arg0, s32 *, 0x28), &data_020fd8dc))
      func_0204a1b0((M2C_UNK)buf, &data_020fd8dc, &data_020fd8e8);
    if (M2C_FIELD(arg0, s32 *, 0x34))
      func_0204a1b0((M2C_UNK)buf, &data_020fd8f8, &data_020fd904);
    else
      func_0204a1b0((M2C_UNK)buf, &data_020fd8f8, &data_020fd910);
    if (M2C_FIELD(arg0, s32 *, 0x13c)) {
      func_020675e4(tmp, &data_020fd918, M2C_FIELD(arg0, s32 *, 0x14c));
      func_0204a1b0((M2C_UNK)buf, &data_020fd91c, (M2C_UNK *)tmp);
    }
    func_0204a1b0((M2C_UNK)buf, &data_020fd92c, (M2C_UNK *)func_0204b6ac(arg0));
    if (M2C_FIELD(arg0, s32 *, 0x28))
      func_02049ef4(buf, (void *)M2C_FIELD(arg0, s32 *, 0x28), 0);
    func_02049ef4(buf, &data_020fd8d8, 2);
    if (buf != (u8 *)arg0 + 0x50)
      func_02049ef4((u8 *)arg0 + 0x50, (void *)M2C_FIELD(buf, s32 *, 4), M2C_FIELD(buf, s32 *, 0xc));
  }
  if (func_0204a30c(arg0) == 0) return;
  if (M2C_FIELD(arg0, s32 *, 0x60) < M2C_FIELD(arg0, s32 *, 0x5c)) return;
  func_0204a2c8((u8 *)arg0 + 0x50);
  temp_r0 = M2C_FIELD(arg0, s32 *, 0x13c) ? 4 : 5;
  M2C_FIELD(arg0, s32 *, 0x10) = temp_r0;
  func_0204a518(arg0, 0, 0);
}

void func_0204ce20(void *arg0) {
    M2C_UNK func_0204a594(void *);
    M2C_UNK func_0204bc64(void *);
    s32 func_0204c300(void *);
 extern M2C_UNK data_020fd864;
 M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
    extern M2C_UNK data_020fd7d0;
    extern M2C_UNK data_020fd93c;
    s32 temp_r0;
    s32 temp_r5;

    temp_r5 = M2C_FIELD(arg0, s32 *, 0x148);
    temp_r0 = func_0204c300(arg0);
    if (temp_r0 == 0) {
        if ((M2C_FIELD(arg0, s32 *, 0xFC) != 0) && (M2C_FIELD(arg0, s32 *, 0x38) != 0)) {

        } else {
            func_020640a8(&data_020fd93c, &data_020fd864, &data_020fd7d0, 0x200);
        }
        func_0204bc64(arg0);
        return;
    }
    if (temp_r5 != M2C_FIELD(arg0, s32 *, 0x148)) {
        func_0204a594(arg0);
    }
    if (temp_r0 != 1) {
        return;
    }
    func_0204bc64(arg0);
    M2C_FIELD(arg0, s32 *, 0x10) = 5;
    func_0204a518(arg0, 0, 0);
}

void func_0204ceb8(void *arg0) {
    s32 PollOneFd(s32, s32 *, M2C_UNK, M2C_UNK);
    s32 func_02049900(s32);
    M2C_UNK func_0204a518(void *, M2C_UNK, M2C_UNK);
    s32 sp0;

    if (PollOneFd(M2C_FIELD(arg0, s32 *, 0x48), &sp0, 0, 0) == -1) {
        M2C_FIELD(arg0, s32 *, 0xFC) = 1;
        M2C_FIELD(arg0, s32 *, 0x38) = 5;
        M2C_FIELD(arg0, s32 *, 0x4C) = func_02049900(M2C_FIELD(arg0, s32 *, 0x48));
        return;
    }
    if (sp0 == 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x10) = 6;
    func_0204a518(arg0, 0, 0);
}

s32 func_0204cf38(void *a){
extern M2C_UNK data_020fd858,data_020fd864,data_020fd7e0,data_020fd968,data_020fd988;
extern u16 data_020ead40[];
M2C_UNK func_020640a8(M2C_UNK *,M2C_UNK *,M2C_UNK *,s32);
s32 func_02068adc(void *,M2C_UNK *,...);
s32 major,minor,status,pos,n,ch;
if(!a)func_020640a8(&data_020fd858,&data_020fd864,&data_020fd7e0,590);
if(M2C_FIELD(a,s32 *,128)<=0)func_020640a8(&data_020fd968,&data_020fd864,&data_020fd7e0,591);
n=func_02068adc(M2C_FIELD(a,void **,120),&data_020fd988,&major,&minor,&status,&pos);
while((ch=M2C_FIELD(M2C_FIELD(a,void **,120),s8 *,pos))!=0 && char_space(ch))pos++;
if(n!=3 || major<1 || status<100 || status>=600){
M2C_FIELD(a,s32 *,252)=1;M2C_FIELD(a,s32 *,56)=7;return 0;
}
M2C_FIELD(a,s32 *,228)=major;M2C_FIELD(a,s32 *,232)=minor;M2C_FIELD(a,s32 *,236)=status;M2C_FIELD(a,s32 *,240)=pos;return 1;
}

void func_0204d084(void *a){
s32 func_0204a740(void *,void *,s32 *);s32 func_02049ef4();s32 func_0204cf38(void *);
s32 func_02049900(s32);u8 *func_02068fdc(s32,M2C_UNK *);
extern M2C_UNK data_020fd8d8;
u8 buf[1024];s32 len=1024; s32 n,off;u8 *p;
n=func_0204a740(a,buf,&len);
if(n==3)return;
if(n==1 && M2C_FIELD(a,s32 *,132)==M2C_FIELD(a,s32 *,128))return;
if(n==0 && !func_02049ef4((u8 *)a+116,buf,len))return;
p=func_02068fdc(M2C_FIELD(a,s32 *,120),&data_020fd8d8);
if(p){
*p=0;off=p-M2C_FIELD(a,u8 **,120);
M2C_FIELD(a,s32 *,248)=off+1;
if(!func_0204cf38(a))return;
M2C_FIELD(a,s32 *,132)=off+2;
M2C_FIELD(a,s32 *,16)=7;
func_0204a518(a,0,0);return;
}
if(n!=2)return;
M2C_FIELD(a,s32 *,252)=1;
M2C_FIELD(a,s32 *,56)=7;
M2C_FIELD(a,s32 *,76)=func_02049900(M2C_FIELD(a,s32 *,72));
}

s32 func_0204d1ac(void *arg0,s32 arg1,s32 arg2) {
 s32 func_02049ef4();
 M2C_UNK func_0204a518(void *,s32,s32);
 s32 a=0,b=0;
 s32 c=M2C_FIELD(arg0,s32 *,0x100)+arg2;
 M2C_FIELD(arg0,s32 *,0x100)=c;
 if(c==M2C_FIELD(arg0,s32 *,0x104)||M2C_FIELD(arg0,s32 *,0x130)) M2C_FIELD(arg0,s32 *,0xFC)=1;
 if(M2C_FIELD(arg0,s32 *,0xC)==0) {
 if(!func_02049ef4(arg0+0xBC)) return 0;
 a=M2C_FIELD(arg0,s32 *,0xC0); b=M2C_FIELD(arg0,s32 *,0xC8);
 } else if(M2C_FIELD(arg0,s32 *,0xC)==1) {
 if(arg2) { M2C_FIELD(arg0,s32 *,0xFC)=1; M2C_FIELD(arg0,s32 *,0x38)=13; return 0; }
 a=arg1;b=arg2;
 } else if(M2C_FIELD(arg0,s32 *,0xC)==2) {a=arg1;b=arg2;}
 func_0204a518(arg0,a,b); return 1;
}

s32 func_0204d26c(void *arg0) {
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    s32 func_02068adc(void *, M2C_UNK *, ...);
    extern M2C_UNK data_020fd7f0;
    extern M2C_UNK data_020fd864;
    extern M2C_UNK data_020fd998;
    extern M2C_UNK data_020fd99c;
    s32 sp0;

    if (M2C_FIELD(arg0, s32 *, 0x120) == 0) {
        func_020640a8(&data_020fd998, &data_020fd864, &data_020fd7f0, 0x321);
    }
    if (func_02068adc(arg0 + 0x114, &data_020fd99c, &sp0) != 1) {
        return -1;
    }
    return sp0;
}

void func_0204d2d0(void *p,void *src,s32 n) {
extern M2C_UNK data_020fd858,data_020fd864,data_020fd838,data_020fd9a0,data_020fd9a8;
s32 left;
if(!p)func_020640a8(&data_020fd858,&data_020fd864,&data_020fd838,0x333);
if(!src)func_020640a8(&data_020fd9a0,&data_020fd864,&data_020fd838,0x334);
if(n<0)func_020640a8(&data_020fd9a8,&data_020fd864,&data_020fd838,0x335);
if(!n)return;
if(M2C_FIELD(p,s32 *,0x120)>=10)return;
left=10-M2C_FIELD(p,s32 *,0x120);
if(left>=n)left=n;
func_020651a4((u8 *)p+0x114+M2C_FIELD(p,s32 *,0x120),src,left);
M2C_FIELD(p,s32 *,0x120)+=left;
*((u8 *)p+M2C_FIELD(p,s32 *,0x120)+0x114)=0;
}

s32 func_0204d39c(void *p, void *src, s32 n) {
    s8 *func_02068ee0(s8 *, s32);
    void func_0204d2d0(void *, void *, s32);
    s32 func_0204d26c(void *);
    s32 func_0204d1ac(void *, s32, s32);
    M2C_UNK func_020640a8(M2C_UNK *, M2C_UNK *, M2C_UNK *, s32);
    extern M2C_UNK data_020fd858, data_020fd864, data_020fd81c, data_020fd9a0, data_020fd9b4, data_020fd8a0;

    u8 *q;
    s32 left;
    if (!p) func_020640a8(&data_020fd858, &data_020fd864, &data_020fd81c, 0x35d);
    if (!src) func_020640a8(&data_020fd9a0, &data_020fd864, &data_020fd81c, 0x35e);
    if (n <= 0) func_020640a8(&data_020fd9b4, &data_020fd864, &data_020fd81c, 0x35f);
    if (!M2C_FIELD(p, s32 *, 0x110)) return func_0204d1ac(p, (s32)src, n);
    if (n <= 0) return 1;

    q = (u8 *)src;
    left = n;

    while (left > 0) {
        s32 state = M2C_FIELD(p, s32 *, 0x128);
        if (state == 0) {
            s8 *found = func_02068ee0((s8 *)q, 10);
            if (found) {
                func_0204d2d0(p, q, (s32)(found - (s8 *)q));
                left -= (s32)((u8 *)(found + 1) - q);
                q = (u8 *)(found + 1);
                {
                    s32 val = func_0204d26c(p);
                    M2C_FIELD(p, s32 *, 0x124) = val;
                    if (val == -1) {
                        M2C_FIELD(p, s32 *, 0xFC) = 1;
                        M2C_FIELD(p, s32 *, 0x38) = 7;
                        return 0;
                    }
                    if (val == 0) M2C_FIELD(p, s32 *, 0x128) = 3;
                    else M2C_FIELD(p, s32 *, 0x128) = 1;
                }
            } else {
                func_0204d2d0(p, q, left);
                return 1;
            }
        } else if (state == 1) {
            s32 t = M2C_FIELD(p, s32 *, 0x124);
            if (t >= left) t = left;
            if (!func_0204d1ac(p, (s32)q, t)) return 0;
            q += t;
            M2C_FIELD(p, s32 *, 0x124) = M2C_FIELD(p, s32 *, 0x124) - t;
            left -= t;
            if (M2C_FIELD(p, s32 *, 0x124) == 0) M2C_FIELD(p, s32 *, 0x128) = 2;
        } else if (state == 2) {
            s8 *found = func_02068ee0((s8 *)q, 10);
            if (!found) return 1;
            *((u8 *)p + 0x114) = 0;
            M2C_FIELD(p, s32 *, 0x120) = 0;
            {
                s32 seg = (s32)((u8 *)(found + 1) - q);
                M2C_FIELD(p, s32 *, 0x124) = 0;
                q = (u8 *)(found + 1);
                M2C_FIELD(p, s32 *, 0x128) = 0;
                left -= seg;
            }
        } else if (state == 3) {
            M2C_FIELD(p, s32 *, 0xFC) = 1;
            return 1;
        } else {
            func_020640a8(&data_020fd8a0, &data_020fd864, &data_020fd81c, 0x3e3);
            return 0;
        }
    }
    return 1;
}

