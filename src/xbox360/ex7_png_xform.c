/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX7: libpng pngrtran.c / pngtrans.c row transforms (compiled with /O1). */

#include "ex6_png.h"
#include "ex7_png.h"

/* Scale samples down by the significant-bit shifts (libpng png_do_unshift). Swing_DLL.xex 0x882E87A0 */
void ex7_png_do_unshift_882E87A0(ex6_png_row_info *row_info, unsigned char *row, const ex7_png_color_8 *sig_bits)
{
    if (row_info->color_type != 3) {
        int shift[4];
        int channels = 0;
        int c;
        unsigned short value = 0;
        unsigned int row_width = row_info->width;

        if (row_info->color_type & 2) {
            shift[channels++] = row_info->bit_depth - sig_bits->red;
            shift[channels++] = row_info->bit_depth - sig_bits->green;
            shift[channels++] = row_info->bit_depth - sig_bits->blue;
        } else {
            shift[channels++] = row_info->bit_depth - sig_bits->gray;
        }
        if (row_info->color_type & 4)
            shift[channels++] = row_info->bit_depth - sig_bits->alpha;

        for (c = 0; c < channels; c++) {
            if (shift[c] <= 0)
                shift[c] = 0;
            else
                value = 1;
        }
        if (!value)
            return;

        switch (row_info->bit_depth) {
        case 2: {
            unsigned char *bp = row;
            unsigned int i;
            unsigned int istop = row_info->rowbytes;
            for (i = 0; i < istop; i++) {
                *bp >>= 1;
                *bp++ &= 0x55;
            }
            break;
        }
        case 4: {
            unsigned char *bp = row;
            unsigned char mask = (unsigned char)((((int)0xf0 >> shift[0]) & (int)0xf0) | (unsigned char)((int)0xf >> shift[0]));
            unsigned int i;
            unsigned int istop = row_info->rowbytes;
            for (i = 0; i < istop; i++) {
                *bp >>= shift[0];
                *bp++ &= mask;
            }
            break;
        }
        case 8: {
            unsigned char *bp = row;
            unsigned int i;
            unsigned int istop = row_width * channels;
            for (i = 0; i < istop; i++) {
                *bp++ >>= shift[i % channels];
            }
            break;
        }
        case 16: {
            unsigned char *bp = row;
            unsigned int i;
            unsigned int istop = channels * row_width;
            for (i = 0; i < istop; i++) {
                value = (unsigned short)((*bp << 8) + *(bp + 1));
                value >>= shift[i % channels];
                *bp++ = (unsigned char)(value >> 8);
                *bp++ = (unsigned char)(value & 0xff);
            }
            break;
        }
        }
    }
}

/* Apply the gamma table to a row (libpng png_do_gamma). Swing_DLL.xex 0x882E8CF8 */
void ex7_png_do_gamma_882E8CF8(ex6_png_row_info *row_info, unsigned char *row, unsigned char *gamma_table,
                               unsigned short **gamma_16_table, int gamma_shift)
{
    unsigned char *sp;
    unsigned int i;
    unsigned int row_width = row_info->width;

    if ((row_info->bit_depth <= 8 && gamma_table != 0) || (row_info->bit_depth == 16 && gamma_16_table != 0)) {
        switch (row_info->color_type) {
        case 2:
            if (row_info->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                }
            } else {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                }
            }
            break;
        case 6:
            if (row_info->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                    *sp = gamma_table[*sp];
                    sp++;
                    sp++;
                }
            } else {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 4;
                }
            }
            break;
        case 4:
            if (row_info->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp += 2;
                }
            } else {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v;
                    v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)((v >> 8) & 0xff);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 4;
                }
            }
            break;
        case 0:
            if (row_info->bit_depth == 2) {
                sp = row;
                for (i = 0; i < row_width; i += 4) {
                    int a = *sp & 0xc0;
                    int b = *sp & 0x30;
                    int c = *sp & 0x0c;
                    int d = *sp & 0x03;
                    *sp = (unsigned char)(((((int)gamma_table[a | (a >> 2) | (a >> 4) | (a >> 6)])) & 0xc0) |
                                          ((((int)gamma_table[(b << 2) | b | (b >> 2) | (b >> 4)]) >> 2) & 0x30) |
                                          ((((int)gamma_table[(c << 4) | (c << 2) | c | (c >> 2)]) >> 4) & 0x0c) |
                                          ((((int)gamma_table[(d << 6) | (d << 4) | (d << 2) | d]) >> 6)));
                    sp++;
                }
            }
            if (row_info->bit_depth == 4) {
                sp = row;
                for (i = 0; i < row_width; i += 2) {
                    int msb = *sp & 0xf0;
                    int lsb = *sp & 0x0f;
                    *sp = (unsigned char)((((int)gamma_table[msb | (msb >> 4)]) & 0xf0) |
                                          (((int)gamma_table[(lsb << 4) | lsb]) >> 4));
                    sp++;
                }
            } else if (row_info->bit_depth == 8) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    *sp = gamma_table[*sp];
                    sp++;
                }
            } else if (row_info->bit_depth == 16) {
                sp = row;
                for (i = 0; i < row_width; i++) {
                    unsigned short v = gamma_16_table[*(sp + 1) >> gamma_shift][*sp];
                    *sp = (unsigned char)(v >> 8);
                    *(sp + 1) = (unsigned char)(v & 0xff);
                    sp += 2;
                }
            }
            break;
        }
    }
}

