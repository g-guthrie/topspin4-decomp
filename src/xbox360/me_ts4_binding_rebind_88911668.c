/* Swing_DLL.xex 0x88911668: Swing_DLL.xex 0x88911668: Rebinds unless the binding is ready and already bound to the same target and source: stores state/target/source/table, rebuilds the layout from the source descriptor (weights resize 88158B28, two maps 8817A4F0), resizes the slot vector to desc->slots and refills the lookup (8890E810).
 * /Oc. Bool helpers written as if/return 1/return 0 (gives li 1; beq; li 0) and Dinkumware resize template. */
typedef struct FVec { float *first; float *last; float *end; } FVec;
typedef struct PVec { void **first; void **last; void **end; } PVec;
typedef struct Map { int w[3]; } Map;
typedef struct Range { int w[3]; } Range;
typedef struct Desc { unsigned count; Range a; Range b; char pad1c[0x20 - 0x1c]; unsigned slots; } Desc;   /* a at 4, b at 0x10, slots at 0x20 */
typedef struct Source { char pad[4]; Desc *desc; } Source;
typedef struct Layout { FVec weights; Map by_b; Map by_a; } Layout;    /* 0x24 */
typedef struct Binding {
    char pad[4];
    const unsigned char *state; /* 0x04 */
    Source *source;             /* 0x08 */
    void *target;               /* 0x0c */
    void *table;                /* 0x10 */
    Layout layout;              /* 0x14 */
    PVec slots;                 /* 0x38 */
} Binding;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_fvec_resize_88158B28(FVec *v, unsigned n);
void fn_8817A4F0(Map *m, void *target, Range *r);
void fn_88281CA8(PVec *v, void **where, unsigned n, void **val);
void ts4_fill_lookup_8890E810(void *table, Binding *b);
static __forceinline void **copy_ptrs(void **first, void **last, void **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (void **)fn_88562DC0(dest, first, n);
        return (void **)((char *)dest + n);
    }
}
static __inline unsigned pvec_size(const PVec *v) { return v->last - v->first; }
static __inline void pvec_resize(PVec *v, unsigned n, void *val)
{
    unsigned size = pvec_size(v);
    if (n < size)
        v->last = copy_ptrs(v->last, v->last, v->first + n);
    else
        fn_88281CA8(v, v->last, n - size, &val);
}
static __inline unsigned char binding_ready(const Binding *b)
{
    if (b->state && *b->state == 1)
        return 1;
    return 0;
}
static __inline unsigned char binding_changed(const Binding *b, void *target, Source *source)
{
    if (binding_ready(b) && b->target && b->source && b->target == target && b->source == source)
        return 0;
    return 1;
}
static __inline void layout_build(Layout *l, void *target, Desc *d)
{
    ts4_fvec_resize_88158B28(&l->weights, d->count);
    fn_8817A4F0(&l->by_a, target, &d->a);
    fn_8817A4F0(&l->by_b, target, &d->b);
}
void fn_88911668(Binding *b, void *target, Source *source, void *table, const unsigned char *state)
{
    Desc *d;
    if (!binding_changed(b, target, source))
        return;
    b->state = state;
    b->target = target;
    b->source = source;
    b->table = table;
    d = source->desc;
    layout_build(&b->layout, target, d);
    pvec_resize(&b->slots, source->desc->slots, 0);
    ts4_fill_lookup_8890E810(b->table, b);
}
