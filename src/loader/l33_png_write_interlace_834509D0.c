/* Loader_DLL.xex 0x834509D0-0x83450C24, executable version 0.0.0.3. */
/* libpng: png_do_write_interlace. */
typedef unsigned long ts4l_u32;
typedef unsigned char ts4l_u8;
typedef struct Ts4lRowInfo {
    ts4l_u32 width;
    ts4l_u32 rowbytes;
    ts4l_u8 color_type;
    ts4l_u8 bit_depth;
    ts4l_u8 channels;
    ts4l_u8 pixel_depth;
} Ts4lRowInfo;
extern ts4l_u32 lbl_8307A9A8[];
extern void fn_833E3AD0(void *dst, const void *src, ts4l_u32 n);

#define PASS_START lbl_8307A9A8
#define PASS_INC (lbl_8307A9A8 + 7)

void ts4l_png_do_write_interlace_834509D0(Ts4lRowInfo *row_info, ts4l_u8 *row, int pass)
{
    if (pass < 6) {
        switch (row_info->pixel_depth) {
        case 1: {
            ts4l_u8 *sp;
            ts4l_u8 *dp;
            int shift;
            int d;
            int value;
            ts4l_u32 i;
            ts4l_u32 row_width = row_info->width;
            dp = row;
            d = 0;
            shift = 7;
            for (i = PASS_START[pass]; i < row_width; i += PASS_INC[pass]) {
                sp = row + (i >> 3);
                value = (int)(*sp >> (ts4l_u8)(7 - (int)(i & 0x07))) & 0x01;
                d |= (value << shift);
                if (shift == 0) {
                    shift = 7;
                    *dp++ = (ts4l_u8)d;
                    d = 0;
                } else {
                    shift--;
                }
            }
            if (shift != 7)
                *dp = (ts4l_u8)d;
            break;
        }
        case 2: {
            ts4l_u8 *sp;
            ts4l_u8 *dp;
            int shift;
            int d;
            int value;
            ts4l_u32 i;
            ts4l_u32 row_width = row_info->width;
            dp = row;
            shift = 6;
            d = 0;
            for (i = PASS_START[pass]; i < row_width; i += PASS_INC[pass]) {
                sp = row + (i >> 2);
                value = (*sp >> (ts4l_u8)((3 - (int)(i & 0x03)) << 1)) & 0x03;
                d |= (value << shift);
                if (shift == 0) {
                    shift = 6;
                    *dp++ = (ts4l_u8)d;
                    d = 0;
                } else {
                    shift -= 2;
                }
            }
            if (shift != 6)
                *dp = (ts4l_u8)d;
            break;
        }
        case 4: {
            ts4l_u8 *sp;
            ts4l_u8 *dp;
            int shift;
            int d;
            int value;
            ts4l_u32 i;
            ts4l_u32 row_width = row_info->width;
            dp = row;
            shift = 4;
            d = 0;
            for (i = PASS_START[pass]; i < row_width; i += PASS_INC[pass]) {
                sp = row + (i >> 1);
                value = (*sp >> (ts4l_u8)(4 - (int)(i & 0x01) * 4)) & 0x0f;
                d |= (value << shift);
                if (shift == 0) {
                    shift = 4;
                    *dp++ = (ts4l_u8)d;
                    d = 0;
                } else {
                    shift -= 4;
                }
            }
            if (shift != 4)
                *dp = (ts4l_u8)d;
            break;
        }
        default: {
            ts4l_u8 *sp;
            ts4l_u8 *dp;
            ts4l_u32 i;
            ts4l_u32 row_width = row_info->width;
            ts4l_u32 pixel_bytes;
            dp = row;
            pixel_bytes = (row_info->pixel_depth >> 3);
            for (i = PASS_START[pass]; i < row_width; i += PASS_INC[pass]) {
                sp = row + i * pixel_bytes;
                if (dp != sp)
                    fn_833E3AD0(dp, sp, pixel_bytes);
                dp += pixel_bytes;
            }
            break;
        }
        }
        row_info->width = (row_info->width + PASS_INC[pass] - 1 - PASS_START[pass]) / PASS_INC[pass];
        row_info->rowbytes = ((row_info->width * row_info->pixel_depth + 7) >> 3);
    }
}
