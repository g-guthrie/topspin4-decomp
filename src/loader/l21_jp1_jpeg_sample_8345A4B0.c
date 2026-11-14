/* Loader_DLL.xex 0x8345A4B0-0x8345AB00, executable version 0.0.0.3.
 * Statically linked libjpeg 6b routines. */

#include "l21_jp1_jpeg_8344E498.h"

void fn_8345A288(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,                                     ts4l_jdim *in_row_group_ctr, ts4l_jdim in_row_groups_avail,                                     ts4l_jsamparray output_buf, ts4l_jdim *out_row_ctr,                                     ts4l_jdim out_rows_avail);
void fn_8345A3D8(struct ts4l_jpeg_decomp *cinfo,                                     struct ts4l_jpeg_component_info *compptr,                                     ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr);
void fn_8345A518(struct ts4l_jpeg_decomp *cinfo,                                      struct ts4l_jpeg_component_info *compptr,                                      ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr);

typedef void (*ts4l_jpeg_upsample1)(struct ts4l_jpeg_decomp *cinfo,
                                   struct ts4l_jpeg_component_info *compptr,
                                   ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr);

/* Separate-component upsampler private state (jdsample.c my_upsampler). */
struct ts4l_jpeg_my_upsampler {
    struct ts4l_jpeg_upsampler pub;       /* 0x00 */
    ts4l_jsamparray color_buf[10];        /* 0x0c */
    ts4l_jpeg_upsample1 methods[10];      /* 0x34 */
    int next_row_out;                    /* 0x5c */
    ts4l_jdim rows_to_go;                 /* 0x60 */
    int rowgroup_height[10];             /* 0x64 */
    unsigned char h_expand[10];          /* 0x8c */
    unsigned char v_expand[10];          /* 0x96 */
};

/* Copies rows of samples (jutils.c jcopy_sample_rows). */



/* Doubles each sample horizontally */
void ts4l_jpeg_h2v1_upsample_8345A4B0(struct ts4l_jpeg_decomp *cinfo,
                                     struct ts4l_jpeg_component_info *compptr,
                                     ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr)
{
    ts4l_jsamparray output_data = *output_data_ptr;
    ts4l_jsamprow inptr, outptr;
    ts4l_jsample invalue;
    ts4l_jsamprow outend;
    int inrow;

    (void)compptr;
    for (inrow = 0; inrow < cinfo->max_v_samp_factor; inrow++) {
        inptr = input_data[inrow];
        outptr = output_data[inrow];
        outend = outptr + cinfo->output_width;
        while (outptr < outend) {
            invalue = *inptr++;
            *outptr++ = invalue;
            *outptr++ = invalue;
        }
    }
}




enum { TS4L_JERR_CCIR601_NOTIMPL = 0x19, TS4L_JERR_FRACT_SAMPLE_NOTIMPL = 0x26 };

/* Linker thunks that forward to the fancy upsamplers above. */
void ts4_tailcall_fn_8345A5B8_8345A808(struct ts4l_jpeg_decomp *cinfo, struct ts4l_jpeg_component_info *compptr,
                          ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr);
void ts4_tailcall_fn_8345A6A0_8345A810(struct ts4l_jpeg_decomp *cinfo, struct ts4l_jpeg_component_info *compptr,
                          ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr);
/* noop_upsample / fullsize_upsample (no work needed). */
void ts4_set_u32_off0_8345A3C8(struct ts4l_jpeg_decomp *cinfo, struct ts4l_jpeg_component_info *compptr,
                               ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr);
void ts4_set_u32_off0_8345A3C0(struct ts4l_jpeg_decomp *cinfo, struct ts4l_jpeg_component_info *compptr,
                               ts4l_jsamparray input_data, ts4l_jsamparray *output_data_ptr);
/* start_pass_upsample. */
void ts4_get_u32_off1c8_8345A270(struct ts4l_jpeg_decomp *cinfo);
/* Rounds a up to a multiple of b (jutils.c jround_up). */
long fn_8344EF00(long a, long b);

/* Creates the upsampler and picks an upsampling method per component
 * */
void ts4l_jpeg_jinit_upsampler_8345A818(struct ts4l_jpeg_decomp *cinfo)
{
    struct ts4l_jpeg_my_upsampler *upsample;
    int ci;
    struct ts4l_jpeg_component_info *compptr;
    int need_buffer, do_fancy;
    int h_in_group, v_in_group, h_out_group, v_out_group;

    upsample = (struct ts4l_jpeg_my_upsampler *)(*cinfo->mem->alloc_small)(cinfo, 1,
                                                                           sizeof(*upsample));
    cinfo->upsample = &upsample->pub;
    upsample->pub.start_pass = ts4_get_u32_off1c8_8345A270;
    upsample->pub.upsample = fn_8345A288;
    upsample->pub.need_context_rows = 0;
    if (cinfo->CCIR601_sampling)
        TS4L_ERREXIT(cinfo, TS4L_JERR_CCIR601_NOTIMPL);
    do_fancy = cinfo->do_fancy_upsampling && cinfo->min_DCT_scaled_size > 1;
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        h_in_group = (compptr->h_samp_factor * compptr->DCT_scaled_size) / cinfo->min_DCT_scaled_size;
        v_in_group = (compptr->v_samp_factor * compptr->DCT_scaled_size) / cinfo->min_DCT_scaled_size;
        h_out_group = cinfo->max_h_samp_factor;
        v_out_group = cinfo->max_v_samp_factor;
        upsample->rowgroup_height[ci] = v_in_group;
        need_buffer = 1;
        if (!compptr->component_needed) {
            upsample->methods[ci] = ts4_set_u32_off0_8345A3C8;
            need_buffer = 0;
        } else if (h_in_group == h_out_group && v_in_group == v_out_group) {
            upsample->methods[ci] = ts4_set_u32_off0_8345A3C0;
            need_buffer = 0;
        } else if (h_in_group * 2 == h_out_group && v_in_group == v_out_group) {
            if (do_fancy && compptr->downsampled_width > 2)
                upsample->methods[ci] = ts4_tailcall_fn_8345A5B8_8345A808;
            else
                upsample->methods[ci] = ts4l_jpeg_h2v1_upsample_8345A4B0;
        } else if (h_in_group * 2 == h_out_group && v_in_group * 2 == v_out_group) {
            if (do_fancy && compptr->downsampled_width > 2) {
                upsample->methods[ci] = ts4_tailcall_fn_8345A6A0_8345A810;
                upsample->pub.need_context_rows = 1;
            } else {
                upsample->methods[ci] = fn_8345A518;
            }
        } else if ((h_out_group % h_in_group) == 0 && (v_out_group % v_in_group) == 0) {
            upsample->methods[ci] = fn_8345A3D8;
            upsample->h_expand[ci] = (unsigned char)(h_out_group / h_in_group);
            upsample->v_expand[ci] = (unsigned char)(v_out_group / v_in_group);
        } else {
            TS4L_ERREXIT(cinfo, TS4L_JERR_FRACT_SAMPLE_NOTIMPL);
        }
        if (need_buffer) {
            upsample->color_buf[ci] = (*cinfo->mem->alloc_sarray)(
                cinfo, 1, (ts4l_jdim)fn_8344EF00((long)cinfo->output_width, (long)cinfo->max_h_samp_factor),
                (ts4l_jdim)cinfo->max_v_samp_factor);
        }
    }
}
