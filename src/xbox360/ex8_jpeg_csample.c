/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b downsampling (jcsample.c). */
#include "ex8_jpeg.h"

void ts4_jpeg_jcopy_sample_rows_882EE8A0(ex8_jsamparray input_array, int source_row, ex8_jsamparray output_array, int dest_row,
                 int num_rows, unsigned int num_cols); /* jcopy_sample_rows */
void ts4_noop_881B3360(ex8_jcomp *cinfo);               /* start_pass_downsample */
void ts4_forward_883006A8(ex8_jcomp *cinfo, ex8_jcinfo *compptr, ex8_jsamparray input_data,
                          ex8_jsamparray output_data); /* h2v2_downsample */

enum {
    EX8_JERR_CCIR601_NOTIMPL = 0x19,
    EX8_JERR_FRACT_SAMPLE_NOTIMPL = 0x26,
    EX8_JTRC_SMOOTH_NOTIMPL = 0x63
};

typedef void (*ex8_downsample_method)(ex8_jcomp *cinfo, ex8_jcinfo *compptr, ex8_jsamparray input_data,
                                      ex8_jsamparray output_data);

typedef struct ex8_downsample_priv {
    ex8_jcdown pub;                          /* 0x00 */
    ex8_downsample_method methods[10];       /* 0x0c */
} ex8_downsample_priv;

/* Replicates the last real column of each row into the padding columns. */
static void ex8_expand_right_edge(ex8_jsamparray image_data, int num_rows, unsigned int input_cols,
                                  unsigned int output_cols)
{
    ex8_jsamprow ptr;
    ex8_joctet pixval;
    int count;
    int row;
    int numcols = (int)(output_cols - input_cols);

    if (numcols > 0) {
        for (row = 0; row < num_rows; row++) {
            ptr = image_data[row] + input_cols;
            pixval = ptr[-1];
            for (count = numcols; count > 0; count--)
                *ptr++ = pixval;
        }
    }
}

/* Downsamples every component with its own method. */
void ex8_sep_downsample_882FFDE8(ex8_jcomp *cinfo, ex8_jsamparray *input_buf, unsigned int in_row_index,
                                 ex8_jsamparray *output_buf, unsigned int out_row_group_index)
{
    ex8_downsample_priv *downsample = (ex8_downsample_priv *)cinfo->downsample;
    int ci;
    ex8_jcinfo *compptr;
    ex8_jsamparray in_ptr, out_ptr;

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        in_ptr = input_buf[ci] + in_row_index;
        out_ptr = output_buf[ci] + (out_row_group_index * compptr->v_samp_factor);
        (*downsample->methods[ci])(cinfo, compptr, in_ptr, out_ptr);
    }
}

/* Downsamples by an integral factor with a box filter. */
void ex8_int_downsample_882FFE78(ex8_jcomp *cinfo, ex8_jcinfo *compptr, ex8_jsamparray input_data,
                                 ex8_jsamparray output_data)
{
    int inrow, outrow, h_expand, v_expand, numpix, numpix2, h, v;
    unsigned int outcol, outcol_h;
    unsigned int output_cols = compptr->width_in_blocks * 8;
    ex8_jsamprow inptr, outptr;
    int outvalue;

    h_expand = cinfo->max_h_samp_factor / compptr->h_samp_factor;
    v_expand = cinfo->max_v_samp_factor / compptr->v_samp_factor;
    numpix = h_expand * v_expand;
    numpix2 = numpix / 2;

    ex8_expand_right_edge(input_data, cinfo->max_v_samp_factor, cinfo->image_width, output_cols * h_expand);

    inrow = 0;
    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        for (outcol = 0, outcol_h = 0; outcol < output_cols; outcol++, outcol_h += h_expand) {
            outvalue = 0;
            for (v = 0; v < v_expand; v++) {
                inptr = input_data[inrow + v] + outcol_h;
                for (h = 0; h < h_expand; h++)
                    outvalue += (int)(*inptr++);
            }
            *outptr++ = (ex8_joctet)((outvalue + numpix2) / numpix);
        }
        inrow += v_expand;
    }
}

/* Copies a component through unchanged (full-size sampling). */
void ex8_fullsize_downsample_88300010(ex8_jcomp *cinfo, ex8_jcinfo *compptr, ex8_jsamparray input_data,
                                      ex8_jsamparray output_data)
{
    ts4_jpeg_jcopy_sample_rows_882EE8A0(input_data, 0, output_data, 0, cinfo->max_v_samp_factor, cinfo->image_width);
    ex8_expand_right_edge(output_data, cinfo->max_v_samp_factor, cinfo->image_width,
                          compptr->width_in_blocks * 8);
}

