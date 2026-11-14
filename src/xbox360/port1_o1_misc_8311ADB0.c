/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l14_o1_misc_8311ADB0.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#define TS4_HIGHBIT 0x8000000000000000ui64
#else
#define __forceinline inline
typedef unsigned long long ts4_u64;
#define TS4_HIGHBIT 0x8000000000000000ULL
#endif

typedef struct ts4_obj_flags {
    unsigned flags;
    int a;
    int b;
    char pad[0x10];
    int n;
} ts4_obj_flags;

/* True when the object is flagged, has equal bounds, or a non-positive count. */

typedef struct ts4_key_entry {
    unsigned a;
    unsigned key;
    unsigned c;
    unsigned d;
} ts4_key_entry;

typedef struct ts4_key_table {
    char pad[0x24];
    ts4_key_entry *arr;
    int count;
} ts4_key_table;

/* First index at or after start whose key is >= the given key, or -1. */

typedef struct ts4_slot_83158B70 {
    unsigned pre : 30;
    unsigned low2 : 2;
    unsigned pad[5];
} ts4_slot_83158B70;

typedef struct ts4_dev_83158B70 {
    char pad0[0x18];
    ts4_u64 dirty;
    char pad1[0x494 - 0x20];
    ts4_slot_83158B70 slots[1];
} ts4_dev_83158B70;

/* Set a per-slot enable field and mark the slot dirty in the 64-bit dirty mask. */

typedef struct ts4_slot_83158CB8 {
    unsigned pre : 20;
    unsigned flag : 1;
    unsigned post : 11;
    unsigned pad[5];
} ts4_slot_83158CB8;

typedef struct ts4_dev_83158CB8 {
    char pad0[0x18];
    ts4_u64 dirty;
    char pad1[0x484 - 0x20];
    ts4_slot_83158CB8 slots[1];
} ts4_dev_83158CB8;

/* Set a per-slot flag bit and mark the slot dirty in the 64-bit dirty mask. */

/* Create an object through the allocator wrapper; error code when it fails. */

/* Same as above for the second creation wrapper. */

typedef struct ts4_slot_8315E2C8 {
    unsigned pre : 30;
    unsigned low2 : 2;
    unsigned pad[5];
} ts4_slot_8315E2C8;

typedef struct ts4_dev_8315E2C8 {
    char pad0[0x18];
    ts4_u64 dirty;
    char pad1[0x494 - 0x20];
    ts4_slot_8315E2C8 slots[1];
} ts4_dev_8315E2C8;

/* Set a per-slot enable field and mark the slot dirty in the 64-bit dirty mask. */

typedef struct ts4_slot_8315E410 {
    unsigned pre : 20;
    unsigned flag : 1;
    unsigned post : 11;
    unsigned pad[5];
} ts4_slot_8315E410;

typedef struct ts4_dev_8315E410 {
    char pad0[0x18];
    ts4_u64 dirty;
    char pad1[0x484 - 0x20];
    ts4_slot_8315E410 slots[1];
} ts4_dev_8315E410;

/* Set a per-slot flag bit and mark the slot dirty in the 64-bit dirty mask. */

typedef struct ts4_pool_blk_8316F200 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_8316F200;

typedef struct ts4_pool_heap_8316F200 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_8316F200;

typedef struct ts4_pool_blk_83173898 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83173898;

typedef struct ts4_pool_heap_83173898 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83173898;

typedef struct ts4_pool_blk_83173B38 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83173B38;

typedef struct ts4_pool_heap_83173B38 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83173B38;

typedef struct ts4_pool_blk_83174FE0 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83174FE0;

typedef struct ts4_pool_heap_83174FE0 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83174FE0;

typedef struct ts4_pool_blk_831791F0 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_831791F0;

typedef struct ts4_pool_heap_831791F0 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_831791F0;

typedef struct ts4_pool_blk_8317B410 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_8317B410;

typedef struct ts4_pool_heap_8317B410 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_8317B410;

typedef struct ts4_pool_blk_8317F460 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_8317F460;

typedef struct ts4_pool_heap_8317F460 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_8317F460;

typedef struct ts4_pool_blk_8317FFE0 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_8317FFE0;

typedef struct ts4_pool_heap_8317FFE0 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_8317FFE0;

typedef struct ts4_pool_blk_83180808 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83180808;

typedef struct ts4_pool_heap_83180808 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83180808;

typedef struct ts4_pool_blk_83183080 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83183080;

typedef struct ts4_pool_heap_83183080 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83183080;

typedef struct ts4_pool_blk_83183A38 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83183A38;

typedef struct ts4_pool_heap_83183A38 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83183A38;

typedef struct ts4_pool_blk_83183E60 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83183E60;

typedef struct ts4_pool_heap_83183E60 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83183E60;

typedef struct ts4_pool_blk_83184ED8 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83184ED8;

typedef struct ts4_pool_heap_83184ED8 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83184ED8;

typedef struct ts4_pool_blk_83186590 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83186590;

typedef struct ts4_pool_heap_83186590 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83186590;

typedef struct ts4_pool_blk_83186BB0 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83186BB0;

typedef struct ts4_pool_heap_83186BB0 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83186BB0;

typedef struct ts4_pool_blk_83187B88 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83187B88;

typedef struct ts4_pool_heap_83187B88 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83187B88;

typedef struct ts4_pool_blk_831883E0 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_831883E0;

typedef struct ts4_pool_heap_831883E0 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_831883E0;

typedef struct ts4_pool_blk_83188F68 {
    unsigned start;
    unsigned size;
    unsigned mask;
} ts4_pool_blk_83188F68;

typedef struct ts4_pool_heap_83188F68 {
    char pad0[0x10];
    int total;
    int cls[0x1000];
} ts4_pool_heap_83188F68;

extern char lbl_88D2F130[];
void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);

/* Swing_DLL.xex 0x885B72F0 */
/* Free one small-block pool item: clear its slot bit in the owning block and
   return its size to the heap's running totals. */
void ts4_pool_free_885B72F0(void *p)
{
    unsigned *u = (unsigned *)p;
    unsigned tag;
    char *base;
    ts4_pool_blk_8316F200 **hp;
    int sz;
    ts4_pool_heap_8316F200 *h = (ts4_pool_heap_8316F200 *)lbl_88D2F130;
    ts4_pool_blk_8316F200 *b;

    tag = u[-2];
    base = (char *)p - u[-1];
    hp = (ts4_pool_blk_8316F200 **)(base - 8);
    sz = ((ts4_pool_blk_8316F200 **)base)[-2]->size - 8;
    RtlEnterCriticalSection(lbl_88D2F130 + 0x54);
    b = *hp;
    b->mask ^= 1u << (((unsigned)(unsigned long)hp - b->start) / b->size);
    RtlLeaveCriticalSection(lbl_88D2F130 + 0x54);
    h->total -= sz;
    h->cls[tag & 0x1fff] -= sz;
}

