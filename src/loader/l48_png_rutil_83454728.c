/* Loader_DLL.xex 0x83454728-0x834553C8, executable version 0.0.0.3.
 * libpng: png_crc_error, png_check_chunk_name, png_get_uint_31, png_crc_finish. */
#include "l48_png.h"

extern void ts4_if_get_u32_off550_83449D78(void *png, void *buf, unsigned int n);
extern void fn_8343FD80(void *png, const char *msg);
extern void fn_8343FDD0(void *png, const char *msg);
extern void ts4l_if_get_fn_8343FC58_8343FE18(void *png, const char *msg);
extern void fn_83440030(void *png, const void *buf, unsigned int n);
extern char lbl_8307ACC0[], lbl_8307ACF8[], lbl_8307AD1C[];

int ts4l_png_crc_error_83454728(l48_png_struct *png_ptr)
{
    unsigned char crc_bytes[4];
    unsigned int crc;
    int need_crc = 1;

    if (png_ptr->chunk_name[0] & 0x20) {
        if ((png_ptr->flags & 0x300) == 0x300)
            need_crc = 0;
    } else {
        if (png_ptr->flags & 0x800)
            need_crc = 0;
    }
    ts4_if_get_u32_off550_83449D78(png_ptr, crc_bytes, 4);
    if (need_crc) {
        crc = ((unsigned int)crc_bytes[0] << 24) + ((unsigned int)crc_bytes[1] << 16) +
              ((unsigned int)crc_bytes[2] << 8) + (unsigned int)crc_bytes[3];
        return (int)(crc != png_ptr->crc);
    }
    return 0;
}

void ts4l_png_check_chunk_name_834547F0(l48_png_struct *png_ptr, unsigned char *chunk_name)
{
#define L48_NONALPHA(c) ((c) < 41 || (c) > 122 || ((c) > 90 && (c) < 97))
    if (L48_NONALPHA(chunk_name[0]) || L48_NONALPHA(chunk_name[1]) || L48_NONALPHA(chunk_name[2]) ||
        L48_NONALPHA(chunk_name[3]))
        fn_8343FDD0(png_ptr, lbl_8307ACC0);
#undef L48_NONALPHA
}

unsigned int ts4l_png_get_uint_31_83455260(void *png_ptr, unsigned char *buf)
{
    unsigned int i = ((unsigned int)buf[0] << 24) + ((unsigned int)buf[1] << 16) +
                     ((unsigned int)buf[2] << 8) + (unsigned int)buf[3];
    if (i > 0x7fffffffu)
        fn_8343FD80(png_ptr, lbl_8307ACF8);
    return i;
}

#ifndef _MSC_VER
#define __forceinline inline
#endif
static __forceinline void l48_crc_read(l48_png_struct *png_ptr, unsigned char *buf, unsigned int length)
{
    ts4_if_get_u32_off550_83449D78(png_ptr, buf, length);
    fn_83440030(png_ptr, buf, length);
}

int ts4l_png_crc_finish_834552D0(l48_png_struct *png_ptr, unsigned int skip)
{
    unsigned int i;
    unsigned int istop = png_ptr->zbuf_size;

    for (i = skip; i > istop; i -= istop) {
        l48_crc_read(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size);
    }
    if (i) {
        l48_crc_read(png_ptr, png_ptr->zbuf, i);
    }
    if (ts4l_png_crc_error_83454728(png_ptr)) {
        if (((png_ptr->chunk_name[0] & 0x20) && !(png_ptr->flags & 0x200)) ||
            (!(png_ptr->chunk_name[0] & 0x20) && (png_ptr->flags & 0x400)))
            ts4l_if_get_fn_8343FC58_8343FE18(png_ptr, lbl_8307AD1C);
        else
            fn_8343FDD0(png_ptr, lbl_8307AD1C);
        return 1;
    }
    return 0;
}
