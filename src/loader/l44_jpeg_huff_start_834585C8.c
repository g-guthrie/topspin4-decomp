/* Loader_DLL.xex 0x834585C8-0x8345866C, 0x83458B48-0x83458CE8, executable version 0.0.0.3. */
/* Library routines: libjpeg jdhuff.c (process_restart, start_pass_huff_decoder). */
#include "l44_jpeg.h"

extern void ts4l_jpeg_make_d_derived_tbl_83457FD0(struct ts4l_jpeg_decomp *cinfo, int isDC, int tblno,
                        struct ts4l_jpeg_d_derived_tbl **pdtbl);

int ts4l_jpeg_process_restart_834585C8(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_jpeg_huff_entropy *entropy = (struct ts4l_jpeg_huff_entropy *)cinfo->entropy;
    int ci;

    cinfo->marker->discarded_bytes += entropy->bitstate.bits_left / 8;
    entropy->bitstate.bits_left = 0;

    if (!(*cinfo->marker->read_restart_marker)(cinfo))
        return 0;

    for (ci = 0; ci < cinfo->comps_in_scan; ci++)
        entropy->last_dc_val[ci] = 0;

    entropy->restarts_to_go = cinfo->restart_interval;

    if (cinfo->unread_marker == 0)
        entropy->insufficient_data = 0;

    return 1;
}

void ts4l_jpeg_start_pass_huff_decoder_83458B48(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_jpeg_huff_entropy *entropy = (struct ts4l_jpeg_huff_entropy *)cinfo->entropy;
    int ci, blkn, dctbl, actbl;
    struct ts4l_jpeg_component_info *compptr;

    if (cinfo->Ss != 0 || cinfo->Se != 63 || cinfo->Ah != 0 || cinfo->Al != 0)
        TS4L_WARNMS(cinfo, 122);

    for (ci = 0; ci < cinfo->comps_in_scan; ci++) {
        compptr = cinfo->cur_comp_info[ci];
        dctbl = compptr->dc_tbl_no;
        actbl = compptr->ac_tbl_no;
        ts4l_jpeg_make_d_derived_tbl_83457FD0(cinfo, 1, dctbl, &entropy->dc_derived_tbls[dctbl]);
        ts4l_jpeg_make_d_derived_tbl_83457FD0(cinfo, 0, actbl, &entropy->ac_derived_tbls[actbl]);
        entropy->last_dc_val[ci] = 0;
    }

    for (blkn = 0; blkn < cinfo->blocks_in_MCU; blkn++) {
        ci = cinfo->MCU_membership[blkn];
        compptr = cinfo->cur_comp_info[ci];
        entropy->dc_cur_tbls[blkn] = entropy->dc_derived_tbls[compptr->dc_tbl_no];
        entropy->ac_cur_tbls[blkn] = entropy->ac_derived_tbls[compptr->ac_tbl_no];
        if (compptr->component_needed) {
            entropy->dc_needed[blkn] = 1;
            entropy->ac_needed[blkn] = (compptr->DCT_scaled_size > 1);
        } else {
            entropy->ac_needed[blkn] = 0;
            entropy->dc_needed[blkn] = 0;
        }
    }

    entropy->bitstate.bits_left = 0;
    entropy->bitstate.get_buffer = 0;
    entropy->insufficient_data = 0;

    entropy->restarts_to_go = cinfo->restart_interval;
}
