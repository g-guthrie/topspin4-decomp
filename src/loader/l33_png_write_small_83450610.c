/* Loader_DLL.xex 0x83450610-0x8345070C, executable version 0.0.0.3. */
/* libpng: png_save_uint_32, png_save_uint_16, png_write_chunk_data. */
typedef unsigned long ts4l_u32;
typedef unsigned char ts4l_u8;
extern void fn_83440030(void *png, const void *buf, ts4l_u32 n);
extern void ts4_if_get_u32_off54c_83445FC0(void *png, const void *buf, ts4l_u32 n);

void ts4l_png_save_uint_32_83450610(ts4l_u8 *buf, ts4l_u32 i)
{
    buf[0] = (ts4l_u8)((i >> 24) & 0xff);
    buf[1] = (ts4l_u8)((i >> 16) & 0xff);
    buf[2] = (ts4l_u8)((i >> 8) & 0xff);
    buf[3] = (ts4l_u8)(i & 0xff);
}

void ts4l_png_save_uint_16_83450630(ts4l_u8 *buf, unsigned i)
{
    buf[0] = (ts4l_u8)((i >> 8) & 0xff);
    buf[1] = (ts4l_u8)(i & 0xff);
}

void ts4l_png_write_chunk_data_834506C8(void *png, const ts4l_u8 *data, ts4l_u32 length)
{
    if (data != 0 && length > 0) {
        fn_83440030(png, data, length);
        ts4_if_get_u32_off54c_83445FC0(png, data, length);
    }
}
