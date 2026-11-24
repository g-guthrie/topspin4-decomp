/* 0x882BF4D8 (Swing_DLL.xex, /O1): constructor of a 16-byte-entry buffer over an even-aligned index range.
 * Base init via fn_882B6B28; range is [first & ~1, (last + 1) & ~1); the entry block comes from the
 * u32-sized allocator; the stride pair (0/8 or 8/0) depends on the descriptor format code. */
typedef struct Ts4RangeDesc { int p0; unsigned int fmt; } Ts4RangeDesc;

typedef struct Ts4RangeBuffer {
    const void *vt;
    char pad0[0x3c - 4];
    unsigned int first;          /* 0x3c */
    char pad1[0x44 - 0x40];
    unsigned int last;           /* 0x44 */
    char pad2[0x80 - 0x48];
    void *entries;               /* 0x80: 16 bytes per index */
    unsigned int lo;             /* 0x84 */
    int c88;
    unsigned int hi;             /* 0x8c */
    int c90, c94, c98;
    unsigned int count;          /* 0x9c */
    int ca0;
    int ok;                      /* 0xa4 */
    int offA;                    /* 0xa8 */
    int offB;                    /* 0xac */
} Ts4RangeBuffer;

extern char lbl_880023FC[];
void fn_882B6B28(Ts4RangeBuffer *t, Ts4RangeDesc *d, int a, int b);
void *ts4_if_get_u32_lbl_88D45B38_88886180(unsigned int size);

/* Checked allocation: null on failure. Its own null test is what puts the caller's test on cr6. */
static void *ts4_range_alloc(unsigned int size)
{
    void *p = ts4_if_get_u32_lbl_88D45B38_88886180(size);
    if (!p)
        return 0;
    return p;
}

Ts4RangeBuffer *ts4_range_buffer_ctor_882BF4D8(Ts4RangeBuffer *t, Ts4RangeDesc *d)
{
    unsigned int hi, n;
    fn_882B6B28(t, d, 0, 1);
    hi = (t->last + 1) & ~1u;
    t->vt = lbl_880023FC;
    t->c88 = 0;
    t->hi = hi;
    t->c94 = 0;
    t->c90 = 0;
    t->c98 = 0;
    t->ca0 = 0;
    t->ok = 1;
    t->lo = t->first & ~1u;
    n = hi - t->lo;
    t->count = n;
    t->entries = ts4_range_alloc(n <= 0x0fffffff ? n << 4 : 0xffffffff);
    if (!t->entries)
        t->ok = 0;
    switch (d->fmt) {
    case 0x1828004B:
    case 0x1A20004B:
        t->offA = 0;
        t->offB = 8;
        break;
    case 0x1828004C:
    case 0x1A20004C:
        t->offB = 0;
        t->offA = 8;
        break;
    }
    return t;
}
