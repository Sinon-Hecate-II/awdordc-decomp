/* 1 function from 0x020A9A30 to 0x020AA93C (main), found by ds-decomp. */
#include "common.h"
extern char data_02126bf0[],data_02126c00[],data_02126c18[],data_02126c24[],data_02126c34[],data_02126c44[],data_02126c54[],data_02126c64[],data_02126c74[],data_02126c84[],data_02126c94[],data_02126ca8[],data_02126cbc[],data_02126ccc[],data_02126ce0[],data_02126cf4[],data_02126d08[],data_02126d10[],data_02126d18[],data_02126d28[],data_02126d38[],data_02126d44[],data_02126d50[],data_02126d60[],data_02126d6c[],data_02126d78[],data_02126d84[],data_02126d90[],data_02126d9c[],data_02126dac[],data_02126dbc[],data_02126dcc[],data_02126ddc[],data_02126dec[],data_02126df8[],data_02126e04[],data_02126e10[],data_02126e1c[],data_02126e2c[],data_02126e3c[],data_02126e4c[],data_02126e5c[],data_02126e68[],data_02126e78[],data_02126e84[],data_02126e94[],data_02126ea4[],data_02126eb4[],data_02126ec4[],data_02126ed4[],data_02126ee4[],data_02126ef4[],data_02126f04[],data_02126f14[],data_02126f24[],data_02126f38[],data_02126f48[],data_02126f5c[],data_02126f6c[],data_02126f7c[],data_02126f90[],data_02126fa0[],data_02126fb0[],data_02126fc0[],data_02126fd4[],data_02126fe4[],data_02126ff0[],data_02126ffc[],data_02127008[],data_02127014[],data_02127020[],data_02127030[],data_02127040[],data_02127054[],data_0212706c[],data_02127060[],data_02127068[],data_02127088[],data_0212707c[],data_02127084[],data_021270a4[],data_02127098[],data_021270a0[],data_021270b4[],data_021270c4[],data_021270d8[],data_021270ec[],data_021270fc[],data_0212710c[],data_0212711c[],data_02127130[],data_0212714c[],data_02127164[],data_0212717c[],data_02127194[],data_021271ac[],data_021271c8[],data_021271e0[],data_021271fc[],data_02127214[],data_0212722c[],data_02127248[],data_02127260[],data_0212727c[],data_02127298[],data_021272b4[],data_021272d0[],data_021272e8[],data_021272f8[],data_02127308[],data_02127318[],data_02127328[],data_02127334[],data_02127340[],data_02127348[];
extern char *data_02126a90;extern u16 **gCur3DSpriteEngine;
char *func_020e3218(void *);s32 StringFormat(char *,const char *,...);
void func_02080c50(void *,s32);void func_020814e4(void *);void func_0200bc5c(void *);void func_02081590(void *,s32);void func_02081528(void);void func_02080cfc(void *,s32);


