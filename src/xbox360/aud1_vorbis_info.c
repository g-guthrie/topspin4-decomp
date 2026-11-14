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

 function: maintain the info structure, info <-> header packets

 ********************************************************************/
/* Derived from libvorbis 1.2.3 lib/info.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex: FMOD context
   argument, allocation-failure checks returning OV_EMEMORY, floor 0 rejected,
   encoder-only psy state removed. */
#include "aud1_vorbis.h"

extern const char lbl_8802F7CC[]; /* "vorbis" */

int ts4_if_call_seq_u32_off24_883BDA50(void *ctx, static_codebook *b); /* vorbis_staticbook_destroy */
void ts4_if_call_seq_u32_off10_883BDAA0(void *ctx, codebook *b);       /* vorbis_book_clear */
int aud1_vorbis_staticbook_unpack_883BE2A8(void *ctx, oggpack_buffer *opb, static_codebook *s);   /* vorbis_staticbook_unpack */

static void _v_readstring(oggpack_buffer *o, char *buf, int bytes)
{
    while (bytes--) {
        *buf++ = (char)lib2_oggpack_read_883BD268(o, 8);
    }
}

/* vorbis_comment_clear: free every comment string, the arrays and the vendor. */
void aud1_vorbis_comment_clear_883AAD18(void *ctx, vorbis_comment *vc)
{
    if (vc) {
        long i;
        if (vc->user_comments) {
            for (i = 0; i < vc->comments; i++)
                if (vc->user_comments[i]) ts4_if_get_u32_off500_8836CD70(ctx, vc->user_comments[i]);
            ts4_if_get_u32_off500_8836CD70(ctx, vc->user_comments);
        }
        if (vc->comment_lengths) ts4_if_get_u32_off500_8836CD70(ctx, vc->comment_lengths);
        if (vc->vendor) ts4_if_get_u32_off500_8836CD70(ctx, vc->vendor);
        ts4_memset(vc, 0, sizeof(*vc));
    }
}

/* vorbis_info_init: zero the info and allocate the codec setup (FMOD: returns status). */
int aud1_vorbis_info_init_883AADF0(void *ctx, vorbis_info *vi)
{
    ts4_memset(vi, 0, sizeof(*vi));
    vi->codec_setup = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(codec_setup_info));
    return vi->codec_setup ? 0 : OV_EMEMORY;
}

/* vorbis_info_clear: release modes, backend settings, codebooks and the setup. */
void aud1_vorbis_info_clear_883AAE58(void *ctx, vorbis_info *vi)
{
    codec_setup_info *ci = vi->codec_setup;
    int i;

    if (ci) {

        for (i = 0; i < ci->modes; i++)
            if (ci->mode_param[i]) ts4_if_get_u32_off500_8836CD70(ctx, ci->mode_param[i]);

        for (i = 0; i < ci->maps; i++) /* unpack does the range checking */
            if (ci->map_param[i])
                lbl_88035FE0[ci->map_type[i]]->free_info(ctx, ci->map_param[i]);

        for (i = 0; i < ci->floors; i++) /* unpack does the range checking */
            if (ci->floor_param[i])
                lbl_88035FCC[ci->floor_type[i]]->free_info(ctx, ci->floor_param[i]);

        for (i = 0; i < ci->residues; i++) /* unpack does the range checking */
            if (ci->residue_param[i])
                lbl_88035FD4[ci->residue_type[i]]->free_info(ctx, ci->residue_param[i]);

        for (i = 0; i < ci->books; i++) {
            if (ci->book_param[i]) {
                /* knows if the book was not alloced */
                ts4_if_call_seq_u32_off24_883BDA50(ctx, ci->book_param[i]);
            }
            if (ci->fullbooks)
                ts4_if_call_seq_u32_off10_883BDAA0(ctx, ci->fullbooks + i);
        }
        if (ci->fullbooks)
            ts4_if_get_u32_off500_8836CD70(ctx, ci->fullbooks);

        ts4_if_get_u32_off500_8836CD70(ctx, ci);
    }

    ts4_memset(vi, 0, sizeof(*vi));
}

/* _vorbis_unpack_info: identification header (version, channels, rate, blocksizes). */
int aud1__vorbis_unpack_info_883AB050(void *ctx, vorbis_info *vi, oggpack_buffer *opb)
{
    codec_setup_info *ci = vi->codec_setup;
    if (!ci) return (OV_EFAULT);

    vi->version = lib2_oggpack_read_883BD268(opb, 32);
    if (vi->version != 0) return (OV_EVERSION);

    vi->channels = lib2_oggpack_read_883BD268(opb, 8);
    vi->rate = lib2_oggpack_read_883BD268(opb, 32);

    vi->bitrate_upper = lib2_oggpack_read_883BD268(opb, 32);
    vi->bitrate_nominal = lib2_oggpack_read_883BD268(opb, 32);
    vi->bitrate_lower = lib2_oggpack_read_883BD268(opb, 32);

    ci->blocksizes[0] = 1 << lib2_oggpack_read_883BD268(opb, 4);
    ci->blocksizes[1] = 1 << lib2_oggpack_read_883BD268(opb, 4);

    if (vi->rate < 1) goto err_out;
    if (vi->channels < 1) goto err_out;
    if (ci->blocksizes[0] < 64) goto err_out;
    if (ci->blocksizes[1] < ci->blocksizes[0]) goto err_out;
    if (ci->blocksizes[1] > 8192) goto err_out;

    if (lib2_oggpack_read_883BD268(opb, 1) != 1) goto err_out; /* EOP check */

    return (0);
err_out:
    aud1_vorbis_info_clear_883AAE58(ctx, vi);
    return (OV_EBADHEADER);
}

