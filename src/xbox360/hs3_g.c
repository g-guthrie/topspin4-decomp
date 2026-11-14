/* HS3 hand-matched: lookups in relative-offset tables (0x887..0x88A). */
#ifdef _MSC_VER
#define HS3_INLINE __forceinline
#else
#define HS3_INLINE static inline
#endif

/* Header of a self-relative array: entries start at (int)entries_off bytes from the header. */
struct HS3RelHdr {
    volatile int entries_off; /* -1 when empty */
    unsigned count;
};

HS3_INLINE char *hs3_rel_begin(struct HS3RelHdr *h)
{
    int off = h->entries_off;
    char *p = 0;
    if (off != -1)
        p = (char *)h + off;
    return p;
}

HS3_INLINE char *hs3_rel_end(struct HS3RelHdr *h, unsigned stride)
{
    int off = h->entries_off;
    char *p = 0;
    if (off != -1)
        p = (char *)h + off + h->count * stride;
    return p;
}

struct HS3E1C { unsigned key; char pad[0x18]; };
struct HS3Blk154 { char pad[0x154]; struct HS3RelHdr hdr; };
struct HS3OwnerA8 { char pad[0xa8]; struct HS3Blk154 *blk; };
struct HS3E14 { char pad[0xc]; unsigned key; char pad2[4]; };
struct HS3Blk10c { char pad[0x10c]; struct HS3RelHdr hdr; };
struct HS3Owner30 { char pad[0x30]; struct HS3Blk10c *blk; };
struct HS3E34 { char pad[0x18]; unsigned key; char pad2[0x34 - 0x1c]; };
struct HS3Blk20c { char pad[0x20c]; struct HS3RelHdr hdr; };
struct HS3OwnerA8b { char pad[0xa8]; struct HS3Blk20c *blk; };
struct HS3E8 { unsigned key; unsigned value; };
struct HS3E18 { unsigned key; char pad[0x14]; };
struct HS3Holder0c { char pad[0xc]; struct HS3RelHdr hdr; };
struct HS3Owner10c { char pad[0x10c]; struct HS3Holder0c *holder; };
struct HS3Owner10cb { char pad[0x10c]; struct HS3RelHdr *tbl; };

/* Find the 0x1c-byte entry whose first word equals `key`, or 0. */
struct HS3E1C *ts4_reltbl_find_e1c_by_key_887CED68(struct HS3OwnerA8 *owner, unsigned key)
{
    struct HS3RelHdr *h = &owner->blk->hdr;
    struct HS3E1C *it = (struct HS3E1C *)hs3_rel_begin(h);
    struct HS3E1C *end = (struct HS3E1C *)hs3_rel_end(h, 0x1c);
    for (; it != end; it++) {
        if (key == it->key)
            return it;
    }
    return 0;
}

/* Find the 0x14-byte entry whose word at +0xc equals *key, or 0. */
struct HS3E14 *ts4_reltbl_find_e14_by_key_887CE4D8(struct HS3Owner30 *owner, unsigned *key)
{
    struct HS3RelHdr *h = &owner->blk->hdr;
    struct HS3E14 *it = (struct HS3E14 *)hs3_rel_begin(h);
    struct HS3E14 *end = (struct HS3E14 *)hs3_rel_end(h, 0x14);
    for (; it != end; it++) {
        if (it->key == *key)
            return it;
    }
    return 0;
}

/* Find the 0x34-byte entry whose word at +0x18 equals *key, or 0. */
struct HS3E34 *ts4_reltbl_find_e34_by_key_887CE950(struct HS3OwnerA8b *owner, unsigned *key)
{
    struct HS3RelHdr *h = &owner->blk->hdr;
    struct HS3E34 *it = (struct HS3E34 *)hs3_rel_begin(h);
    struct HS3E34 *end = (struct HS3E34 *)hs3_rel_end(h, 0x34);
    for (; it != end; it++) {
        if (*key == it->key)
            return it;
    }
    return 0;
}

