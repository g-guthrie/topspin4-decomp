/* (C) 2007 Jean-Marc Valin, CSIRO
*/
/* Derived from CELT 0.6.1 libcelt/laplace.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Float build as linked into FMOD Ex; only the
   decoder's start function is among the open-source functions still
   unmatched. */
#include "lb3_celt.h"

/* rangedec.c */
unsigned fn_883B5418(ec_dec *_this, unsigned _ft);                         /* ec_decode */
void lb3_celt_ec_dec_update_883B54C0(ec_dec *_this, unsigned _fl, unsigned _fh, unsigned _ft); /* ec_dec_update */
#define ec_decode fn_883B5418
#define ec_dec_update lb3_celt_ec_dec_update_883B54C0
#define ec_laplace_decode_start lb3_celt_ec_laplace_decode_start_883C0310

int ec_laplace_decode_start(ec_dec *dec, int decay, int fs)
{
   int val=0;
   int fl, fh, fm;
   unsigned int ft;
   fl = 0;
   ft = 32768;
   fh = fs;
   fm = ec_decode(dec, ft);
   while (fm >= fh && fs != 0)
   {
      fl = fh;
      fs = (fs*(ec_int32)decay)>>14;
      if (fs == 0 && (unsigned int)(fh+2) <= ft)
      {
         fs = 1;
      }
      fh += fs*2;
      val++;
   }
   if (fl>0)
   {
      if (fm >= fl+fs)
      {
         val = -val;
         fl += fs;
      } else {
         fh -= fs;
      }
   }
   /* Preventing an infinite loop in case something screws up in the decoding */
   if (fl==fh)
      fl--;
   ec_dec_update(dec, fl, fh, ft);
   return val;
}
