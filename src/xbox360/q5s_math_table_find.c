/*
 * 0x88656048: finds a byte in one row of a self-relative table. When start < 20, the source at +0x1C
 * reports ready (vtable +0x30) and the owner's key (+0x78) equals key, it fetches the table (vtable
 * +0x48, arg 0); for row idx (< 4 and < table count at +0x4C) it scans bytes [start, 20] of the row's
 * self-relative byte array and returns the first index holding b. Returns 0x33 when not found or not
 * available.
 *
 * Table layout: +0x48 holds a self-relative offset to an array of 0x1C-byte rows; each row starts
 * with a self-relative offset to its bytes (rel_get: address of the offset field + its value).
 *
 * Codegen: the result variable with a break (not `return i`) keeps 0x33 in r25 from the start. The
 * row's byte array written as a chain expression inside the loop (`rel_get(&e->bytes_off)[i]`) gives
 * the base-first `lbzx rD, rBase, rI`; a named `bytes` local gives the index-first order.
 */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Q5sTfRow {
    int bytes_off; /* +0x00 self-relative offset to the row bytes */
    char pad04[0x18];
} Q5sTfRow;

typedef struct Q5sTfTable {
    char pad00[0x48];
    int rows_off; /* +0x48 self-relative offset to the rows */
    u32 count;    /* +0x4C */
} Q5sTfTable;

struct Q5sTfSrc;
typedef struct Q5sTfSrcVt {
    char pad00[0x30];
    u8 (*ready)(struct Q5sTfSrc *s); /* +0x30 */
    char pad34[0x48 - 0x34];
    Q5sTfTable *(*table)(struct Q5sTfSrc *s, int a); /* +0x48 */
} Q5sTfSrcVt;

typedef struct Q5sTfSrc {
    Q5sTfSrcVt *vt;
} Q5sTfSrc;

typedef struct Q5sTfOwner {
    char pad00[0x1C];
    Q5sTfSrc src; /* +0x1C */
    char pad20[0x78 - 0x20];
    u32 key; /* +0x78 */
} Q5sTfOwner;

static __inline char *q5s_rel_get(int *p) { return (char *)p + *p; }

int ts4_table_find_byte_88656048(Q5sTfOwner *self, int idx, u8 b, int start, u32 key)
{
    int ret = 0x33;
    if (start < 20) {
        Q5sTfSrc *s = &self->src;
        if (s->vt->ready(s) && self->key == key) {
            Q5sTfTable *t = s->vt->table(s, 0);
            if (idx < 4 && (u32)idx < t->count) {
                Q5sTfRow *e = (Q5sTfRow *)q5s_rel_get(&t->rows_off) + idx;
                int i;
                for (i = start; i <= 20; i++) {
                    if (b == (u8)q5s_rel_get(&e->bytes_off)[i]) {
                        ret = i;
                        break;
                    }
                }
            }
        }
    }
    return ret;
}
