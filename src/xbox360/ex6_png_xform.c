/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX6: libpng pngget.c / pngtrans.c routines. */

#include "ex6_png.h"

void ts4_if_get_u32_off544_882E2720(ex6_png_struct *png_ptr, const char *message); /* png_warning */
extern const char lbl_88009A70[]; /* rowbytes overflow warning */

/* Copy the IHDR fields out of the info struct (libpng png_get_IHDR). Swing_DLL.xex 0x882E8110 */
unsigned int ex6_png_get_IHDR_882E8110(ex6_png_struct *png_ptr, ex6_png_info *info_ptr, unsigned int *width,
                                       unsigned int *height, int *bit_depth, int *color_type, int *interlace_type,
                                       int *compression_type, int *filter_type)
{
    int channels;
    if (png_ptr == 0 || info_ptr == 0 || width == 0 || height == 0 || bit_depth == 0 || color_type == 0)
        return 0;
    *width = info_ptr->width;
    *height = info_ptr->height;
    *bit_depth = info_ptr->bit_depth;
    *color_type = info_ptr->color_type;
    if (compression_type != 0)
        *compression_type = info_ptr->compression_type;
    if (filter_type != 0)
        *filter_type = info_ptr->filter_type;
    if (interlace_type != 0)
        *interlace_type = info_ptr->interlace_type;
    if (*color_type == 3)
        channels = 1;
    else
        channels = (*color_type & 2) | 1;
    if (*color_type & 4)
        channels++;
    if (*width > 0x7fffffffu / (unsigned int)((channels * *bit_depth + 7) >> 3))
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88009A70);
    return 1;
}

/* Swap the red and blue samples of every pixel in an RGB/RGBA row (libpng png_do_bgr). Swing_DLL.xex 0x882E8350 */
void ex6_png_do_bgr_882E8350(ex6_png_row_info *row_info, unsigned char *row)
{
    if (row_info->color_type & 2) {
        unsigned int i;
        unsigned int istop = row_info->width;
        unsigned char *rp = row;
        if (row_info->bit_depth == 8) {
            if (row_info->color_type == 2) {
                for (i = 0; i < istop; i++, rp += 3) {
                    unsigned char save = *rp;
                    *rp = *(rp + 2);
                    *(rp + 2) = save;
                }
            } else if (row_info->color_type == 6) {
                for (i = 0; i < istop; i++, rp += 4) {
                    unsigned char save = *rp;
                    *rp = *(rp + 2);
                    *(rp + 2) = save;
                }
            }
        } else if (row_info->bit_depth == 16) {
            if (row_info->color_type == 2) {
                for (i = 0; i < istop; i++, rp += 6) {
                    unsigned char save0 = *rp;
                    unsigned char save1 = *(rp + 1);
                    *rp = *(rp + 4);
                    *(rp + 1) = *(rp + 5);
                    *(rp + 4) = save0;
                    *(rp + 5) = save1;
                }
            } else if (row_info->color_type == 6) {
                for (i = 0; i < istop; i++, rp += 8) {
                    unsigned char save0 = *rp;
                    unsigned char save1 = *(rp + 1);
                    *rp = *(rp + 4);
                    *(rp + 1) = *(rp + 5);
                    *(rp + 4) = save0;
                    *(rp + 5) = save1;
                }
            }
        }
    }
}

/* Expand 1/2/4-bit samples of a row to one byte per sample, working backwards in place (libpng png_do_unpack).
 * Swing_DLL.xex 0x882E8630 */
void ex6_png_do_unpack_882E8630(ex6_png_row_info *row_info, unsigned char *row)
{
    if (row_info->bit_depth < 8) {
        unsigned int i;
        unsigned int row_width = row_info->width;
        switch (row_info->bit_depth) {
        case 1: {
            unsigned char *sp = row + ((row_width - 1) >> 3);
            unsigned char *dp = row + row_width - 1;
            unsigned int shift = 7 - ((row_width + 7) & 0x07);
            for (i = 0; i < row_width; i++) {
                *dp = (unsigned char)((*sp >> shift) & 0x01);
                if (shift == 7) {
                    shift = 0;
                    sp--;
                } else
                    shift++;
                dp--;
            }
            break;
        }
        case 2: {
            unsigned char *sp = row + ((row_width - 1) >> 2);
            unsigned char *dp = row + row_width - 1;
            unsigned int shift = (3 - ((row_width + 3) & 0x03)) << 1;
            for (i = 0; i < row_width; i++) {
                *dp = (unsigned char)((*sp >> shift) & 0x03);
                if (shift == 6) {
                    shift = 0;
                    sp--;
                } else
                    shift += 2;
                dp--;
            }
            break;
        }
        case 4: {
            unsigned char *sp = row + ((row_width - 1) >> 1);
            unsigned char *dp = row + row_width - 1;
            unsigned int shift = (1 - ((row_width + 1) & 0x01)) << 2;
            for (i = 0; i < row_width; i++) {
                *dp = (unsigned char)((*sp >> shift) & 0x0f);
                if (shift == 4) {
                    shift = 0;
                    sp--;
                } else
                    shift = 4;
                dp--;
            }
            break;
        }
        }
        row_info->bit_depth = 8;
        row_info->pixel_depth = (unsigned char)(8 * row_info->channels);
        row_info->rowbytes = row_width * row_info->channels;
    }
}

