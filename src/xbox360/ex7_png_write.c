/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX7: libpng pngwrite.c / pngwutil.c routines (compiled with /O1). */

#include "ex7_png.h"

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif

void fn_882E26E8(ex7_png_struct *png_ptr, const char *message); /* png_error */
void ts4_get_u8_off61c_882EFF30(ex7_png_struct *png_ptr);       /* png_write_sig */
void fn_882F0460(ex7_png_struct *png_ptr, unsigned int width, unsigned int height, int bit_depth, int color_type,
                 int compression_type, int filter_type, int interlace_type); /* png_write_IHDR */
void fn_882EFF48(ex7_png_struct *png_ptr, const unsigned char *palette, unsigned int num_pal); /* png_write_PLTE */
void fn_882F07B8(ex7_png_struct *png_ptr, const unsigned char *data, unsigned int length); /* png_write_IDAT */
int ts4_zlib_deflate_882F1788(ex7_z_stream *strm, int flush);                                            /* deflate */
void ts4_if_get_u32_off620_882E71C0(ex7_png_struct *png_ptr);                              /* png_flush */
extern const char lbl_88009650[]; /* "Valid palette required for paletted images\n" */
extern const char lbl_88009770[]; /* "zlib error" */

/* Write the signature, IHDR and PLTE chunks (libpng png_write_info). Swing_DLL.xex 0x882E6828 */
void ex7_png_write_info_882E6828(ex7_png_struct *png_ptr, ex7_png_info *info_ptr)
{
    ts4_get_u8_off61c_882EFF30(png_ptr);
    fn_882F0460(png_ptr, info_ptr->width, info_ptr->height, info_ptr->bit_depth, info_ptr->color_type,
                info_ptr->compression_type, info_ptr->filter_type, info_ptr->interlace_type);
    if (info_ptr->valid & 0x08)
        fn_882EFF48(png_ptr, info_ptr->palette, info_ptr->num_palette);
    else if (info_ptr->color_type == 3)
        fn_882E26E8(png_ptr, lbl_88009650);
}

/* Flush pending deflate output into IDAT chunks (libpng png_write_flush). Swing_DLL.xex 0x882E6B98 */
void ex7_png_write_flush_882E6B98(ex7_png_struct *png_ptr)
{
    int wrote_IDAT;

    if (png_ptr->row_number >= png_ptr->num_rows)
        return;
    do {
        int ret;
        ret = ts4_zlib_deflate_882F1788(&png_ptr->zstream, 2);
        wrote_IDAT = 0;
        if (ret != 0) {
            if (png_ptr->zstream.msg != 0)
                fn_882E26E8(png_ptr, png_ptr->zstream.msg);
            else
                fn_882E26E8(png_ptr, lbl_88009770);
        }
        if (!png_ptr->zstream.avail_out) {
            fn_882F07B8(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size);
            png_ptr->zstream.next_out = png_ptr->zbuf;
            png_ptr->zstream.avail_out = png_ptr->zbuf_size;
            wrote_IDAT = 1;
        }
    } while (wrote_IDAT == 1);
    if (png_ptr->zbuf_size != png_ptr->zstream.avail_out) {
        fn_882F07B8(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size - png_ptr->zstream.avail_out);
        png_ptr->zstream.next_out = png_ptr->zbuf;
        png_ptr->zstream.avail_out = png_ptr->zbuf_size;
    }
    png_ptr->flush_rows = 0;
    ts4_if_get_u32_off620_882E71C0(png_ptr);
}

void ts4_zlib_deflateEnd_882F1B70(ex7_z_stream *strm);                                  /* deflateEnd */
void fn_882EC1E0(ex7_png_struct *png_ptr, void *ptr);                  /* png_free */

/* Free the write-side buffers and reset the png_struct while keeping the error handlers (libpng png_write_destroy). Swing_DLL.xex 0x882E6C68 */
void ex7_png_write_destroy_882E6C68(ex7_png_struct *png_ptr)
{
    unsigned char tmp_jmp[0x540];
    void *error_fn;
    void *warning_fn;
    void *error_ptr;

    ts4_zlib_deflateEnd_882F1B70(&png_ptr->zstream);
    fn_882EC1E0(png_ptr, png_ptr->zbuf);
    fn_882EC1E0(png_ptr, png_ptr->row_buf);
    fn_882EC1E0(png_ptr, png_ptr->prev_row);
    fn_882EC1E0(png_ptr, png_ptr->sub_row);
    fn_882EC1E0(png_ptr, png_ptr->up_row);
    fn_882EC1E0(png_ptr, png_ptr->avg_row);
    fn_882EC1E0(png_ptr, png_ptr->paeth_row);
    fn_882EC1E0(png_ptr, png_ptr->prev_filters);
    fn_882EC1E0(png_ptr, png_ptr->filter_weights);
    fn_882EC1E0(png_ptr, png_ptr->inv_filter_weights);
    fn_882EC1E0(png_ptr, png_ptr->filter_costs);
    fn_882EC1E0(png_ptr, png_ptr->inv_filter_costs);

    memcpy(tmp_jmp, png_ptr->jmpbuf, sizeof(tmp_jmp));
    error_fn = png_ptr->error_fn;
    warning_fn = png_ptr->warning_fn;
    error_ptr = png_ptr->error_ptr;
    memset(png_ptr, 0, sizeof(ex7_png_struct));
    png_ptr->error_fn = error_fn;
    png_ptr->warning_fn = warning_fn;
    png_ptr->error_ptr = error_ptr;
    memcpy(png_ptr->jmpbuf, tmp_jmp, sizeof(tmp_jmp));
}

#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif

