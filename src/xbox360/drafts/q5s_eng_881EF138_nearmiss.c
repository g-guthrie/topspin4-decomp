/* nearmiss: 6 off (LTCG, NO /Oc because the modulo keeps twllei; pp1_pool_primer.c).
 * Only i (target r10) and buckets (target r9) registers are swapped. The sister iterator-next functions
 * 881ED6E8/881ED760 match with the same loop (src/xbox360/q5s_eng_hashtab_iter.c); here the result is returned in r3
 * and nbuckets is loaded before the hash. Tried: if/else, for/while forms, int index, hash/nbuckets locals,
 * HPos inline helper, separate result local. Blocker: register-swap family (regalloc.md R3), no source lever found. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct HNode HNode;
typedef struct HTab { u8 pad0[0x14]; HNode **buckets; u8 pad18[4]; u32 nbuckets; } HTab;
typedef struct HIter { u32 w0; u32 w4; HNode *node; u32 hash; } HIter;
HNode *ts4_htab_iter_first_881EF138(HTab *t, HIter *it)
{
    HNode *r = it->node;
    if (r == 0) {
        u32 i = it->hash % t->nbuckets + 1;
        do { if (i >= t->nbuckets) break; if (t->buckets[i] != 0) r = t->buckets[i]; i++; } while (r == 0);
    }
    return r;
}