#define EX6_PNG_PACK 0x0004u
#define EX6_PNG_DITHER 0x0040u
#define EX6_PNG_16_TO_8 0x0400u
#define EX6_PNG_EXPAND 0x1000u
#define EX6_PNG_GAMMA 0x2000u
#define EX6_PNG_FILLER 0x8000u

/* Update the info struct to describe the image after the read transforms (expand, gamma, 16-to-8, dither, pack,
 * filler) have been applied (libpng png_read_transform_info). Swing_DLL.xex 0x882E84A8 */
void ex6_png_read_transform_info_882E84A8(ex6_png_struct *png_ptr, ex6_png_info *info_ptr)
{
    if (png_ptr->transformations & EX6_PNG_EXPAND) {
        if (info_ptr->color_type == 3) {
            if (png_ptr->num_trans)
                info_ptr->color_type = 6;
            else
                info_ptr->color_type = 2;
            info_ptr->bit_depth = 8;
            info_ptr->num_trans = 0;
        } else {
            if (png_ptr->num_trans)
                info_ptr->color_type |= 4;
            if (info_ptr->bit_depth < 8)
                info_ptr->bit_depth = 8;
            info_ptr->num_trans = 0;
        }
    }
    if (png_ptr->transformations & EX6_PNG_GAMMA)
        info_ptr->gamma = png_ptr->gamma;
    if ((png_ptr->transformations & EX6_PNG_16_TO_8) && info_ptr->bit_depth == 16)
        info_ptr->bit_depth = 8;
    if (png_ptr->transformations & EX6_PNG_DITHER) {
        if ((info_ptr->color_type == 2 || info_ptr->color_type == 6) && png_ptr->palette_lookup &&
            info_ptr->bit_depth == 8)
            info_ptr->color_type = 3;
    }
    if ((png_ptr->transformations & EX6_PNG_PACK) && info_ptr->bit_depth < 8)
        info_ptr->bit_depth = 8;
    if (info_ptr->color_type == 3)
        info_ptr->channels = 1;
    else if (info_ptr->color_type & 2)
        info_ptr->channels = 3;
    else
        info_ptr->channels = 1;
    if (info_ptr->color_type & 4)
        info_ptr->channels++;
    if (png_ptr->transformations & EX6_PNG_FILLER) {
        if (info_ptr->color_type == 2 || info_ptr->color_type == 0)
            info_ptr->channels++;
    }
    info_ptr->pixel_depth = (unsigned char)(info_ptr->channels * info_ptr->bit_depth);
    info_ptr->rowbytes = (info_ptr->pixel_depth * info_ptr->width + 7) >> 3;
}

#define EX6_PNG_FLAG_FILLER_AFTER 0x0080u

/* Insert a filler sample into every pixel of a gray or RGB row, working backwards in place
 * (libpng png_do_read_filler). Swing_DLL.xex 0x882E8A30 */