/* 2:1 horizontal, 2:2 vertical downsampling with input smoothing. */
void ex8_h2v2_smooth_downsample_88300190(ex8_jcomp *cinfo, ex8_jcinfo *compptr, ex8_jsamparray input_data,
                                         ex8_jsamparray output_data)
{
    int inrow, outrow;
    unsigned int colctr;
    unsigned int output_cols = compptr->width_in_blocks * 8;
    ex8_jsamprow inptr0, inptr1, above_ptr, below_ptr, outptr;
    int membersum, neighsum, memberscale, neighscale;

    ex8_expand_right_edge(input_data - 1, cinfo->max_v_samp_factor + 2, cinfo->image_width, output_cols * 2);

    memberscale = 16384 - cinfo->smoothing_factor * 80L;
    neighscale = cinfo->smoothing_factor * 16;

    inrow = 0;
    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        inptr0 = input_data[inrow];
        inptr1 = input_data[inrow + 1];
        above_ptr = input_data[inrow - 1];
        below_ptr = input_data[inrow + 2];

        membersum = *inptr0 + inptr0[1] + *inptr1 + inptr1[1];
        neighsum = *above_ptr + above_ptr[1] + *below_ptr + below_ptr[1] + *inptr0 + inptr0[2] + *inptr1 +
                   inptr1[2];
        neighsum += neighsum;
        neighsum += *above_ptr + above_ptr[2] + *below_ptr + below_ptr[2];
        membersum = membersum * memberscale + neighsum * neighscale;
        *outptr++ = (ex8_joctet)((membersum + 32768) >> 16);
        inptr0 += 2;
        inptr1 += 2;
        above_ptr += 2;
        below_ptr += 2;

        for (colctr = output_cols - 2; colctr > 0; colctr--) {
            membersum = *inptr0 + inptr0[1] + *inptr1 + inptr1[1];
            neighsum = *above_ptr + above_ptr[1] + *below_ptr + below_ptr[1] + inptr0[-1] + inptr0[2] +
                       inptr1[-1] + inptr1[2];
            neighsum += neighsum;
            neighsum += above_ptr[-1] + above_ptr[2] + below_ptr[-1] + below_ptr[2];
            membersum = membersum * memberscale + neighsum * neighscale;
            *outptr++ = (ex8_joctet)((membersum + 32768) >> 16);
            inptr0 += 2;
            inptr1 += 2;
            above_ptr += 2;
            below_ptr += 2;
        }

        membersum = *inptr0 + inptr0[1] + *inptr1 + inptr1[1];
        neighsum = *above_ptr + above_ptr[1] + *below_ptr + below_ptr[1] + inptr0[-1] + inptr0[1] +
                   inptr1[-1] + inptr1[1];
        neighsum += neighsum;
        neighsum += above_ptr[-1] + above_ptr[1] + below_ptr[-1] + below_ptr[1];
        membersum = membersum * memberscale + neighsum * neighscale;
        *outptr = (ex8_joctet)((membersum + 32768) >> 16);

        inrow += 2;
    }
}

/* Smooths full-size input using a 3x3 neighborhood. */
void ex8_fullsize_smooth_downsample_88300440(ex8_jcomp *cinfo, ex8_jcinfo *compptr, ex8_jsamparray input_data,
                                             ex8_jsamparray output_data)
{
    int outrow;
    unsigned int colctr;
    unsigned int output_cols = compptr->width_in_blocks * 8;
    ex8_jsamprow inptr, above_ptr, below_ptr, outptr;
    int membersum, neighsum, memberscale, neighscale;
    int colsum, lastcolsum, nextcolsum;

    ex8_expand_right_edge(input_data - 1, cinfo->max_v_samp_factor + 2, cinfo->image_width, output_cols);

    memberscale = 65536L - cinfo->smoothing_factor * 512L;
    neighscale = cinfo->smoothing_factor * 64;

    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        inptr = input_data[outrow];
        above_ptr = input_data[outrow - 1];
        below_ptr = input_data[outrow + 1];

        colsum = *above_ptr++ + *below_ptr++ + *inptr;
        membersum = *inptr++;
        nextcolsum = *above_ptr + *below_ptr + *inptr;
        neighsum = colsum + (colsum - membersum) + nextcolsum;
        membersum = membersum * memberscale + neighsum * neighscale;
        *outptr++ = (ex8_joctet)((membersum + 32768) >> 16);
        lastcolsum = colsum;
        colsum = nextcolsum;

        for (colctr = output_cols - 2; colctr > 0; colctr--) {
            membersum = *inptr++;
            above_ptr++;
            below_ptr++;
            nextcolsum = *above_ptr + *below_ptr + *inptr;
            neighsum = lastcolsum + (colsum - membersum) + nextcolsum;
            membersum = membersum * memberscale + neighsum * neighscale;
            *outptr++ = (ex8_joctet)((membersum + 32768) >> 16);
            lastcolsum = colsum;
            colsum = nextcolsum;
        }

        membersum = *inptr;
        neighsum = lastcolsum + (colsum - membersum) + colsum;
        membersum = membersum * memberscale + neighsum * neighscale;
        *outptr = (ex8_joctet)((membersum + 32768) >> 16);
    }
}