int func_020a9a30(int a,int b,int c,int d){char name[256],path[256];char *base=data_02126bf0;u16 size;
switch(a){
case 0:base=data_02126c00;switch(b){case 0:switch(c){case 0:StringFormat(name,func_020e3218(data_02126c18));break;
case 1:StringFormat(name,func_020e3218(data_02126c24));break;
case 2:StringFormat(name,func_020e3218(data_02126c34));break;
case 3:StringFormat(name,func_020e3218(data_02126c44));break;
case 4:StringFormat(name,func_020e3218(data_02126c54));break;
case 5:StringFormat(name,func_020e3218(data_02126c64));break;
case 6:StringFormat(name,func_020e3218(data_02126c74));break;
case 7:StringFormat(name,func_020e3218(data_02126c84));break;
case 8:StringFormat(name,func_020e3218(data_02126c94));break;
case 9:StringFormat(name,func_020e3218(data_02126ca8));break;
case 10:StringFormat(name,func_020e3218(data_02126cbc));break;
case 11:StringFormat(name,func_020e3218(data_02126ccc));break;
case 12:StringFormat(name,func_020e3218(data_02126ce0));break;
case 13:StringFormat(name,func_020e3218(data_02126cf4));break;
case 14:StringFormat(name,func_020e3218(data_02126d08));break;
case 15:StringFormat(name,func_020e3218(data_02126d10));break;
case 16:StringFormat(name,func_020e3218(data_02126d18));break;
case 17:StringFormat(name,func_020e3218(data_02126d28));break;
case 18:StringFormat(name,func_020e3218(data_02126d38));break;
case 19:StringFormat(name,func_020e3218(data_02126d44));break;
case 20:StringFormat(name,func_020e3218(data_02126d50));break;
case 21:StringFormat(name,func_020e3218(data_02126d60));break;
case 22:StringFormat(name,func_020e3218(data_02126d6c));break;
case 23:StringFormat(name,func_020e3218(data_02126d78));break;
case 24:StringFormat(name,func_020e3218(data_02126d84));break;
case 25:StringFormat(name,func_020e3218(data_02126d90));break;
case 26:StringFormat(name,func_020e3218(data_02126d9c));break;
case 27:StringFormat(name,func_020e3218(data_02126dac));break;
case 28:StringFormat(name,func_020e3218(data_02126dbc));break;
case 29:StringFormat(name,func_020e3218(data_02126dcc));break;
case 30:StringFormat(name,func_020e3218(data_02126ddc));break;
case 31:StringFormat(name,func_020e3218(data_02126dec));break;
case 32:StringFormat(name,func_020e3218(data_02126df8));break;
case 33:StringFormat(name,func_020e3218(data_02126e04));break;
case 34:StringFormat(name,func_020e3218(data_02126e10));break;
case 35:StringFormat(name,func_020e3218(data_02126e1c));break;
case 36:StringFormat(name,func_020e3218(data_02126e2c));break;
case 37:StringFormat(name,func_020e3218(data_02126e3c));break;
case 38:StringFormat(name,func_020e3218(data_02126e4c));break;
case 39:StringFormat(name,func_020e3218(data_02126e5c));break;
case 40:StringFormat(name,func_020e3218(data_02126e68));break;
case 41:StringFormat(name,func_020e3218(data_02126e78));break;
case 42:StringFormat(name,func_020e3218(data_02126e84));break;
case 43:StringFormat(name,func_020e3218(data_02126e94));break;
case 44:StringFormat(name,func_020e3218(data_02126ea4));break;
case 45:StringFormat(name,func_020e3218(data_02126eb4));break;
case 46:StringFormat(name,func_020e3218(data_02126ec4));break;
case 47:StringFormat(name,func_020e3218(data_02126ed4));break;
case 48:StringFormat(name,func_020e3218(data_02126ee4));break;
case 49:StringFormat(name,func_020e3218(data_02126ef4));break;
case 50:StringFormat(name,func_020e3218(data_02126f04));break;
case 51:StringFormat(name,func_020e3218(data_02126f14));break;
case 52:StringFormat(name,func_020e3218(data_02126f24));break;
case 53:StringFormat(name,func_020e3218(data_02126f38));break;
case 54:StringFormat(name,func_020e3218(data_02126f48));break;
case 55:StringFormat(name,func_020e3218(data_02126f5c));break;
case 56:StringFormat(name,func_020e3218(data_02126f6c));break;
case 57:StringFormat(name,func_020e3218(data_02126f7c));break;
case 58:StringFormat(name,func_020e3218(data_02126f90));break;
case 59:StringFormat(name,func_020e3218(data_02126fa0));break;
case 60:StringFormat(name,func_020e3218(data_02126fb0));break;
case 61:StringFormat(name,func_020e3218(data_02126fc0));break;
case 62:StringFormat(name,func_020e3218(data_02126fd4));break;
case 63:StringFormat(name,func_020e3218(data_02126fe4));break;
case 64:StringFormat(name,func_020e3218(data_02126ff0));break;
case 65:StringFormat(name,func_020e3218(data_02126ffc));break;
case 66:StringFormat(name,func_020e3218(data_02127008));break;
case 67:StringFormat(name,func_020e3218(data_02127014));break;
case 68:StringFormat(name,func_020e3218(data_02127020));break;
case 69:StringFormat(name,func_020e3218(data_02127030));break;
case 70:StringFormat(name,func_020e3218(data_02127040));break;
case 71:return 0;}break;case 1:break;case 2:StringFormat(name,data_02127054);break;}break;
case 1:switch(b){case 0:switch(c){case 0:StringFormat(name,data_0212706c,((u32)(**gCur3DSpriteEngine<<17)>>30)?data_02127060:data_02127068);break;case 1:StringFormat(name,data_02127088,((u32)(**gCur3DSpriteEngine<<17)>>30)?data_0212707c:data_02127084);break;case 2:StringFormat(name,data_021270a4,((u32)(**gCur3DSpriteEngine<<17)>>30)?data_02127098:data_021270a0);break;case 3:StringFormat(name,data_021270b4);break;case 4:StringFormat(name,func_020e3218(data_021270c4));break;case 5:StringFormat(name,data_021270d8);break;}break;case 1:break;case 2:switch(c){case 0:StringFormat(name,data_021270ec);break;case 1:StringFormat(name,data_021270fc);break;case 2:StringFormat(name,data_0212710c);break;case 3:StringFormat(name,data_0212711c);break;}break;}break;
case 2:base=data_02127130;switch(b){case 0:switch(c){case 0:StringFormat(name,func_020e3218(data_0212714c));break;case 1:StringFormat(name,func_020e3218(data_02127164));break;case 2:StringFormat(name,func_020e3218(data_0212717c));break;case 3:StringFormat(name,func_020e3218(data_02127194));break;case 4:StringFormat(name,func_020e3218(data_021271ac));break;case 5:StringFormat(name,func_020e3218(data_021271c8));break;case 6:StringFormat(name,func_020e3218(data_021271e0));break;case 7:StringFormat(name,func_020e3218(data_021271fc));break;case 8:StringFormat(name,func_020e3218(data_02127214));break;case 9:StringFormat(name,func_020e3218(data_0212722c));break;case 10:StringFormat(name,func_020e3218(data_02127248));break;case 11:StringFormat(name,func_020e3218(data_02127260));break;case 12:StringFormat(name,func_020e3218(data_0212727c));break;case 13:StringFormat(name,func_020e3218(data_02127298));break;case 14:StringFormat(name,func_020e3218(data_021272b4));break;case 15:StringFormat(name,func_020e3218(data_021272d0));break;}break;case 1:StringFormat(name,data_021272e8);break;case 2:StringFormat(name,data_021272f8);break;}break;
case 3:switch(b){case 0:StringFormat(name,data_02127308);break;case 2:StringFormat(name,data_02127318);break;}break;
case 4:switch(b){case 0:StringFormat(name,func_020e3218(data_02127328));break;case 2:StringFormat(name,data_02126a90);break;}break;
case 5:switch(b){case 0:StringFormat(name,func_020e3218(data_02127334));break;case 2:StringFormat(name,data_02126a90);break;}break;
}
StringFormat(path,data_02127340,base,name);
if(b==2){func_02080c50(path,d);M2C_FIELD(gCur3DSpriteEngine,u8 *,70)|=16;}
else if(a==2){func_0200bc5c(base);func_020814e4(func_020e3218(data_02127348));func_02081590(name,d);func_02081528();}
else func_02080cfc(path,d);
size=0;if(c&1)size+=12;if(c&2)size+=12;if(c&3)size+=44;if(c&4)size+=28;return size;
}
