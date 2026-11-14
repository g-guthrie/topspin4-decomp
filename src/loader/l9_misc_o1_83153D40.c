/* Loader_DLL.xex 0x83141BD8-0x8317AFEC, executable version 0.0.0.3. */

#ifndef _MSC_VER
#define __forceinline inline
#endif

typedef struct ts4l_ptr_registry {
    char pad[0x40];
    unsigned **items;
    unsigned short count;
} ts4l_ptr_registry;

/* Find the entry whose pointed-to value equals *key; returns index or -1. */
int ts4l_registry_find_83153D40(ts4l_ptr_registry *r, unsigned *key)
{
    int i;
    for (i = 0; i < r->count; i++) {
        if (*key == *r->items[i]) {
            return i;
        }
    }
    return -1;
}

/* Extract a 15-bit field at an arbitrary bit offset of a byte stream. */
unsigned ts4l_bitstream_get15_8317AFA0(unsigned char *p, unsigned bit)
{
    unsigned char *q = p + (bit >> 3);
    unsigned sh = bit & 7;
    unsigned v;
    if (sh < 2) {
        v = ((unsigned)q[0] << 8) | q[1];
        sh = 1 - sh;
    } else {
        v = ((((unsigned)q[0] << 8) | q[1]) << 8) | q[2];
        sh = 9 - sh;
    }
    return (v >> sh) & 0x7fff;
}

/* Test one bit of a tagged value: the low 3 bits of the first byte give the
   storage width (1, 2 or 4 bytes) of the payload that follows. */
unsigned ts4l_tagged_test_bit_8313D170(unsigned char *p, unsigned bit)
{
    switch (p[0] & 7) {
    case 1:
        return *(unsigned char *)(p + 1) & (1u << bit);
    case 2:
        return *(unsigned short *)(p + 1) & (1u << bit);
    case 4:
        return *(unsigned *)(p + 1) & (1u << bit);
    default:
        return 0;
    }
}

/* Round a value to a multiple of align: mode 1 rounds up, mode 2 to nearest. */
int ts4l_align_value_8316E6E0(int v, int a, int mode)
{
    if (mode == 1) {
        v = v + a - 1;
    }
    if (mode == 2) {
        v = v + a / 2;
    }
    return v - v % a;
}

typedef struct ts4l_ring_counter {
    int pad;
    int capacity;
    int count;
    int head;
} ts4l_ring_counter;

/* Pop one slot from a ring counter; returns 1 when it was empty, else 0. */
int ts4l_ring_pop_831226F0(ts4l_ring_counter *r)
{
    int empty = 1;
    if (r->count > 0) {
        r->count--;
        r->head = (r->head + 1) % r->capacity;
        empty = 0;
    }
    return empty;
}

/* Map a sample-rate-like constant to a small table index (0 when unknown). */
int ts4l_rate_index_83173C30(int unused, unsigned rate)
{
    (void)unused;
    if (rate == 0x566d) return 3;
    if (rate == 0xab63) return 6;
    if (rate == 0xbb80) return 7;
    if (rate == 0x2bf2) return 1;
    if (rate == 0x7dfa) return 5;
    if (rate == 0x5dc0) return 4;
    if (rate == 0x3efd) return 2;
    return rate != 0x203a ? 8 : 0;
}

typedef struct ts4l_keyed_item {
    unsigned key;
    unsigned value;
} ts4l_keyed_item;

typedef struct ts4l_sorted_table {
    int count;
    int reserved;
    ts4l_keyed_item **items;
} ts4l_sorted_table;

/* Binary search of a key-sorted pointer table; returns the value (0 if
   absent) and stores the found index (or -1) when out is non-null. */
unsigned ts4l_sorted_table_lookup_83141BD8(ts4l_sorted_table *v, unsigned key, int *out)
{
    int lo = 0, hi = v->count - 1, mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (key == v->items[mid]->key) {
            if (out) *out = mid;
            return v->items[mid]->value;
        }
        if (key < v->items[mid]->key) hi = mid - 1; else lo = mid + 1;
    }
    if (out) *out = -1;
    return 0;
}

typedef struct ts4l_stat_entry {
    unsigned short w, z;
} ts4l_stat_entry;

typedef struct ts4l_stat_block {
    char pad[0x1c];
    unsigned char flag;
    char pad2[0x8c - 0x1d];
    ts4l_stat_entry a[7];
    ts4l_stat_entry b[0x79];
    ts4l_stat_entry c[0x80];
} ts4l_stat_block;

/* Compare weighted sums of three 16-bit histograms and set a flag byte. */
void ts4l_stat_block_update_flag_8316B0D0(ts4l_stat_block *q)
{
    unsigned s2 = 0, s1 = 0;
    int i;
    for (i = 0; i < 7; i++) s1 += q->a[i].w;
    for (i = 0; i < 0x79; i++) s2 += q->b[i].w;
    for (i = 0; i < 0x80; i++) s1 += q->c[i].w;
    q->flag = (s2 >> 2) >= s1;
}

