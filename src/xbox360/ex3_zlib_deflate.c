/* Derived from zlib (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: zlib 1.2.x deflate.c helpers (longest_match, lm_init, deflateEnd, flush_pending). */
#include "ex3_zlib.h"

#ifdef _MSC_VER
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void *memset(void *dst, int c, unsigned int n);
#else
#include <string.h>
#endif

typedef void *(*ex3_alloc_func)(void *opaque, unsigned items, unsigned size);
typedef void (*ex3_free_func)(void *opaque, void *address);

/* z_stream as used here. */
typedef struct ex3_zs {
    unsigned char *next_in;   /* +0x00 */
    unsigned int avail_in;    /* +0x04 */
    unsigned long total_in;   /* +0x08 */
    unsigned char *next_out;  /* +0x0C */
    unsigned int avail_out;   /* +0x10 */
    unsigned long total_out;  /* +0x14 */
    char *msg;                /* +0x18 */
    ex3_deflate_state *state; /* +0x1C */
    ex3_alloc_func zalloc;    /* +0x20 */
    ex3_free_func zfree;      /* +0x24 */
    void *opaque;             /* +0x28 */
} ex3_zs;

#define EX3_INIT_STATE 42
#define EX3_EXTRA_STATE 69
#define EX3_NAME_STATE 73
#define EX3_COMMENT_STATE 91
#define EX3_HCRC_STATE 103
#define EX3_BUSY_STATE 113
#define EX3_FINISH_STATE 666
#define EX3_MIN_LOOKAHEAD (258 + 3 + 1)
#define EX3_MAX_DIST(s) ((s)->w_size - EX3_MIN_LOOKAHEAD)
#define EX3_NIL 0

/* deflate configuration_table entry. */
typedef struct ex3_config {
    unsigned short good_length;
    unsigned short max_lazy;
    unsigned short nice_length;
    unsigned short max_chain;
    void *func;
} ex3_config;

static const ex3_config lbl_880CBA48[10] = {{1, 1, 1, 1, 0}};

unsigned ts4_if_call_seq_u32_off4_88876668(ex3_zs *strm, unsigned char *buf, unsigned size); /* read_buf */
int fn_88877328(ex3_zs *strm); /* deflateReset: not matched yet (needs _tr_init in the same translation unit) */

void *ts4_tailcall_fn_88565258_88871CF0(void *opaque, unsigned items, unsigned size); /* zcalloc */
void ts4_tailcall_fn_885651F8_88871CE8(void *opaque, void *address);                    /* zcfree */
extern const char lbl_880DFC10[]; /* "insufficient memory" */

/* Free a pointer through the stream's allocator (zlib TRY_FREE). */
#define EX3_TRY_FREE(s, p)                                  \
    {                                                       \
        if (p)                                              \
            (*((s)->zfree))((s)->opaque, (void *)(p));      \
    }

#define EX3_CLEAR_HASH(s)                                                        \
    (s)->head[(s)->hash_size - 1] = 0;                                           \
    memset((void *)(s)->head, 0, (unsigned)((s)->hash_size - 1) * sizeof(*(s)->head));

/* Initialise the match finder for a new stream (zlib lm_init). Swing_DLL.xex 0x88876368 */
void ex3_lm_init_88876368(ex3_deflate_state *s)
{
    s->window_size = (unsigned long)2L * s->w_size;

    EX3_CLEAR_HASH(s);

    s->max_lazy_match = lbl_880CBA48[s->level].max_lazy;
    s->good_match = lbl_880CBA48[s->level].good_length;
    s->nice_match = lbl_880CBA48[s->level].nice_length;
    s->max_chain_length = lbl_880CBA48[s->level].max_chain;

    s->strstart = 0;
    s->block_start = 0L;
    s->lookahead = 0;
    s->match_length = s->prev_length = 3 - 1;
    s->match_available = 0;
    s->ins_h = 0;
}

/* Fast longest_match used for the FASTEST (level 1) strategy: only the head candidate is checked
 * (zlib longest_match, FASTEST variant). Swing_DLL.xex 0x888760B8 */
unsigned ex3_longest_match_fast_888760B8(ex3_deflate_state *s, unsigned cur_match)
{
    register unsigned char *scan = s->window + s->strstart;
    register unsigned char *match;
    register int len;
    unsigned char *strend = s->window + s->strstart + 258;

    match = s->window + cur_match;
    if (match[0] != scan[0] || match[1] != scan[1])
        return 3 - 1;

    scan += 2, match += 2;
    do {
    } while (*++scan == *++match && *++scan == *++match && *++scan == *++match && *++scan == *++match &&
             *++scan == *++match && *++scan == *++match && *++scan == *++match && *++scan == *++match &&
             scan < strend);

    len = 258 - (int)(strend - scan);

    if (len < 3)
        return 3 - 1;

    s->match_start = cur_match;
    return (unsigned)len <= s->lookahead ? (unsigned)len : s->lookahead;
}

