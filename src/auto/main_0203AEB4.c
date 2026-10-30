/* 23 functions from 0x0203AEB4 to 0x0203BE54 (main), found by ds-decomp. */
#include "common.h"

s32 func_0203aeb4(s32 a) {
 extern M2C_UNK data_0213d38c; s32 func_0203ae6c(s32);
 s32 i;
 if(!M2C_FIELD(&data_0213d38c,void **,8)||!a)return -1;
 for(i=0;i<M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0x14);i++) {
 if(a==func_0203ae6c(i))return i;
 }return -1;
}

void func_0203af18(void) {
 extern M2C_UNK data_0213d38c; u64 func_02007004(void);
 u64 t; void *p=M2C_FIELD(&data_0213d38c,void **,8);
 if(!p)return;
 M2C_FIELD(p,s32 *,8)=0;
 t=func_02007004();
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u64 *,0xC)=t;
}

s32 func_0203af50(s32 a,void *b,void *c) {
 extern M2C_UNK data_0213d38c;
 s32 func_0203a660(void); s32 func_0204e408(void *,s32,void *,void *);
 if(!M2C_FIELD(&data_0213d38c,void **,8)||!func_0203a660())return 0;
 if(a==-1)a=M2C_FIELD(*M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void ***,4),s32 *,0x214);
 if(!b)b=(u8 *)*M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void ***,4)+0x218;
 if(!c)c=(u8 *)*M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void ***,4)+0x318;
 return func_0204e408(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),a,b,c);
}

void func_0203b000(s32 a) {
 extern M2C_UNK data_0213d38c; s32 func_0203a68c(void *,void *);
 u32 out[132]; void *p=M2C_FIELD(&data_0213d38c,void **,8); s32 n;
 if(M2C_FIELD(p,void **,0x44)&&M2C_FIELD(p,s32 *,0)!=1)
 M2C_FIELD(p,void (**)(s32,s32),0x44)(a,M2C_FIELD(p,s32 *,0x48));
 p=M2C_FIELD(&data_0213d38c,void **,8);
 if(!M2C_FIELD(p,void **,0x34))return;
 n=func_0203a68c((u8 *)M2C_FIELD(p,void **,0x18)+a*12,out+66);
 p=M2C_FIELD(&data_0213d38c,void **,8);
 M2C_FIELD(p,void (**)(s32,s32,void *,s32),0x34)(a,n,out+66,M2C_FIELD(p,s32 *,0x38));
}

void func_0203b088(void) {
    extern M2C_UNK data_0213d38c;
    M2C_FIELD(&data_0213d38c, s32 *, 8) = 0;
}

s32 func_0203b09c(void) {
 extern M2C_UNK data_0213d38c; u64 func_02007004(void);
 u64 func_02072088(u64,u64);
 s32 func_0204db50(void *);
 s32 r=0; void *p=M2C_FIELD(&data_0213d38c,void **,8);
 if(func_02072088((func_02007004()-M2C_FIELD(p,u64 *,0xC))<<6,0x82EA) >=300) {
 M2C_FIELD(p,s32 *,8)++;
 r=func_0204db50(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4));
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u64 *,0xC)=func_02007004();
 }
 return r;
}

void func_0203b128(void) {
 extern M2C_UNK data_0213d38c;
 if(!M2C_FIELD(&data_0213d38c,void **,8))return;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0)=0;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1E)=0;
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1F)=0;
}

void func_0203b158(M2C_UNK *arg0, s32 arg1) {
    (void)arg0;
    (void)arg1;
}

void func_0203b3c4(void) {
 extern M2C_UNK data_0213d38c;
 void *p=M2C_FIELD(&data_0213d38c,void **,8);
 M2C_FIELD(p,void (**)(s32,u8,s32),0x2C)(0,M2C_FIELD(p,u8 *,0x1D),M2C_FIELD(p,s32 *,0x30));
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0)=2;
}

