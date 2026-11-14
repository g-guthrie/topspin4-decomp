/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family JP2: libjpeg 6b inverse DCT routines (jidctflt.c, jidctfst.c, jidctint.c, jidctred.c). */
#include "jp1_jpeg.h"

#define RANGE_MASK 1023

/* jidctflt.c constants; each lives in its own read-only section so every use loads it separately. */
#ifdef _MSC_VER
#pragma const_seg(".jp2rd1")
#endif
static const float lbl_880276D4 = 1.414213562f; /* sqrt(2) */
#ifdef _MSC_VER
#pragma const_seg(".jp2rd2")
#endif
static const float lbl_880276D8 = 1.847759065f; /* 2*c2 */
#ifdef _MSC_VER
#pragma const_seg(".jp2rd3")
#endif
static const float lbl_880276DC = 2.613125930f; /* 2*(c2+c6) */
#ifdef _MSC_VER
#pragma const_seg(".jp2rd4")
#endif
static const float lbl_880276E0 = 1.082392200f; /* 2*(c2-c6) */
#ifdef _MSC_VER
#pragma const_seg()
#endif

/* Floating-point inverse DCT (AA&N), dequantizing with a float multiplier table. */
#define DEQUANTIZE(coef, quantval) (((float)(coef)) * (quantval))

