/* C++ retry (agentB, 2026-11-18): Impl as a class with real virtuals (create slot 1, init slot 2): still 10 off, same r27-r31 naming residue; make() inline, desc local copies, reference/pointer to the registry global: 10-47. */
/* 0x88662390 (draft, 10 instructions off, all callee-saved register naming: the target keeps the
 * registry pointer in r31, the descriptor in r29, the address base in r28). */
/* 0x88662390 (draft): binds the object to a descriptor: creates the fixed-kind helper and the
 * descriptor-kind implementation through the global factory registry, initialises the implementation
 * with the descriptor and argument, and resolves the descriptor's relative payload pointer.
 * The target keeps the registry pointer in a register across the lookup and re-reads it only after
 * the virtual create call; the explicit reload below models that. */
typedef struct Impl Impl;
typedef struct ImplVt { void *f0; Impl *(*create)(Impl *self); void (*init)(Impl *self, void *desc, void *arg); } ImplVt;
struct Impl { ImplVt *vt; };
typedef struct Desc { unsigned int kind; char p[0x14 - 4]; volatile int payload_offset; } Desc;
typedef struct Obj { void *f0; Desc *desc; Impl *helper; Impl *impl; void *payload; } Obj;
extern void *lbl_88D45B20;
Impl *fn_8816D220(void *registry, unsigned int kind);
static __forceinline void *rel_ptr(volatile int *p) { if (*p == -1) return 0; return (char *)p + *p; }
static __forceinline void *rel_ptr2(volatile int *p) { void *r; if (*p == -1) r = 0; else r = (char *)p + *p; return r; }
typedef struct Registry Registry;
static __forceinline Impl *lookup(Registry *r, unsigned int kind) { return fn_8816D220(r, kind); }
static __forceinline Impl *make(unsigned int kind)
{
    Impl *f = fn_8816D220(lbl_88D45B20, kind);
    if (f != 0)
        f = f->vt->create(f);
    return f;
}
void ts4_bind_descriptor_88662390(Obj *o, Desc *d, void *arg)
{
    void *reg;
    Impl *i;
    o->desc = d;
    reg = lbl_88D45B20;
    i = fn_8816D220(reg, 0x9BD3657E);
    if (i != 0) {
        i = i->vt->create(i);
        reg = lbl_88D45B20;
    }
    o->helper = i;
    i = fn_8816D220(reg, d->kind);
    if (i != 0)
        i = i->vt->create(i);
    o->impl = i;
    i->vt->init(i, d, arg);
    { volatile int *p = &d->payload_offset; if (*p == -1) o->payload = 0; else o->payload = (char *)p + *p; }
}
