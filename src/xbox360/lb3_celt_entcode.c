/* (C) 2001-2008 Timothy B. Terriberry
*/
/* Derived from CELT 0.6.1 libcelt/entcode.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Float build as linked into FMOD Ex. */
#include "lb3_celt.h"

#undef ec_ilog
#define ec_ilog fn_883C2F08
/* ec_ilog: number of bits needed to represent v (referenced by name from
   other sources under its placeholder). */
int ec_ilog(ec_uint32 _v){
  /*Branchless version (no EC_CLZ on this compiler).*/
  int ret;
  int m;
  ret=!!_v;
  m=!!(_v&0xFFFF0000)<<4;
  _v>>=m;
  ret|=m;
  m=!!(_v&0xFF00)<<3;
  _v>>=m;
  ret|=m;
  m=!!(_v&0xF0)<<2;
  _v>>=m;
  ret|=m;
  m=!!(_v&0xC)<<1;
  _v>>=m;
  ret|=m;
  ret+=!!(_v&0x2);
  return ret;
}