/* _vorbis_unpack_comment: vendor string and user comments. */
int aud1__vorbis_unpack_comment_883AB190(void *ctx, vorbis_comment *vc, oggpack_buffer *opb)
{
    int i;
    int ret = OV_EBADHEADER;
    int vendorlen = lib2_oggpack_read_883BD268(opb, 32);
    if (vendorlen < 0) goto err_out;
    if (vendorlen > opb->storage - 8) goto err_out;
    vc->vendor = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, vendorlen + 1, 1);
    if (!vc->vendor) { ret = OV_EMEMORY; goto err_out; }
    _v_readstring(opb, vc->vendor, vendorlen);
    i = lib2_oggpack_read_883BD268(opb, 32);
    if (i < 0) goto err_out;
    if (i > ((opb->storage - ts4_bit_cursor_byte_end_883BD358(opb)) >> 2)) goto err_out;
    vc->comments = i;
    vc->user_comments = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, vc->comments + 1, sizeof(*vc->user_comments));
    if (!vc->user_comments) { ret = OV_EMEMORY; goto err_out; }
    vc->comment_lengths = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, vc->comments + 1, sizeof(*vc->comment_lengths));
    if (!vc->comment_lengths) { ret = OV_EMEMORY; goto err_out; }

    for (i = 0; i < vc->comments; i++) {
        int len = lib2_oggpack_read_883BD268(opb, 32);
        if (len < 0) goto err_out;
        if (len > opb->storage - ts4_bit_cursor_byte_end_883BD358(opb)) goto err_out;
        vc->comment_lengths[i] = len;
        vc->user_comments[i] = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, len + 1, 1);
        if (!vc->user_comments[i]) { ret = OV_EMEMORY; goto err_out; }
        _v_readstring(opb, vc->user_comments[i], len);
    }
    if (lib2_oggpack_read_883BD268(opb, 1) != 1) goto err_out; /* EOP check */

    return (0);
err_out:
    aud1_vorbis_comment_clear_883AAD18(ctx, vc);
    return (ret);
}

/* _vorbis_unpack_books: codebooks, time/floor/residue/map backends and modes. */
int aud1__vorbis_unpack_books_883AB398(void *ctx, vorbis_info *vi, oggpack_buffer *opb)
{
    codec_setup_info *ci = vi->codec_setup;
    int i;
    int ret = OV_EBADHEADER;
    if (!ci) return (OV_EFAULT);

    /* codebooks */
    ci->books = lib2_oggpack_read_883BD268(opb, 8) + 1;
    if (ci->books <= 0) goto err_out;
    for (i = 0; i < ci->books; i++) {
        ci->book_param[i] = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(*ci->book_param[i]));
        if (!ci->book_param[i]) { ret = OV_EMEMORY; goto err_out; }
        {
            int r = aud1_vorbis_staticbook_unpack_883BE2A8(ctx, opb, ci->book_param[i]);
            if (r) { ret = r; goto err_out; }
        }
    }

    /* time backend settings; hooks are unused */
    {
        int times = lib2_oggpack_read_883BD268(opb, 6) + 1;
        if (times <= 0) goto err_out;
        for (i = 0; i < times; i++) {
            int test = lib2_oggpack_read_883BD268(opb, 16);
            if (test < 0 || test >= 1) goto err_out;
        }
    }

    /* floor backend settings */
    ci->floors = lib2_oggpack_read_883BD268(opb, 6) + 1;
    if (ci->floors <= 0) goto err_out;
    for (i = 0; i < ci->floors; i++) {
        ci->floor_type[i] = lib2_oggpack_read_883BD268(opb, 16);
        if (ci->floor_type[i] == 0) { ret = OV_EVERSION; goto err_out; }
        if (ci->floor_type[i] < 0 || ci->floor_type[i] >= 2) goto err_out;
        ci->floor_param[i] = lbl_88035FCC[ci->floor_type[i]]->unpack(ctx, vi, opb);
        if (!ci->floor_param[i]) goto err_out;
    }

    /* residue backend settings */
    ci->residues = lib2_oggpack_read_883BD268(opb, 6) + 1;
    if (ci->residues <= 0) goto err_out;
    for (i = 0; i < ci->residues; i++) {
        ci->residue_type[i] = lib2_oggpack_read_883BD268(opb, 16);
        if (ci->residue_type[i] < 0 || ci->residue_type[i] >= 3) goto err_out;
        ci->residue_param[i] = lbl_88035FD4[ci->residue_type[i]]->unpack(ctx, vi, opb);
        if (!ci->residue_param[i]) goto err_out;
    }

    /* map backend settings */
    ci->maps = lib2_oggpack_read_883BD268(opb, 6) + 1;
    if (ci->maps <= 0) goto err_out;
    for (i = 0; i < ci->maps; i++) {
        ci->map_type[i] = lib2_oggpack_read_883BD268(opb, 16);
        if (ci->map_type[i] < 0 || ci->map_type[i] >= 1) goto err_out;
        ci->map_param[i] = lbl_88035FE0[ci->map_type[i]]->unpack(ctx, vi, opb);
        if (!ci->map_param[i]) goto err_out;
    }

    /* mode settings */
    ci->modes = lib2_oggpack_read_883BD268(opb, 6) + 1;
    if (ci->modes <= 0) goto err_out;
    for (i = 0; i < ci->modes; i++) {
        ci->mode_param[i] = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(*ci->mode_param[i]));
        if (!ci->mode_param[i]) { ret = OV_EMEMORY; goto err_out; }
        ci->mode_param[i]->blockflag = lib2_oggpack_read_883BD268(opb, 1);
        ci->mode_param[i]->windowtype = lib2_oggpack_read_883BD268(opb, 16);
        ci->mode_param[i]->transformtype = lib2_oggpack_read_883BD268(opb, 16);
        ci->mode_param[i]->mapping = lib2_oggpack_read_883BD268(opb, 8);

        if (ci->mode_param[i]->windowtype >= 1) goto err_out;
        if (ci->mode_param[i]->transformtype >= 1) goto err_out;
        if (ci->mode_param[i]->mapping >= ci->maps) goto err_out;
        if (ci->mode_param[i]->mapping < 0) goto err_out;
    }

    if (lib2_oggpack_read_883BD268(opb, 1) != 1) goto err_out; /* top level EOP check */

    return (0);