/* 2:1 horizontal downsampling with alternating rounding bias. */
void ex8_h2v1_downsample_883005D8(ex8_jcomp *cinfo, ex8_jcinfo *compptr, ex8_jsamparray input_data,
                                  ex8_jsamparray output_data)
{
    int outrow;
    unsigned int outcol;
    unsigned int output_cols = compptr->width_in_blocks * 8;
    ex8_jsamprow inptr, outptr;
    int bias;

    ex8_expand_right_edge(input_data, cinfo->max_v_samp_factor, cinfo->image_width, output_cols * 2);

    for (outrow = 0; outrow < compptr->v_samp_factor; outrow++) {
        outptr = output_data[outrow];
        inptr = input_data[outrow];
        bias = 0;
        for (outcol = 0; outcol < output_cols; outcol++) {
            *outptr++ = (ex8_joctet)((*inptr + inptr[1] + bias) >> 1);
            bias ^= 1;
            inptr += 2;
        }
    }
}

/* Picks a downsampling method for every component. */
void ex8_jinit_downsampler_883006B0(ex8_jcomp *cinfo)
{
    ex8_downsample_priv *downsample;
    int ci;
    ex8_jcinfo *compptr;
    int smoothok = 1;

    downsample = (ex8_downsample_priv *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ex8_downsample_priv));
    cinfo->downsample = &downsample->pub;
    downsample->pub.start_pass = ts4_noop_881B3360;
    downsample->pub.downsample = ex8_sep_downsample_882FFDE8;
    downsample->pub.need_context_rows = 0;

    if (cinfo->CCIR601_sampling)
        EX8_ERREXIT(cinfo, EX8_JERR_CCIR601_NOTIMPL);

    for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components; ci++, compptr++) {
        if (compptr->h_samp_factor == cinfo->max_h_samp_factor &&
            compptr->v_samp_factor == cinfo->max_v_samp_factor) {
            if (cinfo->smoothing_factor) {
                downsample->methods[ci] = ex8_fullsize_smooth_downsample_88300440;
                downsample->pub.need_context_rows = 1;
            } else {
                downsample->methods[ci] = ex8_fullsize_downsample_88300010;
            }
        } else if (compptr->h_samp_factor * 2 == cinfo->max_h_samp_factor &&
                   compptr->v_samp_factor == cinfo->max_v_samp_factor) {
            smoothok = 0;
            downsample->methods[ci] = ex8_h2v1_downsample_883005D8;
        } else if (compptr->h_samp_factor * 2 == cinfo->max_h_samp_factor &&
                   compptr->v_samp_factor * 2 == cinfo->max_v_samp_factor) {
            if (cinfo->smoothing_factor) {
                downsample->methods[ci] = ex8_h2v2_smooth_downsample_88300190;
                downsample->pub.need_context_rows = 1;
            } else {
                downsample->methods[ci] = ts4_forward_883006A8;
            }
        } else if ((cinfo->max_h_samp_factor % compptr->h_samp_factor) == 0 &&
                   (cinfo->max_v_samp_factor % compptr->v_samp_factor) == 0) {
            smoothok = 0;
            downsample->methods[ci] = ex8_int_downsample_882FFE78;
        } else {
            EX8_ERREXIT(cinfo, EX8_JERR_FRACT_SAMPLE_NOTIMPL);
        }
    }

    if (cinfo->smoothing_factor && !smoothok) {
        cinfo->err->msg_code = EX8_JTRC_SMOOTH_NOTIMPL;
        (*cinfo->err->emit_message)(cinfo, 0);
    }
}
