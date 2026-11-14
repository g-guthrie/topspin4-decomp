/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2009             *
 * by the Xiph.Org Foundation http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: normalized modified discrete cosine transform
           power of two length transform only [64 <= n ]
 last mod: $Id: mdct.c 16227 2009-07-08 06:58:46Z xiphmont $

 Original algorithm adapted long ago from _The use of multirate filter
 banks for coding of high quality digital audio_, by T. Sporer,
 K. Brandenburg and B. Edler, collection of the European Signal
 Processing Conference (EUSIPCO), Amsterdam, June 1992, Vol.1, pp
 211-214

 The below code implements an algorithm that no longer looks much like
 that presented in the paper, but the basic structure remains if you
 dig deep enough to see it.

 This module DOES NOT INCLUDE code to generate/apply the window
 function.  Everybody has their own weird favorite including me... I
 happen to like the properties of y=sin(.5PI*sin^2(x)), but others may
 vehemently disagree.

 ********************************************************************/
/* Derived from libvorbis 1.2.3 lib/mdct.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Float build as linked into FMOD Ex (Swing_DLL.xex). */
#include "aud1_vorbis.h"

#ifdef _MSC_VER
#define LB3_NOINLINE __declspec(noinline)
#define LB3_RESTRICT __restrict
#else
#define LB3_NOINLINE
#define LB3_RESTRICT
#endif

/* upstream name -> placeholder/new name in Swing_DLL.xex */
#define mdct_butterfly_16 lb3_vorbis_mdct_butterfly_16_883C3668
#define mdct_butterfly_first lb3_vorbis_mdct_butterfly_first_883C3AA0
#define mdct_butterfly_generic lb3_vorbis_mdct_butterfly_generic_883C3C28

/* cPI2_8 comes from the image's shared float pool (the butterflies' x is
   declared restrict so that the compiler may schedule its load freely, as it
   does for a literal). */
extern const float lbl_880276F0; /* cPI2_8 = sqrt(.5) */
#define cPI2_8 lbl_880276F0

#define DATA_TYPE float
#define REG_TYPE float
#define MULT_NORM(x) (x)

/* 8 point butterfly (in place, 4 register) */
static void mdct_butterfly_8(DATA_TYPE * LB3_RESTRICT x){
  REG_TYPE r0   = x[6] + x[2];
  REG_TYPE r1   = x[6] - x[2];
  REG_TYPE r2   = x[4] + x[0];
  REG_TYPE r3   = x[4] - x[0];

           x[6] = r0   + r2;
           x[4] = r0   - r2;

           r0   = x[5] - x[1];
           r2   = x[7] - x[3];
           x[0] = r1   + r0;
           x[2] = r1   - r0;

           r0   = x[5] + x[1];
           r1   = x[7] + x[3];
           x[3] = r2   + r3;
           x[1] = r2   - r3;
           x[7] = r1   + r0;
           x[5] = r1   - r0;

}

/* 16 point butterfly (in place, 4 register) */
LB3_NOINLINE void mdct_butterfly_16(DATA_TYPE * LB3_RESTRICT x){
  REG_TYPE r0     = x[1]  - x[9];
  REG_TYPE r1     = x[0]  - x[8];

           x[8]  += x[0];
           x[9]  += x[1];
           x[0]   = MULT_NORM((r0   + r1) * cPI2_8);
           x[1]   = MULT_NORM((r0   - r1) * cPI2_8);

           r0     = x[3]  - x[11];
           r1     = x[10] - x[2];
           x[10] += x[2];
           x[11] += x[3];
           x[2]   = r0;
           x[3]   = r1;

           r0     = x[12] - x[4];
           r1     = x[13] - x[5];
           x[12] += x[4];
           x[13] += x[5];
           x[4]   = MULT_NORM((r0   - r1) * cPI2_8);
           x[5]   = MULT_NORM((r0   + r1) * cPI2_8);

           r0     = x[14] - x[6];
           r1     = x[15] - x[7];
           x[14] += x[6];
           x[15] += x[7];
           x[6]  = r0;
           x[7]  = r1;

           mdct_butterfly_8(x);
           mdct_butterfly_8(x+8);
}


