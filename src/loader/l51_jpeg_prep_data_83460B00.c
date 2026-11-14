/* Loader_DLL.xex 0x83460B00-0x83460D34, 0x83460D38-0x83460F90, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcprepct.c): pre_process_data and pre_process_context. */
#include "l44_jpeg.h"

struct ts4l_cprep_ctl {
    void *start_pass;                  /* 0x00 */
    void *pre_process_data;            /* 0x04 */
    unsigned char **color_buf[10];     /* 0x08 */
    unsigned int rows_to_go;           /* 0x30 */
    int next_buf_row;                  /* 0x34 */
    int this_row_group;                /* 0x38 */
    int next_buf_stop;                 /* 0x3c */
};

struct ts4l_cconvert {
    void *start_pass;
    void (*color_convert)(struct ts4l_jcomp *cinfo, unsigned char **input_buf, unsigned char ***output_buf,
                          unsigned int output_row, int num_rows);
};

struct ts4l_cdownsample {
    void *start_pass;
    void (*downsample)(struct ts4l_jcomp *cinfo, unsigned char ***input_buf, unsigned int in_row_index,
                       unsigned char ***output_buf, unsigned int out_row_group_index);
};

extern void ts4l_jpeg_jcopy_sample_rows_8344EF30(unsigned char **input_array, int source_row, unsigned char **output_array,
                        int dest_row, int num_rows, unsigned int num_cols);

#define J(c) TS4L_J(c)

static void expand_bottom_edge(unsigned char **image_data, unsigned int num_cols, int input_rows,
                               int output_rows)
{
    int row;

    for (row = input_rows; row < output_rows; row++)
        ts4l_jpeg_jcopy_sample_rows_8344EF30(image_data, input_rows - 1, image_data, row, 1, num_cols);
}

void ts4l_jpeg_pre_process_data_83460B00(struct ts4l_jcomp *cinfo, unsigned char **input_buf,
                                        unsigned int *in_row_ctr, unsigned int in_rows_avail,
                                        unsigned char ***output_buf, unsigned int *out_row_group_ctr,
                                        unsigned int out_row_groups_avail)
{
    struct ts4l_cprep_ctl *prep = (struct ts4l_cprep_ctl *)cinfo->prep;
    int numrows, ci;
    unsigned int inrows;
    struct ts4l_jpeg_component_info *compptr;

    while (*in_row_ctr < in_rows_avail && *out_row_group_ctr < out_row_groups_avail) {
        inrows = in_rows_avail - *in_row_ctr;
        numrows = cinfo->max_v_samp_factor - prep->next_buf_row;
        numrows = (int)((unsigned int)numrows < inrows ? (unsigned int)numrows : inrows);
        (*((struct ts4l_cconvert *)cinfo->cconvert)->color_convert)(
            cinfo, input_buf + *in_row_ctr, prep->color_buf, (unsigned int)prep->next_buf_row, numrows);
        *in_row_ctr += numrows;
        prep->next_buf_row += numrows;
        prep->rows_to_go -= numrows;
        if (prep->rows_to_go == 0 && prep->next_buf_row < cinfo->max_v_samp_factor) {
            for (ci = 0; ci < cinfo->num_components; ci++) {
                expand_bottom_edge(prep->color_buf[ci], cinfo->image_width, prep->next_buf_row,
                                   cinfo->max_v_samp_factor);
            }
            prep->next_buf_row = cinfo->max_v_samp_factor;
        }
        if (prep->next_buf_row == cinfo->max_v_samp_factor) {
            (*((struct ts4l_cdownsample *)cinfo->downsample)->downsample)(cinfo, prep->color_buf, 0,
                                                                          output_buf, *out_row_group_ctr);
            prep->next_buf_row = 0;
            (*out_row_group_ctr)++;
        }
        if (prep->rows_to_go == 0 && *out_row_group_ctr < out_row_groups_avail) {
            for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
                expand_bottom_edge(output_buf[ci], compptr->width_in_blocks * 8,
                                   (int)(*out_row_group_ctr * compptr->v_samp_factor),
                                   (int)(out_row_groups_avail * compptr->v_samp_factor));
            }
            *out_row_group_ctr = out_row_groups_avail;
            break;
        }
    }
}

void ts4l_jpeg_pre_process_context_83460D38(struct ts4l_jcomp *cinfo, unsigned char **input_buf,
                                           unsigned int *in_row_ctr, unsigned int in_rows_avail,
                                           unsigned char ***output_buf, unsigned int *out_row_group_ctr,
                                           unsigned int out_row_groups_avail)
{
    struct ts4l_cprep_ctl *prep = (struct ts4l_cprep_ctl *)cinfo->prep;
    int numrows, ci;
    int buf_height = cinfo->max_v_samp_factor * 3;
    unsigned int inrows;
    int row;

    while (*out_row_group_ctr < out_row_groups_avail) {
        if (*in_row_ctr < in_rows_avail) {
            inrows = in_rows_avail - *in_row_ctr;
            numrows = prep->next_buf_stop - prep->next_buf_row;
            numrows = (int)((unsigned int)numrows < inrows ? (unsigned int)numrows : inrows);
            (*((struct ts4l_cconvert *)cinfo->cconvert)->color_convert)(
                cinfo, input_buf + *in_row_ctr, prep->color_buf, (unsigned int)prep->next_buf_row, numrows);
            if (prep->rows_to_go == cinfo->image_height) {
                for (ci = 0; ci < cinfo->num_components; ci++) {
                    for (row = 1; row <= cinfo->max_v_samp_factor; row++) {
                        ts4l_jpeg_jcopy_sample_rows_8344EF30(prep->color_buf[ci], 0, prep->color_buf[ci], -row, 1, cinfo->image_width);
                    }
                }
            }
            *in_row_ctr += numrows;
            prep->next_buf_row += numrows;
            prep->rows_to_go -= numrows;
        } else {
            if (prep->rows_to_go != 0)
                break;
            if (prep->next_buf_row < prep->next_buf_stop) {
                for (ci = 0; ci < cinfo->num_components; ci++) {
                    expand_bottom_edge(prep->color_buf[ci], cinfo->image_width, prep->next_buf_row,
                                       prep->next_buf_stop);
                }
                prep->next_buf_row = prep->next_buf_stop;
            }
        }
        if (prep->next_buf_row == prep->next_buf_stop) {
            (*((struct ts4l_cdownsample *)cinfo->downsample)->downsample)(
                cinfo, prep->color_buf, (unsigned int)prep->this_row_group, output_buf, *out_row_group_ctr);
            (*out_row_group_ctr)++;
            prep->this_row_group += cinfo->max_v_samp_factor;
            if (prep->this_row_group >= buf_height)
                prep->this_row_group = 0;
            if (prep->next_buf_row >= buf_height)
                prep->next_buf_row = 0;
            prep->next_buf_stop = prep->next_buf_row + cinfo->max_v_samp_factor;
        }
    }
}
