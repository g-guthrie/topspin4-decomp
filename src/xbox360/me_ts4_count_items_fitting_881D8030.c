/* 0x881D8030: Counts how many items from start onward fit: adds each item width (source vt slot 13) to the used width and stops once the total exceeds the limit or the count (slot 11) is reached. */
/* Matched on /Oc (agAH). Plain loop. */
typedef struct Item { char p0[8]; float width; } Item;
typedef struct Source Source;
typedef struct SourceVt { void *s[11]; unsigned int (*count)(Source *); void *s12; Item *(*get)(Source *, unsigned int); } SourceVt;
struct Source { SourceVt *vt; };
typedef struct Layout { char p0[0x24]; Source *src; char p28[0x24]; float used; float limit; } Layout;
unsigned int fn_881D8030(Layout *l, unsigned int start)
{
    float total = l->used;
    unsigned int n = l->src->vt->count(l->src);
    unsigned int i;
    for (i = start; i < n; i++) {
        total += l->src->vt->get(l->src, i)->width;
        if (total > l->limit)
            break;
    }
    return i - start;
}
