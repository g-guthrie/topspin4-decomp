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

 function: residue backend 0, 1 and 2 implementation

 ********************************************************************/
/* Derived from libvorbis 1.2.3 lib/res0.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex: FMOD context
   argument, allocation-failure checks, encoder and training code absent. */
#include "aud1_vorbis.h"

void *_alloca(lib2_size_t n);

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct vorbis_info_residue0 {
    /* block-partitioned VQ coded straight residue */
    long begin;
    long end;

    /* first stage (lossless partitioning) */
    int grouping;          /* group n vectors per partition */
    int partitions;        /* possible codebooks for a partition */
    int groupbook;         /* huffbook for partitioning */
    int secondstages[64];  /* expanded out to pointers in lookup */
    int booklist[256];     /* list of second stage books */

    float classmetric1[64];
    float classmetric2[64];
} vorbis_info_residue0;

typedef struct {
    vorbis_info_residue0 *info;

    int parts;
    int stages;
    codebook *fullbooks;
    codebook *phrasebook;
    codebook ***partbooks;

    int partvals;
    int **decodemap;

    long postbits;
    long phrasebits;
    long frames;
} vorbis_look_residue0;

/* res0_free_info (exported copy is ts4_if_call_seq_ts4_memset_883C4BB8;
   this one is inlined into the unpacker) */
static void res0_free_info(void *ctx, vorbis_info_residue *i)
{
    vorbis_info_residue0 *info = (vorbis_info_residue0 *)i;
    if (info) {
        ts4_memset(info, 0, sizeof(*info));
        fn_8836CD70(ctx, info);
    }
}

/* res0_free_look */
void aud1_res0_free_look_883C4C10(void *ctx, vorbis_look_residue *i)
{
    int j;
    if (i) {
        vorbis_look_residue0 *look = (vorbis_look_residue0 *)i;

        for (j = 0; j < look->parts; j++)
            if (look->partbooks[j]) fn_8836CD70(ctx, look->partbooks[j]);
        fn_8836CD70(ctx, look->partbooks);
        for (j = 0; j < look->partvals; j++)
            fn_8836CD70(ctx, look->decodemap[j]);
        fn_8836CD70(ctx, look->decodemap);

        ts4_memset(look, 0, sizeof(*look));
        fn_8836CD70(ctx, look);
    }
}

static int icount(unsigned int v)
{
    int ret = 0;
    while (v) {
        ret += v & 1;
        v >>= 1;
    }
    return (ret);
}

/* res0_unpack: vorbis_info is for range checking */
vorbis_info_residue *aud1_res0_unpack_883C4CE8(void *ctx, vorbis_info *vi, oggpack_buffer *opb)
{
    int j, acc = 0;
    vorbis_info_residue0 *info = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(*info));
    codec_setup_info *ci = vi->codec_setup;
    if (!info) return (NULL);

    info->begin = lib2_oggpack_read_883BD268(opb, 24);
    info->end = lib2_oggpack_read_883BD268(opb, 24);
    info->grouping = lib2_oggpack_read_883BD268(opb, 24) + 1;
    info->partitions = lib2_oggpack_read_883BD268(opb, 6) + 1;
    info->groupbook = lib2_oggpack_read_883BD268(opb, 8);

    /* check for premature EOP */
    if (info->groupbook < 0) goto errout;

    for (j = 0; j < info->partitions; j++) {
        int cascade = lib2_oggpack_read_883BD268(opb, 3);
        int cflag = lib2_oggpack_read_883BD268(opb, 1);
        if (cflag < 0) goto errout;
        if (cflag) {
            int c = lib2_oggpack_read_883BD268(opb, 5);
            if (c < 0) goto errout;
            cascade |= (c << 3);
        }
        info->secondstages[j] = cascade;

        acc += icount(cascade);
    }
    for (j = 0; j < acc; j++) {
        int book = lib2_oggpack_read_883BD268(opb, 8);
        if (book < 0) goto errout;
        info->booklist[j] = book;
    }

    if (info->groupbook >= ci->books) goto errout;
    for (j = 0; j < acc; j++) {
        if (info->booklist[j] >= ci->books) goto errout;
        if (ci->book_param[info->booklist[j]]->maptype == 0) goto errout;
    }

    /* verify the phrasebook is not specifying an impossible or
       inconsistent partitioning scheme. */
    {
        int entries = ci->book_param[info->groupbook]->entries;
        int dim = ci->book_param[info->groupbook]->dim;
        int partvals = 1;
        while (dim > 0) {
            partvals *= info->partitions;
            if (partvals > entries) goto errout;
            dim--;
        }
    }

    return (info);
errout:
    res0_free_info(ctx, info);
    return (NULL);
}