#pragma opt_propagation off
void func_0203b3fc(u8 *a,u32 b,u32 c) { extern M2C_UNK data_0213d38c; void func_02007f8c(void *,s32); void *p=M2C_FIELD(&data_0213d38c,void **,8); if(!p)return; func_02007f8c(a+b*12,0); p=M2C_FIELD(&data_0213d38c,void **,8); if(M2C_FIELD(p,void (**)(s32,s32,s32),0x3c)) M2C_FIELD(p,void (**)(s32,s32,s32),0x3c)(b,c,M2C_FIELD(p,s32 *,0x40)); }
#pragma opt_propagation reset
s32 func_0203b454(u8 *a,s32 b,s32 c) {
 extern M2C_UNK data_0213d38c; s32 func_0203ae6c(s32); s32 func_02031e38(void *);
 s32 i,x;
 for(i=0;i<b;i++) {
 x=func_0203ae6c(i);
 if(x&&x==c) {
 if(func_02031e38(a+b*12)&&!func_02031e38(a+i*12))func_0203b3fc(a,i,b);
 else func_0203b3fc(a,b,i);
 M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),u8 *,0x1D)=1;return 1;
 }
 }return 0;
}

s32 func_0203b500(u8 *a, s32 b, s32 c) {
    extern M2C_UNK data_0213d38c;
    s32 func_0203ae6c(s32);
    s32 func_02031e70(void *);
    s32 func_02031e38(void *);
    void func_020326c4(void *, s32);
    void func_02031eb8(void *);
    void func_0203b3fc(u8 *, u32, u32);

    s32 i, j, x, y;
    s32 result = -1;
    u8 *pi = a;
    u8 *pj = pi;

    for (i = 0; i < b; i++, pi += 12, pj = pi) {
        x = func_0203ae6c(i);
        if (x == 0) {
            continue;
        }

        if (x == c) {
            result = i;
        }

        for (j = i + 1; j < b; j++) {
            pj = a + j * 12;
            y = func_0203ae6c(j);
            if (x != y) {
                continue;
            }

            if (func_02031e70(pi) != 2) {
                continue;
            }

            if (func_02031e70(pj) != 3) {
                continue;
            }

            func_020326c4(pi, x);

            if (func_02031e38(pj) == 0) {
                continue;
            }

            func_02031eb8(pi);
            func_0203b3fc(a, j, i);

            M2C_FIELD(M2C_FIELD(&data_0213d38c, void **, 8), u8 *, 0x1D) = 1;
        }
    }

    return result;
}

s32 func_0203b608(s32 a) {
 extern M2C_UNK data_0213d38c; extern M2C_UNK data_020fc8ec;
 s32 func_0204df00(void *,s32,void *); u32 func_0203b6f8();
 s32 r=func_0204df00(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),a,&data_020fc8ec);
 func_0203b6f8(r); return r;
}

s32 func_0203b63c(s32 arg0,s32 arg1) {
 extern M2C_UNK data_0213d38c;
 s32 func_0203a660(void); s32 func_02039d98(void); s32 func_02032580(s32,s32);
 s32 func_0204e2f4(void *,s32,s32 *); s32 func_0204e1b4(void *,s32,s32);
 void *p=M2C_FIELD(&data_0213d38c,void **,8);
 s32 b=arg1; s32 a=arg0; s32 out=0;
 if(!p||!func_0203a660())return 0;
 a=func_02032580(func_02039d98(),a);
 if(a>0)if(func_0204e2f4(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),a,&out))return 0;
 if(a<=0||out==-1)return 0;
 a=func_0204e1b4(M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),void **,4),out,b);
 if(a == 0) return 1; return 0;
}

u32 func_0203b6f8(u32 a,u32 unused,u32 off){void func_0203accc(u32,u32);u32 ret=a;u32 code=ret;if(ret==0)return 0;switch(ret){case 1:code=9;off=code-10;break;case 2:code=9;off=code-11;break;case 3:code=6;off=code-16;break;case 4:code=6;off=code-26;break;}func_0203accc(code,off+0xfffeeaa8);return ret;}

