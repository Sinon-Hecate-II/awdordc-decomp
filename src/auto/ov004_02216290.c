/* 1 function from 0x02216290 to 0x02217480 (ov004), found by ds-decomp. */
#include "common.h"
static inline void *RenderEntry(void *entries,s32 index){if(index<0)return 0;if(index>=64)return 0;return (u8 *)entries+index*0x20;}
static inline void *RenderSelection(void *entries){s32 i;for(i=0;i<64;i++){void *p=RenderEntry(entries,i);if((u8)((M2C_FIELD(p,u8 *,4)&2)!=0))return p;}return 0;}

extern const s16 gSinCosTable[2048];
extern const s16 data_020e7b30[2048];
extern const s16 data_020e6b30[2048];
extern const s16 data_020e8b30[2048];
extern u32 gFrameCounter;


#pragma push
#pragma optimization_level 3
void func_ov004_02216290(void *arg0){
void func_0200100c(void *);s32 func_02001fb4(s32,s32);s32 func_0207c8ec(s32,s32);
void func_02003fc8(s32,s32,s32,s32,s32,s32,s32,s32,s32);
void func_02001114(void *,s32,s32,s32);void func_02001068(void *,void *,s32,s32,s32);
void func_02001148(void *,void *,void *);void func_02007f68(void *,void *);void func_02003a70(void *);
void func_02087048(s32,s32);void func_020870dc(s32,s32,s32,s32,s32,s32,s32,s32);
void func_020878c4(s32,s32,s32,s32,s32,s32,s32,s32,s32);void func_0208718c(void);
void func_02087c6c(s32,s32,s32,s32,s32,s32);void func_ov004_02214814(s32,s32,s32,s32,s32,s32);
void func_02087a08(s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32);
void func_0200112c(void *,s32,s32);void func_02087064(s32,s32,s32,s32,s32);void func_02003aa8(void *);s32 func_0207cb88(s32);
s32 qp[12],qr[12],q2[12],q1[12],qt[12],qs[12],qm[12],q0[12],pivot[12],tr[12],sz[12],rot[12],mat[12],p2[12],p1[12],p0[12],d[12],c[12],b[12],a[12];s32 j,k,n,value,spacing,tex,flags,cx,cy,amount;void *link,*node; s32 scale,i,x,y,h,w,bottom,top;void *entry;
volatile u32 *gx=(volatile u32 *)0x04000440;
func_0200100c(a);func_0200100c(b);func_0200100c(c);
scale=func_02001fb4(4096,M2C_FIELD(arg0,s32 *,64));
M2C_FIELD(arg0,s16 *,68)=M2C_FIELD(arg0,s16 *,72)-((M2C_FIELD(arg0,s16 *,72)-M2C_FIELD(arg0,s16 *,68))*7)/8;
M2C_FIELD(arg0,s16 *,70)=M2C_FIELD(arg0,s16 *,74)-((M2C_FIELD(arg0,s16 *,74)-M2C_FIELD(arg0,s16 *,70))*7)/8;
switch(M2C_FIELD(arg0,u8 *,56)){
case 0:break;
case 1:M2C_FIELD(arg0,s16 *,76)=48-((48-M2C_FIELD(arg0,s16 *,76))*4)/5;M2C_FIELD(arg0,s16 *,78)=32-((32-M2C_FIELD(arg0,s16 *,78))*4)/5;break;
case 2:M2C_FIELD(arg0,s16 *,76)=-((-M2C_FIELD(arg0,s16 *,76)*7)/8);M2C_FIELD(arg0,s16 *,78)=-((-M2C_FIELD(arg0,s16 *,78)*7)/8);break;
}
if(M2C_FIELD(arg0,s32 *,64)==2048||M2C_FIELD(arg0,s32 *,64)==4096){
if(M2C_FIELD(arg0,s16 *,80)<96-func_0207c8ec(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,80)=96-func_0207c8ec(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096);
if(M2C_FIELD(arg0,s16 *,82)<57-func_0207c8ec(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,82)=57-func_0207c8ec(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096);
if(M2C_FIELD(arg0,s16 *,80)>160-func_0207c8ec(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,80)=160-func_0207c8ec(M2C_FIELD(arg0,s16 *,68)*M2C_FIELD(arg0,s32 *,64),4096);
if(M2C_FIELD(arg0,s16 *,82)>95-func_0207c8ec(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096))M2C_FIELD(arg0,s16 *,82)=95-func_0207c8ec(M2C_FIELD(arg0,s16 *,70)*M2C_FIELD(arg0,s32 *,64),4096);
}
if(M2C_FIELD(arg0,s32 *,64)==2048||M2C_FIELD(arg0,s32 *,64)==4096){
if(M2C_FIELD(arg0,s16 *,68)<0)M2C_FIELD(arg0,s16 *,68)=0;
if(M2C_FIELD(arg0,s16 *,70)<0)M2C_FIELD(arg0,s16 *,70)=0;
if(M2C_FIELD(arg0,s16 *,68)>512)M2C_FIELD(arg0,s16 *,68)=512;
if(M2C_FIELD(arg0,s16 *,70)>304)M2C_FIELD(arg0,s16 *,70)=304;
if(M2C_FIELD(arg0,s16 *,80)<256-func_0207c8ec(M2C_FIELD(arg0,s32 *,64)*512,4096))M2C_FIELD(arg0,s16 *,80)=256-func_0207c8ec(M2C_FIELD(arg0,s32 *,64)*512,4096);
if(M2C_FIELD(arg0,s16 *,82)<192-func_0207c8ec(M2C_FIELD(arg0,s32 *,64)*344,4096))M2C_FIELD(arg0,s16 *,82)=192-func_0207c8ec(M2C_FIELD(arg0,s32 *,64)*344,4096);
if(M2C_FIELD(arg0,s16 *,80)>0)M2C_FIELD(arg0,s16 *,80)=0;
if(M2C_FIELD(arg0,s16 *,82)>0)M2C_FIELD(arg0,s16 *,82)=0;
}
gx[0]=0;func_02003fc8(0,192,0,256,-1000,0,4096,1,0);
func_02001114(a,M2C_FIELD(arg0,s32 *,64),M2C_FIELD(arg0,s32 *,64),4096);
y=M2C_FIELD(arg0,s16 *,82);x=M2C_FIELD(arg0,s16 *,80);func_0200100c(b);func_02001068(b,b,x,y,0);
func_0200100c(d);func_02001148(a,b,d);func_02007f68(d,c);
gx[0]=3;gx[5]=0;gx[0]=2;func_02003a70(c);
{volatile u32 *cmd=(volatile u32 *)0x04000484;cmd[0]=0x20000000;cmd[-14]=0;cmd[-16]=0;}
func_02087048(0,31);func_020870dc(4,512,512,0,0,0,0,0);
func_020878c4(0,0,0,512,304,0,0,512,304);
func_02087048(0,31);func_0208718c();
func_02087c6c(0,M2C_FIELD(arg0,s16 *,70),512,M2C_FIELD(arg0,s16 *,70),2,32767);
func_02087c6c(M2C_FIELD(arg0,s16 *,68),0,M2C_FIELD(arg0,s16 *,68),304,2,32767);
x=256;y=152;w=0;h=0;entry=RenderSelection(M2C_FIELD(arg0,void **,92));
if(entry){w=M2C_FIELD(arg0,s16 *,76)/2;h=M2C_FIELD(arg0,s16 *,78)/2;x=M2C_FIELD(entry,s16 *,0);y=M2C_FIELD(entry,s16 *,2);}
if(w>0||h>0){func_02087048(0,31);func_0208718c();if(M2C_FIELD(arg0,s32 *,64)==4096)func_ov004_02214814(x-w,y-h,x+w,y+h,1,32767);else func_ov004_02214814(x-w,y-h,x+w-1,y+h-1,1,32767);}
gx[0]=3;gx[1]=0;{u16 phase=M2C_FIELD(arg0,u16 *,60);gx[5]=0;gx[12]=-((u32)((phase>>2)<<24)>>8);gx[12]=(u32)((phase>>3)<<24)>>8;gx[12]=0;}
if(M2C_FIELD(arg0,u8 *,57)){func_02087048(4,4);func_020870dc(3,256,256,6144,17,1,0,1);top=y-h;
func_02087a08(0,0,512,0,0,top,512,top,4,0,0,512,top);bottom=y+h+1;
func_02087a08(0,bottom,512,bottom,0,304,512,304,4,0,bottom,512,304);
func_02087a08(0,top,x-w,top,0,bottom,x-w,bottom,4,0,top,x-w,bottom);
func_02087a08(x+w+1,top,512,top,x+w+1,bottom,512,bottom,4,x+w+1,top,512,bottom);
}else{func_02087048(4,16);func_020870dc(3,256,256,5120,16,1,0,0);top=y-h;
func_02087a08(0,0,512,0,0,top,512,top,4,0,0,512,top);bottom=y+h+1;
func_02087a08(0,bottom,512,bottom,0,304,512,304,4,0,bottom,512,304);
func_02087a08(0,top,x-w,top,0,bottom,x-w,bottom,4,0,top,x-w,bottom);
func_02087a08(x+w+1,top,512,top,x+w+1,bottom,512,bottom,4,x+w+1,top,512,bottom);
}
*(volatile u32 *)0x04000448=1;gx[0]=2;func_02087048(5,12);func_0208718c();
{
s32 i_0,j_0,k_0,n_0,value_0,spacing_0,tex_0,flags_0,cx_0,cy_0,amount_0;void *link_0,*node_0;
for(i_0=0;i_0<64;i_0++){
node_0=RenderEntry(M2C_FIELD(arg0,void **,92),i_0);
if((u8)((M2C_FIELD(node_0,u8 *,4)&4)!=0))continue;
if(!(u8)((M2C_FIELD(node_0,u8 *,4)&1)!=0))continue;
func_0200100c(pivot);func_0200100c(tr);func_0200100c(sz);func_0200100c(rot);func_0200100c(mat);
amount_0=M2C_FIELD(node_0,s32 *,12);cx_0=M2C_FIELD(node_0,s16 *,0);cy_0=M2C_FIELD(node_0,s16 *,2);if(!amount_0)continue;
link_0=0;for(j_0=0;j_0<4;j_0++){void *candidate=M2C_FIELD(node_0,void **,16+j_0*4);if(candidate&&(u8)(!(u8)((M2C_FIELD(candidate,u8 *,4)&4)!=0))){link_0=candidate;break;}}
if(!link_0||!(u8)((M2C_FIELD(link_0,u8 *,4)&1)!=0))continue;
if(M2C_FIELD(link_0,s16 *,0)>cx_0){func_0200100c(pivot);func_02001068(pivot,pivot,0,-4,0);func_02001114(sz,(amount_0*64)/8,4096,4096);func_0200112c(rot,gSinCosTable[0],gSinCosTable[1]);func_0200100c(tr);func_02001068(tr,tr,cx_0,cy_0,0);}
if(M2C_FIELD(link_0,s16 *,0)<cx_0){func_0200100c(pivot);func_02001068(pivot,pivot,0,-4,0);func_02001114(sz,(amount_0*64)/8,4096,4096);func_0200112c(rot,data_020e7b30[0],data_020e7b30[1]);func_0200100c(tr);func_02001068(tr,tr,cx_0,cy_0,0);}
if(M2C_FIELD(link_0,s16 *,2)>cy_0){func_0200100c(pivot);func_02001068(pivot,pivot,0,-4,0);func_02001114(sz,(amount_0*38)/8,4096,4096);func_0200112c(rot,data_020e6b30[0],data_020e6b30[1]);func_0200100c(tr);func_02001068(tr,tr,cx_0,cy_0,0);}
if(M2C_FIELD(link_0,s16 *,2)<cy_0){func_0200100c(pivot);func_02001068(pivot,pivot,0,-4,0);func_02001114(sz,(amount_0*38)/8,4096,4096);func_0200112c(rot,data_020e8b30[0],data_020e8b30[1]);func_0200100c(tr);func_02001068(tr,tr,cx_0,cy_0,0);}
func_0200100c(p0);func_02001148(pivot,sz,p0);func_0200100c(p1);func_02001148(p0,rot,p1);func_0200100c(p2);func_02001148(p1,tr,p2);func_02007f68(p2,mat);
func_02087064(3,8,8,7424,24);*(volatile u32 *)0x04000444=0;gx[0]=2;func_02003aa8(mat);
func_020878c4(0,0,5,8,8,0,0,8,8);*(volatile u32 *)0x04000448=1;
}
}
{
s32 i_1,j_1,k_1,n_1,value_1,spacing_1,tex_1,flags_1,cx_1,cy_1,amount_1;void *link_1,*node_1;
func_02087048(0,31);
for(i_1=0;i_1<64;i_1++){
node_1=RenderEntry(M2C_FIELD(arg0,void **,92),i_1);
func_0200100c(qt);func_0200100c(qs);func_0200100c(qm);
tex_1=M2C_FIELD(node_1,u8 *,5)*32;if((u8)((M2C_FIELD(node_1,u8 *,4)&2)!=0))tex_1+=16;
cx_1=M2C_FIELD(node_1,s16 *,0);cy_1=M2C_FIELD(node_1,s16 *,2);
if(!(u8)((M2C_FIELD(node_1,u8 *,4)&1)!=0))continue;
amount_1=func_0207c8ec(scale*M2C_FIELD(node_1,s32 *,8),4096);
func_02001114(qs,amount_1,amount_1,4096);func_0200100c(qt);func_02001068(qt,qt,cx_1,cy_1,0);func_0200100c(q0);func_02001148(qs,qt,q0);func_02007f68(q0,qm);
*(volatile u32 *)0x04000444=0;gx[0]=2;func_02003aa8(qm);
flags_1=0;if(M2C_FIELD(node_1,u8 *,5)!=0)flags_1=2;if((u8)((M2C_FIELD(node_1,u8 *,4)&4)!=0))flags_1++;
func_02087064(3,256,32,7168,flags_1+18);func_020878c4(-8,-8,6,16,16,tex_1,0,tex_1+16,16);
if(amount_1==4096&&(gFrameCounter&63)<48){func_02087064(3,256,32,7168,22);
if((u8)((M2C_FIELD(node_1,u8 *,4)&16)!=0))func_020878c4(2,6,6,32,8,224,8,256,16);
if((u8)((M2C_FIELD(node_1,u8 *,4)&8)!=0))func_020878c4(2,6,6,32,8,224,0,256,8);
}
*(volatile u32 *)0x04000444=1;
}
}
{
s32 i_2,j_2,k_2,n_2,value_2,spacing_2,tex_2,flags_2,cx_2,cy_2,amount_2;void *link_2,*node_2;
func_02087048(0,31);
for(i_2=0;i_2<64;i_2++){
node_2=RenderEntry(M2C_FIELD(arg0,void **,92),i_2);
func_0200100c(qp);func_0200100c(qr);func_0200100c(q2);
value_2=M2C_FIELD(node_2,u8 *,6);cx_2=M2C_FIELD(node_2,s16 *,0);cy_2=M2C_FIELD(node_2,s16 *,2);tex_2=0;spacing_2=8;n_2=func_0207cb88(value_2);
if(!(u8)((M2C_FIELD(node_2,u8 *,4)&1)!=0)||scale!=4096)continue;
if((u8)((M2C_FIELD(node_2,u8 *,4)&2)!=0)){spacing_2=12;tex_2=16;}
cx_2-=((n_2+1)*spacing_2)/2;func_0200100c(qp);func_02001068(qp,qp,cx_2,cy_2-20,0);func_0200100c(q1);func_02001148(qr,qp,q1);func_02007f68(q1,q2);
func_02087064(3,256,32,7296,23);*(volatile u32 *)0x04000444=0;gx[0]=2;func_02003aa8(q2);
flags_2=(u8)((M2C_FIELD(node_2,u8 *,4)&4)!=0)?192:176;
func_020878c4(0,0,8,16,16,flags_2,tex_2,flags_2+16,tex_2+16);
for(j_2=0;j_2<n_2;j_2++){k_2=(value_2%10)*16;func_020878c4((n_2-j_2)*spacing_2,0,8,16,16,k_2,tex_2,k_2+16,tex_2+16);value_2/=10;}
*(volatile u32 *)0x04000448=1;
}
}
*(volatile u32 *)0x04000480=32767;*(volatile u32 *)0x04000448=1;M2C_FIELD(arg0,u16 *,60)++;
}
#pragma pop