/* Find the 8-byte entry whose first word equals `key` in the table behind owner+0x10c, or 0. */
struct HS3E8 *ts4_reltbl_find_e8_by_key_8870DC30(struct HS3Owner10c *owner, unsigned key)
{
    struct HS3RelHdr *h;
    struct HS3E8 *it, *end;
    if (owner->holder) {
        h = &owner->holder->hdr;
        it = (struct HS3E8 *)hs3_rel_begin(h);
        end = (struct HS3E8 *)hs3_rel_end(h, 8);
        for (; it != end; it++) {
            if (key == it->key)
                return it;
        }
    }
    return 0;
}

/* Find the 0x18-byte entry whose first word equals `key` in the table behind owner+0x10c, or 0. */
struct HS3E18 *ts4_reltbl_find_e18_by_key_8870DCA0(struct HS3Owner10cb *owner, unsigned key)
{
    struct HS3RelHdr *h;
    struct HS3E18 *it, *end;
    if (owner->tbl) {
        h = owner->tbl;
        it = (struct HS3E18 *)hs3_rel_begin(h);
        end = (struct HS3E18 *)hs3_rel_end(h, 0x18);
        for (; it != end; it++) {
            if (key == it->key)
                return it;
        }
    }
    return 0;
}

struct HS3E8F { unsigned key; float value; };
struct HS3Owner30b { char pad[0x30]; struct HS3RelHdr *tbl; };
extern float g_ts4_script_constants[];

/* Float value for *key in the owner's relative table, or the default script constant. */
float ts4_reltbl_get_float_by_key_887CE378(struct HS3Owner30b *owner, unsigned *key)
{
    struct HS3RelHdr *h = owner->tbl;
    struct HS3E8F *it = (struct HS3E8F *)hs3_rel_begin(h);
    struct HS3E8F *end = (struct HS3E8F *)hs3_rel_end(h, 8);
    for (; it != end; it++) {
        if (it->key == *key)
            return it->value;
    }
    return g_ts4_script_constants[0];
}

struct HS3E8R { unsigned value; unsigned key; };
struct HS3Obj20 { char pad[0x20]; struct HS3RelHdr *tbl; };
struct HS3Globals27c { char pad[0x27c]; unsigned default_value; };
extern struct HS3Globals27c *lbl_88D45B1C;

/* Write the value whose key (second word) equals *key from the object's relative table, else the global default. */
void ts4_reltbl_get_value_by_key2_88926C10(unsigned *out, struct HS3Obj20 *obj, int unused, unsigned *key)
{
    struct HS3RelHdr *h = obj->tbl;
    struct HS3E8R *begin = (struct HS3E8R *)hs3_rel_begin(h);
    struct HS3E8R *end = (struct HS3E8R *)hs3_rel_end(h, 8);
    struct HS3E8R *it = begin;
    (void)unused;
    if (begin != end) {
        for (; it != end; it++) {
            if (*key == it->key) {
                *out = it->value;
                return;
            }
        }
    }
    *out = lbl_88D45B1C->default_value;
}

struct HS3Blk0c { char pad[0xc]; struct HS3RelHdr hdr; };
struct HS3Owner20 { char pad[0x20]; struct HS3Blk0c *blk; };
struct HS3E40 { char pad[0x30]; unsigned key; char pad2[0x40 - 0x34]; };

/* Binary search the 64-byte entries (sorted by key at +0x30) in the owner's relative table. */
struct HS3E40 *ts4_reltbl_bsearch_e40_88928300(struct HS3Owner20 *owner, unsigned key)
{
    struct HS3RelHdr *h = &owner->blk->hdr;
    struct HS3E40 *result = 0;
    int lo = 0;
    int hi = (int)h->count - 1;
    if (hi >= 0) {
        int off = h->entries_off;
        do {
            int mid = (hi + lo) / 2;
            struct HS3E40 *e = (struct HS3E40 *)((char *)h + (off + mid * 0x40));
            if (e->key == key) {
                result = e;
                break;
            }
            if (e->key < key)
                lo = mid + 1;
            else
                hi = mid - 1;
        } while (lo <= hi);
    }
    return result;
}

