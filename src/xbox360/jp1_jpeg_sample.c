/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG decompression upsampling, IJG jdsample.c style. (JP1) */
#include "jp1_jpeg.h"

typedef void (*ts4_jpeg_upsample1)(struct ts4_jpeg_decomp *cinfo,
                                   struct ts4_jpeg_component_info *compptr,
                                   ts4_jsamparray input_data, ts4_jsamparray *output_data_ptr);

/* Separate-component upsampler private state (jdsample.c my_upsampler). */
struct ts4_jpeg_my_upsampler {
    struct ts4_jpeg_upsampler pub;       /* 0x00 */
    ts4_jsamparray color_buf[10];        /* 0x0c */
    ts4_jpeg_upsample1 methods[10];      /* 0x34 */
    int next_row_out;                    /* 0x5c */
    ts4_jdim rows_to_go;                 /* 0x60 */
    int rowgroup_height[10];             /* 0x64 */
    unsigned char h_expand[10];          /* 0x8c */
    unsigned char v_expand[10];          /* 0x96 */
};

/* Copies rows of samples (jutils.c jcopy_sample_rows). */
void ts4_jpeg_jcopy_sample_rows_882EE8A0(ts4_jsamparray input_array, int source_row, ts4_jsamparray output_array,
                 int dest_row, int num_rows, ts4_jdim num_cols);

/* Upsamples each component into the color buffer, then color-converts the rows
 * (Swing_DLL.xex 0x882F9130). */
void ts4_jpeg_sep_upsample_882F9130(struct ts4_jpeg_decomp *cinfo, ts4_jsampimage input_buf,
                                    ts4_jdim *in_row_group_ctr, ts4_jdim in_row_groups_avail,
                                    ts4_jsamparray output_buf, ts4_jdim *out_row_ctr,
                                    ts4_jdim out_rows_avail)
{
    struct ts4_jpeg_my_upsampler *upsample = (struct ts4_jpeg_my_upsampler *)cinfo->upsample;
    int ci;
    struct ts4_jpeg_component_info *compptr;
    ts4_jdim num_rows;

    (void)in_row_groups_avail;
    if (upsample->next_row_out >= cinfo->max_v_samp_factor) {
        for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
            (*upsample->methods[ci])(cinfo, compptr,
                                     input_buf[ci] + (*in_row_group_ctr * upsample->rowgroup_height[ci]),
                                     upsample->color_buf + ci);
        }
        upsample->next_row_out = 0;
    }
    num_rows = (ts4_jdim)(cinfo->max_v_samp_factor - upsample->next_row_out);
    if (num_rows > upsample->rows_to_go)
        num_rows = upsample->rows_to_go;
    out_rows_avail -= *out_row_ctr;
    if (num_rows > out_rows_avail)
        num_rows = out_rows_avail;
    (*cinfo->cconvert->color_convert)(cinfo, upsample->color_buf,
                                      (ts4_jdim)upsample->next_row_out,
                                      output_buf + *out_row_ctr, (int)num_rows);
    *out_row_ctr += num_rows;
    upsample->rows_to_go -= num_rows;
    upsample->next_row_out += (int)num_rows;
    if (upsample->next_row_out >= cinfo->max_v_samp_factor)
        (*in_row_group_ctr)++;
}

/* Replicates each input sample h_expand times and each row v_expand times
 * (Swing_DLL.xex 0x882F9280). */
void ts4_jpeg_int_upsample_882F9280(struct ts4_jpeg_decomp *cinfo,
                                    struct ts4_jpeg_component_info *compptr,
                                    ts4_jsamparray input_data, ts4_jsamparray *output_data_ptr)
{
    struct ts4_jpeg_my_upsampler *upsample = (struct ts4_jpeg_my_upsampler *)cinfo->upsample;
    ts4_jsamparray output_data = *output_data_ptr;
    ts4_jsamprow inptr, outptr;
    ts4_jsample invalue;
    int h;
    ts4_jsamprow outend;
    int h_expand, v_expand;
    int inrow, outrow;

    h_expand = upsample->h_expand[compptr->component_index];
    v_expand = upsample->v_expand[compptr->component_index];
    inrow = outrow = 0;
    while (outrow < cinfo->max_v_samp_factor) {
        inptr = input_data[inrow];
        outptr = output_data[outrow];
        outend = outptr + cinfo->output_width;
        while (outptr < outend) {
            invalue = *inptr++;
            for (h = h_expand; h > 0; h--) {
                *outptr++ = invalue;
            }
        }
        if (v_expand > 1) {
            ts4_jpeg_jcopy_sample_rows_882EE8A0(output_data, outrow, output_data, outrow + 1, v_expand - 1,
                        cinfo->output_width);
        }
        inrow++;
        outrow += v_expand;
    }
}

