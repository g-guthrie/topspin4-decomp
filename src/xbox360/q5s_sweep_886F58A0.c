/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x886F58A0: add a pointer to the vector: plain push while it holds fewer than 500 entries, afterwards reuse the
 * first null slot and push only when there is none.
 * Source: drafts/me_886F58A0_nearmiss_agBB.c (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_886F58A0.json for route and flags. */
typedef unsigned int u32;
typedef struct Ts4PtrVec { void **first; void **last; u32 pad; void **end; } Ts4PtrVec;
extern void ts4_vector_grow_append_scalar4_8816DD48(Ts4PtrVec *v, void **pos, void **val);
static void pv_push(Ts4PtrVec *v, void **val)
{
    void **p = v->last;
    if (p != v->end) {
        if (p) *p = *val;
        v->last++;
    } else {
        ts4_vector_grow_append_scalar4_8816DD48(v, p, val);
    }
}
void ts4_ptr_pool_add_886F58A0(Ts4PtrVec *v, void *item)
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
