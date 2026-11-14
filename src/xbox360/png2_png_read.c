/* Derived from libpng 1.0.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: libpng pngread.c (1.0.6-era code with PNG_USE_LOCAL_ARRAYS, /O1). */

#include "png2_png.h"

#ifdef _MSC_VER
extern int memcmp(const void *, const void *, unsigned int);
#else
#include <string.h>
#endif

#define PNG2_HAVE_IHDR 0x01u
#define PNG2_HAVE_PLTE 0x02u
#define PNG2_HAVE_IDAT 0x04u
#define PNG2_COLOR_TYPE_PALETTE 3

/* The interlace masks and chunk-name arrays of pngread.c (PNG_IHDR, PNG_IDAT, ... declared as local const arrays
 * upstream); the compiler addresses them from one base, so their order and spacing must match the image. */
static const int lbl_880098EC[7] = {0x80, 0x08, 0x88, 0x22, 0xaa, 0x55, 0xff}; /* png_pass_mask */
static const int png2_pass_dsp_mask[7] = {0xff, 0x0f, 0xff, 0x33, 0xff, 0x55, 0xff}; /* png_pass_dsp_mask (0x88009908) */
static const unsigned char lbl_88009924[8] = {73, 72, 68, 82, 0};   /* "IHDR" */
static const unsigned char lbl_8800992C[8] = {73, 68, 65, 84, 0};   /* "IDAT" */
static const unsigned char lbl_88009934[8] = {73, 69, 78, 68, 0};   /* "IEND" */
static const unsigned char lbl_8800993C[8] = {80, 76, 84, 69, 0};   /* "PLTE" */
static const unsigned char lbl_88009944[8] = {103, 65, 77, 65, 0};  /* "gAMA" */
static const unsigned char lbl_8800994C[8] = {115, 82, 71, 66, 0};  /* "sRGB" */
static const unsigned char lbl_88009954[8] = {116, 82, 78, 83, 0};  /* "tRNS" */

extern const char lbl_880099F8[]; /* "Not a PNG file" */
extern const char lbl_880099D0[]; /* "PNG file corrupted by ASCII conversion" */
extern const char lbl_880099B4[]; /* "Missing IHDR before IDAT" */
extern const char lbl_88009998[]; /* "Missing PLTE before IDAT" */

void ts4_if_get_u32_off550_882EA0A0(png2_png_struct *png_ptr, void *data, unsigned int length); /* png_read_data */
int png2_png_sig_cmp_882E27D0(const unsigned char *sig, unsigned int start, unsigned int num_to_check);
void png2_png_error_882E26E8(png2_png_struct *png_ptr, const char *error_message);
unsigned int ex8_png_get_uint_31_882F4238(png2_png_struct *png_ptr, const unsigned char *buf);
void ts4_call_seq_fn_882EC228_882E28C0(png2_png_struct *png_ptr);                                /* png_reset_crc */
void ts4_call_seq_fn_882EA0A0_882F36C8(png2_png_struct *png_ptr, unsigned char *buf, unsigned int length); /* png_crc_read */
void ex7_png_handle_IHDR_882F43A0(png2_png_struct *png_ptr, png2_png_info *info_ptr, unsigned int length);
void ex7_png_handle_PLTE_882F4668(png2_png_struct *png_ptr, png2_png_info *info_ptr, unsigned int length);
void ts4_if_call_seq_u32_off558_882F4820(png2_png_struct *png_ptr, png2_png_info *info_ptr, unsigned int length); /* png_handle_IEND */
void ex7_png_handle_gAMA_882F48A0(png2_png_struct *png_ptr, png2_png_info *info_ptr, unsigned int length);
void ex7_png_handle_sRGB_882F4A40(png2_png_struct *png_ptr, png2_png_info *info_ptr, unsigned int length);
void ex7_png_handle_tRNS_882F4BB0(png2_png_struct *png_ptr, png2_png_info *info_ptr, unsigned int length);
void ts4_if_call_seq_fn_882F37C8_882F4DE8(png2_png_struct *png_ptr, png2_png_info *info_ptr, unsigned int length); /* png_handle_unknown */

