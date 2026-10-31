/* 18 functions from 0x0203804C to 0x02038F88 (main), found by ds-decomp. */
#include "common.h"

/* Tear down and free the global session/context object at data_0213d1f8: its socket/peer at +0x384, state at +0x458, the sub-structure at +0x1C (four channels plus cleanup), plus close out remaining resources and reset the pointer. */
void func_0203804c(void *a,void *b,s32 c,char *d,char *e,s32 f,s32 g,s32 h,s32 i){
extern void *data_0213d1f8;
extern u8 data_0213df10[];
extern u8 data_0213e010[];
void func_020375fc(void);
void func_02039100(void);
void func_0203d910(void);
void func_02039838(void);
void func_02039844(void);
void func_02039b9c(void);
void func_02039478(void);
void func_02039be4(void *,void *,void *,s32,s32,void *,void *,s32);
void func_0203a9dc(void *,void *,void *,s32,s32);
void func_0203c110(void *,void *,void *,void *,void *,void *,s32,s32);
void func_02044708(void *);
u32 len;
data_0213d1f8=a;
func_020375fc();
M2C_FIELD(data_0213d1f8,s32 *,0)=0;
M2C_FIELD(data_0213d1f8,s32 *,4)=(s32)func_0203d910;
M2C_FIELD(data_0213d1f8,s32 *,8)=(s32)func_02039838;
M2C_FIELD(data_0213d1f8,s32 *,12)=(s32)func_02039844;
M2C_FIELD(data_0213d1f8,s32 *,16)=(s32)func_02039b9c;
M2C_FIELD(data_0213d1f8,s32 *,20)=f?f:0x2000;
M2C_FIELD(data_0213d1f8,s32 *,24)=g?g:0x2000;
M2C_FIELD(data_0213d1f8,s32 *,28)=0;
M2C_FIELD(data_0213d1f8,s32 *,32)=(s32)b;
M2C_FIELD(data_0213d1f8,s32 *,36)=0;
M2C_FIELD(data_0213d1f8,s32 *,40)=0;
M2C_FIELD(data_0213d1f8,u8 *,44)=0;
M2C_FIELD(data_0213d1f8,u8 *,45)=0;
M2C_FIELD(data_0213d1f8,s32 *,100)=0;
M2C_FIELD(data_0213d1f8,s32 *,104)=(s32)data_0213df10;
M2C_FIELD(data_0213d1f8,s32 *,108)=(s32)data_0213e010;
M2C_FIELD(data_0213d1f8,s32 *,112)=0;M2C_FIELD(data_0213d1f8,s32 *,116)=0;M2C_FIELD(data_0213d1f8,s32 *,120)=0;M2C_FIELD(data_0213d1f8,s32 *,124)=0;M2C_FIELD(data_0213d1f8,s32 *,128)=0;M2C_FIELD(data_0213d1f8,s32 *,132)=0;M2C_FIELD(data_0213d1f8,s32 *,136)=0;M2C_FIELD(data_0213d1f8,s32 *,140)=0;M2C_FIELD(data_0213d1f8,s32 *,144)=0;M2C_FIELD(data_0213d1f8,s32 *,148)=0;
func_02039100();
func_02039be4((u8 *)data_0213d1f8+0x98,b,(u8 *)data_0213d1f8+0x1c,c,M2C_FIELD(b,s32 *,0x24),(u8 *)data_0213d1f8+0x2e,func_02039478,0);
func_0203a9dc((u8 *)data_0213d1f8+0x318,(u8 *)data_0213d1f8+0x1c,(u8 *)data_0213d1f8+0x2e,h,i);
func_0203c110((u8 *)data_0213d1f8+0x374,(u8 *)data_0213d1f8+0x1c,data_0213d1f8,(u8 *)data_0213d1f8+4,data_0213df10,data_0213e010,h,i);
func_02044708((u8 *)data_0213d1f8+0x7f8);
if((u32)func_02068c34(d)>=0x100)len=255;else len=func_02068c34(d);
func_02008048(d,data_0213df10,len);
data_0213df10[len]=0;
if((u32)func_02068c34(e)>=0x100)len=255;else len=func_02068c34(e);
func_02008048(e,data_0213e010,len);
data_0213e010[len]=0;
}

