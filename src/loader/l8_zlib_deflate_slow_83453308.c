/* Loader_DLL.xex 0x83453308-0x83453830, executable version 0.0.0.3. */
/* Library routine: zlib 1.1.x deflate_slow (lazy matching), with the
   INSERT_STRING, _tr_tally and FLUSH_BLOCK macros expanded. */

#include "l8_zlib.h"

extern ts4l_u8 lbl_8307BA70[];
extern ts4l_u8 lbl_8307BC70[];

extern void fn_83452B18(ts4l_zstate *s);
extern ts4l_u32 fn_83452960(ts4l_zstate *s, ts4l_u32 cur_match);
extern void fn_83465708(ts4l_zstate *s, char *buf, ts4l_u32 stored_len, int eof);
extern void fn_83452070(ts4l_zstream *strm);

#define TS4L_UPDATE_HASH(s, h, c) (h = (((h) << s->hash_shift) ^ (c)) & s->hash_mask)

#define TS4L_INSERT_STRING(s, str, match_head)                                                 \
    (TS4L_UPDATE_HASH(s, s->ins_h, s->window[(str) + 2]),                                      \
     s->prev[(str) & s->w_mask] = match_head = s->head[s->ins_h], s->head[s->ins_h] = (ts4l_u16)(str))

#define TS4L_D_CODE(dist) ((ts4l_u8)((dist) < 256 ? lbl_8307BA70[dist] : lbl_8307BA70[256 + ((dist) >> 7)]))

#define TS4L_TR_TALLY_LIT(s, c, flush)                                                         \
    {                                                                                          \
        ts4l_u8 cc = (c);                                                                      \
        s->d_buf[s->last_lit] = 0;                                                             \
        s->l_buf[s->last_lit++] = cc;                                                          \
        s->dyn_ltree[cc].freq++;                                                               \
        flush = (s->last_lit == s->lit_bufsize - 1);                                           \
    }

#define TS4L_TR_TALLY_DIST(s, distance, length, flush)                                         \
    {                                                                                          \
        ts4l_u8 len = (length);                                                                \
        ts4l_u16 dist = (distance);                                                            \
        s->d_buf[s->last_lit] = dist;                                                          \
        s->l_buf[s->last_lit++] = len;                                                         \
        dist--;                                                                                \
        s->dyn_ltree[lbl_8307BC70[len] + 256 + 1].freq++;                                      \
        s->dyn_dtree[TS4L_D_CODE(dist)].freq++;                                                \
        flush = (s->last_lit == s->lit_bufsize - 1);                                           \
    }

#define TS4L_FLUSH_BLOCK_ONLY(s, eof)                                                          \
    {                                                                                          \
        fn_83465708(s,                                                                         \
                    (s->block_start >= 0L ? (char *)&s->window[(unsigned)s->block_start]       \
                                          : (char *)0),                                        \
                    (ts4l_u32)((long)s->strstart - s->block_start), (eof));                    \
        s->block_start = s->strstart;                                                          \
        fn_83452070(s->strm);                                                                  \
    }

#define TS4L_FLUSH_BLOCK(s, eof)                                                               \
    {                                                                                          \
        TS4L_FLUSH_BLOCK_ONLY(s, eof);                                                         \
        if (s->strm->avail_out == 0)                                                           \
            return (eof) ? 2 : 0;                                                              \
    }

int ts4l_zlib_deflate_slow_83453308(ts4l_zstate *s, int flush)
{
    ts4l_u32 hash_head = 0;
    int bflush;

    for (;;) {
        if (s->lookahead < 262) {
            fn_83452B18(s);
            if (s->lookahead < 262 && flush == 0)
                return 0;
            if (s->lookahead == 0)
                break;
        }

        if (s->lookahead >= 3) {
            TS4L_INSERT_STRING(s, s->strstart, hash_head);
        }

        s->prev_length = s->match_length, s->prev_match = s->match_start;
        s->match_length = 3 - 1;

        if (hash_head != 0 && s->prev_length < s->max_lazy_match &&
            s->strstart - hash_head <= s->w_size - 262) {
            if (s->strategy != 2) {
                s->match_length = fn_83452960(s, hash_head);
            }
            if (s->match_length <= 5 &&
                (s->strategy == 1 || (s->match_length == 3 && s->strstart - s->match_start > 4096))) {
                s->match_length = 3 - 1;
            }
        }
        if (s->prev_length >= 3 && s->match_length <= s->prev_length) {
            ts4l_u32 max_insert = s->strstart + s->lookahead - 3;

            TS4L_TR_TALLY_DIST(s, s->strstart - 1 - s->prev_match, s->prev_length - 3, bflush);

            s->lookahead -= s->prev_length - 1;
            s->prev_length -= 2;
            do {
                if (++s->strstart <= max_insert) {
                    TS4L_INSERT_STRING(s, s->strstart, hash_head);
                }
            } while (--s->prev_length != 0);
            s->match_available = 0;
            s->match_length = 3 - 1;
            s->strstart++;

            if (bflush)
                TS4L_FLUSH_BLOCK(s, 0);

        } else if (s->match_available) {
            TS4L_TR_TALLY_LIT(s, s->window[s->strstart - 1], bflush);
            if (bflush) {
                TS4L_FLUSH_BLOCK_ONLY(s, 0);
            }
            s->strstart++;
            s->lookahead--;
            if (s->strm->avail_out == 0)
                return 0;
        } else {
            s->match_available = 1;
            s->strstart++;
            s->lookahead--;
        }
    }
    if (s->match_available) {
        TS4L_TR_TALLY_LIT(s, s->window[s->strstart - 1], bflush);
        s->match_available = 0;
    }
    TS4L_FLUSH_BLOCK(s, flush == 4);
    return flush == 4 ? 3 : 1;
}
