/* nearmiss: 6 off (LTCG, NO /Oc (twllei-free but checked without); pp1_pool_primer.c). Hash table begin(): out pointer r3,
 * table r4. Only n (target r9) and buckets (target r8) registers are swapped. A C++ member version
 * (?begin@HTab@@QAA?AUHPos@@XZ) gives the same swap. Blocker: register-swap family (regalloc.md R3), no lever found. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct HNode HNode;
typedef struct HTab { u8 pad0[0x14]; HNode **buckets; u32 count; u32 nbuckets; } HTab;
typedef struct HPos { HTab *t; HNode *n; } HPos;
static __inline void pos_init(HPos *r, HTab *t, HNode *const *pn) { r->t = t; r->n = *pn; }
void ts4_htab_begin_881EE260(HPos *r, HTab *t)
{
    if (t->count != 0) {
        u32 i;
        for (i = 0; i < t->nbuckets; i++) {
            if (t->buckets[i] != 0) {
                pos_init(r, t, &t->buckets[i]);
                return;
            }
        }
    }
    r->t = t; r->n = 0;
}
