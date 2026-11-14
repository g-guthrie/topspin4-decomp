/* Loader_DLL.xex 0x834553C8-0x8345568C, executable version 0.0.0.3. */
/* Library routine: libpng png_handle_IHDR. */

typedef unsigned char ts4l_u8;
typedef unsigned int ts4l_u32;

typedef struct ts4l_png_state {
    char pad0[0x558];
    ts4l_u32 mode;
    char pad1[0x5b8 - 0x55c];
    ts4l_u32 width;
    ts4l_u32 height;
    char pad2[0x5c8 - 0x5c0];
    ts4l_u32 rowbytes;
    char pad3[0x613 - 0x5cc];
    ts4l_u8 interlaced;
    char pad4[2];
    ts4l_u8 color_type;
    ts4l_u8 bit_depth;
    char pad5;
    ts4l_u8 pixel_depth;
    ts4l_u8 channels;
} ts4l_png_state;

typedef struct ts4l_png_info ts4l_png_info;

extern char lbl_8307AE2C[];
extern char lbl_8307AE18[];
extern char lbl_8307ADFC[];
extern char lbl_8307ADE0[];
extern char lbl_8307ADC4[];
extern char lbl_8307AD90[];
extern char lbl_8307AD6C[];
extern char lbl_8307AD48[];
extern char lbl_8307AD28[];

void fn_8343FD80(ts4l_png_state *png, const char *msg);
void fn_83449D78(ts4l_png_state *png, ts4l_u8 *buf, ts4l_u32 n);
void fn_83440030(ts4l_png_state *png, ts4l_u8 *buf, ts4l_u32 n);
void fn_834552D0(ts4l_png_state *png, int skip);
void fn_83446088(ts4l_png_state *png, ts4l_png_info *info, ts4l_u32 width, ts4l_u32 height,
                 int bit_depth, int color_type, int interlace_type, int compression_type,
                 int filter_type);

void ts4l_png_handle_ihdr_834553C8(ts4l_png_state *png, ts4l_png_info *info, ts4l_u32 length)
{
    ts4l_u8 buf[13];
    ts4l_u32 width, height;
    int bit_depth, color_type, compression_type, filter_type;
    int interlace_type;

    if (png->mode != 0)
        fn_8343FD80(png, lbl_8307AE2C);

    if (length != 13)
        fn_8343FD80(png, lbl_8307AE18);

    png->mode |= 1;

    fn_83449D78(png, buf, 13);
    fn_83440030(png, buf, 13);
    fn_834552D0(png, 0);

    width = ((ts4l_u32)buf[0] << 24) + ((ts4l_u32)buf[1] << 16) + ((ts4l_u32)buf[2] << 8) +
            (ts4l_u32)buf[3];
    height = ((ts4l_u32)buf[4] << 24) + ((ts4l_u32)buf[5] << 16) + ((ts4l_u32)buf[6] << 8) +
             (ts4l_u32)buf[7];
    bit_depth = buf[8];
    color_type = buf[9];
    compression_type = buf[10];
    filter_type = buf[11];
    interlace_type = buf[12];

    if (width == 0 || width > 0x7fffffffu || height == 0 || height > 0x7fffffffu)
        fn_8343FD80(png, lbl_8307ADFC);

    if (bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8 && bit_depth != 16)
        fn_8343FD80(png, lbl_8307ADE0);

    if (color_type < 0 || color_type == 1 || color_type == 5 || color_type > 6)
        fn_8343FD80(png, lbl_8307ADC4);

    if ((color_type == 3 && bit_depth > 8) ||
        ((color_type == 2 || color_type == 4 || color_type == 6) && bit_depth < 8))
        fn_8343FD80(png, lbl_8307AD90);

    if (interlace_type >= 2)
        fn_8343FD80(png, lbl_8307AD6C);

    if (compression_type != 0)
        fn_8343FD80(png, lbl_8307AD48);

    if (filter_type != 0)
        fn_8343FD80(png, lbl_8307AD28);

    png->width = width;
    png->height = height;
    png->bit_depth = (ts4l_u8)bit_depth;
    png->color_type = (ts4l_u8)color_type;
    png->interlaced = (ts4l_u8)interlace_type;
    switch (png->color_type) {
    case 0:
        png->channels = 1;
        break;
    case 2:
        png->channels = 3;
        break;
    case 3:
        png->channels = 1;
        break;
    case 4:
        png->channels = 2;
        break;
    case 6:
        png->channels = 4;
        break;
    }
    png->pixel_depth = (ts4l_u8)(png->channels * png->bit_depth);
    png->rowbytes = (png->pixel_depth * width + 7) >> 3;
    fn_83446088(png, info, width, height, bit_depth, color_type, interlace_type, compression_type,
                filter_type);
}
