/* Loader_DLL.xex 0x83448678-0x8344893C, executable version 0.0.0.3. */
/* Library routine: libpng pngrtran.c png_do_read_filler (compiled /O1). */

typedef struct ts4l_png_row_info {
    unsigned int width;
    unsigned int rowbytes;
    unsigned char color_type;
    unsigned char bit_depth;
    unsigned char channels;
    unsigned char pixel_depth;
} ts4l_png_row_info;

#define TS4L_PNG_FLAG_FILLER_AFTER 0x0080u

/* Insert a filler sample into every pixel of a gray or RGB row, working backwards in place
 * (libpng png_do_read_filler). Loader_DLL.xex 0x83448678 */
void ts4l_png_do_read_filler_83448678(ts4l_png_row_info *row_info, unsigned char *row, unsigned int filler,
                                     unsigned int flags)
{
    unsigned int i;
    unsigned int row_width = row_info->width;
    unsigned char hi_filler = (unsigned char)((filler >> 8) & 0xff);
    unsigned char lo_filler = (unsigned char)(filler & 0xff);

    if (row_info->color_type == 0) {
        if (row_info->bit_depth == 8) {
            if (flags & TS4L_PNG_FLAG_FILLER_AFTER) {
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
            if (flags & TS4L_PNG_FLAG_FILLER_AFTER) {
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
            if (flags & TS4L_PNG_FLAG_FILLER_AFTER) {
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
            if (flags & TS4L_PNG_FLAG_FILLER_AFTER) {
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
