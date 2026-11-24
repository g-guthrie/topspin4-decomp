/* Derived from zlib (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX4: zlib 1.2.3 inffast.c inflate_fast. */

typedef void *(*ex4_alloc_func)(void *opaque, unsigned items, unsigned size);
typedef void (*ex4_free_func)(void *opaque, void *address);

struct ex4_inflate_state;

typedef struct ex4_zstream {
    unsigned char *next_in;   /* +0x00 */
    unsigned int avail_in;    /* +0x04 */
    unsigned long total_in;   /* +0x08 */
    unsigned char *next_out;  /* +0x0C */
    unsigned int avail_out;   /* +0x10 */
    unsigned long total_out;  /* +0x14 */
    char *msg;                /* +0x18 */
    struct ex4_inflate_state *state; /* +0x1C */
    ex4_alloc_func zalloc;    /* +0x20 */
    ex4_free_func zfree;      /* +0x24 */
    void *opaque;             /* +0x28 */
    int data_type;            /* +0x2C */
    unsigned long adler;      /* +0x30 */
    unsigned long reserved;   /* +0x34 */
} ex4_zstream;

typedef struct ex4_code {
    unsigned char op;
    unsigned char bits;
    unsigned short val;
} ex4_code;

/* zlib 1.2.3 inflate_state; offsets verified against the machine code. */
typedef struct ex4_inflate_state {
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
    const ex4_code *lencode;       /* +0x4C */
    const ex4_code *distcode;      /* +0x50 */
    unsigned lenbits;              /* +0x54 */
    unsigned distbits;             /* +0x58 */
    unsigned ncode;                /* +0x5C */
    unsigned nlen;                 /* +0x60 */
    unsigned ndist;                /* +0x64 */
    unsigned have;                 /* +0x68 */
    ex4_code *next;                /* +0x6C */
    unsigned short lens[320];      /* +0x70 */
    unsigned short work[288];      /* +0x2F0 */
    ex4_code codes[2048];          /* +0x530 */
} ex4_inflate_state;

extern const char lbl_880DFB20[]; /* "invalid distance too far back" */
extern const char lbl_880DFB08[]; /* "invalid distance code" */
extern const char lbl_880DFAEC[]; /* "invalid literal/length code" */

#define EX4_OFF 1
#define EX4_PUP(a) *++(a)

/* Decode literals and matches in one pass while enough input and output room is available
 * (zlib inflate_fast). Swing_DLL.xex 0x88875C60 */
void ex4_inflate_fast_88875C60(ex4_zstream *strm, unsigned start)
{
    ex4_inflate_state *state;
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
    const ex4_code *lcode;
    const ex4_code *dcode;
    unsigned lmask;
    unsigned dmask;
    ex4_code this_;
    unsigned op;
    unsigned len;
    unsigned dist;
    unsigned char *from;

    state = strm->state;
    in = strm->next_in - EX4_OFF;
    last = in + (strm->avail_in - 5);
    out = strm->next_out - EX4_OFF;
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
            hold += (unsigned long)(EX4_PUP(in)) << bits;
            bits += 8;
            hold += (unsigned long)(EX4_PUP(in)) << bits;
            bits += 8;
        }
        this_ = lcode[hold & lmask];
    dolen:
        op = (unsigned)(this_.bits);
        hold >>= op;
        bits -= op;
        op = (unsigned)(this_.op);
        if (op == 0) {
            EX4_PUP(out) = (unsigned char)(this_.val);
        } else if (op & 16) {
            len = (unsigned)(this_.val);
            op &= 15;
            if (op) {
                if (bits < op) {
                    hold += (unsigned long)(EX4_PUP(in)) << bits;
                    bits += 8;
                }
                len += (unsigned)hold & ((1U << op) - 1);
                hold >>= op;
                bits -= op;
            }
            if (bits < 15) {
                hold += (unsigned long)(EX4_PUP(in)) << bits;
                bits += 8;
                hold += (unsigned long)(EX4_PUP(in)) << bits;
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
                    hold += (unsigned long)(EX4_PUP(in)) << bits;
                    bits += 8;
                    if (bits < op) {
                        hold += (unsigned long)(EX4_PUP(in)) << bits;
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
                    from = window - EX4_OFF;
                    if (write == 0) {
                        from += wsize - op;
                        if (op < len) {
                            len -= op;
                            do {
                                EX4_PUP(out) = EX4_PUP(from);
                            } while (--op);
                            from = out - dist;
                        }
                    } else if (write < op) {
                        from += wsize + write - op;
                        op -= write;
                        if (op < len) {
                            len -= op;
                            do {
                                EX4_PUP(out) = EX4_PUP(from);
                            } while (--op);
                            from = window - EX4_OFF;
                            if (write < len) {
                                op = write;
                                len -= op;
                                do {
                                    EX4_PUP(out) = EX4_PUP(from);
                                } while (--op);
                                from = out - dist;
                            }
                        }
                    } else {
                        from += write - op;
                        if (op < len) {
                            len -= op;
                            do {
                                EX4_PUP(out) = EX4_PUP(from);
                            } while (--op);
                            from = out - dist;
                        }
                    }
                    while (len > 2) {
                        EX4_PUP(out) = EX4_PUP(from);
                        EX4_PUP(out) = EX4_PUP(from);
                        EX4_PUP(out) = EX4_PUP(from);
                        len -= 3;
                    }
                    if (len) {
                        EX4_PUP(out) = EX4_PUP(from);
                        if (len > 1)
                            EX4_PUP(out) = EX4_PUP(from);
                    }
                } else {
                    from = out - dist;
                    do {
                        EX4_PUP(out) = EX4_PUP(from);
                        EX4_PUP(out) = EX4_PUP(from);
                        EX4_PUP(out) = EX4_PUP(from);
                        len -= 3;
                    } while (len > 2);
                    if (len) {
                        EX4_PUP(out) = EX4_PUP(from);
                        if (len > 1)
                            EX4_PUP(out) = EX4_PUP(from);
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

    strm->next_in = in + EX4_OFF;
    strm->next_out = out + EX4_OFF;
    strm->avail_in = (unsigned)(in < last ? 5 + (last - in) : 5 - (in - last));
    strm->avail_out = (unsigned)(out < end ? 257 + (end - out) : 257 - (out - end));
    state->hold = hold;
    state->bits = bits;
}