typedef struct ts4l_bit_writer {
    char p0[8];
    unsigned char *buf;
    char p1[8];
    int pos;
    char p2[0x16b0 - 0x18];
    unsigned short bits;
    unsigned short pad;
    int nbits;
} ts4l_bit_writer;

static __forceinline void ts4l_bit_writer_put(ts4l_bit_writer *w, unsigned char c)
{
    w->buf[w->pos++] = c;
}

/* Flush the partial bit accumulator (up to 16 bits) to the output buffer. */
void ts4l_bit_writer_flush_8316B1F0(ts4l_bit_writer *w)
{
    if (w->nbits > 8) {
        w->buf[w->pos] = (unsigned char)w->bits;
        w->buf[++w->pos] = (unsigned char)(w->bits >> 8);
        w->pos++;
    } else if (w->nbits > 0) {
        w->buf[w->pos] = (unsigned char)w->bits;
        w->pos++;
    }
    w->bits = 0;
    w->nbits = 0;
}

/* Emit whole bytes from the accumulator once 8 or 16 bits are pending. */
void ts4l_bit_writer_drain_8316B160(ts4l_bit_writer *w)
{
    if (w->nbits == 16) {
        ts4l_bit_writer_put(w, (unsigned char)w->bits);
        ts4l_bit_writer_put(w, (unsigned char)(w->bits >> 8));
        w->bits = 0;
        w->nbits = 0;
    } else if (w->nbits >= 8) {
        ts4l_bit_writer_put(w, (unsigned char)w->bits);
        w->bits = (unsigned char)(w->bits >> 8);
        w->nbits -= 8;
    }
}

typedef struct ts4l_code_entry {
    unsigned short key;
    unsigned char a;
    unsigned char b;
} ts4l_code_entry;

extern ts4l_code_entry lbl_83527E18[];

/* Binary search of a 147-entry sorted code table; writes the two payload bytes. */
void ts4l_code_table_lookup_831541E0(unsigned short key, unsigned char *a, unsigned char *b)
{
    int lo = 0, hi = 0x92, mid;
    *a = 0;
    *b = 0;
    if (key == 0) return;
    do {
        mid = (lo + hi) / 2;
        if (lbl_83527E18[mid].key == key) {
            *a = lbl_83527E18[mid].a;
            *b = lbl_83527E18[mid].b;
            return;
        }
        if (lbl_83527E18[mid].key < key) lo = mid + 1;
        else if (lbl_83527E18[mid].key > key) hi = mid - 1;
    } while (lo <= hi);
}

typedef struct ts4l_range_acc {
    char p[0x14];
    int count;
    char q[0xc];
    int sum_a;
    int sum_b;
} ts4l_range_acc;

typedef struct ts4l_range_owner {
    char p[0x34];
    ts4l_range_acc *acc;
    char q[0xdc - 0x38];
    int delta_a;
    int delta_b;
} ts4l_range_owner;

/* Add (dir == 0) or remove the owner's deltas from its accumulator. */
void ts4l_range_acc_update_83176DC0(ts4l_range_owner *a, int dir)
{
    if (dir == 0) {
        a->acc->count++;
        a->acc->sum_a += a->delta_a;
        a->acc->sum_b += a->delta_b;
    } else {
        a->acc->count--;
        a->acc->sum_a -= a->delta_a;
        a->acc->sum_b -= a->delta_b;
    }
}

typedef struct ts4l_seek_state {
    unsigned w0;
    unsigned w4;
    unsigned size;
    unsigned pos;
} ts4l_seek_state;

/* Stream seek: flags 1 = absolute, 2 = relative to the current position,
   4 = relative to the end. Returns 0 or an invalid-argument status. */
int ts4l_stream_seek_831477C0(ts4l_seek_state *s, unsigned flags, int off)
{
    int pos = off;
    if (!(flags & 1)) {
        if (flags & 2) pos = s->pos + off;
        else if (flags & 4) pos = s->size - off - 1;
        else return 0x80070057;
    }
    if (pos >= 0 && pos < (int)s->size) {
        s->pos = pos;
        return 0;
    }
    return 0x80070057;
}

int fn_83163BD8();

typedef struct ts4l_short_table {
    char p[0x130];
    unsigned char *tab;
    char q[0x3c];
    unsigned short n;
} ts4l_short_table;

/* Look up an entry (clamped to the table size) and return its big-endian
   16-bit value, sign-extended. */
short ts4l_short_table_lookup_83163D30(ts4l_short_table *t)
{
    int i = fn_83163BD8(t);
    unsigned char *e;
    int v;
    if (i >= t->n) i = t->n - 1;
    e = t->tab + i * 4;
    v = (e[0] << 8) | e[1];
    return (short)v;
}

int fn_83177CD8();

typedef struct ts4l_item_scan {
    char p[0x1c0];
    unsigned n;
    char q[0x14];
    void *obj;
} ts4l_item_scan;

/* Returns 1 as soon as the per-index callback reports failure, else 0. */
int ts4l_item_scan_any_failed_8317AEE8(ts4l_item_scan *s)
{
    unsigned i;
    for (i = 0; i < s->n; i++) {
        if (fn_83177CD8(s->obj, i) == 0) return 1;
    }
    return 0;
}
