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

 function: stdio-based convenience library for opening/seeking/decoding

 ********************************************************************/
/* Derived from libvorbis 1.2.3 lib/vorbisfile.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex: FMOD context
   argument, CHUNKSIZE 8500, float bittrack/samptrack, and OV_EMEMORY (-139)
   propagated from the allocator. */
#include "aud1_vorbis.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifdef _MSC_VER
#define AUD1_NOINLINE __declspec(noinline)
#else
#define AUD1_NOINLINE
#endif

#define CHUNKSIZE 8500
#define SEEK_SET 0
#define SEEK_CUR 1

#define NOTOPEN 0
#define PARTOPEN 1
#define OPENED 2
#define STREAMSET 3
#define INITSET 4

typedef struct {
    lib2_size_t (*read_func)(void *ptr, lib2_size_t size, lib2_size_t nmemb, void *datasource);
    int (*seek_func)(void *datasource, ogg_int64_t offset, int whence);
    int (*close_func)(void *datasource);
    long (*tell_func)(void *datasource);
} ov_callbacks;

typedef struct OggVorbis_File {
    void *datasource;
    int seekable;
    ogg_int64_t offset;
    ogg_int64_t end;
    ogg_sync_state oy;

    int links;
    ogg_int64_t *offsets;
    ogg_int64_t *dataoffsets;
    long *serialnos;
    ogg_int64_t *pcmlengths;
    vorbis_info *vi;
    vorbis_comment *vc;

    ogg_int64_t pcm_offset;
    int ready_state;
    long current_serialno;
    int current_link;

    float bittrack;
    float samptrack;

    ogg_stream_state os;
    vorbis_dsp_state vd;
    vorbis_block vb;

    ov_callbacks callbacks;
} OggVorbis_File;

int *ts4_if_call_seq_fn_8856CD88_88567ED8(void); /* &errno */
char *lib2_ogg_sync_buffer_883BAE48(void *ctx, ogg_sync_state *oy, long size);
int ts4_if_get_u32_off4_883BAF20(ogg_sync_state *oy, long bytes); /* ogg_sync_wrote */
long lib2_ogg_sync_pageseek_883BAF50(ogg_sync_state *oy, ogg_page *og);
int ts4_if_get_u32_off4_883BB5E8(ogg_sync_state *oy);            /* ogg_sync_reset */
int ts4_read_le32_at_0xE_883BAC18(const ogg_page *og);           /* ogg_page_serialno */
ogg_int64_t lib2_ogg_page_granulepos_883BABB8(const ogg_page *og);
int ts4_if_call_seq_u32_off0_883BAC48(void *ctx, ogg_stream_state *os); /* ogg_stream_clear */
int ts4_if_call_seq_u32_off0_883BADF0(void *ctx, ogg_sync_state *oy);   /* ogg_sync_clear */
int aud1_vorbis_synthesis_init_883BC668(void *ctx, vorbis_dsp_state *v, vorbis_info *vi);
int ts4_call_seq_ts4_memset_883BBD80(void *ctx, vorbis_dsp_state *v, vorbis_block *vb); /* vorbis_block_init */
int ts4_if_call_seq_fn_883BBE98_883BBF50(void *ctx, vorbis_block *vb);  /* vorbis_block_clear */
void fn_883BC3B8(void *ctx, vorbis_dsp_state *v); /* vorbis_dsp_clear (draft) */
void aud1_vorbis_info_clear_883AAE58(void *ctx, vorbis_info *vi);
void aud1_vorbis_comment_clear_883AAD18(void *ctx, vorbis_comment *vc);


