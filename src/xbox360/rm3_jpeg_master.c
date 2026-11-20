/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG decompression master control (IJG libjpeg jdmaster.c style), Swing_DLL.xex
 * auto_03_882EDEC4. This build has no color quantizers or arithmetic decoding. (RM3) */
#include "rm3_jpeg.h"

void ts4_jpeg_calc_output_dimensions_882EDF90(struct ts4_jpeg_decomp *cinfo);       /* jpeg_calc_output_dimensions */
int ts4_jpeg_use_merged_upsample_882EDEC8(struct ts4_jpeg_decomp *cinfo);        /* use_merged_upsample */
void ts4_jpeg_jinit_merged_upsampler_882FADA0(struct ts4_jpeg_decomp *cinfo);       /* jinit_merged_upsampler */
void ts4_jpeg_jinit_color_deconverter_882FA518(struct ts4_jpeg_decomp *cinfo);       /* jinit_color_deconverter */
void ts4_jpeg_jinit_upsampler_882F96C0(struct ts4_jpeg_decomp *cinfo);       /* jinit_upsampler */
void ts4_jpeg_jinit_d_post_controller_882F9058(struct ts4_jpeg_decomp *cinfo, int need_full_buffer); /* jinit_d_post_controller */
void ts4_jpeg_jinit_inverse_dct_882F8E68(struct ts4_jpeg_decomp *cinfo);       /* jinit_inverse_dct */
void ts4_jpeg_jinit_phuff_decoder_882F89A0(struct ts4_jpeg_decomp *cinfo);       /* jinit_phuff_decoder */
void ts4_jpeg_jinit_huff_decoder_882F7B90(struct ts4_jpeg_decomp *cinfo);       /* jinit_huff_decoder */
void ts4_jpeg_jinit_d_coef_controller_882F6D80(struct ts4_jpeg_decomp *cinfo, int need_full_buffer); /* jinit_d_coef_controller */
void ts4_jpeg_jinit_d_main_controller_882F5B30(struct ts4_jpeg_decomp *cinfo, int need_full_buffer); /* jinit_d_main_controller */

enum {
    TS4_JERR_ARITH_NOTIMPL = 0x01,
    TS4_JERR_NOTIMPL = 0x2f,
    TS4_JERR_NOT_COMPILED = 0x30
};

/* Builds the sample range-limit table used after IDCT and color conversion. */
static void prepare_range_limit_table(struct ts4_jpeg_decomp *cinfo)
{
    unsigned char *table;
    int i;

    table = (unsigned char *)(*cinfo->mem->alloc_small)(cinfo, 1, (5 * 256 + 128) * sizeof(unsigned char));
    table += 256;
    cinfo->sample_range_limit = table;
    memset(table - 256, 0, 256 * sizeof(unsigned char));
    for (i = 0; i <= 255; i++)
        table[i] = (unsigned char)i;
    table += 128;
    for (i = 128; i < 2 * 256; i++)
        table[i] = 255;
    memset(table + (2 * 256), 0, (2 * 256 - 128) * sizeof(unsigned char));
    memcpy(table + (4 * 256 - 128), cinfo->sample_range_limit, 128 * sizeof(unsigned char));
}

/* Selects and initializes the decompression modules for the current image
 * (Swing_DLL.xex 0x882EE220). */
void ts4_jpeg_master_selection_882EE220(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_decomp_master *master = cinfo->master;
    int use_c_buffer;

    ts4_jpeg_calc_output_dimensions_882EDF90(cinfo);
    prepare_range_limit_table(cinfo);

    master->pass_number = 0;
    master->using_merged_upsample = ts4_jpeg_use_merged_upsample_882EDEC8(cinfo);

    master->quantizer_1pass = 0;
    master->quantizer_2pass = 0;
    if (!cinfo->quantize_colors || !cinfo->buffered_image) {
        cinfo->enable_1pass_quant = 0;
        cinfo->enable_external_quant = 0;
        cinfo->enable_2pass_quant = 0;
    }
    if (cinfo->quantize_colors) {
        if (cinfo->raw_data_out)
            JPEG_ERREXIT(cinfo, TS4_JERR_NOTIMPL);
        if (cinfo->out_color_components != 3) {
            cinfo->enable_1pass_quant = 1;
            cinfo->enable_external_quant = 0;
            cinfo->enable_2pass_quant = 0;
            cinfo->colormap = 0;
        } else if (cinfo->colormap != 0) {
            cinfo->enable_external_quant = 1;
        } else if (cinfo->two_pass_quantize) {
            cinfo->enable_2pass_quant = 1;
        } else {
            cinfo->enable_1pass_quant = 1;
        }

        if (cinfo->enable_1pass_quant)
            JPEG_ERREXIT(cinfo, TS4_JERR_NOT_COMPILED);

        if (cinfo->enable_2pass_quant || cinfo->enable_external_quant)
            JPEG_ERREXIT(cinfo, TS4_JERR_NOT_COMPILED);
    }

    if (!cinfo->raw_data_out) {
        if (master->using_merged_upsample) {
            ts4_jpeg_jinit_merged_upsampler_882FADA0(cinfo);
        } else {
            ts4_jpeg_jinit_color_deconverter_882FA518(cinfo);
            ts4_jpeg_jinit_upsampler_882F96C0(cinfo);
        }
        ts4_jpeg_jinit_d_post_controller_882F9058(cinfo, cinfo->enable_2pass_quant);
    }
    ts4_jpeg_jinit_inverse_dct_882F8E68(cinfo);
    if (cinfo->arith_code) {
        JPEG_ERREXIT(cinfo, TS4_JERR_ARITH_NOTIMPL);
    } else {
        if (cinfo->progressive_mode)
            ts4_jpeg_jinit_phuff_decoder_882F89A0(cinfo);
        else
            ts4_jpeg_jinit_huff_decoder_882F7B90(cinfo);
    }

    use_c_buffer = cinfo->inputctl->has_multiple_scans || cinfo->buffered_image;
    ts4_jpeg_jinit_d_coef_controller_882F6D80(cinfo, use_c_buffer);

    if (!cinfo->raw_data_out)
        ts4_jpeg_jinit_d_main_controller_882F5B30(cinfo, 0);

    (*cinfo->mem->realize_virt_arrays)(cinfo);

    (*cinfo->inputctl->start_input_pass)(cinfo);

    if (cinfo->progress != 0 && !cinfo->buffered_image && cinfo->inputctl->has_multiple_scans) {
        int nscans;
        if (cinfo->progressive_mode)
            nscans = 2 + 3 * cinfo->num_components;
        else
            nscans = cinfo->num_components;
        cinfo->progress->pass_counter = 0;
        cinfo->progress->pass_limit = (int)cinfo->total_iMCU_rows * nscans;
        cinfo->progress->completed_passes = 0;
        cinfo->progress->total_passes = (cinfo->enable_2pass_quant ? 3 : 2);
        master->pass_number++;
    }
}
