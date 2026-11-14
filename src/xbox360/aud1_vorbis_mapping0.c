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

 function: channel mapping 0 implementation

 ********************************************************************/
/* Derived from libvorbis 1.2.3 lib/mapping0.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex: FMOD context
   argument passed to every backend; encoder functions absent. */
#include "aud1_vorbis.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

void *_alloca(lib2_size_t n);
void fn_883C4020(mdct_lookup *init, float *in, float *out); /* mdct_backward */

typedef struct vorbis_info_mapping0 {
    int submaps;          /* <= 16 */
    int chmuxlist[256];   /* up to 256 channels in a Vorbis stream */

    int floorsubmap[16];   /* [mux] submap to floors */
    int residuesubmap[16]; /* [mux] submap to residue */

    int coupling_steps;
    int coupling_mag[256];
    int coupling_ang[256];
} vorbis_info_mapping0;

/* mapping0_free_info (exported copy is ts4_if_call_seq_ts4_memset_883C4360) */
static void mapping0_free_info(void *ctx, vorbis_info_mapping *i)
{
    vorbis_info_mapping0 *info = (vorbis_info_mapping0 *)i;
    if (info) {
        ts4_memset(info, 0, sizeof(*info));
        ts4_if_get_u32_off500_8836CD70(ctx, info);
    }
}

static int ilog(unsigned int v)
{
    int ret = 0;
    if (v) --v;
    while (v) {
        ret++;
        v >>= 1;
    }
    return (ret);
}

/* mapping0_unpack */
vorbis_info_mapping *aud1_mapping0_unpack_883C43B8(void *ctx, vorbis_info *vi, oggpack_buffer *opb)
{
    int i, b;
    vorbis_info_mapping0 *info = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(*info));
    codec_setup_info *ci = vi->codec_setup;
    ts4_memset(info, 0, sizeof(*info));

    b = lib2_oggpack_read_883BD268(opb, 1);
    if (b < 0) goto err_out;
    if (b) {
        info->submaps = lib2_oggpack_read_883BD268(opb, 4) + 1;
        if (info->submaps <= 0) goto err_out;
    } else
        info->submaps = 1;

    b = lib2_oggpack_read_883BD268(opb, 1);
    if (b < 0) goto err_out;
    if (b) {
        info->coupling_steps = lib2_oggpack_read_883BD268(opb, 8) + 1;
        if (info->coupling_steps <= 0) goto err_out;
        for (i = 0; i < info->coupling_steps; i++) {
            int testM = info->coupling_mag[i] = lib2_oggpack_read_883BD268(opb, ilog(vi->channels));
            int testA = info->coupling_ang[i] = lib2_oggpack_read_883BD268(opb, ilog(vi->channels));

            if (testM < 0 ||
                testA < 0 ||
                testM == testA ||
                testM >= vi->channels ||
                testA >= vi->channels) goto err_out;
        }
    }

    if (lib2_oggpack_read_883BD268(opb, 2) != 0) goto err_out; /* 2,3:reserved */

    if (info->submaps > 1) {
        for (i = 0; i < vi->channels; i++) {
            info->chmuxlist[i] = lib2_oggpack_read_883BD268(opb, 4);
            if (info->chmuxlist[i] >= info->submaps || info->chmuxlist[i] < 0) goto err_out;
        }
    }
    for (i = 0; i < info->submaps; i++) {
        lib2_oggpack_read_883BD268(opb, 8); /* time submap unused */
        info->floorsubmap[i] = lib2_oggpack_read_883BD268(opb, 8);
        if (info->floorsubmap[i] >= ci->floors || info->floorsubmap[i] < 0) goto err_out;
        info->residuesubmap[i] = lib2_oggpack_read_883BD268(opb, 8);
        if (info->residuesubmap[i] >= ci->residues || info->residuesubmap[i] < 0) goto err_out;
    }

    return info;

err_out:
    mapping0_free_info(ctx, info);
    return (NULL);
}

