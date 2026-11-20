/* Loader_DLL.xex 0x83450C88-0x83450FDC, executable version 0.0.0.3. */
/* libpng: png_write_IHDR. */
typedef unsigned long ts4l_u32;
typedef unsigned char ts4l_u8;
typedef struct Ts4lPng {
    char pad0[0x558];
    ts4l_u32 mode;
    ts4l_u32 flags;
    char pad1[0x564 - 0x560];
    char zs_head[0x584 - 0x564];
    void *zalloc;
    void *zfree;
    void *opaque;
    char pad2[0x59c - 0x590];
    ts4l_u32 zbuf;
    ts4l_u32 zbuf_size;
    int zlib_level;
    int zlib_method;
    int zlib_window_bits;
    int zlib_mem_level;
    int zlib_strategy;
    ts4l_u32 width;
    ts4l_u32 height;
    char pad3[4];
    ts4l_u32 usr_width;
    ts4l_u32 rowbytes;
    char pad4[0x613 - 0x5cc];
    ts4l_u8 interlaced;
    char pad5;
    ts4l_u8 do_filter;
    ts4l_u8 color_type;
    ts4l_u8 bit_depth;
    ts4l_u8 usr_bit_depth;
    ts4l_u8 pixel_depth;
    ts4l_u8 channels;
    ts4l_u8 usr_channels;
} Ts4lPng;
extern void fn_8343FD80(Ts4lPng *png, const char *msg);
extern void ts4_if_get_u32_off544_8343FDB8(Ts4lPng *png, const char *msg);
extern void ts4l_if_call_seq_fn_83450640_83450C28(Ts4lPng *png, const char *name, const ts4l_u8 *data, ts4l_u32 len);
extern void fn_8343FF78(void);
extern void ts4_tailcall_fn_8344C6B0_8343FFE8(void);
extern int ts4l_zlib_deflate_init2_83453A60(void *strm, int level, int method, int window_bits, int mem_level, int strategy, const char *version, int size);
extern char lbl_8307AB8C[], lbl_8307AB68[], lbl_8307AB3C[], lbl_8307AB14[], lbl_8307AAF4[], lbl_8307AACC[];
extern char lbl_8307AAA8[], lbl_8307AA88[], lbl_8307AA64[], lbl_8307AA20[], lbl_83005EE0[];

void ts4l_png_write_ihdr_83450C88(Ts4lPng *png, ts4l_u32 width, ts4l_u32 height, int bit_depth,
                                  int color_type, int compression_type, int filter_type, int interlace_type)
{
    ts4l_u8 buf[13];

    switch (color_type) {
    case 0:
        switch (bit_depth) {
        case 1: case 2: case 4: case 8: case 16:
            png->channels = 1;
            break;
        default:
            fn_8343FD80(png, lbl_8307AACC);
        }
        break;
    case 2:
        if (bit_depth != 8 && bit_depth != 16)
            fn_8343FD80(png, lbl_8307AAF4);
        png->channels = 3;
        break;
    case 3:
        switch (bit_depth) {
        case 1: case 2: case 4: case 8:
            png->channels = 1;
            break;
        default:
            fn_8343FD80(png, lbl_8307AB14);
        }
        break;
    case 4:
        if (bit_depth != 8 && bit_depth != 16)
            fn_8343FD80(png, lbl_8307AB3C);
        png->channels = 2;
        break;
    case 6:
        if (bit_depth != 8 && bit_depth != 16)
            fn_8343FD80(png, lbl_8307AB68);
        png->channels = 4;
        break;
    default:
        fn_8343FD80(png, lbl_8307AB8C);
    }
    if (compression_type != 0) {
        ts4_if_get_u32_off544_8343FDB8(png, lbl_8307AAA8);
        compression_type = 0;
    }
    if (filter_type != 0) {
        ts4_if_get_u32_off544_8343FDB8(png, lbl_8307AA88);
        filter_type = 0;
    }
    if (interlace_type != 0 && interlace_type != 1) {
        ts4_if_get_u32_off544_8343FDB8(png, lbl_8307AA64);
        interlace_type = 1;
    }
    png->bit_depth = (ts4l_u8)bit_depth;
    png->color_type = (ts4l_u8)color_type;
    png->interlaced = (ts4l_u8)interlace_type;
    png->width = width;
    png->height = height;
    png->pixel_depth = (ts4l_u8)(bit_depth * png->channels);
    png->rowbytes = (((ts4l_u32)png->pixel_depth + 7) * width) >> 3;
    png->usr_width = png->width;
    png->usr_bit_depth = png->bit_depth;
    png->usr_channels = png->channels;
    buf[0] = (ts4l_u8)(width >> 24);
    buf[1] = (ts4l_u8)(width >> 16);
    buf[2] = (ts4l_u8)(width >> 8);
    buf[3] = (ts4l_u8)width;
    buf[4] = (ts4l_u8)(height >> 24);
    buf[5] = (ts4l_u8)(height >> 16);
    buf[6] = (ts4l_u8)(height >> 8);
    buf[7] = (ts4l_u8)height;
    buf[8] = (ts4l_u8)bit_depth;
    buf[9] = (ts4l_u8)color_type;
    buf[10] = (ts4l_u8)compression_type;
    buf[11] = (ts4l_u8)filter_type;
    buf[12] = (ts4l_u8)interlace_type;
    ts4l_if_call_seq_fn_83450640_83450C28(png, lbl_8307AA20, buf, 13);
    png->zalloc = (void *)fn_8343FF78;
    png->zfree = (void *)ts4_tailcall_fn_8344C6B0_8343FFE8;
    png->opaque = png;
    if (!png->do_filter) {
        if (png->color_type == 3 || png->bit_depth < 8)
            png->do_filter = 8;
        else
            png->do_filter = 0xf8;
    }
    if (!(png->flags & 1)) {
        if (png->do_filter != 8)
            png->zlib_strategy = 1;
        else
            png->zlib_strategy = 0;
    }
    if (!(png->flags & 2))
        png->zlib_level = -1;
    if (!(png->flags & 4))
        png->zlib_mem_level = 8;
    if (!(png->flags & 8))
        png->zlib_window_bits = 15;
    if (!(png->flags & 0x10))
        png->zlib_method = 8;
    ts4l_zlib_deflate_init2_83453A60(png->zs_head + 0, png->zlib_level, png->zlib_method, png->zlib_window_bits,
                png->zlib_mem_level, png->zlib_strategy, lbl_83005EE0, 0x38);
    *(ts4l_u32 *)(png->zs_head + 0xc) = png->zbuf;
    *(ts4l_u32 *)(png->zs_head + 0x10) = png->zbuf_size;
    png->mode = 1;
}