void func_020382d0(void) {
    extern void *data_0213d1f8;
    void func_0205eacc(void *resource);
    void func_020614b0(void *resource);
    void func_0203bd0c(void);
    void func_02058c14(void);
    s32 func_0204db84(void *channel, s32 a, s32 b, s32 c);
    void func_0204db50(void *channel);
    void func_0204db34(void *channel);
    void func_02039e04(void);
    void func_0203b088(void);
    void func_0203e4e0(void);
    void func_020449dc(void);
    void func_0205ad60(void *resource);

    if (!data_0213d1f8) return;
    if (M2C_FIELD(data_0213d1f8, void **, 0x384)) {
        func_0205eacc(M2C_FIELD(data_0213d1f8, void **, 0x384));
        M2C_FIELD(data_0213d1f8, void **, 0x384) = 0;
    }
    M2C_FIELD(data_0213d1f8, u8 *, 0x38C) = 0;
    if (M2C_FIELD(data_0213d1f8, void **, 0x458)) {
        func_020614b0(M2C_FIELD(data_0213d1f8, void **, 0x458));
        M2C_FIELD(data_0213d1f8, void **, 0x458) = 0;
    }
    func_0203bd0c();
    func_02058c14();
    if (M2C_FIELD(data_0213d1f8, s32 *, 0x1C)) {
        func_0204db84(data_0213d1f8 + 0x1C, 0, 0, 0);
        func_0204db84(data_0213d1f8 + 0x1C, 3, 0, 0);
        func_0204db84(data_0213d1f8 + 0x1C, 1, 0, 0);
        func_0204db84(data_0213d1f8 + 0x1C, 2, 0, 0);
        func_0204db50(data_0213d1f8 + 0x1C);
        func_0204db34(data_0213d1f8 + 0x1C);
        M2C_FIELD(data_0213d1f8, s32 *, 0x1C) = 0;
    }
    func_02039e04();
    func_0203b088();
    func_0203e4e0();
    func_020449dc();
    if (M2C_FIELD(data_0213d1f8, void **, 0)) {
        func_0205ad60(M2C_FIELD(data_0213d1f8, void **, 0));
        M2C_FIELD(data_0213d1f8, void **, 0) = 0;
    }
    data_0213d1f8 = 0;
}

/* Advances the online connection state, installs callbacks after the availability check, and releases deferred network resources. */
void func_02038438(void) {
    extern void *data_0213d1f8;
    extern M2C_UNK func_02039698;
    extern M2C_UNK func_020396d0;
    extern M2C_UNK func_0203ad24;
    extern M2C_UNK func_0203adcc;
    s32 func_02037bc4(void);
    void func_02039200(void);
    s32 func_0203761c(void);
    s32 func_0204837c(void);
    s32 func_020392b8(s32);
    void func_02039204(s32);
    void func_02039c68(void);
    void func_02039ca0(void);
    void func_02039db4(s32, s32);
    void func_0203aabc(void);
    void func_0203cb38(s32);
    void func_020447c0(void);
    s32 func_0204db04(s32, s32, s32);
    s32 func_0204db84(void *, s32, s32, s32);
    void func_0205eacc(void *);

    if (func_02037bc4()) func_02039200();
    if (!data_0213d1f8 || M2C_FIELD(data_0213d1f8, s32 *, 0x24) == 0) return;
    if (func_0203761c() != 0) return;
    switch (M2C_FIELD(data_0213d1f8, s32 *, 0x24)) {
    case 1:
        switch (func_0204837c()) {
        case 1:
            if (func_020392b8(func_0204db04((s32)data_0213d1f8 + 0x1c, M2C_FIELD(data_0213d1f8, s32 *, 0xa0), 0))) return;
            if (func_020392b8(func_0204db84((u8 *)data_0213d1f8 + 0x1c, 0, (s32)&func_02039698, 0))) return;
            if (func_020392b8(func_0204db84((u8 *)data_0213d1f8 + 0x1c, 3, (s32)&func_020396d0, 0))) return;
            if (func_020392b8(func_0204db84((u8 *)data_0213d1f8 + 0x1c, 1, (s32)&func_0203ad24, 0))) return;
            if (func_020392b8(func_0204db84((u8 *)data_0213d1f8 + 0x1c, 2, (s32)&func_0203adcc, 0))) return;
            func_02039204(2);
            func_02039c68();
            break;
        case 2:
            func_02039db4(3, -0x4e8e);
            return;
        case 3:
            func_02039db4(4, -0x4e85);
            return;
        }
        break;
    case 2:
        func_02039ca0();
        break;
    case 3:
    case 4:
        func_0203aabc();
        func_0203cb38(0);
        break;
    case 5:
        func_0203cb38(1);
        func_0203aabc();
        break;
    case 6:
        func_020447c0();
        func_0203aabc();
        if (M2C_FIELD(data_0213d1f8, volatile u8 *, 0x389) == 2 || M2C_FIELD(data_0213d1f8, volatile u8 *, 0x389) == 3) func_0203cb38(1);
        else if (M2C_FIELD(data_0213d1f8, s32 *, 0) != 0) func_0203cb38(0);
        break;
    }
    if (M2C_FIELD(data_0213d1f8, u8 *, 0x38c) == 1) {
        if (M2C_FIELD(data_0213d1f8, s32 *, 0x384) != 0) {
            func_0205eacc(M2C_FIELD(data_0213d1f8, s32 *, 0x384));
            M2C_FIELD(data_0213d1f8, s32 *, 0x384) = 0;
        }
        M2C_FIELD(data_0213d1f8, u8 *, 0x38c) = 0;
    }
}

