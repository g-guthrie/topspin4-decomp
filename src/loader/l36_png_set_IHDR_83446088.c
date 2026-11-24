/* Loader_DLL.xex 0x83446088-0x834461A8, executable version 0.0.0.3.
 * libpng 1.0.x/1.2.x pngset.c: png_set_IHDR. */
typedef unsigned char png_byte;
typedef unsigned long png_uint_32;
typedef struct {
    png_uint_32 width;           /* 0x00 */
    png_uint_32 height;          /* 0x04 */
    png_uint_32 valid;           /* 0x08 */
    png_uint_32 rowbytes;        /* 0x0c */
    void *palette;               /* 0x10 */
    unsigned short num_palette;  /* 0x14 */
    unsigned short num_trans;    /* 0x16 */
    png_byte bit_depth;          /* 0x18 */
    png_byte color_type;         /* 0x19 */
    png_byte compression_type;   /* 0x1a */
    png_byte filter_type;        /* 0x1b */
    png_byte interlace_type;     /* 0x1c */
    png_byte channels;           /* 0x1d */
    png_byte pixel_depth;        /* 0x1e */
} png_info;

extern const char lbl_8307593C[];
extern const char lbl_830758FC[];
extern void fn_8343FD80(void *png_ptr, const char *msg);
extern void ts4_if_get_u32_off544_8343FDB8(void *png_ptr, const char *msg);

#define PNG_COLOR_MASK_COLOR 2
#define PNG_COLOR_MASK_ALPHA 4
#define PNG_COLOR_TYPE_PALETTE 3

void ts4l_png_set_IHDR_83446088(void *png_ptr, png_info *info_ptr, png_uint_32 width, png_uint_32 height,
                                int bit_depth, int color_type, int interlace_type, int compression_type,
                                int filter_type)
{
    if (png_ptr == 0 || info_ptr == 0) return;
    if (width > 1000000L || height > 1000000L) {
        fn_8343FD80(png_ptr, lbl_8307593C);
    }
    info_ptr->width = width;
    info_ptr->height = height;
    info_ptr->bit_depth = (png_byte)bit_depth;
    info_ptr->color_type = (png_byte)color_type;
    info_ptr->compression_type = (png_byte)compression_type;
    info_ptr->filter_type = (png_byte)filter_type;
    info_ptr->interlace_type = (png_byte)interlace_type;
    if (info_ptr->color_type == PNG_COLOR_TYPE_PALETTE)
        info_ptr->channels = 1;
    else if (info_ptr->color_type & PNG_COLOR_MASK_COLOR)
        info_ptr->channels = 3;
    else
        info_ptr->channels = 1;
    if (info_ptr->color_type & PNG_COLOR_MASK_ALPHA)
        info_ptr->channels++;
    info_ptr->pixel_depth = (png_byte)(info_ptr->channels * info_ptr->bit_depth);
    if (width > ((png_uint_32)0x7fffffffL / (png_uint_32)((info_ptr->pixel_depth + 7) >> 3))) {
        ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_830758FC);
        info_ptr->rowbytes = 0;
    } else {
        info_ptr->rowbytes = ((width * info_ptr->pixel_depth + 7) >> 3);
    }
}
