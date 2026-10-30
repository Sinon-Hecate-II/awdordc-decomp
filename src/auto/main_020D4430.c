/* 54 functions from 0x020D4430 to 0x020D5430 (main), found by ds-decomp. */
#include "common.h"
void func_020d4f4c(void);
void func_020d5304(void);
void func_020d50bc(void);

void func_020d4430(void){extern void **gCurrentMap;if((s32)M2C_FIELD(*gCurrentMap,u16*,0x52a2)>1)func_020a2b84(M2C_FIELD(*gCurrentMap,u16*,0x52a4));func_ov000_0216a86c();M2C_FIELD(*gCurrentMap,u16*,0x52b0)=6;}

/* Advances the battle state machine one step: bail out when locked or busy,
   handle the current entry's pending flag, otherwise run the step sequence. */
void func_020d447c(void) {
extern void **gCurrentMap;
void func_020cbdbc(void);
u8 func_0207b7c4(void);
void *state;
if(func_020946d0())return;
if(func_0207b7c4())return;
state=*gCurrentMap;
if(M2C_FIELD((u8 *)state+M2C_FIELD(state,u16 *,0x52a4)*0x8c,u8 *,0x67bd)){
M2C_FIELD(state,u16 *,0x52b0)=1;return;
}
func_020994e0(0);
if(func_020d0590(M2C_FIELD(*gCurrentMap,u16 *,0x52a4))){
state=(u8 *)*gCurrentMap+0x67a4+M2C_FIELD(*gCurrentMap,u16 *,0x52a4)*0x8c;
func_0207b764(M2C_FIELD(state,u8 *,0x2d),M2C_FIELD(state,u8 *,0x2e));
}
if(func_0207b7c4())return;
func_020a2b84(M2C_FIELD(*gCurrentMap,u16 *,0x52a4));
func_020cbdbc();func_020a3b58();func_020a694c();func_020a69bc();func_020cfd28();
M2C_FIELD(*gCurrentMap,u16 *,0x52b0)=7;
}

void func_020d457c(void){extern void **gCurrentMap;if(func_0208f8a0())return;func_ov000_0216c200();if(M2C_FIELD(*gCurrentMap,u16*,0x52a2)==1){if(M2C_FIELD(*gCurrentMap,u16*,0x52a4)==1)M2C_FIELD(*gCurrentMap,u16*,0x52b0)=10;else M2C_FIELD(*gCurrentMap,u16*,0x52b0)=9;}else M2C_FIELD(*gCurrentMap,u16*,0x52b0)=8;}

void func_020d45d8(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u16*,0x52b0)=M2C_FIELD(*gCurrentMap,u16*,0x52b2);M2C_FIELD(*gCurrentMap,u16*,0x52b2)=0;func_020ca4c0();}

void func_020d4614(void){extern void **gCurrentMap;if(func_020946d0())return;func_020d33ec();func_020cce4c();M2C_FIELD(*gCurrentMap,u16*,0x52b0)=0;}

void func_020d464c(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u16*,0x52b0)=20;}

void func_020d466c(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u16*,0x52b0)=13;}

void func_020d468c(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ac)=1;}

void func_020d46ac(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ac)=0;}

u8 func_020d46cc(void) {
    extern void **gCurrentMap;
    return M2C_FIELD(*gCurrentMap, u8 *, 0x52AC);
}

s32 func_020d46e8(void){extern void **gCurrentMap;return M2C_FIELD(*gCurrentMap,s8*,0x52aa);}

void func_020d4704(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,s8*,0x52aa)++;}

void func_020d472c(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,s8*,0x52aa)--;}

void func_020d4754(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,s8*,0x52aa)=0;}

u8 func_020d4774(void){extern void **gCurrentMap;return M2C_FIELD(*gCurrentMap,u8*,0x52ab);}

void func_020d4790(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ab)=1;}

void func_020d47b0(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ab)=0;}

void func_020d47d0(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ad)=1;}

void func_020d47f0(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u8*,0x52ad)=0;}

