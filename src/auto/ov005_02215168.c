/* 11 functions from 0x02215168 to 0x02215664 (ov005), found by ds-decomp. */
#include "common.h"

typedef struct {
    u8 unk_0x0[0xa2];
    u8 unk_0xa2[1];
} UnkOv005Selection;

void func_ov005_02215168(s16 arg0) {
 void *func_020ad570(s32);
 s32 func_ov005_022140f8(s32);
 void func_ov005_022172d8(s32,s32);
 void func_ov005_02215278(s16);
 void func_ov005_02215360(s16);
 extern M2C_UNK data_ov005_02221304;
 switch (M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **,8),s16 *,0x92)) {
 case 0:
 M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x8e)=arg0;
 do {
 arg0++;
 if (*(s32 *)func_020ad570(arg0)==0) {
 arg0=M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x8e);
 break;
 }
 } while (!func_ov005_022140f8(arg0));
 func_ov005_022172d8(arg0,1); break;
 case 1: func_ov005_02215278(arg0); break;
 case 2: func_ov005_02215360(arg0); break;
 }
}

void func_ov005_02215200(s16 arg0) {
 s32 func_ov005_022140f8(s32);
 void func_ov005_022172d8(s32,s32);
 extern M2C_UNK data_ov005_02221304;
 s16 i=arg0;
 do {
 if (--i < 0) i=M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x9a)-1;
 if (func_ov005_022140f8(i) && M2C_FIELD((u8 *)M2C_FIELD(&data_ov005_02221304,void **,8)+i,u8 *,0xa2)==1) {
 func_ov005_022172d8(i,1); return;
 }
 } while (i!=arg0);
}

void func_ov005_02215278(s16 arg0) {
 s32 func_ov005_022140f8(s32);
 void func_ov005_022172d8(s32,s32);
 extern M2C_UNK data_ov005_02221304;
 s16 i=arg0;
 do {
 if (++i >= M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x9a)) i=0;
 if (func_ov005_022140f8(i) && M2C_FIELD((u8 *)M2C_FIELD(&data_ov005_02221304,void **,8)+i,u8 *,0xa2)==1) {
 func_ov005_022172d8(i,1); return;
 }
 } while (i!=arg0);
}

void func_ov005_022152ec(void) {
 void func_ov005_02214e18(s32);
 void func_ov005_022172d8(s32,s32);
 extern M2C_UNK data_ov005_02221304;
 if (M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe4)==0) return;
 M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2)--;
 if (M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2)<0) {
 func_ov005_02214e18(-1);
 M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2)=M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe4)-1;
 }
 func_ov005_022172d8(M2C_FIELD((s16 *)M2C_FIELD(&data_ov005_02221304,void **,8)+M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2),s16 *,0xe6),1);
}

void func_ov005_02215360(s16 arg0) {
 void func_ov005_02214e18(s32);
 void func_ov005_022172d8(s32,s32);
 extern M2C_UNK data_ov005_02221304;
 if (M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe4)==0) return;
 M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2)++;
 if (M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2)>=M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe4)) {
 func_ov005_02214e18(-1);
 M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2)=0;
 }
 func_ov005_022172d8(M2C_FIELD((s16 *)M2C_FIELD(&data_ov005_02221304,void **,8)+M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0xe2),s16 *,0xe6),1);
}

void func_ov005_022153d4(u8 *arg0) {
 M2C_UNK func_020b1c60(s32);
 extern M2C_UNK data_ov005_02221304;
 s32 value = M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x94);
 if (value == *arg0) return;
 func_020b1c60(value);
}

void func_ov005_022153fc(u8 *a) {
    s32 func_020b20e0(s32);
    M2C_UNK func_020b1c60(s32);
    M2C_UNK func_0208fe30(s32);
    s32 func_ov005_02214148(void);
    s32 func_ov005_022141cc(void);
    s16 func_ov005_02214184(void);
    s16 func_ov005_02214210(void);
    extern M2C_UNK data_ov005_02221304;
    extern u16 *data_02101e84;

    void *p = M2C_FIELD(&data_ov005_02221304, void **, 8);
    s32 max = M2C_FIELD(p, s16 *, 0x9a) - 6;
    s32 n = *a;
    s32 pos = M2C_FIELD(p, s16 *, 0x98);
    if (max < 0) max = 0;

    if (pos == 0 && n == 0) {
        if (data_02101e84[0] & 0x40) {
            M2C_FIELD(p, s16 *, 0x98) = (s16)max;
            n = 5;
            goto done;
        }
    } else if (data_02101e84[1] & 0x40) {
        if (n >= 2) n--;
        else if (!func_ov005_02214148() && n) n--;
        goto done;
    }

    if (pos == max && n == 5) {
        if (data_02101e84[0] & 0x80) {
            n = 0;
            M2C_FIELD(p, s16 *, 0x98) = 0;
            goto done;
        }
    } else if (data_02101e84[1] & 0x80) {
        if (n < 4) {
            if (func_020b20e0(n + 1)) n++;
        } else if (!func_ov005_022141cc()) {
            if (func_020b20e0(n + 1)) n++;
        }
        goto done;
    }

    if (data_02101e84[1] & 0x20) {
        s32 delta = func_ov005_02214184();
        n -= delta + 6;
        if (n < 0) n = 0;
        if (delta != 0) {
            if (n == *a) func_0208fe30(0x10019);
        }
    } else if (data_02101e84[1] & 0x10) {
        s32 delta = func_ov005_02214210();
        n += 6 - delta;
        if (n >= 6) n = 5;
        if (delta != 0) {
            if (n == *a) func_0208fe30(0x10019);
        }
    }

done:
    if (n != *a) func_020b1c60(n);
    M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x94) = n;
}

void func_ov005_02215594(u8 *arg0) {
 void func_ov005_02214fec(s16);
 extern M2C_UNK data_ov005_02221304;
 func_ov005_02214fec((s16)(M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x98)+*arg0));
}

void func_ov005_022155c0(u8 *arg0) {
    M2C_UNK func_0208fe30(s32);
    extern M2C_UNK data_ov005_02221304;
    M2C_FIELD(M2C_FIELD(&data_ov005_02221304, void **, 8), s16 *, 0x94) = (s16) *arg0;
    func_0208fe30(0x10019);
}

void func_ov005_022155e8(u8 *arg0) {
 s32 func_ov005_022140f8(s32);
 void func_ov005_022148f0(s32);
 void func_ov005_02214e18(s32);
 extern M2C_UNK data_ov005_02221304;
 u8 *flags;
 s32 i=M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x98)+*arg0;
 if (!func_ov005_022140f8(i)) return;
 flags=((UnkOv005Selection *)M2C_FIELD(&data_ov005_02221304,void **,8))->unk_0xa2;
 flags[i] = flags[i] == 0 ? 1 : 0;
 func_ov005_022148f0(M2C_FIELD(M2C_FIELD(&data_ov005_02221304,void **,8),s16 *,0x96));
 func_ov005_02214e18(-1);
}

void func_ov005_02215650(void) {
    M2C_UNK func_01ffa770(M2C_UNK *);
    extern M2C_UNK data_ov005_02220510;
    func_01ffa770(&data_ov005_02220510);
}
