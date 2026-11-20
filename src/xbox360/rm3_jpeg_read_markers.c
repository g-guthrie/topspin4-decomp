/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG marker dispatch loop (IJG libjpeg jdmarker.c read_markers), Swing_DLL.xex
 * auto_03_882E3224. Kept apart from the per-marker readers so they stay calls. (RM3) */
#include "rm3_jpeg.h"

int ts4_jpeg_first_marker_882E4CF0(struct ts4_jpeg_decomp *cinfo); /* first_marker */
int ts4_jpeg_next_marker_882E4B70(struct ts4_jpeg_decomp *cinfo); /* next_marker */
int ts4_jpeg_get_soi_882E33A0(struct ts4_jpeg_decomp *cinfo); /* get_soi */
int ts4_jpeg_get_dri_882E4340(struct ts4_jpeg_decomp *cinfo); /* get_dri */
int ts4_jpeg_skip_variable_882E4A70(struct ts4_jpeg_decomp *cinfo); /* skip_variable */
int ts4_jpeg_get_sof_882E3488(struct ts4_jpeg_decomp *cinfo, int is_prog, int is_arith);
int ts4_jpeg_get_sos_882E38D8(struct ts4_jpeg_decomp *cinfo);
int ts4_jpeg_get_dht_882E3C90(struct ts4_jpeg_decomp *cinfo);
int ts4_jpeg_get_dqt_882E4030(struct ts4_jpeg_decomp *cinfo);

enum {
    TS4_JERR_UNKNOWN_MARKER = 0x44,
    TS4_JERR_SOF_UNSUPPORTED = 0x3c,
    TS4_JTRC_EOI = 0x55,
    TS4_JTRC_PARMLESS_MARKER = 0x5c
};

/* Reads markers until SOS or EOI, dispatching each to its parser; returns
 * 0 when input is suspended, 1 at SOS and 2 at EOI (Swing_DLL.xex 0x882E4DD0). */
int ts4_jpeg_read_markers_882E4DD0(struct ts4_jpeg_decomp *cinfo)
{
    for (;;) {
        if (cinfo->unread_marker == 0) {
            if (!cinfo->marker->saw_SOI) {
                if (!ts4_jpeg_first_marker_882E4CF0(cinfo))
                    return 0;
            } else {
                if (!ts4_jpeg_next_marker_882E4B70(cinfo))
                    return 0;
            }
        }
        switch (cinfo->unread_marker) {
        case 0xd8:
            if (!ts4_jpeg_get_soi_882E33A0(cinfo))
                return 0;
            break;

        case 0xc0:
        case 0xc1:
            if (!ts4_jpeg_get_sof_882E3488(cinfo, 0, 0))
                return 0;
            break;

        case 0xc2:
            if (!ts4_jpeg_get_sof_882E3488(cinfo, 1, 0))
                return 0;
            break;

        case 0xc9:
            if (!ts4_jpeg_get_sof_882E3488(cinfo, 0, 1))
                return 0;
            break;

        case 0xca:
            if (!ts4_jpeg_get_sof_882E3488(cinfo, 1, 1))
                return 0;
            break;

        case 0xc3:
        case 0xc5:
        case 0xc6:
        case 0xc7:
        case 0xc8:
        case 0xcb:
        case 0xcd:
        case 0xce:
        case 0xcf:
            JPEG_ERREXIT1(cinfo, TS4_JERR_SOF_UNSUPPORTED, cinfo->unread_marker);
            break;

        case 0xda:
            if (!ts4_jpeg_get_sos_882E38D8(cinfo))
                return 0;
            cinfo->unread_marker = 0;
            return 1;

        case 0xd9:
            cinfo->err->msg_code = TS4_JTRC_EOI;
            (*cinfo->err->emit_message)(cinfo, 1);
            cinfo->unread_marker = 0;
            return 2;

        case 0xcc:
            if (!ts4_jpeg_skip_variable_882E4A70(cinfo))
                return 0;
            break;

        case 0xc4:
            if (!ts4_jpeg_get_dht_882E3C90(cinfo))
                return 0;
            break;

        case 0xdb:
            if (!ts4_jpeg_get_dqt_882E4030(cinfo))
                return 0;
            break;

        case 0xdd:
            if (!ts4_jpeg_get_dri_882E4340(cinfo))
                return 0;
            break;

        case 0xe0:
        case 0xe1:
        case 0xe2:
        case 0xe3:
        case 0xe4:
        case 0xe5:
        case 0xe6:
        case 0xe7:
        case 0xe8:
        case 0xe9:
        case 0xea:
        case 0xeb:
        case 0xec:
        case 0xed:
        case 0xee:
        case 0xef:
            if (!(*cinfo->marker->process_APPn[cinfo->unread_marker - 0xe0])(cinfo))
                return 0;
            break;

        case 0xfe:
            if (!(*cinfo->marker->process_COM)(cinfo))
                return 0;
            break;

        case 0xd0:
        case 0xd1:
        case 0xd2:
        case 0xd3:
        case 0xd4:
        case 0xd5:
        case 0xd6:
        case 0xd7:
        case 0x01:
            JPEG_MSG1(cinfo, 1, TS4_JTRC_PARMLESS_MARKER, cinfo->unread_marker);
            break;

        case 0xdc:
            if (!ts4_jpeg_skip_variable_882E4A70(cinfo))
                return 0;
            break;

        default:
            JPEG_ERREXIT1(cinfo, TS4_JERR_UNKNOWN_MARKER, cinfo->unread_marker);
            break;
        }
        cinfo->unread_marker = 0;
    }
}