/* Expand palette indices to RGB or RGBA, optionally with tRNS alpha (libpng png_do_expand_palette). Swing_DLL.xex 0x882E9158 */
void ex7_png_do_expand_palette_882E9158(ex6_png_row_info *row_info, unsigned char *row, const ex7_png_color *palette,
                                        const unsigned char *trans, int num_trans)
{
    int shift, value;
    unsigned char *sp, *dp;
    unsigned int i;
    unsigned int row_width = row_info->width;

    if (row_info->color_type == 3) {
        if (row_info->bit_depth < 8) {
            switch (row_info->bit_depth) {
            case 1:
                sp = row + ((row_width - 1) >> 3);
                dp = row + row_width - 1;
                shift = 7 - (int)((row_width + 7) & 0x07);
                for (i = 0; i < row_width; i++) {
                    if ((*sp >> shift) & 0x01)
                        *dp = 1;
                    else
                        *dp = 0;
                    if (shift == 7) {
                        shift = 0;
                        sp--;
                    } else
                        shift++;
                    dp--;
                }
                break;
            case 2:
                sp = row + ((row_width - 1) >> 2);
                dp = row + row_width - 1;
                shift = (int)((3 - ((row_width + 3) & 0x03)) << 1);
                for (i = 0; i < row_width; i++) {
                    value = (*sp >> shift) & 0x03;
                    *dp = (unsigned char)value;
                    if (shift == 6) {
                        shift = 0;
                        sp--;
                    } else
                        shift += 2;
                    dp--;
                }
                break;
            case 4:
                sp = row + ((row_width - 1) >> 1);
                dp = row + row_width - 1;
                shift = (int)((row_width & 0x01) << 2);
                for (i = 0; i < row_width; i++) {
                    value = (*sp >> shift) & 0x0f;
                    *dp = (unsigned char)value;
                    if (shift == 4) {
                        shift = 0;
                        sp--;
                    } else
                        shift += 4;
                    dp--;
                }
                break;
            }
            row_info->bit_depth = 8;
            row_info->pixel_depth = 8;
            row_info->rowbytes = row_width;
        }
        if (row_info->bit_depth == 8) {
            if (trans != 0) {
                sp = row + row_width - 1;
                dp = row + (row_width << 2) - 1;
                for (i = 0; i < row_width; i++) {
                    if ((int)(*sp) >= num_trans)
                        *dp-- = 0xff;
                    else
                        *dp-- = trans[*sp];
                    *dp-- = palette[*sp].blue;
                    *dp-- = palette[*sp].green;
                    *dp-- = palette[*sp].red;
                    sp--;
                }
                row_info->bit_depth = 8;
                row_info->pixel_depth = 32;
                row_info->rowbytes = row_width * 4;
                row_info->color_type = 6;
                row_info->channels = 4;
            } else {
                sp = row + row_width - 1;
                dp = row + (row_width * 3) - 1;
                for (i = 0; i < row_width; i++) {
                    *dp-- = palette[*sp].blue;
                    *dp-- = palette[*sp].green;
                    *dp-- = palette[*sp].red;
                    sp--;
                }
                row_info->bit_depth = 8;
                row_info->pixel_depth = 24;
                row_info->rowbytes = row_width * 3;
                row_info->color_type = 2;
                row_info->channels = 3;
            }
        }
    }
}

