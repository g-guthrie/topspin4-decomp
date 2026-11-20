/* Loader_DLL.xex 0x83447530-0x834489D0, executable version 0.0.0.3.
 * libpng 1.2.x: png_get_tRNS, png_build_grayscale_palette. */
typedef unsigned char png_byte;
typedef unsigned short png_uint_16;
typedef unsigned long png_uint_32;
typedef png_byte *png_bytep;
typedef struct { png_byte red, green, blue; } png_color;
typedef png_color *png_colorp;
typedef struct { png_byte index, red, green, blue; png_uint_16 gray; } png_color_16;

typedef struct {
    png_uint_32 width;           /* 0x00 */
    png_uint_32 height;          /* 0x04 */
    png_uint_32 valid;           /* 0x08 */
    png_uint_32 rowbytes;        /* 0x0c */
    void *palette;               /* 0x10 */
    png_uint_16 num_palette;     /* 0x14 */
    png_uint_16 num_trans;       /* 0x16 */
    png_byte bit_depth;          /* 0x18 */
    png_byte color_type;         /* 0x19 */
    png_byte pad1a[0x16];
    png_bytep trans;             /* 0x30 */
    png_color_16 trans_values;   /* 0x34 */
} png_info;

#define PNG_INFO_tRNS 0x0010
#define PNG_COLOR_TYPE_PALETTE 3

png_uint_32 ts4l_png_get_tRNS_83447530(void *png_ptr, png_info *info_ptr, png_bytep *trans, int *num_trans, png_color_16 **trans_values)
{
    png_uint_32 retval = 0;
    if (png_ptr != 0 && info_ptr != 0 && (info_ptr->valid & PNG_INFO_tRNS)) {
        if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE) {
            if (trans != 0) {
                *trans = info_ptr->trans;
                retval |= PNG_INFO_tRNS;
            }
            if (trans_values != 0) *trans_values = &(info_ptr->trans_values);
        } else {
            if (trans_values != 0) {
                *trans_values = &(info_ptr->trans_values);
                retval |= PNG_INFO_tRNS;
            }
            if (trans != 0) *trans = 0;
        }
        if (num_trans != 0) {
            *num_trans = info_ptr->num_trans;
            retval |= PNG_INFO_tRNS;
        }
    }
    return retval;
}

void ts4l_png_build_grayscale_palette_83448940(int bit_depth, png_colorp palette)
{
    int num_palette;
    int color_inc;
    int i;
    int v;

    if (palette == 0) return;
    switch (bit_depth) {
        case 1:
            num_palette = 2;
            color_inc = 0xff;
            break;
        case 2:
            num_palette = 4;
            color_inc = 0x55;
            break;
        case 4:
            num_palette = 16;
            color_inc = 0x11;
            break;
        case 8:
            num_palette = 256;
            color_inc = 0x01;
            break;
        default:
            num_palette = 0;
            color_inc = 0;
            break;
    }
    for (i = 0, v = 0; i < num_palette; i++, v += color_inc) {
        palette[i].red = (png_byte)v;
        palette[i].green = (png_byte)v;
        palette[i].blue = (png_byte)v;
    }
}
