/* 16 functions from 0x022153FC to 0x022162F4 (ov006), found by ds-decomp. */
#include "common.h"

extern s8 data_ov006_02218345[];
extern s8 data_ov006_02218e10[];
void *func_ov006_02215620(void *arg0){
extern M2C_UNK data_ov006_02218610;
M2C_UNK func_01ffa574(M2C_UNK);M2C_UNK func_02082040(M2C_UNK);M2C_UNK func_020e4ca0();
s32 *arr;void *p=arg0;
M2C_FIELD(p,void **,0)=&data_ov006_02218610;
arr=M2C_FIELD(p,s32 **,0x3c);
if(arr){func_01ffa574(arr[0]);func_01ffa574(arr[1]);func_01ffa574(arr[2]);func_01ffa574(arr[3]);func_01ffa574(arr[4]);func_01ffa574(arr[5]);func_02082040((s32)arr);}
arr=M2C_FIELD(p,void **,0x40);if(arr)M2C_FIELD(M2C_FIELD(arr,void **,0),void (**)(void *),4)((void *)arr);
arr=M2C_FIELD(p,void **,0x44);if(arr)M2C_FIELD(M2C_FIELD(arr,void **,0),void (**)(void *),4)((void *)arr);
arr=M2C_FIELD(p,void **,0x48);if(arr)func_02082040((s32)arr);
arr=M2C_FIELD(p,void **,0x4c);if(arr)M2C_FIELD(M2C_FIELD(arr,void **,0),void (**)(void *),4)((void *)arr);
func_020e4ca0();func_02082040((s32)p);return p;
}

void *func_ov006_022156e4(void *arg0) {
    M2C_UNK func_01ffa574(M2C_UNK);
    M2C_UNK func_02082040(M2C_UNK);
    M2C_UNK func_020e4ca0();
    extern M2C_UNK data_ov006_02218610;
    void *p;
    void *self;

    self = arg0;
    M2C_FIELD(self, void **, 0) = &data_ov006_02218610;
    p = M2C_FIELD(self, void **, 0x3C);
    if (p != NULL) {
        func_01ffa574(M2C_FIELD(p, void **, 0));
        func_01ffa574(M2C_FIELD(p, void **, 4));
        func_01ffa574(M2C_FIELD(p, void **, 8));
        func_01ffa574(M2C_FIELD(p, void **, 0xC));
        func_01ffa574(M2C_FIELD(p, void **, 0x10));
        func_01ffa574(M2C_FIELD(p, void **, 0x14));
        func_02082040(p);
    }
    p = M2C_FIELD(self, void **, 0x40);
    if (p != NULL) {
        M2C_FIELD(M2C_FIELD(p, void **, 0), void (**)(void *), 4)(p);
    }
    p = M2C_FIELD(self, void **, 0x44);
    if (p != NULL) {
        M2C_FIELD(M2C_FIELD(p, void **, 0), void (**)(void *), 4)(p);
    }
    p = M2C_FIELD(self, void **, 0x48);
    if (p != NULL) {
        func_02082040(p);
    }
    p = M2C_FIELD(self, void **, 0x4C);
    if (p != NULL) {
        M2C_FIELD(M2C_FIELD(p, void **, 0), void (**)(void *), 4)(p);
    }
    func_020e4ca0();
    return self;
}

void func_ov006_02215950(u8 *arg0) {
    M2C_UNK func_020b1c60(u8);
    void func_ov006_02215ae0(void *);
    extern void *data_02101e84;
    u8 temp_r1;
    u16 temp_r3;
    u16 temp_r2;
    u8 var_ip;

    temp_r1 = *arg0;
    temp_r3 = M2C_FIELD(data_02101e84, u16 *, 0);
    var_ip = temp_r1;
    temp_r2 = M2C_FIELD(data_02101e84, u16 *, 2);
    if (temp_r3 & 1) {
        func_ov006_02215ae0(arg0);
        return;
    }
    if (temp_r2 & 0x40) {
        if (temp_r1 == 0) {
            if (temp_r2 == temp_r3) {
                var_ip = 0xC;
            }
        } else if (temp_r1 == 1) {
            if (temp_r2 == temp_r3) {
                var_ip = 0xD;
            }
        } else if (temp_r1 == 2) {
            if (temp_r2 == temp_r3) {
                var_ip = 0xD;
            }
        } else {
            var_ip = (u8)(temp_r1 - 3);
        }
        if ((u8)var_ip >= 0xA) goto done;
        goto middle;
    } else if (temp_r2 & 0x80) {
        if (temp_r1 == 7) {
            var_ip = 0xA;
        } else if (temp_r1 == 8) {
            var_ip = 0xA;
        } else if (temp_r1 == 9) {
            var_ip = 0xC;
        } else {
            var_ip = (u8)(temp_r1 + 3);
        }
        if ((u8)var_ip >= 0xA) goto done;
        goto middle;
    }
middle:
    if (temp_r2 & 0x20) {
        switch (var_ip) {
        case 9:
            if (temp_r2 == temp_r3) {
                var_ip = 0xA;
            }
            break;
        case 0:
        case 3:
        case 6:
            if (temp_r2 == temp_r3) {
                var_ip = (u8)(var_ip + 2);
            }
            break;
        default:
        case 1:
        case 2:
        case 4:
        case 5:
        case 7:
        case 8:
            var_ip = (u8)(var_ip - 1);
            break;
        }
    } else if (temp_r2 & 0x10) {
        switch (var_ip) {
        case 9:
            if (temp_r2 == temp_r3) {
                var_ip = 0xA;
            }
            break;
        case 2:
        case 5:
        case 8:
            if (temp_r2 == temp_r3) {
                var_ip = (u8)(var_ip - 2);
            }
            break;
        default:
        case 0:
        case 1:
        case 3:
        case 4:
        case 6:
        case 7:
            var_ip = (u8)(var_ip + 1);
            break;
        }
    }
done:
    if (temp_r1 != var_ip) {
        func_020b1c60(var_ip);
    }
}

