/* 0x884CCC10: holder init: owner, a copy of the two-word pair, and ref = ts4_get_u32_off0_8841EAC8(pair.b) when pair.b is non-null */
/* Matched on /Oc (agAH). Struct copy then a read of the copied member gives the clrrwi copy (CL1 rule 3). */
typedef struct Pair { void *a; void *b; } Pair;
typedef struct Hold { void *owner; void *ref; Pair p; } Hold;
void *ts4_get_u32_off0_8841EAC8(void *b);
Hold *fn_884CCC10(Hold *h, void *owner, const Pair *p)
{
    h->owner = owner;
    h->p = *p;
    h->ref = h->p.b ? ts4_get_u32_off0_8841EAC8(h->p.b) : 0;
    return h;
}