/* _get_data: pull another CHUNKSIZE bytes from the data source into oy. */
AUD1_NOINLINE long aud1__get_data_883A8020(void *ctx, OggVorbis_File *vf)
{
    *ts4_if_call_seq_fn_8856CD88_88567ED8() = 0;
    if (!(vf->callbacks.read_func)) return (-1);
    if (vf->datasource) {
        char *buffer = lib2_ogg_sync_buffer_883BAE48(ctx, &vf->oy, CHUNKSIZE);
        long bytes;
        if (!buffer) return OV_EMEMORY;
        bytes = (vf->callbacks.read_func)(buffer, 1, CHUNKSIZE, vf->datasource);
        if (bytes > 0) ts4_if_get_u32_off4_883BAF20(&vf->oy, bytes);
        if (bytes == 0 && *ts4_if_call_seq_fn_8856CD88_88567ED8()) return (-1);
        return (bytes);
    } else
        return (0);
}

/* _seek_helper: reposition the data source and reset the sync layer. */
int aud1__seek_helper_883A80F0(OggVorbis_File *vf, ogg_int64_t offset)
{
    if (vf->datasource) {
        if (!(vf->callbacks.seek_func) ||
            (vf->callbacks.seek_func)(vf->datasource, offset, SEEK_SET) == -1)
            return OV_EREAD;
        vf->offset = offset;
        ts4_if_get_u32_off4_883BB5E8(&vf->oy);
    } else {
        /* shouldn't happen unless someone writes a broken callback */
        return OV_EFAULT;
    }
    return 0;
}

/* _get_next_page: find the next page, reading at most boundary bytes. */
AUD1_NOINLINE ogg_int64_t aud1__get_next_page_883A8170(void *ctx, OggVorbis_File *vf, ogg_page *og,
                                          ogg_int64_t boundary)
{
    if (boundary > 0) boundary += vf->offset;
    while (1) {
        long more;

        if (boundary > 0 && vf->offset >= boundary) return (OV_FALSE);
        more = lib2_ogg_sync_pageseek_883BAF50(&vf->oy, og);

        if (more < 0) {
            /* skipped n bytes */
            vf->offset -= more;
        } else {
            if (more == 0) {
                /* send more paramedics */
                if (!boundary) return (OV_FALSE);
                {
                    long ret = aud1__get_data_883A8020(ctx, vf);
                    if (ret == 0) return (OV_EOF);
                    if (ret == OV_EMEMORY) return OV_EMEMORY;
                    if (ret < 0) return (OV_EREAD);
                }
            } else {
                /* got a page.  Return the offset at the page beginning,
                   advance the internal offset past the page end */
                ogg_int64_t ret = vf->offset;
                vf->offset += more;
                return (ret);
            }
        }
    }
}

/* _get_prev_page: find the last page beginning before the current offset. */
ogg_int64_t aud1__get_prev_page_883A8250(void *ctx, OggVorbis_File *vf, ogg_page *og)
{
    ogg_int64_t begin = vf->offset;
    ogg_int64_t end = begin;
    ogg_int64_t ret;
    ogg_int64_t offset = -1;

    if (begin == 0) return OV_EREAD;

    while (offset == -1) {
        begin -= CHUNKSIZE;
        if (begin < 0) begin = 0;

        ret = aud1__seek_helper_883A80F0(vf, begin);
        if (ret) return (ret);

        while (vf->offset < end) {
            ts4_memset(og, 0, sizeof(*og));
            ret = aud1__get_next_page_883A8170(ctx, vf, og, end - vf->offset);
            if (ret == OV_EREAD) return (OV_EREAD);
            if (ret == OV_EMEMORY) return OV_EMEMORY;
            if (ret < 0) {
                break;
            } else {
                offset = ret;
            }
        }
    }

    /* In a fully compliant, non-multiplexed stream, we'll still be
       holding the last page.  In multiplexed (or noncompliant streams),
       we will probably have to re-read the last page we saw */
    if (og->header_len == 0) {
        ret = aud1__seek_helper_883A80F0(vf, offset);
        if (ret) return (ret);

        ret = aud1__get_next_page_883A8170(ctx, vf, og, CHUNKSIZE);
        if (ret < 0)
            /* this shouldn't be possible */
            return (OV_EFAULT);
    }

    return (offset);
}

