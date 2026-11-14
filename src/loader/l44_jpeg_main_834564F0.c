/* Loader_DLL.xex 0x834564F0-0x83456BD8, executable version 0.0.0.3. */
/* Library routines: libjpeg jdmainct.c (alloc_funny_pointers, make_funny_pointers,
   set_wraparound_pointers, set_bottom_pointers, process_data_simple_main,
   process_data_context_main). */
#include "l44_jpeg.h"

typedef struct ts4l_my_main {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo, int pass_mode);  /* 0x00 */
    void (*process_data)(struct ts4l_jpeg_decomp *cinfo, void *output_buf, unsigned int *out_row_ctr,
                         unsigned int out_rows_avail);                  /* 0x04 */
    void **buffer[10];                                                  /* 0x08 */
    int buffer_full;                                                    /* 0x30 */
    unsigned int rowgroup_ctr;                                          /* 0x34 */
    void ***xbuffer[2];                                                 /* 0x38 */
    int whichptr;                                                       /* 0x40 */
    int context_state;                                                  /* 0x44 */
    unsigned int rowgroups_avail;                                       /* 0x48 */
    unsigned int iMCU_row_ctr;                                          /* 0x4c */
} ts4l_my_main;

void ts4l_jpeg_alloc_funny_pointers_834564F0(struct ts4l_jpeg_decomp *cinfo)
{
    ts4l_my_main *main = (ts4l_my_main *)cinfo->main;
    int ci, rgroup;
    int M = cinfo->min_DCT_scaled_size;
    struct ts4l_jpeg_component_info *compptr;
    void **xbuf;

    main->xbuffer[0] = (void ***)(*cinfo->mem->alloc_small)(cinfo, 1, 2 * cinfo->num_components * 4);
    main->xbuffer[1] = main->xbuffer[0] + cinfo->num_components;

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        rgroup = (compptr->v_samp_factor * compptr->DCT_scaled_size) / cinfo->min_DCT_scaled_size;
        xbuf = (void **)(*cinfo->mem->alloc_small)(cinfo, 1, 2 * (rgroup * (M + 4)) * 4);
        xbuf += rgroup;
        main->xbuffer[0][ci] = xbuf;
        xbuf += rgroup * (M + 4);
        main->xbuffer[1][ci] = xbuf;
    }
}

void ts4l_jpeg_make_funny_pointers_834565E0(struct ts4l_jpeg_decomp *cinfo)
{
    ts4l_my_main *main = (ts4l_my_main *)cinfo->main;
    int ci, i, rgroup;
    int M = cinfo->min_DCT_scaled_size;
    struct ts4l_jpeg_component_info *compptr;
    void **buf, **xbuf0, **xbuf1;

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        rgroup = (compptr->v_samp_factor * compptr->DCT_scaled_size) / cinfo->min_DCT_scaled_size;
        xbuf0 = main->xbuffer[0][ci];
        xbuf1 = main->xbuffer[1][ci];
        buf = main->buffer[ci];
        for (i = 0; i < rgroup * (M + 2); i++) {
            xbuf0[i] = xbuf1[i] = buf[i];
        }
        for (i = 0; i < rgroup * 2; i++) {
            xbuf1[rgroup * (M - 2) + i] = buf[rgroup * M + i];
            xbuf1[rgroup * M + i] = buf[rgroup * (M - 2) + i];
        }
        for (i = 0; i < rgroup; i++) {
            xbuf0[i - rgroup] = xbuf0[0];
        }
    }
}

void ts4l_jpeg_set_wraparound_pointers_83456708(struct ts4l_jpeg_decomp *cinfo)
{
    ts4l_my_main *main = (ts4l_my_main *)cinfo->main;
    int ci, i, rgroup;
    int M = cinfo->min_DCT_scaled_size;
    struct ts4l_jpeg_component_info *compptr;
    void **xbuf0, **xbuf1;

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        rgroup = (compptr->v_samp_factor * compptr->DCT_scaled_size) / cinfo->min_DCT_scaled_size;
        xbuf0 = main->xbuffer[0][ci];
        xbuf1 = main->xbuffer[1][ci];
        for (i = 0; i < rgroup; i++) {
            xbuf0[i - rgroup] = xbuf0[rgroup * (M + 1) + i];
            xbuf1[i - rgroup] = xbuf1[rgroup * (M + 1) + i];
            xbuf0[rgroup * (M + 2) + i] = xbuf0[i];
            xbuf1[rgroup * (M + 2) + i] = xbuf1[i];
        }
    }
}

