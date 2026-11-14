/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b datastream marker writer, remaining routines (jcmarker.c). */
#include "ex8_jpeg.h"

void ts4_put_byte_882EE920(ex8_jcomp *cinfo, int val); /* emit_byte */
int ts4_jpeg_emit_dqt_882EE9A8(ex8_jcomp *cinfo, int index);
void ts4_jpeg_emit_dht_882EED50(ex8_jcomp *cinfo, int index, int is_ac);

typedef struct ex8_marker_priv {
    ex8_jcmarker pub;                    /* 0x00 */
    void *write_marker_header;           /* 0x14 */
    void *write_marker_byte;             /* 0x18 */
    unsigned int last_restart_interval;  /* 0x1c */
} ex8_marker_priv;

enum {
    EX8_JERR_CANT_SUSPEND = 0x18,
    EX8_JERR_IMAGE_TOO_BIG = 0x29,
    EX8_JTRC_16BIT_TABLES = 0x4b
};

/* emit_byte, which the compiler inlines into the per-component loops. */
static void ex8_emit_byte(ex8_jcomp *cinfo, int val)
{
    ex8_jdest *dest = cinfo->dest;
    *(dest->next_output_byte)++ = (ex8_joctet)val;
    if (--dest->free_in_buffer == 0) {
        if (!(*dest->empty_output_buffer)(cinfo))
            EX8_ERREXIT(cinfo, EX8_JERR_CANT_SUSPEND);
    }
}

/* Writes a start-of-frame header for the given SOFn marker code. */
void ex8_emit_sof_882EF050(ex8_jcomp *cinfo, int code)
{
    int ci;
    ex8_jcinfo *compptr;

    ts4_put_byte_882EE920(cinfo, 0xFF);
    ts4_put_byte_882EE920(cinfo, code);

    {
        int value = 3 * cinfo->num_components + 2 + 5 + 1;
        ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
        ts4_put_byte_882EE920(cinfo, value & 0xFF);
    }

    if ((long)cinfo->image_height > 65535L || (long)cinfo->image_width > 65535L)
        EX8_ERREXIT1(cinfo, EX8_JERR_IMAGE_TOO_BIG, (unsigned int)65535);

    ts4_put_byte_882EE920(cinfo, cinfo->data_precision);
    {
        int value = (int)cinfo->image_height;
        ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
        ts4_put_byte_882EE920(cinfo, value & 0xFF);
    }
    {
        int value = (int)cinfo->image_width;
        ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
        ts4_put_byte_882EE920(cinfo, value & 0xFF);
    }
    ts4_put_byte_882EE920(cinfo, cinfo->num_components);

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        ex8_emit_byte(cinfo, compptr->component_id);
        ex8_emit_byte(cinfo, (compptr->h_samp_factor << 4) + compptr->v_samp_factor);
        ex8_emit_byte(cinfo, compptr->quant_tbl_no);
    }
}

/* Writes a start-of-scan header. */
void ex8_emit_sos_882EF2A8(ex8_jcomp *cinfo)
{
    int i, td, ta;
    ex8_jcinfo *compptr;

    ts4_put_byte_882EE920(cinfo, 0xFF);
    ts4_put_byte_882EE920(cinfo, 0xDA);

    {
        int value = 2 * cinfo->comps_in_scan + 2 + 1 + 3;
        ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
        ts4_put_byte_882EE920(cinfo, value & 0xFF);
    }

    ts4_put_byte_882EE920(cinfo, cinfo->comps_in_scan);

    for (i = 0; i < cinfo->comps_in_scan; i++) {
        compptr = cinfo->cur_comp_info[i];
        ex8_emit_byte(cinfo, compptr->component_id);
        td = compptr->dc_tbl_no;
        ta = compptr->ac_tbl_no;
        if (cinfo->progressive_mode) {
            if (cinfo->Ss == 0) {
                ta = 0;
                if (cinfo->Ah != 0 && !cinfo->arith_code)
                    td = 0;
            } else {
                td = 0;
            }
        }
        ex8_emit_byte(cinfo, (td << 4) + ta);
    }

    ex8_emit_byte(cinfo, cinfo->Ss);
    ex8_emit_byte(cinfo, cinfo->Se);
    ex8_emit_byte(cinfo, (cinfo->Ah << 4) + cinfo->Al);
}

/* Writes the JFIF APP0 header. */
void ex8_emit_jfif_app0_882EF568(ex8_jcomp *cinfo)
{
    ts4_put_byte_882EE920(cinfo, 0xFF);
    ts4_put_byte_882EE920(cinfo, 0xE0);
    {
        int value = 2 + 4 + 1 + 2 + 1 + 2 + 2 + 1 + 1;
        ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
        ts4_put_byte_882EE920(cinfo, value & 0xFF);
    }
    ts4_put_byte_882EE920(cinfo, 0x4A);
    ts4_put_byte_882EE920(cinfo, 0x46);
    ts4_put_byte_882EE920(cinfo, 0x49);
    ts4_put_byte_882EE920(cinfo, 0x46);
    ts4_put_byte_882EE920(cinfo, 0);
    ts4_put_byte_882EE920(cinfo, cinfo->JFIF_major_version);
    ts4_put_byte_882EE920(cinfo, cinfo->JFIF_minor_version);
    ts4_put_byte_882EE920(cinfo, cinfo->density_unit);
    {
        int value = (int)cinfo->X_density;
        ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
        ts4_put_byte_882EE920(cinfo, value & 0xFF);
    }
    {
        int value = (int)cinfo->Y_density;
        ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
        ts4_put_byte_882EE920(cinfo, value & 0xFF);
    }
    ts4_put_byte_882EE920(cinfo, 0);
    ts4_put_byte_882EE920(cinfo, 0);
}