void func_ov006_02215ae0(void *arg0) {
    M2C_UNK func_0208fe30(s32);
    s8 *temp_r0;
    s8 temp_r3;

    temp_r0 = M2C_FIELD(arg0, void **, 0x10);
    data_ov006_02218e10[M2C_FIELD(temp_r0, s8 *, 0x38)] =
        data_ov006_02218345[M2C_FIELD(arg0, u8 *, 0) * 6];
    temp_r3 = (s8)(M2C_FIELD(temp_r0, s8 *, 0x38) + 1);
    if (temp_r3 >= 0 && temp_r3 < 12 &&
        (data_ov006_02218e10[temp_r3] != 0 ||
         (temp_r3 > 0 && data_ov006_02218e10[temp_r3 - 1] != 0))) {
        M2C_FIELD(temp_r0, s8 *, 0x38) = temp_r3;
    }
    func_0208fe30(0x1000D);
}

void func_ov006_02215b64(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov006_02215b78(void) {
    M2C_UNK func_ov006_022157a0();
    func_ov006_022157a0();
}

void func_ov006_02215b84(u8 *arg0) {
    M2C_UNK func_020b1c60(u8);
    M2C_UNK func_ov006_02215c6c();
    extern void *data_02101e84;
    u16 temp_r1;
    u16 temp_r2;
    u8 var_r3;

    var_r3 = *arg0;
    temp_r2 = M2C_FIELD(data_02101e84, u16 *, 0);
    temp_r1 = M2C_FIELD(data_02101e84, u16 *, 2);
    if (temp_r2 & 1) {
        func_ov006_02215c6c();
        return;
    }
    if (temp_r1 & 0x40) {
        switch (*arg0) {
        case 10:
            var_r3 = 8;
            break;
        case 11:
            var_r3 = 0xA;
            break;
        }
        if (var_r3 == 0xA || var_r3 == 0xB) {
            goto L;
        } else {
            goto done;
        }
    } else if (temp_r1 & 0x80) {
        switch (*arg0) {
        case 10:
            var_r3 = 0xB;
            break;
        case 11:
            var_r3 = 0xD;
            break;
        }
        if (var_r3 != 0xA && var_r3 != 0xB) {
            goto done;
        }
    }
L:
    if (temp_r1 & 0x20) {
        switch (var_r3) {
        case 10:
            var_r3 = 9;
            break;
        case 11:
            break;
        }
        if (var_r3 != 0xA) {
            goto done;
        }
    } else if (temp_r1 & 0x10) {
        switch (var_r3) {
        case 10:
            if (temp_r1 == temp_r2) {
                var_r3 = 9;
            }
            break;
        case 11:
            break;
        }
    }
done:
    if (*arg0 != var_r3) {
        func_020b1c60(var_r3);
    }
}

#pragma opt_common_subs off
M2C_UNK func_ov006_02215c6c(void *arg0) {
void func_02007f8c(void *,s32,s32);s32 func_0208fe30(s32);
u8 event=M2C_FIELD(arg0,u8 *,0);void *p=M2C_FIELD(arg0,void **,16);s32 i,j;s8 prev;s8 *q;
switch(event) {
case 10:func_02007f8c(data_ov006_02218e10,0,13);M2C_FIELD(p,s8 *,56)=0;func_0208fe30(0x1000d);return;
case 11:
i=M2C_FIELD(p,s8 *,56);
if(i>0) {
if(i==11&&data_ov006_02218e10[i])data_ov006_02218e10[i]=0;
else {
prev=i-1;
if(prev>=0&&prev<12&&(data_ov006_02218e10[prev]||(prev>0&&data_ov006_02218e10[prev-1])))M2C_FIELD(p,s8 *,56)=prev;
j=M2C_FIELD(p,s8 *,56);
if(j<11){q=data_ov006_02218e10+j;do {j++;*q=q[1];q++;}while(j<11);}
data_ov006_02218e10[11]=0;
}func_0208fe30(0x1000d);return;
}
if(i==0&&data_ov006_02218e10[i]) {
if(i<11){q=data_ov006_02218e10+i;do{i++;*q=q[1];q++;}while(i<11);}
data_ov006_02218e10[11]=0;func_0208fe30(0x1000d);return;
}
func_0208fe30(0x1001d);return;
}
}
#pragma opt_common_subs reset
void func_ov006_02215dc4(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

void func_ov006_02215dd8(void) {
    M2C_UNK func_ov006_022157a0();
    func_ov006_022157a0();
}

void func_ov006_02215de4(u8 *arg0) {
    M2C_UNK func_020b1c60(u8);
    M2C_UNK func_ov006_02215ee4();
    extern void *data_02101e84;
    u16 temp_r1;
    u16 temp_r2;
    u8 var_r3;

    var_r3 = *arg0;
    temp_r2 = M2C_FIELD(data_02101e84, u16 *, 0);
    temp_r1 = M2C_FIELD(data_02101e84, u16 *, 2);
    if (temp_r2 & 1) {
        func_ov006_02215ee4();
        return;
    }
    if (temp_r1 & 0x40) {
        if ((*arg0 != 0xC) && (*arg0 != 0xD)) {
        } else {
            var_r3 = 0xB;
        }
        if (var_r3 == 0xC || var_r3 == 0xD) {
            goto L;
        }
        goto done;
    } else if (temp_r1 & 0x80) {
        switch (*arg0) {
        case 12:
            if (temp_r2 == temp_r1) {
                var_r3 = 0;
            }
            break;
        case 13:
            if (temp_r2 == temp_r1) {
                var_r3 = 2;
            }
            break;
        }
        if (var_r3 != 0xC && var_r3 != 0xD) {
            goto done;
        }
    }
L:
    if (temp_r1 & 0x20) {
        switch (var_r3) {
        case 12:
            if (temp_r2 == temp_r1) {
                var_r3 = 0xD;
            }
            break;
        case 13:
            var_r3 = 0xC;
            break;
        }
        if (var_r3 != 0xC) {
            goto done;
        }
    }
    if (temp_r1 & 0x10) {
        switch (var_r3) {
        case 12:
            var_r3 = 0xD;
            break;
        case 13:
            if (temp_r2 == temp_r1) {
                var_r3 = 0xC;
            }
            break;
        }
    }
done:
    if (*arg0 != var_r3) {
        func_020b1c60(var_r3);
    }
}

void func_ov006_02216188(void) {
    M2C_UNK func_0208fe30(s32);
    func_0208fe30(0x10019);
}

extern u16 **gCur3DSpriteEngine;
extern u16 **data_027e00c8;
#pragma optimization_level 2
void func_ov006_0221619c(void *arg0) {
M2C_UNK func_0208df84(s16,s16,s32,s32,s32,s32);
s32 func_020a8ff4(s32);M2C_UNK func_020a92bc(void *,s32);M2C_UNK func_020a94fc(void *);M2C_UNK func_020b1c44(s32,s32);
u16 **saved;u16 neg;s32 i,x,y;u16 reset;void *p;s32 offset;
offset=func_020a8ff4(M2C_FIELD(arg0,s32 *,0x48));
func_020b1c44(offset,0);
saved=gCur3DSpriteEngine;gCur3DSpriteEngine=data_027e00c8;neg=-offset;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x3a)=neg;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x42)=0;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x38)=neg;
M2C_FIELD(*gCur3DSpriteEngine,u16 *,0x40)=0;
func_0208df84((s16)(offset+(M2C_FIELD(arg0,s16 *,0x3a)+1)),(s16)(M2C_FIELD(arg0,s16 *,0x3c)+1),22,22,(u16)((0x3ff&(0x80>>((u32)(**gCur3DSpriteEngine<<17)>>30)))|0x1000),0);
i=0;x=60;y=12;
if(data_ov006_02218e10[0]){reset=x;do{
if(i==6){x=reset;y+=24;}
p=M2C_FIELD(arg0,void **,0x44);M2C_FIELD(p,u16 *,6)=offset+x;M2C_FIELD(p,u16 *,8)=y;
func_020a92bc(M2C_FIELD(arg0,void **,0x44),data_ov006_02218e10[i]-48);
func_020a94fc(M2C_FIELD(arg0,void **,0x44));i++;x+=24;
}while(data_ov006_02218e10[i]);}
gCur3DSpriteEngine=saved;
}
#pragma optimization_level 4
