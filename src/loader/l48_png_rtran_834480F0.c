/* Loader_DLL.xex 0x834480F0-0x83448278, executable version 0.0.0.3.
 * libpng: png_read_transform_info. */
#include "l48_png.h"

void ts4l_png_read_transform_info_834480F0(l48_png_struct *png_ptr, l48_png_info *info_ptr)
{
    if (png_ptr->transformations & 0x1000) {
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
    if (png_ptr->transformations & 0x2000)
        info_ptr->gamma = png_ptr->gamma;
    if (png_ptr->transformations & 0x400) {
        if (info_ptr->bit_depth == 16)
            info_ptr->bit_depth = 8;
    }
    if (png_ptr->transformations & 0x40) {
        if ((info_ptr->color_type == 2 || info_ptr->color_type == 6) && png_ptr->palette_lookup &&
            info_ptr->bit_depth == 8)
            info_ptr->color_type = 3;
    }
    if (png_ptr->transformations & 0x4) {
        if (info_ptr->bit_depth < 8)
            info_ptr->bit_depth = 8;
    }
    if (info_ptr->color_type == 3)
        info_ptr->channels = 1;
    else if (info_ptr->color_type & 2)
        info_ptr->channels = 3;
    else
        info_ptr->channels = 1;
    if (info_ptr->color_type & 4)
        info_ptr->channels++;
    if (png_ptr->transformations & 0x8000) {
        if (info_ptr->color_type == 2 || info_ptr->color_type == 0)
            info_ptr->channels++;
    }
    info_ptr->pixel_depth = (unsigned char)(info_ptr->channels * info_ptr->bit_depth);
    info_ptr->rowbytes = ((info_ptr->width * (unsigned int)info_ptr->pixel_depth + 7) >> 3);
}