void func_0203b76c(s32 arg0, void *arg1, s32 arg2) {
 extern M2C_UNK data_0213d38c;
 s32 func_02031e70(void *);
 void func_02031eb8(void *);
 void func_020326c4(void *, s32);
 s32 func_0203b454(u8 *, s32, s32);
 s32 func_0204e2f4(void *, s32, s32 *);
 u32 func_0203b6f8(u32, u32, u32);
 s32 func_0203b608(s32);
 void func_0203b000(s32);

 void *r9 = arg1;
 s32 r10 = arg0;
 s32 r8 = arg2;
 s32 r6 = r8 * 12;
 s32 count = M2C_FIELD(r9, s32 *, 4);

 if (M2C_FIELD(r9, s32 *, 0) == 0 && M2C_FIELD(r9, s32 *, 4) != 0) {
  if (func_02031e70((u8 *)M2C_FIELD(M2C_FIELD(&data_0213d38c, void **, 8), void **, 0x18) + r6) != 0) {
   if (M2C_FIELD(M2C_FIELD(&data_0213d38c, void **, 8), s32 *, 0) == 1) {
    s32 r4;
    s32 r5 = 0;
    for (r4 = 0; r4 < count; r4++) {
     if (func_0203b454((u8 *)M2C_FIELD(M2C_FIELD(&data_0213d38c, void **, 8), void **, 0x18), r8,
        (s32)M2C_FIELD((u8 *)M2C_FIELD(r9, void **, 0xc) + r5, void **, 0)) != 0) {
      void *g8 = M2C_FIELD(&data_0213d38c, void **, 8);
      M2C_FIELD(g8, u8 *, 0x1c)++;
      M2C_FIELD(g8, u8 *, 0x1e) = 1;
      M2C_FIELD(r9, s32 *, 8) = 0x601;
      return;
     }
     r5 += 0xac;
    }
    {
     s32 r7;
     s32 r5b = 0;
     if (count > 0) {
      for (r7 = 0; r7 < count; r7++) {
       s32 out = 0;
       func_0203b6f8((u32)func_0204e2f4(M2C_FIELD(M2C_FIELD(&data_0213d38c, void **, 8), void **, 0x4), r10, &out), 0, 0);
       if (out != -1) {
        void *g8 = M2C_FIELD(&data_0213d38c, void **, 8);
        u8 *slotBase = (u8 *)M2C_FIELD(g8, void **, 0x18) + r6;
        func_020326c4(slotBase, (s32)M2C_FIELD(M2C_FIELD(r9, void **, 0xc), void **, 0));
        func_02031eb8(slotBase);
        func_0203b000(r8);
        M2C_FIELD(g8, u8 *, 0x1c)++;
        M2C_FIELD(g8, u8 *, 0x1e) = 1;
        M2C_FIELD(r9, s32 *, 8) = 0x601;
        M2C_FIELD(g8, u8 *, 0x1d) = 1;
        return;
       }
       func_0203b608((s32)M2C_FIELD((u8 *)M2C_FIELD(r9, void **, 0xc) + r5b, void **, 0));
       r5b += 0xac;
      }
     }
    }
    if (M2C_FIELD(r9, s32 *, 8) != 0x600) {
     void *g8 = M2C_FIELD(&data_0213d38c, void **, 8);
     M2C_FIELD(g8, u8 *, 0x1c)++;
     M2C_FIELD(g8, u8 *, 0x1e) = 1;
    }
    return;
   } else {
    return;
   }
  }
 }
 /* tail 0xa88 */
 if (M2C_FIELD(r9, s32 *, 0) != 0) {
  func_0203b6f8((u32)M2C_FIELD(r9, s32 *, 0), 0, 0);
  return;
 }
 if (M2C_FIELD(M2C_FIELD(&data_0213d38c, void **, 8), s32 *, 0) == 1) {
  void *g8 = M2C_FIELD(&data_0213d38c, void **, 8);
  M2C_FIELD(g8, u8 *, 0x1c)++;
  M2C_FIELD(g8, u8 *, 0x1e) = 1;
  return;
 }
 {
  void *g8 = M2C_FIELD(&data_0213d38c, void **, 8);
  u8 *slotBase = (u8 *)M2C_FIELD(g8, void **, 0x18) + r6;
  if (func_02031e70(slotBase) == 0) {
   M2C_FIELD(g8, u8 *, 0x1c)++;
   M2C_FIELD(g8, u8 *, 0x1e) = 1;
  }
 }
 return;
}

