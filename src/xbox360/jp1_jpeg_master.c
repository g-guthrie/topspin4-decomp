/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG decompression master control, IJG jdmaster.c style. (JP1) */
#include "jp1_jpeg.h"

enum { JP1_JERR_BAD_STATE = 0x14, JP1_JERR_MODE_CHANGE = 0x2e, JP1_JERR_NOT_COMPILED = 0x30 };

/* Rounds a / b up (jutils.c jdiv_round_up). */
long ts4_jpeg_jdiv_round_up_882EE848(long a, long b);

void ts4_jpeg_master_selection_882EE220(struct ts4_jpeg_decomp *cinfo);
void ts4_if_get_u32_off54_882EE788(struct ts4_jpeg_decomp *cinfo); /* finish_output_pass */

/* Reports whether merged upsampling and color conversion can handle this image: plain
 * 2h1v or 2h2v YCbCr to RGB (Swing_DLL.xex 0x882EDEC8). */
int ts4_jpeg_use_merged_upsample_882EDEC8(struct ts4_jpeg_decomp *cinfo)
{
    if (cinfo->do_fancy_upsampling || cinfo->CCIR601_sampling)
        return 0;
    if (cinfo->jpeg_color_space != 3 || cinfo->num_components != 3 || cinfo->out_color_space != 2 ||
        cinfo->out_color_components != 3)
        return 0;
    if (cinfo->comp_info[0].h_samp_factor != 2 || cinfo->comp_info[1].h_samp_factor != 1 ||
        cinfo->comp_info[2].h_samp_factor != 1 || cinfo->comp_info[0].v_samp_factor > 2 ||
        cinfo->comp_info[1].v_samp_factor != 1 || cinfo->comp_info[2].v_samp_factor != 1)
        return 0;
    if (cinfo->comp_info[0].DCT_scaled_size != cinfo->min_DCT_scaled_size ||
        cinfo->comp_info[1].DCT_scaled_size != cinfo->min_DCT_scaled_size ||
        cinfo->comp_info[2].DCT_scaled_size != cinfo->min_DCT_scaled_size)
        return 0;
    return 1;
}

/* Computes the output dimensions, per-component IDCT scaling and output component counts
 * from the requested scale and colorspace (Swing_DLL.xex 0x882EDF90). */
void ts4_jpeg_calc_output_dimensions_882EDF90(struct ts4_jpeg_decomp *cinfo)
{
    int ci;
    struct ts4_jpeg_component_info *compptr;

    if (cinfo->global_state != JP1_DSTATE_READY)
        JP1_ERREXIT1(cinfo, JP1_JERR_BAD_STATE, cinfo->global_state);
    if (cinfo->scale_num * 8 <= cinfo->scale_denom) {
        cinfo->output_width = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_width, 8L);
        cinfo->output_height = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_height, 8L);
        cinfo->min_DCT_scaled_size = 1;
    } else if (cinfo->scale_num * 4 <= cinfo->scale_denom) {
        cinfo->output_width = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_width, 4L);
        cinfo->output_height = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_height, 4L);
        cinfo->min_DCT_scaled_size = 2;
    } else if (cinfo->scale_num * 2 <= cinfo->scale_denom) {
        cinfo->output_width = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_width, 2L);
        cinfo->output_height = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848((long)cinfo->image_height, 2L);
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
        compptr->downsampled_width = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848(
            (long)cinfo->image_width * (long)(compptr->h_samp_factor * compptr->DCT_scaled_size),
            (long)(cinfo->max_h_samp_factor * 8));
        compptr->downsampled_height = (ts4_jdim)ts4_jpeg_jdiv_round_up_882EE848(
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
    if (ts4_jpeg_use_merged_upsample_882EDEC8(cinfo))
        cinfo->rec_outbuf_height = cinfo->max_v_samp_factor;
    else
        cinfo->rec_outbuf_height = 1;
}

/* Starts an output pass: selects the quantizer on the first pass, then starts every
 * stage of the output pipeline and the progress counters (Swing_DLL.xex 0x882EE568). */
void ts4_jpeg_prepare_for_output_pass_882EE568(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_decomp_master *master = cinfo->master;

    if (master->is_dummy_pass) {
        JP1_ERREXIT(cinfo, JP1_JERR_NOT_COMPILED);
    } else {
        if (cinfo->quantize_colors && cinfo->colormap == 0) {
            if (cinfo->two_pass_quantize && cinfo->enable_2pass_quant) {
                cinfo->cquantize = (struct ts4_jpeg_cquantizer *)master->quantizer_2pass;
                master->is_dummy_pass = 1;
            } else if (cinfo->enable_1pass_quant) {
                cinfo->cquantize = (struct ts4_jpeg_cquantizer *)master->quantizer_1pass;
            } else {
                JP1_ERREXIT(cinfo, JP1_JERR_MODE_CHANGE);
            }
        }
        (*cinfo->idct->start_pass)(cinfo);
        (*cinfo->coef->start_output_pass)(cinfo);
        if (!cinfo->raw_data_out) {
            if (!master->using_merged_upsample)
                (*cinfo->cconvert->start_pass)(cinfo);
            (*cinfo->upsample->start_pass)(cinfo);
            if (cinfo->quantize_colors)
                (*cinfo->cquantize->start_pass)(cinfo, master->is_dummy_pass);
            (*cinfo->post->start_pass)(cinfo, master->is_dummy_pass ? 3 : 0);
            (*cinfo->main->start_pass)(cinfo, 0);
        }
    }
    if (cinfo->progress != 0) {
        cinfo->progress->completed_passes = master->pass_number;
        cinfo->progress->total_passes = master->pass_number + (master->is_dummy_pass ? 2 : 1);
        if (cinfo->buffered_image && !cinfo->inputctl->eoi_reached) {
            cinfo->progress->total_passes += (cinfo->enable_2pass_quant ? 2 : 1);
        }
    }
}

/* Creates the decompression master and runs master selection (Swing_DLL.xex 0x882EE7D8). */
void ts4_jpeg_jinit_master_decompress_882EE7D8(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_decomp_master *master;

    master = (struct ts4_jpeg_decomp_master *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(*master));
    cinfo->master = master;
    master->prepare_for_output_pass = ts4_jpeg_prepare_for_output_pass_882EE568;
    master->finish_output_pass = ts4_if_get_u32_off54_882EE788;
    master->is_dummy_pass = 0;
    ts4_jpeg_master_selection_882EE220(cinfo);
}