s32 func_02038688(u16 *text,s32 unused,s32 a,s32 b){
extern void *data_0213d1f8;
s32 func_0203761c(void); u32 func_02038020(u16 *);
void func_02007df8(s32,void *,s32); void func_02007e20(void *,void *,s32);
s32 func_02037a0c(void);void func_02039db4(s32,s32);void func_02039204(s32);void InitServiceAvailabilityQuery(s32);
u32 n;
if(!text)return 0;
if(func_0203761c() || M2C_FIELD(data_0213d1f8,s32 *,36)!=0)return 0;
M2C_FIELD(data_0213d1f8,s32 *,112)=a;
M2C_FIELD(data_0213d1f8,s32 *,116)=b;
if(!text || !*text)n=0;
else{
func_02007df8(0,(u8 *)data_0213d1f8+46,52);
if(func_02038020(text)>25)n=25;else n=func_02038020(text);
func_02007e20(text,(u8 *)data_0213d1f8+46,n*2);
}
M2C_FIELD((u8 *)data_0213d1f8+n*2,u16 *,46)=0;
if(func_02037a0c()!=4){func_02039db4(2,-60010);return 1;}
func_02039204(1);InitServiceAvailabilityQuery(M2C_FIELD(data_0213d1f8,s32 *,104));return 1;
}

s32 func_02038790(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f,s32 g){s32 func_0203761c(void);void func_02039204(s32);void func_0203ac20(void *,void *,void *,s32,s32,s32,s32,s32);extern M2C_UNK func_020394d8;extern void *data_0213d1f8;s32 state;if(func_0203761c() || (state=M2C_FIELD(data_0213d1f8,s32 *,36))<3 || state==4)return 0;M2C_FIELD(data_0213d1f8,s32 *,120)=b;M2C_FIELD(data_0213d1f8,s32 *,124)=c;func_02039204(4);func_0203ac20(data_0213d1f8+224,data_0213d1f8+480,&func_020394d8,0,d,e,f,g);return 1;}

s32 func_02038838(s32 a,s32 b,s32 c,s32 d,s32 e,s32 f){s32 func_0203761c(void);void func_02039100(void);void func_02039204(s32);void func_0203c428(s32,s32,void *,s32,s32,s32);extern M2C_UNK func_02039520;extern void *data_0213d1f8;if(func_0203761c() || M2C_FIELD(data_0213d1f8,s32 *,36)!=3)return 0;func_02039100();M2C_FIELD(data_0213d1f8,s32 *,128)=c;M2C_FIELD(data_0213d1f8,s32 *,132)=d;func_02039204(5);func_0203c428((u8)(a-1),b,&func_02039520,0,e,f);return 1;}

