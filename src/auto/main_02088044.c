/* 38 functions from 0x02088044 to 0x02088FF4 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u32 words[2]; } Unk0200FilePair;

void func_02088044(void *arg0) {
    void *func_02087e68();
    M2C_UNK func_02087ea0(void *, void *);
    s32 func_02087f20(void *, void *, u16, u16);
    s32 func_02087f70(void *, u16, u16);
    extern void *data_02101e88;
    void *temp_r1_3;
    s8 temp_r1_2;
    u16 temp_r0;
    u16 temp_r1;
    u16 temp_r2;
    u16 var_r0;
    u16 var_r0_2;
    u8 temp_r0_5;
    void *temp_r0_2;
    void *temp_r0_3;
    void *var_r4;
    s32 var_r5;
    void *temp_r0_4;

    M2C_FIELD(arg0, s8 *, 0xA) = -1;
    M2C_FIELD(arg0, s8 *, 9) = -1;
    M2C_FIELD(arg0, s8 *, 0xB) = -1;
    var_r5 = 0;
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    M2C_FIELD(arg0, s8 *, 0xC) = -1;
    if (M2C_FIELD(data_02101e88, u8 *, 0x12) != 0) {
        var_r4 = M2C_FIELD(arg0, void **, 0x14);
        if ((s32) M2C_FIELD(arg0, u16 *, 0x10) > 0) {
loop_2:
            if ((M2C_FIELD(var_r4, u16 *, 0xA) != 0) && (func_02087f20(arg0, var_r4, M2C_FIELD(data_02101e88, u16 *, 0), M2C_FIELD(data_02101e88, u16 *, 2)) != 0)) {
                if (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0) {
                    M2C_FIELD(arg0, s8 *, 8) = (s8) M2C_FIELD(var_r4, u16 *, 8);
                    M2C_FIELD(arg0, u8 *, 0xE) = 0U;
                    temp_r0 = M2C_FIELD(var_r4, u16 *, 0xA);
                    if (temp_r0 & 1) {
                        if (temp_r0 & 0x20) {
                            temp_r0_2 = M2C_FIELD(arg0, void **, 0);
                            if ((temp_r0_2 != NULL) && (temp_r1 = M2C_FIELD(var_r4, u16 *, 8), (temp_r1 == M2C_FIELD(temp_r0_2, u16 *, 8)))) {
                                M2C_FIELD(arg0, s8 *, 0xB) = (s8) temp_r1;
                            } else {
                                func_02087ea0(arg0, var_r4);
                            }
                        } else {
                            M2C_FIELD(arg0, s8 *, 0xB) = (s8) M2C_FIELD(var_r4, u16 *, 8);
                            func_02087ea0(arg0, var_r4);
                        }
                    } else if (temp_r0 & 0xC) {
                        func_02087ea0(arg0, var_r4);
                    }
                } else {
                    temp_r2 = M2C_FIELD(var_r4, u16 *, 8);
                    if (temp_r2 == M2C_FIELD(arg0, s8 *, 8)) {
                        if ((M2C_FIELD(data_02101e88, u8 *, 0x13) != 0) && (M2C_FIELD(var_r4, u16 *, 0xA) & 0x10)) {
                            M2C_FIELD(arg0, s8 *, 0xB) = (s8) temp_r2;
                            M2C_FIELD(arg0, u8 *, 0xE) = 1U;
                        }
                    } else {
                        M2C_FIELD(arg0, s8 *, 8) = -1;
                        if (M2C_FIELD(data_02101e88, u8 *, 0x13) != 0) {
                            M2C_FIELD(arg0, u8 *, 0xE) = 1U;
                            if (M2C_FIELD(var_r4, u16 *, 0xA) & 0x10) {
                                M2C_FIELD(arg0, s8 *, 0xB) = (s8) M2C_FIELD(var_r4, u16 *, 8);
                            }
                        } else {
                            M2C_FIELD(arg0, u8 *, 0xE) = 0U;
                        }
                        if (M2C_FIELD(var_r4, u16 *, 0xA) & 8) {
                            func_02087ea0(arg0, var_r4);
                        }
                    }
                }
                M2C_FIELD(arg0, s8 *, 0xC) = (s8) M2C_FIELD(var_r4, u16 *, 8);
            } else {
                var_r5 += 1;
                var_r4 += 0xC;
                if (var_r5 < (s32) M2C_FIELD(arg0, u16 *, 0x10)) {
                    goto loop_2;
                }
            }
        }
        if (var_r5 == M2C_FIELD(arg0, u16 *, 0x10)) {
            if ((M2C_FIELD(arg0, u16 *, 0x22) != 0) && (func_02087f70(arg0, M2C_FIELD(data_02101e88, u16 *, 0), M2C_FIELD(data_02101e88, u16 *, 2)) != 0)) {
                if (M2C_FIELD(data_02101e88, u8 *, 0x14) != 0) {
                    M2C_FIELD(arg0, s8 *, 8) = -2;
                    M2C_FIELD(arg0, u8 *, 0xE) = 0U;
                    if (M2C_FIELD(arg0, u16 *, 0x22) & 1) {
                        M2C_FIELD(arg0, s8 *, 0xD) = 1;
                    }
                } else if (M2C_FIELD(arg0, s8 *, 8) == -2) {
                    M2C_FIELD(arg0, u8 *, 0xE) = 0U;
                } else {
                    M2C_FIELD(arg0, s8 *, 8) = -1;
                    M2C_FIELD(arg0, u8 *, 0xE) = 0U;
                }
            } else {
                M2C_FIELD(arg0, s8 *, 8) = -1;
                M2C_FIELD(arg0, u8 *, 0xE) = 0U;
            }
        }
    } else if (M2C_FIELD(data_02101e88, u8 *, 0x16) != 0) {
        temp_r1_2 = M2C_FIELD(arg0, s8 *, 8);
        if ((temp_r1_2 != -1) && ((u32) M2C_FIELD(data_02101e88, u8 *, 0x10) < 0x1EU)) {
            if (temp_r1_2 != -2) {
                temp_r0_3 = func_02087e68();
                if ((func_02087f20(arg0, temp_r0_3, M2C_FIELD(data_02101e88, u16 *, 0), M2C_FIELD(data_02101e88, u16 *, 2)) != 0) && (M2C_FIELD(temp_r0_3, u16 *, 0xA) & 2)) {
                    if (M2C_FIELD(arg0, u8 *, 0xE) == 0) {
                        M2C_FIELD(arg0, s8 *, 0xB) = (s8) M2C_FIELD(arg0, s8 *, 8);
                    }
                }
            } else if ((func_02087f70(arg0, M2C_FIELD(data_02101e88, u16 *, 0), M2C_FIELD(data_02101e88, u16 *, 2)) != 0) && (M2C_FIELD(arg0, u16 *, 0x22) & 2)) {
                M2C_FIELD(arg0, s8 *, 0xD) = 1;
            }
        }
        M2C_FIELD(arg0, s8 *, 8) = -1;
        M2C_FIELD(arg0, u8 *, 0xE) = 0U;
    } else {
        M2C_FIELD(arg0, s8 *, 8) = -1;
        M2C_FIELD(arg0, u8 *, 0xE) = 0U;
    }
    if (M2C_FIELD(arg0, u8 *, 0xF) == 0) {
        temp_r1_3 = M2C_FIELD(arg0, void **, 4);
        if (temp_r1_3 != M2C_FIELD(arg0, void **, 0)) {
            if (temp_r1_3 != NULL) {
                var_r0 = M2C_FIELD(temp_r1_3, u16 *, 8);
            } else {
                var_r0 = -1U;
            }
            M2C_FIELD(arg0, s8 *, 0xA) = (s8) var_r0;
            temp_r0_4 = M2C_FIELD(arg0, void **, 0);
            if (temp_r0_4 != NULL) {
                var_r0_2 = M2C_FIELD(temp_r0_4, u16 *, 8);
            } else {
                var_r0_2 = -1U;
            }
            M2C_FIELD(arg0, s8 *, 9) = (s8) var_r0_2;
        }
    }
    temp_r0_5 = M2C_FIELD(arg0, u8 *, 0xF);
    if ((u32) temp_r0_5 < 0xFFU) {
        M2C_FIELD(arg0, u8 *, 0xF) = (u8) (temp_r0_5 + 1);
    }
}

void func_020883bc(void) {
    M2C_UNK func_020883f0(M2C_UNK);
    extern M2C_UNK data_021577b4;
    s32 i;
    u8 *p;
    i = 0;
    p = (u8 *)&data_021577b4;
    do {
        *p++ = 0;
        i++;
    } while (i < 12);
    func_020883f0(0);
    func_020883f0(4);
}

M2C_UNK func_020883f0(M2C_UNK a) {
extern M2C_UNK data_021577b4,data_0210259c;
s32 func_0200c084(void *,s32,s32);void func_0200b774(void *);void func_0200bf64(void *,void *);
s32 func_0200b9e4(void *,Unk0200FilePair);void func_0200bf28(void *);s32 func_0200bbe0(void *,void *,s32);void func_0200ba9c(void *);void func_0200c214(void *);M2C_UNK func_020e349c(void);
Unk0200FilePair pair;u32 info[11];u32 file[18];s32 size;u8 *dest; s32 offset,n; u32 flag;
flag=((u8 *)&data_021577b4)[a]; if(flag==1)return flag;
if(!func_0200c084(info,0,((s32 *)&data_0210259c)[a]))return;
func_0200b774(file);func_0200bf64(&pair,info);
if(!func_0200b9e4(file,pair))return;
func_0200bf28(info);size=file[10]-file[9];dest=(u8 *)info[1];
for(offset=0;offset<size;offset+=0x2800){n=size-offset;if(n>=0x2800)n=0x2800;if(n!=func_0200bbe0(file,dest+offset,n)){func_0200ba9c(file);return;}}
func_0200ba9c(file);func_0200c214(info);((u8 *)&data_021577b4)[a]=1;func_020e349c();
}

void func_020884f8(u8 a){s32 func_0200c408(M2C_UNK,s32);M2C_UNK func_020e349c();extern M2C_UNK data_0210259c,data_021577b4;
if(M2C_FIELD(&data_021577b4,u8 *,a)==0)return;
if(func_0200c408(0,((s32 *)&data_0210259c)[a])==1)M2C_FIELD(&data_021577b4,u8 *,a)=0;
func_020e349c();}

void func_0208853c(s32 arg0) {
    extern M2C_UNK data_02102590;
    s32 i;
    u8 *p;
    p = (u8 *)&data_02102590;
    i = 0;
    do {
        if ((*p & ((u8 *)&data_02102590)[arg0]) && func_0208858c((u8)i) != 0) func_020884f8(i);
        i++;
        p++;
    } while (i < 12);
}

s32 func_0208858c(s32 arg0) {
    extern M2C_UNK data_021577b4;
    return M2C_FIELD(&data_021577b4, u8 *, arg0);
}

void func_0208859c(void){if(func_0208858c(0)!=0)return;func_0208853c(0);func_020883f0(0);}

void func_020885c4(void){if(func_0208858c(2)!=0)return;func_0208853c(2);func_020883f0(2);}

void func_020885ec(void) {
    func_020884f8(2);
}

void func_020885fc(void) {
    if (func_0208858c(3) != 0) {
        return;
    }
    func_0208853c(3);
    func_020883f0(3);
}

void func_02088624(void) {
    func_020884f8(3);
}

void func_02088634(void) {
    if (func_0208858c(4) != 0) {
        return;
    }
    func_0208853c(4);
    func_020883f0(4);
}

void func_0208865c(void) {
    if (func_0208858c(5) != 0) {
        return;
    }
    func_0208853c(5);
    func_020883f0(5);
}

void func_02088684(void) {
    if (func_0208858c(6) != 0) {
        return;
    }
    func_0208853c(6);
    func_020883f0(6);
}

void func_020886ac(void) {
    if (func_0208858c(7) != 0) {
        return;
    }
    func_0208853c(7);
    func_020883f0(7);
}

void func_020886d4(void) {
    if (func_0208858c(9) != 0) {
        return;
    }
    func_0208853c(9);
    func_020883f0(9);
}

void func_020886fc(void) {
    if (func_0208858c(0xA) != 0) {
        return;
    }
    func_0208853c(0xA);
    func_020883f0(0xA);
}

void func_02088724(void) {
    if (func_0208858c(1) != 0) {
        return;
    }
    func_0208853c(1);
    func_020883f0(1);
}

void func_0208874c(void) {
    if (func_0208858c(0xB) != 0) {
        return;
    }
    func_0208853c(0xB);
    func_020883f0(0xB);
}

#pragma optimization_level 4
void func_02088774(s32 a) { void func_02007e20(void *,s32,s32); extern u8 data_021577c0[]; extern void *gCur3DSpriteEngine; s32 offset=(a<<5)&~1; void *p=gCur3DSpriteEngine; func_02007e20(data_021577c0,offset+M2C_FIELD(p,s32 *,0x30),32); }
#pragma optimization_level reset
void func_020887a8(void *p,s32 a,s32 b,s32 c,s32 d){void func_020887ec(void *);s32 x=M2C_FIELD(p,s16 *,0x34),y=M2C_FIELD(p,s16 *,0x36),z=M2C_FIELD(p,s8 *,0x49),w=M2C_FIELD(p,s32 *,0x44);M2C_FIELD(p,s16 *,0x34)=a;M2C_FIELD(p,s16 *,0x36)=b;M2C_FIELD(p,s8 *,0x49)=c;M2C_FIELD(p,s32 *,0x44)=d;func_020887ec(p);M2C_FIELD(p,s16 *,0x34)=x;M2C_FIELD(p,s16 *,0x36)=y;M2C_FIELD(p,s8 *,0x49)=z;M2C_FIELD(p,s32 *,0x44)=w;}

void func_020887ec(void *p){
s32 func_01ff8f90(s32,s32,s32);void func_01ffaacc(u16,u16,u16,s32,s32);
extern void *gCur3DSpriteEngine,*data_027e00c4,*data_027e00c8;
void *saved,*bank; s32 i;u32 mode,flags;u16 x,y,attr,pal;u32 shift,tile,part,header;
if(M2C_FIELD(p,s32 *,0x44)==0)return;
if((M2C_FIELD(p,u32 *,0x40)>>26)==0)return;
if(((u32)(M2C_FIELD(p,u8 *,0x48)<<31)>>31)==0)return;
if(!func_01ff8f90(M2C_FIELD(p,s16 *,0x34)+M2C_FIELD(p,s16 *,0x38),M2C_FIELD(p,s16 *,0x36)+M2C_FIELD(p,s16 *,0x3a),M2C_FIELD(p,s32 *,0x44)))return;
saved=gCur3DSpriteEngine;
i=0;do{
if(i==0)bank=data_027e00c8;else bank=data_027e00c4;
gCur3DSpriteEngine=bank;mode=(u32)(M2C_FIELD(p,u8 *,0x48)<<28)>>29;
if((mode!=0||bank==data_027e00c8)&&(mode!=1||bank==data_027e00c4)&&(mode!=3||bank==saved)){
header=M2C_FIELD(M2C_FIELD(bank,void **,0),u16 *,0);
flags=M2C_FIELD(p,u32 *,0x40);
pal=(u16)((flags<<6)>>24);
tile=M2C_FIELD(p,u16 *,0x3e);
shift=(header<<17)>>30;
part=(tile>>shift)&0x3ff;
part|=(u16)(pal<<12);
attr=(u16)(part|M2C_FIELD(p,u16 *,0x3c));

y=(M2C_FIELD(p,s16 *,0x36)+M2C_FIELD(p,s16 *,0x3a))&255;
if((flags>>26)!=16)y|=0x400;
func_01ffaacc((u16)((M2C_FIELD(p,s16 *,0x34)+M2C_FIELD(p,s16 *,0x38))&0x1ff),y,attr,M2C_FIELD(p,s32 *,0x44),M2C_FIELD(p,s8 *,0x49));
}i++;}while(i<2);gCur3DSpriteEngine=saved;
}

void func_02088964(void *arg0) {
}

void func_02088c78(void *p) {
void func_02088d94(void *);void func_02088da8(void *);s32 func_0207ca38(s32,s32,s32,s32,s32);
s32 mode,n,t;
mode=(u32)(M2C_FIELD(p,u8 *,0x48)<<24)>>30;
if(!mode)return;
n=1;t=0;
if(M2C_FIELD(p,u8 *,0x4d)){M2C_FIELD(p,u8 *,0x4d)--;return;}
if(M2C_FIELD(p,u8 *,0x4c)==0 && mode==2)func_02088d94(p);
M2C_FIELD(p,u8 *,0x4c)++;
switch((u32)(M2C_FIELD(p,u8 *,0x48)<<24)>>30){
case 1:n=M2C_FIELD(p,u8 *,0x4e);t=M2C_FIELD(p,u8 *,0x4c);break;
case 2:n=M2C_FIELD(p,u8 *,0x4e);t=M2C_FIELD(p,u8 *,0x4c);break;
case 3:n=M2C_FIELD(p,u8 *,0x4f);t=n-M2C_FIELD(p,u8 *,0x4c);break;
}
M2C_FIELD(p,s16 *,0x34)=func_0207ca38(4,M2C_FIELD(p,s16 *,0x54),M2C_FIELD(p,s16 *,0x50),t,n);
M2C_FIELD(p,s16 *,0x36)=func_0207ca38(4,M2C_FIELD(p,s16 *,0x56),M2C_FIELD(p,s16 *,0x52),t,n);
if(M2C_FIELD(p,u8 *,0x4c)<n)return;
if(((u32)(M2C_FIELD(p,u8 *,0x48)<<24)>>30)==3)func_02088da8(p);
M2C_FIELD(p,u8 *,0x48)&=~0xc0;
}

void func_02088d94(void *p){M2C_FIELD(p,u8 *,0x48)=(M2C_FIELD(p,u8 *,0x48)&~1)|1;}

void func_02088da8(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x48) = (u8) (M2C_FIELD(arg0, u8 *, 0x48) & ~1);
}

void func_02088db8(void *p,s32 a){void func_02088d94(void *);if(!a){func_02088d94(p);M2C_FIELD(p,u32 *,0x40)=(M2C_FIELD(p,u32 *,0x40)&~0xfc000000)|0x40000000;M2C_FIELD(p,u8 *,0x48)&=~0x30;return;}M2C_FIELD(p,u8 *,0x4b)=0;M2C_FIELD(p,u8 *,0x4a)=a;M2C_FIELD(p,u8 *,0x48)=(M2C_FIELD(p,u8 *,0x48)&~0x30)|0x10;}

void func_02088e0c(void *p,s32 a){void func_02088da8(void *);if(!a){func_02088da8(p);M2C_FIELD(p,u32 *,0x40)&=~0xfc000000;M2C_FIELD(p,u8 *,0x48)&=~0x30;return;}M2C_FIELD(p,u8 *,0x4b)=0;M2C_FIELD(p,u8 *,0x4a)=a;M2C_FIELD(p,u8 *,0x48)=(M2C_FIELD(p,u8 *,0x48)&~0x30)|0x20;}

void func_02088e5c(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x50) = arg1;
    M2C_FIELD(arg0, s16 *, 0x52) = arg2;
}

void func_02088e68(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x4E) = arg1;
}

void func_02088e70(void *arg0, s16 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x54) = arg1;
    M2C_FIELD(arg0, s16 *, 0x56) = arg2;
}

void func_02088e7c(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 0x4F) = arg1;
}

void func_02088e84(void *p,s16 a,s16 b,s16 c,s32 d){func_02088e5c(p,a,b);func_02088e70(p,c,d);}

void func_02088ea8(void *p,s16 a,s32 b,s32 c,s32 d,s32 e){void func_02088f1c(void *);func_02088e5c(p,c,d);func_02088e70(p,a,b);func_02088e68(p,e);func_02088f1c(p);}

void func_02088eec(void *p,s8 a){void func_02088f1c(void *);func_02088e5c(p,M2C_FIELD(p,s16 *,0x50),M2C_FIELD(p,s16 *,0x52));func_02088e68(p,a);func_02088f1c(p);}

void func_02088f1c(void *p){if(!M2C_FIELD(p,u8 *,0x4e)){M2C_FIELD(p,s16 *,0x34)=M2C_FIELD(p,s16 *,0x50);M2C_FIELD(p,s16 *,0x36)=M2C_FIELD(p,s16 *,0x52);M2C_FIELD(p,s8 *,0x4d)=0;M2C_FIELD(p,u8 *,0x48)&=~0xc0;func_02088d94(p);return;}if(((u32)(M2C_FIELD(p,u8 *,0x48)<<24)>>30)==2)return;M2C_FIELD(p,s8 *,0x4c)=0;M2C_FIELD(p,s8 *,0x4d)=0;M2C_FIELD(p,u8 *,0x48)=(M2C_FIELD(p,u8 *,0x48)&~0xc0)|0x80;}

void func_02088f8c(void *p,s32 a,s32 b,s16 c,s32 d,s32 e){void func_02088ff4(void *);func_02088e5c(p,a,b);func_02088e70(p,c,d);func_02088e7c(p,e);func_02088ff4(p);}

void func_02088fc4(void *p,s8 a){void func_02088ff4(void *);func_02088e70(p,M2C_FIELD(p,s16 *,0x54),M2C_FIELD(p,s16 *,0x56));func_02088e7c(p,a);func_02088ff4(p);}

