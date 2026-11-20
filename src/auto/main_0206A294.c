/* 10 functions from 0x0206A294 to 0x0206ADF8 (main), found by ds-decomp. */
#include "common.h"

/* strtod: parse a floating-point value from the character stream p, whose
   reader is ScanFloatStreamRead; stops after `count` characters.  end, when
   non-null, receives the stream position just past the parsed text, and an
   underflow/overflow raises errno 34 (ERANGE). */
double func_0206a294(M2C_UNK p,M2C_UNK end){
double ScanFloatStrtod();double fabs(double);void ScanFloatStreamRead();extern s32 gErrno;
s32 count,overflow;M2C_UNK state[2];double value,absolute;
state[1]=0;state[0]=p;
value=ScanFloatStrtod(0x7fffffff,ScanFloatStreamRead,state,&count,&overflow);
if(end)M2C_FIELD(end,s32*,0)=p+count;
absolute=fabs(value);
if(overflow || (value!=0.0 && (absolute<2.2250738585072014e-308 || absolute>1.7976931348623157e308)))gErrno=34;
return value;
}

/* atof: parse the double that begins a null-terminated string, ignoring where parsing stopped. */
void atof(M2C_UNK string) {
    double func_0206a294(M2C_UNK, M2C_UNK);
    func_0206a294(string, 0);
}

#pragma opt_peephole off
u32 ScanUint(s32 base, s32 width, s32 (*read)(void *, s32, s32), void *stream, s32 *count, s32 *negative, s32 *overflow)
{
  extern u16 gCharClassTable[];
  extern u8 data_020eacc0[];
  u32 U32DivideRem(u32, u32);
  register s32 state;
  s32 ch;
  register u32 consumed;
  s32 spaces;
  u32 limit;
  u32 value;
  state = 0;
  spaces = (*overflow = state);
  *negative = state;
  limit = state;
  consumed = 0;
  value = state;
  state = 1;
  if ((((base < 0) || (base == 1)) || (base > 36)) || (width < 1))
  {
    state = 64;
  }
  else
  {
    ch = read(stream, spaces, (consumed = spaces + 1, spaces));
  }
  if (base)
  {
    limit = U32DivideRem(~0U, base);
  }
  while ((((s32)consumed <= width) && (ch != (-1))) && (!(state & 96)))
  {
    switch (state)
    {
      case 1:
        if (((ch < 0) || (ch >= 128)) ? (0) : (gCharClassTable[ch] & 256))
      {
        ch = read(stream, 0, 0);
        ++spaces;
        break;
      }
        if (ch == '+')
      {
        ++consumed;
        ch = read(stream, 0, 0);
      }
      else
        if (ch == '-')
      {
        ++consumed;
        ch = read(stream, 0, 0);
        *negative = 1;
      }
        state = 2;
        break;

      case 2:
        if (((base == 0) || (base == 16)) && (ch == '0'))
      {
        state = 4;
        ++consumed;
        ch = read(stream, 0, 0);
      }
      else
      {
        state = 8;
      }
        break;

      case 4:
        if ((ch == 'X') || (ch == 'x'))
      {
        base = 16;
        state = 8;
        ++consumed;
        ch = read(stream, 0, 0);
      }
      else
      {
        if (!base)
        {
          base = 8;
        }
        state = 16;
      }
        break;

      case 8:

      case 16:
        if (!base)
      {
        base = 10;
      }
        if (!limit)
      {
        limit = U32DivideRem(~0U, base);
      }
        if (((ch < 0) || (ch >= 128)) ? (0) : (gCharClassTable[ch] & 8))
      {
        ch -= '0';
        if (ch >= base)
        {
          state = (state == 16) ? (32) : (64);
          ch += '0';
          break;
        }
      }
      else
      {
        if ((!(((ch < 0) || (ch >= 128)) ? (0) : (gCharClassTable[ch] & 1))) || (((((ch < 0) || (ch >= 128)) ? (ch) : (data_020eacc0[ch])) - ('A' - 10)) >= base))
        {
          state = (state == 16) ? (32) : (64);
          break;
        }
        ch = ((ch < 0) || (ch >= 128)) ? (ch) : (data_020eacc0[ch]);
        ch -= 'A' - 10;
      }
        if (value > limit)
      {
        *overflow = 1;
      }
        value *= base;
        if (((u32) ch) > ((~0U) - value))
      {
        *overflow = 1;
      }
        value += ch;
        state = 16;
        ++consumed;
        ch = read(stream, 0, 0);
        break;

    }

  }

  if (!(state & 52))
  {
    value = 0;
    *count = 0;
  }
  else
  {
    *count = (consumed - 1) + spaces;
  }
  read(stream, ch, 1);
  return value;
}
#pragma opt_peephole reset
u64 func_0206a76c(s32 base,s32 width,s32 (*get)(void *,s32,s32),void *ctx,s32 *count,s32 *negative,s32 *overflow) {
extern u16 gCharClassTable[]; extern u8 data_020eacc0[];
s32 state,c,n,space,d; u64 limit,value;
u64 U64Divide(u64,u64);
*overflow=0;value=0;limit=0;*negative=0;state=1;space=0;n=0;
if(base<0 || base==1 || base>36 || width<1)state=64;
else {n++;c=get(ctx,0,0);if(base)limit=U64Divide(~(u64)0,(s64)base);}
while(n<=width && c!=-1 && !(state&96)){
switch(state){
case 1:
if(((c<0 || c>=128)?0:(gCharClassTable[c]&256))){c=get(ctx,0,0);space++;break;}
if(c=='+'){n++;c=get(ctx,0,0);}else if(c=='-'){n++;c=get(ctx,0,0);*negative=1;}state=2;break;
case 2:
if((base==0 || base==16)&&c=='0'){state=4;n++;c=get(ctx,0,0);}else state=8;break;
case 4:
if(c=='X'||c=='x'){base=16;state=8;n++;c=get(ctx,0,0);}else {if(!base)base=8;state=16;}break;
case 8: case 16:
if(!base)base=10;if(!limit)limit=U64Divide(~(u64)0,(s64)base);
if(((c<0 || c>=128)?0:(gCharClassTable[c]&8))){c-='0';if(c>=base){state=state==16?32:64;c+='0';break;}}
else {
if(!((c<0||c>=128)?0:(gCharClassTable[c]&1)) || (c<0||c>=128?c:data_020eacc0[c])-55>=base){state=state==16?32:64;break;}
if(c<0){}else if(c<128)c=data_020eacc0[c];c-=55;
}
if(value>limit)*overflow=1;value*=base;if((u64)(s64)c>~(u64)0-value)*overflow=1;value+=c;state=16;n++;c=get(ctx,0,0);break;
}}
if(!(state&52)){value=0;*count=0;}else *count=n-1+space;
get(ctx,c,1);return value;
}