void ts4_jpeg_idct_float_88304B48(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_component_info *compptr,
                                  ts4_jcoef *coef_block, ts4_jsamparray output_buf, ts4_jdim output_col)
{
    float tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
    float tmp10, tmp11, tmp12, tmp13;
    float z5, z10, z11, z12, z13;
    ts4_jcoef *inptr;
    float *quantptr;
    float *wsptr;
    ts4_jsamprow outptr;
    ts4_jsample *range_limit = cinfo->sample_range_limit + 128;
    int ctr;
    float workspace[64];

    inptr = coef_block;
    quantptr = (float *)compptr->dct_table;
    wsptr = workspace;
    for (ctr = 8; ctr > 0; ctr--) {
        if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 && inptr[8 * 4] == 0 &&
            inptr[8 * 5] == 0 && inptr[8 * 6] == 0 && inptr[8 * 7] == 0) {
            float dcval = DEQUANTIZE(inptr[8 * 0], quantptr[8 * 0]);
            wsptr[8 * 0] = dcval;
            wsptr[8 * 1] = dcval;
            wsptr[8 * 2] = dcval;
            wsptr[8 * 3] = dcval;
            wsptr[8 * 4] = dcval;
            wsptr[8 * 5] = dcval;
            wsptr[8 * 6] = dcval;
            wsptr[8 * 7] = dcval;
            inptr++;
            quantptr++;
            wsptr++;
            continue;
        }
        tmp0 = DEQUANTIZE(inptr[8 * 0], quantptr[8 * 0]);
        tmp1 = DEQUANTIZE(inptr[8 * 2], quantptr[8 * 2]);
        tmp2 = DEQUANTIZE(inptr[8 * 4], quantptr[8 * 4]);
        tmp3 = DEQUANTIZE(inptr[8 * 6], quantptr[8 * 6]);

        tmp10 = tmp0 + tmp2;
        tmp11 = tmp0 - tmp2;

        tmp13 = tmp1 + tmp3;
        tmp12 = (tmp1 - tmp3) * lbl_880276D4 - tmp13;

        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        tmp4 = DEQUANTIZE(inptr[8 * 1], quantptr[8 * 1]);
        tmp5 = DEQUANTIZE(inptr[8 * 3], quantptr[8 * 3]);
        tmp6 = DEQUANTIZE(inptr[8 * 5], quantptr[8 * 5]);
        tmp7 = DEQUANTIZE(inptr[8 * 7], quantptr[8 * 7]);

        z13 = tmp6 + tmp5;
        z10 = tmp6 - tmp5;
        z11 = tmp4 + tmp7;
        z12 = tmp4 - tmp7;

        tmp7 = z11 + z13;
        tmp11 = (z11 - z13) * lbl_880276D4;

        z5 = (z10 + z12) * lbl_880276D8;
        tmp12 = z5 - lbl_880276DC * z10;
        tmp10 = lbl_880276E0 * z12 - z5;

        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;

        wsptr[8 * 0] = tmp0 + tmp7;
        wsptr[8 * 7] = tmp0 - tmp7;
        wsptr[8 * 1] = tmp1 + tmp6;
        wsptr[8 * 6] = tmp1 - tmp6;
        wsptr[8 * 2] = tmp2 + tmp5;
        wsptr[8 * 5] = tmp2 - tmp5;
        wsptr[8 * 4] = tmp3 + tmp4;
        wsptr[8 * 3] = tmp3 - tmp4;

        inptr++;
        quantptr++;
        wsptr++;
    }

    wsptr = workspace;
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + output_col;
        tmp10 = wsptr[0] + wsptr[4];
        tmp11 = wsptr[0] - wsptr[4];

        tmp13 = wsptr[2] + wsptr[6];
        tmp12 = (wsptr[2] - wsptr[6]) * lbl_880276D4 - tmp13;

        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        z13 = wsptr[5] + wsptr[3];
        z10 = wsptr[5] - wsptr[3];
        z11 = wsptr[1] + wsptr[7];
        z12 = wsptr[1] - wsptr[7];

        tmp7 = z11 + z13;
        tmp11 = (z11 - z13) * lbl_880276D4;

        z5 = (z10 + z12) * lbl_880276D8;
        tmp12 = z5 - lbl_880276DC * z10;
        tmp10 = lbl_880276E0 * z12 - z5;

        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;

        outptr[0] = range_limit[(int)(((int)(tmp0 + tmp7) + 4) >> 3) & RANGE_MASK];
        outptr[7] = range_limit[(int)(((int)(tmp0 - tmp7) + 4) >> 3) & RANGE_MASK];
        outptr[1] = range_limit[(int)(((int)(tmp1 + tmp6) + 4) >> 3) & RANGE_MASK];
        outptr[6] = range_limit[(int)(((int)(tmp1 - tmp6) + 4) >> 3) & RANGE_MASK];
        outptr[2] = range_limit[(int)(((int)(tmp2 + tmp5) + 4) >> 3) & RANGE_MASK];
        outptr[5] = range_limit[(int)(((int)(tmp2 - tmp5) + 4) >> 3) & RANGE_MASK];
        outptr[4] = range_limit[(int)(((int)(tmp3 + tmp4) + 4) >> 3) & RANGE_MASK];
        outptr[3] = range_limit[(int)(((int)(tmp3 - tmp4) + 4) >> 3) & RANGE_MASK];

        wsptr += 8;
    }
}

#undef DEQUANTIZE

typedef short jp2_dctelem;

#define DEQUANTIZE(coef, quantval) (((short)(coef)) * (quantval))
#define MULTIPLY(var, c) ((jp2_dctelem)(((var) * (c)) >> 8))

