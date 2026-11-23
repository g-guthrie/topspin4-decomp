/* nearmiss: 34 off (plain), size 0x7c vs 0x88; the target keeps a and the table offset in saved r31/r30 inside a leaf
 * and moves def to r3 at entry; every loop/helper/combo form gives the same leaner body (perm_auto best 34 after 114). */
/* 0x888D82E0: binary search over a self-relative sorted {u32 key; u16 val} array (8-byte entries, {off, count} header):
 * returns (short)(def - val) for the matching key, else def. */
typedef unsigned int u32; typedef unsigned short u16;
typedef struct E { u32 key; u16 val; } E;
typedef struct A { int off; int count; } A;
short ts4_rel_lookup_delta_888D82E0(A *a, const u32 *key, short def)
{
    int lo = 0, hi = a->count - 1;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        E *e = (E *)((char *)a + (mid * 8 + a->off));
        if (e->key == *key) return (short)(def - e->val);
        if (e->key < *key) lo = mid + 1; else hi = mid - 1;
    }
    return def;
}