/* Expand gray/RGB rows to carry a tRNS alpha channel and bit depths below 8 to 8 (libpng png_do_expand). Swing_DLL.xex 0x882E93F8 */
void ex7_png_do_expand_882E93F8(ex6_png_row_info *row_info, unsigned char *row, const ex6_png_color_16 *trans_value)
{
    int shift, value;
    unsigned char *sp, *dp;
    unsigned int i;
    unsigned int row_width = row_info->width;

    if (row_info->color_type == 0) {
        unsigned short gray = (unsigned short)(trans_value ? trans_value->gray : 0);

        if (row_info->bit_depth < 8) {
            switch (row_info->bit_depth) {
            case 1:
                gray = (unsigned short)(gray * 0xff);
                sp = row + ((row_width - 1) >> 3);
                dp = row + row_width - 1;
                shift = 7 - (int)((row_width + 7) & 0x07);
                for (i = 0; i < row_width; i++) {
                    if ((*sp >> shift) & 0x01)
                        *dp = 0xff;
                    else
                        *dp = 0;
                    if (shift == 7) {
                        shift = 0;
                        sp--;
                    } else
                        shift++;
                    dp--;
                }
                break;
            case 2:
                gray = (unsigned short)(gray * 0x55);
                sp = row + ((row_width - 1) >> 2);
                dp = row + row_width - 1;
                shift = (int)((3 - ((row_width + 3) & 0x03)) << 1);
                for (i = 0; i < row_width; i++) {
                    value = (*sp >> shift) & 0x03;
                    *dp = (unsigned char)(value | (value << 2) | (value << 4) | (value << 6));
                    if (shift == 6) {
                        shift = 0;
                        sp--;
                    } else
                        shift += 2;
                    dp--;
                }
                break;
            case 4:
                gray = (unsigned short)(gray * 0x11);
                sp = row + ((row_width - 1) >> 1);
                dp = row + row_width - 1;
                shift = (int)((1 - ((row_width + 1) & 0x01)) << 2);
                for (i = 0; i < row_width; i++) {
                    value = (*sp >> shift) & 0x0f;
                    *dp = (unsigned char)(value | (value << 4));
                    if (shift == 4) {
                        shift = 0;
                        sp--;
                    } else
                        shift = 4;
                    dp--;
                }
                break;
            }
            row_info->bit_depth = 8;
            row_info->pixel_depth = 8;
            row_info->rowbytes = row_width;
        }

        if (trans_value != 0) {
            if (row_info->bit_depth == 8) {
                sp = row + row_width - 1;
                dp = row + (row_width << 1) - 1;
                for (i = 0; i < row_width; i++) {
                    if (*sp == gray)
                        *dp-- = 0;
                    else
                        *dp-- = 0xff;
                    *dp-- = *sp--;
                }
            } else if (row_info->bit_depth == 16) {
                sp = row + row_info->rowbytes - 1;
                dp = row + (row_info->rowbytes << 1) - 1;
                for (i = 0; i < row_width; i++) {
                    if (((*(sp - 1) << 8) | *(sp)) == gray) {
                        *dp-- = 0;
                        *dp-- = 0;
                    } else {
                        *dp-- = 0xff;
                        *dp-- = 0xff;
                    }
                    *dp-- = *sp--;
                    *dp-- = *sp--;
                }
            }
            row_info->color_type = 4;
            row_info->channels = 2;
            row_info->pixel_depth = (unsigned char)(row_info->bit_depth << 1);
            row_info->rowbytes = ((row_width * row_info->pixel_depth) >> 3);
        }
    } else if (row_info->color_type == 2 && trans_value) {
        if (row_info->bit_depth == 8) {
            sp = row + row_info->rowbytes - 1;
            dp = row + (row_width << 2) - 1;
            for (i = 0; i < row_width; i++) {
                if (*(sp - 2) == trans_value->red && *(sp - 1) == trans_value->green && *(sp) == trans_value->blue)
                    *dp-- = 0;
                else
                    *dp-- = 0xff;
                *dp-- = *sp--;
                *dp-- = *sp--;
                *dp-- = *sp--;
            }
        } else if (row_info->bit_depth == 16) {
            sp = row + row_info->rowbytes - 1;
            dp = row + (row_width << 3) - 1;
            for (i = 0; i < row_width; i++) {
                if (((*(sp - 5) << 8) | *(sp - 4)) == trans_value->red &&
                    ((*(sp - 3) << 8) | *(sp - 2)) == trans_value->green &&
                    ((*(sp - 1) << 8) | *(sp)) == trans_value->blue) {
                    *dp-- = 0;
                    *dp-- = 0;
                } else {
                    *dp-- = 0xff;
                    *dp-- = 0xff;
                }
                *dp-- = *sp--;
                *dp-- = *sp--;
                *dp-- = *sp--;
                *dp-- = *sp--;
                *dp-- = *sp--;
                *dp-- = *sp--;
            }
        }
        row_info->color_type = 6;
        row_info->channels = 4;
        row_info->pixel_depth = (unsigned char)(row_info->bit_depth << 2);
        row_info->rowbytes = ((row_width * row_info->pixel_depth) >> 3);
    }
}