/* Fast integer inverse DCT (AA&N scaled, 8 fractional bits). */
void ts4_jpeg_idct_ifast_88304F98(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_component_info *compptr,
                                  ts4_jcoef *coef_block, ts4_jsamparray output_buf, ts4_jdim output_col)
{
    jp2_dctelem tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
    jp2_dctelem tmp10, tmp11, tmp12, tmp13;
    jp2_dctelem z5, z10, z11, z12, z13;
    ts4_jcoef *inptr;
    short *quantptr;
    int *wsptr;
    ts4_jsamprow outptr;
    ts4_jsample *range_limit = cinfo->sample_range_limit + 128;
    int ctr;
    int workspace[64];

    inptr = coef_block;
    quantptr = (short *)compptr->dct_table;
    wsptr = workspace;
    for (ctr = 8; ctr > 0; ctr--) {
        if ((inptr[8 * 1] | inptr[8 * 2] | inptr[8 * 3] | inptr[8 * 4] | inptr[8 * 5] | inptr[8 * 6] |
             inptr[8 * 7]) == 0) {
            int dcval = (int)DEQUANTIZE(inptr[8 * 0], quantptr[8 * 0]);
            wsptr[8 * 0] = dcval;
            wsptr[8 * 1] = dcval;
            wsptr[8 * 2] = dcval;
            wsptr[8 * 3] = dcval;
            wsptr[8 * 4] = dcval;
            wsptr[8 * 5] = dcval;
            wsptr[8 * 6] = dcval;
            wsptr[8 * 7] = dcval;
            inptr++;
            quantptr++;
            wsptr++;
            continue;
        }
        tmp0 = DEQUANTIZE(inptr[8 * 0], quantptr[8 * 0]);
        tmp1 = DEQUANTIZE(inptr[8 * 2], quantptr[8 * 2]);
        tmp2 = DEQUANTIZE(inptr[8 * 4], quantptr[8 * 4]);
        tmp3 = DEQUANTIZE(inptr[8 * 6], quantptr[8 * 6]);

        tmp10 = tmp0 + tmp2;
        tmp11 = tmp0 - tmp2;

        tmp13 = tmp1 + tmp3;
        tmp12 = MULTIPLY(tmp1 - tmp3, 362) - tmp13;

        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        tmp4 = DEQUANTIZE(inptr[8 * 1], quantptr[8 * 1]);
        tmp5 = DEQUANTIZE(inptr[8 * 3], quantptr[8 * 3]);
        tmp6 = DEQUANTIZE(inptr[8 * 5], quantptr[8 * 5]);
        tmp7 = DEQUANTIZE(inptr[8 * 7], quantptr[8 * 7]);

        z13 = tmp6 + tmp5;
        z10 = tmp6 - tmp5;
        z11 = tmp4 + tmp7;
        z12 = tmp4 - tmp7;

        tmp7 = z11 + z13;
        tmp11 = MULTIPLY(z11 - z13, 362);

        z5 = MULTIPLY(z10 + z12, 473);
        tmp10 = MULTIPLY(z12, 277) - z5;
        tmp12 = MULTIPLY(z10, -669) + z5;

        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;

        wsptr[8 * 0] = (int)(tmp0 + tmp7);
        wsptr[8 * 7] = (int)(tmp0 - tmp7);
        wsptr[8 * 1] = (int)(tmp1 + tmp6);
        wsptr[8 * 6] = (int)(tmp1 - tmp6);
        wsptr[8 * 2] = (int)(tmp2 + tmp5);
        wsptr[8 * 5] = (int)(tmp2 - tmp5);
        wsptr[8 * 4] = (int)(tmp3 + tmp4);
        wsptr[8 * 3] = (int)(tmp3 - tmp4);

        inptr++;
        quantptr++;
        wsptr++;
    }

    wsptr = workspace;
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + output_col;
        if ((wsptr[1] | wsptr[2] | wsptr[3] | wsptr[4] | wsptr[5] | wsptr[6] | wsptr[7]) == 0) {
            ts4_jsample dcval = range_limit[((int)(wsptr[0] >> 5)) & RANGE_MASK];
            outptr[0] = dcval;
            outptr[1] = dcval;
            outptr[2] = dcval;
            outptr[3] = dcval;
            outptr[4] = dcval;
            outptr[5] = dcval;
            outptr[6] = dcval;
            outptr[7] = dcval;
            wsptr += 8;
            continue;
        }
        tmp10 = ((jp2_dctelem)wsptr[0] + (jp2_dctelem)wsptr[4]);
        tmp11 = ((jp2_dctelem)wsptr[0] - (jp2_dctelem)wsptr[4]);

        tmp13 = ((jp2_dctelem)wsptr[2] + (jp2_dctelem)wsptr[6]);
        tmp12 = MULTIPLY((jp2_dctelem)wsptr[2] - (jp2_dctelem)wsptr[6], 362) - tmp13;

        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        z13 = (jp2_dctelem)wsptr[5] + (jp2_dctelem)wsptr[3];
        z10 = (jp2_dctelem)wsptr[5] - (jp2_dctelem)wsptr[3];
        z11 = (jp2_dctelem)wsptr[1] + (jp2_dctelem)wsptr[7];
        z12 = (jp2_dctelem)wsptr[1] - (jp2_dctelem)wsptr[7];

        tmp7 = z11 + z13;
        tmp11 = MULTIPLY(z11 - z13, 362);

        z5 = MULTIPLY(z10 + z12, 473);
        tmp10 = MULTIPLY(z12, 277) - z5;
        tmp12 = MULTIPLY(z10, -669) + z5;

        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;

        outptr[0] = range_limit[((int)((tmp0 + tmp7) >> 5)) & RANGE_MASK];
        outptr[7] = range_limit[((int)((tmp0 - tmp7) >> 5)) & RANGE_MASK];
        outptr[1] = range_limit[((int)((tmp1 + tmp6) >> 5)) & RANGE_MASK];
        outptr[6] = range_limit[((int)((tmp1 - tmp6) >> 5)) & RANGE_MASK];
        outptr[2] = range_limit[((int)((tmp2 + tmp5) >> 5)) & RANGE_MASK];
        outptr[5] = range_limit[((int)((tmp2 - tmp5) >> 5)) & RANGE_MASK];
        outptr[4] = range_limit[((int)((tmp3 + tmp4) >> 5)) & RANGE_MASK];
        outptr[3] = range_limit[((int)((tmp3 - tmp4) >> 5)) & RANGE_MASK];

        wsptr += 8;
    }
}