#pragma opt_strength_reduction off
#pragma opt_instruction_scheduling off
/* strtoul: parse an unsigned 32-bit integer from the null-terminated string
 * `text` through the ScanFloatStreamRead reader.  `endptr`, when non-null,
 * receives the position just past the parsed text; a value too large for 32
 * bits gives ULONG_MAX and sets errno to ERANGE (34), and a leading '-' negates
 * the parsed magnitude. */
u32 strtoul(s8 *text, s8 **endptr, s32 base) {
    u32 ScanUint();
    void ScanFloatStreamRead();
    extern s32 gErrno;
    s32 count;
    s32 negative;
    s32 overflow;
    M2C_UNK state[2];
    u32 value;
    state[0] = (M2C_UNK)text;
    state[1] = 0;
    value = ScanUint(base, 0x7fffffff, ScanFloatStreamRead, state, &count, &negative, &overflow);
    if (endptr != 0) {
        *endptr = text + count;
    }
    if (overflow != 0) {
        value = -1;
        gErrno = 34; /* ERANGE */
        goto done;
    }
    if (negative != 0) {
        return -value;
    }
    done: return value;
}
#pragma opt_strength_reduction reset
#pragma opt_instruction_scheduling reset
/* strtol: parse a signed integer from the character stream text, read through
   ScanFloatStreamRead; base is the radix (0 selects it from a 0/0x prefix).
   endptr, when non-null, receives the stream position just past the parsed
   text.  A value that does not fit in 32 bits is clamped to LONG_MAX/LONG_MIN
   and raises errno 34 (ERANGE). */
s32 strtol(M2C_UNK text,M2C_UNK endptr,M2C_UNK base){
u32 ScanUint();void ScanFloatStreamRead();extern s32 gErrno;
s32 count,negative,overflow; M2C_UNK state[2];u32 value;
state[0]=text;state[1]=0;
value=ScanUint(base,0x7fffffff,ScanFloatStreamRead,state,&count,&negative,&overflow);
if(endptr)M2C_FIELD(endptr,s32*,0)=text+count;
if(overflow || (!negative && value>0x7fffffffU) || (negative && value>0x80000000U)){
value=negative?0x80000000:0x7fffffff;gErrno=34;return value;
}
return negative?-value:value;
}

void ParseInt(M2C_UNK arg0) {
    M2C_UNK strtol(M2C_UNK, M2C_UNK, M2C_UNK);
    strtol(arg0, 0, 0xA);
}

#pragma opt_propagation off
s32 func_0206ad4c(void *arg0, s32 arg1) {
    s32 temp_r3;
    s32 var_r1;
    u32 temp_r2;

    var_r1 = arg1;
    if ((arg0 == NULL) || (temp_r3 = M2C_FIELD(arg0, s32 *, 4), (((u32) (temp_r3 << 0x16) >> 0x1D) == 0))) {
        return 0;
    }
    temp_r2 = (u32) (temp_r3 << 0x14) >> 0x1E;
    switch (temp_r2) {
    case 2:
        var_r1 = 1;
        break;
    case 0:
        if (var_r1 > 0) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) ((temp_r3 & ~0xC00) | 0x800);
        } else if (var_r1 < 0) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) ((temp_r3 & ~0xC00) | 0x400);
        }
        break;
    case 1:
        var_r1 = -1;
        break;
    }
    return var_r1;
}
#pragma opt_propagation reset
void func_0206adc0(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK MemCopy(M2C_UNK, M2C_UNK, s32);
    MemCopy(arg0, arg1, arg2 * 2);
}

u16 *func_0206add0(u16 *p,s32 value,u32 n) {
if(n){do {if(*p==value)return p;p++;}while(--n);}
return NULL;
}

