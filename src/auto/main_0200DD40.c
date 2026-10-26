/* 41 functions from 0x0200DD40 to 0x0200ED40 (main), found by ds-decomp. */
#include "common.h"

void func_0200dd40(void) {
    M2C_UNK func_02009d34();
    M2C_UNK func_02009e40(M2C_UNK, M2C_UNK *);
    s32 func_02009e8c(M2C_UNK, M2C_UNK);
    extern M2C_UNK data_0212fcac;
    extern M2C_UNK func_0200dfb8;
    if (M2C_FIELD(&data_0212fcac, u16 *, 0) != 0) return;
    M2C_FIELD(&data_0212fcac, u16 *, 0) = 1;
    M2C_FIELD(&data_0212fcac, s32 *, 4) = 0;
    M2C_FIELD(&data_0212fcac, s32 *, 8) = 0;
    func_02009d34();
    do {} while (func_02009e8c(9, 1) == 0);
    *(s32 *)0x027FFF90 = 0;
    func_02009e40(9, &func_0200dfb8);
}

s32 func_0200dedc(M2C_UNK arg0) {
    s32 func_0200ddb0(M2C_UNK, void (*)(s32), s32);
    void func_0200e20c(s32);
    s32 func_0200e21c(void);
    extern M2C_UNK data_0212fcac;
    s32 result;
    result = func_0200ddb0(arg0, func_0200e20c, 0);
    M2C_FIELD(&data_0212fcac, s32 *, 0x10) = result;
    if (result == 0) func_0200e21c();
    return M2C_FIELD(&data_0212fcac, s32 *, 0x10);
}

s32 func_0200df14(s32 arg0, s32 arg1) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_0212fcac;
    s32 state;
    state = func_0200751c();
    if (M2C_FIELD(&data_0212fcac, s32 *, 4) != 0) {
        func_02007530(state);
        return 1;
    }
    M2C_FIELD(&data_0212fcac, s32 *, 4) = 1;
    func_02007530(state);
    M2C_FIELD(&data_0212fcac, s32 *, 8) = arg0;
    M2C_FIELD(&data_0212fcac, s32 *, 0xC) = arg1;
    if (func_0200e1e4() != 0) return 0;
    return 3;
}

s32 func_0200df70(void) {
    void func_0200e20c(s32);
    s32 func_0200e21c(void);
    extern M2C_UNK data_0212fcac;
    s32 result;
    result = func_0200df14((s32)func_0200e20c, 0);
    M2C_FIELD(&data_0212fcac, s32 *, 0x10) = result;
    if (result == 0) func_0200e21c();
    return M2C_FIELD(&data_0212fcac, s32 *, 0x10);
}

s32 func_0200dfa8(void) {
    return *(s32 *)0x027FFF90;
}

s32 func_0200e1e4(void) {
    s32 func_02009eb0(M2C_UNK, s32, M2C_UNK);
    if (func_02009eb0(9, 0x03004200, 0) >= 0) {
        return 1;
    }
    return 0;
}

void func_0200e20c(s32 arg0) {
    extern M2C_UNK data_0212fcac;
    M2C_FIELD(&data_0212fcac, s32 *, 0x10) = arg0;
}

s32 func_0200e21c(void) {
    extern s32 data_0212fcb0;
    s32 *base;
    s32 status;
    base = &data_0212fcb0;
    do {
        status = *(volatile s32 *)base;
    } while (status == 1);
    return status;
}

s32 func_0200e234(void) {
    s32 func_0200751c(void);
    void func_02007530(s32);
    extern M2C_UNK data_0212fccc;
    s32 state = func_0200751c();
    if (M2C_FIELD(&data_0212fccc, s32 *, 0x18) != 0) {
        func_02007530(state);
        return 0;
    }
    M2C_FIELD(&data_0212fccc, s32 *, 0x18) = 1;
    func_02007530(state);
    return 1;
}

void func_0200e270(void) {
    s32 func_02007574();
    M2C_UNK func_02009f38();
    extern M2C_UNK data_0212fccc;
    extern s32 data_0212fce4;
    s32 *status=&data_0212fce4;
    if(M2C_FIELD(&data_0212fccc,s32 *,0x18)==0) return;
    do {
        if(func_02007574()==0x80) func_02009f38();
    } while(*status!=0);
}