#undef MULTIPLY

#define MULTIPLY(var, c) ((var) * (c))
#define DESCALE(x, n) (((x) + (1 << ((n) - 1))) >> (n))

#define FIX_0_298631336 2446
#define FIX_0_390180644 3196
#define FIX_0_541196100 4433
#define FIX_0_765366865 6270
#define FIX_0_899976223 7373
#define FIX_1_175875602 9633
#define FIX_1_501321110 12299
#define FIX_1_847759065 15137
#define FIX_1_961570560 16069
#define FIX_2_053119869 16819
#define FIX_2_562915447 20995
#define FIX_3_072711026 25172

/* Accurate integer inverse DCT (LL&M, 13 fractional bits). */
void ts4_jpeg_idct_islow_88305428(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_component_info *compptr,
                                  ts4_jcoef *coef_block, ts4_jsamparray output_buf, ts4_jdim output_col)
{
    int tmp0, tmp1, tmp2, tmp3;
    int tmp10, tmp11, tmp12, tmp13;
    int z1, z2, z3, z4, z5;
    ts4_jcoef *inptr;
    short *quantptr;
    int *wsptr;
    ts4_jsamprow outptr;
    ts4_jsample *range_limit = cinfo->sample_range_limit + 128;
    int ctr;
    int workspace[64];

    inptr = coef_block;
    quantptr = (short *)compptr->dct_table;
    wsptr = workspace;
    for (ctr = 8; ctr > 0; ctr--) {
        if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 && inptr[8 * 4] == 0 &&
            inptr[8 * 5] == 0 && inptr[8 * 6] == 0 && inptr[8 * 7] == 0) {
            int dcval = DEQUANTIZE(inptr[8 * 0], quantptr[8 * 0]) << 2;
            wsptr[8 * 0] = dcval;
            wsptr[8 * 1] = dcval;
            wsptr[8 * 2] = dcval;
            wsptr[8 * 3] = dcval;
            wsptr[8 * 4] = dcval;
            wsptr[8 * 5] = dcval;
            wsptr[8 * 6] = dcval;
            wsptr[8 * 7] = dcval;
            inptr++;
            quantptr++;
            wsptr++;
            continue;
        }
        z2 = DEQUANTIZE(inptr[8 * 2], quantptr[8 * 2]);
        z3 = DEQUANTIZE(inptr[8 * 6], quantptr[8 * 6]);

        z1 = MULTIPLY(z2 + z3, FIX_0_541196100);
        tmp2 = z1 + MULTIPLY(z3, -FIX_1_847759065);
        tmp3 = z1 + MULTIPLY(z2, FIX_0_765366865);

        z2 = DEQUANTIZE(inptr[8 * 0], quantptr[8 * 0]);
        z3 = DEQUANTIZE(inptr[8 * 4], quantptr[8 * 4]);

        tmp0 = (z2 + z3) << 13;
        tmp1 = (z2 - z3) << 13;

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        tmp0 = DEQUANTIZE(inptr[8 * 7], quantptr[8 * 7]);
        tmp1 = DEQUANTIZE(inptr[8 * 5], quantptr[8 * 5]);
        tmp2 = DEQUANTIZE(inptr[8 * 3], quantptr[8 * 3]);
        tmp3 = DEQUANTIZE(inptr[8 * 1], quantptr[8 * 1]);

        z1 = tmp0 + tmp3;
        z2 = tmp1 + tmp2;
        z3 = tmp0 + tmp2;
        z4 = tmp1 + tmp3;
        z5 = MULTIPLY(z3 + z4, FIX_1_175875602);

        tmp0 = MULTIPLY(tmp0, FIX_0_298631336);
        tmp1 = MULTIPLY(tmp1, FIX_2_053119869);
        tmp2 = MULTIPLY(tmp2, FIX_3_072711026);
        tmp3 = MULTIPLY(tmp3, FIX_1_501321110);
        z1 = MULTIPLY(z1, -FIX_0_899976223);
        z2 = MULTIPLY(z2, -FIX_2_562915447);
        z3 = MULTIPLY(z3, -FIX_1_961570560);
        z4 = MULTIPLY(z4, -FIX_0_390180644);

        z3 += z5;
        z4 += z5;

        tmp0 += z1 + z3;
        tmp1 += z2 + z4;
        tmp2 += z2 + z3;
        tmp3 += z1 + z4;

        wsptr[8 * 0] = (int)DESCALE(tmp10 + tmp3, 11);
        wsptr[8 * 7] = (int)DESCALE(tmp10 - tmp3, 11);
        wsptr[8 * 1] = (int)DESCALE(tmp11 + tmp2, 11);
        wsptr[8 * 6] = (int)DESCALE(tmp11 - tmp2, 11);
        wsptr[8 * 2] = (int)DESCALE(tmp12 + tmp1, 11);
        wsptr[8 * 5] = (int)DESCALE(tmp12 - tmp1, 11);
        wsptr[8 * 3] = (int)DESCALE(tmp13 + tmp0, 11);
        wsptr[8 * 4] = (int)DESCALE(tmp13 - tmp0, 11);

        inptr++;
        quantptr++;
        wsptr++;
    }

    wsptr = workspace;
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + output_col;
        if (wsptr[1] == 0 && wsptr[2] == 0 && wsptr[3] == 0 && wsptr[4] == 0 && wsptr[5] == 0 &&
            wsptr[6] == 0 && wsptr[7] == 0) {
            ts4_jsample dcval = range_limit[(int)DESCALE((int)wsptr[0], 5) & RANGE_MASK];
            outptr[0] = dcval;
            outptr[1] = dcval;
            outptr[2] = dcval;
            outptr[3] = dcval;
            outptr[4] = dcval;
            outptr[5] = dcval;
            outptr[6] = dcval;
            outptr[7] = dcval;
            wsptr += 8;
            continue;
        }
        z2 = (int)wsptr[2];
        z3 = (int)wsptr[6];

        z1 = MULTIPLY(z2 + z3, FIX_0_541196100);
        tmp2 = z1 + MULTIPLY(z3, -FIX_1_847759065);
        tmp3 = z1 + MULTIPLY(z2, FIX_0_765366865);

        tmp0 = ((int)wsptr[0] + (int)wsptr[4]) << 13;
        tmp1 = ((int)wsptr[0] - (int)wsptr[4]) << 13;

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        tmp0 = (int)wsptr[7];
        tmp1 = (int)wsptr[5];
        tmp2 = (int)wsptr[3];
        tmp3 = (int)wsptr[1];

        z1 = tmp0 + tmp3;
        z2 = tmp1 + tmp2;
        z3 = tmp0 + tmp2;
        z4 = tmp1 + tmp3;
        z5 = MULTIPLY(z3 + z4, FIX_1_175875602);

        tmp0 = MULTIPLY(tmp0, FIX_0_298631336);
        tmp1 = MULTIPLY(tmp1, FIX_2_053119869);
        tmp2 = MULTIPLY(tmp2, FIX_3_072711026);
        tmp3 = MULTIPLY(tmp3, FIX_1_501321110);
        z1 = MULTIPLY(z1, -FIX_0_899976223);
        z2 = MULTIPLY(z2, -FIX_2_562915447);
        z3 = MULTIPLY(z3, -FIX_1_961570560);
        z4 = MULTIPLY(z4, -FIX_0_390180644);

        z3 += z5;
        z4 += z5;

        tmp0 += z1 + z3;
        tmp1 += z2 + z4;
        tmp2 += z2 + z3;
        tmp3 += z1 + z4;

        outptr[0] = range_limit[(int)DESCALE(tmp10 + tmp3, 18) & RANGE_MASK];
        outptr[7] = range_limit[(int)DESCALE(tmp10 - tmp3, 18) & RANGE_MASK];
        outptr[1] = range_limit[(int)DESCALE(tmp11 + tmp2, 18) & RANGE_MASK];
        outptr[6] = range_limit[(int)DESCALE(tmp11 - tmp2, 18) & RANGE_MASK];
        outptr[2] = range_limit[(int)DESCALE(tmp12 + tmp1, 18) & RANGE_MASK];
        outptr[5] = range_limit[(int)DESCALE(tmp12 - tmp1, 18) & RANGE_MASK];
        outptr[3] = range_limit[(int)DESCALE(tmp13 + tmp0, 18) & RANGE_MASK];
        outptr[4] = range_limit[(int)DESCALE(tmp13 - tmp0, 18) & RANGE_MASK];

        wsptr += 8;
    }
}

