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

 function: basic shared codebook operations

 ********************************************************************/
/* Derived from libvorbis 1.2.3 lib/sharedbook.c (codebook layout without quantvals/minval/delta) (BSD license); see
   THIRD_PARTY_NOTICES.md. FMOD variant: allocating calls take a leading
   context. The float literal 1.f is referenced through the image's
   constant-pool label so relocations name the same symbols. */
#include "lib2_ogg.h"

typedef struct static_codebook {
    long dim;
    long entries;
    long *lengthlist;
    int maptype;
    long q_min;
    long q_delta;
    int q_quant;
    int q_sequencep;
    long *quantlist;
    struct encode_aux_nearestmatch *nearest_tree; /* encoder-only, 1.2.x */
    struct encode_aux_threshmatch *thresh_tree;
    struct encode_aux_pigeonhole *pigeon_tree;
    int allocedp;
} static_codebook;

typedef struct codebook {
    long dim;
    long entries;
    long used_entries;
    const static_codebook *c;
    float *valuelist;
    ogg_uint32_t *codelist;
    int *dec_index;
    char *dec_codelengths;
    ogg_uint32_t *dec_firsttable;
    int dec_firsttablen;
    int dec_maxlength;
} codebook;

double fn_88563A38(double x, double y);   /* pow */
double fn_88564430(double x);             /* floor */
extern const float lbl_88001A68;          /* 1.0f */

/* _make_words: given a list of word lengths, generate a list of codewords. */
ogg_uint32_t *lib2__make_words_883BD3A0(void *ctx, long *l, long n, long sparsecount)
{
    long i, j, count = 0;
    ogg_uint32_t marker[33];
    ogg_uint32_t *r = fn_8836CBE8(ctx, (sparsecount ? sparsecount : n) * sizeof(*r));
    if (!r) return 0; /* FMOD addition: allocation check */
    ts4_memset(marker, 0, sizeof(marker));

    for (i = 0; i < n; i++) {
        long length = l[i];
        if (length > 0) {
            ogg_uint32_t entry = marker[length];

            /* update ourself */
            if (length < 32 && (entry >> length)) {
                /* error condition; the lengths must specify an overpopulated tree */
                fn_8836CD70(ctx, r);
                return (0);
            }
            r[count++] = entry;

            /* Look to see if the next shorter marker points to the node
               above. if so, update it and repeat.  */
            {
                for (j = length; j > 0; j--) {
                    if (marker[j] & 1) {
                        /* have to jump branches */
                        if (j == 1)
                            marker[1]++;
                        else
                            marker[j] = marker[j - 1] << 1;
                        break;
                    }
                    marker[j]++;
                }
            }

            /* prune the tree */
            for (j = length + 1; j < 33; j++)
                if ((marker[j] >> 1) == entry) {
                    entry = marker[j];
                    marker[j] = marker[j - 1] << 1;
                } else
                    break;
        } else
            if (sparsecount == 0) count++;
    }

    /* sanity check the huffman tree; an underpopulated tree must be rejected. */
    if (sparsecount != 1) {
        for (i = 1; i < 33; i++)
            if (marker[i] & (0xffffffffUL >> (32 - i))) {
                fn_8836CD70(ctx, r);
                return (0);
            }
    }

    /* bitreverse the words because our bitwise packer/unpacker is LSb endian */
    for (i = 0, count = 0; i < n; i++) {
        ogg_uint32_t temp = 0;
        for (j = 0; j < l[i]; j++) {
            temp <<= 1;
            temp |= (r[count] >> j) & 1;
        }

        if (sparsecount) {
            if (l[i])
                r[count++] = temp;
        } else
            r[count++] = temp;
    }

    return (r);
}

/* _book_maptype1_quantvals: greatest vals with vals^dim <= entries. */
long lib2__book_maptype1_quantvals_883BD5D0(const static_codebook *b)
{
    long vals = (long)(float)fn_88564430((float)fn_88563A38((float)b->entries, lbl_88001A68 / b->dim));

    /* verify via integer means; treat the above as an initial guess */
    while (1) {
        long acc = 1;
        long acc1 = 1;
        int i;
        for (i = 0; i < b->dim; i++) {
            acc *= vals;
            acc1 *= vals + 1;
        }
        if (acc <= b->entries && acc1 > b->entries) {
            return (vals);
        } else {
            if (acc > b->entries) {
                vals--;
            } else {
                vals++;
            }
        }
    }
}

/* sort32a: qsort comparator on the codewords the pointers address. */
int lib2_sort32a_883BDB48(const void *a, const void *b)
{
    return (**(ogg_uint32_t **)a > **(ogg_uint32_t **)b) -
           (**(ogg_uint32_t **)a < **(ogg_uint32_t **)b);
}