void func_0200e2b0(s32 arg0, s32 *arg1) {
    *arg1 = arg0;
}

void func_0200e2b8(s32 arg0) {
    extern M2C_UNK data_0212fccc;
    s32 busy;
    void (*callback)(s32,s32);
    s32 value;
    busy=M2C_FIELD(&data_0212fccc,s32 *,0x18);
    callback=M2C_FIELD(&data_0212fccc,void (**)(s32,s32),0x1C);
    value=M2C_FIELD(&data_0212fccc,s32 *,0x20);
    if(busy!=0) M2C_FIELD(&data_0212fccc,s32 *,0x18)=0;
    if(callback==NULL) return;
    M2C_FIELD(&data_0212fccc,void (**)(s32,s32),0x1C)=NULL;
    callback(arg0,value);
}

void func_0200e2f8(void) {
    M2C_UNK func_0200654c(M2C_UNK *);
    M2C_UNK func_02009d34();
    M2C_UNK func_02009e40(M2C_UNK, M2C_UNK *);
    s32 func_02009e8c(M2C_UNK,M2C_UNK);
    extern M2C_UNK data_0212fccc;
    extern M2C_UNK data_0212fcf4;
    extern M2C_UNK data_0212fd0c;
    extern M2C_UNK func_0200e39c;
    s32 i;
    if(M2C_FIELD(&data_0212fccc,u16 *,0)!=0) return;
    M2C_FIELD(&data_0212fccc,u16 *,0)=1;
    M2C_FIELD(&data_0212fccc,s32 *,0x18)=0;
    M2C_FIELD(&data_0212fccc,s32 *,0x1C)=0;
    func_02009d34();
    do {} while(func_02009e8c(8,1)==0);
    func_02009e40(8,&func_0200e39c);
    for(i=0;i<5;i++) ((u16 (*)[4])&data_0212fd0c)[i][0]=0;
    func_0200654c(&data_0212fcf4);
    M2C_FIELD(&data_0212fccc,s32 *,0x10)=*(s32 *)0x027FFC3C;
}

void func_0200e39c(s32 arg0, u32 arg1, s32 arg2) {
extern M2C_UNK data_0212fd10; extern M2C_UNK data_0212fd0c; extern M2C_UNK data_0212fccc;
u32 command; u16 value; u16 *dest;
if(arg2!=0) { func_0200e2b8(2); return; }
command=(u16)((arg1 & 0x7F00)>>8);
value=arg1&0xFF;
if(command>=0x70 && command<=0x74) {
command-=0x70;
dest=((u16 *(*)[2])&data_0212fd10)[command][0];
value=(u8)value;
if(dest) *dest=value;
((u16 (*)[4])&data_0212fd0c)[command][0]=1;
value=0;
} else if(command==0x60) M2C_FIELD(&data_0212fccc,s32 *,4)=1;
else if(command==0x62) M2C_FIELD(&data_0212fccc,s32 *,8)=1;
else if(command==0x67) {
s32 *p=M2C_FIELD(&data_0212fccc,s32 **,0x24);
if(p) *p=value;
value=0;
}
func_0200e2b8(value);
}

