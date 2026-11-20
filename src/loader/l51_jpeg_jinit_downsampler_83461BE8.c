/* Loader_DLL.xex 0x83461BE8-0x83461E30, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcsample.c): jinit_downsampler. */
#include "l44_jpeg.h"

struct ts4l_cdownsampler {
    void *start_pass;      /* 0x00 */
    void *downsample;      /* 0x04 */
    int need_context_rows; /* 0x08 */
    void *methods[10];     /* 0x0c */
};

extern void ts4_fn_83461200(void);
extern void ts4l_jpeg_sep_downsample_83461250(void);
extern void fn_83461978(void);
extern void ts4l_jpeg_fullsize_downsample_83461478(void);
extern void ts4l_jpeg_h2v1_downsample_83461B10(void);
extern void fn_834616C8(void);
extern void ts4_tailcall_fn_834615D8_83461BE0(void);
extern void ts4l_jpeg_int_downsample_834612E0(void);

#define J(c) TS4L_J(c)

void ts4l_jpeg_jinit_downsampler_83461BE8(struct ts4l_jcomp *cinfo)
{
    struct ts4l_cdownsampler *downsample;
    int ci;
    struct ts4l_jpeg_component_info *compptr;
    int smoothok = 1;

    downsample = (struct ts4l_cdownsampler *)(*cinfo->mem->alloc_small)(J(cinfo), 1, sizeof(*downsample));
    cinfo->downsample = downsample;
    downsample->start_pass = (void *)ts4_fn_83461200;
    downsample->downsample = (void *)ts4l_jpeg_sep_downsample_83461250;
    downsample->need_context_rows = 0;

    if (cinfo->CCIR601_sampling)
        TS4L_CERREXIT(cinfo, 0x19);

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        if (compptr->h_samp_factor == cinfo->max_h_samp_factor &&
            compptr->v_samp_factor == cinfo->max_v_samp_factor) {
            if (cinfo->smoothing_factor) {
                downsample->methods[ci] = (void *)fn_83461978;
                downsample->need_context_rows = 1;
            } else {
                downsample->methods[ci] = (void *)ts4l_jpeg_fullsize_downsample_83461478;
            }
        } else if (compptr->h_samp_factor * 2 == cinfo->max_h_samp_factor &&
                   compptr->v_samp_factor == cinfo->max_v_samp_factor) {
            smoothok = 0;
            downsample->methods[ci] = (void *)ts4l_jpeg_h2v1_downsample_83461B10;
        } else if (compptr->h_samp_factor * 2 == cinfo->max_h_samp_factor &&
                   compptr->v_samp_factor * 2 == cinfo->max_v_samp_factor) {
            if (cinfo->smoothing_factor) {
                downsample->methods[ci] = (void *)fn_834616C8;
                downsample->need_context_rows = 1;
            } else {
                downsample->methods[ci] = (void *)ts4_tailcall_fn_834615D8_83461BE0;
            }
        } else if ((cinfo->max_h_samp_factor % compptr->h_samp_factor) == 0 &&
                   (cinfo->max_v_samp_factor % compptr->v_samp_factor) == 0) {
            smoothok = 0;
            downsample->methods[ci] = (void *)ts4l_jpeg_int_downsample_834612E0;
        } else {
            TS4L_CERREXIT(cinfo, 0x26);
        }
    }

    if (cinfo->smoothing_factor && !smoothok) {
        cinfo->err->msg_code = 0x63;
        (*cinfo->err->emit_message)(cinfo, 0);
    }
}
