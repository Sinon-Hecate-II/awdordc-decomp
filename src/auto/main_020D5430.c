/* 16 functions from 0x020D5430 to 0x020D6398 (main), found by ds-decomp. */
#include "common.h"

void func_020d5430(void) {
 extern void *gCurrentMap;
 func_020cf850(0x1001a);func_0207a7a4(1,4);func_020cf5ec(1);
 if(!func_020bcac0())return;
 if(!func_020bd650())return;
 func_020bd104();func_ov000_021696d4();func_020cfd28();func_0207a768();
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,0x52b4)=0;
}

void func_020d549c(void) {
    M2C_UNK func_0208fe30(s32);
    M2C_UNK func_020cc62c();
    func_0208fe30(0x10017);
    func_020cc62c();
}

void func_020d54b4(void) {

}

void func_020d54b8(void) {
 extern void *gCurrentMap;
 func_020cf80c();func_0207a7a4(1,8);
 if(!func_020d4dd0())return;
 if(!func_020bcc04())return;
 if(!func_020bdcd0())return;
 func_02082770();
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,0x52b4)=0;
}

void func_020d5514(void) {
    extern void *gCurrentMap;
    M2C_UNK (*temp_r0)();

    temp_r0 = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), M2C_UNK (**)(), 0x44);
    if (temp_r0 != NULL) {
        temp_r0();
    }
    M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52B4) = 0xA;
}

void func_020d5868(void) {
 void *func_0209f8e4(s32);
 extern void *gCurrentMap;
 s32 i=0;
 for(;i<func_0209f8d4();i++) {
 void *p=func_0209f8e4(i);
 void *base=M2C_FIELD(gCurrentMap,void **,0);
 u8 **rows=(u8 **)((u8 *)base+0x52e8);
 rows[M2C_FIELD(p,s16 *,6)][M2C_FIELD(p,s16 *,4)]=111;
 }
}

void func_020d61ac(void) {
 extern void *gCurrentMap;
 void *p=M2C_FIELD(gCurrentMap,void **,0);
 func_020cf498(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de));
 func_020c75cc();
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,0x52b4)=5;
}

void func_020d61f0(void) {
    M2C_UNK func_01ffa9e4(M2C_UNK *);
    M2C_UNK func_ov000_021696d4();
    extern M2C_UNK data_0211fbc4;
    func_01ffa9e4(&data_0211fbc4);
    func_ov000_021696d4();
}

void func_020d6310(void);
void func_020d6208(void) {
    extern void *gCurrentMap;
    extern u8 data_02168f24;

    if (func_020d46cc() == 0) {
        if (func_020c9550() != 0) {
            func_020c95e4();
            func_020d61ac();
            return;
        }
        func_020d61f0();
        func_020cfd28();
        if (data_02168f24 != 0) {
            func_ov000_021696d4();
            M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52b4) = 0;
            return;
        }
        {
            void *base = M2C_FIELD(gCurrentMap, void **, 0);
            u8 r3v;
            u8 *r1p;
            r1p = (u8 *)base + 0x5000;
            r3v = r1p[0x2d6];
            if (r3v != 0) {
                void *elem = (u8 *)base + 0x59a4 + (u32)r3v * 14;
                u8 a = r1p[0x2d4];
                u8 b = ((u8 *)elem)[0x0c];
                u8 flag = (a != b) ? 1 : 0;
                func_020d5d0c(elem, flag, 1);
                return;
            }
            {
                void *p2 = *(void **)(r1p + 0x2d0);
                func_020d5aa0(((u8 *)p2)[1], ((u8 *)p2)[2], 1, 1, 1);
                return;
            }
        }
    } else {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52b4) = 6;
        func_ov000_0219c7c4(3);
        func_ov000_0219c7d8(0);
        func_020d6310();
        return;
    }
}

void func_020d6310(void) {
 extern void *gCurrentMap;
 if(!func_020d4dd0())return;
 func_ov000_0219e948();
 if(func_ov000_0219c7b0()!=2)return;
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,0x52b4)=0;
}

void func_020d6350(void) {
 extern void *gCurrentMap;
 void *p=M2C_FIELD(gCurrentMap,void **,0);
 func_020cf498(M2C_FIELD(p,s16 *,0x52dc),M2C_FIELD(p,s16 *,0x52de));
 func_020d468c();func_020bac24();
 M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),s16 *,0x52b4)=0;
}

