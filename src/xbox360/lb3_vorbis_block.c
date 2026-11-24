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

 function: PCM data vector blocking, windowing and dis/reassembly

 ********************************************************************/
/* Derived from libvorbis 1.2.3 lib/block.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex: decode-only FMOD
   copy with a context argument and allocation-failure checks. */
#include "aud1_vorbis.h"

int fn_883C33B8(void *ctx, mdct_lookup *lookup, int n);                  /* mdct_init */
int fn_883BDB78(void *ctx, codebook *dest, const static_codebook *source); /* vorbis_book_init_decode */
int ts4_if_call_seq_u32_off24_883BDA50(void *ctx, static_codebook *b);   /* vorbis_staticbook_destroy */

static int ilog2(unsigned int v)
{
    int ret = 0;
    if (v) --v;
    while (v) {
        ret++;
        v >>= 1;
    }
    return (ret);
}

/* _vds_shared_init: allocate the decode backend state, transforms, books and lookups. */
int fn_883BBFB8(void *ctx, vorbis_dsp_state *v, vorbis_info *vi)
{
    int i;
    codec_setup_info *ci = vi->codec_setup;
    private_state *b = 0;
    int hs;

    if (ci == 0) return 1;
    hs = ci->halfrate_flag;

    ts4_memset(v, 0, sizeof(*v));
    b = v->backend_state = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(*b));
    if (!b) return OV_EMEMORY;

    v->vi = vi;
    b->modebits = ilog2(ci->modes);

    b->transform[0] = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(*b->transform[0]));
    if (!b->transform[0]) return OV_EMEMORY;
    b->transform[1] = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(*b->transform[1]));
    if (!b->transform[1]) return OV_EMEMORY;

    /* MDCT is tranform 0 */

    b->transform[0][0] = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(mdct_lookup));
    if (!b->transform[0][0]) return OV_EMEMORY;
    b->transform[1][0] = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(mdct_lookup));
    if (!b->transform[1][0]) return OV_EMEMORY;
    if (fn_883C33B8(ctx, b->transform[0][0], ci->blocksizes[0] >> hs)) return OV_EMEMORY;
    if (fn_883C33B8(ctx, b->transform[1][0], ci->blocksizes[1] >> hs)) return OV_EMEMORY;

    /* Vorbis I uses only window type 0 */
    b->window[0] = ilog2(ci->blocksizes[0]) - 6;
    b->window[1] = ilog2(ci->blocksizes[1]) - 6;

    /* finish the codebooks */
    if (!ci->fullbooks) {
        ci->fullbooks = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, ci->books, sizeof(*ci->fullbooks));
        if (!ci->fullbooks) return OV_EMEMORY;
        for (i = 0; i < ci->books; i++) {
            codebook *cb = ci->fullbooks;
            if (fn_883BDB78(ctx, cb + i, ci->book_param[i]))
                return OV_EMEMORY;
            /* decode codebooks are now standalone after init */
            ts4_if_call_seq_u32_off24_883BDA50(ctx, ci->book_param[i]);
            ci->book_param[i] = 0;
        }
    }

    /* initialize the storage vectors. blocksize[1] is small for encode,
       but the correct size for decode */
    v->pcm_storage = ci->blocksizes[1];
    v->pcm = ts4_alloc_count_500_8836CBE8(ctx, vi->channels * sizeof(*v->pcm));
    if (!v->pcm) return OV_EMEMORY;
    v->pcmret = ts4_alloc_count_500_8836CBE8(ctx, vi->channels * sizeof(*v->pcmret));
    if (!v->pcmret) return OV_EMEMORY;
    {
        int i;
        for (i = 0; i < vi->channels; i++) {
            v->pcm[i] = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, v->pcm_storage, sizeof(*v->pcm[i]));
            if (!v->pcm[i]) return OV_EMEMORY;
        }
    }

    /* all 1 (large block) or 0 (small block) */
    /* explicitly set for the sake of clarity */
    v->lW = 0; /* previous window size */
    v->W = 0;  /* current window size */

    /* all vector indexes */
    v->centerW = ci->blocksizes[1] / 2;

    v->pcm_current = v->centerW;

    /* initialize all the backend lookups */
    b->flr = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, ci->floors, sizeof(*b->flr));
    if (!b->flr) return OV_EMEMORY;
    b->residue = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, ci->residues, sizeof(*b->residue));
    if (!b->residue) return OV_EMEMORY;

    for (i = 0; i < ci->floors; i++)
        b->flr[i] = lbl_88035FCC[ci->floor_type[i]]->look(ctx, v, ci->floor_param[i]);

    for (i = 0; i < ci->residues; i++)
        b->residue[i] = lbl_88035FD4[ci->residue_type[i]]->look(ctx, v, ci->residue_param[i]);

    return 0;
}


