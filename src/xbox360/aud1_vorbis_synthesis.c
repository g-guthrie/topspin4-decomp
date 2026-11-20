/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2007             *
 * by the Xiph.Org Foundation http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: single-block PCM synthesis

 ********************************************************************/
/* Derived from libvorbis 1.2.3 lib/synthesis.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex: FMOD context
   argument, ripcord status and allocation failures propagated. */
#include "aud1_vorbis.h"

int aud1__vorbis_block_ripcord_883BBE98(void *ctx, vorbis_block *vb);              /* _vorbis_block_ripcord */
void *aud1__vorbis_block_alloc_883BBDD8(void *ctx, vorbis_block *vb, long bytes); /* _vorbis_block_alloc */

/* vorbis_synthesis: unpack an audio packet header and run the mapping inverse. */
int aud1_vorbis_synthesis_883BB9E0(void *ctx, vorbis_block *vb, ogg_packet *op)
{
    vorbis_dsp_state *vd = vb->vd;
    private_state *b = vd->backend_state;
    vorbis_info *vi = vd->vi;
    codec_setup_info *ci = vi->codec_setup;
    oggpack_buffer *opb = &vb->opb;
    int type, mode, i;
    int ret;

    /* first things first.  Make sure decode is ready */
    ret = aud1__vorbis_block_ripcord_883BBE98(ctx, vb);
    if (ret) return ret;
    ts4_call_seq_ts4_memset_883BD130(opb, op->packet, op->bytes);

    /* Check the packet type */
    if (lib2_oggpack_read_883BD268(opb, 1) != 0) {
        /* Oops.  This is not an audio data packet */
        return (OV_ENOTAUDIO);
    }

    /* read our mode and pre/post windowsize */
    mode = lib2_oggpack_read_883BD268(opb, b->modebits);
    if (mode == -1) return (OV_EBADPACKET);

    vb->mode = mode;
    vb->W = ci->mode_param[mode]->blockflag;
    if (vb->W) {

        /* this doesn;t get mapped through mode selection as it's used
           only for window selection */
        vb->lW = lib2_oggpack_read_883BD268(opb, 1);
        vb->nW = lib2_oggpack_read_883BD268(opb, 1);
        if (vb->nW == -1) return (OV_EBADPACKET);
    } else {
        vb->lW = 0;
        vb->nW = 0;
    }

    /* more setup */
    vb->granulepos = op->granulepos;
    vb->sequence = op->packetno;
    vb->eofflag = op->e_o_s;

    /* alloc pcm passback storage */
    vb->pcmend = ci->blocksizes[vb->W];
    vb->pcm = aud1__vorbis_block_alloc_883BBDD8(ctx, vb, sizeof(*vb->pcm) * vi->channels);
    if (!vb->pcm) return OV_EMEMORY;
    for (i = 0; i < vi->channels; i++) {
        vb->pcm[i] = aud1__vorbis_block_alloc_883BBDD8(ctx, vb, vb->pcmend * sizeof(*vb->pcm[i]));
        if (!vb->pcm[i]) return OV_EMEMORY;
    }

    /* unpack_header enforces range checking */
    type = ci->map_type[ci->mode_param[mode]->mapping];

    return (lbl_88035FE0[type]->inverse(ctx, vb, ci->map_param[ci->mode_param[mode]->mapping]));
}

/* vorbis_synthesis_trackonly: track pcm position without decoding. */
int aud1_vorbis_synthesis_trackonly_883BBBB0(void *ctx, vorbis_block *vb, ogg_packet *op)
{
    vorbis_dsp_state *vd = vb->vd;
    private_state *b = vd->backend_state;
    vorbis_info *vi = vd->vi;
    codec_setup_info *ci = vi->codec_setup;
    oggpack_buffer *opb = &vb->opb;
    int mode;
    int ret;

    /* first things first.  Make sure decode is ready */
    ret = aud1__vorbis_block_ripcord_883BBE98(ctx, vb);
    if (ret) return ret;
    ts4_call_seq_ts4_memset_883BD130(opb, op->packet, op->bytes);

    /* Check the packet type */
    if (lib2_oggpack_read_883BD268(opb, 1) != 0) {
        /* Oops.  This is not an audio data packet */
        return (OV_ENOTAUDIO);
    }

    /* read our mode and pre/post windowsize */
    mode = lib2_oggpack_read_883BD268(opb, b->modebits);
    if (mode == -1) return (OV_EBADPACKET);

    vb->mode = mode;
    vb->W = ci->mode_param[mode]->blockflag;
    if (vb->W) {
        vb->lW = lib2_oggpack_read_883BD268(opb, 1);
        vb->nW = lib2_oggpack_read_883BD268(opb, 1);
        if (vb->nW == -1) return (OV_EBADPACKET);
    } else {
        vb->lW = 0;
        vb->nW = 0;
    }

    /* more setup */
    vb->granulepos = op->granulepos;
    vb->sequence = op->packetno;
    vb->eofflag = op->e_o_s;

    /* no pcm */
    vb->pcmend = 0;
    vb->pcm = 0;

    return (0);
}

/* vorbis_packet_blocksize: blocksize of an audio packet without decoding it. */
long aud1_vorbis_packet_blocksize_883BBCB8(vorbis_info *vi, ogg_packet *op)
{
    codec_setup_info *ci = vi->codec_setup;
    oggpack_buffer opb;
    int mode;

    ts4_call_seq_ts4_memset_883BD130(&opb, op->packet, op->bytes);

    /* Check the packet type */
    if (lib2_oggpack_read_883BD268(&opb, 1) != 0) {
        /* Oops.  This is not an audio data packet */
        return (OV_ENOTAUDIO);
    }

    {
        int modebits = 0;
        int v = ci->modes;
        while (v > 1) {
            modebits++;
            v >>= 1;
        }

        /* read our mode and pre/post windowsize */
        mode = lib2_oggpack_read_883BD268(&opb, modebits);
    }
    if (mode == -1) return (OV_EBADPACKET);
    return (ci->blocksizes[ci->mode_param[mode]->blockflag]);
}