/* N point first stage butterfly (in place, 2 register) */
LB3_NOINLINE void mdct_butterfly_first(DATA_TYPE *T,
                                        DATA_TYPE *x,
                                        int points){

  DATA_TYPE *x1        = x          + points      - 8;
  DATA_TYPE *x2        = x          + (points>>1) - 8;
  REG_TYPE   r0;
  REG_TYPE   r1;

  do{

               r0      = x1[6]      -  x2[6];
               r1      = x1[7]      -  x2[7];
               x1[6]  += x2[6];
               x1[7]  += x2[7];
               x2[6]   = MULT_NORM(r1 * T[1]  +  r0 * T[0]);
               x2[7]   = MULT_NORM(r1 * T[0]  -  r0 * T[1]);

               r0      = x1[4]      -  x2[4];
               r1      = x1[5]      -  x2[5];
               x1[4]  += x2[4];
               x1[5]  += x2[5];
               x2[4]   = MULT_NORM(r1 * T[5]  +  r0 * T[4]);
               x2[5]   = MULT_NORM(r1 * T[4]  -  r0 * T[5]);

               r0      = x1[2]      -  x2[2];
               r1      = x1[3]      -  x2[3];
               x1[2]  += x2[2];
               x1[3]  += x2[3];
               x2[2]   = MULT_NORM(r1 * T[9]  +  r0 * T[8]);
               x2[3]   = MULT_NORM(r1 * T[8]  -  r0 * T[9]);

               r0      = x1[0]      -  x2[0];
               r1      = x1[1]      -  x2[1];
               x1[0]  += x2[0];
               x1[1]  += x2[1];
               x2[0]   = MULT_NORM(r1 * T[13] +  r0 * T[12]);
               x2[1]   = MULT_NORM(r1 * T[12] -  r0 * T[13]);

    x1-=8;
    x2-=8;
    T+=16;

  }while(x2>=x);
}

/* N/stage point generic N stage butterfly (in place, 2 register) */
LB3_NOINLINE void mdct_butterfly_generic(DATA_TYPE *T,
                                          DATA_TYPE *x,
                                          int points,
                                          int trigint){

  DATA_TYPE *x1        = x          + points      - 8;
  DATA_TYPE *x2        = x          + (points>>1) - 8;
  REG_TYPE   r0;
  REG_TYPE   r1;

  do{

               r0      = x1[6]      -  x2[6];
               r1      = x1[7]      -  x2[7];
               x1[6]  += x2[6];
               x1[7]  += x2[7];
               x2[6]   = MULT_NORM(r1 * T[1]  +  r0 * T[0]);
               x2[7]   = MULT_NORM(r1 * T[0]  -  r0 * T[1]);

               T+=trigint;

               r0      = x1[4]      -  x2[4];
               r1      = x1[5]      -  x2[5];
               x1[4]  += x2[4];
               x1[5]  += x2[5];
               x2[4]   = MULT_NORM(r1 * T[1]  +  r0 * T[0]);
               x2[5]   = MULT_NORM(r1 * T[0]  -  r0 * T[1]);

               T+=trigint;

               r0      = x1[2]      -  x2[2];
               r1      = x1[3]      -  x2[3];
               x1[2]  += x2[2];
               x1[3]  += x2[3];
               x2[2]   = MULT_NORM(r1 * T[1]  +  r0 * T[0]);
               x2[3]   = MULT_NORM(r1 * T[0]  -  r0 * T[1]);

               T+=trigint;

               r0      = x1[0]      -  x2[0];
               r1      = x1[1]      -  x2[1];
               x1[0]  += x2[0];
               x1[1]  += x2[1];
               x2[0]   = MULT_NORM(r1 * T[1]  +  r0 * T[0]);
               x2[1]   = MULT_NORM(r1 * T[0]  -  r0 * T[1]);

               T+=trigint;
    x1-=8;
    x2-=8;

  }while(x2>=x);
}


