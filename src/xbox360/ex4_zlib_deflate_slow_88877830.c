/* Derived from zlib 1.2.3 (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX4: zlib 1.2.3 deflate.c deflate_slow and deflate_fast (lazy and greedy match strategies). */
#include "ex3_zlib.h"

struct ex3_z_stream {
    unsigned char *next_in;  /* +0x00 */
    unsigned int avail_in;   /* +0x04 */
    unsigned long total_in;  /* +0x08 */
    unsigned char *next_out; /* +0x0C */
    unsigned int avail_out;  /* +0x10 */
};

extern const unsigned char lbl_880CA398[512]; /* _dist_code */
extern const unsigned char lbl_880CA598[256]; /* _length_code */

void ex3_fill_window_888776C8(ex3_deflate_state *s);
unsigned ex3_longest_match_888761B0(ex3_deflate_state *s, unsigned cur_match);
unsigned ex3_longest_match_fast_888760B8(ex3_deflate_state *s, unsigned cur_match);
void fn_88873870(ex3_deflate_state *s, unsigned char *buf, unsigned long stored_len, int eof); /* _tr_flush_block */
void ex3_flush_pending_88876570(struct ex3_z_stream *strm);

#define EX4_Z_NO_FLUSH 0
#define EX4_Z_FILTERED 1
#define EX4_Z_RLE 3
#define EX4_Z_FINISH 4
#define EX4_NEED_MORE 0
#define EX4_BLOCK_DONE 1
#define EX4_FINISH_STARTED 2
#define EX4_FINISH_DONE 3
#define EX4_MIN_LOOKAHEAD 262
#define EX4_MAX_DIST(s) ((s)->w_size - EX4_MIN_LOOKAHEAD)
#define EX4_TOO_FAR 4096
#define EX4_NIL 0
#define EX4_LITERALS 256

#define EX4_UPDATE_HASH(s, h, c) (h = (((h) << (s)->hash_shift) ^ (c)) & (s)->hash_mask)
#define EX4_INSERT_STRING(s, str, match_head)                                                    \
    (EX4_UPDATE_HASH(s, (s)->ins_h, (s)->window[(str) + (3 - 1)]),                               \
     match_head = (s)->prev[(str) & (s)->w_mask] = (s)->head[(s)->ins_h], (s)->head[(s)->ins_h] = (unsigned short)(str))

#define EX4_D_CODE(dist) ((dist) < 256 ? lbl_880CA398[dist] : lbl_880CA398[256 + ((dist) >> 7)])

#define EX4_TALLY_LIT(s, c, flush)                          \
    {                                                       \
        unsigned char cc = (c);                             \
        (s)->d_buf[(s)->last_lit] = 0;                      \
        (s)->l_buf[(s)->last_lit++] = cc;                   \
        (s)->dyn_ltree[cc].fc++;                            \
        flush = ((s)->last_lit == (s)->lit_bufsize - 1);    \
    }

#define EX4_TALLY_DIST(s, distance, length, flush)                                          \
    {                                                                                       \
        unsigned char len = (unsigned char)(length);                                        \
        unsigned short dist = (unsigned short)(distance);                                   \
        (s)->d_buf[(s)->last_lit] = dist;                                                   \
        (s)->l_buf[(s)->last_lit++] = len;                                                  \
        dist--;                                                                             \
        (s)->dyn_ltree[lbl_880CA598[len] + EX4_LITERALS + 1].fc++;                          \
        (s)->dyn_dtree[EX4_D_CODE(dist)].fc++;                                              \
        flush = ((s)->last_lit == (s)->lit_bufsize - 1);                                    \
    }

#define EX4_FLUSH_BLOCK_ONLY(s, last)                                                                      \
    {                                                                                                      \
        fn_88873870((s), ((s)->block_start >= 0L ? &(s)->window[(unsigned)(s)->block_start] : (unsigned char *)0), \
                    (unsigned long)((long)(s)->strstart - (s)->block_start), (last));                      \
        (s)->block_start = (s)->strstart;                                                                  \
        ex3_flush_pending_88876570((s)->strm);                                                             \
    }

#define EX4_FLUSH_BLOCK(s, last)                                              \
    {                                                                         \
        EX4_FLUSH_BLOCK_ONLY(s, last);                                        \
        if ((s)->strm->avail_out == 0)                                        \
            return (last) ? EX4_FINISH_STARTED : EX4_NEED_MORE;               \
    }

