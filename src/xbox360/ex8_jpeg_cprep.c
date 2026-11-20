/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b compression preprocessing controller (jcprepct.c). */
#include "ex8_jpeg.h"

void ts4_jpeg_jcopy_sample_rows_882EE8A0(ex8_jsamparray input_array, int source_row, ex8_jsamparray output_array, int dest_row,
                 int num_rows, unsigned int num_cols); /* jcopy_sample_rows */

void ts4_if_get_u32_off15c_882FF670(ex8_jcomp *cinfo, int pass_mode); /* start_pass_prep */

typedef struct ex8_prep_priv {
    ex8_jcprep pub;                     /* 0x00 */
    ex8_jsamparray color_buf[10];       /* 0x08 */
    unsigned int rows_to_go;            /* 0x30 */
    int next_buf_row;                   /* 0x34 */
    int this_row_group;                 /* 0x38 */
    int next_buf_stop;                  /* 0x3c */
} ex8_prep_priv;

/* Replicates the last real row into the rows below it. */
static void ex8_expand_bottom_edge(ex8_jsamparray image_data, unsigned int num_cols, int input_rows,
                                   int output_rows)
{
    int row;

    for (row = input_rows; row < output_rows; row++)
        ts4_jpeg_jcopy_sample_rows_882EE8A0(image_data, input_rows - 1, image_data, row, 1, num_cols);
}

/* Color-converts input rows and feeds the downsampler a row group at a time. */
void ex8_pre_process_data_882FF6E8(ex8_jcomp *cinfo, ex8_jsamparray input_buf, unsigned int *in_row_ctr,
                                   unsigned int in_rows_avail, ex8_jsamparray *output_buf,
                                   unsigned int *out_row_group_ctr, unsigned int out_row_groups_avail)
{
    ex8_prep_priv *prep = (ex8_prep_priv *)cinfo->prep;
    int numrows, ci;
    unsigned int inrows;
    ex8_jcinfo *compptr;

    while (*in_row_ctr < in_rows_avail && *out_row_group_ctr < out_row_groups_avail) {
        inrows = in_rows_avail - *in_row_ctr;
        numrows = cinfo->max_v_samp_factor - prep->next_buf_row;
        numrows = (int)((unsigned int)numrows < inrows ? (unsigned int)numrows : inrows);
        (*cinfo->cconvert->color_convert)(cinfo, input_buf + *in_row_ctr, prep->color_buf,
                                          (unsigned int)prep->next_buf_row, numrows);
        *in_row_ctr += numrows;
        prep->next_buf_row += numrows;
        prep->rows_to_go -= numrows;
        if (prep->rows_to_go == 0 && prep->next_buf_row < cinfo->max_v_samp_factor) {
            for (ci = 0; ci < cinfo->num_components; ci++)
                ex8_expand_bottom_edge(prep->color_buf[ci], cinfo->image_width, prep->next_buf_row,
                                       cinfo->max_v_samp_factor);
            prep->next_buf_row = cinfo->max_v_samp_factor;
        }
        if (prep->next_buf_row == cinfo->max_v_samp_factor) {
            (*cinfo->downsample->downsample)(cinfo, prep->color_buf, 0, output_buf, *out_row_group_ctr);
            prep->next_buf_row = 0;
            (*out_row_group_ctr)++;
        }
        if (prep->rows_to_go == 0 && *out_row_group_ctr < out_row_groups_avail) {
            for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
                ex8_expand_bottom_edge(output_buf[ci], compptr->width_in_blocks * 8,
                                       (int)(*out_row_group_ctr * compptr->v_samp_factor),
                                       (int)(out_row_groups_avail * compptr->v_samp_factor));
            }
            *out_row_group_ctr = out_row_groups_avail;
            break;
        }
    }
}

