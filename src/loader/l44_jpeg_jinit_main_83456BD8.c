/* Loader_DLL.xex 0x83456BD8-0x83456D18, executable version 0.0.0.3. */
/* Library routine: libjpeg jdmainct.c jinit_d_main_controller. */
#include "l44_jpeg.h"

extern void ts4l_if_get_u32_off1ac_83456B38(struct ts4l_jpeg_decomp *cinfo, int pass_mode);
struct ts4l_main_ctl {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo, int pass_mode);
    void *process_data;
    void **buffer[10];
    int rest[8];
};

extern void fn_834564F0(struct ts4l_jpeg_decomp *cinfo);

void ts4l_jpeg_jinit_d_main_controller_83456BD8(struct ts4l_jpeg_decomp *cinfo, int need_full_buffer)
{
    struct ts4l_main_ctl *main;
    int ci, rgroup, ngroups;
    struct ts4l_jpeg_component_info *compptr;

    main = (struct ts4l_main_ctl *)(*cinfo->mem->alloc_small)(cinfo, 1, 0x50);
    cinfo->main = (struct ts4l_jpeg_d_main *)main;
    main->start_pass = ts4l_if_get_u32_off1ac_83456B38;

    if (need_full_buffer)
        TS4L_ERREXIT(cinfo, 4);

    if (cinfo->upsample->need_context_rows) {
        if (cinfo->min_DCT_scaled_size < 2)
            TS4L_ERREXIT(cinfo, 47);
        fn_834564F0(cinfo);
        ngroups = cinfo->min_DCT_scaled_size + 2;
    } else {
        ngroups = cinfo->min_DCT_scaled_size;
    }

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        rgroup = (compptr->v_samp_factor * compptr->DCT_scaled_size) / cinfo->min_DCT_scaled_size;
        main->buffer[ci] = (void **)(*cinfo->mem->alloc_sarray)(
            cinfo, 1, compptr->width_in_blocks * compptr->DCT_scaled_size, (unsigned int)(rgroup * ngroups));
    }
}
