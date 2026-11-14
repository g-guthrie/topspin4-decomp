/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG decompression main buffer controller, IJG jdmainct.c style. (JP1) */
#include "jp1_jpeg.h"

enum { JP1_JERR_BAD_BUFFER_MODE = 0x04, JP1_JERR_NOTIMPL = 0x2f };
enum { CTX_PREPARE_FOR_IMCU = 0, CTX_PROCESS_IMCU = 1, CTX_POSTPONED_ROW = 2 };

struct ts4_jpeg_my_main {
    struct ts4_jpeg_d_main pub; /* 0x00 */
    ts4_jsamparray buffer[10];  /* 0x08 */
    int buffer_full;            /* 0x30 */
    ts4_jdim rowgroup_ctr;      /* 0x34 */
    ts4_jsampimage xbuffer[2];  /* 0x38 */
    int whichptr;               /* 0x40 */
    int context_state;          /* 0x44 */
    ts4_jdim rowgroups_avail;   /* 0x48 */
    ts4_jdim iMCU_row_ctr;      /* 0x4c */
};

void ts4_if_get_u32_off1ac_882F5A90(struct ts4_jpeg_decomp *cinfo, int pass_mode); /* start_pass_main */

/* Allocates the two context-row pointer lists per component (Swing_DLL.xex 0x882F5448). */
void ts4_jpeg_alloc_funny_pointers_882F5448(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_my_main *main = (struct ts4_jpeg_my_main *)cinfo->main;
    int ci, rgroup;
    int M = cinfo->min_DCT_scaled_size;
    struct ts4_jpeg_component_info *compptr;
    ts4_jsamparray xbuf;

    main->xbuffer[0] = (ts4_jsampimage)(*cinfo->mem->alloc_small)(
        cinfo, 1, cinfo->num_components * 2 * sizeof(ts4_jsamparray));
    main->xbuffer[1] = main->xbuffer[0] + cinfo->num_components;
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        rgroup = (compptr->v_samp_factor * compptr->DCT_scaled_size) / cinfo->min_DCT_scaled_size;
        xbuf = (ts4_jsamparray)(*cinfo->mem->alloc_small)(
            cinfo, 1, 2 * (rgroup * (M + 4)) * sizeof(ts4_jsamprow));
        xbuf += rgroup;
        main->xbuffer[0][ci] = xbuf;
        xbuf += rgroup * (M + 4);
        main->xbuffer[1][ci] = xbuf;
    }
}

/* Builds the two pointer lists so context rows alias the real buffer rows
 * (Swing_DLL.xex 0x882F5538). */
