/* Loader_DLL.xex 0x8345BFE0-0x8345C0E8, 0x8345C0E8-0x8345C13C, 0x8345C218-0x8345C288, executable version 0.0.0.3. */
/* Library routines: libjpeg jcmainct.c (process_data_simple_main, start_pass_main),
   jccoefct.c start_iMCU_row. */
#include "l44_jpeg.h"

struct ts4l_cmain {
    void (*start_pass)(struct ts4l_jcomp *cinfo, int pass_mode);        /* 0x00 */
    void (*process_data)(struct ts4l_jcomp *cinfo);                     /* 0x04 */
    unsigned int cur_iMCU_row;                                          /* 0x08 */
    unsigned int rowgroup_ctr;                                          /* 0x0c */
    int suspended;                                                      /* 0x10 */
    int pass_mode;                                                      /* 0x14 */
    void *buffer[10];                                                   /* 0x18 */
};

struct ts4l_cprep {
    void (*start_pass)(struct ts4l_jcomp *cinfo, int pass_mode);
    void (*pre_process_data)(struct ts4l_jcomp *cinfo, void *input_buf, unsigned int *in_row_ctr,
                             unsigned int in_rows_avail, void *output_buf, unsigned int *out_row_group_ctr,
                             unsigned int out_row_groups_avail);
};

struct ts4l_ccoef_ctl {
    void (*start_pass)(struct ts4l_jcomp *cinfo, int pass_mode);        /* 0x00 */
    int (*compress_data)(struct ts4l_jcomp *cinfo, void *input_buf);    /* 0x04 */
    unsigned int iMCU_row_num;                                          /* 0x08 */
    unsigned int mcu_ctr;                                               /* 0x0c */
    int MCU_vert_offset;                                                /* 0x10 */
    int MCU_rows_per_iMCU_row;                                          /* 0x14 */
};

extern void fn_8345BFE0(void);

void ts4l_jpeg_cmain_process_data_simple_8345BFE0(struct ts4l_jcomp *cinfo, void *input_buf,
                                                  unsigned int *in_row_ctr, unsigned int in_rows_avail)
{
    struct ts4l_cmain *main = (struct ts4l_cmain *)cinfo->main;

    while (main->cur_iMCU_row < cinfo->total_iMCU_rows) {
        if (main->rowgroup_ctr < 8)
            (*((struct ts4l_cprep *)cinfo->prep)->pre_process_data)(
                cinfo, input_buf, in_row_ctr, in_rows_avail, main->buffer, &main->rowgroup_ctr, 8);

        if (main->rowgroup_ctr != 8)
            return;

        if (!(*cinfo->coef->compress_data)(cinfo, main->buffer)) {
            if (!main->suspended) {
                (*in_row_ctr)--;
                main->suspended = 1;
            }
            return;
        }

        if (main->suspended) {
            (*in_row_ctr)++;
            main->suspended = 0;
        }
        main->rowgroup_ctr = 0;
        main->cur_iMCU_row++;
    }
}

void ts4l_jpeg_cmain_start_pass_8345C0E8(struct ts4l_jcomp *cinfo, int pass_mode)
{
    struct ts4l_cmain *main = (struct ts4l_cmain *)cinfo->main;

    if (cinfo->raw_data_in)
        return;

    main->pass_mode = pass_mode;
    main->cur_iMCU_row = 0;
    main->rowgroup_ctr = 0;
    main->suspended = 0;

    switch (pass_mode) {
    case 0:
        main->process_data = (void (*)(struct ts4l_jcomp *))fn_8345BFE0;
        break;
    default:
        TS4L_CERREXIT(cinfo, 4);
        break;
    }
}

void ts4l_jpeg_ccoef_start_iMCU_row_8345C218(struct ts4l_jcomp *cinfo)
{
    struct ts4l_ccoef_ctl *coef = (struct ts4l_ccoef_ctl *)cinfo->coef;

    if (cinfo->comps_in_scan > 1) {
        coef->MCU_rows_per_iMCU_row = 1;
    } else {
        if (coef->iMCU_row_num < (cinfo->total_iMCU_rows - 1))
            coef->MCU_rows_per_iMCU_row = cinfo->cur_comp_info[0]->v_samp_factor;
        else
            coef->MCU_rows_per_iMCU_row = cinfo->cur_comp_info[0]->last_row_height;
    }

    coef->mcu_ctr = 0;
    coef->MCU_vert_offset = 0;
}