int fn_883A83B8(ogg_page *og, long *serialno_list, int n); /* _lookup_page_serialno (CTR loop; see work/aud1_drafts) */

extern const float lbl_88001A20;

int ts4_get_u32_off0_883BAB98(const ogg_page *og); /* ogg_page_bos */
int fn_883BB170(void *ctx, ogg_stream_state *os, ogg_page *og); /* ogg_stream_pagein */
int lib2_ogg_stream_packetout_883BB800(ogg_stream_state *os, ogg_packet *op);
long aud1_vorbis_packet_blocksize_883BBCB8(vorbis_info *vi, ogg_packet *op);

int aud1_vorbis_info_init_883AADF0(void *ctx, vorbis_info *vi);
void ts4_tailcall_ts4_memset_883AAD08(vorbis_comment *vc); /* vorbis_comment_init */
int lib2_ogg_stream_reset_serialno_883BB680(ogg_stream_state *os, int serialno);
int aud1_vorbis_synthesis_idheader_883AB768(ogg_packet *op);
int aud1_vorbis_synthesis_headerin_883AB848(void *ctx, vorbis_info *vi, vorbis_comment *vc,
                                            ogg_packet *op);

/* add a serialno to the list; FMOD returns OV_EMEMORY if the list
   cannot grow */
static int _add_serialno(void *ctx, ogg_page *og, long **serialno_list, int *n)
{
    long s = ts4_read_le32_at_0xE_883BAC18(og);
    (*n)++;

    if (*serialno_list) {
        *serialno_list = fn_8836CCD8(ctx, *serialno_list, sizeof(**serialno_list) * (*n));
    } else {
        *serialno_list = fn_8836CBE8(ctx, sizeof(**serialno_list));
    }
    if (!*serialno_list) return OV_EMEMORY;

    (*serialno_list)[(*n) - 1] = s;
    return 0;
}