void func_0203b9a8(void **conn, void *buf, s32 unused) {
    extern M2C_UNK data_0213d38c;
    extern M2C_UNK data_020fc8f0;
    s32 func_02031e70(void *);
    s32 func_02039d98(void);
    void func_020326f8(s32, void *, void *);
    s32 func_02068d98(void *, void *);
    s32 func_0204e074(void **, s32);
    void func_020326c4(void *, s32);
    s32 func_02032580(s32, s32);
    s32 func_0200567c(void *, s32, void *, ...);
    s32 func_0206527c(void *, void *, s32);
    s32 func_0203b608(s32);
    s32 func_0204e0c4(void **, s32);

    void *data = &data_0213d38c;
    u8 local[0x1c];
    void *p;
    void *q;
    s32 i = 0;
    s32 found = 0;
    s32 offset = 0;
    s32 t;
    s32 t2;
    s32 res;
    u32 v;

    if (M2C_FIELD(buf, s32 *, 0) != 0) {
        return;
    }

    p = M2C_FIELD(data, void **, 8);
    if (M2C_FIELD(p, s32 *, 0x14) <= 0) {
        goto after_loop;
    }

    i = 0;
    found = 0;
    offset = 0;

    for (;;) {
        p = M2C_FIELD(data, void **, 8);
        if (M2C_FIELD(p, s32 *, 0x14) <= i) {
            break;
        }

        q = (u8 *)M2C_FIELD(p, void **, 0x18) + offset;

        t = func_02031e70(q);
        if (t == 1) {
            t = func_02039d98();
            func_020326f8(t, q, local + 0x11);
            if (func_02068d98(local + 0x11, (u8 *)buf + 0x8e) == 0) {
                func_0204e074(conn, M2C_FIELD(buf, s32 *, 4));
                func_020326c4(q, M2C_FIELD(buf, s32 *, 4));
                found = 1;
            }
        } else {
            t = func_02031e70(q);
            if (t != 3) {
                t = func_02031e70(q);
                if (t != 2) {
                    goto skip_handle;
                }
            }
            t = func_02039d98();
            v = M2C_FIELD(t, u32 *, 0x24);
            func_0200567c(local + 0xc, 5, &data_020fc8f0,
                          (v >> 24) & 0xff,
                          (v >> 16) & 0xff,
                          (v >> 8) & 0xff,
                          v & 0xff);
            t2 = M2C_FIELD(buf, s32 *, 4);
            t = func_02039d98();
            res = func_02032580(t, (s32)q);
            if (t2 == res) {
                if (func_0206527c(local + 0xc, (u8 *)buf + 0x97, 4) == 0) {
                    func_0204e074(conn, t2);
                    found = 1;
                }
            }
        skip_handle: ;
        }

        offset += 0xc;
        i++;
    }

after_loop:
    if (found) {
        func_0203b608(M2C_FIELD(buf, s32 *, 4));
    } else {
        func_0204e0c4(conn, M2C_FIELD(buf, s32 *, 4));
    }
}

