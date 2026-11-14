/* Loader_DLL.xex 0x83443EB0-0x83443FF8, 0x83443FF8-0x834441F4, executable version 0.0.0.3. */
/* Library routines: libjpeg jcapistd.c jpeg_write_raw_data, jcparam.c jpeg_add_quant_table. */
#include "l44_jpeg.h"

extern void *ts4_get_u32_off4_8344E350(struct ts4l_jcomp *cinfo);

unsigned int ts4l_jpeg_write_raw_data_83443EB0(struct ts4l_jcomp *cinfo, void *data,
                                               unsigned int num_lines)
{
    unsigned int lines_per_iMCU_row;

    if (cinfo->global_state != 102)
        TS4L_CERREXIT1(cinfo, 20, cinfo->global_state);

    if (cinfo->next_scanline >= cinfo->image_height) {
        cinfo->err->msg_code = 123;
        (*cinfo->err->emit_message)(cinfo, -1);
        return 0;
    }

    if (cinfo->progress != 0) {
        cinfo->progress->pass_counter = (int)cinfo->next_scanline;
        cinfo->progress->pass_limit = (int)cinfo->image_height;
        (*cinfo->progress->progress_monitor)(TS4L_J(cinfo));
    }

    if (cinfo->master->call_pass_startup)
        (*cinfo->master->pass_startup)(cinfo);

    lines_per_iMCU_row = cinfo->max_v_samp_factor * 8;
    if (num_lines < lines_per_iMCU_row)
        TS4L_CERREXIT(cinfo, 23);

    if (!(*cinfo->coef->compress_data)(cinfo, data))
        return 0;

    cinfo->next_scanline += lines_per_iMCU_row;
    return lines_per_iMCU_row;
}

void ts4l_jpeg_add_quant_table_83443FF8(struct ts4l_jcomp *cinfo, int which_tbl,
                                        const unsigned int *basic_table, int scale_factor,
                                        int force_baseline)
{
    struct ts4l_jpeg_quant_tbl **qtblptr;
    int i;
    int temp;

    if (cinfo->global_state != 100)
        TS4L_CERREXIT1(cinfo, 20, cinfo->global_state);

    if (which_tbl < 0 || which_tbl >= 4)
        TS4L_CERREXIT1(cinfo, 31, which_tbl);

    qtblptr = (struct ts4l_jpeg_quant_tbl **)&cinfo->quant_tbl_ptrs[which_tbl];

    if (*qtblptr == 0)
        *qtblptr = (struct ts4l_jpeg_quant_tbl *)ts4_get_u32_off4_8344E350(cinfo);

    for (i = 0; i < 64; i++) {
        temp = ((int)basic_table[i] * scale_factor + 50) / 100;
        if (temp <= 0)
            temp = 1;
        if (temp > 32767)
            temp = 32767;
        if (force_baseline && temp > 255)
            temp = 255;
        (*qtblptr)->quantval[i] = (unsigned short)temp;
    }

    (*qtblptr)->sent_table = 0;
}
