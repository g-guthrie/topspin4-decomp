/* Derived from zlib (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: zlib 1.2.3 inflate.c stream setup, teardown and window handling. */

#ifdef _MSC_VER
extern void *memcpy(void *dst, const void *src, unsigned int n);
#else
#include <string.h>
#endif

typedef void *(*ex3_alloc_func)(void *opaque, unsigned items, unsigned size);
typedef void (*ex3_free_func)(void *opaque, void *address);

struct ex3_inflate_state;

typedef struct ex3_zstream {
    unsigned char *next_in;   /* +0x00 */
    unsigned int avail_in;    /* +0x04 */
    unsigned long total_in;   /* +0x08 */
    unsigned char *next_out;  /* +0x0C */
    unsigned int avail_out;   /* +0x10 */
    unsigned long total_out;  /* +0x14 */
    char *msg;                /* +0x18 */
    struct ex3_inflate_state *state; /* +0x1C */
    ex3_alloc_func zalloc;    /* +0x20 */
    ex3_free_func zfree;      /* +0x24 */
    void *opaque;             /* +0x28 */
    int data_type;            /* +0x2C */
    unsigned long adler;      /* +0x30 */
    unsigned long reserved;   /* +0x34 */
} ex3_zstream;

typedef struct ex3_code {
    unsigned char op;
    unsigned char bits;
    unsigned short val;
} ex3_code;

/* zlib 1.2.3 inflate_state; offsets verified against the machine code. */
typedef struct ex3_inflate_state {
    int mode;                      /* +0x00 */
    int last;                      /* +0x04 */
    int wrap;                      /* +0x08 */
    int havedict;                  /* +0x0C */
    int flags;                     /* +0x10 */
    unsigned dmax;                 /* +0x14 */
    unsigned long check;           /* +0x18 */
    unsigned long total;           /* +0x1C */
    void *head;                    /* +0x20 */
    unsigned wbits;                /* +0x24 */
    unsigned wsize;                /* +0x28 */
    unsigned whave;                /* +0x2C */
    unsigned write;                /* +0x30 */
    unsigned char *window;         /* +0x34 */
    unsigned long hold;            /* +0x38 */
    unsigned bits;                 /* +0x3C */
    unsigned length;               /* +0x40 */
    unsigned offset;               /* +0x44 */
    unsigned extra;                /* +0x48 */
    const ex3_code *lencode;       /* +0x4C */
    const ex3_code *distcode;      /* +0x50 */
    unsigned lenbits;              /* +0x54 */
    unsigned distbits;             /* +0x58 */
    unsigned ncode;                /* +0x5C */
    unsigned nlen;                 /* +0x60 */
    unsigned ndist;                /* +0x64 */
    unsigned have;                 /* +0x68 */
    ex3_code *next;                /* +0x6C */
    unsigned short lens[320];      /* +0x70 */
    unsigned short work[288];      /* +0x2F0 */
    ex3_code codes[2048];          /* +0x530 */
} ex3_inflate_state;

void ts4_tailcall_fn_885651F8_88871CE8(void *opaque, void *address);
void *ts4_tailcall_fn_88565258_88871CF0(void *opaque, unsigned items, unsigned size);

/* Free the inflate state and its window (zlib inflateEnd). Swing_DLL.xex 0x88873FE0 */
int ex3_inflateEnd_88873FE0(ex3_zstream *strm)
{
    ex3_inflate_state *state;

    if (strm == (ex3_zstream *)0 || strm->state == (ex3_inflate_state *)0 || strm->zfree == (ex3_free_func)0)
        return -2;
    state = strm->state;
    if (state->window != (unsigned char *)0)
        (*(strm->zfree))(strm->opaque, (void *)(state->window));
    (*(strm->zfree))(strm->opaque, (void *)(strm->state));
    strm->state = (ex3_inflate_state *)0;
    return 0;
}

/* Copy the newest output into the circular sliding window, allocating it on first use
 * (zlib updatewindow); returns non-zero when the allocation fails. Swing_DLL.xex 0x88874078 */
int ex3_updatewindow_88874078(ex3_zstream *strm, unsigned out)
{
    ex3_inflate_state *state;
    unsigned copy, dist;

    state = strm->state;

    if (state->window == (unsigned char *)0) {
        state->window = (unsigned char *)(*(strm->zalloc))(strm->opaque, 1U << state->wbits, sizeof(unsigned char));
        if (state->window == (unsigned char *)0)
            return 1;
    }

    if (state->wsize == 0) {
        state->wsize = 1U << state->wbits;
        state->write = 0;
        state->whave = 0;
    }

    copy = out - strm->avail_out;
    if (copy >= state->wsize) {
        memcpy(state->window, strm->next_out - state->wsize, state->wsize);
        state->write = 0;
        state->whave = state->wsize;
    } else {
        dist = state->wsize - state->write;
        if (dist > copy)
            dist = copy;
        memcpy(state->window + state->write, strm->next_out - copy, dist);
        copy -= dist;
        if (copy) {
            memcpy(state->window, strm->next_out - copy, copy);
            state->write = copy;
            state->whave = state->wsize;
        } else {
            state->write += dist;
            if (state->write == state->wsize)
                state->write = 0;
            if (state->whave < state->wsize)
                state->whave += dist;
        }
    }
    return 0;
}