s32 func_0200e464(s32 arg0, s32 arg1) {
    void func_0200e8f4(s32);
    extern M2C_UNK data_0212fccc;
    M2C_UNK func_0200eb50(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    if (func_0200e234() == 0) return 1;
    M2C_FIELD(&data_0212fccc, s32 *, 4) = 0;
    func_0200e8f4(0x03006000);
    do {} while (M2C_FIELD(&data_0212fccc, s32 *, 4) == 0);
    M2C_FIELD(&data_0212fccc, s32 *, 4) = 0;
    M2C_FIELD(&data_0212fccc, s32 *, 8) = 0;
    func_0200eb50(0, 2, 0, 1);
    func_0200e8f4((u8)arg0 | 0x02006100);
    func_0200e8f4(0x01010000 | (u16)arg1);
    return 0;
}

s32 func_0200e4f8(u32 arg0, s32 arg1, s32 arg2) {
    void func_0200e8f4(s32);
    extern M2C_UNK data_0212fccc;
    if (func_0200e234() == 0) return 1;
    M2C_FIELD(&data_0212fccc, s32 *, 0x1C) = arg1;
    M2C_FIELD(&data_0212fccc, s32 *, 0x20) = arg2;
    func_0200e8f4((u8)(arg0 >> 16) | 0x02006300);
    func_0200e8f4(0x01010000 | (u16)arg0);
    return 0;
}

s32 func_0200e558(s32 arg0, s32 arg1, void (*arg2)(s32, s32 *), s32 *arg3) {
    void func_0200e8f4(s32);
    extern M2C_UNK data_0212fccc;
    extern M2C_UNK data_0212fd0c;
    extern M2C_UNK data_0212fd10;
    if (func_0200e234() == 0) return 1;
    M2C_FIELD(&data_0212fccc, void (**)(s32, s32 *), 0x1C) = arg2;
    M2C_FIELD(&data_0212fccc, s32 **, 0x20) = arg3;
    ((u16 (*)[4])&data_0212fd0c)[arg0][0] = 0;
    ((s32 (*)[2])&data_0212fd10)[arg0][0] = arg1;
    func_0200e8f4((u8)arg0 | 0x03006500);
    return 0;
}

s32 func_0200e5c4(M2C_UNK arg0, M2C_UNK arg1) {
    void func_0200e270(void);
    s32 func_0200e558(M2C_UNK, M2C_UNK, void (*)(s32, s32 *), s32 *);
    s32 sp0;
    s32 result;
    result = func_0200e558(arg0, arg1, func_0200e2b0, &sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

s32 func_0200e5ec(s32 arg0, M2C_UNK arg1, void (*arg2)(s32, s32 *), s32 *arg3) {
    void func_0200e8f4(s32);
    extern M2C_UNK data_0212fccc;
    if (func_0200e234() == 0) return 1;
    M2C_FIELD(&data_0212fccc, void (**)(s32, s32 *), 0x1C) = arg2;
    M2C_FIELD(&data_0212fccc, s32 **, 0x20) = arg3;
    func_0200e8f4((u8)arg0 | 0x02006400);
    func_0200e8f4(0x01010000 | (u16)arg1);
    return 0;
}

s32 func_0200e64c(M2C_UNK arg0, M2C_UNK arg1) {
    void func_0200e270(void);
    s32 func_0200e5ec(M2C_UNK, M2C_UNK, void (*)(s32, s32 *), s32 *);
    s32 sp0;
    s32 result;
    result = func_0200e5ec(arg0, arg1, func_0200e2b0, &sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

s32 func_0200e674(s32 arg0, void (*arg1)(s32, s32 *), s32 *arg2) {
    s32 func_0200e4f8();
    s32 var_r0;

    switch (arg0) {                                 /* irregular */
    case 1:
        var_r0 = 1;
        break;
    case 3:
        var_r0 = 2;
        break;
    case 2:
        var_r0 = 3;
        break;
    default:
        var_r0 = 0;
        break;
    }
    if (var_r0 == 0) {
        return 0xFFFF;
    }
    return func_0200e4f8();
}

s32 func_0200e6c8(s32 arg0) {
    void func_0200e270(void);
    s32 sp0;
    s32 result;
    result = func_0200e674(arg0, func_0200e2b0, &sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

s32 func_0200e6f0(M2C_UNK arg0, M2C_UNK arg1, void (*arg2)(s32, s32 *), s32 *arg3) {
    s32 sel;

    sel = 0;
    if (arg0 == 0) {
        if (arg1 == 1) sel = 6;
        if (arg1 == 0) sel = 7;
    } else if (arg0 == 1) {
        if (arg1 == 1) sel = 4;
        if (arg1 == 0) sel = 5;
    } else if (arg0 == 2) {
        if (arg1 == 1) sel = 8;
        if (arg1 == 0) sel = 9;
    }
    if (sel == 0) {
        return 0xFFFF;
    }
    return func_0200e4f8(sel, (M2C_UNK)arg2, (s32)arg3);
}

s32 func_0200e76c(M2C_UNK arg0, M2C_UNK arg1) {
    void func_0200e270(void);
    s32 func_0200e6f0(M2C_UNK, M2C_UNK, void (*)(s32, s32 *), s32 *);
    s32 sp0;
    s32 result;
    result = func_0200e6f0(arg0, arg1, func_0200e2b0, &sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

void func_0200e794(s32 arg0, s32 arg1) {
    void func_0200758c(M2C_UNK);
    s32 func_0200ec44(void);

    M2C_UNK func_0200e76c(M2C_UNK, M2C_UNK);
    s32 func_0200ec24(s32);
    s32 func_0200e4f8(u32, s32, s32);
    s32 sp4;
    s32 sp0;

    func_0200758c(0x996A00);
    if (func_0200ec44() != 1) {
        func_0200e898(&sp4, &sp0);
        if (sp4 != 0) {
            func_0200e76c(0, 0);
        }
        if (sp0 != 0) {
            func_0200e76c(1, 0);
        }
        while (func_0200ec24(1) == 0) {
            func_0200758c(0x996A00);
        }
    }
    func_0200e4f8(0xE, arg0, arg1);
}

s32 func_0200e840(void) {
s32 sp0,result;
result=((s32 (*)(s32,s32))func_0200e794)((s32)func_0200e2b0,(s32)&sp0);
if(result)return result;
func_0200e270();return sp0;
}

void func_0200e868(s32 a) {
func_0200e64c(2,(u16)a);
}

void func_0200e880(s32 a) {
func_0200e64c(3,(u16)a);
}

s32 func_0200e898(s32 *a,s32 *b) {
u16 value;s32 result;
result=func_0200e5c4(0,&value);
if(result)return result;
if(a)*a=(value&8)?1:0;
if(b)*b=(value&4)?1:0;
return result;
}

void func_0200e8f4(M2C_UNK arg0) {
    do {

    } while (func_02009eb0(8, arg0, 0) != 0);
}

s32 func_0200eb50(s32 arg0,s32 arg1,s32 arg2,s32 arg3) {
extern M2C_UNK data_0212fccc;
switch(arg0) {
case 1:
if(arg2==0 && (u32)(*(volatile u32 *)0x027FFC3C-M2C_FIELD(&data_0212fccc,u32 *,0x10))<=7) return 0;
if(arg1!=0) { if(arg3!=0) func_0200e6c8(arg1); else func_0200e674(arg1,0,0); }
*(volatile u16 *)0x04000304 |= 1;
break;
case 0:
*(volatile u16 *)0x04000304 &= ~1;
M2C_FIELD(&data_0212fccc,u32 *,0x10)=*(volatile u32 *)0x027FFC3C;
if(arg1!=0) { if(arg3!=0) func_0200e6c8(arg1); else func_0200e674(arg1,0,0); }
break;
}
return 1;
}

s32 func_0200ec24(s32 arg0) {
    M2C_UNK func_0200eb50(s32, M2C_UNK, M2C_UNK, M2C_UNK);
    s32 var_r0;

    var_r0 = arg0;
    if (var_r0 != 1) {
        var_r0 = 0;
    }
    func_0200eb50(var_r0, 0, 0, 1);
}

s32 func_0200ec44(void) {
    if (*(u16 *)0x04000304 & 1) {
        return 1;
    }
    return 0;
}

s32 func_0200ec60(s32 arg0, void (*arg1)(s32, s32 *), s32 *arg2) {
 s32 func_0200e234();
 void func_0200e8f4(s32);
 extern M2C_UNK data_0212fccc;
 if (func_0200e234() == 0) return 1;
 M2C_FIELD(&data_0212fccc, void (**)(s32,s32 *), 0x1C) = arg1;
 M2C_FIELD(&data_0212fccc, s32 **, 0x20) = arg2;
 func_0200e8f4((u8)arg0 | 0x03006600);
 return 0;
}

s32 func_0200eca8(s32 arg0) {
    void func_0200e270(void);
    s32 sp0;
    s32 result;
    result = func_0200ec60(arg0, func_0200e2b0, &sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

s32 func_0200ecd0(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_0200e234();
    extern M2C_UNK data_0212fccc;
    if (func_0200e234() == 0) {
        return 1;
    }
    M2C_FIELD(&data_0212fccc, s32 *, 0x1C) = arg1;
    M2C_FIELD(&data_0212fccc, s32 *, 0x20) = arg2;
    M2C_FIELD(&data_0212fccc, s32 *, 0x24) = arg0;
    func_0200e8f4(0x03006700);
    return 0;
}

s32 func_0200ed18(s32 arg0) {
    s32 sp0;
    s32 result;
    result = func_0200ecd0(arg0, (s32)func_0200e2b0, (s32)&sp0);
    if (result != 0) return result;
    func_0200e270();
    return sp0;
}