void ex6_png_do_read_filler_882E8A30(ex6_png_row_info *row_info, unsigned char *row, unsigned int filler,
                                     unsigned int flags)
{
    unsigned int i;
    unsigned int row_width = row_info->width;
    unsigned char hi_filler = (unsigned char)((filler >> 8) & 0xff);
    unsigned char lo_filler = (unsigned char)(filler & 0xff);

    if (row_info->color_type == 0) {
        if (row_info->bit_depth == 8) {
            if (flags & EX6_PNG_FLAG_FILLER_AFTER) {
                unsigned char *sp = row + row_width;
                unsigned char *dp = sp + row_width;
                for (i = 1; i < row_width; i++) {
                    *(--dp) = lo_filler;
                    *(--dp) = *(--sp);
                }
                *(--dp) = lo_filler;
                row_info->channels = 2;
                row_info->pixel_depth = 16;
                row_info->rowbytes = row_width * 2;
            } else {
                unsigned char *sp = row + row_width;
                unsigned char *dp = sp + row_width;
                for (i = 0; i < row_width; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = lo_filler;
                }
                row_info->channels = 2;
                row_info->pixel_depth = 16;
                row_info->rowbytes = row_width * 2;
            }
        } else if (row_info->bit_depth == 16) {
            if (flags & EX6_PNG_FLAG_FILLER_AFTER) {
                unsigned char *sp = row + row_width * 2;
                unsigned char *dp = sp + row_width * 2;
                for (i = 1; i < row_width; i++) {
                    *(--dp) = hi_filler;
                    *(--dp) = lo_filler;
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                }
                *(--dp) = hi_filler;
                *(--dp) = lo_filler;
                row_info->channels = 2;
                row_info->pixel_depth = 32;
                row_info->rowbytes = row_width * 4;
            } else {
                unsigned char *sp = row + row_width * 2;
                unsigned char *dp = sp + row_width * 2;
                for (i = 0; i < row_width; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = hi_filler;
                    *(--dp) = lo_filler;
                }
                row_info->channels = 2;
                row_info->pixel_depth = 32;
                row_info->rowbytes = row_width * 4;
            }
        }
    } else if (row_info->color_type == 2) {
        if (row_info->bit_depth == 8) {
            if (flags & EX6_PNG_FLAG_FILLER_AFTER) {
                unsigned char *sp = row + row_width * 3;
                unsigned char *dp = sp + row_width;
                for (i = 1; i < row_width; i++) {
                    *(--dp) = lo_filler;
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                }
                *(--dp) = lo_filler;
                row_info->channels = 4;
                row_info->pixel_depth = 32;
                row_info->rowbytes = row_width * 4;
            } else {
                unsigned char *sp = row + row_width * 3;
                unsigned char *dp = sp + row_width;
                for (i = 0; i < row_width; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = lo_filler;
                }
                row_info->channels = 4;
                row_info->pixel_depth = 32;
                row_info->rowbytes = row_width * 4;
            }
        } else if (row_info->bit_depth == 16) {
            if (flags & EX6_PNG_FLAG_FILLER_AFTER) {
                unsigned char *sp = row + row_width * 6;
                unsigned char *dp = sp + row_width * 2;
                for (i = 1; i < row_width; i++) {
                    *(--dp) = hi_filler;
                    *(--dp) = lo_filler;
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                }
                *(--dp) = hi_filler;
                *(--dp) = lo_filler;
                row_info->channels = 4;
                row_info->pixel_depth = 64;
                row_info->rowbytes = row_width * 8;
            } else {
                unsigned char *sp = row + row_width * 6;
                unsigned char *dp = sp + row_width * 2;
                for (i = 0; i < row_width; i++) {
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = *(--sp);
                    *(--dp) = hi_filler;
                    *(--dp) = lo_filler;
                }
                row_info->channels = 4;
                row_info->pixel_depth = 64;
                row_info->rowbytes = row_width * 8;
            }
        }
    }
}

/* Reduce an RGB/RGBA row to palette indices through the 5-5-5 palette lookup, or remap palette indices through the
 * dither lookup (libpng png_do_dither). Swing_DLL.xex 0x882E98A0 */
void ex6_png_do_dither_882E98A0(ex6_png_row_info *row_info, unsigned char *row, unsigned char *palette_lookup,
                                unsigned char *dither_lookup)
{
    unsigned char *sp;
    unsigned char *dp;
    unsigned int i;
    unsigned int row_width = row_info->width;

    if (row_info->color_type == 2 && palette_lookup && row_info->bit_depth == 8) {
        int r, g, b, p;
        sp = row;
        dp = row;
        for (i = 0; i < row_width; i++) {
            r = *sp++;
            g = *sp++;
            b = *sp++;
            p = (((r >> 3) & 31) << 10) | (((g >> 3) & 31) << 5) | ((b >> 3) & 31);
            *dp++ = palette_lookup[p];
        }
        row_info->color_type = 3;
        row_info->channels = 1;
        row_info->pixel_depth = row_info->bit_depth;
        row_info->rowbytes = ((row_width * row_info->pixel_depth + 7) >> 3);
    } else if (row_info->color_type == 6 && palette_lookup && row_info->bit_depth == 8) {
        int r, g, b, p;
        sp = row;
        dp = row;
        for (i = 0; i < row_width; i++) {
            r = *sp++;
            g = *sp++;
            b = *sp++;
            sp++;
            p = (((r >> 3) & 31) << 10) | (((g >> 3) & 31) << 5) | ((b >> 3) & 31);
            *dp++ = palette_lookup[p];
        }
        row_info->color_type = 3;
        row_info->channels = 1;
        row_info->pixel_depth = row_info->bit_depth;
        row_info->rowbytes = ((row_width * row_info->pixel_depth + 7) >> 3);
    } else if (row_info->color_type == 3 && dither_lookup && row_info->bit_depth == 8) {
        sp = row;
        for (i = 0; i < row_width; i++, sp++)
            *sp = dither_lookup[*sp];
    }
}
