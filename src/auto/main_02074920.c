/* 9 functions from 0x02074920 to 0x020756A4 (main), found by ds-decomp. */
#include "common.h"
typedef struct { u16 id; u8 kind; u8 active; s32 value; u8 data[32]; } Entry_02074920;
typedef struct { Entry_02074920 entries[128]; u32 count; } List_02074920;

u16 func_02074920(void *arg0) {
u8 *p;
s32 i;
s32 skip;
u32 value;
u16 best;
u8 oldrank;
u8 oldkind;
u32 oldvalue;
s32 rank;
best=0xffff;
p=arg0;
for(i=0;i<256;i++,p+=12) {
rank=(M2C_FIELD((u8 *)arg0+(i>>2),u8 *,0xc0c)>>((i&3)*2))&3;
switch(rank) {
case 0: case 1: case 2:
if(best==0xffff) break;
if(rank>oldrank)continue;
if(rank<oldrank)break;
{
u8 kind=M2C_FIELD(p,u8 *,6);
if(kind!=oldkind && rank!=0) {
if(kind==1)continue;
if(oldkind==1)break;
}
value=M2C_FIELD(p,u32 *,0);
if((value&0xffff0000)==0xffff0000 && !(oldvalue&0xffff0000) && oldvalue!=0)skip=0;
else if(!(value&0xffff0000) && (oldvalue&0xffff0000)==0xffff0000 && value!=0)skip=1;
else skip=value>oldvalue;
if(skip)continue;
}
break;
case 3: continue;
}
oldrank=rank;
best=i;
oldvalue=M2C_FIELD(p,u32 *,0);
oldkind=M2C_FIELD(p,u8 *,6);
}
return best;
}

void func_02074a48(List_02074920 *arg0) {
u32 i=0;
for(;i<arg0->count;i++) arg0->entries[i].active=0;
}

void func_02074a7c(List_02074920 *arg0,u16 a,u8 b,s32 c,void *data) {
void func_02007ef4(void *,void *,u32); void func_02007e98(s32,void *,u32);
u32 n=arg0->count; Entry_02074920 *p;
if(n>=128) return;
p=&arg0->entries[n]; p->id=a; p->kind=b; p->active=1; p->value=c;
if(data) func_02007ef4(data,p->data,32); else func_02007e98(0,p->data,32);
arg0->count++;
}

void func_02074aec(List_02074920 *arg0,s32 arg1) {
void func_02008048(void *,void *,u32);
Entry_02074920 *p; u32 i,n;
n=arg0->count; i=0; p=arg0->entries;
for(;i<n;i++,p++) {
if(arg1==p->id) {
if(i<n-1) {
Entry_02074920 *q=&arg0->entries[i];
do {func_02008048(q+1,q,40); i++; q++;} while(i<arg0->count-1);
}
arg0->count--; return;
}
}
}

/* Sorts the entry list by kind and id using bubble sort. */
u32 func_02074b84(List_02074920 *list) {
    void func_02008048(void *, void *, u32);
    u32 i;
    Entry_02074920 *cur;
    u32 j;
    u8 scratch[0x28];
    u32 count;
    u32 limit;
    u32 subLimit;

    count = list->count;
    if (count <= 1U) {
        return count;
    }
    limit = count - 1;
    j = 0;
    if (limit == 0) {
        return count;
    }
    do {
        i = 0;
        subLimit = limit - j;
        if (subLimit != 0) {
            cur = list->entries;
            do {
                u8 nextKind = (cur + 1)->kind;
                u8 curKind = cur->kind;
                if (((u32)curKind > (u32)nextKind) || (curKind == nextKind && cur->id > (cur + 1)->id)) {
                    func_02008048(cur, scratch, 0x28);
                    func_02008048(cur + 1, cur, 0x28);
                    func_02008048(scratch, cur + 1, 0x28);
                }
                i = i + 1;
                limit = list->count - 1;
                subLimit = limit - j;
                cur = cur + 1;
            } while (i < subLimit);
        }
        j = j + 1;
    } while (j < limit);
    return subLimit;
}

void func_02074c58(void *arg0) {
    s32 func_0200558c(void);
    void func_020055f4(u8);
    s32 func_0200fe08(void);
    void func_0200fe5c(u16);
    void func_0200fe6c(u8);
    s32 func_0201033c(s32, s32 *, s32, s32, s32, s32, s32, s32, s32);
    s32 func_02010424(void);
    s32 func_0201044c(s32);
    u8 tmp;
    u16 id2;
    u16 id;
    s32 sp14;

    if (func_0200fe08() == 0) {
        id = 0;
    } else {
        id = (u16)func_0200558c();
        ((void(*)(M2C_UNK))func_0200fe5c)(id);
        tmp = (u8)func_0201044c(0x1202);
        ((void(*)(M2C_UNK))func_0200fe6c)(id);
        ((void(*)(M2C_UNK))func_020055f4)(id);
        if (tmp == 0) {
            id = 0;
        } else {
            if ((u8)func_02010424() != 2) {
                id = 0;
            } else {
                id2 = (u16)func_0200558c();
                ((void(*)(M2C_UNK))func_0200fe5c)(id2);
                id = (u8)func_0201033c(0, &sp14, 4, 0, 0, 0, 6, 1, 0);
                ((void(*)(M2C_UNK))func_0200fe6c)(id2);
                ((void(*)(M2C_UNK))func_020055f4)(id2);
                if (id == 0) {
                    id = 0;
                }
            }
        }
    }
    M2C_FIELD(arg0, u8 *, 0x2050) = (u8)id;
    if ((id & 0xFF) == 0) {
        M2C_FIELD(arg0, u8 *, 0x2052) = 1;
    }
}