void ts4l_jpeg_set_bottom_pointers_834567F8(struct ts4l_jpeg_decomp *cinfo)
{
    ts4l_my_main *main = (ts4l_my_main *)cinfo->main;
    int ci, i, rgroup, iMCUheight, rows_left;
    struct ts4l_jpeg_component_info *compptr;
    void **xbuf;

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        iMCUheight = compptr->v_samp_factor * compptr->DCT_scaled_size;
        rgroup = iMCUheight / cinfo->min_DCT_scaled_size;
        rows_left = (int)(compptr->downsampled_height % (unsigned int)iMCUheight);
        if (rows_left == 0)
            rows_left = iMCUheight;
        if (ci == 0) {
            main->rowgroups_avail = (unsigned int)((rows_left - 1) / rgroup + 1);
        }
        xbuf = main->xbuffer[main->whichptr][ci];
        for (i = 0; i < rgroup * 2; i++) {
            xbuf[rows_left + i] = xbuf[rows_left - 1];
        }
    }
}

void ts4l_jpeg_process_data_simple_main_834568E8(struct ts4l_jpeg_decomp *cinfo, void *output_buf,
                                                 unsigned int *out_row_ctr, unsigned int out_rows_avail)
{
    ts4l_my_main *main = (ts4l_my_main *)cinfo->main;
    unsigned int min_dct;

    if (!main->buffer_full) {
        if (!(*cinfo->coef->decompress_data)(cinfo, (ts4l_jsampimage)main->buffer))
            return;
        main->buffer_full = 1;
    }

    min_dct = (unsigned int)cinfo->min_DCT_scaled_size;
    (*cinfo->post->post_process_data)(cinfo, (ts4l_jsampimage)main->buffer, &main->rowgroup_ctr,
                                      min_dct, (ts4l_jsamparray)output_buf,
                                      out_row_ctr, out_rows_avail);

    if (main->rowgroup_ctr >= min_dct) {
        main->buffer_full = 0;
        main->rowgroup_ctr = 0;
    }
}

void ts4l_jpeg_process_data_context_main_83456990(struct ts4l_jpeg_decomp *cinfo, void *output_buf,
                                                  unsigned int *out_row_ctr, unsigned int out_rows_avail)
{
    ts4l_my_main *main = (ts4l_my_main *)cinfo->main;

    if (!main->buffer_full) {
        if (!(*cinfo->coef->decompress_data)(cinfo, (ts4l_jsampimage)main->xbuffer[main->whichptr]))
            return;
        main->buffer_full = 1;
        main->iMCU_row_ctr++;
    }

    switch (main->context_state) {
    case 2:
        (*cinfo->post->post_process_data)(cinfo, (ts4l_jsampimage)main->xbuffer[main->whichptr],
                                          &main->rowgroup_ctr, main->rowgroups_avail,
                                          (ts4l_jsamparray)output_buf, out_row_ctr, out_rows_avail);
        if (main->rowgroup_ctr < main->rowgroups_avail)
            return;
        main->context_state = 0;
        if (*out_row_ctr >= out_rows_avail)
            return;
        /* FALLTHROUGH */
    case 0:
        main->rowgroup_ctr = 0;
        main->rowgroups_avail = (unsigned int)(cinfo->min_DCT_scaled_size - 1);
        if (main->iMCU_row_ctr == cinfo->total_iMCU_rows)
            ts4l_jpeg_set_bottom_pointers_834567F8(cinfo);
        main->context_state = 1;
        /* FALLTHROUGH */
    case 1:
        (*cinfo->post->post_process_data)(cinfo, (ts4l_jsampimage)main->xbuffer[main->whichptr],
                                          &main->rowgroup_ctr, main->rowgroups_avail,
                                          (ts4l_jsamparray)output_buf, out_row_ctr, out_rows_avail);
        if (main->rowgroup_ctr < main->rowgroups_avail)
            return;
        if (main->iMCU_row_ctr == 1)
            ts4l_jpeg_set_wraparound_pointers_83456708(cinfo);
        main->whichptr ^= 1;
        main->buffer_full = 0;
        main->rowgroup_ctr = (unsigned int)(cinfo->min_DCT_scaled_size + 1);
        main->rowgroups_avail = (unsigned int)(cinfo->min_DCT_scaled_size + 2);
        main->context_state = 2;
    }
}
