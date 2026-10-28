/* 30 functions from 0x0222A9DC to 0x0222B9DC (ov010), found by ds-decomp. */
#include "common.h"

void func_ov010_0222a9dc(void *arg0) {
    M2C_UNK func_ov010_02228180(void *);
    M2C_UNK func_01ffa8c4(void *, s32);

    if (func_ov010_02228180(arg0) == 3) {
        func_01ffa8c4(arg0, 8);
    }
}

void func_ov010_0222ad50(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, void *arg3) {
    s32 func_020abe90(M2C_UNK);
    s32 func_020ad3f0(void);
    M2C_UNK func_ov010_0222a808(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, void *);
    M2C_UNK func_ov010_02228320(void);
    M2C_UNK func_ov010_022282d4(M2C_UNK);
    M2C_UNK func_01ffa8c4(void *, M2C_UNK);
    if (func_020abe90(M2C_FIELD(arg3, u8 *, 0x35)) == 1) {
        return;
    }
    if (func_020ad3f0() != 0) {
        return;
    }
    if (arg0 == 0) {
        return;
    }
    func_ov010_0222a808(M2C_FIELD(arg3, s8 *, 0x35), M2C_FIELD(arg3, u16 *, 0x36), arg0, arg1, arg2, arg3);
    func_ov010_02228320();
    switch (arg2) {
    case 0:
    case 1:
    case 2:
        func_ov010_022282d4(6);
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        func_01ffa8c4(arg3, 1);
        break;
    default:
        break;
    }
}

