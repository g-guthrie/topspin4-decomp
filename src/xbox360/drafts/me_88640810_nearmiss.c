/* agentA2 (2026-11-18 tips pass): block-local pointer zero store in ref_init, named call arguments in a block, volatile/pointer read of lbl_88D45290: still 7 off (plain and LTCG); target loads the manager address before li 0. */
/* NEAR MISS 0x88640810: 7 off, the zero store of the handle and the manager load are scheduled differently
 * (target: lis; mr; li 0; addi; addi; stw; lwz). Declaration order and a Ref struct did not change it. */
/* 0x88640810 (hand match): looks up the resource named by the descriptor through the global resource
 * manager; when the handle differs from the current one it becomes current and the changed flag is set.
 * The lookup's reference is then dropped. */
typedef struct Text { void *data; } Text;
typedef struct Desc { char p[0x18]; char name[1]; } Desc;
typedef struct Obj { char p[0x19c]; void *current; unsigned char changed; } Obj;
extern void *lbl_88D45290;
void *ts4_assign_text_from_c_string(void *out, const char *s);
void fn_88640510(void *manager, void *name, void **handle, int flags);
void ts4_if_atomic_interlocked_dec_881876D0(void *h);
typedef struct Ref { void *p; } Ref;
static __forceinline void ref_init(Ref *r) { r->p = 0; }
static __forceinline void ref_release(Ref *r) { if (r->p != 0) ts4_if_atomic_interlocked_dec_881876D0(r->p); }
void ts4_update_named_resource_88640810(Obj *o, Desc *d)
{
    void *mgr = lbl_88D45290;
    Ref h;
    Text name;
    ref_init(&h);
    fn_88640510(mgr, ts4_assign_text_from_c_string(&name, d->name), &h.p, 0);
    if (h.p != o->current) {
        o->current = h.p;
        o->changed = 1;
    }
    ref_release(&h);
}
