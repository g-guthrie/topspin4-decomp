/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG marker reader (IJG libjpeg jdmarker.c style), Swing_DLL.xex auto_03_882E3224.
 * Behaviour mirrors the Independent JPEG Group's marker parser. (RM3) */
#include "rm3_jpeg.h"

/* Examines an APP0 marker payload: records JFIF header fields and traces JFXX
 * thumbnail extensions (Swing_DLL.xex 0x882E44A8). */
void ts4_jpeg_examine_app0_882E44A8(struct ts4_jpeg_decomp *cinfo, const ts4_joctet *data,
                                    unsigned int datalen, int remaining)
{
    int totallen = (int)datalen + remaining;

    if (datalen >= 14 && data[0] == 0x4A && data[1] == 0x46 && data[2] == 0x49 &&
        data[3] == 0x46 && data[4] == 0) {
        cinfo->saw_JFIF_marker = 1;
        cinfo->JFIF_major_version = data[5];
        cinfo->JFIF_minor_version = data[6];
        cinfo->density_unit = data[7];
        cinfo->X_density = (unsigned short)((data[8] << 8) + data[9]);
        cinfo->Y_density = (unsigned short)((data[10] << 8) + data[11]);
        if (cinfo->JFIF_major_version != 1)
            JPEG_MSG2(cinfo, -1, TS4_JWRN_JFIF_MAJOR, cinfo->JFIF_major_version,
                      cinfo->JFIF_minor_version);
        JPEG_TRACE5(cinfo, 1, TS4_JTRC_JFIF, cinfo->JFIF_major_version, cinfo->JFIF_minor_version,
                    cinfo->X_density, cinfo->Y_density, cinfo->density_unit);
        if (data[12] | data[13])
            JPEG_MSG2(cinfo, 1, TS4_JTRC_JFIF_THUMBNAIL, data[12], data[13]);
        totallen -= 14;
        if (totallen != (int)data[12] * (int)data[13] * 3)
            JPEG_MSG1(cinfo, 1, TS4_JTRC_JFIF_BADTHUMBNAILSIZE, totallen);
    } else if (datalen >= 6 && data[0] == 0x4A && data[1] == 0x46 && data[2] == 0x58 &&
               data[3] == 0x58 && data[4] == 0) {
        switch (data[5]) {
        case 0x10:
            JPEG_MSG1(cinfo, 1, TS4_JTRC_THUMB_JPEG, totallen);
            break;
        case 0x11:
            JPEG_MSG1(cinfo, 1, TS4_JTRC_THUMB_PALETTE, totallen);
            break;
        case 0x13:
            JPEG_MSG1(cinfo, 1, TS4_JTRC_THUMB_RGB, totallen);
            break;
        default:
            JPEG_MSG2(cinfo, 1, TS4_JTRC_JFIF_EXTENSION, data[5], totallen);
            break;
        }
    } else {
        JPEG_MSG1(cinfo, 1, TS4_JTRC_APP0, totallen);
    }
}

/* Reads a DQT marker segment into the quantization tables, converting each
 * table from zigzag to natural order (Swing_DLL.xex 0x882E4030). */
int ts4_jpeg_get_dqt_882E4030(struct ts4_jpeg_decomp *cinfo)
{
    int length;
    int n, i, prec;
    unsigned int tmp;
    struct ts4_jpeg_quant_tbl *quant_ptr;
    JPEG_INPUT_VARS(cinfo);

    JPEG_INPUT_2BYTES(cinfo, length, return 0);
    length -= 2;

    while (length > 0) {
        JPEG_INPUT_BYTE(cinfo, n, return 0);
        prec = n >> 4;
        n &= 0x0F;

        JPEG_MSG2(cinfo, 1, TS4_JTRC_DQT, n, prec);

        if (n >= 4)
            JPEG_ERREXIT1(cinfo, TS4_JERR_DQT_INDEX, n);

        if (cinfo->quant_tbl_ptrs[n] == 0)
            cinfo->quant_tbl_ptrs[n] = ts4_get_u32_off4_882EDE48(cinfo);
        quant_ptr = cinfo->quant_tbl_ptrs[n];

        for (i = 0; i < 64; i++) {
            if (prec)
                JPEG_INPUT_2BYTES(cinfo, tmp, return 0);
            else
                JPEG_INPUT_BYTE(cinfo, tmp, return 0);
            quant_ptr->quantval[lbl_88025F10[i]] = (unsigned short)tmp;
        }

        if (cinfo->err->trace_level >= 2) {
            for (i = 0; i < 64; i += 8) {
                JPEG_TRACE8(cinfo, 2, TS4_JTRC_QUANTVALS, quant_ptr->quantval[i],
                            quant_ptr->quantval[i + 1], quant_ptr->quantval[i + 2],
                            quant_ptr->quantval[i + 3], quant_ptr->quantval[i + 4],
                            quant_ptr->quantval[i + 5], quant_ptr->quantval[i + 6],
                            quant_ptr->quantval[i + 7]);
            }
        }

        length -= 64 + 1;
        if (prec)
            length -= 64;
    }

    if (length != 0)
        JPEG_ERREXIT(cinfo, TS4_JERR_BAD_LENGTH);

    JPEG_INPUT_SYNC(cinfo);
    return 1;
}

