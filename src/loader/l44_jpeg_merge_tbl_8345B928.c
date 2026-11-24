/* Loader_DLL.xex 0x8345B928-0x8345BA44, executable version 0.0.0.3. */
/* Library routine: libjpeg jdmerge.c build_ycc_rgb_table. */
#include "l44_jpeg.h"

struct ts4l_merged_upsample {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo);   /* 0x00 */
    void *upsample;                                       /* 0x04 */
    int need_context_rows;                                /* 0x08 */
    void *upmethod;                                       /* 0x0c */
    int *Cr_r_tab;                                        /* 0x10 */
    int *Cb_b_tab;                                        /* 0x14 */
    long *Cr_g_tab;                                       /* 0x18 */
    long *Cb_g_tab;                                       /* 0x1c */
};

void ts4l_jpeg_merge_build_ycc_rgb_table_8345B928(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_merged_upsample *upsample = (struct ts4l_merged_upsample *)cinfo->upsample;
    int i;
    long x;

    upsample->Cr_r_tab = (int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    upsample->Cb_b_tab = (int *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(int));
    upsample->Cr_g_tab = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(long));
    upsample->Cb_g_tab = (long *)(*cinfo->mem->alloc_small)(cinfo, 1, 256 * sizeof(long));

    for (i = 0, x = -128; i <= 255; i++, x++) {
        upsample->Cr_r_tab[i] = (int)((91881L * x + 32768L) >> 16);
        upsample->Cb_b_tab[i] = (int)((116130L * x + 32768L) >> 16);
        upsample->Cr_g_tab[i] = (-46802L) * x;
        upsample->Cb_g_tab[i] = (-22554L) * x + 32768L;
    }
}