/* Same as pre_process_data, but keeps context rows above and below each row group. */
void ex8_pre_process_context_882FF920(ex8_jcomp *cinfo, ex8_jsamparray input_buf, unsigned int *in_row_ctr,
                                      unsigned int in_rows_avail, ex8_jsamparray *output_buf,
                                      unsigned int *out_row_group_ctr, unsigned int out_row_groups_avail)
{
    ex8_prep_priv *prep = (ex8_prep_priv *)cinfo->prep;
    int numrows, ci;
    int buf_height = cinfo->max_v_samp_factor * 3;
    unsigned int inrows;

    while (*out_row_group_ctr < out_row_groups_avail) {
        if (*in_row_ctr < in_rows_avail) {
            inrows = in_rows_avail - *in_row_ctr;
            numrows = prep->next_buf_stop - prep->next_buf_row;
            numrows = (int)((unsigned int)numrows < inrows ? (unsigned int)numrows : inrows);
            (*cinfo->cconvert->color_convert)(cinfo, input_buf + *in_row_ctr, prep->color_buf,
                                              (unsigned int)prep->next_buf_row, numrows);
            if (prep->rows_to_go == cinfo->image_height) {
                for (ci = 0; ci < cinfo->num_components; ci++) {
                    int row;
                    for (row = 1; row <= cinfo->max_v_samp_factor; row++)
                        ts4_jpeg_jcopy_sample_rows_882EE8A0(prep->color_buf[ci], 0, prep->color_buf[ci], -row, 1, cinfo->image_width);
                }
            }
            *in_row_ctr += numrows;
            prep->next_buf_row += numrows;
            prep->rows_to_go -= numrows;
        } else {
            if (prep->rows_to_go != 0)
                break;
            if (prep->next_buf_row < prep->next_buf_stop) {
                for (ci = 0; ci < cinfo->num_components; ci++)
                    ex8_expand_bottom_edge(prep->color_buf[ci], cinfo->image_width, prep->next_buf_row,
                                           prep->next_buf_stop);
                prep->next_buf_row = prep->next_buf_stop;
            }
        }
        if (prep->next_buf_row == prep->next_buf_stop) {
            (*cinfo->downsample->downsample)(cinfo, prep->color_buf, (unsigned int)prep->this_row_group,
                                             output_buf, *out_row_group_ctr);
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

/* Builds the row-pointer array that wraps the three row groups of context buffer. */
void ex8_create_context_buffer_882FFB78(ex8_jcomp *cinfo)
{
    ex8_prep_priv *prep = (ex8_prep_priv *)cinfo->prep;
    int rgroup_height = cinfo->max_v_samp_factor;
    int ci, i;
    ex8_jcinfo *compptr;
    ex8_jsamparray true_buffer, fake_buffer;

    fake_buffer = (ex8_jsamparray)(*cinfo->mem->alloc_small)(cinfo, 1,
                                                             (cinfo->num_components * 5 * rgroup_height) *
                                                                 sizeof(ex8_jsamprow));

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        true_buffer = (*cinfo->mem->alloc_sarray)(
            cinfo, 1,
            (unsigned int)(((long)compptr->width_in_blocks * 8 * cinfo->max_h_samp_factor) / compptr->h_samp_factor),
            (unsigned int)(3 * rgroup_height));
        memcpy(fake_buffer + rgroup_height, true_buffer, 3 * rgroup_height * sizeof(ex8_jsamprow));
        for (i = 0; i < rgroup_height; i++) {
            fake_buffer[i] = true_buffer[2 * rgroup_height + i];
            fake_buffer[4 * rgroup_height + i] = true_buffer[i];
        }
        prep->color_buf[ci] = fake_buffer + rgroup_height;
        fake_buffer += 5 * rgroup_height;
    }
}

/* Allocates the preprocessing controller and its color conversion buffers. */
void ex8_jinit_c_prep_controller_882FFCC8(ex8_jcomp *cinfo, int need_full_buffer)
{
    ex8_prep_priv *prep;
    int ci;
    ex8_jcinfo *compptr;

    if (need_full_buffer)
        EX8_ERREXIT(cinfo, 4);

    prep = (ex8_prep_priv *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ex8_prep_priv));
    cinfo->prep = &prep->pub;
    prep->pub.start_pass = ts4_if_get_u32_off15c_882FF670;

    if (cinfo->downsample->need_context_rows) {
        prep->pub.pre_process_data = ex8_pre_process_context_882FF920;
        ex8_create_context_buffer_882FFB78(cinfo);
    } else {
        prep->pub.pre_process_data = ex8_pre_process_data_882FF6E8;
        for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
            prep->color_buf[ci] = (*cinfo->mem->alloc_sarray)(
                cinfo, 1,
                (unsigned int)(((long)compptr->width_in_blocks * 8 * cinfo->max_h_samp_factor) /
                               compptr->h_samp_factor),
                (unsigned int)cinfo->max_v_samp_factor);
        }
    }
}
