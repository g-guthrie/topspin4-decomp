/* Loader_DLL.xex 0x8345BB68-0x8345BBD4, executable version 0.0.0.3.
 * Statically linked libjpeg 6b routines. */

#include "l21_jp1_jpeg_8344E498.h"

struct ts4l_jpeg_my_merged_upsampler;
typedef void (*ts4l_jpeg_merged_upmethod)(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                         ts4l_jdim in_row_group_ctr, ts4l_jsamparray output_buf);

/* Merged upsampler private state (jdmerge.c my_upsampler). */
struct ts4l_jpeg_my_merged_upsampler {
    struct ts4l_jpeg_upsampler pub;       /* 0x00 */
    ts4l_jpeg_merged_upmethod upmethod;   /* 0x0c */
    int *Cr_r_tab;                       /* 0x10 */
    int *Cb_b_tab;                       /* 0x14 */
    long *Cr_g_tab;                      /* 0x18 */
    long *Cb_g_tab;                      /* 0x1c */
    ts4l_jsamprow spare_row;              /* 0x20 */
    int spare_full;                      /* 0x24 */
    ts4l_jdim out_row_width;              /* 0x28 */
    ts4l_jdim rows_to_go;                 /* 0x2c */
};

#define TS4L_SCALEBITS 16
#define TS4L_ONE_HALF ((long)1 << (TS4L_SCALEBITS - 1))
#define TS4L_FIX_1_40200 91881L
#define TS4L_FIX_1_77200 116130L
#define TS4L_FIX_0_71414 46802L
#define TS4L_FIX_0_34414 22554L

/* Copies rows of samples (jutils.c jcopy_sample_rows). */
/* start_pass_merged_upsample. */
/* Linker thunk that forwards to h2v2_merged_upsample. */




/* Upsample and convert one row at a time */
void ts4l_jpeg_merged_1v_upsample_8345BB68(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                                          ts4l_jdim *in_row_group_ctr, ts4l_jdim in_row_groups_avail,
                                          ts4l_jsamparray output_buf, ts4l_jdim *out_row_ctr,
                                          ts4l_jdim out_rows_avail)
{
    struct ts4l_jpeg_my_merged_upsampler *upsample = (struct ts4l_jpeg_my_merged_upsampler *)cinfo->upsample;

    (void)in_row_groups_avail;
    (void)out_rows_avail;
    (*upsample->upmethod)(cinfo, input_buf, *in_row_group_ctr, output_buf + *out_row_ctr);
    (*out_row_ctr)++;
    (*in_row_group_ctr)++;
}



