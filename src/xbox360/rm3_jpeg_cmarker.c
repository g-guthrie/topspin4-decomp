/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG marker writer (IJG libjpeg jcmarker.c style), Swing_DLL.xex auto_03_882EE91C.
 * emit_byte (0x882EE920) is shared with other callers, so the calls the original
 * left out of line go through its placeholder name. (RM3) */
#include "rm3_jpeg.h"

void ts4_put_byte_882EE920(struct ts4_jpeg_comp *cinfo, int val); /* emit_byte */

enum {
    TS4_JERR_CANT_SUSPEND = 0x18,
    TS4_JERR_NO_HUFF_TABLE = 0x32,
    TS4_JERR_NO_QUANT_TABLE = 0x34
};

/* emit_byte, which the compiler inlines into these callers. */
static void emit_byte(struct ts4_jpeg_comp *cinfo, int val)
{
    struct ts4_jpeg_destination_mgr *dest = cinfo->dest;
    *(dest->next_output_byte)++ = (ts4_joctet)val;
    if (--dest->free_in_buffer == 0) {
        if (!(*dest->empty_output_buffer)(cinfo))
            JPEG_ERREXIT(cinfo, TS4_JERR_CANT_SUSPEND);
    }
}

/* Writes a DQT segment for one quantization table unless already sent; returns
 * 1 when 16-bit precision was needed (Swing_DLL.xex 0x882EE9A8). */
int ts4_jpeg_emit_dqt_882EE9A8(struct ts4_jpeg_comp *cinfo, int index)
{
    struct ts4_jpeg_comp_quant_tbl *qtbl = cinfo->quant_tbl_ptrs[index];
    int prec;
    int i;

    if (qtbl == 0)
        JPEG_ERREXIT1(cinfo, TS4_JERR_NO_QUANT_TABLE, index);

    prec = 0;
    for (i = 0; i < 64; i++) {
        if (qtbl->quantval[i] > 255)
            prec = 1;
    }

    if (!qtbl->sent_table) {
        emit_byte(cinfo, 0xFF);
        emit_byte(cinfo, 0xDB);

        {
            int value = prec ? 64 * 2 + 1 + 2 : 64 + 1 + 2;
            emit_byte(cinfo, (value >> 8) & 0xFF);
            emit_byte(cinfo, value & 0xFF);
        }

        emit_byte(cinfo, index + (prec << 4));

        for (i = 0; i < 64; i++) {
            unsigned int qval = qtbl->quantval[lbl_88025F10[i]];
            if (prec)
                emit_byte(cinfo, (int)(qval >> 8));
            emit_byte(cinfo, (int)(qval & 0xFF));
        }

        qtbl->sent_table = 1;
    }

    return prec;
}

/* Writes a DHT segment for one DC or AC Huffman table unless already sent
 * (Swing_DLL.xex 0x882EED50). */
void ts4_jpeg_emit_dht_882EED50(struct ts4_jpeg_comp *cinfo, int index, int is_ac)
{
    struct ts4_jpeg_comp_huff_tbl *htbl;
    int length, i;

    if (is_ac) {
        htbl = cinfo->ac_huff_tbl_ptrs[index];
        index += 0x10;
    } else {
        htbl = cinfo->dc_huff_tbl_ptrs[index];
    }

    if (htbl == 0)
        JPEG_ERREXIT1(cinfo, TS4_JERR_NO_HUFF_TABLE, index);

    if (!htbl->sent_table) {
        ts4_put_byte_882EE920(cinfo, 0xFF);
        ts4_put_byte_882EE920(cinfo, 0xC4);

        length = 0;
        for (i = 1; i <= 16; i++)
            length += htbl->bits[i];

        {
            int value = length + 2 + 1 + 16;
            emit_byte(cinfo, (value >> 8) & 0xFF);
            emit_byte(cinfo, value & 0xFF);
        }
        emit_byte(cinfo, index);

        for (i = 1; i <= 16; i++)
            emit_byte(cinfo, htbl->bits[i]);

        for (i = 0; i < length; i++)
            emit_byte(cinfo, htbl->huffval[i]);

        htbl->sent_table = 1;
    }
}
