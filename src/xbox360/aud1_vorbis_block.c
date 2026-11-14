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

int fn_883BBFB8(void *ctx, vorbis_dsp_state *v, vorbis_info *vi); /* draft: work/aud1_drafts */
void fn_883BC3B8(void *ctx, vorbis_dsp_state *v); /* draft: work/aud1_drafts */

#define WORD_ALIGN 8

int fn_883C33B8(void *ctx, mdct_lookup *lookup, int n);                  /* mdct_init */
void ts4_if_call_seq_u32_off8_883C3E70(void *ctx, mdct_lookup *lookup);  /* mdct_clear */
int fn_883BDB78(void *ctx, codebook *dest, const static_codebook *source); /* vorbis_book_init_decode */
int ts4_if_call_seq_u32_off24_883BDA50(void *ctx, static_codebook *b);   /* vorbis_staticbook_destroy */

/* _vorbis_block_alloc: bump allocator over the block's local storage. */
void *aud1__vorbis_block_alloc_883BBDD8(void *ctx, vorbis_block *vb, long bytes)
{
    bytes = (bytes + (WORD_ALIGN - 1)) & ~(WORD_ALIGN - 1);
    if (bytes + vb->localtop > vb->localalloc) {
        /* can't just _ogg_realloc... there are outstanding pointers */
        if (vb->localstore) {
            struct alloc_chain *link = fn_8836CBE8(ctx, sizeof(*link));
            if (!link) return 0;
            vb->totaluse += vb->localtop;
            link->next = vb->reap;
            link->ptr = vb->localstore;
            vb->reap = link;
        }
        /* highly conservative */
        vb->localalloc = bytes;
        vb->localstore = fn_8836CBE8(ctx, vb->localalloc);
        if (!vb->localstore) return 0;
        vb->localtop = 0;
    }
    {
        void *ret = (void *)(((char *)vb->localstore) + vb->localtop);
        vb->localtop += bytes;
        return ret;
    }
}

/* _vorbis_block_ripcord: reap the chain, consolidate storage, pull the ripcord. */
int aud1__vorbis_block_ripcord_883BBE98(void *ctx, vorbis_block *vb)
{
    /* reap the chain */
    struct alloc_chain *reap = vb->reap;
    int ret = 0;
    while (reap) {
        struct alloc_chain *next = reap->next;
        ts4_if_get_u32_off500_8836CD70(ctx, reap->ptr);
        ts4_memset(reap, 0, sizeof(*reap));
        ts4_if_get_u32_off500_8836CD70(ctx, reap);
        reap = next;
    }
    /* consolidate storage */
    if (vb->totaluse) {
        vb->localstore = fn_8836CCD8(ctx, vb->localstore, vb->totaluse + vb->localalloc);
        if (!vb->localstore) ret = OV_EMEMORY;
        vb->localalloc += vb->totaluse;
        vb->totaluse = 0;
    }

    /* pull the ripcord */
    vb->localtop = 0;
    vb->reap = 0;
    return ret;
}

/* vorbis_synthesis_restart: reset decode position state. */
int aud1_vorbis_synthesis_restart_883BC5F8(vorbis_dsp_state *v)
{
    vorbis_info *vi = v->vi;
    codec_setup_info *ci;
    int hs;

    if (!v->backend_state) return -1;
    if (!vi) return -1;
    ci = vi->codec_setup;
    if (!ci) return -1;
    hs = ci->halfrate_flag;

    v->centerW = ci->blocksizes[1] >> (hs + 1);
    v->pcm_current = v->centerW >> hs;

    v->pcm_returned = -1;
    v->granulepos = -1;
    v->sequence = -1;
    v->eofflag = 0;
    ((private_state *)(v->backend_state))->sample_count = -1;

    return (0);
}

/* vorbis_synthesis_init: shared init for decode, then reset position state. */
int aud1_vorbis_synthesis_init_883BC668(void *ctx, vorbis_dsp_state *v, vorbis_info *vi)
{
    int ret = fn_883BBFB8(ctx, v, vi);
    if (ret) {
        fn_883BC3B8(ctx, v);
        return ret;
    }
    aud1_vorbis_synthesis_restart_883BC5F8(v);
    return 0;
}

/* vorbis_synthesis_pcmout: expose decoded but unreturned samples. */
int aud1_vorbis_synthesis_pcmout_883BD068(vorbis_dsp_state *v, float ***pcm)
{
    vorbis_info *vi = v->vi;

    if (v->pcm_returned > -1 && v->pcm_returned < v->pcm_current) {
        if (pcm) {
            int i;
            for (i = 0; i < vi->channels; i++)
                v->pcmret[i] = v->pcm[i] + v->pcm_returned;
            *pcm = v->pcmret;
        }
        return (v->pcm_current - v->pcm_returned);
    }
    return (0);
}
