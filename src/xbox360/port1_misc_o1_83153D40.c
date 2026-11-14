/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l9_misc_o1_83153D40.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
#ifndef _MSC_VER
#define __forceinline inline
#endif

typedef struct ts4_ptr_registry {
    char pad[0x40];
    unsigned **items;
    unsigned short count;
} ts4_ptr_registry;

/* Find the entry whose pointed-to value equals *key; returns index or -1. */

/* Extract a 15-bit field at an arbitrary bit offset of a byte stream. */

/* Round a value to a multiple of align: mode 1 rounds up, mode 2 to nearest. */

typedef struct ts4_ring_counter {
    int pad;
    int capacity;
    int count;
    int head;
} ts4_ring_counter;

/* Pop one slot from a ring counter; returns 1 when it was empty, else 0. */

/* Map a sample-rate-like constant to a small table index (0 when unknown). */

typedef struct ts4_keyed_item {
    unsigned key;
    unsigned value;
} ts4_keyed_item;

typedef struct ts4_sorted_table {
    int count;
    int reserved;
    ts4_keyed_item **items;
} ts4_sorted_table;

typedef struct ts4_stat_entry {
    unsigned short w, z;
} ts4_stat_entry;

typedef struct ts4_stat_block {
    char pad[0x1c];
    unsigned char flag;
    char pad2[0x8c - 0x1d];
    ts4_stat_entry a[7];
    ts4_stat_entry b[0x79];
    ts4_stat_entry c[0x80];
} ts4_stat_block;

/* Compare weighted sums of three 16-bit histograms and set a flag byte. */

typedef struct ts4_bit_writer {
    char p0[8];
    unsigned char *buf;
    char p1[8];
    int pos;
    char p2[0x16b0 - 0x18];
    unsigned short bits;
    unsigned short pad;
    int nbits;
} ts4_bit_writer;

/* Flush the partial bit accumulator (up to 16 bits) to the output buffer. */

/* Emit whole bytes from the accumulator once 8 or 16 bits are pending. */

typedef struct ts4_code_entry {
    unsigned short key;
    unsigned char a;
    unsigned char b;
} ts4_code_entry;

/* Binary search of a 147-entry sorted code table; writes the two payload bytes. */

typedef struct ts4_range_acc {
    char p[0x14];
    int count;
    char q[0xc];
    int sum_a;
    int sum_b;
} ts4_range_acc;

typedef struct ts4_range_owner {
    char p[0x34];
    ts4_range_acc *acc;
    char q[0xdc - 0x38];
    int delta_a;
    int delta_b;
} ts4_range_owner;

/* Add (dir == 0) or remove the owner's deltas from its accumulator. */

typedef struct ts4_seek_state {
    unsigned w0;
    unsigned w4;
    unsigned size;
    unsigned pos;
} ts4_seek_state;

typedef struct ts4_short_table {
    char p[0x130];
    unsigned char *tab;
    char q[0x3c];
    unsigned short n;
} ts4_short_table;

typedef struct ts4_item_scan {
    char p[0x1c0];
    unsigned n;
    char q[0x14];
    void *obj;
} ts4_item_scan;

/* Returns 1 as soon as the per-index callback reports failure, else 0. */

int fn_8859AD10();

/* Swing_DLL.xex 0x8859A008 */
void ts4_range_acc_update_8859A008(ts4_range_owner *a, int dir)
{
    if (dir == 0) {
        a->acc->count++;
        a->acc->sum_a += a->delta_a;
        a->acc->sum_b += a->delta_b;
    } else {
        a->acc->count--;
        a->acc->sum_a -= a->delta_a;
        a->acc->sum_b -= a->delta_b;
    }
}

/* Swing_DLL.xex 0x8859CFA0 */
int ts4_item_scan_any_failed_8859CFA0(ts4_item_scan *s)
{
    unsigned i;
    for (i = 0; i < s->n; i++) {
        if (fn_8859AD10(s->obj, i) == 0) return 1;
    }
    return 0;
}