/* Check the rest of the signature, then read and dispatch chunks up to the first IDAT (libpng png_read_info).
 * Swing_DLL.xex 0x882E75D8 */
void png2_png_read_info_882E75D8(png2_png_struct *png_ptr, png2_png_info *info_ptr)
{
    if (png_ptr->sig_bytes < 8) {
        unsigned int num_checked = png_ptr->sig_bytes, num_to_check = 8 - num_checked;

        ts4_if_get_u32_off550_882EA0A0(png_ptr, &(info_ptr->signature[num_checked]), num_to_check);
        png_ptr->sig_bytes = 8;
        if (png2_png_sig_cmp_882E27D0(info_ptr->signature, num_checked, num_to_check)) {
            if (num_checked < 4 && png2_png_sig_cmp_882E27D0(info_ptr->signature, num_checked, num_to_check - 4))
                png2_png_error_882E26E8(png_ptr, lbl_880099F8);
            else
                png2_png_error_882E26E8(png_ptr, lbl_880099D0);
        }
    }

    for (;;) {
        unsigned char chunk_length[4];
        unsigned int length;

        ts4_if_get_u32_off550_882EA0A0(png_ptr, chunk_length, 4);
        length = ex8_png_get_uint_31_882F4238(png_ptr, chunk_length);
        ts4_call_seq_fn_882EC228_882E28C0(png_ptr);
        ts4_call_seq_fn_882EA0A0_882F36C8(png_ptr, png_ptr->chunk_name, 4);

        if (!memcmp(png_ptr->chunk_name, lbl_88009924, 4))
            ex7_png_handle_IHDR_882F43A0(png_ptr, info_ptr, length);
        else if (!memcmp(png_ptr->chunk_name, lbl_8800993C, 4))
            ex7_png_handle_PLTE_882F4668(png_ptr, info_ptr, length);
        else if (!memcmp(png_ptr->chunk_name, lbl_88009934, 4))
            ts4_if_call_seq_u32_off558_882F4820(png_ptr, info_ptr, length);
        else if (!memcmp(png_ptr->chunk_name, lbl_8800992C, 4)) {
            if (!(png_ptr->mode & PNG2_HAVE_IHDR))
                png2_png_error_882E26E8(png_ptr, lbl_880099B4);
            else if (png_ptr->color_type == PNG2_COLOR_TYPE_PALETTE && !(png_ptr->mode & PNG2_HAVE_PLTE))
                png2_png_error_882E26E8(png_ptr, lbl_88009998);
            png_ptr->idat_size = length;
            png_ptr->mode |= PNG2_HAVE_IDAT;
            break;
        } else if (!memcmp(png_ptr->chunk_name, lbl_88009944, 4))
            ex7_png_handle_gAMA_882F48A0(png_ptr, info_ptr, length);
        else if (!memcmp(png_ptr->chunk_name, lbl_8800994C, 4))
            ex7_png_handle_sRGB_882F4A40(png_ptr, info_ptr, length);
        else if (!memcmp(png_ptr->chunk_name, lbl_88009954, 4))
            ex7_png_handle_tRNS_882F4BB0(png_ptr, info_ptr, length);
        else
            ts4_if_call_seq_fn_882F37C8_882F4DE8(png_ptr, info_ptr, length);
    }
}

#define PNG2_FLAG_ZLIB_FINISHED 0x20u
#define PNG2_FLAG_ROW_INIT 0x40u
#define PNG2_AFTER_IDAT 0x08u
#define PNG2_INTERLACE 0x0002u
#define PNG2_Z_OK 0
#define PNG2_Z_STREAM_END 1
#define PNG2_Z_PARTIAL_FLUSH 1

typedef void (*png2_read_status_ptr)(png2_png_struct *png_ptr, unsigned int row_number, int pass);

extern const char lbl_88009A4C[]; /* "Invalid attempt to read row data" */
extern const char lbl_88009A34[]; /* "Not enough image data" */
extern const char lbl_88009A20[]; /* "Decompression error" */
extern const char lbl_88009A08[]; /* "Extra compressed data" */