void func_ov010_0222ae08(M2C_UNK arg0) {
    M2C_UNK func_ov010_0222a20c(M2C_UNK *, M2C_UNK);
    void func_ov010_0222ad50(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    func_ov010_0222a20c((M2C_UNK *) &func_ov010_0222ad50, arg0);
}

void func_ov010_0222ae20(void *arg0) {
M2C_UNK func_020899cc(void *,M2C_UNK,s32,s32);void *func_0208b520(void *);M2C_UNK func_ov010_02228614();
extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine;
s32 old;u32 current;s32 i;s8 mode;void *p;
if(M2C_FIELD(arg0,s8 *,0x35)>=0){
old=gCur3DSpriteEngine;i=0;
do {
if(i==0)current=data_027e00c8;else current=data_027e00c4;
gCur3DSpriteEngine=current;mode=M2C_FIELD(arg0,s8 *,0x35);
if(mode==0&&current!=data_027e00c8)continue;
if(mode==1&&current!=data_027e00c4)continue;
if(mode==3&&current!=old)continue;
p=func_0208b520(arg0);
func_020899cc(p,0,M2C_FIELD(arg0,u16 *,0x36)<<5,0x4200001b);
M2C_FIELD(p,s32 *,0x58)=((M2C_FIELD(p,s32 *,0x58)|0x1000)&~0x400)|0x800;
}while(++i<2);
gCur3DSpriteEngine=old;
}
func_ov010_02228614();
}

void func_ov010_0222aef8(M2C_UNK arg0) {
    s32 func_ov010_02228640();
    M2C_UNK func_01ffa6fc(M2C_UNK);
    if (func_ov010_02228640() != 0) {
        return;
    }
    func_01ffa6fc(arg0);
}

void func_ov010_0222af18(void) {
    M2C_UNK func_02085c4c();
    M2C_UNK func_ov010_02228760(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32);
    func_ov010_02228760(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    func_02085c4c();
}

void func_ov010_0222af58(M2C_UNK arg0) {
    s32 func_020c4bc0(M2C_UNK);
    if (func_ov010_022282b4(2) == 0) {
        return;
    }
    if (func_020c4bc0(0) != 0) {
        func_020c4cdc(arg0);
    }
    func_020c4dd0(arg0);
    func_01ffa6fc(arg0);
}

void func_ov010_0222af9c(void *arg0) {
    s32 func_ov010_02229ef4(s32, M2C_UNK, M2C_UNK, s32, s32);
    if (func_ov010_02229ef4(arg0 + 0x38, 1, 0, arg0 + 0x3C, arg0 + 0x40) != 0) {
        return;
    }
    if (((s32) M2C_FIELD(arg0, s8 *, 0x35) >= 0) && (func_0208b5ec() != 0)) {
        func_0208af20();
    }
    if (M2C_FIELD(arg0, u8 *, 0x34) & 1) {
        func_01ffa8c4(arg0, 0xB);
        return;
    }
    func_01ffa8c4(arg0, 0x10);
}

void func_ov010_0222b01c(void *arg0) {
    M2C_UNK func_0208af20();
    s32 func_0208b5ec();
    s32 func_ov010_02229f64();
    if (func_ov010_02229f64() != 0) {
        return;
    }
    if (((s32) M2C_FIELD(arg0, s8 *, 0x35) >= 0) && (func_0208b5ec() != 0)) {
        func_0208af20();
    }
    if (M2C_FIELD(arg0, u8 *, 0x34) & 1) {
        func_01ffa8c4(arg0, 0xB);
        return;
    }
    func_01ffa8c4(arg0, 0x10);
}

void func_ov010_0222b074(void) {
    M2C_UNK func_ov010_02228a70();
    func_ov010_02228a70();
}

void func_ov010_0222b080(void) {
    M2C_UNK func_ov010_02228714();
    func_ov010_02228714();
}

void func_ov010_0222b08c(M2C_UNK arg0) {
    s32 func_ov010_02228720();
    if (func_ov010_02228720() != 0) {
        return;
    }
    func_01ffa8c4(arg0, 0x12);
}

void func_ov010_0222b0b0(void *arg0) {
    s32 func_020abe90(M2C_UNK);
    M2C_UNK func_020ad348(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if ((M2C_FIELD(arg0, u8 *, 0x34) & 2) && (func_020abe90(0) == 0)) {
        func_020ad348(2, 8, 0, arg0);
    }
    if (!(M2C_FIELD(arg0, u8 *, 0x34) & 4)) {
        return;
    }
    if (func_020abe90(1) != 0) {
        return;
    }
    func_020ad348(2, 8, 1, arg0);
}

void func_ov010_0222b11c(M2C_UNK arg0) {
    M2C_UNK func_020c4cdc();
    M2C_UNK func_020c4dd0(M2C_UNK);
    func_020c4cdc();
    func_020c4dd0(arg0);
    func_01ffa8c4(arg0, 1);
}

/* Refresh the entity's sprite on the selected display banks, then queue command 19. */
void func_ov010_0222b140(void *entity) {
M2C_UNK func_020899cc(void *,M2C_UNK,s32,s32);void *func_0208b564(void *);
extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine;
s32 savedBank;u32 bank;s32 i;s8 mode;void *created;
if(M2C_FIELD(entity,s8 *,0x35)>=0&&func_0208b5ec())func_0208af20();
if(M2C_FIELD(entity,s8 *,0x35)>=0){
savedBank=gCur3DSpriteEngine;i=0;
do {
if(i==0)bank=data_027e00c8;else bank=data_027e00c4;
gCur3DSpriteEngine=bank;mode=M2C_FIELD(entity,s8 *,0x35);
if(mode==0&&bank!=data_027e00c8)continue;
if(mode==1&&bank!=data_027e00c4)continue;
if(mode==3&&bank!=savedBank)continue;
created=func_0208b564(entity);
func_020899cc(created,2,M2C_FIELD(entity,u16 *,0x36)<<5,0x4200001f);
M2C_FIELD(created,s32 *,0x58)|=0x1000;
}while(++i<2);
gCur3DSpriteEngine=savedBank;
}
func_01ffa8c4((s32)entity,19);
}

void func_ov010_0222b234(void *arg0) {
M2C_UNK func_020899cc(void *,M2C_UNK,s32,s32);void *func_0208b520(void *);M2C_UNK func_01ffa8c4(s32,s32);
extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine;
s32 old;u32 current;s32 i;s8 mode;void *p;
if(M2C_FIELD(arg0,s8 *,0x35)>=0){
old=gCur3DSpriteEngine;i=0;
do {
if(i==0)current=data_027e00c8;else current=data_027e00c4;
gCur3DSpriteEngine=current;mode=M2C_FIELD(arg0,s8 *,0x35);
if(mode==0&&current!=data_027e00c8)continue;
if(mode==1&&current!=data_027e00c4)continue;
if(mode==3&&current!=old)continue;
p=func_0208b520(arg0);
func_020899cc(p,0,M2C_FIELD(arg0,u16 *,0x36)<<5,0x4200001e);
M2C_FIELD(p,s32 *,0x58)=((M2C_FIELD(p,s32 *,0x58)|0x1000)&~0x400)|0x800;
}while(++i<2);
gCur3DSpriteEngine=old;
}
func_01ffa8c4((s32)arg0,7);
}

/* Creates a draw entry in both active banks when the entity's bank selector allows. */
void func_ov010_0222b314(void *entity) {
    s32 func_02037c90();
    M2C_UNK func_020899cc(void *, M2C_UNK, s32, s32);
    void *func_0208b564(void *);
    M2C_UNK func_01ffa8c4(M2C_UNK, M2C_UNK);
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    extern s32 gCur3DSpriteEngine;
    void *created;
    s32 bank;
    s32 i;
    s8 mode;
    s32 savedBank;

    if ((func_02037c90() == 2) || (M2C_FIELD(entity, s8 *, 0x3C) != 0)) {
        if ((s32) M2C_FIELD(entity, s8 *, 0x35) >= 0) {
            savedBank = gCur3DSpriteEngine;
            for (i = 0; i < 2; ++i) {
                if (i == 0) {
                    bank = data_027e00c8;
                } else {
                    bank = data_027e00c4;
                }
                gCur3DSpriteEngine = bank;
                mode = M2C_FIELD(entity, s8 *, 0x35);
                if (mode == 0 && bank != data_027e00c8) {
                    continue;
                }
                if (mode == 1 && bank != data_027e00c4) {
                    continue;
                }
                if (mode == 3 && bank != savedBank) {
                    continue;
                }
                created = func_0208b564(entity);
                func_020899cc(created, 2, M2C_FIELD(entity, u16 *, 0x36) << 5, 0x4200001C);
                M2C_FIELD(created, s32 *, 0x58) = (s32) (M2C_FIELD(created, s32 *, 0x58) | 0x1000);
            }
            gCur3DSpriteEngine = savedBank;
        }
        func_01ffa8c4(entity, 0x11);
        return;
    }
    func_01ffa8c4(entity, 2);
}

void func_ov010_0222b414(void) {

}

void func_ov010_0222b418(void *arg0) {
    M2C_UNK func_020899cc(void *, M2C_UNK, s32, s32);
    void *func_0208b564(void *);
    extern s32 data_027e00c4;
    extern s32 data_027e00c8;
    M2C_UNK func_020c4a74(M2C_UNK);
    extern s32 gCur3DSpriteEngine;
    s8 temp_r1;
    s32 var_r8;
    s32 var_r2;
    register unsigned long temp_r9;
    void *temp_r0;

    if (func_020d4810() != 0) {
        func_020c4a74(0);
        M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 1);
        func_01ffa8c4(arg0, 3);
        return;
    }
    if (M2C_FIELD(arg0, s8 *, 0x35) >= 0) {
        temp_r9 = gCur3DSpriteEngine;
        var_r8 = 0;
        do {
            if (var_r8 == 0) {
                var_r2 = data_027e00c8;
            } else {
                var_r2 = data_027e00c4;
            }
            gCur3DSpriteEngine = var_r2;
            temp_r1 = M2C_FIELD(arg0, s8 *, 0x35);
            switch (temp_r1) {                      /* irregular */
            case 0:
                if (var_r2 == data_027e00c8) {
                    if (((temp_r1 != 1) || (var_r2 == data_027e00c4)) && ((temp_r1 != 3) || (var_r2 == temp_r9))) {
                    default:
                        temp_r0 = func_0208b564(arg0);
                        func_020899cc(temp_r0, 2, M2C_FIELD(arg0, u16 *, 0x36) << 5, 0x42000017);
                        M2C_FIELD(temp_r0, s32 *, 0x58) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x58) | 0x1000);
                    }
                }
                break;
            }
            var_r8++;
        } while (2 > var_r8);
        gCur3DSpriteEngine = temp_r9;
    }
    func_01ffa8c4(arg0, 0xC);
}