void func_0203bb58(s32 unused, void *r10) {
    extern M2C_UNK data_0213d38c;
    s32 func_02031e70(void *);
    s32 func_02039d98(void);
    void func_020326f8(s32, void *, void *);
    s32 func_02068d98(void *, void *);
    void func_020326c4(void *, s32);
    void func_02031eb8(void *);
    s32 func_02032580(s32, s32);
    s32 func_02031e38(void *);
    s32 func_0203b500(u8 *, s32, s32);
    void func_0203b000(s32);

    u8 buf[0x18];
    void *data = &data_0213d38c;
    void *p;
    void *q;
    s32 r6 = 0;
    s32 r7 = 0;
    s32 r8 = 0;
    s32 r9 = 0;
    s32 r11 = 1;
    s32 t;
    s32 res;

    if (M2C_FIELD(r10, s32 *, 0) != 0) {
        return;
    }

    p = M2C_FIELD(data, void **, 8);
    if (M2C_FIELD(p, s32 *, 0x14) <= 0) {
        goto after_loop;
    }

    r9 = 0;
    r11 = 1;

    for (;;) {
        p = M2C_FIELD(data, void **, 8);
        if (M2C_FIELD(p, s32 *, 0x14) <= r6) {
            break;
        }

        q = (u8 *)M2C_FIELD(p, void **, 0x18) + r9;

        t = func_02031e70(q);
        if (t == 1) {
            t = func_02039d98();
            func_020326f8(t, q, buf);
            if (func_02068d98(buf, (u8 *)r10 + 0x8e) == 0) {
                func_020326c4(q, M2C_FIELD(r10, s32 *, 4));
                func_02031eb8(q);
                r7 = r11;
            }
        } else {
            t = func_02031e70(q);
            if (t != 3) {
                t = func_02031e70(q);
                if (t != 2) {
                    goto skip_handle;
                }
            }
            t = func_02039d98();
            res = func_02032580(t, (s32)q);
            if (res == M2C_FIELD(r10, s32 *, 4)) {
                if (func_02031e38(q) == 1) {
                    r8 = 1;
                } else {
                    func_020326c4(q, M2C_FIELD(r10, s32 *, 4));
                    func_02031eb8(q);
                    r7 = 1;
                }
            }
            skip_handle: ;
        }

        p = M2C_FIELD(data, void **, 8);
        r6++;
        r9 += 0xc;
    }

after_loop:
    if (r7 == 0) {
        return;
    }

    p = M2C_FIELD(data, void **, 8);
    res = func_0203b500((u8 *)M2C_FIELD(p, void **, 0x18), M2C_FIELD(p, s32 *, 0x14), M2C_FIELD(r10, s32 *, 4));
    if (r8 == 0) {
        func_0203b000(res);
    }

    M2C_FIELD(M2C_FIELD(data, void **, 8), u8 *, 0x1d) = 1;
}

s32 func_0203bcf8(void) {
 extern M2C_UNK data_0213d38c;
 return M2C_FIELD(M2C_FIELD(&data_0213d38c,void **,8),s32 *,0x20);
}

void func_0203bd0c(void) {
    M2C_UNK func_0205d8f4();
    extern M2C_UNK data_0213d39c;
    if (M2C_FIELD(&data_0213d39c, s32 *, 0x10) != 0) {
        M2C_FIELD(&data_0213d39c, s32 *, 0xC) = 1;
        return;
    }
    func_0205d8f4();
}

s32 func_0203bd34(void) {
    s32 func_0203bd54();
    M2C_UNK func_020418c4();
    if (func_0203bd54() == 0) {
        return 0;
    }
    func_020418c4();
    return 1;
}

s32 func_0203bd54(void) {
    s32 func_0203761c();
    s32 func_02038f6c();
    void *func_02044268();
    if (func_0203761c() != 0) {
        return 0;
    }
    if ((func_02044268() == NULL) || (func_02038f6c() != 5) || (M2C_FIELD(func_02044268(), u8 *, 0x1A9) != 0)) {
        return 0;
    }
    return 1;
}

s32 func_0203bda0(void (*callback)(s32),s32 arg) {
s32 func_0203761c(void);void *func_02044268(void);s32 func_02038f6c(void);void func_0203e410(void);
void *p;
if(func_0203761c()!=0||!func_02044268()||M2C_FIELD(func_02044268(),u8 *,0x15)!=2||(func_02038f6c()!=5&&func_02038f6c()!=6))return 0;
if(M2C_FIELD(func_02044268(),s32 *,0x1a0)==10){
p=func_02044268();M2C_FIELD(p,u8 *,0x16)=M2C_FIELD(func_02044268(),u8 *,0xd);
func_0203e410();if(callback)callback(arg);
}else{
M2C_FIELD(func_02044268(),void (**)(s32),0x47c)=callback;
M2C_FIELD(func_02044268(),s32 *,0x480)=arg;
M2C_FIELD(func_02044268(),u8 *,0x1ae)=1;
}return 1;
}