err_out:
    aud1_vorbis_info_clear_883AAE58(ctx, vi);
    return (ret);
}

/* vorbis_synthesis_idheader: is this packet a Vorbis identification header? */
int aud1_vorbis_synthesis_idheader_883AB768(ogg_packet *op)
{
    oggpack_buffer opb;
    char buffer[6];

    if (op) {
        ts4_call_seq_ts4_memset_883BD130(&opb, op->packet, op->bytes);

        if (!op->b_o_s)
            return (0); /* Not the initial packet */

        if (lib2_oggpack_read_883BD268(&opb, 8) != 1)
            return 0; /* not an ID header */

        ts4_memset(buffer, 0, 6);
        _v_readstring(&opb, buffer, 6);
        if (memcmp(buffer, lbl_8802F7CC, 6))
            return 0; /* not vorbis */

        return 1;
    }

    return 0;
}

/* vorbis_synthesis_headerin: dispatch one of the three header packets. */
int aud1_vorbis_synthesis_headerin_883AB848(void *ctx, vorbis_info *vi, vorbis_comment *vc, ogg_packet *op)
{
    oggpack_buffer opb;

    if (op) {
        ts4_call_seq_ts4_memset_883BD130(&opb, op->packet, op->bytes);

        /* Which of the three types of header is this? */
        /* Also verify header-ness, vorbis */
        {
            char buffer[6];
            int packtype = lib2_oggpack_read_883BD268(&opb, 8);
            ts4_memset(buffer, 0, 6);
            _v_readstring(&opb, buffer, 6);
            if (memcmp(buffer, lbl_8802F7CC, 6)) {
                /* not a vorbis header */
                return (OV_ENOTVORBIS);
            }
            switch (packtype) {
            case 0x01: /* least significant *bit* is read first */
                if (!op->b_o_s) {
                    /* Not the initial packet */
                    return (OV_EBADHEADER);
                }
                if (vi->rate != 0) {
                    /* previously initialized info header */
                    return (OV_EBADHEADER);
                }

                return (aud1__vorbis_unpack_info_883AB050(ctx, vi, &opb));

            case 0x03: /* least significant *bit* is read first */
                if (vi->rate == 0) {
                    /* um... we didn't get the initial header */
                    return (OV_EBADHEADER);
                }

                return (aud1__vorbis_unpack_comment_883AB190(ctx, vc, &opb));

            case 0x05: /* least significant *bit* is read first */
                if (vi->rate == 0 || vc->vendor == 0) {
                    /* um... we didn;t get the initial header or comments yet */
                    return (OV_EBADHEADER);
                }

                return (aud1__vorbis_unpack_books_883AB398(ctx, vi, &opb));

            default:
                /* Not a valid vorbis header type */
                return (OV_EBADHEADER);
                break;
            }
        }
    }
    return (OV_EBADHEADER);
}