/* _fetch_headers: read the three Vorbis headers of the current link. */
int aud1__fetch_headers_883A85D0(void *ctx, OggVorbis_File *vf, vorbis_info *vi,
                                 vorbis_comment *vc, long **serialno_list, int *serialno_n,
                                 ogg_page *og_ptr)
{
    ogg_page og;
    ogg_packet op;
    int i, ret;
    int allbos = 0;

    if (!og_ptr) {
        ogg_int64_t llret = aud1__get_next_page_883A8170(ctx, vf, &og, CHUNKSIZE);
        if (llret == OV_EREAD) return (OV_EREAD);
        if (llret == OV_EMEMORY) return OV_EMEMORY;
        if (llret < 0) return (OV_ENOTVORBIS);
        og_ptr = &og;
    }

    if (aud1_vorbis_info_init_883AADF0(ctx, vi)) return OV_EMEMORY;
    ts4_tailcall_ts4_memset_883AAD08(vc);
    vf->ready_state = OPENED;

    /* extract the serialnos of all BOS pages + the first set of vorbis
       headers we see in the link */

    while (ts4_get_u32_off0_883BAB98(og_ptr)) {
        if (serialno_list) {
            if (fn_883A83B8(og_ptr, *serialno_list, *serialno_n)) {
                /* a dupe serialnumber in an initial header packet set == invalid stream */
                if (*serialno_list) fn_8836CD70(ctx, *serialno_list);
                *serialno_list = 0;
                *serialno_n = 0;
                ret = OV_EBADHEADER;
                goto bail_header;
            }

            if (_add_serialno(ctx, og_ptr, serialno_list, serialno_n)) return OV_EMEMORY;
        }

        if (vf->ready_state < STREAMSET) {
            /* we don't have a vorbis stream in this link yet, so begin
               prospective stream setup. We need a stream to get packets */
            lib2_ogg_stream_reset_serialno_883BB680(&vf->os, ts4_read_le32_at_0xE_883BAC18(og_ptr));
            fn_883BB170(ctx, &vf->os, og_ptr);

            if (lib2_ogg_stream_packetout_883BB800(&vf->os, &op) > 0 &&
                aud1_vorbis_synthesis_idheader_883AB768(&op)) {
                /* vorbis header; continue setup */
                vf->ready_state = STREAMSET;
                if ((ret = aud1_vorbis_synthesis_headerin_883AB848(ctx, vi, vc, &op))) {
                    ret = OV_EBADHEADER;
                    goto bail_header;
                }
            }
        }

        /* get next page */
        {
            ogg_int64_t llret = aud1__get_next_page_883A8170(ctx, vf, og_ptr, CHUNKSIZE);
            if (llret == OV_EREAD) {
                ret = OV_EREAD;
                goto bail_header;
            }
            if (llret == OV_EMEMORY) {
                ret = OV_EMEMORY;
                goto bail_header;
            }
            if (llret < 0) {
                ret = OV_ENOTVORBIS;
                goto bail_header;
            }

            /* if this page also belongs to our vorbis stream, submit it and break */
            if (vf->ready_state == STREAMSET &&
                vf->os.serialno == ts4_read_le32_at_0xE_883BAC18(og_ptr)) {
                fn_883BB170(ctx, &vf->os, og_ptr);
                break;
            }
        }
    }

    if (vf->ready_state != STREAMSET) {
        ret = OV_ENOTVORBIS;
        goto bail_header;
    }

    while (1) {

        i = 0;
        while (i < 2) { /* get a page loop */

            while (i < 2) { /* get a packet loop */

                int result = lib2_ogg_stream_packetout_883BB800(&vf->os, &op);
                if (result == 0) break;
                if (result == -1) {
                    ret = OV_EBADHEADER;
                    goto bail_header;
                }

                if ((ret = aud1_vorbis_synthesis_headerin_883AB848(ctx, vi, vc, &op)))
                    goto bail_header;

                i++;
            }

            while (i < 2) {
                if (aud1__get_next_page_883A8170(ctx, vf, og_ptr, CHUNKSIZE) < 0) {
                    ret = OV_EBADHEADER;
                    goto bail_header;
                }

                /* if this page belongs to the correct stream, go parse it */
                if (vf->os.serialno == ts4_read_le32_at_0xE_883BAC18(og_ptr)) {
                    fn_883BB170(ctx, &vf->os, og_ptr);
                    break;
                }

                /* if we never see the final vorbis headers before the link
                   ends, abort */
                if (ts4_get_u32_off0_883BAB98(og_ptr)) {
                    if (allbos) {
                        ret = OV_EBADHEADER;
                        goto bail_header;
                    } else
                        allbos = 1;
                }

                /* otherwise, keep looking */
            }
        }

        return 0;
    }

bail_header:
    aud1_vorbis_info_clear_883AAE58(ctx, vi);
    aud1_vorbis_comment_clear_883AAD18(ctx, vc);
    vf->ready_state = OPENED;

    return ret;
}