u8 func_02074d44(void *arg0) {
s32 func_0200558c(void); void func_020055f4(u8); void func_0200fe5c(u16); void func_0200fe6c(u8);
s32 func_0201033c(s32,s32 *,s32,s32,s32,s32,s32,s32,s32);
s32 out; u8 low; u8 result; u16 id;
if(!M2C_FIELD(arg0,u8 *,0x2050)) return 0;
if(M2C_FIELD(arg0,u8 *,0x2052)==1) return 0;
id=func_0200558c(); func_0200fe5c(id); low=id;
if(func_0201033c(0,&out,4,0,0,0,6,1,0)) result=1; else result=0;
func_0200fe6c(low); func_020055f4(low); return result;
}

void func_02074dec(s32 arg0) { (void)arg0; }

void func_020753f8(void *a, void *b, void *c, s32 d, u8 e, u32 f) {
void *func_020e34bc(u32); void func_020e35cc(void *); s32 func_0200558c(void); void func_020055f4(u8); void func_0200fe5c(u16); void func_0200fe6c(u8);
void func_02007ef4(void *,void *,u32); void func_02007e98(s32,void *,u32); void func_02008048(void *,void *,u32);
u32 func_020746fc(void *,void *); s32 func_0201033c(s32,s32 *,s32,s32,s32,s32,s32,s32,s32); s32 func_02010584(void);
u8 *p; s32 idx; u16 prev; s32 mask; u16 id; u8 ok; u32 n;
if(!M2C_FIELD(a,u8 *,0x2050)||M2C_FIELD(a,u8 *,0x2052)==1||!e)return;
p=func_020e34bc(0x400); prev=0xffff; idx=func_02074920(a);
func_02074a7c((List_02074920 *)((u8 *)a+0xc4c),(u16)idx,e,f,c);
id=func_0200558c();
mask=prev-0x10000;
while(d){
M2C_FIELD((u8 *)a+(idx>>2),u8 *,0xc0c)&=(mask^(3<<((idx&3)*2)));
M2C_FIELD((u8 *)a+(idx>>2),u8 *,0xc0c)|=3<<((idx&3)*2);
M2C_FIELD(p,u32 *,0)=0x32777364;
M2C_FIELD(p,u32 *,8)=M2C_FIELD((u8 *)a+idx*12,u32 *,0)+1;
if(prev==0xffff){
n=d+0x38; if(n>0x400)n=0x400; M2C_FIELD(p,u16 *,12)=n;
d-=M2C_FIELD(p,u16 *,12)-0x38;
M2C_FIELD(p,u32 *,20)=f;
if(c)func_02007ef4(c,p+24,32);else func_02007e98(0,p+24,32);
func_02007ef4(b,p+0x38,M2C_FIELD(p,u16 *,12)-(s32)((p+0x38)-p));
b=(u8 *)b+(M2C_FIELD(p,u16 *,12)-(s32)((p+0x38)-p));
}else{
n=d+0x14;if(n>0x400)n=0x400;M2C_FIELD(p,u16 *,12)=n;
d-=M2C_FIELD(p,u16 *,12)-0x14;
func_02007ef4(b,p+0x14,M2C_FIELD(p,u16 *,12)-0x14);
b=(u8 *)b+(M2C_FIELD(p,u16 *,12)-0x14);
}
M2C_FIELD(p,u8 *,14)=e;M2C_FIELD(p,u8 *,15)=1;M2C_FIELD(p,u16 *,16)=prev;
M2C_FIELD(p,u16 *,18)=d?func_02074920(a):0xffff;
M2C_FIELD(p,u32 *,4)=func_020746fc(a,p);
func_0200fe5c(id);
func_0201033c((s32)p,(s32 *)(idx<<10),M2C_FIELD(p,u16 *,12),0,0,1,7,10,2);
ok=func_02010584()!=0;((void(*)(u32))func_0200fe6c)(id);
if(!ok){M2C_FIELD((u8 *)a+0x2000,u8 *,0x52)=1;break;}
func_02008048(p+8,(u8 *)a+idx*12,12);
prev=idx;idx=M2C_FIELD(p,u16 *,18);
}
((void(*)(u32))func_020055f4)(id);func_020e35cc(p);
}

