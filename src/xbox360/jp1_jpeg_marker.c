/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG marker reader helpers (IJG jdmarker.c style). (JP1) */
#include "jp1_jpeg.h"

enum {
    JP1_JERR_NO_SOI = 0x35, JP1_JTRC_SOI = 0x66, JP1_JERR_SOI_DUPLICATE = 0x3d,
    JP1_JERR_BAD_LENGTH = 0x0b, JP1_JTRC_DRI = 0x52, JP1_JTRC_ADOBE = 0x4c, JP1_JTRC_APP14 = 0x4e,
    JP1_JERR_UNKNOWN_MARKER = 0x44, JP1_JTRC_SKIP = 0x5b, JP1_JWRN_EXTRANEOUS_DATA = 0x74
};

void ts4_jpeg_examine_app0_882E44A8(struct ts4_jpeg_decomp *cinfo, const ts4_joctet *data,
                                    unsigned int datalen, int remaining);

/* Examines an APP14 (Adobe) marker payload (Swing_DLL.xex 0x882E47B8). */
void ts4_jpeg_examine_app14_882E47B8(struct ts4_jpeg_decomp *cinfo, const ts4_joctet *data,
                                     unsigned int datalen, int remaining)
{
    unsigned int version, flags0, flags1, transform;
    if (datalen >= 12 && data[0] == 0x41 && data[1] == 0x64 && data[2] == 0x6f &&
        data[3] == 0x62 && data[4] == 0x65) {
        version = (data[5] << 8) + data[6];
        flags0 = (data[7] << 8) + data[8];
        flags1 = (data[9] << 8) + data[10];
        transform = data[11];
        JP1_TRACEMS4(cinfo, 1, JP1_JTRC_ADOBE, version, flags0, flags1, transform);
        cinfo->saw_Adobe_marker = 1;
        cinfo->Adobe_transform = (unsigned char)transform;
    } else {
        JP1_TRACEMS1(cinfo, 1, JP1_JTRC_APP14, (int)(datalen + remaining));
    }
}

/* Reads an APP0 or APP14 marker segment and hands its leading bytes to the
 * matching examiner (Swing_DLL.xex 0x882E48C8). */
int ts4_jpeg_get_interesting_appn_882E48C8(struct ts4_jpeg_decomp *cinfo)
{
    int length;
    ts4_joctet b[14];
    unsigned int i, numtoread;
    JP1_INPUT_VARS(cinfo);

    JP1_INPUT_2BYTES(cinfo, length, return 0);
    length -= 2;
    if (length >= 14)
        numtoread = 14;
    else if (length > 0)
        numtoread = (unsigned int)length;
    else
        numtoread = 0;
    for (i = 0; i < numtoread; i++)
        JP1_INPUT_BYTE(cinfo, b[i], return 0);
    length -= (int)numtoread;
    switch (cinfo->unread_marker) {
    case 0xE0:
        ts4_jpeg_examine_app0_882E44A8(cinfo, b, numtoread, length);
        break;
    case 0xEE:
        ts4_jpeg_examine_app14_882E47B8(cinfo, b, numtoread, length);
        break;
    default:
        JP1_ERREXIT1(cinfo, JP1_JERR_UNKNOWN_MARKER, cinfo->unread_marker);
        break;
    }
    JP1_INPUT_SYNC(cinfo);
    if (length > 0)
        (*cinfo->src->skip_input_data)(cinfo, length);
    return 1;
}

/* Skips over an uninteresting variable-length marker segment (Swing_DLL.xex 0x882E4A70). */
int ts4_jpeg_skip_variable_882E4A70(struct ts4_jpeg_decomp *cinfo)
{
    int length;
    JP1_INPUT_VARS(cinfo);

    JP1_INPUT_2BYTES(cinfo, length, return 0);
    length -= 2;
    JP1_TRACEMS2(cinfo, 1, JP1_JTRC_SKIP, cinfo->unread_marker, (int)length);
    JP1_INPUT_SYNC(cinfo);
    if (length > 0)
        (*cinfo->src->skip_input_data)(cinfo, (int)length);
    return 1;
}

