/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG compression parameter setup (IJG libjpeg jcparam.c style), Swing_DLL.xex
 * auto_03_882E5668. Only the fields these functions touch are declared. (RM3) */
#include "rm3_jpeg.h"

enum {
    TS4_JCS_UNKNOWN = 0,
    TS4_JCS_GRAYSCALE = 1,
    TS4_JCS_RGB = 2,
    TS4_JCS_YCbCr = 3,
    TS4_JCS_CMYK = 4,
    TS4_JCS_YCCK = 5
};

enum {
    TS4_JERR_BAD_J_COLORSPACE = 0x0a,
    TS4_JERR_BAD_STATE = 0x14,
    TS4_JERR_COMPONENT_COUNT = 0x1a,
    TS4_CSTATE_START = 100
};

#define SET_COMP(index, id, hsamp, vsamp, quant, dctbl, actbl)                             \
    (compptr = &cinfo->comp_info[index], compptr->component_id = (id),                     \
     compptr->h_samp_factor = (hsamp), compptr->v_samp_factor = (vsamp),                   \
     compptr->quant_tbl_no = (quant), compptr->dc_tbl_no = (dctbl),                        \
     compptr->ac_tbl_no = (actbl))

/* Sets the JPEG output colorspace and the matching component IDs, sampling
 * factors and table selectors (Swing_DLL.xex 0x882E5F18). */
void ts4_jpeg_set_colorspace_882E5F18(struct ts4_jpeg_comp *cinfo, int colorspace)
{
    struct ts4_jpeg_component_info *compptr;
    int ci;

    if (cinfo->global_state != TS4_CSTATE_START)
        (cinfo->err->msg_code = TS4_JERR_BAD_STATE, cinfo->err->msg_parm[0] = cinfo->global_state,
         (*cinfo->err->error_exit)(cinfo));

    cinfo->jpeg_color_space = colorspace;

    cinfo->write_JFIF_header = 0;
    cinfo->write_Adobe_marker = 0;
    cinfo->marker_flag_e0 = 1;
    cinfo->marker_flag_e4 = 1;

    switch (colorspace) {
    case TS4_JCS_GRAYSCALE:
        cinfo->write_JFIF_header = 1;
        cinfo->num_components = 1;
        SET_COMP(0, 1, 1, 1, 0, 0, 0);
        break;
    case TS4_JCS_RGB:
        cinfo->write_Adobe_marker = 1;
        cinfo->num_components = 3;
        SET_COMP(0, 0x52, 1, 1, 0, 0, 0);
        SET_COMP(1, 0x47, 1, 1, 0, 0, 0);
        SET_COMP(2, 0x42, 1, 1, 0, 0, 0);
        break;
    case TS4_JCS_YCbCr:
        cinfo->write_JFIF_header = 1;
        cinfo->num_components = 3;
        SET_COMP(0, 1, 2, 2, 0, 0, 0);
        SET_COMP(1, 2, 1, 1, 1, 1, 1);
        SET_COMP(2, 3, 1, 1, 1, 1, 1);
        break;
    case TS4_JCS_CMYK:
        cinfo->write_Adobe_marker = 1;
        cinfo->num_components = 4;
        SET_COMP(0, 0x43, 1, 1, 0, 0, 0);
        SET_COMP(1, 0x4D, 1, 1, 0, 0, 0);
        SET_COMP(2, 0x59, 1, 1, 0, 0, 0);
        SET_COMP(3, 0x4B, 1, 1, 0, 0, 0);
        break;
    case TS4_JCS_YCCK:
        cinfo->write_Adobe_marker = 1;
        cinfo->num_components = 4;
        SET_COMP(0, 1, 2, 2, 0, 0, 0);
        SET_COMP(1, 2, 1, 1, 1, 1, 1);
        SET_COMP(2, 3, 1, 1, 1, 1, 1);
        SET_COMP(3, 4, 2, 2, 0, 0, 0);
        break;
    case TS4_JCS_UNKNOWN:
        cinfo->num_components = cinfo->input_components;
        if (cinfo->num_components < 1 || cinfo->num_components > 10)
            (cinfo->err->msg_code = TS4_JERR_COMPONENT_COUNT,
             cinfo->err->msg_parm[0] = cinfo->num_components, cinfo->err->msg_parm[1] = 10,
             (*cinfo->err->error_exit)(cinfo));
        for (ci = 0; ci < cinfo->num_components; ci++) {
            SET_COMP(ci, ci, 1, 1, 0, 0, 0);
        }
        break;
    default:
        (cinfo->err->msg_code = TS4_JERR_BAD_J_COLORSPACE, (*cinfo->err->error_exit)(cinfo));
    }
}
