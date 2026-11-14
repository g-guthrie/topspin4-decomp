/* Loader_DLL.xex 0x8344E498-0x8344EED8, executable version 0.0.0.3.
 * Statically linked libjpeg 6b routines. */

#include "l21_jp1_jpeg_8344E498.h"

int fn_8344E3D0(struct ts4l_jpeg_decomp *cinfo);
void fn_8344EB28(struct ts4l_jpeg_decomp *cinfo);

enum { TS4L_JERR_BAD_STATE = 0x14, TS4L_JERR_MODE_CHANGE = 0x2e, TS4L_JERR_NOT_COMPILED = 0x30 };

/* Rounds a / b up (jutils.c jdiv_round_up). */
long fn_8344EED8(long a, long b);

void ts4l_jpeg_master_selection_8344E7E0(struct ts4l_jpeg_decomp *cinfo);
void ts4l_if_get_u32_off54_8344ED48(struct ts4l_jpeg_decomp *cinfo); /* finish_output_pass */


/* Computes the output dimensions, per-component IDCT scaling and output component counts
 * from the requested scale and colorspace */
void ts4l_jpeg_calc_output_dimensions_8344E498(struct ts4l_jpeg_decomp *cinfo)
{
    int ci;
    struct ts4l_jpeg_component_info *compptr;

    if (cinfo->global_state != TS4L_DSTATE_READY)
        TS4L_ERREXIT1(cinfo, TS4L_JERR_BAD_STATE, cinfo->global_state);
    if (cinfo->scale_num * 8 <= cinfo->scale_denom) {
        cinfo->output_width = (ts4l_jdim)fn_8344EED8((long)cinfo->image_width, 8L);
        cinfo->output_height = (ts4l_jdim)fn_8344EED8((long)cinfo->image_height, 8L);
        cinfo->min_DCT_scaled_size = 1;
    } else if (cinfo->scale_num * 4 <= cinfo->scale_denom) {
        cinfo->output_width = (ts4l_jdim)fn_8344EED8((long)cinfo->image_width, 4L);
        cinfo->output_height = (ts4l_jdim)fn_8344EED8((long)cinfo->image_height, 4L);
        cinfo->min_DCT_scaled_size = 2;
    } else if (cinfo->scale_num * 2 <= cinfo->scale_denom) {
        cinfo->output_width = (ts4l_jdim)fn_8344EED8((long)cinfo->image_width, 2L);
        cinfo->output_height = (ts4l_jdim)fn_8344EED8((long)cinfo->image_height, 2L);
        cinfo->min_DCT_scaled_size = 4;
    } else {
        cinfo->output_width = cinfo->image_width;
        cinfo->output_height = cinfo->image_height;
        cinfo->min_DCT_scaled_size = 8;
    }
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        int ssize = cinfo->min_DCT_scaled_size;
        while (ssize < 8 &&
               (compptr->h_samp_factor * ssize * 2 <=
                cinfo->max_h_samp_factor * cinfo->min_DCT_scaled_size) &&
               (compptr->v_samp_factor * ssize * 2 <=
                cinfo->max_v_samp_factor * cinfo->min_DCT_scaled_size)) {
            ssize = ssize * 2;
        }
        compptr->DCT_scaled_size = ssize;
    }
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        compptr->downsampled_width = (ts4l_jdim)fn_8344EED8(
            (long)cinfo->image_width * (long)(compptr->h_samp_factor * compptr->DCT_scaled_size),
            (long)(cinfo->max_h_samp_factor * 8));
        compptr->downsampled_height = (ts4l_jdim)fn_8344EED8(
            (long)cinfo->image_height * (long)(compptr->v_samp_factor * compptr->DCT_scaled_size),
            (long)(cinfo->max_v_samp_factor * 8));
    }
    switch (cinfo->out_color_space) {
    case 1:
        cinfo->out_color_components = 1;
        break;
    case 2:
    case 3:
        cinfo->out_color_components = 3;
        break;
    case 4:
    case 5:
        cinfo->out_color_components = 4;
        break;
    default:
        cinfo->out_color_components = cinfo->num_components;
        break;
    }
    cinfo->output_components = (cinfo->quantize_colors ? 1 : cinfo->out_color_components);
    if (fn_8344E3D0(cinfo))
        cinfo->rec_outbuf_height = cinfo->max_v_samp_factor;
    else
        cinfo->rec_outbuf_height = 1;
}


/* Creates the decompression master and runs master selection */
void ts4l_jpeg_jinit_master_decompress_8344EE68(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_jpeg_decomp_master *master;

    master = (struct ts4l_jpeg_decomp_master *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(*master));
    cinfo->master = master;
    master->prepare_for_output_pass = fn_8344EB28;
    master->finish_output_pass = ts4l_if_get_u32_off54_8344ED48;
    master->is_dummy_pass = 0;
    ts4l_jpeg_master_selection_8344E7E0(cinfo);
}