/* Reads a SOFn frame header: image geometry, precision and per-component
 * sampling/quantization selectors (Swing_DLL.xex 0x882E3488). */
int ts4_jpeg_get_sof_882E3488(struct ts4_jpeg_decomp *cinfo, int is_prog, int is_arith)
{
    int length;
    int c, ci;
    struct ts4_jpeg_component_info *compptr;
    JPEG_INPUT_VARS(cinfo);

    cinfo->progressive_mode = is_prog;
    cinfo->arith_code = is_arith;

    JPEG_INPUT_2BYTES(cinfo, length, return 0);

    JPEG_INPUT_BYTE(cinfo, cinfo->data_precision, return 0);
    JPEG_INPUT_2BYTES(cinfo, cinfo->image_height, return 0);
    JPEG_INPUT_2BYTES(cinfo, cinfo->image_width, return 0);
    JPEG_INPUT_BYTE(cinfo, cinfo->num_components, return 0);

    length -= 8;

    JPEG_TRACE4(cinfo, 1, TS4_JTRC_SOF, cinfo->unread_marker, (int)cinfo->image_width,
                (int)cinfo->image_height, cinfo->num_components);

    if (cinfo->marker->saw_SOF)
        JPEG_ERREXIT(cinfo, TS4_JERR_SOF_DUPLICATE);

    if (cinfo->image_height <= 0 || cinfo->image_width <= 0 || cinfo->num_components <= 0)
        JPEG_ERREXIT(cinfo, TS4_JERR_EMPTY_IMAGE);

    if (length != cinfo->num_components * 3)
        JPEG_ERREXIT(cinfo, TS4_JERR_BAD_LENGTH);

    if (cinfo->comp_info == 0)
        cinfo->comp_info = (struct ts4_jpeg_component_info *)(*cinfo->mem->alloc_small)(
            cinfo, 1, cinfo->num_components * sizeof(struct ts4_jpeg_component_info));

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        compptr->component_index = ci;
        JPEG_INPUT_BYTE(cinfo, compptr->component_id, return 0);
        JPEG_INPUT_BYTE(cinfo, c, return 0);
        compptr->h_samp_factor = (c >> 4) & 15;
        compptr->v_samp_factor = (c) & 15;
        JPEG_INPUT_BYTE(cinfo, compptr->quant_tbl_no, return 0);

        JPEG_TRACE4(cinfo, 1, TS4_JTRC_SOF_COMPONENT, compptr->component_id,
                    compptr->h_samp_factor, compptr->v_samp_factor, compptr->quant_tbl_no);
    }

    cinfo->marker->saw_SOF = 1;

    JPEG_INPUT_SYNC(cinfo);
    return 1;
}

/* Reads a SOS scan header: the scan's component list with their Huffman table
 * selectors, then the spectral/approximation parameters (Swing_DLL.xex 0x882E38D8). */