/* Find the longest match in the hash chain for the string at strstart (zlib longest_match).
 * Swing_DLL.xex 0x888761B0 */
unsigned ex3_longest_match_888761B0(ex3_deflate_state *s, unsigned cur_match)
{
    unsigned chain_length = s->max_chain_length;
    register unsigned char *scan = s->window + s->strstart;
    register unsigned char *match;
    register int len;
    int best_len = s->prev_length;
    int nice_match = s->nice_match;
    unsigned limit = s->strstart > (unsigned)EX3_MAX_DIST(s) ? s->strstart - (unsigned)EX3_MAX_DIST(s) : 0;
    unsigned short *prev = s->prev;
    unsigned wmask = s->w_mask;
    register unsigned char *strend = s->window + s->strstart + 258;
    register unsigned char scan_end1 = scan[best_len - 1];
    register unsigned char scan_end = scan[best_len];

    if (s->prev_length >= s->good_match) {
        chain_length >>= 2;
    }
    if ((unsigned)nice_match > s->lookahead)
        nice_match = s->lookahead;

    do {
        match = s->window + cur_match;

        if (match[best_len] != scan_end || match[best_len - 1] != scan_end1 || *match != *scan ||
            *++match != scan[1])
            continue;

        scan += 2, match++;
        do {
        } while (*++scan == *++match && *++scan == *++match && *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match && *++scan == *++match && *++scan == *++match &&
                 scan < strend);

        len = 258 - (int)(strend - scan);
        scan = strend - 258;

        if (len > best_len) {
            s->match_start = cur_match;
            best_len = len;
            if (len >= nice_match)
                break;
            scan_end1 = scan[best_len - 1];
            scan_end = scan[best_len];
        }
    } while ((cur_match = prev[cur_match & wmask]) > limit && --chain_length != 0);

    if ((unsigned)best_len <= s->lookahead)
        return (unsigned)best_len;
    return s->lookahead;
}

/* Free all the memory of a deflate stream (zlib deflateEnd). Swing_DLL.xex 0x88876438 */
int ex3_deflateEnd_88876438(ex3_zs *strm)
{
    int status;

    if (strm == (ex3_zs *)0 || strm->state == (ex3_deflate_state *)0)
        return -2;

    status = strm->state->status;
    if (status != EX3_INIT_STATE && status != EX3_EXTRA_STATE && status != EX3_NAME_STATE &&
        status != EX3_COMMENT_STATE && status != EX3_HCRC_STATE && status != EX3_BUSY_STATE &&
        status != EX3_FINISH_STATE) {
        return -2;
    }

    EX3_TRY_FREE(strm, strm->state->pending_buf);
    EX3_TRY_FREE(strm, strm->state->head);
    EX3_TRY_FREE(strm, strm->state->prev);
    EX3_TRY_FREE(strm, strm->state->window);

    (*(strm->zfree))(strm->opaque, (void *)strm->state);
    strm->state = (ex3_deflate_state *)0;

    return status == EX3_BUSY_STATE ? -3 : 0;
}

/* Copy as much pending output as fits into the output buffer (zlib flush_pending).
 * Swing_DLL.xex 0x88876570 */
void ex3_flush_pending_88876570(ex3_zs *strm)
{
    unsigned len = strm->state->pending;

    if (len > strm->avail_out)
        len = strm->avail_out;
    if (len == 0)
        return;

    memcpy(strm->next_out, strm->state->pending_out, len);
    strm->next_out += len;
    strm->state->pending_out += len;
    strm->total_out += len;
    strm->avail_out -= len;
    strm->state->pending -= len;
    if (strm->state->pending == 0) {
        strm->state->pending_out = strm->state->pending_buf;
    }
}

/* Put a 16-bit value, most significant byte first, into the pending buffer (zlib putShortMSB).
 * Swing_DLL.xex 0x88876630 */
void ex3_putShortMSB_88876630(ex3_deflate_state *s, unsigned b)
{
    EX3_PUT_BYTE(s, (unsigned char)(b >> 8));
    EX3_PUT_BYTE(s, (unsigned char)(b & 0xff));
}

/* Fill the window when the lookahead becomes insufficient, sliding it when it is nearly full
 * (zlib fill_window). Swing_DLL.xex 0x888776C8 */