/* _initial_pcmoffset: PCM offset of the first audio page of this link. */
ogg_int64_t aud1__initial_pcmoffset_883A8920(void *ctx, OggVorbis_File *vf, vorbis_info *vi)
{
    ogg_page og;
    ogg_int64_t accumulated = 0;
    long lastblock = -1;
    int result;
    int serialno = vf->os.serialno;

    while (1) {
        ogg_packet op;
        if (aud1__get_next_page_883A8170(ctx, vf, &og, -1) < 0)
            break; /* should not be possible unless the file is truncated/mangled */

        if (ts4_get_u32_off0_883BAB98(&og)) break;
        if (ts4_read_le32_at_0xE_883BAC18(&og) != serialno) continue;

        /* count blocksizes of all frames in the page */
        fn_883BB170(ctx, &vf->os, &og);
        while ((result = lib2_ogg_stream_packetout_883BB800(&vf->os, &op))) {
            if (result > 0) { /* ignore holes */
                long thisblock = aud1_vorbis_packet_blocksize_883BBCB8(vi, &op);
                if (lastblock != -1) accumulated += (lastblock + thisblock) >> 2;
                lastblock = thisblock;
            }
        }

        if (lib2_ogg_page_granulepos_883BABB8(&og) != -1) {
            /* pcm offset of last packet on the first audio page */
            accumulated = lib2_ogg_page_granulepos_883BABB8(&og) - accumulated;
            break;
        }
    }

    /* less than zero?  This is a stream with samples trimmed off
       the beginning, a normal occurrence; set the offset to zero */
    if (accumulated < 0) accumulated = 0;

    return accumulated;
}


/* _make_decode_ready: set up the synthesis state for the current link. */
int aud1__make_decode_ready_883A8F28(void *ctx, OggVorbis_File *vf)
{
    int ret;
    if (vf->ready_state > STREAMSET) return 0;
    if (vf->ready_state < STREAMSET) return OV_EFAULT;
    if (vf->seekable) {
        ret = aud1_vorbis_synthesis_init_883BC668(ctx, &vf->vd, vf->vi + vf->current_link);
        if (ret == OV_EMEMORY) return OV_EMEMORY;
        if (ret) return OV_EBADLINK;
    } else {
        ret = aud1_vorbis_synthesis_init_883BC668(ctx, &vf->vd, vf->vi);
        if (ret == OV_EMEMORY) return OV_EMEMORY;
        if (ret) return OV_EBADLINK;
    }
    if (ts4_call_seq_ts4_memset_883BBD80(ctx, &vf->vd, &vf->vb)) return OV_EMEMORY;
    vf->ready_state = INITSET;
    vf->bittrack = lbl_88001A20; /* 0.f */
    vf->samptrack = vf->bittrack;
    return 0;
}

/* ov_clear: release everything held by vf and zero it. */
int aud1_ov_clear_883A9440(void *ctx, OggVorbis_File *vf)
{
    if (vf) {
        ts4_if_call_seq_fn_883BBE98_883BBF50(ctx, &vf->vb);
        fn_883BC3B8(ctx, &vf->vd);
        ts4_if_call_seq_u32_off0_883BAC48(ctx, &vf->os);

        if (vf->vi && vf->links) {
            int i;
            for (i = 0; i < vf->links; i++) {
                aud1_vorbis_info_clear_883AAE58(ctx, vf->vi + i);
                aud1_vorbis_comment_clear_883AAD18(ctx, vf->vc + i);
            }
            fn_8836CD70(ctx, vf->vi);
            fn_8836CD70(ctx, vf->vc);
        }
        if (vf->dataoffsets) fn_8836CD70(ctx, vf->dataoffsets);
        if (vf->pcmlengths) fn_8836CD70(ctx, vf->pcmlengths);
        if (vf->serialnos) fn_8836CD70(ctx, vf->serialnos);
        if (vf->offsets) fn_8836CD70(ctx, vf->offsets);
        ts4_if_call_seq_u32_off0_883BADF0(ctx, &vf->oy);
        if (vf->datasource && vf->callbacks.close_func)
            (vf->callbacks.close_func)(vf->datasource);
        ts4_memset(vf, 0, sizeof(*vf));
    }
    return (0);
}

/* ov_pcm_total: PCM length of link i, or of the whole stream when i < 0. */
ogg_int64_t aud1_ov_pcm_total_883A9598(OggVorbis_File *vf, int i)
{
    if (vf->ready_state < OPENED) return (OV_EINVAL);
    if (!vf->seekable || i >= vf->links) return (OV_EINVAL);
    if (i < 0) {
        ogg_int64_t acc = 0;
        int i;
        for (i = 0; i < vf->links; i++)
            acc += aud1_ov_pcm_total_883A9598(vf, i);
        return (acc);
    } else {
        return (vf->pcmlengths[i * 2 + 1]);
    }
}

