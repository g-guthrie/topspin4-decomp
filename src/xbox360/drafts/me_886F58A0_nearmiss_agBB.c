/* NEAR-MISS (agBB, /Oc): 1 extra instruction. The candidate reloads `item` (lwz r4,0x7c(r1)) after the slot store
   in the loop, before the second push; the target keeps r4. Local copies and a store-after-loop form do not help. */

typedef unsigned int u32;
typedef struct PV { void **first; void **last; u32 pad; void **end; } PV;
extern void ts4_vector_grow_append_scalar4_8816DD48(PV *v, void **pos, void **val);
static void pv_push(PV *v, void **val)
{
    void **p = v->last;
    if (p != v->end) {
        if (p) *p = *val;
        v->last++;
    } else {
        ts4_vector_grow_append_scalar4_8816DD48(v, p, val);
    }
}
void fn_886F58A0(PV *v, void *item)
{
    void **last = v->last;
    void **it;
    if ((u32)(last - v->first) < 500) {
        pv_push(v, &item);
    } else {
        for (it = v->first; it < last; it++) {
            if (!*it) { *it = item; break; }
        }
        if (it == last) pv_push(v, &item);
    }
}
