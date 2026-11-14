/* (C) 2007-2008 Jean-Marc Valin, CSIRO
   (C) 2008-2009 Gregory Maxwell */
/* Derived from CELT 0.6.1 libcelt/bands.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Float build as linked into FMOD Ex. */
#include "lb3_celt.h"

#define stereo_band_mix lb3_celt_stereo_band_mix_883B3FA0

#define SQRT_HALF_F lbl_880353E0
#define ONE_F lbl_88001A68

/* Mid-side or intensity rotation of one band of a stereo signal. */
void stereo_band_mix(const CELTMode *m, celt_norm_t *X, const celt_ener_t *bank, int stereo_mode, int bandID, int dir)
{
   int i = bandID;
   const celt_int16_t *eBands = m->eBands;
   const int C = CHANNELS(m);
   int j;
   celt_word16_t a1, a2;
   if (stereo_mode==0)
   {
      /* Do mid-side when not doing intensity stereo */
      a1 = SQRT_HALF_F;
      a2 = dir*SQRT_HALF_F;
   } else {
      celt_word16_t left, right;
      celt_word16_t norm;
      left = bank[i];
      right = bank[i+m->nbEBands];
      norm = EPSILON + celt_sqrt(EPSILON+left*left+right*right);
      {
         /* the compiler turns the two divisions by norm into one reciprocal */
         celt_word16_t inv = ONE_F/norm;
         a1 = inv*left;
         a2 = (inv*right)*dir;
      }
   }
   for (j=eBands[i];j<eBands[i+1];j++)
   {
      celt_norm_t r, l;
      l = X[j*C];
      r = X[j*C+1];
      X[j*C] = a1*l + a2*r;
      X[j*C+1] = a1*r - a2*l;
   }
}
