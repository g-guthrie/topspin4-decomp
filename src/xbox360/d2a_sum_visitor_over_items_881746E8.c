/* Swing_DLL.xex 0x881746E8-0x881767B8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Visitor { void **vtable; } Visitor;
typedef struct Vec { void **begin; void **end; } Vec;
#ifdef _MSC_VER
#define FORCEINLINE __forceinline
#else
#define FORCEINLINE inline
#endif
static FORCEINLINE u32 vec_size(Vec *v) { return (u32)(v->end - v->begin); }
static FORCEINLINE void *vec_at(Vec *v, u32 i) { return v->begin[i]; }

typedef int (*Visit_881746E8)(Visitor *, void *, int);
typedef struct Holder_881746E8 { u32 pad[2]; Vec items; } Holder_881746E8;

/* Calls virtual slot 4 of the visitor for every pointer in the vector and sums the results. */
int ts4_sum_visitor_over_items_881746E8(Holder_881746E8 *self, Visitor *v)
{
    int total = 0;
    u32 i;
    for (i = 0; i < vec_size(&self->items); ++i) {
        total += ((Visit_881746E8)v->vtable[4])(v, vec_at(&self->items, i), 12);
    }
    return total;
}

typedef int (*Visit_88174770)(Visitor *, void *, int);
typedef struct Holder_88174770 { u32 pad[2]; Vec items; } Holder_88174770;

/* Calls virtual slot 1 of the visitor for every pointer in the vector and sums the results. */
int ts4_sum_visitor_over_items_88174770(Holder_88174770 *self, Visitor *v)
{
    int total = 0;
    u32 i;
    for (i = 0; i < vec_size(&self->items); ++i) {
        total += ((Visit_88174770)v->vtable[1])(v, vec_at(&self->items, i), 12);
    }
    return total;
}

typedef int (*Visit_88174870)(Visitor *, void *, int);
typedef struct Holder_88174870 { u32 pad[2]; Vec items; } Holder_88174870;

/* Calls virtual slot 4 of the visitor for every pointer in the vector and sums the results. */
int ts4_sum_visitor_over_items_88174870(Holder_88174870 *self, Visitor *v)
{
    int total = 0;
    u32 i;
    for (i = 0; i < vec_size(&self->items); ++i) {
        total += ((Visit_88174870)v->vtable[4])(v, vec_at(&self->items, i), 16);
    }
    return total;
}

typedef int (*Visit_881748F8)(Visitor *, void *, int);
typedef struct Holder_881748F8 { u32 pad[2]; Vec items; } Holder_881748F8;

/* Calls virtual slot 1 of the visitor for every pointer in the vector and sums the results. */
int ts4_sum_visitor_over_items_881748F8(Holder_881748F8 *self, Visitor *v)
{
    int total = 0;
    u32 i;
    for (i = 0; i < vec_size(&self->items); ++i) {
        total += ((Visit_881748F8)v->vtable[1])(v, vec_at(&self->items, i), 16);
    }
    return total;
}

typedef int (*Visit_881759C8)(Visitor *, void *, int);
typedef struct Holder_881759C8 { u32 pad[2]; Vec items; } Holder_881759C8;

/* Calls virtual slot 4 of the visitor for every pointer in the vector and sums the results. */
int ts4_sum_visitor_over_items_881759C8(Holder_881759C8 *self, Visitor *v)
{
    int total = 0;
    u32 i;
    for (i = 0; i < vec_size(&self->items); ++i) {
        total += ((Visit_881759C8)v->vtable[4])(v, vec_at(&self->items, i), 1);
    }
    return total;
}

typedef int (*Visit_88175A50)(Visitor *, void *, int);
typedef struct Holder_88175A50 { u32 pad[2]; Vec items; } Holder_88175A50;

/* Calls virtual slot 1 of the visitor for every pointer in the vector and sums the results. */
int ts4_sum_visitor_over_items_88175A50(Holder_88175A50 *self, Visitor *v)
{
    int total = 0;
    u32 i;
    for (i = 0; i < vec_size(&self->items); ++i) {
        total += ((Visit_88175A50)v->vtable[1])(v, vec_at(&self->items, i), 1);
    }
    return total;
}

typedef int (*Visit_881761B0)(Visitor *, void *, int);
typedef struct Holder_881761B0 { u32 pad[2]; Vec items; } Holder_881761B0;

/* Calls virtual slot 1 of the visitor for every pointer in the vector and sums the results. */
int ts4_sum_visitor_over_items_881761B0(Holder_881761B0 *self, Visitor *v)
{
    int total = 0;
    u32 i;
    for (i = 0; i < vec_size(&self->items); ++i) {
        total += ((Visit_881761B0)v->vtable[1])(v, vec_at(&self->items, i), 8);
    }
    return total;
}

typedef int (*Visit_88176470)(Visitor *, void *, int);
typedef struct Holder_88176470 { u32 pad[2]; Vec items; } Holder_88176470;

/* Calls virtual slot 4 of the visitor for every pointer in the vector and sums the results. */
int ts4_sum_visitor_over_items_88176470(Holder_88176470 *self, Visitor *v)
{
    int total = 0;
    u32 i;
    for (i = 0; i < vec_size(&self->items); ++i) {
        total += ((Visit_88176470)v->vtable[4])(v, vec_at(&self->items, i), 4);
    }
    return total;
}

typedef int (*Visit_881764F8)(Visitor *, void *, int);
typedef struct Holder_881764F8 { u32 pad[2]; Vec items; } Holder_881764F8;

/* Calls virtual slot 1 of the visitor for every pointer in the vector and sums the results. */
int ts4_sum_visitor_over_items_881764F8(Holder_881764F8 *self, Visitor *v)
{
    int total = 0;
    u32 i;
    for (i = 0; i < vec_size(&self->items); ++i) {
        total += ((Visit_881764F8)v->vtable[1])(v, vec_at(&self->items, i), 4);
    }
    return total;
}

typedef int (*Visit_881767B8)(Visitor *, void *, int);
typedef struct Holder_881767B8 { u32 pad[2]; Vec items; } Holder_881767B8;

/* Calls virtual slot 4 of the visitor for every pointer in the vector and sums the results. */
int ts4_sum_visitor_over_items_881767B8(Holder_881767B8 *self, Visitor *v)
{
    int total = 0;
    u32 i;
    for (i = 0; i < vec_size(&self->items); ++i) {
        total += ((Visit_881767B8)v->vtable[4])(v, vec_at(&self->items, i), 8);
    }
    return total;
}
