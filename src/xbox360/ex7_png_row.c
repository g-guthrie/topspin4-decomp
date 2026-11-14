/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX7: libpng pngrutil.c row filtering and interlacing (compiled with /O1). */

#include "ex7_png.h"

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

#ifdef _MSC_VER
extern int abs(int);
#pragma intrinsic(abs)
#else
#include <stdlib.h>
#endif

void ts4_if_get_u32_off544_882E2720(ex7_png_struct *png_ptr, const char *message); /* png_warning */
extern const char lbl_88026378[]; /* "Ignoring bad adaptive filter type" */

/* Undo the PNG scanline filter for one row (libpng png_read_filter_row). Swing_DLL.xex 0x882F3E08 */
void ex7_png_read_filter_row_882F3E08(ex7_png_struct *png_ptr, ex7_png_row_info *row_info, unsigned char *row,
                                      unsigned char *prev_row, int filter)
{
    switch (filter) {
    case 0:
        break;
    case 1: {
        unsigned int i;
        unsigned int istop = row_info->rowbytes;
        unsigned int bpp = (row_info->pixel_depth + 7) >> 3;
        unsigned char *rp = row + bpp;
        unsigned char *lp = row;

        for (i = bpp; i < istop; i++) {
            *rp = (unsigned char)(((int)(*rp) + (int)(*lp++)) & 0xff);
            rp++;
        }
        break;
    }
    case 2: {
        unsigned int i;
        unsigned int istop = row_info->rowbytes;
        unsigned char *rp = row;
        unsigned char *pp = prev_row;

        for (i = 0; i < istop; i++) {
            *rp = (unsigned char)(((int)(*rp) + (int)(*pp++)) & 0xff);
            rp++;
        }
        break;
    }
    case 3: {
        unsigned int i;
        unsigned char *rp = row;
        unsigned char *pp = prev_row;
        unsigned char *lp = row;
        unsigned int bpp = (row_info->pixel_depth + 7) >> 3;
        unsigned int istop = row_info->rowbytes - bpp;

        for (i = 0; i < bpp; i++) {
            *rp = (unsigned char)(((int)(*rp) + ((int)(*pp++) / 2)) & 0xff);
            rp++;
        }
        for (i = 0; i < istop; i++) {
            *rp = (unsigned char)(((int)(*rp) + (int)(*pp++ + *lp++) / 2) & 0xff);
            rp++;
        }
        break;
    }
    case 4: {
        unsigned int i;
        unsigned char *rp = row;
        unsigned char *pp = prev_row;
        unsigned char *lp = row;
        unsigned char *cp = prev_row;
        unsigned int bpp = (row_info->pixel_depth + 7) >> 3;
        unsigned int istop = row_info->rowbytes - bpp;

        for (i = 0; i < bpp; i++) {
            *rp = (unsigned char)(((int)(*rp) + (int)(*pp++)) & 0xff);
            rp++;
        }
        for (i = 0; i < istop; i++) {
            int a, b, c, pa, pb, pc, p;

            a = *lp++;
            b = *pp++;
            c = *cp++;
            p = b - c;
            pc = a - c;
            pa = abs(p);
            pb = abs(pc);
            pc = abs(p + pc);
            if (pa <= pb && pa <= pc)
                p = a;
            else if (pb <= pc)
                p = b;
            else
                p = c;
            *rp = (unsigned char)(((int)(*rp) + p) & 0xff);
            rp++;
        }
        break;
    }
    default:
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026378);
        *row = 0;
        break;
    }
}

extern const unsigned int lbl_88026308[]; /* png_pass_inc */