void ex3_fill_window_888776C8(ex3_deflate_state *s)
{
    register unsigned n, m;
    register unsigned short *p;
    unsigned more;
    unsigned wsize = s->w_size;

    do {
        more = (unsigned)(s->window_size - (unsigned long)s->lookahead - (unsigned long)s->strstart);

        if (s->strstart >= wsize + EX3_MAX_DIST(s)) {
            memcpy(s->window, s->window + wsize, (unsigned)wsize);
            s->match_start -= wsize;
            s->strstart -= wsize;
            s->block_start -= (long)wsize;

            n = s->hash_size;
            p = &s->head[n];
            do {
                m = *--p;
                *p = (unsigned short)(m >= wsize ? m - wsize : EX3_NIL);
            } while (--n);

            n = wsize;
            p = &s->prev[n];
            do {
                m = *--p;
                *p = (unsigned short)(m >= wsize ? m - wsize : EX3_NIL);
            } while (--n);
            more += wsize;
        }
        if (((ex3_zs *)s->strm)->avail_in == 0)
            return;

        n = ts4_if_call_seq_u32_off4_88876668((ex3_zs *)s->strm, s->window + s->strstart + s->lookahead, more);
        s->lookahead += n;

        if (s->lookahead >= 3) {
            s->ins_h = s->window[s->strstart];
            s->ins_h = ((s->ins_h << s->hash_shift) ^ s->window[s->strstart + 1]) & s->hash_mask;
        }
    } while (s->lookahead < EX3_MIN_LOOKAHEAD && ((ex3_zs *)s->strm)->avail_in != 0);
}

/* Initialise a deflate stream with explicit parameters (zlib deflateInit2_). Swing_DLL.xex 0x88877400 */
int ex3_deflateInit2__88877400(ex3_zs *strm, int level, int method, int windowBits, int memLevel, int strategy,
                               const char *version, unsigned stream_size)
{
    ex3_deflate_state *s;
    int wrap = 1;
    unsigned short *overlay;

    if (version == (const char *)0 || version[0] != '1' || stream_size != 56)
        return -6;
    if (strm == (ex3_zs *)0)
        return -2;

    strm->msg = (char *)0;
    if (strm->zalloc == (ex3_alloc_func)0) {
        strm->zalloc = (ex3_alloc_func)ts4_tailcall_fn_88565258_88871CF0;
        strm->opaque = (void *)0;
    }
    if (strm->zfree == (ex3_free_func)0)
        strm->zfree = (ex3_free_func)ts4_tailcall_fn_885651F8_88871CE8;

    if (level == -1)
        level = 6;

    if (windowBits < 0) {
        wrap = 0;
        windowBits = -windowBits;
    } else if (windowBits > 15) {
        wrap = 2;
        windowBits -= 16;
    }
    if (memLevel < 1 || memLevel > 9 || method != 8 || windowBits < 8 || windowBits > 15 || level < 0 ||
        level > 9 || strategy < 0 || strategy > 4) {
        return -2;
    }
    if (windowBits == 8)
        windowBits = 9;
    s = (ex3_deflate_state *)(*(strm->zalloc))(strm->opaque, 1, sizeof(ex3_deflate_state));
    if (s == (ex3_deflate_state *)0)
        return -4;
    strm->state = s;
    s->strm = (void *)strm;

    s->wrap = wrap;
    s->gzhead = (void *)0;
    s->w_bits = windowBits;
    s->w_size = 1 << s->w_bits;
    s->w_mask = s->w_size - 1;

    s->hash_bits = memLevel + 7;
    s->hash_size = 1 << s->hash_bits;
    s->hash_mask = s->hash_size - 1;
    s->hash_shift = ((s->hash_bits + 3 - 1) / 3);

    s->window = (unsigned char *)(*(strm->zalloc))(strm->opaque, s->w_size, 2 * sizeof(unsigned char));
    s->prev = (unsigned short *)(*(strm->zalloc))(strm->opaque, s->w_size, sizeof(unsigned short));
    s->head = (unsigned short *)(*(strm->zalloc))(strm->opaque, s->hash_size, sizeof(unsigned short));

    s->lit_bufsize = 1 << (memLevel + 6);

    overlay = (unsigned short *)(*(strm->zalloc))(strm->opaque, s->lit_bufsize, sizeof(unsigned short) + 2);
    s->pending_buf = (unsigned char *)overlay;
    s->pending_buf_size = (unsigned long)s->lit_bufsize * (sizeof(unsigned short) + 2L);

    if (s->window == (unsigned char *)0 || s->prev == (unsigned short *)0 || s->head == (unsigned short *)0 ||
        s->pending_buf == (unsigned char *)0) {
        s->status = EX3_FINISH_STATE;
        strm->msg = (char *)lbl_880DFC10;
        ex3_deflateEnd_88876438(strm);
        return -4;
    }
    s->d_buf = overlay + s->lit_bufsize / sizeof(unsigned short);
    s->l_buf = s->pending_buf + (1 + sizeof(unsigned short)) * s->lit_bufsize;

    s->level = level;
    s->strategy = strategy;
    s->method = (unsigned char)method;

    return fn_88877328(strm);
}