#define FIX_0_211164243 1730
#define FIX_0_509795579 4176
#define FIX_0_601344887 4926
#define FIX_0_720959822 5906
#define FIX_0_765366865 6270
#define FIX_0_850430095 6967
#define FIX_0_899976223 7373
#define FIX_1_061594337 8697
#define FIX_1_272758580 10426
#define FIX_1_451774981 11893
#define FIX_1_847759065 15137
#define FIX_2_172734803 17799
#define FIX_2_562915447 20995
#define FIX_3_624509785 29692

/* Reduced-size inverse DCT producing a 4x4 block of samples (jidctred.c). */
void ts4_jpeg_idct_4x4_883058D0(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_component_info *compptr,
                                ts4_jcoef *coef_block, ts4_jsamparray output_buf, ts4_jdim output_col)
{
    int tmp0, tmp2, tmp10, tmp12;
    int z1, z2, z3, z4;
    ts4_jcoef *inptr;
    short *quantptr;
    int *wsptr;
    ts4_jsamprow outptr;
    ts4_jsample *range_limit = cinfo->sample_range_limit + 128;
    int ctr;
    int workspace[8 * 4];

    inptr = coef_block;
    quantptr = (short *)compptr->dct_table;
    wsptr = workspace;
    for (ctr = 8; ctr > 0; inptr++, quantptr++, wsptr++, ctr--) {
        if (ctr == 8 - 4)
            continue;
        if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 && inptr[8 * 5] == 0 &&
            inptr[8 * 6] == 0 && inptr[8 * 7] == 0) {
            int dcval = DEQUANTIZE(inptr[8 * 0], quantptr[8 * 0]) << 2;
            wsptr[8 * 0] = dcval;
            wsptr[8 * 1] = dcval;
            wsptr[8 * 2] = dcval;
            wsptr[8 * 3] = dcval;
            continue;
        }
        tmp0 = DEQUANTIZE(inptr[8 * 0], quantptr[8 * 0]);
        tmp0 <<= (13 + 1);

        z2 = DEQUANTIZE(inptr[8 * 2], quantptr[8 * 2]);
        z3 = DEQUANTIZE(inptr[8 * 6], quantptr[8 * 6]);

        tmp2 = MULTIPLY(z2, FIX_1_847759065) + MULTIPLY(z3, -FIX_0_765366865);

        tmp10 = tmp0 + tmp2;
        tmp12 = tmp0 - tmp2;

        z1 = DEQUANTIZE(inptr[8 * 7], quantptr[8 * 7]);
        z2 = DEQUANTIZE(inptr[8 * 5], quantptr[8 * 5]);
        z3 = DEQUANTIZE(inptr[8 * 3], quantptr[8 * 3]);
        z4 = DEQUANTIZE(inptr[8 * 1], quantptr[8 * 1]);

        tmp0 = MULTIPLY(z1, -FIX_0_211164243) + MULTIPLY(z2, FIX_1_451774981) +
               MULTIPLY(z3, -FIX_2_172734803) + MULTIPLY(z4, FIX_1_061594337);

        tmp2 = MULTIPLY(z1, -FIX_0_509795579) + MULTIPLY(z2, -FIX_0_601344887) +
               MULTIPLY(z3, FIX_0_899976223) + MULTIPLY(z4, FIX_2_562915447);

        wsptr[8 * 0] = (int)DESCALE(tmp10 + tmp2, 13 - 2 + 1);
        wsptr[8 * 3] = (int)DESCALE(tmp10 - tmp2, 13 - 2 + 1);
        wsptr[8 * 1] = (int)DESCALE(tmp12 + tmp0, 13 - 2 + 1);
        wsptr[8 * 2] = (int)DESCALE(tmp12 - tmp0, 13 - 2 + 1);
    }

    wsptr = workspace;
    for (ctr = 0; ctr < 4; ctr++) {
        outptr = output_buf[ctr] + output_col;
        if (wsptr[1] == 0 && wsptr[2] == 0 && wsptr[3] == 0 && wsptr[5] == 0 && wsptr[6] == 0 &&
            wsptr[7] == 0) {
            ts4_jsample dcval = range_limit[(int)DESCALE((int)wsptr[0], 2 + 3) & RANGE_MASK];
            outptr[0] = dcval;
            outptr[1] = dcval;
            outptr[2] = dcval;
            outptr[3] = dcval;
            wsptr += 8;
            continue;
        }
        tmp0 = ((int)wsptr[0]) << (13 + 1);

        tmp2 = MULTIPLY((int)wsptr[2], FIX_1_847759065) + MULTIPLY((int)wsptr[6], -FIX_0_765366865);

        tmp10 = tmp0 + tmp2;
        tmp12 = tmp0 - tmp2;

        z1 = (int)wsptr[7];
        z2 = (int)wsptr[5];
        z3 = (int)wsptr[3];
        z4 = (int)wsptr[1];

        tmp0 = MULTIPLY(z1, -FIX_0_211164243) + MULTIPLY(z2, FIX_1_451774981) +
               MULTIPLY(z3, -FIX_2_172734803) + MULTIPLY(z4, FIX_1_061594337);

        tmp2 = MULTIPLY(z1, -FIX_0_509795579) + MULTIPLY(z2, -FIX_0_601344887) +
               MULTIPLY(z3, FIX_0_899976223) + MULTIPLY(z4, FIX_2_562915447);

        outptr[0] = range_limit[(int)DESCALE(tmp10 + tmp2, 13 + 2 + 3 + 1) & RANGE_MASK];
        outptr[3] = range_limit[(int)DESCALE(tmp10 - tmp2, 13 + 2 + 3 + 1) & RANGE_MASK];
        outptr[1] = range_limit[(int)DESCALE(tmp12 + tmp0, 13 + 2 + 3 + 1) & RANGE_MASK];
        outptr[2] = range_limit[(int)DESCALE(tmp12 - tmp0, 13 + 2 + 3 + 1) & RANGE_MASK];

        wsptr += 8;
    }
}