/* Spread an interlaced pass row out to the full image width (libpng png_do_read_interlace). Swing_DLL.xex 0x882F3AC8 */
void ex7_png_do_read_interlace_882F3AC8(ex7_png_row_info *row_info, unsigned char *row, int pass)
{
    if (row != 0 && row_info != 0) {
        unsigned int final_width;

        final_width = row_info->width * lbl_88026308[pass];
        switch (row_info->pixel_depth) {
        case 1: {
            unsigned char *sp = row + ((row_info->width - 1) >> 3);
            unsigned char *dp = row + ((final_width - 1) >> 3);
            int sshift, dshift;
            int s_start, s_end, s_inc;
            int jstop = lbl_88026308[pass];
            unsigned char v;
            unsigned int i;
            int j;

            sshift = (int)(7 - ((row_info->width + 7) & 0x07));
            dshift = (int)(7 - ((final_width + 7) & 0x07));
            s_start = 0;
            s_end = 7;
            s_inc = 1;
            for (i = 0; i < row_info->width; i++) {
                v = (unsigned char)((*sp >> sshift) & 0x01);
                for (j = 0; j < jstop; j++) {
                    *dp &= (unsigned char)((0x7f7f >> (7 - dshift)) & 0xff);
                    *dp |= (unsigned char)(v << dshift);
                    if (dshift == s_end) {
                        dshift = s_start;
                        dp--;
                    } else
                        dshift += s_inc;
                }
                if (sshift == s_end) {
                    sshift = s_start;
                    sp--;
                } else
                    sshift += s_inc;
            }
            break;
        }
        case 2: {
            unsigned char *sp = row + ((row_info->width - 1) >> 2);
            unsigned char *dp = row + ((final_width - 1) >> 2);
            int sshift, dshift;
            int s_start, s_end, s_inc;
            int jstop = lbl_88026308[pass];
            unsigned char v;
            unsigned int i;
            int j;

            sshift = (int)((3 - ((row_info->width + 3) & 0x03)) << 1);
            dshift = (int)((3 - ((final_width + 3) & 0x03)) << 1);
            s_start = 0;
            s_end = 6;
            s_inc = 2;
            for (i = 0; i < row_info->width; i++) {
                v = (unsigned char)((*sp >> sshift) & 0x03);
                for (j = 0; j < jstop; j++) {
                    *dp &= (unsigned char)((0x3f3f >> (6 - dshift)) & 0xff);
                    *dp |= (unsigned char)(v << dshift);
                    if (dshift == s_end) {
                        dshift = s_start;
                        dp--;
                    } else
                        dshift += s_inc;
                }
                if (sshift == s_end) {
                    sshift = s_start;
                    sp--;
                } else
                    sshift += s_inc;
            }
            break;
        }
        case 4: {
            unsigned char *sp = row + ((row_info->width - 1) >> 1);
            unsigned char *dp = row + ((final_width - 1) >> 1);
            int sshift, dshift;
            int s_start, s_end, s_inc;
            int jstop = lbl_88026308[pass];
            unsigned char v;
            unsigned int i;
            int j;

            sshift = (int)((1 - ((row_info->width + 1) & 0x01)) << 2);
            dshift = (int)((1 - ((final_width + 1) & 0x01)) << 2);
            s_start = 0;
            s_end = 4;
            s_inc = 4;
            for (i = 0; i < row_info->width; i++) {
                v = (unsigned char)((*sp >> sshift) & 0x0f);
                for (j = 0; j < jstop; j++) {
                    *dp &= (unsigned char)((0xf0f >> (4 - dshift)) & 0xff);
                    *dp |= (unsigned char)(v << dshift);
                    if (dshift == s_end) {
                        dshift = s_start;
                        dp--;
                    } else
                        dshift += s_inc;
                }
                if (sshift == s_end) {
                    sshift = s_start;
                    sp--;
                } else
                    sshift += s_inc;
            }
            break;
        }
        default: {
            unsigned int pixel_bytes = (row_info->pixel_depth >> 3);
            unsigned char *sp = row + (row_info->width - 1) * pixel_bytes;
            unsigned char *dp = row + (final_width - 1) * pixel_bytes;
            int jstop = lbl_88026308[pass];
            unsigned int i;

            for (i = 0; i < row_info->width; i++) {
                unsigned char v[8];
                int j;

                memcpy(v, sp, pixel_bytes);
                for (j = 0; j < jstop; j++) {
                    memcpy(dp, v, pixel_bytes);
                    dp -= pixel_bytes;
                }
                sp -= pixel_bytes;
            }
            break;
        }
        }
        row_info->width = final_width;
        row_info->rowbytes = ((final_width * row_info->pixel_depth) + 7) >> 3;
    }
}
