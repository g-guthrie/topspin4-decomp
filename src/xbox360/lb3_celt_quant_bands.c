/* (C) 2007-2008 Jean-Marc Valin, CSIRO
*/
/* Derived from CELT 0.6.1 libcelt/quant_bands.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Float build as linked into FMOD Ex; only the
   decoder-side energy functions are linked from this file (the loops are
   written in the inverted do-while form the compiler produced). */
#include "lb3_celt.h"

#define unquant_fine_energy lb3_celt_unquant_fine_energy_883B2038

/* Constants come from the image's shared float pool: 0.5f, 1.f/16384 and ln 2.
   They are copied into locals in the loop pre-header, as the compiler did
   with the literals of the original build. */
#define HALF_F lbl_88001978
#define SCALE_1_16384 lbl_880291C0
#define LN2_D lbl_88035330

void unquant_fine_energy(const CELTMode *m, celt_ener_t *eBands, celt_word16_t *oldEBands, int *fine_quant, ec_dec *dec)
{
   int i, c;
   const int C = CHANNELS(m);
   i=0;
   /* Decode finer resolution */
   if (m->nbEBands > 0) {
   const celt_word16_t scale = SCALE_1_16384;
   const celt_word16_t half = HALF_F;
   do
   {
      if (fine_quant[i] > 0) {
      c=0;
      do {
         int q2;
         celt_word16_t offset;
         q2 = ec_dec_bits(dec, fine_quant[i]);
         offset = (q2+half)*(1<<(14-fine_quant[i]))*scale - half;
         oldEBands[i+c*m->nbEBands] += offset;
      } while (++c < C);
      }
   } while (++i < m->nbEBands);
   }
   i=0;
   if (C*m->nbEBands > 0) {
   const double ln2 = LN2_D;
   do
      eBands[i] = fn_88565118(ln2*oldEBands[i]);
   while (++i < C*m->nbEBands);
   }
}