void func_ov010_0222b520(void *arg0) {
M2C_UNK func_020899cc(void *,M2C_UNK,s32,s32);void *func_0208b564(void *);M2C_UNK func_01ffa8c4(s32,s32);M2C_UNK func_0208ae88(void *,s32);
extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine;
s32 old;u32 current;s32 i;s8 mode;void *p;
if(M2C_FIELD(arg0,s8 *,0x35)>=0){
old=gCur3DSpriteEngine;i=0;
do {
if(i==0)current=data_027e00c8;else current=data_027e00c4;
gCur3DSpriteEngine=current;mode=M2C_FIELD(arg0,s8 *,0x35);
if(mode==0&&current!=data_027e00c8)continue;
if(mode==1&&current!=data_027e00c4)continue;
if(mode==3&&current!=old)continue;
p=func_0208b564(arg0);
func_020899cc(p,3,M2C_FIELD(arg0,u16 *,0x36)<<5,0x4200001a);
M2C_FIELD(p,s32 *,0x58)|=0x1000;
func_0208ae88(p,1);
}while(++i<2);
gCur3DSpriteEngine=old;
}
func_01ffa8c4((s32)arg0,14);
}

void func_ov010_0222b604(void *arg0) {
M2C_UNK func_020899cc(void *,M2C_UNK,s32,s32);void *func_0208b564(void *);
extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine;
s32 old;u32 current;s32 i;s8 mode;void *p;
if(func_020d4810()){
if(M2C_FIELD(arg0,s8 *,0x35)<0)return;
old=gCur3DSpriteEngine;i=0;
do {
if(i==0)current=data_027e00c8;else current=data_027e00c4;
gCur3DSpriteEngine=current;mode=M2C_FIELD(arg0,s8 *,0x35);
if(mode==0&&current!=data_027e00c8)continue;
if(mode==1&&current!=data_027e00c4)continue;
if(mode==3&&current!=old)continue;
p=func_0208b564(arg0);
func_020899cc(p,2,M2C_FIELD(arg0,u16 *,0x36)<<5,0x42000019);
M2C_FIELD(p,s32 *,0x58)|=0x1000;
}while(++i<2);
gCur3DSpriteEngine=old;return;
}
func_01ffa8c4((s32)arg0,1);
}