/* Doubles each sample horizontally (Swing_DLL.xex 0x882F9358). */
void ts4_jpeg_h2v1_upsample_882F9358(struct ts4_jpeg_decomp *cinfo,
                                     struct ts4_jpeg_component_info *compptr,
                                     ts4_jsamparray input_data, ts4_jsamparray *output_data_ptr)
{
    ts4_jsamparray output_data = *output_data_ptr;
    ts4_jsamprow inptr, outptr;
    ts4_jsample invalue;
    ts4_jsamprow outend;
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

/* Doubles each sample horizontally and each row vertically (Swing_DLL.xex 0x882F93C0). */
void ts4_jpeg_h2v2_upsample_882F93C0(struct ts4_jpeg_decomp *cinfo,
                                     struct ts4_jpeg_component_info *compptr,
                                     ts4_jsamparray input_data, ts4_jsamparray *output_data_ptr)
{
    ts4_jsamparray output_data = *output_data_ptr;
    ts4_jsamprow inptr, outptr;
    ts4_jsample invalue;
    ts4_jsamprow outend;
    int inrow, outrow;

    (void)compptr;
    inrow = outrow = 0;
    while (outrow < cinfo->max_v_samp_factor) {
        inptr = input_data[inrow];
        outptr = output_data[outrow];
        outend = outptr + cinfo->output_width;
        while (outptr < outend) {
            invalue = *inptr++;
            *outptr++ = invalue;
            *outptr++ = invalue;
        }
        ts4_jpeg_jcopy_sample_rows_882EE8A0(output_data, outrow, output_data, outrow + 1, 1, cinfo->output_width);
        inrow++;
        outrow += 2;
    }
}

/* Triangle-filter 2:1 horizontal upsampling (Swing_DLL.xex 0x882F9460). */
void ts4_jpeg_h2v1_fancy_upsample_882F9460(struct ts4_jpeg_decomp *cinfo,
                                           struct ts4_jpeg_component_info *compptr,
                                           ts4_jsamparray input_data,
                                           ts4_jsamparray *output_data_ptr)
{
    ts4_jsamparray output_data = *output_data_ptr;
    ts4_jsamprow inptr, outptr;
    int invalue;
    ts4_jdim colctr;
    int inrow;

    for (inrow = 0; inrow < cinfo->max_v_samp_factor; inrow++) {
        inptr = input_data[inrow];
        outptr = output_data[inrow];
        invalue = *inptr++;
        *outptr++ = (ts4_jsample)invalue;
        *outptr++ = (ts4_jsample)((invalue * 3 + *inptr + 2) >> 2);
        for (colctr = compptr->downsampled_width - 2; colctr > 0; colctr--) {
            invalue = *inptr++ * 3;
            *outptr++ = (ts4_jsample)((invalue + inptr[-2] + 1) >> 2);
            *outptr++ = (ts4_jsample)((invalue + *inptr + 2) >> 2);
        }
        invalue = *inptr;
        *outptr++ = (ts4_jsample)((invalue * 3 + inptr[-1] + 1) >> 2);
        *outptr++ = (ts4_jsample)invalue;
    }
}

/* Triangle-filter 2:1 horizontal and vertical upsampling (Swing_DLL.xex 0x882F9548). */
void ts4_jpeg_h2v2_fancy_upsample_882F9548(struct ts4_jpeg_decomp *cinfo,
                                           struct ts4_jpeg_component_info *compptr,
                                           ts4_jsamparray input_data,
                                           ts4_jsamparray *output_data_ptr)
{
    ts4_jsamparray output_data = *output_data_ptr;
    ts4_jsamprow inptr0, inptr1, outptr;
    int thiscolsum, lastcolsum, nextcolsum;
    ts4_jdim colctr;
    int inrow, outrow, v;

    inrow = outrow = 0;
    while (outrow < cinfo->max_v_samp_factor) {
        for (v = 0; v < 2; v++) {
            inptr0 = input_data[inrow];
            if (v == 0)
                inptr1 = input_data[inrow - 1];
            else
                inptr1 = input_data[inrow + 1];
            outptr = output_data[outrow++];
            thiscolsum = (*inptr0++) * 3 + (*inptr1++);
            nextcolsum = (*inptr0++) * 3 + (*inptr1++);
            *outptr++ = (ts4_jsample)((thiscolsum * 4 + 8) >> 4);
            *outptr++ = (ts4_jsample)((thiscolsum * 3 + nextcolsum + 7) >> 4);
            lastcolsum = thiscolsum;
            thiscolsum = nextcolsum;
            for (colctr = compptr->downsampled_width - 2; colctr > 0; colctr--) {
                nextcolsum = (*inptr0++) * 3 + (*inptr1++);
                *outptr++ = (ts4_jsample)((thiscolsum * 3 + lastcolsum + 8) >> 4);
                *outptr++ = (ts4_jsample)((thiscolsum * 3 + nextcolsum + 7) >> 4);
                lastcolsum = thiscolsum;
                thiscolsum = nextcolsum;
            }
            *outptr++ = (ts4_jsample)((thiscolsum * 3 + lastcolsum + 8) >> 4);
            *outptr++ = (ts4_jsample)((thiscolsum * 4 + 7) >> 4);
        }
        inrow++;
    }
}

enum { JP1_JERR_CCIR601_NOTIMPL = 0x19, JP1_JERR_FRACT_SAMPLE_NOTIMPL = 0x26 };

/* Linker thunks that forward to the fancy upsamplers above. */
void ts4_forward_882F96B0(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_component_info *compptr,
                          ts4_jsamparray input_data, ts4_jsamparray *output_data_ptr);
void ts4_forward_882F96B8(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_component_info *compptr,
                          ts4_jsamparray input_data, ts4_jsamparray *output_data_ptr);
/* noop_upsample / fullsize_upsample (no work needed). */
void ts4_set_u32_off0_882F9270(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_component_info *compptr,
                               ts4_jsamparray input_data, ts4_jsamparray *output_data_ptr);
void ts4_set_u32_off0_882F9268(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_component_info *compptr,
                               ts4_jsamparray input_data, ts4_jsamparray *output_data_ptr);
/* start_pass_upsample. */
void ts4_get_u32_off1c8_882F9118(struct ts4_jpeg_decomp *cinfo);
/* Rounds a up to a multiple of b (jutils.c jround_up). */
long ts4_jpeg_jround_up_882EE870(long a, long b);

/* Creates the upsampler and picks an upsampling method per component
 * (Swing_DLL.xex 0x882F96C0). */
void ts4_jpeg_jinit_upsampler_882F96C0(struct ts4_jpeg_decomp *cinfo)
{
    struct ts4_jpeg_my_upsampler *upsample;
    int ci;
    struct ts4_jpeg_component_info *compptr;
    int need_buffer, do_fancy;
    int h_in_group, v_in_group, h_out_group, v_out_group;

    upsample = (struct ts4_jpeg_my_upsampler *)(*cinfo->mem->alloc_small)(cinfo, 1,
                                                                           sizeof(*upsample));
    cinfo->upsample = &upsample->pub;
    upsample->pub.start_pass = ts4_get_u32_off1c8_882F9118;
    upsample->pub.upsample = ts4_jpeg_sep_upsample_882F9130;
    upsample->pub.need_context_rows = 0;
    if (cinfo->CCIR601_sampling)
        JP1_ERREXIT(cinfo, JP1_JERR_CCIR601_NOTIMPL);
    do_fancy = cinfo->do_fancy_upsampling && cinfo->min_DCT_scaled_size > 1;
    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        h_in_group = (compptr->h_samp_factor * compptr->DCT_scaled_size) / cinfo->min_DCT_scaled_size;
        v_in_group = (compptr->v_samp_factor * compptr->DCT_scaled_size) / cinfo->min_DCT_scaled_size;
        h_out_group = cinfo->max_h_samp_factor;
        v_out_group = cinfo->max_v_samp_factor;
        upsample->rowgroup_height[ci] = v_in_group;
        need_buffer = 1;
        if (!compptr->component_needed) {
            upsample->methods[ci] = ts4_set_u32_off0_882F9270;
            need_buffer = 0;
        } else if (h_in_group == h_out_group && v_in_group == v_out_group) {
            upsample->methods[ci] = ts4_set_u32_off0_882F9268;
            need_buffer = 0;
        } else if (h_in_group * 2 == h_out_group && v_in_group == v_out_group) {
            if (do_fancy && compptr->downsampled_width > 2)
                upsample->methods[ci] = ts4_forward_882F96B0;
            else
                upsample->methods[ci] = ts4_jpeg_h2v1_upsample_882F9358;
        } else if (h_in_group * 2 == h_out_group && v_in_group * 2 == v_out_group) {
            if (do_fancy && compptr->downsampled_width > 2) {
                upsample->methods[ci] = ts4_forward_882F96B8;
                upsample->pub.need_context_rows = 1;
            } else {
                upsample->methods[ci] = ts4_jpeg_h2v2_upsample_882F93C0;
            }
        } else if ((h_out_group % h_in_group) == 0 && (v_out_group % v_in_group) == 0) {
            upsample->methods[ci] = ts4_jpeg_int_upsample_882F9280;
            upsample->h_expand[ci] = (unsigned char)(h_out_group / h_in_group);
            upsample->v_expand[ci] = (unsigned char)(v_out_group / v_in_group);
        } else {
            JP1_ERREXIT(cinfo, JP1_JERR_FRACT_SAMPLE_NOTIMPL);
        }
        if (need_buffer) {
            upsample->color_buf[ci] = (*cinfo->mem->alloc_sarray)(
                cinfo, 1, (ts4_jdim)ts4_jpeg_jround_up_882EE870((long)cinfo->output_width, (long)cinfo->max_h_samp_factor),
                (ts4_jdim)cinfo->max_v_samp_factor);
        }
    }
}
