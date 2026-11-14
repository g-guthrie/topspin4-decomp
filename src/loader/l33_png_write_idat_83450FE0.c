/* Loader_DLL.xex 0x83450FE0-0x83451370, executable version 0.0.0.3. */
/* libpng: png_write_IDAT, png_write_filtered_row. */
typedef unsigned long ts4l_u32;
typedef unsigned char ts4l_u8;
typedef struct Ts4lPng {
    char pad0[0x558];
    ts4l_u32 mode;
    char pad1[0x560 - 0x55c];
    ts4l_u32 transformations;
    ts4l_u8 *zs_next_in;
    ts4l_u32 zs_avail_in;
    char pad3[0x570 - 0x56c];
    ts4l_u8 *zs_next_out;
    ts4l_u32 zs_avail_out;
    char pad4[0x57c - 0x578];
    const char *zs_msg;
    char pad5[0x59c - 0x580];
    ts4l_u8 *zbuf;
    ts4l_u32 zbuf_size;
    char pad6[0x5b8 - 0x5a4];
    ts4l_u32 width;
    ts4l_u32 height;
    ts4l_u32 num_rows;
    ts4l_u32 usr_width;
    char pad7[0x5d4 - 0x5c8];
    ts4l_u32 row_number;
    ts4l_u8 *prev_row;
    ts4l_u8 *row_buf;
    char pad8[0x5f4 - 0x5e0];
    ts4l_u32 info_rowbytes;
    char pad9[0x613 - 0x5f8];
    ts4l_u8 interlaced;
    ts4l_u8 pass;
    char pad10[0x618 - 0x615];
    ts4l_u8 usr_bit_depth;
    char pad11[0x61b - 0x619];
    ts4l_u8 usr_channels;
    char pad12[0x624 - 0x61c];
    ts4l_u32 flush_dist;
    ts4l_u32 flush_rows;
} Ts4lPng;
extern void ts4l_if_call_seq_fn_83450640_83450C28(Ts4lPng *png, const char *name, const ts4l_u8 *data, ts4l_u32 len);
extern void fn_8343FD80(Ts4lPng *png, const char *msg);
extern void fn_833E3A30(void *p, int c, ts4l_u32 n);
extern int ts4l_zlib_deflate_83452130(void *strm, int flush);
extern int fn_83453830(void *strm);
extern void fn_83445578(Ts4lPng *png);
extern ts4l_u32 lbl_8307A9A8[];
extern char lbl_8307AA28[], lbl_830756C0[];
extern void fn_83451080(Ts4lPng *png);
#define PASS_START lbl_8307A9A8
#define PASS_INC (lbl_8307A9A8 + 7)
#define PASS_YSTART (lbl_8307A9A8 + 14)
#define PASS_YINC (lbl_8307A9A8 + 21)

void ts4l_png_write_idat_83450FE0(Ts4lPng *png, const ts4l_u8 *data, ts4l_u32 length)
{
    ts4l_if_call_seq_fn_83450640_83450C28(png, lbl_8307AA28, data, length);
    png->mode |= 4;
}

void ts4l_png_write_filtered_row_83451290(Ts4lPng *png, ts4l_u8 *filtered_row)
{
    int ret;

    png->zs_next_in = filtered_row;
    png->zs_avail_in = png->info_rowbytes + 1;
    do {
        ret = ts4l_zlib_deflate_83452130((void *)&png->zs_next_in, 0);
        if (ret != 0) {
            if (png->zs_msg != 0)
                fn_8343FD80(png, png->zs_msg);
            else
                fn_8343FD80(png, lbl_830756C0);
        }
        if (!png->zs_avail_out) {
            ts4l_png_write_idat_83450FE0(png, png->zbuf, png->zbuf_size);
            png->zs_next_out = png->zbuf;
            png->zs_avail_out = png->zbuf_size;
        }
    } while (png->zs_avail_in);
    if (png->prev_row != 0) {
        ts4l_u8 *tptr = png->prev_row;
        png->prev_row = png->row_buf;
        png->row_buf = tptr;
    }
    fn_83451080(png);
    png->flush_rows++;
    if (png->flush_dist > 0 && png->flush_rows >= png->flush_dist)
        fn_83445578(png);
}