struct HS3OwnerA8t { char pad[0xa8]; struct HS3RelHdr *tbl; };
struct HS3Blk700 { char pad[0x700]; struct HS3RelHdr hdr; };
struct HS3Blk1e8 { char pad[0x1e8]; struct HS3RelHdr hdr; };
struct HS3OwnerA8c { char pad[0xa8]; struct HS3Blk1e8 *blk; };
struct HS3Blk1c0 { char pad[0x1c0]; struct HS3RelHdr hdr; };
struct HS3OwnerA8d { char pad[0xa8]; struct HS3Blk1c0 *blk; };
struct HS3Owner2c { char pad[0x2c]; struct HS3Blk700 *blk; };
struct HS3E8B { unsigned key; unsigned char value; char pad[3]; };
struct HS3E4C { char pad[0x30]; unsigned key; char pad2[0x4c - 0x34]; };
struct HS3EB4 {
    char pad[0x64];
    int a64;
    int a68;
    char pad2[0x75 - 0x6c];
    unsigned char flag75;
    char pad3[0xb4 - 0x76];
};

/* Float value for *key in the table at owner+0xa8, or the default script constant. */
float ts4_reltbl_get_float_by_key_a8_887CF0A8(struct HS3OwnerA8t *owner, unsigned *key)
{
    struct HS3RelHdr *h = owner->tbl;
    struct HS3E8F *it = (struct HS3E8F *)hs3_rel_begin(h);
    struct HS3E8F *end = (struct HS3E8F *)hs3_rel_end(h, 8);
    for (; it != end; it++) {
        if (it->key == *key)
            return it->value;
    }
    return g_ts4_script_constants[0];
}

/* Byte value for *key in the table at owner+0x2c, or 0. */
unsigned char ts4_reltbl_get_byte_by_key_2c_887D2430(struct HS3Owner2c *owner, unsigned *key)
{
    struct HS3RelHdr *h = &owner->blk->hdr;
    struct HS3E8B *it = (struct HS3E8B *)hs3_rel_begin(h);
    struct HS3E8B *end = (struct HS3E8B *)hs3_rel_end(h, 8);
    for (; it != end; it++) {
        if (it->key == *key)
            return it->value;
    }
    return 0;
}

/* Find the 8-byte entry for *key in the table at owner+0x2c, or 0. */
struct HS3E8 *ts4_reltbl_find_e8_by_key_2c_887D24A0(struct HS3Owner2c *owner, unsigned *key)
{
    struct HS3RelHdr *h = &owner->blk->hdr;
    struct HS3E8 *it = (struct HS3E8 *)hs3_rel_begin(h);
    struct HS3E8 *end = (struct HS3E8 *)hs3_rel_end(h, 8);
    for (; it != end; it++) {
        if (it->key == *key)
            return it;
    }
    return 0;
}

/* Find the 0x4c-byte entry whose +0x30 word equals *key (non-zero) in the table at owner+0xa8. */
struct HS3E4C *ts4_reltbl_find_e4c_by_nonzero_key_887D0650(struct HS3OwnerA8c *owner, unsigned *key)
{
    unsigned k = *key;
    if (k) {
        struct HS3RelHdr *h = &owner->blk->hdr;
        struct HS3E4C *it = (struct HS3E4C *)hs3_rel_begin(h);
        struct HS3E4C *end = (struct HS3E4C *)hs3_rel_end(h, 0x4c);
        for (; it != end; it++) {
            if (k == it->key)
                return it;
        }
    }
    return 0;
}

/* Find the active 0xb4-byte entry whose +0x64/+0x68 words equal (a, b) in the table at owner+0xa8. */
struct HS3EB4 *ts4_reltbl_find_eb4_active_pair_887D05D0(struct HS3OwnerA8d *owner, int a, int b)
{
    struct HS3RelHdr *h = &owner->blk->hdr;
    struct HS3EB4 *it = (struct HS3EB4 *)hs3_rel_begin(h);
    struct HS3EB4 *end = (struct HS3EB4 *)hs3_rel_end(h, 0xb4);
    for (; it != end; it++) {
        if (it->flag75 && it->a64 == a && it->a68 == b)
            return it;
    }
    return 0;
}