void ts4_if_call_seq_u32_off4_883BADB0(ogg_sync_state *oy);                        /* ogg_sync_init */
void ts4_if_call_seq_ts4_memset_883BB920(void *ctx, ogg_stream_state *os, int serialno); /* ogg_stream_init */
void *fn_8857ACB8(void *dst, const void *src, lib2_size_t n);                        /* memcpy */

/* _ov_open1: partial open; reads the first link's headers. */
int aud1__ov_open1_883AA9E0(void *ctx, void *f, OggVorbis_File *vf, char *initial, long ibytes,
                            ov_callbacks callbacks)
{
    int offsettest = ((f && callbacks.seek_func) ? callbacks.seek_func(f, 0, SEEK_CUR) : -1);
    long *serialno_list = NULL;
    int serialno_list_size = 0;
    int ret;

    ts4_memset(vf, 0, sizeof(*vf));
    vf->datasource = f;
    vf->callbacks = callbacks;

    /* init the framing state */
    ts4_if_call_seq_u32_off4_883BADB0(&vf->oy);

    /* perhaps some data was previously read into a buffer for testing
       against other stream types.  Allow initialization from this
       previously read data (especially as we may be reading from a
       non-seekable stream) */
    if (initial) {
        char *buffer = lib2_ogg_sync_buffer_883BAE48(ctx, &vf->oy, ibytes);
        if (!buffer) return OV_EMEMORY;
        fn_8857ACB8(buffer, initial, ibytes);
        ts4_if_get_u32_off4_883BAF20(&vf->oy, ibytes);
    }

    /* can we seek? Stevens suggests the seek test was portable */
    if (offsettest != -1) vf->seekable = 1;

    /* No seeking yet; Set up a 'single' (current) logical bitstream
       entry for partial open */
    vf->links = 1;
    vf->vi = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, vf->links, sizeof(*vf->vi));
    if (!vf->vi) return OV_EMEMORY;
    vf->vc = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, vf->links, sizeof(*vf->vc));
    if (!vf->vc) return OV_EMEMORY;
    ts4_if_call_seq_ts4_memset_883BB920(ctx, &vf->os, -1); /* fill in the serialno later */

    /* Fetch all BOS pages, store the vorbis header and all seen serial
       numbers, load subsequent vorbis setup headers */
    if ((ret = aud1__fetch_headers_883A85D0(ctx, vf, vf->vi, vf->vc, &serialno_list,
                                            &serialno_list_size, NULL)) < 0) {
        vf->datasource = NULL;
        aud1_ov_clear_883A9440(ctx, vf);
    } else {
        /* serial number list for first link needs to be held somewhere
           for second stage of seekable stream open; this saves having to
           seek/reread first link's serialnumber data then. */
        vf->serialnos = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, serialno_list_size + 2,
                                                                  sizeof(*vf->serialnos));
        if (!vf->serialnos) return OV_EMEMORY;
        vf->serialnos[0] = vf->current_serialno;
        vf->serialnos[1] = serialno_list_size;
        fn_8857ACB8(vf->serialnos + 2, serialno_list, serialno_list_size * sizeof(*vf->serialnos));

        vf->offsets = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(*vf->offsets));
        if (!vf->offsets) return OV_EMEMORY;
        vf->dataoffsets = ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ctx, 1, sizeof(*vf->dataoffsets));
        if (!vf->dataoffsets) return OV_EMEMORY;
        vf->offsets[0] = 0;
        vf->dataoffsets[0] = vf->offset;
        vf->current_serialno = vf->os.serialno;

        vf->ready_state = PARTOPEN;
    }
    if (serialno_list) fn_8836CD70(ctx, serialno_list);
    return (ret);
}