void *ts4_if_call_seq_fn_88888668_882EC170(ex7_png_struct *png_ptr, unsigned int size); /* png_malloc */

/* Allocate the row and filter buffers and set the row geometry before writing (libpng png_write_start_row). Swing_DLL.xex 0x882F0020 */
void ex7_png_write_start_row_882F0020(ex7_png_struct *png_ptr)
{
    unsigned int buf_size;

    buf_size = ((png_ptr->usr_channels * png_ptr->usr_bit_depth * png_ptr->width + 7) >> 3) + 1;
    png_ptr->row_buf = (unsigned char *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, buf_size);
    png_ptr->row_buf[0] = 0;
    if (png_ptr->do_filter & 0x10) {
        png_ptr->sub_row = (unsigned char *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, png_ptr->rowbytes + 1);
        png_ptr->sub_row[0] = 1;
    }
    if (png_ptr->do_filter & 0xe0) {
        png_ptr->prev_row = (unsigned char *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, buf_size);
        memset(png_ptr->prev_row, 0, buf_size);
        if (png_ptr->do_filter & 0x20) {
            png_ptr->up_row = (unsigned char *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, png_ptr->rowbytes + 1);
            png_ptr->up_row[0] = 2;
        }
        if (png_ptr->do_filter & 0x40) {
            png_ptr->avg_row = (unsigned char *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, png_ptr->rowbytes + 1);
            png_ptr->avg_row[0] = 3;
        }
        if (png_ptr->do_filter & 0x80) {
            png_ptr->paeth_row = (unsigned char *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, png_ptr->rowbytes + 1);
            png_ptr->paeth_row[0] = 4;
        }
    }
    if (png_ptr->interlaced) {
        if (!(png_ptr->transformations & 0x02)) {
            png_ptr->num_rows = (png_ptr->height + 7) >> 3;
            png_ptr->usr_width = (png_ptr->width + 7) >> 3;
        } else {
            png_ptr->num_rows = png_ptr->height;
            png_ptr->usr_width = png_ptr->width;
        }
    } else {
        png_ptr->num_rows = png_ptr->height;
        png_ptr->usr_width = png_ptr->width;
    }
    png_ptr->zstream.avail_out = png_ptr->zbuf_size;
    png_ptr->zstream.next_out = png_ptr->zbuf;
}

extern const unsigned int lbl_88026050[]; /* png_pass_start[7], png_pass_inc[7] */

/* Pack one interlace pass out of a full-width row (libpng png_do_write_interlace). Swing_DLL.xex 0x882F01A8 */
void ex7_png_do_write_interlace_882F01A8(ex7_png_row_info *row_info, unsigned char *row, int pass)
{
    if (pass < 6) {
        switch (row_info->pixel_depth) {
        case 1: {
            unsigned char *sp;
            unsigned char *dp;
            int shift;
            int d;
            int value;
            unsigned int i;
            unsigned int row_width = row_info->width;

            dp = row;
            d = 0;
            shift = 7;
            for (i = lbl_88026050[pass]; i < row_width; i += lbl_88026050[7 + pass]) {
                sp = row + (i >> 3);
                value = (int)(*sp >> (7 - (int)(i & 0x07))) & 0x01;
                d |= (value << shift);
                if (shift == 0) {
                    shift = 7;
                    *dp++ = (unsigned char)d;
                    d = 0;
                } else
                    shift--;
            }
            if (shift != 7)
                *dp = (unsigned char)d;
            break;
        }
        case 2: {
            unsigned char *sp;
            unsigned char *dp;
            int shift;
            int d;
            int value;
            unsigned int i;
            unsigned int row_width = row_info->width;

            dp = row;
            shift = 6;
            d = 0;
            for (i = lbl_88026050[pass]; i < row_width; i += lbl_88026050[7 + pass]) {
                sp = row + (i >> 2);
                value = (*sp >> ((3 - (int)(i & 0x03)) << 1)) & 0x03;
                d |= (value << shift);
                if (shift == 0) {
                    shift = 6;
                    *dp++ = (unsigned char)d;
                    d = 0;
                } else
                    shift -= 2;
            }
            if (shift != 6)
                *dp = (unsigned char)d;
            break;
        }
        case 4: {
            unsigned char *sp;
            unsigned char *dp;
            int shift;
            int d;
            int value;
            unsigned int i;
            unsigned int row_width = row_info->width;

            dp = row;
            shift = 4;
            d = 0;
            for (i = lbl_88026050[pass]; i < row_width; i += lbl_88026050[7 + pass]) {
                sp = row + (i >> 1);
                value = (*sp >> ((1 - (int)(i & 0x01)) << 2)) & 0x0f;
                d |= (value << shift);
                if (shift == 0) {
                    shift = 4;
                    *dp++ = (unsigned char)d;
                    d = 0;
                } else
                    shift -= 4;
            }
            if (shift != 4)
                *dp = (unsigned char)d;
            break;
        }
        default: {
            unsigned char *sp;
            unsigned char *dp = row;
            unsigned int i;
            unsigned int row_width = row_info->width;
            unsigned int pixel_bytes = (row_info->pixel_depth >> 3);

            for (i = lbl_88026050[pass]; i < row_width; i += lbl_88026050[7 + pass]) {
                sp = row + i * pixel_bytes;
                if (dp != sp)
                    memcpy(dp, sp, pixel_bytes);
                dp = pixel_bytes + dp;
            }
            break;
        }
        }
        row_info->width = (row_info->width + lbl_88026050[7 + pass] - 1 - lbl_88026050[pass]) / lbl_88026050[7 + pass];
        row_info->rowbytes = ((row_info->pixel_depth * row_info->width) + 7) >> 3;
    }
}
