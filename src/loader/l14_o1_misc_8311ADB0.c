/* Loader_DLL.xex 0x8311ADB0-0x83188F68, executable version 0.0.0.3. */

#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#define TS4L_HIGHBIT 0x8000000000000000ui64
#else
#define __forceinline inline
typedef unsigned long long ts4l_u64;
#define TS4L_HIGHBIT 0x8000000000000000ULL
#endif

typedef struct ts4l_obj_flags {
    unsigned flags;
    int a;
    int b;
    char pad[0x10];
    int n;
} ts4l_obj_flags;

/* True when the object is flagged, has equal bounds, or a non-positive count. */
int ts4l_obj_is_empty_8311ADB0(ts4l_obj_flags *o)
{
    if (o->flags & 1) return 1;
    if (o->a == o->b) return 1;
    return o->n < 1;
}

typedef struct ts4l_key_entry {
    unsigned a;
    unsigned key;
    unsigned c;
    unsigned d;
} ts4l_key_entry;

typedef struct ts4l_key_table {
    char pad[0x24];
    ts4l_key_entry *arr;
    int count;
} ts4l_key_table;

/* First index at or after start whose key is >= the given key, or -1. */
int ts4l_key_table_find_ge_8311AF38(ts4l_key_table *t, int start, unsigned key)
{
    int i;
    for (i = start; i < t->count; i++) {
        if (t->arr[i].key >= key) return i;
    }
    return -1;
}

typedef struct ts4l_slot_83158B70 {
    unsigned pre : 30;
    unsigned low2 : 2;
    unsigned pad[5];
} ts4l_slot_83158B70;

typedef struct ts4l_dev_83158B70 {
    char pad0[0x18];
    ts4l_u64 dirty;
    char pad1[0x494 - 0x20];
    ts4l_slot_83158B70 slots[1];
} ts4l_dev_83158B70;

/* Set a per-slot enable field and mark the slot dirty in the 64-bit dirty mask. */
void ts4l_slot_set_enable_83158B70(ts4l_dev_83158B70 *d, unsigned idx, int n)
{
    d->slots[idx].low2 = (n != 0);
    d->dirty |= TS4L_HIGHBIT >> (idx + 0x20);
}

typedef struct ts4l_slot_83158CB8 {
    unsigned pre : 20;
    unsigned flag : 1;
    unsigned post : 11;
    unsigned pad[5];
} ts4l_slot_83158CB8;

typedef struct ts4l_dev_83158CB8 {
    char pad0[0x18];
    ts4l_u64 dirty;
    char pad1[0x484 - 0x20];
    ts4l_slot_83158CB8 slots[1];
} ts4l_dev_83158CB8;

/* Set a per-slot flag bit and mark the slot dirty in the 64-bit dirty mask. */
void ts4l_slot_set_flag_83158CB8(ts4l_dev_83158CB8 *d, unsigned idx, int n)
{
    d->slots[idx].flag = (n == 0);
    d->dirty |= TS4L_HIGHBIT >> (idx + 0x20);
}

void *fn_830B4408(int dev);

/* Create an object through the allocator wrapper; error code when it fails. */
int ts4l_create_check_83158E90(int dev, int unused, void **out)
{
    void *p = fn_830B4408(dev);
    (void)unused;
    *out = p;
    return p ? 0 : 0x88760866;
}

void *fn_830B4448(int dev);

/* Same as above for the second creation wrapper. */
int ts4l_create_check_83158F00(int dev, void **out)
{
    void *p = fn_830B4448(dev);
    *out = p;
    return p ? 0 : 0x88760866;
}

typedef struct ts4l_slot_8315E2C8 {
    unsigned pre : 30;
    unsigned low2 : 2;
    unsigned pad[5];
} ts4l_slot_8315E2C8;

typedef struct ts4l_dev_8315E2C8 {
    char pad0[0x18];
    ts4l_u64 dirty;
    char pad1[0x494 - 0x20];
    ts4l_slot_8315E2C8 slots[1];
} ts4l_dev_8315E2C8;

/* Set a per-slot enable field and mark the slot dirty in the 64-bit dirty mask. */
void ts4l_slot_set_enable_8315E2C8(ts4l_dev_8315E2C8 *d, unsigned idx, int n)
{
    d->slots[idx].low2 = (n != 0);
    d->dirty |= TS4L_HIGHBIT >> (idx + 0x20);
}