s32 func_020388d8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 func_0203761c(void); void func_02039100(void); void func_02039204(s32);
    s32 func_0203ae50(void); u32 func_02037eec(u32);
    void func_0203c614(s32,s32,u8,s32,void *,s32,s32,s32);
    extern void *data_0213d1f8; extern M2C_UNK func_02039520;
    u8 buf2[64]; u8 buf1[64];
    if (func_0203761c() != 0 || M2C_FIELD(data_0213d1f8,s32 *,0x24) != 3) return 0;
    func_02039100();
    M2C_FIELD(data_0213d1f8,s32 *,0x80)=a4;
    M2C_FIELD(data_0213d1f8,s32 *,0x84)=a5;
    func_02039204(5);
    if(a0 != 0) {
        func_0203c614(a0,a1,(u8)(a2-1),a3,&func_02039520,0,a6,a7);
    } else {
        u32 k; u8 *p; s32 i, j;
        a1=0; i=a1;
        while(i<func_0203ae50()) { buf1[i]=(u8)i; i=(i+1)&255; }
        j=0;
        while(j<func_0203ae50()) {
            k=func_02037eec(func_0203ae50()-j);
            buf2[j]=buf1[k]; p=&buf1[k]; a1++;
            while(k<func_0203ae50()-j-1) { *p=p[1]; p++; k++; }
            j=(j+1)&255;
        }
        func_0203c614((s32)buf2,a1,(u8)(a2-1),a3,&func_02039520,0,a6,a7);
    }
    return 1;
}

s32 func_02038a84(s32 a,s32 b,s32 c,s32 d,s32 e){s32 func_0203761c(void);void func_02039100(void);void func_02039204(s32);void func_0203c878(s32,void *,s32,s32,s32);extern M2C_UNK func_02039520;extern void *data_0213d1f8;if(func_0203761c() || M2C_FIELD(data_0213d1f8,s32 *,36)!=3)return 0;func_02039100();M2C_FIELD(data_0213d1f8,s32 *,136)=b;M2C_FIELD(data_0213d1f8,s32 *,140)=c;M2C_FIELD(data_0213d1f8,u8 *,44)=0;func_02039204(5);func_0203c878((u8)(a-1),&func_02039520,0,d,e);return 1;}

s32 func_02038b1c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_0203761c(void);
    void func_02039100(void);
    void func_02039204(s32);
    s32 func_0203ae6c(s32);
    s32 func_0204e364(void **, s32);
    s32 func_0204e2f4(void **, s32, s32 *);
    s32 func_0204e1b4(void **, s32, void *);
    s32 func_02037df0(s8 *, s8 *, s8 *, s32);
    s32 func_0206abd8(s8 *, s32, s32);
    void func_0203c920(s32, M2C_UNK, M2C_UNK, s32, s32);
    void func_02037638(s32, s32);
    void func_0203af50(s32, void *, s32);
    extern void *data_0213d1f8;
    extern M2C_UNK data_020fc890;
    extern M2C_UNK data_020fc894;
    extern M2C_UNK data_020fc898;
    extern M2C_UNK func_02039520;

    s32 mode = arg3;
    s32 outbuf[2];
    s32 v = -1;
    u8 payload[0x208];
    u8 firstc;
    u8 firstval;
    u8 secondval;
    s32 r4;

    if (func_0203761c() != 0 || M2C_FIELD(data_0213d1f8, s32 *, 0x24) != 3) return 0;

    func_02039100();
    M2C_FIELD(data_0213d1f8, s32 *, 0x88) = arg1;
    M2C_FIELD(data_0213d1f8, s32 *, 0x8C) = arg2;
    func_02039204(5);

    r4 = func_0203ae6c(arg0);
    if (r4 == 0 || func_0204e364((void **)((char *)data_0213d1f8 + 0x1C), r4) == 0) {
        mode = 0x0B;
        goto tail;
    }

    func_0204e2f4((void **)((char *)data_0213d1f8 + 0x1C), r4, &v);
    func_0204e1b4((void **)((char *)data_0213d1f8 + 0x1C), v, outbuf);

    if (M2C_FIELD(outbuf, s32 *, 0x04) != 6) {
        mode = 0x0B;
        goto tail;
    }

    firstc = 0x30;
    func_02037df0(&data_020fc890, (s8 *)&firstc, (s8 *)payload, 0x2F);
    firstval = (u8)func_0206abd8((s8 *)&firstc, 0, 10);

    func_02037df0(&data_020fc894, (s8 *)&firstc, (s8 *)payload, 0x2F);
    secondval = (u8)func_0206abd8((s8 *)&firstc, 0, 10);
    if (secondval == firstval) {
        mode = 0x0D;
        goto tail;
    }

    func_0203c920(r4, &func_02039520, 0, mode, arg4);
    return 1;