/* Writes the Adobe APP14 header carrying the color transform code. */
void ex8_emit_adobe_app14_882EF680(ex8_jcomp *cinfo)
{
    ts4_put_byte_882EE920(cinfo, 0xFF);
    ts4_put_byte_882EE920(cinfo, 0xEE);
    {
        int value = 2 + 5 + 2 + 2 + 2 + 1;
        ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
        ts4_put_byte_882EE920(cinfo, value & 0xFF);
    }
    ts4_put_byte_882EE920(cinfo, 0x41);
    ts4_put_byte_882EE920(cinfo, 0x64);
    ts4_put_byte_882EE920(cinfo, 0x6F);
    ts4_put_byte_882EE920(cinfo, 0x62);
    ts4_put_byte_882EE920(cinfo, 0x65);
    {
        int value = 100;
        ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
        ts4_put_byte_882EE920(cinfo, value & 0xFF);
    }
    {
        int value = 0;
        ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
        ts4_put_byte_882EE920(cinfo, value & 0xFF);
    }
    {
        int value = 0;
        ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
        ts4_put_byte_882EE920(cinfo, value & 0xFF);
    }
    switch (cinfo->jpeg_color_space) {
    case 3:
        ts4_put_byte_882EE920(cinfo, 1);
        break;
    case 5:
        ts4_put_byte_882EE920(cinfo, 2);
        break;
    default:
        ts4_put_byte_882EE920(cinfo, 0);
        break;
    }
}

/* Writes the DQT segments and the SOFn frame header. */
void ex8_write_frame_header_882EF888(ex8_jcomp *cinfo)
{
    int ci, prec;
    int is_baseline;
    ex8_jcinfo *compptr;

    prec = 0;
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++)
        prec += ts4_jpeg_emit_dqt_882EE9A8(cinfo, compptr->quant_tbl_no);

    if (cinfo->arith_code || cinfo->progressive_mode || cinfo->data_precision != 8) {
        is_baseline = 0;
    } else {
        is_baseline = 1;
        for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
            if (compptr->dc_tbl_no > 1 || compptr->ac_tbl_no > 1)
                is_baseline = 0;
        }
        if (prec && is_baseline) {
            is_baseline = 0;
            cinfo->err->msg_code = EX8_JTRC_16BIT_TABLES;
            (*cinfo->err->emit_message)(cinfo, 0);
        }
    }

    if (cinfo->arith_code) {
        ex8_emit_sof_882EF050(cinfo, 0xC9);
    } else {
        if (cinfo->progressive_mode)
            ex8_emit_sof_882EF050(cinfo, 0xC2);
        else if (is_baseline)
            ex8_emit_sof_882EF050(cinfo, 0xC0);
        else
            ex8_emit_sof_882EF050(cinfo, 0xC1);
    }
}

/* Writes the Huffman tables, a DRI if needed, and the SOS header for a scan. */
void ex8_write_scan_header_882EF9D8(ex8_jcomp *cinfo)
{
    ex8_marker_priv *marker = (ex8_marker_priv *)cinfo->marker;
    int i;
    ex8_jcinfo *compptr;

    if (!cinfo->arith_code) {
        for (i = 0; i < cinfo->comps_in_scan; i++) {
            compptr = cinfo->cur_comp_info[i];
            if (cinfo->progressive_mode) {
                if (cinfo->Ss == 0) {
                    if (cinfo->Ah == 0)
                        ts4_jpeg_emit_dht_882EED50(cinfo, compptr->dc_tbl_no, 0);
                } else {
                    ts4_jpeg_emit_dht_882EED50(cinfo, compptr->ac_tbl_no, 1);
                }
            } else {
                ts4_jpeg_emit_dht_882EED50(cinfo, compptr->dc_tbl_no, 0);
                ts4_jpeg_emit_dht_882EED50(cinfo, compptr->ac_tbl_no, 1);
            }
        }
    }

    if (cinfo->restart_interval != marker->last_restart_interval) {
        ts4_put_byte_882EE920(cinfo, 0xFF);
        ts4_put_byte_882EE920(cinfo, 0xDD);
        ts4_put_byte_882EE920(cinfo, 0);
        ts4_put_byte_882EE920(cinfo, 4);
        {
            int value = (int)cinfo->restart_interval;
            ts4_put_byte_882EE920(cinfo, (value >> 8) & 0xFF);
            ts4_put_byte_882EE920(cinfo, value & 0xFF);
        }
        marker->last_restart_interval = cinfo->restart_interval;
    }

    ex8_emit_sos_882EF2A8(cinfo);
}

/* Writes an abbreviated table-only datastream (SOI, tables, EOI). */
void ex8_write_tables_only_882EFB30(ex8_jcomp *cinfo)
{
    int i;

    ts4_put_byte_882EE920(cinfo, 0xFF);
    ts4_put_byte_882EE920(cinfo, 0xD8);

    for (i = 0; i < 4; i++) {
        if (cinfo->quant_tbl_ptrs[i] != 0)
            (void)ts4_jpeg_emit_dqt_882EE9A8(cinfo, i);
    }

    if (!cinfo->arith_code) {
        for (i = 0; i < 4; i++) {
            if (cinfo->dc_huff_tbl_ptrs[i] != 0)
                ts4_jpeg_emit_dht_882EED50(cinfo, i, 0);
            if (cinfo->ac_huff_tbl_ptrs[i] != 0)
                ts4_jpeg_emit_dht_882EED50(cinfo, i, 1);
        }
    }

    ex8_emit_byte(cinfo, 0xFF);
    ex8_emit_byte(cinfo, 0xD9);
}
