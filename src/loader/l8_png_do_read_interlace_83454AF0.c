/* Loader_DLL.xex 0x83454AF0-0x83454E2C, executable version 0.0.0.3. */
/* Library routine: libpng png_do_read_interlace (no PACKSWAP). */

typedef unsigned char ts4l_u8;
typedef unsigned int ts4l_u32;

typedef struct ts4l_png_row_info {
    ts4l_u32 width;
    ts4l_u32 rowbytes;
    ts4l_u8 color_type;
    ts4l_u8 bit_depth;
    ts4l_u8 channels;
    ts4l_u8 pixel_depth;
} ts4l_png_row_info;

extern int lbl_8307AC64[];

void *fn_833E3AD0(void *dst, const void *src, ts4l_u32 n);

void ts4l_png_do_read_interlace_83454AF0(ts4l_png_row_info *row_info, ts4l_u8 *row, int pass)
{
    if (row != 0 && row_info != 0) {
        ts4l_u32 final_width;

        final_width = row_info->width * lbl_8307AC64[pass];
        switch (row_info->pixel_depth) {
        case 1: {
            ts4l_u8 *sp = row + (row_info->width - 1) / 8;
            ts4l_u8 *dp = row + (final_width - 1) / 8;
            int sshift, dshift;
            int jstop = lbl_8307AC64[pass];
            ts4l_u8 v;
            ts4l_u32 i;
            int j;

            sshift = (int)(7 - ((row_info->width + 7) & 0x07));
            dshift = (int)(7 - ((final_width + 7) & 0x07));
            for (i = 0; i < row_info->width; i++) {
                v = (ts4l_u8)((*sp >> sshift) & 0x01);
                for (j = 0; j < jstop; j++) {
                    *dp &= (ts4l_u8)((0x7f7f >> (7 - dshift)) & 0xff);
                    *dp |= (ts4l_u8)(v << dshift);
                    if (dshift == 7) {
                        dshift = 0;
                        dp--;
                    } else {
                        dshift += 1;
                    }
                }
                if (sshift == 7) {
                    sshift = 0;
                    sp--;
                } else {
                    sshift += 1;
                }
            }
            break;
        }
        case 2: {
            ts4l_u8 *sp = row + (row_info->width - 1) / 4;
            ts4l_u8 *dp = row + (final_width - 1) / 4;
            int sshift, dshift;
            int jstop = lbl_8307AC64[pass];
            ts4l_u8 v;
            ts4l_u32 i;
            int j;

            sshift = (int)((3 - ((row_info->width + 3) & 0x03)) << 1);
            dshift = (int)((3 - ((final_width + 3) & 0x03)) << 1);
            for (i = 0; i < row_info->width; i++) {
                v = (ts4l_u8)((*sp >> sshift) & 0x03);
                for (j = 0; j < jstop; j++) {
                    *dp &= (ts4l_u8)((0x3f3f >> (6 - dshift)) & 0xff);
                    *dp |= (ts4l_u8)(v << dshift);
                    if (dshift == 6) {
                        dshift = 0;
                        dp--;
                    } else {
                        dshift += 2;
                    }
                }
                if (sshift == 6) {
                    sshift = 0;
                    sp--;
                } else {
                    sshift += 2;
                }
            }
            break;
        }
        case 4: {
            ts4l_u8 *sp = row + (row_info->width - 1) / 2;
            ts4l_u8 *dp = row + (final_width - 1) / 2;
            int sshift, dshift;
            int jstop = lbl_8307AC64[pass];
            ts4l_u8 v;
            ts4l_u32 i;
            int j;

            sshift = (int)((1 - ((row_info->width + 1) & 0x01)) << 2);
            dshift = (int)((1 - ((final_width + 1) & 0x01)) << 2);
            for (i = 0; i < row_info->width; i++) {
                v = (ts4l_u8)((*sp >> sshift) & 0xf);
                for (j = 0; j < jstop; j++) {
                    *dp &= (ts4l_u8)((0xf0f >> (4 - dshift)) & 0xff);
                    *dp |= (ts4l_u8)(v << dshift);
                    if (dshift == 4) {
                        dshift = 0;
                        dp--;
                    } else {
                        dshift += 4;
                    }
                }
                if (sshift == 4) {
                    sshift = 0;
                    sp--;
                } else {
                    sshift += 4;
                }
            }
            break;
        }
        default: {
            ts4l_u32 pixel_bytes = (row_info->pixel_depth >> 3);
            ts4l_u8 *sp = row + (row_info->width - 1) * pixel_bytes;
            ts4l_u8 *dp = row + (final_width - 1) * pixel_bytes;
            int jstop = lbl_8307AC64[pass];
            ts4l_u32 i;
            int j;
            ts4l_u8 v[8];

            for (i = 0; i < row_info->width; i++) {
                fn_833E3AD0(v, sp, pixel_bytes);
                for (j = 0; j < jstop; j++) {
                    fn_833E3AD0(dp, v, pixel_bytes);
                    dp -= pixel_bytes;
                }
                sp -= pixel_bytes;
            }
            break;
        }
        }
        row_info->width = final_width;
        row_info->rowbytes = ((final_width * (ts4l_u32)row_info->pixel_depth + 7) >> 3);
    }
}
