/* 16 functions from 0x021EAED0 to 0x021EBEC0 (ov003), found by ds-decomp. */
#include "common.h"

u8 func_ov003_021eba24(void *arg0) {
 s32 func_020848c4();
 s32 value;
 u8 i;
 u8 count;
 s8 result;
 value=func_020848c4();
 count=M2C_FIELD(arg0,u8 *,4);
 for(i=0;(u32)i<(u32)count;i++) {
  if(value==M2C_FIELD(arg0+i,u8 *,0x74)) {result=(s8)i; goto done;}
 }
 result=-1;
done:
 return (u8)result;
}

s32 func_ov003_021eba74(void) {
 s32 func_020846a4();
 s32 func_020848f8();
 void *func_02084e24(s32);
 s8 i;
 s32 mask;
 void *p;
 if(func_020846a4()==0) return 0;
 mask=func_020848f8();
 for(i=0;i<4;i++) {
  if(mask & (1<<i)) {
   p=func_02084e24(i);
   if(p==NULL) return 0;
   if(M2C_FIELD(p,s32 *,0x18)==0) return 0;
  }
 }
 return 1;
}

void func_ov003_021ebae0(void *arg0) {
    M2C_UNK func_ov003_021e88e0(void *);
    void *temp_r0;

    M2C_FIELD(arg0, u8 *, 0x3A) = (u8) (M2C_FIELD(arg0, u8 *, 0x3A) | 0x80);
    func_0208fe30(0x1000D);
    temp_r0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x64), void **, 4);
    if ((s32) M2C_FIELD(temp_r0, s8 *, 0x5A) >= 0) {
        M2C_FIELD(temp_r0, s32 *, 0x40) = (s32) ((M2C_FIELD(temp_r0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(temp_r0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
        M2C_FIELD(temp_r0, s8 *, 0x5A) = 0xC;
    }
    func_02088da8(M2C_FIELD(arg0, s32 *, 0x58));
    func_02088da8(M2C_FIELD(arg0, s32 *, 0x5C));
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
    if (func_ov003_021e6cfc() == 0) {
        return;
    }
    func_ov003_021e88e0(arg0);
}

void func_ov003_021ebb88(void *arg0) {
    if ((s32) M2C_FIELD(arg0, s8 *, 0x5A) < 0) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(arg0, u8 *, 0x59) << 0x1C) >> 0x1C) + 1) << 0x18) >> 6));
    M2C_FIELD(arg0, s8 *, 0x5A) = 0xC;
}

