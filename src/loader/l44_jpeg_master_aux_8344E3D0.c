/* Loader_DLL.xex 0x8344E3D0-0x8344E498, 0x8344EB28-0x8344ED48, executable version 0.0.0.3. */
/* Library routines: libjpeg jdmaster.c (use_merged_upsample, prepare_for_output_pass). */
#include "l44_jpeg.h"

int ts4l_jpeg_use_merged_upsample_8344E3D0(struct ts4l_jpeg_decomp *cinfo)
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

void ts4l_jpeg_prepare_for_output_pass_8344EB28(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_jpeg_decomp_master *master = cinfo->master;

    if (master->is_dummy_pass) {
        TS4L_ERREXIT(cinfo, 48);
    } else {
        if (cinfo->quantize_colors && cinfo->colormap == 0) {
            if (cinfo->two_pass_quantize && cinfo->enable_2pass_quant) {
                cinfo->cquantize = (struct ts4l_jpeg_cquantizer *)master->quantizer_2pass;
                master->is_dummy_pass = 1;
            } else if (cinfo->enable_1pass_quant) {
                cinfo->cquantize = (struct ts4l_jpeg_cquantizer *)master->quantizer_1pass;
            } else {
                TS4L_ERREXIT(cinfo, 46);
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
            (*cinfo->post->start_pass)(cinfo, (master->is_dummy_pass ? 3 : 0));
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
