/* Loader_DLL.xex 0x83445740-0x83445E10, executable version 0.0.0.3.
 * libpng: png_set_filter, png_set_filter_heuristics, png_create_write_struct. */
#include "l48_png.h"

extern int _setjmp(void *);
#ifdef _MSC_VER
#pragma intrinsic(_setjmp)
#endif
extern void ts4_if_get_u32_off544_8343FDB8(void *png, const char *msg);
extern void fn_8343FD80(void *png, const char *msg);
extern void *ts4l_if_call_seq_fn_8340D710_8344C640(void *png, unsigned int size);
extern l48_png_struct *fn_8344C5B0(int type);
extern void ts4l_free_tag_pair_8344C6B0(void *png, void *ptr);
extern void fn_8344C628(void *ptr);
extern void ts4_set_u32_off548_8343FD68(void *png, void *error_ptr, void *error_fn, void *warn_fn);
extern void ts4l_if_call_seq_u32_off550_83445FF8(void *png, void *io_ptr, void *write_fn, void *flush_fn);
extern void fn_83445960(l48_png_struct *png, int method, int num_weights, double *weights, double *costs);
extern char lbl_83075760[], lbl_8307573C[], lbl_83075714[], lbl_830756EC[], lbl_830756CC[];
extern char lbl_83075780[], lbl_83075838[];
extern char lbl_83075A0C[], lbl_830759F8[], lbl_830759E4[], lbl_83005EE0[];
extern void ts4l_alloc_zero_8343FF78(void);
extern void ts4_tailcall_fn_8344C6B0_8343FFE8(void);
extern int ts4_tailcall_fn_83453DF8_83453F50(void *strm, const char *version, int size);
extern void ts4l_if_call_seq_u32_off54c_83449D98(void *png, void *io_ptr, void *read_fn);

void ts4l_png_set_filter_83445740(l48_png_struct *png_ptr, int method, int filters)
{
    if (method == 0) {
        switch (filters & 0xff) {
        case 5:
        case 6:
        case 7:
            ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_83075760);
        case 0:
            png_ptr->do_filter = 0x08;
            break;
        case 1:
            png_ptr->do_filter = 0x10;
            break;
        case 2:
            png_ptr->do_filter = 0x20;
            break;
        case 3:
            png_ptr->do_filter = 0x40;
            break;
        case 4:
            png_ptr->do_filter = 0x80;
            break;
        default:
            png_ptr->do_filter = (unsigned char)filters;
            break;
        }
        if (png_ptr->row_buf != 0) {
            if ((png_ptr->do_filter & 0x10) && png_ptr->sub_row == 0) {
                png_ptr->sub_row = ts4l_if_call_seq_fn_8340D710_8344C640(png_ptr, png_ptr->rowbytes + 1);
                png_ptr->sub_row[0] = 1;
            }
            if ((png_ptr->do_filter & 0x20) && png_ptr->up_row == 0) {
                if (png_ptr->prev_row == 0) {
                    ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_8307573C);
                    png_ptr->do_filter &= ~0x20;
                } else {
                    png_ptr->up_row = ts4l_if_call_seq_fn_8340D710_8344C640(png_ptr, png_ptr->rowbytes + 1);
                    png_ptr->up_row[0] = 2;
                }
            }
            if ((png_ptr->do_filter & 0x40) && png_ptr->avg_row == 0) {
                if (png_ptr->prev_row == 0) {
                    ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_83075714);
                    png_ptr->do_filter &= ~0x40;
                } else {
                    png_ptr->avg_row = ts4l_if_call_seq_fn_8340D710_8344C640(png_ptr, png_ptr->rowbytes + 1);
                    png_ptr->avg_row[0] = 3;
                }
            }
            if ((png_ptr->do_filter & 0x80) && png_ptr->paeth_row == 0) {
                if (png_ptr->prev_row == 0) {
                    ts4_if_get_u32_off544_8343FDB8(png_ptr, lbl_830756EC);
                    png_ptr->do_filter &= 0x7f;
                } else {
                    png_ptr->paeth_row = ts4l_if_call_seq_fn_8340D710_8344C640(png_ptr, png_ptr->rowbytes + 1);
                    png_ptr->paeth_row[0] = 4;
                }
            }
            if (png_ptr->do_filter == 0)
                png_ptr->do_filter = 0x08;
        }
    } else {
        fn_8343FD80(png_ptr, lbl_830756CC);
    }
}

l48_png_struct *ts4l_png_create_write_struct_83445D18(const char *user_png_ver, void *error_ptr, void *error_fn, void *warn_fn)
{
    l48_png_struct *png_ptr;

    png_ptr = fn_8344C5B0(1);
    if (png_ptr == 0)
        return 0;
    if (_setjmp(png_ptr)) {
        ts4l_free_tag_pair_8344C6B0(png_ptr, png_ptr->zbuf);
        fn_8344C628(png_ptr);
        return 0;
    }
    ts4_set_u32_off548_8343FD68(png_ptr, error_ptr, error_fn, warn_fn);
    if (user_png_ver == 0 || user_png_ver[0] != '1')
        fn_8343FD80(png_ptr, lbl_83075838);
    png_ptr->zbuf_size = 8192;
    png_ptr->zbuf = ts4l_if_call_seq_fn_8340D710_8344C640(png_ptr, 8192);
    ts4l_if_call_seq_u32_off550_83445FF8(png_ptr, 0, 0, 0);
    fn_83445960(png_ptr, 0, 1, 0, 0);
    return png_ptr;
}

l48_png_struct *ts4l_png_create_read_struct_834462A0(const char *user_png_ver, void *error_ptr, void *error_fn, void *warn_fn)
{
    l48_png_struct *png_ptr;
    int ret;

    png_ptr = fn_8344C5B0(1);
    if (png_ptr == 0)
        return 0;
    if (_setjmp(png_ptr)) {
        ts4l_free_tag_pair_8344C6B0(png_ptr, png_ptr->zbuf);
        fn_8344C628(png_ptr);
        return 0;
    }
    ts4_set_u32_off548_8343FD68(png_ptr, error_ptr, error_fn, warn_fn);
    if (user_png_ver == 0 || user_png_ver[0] != '1')
        fn_8343FD80(png_ptr, lbl_83075838);
    png_ptr->zbuf_size = 8192;
    png_ptr->zbuf = ts4l_if_call_seq_fn_8340D710_8344C640(png_ptr, 8192);
    png_ptr->zstream.zalloc = (void *)ts4l_alloc_zero_8343FF78;
    png_ptr->zstream.zfree = (void *)ts4_tailcall_fn_8344C6B0_8343FFE8;
    png_ptr->zstream.opaque = png_ptr;
    ret = ts4_tailcall_fn_83453DF8_83453F50(&png_ptr->zstream, lbl_83005EE0, 56);
    if (ret != -6) {
        if (ret != -4 && ret != -2) {
            if (ret != 0)
                fn_8343FD80(png_ptr, lbl_83075A0C);
        } else {
            fn_8343FD80(png_ptr, lbl_830759F8);
        }
    } else {
        fn_8343FD80(png_ptr, lbl_830759E4);
    }
    png_ptr->zstream.next_out = png_ptr->zbuf;
    png_ptr->zstream.avail_out = png_ptr->zbuf_size;
    ts4l_if_call_seq_u32_off54c_83449D98(png_ptr, 0, 0);
    return png_ptr;
}
