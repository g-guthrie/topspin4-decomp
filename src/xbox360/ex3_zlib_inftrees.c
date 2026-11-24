/* Derived from zlib (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: zlib 1.2.3 inftrees.c (inflate_table). */

typedef struct ex3_code {
    unsigned char op;
    unsigned char bits;
    unsigned short val;
} ex3_code;

#define EX3_MAXBITS 15

/* Length and distance base/extra tables. They are statics of the original function, so the compiler reaches
 * them from one base register (the last (distance extra bits) table). The contents below are placeholders: only
 * sizes and order matter for the code generation (the real data lives in the game image at 0x880CA838..). */
#ifdef _MSC_VER
#define EX3_UNUSED_DATA
#else
#define EX3_UNUSED_DATA __attribute__((unused))
#endif
static const unsigned char ex3_layout_first[8] EX3_UNUSED_DATA = {1}; /* shifts the base-register choice to the last table */
static const unsigned short ex3_lbase[32] = {1};
static const unsigned short ex3_lext[32] = {1};
static const unsigned short ex3_dbase[32] = {1};
static const unsigned short lbl_880CA878[32] = {1}; /* dext */

/* Build the decoding tables for a set of Huffman code lengths (zlib inflate_table).
 * type: 0 CODES, 1 LENS, 2 DISTS. Returns 0, -1 (bad lengths) or 1 (table too big).
 * Swing_DLL.xex 0x88873AB0 */
int ex3_inflate_table_88873AB0(int type, unsigned short *lens, unsigned codes, ex3_code **table, unsigned *bits,
                               unsigned short *work)
{
    unsigned len;
    unsigned sym;
    unsigned min, max;
    unsigned root;
    unsigned curr;
    unsigned drop;
    int left;
    unsigned used;
    unsigned huff;
    unsigned incr;
    unsigned fill;
    unsigned low;
    unsigned mask;
    ex3_code this_;
    ex3_code *next;
    const unsigned short *base;
    const unsigned short *extra;
    int match;
    unsigned short count[EX3_MAXBITS + 1];
    unsigned short offs[EX3_MAXBITS + 1];

    for (len = 0; len <= EX3_MAXBITS; len++)
        count[len] = 0;
    for (sym = 0; sym < codes; sym++)
        count[lens[sym]]++;

    root = *bits;
    for (max = EX3_MAXBITS; max >= 1; max--)
        if (count[max] != 0)
            break;
    if (root > max)
        root = max;
    if (max == 0) {
        this_.op = (unsigned char)64;
        this_.bits = (unsigned char)1;
        this_.val = (unsigned short)0;
        *(*table)++ = this_;
        *(*table)++ = this_;
        *bits = 1;
        return 0;
    }
    for (min = 1; min <= EX3_MAXBITS; min++)
        if (count[min] != 0)
            break;
    if (root < min)
        root = min;

    left = 1;
    for (len = 1; len <= EX3_MAXBITS; len++) {
        left <<= 1;
        left -= count[len];
        if (left < 0)
            return -1;
    }
    if (left > 0 && (type == 0 || max != 1))
        return -1;

    offs[1] = 0;
    for (len = 1; len < EX3_MAXBITS; len++)
        offs[len + 1] = offs[len] + count[len];

    for (sym = 0; sym < codes; sym++)
        if (lens[sym] != 0)
            work[offs[lens[sym]]++] = (unsigned short)sym;

    switch (type) {
    case 0:
        base = extra = work;
        match = 19;
        break;
    case 1:
        base = ex3_lbase;
        base -= 257;
        extra = ex3_lext;
        extra -= 257;
        match = 256;
        break;
    default:
        base = ex3_dbase;
        extra = lbl_880CA878;
        match = -1;
    }

    huff = 0;
    sym = 0;
    len = min;
    next = *table;
    curr = root;
    drop = 0;
    low = (unsigned)(-1);
    used = 1U << root;
    mask = used - 1;

    if (type == 1 && used >= 2048 - 592)
        return 1;

    for (;;) {
        this_.bits = (unsigned char)(len - drop);
        if ((int)(work[sym]) < match) {
            this_.op = (unsigned char)0;
            this_.val = work[sym];
        } else if ((int)(work[sym]) > match) {
            this_.op = (unsigned char)(extra[work[sym]]);
            this_.val = base[work[sym]];
        } else {
            this_.op = (unsigned char)(32 + 64);
            this_.val = 0;
        }

        incr = 1U << (len - drop);
        fill = 1U << curr;
        min = fill;
        do {
            fill -= incr;
            next[(huff >> drop) + fill] = this_;
        } while (fill != 0);

        incr = 1U << (len - 1);
        while (huff & incr)
            incr >>= 1;
        if (incr != 0) {
            huff &= incr - 1;
            huff += incr;
        } else
            huff = 0;

        sym++;
        if (--(count[len]) == 0) {
            if (len == max)
                break;
            len = lens[work[sym]];
        }

        if (len > root && (huff & mask) != low) {
            if (drop == 0)
                drop = root;

            next += min;

            curr = len - drop;
            left = (int)(1 << curr);
            while (curr + drop < max) {
                left -= count[curr + drop];
                if (left <= 0)
                    break;
                curr++;
                left <<= 1;
            }

            used += 1U << curr;
            if (type == 1 && used >= 2048 - 592)
                return 1;

            low = huff & mask;
            (*table)[low].op = (unsigned char)curr;
            (*table)[low].bits = (unsigned char)root;
            (*table)[low].val = (unsigned short)(next - *table);
        }
    }

    this_.op = (unsigned char)64;
    this_.bits = (unsigned char)(len - drop);
    this_.val = (unsigned short)0;
    while (huff != 0) {
        if (drop != 0 && (huff & mask) != low) {
            drop = 0;
            len = root;
            next = *table;
            this_.bits = (unsigned char)len;
        }

        next[huff >> drop] = this_;

        incr = 1U << (len - 1);
        while (huff & incr)
            incr >>= 1;
        if (incr != 0) {
            huff &= incr - 1;
            huff += incr;
        } else
            huff = 0;
    }

    *table += used;
    *bits = root;
    return 0;
}