u8 func_020d4810(void){extern void **gCurrentMap;return M2C_FIELD(*gCurrentMap,u8*,0x52ad);}

/* Normalize the current map/arena id into the base slot (225), copying its
   entry there when it falls in the arena range [225,425). */
void func_020d482c(void) {
    extern void **gCurrentMap;
    extern u16 data_02168f14;
    void *func_020c7e6c(s32);
    s32 func_020a89a4(s32);
    void *dst;
    u32 mapId;
    s32 inRange;

    if ((u8)((u32)(data_02168f14 << 29) >> 29) == 0)
        func_0209f390();
    if (func_020846a4()) {
        mapId = M2C_FIELD(*gCurrentMap, u16 *, 0x5142);
        inRange = 0;
        if (mapId >= 225)
            inRange = mapId < 425;
        if (inRange) {
            dst = func_020c7e6c(225);
            func_02007ef4(func_020c7e6c(M2C_FIELD(*gCurrentMap, u16 *, 0x5142)), dst, 84);
            M2C_FIELD(*gCurrentMap, u16 *, 0x5142) = 225;
        }
        if (func_02084830())
            M2C_FIELD(&data_02168f14, u16 *, 4) = func_020a89a4(M2C_FIELD(*gCurrentMap, u16 *, 0x5142));
    }
    func_020945f8();
    func_020a2148(0);
    func_02091c20(25, 1);
}

void func_020d4928(void) {
    M2C_UNK func_020d9394();
    M2C_UNK func_020d4b30();
    M2C_UNK func_020d3d68();
    M2C_UNK func_0209643c();
    M2C_UNK func_020d4ae8();
    M2C_UNK func_020b1ae0();
    func_020b1ae0();
    func_020d4ae8();
    func_0209643c();
    func_020d3d68();
    func_020d4b30();
    func_020d9394();
}

void func_020d4948(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212be74;
    func_01ffa3dc(&data_0212be74, 7);
}

void func_020d4960(void *arg0){extern M2C_UNK data_02168f0c; void *func_02084cc0(void *); void func_02086330(void *); if(M2C_FIELD(&data_02168f0c,u8*,0)==0)return;func_02086330(func_02084cc0(arg0));}

void func_020d4984(void) {
    M2C_UNK func_02088634();
    M2C_UNK func_0209f858();
    s32 func_020cd1e4();
    M2C_UNK func_020cd5ac();
    M2C_UNK func_020d887c();
    M2C_UNK func_020d88ac();
    M2C_UNK func_020d895c();
    M2C_UNK func_020d8cc8();
    s32 func_020e4b54();
    extern s32 data_0215d8a0;
    extern M2C_UNK data_02168f0c;
    extern u16 data_02168f14;
    u32 temp_r0;

    temp_r0 = (u32) (data_02168f14 << 0x1D) >> 0x1D;
    switch ((u8) temp_r0) {                         /* irregular */
    case 0:
        if ((func_020cd1e4() != 0) && (func_020e4b54() != 0) && (((u32) (data_0215d8a0 << 8) >> 0x18) == 1)) {
            func_020d88ac();
            return;
        }
        func_02088634();
        func_020cd5ac();
        return;
    case 1:
        if (M2C_FIELD(&data_02168f0c, u8 *, 0) != 0) {
            if ((M2C_FIELD(&data_02168f0c, u8 *, 1) != 0) || ((M2C_FIELD(&data_02168f0c, u8 *, 2) != 0) && (M2C_FIELD(&data_02168f0c, u8 *, 3) == 0))) {
                func_020d887c();
            } else {
                func_020d895c();
            }
            func_020d8cc8();
            func_0209f858();
            return;
        }
        func_020d887c();
        return;
    }
}

void func_020d4a50(void) {
    M2C_UNK func_01ffa3dc(M2C_UNK *, M2C_UNK);
    extern M2C_UNK data_0212be0c;
    func_01ffa3dc(&data_0212be0c, 7);
}

