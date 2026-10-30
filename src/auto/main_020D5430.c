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

void func_020d5554(s32 arg0, s32 arg1) {
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

s32 func_020d58c4(s32 x,s32 y) {
void *func_020a45f8(s32,s32);
extern void *gCurrentMap;
void *unit; s32 a,b; M2C_UNK (*cb)();
unit=func_020a45f8(x,y);
if(unit){
func_01ffb554((u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x1e30);
func_01ffb3d0(-1);
if(func_020a5364(unit,64,1)){
cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),M2C_UNK (**)(),52);if(cb)cb();
goto finish;
}
}
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,x+M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+y*2,u16 *,0x3758));
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0)=(u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x59a4+M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)*14;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d6)=0;
if(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,x+M2C_FIELD((u8 *)M2C_FIELD(gCurrentMap,void **,0)+y*2,u16 *,0x3758))==0){func_020d5514();return 1;}
a=func_020ba3b4(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
b=func_020ba414(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
if(a==0 && b==0){func_0208fe30(0x1001d);return 0;}
func_01ffb554((u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x1e30);
func_ov000_0216939c(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),M2C_UNK (**)(),52);if(cb)cb();
func_020cfd28();
func_020d5554(x,y);
finish:
func_0207a748(1);
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52b4)=8;
func_0208fe30(0x1001c);return 1;
}

s32 func_020d5aa0(u8 arg0, u8 arg1, s32 arg2, s32 arg3, u8 arg4) { (void)arg0; (void)arg1; (void)arg2; (void)arg3; (void)arg4; return 0; }

void func_020d5d0c(u8 *p,s32 index,s32 arg2){
extern void *gCurrentMap; extern M2C_UNK data_0211fbc4;
s32 slot; M2C_UNK (*cb)(); void *unit;
func_020c93cc();
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)=(p+index)[12];
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0)=(u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x59a4+M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)*14;
slot=p?((s32)p-(s32)((u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x59a4))/14:0;
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d6)=slot;
M2C_FIELD(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0),u16 *,4)&=~8;
func_ov000_0216a8dc(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
func_ov000_0216939c(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,4),M2C_UNK (**)(),56);if(cb)cb();
func_020cfd28();
unit=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0);
func_020d5554(M2C_FIELD(unit,u8 *,1),M2C_FIELD(unit,u8 *,2));
func_0209fb70();
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52b6)=(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u8 *,0x52d4)>>6)+1;
func_01ffb554((u8 *)M2C_FIELD(gCurrentMap,void **,0)+0x1e30);
func_01ffc2e8(M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),void **,0x52d0));
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52b6)=M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52a4);
func_020d5868();
func_0207a748(0);func_0207b028(7);
M2C_FIELD(M2C_FIELD(gCurrentMap,void **,0),u16 *,0x52b4)=2;
func_020a06a0(arg2);
func_01ffa3dc(&data_0211fbc4,6);
func_0208fe30(0x1001c);
}

void func_020d5ef8(s32 r6, s32 r5) {
    M2C_UNK func_0208fe30();
    M2C_UNK func_020d6398();
    M2C_UNK func_0207a768();
    M2C_UNK func_020a0964();
    M2C_UNK func_020d468c();
    M2C_UNK func_020a0d18();
    M2C_UNK func_020d46ac();
    M2C_UNK func_020a046c();
    M2C_UNK func_01ffb3d0();
    M2C_UNK func_020cc7e0();
    extern void *gCurrentMap;
    extern u8 data_02168f24;
    s32 r4;

    r4 = 0;
    {
        u8 r3 = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, 0x52d4);
        u16 r12 = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, 0x52a8);
        if (r12 != (r3 & 0xc0)) {
            func_0208fe30(0x1001d);
            return;
        }
    }
    {
        u8 **rows = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + 0x52e8);
        s8 val = (s8)rows[r5][r6];
        if (val > 0x6e) {
            r4 = 1;
        } else {
            if (func_020d6398() == 0) {
                func_0208fe30(0x1001d);
                return;
            }
        }
    }
    func_0207a768();
    {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, 0x52e0) = (u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, 0x52d0), u8 *, 1);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52d8) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52e0);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u16 *, 0x52e2) = (u8)M2C_FIELD(M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), void **, 0x52d0), u8 *, 2);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52da) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52e2);
    }
    if (r4 != 0) {
        func_020a0964(r6, r5, (u8 *)M2C_FIELD(gCurrentMap, void **, 0) + 0x52dc);
        func_020d468c();
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52c2) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52dc);
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52c4) = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52de);
        func_020a0d18();
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52c2) = (s16)r6;
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52c4) = (s16)r5;
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52b4) = 5;
    } else {
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52dc) = (s16)r6;
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52de) = (s16)r5;
        func_020d46ac();
        func_020a0d18();
        M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52b4) = 4;
    }
    {
        s16 d8 = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52d8);
        s16 dc = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52dc);
        if (d8 == dc) {
            s16 da = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52da);
            s16 de = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52de);
            if (da == de) {
                M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), u8 *, 0x5388) = 4;
                goto skip046c;
            }
        }
        func_020a046c();
    }
skip046c:
    if (r4 != 0) {
        func_01ffb3d0(-1);
        {
            u8 **rows = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + 0x52e8);
            s16 de = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52de);
            s16 dc = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52dc);
            rows[de][dc] = 1;
        }
        {
            u8 **rows = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + 0x52e8);
            rows[r5][r6] = 1;
        }
        func_020cc7e0();
        {
            void (*fp)() = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 4), void (**)(), 0x3c);
            if (fp != NULL) {
                fp();
            }
        }
    } else {
        func_01ffb3d0(-1);
        {
            u8 **rows = (u8 **)((u8 *)M2C_FIELD(gCurrentMap, void **, 0) + 0x52e8);
            s16 de = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52de);
            s16 dc = M2C_FIELD(M2C_FIELD(gCurrentMap, void **, 0), s16 *, 0x52dc);
            rows[de][dc] = 1;
        }
        data_02168f24 = 0;
    }
    return;
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

