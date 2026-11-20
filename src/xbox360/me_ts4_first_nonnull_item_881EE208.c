/* 0x881EE208: first non-null pointer of items[0..n) (+0x14, +0x1c), when +0x18 is set; else NULL */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char pad[0x14]; void **items; void *x18; unsigned int n; } O;
void *ts4_first_nonnull_item_881EE208(O *o)
{
    if (o->x18) {
        unsigned int i = 0;
        if (o->n) {
            for (; i < o->n; i++)
                if (o->items[i]) return o->items[i];
        }
    }
    return 0;
}
