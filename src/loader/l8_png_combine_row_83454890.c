/* Loader_DLL.xex 0x83454890-0x83454AEC, executable version 0.0.0.3. */
/* Library routine: libpng png_combine_row (no PACKSWAP). */

typedef unsigned char ts4l_u8;
typedef unsigned int ts4l_u32;

typedef struct ts4l_png_state {
    char pad0[0x5b8];
    ts4l_u32 width;
    char pad1[0x20];
    ts4l_u8 *row_buf;
    char pad2[0x1b];
    ts4l_u8 pixel_depth;
} ts4l_png_state;

void *fn_833E3AD0(void *dst, const void *src, ts4l_u32 n);

void ts4l_png_combine_row_83454890(ts4l_png_state *png, ts4l_u8 *row, int mask)
{
    if (mask == 0xff) {
        fn_833E3AD0(row, png->row_buf + 1, (png->pixel_depth * png->width + 7) >> 3);
    } else {
        switch (png->pixel_depth) {
        case 1: {
            ts4l_u8 *sp = png->row_buf + 1;
            ts4l_u8 *dp = row;
            int m = 0x80;
            int shift = 7;
            ts4l_u32 i;
            ts4l_u32 row_width = png->width;
            for (i = 0; i < row_width; i++) {
                if (m & mask) {
                    int value = (*sp >> shift) & 0x1;
                    *dp &= (ts4l_u8)((0x7f7f >> (7 - shift)) & 0xff);
                    *dp |= (ts4l_u8)(value << shift);
                }
                if (shift == 0) {
                    shift = 7;
                    sp++;
                    dp++;
                } else {
                    shift -= 1;
                }
                if (m == 1) m = 0x80; else m >>= 1;
            }
            break;
        }
        case 2: {
            ts4l_u8 *sp = png->row_buf + 1;
            ts4l_u8 *dp = row;
            int m = 0x80;
            int shift = 6;
            ts4l_u32 i;
            ts4l_u32 row_width = png->width;
            for (i = 0; i < row_width; i++) {
                if (m & mask) {
                    int value = (*sp >> shift) & 0x3;
                    *dp &= (ts4l_u8)((0x3f3f >> (6 - shift)) & 0xff);
                    *dp |= (ts4l_u8)(value << shift);
                }
                if (shift == 0) {
                    shift = 6;
                    sp++;
                    dp++;
                } else {
                    shift -= 2;
                }
                if (m == 1) m = 0x80; else m >>= 1;
            }
            break;
        }
        case 4: {
            ts4l_u8 *sp = png->row_buf + 1;
            ts4l_u8 *dp = row;
            int m = 0x80;
            int shift = 4;
            ts4l_u32 i;
            ts4l_u32 row_width = png->width;
            for (i = 0; i < row_width; i++) {
                if (m & mask) {
                    int value = (*sp >> shift) & 0xf;
                    *dp &= (ts4l_u8)((0xf0f >> (4 - shift)) & 0xff);
                    *dp |= (ts4l_u8)(value << shift);
                }
                if (shift == 0) {
                    shift = 4;
                    sp++;
                    dp++;
                } else {
                    shift -= 4;
                }
                if (m == 1) m = 0x80; else m >>= 1;
            }
            break;
        }
        default: {
            ts4l_u8 *sp = png->row_buf + 1;
            ts4l_u8 *dp = row;
            ts4l_u32 pixel_bytes = png->pixel_depth >> 3;
            ts4l_u32 i;
            ts4l_u32 row_width = png->width;
            ts4l_u8 m = 0x80;
            for (i = 0; i < row_width; i++) {
                if (m & mask)
                    fn_833E3AD0(dp, sp, pixel_bytes);
                sp += pixel_bytes;
                dp += pixel_bytes;
                if (m == 1) m = 0x80; else m >>= 1;
            }
            break;
        }
        }
    }
}
