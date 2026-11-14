/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2010             *
 * by the Xiph.Org Foundation http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: code raw packets into framed OggSquish stream and
           decode Ogg streams back into raw packets

 ********************************************************************/
/* Derived from libogg 1.2.x src/framing.c (BSD license); see
   THIRD_PARTY_NOTICES.md. FMOD variant: allocating calls take a context. */
#include "lib2_ogg.h"

extern const ogg_uint32_t lbl_88035B48[256];   /* crc_lookup */
extern const char lbl_8802B710[];              /* "OggS" */
int ts4_if_call_seq_u32_off0_883BAC48(void *ctx, ogg_stream_state *os); /* ogg_stream_clear */
int ts4_if_call_seq_u32_off0_883BADF0(void *ctx, ogg_sync_state *oy);   /* ogg_sync_clear */
/* ogg_sync_wrote (0x883BAF20) is already defined elsewhere as ts4_if_get_u32_off4_883BAF20. */
void lib2_ogg_page_checksum_set_883BACD0(ogg_page *og);
int fn_883BB6E0(ogg_stream_state *os, ogg_packet *op, int adv); /* _packetout (not yet matched; draft in work/lib2_drafts) */

/* Header accessors (separate public functions upstream; inlined here). */
static int ogg_page_version(const ogg_page *og) { return ((int)(og->header[4])); }
static int ogg_page_continued(const ogg_page *og) { return ((int)(og->header[5] & 0x01)); }
static int ogg_page_bos(const ogg_page *og) { return ((int)(og->header[5] & 0x02)); }
static int ogg_page_eos(const ogg_page *og) { return ((int)(og->header[5] & 0x04)); }
static int ogg_page_serialno(const ogg_page *og)
{
    return (og->header[14] | (og->header[15] << 8) | (og->header[16] << 16) | (og->header[17] << 24));
}
static long ogg_page_pageno(const ogg_page *og)
{
    return (og->header[18] | (og->header[19] << 8) | (og->header[20] << 16) | (og->header[21] << 24));
}

/* ogg_stream_check / ogg_sync_check: reject cleared or failed states. */
static int ogg_stream_check(ogg_stream_state *os)
{
    if (!os || !os->body_data) return -1;
    return 0;
}
static int ogg_sync_check(ogg_sync_state *oy)
{
    if (oy->storage < 0) return -1;
    return 0;
}

/* ogg_page_granulepos: 64-bit little-endian granule position at header[6..13]. */
ogg_int64_t lib2_ogg_page_granulepos_883BABB8(const ogg_page *og)
{
    unsigned char *page = og->header;
    ogg_int64_t granulepos = page[13] & (0xff);
    granulepos = (granulepos << 8) | (page[12] & 0xff);
    granulepos = (granulepos << 8) | (page[11] & 0xff);
    granulepos = (granulepos << 8) | (page[10] & 0xff);
    granulepos = (granulepos << 8) | (page[9] & 0xff);
    granulepos = (granulepos << 8) | (page[8] & 0xff);
    granulepos = (granulepos << 8) | (page[7] & 0xff);
    granulepos = (granulepos << 8) | (page[6] & 0xff);
    return (granulepos);
}

/* ogg_page_checksum_set: CRC the header and body (checksum field zeroed). */
void lib2_ogg_page_checksum_set_883BACD0(ogg_page *og)
{
    if (og) {
        ogg_uint32_t crc_reg = 0;
        int i;

        /* safety; needed for API behavior, but not framing code */
        og->header[22] = 0;
        og->header[23] = 0;
        og->header[24] = 0;
        og->header[25] = 0;

        for (i = 0; i < og->header_len; i++)
            crc_reg = (crc_reg << 8) ^ lbl_88035B48[((crc_reg >> 24) & 0xff) ^ og->header[i]];
        for (i = 0; i < og->body_len; i++)
            crc_reg = (crc_reg << 8) ^ lbl_88035B48[((crc_reg >> 24) & 0xff) ^ og->body[i]];

        og->header[22] = (unsigned char)(crc_reg & 0xff);
        og->header[23] = (unsigned char)((crc_reg >> 8) & 0xff);
        og->header[24] = (unsigned char)((crc_reg >> 16) & 0xff);
        og->header[25] = (unsigned char)((crc_reg >> 24) & 0xff);
    }
}