u8 func_ov003_021ebbcc(void *arg0) {
    u8 var_r0;

    if ((((u32) (M2C_FIELD(arg0, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) != (u16) ((u32) (M2C_FIELD(arg0, s32 *, 0x40) << 6) >> 0x18)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021ebc00(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) (((u32) (M2C_FIELD(arg0, u8 *, 0x59) << 0x1C) >> 0x1C) + 2) << 0x18) >> 6));
    M2C_FIELD(arg0, s8 *, 0x5A) = 0;
}

u8 func_ov003_021ebc38(void *arg0) {
    u8 var_r0;

    if (((u32) (M2C_FIELD(arg0, u8 *, 0x39) << 0x18) >> 0x1C) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_ov003_021ebc54(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x40) = (s32) ((M2C_FIELD(arg0, s32 *, 0x40) & ~0x03FC0000) | ((u32) ((u16) ((u32) (M2C_FIELD(arg0, u8 *, 0x59) << 0x1C) >> 0x1C) << 0x18) >> 6));
    M2C_FIELD(arg0, s8 *, 0x5A) = 0;
}

u8 func_ov003_021ebc88(void *arg0) {
    return M2C_FIELD(arg0, u8 *, 0x59);
}

u8 func_ov003_021ebc90(s32 arg0, s32 arg1) {
    return (u8) M2C_FIELD(((arg1 * 0x18) + arg0), s32 *, 0x18);
}

void func_ov003_021ebca4(s32 arg0,s32 arg1,s32 arg2) {
 s32 offset;
 s32 base;
 void *p;
 void *q;
 s32 value;
 s32 temp;
 offset=arg1*0x18;
 base=arg0+0x18;
 M2C_FIELD(base+offset,s32 *,0)=arg2;
 p=(void *)(arg0+offset);
 if(M2C_FIELD(p,u8 *,0x28)) {
  if(M2C_FIELD(base+offset,s32 *,0)>M2C_FIELD(p,s32 *,0x1c)) {
   do {
    temp=M2C_FIELD(p,s32 *,0x18)-(M2C_FIELD(p,s32 *,0x1c)-M2C_FIELD(p,s32 *,0x20)+1);
    M2C_FIELD(p,s32 *,0x18)=temp;
   } while(temp>M2C_FIELD(p,s32 *,0x1c));
  }
  q=(void *)(arg0+offset);
  if(M2C_FIELD(base+offset,s32 *,0)>=M2C_FIELD(q,s32 *,0x20)) return;
  do {
   temp=M2C_FIELD(q,s32 *,0x18)+(M2C_FIELD(q,s32 *,0x1c)-M2C_FIELD(q,s32 *,0x20)+1);
   M2C_FIELD(q,s32 *,0x18)=temp;
  } while(temp<M2C_FIELD(q,s32 *,0x20));
  return;
 }
 value=M2C_FIELD(p,s32 *,0x1c);
 temp=M2C_FIELD(base+offset,s32 *,0);
 if(temp<=value) {
  value=M2C_FIELD(p,s32 *,0x20);
  if(temp>=value) value=temp;
 }
 M2C_FIELD(base+offset,s32 *,0)=value;
}

s8 func_ov003_021ebd64(void *arg0,s32 arg1) {
 void *func_02084e24(s32);
 void *func_02084e64(s32);
 s32 func_020a22fc(s32);
 s32 func_ov003_02200808(u8);
 s32 id=M2C_FIELD(M2C_FIELD(arg0,s32 *,0x6c)+arg1,u8 *,0x74);
 u8 missing;
 void *p;
 if(id==0xff) missing=1; else missing=0;
 if(!missing) {
  p=func_02084e24(id);
  if(p) return M2C_FIELD(p,s8 *,0xd);
  return (s8)func_ov003_02200808((u8)func_020a22fc(arg1+1));
 }
 p=func_02084e64(id);
 if(p) return M2C_FIELD(p+arg1,s8 *,0x12);
 return (s8)func_ov003_02200808((u8)func_020a22fc(arg1+1));
}

void func_ov003_021ebde8(void *arg0, s8 arg1, s8 arg2) {
    M2C_FIELD(arg0, s8 *, 0x10) = arg1;
    M2C_FIELD(arg0, s8 *, 0x11) = arg2;
}

void func_ov003_021ebdf4(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_02088da8(s32);
    M2C_UNK func_0208fe30(s32);
    s32 func_ov003_021e6cfc();
    s32 func_ov003_021e6e40();
    M2C_UNK func_ov003_021e891c(void *);
    M2C_UNK func_ov003_021f140c(M2C_UNK);
    M2C_FIELD(arg0, u8 *, 0x3A) = (u8) (M2C_FIELD(arg0, u8 *, 0x3A) & ~0x80);
    func_0208fe30(0x1000F);
    func_02088da8(M2C_FIELD(arg0, s32 *, 0x58));
    func_02088da8(M2C_FIELD(arg0, s32 *, 0x5C));
    func_ov003_021f140c(2);
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    func_01ffa6fc(arg0);
    if (func_ov003_021e6cfc() == 0) {
        return;
    }
    if (func_ov003_021e6e40() != 0) {
        return;
    }
    func_ov003_021e891c(arg0);
}

void func_ov003_021ebe60(void *arg0) {
 M2C_UNK func_020aacf0(s32);
 u8 i;
 func_020aacf0(M2C_FIELD(arg0,s32 *,0));
 func_020aacf0(M2C_FIELD(arg0,s32 *,4));
 for(i=0;(u32)i<4U;i++) {
  func_020aacf0(((s32 *)(arg0+8))[i]);
  func_020aacf0(((s32 *)(arg0+0x18))[i]);
  func_020aacf0(((s32 *)(arg0+0x28))[i]);
  func_020aacf0(((s32 *)(arg0+0x38))[i]);
 }
}