void ex8_png_read_start_row_882F4028(png2_png_struct *png_ptr);
void ex7_png_crc_finish_882F42A8(png2_png_struct *png_ptr, unsigned int skip);
int png2_zlib_inflate_882F3178(png2_z_stream *strm, int flush); /* zlib inflate */
void ex7_png_read_filter_row_882F3E08(png2_png_struct *png_ptr, png2_png_row_info *row_info, unsigned char *row,
                                      unsigned char *prev_row, int filter);
void ts4_memcpy_forward_shifted_882EC208(png2_png_struct *png_ptr, void *dst, const void *src, unsigned int length); /* png_memcpy_check */
void ex7_png_do_read_transformations_882E9EE0(png2_png_struct *png_ptr);
void ex7_png_do_read_interlace_882F3AC8(png2_png_row_info *row_info, unsigned char *row, int pass, unsigned int transformations);
void png2_png_combine_row_882F3868(png2_png_struct *png_ptr, unsigned char *row, int mask); /* png_combine_row */
void png2_png_read_finish_row_882F4E58(png2_png_struct *png_ptr);                               /* png_read_finish_row */

/* Inflate and unfilter the next image row, apply the read transformations and combine it into the caller's
 * row and display-row buffers, handling interlace passes (libpng png_read_row). Swing_DLL.xex 0x882E7940 */
