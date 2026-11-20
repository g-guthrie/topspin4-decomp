/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG inverse-DCT controller creation, IJG jddctmgr.c style. (JP1) */
#include "jp1_jpeg.h"

void ts4_jpeg_idct_start_pass_882F8A78(struct ts4_jpeg_decomp *cinfo);

/* Creates the IDCT controller and a zeroed multiplier table per component
 * (Swing_DLL.xex 0x882F8E68). */
void ts4_jpeg_jinit_inverse_dct_882F8E68(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_idct_controller *idct;
    int ci;
    struct ts4_jpeg_component_info *compptr;

    idct = (struct ts4_jpeg_idct_controller *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(*idct));
    cinfo->idct = idct;
    idct->start_pass = ts4_jpeg_idct_start_pass_882F8A78;
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        compptr->dct_table = (*cinfo->mem->alloc_small)(cinfo, 1, 64 * sizeof(int));
        memset(compptr->dct_table, 0, 64 * sizeof(int));
        idct->cur_method[ci] = -1;
    }
}
