/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libpng pngrutil.c / pngread.c helpers (compiled with /O1). */

#include "ex8_png.h"

void fn_882E26E8(ex8_png_struct *png_ptr, const char *message);       /* png_error */
void fn_882E2738(ex8_png_struct *png_ptr, const char *message);       /* png_chunk_error */
void ex7_png_init_read_transformations_882E9D60(ex8_png_struct *png_ptr);                             /* png_init_read_transformations */
void *ts4_if_call_seq_fn_88888668_882EC170(ex8_png_struct *png_ptr, unsigned int size); /* png_malloc */
void ts4_memset_forward_shifted_882EC218(ex8_png_struct *png_ptr, void *s, int value, unsigned int length);

extern const char lbl_8802639C[]; /* "PNG unsigned integer out of range." */
extern const char lbl_88026364[]; /* "invalid chunk type" */

/* Reads a 31-bit big-endian value from a chunk header (libpng png_get_uint_31). */
unsigned int ex8_png_get_uint_31_882F4238(ex8_png_struct *png_ptr, const unsigned char *buf)
{
    unsigned int i = ((unsigned int)(*buf) << 24) + ((unsigned int)(*(buf + 1)) << 16) +
                     ((unsigned int)(*(buf + 2)) << 8) + (unsigned int)(*(buf + 3));

    if (i > 0x7fffffffU)
        fn_882E26E8(png_ptr, lbl_8802639C);
    return i;
}

#define EX8_ISNONALPHA(c) ((c) < 41 || (c) > 122 || ((c) > 90 && (c) < 97))

/* Rejects a chunk name containing non-letters (libpng png_check_chunk_name). */
void ex8_png_check_chunk_name_882F37C8(ex8_png_struct *png_ptr, const unsigned char *chunk_name)
{
    if (EX8_ISNONALPHA(chunk_name[0]) || EX8_ISNONALPHA(chunk_name[1]) || EX8_ISNONALPHA(chunk_name[2]) ||
        EX8_ISNONALPHA(chunk_name[3]))
        fn_882E2738(png_ptr, lbl_88026364);
}

/* Interlace pass tables (start column, column step, start row, row step), laid out as one block. */
extern const int lbl_880262EC[28];

/* Computes the row geometry for the next image pass and allocates the row buffers. */
void ex8_png_read_start_row_882F4028(ex8_png_struct *png_ptr)
{
    int max_pixel_depth;
    unsigned int row_bytes;

    png_ptr->zstream.avail_in = 0;
    ex7_png_init_read_transformations_882E9D60(png_ptr);
    if (png_ptr->interlaced) {
        if (!(png_ptr->transformations & 0x2))
            png_ptr->num_rows = (png_ptr->height + 8 - 1 - 0) / 8;
        else
            png_ptr->num_rows = png_ptr->height;
        png_ptr->iwidth = (png_ptr->width + lbl_880262EC[7 + png_ptr->pass] - 1 - lbl_880262EC[png_ptr->pass]) /
                          lbl_880262EC[7 + png_ptr->pass];
        row_bytes = ((png_ptr->iwidth * png_ptr->pixel_depth + 7) >> 3) + 1;
        png_ptr->irowbytes = row_bytes;
    } else {
        png_ptr->num_rows = png_ptr->height;
        png_ptr->iwidth = png_ptr->width;
        png_ptr->irowbytes = png_ptr->rowbytes + 1;
    }
    max_pixel_depth = png_ptr->pixel_depth;
    if ((png_ptr->transformations & 0x4) && png_ptr->bit_depth < 8)
        max_pixel_depth = 8;
    if (png_ptr->transformations & 0x1000) {
        if (png_ptr->color_type == 3) {
            if (png_ptr->num_trans)
                max_pixel_depth = 32;
            else
                max_pixel_depth = 24;
        } else if (png_ptr->color_type == 0) {
            if (max_pixel_depth < 8)
                max_pixel_depth = 8;
            if (png_ptr->num_trans)
                max_pixel_depth *= 2;
        } else if (png_ptr->color_type == 2) {
            if (png_ptr->num_trans) {
                max_pixel_depth *= 4;
                max_pixel_depth /= 3;
            }
        }
    }
    if (png_ptr->transformations & 0x8000) {
        if (png_ptr->color_type == 3) {
            max_pixel_depth = 32;
        } else if (png_ptr->color_type == 0) {
            if (max_pixel_depth <= 8)
                max_pixel_depth = 16;
            else
                max_pixel_depth = 32;
        } else if (png_ptr->color_type == 2) {
            if (max_pixel_depth <= 32)
                max_pixel_depth = 32;
            else
                max_pixel_depth = 64;
        }
    }
    row_bytes = ((png_ptr->width + 7) & ~7U);
    row_bytes = ((row_bytes * max_pixel_depth + 7) >> 3) + 1 + ((max_pixel_depth + 7) >> 3);
    png_ptr->row_buf = ts4_if_call_seq_fn_88888668_882EC170(png_ptr, row_bytes);
    png_ptr->prev_row = ts4_if_call_seq_fn_88888668_882EC170(png_ptr, png_ptr->rowbytes + 1);
    ts4_memset_forward_shifted_882EC218(png_ptr, png_ptr->prev_row, 0, png_ptr->rowbytes + 1);
    png_ptr->flags |= 0x40;
}
