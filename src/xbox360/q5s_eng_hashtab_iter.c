/* q5s eng: intrusive hash table iterator increment (LTCG, no /Oc: the modulo keeps its twllei trap).
 * The node's chain link and cached hash sit at a per-table offset (+0x38/+0x3c and +0x8/+0xc); at the
 * end of a chain the scan resumes at the next non-empty bucket. Reading the bucket twice
 * (`if (b[i]) r = b[i];`) gives the target's late-removed reload (`clrrwi r8,r5,0`). */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct EngHNode38 { u8 pad[0x38]; struct EngHNode38 *next; u32 hash; } EngHNode38;
typedef struct EngHTab38 { u8 pad0[0x14]; EngHNode38 **buckets; u8 pad18[4]; u32 nbuckets; } EngHTab38;
typedef struct EngHIt38 { EngHTab38 *t; EngHNode38 *n; } EngHIt38;

void ts4_htab38_iter_next_881ED6E8(EngHIt38 *it)
{
    EngHNode38 *n = it->n;
    EngHTab38 *t = it->t;
    if (n->next != 0) {
        it->n = n->next;
        return;
    }
    {
        EngHNode38 *r = 0;
        u32 i = n->hash % t->nbuckets + 1;
        do {
            if (i >= t->nbuckets) break;
            if (t->buckets[i] != 0) r = t->buckets[i];
            i++;
        } while (r == 0);
        it->n = r;
    }
}

typedef struct EngHNode08 { u8 pad[0x8]; struct EngHNode08 *next; u32 hash; } EngHNode08;
typedef struct EngHTab08 { u8 pad0[0x14]; EngHNode08 **buckets; u8 pad18[4]; u32 nbuckets; } EngHTab08;
typedef struct EngHIt08 { EngHTab08 *t; EngHNode08 *n; } EngHIt08;

void ts4_htab08_iter_next_881ED760(EngHIt08 *it)
{
    EngHNode08 *n = it->n;
    EngHTab08 *t = it->t;
    if (n->next != 0) {
        it->n = n->next;
        return;
    }
    {
        EngHNode08 *r = 0;
        u32 i = n->hash % t->nbuckets + 1;
        do {
            if (i >= t->nbuckets) break;
            if (t->buckets[i] != 0) r = t->buckets[i];
            i++;
        } while (r == 0);
        it->n = r;
    }
}
