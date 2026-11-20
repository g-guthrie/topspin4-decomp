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

 function: basic codebook pack/unpack/code/decode operations

 ********************************************************************/
/* Derived from libvorbis 1.2.3 lib/codebook.c (BSD license); see
   THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex: FMOD context
   argument and OV_EMEMORY on allocation failure in the unpacker; encoder
   functions absent. */
#include "aud1_vorbis.h"

void *_alloca(lib2_size_t n);

#ifdef _MSC_VER
#define AUD1_NOINLINE __declspec(noinline)
#else
#define AUD1_NOINLINE
#endif

int lib2__book_maptype1_quantvals_883BD5D0(const static_codebook *b);
void ts4_if_call_seq_u32_off24_883BD9D8(void *ctx, static_codebook *b); /* vorbis_staticbook_clear */

/* vorbis_staticbook_unpack: read one codebook header into s. */
int aud1_vorbis_staticbook_unpack_883BE2A8(void *ctx, oggpack_buffer *opb, static_codebook *s)
{
    long i, j;
    int ret = -1;
    ts4_memset(s, 0, sizeof(*s));
    s->allocedp = 1;

    /* make sure alignment is correct */
    if (lib2_oggpack_read_883BD268(opb, 24) != 0x564342) goto _eofout;

    /* first the basic parameters */
    s->dim = lib2_oggpack_read_883BD268(opb, 16);
    s->entries = lib2_oggpack_read_883BD268(opb, 24);
    if (s->entries == -1) goto _eofout;

    if (ts4_bit_length_883BD378(s->dim) + ts4_bit_length_883BD378(s->entries) > 24) goto _eofout;

    /* codeword ordering.... length ordered or unordered? */
    switch ((int)lib2_oggpack_read_883BD268(opb, 1)) {
    case 0:
        /* unordered */
        s->lengthlist = fn_8836CBE8(ctx, sizeof(*s->lengthlist) * s->entries);
        if (!s->lengthlist) { ret = OV_EMEMORY; goto _errout; }

        /* allocated but unused entries? */
        if (lib2_oggpack_read_883BD268(opb, 1)) {
            /* yes, unused entries */
            for (i = 0; i < s->entries; i++) {
                if (lib2_oggpack_read_883BD268(opb, 1)) {
                    long num = lib2_oggpack_read_883BD268(opb, 5);
                    if (num == -1) goto _eofout;
                    s->lengthlist[i] = num + 1;
                } else
                    s->lengthlist[i] = 0;
            }
        } else {
            /* all entries used; no tagging */
            for (i = 0; i < s->entries; i++) {
                long num = lib2_oggpack_read_883BD268(opb, 5);
                if (num == -1) goto _eofout;
                s->lengthlist[i] = num + 1;
            }
        }
        break;
    case 1:
        /* ordered */
        {
            long length = lib2_oggpack_read_883BD268(opb, 5) + 1;
            s->lengthlist = fn_8836CBE8(ctx, sizeof(*s->lengthlist) * s->entries);
            if (!s->lengthlist) { ret = OV_EMEMORY; goto _errout; }

            for (i = 0; i < s->entries;) {
                long num = lib2_oggpack_read_883BD268(opb, ts4_bit_length_883BD378(s->entries - i));
                if (num == -1) goto _eofout;
                for (j = 0; j < num && i < s->entries; j++, i++)
                    s->lengthlist[i] = length;
                length++;
            }
        }
        break;
    default:
        /* EOF */
        return (-1);
    }

    /* Do we have a mapping to unpack? */
    switch ((s->maptype = lib2_oggpack_read_883BD268(opb, 4))) {
    case 0:
        /* no mapping */
        break;
    case 1:
    case 2:
        /* implicitly populated value mapping */
        /* explicitly populated value mapping */
        s->q_min = lib2_oggpack_read_883BD268(opb, 32);
        s->q_delta = lib2_oggpack_read_883BD268(opb, 32);
        s->q_quant = lib2_oggpack_read_883BD268(opb, 4) + 1;
        s->q_sequencep = lib2_oggpack_read_883BD268(opb, 1);
        if (s->q_sequencep == -1) goto _eofout;

        {
            int quantvals = 0;
            switch (s->maptype) {
            case 1:
                quantvals = (s->dim == 0 ? 0 : lib2__book_maptype1_quantvals_883BD5D0(s));
                break;
            case 2:
                quantvals = s->entries * s->dim;
                break;
            }

            /* quantized values */
            s->quantlist = fn_8836CBE8(ctx, sizeof(*s->quantlist) * quantvals);
            if (!s->quantlist) { ret = OV_EMEMORY; goto _errout; }
            for (i = 0; i < quantvals; i++)
                s->quantlist[i] = lib2_oggpack_read_883BD268(opb, s->q_quant);

            if (quantvals && s->quantlist[quantvals - 1] == -1) goto _eofout;
        }
        break;
    default:
        goto _errout;
    }

    /* all set */
    return (0);

_errout:
_eofout:
    ts4_if_call_seq_u32_off24_883BD9D8(ctx, s);
    return (ret);
}