/* Reset an inflate stream (zlib inflateReset). Swing_DLL.xex 0x888741F0 */
int ex3_inflateReset_888741F0(ex3_zstream *strm)
{
    ex3_inflate_state *state;

    if (strm == (ex3_zstream *)0 || strm->state == (ex3_inflate_state *)0)
        return -2;
    state = strm->state;
    strm->total_in = strm->total_out = state->total = 0;
    strm->msg = (char *)0;
    strm->adler = 1;
    state->mode = 0;
    state->last = 0;
    state->havedict = 0;
    state->dmax = 32768U;
    state->head = (void *)0;
    state->wsize = 0;
    state->whave = 0;
    state->write = 0;
    state->hold = 0;
    state->bits = 0;
    state->lencode = state->distcode = state->next = state->codes;
    return 0;
}

/* Initialise an inflate stream with an explicit window size (zlib inflateInit2_).
 * Swing_DLL.xex 0x88875B18 */
int ex3_inflateInit2__88875B18(ex3_zstream *strm, int windowBits, const char *version, int stream_size)
{
    ex3_inflate_state *state;

    if (version == (const char *)0 || version[0] != '1' || stream_size != 56)
        return -6;
    if (strm == (ex3_zstream *)0)
        return -2;
    strm->msg = (char *)0;
    if (strm->zalloc == (ex3_alloc_func)0) {
        strm->zalloc = (ex3_alloc_func)ts4_tailcall_fn_88565258_88871CF0;
        strm->opaque = (void *)0;
    }
    if (strm->zfree == (ex3_free_func)0)
        strm->zfree = (ex3_free_func)ts4_tailcall_fn_885651F8_88871CE8;
    state = (ex3_inflate_state *)(*(strm->zalloc))(strm->opaque, 1, sizeof(ex3_inflate_state));
    if (state == (ex3_inflate_state *)0)
        return -4;
    strm->state = state;
    if (windowBits < 0) {
        state->wrap = 0;
        windowBits = -windowBits;
    } else {
        state->wrap = (windowBits >> 4) + 1;
        if (windowBits < 48)
            windowBits &= 15;
    }
    if (windowBits < 8 || windowBits > 15) {
        (*(strm->zfree))(strm->opaque, (void *)(state));
        strm->state = (ex3_inflate_state *)0;
        return -2;
    }
    state->wbits = (unsigned)windowBits;
    state->window = (unsigned char *)0;
    return ex3_inflateReset_888741F0(strm);
}

extern const char lbl_880DFB20[]; /* "invalid distance too far back" */
extern const char lbl_880DFB08[]; /* "invalid distance code" */
extern const char lbl_880DFAEC[]; /* "invalid literal/length code" */

#define EX3_OFF 1
#define EX3_PUP(a) *++(a)

/* Decode literals and matches in one pass while enough input and output room is available
 * (zlib inflate_fast). Swing_DLL.xex 0x88875C60 */