/* _01inverse: shared decoder for residue types 0 and 1. */
int aud1__01inverse_883C51B0(void *ctx, vorbis_block *vb, vorbis_look_residue *vl,
                             float **in, int ch,
                             long (*decodepart)(codebook *, float *,
                                                oggpack_buffer *, int))
{
    long i, j, k, l, s;
    vorbis_look_residue0 *look = (vorbis_look_residue0 *)vl;
    vorbis_info_residue0 *info = look->info;

    /* move all this setup out later */
    int samples_per_partition = info->grouping;
    int partitions_per_word = look->phrasebook->dim;
    int max = vb->pcmend >> 1;
    int end = (info->end < max ? info->end : max);
    int n = end - info->begin;

    if (n > 0) {
        int partvals = n / samples_per_partition;
        int partwords = (partvals + partitions_per_word - 1) / partitions_per_word;
        int ***partword = _alloca(ch * sizeof(*partword));

        for (j = 0; j < ch; j++) {
            partword[j] = aud1__vorbis_block_alloc_883BBDD8(ctx, vb, partwords * sizeof(*partword[j]));
            if (!partword[j]) return (OV_EMEMORY);
        }

        for (s = 0; s < look->stages; s++) {
            /* each loop decodes on partition codeword containing
               partitions_per_word partitions */
            for (i = 0, l = 0; i < partvals; l++) {
                if (s == 0) {
                    /* fetch the partition word for each channel */
                    for (j = 0; j < ch; j++) {
                        int temp = ts4_if_call_seq_u32_off8_883BE820(look->phrasebook, &vb->opb);

                        if (temp == -1) goto eopbreak;
                        partword[j][l] = look->decodemap[temp];
                        if (partword[j][l] == NULL) goto errout;
                    }
                }

                /* now we decode residual values for the partitions */
                for (k = 0; k < partitions_per_word && i < partvals; k++, i++)
                    for (j = 0; j < ch; j++) {
                        long offset = info->begin + i * samples_per_partition;
                        if (info->secondstages[partword[j][l][k]] & (1 << s)) {
                            codebook *stagebook = look->partbooks[partword[j][l][k]][s];
                            if (stagebook) {
                                if (decodepart(stagebook, in[j] + offset, &vb->opb,
                                               samples_per_partition) == -1) goto eopbreak;
                            }
                        }
                    }
            }
        }
    }
errout:
eopbreak:
    return (0);
}

/* res0_inverse */
int aud1_res0_inverse_883C5438(void *ctx, vorbis_block *vb, vorbis_look_residue *vl,
                               float **in, int *nonzero, int ch)
{
    int i, used = 0;
    for (i = 0; i < ch; i++)
        if (nonzero[i])
            in[used++] = in[i];
    if (used)
        return (aud1__01inverse_883C51B0(ctx, vb, vl, in, used, fn_883BE888));
    else
        return (0);
}

/* res1_inverse */
int aud1_res1_inverse_883C5498(void *ctx, vorbis_block *vb, vorbis_look_residue *vl,
                               float **in, int *nonzero, int ch)
{
    int i, used = 0;
    for (i = 0; i < ch; i++)
        if (nonzero[i])
            in[used++] = in[i];
    if (used)
        return (aud1__01inverse_883C51B0(ctx, vb, vl, in, used, aud1_vorbis_book_decodev_add_883BEA60));
    else
        return (0);
}

/* res2_inverse */
int aud1_res2_inverse_883C54F8(void *ctx, vorbis_block *vb, vorbis_look_residue *vl,
                               float **in, int *nonzero, int ch)
{
    long i, k, l, s;
    vorbis_look_residue0 *look = (vorbis_look_residue0 *)vl;
    vorbis_info_residue0 *info = look->info;

    /* move all this setup out later */
    int samples_per_partition = info->grouping;
    int partitions_per_word = look->phrasebook->dim;
    int max = (vb->pcmend * ch) >> 1;
    int end = (info->end < max ? info->end : max);
    int n = end - info->begin;

    if (n > 0) {
        int partvals = n / samples_per_partition;
        int partwords = (partvals + partitions_per_word - 1) / partitions_per_word;
        int **partword = aud1__vorbis_block_alloc_883BBDD8(ctx, vb, partwords * sizeof(*partword));
        if (!partword) return (-1);

        for (i = 0; i < ch; i++) if (nonzero[i]) break;
        if (i == ch) return (0); /* no nonzero vectors */

        for (s = 0; s < look->stages; s++) {
            for (i = 0, l = 0; i < partvals; l++) {
                if (s == 0) {
                    /* fetch the partition word */
                    int temp = ts4_if_call_seq_u32_off8_883BE820(look->phrasebook, &vb->opb);
                    if (temp == -1) goto eopbreak;
                    partword[l] = look->decodemap[temp];
                    if (partword[l] == NULL) goto errout;
                }

                /* now we decode residual values for the partitions */
                for (k = 0; k < partitions_per_word && i < partvals; k++, i++)
                    if (info->secondstages[partword[l][k]] & (1 << s)) {
                        codebook *stagebook = look->partbooks[partword[l][k]][s];

                        if (stagebook) {
                            if (fn_883BECA0(stagebook, in,
                                            i * samples_per_partition + info->begin, ch,
                                            &vb->opb, samples_per_partition) == -1)
                                goto eopbreak;
                        }
                    }
            }
        }
    }
errout:
eopbreak:
    return (0);
}