void func_020d4a68(void *arg0){extern void **gCurrentMap;void (*cb)(void);func_020ceb48();func_020b4c08(M2C_FIELD(arg0,s16*,0x34));func_020d1c38();func_020b1ae0();cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,4),void(**)(void),0x50);if(cb)cb();func_020d4b30();func_020a2b84(M2C_FIELD(*gCurrentMap,u16*,0x52a4));func_020d93a8();}

void func_020d4ac8(s16 arg0) {
    extern M2C_UNK data_0212bdcc;
    M2C_FIELD(func_01ffa3dc(&data_0212bdcc, 7), s16 *, 0x34) = arg0;
}

int func_020d4ae8(void){extern void **gCurrentMap;int (*cb)(void);func_020d3d24();cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,4),int(**)(void),0x4c);if(cb)cb();cb=M2C_FIELD(M2C_FIELD(gCurrentMap,void**,4),int(**)(void),0x50);if(cb)return cb();return (int)cb;}

extern void func_020d4cf0(void);
extern void func_020a44d0(void);
extern void func_020d33d8(void);
extern void func_020cbdbc(void);
extern int func_020846a4(void);
extern void func_020852a8(void);
extern void func_020901b0(int, int, int, int);
int func_020d4b30() {
    extern void **gCurrentMap;
    void (*callback)(void);
    void *ptr;

    ptr = (void *)gCurrentMap;
    ptr = *(void **)((char *)ptr + 4);
    callback = *(void (**)(void))((char *)ptr + 0x40);

    if (callback != 0) {
        callback();
    }

    func_020d4cf0();
    func_020a44d0();
    func_020d33d8();
    func_020cbdbc();

    if (func_020846a4() == 1) {
        func_020852a8();
        func_020901b0(1, -1, 0x108, 0);
    }

    func_020901b0(2, -1, 0x109, 0);
}

int func_020d4ba4(void){func_020a44e8();func_020d4d78();func_020d33ec();func_ov000_021696d4();func_02090034(1,10);func_02090034(2,10);}

M2C_UNK func_020d4bd4(void){extern void **gCurrentMap;void (*cb)(void)=M2C_FIELD(gCurrentMap[1],void (**)(void),0x50);if(cb)cb();func_02091cd0();func_020d4b30();func_020cfd28();}

void func_020d4c08(void) {
    M2C_UNK func_020d4ba4();
    M2C_UNK func_020d8e28();
    func_020d8e28();
    func_020d4ba4();
}

void func_020d4c18(void) {
    M2C_UNK func_020d9394();
    M2C_UNK func_020d4bd4();
    func_020d4bd4();
    func_020d9394();
}

void func_020d4ca4(void *);
void func_020d4c28(void *arg0){func_02003bd0();func_02077c10();func_020d4ca4(arg0);}

void func_020d4c44(void) {
    M2C_UNK func_020d3b24();
    func_020d3b24();
}

void *func_020d4cd4(void);
u8 func_020d4cb0(void *);
void func_020d4cc8(void *);
void func_020d4c50(void){void *p=func_020d4cd4();if(!p)return;if(!func_020d4cb0(p))return;func_02077c64();func_02077c78();func_020d4cc8(p);}

void func_020d4c80(void *arg0) {
    M2C_UNK func_01ffa6fc(void *);
    M2C_UNK func_01ffaa0c(u16);
    func_01ffaa0c((u16) M2C_FIELD(arg0, s32 *, 0x5C));
    func_01ffa6fc(arg0);
}

void func_020d4ca4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 1;
}