void ts4_jpeg_make_funny_pointers_882F5538(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_my_main *main = (struct ts4_jpeg_my_main *)cinfo->main;
    int ci, i, rgroup;
    int M = cinfo->min_DCT_scaled_size;
    struct ts4_jpeg_component_info *compptr;
    ts4_jsamparray buf, xbuf0, xbuf1;

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

/* Points the top context rows at the bottom ones for the wrap-around iMCU rows
 * (Swing_DLL.xex 0x882F5660). */
void ts4_jpeg_set_wraparound_pointers_882F5660(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_my_main *main = (struct ts4_jpeg_my_main *)cinfo->main;
    int ci, i, rgroup;
    int M = cinfo->min_DCT_scaled_size;
    struct ts4_jpeg_component_info *compptr;
    ts4_jsamparray xbuf0, xbuf1;

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

/* Replicates the last real sample row below the image bottom (Swing_DLL.xex 0x882F5750). */
void ts4_jpeg_set_bottom_pointers_882F5750(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_my_main *main = (struct ts4_jpeg_my_main *)cinfo->main;
    int ci, i, rgroup, iMCUheight, rows_left;
    struct ts4_jpeg_component_info *compptr;
    ts4_jsamparray xbuf;

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        iMCUheight = compptr->v_samp_factor * compptr->DCT_scaled_size;
        rgroup = iMCUheight / cinfo->min_DCT_scaled_size;
        rows_left = (int)(compptr->downsampled_height % (ts4_jdim)iMCUheight);
        if (rows_left == 0)
            rows_left = iMCUheight;
        if (ci == 0) {
            main->rowgroups_avail = (ts4_jdim)((rows_left - 1) / rgroup + 1);
        }
        xbuf = main->xbuffer[main->whichptr][ci];
        for (i = 0; i < rgroup * 2; i++) {
            xbuf[rows_left + i] = xbuf[rows_left - 1];
        }
    }
}

/* Main-buffer pass-through for the no-context case (Swing_DLL.xex 0x882F5840). */
void ts4_jpeg_process_data_simple_main_882F5840(struct ts4_jpeg_decomp *cinfo,
                                                ts4_jsamparray output_buf, ts4_jdim *out_row_ctr,
                                                ts4_jdim out_rows_avail)
{
    struct ts4_jpeg_my_main *main = (struct ts4_jpeg_my_main *)cinfo->main;

    if (!main->buffer_full) {
        if (!(*cinfo->coef->decompress_data)(cinfo, (ts4_jsampimage)main->buffer))
            return;
        main->buffer_full = 1;
    }
    {
        ts4_jdim ngroups = (ts4_jdim)cinfo->min_DCT_scaled_size;
        (*cinfo->post->post_process_data)(cinfo, (ts4_jsampimage)main->buffer,
                                          &main->rowgroup_ctr, ngroups, output_buf, out_row_ctr,
                                          out_rows_avail);
        if (main->rowgroup_ctr >= ngroups) {
            main->buffer_full = 0;
            main->rowgroup_ctr = 0;
        }
    }
}

/* Main-buffer processing with context rows for fancy upsampling (Swing_DLL.xex 0x882F58E8). */
void ts4_jpeg_process_data_context_main_882F58E8(struct ts4_jpeg_decomp *cinfo,
                                                 ts4_jsamparray output_buf, ts4_jdim *out_row_ctr,
                                                 ts4_jdim out_rows_avail)
{
    struct ts4_jpeg_my_main *main = (struct ts4_jpeg_my_main *)cinfo->main;

    if (!main->buffer_full) {
        if (!(*cinfo->coef->decompress_data)(cinfo, main->xbuffer[main->whichptr]))
            return;
        main->buffer_full = 1;
        main->iMCU_row_ctr++;
    }
    switch (main->context_state) {
    case CTX_POSTPONED_ROW:
        (*cinfo->post->post_process_data)(cinfo, main->xbuffer[main->whichptr],
                                          &main->rowgroup_ctr, main->rowgroups_avail, output_buf,
                                          out_row_ctr, out_rows_avail);
        if (main->rowgroup_ctr < main->rowgroups_avail)
            return;
        main->context_state = CTX_PREPARE_FOR_IMCU;
        if (*out_row_ctr >= out_rows_avail)
            return;
        /* fall through */
    case CTX_PREPARE_FOR_IMCU:
        main->rowgroup_ctr = 0;
        main->rowgroups_avail = (ts4_jdim)(cinfo->min_DCT_scaled_size - 1);
        if (main->iMCU_row_ctr == cinfo->total_iMCU_rows)
            ts4_jpeg_set_bottom_pointers_882F5750(cinfo);
        main->context_state = CTX_PROCESS_IMCU;
        /* fall through */
    case CTX_PROCESS_IMCU:
        (*cinfo->post->post_process_data)(cinfo, main->xbuffer[main->whichptr],
                                          &main->rowgroup_ctr, main->rowgroups_avail, output_buf,
                                          out_row_ctr, out_rows_avail);
        if (main->rowgroup_ctr < main->rowgroups_avail)
            return;
        if (main->iMCU_row_ctr == 1)
            ts4_jpeg_set_wraparound_pointers_882F5660(cinfo);
        main->whichptr ^= 1;
        main->buffer_full = 0;
        main->rowgroup_ctr = (ts4_jdim)(cinfo->min_DCT_scaled_size + 1);
        main->rowgroups_avail = (ts4_jdim)(cinfo->min_DCT_scaled_size + 2);
        main->context_state = CTX_POSTPONED_ROW;
    }
}

/* Creates the main buffer controller and its sample buffers (Swing_DLL.xex 0x882F5B30). */
void ts4_jpeg_jinit_d_main_controller_882F5B30(struct ts4_jpeg_decomp *cinfo, int need_full_buffer)
{
    struct ts4_jpeg_my_main *main;
    int ci, rgroup, ngroups;
    struct ts4_jpeg_component_info *compptr;

    main = (struct ts4_jpeg_my_main *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(*main));
    cinfo->main = &main->pub;
    main->pub.start_pass = ts4_if_get_u32_off1ac_882F5A90;
    if (need_full_buffer)
        JP1_ERREXIT(cinfo, JP1_JERR_BAD_BUFFER_MODE);
    if (cinfo->upsample->need_context_rows) {
        if (cinfo->min_DCT_scaled_size < 2)
            JP1_ERREXIT(cinfo, JP1_JERR_NOTIMPL);
        ts4_jpeg_alloc_funny_pointers_882F5448(cinfo);
        ngroups = cinfo->min_DCT_scaled_size + 2;
    } else {
        ngroups = cinfo->min_DCT_scaled_size;
    }
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        rgroup = (compptr->v_samp_factor * compptr->DCT_scaled_size) / cinfo->min_DCT_scaled_size;
        main->buffer[ci] = (*cinfo->mem->alloc_sarray)(
            cinfo, 1, compptr->width_in_blocks * compptr->DCT_scaled_size,
            (ts4_jdim)(rgroup * ngroups));
    }
}