static ogg_uint32_t bitreverse(ogg_uint32_t x)
{
    x = ((x >> 16) & 0x0000ffff) | ((x << 16) & 0xffff0000);
    x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
    return ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
}

/* decode_packed_entry_number: table lookup, then bisect the sorted codewords. */
AUD1_NOINLINE long aud1_decode_packed_entry_number_883BE648(codebook *book, oggpack_buffer *b)
{
    int read = book->dec_maxlength;
    long lo, hi;
    long lok = lib2_oggpack_look_883BD168(b, book->dec_firsttablen);

    if (lok >= 0) {
        long entry = book->dec_firsttable[lok];
        if (entry & 0x80000000UL) {
            lo = (entry >> 15) & 0x7fff;
            hi = book->used_entries - (entry & 0x7fff);
        } else {
            lib2_oggpack_adv_883BD230(b, book->dec_codelengths[entry - 1]);
            return (entry - 1);
        }
    } else {
        lo = 0;
        hi = book->used_entries;
    }

    lok = lib2_oggpack_look_883BD168(b, read);

    while (lok < 0 && read > 1)
        lok = lib2_oggpack_look_883BD168(b, --read);
    if (lok < 0) return -1;

    /* bisect search for the codeword in the ordered list */
    {
        ogg_uint32_t testword = bitreverse((ogg_uint32_t)lok);

        while (hi - lo > 1) {
            long p = (hi - lo) >> 1;
            long test = book->codelist[lo + p] > testword;
            lo += p & (test - 1);
            hi -= p & (-test);
        }

        if (book->dec_codelengths[lo] <= read) {
            lib2_oggpack_adv_883BD230(b, book->dec_codelengths[lo]);
            return (lo);
        }
    }

    lib2_oggpack_adv_883BD230(b, read);

    return (-1);
}

/* vorbis_book_decodev_add: sequential additive vector decode. */
long aud1_vorbis_book_decodev_add_883BEA60(codebook *book, float *a, oggpack_buffer *b, int n)
{
    if (book->used_entries > 0) {
        int i, j, entry;
        float *t;

        if (book->dim > 8) {
            for (i = 0; i < n;) {
                entry = aud1_decode_packed_entry_number_883BE648(book, b);
                if (entry == -1) return (-1);
                t = book->valuelist + entry * book->dim;
                for (j = 0; j < book->dim;)
                    a[i++] += t[j++];
            }
        } else {
            for (i = 0; i < n;) {
                entry = aud1_decode_packed_entry_number_883BE648(book, b);
                if (entry == -1) return (-1);
                t = book->valuelist + entry * book->dim;
                j = 0;
                switch ((int)book->dim) {
                case 8:
                    a[i++] += t[j++];
                case 7:
                    a[i++] += t[j++];
                case 6:
                    a[i++] += t[j++];
                case 5:
                    a[i++] += t[j++];
                case 4:
                    a[i++] += t[j++];
                case 3:
                    a[i++] += t[j++];
                case 2:
                    a[i++] += t[j++];
                case 1:
                    a[i++] += t[j++];
                case 0:
                    break;
                }
            }
        }
    }
    return (0);
}

