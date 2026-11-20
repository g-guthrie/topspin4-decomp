/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b forward DCT, fast integer and slow-but-accurate integer (jfdctfst.c, jfdctint.c). */
#include "ex8_jpeg.h"

typedef short ex8_dctelem;

/* AA&N scaled integer forward DCT (8 fractional bits of constants). */
void ex8_jpeg_fdct_ifast_88307068(ex8_dctelem *data)
{
    ex8_dctelem tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
    ex8_dctelem tmp10, tmp11, tmp12, tmp13;
    ex8_dctelem z1, z2, z3, z4, z5, z11, z13;
    ex8_dctelem *dataptr;
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

        z1 = (ex8_dctelem)(((tmp12 + tmp13) * 181) >> 8);
        dataptr[2] = tmp13 + z1;
        dataptr[6] = tmp13 - z1;

        tmp10 = tmp4 + tmp5;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp6 + tmp7;

        z5 = (ex8_dctelem)(((tmp10 - tmp12) * 98) >> 8);
        z2 = (ex8_dctelem)((tmp10 * 139) >> 8) + z5;
        z4 = (ex8_dctelem)((tmp12 * 334) >> 8) + z5;
        z3 = (ex8_dctelem)((tmp11 * 181) >> 8);

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

        z1 = (ex8_dctelem)(((tmp12 + tmp13) * 181) >> 8);
        dataptr[8 * 2] = tmp13 + z1;
        dataptr[8 * 6] = tmp13 - z1;

        tmp10 = tmp4 + tmp5;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp6 + tmp7;

        z5 = (ex8_dctelem)(((tmp10 - tmp12) * 98) >> 8);
        z2 = (ex8_dctelem)((tmp10 * 139) >> 8) + z5;
        z4 = (ex8_dctelem)((tmp12 * 334) >> 8) + z5;
        z3 = (ex8_dctelem)((tmp11 * 181) >> 8);

        z11 = tmp7 + z3;
        z13 = tmp7 - z3;

        dataptr[8 * 5] = z13 + z2;
        dataptr[8 * 3] = z13 - z2;
        dataptr[8 * 1] = z11 + z4;
        dataptr[8 * 7] = z11 - z4;

        dataptr++;
    }
}

/* Accurate integer forward DCT (LL&M, 13 fractional bits of constants). */
void ex8_jpeg_fdct_islow_88307368(ex8_dctelem *data)
{
    int tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7;
    int tmp10, tmp11, tmp12, tmp13;
    int z1, z2, z3, z4, z5;
    ex8_dctelem *dataptr;
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

        dataptr[0] = (ex8_dctelem)((tmp10 + tmp11) << 2);
        dataptr[4] = (ex8_dctelem)((tmp10 - tmp11) << 2);

        z1 = (tmp12 + tmp13) * 4433;
        dataptr[2] = (ex8_dctelem)((z1 + tmp13 * 6270 + (1 << (11 - 1))) >> 11);
        dataptr[6] = (ex8_dctelem)((z1 + tmp12 * (-15137) + (1 << (11 - 1))) >> 11);

        z1 = tmp4 + tmp7;
        z2 = tmp5 + tmp6;
        z3 = tmp4 + tmp6;
        z4 = tmp5 + tmp7;
        z5 = (z3 + z4) * 9633;

        tmp4 = tmp4 * 2446;
        tmp5 = tmp5 * 16819;
        tmp6 = tmp6 * 25172;
        tmp7 = tmp7 * 12299;
        z1 = z1 * (-7373);
        z2 = z2 * (-20995);
        z3 = z3 * (-16069);
        z4 = z4 * (-3196);

        z3 += z5;
        z4 += z5;

        dataptr[7] = (ex8_dctelem)((tmp4 + z1 + z3 + (1 << (11 - 1))) >> 11);
        dataptr[5] = (ex8_dctelem)((tmp5 + z2 + z4 + (1 << (11 - 1))) >> 11);
        dataptr[3] = (ex8_dctelem)((tmp6 + z2 + z3 + (1 << (11 - 1))) >> 11);
        dataptr[1] = (ex8_dctelem)((tmp7 + z1 + z4 + (1 << (11 - 1))) >> 11);

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

        dataptr[8 * 0] = (ex8_dctelem)((tmp10 + tmp11 + (1 << (2 - 1))) >> 2);
        dataptr[8 * 4] = (ex8_dctelem)((tmp10 - tmp11 + (1 << (2 - 1))) >> 2);

        z1 = (tmp12 + tmp13) * 4433;
        dataptr[8 * 2] = (ex8_dctelem)((z1 + tmp13 * 6270 + (1 << (15 - 1))) >> 15);
        dataptr[8 * 6] = (ex8_dctelem)((z1 + tmp12 * (-15137) + (1 << (15 - 1))) >> 15);

        z1 = tmp4 + tmp7;
        z2 = tmp5 + tmp6;
        z3 = tmp4 + tmp6;
        z4 = tmp5 + tmp7;
        z5 = (z3 + z4) * 9633;

        tmp4 = tmp4 * 2446;
        tmp5 = tmp5 * 16819;
        tmp6 = tmp6 * 25172;
        tmp7 = tmp7 * 12299;
        z1 = z1 * (-7373);
        z2 = z2 * (-20995);
        z3 = z3 * (-16069);
        z4 = z4 * (-3196);

        z3 += z5;
        z4 += z5;

        dataptr[8 * 7] = (ex8_dctelem)((tmp4 + z1 + z3 + (1 << (15 - 1))) >> 15);
        dataptr[8 * 5] = (ex8_dctelem)((tmp5 + z2 + z4 + (1 << (15 - 1))) >> 15);
        dataptr[8 * 3] = (ex8_dctelem)((tmp6 + z2 + z3 + (1 << (15 - 1))) >> 15);
        dataptr[8 * 1] = (ex8_dctelem)((tmp7 + z1 + z4 + (1 << (15 - 1))) >> 15);

        dataptr++;
    }
}
