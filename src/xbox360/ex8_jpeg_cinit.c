/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b compression initialization (jcinit.c). */
#include "ex8_jpeg.h"

enum { EX8_JERR_ARITH_NOTIMPL = 1 };

void ex8_jinit_c_master_control_883021B0(ex8_jcomp *cinfo, int transcode_only); /* jinit_c_master_control */
void fn_88300F78(ex8_jcomp *cinfo);
void ex8_jinit_downsampler_883006B0(ex8_jcomp *cinfo);
void ex8_jinit_c_prep_controller_882FFCC8(ex8_jcomp *cinfo, int need_full_buffer);
void ex8_jinit_forward_dct_882FF558(ex8_jcomp *cinfo);
void ex8_jinit_phuff_encoder_882FE1A0(ex8_jcomp *cinfo);
void ex8_jinit_huff_encoder_882FCFE0(ex8_jcomp *cinfo);
void ex8_jinit_c_coef_controller_882FB938(ex8_jcomp *cinfo, int need_full_buffer);
void ex8_jinit_c_main_controller_882FAFE0(ex8_jcomp *cinfo, int need_full_buffer);
void ts4_get_u32_off4_882EFCB0(ex8_jcomp *cinfo); /* jinit_marker_writer */

/* Sets up every compression module and writes the SOI. */
void ex8_jinit_compress_master_882EFD50(ex8_jcomp *cinfo)
{
    ex8_jinit_c_master_control_883021B0(cinfo, 0);

    if (!cinfo->raw_data_in) {
        fn_88300F78(cinfo);
        ex8_jinit_downsampler_883006B0(cinfo);
        ex8_jinit_c_prep_controller_882FFCC8(cinfo, 0);
    }

    ex8_jinit_forward_dct_882FF558(cinfo);

    if (cinfo->arith_code) {
        EX8_ERREXIT(cinfo, EX8_JERR_ARITH_NOTIMPL);
    } else {
        if (cinfo->progressive_mode)
            ex8_jinit_phuff_encoder_882FE1A0(cinfo);
        else
            ex8_jinit_huff_encoder_882FCFE0(cinfo);
    }

    ex8_jinit_c_coef_controller_882FB938(cinfo, (int)(cinfo->num_scans > 1 || cinfo->optimize_coding));
    ex8_jinit_c_main_controller_882FAFE0(cinfo, 0);

    ts4_get_u32_off4_882EFCB0(cinfo);

    (*cinfo->mem->realize_virt_arrays)(cinfo);

    (*cinfo->marker->write_file_header)(cinfo);
}
