/* 0x886CB3A8: for every group in the source description and every id listed in that group, appends a
 * 16-byte binding {group tag, id, weight = event default, active = 0} to the owner's fixed-capacity
 * binding array, dropping entries once the array is full. Matched by naming the memcpy size and source
 * in locals first (puts `li r5,0x10` before `addi r4`). */
void *memcpy(void *dst, const void *src, unsigned long n);
typedef struct IdList { int offset; int count; } IdList;
typedef struct Group { IdList ids; char p[0xc - 8]; unsigned int tag; } Group;
typedef struct Groups { volatile int offset; int count; } Groups;
typedef struct Desc { char p[8]; Groups groups; } Desc;
typedef struct Src { char p[0xc]; Desc *desc; } Src;
typedef struct Binding { unsigned int tag; unsigned int id; float weight; unsigned char active; } Binding;
typedef struct Bindings { int offset; int count; int capacity; } Bindings;
typedef struct Owner { char p[0x24]; Bindings *out; Src *src; } Owner;
extern float lbl_8814B440;
static __forceinline Group *groups_begin(Groups *t) { Group *r = 0; int off = t->offset; if (off != -1) r = (Group *)((char *)t + off); return r; }
static __forceinline Group *groups_end(Groups *t) { Group *r = 0; int off = t->offset; if (off != -1) r = (Group *)((char *)t + (t->count * sizeof(Group) + off)); return r; }
static __forceinline unsigned int *ids_begin(IdList *t) { unsigned int *r = 0; if (t->offset != -1) r = (unsigned int *)((char *)t + t->offset); return r; }
static __forceinline unsigned int *ids_end(IdList *t) { unsigned int *r = 0; if (t->offset != -1) r = (unsigned int *)((char *)t + (t->count * 4 + t->offset)); return r; }
static __forceinline void push(Bindings *b, const Binding *v) { if (b->count < b->capacity) { { unsigned long n = sizeof(Binding); const void *s = v; memcpy((char *)b + (b->count * sizeof(Binding) + b->offset), s, n); } b->count++; } }
void ts4_append_group_bindings_886CB3A8(Owner *o)
{
    Groups *gs = &o->src->desc->groups;
    Group *g, *ge;
    float zero;
    ge = groups_end(gs);
    g = groups_begin(gs);
    if (g == ge) return;
    zero = lbl_8814B440;
    for (; g != ge; g++) {
        unsigned int *id, *ie;
        ie = ids_end(&g->ids);
        for (id = ids_begin(&g->ids); id != ie; id++) {
            Binding b;
            b.weight = zero;
            b.tag = g->tag;
            b.id = *id;
            b.active = 0;
            push(o->out, &b);
        }
    }
}