void ex3_inflate_fast_88875C60(ex3_zstream *strm, unsigned start)
{
    ex3_inflate_state *state;
    unsigned char *in;
    unsigned char *last;
    unsigned char *out;
    unsigned char *beg;
    unsigned char *end;
    unsigned wsize;
    unsigned whave;
    unsigned write;
    unsigned char *window;
    unsigned long hold;
    unsigned bits;
    const ex3_code *lcode;
    const ex3_code *dcode;
    unsigned lmask;
    unsigned dmask;
    ex3_code this_;
    unsigned op;
    unsigned len;
    unsigned dist;
    unsigned char *from;

    state = strm->state;
    in = strm->next_in - EX3_OFF;
    last = in + (strm->avail_in - 5);
    out = strm->next_out - EX3_OFF;
    beg = out - (start - strm->avail_out);
    end = out + (strm->avail_out - 257);
    wsize = state->wsize;
    whave = state->whave;
    write = state->write;
    window = state->window;
    hold = state->hold;
    bits = state->bits;
    lcode = state->lencode;
    dcode = state->distcode;
    lmask = (1U << state->lenbits) - 1;
    dmask = (1U << state->distbits) - 1;

    do {
        if (bits < 15) {
            hold += (unsigned long)(EX3_PUP(in)) << bits;
            bits += 8;
            hold += (unsigned long)(EX3_PUP(in)) << bits;
            bits += 8;
        }
        this_ = lcode[hold & lmask];
    dolen:
        op = (unsigned)(this_.bits);
        hold >>= op;
        bits -= op;
        op = (unsigned)(this_.op);
        if (op == 0) {
            EX3_PUP(out) = (unsigned char)(this_.val);
        } else if (op & 16) {
            len = (unsigned)(this_.val);
            op &= 15;
            if (op) {
                if (bits < op) {
                    hold += (unsigned long)(EX3_PUP(in)) << bits;
                    bits += 8;
                }
                len += (unsigned)hold & ((1U << op) - 1);
                hold >>= op;
                bits -= op;
            }
            if (bits < 15) {
                hold += (unsigned long)(EX3_PUP(in)) << bits;
                bits += 8;
                hold += (unsigned long)(EX3_PUP(in)) << bits;
                bits += 8;
            }
            this_ = dcode[hold & dmask];
        dodist:
            op = (unsigned)(this_.bits);
            hold >>= op;
            bits -= op;
            op = (unsigned)(this_.op);
            if (op & 16) {
                dist = (unsigned)(this_.val);
                op &= 15;
                if (bits < op) {
                    hold += (unsigned long)(EX3_PUP(in)) << bits;
                    bits += 8;
                    if (bits < op) {
                        hold += (unsigned long)(EX3_PUP(in)) << bits;
                        bits += 8;
                    }
                }
                dist += (unsigned)hold & ((1U << op) - 1);
                hold >>= op;
                bits -= op;
                op = (unsigned)(out - beg);
                if (dist > op) {
                    op = dist - op;
                    if (op > whave) {
                        strm->msg = (char *)lbl_880DFB20;
                        state->mode = 27;
                        break;
                    }
                    from = window - EX3_OFF;
                    if (write == 0) {
                        from += wsize - op;
                        if (op < len) {
                            len -= op;
                            do {
                                EX3_PUP(out) = EX3_PUP(from);
                            } while (--op);
                            from = out - dist;
                            do {
                                EX3_PUP(out) = EX3_PUP(from);
                            } while (--len);
                        }
                    } else if (write < op) {
                        from += wsize + write - op;
                        op -= write;
                        if (op < len) {
                            len -= op;
                            do {
                                EX3_PUP(out) = EX3_PUP(from);
                            } while (--op);
                            from = window - EX3_OFF;
                            if (write < len) {
                                op = write;
                                len -= op;
                                do {
                                    EX3_PUP(out) = EX3_PUP(from);
                                } while (--op);
                                from = out - dist;
                                do {
                                    EX3_PUP(out) = EX3_PUP(from);
                                } while (--len);
                            }
                        }
                    } else {
                        from += write - op;
                        if (op < len) {
                            len -= op;
                            do {
                                EX3_PUP(out) = EX3_PUP(from);
                            } while (--op);
                            from = out - dist;
                            do {
                                EX3_PUP(out) = EX3_PUP(from);
                            } while (--len);
                        }
                    }
                    while (len > 2) {
                        EX3_PUP(out) = EX3_PUP(from);
                        EX3_PUP(out) = EX3_PUP(from);
                        EX3_PUP(out) = EX3_PUP(from);
                        len -= 3;
                    }
                    if (len) {
                        EX3_PUP(out) = EX3_PUP(from);
                        if (len > 1)
                            EX3_PUP(out) = EX3_PUP(from);
                    }
                } else {
                    from = out - dist;
                    do {
                        EX3_PUP(out) = EX3_PUP(from);
                        EX3_PUP(out) = EX3_PUP(from);
                        EX3_PUP(out) = EX3_PUP(from);
                        len -= 3;
                    } while (len > 2);
                    if (len) {
                        EX3_PUP(out) = EX3_PUP(from);
                        if (len > 1)
                            EX3_PUP(out) = EX3_PUP(from);
                    }
                }
            } else if ((op & 64) == 0) {
                this_ = dcode[this_.val + (hold & ((1U << op) - 1))];
                goto dodist;
            } else {
                strm->msg = (char *)lbl_880DFB08;
                state->mode = 27;
                break;
            }
        } else if ((op & 64) == 0) {
            this_ = lcode[this_.val + (hold & ((1U << op) - 1))];
            goto dolen;
        } else if (op & 32) {
            state->mode = 11;
            break;
        } else {
            strm->msg = (char *)lbl_880DFAEC;
            state->mode = 27;
            break;
        }
    } while (in < last && out < end);

    len = bits >> 3;
    in -= len;
    bits -= len << 3;
    hold &= (1U << bits) - 1;

    strm->next_in = in + EX3_OFF;
    strm->next_out = out + EX3_OFF;
    strm->avail_in = (unsigned)(in < last ? 5 + (last - in) : 5 - (in - last));
    strm->avail_out = (unsigned)(out < end ? 257 + (end - out) : 257 - (out - end));
    state->hold = hold;
    state->bits = bits;
}