/* Lazy-evaluation deflate for levels 4-9 (zlib deflate_slow). Swing_DLL.xex 0x88877830 */
int ex4_deflate_slow_88877830(ex3_deflate_state *s, int flush)
{
    unsigned hash_head = EX4_NIL;
    int bflush;

    for (;;) {
        if (s->lookahead < EX4_MIN_LOOKAHEAD) {
            ex3_fill_window_888776C8(s);
            if (s->lookahead < EX4_MIN_LOOKAHEAD && flush == EX4_Z_NO_FLUSH) {
                return EX4_NEED_MORE;
            }
            if (s->lookahead == 0)
                break;
        }

        if (s->lookahead >= 3)
            EX4_INSERT_STRING(s, s->strstart, hash_head);

        s->prev_length = s->match_length, s->prev_match = s->match_start;
        s->match_length = 3 - 1;

        if (hash_head != EX4_NIL && s->prev_length < s->max_lazy_match &&
            s->strstart - hash_head <= EX4_MAX_DIST(s)) {
            if (s->strategy != 2 && s->strategy != EX4_Z_RLE) {
                s->match_length = ex3_longest_match_888761B0(s, hash_head);
            } else if (s->strategy == EX4_Z_RLE && s->strstart - hash_head == 1) {
                s->match_length = ex3_longest_match_fast_888760B8(s, hash_head);
            }
            if (s->match_length <= 5 &&
                (s->strategy == EX4_Z_FILTERED || (s->match_length == 3 && s->strstart - s->match_start > EX4_TOO_FAR))) {
                s->match_length = 3 - 1;
            }
        }
        if (s->prev_length >= 3 && s->match_length <= s->prev_length) {
            unsigned max_insert = s->strstart + s->lookahead - 3;

            EX4_TALLY_DIST(s, s->strstart - 1 - s->prev_match, s->prev_length - 3, bflush);

            s->lookahead -= s->prev_length - 1;
            s->prev_length -= 2;
            do {
                if (++s->strstart <= max_insert) {
                    EX4_INSERT_STRING(s, s->strstart, hash_head);
                }
            } while (--s->prev_length != 0);
            s->match_available = 0;
            s->match_length = 3 - 1;
            s->strstart++;

            if (bflush)
                EX4_FLUSH_BLOCK(s, 0);

        } else if (s->match_available) {
            EX4_TALLY_LIT(s, s->window[s->strstart - 1], bflush);
            if (bflush) {
                EX4_FLUSH_BLOCK_ONLY(s, 0);
            }
            s->strstart++;
            s->lookahead--;
            if (s->strm->avail_out == 0)
                return EX4_NEED_MORE;
        } else {
            s->match_available = 1;
            s->strstart++;
            s->lookahead--;
        }
    }
    if (s->match_available) {
        EX4_TALLY_LIT(s, s->window[s->strstart - 1], bflush);
        s->match_available = 0;
    }
    EX4_FLUSH_BLOCK(s, flush == EX4_Z_FINISH);
    return flush == EX4_Z_FINISH ? EX4_FINISH_DONE : EX4_BLOCK_DONE;
}

/* Greedy deflate for levels 1-3 (zlib deflate_fast). Swing_DLL.xex 0x88877DB0 */
int ex4_deflate_fast_88877DB0(ex3_deflate_state *s, int flush)
{
    unsigned hash_head = EX4_NIL;
    int bflush;

    for (;;) {
        if (s->lookahead < EX4_MIN_LOOKAHEAD) {
            ex3_fill_window_888776C8(s);
            if (s->lookahead < EX4_MIN_LOOKAHEAD && flush == EX4_Z_NO_FLUSH) {
                return EX4_NEED_MORE;
            }
            if (s->lookahead == 0)
                break;
        }

        if (s->lookahead >= 3) {
            EX4_INSERT_STRING(s, s->strstart, hash_head);
        }

        if (hash_head != EX4_NIL && s->strstart - hash_head <= EX4_MAX_DIST(s)) {
            if (s->strategy != 2 && s->strategy != EX4_Z_RLE) {
                s->match_length = ex3_longest_match_888761B0(s, hash_head);
            } else if (s->strategy == EX4_Z_RLE && s->strstart - hash_head == 1) {
                s->match_length = ex3_longest_match_fast_888760B8(s, hash_head);
            }
        }
        if (s->match_length >= 3) {
            EX4_TALLY_DIST(s, s->strstart - s->match_start, s->match_length - 3, bflush);

            s->lookahead -= s->match_length;

            if (s->match_length <= s->max_lazy_match && s->lookahead >= 3) {
                s->match_length--;
                do {
                    s->strstart++;
                    EX4_INSERT_STRING(s, s->strstart, hash_head);
                } while (--s->match_length != 0);
                s->strstart++;
            } else {
                s->strstart += s->match_length;
                s->match_length = 0;
                s->ins_h = s->window[s->strstart];
                EX4_UPDATE_HASH(s, s->ins_h, s->window[s->strstart + 1]);
            }
        } else {
            EX4_TALLY_LIT(s, s->window[s->strstart], bflush);
            s->lookahead--;
            s->strstart++;
        }
        if (bflush)
            EX4_FLUSH_BLOCK(s, 0);
    }
    EX4_FLUSH_BLOCK(s, flush == EX4_Z_FINISH);
    return flush == EX4_Z_FINISH ? EX4_FINISH_DONE : EX4_BLOCK_DONE;
}
