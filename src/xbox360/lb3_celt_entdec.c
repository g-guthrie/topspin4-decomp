/* (C) 2001-2008 Timothy B. Terriberry
   (C) 2008 Jean-Marc Valin */
/* Derived from CELT 0.6.1 libcelt/entdec.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Float build as linked into FMOD Ex; only the
   bit and uint readers are of interest here, the byte buffer helpers are in
   other units. */
#include "lb3_celt.h"

/* os_support.h: celt_notify prints "notification: %s\n" on stderr */
extern const char lbl_88035378[]; /* "notification: %s\n" */
extern const char lbl_8803538C[]; /* "uint decode error" */
#define celt_notify(str) fn_88569190(aud1_stderr, lbl_88035378, (str))

#define EC_UNIT_BITS (8)
#define EC_UNIT_MASK ((1U<<EC_UNIT_BITS)-1)

/* rangedec.c */
unsigned fn_883B5418(ec_dec *_this, unsigned _ft);                         /* ec_decode */
unsigned lb3_celt_ec_decode_bin_883B5468(ec_dec *_this, unsigned bits);   /* ec_decode_bin */
void lb3_celt_ec_dec_update_883B54C0(ec_dec *_this, unsigned _fl, unsigned _fh, unsigned _ft); /* ec_dec_update */
#define ec_decode fn_883B5418
#define ec_decode_bin lb3_celt_ec_decode_bin_883B5468
#define ec_dec_update lb3_celt_ec_dec_update_883B54C0

ec_uint32 ec_dec_bits(ec_dec *_this,int _ftb){
  ec_uint32 t;
  unsigned  s;
  unsigned  ft;
  t=0;
  while(_ftb>EC_UNIT_BITS){
    s=ec_decode_bin(_this,EC_UNIT_BITS);
    ec_dec_update(_this,s,s+1,EC_UNIT_MASK+1);
    t=(t<<EC_UNIT_BITS)|s;
    _ftb-=EC_UNIT_BITS;
  }
  ft=1U<<_ftb;
  s=ec_decode_bin(_this,_ftb);
  ec_dec_update(_this,s,s+1,ft);
  t=(t<<_ftb)|s;
  return t;
}

ec_uint32 ec_dec_uint(ec_dec *_this,ec_uint32 _ft){
  ec_uint32 t;
  unsigned  ft;
  unsigned  s;
  int       ftb;
  t=0;
  /*In order to optimize EC_ILOG(), it is undefined for the value 0.*/
  celt_assert(_ft>1);
  _ft--;
  ftb=EC_ILOG(_ft);
  if(ftb>EC_UNIT_BITS){
    ftb-=EC_UNIT_BITS;
    ft=(unsigned)(_ft>>ftb)+1;
    s=ec_decode(_this,ft);
    ec_dec_update(_this,s,s+1,ft);
    t=(t<<EC_UNIT_BITS)|s;
    t = (t<<ftb)|ec_dec_bits(_this,ftb);
    if (t>_ft)
    {
       celt_notify(lbl_8803538C);
       t = _ft;
    }
    return t;
  } else {
    _ft++;
    s=ec_decode(_this,(unsigned)_ft);
    ec_dec_update(_this,s,s+1,(unsigned)_ft);
    t=(t<<ftb)|s;
    return t;
  }
}