int ts4_jpeg_get_sos_882E38D8(struct ts4_jpeg_decomp *cinfo)
{
    int length;
    int i, ci, n, c, cc;
    struct ts4_jpeg_component_info *compptr;
    JPEG_INPUT_VARS(cinfo);

    if (!cinfo->marker->saw_SOF)
        JPEG_ERREXIT(cinfo, TS4_JERR_SOS_NO_SOF);

    JPEG_INPUT_2BYTES(cinfo, length, return 0);

    JPEG_INPUT_BYTE(cinfo, n, return 0);

    JPEG_MSG1(cinfo, 1, TS4_JTRC_SOS, n);

    if (length != (n * 2 + 6) || n < 1 || n > 4)
        JPEG_ERREXIT(cinfo, TS4_JERR_BAD_LENGTH);

    cinfo->comps_in_scan = n;

    for (i = 0; i < n; i++) {
        JPEG_INPUT_BYTE(cinfo, cc, return 0);
        JPEG_INPUT_BYTE(cinfo, c, return 0);

        for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
            if (cc == compptr->component_id)
                goto id_found;
        }

        JPEG_ERREXIT1(cinfo, TS4_JERR_BAD_COMPONENT_ID, cc);

    id_found:
        cinfo->cur_comp_info[i] = compptr;
        compptr->dc_tbl_no = (c >> 4) & 15;
        compptr->ac_tbl_no = (c) & 15;

        JPEG_TRACE3(cinfo, 1, TS4_JTRC_SOS_COMPONENT, cc, compptr->dc_tbl_no, compptr->ac_tbl_no);
    }

    JPEG_INPUT_BYTE(cinfo, c, return 0);
    cinfo->Ss = c;
    JPEG_INPUT_BYTE(cinfo, c, return 0);
    cinfo->Se = c;
    JPEG_INPUT_BYTE(cinfo, c, return 0);
    cinfo->Ah = (c >> 4) & 15;
    cinfo->Al = (c) & 15;

    JPEG_TRACE4(cinfo, 1, TS4_JTRC_SOS_PARAMS, cinfo->Ss, cinfo->Se, cinfo->Ah, cinfo->Al);

    cinfo->marker->next_restart_num = 0;

    cinfo->input_scan_number++;

    JPEG_INPUT_SYNC(cinfo);
    return 1;
}

/* Reads a DHT marker segment: code-length counts and symbol values for each
 * DC/AC Huffman table it defines (Swing_DLL.xex 0x882E3C90). */
int ts4_jpeg_get_dht_882E3C90(struct ts4_jpeg_decomp *cinfo)
{
    int length;
    unsigned char bits[17];
    unsigned char huffval[256];
    int i, index, count;
    struct ts4_jpeg_huff_tbl **htblptr;
    JPEG_INPUT_VARS(cinfo);

    JPEG_INPUT_2BYTES(cinfo, length, return 0);
    length -= 2;

    while (length > 16) {
        JPEG_INPUT_BYTE(cinfo, index, return 0);

        JPEG_MSG1(cinfo, 1, TS4_JTRC_DHT, index);

        bits[0] = 0;
        count = 0;
        for (i = 1; i <= 16; i++) {
            JPEG_INPUT_BYTE(cinfo, bits[i], return 0);
            count += bits[i];
        }

        length -= 1 + 16;

        JPEG_TRACE8(cinfo, 2, TS4_JTRC_HUFFBITS, bits[1], bits[2], bits[3], bits[4], bits[5],
                    bits[6], bits[7], bits[8]);
        JPEG_TRACE8(cinfo, 2, TS4_JTRC_HUFFBITS, bits[9], bits[10], bits[11], bits[12], bits[13],
                    bits[14], bits[15], bits[16]);

        if (count > 256 || count > length)
            JPEG_ERREXIT(cinfo, TS4_JERR_BAD_HUFF_TABLE);

        for (i = 0; i < count; i++)
            JPEG_INPUT_BYTE(cinfo, huffval[i], return 0);

        length -= count;

        if (index & 0x10) {
            index -= 0x10;
            htblptr = &cinfo->ac_huff_tbl_ptrs[index];
        } else {
            htblptr = &cinfo->dc_huff_tbl_ptrs[index];
        }

        if (index < 0 || index >= 4)
            JPEG_ERREXIT1(cinfo, TS4_JERR_DHT_INDEX, index);

        if (*htblptr == 0)
            *htblptr = ts4_get_u32_off4_882EDE88(cinfo);

        memcpy((*htblptr)->bits, bits, sizeof((*htblptr)->bits));
        memcpy((*htblptr)->huffval, huffval, sizeof((*htblptr)->huffval));
    }

    if (length != 0)
        JPEG_ERREXIT(cinfo, TS4_JERR_BAD_LENGTH);

    JPEG_INPUT_SYNC(cinfo);
    return 1;
}
