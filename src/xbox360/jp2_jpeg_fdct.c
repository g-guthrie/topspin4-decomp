/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "jp1_jpeg.h"

#ifdef _MSC_VER
#pragma const_seg(".jp2rd5")
#endif
static const float lbl_880276E4 = 1.306562965f;
#ifdef _MSC_VER
#pragma const_seg(".jp2rd6")
#endif
static const float lbl_880276E8 = 0.541196100f;
#ifdef _MSC_VER
#pragma const_seg(".jp2rd7")
#endif
static const float lbl_880276EC = 0.382683433f;
#ifdef _MSC_VER
#pragma const_seg(".jp2rd8")
#endif
static const float lbl_880276F0 = 0.707106781f;
#ifdef _MSC_VER
#pragma const_seg()
#endif

/* Floating-point forward DCT of one 8x8 block, in place (jfdctflt.c jpeg_fdct_float). */
void ts4_jpeg_fdct_float_88306220(float *data)
{
    float tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
    float tmp10, tmp11, tmp12, tmp13;
    float z1, z2, z3, z4, z5, z11, z13;
    float *dataptr;
    int ctr;

    dataptr = data;
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        tmp0 = dataptr[0] + dataptr[7];
        tmp7 = dataptr[0] - dataptr[7];
        tmp1 = dataptr[1] + dataptr[6];
        tmp6 = dataptr[1] - dataptr[6];
        tmp2 = dataptr[2] + dataptr[5];
        tmp5 = dataptr[2] - dataptr[5];
        tmp3 = dataptr[3] + dataptr[4];
        tmp4 = dataptr[3] - dataptr[4];

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        dataptr[0] = tmp10 + tmp11;
        dataptr[4] = tmp10 - tmp11;

        z1 = (tmp12 + tmp13) * lbl_880276F0;
        dataptr[2] = tmp13 + z1;
        dataptr[6] = tmp13 - z1;

        tmp10 = tmp4 + tmp5;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp6 + tmp7;

        z5 = (tmp10 - tmp12) * lbl_880276EC;
        z2 = lbl_880276E8 * tmp10 + z5;
        z4 = lbl_880276E4 * tmp12 + z5;
        z3 = tmp11 * lbl_880276F0;

        z11 = tmp7 + z3;
        z13 = tmp7 - z3;

        dataptr[5] = z13 + z2;
        dataptr[3] = z13 - z2;
        dataptr[1] = z11 + z4;
        dataptr[7] = z11 - z4;

        dataptr += 8;
    }

    dataptr = data;
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
        tmp7 = dataptr[8 * 0] - dataptr[8 * 7];
        tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
        tmp6 = dataptr[8 * 1] - dataptr[8 * 6];
        tmp2 = dataptr[8 * 2] + dataptr[8 * 5];
        tmp5 = dataptr[8 * 2] - dataptr[8 * 5];
        tmp3 = dataptr[8 * 3] + dataptr[8 * 4];
        tmp4 = dataptr[8 * 3] - dataptr[8 * 4];

        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;

        dataptr[8 * 0] = tmp10 + tmp11;
        dataptr[8 * 4] = tmp10 - tmp11;

        z1 = (tmp12 + tmp13) * lbl_880276F0;
        dataptr[8 * 2] = tmp13 + z1;
        dataptr[8 * 6] = tmp13 - z1;

        tmp10 = tmp4 + tmp5;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp6 + tmp7;

        z5 = (tmp10 - tmp12) * lbl_880276EC;
        z2 = lbl_880276E8 * tmp10 + z5;
        z4 = lbl_880276E4 * tmp12 + z5;
        z3 = tmp11 * lbl_880276F0;

        z11 = tmp7 + z3;
        z13 = tmp7 - z3;

        dataptr[8 * 5] = z13 + z2;
        dataptr[8 * 3] = z13 - z2;
        dataptr[8 * 1] = z11 + z4;
        dataptr[8 * 7] = z11 - z4;

        dataptr++;
    }
}