void png2_png_read_row_882E7940(png2_png_struct *png_ptr, unsigned char *row, unsigned char *dsp_row)
{
    int ret;

    if (!(png_ptr->flags & PNG2_FLAG_ROW_INIT))
        ex8_png_read_start_row_882F4028(png_ptr);

    if (png_ptr->interlaced && (png_ptr->transformations & PNG2_INTERLACE)) {
        switch (png_ptr->pass) {
        case 0:
            if (png_ptr->row_number & 0x07) {
                if (dsp_row != 0)
                    png2_png_combine_row_882F3868(png_ptr, dsp_row, png2_pass_dsp_mask[png_ptr->pass]);
                png2_png_read_finish_row_882F4E58(png_ptr);
                return;
            }
            break;
        case 1:
            if ((png_ptr->row_number & 0x07) || png_ptr->width < 5) {
                if (dsp_row != 0)
                    png2_png_combine_row_882F3868(png_ptr, dsp_row, png2_pass_dsp_mask[png_ptr->pass]);
                png2_png_read_finish_row_882F4E58(png_ptr);
                return;
            }
            break;
        case 2:
            if ((png_ptr->row_number & 0x07) != 4) {
                if (dsp_row != 0 && (png_ptr->row_number & 4))
                    png2_png_combine_row_882F3868(png_ptr, dsp_row, png2_pass_dsp_mask[png_ptr->pass]);
                png2_png_read_finish_row_882F4E58(png_ptr);
                return;
            }
            break;
        case 3:
            if ((png_ptr->row_number & 3) || png_ptr->width < 3) {
                if (dsp_row != 0)
                    png2_png_combine_row_882F3868(png_ptr, dsp_row, png2_pass_dsp_mask[png_ptr->pass]);
                png2_png_read_finish_row_882F4E58(png_ptr);
                return;
            }
            break;
        case 4:
            if ((png_ptr->row_number & 3) != 2) {
                if (dsp_row != 0 && (png_ptr->row_number & 2))
                    png2_png_combine_row_882F3868(png_ptr, dsp_row, png2_pass_dsp_mask[png_ptr->pass]);
                png2_png_read_finish_row_882F4E58(png_ptr);
                return;
            }
            break;
        case 5:
            if ((png_ptr->row_number & 1) || png_ptr->width < 2) {
                if (dsp_row != 0)
                    png2_png_combine_row_882F3868(png_ptr, dsp_row, png2_pass_dsp_mask[png_ptr->pass]);
                png2_png_read_finish_row_882F4E58(png_ptr);
                return;
            }
            break;
        case 6:
            if (!(png_ptr->row_number & 1)) {
                png2_png_read_finish_row_882F4E58(png_ptr);
                return;
            }
            break;
        }
    }

    if (!(png_ptr->mode & PNG2_HAVE_IDAT))
        png2_png_error_882E26E8(png_ptr, lbl_88009A4C);

    png_ptr->zstream.next_out = png_ptr->row_buf;
    png_ptr->zstream.avail_out = png_ptr->irowbytes;
    do {
        if (!(png_ptr->zstream.avail_in)) {
            while (!png_ptr->idat_size) {
                unsigned char chunk_length[4];

                ex7_png_crc_finish_882F42A8(png_ptr, 0);
                ts4_if_get_u32_off550_882EA0A0(png_ptr, chunk_length, 4);
                png_ptr->idat_size = ex8_png_get_uint_31_882F4238(png_ptr, chunk_length);
                ts4_call_seq_fn_882EC228_882E28C0(png_ptr);
                ts4_call_seq_fn_882EA0A0_882F36C8(png_ptr, png_ptr->chunk_name, 4);
                if (memcmp(png_ptr->chunk_name, lbl_8800992C, 4))
                    png2_png_error_882E26E8(png_ptr, lbl_88009A34);
            }
            png_ptr->zstream.avail_in = png_ptr->zbuf_size;
            png_ptr->zstream.next_in = png_ptr->zbuf;
            if (png_ptr->zbuf_size > png_ptr->idat_size)
                png_ptr->zstream.avail_in = png_ptr->idat_size;
            ts4_call_seq_fn_882EA0A0_882F36C8(png_ptr, png_ptr->zbuf, png_ptr->zstream.avail_in);
            png_ptr->idat_size -= png_ptr->zstream.avail_in;
        }
        ret = png2_zlib_inflate_882F3178(&png_ptr->zstream, PNG2_Z_PARTIAL_FLUSH);
        if (ret == PNG2_Z_STREAM_END) {
            if (png_ptr->zstream.avail_out || png_ptr->zstream.avail_in || png_ptr->idat_size)
                png2_png_error_882E26E8(png_ptr, lbl_88009A08);
            png_ptr->mode |= PNG2_AFTER_IDAT;
            png_ptr->flags |= PNG2_FLAG_ZLIB_FINISHED;
            break;
        }
        if (ret != PNG2_Z_OK)
            png2_png_error_882E26E8(png_ptr, png_ptr->zstream.msg ? png_ptr->zstream.msg : lbl_88009A20);
    } while (png_ptr->zstream.avail_out);

    png_ptr->row_info.color_type = png_ptr->color_type;
    png_ptr->row_info.width = png_ptr->iwidth;
    png_ptr->row_info.channels = png_ptr->channels;
    png_ptr->row_info.bit_depth = png_ptr->bit_depth;
    png_ptr->row_info.pixel_depth = png_ptr->pixel_depth;
    png_ptr->row_info.rowbytes = ((png_ptr->row_info.width * (unsigned int)png_ptr->row_info.pixel_depth + 7) >> 3);

    ex7_png_read_filter_row_882F3E08(png_ptr, &(png_ptr->row_info), png_ptr->row_buf + 1, png_ptr->prev_row + 1,
                                     (int)(png_ptr->row_buf[0]));
    ts4_memcpy_forward_shifted_882EC208(png_ptr, png_ptr->prev_row, png_ptr->row_buf, png_ptr->rowbytes + 1);

    if (png_ptr->transformations)
        ex7_png_do_read_transformations_882E9EE0(png_ptr);

    if (png_ptr->interlaced && (png_ptr->transformations & PNG2_INTERLACE)) {
        if (png_ptr->pass < 6)
            ex7_png_do_read_interlace_882F3AC8(&(png_ptr->row_info), png_ptr->row_buf + 1, png_ptr->pass,
                                               png_ptr->transformations);
        if (dsp_row != 0)
            png2_png_combine_row_882F3868(png_ptr, dsp_row, png2_pass_dsp_mask[png_ptr->pass]);
        if (row != 0)
            png2_png_combine_row_882F3868(png_ptr, row, lbl_880098EC[png_ptr->pass]);
    } else {
        if (row != 0)
            png2_png_combine_row_882F3868(png_ptr, row, 0xff);
        if (dsp_row != 0)
            png2_png_combine_row_882F3868(png_ptr, dsp_row, 0xff);
    }
    png2_png_read_finish_row_882F4E58(png_ptr);

    if (png_ptr->read_row_fn != 0)
        (*(png2_read_status_ptr)png_ptr->read_row_fn)(png_ptr, png_ptr->row_number, png_ptr->pass);
}
