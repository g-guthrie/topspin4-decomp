/* Loader_DLL.xex 0x83453A60-0x83453CD4, executable version 0.0.0.3. */
/* Library routine: zlib 1.1.x deflateInit2_ (deflate.c). */

#include "l8_zlib.h"

extern char *lbl_8307BE9C[];

extern void *fn_83465AB0(void *opaque, ts4l_u32 items, ts4l_u32 size);
extern void fn_83465B10(void *opaque, void *address);
extern int fn_83452518(ts4l_zstream *strm);
extern int fn_83453830(ts4l_zstream *strm);

#define TS4L_ZALLOC(strm, items, size) (*((strm)->zalloc))((strm)->opaque, (items), (size))

int ts4l_zlib_deflate_init2_83453A60(ts4l_zstream *strm, int level, int method, int windowBits,
                                     int memLevel, int strategy, const char *version,
                                     ts4l_u32 stream_size)
{
    ts4l_zstate *s;
    int noheader = 0;
    ts4l_u16 *overlay;

    if (version == 0 || version[0] != '1' || stream_size != 56)
        return -6;
    if (strm == 0)
        return -2;

    strm->msg = 0;
    if (strm->zalloc == 0) {
        strm->zalloc = fn_83465AB0;
        strm->opaque = (void *)0;
    }
    if (strm->zfree == 0)
        strm->zfree = fn_83465B10;

    if (level == -1)
        level = 6;

    if (windowBits < 0) {
        noheader = 1;
        windowBits = -windowBits;
    }
    if (memLevel < 1 || memLevel > 9 || method != 8 || windowBits < 9 || windowBits > 15 ||
        level < 0 || level > 9 || strategy < 0 || strategy > 2) {
        return -2;
    }
    s = (ts4l_zstate *)TS4L_ZALLOC(strm, 1, sizeof(ts4l_zstate));
    if (s == 0)
        return -4;
    s->status = 42;
    strm->state = s;
    s->strm = strm;

    s->noheader = noheader;
    s->w_bits = windowBits;
    s->w_size = 1 << s->w_bits;
    s->w_mask = s->w_size - 1;

    s->hash_bits = memLevel + 7;
    s->hash_size = 1 << s->hash_bits;
    s->hash_mask = s->hash_size - 1;
    s->hash_shift = ((s->hash_bits + 3 - 1) / 3);

    s->window = (ts4l_u8 *)TS4L_ZALLOC(strm, s->w_size, 2);
    s->prev = (ts4l_u16 *)TS4L_ZALLOC(strm, s->w_size, 2);
    s->head = (ts4l_u16 *)TS4L_ZALLOC(strm, s->hash_size, 2);

    s->lit_bufsize = 1 << (memLevel + 6);

    overlay = (ts4l_u16 *)TS4L_ZALLOC(strm, s->lit_bufsize, 4);
    s->pending_buf = (ts4l_u8 *)overlay;
    s->pending_buf_size = (ts4l_u32)s->lit_bufsize * 4L;

    if (s->window == 0 || s->prev == 0 || s->head == 0 || s->pending_buf == 0) {
        strm->msg = lbl_8307BE9C[2 - (-4)];
        fn_83452518(strm);
        return -4;
    }
    s->d_buf = overlay + s->lit_bufsize / 2;
    s->l_buf = s->pending_buf + (1 + 2) * s->lit_bufsize;

    s->level = level;
    s->strategy = strategy;
    s->method = (ts4l_u8)method;

    return fn_83453830(strm);
}
