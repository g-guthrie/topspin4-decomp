/* (C) 2007-2008 Jean-Marc Valin, CSIRO
*/
/* Derived from CELT 0.6.1 libcelt/vq.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Float build as linked into FMOD Ex. */
#include "lb3_celt.h"

#define alg_unquant lb3_celt_alg_unquant_883C3098
#define decode_pulses lb3_celt_decode_pulses_883C2BC8
#define ZERO_F lbl_88001A20
#define ONE_F lbl_88001A68

/* mix_pitch_and_residual (static upstream, still unmatched: see failed list);
   the float build has no K parameter. */
void fn_883C2F80(int *iy, celt_norm_t *X, int N, const celt_norm_t *P);
#define mix_pitch_and_residual fn_883C2F80

/** Decode pulse vector and combine the result with the pitch vector to produce
    the final normalised signal in the current band. */
void alg_unquant(celt_norm_t *X, int N, int K, celt_norm_t *P, ec_dec *dec)
{
   VARDECL(int, iy);
   SAVE_STACK;
   ALLOC(iy, N, int);
   decode_pulses(iy, N, K, dec);
   mix_pitch_and_residual(iy, X, N, P);
   RESTORE_STACK;
}
