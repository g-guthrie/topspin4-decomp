/* Loader_DLL.xex 0x83452130-0x83452518, executable version 0.0.0.3. */
/* Library routine: zlib 1.1.x deflate (deflate.c), with putShortMSB inlined. */

#include "l8_zlib.h"

typedef struct ts4l_zconfig {
    ts4l_u16 good_length;
    ts4l_u16 max_lazy;
    ts4l_u16 nice_length;
    ts4l_u16 max_chain;
    int (*func)(ts4l_zstate *s, int flush);
} ts4l_zconfig;

extern ts4l_zconfig lbl_8307ABB0[];
extern char *lbl_8307BE9C[];

extern void fn_83452070(ts4l_zstream *strm);
extern void fn_834653D8(ts4l_zstate *s);
extern void fn_83465250(ts4l_zstate *s, char *buf, ts4l_u32 stored_len, int eof);
extern void *fn_833E3A30(void *dst, int value, unsigned int n);

#define TS4L_ERR_MSG(err) lbl_8307BE9C[2 - (err)]
#define TS4L_ERR_RETURN(strm, err) return (strm->msg = TS4L_ERR_MSG(err), (err))

#define TS4L_PUT_BYTE(s, c) { s->pending_buf[s->pending++] = (c); }

static void ts4l_putShortMSB(ts4l_zstate *s, ts4l_u32 b)
{
    TS4L_PUT_BYTE(s, (ts4l_u8)(b >> 8));
    TS4L_PUT_BYTE(s, (ts4l_u8)(b & 0xff));
}

int ts4l_zlib_deflate_83452130(ts4l_zstream *strm, int flush)
{
    int old_flush;
    ts4l_zstate *s;

    if (strm == 0 || strm->state == 0 || flush > 4 || flush < 0)
        return -2;
    s = strm->state;

    if (strm->next_out == 0 || (strm->next_in == 0 && strm->avail_in != 0) ||
        (s->status == 666 && flush != 4)) {
        TS4L_ERR_RETURN(strm, -2);
    }
    if (strm->avail_out == 0)
        TS4L_ERR_RETURN(strm, -5);

    s->strm = strm;
    old_flush = s->last_flush;
    s->last_flush = flush;

    if (s->status == 42) {
        ts4l_u32 header = (8 + ((s->w_bits - 8) << 4)) << 8;
        ts4l_u32 level_flags = (s->level - 1) >> 1;

        if (level_flags > 3)
            level_flags = 3;
        header |= (level_flags << 6);
        if (s->strstart != 0)
            header |= 0x20;
        header += 31 - (header % 31);

        s->status = 113;
        ts4l_putShortMSB(s, header);

        if (s->strstart != 0) {
            ts4l_putShortMSB(s, (ts4l_u32)(strm->adler >> 16));
            ts4l_putShortMSB(s, (ts4l_u32)(strm->adler & 0xffff));
        }
        strm->adler = 1L;
    }

    if (s->pending != 0) {
        fn_83452070(strm);
        if (strm->avail_out == 0) {
            s->last_flush = -1;
            return 0;
        }
    } else if (strm->avail_in == 0 && flush <= old_flush && flush != 4) {
        TS4L_ERR_RETURN(strm, -5);
    }

    if (s->status == 666 && strm->avail_in != 0)
        TS4L_ERR_RETURN(strm, -5);

    if (strm->avail_in != 0 || s->lookahead != 0 || (flush != 0 && s->status != 666)) {
        int bstate;

        bstate = (*(lbl_8307ABB0[s->level].func))(s, flush);

        if (bstate == 2 || bstate == 3)
            s->status = 666;
        if (bstate == 0 || bstate == 2) {
            if (strm->avail_out == 0)
                s->last_flush = -1;
            return 0;
        }
        if (bstate == 1) {
            if (flush == 1) {
                fn_834653D8(s);
            } else {
                fn_83465250(s, (char *)0, 0L, 0);
                if (flush == 3) {
                    s->head[s->hash_size - 1] = 0;
                    fn_833E3A30((ts4l_u8 *)s->head, 0, (ts4l_u32)(s->hash_size - 1) * sizeof(*s->head));
                }
            }
            fn_83452070(strm);
            if (strm->avail_out == 0) {
                s->last_flush = -1;
                return 0;
            }
        }
    }

    if (flush != 4)
        return 0;
    if (s->noheader)
        return 1;

    ts4l_putShortMSB(s, (ts4l_u32)(strm->adler >> 16));
    ts4l_putShortMSB(s, (ts4l_u32)(strm->adler & 0xffff));
    fn_83452070(strm);
    s->noheader = -1;
    return s->pending != 0 ? 0 : 1;
}