u8 func_020d4cb0(void *arg0) {
    u8 var_r0;

    if (M2C_FIELD(arg0, s32 *, 0x5C) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020d4cc8(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x5C) = 0;
}

void *func_020d4cd4(void) {
    void *func_01ffa860(M2C_UNK *, s32);
    extern M2C_UNK data_0212bd84;
    return func_01ffa860(&data_0212bd84, 0xFF03);
}

void func_020d4cf0(void){extern M2C_UNK data_0212bd84,data_0212bdb4,data_0212bd9c,data_02168f0c; s32 func_01ffa810(s32);M2C_UNK func_01ffa3dc();void func_01ffa8bc(M2C_UNK,s32);M2C_UNK p;if(func_01ffa810(0xff03))return;p=func_01ffa3dc(&data_0212bd84,4);func_01ffa8bc(p,0xff03);func_020d4cc8((void*)p);func_01ffa8bc(func_01ffa3dc(&data_0212bdb4,6),0xff03);func_01ffa8bc(func_01ffa3dc(&data_0212bd9c,10),0xff03);if(M2C_FIELD(&data_02168f0c,u8*,0))func_020852a8();}

int func_020d4d78(void){s32 func_01ffa810(s32);void *func_0209cce4(void (*)(void *),int);if(!func_01ffa810(0xff03))return;M2C_FIELD(func_0209cce4(func_020d4c80,2),s32*,0x5c)=0xff03;}

u8 func_020d4dac(void) {
    s32 func_01ffa810(s32);
    u8 var_r0;

    if (func_01ffa810(0xFF03) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

u8 func_020d4dd0(void){extern void **gCurrentMap;return (M2C_FIELD(*gCurrentMap,u8*,0x5154)&15)==0;}

void func_020d5068(void);
void func_020d4dfc(void){extern void **gCurrentMap;switch(M2C_FIELD(*gCurrentMap,u16*,0x52b4)){case 0:func_020d4f4c();break;case 1:func_020d5068();break;case 2:func_020d50bc();break;case 3:func_020d5304();break;case 4:func_020d61ac();break;case 5:func_020d6208();break;case 6:func_020d6310();break;case 7:func_020d6350();break;case 8:func_020d5430();break;case 9:func_020d54b4();break;case 10:func_020d54b8();break;}}

int func_020d4ea8(void){extern void **gCurrentMap;u16 state;if(!func_020d19b4(M2C_FIELD(*gCurrentMap,u16*,0x52a4)))return 2;if(func_020946d0())return 3;state=M2C_FIELD(*gCurrentMap,u16*,0x52b0);if(state==12||state==13||state==20){switch(M2C_FIELD(*gCurrentMap,u16*,0x52b4)){case 0:case 2:case 3:return 0;case 4:case 5:return 1;}}return 3;}

void func_020d4f4c(void) {
s32 func_020d8f60(void); s32 func_020bd13c(void); s32 func_ov000_0216ab64(s32); s32 func_020bc910(void); s32 func_020bd560(void);
s32 old, reset, notify, key;
old=func_020d8f60();
reset=0; notify=0;
key=func_020bd13c();
switch(key) { case 0x1000: notify=1; break; case 0: reset=1; notify=1; break; }
if(notify) { func_020cf828(0x1001a); func_0207a7a4(1,4); }
func_020cf5ec(0);
if(func_020d4dd0()) {
if(func_ov000_0216ab64(1)) return;
switch(key) {
case 0: case 0x20: case 0x1000:
if(func_020bc910()) return;
if(func_020bd560()) return;
break;
case 0x10: func_020c752c(); return;
case 0x100: func_020ccca0(); return;
case 0x40: func_020d8fa0(); break;
case 0x80: break;
}
}
func_020d6778(0);
if(!reset) return;
func_020bdfa8(); func_020be078();
if(!old) return;
func_020be044();
}

void func_020d5068(void){extern void **gCurrentMap;M2C_FIELD(*gCurrentMap,u16*,0x52b4)=0;}

u8 func_020d5088(void *arg0) {
    s32 func_020a735c();
    u8 var_r0;

    if (func_020a735c() != 0x14) {
        return 0U;
    }
    if (((u32) (M2C_FIELD(arg0, u16 *, 6) << 0x15) >> 0x1C) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}

void func_020d50bc(void) {
 extern void **gCurrentMap;
 extern u8 data_0211fbc4[];
 u32 func_020bca68(void);
 u32 func_020bd684(void);
 void *m;
 u32 keys;
 func_020cf850(0x1001a);
 func_0207a7a4(1,4);
 m=*gCurrentMap;
 if (M2C_FIELD(M2C_FIELD((u8*)m+M2C_FIELD(m,s16*,0x52c4)*4, s8 **,0x52e8)+M2C_FIELD(m,s16*,0x52c2),s8*,0)>110) {
 func_020cf5ec(2);
 } else if(func_020d5088(M2C_FIELD(m,void**,0x52d0))) {
 m=*gCurrentMap;
 if(M2C_FIELD((u8*)m+(M2C_FIELD(m,s16*,0x52c2)+M2C_FIELD((u8*)m+M2C_FIELD(m,s16*,0x52c4)*2,u16*,0x3758)),s8*,0x1e30)>=0) {
 func_020cf754(1,func_020a76d4(M2C_FIELD(m,void**,0x52d0)));
 } else func_020cf5ec(1);
 } else {
 m=*gCurrentMap;
 if(func_020ba790(M2C_FIELD(m,s16*,0x52c2),M2C_FIELD(m,s16*,0x52c4)))func_020cf5ec(2);
 else func_020cf5ec(1);
 }
 if(func_020d4dd0()){
 keys=0;
 keys|=func_020bca68();
 keys|=func_020bd684();
 if(keys&0x10){
 m=*gCurrentMap;
 func_020d5ef8(M2C_FIELD(m,s16*,0x52c2),M2C_FIELD(m,s16*,0x52c4));
 func_0207b040();
 } else if(keys&0x20) {
 m=M2C_FIELD(*gCurrentMap,void**,0x52d0);
 func_0207b764(M2C_FIELD(m,u8*,1),M2C_FIELD(m,u8*,2));
 func_ov000_021696d4();
 m=*gCurrentMap;
 if(M2C_FIELD(m,u8*,0x52d6)) {
 m=M2C_FIELD(m,void**,0x52d0);
 M2C_FIELD(m,u16*,4)|=0xa;
 }
 func_020cfd28();func_0207a768();func_0207b040();
 M2C_FIELD(*gCurrentMap,u16*,0x52b4)=0;
 func_01ffa9e4(data_0211fbc4);
 func_0208fe30(0x1000f);
 } else if(keys&0x100)func_020ccca0();
 else if(keys&0x40)func_020d8fa0();
 }
 func_020d6778(2);
}

void func_020d52d0(void){extern void **gCurrentMap;func_020b2268();func_0208fe30(0x1000f);M2C_FIELD(*gCurrentMap,u16*,0x52b4)=0;}

void func_020d5304(void) {
extern void **gCurrentMap;
s32 func_020ba980(s32,s32);
s32 func_020bcaf0(void);
s32 func_020bdd18(void);
s32 valid, keys;
u32 index;
void *state;
keys=0;
func_020cf828(0x1001a);
func_0207a7a4(1,4);
valid=func_020ba980(M2C_FIELD(*gCurrentMap,s16 *,0x52c2),M2C_FIELD(*gCurrentMap,s16 *,0x52c4));
if(valid) func_020cf5ec(4); else func_020cf5ec(5);
if(!func_020d4dd0()) return;
keys |= func_020bcaf0();
keys |= func_020bdd18();
if(keys&0x20) {func_020d52d0();return;}
if(keys&0x100) {func_020ccca0();return;}
if(keys&0x40) {func_020d8fa0();return;}
if(keys&0x10) {
if(valid) {
state=*gCurrentMap;
index=M2C_FIELD(state,u8 *,M2C_FIELD(state,s16 *,0x52c2)+M2C_FIELD((u8 *)state+M2C_FIELD(state,s16 *,0x52c4)*2,u16 *,0x3758));
func_ov000_02199f50(0x10,index,0,0);
M2C_FIELD(*gCurrentMap,void **,0x52d0)=(u8 *)state+0x59a4+index*14;
func_ov000_0219fd54();
} else func_020d52d0();
}
}