void func_ov010_0222b6ec(void *arg0) {
M2C_UNK func_020899cc(void *,M2C_UNK,s32,s32);void *func_0208b564(void *);
extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine;
s32 old;u32 current;s32 i;s8 mode;void *p;
if(M2C_FIELD(arg0,s8 *,0x35)>=0){
old=gCur3DSpriteEngine;i=0;
do {
if(i==0)current=data_027e00c8;else current=data_027e00c4;
gCur3DSpriteEngine=current;mode=M2C_FIELD(arg0,s8 *,0x35);
if(mode==0&&current!=data_027e00c8)continue;
if(mode==1&&current!=data_027e00c4)continue;
if(mode==3&&current!=old)continue;
p=func_0208b564(arg0);
func_020899cc(p,3,M2C_FIELD(arg0,u16 *,0x36)<<5,0x42000018);
M2C_FIELD(p,s32 *,0x58)|=0x1000;
func_0208ae88(p,1);
}while(++i<2);
gCur3DSpriteEngine=old;
}
func_01ffa8c4((s32)arg0,13);
}

void func_ov010_0222b7d0(M2C_UNK arg0) {
    func_01ffa8c4(arg0, 0x10);
}

void func_ov010_0222b7e0(void *arg0) {
M2C_UNK func_020899cc(void *,M2C_UNK,s32,s32);void *func_0208b564(void *);
extern s32 data_027e00c4,data_027e00c8,gCur3DSpriteEngine;
s32 old;u32 current;s32 i;s8 mode;void *p;
if(M2C_FIELD(arg0,s8 *,0x35)<0)return;
old=gCur3DSpriteEngine;i=0;
do {
if(i==0)current=data_027e00c8;else current=data_027e00c4;
gCur3DSpriteEngine=current;mode=M2C_FIELD(arg0,s8 *,0x35);
if(mode==0&&current!=data_027e00c8)continue;
if(mode==1&&current!=data_027e00c4)continue;
if(mode==3&&current!=old)continue;
p=func_0208b564(arg0);
func_020899cc(p,2,M2C_FIELD(arg0,u16 *,0x36)<<5,0x42000016);
M2C_FIELD(p,s32 *,0x58)|=0x1000;
}while(++i<2);
gCur3DSpriteEngine=old;
}

void func_ov010_0222b8ac(void *arg0) {
    if (func_020d4810() != 0) {
        M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 1);
        func_01ffa8c4(arg0, 3);
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void func_ov010_0222b8ec(M2C_UNK arg0) {
    s32 func_020d4810();
    if (func_020d4810() != 0) {
        func_01ffa8c4(arg0, 3);
        return;
    }
    func_01ffa8c4(arg0, 1);
}

void func_ov010_0222b91c(M2C_UNK arg0) {
    M2C_UNK func_01ffa8c4(M2C_UNK, M2C_UNK);
    func_01ffa8c4(arg0, 1);
}

void func_ov010_0222b92c(void *arg0) {
    M2C_UNK func_020ad2a0(M2C_UNK, M2C_UNK, M2C_UNK, void *);
    if (func_020abe90(0) == 1) {
        func_020ad2a0(2, 8, 0, arg0);
        M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 2);
    }
    if (func_020abe90(1) != 1) {
        return;
    }
    func_020ad2a0(2, 8, 1, arg0);
    M2C_FIELD(arg0, u8 *, 0x34) = (u8) (M2C_FIELD(arg0, u8 *, 0x34) | 4);
}

void func_ov010_0222b998(void) {
    M2C_UNK func_020852a8();
    M2C_UNK func_020d47f0();
    M2C_UNK func_ov010_022282d4(M2C_UNK);
    M2C_UNK func_ov010_02228320();
    func_020d47f0();
    func_ov010_02228320();
    func_ov010_022282d4(6);
    func_020852a8();
}

void func_ov010_0222b9b4(void) {
    M2C_UNK func_020852e0();
    M2C_UNK func_020d47d0();
    s32 func_ov010_022282b4(M2C_UNK);
    if (func_ov010_022282b4(2) != 0) {
        func_020d47d0();
        return;
    }
    func_020d47f0();
    func_020852e0();
}