/* Scans forward to the next marker byte, counting discarded bytes (Swing_DLL.xex 0x882E4B70). */
int ts4_jpeg_next_marker_882E4B70(struct ts4_jpeg_decomp *cinfo)
{
    int c;
    JP1_INPUT_VARS(cinfo);

    for (;;) {
        JP1_INPUT_BYTE(cinfo, c, return 0);
        while (c != 0xFF) {
            cinfo->marker->discarded_bytes++;
            JP1_INPUT_SYNC(cinfo);
            JP1_INPUT_BYTE(cinfo, c, return 0);
        }
        do {
            JP1_INPUT_BYTE(cinfo, c, return 0);
        } while (c == 0xFF);
        if (c != 0)
            break;
        cinfo->marker->discarded_bytes += 2;
        JP1_INPUT_SYNC(cinfo);
    }
    if (cinfo->marker->discarded_bytes != 0) {
        JP1_WARNMS2(cinfo, JP1_JWRN_EXTRANEOUS_DATA, cinfo->marker->discarded_bytes, c);
        cinfo->marker->discarded_bytes = 0;
    }
    cinfo->unread_marker = c;
    JP1_INPUT_SYNC(cinfo);
    return 1;
}

/* Requires the stream to begin with an SOI marker (Swing_DLL.xex 0x882E4CF0). */
int ts4_jpeg_first_marker_882E4CF0(struct ts4_jpeg_decomp *cinfo)
{
    int c, c2;
    JP1_INPUT_VARS(cinfo);

    JP1_INPUT_BYTE(cinfo, c, return 0);
    JP1_INPUT_BYTE(cinfo, c2, return 0);
    if (c != 0xFF || c2 != 0xD8)
        JP1_ERREXIT2(cinfo, JP1_JERR_NO_SOI, c, c2);
    cinfo->unread_marker = c2;
    JP1_INPUT_SYNC(cinfo);
    return 1;
}

/* Processes an SOI marker: resets the JFIF/Adobe defaults and arithmetic-coding tables
 * (Swing_DLL.xex 0x882E33A0). */
int ts4_jpeg_get_soi_882E33A0(struct ts4_jpeg_decomp *cinfo)
{
    int i;

    JP1_TRACEMS(cinfo, 1, JP1_JTRC_SOI);
    if (cinfo->marker->saw_SOI)
        JP1_ERREXIT(cinfo, JP1_JERR_SOI_DUPLICATE);
    for (i = 0; i < 16; i++) {
        cinfo->arith_dc_L[i] = 0;
        cinfo->arith_dc_U[i] = 1;
        cinfo->arith_ac_K[i] = 5;
    }
    cinfo->restart_interval = 0;
    cinfo->jpeg_color_space = 0;
    cinfo->CCIR601_sampling = 0;
    cinfo->saw_JFIF_marker = 0;
    cinfo->JFIF_major_version = 1;
    cinfo->JFIF_minor_version = 1;
    cinfo->density_unit = 0;
    cinfo->X_density = 1;
    cinfo->Y_density = 1;
    cinfo->saw_Adobe_marker = 0;
    cinfo->Adobe_transform = 0;
    cinfo->marker->saw_SOI = 1;
    return 1;
}

/* Reads a DRI marker segment: the restart interval (Swing_DLL.xex 0x882E4340). */
int ts4_jpeg_get_dri_882E4340(struct ts4_jpeg_decomp *cinfo)
{
    int length;
    unsigned int tmp;
    JP1_INPUT_VARS(cinfo);

    JP1_INPUT_2BYTES(cinfo, length, return 0);
    if (length != 4)
        JP1_ERREXIT(cinfo, JP1_JERR_BAD_LENGTH);
    JP1_INPUT_2BYTES(cinfo, tmp, return 0);
    JP1_TRACEMS1(cinfo, 1, JP1_JTRC_DRI, (int)tmp);
    cinfo->restart_interval = tmp;
    JP1_INPUT_SYNC(cinfo);
    return 1;
}
