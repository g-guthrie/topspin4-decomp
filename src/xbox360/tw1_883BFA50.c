/*
Copyright (c) 2003-2004, Mark Borgerding
Lots of modifications by JMV
Copyright (c) 2005-2007, Jean-Marc Valin
Copyright (c) 2008,      Jean-Marc Valin, CSIRO

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
    * Neither the author nor the names of any contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/* Derived from CELT 0.6.1 libcelt/kiss_fft.c and _kiss_fft_guts.h (BSD license,
   based on KISS FFT, Copyright (c) 2003-2004 Mark Borgerding); see
   THIRD_PARTY_NOTICES.md. Float build as linked into FMOD Ex. */
#include "lb3_celt.h"

#define MAXFACTORS 32
typedef struct { float r; float i; } kiss_fft_cpx;
typedef kiss_fft_cpx kiss_twiddle_cpx;
struct kiss_fft_state {
    int nfft;
    float scale;
    int factors[2*MAXFACTORS];
    kiss_twiddle_cpx twiddles[1];
};
typedef struct kiss_fft_state *kiss_fft_cfg;
#define size_t unsigned int

/* complex arithmetic of _kiss_fft_guts.h (float) */
#define S_MUL(a,b) ( (a)*(b) )
#define C_MUL(m,a,b) \
    do{ (m).r = (a).r*(b).r - (a).i*(b).i;\
        (m).i = (a).r*(b).i + (a).i*(b).r; }while(0)
#define C_MULC(m,a,b) \
    do{ (m).r = (a).r*(b).r + (a).i*(b).i;\
        (m).i = (a).i*(b).r - (a).r*(b).i; }while(0)
#define C_FIXDIV(c,div) /* NOOP */
#define C_ADD( res, a,b)\
    do { \
	    (res).r=(a).r+(b).r;  (res).i=(a).i+(b).i; \
    }while(0)
#define C_SUB( res, a,b)\
    do { \
	    (res).r=(a).r-(b).r;  (res).i=(a).i-(b).i; \
    }while(0)
#define C_ADDTO( res , a)\
    do { \
	    (res).r += (a).r;  (res).i += (a).i;\
    }while(0)

/* upstream name -> placeholder/new name in Swing_DLL.xex */
#define kf_bfly5 lb3_celt_kf_bfly5_883C0F50
#define ki_bfly5 lb3_celt_ki_bfly5_883C1188
#define compute_bitrev_table lb3_celt_compute_bitrev_table_883C1960
#define kf_work fn_883C1A10
#define ki_work fn_883C1B68
#define kiss_fft_stride lb3_celt_kiss_fft_stride_883C1EB8
#define kiss_ifft_stride lb3_celt_kiss_ifft_stride_883C1FD0

/* os_support.h _celt_fatal: report on stderr and abort */
extern const char lbl_880353A8[]; /* "Fatal (internal) error in %s, line %d: %s\n" */
extern const char lbl_8803868C[]; /* "..\\lib\\libcelt\\kiss_fft.c" */
extern const char lbl_88038670[]; /* "In-place FFT not supported" */
void fn_88562E80(void); /* abort */
#define celt_fatal_at(str,file,line) (fn_88569190(aud1_stderr, lbl_880353A8, (file), (line), (str)), fn_88562E80())

void fn_883C1A10(kiss_fft_cpx *Fout, const kiss_fft_cpx *f, const size_t fstride, int in_stride, int *factors, const kiss_fft_cfg st, int N, int s2, int m2); /* kf_work, still unmatched */
void fn_883C1B68(kiss_fft_cpx *Fout, const kiss_fft_cpx *f, const size_t fstride, int in_stride, int *factors, const kiss_fft_cfg st, int N, int s2, int m2); /* ki_work, still unmatched */

/* Swing_DLL.xex 0x883BFA50: kf_bfly5 (twin lb3_celt_kf_bfly5_883C0F50), one field offset 0x10c instead of 0x108 */
void ts4_celt_kf_bfly5_883BFA50(
                     kiss_fft_cpx * Fout,
                     const size_t fstride,
                     const kiss_fft_cfg st,
                     int m
                    )
{
   kiss_fft_cpx *Fout0,*Fout1,*Fout2,*Fout3,*Fout4;
   int u;
   kiss_fft_cpx scratch[13];
   kiss_twiddle_cpx * twiddles = st->twiddles;
   kiss_twiddle_cpx *tw;
   kiss_twiddle_cpx ya,yb;
   ya = twiddles[fstride*m];
   yb = twiddles[fstride*2*m];

   Fout0=Fout;
   Fout1=Fout0+m;
   Fout2=Fout0+2*m;
   Fout3=Fout0+3*m;
   Fout4=Fout0+4*m;

   tw=st->twiddles;
   for ( u=0; u<m; ++u ) {
      C_FIXDIV( *Fout0,5); C_FIXDIV( *Fout1,5); C_FIXDIV( *Fout2,5); C_FIXDIV( *Fout3,5); C_FIXDIV( *Fout4,5);
      scratch[0] = *Fout0;

      C_MUL(scratch[1] ,*Fout1, tw[u*fstride]);
      C_MUL(scratch[2] ,*Fout2, tw[2*u*fstride]);
      C_MUL(scratch[3] ,*Fout3, tw[3*u*fstride]);
      C_MUL(scratch[4] ,*Fout4, tw[4*u*fstride]);

      C_ADD( scratch[7],scratch[1],scratch[4]);
      C_SUB( scratch[10],scratch[1],scratch[4]);
      C_ADD( scratch[8],scratch[2],scratch[3]);
      C_SUB( scratch[9],scratch[2],scratch[3]);

      Fout0->r += scratch[7].r + scratch[8].r;
      Fout0->i += scratch[7].i + scratch[8].i;

      scratch[5].r = scratch[0].r + S_MUL(scratch[7].r,ya.r) + S_MUL(scratch[8].r,yb.r);
      scratch[5].i = scratch[0].i + S_MUL(scratch[7].i,ya.r) + S_MUL(scratch[8].i,yb.r);

      scratch[6].r =  S_MUL(scratch[10].i,ya.i) + S_MUL(scratch[9].i,yb.i);
      scratch[6].i = -S_MUL(scratch[10].r,ya.i) - S_MUL(scratch[9].r,yb.i);

      C_SUB(*Fout1,scratch[5],scratch[6]);
      C_ADD(*Fout4,scratch[5],scratch[6]);

      scratch[11].r = scratch[0].r + S_MUL(scratch[7].r,yb.r) + S_MUL(scratch[8].r,ya.r);
      scratch[11].i = scratch[0].i + S_MUL(scratch[7].i,yb.r) + S_MUL(scratch[8].i,ya.r);
      scratch[12].r = - S_MUL(scratch[10].i,yb.i) + S_MUL(scratch[9].i,ya.i);
      scratch[12].i = S_MUL(scratch[10].r,yb.i) - S_MUL(scratch[9].r,ya.i);

      C_ADD(*Fout2,scratch[11],scratch[12]);
      C_SUB(*Fout3,scratch[11],scratch[12]);

      ++Fout0;++Fout1;++Fout2;++Fout3;++Fout4;
   }
}