typedef struct ts4l_slot_8315E410 {
    unsigned pre : 20;
    unsigned flag : 1;
    unsigned post : 11;
    unsigned pad[5];
} ts4l_slot_8315E410;

typedef struct ts4l_dev_8315E410 {
    char pad0[0x18];
    ts4l_u64 dirty;
    char pad1[0x484 - 0x20];
    ts4l_slot_8315E410 slots[1];
} ts4l_dev_8315E410;

/* Set a per-slot flag bit and mark the slot dirty in the 64-bit dirty mask. */
void ts4l_slot_set_flag_8315E410(ts4l_dev_8315E410 *d, unsigned idx, int n)
{
    d->slots[idx].flag = (n == 0);
    d->dirty |= TS4L_HIGHBIT >> (idx + 0x20);
}

typedef struct ts4l_pool_blk_8316F200 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_8316F200;

typedef struct ts4l_pool_heap_8316F200 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_8316F200;

extern char lbl_83531690[];
void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_8316F200(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_8316F200 **hp;
    int sz;
    ts4l_pool_heap_8316F200 *h = (ts4l_pool_heap_8316F200 *)lbl_83531690;
    ts4l_pool_blk_8316F200 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_8316F200 **)(base - 8);
    sz = ((ts4l_pool_blk_8316F200 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83173898 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83173898;

typedef struct ts4l_pool_heap_83173898 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83173898;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83173898(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83173898 **hp;
    int sz;
    ts4l_pool_heap_83173898 *h = (ts4l_pool_heap_83173898 *)lbl_83531690;
    ts4l_pool_blk_83173898 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83173898 **)(base - 8);
    sz = ((ts4l_pool_blk_83173898 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83173B38 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83173B38;

typedef struct ts4l_pool_heap_83173B38 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83173B38;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83173B38(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83173B38 **hp;
    int sz;
    ts4l_pool_heap_83173B38 *h = (ts4l_pool_heap_83173B38 *)lbl_83531690;
    ts4l_pool_blk_83173B38 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83173B38 **)(base - 8);
    sz = ((ts4l_pool_blk_83173B38 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83174FE0 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83174FE0;

typedef struct ts4l_pool_heap_83174FE0 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83174FE0;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83174FE0(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83174FE0 **hp;
    int sz;
    ts4l_pool_heap_83174FE0 *h = (ts4l_pool_heap_83174FE0 *)lbl_83531690;
    ts4l_pool_blk_83174FE0 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83174FE0 **)(base - 8);
    sz = ((ts4l_pool_blk_83174FE0 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_831791F0 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_831791F0;

typedef struct ts4l_pool_heap_831791F0 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_831791F0;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_831791F0(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_831791F0 **hp;
    int sz;
    ts4l_pool_heap_831791F0 *h = (ts4l_pool_heap_831791F0 *)lbl_83531690;
    ts4l_pool_blk_831791F0 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_831791F0 **)(base - 8);
    sz = ((ts4l_pool_blk_831791F0 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_8317B410 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_8317B410;

typedef struct ts4l_pool_heap_8317B410 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_8317B410;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_8317B410(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_8317B410 **hp;
    int sz;
    ts4l_pool_heap_8317B410 *h = (ts4l_pool_heap_8317B410 *)lbl_83531690;
    ts4l_pool_blk_8317B410 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_8317B410 **)(base - 8);
    sz = ((ts4l_pool_blk_8317B410 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_8317F460 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_8317F460;

typedef struct ts4l_pool_heap_8317F460 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_8317F460;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_8317F460(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_8317F460 **hp;
    int sz;
    ts4l_pool_heap_8317F460 *h = (ts4l_pool_heap_8317F460 *)lbl_83531690;
    ts4l_pool_blk_8317F460 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_8317F460 **)(base - 8);
    sz = ((ts4l_pool_blk_8317F460 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_8317FFE0 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_8317FFE0;

typedef struct ts4l_pool_heap_8317FFE0 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_8317FFE0;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_8317FFE0(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_8317FFE0 **hp;
    int sz;
    ts4l_pool_heap_8317FFE0 *h = (ts4l_pool_heap_8317FFE0 *)lbl_83531690;
    ts4l_pool_blk_8317FFE0 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_8317FFE0 **)(base - 8);
    sz = ((ts4l_pool_blk_8317FFE0 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83180808 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83180808;

typedef struct ts4l_pool_heap_83180808 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83180808;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83180808(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83180808 **hp;
    int sz;
    ts4l_pool_heap_83180808 *h = (ts4l_pool_heap_83180808 *)lbl_83531690;
    ts4l_pool_blk_83180808 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83180808 **)(base - 8);
    sz = ((ts4l_pool_blk_83180808 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83183080 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83183080;

typedef struct ts4l_pool_heap_83183080 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83183080;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83183080(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83183080 **hp;
    int sz;
    ts4l_pool_heap_83183080 *h = (ts4l_pool_heap_83183080 *)lbl_83531690;
    ts4l_pool_blk_83183080 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83183080 **)(base - 8);
    sz = ((ts4l_pool_blk_83183080 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83183A38 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83183A38;

typedef struct ts4l_pool_heap_83183A38 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83183A38;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83183A38(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83183A38 **hp;
    int sz;
    ts4l_pool_heap_83183A38 *h = (ts4l_pool_heap_83183A38 *)lbl_83531690;
    ts4l_pool_blk_83183A38 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83183A38 **)(base - 8);
    sz = ((ts4l_pool_blk_83183A38 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83183E60 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83183E60;

typedef struct ts4l_pool_heap_83183E60 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83183E60;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83183E60(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83183E60 **hp;
    int sz;
    ts4l_pool_heap_83183E60 *h = (ts4l_pool_heap_83183E60 *)lbl_83531690;
    ts4l_pool_blk_83183E60 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83183E60 **)(base - 8);
    sz = ((ts4l_pool_blk_83183E60 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83184ED8 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83184ED8;

typedef struct ts4l_pool_heap_83184ED8 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83184ED8;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83184ED8(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83184ED8 **hp;
    int sz;
    ts4l_pool_heap_83184ED8 *h = (ts4l_pool_heap_83184ED8 *)lbl_83531690;
    ts4l_pool_blk_83184ED8 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83184ED8 **)(base - 8);
    sz = ((ts4l_pool_blk_83184ED8 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83186590 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83186590;

typedef struct ts4l_pool_heap_83186590 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83186590;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83186590(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83186590 **hp;
    int sz;
    ts4l_pool_heap_83186590 *h = (ts4l_pool_heap_83186590 *)lbl_83531690;
    ts4l_pool_blk_83186590 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83186590 **)(base - 8);
    sz = ((ts4l_pool_blk_83186590 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83186BB0 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83186BB0;

typedef struct ts4l_pool_heap_83186BB0 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83186BB0;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83186BB0(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83186BB0 **hp;
    int sz;
    ts4l_pool_heap_83186BB0 *h = (ts4l_pool_heap_83186BB0 *)lbl_83531690;
    ts4l_pool_blk_83186BB0 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83186BB0 **)(base - 8);
    sz = ((ts4l_pool_blk_83186BB0 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83187B88 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83187B88;

typedef struct ts4l_pool_heap_83187B88 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83187B88;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83187B88(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83187B88 **hp;
    int sz;
    ts4l_pool_heap_83187B88 *h = (ts4l_pool_heap_83187B88 *)lbl_83531690;
    ts4l_pool_blk_83187B88 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83187B88 **)(base - 8);
    sz = ((ts4l_pool_blk_83187B88 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_831883E0 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_831883E0;

typedef struct ts4l_pool_heap_831883E0 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_831883E0;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_831883E0(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_831883E0 **hp;
    int sz;
    ts4l_pool_heap_831883E0 *h = (ts4l_pool_heap_831883E0 *)lbl_83531690;
    ts4l_pool_blk_831883E0 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_831883E0 **)(base - 8);
    sz = ((ts4l_pool_blk_831883E0 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

typedef struct ts4l_pool_blk_83188F68 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4l_pool_blk_83188F68;

typedef struct ts4l_pool_heap_83188F68 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4l_pool_heap_83188F68;

void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4l_pool_free_83188F68(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4l_pool_blk_83188F68 **hp;
    int sz;
    ts4l_pool_heap_83188F68 *h = (ts4l_pool_heap_83188F68 *)lbl_83531690;
    ts4l_pool_blk_83188F68 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4l_pool_blk_83188F68 **)(base - 8);
    sz = ((ts4l_pool_blk_83188F68 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_83531690 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_83531690 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}
