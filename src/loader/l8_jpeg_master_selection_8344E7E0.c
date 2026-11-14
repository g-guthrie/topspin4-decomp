/* Loader_DLL.xex 0x8344E7E0-0x8344EB28, executable version 0.0.0.3. */
/* Library routine: libjpeg master_selection (jdmaster.c), with
   prepare_range_limit_table inlined. */

#include "l8_jpeg.h"

#ifdef _MSC_VER
void *memcpy(void *, const void *, unsigned int);
void *memset(void *, int, unsigned int);
#pragma intrinsic(memcpy)
#pragma intrinsic(memset)
#else
#include <string.h>
#endif
extern void fn_8344E498(ts4l_jcinfo *cinfo);
extern int fn_8344E3D0(ts4l_jcinfo *cinfo);
extern void fn_8345BF00(ts4l_jcinfo *cinfo);
extern void fn_8345B678(ts4l_jcinfo *cinfo);
extern void fn_8345A818(ts4l_jcinfo *cinfo);
extern void fn_8345A1B0(ts4l_jcinfo *cinfo, int need_full_buffer);
extern void fn_83459FC0(ts4l_jcinfo *cinfo);
extern void fn_83459AF8(ts4l_jcinfo *cinfo);
extern void fn_83458CE8(ts4l_jcinfo *cinfo);
extern void fn_83457E30(ts4l_jcinfo *cinfo, int need_full_buffer);
extern void fn_83456BD8(ts4l_jcinfo *cinfo, int need_full_buffer);

void ts4l_jpeg_master_selection_8344E7E0(ts4l_jcinfo *cinfo)
{
    ts4l_jmaster *master = cinfo->master;
    int use_c_buffer;
    ts4l_u8 *table;
    int i;

    fn_8344E498(cinfo);

    table = (ts4l_u8 *)(*cinfo->mem->alloc_small)(cinfo, 1, 1408);
    table += 256;
    cinfo->sample_range_limit = table;
    memset(table - 256, 0, 256);
    for (i = 0; i <= 255; i++)
        table[i] = (ts4l_u8)i;
    table += 128;
    for (i = 128; i < 2 * 256; i++)
        table[i] = 255;
    memset(table + (2 * 256), 0, 2 * 256 - 128);
    memcpy(table + (4 * 256 - 128), cinfo->sample_range_limit, 128);

    master->pass_number = 0;
    master->using_merged_upsample = fn_8344E3D0(cinfo);
    master->quantizer_1pass = 0;
    master->quantizer_2pass = 0;

    if (!cinfo->quantize_colors || !cinfo->buffered_image) {
        cinfo->enable_1pass_quant = 0;
        cinfo->enable_external_quant = 0;
        cinfo->enable_2pass_quant = 0;
    }

    if (cinfo->quantize_colors) {
        if (cinfo->raw_data_out)
            TS4L_ERREXIT(cinfo, 47);
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
            TS4L_ERREXIT(cinfo, 48);

        if (cinfo->enable_2pass_quant || cinfo->enable_external_quant)
            TS4L_ERREXIT(cinfo, 48);
    }

    if (!cinfo->raw_data_out) {
        if (master->using_merged_upsample) {
            fn_8345BF00(cinfo);
        } else {
            fn_8345B678(cinfo);
            fn_8345A818(cinfo);
        }
        fn_8345A1B0(cinfo, cinfo->enable_2pass_quant);
    }
    fn_83459FC0(cinfo);
    if (cinfo->arith_code) {
        TS4L_ERREXIT(cinfo, 1);
    } else {
        if (cinfo->progressive_mode)
            fn_83459AF8(cinfo);
        else
            fn_83458CE8(cinfo);
    }

    use_c_buffer = cinfo->inputctl->has_multiple_scans || cinfo->buffered_image;
    fn_83457E30(cinfo, use_c_buffer);

    if (!cinfo->raw_data_out)
        fn_83456BD8(cinfo, 0);

    (*cinfo->mem->realize_virt_arrays)(cinfo);

    (*cinfo->inputctl->start_input_pass)(cinfo);

    if (cinfo->progress != 0 && !cinfo->buffered_image && cinfo->inputctl->has_multiple_scans) {
        int nscans;
        if (cinfo->progressive_mode) {
            nscans = 2 + 3 * cinfo->num_components;
        } else {
            nscans = cinfo->num_components;
        }
        cinfo->progress->pass_counter = 0L;
        cinfo->progress->pass_limit = (long)cinfo->total_iMCU_rows * nscans;
        cinfo->progress->completed_passes = 0;
        cinfo->progress->total_passes = (cinfo->enable_2pass_quant ? 3 : 2);
        master->pass_number++;
    }
}