tail:
    func_02037638(mode, 0);
    {
        void *st = data_0213d1f8;
        void *fp = *(void **)((char *)st + 0x88);
        ((void (*)(s32, s32, s32, s32, s32, s32))fp)(mode, 0, 1, 0, 0, *(s32 *)((char *)st + 0x8C));
    }
    if (data_0213d1f8 != 0) {
        if (M2C_FIELD(data_0213d1f8, s32 *, 0x24) == 5) {
            func_02039204(3);
            func_0203af50(1, &data_020fc898, 0);
        }
    }
    return 1;
}

s32 func_02038d14(s32 a,s32 b){extern void *data_0213d1f8;if(!data_0213d1f8)return 0;M2C_FIELD(data_0213d1f8,s32 *,144)=a;M2C_FIELD(data_0213d1f8,s32 *,148)=b;return 1;}

s32 func_02038d40(void){extern void *data_0213d1f8;extern M2C_UNK data_020fc898;s32 func_0203761c(void);void func_0203af50(s32,void *,s32);void func_0203bd0c(void);void func_02039204(s32);void func_0205afec(void *);s32 state;if(!data_0213d1f8 || func_0203761c() || ((state=M2C_FIELD(data_0213d1f8,s32 *,0x24))!=5 && state!=6))return -1;if(!M2C_FIELD(data_0213d1f8,u8 *,0x381)){func_0203af50(1,&data_020fc898,0);func_0203bd0c();func_02039204(3);return 1;}M2C_FIELD(data_0213d1f8,u8 *,0x2d)=1;func_0205afec(M2C_FIELD(data_0213d1f8,void **,0));M2C_FIELD(data_0213d1f8,u8 *,0x2d)=0;return 0;}

s32 func_02038de4(s32 a){extern void *data_0213d1f8;s32 func_0203761c(void);void *func_02039050(s32);void func_0205afcc(void *);s32 state;void *p;if(!data_0213d1f8 || func_0203761c() || ((state=M2C_FIELD(data_0213d1f8,s32 *,0x24))!=5 && state!=6))return -1;p=func_02039050(a);if(!p)return -2;func_0205afcc(p);return 0;}

s32 func_02038e4c(void){extern void *data_0213d1f8;s32 func_0203e2c4(void);s32 func_0203e2a4(void);if(!data_0213d1f8)return 0;if(M2C_FIELD(data_0213d1f8,volatile u8 *,0x389)==2 || M2C_FIELD(data_0213d1f8,volatile u8 *,0x389)==3)return func_0203e2c4()+1;return func_0203e2a4()+1;}

u8 func_02038e94(void) {
    extern void *data_0213d1f8;
    if (data_0213d1f8 != NULL) {
        return M2C_FIELD(data_0213d1f8, u8 *, 0x2C);
    }
    return 0U;
}

s32 func_02038eb0(s32 *a){extern void *data_0213d1f8;s32 func_0203e36c(s32 *);s32 func_0203e338(s32 *);if(!data_0213d1f8)return 0;*a=(s32)(data_0213d1f8+0x644);if(M2C_FIELD(data_0213d1f8,volatile u8 *,0x389)==2 || M2C_FIELD(data_0213d1f8,volatile u8 *,0x389)==3)return func_0203e36c(a);return func_0203e338(a);}

s32 func_02038f00(void){extern void *data_0213d1f8;s32 func_02038eb0(s32 *);s32 func_02039284(s32,s32);s32 a,b;if(!data_0213d1f8)return 0;b=func_02038eb0(&a);return func_02039284(a,b);}

s32 func_02038f34(s32 a){extern void *data_0213d1f8;s32 func_020391b8(s32);if(!data_0213d1f8)return 0;if(!(M2C_FIELD(data_0213d1f8,u32 *,0x664)&(1<<a)))return 0;return func_020391b8(a);}

s32 func_02038f6c(void) {
    extern void *data_0213d1f8;
    if (data_0213d1f8 != NULL) {
        return M2C_FIELD(data_0213d1f8, s32 *, 0x24);
    }
    return 0;
}