/* Reduced-size inverse DCT producing a 2x2 block of samples (jidctred.c). */
void ts4_jpeg_idct_2x2_88305C08(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_component_info *compptr,
                                ts4_jcoef *coef_block, ts4_jsamparray output_buf, ts4_jdim output_col)
{
    int tmp0, tmp10, z1;
    ts4_jcoef *inptr;
    short *quantptr;
    int *wsptr;
    ts4_jsamprow outptr;
    ts4_jsample *range_limit = cinfo->sample_range_limit + 128;
    int ctr;
    int workspace[8 * 2];

    inptr = coef_block;
    quantptr = (short *)compptr->dct_table;
    wsptr = workspace;
    for (ctr = 8; ctr > 0; inptr++, quantptr++, wsptr++, ctr--) {
        if (ctr == 8 - 2 || ctr == 8 - 4 || ctr == 8 - 6)
            continue;
        if (inptr[8 * 1] == 0 && inptr[8 * 3] == 0 && inptr[8 * 5] == 0 && inptr[8 * 7] == 0) {
            int dcval = DEQUANTIZE(inptr[8 * 0], quantptr[8 * 0]) << 2;
            wsptr[8 * 0] = dcval;
            wsptr[8 * 1] = dcval;
            continue;
        }
        z1 = DEQUANTIZE(inptr[8 * 0], quantptr[8 * 0]);
        tmp10 = z1 << (13 + 2);

        z1 = DEQUANTIZE(inptr[8 * 7], quantptr[8 * 7]);
        tmp0 = MULTIPLY(z1, -FIX_0_720959822);
        z1 = DEQUANTIZE(inptr[8 * 5], quantptr[8 * 5]);
        tmp0 += MULTIPLY(z1, FIX_0_850430095);
        z1 = DEQUANTIZE(inptr[8 * 3], quantptr[8 * 3]);
        tmp0 += MULTIPLY(z1, -FIX_1_272758580);
        z1 = DEQUANTIZE(inptr[8 * 1], quantptr[8 * 1]);
        tmp0 += MULTIPLY(z1, FIX_3_624509785);

        wsptr[8 * 0] = (int)DESCALE(tmp10 + tmp0, 13 - 2 + 2);
        wsptr[8 * 1] = (int)DESCALE(tmp10 - tmp0, 13 - 2 + 2);
    }

    wsptr = workspace;
    for (ctr = 0; ctr < 2; ctr++) {
        outptr = output_buf[ctr] + output_col;
        if (wsptr[1] == 0 && wsptr[3] == 0 && wsptr[5] == 0 && wsptr[7] == 0) {
            ts4_jsample dcval = range_limit[(int)DESCALE((int)wsptr[0], 2 + 3) & RANGE_MASK];
            outptr[0] = dcval;
            outptr[1] = dcval;
            wsptr += 8;
            continue;
        }
        tmp10 = ((int)wsptr[0]) << (13 + 2);

        tmp0 = MULTIPLY((int)wsptr[7], -FIX_0_720959822) + MULTIPLY((int)wsptr[5], FIX_0_850430095) +
               MULTIPLY((int)wsptr[3], -FIX_1_272758580) + MULTIPLY((int)wsptr[1], FIX_3_624509785);

        outptr[0] = range_limit[(int)DESCALE(tmp10 + tmp0, 13 + 2 + 3 + 2) & RANGE_MASK];
        outptr[1] = range_limit[(int)DESCALE(tmp10 - tmp0, 13 + 2 + 3 + 2) & RANGE_MASK];

        wsptr += 8;
    }
}
