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

 function: floor backend 1 implementation

 ********************************************************************/
/* Derived from libvorbis 1.2.3 lib/floor1.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex: FMOD context
   argument, allocation-failure checks, the look state has no sorted_index,
   encoder functions absent. */
#include "aud1_vorbis.h"


#ifdef _MSC_VER
#define AUD1_NOINLINE __declspec(noinline)
#else
#define AUD1_NOINLINE
#endif

int abs(int);

#ifndef NULL
#define NULL ((void *)0)
#endif

#define VIF_POSIT 63
#define VIF_CLASS 16
#define VIF_PARTS 31

typedef struct {
    int partitions;                /* 0 to 31 */
    int partitionclass[VIF_PARTS]; /* 0 to 15 */

    int class_dim[VIF_CLASS];        /* 1 to 8 */
    int class_subs[VIF_CLASS];       /* 0,1,2,3 (bits: 1<<n poss) */
    int class_book[VIF_CLASS];       /* subs ^ dim entries */
    int class_subbook[VIF_CLASS][8]; /* [VIF_CLASS][subs] */

    int mult;                  /* 1 2 3 or 4 */
    int postlist[VIF_POSIT + 2]; /* first two implicit */

    /* encode side analysis parameters */
    float maxover;
    float maxunder;
    float maxerr;

    float twofitweight;
    float twofitatten;

    int n;
} vorbis_info_floor1;

typedef struct {
    int forward_index[VIF_POSIT + 2];
    int reverse_index[VIF_POSIT + 2];

    int hineighbor[VIF_POSIT];
    int loneighbor[VIF_POSIT];
    int posts;

    int n;
    int quant_q;
    vorbis_info_floor1 *vi;

    long phrasebits;
    long postbits;
    long frames;
} vorbis_look_floor1;

extern const float lbl_88038960[256]; /* FLOOR1_fromdB_LOOKUP */
int ts4_get_u32_off0_883C57A8(const void *a, const void *b); /* icomp */
void ts4_qsort_8856B388(void *base, lib2_size_t n, lib2_size_t size,
                 int (*cmp)(const void *, const void *)); /* qsort */

/* floor1_free_info (exported copy is ts4_if_call_seq_ts4_memset_883C56F8) */
static void floor1_free_info(void *ctx, vorbis_info_floor *i)
{
    vorbis_info_floor1 *info = (vorbis_info_floor1 *)i;
    if (info) {
        ts4_memset(info, 0, sizeof(*info));
        fn_8836CD70(ctx, info);
    }
}

static int ilog(unsigned int v)
{
    int ret = 0;
    while (v) {
        ret++;
        v >>= 1;
    }
    return (ret);
}

static int render_point(int x0, int x1, int y0, int y1, int x)
{
    y0 &= 0x7fff; /* mask off flag */
    y1 &= 0x7fff;

    {
        int dy = y1 - y0;
        int adx = x1 - x0;
        int ady = abs(dy);
        int err = ady * (x - x0);

        int off = err / adx;
        if (dy < 0) return (y0 - off);
        return (y0 + off);
    }
}

/* floor1_inverse1: unpack the floor posts of one block. */
void *aud1_floor1_inverse1_883C5EF8(void *ctx, vorbis_block *vb, vorbis_look_floor *in)
{
    vorbis_look_floor1 *look = (vorbis_look_floor1 *)in;
    vorbis_info_floor1 *info = look->vi;
    codec_setup_info *ci = vb->vd->vi->codec_setup;

    int i, j, k;
    codebook *books = ci->fullbooks;

    /* unpack wrapped/predicted values from stream */
    if (lib2_oggpack_read_883BD268(&vb->opb, 1) == 1) {
        int *fit_value = aud1__vorbis_block_alloc_883BBDD8(ctx, vb, (look->posts) * sizeof(*fit_value));

        fit_value[0] = lib2_oggpack_read_883BD268(&vb->opb, ilog(look->quant_q - 1));
        fit_value[1] = lib2_oggpack_read_883BD268(&vb->opb, ilog(look->quant_q - 1));

        /* partition by partition */
        for (i = 0, j = 2; i < info->partitions; i++) {
            int class = info->partitionclass[i];
            int cdim = info->class_dim[class];
            int csubbits = info->class_subs[class];
            int csub = 1 << csubbits;
            int cval = 0;

            /* decode the partition's first stage cascade value */
            if (csubbits) {
                cval = ts4_if_call_seq_u32_off8_883BE820(books + info->class_book[class], &vb->opb);

                if (cval == -1) goto eop;
            }

            for (k = 0; k < cdim; k++) {
                int book = info->class_subbook[class][cval & (csub - 1)];
                cval >>= csubbits;
                if (book >= 0) {
                    if ((fit_value[j + k] = ts4_if_call_seq_u32_off8_883BE820(books + book, &vb->opb)) == -1)
                        goto eop;
                } else {
                    fit_value[j + k] = 0;
                }
            }
            j += cdim;
        }

        /* unwrap positive values and reconsitute via linear interpolation */
        for (i = 2; i < look->posts; i++) {
            int predicted = render_point(info->postlist[look->loneighbor[i - 2]],
                                         info->postlist[look->hineighbor[i - 2]],
                                         fit_value[look->loneighbor[i - 2]],
                                         fit_value[look->hineighbor[i - 2]],
                                         info->postlist[i]);
            int hiroom = look->quant_q - predicted;
            int loroom = predicted;
            int room = (hiroom < loroom ? hiroom : loroom) << 1;
            int val = fit_value[i];

            if (val) {
                if (val >= room) {
                    if (hiroom > loroom) {
                        val = val - loroom;
                    } else {
                        val = -1 - (val - hiroom);
                    }
                } else {
                    if (val & 1) {
                        val = -((val + 1) >> 1);
                    } else {
                        val >>= 1;
                    }
                }

                fit_value[i] = val + predicted;
                fit_value[look->loneighbor[i - 2]] &= 0x7fff;
                fit_value[look->hineighbor[i - 2]] &= 0x7fff;

            } else {
                fit_value[i] = predicted | 0x8000;
            }
        }

        return (fit_value);
    }
eop:
    return (NULL);
}