/* ogg_sync_buffer: compact returned bytes and expose at least size bytes. */
char *lib2_ogg_sync_buffer_883BAE48(void *ctx, ogg_sync_state *oy, long size)
{
    if (ogg_sync_check(oy)) return 0;

    /* first, clear out any space that has been previously returned */
    if (oy->returned) {
        oy->fill -= oy->returned;
        if (oy->fill > 0)
            fn_88562DC0(oy->data, oy->data + oy->returned, oy->fill);
        oy->returned = 0;
    }

    if (size > oy->storage - oy->fill) {
        /* We need to extend the internal buffer */
        long newsize = size + oy->fill + 4096; /* an extra page to be nice */
        void *ret;

        if (oy->data)
            ret = fn_8836CCD8(ctx, oy->data, newsize);
        else
            ret = fn_8836CBE8(ctx, newsize);
        oy->data = 0;
        if (!ret) {
            ts4_if_call_seq_u32_off0_883BADF0(ctx, oy);
            return 0;
        }
        oy->data = ret;
        oy->storage = newsize;
    }

    /* expose a segment at least as large as requested at the fill mark */
    return ((char *)oy->data + oy->fill);
}

/* ogg_sync_pageseek: verify a page at the head of the buffer or skip to the next capture. */
long lib2_ogg_sync_pageseek_883BAF50(ogg_sync_state *oy, ogg_page *og)
{
    unsigned char *page = oy->data + oy->returned;
    unsigned char *next;
    long bytes = oy->fill - oy->returned;

    if (ogg_sync_check(oy)) return 0;

    if (oy->headerbytes == 0) {
        int headerbytes, i;
        if (bytes < 27) return (0); /* not enough for a header */

        /* verify capture pattern */
        if (memcmp(page, lbl_8802B710, 4)) goto sync_fail;

        headerbytes = page[26] + 27;
        if (bytes < headerbytes) return (0); /* not enough for header + seg table */

        /* count up body length in the segment table */
        for (i = 0; i < page[26]; i++)
            oy->bodybytes += page[27 + i];
        oy->headerbytes = headerbytes;
    }

    if (oy->bodybytes + oy->headerbytes > bytes) return (0);

    /* The whole test page is buffered.  Verify the checksum */
    {
        /* Grab the checksum bytes, set the header field to zero */
        char chksum[4];
        ogg_page log;

        fn_8857ACB8(chksum, page + 22, 4);
        ts4_memset(page + 22, 0, 4);

        /* set up a temp page struct and recompute the checksum */
        log.header = page;
        log.header_len = oy->headerbytes;
        log.body = page + oy->headerbytes;
        log.body_len = oy->bodybytes;
        lib2_ogg_page_checksum_set_883BACD0(&log);

        /* Compare */
        if (memcmp(chksum, page + 22, 4)) {
            /* replace the computed checksum with the one actually read in */
            fn_8857ACB8(page + 22, chksum, 4);

            /* Bad checksum. Lose sync */
            goto sync_fail;
        }
    }

    /* yes, have a whole page all ready to go */
    {
        unsigned char *page = oy->data + oy->returned;
        long bytes;

        if (og) {
            og->header = page;
            og->header_len = oy->headerbytes;
            og->body = page + oy->headerbytes;
            og->body_len = oy->bodybytes;
        }

        oy->unsynced = 0;
        oy->returned += (bytes = oy->headerbytes + oy->bodybytes);
        oy->headerbytes = 0;
        oy->bodybytes = 0;
        return (bytes);
    }

sync_fail:

    oy->headerbytes = 0;
    oy->bodybytes = 0;

    /* search for possible capture */
    next = fn_88569CF0(page + 1, 'O', bytes - 1);
    if (!next)
        next = oy->data + oy->fill;

    oy->returned = (int)(next - oy->data);
    return ((long)-(next - page));
}

int lib2_ogg_stream_reset_883BB620(ogg_stream_state *os)
{
    if (ogg_stream_check(os)) return -1;

    os->body_fill = 0;
    os->body_returned = 0;

    os->lacing_fill = 0;
    os->lacing_packet = 0;
    os->lacing_returned = 0;

    os->header_fill = 0;

    os->e_o_s = 0;
    os->b_o_s = 0;
    os->pageno = -1;
    os->packetno = 0;
    os->granulepos = 0;

    return (0);
}

/* ogg_stream_reset_serialno: reset and adopt a new serial number. */
int lib2_ogg_stream_reset_serialno_883BB680(ogg_stream_state *os, int serialno)
{
    if (ogg_stream_check(os)) return -1;
    lib2_ogg_stream_reset_883BB620(os);
    os->serialno = serialno;
    return (0);
}

/* ogg_stream_packetout: return and consume the next packet. */
int lib2_ogg_stream_packetout_883BB800(ogg_stream_state *os, ogg_packet *op)
{
    if (ogg_stream_check(os)) return 0;
    return fn_883BB6E0(os, op, 1);
}
