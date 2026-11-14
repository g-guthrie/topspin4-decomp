/* Loader_DLL.xex 0x83450640-0x834506C4, executable version 0.0.0.3. */
/* libpng: png_write_chunk_start. */
typedef unsigned long ts4l_u32;
typedef unsigned char ts4l_u8;
extern void ts4_if_get_u32_off54c_83445FC0(void *png, const void *buf, ts4l_u32 n);
extern void ts4_call_seq_fn_8344C708_8343FFF0(void *png);
extern void fn_83440030(void *png, const void *buf, ts4l_u32 n);

void ts4l_png_write_chunk_start_83450640(void *png, const ts4l_u8 *name, ts4l_u32 length)
{
    ts4l_u8 buf[4];
    buf[0] = (ts4l_u8)(length >> 24);
    buf[1] = (ts4l_u8)(length >> 16);
    buf[2] = (ts4l_u8)(length >> 8);
    buf[3] = (ts4l_u8)length;
    ts4_if_get_u32_off54c_83445FC0(png, buf, 4);
    ts4_if_get_u32_off54c_83445FC0(png, name, 4);
    ts4_call_seq_fn_8344C708_8343FFF0(png);
    fn_83440030(png, name, 4);
}
