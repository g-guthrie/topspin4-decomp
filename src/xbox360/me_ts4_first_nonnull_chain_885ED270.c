/* 0x885ED270: returns p->a, else p->b, else the first non-null +8 along the +0x10 chain; self is unused */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct N { void *a; int x4; void *b; int xc; struct N *next; } N;
void *ts4_first_nonnull_chain_885ED270(void *self, N *p)
{
    void *r;
    if ((r = p->a) != 0) return r;
    if ((r = p->b) != 0) return r;
    do {
        p = p->next;
        if (!p) return 0;
        r = p->b;
    } while (!r);
    return r;
}
